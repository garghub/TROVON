static u16 tx4939ide_readw(void __iomem *base, u32 reg)
{
return __raw_readw(base + tx4939ide_swizzlew(reg));
}
static u8 tx4939ide_readb(void __iomem *base, u32 reg)
{
return __raw_readb(base + tx4939ide_swizzleb(reg));
}
static void tx4939ide_writel(u32 val, void __iomem *base, u32 reg)
{
__raw_writel(val, base + tx4939ide_swizzlel(reg));
}
static void tx4939ide_writew(u16 val, void __iomem *base, u32 reg)
{
__raw_writew(val, base + tx4939ide_swizzlew(reg));
}
static void tx4939ide_writeb(u8 val, void __iomem *base, u32 reg)
{
__raw_writeb(val, base + tx4939ide_swizzleb(reg));
}
static void tx4939ide_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
int is_slave = drive->dn;
u32 mask, val;
const u8 pio = drive->pio_mode - XFER_PIO_0;
u8 safe = pio;
ide_drive_t *pair;
pair = ide_get_pair_dev(drive);
if (pair)
safe = min_t(u8, safe, pair->pio_mode - XFER_PIO_0);
mask = is_slave ? 0x07f00000 : 0x000007f0;
val = ((safe << 8) | (pio << 4)) << (is_slave ? 16 : 0);
hwif->select_data = (hwif->select_data & ~mask) | val;
}
static void tx4939ide_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
u32 mask, val;
const u8 mode = drive->dma_mode;
if (mode >= XFER_UDMA_0)
val = mode - XFER_UDMA_0 + 8;
else
val = mode - XFER_MW_DMA_0 + 5;
if (drive->dn) {
mask = 0x00f00000;
val <<= 20;
} else {
mask = 0x000000f0;
val <<= 4;
}
hwif->select_data = (hwif->select_data & ~mask) | val;
}
static u16 tx4939ide_check_error_ints(ide_hwif_t *hwif)
{
void __iomem *base = TX4939IDE_BASE(hwif);
u16 ctl = tx4939ide_readw(base, TX4939IDE_Int_Ctl);
if (ctl & TX4939IDE_INT_BUSERR) {
u16 sysctl = tx4939ide_readw(base, TX4939IDE_Sys_Ctl);
tx4939ide_writew(sysctl | 0x4000, base, TX4939IDE_Sys_Ctl);
mmiowb();
ndelay(270);
tx4939ide_writew(sysctl, base, TX4939IDE_Sys_Ctl);
}
if (ctl & (TX4939IDE_INT_ADDRERR |
TX4939IDE_INT_DEVTIMING | TX4939IDE_INT_BUSERR))
pr_err("%s: Error interrupt %#x (%s%s%s )\n",
hwif->name, ctl,
ctl & TX4939IDE_INT_ADDRERR ? " Address-Error" : "",
ctl & TX4939IDE_INT_DEVTIMING ? " DEV-Timing" : "",
ctl & TX4939IDE_INT_BUSERR ? " Bus-Error" : "");
return ctl;
}
static void tx4939ide_clear_irq(ide_drive_t *drive)
{
ide_hwif_t *hwif;
void __iomem *base;
u16 ctl;
if (drive->waiting_for_dma)
return;
hwif = drive->hwif;
base = TX4939IDE_BASE(hwif);
ctl = tx4939ide_check_error_ints(hwif);
tx4939ide_writew(ctl, base, TX4939IDE_Int_Ctl);
}
static u8 tx4939ide_cable_detect(ide_hwif_t *hwif)
{
void __iomem *base = TX4939IDE_BASE(hwif);
return tx4939ide_readw(base, TX4939IDE_Sys_Ctl) & 0x2000 ?
ATA_CBL_PATA40 : ATA_CBL_PATA80;
}
static void tx4939ide_dma_host_set(ide_drive_t *drive, int on)
{
ide_hwif_t *hwif = drive->hwif;
u8 unit = drive->dn;
void __iomem *base = TX4939IDE_BASE(hwif);
u8 dma_stat = tx4939ide_readb(base, TX4939IDE_DMA_Stat);
if (on)
dma_stat |= (1 << (5 + unit));
else
dma_stat &= ~(1 << (5 + unit));
tx4939ide_writeb(dma_stat, base, TX4939IDE_DMA_Stat);
}
static u8 tx4939ide_clear_dma_status(void __iomem *base)
{
u8 dma_stat;
dma_stat = tx4939ide_readb(base, TX4939IDE_DMA_Stat);
tx4939ide_writeb(dma_stat | ATA_DMA_INTR | ATA_DMA_ERR, base,
TX4939IDE_DMA_Stat);
tx4939ide_writew(TX4939IDE_IGNORE_INTS << 8, base, TX4939IDE_Int_Ctl);
return dma_stat;
}
static int tx4939ide_build_dmatable(ide_drive_t *drive, struct ide_cmd *cmd)
{
ide_hwif_t *hwif = drive->hwif;
u32 *table = (u32 *)hwif->dmatable_cpu;
unsigned int count = 0;
int i;
struct scatterlist *sg;
for_each_sg(hwif->sg_table, sg, cmd->sg_nents, i) {
u32 cur_addr, cur_len, bcount;
cur_addr = sg_dma_address(sg);
cur_len = sg_dma_len(sg);
while (cur_len) {
if (count++ >= PRD_ENTRIES)
goto use_pio_instead;
bcount = 0x10000 - (cur_addr & 0xffff);
if (bcount > cur_len)
bcount = cur_len;
if (bcount == 0x10000)
bcount = 0x8000;
*table++ = bcount & 0xffff;
*table++ = cur_addr;
cur_addr += bcount;
cur_len -= bcount;
}
}
if (count) {
*(table - 2) |= 0x80000000;
return count;
}
use_pio_instead:
printk(KERN_ERR "%s: %s\n", drive->name,
count ? "DMA table too small" : "empty DMA table?");
return 0;
}
static int tx4939ide_dma_setup(ide_drive_t *drive, struct ide_cmd *cmd)
{
ide_hwif_t *hwif = drive->hwif;
void __iomem *base = TX4939IDE_BASE(hwif);
u8 rw = (cmd->tf_flags & IDE_TFLAG_WRITE) ? 0 : ATA_DMA_WR;
if (tx4939ide_build_dmatable(drive, cmd) == 0)
return 1;
tx4939ide_writel(hwif->dmatable_dma, base, TX4939IDE_PRD_Ptr);
tx4939ide_writeb(rw, base, TX4939IDE_DMA_Cmd);
tx4939ide_clear_dma_status(base);
tx4939ide_writew(SECTOR_SIZE / 2, base, drive->dn ?
TX4939IDE_Xfer_Cnt_2 : TX4939IDE_Xfer_Cnt_1);
tx4939ide_writew(blk_rq_sectors(cmd->rq), base, TX4939IDE_Sec_Cnt);
return 0;
}
static int tx4939ide_dma_end(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 dma_stat, dma_cmd;
void __iomem *base = TX4939IDE_BASE(hwif);
u16 ctl = tx4939ide_readw(base, TX4939IDE_Int_Ctl);
dma_cmd = tx4939ide_readb(base, TX4939IDE_DMA_Cmd);
tx4939ide_writeb(dma_cmd & ~ATA_DMA_START, base, TX4939IDE_DMA_Cmd);
dma_stat = tx4939ide_clear_dma_status(base);
#define CHECK_DMA_MASK (ATA_DMA_ACTIVE | ATA_DMA_ERR | ATA_DMA_INTR)
if ((dma_stat & CHECK_DMA_MASK) == 0 &&
(ctl & (TX4939IDE_INT_XFEREND | TX4939IDE_INT_HOST)) ==
(TX4939IDE_INT_XFEREND | TX4939IDE_INT_HOST))
return 0;
return ((dma_stat & CHECK_DMA_MASK) !=
ATA_DMA_INTR) ? 0x10 | dma_stat : 0;
}
static int tx4939ide_dma_test_irq(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
void __iomem *base = TX4939IDE_BASE(hwif);
u16 ctl, ide_int;
u8 dma_stat, stat;
int found = 0;
ctl = tx4939ide_check_error_ints(hwif);
ide_int = ctl & (TX4939IDE_INT_XFEREND | TX4939IDE_INT_HOST);
switch (ide_int) {
case TX4939IDE_INT_HOST:
stat = tx4939ide_readb(base, TX4939IDE_AltStat_DevCtl);
if ((stat & (ATA_BUSY | ATA_DRQ | ATA_ERR)) == ATA_ERR)
found = 1;
else
ctl &= ~TX4939IDE_INT_XFEREND << 8;
ctl |= ide_int << 8;
break;
case TX4939IDE_INT_HOST | TX4939IDE_INT_XFEREND:
dma_stat = tx4939ide_readb(base, TX4939IDE_DMA_Stat);
if (!(dma_stat & ATA_DMA_INTR))
pr_warning("%s: weird interrupt status. "
"DMA_Stat %#02x int_ctl %#04x\n",
hwif->name, dma_stat, ctl);
found = 1;
break;
}
ctl &= ~ide_int;
tx4939ide_writew(ctl, base, TX4939IDE_Int_Ctl);
return found;
}
static u8 tx4939ide_dma_sff_read_status(ide_hwif_t *hwif)
{
void __iomem *base = TX4939IDE_BASE(hwif);
return tx4939ide_readb(base, TX4939IDE_DMA_Stat);
}
static void tx4939ide_init_hwif(ide_hwif_t *hwif)
{
void __iomem *base = TX4939IDE_BASE(hwif);
tx4939ide_writew(0x8000, base, TX4939IDE_Sys_Ctl);
mmiowb();
ndelay(450);
tx4939ide_writew(0x0000, base, TX4939IDE_Sys_Ctl);
tx4939ide_writew((TX4939IDE_IGNORE_INTS << 8) | 0xff, base,
TX4939IDE_Int_Ctl);
tx4939ide_writew(0x0008, base, TX4939IDE_Lo_Burst_Cnt);
tx4939ide_writew(0, base, TX4939IDE_Up_Burst_Cnt);
}
static int tx4939ide_init_dma(ide_hwif_t *hwif, const struct ide_port_info *d)
{
hwif->dma_base =
hwif->extra_base + tx4939ide_swizzleb(TX4939IDE_DMA_Cmd);
return ide_allocate_dma_engine(hwif);
}
static void tx4939ide_tf_load_fixup(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
void __iomem *base = TX4939IDE_BASE(hwif);
u16 sysctl = hwif->select_data >> (drive->dn ? 16 : 0);
tx4939ide_writew(sysctl, base, TX4939IDE_Sys_Ctl);
}
static void tx4939ide_tf_load(ide_drive_t *drive, struct ide_taskfile *tf,
u8 valid)
{
ide_tf_load(drive, tf, valid);
if (valid & IDE_VALID_DEVICE)
tx4939ide_tf_load_fixup(drive);
}
static void tx4939ide_input_data_swap(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
unsigned long port = drive->hwif->io_ports.data_addr;
unsigned short *ptr = buf;
unsigned int count = (len + 1) / 2;
while (count--)
*ptr++ = cpu_to_le16(__raw_readw((void __iomem *)port));
__ide_flush_dcache_range((unsigned long)buf, roundup(len, 2));
}
static void tx4939ide_output_data_swap(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
unsigned long port = drive->hwif->io_ports.data_addr;
unsigned short *ptr = buf;
unsigned int count = (len + 1) / 2;
while (count--) {
__raw_writew(le16_to_cpu(*ptr), (void __iomem *)port);
ptr++;
}
__ide_flush_dcache_range((unsigned long)buf, roundup(len, 2));
}
static int __init tx4939ide_probe(struct platform_device *pdev)
{
struct ide_hw hw, *hws[] = { &hw };
struct ide_host *host;
struct resource *res;
int irq, ret;
unsigned long mapbase;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
if (!devm_request_mem_region(&pdev->dev, res->start,
res->end - res->start + 1, "tx4938ide"))
return -EBUSY;
mapbase = (unsigned long)devm_ioremap(&pdev->dev, res->start,
res->end - res->start + 1);
if (!mapbase)
return -EBUSY;
memset(&hw, 0, sizeof(hw));
hw.io_ports.data_addr =
mapbase + tx4939ide_swizzlew(TX4939IDE_Data);
hw.io_ports.error_addr =
mapbase + tx4939ide_swizzleb(TX4939IDE_Error_Feature);
hw.io_ports.nsect_addr =
mapbase + tx4939ide_swizzleb(TX4939IDE_Sec);
hw.io_ports.lbal_addr =
mapbase + tx4939ide_swizzleb(TX4939IDE_LBA0);
hw.io_ports.lbam_addr =
mapbase + tx4939ide_swizzleb(TX4939IDE_LBA1);
hw.io_ports.lbah_addr =
mapbase + tx4939ide_swizzleb(TX4939IDE_LBA2);
hw.io_ports.device_addr =
mapbase + tx4939ide_swizzleb(TX4939IDE_DevHead);
hw.io_ports.command_addr =
mapbase + tx4939ide_swizzleb(TX4939IDE_Stat_Cmd);
hw.io_ports.ctl_addr =
mapbase + tx4939ide_swizzleb(TX4939IDE_AltStat_DevCtl);
hw.irq = irq;
hw.dev = &pdev->dev;
pr_info("TX4939 IDE interface (base %#lx, irq %d)\n", mapbase, irq);
host = ide_host_alloc(&tx4939ide_port_info, hws, 1);
if (!host)
return -ENOMEM;
host->ports[0]->extra_base = mapbase;
ret = ide_host_register(host, &tx4939ide_port_info, hws);
if (ret) {
ide_host_free(host);
return ret;
}
platform_set_drvdata(pdev, host);
return 0;
}
static int __exit tx4939ide_remove(struct platform_device *pdev)
{
struct ide_host *host = platform_get_drvdata(pdev);
ide_host_remove(host);
return 0;
}
static int tx4939ide_resume(struct platform_device *dev)
{
struct ide_host *host = platform_get_drvdata(dev);
ide_hwif_t *hwif = host->ports[0];
tx4939ide_init_hwif(hwif);
return 0;
}
static int __init tx4939ide_init(void)
{
return platform_driver_probe(&tx4939ide_driver, tx4939ide_probe);
}
static void __exit tx4939ide_exit(void)
{
platform_driver_unregister(&tx4939ide_driver);
}
