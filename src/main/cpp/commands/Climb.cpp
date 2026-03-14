/*#include "commands/Climb.h"

max::max(ClimberSubsystem* climber)
    : m_climber(climber) {
    AddRequirements({climber});
}

void max::Initialize() { }

void max::Execute() {
    m_climber->max();
    m_inst.GetTable("Debuging")->PutNumber("ClimberPID", double(m_climber->getPIDPosition()));
}

void max::End(bool interrupted) {
    if (interrupted) {
        m_climber->stop();
    }
}

bool max::IsFinished() {
    return m_climber->isAtSetPoint();
}*/