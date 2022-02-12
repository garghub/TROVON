int ntb_register_event_callback(struct ntb_device *ndev,
void (*func)(void *handle, enum ntb_hw_event event))
{
if (ndev->event_cb)
return -EINVAL;
ndev->event_cb = func;
return 0;
}
void ntb_unregister_event_callback(struct ntb_device *ndev)
{
ndev->event_cb = NULL;
}
int ntb_register_db_callback(struct ntb_device *ndev, unsigned int idx,
void *data, void (*func)(void *data, int db_num))
{
unsigned long mask;
if (idx >= ndev->max_cbs || ndev->db_cb[idx].callback) {
dev_warn(&ndev->pdev->dev, "Invalid Index.\n");
return -EINVAL;
}
ndev->db_cb[idx].callback = func;
ndev->db_cb[idx].data = data;
mask = readw(ndev->reg_ofs.pdb_mask);
clear_bit(idx * ndev->bits_per_vector, &mask);
writew(mask, ndev->reg_ofs.pdb_mask);
return 0;
}
void ntb_unregister_db_callback(struct ntb_device *ndev, unsigned int idx)
{
unsigned long mask;
if (idx >= ndev->max_cbs || !ndev->db_cb[idx].callback)
return;
mask = readw(ndev->reg_ofs.pdb_mask);
set_bit(idx * ndev->bits_per_vector, &mask);
writew(mask, ndev->reg_ofs.pdb_mask);
ndev->db_cb[idx].callback = NULL;
}
void *ntb_find_transport(struct pci_dev *pdev)
{
struct ntb_device *ndev = pci_get_drvdata(pdev);
return ndev->ntb_transport;
}
struct ntb_device *ntb_register_transport(struct pci_dev *pdev, void *transport)
{
struct ntb_device *ndev = pci_get_drvdata(pdev);
if (ndev->ntb_transport)
return NULL;
ndev->ntb_transport = transport;
return ndev;
}
void ntb_unregister_transport(struct ntb_device *ndev)
{
int i;
if (!ndev->ntb_transport)
return;
for (i = 0; i < ndev->max_cbs; i++)
ntb_unregister_db_callback(ndev, i);
ntb_unregister_event_callback(ndev);
ndev->ntb_transport = NULL;
}
int ntb_write_local_spad(struct ntb_device *ndev, unsigned int idx, u32 val)
{
if (idx >= ndev->limits.max_spads)
return -EINVAL;
dev_dbg(&ndev->pdev->dev, "Writing %x to local scratch pad index %d\n",
val, idx);
writel(val, ndev->reg_ofs.spad_read + idx * 4);
return 0;
}
int ntb_read_local_spad(struct ntb_device *ndev, unsigned int idx, u32 *val)
{
if (idx >= ndev->limits.max_spads)
return -EINVAL;
*val = readl(ndev->reg_ofs.spad_write + idx * 4);
dev_dbg(&ndev->pdev->dev,
"Reading %x from local scratch pad index %d\n", *val, idx);
return 0;
}
int ntb_write_remote_spad(struct ntb_device *ndev, unsigned int idx, u32 val)
{
if (idx >= ndev->limits.max_spads)
return -EINVAL;
dev_dbg(&ndev->pdev->dev, "Writing %x to remote scratch pad index %d\n",
val, idx);
writel(val, ndev->reg_ofs.spad_write + idx * 4);
return 0;
}
int ntb_read_remote_spad(struct ntb_device *ndev, unsigned int idx, u32 *val)
{
if (idx >= ndev->limits.max_spads)
return -EINVAL;
*val = readl(ndev->reg_ofs.spad_read + idx * 4);
dev_dbg(&ndev->pdev->dev,
"Reading %x from remote scratch pad index %d\n", *val, idx);
return 0;
}
void __iomem *ntb_get_mw_vbase(struct ntb_device *ndev, unsigned int mw)
{
if (mw >= NTB_NUM_MW)
return NULL;
return ndev->mw[mw].vbase;
}
resource_size_t ntb_get_mw_size(struct ntb_device *ndev, unsigned int mw)
{
if (mw >= NTB_NUM_MW)
return 0;
return ndev->mw[mw].bar_sz;
}
void ntb_set_mw_addr(struct ntb_device *ndev, unsigned int mw, u64 addr)
{
if (mw >= NTB_NUM_MW)
return;
dev_dbg(&ndev->pdev->dev, "Writing addr %Lx to BAR %d\n", addr,
MW_TO_BAR(mw));
ndev->mw[mw].phys_addr = addr;
switch (MW_TO_BAR(mw)) {
case NTB_BAR_23:
writeq(addr, ndev->reg_ofs.sbar2_xlat);
break;
case NTB_BAR_45:
writeq(addr, ndev->reg_ofs.sbar4_xlat);
break;
}
}
void ntb_ring_sdb(struct ntb_device *ndev, unsigned int db)
{
dev_dbg(&ndev->pdev->dev, "%s: ringing doorbell %d\n", __func__, db);
if (ndev->hw_type == BWD_HW)
writeq((u64) 1 << db, ndev->reg_ofs.sdb);
else
writew(((1 << ndev->bits_per_vector) - 1) <<
(db * ndev->bits_per_vector), ndev->reg_ofs.sdb);
}
static void ntb_link_event(struct ntb_device *ndev, int link_state)
{
unsigned int event;
if (ndev->link_status == link_state)
return;
if (link_state == NTB_LINK_UP) {
u16 status;
dev_info(&ndev->pdev->dev, "Link Up\n");
ndev->link_status = NTB_LINK_UP;
event = NTB_EVENT_HW_LINK_UP;
if (ndev->hw_type == BWD_HW)
status = readw(ndev->reg_ofs.lnk_stat);
else {
int rc = pci_read_config_word(ndev->pdev,
SNB_LINK_STATUS_OFFSET,
&status);
if (rc)
return;
}
dev_info(&ndev->pdev->dev, "Link Width %d, Link Speed %d\n",
(status & NTB_LINK_WIDTH_MASK) >> 4,
(status & NTB_LINK_SPEED_MASK));
} else {
dev_info(&ndev->pdev->dev, "Link Down\n");
ndev->link_status = NTB_LINK_DOWN;
event = NTB_EVENT_HW_LINK_DOWN;
}
if (ndev->event_cb)
ndev->event_cb(ndev->ntb_transport, event);
}
static int ntb_link_status(struct ntb_device *ndev)
{
int link_state;
if (ndev->hw_type == BWD_HW) {
u32 ntb_cntl;
ntb_cntl = readl(ndev->reg_ofs.lnk_cntl);
if (ntb_cntl & BWD_CNTL_LINK_DOWN)
link_state = NTB_LINK_DOWN;
else
link_state = NTB_LINK_UP;
} else {
u16 status;
int rc;
rc = pci_read_config_word(ndev->pdev, SNB_LINK_STATUS_OFFSET,
&status);
if (rc)
return rc;
if (status & NTB_LINK_STATUS_ACTIVE)
link_state = NTB_LINK_UP;
else
link_state = NTB_LINK_DOWN;
}
ntb_link_event(ndev, link_state);
return 0;
}
static void bwd_link_poll(struct work_struct *work)
{
struct ntb_device *ndev = container_of(work, struct ntb_device,
hb_timer.work);
unsigned long ts = jiffies;
if (ts > ndev->last_ts + NTB_HB_TIMEOUT) {
int rc = ntb_link_status(ndev);
if (rc)
dev_err(&ndev->pdev->dev,
"Error determining link status\n");
}
schedule_delayed_work(&ndev->hb_timer, NTB_HB_TIMEOUT);
}
static int ntb_xeon_setup(struct ntb_device *ndev)
{
int rc;
u8 val;
ndev->hw_type = SNB_HW;
rc = pci_read_config_byte(ndev->pdev, NTB_PPD_OFFSET, &val);
if (rc)
return rc;
switch (val & SNB_PPD_CONN_TYPE) {
case NTB_CONN_B2B:
ndev->conn_type = NTB_CONN_B2B;
break;
case NTB_CONN_CLASSIC:
case NTB_CONN_RP:
default:
dev_err(&ndev->pdev->dev, "Only B2B supported at this time\n");
return -EINVAL;
}
if (val & SNB_PPD_DEV_TYPE)
ndev->dev_type = NTB_DEV_DSD;
else
ndev->dev_type = NTB_DEV_USD;
ndev->reg_ofs.pdb = ndev->reg_base + SNB_PDOORBELL_OFFSET;
ndev->reg_ofs.pdb_mask = ndev->reg_base + SNB_PDBMSK_OFFSET;
ndev->reg_ofs.sbar2_xlat = ndev->reg_base + SNB_SBAR2XLAT_OFFSET;
ndev->reg_ofs.sbar4_xlat = ndev->reg_base + SNB_SBAR4XLAT_OFFSET;
ndev->reg_ofs.lnk_cntl = ndev->reg_base + SNB_NTBCNTL_OFFSET;
ndev->reg_ofs.lnk_stat = ndev->reg_base + SNB_LINK_STATUS_OFFSET;
ndev->reg_ofs.spad_read = ndev->reg_base + SNB_SPAD_OFFSET;
ndev->reg_ofs.spci_cmd = ndev->reg_base + SNB_PCICMD_OFFSET;
if (ndev->conn_type == NTB_CONN_B2B) {
ndev->reg_ofs.sdb = ndev->reg_base + SNB_B2B_DOORBELL_OFFSET;
ndev->reg_ofs.spad_write = ndev->reg_base + SNB_B2B_SPAD_OFFSET;
ndev->limits.max_spads = SNB_MAX_SPADS;
} else {
ndev->reg_ofs.sdb = ndev->reg_base + SNB_SDOORBELL_OFFSET;
ndev->reg_ofs.spad_write = ndev->reg_base + SNB_SPAD_OFFSET;
ndev->limits.max_spads = SNB_MAX_COMPAT_SPADS;
}
ndev->limits.max_db_bits = SNB_MAX_DB_BITS;
ndev->limits.msix_cnt = SNB_MSIX_CNT;
ndev->bits_per_vector = SNB_DB_BITS_PER_VEC;
return 0;
}
static int ntb_bwd_setup(struct ntb_device *ndev)
{
int rc;
u32 val;
ndev->hw_type = BWD_HW;
rc = pci_read_config_dword(ndev->pdev, NTB_PPD_OFFSET, &val);
if (rc)
return rc;
switch ((val & BWD_PPD_CONN_TYPE) >> 8) {
case NTB_CONN_B2B:
ndev->conn_type = NTB_CONN_B2B;
break;
case NTB_CONN_RP:
default:
dev_err(&ndev->pdev->dev, "Only B2B supported at this time\n");
return -EINVAL;
}
if (val & BWD_PPD_DEV_TYPE)
ndev->dev_type = NTB_DEV_DSD;
else
ndev->dev_type = NTB_DEV_USD;
rc = pci_write_config_dword(ndev->pdev, NTB_PPD_OFFSET,
val | BWD_PPD_INIT_LINK);
if (rc)
return rc;
ndev->reg_ofs.pdb = ndev->reg_base + BWD_PDOORBELL_OFFSET;
ndev->reg_ofs.pdb_mask = ndev->reg_base + BWD_PDBMSK_OFFSET;
ndev->reg_ofs.sbar2_xlat = ndev->reg_base + BWD_SBAR2XLAT_OFFSET;
ndev->reg_ofs.sbar4_xlat = ndev->reg_base + BWD_SBAR4XLAT_OFFSET;
ndev->reg_ofs.lnk_cntl = ndev->reg_base + BWD_NTBCNTL_OFFSET;
ndev->reg_ofs.lnk_stat = ndev->reg_base + BWD_LINK_STATUS_OFFSET;
ndev->reg_ofs.spad_read = ndev->reg_base + BWD_SPAD_OFFSET;
ndev->reg_ofs.spci_cmd = ndev->reg_base + BWD_PCICMD_OFFSET;
if (ndev->conn_type == NTB_CONN_B2B) {
ndev->reg_ofs.sdb = ndev->reg_base + BWD_B2B_DOORBELL_OFFSET;
ndev->reg_ofs.spad_write = ndev->reg_base + BWD_B2B_SPAD_OFFSET;
ndev->limits.max_spads = BWD_MAX_SPADS;
} else {
ndev->reg_ofs.sdb = ndev->reg_base + BWD_PDOORBELL_OFFSET;
ndev->reg_ofs.spad_write = ndev->reg_base + BWD_SPAD_OFFSET;
ndev->limits.max_spads = BWD_MAX_COMPAT_SPADS;
}
ndev->limits.max_db_bits = BWD_MAX_DB_BITS;
ndev->limits.msix_cnt = BWD_MSIX_CNT;
ndev->bits_per_vector = BWD_DB_BITS_PER_VEC;
INIT_DELAYED_WORK(&ndev->hb_timer, bwd_link_poll);
schedule_delayed_work(&ndev->hb_timer, NTB_HB_TIMEOUT);
return 0;
}
static int ntb_device_setup(struct ntb_device *ndev)
{
int rc;
switch (ndev->pdev->device) {
case PCI_DEVICE_ID_INTEL_NTB_2ND_SNB:
case PCI_DEVICE_ID_INTEL_NTB_RP_JSF:
case PCI_DEVICE_ID_INTEL_NTB_RP_SNB:
case PCI_DEVICE_ID_INTEL_NTB_CLASSIC_JSF:
case PCI_DEVICE_ID_INTEL_NTB_CLASSIC_SNB:
case PCI_DEVICE_ID_INTEL_NTB_B2B_JSF:
case PCI_DEVICE_ID_INTEL_NTB_B2B_SNB:
rc = ntb_xeon_setup(ndev);
break;
case PCI_DEVICE_ID_INTEL_NTB_B2B_BWD:
rc = ntb_bwd_setup(ndev);
break;
default:
rc = -ENODEV;
}
writew(PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER, ndev->reg_ofs.spci_cmd);
return rc;
}
static void ntb_device_free(struct ntb_device *ndev)
{
if (ndev->hw_type == BWD_HW)
cancel_delayed_work_sync(&ndev->hb_timer);
}
static irqreturn_t bwd_callback_msix_irq(int irq, void *data)
{
struct ntb_db_cb *db_cb = data;
struct ntb_device *ndev = db_cb->ndev;
dev_dbg(&ndev->pdev->dev, "MSI-X irq %d received for DB %d\n", irq,
db_cb->db_num);
if (db_cb->callback)
db_cb->callback(db_cb->data, db_cb->db_num);
ndev->last_ts = jiffies;
writeq((u64) 1 << db_cb->db_num, ndev->reg_ofs.pdb);
return IRQ_HANDLED;
}
static irqreturn_t xeon_callback_msix_irq(int irq, void *data)
{
struct ntb_db_cb *db_cb = data;
struct ntb_device *ndev = db_cb->ndev;
dev_dbg(&ndev->pdev->dev, "MSI-X irq %d received for DB %d\n", irq,
db_cb->db_num);
if (db_cb->callback)
db_cb->callback(db_cb->data, db_cb->db_num);
writew(((1 << ndev->bits_per_vector) - 1) <<
(db_cb->db_num * ndev->bits_per_vector), ndev->reg_ofs.pdb);
return IRQ_HANDLED;
}
static irqreturn_t xeon_event_msix_irq(int irq, void *dev)
{
struct ntb_device *ndev = dev;
int rc;
dev_dbg(&ndev->pdev->dev, "MSI-X irq %d received for Events\n", irq);
rc = ntb_link_status(ndev);
if (rc)
dev_err(&ndev->pdev->dev, "Error determining link status\n");
writew(1 << ndev->limits.max_db_bits, ndev->reg_ofs.pdb);
return IRQ_HANDLED;
}
static irqreturn_t ntb_interrupt(int irq, void *dev)
{
struct ntb_device *ndev = dev;
unsigned int i = 0;
if (ndev->hw_type == BWD_HW) {
u64 pdb = readq(ndev->reg_ofs.pdb);
dev_dbg(&ndev->pdev->dev, "irq %d - pdb = %Lx\n", irq, pdb);
while (pdb) {
i = __ffs(pdb);
pdb &= pdb - 1;
bwd_callback_msix_irq(irq, &ndev->db_cb[i]);
}
} else {
u16 pdb = readw(ndev->reg_ofs.pdb);
dev_dbg(&ndev->pdev->dev, "irq %d - pdb = %x sdb %x\n", irq,
pdb, readw(ndev->reg_ofs.sdb));
if (pdb & SNB_DB_HW_LINK) {
xeon_event_msix_irq(irq, dev);
pdb &= ~SNB_DB_HW_LINK;
}
while (pdb) {
i = __ffs(pdb);
pdb &= pdb - 1;
xeon_callback_msix_irq(irq, &ndev->db_cb[i]);
}
}
return IRQ_HANDLED;
}
static int ntb_setup_msix(struct ntb_device *ndev)
{
struct pci_dev *pdev = ndev->pdev;
struct msix_entry *msix;
int msix_entries;
int rc, i, pos;
u16 val;
pos = pci_find_capability(pdev, PCI_CAP_ID_MSIX);
if (!pos) {
rc = -EIO;
goto err;
}
rc = pci_read_config_word(pdev, pos + PCI_MSIX_FLAGS, &val);
if (rc)
goto err;
msix_entries = msix_table_size(val);
if (msix_entries > ndev->limits.msix_cnt) {
rc = -EINVAL;
goto err;
}
ndev->msix_entries = kmalloc(sizeof(struct msix_entry) * msix_entries,
GFP_KERNEL);
if (!ndev->msix_entries) {
rc = -ENOMEM;
goto err;
}
for (i = 0; i < msix_entries; i++)
ndev->msix_entries[i].entry = i;
rc = pci_enable_msix(pdev, ndev->msix_entries, msix_entries);
if (rc < 0)
goto err1;
if (rc > 0) {
if (ndev->hw_type != BWD_HW) {
rc = -EIO;
goto err1;
}
dev_warn(&pdev->dev,
"Only %d MSI-X vectors. Limiting the number of queues to that number.\n",
rc);
msix_entries = rc;
}
for (i = 0; i < msix_entries; i++) {
msix = &ndev->msix_entries[i];
WARN_ON(!msix->vector);
if (ndev->hw_type == BWD_HW) {
rc = request_irq(msix->vector, bwd_callback_msix_irq, 0,
"ntb-callback-msix", &ndev->db_cb[i]);
if (rc)
goto err2;
} else {
if (i == msix_entries - 1) {
rc = request_irq(msix->vector,
xeon_event_msix_irq, 0,
"ntb-event-msix", ndev);
if (rc)
goto err2;
} else {
rc = request_irq(msix->vector,
xeon_callback_msix_irq, 0,
"ntb-callback-msix",
&ndev->db_cb[i]);
if (rc)
goto err2;
}
}
}
ndev->num_msix = msix_entries;
if (ndev->hw_type == BWD_HW)
ndev->max_cbs = msix_entries;
else
ndev->max_cbs = msix_entries - 1;
return 0;
err2:
while (--i >= 0) {
msix = &ndev->msix_entries[i];
if (ndev->hw_type != BWD_HW && i == ndev->num_msix - 1)
free_irq(msix->vector, ndev);
else
free_irq(msix->vector, &ndev->db_cb[i]);
}
pci_disable_msix(pdev);
err1:
kfree(ndev->msix_entries);
dev_err(&pdev->dev, "Error allocating MSI-X interrupt\n");
err:
ndev->num_msix = 0;
return rc;
}
static int ntb_setup_msi(struct ntb_device *ndev)
{
struct pci_dev *pdev = ndev->pdev;
int rc;
rc = pci_enable_msi(pdev);
if (rc)
return rc;
rc = request_irq(pdev->irq, ntb_interrupt, 0, "ntb-msi", ndev);
if (rc) {
pci_disable_msi(pdev);
dev_err(&pdev->dev, "Error allocating MSI interrupt\n");
return rc;
}
return 0;
}
static int ntb_setup_intx(struct ntb_device *ndev)
{
struct pci_dev *pdev = ndev->pdev;
int rc;
pci_msi_off(pdev);
pci_intx(pdev, 1);
rc = request_irq(pdev->irq, ntb_interrupt, IRQF_SHARED, "ntb-intx",
ndev);
if (rc)
return rc;
return 0;
}
static int ntb_setup_interrupts(struct ntb_device *ndev)
{
int rc;
if (ndev->hw_type == BWD_HW)
writeq(~0, ndev->reg_ofs.pdb_mask);
else
writew(~(1 << ndev->limits.max_db_bits),
ndev->reg_ofs.pdb_mask);
rc = ntb_setup_msix(ndev);
if (!rc)
goto done;
ndev->bits_per_vector = 1;
ndev->max_cbs = ndev->limits.max_db_bits;
rc = ntb_setup_msi(ndev);
if (!rc)
goto done;
rc = ntb_setup_intx(ndev);
if (rc) {
dev_err(&ndev->pdev->dev, "no usable interrupts\n");
return rc;
}
done:
return 0;
}
static void ntb_free_interrupts(struct ntb_device *ndev)
{
struct pci_dev *pdev = ndev->pdev;
if (ndev->hw_type == BWD_HW)
writeq(~0, ndev->reg_ofs.pdb_mask);
else
writew(~0, ndev->reg_ofs.pdb_mask);
if (ndev->num_msix) {
struct msix_entry *msix;
u32 i;
for (i = 0; i < ndev->num_msix; i++) {
msix = &ndev->msix_entries[i];
if (ndev->hw_type != BWD_HW && i == ndev->num_msix - 1)
free_irq(msix->vector, ndev);
else
free_irq(msix->vector, &ndev->db_cb[i]);
}
pci_disable_msix(pdev);
} else {
free_irq(pdev->irq, ndev);
if (pci_dev_msi_enabled(pdev))
pci_disable_msi(pdev);
}
}
static int ntb_create_callbacks(struct ntb_device *ndev)
{
int i;
ndev->db_cb = kcalloc(ndev->limits.max_db_bits,
sizeof(struct ntb_db_cb),
GFP_KERNEL);
if (!ndev->db_cb)
return -ENOMEM;
for (i = 0; i < ndev->limits.max_db_bits; i++) {
ndev->db_cb[i].db_num = i;
ndev->db_cb[i].ndev = ndev;
}
return 0;
}
static void ntb_free_callbacks(struct ntb_device *ndev)
{
int i;
for (i = 0; i < ndev->limits.max_db_bits; i++)
ntb_unregister_db_callback(ndev, i);
kfree(ndev->db_cb);
}
static int ntb_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct ntb_device *ndev;
int rc, i;
ndev = kzalloc(sizeof(struct ntb_device), GFP_KERNEL);
if (!ndev)
return -ENOMEM;
ndev->pdev = pdev;
ndev->link_status = NTB_LINK_DOWN;
pci_set_drvdata(pdev, ndev);
rc = pci_enable_device(pdev);
if (rc)
goto err;
pci_set_master(ndev->pdev);
rc = pci_request_selected_regions(pdev, NTB_BAR_MASK, KBUILD_MODNAME);
if (rc)
goto err1;
ndev->reg_base = pci_ioremap_bar(pdev, NTB_BAR_MMIO);
if (!ndev->reg_base) {
dev_warn(&pdev->dev, "Cannot remap BAR 0\n");
rc = -EIO;
goto err2;
}
for (i = 0; i < NTB_NUM_MW; i++) {
ndev->mw[i].bar_sz = pci_resource_len(pdev, MW_TO_BAR(i));
ndev->mw[i].vbase =
ioremap_wc(pci_resource_start(pdev, MW_TO_BAR(i)),
ndev->mw[i].bar_sz);
dev_info(&pdev->dev, "MW %d size %llu\n", i,
pci_resource_len(pdev, MW_TO_BAR(i)));
if (!ndev->mw[i].vbase) {
dev_warn(&pdev->dev, "Cannot remap BAR %d\n",
MW_TO_BAR(i));
rc = -EIO;
goto err3;
}
}
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (rc) {
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc)
goto err3;
dev_warn(&pdev->dev, "Cannot DMA highmem\n");
}
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (rc) {
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc)
goto err3;
dev_warn(&pdev->dev, "Cannot DMA consistent highmem\n");
}
rc = ntb_device_setup(ndev);
if (rc)
goto err3;
rc = ntb_create_callbacks(ndev);
if (rc)
goto err4;
rc = ntb_setup_interrupts(ndev);
if (rc)
goto err5;
for (i = 0; i < ndev->limits.max_spads; i++) {
ntb_write_local_spad(ndev, i, 0);
ntb_write_remote_spad(ndev, i, 0);
}
rc = ntb_transport_init(pdev);
if (rc)
goto err6;
writel(NTB_CNTL_BAR23_SNOOP | NTB_CNTL_BAR45_SNOOP,
ndev->reg_ofs.lnk_cntl);
return 0;
err6:
ntb_free_interrupts(ndev);
err5:
ntb_free_callbacks(ndev);
err4:
ntb_device_free(ndev);
err3:
for (i--; i >= 0; i--)
iounmap(ndev->mw[i].vbase);
iounmap(ndev->reg_base);
err2:
pci_release_selected_regions(pdev, NTB_BAR_MASK);
err1:
pci_disable_device(pdev);
err:
kfree(ndev);
dev_err(&pdev->dev, "Error loading %s module\n", KBUILD_MODNAME);
return rc;
}
static void ntb_pci_remove(struct pci_dev *pdev)
{
struct ntb_device *ndev = pci_get_drvdata(pdev);
int i;
u32 ntb_cntl;
ntb_cntl = readl(ndev->reg_ofs.lnk_cntl);
ntb_cntl |= NTB_LINK_DISABLE;
writel(ntb_cntl, ndev->reg_ofs.lnk_cntl);
ntb_transport_free(ndev->ntb_transport);
ntb_free_interrupts(ndev);
ntb_free_callbacks(ndev);
ntb_device_free(ndev);
for (i = 0; i < NTB_NUM_MW; i++)
iounmap(ndev->mw[i].vbase);
iounmap(ndev->reg_base);
pci_release_selected_regions(pdev, NTB_BAR_MASK);
pci_disable_device(pdev);
kfree(ndev);
}
