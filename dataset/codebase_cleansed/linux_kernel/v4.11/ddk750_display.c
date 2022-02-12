static void setDisplayControl(int ctrl, int disp_state)
{
unsigned long reg, val, reserved;
int cnt = 0;
if (!ctrl) {
reg = PANEL_DISPLAY_CTRL;
reserved = PANEL_DISPLAY_CTRL_RESERVED_MASK;
} else {
reg = CRT_DISPLAY_CTRL;
reserved = CRT_DISPLAY_CTRL_RESERVED_MASK;
}
val = peek32(reg);
if (disp_state) {
val |= DISPLAY_CTRL_TIMING;
poke32(reg, val);
val |= DISPLAY_CTRL_PLANE;
do {
cnt++;
poke32(reg, val);
} while ((peek32(reg) & ~reserved) != (val & ~reserved));
pr_debug("Set Plane enbit:after tried %d times\n", cnt);
} else {
val &= ~DISPLAY_CTRL_PLANE;
poke32(reg, val);
val &= ~DISPLAY_CTRL_TIMING;
poke32(reg, val);
}
}
static void primary_wait_vertical_sync(int delay)
{
unsigned int status;
if (!(peek32(PANEL_PLL_CTRL) & PLL_CTRL_POWER) ||
!(peek32(PANEL_DISPLAY_CTRL) & DISPLAY_CTRL_TIMING))
return;
while (delay-- > 0) {
do {
status = peek32(SYSTEM_CTRL);
} while (status & SYSTEM_CTRL_PANEL_VSYNC_ACTIVE);
do {
status = peek32(SYSTEM_CTRL);
} while (!(status & SYSTEM_CTRL_PANEL_VSYNC_ACTIVE));
}
}
static void swPanelPowerSequence(int disp, int delay)
{
unsigned int reg;
reg = peek32(PANEL_DISPLAY_CTRL);
reg |= (disp ? PANEL_DISPLAY_CTRL_FPEN : 0);
poke32(PANEL_DISPLAY_CTRL, reg);
primary_wait_vertical_sync(delay);
reg = peek32(PANEL_DISPLAY_CTRL);
reg |= (disp ? PANEL_DISPLAY_CTRL_DATA : 0);
poke32(PANEL_DISPLAY_CTRL, reg);
primary_wait_vertical_sync(delay);
reg = peek32(PANEL_DISPLAY_CTRL);
reg |= (disp ? PANEL_DISPLAY_CTRL_VBIASEN : 0);
poke32(PANEL_DISPLAY_CTRL, reg);
primary_wait_vertical_sync(delay);
reg = peek32(PANEL_DISPLAY_CTRL);
reg |= (disp ? PANEL_DISPLAY_CTRL_FPEN : 0);
poke32(PANEL_DISPLAY_CTRL, reg);
primary_wait_vertical_sync(delay);
}
void ddk750_setLogicalDispOut(disp_output_t output)
{
unsigned int reg;
if (output & PNL_2_USAGE) {
reg = peek32(PANEL_DISPLAY_CTRL);
reg &= ~PANEL_DISPLAY_CTRL_SELECT_MASK;
reg |= (((output & PNL_2_MASK) >> PNL_2_OFFSET) <<
PANEL_DISPLAY_CTRL_SELECT_SHIFT);
poke32(PANEL_DISPLAY_CTRL, reg);
}
if (output & CRT_2_USAGE) {
reg = peek32(CRT_DISPLAY_CTRL);
reg &= ~CRT_DISPLAY_CTRL_SELECT_MASK;
reg |= (((output & CRT_2_MASK) >> CRT_2_OFFSET) <<
CRT_DISPLAY_CTRL_SELECT_SHIFT);
reg &= ~CRT_DISPLAY_CTRL_BLANK;
poke32(CRT_DISPLAY_CTRL, reg);
}
if (output & PRI_TP_USAGE) {
setDisplayControl(0, (output & PRI_TP_MASK) >> PRI_TP_OFFSET);
}
if (output & SEC_TP_USAGE) {
setDisplayControl(1, (output & SEC_TP_MASK) >> SEC_TP_OFFSET);
}
if (output & PNL_SEQ_USAGE) {
swPanelPowerSequence((output & PNL_SEQ_MASK) >> PNL_SEQ_OFFSET, 4);
}
if (output & DAC_USAGE)
setDAC((output & DAC_MASK) >> DAC_OFFSET);
if (output & DPMS_USAGE)
ddk750_set_dpms((output & DPMS_MASK) >> DPMS_OFFSET);
}
