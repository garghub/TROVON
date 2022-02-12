static int ahci_qoriq_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
const unsigned long *timing = sata_ehc_deb_timing(&link->eh_context);
void __iomem *port_mmio = ahci_port_base(link->ap);
u32 px_cmd, px_is, px_val;
struct ata_port *ap = link->ap;
struct ahci_port_priv *pp = ap->private_data;
struct ahci_host_priv *hpriv = ap->host->private_data;
struct ahci_qoriq_priv *qoriq_priv = hpriv->plat_data;
u8 *d2h_fis = pp->rx_fis + RX_FIS_D2H_REG;
struct ata_taskfile tf;
bool online;
int rc;
bool ls1021a_workaround = (qoriq_priv->type == AHCI_LS1021A);
DPRINTK("ENTER\n");
ahci_stop_engine(ap);
if (ls1021a_workaround) {
px_cmd = readl(port_mmio + PORT_CMD);
px_is = readl(port_mmio + PORT_IRQ_STAT);
}
ata_tf_init(link->device, &tf);
tf.command = ATA_BUSY;
ata_tf_to_fis(&tf, 0, 0, d2h_fis);
rc = sata_link_hardreset(link, timing, deadline, &online,
ahci_check_ready);
if (ls1021a_workaround) {
px_val = readl(port_mmio + PORT_CMD);
if (px_val != px_cmd)
writel(px_cmd, port_mmio + PORT_CMD);
px_val = readl(port_mmio + PORT_IRQ_STAT);
if (px_val != px_is)
writel(px_is, port_mmio + PORT_IRQ_STAT);
}
hpriv->start_engine(ap);
if (online)
*class = ahci_dev_classify(ap);
DPRINTK("EXIT, rc=%d, class=%u\n", rc, *class);
return rc;
}
static int ahci_qoriq_phy_init(struct ahci_host_priv *hpriv)
{
struct ahci_qoriq_priv *qpriv = hpriv->plat_data;
void __iomem *reg_base = hpriv->mmio;
switch (qpriv->type) {
case AHCI_LS1021A:
writel(SATA_ECC_DISABLE, qpriv->ecc_addr);
writel(AHCI_PORT_PHY_1_CFG, reg_base + PORT_PHY1);
writel(LS1021A_PORT_PHY2, reg_base + PORT_PHY2);
writel(LS1021A_PORT_PHY3, reg_base + PORT_PHY3);
writel(LS1021A_PORT_PHY4, reg_base + PORT_PHY4);
writel(LS1021A_PORT_PHY5, reg_base + PORT_PHY5);
writel(AHCI_PORT_TRANS_CFG, reg_base + PORT_TRANS);
writel(AHCI_PORT_AXICC_CFG, reg_base + LS1021A_AXICC_ADDR);
break;
case AHCI_LS1043A:
writel(AHCI_PORT_PHY_1_CFG, reg_base + PORT_PHY1);
writel(AHCI_PORT_TRANS_CFG, reg_base + PORT_TRANS);
writel(AHCI_PORT_AXICC_CFG, reg_base + PORT_AXICC);
break;
case AHCI_LS2080A:
writel(AHCI_PORT_PHY_1_CFG, reg_base + PORT_PHY1);
writel(AHCI_PORT_TRANS_CFG, reg_base + PORT_TRANS);
writel(AHCI_PORT_AXICC_CFG, reg_base + PORT_AXICC);
break;
}
return 0;
}
static int ahci_qoriq_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
struct ahci_qoriq_priv *qoriq_priv;
const struct of_device_id *of_id;
struct resource *res;
int rc;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
of_id = of_match_node(ahci_qoriq_of_match, np);
if (!of_id)
return -ENODEV;
qoriq_priv = devm_kzalloc(dev, sizeof(*qoriq_priv), GFP_KERNEL);
if (!qoriq_priv)
return -ENOMEM;
qoriq_priv->type = (enum ahci_qoriq_type)of_id->data;
if (qoriq_priv->type == AHCI_LS1021A) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"sata-ecc");
qoriq_priv->ecc_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(qoriq_priv->ecc_addr))
return PTR_ERR(qoriq_priv->ecc_addr);
}
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
hpriv->plat_data = qoriq_priv;
rc = ahci_qoriq_phy_init(hpriv);
if (rc)
goto disable_resources;
rc = ahci_platform_init_host(pdev, hpriv, &ahci_qoriq_port_info,
&ahci_qoriq_sht);
if (rc)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
static int ahci_qoriq_resume(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
int rc;
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
rc = ahci_qoriq_phy_init(hpriv);
if (rc)
goto disable_resources;
rc = ahci_platform_resume_host(dev);
if (rc)
goto disable_resources;
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
