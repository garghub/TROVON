static int piix_port_start(struct ata_port *ap)
{
if (!(ap->flags & PIIX_FLAG_PIO16))
ap->pflags |= ATA_PFLAG_PIO32 | ATA_PFLAG_PIO32CHANGE;
return ata_bmdma_port_start(ap);
}
static int ich_pata_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct piix_host_priv *hpriv = ap->host->private_data;
const struct ich_laptop *lap = &ich_laptop[0];
u8 mask;
while (lap->device) {
if (lap->device == pdev->device &&
lap->subvendor == pdev->subsystem_vendor &&
lap->subdevice == pdev->subsystem_device)
return ATA_CBL_PATA40_SHORT;
lap++;
}
mask = ap->port_no == 0 ? PIIX_80C_PRI : PIIX_80C_SEC;
if ((hpriv->saved_iocfg & mask) == 0)
return ATA_CBL_PATA40;
return ATA_CBL_PATA80;
}
static int piix_pata_prereset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (!pci_test_config_bits(pdev, &piix_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static void piix_set_timings(struct ata_port *ap, struct ata_device *adev,
u8 pio)
{
struct pci_dev *dev = to_pci_dev(ap->host->dev);
unsigned long flags;
unsigned int is_slave = (adev->devno != 0);
unsigned int master_port= ap->port_no ? 0x42 : 0x40;
unsigned int slave_port = 0x44;
u16 master_data;
u8 slave_data;
u8 udma_enable;
int control = 0;
static const
u8 timings[][2] = { { 0, 0 },
{ 0, 0 },
{ 1, 0 },
{ 2, 1 },
{ 2, 3 }, };
if (pio >= 2)
control |= 1;
if (ata_pio_need_iordy(adev))
control |= 2;
if (adev->class == ATA_DEV_ATA)
control |= 4;
if (adev->pio_mode < XFER_PIO_0 + pio)
control |= 8;
spin_lock_irqsave(&piix_lock, flags);
pci_read_config_word(dev, master_port, &master_data);
if (is_slave) {
master_data &= 0xff0f;
master_data |= (control << 4);
pci_read_config_byte(dev, slave_port, &slave_data);
slave_data &= (ap->port_no ? 0x0f : 0xf0);
slave_data |= ((timings[pio][0] << 2) | timings[pio][1])
<< (ap->port_no ? 4 : 0);
} else {
master_data &= 0xccf0;
master_data |= control;
master_data |=
(timings[pio][0] << 12) |
(timings[pio][1] << 8);
}
master_data |= 0x4000;
pci_write_config_word(dev, master_port, master_data);
if (is_slave)
pci_write_config_byte(dev, slave_port, slave_data);
if (ap->udma_mask) {
pci_read_config_byte(dev, 0x48, &udma_enable);
udma_enable &= ~(1 << (2 * ap->port_no + adev->devno));
pci_write_config_byte(dev, 0x48, udma_enable);
}
spin_unlock_irqrestore(&piix_lock, flags);
}
static void piix_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
piix_set_timings(ap, adev, adev->pio_mode - XFER_PIO_0);
}
static void do_pata_set_dmamode(struct ata_port *ap, struct ata_device *adev, int isich)
{
struct pci_dev *dev = to_pci_dev(ap->host->dev);
unsigned long flags;
u8 speed = adev->dma_mode;
int devid = adev->devno + 2 * ap->port_no;
u8 udma_enable = 0;
if (speed >= XFER_UDMA_0) {
unsigned int udma = speed - XFER_UDMA_0;
u16 udma_timing;
u16 ideconf;
int u_clock, u_speed;
spin_lock_irqsave(&piix_lock, flags);
pci_read_config_byte(dev, 0x48, &udma_enable);
u_speed = min(2 - (udma & 1), udma);
if (udma == 5)
u_clock = 0x1000;
else if (udma > 2)
u_clock = 1;
else
u_clock = 0;
udma_enable |= (1 << devid);
pci_read_config_word(dev, 0x4A, &udma_timing);
udma_timing &= ~(3 << (4 * devid));
udma_timing |= u_speed << (4 * devid);
pci_write_config_word(dev, 0x4A, udma_timing);
if (isich) {
pci_read_config_word(dev, 0x54, &ideconf);
ideconf &= ~(0x1001 << devid);
ideconf |= u_clock << devid;
pci_write_config_word(dev, 0x54, ideconf);
}
pci_write_config_byte(dev, 0x48, udma_enable);
spin_unlock_irqrestore(&piix_lock, flags);
} else {
unsigned int mwdma = speed - XFER_MW_DMA_0;
const unsigned int needed_pio[3] = {
XFER_PIO_0, XFER_PIO_3, XFER_PIO_4
};
int pio = needed_pio[mwdma] - XFER_PIO_0;
piix_set_timings(ap, adev, pio);
}
}
static void piix_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
do_pata_set_dmamode(ap, adev, 0);
}
static void ich_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
do_pata_set_dmamode(ap, adev, 1);
}
static void piix_sidpr_sel(struct ata_link *link, unsigned int reg)
{
struct ata_port *ap = link->ap;
struct piix_host_priv *hpriv = ap->host->private_data;
iowrite32(((ap->port_no * 2 + link->pmp) << 8) | piix_sidx_map[reg],
hpriv->sidpr + PIIX_SIDPR_IDX);
}
static int piix_sidpr_scr_read(struct ata_link *link,
unsigned int reg, u32 *val)
{
struct piix_host_priv *hpriv = link->ap->host->private_data;
if (reg >= ARRAY_SIZE(piix_sidx_map))
return -EINVAL;
piix_sidpr_sel(link, reg);
*val = ioread32(hpriv->sidpr + PIIX_SIDPR_DATA);
return 0;
}
static int piix_sidpr_scr_write(struct ata_link *link,
unsigned int reg, u32 val)
{
struct piix_host_priv *hpriv = link->ap->host->private_data;
if (reg >= ARRAY_SIZE(piix_sidx_map))
return -EINVAL;
piix_sidpr_sel(link, reg);
iowrite32(val, hpriv->sidpr + PIIX_SIDPR_DATA);
return 0;
}
static int piix_sidpr_set_lpm(struct ata_link *link, enum ata_lpm_policy policy,
unsigned hints)
{
return sata_link_scr_lpm(link, policy, false);
}
static bool piix_irq_check(struct ata_port *ap)
{
if (unlikely(!ap->ioaddr.bmdma_addr))
return false;
return ap->ops->bmdma_status(ap) & ATA_DMA_INTR;
}
static int piix_broken_suspend(void)
{
static const struct dmi_system_id sysids[] = {
{
.ident = "TECRA M3",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "TECRA M3"),
},
},
{
.ident = "TECRA M3",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "Tecra M3"),
},
},
{
.ident = "TECRA M4",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "Tecra M4"),
},
},
{
.ident = "TECRA M4",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "TECRA M4"),
},
},
{
.ident = "TECRA M5",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "TECRA M5"),
},
},
{
.ident = "TECRA M6",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "TECRA M6"),
},
},
{
.ident = "TECRA M7",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "TECRA M7"),
},
},
{
.ident = "TECRA A8",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "TECRA A8"),
},
},
{
.ident = "Satellite R20",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "Satellite R20"),
},
},
{
.ident = "Satellite R25",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "Satellite R25"),
},
},
{
.ident = "Satellite U200",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "Satellite U200"),
},
},
{
.ident = "Satellite U200",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "SATELLITE U200"),
},
},
{
.ident = "Satellite Pro U200",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "SATELLITE PRO U200"),
},
},
{
.ident = "Satellite U205",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "Satellite U205"),
},
},
{
.ident = "SATELLITE U205",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "SATELLITE U205"),
},
},
{
.ident = "Satellite Pro A120",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "Satellite Pro A120"),
},
},
{
.ident = "Portege M500",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
DMI_MATCH(DMI_PRODUCT_NAME, "PORTEGE M500"),
},
},
{
.ident = "VGN-BX297XP",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Sony Corporation"),
DMI_MATCH(DMI_PRODUCT_NAME, "VGN-BX297XP"),
},
},
{ }
};
static const char *oemstrs[] = {
"Tecra M3,",
};
int i;
if (dmi_check_system(sysids))
return 1;
for (i = 0; i < ARRAY_SIZE(oemstrs); i++)
if (dmi_find_device(DMI_DEV_TYPE_OEM_STRING, oemstrs[i], NULL))
return 1;
if (dmi_match(DMI_SYS_VENDOR, "TOSHIBA") &&
dmi_match(DMI_PRODUCT_NAME, "000000") &&
dmi_match(DMI_PRODUCT_VERSION, "000000") &&
dmi_match(DMI_PRODUCT_SERIAL, "000000") &&
dmi_match(DMI_BOARD_VENDOR, "TOSHIBA") &&
dmi_match(DMI_BOARD_NAME, "Portable PC") &&
dmi_match(DMI_BOARD_VERSION, "Version A0"))
return 1;
return 0;
}
static int piix_pci_device_suspend(struct pci_dev *pdev, pm_message_t mesg)
{
struct ata_host *host = pci_get_drvdata(pdev);
unsigned long flags;
int rc = 0;
rc = ata_host_suspend(host, mesg);
if (rc)
return rc;
if (piix_broken_suspend() && (mesg.event & PM_EVENT_SLEEP)) {
pci_save_state(pdev);
if (pdev->current_state == PCI_D0)
pdev->current_state = PCI_UNKNOWN;
spin_lock_irqsave(&host->lock, flags);
host->flags |= PIIX_HOST_BROKEN_SUSPEND;
spin_unlock_irqrestore(&host->lock, flags);
} else
ata_pci_device_do_suspend(pdev, mesg);
return 0;
}
static int piix_pci_device_resume(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
unsigned long flags;
int rc;
if (host->flags & PIIX_HOST_BROKEN_SUSPEND) {
spin_lock_irqsave(&host->lock, flags);
host->flags &= ~PIIX_HOST_BROKEN_SUSPEND;
spin_unlock_irqrestore(&host->lock, flags);
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
rc = pci_reenable_device(pdev);
if (rc)
dev_err(&pdev->dev,
"failed to enable device after resume (%d)\n",
rc);
} else
rc = ata_pci_device_do_resume(pdev);
if (rc == 0)
ata_host_resume(host);
return rc;
}
static u8 piix_vmw_bmdma_status(struct ata_port *ap)
{
return ata_bmdma_status(ap) & ~ATA_DMA_ERR;
}
static int piix_disable_ahci(struct pci_dev *pdev)
{
void __iomem *mmio;
u32 tmp;
int rc = 0;
if (!pci_resource_start(pdev, AHCI_PCI_BAR) ||
!pci_resource_len(pdev, AHCI_PCI_BAR))
return 0;
mmio = pci_iomap(pdev, AHCI_PCI_BAR, 64);
if (!mmio)
return -ENOMEM;
tmp = ioread32(mmio + AHCI_GLOBAL_CTL);
if (tmp & AHCI_ENABLE) {
tmp &= ~AHCI_ENABLE;
iowrite32(tmp, mmio + AHCI_GLOBAL_CTL);
tmp = ioread32(mmio + AHCI_GLOBAL_CTL);
if (tmp & AHCI_ENABLE)
rc = -EIO;
}
pci_iounmap(pdev, mmio);
return rc;
}
static int piix_check_450nx_errata(struct pci_dev *ata_dev)
{
struct pci_dev *pdev = NULL;
u16 cfg;
int no_piix_dma = 0;
while ((pdev = pci_get_device(PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTEL_82454NX, pdev)) != NULL) {
pci_read_config_word(pdev, 0x41, &cfg);
if (pdev->revision == 0x00)
no_piix_dma = 1;
else if (cfg & (1<<14) && pdev->revision < 5)
no_piix_dma = 2;
}
if (no_piix_dma)
dev_warn(&ata_dev->dev,
"450NX errata present, disabling IDE DMA%s\n",
no_piix_dma == 2 ? " - a BIOS update may resolve this"
: "");
return no_piix_dma;
}
static void piix_init_pcs(struct ata_host *host,
const struct piix_map_db *map_db)
{
struct pci_dev *pdev = to_pci_dev(host->dev);
u16 pcs, new_pcs;
pci_read_config_word(pdev, ICH5_PCS, &pcs);
new_pcs = pcs | map_db->port_enable;
if (new_pcs != pcs) {
DPRINTK("updating PCS from 0x%x to 0x%x\n", pcs, new_pcs);
pci_write_config_word(pdev, ICH5_PCS, new_pcs);
msleep(150);
}
}
static const int *piix_init_sata_map(struct pci_dev *pdev,
struct ata_port_info *pinfo,
const struct piix_map_db *map_db)
{
const int *map;
int i, invalid_map = 0;
u8 map_value;
char buf[32];
char *p = buf, *end = buf + sizeof(buf);
pci_read_config_byte(pdev, ICH5_PMR, &map_value);
map = map_db->map[map_value & map_db->mask];
for (i = 0; i < 4; i++) {
switch (map[i]) {
case RV:
invalid_map = 1;
p += scnprintf(p, end - p, " XX");
break;
case NA:
p += scnprintf(p, end - p, " --");
break;
case IDE:
WARN_ON((i & 1) || map[i + 1] != IDE);
pinfo[i / 2] = piix_port_info[ich_pata_100];
i++;
p += scnprintf(p, end - p, " IDE IDE");
break;
default:
p += scnprintf(p, end - p, " P%d", map[i]);
if (i & 1)
pinfo[i / 2].flags |= ATA_FLAG_SLAVE_POSS;
break;
}
}
dev_info(&pdev->dev, "MAP [%s ]\n", buf);
if (invalid_map)
dev_err(&pdev->dev, "invalid MAP value %u\n", map_value);
return map;
}
static bool piix_no_sidpr(struct ata_host *host)
{
struct pci_dev *pdev = to_pci_dev(host->dev);
if (pdev->vendor == PCI_VENDOR_ID_INTEL && pdev->device == 0x2920 &&
pdev->subsystem_vendor == PCI_VENDOR_ID_SAMSUNG &&
pdev->subsystem_device == 0xb049) {
dev_warn(host->dev,
"Samsung DB-P70 detected, disabling SIDPR\n");
return true;
}
return false;
}
static int piix_init_sidpr(struct ata_host *host)
{
struct pci_dev *pdev = to_pci_dev(host->dev);
struct piix_host_priv *hpriv = host->private_data;
struct ata_link *link0 = &host->ports[0]->link;
u32 scontrol;
int i, rc;
for (i = 0; i < 4; i++)
if (hpriv->map[i] == IDE)
return 0;
if (piix_no_sidpr(host))
return 0;
if (!(host->ports[0]->flags & PIIX_FLAG_SIDPR))
return 0;
if (pci_resource_start(pdev, PIIX_SIDPR_BAR) == 0 ||
pci_resource_len(pdev, PIIX_SIDPR_BAR) != PIIX_SIDPR_LEN)
return 0;
if (pcim_iomap_regions(pdev, 1 << PIIX_SIDPR_BAR, DRV_NAME))
return 0;
hpriv->sidpr = pcim_iomap_table(pdev)[PIIX_SIDPR_BAR];
piix_sidpr_scr_read(link0, SCR_CONTROL, &scontrol);
if ((scontrol & 0xf00) != 0x300) {
scontrol |= 0x300;
piix_sidpr_scr_write(link0, SCR_CONTROL, scontrol);
piix_sidpr_scr_read(link0, SCR_CONTROL, &scontrol);
if ((scontrol & 0xf00) != 0x300) {
dev_info(host->dev,
"SCR access via SIDPR is available but doesn't work\n");
return 0;
}
}
for (i = 0; i < 2; i++) {
struct ata_port *ap = host->ports[i];
ap->ops = &piix_sidpr_sata_ops;
if (ap->flags & ATA_FLAG_SLAVE_POSS) {
rc = ata_slave_link_init(ap);
if (rc)
return rc;
}
}
return 0;
}
static void piix_iocfg_bit18_quirk(struct ata_host *host)
{
static const struct dmi_system_id sysids[] = {
{
.ident = "M570U",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Clevo Co."),
DMI_MATCH(DMI_PRODUCT_NAME, "M570U"),
},
},
{ }
};
struct pci_dev *pdev = to_pci_dev(host->dev);
struct piix_host_priv *hpriv = host->private_data;
if (!dmi_check_system(sysids))
return;
if (hpriv->saved_iocfg & (1 << 18)) {
dev_info(&pdev->dev, "applying IOCFG bit18 quirk\n");
pci_write_config_dword(pdev, PIIX_IOCFG,
hpriv->saved_iocfg & ~(1 << 18));
}
}
static bool piix_broken_system_poweroff(struct pci_dev *pdev)
{
static const struct dmi_system_id broken_systems[] = {
{
.ident = "HP Compaq 2510p",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
DMI_MATCH(DMI_PRODUCT_NAME, "HP Compaq 2510p"),
},
.driver_data = (void *)0x1FUL,
},
{
.ident = "HP Compaq nc6000",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
DMI_MATCH(DMI_PRODUCT_NAME, "HP Compaq nc6000"),
},
.driver_data = (void *)0x1FUL,
},
{ }
};
const struct dmi_system_id *dmi = dmi_first_match(broken_systems);
if (dmi) {
unsigned long slot = (unsigned long)dmi->driver_data;
return slot == PCI_SLOT(pdev->devfn);
}
return false;
}
static void piix_ignore_devices_quirk(struct ata_host *host)
{
#if IS_ENABLED(CONFIG_HYPERV_STORAGE)
static const struct dmi_system_id ignore_hyperv[] = {
{
.ident = "Hyper-V Virtual Machine",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR,
"Microsoft Corporation"),
DMI_MATCH(DMI_PRODUCT_NAME, "Virtual Machine"),
},
},
{ }
};
static const struct dmi_system_id allow_virtual_pc[] = {
{
.ident = "MS Virtual PC 2007",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR,
"Microsoft Corporation"),
DMI_MATCH(DMI_PRODUCT_NAME, "Virtual Machine"),
DMI_MATCH(DMI_PRODUCT_VERSION, "VS2005R2"),
},
},
{ }
};
const struct dmi_system_id *ignore = dmi_first_match(ignore_hyperv);
const struct dmi_system_id *allow = dmi_first_match(allow_virtual_pc);
if (ignore && !allow && prefer_ms_hyperv) {
host->flags |= ATA_HOST_IGNORE_ATA;
dev_info(host->dev, "%s detected, ATA device ignore set\n",
ignore->ident);
}
#endif
}
static int piix_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct device *dev = &pdev->dev;
struct ata_port_info port_info[2];
const struct ata_port_info *ppi[] = { &port_info[0], &port_info[1] };
struct scsi_host_template *sht = &piix_sht;
unsigned long port_flags;
struct ata_host *host;
struct piix_host_priv *hpriv;
int rc;
ata_print_version_once(&pdev->dev, DRV_VERSION);
if (!in_module_init && ent->driver_data >= ich5_sata)
return -ENODEV;
if (piix_broken_system_poweroff(pdev)) {
piix_port_info[ent->driver_data].flags |=
ATA_FLAG_NO_POWEROFF_SPINDOWN |
ATA_FLAG_NO_HIBERNATE_SPINDOWN;
dev_info(&pdev->dev, "quirky BIOS, skipping spindown "
"on poweroff and hibernation\n");
}
port_info[0] = piix_port_info[ent->driver_data];
port_info[1] = piix_port_info[ent->driver_data];
port_flags = port_info[0].flags;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
hpriv = devm_kzalloc(dev, sizeof(*hpriv), GFP_KERNEL);
if (!hpriv)
return -ENOMEM;
pci_read_config_dword(pdev, PIIX_IOCFG, &hpriv->saved_iocfg);
if (pdev->vendor == PCI_VENDOR_ID_INTEL && pdev->device == 0x2652) {
rc = piix_disable_ahci(pdev);
if (rc)
return rc;
}
if (port_flags & ATA_FLAG_SATA)
hpriv->map = piix_init_sata_map(pdev, port_info,
piix_map_db_table[ent->driver_data]);
rc = ata_pci_bmdma_prepare_host(pdev, ppi, &host);
if (rc)
return rc;
host->private_data = hpriv;
if (port_flags & ATA_FLAG_SATA) {
piix_init_pcs(host, piix_map_db_table[ent->driver_data]);
rc = piix_init_sidpr(host);
if (rc)
return rc;
if (host->ports[0]->ops == &piix_sidpr_sata_ops)
sht = &piix_sidpr_sht;
}
piix_iocfg_bit18_quirk(host);
if (port_flags & PIIX_FLAG_CHECKINTR)
pci_intx(pdev, 1);
if (piix_check_450nx_errata(pdev)) {
host->ports[0]->mwdma_mask = 0;
host->ports[0]->udma_mask = 0;
host->ports[1]->mwdma_mask = 0;
host->ports[1]->udma_mask = 0;
}
host->flags |= ATA_HOST_PARALLEL_SCAN;
piix_ignore_devices_quirk(host);
pci_set_master(pdev);
return ata_pci_sff_activate_host(host, ata_bmdma_interrupt, sht);
}
static void piix_remove_one(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
struct piix_host_priv *hpriv = host->private_data;
pci_write_config_dword(pdev, PIIX_IOCFG, hpriv->saved_iocfg);
ata_pci_remove_one(pdev);
}
static int __init piix_init(void)
{
int rc;
DPRINTK("pci_register_driver\n");
rc = pci_register_driver(&piix_pci_driver);
if (rc)
return rc;
in_module_init = 0;
DPRINTK("done\n");
return 0;
}
static void __exit piix_exit(void)
{
pci_unregister_driver(&piix_pci_driver);
}
