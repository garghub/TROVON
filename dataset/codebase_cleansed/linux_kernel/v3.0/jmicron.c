static u8 jmicron_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *pdev = to_pci_dev(hwif->dev);
u32 control;
u32 control5;
int port = hwif->channel;
port_type port_map[2];
pci_read_config_dword(pdev, 0x40, &control);
if (control & (1 << 23)) {
port_map[0] = PORT_SATA;
port_map[1] = PORT_PATA0;
} else {
port_map[0] = PORT_SATA;
port_map[1] = PORT_SATA;
}
pci_read_config_dword(pdev, 0x80, &control5);
if (control5 & (1<<24))
port_map[0] = PORT_PATA1;
if (control & (1 << 22))
port = port ^ 1;
switch (port_map[port]) {
case PORT_PATA0:
if (control & (1 << 3))
return ATA_CBL_PATA40;
return ATA_CBL_PATA80;
case PORT_PATA1:
if (control5 & (1 << 19))
return ATA_CBL_PATA40;
return ATA_CBL_PATA80;
case PORT_SATA:
break;
}
return ATA_CBL_PATA80;
}
static void jmicron_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
}
static void jmicron_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
}
static int __devinit jmicron_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
return ide_pci_init_one(dev, &jmicron_chipset, NULL);
}
static int __init jmicron_ide_init(void)
{
return ide_pci_register_driver(&jmicron_pci_driver);
}
static void __exit jmicron_ide_exit(void)
{
pci_unregister_driver(&jmicron_pci_driver);
}
