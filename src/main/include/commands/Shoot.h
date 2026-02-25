#pragma once
#include <frc2/command/Commands.h>
#include <frc2/command/Commandhelper.h>
#include "subsystems/IntakeSubsystem.h"
class Shoot : public frc2::CommandHelper<frc2::Command, Shoot> {
    public: 
        Shoot(IntakeSubsystem* Shooting, double speed);
        
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;
    private: 
        IntakeSubsystem* m_intake;
        double m_speed;
};