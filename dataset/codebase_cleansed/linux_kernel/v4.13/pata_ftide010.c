static void ftide010_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
struct ftide010 *ftide = ap->host->private_data;
u8 speed = adev->dma_mode;
u8 devno = adev->devno & 1;
u8 udma_en_mask;
u8 f66m_en_mask;
u8 clkreg;
u8 timreg;
u8 i;
if (!devno) {
udma_en_mask = FTIDE010_CLK_MOD_DEV0_UDMA_EN;
f66m_en_mask = FTIDE010_CLK_MOD_DEV0_CLK_SEL;
} else {
udma_en_mask = FTIDE010_CLK_MOD_DEV1_UDMA_EN;
f66m_en_mask = FTIDE010_CLK_MOD_DEV1_CLK_SEL;
}
clkreg = readb(ftide->base + FTIDE010_CLK_MOD);
clkreg &= ~udma_en_mask;
clkreg &= ~f66m_en_mask;
if (speed & XFER_UDMA_0) {
i = speed & ~XFER_UDMA_0;
dev_dbg(ftide->dev, "set UDMA mode %02x, index %d\n",
speed, i);
clkreg |= udma_en_mask;
if (set_udma_66_mhz[i]) {
clkreg |= f66m_en_mask;
timreg = udma_66_setup_time[i] << 4 |
udma_66_hold_time[i];
} else {
timreg = udma_50_setup_time[i] << 4 |
udma_50_hold_time[i];
}
if (i >= 5)
timreg |= FTIDE010_UDMA_TIMING_MODE_56;
dev_dbg(ftide->dev, "UDMA write clkreg = %02x, timreg = %02x\n",
clkreg, timreg);
writeb(clkreg, ftide->base + FTIDE010_CLK_MOD);
writeb(timreg, ftide->base + FTIDE010_UDMA_TIMING0 + devno);
} else {
i = speed & ~XFER_MW_DMA_0;
dev_dbg(ftide->dev, "set MWDMA mode %02x, index %d\n",
speed, i);
if (set_mdma_66_mhz[i]) {
clkreg |= f66m_en_mask;
timreg = mwdma_66_active_time[i] << 4 |
mwdma_66_recovery_time[i];
} else {
timreg = mwdma_50_active_time[i] << 4 |
mwdma_50_recovery_time[i];
}
dev_dbg(ftide->dev,
"MWDMA write clkreg = %02x, timreg = %02x\n",
clkreg, timreg);
writeb(clkreg, ftide->base + FTIDE010_CLK_MOD);
writeb(timreg, ftide->base + FTIDE010_MWDMA_TIMING);
}
ap->private_data = adev;
return;
}
static void ftide010_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct ftide010 *ftide = ap->host->private_data;
u8 pio = adev->pio_mode - XFER_PIO_0;
dev_dbg(ftide->dev, "set PIO mode %02x, index %d\n",
adev->pio_mode, pio);
writeb(pio_active_time[pio] << 4 | pio_recovery_time[pio],
ftide->base + FTIDE010_PIO_TIMING);
}
static unsigned int ftide010_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_device *adev = qc->dev;
if (adev != ap->private_data && ata_dma_enabled(adev))
ftide010_set_dmamode(ap, adev);
return ata_bmdma_qc_issue(qc);
}
static int pata_ftide010_gemini_port_start(struct ata_port *ap)
{
struct ftide010 *ftide = ap->host->private_data;
struct device *dev = ftide->dev;
struct sata_gemini *sg = ftide->sg;
int bridges = 0;
int ret;
ret = ata_bmdma_port_start(ap);
if (ret)
return ret;
if (ftide->master_to_sata0) {
dev_info(dev, "SATA0 (master) start\n");
ret = gemini_sata_start_bridge(sg, 0);
if (!ret)
bridges++;
}
if (ftide->master_to_sata1) {
dev_info(dev, "SATA1 (master) start\n");
ret = gemini_sata_start_bridge(sg, 1);
if (!ret)
bridges++;
}
if (ftide->slave_to_sata0 && !ftide->master_to_sata0) {
dev_info(dev, "SATA0 (slave) start\n");
ret = gemini_sata_start_bridge(sg, 0);
if (!ret)
bridges++;
}
if (ftide->slave_to_sata1 && !ftide->master_to_sata1) {
dev_info(dev, "SATA1 (slave) start\n");
ret = gemini_sata_start_bridge(sg, 1);
if (!ret)
bridges++;
}
dev_info(dev, "brought %d bridges online\n", bridges);
return (bridges > 0) ? 0 : -EINVAL;
}
static void pata_ftide010_gemini_port_stop(struct ata_port *ap)
{
struct ftide010 *ftide = ap->host->private_data;
struct device *dev = ftide->dev;
struct sata_gemini *sg = ftide->sg;
if (ftide->master_to_sata0) {
dev_info(dev, "SATA0 (master) stop\n");
gemini_sata_stop_bridge(sg, 0);
}
if (ftide->master_to_sata1) {
dev_info(dev, "SATA1 (master) stop\n");
gemini_sata_stop_bridge(sg, 1);
}
if (ftide->slave_to_sata0 && !ftide->master_to_sata0) {
dev_info(dev, "SATA0 (slave) stop\n");
gemini_sata_stop_bridge(sg, 0);
}
if (ftide->slave_to_sata1 && !ftide->master_to_sata1) {
dev_info(dev, "SATA1 (slave) stop\n");
gemini_sata_stop_bridge(sg, 1);
}
}
static int pata_ftide010_gemini_cable_detect(struct ata_port *ap)
{
struct ftide010 *ftide = ap->host->private_data;
return ftide->master_cbl;
}
static int pata_ftide010_gemini_init(struct ftide010 *ftide,
bool is_ata1)
{
struct device *dev = ftide->dev;
struct sata_gemini *sg;
enum gemini_muxmode muxmode;
sg = gemini_sata_bridge_get();
if (IS_ERR(sg))
return PTR_ERR(sg);
ftide->sg = sg;
muxmode = gemini_sata_get_muxmode(sg);
pata_ftide010_port_ops.port_start =
pata_ftide010_gemini_port_start;
pata_ftide010_port_ops.port_stop =
pata_ftide010_gemini_port_stop;
pata_ftide010_port_ops.cable_detect =
pata_ftide010_gemini_cable_detect;
if (gemini_sata_bridge_enabled(sg, is_ata1))
ftide010_port_info[0].flags |= ATA_FLAG_SATA;
if (!is_ata1) {
switch (muxmode) {
case GEMINI_MUXMODE_0:
ftide->master_cbl = ATA_CBL_SATA;
ftide->slave_cbl = ATA_CBL_PATA40;
ftide->master_to_sata0 = true;
break;
case GEMINI_MUXMODE_1:
ftide->master_cbl = ATA_CBL_SATA;
ftide->slave_cbl = ATA_CBL_NONE;
ftide->master_to_sata0 = true;
break;
case GEMINI_MUXMODE_2:
ftide->master_cbl = ATA_CBL_PATA40;
ftide->slave_cbl = ATA_CBL_PATA40;
break;
case GEMINI_MUXMODE_3:
ftide->master_cbl = ATA_CBL_SATA;
ftide->slave_cbl = ATA_CBL_SATA;
ftide->master_to_sata0 = true;
ftide->slave_to_sata1 = true;
break;
}
} else {
switch (muxmode) {
case GEMINI_MUXMODE_0:
ftide->master_cbl = ATA_CBL_SATA;
ftide->slave_cbl = ATA_CBL_NONE;
ftide->master_to_sata1 = true;
break;
case GEMINI_MUXMODE_1:
ftide->master_cbl = ATA_CBL_SATA;
ftide->slave_cbl = ATA_CBL_PATA40;
ftide->master_to_sata1 = true;
break;
case GEMINI_MUXMODE_2:
ftide->master_cbl = ATA_CBL_SATA;
ftide->slave_cbl = ATA_CBL_SATA;
ftide->slave_to_sata0 = true;
ftide->master_to_sata1 = true;
break;
case GEMINI_MUXMODE_3:
ftide->master_cbl = ATA_CBL_PATA40;
ftide->slave_cbl = ATA_CBL_PATA40;
break;
}
}
dev_info(dev, "set up Gemini PATA%d\n", is_ata1);
return 0;
}
static int pata_ftide010_gemini_init(struct ftide010 *ftide,
bool is_ata1)
{
return -ENOTSUPP;
}
static int pata_ftide010_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
const struct ata_port_info pi = ftide010_port_info[0];
const struct ata_port_info *ppi[] = { &pi, NULL };
struct ftide010 *ftide;
struct resource *res;
int irq;
int ret;
int i;
ftide = devm_kzalloc(dev, sizeof(*ftide), GFP_KERNEL);
if (!ftide)
return -ENOMEM;
ftide->dev = dev;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
ftide->base = devm_ioremap_resource(dev, res);
if (IS_ERR(ftide->base))
return PTR_ERR(ftide->base);
ftide->pclk = devm_clk_get(dev, "PCLK");
if (!IS_ERR(ftide->pclk)) {
ret = clk_prepare_enable(ftide->pclk);
if (ret) {
dev_err(dev, "failed to enable PCLK\n");
return ret;
}
}
if (of_device_is_compatible(np, "cortina,gemini-pata")) {
ret = pata_ftide010_gemini_init(ftide,
(res->start == 0x63400000));
if (ret)
goto err_dis_clk;
} else {
ftide->master_cbl = ATA_CBL_PATA40;
ftide->slave_cbl = ATA_CBL_PATA40;
}
ftide->host = ata_host_alloc_pinfo(dev, ppi, 1);
if (!ftide->host) {
ret = -ENOMEM;
goto err_dis_clk;
}
ftide->host->private_data = ftide;
for (i = 0; i < ftide->host->n_ports; i++) {
struct ata_port *ap = ftide->host->ports[i];
struct ata_ioports *ioaddr = &ap->ioaddr;
ioaddr->bmdma_addr = ftide->base + FTIDE010_DMA_REG;
ioaddr->cmd_addr = ftide->base + FTIDE010_CMD_DATA;
ioaddr->ctl_addr = ftide->base + FTIDE010_ALTSTAT_CTRL;
ioaddr->altstatus_addr = ftide->base + FTIDE010_ALTSTAT_CTRL;
ata_sff_std_ports(ioaddr);
}
dev_info(dev, "device ID %08x, irq %d, reg %pR\n",
readl(ftide->base + FTIDE010_IDE_DEVICE_ID), irq, res);
ret = ata_host_activate(ftide->host, irq, ata_bmdma_interrupt,
0, &pata_ftide010_sht);
if (ret)
goto err_dis_clk;
return 0;
err_dis_clk:
if (!IS_ERR(ftide->pclk))
clk_disable_unprepare(ftide->pclk);
return ret;
}
static int pata_ftide010_remove(struct platform_device *pdev)
{
struct ata_host *host = platform_get_drvdata(pdev);
struct ftide010 *ftide = host->private_data;
ata_host_detach(ftide->host);
if (!IS_ERR(ftide->pclk))
clk_disable_unprepare(ftide->pclk);
return 0;
}
