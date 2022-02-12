static void ahci_ceva_setup(struct ahci_host_priv *hpriv)
{
void __iomem *mmio = hpriv->mmio;
struct ceva_ahci_priv *cevapriv = hpriv->plat_data;
u32 tmp;
int i;
tmp = PAXIC_ADBW_BW64 | PAXIC_MAWIDD | PAXIC_MARIDD | PAXIC_OTL;
writel(tmp, mmio + AHCI_VEND_PAXIC);
tmp = readl(mmio + HOST_CTL);
tmp |= HOST_AHCI_EN;
writel(tmp, mmio + HOST_CTL);
for (i = 0; i < NR_PORTS; i++) {
tmp = PCFG_TPSS_VAL | PCFG_TPRS_VAL | (PCFG_PAD_VAL + i);
writel(tmp, mmio + AHCI_VEND_PCFG);
tmp = PPCFG_TTA | PPCFG_PSS_EN | PPCFG_ESDF_EN;
writel(tmp, mmio + AHCI_VEND_PPCFG);
tmp = PP2C_CIBGMN | PP2C_CIBGMX | PP2C_CIBGN | PP2C_CINMP;
writel(tmp, mmio + AHCI_VEND_PP2C);
tmp = PP3C_CWBGMN | PP3C_CWBGMX | PP3C_CWBGN | PP3C_CWNMP;
writel(tmp, mmio + AHCI_VEND_PP3C);
tmp = PP4C_BMX | PP4C_BNM | PP4C_SFD | PP4C_PTST;
writel(tmp, mmio + AHCI_VEND_PP4C);
tmp = PP5C_RIT | PP5C_RCT;
writel(tmp, mmio + AHCI_VEND_PP5C);
tmp = PTC_RX_WM_VAL | PTC_RSVD;
writel(tmp, mmio + AHCI_VEND_PTC);
tmp = PORT_SCTL_SPD_GEN2 | PORT_SCTL_IPM;
if (cevapriv->flags & CEVA_FLAG_BROKEN_GEN2)
tmp = PORT_SCTL_SPD_GEN1 | PORT_SCTL_IPM;
writel(tmp, mmio + PORT_SCR_CTL + PORT_BASE + PORT_OFFSET * i);
}
}
static int ceva_ahci_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
struct ceva_ahci_priv *cevapriv;
int rc;
cevapriv = devm_kzalloc(dev, sizeof(*cevapriv), GFP_KERNEL);
if (!cevapriv)
return -ENOMEM;
cevapriv->ahci_pdev = pdev;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
if (of_property_read_bool(np, "ceva,broken-gen2"))
cevapriv->flags = CEVA_FLAG_BROKEN_GEN2;
hpriv->plat_data = cevapriv;
ahci_ceva_setup(hpriv);
rc = ahci_platform_init_host(pdev, hpriv, &ahci_ceva_port_info,
&ahci_platform_sht);
if (rc)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
static int __maybe_unused ceva_ahci_suspend(struct device *dev)
{
return ahci_platform_suspend_host(dev);
}
static int __maybe_unused ceva_ahci_resume(struct device *dev)
{
return ahci_platform_resume_host(dev);
}
