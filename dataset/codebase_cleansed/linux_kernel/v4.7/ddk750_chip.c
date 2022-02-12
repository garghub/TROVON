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
M = (pll_reg & PLL_CTRL_M_MASK) >> PLL_CTRL_M_SHIFT;
N = (pll_reg & PLL_CTRL_N_MASK) >> PLL_CTRL_M_SHIFT;
OD = (pll_reg & PLL_CTRL_OD_MASK) >> PLL_CTRL_OD_SHIFT;
POD = (pll_reg & PLL_CTRL_POD_MASK) >> PLL_CTRL_POD_SHIFT;
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
unsigned int reg, divisor;
if (getChipType() == SM750LE)
return;
if (frequency) {
if (frequency > MHz(336))
frequency = MHz(336);
divisor = roundedDiv(get_mxclk_freq(), frequency);
reg = PEEK32(CURRENT_GATE) & ~CURRENT_GATE_M2XCLK_MASK;
switch (divisor) {
default:
case 1:
reg |= CURRENT_GATE_M2XCLK_DIV_1;
break;
case 2:
reg |= CURRENT_GATE_M2XCLK_DIV_2;
break;
case 3:
reg |= CURRENT_GATE_M2XCLK_DIV_3;
break;
case 4:
reg |= CURRENT_GATE_M2XCLK_DIV_4;
break;
}
setCurrentGate(reg);
}
}
static void setMasterClock(unsigned int frequency)
{
unsigned int reg, divisor;
if (getChipType() == SM750LE)
return;
if (frequency) {
if (frequency > MHz(190))
frequency = MHz(190);
divisor = roundedDiv(get_mxclk_freq(), frequency);
reg = PEEK32(CURRENT_GATE) & ~CURRENT_GATE_MCLK_MASK;
switch (divisor) {
default:
case 3:
reg |= CURRENT_GATE_MCLK_DIV_3;
break;
case 4:
reg |= CURRENT_GATE_MCLK_DIV_4;
break;
case 6:
reg |= CURRENT_GATE_MCLK_DIV_6;
break;
case 8:
reg |= CURRENT_GATE_MCLK_DIV_8;
break;
}
setCurrentGate(reg);
}
}
unsigned int ddk750_getVMSize(void)
{
unsigned int reg;
unsigned int data;
if (getChipType() == SM750LE)
return SZ_64M;
reg = PEEK32(MODE0_GATE);
reg |= MODE0_GATE_GPIO;
POKE32(MODE0_GATE, reg);
reg = PEEK32(MISC_CTRL) & MISC_CTRL_LOCALMEM_SIZE_MASK;
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
unsigned int reg;
if (pInitParam->powerMode != 0)
pInitParam->powerMode = 0;
setPowerMode(pInitParam->powerMode);
reg = PEEK32(CURRENT_GATE);
reg |= (CURRENT_GATE_DISPLAY | CURRENT_GATE_LOCALMEM);
setCurrentGate(reg);
if (getChipType() != SM750LE) {
reg = PEEK32(VGA_CONFIGURATION);
reg |= (VGA_CONFIGURATION_PLL | VGA_CONFIGURATION_MODE);
POKE32(VGA_CONFIGURATION, reg);
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
reg = PEEK32(MISC_CTRL);
reg &= ~MISC_CTRL_LOCALMEM_RESET;
POKE32(MISC_CTRL, reg);
reg |= MISC_CTRL_LOCALMEM_RESET;
POKE32(MISC_CTRL, reg);
}
if (pInitParam->setAllEngOff == 1) {
enable2DEngine(0);
reg = PEEK32(VIDEO_DISPLAY_CTRL);
reg &= ~DISPLAY_CTRL_PLANE;
POKE32(VIDEO_DISPLAY_CTRL, reg);
reg = PEEK32(VIDEO_ALPHA_DISPLAY_CTRL);
reg &= ~DISPLAY_CTRL_PLANE;
POKE32(VIDEO_ALPHA_DISPLAY_CTRL, reg);
reg = PEEK32(ALPHA_DISPLAY_CTRL);
reg &= ~DISPLAY_CTRL_PLANE;
POKE32(ALPHA_DISPLAY_CTRL, reg);
reg = PEEK32(DMA_ABORT_INTERRUPT);
reg |= DMA_ABORT_INTERRUPT_ABORT_1;
POKE32(DMA_ABORT_INTERRUPT, reg);
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
int max_d = 6;
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
diff = abs(tmpClock - request_orig);
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
#ifndef VALIDATION_CHIP
unsigned int POD = pPLL->POD;
#endif
unsigned int OD = pPLL->OD;
unsigned int M = pPLL->M;
unsigned int N = pPLL->N;
unsigned int reg = 0;
reg = PLL_CTRL_POWER |
#ifndef VALIDATION_CHIP
((POD << PLL_CTRL_POD_SHIFT) & PLL_CTRL_POD_MASK) |
#endif
((OD << PLL_CTRL_OD_SHIFT) & PLL_CTRL_OD_MASK) |
((N << PLL_CTRL_N_SHIFT) & PLL_CTRL_N_MASK) |
((M << PLL_CTRL_M_SHIFT) & PLL_CTRL_M_MASK);
return reg;
}
