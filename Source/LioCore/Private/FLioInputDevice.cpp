// Fill out your copyright notice in the Description page of Project Settings.


#include "FLioInputDevice.h"

FLioInputDevice::FLioInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
:MessageHandler(InMessageHandler)
{
	//Init device here
}

FLioInputDevice::~FLioInputDevice()
{
	//close device here
}

void FLioInputDevice::Tick(float DeltaTime)
{

}

void FLioInputDevice::SendControllerEvents()
{
	// Build a local snapshot so we don't hold the lock while calling into the engine
	TArray<TPair<FKey, float>> Snapshot;
	{
		FScopeLock _(&Mutex);
		Snapshot.Reserve(PendingAnalog.Num());
		for (const TPair<FKey, float>& It : PendingAnalog)
		{
			Snapshot.Add(It);
		}
	}

	// Single virtual controller; extend to multiple if needed

	// Emit analog events for each registered key
	for (const TPair<FKey, float>& It : Snapshot)
	{
		const auto& Addr = It.Key.GetFName();
		const auto Value = It.Value;

		// Use the key's FName; Enhanced Input will route this via IMC mappings
		MessageHandler->OnControllerAnalog(Addr, PLATFORMUSERID_NONE,
			FInputDeviceId::CreateFromInternalId(0), Value);
	}
}

void FLioInputDevice::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool FLioInputDevice::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
	return false;
}

void FLioInputDevice::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
}

void FLioInputDevice::SetChannelValues(int32 ControllerId, const FForceFeedbackValues& values)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
}

void FLioInputDevice::PushAnalog(const FKey& key, float value)
{
	{
		FScopeLock Lock(&Mutex);
		PendingAnalog.FindOrAdd(key) = value;		
	}
}
