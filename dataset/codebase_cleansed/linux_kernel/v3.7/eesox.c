static void
eesoxscsi_irqenable(struct expansion_card *ec, int irqnr)
{
struct eesoxscsi_info *info = (struct eesoxscsi_info *)ec->irq_data;
info->control |= EESOX_INTR_ENABLE;
writeb(info->control, info->ctl_port);
}
static void
eesoxscsi_irqdisable(struct expansion_card *ec, int irqnr)
{
struct eesoxscsi_info *info = (struct eesoxscsi_info *)ec->irq_data;
info->control &= ~EESOX_INTR_ENABLE;
writeb(info->control, info->ctl_port);
}
static void
eesoxscsi_terminator_ctl(struct Scsi_Host *host, int on_off)
{
struct eesoxscsi_info *info = (struct eesoxscsi_info *)host->hostdata;
unsigned long flags;
spin_lock_irqsave(host->host_lock, flags);
if (on_off)
info->control |= EESOX_TERM_ENABLE;
else
info->control &= ~EESOX_TERM_ENABLE;
writeb(info->control, info->ctl_port);
spin_unlock_irqrestore(host->host_lock, flags);
}
static irqreturn_t
eesoxscsi_intr(int irq, void *dev_id)
{
struct eesoxscsi_info *info = dev_id;
return fas216_intr(&info->info);
}
static fasdmatype_t
eesoxscsi_dma_setup(struct Scsi_Host *host, struct scsi_pointer *SCp,
fasdmadir_t direction, fasdmatype_t min_type)
{
struct eesoxscsi_info *info = (struct eesoxscsi_info *)host->hostdata;
struct device *dev = scsi_get_device(host);
int dmach = info->info.scsi.dma;
if (dmach != NO_DMA &&
(min_type == fasdma_real_all || SCp->this_residual >= 512)) {
int bufs, map_dir, dma_dir;
bufs = copy_SCp_to_sg(&info->sg[0], SCp, NR_SG);
if (direction == DMA_OUT)
map_dir = DMA_TO_DEVICE,
dma_dir = DMA_MODE_WRITE;
else
map_dir = DMA_FROM_DEVICE,
dma_dir = DMA_MODE_READ;
dma_map_sg(dev, info->sg, bufs, map_dir);
disable_dma(dmach);
set_dma_sg(dmach, info->sg, bufs);
set_dma_mode(dmach, dma_dir);
enable_dma(dmach);
return fasdma_real_all;
}
return fasdma_pseudo;
}
static void eesoxscsi_buffer_in(void *buf, int length, void __iomem *base)
{
const void __iomem *reg_fas = base + EESOX_FAS216_OFFSET;
const void __iomem *reg_dmastat = base + EESOX_DMASTAT;
const void __iomem *reg_dmadata = base + EESOX_DMADATA;
register const unsigned long mask = 0xffff;
do {
unsigned int status;
status = readb(reg_fas + (REG_STAT << EESOX_FAS216_SHIFT));
if (status & STAT_INT)
break;
status = readb(reg_dmastat);
if (!(status & EESOX_STAT_DMA))
continue;
status = readb(reg_fas + (REG_CFIS << EESOX_FAS216_SHIFT)) & CFIS_CF;
if (status > 16)
status = 16;
if (status > length)
status = length;
if (((u32)buf) & 2 && status >= 2) {
*(u16 *)buf = readl(reg_dmadata);
buf += 2;
status -= 2;
length -= 2;
}
if (status >= 8) {
unsigned long l1, l2;
l1 = readl(reg_dmadata) & mask;
l1 |= readl(reg_dmadata) << 16;
l2 = readl(reg_dmadata) & mask;
l2 |= readl(reg_dmadata) << 16;
*(u32 *)buf = l1;
buf += 4;
*(u32 *)buf = l2;
buf += 4;
length -= 8;
continue;
}
if (status >= 4) {
unsigned long l1;
l1 = readl(reg_dmadata) & mask;
l1 |= readl(reg_dmadata) << 16;
*(u32 *)buf = l1;
buf += 4;
length -= 4;
continue;
}
if (status >= 2) {
*(u16 *)buf = readl(reg_dmadata);
buf += 2;
length -= 2;
}
} while (length);
}
static void eesoxscsi_buffer_out(void *buf, int length, void __iomem *base)
{
const void __iomem *reg_fas = base + EESOX_FAS216_OFFSET;
const void __iomem *reg_dmastat = base + EESOX_DMASTAT;
void __iomem *reg_dmadata = base + EESOX_DMADATA;
do {
unsigned int status;
status = readb(reg_fas + (REG_STAT << EESOX_FAS216_SHIFT));
if (status & STAT_INT)
break;
status = readb(reg_dmastat);
if (!(status & EESOX_STAT_DMA))
continue;
status = readb(reg_fas + (REG_CFIS << EESOX_FAS216_SHIFT)) & CFIS_CF;
if (status > 16)
status = 16;
status = 16 - status;
if (status > length)
status = length;
status &= ~1;
if (((u32)buf) & 2 && status >= 2) {
writel(*(u16 *)buf << 16, reg_dmadata);
buf += 2;
status -= 2;
length -= 2;
}
if (status >= 8) {
unsigned long l1, l2;
l1 = *(u32 *)buf;
buf += 4;
l2 = *(u32 *)buf;
buf += 4;
writel(l1 << 16, reg_dmadata);
writel(l1, reg_dmadata);
writel(l2 << 16, reg_dmadata);
writel(l2, reg_dmadata);
length -= 8;
continue;
}
if (status >= 4) {
unsigned long l1;
l1 = *(u32 *)buf;
buf += 4;
writel(l1 << 16, reg_dmadata);
writel(l1, reg_dmadata);
length -= 4;
continue;
}
if (status >= 2) {
writel(*(u16 *)buf << 16, reg_dmadata);
buf += 2;
length -= 2;
}
} while (length);
}
static void
eesoxscsi_dma_pseudo(struct Scsi_Host *host, struct scsi_pointer *SCp,
fasdmadir_t dir, int transfer_size)
{
struct eesoxscsi_info *info = (struct eesoxscsi_info *)host->hostdata;
if (dir == DMA_IN) {
eesoxscsi_buffer_in(SCp->ptr, SCp->this_residual, info->base);
} else {
eesoxscsi_buffer_out(SCp->ptr, SCp->this_residual, info->base);
}
}
static void
eesoxscsi_dma_stop(struct Scsi_Host *host, struct scsi_pointer *SCp)
{
struct eesoxscsi_info *info = (struct eesoxscsi_info *)host->hostdata;
if (info->info.scsi.dma != NO_DMA)
disable_dma(info->info.scsi.dma);
}
const char *eesoxscsi_info(struct Scsi_Host *host)
{
struct eesoxscsi_info *info = (struct eesoxscsi_info *)host->hostdata;
static char string[150];
sprintf(string, "%s (%s) in slot %d v%s terminators o%s",
host->hostt->name, info->info.scsi.type, info->ec->slot_no,
VERSION, info->control & EESOX_TERM_ENABLE ? "n" : "ff");
return string;
}
static int
eesoxscsi_set_proc_info(struct Scsi_Host *host, char *buffer, int length)
{
int ret = length;
if (length >= 9 && strncmp(buffer, "EESOXSCSI", 9) == 0) {
buffer += 9;
length -= 9;
if (length >= 5 && strncmp(buffer, "term=", 5) == 0) {
if (buffer[5] == '1')
eesoxscsi_terminator_ctl(host, 1);
else if (buffer[5] == '0')
eesoxscsi_terminator_ctl(host, 0);
else
ret = -EINVAL;
} else
ret = -EINVAL;
} else
ret = -EINVAL;
return ret;
}
int eesoxscsi_proc_info(struct Scsi_Host *host, char *buffer, char **start, off_t offset,
int length, int inout)
{
struct eesoxscsi_info *info;
char *p = buffer;
int pos;
if (inout == 1)
return eesoxscsi_set_proc_info(host, buffer, length);
info = (struct eesoxscsi_info *)host->hostdata;
p += sprintf(p, "EESOX SCSI driver v%s\n", VERSION);
p += fas216_print_host(&info->info, p);
p += sprintf(p, "Term : o%s\n",
info->control & EESOX_TERM_ENABLE ? "n" : "ff");
p += fas216_print_stats(&info->info, p);
p += fas216_print_devices(&info->info, p);
*start = buffer + offset;
pos = p - buffer - offset;
if (pos > length)
pos = length;
return pos;
}
static ssize_t eesoxscsi_show_term(struct device *dev, struct device_attribute *attr, char *buf)
{
struct expansion_card *ec = ECARD_DEV(dev);
struct Scsi_Host *host = ecard_get_drvdata(ec);
struct eesoxscsi_info *info = (struct eesoxscsi_info *)host->hostdata;
return sprintf(buf, "%d\n", info->control & EESOX_TERM_ENABLE ? 1 : 0);
}
static ssize_t eesoxscsi_store_term(struct device *dev, struct device_attribute *attr, const char *buf, size_t len)
{
struct expansion_card *ec = ECARD_DEV(dev);
struct Scsi_Host *host = ecard_get_drvdata(ec);
struct eesoxscsi_info *info = (struct eesoxscsi_info *)host->hostdata;
unsigned long flags;
if (len > 1) {
spin_lock_irqsave(host->host_lock, flags);
if (buf[0] != '0') {
info->control |= EESOX_TERM_ENABLE;
} else {
info->control &= ~EESOX_TERM_ENABLE;
}
writeb(info->control, info->ctl_port);
spin_unlock_irqrestore(host->host_lock, flags);
}
return len;
}
static int __devinit
eesoxscsi_probe(struct expansion_card *ec, const struct ecard_id *id)
{
struct Scsi_Host *host;
struct eesoxscsi_info *info;
void __iomem *base;
int ret;
ret = ecard_request_resources(ec);
if (ret)
goto out;
base = ecardm_iomap(ec, ECARD_RES_IOCFAST, 0, 0);
if (!base) {
ret = -ENOMEM;
goto out_region;
}
host = scsi_host_alloc(&eesox_template,
sizeof(struct eesoxscsi_info));
if (!host) {
ret = -ENOMEM;
goto out_region;
}
ecard_set_drvdata(ec, host);
info = (struct eesoxscsi_info *)host->hostdata;
info->ec = ec;
info->base = base;
info->ctl_port = base + EESOX_CONTROL;
info->control = term[ec->slot_no] ? EESOX_TERM_ENABLE : 0;
writeb(info->control, info->ctl_port);
info->info.scsi.io_base = base + EESOX_FAS216_OFFSET;
info->info.scsi.io_shift = EESOX_FAS216_SHIFT;
info->info.scsi.irq = ec->irq;
info->info.scsi.dma = ec->dma;
info->info.ifcfg.clockrate = 40;
info->info.ifcfg.select_timeout = 255;
info->info.ifcfg.asyncperiod = 200;
info->info.ifcfg.sync_max_depth = 7;
info->info.ifcfg.cntl3 = CNTL3_FASTSCSI | CNTL3_FASTCLK;
info->info.ifcfg.disconnect_ok = 1;
info->info.ifcfg.wide_max_size = 0;
info->info.ifcfg.capabilities = FASCAP_PSEUDODMA;
info->info.dma.setup = eesoxscsi_dma_setup;
info->info.dma.pseudo = eesoxscsi_dma_pseudo;
info->info.dma.stop = eesoxscsi_dma_stop;
ec->irqaddr = base + EESOX_DMASTAT;
ec->irqmask = EESOX_STAT_INTR;
ecard_setirq(ec, &eesoxscsi_ops, info);
device_create_file(&ec->dev, &dev_attr_bus_term);
ret = fas216_init(host);
if (ret)
goto out_free;
ret = request_irq(ec->irq, eesoxscsi_intr, 0, "eesoxscsi", info);
if (ret) {
printk("scsi%d: IRQ%d not free: %d\n",
host->host_no, ec->irq, ret);
goto out_remove;
}
if (info->info.scsi.dma != NO_DMA) {
if (request_dma(info->info.scsi.dma, "eesox")) {
printk("scsi%d: DMA%d not free, DMA disabled\n",
host->host_no, info->info.scsi.dma);
info->info.scsi.dma = NO_DMA;
} else {
set_dma_speed(info->info.scsi.dma, 180);
info->info.ifcfg.capabilities |= FASCAP_DMA;
info->info.ifcfg.cntl3 |= CNTL3_BS8;
}
}
ret = fas216_add(host, &ec->dev);
if (ret == 0)
goto out;
if (info->info.scsi.dma != NO_DMA)
free_dma(info->info.scsi.dma);
free_irq(ec->irq, host);
out_remove:
fas216_remove(host);
out_free:
device_remove_file(&ec->dev, &dev_attr_bus_term);
scsi_host_put(host);
out_region:
ecard_release_resources(ec);
out:
return ret;
}
static void __devexit eesoxscsi_remove(struct expansion_card *ec)
{
struct Scsi_Host *host = ecard_get_drvdata(ec);
struct eesoxscsi_info *info = (struct eesoxscsi_info *)host->hostdata;
ecard_set_drvdata(ec, NULL);
fas216_remove(host);
if (info->info.scsi.dma != NO_DMA)
free_dma(info->info.scsi.dma);
free_irq(ec->irq, info);
device_remove_file(&ec->dev, &dev_attr_bus_term);
fas216_release(host);
scsi_host_put(host);
ecard_release_resources(ec);
}
static int __init eesox_init(void)
{
return ecard_register_driver(&eesoxscsi_driver);
}
static void __exit eesox_exit(void)
{
ecard_remove_driver(&eesoxscsi_driver);
}
