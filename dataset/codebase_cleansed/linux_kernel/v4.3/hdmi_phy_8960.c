static int hdmi_pll_enable(struct clk_hw *hw)
{
struct hdmi_phy_8960 *phy_8960 = clk_to_phy(hw);
struct hdmi *hdmi = phy_8960->hdmi;
int timeout_count, pll_lock_retry = 10;
unsigned int val;
DBG("");
hdmi_write(hdmi, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG2, 0x8d);
hdmi_write(hdmi, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG0, 0x10);
hdmi_write(hdmi, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG1, 0x1a);
udelay(10);
hdmi_write(hdmi, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG2, 0x0d);
val = hdmi_read(hdmi, REG_HDMI_8960_PHY_REG12);
val |= HDMI_8960_PHY_REG12_SW_RESET;
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG12, val);
val &= ~HDMI_8960_PHY_REG12_SW_RESET;
udelay(10);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG12, val);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG2, 0x3f);
val = hdmi_read(hdmi, REG_HDMI_8960_PHY_REG12);
val |= HDMI_8960_PHY_REG12_PWRDN_B;
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG12, val);
mb();
udelay(10);
val = hdmi_read(hdmi, REG_HDMI_8960_PHY_PLL_PWRDN_B);
val |= HDMI_8960_PHY_PLL_PWRDN_B_PLL_PWRDN_B;
val &= ~HDMI_8960_PHY_PLL_PWRDN_B_PD_PLL;
hdmi_write(hdmi, REG_HDMI_8960_PHY_PLL_PWRDN_B, val);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG2, 0x80);
timeout_count = 1000;
while (--pll_lock_retry > 0) {
val = hdmi_read(hdmi, REG_HDMI_8960_PHY_PLL_STATUS0);
if (val & HDMI_8960_PHY_PLL_STATUS0_PLL_LOCK)
break;
udelay(1);
if (--timeout_count > 0)
continue;
hdmi_write(hdmi, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG2, 0x8d);
udelay(10);
hdmi_write(hdmi, REG_HDMI_8960_PHY_PLL_LOCKDET_CFG2, 0x0d);
udelay(350);
timeout_count = 1000;
}
return 0;
}
static void hdmi_pll_disable(struct clk_hw *hw)
{
struct hdmi_phy_8960 *phy_8960 = clk_to_phy(hw);
struct hdmi *hdmi = phy_8960->hdmi;
unsigned int val;
DBG("");
val = hdmi_read(hdmi, REG_HDMI_8960_PHY_REG12);
val &= ~HDMI_8960_PHY_REG12_PWRDN_B;
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG12, val);
val = hdmi_read(hdmi, REG_HDMI_8960_PHY_PLL_PWRDN_B);
val |= HDMI_8960_PHY_REG12_SW_RESET;
val &= ~HDMI_8960_PHY_REG12_PWRDN_B;
hdmi_write(hdmi, REG_HDMI_8960_PHY_PLL_PWRDN_B, val);
mb();
}
static const struct pll_rate *find_rate(unsigned long rate)
{
int i;
for (i = 1; i < ARRAY_SIZE(freqtbl); i++)
if (rate > freqtbl[i].rate)
return &freqtbl[i-1];
return &freqtbl[i-1];
}
static unsigned long hdmi_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct hdmi_phy_8960 *phy_8960 = clk_to_phy(hw);
return phy_8960->pixclk;
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
struct hdmi_phy_8960 *phy_8960 = clk_to_phy(hw);
struct hdmi *hdmi = phy_8960->hdmi;
const struct pll_rate *pll_rate = find_rate(rate);
int i;
DBG("rate=%lu", rate);
for (i = 0; pll_rate->conf[i].reg; i++)
hdmi_write(hdmi, pll_rate->conf[i].reg, pll_rate->conf[i].val);
phy_8960->pixclk = rate;
return 0;
}
static void hdmi_phy_8960_destroy(struct hdmi_phy *phy)
{
struct hdmi_phy_8960 *phy_8960 = to_hdmi_phy_8960(phy);
kfree(phy_8960);
}
static void hdmi_phy_8960_powerup(struct hdmi_phy *phy,
unsigned long int pixclock)
{
struct hdmi_phy_8960 *phy_8960 = to_hdmi_phy_8960(phy);
struct hdmi *hdmi = phy_8960->hdmi;
DBG("pixclock: %lu", pixclock);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG2, 0x00);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG0, 0x1b);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG1, 0xf2);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG4, 0x00);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG5, 0x00);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG6, 0x00);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG7, 0x00);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG8, 0x00);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG9, 0x00);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG10, 0x00);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG11, 0x00);
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG3, 0x20);
}
static void hdmi_phy_8960_powerdown(struct hdmi_phy *phy)
{
struct hdmi_phy_8960 *phy_8960 = to_hdmi_phy_8960(phy);
struct hdmi *hdmi = phy_8960->hdmi;
DBG("");
hdmi_write(hdmi, REG_HDMI_8960_PHY_REG2, 0x7f);
}
struct hdmi_phy *hdmi_phy_8960_init(struct hdmi *hdmi)
{
struct hdmi_phy_8960 *phy_8960;
struct hdmi_phy *phy = NULL;
int ret;
#ifdef CONFIG_COMMON_CLK
int i;
for (i = 0; i < (ARRAY_SIZE(freqtbl) - 1); i++)
if (WARN_ON(freqtbl[i].rate < freqtbl[i+1].rate))
return ERR_PTR(-EINVAL);
#endif
phy_8960 = kzalloc(sizeof(*phy_8960), GFP_KERNEL);
if (!phy_8960) {
ret = -ENOMEM;
goto fail;
}
phy = &phy_8960->base;
phy->funcs = &hdmi_phy_8960_funcs;
phy_8960->hdmi = hdmi;
#ifdef CONFIG_COMMON_CLK
phy_8960->pll_hw.init = &pll_init;
phy_8960->pll = devm_clk_register(&hdmi->pdev->dev, &phy_8960->pll_hw);
if (IS_ERR(phy_8960->pll)) {
ret = PTR_ERR(phy_8960->pll);
phy_8960->pll = NULL;
goto fail;
}
#endif
return phy;
fail:
if (phy)
hdmi_phy_8960_destroy(phy);
return ERR_PTR(ret);
}
