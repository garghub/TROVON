logical_chip_type_t getChipType(void)
{
unsigned short physicalID;
char physicalRev;
logical_chip_type_t chip;
physicalID = devId750;
physicalRev = revId750;
if (physicalID == 0x718)
chip = SM718;
else if (physicalID == 0x750) {
chip = SM750;
if (physicalRev == SM750LE_REVISION_ID)
chip = SM750LE;
} else
chip = SM_UNKNOWN;
return chip;
}
inline unsigned int twoToPowerOfx(unsigned long x)
{
unsigned long i;
unsigned long result = 1;
for (i = 1; i <= x; i++)
result *= 2;
return result;
}
inline unsigned int calcPLL(pll_value_t *pPLL)
{
return (pPLL->inputFreq * pPLL->M / pPLL->N / twoToPowerOfx(pPLL->OD) / twoToPowerOfx(pPLL->POD));
}
unsigned int getPllValue(clock_type_t clockType, pll_value_t *pPLL)
{
unsigned int ulPllReg = 0;
pPLL->inputFreq = DEFAULT_INPUT_CLOCK;
pPLL->clockType = clockType;
switch (clockType) {
case MXCLK_PLL:
ulPllReg = PEEK32(MXCLK_PLL_CTRL);
break;
case PRIMARY_PLL:
ulPllReg = PEEK32(PANEL_PLL_CTRL);
break;
case SECONDARY_PLL:
ulPllReg = PEEK32(CRT_PLL_CTRL);
break;
case VGA0_PLL:
ulPllReg = PEEK32(VGA_PLL0_CTRL);
break;
case VGA1_PLL:
ulPllReg = PEEK32(VGA_PLL1_CTRL);
break;
}
pPLL->M = FIELD_GET(ulPllReg, PANEL_PLL_CTRL, M);
pPLL->N = FIELD_GET(ulPllReg, PANEL_PLL_CTRL, N);
pPLL->OD = FIELD_GET(ulPllReg, PANEL_PLL_CTRL, OD);
pPLL->POD = FIELD_GET(ulPllReg, PANEL_PLL_CTRL, POD);
return calcPLL(pPLL);
}
unsigned int getChipClock(void)
{
pll_value_t pll;
#if 1
if (getChipType() == SM750LE)
return MHz(130);
#endif
return getPllValue(MXCLK_PLL, &pll);
}
void setChipClock(unsigned int frequency)
{
pll_value_t pll;
unsigned int ulActualMxClk;
#if 1
if (getChipType() == SM750LE)
return;
#endif
if (frequency) {
pll.inputFreq = DEFAULT_INPUT_CLOCK;
pll.clockType = MXCLK_PLL;
ulActualMxClk = calcPllValue(frequency, &pll);
POKE32(MXCLK_PLL_CTRL, formatPllReg(&pll));
}
}
void setMemoryClock(unsigned int frequency)
{
unsigned int ulReg, divisor;
#if 1
if (getChipType() == SM750LE)
return;
#endif
if (frequency) {
if (frequency > MHz(336))
frequency = MHz(336);
divisor = (unsigned int) roundedDiv(getChipClock(), frequency);
ulReg = PEEK32(CURRENT_GATE);
switch (divisor) {
default:
case 1:
ulReg = FIELD_SET(ulReg, CURRENT_GATE, M2XCLK, DIV_1);
break;
case 2:
ulReg = FIELD_SET(ulReg, CURRENT_GATE, M2XCLK, DIV_2);
break;
case 3:
ulReg = FIELD_SET(ulReg, CURRENT_GATE, M2XCLK, DIV_3);
break;
case 4:
ulReg = FIELD_SET(ulReg, CURRENT_GATE, M2XCLK, DIV_4);
break;
}
setCurrentGate(ulReg);
}
}
void setMasterClock(unsigned int frequency)
{
unsigned int ulReg, divisor;
#if 1
if (getChipType() == SM750LE)
return;
#endif
if (frequency) {
if (frequency > MHz(190))
frequency = MHz(190);
divisor = (unsigned int) roundedDiv(getChipClock(), frequency);
ulReg = PEEK32(CURRENT_GATE);
switch (divisor) {
default:
case 3:
ulReg = FIELD_SET(ulReg, CURRENT_GATE, MCLK, DIV_3);
break;
case 4:
ulReg = FIELD_SET(ulReg, CURRENT_GATE, MCLK, DIV_4);
break;
case 6:
ulReg = FIELD_SET(ulReg, CURRENT_GATE, MCLK, DIV_6);
break;
case 8:
ulReg = FIELD_SET(ulReg, CURRENT_GATE, MCLK, DIV_8);
break;
}
setCurrentGate(ulReg);
}
}
unsigned int ddk750_getVMSize(void)
{
unsigned int reg;
unsigned int data;
if (getChipType() == SM750LE)
return MB(64);
reg = PEEK32(MODE0_GATE);
reg = FIELD_SET(reg, MODE0_GATE, GPIO, ON);
POKE32(MODE0_GATE, reg);
reg = FIELD_GET(PEEK32(MISC_CTRL), MISC_CTRL, LOCALMEM_SIZE);
switch (reg) {
case MISC_CTRL_LOCALMEM_SIZE_8M:
data = MB(8); break;
case MISC_CTRL_LOCALMEM_SIZE_16M:
data = MB(16); break;
case MISC_CTRL_LOCALMEM_SIZE_32M:
data = MB(32); break;
case MISC_CTRL_LOCALMEM_SIZE_64M:
data = MB(64); break;
default:
data = 0;
break;
}
return data;
}
int ddk750_initHw(initchip_param_t *pInitParam)
{
unsigned int ulReg;
#if 0
if (getChipType() == SM718) {
ulReg = PEEK32(0x74);
POKE32(0x74, ulReg|0x80000000);
}
#endif
if (pInitParam->powerMode != 0 )
pInitParam->powerMode = 0;
setPowerMode(pInitParam->powerMode);
ulReg = PEEK32(CURRENT_GATE);
ulReg = FIELD_SET(ulReg, CURRENT_GATE, DISPLAY, ON);
ulReg = FIELD_SET(ulReg, CURRENT_GATE, LOCALMEM, ON);
setCurrentGate(ulReg);
if (getChipType() != SM750LE) {
ulReg = PEEK32(VGA_CONFIGURATION);
ulReg = FIELD_SET(ulReg, VGA_CONFIGURATION, PLL, PANEL);
ulReg = FIELD_SET(ulReg, VGA_CONFIGURATION, MODE, GRAPHIC);
POKE32(VGA_CONFIGURATION, ulReg);
} else {
#if defined(__i386__) || defined(__x86_64__)
outb_p(0x88, 0x3d4);
outb_p(0x06, 0x3d5);
#endif
}
setChipClock(MHz((unsigned int)pInitParam->chipClock));
setMemoryClock(MHz(pInitParam->memClock));
setMasterClock(MHz(pInitParam->masterClock));
if (pInitParam->resetMemory == 1) {
ulReg = PEEK32(MISC_CTRL);
ulReg = FIELD_SET(ulReg, MISC_CTRL, LOCALMEM_RESET, RESET);
POKE32(MISC_CTRL, ulReg);
ulReg = FIELD_SET(ulReg, MISC_CTRL, LOCALMEM_RESET, NORMAL);
POKE32(MISC_CTRL, ulReg);
}
if (pInitParam->setAllEngOff == 1) {
enable2DEngine(0);
ulReg = PEEK32(VIDEO_DISPLAY_CTRL);
ulReg = FIELD_SET(ulReg, VIDEO_DISPLAY_CTRL, PLANE, DISABLE);
POKE32(VIDEO_DISPLAY_CTRL, ulReg);
ulReg = PEEK32(VIDEO_ALPHA_DISPLAY_CTRL);
ulReg = FIELD_SET(ulReg, VIDEO_ALPHA_DISPLAY_CTRL, PLANE, DISABLE);
POKE32(VIDEO_ALPHA_DISPLAY_CTRL, ulReg);
ulReg = PEEK32(ALPHA_DISPLAY_CTRL);
ulReg = FIELD_SET(ulReg, ALPHA_DISPLAY_CTRL, PLANE, DISABLE);
POKE32(ALPHA_DISPLAY_CTRL, ulReg);
#if 0
ulReg = PEEK32(PANEL_HWC_ADDRESS);
ulReg = FIELD_SET(ulReg, PANEL_HWC_ADDRESS, ENABLE, DISABLE);
POKE32(PANEL_HWC_ADDRESS, ulReg);
ulReg = PEEK32(CRT_HWC_ADDRESS);
ulReg = FIELD_SET(ulReg, CRT_HWC_ADDRESS, ENABLE, DISABLE);
POKE32(CRT_HWC_ADDRESS, ulReg);
ulReg = PEEK32(ZV0_CAPTURE_CTRL);
ulReg = FIELD_SET(ulReg, ZV0_CAPTURE_CTRL, CAP, DISABLE);
POKE32(ZV0_CAPTURE_CTRL, ulReg);
ulReg = PEEK32(ZV1_CAPTURE_CTRL);
ulReg = FIELD_SET(ulReg, ZV1_CAPTURE_CTRL, CAP, DISABLE);
POKE32(ZV1_CAPTURE_CTRL, ulReg);
enableZVPort(0);
ulReg = PEEK32(DMA_ABORT_INTERRUPT);
ulReg = FIELD_SET(ulReg, DMA_ABORT_INTERRUPT, ABORT_1, ABORT);
POKE32(DMA_ABORT_INTERRUPT, ulReg);
enableI2C(0);
#endif
ulReg = PEEK32(DMA_ABORT_INTERRUPT);
ulReg = FIELD_SET(ulReg, DMA_ABORT_INTERRUPT, ABORT_1, ABORT);
POKE32(DMA_ABORT_INTERRUPT, ulReg);
enableDMA(0);
}
return 0;
}
unsigned int calcPllValue(unsigned int request_orig, pll_value_t *pll)
{
static pllcalparam xparm_PIXEL[] = {
{0, 0, 0, 1},
{1, 0, 1, 2},
{2, 0, 2, 4},
{3, 0, 3, 8},
{4, 1, 3, 16},
{5, 2, 3, 32},
{6, 3, 3, 64},
};
static pllcalparam xparm_MXCLK[] = {
{0, 0, 0, 1},
{1, 0, 1, 2},
{2, 0, 2, 4},
{3, 0, 3, 8},
};
int N, M, X, d;
int xcnt;
int miniDiff;
unsigned int RN, quo, rem, fl_quo;
unsigned int input, request;
unsigned int tmpClock, ret;
pllcalparam *xparm;
#if 1
if (getChipType() == SM750LE) {
return request_orig;
}
#endif
ret = 0;
miniDiff = ~0;
request = request_orig / 1000;
input = pll->inputFreq / 1000;
if (pll->clockType != MXCLK_PLL) {
xparm = &xparm_PIXEL[0];
xcnt = sizeof(xparm_PIXEL)/sizeof(xparm_PIXEL[0]);
} else {
xparm = &xparm_MXCLK[0];
xcnt = sizeof(xparm_MXCLK)/sizeof(xparm_MXCLK[0]);
}
for (N = 15; N > 1; N--) {
RN = N * request;
quo = RN / input;
rem = RN % input;
fl_quo = (rem * 10000 /input);
for (d = xcnt - 1; d >= 0; d--) {
X = xparm[d].value;
M = quo*X;
M += fl_quo * X / 10000;
M += (fl_quo*X % 10000)>5000?1:0;
if (M < 256 && M > 0) {
unsigned int diff;
tmpClock = pll->inputFreq *M / N / X;
diff = absDiff(tmpClock, request_orig);
if (diff < miniDiff) {
pll->M = M;
pll->N = N;
pll->OD = xparm[d].od;
pll->POD = xparm[d].pod;
miniDiff = diff;
ret = tmpClock;
}
}
}
}
return ret;
}
unsigned int calcPllValue2(
unsigned int ulRequestClk,
pll_value_t *pPLL
)
{
unsigned int M, N, OD, POD = 0, diff, pllClk, odPower, podPower;
unsigned int bestDiff = 0xffffffff;
unsigned int ret;
pPLL->M = 0;
pPLL->N = 0;
pPLL->OD = 0;
pPLL->POD = 0;
pPLL->inputFreq /= 1000;
ulRequestClk /= 1000;
#ifndef VALIDATION_CHIP
for (POD = 0; POD <= 3; POD++)
#endif
{
#ifndef VALIDATION_CHIP
if ((POD > 0) && (pPLL->clockType == MXCLK_PLL))
break;
#endif
podPower = twoToPowerOfx(POD);
for (OD = 0; OD <= 3; OD++) {
odPower = twoToPowerOfx(OD);
#ifdef VALIDATION_CHIP
if (odPower > 4)
podPower = 4;
else
podPower = odPower;
#endif
for (N = 2; N <= 15; N++) {
M = ulRequestClk * N * odPower * 1000 / pPLL->inputFreq;
M = roundedDiv(M, 1000);
if (M < 256) {
pllClk = pPLL->inputFreq * M / N / odPower / podPower;
diff = absDiff(pllClk, ulRequestClk);
if (diff < bestDiff) {
bestDiff = diff;
pPLL->M = M;
pPLL->N = N;
pPLL->OD = OD;
#ifdef VALIDATION_CHIP
if (OD > 2)
POD = 2;
else
POD = OD;
#endif
pPLL->POD = POD;
}
}
}
}
}
ulRequestClk *= 1000;
pPLL->inputFreq = DEFAULT_INPUT_CLOCK;
ret = calcPLL(pPLL);
return ret;
}
unsigned int formatPllReg(pll_value_t *pPLL)
{
unsigned int ulPllReg = 0;
ulPllReg =
FIELD_SET( 0, PANEL_PLL_CTRL, BYPASS, OFF)
| FIELD_SET( 0, PANEL_PLL_CTRL, POWER, ON)
| FIELD_SET( 0, PANEL_PLL_CTRL, INPUT, OSC)
#ifndef VALIDATION_CHIP
| FIELD_VALUE(0, PANEL_PLL_CTRL, POD, pPLL->POD)
#endif
| FIELD_VALUE(0, PANEL_PLL_CTRL, OD, pPLL->OD)
| FIELD_VALUE(0, PANEL_PLL_CTRL, N, pPLL->N)
| FIELD_VALUE(0, PANEL_PLL_CTRL, M, pPLL->M);
return ulPllReg;
}
