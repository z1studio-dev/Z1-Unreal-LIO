#pragma once
#include "Widgets/SCompoundWidget.h"
class SLioControlListWidget : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SLioControlListWidget) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	
private:

	FReply OnAddControlClicked();
	TSharedRef<SWidget> GenerateAddMenu();

	TSharedPtr<SVerticalBox> ControlsBox;
};
