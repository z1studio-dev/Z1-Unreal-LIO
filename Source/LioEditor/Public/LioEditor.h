#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FLioEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
    
private:
    FDelegateHandle GlobalHandle;
    void OnRowExtension(const FOnGenerateGlobalRowExtensionArgs& Args,
                     TArray<FPropertyRowExtensionButton>& OutButtons);
	void OnClicked(UObject* Owner, FString PropertyPath);

};
