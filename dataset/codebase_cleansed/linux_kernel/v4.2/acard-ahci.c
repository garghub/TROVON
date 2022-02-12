static int acard_ahci_pci_device_suspend(struct pci_dev *pdev, pm_message_t mesg)
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
static int acard_ahci_pci_device_resume(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
if (pdev->dev.power.power_state.event == PM_EVENT_SUSPEND) {
rc = ahci_reset_controller(host);
if (rc)
return rc;
ahci_init_controller(host);
}
ata_host_resume(host);
return 0;
}
static int acard_ahci_configure_dma_masks(struct pci_dev *pdev, int using_dac)
{
int rc;
if (using_dac &&
!dma_set_mask(&pdev->dev, DMA_BIT_MASK(64))) {
rc = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(64));
if (rc) {
rc = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev,
"64-bit DMA enable failed\n");
return rc;
}
}
} else {
rc = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev, "32-bit DMA enable failed\n");
return rc;
}
rc = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev,
"32-bit consistent DMA enable failed\n");
return rc;
}
}
return 0;
}
static void acard_ahci_pci_print_info(struct ata_host *host)
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
static unsigned int acard_ahci_fill_sg(struct ata_queued_cmd *qc, void *cmd_tbl)
{
struct scatterlist *sg;
struct acard_sg *acard_sg = cmd_tbl + AHCI_CMD_TBL_HDR_SZ;
unsigned int si, last_si = 0;
VPRINTK("ENTER\n");
for_each_sg(qc->sg, sg, qc->n_elem, si) {
dma_addr_t addr = sg_dma_address(sg);
u32 sg_len = sg_dma_len(sg);
acard_sg[si].addr = cpu_to_le32(addr & 0xffffffff);
acard_sg[si].addr_hi = cpu_to_le32((addr >> 16) >> 16);
acard_sg[si].size = cpu_to_le32(sg_len);
last_si = si;
}
acard_sg[last_si].size |= cpu_to_le32(1 << 31);
return si;
}
static void acard_ahci_qc_prep(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ahci_port_priv *pp = ap->private_data;
int is_atapi = ata_is_atapi(qc->tf.protocol);
void *cmd_tbl;
u32 opts;
const u32 cmd_fis_len = 5;
unsigned int n_elem;
cmd_tbl = pp->cmd_tbl + qc->tag * AHCI_CMD_TBL_SZ;
ata_tf_to_fis(&qc->tf, qc->dev->link->pmp, 1, cmd_tbl);
if (is_atapi) {
memset(cmd_tbl + AHCI_CMD_TBL_CDB, 0, 32);
memcpy(cmd_tbl + AHCI_CMD_TBL_CDB, qc->cdb, qc->dev->cdb_len);
}
n_elem = 0;
if (qc->flags & ATA_QCFLAG_DMAMAP)
n_elem = acard_ahci_fill_sg(qc, cmd_tbl);
opts = cmd_fis_len | (qc->dev->link->pmp << 12);
if (qc->tf.flags & ATA_TFLAG_WRITE)
opts |= AHCI_CMD_WRITE;
if (is_atapi)
opts |= AHCI_CMD_ATAPI | AHCI_CMD_PREFETCH;
ahci_fill_cmd_slot(pp, qc->tag, opts);
}
static bool acard_ahci_qc_fill_rtf(struct ata_queued_cmd *qc)
{
struct ahci_port_priv *pp = qc->ap->private_data;
u8 *rx_fis = pp->rx_fis;
if (pp->fbs_enabled)
rx_fis += qc->dev->link->pmp * ACARD_AHCI_RX_FIS_SZ;
if (qc->tf.protocol == ATA_PROT_PIO && qc->dma_dir == DMA_FROM_DEVICE &&
!(qc->flags & ATA_QCFLAG_FAILED)) {
ata_tf_from_fis(rx_fis + RX_FIS_PIO_SETUP, &qc->result_tf);
qc->result_tf.command = (rx_fis + RX_FIS_PIO_SETUP)[15];
} else
ata_tf_from_fis(rx_fis + RX_FIS_D2H_REG, &qc->result_tf);
return true;
}
static int acard_ahci_port_start(struct ata_port *ap)
{
struct ahci_host_priv *hpriv = ap->host->private_data;
struct device *dev = ap->host->dev;
struct ahci_port_priv *pp;
void *mem;
dma_addr_t mem_dma;
size_t dma_sz, rx_fis_sz;
pp = devm_kzalloc(dev, sizeof(*pp), GFP_KERNEL);
if (!pp)
return -ENOMEM;
if ((hpriv->cap & HOST_CAP_FBS) && sata_pmp_supported(ap)) {
void __iomem *port_mmio = ahci_port_base(ap);
u32 cmd = readl(port_mmio + PORT_CMD);
if (cmd & PORT_CMD_FBSCP)
pp->fbs_supported = true;
else if (hpriv->flags & AHCI_HFLAG_YES_FBS) {
dev_info(dev, "port %d can do FBS, forcing FBSCP\n",
ap->port_no);
pp->fbs_supported = true;
} else
dev_warn(dev, "port %d is not capable of FBS\n",
ap->port_no);
}
if (pp->fbs_supported) {
dma_sz = AHCI_PORT_PRIV_FBS_DMA_SZ;
rx_fis_sz = ACARD_AHCI_RX_FIS_SZ * 16;
} else {
dma_sz = AHCI_PORT_PRIV_DMA_SZ;
rx_fis_sz = ACARD_AHCI_RX_FIS_SZ;
}
mem = dmam_alloc_coherent(dev, dma_sz, &mem_dma, GFP_KERNEL);
if (!mem)
return -ENOMEM;
memset(mem, 0, dma_sz);
pp->cmd_slot = mem;
pp->cmd_slot_dma = mem_dma;
mem += AHCI_CMD_SLOT_SZ;
mem_dma += AHCI_CMD_SLOT_SZ;
pp->rx_fis = mem;
pp->rx_fis_dma = mem_dma;
mem += rx_fis_sz;
mem_dma += rx_fis_sz;
pp->cmd_tbl = mem;
pp->cmd_tbl_dma = mem_dma;
pp->intr_mask = DEF_PORT_IRQ;
ap->private_data = pp;
return ahci_port_resume(ap);
}
static int acard_ahci_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
unsigned int board_id = ent->driver_data;
struct ata_port_info pi = acard_ahci_port_info[board_id];
const struct ata_port_info *ppi[] = { &pi, NULL };
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
struct ata_host *host;
int n_ports, i, rc;
VPRINTK("ENTER\n");
WARN_ON((int)ATA_MAX_QUEUE > AHCI_MAX_CMDS);
ata_print_version_once(&pdev->dev, DRV_VERSION);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = pcim_iomap_regions_request_all(pdev, 1 << AHCI_PCI_BAR, DRV_NAME);
if (rc == -EBUSY)
pcim_pin_device(pdev);
if (rc)
return rc;
hpriv = devm_kzalloc(dev, sizeof(*hpriv), GFP_KERNEL);
if (!hpriv)
return -ENOMEM;
hpriv->irq = pdev->irq;
hpriv->flags |= (unsigned long)pi.private_data;
if (!(hpriv->flags & AHCI_HFLAG_NO_MSI))
pci_enable_msi(pdev);
hpriv->mmio = pcim_iomap_table(pdev)[AHCI_PCI_BAR];
ahci_save_initial_config(&pdev->dev, hpriv);
if (hpriv->cap & HOST_CAP_NCQ)
pi.flags |= ATA_FLAG_NCQ;
if (hpriv->cap & HOST_CAP_PMP)
pi.flags |= ATA_FLAG_PMP;
ahci_set_em_messages(hpriv, &pi);
n_ports = max(ahci_nr_ports(hpriv->cap), fls(hpriv->port_map));
host = ata_host_alloc_pinfo(&pdev->dev, ppi, n_ports);
if (!host)
return -ENOMEM;
host->private_data = hpriv;
if (!(hpriv->cap & HOST_CAP_SSS) || ahci_ignore_sss)
host->flags |= ATA_HOST_PARALLEL_SCAN;
else
printk(KERN_INFO "ahci: SSS flag set, parallel bus scan disabled\n");
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
ata_port_pbar_desc(ap, AHCI_PCI_BAR, -1, "abar");
ata_port_pbar_desc(ap, AHCI_PCI_BAR,
0x100 + ap->port_no * 0x80, "port");
if (!(hpriv->port_map & (1 << i)))
ap->ops = &ata_dummy_port_ops;
}
rc = acard_ahci_configure_dma_masks(pdev, hpriv->cap & HOST_CAP_64);
if (rc)
return rc;
rc = ahci_reset_controller(host);
if (rc)
return rc;
ahci_init_controller(host);
acard_ahci_pci_print_info(host);
pci_set_master(pdev);
return ahci_host_activate(host, &acard_ahci_sht);
}
