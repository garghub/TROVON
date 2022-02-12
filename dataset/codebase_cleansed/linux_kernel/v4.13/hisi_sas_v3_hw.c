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
static void hisi_sas_write32(struct hisi_hba *hisi_hba, u32 off, u32 val)
{
void __iomem *regs = hisi_hba->regs + off;
writel(val, regs);
}
static void hisi_sas_phy_write32(struct hisi_hba *hisi_hba, int phy_no,
u32 off, u32 val)
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
static void init_reg_v3_hw(struct hisi_hba *hisi_hba)
{
int i;
hisi_sas_write32(hisi_hba, DLVRY_QUEUE_ENABLE,
(u32)((1ULL << hisi_hba->queue_count) - 1));
hisi_sas_write32(hisi_hba, AXI_USER1, 0x0);
hisi_sas_write32(hisi_hba, AXI_USER2, 0x40000060);
hisi_sas_write32(hisi_hba, HGC_SAS_TXFAIL_RETRY_CTRL, 0x108);
hisi_sas_write32(hisi_hba, CFG_1US_TIMER_TRSH, 0xd);
hisi_sas_write32(hisi_hba, INT_COAL_EN, 0x1);
hisi_sas_write32(hisi_hba, OQ_INT_COAL_TIME, 0x1);
hisi_sas_write32(hisi_hba, OQ_INT_COAL_CNT, 0x1);
hisi_sas_write32(hisi_hba, OQ_INT_SRC, 0xffff);
hisi_sas_write32(hisi_hba, ENT_INT_SRC1, 0xffffffff);
hisi_sas_write32(hisi_hba, ENT_INT_SRC2, 0xffffffff);
hisi_sas_write32(hisi_hba, ENT_INT_SRC3, 0xffffffff);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK1, 0xfefefefe);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK2, 0xfefefefe);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK3, 0xffffffff);
hisi_sas_write32(hisi_hba, CHNL_PHYUPDOWN_INT_MSK, 0x0);
hisi_sas_write32(hisi_hba, CHNL_ENT_INT_MSK, 0x0);
hisi_sas_write32(hisi_hba, HGC_COM_INT_MSK, 0x0);
hisi_sas_write32(hisi_hba, SAS_ECC_INTR_MSK, 0xfff00c30);
hisi_sas_write32(hisi_hba, AWQOS_AWCACHE_CFG, 0xf0f0);
hisi_sas_write32(hisi_hba, ARQOS_ARCACHE_CFG, 0xf0f0);
for (i = 0; i < hisi_hba->queue_count; i++)
hisi_sas_write32(hisi_hba, OQ0_INT_SRC_MSK+0x4*i, 0);
hisi_sas_write32(hisi_hba, AXI_AHB_CLK_CFG, 1);
hisi_sas_write32(hisi_hba, HYPER_STREAM_ID_EN_CFG, 1);
hisi_sas_write32(hisi_hba, CFG_MAX_TAG, 0xfff07fff);
for (i = 0; i < hisi_hba->n_phy; i++) {
hisi_sas_phy_write32(hisi_hba, i, PROG_PHY_LINK_RATE, 0x801);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT0, 0xffffffff);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT1, 0xffffffff);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT2, 0xffffffff);
hisi_sas_phy_write32(hisi_hba, i, RXOP_CHECK_CFG_H, 0x1000);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT1_MSK, 0xffffffff);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT2_MSK, 0x8ffffbff);
hisi_sas_phy_write32(hisi_hba, i, SL_CFG, 0x83f801fc);
hisi_sas_phy_write32(hisi_hba, i, PHY_CTRL_RDY_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, PHYCTRL_NOT_RDY_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, PHYCTRL_DWS_RESET_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, PHYCTRL_PHY_ENA_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, SL_RX_BCAST_CHK_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, PHYCTRL_OOB_RESTART_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, PHY_CTRL, 0x199b4fa);
hisi_sas_phy_write32(hisi_hba, i, SAS_SSP_CON_TIMER_CFG,
0xa0064);
hisi_sas_phy_write32(hisi_hba, i, SAS_STP_CON_TIMER_CFG,
0xa0064);
}
for (i = 0; i < hisi_hba->queue_count; i++) {
hisi_sas_write32(hisi_hba,
DLVRY_Q_0_BASE_ADDR_HI + (i * 0x14),
upper_32_bits(hisi_hba->cmd_hdr_dma[i]));
hisi_sas_write32(hisi_hba, DLVRY_Q_0_BASE_ADDR_LO + (i * 0x14),
lower_32_bits(hisi_hba->cmd_hdr_dma[i]));
hisi_sas_write32(hisi_hba, DLVRY_Q_0_DEPTH + (i * 0x14),
HISI_SAS_QUEUE_SLOTS);
hisi_sas_write32(hisi_hba, COMPL_Q_0_BASE_ADDR_HI + (i * 0x14),
upper_32_bits(hisi_hba->complete_hdr_dma[i]));
hisi_sas_write32(hisi_hba, COMPL_Q_0_BASE_ADDR_LO + (i * 0x14),
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
hisi_sas_write32(hisi_hba, IO_BROKEN_MSG_ADDR_LO,
lower_32_bits(hisi_hba->breakpoint_dma));
hisi_sas_write32(hisi_hba, IO_BROKEN_MSG_ADDR_HI,
upper_32_bits(hisi_hba->breakpoint_dma));
hisi_sas_write32(hisi_hba, IO_SATA_BROKEN_MSG_ADDR_LO,
lower_32_bits(hisi_hba->sata_breakpoint_dma));
hisi_sas_write32(hisi_hba, IO_SATA_BROKEN_MSG_ADDR_HI,
upper_32_bits(hisi_hba->sata_breakpoint_dma));
hisi_sas_write32(hisi_hba, SATA_INITI_D2H_STORE_ADDR_LO,
lower_32_bits(hisi_hba->initial_fis_dma));
hisi_sas_write32(hisi_hba, SATA_INITI_D2H_STORE_ADDR_HI,
upper_32_bits(hisi_hba->initial_fis_dma));
}
static void config_phy_opt_mode_v3_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CFG);
cfg &= ~PHY_CFG_DC_OPT_MSK;
cfg |= 1 << PHY_CFG_DC_OPT_OFF;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CFG, cfg);
}
static void config_id_frame_v3_hw(struct hisi_hba *hisi_hba, int phy_no)
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
static void setup_itct_v3_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_device *sas_dev)
{
struct domain_device *device = sas_dev->sas_device;
struct device *dev = hisi_hba->dev;
u64 qw0, device_id = sas_dev->device_id;
struct hisi_sas_itct *itct = &hisi_hba->itct[device_id];
struct domain_device *parent_dev = device->parent;
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
case SAS_SATA_DEV:
case SAS_SATA_PENDING:
if (parent_dev && DEV_IS_EXPANDER(parent_dev->dev_type))
qw0 = HISI_SAS_DEV_TYPE_STP << ITCT_HDR_DEV_TYPE_OFF;
else
qw0 = HISI_SAS_DEV_TYPE_SATA << ITCT_HDR_DEV_TYPE_OFF;
break;
default:
dev_warn(dev, "setup itct: unsupported dev type (%d)\n",
sas_dev->dev_type);
}
qw0 |= ((1 << ITCT_HDR_VALID_OFF) |
(device->linkrate << ITCT_HDR_MCR_OFF) |
(1 << ITCT_HDR_VLN_OFF) |
(0xfa << ITCT_HDR_SMP_TIMEOUT_OFF) |
(1 << ITCT_HDR_AWT_CONTINUE_OFF) |
(port->id << ITCT_HDR_PORT_ID_OFF));
itct->qw0 = cpu_to_le64(qw0);
memcpy(&itct->sas_addr, device->sas_addr, SAS_ADDR_SIZE);
itct->sas_addr = __swab64(itct->sas_addr);
if (!dev_is_sata(device))
itct->qw2 = cpu_to_le64((5000ULL << ITCT_HDR_INLT_OFF) |
(0x1ULL << ITCT_HDR_RTOLT_OFF));
}
static void free_device_v3_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_device *sas_dev)
{
u64 dev_id = sas_dev->device_id;
struct device *dev = hisi_hba->dev;
struct hisi_sas_itct *itct = &hisi_hba->itct[dev_id];
u32 reg_val = hisi_sas_read32(hisi_hba, ENT_INT_SRC3);
if (ENT_INT_SRC3_ITC_INT_MSK & reg_val)
hisi_sas_write32(hisi_hba, ENT_INT_SRC3,
ENT_INT_SRC3_ITC_INT_MSK);
reg_val = hisi_sas_read32(hisi_hba, ITCT_CLR);
reg_val |= ITCT_CLR_EN_MSK | (dev_id & ITCT_DEV_MSK);
hisi_sas_write32(hisi_hba, ITCT_CLR, reg_val);
udelay(10);
reg_val = hisi_sas_read32(hisi_hba, ENT_INT_SRC3);
if (ENT_INT_SRC3_ITC_INT_MSK & reg_val) {
dev_dbg(dev, "got clear ITCT done interrupt\n");
memset(itct, 0, sizeof(struct hisi_sas_itct));
hisi_sas_write32(hisi_hba, ENT_INT_SRC3,
ENT_INT_SRC3_ITC_INT_MSK);
hisi_hba->devices[dev_id].dev_type = SAS_PHY_UNUSED;
hisi_hba->devices[dev_id].dev_status = HISI_SAS_DEV_NORMAL;
hisi_sas_write32(hisi_hba, ITCT_CLR, 0);
dev_dbg(dev, "clear ITCT ok\n");
}
}
static void dereg_device_v3_hw(struct hisi_hba *hisi_hba,
struct domain_device *device)
{
struct hisi_sas_slot *slot, *slot2;
struct hisi_sas_device *sas_dev = device->lldd_dev;
u32 cfg_abt_set_query_iptt;
cfg_abt_set_query_iptt = hisi_sas_read32(hisi_hba,
CFG_ABT_SET_QUERY_IPTT);
list_for_each_entry_safe(slot, slot2, &sas_dev->list, entry) {
cfg_abt_set_query_iptt &= ~CFG_SET_ABORTED_IPTT_MSK;
cfg_abt_set_query_iptt |= (1 << CFG_SET_ABORTED_EN_OFF) |
(slot->idx << CFG_SET_ABORTED_IPTT_OFF);
hisi_sas_write32(hisi_hba, CFG_ABT_SET_QUERY_IPTT,
cfg_abt_set_query_iptt);
}
cfg_abt_set_query_iptt &= ~(1 << CFG_SET_ABORTED_EN_OFF);
hisi_sas_write32(hisi_hba, CFG_ABT_SET_QUERY_IPTT,
cfg_abt_set_query_iptt);
hisi_sas_write32(hisi_hba, CFG_ABT_SET_IPTT_DONE,
1 << CFG_ABT_SET_IPTT_DONE_OFF);
}
static int hw_init_v3_hw(struct hisi_hba *hisi_hba)
{
init_reg_v3_hw(hisi_hba);
return 0;
}
static void enable_phy_v3_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CFG);
cfg |= PHY_CFG_ENA_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CFG, cfg);
}
static void disable_phy_v3_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CFG);
cfg &= ~PHY_CFG_ENA_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CFG, cfg);
}
static void start_phy_v3_hw(struct hisi_hba *hisi_hba, int phy_no)
{
config_id_frame_v3_hw(hisi_hba, phy_no);
config_phy_opt_mode_v3_hw(hisi_hba, phy_no);
enable_phy_v3_hw(hisi_hba, phy_no);
}
static void stop_phy_v3_hw(struct hisi_hba *hisi_hba, int phy_no)
{
disable_phy_v3_hw(hisi_hba, phy_no);
}
static void start_phys_v3_hw(struct hisi_hba *hisi_hba)
{
int i;
for (i = 0; i < hisi_hba->n_phy; i++)
start_phy_v3_hw(hisi_hba, i);
}
static void phy_hard_reset_v3_hw(struct hisi_hba *hisi_hba, int phy_no)
{
struct hisi_sas_phy *phy = &hisi_hba->phy[phy_no];
u32 txid_auto;
stop_phy_v3_hw(hisi_hba, phy_no);
if (phy->identify.device_type == SAS_END_DEVICE) {
txid_auto = hisi_sas_phy_read32(hisi_hba, phy_no, TXID_AUTO);
hisi_sas_phy_write32(hisi_hba, phy_no, TXID_AUTO,
txid_auto | TX_HARDRST_MSK);
}
msleep(100);
start_phy_v3_hw(hisi_hba, phy_no);
}
enum sas_linkrate phy_get_max_linkrate_v3_hw(void)
{
return SAS_LINK_RATE_12_0_GBPS;
}
static void phys_init_v3_hw(struct hisi_hba *hisi_hba)
{
start_phys_v3_hw(hisi_hba);
}
static void sl_notify_v3_hw(struct hisi_hba *hisi_hba, int phy_no)
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
static int get_wideport_bitmap_v3_hw(struct hisi_hba *hisi_hba, int port_id)
{
int i, bitmap = 0;
u32 phy_port_num_ma = hisi_sas_read32(hisi_hba, PHY_PORT_NUM_MA);
for (i = 0; i < hisi_hba->n_phy; i++)
if (((phy_port_num_ma >> (i * 4)) & 0xf) == port_id)
bitmap |= 1 << i;
return bitmap;
}
static int
get_free_slot_v3_hw(struct hisi_hba *hisi_hba, struct hisi_sas_dq *dq)
{
struct device *dev = hisi_hba->dev;
int queue = dq->id;
u32 r, w;
w = dq->wr_point;
r = hisi_sas_read32_relaxed(hisi_hba,
DLVRY_Q_0_RD_PTR + (queue * 0x14));
if (r == (w+1) % HISI_SAS_QUEUE_SLOTS) {
dev_warn(dev, "full queue=%d r=%d w=%d\n\n",
queue, r, w);
return -EAGAIN;
}
return 0;
}
static void start_delivery_v3_hw(struct hisi_sas_dq *dq)
{
struct hisi_hba *hisi_hba = dq->hisi_hba;
int dlvry_queue = dq->slot_prep->dlvry_queue;
int dlvry_queue_slot = dq->slot_prep->dlvry_queue_slot;
dq->wr_point = ++dlvry_queue_slot % HISI_SAS_QUEUE_SLOTS;
hisi_sas_write32(hisi_hba, DLVRY_Q_0_WR_PTR + (dlvry_queue * 0x14),
dq->wr_point);
}
static int prep_prd_sge_v3_hw(struct hisi_hba *hisi_hba,
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
static int prep_ssp_v3_hw(struct hisi_hba *hisi_hba,
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
u8 *buf_cmd;
u32 dw1 = 0, dw2 = 0;
hdr->dw0 = cpu_to_le32((1 << CMD_HDR_RESP_REPORT_OFF) |
(2 << CMD_HDR_TLR_CTRL_OFF) |
(port->id << CMD_HDR_PORT_OFF) |
(priority << CMD_HDR_PRIORITY_OFF) |
(1 << CMD_HDR_CMD_OFF));
dw1 = 1 << CMD_HDR_VDTL_OFF;
if (is_tmf) {
dw1 |= 2 << CMD_HDR_FRAME_TYPE_OFF;
dw1 |= DIR_NO_DATA << CMD_HDR_DIR_OFF;
} else {
dw1 |= 1 << CMD_HDR_FRAME_TYPE_OFF;
switch (scsi_cmnd->sc_data_direction) {
case DMA_TO_DEVICE:
has_data = 1;
dw1 |= DIR_TO_DEVICE << CMD_HDR_DIR_OFF;
break;
case DMA_FROM_DEVICE:
has_data = 1;
dw1 |= DIR_TO_INI << CMD_HDR_DIR_OFF;
break;
default:
dw1 &= ~CMD_HDR_DIR_MSK;
}
}
dw1 |= sas_dev->device_id << CMD_HDR_DEV_ID_OFF;
hdr->dw1 = cpu_to_le32(dw1);
dw2 = (((sizeof(struct ssp_command_iu) + sizeof(struct ssp_frame_hdr)
+ 3) / 4) << CMD_HDR_CFL_OFF) |
((HISI_SAS_MAX_SSP_RESP_SZ / 4) << CMD_HDR_MRFL_OFF) |
(2 << CMD_HDR_SG_MOD_OFF);
hdr->dw2 = cpu_to_le32(dw2);
hdr->transfer_tags = cpu_to_le32(slot->idx);
if (has_data) {
rc = prep_prd_sge_v3_hw(hisi_hba, slot, hdr, task->scatter,
slot->n_elem);
if (rc)
return rc;
}
hdr->data_transfer_len = cpu_to_le32(task->total_xfer_len);
hdr->cmd_table_addr = cpu_to_le64(hisi_sas_cmd_hdr_addr_dma(slot));
hdr->sts_buffer_addr = cpu_to_le64(hisi_sas_status_buf_addr_dma(slot));
buf_cmd = hisi_sas_cmd_hdr_addr_mem(slot) +
sizeof(struct ssp_frame_hdr);
memcpy(buf_cmd, &task->ssp_task.LUN, 8);
if (!is_tmf) {
buf_cmd[9] = ssp_task->task_attr | (ssp_task->task_prio << 3);
memcpy(buf_cmd + 12, scsi_cmnd->cmnd, scsi_cmnd->cmd_len);
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
static int prep_smp_v3_hw(struct hisi_hba *hisi_hba,
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
(2 << CMD_HDR_CMD_OFF));
hdr->dw1 = cpu_to_le32((sas_dev->device_id << CMD_HDR_DEV_ID_OFF) |
(1 << CMD_HDR_FRAME_TYPE_OFF) |
(DIR_NO_DATA << CMD_HDR_DIR_OFF));
hdr->dw2 = cpu_to_le32((((req_len - 4) / 4) << CMD_HDR_CFL_OFF) |
(HISI_SAS_MAX_SMP_RESP_SZ / 4 <<
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
static int get_ncq_tag_v3_hw(struct sas_task *task, u32 *tag)
{
struct ata_queued_cmd *qc = task->uldd_task;
if (qc) {
if (qc->tf.command == ATA_CMD_FPDMA_WRITE ||
qc->tf.command == ATA_CMD_FPDMA_READ) {
*tag = qc->tag;
return 1;
}
}
return 0;
}
static int prep_ata_v3_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot)
{
struct sas_task *task = slot->task;
struct domain_device *device = task->dev;
struct domain_device *parent_dev = device->parent;
struct hisi_sas_device *sas_dev = device->lldd_dev;
struct hisi_sas_cmd_hdr *hdr = slot->cmd_hdr;
struct asd_sas_port *sas_port = device->port;
struct hisi_sas_port *port = to_hisi_sas_port(sas_port);
u8 *buf_cmd;
int has_data = 0, rc = 0, hdr_tag = 0;
u32 dw1 = 0, dw2 = 0;
hdr->dw0 = cpu_to_le32(port->id << CMD_HDR_PORT_OFF);
if (parent_dev && DEV_IS_EXPANDER(parent_dev->dev_type))
hdr->dw0 |= cpu_to_le32(3 << CMD_HDR_CMD_OFF);
else
hdr->dw0 |= cpu_to_le32(4 << CMD_HDR_CMD_OFF);
switch (task->data_dir) {
case DMA_TO_DEVICE:
has_data = 1;
dw1 |= DIR_TO_DEVICE << CMD_HDR_DIR_OFF;
break;
case DMA_FROM_DEVICE:
has_data = 1;
dw1 |= DIR_TO_INI << CMD_HDR_DIR_OFF;
break;
default:
dw1 &= ~CMD_HDR_DIR_MSK;
}
if ((task->ata_task.fis.command == ATA_CMD_DEV_RESET) &&
(task->ata_task.fis.control & ATA_SRST))
dw1 |= 1 << CMD_HDR_RESET_OFF;
dw1 |= (hisi_sas_get_ata_protocol(
task->ata_task.fis.command, task->data_dir))
<< CMD_HDR_FRAME_TYPE_OFF;
dw1 |= sas_dev->device_id << CMD_HDR_DEV_ID_OFF;
if (CMD_IS_UNCONSTRAINT(task->ata_task.fis.command))
dw1 |= 1 << CMD_HDR_UNCON_CMD_OFF;
hdr->dw1 = cpu_to_le32(dw1);
if (task->ata_task.use_ncq && get_ncq_tag_v3_hw(task, &hdr_tag)) {
task->ata_task.fis.sector_count |= (u8) (hdr_tag << 3);
dw2 |= hdr_tag << CMD_HDR_NCQ_TAG_OFF;
}
dw2 |= (HISI_SAS_MAX_STP_RESP_SZ / 4) << CMD_HDR_CFL_OFF |
2 << CMD_HDR_SG_MOD_OFF;
hdr->dw2 = cpu_to_le32(dw2);
hdr->transfer_tags = cpu_to_le32(slot->idx);
if (has_data) {
rc = prep_prd_sge_v3_hw(hisi_hba, slot, hdr, task->scatter,
slot->n_elem);
if (rc)
return rc;
}
hdr->data_transfer_len = cpu_to_le32(task->total_xfer_len);
hdr->cmd_table_addr = cpu_to_le64(hisi_sas_cmd_hdr_addr_dma(slot));
hdr->sts_buffer_addr = cpu_to_le64(hisi_sas_status_buf_addr_dma(slot));
buf_cmd = hisi_sas_cmd_hdr_addr_mem(slot);
if (likely(!task->ata_task.device_control_reg_update))
task->ata_task.fis.flags |= 0x80;
memcpy(buf_cmd, &task->ata_task.fis, sizeof(struct host_to_dev_fis));
return 0;
}
static int prep_abort_v3_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot,
int device_id, int abort_flag, int tag_to_abort)
{
struct sas_task *task = slot->task;
struct domain_device *dev = task->dev;
struct hisi_sas_cmd_hdr *hdr = slot->cmd_hdr;
struct hisi_sas_port *port = slot->port;
hdr->dw0 = cpu_to_le32((5 << CMD_HDR_CMD_OFF) |
(port->id << CMD_HDR_PORT_OFF) |
((dev_is_sata(dev) ? 1:0)
<< CMD_HDR_ABORT_DEVICE_TYPE_OFF) |
(abort_flag
<< CMD_HDR_ABORT_FLAG_OFF));
hdr->dw1 = cpu_to_le32(device_id
<< CMD_HDR_DEV_ID_OFF);
hdr->dw7 = cpu_to_le32(tag_to_abort << CMD_HDR_ABORT_IPTT_OFF);
hdr->transfer_tags = cpu_to_le32(slot->idx);
return 0;
}
static int phy_up_v3_hw(int phy_no, struct hisi_hba *hisi_hba)
{
int i, res = 0;
u32 context, port_id, link_rate, hard_phy_linkrate;
struct hisi_sas_phy *phy = &hisi_hba->phy[phy_no];
struct asd_sas_phy *sas_phy = &phy->sas_phy;
struct device *dev = hisi_hba->dev;
hisi_sas_phy_write32(hisi_hba, phy_no, PHYCTRL_PHY_ENA_MSK, 1);
port_id = hisi_sas_read32(hisi_hba, PHY_PORT_NUM_MA);
port_id = (port_id >> (4 * phy_no)) & 0xf;
link_rate = hisi_sas_read32(hisi_hba, PHY_CONN_RATE);
link_rate = (link_rate >> (phy_no * 4)) & 0xf;
if (port_id == 0xf) {
dev_err(dev, "phyup: phy%d invalid portid\n", phy_no);
res = IRQ_NONE;
goto end;
}
sas_phy->linkrate = link_rate;
hard_phy_linkrate = hisi_sas_phy_read32(hisi_hba, phy_no,
HARD_PHY_LINKRATE);
phy->maximum_linkrate = hard_phy_linkrate & 0xf;
phy->minimum_linkrate = (hard_phy_linkrate >> 4) & 0xf;
phy->phy_type &= ~(PORT_TYPE_SAS | PORT_TYPE_SATA);
context = hisi_sas_read32(hisi_hba, PHY_CONTEXT);
if (context & (1 << phy_no)) {
struct hisi_sas_initial_fis *initial_fis;
struct dev_to_host_fis *fis;
u8 attached_sas_addr[SAS_ADDR_SIZE] = {0};
dev_info(dev, "phyup: phy%d link_rate=%d\n", phy_no, link_rate);
initial_fis = &hisi_hba->initial_fis[phy_no];
fis = &initial_fis->fis;
sas_phy->oob_mode = SATA_OOB_MODE;
attached_sas_addr[0] = 0x50;
attached_sas_addr[7] = phy_no;
memcpy(sas_phy->attached_sas_addr,
attached_sas_addr,
SAS_ADDR_SIZE);
memcpy(sas_phy->frame_rcvd, fis,
sizeof(struct dev_to_host_fis));
phy->phy_type |= PORT_TYPE_SATA;
phy->identify.device_type = SAS_SATA_DEV;
phy->frame_rcvd_size = sizeof(struct dev_to_host_fis);
phy->identify.target_port_protocols = SAS_PROTOCOL_SATA;
} else {
u32 *frame_rcvd = (u32 *)sas_phy->frame_rcvd;
struct sas_identify_frame *id =
(struct sas_identify_frame *)frame_rcvd;
dev_info(dev, "phyup: phy%d link_rate=%d\n", phy_no, link_rate);
for (i = 0; i < 6; i++) {
u32 idaf = hisi_sas_phy_read32(hisi_hba, phy_no,
RX_IDAF_DWORD0 + (i * 4));
frame_rcvd[i] = __swab32(idaf);
}
sas_phy->oob_mode = SAS_OOB_MODE;
memcpy(sas_phy->attached_sas_addr,
&id->sas_addr,
SAS_ADDR_SIZE);
phy->phy_type |= PORT_TYPE_SAS;
phy->identify.device_type = id->dev_type;
phy->frame_rcvd_size = sizeof(struct sas_identify_frame);
if (phy->identify.device_type == SAS_END_DEVICE)
phy->identify.target_port_protocols =
SAS_PROTOCOL_SSP;
else if (phy->identify.device_type != SAS_PHY_UNUSED)
phy->identify.target_port_protocols =
SAS_PROTOCOL_SMP;
}
phy->port_id = port_id;
phy->phy_attached = 1;
queue_work(hisi_hba->wq, &phy->phyup_ws);
end:
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0,
CHL_INT0_SL_PHY_ENABLE_MSK);
hisi_sas_phy_write32(hisi_hba, phy_no, PHYCTRL_PHY_ENA_MSK, 0);
return res;
}
static int phy_down_v3_hw(int phy_no, struct hisi_hba *hisi_hba)
{
int res = 0;
u32 phy_state, sl_ctrl, txid_auto;
struct device *dev = hisi_hba->dev;
hisi_sas_phy_write32(hisi_hba, phy_no, PHYCTRL_NOT_RDY_MSK, 1);
phy_state = hisi_sas_read32(hisi_hba, PHY_STATE);
dev_info(dev, "phydown: phy%d phy_state=0x%x\n", phy_no, phy_state);
hisi_sas_phy_down(hisi_hba, phy_no, (phy_state & 1 << phy_no) ? 1 : 0);
sl_ctrl = hisi_sas_phy_read32(hisi_hba, phy_no, SL_CONTROL);
hisi_sas_phy_write32(hisi_hba, phy_no, SL_CONTROL,
sl_ctrl&(~SL_CTA_MSK));
txid_auto = hisi_sas_phy_read32(hisi_hba, phy_no, TXID_AUTO);
hisi_sas_phy_write32(hisi_hba, phy_no, TXID_AUTO,
txid_auto | CT3_MSK);
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0, CHL_INT0_NOT_RDY_MSK);
hisi_sas_phy_write32(hisi_hba, phy_no, PHYCTRL_NOT_RDY_MSK, 0);
return res;
}
static void phy_bcast_v3_hw(int phy_no, struct hisi_hba *hisi_hba)
{
struct hisi_sas_phy *phy = &hisi_hba->phy[phy_no];
struct asd_sas_phy *sas_phy = &phy->sas_phy;
struct sas_ha_struct *sas_ha = &hisi_hba->sha;
hisi_sas_phy_write32(hisi_hba, phy_no, SL_RX_BCAST_CHK_MSK, 1);
sas_ha->notify_port_event(sas_phy, PORTE_BROADCAST_RCVD);
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0,
CHL_INT0_SL_RX_BCST_ACK_MSK);
hisi_sas_phy_write32(hisi_hba, phy_no, SL_RX_BCAST_CHK_MSK, 0);
}
static irqreturn_t int_phy_up_down_bcast_v3_hw(int irq_no, void *p)
{
struct hisi_hba *hisi_hba = p;
u32 irq_msk;
int phy_no = 0;
irqreturn_t res = IRQ_NONE;
irq_msk = hisi_sas_read32(hisi_hba, CHNL_INT_STATUS)
& 0x11111111;
while (irq_msk) {
if (irq_msk & 1) {
u32 irq_value = hisi_sas_phy_read32(hisi_hba, phy_no,
CHL_INT0);
u32 phy_state = hisi_sas_read32(hisi_hba, PHY_STATE);
int rdy = phy_state & (1 << phy_no);
if (rdy) {
if (irq_value & CHL_INT0_SL_PHY_ENABLE_MSK)
if (phy_up_v3_hw(phy_no, hisi_hba)
== IRQ_HANDLED)
res = IRQ_HANDLED;
if (irq_value & CHL_INT0_SL_RX_BCST_ACK_MSK)
phy_bcast_v3_hw(phy_no, hisi_hba);
} else {
if (irq_value & CHL_INT0_NOT_RDY_MSK)
if (phy_down_v3_hw(phy_no, hisi_hba)
== IRQ_HANDLED)
res = IRQ_HANDLED;
}
}
irq_msk >>= 4;
phy_no++;
}
return res;
}
static irqreturn_t int_chnl_int_v3_hw(int irq_no, void *p)
{
struct hisi_hba *hisi_hba = p;
struct device *dev = hisi_hba->dev;
u32 ent_msk, ent_tmp, irq_msk;
int phy_no = 0;
ent_msk = hisi_sas_read32(hisi_hba, ENT_INT_SRC_MSK3);
ent_tmp = ent_msk;
ent_msk |= ENT_INT_SRC_MSK3_ENT95_MSK_MSK;
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK3, ent_msk);
irq_msk = hisi_sas_read32(hisi_hba, CHNL_INT_STATUS)
& 0xeeeeeeee;
while (irq_msk) {
u32 irq_value0 = hisi_sas_phy_read32(hisi_hba, phy_no,
CHL_INT0);
u32 irq_value1 = hisi_sas_phy_read32(hisi_hba, phy_no,
CHL_INT1);
u32 irq_value2 = hisi_sas_phy_read32(hisi_hba, phy_no,
CHL_INT2);
if ((irq_msk & (4 << (phy_no * 4))) &&
irq_value1) {
if (irq_value1 & (CHL_INT1_DMAC_RX_ECC_ERR_MSK |
CHL_INT1_DMAC_TX_ECC_ERR_MSK))
panic("%s: DMAC RX/TX ecc bad error! (0x%x)",
dev_name(dev), irq_value1);
hisi_sas_phy_write32(hisi_hba, phy_no,
CHL_INT1, irq_value1);
}
if (irq_msk & (8 << (phy_no * 4)) && irq_value2)
hisi_sas_phy_write32(hisi_hba, phy_no,
CHL_INT2, irq_value2);
if (irq_msk & (2 << (phy_no * 4)) && irq_value0) {
hisi_sas_phy_write32(hisi_hba, phy_no,
CHL_INT0, irq_value0
& (~CHL_INT0_HOTPLUG_TOUT_MSK)
& (~CHL_INT0_SL_PHY_ENABLE_MSK)
& (~CHL_INT0_NOT_RDY_MSK));
}
irq_msk &= ~(0xe << (phy_no * 4));
phy_no++;
}
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK3, ent_tmp);
return IRQ_HANDLED;
}
static void
slot_err_v3_hw(struct hisi_hba *hisi_hba, struct sas_task *task,
struct hisi_sas_slot *slot)
{
struct task_status_struct *ts = &task->task_status;
struct hisi_sas_complete_v3_hdr *complete_queue =
hisi_hba->complete_hdr[slot->cmplt_queue];
struct hisi_sas_complete_v3_hdr *complete_hdr =
&complete_queue[slot->cmplt_queue_slot];
struct hisi_sas_err_record_v3 *record =
hisi_sas_status_buf_addr_mem(slot);
u32 dma_rx_err_type = record->dma_rx_err_type;
u32 trans_tx_fail_type = record->trans_tx_fail_type;
switch (task->task_proto) {
case SAS_PROTOCOL_SSP:
if (dma_rx_err_type & RX_DATA_LEN_UNDERFLOW_MSK) {
ts->residual = trans_tx_fail_type;
ts->stat = SAS_DATA_UNDERRUN;
} else if (complete_hdr->dw3 & CMPLT_HDR_IO_IN_TARGET_MSK) {
ts->stat = SAS_QUEUE_FULL;
slot->abort = 1;
} else {
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_RSVD_RETRY;
}
break;
case SAS_PROTOCOL_SATA:
case SAS_PROTOCOL_STP:
case SAS_PROTOCOL_SATA | SAS_PROTOCOL_STP:
if (dma_rx_err_type & RX_DATA_LEN_UNDERFLOW_MSK) {
ts->residual = trans_tx_fail_type;
ts->stat = SAS_DATA_UNDERRUN;
} else if (complete_hdr->dw3 & CMPLT_HDR_IO_IN_TARGET_MSK) {
ts->stat = SAS_PHY_DOWN;
slot->abort = 1;
} else {
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_RSVD_RETRY;
}
hisi_sas_sata_done(task, slot);
break;
case SAS_PROTOCOL_SMP:
ts->stat = SAM_STAT_CHECK_CONDITION;
break;
default:
break;
}
}
static int
slot_complete_v3_hw(struct hisi_hba *hisi_hba, struct hisi_sas_slot *slot)
{
struct sas_task *task = slot->task;
struct hisi_sas_device *sas_dev;
struct device *dev = hisi_hba->dev;
struct task_status_struct *ts;
struct domain_device *device;
enum exec_status sts;
struct hisi_sas_complete_v3_hdr *complete_queue =
hisi_hba->complete_hdr[slot->cmplt_queue];
struct hisi_sas_complete_v3_hdr *complete_hdr =
&complete_queue[slot->cmplt_queue_slot];
int aborted;
unsigned long flags;
if (unlikely(!task || !task->lldd_task || !task->dev))
return -EINVAL;
ts = &task->task_status;
device = task->dev;
sas_dev = device->lldd_dev;
spin_lock_irqsave(&task->task_state_lock, flags);
aborted = task->task_state_flags & SAS_TASK_STATE_ABORTED;
task->task_state_flags &=
~(SAS_TASK_STATE_PENDING | SAS_TASK_AT_INITIATOR);
spin_unlock_irqrestore(&task->task_state_lock, flags);
memset(ts, 0, sizeof(*ts));
ts->resp = SAS_TASK_COMPLETE;
if (unlikely(aborted)) {
ts->stat = SAS_ABORTED_TASK;
hisi_sas_slot_task_free(hisi_hba, task, slot);
return -1;
}
if (unlikely(!sas_dev)) {
dev_dbg(dev, "slot complete: port has not device\n");
ts->stat = SAS_PHY_DOWN;
goto out;
}
switch ((complete_hdr->dw0 & CMPLT_HDR_ABORT_STAT_MSK)
>> CMPLT_HDR_ABORT_STAT_OFF) {
case STAT_IO_ABORTED:
ts->stat = SAS_ABORTED_TASK;
goto out;
case STAT_IO_COMPLETE:
ts->stat = TMF_RESP_FUNC_SUCC;
goto out;
case STAT_IO_NO_DEVICE:
ts->stat = TMF_RESP_FUNC_COMPLETE;
goto out;
case STAT_IO_NOT_VALID:
ts->stat = TMF_RESP_FUNC_FAILED;
goto out;
default:
break;
}
if ((complete_hdr->dw0 & CMPLT_HDR_CMPLT_MSK) == 0x3) {
slot_err_v3_hw(hisi_hba, task, slot);
if (unlikely(slot->abort))
return ts->stat;
goto out;
}
switch (task->task_proto) {
case SAS_PROTOCOL_SSP: {
struct ssp_response_iu *iu =
hisi_sas_status_buf_addr_mem(slot) +
sizeof(struct hisi_sas_err_record);
sas_ssp_task_response(dev, task, iu);
break;
}
case SAS_PROTOCOL_SMP: {
struct scatterlist *sg_resp = &task->smp_task.smp_resp;
void *to;
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
ts->stat = SAM_STAT_GOOD;
hisi_sas_sata_done(task, slot);
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
spin_lock_irqsave(&task->task_state_lock, flags);
task->task_state_flags |= SAS_TASK_STATE_DONE;
spin_unlock_irqrestore(&task->task_state_lock, flags);
spin_lock_irqsave(&hisi_hba->lock, flags);
hisi_sas_slot_task_free(hisi_hba, task, slot);
spin_unlock_irqrestore(&hisi_hba->lock, flags);
sts = ts->stat;
if (task->task_done)
task->task_done(task);
return sts;
}
static void cq_tasklet_v3_hw(unsigned long val)
{
struct hisi_sas_cq *cq = (struct hisi_sas_cq *)val;
struct hisi_hba *hisi_hba = cq->hisi_hba;
struct hisi_sas_slot *slot;
struct hisi_sas_itct *itct;
struct hisi_sas_complete_v3_hdr *complete_queue;
u32 rd_point = cq->rd_point, wr_point, dev_id;
int queue = cq->id;
struct hisi_sas_dq *dq = &hisi_hba->dq[queue];
complete_queue = hisi_hba->complete_hdr[queue];
spin_lock(&dq->lock);
wr_point = hisi_sas_read32(hisi_hba, COMPL_Q_0_WR_PTR +
(0x14 * queue));
while (rd_point != wr_point) {
struct hisi_sas_complete_v3_hdr *complete_hdr;
int iptt;
complete_hdr = &complete_queue[rd_point];
if (complete_hdr->act) {
u32 act_tmp = complete_hdr->act;
int ncq_tag_count = ffs(act_tmp);
dev_id = (complete_hdr->dw1 & CMPLT_HDR_DEV_ID_MSK) >>
CMPLT_HDR_DEV_ID_OFF;
itct = &hisi_hba->itct[dev_id];
while (ncq_tag_count) {
__le64 *ncq_tag = &itct->qw4_15[0];
ncq_tag_count -= 1;
iptt = (ncq_tag[ncq_tag_count / 5]
>> (ncq_tag_count % 5) * 12) & 0xfff;
slot = &hisi_hba->slot_info[iptt];
slot->cmplt_queue_slot = rd_point;
slot->cmplt_queue = queue;
slot_complete_v3_hw(hisi_hba, slot);
act_tmp &= ~(1 << ncq_tag_count);
ncq_tag_count = ffs(act_tmp);
}
} else {
iptt = (complete_hdr->dw1) & CMPLT_HDR_IPTT_MSK;
slot = &hisi_hba->slot_info[iptt];
slot->cmplt_queue_slot = rd_point;
slot->cmplt_queue = queue;
slot_complete_v3_hw(hisi_hba, slot);
}
if (++rd_point >= HISI_SAS_QUEUE_SLOTS)
rd_point = 0;
}
cq->rd_point = rd_point;
hisi_sas_write32(hisi_hba, COMPL_Q_0_RD_PTR + (0x14 * queue), rd_point);
spin_unlock(&dq->lock);
}
static irqreturn_t cq_interrupt_v3_hw(int irq_no, void *p)
{
struct hisi_sas_cq *cq = p;
struct hisi_hba *hisi_hba = cq->hisi_hba;
int queue = cq->id;
hisi_sas_write32(hisi_hba, OQ_INT_SRC, 1 << queue);
tasklet_schedule(&cq->tasklet);
return IRQ_HANDLED;
}
static int interrupt_init_v3_hw(struct hisi_hba *hisi_hba)
{
struct device *dev = hisi_hba->dev;
struct pci_dev *pdev = hisi_hba->pci_dev;
int vectors, rc;
int i, k;
int max_msi = HISI_SAS_MSI_COUNT_V3_HW;
vectors = pci_alloc_irq_vectors(hisi_hba->pci_dev, 1,
max_msi, PCI_IRQ_MSI);
if (vectors < max_msi) {
dev_err(dev, "could not allocate all msi (%d)\n", vectors);
return -ENOENT;
}
rc = devm_request_irq(dev, pci_irq_vector(pdev, 1),
int_phy_up_down_bcast_v3_hw, 0,
DRV_NAME " phy", hisi_hba);
if (rc) {
dev_err(dev, "could not request phy interrupt, rc=%d\n", rc);
rc = -ENOENT;
goto free_irq_vectors;
}
rc = devm_request_irq(dev, pci_irq_vector(pdev, 2),
int_chnl_int_v3_hw, 0,
DRV_NAME " channel", hisi_hba);
if (rc) {
dev_err(dev, "could not request chnl interrupt, rc=%d\n", rc);
rc = -ENOENT;
goto free_phy_irq;
}
for (i = 0; i < hisi_hba->queue_count; i++) {
struct hisi_sas_cq *cq = &hisi_hba->cq[i];
struct tasklet_struct *t = &cq->tasklet;
rc = devm_request_irq(dev, pci_irq_vector(pdev, i+16),
cq_interrupt_v3_hw, 0,
DRV_NAME " cq", cq);
if (rc) {
dev_err(dev,
"could not request cq%d interrupt, rc=%d\n",
i, rc);
rc = -ENOENT;
goto free_cq_irqs;
}
tasklet_init(t, cq_tasklet_v3_hw, (unsigned long)cq);
}
return 0;
free_cq_irqs:
for (k = 0; k < i; k++) {
struct hisi_sas_cq *cq = &hisi_hba->cq[k];
free_irq(pci_irq_vector(pdev, k+16), cq);
}
free_irq(pci_irq_vector(pdev, 2), hisi_hba);
free_phy_irq:
free_irq(pci_irq_vector(pdev, 1), hisi_hba);
free_irq_vectors:
pci_free_irq_vectors(pdev);
return rc;
}
static int hisi_sas_v3_init(struct hisi_hba *hisi_hba)
{
int rc;
rc = hw_init_v3_hw(hisi_hba);
if (rc)
return rc;
rc = interrupt_init_v3_hw(hisi_hba);
if (rc)
return rc;
return 0;
}
static struct Scsi_Host *
hisi_sas_shost_alloc_pci(struct pci_dev *pdev)
{
struct Scsi_Host *shost;
struct hisi_hba *hisi_hba;
struct device *dev = &pdev->dev;
shost = scsi_host_alloc(hisi_sas_sht, sizeof(*hisi_hba));
if (!shost)
goto err_out;
hisi_hba = shost_priv(shost);
hisi_hba->hw = &hisi_sas_v3_hw;
hisi_hba->pci_dev = pdev;
hisi_hba->dev = dev;
hisi_hba->shost = shost;
SHOST_TO_SAS_HA(shost) = &hisi_hba->sha;
init_timer(&hisi_hba->timer);
if (hisi_sas_get_fw_info(hisi_hba) < 0)
goto err_out;
if (hisi_sas_alloc(hisi_hba, shost)) {
hisi_sas_free(hisi_hba);
goto err_out;
}
return shost;
err_out:
dev_err(dev, "shost alloc failed\n");
return NULL;
}
static int
hisi_sas_v3_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct Scsi_Host *shost;
struct hisi_hba *hisi_hba;
struct device *dev = &pdev->dev;
struct asd_sas_phy **arr_phy;
struct asd_sas_port **arr_port;
struct sas_ha_struct *sha;
int rc, phy_nr, port_nr, i;
rc = pci_enable_device(pdev);
if (rc)
goto err_out;
pci_set_master(pdev);
rc = pci_request_regions(pdev, DRV_NAME);
if (rc)
goto err_out_disable_device;
if ((pci_set_dma_mask(pdev, DMA_BIT_MASK(64)) != 0) ||
(pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64)) != 0)) {
if ((pci_set_dma_mask(pdev, DMA_BIT_MASK(32)) != 0) ||
(pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32)) != 0)) {
dev_err(dev, "No usable DMA addressing method\n");
rc = -EIO;
goto err_out_regions;
}
}
shost = hisi_sas_shost_alloc_pci(pdev);
if (!shost) {
rc = -ENOMEM;
goto err_out_regions;
}
sha = SHOST_TO_SAS_HA(shost);
hisi_hba = shost_priv(shost);
dev_set_drvdata(dev, sha);
hisi_hba->regs = pcim_iomap(pdev, 5, 0);
if (!hisi_hba->regs) {
dev_err(dev, "cannot map register.\n");
rc = -ENOMEM;
goto err_out_ha;
}
phy_nr = port_nr = hisi_hba->n_phy;
arr_phy = devm_kcalloc(dev, phy_nr, sizeof(void *), GFP_KERNEL);
arr_port = devm_kcalloc(dev, port_nr, sizeof(void *), GFP_KERNEL);
if (!arr_phy || !arr_port) {
rc = -ENOMEM;
goto err_out_ha;
}
sha->sas_phy = arr_phy;
sha->sas_port = arr_port;
sha->core.shost = shost;
sha->lldd_ha = hisi_hba;
shost->transportt = hisi_sas_stt;
shost->max_id = HISI_SAS_MAX_DEVICES;
shost->max_lun = ~0;
shost->max_channel = 1;
shost->max_cmd_len = 16;
shost->sg_tablesize = min_t(u16, SG_ALL, HISI_SAS_SGE_PAGE_CNT);
shost->can_queue = hisi_hba->hw->max_command_entries;
shost->cmd_per_lun = hisi_hba->hw->max_command_entries;
sha->sas_ha_name = DRV_NAME;
sha->dev = dev;
sha->lldd_module = THIS_MODULE;
sha->sas_addr = &hisi_hba->sas_addr[0];
sha->num_phys = hisi_hba->n_phy;
sha->core.shost = hisi_hba->shost;
for (i = 0; i < hisi_hba->n_phy; i++) {
sha->sas_phy[i] = &hisi_hba->phy[i].sas_phy;
sha->sas_port[i] = &hisi_hba->port[i].sas_port;
}
hisi_sas_init_add(hisi_hba);
rc = scsi_add_host(shost, dev);
if (rc)
goto err_out_ha;
rc = sas_register_ha(sha);
if (rc)
goto err_out_register_ha;
rc = hisi_hba->hw->hw_init(hisi_hba);
if (rc)
goto err_out_register_ha;
scsi_scan_host(shost);
return 0;
err_out_register_ha:
scsi_remove_host(shost);
err_out_ha:
kfree(shost);
err_out_regions:
pci_release_regions(pdev);
err_out_disable_device:
pci_disable_device(pdev);
err_out:
return rc;
}
static void
hisi_sas_v3_destroy_irqs(struct pci_dev *pdev, struct hisi_hba *hisi_hba)
{
int i;
free_irq(pci_irq_vector(pdev, 1), hisi_hba);
free_irq(pci_irq_vector(pdev, 2), hisi_hba);
for (i = 0; i < hisi_hba->queue_count; i++) {
struct hisi_sas_cq *cq = &hisi_hba->cq[i];
free_irq(pci_irq_vector(pdev, i+16), cq);
}
pci_free_irq_vectors(pdev);
}
static void hisi_sas_v3_remove(struct pci_dev *pdev)
{
struct device *dev = &pdev->dev;
struct sas_ha_struct *sha = dev_get_drvdata(dev);
struct hisi_hba *hisi_hba = sha->lldd_ha;
sas_unregister_ha(sha);
sas_remove_host(sha->core.shost);
hisi_sas_free(hisi_hba);
hisi_sas_v3_destroy_irqs(pdev, hisi_hba);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
