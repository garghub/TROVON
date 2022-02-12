static int rcar_gen2_phy_init(struct phy *p)
{
struct rcar_gen2_phy *phy = phy_get_drvdata(p);
struct rcar_gen2_channel *channel = phy->channel;
struct rcar_gen2_phy_driver *drv = channel->drv;
unsigned long flags;
u32 ugctrl2;
if (cmpxchg(&channel->selected_phy, -1, phy->number) != -1)
return -EBUSY;
clk_prepare_enable(drv->clk);
spin_lock_irqsave(&drv->lock, flags);
ugctrl2 = readl(drv->base + USBHS_UGCTRL2);
ugctrl2 &= ~channel->select_mask;
ugctrl2 |= phy->select_value;
writel(ugctrl2, drv->base + USBHS_UGCTRL2);
spin_unlock_irqrestore(&drv->lock, flags);
return 0;
}
static int rcar_gen2_phy_exit(struct phy *p)
{
struct rcar_gen2_phy *phy = phy_get_drvdata(p);
struct rcar_gen2_channel *channel = phy->channel;
clk_disable_unprepare(channel->drv->clk);
channel->selected_phy = -1;
return 0;
}
static int rcar_gen2_phy_power_on(struct phy *p)
{
struct rcar_gen2_phy *phy = phy_get_drvdata(p);
struct rcar_gen2_phy_driver *drv = phy->channel->drv;
void __iomem *base = drv->base;
unsigned long flags;
u32 value;
int err = 0, i;
if (phy->select_value != USBHS_UGCTRL2_USB0SEL_HS_USB)
return 0;
spin_lock_irqsave(&drv->lock, flags);
value = readl(base + USBHS_UGCTRL);
value &= ~USBHS_UGCTRL_PLLRESET;
writel(value, base + USBHS_UGCTRL);
value = readw(base + USBHS_LPSTS);
value |= USBHS_LPSTS_SUSPM;
writew(value, base + USBHS_LPSTS);
for (i = 0; i < 20; i++) {
value = readl(base + USBHS_UGSTS);
if ((value & USBHS_UGSTS_LOCK) == USBHS_UGSTS_LOCK) {
value = readl(base + USBHS_UGCTRL);
value |= USBHS_UGCTRL_CONNECT;
writel(value, base + USBHS_UGCTRL);
goto out;
}
udelay(1);
}
err = -ETIMEDOUT;
out:
spin_unlock_irqrestore(&drv->lock, flags);
return err;
}
static int rcar_gen2_phy_power_off(struct phy *p)
{
struct rcar_gen2_phy *phy = phy_get_drvdata(p);
struct rcar_gen2_phy_driver *drv = phy->channel->drv;
void __iomem *base = drv->base;
unsigned long flags;
u32 value;
if (phy->select_value != USBHS_UGCTRL2_USB0SEL_HS_USB)
return 0;
spin_lock_irqsave(&drv->lock, flags);
value = readl(base + USBHS_UGCTRL);
value &= ~USBHS_UGCTRL_CONNECT;
writel(value, base + USBHS_UGCTRL);
value = readw(base + USBHS_LPSTS);
value &= ~USBHS_LPSTS_SUSPM;
writew(value, base + USBHS_LPSTS);
value = readl(base + USBHS_UGCTRL);
value |= USBHS_UGCTRL_PLLRESET;
writel(value, base + USBHS_UGCTRL);
spin_unlock_irqrestore(&drv->lock, flags);
return 0;
}
static struct phy *rcar_gen2_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct rcar_gen2_phy_driver *drv;
struct device_node *np = args->np;
int i;
if (!of_device_is_available(np)) {
dev_warn(dev, "Requested PHY is disabled\n");
return ERR_PTR(-ENODEV);
}
drv = dev_get_drvdata(dev);
if (!drv)
return ERR_PTR(-EINVAL);
for (i = 0; i < drv->num_channels; i++) {
if (np == drv->channels[i].of_node)
break;
}
if (i >= drv->num_channels || args->args[0] >= 2)
return ERR_PTR(-ENODEV);
return drv->channels[i].phys[args->args[0]].phy;
}
static int rcar_gen2_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rcar_gen2_phy_driver *drv;
struct phy_provider *provider;
struct device_node *np;
struct resource *res;
void __iomem *base;
struct clk *clk;
int i = 0;
if (!dev->of_node) {
dev_err(dev,
"This driver is required to be instantiated from device tree\n");
return -EINVAL;
}
clk = devm_clk_get(dev, "usbhs");
if (IS_ERR(clk)) {
dev_err(dev, "Can't get USBHS clock\n");
return PTR_ERR(clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
drv = devm_kzalloc(dev, sizeof(*drv), GFP_KERNEL);
if (!drv)
return -ENOMEM;
spin_lock_init(&drv->lock);
drv->clk = clk;
drv->base = base;
drv->num_channels = of_get_child_count(dev->of_node);
drv->channels = devm_kcalloc(dev, drv->num_channels,
sizeof(struct rcar_gen2_channel),
GFP_KERNEL);
if (!drv->channels)
return -ENOMEM;
for_each_child_of_node(dev->of_node, np) {
struct rcar_gen2_channel *channel = drv->channels + i;
u32 channel_num;
int error, n;
channel->of_node = np;
channel->drv = drv;
channel->selected_phy = -1;
error = of_property_read_u32(np, "reg", &channel_num);
if (error || channel_num > 2) {
dev_err(dev, "Invalid \"reg\" property\n");
return error;
}
channel->select_mask = select_mask[channel_num];
for (n = 0; n < PHYS_PER_CHANNEL; n++) {
struct rcar_gen2_phy *phy = &channel->phys[n];
phy->channel = channel;
phy->number = n;
phy->select_value = select_value[channel_num][n];
phy->phy = devm_phy_create(dev, NULL,
&rcar_gen2_phy_ops);
if (IS_ERR(phy->phy)) {
dev_err(dev, "Failed to create PHY\n");
return PTR_ERR(phy->phy);
}
phy_set_drvdata(phy->phy, phy);
}
i++;
}
provider = devm_of_phy_provider_register(dev, rcar_gen2_phy_xlate);
if (IS_ERR(provider)) {
dev_err(dev, "Failed to register PHY provider\n");
return PTR_ERR(provider);
}
dev_set_drvdata(dev, drv);
return 0;
}
