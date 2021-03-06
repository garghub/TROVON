static int hclge_shaper_para_calc(u32 ir, u8 shaper_level,
u8 *ir_b, u8 *ir_u, u8 *ir_s)
{
const u16 tick_array[HCLGE_SHAPER_LVL_CNT] = {
6 * 256,
6 * 32,
6 * 8,
6 * 256
};
u8 ir_u_calc = 0, ir_s_calc = 0;
u32 ir_calc;
u32 tick;
if (shaper_level >= HCLGE_SHAPER_LVL_CNT)
return -EINVAL;
tick = tick_array[shaper_level];
ir_calc = (1008000 + (tick >> 1) - 1) / tick;
if (ir_calc == ir) {
*ir_b = 126;
*ir_u = 0;
*ir_s = 0;
return 0;
} else if (ir_calc > ir) {
while (ir_calc > ir) {
ir_s_calc++;
ir_calc = 1008000 / (tick * (1 << ir_s_calc));
}
if (ir_calc == ir)
*ir_b = 126;
else
*ir_b = (ir * tick * (1 << ir_s_calc) + 4000) / 8000;
} else {
u32 numerator;
while (ir_calc < ir) {
ir_u_calc++;
numerator = 1008000 * (1 << ir_u_calc);
ir_calc = (numerator + (tick >> 1)) / tick;
}
if (ir_calc == ir) {
*ir_b = 126;
} else {
u32 denominator = (8000 * (1 << --ir_u_calc));
*ir_b = (ir * tick + (denominator >> 1)) / denominator;
}
}
*ir_u = ir_u_calc;
*ir_s = ir_s_calc;
return 0;
}
static int hclge_mac_pause_en_cfg(struct hclge_dev *hdev, bool tx, bool rx)
{
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_CFG_MAC_PAUSE_EN, false);
desc.data[0] = cpu_to_le32((tx ? HCLGE_TX_MAC_PAUSE_EN_MSK : 0) |
(rx ? HCLGE_RX_MAC_PAUSE_EN_MSK : 0));
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_fill_pri_array(struct hclge_dev *hdev, u8 *pri, u8 pri_id)
{
u8 tc;
tc = hdev->tm_info.prio_tc[pri_id];
if (tc >= hdev->tm_info.num_tc)
return -EINVAL;
pri[pri_id >> 1] |= tc << ((pri_id & 1) * 4);
return 0;
}
static int hclge_up_to_tc_map(struct hclge_dev *hdev)
{
struct hclge_desc desc;
u8 *pri = (u8 *)desc.data;
u8 pri_id;
int ret;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_PRI_TO_TC_MAPPING, false);
for (pri_id = 0; pri_id < HNAE3_MAX_USER_PRIO; pri_id++) {
ret = hclge_fill_pri_array(hdev, pri, pri_id);
if (ret)
return ret;
}
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_pg_to_pri_map_cfg(struct hclge_dev *hdev,
u8 pg_id, u8 pri_bit_map)
{
struct hclge_pg_to_pri_link_cmd *map;
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_PG_TO_PRI_LINK, false);
map = (struct hclge_pg_to_pri_link_cmd *)desc.data;
map->pg_id = pg_id;
map->pri_bit_map = pri_bit_map;
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_qs_to_pri_map_cfg(struct hclge_dev *hdev,
u16 qs_id, u8 pri)
{
struct hclge_qs_to_pri_link_cmd *map;
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_QS_TO_PRI_LINK, false);
map = (struct hclge_qs_to_pri_link_cmd *)desc.data;
map->qs_id = cpu_to_le16(qs_id);
map->priority = pri;
map->link_vld = HCLGE_TM_QS_PRI_LINK_VLD_MSK;
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_q_to_qs_map_cfg(struct hclge_dev *hdev,
u8 q_id, u16 qs_id)
{
struct hclge_nq_to_qs_link_cmd *map;
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_NQ_TO_QS_LINK, false);
map = (struct hclge_nq_to_qs_link_cmd *)desc.data;
map->nq_id = cpu_to_le16(q_id);
map->qset_id = cpu_to_le16(qs_id | HCLGE_TM_Q_QS_LINK_VLD_MSK);
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_pg_weight_cfg(struct hclge_dev *hdev, u8 pg_id,
u8 dwrr)
{
struct hclge_pg_weight_cmd *weight;
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_PG_WEIGHT, false);
weight = (struct hclge_pg_weight_cmd *)desc.data;
weight->pg_id = pg_id;
weight->dwrr = dwrr;
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_pri_weight_cfg(struct hclge_dev *hdev, u8 pri_id,
u8 dwrr)
{
struct hclge_priority_weight_cmd *weight;
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_PRI_WEIGHT, false);
weight = (struct hclge_priority_weight_cmd *)desc.data;
weight->pri_id = pri_id;
weight->dwrr = dwrr;
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_qs_weight_cfg(struct hclge_dev *hdev, u16 qs_id,
u8 dwrr)
{
struct hclge_qs_weight_cmd *weight;
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_QS_WEIGHT, false);
weight = (struct hclge_qs_weight_cmd *)desc.data;
weight->qs_id = cpu_to_le16(qs_id);
weight->dwrr = dwrr;
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_pg_shapping_cfg(struct hclge_dev *hdev,
enum hclge_shap_bucket bucket, u8 pg_id,
u8 ir_b, u8 ir_u, u8 ir_s, u8 bs_b, u8 bs_s)
{
struct hclge_pg_shapping_cmd *shap_cfg_cmd;
enum hclge_opcode_type opcode;
struct hclge_desc desc;
opcode = bucket ? HCLGE_OPC_TM_PG_P_SHAPPING :
HCLGE_OPC_TM_PG_C_SHAPPING;
hclge_cmd_setup_basic_desc(&desc, opcode, false);
shap_cfg_cmd = (struct hclge_pg_shapping_cmd *)desc.data;
shap_cfg_cmd->pg_id = pg_id;
hclge_tm_set_field(shap_cfg_cmd->pg_shapping_para, IR_B, ir_b);
hclge_tm_set_field(shap_cfg_cmd->pg_shapping_para, IR_U, ir_u);
hclge_tm_set_field(shap_cfg_cmd->pg_shapping_para, IR_S, ir_s);
hclge_tm_set_field(shap_cfg_cmd->pg_shapping_para, BS_B, bs_b);
hclge_tm_set_field(shap_cfg_cmd->pg_shapping_para, BS_S, bs_s);
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_pri_shapping_cfg(struct hclge_dev *hdev,
enum hclge_shap_bucket bucket, u8 pri_id,
u8 ir_b, u8 ir_u, u8 ir_s,
u8 bs_b, u8 bs_s)
{
struct hclge_pri_shapping_cmd *shap_cfg_cmd;
enum hclge_opcode_type opcode;
struct hclge_desc desc;
opcode = bucket ? HCLGE_OPC_TM_PRI_P_SHAPPING :
HCLGE_OPC_TM_PRI_C_SHAPPING;
hclge_cmd_setup_basic_desc(&desc, opcode, false);
shap_cfg_cmd = (struct hclge_pri_shapping_cmd *)desc.data;
shap_cfg_cmd->pri_id = pri_id;
hclge_tm_set_field(shap_cfg_cmd->pri_shapping_para, IR_B, ir_b);
hclge_tm_set_field(shap_cfg_cmd->pri_shapping_para, IR_U, ir_u);
hclge_tm_set_field(shap_cfg_cmd->pri_shapping_para, IR_S, ir_s);
hclge_tm_set_field(shap_cfg_cmd->pri_shapping_para, BS_B, bs_b);
hclge_tm_set_field(shap_cfg_cmd->pri_shapping_para, BS_S, bs_s);
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_pg_schd_mode_cfg(struct hclge_dev *hdev, u8 pg_id)
{
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_PG_SCH_MODE_CFG, false);
if (hdev->tm_info.pg_info[pg_id].pg_sch_mode == HCLGE_SCH_MODE_DWRR)
desc.data[1] = cpu_to_le32(HCLGE_TM_TX_SCHD_DWRR_MSK);
else
desc.data[1] = 0;
desc.data[0] = cpu_to_le32(pg_id);
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_pri_schd_mode_cfg(struct hclge_dev *hdev, u8 pri_id)
{
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_PRI_SCH_MODE_CFG, false);
if (hdev->tm_info.tc_info[pri_id].tc_sch_mode == HCLGE_SCH_MODE_DWRR)
desc.data[1] = cpu_to_le32(HCLGE_TM_TX_SCHD_DWRR_MSK);
else
desc.data[1] = 0;
desc.data[0] = cpu_to_le32(pri_id);
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_qs_schd_mode_cfg(struct hclge_dev *hdev, u16 qs_id)
{
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_QS_SCH_MODE_CFG, false);
if (hdev->tm_info.tc_info[qs_id].tc_sch_mode == HCLGE_SCH_MODE_DWRR)
desc.data[1] = cpu_to_le32(HCLGE_TM_TX_SCHD_DWRR_MSK);
else
desc.data[1] = 0;
desc.data[0] = cpu_to_le32(qs_id);
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static int hclge_tm_qs_bp_cfg(struct hclge_dev *hdev, u8 tc)
{
struct hclge_bp_to_qs_map_cmd *bp_to_qs_map_cmd;
struct hclge_desc desc;
hclge_cmd_setup_basic_desc(&desc, HCLGE_OPC_TM_BP_TO_QSET_MAPPING,
false);
bp_to_qs_map_cmd = (struct hclge_bp_to_qs_map_cmd *)desc.data;
bp_to_qs_map_cmd->tc_id = tc;
bp_to_qs_map_cmd->qs_bit_map = cpu_to_le32(1 << tc);
return hclge_cmd_send(&hdev->hw, &desc, 1);
}
static void hclge_tm_vport_tc_info_update(struct hclge_vport *vport)
{
struct hnae3_knic_private_info *kinfo = &vport->nic.kinfo;
struct hclge_dev *hdev = vport->back;
u8 i;
kinfo = &vport->nic.kinfo;
vport->bw_limit = hdev->tm_info.pg_info[0].bw_limit;
kinfo->num_tc =
min_t(u16, kinfo->num_tqps, hdev->tm_info.num_tc);
kinfo->rss_size
= min_t(u16, hdev->rss_size_max,
kinfo->num_tqps / kinfo->num_tc);
vport->qs_offset = hdev->tm_info.num_tc * vport->vport_id;
vport->dwrr = 100;
vport->alloc_rss_size = kinfo->rss_size;
for (i = 0; i < kinfo->num_tc; i++) {
if (hdev->hw_tc_map & BIT(i)) {
kinfo->tc_info[i].enable = true;
kinfo->tc_info[i].tqp_offset = i * kinfo->rss_size;
kinfo->tc_info[i].tqp_count = kinfo->rss_size;
kinfo->tc_info[i].tc = i;
} else {
kinfo->tc_info[i].enable = false;
kinfo->tc_info[i].tqp_offset = 0;
kinfo->tc_info[i].tqp_count = 1;
kinfo->tc_info[i].tc = 0;
}
}
memcpy(kinfo->prio_tc, hdev->tm_info.prio_tc,
FIELD_SIZEOF(struct hnae3_knic_private_info, prio_tc));
}
static void hclge_tm_vport_info_update(struct hclge_dev *hdev)
{
struct hclge_vport *vport = hdev->vport;
u32 i;
for (i = 0; i < hdev->num_alloc_vport; i++) {
hclge_tm_vport_tc_info_update(vport);
vport++;
}
}
static void hclge_tm_tc_info_init(struct hclge_dev *hdev)
{
u8 i;
for (i = 0; i < hdev->tm_info.num_tc; i++) {
hdev->tm_info.tc_info[i].tc_id = i;
hdev->tm_info.tc_info[i].tc_sch_mode = HCLGE_SCH_MODE_DWRR;
hdev->tm_info.tc_info[i].pgid = 0;
hdev->tm_info.tc_info[i].bw_limit =
hdev->tm_info.pg_info[0].bw_limit;
}
for (i = 0; i < HNAE3_MAX_USER_PRIO; i++)
hdev->tm_info.prio_tc[i] =
(i >= hdev->tm_info.num_tc) ? 0 : i;
hdev->flag &= ~HCLGE_FLAG_DCB_ENABLE;
}
static void hclge_tm_pg_info_init(struct hclge_dev *hdev)
{
u8 i;
for (i = 0; i < hdev->tm_info.num_pg; i++) {
int k;
hdev->tm_info.pg_dwrr[i] = i ? 0 : 100;
hdev->tm_info.pg_info[i].pg_id = i;
hdev->tm_info.pg_info[i].pg_sch_mode = HCLGE_SCH_MODE_DWRR;
hdev->tm_info.pg_info[i].bw_limit = HCLGE_ETHER_MAX_RATE;
if (i != 0)
continue;
hdev->tm_info.pg_info[i].tc_bit_map = hdev->hw_tc_map;
for (k = 0; k < hdev->tm_info.num_tc; k++)
hdev->tm_info.pg_info[i].tc_dwrr[k] = 100;
}
}
static int hclge_tm_schd_info_init(struct hclge_dev *hdev)
{
if ((hdev->tx_sch_mode != HCLGE_FLAG_TC_BASE_SCH_MODE) &&
(hdev->tm_info.num_pg != 1))
return -EINVAL;
hclge_tm_pg_info_init(hdev);
hclge_tm_tc_info_init(hdev);
hclge_tm_vport_info_update(hdev);
hdev->tm_info.fc_mode = HCLGE_FC_NONE;
hdev->fc_mode_last_time = hdev->tm_info.fc_mode;
return 0;
}
static int hclge_tm_pg_to_pri_map(struct hclge_dev *hdev)
{
int ret;
u32 i;
if (hdev->tx_sch_mode != HCLGE_FLAG_TC_BASE_SCH_MODE)
return 0;
for (i = 0; i < hdev->tm_info.num_pg; i++) {
ret = hclge_tm_pg_to_pri_map_cfg(
hdev, i, hdev->tm_info.pg_info[i].tc_bit_map);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_pg_shaper_cfg(struct hclge_dev *hdev)
{
u8 ir_u, ir_b, ir_s;
int ret;
u32 i;
if (hdev->tx_sch_mode != HCLGE_FLAG_TC_BASE_SCH_MODE)
return 0;
for (i = 0; i < hdev->tm_info.num_pg; i++) {
ret = hclge_shaper_para_calc(
hdev->tm_info.pg_info[i].bw_limit,
HCLGE_SHAPER_LVL_PG,
&ir_b, &ir_u, &ir_s);
if (ret)
return ret;
ret = hclge_tm_pg_shapping_cfg(hdev,
HCLGE_TM_SHAP_C_BUCKET, i,
0, 0, 0, HCLGE_SHAPER_BS_U_DEF,
HCLGE_SHAPER_BS_S_DEF);
if (ret)
return ret;
ret = hclge_tm_pg_shapping_cfg(hdev,
HCLGE_TM_SHAP_P_BUCKET, i,
ir_b, ir_u, ir_s,
HCLGE_SHAPER_BS_U_DEF,
HCLGE_SHAPER_BS_S_DEF);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_pg_dwrr_cfg(struct hclge_dev *hdev)
{
int ret;
u32 i;
if (hdev->tx_sch_mode != HCLGE_FLAG_TC_BASE_SCH_MODE)
return 0;
for (i = 0; i < hdev->tm_info.num_pg; i++) {
ret = hclge_tm_pg_weight_cfg(hdev, i,
hdev->tm_info.pg_dwrr[i]);
if (ret)
return ret;
}
return 0;
}
static int hclge_vport_q_to_qs_map(struct hclge_dev *hdev,
struct hclge_vport *vport)
{
struct hnae3_knic_private_info *kinfo = &vport->nic.kinfo;
struct hnae3_queue **tqp = kinfo->tqp;
struct hnae3_tc_info *v_tc_info;
u32 i, j;
int ret;
for (i = 0; i < kinfo->num_tc; i++) {
v_tc_info = &kinfo->tc_info[i];
for (j = 0; j < v_tc_info->tqp_count; j++) {
struct hnae3_queue *q = tqp[v_tc_info->tqp_offset + j];
ret = hclge_tm_q_to_qs_map_cfg(hdev,
hclge_get_queue_id(q),
vport->qs_offset + i);
if (ret)
return ret;
}
}
return 0;
}
static int hclge_tm_pri_q_qs_cfg(struct hclge_dev *hdev)
{
struct hclge_vport *vport = hdev->vport;
int ret;
u32 i;
if (hdev->tx_sch_mode == HCLGE_FLAG_TC_BASE_SCH_MODE) {
for (i = 0; i < hdev->tm_info.num_tc; i++) {
ret = hclge_tm_qs_to_pri_map_cfg(hdev, i, i);
if (ret)
return ret;
}
} else if (hdev->tx_sch_mode == HCLGE_FLAG_VNET_BASE_SCH_MODE) {
int k;
for (k = 0; k < hdev->num_alloc_vport; k++)
for (i = 0; i < HNAE3_MAX_TC; i++) {
ret = hclge_tm_qs_to_pri_map_cfg(
hdev, vport[k].qs_offset + i, k);
if (ret)
return ret;
}
} else {
return -EINVAL;
}
for (i = 0; i < hdev->num_alloc_vport; i++) {
ret = hclge_vport_q_to_qs_map(hdev, vport);
if (ret)
return ret;
vport++;
}
return 0;
}
static int hclge_tm_pri_tc_base_shaper_cfg(struct hclge_dev *hdev)
{
u8 ir_u, ir_b, ir_s;
int ret;
u32 i;
for (i = 0; i < hdev->tm_info.num_tc; i++) {
ret = hclge_shaper_para_calc(
hdev->tm_info.tc_info[i].bw_limit,
HCLGE_SHAPER_LVL_PRI,
&ir_b, &ir_u, &ir_s);
if (ret)
return ret;
ret = hclge_tm_pri_shapping_cfg(
hdev, HCLGE_TM_SHAP_C_BUCKET, i,
0, 0, 0, HCLGE_SHAPER_BS_U_DEF,
HCLGE_SHAPER_BS_S_DEF);
if (ret)
return ret;
ret = hclge_tm_pri_shapping_cfg(
hdev, HCLGE_TM_SHAP_P_BUCKET, i,
ir_b, ir_u, ir_s, HCLGE_SHAPER_BS_U_DEF,
HCLGE_SHAPER_BS_S_DEF);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_pri_vnet_base_shaper_pri_cfg(struct hclge_vport *vport)
{
struct hclge_dev *hdev = vport->back;
u8 ir_u, ir_b, ir_s;
int ret;
ret = hclge_shaper_para_calc(vport->bw_limit, HCLGE_SHAPER_LVL_VF,
&ir_b, &ir_u, &ir_s);
if (ret)
return ret;
ret = hclge_tm_pri_shapping_cfg(hdev, HCLGE_TM_SHAP_C_BUCKET,
vport->vport_id,
0, 0, 0, HCLGE_SHAPER_BS_U_DEF,
HCLGE_SHAPER_BS_S_DEF);
if (ret)
return ret;
ret = hclge_tm_pri_shapping_cfg(hdev, HCLGE_TM_SHAP_P_BUCKET,
vport->vport_id,
ir_b, ir_u, ir_s,
HCLGE_SHAPER_BS_U_DEF,
HCLGE_SHAPER_BS_S_DEF);
if (ret)
return ret;
return 0;
}
static int hclge_tm_pri_vnet_base_shaper_qs_cfg(struct hclge_vport *vport)
{
struct hnae3_knic_private_info *kinfo = &vport->nic.kinfo;
struct hclge_dev *hdev = vport->back;
struct hnae3_tc_info *v_tc_info;
u8 ir_u, ir_b, ir_s;
u32 i;
int ret;
for (i = 0; i < kinfo->num_tc; i++) {
v_tc_info = &kinfo->tc_info[i];
ret = hclge_shaper_para_calc(
hdev->tm_info.tc_info[i].bw_limit,
HCLGE_SHAPER_LVL_QSET,
&ir_b, &ir_u, &ir_s);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_pri_vnet_base_shaper_cfg(struct hclge_dev *hdev)
{
struct hclge_vport *vport = hdev->vport;
int ret;
u32 i;
for (i = 0; i < hdev->num_alloc_vport; i++) {
ret = hclge_tm_pri_vnet_base_shaper_pri_cfg(vport);
if (ret)
return ret;
ret = hclge_tm_pri_vnet_base_shaper_qs_cfg(vport);
if (ret)
return ret;
vport++;
}
return 0;
}
static int hclge_tm_pri_shaper_cfg(struct hclge_dev *hdev)
{
int ret;
if (hdev->tx_sch_mode == HCLGE_FLAG_TC_BASE_SCH_MODE) {
ret = hclge_tm_pri_tc_base_shaper_cfg(hdev);
if (ret)
return ret;
} else {
ret = hclge_tm_pri_vnet_base_shaper_cfg(hdev);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_pri_tc_base_dwrr_cfg(struct hclge_dev *hdev)
{
struct hclge_pg_info *pg_info;
u8 dwrr;
int ret;
u32 i;
for (i = 0; i < hdev->tm_info.num_tc; i++) {
pg_info =
&hdev->tm_info.pg_info[hdev->tm_info.tc_info[i].pgid];
dwrr = pg_info->tc_dwrr[i];
ret = hclge_tm_pri_weight_cfg(hdev, i, dwrr);
if (ret)
return ret;
ret = hclge_tm_qs_weight_cfg(hdev, i, dwrr);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_pri_vnet_base_dwrr_pri_cfg(struct hclge_vport *vport)
{
struct hnae3_knic_private_info *kinfo = &vport->nic.kinfo;
struct hclge_dev *hdev = vport->back;
int ret;
u8 i;
ret = hclge_tm_pri_weight_cfg(hdev, vport->vport_id, vport->dwrr);
if (ret)
return ret;
for (i = 0; i < kinfo->num_tc; i++) {
ret = hclge_tm_qs_weight_cfg(
hdev, vport->qs_offset + i,
hdev->tm_info.pg_info[0].tc_dwrr[i]);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_pri_vnet_base_dwrr_cfg(struct hclge_dev *hdev)
{
struct hclge_vport *vport = hdev->vport;
int ret;
u32 i;
for (i = 0; i < hdev->num_alloc_vport; i++) {
ret = hclge_tm_pri_vnet_base_dwrr_pri_cfg(vport);
if (ret)
return ret;
vport++;
}
return 0;
}
static int hclge_tm_pri_dwrr_cfg(struct hclge_dev *hdev)
{
int ret;
if (hdev->tx_sch_mode == HCLGE_FLAG_TC_BASE_SCH_MODE) {
ret = hclge_tm_pri_tc_base_dwrr_cfg(hdev);
if (ret)
return ret;
} else {
ret = hclge_tm_pri_vnet_base_dwrr_cfg(hdev);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_map_cfg(struct hclge_dev *hdev)
{
int ret;
ret = hclge_tm_pg_to_pri_map(hdev);
if (ret)
return ret;
return hclge_tm_pri_q_qs_cfg(hdev);
}
static int hclge_tm_shaper_cfg(struct hclge_dev *hdev)
{
int ret;
ret = hclge_tm_pg_shaper_cfg(hdev);
if (ret)
return ret;
return hclge_tm_pri_shaper_cfg(hdev);
}
int hclge_tm_dwrr_cfg(struct hclge_dev *hdev)
{
int ret;
ret = hclge_tm_pg_dwrr_cfg(hdev);
if (ret)
return ret;
return hclge_tm_pri_dwrr_cfg(hdev);
}
static int hclge_tm_lvl2_schd_mode_cfg(struct hclge_dev *hdev)
{
int ret;
u8 i;
if (hdev->tx_sch_mode == HCLGE_FLAG_VNET_BASE_SCH_MODE)
return 0;
for (i = 0; i < hdev->tm_info.num_pg; i++) {
ret = hclge_tm_pg_schd_mode_cfg(hdev, i);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_schd_mode_vnet_base_cfg(struct hclge_vport *vport)
{
struct hnae3_knic_private_info *kinfo = &vport->nic.kinfo;
struct hclge_dev *hdev = vport->back;
int ret;
u8 i;
ret = hclge_tm_pri_schd_mode_cfg(hdev, vport->vport_id);
if (ret)
return ret;
for (i = 0; i < kinfo->num_tc; i++) {
ret = hclge_tm_qs_schd_mode_cfg(hdev, vport->qs_offset + i);
if (ret)
return ret;
}
return 0;
}
static int hclge_tm_lvl34_schd_mode_cfg(struct hclge_dev *hdev)
{
struct hclge_vport *vport = hdev->vport;
int ret;
u8 i;
if (hdev->tx_sch_mode == HCLGE_FLAG_TC_BASE_SCH_MODE) {
for (i = 0; i < hdev->tm_info.num_tc; i++) {
ret = hclge_tm_pri_schd_mode_cfg(hdev, i);
if (ret)
return ret;
ret = hclge_tm_qs_schd_mode_cfg(hdev, i);
if (ret)
return ret;
}
} else {
for (i = 0; i < hdev->num_alloc_vport; i++) {
ret = hclge_tm_schd_mode_vnet_base_cfg(vport);
if (ret)
return ret;
vport++;
}
}
return 0;
}
static int hclge_tm_schd_mode_hw(struct hclge_dev *hdev)
{
int ret;
ret = hclge_tm_lvl2_schd_mode_cfg(hdev);
if (ret)
return ret;
return hclge_tm_lvl34_schd_mode_cfg(hdev);
}
static int hclge_tm_schd_setup_hw(struct hclge_dev *hdev)
{
int ret;
ret = hclge_tm_map_cfg(hdev);
if (ret)
return ret;
ret = hclge_tm_shaper_cfg(hdev);
if (ret)
return ret;
ret = hclge_tm_dwrr_cfg(hdev);
if (ret)
return ret;
return hclge_tm_schd_mode_hw(hdev);
}
int hclge_pause_setup_hw(struct hclge_dev *hdev)
{
bool en = hdev->tm_info.fc_mode != HCLGE_FC_PFC;
int ret;
u8 i;
ret = hclge_mac_pause_en_cfg(hdev, en, en);
if (ret)
return ret;
if (!hnae3_dev_dcb_supported(hdev))
return 0;
for (i = 0; i < hdev->tm_info.num_tc; i++) {
ret = hclge_tm_qs_bp_cfg(hdev, i);
if (ret)
return ret;
}
return hclge_up_to_tc_map(hdev);
}
int hclge_tm_init_hw(struct hclge_dev *hdev)
{
int ret;
if ((hdev->tx_sch_mode != HCLGE_FLAG_TC_BASE_SCH_MODE) &&
(hdev->tx_sch_mode != HCLGE_FLAG_VNET_BASE_SCH_MODE))
return -ENOTSUPP;
ret = hclge_tm_schd_setup_hw(hdev);
if (ret)
return ret;
ret = hclge_pause_setup_hw(hdev);
if (ret)
return ret;
return 0;
}
int hclge_tm_schd_init(struct hclge_dev *hdev)
{
int ret = hclge_tm_schd_info_init(hdev);
if (ret)
return ret;
return hclge_tm_init_hw(hdev);
}
