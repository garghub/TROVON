static inline unsigned long clkc_readl(unsigned reg)
{
return readl(sirfsoc_clk_vbase + reg);
}
static inline void clkc_writel(u32 val, unsigned reg)
{
writel(val, sirfsoc_clk_vbase + reg);
}
static unsigned long pll_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long fin = parent_rate;
struct clk_pll *clk = to_pllclk(hw);
u32 regcfg2 = clk->regofs + SIRFSOC_CLKC_PLL1_CFG2 -
SIRFSOC_CLKC_PLL1_CFG0;
if (clkc_readl(regcfg2) & BIT(2)) {
return fin;
} else {
u32 cfg0 = clkc_readl(clk->regofs);
u32 nf = (cfg0 & (BIT(13) - 1)) + 1;
u32 nr = ((cfg0 >> 13) & (BIT(6) - 1)) + 1;
u32 od = ((cfg0 >> 19) & (BIT(4) - 1)) + 1;
WARN_ON(fin % MHZ);
return fin / MHZ * nf / nr / od * MHZ;
}
}
static long pll_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned long fin, nf, nr, od;
rate = rate - rate % MHZ;
nf = rate / MHZ;
if (nf > BIT(13))
nf = BIT(13);
if (nf < 1)
nf = 1;
fin = *parent_rate;
nr = fin / MHZ;
if (nr > BIT(6))
nr = BIT(6);
od = 1;
return fin * nf / (nr * od);
}
static int pll_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_pll *clk = to_pllclk(hw);
unsigned long fin, nf, nr, od, reg;
nf = rate / MHZ;
if (unlikely((rate % MHZ) || nf > BIT(13) || nf < 1))
return -EINVAL;
fin = parent_rate;
BUG_ON(fin < MHZ);
nr = fin / MHZ;
BUG_ON((fin % MHZ) || nr > BIT(6));
od = 1;
reg = (nf - 1) | ((nr - 1) << 13) | ((od - 1) << 19);
clkc_writel(reg, clk->regofs);
reg = clk->regofs + SIRFSOC_CLKC_PLL1_CFG1 - SIRFSOC_CLKC_PLL1_CFG0;
clkc_writel((nf >> 1) - 1, reg);
reg = clk->regofs + SIRFSOC_CLKC_PLL1_CFG2 - SIRFSOC_CLKC_PLL1_CFG0;
while (!(clkc_readl(reg) & BIT(6)))
cpu_relax();
return 0;
}
static int usb_pll_clk_enable(struct clk_hw *hw)
{
u32 reg = readl(sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
reg &= ~(SIRFSOC_USBPHY_PLL_POWERDOWN | SIRFSOC_USBPHY_PLL_BYPASS);
writel(reg, sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
while (!(readl(sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL) &
SIRFSOC_USBPHY_PLL_LOCK))
cpu_relax();
return 0;
}
static void usb_pll_clk_disable(struct clk_hw *clk)
{
u32 reg = readl(sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
reg |= (SIRFSOC_USBPHY_PLL_POWERDOWN | SIRFSOC_USBPHY_PLL_BYPASS);
writel(reg, sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
}
static unsigned long usb_pll_clk_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
u32 reg = readl(sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
return (reg & SIRFSOC_USBPHY_PLL_BYPASS) ? parent_rate : 48*MHZ;
}
static u8 dmn_clk_get_parent(struct clk_hw *hw)
{
struct clk_dmn *clk = to_dmnclk(hw);
u32 cfg = clkc_readl(clk->regofs);
if (strcmp(hw->init->name, "io") == 0)
return 4;
WARN_ON((cfg & (BIT(3) - 1)) > 4);
return cfg & (BIT(3) - 1);
}
static int dmn_clk_set_parent(struct clk_hw *hw, u8 parent)
{
struct clk_dmn *clk = to_dmnclk(hw);
u32 cfg = clkc_readl(clk->regofs);
if (strcmp(hw->init->name, "io") == 0)
return -EINVAL;
cfg &= ~(BIT(3) - 1);
clkc_writel(cfg | parent, clk->regofs);
while (clkc_readl(clk->regofs) & BIT(3))
cpu_relax();
return 0;
}
static unsigned long dmn_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long fin = parent_rate;
struct clk_dmn *clk = to_dmnclk(hw);
u32 cfg = clkc_readl(clk->regofs);
if (cfg & BIT(24)) {
return fin;
} else {
u32 wait = (cfg >> 16) & (BIT(4) - 1);
u32 hold = (cfg >> 20) & (BIT(4) - 1);
return fin / (wait + hold + 2);
}
}
static long dmn_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned long fin;
unsigned ratio, wait, hold;
unsigned bits = (strcmp(hw->init->name, "mem") == 0) ? 3 : 4;
fin = *parent_rate;
ratio = fin / rate;
if (ratio < 2)
ratio = 2;
if (ratio > BIT(bits + 1))
ratio = BIT(bits + 1);
wait = (ratio >> 1) - 1;
hold = ratio - wait - 2;
return fin / (wait + hold + 2);
}
static int dmn_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_dmn *clk = to_dmnclk(hw);
unsigned long fin;
unsigned ratio, wait, hold, reg;
unsigned bits = (strcmp(hw->init->name, "mem") == 0) ? 3 : 4;
fin = parent_rate;
ratio = fin / rate;
if (unlikely(ratio < 2 || ratio > BIT(bits + 1)))
return -EINVAL;
WARN_ON(fin % rate);
wait = (ratio >> 1) - 1;
hold = ratio - wait - 2;
reg = clkc_readl(clk->regofs);
reg &= ~(((BIT(bits) - 1) << 16) | ((BIT(bits) - 1) << 20));
reg |= (wait << 16) | (hold << 20) | BIT(25);
clkc_writel(reg, clk->regofs);
while (clkc_readl(clk->regofs) & BIT(25))
cpu_relax();
return 0;
}
static int std_clk_is_enabled(struct clk_hw *hw)
{
u32 reg;
int bit;
struct clk_std *clk = to_stdclk(hw);
bit = clk->enable_bit % 32;
reg = clk->enable_bit / 32;
reg = SIRFSOC_CLKC_CLK_EN0 + reg * sizeof(reg);
return !!(clkc_readl(reg) & BIT(bit));
}
static int std_clk_enable(struct clk_hw *hw)
{
u32 val, reg;
int bit;
struct clk_std *clk = to_stdclk(hw);
BUG_ON(clk->enable_bit < 0 || clk->enable_bit > 63);
bit = clk->enable_bit % 32;
reg = clk->enable_bit / 32;
reg = SIRFSOC_CLKC_CLK_EN0 + reg * sizeof(reg);
val = clkc_readl(reg) | BIT(bit);
clkc_writel(val, reg);
return 0;
}
static void std_clk_disable(struct clk_hw *hw)
{
u32 val, reg;
int bit;
struct clk_std *clk = to_stdclk(hw);
BUG_ON(clk->enable_bit < 0 || clk->enable_bit > 63);
bit = clk->enable_bit % 32;
reg = clk->enable_bit / 32;
reg = SIRFSOC_CLKC_CLK_EN0 + reg * sizeof(reg);
val = clkc_readl(reg) & ~BIT(bit);
clkc_writel(val, reg);
}
void __init sirfsoc_of_clk_init(void)
{
struct clk *clk;
struct device_node *np;
np = of_find_matching_node(NULL, clkc_ids);
if (!np)
panic("unable to find compatible clkc node in dtb\n");
sirfsoc_clk_vbase = of_iomap(np, 0);
if (!sirfsoc_clk_vbase)
panic("unable to map clkc registers\n");
of_node_put(np);
np = of_find_matching_node(NULL, rsc_ids);
if (!np)
panic("unable to find compatible rsc node in dtb\n");
sirfsoc_rsc_vbase = of_iomap(np, 0);
if (!sirfsoc_rsc_vbase)
panic("unable to map rsc registers\n");
of_node_put(np);
clk = clk_register_fixed_rate(NULL, "rtc", NULL,
CLK_IS_ROOT, 32768);
BUG_ON(IS_ERR(clk));
clk = clk_register_fixed_rate(NULL, "osc", NULL,
CLK_IS_ROOT, 26000000);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_pll1.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_pll2.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_pll3.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_mem.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_sys.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_security.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b8030000.security");
clk = clk_register(NULL, &clk_dsp.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_gps.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "a8010000.gps");
clk = clk_register(NULL, &clk_mf.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_io.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "io");
clk = clk_register(NULL, &clk_cpu.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "cpu");
clk = clk_register(NULL, &clk_uart0.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0050000.uart");
clk = clk_register(NULL, &clk_uart1.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0060000.uart");
clk = clk_register(NULL, &clk_uart2.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0070000.uart");
clk = clk_register(NULL, &clk_tsc.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0110000.tsc");
clk = clk_register(NULL, &clk_i2c0.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b00e0000.i2c");
clk = clk_register(NULL, &clk_i2c1.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b00f0000.i2c");
clk = clk_register(NULL, &clk_spi0.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b00d0000.spi");
clk = clk_register(NULL, &clk_spi1.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0170000.spi");
clk = clk_register(NULL, &clk_pwmc.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0130000.pwm");
clk = clk_register(NULL, &clk_efuse.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0140000.efusesys");
clk = clk_register(NULL, &clk_pulse.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0150000.pulsec");
clk = clk_register(NULL, &clk_dmac0.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b00b0000.dma-controller");
clk = clk_register(NULL, &clk_dmac1.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0160000.dma-controller");
clk = clk_register(NULL, &clk_nand.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0030000.nand");
clk = clk_register(NULL, &clk_audio.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0040000.audio");
clk = clk_register(NULL, &clk_usp0.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0080000.usp");
clk = clk_register(NULL, &clk_usp1.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b0090000.usp");
clk = clk_register(NULL, &clk_usp2.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b00a0000.usp");
clk = clk_register(NULL, &clk_vip.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b00c0000.vip");
clk = clk_register(NULL, &clk_gfx.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "98000000.graphics");
clk = clk_register(NULL, &clk_mm.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "a0000000.multimedia");
clk = clk_register(NULL, &clk_lcd.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "90010000.display");
clk = clk_register(NULL, &clk_vpp.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "90020000.vpp");
clk = clk_register(NULL, &clk_mmc01.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_mmc23.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_mmc45.hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &usb_pll_clk_hw);
BUG_ON(IS_ERR(clk));
clk = clk_register(NULL, &clk_usb0.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b00e0000.usb");
clk = clk_register(NULL, &clk_usb1.hw);
BUG_ON(IS_ERR(clk));
clk_register_clkdev(clk, NULL, "b00f0000.usb");
}
