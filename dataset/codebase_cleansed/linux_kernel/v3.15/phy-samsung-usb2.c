static int samsung_usb2_phy_power_on(struct phy *phy)
{
struct samsung_usb2_phy_instance *inst = phy_get_drvdata(phy);
struct samsung_usb2_phy_driver *drv = inst->drv;
int ret;
dev_dbg(drv->dev, "Request to power_on \"%s\" usb phy\n",
inst->cfg->label);
ret = clk_prepare_enable(drv->clk);
if (ret)
goto err_main_clk;
ret = clk_prepare_enable(drv->ref_clk);
if (ret)
goto err_instance_clk;
if (inst->cfg->power_on) {
spin_lock(&drv->lock);
ret = inst->cfg->power_on(inst);
spin_unlock(&drv->lock);
}
return 0;
err_instance_clk:
clk_disable_unprepare(drv->clk);
err_main_clk:
return ret;
}
static int samsung_usb2_phy_power_off(struct phy *phy)
{
struct samsung_usb2_phy_instance *inst = phy_get_drvdata(phy);
struct samsung_usb2_phy_driver *drv = inst->drv;
int ret = 0;
dev_dbg(drv->dev, "Request to power_off \"%s\" usb phy\n",
inst->cfg->label);
if (inst->cfg->power_off) {
spin_lock(&drv->lock);
ret = inst->cfg->power_off(inst);
spin_unlock(&drv->lock);
}
clk_disable_unprepare(drv->ref_clk);
clk_disable_unprepare(drv->clk);
return ret;
}
static struct phy *samsung_usb2_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct samsung_usb2_phy_driver *drv;
drv = dev_get_drvdata(dev);
if (!drv)
return ERR_PTR(-EINVAL);
if (WARN_ON(args->args[0] >= drv->cfg->num_phys))
return ERR_PTR(-ENODEV);
return drv->instances[args->args[0]].phy;
}
static int samsung_usb2_phy_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct samsung_usb2_phy_config *cfg;
struct device *dev = &pdev->dev;
struct phy_provider *phy_provider;
struct resource *mem;
struct samsung_usb2_phy_driver *drv;
int i, ret;
if (!pdev->dev.of_node) {
dev_err(dev, "This driver is required to be instantiated from device tree\n");
return -EINVAL;
}
match = of_match_node(samsung_usb2_phy_of_match, pdev->dev.of_node);
if (!match) {
dev_err(dev, "of_match_node() failed\n");
return -EINVAL;
}
cfg = match->data;
drv = devm_kzalloc(dev, sizeof(struct samsung_usb2_phy_driver) +
cfg->num_phys * sizeof(struct samsung_usb2_phy_instance),
GFP_KERNEL);
if (!drv)
return -ENOMEM;
dev_set_drvdata(dev, drv);
spin_lock_init(&drv->lock);
drv->cfg = cfg;
drv->dev = dev;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
drv->reg_phy = devm_ioremap_resource(dev, mem);
if (IS_ERR(drv->reg_phy)) {
dev_err(dev, "Failed to map register memory (phy)\n");
return PTR_ERR(drv->reg_phy);
}
drv->reg_pmu = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"samsung,pmureg-phandle");
if (IS_ERR(drv->reg_pmu)) {
dev_err(dev, "Failed to map PMU registers (via syscon)\n");
return PTR_ERR(drv->reg_pmu);
}
if (drv->cfg->has_mode_switch) {
drv->reg_sys = syscon_regmap_lookup_by_phandle(
pdev->dev.of_node, "samsung,sysreg-phandle");
if (IS_ERR(drv->reg_sys)) {
dev_err(dev, "Failed to map system registers (via syscon)\n");
return PTR_ERR(drv->reg_sys);
}
}
drv->clk = devm_clk_get(dev, "phy");
if (IS_ERR(drv->clk)) {
dev_err(dev, "Failed to get clock of phy controller\n");
return PTR_ERR(drv->clk);
}
drv->ref_clk = devm_clk_get(dev, "ref");
if (IS_ERR(drv->ref_clk)) {
dev_err(dev, "Failed to get reference clock for the phy controller\n");
return PTR_ERR(drv->ref_clk);
}
drv->ref_rate = clk_get_rate(drv->ref_clk);
if (drv->cfg->rate_to_clk) {
ret = drv->cfg->rate_to_clk(drv->ref_rate, &drv->ref_reg_val);
if (ret)
return ret;
}
for (i = 0; i < drv->cfg->num_phys; i++) {
char *label = drv->cfg->phys[i].label;
struct samsung_usb2_phy_instance *p = &drv->instances[i];
dev_dbg(dev, "Creating phy \"%s\"\n", label);
p->phy = devm_phy_create(dev, &samsung_usb2_phy_ops, NULL);
if (IS_ERR(p->phy)) {
dev_err(drv->dev, "Failed to create usb2_phy \"%s\"\n",
label);
return PTR_ERR(p->phy);
}
p->cfg = &drv->cfg->phys[i];
p->drv = drv;
phy_set_bus_width(p->phy, 8);
phy_set_drvdata(p->phy, p);
}
phy_provider = devm_of_phy_provider_register(dev,
samsung_usb2_phy_xlate);
if (IS_ERR(phy_provider)) {
dev_err(drv->dev, "Failed to register phy provider\n");
return PTR_ERR(phy_provider);
}
return 0;
}
