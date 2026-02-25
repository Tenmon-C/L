#include "commands/Shoot.h"

Shoot::Shoot(IntakeSubsystem* Shooting, double speed) {
    AddRequirements({Shooting});
}
void Shoot::Initialize() {
}
void Shoot::Execute() {
    m_intake->SetIntake(m_speed);
}
void Shoot::End(bool interrupted) {
    if (interrupted) {
        m_intake->Stop();
    }
}
bool Shoot::IsFinished() {
    return false;
}