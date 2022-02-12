static inline bool phy_is_ulpi(struct tegra_usb_phy *phy)
{
return (phy->instance == 1);
}
static int utmip_pad_open(struct tegra_usb_phy *phy)
{
phy->pad_clk = clk_get_sys("utmip-pad", NULL);
if (IS_ERR(phy->pad_clk)) {
pr_err("%s: can't get utmip pad clock\n", __func__);
return PTR_ERR(phy->pad_clk);
}
if (phy->instance == 0) {
phy->pad_regs = phy->regs;
} else {
phy->pad_regs = ioremap(TEGRA_USB_BASE, TEGRA_USB_SIZE);
if (!phy->pad_regs) {
pr_err("%s: can't remap usb registers\n", __func__);
clk_put(phy->pad_clk);
return -ENOMEM;
}
}
return 0;
}
static void utmip_pad_close(struct tegra_usb_phy *phy)
{
if (phy->instance != 0)
iounmap(phy->pad_regs);
clk_put(phy->pad_clk);
}
static void utmip_pad_power_on(struct tegra_usb_phy *phy)
{
unsigned long val, flags;
void __iomem *base = phy->pad_regs;
clk_prepare_enable(phy->pad_clk);
spin_lock_irqsave(&utmip_pad_lock, flags);
if (utmip_pad_count++ == 0) {
val = readl(base + UTMIP_BIAS_CFG0);
val &= ~(UTMIP_OTGPD | UTMIP_BIASPD);
writel(val, base + UTMIP_BIAS_CFG0);
}
spin_unlock_irqrestore(&utmip_pad_lock, flags);
clk_disable_unprepare(phy->pad_clk);
}
static int utmip_pad_power_off(struct tegra_usb_phy *phy)
{
unsigned long val, flags;
void __iomem *base = phy->pad_regs;
if (!utmip_pad_count) {
pr_err("%s: utmip pad already powered off\n", __func__);
return -EINVAL;
}
clk_prepare_enable(phy->pad_clk);
spin_lock_irqsave(&utmip_pad_lock, flags);
if (--utmip_pad_count == 0) {
val = readl(base + UTMIP_BIAS_CFG0);
val |= UTMIP_OTGPD | UTMIP_BIASPD;
writel(val, base + UTMIP_BIAS_CFG0);
}
spin_unlock_irqrestore(&utmip_pad_lock, flags);
clk_disable_unprepare(phy->pad_clk);
return 0;
}
static int utmi_wait_register(void __iomem *reg, u32 mask, u32 result)
{
unsigned long timeout = 2000;
do {
if ((readl(reg) & mask) == result)
return 0;
udelay(1);
timeout--;
} while (timeout);
return -1;
}
static void utmi_phy_clk_disable(struct tegra_usb_phy *phy)
{
unsigned long val;
void __iomem *base = phy->regs;
if (phy->instance == 0) {
val = readl(base + USB_SUSP_CTRL);
val |= USB_SUSP_SET;
writel(val, base + USB_SUSP_CTRL);
udelay(10);
val = readl(base + USB_SUSP_CTRL);
val &= ~USB_SUSP_SET;
writel(val, base + USB_SUSP_CTRL);
}
if (phy->instance == 2) {
val = readl(base + USB_PORTSC1);
val |= USB_PORTSC1_PHCD;
writel(val, base + USB_PORTSC1);
}
if (utmi_wait_register(base + USB_SUSP_CTRL, USB_PHY_CLK_VALID, 0) < 0)
pr_err("%s: timeout waiting for phy to stabilize\n", __func__);
}
static void utmi_phy_clk_enable(struct tegra_usb_phy *phy)
{
unsigned long val;
void __iomem *base = phy->regs;
if (phy->instance == 0) {
val = readl(base + USB_SUSP_CTRL);
val |= USB_SUSP_CLR;
writel(val, base + USB_SUSP_CTRL);
udelay(10);
val = readl(base + USB_SUSP_CTRL);
val &= ~USB_SUSP_CLR;
writel(val, base + USB_SUSP_CTRL);
}
if (phy->instance == 2) {
val = readl(base + USB_PORTSC1);
val &= ~USB_PORTSC1_PHCD;
writel(val, base + USB_PORTSC1);
}
if (utmi_wait_register(base + USB_SUSP_CTRL, USB_PHY_CLK_VALID,
USB_PHY_CLK_VALID))
pr_err("%s: timeout waiting for phy to stabilize\n", __func__);
}
static int utmi_phy_power_on(struct tegra_usb_phy *phy)
{
unsigned long val;
void __iomem *base = phy->regs;
struct tegra_utmip_config *config = phy->config;
val = readl(base + USB_SUSP_CTRL);
val |= UTMIP_RESET;
writel(val, base + USB_SUSP_CTRL);
if (phy->instance == 0) {
val = readl(base + USB1_LEGACY_CTRL);
val |= USB1_NO_LEGACY_MODE;
writel(val, base + USB1_LEGACY_CTRL);
}
val = readl(base + UTMIP_TX_CFG0);
val &= ~UTMIP_FS_PREABMLE_J;
writel(val, base + UTMIP_TX_CFG0);
val = readl(base + UTMIP_HSRX_CFG0);
val &= ~(UTMIP_IDLE_WAIT(~0) | UTMIP_ELASTIC_LIMIT(~0));
val |= UTMIP_IDLE_WAIT(config->idle_wait_delay);
val |= UTMIP_ELASTIC_LIMIT(config->elastic_limit);
writel(val, base + UTMIP_HSRX_CFG0);
val = readl(base + UTMIP_HSRX_CFG1);
val &= ~UTMIP_HS_SYNC_START_DLY(~0);
val |= UTMIP_HS_SYNC_START_DLY(config->hssync_start_delay);
writel(val, base + UTMIP_HSRX_CFG1);
val = readl(base + UTMIP_DEBOUNCE_CFG0);
val &= ~UTMIP_BIAS_DEBOUNCE_A(~0);
val |= UTMIP_BIAS_DEBOUNCE_A(phy->freq->debounce);
writel(val, base + UTMIP_DEBOUNCE_CFG0);
val = readl(base + UTMIP_MISC_CFG0);
val &= ~UTMIP_SUSPEND_EXIT_ON_EDGE;
writel(val, base + UTMIP_MISC_CFG0);
val = readl(base + UTMIP_MISC_CFG1);
val &= ~(UTMIP_PLL_ACTIVE_DLY_COUNT(~0) | UTMIP_PLLU_STABLE_COUNT(~0));
val |= UTMIP_PLL_ACTIVE_DLY_COUNT(phy->freq->active_delay) |
UTMIP_PLLU_STABLE_COUNT(phy->freq->stable_count);
writel(val, base + UTMIP_MISC_CFG1);
val = readl(base + UTMIP_PLL_CFG1);
val &= ~(UTMIP_XTAL_FREQ_COUNT(~0) | UTMIP_PLLU_ENABLE_DLY_COUNT(~0));
val |= UTMIP_XTAL_FREQ_COUNT(phy->freq->xtal_freq_count) |
UTMIP_PLLU_ENABLE_DLY_COUNT(phy->freq->enable_delay);
writel(val, base + UTMIP_PLL_CFG1);
if (phy->mode == TEGRA_USB_PHY_MODE_DEVICE) {
val = readl(base + USB_SUSP_CTRL);
val &= ~(USB_WAKE_ON_CNNT_EN_DEV | USB_WAKE_ON_DISCON_EN_DEV);
writel(val, base + USB_SUSP_CTRL);
}
utmip_pad_power_on(phy);
val = readl(base + UTMIP_XCVR_CFG0);
val &= ~(UTMIP_FORCE_PD_POWERDOWN | UTMIP_FORCE_PD2_POWERDOWN |
UTMIP_FORCE_PDZI_POWERDOWN | UTMIP_XCVR_SETUP(~0) |
UTMIP_XCVR_LSFSLEW(~0) | UTMIP_XCVR_LSRSLEW(~0) |
UTMIP_XCVR_HSSLEW_MSB(~0));
val |= UTMIP_XCVR_SETUP(config->xcvr_setup);
val |= UTMIP_XCVR_LSFSLEW(config->xcvr_lsfslew);
val |= UTMIP_XCVR_LSRSLEW(config->xcvr_lsrslew);
writel(val, base + UTMIP_XCVR_CFG0);
val = readl(base + UTMIP_XCVR_CFG1);
val &= ~(UTMIP_FORCE_PDDISC_POWERDOWN | UTMIP_FORCE_PDCHRP_POWERDOWN |
UTMIP_FORCE_PDDR_POWERDOWN | UTMIP_XCVR_TERM_RANGE_ADJ(~0));
val |= UTMIP_XCVR_TERM_RANGE_ADJ(config->term_range_adj);
writel(val, base + UTMIP_XCVR_CFG1);
val = readl(base + UTMIP_BAT_CHRG_CFG0);
val &= ~UTMIP_PD_CHRG;
writel(val, base + UTMIP_BAT_CHRG_CFG0);
val = readl(base + UTMIP_BIAS_CFG1);
val &= ~UTMIP_BIAS_PDTRK_COUNT(~0);
val |= UTMIP_BIAS_PDTRK_COUNT(0x5);
writel(val, base + UTMIP_BIAS_CFG1);
if (phy->instance == 0) {
val = readl(base + UTMIP_SPARE_CFG0);
if (phy->mode == TEGRA_USB_PHY_MODE_DEVICE)
val &= ~FUSE_SETUP_SEL;
else
val |= FUSE_SETUP_SEL;
writel(val, base + UTMIP_SPARE_CFG0);
}
if (phy->instance == 2) {
val = readl(base + USB_SUSP_CTRL);
val |= UTMIP_PHY_ENABLE;
writel(val, base + USB_SUSP_CTRL);
}
val = readl(base + USB_SUSP_CTRL);
val &= ~UTMIP_RESET;
writel(val, base + USB_SUSP_CTRL);
if (phy->instance == 0) {
val = readl(base + USB1_LEGACY_CTRL);
val &= ~USB1_VBUS_SENSE_CTL_MASK;
val |= USB1_VBUS_SENSE_CTL_A_SESS_VLD;
writel(val, base + USB1_LEGACY_CTRL);
val = readl(base + USB_SUSP_CTRL);
val &= ~USB_SUSP_SET;
writel(val, base + USB_SUSP_CTRL);
}
utmi_phy_clk_enable(phy);
if (phy->instance == 2) {
val = readl(base + USB_PORTSC1);
val &= ~USB_PORTSC1_PTS(~0);
writel(val, base + USB_PORTSC1);
}
return 0;
}
static int utmi_phy_power_off(struct tegra_usb_phy *phy)
{
unsigned long val;
void __iomem *base = phy->regs;
utmi_phy_clk_disable(phy);
if (phy->mode == TEGRA_USB_PHY_MODE_DEVICE) {
val = readl(base + USB_SUSP_CTRL);
val &= ~USB_WAKEUP_DEBOUNCE_COUNT(~0);
val |= USB_WAKE_ON_CNNT_EN_DEV | USB_WAKEUP_DEBOUNCE_COUNT(5);
writel(val, base + USB_SUSP_CTRL);
}
val = readl(base + USB_SUSP_CTRL);
val |= UTMIP_RESET;
writel(val, base + USB_SUSP_CTRL);
val = readl(base + UTMIP_BAT_CHRG_CFG0);
val |= UTMIP_PD_CHRG;
writel(val, base + UTMIP_BAT_CHRG_CFG0);
val = readl(base + UTMIP_XCVR_CFG0);
val |= UTMIP_FORCE_PD_POWERDOWN | UTMIP_FORCE_PD2_POWERDOWN |
UTMIP_FORCE_PDZI_POWERDOWN;
writel(val, base + UTMIP_XCVR_CFG0);
val = readl(base + UTMIP_XCVR_CFG1);
val |= UTMIP_FORCE_PDDISC_POWERDOWN | UTMIP_FORCE_PDCHRP_POWERDOWN |
UTMIP_FORCE_PDDR_POWERDOWN;
writel(val, base + UTMIP_XCVR_CFG1);
return utmip_pad_power_off(phy);
}
static void utmi_phy_preresume(struct tegra_usb_phy *phy)
{
unsigned long val;
void __iomem *base = phy->regs;
val = readl(base + UTMIP_TX_CFG0);
val |= UTMIP_HS_DISCON_DISABLE;
writel(val, base + UTMIP_TX_CFG0);
}
static void utmi_phy_postresume(struct tegra_usb_phy *phy)
{
unsigned long val;
void __iomem *base = phy->regs;
val = readl(base + UTMIP_TX_CFG0);
val &= ~UTMIP_HS_DISCON_DISABLE;
writel(val, base + UTMIP_TX_CFG0);
}
static void utmi_phy_restore_start(struct tegra_usb_phy *phy,
enum tegra_usb_phy_port_speed port_speed)
{
unsigned long val;
void __iomem *base = phy->regs;
val = readl(base + UTMIP_MISC_CFG0);
val &= ~UTMIP_DPDM_OBSERVE_SEL(~0);
if (port_speed == TEGRA_USB_PHY_PORT_SPEED_LOW)
val |= UTMIP_DPDM_OBSERVE_SEL_FS_K;
else
val |= UTMIP_DPDM_OBSERVE_SEL_FS_J;
writel(val, base + UTMIP_MISC_CFG0);
udelay(1);
val = readl(base + UTMIP_MISC_CFG0);
val |= UTMIP_DPDM_OBSERVE;
writel(val, base + UTMIP_MISC_CFG0);
udelay(10);
}
static void utmi_phy_restore_end(struct tegra_usb_phy *phy)
{
unsigned long val;
void __iomem *base = phy->regs;
val = readl(base + UTMIP_MISC_CFG0);
val &= ~UTMIP_DPDM_OBSERVE;
writel(val, base + UTMIP_MISC_CFG0);
udelay(10);
}
static int ulpi_phy_power_on(struct tegra_usb_phy *phy)
{
int ret;
unsigned long val;
void __iomem *base = phy->regs;
struct tegra_ulpi_config *config = phy->config;
gpio_direction_output(config->reset_gpio, 0);
msleep(5);
gpio_direction_output(config->reset_gpio, 1);
clk_prepare_enable(phy->clk);
msleep(1);
val = readl(base + USB_SUSP_CTRL);
val |= UHSIC_RESET;
writel(val, base + USB_SUSP_CTRL);
val = readl(base + ULPI_TIMING_CTRL_0);
val |= ULPI_OUTPUT_PINMUX_BYP | ULPI_CLKOUT_PINMUX_BYP;
writel(val, base + ULPI_TIMING_CTRL_0);
val = readl(base + USB_SUSP_CTRL);
val |= ULPI_PHY_ENABLE;
writel(val, base + USB_SUSP_CTRL);
val = 0;
writel(val, base + ULPI_TIMING_CTRL_1);
val |= ULPI_DATA_TRIMMER_SEL(4);
val |= ULPI_STPDIRNXT_TRIMMER_SEL(4);
val |= ULPI_DIR_TRIMMER_SEL(4);
writel(val, base + ULPI_TIMING_CTRL_1);
udelay(10);
val |= ULPI_DATA_TRIMMER_LOAD;
val |= ULPI_STPDIRNXT_TRIMMER_LOAD;
val |= ULPI_DIR_TRIMMER_LOAD;
writel(val, base + ULPI_TIMING_CTRL_1);
ret = usb_phy_io_write(phy->ulpi, 0x40, 0x08);
if (ret) {
pr_err("%s: ulpi write failed\n", __func__);
return ret;
}
ret = usb_phy_io_write(phy->ulpi, 0x80, 0x0B);
if (ret) {
pr_err("%s: ulpi write failed\n", __func__);
return ret;
}
val = readl(base + USB_PORTSC1);
val |= USB_PORTSC1_WKOC | USB_PORTSC1_WKDS | USB_PORTSC1_WKCN;
writel(val, base + USB_PORTSC1);
val = readl(base + USB_SUSP_CTRL);
val |= USB_SUSP_CLR;
writel(val, base + USB_SUSP_CTRL);
udelay(100);
val = readl(base + USB_SUSP_CTRL);
val &= ~USB_SUSP_CLR;
writel(val, base + USB_SUSP_CTRL);
return 0;
}
static int ulpi_phy_power_off(struct tegra_usb_phy *phy)
{
unsigned long val;
void __iomem *base = phy->regs;
struct tegra_ulpi_config *config = phy->config;
val = readl(base + USB_PORTSC1);
val &= ~(USB_PORTSC1_WKOC | USB_PORTSC1_WKDS | USB_PORTSC1_WKCN);
writel(val, base + USB_PORTSC1);
clk_disable(phy->clk);
return gpio_direction_output(config->reset_gpio, 0);
}
static int tegra_phy_init(struct usb_phy *x)
{
struct tegra_usb_phy *phy = container_of(x, struct tegra_usb_phy, u_phy);
struct tegra_ulpi_config *ulpi_config;
int err;
if (phy_is_ulpi(phy)) {
ulpi_config = phy->config;
phy->clk = clk_get_sys(NULL, ulpi_config->clk);
if (IS_ERR(phy->clk)) {
pr_err("%s: can't get ulpi clock\n", __func__);
err = -ENXIO;
goto err1;
}
if (!gpio_is_valid(ulpi_config->reset_gpio))
ulpi_config->reset_gpio =
of_get_named_gpio(phy->dev->of_node,
"nvidia,phy-reset-gpio", 0);
if (!gpio_is_valid(ulpi_config->reset_gpio)) {
pr_err("%s: invalid reset gpio: %d\n", __func__,
ulpi_config->reset_gpio);
err = -EINVAL;
goto err1;
}
gpio_request(ulpi_config->reset_gpio, "ulpi_phy_reset_b");
gpio_direction_output(ulpi_config->reset_gpio, 0);
phy->ulpi = otg_ulpi_create(&ulpi_viewport_access_ops, 0);
phy->ulpi->io_priv = phy->regs + ULPI_VIEWPORT;
} else {
err = utmip_pad_open(phy);
if (err < 0)
goto err1;
}
return 0;
err1:
clk_disable_unprepare(phy->pll_u);
clk_put(phy->pll_u);
return err;
}
static void tegra_usb_phy_close(struct usb_phy *x)
{
struct tegra_usb_phy *phy = container_of(x, struct tegra_usb_phy, u_phy);
if (phy_is_ulpi(phy))
clk_put(phy->clk);
else
utmip_pad_close(phy);
clk_disable_unprepare(phy->pll_u);
clk_put(phy->pll_u);
kfree(phy);
}
static int tegra_usb_phy_power_on(struct tegra_usb_phy *phy)
{
if (phy_is_ulpi(phy))
return ulpi_phy_power_on(phy);
else
return utmi_phy_power_on(phy);
}
static int tegra_usb_phy_power_off(struct tegra_usb_phy *phy)
{
if (phy_is_ulpi(phy))
return ulpi_phy_power_off(phy);
else
return utmi_phy_power_off(phy);
}
static int tegra_usb_phy_suspend(struct usb_phy *x, int suspend)
{
struct tegra_usb_phy *phy = container_of(x, struct tegra_usb_phy, u_phy);
if (suspend)
return tegra_usb_phy_power_off(phy);
else
return tegra_usb_phy_power_on(phy);
}
struct tegra_usb_phy *tegra_usb_phy_open(struct device *dev, int instance,
void __iomem *regs, void *config, enum tegra_usb_phy_mode phy_mode)
{
struct tegra_usb_phy *phy;
unsigned long parent_rate;
int i;
int err;
phy = kmalloc(sizeof(struct tegra_usb_phy), GFP_KERNEL);
if (!phy)
return ERR_PTR(-ENOMEM);
phy->instance = instance;
phy->regs = regs;
phy->config = config;
phy->mode = phy_mode;
phy->dev = dev;
if (!phy->config) {
if (phy_is_ulpi(phy)) {
pr_err("%s: ulpi phy configuration missing", __func__);
err = -EINVAL;
goto err0;
} else {
phy->config = &utmip_default[instance];
}
}
phy->pll_u = clk_get_sys(NULL, "pll_u");
if (IS_ERR(phy->pll_u)) {
pr_err("Can't get pll_u clock\n");
err = PTR_ERR(phy->pll_u);
goto err0;
}
clk_prepare_enable(phy->pll_u);
parent_rate = clk_get_rate(clk_get_parent(phy->pll_u));
for (i = 0; i < ARRAY_SIZE(tegra_freq_table); i++) {
if (tegra_freq_table[i].freq == parent_rate) {
phy->freq = &tegra_freq_table[i];
break;
}
}
if (!phy->freq) {
pr_err("invalid pll_u parent rate %ld\n", parent_rate);
err = -EINVAL;
goto err1;
}
phy->u_phy.init = tegra_phy_init;
phy->u_phy.shutdown = tegra_usb_phy_close;
phy->u_phy.set_suspend = tegra_usb_phy_suspend;
return phy;
err1:
clk_disable_unprepare(phy->pll_u);
clk_put(phy->pll_u);
err0:
kfree(phy);
return ERR_PTR(err);
}
void tegra_usb_phy_preresume(struct tegra_usb_phy *phy)
{
if (!phy_is_ulpi(phy))
utmi_phy_preresume(phy);
}
void tegra_usb_phy_postresume(struct tegra_usb_phy *phy)
{
if (!phy_is_ulpi(phy))
utmi_phy_postresume(phy);
}
void tegra_ehci_phy_restore_start(struct tegra_usb_phy *phy,
enum tegra_usb_phy_port_speed port_speed)
{
if (!phy_is_ulpi(phy))
utmi_phy_restore_start(phy, port_speed);
}
void tegra_ehci_phy_restore_end(struct tegra_usb_phy *phy)
{
if (!phy_is_ulpi(phy))
utmi_phy_restore_end(phy);
}
void tegra_usb_phy_clk_disable(struct tegra_usb_phy *phy)
{
if (!phy_is_ulpi(phy))
utmi_phy_clk_disable(phy);
}
void tegra_usb_phy_clk_enable(struct tegra_usb_phy *phy)
{
if (!phy_is_ulpi(phy))
utmi_phy_clk_enable(phy);
}
