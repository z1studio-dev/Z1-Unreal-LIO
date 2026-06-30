#pragma once
#include "Widgets/SCompoundWidget.h"
class SLioAssignmentsPanel : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SLioAssignmentsPanel) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
};
