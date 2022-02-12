static unsigned int get_scr_cfg_addr(struct ata_port *ap, unsigned int sc_reg)
{
struct uli_priv *hpriv = ap->host->private_data;
return hpriv->scr_cfg_addr[ap->port_no] + (4 * sc_reg);
}
static u32 uli_scr_cfg_read(struct ata_link *link, unsigned int sc_reg)
{
struct pci_dev *pdev = to_pci_dev(link->ap->host->dev);
unsigned int cfg_addr = get_scr_cfg_addr(link->ap, sc_reg);
u32 val;
pci_read_config_dword(pdev, cfg_addr, &val);
return val;
}
static void uli_scr_cfg_write(struct ata_link *link, unsigned int scr, u32 val)
{
struct pci_dev *pdev = to_pci_dev(link->ap->host->dev);
unsigned int cfg_addr = get_scr_cfg_addr(link->ap, scr);
pci_write_config_dword(pdev, cfg_addr, val);
}
static int uli_scr_read(struct ata_link *link, unsigned int sc_reg, u32 *val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
*val = uli_scr_cfg_read(link, sc_reg);
return 0;
}
static int uli_scr_write(struct ata_link *link, unsigned int sc_reg, u32 val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
uli_scr_cfg_write(link, sc_reg, val);
return 0;
}
static int uli_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
const struct ata_port_info *ppi[] = { &uli_port_info, NULL };
unsigned int board_idx = (unsigned int) ent->driver_data;
struct ata_host *host;
struct uli_priv *hpriv;
void __iomem * const *iomap;
struct ata_ioports *ioaddr;
int n_ports, rc;
ata_print_version_once(&pdev->dev, DRV_VERSION);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
n_ports = 2;
if (board_idx == uli_5287)
n_ports = 4;
host = ata_host_alloc_pinfo(&pdev->dev, ppi, n_ports);
if (!host)
return -ENOMEM;
hpriv = devm_kzalloc(&pdev->dev, sizeof(*hpriv), GFP_KERNEL);
if (!hpriv)
return -ENOMEM;
host->private_data = hpriv;
rc = ata_pci_sff_init_host(host);
if (rc)
return rc;
ata_pci_bmdma_init(host);
iomap = host->iomap;
switch (board_idx) {
case uli_5287:
hpriv->scr_cfg_addr[0] = ULI5287_BASE;
hpriv->scr_cfg_addr[1] = ULI5287_BASE + ULI5287_OFFS;
ioaddr = &host->ports[2]->ioaddr;
ioaddr->cmd_addr = iomap[0] + 8;
ioaddr->altstatus_addr =
ioaddr->ctl_addr = (void __iomem *)
((unsigned long)iomap[1] | ATA_PCI_CTL_OFS) + 4;
ioaddr->bmdma_addr = iomap[4] + 16;
hpriv->scr_cfg_addr[2] = ULI5287_BASE + ULI5287_OFFS*4;
ata_sff_std_ports(ioaddr);
ata_port_desc(host->ports[2],
"cmd 0x%llx ctl 0x%llx bmdma 0x%llx",
(unsigned long long)pci_resource_start(pdev, 0) + 8,
((unsigned long long)pci_resource_start(pdev, 1) | ATA_PCI_CTL_OFS) + 4,
(unsigned long long)pci_resource_start(pdev, 4) + 16);
ioaddr = &host->ports[3]->ioaddr;
ioaddr->cmd_addr = iomap[2] + 8;
ioaddr->altstatus_addr =
ioaddr->ctl_addr = (void __iomem *)
((unsigned long)iomap[3] | ATA_PCI_CTL_OFS) + 4;
ioaddr->bmdma_addr = iomap[4] + 24;
hpriv->scr_cfg_addr[3] = ULI5287_BASE + ULI5287_OFFS*5;
ata_sff_std_ports(ioaddr);
ata_port_desc(host->ports[2],
"cmd 0x%llx ctl 0x%llx bmdma 0x%llx",
(unsigned long long)pci_resource_start(pdev, 2) + 9,
((unsigned long long)pci_resource_start(pdev, 3) | ATA_PCI_CTL_OFS) + 4,
(unsigned long long)pci_resource_start(pdev, 4) + 24);
break;
case uli_5289:
hpriv->scr_cfg_addr[0] = ULI5287_BASE;
hpriv->scr_cfg_addr[1] = ULI5287_BASE + ULI5287_OFFS;
break;
case uli_5281:
hpriv->scr_cfg_addr[0] = ULI5281_BASE;
hpriv->scr_cfg_addr[1] = ULI5281_BASE + ULI5281_OFFS;
break;
default:
BUG();
break;
}
pci_set_master(pdev);
pci_intx(pdev, 1);
return ata_host_activate(host, pdev->irq, ata_bmdma_interrupt,
IRQF_SHARED, &uli_sht);
}
