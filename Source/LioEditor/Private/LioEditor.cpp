#include "LioEditor.h"

#define LOCTEXT_NAMESPACE "FLioEditorModule"

void FLioEditorModule::StartupModule()
{
#if WITH_EDITOR
	auto& PropEd = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	GlobalHandle = PropEd.GetGlobalRowExtensionDelegate().AddRaw(
	  this, &FLioEditorModule::OnRowExtension
	);
#endif
}

void FLioEditorModule::OnRowExtension(const FOnGenerateGlobalRowExtensionArgs& Args,
					 TArray<FPropertyRowExtensionButton>& OutButtons)
{
	if (!Args.PropertyHandle.IsValid())
	{
		return;			
	}
	
	TArray<UObject*> OuterObjects;
	Args.PropertyHandle->GetOuterObjects(OuterObjects);
	
	if (OuterObjects.Num() == 0 && !OuterObjects[0])
	{
		return;
	}

	//filter categories, header, etc
	FProperty* Prop = Args.PropertyHandle->GetProperty();
	if (!Prop)
	{
		return;
	}
	
	//only editable instancer
	if (
		!Prop->HasAnyPropertyFlags(CPF_Edit) &&  
		Prop->HasAnyPropertyFlags(CPF_DisableEditOnInstance))
	{
		return;
	}
	
	//
	const UObject* Owner = OuterObjects[0];
	const FString PropertyId = FString::Printf(TEXT("%s.%s"),
		*Owner->GetPathName(),
		*Prop->GetName()
	);

	// 6) Ajoute le bouton "œil"
	FPropertyRowExtensionButton B;
	B.Icon = FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Visible");
	B.Label = FText(); // vide => juste l'icône (si tu veux)
	B.ToolTip = FText::FromString(TEXT("Expose (plugin callback)"));

	// 7) Callback : on passe Owner + PropertyId
	B.UIAction = FUIAction(
		FExecuteAction::CreateRaw(this, &FLioEditorModule::OnClicked, OuterObjects[0], PropertyId)
	);

	OutButtons.Add(MoveTemp(B));
}
void FLioEditorModule::OnClicked(UObject* Owner, FString PropertyPath)
{
	// ✅ TON CALLBACK ICI
	// Owner = l'objet qui possède la propriété
	// PropertyPath = chemin stable côté Details (ex: "MyComp.MyVar" / "MyStruct.Value" etc.)
	
}


void FLioEditorModule::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FLioEditorModule, LioEditor)