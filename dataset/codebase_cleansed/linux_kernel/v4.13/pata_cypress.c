static void cy82c693_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct ata_timing t;
const unsigned long T = 1000000 / 33;
short time_16, time_8;
u32 addr;
if (ata_timing_compute(adev, adev->pio_mode, &t, T, 1) < 0) {
printk(KERN_ERR DRV_NAME ": mome computation failed.\n");
return;
}
time_16 = clamp_val(t.recover - 1, 0, 15) |
(clamp_val(t.active - 1, 0, 15) << 4);
time_8 = clamp_val(t.act8b - 1, 0, 15) |
(clamp_val(t.rec8b - 1, 0, 15) << 4);
if (adev->devno == 0) {
pci_read_config_dword(pdev, CY82_IDE_ADDRSETUP, &addr);
addr &= ~0x0F;
addr |= clamp_val(t.setup - 1, 0, 15);
pci_write_config_dword(pdev, CY82_IDE_ADDRSETUP, addr);
pci_write_config_byte(pdev, CY82_IDE_MASTER_IOR, time_16);
pci_write_config_byte(pdev, CY82_IDE_MASTER_IOW, time_16);
pci_write_config_byte(pdev, CY82_IDE_MASTER_8BIT, time_8);
} else {
pci_read_config_dword(pdev, CY82_IDE_ADDRSETUP, &addr);
addr &= ~0xF0;
addr |= (clamp_val(t.setup - 1, 0, 15) << 4);
pci_write_config_dword(pdev, CY82_IDE_ADDRSETUP, addr);
pci_write_config_byte(pdev, CY82_IDE_SLAVE_IOR, time_16);
pci_write_config_byte(pdev, CY82_IDE_SLAVE_IOW, time_16);
pci_write_config_byte(pdev, CY82_IDE_SLAVE_8BIT, time_8);
}
}
static void cy82c693_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
int reg = CY82_INDEX_CHANNEL0 + ap->port_no;
outb(reg, 0x22);
outb(adev->dma_mode - XFER_MW_DMA_0, 0x23);
outb(CY82_INDEX_TIMEOUT, 0x22);
outb(0x50, 0x23);
}
static int cy82c693_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &cy82c693_port_ops
};
const struct ata_port_info *ppi[] = { &info, &ata_dummy_port_info };
if (PCI_FUNC(pdev->devfn) != 1)
return -ENODEV;
return ata_pci_bmdma_init_one(pdev, ppi, &cy82c693_sht, NULL, 0);
}
