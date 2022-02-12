static void
cumanascsi_2_irqenable(struct expansion_card *ec, int irqnr)
{
struct cumanascsi2_info *info = ec->irq_data;
writeb(ALATCH_ENA_INT, info->base + CUMANASCSI2_ALATCH);
}
static void
cumanascsi_2_irqdisable(struct expansion_card *ec, int irqnr)
{
struct cumanascsi2_info *info = ec->irq_data;
writeb(ALATCH_DIS_INT, info->base + CUMANASCSI2_ALATCH);
}
static void
cumanascsi_2_terminator_ctl(struct Scsi_Host *host, int on_off)
{
struct cumanascsi2_info *info = (struct cumanascsi2_info *)host->hostdata;
if (on_off) {
info->terms = 1;
writeb(ALATCH_ENA_TERM, info->base + CUMANASCSI2_ALATCH);
} else {
info->terms = 0;
writeb(ALATCH_DIS_TERM, info->base + CUMANASCSI2_ALATCH);
}
}
static irqreturn_t
cumanascsi_2_intr(int irq, void *dev_id)
{
struct cumanascsi2_info *info = dev_id;
return fas216_intr(&info->info);
}
static fasdmatype_t
cumanascsi_2_dma_setup(struct Scsi_Host *host, struct scsi_pointer *SCp,
fasdmadir_t direction, fasdmatype_t min_type)
{
struct cumanascsi2_info *info = (struct cumanascsi2_info *)host->hostdata;
struct device *dev = scsi_get_device(host);
int dmach = info->info.scsi.dma;
writeb(ALATCH_DIS_DMA, info->base + CUMANASCSI2_ALATCH);
if (dmach != NO_DMA &&
(min_type == fasdma_real_all || SCp->this_residual >= 512)) {
int bufs, map_dir, dma_dir, alatch_dir;
bufs = copy_SCp_to_sg(&info->sg[0], SCp, NR_SG);
if (direction == DMA_OUT)
map_dir = DMA_TO_DEVICE,
dma_dir = DMA_MODE_WRITE,
alatch_dir = ALATCH_DMA_OUT;
else
map_dir = DMA_FROM_DEVICE,
dma_dir = DMA_MODE_READ,
alatch_dir = ALATCH_DMA_IN;
dma_map_sg(dev, info->sg, bufs, map_dir);
disable_dma(dmach);
set_dma_sg(dmach, info->sg, bufs);
writeb(alatch_dir, info->base + CUMANASCSI2_ALATCH);
set_dma_mode(dmach, dma_dir);
enable_dma(dmach);
writeb(ALATCH_ENA_DMA, info->base + CUMANASCSI2_ALATCH);
writeb(ALATCH_DIS_BIT32, info->base + CUMANASCSI2_ALATCH);
return fasdma_real_all;
}
return fasdma_pio;
}
static void
cumanascsi_2_dma_pseudo(struct Scsi_Host *host, struct scsi_pointer *SCp,
fasdmadir_t direction, int transfer)
{
struct cumanascsi2_info *info = (struct cumanascsi2_info *)host->hostdata;
unsigned int length;
unsigned char *addr;
length = SCp->this_residual;
addr = SCp->ptr;
if (direction == DMA_OUT)
#if 0
while (length > 1) {
unsigned long word;
unsigned int status = readb(info->base + CUMANASCSI2_STATUS);
if (status & STATUS_INT)
goto end;
if (!(status & STATUS_DRQ))
continue;
word = *addr | *(addr + 1) << 8;
writew(word, info->base + CUMANASCSI2_PSEUDODMA);
addr += 2;
length -= 2;
}
#else
printk ("PSEUDO_OUT???\n");
#endif
else {
if (transfer && (transfer & 255)) {
while (length >= 256) {
unsigned int status = readb(info->base + CUMANASCSI2_STATUS);
if (status & STATUS_INT)
return;
if (!(status & STATUS_DRQ))
continue;
readsw(info->base + CUMANASCSI2_PSEUDODMA,
addr, 256 >> 1);
addr += 256;
length -= 256;
}
}
while (length > 0) {
unsigned long word;
unsigned int status = readb(info->base + CUMANASCSI2_STATUS);
if (status & STATUS_INT)
return;
if (!(status & STATUS_DRQ))
continue;
word = readw(info->base + CUMANASCSI2_PSEUDODMA);
*addr++ = word;
if (--length > 0) {
*addr++ = word >> 8;
length --;
}
}
}
}
static void
cumanascsi_2_dma_stop(struct Scsi_Host *host, struct scsi_pointer *SCp)
{
struct cumanascsi2_info *info = (struct cumanascsi2_info *)host->hostdata;
if (info->info.scsi.dma != NO_DMA) {
writeb(ALATCH_DIS_DMA, info->base + CUMANASCSI2_ALATCH);
disable_dma(info->info.scsi.dma);
}
}
const char *cumanascsi_2_info(struct Scsi_Host *host)
{
struct cumanascsi2_info *info = (struct cumanascsi2_info *)host->hostdata;
static char string[150];
sprintf(string, "%s (%s) in slot %d v%s terminators o%s",
host->hostt->name, info->info.scsi.type, info->ec->slot_no,
VERSION, info->terms ? "n" : "ff");
return string;
}
static int
cumanascsi_2_set_proc_info(struct Scsi_Host *host, char *buffer, int length)
{
int ret = length;
if (length >= 11 && strncmp(buffer, "CUMANASCSI2", 11) == 0) {
buffer += 11;
length -= 11;
if (length >= 5 && strncmp(buffer, "term=", 5) == 0) {
if (buffer[5] == '1')
cumanascsi_2_terminator_ctl(host, 1);
else if (buffer[5] == '0')
cumanascsi_2_terminator_ctl(host, 0);
else
ret = -EINVAL;
} else
ret = -EINVAL;
} else
ret = -EINVAL;
return ret;
}
int cumanascsi_2_proc_info (struct Scsi_Host *host, char *buffer, char **start, off_t offset,
int length, int inout)
{
struct cumanascsi2_info *info;
char *p = buffer;
int pos;
if (inout == 1)
return cumanascsi_2_set_proc_info(host, buffer, length);
info = (struct cumanascsi2_info *)host->hostdata;
p += sprintf(p, "Cumana SCSI II driver v%s\n", VERSION);
p += fas216_print_host(&info->info, p);
p += sprintf(p, "Term : o%s\n",
info->terms ? "n" : "ff");
p += fas216_print_stats(&info->info, p);
p += fas216_print_devices(&info->info, p);
*start = buffer + offset;
pos = p - buffer - offset;
if (pos > length)
pos = length;
return pos;
}
static int cumanascsi2_probe(struct expansion_card *ec,
const struct ecard_id *id)
{
struct Scsi_Host *host;
struct cumanascsi2_info *info;
void __iomem *base;
int ret;
ret = ecard_request_resources(ec);
if (ret)
goto out;
base = ecardm_iomap(ec, ECARD_RES_MEMC, 0, 0);
if (!base) {
ret = -ENOMEM;
goto out_region;
}
host = scsi_host_alloc(&cumanascsi2_template,
sizeof(struct cumanascsi2_info));
if (!host) {
ret = -ENOMEM;
goto out_region;
}
ecard_set_drvdata(ec, host);
info = (struct cumanascsi2_info *)host->hostdata;
info->ec = ec;
info->base = base;
cumanascsi_2_terminator_ctl(host, term[ec->slot_no]);
info->info.scsi.io_base = base + CUMANASCSI2_FAS216_OFFSET;
info->info.scsi.io_shift = CUMANASCSI2_FAS216_SHIFT;
info->info.scsi.irq = ec->irq;
info->info.scsi.dma = ec->dma;
info->info.ifcfg.clockrate = 40;
info->info.ifcfg.select_timeout = 255;
info->info.ifcfg.asyncperiod = 200;
info->info.ifcfg.sync_max_depth = 7;
info->info.ifcfg.cntl3 = CNTL3_BS8 | CNTL3_FASTSCSI | CNTL3_FASTCLK;
info->info.ifcfg.disconnect_ok = 1;
info->info.ifcfg.wide_max_size = 0;
info->info.ifcfg.capabilities = FASCAP_PSEUDODMA;
info->info.dma.setup = cumanascsi_2_dma_setup;
info->info.dma.pseudo = cumanascsi_2_dma_pseudo;
info->info.dma.stop = cumanascsi_2_dma_stop;
ec->irqaddr = info->base + CUMANASCSI2_STATUS;
ec->irqmask = STATUS_INT;
ecard_setirq(ec, &cumanascsi_2_ops, info);
ret = fas216_init(host);
if (ret)
goto out_free;
ret = request_irq(ec->irq, cumanascsi_2_intr,
IRQF_DISABLED, "cumanascsi2", info);
if (ret) {
printk("scsi%d: IRQ%d not free: %d\n",
host->host_no, ec->irq, ret);
goto out_release;
}
if (info->info.scsi.dma != NO_DMA) {
if (request_dma(info->info.scsi.dma, "cumanascsi2")) {
printk("scsi%d: DMA%d not free, using PIO\n",
host->host_no, info->info.scsi.dma);
info->info.scsi.dma = NO_DMA;
} else {
set_dma_speed(info->info.scsi.dma, 180);
info->info.ifcfg.capabilities |= FASCAP_DMA;
}
}
ret = fas216_add(host, &ec->dev);
if (ret == 0)
goto out;
if (info->info.scsi.dma != NO_DMA)
free_dma(info->info.scsi.dma);
free_irq(ec->irq, host);
out_release:
fas216_release(host);
out_free:
scsi_host_put(host);
out_region:
ecard_release_resources(ec);
out:
return ret;
}
static void cumanascsi2_remove(struct expansion_card *ec)
{
struct Scsi_Host *host = ecard_get_drvdata(ec);
struct cumanascsi2_info *info = (struct cumanascsi2_info *)host->hostdata;
ecard_set_drvdata(ec, NULL);
fas216_remove(host);
if (info->info.scsi.dma != NO_DMA)
free_dma(info->info.scsi.dma);
free_irq(ec->irq, info);
fas216_release(host);
scsi_host_put(host);
ecard_release_resources(ec);
}
static int __init cumanascsi2_init(void)
{
return ecard_register_driver(&cumanascsi2_driver);
}
static void __exit cumanascsi2_exit(void)
{
ecard_remove_driver(&cumanascsi2_driver);
}
