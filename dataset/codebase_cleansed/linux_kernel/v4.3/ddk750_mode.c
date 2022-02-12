static unsigned long displayControlAdjust_SM750LE(mode_parameter_t *pModeParam, unsigned long dispControl)
{
unsigned long x, y;
x = pModeParam->horizontal_display_end;
y = pModeParam->vertical_display_end;
POKE32(CRT_AUTO_CENTERING_TL,
FIELD_VALUE(0, CRT_AUTO_CENTERING_TL, TOP, 0)
| FIELD_VALUE(0, CRT_AUTO_CENTERING_TL, LEFT, 0));
POKE32(CRT_AUTO_CENTERING_BR,
FIELD_VALUE(0, CRT_AUTO_CENTERING_BR, BOTTOM, y-1)
| FIELD_VALUE(0, CRT_AUTO_CENTERING_BR, RIGHT, x-1));
dispControl &= FIELD_CLEAR(CRT_DISPLAY_CTRL, CLK);
if (x == 800 && y == 600)
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CLK, PLL41);
else if (x == 1024 && y == 768)
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CLK, PLL65);
else if (x == 1152 && y == 864)
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CLK, PLL80);
else if (x == 1280 && y == 768)
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CLK, PLL80);
else if (x == 1280 && y == 720)
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CLK, PLL74);
else if (x == 1280 && y == 960)
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CLK, PLL108);
else if (x == 1280 && y == 1024)
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CLK, PLL108);
else
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CLK, PLL25);
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CRTSELECT, CRT);
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, RGBBIT, 24BIT);
dispControl = FIELD_SET(dispControl, CRT_DISPLAY_CTRL, CLOCK_PHASE, ACTIVE_LOW);
POKE32(CRT_DISPLAY_CTRL, dispControl);
return dispControl;
}
static int programModeRegisters(mode_parameter_t *pModeParam, pll_value_t *pll)
{
int ret = 0;
int cnt = 0;
unsigned int ulTmpValue, ulReg;
if (pll->clockType == SECONDARY_PLL) {
POKE32(CRT_PLL_CTRL, formatPllReg(pll));
POKE32(CRT_HORIZONTAL_TOTAL,
FIELD_VALUE(0, CRT_HORIZONTAL_TOTAL, TOTAL, pModeParam->horizontal_total - 1)
| FIELD_VALUE(0, CRT_HORIZONTAL_TOTAL, DISPLAY_END, pModeParam->horizontal_display_end - 1));
POKE32(CRT_HORIZONTAL_SYNC,
FIELD_VALUE(0, CRT_HORIZONTAL_SYNC, WIDTH, pModeParam->horizontal_sync_width)
| FIELD_VALUE(0, CRT_HORIZONTAL_SYNC, START, pModeParam->horizontal_sync_start - 1));
POKE32(CRT_VERTICAL_TOTAL,
FIELD_VALUE(0, CRT_VERTICAL_TOTAL, TOTAL, pModeParam->vertical_total - 1)
| FIELD_VALUE(0, CRT_VERTICAL_TOTAL, DISPLAY_END, pModeParam->vertical_display_end - 1));
POKE32(CRT_VERTICAL_SYNC,
FIELD_VALUE(0, CRT_VERTICAL_SYNC, HEIGHT, pModeParam->vertical_sync_height)
| FIELD_VALUE(0, CRT_VERTICAL_SYNC, START, pModeParam->vertical_sync_start - 1));
ulTmpValue = FIELD_VALUE(0, CRT_DISPLAY_CTRL, VSYNC_PHASE, pModeParam->vertical_sync_polarity)|
FIELD_VALUE(0, CRT_DISPLAY_CTRL, HSYNC_PHASE, pModeParam->horizontal_sync_polarity)|
FIELD_SET(0, CRT_DISPLAY_CTRL, TIMING, ENABLE)|
FIELD_SET(0, CRT_DISPLAY_CTRL, PLANE, ENABLE);
if (getChipType() == SM750LE) {
displayControlAdjust_SM750LE(pModeParam, ulTmpValue);
} else {
ulReg = PEEK32(CRT_DISPLAY_CTRL)
& FIELD_CLEAR(CRT_DISPLAY_CTRL, VSYNC_PHASE)
& FIELD_CLEAR(CRT_DISPLAY_CTRL, HSYNC_PHASE)
& FIELD_CLEAR(CRT_DISPLAY_CTRL, TIMING)
& FIELD_CLEAR(CRT_DISPLAY_CTRL, PLANE);
POKE32(CRT_DISPLAY_CTRL, ulTmpValue|ulReg);
}
} else if (pll->clockType == PRIMARY_PLL) {
unsigned int ulReservedBits;
POKE32(PANEL_PLL_CTRL, formatPllReg(pll));
POKE32(PANEL_HORIZONTAL_TOTAL,
FIELD_VALUE(0, PANEL_HORIZONTAL_TOTAL, TOTAL, pModeParam->horizontal_total - 1)
| FIELD_VALUE(0, PANEL_HORIZONTAL_TOTAL, DISPLAY_END, pModeParam->horizontal_display_end - 1));
POKE32(PANEL_HORIZONTAL_SYNC,
FIELD_VALUE(0, PANEL_HORIZONTAL_SYNC, WIDTH, pModeParam->horizontal_sync_width)
| FIELD_VALUE(0, PANEL_HORIZONTAL_SYNC, START, pModeParam->horizontal_sync_start - 1));
POKE32(PANEL_VERTICAL_TOTAL,
FIELD_VALUE(0, PANEL_VERTICAL_TOTAL, TOTAL, pModeParam->vertical_total - 1)
| FIELD_VALUE(0, PANEL_VERTICAL_TOTAL, DISPLAY_END, pModeParam->vertical_display_end - 1));
POKE32(PANEL_VERTICAL_SYNC,
FIELD_VALUE(0, PANEL_VERTICAL_SYNC, HEIGHT, pModeParam->vertical_sync_height)
| FIELD_VALUE(0, PANEL_VERTICAL_SYNC, START, pModeParam->vertical_sync_start - 1));
ulTmpValue = FIELD_VALUE(0, PANEL_DISPLAY_CTRL, VSYNC_PHASE, pModeParam->vertical_sync_polarity)|
FIELD_VALUE(0, PANEL_DISPLAY_CTRL, HSYNC_PHASE, pModeParam->horizontal_sync_polarity)|
FIELD_VALUE(0, PANEL_DISPLAY_CTRL, CLOCK_PHASE, pModeParam->clock_phase_polarity)|
FIELD_SET(0, PANEL_DISPLAY_CTRL, TIMING, ENABLE)|
FIELD_SET(0, PANEL_DISPLAY_CTRL, PLANE, ENABLE);
ulReservedBits = FIELD_SET(0, PANEL_DISPLAY_CTRL, RESERVED_1_MASK, ENABLE) |
FIELD_SET(0, PANEL_DISPLAY_CTRL, RESERVED_2_MASK, ENABLE) |
FIELD_SET(0, PANEL_DISPLAY_CTRL, RESERVED_3_MASK, ENABLE)|
FIELD_SET(0, PANEL_DISPLAY_CTRL, VSYNC, ACTIVE_LOW);
ulReg = (PEEK32(PANEL_DISPLAY_CTRL) & ~ulReservedBits)
& FIELD_CLEAR(PANEL_DISPLAY_CTRL, CLOCK_PHASE)
& FIELD_CLEAR(PANEL_DISPLAY_CTRL, VSYNC_PHASE)
& FIELD_CLEAR(PANEL_DISPLAY_CTRL, HSYNC_PHASE)
& FIELD_CLEAR(PANEL_DISPLAY_CTRL, TIMING)
& FIELD_CLEAR(PANEL_DISPLAY_CTRL, PLANE);
POKE32(PANEL_DISPLAY_CTRL, ulTmpValue|ulReg);
#if 1
while ((PEEK32(PANEL_DISPLAY_CTRL) & ~ulReservedBits) != (ulTmpValue|ulReg)) {
cnt++;
if (cnt > 1000)
break;
POKE32(PANEL_DISPLAY_CTRL, ulTmpValue|ulReg);
}
#endif
} else {
ret = -1;
}
return ret;
}
int ddk750_setModeTiming(mode_parameter_t *parm, clock_type_t clock)
{
pll_value_t pll;
unsigned int uiActualPixelClk;
pll.inputFreq = DEFAULT_INPUT_CLOCK;
pll.clockType = clock;
uiActualPixelClk = calcPllValue(parm->pixel_clock, &pll);
if (getChipType() == SM750LE) {
outb_p(0x88, 0x3d4);
outb_p(0x06, 0x3d5);
}
programModeRegisters(parm, &pll);
return 0;
}
