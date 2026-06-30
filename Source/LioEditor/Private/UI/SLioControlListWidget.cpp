#include "SLioControlListWidget.h"

#include "SLioMidiControlWidget.h"

void SLioControlListWidget::Construct(const FArguments& InArgs)
{
	
	ChildSlot
[
	SNew(SBorder)
	[
		SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SAssignNew(ControlsBox, SVerticalBox)
		]

		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SButton)
			.Text(FText::FromString("+ Add Control"))
			.OnClicked(this, &SLioControlListWidget::OnAddControlClicked)
		]
	]
];
}

FReply SLioControlListWidget::OnAddControlClicked()
{
	FSlateApplication::Get().PushMenu(
		AsShared(),
		FWidgetPath(),
		GenerateAddMenu(),
		FSlateApplication::Get().GetCursorPos(),
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu)
	);

	return FReply::Handled();
}

TSharedRef<SWidget> SLioControlListWidget::GenerateAddMenu()
{
	FMenuBuilder MenuBuilder(true, nullptr);

	MenuBuilder.AddMenuEntry(
		FText::FromString("MIDI"),
		FText::FromString("Add MIDI control"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateLambda([this]()
		{
			ControlsBox->AddSlot()
			.AutoHeight()
			[
				SNew(SLioMidiControlWidget)
			];
		}))
	);

	MenuBuilder.AddMenuEntry(
		FText::FromString("OSC"),
		FText::FromString("Add OSC control"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateLambda([this]()
		{
			ControlsBox->AddSlot()
			.AutoHeight()
			[
				SNew(STextBlock).Text(FText::FromString("OSC Control (dummy)"))
			];
		}))
	);

	MenuBuilder.AddMenuEntry(
		FText::FromString("DMX"),
		FText::FromString("Add DMX control"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateLambda([this]()
		{
			ControlsBox->AddSlot()
			.AutoHeight()
			[
				SNew(STextBlock).Text(FText::FromString("DMX Control (dummy)"))
			];
		}))
	);

	return MenuBuilder.MakeWidget();
}