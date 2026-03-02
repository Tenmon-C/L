#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/Command.h>
#include "subsystems/ClimberSubsystem.h"

class max : public frc2::CommandHelper<frc2::Command, max> {
public:
    max(ClimberSubsystem* climber);

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

private:
    ClimberSubsystem* m_climber;
};