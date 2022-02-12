logical_chip_type_t sm750_get_chip_type(void)
{
return chip;
}
void sm750_set_chip_type(unsigned short devId, u8 revId)
{
if (devId == 0x718)
chip = SM718;
else if (devId == 0x750) {
chip = SM750;
if (revId == SM750LE_REVISION_ID) {
chip = SM750LE;
pr_info("found sm750le\n");
}
} else {
chip = SM_UNKNOWN;
}
}
static unsigned int get_mxclk_freq(void)
{
unsigned int pll_reg;
unsigned int M, N, OD, POD;
if (sm750_get_chip_type() == SM750LE)
return MHz(130);
pll_reg = peek32(MXCLK_PLL_CTRL);
M = (pll_reg & PLL_CTRL_M_MASK) >> PLL_CTRL_M_SHIFT;
N = (pll_reg & PLL_CTRL_N_MASK) >> PLL_CTRL_M_SHIFT;
OD = (pll_reg & PLL_CTRL_OD_MASK) >> PLL_CTRL_OD_SHIFT;
POD = (pll_reg & PLL_CTRL_POD_MASK) >> PLL_CTRL_POD_SHIFT;
return DEFAULT_INPUT_CLOCK * M / N / (1 << OD) / (1 << POD);
}
static void set_chip_clock(unsigned int frequency)
{
struct pll_value pll;
unsigned int ulActualMxClk;
if (sm750_get_chip_type() == SM750LE)
return;
if (frequency) {
pll.inputFreq = DEFAULT_INPUT_CLOCK;
pll.clockType = MXCLK_PLL;
ulActualMxClk = sm750_calc_pll_value(frequency, &pll);
poke32(MXCLK_PLL_CTRL, sm750_format_pll_reg(&pll));
}
}
static void set_memory_clock(unsigned int frequency)
{
unsigned int reg, divisor;
if (sm750_get_chip_type() == SM750LE)
return;
if (frequency) {
if (frequency > MHz(336))
frequency = MHz(336);
divisor = DIV_ROUND_CLOSEST(get_mxclk_freq(), frequency);
reg = peek32(CURRENT_GATE) & ~CURRENT_GATE_M2XCLK_MASK;
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
sm750_set_current_gate(reg);
}
}
static void set_master_clock(unsigned int frequency)
{
unsigned int reg, divisor;
if (sm750_get_chip_type() == SM750LE)
return;
if (frequency) {
if (frequency > MHz(190))
frequency = MHz(190);
divisor = DIV_ROUND_CLOSEST(get_mxclk_freq(), frequency);
reg = peek32(CURRENT_GATE) & ~CURRENT_GATE_MCLK_MASK;
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
sm750_set_current_gate(reg);
}
}
unsigned int ddk750_get_vm_size(void)
{
unsigned int reg;
unsigned int data;
if (sm750_get_chip_type() == SM750LE)
return SZ_64M;
reg = peek32(MODE0_GATE);
reg |= MODE0_GATE_GPIO;
poke32(MODE0_GATE, reg);
reg = peek32(MISC_CTRL) & MISC_CTRL_LOCALMEM_SIZE_MASK;
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
int ddk750_init_hw(struct initchip_param *pInitParam)
{
unsigned int reg;
if (pInitParam->powerMode != 0)
pInitParam->powerMode = 0;
sm750_set_power_mode(pInitParam->powerMode);
reg = peek32(CURRENT_GATE);
reg |= (CURRENT_GATE_DISPLAY | CURRENT_GATE_LOCALMEM);
sm750_set_current_gate(reg);
if (sm750_get_chip_type() != SM750LE) {
reg = peek32(VGA_CONFIGURATION);
reg |= (VGA_CONFIGURATION_PLL | VGA_CONFIGURATION_MODE);
poke32(VGA_CONFIGURATION, reg);
} else {
#if defined(__i386__) || defined(__x86_64__)
outb_p(0x88, 0x3d4);
outb_p(0x06, 0x3d5);
#endif
}
set_chip_clock(MHz((unsigned int)pInitParam->chipClock));
set_memory_clock(MHz(pInitParam->memClock));
set_master_clock(MHz(pInitParam->masterClock));
if (pInitParam->resetMemory == 1) {
reg = peek32(MISC_CTRL);
reg &= ~MISC_CTRL_LOCALMEM_RESET;
poke32(MISC_CTRL, reg);
reg |= MISC_CTRL_LOCALMEM_RESET;
poke32(MISC_CTRL, reg);
}
if (pInitParam->setAllEngOff == 1) {
sm750_enable_2d_engine(0);
reg = peek32(VIDEO_DISPLAY_CTRL);
reg &= ~DISPLAY_CTRL_PLANE;
poke32(VIDEO_DISPLAY_CTRL, reg);
reg = peek32(VIDEO_ALPHA_DISPLAY_CTRL);
reg &= ~DISPLAY_CTRL_PLANE;
poke32(VIDEO_ALPHA_DISPLAY_CTRL, reg);
reg = peek32(ALPHA_DISPLAY_CTRL);
reg &= ~DISPLAY_CTRL_PLANE;
poke32(ALPHA_DISPLAY_CTRL, reg);
reg = peek32(DMA_ABORT_INTERRUPT);
reg |= DMA_ABORT_INTERRUPT_ABORT_1;
poke32(DMA_ABORT_INTERRUPT, reg);
sm750_enable_dma(0);
}
return 0;
}
unsigned int sm750_calc_pll_value(unsigned int request_orig, struct pll_value *pll)
{
int N, M, X, d;
int mini_diff;
unsigned int RN, quo, rem, fl_quo;
unsigned int input, request;
unsigned int tmpClock, ret;
const int max_OD = 3;
int max_d = 6;
if (sm750_get_chip_type() == SM750LE) {
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
X = BIT(d);
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
unsigned int sm750_format_pll_reg(struct pll_value *pPLL)
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
