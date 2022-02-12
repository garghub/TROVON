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
static unsigned int get_mxclk_freq(void)
{
unsigned int pll_reg;
unsigned int M, N, OD, POD;
if (getChipType() == SM750LE)
return MHz(130);
pll_reg = PEEK32(MXCLK_PLL_CTRL);
M = FIELD_GET(pll_reg, PANEL_PLL_CTRL, M);
N = FIELD_GET(pll_reg, PANEL_PLL_CTRL, N);
OD = FIELD_GET(pll_reg, PANEL_PLL_CTRL, OD);
POD = FIELD_GET(pll_reg, PANEL_PLL_CTRL, POD);
return DEFAULT_INPUT_CLOCK * M / N / (1 << OD) / (1 << POD);
}
static void setChipClock(unsigned int frequency)
{
pll_value_t pll;
unsigned int ulActualMxClk;
if (getChipType() == SM750LE)
return;
if (frequency) {
pll.inputFreq = DEFAULT_INPUT_CLOCK;
pll.clockType = MXCLK_PLL;
ulActualMxClk = calcPllValue(frequency, &pll);
POKE32(MXCLK_PLL_CTRL, formatPllReg(&pll));
}
}
static void setMemoryClock(unsigned int frequency)
{
unsigned int ulReg, divisor;
if (getChipType() == SM750LE)
return;
if (frequency) {
if (frequency > MHz(336))
frequency = MHz(336);
divisor = roundedDiv(get_mxclk_freq(), frequency);
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
static void setMasterClock(unsigned int frequency)
{
unsigned int ulReg, divisor;
if (getChipType() == SM750LE)
return;
if (frequency) {
if (frequency > MHz(190))
frequency = MHz(190);
divisor = roundedDiv(get_mxclk_freq(), frequency);
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
return SZ_64M;
reg = PEEK32(MODE0_GATE);
reg = FIELD_SET(reg, MODE0_GATE, GPIO, ON);
POKE32(MODE0_GATE, reg);
reg = FIELD_GET(PEEK32(MISC_CTRL), MISC_CTRL, LOCALMEM_SIZE);
switch (reg) {
case MISC_CTRL_LOCALMEM_SIZE_8M:
data = SZ_8M; break;
case MISC_CTRL_LOCALMEM_SIZE_16M:
data = SZ_16M; break;
case MISC_CTRL_LOCALMEM_SIZE_32M:
data = SZ_32M; break;
case MISC_CTRL_LOCALMEM_SIZE_64M:
data = SZ_64M; break;
default:
data = 0;
break;
}
return data;
}
int ddk750_initHw(initchip_param_t *pInitParam)
{
unsigned int ulReg;
if (pInitParam->powerMode != 0)
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
ulReg = PEEK32(DMA_ABORT_INTERRUPT);
ulReg = FIELD_SET(ulReg, DMA_ABORT_INTERRUPT, ABORT_1, ABORT);
POKE32(DMA_ABORT_INTERRUPT, ulReg);
enableDMA(0);
}
return 0;
}
unsigned int calcPllValue(unsigned int request_orig, pll_value_t *pll)
{
int N, M, X, d;
int mini_diff;
unsigned int RN, quo, rem, fl_quo;
unsigned int input, request;
unsigned int tmpClock, ret;
const int max_OD = 3;
int max_d;
if (getChipType() == SM750LE) {
return request_orig;
}
ret = 0;
mini_diff = ~0;
request = request_orig / 1000;
input = pll->inputFreq / 1000;
if (pll->clockType == MXCLK_PLL)
max_d = 3;
for (N = 15; N > 1; N--) {
RN = N * request;
quo = RN / input;
rem = RN % input;
fl_quo = (rem * 10000 / input);
for (d = max_d; d >= 0; d--) {
X = (1 << d);
M = quo * X;
M += fl_quo * X / 10000;
M += (fl_quo * X % 10000) > 5000 ? 1 : 0;
if (M < 256 && M > 0) {
unsigned int diff;
tmpClock = pll->inputFreq * M / N / X;
diff = absDiff(tmpClock, request_orig);
if (diff < mini_diff) {
pll->M = M;
pll->N = N;
pll->POD = 0;
if (d > max_OD)
pll->POD = d - max_OD;
pll->OD = d - pll->POD;
mini_diff = diff;
ret = tmpClock;
}
}
}
}
return ret;
}
unsigned int formatPllReg(pll_value_t *pPLL)
{
unsigned int ulPllReg = 0;
ulPllReg =
FIELD_SET(0, PANEL_PLL_CTRL, BYPASS, OFF)
| FIELD_SET(0, PANEL_PLL_CTRL, POWER, ON)
| FIELD_SET(0, PANEL_PLL_CTRL, INPUT, OSC)
#ifndef VALIDATION_CHIP
| FIELD_VALUE(0, PANEL_PLL_CTRL, POD, pPLL->POD)
#endif
| FIELD_VALUE(0, PANEL_PLL_CTRL, OD, pPLL->OD)
| FIELD_VALUE(0, PANEL_PLL_CTRL, N, pPLL->N)
| FIELD_VALUE(0, PANEL_PLL_CTRL, M, pPLL->M);
return ulPllReg;
}
