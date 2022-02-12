static void ahci_pci_save_initial_config(struct pci_dev *pdev,
struct ahci_host_priv *hpriv)
{
unsigned int force_port_map = 0;
unsigned int mask_port_map = 0;
if (pdev->vendor == PCI_VENDOR_ID_JMICRON && pdev->device == 0x2361) {
dev_info(&pdev->dev, "JMB361 has only one port\n");
force_port_map = 1;
}
if (hpriv->flags & AHCI_HFLAG_MV_PATA) {
if (pdev->device == 0x6121)
mask_port_map = 0x3;
else
mask_port_map = 0xf;
dev_info(&pdev->dev,
"Disabling your PATA port. Use the boot option 'ahci.marvell_enable=0' to avoid this.\n");
}
ahci_save_initial_config(&pdev->dev, hpriv, force_port_map,
mask_port_map);
}
static int ahci_pci_reset_controller(struct ata_host *host)
{
struct pci_dev *pdev = to_pci_dev(host->dev);
ahci_reset_controller(host);
if (pdev->vendor == PCI_VENDOR_ID_INTEL) {
struct ahci_host_priv *hpriv = host->private_data;
u16 tmp16;
pci_read_config_word(pdev, 0x92, &tmp16);
if ((tmp16 & hpriv->port_map) != hpriv->port_map) {
tmp16 |= hpriv->port_map;
pci_write_config_word(pdev, 0x92, tmp16);
}
}
return 0;
}
static void ahci_pci_init_controller(struct ata_host *host)
{
struct ahci_host_priv *hpriv = host->private_data;
struct pci_dev *pdev = to_pci_dev(host->dev);
void __iomem *port_mmio;
u32 tmp;
int mv;
if (hpriv->flags & AHCI_HFLAG_MV_PATA) {
if (pdev->device == 0x6121)
mv = 2;
else
mv = 4;
port_mmio = __ahci_port_base(host, mv);
writel(0, port_mmio + PORT_IRQ_MASK);
tmp = readl(port_mmio + PORT_IRQ_STAT);
VPRINTK("PORT_IRQ_STAT 0x%x\n", tmp);
if (tmp)
writel(tmp, port_mmio + PORT_IRQ_STAT);
}
ahci_init_controller(host);
}
static int ahci_vt8251_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
bool online;
int rc;
DPRINTK("ENTER\n");
ahci_stop_engine(ap);
rc = sata_link_hardreset(link, sata_ehc_deb_timing(&link->eh_context),
deadline, &online, NULL);
ahci_start_engine(ap);
DPRINTK("EXIT, rc=%d, class=%u\n", rc, *class);
return online ? -EAGAIN : rc;
}
static int ahci_p5wdh_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct ahci_port_priv *pp = ap->private_data;
u8 *d2h_fis = pp->rx_fis + RX_FIS_D2H_REG;
struct ata_taskfile tf;
bool online;
int rc;
ahci_stop_engine(ap);
ata_tf_init(link->device, &tf);
tf.command = ATA_BUSY;
ata_tf_to_fis(&tf, 0, 0, d2h_fis);
rc = sata_link_hardreset(link, sata_ehc_deb_timing(&link->eh_context),
deadline, &online, NULL);
ahci_start_engine(ap);
if (online) {
rc = ata_wait_after_reset(link, jiffies + 2 * HZ,
ahci_check_ready);
if (rc)
ahci_kick_engine(ap);
}
return rc;
}
static int ahci_pci_device_suspend(struct pci_dev *pdev, pm_message_t mesg)
{
struct ata_host *host = pci_get_drvdata(pdev);
struct ahci_host_priv *hpriv = host->private_data;
void __iomem *mmio = hpriv->mmio;
u32 ctl;
if (mesg.event & PM_EVENT_SUSPEND &&
hpriv->flags & AHCI_HFLAG_NO_SUSPEND) {
dev_err(&pdev->dev,
"BIOS update required for suspend/resume\n");
return -EIO;
}
if (mesg.event & PM_EVENT_SLEEP) {
ctl = readl(mmio + HOST_CTL);
ctl &= ~HOST_IRQ_EN;
writel(ctl, mmio + HOST_CTL);
readl(mmio + HOST_CTL);
}
return ata_pci_device_suspend(pdev, mesg);
}
static int ahci_pci_device_resume(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
if (pdev->dev.power.power_state.event == PM_EVENT_SUSPEND) {
rc = ahci_pci_reset_controller(host);
if (rc)
return rc;
ahci_pci_init_controller(host);
}
ata_host_resume(host);
return 0;
}
static int ahci_configure_dma_masks(struct pci_dev *pdev, int using_dac)
{
int rc;
if (pdev->dma_mask && pdev->dma_mask < DMA_BIT_MASK(32))
return 0;
if (using_dac &&
!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (rc) {
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev,
"64-bit DMA enable failed\n");
return rc;
}
}
} else {
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev, "32-bit DMA enable failed\n");
return rc;
}
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev,
"32-bit consistent DMA enable failed\n");
return rc;
}
}
return 0;
}
static void ahci_pci_print_info(struct ata_host *host)
{
struct pci_dev *pdev = to_pci_dev(host->dev);
u16 cc;
const char *scc_s;
pci_read_config_word(pdev, 0x0a, &cc);
if (cc == PCI_CLASS_STORAGE_IDE)
scc_s = "IDE";
else if (cc == PCI_CLASS_STORAGE_SATA)
scc_s = "SATA";
else if (cc == PCI_CLASS_STORAGE_RAID)
scc_s = "RAID";
else
scc_s = "unknown";
ahci_print_info(host, scc_s);
}
static void ahci_p5wdh_workaround(struct ata_host *host)
{
static struct dmi_system_id sysids[] = {
{
.ident = "P5W DH Deluxe",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR,
"ASUSTEK COMPUTER INC"),
DMI_MATCH(DMI_PRODUCT_NAME, "P5W DH Deluxe"),
},
},
{ }
};
struct pci_dev *pdev = to_pci_dev(host->dev);
if (pdev->bus->number == 0 && pdev->devfn == PCI_DEVFN(0x1f, 2) &&
dmi_check_system(sysids)) {
struct ata_port *ap = host->ports[1];
dev_info(&pdev->dev,
"enabling ASUS P5W DH Deluxe on-board SIMG4726 workaround\n");
ap->ops = &ahci_p5wdh_ops;
ap->link.flags |= ATA_LFLAG_NO_SRST | ATA_LFLAG_ASSUME_ATA;
}
}
static bool ahci_sb600_enable_64bit(struct pci_dev *pdev)
{
static const struct dmi_system_id sysids[] = {
{
.ident = "ASUS M2A-VM",
.matches = {
DMI_MATCH(DMI_BOARD_VENDOR,
"ASUSTeK Computer INC."),
DMI_MATCH(DMI_BOARD_NAME, "M2A-VM"),
},
.driver_data = "20071026",
},
{
.ident = "MSI K9A2 Platinum",
.matches = {
DMI_MATCH(DMI_BOARD_VENDOR,
"MICRO-STAR INTER"),
DMI_MATCH(DMI_BOARD_NAME, "MS-7376"),
},
},
{
.ident = "MSI K9AGM2",
.matches = {
DMI_MATCH(DMI_BOARD_VENDOR,
"MICRO-STAR INTER"),
DMI_MATCH(DMI_BOARD_NAME, "MS-7327"),
},
},
{
.ident = "ASUS M3A",
.matches = {
DMI_MATCH(DMI_BOARD_VENDOR,
"ASUSTeK Computer INC."),
DMI_MATCH(DMI_BOARD_NAME, "M3A"),
},
},
{ }
};
const struct dmi_system_id *match;
int year, month, date;
char buf[9];
match = dmi_first_match(sysids);
if (pdev->bus->number != 0 || pdev->devfn != PCI_DEVFN(0x12, 0) ||
!match)
return false;
if (!match->driver_data)
goto enable_64bit;
dmi_get_date(DMI_BIOS_DATE, &year, &month, &date);
snprintf(buf, sizeof(buf), "%04d%02d%02d", year, month, date);
if (strcmp(buf, match->driver_data) >= 0)
goto enable_64bit;
else {
dev_warn(&pdev->dev,
"%s: BIOS too old, forcing 32bit DMA, update BIOS\n",
match->ident);
return false;
}
enable_64bit:
dev_warn(&pdev->dev, "%s: enabling 64bit DMA\n", match->ident);
return true;
}
static bool ahci_broken_system_poweroff(struct pci_dev *pdev)
{
static const struct dmi_system_id broken_systems[] = {
{
.ident = "HP Compaq nx6310",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
DMI_MATCH(DMI_PRODUCT_NAME, "HP Compaq nx6310"),
},
.driver_data = (void *)0x1FUL,
},
{
.ident = "HP Compaq 6720s",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
DMI_MATCH(DMI_PRODUCT_NAME, "HP Compaq 6720s"),
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
static bool ahci_broken_suspend(struct pci_dev *pdev)
{
static const struct dmi_system_id sysids[] = {
{
.ident = "dv4",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
DMI_MATCH(DMI_PRODUCT_NAME,
"HP Pavilion dv4 Notebook PC"),
},
.driver_data = "20090105",
},
{
.ident = "dv5",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
DMI_MATCH(DMI_PRODUCT_NAME,
"HP Pavilion dv5 Notebook PC"),
},
.driver_data = "20090506",
},
{
.ident = "dv6",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
DMI_MATCH(DMI_PRODUCT_NAME,
"HP Pavilion dv6 Notebook PC"),
},
.driver_data = "20090423",
},
{
.ident = "HDX18",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
DMI_MATCH(DMI_PRODUCT_NAME,
"HP HDX18 Notebook PC"),
},
.driver_data = "20090430",
},
{
.ident = "G725",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "eMachines"),
DMI_MATCH(DMI_PRODUCT_NAME, "eMachines G725"),
},
.driver_data = "20091216",
},
{ }
};
const struct dmi_system_id *dmi = dmi_first_match(sysids);
int year, month, date;
char buf[9];
if (!dmi || pdev->bus->number || pdev->devfn != PCI_DEVFN(0x1f, 2))
return false;
dmi_get_date(DMI_BIOS_DATE, &year, &month, &date);
snprintf(buf, sizeof(buf), "%04d%02d%02d", year, month, date);
return strcmp(buf, dmi->driver_data) < 0;
}
static bool ahci_broken_online(struct pci_dev *pdev)
{
#define ENCODE_BUSDEVFN(bus, slot, func) \
(void *)(unsigned long)(((bus) << 8) | PCI_DEVFN((slot), (func)))
static const struct dmi_system_id sysids[] = {
{
.ident = "EP45-DQ6",
.matches = {
DMI_MATCH(DMI_BOARD_VENDOR,
"Gigabyte Technology Co., Ltd."),
DMI_MATCH(DMI_BOARD_NAME, "EP45-DQ6"),
},
.driver_data = ENCODE_BUSDEVFN(0x0a, 0x00, 0),
},
{
.ident = "EP45-DS5",
.matches = {
DMI_MATCH(DMI_BOARD_VENDOR,
"Gigabyte Technology Co., Ltd."),
DMI_MATCH(DMI_BOARD_NAME, "EP45-DS5"),
},
.driver_data = ENCODE_BUSDEVFN(0x03, 0x00, 0),
},
{ }
};
#undef ENCODE_BUSDEVFN
const struct dmi_system_id *dmi = dmi_first_match(sysids);
unsigned int val;
if (!dmi)
return false;
val = (unsigned long)dmi->driver_data;
return pdev->bus->number == (val >> 8) && pdev->devfn == (val & 0xff);
}
static void ahci_gtf_filter_workaround(struct ata_host *host)
{
static const struct dmi_system_id sysids[] = {
{
.ident = "Aspire 3810T",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 3810T"),
},
.driver_data = (void *)ATA_ACPI_FILTER_FPDMA_OFFSET,
},
{ }
};
const struct dmi_system_id *dmi = dmi_first_match(sysids);
unsigned int filter;
int i;
if (!dmi)
return;
filter = (unsigned long)dmi->driver_data;
dev_info(host->dev, "applying extra ACPI _GTF filter 0x%x for %s\n",
filter, dmi->ident);
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
struct ata_link *link;
struct ata_device *dev;
ata_for_each_link(link, ap, EDGE)
ata_for_each_dev(dev, link, ALL)
dev->gtf_filter |= filter;
}
}
static inline void ahci_gtf_filter_workaround(struct ata_host *host)
{}
int ahci_init_interrupts(struct pci_dev *pdev, struct ahci_host_priv *hpriv)
{
int rc;
unsigned int maxvec;
if (!(hpriv->flags & AHCI_HFLAG_NO_MSI)) {
rc = pci_enable_msi_block_auto(pdev, &maxvec);
if (rc > 0) {
if ((rc == maxvec) || (rc == 1))
return rc;
pci_disable_msi(pdev);
if (!pci_enable_msi(pdev))
return 1;
}
}
pci_intx(pdev, 1);
return 0;
}
int ahci_host_activate(struct ata_host *host, int irq, unsigned int n_msis)
{
int i, rc;
if (n_msis < host->n_ports)
return -EINVAL;
rc = ata_host_start(host);
if (rc)
return rc;
for (i = 0; i < host->n_ports; i++) {
const char* desc;
struct ahci_port_priv *pp = host->ports[i]->private_data;
if (pp)
desc = pp->irq_desc;
else
desc = dev_driver_string(host->dev);
rc = devm_request_threaded_irq(host->dev,
irq + i, ahci_hw_interrupt, ahci_thread_fn, IRQF_SHARED,
desc, host->ports[i]);
if (rc)
goto out_free_irqs;
}
for (i = 0; i < host->n_ports; i++)
ata_port_desc(host->ports[i], "irq %d", irq + i);
rc = ata_host_register(host, &ahci_sht);
if (rc)
goto out_free_all_irqs;
return 0;
out_free_all_irqs:
i = host->n_ports;
out_free_irqs:
for (i--; i >= 0; i--)
devm_free_irq(host->dev, irq + i, host->ports[i]);
return rc;
}
static int ahci_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
unsigned int board_id = ent->driver_data;
struct ata_port_info pi = ahci_port_info[board_id];
const struct ata_port_info *ppi[] = { &pi, NULL };
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
struct ata_host *host;
int n_ports, n_msis, i, rc;
int ahci_pci_bar = AHCI_PCI_BAR_STANDARD;
VPRINTK("ENTER\n");
WARN_ON((int)ATA_MAX_QUEUE > AHCI_MAX_CMDS);
ata_print_version_once(&pdev->dev, DRV_VERSION);
if (pdev->vendor == PCI_VENDOR_ID_MARVELL && !marvell_enable)
return -ENODEV;
if (pdev->vendor == PCI_VENDOR_ID_NVIDIA &&
pdev->device == PCI_DEVICE_ID_NVIDIA_NFORCE_MCP89_SATA &&
pdev->subsystem_vendor == PCI_VENDOR_ID_APPLE &&
pdev->subsystem_device == 0xcb89)
return -ENODEV;
if (pdev->vendor == PCI_VENDOR_ID_PROMISE)
dev_info(&pdev->dev,
"PDC42819 can only drive SATA devices with this driver\n");
if (pdev->vendor == PCI_VENDOR_ID_STMICRO && pdev->device == 0xCC06)
ahci_pci_bar = AHCI_PCI_BAR_STA2X11;
else if (pdev->vendor == 0x1c44 && pdev->device == 0x8000)
ahci_pci_bar = AHCI_PCI_BAR_ENMOTUS;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = pcim_iomap_regions_request_all(pdev, 1 << ahci_pci_bar, DRV_NAME);
if (rc == -EBUSY)
pcim_pin_device(pdev);
if (rc)
return rc;
if (pdev->vendor == PCI_VENDOR_ID_INTEL &&
(pdev->device == 0x2652 || pdev->device == 0x2653)) {
u8 map;
pci_read_config_byte(pdev, ICH_MAP, &map);
if (map & 0x3) {
dev_info(&pdev->dev,
"controller is in combined mode, can't enable AHCI mode\n");
return -ENODEV;
}
}
hpriv = devm_kzalloc(dev, sizeof(*hpriv), GFP_KERNEL);
if (!hpriv)
return -ENOMEM;
hpriv->flags |= (unsigned long)pi.private_data;
if (board_id == board_ahci_mcp65 &&
(pdev->revision == 0xa1 || pdev->revision == 0xa2))
hpriv->flags |= AHCI_HFLAG_NO_MSI;
if (board_id == board_ahci_sb700 && pdev->revision >= 0x40)
hpriv->flags &= ~AHCI_HFLAG_IGN_SERR_INTERNAL;
if (ahci_sb600_enable_64bit(pdev))
hpriv->flags &= ~AHCI_HFLAG_32BIT_ONLY;
hpriv->mmio = pcim_iomap_table(pdev)[ahci_pci_bar];
n_msis = ahci_init_interrupts(pdev, hpriv);
if (n_msis > 1)
hpriv->flags |= AHCI_HFLAG_MULTI_MSI;
ahci_pci_save_initial_config(pdev, hpriv);
if (hpriv->cap & HOST_CAP_NCQ) {
pi.flags |= ATA_FLAG_NCQ;
if (!(hpriv->flags & AHCI_HFLAG_NO_FPDMA_AA))
pi.flags |= ATA_FLAG_FPDMA_AA;
pi.flags |= ATA_FLAG_FPDMA_AUX;
}
if (hpriv->cap & HOST_CAP_PMP)
pi.flags |= ATA_FLAG_PMP;
ahci_set_em_messages(hpriv, &pi);
if (ahci_broken_system_poweroff(pdev)) {
pi.flags |= ATA_FLAG_NO_POWEROFF_SPINDOWN;
dev_info(&pdev->dev,
"quirky BIOS, skipping spindown on poweroff\n");
}
if (ahci_broken_suspend(pdev)) {
hpriv->flags |= AHCI_HFLAG_NO_SUSPEND;
dev_warn(&pdev->dev,
"BIOS update required for suspend/resume\n");
}
if (ahci_broken_online(pdev)) {
hpriv->flags |= AHCI_HFLAG_SRST_TOUT_IS_OFFLINE;
dev_info(&pdev->dev,
"online status unreliable, applying workaround\n");
}
n_ports = max(ahci_nr_ports(hpriv->cap), fls(hpriv->port_map));
host = ata_host_alloc_pinfo(&pdev->dev, ppi, n_ports);
if (!host)
return -ENOMEM;
host->private_data = hpriv;
if (!(hpriv->cap & HOST_CAP_SSS) || ahci_ignore_sss)
host->flags |= ATA_HOST_PARALLEL_SCAN;
else
dev_info(&pdev->dev, "SSS flag set, parallel bus scan disabled\n");
if (pi.flags & ATA_FLAG_EM)
ahci_reset_em(host);
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
ata_port_pbar_desc(ap, ahci_pci_bar, -1, "abar");
ata_port_pbar_desc(ap, ahci_pci_bar,
0x100 + ap->port_no * 0x80, "port");
if (ap->flags & ATA_FLAG_EM)
ap->em_message_type = hpriv->em_msg_type;
if (!(hpriv->port_map & (1 << i)))
ap->ops = &ata_dummy_port_ops;
}
ahci_p5wdh_workaround(host);
ahci_gtf_filter_workaround(host);
rc = ahci_configure_dma_masks(pdev, hpriv->cap & HOST_CAP_64);
if (rc)
return rc;
rc = ahci_pci_reset_controller(host);
if (rc)
return rc;
ahci_pci_init_controller(host);
ahci_pci_print_info(host);
pci_set_master(pdev);
if (hpriv->flags & AHCI_HFLAG_MULTI_MSI)
return ahci_host_activate(host, pdev->irq, n_msis);
return ata_host_activate(host, pdev->irq, ahci_interrupt, IRQF_SHARED,
&ahci_sht);
}
