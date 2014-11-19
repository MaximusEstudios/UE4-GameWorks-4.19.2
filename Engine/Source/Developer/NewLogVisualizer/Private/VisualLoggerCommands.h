// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#define LOCTEXT_NAMESPACE "FVisualLoggerCommands"


class FVisualLoggerCommands : public TCommands<FVisualLoggerCommands>
{
public:

	/** Default constructor. */
	FVisualLoggerCommands()
		: TCommands<FVisualLoggerCommands>("VisualLogger", NSLOCTEXT("Contexts", "VisualLogger", "Visual Logger"), NAME_None, "LogVisualizerStyle")
	{ }

public:

	// TCommands interface

	virtual void RegisterCommands() override
	{
		UI_COMMAND(StartRecording, "Start", "Start the debugger", EUserInterfaceActionType::Button, FInputGesture());
		UI_COMMAND(StopRecording, "Stop", "Step over the current message", EUserInterfaceActionType::Button, FInputGesture());
		UI_COMMAND(Pause, "Pause", "Stop the debugger", EUserInterfaceActionType::Button, FInputGesture());
		UI_COMMAND(Resume, "Resume", "Stop the debugger", EUserInterfaceActionType::Button, FInputGesture());
		UI_COMMAND(Load, "Load", "Load external vlogs", EUserInterfaceActionType::Button, FInputGesture());
		UI_COMMAND(Save, "Save", "Save selected data to vlog file", EUserInterfaceActionType::Button, FInputGesture());
	}

public:

	TSharedPtr<FUICommandInfo> StartRecording;
	TSharedPtr<FUICommandInfo> StopRecording;
	TSharedPtr<FUICommandInfo> Pause;
	TSharedPtr<FUICommandInfo> Resume;
	TSharedPtr<FUICommandInfo> Load;
	TSharedPtr<FUICommandInfo> Save;
};


#undef LOCTEXT_NAMESPACE
