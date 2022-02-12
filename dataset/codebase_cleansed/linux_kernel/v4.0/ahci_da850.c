static void da850_sata_init(struct device *dev, void __iomem *pwrdn_reg,
void __iomem *ahci_base)
{
unsigned int val;
val = readl(pwrdn_reg);
val &= ~BIT(0);
writel(val, pwrdn_reg);
val = SATA_PHY_MPY(DA850_SATA_CLK_MULTIPLIER + 1) | SATA_PHY_LOS(1) |
SATA_PHY_RXCDR(4) | SATA_PHY_RXEQ(1) | SATA_PHY_TXSWING(3) |
SATA_PHY_ENPLL(1);
writel(val, ahci_base + SATA_P0PHYCR_REG);
}
static int ahci_da850_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
struct resource *res;
void __iomem *pwrdn_reg;
int rc;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res)
goto disable_resources;
pwrdn_reg = devm_ioremap(dev, res->start, resource_size(res));
if (!pwrdn_reg)
goto disable_resources;
da850_sata_init(dev, pwrdn_reg, hpriv->mmio);
rc = ahci_platform_init_host(pdev, hpriv, &ahci_da850_port_info,
&ahci_platform_sht);
if (rc)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
