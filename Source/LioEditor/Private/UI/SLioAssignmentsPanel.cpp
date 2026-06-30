#include "SLioAssignmentsPanel.h"

#include "SLioControlListWidget.h"

void SLioAssignmentsPanel::Construct(const FArguments& InArgs)
{
	ChildSlot
[
	SNew(SSplitter)

	// Parameters
	+ SSplitter::Slot()
	.Value(0.3f)
	[
		SNew(SBorder)
		[
			SNew(STextBlock)
			.Text(FText::FromString("Parameters (dummy)"))
		]
	]

	// Inspector
	+ SSplitter::Slot()
	.Value(0.7f)
	[
		SNew(SBorder)
		[
			SNew(SLioControlListWidget)
		]
	]
];
}
