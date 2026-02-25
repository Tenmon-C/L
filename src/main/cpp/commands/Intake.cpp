#include "commands/Intake.h"

Intake::Intake(IntakeSubsystem* intake, double speed) {
    AddRequirements({intake});
}
void Intake::Initialize() {
}
void Intake::Execute() {
    m_intake->SetIntake(m_speed);
}
void Intake::End(bool interrupted) {
    if (interrupted) {
        m_intake->Stop();
    }
}
bool Intake::IsFinished() {
    return false;
}