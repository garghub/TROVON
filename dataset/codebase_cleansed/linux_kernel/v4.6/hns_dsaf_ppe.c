void hns_ppe_set_tso_enable(struct hns_ppe_cb *ppe_cb, u32 value)
{
dsaf_set_dev_bit(ppe_cb, PPEV2_CFG_TSO_EN_REG, 0, !!value);
}
void hns_ppe_set_rss_key(struct hns_ppe_cb *ppe_cb,
const u32 rss_key[HNS_PPEV2_RSS_KEY_NUM])
{
u32 key_item;
for (key_item = 0; key_item < HNS_PPEV2_RSS_KEY_NUM; key_item++)
dsaf_write_dev(ppe_cb, PPEV2_RSS_KEY_REG + key_item * 0x4,
rss_key[key_item]);
}
void hns_ppe_set_indir_table(struct hns_ppe_cb *ppe_cb,
const u32 rss_tab[HNS_PPEV2_RSS_IND_TBL_SIZE])
{
int i;
int reg_value;
for (i = 0; i < (HNS_PPEV2_RSS_IND_TBL_SIZE / 4); i++) {
reg_value = dsaf_read_dev(ppe_cb,
PPEV2_INDRECTION_TBL_REG + i * 0x4);
dsaf_set_field(reg_value, PPEV2_CFG_RSS_TBL_4N0_M,
PPEV2_CFG_RSS_TBL_4N0_S,
rss_tab[i * 4 + 0] & 0x1F);
dsaf_set_field(reg_value, PPEV2_CFG_RSS_TBL_4N1_M,
PPEV2_CFG_RSS_TBL_4N1_S,
rss_tab[i * 4 + 1] & 0x1F);
dsaf_set_field(reg_value, PPEV2_CFG_RSS_TBL_4N2_M,
PPEV2_CFG_RSS_TBL_4N2_S,
rss_tab[i * 4 + 2] & 0x1F);
dsaf_set_field(reg_value, PPEV2_CFG_RSS_TBL_4N3_M,
PPEV2_CFG_RSS_TBL_4N3_S,
rss_tab[i * 4 + 3] & 0x1F);
dsaf_write_dev(
ppe_cb, PPEV2_INDRECTION_TBL_REG + i * 0x4, reg_value);
}
}
static void __iomem *hns_ppe_common_get_ioaddr(
struct ppe_common_cb *ppe_common)
{
void __iomem *base_addr;
int idx = ppe_common->comm_index;
if (idx == HNS_DSAF_COMM_SERVICE_NW_IDX)
base_addr = ppe_common->dsaf_dev->ppe_base
+ PPE_COMMON_REG_OFFSET;
else
base_addr = ppe_common->dsaf_dev->sds_base
+ (idx - 1) * HNS_DSAF_DEBUG_NW_REG_OFFSET
+ PPE_COMMON_REG_OFFSET;
return base_addr;
}
int hns_ppe_common_get_cfg(struct dsaf_device *dsaf_dev, int comm_index)
{
struct ppe_common_cb *ppe_common;
int ppe_num;
if (comm_index == HNS_DSAF_COMM_SERVICE_NW_IDX)
ppe_num = HNS_PPE_SERVICE_NW_ENGINE_NUM;
else
ppe_num = HNS_PPE_DEBUG_NW_ENGINE_NUM;
ppe_common = devm_kzalloc(dsaf_dev->dev, sizeof(*ppe_common) +
ppe_num * sizeof(struct hns_ppe_cb), GFP_KERNEL);
if (!ppe_common)
return -ENOMEM;
ppe_common->ppe_num = ppe_num;
ppe_common->dsaf_dev = dsaf_dev;
ppe_common->comm_index = comm_index;
if (comm_index == HNS_DSAF_COMM_SERVICE_NW_IDX)
ppe_common->ppe_mode = PPE_COMMON_MODE_SERVICE;
else
ppe_common->ppe_mode = PPE_COMMON_MODE_DEBUG;
ppe_common->dev = dsaf_dev->dev;
ppe_common->io_base = hns_ppe_common_get_ioaddr(ppe_common);
dsaf_dev->ppe_common[comm_index] = ppe_common;
return 0;
}
void hns_ppe_common_free_cfg(struct dsaf_device *dsaf_dev, u32 comm_index)
{
dsaf_dev->ppe_common[comm_index] = NULL;
}
static void __iomem *hns_ppe_get_iobase(struct ppe_common_cb *ppe_common,
int ppe_idx)
{
void __iomem *base_addr;
int common_idx = ppe_common->comm_index;
if (ppe_common->ppe_mode == PPE_COMMON_MODE_SERVICE) {
base_addr = ppe_common->dsaf_dev->ppe_base +
ppe_idx * PPE_REG_OFFSET;
} else {
base_addr = ppe_common->dsaf_dev->sds_base +
(common_idx - 1) * HNS_DSAF_DEBUG_NW_REG_OFFSET;
}
return base_addr;
}
static int hns_ppe_get_port(struct ppe_common_cb *ppe_common, int idx)
{
int port;
if (ppe_common->ppe_mode == PPE_COMMON_MODE_SERVICE)
port = idx;
else
port = HNS_PPE_SERVICE_NW_ENGINE_NUM
+ ppe_common->comm_index - 1;
return port;
}
static void hns_ppe_get_cfg(struct ppe_common_cb *ppe_common)
{
u32 i;
struct hns_ppe_cb *ppe_cb;
u32 ppe_num = ppe_common->ppe_num;
for (i = 0; i < ppe_num; i++) {
ppe_cb = &ppe_common->ppe_cb[i];
ppe_cb->dev = ppe_common->dev;
ppe_cb->next = NULL;
ppe_cb->ppe_common_cb = ppe_common;
ppe_cb->index = i;
ppe_cb->port = hns_ppe_get_port(ppe_common, i);
ppe_cb->io_base = hns_ppe_get_iobase(ppe_common, i);
ppe_cb->virq = 0;
}
}
static void hns_ppe_cnt_clr_ce(struct hns_ppe_cb *ppe_cb)
{
dsaf_set_dev_bit(ppe_cb, PPE_TNL_0_5_CNT_CLR_CE_REG,
PPE_CNT_CLR_CE_B, 1);
}
static void hns_ppe_set_vlan_strip(struct hns_ppe_cb *ppe_cb, int en)
{
dsaf_write_dev(ppe_cb, PPEV2_VLAN_STRIP_EN_REG, en);
}
static void hns_ppe_checksum_hw(struct hns_ppe_cb *ppe_cb, u32 value)
{
dsaf_set_dev_field(ppe_cb, PPE_CFG_PRO_CHECK_EN_REG,
0xfffffff, 0, value);
}
static void hns_ppe_set_qid_mode(struct ppe_common_cb *ppe_common,
enum ppe_qid_mode qid_mdoe)
{
dsaf_set_dev_field(ppe_common, PPE_COM_CFG_QID_MODE_REG,
PPE_CFG_QID_MODE_CF_QID_MODE_M,
PPE_CFG_QID_MODE_CF_QID_MODE_S, qid_mdoe);
}
static void hns_ppe_set_qid(struct ppe_common_cb *ppe_common, u32 qid)
{
u32 qid_mod = dsaf_read_dev(ppe_common, PPE_COM_CFG_QID_MODE_REG);
if (!dsaf_get_field(qid_mod, PPE_CFG_QID_MODE_DEF_QID_M,
PPE_CFG_QID_MODE_DEF_QID_S)) {
dsaf_set_field(qid_mod, PPE_CFG_QID_MODE_DEF_QID_M,
PPE_CFG_QID_MODE_DEF_QID_S, qid);
dsaf_write_dev(ppe_common, PPE_COM_CFG_QID_MODE_REG, qid_mod);
}
}
static void hns_ppe_set_port_mode(struct hns_ppe_cb *ppe_cb,
enum ppe_port_mode mode)
{
dsaf_write_dev(ppe_cb, PPE_CFG_XGE_MODE_REG, mode);
}
static int hns_ppe_common_init_hw(struct ppe_common_cb *ppe_common)
{
enum ppe_qid_mode qid_mode;
enum dsaf_mode dsaf_mode = ppe_common->dsaf_dev->dsaf_mode;
hns_ppe_com_srst(ppe_common, 0);
mdelay(100);
hns_ppe_com_srst(ppe_common, 1);
mdelay(100);
if (ppe_common->ppe_mode == PPE_COMMON_MODE_SERVICE) {
switch (dsaf_mode) {
case DSAF_MODE_ENABLE_FIX:
case DSAF_MODE_DISABLE_FIX:
qid_mode = PPE_QID_MODE0;
hns_ppe_set_qid(ppe_common, 0);
break;
case DSAF_MODE_ENABLE_0VM:
case DSAF_MODE_DISABLE_2PORT_64VM:
qid_mode = PPE_QID_MODE3;
break;
case DSAF_MODE_ENABLE_8VM:
case DSAF_MODE_DISABLE_2PORT_16VM:
qid_mode = PPE_QID_MODE4;
break;
case DSAF_MODE_ENABLE_16VM:
case DSAF_MODE_DISABLE_6PORT_0VM:
qid_mode = PPE_QID_MODE5;
break;
case DSAF_MODE_ENABLE_32VM:
case DSAF_MODE_DISABLE_6PORT_16VM:
qid_mode = PPE_QID_MODE2;
break;
case DSAF_MODE_ENABLE_128VM:
case DSAF_MODE_DISABLE_6PORT_4VM:
qid_mode = PPE_QID_MODE1;
break;
case DSAF_MODE_DISABLE_2PORT_8VM:
qid_mode = PPE_QID_MODE7;
break;
case DSAF_MODE_DISABLE_6PORT_2VM:
qid_mode = PPE_QID_MODE6;
break;
default:
dev_err(ppe_common->dev,
"get ppe queue mode failed! dsaf_mode=%d\n",
dsaf_mode);
return -EINVAL;
}
hns_ppe_set_qid_mode(ppe_common, qid_mode);
}
dsaf_set_dev_bit(ppe_common, PPE_COM_COMMON_CNT_CLR_CE_REG,
PPE_COMMON_CNT_CLR_CE_B, 1);
return 0;
}
static void hns_ppe_exc_irq_en(struct hns_ppe_cb *ppe_cb, int en)
{
u32 clr_vlue = 0xfffffffful;
u32 msk_vlue = en ? 0xfffffffful : 0;
u32 vld_msk = 0;
dsaf_set_bit(vld_msk, 0, 1);
dsaf_set_bit(vld_msk, 1, 1);
dsaf_set_bit(vld_msk, 7, 1);
dsaf_write_dev(ppe_cb, PPE_RINT_REG, clr_vlue);
dsaf_write_dev(ppe_cb, PPE_INTEN_REG, msk_vlue & vld_msk);
}
static void hns_ppe_init_hw(struct hns_ppe_cb *ppe_cb)
{
struct ppe_common_cb *ppe_common_cb = ppe_cb->ppe_common_cb;
u32 port = ppe_cb->port;
struct dsaf_device *dsaf_dev = ppe_common_cb->dsaf_dev;
int i;
netdev_rss_key_fill(ppe_cb->rss_key, HNS_PPEV2_RSS_KEY_SIZE);
hns_ppe_srst_by_port(dsaf_dev, port, 0);
mdelay(10);
hns_ppe_srst_by_port(dsaf_dev, port, 1);
hns_ppe_exc_irq_en(ppe_cb, 0);
if (ppe_common_cb->ppe_mode == PPE_COMMON_MODE_DEBUG)
hns_ppe_set_port_mode(ppe_cb, PPE_MODE_GE);
else
hns_ppe_set_port_mode(ppe_cb, PPE_MODE_XGE);
hns_ppe_checksum_hw(ppe_cb, 0xffffffff);
hns_ppe_cnt_clr_ce(ppe_cb);
if (!AE_IS_VER1(dsaf_dev->dsaf_ver)) {
hns_ppe_set_vlan_strip(ppe_cb, 0);
dsaf_write_dev(ppe_cb, PPE_CFG_MAX_FRAME_LEN_REG,
HNS_PPEV2_MAX_FRAME_LEN);
hns_ppe_set_rss_key(ppe_cb, ppe_cb->rss_key);
for (i = 0; i < HNS_PPEV2_RSS_IND_TBL_SIZE; i++)
ppe_cb->rss_indir_table[i] = i;
hns_ppe_set_indir_table(ppe_cb, ppe_cb->rss_indir_table);
}
}
static void hns_ppe_uninit_hw(struct hns_ppe_cb *ppe_cb)
{
u32 port;
if (ppe_cb->ppe_common_cb) {
port = ppe_cb->index;
hns_ppe_srst_by_port(ppe_cb->ppe_common_cb->dsaf_dev, port, 0);
}
}
void hns_ppe_uninit_ex(struct ppe_common_cb *ppe_common)
{
u32 i;
for (i = 0; i < ppe_common->ppe_num; i++) {
hns_ppe_uninit_hw(&ppe_common->ppe_cb[i]);
memset(&ppe_common->ppe_cb[i], 0, sizeof(struct hns_ppe_cb));
}
}
void hns_ppe_uninit(struct dsaf_device *dsaf_dev)
{
u32 i;
for (i = 0; i < HNS_PPE_COM_NUM; i++) {
if (dsaf_dev->ppe_common[i])
hns_ppe_uninit_ex(dsaf_dev->ppe_common[i]);
hns_rcb_common_free_cfg(dsaf_dev, i);
hns_ppe_common_free_cfg(dsaf_dev, i);
}
}
void hns_ppe_reset_common(struct dsaf_device *dsaf_dev, u8 ppe_common_index)
{
u32 i;
int ret;
struct ppe_common_cb *ppe_common;
ppe_common = dsaf_dev->ppe_common[ppe_common_index];
ret = hns_ppe_common_init_hw(ppe_common);
if (ret)
return;
for (i = 0; i < ppe_common->ppe_num; i++)
hns_ppe_init_hw(&ppe_common->ppe_cb[i]);
ret = hns_rcb_common_init_hw(dsaf_dev->rcb_common[ppe_common_index]);
if (ret)
return;
hns_rcb_common_init_commit_hw(dsaf_dev->rcb_common[ppe_common_index]);
}
void hns_ppe_update_stats(struct hns_ppe_cb *ppe_cb)
{
struct hns_ppe_hw_stats *hw_stats = &ppe_cb->hw_stats;
hw_stats->rx_pkts_from_sw
+= dsaf_read_dev(ppe_cb, PPE_HIS_RX_SW_PKT_CNT_REG);
hw_stats->rx_pkts
+= dsaf_read_dev(ppe_cb, PPE_HIS_RX_WR_BD_OK_PKT_CNT_REG);
hw_stats->rx_drop_no_bd
+= dsaf_read_dev(ppe_cb, PPE_HIS_RX_PKT_NO_BUF_CNT_REG);
hw_stats->rx_alloc_buf_fail
+= dsaf_read_dev(ppe_cb, PPE_HIS_RX_APP_BUF_FAIL_CNT_REG);
hw_stats->rx_alloc_buf_wait
+= dsaf_read_dev(ppe_cb, PPE_HIS_RX_APP_BUF_WAIT_CNT_REG);
hw_stats->rx_drop_no_buf
+= dsaf_read_dev(ppe_cb, PPE_HIS_RX_PKT_DROP_FUL_CNT_REG);
hw_stats->rx_err_fifo_full
+= dsaf_read_dev(ppe_cb, PPE_HIS_RX_PKT_DROP_PRT_CNT_REG);
hw_stats->tx_bd_form_rcb
+= dsaf_read_dev(ppe_cb, PPE_HIS_TX_BD_CNT_REG);
hw_stats->tx_pkts_from_rcb
+= dsaf_read_dev(ppe_cb, PPE_HIS_TX_PKT_CNT_REG);
hw_stats->tx_pkts
+= dsaf_read_dev(ppe_cb, PPE_HIS_TX_PKT_OK_CNT_REG);
hw_stats->tx_err_fifo_empty
+= dsaf_read_dev(ppe_cb, PPE_HIS_TX_PKT_EPT_CNT_REG);
hw_stats->tx_err_checksum
+= dsaf_read_dev(ppe_cb, PPE_HIS_TX_PKT_CS_FAIL_CNT_REG);
}
int hns_ppe_get_sset_count(int stringset)
{
if (stringset == ETH_SS_STATS)
return ETH_PPE_STATIC_NUM;
return 0;
}
int hns_ppe_get_regs_count(void)
{
return ETH_PPE_DUMP_NUM;
}
void hns_ppe_get_strings(struct hns_ppe_cb *ppe_cb, int stringset, u8 *data)
{
char *buff = (char *)data;
int index = ppe_cb->index;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_rx_sw_pkt", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_rx_pkt_ok", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_rx_drop_pkt_no_bd", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_rx_alloc_buf_fail", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_rx_alloc_buf_wait", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_rx_pkt_drop_no_buf", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_rx_pkt_err_fifo_full", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_tx_bd", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_tx_pkt", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_tx_pkt_ok", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_tx_pkt_err_fifo_empty", index);
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "ppe%d_tx_pkt_err_csum_fail", index);
}
void hns_ppe_get_stats(struct hns_ppe_cb *ppe_cb, u64 *data)
{
u64 *regs_buff = data;
struct hns_ppe_hw_stats *hw_stats = &ppe_cb->hw_stats;
regs_buff[0] = hw_stats->rx_pkts_from_sw;
regs_buff[1] = hw_stats->rx_pkts;
regs_buff[2] = hw_stats->rx_drop_no_bd;
regs_buff[3] = hw_stats->rx_alloc_buf_fail;
regs_buff[4] = hw_stats->rx_alloc_buf_wait;
regs_buff[5] = hw_stats->rx_drop_no_buf;
regs_buff[6] = hw_stats->rx_err_fifo_full;
regs_buff[7] = hw_stats->tx_bd_form_rcb;
regs_buff[8] = hw_stats->tx_pkts_from_rcb;
regs_buff[9] = hw_stats->tx_pkts;
regs_buff[10] = hw_stats->tx_err_fifo_empty;
regs_buff[11] = hw_stats->tx_err_checksum;
}
int hns_ppe_init(struct dsaf_device *dsaf_dev)
{
int i, k;
int ret;
for (i = 0; i < HNS_PPE_COM_NUM; i++) {
ret = hns_ppe_common_get_cfg(dsaf_dev, i);
if (ret)
goto get_ppe_cfg_fail;
ret = hns_rcb_common_get_cfg(dsaf_dev, i);
if (ret)
goto get_rcb_cfg_fail;
hns_ppe_get_cfg(dsaf_dev->ppe_common[i]);
hns_rcb_get_cfg(dsaf_dev->rcb_common[i]);
}
for (i = 0; i < HNS_PPE_COM_NUM; i++)
hns_ppe_reset_common(dsaf_dev, i);
return 0;
get_rcb_cfg_fail:
hns_ppe_common_free_cfg(dsaf_dev, i);
get_ppe_cfg_fail:
for (k = i - 1; k >= 0; k--) {
hns_rcb_common_free_cfg(dsaf_dev, k);
hns_ppe_common_free_cfg(dsaf_dev, k);
}
return ret;
}
void hns_ppe_get_regs(struct hns_ppe_cb *ppe_cb, void *data)
{
struct ppe_common_cb *ppe_common = ppe_cb->ppe_common_cb;
u32 *regs = data;
u32 i;
u32 offset;
regs[0] = dsaf_read_dev(ppe_common, PPE_COM_CFG_QID_MODE_REG);
regs[1] = dsaf_read_dev(ppe_common, PPE_COM_INTEN_REG);
regs[2] = dsaf_read_dev(ppe_common, PPE_COM_RINT_REG);
regs[3] = dsaf_read_dev(ppe_common, PPE_COM_INTSTS_REG);
regs[4] = dsaf_read_dev(ppe_common, PPE_COM_COMMON_CNT_CLR_CE_REG);
for (i = 0; i < DSAF_TOTAL_QUEUE_NUM; i++) {
offset = PPE_COM_HIS_RX_PKT_QID_DROP_CNT_REG + 0x4 * i;
regs[5 + i] = dsaf_read_dev(ppe_common, offset);
offset = PPE_COM_HIS_RX_PKT_QID_OK_CNT_REG + 0x4 * i;
regs[5 + i + DSAF_TOTAL_QUEUE_NUM]
= dsaf_read_dev(ppe_common, offset);
offset = PPE_COM_HIS_TX_PKT_QID_ERR_CNT_REG + 0x4 * i;
regs[5 + i + DSAF_TOTAL_QUEUE_NUM * 2]
= dsaf_read_dev(ppe_common, offset);
offset = PPE_COM_HIS_TX_PKT_QID_OK_CNT_REG + 0x4 * i;
regs[5 + i + DSAF_TOTAL_QUEUE_NUM * 3]
= dsaf_read_dev(ppe_common, offset);
}
for (i = 521; i < 524; i++)
regs[i] = 0xeeeeeeee;
regs[525] = dsaf_read_dev(ppe_cb, PPE_CFG_TX_FIFO_THRSLD_REG);
regs[526] = dsaf_read_dev(ppe_cb, PPE_CFG_RX_FIFO_THRSLD_REG);
regs[527] = dsaf_read_dev(ppe_cb, PPE_CFG_RX_FIFO_PAUSE_THRSLD_REG);
regs[528] = dsaf_read_dev(ppe_cb, PPE_CFG_RX_FIFO_SW_BP_THRSLD_REG);
regs[529] = dsaf_read_dev(ppe_cb, PPE_CFG_PAUSE_IDLE_CNT_REG);
regs[530] = dsaf_read_dev(ppe_cb, PPE_CFG_BUS_CTRL_REG);
regs[531] = dsaf_read_dev(ppe_cb, PPE_CFG_TNL_TO_BE_RST_REG);
regs[532] = dsaf_read_dev(ppe_cb, PPE_CURR_TNL_CAN_RST_REG);
regs[533] = dsaf_read_dev(ppe_cb, PPE_CFG_XGE_MODE_REG);
regs[534] = dsaf_read_dev(ppe_cb, PPE_CFG_MAX_FRAME_LEN_REG);
regs[535] = dsaf_read_dev(ppe_cb, PPE_CFG_RX_PKT_MODE_REG);
regs[536] = dsaf_read_dev(ppe_cb, PPE_CFG_RX_VLAN_TAG_REG);
regs[537] = dsaf_read_dev(ppe_cb, PPE_CFG_TAG_GEN_REG);
regs[538] = dsaf_read_dev(ppe_cb, PPE_CFG_PARSE_TAG_REG);
regs[539] = dsaf_read_dev(ppe_cb, PPE_CFG_PRO_CHECK_EN_REG);
regs[540] = dsaf_read_dev(ppe_cb, PPE_INTEN_REG);
regs[541] = dsaf_read_dev(ppe_cb, PPE_RINT_REG);
regs[542] = dsaf_read_dev(ppe_cb, PPE_INTSTS_REG);
regs[543] = dsaf_read_dev(ppe_cb, PPE_CFG_RX_PKT_INT_REG);
regs[544] = dsaf_read_dev(ppe_cb, PPE_CFG_HEAT_DECT_TIME0_REG);
regs[545] = dsaf_read_dev(ppe_cb, PPE_CFG_HEAT_DECT_TIME1_REG);
regs[546] = dsaf_read_dev(ppe_cb, PPE_HIS_RX_SW_PKT_CNT_REG);
regs[547] = dsaf_read_dev(ppe_cb, PPE_HIS_RX_WR_BD_OK_PKT_CNT_REG);
regs[548] = dsaf_read_dev(ppe_cb, PPE_HIS_RX_PKT_NO_BUF_CNT_REG);
regs[549] = dsaf_read_dev(ppe_cb, PPE_HIS_TX_BD_CNT_REG);
regs[550] = dsaf_read_dev(ppe_cb, PPE_HIS_TX_PKT_CNT_REG);
regs[551] = dsaf_read_dev(ppe_cb, PPE_HIS_TX_PKT_OK_CNT_REG);
regs[552] = dsaf_read_dev(ppe_cb, PPE_HIS_TX_PKT_EPT_CNT_REG);
regs[553] = dsaf_read_dev(ppe_cb, PPE_HIS_TX_PKT_CS_FAIL_CNT_REG);
regs[554] = dsaf_read_dev(ppe_cb, PPE_HIS_RX_APP_BUF_FAIL_CNT_REG);
regs[555] = dsaf_read_dev(ppe_cb, PPE_HIS_RX_APP_BUF_WAIT_CNT_REG);
regs[556] = dsaf_read_dev(ppe_cb, PPE_HIS_RX_PKT_DROP_FUL_CNT_REG);
regs[557] = dsaf_read_dev(ppe_cb, PPE_HIS_RX_PKT_DROP_PRT_CNT_REG);
regs[558] = dsaf_read_dev(ppe_cb, PPE_TNL_0_5_CNT_CLR_CE_REG);
regs[559] = dsaf_read_dev(ppe_cb, PPE_CFG_AXI_DBG_REG);
regs[560] = dsaf_read_dev(ppe_cb, PPE_HIS_PRO_ERR_REG);
regs[561] = dsaf_read_dev(ppe_cb, PPE_HIS_TNL_FIFO_ERR_REG);
regs[562] = dsaf_read_dev(ppe_cb, PPE_CURR_CFF_DATA_NUM_REG);
regs[563] = dsaf_read_dev(ppe_cb, PPE_CURR_RX_ST_REG);
regs[564] = dsaf_read_dev(ppe_cb, PPE_CURR_TX_ST_REG);
regs[565] = dsaf_read_dev(ppe_cb, PPE_CURR_RX_FIFO0_REG);
regs[566] = dsaf_read_dev(ppe_cb, PPE_CURR_RX_FIFO1_REG);
regs[567] = dsaf_read_dev(ppe_cb, PPE_CURR_TX_FIFO0_REG);
regs[568] = dsaf_read_dev(ppe_cb, PPE_CURR_TX_FIFO1_REG);
regs[569] = dsaf_read_dev(ppe_cb, PPE_ECO0_REG);
regs[570] = dsaf_read_dev(ppe_cb, PPE_ECO1_REG);
regs[571] = dsaf_read_dev(ppe_cb, PPE_ECO2_REG);
for (i = 572; i < 576; i++)
regs[i] = 0xeeeeeeee;
}
