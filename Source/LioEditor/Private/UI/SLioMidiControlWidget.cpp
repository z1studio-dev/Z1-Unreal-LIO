#include "SLioMidiControlWidget.h"

#include "Widgets/Layout/SBorder.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SSpinBox.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"

void SLioMidiControlWidget::Construct(const FArguments& InArgs)
{
    ChildSlot
    [
        SNew(SBorder)
        .Padding(8)
        [
            SNew(SVerticalBox)

            // Header
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SHorizontalBox)

                + SHorizontalBox::Slot()
                .FillWidth(1)
                [
                    SNew(STextBlock)
                    .Text(FText::FromString("MIDI Control"))
                ]

                + SHorizontalBox::Slot()
                .AutoWidth()
                [
                    SNew(SButton)
                    .Text(FText::FromString("X"))
                ]
            ]

            // Type (Note / CC)
            + SVerticalBox::Slot()
            .AutoHeight()
            .Padding(0,5)
            [
                SNew(SHorizontalBox)

                + SHorizontalBox::Slot()
                .AutoWidth()
                [
                    SNew(STextBlock)
                    .Text(FText::FromString("Type"))
                ]

                + SHorizontalBox::Slot()
                .FillWidth(1)
                [
                    SNew(SComboBox<TSharedPtr<FString>>)
                ]
            ]

            // Channel
            + SVerticalBox::Slot()
            .AutoHeight()
            .Padding(0,5)
            [
                SNew(SHorizontalBox)

                + SHorizontalBox::Slot()
                .AutoWidth()
                [
                    SNew(STextBlock)
                    .Text(FText::FromString("Channel"))
                ]

                + SHorizontalBox::Slot()
                .FillWidth(1)
                [
                    SNew(SSpinBox<int32>)
                    .MinValue(1)
                    .MaxValue(16)
                ]
            ]

            // CC / Note
            + SVerticalBox::Slot()
            .AutoHeight()
            .Padding(0,5)
            [
                SNew(SHorizontalBox)

                + SHorizontalBox::Slot()
                .AutoWidth()
                [
                    SNew(STextBlock)
                    .Text(FText::FromString("CC"))
                ]

                + SHorizontalBox::Slot()
                .FillWidth(1)
                [
                    SNew(SSpinBox<int32>)
                    .MinValue(0)
                    .MaxValue(127)
                ]
            ]

            // Input Range
            + SVerticalBox::Slot()
            .AutoHeight()
            .Padding(0,5)
            [
                SNew(STextBlock).Text(FText::FromString("Input Range"))
            ]

            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SSlider)
            ]

            // Output Range
            + SVerticalBox::Slot()
            .AutoHeight()
            .Padding(0,5)
            [
                SNew(STextBlock).Text(FText::FromString("Output Range"))
            ]

            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SSlider)
            ]

            // Curve (placeholder)
            + SVerticalBox::Slot()
            .AutoHeight()
            .Padding(0,5)
            [
                SNew(STextBlock)
                .Text(FText::FromString("Remap Curve"))
            ]

            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SBorder)
                .Padding(10)
                [
                    SNew(STextBlock)
                    .Text(FText::FromString("Curve Editor (todo)"))
                ]
            ]

            // Filter
            + SVerticalBox::Slot()
            .AutoHeight()
            .Padding(0,5)
            [
                SNew(STextBlock)
                .Text(FText::FromString("Filter"))
            ]
        ]
    ];
}