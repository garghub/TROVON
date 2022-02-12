static unsigned short sc1200_get_pci_clock (void)
{
unsigned char chip_id, silicon_revision;
unsigned int pci_clock;
chip_id = inb (0x903c);
silicon_revision = inb (0x903d);
if (chip_id == 0x04 && silicon_revision < SC1200_REV_B1) {
pci_clock = PCI_CLK_33;
} else {
pci_clock = inw (0x901e);
pci_clock >>= 8;
pci_clock &= 0x03;
if (pci_clock == PCI_CLK_33A)
pci_clock = PCI_CLK_33;
}
return pci_clock;
}
static void sc1200_tunepio(ide_drive_t *drive, u8 pio)
{
ide_hwif_t *hwif = drive->hwif;
struct pci_dev *pdev = to_pci_dev(hwif->dev);
unsigned int basereg = hwif->channel ? 0x50 : 0x40, format = 0;
pci_read_config_dword(pdev, basereg + 4, &format);
format = (format >> 31) & 1;
if (format)
format += sc1200_get_pci_clock();
pci_write_config_dword(pdev, basereg + ((drive->dn & 1) << 3),
sc1200_pio_timings[format][pio]);
}
static u8 sc1200_udma_filter(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
ide_drive_t *mate = ide_get_pair_dev(drive);
u16 *mateid;
u8 mask = hwif->ultra_mask;
if (mate == NULL)
goto out;
mateid = mate->id;
if (ata_id_has_dma(mateid) && __ide_dma_bad_drive(mate) == 0) {
if ((mateid[ATA_ID_FIELD_VALID] & 4) &&
(mateid[ATA_ID_UDMA_MODES] & 7))
goto out;
if (mateid[ATA_ID_MWDMA_MODES] & 7)
mask = 0;
}
out:
return mask;
}
static void sc1200_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned int reg, timings;
unsigned short pci_clock;
unsigned int basereg = hwif->channel ? 0x50 : 0x40;
const u8 mode = drive->dma_mode;
static const u32 udma_timing[3][3] = {
{ 0x00921250, 0x00911140, 0x00911030 },
{ 0x00932470, 0x00922260, 0x00922140 },
{ 0x009436a1, 0x00933481, 0x00923261 },
};
static const u32 mwdma_timing[3][3] = {
{ 0x00077771, 0x00012121, 0x00002020 },
{ 0x000bbbb2, 0x00024241, 0x00013131 },
{ 0x000ffff3, 0x00035352, 0x00015151 },
};
pci_clock = sc1200_get_pci_clock();
if (mode >= XFER_UDMA_0)
timings = udma_timing[pci_clock][mode - XFER_UDMA_0];
else
timings = mwdma_timing[pci_clock][mode - XFER_MW_DMA_0];
if ((drive->dn & 1) == 0) {
pci_read_config_dword(dev, basereg + 4, &reg);
timings |= reg & 0x80000000;
pci_write_config_dword(dev, basereg + 4, timings);
} else
pci_write_config_dword(dev, basereg + 12, timings);
}
static int sc1200_dma_end(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
unsigned long dma_base = hwif->dma_base;
u8 dma_stat;
dma_stat = inb(dma_base+2);
if (!(dma_stat & 4))
printk(" ide_dma_end dma_stat=%0x err=%x newerr=%x\n",
dma_stat, ((dma_stat&7)!=4), ((dma_stat&2)==2));
outb(dma_stat|0x1b, dma_base+2);
outb(inb(dma_base)&~1, dma_base);
return (dma_stat & 7) != 4;
}
static void sc1200_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
int mode = -1;
const u8 pio = drive->pio_mode - XFER_PIO_0;
switch (pio) {
case 200: mode = XFER_UDMA_0; break;
case 201: mode = XFER_UDMA_1; break;
case 202: mode = XFER_UDMA_2; break;
case 100: mode = XFER_MW_DMA_0; break;
case 101: mode = XFER_MW_DMA_1; break;
case 102: mode = XFER_MW_DMA_2; break;
}
if (mode != -1) {
printk("SC1200: %s: changing (U)DMA mode\n", drive->name);
ide_dma_off_quietly(drive);
if (ide_set_dma_mode(drive, mode) == 0 &&
(drive->dev_flags & IDE_DFLAG_USING_DMA))
hwif->dma_ops->dma_host_set(drive, 1);
return;
}
sc1200_tunepio(drive, pio);
}
static int sc1200_suspend (struct pci_dev *dev, pm_message_t state)
{
printk("SC1200: suspend(%u)\n", state.event);
if (state.event == PM_EVENT_ON) {
struct ide_host *host = pci_get_drvdata(dev);
struct sc1200_saved_state *ss = host->host_priv;
unsigned int r;
for (r = 0; r < 8; r++)
pci_read_config_dword(dev, 0x40 + r * 4, &ss->regs[r]);
}
pci_disable_device(dev);
pci_set_power_state(dev, pci_choose_state(dev, state));
return 0;
}
static int sc1200_resume (struct pci_dev *dev)
{
struct ide_host *host = pci_get_drvdata(dev);
struct sc1200_saved_state *ss = host->host_priv;
unsigned int r;
int i;
i = pci_enable_device(dev);
if (i)
return i;
for (r = 0; r < 8; r++)
pci_write_config_dword(dev, 0x40 + r * 4, ss->regs[r]);
return 0;
}
static int sc1200_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct sc1200_saved_state *ss = NULL;
int rc;
#ifdef CONFIG_PM
ss = kmalloc(sizeof(*ss), GFP_KERNEL);
if (ss == NULL)
return -ENOMEM;
#endif
rc = ide_pci_init_one(dev, &sc1200_chipset, ss);
if (rc)
kfree(ss);
return rc;
}
static int __init sc1200_ide_init(void)
{
return ide_pci_register_driver(&sc1200_pci_driver);
}
static void __exit sc1200_ide_exit(void)
{
pci_unregister_driver(&sc1200_pci_driver);
}
