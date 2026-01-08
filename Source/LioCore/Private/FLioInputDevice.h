// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "IInputDevice.h"


class LIOCORE_API FLioInputDevice : public IInputDevice
{
public:
	FLioInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler);
	virtual ~FLioInputDevice() override;

	/** Tick the interface (e.g. check for new controllers) */
	virtual void Tick(float DeltaTime) override;

	/** Poll for controller state and send events if needed */
	virtual void SendControllerEvents() override;

	/** Set which MessageHandler will get the events from SendControllerEvents. */
	virtual void SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;

	/** Exec handler to allow console commands to be passed through for debugging */
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;

	/** IForceFeedbackSystem pass through functions **/
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override;
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values) override;

	void PushAnalog(const FKey& key, float value);
private:

	// Thread-safety: allow pushing while engine pulls in SendControllerEvents()
	FCriticalSection Mutex;

	// Latest analog value per key (last write wins within the frame)
	TMap<FKey, float> PendingAnalog;
	
	TSharedRef<FGenericApplicationMessageHandler> MessageHandler;
};
