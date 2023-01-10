#include <MPG.h>

class Gamepad : public MPG
{
  public:
    Gamepad(int debounceMS = 5) : MPG(debounceMS) { }
    void read() override;
}

MPGSettings _mpgSettings;

void Gamepad::read() {
  // Read dpad inptus
  state.dpad = 0
    | ((ports[PORTF_INDEX] >> PORT_PIN_UP    & 1)  ? GAMEPAD_MASK_UP    : 0)
    | ((ports[PORTF_INDEX] >> PORT_PIN_DOWN  & 1)  ? GAMEPAD_MASK_DOWN  : 0)
    | ((ports[PORTF_INDEX] >> PORT_PIN_LEFT  & 1)  ? GAMEPAD_MASK_LEFT  : 0)
    | ((ports[PORTF_INDEX] >> PORT_PIN_RIGHT & 1)  ? GAMEPAD_MASK_RIGHT : 0)
  ;

  // Read button inputs
  state.buttons = 0
    | ((ports[PORTD_INDEX] >> PORT_PIN_K1 & 1)     ? GAMEPAD_MASK_B1    : 0)
    | ((ports[PORTD_INDEX] >> PORT_PIN_K2 & 1)     ? GAMEPAD_MASK_B2    : 0)
    | ((ports[PORTD_INDEX] >> PORT_PIN_P1 & 1)     ? GAMEPAD_MASK_B3    : 0)
    | ((ports[PORTD_INDEX] >> PORT_PIN_P2 & 1)     ? GAMEPAD_MASK_B4    : 0)
    | ((ports[PORTD_INDEX] >> PORT_PIN_P4 & 1)     ? GAMEPAD_MASK_L1    : 0)
    | ((ports[PORTB_INDEX] >> PORT_PIN_P3 & 1)     ? GAMEPAD_MASK_R1    : 0)
    | ((ports[PORTD_INDEX] >> PORT_PIN_K4 & 1)     ? GAMEPAD_MASK_L2    : 0)
    | ((ports[PORTB_INDEX] >> PORT_PIN_K3 & 1)     ? GAMEPAD_MASK_R2    : 0)
    | ((ports[PORTB_INDEX] >> PORT_PIN_SELECT & 1) ? GAMEPAD_MASK_S1    : 0)
    | ((ports[PORTB_INDEX] >> PORT_PIN_START & 1)  ? GAMEPAD_MASK_S2    : 0)
    | ((ports[PORTB_INDEX] >> PORT_PIN_LS & 1)     ? GAMEPAD_MASK_L3    : 0)
    | ((ports[PORTB_INDEX] >> PORT_PIN_RS & 1)     ? GAMEPAD_MASK_R3    : 0)
  ;

  // No analog, but could read them here with analogRead() or fill outside of this method
  state.lt = 0;
  state.rt = 0;
  state.lx = GAMEPAD_JOYSTICK_MID;
  state.ly = GAMEPAD_JOYSTICK_MID;
  state.rx = GAMEPAD_JOYSTICK_MID;
  state.ry = GAMEPAD_JOYSTICK_MID;
}

// 32u4 doesn't need these, but others might!
void GamepadStorage::start() { }
void GamepadStorage::save() { }
