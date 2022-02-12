static void ahci_mvebu_mbus_config(struct ahci_host_priv *hpriv,
const struct mbus_dram_target_info *dram)
{
int i;
for (i = 0; i < 4; i++) {
writel(0, hpriv->mmio + AHCI_WINDOW_CTRL(i));
writel(0, hpriv->mmio + AHCI_WINDOW_BASE(i));
writel(0, hpriv->mmio + AHCI_WINDOW_SIZE(i));
}
for (i = 0; i < dram->num_cs; i++) {
const struct mbus_dram_window *cs = dram->cs + i;
writel((cs->mbus_attr << 8) |
(dram->mbus_dram_target_id << 4) | 1,
hpriv->mmio + AHCI_WINDOW_CTRL(i));
writel(cs->base, hpriv->mmio + AHCI_WINDOW_BASE(i));
writel(((cs->size - 1) & 0xffff0000),
hpriv->mmio + AHCI_WINDOW_SIZE(i));
}
}
static void ahci_mvebu_regret_option(struct ahci_host_priv *hpriv)
{
writel(0x4, hpriv->mmio + AHCI_VENDOR_SPECIFIC_0_ADDR);
writel(0x80, hpriv->mmio + AHCI_VENDOR_SPECIFIC_0_DATA);
}
static int ahci_mvebu_probe(struct platform_device *pdev)
{
struct ahci_host_priv *hpriv;
const struct mbus_dram_target_info *dram;
int rc;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
dram = mv_mbus_dram_info();
if (!dram)
return -ENODEV;
ahci_mvebu_mbus_config(hpriv, dram);
ahci_mvebu_regret_option(hpriv);
rc = ahci_platform_init_host(pdev, hpriv, &ahci_mvebu_port_info,
0, 0, 0);
if (rc)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
