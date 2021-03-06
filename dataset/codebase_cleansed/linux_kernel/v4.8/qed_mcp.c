bool qed_mcp_is_init(struct qed_hwfn *p_hwfn)
{
if (!p_hwfn->mcp_info || !p_hwfn->mcp_info->public_base)
return false;
return true;
}
void qed_mcp_cmd_port_init(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
u32 addr = SECTION_OFFSIZE_ADDR(p_hwfn->mcp_info->public_base,
PUBLIC_PORT);
u32 mfw_mb_offsize = qed_rd(p_hwfn, p_ptt, addr);
p_hwfn->mcp_info->port_addr = SECTION_ADDR(mfw_mb_offsize,
MFW_PORT(p_hwfn));
DP_VERBOSE(p_hwfn, QED_MSG_SP,
"port_addr = 0x%x, port_id 0x%02x\n",
p_hwfn->mcp_info->port_addr, MFW_PORT(p_hwfn));
}
void qed_mcp_read_mb(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
u32 length = MFW_DRV_MSG_MAX_DWORDS(p_hwfn->mcp_info->mfw_mb_length);
u32 tmp, i;
if (!p_hwfn->mcp_info->public_base)
return;
for (i = 0; i < length; i++) {
tmp = qed_rd(p_hwfn, p_ptt,
p_hwfn->mcp_info->mfw_mb_addr +
(i << 2) + sizeof(u32));
((u32 *)p_hwfn->mcp_info->mfw_mb_cur)[i] =
be32_to_cpu((__force __be32)tmp);
}
}
int qed_mcp_free(struct qed_hwfn *p_hwfn)
{
if (p_hwfn->mcp_info) {
kfree(p_hwfn->mcp_info->mfw_mb_cur);
kfree(p_hwfn->mcp_info->mfw_mb_shadow);
}
kfree(p_hwfn->mcp_info);
return 0;
}
static int qed_load_mcp_offsets(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
struct qed_mcp_info *p_info = p_hwfn->mcp_info;
u32 drv_mb_offsize, mfw_mb_offsize;
u32 mcp_pf_id = MCP_PF_ID(p_hwfn);
p_info->public_base = qed_rd(p_hwfn, p_ptt, MISC_REG_SHARED_MEM_ADDR);
if (!p_info->public_base)
return 0;
p_info->public_base |= GRCBASE_MCP;
drv_mb_offsize = qed_rd(p_hwfn, p_ptt,
SECTION_OFFSIZE_ADDR(p_info->public_base,
PUBLIC_DRV_MB));
p_info->drv_mb_addr = SECTION_ADDR(drv_mb_offsize, mcp_pf_id);
DP_VERBOSE(p_hwfn, QED_MSG_SP,
"drv_mb_offsiz = 0x%x, drv_mb_addr = 0x%x mcp_pf_id = 0x%x\n",
drv_mb_offsize, p_info->drv_mb_addr, mcp_pf_id);
mfw_mb_offsize = qed_rd(p_hwfn, p_ptt,
SECTION_OFFSIZE_ADDR(p_info->public_base,
PUBLIC_MFW_MB));
p_info->mfw_mb_addr = SECTION_ADDR(mfw_mb_offsize, mcp_pf_id);
p_info->mfw_mb_length = (u16)qed_rd(p_hwfn, p_ptt, p_info->mfw_mb_addr);
p_info->drv_mb_seq = DRV_MB_RD(p_hwfn, p_ptt, drv_mb_header) &
DRV_MSG_SEQ_NUMBER_MASK;
p_info->drv_pulse_seq = DRV_MB_RD(p_hwfn, p_ptt, drv_pulse_mb) &
DRV_PULSE_SEQ_MASK;
p_info->mcp_hist = (u16)qed_rd(p_hwfn, p_ptt, MISCS_REG_GENERIC_POR_0);
return 0;
}
int qed_mcp_cmd_init(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
struct qed_mcp_info *p_info;
u32 size;
p_hwfn->mcp_info = kzalloc(sizeof(*p_hwfn->mcp_info), GFP_KERNEL);
if (!p_hwfn->mcp_info)
goto err;
p_info = p_hwfn->mcp_info;
if (qed_load_mcp_offsets(p_hwfn, p_ptt) != 0) {
DP_NOTICE(p_hwfn, "MCP is not initialized\n");
return 0;
}
size = MFW_DRV_MSG_MAX_DWORDS(p_info->mfw_mb_length) * sizeof(u32);
p_info->mfw_mb_cur = kzalloc(size, GFP_KERNEL);
p_info->mfw_mb_shadow =
kzalloc(sizeof(u32) * MFW_DRV_MSG_MAX_DWORDS(
p_info->mfw_mb_length), GFP_KERNEL);
if (!p_info->mfw_mb_shadow || !p_info->mfw_mb_addr)
goto err;
spin_lock_init(&p_info->lock);
return 0;
err:
DP_NOTICE(p_hwfn, "Failed to allocate mcp memory\n");
qed_mcp_free(p_hwfn);
return -ENOMEM;
}
static int qed_mcp_mb_lock(struct qed_hwfn *p_hwfn,
u32 cmd)
{
spin_lock_bh(&p_hwfn->mcp_info->lock);
if (cmd == DRV_MSG_CODE_LOAD_DONE || cmd == DRV_MSG_CODE_UNLOAD_DONE)
p_hwfn->mcp_info->block_mb_sending = false;
if (p_hwfn->mcp_info->block_mb_sending) {
DP_NOTICE(p_hwfn,
"Trying to send a MFW mailbox command [0x%x] in parallel to [UN]LOAD_REQ. Aborting.\n",
cmd);
spin_unlock_bh(&p_hwfn->mcp_info->lock);
return -EBUSY;
}
if (cmd == DRV_MSG_CODE_LOAD_REQ || cmd == DRV_MSG_CODE_UNLOAD_REQ) {
p_hwfn->mcp_info->block_mb_sending = true;
spin_unlock_bh(&p_hwfn->mcp_info->lock);
}
return 0;
}
static void qed_mcp_mb_unlock(struct qed_hwfn *p_hwfn,
u32 cmd)
{
if (cmd != DRV_MSG_CODE_LOAD_REQ && cmd != DRV_MSG_CODE_UNLOAD_REQ)
spin_unlock_bh(&p_hwfn->mcp_info->lock);
}
int qed_mcp_reset(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
u32 seq = ++p_hwfn->mcp_info->drv_mb_seq;
u8 delay = CHIP_MCP_RESP_ITER_US;
u32 org_mcp_reset_seq, cnt = 0;
int rc = 0;
rc = qed_mcp_mb_lock(p_hwfn, DRV_MSG_CODE_MCP_RESET);
if (rc != 0)
return rc;
org_mcp_reset_seq = qed_rd(p_hwfn, p_ptt, MISCS_REG_GENERIC_POR_0);
DRV_MB_WR(p_hwfn, p_ptt, drv_mb_header,
(DRV_MSG_CODE_MCP_RESET | seq));
do {
udelay(delay);
} while ((org_mcp_reset_seq == qed_rd(p_hwfn, p_ptt,
MISCS_REG_GENERIC_POR_0)) &&
(cnt++ < QED_MCP_RESET_RETRIES));
if (org_mcp_reset_seq !=
qed_rd(p_hwfn, p_ptt, MISCS_REG_GENERIC_POR_0)) {
DP_VERBOSE(p_hwfn, QED_MSG_SP,
"MCP was reset after %d usec\n", cnt * delay);
} else {
DP_ERR(p_hwfn, "Failed to reset MCP\n");
rc = -EAGAIN;
}
qed_mcp_mb_unlock(p_hwfn, DRV_MSG_CODE_MCP_RESET);
return rc;
}
static int qed_do_mcp_cmd(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 cmd,
u32 param,
u32 *o_mcp_resp,
u32 *o_mcp_param)
{
u8 delay = CHIP_MCP_RESP_ITER_US;
u32 seq, cnt = 1, actual_mb_seq;
int rc = 0;
actual_mb_seq = DRV_MB_RD(p_hwfn, p_ptt, drv_mb_header) &
DRV_MSG_SEQ_NUMBER_MASK;
if (p_hwfn->mcp_info->mcp_hist !=
qed_rd(p_hwfn, p_ptt, MISCS_REG_GENERIC_POR_0)) {
DP_VERBOSE(p_hwfn, QED_MSG_SP, "Rereading MCP offsets\n");
qed_load_mcp_offsets(p_hwfn, p_ptt);
qed_mcp_cmd_port_init(p_hwfn, p_ptt);
}
seq = ++p_hwfn->mcp_info->drv_mb_seq;
DRV_MB_WR(p_hwfn, p_ptt, drv_mb_param, param);
DRV_MB_WR(p_hwfn, p_ptt, drv_mb_header, (cmd | seq));
DP_VERBOSE(p_hwfn, QED_MSG_SP,
"wrote command (%x) to MFW MB param 0x%08x\n",
(cmd | seq), param);
do {
udelay(delay);
*o_mcp_resp = DRV_MB_RD(p_hwfn, p_ptt, fw_mb_header);
} while ((seq != (*o_mcp_resp & FW_MSG_SEQ_NUMBER_MASK)) &&
(cnt++ < QED_DRV_MB_MAX_RETRIES));
DP_VERBOSE(p_hwfn, QED_MSG_SP,
"[after %d ms] read (%x) seq is (%x) from FW MB\n",
cnt * delay, *o_mcp_resp, seq);
if (seq == (*o_mcp_resp & FW_MSG_SEQ_NUMBER_MASK)) {
*o_mcp_resp &= FW_MSG_CODE_MASK;
*o_mcp_param = DRV_MB_RD(p_hwfn, p_ptt, fw_mb_param);
} else {
DP_ERR(p_hwfn, "MFW failed to respond!\n");
*o_mcp_resp = 0;
rc = -EAGAIN;
}
return rc;
}
static int qed_mcp_cmd_and_union(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct qed_mcp_mb_params *p_mb_params)
{
u32 union_data_addr;
int rc;
if (!qed_mcp_is_init(p_hwfn)) {
DP_NOTICE(p_hwfn, "MFW is not initialized !\n");
return -EBUSY;
}
union_data_addr = p_hwfn->mcp_info->drv_mb_addr +
offsetof(struct public_drv_mb, union_data);
rc = qed_mcp_mb_lock(p_hwfn, p_mb_params->cmd);
if (rc)
return rc;
if (p_mb_params->p_data_src != NULL)
qed_memcpy_to(p_hwfn, p_ptt, union_data_addr,
p_mb_params->p_data_src,
sizeof(*p_mb_params->p_data_src));
rc = qed_do_mcp_cmd(p_hwfn, p_ptt, p_mb_params->cmd,
p_mb_params->param, &p_mb_params->mcp_resp,
&p_mb_params->mcp_param);
if (p_mb_params->p_data_dst != NULL)
qed_memcpy_from(p_hwfn, p_ptt, p_mb_params->p_data_dst,
union_data_addr,
sizeof(*p_mb_params->p_data_dst));
qed_mcp_mb_unlock(p_hwfn, p_mb_params->cmd);
return rc;
}
int qed_mcp_cmd(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 cmd,
u32 param,
u32 *o_mcp_resp,
u32 *o_mcp_param)
{
struct qed_mcp_mb_params mb_params;
int rc;
memset(&mb_params, 0, sizeof(mb_params));
mb_params.cmd = cmd;
mb_params.param = param;
rc = qed_mcp_cmd_and_union(p_hwfn, p_ptt, &mb_params);
if (rc)
return rc;
*o_mcp_resp = mb_params.mcp_resp;
*o_mcp_param = mb_params.mcp_param;
return 0;
}
int qed_mcp_load_req(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *p_load_code)
{
struct qed_dev *cdev = p_hwfn->cdev;
struct qed_mcp_mb_params mb_params;
union drv_union_data union_data;
int rc;
memset(&mb_params, 0, sizeof(mb_params));
mb_params.cmd = DRV_MSG_CODE_LOAD_REQ;
mb_params.param = PDA_COMP | DRV_ID_MCP_HSI_VER_CURRENT |
cdev->drv_type;
memcpy(&union_data.ver_str, cdev->ver_str, MCP_DRV_VER_STR_SIZE);
mb_params.p_data_src = &union_data;
rc = qed_mcp_cmd_and_union(p_hwfn, p_ptt, &mb_params);
if (rc) {
DP_ERR(p_hwfn, "MCP response failure, aborting\n");
return rc;
}
*p_load_code = mb_params.mcp_resp;
if (!(*p_load_code) ||
((*p_load_code) == FW_MSG_CODE_DRV_LOAD_REFUSED_HSI) ||
((*p_load_code) == FW_MSG_CODE_DRV_LOAD_REFUSED_PDA) ||
((*p_load_code) == FW_MSG_CODE_DRV_LOAD_REFUSED_DIAG)) {
DP_ERR(p_hwfn, "MCP refused load request, aborting\n");
return -EBUSY;
}
return 0;
}
static void qed_mcp_handle_vf_flr(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
u32 addr = SECTION_OFFSIZE_ADDR(p_hwfn->mcp_info->public_base,
PUBLIC_PATH);
u32 mfw_path_offsize = qed_rd(p_hwfn, p_ptt, addr);
u32 path_addr = SECTION_ADDR(mfw_path_offsize,
QED_PATH_ID(p_hwfn));
u32 disabled_vfs[VF_MAX_STATIC / 32];
int i;
DP_VERBOSE(p_hwfn,
QED_MSG_SP,
"Reading Disabled VF information from [offset %08x], path_addr %08x\n",
mfw_path_offsize, path_addr);
for (i = 0; i < (VF_MAX_STATIC / 32); i++) {
disabled_vfs[i] = qed_rd(p_hwfn, p_ptt,
path_addr +
offsetof(struct public_path,
mcp_vf_disabled) +
sizeof(u32) * i);
DP_VERBOSE(p_hwfn, (QED_MSG_SP | QED_MSG_IOV),
"FLR-ed VFs [%08x,...,%08x] - %08x\n",
i * 32, (i + 1) * 32 - 1, disabled_vfs[i]);
}
if (qed_iov_mark_vf_flr(p_hwfn, disabled_vfs))
qed_schedule_iov(p_hwfn, QED_IOV_WQ_FLR_FLAG);
}
int qed_mcp_ack_vf_flr(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *vfs_to_ack)
{
u32 addr = SECTION_OFFSIZE_ADDR(p_hwfn->mcp_info->public_base,
PUBLIC_FUNC);
u32 mfw_func_offsize = qed_rd(p_hwfn, p_ptt, addr);
u32 func_addr = SECTION_ADDR(mfw_func_offsize,
MCP_PF_ID(p_hwfn));
struct qed_mcp_mb_params mb_params;
union drv_union_data union_data;
int rc;
int i;
for (i = 0; i < (VF_MAX_STATIC / 32); i++)
DP_VERBOSE(p_hwfn, (QED_MSG_SP | QED_MSG_IOV),
"Acking VFs [%08x,...,%08x] - %08x\n",
i * 32, (i + 1) * 32 - 1, vfs_to_ack[i]);
memset(&mb_params, 0, sizeof(mb_params));
mb_params.cmd = DRV_MSG_CODE_VF_DISABLED_DONE;
memcpy(&union_data.ack_vf_disabled, vfs_to_ack, VF_MAX_STATIC / 8);
mb_params.p_data_src = &union_data;
rc = qed_mcp_cmd_and_union(p_hwfn, p_ptt, &mb_params);
if (rc) {
DP_NOTICE(p_hwfn, "Failed to pass ACK for VF flr to MFW\n");
return -EBUSY;
}
for (i = 0; i < (VF_MAX_STATIC / 32); i++)
qed_wr(p_hwfn, p_ptt,
func_addr +
offsetof(struct public_func, drv_ack_vf_disabled) +
i * sizeof(u32), 0);
return rc;
}
static void qed_mcp_handle_transceiver_change(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
u32 transceiver_state;
transceiver_state = qed_rd(p_hwfn, p_ptt,
p_hwfn->mcp_info->port_addr +
offsetof(struct public_port,
transceiver_data));
DP_VERBOSE(p_hwfn,
(NETIF_MSG_HW | QED_MSG_SP),
"Received transceiver state update [0x%08x] from mfw [Addr 0x%x]\n",
transceiver_state,
(u32)(p_hwfn->mcp_info->port_addr +
offsetof(struct public_port,
transceiver_data)));
transceiver_state = GET_FIELD(transceiver_state,
ETH_TRANSCEIVER_STATE);
if (transceiver_state == ETH_TRANSCEIVER_STATE_PRESENT)
DP_NOTICE(p_hwfn, "Transceiver is present.\n");
else
DP_NOTICE(p_hwfn, "Transceiver is unplugged.\n");
}
static void qed_mcp_handle_link_change(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
bool b_reset)
{
struct qed_mcp_link_state *p_link;
u8 max_bw, min_bw;
u32 status = 0;
p_link = &p_hwfn->mcp_info->link_output;
memset(p_link, 0, sizeof(*p_link));
if (!b_reset) {
status = qed_rd(p_hwfn, p_ptt,
p_hwfn->mcp_info->port_addr +
offsetof(struct public_port, link_status));
DP_VERBOSE(p_hwfn, (NETIF_MSG_LINK | QED_MSG_SP),
"Received link update [0x%08x] from mfw [Addr 0x%x]\n",
status,
(u32)(p_hwfn->mcp_info->port_addr +
offsetof(struct public_port,
link_status)));
} else {
DP_VERBOSE(p_hwfn, NETIF_MSG_LINK,
"Resetting link indications\n");
return;
}
if (p_hwfn->b_drv_link_init)
p_link->link_up = !!(status & LINK_STATUS_LINK_UP);
else
p_link->link_up = false;
p_link->full_duplex = true;
switch ((status & LINK_STATUS_SPEED_AND_DUPLEX_MASK)) {
case LINK_STATUS_SPEED_AND_DUPLEX_100G:
p_link->speed = 100000;
break;
case LINK_STATUS_SPEED_AND_DUPLEX_50G:
p_link->speed = 50000;
break;
case LINK_STATUS_SPEED_AND_DUPLEX_40G:
p_link->speed = 40000;
break;
case LINK_STATUS_SPEED_AND_DUPLEX_25G:
p_link->speed = 25000;
break;
case LINK_STATUS_SPEED_AND_DUPLEX_20G:
p_link->speed = 20000;
break;
case LINK_STATUS_SPEED_AND_DUPLEX_10G:
p_link->speed = 10000;
break;
case LINK_STATUS_SPEED_AND_DUPLEX_1000THD:
p_link->full_duplex = false;
case LINK_STATUS_SPEED_AND_DUPLEX_1000TFD:
p_link->speed = 1000;
break;
default:
p_link->speed = 0;
}
if (p_link->link_up && p_link->speed)
p_link->line_speed = p_link->speed;
else
p_link->line_speed = 0;
max_bw = p_hwfn->mcp_info->func_info.bandwidth_max;
min_bw = p_hwfn->mcp_info->func_info.bandwidth_min;
__qed_configure_pf_max_bandwidth(p_hwfn, p_ptt, p_link, max_bw);
__qed_configure_pf_min_bandwidth(p_hwfn, p_ptt, p_link, min_bw);
qed_configure_vp_wfq_on_link_change(p_hwfn->cdev, p_link->min_pf_rate);
p_link->an = !!(status & LINK_STATUS_AUTO_NEGOTIATE_ENABLED);
p_link->an_complete = !!(status &
LINK_STATUS_AUTO_NEGOTIATE_COMPLETE);
p_link->parallel_detection = !!(status &
LINK_STATUS_PARALLEL_DETECTION_USED);
p_link->pfc_enabled = !!(status & LINK_STATUS_PFC_ENABLED);
p_link->partner_adv_speed |=
(status & LINK_STATUS_LINK_PARTNER_1000TFD_CAPABLE) ?
QED_LINK_PARTNER_SPEED_1G_FD : 0;
p_link->partner_adv_speed |=
(status & LINK_STATUS_LINK_PARTNER_1000THD_CAPABLE) ?
QED_LINK_PARTNER_SPEED_1G_HD : 0;
p_link->partner_adv_speed |=
(status & LINK_STATUS_LINK_PARTNER_10G_CAPABLE) ?
QED_LINK_PARTNER_SPEED_10G : 0;
p_link->partner_adv_speed |=
(status & LINK_STATUS_LINK_PARTNER_20G_CAPABLE) ?
QED_LINK_PARTNER_SPEED_20G : 0;
p_link->partner_adv_speed |=
(status & LINK_STATUS_LINK_PARTNER_40G_CAPABLE) ?
QED_LINK_PARTNER_SPEED_40G : 0;
p_link->partner_adv_speed |=
(status & LINK_STATUS_LINK_PARTNER_50G_CAPABLE) ?
QED_LINK_PARTNER_SPEED_50G : 0;
p_link->partner_adv_speed |=
(status & LINK_STATUS_LINK_PARTNER_100G_CAPABLE) ?
QED_LINK_PARTNER_SPEED_100G : 0;
p_link->partner_tx_flow_ctrl_en =
!!(status & LINK_STATUS_TX_FLOW_CONTROL_ENABLED);
p_link->partner_rx_flow_ctrl_en =
!!(status & LINK_STATUS_RX_FLOW_CONTROL_ENABLED);
switch (status & LINK_STATUS_LINK_PARTNER_FLOW_CONTROL_MASK) {
case LINK_STATUS_LINK_PARTNER_SYMMETRIC_PAUSE:
p_link->partner_adv_pause = QED_LINK_PARTNER_SYMMETRIC_PAUSE;
break;
case LINK_STATUS_LINK_PARTNER_ASYMMETRIC_PAUSE:
p_link->partner_adv_pause = QED_LINK_PARTNER_ASYMMETRIC_PAUSE;
break;
case LINK_STATUS_LINK_PARTNER_BOTH_PAUSE:
p_link->partner_adv_pause = QED_LINK_PARTNER_BOTH_PAUSE;
break;
default:
p_link->partner_adv_pause = 0;
}
p_link->sfp_tx_fault = !!(status & LINK_STATUS_SFP_TX_FAULT);
qed_link_update(p_hwfn);
}
int qed_mcp_set_link(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt, bool b_up)
{
struct qed_mcp_link_params *params = &p_hwfn->mcp_info->link_input;
struct qed_mcp_mb_params mb_params;
union drv_union_data union_data;
struct eth_phy_cfg *phy_cfg;
int rc = 0;
u32 cmd;
phy_cfg = &union_data.drv_phy_cfg;
memset(phy_cfg, 0, sizeof(*phy_cfg));
cmd = b_up ? DRV_MSG_CODE_INIT_PHY : DRV_MSG_CODE_LINK_RESET;
if (!params->speed.autoneg)
phy_cfg->speed = params->speed.forced_speed;
phy_cfg->pause |= (params->pause.autoneg) ? ETH_PAUSE_AUTONEG : 0;
phy_cfg->pause |= (params->pause.forced_rx) ? ETH_PAUSE_RX : 0;
phy_cfg->pause |= (params->pause.forced_tx) ? ETH_PAUSE_TX : 0;
phy_cfg->adv_speed = params->speed.advertised_speeds;
phy_cfg->loopback_mode = params->loopback_mode;
p_hwfn->b_drv_link_init = b_up;
if (b_up) {
DP_VERBOSE(p_hwfn, NETIF_MSG_LINK,
"Configuring Link: Speed 0x%08x, Pause 0x%08x, adv_speed 0x%08x, loopback 0x%08x, features 0x%08x\n",
phy_cfg->speed,
phy_cfg->pause,
phy_cfg->adv_speed,
phy_cfg->loopback_mode,
phy_cfg->feature_config_flags);
} else {
DP_VERBOSE(p_hwfn, NETIF_MSG_LINK,
"Resetting link\n");
}
memset(&mb_params, 0, sizeof(mb_params));
mb_params.cmd = cmd;
mb_params.p_data_src = &union_data;
rc = qed_mcp_cmd_and_union(p_hwfn, p_ptt, &mb_params);
if (rc) {
DP_ERR(p_hwfn, "MCP response failure, aborting\n");
return rc;
}
if (!b_up)
qed_mcp_handle_link_change(p_hwfn, p_ptt, true);
return 0;
}
static void qed_read_pf_bandwidth(struct qed_hwfn *p_hwfn,
struct public_func *p_shmem_info)
{
struct qed_mcp_function_info *p_info;
p_info = &p_hwfn->mcp_info->func_info;
p_info->bandwidth_min = (p_shmem_info->config &
FUNC_MF_CFG_MIN_BW_MASK) >>
FUNC_MF_CFG_MIN_BW_SHIFT;
if (p_info->bandwidth_min < 1 || p_info->bandwidth_min > 100) {
DP_INFO(p_hwfn,
"bandwidth minimum out of bounds [%02x]. Set to 1\n",
p_info->bandwidth_min);
p_info->bandwidth_min = 1;
}
p_info->bandwidth_max = (p_shmem_info->config &
FUNC_MF_CFG_MAX_BW_MASK) >>
FUNC_MF_CFG_MAX_BW_SHIFT;
if (p_info->bandwidth_max < 1 || p_info->bandwidth_max > 100) {
DP_INFO(p_hwfn,
"bandwidth maximum out of bounds [%02x]. Set to 100\n",
p_info->bandwidth_max);
p_info->bandwidth_max = 100;
}
}
static u32 qed_mcp_get_shmem_func(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct public_func *p_data,
int pfid)
{
u32 addr = SECTION_OFFSIZE_ADDR(p_hwfn->mcp_info->public_base,
PUBLIC_FUNC);
u32 mfw_path_offsize = qed_rd(p_hwfn, p_ptt, addr);
u32 func_addr = SECTION_ADDR(mfw_path_offsize, pfid);
u32 i, size;
memset(p_data, 0, sizeof(*p_data));
size = min_t(u32, sizeof(*p_data),
QED_SECTION_SIZE(mfw_path_offsize));
for (i = 0; i < size / sizeof(u32); i++)
((u32 *)p_data)[i] = qed_rd(p_hwfn, p_ptt,
func_addr + (i << 2));
return size;
}
int qed_hw_init_first_eth(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u8 *p_pf)
{
struct public_func shmem_info;
int i;
for (i = 0; i < NUM_OF_ENG_PFS(p_hwfn->cdev);
i += p_hwfn->cdev->num_ports_in_engines) {
qed_mcp_get_shmem_func(p_hwfn, p_ptt, &shmem_info,
MCP_PF_ID_BY_REL(p_hwfn, i));
if (shmem_info.config & FUNC_MF_CFG_FUNC_HIDE)
continue;
if ((shmem_info.config & FUNC_MF_CFG_PROTOCOL_MASK) ==
FUNC_MF_CFG_PROTOCOL_ETHERNET) {
*p_pf = (u8)i;
return 0;
}
}
DP_NOTICE(p_hwfn,
"Failed to find on port an ethernet interface in MF_SI mode\n");
return -EINVAL;
}
static void qed_mcp_update_bw(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
struct qed_mcp_function_info *p_info;
struct public_func shmem_info;
u32 resp = 0, param = 0;
qed_mcp_get_shmem_func(p_hwfn, p_ptt, &shmem_info,
MCP_PF_ID(p_hwfn));
qed_read_pf_bandwidth(p_hwfn, &shmem_info);
p_info = &p_hwfn->mcp_info->func_info;
qed_configure_pf_min_bandwidth(p_hwfn->cdev, p_info->bandwidth_min);
qed_configure_pf_max_bandwidth(p_hwfn->cdev, p_info->bandwidth_max);
qed_mcp_cmd(p_hwfn, p_ptt, DRV_MSG_CODE_BW_UPDATE_ACK, 0, &resp,
&param);
}
int qed_mcp_handle_events(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
struct qed_mcp_info *info = p_hwfn->mcp_info;
int rc = 0;
bool found = false;
u16 i;
DP_VERBOSE(p_hwfn, QED_MSG_SP, "Received message from MFW\n");
qed_mcp_read_mb(p_hwfn, p_ptt);
for (i = 0; i < info->mfw_mb_length; i++) {
if (info->mfw_mb_cur[i] == info->mfw_mb_shadow[i])
continue;
found = true;
DP_VERBOSE(p_hwfn, NETIF_MSG_LINK,
"Msg [%d] - old CMD 0x%02x, new CMD 0x%02x\n",
i, info->mfw_mb_shadow[i], info->mfw_mb_cur[i]);
switch (i) {
case MFW_DRV_MSG_LINK_CHANGE:
qed_mcp_handle_link_change(p_hwfn, p_ptt, false);
break;
case MFW_DRV_MSG_VF_DISABLED:
qed_mcp_handle_vf_flr(p_hwfn, p_ptt);
break;
case MFW_DRV_MSG_LLDP_DATA_UPDATED:
qed_dcbx_mib_update_event(p_hwfn, p_ptt,
QED_DCBX_REMOTE_LLDP_MIB);
break;
case MFW_DRV_MSG_DCBX_REMOTE_MIB_UPDATED:
qed_dcbx_mib_update_event(p_hwfn, p_ptt,
QED_DCBX_REMOTE_MIB);
break;
case MFW_DRV_MSG_DCBX_OPERATIONAL_MIB_UPDATED:
qed_dcbx_mib_update_event(p_hwfn, p_ptt,
QED_DCBX_OPERATIONAL_MIB);
break;
case MFW_DRV_MSG_TRANSCEIVER_STATE_CHANGE:
qed_mcp_handle_transceiver_change(p_hwfn, p_ptt);
break;
case MFW_DRV_MSG_BW_UPDATE:
qed_mcp_update_bw(p_hwfn, p_ptt);
break;
default:
DP_NOTICE(p_hwfn, "Unimplemented MFW message %d\n", i);
rc = -EINVAL;
}
}
for (i = 0; i < MFW_DRV_MSG_MAX_DWORDS(info->mfw_mb_length); i++) {
__be32 val = cpu_to_be32(((u32 *)info->mfw_mb_cur)[i]);
qed_wr(p_hwfn, p_ptt,
info->mfw_mb_addr + sizeof(u32) +
MFW_DRV_MSG_MAX_DWORDS(info->mfw_mb_length) *
sizeof(u32) + i * sizeof(u32),
(__force u32)val);
}
if (!found) {
DP_NOTICE(p_hwfn,
"Received an MFW message indication but no new message!\n");
rc = -EINVAL;
}
memcpy(info->mfw_mb_shadow, info->mfw_mb_cur, info->mfw_mb_length);
return rc;
}
int qed_mcp_get_mfw_ver(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *p_mfw_ver, u32 *p_running_bundle_id)
{
u32 global_offsize;
if (IS_VF(p_hwfn->cdev)) {
if (p_hwfn->vf_iov_info) {
struct pfvf_acquire_resp_tlv *p_resp;
p_resp = &p_hwfn->vf_iov_info->acquire_resp;
*p_mfw_ver = p_resp->pfdev_info.mfw_ver;
return 0;
} else {
DP_VERBOSE(p_hwfn,
QED_MSG_IOV,
"VF requested MFW version prior to ACQUIRE\n");
return -EINVAL;
}
}
global_offsize = qed_rd(p_hwfn, p_ptt,
SECTION_OFFSIZE_ADDR(p_hwfn->
mcp_info->public_base,
PUBLIC_GLOBAL));
*p_mfw_ver =
qed_rd(p_hwfn, p_ptt,
SECTION_ADDR(global_offsize,
0) + offsetof(struct public_global, mfw_ver));
if (p_running_bundle_id != NULL) {
*p_running_bundle_id = qed_rd(p_hwfn, p_ptt,
SECTION_ADDR(global_offsize, 0) +
offsetof(struct public_global,
running_bundle_id));
}
return 0;
}
int qed_mcp_get_media_type(struct qed_dev *cdev,
u32 *p_media_type)
{
struct qed_hwfn *p_hwfn = &cdev->hwfns[0];
struct qed_ptt *p_ptt;
if (IS_VF(cdev))
return -EINVAL;
if (!qed_mcp_is_init(p_hwfn)) {
DP_NOTICE(p_hwfn, "MFW is not initialized !\n");
return -EBUSY;
}
*p_media_type = MEDIA_UNSPECIFIED;
p_ptt = qed_ptt_acquire(p_hwfn);
if (!p_ptt)
return -EBUSY;
*p_media_type = qed_rd(p_hwfn, p_ptt, p_hwfn->mcp_info->port_addr +
offsetof(struct public_port, media_type));
qed_ptt_release(p_hwfn, p_ptt);
return 0;
}
static int
qed_mcp_get_shmem_proto(struct qed_hwfn *p_hwfn,
struct public_func *p_info,
enum qed_pci_personality *p_proto)
{
int rc = 0;
switch (p_info->config & FUNC_MF_CFG_PROTOCOL_MASK) {
case FUNC_MF_CFG_PROTOCOL_ETHERNET:
if (test_bit(QED_DEV_CAP_ROCE,
&p_hwfn->hw_info.device_capabilities))
*p_proto = QED_PCI_ETH_ROCE;
else
*p_proto = QED_PCI_ETH;
break;
case FUNC_MF_CFG_PROTOCOL_ISCSI:
*p_proto = QED_PCI_ISCSI;
break;
case FUNC_MF_CFG_PROTOCOL_ROCE:
DP_NOTICE(p_hwfn, "RoCE personality is not a valid value!\n");
rc = -EINVAL;
break;
default:
rc = -EINVAL;
}
return rc;
}
int qed_mcp_fill_shmem_func_info(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
struct qed_mcp_function_info *info;
struct public_func shmem_info;
qed_mcp_get_shmem_func(p_hwfn, p_ptt, &shmem_info,
MCP_PF_ID(p_hwfn));
info = &p_hwfn->mcp_info->func_info;
info->pause_on_host = (shmem_info.config &
FUNC_MF_CFG_PAUSE_ON_HOST_RING) ? 1 : 0;
if (qed_mcp_get_shmem_proto(p_hwfn, &shmem_info,
&info->protocol)) {
DP_ERR(p_hwfn, "Unknown personality %08x\n",
(u32)(shmem_info.config & FUNC_MF_CFG_PROTOCOL_MASK));
return -EINVAL;
}
qed_read_pf_bandwidth(p_hwfn, &shmem_info);
if (shmem_info.mac_upper || shmem_info.mac_lower) {
info->mac[0] = (u8)(shmem_info.mac_upper >> 8);
info->mac[1] = (u8)(shmem_info.mac_upper);
info->mac[2] = (u8)(shmem_info.mac_lower >> 24);
info->mac[3] = (u8)(shmem_info.mac_lower >> 16);
info->mac[4] = (u8)(shmem_info.mac_lower >> 8);
info->mac[5] = (u8)(shmem_info.mac_lower);
} else {
DP_NOTICE(p_hwfn, "MAC is 0 in shmem\n");
}
info->wwn_port = (u64)shmem_info.fcoe_wwn_port_name_upper |
(((u64)shmem_info.fcoe_wwn_port_name_lower) << 32);
info->wwn_node = (u64)shmem_info.fcoe_wwn_node_name_upper |
(((u64)shmem_info.fcoe_wwn_node_name_lower) << 32);
info->ovlan = (u16)(shmem_info.ovlan_stag & FUNC_MF_CFG_OV_STAG_MASK);
DP_VERBOSE(p_hwfn, (QED_MSG_SP | NETIF_MSG_IFUP),
"Read configuration from shmem: pause_on_host %02x protocol %02x BW [%02x - %02x] MAC %02x:%02x:%02x:%02x:%02x:%02x wwn port %llx node %llx ovlan %04x\n",
info->pause_on_host, info->protocol,
info->bandwidth_min, info->bandwidth_max,
info->mac[0], info->mac[1], info->mac[2],
info->mac[3], info->mac[4], info->mac[5],
info->wwn_port, info->wwn_node, info->ovlan);
return 0;
}
struct qed_mcp_link_params
*qed_mcp_get_link_params(struct qed_hwfn *p_hwfn)
{
if (!p_hwfn || !p_hwfn->mcp_info)
return NULL;
return &p_hwfn->mcp_info->link_input;
}
struct qed_mcp_link_state
*qed_mcp_get_link_state(struct qed_hwfn *p_hwfn)
{
if (!p_hwfn || !p_hwfn->mcp_info)
return NULL;
return &p_hwfn->mcp_info->link_output;
}
struct qed_mcp_link_capabilities
*qed_mcp_get_link_capabilities(struct qed_hwfn *p_hwfn)
{
if (!p_hwfn || !p_hwfn->mcp_info)
return NULL;
return &p_hwfn->mcp_info->link_capabilities;
}
int qed_mcp_drain(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
u32 resp = 0, param = 0;
int rc;
rc = qed_mcp_cmd(p_hwfn, p_ptt,
DRV_MSG_CODE_NIG_DRAIN, 1000,
&resp, &param);
msleep(1020);
return rc;
}
int qed_mcp_get_flash_size(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *p_flash_size)
{
u32 flash_size;
if (IS_VF(p_hwfn->cdev))
return -EINVAL;
flash_size = qed_rd(p_hwfn, p_ptt, MCP_REG_NVM_CFG4);
flash_size = (flash_size & MCP_REG_NVM_CFG4_FLASH_SIZE) >>
MCP_REG_NVM_CFG4_FLASH_SIZE_SHIFT;
flash_size = (1 << (flash_size + MCP_BYTES_PER_MBIT_SHIFT));
*p_flash_size = flash_size;
return 0;
}
int qed_mcp_config_vf_msix(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u8 vf_id, u8 num)
{
u32 resp = 0, param = 0, rc_param = 0;
int rc;
if (!IS_LEAD_HWFN(p_hwfn))
return 0;
num *= p_hwfn->cdev->num_hwfns;
param |= (vf_id << DRV_MB_PARAM_CFG_VF_MSIX_VF_ID_SHIFT) &
DRV_MB_PARAM_CFG_VF_MSIX_VF_ID_MASK;
param |= (num << DRV_MB_PARAM_CFG_VF_MSIX_SB_NUM_SHIFT) &
DRV_MB_PARAM_CFG_VF_MSIX_SB_NUM_MASK;
rc = qed_mcp_cmd(p_hwfn, p_ptt, DRV_MSG_CODE_CFG_VF_MSIX, param,
&resp, &rc_param);
if (resp != FW_MSG_CODE_DRV_CFG_VF_MSIX_DONE) {
DP_NOTICE(p_hwfn, "VF[%d]: MFW failed to set MSI-X\n", vf_id);
rc = -EINVAL;
} else {
DP_VERBOSE(p_hwfn, QED_MSG_IOV,
"Requested 0x%02x MSI-x interrupts from VF 0x%02x\n",
num, vf_id);
}
return rc;
}
int
qed_mcp_send_drv_version(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct qed_mcp_drv_version *p_ver)
{
struct drv_version_stc *p_drv_version;
struct qed_mcp_mb_params mb_params;
union drv_union_data union_data;
__be32 val;
u32 i;
int rc;
p_drv_version = &union_data.drv_version;
p_drv_version->version = p_ver->version;
for (i = 0; i < (MCP_DRV_VER_STR_SIZE - 4) / sizeof(u32); i++) {
val = cpu_to_be32(*((u32 *)&p_ver->name[i * sizeof(u32)]));
*(__be32 *)&p_drv_version->name[i * sizeof(u32)] = val;
}
memset(&mb_params, 0, sizeof(mb_params));
mb_params.cmd = DRV_MSG_CODE_SET_VERSION;
mb_params.p_data_src = &union_data;
rc = qed_mcp_cmd_and_union(p_hwfn, p_ptt, &mb_params);
if (rc)
DP_ERR(p_hwfn, "MCP response failure, aborting\n");
return rc;
}
int qed_mcp_set_led(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt,
enum qed_led_mode mode)
{
u32 resp = 0, param = 0, drv_mb_param;
int rc;
switch (mode) {
case QED_LED_MODE_ON:
drv_mb_param = DRV_MB_PARAM_SET_LED_MODE_ON;
break;
case QED_LED_MODE_OFF:
drv_mb_param = DRV_MB_PARAM_SET_LED_MODE_OFF;
break;
case QED_LED_MODE_RESTORE:
drv_mb_param = DRV_MB_PARAM_SET_LED_MODE_OPER;
break;
default:
DP_NOTICE(p_hwfn, "Invalid LED mode %d\n", mode);
return -EINVAL;
}
rc = qed_mcp_cmd(p_hwfn, p_ptt, DRV_MSG_CODE_SET_LED_MODE,
drv_mb_param, &resp, &param);
return rc;
}
int qed_mcp_bist_register_test(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt)
{
u32 drv_mb_param = 0, rsp, param;
int rc = 0;
drv_mb_param = (DRV_MB_PARAM_BIST_REGISTER_TEST <<
DRV_MB_PARAM_BIST_TEST_INDEX_SHIFT);
rc = qed_mcp_cmd(p_hwfn, p_ptt, DRV_MSG_CODE_BIST_TEST,
drv_mb_param, &rsp, &param);
if (rc)
return rc;
if (((rsp & FW_MSG_CODE_MASK) != FW_MSG_CODE_OK) ||
(param != DRV_MB_PARAM_BIST_RC_PASSED))
rc = -EAGAIN;
return rc;
}
int qed_mcp_bist_clock_test(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt)
{
u32 drv_mb_param, rsp, param;
int rc = 0;
drv_mb_param = (DRV_MB_PARAM_BIST_CLOCK_TEST <<
DRV_MB_PARAM_BIST_TEST_INDEX_SHIFT);
rc = qed_mcp_cmd(p_hwfn, p_ptt, DRV_MSG_CODE_BIST_TEST,
drv_mb_param, &rsp, &param);
if (rc)
return rc;
if (((rsp & FW_MSG_CODE_MASK) != FW_MSG_CODE_OK) ||
(param != DRV_MB_PARAM_BIST_RC_PASSED))
rc = -EAGAIN;
return rc;
}
