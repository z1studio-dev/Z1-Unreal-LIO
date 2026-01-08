#pragma once
//https://unrealcommunity.wiki/custom-input-device-plugin-guide-6g8yq3eb
#include "CoreMinimal.h"
#include "IInputDeviceModule.h"
#include "Modules/ModuleManager.h"

/**
*
* Frame N (Game Thread)
┌───────────────────────────────────────────────────────────────────────┐
│ 1) OS message pump                                                    │
│    - Keyboard / Mouse / Gamepad / VR / OS events                      │
├───────────────────────────────────────────────────────────────────────┤
│ 2) Slate tick                                                         │
│    - FSlateApplication::Tick()                                        │
│    - calls PollGameDeviceState()                                      │
│      └─ for each IInputDevice:                                        │
│         a) Device->Tick(DeltaTime)                                    │
│         b) Device->SendControllerEvents()                             │
│            └─ MessageHandler->OnControllerAnalog(...)                 │
│               (your LIO_* keys emit here)                             │
├───────────────────────────────────────────────────────────────────────┤
│ 3) Engine input processing                                            │
│    - Viewport → PlayerController                                      │
│    - Enhanced Input pipeline                                          │
│        • Active IMCs (priorities)                                     │
│        • Triggers / Modifiers                                         │
│        • InputActions receive values                                  │
├───────────────────────────────────────────────────────────────────────┤
│ 4) World/Gameplay tick                                                │
│    - Actors/Components Tick                                           │
│    - Your game logic reads Action values                              │
└───────────────────────────────────────────────────────────────────────┘

 */
class FLioInputDevice;
class FLioCoreModule : public IInputDeviceModule
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    /** Implements the rest of the IInputDeviceModule interface **/
    
    /** Creates a new instance of the IInputDevice associated with this IInputDeviceModule **/
    virtual TSharedPtr<IInputDevice> CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) override;
	
	// Access for the BP bridge
	static FLioInputDevice* GetDevice();

private:
	static FLioInputDevice* DeviceRaw; // not owning; lifetime managed by engine's TSharedPtr
};
bool RegisterAxis1DKeyIfNeeded(const FKey& Key, const FText& DisplayName, const FName& MenuCategory, const FText& CategoryDisplayName);
