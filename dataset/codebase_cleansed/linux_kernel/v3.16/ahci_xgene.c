static int xgene_ahci_init_memram(struct xgene_ahci_context *ctx)
{
dev_dbg(ctx->dev, "Release memory from shutdown\n");
writel(0x0, ctx->csr_diag + CFG_MEM_RAM_SHUTDOWN);
readl(ctx->csr_diag + CFG_MEM_RAM_SHUTDOWN);
msleep(1);
if (readl(ctx->csr_diag + BLOCK_MEM_RDY) != 0xFFFFFFFF) {
dev_err(ctx->dev, "failed to release memory from shutdown\n");
return -ENODEV;
}
return 0;
}
static int xgene_ahci_restart_engine(struct ata_port *ap)
{
struct ahci_host_priv *hpriv = ap->host->private_data;
ahci_stop_engine(ap);
ahci_start_fis_rx(ap);
hpriv->start_engine(ap);
return 0;
}
static unsigned int xgene_ahci_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ahci_host_priv *hpriv = ap->host->private_data;
struct xgene_ahci_context *ctx = hpriv->plat_data;
int rc = 0;
if (unlikely(ctx->last_cmd[ap->port_no] == ATA_CMD_ID_ATA))
xgene_ahci_restart_engine(ap);
rc = ahci_qc_issue(qc);
ctx->last_cmd[ap->port_no] = qc->tf.command;
return rc;
}
static unsigned int xgene_ahci_read_id(struct ata_device *dev,
struct ata_taskfile *tf, u16 *id)
{
u32 err_mask;
err_mask = ata_do_dev_read_id(dev, tf, id);
if (err_mask)
return err_mask;
id[ATA_ID_FEATURE_SUPP] &= ~(1 << 8);
return 0;
}
static void xgene_ahci_set_phy_cfg(struct xgene_ahci_context *ctx, int channel)
{
void __iomem *mmio = ctx->hpriv->mmio;
u32 val;
dev_dbg(ctx->dev, "port configure mmio 0x%p channel %d\n",
mmio, channel);
val = readl(mmio + PORTCFG);
val = PORTADDR_SET(val, channel == 0 ? 2 : 3);
writel(val, mmio + PORTCFG);
readl(mmio + PORTCFG);
writel(0x0001fffe, mmio + PORTPHY1CFG);
readl(mmio + PORTPHY1CFG);
writel(0x5018461c, mmio + PORTPHY2CFG);
readl(mmio + PORTPHY2CFG);
writel(0x1c081907, mmio + PORTPHY3CFG);
readl(mmio + PORTPHY3CFG);
writel(0x1c080815, mmio + PORTPHY4CFG);
readl(mmio + PORTPHY4CFG);
val = readl(mmio + PORTPHY5CFG);
val = PORTPHY5CFG_RTCHG_SET(val, 0x300);
writel(val, mmio + PORTPHY5CFG);
readl(mmio + PORTPHY5CFG);
val = readl(mmio + PORTAXICFG);
val = PORTAXICFG_EN_CONTEXT_SET(val, 0x1);
val = PORTAXICFG_OUTTRANS_SET(val, 0xe);
writel(val, mmio + PORTAXICFG);
readl(mmio + PORTAXICFG);
}
static int xgene_ahci_do_hardreset(struct ata_link *link,
unsigned long deadline, bool *online)
{
const unsigned long *timing = sata_ehc_deb_timing(&link->eh_context);
struct ata_port *ap = link->ap;
struct ahci_host_priv *hpriv = ap->host->private_data;
struct xgene_ahci_context *ctx = hpriv->plat_data;
struct ahci_port_priv *pp = ap->private_data;
u8 *d2h_fis = pp->rx_fis + RX_FIS_D2H_REG;
void __iomem *port_mmio = ahci_port_base(ap);
struct ata_taskfile tf;
int rc;
u32 val;
ata_tf_init(link->device, &tf);
tf.command = ATA_BUSY;
ata_tf_to_fis(&tf, 0, 0, d2h_fis);
rc = sata_link_hardreset(link, timing, deadline, online,
ahci_check_ready);
val = readl(port_mmio + PORT_SCR_ERR);
if (val & (SERR_DISPARITY | SERR_10B_8B_ERR))
dev_warn(ctx->dev, "link has error\n");
val = readl(port_mmio + PORT_SCR_ERR);
writel(val, port_mmio + PORT_SCR_ERR);
return rc;
}
static int xgene_ahci_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct ahci_host_priv *hpriv = ap->host->private_data;
void __iomem *port_mmio = ahci_port_base(ap);
bool online;
int rc;
u32 portcmd_saved;
u32 portclb_saved;
u32 portclbhi_saved;
u32 portrxfis_saved;
u32 portrxfishi_saved;
portcmd_saved = readl(port_mmio + PORT_CMD);
portclb_saved = readl(port_mmio + PORT_LST_ADDR);
portclbhi_saved = readl(port_mmio + PORT_LST_ADDR_HI);
portrxfis_saved = readl(port_mmio + PORT_FIS_ADDR);
portrxfishi_saved = readl(port_mmio + PORT_FIS_ADDR_HI);
ahci_stop_engine(ap);
rc = xgene_ahci_do_hardreset(link, deadline, &online);
writel(portcmd_saved, port_mmio + PORT_CMD);
writel(portclb_saved, port_mmio + PORT_LST_ADDR);
writel(portclbhi_saved, port_mmio + PORT_LST_ADDR_HI);
writel(portrxfis_saved, port_mmio + PORT_FIS_ADDR);
writel(portrxfishi_saved, port_mmio + PORT_FIS_ADDR_HI);
hpriv->start_engine(ap);
if (online)
*class = ahci_dev_classify(ap);
return rc;
}
static void xgene_ahci_host_stop(struct ata_host *host)
{
struct ahci_host_priv *hpriv = host->private_data;
ahci_platform_disable_resources(hpriv);
}
static int xgene_ahci_hw_init(struct ahci_host_priv *hpriv)
{
struct xgene_ahci_context *ctx = hpriv->plat_data;
int i;
int rc;
u32 val;
rc = xgene_ahci_init_memram(ctx);
if (rc)
return rc;
for (i = 0; i < MAX_AHCI_CHN_PERCTR; i++)
xgene_ahci_set_phy_cfg(ctx, i);
writel(0xffffffff, hpriv->mmio + HOST_IRQ_STAT);
readl(hpriv->mmio + HOST_IRQ_STAT);
writel(0, ctx->csr_core + INTSTATUSMASK);
val = readl(ctx->csr_core + INTSTATUSMASK);
dev_dbg(ctx->dev, "top level interrupt mask 0x%X value 0x%08X\n",
INTSTATUSMASK, val);
writel(0x0, ctx->csr_core + ERRINTSTATUSMASK);
readl(ctx->csr_core + ERRINTSTATUSMASK);
writel(0x0, ctx->csr_axi + INT_SLV_TMOMASK);
readl(ctx->csr_axi + INT_SLV_TMOMASK);
writel(0xffffffff, ctx->csr_core + SLVRDERRATTRIBUTES);
writel(0xffffffff, ctx->csr_core + SLVWRERRATTRIBUTES);
writel(0xffffffff, ctx->csr_core + MSTRDERRATTRIBUTES);
writel(0xffffffff, ctx->csr_core + MSTWRERRATTRIBUTES);
val = readl(ctx->csr_core + BUSCTLREG);
val &= ~0x00000002;
val &= ~0x00000001;
writel(val, ctx->csr_core + BUSCTLREG);
val = readl(ctx->csr_core + IOFMSTRWAUX);
val |= (1 << 3);
val |= (1 << 9);
writel(val, ctx->csr_core + IOFMSTRWAUX);
val = readl(ctx->csr_core + IOFMSTRWAUX);
dev_dbg(ctx->dev, "coherency 0x%X value 0x%08X\n",
IOFMSTRWAUX, val);
return rc;
}
static int xgene_ahci_mux_select(struct xgene_ahci_context *ctx)
{
u32 val;
if (IS_ERR(ctx->csr_mux))
return 0;
val = readl(ctx->csr_mux + SATA_ENET_CONFIG_REG);
val &= ~CFG_SATA_ENET_SELECT_MASK;
writel(val, ctx->csr_mux + SATA_ENET_CONFIG_REG);
val = readl(ctx->csr_mux + SATA_ENET_CONFIG_REG);
return val & CFG_SATA_ENET_SELECT_MASK ? -1 : 0;
}
static int xgene_ahci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
struct xgene_ahci_context *ctx;
struct resource *res;
unsigned long hflags;
int rc;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
hpriv->plat_data = ctx;
ctx->hpriv = hpriv;
ctx->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
ctx->csr_core = devm_ioremap_resource(dev, res);
if (IS_ERR(ctx->csr_core))
return PTR_ERR(ctx->csr_core);
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
ctx->csr_diag = devm_ioremap_resource(dev, res);
if (IS_ERR(ctx->csr_diag))
return PTR_ERR(ctx->csr_diag);
res = platform_get_resource(pdev, IORESOURCE_MEM, 3);
ctx->csr_axi = devm_ioremap_resource(dev, res);
if (IS_ERR(ctx->csr_axi))
return PTR_ERR(ctx->csr_axi);
res = platform_get_resource(pdev, IORESOURCE_MEM, 4);
ctx->csr_mux = devm_ioremap_resource(dev, res);
dev_dbg(dev, "VAddr 0x%p Mmio VAddr 0x%p\n", ctx->csr_core,
hpriv->mmio);
if ((rc = xgene_ahci_mux_select(ctx))) {
dev_err(dev, "SATA mux selection failed error %d\n", rc);
return -ENODEV;
}
rc = ahci_platform_enable_clks(hpriv);
if (rc)
goto disable_resources;
ahci_platform_disable_clks(hpriv);
rc = ahci_platform_enable_resources(hpriv);
if (rc)
goto disable_resources;
xgene_ahci_hw_init(hpriv);
rc = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(64));
if (rc) {
dev_err(dev, "Unable to set dma mask\n");
goto disable_resources;
}
hflags = AHCI_HFLAG_NO_PMP | AHCI_HFLAG_YES_NCQ;
rc = ahci_platform_init_host(pdev, hpriv, &xgene_ahci_port_info,
hflags, 0, 0);
if (rc)
goto disable_resources;
dev_dbg(dev, "X-Gene SATA host controller initialized\n");
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
