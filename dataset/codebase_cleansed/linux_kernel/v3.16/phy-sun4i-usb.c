static void sun4i_usb_phy_write(struct sun4i_usb_phy *phy, u32 addr, u32 data,
int len)
{
struct sun4i_usb_phy_data *phy_data = to_sun4i_usb_phy_data(phy);
u32 temp, usbc_bit = BIT(phy->index * 2);
int i;
mutex_lock(&phy_data->mutex);
for (i = 0; i < len; i++) {
temp = readl(phy_data->base + REG_PHYCTL);
temp &= ~(0xff << 8);
temp |= ((addr + i) << 8);
writel(temp, phy_data->base + REG_PHYCTL);
temp = readb(phy_data->base + REG_PHYCTL);
if (data & 0x1)
temp |= PHYCTL_DATA;
else
temp &= ~PHYCTL_DATA;
temp &= ~usbc_bit;
writeb(temp, phy_data->base + REG_PHYCTL);
temp = readb(phy_data->base + REG_PHYCTL);
temp |= usbc_bit;
writeb(temp, phy_data->base + REG_PHYCTL);
temp = readb(phy_data->base + REG_PHYCTL);
temp &= ~usbc_bit;
writeb(temp, phy_data->base + REG_PHYCTL);
data >>= 1;
}
mutex_unlock(&phy_data->mutex);
}
static void sun4i_usb_phy_passby(struct sun4i_usb_phy *phy, int enable)
{
u32 bits, reg_value;
if (!phy->pmu)
return;
bits = SUNXI_AHB_ICHR8_EN | SUNXI_AHB_INCR4_BURST_EN |
SUNXI_AHB_INCRX_ALIGN_EN | SUNXI_ULPI_BYPASS_EN;
reg_value = readl(phy->pmu);
if (enable)
reg_value |= bits;
else
reg_value &= ~bits;
writel(reg_value, phy->pmu);
}
static int sun4i_usb_phy_init(struct phy *_phy)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
struct sun4i_usb_phy_data *data = to_sun4i_usb_phy_data(phy);
int ret;
ret = clk_prepare_enable(phy->clk);
if (ret)
return ret;
ret = reset_control_deassert(phy->reset);
if (ret) {
clk_disable_unprepare(phy->clk);
return ret;
}
sun4i_usb_phy_write(phy, PHY_TX_AMPLITUDE_TUNE, 0x14, 5);
sun4i_usb_phy_write(phy, PHY_DISCON_TH_SEL, data->disc_thresh, 2);
sun4i_usb_phy_passby(phy, 1);
return 0;
}
static int sun4i_usb_phy_exit(struct phy *_phy)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
sun4i_usb_phy_passby(phy, 0);
reset_control_assert(phy->reset);
clk_disable_unprepare(phy->clk);
return 0;
}
static int sun4i_usb_phy_power_on(struct phy *_phy)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
int ret = 0;
if (phy->vbus)
ret = regulator_enable(phy->vbus);
return ret;
}
static int sun4i_usb_phy_power_off(struct phy *_phy)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
if (phy->vbus)
regulator_disable(phy->vbus);
return 0;
}
static struct phy *sun4i_usb_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct sun4i_usb_phy_data *data = dev_get_drvdata(dev);
if (WARN_ON(args->args[0] == 0 || args->args[0] >= data->num_phys))
return ERR_PTR(-ENODEV);
return data->phys[args->args[0]].phy;
}
static int sun4i_usb_phy_probe(struct platform_device *pdev)
{
struct sun4i_usb_phy_data *data;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct phy_provider *phy_provider;
bool dedicated_clocks;
struct resource *res;
int i;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
mutex_init(&data->mutex);
if (of_device_is_compatible(np, "allwinner,sun5i-a13-usb-phy"))
data->num_phys = 2;
else
data->num_phys = 3;
if (of_device_is_compatible(np, "allwinner,sun4i-a10-usb-phy"))
data->disc_thresh = 3;
else
data->disc_thresh = 2;
if (of_device_is_compatible(np, "allwinner,sun6i-a31-usb-phy"))
dedicated_clocks = true;
else
dedicated_clocks = false;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "phy_ctrl");
data->base = devm_ioremap_resource(dev, res);
if (IS_ERR(data->base))
return PTR_ERR(data->base);
for (i = 1; i < data->num_phys; i++) {
struct sun4i_usb_phy *phy = data->phys + i;
char name[16];
snprintf(name, sizeof(name), "usb%d_vbus", i);
phy->vbus = devm_regulator_get_optional(dev, name);
if (IS_ERR(phy->vbus)) {
if (PTR_ERR(phy->vbus) == -EPROBE_DEFER)
return -EPROBE_DEFER;
phy->vbus = NULL;
}
if (dedicated_clocks)
snprintf(name, sizeof(name), "usb%d_phy", i);
else
strlcpy(name, "usb_phy", sizeof(name));
phy->clk = devm_clk_get(dev, name);
if (IS_ERR(phy->clk)) {
dev_err(dev, "failed to get clock %s\n", name);
return PTR_ERR(phy->clk);
}
snprintf(name, sizeof(name), "usb%d_reset", i);
phy->reset = devm_reset_control_get(dev, name);
if (IS_ERR(phy->reset)) {
dev_err(dev, "failed to get reset %s\n", name);
return PTR_ERR(phy->reset);
}
if (i) {
snprintf(name, sizeof(name), "pmu%d", i);
res = platform_get_resource_byname(pdev,
IORESOURCE_MEM, name);
phy->pmu = devm_ioremap_resource(dev, res);
if (IS_ERR(phy->pmu))
return PTR_ERR(phy->pmu);
}
phy->phy = devm_phy_create(dev, &sun4i_usb_phy_ops, NULL);
if (IS_ERR(phy->phy)) {
dev_err(dev, "failed to create PHY %d\n", i);
return PTR_ERR(phy->phy);
}
phy->index = i;
phy_set_drvdata(phy->phy, &data->phys[i]);
}
dev_set_drvdata(dev, data);
phy_provider = devm_of_phy_provider_register(dev, sun4i_usb_phy_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
return 0;
}
