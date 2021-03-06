static void qed_enable_pf_rl(struct qed_hwfn *p_hwfn, bool pf_rl_en)
{
STORE_RT_REG(p_hwfn, QM_REG_RLPFENABLE_RT_OFFSET, pf_rl_en ? 1 : 0);
if (pf_rl_en) {
STORE_RT_REG(p_hwfn, QM_REG_RLPFVOQENABLE_RT_OFFSET,
(1 << MAX_NUM_VOQS) - 1);
STORE_RT_REG(p_hwfn,
QM_REG_RLPFPERIOD_RT_OFFSET, QM_RL_PERIOD_CLK_25M);
STORE_RT_REG(p_hwfn,
QM_REG_RLPFPERIODTIMER_RT_OFFSET,
QM_RL_PERIOD_CLK_25M);
if (QM_BYPASS_EN)
STORE_RT_REG(p_hwfn,
QM_REG_AFULLQMBYPTHRPFRL_RT_OFFSET,
QM_RL_UPPER_BOUND);
}
}
static void qed_enable_pf_wfq(struct qed_hwfn *p_hwfn, bool pf_wfq_en)
{
STORE_RT_REG(p_hwfn, QM_REG_WFQPFENABLE_RT_OFFSET, pf_wfq_en ? 1 : 0);
if (pf_wfq_en && QM_BYPASS_EN)
STORE_RT_REG(p_hwfn,
QM_REG_AFULLQMBYPTHRPFWFQ_RT_OFFSET,
QM_WFQ_UPPER_BOUND);
}
static void qed_enable_vport_rl(struct qed_hwfn *p_hwfn, bool vport_rl_en)
{
STORE_RT_REG(p_hwfn, QM_REG_RLGLBLENABLE_RT_OFFSET,
vport_rl_en ? 1 : 0);
if (vport_rl_en) {
STORE_RT_REG(p_hwfn,
QM_REG_RLGLBLPERIOD_0_RT_OFFSET,
QM_RL_PERIOD_CLK_25M);
STORE_RT_REG(p_hwfn,
QM_REG_RLGLBLPERIODTIMER_0_RT_OFFSET,
QM_RL_PERIOD_CLK_25M);
if (QM_BYPASS_EN)
STORE_RT_REG(p_hwfn,
QM_REG_AFULLQMBYPTHRGLBLRL_RT_OFFSET,
QM_RL_UPPER_BOUND);
}
}
static void qed_enable_vport_wfq(struct qed_hwfn *p_hwfn, bool vport_wfq_en)
{
STORE_RT_REG(p_hwfn, QM_REG_WFQVPENABLE_RT_OFFSET,
vport_wfq_en ? 1 : 0);
if (vport_wfq_en && QM_BYPASS_EN)
STORE_RT_REG(p_hwfn,
QM_REG_AFULLQMBYPTHRVPWFQ_RT_OFFSET,
QM_WFQ_UPPER_BOUND);
}
static void qed_cmdq_lines_voq_rt_init(struct qed_hwfn *p_hwfn,
u8 voq, u16 cmdq_lines)
{
u32 qm_line_crd;
bool is_bb_a0 = QED_IS_BB_A0(p_hwfn->cdev);
if (is_bb_a0)
cmdq_lines = min_t(u32, cmdq_lines, 1022);
qm_line_crd = QM_VOQ_LINE_CRD(cmdq_lines);
OVERWRITE_RT_REG(p_hwfn, PBF_CMDQ_LINES_RT_OFFSET(voq),
(u32)cmdq_lines);
STORE_RT_REG(p_hwfn, QM_REG_VOQCRDLINE_RT_OFFSET + voq, qm_line_crd);
STORE_RT_REG(p_hwfn, QM_REG_VOQINITCRDLINE_RT_OFFSET + voq,
qm_line_crd);
}
static void qed_cmdq_lines_rt_init(
struct qed_hwfn *p_hwfn,
u8 max_ports_per_engine,
u8 max_phys_tcs_per_port,
struct init_qm_port_params port_params[MAX_NUM_PORTS])
{
u8 tc, voq, port_id, num_tcs_in_port;
for (voq = 0; voq < MAX_NUM_VOQS; voq++)
STORE_RT_REG(p_hwfn, PBF_CMDQ_LINES_RT_OFFSET(voq), 0);
for (port_id = 0; port_id < max_ports_per_engine; port_id++) {
if (port_params[port_id].active) {
u16 phys_lines, phys_lines_per_tc;
phys_lines = port_params[port_id].num_pbf_cmd_lines -
PBF_CMDQ_PURE_LB_LINES;
num_tcs_in_port = 0;
for (tc = 0; tc < NUM_OF_PHYS_TCS; tc++) {
if (((port_params[port_id].active_phys_tcs >>
tc) & 0x1) == 1)
num_tcs_in_port++;
}
phys_lines_per_tc = phys_lines / num_tcs_in_port;
for (tc = 0; tc < NUM_OF_PHYS_TCS; tc++) {
if (((port_params[port_id].active_phys_tcs >>
tc) & 0x1) != 1)
continue;
voq = PHYS_VOQ(port_id, tc,
max_phys_tcs_per_port);
qed_cmdq_lines_voq_rt_init(p_hwfn, voq,
phys_lines_per_tc);
}
qed_cmdq_lines_voq_rt_init(p_hwfn, LB_VOQ(port_id),
PBF_CMDQ_PURE_LB_LINES);
}
}
}
static void qed_btb_blocks_rt_init(
struct qed_hwfn *p_hwfn,
u8 max_ports_per_engine,
u8 max_phys_tcs_per_port,
struct init_qm_port_params port_params[MAX_NUM_PORTS])
{
u32 usable_blocks, pure_lb_blocks, phys_blocks;
u8 tc, voq, port_id, num_tcs_in_port;
for (port_id = 0; port_id < max_ports_per_engine; port_id++) {
u32 temp;
if (!port_params[port_id].active)
continue;
usable_blocks = port_params[port_id].num_btb_blocks -
BTB_HEADROOM_BLOCKS;
num_tcs_in_port = 0;
for (tc = 0; tc < NUM_OF_PHYS_TCS; tc++) {
if (((port_params[port_id].active_phys_tcs >>
tc) & 0x1) == 1)
num_tcs_in_port++;
}
pure_lb_blocks = (usable_blocks * BTB_PURE_LB_FACTOR) /
(num_tcs_in_port * BTB_PURE_LB_FACTOR +
BTB_PURE_LB_RATIO);
pure_lb_blocks = max_t(u32, BTB_JUMBO_PKT_BLOCKS,
pure_lb_blocks / BTB_PURE_LB_FACTOR);
phys_blocks = (usable_blocks - pure_lb_blocks) /
num_tcs_in_port;
for (tc = 0; tc < NUM_OF_PHYS_TCS; tc++) {
if (((port_params[port_id].active_phys_tcs >>
tc) & 0x1) != 1)
continue;
voq = PHYS_VOQ(port_id, tc,
max_phys_tcs_per_port);
STORE_RT_REG(p_hwfn, PBF_BTB_GUARANTEED_RT_OFFSET(voq),
phys_blocks);
}
temp = LB_VOQ(port_id);
STORE_RT_REG(p_hwfn, PBF_BTB_GUARANTEED_RT_OFFSET(temp),
pure_lb_blocks);
}
}
static void qed_tx_pq_map_rt_init(
struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct qed_qm_pf_rt_init_params *p_params,
u32 base_mem_addr_4kb)
{
struct init_qm_vport_params *vport_params = p_params->vport_params;
u16 num_pqs = p_params->num_pf_pqs + p_params->num_vf_pqs;
u16 first_pq_group = p_params->start_pq / QM_PF_QUEUE_GROUP_SIZE;
u16 last_pq_group = (p_params->start_pq + num_pqs - 1) /
QM_PF_QUEUE_GROUP_SIZE;
bool is_bb_a0 = QED_IS_BB_A0(p_hwfn->cdev);
u16 i, pq_id, pq_group;
u32 tx_pq_vf_mask[MAX_QM_TX_QUEUES / QM_PF_QUEUE_GROUP_SIZE] = { 0 };
u32 tx_pq_vf_mask_width = is_bb_a0 ? 32 : QM_PF_QUEUE_GROUP_SIZE;
u32 num_tx_pq_vf_masks = MAX_QM_TX_QUEUES / tx_pq_vf_mask_width;
u32 pq_mem_4kb = QM_PQ_MEM_4KB(p_params->num_pf_cids);
u32 vport_pq_mem_4kb = QM_PQ_MEM_4KB(p_params->num_vf_cids);
u32 mem_addr_4kb = base_mem_addr_4kb;
for (pq_group = first_pq_group; pq_group <= last_pq_group; pq_group++)
STORE_RT_REG(p_hwfn, QM_REG_PQTX2PF_0_RT_OFFSET + pq_group,
(u32)(p_params->pf_id));
STORE_RT_REG(p_hwfn, QM_REG_MAXPQSIZE_0_RT_OFFSET,
QM_PQ_SIZE_256B(p_params->num_pf_cids));
STORE_RT_REG(p_hwfn, QM_REG_MAXPQSIZE_1_RT_OFFSET,
QM_PQ_SIZE_256B(p_params->num_vf_cids));
for (i = 0, pq_id = p_params->start_pq; i < num_pqs; i++, pq_id++) {
u8 voq = VOQ(p_params->port_id, p_params->pq_params[i].tc_id,
p_params->max_phys_tcs_per_port);
bool is_vf_pq = (i >= p_params->num_pf_pqs);
struct qm_rf_pq_map tx_pq_map;
u8 vport_id_in_pf = p_params->pq_params[i].vport_id -
p_params->start_vport;
u16 *pq_ids = &vport_params[vport_id_in_pf].first_tx_pq_id[0];
u16 first_tx_pq_id = pq_ids[p_params->pq_params[i].tc_id];
if (first_tx_pq_id == QM_INVALID_PQ_ID) {
pq_ids[p_params->pq_params[i].tc_id] = pq_id;
first_tx_pq_id = pq_id;
STORE_RT_REG(p_hwfn,
QM_REG_WFQVPMAP_RT_OFFSET +
first_tx_pq_id,
(voq << QM_WFQ_VP_PQ_VOQ_SHIFT) |
(p_params->pf_id <<
QM_WFQ_VP_PQ_PF_SHIFT));
}
memset(&tx_pq_map, 0, sizeof(tx_pq_map));
SET_FIELD(tx_pq_map.reg, QM_RF_PQ_MAP_PQ_VALID, 1);
SET_FIELD(tx_pq_map.reg, QM_RF_PQ_MAP_RL_VALID,
p_params->pq_params[i].rl_valid ? 1 : 0);
SET_FIELD(tx_pq_map.reg, QM_RF_PQ_MAP_VP_PQ_ID, first_tx_pq_id);
SET_FIELD(tx_pq_map.reg, QM_RF_PQ_MAP_RL_ID,
p_params->pq_params[i].rl_valid ?
p_params->pq_params[i].vport_id : 0);
SET_FIELD(tx_pq_map.reg, QM_RF_PQ_MAP_VOQ, voq);
SET_FIELD(tx_pq_map.reg, QM_RF_PQ_MAP_WRR_WEIGHT_GROUP,
p_params->pq_params[i].wrr_group);
STORE_RT_REG(p_hwfn, QM_REG_TXPQMAP_RT_OFFSET + pq_id,
*((u32 *)&tx_pq_map));
STORE_RT_REG(p_hwfn,
QM_REG_BASEADDRTXPQ_RT_OFFSET + pq_id,
mem_addr_4kb);
if (is_vf_pq) {
tx_pq_vf_mask[pq_id / tx_pq_vf_mask_width] |=
(1 << (pq_id % tx_pq_vf_mask_width));
mem_addr_4kb += vport_pq_mem_4kb;
} else {
mem_addr_4kb += pq_mem_4kb;
}
}
for (i = 0; i < num_tx_pq_vf_masks; i++) {
if (tx_pq_vf_mask[i]) {
u32 addr;
addr = QM_REG_MAXPQSIZETXSEL_0_RT_OFFSET + i;
STORE_RT_REG(p_hwfn, addr,
tx_pq_vf_mask[i]);
}
}
}
static void qed_other_pq_map_rt_init(struct qed_hwfn *p_hwfn,
u8 port_id,
u8 pf_id,
u32 num_pf_cids,
u32 num_tids, u32 base_mem_addr_4kb)
{
u16 i, pq_id;
u16 pq_group = pf_id;
u32 pq_size = num_pf_cids + num_tids;
u32 pq_mem_4kb = QM_PQ_MEM_4KB(pq_size);
u32 mem_addr_4kb = base_mem_addr_4kb;
STORE_RT_REG(p_hwfn, QM_REG_PQOTHER2PF_0_RT_OFFSET + pq_group,
(u32)(pf_id));
STORE_RT_REG(p_hwfn, QM_REG_MAXPQSIZE_2_RT_OFFSET,
QM_PQ_SIZE_256B(pq_size));
for (i = 0, pq_id = pf_id * QM_PF_QUEUE_GROUP_SIZE;
i < QM_OTHER_PQS_PER_PF; i++, pq_id++) {
STORE_RT_REG(p_hwfn,
QM_REG_BASEADDROTHERPQ_RT_OFFSET + pq_id,
mem_addr_4kb);
mem_addr_4kb += pq_mem_4kb;
}
}
static int qed_pf_wfq_rt_init(struct qed_hwfn *p_hwfn,
struct qed_qm_pf_rt_init_params *p_params)
{
u16 num_tx_pqs = p_params->num_pf_pqs + p_params->num_vf_pqs;
u32 crd_reg_offset;
u32 inc_val;
u16 i;
if (p_params->pf_id < MAX_NUM_PFS_BB)
crd_reg_offset = QM_REG_WFQPFCRD_RT_OFFSET;
else
crd_reg_offset = QM_REG_WFQPFCRD_MSB_RT_OFFSET +
(p_params->pf_id % MAX_NUM_PFS_BB);
inc_val = QM_WFQ_INC_VAL(p_params->pf_wfq);
if (!inc_val || inc_val > QM_WFQ_MAX_INC_VAL) {
DP_NOTICE(p_hwfn, "Invalid PF WFQ weight configuration");
return -1;
}
for (i = 0; i < num_tx_pqs; i++) {
u8 voq = VOQ(p_params->port_id, p_params->pq_params[i].tc_id,
p_params->max_phys_tcs_per_port);
OVERWRITE_RT_REG(p_hwfn,
crd_reg_offset + voq * MAX_NUM_PFS_BB,
QM_WFQ_CRD_REG_SIGN_BIT);
}
STORE_RT_REG(p_hwfn, QM_REG_WFQPFWEIGHT_RT_OFFSET + p_params->pf_id,
inc_val);
STORE_RT_REG(p_hwfn,
QM_REG_WFQPFUPPERBOUND_RT_OFFSET + p_params->pf_id,
QM_WFQ_UPPER_BOUND | QM_WFQ_CRD_REG_SIGN_BIT);
return 0;
}
static int qed_pf_rl_rt_init(struct qed_hwfn *p_hwfn, u8 pf_id, u32 pf_rl)
{
u32 inc_val = QM_RL_INC_VAL(pf_rl);
if (inc_val > QM_RL_MAX_INC_VAL) {
DP_NOTICE(p_hwfn, "Invalid PF rate limit configuration");
return -1;
}
STORE_RT_REG(p_hwfn, QM_REG_RLPFCRD_RT_OFFSET + pf_id,
QM_RL_CRD_REG_SIGN_BIT);
STORE_RT_REG(p_hwfn, QM_REG_RLPFUPPERBOUND_RT_OFFSET + pf_id,
QM_RL_UPPER_BOUND | QM_RL_CRD_REG_SIGN_BIT);
STORE_RT_REG(p_hwfn, QM_REG_RLPFINCVAL_RT_OFFSET + pf_id, inc_val);
return 0;
}
static int qed_vp_wfq_rt_init(struct qed_hwfn *p_hwfn,
u8 num_vports,
struct init_qm_vport_params *vport_params)
{
u32 inc_val;
u8 tc, i;
for (i = 0; i < num_vports; i++) {
if (!vport_params[i].vport_wfq)
continue;
inc_val = QM_WFQ_INC_VAL(vport_params[i].vport_wfq);
if (inc_val > QM_WFQ_MAX_INC_VAL) {
DP_NOTICE(p_hwfn,
"Invalid VPORT WFQ weight configuration");
return -1;
}
for (tc = 0; tc < NUM_OF_TCS; tc++) {
u16 vport_pq_id = vport_params[i].first_tx_pq_id[tc];
if (vport_pq_id != QM_INVALID_PQ_ID) {
STORE_RT_REG(p_hwfn,
QM_REG_WFQVPCRD_RT_OFFSET +
vport_pq_id,
QM_WFQ_CRD_REG_SIGN_BIT);
STORE_RT_REG(p_hwfn,
QM_REG_WFQVPWEIGHT_RT_OFFSET +
vport_pq_id, inc_val);
}
}
}
return 0;
}
static int qed_vport_rl_rt_init(struct qed_hwfn *p_hwfn,
u8 start_vport,
u8 num_vports,
struct init_qm_vport_params *vport_params)
{
u8 i, vport_id;
for (i = 0, vport_id = start_vport; i < num_vports; i++, vport_id++) {
u32 inc_val = QM_RL_INC_VAL(vport_params[i].vport_rl);
if (inc_val > QM_RL_MAX_INC_VAL) {
DP_NOTICE(p_hwfn,
"Invalid VPORT rate-limit configuration");
return -1;
}
STORE_RT_REG(p_hwfn,
QM_REG_RLGLBLCRD_RT_OFFSET + vport_id,
QM_RL_CRD_REG_SIGN_BIT);
STORE_RT_REG(p_hwfn,
QM_REG_RLGLBLUPPERBOUND_RT_OFFSET + vport_id,
QM_RL_UPPER_BOUND | QM_RL_CRD_REG_SIGN_BIT);
STORE_RT_REG(p_hwfn,
QM_REG_RLGLBLINCVAL_RT_OFFSET + vport_id,
inc_val);
}
return 0;
}
static bool qed_poll_on_qm_cmd_ready(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
u32 reg_val, i;
for (i = 0, reg_val = 0; i < QM_STOP_CMD_MAX_POLL_COUNT && reg_val == 0;
i++) {
udelay(QM_STOP_CMD_POLL_PERIOD_US);
reg_val = qed_rd(p_hwfn, p_ptt, QM_REG_SDMCMDREADY);
}
if (i == QM_STOP_CMD_MAX_POLL_COUNT) {
DP_VERBOSE(p_hwfn, NETIF_MSG_HW,
"Timeout when waiting for QM SDM command ready signal\n");
return false;
}
return true;
}
static bool qed_send_qm_cmd(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 cmd_addr, u32 cmd_data_lsb, u32 cmd_data_msb)
{
if (!qed_poll_on_qm_cmd_ready(p_hwfn, p_ptt))
return false;
qed_wr(p_hwfn, p_ptt, QM_REG_SDMCMDADDR, cmd_addr);
qed_wr(p_hwfn, p_ptt, QM_REG_SDMCMDDATALSB, cmd_data_lsb);
qed_wr(p_hwfn, p_ptt, QM_REG_SDMCMDDATAMSB, cmd_data_msb);
qed_wr(p_hwfn, p_ptt, QM_REG_SDMCMDGO, 1);
qed_wr(p_hwfn, p_ptt, QM_REG_SDMCMDGO, 0);
return qed_poll_on_qm_cmd_ready(p_hwfn, p_ptt);
}
u32 qed_qm_pf_mem_size(u8 pf_id,
u32 num_pf_cids,
u32 num_vf_cids,
u32 num_tids, u16 num_pf_pqs, u16 num_vf_pqs)
{
return QM_PQ_MEM_4KB(num_pf_cids) * num_pf_pqs +
QM_PQ_MEM_4KB(num_vf_cids) * num_vf_pqs +
QM_PQ_MEM_4KB(num_pf_cids + num_tids) * QM_OTHER_PQS_PER_PF;
}
int qed_qm_common_rt_init(
struct qed_hwfn *p_hwfn,
struct qed_qm_common_rt_init_params *p_params)
{
u32 mask = (QM_OPPOR_LINE_VOQ_DEF <<
QM_RF_OPPORTUNISTIC_MASK_LINEVOQ_SHIFT) |
(QM_BYTE_CRD_EN << QM_RF_OPPORTUNISTIC_MASK_BYTEVOQ_SHIFT) |
(p_params->pf_wfq_en <<
QM_RF_OPPORTUNISTIC_MASK_PFWFQ_SHIFT) |
(p_params->vport_wfq_en <<
QM_RF_OPPORTUNISTIC_MASK_VPWFQ_SHIFT) |
(p_params->pf_rl_en <<
QM_RF_OPPORTUNISTIC_MASK_PFRL_SHIFT) |
(p_params->vport_rl_en <<
QM_RF_OPPORTUNISTIC_MASK_VPQCNRL_SHIFT) |
(QM_OPPOR_FW_STOP_DEF <<
QM_RF_OPPORTUNISTIC_MASK_FWPAUSE_SHIFT) |
(QM_OPPOR_PQ_EMPTY_DEF <<
QM_RF_OPPORTUNISTIC_MASK_QUEUEEMPTY_SHIFT);
STORE_RT_REG(p_hwfn, QM_REG_AFULLOPRTNSTCCRDMASK_RT_OFFSET, mask);
qed_enable_pf_rl(p_hwfn, p_params->pf_rl_en);
qed_enable_pf_wfq(p_hwfn, p_params->pf_wfq_en);
qed_enable_vport_rl(p_hwfn, p_params->vport_rl_en);
qed_enable_vport_wfq(p_hwfn, p_params->vport_wfq_en);
qed_cmdq_lines_rt_init(p_hwfn,
p_params->max_ports_per_engine,
p_params->max_phys_tcs_per_port,
p_params->port_params);
qed_btb_blocks_rt_init(p_hwfn,
p_params->max_ports_per_engine,
p_params->max_phys_tcs_per_port,
p_params->port_params);
return 0;
}
int qed_qm_pf_rt_init(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct qed_qm_pf_rt_init_params *p_params)
{
struct init_qm_vport_params *vport_params = p_params->vport_params;
u32 other_mem_size_4kb = QM_PQ_MEM_4KB(p_params->num_pf_cids +
p_params->num_tids) *
QM_OTHER_PQS_PER_PF;
u8 tc, i;
for (i = 0; i < p_params->num_vports; i++)
for (tc = 0; tc < NUM_OF_TCS; tc++)
vport_params[i].first_tx_pq_id[tc] = QM_INVALID_PQ_ID;
qed_other_pq_map_rt_init(p_hwfn, p_params->port_id, p_params->pf_id,
p_params->num_pf_cids, p_params->num_tids, 0);
qed_tx_pq_map_rt_init(p_hwfn, p_ptt, p_params, other_mem_size_4kb);
if (p_params->pf_wfq)
if (qed_pf_wfq_rt_init(p_hwfn, p_params))
return -1;
if (qed_pf_rl_rt_init(p_hwfn, p_params->pf_id, p_params->pf_rl))
return -1;
if (qed_vp_wfq_rt_init(p_hwfn, p_params->num_vports, vport_params))
return -1;
if (qed_vport_rl_rt_init(p_hwfn, p_params->start_vport,
p_params->num_vports, vport_params))
return -1;
return 0;
}
int qed_init_pf_wfq(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u8 pf_id, u16 pf_wfq)
{
u32 inc_val = QM_WFQ_INC_VAL(pf_wfq);
if (!inc_val || inc_val > QM_WFQ_MAX_INC_VAL) {
DP_NOTICE(p_hwfn, "Invalid PF WFQ weight configuration");
return -1;
}
qed_wr(p_hwfn, p_ptt, QM_REG_WFQPFWEIGHT + pf_id * 4, inc_val);
return 0;
}
int qed_init_pf_rl(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u8 pf_id, u32 pf_rl)
{
u32 inc_val = QM_RL_INC_VAL(pf_rl);
if (inc_val > QM_RL_MAX_INC_VAL) {
DP_NOTICE(p_hwfn, "Invalid PF rate limit configuration");
return -1;
}
qed_wr(p_hwfn, p_ptt,
QM_REG_RLPFCRD + pf_id * 4,
QM_RL_CRD_REG_SIGN_BIT);
qed_wr(p_hwfn, p_ptt, QM_REG_RLPFINCVAL + pf_id * 4, inc_val);
return 0;
}
int qed_init_vport_wfq(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u16 first_tx_pq_id[NUM_OF_TCS], u16 vport_wfq)
{
u32 inc_val = QM_WFQ_INC_VAL(vport_wfq);
u8 tc;
if (!inc_val || inc_val > QM_WFQ_MAX_INC_VAL) {
DP_NOTICE(p_hwfn, "Invalid VPORT WFQ weight configuration");
return -1;
}
for (tc = 0; tc < NUM_OF_TCS; tc++) {
u16 vport_pq_id = first_tx_pq_id[tc];
if (vport_pq_id != QM_INVALID_PQ_ID)
qed_wr(p_hwfn, p_ptt,
QM_REG_WFQVPWEIGHT + vport_pq_id * 4,
inc_val);
}
return 0;
}
int qed_init_vport_rl(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u8 vport_id, u32 vport_rl)
{
u32 inc_val = QM_RL_INC_VAL(vport_rl);
if (inc_val > QM_RL_MAX_INC_VAL) {
DP_NOTICE(p_hwfn, "Invalid VPORT rate-limit configuration");
return -1;
}
qed_wr(p_hwfn, p_ptt,
QM_REG_RLGLBLCRD + vport_id * 4,
QM_RL_CRD_REG_SIGN_BIT);
qed_wr(p_hwfn, p_ptt, QM_REG_RLGLBLINCVAL + vport_id * 4, inc_val);
return 0;
}
bool qed_send_qm_stop_cmd(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
bool is_release_cmd,
bool is_tx_pq, u16 start_pq, u16 num_pqs)
{
u32 cmd_arr[QM_CMD_STRUCT_SIZE(QM_STOP_CMD)] = { 0 };
u32 pq_mask = 0, last_pq = start_pq + num_pqs - 1, pq_id;
QM_CMD_SET_FIELD(cmd_arr, QM_STOP_CMD, PQ_TYPE, is_tx_pq ? 0 : 1);
for (pq_id = start_pq; pq_id <= last_pq; pq_id++) {
if (!is_release_cmd)
pq_mask |= (1 << (pq_id % QM_STOP_PQ_MASK_WIDTH));
if ((pq_id == last_pq) ||
(pq_id % QM_STOP_PQ_MASK_WIDTH ==
(QM_STOP_PQ_MASK_WIDTH - 1))) {
QM_CMD_SET_FIELD(cmd_arr, QM_STOP_CMD,
PAUSE_MASK, pq_mask);
QM_CMD_SET_FIELD(cmd_arr, QM_STOP_CMD,
GROUP_ID,
pq_id / QM_STOP_PQ_MASK_WIDTH);
if (!qed_send_qm_cmd(p_hwfn, p_ptt, QM_STOP_CMD_ADDR,
cmd_arr[0], cmd_arr[1]))
return false;
pq_mask = 0;
}
}
return true;
}
static void
qed_set_tunnel_type_enable_bit(unsigned long *var, int bit, bool enable)
{
if (enable)
set_bit(bit, var);
else
clear_bit(bit, var);
}
void qed_set_vxlan_dest_port(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u16 dest_port)
{
qed_wr(p_hwfn, p_ptt, PRS_REG_VXLAN_PORT, dest_port);
qed_wr(p_hwfn, p_ptt, NIG_REG_VXLAN_CTRL, dest_port);
qed_wr(p_hwfn, p_ptt, PBF_REG_VXLAN_PORT, dest_port);
}
void qed_set_vxlan_enable(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, bool vxlan_enable)
{
unsigned long reg_val = 0;
u8 shift;
reg_val = qed_rd(p_hwfn, p_ptt, PRS_REG_ENCAPSULATION_TYPE_EN);
shift = PRS_REG_ENCAPSULATION_TYPE_EN_VXLAN_ENABLE_SHIFT;
qed_set_tunnel_type_enable_bit(&reg_val, shift, vxlan_enable);
qed_wr(p_hwfn, p_ptt, PRS_REG_ENCAPSULATION_TYPE_EN, reg_val);
if (reg_val)
qed_wr(p_hwfn, p_ptt, PRS_REG_OUTPUT_FORMAT_4_0,
PRS_ETH_TUNN_FIC_FORMAT);
reg_val = qed_rd(p_hwfn, p_ptt, NIG_REG_ENC_TYPE_ENABLE);
shift = NIG_REG_ENC_TYPE_ENABLE_VXLAN_ENABLE_SHIFT;
qed_set_tunnel_type_enable_bit(&reg_val, shift, vxlan_enable);
qed_wr(p_hwfn, p_ptt, NIG_REG_ENC_TYPE_ENABLE, reg_val);
qed_wr(p_hwfn, p_ptt, DORQ_REG_L2_EDPM_TUNNEL_VXLAN_EN,
vxlan_enable ? 1 : 0);
}
void qed_set_gre_enable(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt,
bool eth_gre_enable, bool ip_gre_enable)
{
unsigned long reg_val = 0;
u8 shift;
reg_val = qed_rd(p_hwfn, p_ptt, PRS_REG_ENCAPSULATION_TYPE_EN);
shift = PRS_REG_ENCAPSULATION_TYPE_EN_ETH_OVER_GRE_ENABLE_SHIFT;
qed_set_tunnel_type_enable_bit(&reg_val, shift, eth_gre_enable);
shift = PRS_REG_ENCAPSULATION_TYPE_EN_IP_OVER_GRE_ENABLE_SHIFT;
qed_set_tunnel_type_enable_bit(&reg_val, shift, ip_gre_enable);
qed_wr(p_hwfn, p_ptt, PRS_REG_ENCAPSULATION_TYPE_EN, reg_val);
if (reg_val)
qed_wr(p_hwfn, p_ptt, PRS_REG_OUTPUT_FORMAT_4_0,
PRS_ETH_TUNN_FIC_FORMAT);
reg_val = qed_rd(p_hwfn, p_ptt, NIG_REG_ENC_TYPE_ENABLE);
shift = NIG_REG_ENC_TYPE_ENABLE_ETH_OVER_GRE_ENABLE_SHIFT;
qed_set_tunnel_type_enable_bit(&reg_val, shift, eth_gre_enable);
shift = NIG_REG_ENC_TYPE_ENABLE_IP_OVER_GRE_ENABLE_SHIFT;
qed_set_tunnel_type_enable_bit(&reg_val, shift, ip_gre_enable);
qed_wr(p_hwfn, p_ptt, NIG_REG_ENC_TYPE_ENABLE, reg_val);
qed_wr(p_hwfn, p_ptt, DORQ_REG_L2_EDPM_TUNNEL_GRE_ETH_EN,
eth_gre_enable ? 1 : 0);
qed_wr(p_hwfn, p_ptt, DORQ_REG_L2_EDPM_TUNNEL_GRE_IP_EN,
ip_gre_enable ? 1 : 0);
}
void qed_set_geneve_dest_port(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u16 dest_port)
{
qed_wr(p_hwfn, p_ptt, PRS_REG_NGE_PORT, dest_port);
qed_wr(p_hwfn, p_ptt, NIG_REG_NGE_PORT, dest_port);
qed_wr(p_hwfn, p_ptt, PBF_REG_NGE_PORT, dest_port);
}
void qed_set_geneve_enable(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
bool eth_geneve_enable, bool ip_geneve_enable)
{
unsigned long reg_val = 0;
u8 shift;
reg_val = qed_rd(p_hwfn, p_ptt, PRS_REG_ENCAPSULATION_TYPE_EN);
shift = PRS_REG_ENCAPSULATION_TYPE_EN_ETH_OVER_GENEVE_ENABLE_SHIFT;
qed_set_tunnel_type_enable_bit(&reg_val, shift, eth_geneve_enable);
shift = PRS_REG_ENCAPSULATION_TYPE_EN_IP_OVER_GENEVE_ENABLE_SHIFT;
qed_set_tunnel_type_enable_bit(&reg_val, shift, ip_geneve_enable);
qed_wr(p_hwfn, p_ptt, PRS_REG_ENCAPSULATION_TYPE_EN, reg_val);
if (reg_val)
qed_wr(p_hwfn, p_ptt, PRS_REG_OUTPUT_FORMAT_4_0,
PRS_ETH_TUNN_FIC_FORMAT);
qed_wr(p_hwfn, p_ptt, NIG_REG_NGE_ETH_ENABLE,
eth_geneve_enable ? 1 : 0);
qed_wr(p_hwfn, p_ptt, NIG_REG_NGE_IP_ENABLE, ip_geneve_enable ? 1 : 0);
reg_val = (ip_geneve_enable || eth_geneve_enable) ? 1 : 0;
qed_wr(p_hwfn, p_ptt, NIG_REG_NGE_COMP_VER, reg_val);
qed_wr(p_hwfn, p_ptt, PBF_REG_NGE_COMP_VER, reg_val);
qed_wr(p_hwfn, p_ptt, PRS_REG_NGE_COMP_VER, reg_val);
if (QED_IS_BB_B0(p_hwfn->cdev))
return;
qed_wr(p_hwfn, p_ptt, DORQ_REG_L2_EDPM_TUNNEL_NGE_ETH_EN,
eth_geneve_enable ? 1 : 0);
qed_wr(p_hwfn, p_ptt, DORQ_REG_L2_EDPM_TUNNEL_NGE_IP_EN,
ip_geneve_enable ? 1 : 0);
}
