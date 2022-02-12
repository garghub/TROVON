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
static void ntb_irq_work(unsigned long data)
{
struct ntb_db_cb *db_cb = (struct ntb_db_cb *)data;
int rc;
rc = db_cb->callback(db_cb->data, db_cb->db_num);
if (rc)
tasklet_schedule(&db_cb->irq_work);
else {
struct ntb_device *ndev = db_cb->ndev;
unsigned long mask;
mask = readw(ndev->reg_ofs.ldb_mask);
clear_bit(db_cb->db_num * ndev->bits_per_vector, &mask);
writew(mask, ndev->reg_ofs.ldb_mask);
}
}
int ntb_register_db_callback(struct ntb_device *ndev, unsigned int idx,
void *data, int (*func)(void *data, int db_num))
{
unsigned long mask;
if (idx >= ndev->max_cbs || ndev->db_cb[idx].callback) {
dev_warn(&ndev->pdev->dev, "Invalid Index.\n");
return -EINVAL;
}
ndev->db_cb[idx].callback = func;
ndev->db_cb[idx].data = data;
ndev->db_cb[idx].ndev = ndev;
tasklet_init(&ndev->db_cb[idx].irq_work, ntb_irq_work,
(unsigned long) &ndev->db_cb[idx]);
mask = readw(ndev->reg_ofs.ldb_mask);
clear_bit(idx * ndev->bits_per_vector, &mask);
writew(mask, ndev->reg_ofs.ldb_mask);
return 0;
}
void ntb_unregister_db_callback(struct ntb_device *ndev, unsigned int idx)
{
unsigned long mask;
if (idx >= ndev->max_cbs || !ndev->db_cb[idx].callback)
return;
mask = readw(ndev->reg_ofs.ldb_mask);
set_bit(idx * ndev->bits_per_vector, &mask);
writew(mask, ndev->reg_ofs.ldb_mask);
tasklet_disable(&ndev->db_cb[idx].irq_work);
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
resource_size_t ntb_get_mw_base(struct ntb_device *ndev, unsigned int mw)
{
if (mw >= ntb_max_mw(ndev))
return 0;
return pci_resource_start(ndev->pdev, MW_TO_BAR(mw));
}
void __iomem *ntb_get_mw_vbase(struct ntb_device *ndev, unsigned int mw)
{
if (mw >= ntb_max_mw(ndev))
return NULL;
return ndev->mw[mw].vbase;
}
u64 ntb_get_mw_size(struct ntb_device *ndev, unsigned int mw)
{
if (mw >= ntb_max_mw(ndev))
return 0;
return ndev->mw[mw].bar_sz;
}
void ntb_set_mw_addr(struct ntb_device *ndev, unsigned int mw, u64 addr)
{
if (mw >= ntb_max_mw(ndev))
return;
dev_dbg(&ndev->pdev->dev, "Writing addr %Lx to BAR %d\n", addr,
MW_TO_BAR(mw));
ndev->mw[mw].phys_addr = addr;
switch (MW_TO_BAR(mw)) {
case NTB_BAR_23:
writeq(addr, ndev->reg_ofs.bar2_xlat);
break;
case NTB_BAR_45:
writeq(addr, ndev->reg_ofs.bar4_xlat);
break;
}
}
void ntb_ring_doorbell(struct ntb_device *ndev, unsigned int db)
{
dev_dbg(&ndev->pdev->dev, "%s: ringing doorbell %d\n", __func__, db);
if (ndev->hw_type == BWD_HW)
writeq((u64) 1 << db, ndev->reg_ofs.rdb);
else
writew(((1 << ndev->bits_per_vector) - 1) <<
(db * ndev->bits_per_vector), ndev->reg_ofs.rdb);
}
static void bwd_recover_link(struct ntb_device *ndev)
{
u32 status;
writeb(0xe0, ndev->reg_base + BWD_MODPHY_PCSREG6);
writeb(0x40, ndev->reg_base + BWD_MODPHY_PCSREG4);
writeb(0x60, ndev->reg_base + BWD_MODPHY_PCSREG4);
writeb(0x60, ndev->reg_base + BWD_MODPHY_PCSREG6);
msleep(100);
status = readl(ndev->reg_base + BWD_ERRCORSTS_OFFSET);
dev_dbg(&ndev->pdev->dev, "ERRCORSTS = %x\n", status);
status &= PCI_ERR_COR_REP_ROLL;
writel(status, ndev->reg_base + BWD_ERRCORSTS_OFFSET);
status = readl(ndev->reg_base + BWD_LTSSMERRSTS0_OFFSET);
dev_dbg(&ndev->pdev->dev, "LTSSMERRSTS0 = %x\n", status);
status |= BWD_LTSSMERRSTS0_UNEXPECTEDEI;
writel(status, ndev->reg_base + BWD_LTSSMERRSTS0_OFFSET);
status = readl(ndev->reg_base + BWD_DESKEWSTS_OFFSET);
dev_dbg(&ndev->pdev->dev, "DESKEWSTS = %x\n", status);
status |= BWD_DESKEWSTS_DBERR;
writel(status, ndev->reg_base + BWD_DESKEWSTS_OFFSET);
status = readl(ndev->reg_base + BWD_IBSTERRRCRVSTS0_OFFSET);
dev_dbg(&ndev->pdev->dev, "IBSTERRRCRVSTS0 = %x\n", status);
status &= BWD_IBIST_ERR_OFLOW;
writel(status, ndev->reg_base + BWD_IBSTERRRCRVSTS0_OFFSET);
status = readl(ndev->reg_base + BWD_LTSSMSTATEJMP_OFFSET);
dev_dbg(&ndev->pdev->dev, "LTSSMSTATEJMP = %x\n", status);
status &= ~BWD_LTSSMSTATEJMP_FORCEDETECT;
writel(status, ndev->reg_base + BWD_LTSSMSTATEJMP_OFFSET);
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
if (ndev->hw_type == BWD_HW ||
ndev->conn_type == NTB_CONN_TRANSPARENT)
status = readw(ndev->reg_ofs.lnk_stat);
else {
int rc = pci_read_config_word(ndev->pdev,
SNB_LINK_STATUS_OFFSET,
&status);
if (rc)
return;
}
ndev->link_width = (status & NTB_LINK_WIDTH_MASK) >> 4;
ndev->link_speed = (status & NTB_LINK_SPEED_MASK);
dev_info(&ndev->pdev->dev, "Link Width %d, Link Speed %d\n",
ndev->link_width, ndev->link_speed);
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
static void bwd_link_recovery(struct work_struct *work)
{
struct ntb_device *ndev = container_of(work, struct ntb_device,
lr_timer.work);
u32 status32;
bwd_recover_link(ndev);
msleep(BWD_LINK_RECOVERY_TIME + prandom_u32() % BWD_LINK_RECOVERY_TIME);
status32 = readl(ndev->reg_base + BWD_LTSSMSTATEJMP_OFFSET);
if (status32 & BWD_LTSSMSTATEJMP_FORCEDETECT)
goto retry;
status32 = readl(ndev->reg_base + BWD_IBSTERRRCRVSTS0_OFFSET);
if (status32 & BWD_IBIST_ERR_OFLOW)
goto retry;
status32 = readl(ndev->reg_ofs.lnk_cntl);
if (!(status32 & BWD_CNTL_LINK_DOWN)) {
unsigned char speed, width;
u16 status16;
status16 = readw(ndev->reg_ofs.lnk_stat);
width = (status16 & NTB_LINK_WIDTH_MASK) >> 4;
speed = (status16 & NTB_LINK_SPEED_MASK);
if (ndev->link_width != width || ndev->link_speed != speed)
goto retry;
}
schedule_delayed_work(&ndev->hb_timer, NTB_HB_TIMEOUT);
return;
retry:
schedule_delayed_work(&ndev->lr_timer, NTB_HB_TIMEOUT);
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
if (ndev->link_status == NTB_LINK_DOWN) {
u32 status32 = readl(ndev->reg_base +
BWD_LTSSMSTATEJMP_OFFSET);
if (status32 & BWD_LTSSMSTATEJMP_FORCEDETECT) {
schedule_delayed_work(&ndev->lr_timer, 0);
return;
}
}
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
if (val & SNB_PPD_DEV_TYPE)
ndev->dev_type = NTB_DEV_USD;
else
ndev->dev_type = NTB_DEV_DSD;
switch (val & SNB_PPD_CONN_TYPE) {
case NTB_CONN_B2B:
dev_info(&ndev->pdev->dev, "Conn Type = B2B\n");
ndev->conn_type = NTB_CONN_B2B;
ndev->reg_ofs.ldb = ndev->reg_base + SNB_PDOORBELL_OFFSET;
ndev->reg_ofs.ldb_mask = ndev->reg_base + SNB_PDBMSK_OFFSET;
ndev->reg_ofs.spad_read = ndev->reg_base + SNB_SPAD_OFFSET;
ndev->reg_ofs.bar2_xlat = ndev->reg_base + SNB_SBAR2XLAT_OFFSET;
ndev->reg_ofs.bar4_xlat = ndev->reg_base + SNB_SBAR4XLAT_OFFSET;
ndev->limits.max_spads = SNB_MAX_B2B_SPADS;
if (xeon_errata_workaround) {
if (!ndev->mw[1].bar_sz)
return -EINVAL;
ndev->limits.max_mw = SNB_ERRATA_MAX_MW;
ndev->limits.max_db_bits = SNB_MAX_DB_BITS;
ndev->reg_ofs.spad_write = ndev->mw[1].vbase +
SNB_SPAD_OFFSET;
ndev->reg_ofs.rdb = ndev->mw[1].vbase +
SNB_PDOORBELL_OFFSET;
writeq(ndev->mw[1].bar_sz + 0x1000, ndev->reg_base +
SNB_PBAR4LMT_OFFSET);
} else {
ndev->limits.max_mw = SNB_MAX_MW;
ndev->limits.max_db_bits = SNB_MAX_DB_BITS - 1;
ndev->reg_ofs.spad_write = ndev->reg_base +
SNB_B2B_SPAD_OFFSET;
ndev->reg_ofs.rdb = ndev->reg_base +
SNB_B2B_DOORBELL_OFFSET;
writeq(0, ndev->reg_base + SNB_PBAR4LMT_OFFSET);
}
if (ndev->dev_type == NTB_DEV_USD) {
writeq(SNB_MBAR23_DSD_ADDR, ndev->reg_base +
SNB_PBAR2XLAT_OFFSET);
if (xeon_errata_workaround)
writeq(SNB_MBAR01_DSD_ADDR, ndev->reg_base +
SNB_PBAR4XLAT_OFFSET);
else {
writeq(SNB_MBAR45_DSD_ADDR, ndev->reg_base +
SNB_PBAR4XLAT_OFFSET);
writel(SNB_MBAR01_DSD_ADDR & 0xffffffff,
ndev->reg_base + SNB_B2B_XLAT_OFFSETL);
writel(SNB_MBAR01_DSD_ADDR >> 32,
ndev->reg_base + SNB_B2B_XLAT_OFFSETU);
}
writeq(SNB_MBAR01_USD_ADDR, ndev->reg_base +
SNB_SBAR0BASE_OFFSET);
writeq(SNB_MBAR23_USD_ADDR, ndev->reg_base +
SNB_SBAR2BASE_OFFSET);
writeq(SNB_MBAR45_USD_ADDR, ndev->reg_base +
SNB_SBAR4BASE_OFFSET);
} else {
writeq(SNB_MBAR23_USD_ADDR, ndev->reg_base +
SNB_PBAR2XLAT_OFFSET);
if (xeon_errata_workaround)
writeq(SNB_MBAR01_USD_ADDR, ndev->reg_base +
SNB_PBAR4XLAT_OFFSET);
else {
writeq(SNB_MBAR45_USD_ADDR, ndev->reg_base +
SNB_PBAR4XLAT_OFFSET);
writel(SNB_MBAR01_DSD_ADDR & 0xffffffff,
ndev->reg_base + SNB_B2B_XLAT_OFFSETL);
writel(SNB_MBAR01_USD_ADDR >> 32,
ndev->reg_base + SNB_B2B_XLAT_OFFSETU);
}
writeq(SNB_MBAR01_DSD_ADDR, ndev->reg_base +
SNB_SBAR0BASE_OFFSET);
writeq(SNB_MBAR23_DSD_ADDR, ndev->reg_base +
SNB_SBAR2BASE_OFFSET);
writeq(SNB_MBAR45_DSD_ADDR, ndev->reg_base +
SNB_SBAR4BASE_OFFSET);
}
break;
case NTB_CONN_RP:
dev_info(&ndev->pdev->dev, "Conn Type = RP\n");
ndev->conn_type = NTB_CONN_RP;
if (xeon_errata_workaround) {
dev_err(&ndev->pdev->dev,
"NTB-RP disabled due to hardware errata. To disregard this warning and potentially lock-up the system, add the parameter 'xeon_errata_workaround=0'.\n");
return -EINVAL;
}
ndev->limits.max_spads = SNB_MAX_COMPAT_SPADS / 2;
ndev->limits.max_db_bits = SNB_MAX_DB_BITS;
ndev->reg_ofs.rdb = ndev->reg_base + SNB_SDOORBELL_OFFSET;
ndev->reg_ofs.ldb = ndev->reg_base + SNB_PDOORBELL_OFFSET;
ndev->reg_ofs.ldb_mask = ndev->reg_base + SNB_PDBMSK_OFFSET;
ndev->reg_ofs.spad_write = ndev->reg_base + SNB_SPAD_OFFSET +
ndev->limits.max_spads * 4;
ndev->reg_ofs.spad_read = ndev->reg_base + SNB_SPAD_OFFSET;
ndev->reg_ofs.bar2_xlat = ndev->reg_base + SNB_SBAR2XLAT_OFFSET;
ndev->reg_ofs.bar4_xlat = ndev->reg_base + SNB_SBAR4XLAT_OFFSET;
ndev->limits.max_mw = SNB_MAX_MW;
break;
case NTB_CONN_TRANSPARENT:
dev_info(&ndev->pdev->dev, "Conn Type = TRANSPARENT\n");
ndev->conn_type = NTB_CONN_TRANSPARENT;
ndev->limits.max_spads = SNB_MAX_COMPAT_SPADS / 2;
ndev->limits.max_db_bits = SNB_MAX_DB_BITS;
ndev->reg_ofs.rdb = ndev->reg_base + SNB_PDOORBELL_OFFSET;
ndev->reg_ofs.ldb = ndev->reg_base + SNB_SDOORBELL_OFFSET;
ndev->reg_ofs.ldb_mask = ndev->reg_base + SNB_SDBMSK_OFFSET;
ndev->reg_ofs.spad_write = ndev->reg_base + SNB_SPAD_OFFSET;
ndev->reg_ofs.spad_read = ndev->reg_base + SNB_SPAD_OFFSET +
ndev->limits.max_spads * 4;
ndev->reg_ofs.bar2_xlat = ndev->reg_base + SNB_PBAR2XLAT_OFFSET;
ndev->reg_ofs.bar4_xlat = ndev->reg_base + SNB_PBAR4XLAT_OFFSET;
ndev->limits.max_mw = SNB_MAX_MW;
break;
default:
dev_err(&ndev->pdev->dev, "Unknown PPD %x\n", val);
return -EINVAL;
}
ndev->reg_ofs.lnk_cntl = ndev->reg_base + SNB_NTBCNTL_OFFSET;
ndev->reg_ofs.lnk_stat = ndev->reg_base + SNB_SLINK_STATUS_OFFSET;
ndev->reg_ofs.spci_cmd = ndev->reg_base + SNB_PCICMD_OFFSET;
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
dev_err(&ndev->pdev->dev, "Unsupported NTB configuration\n");
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
ndev->reg_ofs.ldb = ndev->reg_base + BWD_PDOORBELL_OFFSET;
ndev->reg_ofs.ldb_mask = ndev->reg_base + BWD_PDBMSK_OFFSET;
ndev->reg_ofs.rdb = ndev->reg_base + BWD_B2B_DOORBELL_OFFSET;
ndev->reg_ofs.bar2_xlat = ndev->reg_base + BWD_SBAR2XLAT_OFFSET;
ndev->reg_ofs.bar4_xlat = ndev->reg_base + BWD_SBAR4XLAT_OFFSET;
ndev->reg_ofs.lnk_cntl = ndev->reg_base + BWD_NTBCNTL_OFFSET;
ndev->reg_ofs.lnk_stat = ndev->reg_base + BWD_LINK_STATUS_OFFSET;
ndev->reg_ofs.spad_read = ndev->reg_base + BWD_SPAD_OFFSET;
ndev->reg_ofs.spad_write = ndev->reg_base + BWD_B2B_SPAD_OFFSET;
ndev->reg_ofs.spci_cmd = ndev->reg_base + BWD_PCICMD_OFFSET;
ndev->limits.max_mw = BWD_MAX_MW;
ndev->limits.max_spads = BWD_MAX_SPADS;
ndev->limits.max_db_bits = BWD_MAX_DB_BITS;
ndev->limits.msix_cnt = BWD_MSIX_CNT;
ndev->bits_per_vector = BWD_DB_BITS_PER_VEC;
INIT_DELAYED_WORK(&ndev->hb_timer, bwd_link_poll);
INIT_DELAYED_WORK(&ndev->lr_timer, bwd_link_recovery);
schedule_delayed_work(&ndev->hb_timer, NTB_HB_TIMEOUT);
return 0;
}
static int ntb_device_setup(struct ntb_device *ndev)
{
int rc;
switch (ndev->pdev->device) {
case PCI_DEVICE_ID_INTEL_NTB_SS_JSF:
case PCI_DEVICE_ID_INTEL_NTB_SS_SNB:
case PCI_DEVICE_ID_INTEL_NTB_SS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_SS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_PS_JSF:
case PCI_DEVICE_ID_INTEL_NTB_PS_SNB:
case PCI_DEVICE_ID_INTEL_NTB_PS_IVT:
case PCI_DEVICE_ID_INTEL_NTB_PS_HSX:
case PCI_DEVICE_ID_INTEL_NTB_B2B_JSF:
case PCI_DEVICE_ID_INTEL_NTB_B2B_SNB:
case PCI_DEVICE_ID_INTEL_NTB_B2B_IVT:
case PCI_DEVICE_ID_INTEL_NTB_B2B_HSX:
rc = ntb_xeon_setup(ndev);
break;
case PCI_DEVICE_ID_INTEL_NTB_B2B_BWD:
rc = ntb_bwd_setup(ndev);
break;
default:
rc = -ENODEV;
}
if (rc)
return rc;
dev_info(&ndev->pdev->dev, "Device Type = %s\n",
ndev->dev_type == NTB_DEV_USD ? "USD/DSP" : "DSD/USP");
if (ndev->conn_type == NTB_CONN_B2B)
writew(PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER,
ndev->reg_ofs.spci_cmd);
return 0;
}
static void ntb_device_free(struct ntb_device *ndev)
{
if (ndev->hw_type == BWD_HW) {
cancel_delayed_work_sync(&ndev->hb_timer);
cancel_delayed_work_sync(&ndev->lr_timer);
}
}
static irqreturn_t bwd_callback_msix_irq(int irq, void *data)
{
struct ntb_db_cb *db_cb = data;
struct ntb_device *ndev = db_cb->ndev;
unsigned long mask;
dev_dbg(&ndev->pdev->dev, "MSI-X irq %d received for DB %d\n", irq,
db_cb->db_num);
mask = readw(ndev->reg_ofs.ldb_mask);
set_bit(db_cb->db_num * ndev->bits_per_vector, &mask);
writew(mask, ndev->reg_ofs.ldb_mask);
tasklet_schedule(&db_cb->irq_work);
ndev->last_ts = jiffies;
writeq((u64) 1 << db_cb->db_num, ndev->reg_ofs.ldb);
return IRQ_HANDLED;
}
static irqreturn_t xeon_callback_msix_irq(int irq, void *data)
{
struct ntb_db_cb *db_cb = data;
struct ntb_device *ndev = db_cb->ndev;
unsigned long mask;
dev_dbg(&ndev->pdev->dev, "MSI-X irq %d received for DB %d\n", irq,
db_cb->db_num);
mask = readw(ndev->reg_ofs.ldb_mask);
set_bit(db_cb->db_num * ndev->bits_per_vector, &mask);
writew(mask, ndev->reg_ofs.ldb_mask);
tasklet_schedule(&db_cb->irq_work);
writew(((1 << ndev->bits_per_vector) - 1) <<
(db_cb->db_num * ndev->bits_per_vector), ndev->reg_ofs.ldb);
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
writew(1 << SNB_LINK_DB, ndev->reg_ofs.ldb);
return IRQ_HANDLED;
}
static irqreturn_t ntb_interrupt(int irq, void *dev)
{
struct ntb_device *ndev = dev;
unsigned int i = 0;
if (ndev->hw_type == BWD_HW) {
u64 ldb = readq(ndev->reg_ofs.ldb);
dev_dbg(&ndev->pdev->dev, "irq %d - ldb = %Lx\n", irq, ldb);
while (ldb) {
i = __ffs(ldb);
ldb &= ldb - 1;
bwd_callback_msix_irq(irq, &ndev->db_cb[i]);
}
} else {
u16 ldb = readw(ndev->reg_ofs.ldb);
dev_dbg(&ndev->pdev->dev, "irq %d - ldb = %x\n", irq, ldb);
if (ldb & SNB_DB_HW_LINK) {
xeon_event_msix_irq(irq, dev);
ldb &= ~SNB_DB_HW_LINK;
}
while (ldb) {
i = __ffs(ldb);
ldb &= ldb - 1;
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
int rc, i;
u16 val;
if (!pdev->msix_cap) {
rc = -EIO;
goto err;
}
rc = pci_read_config_word(pdev, pdev->msix_cap + PCI_MSIX_FLAGS, &val);
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
rc = pci_enable_msix(pdev, ndev->msix_entries, msix_entries);
if (rc)
goto err1;
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
writeq(~0, ndev->reg_ofs.ldb_mask);
else {
u16 var = 1 << SNB_LINK_DB;
writew(~var, ndev->reg_ofs.ldb_mask);
}
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
writeq(~0, ndev->reg_ofs.ldb_mask);
else
writew(~0, ndev->reg_ofs.ldb_mask);
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
static void ntb_setup_debugfs(struct ntb_device *ndev)
{
if (!debugfs_initialized())
return;
if (!debugfs_dir)
debugfs_dir = debugfs_create_dir(KBUILD_MODNAME, NULL);
ndev->debugfs_dir = debugfs_create_dir(pci_name(ndev->pdev),
debugfs_dir);
}
static void ntb_free_debugfs(struct ntb_device *ndev)
{
debugfs_remove_recursive(ndev->debugfs_dir);
if (debugfs_dir && simple_empty(debugfs_dir)) {
debugfs_remove_recursive(debugfs_dir);
debugfs_dir = NULL;
}
}
static void ntb_hw_link_up(struct ntb_device *ndev)
{
if (ndev->conn_type == NTB_CONN_TRANSPARENT)
ntb_link_event(ndev, NTB_LINK_UP);
else {
u32 ntb_cntl;
ntb_cntl = readl(ndev->reg_ofs.lnk_cntl);
ntb_cntl &= ~(NTB_CNTL_LINK_DISABLE | NTB_CNTL_CFG_LOCK);
ntb_cntl |= NTB_CNTL_P2S_BAR23_SNOOP | NTB_CNTL_S2P_BAR23_SNOOP;
ntb_cntl |= NTB_CNTL_P2S_BAR45_SNOOP | NTB_CNTL_S2P_BAR45_SNOOP;
writel(ntb_cntl, ndev->reg_ofs.lnk_cntl);
}
}
static void ntb_hw_link_down(struct ntb_device *ndev)
{
u32 ntb_cntl;
if (ndev->conn_type == NTB_CONN_TRANSPARENT) {
ntb_link_event(ndev, NTB_LINK_DOWN);
return;
}
ntb_cntl = readl(ndev->reg_ofs.lnk_cntl);
ntb_cntl &= ~(NTB_CNTL_P2S_BAR23_SNOOP | NTB_CNTL_S2P_BAR23_SNOOP);
ntb_cntl &= ~(NTB_CNTL_P2S_BAR45_SNOOP | NTB_CNTL_S2P_BAR45_SNOOP);
ntb_cntl |= NTB_CNTL_LINK_DISABLE | NTB_CNTL_CFG_LOCK;
writel(ntb_cntl, ndev->reg_ofs.lnk_cntl);
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
ntb_setup_debugfs(ndev);
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
for (i = 0; i < NTB_MAX_NUM_MW; i++) {
ndev->mw[i].bar_sz = pci_resource_len(pdev, MW_TO_BAR(i));
ndev->mw[i].vbase =
ioremap_wc(pci_resource_start(pdev, MW_TO_BAR(i)),
ndev->mw[i].bar_sz);
dev_info(&pdev->dev, "MW %d size %llu\n", i,
(unsigned long long) ndev->mw[i].bar_sz);
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
ntb_hw_link_up(ndev);
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
ntb_free_debugfs(ndev);
kfree(ndev);
dev_err(&pdev->dev, "Error loading %s module\n", KBUILD_MODNAME);
return rc;
}
static void ntb_pci_remove(struct pci_dev *pdev)
{
struct ntb_device *ndev = pci_get_drvdata(pdev);
int i;
ntb_hw_link_down(ndev);
ntb_transport_free(ndev->ntb_transport);
ntb_free_interrupts(ndev);
ntb_free_callbacks(ndev);
ntb_device_free(ndev);
for (i = 0; i < NTB_MAX_NUM_MW; i++)
iounmap(ndev->mw[i].vbase);
iounmap(ndev->reg_base);
pci_release_selected_regions(pdev, NTB_BAR_MASK);
pci_disable_device(pdev);
ntb_free_debugfs(ndev);
kfree(ndev);
}
