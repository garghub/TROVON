void ddk750_set_dpms(DPMS_t state)
{
unsigned int value;
if (sm750_get_chip_type() == SM750LE) {
value = peek32(CRT_DISPLAY_CTRL) & ~CRT_DISPLAY_CTRL_DPMS_MASK;
value |= (state << CRT_DISPLAY_CTRL_DPMS_SHIFT);
poke32(CRT_DISPLAY_CTRL, value);
} else {
value = peek32(SYSTEM_CTRL);
value = (value & ~SYSTEM_CTRL_DPMS_MASK) | state;
poke32(SYSTEM_CTRL, value);
}
}
static unsigned int get_power_mode(void)
{
if (sm750_get_chip_type() == SM750LE)
return 0;
return peek32(POWER_MODE_CTRL) & POWER_MODE_CTRL_MODE_MASK;
}
void sm750_set_power_mode(unsigned int mode)
{
unsigned int ctrl = 0;
ctrl = peek32(POWER_MODE_CTRL) & ~POWER_MODE_CTRL_MODE_MASK;
if (sm750_get_chip_type() == SM750LE)
return;
switch (mode) {
case POWER_MODE_CTRL_MODE_MODE0:
ctrl |= POWER_MODE_CTRL_MODE_MODE0;
break;
case POWER_MODE_CTRL_MODE_MODE1:
ctrl |= POWER_MODE_CTRL_MODE_MODE1;
break;
case POWER_MODE_CTRL_MODE_SLEEP:
ctrl |= POWER_MODE_CTRL_MODE_SLEEP;
break;
default:
break;
}
if (mode == POWER_MODE_CTRL_MODE_SLEEP) {
ctrl &= ~POWER_MODE_CTRL_OSC_INPUT;
#ifdef VALIDATION_CHIP
ctrl &= ~POWER_MODE_CTRL_336CLK;
#endif
} else {
ctrl |= POWER_MODE_CTRL_OSC_INPUT;
#ifdef VALIDATION_CHIP
ctrl |= POWER_MODE_CTRL_336CLK;
#endif
}
poke32(POWER_MODE_CTRL, ctrl);
}
void sm750_set_current_gate(unsigned int gate)
{
if (get_power_mode() == POWER_MODE_CTRL_MODE_MODE1)
poke32(MODE1_GATE, gate);
else
poke32(MODE0_GATE, gate);
}
void sm750_enable_2d_engine(unsigned int enable)
{
u32 gate;
gate = peek32(CURRENT_GATE);
if (enable)
gate |= (CURRENT_GATE_DE | CURRENT_GATE_CSC);
else
gate &= ~(CURRENT_GATE_DE | CURRENT_GATE_CSC);
sm750_set_current_gate(gate);
}
void sm750_enable_dma(unsigned int enable)
{
u32 gate;
gate = peek32(CURRENT_GATE);
if (enable)
gate |= CURRENT_GATE_DMA;
else
gate &= ~CURRENT_GATE_DMA;
sm750_set_current_gate(gate);
}
void sm750_enable_gpio(unsigned int enable)
{
u32 gate;
gate = peek32(CURRENT_GATE);
if (enable)
gate |= CURRENT_GATE_GPIO;
else
gate &= ~CURRENT_GATE_GPIO;
sm750_set_current_gate(gate);
}
void sm750_enable_i2c(unsigned int enable)
{
u32 gate;
gate = peek32(CURRENT_GATE);
if (enable)
gate |= CURRENT_GATE_I2C;
else
gate &= ~CURRENT_GATE_I2C;
sm750_set_current_gate(gate);
}
