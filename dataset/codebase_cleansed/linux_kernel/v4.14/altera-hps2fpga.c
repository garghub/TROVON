static int alt_hps2fpga_enable_show(struct fpga_bridge *bridge)
{
struct altera_hps2fpga_data *priv = bridge->priv;
return reset_control_status(priv->bridge_reset);
}
static int _alt_hps2fpga_enable_set(struct altera_hps2fpga_data *priv,
bool enable)
{
unsigned long flags;
int ret;
if (enable)
ret = reset_control_deassert(priv->bridge_reset);
else
ret = reset_control_assert(priv->bridge_reset);
if (ret)
return ret;
if (priv->remap_mask) {
spin_lock_irqsave(&l3_remap_lock, flags);
l3_remap_shadow |= ALT_L3_REMAP_MPUZERO_MSK;
if (enable)
l3_remap_shadow |= priv->remap_mask;
else
l3_remap_shadow &= ~priv->remap_mask;
ret = regmap_write(priv->l3reg, ALT_L3_REMAP_OFST,
l3_remap_shadow);
spin_unlock_irqrestore(&l3_remap_lock, flags);
}
return ret;
}
static int alt_hps2fpga_enable_set(struct fpga_bridge *bridge, bool enable)
{
return _alt_hps2fpga_enable_set(bridge->priv, enable);
}
static int alt_fpga_bridge_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct altera_hps2fpga_data *priv;
const struct of_device_id *of_id;
u32 enable;
int ret;
of_id = of_match_device(altera_fpga_of_match, dev);
if (!of_id) {
dev_err(dev, "failed to match device\n");
return -ENODEV;
}
priv = (struct altera_hps2fpga_data *)of_id->data;
priv->bridge_reset = of_reset_control_get_exclusive_by_index(dev->of_node,
0);
if (IS_ERR(priv->bridge_reset)) {
dev_err(dev, "Could not get %s reset control\n", priv->name);
return PTR_ERR(priv->bridge_reset);
}
if (priv->remap_mask) {
priv->l3reg = syscon_regmap_lookup_by_compatible("altr,l3regs");
if (IS_ERR(priv->l3reg)) {
dev_err(dev, "regmap for altr,l3regs lookup failed\n");
return PTR_ERR(priv->l3reg);
}
}
priv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(dev, "no clock specified\n");
return PTR_ERR(priv->clk);
}
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(dev, "could not enable clock\n");
return -EBUSY;
}
if (!of_property_read_u32(dev->of_node, "bridge-enable", &enable)) {
if (enable > 1) {
dev_warn(dev, "invalid bridge-enable %u > 1\n", enable);
} else {
dev_info(dev, "%s bridge\n",
(enable ? "enabling" : "disabling"));
ret = _alt_hps2fpga_enable_set(priv, enable);
if (ret)
goto err;
}
}
ret = fpga_bridge_register(dev, priv->name, &altera_hps2fpga_br_ops,
priv);
err:
if (ret)
clk_disable_unprepare(priv->clk);
return ret;
}
static int alt_fpga_bridge_remove(struct platform_device *pdev)
{
struct fpga_bridge *bridge = platform_get_drvdata(pdev);
struct altera_hps2fpga_data *priv = bridge->priv;
fpga_bridge_unregister(&pdev->dev);
clk_disable_unprepare(priv->clk);
return 0;
}
