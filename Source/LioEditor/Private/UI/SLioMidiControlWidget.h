#pragma once
#include "Widgets/SCompoundWidget.h"

class SLioMidiControlWidget : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SLioMidiControlWidget) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
};
