static inline struct tegra210_xusb_padctl *
to_tegra210_xusb_padctl(struct tegra_xusb_padctl *padctl)
{
return container_of(padctl, struct tegra210_xusb_padctl, base);
}
static int tegra210_pex_uphy_enable(struct tegra_xusb_padctl *padctl)
{
struct tegra_xusb_pcie_pad *pcie = to_pcie_pad(padctl->pcie);
unsigned long timeout;
u32 value;
int err;
if (pcie->enable > 0) {
pcie->enable++;
return 0;
}
err = clk_prepare_enable(pcie->pll);
if (err < 0)
return err;
err = reset_control_deassert(pcie->rst);
if (err < 0)
goto disable;
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
value &= ~(XUSB_PADCTL_UPHY_PLL_CTL2_CAL_CTRL_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL2_CAL_CTRL_SHIFT);
value |= XUSB_PADCTL_UPHY_PLL_CTL2_CAL_CTRL_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL2_CAL_CTRL_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL5);
value &= ~(XUSB_PADCTL_UPHY_PLL_CTL5_DCO_CTRL_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL5_DCO_CTRL_SHIFT);
value |= XUSB_PADCTL_UPHY_PLL_CTL5_DCO_CTRL_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL5_DCO_CTRL_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL5);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value |= XUSB_PADCTL_UPHY_PLL_CTL1_PWR_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
value |= XUSB_PADCTL_UPHY_PLL_CTL2_CAL_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
value |= XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL4);
value &= ~((XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_SHIFT) |
(XUSB_PADCTL_UPHY_PLL_CTL4_REFCLK_SEL_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL4_REFCLK_SEL_SHIFT));
value |= (XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_USB_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_SHIFT) |
XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL4);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value &= ~((XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_MDIV_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_MDIV_SHIFT) |
(XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_SHIFT));
value |= XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_USB_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL1_IDDQ;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value &= ~(XUSB_PADCTL_UPHY_PLL_CTL1_SLEEP_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL1_SLEEP_SHIFT);
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
usleep_range(10, 20);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL4);
value |= XUSB_PADCTL_UPHY_PLL_CTL4_REFCLKBUF_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL4);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
value |= XUSB_PADCTL_UPHY_PLL_CTL2_CAL_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
if (value & XUSB_PADCTL_UPHY_PLL_CTL2_CAL_DONE)
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL2_CAL_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
if (!(value & XUSB_PADCTL_UPHY_PLL_CTL2_CAL_DONE))
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value |= XUSB_PADCTL_UPHY_PLL_CTL1_ENABLE;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
if (value & XUSB_PADCTL_UPHY_PLL_CTL1_LOCKDET_STATUS)
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
value |= XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_EN |
XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_CLK_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
if (value & XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_DONE)
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
if (!(value & XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_DONE))
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_CLK_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
tegra210_xusb_pll_hw_control_enable();
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL1_PWR_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL2_CAL_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL2);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_P0_CTL8);
usleep_range(10, 20);
tegra210_xusb_pll_hw_sequence_start();
pcie->enable++;
return 0;
reset:
reset_control_assert(pcie->rst);
disable:
clk_disable_unprepare(pcie->pll);
return err;
}
static void tegra210_pex_uphy_disable(struct tegra_xusb_padctl *padctl)
{
struct tegra_xusb_pcie_pad *pcie = to_pcie_pad(padctl->pcie);
mutex_lock(&padctl->lock);
if (WARN_ON(pcie->enable == 0))
goto unlock;
if (--pcie->enable > 0)
goto unlock;
reset_control_assert(pcie->rst);
clk_disable_unprepare(pcie->pll);
unlock:
mutex_unlock(&padctl->lock);
}
static int tegra210_sata_uphy_enable(struct tegra_xusb_padctl *padctl, bool usb)
{
struct tegra_xusb_sata_pad *sata = to_sata_pad(padctl->sata);
unsigned long timeout;
u32 value;
int err;
if (sata->enable > 0) {
sata->enable++;
return 0;
}
err = clk_prepare_enable(sata->pll);
if (err < 0)
return err;
err = reset_control_deassert(sata->rst);
if (err < 0)
goto disable;
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
value &= ~(XUSB_PADCTL_UPHY_PLL_CTL2_CAL_CTRL_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL2_CAL_CTRL_SHIFT);
value |= XUSB_PADCTL_UPHY_PLL_CTL2_CAL_CTRL_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL2_CAL_CTRL_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL5);
value &= ~(XUSB_PADCTL_UPHY_PLL_CTL5_DCO_CTRL_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL5_DCO_CTRL_SHIFT);
value |= XUSB_PADCTL_UPHY_PLL_CTL5_DCO_CTRL_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL5_DCO_CTRL_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL5);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value |= XUSB_PADCTL_UPHY_PLL_CTL1_PWR_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
value |= XUSB_PADCTL_UPHY_PLL_CTL2_CAL_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
value |= XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL4);
value &= ~((XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_SHIFT) |
(XUSB_PADCTL_UPHY_PLL_CTL4_REFCLK_SEL_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL4_REFCLK_SEL_SHIFT));
value |= XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_EN;
if (usb)
value |= (XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_USB_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_SHIFT);
else
value |= (XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_SATA_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL4_TXCLKREF_SEL_SHIFT);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value &= ~((XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_MDIV_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_MDIV_SHIFT) |
(XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_SHIFT));
if (usb)
value |= XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_USB_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_SHIFT;
else
value |= XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_SATA_VAL <<
XUSB_PADCTL_UPHY_PLL_CTL1_FREQ_NDIV_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL1_IDDQ;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value &= ~(XUSB_PADCTL_UPHY_PLL_CTL1_SLEEP_MASK <<
XUSB_PADCTL_UPHY_PLL_CTL1_SLEEP_SHIFT);
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
usleep_range(10, 20);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL4);
value |= XUSB_PADCTL_UPHY_PLL_CTL4_REFCLKBUF_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL4);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
value |= XUSB_PADCTL_UPHY_PLL_CTL2_CAL_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
if (value & XUSB_PADCTL_UPHY_PLL_CTL2_CAL_DONE)
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL2_CAL_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
if (!(value & XUSB_PADCTL_UPHY_PLL_CTL2_CAL_DONE))
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value |= XUSB_PADCTL_UPHY_PLL_CTL1_ENABLE;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
if (value & XUSB_PADCTL_UPHY_PLL_CTL1_LOCKDET_STATUS)
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
value |= XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_EN |
XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_CLK_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
if (value & XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_DONE)
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
if (!(value & XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_DONE))
break;
usleep_range(10, 20);
}
if (time_after_eq(jiffies, timeout)) {
err = -ETIMEDOUT;
goto reset;
}
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_CLK_EN;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
tegra210_sata_pll_hw_control_enable();
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL1_PWR_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL2_CAL_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL2);
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
value &= ~XUSB_PADCTL_UPHY_PLL_CTL8_RCAL_OVRD;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_PLL_S0_CTL8);
usleep_range(10, 20);
tegra210_sata_pll_hw_sequence_start();
sata->enable++;
return 0;
reset:
reset_control_assert(sata->rst);
disable:
clk_disable_unprepare(sata->pll);
return err;
}
static void tegra210_sata_uphy_disable(struct tegra_xusb_padctl *padctl)
{
struct tegra_xusb_sata_pad *sata = to_sata_pad(padctl->sata);
mutex_lock(&padctl->lock);
if (WARN_ON(sata->enable == 0))
goto unlock;
if (--sata->enable > 0)
goto unlock;
reset_control_assert(sata->rst);
clk_disable_unprepare(sata->pll);
unlock:
mutex_unlock(&padctl->lock);
}
static int tegra210_xusb_padctl_enable(struct tegra_xusb_padctl *padctl)
{
u32 value;
mutex_lock(&padctl->lock);
if (padctl->enable++ > 0)
goto out;
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value &= ~XUSB_PADCTL_ELPG_PROGRAM1_AUX_MUX_LP0_CLAMP_EN;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value &= ~XUSB_PADCTL_ELPG_PROGRAM1_AUX_MUX_LP0_CLAMP_EN_EARLY;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value &= ~XUSB_PADCTL_ELPG_PROGRAM1_AUX_MUX_LP0_VCORE_DOWN;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
out:
mutex_unlock(&padctl->lock);
return 0;
}
static int tegra210_xusb_padctl_disable(struct tegra_xusb_padctl *padctl)
{
u32 value;
mutex_lock(&padctl->lock);
if (WARN_ON(padctl->enable == 0))
goto out;
if (--padctl->enable > 0)
goto out;
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value |= XUSB_PADCTL_ELPG_PROGRAM1_AUX_MUX_LP0_VCORE_DOWN;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value |= XUSB_PADCTL_ELPG_PROGRAM1_AUX_MUX_LP0_CLAMP_EN_EARLY;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value |= XUSB_PADCTL_ELPG_PROGRAM1_AUX_MUX_LP0_CLAMP_EN;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
out:
mutex_unlock(&padctl->lock);
return 0;
}
static int tegra210_hsic_set_idle(struct tegra_xusb_padctl *padctl,
unsigned int index, bool idle)
{
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_HSIC_PADX_CTL0(index));
value &= ~(XUSB_PADCTL_HSIC_PAD_CTL0_RPU_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPU_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPD_STROBE);
if (idle)
value |= XUSB_PADCTL_HSIC_PAD_CTL0_RPD_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPD_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPU_STROBE;
else
value &= ~(XUSB_PADCTL_HSIC_PAD_CTL0_RPD_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPD_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPU_STROBE);
padctl_writel(padctl, value, XUSB_PADCTL_HSIC_PADX_CTL0(index));
return 0;
}
static int tegra210_usb3_set_lfps_detect(struct tegra_xusb_padctl *padctl,
unsigned int index, bool enable)
{
struct tegra_xusb_port *port;
struct tegra_xusb_lane *lane;
u32 value, offset;
port = tegra_xusb_find_port(padctl, "usb3", index);
if (!port)
return -ENODEV;
lane = port->lane;
if (lane->pad == padctl->pcie)
offset = XUSB_PADCTL_UPHY_MISC_PAD_PX_CTL1(lane->index);
else
offset = XUSB_PADCTL_UPHY_MISC_PAD_S0_CTL1;
value = padctl_readl(padctl, offset);
value &= ~((XUSB_PADCTL_UPHY_MISC_PAD_CTL1_AUX_RX_IDLE_MODE_MASK <<
XUSB_PADCTL_UPHY_MISC_PAD_CTL1_AUX_RX_IDLE_MODE_SHIFT) |
XUSB_PADCTL_UPHY_MISC_PAD_CTL1_AUX_RX_TERM_EN |
XUSB_PADCTL_UPHY_MISC_PAD_CTL1_AUX_RX_MODE_OVRD);
if (!enable) {
value |= (XUSB_PADCTL_UPHY_MISC_PAD_CTL1_AUX_RX_IDLE_MODE_VAL <<
XUSB_PADCTL_UPHY_MISC_PAD_CTL1_AUX_RX_IDLE_MODE_SHIFT) |
XUSB_PADCTL_UPHY_MISC_PAD_CTL1_AUX_RX_TERM_EN |
XUSB_PADCTL_UPHY_MISC_PAD_CTL1_AUX_RX_MODE_OVRD;
}
padctl_writel(padctl, value, offset);
return 0;
}
static struct tegra_xusb_lane *
tegra210_usb2_lane_probe(struct tegra_xusb_pad *pad, struct device_node *np,
unsigned int index)
{
struct tegra_xusb_usb2_lane *usb2;
int err;
usb2 = kzalloc(sizeof(*usb2), GFP_KERNEL);
if (!usb2)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&usb2->base.list);
usb2->base.soc = &pad->soc->lanes[index];
usb2->base.index = index;
usb2->base.pad = pad;
usb2->base.np = np;
err = tegra_xusb_lane_parse_dt(&usb2->base, np);
if (err < 0) {
kfree(usb2);
return ERR_PTR(err);
}
return &usb2->base;
}
static void tegra210_usb2_lane_remove(struct tegra_xusb_lane *lane)
{
struct tegra_xusb_usb2_lane *usb2 = to_usb2_lane(lane);
kfree(usb2);
}
static int tegra210_usb2_phy_init(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_USB2_PAD_MUX);
value &= ~(XUSB_PADCTL_USB2_PAD_MUX_USB2_BIAS_PAD_MASK <<
XUSB_PADCTL_USB2_PAD_MUX_USB2_BIAS_PAD_SHIFT);
value |= XUSB_PADCTL_USB2_PAD_MUX_USB2_BIAS_PAD_XUSB <<
XUSB_PADCTL_USB2_PAD_MUX_USB2_BIAS_PAD_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_USB2_PAD_MUX);
return tegra210_xusb_padctl_enable(padctl);
}
static int tegra210_usb2_phy_exit(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
return tegra210_xusb_padctl_disable(lane->pad->padctl);
}
static int tegra210_usb2_phy_power_on(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_usb2_lane *usb2 = to_usb2_lane(lane);
struct tegra_xusb_usb2_pad *pad = to_usb2_pad(lane->pad);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
struct tegra210_xusb_padctl *priv;
struct tegra_xusb_usb2_port *port;
unsigned int index = lane->index;
u32 value;
int err;
port = tegra_xusb_find_usb2_port(padctl, index);
if (!port) {
dev_err(&phy->dev, "no port found for USB2 lane %u\n", index);
return -ENODEV;
}
priv = to_tegra210_xusb_padctl(padctl);
value = padctl_readl(padctl, XUSB_PADCTL_USB2_BIAS_PAD_CTL0);
value &= ~((XUSB_PADCTL_USB2_BIAS_PAD_CTL0_HS_SQUELCH_LEVEL_MASK <<
XUSB_PADCTL_USB2_BIAS_PAD_CTL0_HS_SQUELCH_LEVEL_SHIFT) |
(XUSB_PADCTL_USB2_BIAS_PAD_CTL0_HS_DISCON_LEVEL_MASK <<
XUSB_PADCTL_USB2_BIAS_PAD_CTL0_HS_DISCON_LEVEL_SHIFT));
value |= (XUSB_PADCTL_USB2_BIAS_PAD_CTL0_HS_DISCON_LEVEL_VAL <<
XUSB_PADCTL_USB2_BIAS_PAD_CTL0_HS_DISCON_LEVEL_SHIFT);
if (tegra_sku_info.revision < TEGRA_REVISION_A02)
value |=
(XUSB_PADCTL_USB2_BIAS_PAD_CTL0_HS_SQUELCH_LEVEL_VAL <<
XUSB_PADCTL_USB2_BIAS_PAD_CTL0_HS_SQUELCH_LEVEL_SHIFT);
padctl_writel(padctl, value, XUSB_PADCTL_USB2_BIAS_PAD_CTL0);
value = padctl_readl(padctl, XUSB_PADCTL_USB2_PORT_CAP);
value &= ~XUSB_PADCTL_USB2_PORT_CAP_PORTX_CAP_MASK(index);
value |= XUSB_PADCTL_USB2_PORT_CAP_PORTX_CAP_HOST(index);
padctl_writel(padctl, value, XUSB_PADCTL_USB2_PORT_CAP);
value = padctl_readl(padctl, XUSB_PADCTL_USB2_OTG_PADX_CTL0(index));
value &= ~((XUSB_PADCTL_USB2_OTG_PAD_CTL0_HS_CURR_LEVEL_MASK <<
XUSB_PADCTL_USB2_OTG_PAD_CTL0_HS_CURR_LEVEL_SHIFT) |
XUSB_PADCTL_USB2_OTG_PAD_CTL0_PD |
XUSB_PADCTL_USB2_OTG_PAD_CTL0_PD2 |
XUSB_PADCTL_USB2_OTG_PAD_CTL0_PD_ZI);
value |= (priv->fuse.hs_curr_level[index] +
usb2->hs_curr_level_offset) <<
XUSB_PADCTL_USB2_OTG_PAD_CTL0_HS_CURR_LEVEL_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_USB2_OTG_PADX_CTL0(index));
value = padctl_readl(padctl, XUSB_PADCTL_USB2_OTG_PADX_CTL1(index));
value &= ~((XUSB_PADCTL_USB2_OTG_PAD_CTL1_TERM_RANGE_ADJ_MASK <<
XUSB_PADCTL_USB2_OTG_PAD_CTL1_TERM_RANGE_ADJ_SHIFT) |
(XUSB_PADCTL_USB2_OTG_PAD_CTL1_RPD_CTRL_MASK <<
XUSB_PADCTL_USB2_OTG_PAD_CTL1_RPD_CTRL_SHIFT) |
XUSB_PADCTL_USB2_OTG_PAD_CTL1_PD_DR |
XUSB_PADCTL_USB2_OTG_PAD_CTL1_PD_CHRP_OVRD |
XUSB_PADCTL_USB2_OTG_PAD_CTL1_PD_DISC_OVRD);
value |= (priv->fuse.hs_term_range_adj <<
XUSB_PADCTL_USB2_OTG_PAD_CTL1_TERM_RANGE_ADJ_SHIFT) |
(priv->fuse.rpd_ctrl <<
XUSB_PADCTL_USB2_OTG_PAD_CTL1_RPD_CTRL_SHIFT);
padctl_writel(padctl, value, XUSB_PADCTL_USB2_OTG_PADX_CTL1(index));
value = padctl_readl(padctl,
XUSB_PADCTL_USB2_BATTERY_CHRG_OTGPADX_CTL1(index));
value &= ~(XUSB_PADCTL_USB2_BATTERY_CHRG_OTGPAD_CTL1_VREG_LEV_MASK <<
XUSB_PADCTL_USB2_BATTERY_CHRG_OTGPAD_CTL1_VREG_LEV_SHIFT);
value |= XUSB_PADCTL_USB2_BATTERY_CHRG_OTGPAD_CTL1_VREG_FIX18;
padctl_writel(padctl, value,
XUSB_PADCTL_USB2_BATTERY_CHRG_OTGPADX_CTL1(index));
err = regulator_enable(port->supply);
if (err)
return err;
mutex_lock(&padctl->lock);
if (pad->enable > 0) {
pad->enable++;
mutex_unlock(&padctl->lock);
return 0;
}
err = clk_prepare_enable(pad->clk);
if (err)
goto disable_regulator;
value = padctl_readl(padctl, XUSB_PADCTL_USB2_BIAS_PAD_CTL1);
value &= ~((XUSB_PADCTL_USB2_BIAS_PAD_CTL1_TRK_START_TIMER_MASK <<
XUSB_PADCTL_USB2_BIAS_PAD_CTL1_TRK_START_TIMER_SHIFT) |
(XUSB_PADCTL_USB2_BIAS_PAD_CTL1_TRK_DONE_RESET_TIMER_MASK <<
XUSB_PADCTL_USB2_BIAS_PAD_CTL1_TRK_DONE_RESET_TIMER_SHIFT));
value |= (XUSB_PADCTL_USB2_BIAS_PAD_CTL1_TRK_START_TIMER_VAL <<
XUSB_PADCTL_USB2_BIAS_PAD_CTL1_TRK_START_TIMER_SHIFT) |
(XUSB_PADCTL_USB2_BIAS_PAD_CTL1_TRK_DONE_RESET_TIMER_VAL <<
XUSB_PADCTL_USB2_BIAS_PAD_CTL1_TRK_DONE_RESET_TIMER_SHIFT);
padctl_writel(padctl, value, XUSB_PADCTL_USB2_BIAS_PAD_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_USB2_BIAS_PAD_CTL0);
value &= ~XUSB_PADCTL_USB2_BIAS_PAD_CTL0_PD;
padctl_writel(padctl, value, XUSB_PADCTL_USB2_BIAS_PAD_CTL0);
udelay(1);
value = padctl_readl(padctl, XUSB_PADCTL_USB2_BIAS_PAD_CTL1);
value &= ~XUSB_PADCTL_USB2_BIAS_PAD_CTL1_PD_TRK;
padctl_writel(padctl, value, XUSB_PADCTL_USB2_BIAS_PAD_CTL1);
udelay(50);
clk_disable_unprepare(pad->clk);
pad->enable++;
mutex_unlock(&padctl->lock);
return 0;
disable_regulator:
regulator_disable(port->supply);
mutex_unlock(&padctl->lock);
return err;
}
static int tegra210_usb2_phy_power_off(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_usb2_pad *pad = to_usb2_pad(lane->pad);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
struct tegra_xusb_usb2_port *port;
u32 value;
port = tegra_xusb_find_usb2_port(padctl, lane->index);
if (!port) {
dev_err(&phy->dev, "no port found for USB2 lane %u\n",
lane->index);
return -ENODEV;
}
mutex_lock(&padctl->lock);
if (WARN_ON(pad->enable == 0))
goto out;
if (--pad->enable > 0)
goto out;
value = padctl_readl(padctl, XUSB_PADCTL_USB2_BIAS_PAD_CTL0);
value |= XUSB_PADCTL_USB2_BIAS_PAD_CTL0_PD;
padctl_writel(padctl, value, XUSB_PADCTL_USB2_BIAS_PAD_CTL0);
out:
regulator_disable(port->supply);
mutex_unlock(&padctl->lock);
return 0;
}
static struct tegra_xusb_pad *
tegra210_usb2_pad_probe(struct tegra_xusb_padctl *padctl,
const struct tegra_xusb_pad_soc *soc,
struct device_node *np)
{
struct tegra_xusb_usb2_pad *usb2;
struct tegra_xusb_pad *pad;
int err;
usb2 = kzalloc(sizeof(*usb2), GFP_KERNEL);
if (!usb2)
return ERR_PTR(-ENOMEM);
pad = &usb2->base;
pad->ops = &tegra210_usb2_lane_ops;
pad->soc = soc;
err = tegra_xusb_pad_init(pad, padctl, np);
if (err < 0) {
kfree(usb2);
goto out;
}
usb2->clk = devm_clk_get(&pad->dev, "trk");
if (IS_ERR(usb2->clk)) {
err = PTR_ERR(usb2->clk);
dev_err(&pad->dev, "failed to get trk clock: %d\n", err);
goto unregister;
}
err = tegra_xusb_pad_register(pad, &tegra210_usb2_phy_ops);
if (err < 0)
goto unregister;
dev_set_drvdata(&pad->dev, pad);
return pad;
unregister:
device_unregister(&pad->dev);
out:
return ERR_PTR(err);
}
static void tegra210_usb2_pad_remove(struct tegra_xusb_pad *pad)
{
struct tegra_xusb_usb2_pad *usb2 = to_usb2_pad(pad);
kfree(usb2);
}
static struct tegra_xusb_lane *
tegra210_hsic_lane_probe(struct tegra_xusb_pad *pad, struct device_node *np,
unsigned int index)
{
struct tegra_xusb_hsic_lane *hsic;
int err;
hsic = kzalloc(sizeof(*hsic), GFP_KERNEL);
if (!hsic)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&hsic->base.list);
hsic->base.soc = &pad->soc->lanes[index];
hsic->base.index = index;
hsic->base.pad = pad;
hsic->base.np = np;
err = tegra_xusb_lane_parse_dt(&hsic->base, np);
if (err < 0) {
kfree(hsic);
return ERR_PTR(err);
}
return &hsic->base;
}
static void tegra210_hsic_lane_remove(struct tegra_xusb_lane *lane)
{
struct tegra_xusb_hsic_lane *hsic = to_hsic_lane(lane);
kfree(hsic);
}
static int tegra210_hsic_phy_init(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_USB2_PAD_MUX);
value &= ~(XUSB_PADCTL_USB2_PAD_MUX_HSIC_PAD_TRK_MASK <<
XUSB_PADCTL_USB2_PAD_MUX_HSIC_PAD_TRK_SHIFT);
value |= XUSB_PADCTL_USB2_PAD_MUX_HSIC_PAD_TRK_XUSB <<
XUSB_PADCTL_USB2_PAD_MUX_HSIC_PAD_TRK_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_USB2_PAD_MUX);
return tegra210_xusb_padctl_enable(padctl);
}
static int tegra210_hsic_phy_exit(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
return tegra210_xusb_padctl_disable(lane->pad->padctl);
}
static int tegra210_hsic_phy_power_on(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_hsic_lane *hsic = to_hsic_lane(lane);
struct tegra_xusb_hsic_pad *pad = to_hsic_pad(lane->pad);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
struct tegra210_xusb_padctl *priv;
unsigned int index = lane->index;
u32 value;
int err;
priv = to_tegra210_xusb_padctl(padctl);
err = regulator_enable(pad->supply);
if (err)
return err;
padctl_writel(padctl, hsic->strobe_trim,
XUSB_PADCTL_HSIC_STRB_TRIM_CONTROL);
value = padctl_readl(padctl, XUSB_PADCTL_HSIC_PADX_CTL1(index));
value &= ~(XUSB_PADCTL_HSIC_PAD_CTL1_TX_RTUNEP_MASK <<
XUSB_PADCTL_HSIC_PAD_CTL1_TX_RTUNEP_SHIFT);
value |= (hsic->tx_rtune_p <<
XUSB_PADCTL_HSIC_PAD_CTL1_TX_RTUNEP_SHIFT);
padctl_writel(padctl, value, XUSB_PADCTL_HSIC_PADX_CTL1(index));
value = padctl_readl(padctl, XUSB_PADCTL_HSIC_PADX_CTL2(index));
value &= ~((XUSB_PADCTL_HSIC_PAD_CTL2_RX_STROBE_TRIM_MASK <<
XUSB_PADCTL_HSIC_PAD_CTL2_RX_STROBE_TRIM_SHIFT) |
(XUSB_PADCTL_HSIC_PAD_CTL2_RX_DATA_TRIM_MASK <<
XUSB_PADCTL_HSIC_PAD_CTL2_RX_DATA_TRIM_SHIFT));
value |= (hsic->rx_strobe_trim <<
XUSB_PADCTL_HSIC_PAD_CTL2_RX_STROBE_TRIM_SHIFT) |
(hsic->rx_data_trim <<
XUSB_PADCTL_HSIC_PAD_CTL2_RX_DATA_TRIM_SHIFT);
padctl_writel(padctl, value, XUSB_PADCTL_HSIC_PADX_CTL2(index));
value = padctl_readl(padctl, XUSB_PADCTL_HSIC_PADX_CTL0(index));
value &= ~(XUSB_PADCTL_HSIC_PAD_CTL0_RPU_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPU_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPU_STROBE |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_STROBE |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_STROBE |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_STROBE);
value |= XUSB_PADCTL_HSIC_PAD_CTL0_RPD_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPD_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_RPD_STROBE;
padctl_writel(padctl, value, XUSB_PADCTL_HSIC_PADX_CTL0(index));
err = clk_prepare_enable(pad->clk);
if (err)
goto disable;
value = padctl_readl(padctl, XUSB_PADCTL_HSIC_PAD_TRK_CTL);
value &= ~((XUSB_PADCTL_HSIC_PAD_TRK_CTL_TRK_START_TIMER_MASK <<
XUSB_PADCTL_HSIC_PAD_TRK_CTL_TRK_START_TIMER_SHIFT) |
(XUSB_PADCTL_HSIC_PAD_TRK_CTL_TRK_DONE_RESET_TIMER_MASK <<
XUSB_PADCTL_HSIC_PAD_TRK_CTL_TRK_DONE_RESET_TIMER_SHIFT));
value |= (XUSB_PADCTL_HSIC_PAD_TRK_CTL_TRK_START_TIMER_VAL <<
XUSB_PADCTL_HSIC_PAD_TRK_CTL_TRK_START_TIMER_SHIFT) |
(XUSB_PADCTL_HSIC_PAD_TRK_CTL_TRK_DONE_RESET_TIMER_VAL <<
XUSB_PADCTL_HSIC_PAD_TRK_CTL_TRK_DONE_RESET_TIMER_SHIFT);
padctl_writel(padctl, value, XUSB_PADCTL_HSIC_PAD_TRK_CTL);
udelay(1);
value = padctl_readl(padctl, XUSB_PADCTL_HSIC_PAD_TRK_CTL);
value &= ~XUSB_PADCTL_HSIC_PAD_TRK_CTL_PD_TRK;
padctl_writel(padctl, value, XUSB_PADCTL_HSIC_PAD_TRK_CTL);
udelay(50);
clk_disable_unprepare(pad->clk);
return 0;
disable:
regulator_disable(pad->supply);
return err;
}
static int tegra210_hsic_phy_power_off(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_hsic_pad *pad = to_hsic_pad(lane->pad);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
unsigned int index = lane->index;
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_HSIC_PADX_CTL0(index));
value |= XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_STROBE |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_STROBE |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_DATA0 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_DATA1 |
XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_STROBE;
padctl_writel(padctl, value, XUSB_PADCTL_HSIC_PADX_CTL1(index));
regulator_disable(pad->supply);
return 0;
}
static struct tegra_xusb_pad *
tegra210_hsic_pad_probe(struct tegra_xusb_padctl *padctl,
const struct tegra_xusb_pad_soc *soc,
struct device_node *np)
{
struct tegra_xusb_hsic_pad *hsic;
struct tegra_xusb_pad *pad;
int err;
hsic = kzalloc(sizeof(*hsic), GFP_KERNEL);
if (!hsic)
return ERR_PTR(-ENOMEM);
pad = &hsic->base;
pad->ops = &tegra210_hsic_lane_ops;
pad->soc = soc;
err = tegra_xusb_pad_init(pad, padctl, np);
if (err < 0) {
kfree(hsic);
goto out;
}
hsic->clk = devm_clk_get(&pad->dev, "trk");
if (IS_ERR(hsic->clk)) {
err = PTR_ERR(hsic->clk);
dev_err(&pad->dev, "failed to get trk clock: %d\n", err);
goto unregister;
}
err = tegra_xusb_pad_register(pad, &tegra210_hsic_phy_ops);
if (err < 0)
goto unregister;
dev_set_drvdata(&pad->dev, pad);
return pad;
unregister:
device_unregister(&pad->dev);
out:
return ERR_PTR(err);
}
static void tegra210_hsic_pad_remove(struct tegra_xusb_pad *pad)
{
struct tegra_xusb_hsic_pad *hsic = to_hsic_pad(pad);
kfree(hsic);
}
static struct tegra_xusb_lane *
tegra210_pcie_lane_probe(struct tegra_xusb_pad *pad, struct device_node *np,
unsigned int index)
{
struct tegra_xusb_pcie_lane *pcie;
int err;
pcie = kzalloc(sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&pcie->base.list);
pcie->base.soc = &pad->soc->lanes[index];
pcie->base.index = index;
pcie->base.pad = pad;
pcie->base.np = np;
err = tegra_xusb_lane_parse_dt(&pcie->base, np);
if (err < 0) {
kfree(pcie);
return ERR_PTR(err);
}
return &pcie->base;
}
static void tegra210_pcie_lane_remove(struct tegra_xusb_lane *lane)
{
struct tegra_xusb_pcie_lane *pcie = to_pcie_lane(lane);
kfree(pcie);
}
static int tegra210_pcie_phy_init(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
return tegra210_xusb_padctl_enable(lane->pad->padctl);
}
static int tegra210_pcie_phy_exit(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
return tegra210_xusb_padctl_disable(lane->pad->padctl);
}
static int tegra210_pcie_phy_power_on(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
u32 value;
int err;
mutex_lock(&padctl->lock);
err = tegra210_pex_uphy_enable(padctl);
if (err < 0)
goto unlock;
value = padctl_readl(padctl, XUSB_PADCTL_USB3_PAD_MUX);
value |= XUSB_PADCTL_USB3_PAD_MUX_PCIE_IDDQ_DISABLE(lane->index);
padctl_writel(padctl, value, XUSB_PADCTL_USB3_PAD_MUX);
unlock:
mutex_unlock(&padctl->lock);
return err;
}
static int tegra210_pcie_phy_power_off(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_USB3_PAD_MUX);
value &= ~XUSB_PADCTL_USB3_PAD_MUX_PCIE_IDDQ_DISABLE(lane->index);
padctl_writel(padctl, value, XUSB_PADCTL_USB3_PAD_MUX);
tegra210_pex_uphy_disable(padctl);
return 0;
}
static struct tegra_xusb_pad *
tegra210_pcie_pad_probe(struct tegra_xusb_padctl *padctl,
const struct tegra_xusb_pad_soc *soc,
struct device_node *np)
{
struct tegra_xusb_pcie_pad *pcie;
struct tegra_xusb_pad *pad;
int err;
pcie = kzalloc(sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return ERR_PTR(-ENOMEM);
pad = &pcie->base;
pad->ops = &tegra210_pcie_lane_ops;
pad->soc = soc;
err = tegra_xusb_pad_init(pad, padctl, np);
if (err < 0) {
kfree(pcie);
goto out;
}
pcie->pll = devm_clk_get(&pad->dev, "pll");
if (IS_ERR(pcie->pll)) {
err = PTR_ERR(pcie->pll);
dev_err(&pad->dev, "failed to get PLL: %d\n", err);
goto unregister;
}
pcie->rst = devm_reset_control_get(&pad->dev, "phy");
if (IS_ERR(pcie->rst)) {
err = PTR_ERR(pcie->rst);
dev_err(&pad->dev, "failed to get PCIe pad reset: %d\n", err);
goto unregister;
}
err = tegra_xusb_pad_register(pad, &tegra210_pcie_phy_ops);
if (err < 0)
goto unregister;
dev_set_drvdata(&pad->dev, pad);
return pad;
unregister:
device_unregister(&pad->dev);
out:
return ERR_PTR(err);
}
static void tegra210_pcie_pad_remove(struct tegra_xusb_pad *pad)
{
struct tegra_xusb_pcie_pad *pcie = to_pcie_pad(pad);
kfree(pcie);
}
static struct tegra_xusb_lane *
tegra210_sata_lane_probe(struct tegra_xusb_pad *pad, struct device_node *np,
unsigned int index)
{
struct tegra_xusb_sata_lane *sata;
int err;
sata = kzalloc(sizeof(*sata), GFP_KERNEL);
if (!sata)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&sata->base.list);
sata->base.soc = &pad->soc->lanes[index];
sata->base.index = index;
sata->base.pad = pad;
sata->base.np = np;
err = tegra_xusb_lane_parse_dt(&sata->base, np);
if (err < 0) {
kfree(sata);
return ERR_PTR(err);
}
return &sata->base;
}
static void tegra210_sata_lane_remove(struct tegra_xusb_lane *lane)
{
struct tegra_xusb_sata_lane *sata = to_sata_lane(lane);
kfree(sata);
}
static int tegra210_sata_phy_init(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
return tegra210_xusb_padctl_enable(lane->pad->padctl);
}
static int tegra210_sata_phy_exit(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
return tegra210_xusb_padctl_disable(lane->pad->padctl);
}
static int tegra210_sata_phy_power_on(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
u32 value;
int err;
mutex_lock(&padctl->lock);
err = tegra210_sata_uphy_enable(padctl, false);
if (err < 0)
goto unlock;
value = padctl_readl(padctl, XUSB_PADCTL_USB3_PAD_MUX);
value |= XUSB_PADCTL_USB3_PAD_MUX_SATA_IDDQ_DISABLE(lane->index);
padctl_writel(padctl, value, XUSB_PADCTL_USB3_PAD_MUX);
unlock:
mutex_unlock(&padctl->lock);
return err;
}
static int tegra210_sata_phy_power_off(struct phy *phy)
{
struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
struct tegra_xusb_padctl *padctl = lane->pad->padctl;
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_USB3_PAD_MUX);
value &= ~XUSB_PADCTL_USB3_PAD_MUX_SATA_IDDQ_DISABLE(lane->index);
padctl_writel(padctl, value, XUSB_PADCTL_USB3_PAD_MUX);
tegra210_sata_uphy_disable(lane->pad->padctl);
return 0;
}
static struct tegra_xusb_pad *
tegra210_sata_pad_probe(struct tegra_xusb_padctl *padctl,
const struct tegra_xusb_pad_soc *soc,
struct device_node *np)
{
struct tegra_xusb_sata_pad *sata;
struct tegra_xusb_pad *pad;
int err;
sata = kzalloc(sizeof(*sata), GFP_KERNEL);
if (!sata)
return ERR_PTR(-ENOMEM);
pad = &sata->base;
pad->ops = &tegra210_sata_lane_ops;
pad->soc = soc;
err = tegra_xusb_pad_init(pad, padctl, np);
if (err < 0) {
kfree(sata);
goto out;
}
sata->rst = devm_reset_control_get(&pad->dev, "phy");
if (IS_ERR(sata->rst)) {
err = PTR_ERR(sata->rst);
dev_err(&pad->dev, "failed to get SATA pad reset: %d\n", err);
goto unregister;
}
err = tegra_xusb_pad_register(pad, &tegra210_sata_phy_ops);
if (err < 0)
goto unregister;
dev_set_drvdata(&pad->dev, pad);
return pad;
unregister:
device_unregister(&pad->dev);
out:
return ERR_PTR(err);
}
static void tegra210_sata_pad_remove(struct tegra_xusb_pad *pad)
{
struct tegra_xusb_sata_pad *sata = to_sata_pad(pad);
kfree(sata);
}
static int tegra210_usb2_port_enable(struct tegra_xusb_port *port)
{
return 0;
}
static void tegra210_usb2_port_disable(struct tegra_xusb_port *port)
{
}
static struct tegra_xusb_lane *
tegra210_usb2_port_map(struct tegra_xusb_port *port)
{
return tegra_xusb_find_lane(port->padctl, "usb2", port->index);
}
static int tegra210_hsic_port_enable(struct tegra_xusb_port *port)
{
return 0;
}
static void tegra210_hsic_port_disable(struct tegra_xusb_port *port)
{
}
static struct tegra_xusb_lane *
tegra210_hsic_port_map(struct tegra_xusb_port *port)
{
return tegra_xusb_find_lane(port->padctl, "hsic", port->index);
}
static int tegra210_usb3_port_enable(struct tegra_xusb_port *port)
{
struct tegra_xusb_usb3_port *usb3 = to_usb3_port(port);
struct tegra_xusb_padctl *padctl = port->padctl;
struct tegra_xusb_lane *lane = usb3->base.lane;
unsigned int index = port->index;
u32 value;
int err;
value = padctl_readl(padctl, XUSB_PADCTL_SS_PORT_MAP);
if (!usb3->internal)
value &= ~XUSB_PADCTL_SS_PORT_MAP_PORTX_INTERNAL(index);
else
value |= XUSB_PADCTL_SS_PORT_MAP_PORTX_INTERNAL(index);
value &= ~XUSB_PADCTL_SS_PORT_MAP_PORTX_MAP_MASK(index);
value |= XUSB_PADCTL_SS_PORT_MAP_PORTX_MAP(index, usb3->port);
padctl_writel(padctl, value, XUSB_PADCTL_SS_PORT_MAP);
err = regulator_enable(usb3->supply);
if (err < 0)
return err;
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_USB3_PADX_ECTL1(index));
value &= ~(XUSB_PADCTL_UPHY_USB3_PAD_ECTL1_TX_TERM_CTRL_MASK <<
XUSB_PADCTL_UPHY_USB3_PAD_ECTL1_TX_TERM_CTRL_SHIFT);
value |= XUSB_PADCTL_UPHY_USB3_PAD_ECTL1_TX_TERM_CTRL_VAL <<
XUSB_PADCTL_UPHY_USB3_PAD_ECTL1_TX_TERM_CTRL_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_USB3_PADX_ECTL1(index));
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_USB3_PADX_ECTL2(index));
value &= ~(XUSB_PADCTL_UPHY_USB3_PAD_ECTL2_RX_CTLE_MASK <<
XUSB_PADCTL_UPHY_USB3_PAD_ECTL2_RX_CTLE_SHIFT);
value |= XUSB_PADCTL_UPHY_USB3_PAD_ECTL2_RX_CTLE_VAL <<
XUSB_PADCTL_UPHY_USB3_PAD_ECTL2_RX_CTLE_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_USB3_PADX_ECTL2(index));
padctl_writel(padctl, XUSB_PADCTL_UPHY_USB3_PAD_ECTL3_RX_DFE_VAL,
XUSB_PADCTL_UPHY_USB3_PADX_ECTL3(index));
value = padctl_readl(padctl, XUSB_PADCTL_UPHY_USB3_PADX_ECTL4(index));
value &= ~(XUSB_PADCTL_UPHY_USB3_PAD_ECTL4_RX_CDR_CTRL_MASK <<
XUSB_PADCTL_UPHY_USB3_PAD_ECTL4_RX_CDR_CTRL_SHIFT);
value |= XUSB_PADCTL_UPHY_USB3_PAD_ECTL4_RX_CDR_CTRL_VAL <<
XUSB_PADCTL_UPHY_USB3_PAD_ECTL4_RX_CDR_CTRL_SHIFT;
padctl_writel(padctl, value, XUSB_PADCTL_UPHY_USB3_PADX_ECTL4(index));
padctl_writel(padctl, XUSB_PADCTL_UPHY_USB3_PAD_ECTL6_RX_EQ_CTRL_H_VAL,
XUSB_PADCTL_UPHY_USB3_PADX_ECTL6(index));
if (lane->pad == padctl->sata)
err = tegra210_sata_uphy_enable(padctl, true);
else
err = tegra210_pex_uphy_enable(padctl);
if (err) {
dev_err(&port->dev, "%s: failed to enable UPHY: %d\n",
__func__, err);
return err;
}
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value &= ~XUSB_PADCTL_ELPG_PROGRAM1_SSPX_ELPG_VCORE_DOWN(index);
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value &= ~XUSB_PADCTL_ELPG_PROGRAM1_SSPX_ELPG_CLAMP_EN_EARLY(index);
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value &= ~XUSB_PADCTL_ELPG_PROGRAM1_SSPX_ELPG_CLAMP_EN(index);
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
return 0;
}
static void tegra210_usb3_port_disable(struct tegra_xusb_port *port)
{
struct tegra_xusb_usb3_port *usb3 = to_usb3_port(port);
struct tegra_xusb_padctl *padctl = port->padctl;
struct tegra_xusb_lane *lane = port->lane;
unsigned int index = port->index;
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value |= XUSB_PADCTL_ELPG_PROGRAM1_SSPX_ELPG_CLAMP_EN_EARLY(index);
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value |= XUSB_PADCTL_ELPG_PROGRAM1_SSPX_ELPG_CLAMP_EN(index);
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
usleep_range(250, 350);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM1);
value |= XUSB_PADCTL_ELPG_PROGRAM1_SSPX_ELPG_VCORE_DOWN(index);
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM1);
if (lane->pad == padctl->sata)
tegra210_sata_uphy_disable(padctl);
else
tegra210_pex_uphy_disable(padctl);
regulator_disable(usb3->supply);
value = padctl_readl(padctl, XUSB_PADCTL_SS_PORT_MAP);
value &= ~XUSB_PADCTL_SS_PORT_MAP_PORTX_MAP_MASK(index);
value |= XUSB_PADCTL_SS_PORT_MAP_PORTX_MAP(index, 0x7);
padctl_writel(padctl, value, XUSB_PADCTL_SS_PORT_MAP);
}
static struct tegra_xusb_lane *
tegra210_usb3_port_map(struct tegra_xusb_port *port)
{
return tegra_xusb_port_find_lane(port, tegra210_usb3_map, "usb3-ss");
}
static int
tegra210_xusb_read_fuse_calibration(struct tegra210_xusb_fuse_calibration *fuse)
{
unsigned int i;
u32 value;
int err;
err = tegra_fuse_readl(TEGRA_FUSE_SKU_CALIB_0, &value);
if (err < 0)
return err;
for (i = 0; i < ARRAY_SIZE(fuse->hs_curr_level); i++) {
fuse->hs_curr_level[i] =
(value >> FUSE_SKU_CALIB_HS_CURR_LEVEL_PADX_SHIFT(i)) &
FUSE_SKU_CALIB_HS_CURR_LEVEL_PAD_MASK;
}
fuse->hs_term_range_adj =
(value >> FUSE_SKU_CALIB_HS_TERM_RANGE_ADJ_SHIFT) &
FUSE_SKU_CALIB_HS_TERM_RANGE_ADJ_MASK;
err = tegra_fuse_readl(TEGRA_FUSE_USB_CALIB_EXT_0, &value);
if (err < 0)
return err;
fuse->rpd_ctrl =
(value >> FUSE_USB_CALIB_EXT_RPD_CTRL_SHIFT) &
FUSE_USB_CALIB_EXT_RPD_CTRL_MASK;
return 0;
}
static struct tegra_xusb_padctl *
tegra210_xusb_padctl_probe(struct device *dev,
const struct tegra_xusb_padctl_soc *soc)
{
struct tegra210_xusb_padctl *padctl;
int err;
padctl = devm_kzalloc(dev, sizeof(*padctl), GFP_KERNEL);
if (!padctl)
return ERR_PTR(-ENOMEM);
padctl->base.dev = dev;
padctl->base.soc = soc;
err = tegra210_xusb_read_fuse_calibration(&padctl->fuse);
if (err < 0)
return ERR_PTR(err);
return &padctl->base;
}
static void tegra210_xusb_padctl_remove(struct tegra_xusb_padctl *padctl)
{
}
