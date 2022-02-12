static void cs5520_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *pdev = to_pci_dev(hwif->dev);
int controller = drive->dn > 1 ? 1 : 0;
const u8 pio = drive->pio_mode - XFER_PIO_0;
pci_write_config_byte(pdev, 0x62 + controller,
(cs5520_pio_clocks[pio].recovery << 4) |
(cs5520_pio_clocks[pio].assert));
pci_write_config_byte(pdev, 0x64 + 4*controller + (drive->dn&1),
(cs5520_pio_clocks[pio].recovery << 4) |
(cs5520_pio_clocks[pio].assert));
pci_write_config_byte(pdev, 0x66 + 4*controller + (drive->dn&1),
(cs5520_pio_clocks[pio].recovery << 4) |
(cs5520_pio_clocks[pio].assert));
}
static void cs5520_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
printk(KERN_ERR "cs55x0: bad ide timing.\n");
drive->pio_mode = XFER_PIO_0 + 0;
cs5520_set_pio_mode(hwif, drive);
}
static int __devinit cs5520_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
const struct ide_port_info *d = &cyrix_chipset;
struct ide_hw hw[2], *hws[] = { NULL, NULL };
ide_setup_pci_noise(dev, d);
if (pci_enable_device_io(dev)) {
printk(KERN_WARNING "%s: Unable to enable 55x0.\n", d->name);
return -ENODEV;
}
pci_set_master(dev);
if (pci_set_dma_mask(dev, DMA_BIT_MASK(32))) {
printk(KERN_WARNING "%s: No suitable DMA available.\n",
d->name);
return -ENODEV;
}
ide_pci_setup_ports(dev, d, &hw[0], &hws[0]);
hw[0].irq = 14;
hw[1].irq = 15;
return ide_host_add(d, hws, 2, NULL);
}
static int __init cs5520_ide_init(void)
{
return ide_pci_register_driver(&cs5520_pci_driver);
}
