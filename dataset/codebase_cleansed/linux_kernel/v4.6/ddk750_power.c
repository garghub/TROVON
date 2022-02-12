void ddk750_setDPMS(DPMS_t state)
{
unsigned int value;
if (getChipType() == SM750LE) {
value = PEEK32(CRT_DISPLAY_CTRL) & ~CRT_DISPLAY_CTRL_DPMS_MASK;
value |= (state << CRT_DISPLAY_CTRL_DPMS_SHIFT);
POKE32(CRT_DISPLAY_CTRL, value);
} else {
value = PEEK32(SYSTEM_CTRL);
value = (value & ~SYSTEM_CTRL_DPMS_MASK) | state;
POKE32(SYSTEM_CTRL, value);
}
}
static unsigned int getPowerMode(void)
{
if (getChipType() == SM750LE)
return 0;
return PEEK32(POWER_MODE_CTRL) & POWER_MODE_CTRL_MODE_MASK;
}
void setPowerMode(unsigned int powerMode)
{
unsigned int control_value = 0;
control_value = PEEK32(POWER_MODE_CTRL) & ~POWER_MODE_CTRL_MODE_MASK;
if (getChipType() == SM750LE)
return;
switch (powerMode) {
case POWER_MODE_CTRL_MODE_MODE0:
control_value |= POWER_MODE_CTRL_MODE_MODE0;
break;
case POWER_MODE_CTRL_MODE_MODE1:
control_value |= POWER_MODE_CTRL_MODE_MODE1;
break;
case POWER_MODE_CTRL_MODE_SLEEP:
control_value |= POWER_MODE_CTRL_MODE_SLEEP;
break;
default:
break;
}
if (powerMode == POWER_MODE_CTRL_MODE_SLEEP) {
control_value &= ~POWER_MODE_CTRL_OSC_INPUT;
#ifdef VALIDATION_CHIP
control_value &= ~POWER_MODE_CTRL_336CLK;
#endif
} else {
control_value |= POWER_MODE_CTRL_OSC_INPUT;
#ifdef VALIDATION_CHIP
control_value |= POWER_MODE_CTRL_336CLK;
#endif
}
POKE32(POWER_MODE_CTRL, control_value);
}
void setCurrentGate(unsigned int gate)
{
unsigned int gate_reg;
unsigned int mode;
mode = getPowerMode();
switch (mode) {
case POWER_MODE_CTRL_MODE_MODE0:
gate_reg = MODE0_GATE;
break;
case POWER_MODE_CTRL_MODE_MODE1:
gate_reg = MODE1_GATE;
break;
default:
gate_reg = MODE0_GATE;
break;
}
POKE32(gate_reg, gate);
}
void enable2DEngine(unsigned int enable)
{
u32 gate;
gate = PEEK32(CURRENT_GATE);
if (enable)
gate |= (CURRENT_GATE_DE | CURRENT_GATE_CSC);
else
gate &= ~(CURRENT_GATE_DE | CURRENT_GATE_CSC);
setCurrentGate(gate);
}
void enableDMA(unsigned int enable)
{
u32 gate;
gate = PEEK32(CURRENT_GATE);
if (enable)
gate |= CURRENT_GATE_DMA;
else
gate &= ~CURRENT_GATE_DMA;
setCurrentGate(gate);
}
void enableGPIO(unsigned int enable)
{
u32 gate;
gate = PEEK32(CURRENT_GATE);
if (enable)
gate |= CURRENT_GATE_GPIO;
else
gate &= ~CURRENT_GATE_GPIO;
setCurrentGate(gate);
}
void enableI2C(unsigned int enable)
{
u32 gate;
gate = PEEK32(CURRENT_GATE);
if (enable)
gate |= CURRENT_GATE_I2C;
else
gate &= ~CURRENT_GATE_I2C;
setCurrentGate(gate);
}
