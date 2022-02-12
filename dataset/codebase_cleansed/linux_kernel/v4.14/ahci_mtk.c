static int mtk_ahci_platform_resets(struct ahci_host_priv *hpriv,
struct device *dev)
{
struct mtk_ahci_plat *plat = hpriv->plat_data;
int err;
plat->axi_rst = devm_reset_control_get_optional_exclusive(dev, "axi");
if (PTR_ERR(plat->axi_rst) == -EPROBE_DEFER)
return PTR_ERR(plat->axi_rst);
plat->sw_rst = devm_reset_control_get_optional_exclusive(dev, "sw");
if (PTR_ERR(plat->sw_rst) == -EPROBE_DEFER)
return PTR_ERR(plat->sw_rst);
plat->reg_rst = devm_reset_control_get_optional_exclusive(dev, "reg");
if (PTR_ERR(plat->reg_rst) == -EPROBE_DEFER)
return PTR_ERR(plat->reg_rst);
err = reset_control_assert(plat->axi_rst);
if (err) {
dev_err(dev, "failed to assert AXI bus\n");
return err;
}
err = reset_control_assert(plat->sw_rst);
if (err) {
dev_err(dev, "failed to assert PHY digital part\n");
return err;
}
err = reset_control_assert(plat->reg_rst);
if (err) {
dev_err(dev, "failed to assert PHY register part\n");
return err;
}
err = reset_control_deassert(plat->reg_rst);
if (err) {
dev_err(dev, "failed to deassert PHY register part\n");
return err;
}
err = reset_control_deassert(plat->sw_rst);
if (err) {
dev_err(dev, "failed to deassert PHY digital part\n");
return err;
}
err = reset_control_deassert(plat->axi_rst);
if (err) {
dev_err(dev, "failed to deassert AXI bus\n");
return err;
}
return 0;
}
static int mtk_ahci_parse_property(struct ahci_host_priv *hpriv,
struct device *dev)
{
struct mtk_ahci_plat *plat = hpriv->plat_data;
struct device_node *np = dev->of_node;
if (of_find_property(np, "mediatek,phy-mode", NULL)) {
plat->mode = syscon_regmap_lookup_by_phandle(
np, "mediatek,phy-mode");
if (IS_ERR(plat->mode)) {
dev_err(dev, "missing phy-mode phandle\n");
return PTR_ERR(plat->mode);
}
regmap_update_bits(plat->mode, SYS_CFG, SYS_CFG_SATA_MSK,
SYS_CFG_SATA_EN);
}
of_property_read_u32(np, "ports-implemented", &hpriv->force_port_map);
return 0;
}
static int mtk_ahci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_ahci_plat *plat;
struct ahci_host_priv *hpriv;
int err;
plat = devm_kzalloc(dev, sizeof(*plat), GFP_KERNEL);
if (!plat)
return -ENOMEM;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
hpriv->plat_data = plat;
err = mtk_ahci_parse_property(hpriv, dev);
if (err)
return err;
err = mtk_ahci_platform_resets(hpriv, dev);
if (err)
return err;
err = ahci_platform_enable_resources(hpriv);
if (err)
return err;
err = ahci_platform_init_host(pdev, hpriv, &ahci_port_info,
&ahci_platform_sht);
if (err)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return err;
}
