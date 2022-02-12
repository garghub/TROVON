static void setDisplayControl(int ctrl,int dispState)
{
unsigned long ulDisplayCtrlReg, ulReservedBits;
int cnt;
cnt = 0;
if (!ctrl)
{
ulDisplayCtrlReg = PEEK32(PANEL_DISPLAY_CTRL);
if (dispState)
{
ulDisplayCtrlReg = FIELD_SET(ulDisplayCtrlReg,
PANEL_DISPLAY_CTRL, TIMING, ENABLE);
POKE32(PANEL_DISPLAY_CTRL, ulDisplayCtrlReg);
ulDisplayCtrlReg = FIELD_SET(ulDisplayCtrlReg,
PANEL_DISPLAY_CTRL, PLANE, ENABLE);
ulReservedBits = FIELD_SET(0, PANEL_DISPLAY_CTRL, RESERVED_1_MASK, ENABLE) |
FIELD_SET(0, PANEL_DISPLAY_CTRL, RESERVED_2_MASK, ENABLE) |
FIELD_SET(0, PANEL_DISPLAY_CTRL, RESERVED_3_MASK, ENABLE);
do
{
cnt++;
POKE32(PANEL_DISPLAY_CTRL, ulDisplayCtrlReg);
} while((PEEK32(PANEL_DISPLAY_CTRL) & ~ulReservedBits) !=
(ulDisplayCtrlReg & ~ulReservedBits));
printk("Set Panel Plane enbit:after tried %d times\n",cnt);
}
else
{
ulDisplayCtrlReg = FIELD_SET(ulDisplayCtrlReg,
PANEL_DISPLAY_CTRL, PLANE, DISABLE);
POKE32(PANEL_DISPLAY_CTRL, ulDisplayCtrlReg);
ulDisplayCtrlReg = FIELD_SET(ulDisplayCtrlReg,
PANEL_DISPLAY_CTRL, TIMING, DISABLE);
POKE32(PANEL_DISPLAY_CTRL, ulDisplayCtrlReg);
}
}
else
{
ulDisplayCtrlReg = PEEK32(CRT_DISPLAY_CTRL);
if (dispState)
{
ulDisplayCtrlReg = FIELD_SET(ulDisplayCtrlReg,
CRT_DISPLAY_CTRL, TIMING, ENABLE);
POKE32(CRT_DISPLAY_CTRL, ulDisplayCtrlReg);
ulDisplayCtrlReg = FIELD_SET(ulDisplayCtrlReg,
CRT_DISPLAY_CTRL, PLANE, ENABLE);
ulReservedBits = FIELD_SET(0, CRT_DISPLAY_CTRL, RESERVED_1_MASK, ENABLE) |
FIELD_SET(0, CRT_DISPLAY_CTRL, RESERVED_2_MASK, ENABLE) |
FIELD_SET(0, CRT_DISPLAY_CTRL, RESERVED_3_MASK, ENABLE) |
FIELD_SET(0, CRT_DISPLAY_CTRL, RESERVED_4_MASK, ENABLE);
do
{
cnt++;
POKE32(CRT_DISPLAY_CTRL, ulDisplayCtrlReg);
} while((PEEK32(CRT_DISPLAY_CTRL) & ~ulReservedBits) !=
(ulDisplayCtrlReg & ~ulReservedBits));
printk("Set Crt Plane enbit:after tried %d times\n",cnt);
}
else
{
ulDisplayCtrlReg = FIELD_SET(ulDisplayCtrlReg,
CRT_DISPLAY_CTRL, PLANE, DISABLE);
POKE32(CRT_DISPLAY_CTRL, ulDisplayCtrlReg);
ulDisplayCtrlReg = FIELD_SET(ulDisplayCtrlReg,
CRT_DISPLAY_CTRL, TIMING, DISABLE);
POKE32(CRT_DISPLAY_CTRL, ulDisplayCtrlReg);
}
}
}
static void waitNextVerticalSync(int ctrl,int delay)
{
unsigned int status;
if(!ctrl){
if ((FIELD_GET(PEEK32(PANEL_PLL_CTRL), PANEL_PLL_CTRL, POWER) ==
PANEL_PLL_CTRL_POWER_OFF) ||
(FIELD_GET(PEEK32(PANEL_DISPLAY_CTRL), PANEL_DISPLAY_CTRL, TIMING) ==
PANEL_DISPLAY_CTRL_TIMING_DISABLE))
{
return;
}
while (delay-- > 0)
{
do
{
status = FIELD_GET(PEEK32(SYSTEM_CTRL),
SYSTEM_CTRL,
PANEL_VSYNC);
}
while (status == SYSTEM_CTRL_PANEL_VSYNC_ACTIVE);
do
{
status = FIELD_GET(PEEK32(SYSTEM_CTRL),
SYSTEM_CTRL,
PANEL_VSYNC);
}
while (status == SYSTEM_CTRL_PANEL_VSYNC_INACTIVE);
}
}else{
if ((FIELD_GET(PEEK32(CRT_PLL_CTRL), CRT_PLL_CTRL, POWER) ==
CRT_PLL_CTRL_POWER_OFF) ||
(FIELD_GET(PEEK32(CRT_DISPLAY_CTRL), CRT_DISPLAY_CTRL, TIMING) ==
CRT_DISPLAY_CTRL_TIMING_DISABLE))
{
return;
}
while (delay-- > 0)
{
do
{
status = FIELD_GET(PEEK32(SYSTEM_CTRL),
SYSTEM_CTRL,
CRT_VSYNC);
}
while (status == SYSTEM_CTRL_CRT_VSYNC_ACTIVE);
do
{
status = FIELD_GET(PEEK32(SYSTEM_CTRL),
SYSTEM_CTRL,
CRT_VSYNC);
}
while (status == SYSTEM_CTRL_CRT_VSYNC_INACTIVE);
}
}
}
static void swPanelPowerSequence(int disp,int delay)
{
unsigned int reg;
reg = PEEK32(PANEL_DISPLAY_CTRL);
reg = FIELD_VALUE(reg,PANEL_DISPLAY_CTRL,FPEN,disp);
POKE32(PANEL_DISPLAY_CTRL,reg);
primaryWaitVerticalSync(delay);
reg = PEEK32(PANEL_DISPLAY_CTRL);
reg = FIELD_VALUE(reg,PANEL_DISPLAY_CTRL,DATA,disp);
POKE32(PANEL_DISPLAY_CTRL,reg);
primaryWaitVerticalSync(delay);
reg = PEEK32(PANEL_DISPLAY_CTRL);
reg = FIELD_VALUE(reg,PANEL_DISPLAY_CTRL,VBIASEN,disp);
POKE32(PANEL_DISPLAY_CTRL,reg);
primaryWaitVerticalSync(delay);
reg = PEEK32(PANEL_DISPLAY_CTRL);
reg = FIELD_VALUE(reg,PANEL_DISPLAY_CTRL,FPEN,disp);
POKE32(PANEL_DISPLAY_CTRL,reg);
primaryWaitVerticalSync(delay);
}
void ddk750_setLogicalDispOut(disp_output_t output)
{
unsigned int reg;
if(output & PNL_2_USAGE){
reg = PEEK32(PANEL_DISPLAY_CTRL);
reg = FIELD_VALUE(reg,PANEL_DISPLAY_CTRL,SELECT,(output & PNL_2_MASK)>>PNL_2_OFFSET);
POKE32(PANEL_DISPLAY_CTRL,reg);
}
if(output & CRT_2_USAGE){
reg = PEEK32(CRT_DISPLAY_CTRL);
reg = FIELD_VALUE(reg,CRT_DISPLAY_CTRL,SELECT,(output & CRT_2_MASK)>>CRT_2_OFFSET);
reg = FIELD_SET(reg,CRT_DISPLAY_CTRL,BLANK,OFF);
POKE32(CRT_DISPLAY_CTRL,reg);
}
if(output & PRI_TP_USAGE){
setDisplayControl(0,(output&PRI_TP_MASK)>>PRI_TP_OFFSET);
}
if(output & SEC_TP_USAGE){
setDisplayControl(1,(output&SEC_TP_MASK)>>SEC_TP_OFFSET);
}
if(output & PNL_SEQ_USAGE){
swPanelPowerSequence((output&PNL_SEQ_MASK)>>PNL_SEQ_OFFSET,4);
}
if(output & DAC_USAGE)
setDAC((output & DAC_MASK)>>DAC_OFFSET);
if(output & DPMS_USAGE)
ddk750_setDPMS((output & DPMS_MASK) >> DPMS_OFFSET);
}
int ddk750_initDVIDisp(void)
{
if ((dviInit(1,
1,
0,
1,
1,
1,
7,
1,
1,
4
) != 0) && (dviGetVendorID() != 0x0000) && (dviGetDeviceID() != 0x0000))
{
return (-1);
}
return 0;
}
