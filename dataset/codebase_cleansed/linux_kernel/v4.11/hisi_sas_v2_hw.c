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
static int
slot_index_alloc_quirk_v2_hw(struct hisi_hba *hisi_hba, int *slot_idx,
struct domain_device *device)
{
unsigned int index = 0;
void *bitmap = hisi_hba->slot_index_tags;
int sata_dev = dev_is_sata(device);
while (1) {
index = find_next_zero_bit(bitmap, hisi_hba->slot_index_count,
index);
if (index >= hisi_hba->slot_index_count)
return -SAS_QUEUE_FULL;
if (sata_dev || (index & 1))
break;
index++;
}
set_bit(index, bitmap);
*slot_idx = index;
return 0;
}
static struct
hisi_sas_device *alloc_dev_quirk_v2_hw(struct domain_device *device)
{
struct hisi_hba *hisi_hba = device->port->ha->lldd_ha;
struct hisi_sas_device *sas_dev = NULL;
int i, sata_dev = dev_is_sata(device);
spin_lock(&hisi_hba->lock);
for (i = 0; i < HISI_SAS_MAX_DEVICES; i++) {
if (sata_dev && (i & 1))
continue;
if (hisi_hba->devices[i].dev_type == SAS_PHY_UNUSED) {
hisi_hba->devices[i].device_id = i;
sas_dev = &hisi_hba->devices[i];
sas_dev->dev_status = HISI_SAS_DEV_NORMAL;
sas_dev->dev_type = device->dev_type;
sas_dev->hisi_hba = hisi_hba;
sas_dev->sas_device = device;
break;
}
}
spin_unlock(&hisi_hba->lock);
return sas_dev;
}
static void config_phy_opt_mode_v2_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CFG);
cfg &= ~PHY_CFG_DC_OPT_MSK;
cfg |= 1 << PHY_CFG_DC_OPT_OFF;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CFG, cfg);
}
static void config_id_frame_v2_hw(struct hisi_hba *hisi_hba, int phy_no)
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
static void setup_itct_v2_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_device *sas_dev)
{
struct domain_device *device = sas_dev->sas_device;
struct device *dev = &hisi_hba->pdev->dev;
u64 qw0, device_id = sas_dev->device_id;
struct hisi_sas_itct *itct = &hisi_hba->itct[device_id];
struct domain_device *parent_dev = device->parent;
struct hisi_sas_port *port = device->port->lldd_port;
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
(ITCT_HDR_SMP_TIMEOUT << ITCT_HDR_SMP_TIMEOUT_OFF) |
(1 << ITCT_HDR_AWT_CONTINUE_OFF) |
(port->id << ITCT_HDR_PORT_ID_OFF));
itct->qw0 = cpu_to_le64(qw0);
memcpy(&itct->sas_addr, device->sas_addr, SAS_ADDR_SIZE);
itct->sas_addr = __swab64(itct->sas_addr);
if (!dev_is_sata(device))
itct->qw2 = cpu_to_le64((5000ULL << ITCT_HDR_INLT_OFF) |
(0x1ULL << ITCT_HDR_BITLT_OFF) |
(0x32ULL << ITCT_HDR_MCTLT_OFF) |
(0x1ULL << ITCT_HDR_RTOLT_OFF));
}
static void free_device_v2_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_device *sas_dev)
{
u64 dev_id = sas_dev->device_id;
struct device *dev = &hisi_hba->pdev->dev;
struct hisi_sas_itct *itct = &hisi_hba->itct[dev_id];
u32 reg_val = hisi_sas_read32(hisi_hba, ENT_INT_SRC3);
int i;
if (ENT_INT_SRC3_ITC_INT_MSK & reg_val)
hisi_sas_write32(hisi_hba, ENT_INT_SRC3,
ENT_INT_SRC3_ITC_INT_MSK);
for (i = 0; i < 2; i++) {
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
hisi_sas_write32(hisi_hba, ITCT_CLR, 0);
dev_dbg(dev, "clear ITCT ok\n");
break;
}
}
}
static int reset_hw_v2_hw(struct hisi_hba *hisi_hba)
{
int i, reset_val;
u32 val;
unsigned long end_time;
struct device *dev = &hisi_hba->pdev->dev;
if (hisi_hba->n_phy == 9)
reset_val = 0x1fffff;
else
reset_val = 0x7ffff;
hisi_sas_write32(hisi_hba, DLVRY_QUEUE_ENABLE, 0);
for (i = 0; i < hisi_hba->n_phy; i++) {
u32 phy_cfg = hisi_sas_phy_read32(hisi_hba, i, PHY_CFG);
phy_cfg &= ~PHY_CTRL_RESET_MSK;
hisi_sas_phy_write32(hisi_hba, i, PHY_CFG, phy_cfg);
}
udelay(50);
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
reset_val);
regmap_write(hisi_hba->ctrl, hisi_hba->ctrl_clock_ena_reg + 4,
reset_val);
msleep(1);
regmap_read(hisi_hba->ctrl, hisi_hba->ctrl_reset_sts_reg, &val);
if (reset_val != (val & reset_val)) {
dev_err(dev, "SAS reset fail.\n");
return -EIO;
}
regmap_write(hisi_hba->ctrl, hisi_hba->ctrl_reset_reg + 4,
reset_val);
regmap_write(hisi_hba->ctrl, hisi_hba->ctrl_clock_ena_reg,
reset_val);
msleep(1);
regmap_read(hisi_hba->ctrl, hisi_hba->ctrl_reset_sts_reg,
&val);
if (val & reset_val) {
dev_err(dev, "SAS de-reset fail.\n");
return -EIO;
}
} else
dev_warn(dev, "no reset method\n");
return 0;
}
static void init_reg_v2_hw(struct hisi_hba *hisi_hba)
{
struct device *dev = &hisi_hba->pdev->dev;
int i;
if (device_property_present(dev, "hip06-sas-v2-quirk-amt")) {
hisi_sas_write32(hisi_hba, AM_CFG_MAX_TRANS, 0x2020);
hisi_sas_write32(hisi_hba, AM_CFG_SINGLE_PORT_MAX_TRANS,
0x2020);
}
hisi_sas_write32(hisi_hba, DLVRY_QUEUE_ENABLE,
(u32)((1ULL << hisi_hba->queue_count) - 1));
hisi_sas_write32(hisi_hba, AXI_USER1, 0xc0000000);
hisi_sas_write32(hisi_hba, AXI_USER2, 0x10000);
hisi_sas_write32(hisi_hba, HGC_SAS_TXFAIL_RETRY_CTRL, 0x108);
hisi_sas_write32(hisi_hba, HGC_SAS_TX_OPEN_FAIL_RETRY_CTRL, 0x7FF);
hisi_sas_write32(hisi_hba, OPENA_WT_CONTI_TIME, 0x1);
hisi_sas_write32(hisi_hba, I_T_NEXUS_LOSS_TIME, 0x1F4);
hisi_sas_write32(hisi_hba, MAX_CON_TIME_LIMIT_TIME, 0x32);
hisi_sas_write32(hisi_hba, BUS_INACTIVE_LIMIT_TIME, 0x1);
hisi_sas_write32(hisi_hba, CFG_AGING_TIME, 0x1);
hisi_sas_write32(hisi_hba, HGC_ERR_STAT_EN, 0x1);
hisi_sas_write32(hisi_hba, HGC_GET_ITV_TIME, 0x1);
hisi_sas_write32(hisi_hba, INT_COAL_EN, 0x1);
hisi_sas_write32(hisi_hba, OQ_INT_COAL_TIME, 0x1);
hisi_sas_write32(hisi_hba, OQ_INT_COAL_CNT, 0x1);
hisi_sas_write32(hisi_hba, ENT_INT_COAL_TIME, 0x1);
hisi_sas_write32(hisi_hba, ENT_INT_COAL_CNT, 0x1);
hisi_sas_write32(hisi_hba, OQ_INT_SRC, 0x0);
hisi_sas_write32(hisi_hba, ENT_INT_SRC1, 0xffffffff);
hisi_sas_write32(hisi_hba, ENT_INT_SRC2, 0xffffffff);
hisi_sas_write32(hisi_hba, ENT_INT_SRC3, 0xffffffff);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK1, 0x7efefefe);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK2, 0x7efefefe);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK3, 0x7ffffffe);
hisi_sas_write32(hisi_hba, SAS_ECC_INTR_MSK, 0xfff00c30);
for (i = 0; i < hisi_hba->queue_count; i++)
hisi_sas_write32(hisi_hba, OQ0_INT_SRC_MSK+0x4*i, 0);
hisi_sas_write32(hisi_hba, AXI_AHB_CLK_CFG, 1);
hisi_sas_write32(hisi_hba, HYPER_STREAM_ID_EN_CFG, 1);
for (i = 0; i < hisi_hba->n_phy; i++) {
hisi_sas_phy_write32(hisi_hba, i, PROG_PHY_LINK_RATE, 0x855);
hisi_sas_phy_write32(hisi_hba, i, SAS_PHY_CTRL, 0x30b9908);
hisi_sas_phy_write32(hisi_hba, i, SL_TOUT_CFG, 0x7d7d7d7d);
hisi_sas_phy_write32(hisi_hba, i, SL_CONTROL, 0x0);
hisi_sas_phy_write32(hisi_hba, i, TXID_AUTO, 0x2);
hisi_sas_phy_write32(hisi_hba, i, DONE_RECEIVED_TIME, 0x10);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT0, 0xffffffff);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT1, 0xffffffff);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT2, 0xfff87fff);
hisi_sas_phy_write32(hisi_hba, i, RXOP_CHECK_CFG_H, 0x1000);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT1_MSK, 0xffffffff);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT2_MSK, 0x8ffffbff);
hisi_sas_phy_write32(hisi_hba, i, SL_CFG, 0x23f801fc);
hisi_sas_phy_write32(hisi_hba, i, PHY_CTRL_RDY_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, PHYCTRL_NOT_RDY_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, PHYCTRL_DWS_RESET_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, PHYCTRL_PHY_ENA_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, SL_RX_BCAST_CHK_MSK, 0x0);
hisi_sas_phy_write32(hisi_hba, i, CHL_INT_COAL_EN, 0x0);
hisi_sas_phy_write32(hisi_hba, i, PHYCTRL_OOB_RESTART_MSK, 0x0);
if (hisi_hba->refclk_frequency_mhz == 66)
hisi_sas_phy_write32(hisi_hba, i, PHY_CTRL, 0x199B694);
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
static void hisi_sas_link_timeout_enable_link(unsigned long data)
{
struct hisi_hba *hisi_hba = (struct hisi_hba *)data;
int i, reg_val;
for (i = 0; i < hisi_hba->n_phy; i++) {
reg_val = hisi_sas_phy_read32(hisi_hba, i, CON_CONTROL);
if (!(reg_val & BIT(0))) {
hisi_sas_phy_write32(hisi_hba, i,
CON_CONTROL, 0x7);
break;
}
}
hisi_hba->timer.function = hisi_sas_link_timeout_disable_link;
mod_timer(&hisi_hba->timer, jiffies + msecs_to_jiffies(900));
}
static void hisi_sas_link_timeout_disable_link(unsigned long data)
{
struct hisi_hba *hisi_hba = (struct hisi_hba *)data;
int i, reg_val;
reg_val = hisi_sas_read32(hisi_hba, PHY_STATE);
for (i = 0; i < hisi_hba->n_phy && reg_val; i++) {
if (reg_val & BIT(i)) {
hisi_sas_phy_write32(hisi_hba, i,
CON_CONTROL, 0x6);
break;
}
}
hisi_hba->timer.function = hisi_sas_link_timeout_enable_link;
mod_timer(&hisi_hba->timer, jiffies + msecs_to_jiffies(100));
}
static void set_link_timer_quirk(struct hisi_hba *hisi_hba)
{
hisi_hba->timer.data = (unsigned long)hisi_hba;
hisi_hba->timer.function = hisi_sas_link_timeout_disable_link;
hisi_hba->timer.expires = jiffies + msecs_to_jiffies(1000);
add_timer(&hisi_hba->timer);
}
static int hw_init_v2_hw(struct hisi_hba *hisi_hba)
{
struct device *dev = &hisi_hba->pdev->dev;
int rc;
rc = reset_hw_v2_hw(hisi_hba);
if (rc) {
dev_err(dev, "hisi_sas_reset_hw failed, rc=%d", rc);
return rc;
}
msleep(100);
init_reg_v2_hw(hisi_hba);
return 0;
}
static void enable_phy_v2_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CFG);
cfg |= PHY_CFG_ENA_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CFG, cfg);
}
static void disable_phy_v2_hw(struct hisi_hba *hisi_hba, int phy_no)
{
u32 cfg = hisi_sas_phy_read32(hisi_hba, phy_no, PHY_CFG);
cfg &= ~PHY_CFG_ENA_MSK;
hisi_sas_phy_write32(hisi_hba, phy_no, PHY_CFG, cfg);
}
static void start_phy_v2_hw(struct hisi_hba *hisi_hba, int phy_no)
{
config_id_frame_v2_hw(hisi_hba, phy_no);
config_phy_opt_mode_v2_hw(hisi_hba, phy_no);
enable_phy_v2_hw(hisi_hba, phy_no);
}
static void stop_phy_v2_hw(struct hisi_hba *hisi_hba, int phy_no)
{
disable_phy_v2_hw(hisi_hba, phy_no);
}
static void phy_hard_reset_v2_hw(struct hisi_hba *hisi_hba, int phy_no)
{
struct hisi_sas_phy *phy = &hisi_hba->phy[phy_no];
u32 txid_auto;
stop_phy_v2_hw(hisi_hba, phy_no);
if (phy->identify.device_type == SAS_END_DEVICE) {
txid_auto = hisi_sas_phy_read32(hisi_hba, phy_no, TXID_AUTO);
hisi_sas_phy_write32(hisi_hba, phy_no, TXID_AUTO,
txid_auto | TX_HARDRST_MSK);
}
msleep(100);
start_phy_v2_hw(hisi_hba, phy_no);
}
static void start_phys_v2_hw(struct hisi_hba *hisi_hba)
{
int i;
for (i = 0; i < hisi_hba->n_phy; i++)
start_phy_v2_hw(hisi_hba, i);
}
static void phys_init_v2_hw(struct hisi_hba *hisi_hba)
{
start_phys_v2_hw(hisi_hba);
}
static void sl_notify_v2_hw(struct hisi_hba *hisi_hba, int phy_no)
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
static enum sas_linkrate phy_get_max_linkrate_v2_hw(void)
{
return SAS_LINK_RATE_12_0_GBPS;
}
static void phy_set_linkrate_v2_hw(struct hisi_hba *hisi_hba, int phy_no,
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
phy_hard_reset_v2_hw(hisi_hba, phy_no);
}
static int get_wideport_bitmap_v2_hw(struct hisi_hba *hisi_hba, int port_id)
{
int i, bitmap = 0;
u32 phy_port_num_ma = hisi_sas_read32(hisi_hba, PHY_PORT_NUM_MA);
u32 phy_state = hisi_sas_read32(hisi_hba, PHY_STATE);
for (i = 0; i < (hisi_hba->n_phy < 9 ? hisi_hba->n_phy : 8); i++)
if (phy_state & 1 << i)
if (((phy_port_num_ma >> (i * 4)) & 0xf) == port_id)
bitmap |= 1 << i;
if (hisi_hba->n_phy == 9) {
u32 port_state = hisi_sas_read32(hisi_hba, PORT_STATE);
if (phy_state & 1 << 8)
if (((port_state & PORT_STATE_PHY8_PORT_NUM_MSK) >>
PORT_STATE_PHY8_PORT_NUM_OFF) == port_id)
bitmap |= 1 << 9;
}
return bitmap;
}
static int get_free_slot_v2_hw(struct hisi_hba *hisi_hba, u32 dev_id,
int *q, int *s)
{
struct device *dev = &hisi_hba->pdev->dev;
struct hisi_sas_dq *dq;
u32 r, w;
int queue = dev_id % hisi_hba->queue_count;
dq = &hisi_hba->dq[queue];
w = dq->wr_point;
r = hisi_sas_read32_relaxed(hisi_hba,
DLVRY_Q_0_RD_PTR + (queue * 0x14));
if (r == (w+1) % HISI_SAS_QUEUE_SLOTS) {
dev_warn(dev, "full queue=%d r=%d w=%d\n\n",
queue, r, w);
return -EAGAIN;
}
*q = queue;
*s = w;
return 0;
}
static void start_delivery_v2_hw(struct hisi_hba *hisi_hba)
{
int dlvry_queue = hisi_hba->slot_prep->dlvry_queue;
int dlvry_queue_slot = hisi_hba->slot_prep->dlvry_queue_slot;
struct hisi_sas_dq *dq = &hisi_hba->dq[dlvry_queue];
dq->wr_point = ++dlvry_queue_slot % HISI_SAS_QUEUE_SLOTS;
hisi_sas_write32(hisi_hba, DLVRY_Q_0_WR_PTR + (dlvry_queue * 0x14),
dq->wr_point);
}
static int prep_prd_sge_v2_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot,
struct hisi_sas_cmd_hdr *hdr,
struct scatterlist *scatter,
int n_elem)
{
struct device *dev = &hisi_hba->pdev->dev;
struct scatterlist *sg;
int i;
if (n_elem > HISI_SAS_SGE_PAGE_CNT) {
dev_err(dev, "prd err: n_elem(%d) > HISI_SAS_SGE_PAGE_CNT",
n_elem);
return -EINVAL;
}
slot->sge_page = dma_pool_alloc(hisi_hba->sge_page_pool, GFP_ATOMIC,
&slot->sge_page_dma);
if (!slot->sge_page)
return -ENOMEM;
for_each_sg(scatter, sg, n_elem, i) {
struct hisi_sas_sge *entry = &slot->sge_page->sge[i];
entry->addr = cpu_to_le64(sg_dma_address(sg));
entry->page_ctrl_0 = entry->page_ctrl_1 = 0;
entry->data_len = cpu_to_le32(sg_dma_len(sg));
entry->data_off = 0;
}
hdr->prd_table_addr = cpu_to_le64(slot->sge_page_dma);
hdr->sg_len = cpu_to_le32(n_elem << CMD_HDR_DATA_SGL_LEN_OFF);
return 0;
}
static int prep_smp_v2_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot)
{
struct sas_task *task = slot->task;
struct hisi_sas_cmd_hdr *hdr = slot->cmd_hdr;
struct domain_device *device = task->dev;
struct device *dev = &hisi_hba->pdev->dev;
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
hdr->sts_buffer_addr = cpu_to_le64(slot->status_buffer_dma);
return 0;
err_out_resp:
dma_unmap_sg(dev, &slot->task->smp_task.smp_resp, 1,
DMA_FROM_DEVICE);
err_out_req:
dma_unmap_sg(dev, &slot->task->smp_task.smp_req, 1,
DMA_TO_DEVICE);
return rc;
}
static int prep_ssp_v2_hw(struct hisi_hba *hisi_hba,
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
rc = prep_prd_sge_v2_hw(hisi_hba, slot, hdr, task->scatter,
slot->n_elem);
if (rc)
return rc;
}
hdr->data_transfer_len = cpu_to_le32(task->total_xfer_len);
hdr->cmd_table_addr = cpu_to_le64(slot->command_table_dma);
hdr->sts_buffer_addr = cpu_to_le64(slot->status_buffer_dma);
buf_cmd = slot->command_table + sizeof(struct ssp_frame_hdr);
memcpy(buf_cmd, &task->ssp_task.LUN, 8);
if (!is_tmf) {
buf_cmd[9] = task->ssp_task.task_attr |
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
static void sata_done_v2_hw(struct hisi_hba *hisi_hba, struct sas_task *task,
struct hisi_sas_slot *slot)
{
struct task_status_struct *ts = &task->task_status;
struct ata_task_resp *resp = (struct ata_task_resp *)ts->buf;
struct dev_to_host_fis *d2h = slot->status_buffer +
sizeof(struct hisi_sas_err_record);
resp->frame_len = sizeof(struct dev_to_host_fis);
memcpy(&resp->ending_fis[0], d2h, sizeof(struct dev_to_host_fis));
ts->buf_valid_size = sizeof(*resp);
}
static void slot_err_v2_hw(struct hisi_hba *hisi_hba,
struct sas_task *task,
struct hisi_sas_slot *slot)
{
struct task_status_struct *ts = &task->task_status;
struct hisi_sas_err_record_v2 *err_record = slot->status_buffer;
u32 trans_tx_fail_type = cpu_to_le32(err_record->trans_tx_fail_type);
u32 trans_rx_fail_type = cpu_to_le32(err_record->trans_rx_fail_type);
u16 dma_tx_err_type = cpu_to_le16(err_record->dma_tx_err_type);
u16 sipc_rx_err_type = cpu_to_le16(err_record->sipc_rx_err_type);
u32 dma_rx_err_type = cpu_to_le32(err_record->dma_rx_err_type);
int error = -1;
if (dma_rx_err_type) {
error = ffs(dma_rx_err_type)
- 1 + DMA_RX_ERR_BASE;
} else if (sipc_rx_err_type) {
error = ffs(sipc_rx_err_type)
- 1 + SIPC_RX_ERR_BASE;
} else if (dma_tx_err_type) {
error = ffs(dma_tx_err_type)
- 1 + DMA_TX_ERR_BASE;
} else if (trans_rx_fail_type) {
error = ffs(trans_rx_fail_type)
- 1 + TRANS_RX_FAIL_BASE;
} else if (trans_tx_fail_type) {
error = ffs(trans_tx_fail_type)
- 1 + TRANS_TX_FAIL_BASE;
}
switch (task->task_proto) {
case SAS_PROTOCOL_SSP:
{
switch (error) {
case TRANS_TX_OPEN_CNX_ERR_NO_DESTINATION:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_NO_DEST;
break;
}
case TRANS_TX_OPEN_CNX_ERR_PATHWAY_BLOCKED:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_PATH_BLOCKED;
break;
}
case TRANS_TX_OPEN_CNX_ERR_PROTOCOL_NOT_SUPPORTED:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_EPROTO;
break;
}
case TRANS_TX_OPEN_CNX_ERR_CONNECTION_RATE_NOT_SUPPORTED:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_CONN_RATE;
break;
}
case TRANS_TX_OPEN_CNX_ERR_BAD_DESTINATION:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_BAD_DEST;
break;
}
case TRANS_TX_OPEN_CNX_ERR_BREAK_RCVD:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_RSVD_RETRY;
break;
}
case TRANS_TX_OPEN_CNX_ERR_WRONG_DESTINATION:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_WRONG_DEST;
break;
}
case TRANS_TX_OPEN_CNX_ERR_ZONE_VIOLATION:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_UNKNOWN;
break;
}
case TRANS_TX_OPEN_CNX_ERR_LOW_PHY_POWER:
{
ts->stat = SAS_DEV_NO_RESPONSE;
break;
}
case TRANS_RX_ERR_WITH_CLOSE_PHY_DISABLE:
{
ts->stat = SAS_PHY_DOWN;
break;
}
case TRANS_TX_OPEN_CNX_ERR_OPEN_TIMEOUT:
{
ts->stat = SAS_OPEN_TO;
break;
}
case DMA_RX_DATA_LEN_OVERFLOW:
{
ts->stat = SAS_DATA_OVERRUN;
ts->residual = 0;
break;
}
case DMA_RX_DATA_LEN_UNDERFLOW:
case SIPC_RX_DATA_UNDERFLOW_ERR:
{
ts->residual = trans_tx_fail_type;
ts->stat = SAS_DATA_UNDERRUN;
break;
}
case TRANS_TX_ERR_FRAME_TXED:
{
ts->stat = SAS_QUEUE_FULL;
slot->abort = 1;
break;
}
case TRANS_TX_OPEN_FAIL_WITH_IT_NEXUS_LOSS:
case TRANS_TX_ERR_PHY_NOT_ENABLE:
case TRANS_TX_OPEN_CNX_ERR_BY_OTHER:
case TRANS_TX_OPEN_CNX_ERR_AIP_TIMEOUT:
case TRANS_TX_OPEN_RETRY_ERR_THRESHOLD_REACHED:
case TRANS_TX_ERR_WITH_BREAK_TIMEOUT:
case TRANS_TX_ERR_WITH_BREAK_REQUEST:
case TRANS_TX_ERR_WITH_BREAK_RECEVIED:
case TRANS_TX_ERR_WITH_CLOSE_TIMEOUT:
case TRANS_TX_ERR_WITH_CLOSE_NORMAL:
case TRANS_TX_ERR_WITH_CLOSE_DWS_TIMEOUT:
case TRANS_TX_ERR_WITH_CLOSE_COMINIT:
case TRANS_TX_ERR_WITH_NAK_RECEVIED:
case TRANS_TX_ERR_WITH_ACK_NAK_TIMEOUT:
case TRANS_TX_ERR_WITH_IPTT_CONFLICT:
case TRANS_TX_ERR_WITH_CREDIT_TIMEOUT:
case TRANS_RX_ERR_WITH_RXFRAME_CRC_ERR:
case TRANS_RX_ERR_WITH_RXFIS_8B10B_DISP_ERR:
case TRANS_RX_ERR_WITH_RXFRAME_HAVE_ERRPRM:
case TRANS_RX_ERR_WITH_BREAK_TIMEOUT:
case TRANS_RX_ERR_WITH_BREAK_REQUEST:
case TRANS_RX_ERR_WITH_BREAK_RECEVIED:
case TRANS_RX_ERR_WITH_CLOSE_NORMAL:
case TRANS_RX_ERR_WITH_CLOSE_DWS_TIMEOUT:
case TRANS_RX_ERR_WITH_CLOSE_COMINIT:
case TRANS_RX_ERR_WITH_DATA_LEN0:
case TRANS_RX_ERR_WITH_BAD_HASH:
case TRANS_RX_XRDY_WLEN_ZERO_ERR:
case TRANS_RX_SSP_FRM_LEN_ERR:
case TRANS_RX_ERR_WITH_BAD_FRM_TYPE:
case DMA_TX_UNEXP_XFER_ERR:
case DMA_TX_UNEXP_RETRANS_ERR:
case DMA_TX_XFER_LEN_OVERFLOW:
case DMA_TX_XFER_OFFSET_ERR:
case DMA_RX_DATA_OFFSET_ERR:
case DMA_RX_UNEXP_NORM_RESP_ERR:
case DMA_RX_UNEXP_RDFRAME_ERR:
case DMA_RX_UNKNOWN_FRM_ERR:
{
ts->stat = SAS_OPEN_REJECT;
ts->open_rej_reason = SAS_OREJ_UNKNOWN;
break;
}
default:
break;
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
switch (error) {
case TRANS_TX_OPEN_CNX_ERR_LOW_PHY_POWER:
case TRANS_TX_OPEN_CNX_ERR_PATHWAY_BLOCKED:
case TRANS_TX_OPEN_CNX_ERR_NO_DESTINATION:
{
ts->resp = SAS_TASK_UNDELIVERED;
ts->stat = SAS_DEV_NO_RESPONSE;
break;
}
case TRANS_TX_OPEN_CNX_ERR_PROTOCOL_NOT_SUPPORTED:
case TRANS_TX_OPEN_CNX_ERR_CONNECTION_RATE_NOT_SUPPORTED:
case TRANS_TX_OPEN_CNX_ERR_BAD_DESTINATION:
case TRANS_TX_OPEN_CNX_ERR_BREAK_RCVD:
case TRANS_TX_OPEN_CNX_ERR_WRONG_DESTINATION:
case TRANS_TX_OPEN_CNX_ERR_ZONE_VIOLATION:
case TRANS_TX_OPEN_CNX_ERR_STP_RESOURCES_BUSY:
{
ts->stat = SAS_OPEN_REJECT;
break;
}
case TRANS_TX_OPEN_CNX_ERR_OPEN_TIMEOUT:
{
ts->stat = SAS_OPEN_TO;
break;
}
case DMA_RX_DATA_LEN_OVERFLOW:
{
ts->stat = SAS_DATA_OVERRUN;
break;
}
case TRANS_TX_OPEN_FAIL_WITH_IT_NEXUS_LOSS:
case TRANS_TX_ERR_PHY_NOT_ENABLE:
case TRANS_TX_OPEN_CNX_ERR_BY_OTHER:
case TRANS_TX_OPEN_CNX_ERR_AIP_TIMEOUT:
case TRANS_TX_OPEN_RETRY_ERR_THRESHOLD_REACHED:
case TRANS_TX_ERR_WITH_BREAK_TIMEOUT:
case TRANS_TX_ERR_WITH_BREAK_REQUEST:
case TRANS_TX_ERR_WITH_BREAK_RECEVIED:
case TRANS_TX_ERR_WITH_CLOSE_TIMEOUT:
case TRANS_TX_ERR_WITH_CLOSE_NORMAL:
case TRANS_TX_ERR_WITH_CLOSE_DWS_TIMEOUT:
case TRANS_TX_ERR_WITH_CLOSE_COMINIT:
case TRANS_TX_ERR_WITH_NAK_RECEVIED:
case TRANS_TX_ERR_WITH_ACK_NAK_TIMEOUT:
case TRANS_TX_ERR_WITH_CREDIT_TIMEOUT:
case TRANS_TX_ERR_WITH_WAIT_RECV_TIMEOUT:
case TRANS_RX_ERR_WITH_RXFIS_8B10B_DISP_ERR:
case TRANS_RX_ERR_WITH_RXFRAME_HAVE_ERRPRM:
case TRANS_RX_ERR_WITH_RXFIS_DECODE_ERROR:
case TRANS_RX_ERR_WITH_RXFIS_CRC_ERR:
case TRANS_RX_ERR_WITH_RXFRAME_LENGTH_OVERRUN:
case TRANS_RX_ERR_WITH_RXFIS_RX_SYNCP:
case TRANS_RX_ERR_WITH_CLOSE_NORMAL:
case TRANS_RX_ERR_WITH_CLOSE_PHY_DISABLE:
case TRANS_RX_ERR_WITH_CLOSE_DWS_TIMEOUT:
case TRANS_RX_ERR_WITH_CLOSE_COMINIT:
case TRANS_RX_ERR_WITH_DATA_LEN0:
case TRANS_RX_ERR_WITH_BAD_HASH:
case TRANS_RX_XRDY_WLEN_ZERO_ERR:
case TRANS_RX_SSP_FRM_LEN_ERR:
case SIPC_RX_FIS_STATUS_ERR_BIT_VLD:
case SIPC_RX_PIO_WRSETUP_STATUS_DRQ_ERR:
case SIPC_RX_FIS_STATUS_BSY_BIT_ERR:
case SIPC_RX_WRSETUP_LEN_ODD_ERR:
case SIPC_RX_WRSETUP_LEN_ZERO_ERR:
case SIPC_RX_WRDATA_LEN_NOT_MATCH_ERR:
case SIPC_RX_SATA_UNEXP_FIS_ERR:
case DMA_RX_SATA_FRAME_TYPE_ERR:
case DMA_RX_UNEXP_RDFRAME_ERR:
case DMA_RX_PIO_DATA_LEN_ERR:
case DMA_RX_RDSETUP_STATUS_ERR:
case DMA_RX_RDSETUP_STATUS_DRQ_ERR:
case DMA_RX_RDSETUP_STATUS_BSY_ERR:
case DMA_RX_RDSETUP_LEN_ODD_ERR:
case DMA_RX_RDSETUP_LEN_ZERO_ERR:
case DMA_RX_RDSETUP_LEN_OVER_ERR:
case DMA_RX_RDSETUP_OFFSET_ERR:
case DMA_RX_RDSETUP_ACTIVE_ERR:
case DMA_RX_RDSETUP_ESTATUS_ERR:
case DMA_RX_UNKNOWN_FRM_ERR:
{
ts->stat = SAS_OPEN_REJECT;
break;
}
default:
{
ts->stat = SAS_PROTO_RESPONSE;
break;
}
}
sata_done_v2_hw(hisi_hba, task, slot);
}
break;
default:
break;
}
}
static int
slot_complete_v2_hw(struct hisi_hba *hisi_hba, struct hisi_sas_slot *slot,
int abort)
{
struct sas_task *task = slot->task;
struct hisi_sas_device *sas_dev;
struct device *dev = &hisi_hba->pdev->dev;
struct task_status_struct *ts;
struct domain_device *device;
enum exec_status sts;
struct hisi_sas_complete_v2_hdr *complete_queue =
hisi_hba->complete_hdr[slot->cmplt_queue];
struct hisi_sas_complete_v2_hdr *complete_hdr =
&complete_queue[slot->cmplt_queue_slot];
if (unlikely(!task || !task->lldd_task || !task->dev))
return -EINVAL;
ts = &task->task_status;
device = task->dev;
sas_dev = device->lldd_dev;
task->task_state_flags &=
~(SAS_TASK_STATE_PENDING | SAS_TASK_AT_INITIATOR);
task->task_state_flags |= SAS_TASK_STATE_DONE;
memset(ts, 0, sizeof(*ts));
ts->resp = SAS_TASK_COMPLETE;
if (unlikely(!sas_dev || abort)) {
if (!sas_dev)
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
ts->stat = TMF_RESP_FUNC_COMPLETE;
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
if ((complete_hdr->dw0 & CMPLT_HDR_ERX_MSK) &&
(!(complete_hdr->dw0 & CMPLT_HDR_RSPNS_XFRD_MSK))) {
slot_err_v2_hw(hisi_hba, task, slot);
if (unlikely(slot->abort)) {
queue_work(hisi_hba->wq, &slot->abort_slot);
return ts->stat;
}
goto out;
}
switch (task->task_proto) {
case SAS_PROTOCOL_SSP:
{
struct ssp_response_iu *iu = slot->status_buffer +
sizeof(struct hisi_sas_err_record);
sas_ssp_task_response(dev, task, iu);
break;
}
case SAS_PROTOCOL_SMP:
{
struct scatterlist *sg_resp = &task->smp_task.smp_resp;
void *to;
ts->stat = SAM_STAT_GOOD;
to = kmap_atomic(sg_page(sg_resp));
dma_unmap_sg(dev, &task->smp_task.smp_resp, 1,
DMA_FROM_DEVICE);
dma_unmap_sg(dev, &task->smp_task.smp_req, 1,
DMA_TO_DEVICE);
memcpy(to + sg_resp->offset,
slot->status_buffer +
sizeof(struct hisi_sas_err_record),
sg_dma_len(sg_resp));
kunmap_atomic(to);
break;
}
case SAS_PROTOCOL_SATA:
case SAS_PROTOCOL_STP:
case SAS_PROTOCOL_SATA | SAS_PROTOCOL_STP:
{
ts->stat = SAM_STAT_GOOD;
sata_done_v2_hw(hisi_hba, task, slot);
break;
}
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
hisi_sas_slot_task_free(hisi_hba, task, slot);
sts = ts->stat;
if (task->task_done)
task->task_done(task);
return sts;
}
static u8 get_ata_protocol(u8 cmd, int direction)
{
switch (cmd) {
case ATA_CMD_FPDMA_WRITE:
case ATA_CMD_FPDMA_READ:
case ATA_CMD_FPDMA_RECV:
case ATA_CMD_FPDMA_SEND:
case ATA_CMD_NCQ_NON_DATA:
return SATA_PROTOCOL_FPDMA;
case ATA_CMD_DOWNLOAD_MICRO:
case ATA_CMD_ID_ATA:
case ATA_CMD_PMP_READ:
case ATA_CMD_READ_LOG_EXT:
case ATA_CMD_PIO_READ:
case ATA_CMD_PIO_READ_EXT:
case ATA_CMD_PMP_WRITE:
case ATA_CMD_WRITE_LOG_EXT:
case ATA_CMD_PIO_WRITE:
case ATA_CMD_PIO_WRITE_EXT:
return SATA_PROTOCOL_PIO;
case ATA_CMD_DSM:
case ATA_CMD_DOWNLOAD_MICRO_DMA:
case ATA_CMD_PMP_READ_DMA:
case ATA_CMD_PMP_WRITE_DMA:
case ATA_CMD_READ:
case ATA_CMD_READ_EXT:
case ATA_CMD_READ_LOG_DMA_EXT:
case ATA_CMD_READ_STREAM_DMA_EXT:
case ATA_CMD_TRUSTED_RCV_DMA:
case ATA_CMD_TRUSTED_SND_DMA:
case ATA_CMD_WRITE:
case ATA_CMD_WRITE_EXT:
case ATA_CMD_WRITE_FUA_EXT:
case ATA_CMD_WRITE_QUEUED:
case ATA_CMD_WRITE_LOG_DMA_EXT:
case ATA_CMD_WRITE_STREAM_DMA_EXT:
return SATA_PROTOCOL_DMA;
case ATA_CMD_CHK_POWER:
case ATA_CMD_DEV_RESET:
case ATA_CMD_EDD:
case ATA_CMD_FLUSH:
case ATA_CMD_FLUSH_EXT:
case ATA_CMD_VERIFY:
case ATA_CMD_VERIFY_EXT:
case ATA_CMD_SET_FEATURES:
case ATA_CMD_STANDBY:
case ATA_CMD_STANDBYNOW1:
return SATA_PROTOCOL_NONDATA;
default:
if (direction == DMA_NONE)
return SATA_PROTOCOL_NONDATA;
return SATA_PROTOCOL_PIO;
}
}
static int get_ncq_tag_v2_hw(struct sas_task *task, u32 *tag)
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
static int prep_ata_v2_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot)
{
struct sas_task *task = slot->task;
struct domain_device *device = task->dev;
struct domain_device *parent_dev = device->parent;
struct hisi_sas_device *sas_dev = device->lldd_dev;
struct hisi_sas_cmd_hdr *hdr = slot->cmd_hdr;
struct hisi_sas_port *port = device->port->lldd_port;
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
if (0 == task->ata_task.fis.command)
dw1 |= 1 << CMD_HDR_RESET_OFF;
dw1 |= (get_ata_protocol(task->ata_task.fis.command, task->data_dir))
<< CMD_HDR_FRAME_TYPE_OFF;
dw1 |= sas_dev->device_id << CMD_HDR_DEV_ID_OFF;
hdr->dw1 = cpu_to_le32(dw1);
if (task->ata_task.use_ncq && get_ncq_tag_v2_hw(task, &hdr_tag)) {
task->ata_task.fis.sector_count |= (u8) (hdr_tag << 3);
dw2 |= hdr_tag << CMD_HDR_NCQ_TAG_OFF;
}
dw2 |= (HISI_SAS_MAX_STP_RESP_SZ / 4) << CMD_HDR_CFL_OFF |
2 << CMD_HDR_SG_MOD_OFF;
hdr->dw2 = cpu_to_le32(dw2);
hdr->transfer_tags = cpu_to_le32(slot->idx);
if (has_data) {
rc = prep_prd_sge_v2_hw(hisi_hba, slot, hdr, task->scatter,
slot->n_elem);
if (rc)
return rc;
}
hdr->data_transfer_len = cpu_to_le32(task->total_xfer_len);
hdr->cmd_table_addr = cpu_to_le64(slot->command_table_dma);
hdr->sts_buffer_addr = cpu_to_le64(slot->status_buffer_dma);
buf_cmd = slot->command_table;
if (likely(!task->ata_task.device_control_reg_update))
task->ata_task.fis.flags |= 0x80;
memcpy(buf_cmd, &task->ata_task.fis, sizeof(struct host_to_dev_fis));
return 0;
}
static int prep_abort_v2_hw(struct hisi_hba *hisi_hba,
struct hisi_sas_slot *slot,
int device_id, int abort_flag, int tag_to_abort)
{
struct sas_task *task = slot->task;
struct domain_device *dev = task->dev;
struct hisi_sas_cmd_hdr *hdr = slot->cmd_hdr;
struct hisi_sas_port *port = slot->port;
hdr->dw0 = cpu_to_le32((5 << CMD_HDR_CMD_OFF) |
(port->id << CMD_HDR_PORT_OFF) |
((dev_is_sata(dev) ? 1:0) <<
CMD_HDR_ABORT_DEVICE_TYPE_OFF) |
(abort_flag << CMD_HDR_ABORT_FLAG_OFF));
hdr->dw1 = cpu_to_le32(device_id << CMD_HDR_DEV_ID_OFF);
hdr->dw7 = cpu_to_le32(tag_to_abort << CMD_HDR_ABORT_IPTT_OFF);
hdr->transfer_tags = cpu_to_le32(slot->idx);
return 0;
}
static int phy_up_v2_hw(int phy_no, struct hisi_hba *hisi_hba)
{
int i, res = 0;
u32 context, port_id, link_rate, hard_phy_linkrate;
struct hisi_sas_phy *phy = &hisi_hba->phy[phy_no];
struct asd_sas_phy *sas_phy = &phy->sas_phy;
struct device *dev = &hisi_hba->pdev->dev;
u32 *frame_rcvd = (u32 *)sas_phy->frame_rcvd;
struct sas_identify_frame *id = (struct sas_identify_frame *)frame_rcvd;
hisi_sas_phy_write32(hisi_hba, phy_no, PHYCTRL_PHY_ENA_MSK, 1);
context = hisi_sas_read32(hisi_hba, PHY_CONTEXT);
if (context & (1 << phy_no))
goto end;
if (phy_no == 8) {
u32 port_state = hisi_sas_read32(hisi_hba, PORT_STATE);
port_id = (port_state & PORT_STATE_PHY8_PORT_NUM_MSK) >>
PORT_STATE_PHY8_PORT_NUM_OFF;
link_rate = (port_state & PORT_STATE_PHY8_CONN_RATE_MSK) >>
PORT_STATE_PHY8_CONN_RATE_OFF;
} else {
port_id = hisi_sas_read32(hisi_hba, PHY_PORT_NUM_MA);
port_id = (port_id >> (4 * phy_no)) & 0xf;
link_rate = hisi_sas_read32(hisi_hba, PHY_CONN_RATE);
link_rate = (link_rate >> (phy_no * 4)) & 0xf;
}
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
sas_phy->linkrate = link_rate;
hard_phy_linkrate = hisi_sas_phy_read32(hisi_hba, phy_no,
HARD_PHY_LINKRATE);
phy->maximum_linkrate = hard_phy_linkrate & 0xf;
phy->minimum_linkrate = (hard_phy_linkrate >> 4) & 0xf;
sas_phy->oob_mode = SAS_OOB_MODE;
memcpy(sas_phy->attached_sas_addr, &id->sas_addr, SAS_ADDR_SIZE);
dev_info(dev, "phyup: phy%d link_rate=%d\n", phy_no, link_rate);
phy->port_id = port_id;
phy->phy_type &= ~(PORT_TYPE_SAS | PORT_TYPE_SATA);
phy->phy_type |= PORT_TYPE_SAS;
phy->phy_attached = 1;
phy->identify.device_type = id->dev_type;
phy->frame_rcvd_size = sizeof(struct sas_identify_frame);
if (phy->identify.device_type == SAS_END_DEVICE)
phy->identify.target_port_protocols =
SAS_PROTOCOL_SSP;
else if (phy->identify.device_type != SAS_PHY_UNUSED) {
phy->identify.target_port_protocols =
SAS_PROTOCOL_SMP;
if (!timer_pending(&hisi_hba->timer))
set_link_timer_quirk(hisi_hba);
}
queue_work(hisi_hba->wq, &phy->phyup_ws);
end:
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0,
CHL_INT0_SL_PHY_ENABLE_MSK);
hisi_sas_phy_write32(hisi_hba, phy_no, PHYCTRL_PHY_ENA_MSK, 0);
return res;
}
static bool check_any_wideports_v2_hw(struct hisi_hba *hisi_hba)
{
u32 port_state;
port_state = hisi_sas_read32(hisi_hba, PORT_STATE);
if (port_state & 0x1ff)
return true;
return false;
}
static int phy_down_v2_hw(int phy_no, struct hisi_hba *hisi_hba)
{
int res = 0;
u32 phy_state, sl_ctrl, txid_auto;
struct hisi_sas_phy *phy = &hisi_hba->phy[phy_no];
struct hisi_sas_port *port = phy->port;
hisi_sas_phy_write32(hisi_hba, phy_no, PHYCTRL_NOT_RDY_MSK, 1);
phy_state = hisi_sas_read32(hisi_hba, PHY_STATE);
hisi_sas_phy_down(hisi_hba, phy_no, (phy_state & 1 << phy_no) ? 1 : 0);
sl_ctrl = hisi_sas_phy_read32(hisi_hba, phy_no, SL_CONTROL);
hisi_sas_phy_write32(hisi_hba, phy_no, SL_CONTROL,
sl_ctrl & ~SL_CONTROL_CTA_MSK);
if (port && !get_wideport_bitmap_v2_hw(hisi_hba, port->id))
if (!check_any_wideports_v2_hw(hisi_hba) &&
timer_pending(&hisi_hba->timer))
del_timer(&hisi_hba->timer);
txid_auto = hisi_sas_phy_read32(hisi_hba, phy_no, TXID_AUTO);
hisi_sas_phy_write32(hisi_hba, phy_no, TXID_AUTO,
txid_auto | TXID_AUTO_CT3_MSK);
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0, CHL_INT0_NOT_RDY_MSK);
hisi_sas_phy_write32(hisi_hba, phy_no, PHYCTRL_NOT_RDY_MSK, 0);
return res;
}
static irqreturn_t int_phy_updown_v2_hw(int irq_no, void *p)
{
struct hisi_hba *hisi_hba = p;
u32 irq_msk;
int phy_no = 0;
irqreturn_t res = IRQ_HANDLED;
irq_msk = (hisi_sas_read32(hisi_hba, HGC_INVLD_DQE_INFO)
>> HGC_INVLD_DQE_INFO_FB_CH0_OFF) & 0x1ff;
while (irq_msk) {
if (irq_msk & 1) {
u32 irq_value = hisi_sas_phy_read32(hisi_hba, phy_no,
CHL_INT0);
if (irq_value & CHL_INT0_SL_PHY_ENABLE_MSK)
if (phy_up_v2_hw(phy_no, hisi_hba)) {
res = IRQ_NONE;
goto end;
}
if (irq_value & CHL_INT0_NOT_RDY_MSK)
if (phy_down_v2_hw(phy_no, hisi_hba)) {
res = IRQ_NONE;
goto end;
}
}
irq_msk >>= 1;
phy_no++;
}
end:
return res;
}
static void phy_bcast_v2_hw(int phy_no, struct hisi_hba *hisi_hba)
{
struct hisi_sas_phy *phy = &hisi_hba->phy[phy_no];
struct asd_sas_phy *sas_phy = &phy->sas_phy;
struct sas_ha_struct *sas_ha = &hisi_hba->sha;
u32 bcast_status;
hisi_sas_phy_write32(hisi_hba, phy_no, SL_RX_BCAST_CHK_MSK, 1);
bcast_status = hisi_sas_phy_read32(hisi_hba, phy_no, RX_PRIMS_STATUS);
if (bcast_status & RX_BCAST_CHG_MSK)
sas_ha->notify_port_event(sas_phy, PORTE_BROADCAST_RCVD);
hisi_sas_phy_write32(hisi_hba, phy_no, CHL_INT0,
CHL_INT0_SL_RX_BCST_ACK_MSK);
hisi_sas_phy_write32(hisi_hba, phy_no, SL_RX_BCAST_CHK_MSK, 0);
}
static irqreturn_t int_chnl_int_v2_hw(int irq_no, void *p)
{
struct hisi_hba *hisi_hba = p;
struct device *dev = &hisi_hba->pdev->dev;
u32 ent_msk, ent_tmp, irq_msk;
int phy_no = 0;
ent_msk = hisi_sas_read32(hisi_hba, ENT_INT_SRC_MSK3);
ent_tmp = ent_msk;
ent_msk |= ENT_INT_SRC_MSK3_ENT95_MSK_MSK;
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK3, ent_msk);
irq_msk = (hisi_sas_read32(hisi_hba, HGC_INVLD_DQE_INFO) >>
HGC_INVLD_DQE_INFO_FB_CH3_OFF) & 0x1ff;
while (irq_msk) {
if (irq_msk & (1 << phy_no)) {
u32 irq_value0 = hisi_sas_phy_read32(hisi_hba, phy_no,
CHL_INT0);
u32 irq_value1 = hisi_sas_phy_read32(hisi_hba, phy_no,
CHL_INT1);
u32 irq_value2 = hisi_sas_phy_read32(hisi_hba, phy_no,
CHL_INT2);
if (irq_value1) {
if (irq_value1 & (CHL_INT1_DMAC_RX_ECC_ERR_MSK |
CHL_INT1_DMAC_TX_ECC_ERR_MSK))
panic("%s: DMAC RX/TX ecc bad error!\
(0x%x)",
dev_name(dev), irq_value1);
hisi_sas_phy_write32(hisi_hba, phy_no,
CHL_INT1, irq_value1);
}
if (irq_value2)
hisi_sas_phy_write32(hisi_hba, phy_no,
CHL_INT2, irq_value2);
if (irq_value0) {
if (irq_value0 & CHL_INT0_SL_RX_BCST_ACK_MSK)
phy_bcast_v2_hw(phy_no, hisi_hba);
hisi_sas_phy_write32(hisi_hba, phy_no,
CHL_INT0, irq_value0
& (~CHL_INT0_HOTPLUG_TOUT_MSK)
& (~CHL_INT0_SL_PHY_ENABLE_MSK)
& (~CHL_INT0_NOT_RDY_MSK));
}
}
irq_msk &= ~(1 << phy_no);
phy_no++;
}
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK3, ent_tmp);
return IRQ_HANDLED;
}
static void
one_bit_ecc_error_process_v2_hw(struct hisi_hba *hisi_hba, u32 irq_value)
{
struct device *dev = &hisi_hba->pdev->dev;
u32 reg_val;
if (irq_value & BIT(SAS_ECC_INTR_DQE_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_DQE_ECC_ADDR);
dev_warn(dev, "hgc_dqe_acc1b_intr found: \
Ram address is 0x%08X\n",
(reg_val & HGC_DQE_ECC_1B_ADDR_MSK) >>
HGC_DQE_ECC_1B_ADDR_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_IOST_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_IOST_ECC_ADDR);
dev_warn(dev, "hgc_iost_acc1b_intr found: \
Ram address is 0x%08X\n",
(reg_val & HGC_IOST_ECC_1B_ADDR_MSK) >>
HGC_IOST_ECC_1B_ADDR_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_ITCT_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_ITCT_ECC_ADDR);
dev_warn(dev, "hgc_itct_acc1b_intr found: \
Ram address is 0x%08X\n",
(reg_val & HGC_ITCT_ECC_1B_ADDR_MSK) >>
HGC_ITCT_ECC_1B_ADDR_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_IOSTLIST_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_LM_DFX_STATUS2);
dev_warn(dev, "hgc_iostl_acc1b_intr found: \
memory address is 0x%08X\n",
(reg_val & HGC_LM_DFX_STATUS2_IOSTLIST_MSK) >>
HGC_LM_DFX_STATUS2_IOSTLIST_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_ITCTLIST_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_LM_DFX_STATUS2);
dev_warn(dev, "hgc_itctl_acc1b_intr found: \
memory address is 0x%08X\n",
(reg_val & HGC_LM_DFX_STATUS2_ITCTLIST_MSK) >>
HGC_LM_DFX_STATUS2_ITCTLIST_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_CQE_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_CQE_ECC_ADDR);
dev_warn(dev, "hgc_cqe_acc1b_intr found: \
Ram address is 0x%08X\n",
(reg_val & HGC_CQE_ECC_1B_ADDR_MSK) >>
HGC_CQE_ECC_1B_ADDR_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_NCQ_MEM0_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_RXM_DFX_STATUS14);
dev_warn(dev, "rxm_mem0_acc1b_intr found: \
memory address is 0x%08X\n",
(reg_val & HGC_RXM_DFX_STATUS14_MEM0_MSK) >>
HGC_RXM_DFX_STATUS14_MEM0_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_NCQ_MEM1_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_RXM_DFX_STATUS14);
dev_warn(dev, "rxm_mem1_acc1b_intr found: \
memory address is 0x%08X\n",
(reg_val & HGC_RXM_DFX_STATUS14_MEM1_MSK) >>
HGC_RXM_DFX_STATUS14_MEM1_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_NCQ_MEM2_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_RXM_DFX_STATUS14);
dev_warn(dev, "rxm_mem2_acc1b_intr found: \
memory address is 0x%08X\n",
(reg_val & HGC_RXM_DFX_STATUS14_MEM2_MSK) >>
HGC_RXM_DFX_STATUS14_MEM2_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_NCQ_MEM3_ECC_1B_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_RXM_DFX_STATUS15);
dev_warn(dev, "rxm_mem3_acc1b_intr found: \
memory address is 0x%08X\n",
(reg_val & HGC_RXM_DFX_STATUS15_MEM3_MSK) >>
HGC_RXM_DFX_STATUS15_MEM3_OFF);
}
}
static void multi_bit_ecc_error_process_v2_hw(struct hisi_hba *hisi_hba,
u32 irq_value)
{
u32 reg_val;
struct device *dev = &hisi_hba->pdev->dev;
if (irq_value & BIT(SAS_ECC_INTR_DQE_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_DQE_ECC_ADDR);
panic("%s: hgc_dqe_accbad_intr (0x%x) found: \
Ram address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_DQE_ECC_MB_ADDR_MSK) >>
HGC_DQE_ECC_MB_ADDR_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_IOST_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_IOST_ECC_ADDR);
panic("%s: hgc_iost_accbad_intr (0x%x) found: \
Ram address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_IOST_ECC_MB_ADDR_MSK) >>
HGC_IOST_ECC_MB_ADDR_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_ITCT_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_ITCT_ECC_ADDR);
panic("%s: hgc_itct_accbad_intr (0x%x) found: \
Ram address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_ITCT_ECC_MB_ADDR_MSK) >>
HGC_ITCT_ECC_MB_ADDR_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_IOSTLIST_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_LM_DFX_STATUS2);
panic("%s: hgc_iostl_accbad_intr (0x%x) found: \
memory address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_LM_DFX_STATUS2_IOSTLIST_MSK) >>
HGC_LM_DFX_STATUS2_IOSTLIST_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_ITCTLIST_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_LM_DFX_STATUS2);
panic("%s: hgc_itctl_accbad_intr (0x%x) found: \
memory address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_LM_DFX_STATUS2_ITCTLIST_MSK) >>
HGC_LM_DFX_STATUS2_ITCTLIST_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_CQE_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_CQE_ECC_ADDR);
panic("%s: hgc_cqe_accbad_intr (0x%x) found: \
Ram address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_CQE_ECC_MB_ADDR_MSK) >>
HGC_CQE_ECC_MB_ADDR_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_NCQ_MEM0_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_RXM_DFX_STATUS14);
panic("%s: rxm_mem0_accbad_intr (0x%x) found: \
memory address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_RXM_DFX_STATUS14_MEM0_MSK) >>
HGC_RXM_DFX_STATUS14_MEM0_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_NCQ_MEM1_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_RXM_DFX_STATUS14);
panic("%s: rxm_mem1_accbad_intr (0x%x) found: \
memory address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_RXM_DFX_STATUS14_MEM1_MSK) >>
HGC_RXM_DFX_STATUS14_MEM1_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_NCQ_MEM2_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_RXM_DFX_STATUS14);
panic("%s: rxm_mem2_accbad_intr (0x%x) found: \
memory address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_RXM_DFX_STATUS14_MEM2_MSK) >>
HGC_RXM_DFX_STATUS14_MEM2_OFF);
}
if (irq_value & BIT(SAS_ECC_INTR_NCQ_MEM3_ECC_MB_OFF)) {
reg_val = hisi_sas_read32(hisi_hba, HGC_RXM_DFX_STATUS15);
panic("%s: rxm_mem3_accbad_intr (0x%x) found: \
memory address is 0x%08X\n",
dev_name(dev), irq_value,
(reg_val & HGC_RXM_DFX_STATUS15_MEM3_MSK) >>
HGC_RXM_DFX_STATUS15_MEM3_OFF);
}
}
static irqreturn_t fatal_ecc_int_v2_hw(int irq_no, void *p)
{
struct hisi_hba *hisi_hba = p;
u32 irq_value, irq_msk;
irq_msk = hisi_sas_read32(hisi_hba, SAS_ECC_INTR_MSK);
hisi_sas_write32(hisi_hba, SAS_ECC_INTR_MSK, irq_msk | 0xffffffff);
irq_value = hisi_sas_read32(hisi_hba, SAS_ECC_INTR);
if (irq_value) {
one_bit_ecc_error_process_v2_hw(hisi_hba, irq_value);
multi_bit_ecc_error_process_v2_hw(hisi_hba, irq_value);
}
hisi_sas_write32(hisi_hba, SAS_ECC_INTR, irq_value);
hisi_sas_write32(hisi_hba, SAS_ECC_INTR_MSK, irq_msk);
return IRQ_HANDLED;
}
static irqreturn_t fatal_axi_int_v2_hw(int irq_no, void *p)
{
struct hisi_hba *hisi_hba = p;
u32 irq_value, irq_msk, err_value;
struct device *dev = &hisi_hba->pdev->dev;
irq_msk = hisi_sas_read32(hisi_hba, ENT_INT_SRC_MSK3);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK3, irq_msk | 0xfffffffe);
irq_value = hisi_sas_read32(hisi_hba, ENT_INT_SRC3);
if (irq_value) {
if (irq_value & BIT(ENT_INT_SRC3_WP_DEPTH_OFF)) {
hisi_sas_write32(hisi_hba, ENT_INT_SRC3,
1 << ENT_INT_SRC3_WP_DEPTH_OFF);
panic("%s: write pointer and depth error (0x%x) \
found!\n",
dev_name(dev), irq_value);
}
if (irq_value & BIT(ENT_INT_SRC3_IPTT_SLOT_NOMATCH_OFF)) {
hisi_sas_write32(hisi_hba, ENT_INT_SRC3,
1 <<
ENT_INT_SRC3_IPTT_SLOT_NOMATCH_OFF);
panic("%s: iptt no match slot error (0x%x) found!\n",
dev_name(dev), irq_value);
}
if (irq_value & BIT(ENT_INT_SRC3_RP_DEPTH_OFF))
panic("%s: read pointer and depth error (0x%x) \
found!\n",
dev_name(dev), irq_value);
if (irq_value & BIT(ENT_INT_SRC3_AXI_OFF)) {
int i;
hisi_sas_write32(hisi_hba, ENT_INT_SRC3,
1 << ENT_INT_SRC3_AXI_OFF);
err_value = hisi_sas_read32(hisi_hba,
HGC_AXI_FIFO_ERR_INFO);
for (i = 0; i < AXI_ERR_NR; i++) {
if (err_value & BIT(i))
panic("%s: %s (0x%x) found!\n",
dev_name(dev),
axi_err_info[i], irq_value);
}
}
if (irq_value & BIT(ENT_INT_SRC3_FIFO_OFF)) {
int i;
hisi_sas_write32(hisi_hba, ENT_INT_SRC3,
1 << ENT_INT_SRC3_FIFO_OFF);
err_value = hisi_sas_read32(hisi_hba,
HGC_AXI_FIFO_ERR_INFO);
for (i = 0; i < FIFO_ERR_NR; i++) {
if (err_value & BIT(AXI_ERR_NR + i))
panic("%s: %s (0x%x) found!\n",
dev_name(dev),
fifo_err_info[i], irq_value);
}
}
if (irq_value & BIT(ENT_INT_SRC3_LM_OFF)) {
hisi_sas_write32(hisi_hba, ENT_INT_SRC3,
1 << ENT_INT_SRC3_LM_OFF);
panic("%s: LM add/fetch list error (0x%x) found!\n",
dev_name(dev), irq_value);
}
if (irq_value & BIT(ENT_INT_SRC3_ABT_OFF)) {
hisi_sas_write32(hisi_hba, ENT_INT_SRC3,
1 << ENT_INT_SRC3_ABT_OFF);
panic("%s: SAS_HGC_ABT fetch LM list error (0x%x) found!\n",
dev_name(dev), irq_value);
}
}
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK3, irq_msk);
return IRQ_HANDLED;
}
static void cq_tasklet_v2_hw(unsigned long val)
{
struct hisi_sas_cq *cq = (struct hisi_sas_cq *)val;
struct hisi_hba *hisi_hba = cq->hisi_hba;
struct hisi_sas_slot *slot;
struct hisi_sas_itct *itct;
struct hisi_sas_complete_v2_hdr *complete_queue;
u32 rd_point = cq->rd_point, wr_point, dev_id;
int queue = cq->id;
complete_queue = hisi_hba->complete_hdr[queue];
spin_lock(&hisi_hba->lock);
wr_point = hisi_sas_read32(hisi_hba, COMPL_Q_0_WR_PTR +
(0x14 * queue));
while (rd_point != wr_point) {
struct hisi_sas_complete_v2_hdr *complete_hdr;
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
slot_complete_v2_hw(hisi_hba, slot, 0);
act_tmp &= ~(1 << ncq_tag_count);
ncq_tag_count = ffs(act_tmp);
}
} else {
iptt = (complete_hdr->dw1) & CMPLT_HDR_IPTT_MSK;
slot = &hisi_hba->slot_info[iptt];
slot->cmplt_queue_slot = rd_point;
slot->cmplt_queue = queue;
slot_complete_v2_hw(hisi_hba, slot, 0);
}
if (++rd_point >= HISI_SAS_QUEUE_SLOTS)
rd_point = 0;
}
cq->rd_point = rd_point;
hisi_sas_write32(hisi_hba, COMPL_Q_0_RD_PTR + (0x14 * queue), rd_point);
spin_unlock(&hisi_hba->lock);
}
static irqreturn_t cq_interrupt_v2_hw(int irq_no, void *p)
{
struct hisi_sas_cq *cq = p;
struct hisi_hba *hisi_hba = cq->hisi_hba;
int queue = cq->id;
hisi_sas_write32(hisi_hba, OQ_INT_SRC, 1 << queue);
tasklet_schedule(&cq->tasklet);
return IRQ_HANDLED;
}
static irqreturn_t sata_int_v2_hw(int irq_no, void *p)
{
struct hisi_sas_phy *phy = p;
struct hisi_hba *hisi_hba = phy->hisi_hba;
struct asd_sas_phy *sas_phy = &phy->sas_phy;
struct device *dev = &hisi_hba->pdev->dev;
struct hisi_sas_initial_fis *initial_fis;
struct dev_to_host_fis *fis;
u32 ent_tmp, ent_msk, ent_int, port_id, link_rate, hard_phy_linkrate;
irqreturn_t res = IRQ_HANDLED;
u8 attached_sas_addr[SAS_ADDR_SIZE] = {0};
int phy_no, offset;
phy_no = sas_phy->id;
initial_fis = &hisi_hba->initial_fis[phy_no];
fis = &initial_fis->fis;
offset = 4 * (phy_no / 4);
ent_msk = hisi_sas_read32(hisi_hba, ENT_INT_SRC_MSK1 + offset);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK1 + offset,
ent_msk | 1 << ((phy_no % 4) * 8));
ent_int = hisi_sas_read32(hisi_hba, ENT_INT_SRC1 + offset);
ent_tmp = ent_int & (1 << (ENT_INT_SRC1_D2H_FIS_CH1_OFF *
(phy_no % 4)));
ent_int >>= ENT_INT_SRC1_D2H_FIS_CH1_OFF * (phy_no % 4);
if ((ent_int & ENT_INT_SRC1_D2H_FIS_CH0_MSK) == 0) {
dev_warn(dev, "sata int: phy%d did not receive FIS\n", phy_no);
res = IRQ_NONE;
goto end;
}
if (fis->status & ATA_ERR) {
dev_warn(dev, "sata int: phy%d FIS status: 0x%x\n", phy_no,
fis->status);
disable_phy_v2_hw(hisi_hba, phy_no);
enable_phy_v2_hw(hisi_hba, phy_no);
res = IRQ_NONE;
goto end;
}
if (unlikely(phy_no == 8)) {
u32 port_state = hisi_sas_read32(hisi_hba, PORT_STATE);
port_id = (port_state & PORT_STATE_PHY8_PORT_NUM_MSK) >>
PORT_STATE_PHY8_PORT_NUM_OFF;
link_rate = (port_state & PORT_STATE_PHY8_CONN_RATE_MSK) >>
PORT_STATE_PHY8_CONN_RATE_OFF;
} else {
port_id = hisi_sas_read32(hisi_hba, PHY_PORT_NUM_MA);
port_id = (port_id >> (4 * phy_no)) & 0xf;
link_rate = hisi_sas_read32(hisi_hba, PHY_CONN_RATE);
link_rate = (link_rate >> (phy_no * 4)) & 0xf;
}
if (port_id == 0xf) {
dev_err(dev, "sata int: phy%d invalid portid\n", phy_no);
res = IRQ_NONE;
goto end;
}
sas_phy->linkrate = link_rate;
hard_phy_linkrate = hisi_sas_phy_read32(hisi_hba, phy_no,
HARD_PHY_LINKRATE);
phy->maximum_linkrate = hard_phy_linkrate & 0xf;
phy->minimum_linkrate = (hard_phy_linkrate >> 4) & 0xf;
sas_phy->oob_mode = SATA_OOB_MODE;
attached_sas_addr[0] = 0x50;
attached_sas_addr[7] = phy_no;
memcpy(sas_phy->attached_sas_addr, attached_sas_addr, SAS_ADDR_SIZE);
memcpy(sas_phy->frame_rcvd, fis, sizeof(struct dev_to_host_fis));
dev_info(dev, "sata int phyup: phy%d link_rate=%d\n", phy_no, link_rate);
phy->phy_type &= ~(PORT_TYPE_SAS | PORT_TYPE_SATA);
phy->port_id = port_id;
phy->phy_type |= PORT_TYPE_SATA;
phy->phy_attached = 1;
phy->identify.device_type = SAS_SATA_DEV;
phy->frame_rcvd_size = sizeof(struct dev_to_host_fis);
phy->identify.target_port_protocols = SAS_PROTOCOL_SATA;
queue_work(hisi_hba->wq, &phy->phyup_ws);
end:
hisi_sas_write32(hisi_hba, ENT_INT_SRC1 + offset, ent_tmp);
hisi_sas_write32(hisi_hba, ENT_INT_SRC_MSK1 + offset, ent_msk);
return res;
}
static int interrupt_init_v2_hw(struct hisi_hba *hisi_hba)
{
struct platform_device *pdev = hisi_hba->pdev;
struct device *dev = &pdev->dev;
int i, irq, rc, irq_map[128];
for (i = 0; i < 128; i++)
irq_map[i] = platform_get_irq(pdev, i);
for (i = 0; i < HISI_SAS_PHY_INT_NR; i++) {
int idx = i;
irq = irq_map[idx + 1];
if (!irq) {
dev_err(dev, "irq init: fail map phy interrupt %d\n",
idx);
return -ENOENT;
}
rc = devm_request_irq(dev, irq, phy_interrupts[i], 0,
DRV_NAME " phy", hisi_hba);
if (rc) {
dev_err(dev, "irq init: could not request "
"phy interrupt %d, rc=%d\n",
irq, rc);
return -ENOENT;
}
}
for (i = 0; i < hisi_hba->n_phy; i++) {
struct hisi_sas_phy *phy = &hisi_hba->phy[i];
int idx = i + 72;
irq = irq_map[idx];
if (!irq) {
dev_err(dev, "irq init: fail map phy interrupt %d\n",
idx);
return -ENOENT;
}
rc = devm_request_irq(dev, irq, sata_int_v2_hw, 0,
DRV_NAME " sata", phy);
if (rc) {
dev_err(dev, "irq init: could not request "
"sata interrupt %d, rc=%d\n",
irq, rc);
return -ENOENT;
}
}
for (i = 0; i < HISI_SAS_FATAL_INT_NR; i++) {
int idx = i;
irq = irq_map[idx + 81];
if (!irq) {
dev_err(dev, "irq init: fail map fatal interrupt %d\n",
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
for (i = 0; i < hisi_hba->queue_count; i++) {
int idx = i + 96;
struct hisi_sas_cq *cq = &hisi_hba->cq[i];
struct tasklet_struct *t = &cq->tasklet;
irq = irq_map[idx];
if (!irq) {
dev_err(dev,
"irq init: could not map cq interrupt %d\n",
idx);
return -ENOENT;
}
rc = devm_request_irq(dev, irq, cq_interrupt_v2_hw, 0,
DRV_NAME " cq", &hisi_hba->cq[i]);
if (rc) {
dev_err(dev,
"irq init: could not request cq interrupt %d, rc=%d\n",
irq, rc);
return -ENOENT;
}
tasklet_init(t, cq_tasklet_v2_hw, (unsigned long)cq);
}
return 0;
}
static int hisi_sas_v2_init(struct hisi_hba *hisi_hba)
{
int rc;
rc = hw_init_v2_hw(hisi_hba);
if (rc)
return rc;
rc = interrupt_init_v2_hw(hisi_hba);
if (rc)
return rc;
phys_init_v2_hw(hisi_hba);
return 0;
}
static int hisi_sas_v2_probe(struct platform_device *pdev)
{
int ret = platform_get_irq(pdev, 0);
if (ret < 0) {
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "cannot obtain irq\n");
return ret;
}
return hisi_sas_probe(pdev, &hisi_sas_v2_hw);
}
static int hisi_sas_v2_remove(struct platform_device *pdev)
{
struct sas_ha_struct *sha = platform_get_drvdata(pdev);
struct hisi_hba *hisi_hba = sha->lldd_ha;
if (timer_pending(&hisi_hba->timer))
del_timer(&hisi_hba->timer);
return hisi_sas_remove(pdev);
}
