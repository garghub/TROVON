static int cygnus_pcie_power_config(struct cygnus_pcie_phy *phy, bool enable)
{
struct cygnus_pcie_phy_core *core = phy->core;
unsigned shift;
u32 val;
mutex_lock(&core->lock);
switch (phy->id) {
case CYGNUS_PHY_PCIE0:
shift = PCIE0_PHY_IDDQ_SHIFT;
break;
case CYGNUS_PHY_PCIE1:
shift = PCIE1_PHY_IDDQ_SHIFT;
break;
default:
mutex_unlock(&core->lock);
dev_err(core->dev, "PCIe PHY %d invalid\n", phy->id);
return -EINVAL;
}
if (enable) {
val = readl(core->base + PCIE_CFG_OFFSET);
val &= ~BIT(shift);
writel(val, core->base + PCIE_CFG_OFFSET);
msleep(50);
} else {
val = readl(core->base + PCIE_CFG_OFFSET);
val |= BIT(shift);
writel(val, core->base + PCIE_CFG_OFFSET);
}
mutex_unlock(&core->lock);
dev_dbg(core->dev, "PCIe PHY %d %s\n", phy->id,
enable ? "enabled" : "disabled");
return 0;
}
static int cygnus_pcie_phy_power_on(struct phy *p)
{
struct cygnus_pcie_phy *phy = phy_get_drvdata(p);
return cygnus_pcie_power_config(phy, true);
}
static int cygnus_pcie_phy_power_off(struct phy *p)
{
struct cygnus_pcie_phy *phy = phy_get_drvdata(p);
return cygnus_pcie_power_config(phy, false);
}
static int cygnus_pcie_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node, *child;
struct cygnus_pcie_phy_core *core;
struct phy_provider *provider;
struct resource *res;
unsigned cnt = 0;
int ret;
if (of_get_child_count(node) == 0) {
dev_err(dev, "PHY no child node\n");
return -ENODEV;
}
core = devm_kzalloc(dev, sizeof(*core), GFP_KERNEL);
if (!core)
return -ENOMEM;
core->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
core->base = devm_ioremap_resource(dev, res);
if (IS_ERR(core->base))
return PTR_ERR(core->base);
mutex_init(&core->lock);
for_each_available_child_of_node(node, child) {
unsigned int id;
struct cygnus_pcie_phy *p;
if (of_property_read_u32(child, "reg", &id)) {
dev_err(dev, "missing reg property for %s\n",
child->name);
ret = -EINVAL;
goto put_child;
}
if (id >= MAX_NUM_PHYS) {
dev_err(dev, "invalid PHY id: %u\n", id);
ret = -EINVAL;
goto put_child;
}
if (core->phys[id].phy) {
dev_err(dev, "duplicated PHY id: %u\n", id);
ret = -EINVAL;
goto put_child;
}
p = &core->phys[id];
p->phy = devm_phy_create(dev, child, &cygnus_pcie_phy_ops);
if (IS_ERR(p->phy)) {
dev_err(dev, "failed to create PHY\n");
ret = PTR_ERR(p->phy);
goto put_child;
}
p->core = core;
p->id = id;
phy_set_drvdata(p->phy, p);
cnt++;
}
dev_set_drvdata(dev, core);
provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(provider)) {
dev_err(dev, "failed to register PHY provider\n");
return PTR_ERR(provider);
}
dev_dbg(dev, "registered %u PCIe PHY(s)\n", cnt);
return 0;
put_child:
of_node_put(child);
return ret;
}
