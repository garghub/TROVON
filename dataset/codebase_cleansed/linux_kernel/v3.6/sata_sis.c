static unsigned int get_scr_cfg_addr(struct ata_link *link, unsigned int sc_reg)
{
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
unsigned int addr = SIS_SCR_BASE + (4 * sc_reg);
u8 pmr;
if (ap->port_no) {
switch (pdev->device) {
case 0x0180:
case 0x0181:
pci_read_config_byte(pdev, SIS_PMR, &pmr);
if ((pmr & SIS_PMR_COMBINED) == 0)
addr += SIS180_SATA1_OFS;
break;
case 0x0182:
case 0x0183:
case 0x1182:
addr += SIS182_SATA1_OFS;
break;
}
}
if (link->pmp)
addr += 0x10;
return addr;
}
static u32 sis_scr_cfg_read(struct ata_link *link,
unsigned int sc_reg, u32 *val)
{
struct pci_dev *pdev = to_pci_dev(link->ap->host->dev);
unsigned int cfg_addr = get_scr_cfg_addr(link, sc_reg);
if (sc_reg == SCR_ERROR)
return -EINVAL;
pci_read_config_dword(pdev, cfg_addr, val);
return 0;
}
static int sis_scr_cfg_write(struct ata_link *link,
unsigned int sc_reg, u32 val)
{
struct pci_dev *pdev = to_pci_dev(link->ap->host->dev);
unsigned int cfg_addr = get_scr_cfg_addr(link, sc_reg);
pci_write_config_dword(pdev, cfg_addr, val);
return 0;
}
static int sis_scr_read(struct ata_link *link, unsigned int sc_reg, u32 *val)
{
struct ata_port *ap = link->ap;
void __iomem *base = ap->ioaddr.scr_addr + link->pmp * 0x10;
if (sc_reg > SCR_CONTROL)
return -EINVAL;
if (ap->flags & SIS_FLAG_CFGSCR)
return sis_scr_cfg_read(link, sc_reg, val);
*val = ioread32(base + sc_reg * 4);
return 0;
}
static int sis_scr_write(struct ata_link *link, unsigned int sc_reg, u32 val)
{
struct ata_port *ap = link->ap;
void __iomem *base = ap->ioaddr.scr_addr + link->pmp * 0x10;
if (sc_reg > SCR_CONTROL)
return -EINVAL;
if (ap->flags & SIS_FLAG_CFGSCR)
return sis_scr_cfg_write(link, sc_reg, val);
iowrite32(val, base + (sc_reg * 4));
return 0;
}
static int sis_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct ata_port_info pi = sis_port_info;
const struct ata_port_info *ppi[] = { &pi, &pi };
struct ata_host *host;
u32 genctl, val;
u8 pmr;
u8 port2_start = 0x20;
int i, rc;
ata_print_version_once(&pdev->dev, DRV_VERSION);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
pci_read_config_dword(pdev, SIS_GENCTL, &genctl);
if ((genctl & GENCTL_IOMAPPED_SCR) == 0)
pi.flags |= SIS_FLAG_CFGSCR;
if ((!(pi.flags & SIS_FLAG_CFGSCR)) &&
((pci_resource_start(pdev, SIS_SCR_PCI_BAR) == 0) ||
(pci_resource_len(pdev, SIS_SCR_PCI_BAR) < 128))) {
genctl &= ~GENCTL_IOMAPPED_SCR;
pci_write_config_dword(pdev, SIS_GENCTL, genctl);
pi.flags |= SIS_FLAG_CFGSCR;
}
pci_read_config_byte(pdev, SIS_PMR, &pmr);
switch (ent->device) {
case 0x0180:
case 0x0181:
switch (pmr & 0x30) {
case 0x10:
ppi[1] = &sis_info133_for_sata;
break;
case 0x30:
ppi[0] = &sis_info133_for_sata;
break;
}
if ((pmr & SIS_PMR_COMBINED) == 0) {
dev_info(&pdev->dev,
"Detected SiS 180/181/964 chipset in SATA mode\n");
port2_start = 64;
} else {
dev_info(&pdev->dev,
"Detected SiS 180/181 chipset in combined mode\n");
port2_start = 0;
pi.flags |= ATA_FLAG_SLAVE_POSS;
}
break;
case 0x0182:
case 0x0183:
pci_read_config_dword(pdev, 0x6C, &val);
if (val & (1L << 31)) {
dev_info(&pdev->dev, "Detected SiS 182/965 chipset\n");
pi.flags |= ATA_FLAG_SLAVE_POSS;
} else {
dev_info(&pdev->dev, "Detected SiS 182/965L chipset\n");
}
break;
case 0x1182:
dev_info(&pdev->dev,
"Detected SiS 1182/966/680 SATA controller\n");
pi.flags |= ATA_FLAG_SLAVE_POSS;
break;
case 0x1183:
dev_info(&pdev->dev,
"Detected SiS 1183/966/966L/968/680 controller in PATA mode\n");
ppi[0] = &sis_info133_for_sata;
ppi[1] = &sis_info133_for_sata;
break;
}
rc = ata_pci_bmdma_prepare_host(pdev, ppi, &host);
if (rc)
return rc;
for (i = 0; i < 2; i++) {
struct ata_port *ap = host->ports[i];
if (ap->flags & ATA_FLAG_SATA &&
ap->flags & ATA_FLAG_SLAVE_POSS) {
rc = ata_slave_link_init(ap);
if (rc)
return rc;
}
}
if (!(pi.flags & SIS_FLAG_CFGSCR)) {
void __iomem *mmio;
rc = pcim_iomap_regions(pdev, 1 << SIS_SCR_PCI_BAR, DRV_NAME);
if (rc)
return rc;
mmio = host->iomap[SIS_SCR_PCI_BAR];
host->ports[0]->ioaddr.scr_addr = mmio;
host->ports[1]->ioaddr.scr_addr = mmio + port2_start;
}
pci_set_master(pdev);
pci_intx(pdev, 1);
return ata_host_activate(host, pdev->irq, ata_bmdma_interrupt,
IRQF_SHARED, &sis_sht);
}
