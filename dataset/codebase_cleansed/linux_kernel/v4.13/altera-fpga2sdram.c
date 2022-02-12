static int alt_fpga2sdram_enable_show(struct fpga_bridge *bridge)
{
struct alt_fpga2sdram_data *priv = bridge->priv;
int value;
regmap_read(priv->sdrctl, ALT_SDR_CTL_FPGAPORTRST_OFST, &value);
return (value & priv->mask) == priv->mask;
}
static inline int _alt_fpga2sdram_enable_set(struct alt_fpga2sdram_data *priv,
bool enable)
{
return regmap_update_bits(priv->sdrctl, ALT_SDR_CTL_FPGAPORTRST_OFST,
priv->mask, enable ? priv->mask : 0);
}
static int alt_fpga2sdram_enable_set(struct fpga_bridge *bridge, bool enable)
{
return _alt_fpga2sdram_enable_set(bridge->priv, enable);
}
static int alt_fpga_bridge_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct alt_fpga2sdram_data *priv;
u32 enable;
struct regmap *sysmgr;
int ret = 0;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
priv->sdrctl = syscon_regmap_lookup_by_compatible("altr,sdr-ctl");
if (IS_ERR(priv->sdrctl)) {
dev_err(dev, "regmap for altr,sdr-ctl lookup failed.\n");
return PTR_ERR(priv->sdrctl);
}
sysmgr = syscon_regmap_lookup_by_compatible("altr,sys-mgr");
if (IS_ERR(sysmgr)) {
dev_err(dev, "regmap for altr,sys-mgr lookup failed.\n");
return PTR_ERR(sysmgr);
}
regmap_read(sysmgr, SYSMGR_ISWGRP_HANDOFF3, &priv->mask);
ret = fpga_bridge_register(dev, F2S_BRIDGE_NAME,
&altera_fpga2sdram_br_ops, priv);
if (ret)
return ret;
dev_info(dev, "driver initialized with handoff %08x\n", priv->mask);
if (!of_property_read_u32(dev->of_node, "bridge-enable", &enable)) {
if (enable > 1) {
dev_warn(dev, "invalid bridge-enable %u > 1\n", enable);
} else {
dev_info(dev, "%s bridge\n",
(enable ? "enabling" : "disabling"));
ret = _alt_fpga2sdram_enable_set(priv, enable);
if (ret) {
fpga_bridge_unregister(&pdev->dev);
return ret;
}
}
}
return ret;
}
static int alt_fpga_bridge_remove(struct platform_device *pdev)
{
fpga_bridge_unregister(&pdev->dev);
return 0;
}
