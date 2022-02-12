static void sil_bmdma_stop(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
void __iomem *mmio_base = ap->host->iomap[SIL_MMIO_BAR];
void __iomem *bmdma2 = mmio_base + sil_port[ap->port_no].bmdma2;
iowrite8(0, bmdma2);
ata_sff_dma_pause(ap);
}
static void sil_bmdma_setup(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
void __iomem *bmdma = ap->ioaddr.bmdma_addr;
iowrite32(ap->bmdma_prd_dma, bmdma + ATA_DMA_TABLE_OFS);
ap->ops->sff_exec_command(ap, &qc->tf);
}
static void sil_bmdma_start(struct ata_queued_cmd *qc)
{
unsigned int rw = (qc->tf.flags & ATA_TFLAG_WRITE);
struct ata_port *ap = qc->ap;
void __iomem *mmio_base = ap->host->iomap[SIL_MMIO_BAR];
void __iomem *bmdma2 = mmio_base + sil_port[ap->port_no].bmdma2;
u8 dmactl = ATA_DMA_START;
if (!rw)
dmactl |= ATA_DMA_WR;
iowrite8(dmactl, bmdma2);
}
static void sil_fill_sg(struct ata_queued_cmd *qc)
{
struct scatterlist *sg;
struct ata_port *ap = qc->ap;
struct ata_bmdma_prd *prd, *last_prd = NULL;
unsigned int si;
prd = &ap->bmdma_prd[0];
for_each_sg(qc->sg, sg, qc->n_elem, si) {
u32 addr = (u32) sg_dma_address(sg);
u32 sg_len = sg_dma_len(sg);
prd->addr = cpu_to_le32(addr);
prd->flags_len = cpu_to_le32(sg_len);
VPRINTK("PRD[%u] = (0x%X, 0x%X)\n", si, addr, sg_len);
last_prd = prd;
prd++;
}
if (likely(last_prd))
last_prd->flags_len |= cpu_to_le32(ATA_PRD_EOT);
}
static void sil_qc_prep(struct ata_queued_cmd *qc)
{
if (!(qc->flags & ATA_QCFLAG_DMAMAP))
return;
sil_fill_sg(qc);
}
static unsigned char sil_get_device_cache_line(struct pci_dev *pdev)
{
u8 cache_line = 0;
pci_read_config_byte(pdev, PCI_CACHE_LINE_SIZE, &cache_line);
return cache_line;
}
static int sil_set_mode(struct ata_link *link, struct ata_device **r_failed)
{
struct ata_port *ap = link->ap;
void __iomem *mmio_base = ap->host->iomap[SIL_MMIO_BAR];
void __iomem *addr = mmio_base + sil_port[ap->port_no].xfer_mode;
struct ata_device *dev;
u32 tmp, dev_mode[2] = { };
int rc;
rc = ata_do_set_mode(link, r_failed);
if (rc)
return rc;
ata_for_each_dev(dev, link, ALL) {
if (!ata_dev_enabled(dev))
dev_mode[dev->devno] = 0;
else if (dev->flags & ATA_DFLAG_PIO)
dev_mode[dev->devno] = 1;
else
dev_mode[dev->devno] = 3;
}
tmp = readl(addr);
tmp &= ~((1<<5) | (1<<4) | (1<<1) | (1<<0));
tmp |= dev_mode[0];
tmp |= (dev_mode[1] << 4);
writel(tmp, addr);
readl(addr);
return 0;
}
static inline void __iomem *sil_scr_addr(struct ata_port *ap,
unsigned int sc_reg)
{
void __iomem *offset = ap->ioaddr.scr_addr;
switch (sc_reg) {
case SCR_STATUS:
return offset + 4;
case SCR_ERROR:
return offset + 8;
case SCR_CONTROL:
return offset;
default:
break;
}
return NULL;
}
static int sil_scr_read(struct ata_link *link, unsigned int sc_reg, u32 *val)
{
void __iomem *mmio = sil_scr_addr(link->ap, sc_reg);
if (mmio) {
*val = readl(mmio);
return 0;
}
return -EINVAL;
}
static int sil_scr_write(struct ata_link *link, unsigned int sc_reg, u32 val)
{
void __iomem *mmio = sil_scr_addr(link->ap, sc_reg);
if (mmio) {
writel(val, mmio);
return 0;
}
return -EINVAL;
}
static void sil_host_intr(struct ata_port *ap, u32 bmdma2)
{
struct ata_eh_info *ehi = &ap->link.eh_info;
struct ata_queued_cmd *qc = ata_qc_from_tag(ap, ap->link.active_tag);
u8 status;
if (unlikely(bmdma2 & SIL_DMA_SATA_IRQ)) {
u32 serror = 0xffffffff;
sil_scr_read(&ap->link, SCR_ERROR, &serror);
sil_scr_write(&ap->link, SCR_ERROR, serror);
if (serror & SERR_PHYRDY_CHG) {
ap->link.eh_info.serror |= serror;
goto freeze;
}
if (!(bmdma2 & SIL_DMA_COMPLETE))
return;
}
if (unlikely(!qc || (qc->tf.flags & ATA_TFLAG_POLLING))) {
ap->ops->sff_check_status(ap);
return;
}
switch (ap->hsm_task_state) {
case HSM_ST_FIRST:
if (!(qc->dev->flags & ATA_DFLAG_CDB_INTR))
goto err_hsm;
break;
case HSM_ST_LAST:
if (ata_is_dma(qc->tf.protocol)) {
ap->ops->bmdma_stop(qc);
if (bmdma2 & SIL_DMA_ERROR) {
qc->err_mask |= AC_ERR_HOST_BUS;
ap->hsm_task_state = HSM_ST_ERR;
}
}
break;
case HSM_ST:
break;
default:
goto err_hsm;
}
status = ap->ops->sff_check_status(ap);
if (unlikely(status & ATA_BUSY))
goto err_hsm;
ata_bmdma_irq_clear(ap);
ata_sff_hsm_move(ap, qc, status, 0);
if (unlikely(qc->err_mask) && ata_is_dma(qc->tf.protocol))
ata_ehi_push_desc(ehi, "BMDMA2 stat 0x%x", bmdma2);
return;
err_hsm:
qc->err_mask |= AC_ERR_HSM;
freeze:
ata_port_freeze(ap);
}
static irqreturn_t sil_interrupt(int irq, void *dev_instance)
{
struct ata_host *host = dev_instance;
void __iomem *mmio_base = host->iomap[SIL_MMIO_BAR];
int handled = 0;
int i;
spin_lock(&host->lock);
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
u32 bmdma2 = readl(mmio_base + sil_port[ap->port_no].bmdma2);
if (ap->flags & SIL_FLAG_NO_SATA_IRQ)
bmdma2 &= ~SIL_DMA_SATA_IRQ;
if (bmdma2 == 0xffffffff ||
!(bmdma2 & (SIL_DMA_COMPLETE | SIL_DMA_SATA_IRQ)))
continue;
sil_host_intr(ap, bmdma2);
handled = 1;
}
spin_unlock(&host->lock);
return IRQ_RETVAL(handled);
}
static void sil_freeze(struct ata_port *ap)
{
void __iomem *mmio_base = ap->host->iomap[SIL_MMIO_BAR];
u32 tmp;
writel(0, mmio_base + sil_port[ap->port_no].sien);
tmp = readl(mmio_base + SIL_SYSCFG);
tmp |= SIL_MASK_IDE0_INT << ap->port_no;
writel(tmp, mmio_base + SIL_SYSCFG);
readl(mmio_base + SIL_SYSCFG);
iowrite8(ioread8(ap->ioaddr.bmdma_addr) & ~SIL_DMA_ENABLE,
ap->ioaddr.bmdma_addr);
ioread8(ap->ioaddr.bmdma_addr);
}
static void sil_thaw(struct ata_port *ap)
{
void __iomem *mmio_base = ap->host->iomap[SIL_MMIO_BAR];
u32 tmp;
ap->ops->sff_check_status(ap);
ata_bmdma_irq_clear(ap);
if (!(ap->flags & SIL_FLAG_NO_SATA_IRQ))
writel(SIL_SIEN_N, mmio_base + sil_port[ap->port_no].sien);
tmp = readl(mmio_base + SIL_SYSCFG);
tmp &= ~(SIL_MASK_IDE0_INT << ap->port_no);
writel(tmp, mmio_base + SIL_SYSCFG);
}
static void sil_dev_config(struct ata_device *dev)
{
struct ata_port *ap = dev->link->ap;
int print_info = ap->link.eh_context.i.flags & ATA_EHI_PRINTINFO;
unsigned int n, quirks = 0;
unsigned char model_num[ATA_ID_PROD_LEN + 1];
ata_id_c_string(dev->id, model_num, ATA_ID_PROD, sizeof(model_num));
for (n = 0; sil_blacklist[n].product; n++)
if (!strcmp(sil_blacklist[n].product, model_num)) {
quirks = sil_blacklist[n].quirk;
break;
}
if (slow_down ||
((ap->flags & SIL_FLAG_MOD15WRITE) &&
(quirks & SIL_QUIRK_MOD15WRITE))) {
if (print_info)
ata_dev_info(dev,
"applying Seagate errata fix (mod15write workaround)\n");
dev->max_sectors = 15;
return;
}
if (quirks & SIL_QUIRK_UDMA5MAX) {
if (print_info)
ata_dev_info(dev, "applying Maxtor errata fix %s\n",
model_num);
dev->udma_mask &= ATA_UDMA5;
return;
}
}
static void sil_init_controller(struct ata_host *host)
{
struct pci_dev *pdev = to_pci_dev(host->dev);
void __iomem *mmio_base = host->iomap[SIL_MMIO_BAR];
u8 cls;
u32 tmp;
int i;
cls = sil_get_device_cache_line(pdev);
if (cls) {
cls >>= 3;
cls++;
for (i = 0; i < host->n_ports; i++)
writew(cls << 8 | cls,
mmio_base + sil_port[i].fifo_cfg);
} else
dev_warn(&pdev->dev,
"cache line size not set. Driver may not function\n");
if (host->ports[0]->flags & SIL_FLAG_RERR_ON_DMA_ACT) {
int cnt;
for (i = 0, cnt = 0; i < host->n_ports; i++) {
tmp = readl(mmio_base + sil_port[i].sfis_cfg);
if ((tmp & 0x3) != 0x01)
continue;
if (!cnt)
dev_info(&pdev->dev,
"Applying R_ERR on DMA activate FIS errata fix\n");
writel(tmp & ~0x3, mmio_base + sil_port[i].sfis_cfg);
cnt++;
}
}
if (host->n_ports == 4) {
tmp = readl(mmio_base + sil_port[2].bmdma);
if ((tmp & SIL_INTR_STEERING) == 0)
writel(tmp | SIL_INTR_STEERING,
mmio_base + sil_port[2].bmdma);
}
}
static bool sil_broken_system_poweroff(struct pci_dev *pdev)
{
static const struct dmi_system_id broken_systems[] = {
{
.ident = "HP Compaq nx6325",
.matches = {
DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
DMI_MATCH(DMI_PRODUCT_NAME, "HP Compaq nx6325"),
},
.driver_data = (void *)0x12UL,
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
static int sil_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int board_id = ent->driver_data;
struct ata_port_info pi = sil_port_info[board_id];
const struct ata_port_info *ppi[] = { &pi, NULL };
struct ata_host *host;
void __iomem *mmio_base;
int n_ports, rc;
unsigned int i;
ata_print_version_once(&pdev->dev, DRV_VERSION);
n_ports = 2;
if (board_id == sil_3114)
n_ports = 4;
if (sil_broken_system_poweroff(pdev)) {
pi.flags |= ATA_FLAG_NO_POWEROFF_SPINDOWN |
ATA_FLAG_NO_HIBERNATE_SPINDOWN;
dev_info(&pdev->dev, "quirky BIOS, skipping spindown "
"on poweroff and hibernation\n");
}
host = ata_host_alloc_pinfo(&pdev->dev, ppi, n_ports);
if (!host)
return -ENOMEM;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = pcim_iomap_regions(pdev, 1 << SIL_MMIO_BAR, DRV_NAME);
if (rc == -EBUSY)
pcim_pin_device(pdev);
if (rc)
return rc;
host->iomap = pcim_iomap_table(pdev);
rc = pci_set_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
rc = pci_set_consistent_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
mmio_base = host->iomap[SIL_MMIO_BAR];
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
struct ata_ioports *ioaddr = &ap->ioaddr;
ioaddr->cmd_addr = mmio_base + sil_port[i].tf;
ioaddr->altstatus_addr =
ioaddr->ctl_addr = mmio_base + sil_port[i].ctl;
ioaddr->bmdma_addr = mmio_base + sil_port[i].bmdma;
ioaddr->scr_addr = mmio_base + sil_port[i].scr;
ata_sff_std_ports(ioaddr);
ata_port_pbar_desc(ap, SIL_MMIO_BAR, -1, "mmio");
ata_port_pbar_desc(ap, SIL_MMIO_BAR, sil_port[i].tf, "tf");
}
sil_init_controller(host);
pci_set_master(pdev);
return ata_host_activate(host, pdev->irq, sil_interrupt, IRQF_SHARED,
&sil_sht);
}
static int sil_pci_device_resume(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
sil_init_controller(host);
ata_host_resume(host);
return 0;
}
static int __init sil_init(void)
{
return pci_register_driver(&sil_pci_driver);
}
static void __exit sil_exit(void)
{
pci_unregister_driver(&sil_pci_driver);
}
