static inline void pll_write(struct hdmi_pll_8960 *pll, u32 reg, u32 data)
{
msm_writel(data, pll->mmio + reg);
}
static inline u32 pll_read(struct hdmi_pll_8960 *pll, u32 reg)
{
return msm_readl(pll->mmio + reg);
}
static inline struct hdmi_phy *pll_get_phy(struct hdmi_pll_8960 *pll)
{
return platform_get_drvdata(pll->pdev);
}
static int hdmi_pll_enable(struct clk_hw *hw)
{
struct hdmi_pll_8960 *pll = hw_clk_to_pll(hw);
struct hdmi_phy *phy = pll_get_phy(pll);
int timeout_count, pll_lock_retry = 10;
unsigned int val;
DBG("");
pll_write(pll, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG2, 0x8d);
pll_write(pll, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG0, 0x10);
pll_write(pll, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG1, 0x1a);
udelay(10);
pll_write(pll, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG2, 0x0d);
val = hdmi_phy_read(phy, REG_HDMI_8960_PHY_REG12);
val |= HDMI_8960_PHY_REG12_SW_RESET;
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG12, val);
val &= ~HDMI_8960_PHY_REG12_SW_RESET;
udelay(10);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG12, val);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG2, 0x3f);
val = hdmi_phy_read(phy, REG_HDMI_8960_PHY_REG12);
val |= HDMI_8960_PHY_REG12_PWRDN_B;
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG12, val);
mb();
udelay(10);
val = pll_read(pll, REG_HDMI_8960_PHY_PLL_PWRDN_B);
val |= HDMI_8960_PHY_PLL_PWRDN_B_PLL_PWRDN_B;
val &= ~HDMI_8960_PHY_PLL_PWRDN_B_PD_PLL;
pll_write(pll, REG_HDMI_8960_PHY_PLL_PWRDN_B, val);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG2, 0x80);
timeout_count = 1000;
while (--pll_lock_retry > 0) {
val = pll_read(pll, REG_HDMI_8960_PHY_PLL_STATUS0);
if (val & HDMI_8960_PHY_PLL_STATUS0_PLL_LOCK)
break;
udelay(1);
if (--timeout_count > 0)
continue;
pll_write(pll, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG2, 0x8d);
udelay(10);
pll_write(pll, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG2, 0x0d);
udelay(350);
timeout_count = 1000;
}
return 0;
}
static void hdmi_pll_disable(struct clk_hw *hw)
{
struct hdmi_pll_8960 *pll = hw_clk_to_pll(hw);
struct hdmi_phy *phy = pll_get_phy(pll);
unsigned int val;
DBG("");
val = hdmi_phy_read(phy, REG_HDMI_8960_PHY_REG12);
val &= ~HDMI_8960_PHY_REG12_PWRDN_B;
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG12, val);
val = pll_read(pll, REG_HDMI_8960_PHY_PLL_PWRDN_B);
val |= HDMI_8960_PHY_REG12_SW_RESET;
val &= ~HDMI_8960_PHY_REG12_PWRDN_B;
pll_write(pll, REG_HDMI_8960_PHY_PLL_PWRDN_B, val);
mb();
}
static const struct pll_rate *find_rate(unsigned long rate)
{
int i;
for (i = 1; i < ARRAY_SIZE(freqtbl); i++)
if (rate > freqtbl[i].rate)
return &freqtbl[i - 1];
return &freqtbl[i - 1];
}
static unsigned long hdmi_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct hdmi_pll_8960 *pll = hw_clk_to_pll(hw);
return pll->pixclk;
}
static long hdmi_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
const struct pll_rate *pll_rate = find_rate(rate);
return pll_rate->rate;
}
static int hdmi_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct hdmi_pll_8960 *pll = hw_clk_to_pll(hw);
const struct pll_rate *pll_rate = find_rate(rate);
int i;
DBG("rate=%lu", rate);
for (i = 0; i < pll_rate->num_reg; i++)
pll_write(pll, pll_rate->conf[i].reg, pll_rate->conf[i].val);
pll->pixclk = rate;
return 0;
}
int msm_hdmi_pll_8960_init(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct hdmi_pll_8960 *pll;
struct clk *clk;
int i;
for (i = 0; i < (ARRAY_SIZE(freqtbl) - 1); i++)
if (WARN_ON(freqtbl[i].rate < freqtbl[i + 1].rate))
return -EINVAL;
pll = devm_kzalloc(dev, sizeof(*pll), GFP_KERNEL);
if (!pll)
return -ENOMEM;
pll->mmio = msm_ioremap(pdev, "hdmi_pll", "HDMI_PLL");
if (IS_ERR(pll->mmio)) {
dev_err(dev, "failed to map pll base\n");
return -ENOMEM;
}
pll->pdev = pdev;
pll->clk_hw.init = &pll_init;
clk = devm_clk_register(dev, &pll->clk_hw);
if (IS_ERR(clk)) {
dev_err(dev, "failed to register pll clock\n");
return -EINVAL;
}
return 0;
}
