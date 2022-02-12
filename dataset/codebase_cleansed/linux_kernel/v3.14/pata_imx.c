static int pata_imx_set_mode(struct ata_link *link, struct ata_device **unused)
{
struct ata_device *dev;
struct ata_port *ap = link->ap;
struct pata_imx_priv *priv = ap->host->private_data;
u32 val;
ata_for_each_dev(dev, link, ENABLED) {
dev->pio_mode = dev->xfer_mode = XFER_PIO_0;
dev->xfer_shift = ATA_SHIFT_PIO;
dev->flags |= ATA_DFLAG_PIO;
val = __raw_readl(priv->host_regs + PATA_IMX_ATA_CONTROL);
if (ata_pio_need_iordy(dev))
val |= PATA_IMX_ATA_CTRL_IORDY_EN;
else
val &= ~PATA_IMX_ATA_CTRL_IORDY_EN;
__raw_writel(val, priv->host_regs + PATA_IMX_ATA_CONTROL);
ata_dev_info(dev, "configured for PIO\n");
}
return 0;
}
static void pata_imx_setup_port(struct ata_ioports *ioaddr)
{
ioaddr->data_addr = ioaddr->cmd_addr + (ATA_REG_DATA << 2);
ioaddr->error_addr = ioaddr->cmd_addr + (ATA_REG_ERR << 2);
ioaddr->feature_addr = ioaddr->cmd_addr + (ATA_REG_FEATURE << 2);
ioaddr->nsect_addr = ioaddr->cmd_addr + (ATA_REG_NSECT << 2);
ioaddr->lbal_addr = ioaddr->cmd_addr + (ATA_REG_LBAL << 2);
ioaddr->lbam_addr = ioaddr->cmd_addr + (ATA_REG_LBAM << 2);
ioaddr->lbah_addr = ioaddr->cmd_addr + (ATA_REG_LBAH << 2);
ioaddr->device_addr = ioaddr->cmd_addr + (ATA_REG_DEVICE << 2);
ioaddr->status_addr = ioaddr->cmd_addr + (ATA_REG_STATUS << 2);
ioaddr->command_addr = ioaddr->cmd_addr + (ATA_REG_CMD << 2);
}
static int pata_imx_probe(struct platform_device *pdev)
{
struct ata_host *host;
struct ata_port *ap;
struct pata_imx_priv *priv;
int irq = 0;
struct resource *io_res;
int ret;
io_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (io_res == NULL)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev,
sizeof(struct pata_imx_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(&pdev->dev, "Failed to get clock\n");
return PTR_ERR(priv->clk);
}
ret = clk_prepare_enable(priv->clk);
if (ret)
return ret;
host = ata_host_alloc(&pdev->dev, 1);
if (!host) {
ret = -ENOMEM;
goto err;
}
host->private_data = priv;
ap = host->ports[0];
ap->ops = &pata_imx_port_ops;
ap->pio_mask = ATA_PIO0;
ap->flags |= ATA_FLAG_SLAVE_POSS;
priv->host_regs = devm_ioremap(&pdev->dev, io_res->start,
resource_size(io_res));
if (!priv->host_regs) {
dev_err(&pdev->dev, "failed to map IO/CTL base\n");
ret = -EBUSY;
goto err;
}
ap->ioaddr.cmd_addr = priv->host_regs + PATA_IMX_DRIVE_DATA;
ap->ioaddr.ctl_addr = priv->host_regs + PATA_IMX_DRIVE_CONTROL;
ap->ioaddr.altstatus_addr = ap->ioaddr.ctl_addr;
pata_imx_setup_port(&ap->ioaddr);
ata_port_desc(ap, "cmd 0x%llx ctl 0x%llx",
(unsigned long long)io_res->start + PATA_IMX_DRIVE_DATA,
(unsigned long long)io_res->start + PATA_IMX_DRIVE_CONTROL);
__raw_writel(PATA_IMX_ATA_CTRL_FIFO_RST_B |
PATA_IMX_ATA_CTRL_ATA_RST_B,
priv->host_regs + PATA_IMX_ATA_CONTROL);
__raw_writel(PATA_IMX_ATA_INTR_ATA_INTRQ2,
priv->host_regs + PATA_IMX_ATA_INT_EN);
ret = ata_host_activate(host, irq, ata_sff_interrupt, 0,
&pata_imx_sht);
if (ret)
goto err;
return 0;
err:
clk_disable_unprepare(priv->clk);
return ret;
}
static int pata_imx_remove(struct platform_device *pdev)
{
struct ata_host *host = platform_get_drvdata(pdev);
struct pata_imx_priv *priv = host->private_data;
ata_host_detach(host);
__raw_writel(0, priv->host_regs + PATA_IMX_ATA_INT_EN);
clk_disable_unprepare(priv->clk);
return 0;
}
static int pata_imx_suspend(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct pata_imx_priv *priv = host->private_data;
int ret;
ret = ata_host_suspend(host, PMSG_SUSPEND);
if (!ret) {
__raw_writel(0, priv->host_regs + PATA_IMX_ATA_INT_EN);
priv->ata_ctl =
__raw_readl(priv->host_regs + PATA_IMX_ATA_CONTROL);
clk_disable_unprepare(priv->clk);
}
return ret;
}
static int pata_imx_resume(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct pata_imx_priv *priv = host->private_data;
int ret = clk_prepare_enable(priv->clk);
if (ret)
return ret;
__raw_writel(priv->ata_ctl, priv->host_regs + PATA_IMX_ATA_CONTROL);
__raw_writel(PATA_IMX_ATA_INTR_ATA_INTRQ2,
priv->host_regs + PATA_IMX_ATA_INT_EN);
ata_host_resume(host);
return 0;
}
