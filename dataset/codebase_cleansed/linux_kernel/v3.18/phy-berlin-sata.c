static inline void phy_berlin_sata_reg_setbits(void __iomem *ctrl_reg, u32 reg,
u32 mask, u32 val)
{
u32 regval;
writel(PHY_BASE + reg, ctrl_reg + PORT_VSR_ADDR);
regval = readl(ctrl_reg + PORT_VSR_DATA);
regval &= ~mask;
regval |= val;
writel(regval, ctrl_reg + PORT_VSR_DATA);
}
static int phy_berlin_sata_power_on(struct phy *phy)
{
struct phy_berlin_desc *desc = phy_get_drvdata(phy);
struct phy_berlin_priv *priv = dev_get_drvdata(phy->dev.parent);
void __iomem *ctrl_reg = priv->base + 0x60 + (desc->index * 0x80);
int ret = 0;
u32 regval;
clk_prepare_enable(priv->clk);
spin_lock(&priv->lock);
writel(CONTROL_REGISTER, priv->base + HOST_VSA_ADDR);
regval = readl(priv->base + HOST_VSA_DATA);
regval &= ~desc->power_bit;
writel(regval, priv->base + HOST_VSA_DATA);
writel(MBUS_SIZE_CONTROL, priv->base + HOST_VSA_ADDR);
regval = readl(priv->base + HOST_VSA_DATA);
regval |= MBUS_WRITE_REQUEST_SIZE_128 | MBUS_READ_REQUEST_SIZE_128;
writel(regval, priv->base + HOST_VSA_DATA);
phy_berlin_sata_reg_setbits(ctrl_reg, 0x1, 0xff,
REF_FREF_SEL_25 | PHY_MODE_SATA);
phy_berlin_sata_reg_setbits(ctrl_reg, 0x25, 0xc00, PHY_GEN_MAX_6_0);
phy_berlin_sata_reg_setbits(ctrl_reg, 0x23, 0xc00, DATA_BIT_WIDTH_40);
phy_berlin_sata_reg_setbits(ctrl_reg, 0x2, 0x0, USE_MAX_PLL_RATE);
regval = readl(ctrl_reg + PORT_SCR_CTL);
regval &= ~GENMASK(7, 4);
regval |= 0x30;
writel(regval, ctrl_reg + PORT_SCR_CTL);
spin_unlock(&priv->lock);
clk_disable_unprepare(priv->clk);
return ret;
}
static int phy_berlin_sata_power_off(struct phy *phy)
{
struct phy_berlin_desc *desc = phy_get_drvdata(phy);
struct phy_berlin_priv *priv = dev_get_drvdata(phy->dev.parent);
u32 regval;
clk_prepare_enable(priv->clk);
spin_lock(&priv->lock);
writel(CONTROL_REGISTER, priv->base + HOST_VSA_ADDR);
regval = readl(priv->base + HOST_VSA_DATA);
regval |= desc->power_bit;
writel(regval, priv->base + HOST_VSA_DATA);
spin_unlock(&priv->lock);
clk_disable_unprepare(priv->clk);
return 0;
}
static struct phy *phy_berlin_sata_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct phy_berlin_priv *priv = dev_get_drvdata(dev);
int i;
if (WARN_ON(args->args[0] >= priv->nphys))
return ERR_PTR(-ENODEV);
for (i = 0; i < priv->nphys; i++) {
if (priv->phys[i]->index == args->args[0])
break;
}
if (i == priv->nphys)
return ERR_PTR(-ENODEV);
return priv->phys[i]->phy;
}
static int phy_berlin_sata_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *child;
struct phy *phy;
struct phy_provider *phy_provider;
struct phy_berlin_priv *priv;
struct resource *res;
int i = 0;
u32 phy_id;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
priv->base = devm_ioremap(dev, res->start, resource_size(res));
if (!priv->base)
return -ENOMEM;
priv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(priv->clk))
return PTR_ERR(priv->clk);
priv->nphys = of_get_child_count(dev->of_node);
if (priv->nphys == 0)
return -ENODEV;
priv->phys = devm_kzalloc(dev, priv->nphys * sizeof(*priv->phys),
GFP_KERNEL);
if (!priv->phys)
return -ENOMEM;
dev_set_drvdata(dev, priv);
spin_lock_init(&priv->lock);
for_each_available_child_of_node(dev->of_node, child) {
struct phy_berlin_desc *phy_desc;
if (of_property_read_u32(child, "reg", &phy_id)) {
dev_err(dev, "missing reg property in node %s\n",
child->name);
return -EINVAL;
}
if (phy_id >= ARRAY_SIZE(phy_berlin_power_down_bits)) {
dev_err(dev, "invalid reg in node %s\n", child->name);
return -EINVAL;
}
phy_desc = devm_kzalloc(dev, sizeof(*phy_desc), GFP_KERNEL);
if (!phy_desc)
return -ENOMEM;
phy = devm_phy_create(dev, NULL, &phy_berlin_sata_ops, NULL);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create PHY %d\n", phy_id);
return PTR_ERR(phy);
}
phy_desc->phy = phy;
phy_desc->power_bit = phy_berlin_power_down_bits[phy_id];
phy_desc->index = phy_id;
phy_set_drvdata(phy, phy_desc);
priv->phys[i++] = phy_desc;
phy_berlin_sata_power_off(phy);
}
phy_provider =
devm_of_phy_provider_register(dev, phy_berlin_sata_phy_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
return 0;
}
