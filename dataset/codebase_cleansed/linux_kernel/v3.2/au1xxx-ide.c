static inline void auide_insw(unsigned long port, void *addr, u32 count)
{
_auide_hwif *ahwif = &auide_hwif;
chan_tab_t *ctp;
au1x_ddma_desc_t *dp;
if (!au1xxx_dbdma_put_dest(ahwif->rx_chan, virt_to_phys(addr),
count << 1, DDMA_FLAGS_NOIE)) {
printk(KERN_ERR "%s failed %d\n", __func__, __LINE__);
return;
}
ctp = *((chan_tab_t **)ahwif->rx_chan);
dp = ctp->cur_ptr;
while (dp->dscr_cmd0 & DSCR_CMD0_V)
;
ctp->cur_ptr = au1xxx_ddma_get_nextptr_virt(dp);
}
static inline void auide_outsw(unsigned long port, void *addr, u32 count)
{
_auide_hwif *ahwif = &auide_hwif;
chan_tab_t *ctp;
au1x_ddma_desc_t *dp;
if (!au1xxx_dbdma_put_source(ahwif->tx_chan, virt_to_phys(addr),
count << 1, DDMA_FLAGS_NOIE)) {
printk(KERN_ERR "%s failed %d\n", __func__, __LINE__);
return;
}
ctp = *((chan_tab_t **)ahwif->tx_chan);
dp = ctp->cur_ptr;
while (dp->dscr_cmd0 & DSCR_CMD0_V)
;
ctp->cur_ptr = au1xxx_ddma_get_nextptr_virt(dp);
}
static void au1xxx_input_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
auide_insw(drive->hwif->io_ports.data_addr, buf, (len + 1) / 2);
}
static void au1xxx_output_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
auide_outsw(drive->hwif->io_ports.data_addr, buf, (len + 1) / 2);
}
static void au1xxx_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
int mem_sttime = 0, mem_stcfg = au_readl(MEM_STCFG2);
switch (drive->pio_mode - XFER_PIO_0) {
case 0:
mem_sttime = SBC_IDE_TIMING(PIO0);
mem_stcfg |= TS_MASK;
mem_stcfg &= ~TCSOE_MASK;
mem_stcfg &= ~TOECS_MASK;
mem_stcfg |= SBC_IDE_PIO0_TCSOE | SBC_IDE_PIO0_TOECS;
break;
case 1:
mem_sttime = SBC_IDE_TIMING(PIO1);
mem_stcfg |= TS_MASK;
mem_stcfg &= ~TCSOE_MASK;
mem_stcfg &= ~TOECS_MASK;
mem_stcfg |= SBC_IDE_PIO1_TCSOE | SBC_IDE_PIO1_TOECS;
break;
case 2:
mem_sttime = SBC_IDE_TIMING(PIO2);
mem_stcfg &= ~TS_MASK;
mem_stcfg &= ~TCSOE_MASK;
mem_stcfg &= ~TOECS_MASK;
mem_stcfg |= SBC_IDE_PIO2_TCSOE | SBC_IDE_PIO2_TOECS;
break;
case 3:
mem_sttime = SBC_IDE_TIMING(PIO3);
mem_stcfg &= ~TS_MASK;
mem_stcfg &= ~TCSOE_MASK;
mem_stcfg &= ~TOECS_MASK;
mem_stcfg |= SBC_IDE_PIO3_TCSOE | SBC_IDE_PIO3_TOECS;
break;
case 4:
mem_sttime = SBC_IDE_TIMING(PIO4);
mem_stcfg &= ~TS_MASK;
mem_stcfg &= ~TCSOE_MASK;
mem_stcfg &= ~TOECS_MASK;
mem_stcfg |= SBC_IDE_PIO4_TCSOE | SBC_IDE_PIO4_TOECS;
break;
}
au_writel(mem_sttime,MEM_STTIME2);
au_writel(mem_stcfg,MEM_STCFG2);
}
static void auide_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
int mem_sttime = 0, mem_stcfg = au_readl(MEM_STCFG2);
switch (drive->dma_mode) {
#ifdef CONFIG_BLK_DEV_IDE_AU1XXX_MDMA2_DBDMA
case XFER_MW_DMA_2:
mem_sttime = SBC_IDE_TIMING(MDMA2);
mem_stcfg &= ~TS_MASK;
mem_stcfg &= ~TCSOE_MASK;
mem_stcfg &= ~TOECS_MASK;
mem_stcfg |= SBC_IDE_MDMA2_TCSOE | SBC_IDE_MDMA2_TOECS;
break;
case XFER_MW_DMA_1:
mem_sttime = SBC_IDE_TIMING(MDMA1);
mem_stcfg &= ~TS_MASK;
mem_stcfg &= ~TCSOE_MASK;
mem_stcfg &= ~TOECS_MASK;
mem_stcfg |= SBC_IDE_MDMA1_TCSOE | SBC_IDE_MDMA1_TOECS;
break;
case XFER_MW_DMA_0:
mem_sttime = SBC_IDE_TIMING(MDMA0);
mem_stcfg |= TS_MASK;
mem_stcfg &= ~TCSOE_MASK;
mem_stcfg &= ~TOECS_MASK;
mem_stcfg |= SBC_IDE_MDMA0_TCSOE | SBC_IDE_MDMA0_TOECS;
break;
#endif
}
au_writel(mem_sttime,MEM_STTIME2);
au_writel(mem_stcfg,MEM_STCFG2);
}
static int auide_build_dmatable(ide_drive_t *drive, struct ide_cmd *cmd)
{
ide_hwif_t *hwif = drive->hwif;
_auide_hwif *ahwif = &auide_hwif;
struct scatterlist *sg;
int i = cmd->sg_nents, count = 0;
int iswrite = !!(cmd->tf_flags & IDE_TFLAG_WRITE);
ahwif->drive = drive;
sg = hwif->sg_table;
while (i && sg_dma_len(sg)) {
u32 cur_addr;
u32 cur_len;
cur_addr = sg_dma_address(sg);
cur_len = sg_dma_len(sg);
while (cur_len) {
u32 flags = DDMA_FLAGS_NOIE;
unsigned int tc = (cur_len < 0xfe00)? cur_len: 0xfe00;
if (++count >= PRD_ENTRIES) {
printk(KERN_WARNING "%s: DMA table too small\n",
drive->name);
return 0;
}
if (1==i)
flags = DDMA_FLAGS_IE;
else
flags = DDMA_FLAGS_NOIE;
if (iswrite) {
if (!au1xxx_dbdma_put_source(ahwif->tx_chan,
sg_phys(sg), tc, flags)) {
printk(KERN_ERR "%s failed %d\n",
__func__, __LINE__);
}
} else {
if (!au1xxx_dbdma_put_dest(ahwif->rx_chan,
sg_phys(sg), tc, flags)) {
printk(KERN_ERR "%s failed %d\n",
__func__, __LINE__);
}
}
cur_addr += tc;
cur_len -= tc;
}
sg = sg_next(sg);
i--;
}
if (count)
return 1;
return 0;
}
static int auide_dma_end(ide_drive_t *drive)
{
return 0;
}
static void auide_dma_start(ide_drive_t *drive )
{
}
static int auide_dma_setup(ide_drive_t *drive, struct ide_cmd *cmd)
{
if (auide_build_dmatable(drive, cmd) == 0)
return 1;
return 0;
}
static int auide_dma_test_irq(ide_drive_t *drive)
{
drive->waiting_for_dma++;
if (drive->waiting_for_dma >= DMA_WAIT_TIMEOUT) {
printk(KERN_WARNING "%s: timeout waiting for ddma to complete\n",
drive->name);
return 1;
}
udelay(10);
return 0;
}
static void auide_dma_host_set(ide_drive_t *drive, int on)
{
}
static void auide_ddma_tx_callback(int irq, void *param)
{
}
static void auide_ddma_rx_callback(int irq, void *param)
{
}
static void auide_init_dbdma_dev(dbdev_tab_t *dev, u32 dev_id, u32 tsize,
u32 devwidth, u32 flags, u32 regbase)
{
dev->dev_id = dev_id;
dev->dev_physaddr = CPHYSADDR(regbase);
dev->dev_intlevel = 0;
dev->dev_intpolarity = 0;
dev->dev_tsize = tsize;
dev->dev_devwidth = devwidth;
dev->dev_flags = flags;
}
static int auide_ddma_init(ide_hwif_t *hwif, const struct ide_port_info *d)
{
_auide_hwif *auide = &auide_hwif;
dbdev_tab_t source_dev_tab, target_dev_tab;
u32 dev_id, tsize, devwidth, flags;
dev_id = hwif->ddma_id;
tsize = 8;
devwidth = 32;
#ifdef IDE_AU1XXX_BURSTMODE
flags = DEV_FLAGS_SYNC | DEV_FLAGS_BURSTABLE;
#else
flags = DEV_FLAGS_SYNC;
#endif
auide_init_dbdma_dev(&source_dev_tab, dev_id, tsize, devwidth,
DEV_FLAGS_OUT | flags, auide->regbase);
auide->tx_dev_id = au1xxx_ddma_add_device( &source_dev_tab );
auide_init_dbdma_dev(&source_dev_tab, dev_id, tsize, devwidth,
DEV_FLAGS_IN | flags, auide->regbase);
auide->rx_dev_id = au1xxx_ddma_add_device( &source_dev_tab );
auide_init_dbdma_dev(&target_dev_tab, (u32)DSCR_CMD0_ALWAYS, tsize,
devwidth, DEV_FLAGS_ANYUSE, auide->regbase);
auide->target_dev_id = au1xxx_ddma_add_device(&target_dev_tab);
auide->tx_chan = au1xxx_dbdma_chan_alloc(auide->target_dev_id,
auide->tx_dev_id,
auide_ddma_tx_callback,
(void*)auide);
auide->rx_chan = au1xxx_dbdma_chan_alloc(auide->rx_dev_id,
auide->target_dev_id,
auide_ddma_rx_callback,
(void*)auide);
auide->tx_desc_head = (void*)au1xxx_dbdma_ring_alloc(auide->tx_chan,
NUM_DESCRIPTORS);
auide->rx_desc_head = (void*)au1xxx_dbdma_ring_alloc(auide->rx_chan,
NUM_DESCRIPTORS);
(void)ide_allocate_dma_engine(hwif);
au1xxx_dbdma_start( auide->tx_chan );
au1xxx_dbdma_start( auide->rx_chan );
return 0;
}
static int auide_ddma_init(ide_hwif_t *hwif, const struct ide_port_info *d)
{
_auide_hwif *auide = &auide_hwif;
dbdev_tab_t source_dev_tab;
int flags;
#ifdef IDE_AU1XXX_BURSTMODE
flags = DEV_FLAGS_SYNC | DEV_FLAGS_BURSTABLE;
#else
flags = DEV_FLAGS_SYNC;
#endif
auide_init_dbdma_dev(&source_dev_tab, (u32)DSCR_CMD0_ALWAYS, 8, 32,
DEV_FLAGS_OUT | flags, auide->regbase);
auide->tx_dev_id = au1xxx_ddma_add_device( &source_dev_tab );
auide_init_dbdma_dev(&source_dev_tab, (u32)DSCR_CMD0_ALWAYS, 8, 32,
DEV_FLAGS_IN | flags, auide->regbase);
auide->rx_dev_id = au1xxx_ddma_add_device( &source_dev_tab );
auide->tx_chan = au1xxx_dbdma_chan_alloc(DSCR_CMD0_ALWAYS,
auide->tx_dev_id,
NULL,
(void*)auide);
auide->rx_chan = au1xxx_dbdma_chan_alloc(auide->rx_dev_id,
DSCR_CMD0_ALWAYS,
NULL,
(void*)auide);
auide->tx_desc_head = (void*)au1xxx_dbdma_ring_alloc(auide->tx_chan,
NUM_DESCRIPTORS);
auide->rx_desc_head = (void*)au1xxx_dbdma_ring_alloc(auide->rx_chan,
NUM_DESCRIPTORS);
au1xxx_dbdma_start( auide->tx_chan );
au1xxx_dbdma_start( auide->rx_chan );
return 0;
}
static void auide_setup_ports(struct ide_hw *hw, _auide_hwif *ahwif)
{
int i;
unsigned long *ata_regs = hw->io_ports_array;
for (i = 0; i < 8; i++)
*ata_regs++ = ahwif->regbase + (i << IDE_REG_SHIFT);
*ata_regs = ahwif->regbase + (14 << IDE_REG_SHIFT);
}
static int au_ide_probe(struct platform_device *dev)
{
_auide_hwif *ahwif = &auide_hwif;
struct resource *res;
struct ide_host *host;
int ret = 0;
struct ide_hw hw, *hws[] = { &hw };
#if defined(CONFIG_BLK_DEV_IDE_AU1XXX_MDMA2_DBDMA)
char *mode = "MWDMA2";
#elif defined(CONFIG_BLK_DEV_IDE_AU1XXX_PIO_DBDMA)
char *mode = "PIO+DDMA(offload)";
#endif
memset(&auide_hwif, 0, sizeof(_auide_hwif));
ahwif->irq = platform_get_irq(dev, 0);
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (res == NULL) {
pr_debug("%s %d: no base address\n", DRV_NAME, dev->id);
ret = -ENODEV;
goto out;
}
if (ahwif->irq < 0) {
pr_debug("%s %d: no IRQ\n", DRV_NAME, dev->id);
ret = -ENODEV;
goto out;
}
if (!request_mem_region(res->start, resource_size(res), dev->name)) {
pr_debug("%s: request_mem_region failed\n", DRV_NAME);
ret = -EBUSY;
goto out;
}
ahwif->regbase = (u32)ioremap(res->start, resource_size(res));
if (ahwif->regbase == 0) {
ret = -ENOMEM;
goto out;
}
res = platform_get_resource(dev, IORESOURCE_DMA, 0);
if (!res) {
pr_debug("%s: no DDMA ID resource\n", DRV_NAME);
ret = -ENODEV;
goto out;
}
ahwif->ddma_id = res->start;
memset(&hw, 0, sizeof(hw));
auide_setup_ports(&hw, ahwif);
hw.irq = ahwif->irq;
hw.dev = &dev->dev;
ret = ide_host_add(&au1xxx_port_info, hws, 1, &host);
if (ret)
goto out;
auide_hwif.hwif = host->ports[0];
platform_set_drvdata(dev, host);
printk(KERN_INFO "Au1xxx IDE(builtin) configured for %s\n", mode );
out:
return ret;
}
static int au_ide_remove(struct platform_device *dev)
{
struct resource *res;
struct ide_host *host = platform_get_drvdata(dev);
_auide_hwif *ahwif = &auide_hwif;
ide_host_remove(host);
iounmap((void *)ahwif->regbase);
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
return 0;
}
static int __init au_ide_init(void)
{
return platform_driver_register(&au1200_ide_driver);
}
static void __exit au_ide_exit(void)
{
platform_driver_unregister(&au1200_ide_driver);
}
