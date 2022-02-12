static u32 hisi_sas_read32(struct hisi_hba *hisi_hba, u32 off)
{
void __iomem *regs = hisi_hba->regs + off;
return readl(regs);
}
static u32 hisi_sas_read32_relaxed(struct hisi_hba *hisi_hba, u32 off)
{
void __iomem *regs = hisi_hba->regs + off;
return readl_relaxed(regs);
}
static void hisi_sas_write32(struct hisi_hba *hisi_hba,
u32 off, u32 val)
{
void __iomem *regs = hisi_hba->regs + off;
writel(val, regs);
}
static void hisi_sas_phy_write32(struct hisi_hba *hisi_hba,
int phy_no, u32 off, u32 val)
{
void __iomem *regs = hisi_hba->regs + (0x400 * phy_no) + off;
writel(val, regs);
}
static u32 hisi_sas_phy_read32(struct hisi_hba *hisi_hba,
int phy_no, u32 off)
{
void __iomem *regs = hisi_hba->regs + (0x400 * phy_no) + off;
return readl(regs);
}
static void config_phy_opt_mode_v1_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CFG);
cfg &= ~PHY_CFG_DC_OPT_MSK;
cfg |= 1 << PHY_CFG_DC_OPT_OFF;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CFG, cfg);
}
static void config_tx_tfe_autoneg_v1_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CONFIG2);
cfg &= ~PHY_CONFIG2_FORCE_TXDEEMPH_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CONFIG2, cfg);
}
static void config_id_frame_v1_hw(struct hisi_hba *hisi_hba, int phy_no)
{
struct sas_identify_frame identify_frame;
u32 *identify_buffer;
memset(&identify_frame, 0, sizeof(identify_frame));
identify_frame.dev_type = SAS_END_DEVICE;
identify_frame.frame_type = 0;
identify_frame._un1 = 1;
identify_frame.initiator_bits = SAS_PROTOCOL_ALL;
identify_frame.target_bits = SAS_PROTOCOL_NONE;
memcpy(&identify_frame._un4_11[0], hisi_hba->sas_addr, SAS_ADDR_SIZE);
memcpy(&identify_frame.sas_addr[0], hisi_hba->sas_addr, SAS_ADDR_SIZE);
identify_frame.phy_id = phy_no;
identify_buffer = (u32 *)(&identify_frame);
hisi_sas_phy_write32(hisi_hba, phy_no, TX_ID_DWORD0,
__swab32(identify_buffer[0]));
hisi_sas_phy_write32(hisi_hba, phy_no, TX_ID_DWORD1,
__swab32(identify_buffer[1]));
hisi_sas_phy_write32(hisi_hba, phy_no, TX_ID_DWORD2,
__swab32(identify_buffer[2]));
hisi_sas_phy_write32(hisi_hba, phy_no, TX_ID_DWORD3,
__swab32(identify_buffer[3]));
hisi_sas_phy_write32(hisi_hba, phy_no, TX_ID_DWORD4,
__swab32(identify_buffer[4]));
hisi_sas_phy_write32(hisi_hba, phy_no, TX_ID_DWORD5,
__swab32(identify_buffer[5]));
}
static void setup_itct_v1_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_device *sas_dev)
{
struct domain_device *device = sas_dev->sas_device;
struct device *dev = hisi_hba->dev;
u64 qw0, device_id = sas_dev->device_id;
struct hisi_sas_itct *itct = &hisi_hba->itct[device_id];
struct asd_sas_port *sas_port = device->port;
struct hisi_sas_port *port = to_hisi_sas_port(sas_port);
memset(itct, 0, sizeof(*itct));
qw0 = 0;
switch (sas_dev->dev_type) {
case SAS_END_DEVICE:
case SAS_EDGE_EXPANDER_DEVICE:
case SAS_FANOUT_EXPANDER_DEVICE:
qw0 = HISI_SAS_DEV_TYPE_SSP << ITCT_HDR_DEV_TYPE_OFF;
break;
default:
dev_warn(dev, "setup itct: unsupported dev type (%d)\n",
sas_dev->dev_type);
}
qw0 |= ((1 << ITCT_HDR_VALID_OFF) |
(1 << ITCT_HDR_AWT_CONTROL_OFF) |
(device->max_linkrate << ITCT_HDR_MAX_CONN_RATE_OFF) |
(1 << ITCT_HDR_VALID_LINK_NUM_OFF) |
(port->id << ITCT_HDR_PORT_ID_OFF));
itct->qw0 = cpu_to_le64(qw0);
memcpy(&itct->sas_addr, device->sas_addr, SAS_ADDR_SIZE);
itct->sas_addr = __swab64(itct->sas_addr);
itct->qw2 = cpu_to_le64((500ULL << ITCT_HDR_IT_NEXUS_LOSS_TL_OFF) |
(0xff00ULL << ITCT_HDR_BUS_INACTIVE_TL_OFF) |
(0xff00ULL << ITCT_HDR_MAX_CONN_TL_OFF) |
(0xff00ULL << ITCT_HDR_REJ_OPEN_TL_OFF));
}
static void free_device_v1_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_device *sas_dev)
{
u64 dev_id = sas_dev->device_id;
struct hisi_sas_itct *itct = &hisi_hba->itct[dev_id];
u64 qw0;
u32 reg_val = hisi_sas_read32(hisi_hba, CFG_AGING_TIME);
reg_val |= CFG_AGING_TIME_ITCT_REL_MSK;
hisi_sas_write32(hisi_hba, CFG_AGING_TIME, reg_val);
udelay(1);
reg_val = hisi_sas_read32(hisi_hba, CFG_AGING_TIME);
reg_val &= ~CFG_AGING_TIME_ITCT_REL_MSK;
hisi_sas_write32(hisi_hba, CFG_AGING_TIME, reg_val);
qw0 = cpu_to_le64(itct->qw0);
qw0 &= ~ITCT_HDR_VALID_MSK;
itct->qw0 = cpu_to_le64(qw0);
}
static int reset_hw_v1_hw(struct hisi_hba *hisi_hba)
{
int i;
unsigned long end_time;
u32 val;
struct device *dev = hisi_hba->dev;
for (i = 0; i < hisi_hba->n_phy; i++) {
u32 phy_ctrl = hisi_sas_phy_read32(hisi_hba, i, PHY_CTRL);
phy_ctrl |= PHY_CTRL_RESET_MSK;
hisi_sas_phy_write32(hisi_hba, i, PHY_CTRL, phy_ctrl);
}
msleep(1);
for (i = 0; i < hisi_hba->n_phy; i++) {
u32 dma_tx_status, dma_rx_status;
end_time = jiffies + msecs_to_jiffies(1000);
while (1) {
dma_tx_status = hisi_sas_phy_read32(hisi_hba, i,
DMA_TX_STATUS);
dma_rx_status = hisi_sas_phy_read32(hisi_hba, i,
DMA_RX_STATUS);
if (!(dma_tx_status & DMA_TX_STATUS_BUSY_MSK) &&
!(dma_rx_status & DMA_RX_STATUS_BUSY_MSK))
break;
msleep(20);
if (time_after(jiffies, end_time))
return -EIO;
}
}
end_time = jiffies + msecs_to_jiffies(1000);
while (1) {
u32 axi_status =
hisi_sas_read32(hisi_hba, AXI_CFG);
if (axi_status == 0)
break;
msleep(20);
if (time_after(jiffies, end_time))
return -EIO;
}
if (ACPI_HANDLE(dev)) {
acpi_status s;
s = acpi_evaluate_object(ACPI_HANDLE(dev), "_RST", NULL, NULL);
if (ACPI_FAILURE(s)) {
dev_err(dev, "Reset failed\n");
return -EIO;
}
} else if (hisi_hba->ctrl) {
regmap_write(hisi_hba->ctrl, hisi_hba->ctrl_reset_reg,
RESET_VALUE);
regmap_write(hisi_hba->ctrl, hisi_hba->ctrl_clock_ena_reg + 4,
RESET_VALUE);
msleep(1);
regmap_read(hisi_hba->ctrl, hisi_hba->ctrl_reset_sts_reg, &val);
if (RESET_VALUE != (val & RESET_VALUE)) {
dev_err(dev, "Reset failed\n");
return -EIO;
}
regmap_write(hisi_hba->ctrl, hisi_hba->ctrl_reset_reg + 4,
RESET_VALUE);
regmap_write(hisi_hba->ctrl, hisi_hba->ctrl_clock_ena_reg,
RESET_VALUE);
msleep(1);
regmap_read(hisi_hba->ctrl, hisi_hba->ctrl_reset_sts_reg, &val);
if (val & RESET_VALUE) {
dev_err(dev, "De-reset failed\n");
return -EIO;
}
} else
dev_warn(dev, "no reset method\n");
return 0;
}
static void init_reg_v1_hw(struct hisi_hba *hisi_hba)
{
int i;
hisi_sas_write32(hisi_hba, DLVRY_QUEUE_ENABLE,
(u32)((1ULL << hisi_hba->queue_count) - 1));
hisi_sas_write32(hisi_hba, HGC_TRANS_TASK_CNT_LIMIT, 0x11);
hisi_sas_write32(hisi_hba, DEVICE_MSG_WORK_MODE, 0x1);
hisi_sas_write32(hisi_hba, HGC_SAS_TXFAIL_RETRY_CTRL, 0x1ff);
hisi_sas_write32(hisi_hba, HGC_ERR_STAT_EN, 0x401);
hisi_sas_write32(hisi_hba, CFG_1US_TIMER_TRSH, 0x64);
hisi_sas_write32(hisi_hba, HGC_GET_ITV_TIME, 0x1);
hisi_sas_write32(hisi_hba, I_T_NEXUS_LOSS_TIME, 0x64);
hisi_sas_write32(hisi_hba, BUS_INACTIVE_LIMIT_TIME, 0x2710);
hisi_sas_write32(hisi_hba, REJECT_TO_OPEN_LIMIT_TIME, 0x1);
hisi_sas_write32(hisi_hba, CFG_AGING_TIME, 0x7a12);
hisi_sas_write32(hisi_hba, HGC_DFX_CFG2, 0x9c40);
hisi_sas_write32(hisi_hba, FIS_LIST_BADDR_L, 0x2);
hisi_sas_write32(hisi_hba, INT_COAL_EN, 0xc);
hisi_sas_write32(hisi_hba, OQ_INT_COAL_TIME, 0x186a0);
hisi_sas_write32(hisi_hba, OQ_INT_COAL_CNT, 1);
hisi_sas_write32(hisi_hba, ENT_INT_COAL_TIME, 0x1);
hisi_sas_write32(hisi_hba, ENT_INT_COAL_CNT, 0x1);
hisi_sas_write32(hisi_hba, OQ_INT_SRC, 0xffffffff);
hisi_sas_write32(hisi_hba, OQ_INT_SRC_MSK, 0);
hisi_sas_write32(hisi_hba, ENT_INT_SRC1, 0xffffffff);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK1, 0);
hisi_sas_write32(hisi_hba, ENT_INT_SRC2, 0xffffffff);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK2, 0);
hisi_sas_write32(hisi_hba, SAS_ECC_INTR_MSK, 0);
hisi_sas_write32(hisi_hba, AXI_AHB_CLK_CFG, 0x2);
hisi_sas_write32(hisi_hba, CFG_SAS_CONFIG, 0x22000000);
for (i = 0; i < hisi_hba->n_phy; i++) {
hisi_sas_phy_write32(hisi_hba, i, PROG_PHY_LINK_RATE, 0x88a);
hisi_sas_phy_write32(hisi_hba, i, PHY_CONFIG2, 0x7c080);
hisi_sas_phy_write32(hisi_hba, i, PHY_RATE_NEGO, 0x415ee00);
hisi_sas_phy_write32(hisi_hba, i, PHY_PCN, 0x80a80000);
hisi_sas_phy_write32(hisi_hba, i, SL_TOUT_CFG, 0x7d7d7d7d);
hisi_sas_phy_write32(hisi_hba, i, DONE_RECEIVED_TIME, 0x0);
hisi_sas_phy_write32(hisi_hba, i, RXOP_CHECK_CFG_H, 0x1000);
hisi_sas_phy_write32(hisi_hba, i, DONE_RECEIVED_TIME, 0);
hisi_sas_phy_write32(hisi_hba, i, CON_CFG_DRIVER, 0x13f0a);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT_COAL_EN, 3);
hisi_sas_phy_write32(hisi_hba, i, DONE_RECEIVED_TIME, 8);
}
for (i = 0; i < hisi_hba->queue_count; i++) {
hisi_sas_write32(hisi_hba,
DLVRY_Q_0_BASE_ADDR_HI + (i * 0x14),
upper_32_bits(hisi_hba->cmd_hdr_dma[i]));
hisi_sas_write32(hisi_hba,
DLVRY_Q_0_BASE_ADDR_LO + (i * 0x14),
lower_32_bits(hisi_hba->cmd_hdr_dma[i]));
hisi_sas_write32(hisi_hba,
DLVRY_Q_0_DEPTH + (i * 0x14),
HISI_SAS_QUEUE_SLOTS);
hisi_sas_write32(hisi_hba,
COMPL_Q_0_BASE_ADDR_HI + (i * 0x14),
upper_32_bits(hisi_hba->complete_hdr_dma[i]));
hisi_sas_write32(hisi_hba,
COMPL_Q_0_BASE_ADDR_LO + (i * 0x14),
lower_32_bits(hisi_hba->complete_hdr_dma[i]));
hisi_sas_write32(hisi_hba, COMPL_Q_0_DEPTH + (i * 0x14),
HISI_SAS_QUEUE_SLOTS);
}
hisi_sas_write32(hisi_hba, ITCT_BASE_ADDR_LO,
lower_32_bits(hisi_hba->itct_dma));
hisi_sas_write32(hisi_hba, ITCT_BASE_ADDR_HI,
upper_32_bits(hisi_hba->itct_dma));
hisi_sas_write32(hisi_hba, IOST_BASE_ADDR_LO,
lower_32_bits(hisi_hba->iost_dma));
hisi_sas_write32(hisi_hba, IOST_BASE_ADDR_HI,
upper_32_bits(hisi_hba->iost_dma));
hisi_sas_write32(hisi_hba, BROKEN_MSG_ADDR_LO,
lower_32_bits(hisi_hba->breakpoint_dma));
hisi_sas_write32(hisi_hba, BROKEN_MSG_ADDR_HI,
upper_32_bits(hisi_hba->breakpoint_dma));
}
static int hw_init_v1_hw(struct hisi_hba *hisi_hba)
{
struct device *dev = hisi_hba->dev;
int rc;
rc = reset_hw_v1_hw(hisi_hba);
if (rc) {
dev_err(dev, "hisi_sas_reset_hw failed, rc=%d", rc);
return rc;
}
msleep(100);
init_reg_v1_hw(hisi_hba);
return 0;
}
static void enable_phy_v1_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CFG);
cfg |= PHY_CFG_ENA_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CFG, cfg);
}
static void disable_phy_v1_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CFG);
cfg &= ~PHY_CFG_ENA_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CFG, cfg);
}
static void start_phy_v1_hw(struct hisi_hba *hisi_hba, int phy_no)
{
config_id_frame_v1_hw(hisi_hba, phy_no);
config_phy_opt_mode_v1_hw(hisi_hba, phy_no);
config_tx_tfe_autoneg_v1_hw(hisi_hba, phy_no);
enable_phy_v1_hw(hisi_hba, phy_no);
}
static void stop_phy_v1_hw(struct hisi_hba *hisi_hba, int phy_no)
{
disable_phy_v1_hw(hisi_hba, phy_no);
}
static void phy_hard_reset_v1_hw(struct hisi_hba *hisi_hba, int phy_no)
{
stop_phy_v1_hw(hisi_hba, phy_no);
msleep(100);
start_phy_v1_hw(hisi_hba, phy_no);
}
static void start_phys_v1_hw(unsigned long data)
{
struct hisi_hba *hisi_hba = (struct hisi_hba *)data;
int i;
for (i = 0; i < hisi_hba->n_phy; i++) {
hisi_sas_phy_write32(hisi_hba, i, CHL_INT2_MSK, 0x12a);
start_phy_v1_hw(hisi_hba, i);
}
}
static void phys_init_v1_hw(struct hisi_hba *hisi_hba)
{
int i;
struct timer_list *timer = &hisi_hba->timer;
for (i = 0; i < hisi_hba->n_phy; i++) {
hisi_sas_phy_write32(hisi_hba, i, CHL_INT2_MSK, 0x6a);
hisi_sas_phy_read32(hisi_hba, i, CHL_INT2_MSK);
}
setup_timer(timer, start_phys_v1_hw, (unsigned long)hisi_hba);
mod_timer(timer, jiffies + HZ);
}
static void sl_notify_v1_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 sl_control;
sl_control = hisi_sas_phy_read32(hisi_hba, phy_no, SL_CONTROL);
sl_control |= SL_CONTROL_NOTIFY_EN_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, SL_CONTROL, sl_control);
msleep(1);
sl_control = hisi_sas_phy_read32(hisi_hba, phy_no, SL_CONTROL);
sl_control &= ~SL_CONTROL_NOTIFY_EN_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, SL_CONTROL, sl_control);
}
static enum sas_linkrate phy_get_max_linkrate_v1_hw(void)
{
return SAS_LINK_RATE_6_0_GBPS;
}
static void phy_set_linkrate_v1_hw(struct hisi_hba *hisi_hba, int phy_no,
struct sas_phy_linkrates *r)
{
u32 prog_phy_link_rate =
hisi_sas_phy_read32(hisi_hba, phy_no, PROG_PHY_LINK_RATE);
struct hisi_sas_phy *phy = &hisi_hba->phy[phy_no];
struct asd_sas_phy *sas_phy = &phy->sas_phy;
int i;
enum sas_linkrate min, max;
u32 rate_mask = 0;
if (r->maximum_linkrate == SAS_LINK_RATE_UNKNOWN) {
max = sas_phy->phy->maximum_linkrate;
min = r->minimum_linkrate;
} else if (r->minimum_linkrate == SAS_LINK_RATE_UNKNOWN) {
max = r->maximum_linkrate;
min = sas_phy->phy->minimum_linkrate;
} else
return;
sas_phy->phy->maximum_linkrate = max;
sas_phy->phy->minimum_linkrate = min;
min -= SAS_LINK_RATE_1_5_GBPS;
max -= SAS_LINK_RATE_1_5_GBPS;
for (i = 0; i <= max; i++)
rate_mask |= 1 << (i * 2);
prog_phy_link_rate &= ~0xff;
prog_phy_link_rate |= rate_mask;
hisi_sas_phy_write32(hisi_hba, phy_no, PROG_PHY_LINK_RATE,
prog_phy_link_rate);
phy_hard_reset_v1_hw(hisi_hba, phy_no);
}
static int get_wideport_bitmap_v1_hw(struct hisi_hba *hisi_hba, int port_id)
{
int i, bitmap = 0;
u32 phy_port_num_ma = hisi_sas_read32(hisi_hba, PHY_PORT_NUM_MA);
for (i = 0; i < hisi_hba->n_phy; i++)
if (((phy_port_num_ma >> (i * 4)) & 0xf) == port_id)
bitmap |= 1 << i;
return bitmap;
}
static int
get_free_slot_v1_hw(struct hisi_hba *hisi_hba, struct hisi_sas_dq *dq)
{
struct device *dev = hisi_hba->dev;
int queue = dq->id;
u32 r, w;
w = dq->wr_point;
r = hisi_sas_read32_relaxed(hisi_hba,
DLVRY_Q_0_RD_PTR + (queue * 0x14));
if (r == (w+1) % HISI_SAS_QUEUE_SLOTS) {
dev_warn(dev, "could not find free slot\n");
return -EAGAIN;
}
return 0;
}
static void start_delivery_v1_hw(struct hisi_sas_dq *dq)
{
struct hisi_hba *hisi_hba = dq->hisi_hba;
int dlvry_queue = dq->slot_prep->dlvry_queue;
int dlvry_queue_slot = dq->slot_prep->dlvry_queue_slot;
dq->wr_point = ++dlvry_queue_slot % HISI_SAS_QUEUE_SLOTS;
hisi_sas_write32(hisi_hba, DLVRY_Q_0_WR_PTR + (dlvry_queue * 0x14),
dq->wr_point);
}
static int prep_prd_sge_v1_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot,
struct hisi_sas_cmd_hdr *hdr,
struct scatterlist *scatter,
int n_elem)
{
struct hisi_sas_sge_page *sge_page = hisi_sas_sge_addr_mem(slot);
struct device *dev = hisi_hba->dev;
struct scatterlist *sg;
int i;
if (n_elem > HISI_SAS_SGE_PAGE_CNT) {
dev_err(dev, "prd err: n_elem(%d) > HISI_SAS_SGE_PAGE_CNT",
n_elem);
return -EINVAL;
}
for_each_sg(scatter, sg, n_elem, i) {
struct hisi_sas_sge *entry = &sge_page->sge[i];
entry->addr = cpu_to_le64(sg_dma_address(sg));
entry->page_ctrl_0 = entry->page_ctrl_1 = 0;
entry->data_len = cpu_to_le32(sg_dma_len(sg));
entry->data_off = 0;
}
hdr->prd_table_addr = cpu_to_le64(hisi_sas_sge_addr_dma(slot));
hdr->sg_len = cpu_to_le32(n_elem << CMD_HDR_DATA_SGL_LEN_OFF);
return 0;
}
static int prep_smp_v1_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot)
{
struct sas_task *task = slot->task;
struct hisi_sas_cmd_hdr *hdr = slot->cmd_hdr;
struct domain_device *device = task->dev;
struct device *dev = hisi_hba->dev;
struct hisi_sas_port *port = slot->port;
struct scatterlist *sg_req, *sg_resp;
struct hisi_sas_device *sas_dev = device->lldd_dev;
dma_addr_t req_dma_addr;
unsigned int req_len, resp_len;
int elem, rc;
sg_req = &task->smp_task.smp_req;
elem = dma_map_sg(dev, sg_req, 1, DMA_TO_DEVICE);
if (!elem)
return -ENOMEM;
req_len = sg_dma_len(sg_req);
req_dma_addr = sg_dma_address(sg_req);
sg_resp = &task->smp_task.smp_resp;
elem = dma_map_sg(dev, sg_resp, 1, DMA_FROM_DEVICE);
if (!elem) {
rc = -ENOMEM;
goto err_out_req;
}
resp_len = sg_dma_len(sg_resp);
if ((req_len & 0x3) || (resp_len & 0x3)) {
rc = -EINVAL;
goto err_out_resp;
}
hdr->dw0 = cpu_to_le32((port->id << CMD_HDR_PORT_OFF) |
(1 << CMD_HDR_PRIORITY_OFF) |
(1 << CMD_HDR_MODE_OFF) |
(2 << CMD_HDR_CMD_OFF));
hdr->dw1 = cpu_to_le32(sas_dev->device_id << CMD_HDR_DEVICE_ID_OFF);
hdr->dw2 = cpu_to_le32((((req_len-4)/4) << CMD_HDR_CFL_OFF) |
(HISI_SAS_MAX_SMP_RESP_SZ/4 <<
CMD_HDR_MRFL_OFF));
hdr->transfer_tags = cpu_to_le32(slot->idx << CMD_HDR_IPTT_OFF);
hdr->cmd_table_addr = cpu_to_le64(req_dma_addr);
hdr->sts_buffer_addr = cpu_to_le64(hisi_sas_status_buf_addr_dma(slot));
return 0;
err_out_resp:
dma_unmap_sg(dev, &slot->task->smp_task.smp_resp, 1,
DMA_FROM_DEVICE);
err_out_req:
dma_unmap_sg(dev, &slot->task->smp_task.smp_req, 1,
DMA_TO_DEVICE);
return rc;
}
static int prep_ssp_v1_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot, int is_tmf,
struct hisi_sas_tmf_task *tmf)
{
struct sas_task *task = slot->task;
struct hisi_sas_cmd_hdr *hdr = slot->cmd_hdr;
struct domain_device *device = task->dev;
struct hisi_sas_device *sas_dev = device->lldd_dev;
struct hisi_sas_port *port = slot->port;
struct sas_ssp_task *ssp_task = &task->ssp_task;
struct scsi_cmnd *scsi_cmnd = ssp_task->cmd;
int has_data = 0, rc, priority = is_tmf;
u8 *buf_cmd, fburst = 0;
u32 dw1, dw2;
hdr->dw0 = cpu_to_le32((1 << CMD_HDR_RESP_REPORT_OFF) |
(0x2 << CMD_HDR_TLR_CTRL_OFF) |
(port->id << CMD_HDR_PORT_OFF) |
(priority << CMD_HDR_PRIORITY_OFF) |
(1 << CMD_HDR_MODE_OFF) |
(1 << CMD_HDR_CMD_OFF));
dw1 = 1 << CMD_HDR_VERIFY_DTL_OFF;
if (is_tmf) {
dw1 |= 3 << CMD_HDR_SSP_FRAME_TYPE_OFF;
} else {
switch (scsi_cmnd->sc_data_direction) {
case DMA_TO_DEVICE:
dw1 |= 2 << CMD_HDR_SSP_FRAME_TYPE_OFF;
has_data = 1;
break;
case DMA_FROM_DEVICE:
dw1 |= 1 << CMD_HDR_SSP_FRAME_TYPE_OFF;
has_data = 1;
break;
default:
dw1 |= 0 << CMD_HDR_SSP_FRAME_TYPE_OFF;
}
}
dw1 |= sas_dev->device_id << CMD_HDR_DEVICE_ID_OFF;
hdr->dw1 = cpu_to_le32(dw1);
if (is_tmf) {
dw2 = ((sizeof(struct ssp_tmf_iu) +
sizeof(struct ssp_frame_hdr)+3)/4) <<
CMD_HDR_CFL_OFF;
} else {
dw2 = ((sizeof(struct ssp_command_iu) +
sizeof(struct ssp_frame_hdr)+3)/4) <<
CMD_HDR_CFL_OFF;
}
dw2 |= (HISI_SAS_MAX_SSP_RESP_SZ/4) << CMD_HDR_MRFL_OFF;
hdr->transfer_tags = cpu_to_le32(slot->idx << CMD_HDR_IPTT_OFF);
if (has_data) {
rc = prep_prd_sge_v1_hw(hisi_hba, slot, hdr, task->scatter,
slot->n_elem);
if (rc)
return rc;
}
hdr->data_transfer_len = cpu_to_le32(task->total_xfer_len);
hdr->cmd_table_addr = cpu_to_le64(hisi_sas_cmd_hdr_addr_dma(slot));
hdr->sts_buffer_addr = cpu_to_le64(hisi_sas_status_buf_addr_dma(slot));
buf_cmd = hisi_sas_cmd_hdr_addr_mem(slot) +
sizeof(struct ssp_frame_hdr);
if (task->ssp_task.enable_first_burst) {
fburst = (1 << 7);
dw2 |= 1 << CMD_HDR_FIRST_BURST_OFF;
}
hdr->dw2 = cpu_to_le32(dw2);
memcpy(buf_cmd, &task->ssp_task.LUN, 8);
if (!is_tmf) {
buf_cmd[9] = fburst | task->ssp_task.task_attr |
(task->ssp_task.task_prio << 3);
memcpy(buf_cmd + 12, task->ssp_task.cmd->cmnd,
task->ssp_task.cmd->cmd_len);
} else {
buf_cmd[10] = tmf->tmf;
switch (tmf->tmf) {
case TMF_ABORT_TASK:
case TMF_QUERY_TASK:
buf_cmd[12] =
(tmf->tag_of_task_to_be_managed >> 8) & 0xff;
buf_cmd[13] =
tmf->tag_of_task_to_be_managed & 0xff;
break;
default:
break;
}
}
return 0;
}
static void slot_err_v1_hw(struct hisi_hba *hisi_hba,
struct sas_task *task,
struct hisi_sas_slot *slot)
{
struct task_status_struct *ts = &task->task_status;
struct hisi_sas_err_record_v1 *err_record =
hisi_sas_status_buf_addr_mem(slot);
struct device *dev = hisi_hba->dev;
switch (task->task_proto) {
case SAS_PROTOCOL_SSP:
{
int error = -1;
u32 dma_err_type = cpu_to_le32(err_record->dma_err_type);
u32 dma_tx_err_type = ((dma_err_type &
ERR_HDR_DMA_TX_ERR_TYPE_MSK)) >>
ERR_HDR_DMA_TX_ERR_TYPE_OFF;
u32 dma_rx_err_type = ((dma_err_type &
ERR_HDR_DMA_RX_ERR_TYPE_MSK)) >>
ERR_HDR_DMA_RX_ERR_TYPE_OFF;
u32 trans_tx_fail_type =
cpu_to_le32(err_record->trans_tx_fail_type);
u32 trans_rx_fail_type =
cpu_to_le32(err_record->trans_rx_fail_type);
if (dma_tx_err_type) {
error = ffs(dma_tx_err_type)
- 1 + DMA_TX_ERR_BASE;
} else if (dma_rx_err_type) {
error = ffs(dma_rx_err_type)
- 1 + DMA_RX_ERR_BASE;
} else if (trans_tx_fail_type) {
error = ffs(trans_tx_fail_type)
- 1 + TRANS_TX_FAIL_BASE;
} else if (trans_rx_fail_type) {
error = ffs(trans_rx_fail_type)
- 1 + TRANS_RX_FAIL_BASE;
}
switch (error) {
case DMA_TX_DATA_UNDERFLOW_ERR:
case DMA_RX_DATA_UNDERFLOW_ERR:
{
ts->residual = 0;
ts->stat = SAS_DATA_UNDERRUN;
break;
}
case DMA_TX_DATA_SGL_OVERFLOW_ERR:
case DMA_TX_DIF_SGL_OVERFLOW_ERR:
case DMA_TX_XFER_RDY_LENGTH_OVERFLOW_ERR:
case DMA_RX_DATA_OVERFLOW_ERR:
case TRANS_RX_FRAME_OVERRUN_ERR:
case TRANS_RX_LINK_BUF_OVERRUN_ERR:
{
ts->stat = SAS_DATA_OVERRUN;
ts->residual = 0;
break;
}
case TRANS_TX_PHY_NOT_ENABLE_ERR:
{
ts->stat = SAS_PHY_DOWN;
break;
}
case TRANS_TX_OPEN_REJCT_WRONG_DEST_ERR:
case TRANS_TX_OPEN_REJCT_ZONE_VIOLATION_ERR:
case TRANS_TX_OPEN_REJCT_BY_OTHER_ERR:
case TRANS_TX_OPEN_REJCT_AIP_TIMEOUT_ERR:
case TRANS_TX_OPEN_REJCT_STP_BUSY_ERR:
case TRANS_TX_OPEN_REJCT_PROTOCOL_NOT_SUPPORT_ERR:
case TRANS_TX_OPEN_REJCT_RATE_NOT_SUPPORT_ERR:
case TRANS_TX_OPEN_REJCT_BAD_DEST_ERR:
case TRANS_TX_OPEN_BREAK_RECEIVE_ERR:
case TRANS_TX_OPEN_REJCT_PATHWAY_BLOCKED_ERR:
case TRANS_TX_OPEN_REJCT_NO_DEST_ERR:
case TRANS_TX_OPEN_RETRY_ERR:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_UNKNOWN;
break;
}
case TRANS_TX_OPEN_TIMEOUT_ERR:
{
ts->stat = SAS_OPEN_TO;
break;
}
case TRANS_TX_NAK_RECEIVE_ERR:
case TRANS_TX_ACK_NAK_TIMEOUT_ERR:
{
ts->stat = SAS_NAK_R_ERR;
break;
}
case TRANS_TX_CREDIT_TIMEOUT_ERR:
case TRANS_TX_CLOSE_NORMAL_ERR:
{
ts->stat = SAS_QUEUE_FULL;
slot->abort = 1;
break;
}
default:
{
ts->stat = SAM_STAT_CHECK_CONDITION;
break;
}
}
}
break;
case SAS_PROTOCOL_SMP:
ts->stat = SAM_STAT_CHECK_CONDITION;
break;
case SAS_PROTOCOL_SATA:
case SAS_PROTOCOL_STP:
case SAS_PROTOCOL_SATA | SAS_PROTOCOL_STP:
{
dev_err(dev, "slot err: SATA/STP not supported");
}
break;
default:
break;
}
}
static int slot_complete_v1_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot)
{
struct sas_task *task = slot->task;
struct hisi_sas_device *sas_dev;
struct device *dev = hisi_hba->dev;
struct task_status_struct *ts;
struct domain_device *device;
enum exec_status sts;
struct hisi_sas_complete_v1_hdr *complete_queue =
hisi_hba->complete_hdr[slot->cmplt_queue];
struct hisi_sas_complete_v1_hdr *complete_hdr;
unsigned long flags;
u32 cmplt_hdr_data;
complete_hdr = &complete_queue[slot->cmplt_queue_slot];
cmplt_hdr_data = le32_to_cpu(complete_hdr->data);
if (unlikely(!task || !task->lldd_task || !task->dev))
return -EINVAL;
ts = &task->task_status;
device = task->dev;
sas_dev = device->lldd_dev;
spin_lock_irqsave(&task->task_state_lock, flags);
task->task_state_flags &=
~(SAS_TASK_STATE_PENDING | SAS_TASK_AT_INITIATOR);
task->task_state_flags |= SAS_TASK_STATE_DONE;
spin_unlock_irqrestore(&task->task_state_lock, flags);
memset(ts, 0, sizeof(*ts));
ts->resp = SAS_TASK_COMPLETE;
if (unlikely(!sas_dev)) {
dev_dbg(dev, "slot complete: port has no device\n");
ts->stat = SAS_PHY_DOWN;
goto out;
}
if (cmplt_hdr_data & CMPLT_HDR_IO_CFG_ERR_MSK) {
u32 info_reg = hisi_sas_read32(hisi_hba, HGC_INVLD_DQE_INFO);
if (info_reg & HGC_INVLD_DQE_INFO_DQ_MSK)
dev_err(dev, "slot complete: [%d:%d] has dq IPTT err",
slot->cmplt_queue, slot->cmplt_queue_slot);
if (info_reg & HGC_INVLD_DQE_INFO_TYPE_MSK)
dev_err(dev, "slot complete: [%d:%d] has dq type err",
slot->cmplt_queue, slot->cmplt_queue_slot);
if (info_reg & HGC_INVLD_DQE_INFO_FORCE_MSK)
dev_err(dev, "slot complete: [%d:%d] has dq force phy err",
slot->cmplt_queue, slot->cmplt_queue_slot);
if (info_reg & HGC_INVLD_DQE_INFO_PHY_MSK)
dev_err(dev, "slot complete: [%d:%d] has dq phy id err",
slot->cmplt_queue, slot->cmplt_queue_slot);
if (info_reg & HGC_INVLD_DQE_INFO_ABORT_MSK)
dev_err(dev, "slot complete: [%d:%d] has dq abort flag err",
slot->cmplt_queue, slot->cmplt_queue_slot);
if (info_reg & HGC_INVLD_DQE_INFO_IPTT_OF_MSK)
dev_err(dev, "slot complete: [%d:%d] has dq IPTT or ICT err",
slot->cmplt_queue, slot->cmplt_queue_slot);
if (info_reg & HGC_INVLD_DQE_INFO_SSP_ERR_MSK)
dev_err(dev, "slot complete: [%d:%d] has dq SSP frame type err",
slot->cmplt_queue, slot->cmplt_queue_slot);
if (info_reg & HGC_INVLD_DQE_INFO_OFL_MSK)
dev_err(dev, "slot complete: [%d:%d] has dq order frame len err",
slot->cmplt_queue, slot->cmplt_queue_slot);
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_UNKNOWN;
goto out;
}
if (cmplt_hdr_data & CMPLT_HDR_ERR_RCRD_XFRD_MSK &&
!(cmplt_hdr_data & CMPLT_HDR_RSPNS_XFRD_MSK)) {
slot_err_v1_hw(hisi_hba, task, slot);
if (unlikely(slot->abort)) {
queue_work(hisi_hba->wq, &slot->abort_slot);
return ts->stat;
}
goto out;
}
switch (task->task_proto) {
case SAS_PROTOCOL_SSP:
{
struct hisi_sas_status_buffer *status_buffer =
hisi_sas_status_buf_addr_mem(slot);
struct ssp_response_iu *iu = (struct ssp_response_iu *)
&status_buffer->iu[0];
sas_ssp_task_response(dev, task, iu);
break;
}
case SAS_PROTOCOL_SMP:
{
void *to;
struct scatterlist *sg_resp = &task->smp_task.smp_resp;
ts->stat = SAM_STAT_GOOD;
to = kmap_atomic(sg_page(sg_resp));
dma_unmap_sg(dev, &task->smp_task.smp_resp, 1,
DMA_FROM_DEVICE);
dma_unmap_sg(dev, &task->smp_task.smp_req, 1,
DMA_TO_DEVICE);
memcpy(to + sg_resp->offset,
hisi_sas_status_buf_addr_mem(slot) +
sizeof(struct hisi_sas_err_record),
sg_dma_len(sg_resp));
kunmap_atomic(to);
break;
}
case SAS_PROTOCOL_SATA:
case SAS_PROTOCOL_STP:
case SAS_PROTOCOL_SATA | SAS_PROTOCOL_STP:
dev_err(dev, "slot complete: SATA/STP not supported");
break;
default:
ts->stat = SAM_STAT_CHECK_CONDITION;
break;
}
if (!slot->port->port_attached) {
dev_err(dev, "slot complete: port %d has removed\n",
slot->port->sas_port.id);
ts->stat = SAS_PHY_DOWN;
}
out:
if (sas_dev)
atomic64_dec(&sas_dev->running_req);
hisi_sas_slot_task_free(hisi_hba, task, slot);
sts = ts->stat;
if (task->task_done)
task->task_done(task);
return sts;
}
static irqreturn_t int_phyup_v1_hw(int irq_no, void *p)
{
struct hisi_sas_phy *phy = p;
struct hisi_hba *hisi_hba = phy->hisi_hba;
struct device *dev = hisi_hba->dev;
struct asd_sas_phy *sas_phy = &phy->sas_phy;
int i, phy_no = sas_phy->id;
u32 irq_value, context, port_id, link_rate;
u32 *frame_rcvd = (u32 *)sas_phy->frame_rcvd;
struct sas_identify_frame *id = (struct sas_identify_frame *)frame_rcvd;
irqreturn_t res = IRQ_HANDLED;
irq_value = hisi_sas_phy_read32(hisi_hba, phy_no, CHL_INT2);
if (!(irq_value & CHL_INT2_SL_PHY_ENA_MSK)) {
dev_dbg(dev, "phyup: irq_value = %x not set enable bit\n",
irq_value);
res = IRQ_NONE;
goto end;
}
context = hisi_sas_read32(hisi_hba, PHY_CONTEXT);
if (context & 1 << phy_no) {
dev_err(dev, "phyup: phy%d SATA attached equipment\n",
phy_no);
goto end;
}
port_id = (hisi_sas_read32(hisi_hba, PHY_PORT_NUM_MA) >> (4 * phy_no))
& 0xf;
if (port_id == 0xf) {
dev_err(dev, "phyup: phy%d invalid portid\n", phy_no);
res = IRQ_NONE;
goto end;
}
for (i = 0; i < 6; i++) {
u32 idaf = hisi_sas_phy_read32(hisi_hba, phy_no,
RX_IDAF_DWORD0 + (i * 4));
frame_rcvd[i] = __swab32(idaf);
}
link_rate = hisi_sas_read32(hisi_hba, PHY_CONN_RATE);
link_rate = (link_rate >> (phy_no * 4)) & 0xf;
sas_phy->linkrate = link_rate;
sas_phy->oob_mode = SAS_OOB_MODE;
memcpy(sas_phy->attached_sas_addr,
&id->sas_addr, SAS_ADDR_SIZE);
dev_info(dev, "phyup: phy%d link_rate=%d\n",
phy_no, link_rate);
phy->port_id = port_id;
phy->phy_type &= ~(PORT_TYPE_SAS | PORT_TYPE_SATA);
phy->phy_type |= PORT_TYPE_SAS;
phy->phy_attached = 1;
phy->identify.device_type = id->dev_type;
phy->frame_rcvd_size = sizeof(struct sas_identify_frame);
if (phy->identify.device_type == SAS_END_DEVICE)
phy->identify.target_port_protocols =
SAS_PROTOCOL_SSP;
else if (phy->identify.device_type != SAS_PHY_UNUSED)
phy->identify.target_port_protocols =
SAS_PROTOCOL_SMP;
queue_work(hisi_hba->wq, &phy->phyup_ws);
end:
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT2,
CHL_INT2_SL_PHY_ENA_MSK);
if (irq_value & CHL_INT2_SL_PHY_ENA_MSK) {
u32 chl_int0 = hisi_sas_phy_read32(hisi_hba, phy_no, CHL_INT0);
chl_int0 &= ~CHL_INT0_PHYCTRL_NOTRDY_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0, chl_int0);
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0_MSK, 0x3ce3ee);
}
return res;
}
static irqreturn_t int_bcast_v1_hw(int irq, void *p)
{
struct hisi_sas_phy *phy = p;
struct hisi_hba *hisi_hba = phy->hisi_hba;
struct asd_sas_phy *sas_phy = &phy->sas_phy;
struct sas_ha_struct *sha = &hisi_hba->sha;
struct device *dev = hisi_hba->dev;
int phy_no = sas_phy->id;
u32 irq_value;
irqreturn_t res = IRQ_HANDLED;
irq_value = hisi_sas_phy_read32(hisi_hba, phy_no, CHL_INT2);
if (!(irq_value & CHL_INT2_SL_RX_BC_ACK_MSK)) {
dev_err(dev, "bcast: irq_value = %x not set enable bit",
irq_value);
res = IRQ_NONE;
goto end;
}
sha->notify_port_event(sas_phy, PORTE_BROADCAST_RCVD);
end:
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT2,
CHL_INT2_SL_RX_BC_ACK_MSK);
return res;
}
static irqreturn_t int_abnormal_v1_hw(int irq, void *p)
{
struct hisi_sas_phy *phy = p;
struct hisi_hba *hisi_hba = phy->hisi_hba;
struct device *dev = hisi_hba->dev;
struct asd_sas_phy *sas_phy = &phy->sas_phy;
u32 irq_value, irq_mask_old;
int phy_no = sas_phy->id;
irq_mask_old = hisi_sas_phy_read32(hisi_hba, phy_no, CHL_INT0_MSK);
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0_MSK, 0x3fffff);
irq_value = hisi_sas_phy_read32(hisi_hba, phy_no, CHL_INT0);
if (irq_value & CHL_INT0_PHYCTRL_NOTRDY_MSK) {
u32 phy_state = hisi_sas_read32(hisi_hba, PHY_STATE);
hisi_sas_phy_down(hisi_hba, phy_no,
(phy_state & 1 << phy_no) ? 1 : 0);
}
if (irq_value & CHL_INT0_ID_TIMEOUT_MSK)
dev_dbg(dev, "abnormal: ID_TIMEOUT phy%d identify timeout\n",
phy_no);
if (irq_value & CHL_INT0_DWS_LOST_MSK)
dev_dbg(dev, "abnormal: DWS_LOST phy%d dws lost\n", phy_no);
if (irq_value & CHL_INT0_SN_FAIL_NGR_MSK)
dev_dbg(dev, "abnormal: SN_FAIL_NGR phy%d sn fail ngr\n",
phy_no);
if (irq_value & CHL_INT0_SL_IDAF_FAIL_MSK ||
irq_value & CHL_INT0_SL_OPAF_FAIL_MSK)
dev_dbg(dev, "abnormal: SL_ID/OPAF_FAIL phy%d check adr frm err\n",
phy_no);
if (irq_value & CHL_INT0_SL_PS_FAIL_OFF)
dev_dbg(dev, "abnormal: SL_PS_FAIL phy%d fail\n", phy_no);
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0, irq_value);
if (irq_value & CHL_INT0_PHYCTRL_NOTRDY_MSK)
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0_MSK,
0x3fffff & ~CHL_INT0_MSK_PHYCTRL_NOTRDY_MSK);
else
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0_MSK,
irq_mask_old);
return IRQ_HANDLED;
}
static irqreturn_t cq_interrupt_v1_hw(int irq, void *p)
{
struct hisi_sas_cq *cq = p;
struct hisi_hba *hisi_hba = cq->hisi_hba;
struct hisi_sas_slot *slot;
int queue = cq->id;
struct hisi_sas_complete_v1_hdr *complete_queue =
(struct hisi_sas_complete_v1_hdr *)
hisi_hba->complete_hdr[queue];
u32 irq_value, rd_point = cq->rd_point, wr_point;
spin_lock(&hisi_hba->lock);
irq_value = hisi_sas_read32(hisi_hba, OQ_INT_SRC);
hisi_sas_write32(hisi_hba, OQ_INT_SRC, 1 << queue);
wr_point = hisi_sas_read32(hisi_hba,
COMPL_Q_0_WR_PTR + (0x14 * queue));
while (rd_point != wr_point) {
struct hisi_sas_complete_v1_hdr *complete_hdr;
int idx;
u32 cmplt_hdr_data;
complete_hdr = &complete_queue[rd_point];
cmplt_hdr_data = cpu_to_le32(complete_hdr->data);
idx = (cmplt_hdr_data & CMPLT_HDR_IPTT_MSK) >>
CMPLT_HDR_IPTT_OFF;
slot = &hisi_hba->slot_info[idx];
slot->cmplt_queue_slot = rd_point;
slot->cmplt_queue = queue;
slot_complete_v1_hw(hisi_hba, slot);
if (++rd_point >= HISI_SAS_QUEUE_SLOTS)
rd_point = 0;
}
cq->rd_point = rd_point;
hisi_sas_write32(hisi_hba, COMPL_Q_0_RD_PTR + (0x14 * queue), rd_point);
spin_unlock(&hisi_hba->lock);
return IRQ_HANDLED;
}
static irqreturn_t fatal_ecc_int_v1_hw(int irq, void *p)
{
struct hisi_hba *hisi_hba = p;
struct device *dev = hisi_hba->dev;
u32 ecc_int = hisi_sas_read32(hisi_hba, SAS_ECC_INTR);
if (ecc_int & SAS_ECC_INTR_DQ_ECC1B_MSK) {
u32 ecc_err = hisi_sas_read32(hisi_hba, HGC_ECC_ERR);
panic("%s: Fatal DQ 1b ECC interrupt (0x%x)\n",
dev_name(dev), ecc_err);
}
if (ecc_int & SAS_ECC_INTR_DQ_ECCBAD_MSK) {
u32 addr = (hisi_sas_read32(hisi_hba, HGC_DQ_ECC_ADDR) &
HGC_DQ_ECC_ADDR_BAD_MSK) >>
HGC_DQ_ECC_ADDR_BAD_OFF;
panic("%s: Fatal DQ RAM ECC interrupt @ 0x%08x\n",
dev_name(dev), addr);
}
if (ecc_int & SAS_ECC_INTR_IOST_ECC1B_MSK) {
u32 ecc_err = hisi_sas_read32(hisi_hba, HGC_ECC_ERR);
panic("%s: Fatal IOST 1b ECC interrupt (0x%x)\n",
dev_name(dev), ecc_err);
}
if (ecc_int & SAS_ECC_INTR_IOST_ECCBAD_MSK) {
u32 addr = (hisi_sas_read32(hisi_hba, HGC_IOST_ECC_ADDR) &
HGC_IOST_ECC_ADDR_BAD_MSK) >>
HGC_IOST_ECC_ADDR_BAD_OFF;
panic("%s: Fatal IOST RAM ECC interrupt @ 0x%08x\n",
dev_name(dev), addr);
}
if (ecc_int & SAS_ECC_INTR_ITCT_ECCBAD_MSK) {
u32 addr = (hisi_sas_read32(hisi_hba, HGC_ITCT_ECC_ADDR) &
HGC_ITCT_ECC_ADDR_BAD_MSK) >>
HGC_ITCT_ECC_ADDR_BAD_OFF;
panic("%s: Fatal TCT RAM ECC interrupt @ 0x%08x\n",
dev_name(dev), addr);
}
if (ecc_int & SAS_ECC_INTR_ITCT_ECC1B_MSK) {
u32 ecc_err = hisi_sas_read32(hisi_hba, HGC_ECC_ERR);
panic("%s: Fatal ITCT 1b ECC interrupt (0x%x)\n",
dev_name(dev), ecc_err);
}
hisi_sas_write32(hisi_hba, SAS_ECC_INTR, ecc_int | 0x3f);
return IRQ_HANDLED;
}
static irqreturn_t fatal_axi_int_v1_hw(int irq, void *p)
{
struct hisi_hba *hisi_hba = p;
struct device *dev = hisi_hba->dev;
u32 axi_int = hisi_sas_read32(hisi_hba, ENT_INT_SRC2);
u32 axi_info = hisi_sas_read32(hisi_hba, HGC_AXI_FIFO_ERR_INFO);
if (axi_int & ENT_INT_SRC2_DQ_CFG_ERR_MSK)
panic("%s: Fatal DQ_CFG_ERR interrupt (0x%x)\n",
dev_name(dev), axi_info);
if (axi_int & ENT_INT_SRC2_CQ_CFG_ERR_MSK)
panic("%s: Fatal CQ_CFG_ERR interrupt (0x%x)\n",
dev_name(dev), axi_info);
if (axi_int & ENT_INT_SRC2_AXI_WRONG_INT_MSK)
panic("%s: Fatal AXI_WRONG_INT interrupt (0x%x)\n",
dev_name(dev), axi_info);
if (axi_int & ENT_INT_SRC2_AXI_OVERLF_INT_MSK)
panic("%s: Fatal AXI_OVERLF_INT incorrect interrupt (0x%x)\n",
dev_name(dev), axi_info);
hisi_sas_write32(hisi_hba, ENT_INT_SRC2, axi_int | 0x30000000);
return IRQ_HANDLED;
}
static int interrupt_init_v1_hw(struct hisi_hba *hisi_hba)
{
struct platform_device *pdev = hisi_hba->platform_dev;
struct device *dev = &pdev->dev;
int i, j, irq, rc, idx;
for (i = 0; i < hisi_hba->n_phy; i++) {
struct hisi_sas_phy *phy = &hisi_hba->phy[i];
idx = i * HISI_SAS_PHY_INT_NR;
for (j = 0; j < HISI_SAS_PHY_INT_NR; j++, idx++) {
irq = platform_get_irq(pdev, idx);
if (!irq) {
dev_err(dev,
"irq init: fail map phy interrupt %d\n",
idx);
return -ENOENT;
}
rc = devm_request_irq(dev, irq, phy_interrupts[j], 0,
DRV_NAME " phy", phy);
if (rc) {
dev_err(dev, "irq init: could not request "
"phy interrupt %d, rc=%d\n",
irq, rc);
return -ENOENT;
}
}
}
idx = hisi_hba->n_phy * HISI_SAS_PHY_INT_NR;
for (i = 0; i < hisi_hba->queue_count; i++, idx++) {
irq = platform_get_irq(pdev, idx);
if (!irq) {
dev_err(dev, "irq init: could not map cq interrupt %d\n",
idx);
return -ENOENT;
}
rc = devm_request_irq(dev, irq, cq_interrupt_v1_hw, 0,
DRV_NAME " cq", &hisi_hba->cq[i]);
if (rc) {
dev_err(dev, "irq init: could not request cq interrupt %d, rc=%d\n",
irq, rc);
return -ENOENT;
}
}
idx = (hisi_hba->n_phy * HISI_SAS_PHY_INT_NR) + hisi_hba->queue_count;
for (i = 0; i < HISI_SAS_FATAL_INT_NR; i++, idx++) {
irq = platform_get_irq(pdev, idx);
if (!irq) {
dev_err(dev, "irq init: could not map fatal interrupt %d\n",
idx);
return -ENOENT;
}
rc = devm_request_irq(dev, irq, fatal_interrupts[i], 0,
DRV_NAME " fatal", hisi_hba);
if (rc) {
dev_err(dev,
"irq init: could not request fatal interrupt %d, rc=%d\n",
irq, rc);
return -ENOENT;
}
}
return 0;
}
static int interrupt_openall_v1_hw(struct hisi_hba *hisi_hba)
{
int i;
u32 val;
for (i = 0; i < hisi_hba->n_phy; i++) {
val = hisi_sas_phy_read32(hisi_hba, i, CHL_INT0);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT0, val);
val = hisi_sas_phy_read32(hisi_hba, i, CHL_INT1);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT1, val);
val = hisi_sas_phy_read32(hisi_hba, i, CHL_INT2);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT2, val);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT0_MSK, 0x3ce3ee);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT1_MSK, 0x17fff);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT2_MSK, 0x8000012a);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT0_MSK,
0x3fffff & ~CHL_INT0_MSK_PHYCTRL_NOTRDY_MSK);
}
return 0;
}
static int hisi_sas_v1_init(struct hisi_hba *hisi_hba)
{
int rc;
rc = hw_init_v1_hw(hisi_hba);
if (rc)
return rc;
rc = interrupt_init_v1_hw(hisi_hba);
if (rc)
return rc;
rc = interrupt_openall_v1_hw(hisi_hba);
if (rc)
return rc;
return 0;
}
static int hisi_sas_v1_probe(struct platform_device *pdev)
{
return hisi_sas_probe(pdev, &hisi_sas_v1_hw);
}
static int hisi_sas_v1_remove(struct platform_device *pdev)
{
return hisi_sas_remove(pdev);
}
