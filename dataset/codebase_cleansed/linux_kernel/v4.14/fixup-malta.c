int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int virq;
virq = irq_tab[slot][pin];
return pci_irq[virq];
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static void malta_piix_func3_base_fixup(struct pci_dev *dev)
{
pci_write_config_word(dev, PIIX4_FUNC3_PMBA, 0x1000);
pci_write_config_byte(dev, PIIX4_FUNC3_PMREGMISC,
PIIX4_FUNC3_PMREGMISC_EN);
}
static void malta_piix_func0_fixup(struct pci_dev *pdev)
{
unsigned char reg_val;
u32 reg_val32;
u16 reg_val16;
static int piixirqmap[PIIX4_FUNC0_PIRQRC_IRQ_ROUTING_MAX] = {
0, 0, 0, 3,
4, 5, 6, 7,
0, 9, 10, 11,
12, 0, 14, 15
};
int i;
for (i = 0; i <= 3; i++) {
pci_read_config_byte(pdev, PIIX4_FUNC0_PIRQRC+i, &reg_val);
if (reg_val & PIIX4_FUNC0_PIRQRC_IRQ_ROUTING_DISABLE)
pci_irq[PCIA+i] = 0;
else
pci_irq[PCIA+i] = piixirqmap[reg_val &
PIIX4_FUNC0_PIRQRC_IRQ_ROUTING_MASK];
}
if (PCI_SLOT(pdev->devfn) == 10) {
pci_read_config_byte(pdev, PIIX4_FUNC0_TOM, &reg_val);
pci_write_config_byte(pdev, PIIX4_FUNC0_TOM, reg_val |
PIIX4_FUNC0_TOM_TOP_OF_MEMORY_MASK);
}
pci_read_config_dword(pdev, PIIX4_FUNC0_GENCFG, &reg_val32);
pci_write_config_dword(pdev, PIIX4_FUNC0_GENCFG,
reg_val32 | PIIX4_FUNC0_GENCFG_SERIRQ);
pci_read_config_byte(pdev, PIIX4_FUNC0_SERIRQC, &reg_val);
reg_val |= PIIX4_FUNC0_SERIRQC_EN | PIIX4_FUNC0_SERIRQC_CONT;
pci_write_config_byte(pdev, PIIX4_FUNC0_SERIRQC, reg_val);
pci_read_config_word(pdev, PCI_COMMAND, &reg_val16);
pci_write_config_word(pdev, PCI_COMMAND,
reg_val16 | PCI_COMMAND_SPECIAL);
}
static void malta_piix_func1_fixup(struct pci_dev *pdev)
{
unsigned char reg_val;
if (PCI_SLOT(pdev->devfn) == 10) {
pci_read_config_byte(pdev, PIIX4_FUNC1_IDETIM_PRIMARY_HI,
&reg_val);
pci_write_config_byte(pdev, PIIX4_FUNC1_IDETIM_PRIMARY_HI,
reg_val|PIIX4_FUNC1_IDETIM_PRIMARY_HI_IDE_DECODE_EN);
pci_read_config_byte(pdev, PIIX4_FUNC1_IDETIM_SECONDARY_HI,
&reg_val);
pci_write_config_byte(pdev, PIIX4_FUNC1_IDETIM_SECONDARY_HI,
reg_val|PIIX4_FUNC1_IDETIM_SECONDARY_HI_IDE_DECODE_EN);
}
}
static void quirk_dlcsetup(struct pci_dev *dev)
{
u8 odlc, ndlc;
(void) pci_read_config_byte(dev, PIIX4_FUNC0_DLC, &odlc);
ndlc = odlc | PIIX4_FUNC0_DLC_USBPR_EN |
PIIX4_FUNC0_DLC_PASSIVE_RELEASE_EN |
PIIX4_FUNC0_DLC_DELAYED_TRANSACTION_EN;
(void) pci_write_config_byte(dev, PIIX4_FUNC0_DLC, ndlc);
}
