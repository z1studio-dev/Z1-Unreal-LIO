#include "LioCore.h"
#include "InputCoreTypes.h"
#include "FLioInputDevice.h"
#define LOCTEXT_NAMESPACE "FLioCoreModule"

FLioInputDevice* FLioCoreModule::DeviceRaw = nullptr;

// Helper
bool RegisterAxis1DKeyIfNeeded(const FKey& Key, const FText& DisplayName, const FName& MenuCategory, const FText& CategoryDisplayName)
{
	// Déclarer la catégorie dans l'UI (facultatif mais clean)
	EKeys::AddMenuCategoryDisplayInfo(MenuCategory, CategoryDisplayName, NAME_None);

	//const FKey Key(KeyName);
	const TSharedPtr<FKeyDetails> Existing = EKeys::GetKeyDetails(Key);
	if (!Existing.IsValid())
	{
		// Flags : analogique 1D + "périphérique" (pour s'aligner sur l'UX des axes)
		const uint32 Flags = FKeyDetails::GamepadKey | FKeyDetails::Axis1D;

		// Passer la catégorie via le constructeur
		const FKeyDetails Details(
			Key,
			DisplayName,                // Long display name
			Flags,
			MenuCategory                // Category pour le picker d’IMC
		);

		EKeys::AddKey(Details);
		return true;
	}
	return false;
}

void FLioCoreModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("LioInputDevicePlugin initiated!"));

	// IMPORTANT: This line registers our input device module with the engine.
	//        If we do not register the input device module with the engine,
	//        the engine won't know about our existence. Which means 
	//        CreateInputDevice never gets called, which means the engine
	//        will never try to poll for events from our custom input device.
	IModularFeatures::Get().RegisterModularFeature(IInputDeviceModule::GetModularFeatureName(), this);



	
	//const FName MenuCat   = FName(TEXT("Lio|Input"));
	//const FText CatLabel  = LOCTEXT("LioInputCategory", "Lio | Input");

	// Exemple : 4 LFO (ajoute / renomme comme tu veux)
	//RegisterAxis1DKeyIfNeeded(FName(TEXT("LIO_LFO1_Axis1D")), LOCTEXT("LioLFO1", "Lio LFO1 Axis1D"), MenuCat, CatLabel);
}

void FLioCoreModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UE_LOG(LogTemp, Warning, TEXT("BlankInputDevicePlugin shut down!"));

	// Unregister our input device module
	IModularFeatures::Get().UnregisterModularFeature(IInputDeviceModule::GetModularFeatureName(), this);
}

TSharedPtr<IInputDevice> FLioCoreModule::CreateInputDevice(
	const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	UE_LOG(LogTemp, Warning, TEXT("Created new input device!"));
	TSharedPtr<FLioInputDevice> Dev = MakeShared<FLioInputDevice>(InMessageHandler);
	DeviceRaw = Dev.Get(); //not owning
	return Dev;
}

FLioInputDevice* FLioCoreModule::GetDevice()
{
	return DeviceRaw;
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FLioCoreModule, LioCore)