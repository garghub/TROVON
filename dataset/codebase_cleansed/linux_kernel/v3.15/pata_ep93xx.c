static void ep93xx_pata_clear_regs(void __iomem *base)
{
writel(IDECTRL_CS0N | IDECTRL_CS1N | IDECTRL_DIORN |
IDECTRL_DIOWN, base + IDECTRL);
writel(0, base + IDECFG);
writel(0, base + IDEMDMAOP);
writel(0, base + IDEUDMAOP);
writel(0, base + IDEDATAOUT);
writel(0, base + IDEDATAIN);
writel(0, base + IDEMDMADATAOUT);
writel(0, base + IDEMDMADATAIN);
writel(0, base + IDEUDMADATAOUT);
writel(0, base + IDEUDMADATAIN);
writel(0, base + IDEUDMADEBUG);
}
static bool ep93xx_pata_check_iordy(void __iomem *base)
{
return !!(readl(base + IDECTRL) & IDECTRL_IORDY);
}
static int ep93xx_pata_get_wst(int pio_mode)
{
int val;
if (pio_mode == 0)
val = 3;
else if (pio_mode < 3)
val = 2;
else
val = 1;
return val << IDECFG_WST_SHIFT;
}
static void ep93xx_pata_enable_pio(void __iomem *base, int pio_mode)
{
writel(IDECFG_IDEEN | IDECFG_PIO |
ep93xx_pata_get_wst(pio_mode) |
(pio_mode << IDECFG_MODE_SHIFT), base + IDECFG);
}
static void ep93xx_pata_delay(unsigned long count)
{
__asm__ volatile (
"0:\n"
"mov r0, r0\n"
"subs %0, %1, #1\n"
"bge 0b\n"
: "=r" (count)
: "0" (count)
);
}
static unsigned long ep93xx_pata_wait_for_iordy(void __iomem *base,
unsigned long t2)
{
unsigned long start = (1250 + 35) / 25 - t2;
unsigned long counter = start;
while (!ep93xx_pata_check_iordy(base) && counter--)
ep93xx_pata_delay(1);
return start - counter;
}
static void ep93xx_pata_rw_begin(void __iomem *base, unsigned long addr,
unsigned long t1)
{
writel(IDECTRL_DIOWN | IDECTRL_DIORN | addr, base + IDECTRL);
ep93xx_pata_delay(t1);
}
static void ep93xx_pata_rw_end(void __iomem *base, unsigned long addr,
bool iordy, unsigned long t0, unsigned long t2,
unsigned long t2i)
{
ep93xx_pata_delay(t2);
if (iordy)
t2 += ep93xx_pata_wait_for_iordy(base, t2);
writel(IDECTRL_DIOWN | IDECTRL_DIORN | addr, base + IDECTRL);
if (t0 > t2 && t0 - t2 > t2i)
ep93xx_pata_delay(t0 - t2);
else
ep93xx_pata_delay(t2i);
}
static u16 ep93xx_pata_read(struct ep93xx_pata_data *drv_data,
unsigned long addr,
bool reg)
{
void __iomem *base = drv_data->ide_base;
const struct ata_timing *t = &drv_data->t;
unsigned long t0 = reg ? t->cyc8b : t->cycle;
unsigned long t2 = reg ? t->act8b : t->active;
unsigned long t2i = reg ? t->rec8b : t->recover;
ep93xx_pata_rw_begin(base, addr, t->setup);
writel(IDECTRL_DIOWN | addr, base + IDECTRL);
ep93xx_pata_rw_end(base, addr, drv_data->iordy, t0, t2, t2i);
return readl(base + IDEDATAIN);
}
static u16 ep93xx_pata_read_reg(struct ep93xx_pata_data *drv_data,
unsigned long addr)
{
return ep93xx_pata_read(drv_data, addr, true);
}
static u16 ep93xx_pata_read_data(struct ep93xx_pata_data *drv_data,
unsigned long addr)
{
return ep93xx_pata_read(drv_data, addr, false);
}
static void ep93xx_pata_write(struct ep93xx_pata_data *drv_data,
u16 value, unsigned long addr,
bool reg)
{
void __iomem *base = drv_data->ide_base;
const struct ata_timing *t = &drv_data->t;
unsigned long t0 = reg ? t->cyc8b : t->cycle;
unsigned long t2 = reg ? t->act8b : t->active;
unsigned long t2i = reg ? t->rec8b : t->recover;
ep93xx_pata_rw_begin(base, addr, t->setup);
writel(value, base + IDEDATAOUT);
writel(IDECTRL_DIORN | addr, base + IDECTRL);
ep93xx_pata_rw_end(base, addr, drv_data->iordy, t0, t2, t2i);
}
static void ep93xx_pata_write_reg(struct ep93xx_pata_data *drv_data,
u16 value, unsigned long addr)
{
ep93xx_pata_write(drv_data, value, addr, true);
}
static void ep93xx_pata_write_data(struct ep93xx_pata_data *drv_data,
u16 value, unsigned long addr)
{
ep93xx_pata_write(drv_data, value, addr, false);
}
static void ep93xx_pata_set_piomode(struct ata_port *ap,
struct ata_device *adev)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
struct ata_device *pair = ata_dev_pair(adev);
unsigned long T = 1000000 / (200 / 5);
ata_timing_compute(adev, adev->pio_mode, &drv_data->t, T, 0);
if (pair && pair->pio_mode) {
struct ata_timing t;
ata_timing_compute(pair, pair->pio_mode, &t, T, 0);
ata_timing_merge(&t, &drv_data->t, &drv_data->t,
ATA_TIMING_SETUP | ATA_TIMING_8BIT);
}
drv_data->iordy = ata_pio_need_iordy(adev);
ep93xx_pata_enable_pio(drv_data->ide_base,
adev->pio_mode - XFER_PIO_0);
}
static u8 ep93xx_pata_check_status(struct ata_port *ap)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
return ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_STATUS);
}
static u8 ep93xx_pata_check_altstatus(struct ata_port *ap)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
return ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_ALTSTATUS);
}
static void ep93xx_pata_tf_load(struct ata_port *ap,
const struct ata_taskfile *tf)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
unsigned int is_addr = tf->flags & ATA_TFLAG_ISADDR;
if (tf->ctl != ap->last_ctl) {
ep93xx_pata_write_reg(drv_data, tf->ctl, IDECTRL_ADDR_CTL);
ap->last_ctl = tf->ctl;
ata_wait_idle(ap);
}
if (is_addr && (tf->flags & ATA_TFLAG_LBA48)) {
ep93xx_pata_write_reg(drv_data, tf->hob_feature,
IDECTRL_ADDR_FEATURE);
ep93xx_pata_write_reg(drv_data, tf->hob_nsect,
IDECTRL_ADDR_NSECT);
ep93xx_pata_write_reg(drv_data, tf->hob_lbal,
IDECTRL_ADDR_LBAL);
ep93xx_pata_write_reg(drv_data, tf->hob_lbam,
IDECTRL_ADDR_LBAM);
ep93xx_pata_write_reg(drv_data, tf->hob_lbah,
IDECTRL_ADDR_LBAH);
}
if (is_addr) {
ep93xx_pata_write_reg(drv_data, tf->feature,
IDECTRL_ADDR_FEATURE);
ep93xx_pata_write_reg(drv_data, tf->nsect, IDECTRL_ADDR_NSECT);
ep93xx_pata_write_reg(drv_data, tf->lbal, IDECTRL_ADDR_LBAL);
ep93xx_pata_write_reg(drv_data, tf->lbam, IDECTRL_ADDR_LBAM);
ep93xx_pata_write_reg(drv_data, tf->lbah, IDECTRL_ADDR_LBAH);
}
if (tf->flags & ATA_TFLAG_DEVICE)
ep93xx_pata_write_reg(drv_data, tf->device,
IDECTRL_ADDR_DEVICE);
ata_wait_idle(ap);
}
static void ep93xx_pata_tf_read(struct ata_port *ap, struct ata_taskfile *tf)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
tf->command = ep93xx_pata_check_status(ap);
tf->feature = ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_FEATURE);
tf->nsect = ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_NSECT);
tf->lbal = ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_LBAL);
tf->lbam = ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_LBAM);
tf->lbah = ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_LBAH);
tf->device = ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_DEVICE);
if (tf->flags & ATA_TFLAG_LBA48) {
ep93xx_pata_write_reg(drv_data, tf->ctl | ATA_HOB,
IDECTRL_ADDR_CTL);
tf->hob_feature = ep93xx_pata_read_reg(drv_data,
IDECTRL_ADDR_FEATURE);
tf->hob_nsect = ep93xx_pata_read_reg(drv_data,
IDECTRL_ADDR_NSECT);
tf->hob_lbal = ep93xx_pata_read_reg(drv_data,
IDECTRL_ADDR_LBAL);
tf->hob_lbam = ep93xx_pata_read_reg(drv_data,
IDECTRL_ADDR_LBAM);
tf->hob_lbah = ep93xx_pata_read_reg(drv_data,
IDECTRL_ADDR_LBAH);
ep93xx_pata_write_reg(drv_data, tf->ctl, IDECTRL_ADDR_CTL);
ap->last_ctl = tf->ctl;
}
}
static void ep93xx_pata_exec_command(struct ata_port *ap,
const struct ata_taskfile *tf)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
ep93xx_pata_write_reg(drv_data, tf->command,
IDECTRL_ADDR_COMMAND);
ata_sff_pause(ap);
}
static void ep93xx_pata_dev_select(struct ata_port *ap, unsigned int device)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
u8 tmp = ATA_DEVICE_OBS;
if (device != 0)
tmp |= ATA_DEV1;
ep93xx_pata_write_reg(drv_data, tmp, IDECTRL_ADDR_DEVICE);
ata_sff_pause(ap);
}
static void ep93xx_pata_set_devctl(struct ata_port *ap, u8 ctl)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
ep93xx_pata_write_reg(drv_data, ctl, IDECTRL_ADDR_CTL);
}
static unsigned int ep93xx_pata_data_xfer(struct ata_device *adev,
unsigned char *buf,
unsigned int buflen, int rw)
{
struct ata_port *ap = adev->link->ap;
struct ep93xx_pata_data *drv_data = ap->host->private_data;
u16 *data = (u16 *)buf;
unsigned int words = buflen >> 1;
while (words--)
if (rw == READ)
*data++ = cpu_to_le16(
ep93xx_pata_read_data(
drv_data, IDECTRL_ADDR_DATA));
else
ep93xx_pata_write_data(drv_data, le16_to_cpu(*data++),
IDECTRL_ADDR_DATA);
if (unlikely(buflen & 0x01)) {
unsigned char pad[2] = { };
buf += buflen - 1;
if (rw == READ) {
*pad = cpu_to_le16(
ep93xx_pata_read_data(
drv_data, IDECTRL_ADDR_DATA));
*buf = pad[0];
} else {
pad[0] = *buf;
ep93xx_pata_write_data(drv_data, le16_to_cpu(*pad),
IDECTRL_ADDR_DATA);
}
words++;
}
return words << 1;
}
static bool ep93xx_pata_device_is_present(struct ata_port *ap,
unsigned int device)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
u8 nsect, lbal;
ap->ops->sff_dev_select(ap, device);
ep93xx_pata_write_reg(drv_data, 0x55, IDECTRL_ADDR_NSECT);
ep93xx_pata_write_reg(drv_data, 0xaa, IDECTRL_ADDR_LBAL);
ep93xx_pata_write_reg(drv_data, 0xaa, IDECTRL_ADDR_NSECT);
ep93xx_pata_write_reg(drv_data, 0x55, IDECTRL_ADDR_LBAL);
ep93xx_pata_write_reg(drv_data, 0x55, IDECTRL_ADDR_NSECT);
ep93xx_pata_write_reg(drv_data, 0xaa, IDECTRL_ADDR_LBAL);
nsect = ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_NSECT);
lbal = ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_LBAL);
if ((nsect == 0x55) && (lbal == 0xaa))
return true;
return false;
}
static int ep93xx_pata_wait_after_reset(struct ata_link *link,
unsigned int devmask,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct ep93xx_pata_data *drv_data = ap->host->private_data;
unsigned int dev0 = devmask & (1 << 0);
unsigned int dev1 = devmask & (1 << 1);
int rc, ret = 0;
ata_msleep(ap, ATA_WAIT_AFTER_RESET);
rc = ata_sff_wait_ready(link, deadline);
if (rc)
return rc;
if (dev1) {
int i;
ap->ops->sff_dev_select(ap, 1);
for (i = 0; i < 2; i++) {
u8 nsect, lbal;
nsect = ep93xx_pata_read_reg(drv_data,
IDECTRL_ADDR_NSECT);
lbal = ep93xx_pata_read_reg(drv_data,
IDECTRL_ADDR_LBAL);
if (nsect == 1 && lbal == 1)
break;
msleep(50);
}
rc = ata_sff_wait_ready(link, deadline);
if (rc) {
if (rc != -ENODEV)
return rc;
ret = rc;
}
}
ap->ops->sff_dev_select(ap, 0);
if (dev1)
ap->ops->sff_dev_select(ap, 1);
if (dev0)
ap->ops->sff_dev_select(ap, 0);
return ret;
}
static int ep93xx_pata_bus_softreset(struct ata_port *ap, unsigned int devmask,
unsigned long deadline)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
ep93xx_pata_write_reg(drv_data, ap->ctl, IDECTRL_ADDR_CTL);
udelay(20);
ep93xx_pata_write_reg(drv_data, ap->ctl | ATA_SRST, IDECTRL_ADDR_CTL);
udelay(20);
ep93xx_pata_write_reg(drv_data, ap->ctl, IDECTRL_ADDR_CTL);
ap->last_ctl = ap->ctl;
return ep93xx_pata_wait_after_reset(&ap->link, devmask, deadline);
}
static void ep93xx_pata_release_dma(struct ep93xx_pata_data *drv_data)
{
if (drv_data->dma_rx_channel) {
dma_release_channel(drv_data->dma_rx_channel);
drv_data->dma_rx_channel = NULL;
}
if (drv_data->dma_tx_channel) {
dma_release_channel(drv_data->dma_tx_channel);
drv_data->dma_tx_channel = NULL;
}
}
static bool ep93xx_pata_dma_filter(struct dma_chan *chan, void *filter_param)
{
if (ep93xx_dma_chan_is_m2p(chan))
return false;
chan->private = filter_param;
return true;
}
static void ep93xx_pata_dma_init(struct ep93xx_pata_data *drv_data)
{
const struct platform_device *pdev = drv_data->pdev;
dma_cap_mask_t mask;
struct dma_slave_config conf;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
drv_data->dma_rx_data.port = EP93XX_DMA_IDE;
drv_data->dma_rx_data.direction = DMA_FROM_DEVICE;
drv_data->dma_rx_data.name = "ep93xx-pata-rx";
drv_data->dma_rx_channel = dma_request_channel(mask,
ep93xx_pata_dma_filter, &drv_data->dma_rx_data);
if (!drv_data->dma_rx_channel)
return;
drv_data->dma_tx_data.port = EP93XX_DMA_IDE;
drv_data->dma_tx_data.direction = DMA_TO_DEVICE;
drv_data->dma_tx_data.name = "ep93xx-pata-tx";
drv_data->dma_tx_channel = dma_request_channel(mask,
ep93xx_pata_dma_filter, &drv_data->dma_tx_data);
if (!drv_data->dma_tx_channel) {
dma_release_channel(drv_data->dma_rx_channel);
return;
}
memset(&conf, 0, sizeof(conf));
conf.direction = DMA_FROM_DEVICE;
conf.src_addr = drv_data->udma_in_phys;
conf.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
if (dmaengine_slave_config(drv_data->dma_rx_channel, &conf)) {
dev_err(&pdev->dev, "failed to configure rx dma channel\n");
ep93xx_pata_release_dma(drv_data);
return;
}
memset(&conf, 0, sizeof(conf));
conf.direction = DMA_TO_DEVICE;
conf.dst_addr = drv_data->udma_out_phys;
conf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
if (dmaengine_slave_config(drv_data->dma_tx_channel, &conf)) {
dev_err(&pdev->dev, "failed to configure tx dma channel\n");
ep93xx_pata_release_dma(drv_data);
}
}
static void ep93xx_pata_dma_start(struct ata_queued_cmd *qc)
{
struct dma_async_tx_descriptor *txd;
struct ep93xx_pata_data *drv_data = qc->ap->host->private_data;
void __iomem *base = drv_data->ide_base;
struct ata_device *adev = qc->dev;
u32 v = qc->dma_dir == DMA_TO_DEVICE ? IDEUDMAOP_RWOP : 0;
struct dma_chan *channel = qc->dma_dir == DMA_TO_DEVICE
? drv_data->dma_tx_channel : drv_data->dma_rx_channel;
txd = channel->device->device_prep_slave_sg(channel, qc->sg,
qc->n_elem, qc->dma_dir, DMA_CTRL_ACK, NULL);
if (!txd) {
dev_err(qc->ap->dev, "failed to prepare slave for sg dma\n");
return;
}
txd->callback = NULL;
txd->callback_param = NULL;
if (dmaengine_submit(txd) < 0) {
dev_err(qc->ap->dev, "failed to submit dma transfer\n");
return;
}
dma_async_issue_pending(channel);
writel(v, base + IDEUDMAOP);
readl(base + IDEUDMAOP);
writel(v | IDEUDMAOP_UEN, base + IDEUDMAOP);
writel(IDECFG_IDEEN | IDECFG_UDMA |
((adev->xfer_mode - XFER_UDMA_0) << IDECFG_MODE_SHIFT),
base + IDECFG);
}
static void ep93xx_pata_dma_stop(struct ata_queued_cmd *qc)
{
struct ep93xx_pata_data *drv_data = qc->ap->host->private_data;
void __iomem *base = drv_data->ide_base;
dmaengine_terminate_all(drv_data->dma_rx_channel);
dmaengine_terminate_all(drv_data->dma_tx_channel);
writel(0, base + IDEUDMAOP);
writel(readl(base + IDECTRL) | IDECTRL_DIOWN | IDECTRL_DIORN |
IDECTRL_CS0N | IDECTRL_CS1N, base + IDECTRL);
ep93xx_pata_enable_pio(drv_data->ide_base,
qc->dev->pio_mode - XFER_PIO_0);
ata_sff_dma_pause(qc->ap);
}
static void ep93xx_pata_dma_setup(struct ata_queued_cmd *qc)
{
qc->ap->ops->sff_exec_command(qc->ap, &qc->tf);
}
static u8 ep93xx_pata_dma_status(struct ata_port *ap)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
u32 val = readl(drv_data->ide_base + IDEUDMASTS);
if (val & IDEUDMASTS_NDO || val & IDEUDMASTS_NDI ||
val & IDEUDMASTS_N4X || val & IDEUDMASTS_INTIDE)
return ATA_DMA_ERR;
if (readl(drv_data->ide_base + IDECTRL) & IDECTRL_INTRQ)
return ATA_DMA_INTR;
if (val & IDEUDMASTS_SBUSY || val & IDEUDMASTS_DMAIDE)
return ATA_DMA_ACTIVE;
return 0;
}
static int ep93xx_pata_softreset(struct ata_link *al, unsigned int *classes,
unsigned long deadline)
{
struct ata_port *ap = al->ap;
unsigned int slave_possible = ap->flags & ATA_FLAG_SLAVE_POSS;
unsigned int devmask = 0;
int rc;
u8 err;
if (ep93xx_pata_device_is_present(ap, 0))
devmask |= (1 << 0);
if (slave_possible && ep93xx_pata_device_is_present(ap, 1))
devmask |= (1 << 1);
ap->ops->sff_dev_select(al->ap, 0);
rc = ep93xx_pata_bus_softreset(ap, devmask, deadline);
if (rc && (rc != -ENODEV || sata_scr_valid(al))) {
ata_link_err(al, "SRST failed (errno=%d)\n", rc);
return rc;
}
classes[0] = ata_sff_dev_classify(&al->device[0], devmask & (1 << 0),
&err);
if (slave_possible && err != 0x81)
classes[1] = ata_sff_dev_classify(&al->device[1],
devmask & (1 << 1), &err);
return 0;
}
static void ep93xx_pata_drain_fifo(struct ata_queued_cmd *qc)
{
int count;
struct ata_port *ap;
struct ep93xx_pata_data *drv_data;
if (qc == NULL || qc->dma_dir == DMA_TO_DEVICE)
return;
ap = qc->ap;
drv_data = ap->host->private_data;
for (count = 0; (ap->ops->sff_check_status(ap) & ATA_DRQ)
&& count < 65536; count += 2)
ep93xx_pata_read_reg(drv_data, IDECTRL_ADDR_DATA);
if (count)
ata_port_dbg(ap, "drained %d bytes to clear DRQ.\n", count);
}
static int ep93xx_pata_port_start(struct ata_port *ap)
{
struct ep93xx_pata_data *drv_data = ap->host->private_data;
drv_data->t = *ata_timing_find_mode(XFER_PIO_0);
return 0;
}
static int ep93xx_pata_probe(struct platform_device *pdev)
{
struct ep93xx_pata_data *drv_data;
struct ata_host *host;
struct ata_port *ap;
unsigned int irq;
struct resource *mem_res;
void __iomem *ide_base;
int err;
err = ep93xx_ide_acquire_gpio(pdev);
if (err)
return err;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
err = -ENXIO;
goto err_rel_gpio;
}
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ide_base = devm_ioremap_resource(&pdev->dev, mem_res);
if (IS_ERR(ide_base)) {
err = PTR_ERR(ide_base);
goto err_rel_gpio;
}
drv_data = devm_kzalloc(&pdev->dev, sizeof(*drv_data), GFP_KERNEL);
if (!drv_data) {
err = -ENXIO;
goto err_rel_gpio;
}
platform_set_drvdata(pdev, drv_data);
drv_data->pdev = pdev;
drv_data->ide_base = ide_base;
drv_data->udma_in_phys = mem_res->start + IDEUDMADATAIN;
drv_data->udma_out_phys = mem_res->start + IDEUDMADATAOUT;
ep93xx_pata_dma_init(drv_data);
host = ata_host_alloc(&pdev->dev, 1);
if (!host) {
err = -ENXIO;
goto err_rel_dma;
}
ep93xx_pata_clear_regs(ide_base);
host->private_data = drv_data;
ap = host->ports[0];
ap->dev = &pdev->dev;
ap->ops = &ep93xx_pata_port_ops;
ap->flags |= ATA_FLAG_SLAVE_POSS;
ap->pio_mask = ATA_PIO4;
if (drv_data->dma_rx_channel && drv_data->dma_tx_channel) {
int chip_rev = ep93xx_chip_revision();
if (chip_rev == EP93XX_CHIP_REV_E1)
ap->udma_mask = ATA_UDMA3;
else if (chip_rev == EP93XX_CHIP_REV_E2)
ap->udma_mask = ATA_UDMA4;
else
ap->udma_mask = ATA_UDMA2;
}
ep93xx_pata_enable_pio(ide_base, 0);
dev_info(&pdev->dev, "version " DRV_VERSION "\n");
err = ata_host_activate(host, irq, ata_bmdma_interrupt, 0,
&ep93xx_pata_sht);
if (err == 0)
return 0;
err_rel_dma:
ep93xx_pata_release_dma(drv_data);
err_rel_gpio:
ep93xx_ide_release_gpio(pdev);
return err;
}
static int ep93xx_pata_remove(struct platform_device *pdev)
{
struct ata_host *host = platform_get_drvdata(pdev);
struct ep93xx_pata_data *drv_data = host->private_data;
ata_host_detach(host);
ep93xx_pata_release_dma(drv_data);
ep93xx_pata_clear_regs(drv_data->ide_base);
ep93xx_ide_release_gpio(pdev);
return 0;
}
