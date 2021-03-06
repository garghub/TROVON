static u32 bnx2x_bits_en(struct bnx2x *bp, u32 reg, u32 bits)
{
u32 val = REG_RD(bp, reg);
val |= bits;
REG_WR(bp, reg, val);
return val;
}
static u32 bnx2x_bits_dis(struct bnx2x *bp, u32 reg, u32 bits)
{
u32 val = REG_RD(bp, reg);
val &= ~bits;
REG_WR(bp, reg, val);
return val;
}
void bnx2x_ets_disabled(struct link_params *params)
{
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "ETS disabled configuration\n");
REG_WR(bp, NIG_REG_P0_TX_ARB_PRIORITY_CLIENT, 0x4688);
REG_WR(bp, NIG_REG_P0_TX_ARB_CLIENT_IS_STRICT, 0x7);
REG_WR(bp, NIG_REG_P0_TX_ARB_CLIENT_IS_SUBJECT2WFQ, 0);
REG_WR(bp, NIG_REG_P0_TX_ARB_NUM_STRICT_ARB_SLOTS, 0x100);
REG_WR(bp, NIG_REG_P0_TX_ARB_CLIENT_CREDIT_MAP, 0);
REG_WR(bp, NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_0, 0);
REG_WR(bp, NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_1, 0);
REG_WR(bp, NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_0, 0);
REG_WR(bp, NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_1, 0);
REG_WR(bp, PBF_REG_HIGH_PRIORITY_COS_NUM, 0);
REG_WR(bp, PBF_REG_ETS_ENABLED, 0);
REG_WR(bp, PBF_REG_COS0_WEIGHT, 0x2710);
REG_WR(bp, PBF_REG_COS1_WEIGHT, 0x2710);
REG_WR(bp, PBF_REG_COS0_UPPER_BOUND, 0x989680);
REG_WR(bp, PBF_REG_COS1_UPPER_BOUND, 0x989680);
REG_WR(bp, PBF_REG_NUM_STRICT_ARB_SLOTS, 0);
}
static void bnx2x_ets_bw_limit_common(const struct link_params *params)
{
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "ETS enabled BW limit configuration\n");
REG_WR(bp, NIG_REG_P0_TX_ARB_CLIENT_IS_SUBJECT2WFQ, 0x18);
REG_WR(bp, NIG_REG_P0_TX_ARB_CLIENT_CREDIT_MAP, 0x111A);
REG_WR(bp, NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_0,
ETS_BW_LIMIT_CREDIT_UPPER_BOUND);
REG_WR(bp, NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_1,
ETS_BW_LIMIT_CREDIT_UPPER_BOUND);
REG_WR(bp, PBF_REG_ETS_ENABLED, 1);
REG_WR(bp, PBF_REG_NUM_STRICT_ARB_SLOTS, 0);
REG_WR(bp, NIG_REG_P0_TX_ARB_CLIENT_IS_STRICT, 0x7);
REG_WR(bp, PBF_REG_COS0_UPPER_BOUND,
ETS_BW_LIMIT_CREDIT_UPPER_BOUND);
REG_WR(bp, PBF_REG_COS1_UPPER_BOUND,
ETS_BW_LIMIT_CREDIT_UPPER_BOUND);
}
void bnx2x_ets_bw_limit(const struct link_params *params, const u32 cos0_bw,
const u32 cos1_bw)
{
struct bnx2x *bp = params->bp;
const u32 total_bw = cos0_bw + cos1_bw;
u32 cos0_credit_weight = 0;
u32 cos1_credit_weight = 0;
DP(NETIF_MSG_LINK, "ETS enabled BW limit configuration\n");
if ((0 == total_bw) ||
(0 == cos0_bw) ||
(0 == cos1_bw)) {
DP(NETIF_MSG_LINK, "Total BW can't be zero\n");
return;
}
cos0_credit_weight = (cos0_bw * ETS_BW_LIMIT_CREDIT_WEIGHT)/
total_bw;
cos1_credit_weight = (cos1_bw * ETS_BW_LIMIT_CREDIT_WEIGHT)/
total_bw;
bnx2x_ets_bw_limit_common(params);
REG_WR(bp, NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_0, cos0_credit_weight);
REG_WR(bp, NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_1, cos1_credit_weight);
REG_WR(bp, PBF_REG_COS0_WEIGHT, cos0_credit_weight);
REG_WR(bp, PBF_REG_COS1_WEIGHT, cos1_credit_weight);
}
u8 bnx2x_ets_strict(const struct link_params *params, const u8 strict_cos)
{
struct bnx2x *bp = params->bp;
u32 val = 0;
DP(NETIF_MSG_LINK, "ETS enabled strict configuration\n");
REG_WR(bp, NIG_REG_P0_TX_ARB_CLIENT_IS_STRICT, 0x1F);
REG_WR(bp, NIG_REG_P0_TX_ARB_NUM_STRICT_ARB_SLOTS, 0x100);
REG_WR(bp, PBF_REG_ETS_ENABLED, 0);
REG_WR(bp, PBF_REG_NUM_STRICT_ARB_SLOTS, 0x100);
REG_WR(bp, PBF_REG_HIGH_PRIORITY_COS_NUM, strict_cos);
val = (0 == strict_cos) ? 0x2318 : 0x22E0;
REG_WR(bp, NIG_REG_P0_TX_ARB_PRIORITY_CLIENT, val);
return 0;
}
static void bnx2x_bmac2_get_pfc_stat(struct link_params *params,
u32 pfc_frames_sent[2],
u32 pfc_frames_received[2])
{
struct bnx2x *bp = params->bp;
u32 bmac_addr = params->port ? NIG_REG_INGRESS_BMAC1_MEM :
NIG_REG_INGRESS_BMAC0_MEM;
DP(NETIF_MSG_LINK, "pfc statistic read from BMAC\n");
REG_RD_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_TX_STAT_GTPP,
pfc_frames_sent, 2);
REG_RD_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_RX_STAT_GRPP,
pfc_frames_received, 2);
}
static void bnx2x_emac_get_pfc_stat(struct link_params *params,
u32 pfc_frames_sent[2],
u32 pfc_frames_received[2])
{
struct bnx2x *bp = params->bp;
u32 emac_base = params->port ? GRCBASE_EMAC1 : GRCBASE_EMAC0;
u32 val_xon = 0;
u32 val_xoff = 0;
DP(NETIF_MSG_LINK, "pfc statistic read from EMAC\n");
val_xoff = REG_RD(bp, emac_base +
EMAC_REG_RX_PFC_STATS_XOFF_RCVD);
val_xoff &= EMAC_REG_RX_PFC_STATS_XOFF_RCVD_COUNT;
val_xon = REG_RD(bp, emac_base + EMAC_REG_RX_PFC_STATS_XON_RCVD);
val_xon &= EMAC_REG_RX_PFC_STATS_XON_RCVD_COUNT;
pfc_frames_received[0] = val_xon + val_xoff;
val_xoff = REG_RD(bp, emac_base +
EMAC_REG_RX_PFC_STATS_XOFF_SENT);
val_xoff &= EMAC_REG_RX_PFC_STATS_XOFF_SENT_COUNT;
val_xon = REG_RD(bp, emac_base + EMAC_REG_RX_PFC_STATS_XON_SENT);
val_xon &= EMAC_REG_RX_PFC_STATS_XON_SENT_COUNT;
pfc_frames_sent[0] = val_xon + val_xoff;
}
void bnx2x_pfc_statistic(struct link_params *params, struct link_vars *vars,
u32 pfc_frames_sent[2],
u32 pfc_frames_received[2])
{
struct bnx2x *bp = params->bp;
u32 val = 0;
DP(NETIF_MSG_LINK, "pfc statistic\n");
if (!vars->link_up)
return;
val = REG_RD(bp, MISC_REG_RESET_REG_2);
if ((val & (MISC_REGISTERS_RESET_REG_2_RST_BMAC0 << params->port))
== 0) {
DP(NETIF_MSG_LINK, "About to read stats from EMAC\n");
bnx2x_emac_get_pfc_stat(params, pfc_frames_sent,
pfc_frames_received);
} else {
DP(NETIF_MSG_LINK, "About to read stats from BMAC\n");
bnx2x_bmac2_get_pfc_stat(params, pfc_frames_sent,
pfc_frames_received);
}
}
static void bnx2x_emac_init(struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u8 port = params->port;
u32 emac_base = port ? GRCBASE_EMAC1 : GRCBASE_EMAC0;
u32 val;
u16 timeout;
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_CLEAR,
(MISC_REGISTERS_RESET_REG_2_RST_EMAC0_HARD_CORE << port));
udelay(5);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_SET,
(MISC_REGISTERS_RESET_REG_2_RST_EMAC0_HARD_CORE << port));
val = REG_RD(bp, emac_base + EMAC_REG_EMAC_MODE);
EMAC_WR(bp, EMAC_REG_EMAC_MODE, (val | EMAC_MODE_RESET));
timeout = 200;
do {
val = REG_RD(bp, emac_base + EMAC_REG_EMAC_MODE);
DP(NETIF_MSG_LINK, "EMAC reset reg is %u\n", val);
if (!timeout) {
DP(NETIF_MSG_LINK, "EMAC timeout!\n");
return;
}
timeout--;
} while (val & EMAC_MODE_RESET);
val = ((params->mac_addr[0] << 8) |
params->mac_addr[1]);
EMAC_WR(bp, EMAC_REG_EMAC_MAC_MATCH, val);
val = ((params->mac_addr[2] << 24) |
(params->mac_addr[3] << 16) |
(params->mac_addr[4] << 8) |
params->mac_addr[5]);
EMAC_WR(bp, EMAC_REG_EMAC_MAC_MATCH + 4, val);
}
static u8 bnx2x_emac_enable(struct link_params *params,
struct link_vars *vars, u8 lb)
{
struct bnx2x *bp = params->bp;
u8 port = params->port;
u32 emac_base = port ? GRCBASE_EMAC1 : GRCBASE_EMAC0;
u32 val;
DP(NETIF_MSG_LINK, "enabling EMAC\n");
REG_WR(bp, NIG_REG_EGRESS_EMAC0_PORT + port*4, 1);
if (vars->phy_flags & PHY_XGXS_FLAG) {
u32 ser_lane = ((params->lane_config &
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_MASK) >>
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_SHIFT);
DP(NETIF_MSG_LINK, "XGXS\n");
REG_WR(bp, NIG_REG_XGXS_LANE_SEL_P0 + port*4, ser_lane);
REG_WR(bp, NIG_REG_XGXS_SERDES0_MODE_SEL + port*4, 1);
} else {
DP(NETIF_MSG_LINK, "SerDes\n");
REG_WR(bp, NIG_REG_XGXS_SERDES0_MODE_SEL + port*4, 0);
}
bnx2x_bits_en(bp, emac_base + EMAC_REG_EMAC_RX_MODE,
EMAC_RX_MODE_RESET);
bnx2x_bits_en(bp, emac_base + EMAC_REG_EMAC_TX_MODE,
EMAC_TX_MODE_RESET);
if (CHIP_REV_IS_SLOW(bp)) {
val = REG_RD(bp, emac_base + EMAC_REG_EMAC_MODE);
EMAC_WR(bp, EMAC_REG_EMAC_MODE, (val | EMAC_MODE_PORT_GMII));
} else {
bnx2x_bits_dis(bp, emac_base + EMAC_REG_EMAC_RX_MODE,
EMAC_RX_MODE_FLOW_EN);
bnx2x_bits_dis(bp, emac_base + EMAC_REG_EMAC_TX_MODE,
(EMAC_TX_MODE_EXT_PAUSE_EN |
EMAC_TX_MODE_FLOW_EN));
if (!(params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED)) {
if (vars->flow_ctrl & BNX2X_FLOW_CTRL_RX)
bnx2x_bits_en(bp, emac_base +
EMAC_REG_EMAC_RX_MODE,
EMAC_RX_MODE_FLOW_EN);
if (vars->flow_ctrl & BNX2X_FLOW_CTRL_TX)
bnx2x_bits_en(bp, emac_base +
EMAC_REG_EMAC_TX_MODE,
(EMAC_TX_MODE_EXT_PAUSE_EN |
EMAC_TX_MODE_FLOW_EN));
} else
bnx2x_bits_en(bp, emac_base + EMAC_REG_EMAC_TX_MODE,
EMAC_TX_MODE_FLOW_EN);
}
val = REG_RD(bp, emac_base + EMAC_REG_EMAC_RX_MODE);
val |= EMAC_RX_MODE_KEEP_VLAN_TAG | EMAC_RX_MODE_PROMISCUOUS;
EMAC_WR(bp, EMAC_REG_RX_PFC_MODE, 0);
if (params->feature_config_flags & FEATURE_CONFIG_PFC_ENABLED) {
DP(NETIF_MSG_LINK, "PFC is enabled\n");
EMAC_WR(bp, EMAC_REG_RX_PFC_MODE,
EMAC_REG_RX_PFC_MODE_RX_EN |
EMAC_REG_RX_PFC_MODE_TX_EN |
EMAC_REG_RX_PFC_MODE_PRIORITIES);
EMAC_WR(bp, EMAC_REG_RX_PFC_PARAM,
((0x0101 <<
EMAC_REG_RX_PFC_PARAM_OPCODE_BITSHIFT) |
(0x00ff <<
EMAC_REG_RX_PFC_PARAM_PRIORITY_EN_BITSHIFT)));
val |= EMAC_RX_MODE_KEEP_MAC_CONTROL;
}
EMAC_WR(bp, EMAC_REG_EMAC_RX_MODE, val);
val = REG_RD(bp, emac_base + EMAC_REG_EMAC_MODE);
if (lb)
val |= 0x810;
else
val &= ~0x810;
EMAC_WR(bp, EMAC_REG_EMAC_MODE, val);
REG_WR(bp, NIG_REG_NIG_EMAC0_EN + port*4, 1);
EMAC_WR(bp, EMAC_REG_EMAC_RX_MTU_SIZE,
(EMAC_RX_MTU_SIZE_JUMBO_ENA |
(ETH_MAX_JUMBO_PACKET_SIZE + ETH_OVREHEAD)));
REG_WR(bp, NIG_REG_NIG_INGRESS_EMAC0_NO_CRC + port*4, 0x1);
REG_WR(bp, NIG_REG_BMAC0_IN_EN + port*4, 0x0);
REG_WR(bp, NIG_REG_BMAC0_PAUSE_OUT_EN + port*4, 0x0);
REG_WR(bp, NIG_REG_BMAC0_OUT_EN + port*4, 0x0);
REG_WR(bp, NIG_REG_EMAC0_IN_EN + port*4, 0x1);
val = 0;
if ((params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED) ||
(vars->flow_ctrl & BNX2X_FLOW_CTRL_TX))
val = 1;
REG_WR(bp, NIG_REG_EMAC0_PAUSE_OUT_EN + port*4, val);
REG_WR(bp, NIG_REG_EGRESS_EMAC0_OUT_EN + port*4, 0x1);
REG_WR(bp, NIG_REG_BMAC0_REGS_OUT_EN + port*4, 0x0);
vars->mac_type = MAC_TYPE_EMAC;
return 0;
}
static void bnx2x_update_pfc_bmac1(struct link_params *params,
struct link_vars *vars)
{
u32 wb_data[2];
struct bnx2x *bp = params->bp;
u32 bmac_addr = params->port ? NIG_REG_INGRESS_BMAC1_MEM :
NIG_REG_INGRESS_BMAC0_MEM;
u32 val = 0x14;
if ((!(params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED)) &&
(vars->flow_ctrl & BNX2X_FLOW_CTRL_RX))
val |= (1<<5);
wb_data[0] = val;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC_REGISTER_RX_CONTROL, wb_data, 2);
val = 0xc0;
if (!(params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED) &&
(vars->flow_ctrl & BNX2X_FLOW_CTRL_TX))
val |= 0x800000;
wb_data[0] = val;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC_REGISTER_TX_CONTROL, wb_data, 2);
}
static void bnx2x_update_pfc_bmac2(struct link_params *params,
struct link_vars *vars,
u8 is_lb)
{
u32 wb_data[2];
struct bnx2x *bp = params->bp;
u32 bmac_addr = params->port ? NIG_REG_INGRESS_BMAC1_MEM :
NIG_REG_INGRESS_BMAC0_MEM;
u32 val = 0x14;
if ((!(params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED)) &&
(vars->flow_ctrl & BNX2X_FLOW_CTRL_RX))
val |= (1<<5);
wb_data[0] = val;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_RX_CONTROL, wb_data, 2);
udelay(30);
val = 0xc0;
if (!(params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED) &&
(vars->flow_ctrl & BNX2X_FLOW_CTRL_TX))
val |= 0x800000;
wb_data[0] = val;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_TX_CONTROL, wb_data, 2);
if (params->feature_config_flags & FEATURE_CONFIG_PFC_ENABLED) {
DP(NETIF_MSG_LINK, "PFC is enabled\n");
wb_data[0] = 0x0;
wb_data[0] |= (1<<0);
wb_data[0] |= (1<<1);
wb_data[0] |= (1<<2);
wb_data[0] |= (1<<3);
wb_data[0] |= (1<<5);
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_PFC_CONTROL,
wb_data, 2);
wb_data[0] &= ~(1<<2);
} else {
DP(NETIF_MSG_LINK, "PFC is disabled\n");
wb_data[0] = 0x8;
wb_data[1] = 0;
}
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_PFC_CONTROL, wb_data, 2);
val = 0x8000;
if (params->feature_config_flags & FEATURE_CONFIG_PFC_ENABLED)
val |= (1<<16);
wb_data[0] = val;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_TX_PAUSE_CONTROL,
wb_data, 2);
val = 0x3;
if (is_lb) {
val |= 0x4;
DP(NETIF_MSG_LINK, "enable bmac loopback\n");
}
if (params->feature_config_flags & FEATURE_CONFIG_PFC_ENABLED)
val |= ((1<<6)|(1<<5));
wb_data[0] = val;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_BMAC_CONTROL, wb_data, 2);
}
static void bnx2x_update_pfc_brb(struct link_params *params,
struct link_vars *vars,
struct bnx2x_nig_brb_pfc_port_params *pfc_params)
{
struct bnx2x *bp = params->bp;
int set_pfc = params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED;
u32 pause_xoff_th = PFC_BRB_MAC_PAUSE_XOFF_THRESHOLD_PAUSEABLE;
u32 pause_xon_th = PFC_BRB_MAC_PAUSE_XON_THRESHOLD_PAUSEABLE;
u32 full_xoff_th = PFC_BRB_MAC_FULL_XOFF_THRESHOLD_PAUSEABLE;
u32 full_xon_th = PFC_BRB_MAC_FULL_XON_THRESHOLD_PAUSEABLE;
if (set_pfc && pfc_params)
if (!pfc_params->cos0_pauseable) {
pause_xoff_th =
PFC_BRB_MAC_PAUSE_XOFF_THRESHOLD_NON_PAUSEABLE;
pause_xon_th =
PFC_BRB_MAC_PAUSE_XON_THRESHOLD_NON_PAUSEABLE;
full_xoff_th =
PFC_BRB_MAC_FULL_XOFF_THRESHOLD_NON_PAUSEABLE;
full_xon_th =
PFC_BRB_MAC_FULL_XON_THRESHOLD_NON_PAUSEABLE;
}
REG_WR(bp, BRB1_REG_PAUSE_0_XOFF_THRESHOLD_0 , pause_xoff_th);
REG_WR(bp, BRB1_REG_PAUSE_0_XON_THRESHOLD_0 , pause_xon_th);
REG_WR(bp, BRB1_REG_FULL_0_XOFF_THRESHOLD_0 , full_xoff_th);
REG_WR(bp, BRB1_REG_FULL_0_XON_THRESHOLD_0 , full_xon_th);
if (set_pfc && pfc_params) {
if (pfc_params->cos1_pauseable) {
pause_xoff_th =
PFC_BRB_MAC_PAUSE_XOFF_THRESHOLD_PAUSEABLE;
pause_xon_th =
PFC_BRB_MAC_PAUSE_XON_THRESHOLD_PAUSEABLE;
full_xoff_th =
PFC_BRB_MAC_FULL_XOFF_THRESHOLD_PAUSEABLE;
full_xon_th =
PFC_BRB_MAC_FULL_XON_THRESHOLD_PAUSEABLE;
} else {
pause_xoff_th =
PFC_BRB_MAC_PAUSE_XOFF_THRESHOLD_NON_PAUSEABLE;
pause_xon_th =
PFC_BRB_MAC_PAUSE_XON_THRESHOLD_NON_PAUSEABLE;
full_xoff_th =
PFC_BRB_MAC_FULL_XOFF_THRESHOLD_NON_PAUSEABLE;
full_xon_th =
PFC_BRB_MAC_FULL_XON_THRESHOLD_NON_PAUSEABLE;
}
REG_WR(bp, BRB1_REG_PAUSE_1_XOFF_THRESHOLD_0, pause_xoff_th);
REG_WR(bp, BRB1_REG_PAUSE_1_XON_THRESHOLD_0, pause_xon_th);
REG_WR(bp, BRB1_REG_FULL_1_XOFF_THRESHOLD_0, full_xoff_th);
REG_WR(bp, BRB1_REG_FULL_1_XON_THRESHOLD_0, full_xon_th);
}
}
static void bnx2x_update_pfc_nig(struct link_params *params,
struct link_vars *vars,
struct bnx2x_nig_brb_pfc_port_params *nig_params)
{
u32 xcm_mask = 0, ppp_enable = 0, pause_enable = 0, llfc_out_en = 0;
u32 llfc_enable = 0, xcm0_out_en = 0, p0_hwpfc_enable = 0;
u32 pkt_priority_to_cos = 0;
u32 val;
struct bnx2x *bp = params->bp;
int port = params->port;
int set_pfc = params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED;
DP(NETIF_MSG_LINK, "updating pfc nig parameters\n");
xcm_mask = REG_RD(bp,
port ? NIG_REG_LLH1_XCM_MASK :
NIG_REG_LLH0_XCM_MASK);
if (set_pfc) {
pause_enable = 0;
llfc_out_en = 0;
llfc_enable = 0;
ppp_enable = 1;
xcm_mask &= ~(port ? NIG_LLH1_XCM_MASK_REG_LLH1_XCM_MASK_BCN :
NIG_LLH0_XCM_MASK_REG_LLH0_XCM_MASK_BCN);
xcm0_out_en = 0;
p0_hwpfc_enable = 1;
} else {
if (nig_params) {
llfc_out_en = nig_params->llfc_out_en;
llfc_enable = nig_params->llfc_enable;
pause_enable = nig_params->pause_enable;
} else
pause_enable = 1;
xcm_mask |= (port ? NIG_LLH1_XCM_MASK_REG_LLH1_XCM_MASK_BCN :
NIG_LLH0_XCM_MASK_REG_LLH0_XCM_MASK_BCN);
xcm0_out_en = 1;
}
REG_WR(bp, port ? NIG_REG_LLFC_OUT_EN_1 :
NIG_REG_LLFC_OUT_EN_0, llfc_out_en);
REG_WR(bp, port ? NIG_REG_LLFC_ENABLE_1 :
NIG_REG_LLFC_ENABLE_0, llfc_enable);
REG_WR(bp, port ? NIG_REG_PAUSE_ENABLE_1 :
NIG_REG_PAUSE_ENABLE_0, pause_enable);
REG_WR(bp, port ? NIG_REG_PPP_ENABLE_1 :
NIG_REG_PPP_ENABLE_0, ppp_enable);
REG_WR(bp, port ? NIG_REG_LLH1_XCM_MASK :
NIG_REG_LLH0_XCM_MASK, xcm_mask);
REG_WR(bp, NIG_REG_LLFC_EGRESS_SRC_ENABLE_0, 0x7);
REG_WR(bp, NIG_REG_XCM0_OUT_EN, xcm0_out_en);
REG_WR(bp, NIG_REG_P0_HWPFC_ENABLE, p0_hwpfc_enable);
switch (vars->mac_type) {
case MAC_TYPE_EMAC:
val = 1;
break;
case MAC_TYPE_BMAC:
val = 0;
break;
default:
val = 0;
break;
}
REG_WR(bp, NIG_REG_EGRESS_EMAC0_PORT, val);
if (nig_params) {
pkt_priority_to_cos = nig_params->pkt_priority_to_cos;
REG_WR(bp, port ? NIG_REG_P1_RX_COS0_PRIORITY_MASK :
NIG_REG_P0_RX_COS0_PRIORITY_MASK,
nig_params->rx_cos0_priority_mask);
REG_WR(bp, port ? NIG_REG_P1_RX_COS1_PRIORITY_MASK :
NIG_REG_P0_RX_COS1_PRIORITY_MASK,
nig_params->rx_cos1_priority_mask);
REG_WR(bp, port ? NIG_REG_LLFC_HIGH_PRIORITY_CLASSES_1 :
NIG_REG_LLFC_HIGH_PRIORITY_CLASSES_0,
nig_params->llfc_high_priority_classes);
REG_WR(bp, port ? NIG_REG_LLFC_LOW_PRIORITY_CLASSES_1 :
NIG_REG_LLFC_LOW_PRIORITY_CLASSES_0,
nig_params->llfc_low_priority_classes);
}
REG_WR(bp, port ? NIG_REG_P1_PKT_PRIORITY_TO_COS :
NIG_REG_P0_PKT_PRIORITY_TO_COS,
pkt_priority_to_cos);
}
void bnx2x_update_pfc(struct link_params *params,
struct link_vars *vars,
struct bnx2x_nig_brb_pfc_port_params *pfc_params)
{
u32 val;
struct bnx2x *bp = params->bp;
bnx2x_update_pfc_nig(params, vars, pfc_params);
bnx2x_update_pfc_brb(params, vars, pfc_params);
if (!vars->link_up)
return;
val = REG_RD(bp, MISC_REG_RESET_REG_2);
if ((val & (MISC_REGISTERS_RESET_REG_2_RST_BMAC0 << params->port))
== 0) {
DP(NETIF_MSG_LINK, "About to update PFC in EMAC\n");
bnx2x_emac_enable(params, vars, 0);
return;
}
DP(NETIF_MSG_LINK, "About to update PFC in BMAC\n");
if (CHIP_IS_E2(bp))
bnx2x_update_pfc_bmac2(params, vars, 0);
else
bnx2x_update_pfc_bmac1(params, vars);
val = 0;
if ((params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED) ||
(vars->flow_ctrl & BNX2X_FLOW_CTRL_TX))
val = 1;
REG_WR(bp, NIG_REG_BMAC0_PAUSE_OUT_EN + params->port*4, val);
}
static u8 bnx2x_bmac1_enable(struct link_params *params,
struct link_vars *vars,
u8 is_lb)
{
struct bnx2x *bp = params->bp;
u8 port = params->port;
u32 bmac_addr = port ? NIG_REG_INGRESS_BMAC1_MEM :
NIG_REG_INGRESS_BMAC0_MEM;
u32 wb_data[2];
u32 val;
DP(NETIF_MSG_LINK, "Enabling BigMAC1\n");
wb_data[0] = 0x3c;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC_REGISTER_BMAC_XGXS_CONTROL,
wb_data, 2);
wb_data[0] = ((params->mac_addr[2] << 24) |
(params->mac_addr[3] << 16) |
(params->mac_addr[4] << 8) |
params->mac_addr[5]);
wb_data[1] = ((params->mac_addr[0] << 8) |
params->mac_addr[1]);
REG_WR_DMAE(bp, bmac_addr + BIGMAC_REGISTER_TX_SOURCE_ADDR, wb_data, 2);
val = 0x3;
if (is_lb) {
val |= 0x4;
DP(NETIF_MSG_LINK, "enable bmac loopback\n");
}
wb_data[0] = val;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC_REGISTER_BMAC_CONTROL, wb_data, 2);
wb_data[0] = ETH_MAX_JUMBO_PACKET_SIZE + ETH_OVREHEAD;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC_REGISTER_RX_MAX_SIZE, wb_data, 2);
bnx2x_update_pfc_bmac1(params, vars);
wb_data[0] = ETH_MAX_JUMBO_PACKET_SIZE + ETH_OVREHEAD;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC_REGISTER_TX_MAX_SIZE, wb_data, 2);
wb_data[0] = ETH_MAX_JUMBO_PACKET_SIZE + ETH_OVREHEAD;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC_REGISTER_CNT_MAX_SIZE, wb_data, 2);
wb_data[0] = 0x1000200;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC_REGISTER_RX_LLFC_MSG_FLDS,
wb_data, 2);
return 0;
}
static u8 bnx2x_bmac2_enable(struct link_params *params,
struct link_vars *vars,
u8 is_lb)
{
struct bnx2x *bp = params->bp;
u8 port = params->port;
u32 bmac_addr = port ? NIG_REG_INGRESS_BMAC1_MEM :
NIG_REG_INGRESS_BMAC0_MEM;
u32 wb_data[2];
DP(NETIF_MSG_LINK, "Enabling BigMAC2\n");
wb_data[0] = 0;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_BMAC_CONTROL, wb_data, 2);
udelay(30);
wb_data[0] = 0x3c;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_BMAC_XGXS_CONTROL,
wb_data, 2);
udelay(30);
wb_data[0] = ((params->mac_addr[2] << 24) |
(params->mac_addr[3] << 16) |
(params->mac_addr[4] << 8) |
params->mac_addr[5]);
wb_data[1] = ((params->mac_addr[0] << 8) |
params->mac_addr[1]);
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_TX_SOURCE_ADDR,
wb_data, 2);
udelay(30);
wb_data[0] = 0x1000200;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_RX_LLFC_MSG_FLDS,
wb_data, 2);
udelay(30);
wb_data[0] = ETH_MAX_JUMBO_PACKET_SIZE + ETH_OVREHEAD;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_RX_MAX_SIZE, wb_data, 2);
udelay(30);
wb_data[0] = ETH_MAX_JUMBO_PACKET_SIZE + ETH_OVREHEAD;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_TX_MAX_SIZE, wb_data, 2);
udelay(30);
wb_data[0] = ETH_MAX_JUMBO_PACKET_SIZE + ETH_OVREHEAD - 2;
wb_data[1] = 0;
REG_WR_DMAE(bp, bmac_addr + BIGMAC2_REGISTER_CNT_MAX_SIZE, wb_data, 2);
udelay(30);
bnx2x_update_pfc_bmac2(params, vars, is_lb);
return 0;
}
static u8 bnx2x_bmac_enable(struct link_params *params,
struct link_vars *vars,
u8 is_lb)
{
u8 rc, port = params->port;
struct bnx2x *bp = params->bp;
u32 val;
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_CLEAR,
(MISC_REGISTERS_RESET_REG_2_RST_BMAC0 << port));
msleep(1);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_SET,
(MISC_REGISTERS_RESET_REG_2_RST_BMAC0 << port));
REG_WR(bp, NIG_REG_BMAC0_REGS_OUT_EN + port*4, 0x1);
if (CHIP_IS_E2(bp))
rc = bnx2x_bmac2_enable(params, vars, is_lb);
else
rc = bnx2x_bmac1_enable(params, vars, is_lb);
REG_WR(bp, NIG_REG_XGXS_SERDES0_MODE_SEL + port*4, 0x1);
REG_WR(bp, NIG_REG_XGXS_LANE_SEL_P0 + port*4, 0x0);
REG_WR(bp, NIG_REG_EGRESS_EMAC0_PORT + port*4, 0x0);
val = 0;
if ((params->feature_config_flags &
FEATURE_CONFIG_PFC_ENABLED) ||
(vars->flow_ctrl & BNX2X_FLOW_CTRL_TX))
val = 1;
REG_WR(bp, NIG_REG_BMAC0_PAUSE_OUT_EN + port*4, val);
REG_WR(bp, NIG_REG_EGRESS_EMAC0_OUT_EN + port*4, 0x0);
REG_WR(bp, NIG_REG_EMAC0_IN_EN + port*4, 0x0);
REG_WR(bp, NIG_REG_EMAC0_PAUSE_OUT_EN + port*4, 0x0);
REG_WR(bp, NIG_REG_BMAC0_IN_EN + port*4, 0x1);
REG_WR(bp, NIG_REG_BMAC0_OUT_EN + port*4, 0x1);
vars->mac_type = MAC_TYPE_BMAC;
return rc;
}
static void bnx2x_update_mng(struct link_params *params, u32 link_status)
{
struct bnx2x *bp = params->bp;
REG_WR(bp, params->shmem_base +
offsetof(struct shmem_region,
port_mb[params->port].link_status), link_status);
}
static void bnx2x_bmac_rx_disable(struct bnx2x *bp, u8 port)
{
u32 bmac_addr = port ? NIG_REG_INGRESS_BMAC1_MEM :
NIG_REG_INGRESS_BMAC0_MEM;
u32 wb_data[2];
u32 nig_bmac_enable = REG_RD(bp, NIG_REG_BMAC0_REGS_OUT_EN + port*4);
if (REG_RD(bp, MISC_REG_RESET_REG_2) &
(MISC_REGISTERS_RESET_REG_2_RST_BMAC0 << port) &&
nig_bmac_enable) {
if (CHIP_IS_E2(bp)) {
REG_RD_DMAE(bp, bmac_addr +
BIGMAC2_REGISTER_BMAC_CONTROL,
wb_data, 2);
wb_data[0] &= ~BMAC_CONTROL_RX_ENABLE;
REG_WR_DMAE(bp, bmac_addr +
BIGMAC2_REGISTER_BMAC_CONTROL,
wb_data, 2);
} else {
REG_RD_DMAE(bp, bmac_addr +
BIGMAC_REGISTER_BMAC_CONTROL,
wb_data, 2);
wb_data[0] &= ~BMAC_CONTROL_RX_ENABLE;
REG_WR_DMAE(bp, bmac_addr +
BIGMAC_REGISTER_BMAC_CONTROL,
wb_data, 2);
}
msleep(1);
}
}
static u8 bnx2x_pbf_update(struct link_params *params, u32 flow_ctrl,
u32 line_speed)
{
struct bnx2x *bp = params->bp;
u8 port = params->port;
u32 init_crd, crd;
u32 count = 1000;
REG_WR(bp, PBF_REG_DISABLE_NEW_TASK_PROC_P0 + port*4, 0x1);
init_crd = REG_RD(bp, PBF_REG_P0_INIT_CRD + port*4);
crd = REG_RD(bp, PBF_REG_P0_CREDIT + port*8);
DP(NETIF_MSG_LINK, "init_crd 0x%x crd 0x%x\n", init_crd, crd);
while ((init_crd != crd) && count) {
msleep(5);
crd = REG_RD(bp, PBF_REG_P0_CREDIT + port*8);
count--;
}
crd = REG_RD(bp, PBF_REG_P0_CREDIT + port*8);
if (init_crd != crd) {
DP(NETIF_MSG_LINK, "BUG! init_crd 0x%x != crd 0x%x\n",
init_crd, crd);
return -EINVAL;
}
if (flow_ctrl & BNX2X_FLOW_CTRL_RX ||
line_speed == SPEED_10 ||
line_speed == SPEED_100 ||
line_speed == SPEED_1000 ||
line_speed == SPEED_2500) {
REG_WR(bp, PBF_REG_P0_PAUSE_ENABLE + port*4, 1);
REG_WR(bp, PBF_REG_P0_ARB_THRSH + port*4, 0);
init_crd = 778;
} else {
u32 thresh = (ETH_MAX_JUMBO_PACKET_SIZE +
ETH_OVREHEAD)/16;
REG_WR(bp, PBF_REG_P0_PAUSE_ENABLE + port*4, 0);
REG_WR(bp, PBF_REG_P0_ARB_THRSH + port*4, thresh);
switch (line_speed) {
case SPEED_10000:
init_crd = thresh + 553 - 22;
break;
case SPEED_12000:
init_crd = thresh + 664 - 22;
break;
case SPEED_13000:
init_crd = thresh + 742 - 22;
break;
case SPEED_16000:
init_crd = thresh + 778 - 22;
break;
default:
DP(NETIF_MSG_LINK, "Invalid line_speed 0x%x\n",
line_speed);
return -EINVAL;
}
}
REG_WR(bp, PBF_REG_P0_INIT_CRD + port*4, init_crd);
DP(NETIF_MSG_LINK, "PBF updated to speed %d credit %d\n",
line_speed, init_crd);
REG_WR(bp, PBF_REG_INIT_P0 + port*4, 0x1);
msleep(5);
REG_WR(bp, PBF_REG_INIT_P0 + port*4, 0x0);
REG_WR(bp, PBF_REG_DISABLE_NEW_TASK_PROC_P0 + port*4, 0x0);
return 0;
}
static u32 bnx2x_get_emac_base(struct bnx2x *bp,
u32 mdc_mdio_access, u8 port)
{
u32 emac_base = 0;
switch (mdc_mdio_access) {
case SHARED_HW_CFG_MDC_MDIO_ACCESS1_PHY_TYPE:
break;
case SHARED_HW_CFG_MDC_MDIO_ACCESS1_EMAC0:
if (REG_RD(bp, NIG_REG_PORT_SWAP))
emac_base = GRCBASE_EMAC1;
else
emac_base = GRCBASE_EMAC0;
break;
case SHARED_HW_CFG_MDC_MDIO_ACCESS1_EMAC1:
if (REG_RD(bp, NIG_REG_PORT_SWAP))
emac_base = GRCBASE_EMAC0;
else
emac_base = GRCBASE_EMAC1;
break;
case SHARED_HW_CFG_MDC_MDIO_ACCESS1_BOTH:
emac_base = (port) ? GRCBASE_EMAC1 : GRCBASE_EMAC0;
break;
case SHARED_HW_CFG_MDC_MDIO_ACCESS1_SWAPPED:
emac_base = (port) ? GRCBASE_EMAC0 : GRCBASE_EMAC1;
break;
default:
break;
}
return emac_base;
}
static u8 bnx2x_cl45_write(struct bnx2x *bp, struct bnx2x_phy *phy,
u8 devad, u16 reg, u16 val)
{
u32 tmp, saved_mode;
u8 i, rc = 0;
saved_mode = REG_RD(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_MODE);
tmp = saved_mode & ~(EMAC_MDIO_MODE_AUTO_POLL |
EMAC_MDIO_MODE_CLOCK_CNT);
tmp |= (EMAC_MDIO_MODE_CLAUSE_45 |
(49 << EMAC_MDIO_MODE_CLOCK_CNT_BITSHIFT));
REG_WR(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_MODE, tmp);
REG_RD(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_MODE);
udelay(40);
tmp = ((phy->addr << 21) | (devad << 16) | reg |
EMAC_MDIO_COMM_COMMAND_ADDRESS |
EMAC_MDIO_COMM_START_BUSY);
REG_WR(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_COMM, tmp);
for (i = 0; i < 50; i++) {
udelay(10);
tmp = REG_RD(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_COMM);
if (!(tmp & EMAC_MDIO_COMM_START_BUSY)) {
udelay(5);
break;
}
}
if (tmp & EMAC_MDIO_COMM_START_BUSY) {
DP(NETIF_MSG_LINK, "write phy register failed\n");
netdev_err(bp->dev, "MDC/MDIO access timeout\n");
rc = -EFAULT;
} else {
tmp = ((phy->addr << 21) | (devad << 16) | val |
EMAC_MDIO_COMM_COMMAND_WRITE_45 |
EMAC_MDIO_COMM_START_BUSY);
REG_WR(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_COMM, tmp);
for (i = 0; i < 50; i++) {
udelay(10);
tmp = REG_RD(bp, phy->mdio_ctrl +
EMAC_REG_EMAC_MDIO_COMM);
if (!(tmp & EMAC_MDIO_COMM_START_BUSY)) {
udelay(5);
break;
}
}
if (tmp & EMAC_MDIO_COMM_START_BUSY) {
DP(NETIF_MSG_LINK, "write phy register failed\n");
netdev_err(bp->dev, "MDC/MDIO access timeout\n");
rc = -EFAULT;
}
}
REG_WR(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_MODE, saved_mode);
return rc;
}
static u8 bnx2x_cl45_read(struct bnx2x *bp, struct bnx2x_phy *phy,
u8 devad, u16 reg, u16 *ret_val)
{
u32 val, saved_mode;
u16 i;
u8 rc = 0;
saved_mode = REG_RD(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_MODE);
val = saved_mode & ~((EMAC_MDIO_MODE_AUTO_POLL |
EMAC_MDIO_MODE_CLOCK_CNT));
val |= (EMAC_MDIO_MODE_CLAUSE_45 |
(49L << EMAC_MDIO_MODE_CLOCK_CNT_BITSHIFT));
REG_WR(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_MODE, val);
REG_RD(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_MODE);
udelay(40);
val = ((phy->addr << 21) | (devad << 16) | reg |
EMAC_MDIO_COMM_COMMAND_ADDRESS |
EMAC_MDIO_COMM_START_BUSY);
REG_WR(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_COMM, val);
for (i = 0; i < 50; i++) {
udelay(10);
val = REG_RD(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_COMM);
if (!(val & EMAC_MDIO_COMM_START_BUSY)) {
udelay(5);
break;
}
}
if (val & EMAC_MDIO_COMM_START_BUSY) {
DP(NETIF_MSG_LINK, "read phy register failed\n");
netdev_err(bp->dev, "MDC/MDIO access timeout\n");
*ret_val = 0;
rc = -EFAULT;
} else {
val = ((phy->addr << 21) | (devad << 16) |
EMAC_MDIO_COMM_COMMAND_READ_45 |
EMAC_MDIO_COMM_START_BUSY);
REG_WR(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_COMM, val);
for (i = 0; i < 50; i++) {
udelay(10);
val = REG_RD(bp, phy->mdio_ctrl +
EMAC_REG_EMAC_MDIO_COMM);
if (!(val & EMAC_MDIO_COMM_START_BUSY)) {
*ret_val = (u16)(val & EMAC_MDIO_COMM_DATA);
break;
}
}
if (val & EMAC_MDIO_COMM_START_BUSY) {
DP(NETIF_MSG_LINK, "read phy register failed\n");
netdev_err(bp->dev, "MDC/MDIO access timeout\n");
*ret_val = 0;
rc = -EFAULT;
}
}
REG_WR(bp, phy->mdio_ctrl + EMAC_REG_EMAC_MDIO_MODE, saved_mode);
return rc;
}
u8 bnx2x_phy_read(struct link_params *params, u8 phy_addr,
u8 devad, u16 reg, u16 *ret_val)
{
u8 phy_index;
for (phy_index = 0; phy_index < params->num_phys; phy_index++) {
if (params->phy[phy_index].addr == phy_addr) {
return bnx2x_cl45_read(params->bp,
&params->phy[phy_index], devad,
reg, ret_val);
}
}
return -EINVAL;
}
u8 bnx2x_phy_write(struct link_params *params, u8 phy_addr,
u8 devad, u16 reg, u16 val)
{
u8 phy_index;
for (phy_index = 0; phy_index < params->num_phys; phy_index++) {
if (params->phy[phy_index].addr == phy_addr) {
return bnx2x_cl45_write(params->bp,
&params->phy[phy_index], devad,
reg, val);
}
}
return -EINVAL;
}
static void bnx2x_set_aer_mmd_xgxs(struct link_params *params,
struct bnx2x_phy *phy)
{
u32 ser_lane;
u16 offset, aer_val;
struct bnx2x *bp = params->bp;
ser_lane = ((params->lane_config &
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_MASK) >>
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_SHIFT);
offset = phy->addr + ser_lane;
if (CHIP_IS_E2(bp))
aer_val = 0x3800 + offset - 1;
else
aer_val = 0x3800 + offset;
CL22_WR_OVER_CL45(bp, phy, MDIO_REG_BANK_AER_BLOCK,
MDIO_AER_BLOCK_AER_REG, aer_val);
}
static void bnx2x_set_aer_mmd_serdes(struct bnx2x *bp,
struct bnx2x_phy *phy)
{
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_AER_BLOCK,
MDIO_AER_BLOCK_AER_REG, 0x3800);
}
static void bnx2x_set_serdes_access(struct bnx2x *bp, u8 port)
{
u32 emac_base = (port) ? GRCBASE_EMAC1 : GRCBASE_EMAC0;
REG_WR(bp, NIG_REG_SERDES0_CTRL_MD_ST + port*0x10, 1);
REG_WR(bp, emac_base + EMAC_REG_EMAC_MDIO_COMM, 0x245f8000);
udelay(500);
REG_WR(bp, emac_base + EMAC_REG_EMAC_MDIO_COMM, 0x245d000f);
udelay(500);
REG_WR(bp, NIG_REG_SERDES0_CTRL_MD_ST + port*0x10, 0);
}
static void bnx2x_serdes_deassert(struct bnx2x *bp, u8 port)
{
u32 val;
DP(NETIF_MSG_LINK, "bnx2x_serdes_deassert\n");
val = SERDES_RESET_BITS << (port*16);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_3_CLEAR, val);
udelay(500);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_3_SET, val);
bnx2x_set_serdes_access(bp, port);
REG_WR(bp, NIG_REG_SERDES0_CTRL_MD_DEVAD + port*0x10,
DEFAULT_PHY_DEV_ADDR);
}
static void bnx2x_xgxs_deassert(struct link_params *params)
{
struct bnx2x *bp = params->bp;
u8 port;
u32 val;
DP(NETIF_MSG_LINK, "bnx2x_xgxs_deassert\n");
port = params->port;
val = XGXS_RESET_BITS << (port*16);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_3_CLEAR, val);
udelay(500);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_3_SET, val);
REG_WR(bp, NIG_REG_XGXS0_CTRL_MD_ST + port*0x18, 0);
REG_WR(bp, NIG_REG_XGXS0_CTRL_MD_DEVAD + port*0x18,
params->phy[INT_PHY].def_md_devad);
}
void bnx2x_link_status_update(struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u8 link_10g;
u8 port = params->port;
vars->link_status = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region,
port_mb[port].link_status));
vars->link_up = (vars->link_status & LINK_STATUS_LINK_UP);
if (vars->link_up) {
DP(NETIF_MSG_LINK, "phy link up\n");
vars->phy_link_up = 1;
vars->duplex = DUPLEX_FULL;
switch (vars->link_status &
LINK_STATUS_SPEED_AND_DUPLEX_MASK) {
case LINK_10THD:
vars->duplex = DUPLEX_HALF;
case LINK_10TFD:
vars->line_speed = SPEED_10;
break;
case LINK_100TXHD:
vars->duplex = DUPLEX_HALF;
case LINK_100T4:
case LINK_100TXFD:
vars->line_speed = SPEED_100;
break;
case LINK_1000THD:
vars->duplex = DUPLEX_HALF;
case LINK_1000TFD:
vars->line_speed = SPEED_1000;
break;
case LINK_2500THD:
vars->duplex = DUPLEX_HALF;
case LINK_2500TFD:
vars->line_speed = SPEED_2500;
break;
case LINK_10GTFD:
vars->line_speed = SPEED_10000;
break;
case LINK_12GTFD:
vars->line_speed = SPEED_12000;
break;
case LINK_12_5GTFD:
vars->line_speed = SPEED_12500;
break;
case LINK_13GTFD:
vars->line_speed = SPEED_13000;
break;
case LINK_15GTFD:
vars->line_speed = SPEED_15000;
break;
case LINK_16GTFD:
vars->line_speed = SPEED_16000;
break;
default:
break;
}
vars->flow_ctrl = 0;
if (vars->link_status & LINK_STATUS_TX_FLOW_CONTROL_ENABLED)
vars->flow_ctrl |= BNX2X_FLOW_CTRL_TX;
if (vars->link_status & LINK_STATUS_RX_FLOW_CONTROL_ENABLED)
vars->flow_ctrl |= BNX2X_FLOW_CTRL_RX;
if (!vars->flow_ctrl)
vars->flow_ctrl = BNX2X_FLOW_CTRL_NONE;
if (vars->line_speed &&
((vars->line_speed == SPEED_10) ||
(vars->line_speed == SPEED_100))) {
vars->phy_flags |= PHY_SGMII_FLAG;
} else {
vars->phy_flags &= ~PHY_SGMII_FLAG;
}
link_10g = ((vars->line_speed == SPEED_10000) ||
(vars->line_speed == SPEED_12000) ||
(vars->line_speed == SPEED_12500) ||
(vars->line_speed == SPEED_13000) ||
(vars->line_speed == SPEED_15000) ||
(vars->line_speed == SPEED_16000));
if (link_10g)
vars->mac_type = MAC_TYPE_BMAC;
else
vars->mac_type = MAC_TYPE_EMAC;
} else {
DP(NETIF_MSG_LINK, "phy link down\n");
vars->phy_link_up = 0;
vars->line_speed = 0;
vars->duplex = DUPLEX_FULL;
vars->flow_ctrl = BNX2X_FLOW_CTRL_NONE;
vars->mac_type = MAC_TYPE_NONE;
}
DP(NETIF_MSG_LINK, "link_status 0x%x phy_link_up %x\n",
vars->link_status, vars->phy_link_up);
DP(NETIF_MSG_LINK, "line_speed %x duplex %x flow_ctrl 0x%x\n",
vars->line_speed, vars->duplex, vars->flow_ctrl);
}
static void bnx2x_set_master_ln(struct link_params *params,
struct bnx2x_phy *phy)
{
struct bnx2x *bp = params->bp;
u16 new_master_ln, ser_lane;
ser_lane = ((params->lane_config &
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_MASK) >>
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_SHIFT);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_XGXS_BLOCK2,
MDIO_XGXS_BLOCK2_TEST_MODE_LANE,
&new_master_ln);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_XGXS_BLOCK2 ,
MDIO_XGXS_BLOCK2_TEST_MODE_LANE,
(new_master_ln | ser_lane));
}
static u8 bnx2x_reset_unicore(struct link_params *params,
struct bnx2x_phy *phy,
u8 set_serdes)
{
struct bnx2x *bp = params->bp;
u16 mii_control;
u16 i;
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL, &mii_control);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL,
(mii_control |
MDIO_COMBO_IEEO_MII_CONTROL_RESET));
if (set_serdes)
bnx2x_set_serdes_access(bp, params->port);
for (i = 0; i < MDIO_ACCESS_TIMEOUT; i++) {
udelay(5);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL,
&mii_control);
if (!(mii_control & MDIO_COMBO_IEEO_MII_CONTROL_RESET)) {
udelay(5);
return 0;
}
}
netdev_err(bp->dev, "Warning: PHY was not initialized,"
" Port %d\n",
params->port);
DP(NETIF_MSG_LINK, "BUG! XGXS is still in reset!\n");
return -EINVAL;
}
static void bnx2x_set_swap_lanes(struct link_params *params,
struct bnx2x_phy *phy)
{
struct bnx2x *bp = params->bp;
u16 ser_lane, rx_lane_swap, tx_lane_swap;
ser_lane = ((params->lane_config &
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_MASK) >>
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_SHIFT);
rx_lane_swap = ((params->lane_config &
PORT_HW_CFG_LANE_SWAP_CFG_RX_MASK) >>
PORT_HW_CFG_LANE_SWAP_CFG_RX_SHIFT);
tx_lane_swap = ((params->lane_config &
PORT_HW_CFG_LANE_SWAP_CFG_TX_MASK) >>
PORT_HW_CFG_LANE_SWAP_CFG_TX_SHIFT);
if (rx_lane_swap != 0x1b) {
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_XGXS_BLOCK2,
MDIO_XGXS_BLOCK2_RX_LN_SWAP,
(rx_lane_swap |
MDIO_XGXS_BLOCK2_RX_LN_SWAP_ENABLE |
MDIO_XGXS_BLOCK2_RX_LN_SWAP_FORCE_ENABLE));
} else {
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_XGXS_BLOCK2,
MDIO_XGXS_BLOCK2_RX_LN_SWAP, 0);
}
if (tx_lane_swap != 0x1b) {
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_XGXS_BLOCK2,
MDIO_XGXS_BLOCK2_TX_LN_SWAP,
(tx_lane_swap |
MDIO_XGXS_BLOCK2_TX_LN_SWAP_ENABLE));
} else {
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_XGXS_BLOCK2,
MDIO_XGXS_BLOCK2_TX_LN_SWAP, 0);
}
}
static void bnx2x_set_parallel_detection(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u16 control2;
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_A_1000X_CONTROL2,
&control2);
if (phy->speed_cap_mask & PORT_HW_CFG_SPEED_CAPABILITY_D0_1G)
control2 |= MDIO_SERDES_DIGITAL_A_1000X_CONTROL2_PRL_DT_EN;
else
control2 &= ~MDIO_SERDES_DIGITAL_A_1000X_CONTROL2_PRL_DT_EN;
DP(NETIF_MSG_LINK, "phy->speed_cap_mask = 0x%x, control2 = 0x%x\n",
phy->speed_cap_mask, control2);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_A_1000X_CONTROL2,
control2);
if ((phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_DIRECT) &&
(phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G)) {
DP(NETIF_MSG_LINK, "XGXS\n");
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_10G_PARALLEL_DETECT,
MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_LINK,
MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_LINK_CNT);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_10G_PARALLEL_DETECT,
MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_CONTROL,
&control2);
control2 |=
MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_CONTROL_PARDET10G_EN;
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_10G_PARALLEL_DETECT,
MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_CONTROL,
control2);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_XGXS_BLOCK2,
MDIO_XGXS_BLOCK2_UNICORE_MODE_10G,
MDIO_XGXS_BLOCK2_UNICORE_MODE_10G_CX4_XGXS |
MDIO_XGXS_BLOCK2_UNICORE_MODE_10G_HIGIG_XGXS);
}
}
static void bnx2x_set_autoneg(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars,
u8 enable_cl73)
{
struct bnx2x *bp = params->bp;
u16 reg_val;
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL, &reg_val);
if (vars->line_speed == SPEED_AUTO_NEG)
reg_val |= MDIO_COMBO_IEEO_MII_CONTROL_AN_EN;
else
reg_val &= ~(MDIO_COMBO_IEEO_MII_CONTROL_AN_EN |
MDIO_COMBO_IEEO_MII_CONTROL_RESTART_AN);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL, reg_val);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_A_1000X_CONTROL1, &reg_val);
reg_val &= ~(MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_SIGNAL_DETECT_EN |
MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_INVERT_SIGNAL_DETECT);
reg_val |= MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_FIBER_MODE;
if (vars->line_speed == SPEED_AUTO_NEG)
reg_val |= MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_AUTODET;
else
reg_val &= ~MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_AUTODET;
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_A_1000X_CONTROL1, reg_val);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_BAM_NEXT_PAGE,
MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL,
&reg_val);
if (vars->line_speed == SPEED_AUTO_NEG) {
reg_val |= (MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL_BAM_MODE |
MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL_TETON_AN);
} else {
reg_val &= ~(MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL_BAM_MODE |
MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL_TETON_AN);
}
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_BAM_NEXT_PAGE,
MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL,
reg_val);
if (enable_cl73) {
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_USERB0,
MDIO_CL73_USERB0_CL73_UCTRL,
0xe);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_USERB0,
MDIO_CL73_USERB0_CL73_BAM_CTRL1,
MDIO_CL73_USERB0_CL73_BAM_CTRL1_BAM_EN |
MDIO_CL73_USERB0_CL73_BAM_CTRL1_BAM_STATION_MNGR_EN |
MDIO_CL73_USERB0_CL73_BAM_CTRL1_BAM_NP_AFTER_BP_EN);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB1,
MDIO_CL73_IEEEB1_AN_ADV2,
&reg_val);
if (phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G)
reg_val |= MDIO_CL73_IEEEB1_AN_ADV2_ADVR_10G_KX4;
if (phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_1G)
reg_val |= MDIO_CL73_IEEEB1_AN_ADV2_ADVR_1000M_KX;
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB1,
MDIO_CL73_IEEEB1_AN_ADV2,
reg_val);
reg_val = MDIO_CL73_IEEEB0_CL73_AN_CONTROL_AN_EN;
} else
reg_val = 0;
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB0,
MDIO_CL73_IEEEB0_CL73_AN_CONTROL, reg_val);
}
static void bnx2x_program_serdes(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u16 reg_val;
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL, &reg_val);
reg_val &= ~(MDIO_COMBO_IEEO_MII_CONTROL_FULL_DUPLEX |
MDIO_COMBO_IEEO_MII_CONTROL_AN_EN |
MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_MASK);
if (phy->req_duplex == DUPLEX_FULL)
reg_val |= MDIO_COMBO_IEEO_MII_CONTROL_FULL_DUPLEX;
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL, reg_val);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_MISC1, &reg_val);
DP(NETIF_MSG_LINK, "MDIO_REG_BANK_SERDES_DIGITAL = 0x%x\n", reg_val);
reg_val &= ~(MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_MASK |
MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_SEL);
if (!((vars->line_speed == SPEED_1000) ||
(vars->line_speed == SPEED_100) ||
(vars->line_speed == SPEED_10))) {
reg_val |= (MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_156_25M |
MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_SEL);
if (vars->line_speed == SPEED_10000)
reg_val |=
MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_10G_CX4;
if (vars->line_speed == SPEED_13000)
reg_val |=
MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_13G;
}
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_MISC1, reg_val);
}
static void bnx2x_set_brcm_cl37_advertisment(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u16 val = 0;
if (phy->speed_cap_mask & PORT_HW_CFG_SPEED_CAPABILITY_D0_2_5G)
val |= MDIO_OVER_1G_UP1_2_5G;
if (phy->speed_cap_mask & PORT_HW_CFG_SPEED_CAPABILITY_D0_10G)
val |= MDIO_OVER_1G_UP1_10G;
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_OVER_1G,
MDIO_OVER_1G_UP1, val);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_OVER_1G,
MDIO_OVER_1G_UP3, 0x400);
}
static void bnx2x_calc_ieee_aneg_adv(struct bnx2x_phy *phy,
struct link_params *params, u16 *ieee_fc)
{
struct bnx2x *bp = params->bp;
*ieee_fc = MDIO_COMBO_IEEE0_AUTO_NEG_ADV_FULL_DUPLEX;
switch (phy->req_flow_ctrl) {
case BNX2X_FLOW_CTRL_AUTO:
if (params->req_fc_auto_adv == BNX2X_FLOW_CTRL_BOTH)
*ieee_fc |= MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH;
else
*ieee_fc |=
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC;
break;
case BNX2X_FLOW_CTRL_TX:
*ieee_fc |= MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC;
break;
case BNX2X_FLOW_CTRL_RX:
case BNX2X_FLOW_CTRL_BOTH:
*ieee_fc |= MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH;
break;
case BNX2X_FLOW_CTRL_NONE:
default:
*ieee_fc |= MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_NONE;
break;
}
DP(NETIF_MSG_LINK, "ieee_fc = 0x%x\n", *ieee_fc);
}
static void bnx2x_set_ieee_aneg_advertisment(struct bnx2x_phy *phy,
struct link_params *params,
u16 ieee_fc)
{
struct bnx2x *bp = params->bp;
u16 val;
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_AUTO_NEG_ADV, ieee_fc);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB1,
MDIO_CL73_IEEEB1_AN_ADV1, &val);
val &= ~MDIO_CL73_IEEEB1_AN_ADV1_PAUSE_BOTH;
val |= ((ieee_fc<<3) & MDIO_CL73_IEEEB1_AN_ADV1_PAUSE_MASK);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB1,
MDIO_CL73_IEEEB1_AN_ADV1, val);
}
static void bnx2x_restart_autoneg(struct bnx2x_phy *phy,
struct link_params *params,
u8 enable_cl73)
{
struct bnx2x *bp = params->bp;
u16 mii_control;
DP(NETIF_MSG_LINK, "bnx2x_restart_autoneg\n");
if (enable_cl73) {
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB0,
MDIO_CL73_IEEEB0_CL73_AN_CONTROL,
&mii_control);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB0,
MDIO_CL73_IEEEB0_CL73_AN_CONTROL,
(mii_control |
MDIO_CL73_IEEEB0_CL73_AN_CONTROL_AN_EN |
MDIO_CL73_IEEEB0_CL73_AN_CONTROL_RESTART_AN));
} else {
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL,
&mii_control);
DP(NETIF_MSG_LINK,
"bnx2x_restart_autoneg mii_control before = 0x%x\n",
mii_control);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL,
(mii_control |
MDIO_COMBO_IEEO_MII_CONTROL_AN_EN |
MDIO_COMBO_IEEO_MII_CONTROL_RESTART_AN));
}
}
static void bnx2x_initialize_sgmii_process(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u16 control1;
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_A_1000X_CONTROL1,
&control1);
control1 |= MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_INVERT_SIGNAL_DETECT;
control1 &= ~(MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_FIBER_MODE |
MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_AUTODET |
MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_MSTR_MODE);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_A_1000X_CONTROL1,
control1);
if (!(vars->line_speed == SPEED_AUTO_NEG)) {
u16 mii_control;
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL,
&mii_control);
mii_control &= ~(MDIO_COMBO_IEEO_MII_CONTROL_AN_EN |
MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_MASK|
MDIO_COMBO_IEEO_MII_CONTROL_FULL_DUPLEX);
switch (vars->line_speed) {
case SPEED_100:
mii_control |=
MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_100;
break;
case SPEED_1000:
mii_control |=
MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_1000;
break;
case SPEED_10:
break;
default:
DP(NETIF_MSG_LINK, "Invalid line_speed 0x%x\n",
vars->line_speed);
break;
}
if (phy->req_duplex == DUPLEX_FULL)
mii_control |=
MDIO_COMBO_IEEO_MII_CONTROL_FULL_DUPLEX;
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_MII_CONTROL,
mii_control);
} else {
bnx2x_restart_autoneg(phy, params, 0);
}
}
static void bnx2x_pause_resolve(struct link_vars *vars, u32 pause_result)
{
switch (pause_result) {
case 0xb:
vars->flow_ctrl = BNX2X_FLOW_CTRL_TX;
break;
case 0xe:
vars->flow_ctrl = BNX2X_FLOW_CTRL_RX;
break;
case 0x5:
case 0x7:
case 0xd:
case 0xf:
vars->flow_ctrl = BNX2X_FLOW_CTRL_BOTH;
break;
default:
break;
}
if (pause_result & (1<<0))
vars->link_status |= LINK_STATUS_LINK_PARTNER_SYMMETRIC_PAUSE;
if (pause_result & (1<<1))
vars->link_status |= LINK_STATUS_LINK_PARTNER_ASYMMETRIC_PAUSE;
}
static u8 bnx2x_direct_parallel_detect_used(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u16 pd_10g, status2_1000x;
if (phy->req_line_speed != SPEED_AUTO_NEG)
return 0;
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_A_1000X_STATUS2,
&status2_1000x);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_SERDES_DIGITAL,
MDIO_SERDES_DIGITAL_A_1000X_STATUS2,
&status2_1000x);
if (status2_1000x & MDIO_SERDES_DIGITAL_A_1000X_STATUS2_AN_DISABLED) {
DP(NETIF_MSG_LINK, "1G parallel detect link on port %d\n",
params->port);
return 1;
}
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_10G_PARALLEL_DETECT,
MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_STATUS,
&pd_10g);
if (pd_10g & MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_STATUS_PD_LINK) {
DP(NETIF_MSG_LINK, "10G parallel detect link on port %d\n",
params->port);
return 1;
}
return 0;
}
static void bnx2x_flow_ctrl_resolve(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars,
u32 gp_status)
{
struct bnx2x *bp = params->bp;
u16 ld_pause;
u16 lp_pause;
u16 pause_result;
vars->flow_ctrl = BNX2X_FLOW_CTRL_NONE;
if (phy->req_flow_ctrl != BNX2X_FLOW_CTRL_AUTO)
vars->flow_ctrl = phy->req_flow_ctrl;
else if (phy->req_line_speed != SPEED_AUTO_NEG)
vars->flow_ctrl = params->req_fc_auto_adv;
else if ((gp_status & MDIO_AN_CL73_OR_37_COMPLETE) &&
(!(vars->phy_flags & PHY_SGMII_FLAG))) {
if (bnx2x_direct_parallel_detect_used(phy, params)) {
vars->flow_ctrl = params->req_fc_auto_adv;
return;
}
if ((gp_status &
(MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_AUTONEG_COMPLETE |
MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_MR_LP_NP_AN_ABLE)) ==
(MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_AUTONEG_COMPLETE |
MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_MR_LP_NP_AN_ABLE)) {
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB1,
MDIO_CL73_IEEEB1_AN_ADV1,
&ld_pause);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB1,
MDIO_CL73_IEEEB1_AN_LP_ADV1,
&lp_pause);
pause_result = (ld_pause &
MDIO_CL73_IEEEB1_AN_ADV1_PAUSE_MASK)
>> 8;
pause_result |= (lp_pause &
MDIO_CL73_IEEEB1_AN_LP_ADV1_PAUSE_MASK)
>> 10;
DP(NETIF_MSG_LINK, "pause_result CL73 0x%x\n",
pause_result);
} else {
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_AUTO_NEG_ADV,
&ld_pause);
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_COMBO_IEEE0,
MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1,
&lp_pause);
pause_result = (ld_pause &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_MASK)>>5;
pause_result |= (lp_pause &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_MASK)>>7;
DP(NETIF_MSG_LINK, "pause_result CL37 0x%x\n",
pause_result);
}
bnx2x_pause_resolve(vars, pause_result);
}
DP(NETIF_MSG_LINK, "flow_ctrl 0x%x\n", vars->flow_ctrl);
}
static void bnx2x_check_fallback_to_cl37(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u16 rx_status, ustat_val, cl37_fsm_recieved;
DP(NETIF_MSG_LINK, "bnx2x_check_fallback_to_cl37\n");
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_RX0,
MDIO_RX0_RX_STATUS,
&rx_status);
if ((rx_status & MDIO_RX0_RX_STATUS_SIGDET) !=
(MDIO_RX0_RX_STATUS_SIGDET)) {
DP(NETIF_MSG_LINK, "Signal is not detected. Restoring CL73."
"rx_status(0x80b0) = 0x%x\n", rx_status);
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB0,
MDIO_CL73_IEEEB0_CL73_AN_CONTROL,
MDIO_CL73_IEEEB0_CL73_AN_CONTROL_AN_EN);
return;
}
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_USERB0,
MDIO_CL73_USERB0_CL73_USTAT1,
&ustat_val);
if ((ustat_val &
(MDIO_CL73_USERB0_CL73_USTAT1_LINK_STATUS_CHECK |
MDIO_CL73_USERB0_CL73_USTAT1_AN_GOOD_CHECK_BAM37)) !=
(MDIO_CL73_USERB0_CL73_USTAT1_LINK_STATUS_CHECK |
MDIO_CL73_USERB0_CL73_USTAT1_AN_GOOD_CHECK_BAM37)) {
DP(NETIF_MSG_LINK, "CL73 state-machine is not stable. "
"ustat_val(0x8371) = 0x%x\n", ustat_val);
return;
}
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_REMOTE_PHY,
MDIO_REMOTE_PHY_MISC_RX_STATUS,
&cl37_fsm_recieved);
if ((cl37_fsm_recieved &
(MDIO_REMOTE_PHY_MISC_RX_STATUS_CL37_FSM_RECEIVED_OVER1G_MSG |
MDIO_REMOTE_PHY_MISC_RX_STATUS_CL37_FSM_RECEIVED_BRCM_OUI_MSG)) !=
(MDIO_REMOTE_PHY_MISC_RX_STATUS_CL37_FSM_RECEIVED_OVER1G_MSG |
MDIO_REMOTE_PHY_MISC_RX_STATUS_CL37_FSM_RECEIVED_BRCM_OUI_MSG)) {
DP(NETIF_MSG_LINK, "No CL37 FSM were received. "
"misc_rx_status(0x8330) = 0x%x\n",
cl37_fsm_recieved);
return;
}
CL22_WR_OVER_CL45(bp, phy,
MDIO_REG_BANK_CL73_IEEEB0,
MDIO_CL73_IEEEB0_CL73_AN_CONTROL,
0);
bnx2x_restart_autoneg(phy, params, 0);
DP(NETIF_MSG_LINK, "Disabling CL73, and restarting CL37 autoneg\n");
}
static void bnx2x_xgxs_an_resolve(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars,
u32 gp_status)
{
if (gp_status & MDIO_AN_CL73_OR_37_COMPLETE)
vars->link_status |=
LINK_STATUS_AUTO_NEGOTIATE_COMPLETE;
if (bnx2x_direct_parallel_detect_used(phy, params))
vars->link_status |=
LINK_STATUS_PARALLEL_DETECTION_USED;
}
static u8 bnx2x_link_settings_status(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u16 new_line_speed, gp_status;
u8 rc = 0;
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_GP_STATUS,
MDIO_GP_STATUS_TOP_AN_STATUS1,
&gp_status);
if (phy->req_line_speed == SPEED_AUTO_NEG)
vars->link_status |= LINK_STATUS_AUTO_NEGOTIATE_ENABLED;
if (gp_status & MDIO_GP_STATUS_TOP_AN_STATUS1_LINK_STATUS) {
DP(NETIF_MSG_LINK, "phy link up gp_status=0x%x\n",
gp_status);
vars->phy_link_up = 1;
vars->link_status |= LINK_STATUS_LINK_UP;
if (gp_status & MDIO_GP_STATUS_TOP_AN_STATUS1_DUPLEX_STATUS)
vars->duplex = DUPLEX_FULL;
else
vars->duplex = DUPLEX_HALF;
if (SINGLE_MEDIA_DIRECT(params)) {
bnx2x_flow_ctrl_resolve(phy, params, vars, gp_status);
if (phy->req_line_speed == SPEED_AUTO_NEG)
bnx2x_xgxs_an_resolve(phy, params, vars,
gp_status);
}
switch (gp_status & GP_STATUS_SPEED_MASK) {
case GP_STATUS_10M:
new_line_speed = SPEED_10;
if (vars->duplex == DUPLEX_FULL)
vars->link_status |= LINK_10TFD;
else
vars->link_status |= LINK_10THD;
break;
case GP_STATUS_100M:
new_line_speed = SPEED_100;
if (vars->duplex == DUPLEX_FULL)
vars->link_status |= LINK_100TXFD;
else
vars->link_status |= LINK_100TXHD;
break;
case GP_STATUS_1G:
case GP_STATUS_1G_KX:
new_line_speed = SPEED_1000;
if (vars->duplex == DUPLEX_FULL)
vars->link_status |= LINK_1000TFD;
else
vars->link_status |= LINK_1000THD;
break;
case GP_STATUS_2_5G:
new_line_speed = SPEED_2500;
if (vars->duplex == DUPLEX_FULL)
vars->link_status |= LINK_2500TFD;
else
vars->link_status |= LINK_2500THD;
break;
case GP_STATUS_5G:
case GP_STATUS_6G:
DP(NETIF_MSG_LINK,
"link speed unsupported gp_status 0x%x\n",
gp_status);
return -EINVAL;
case GP_STATUS_10G_KX4:
case GP_STATUS_10G_HIG:
case GP_STATUS_10G_CX4:
new_line_speed = SPEED_10000;
vars->link_status |= LINK_10GTFD;
break;
case GP_STATUS_12G_HIG:
new_line_speed = SPEED_12000;
vars->link_status |= LINK_12GTFD;
break;
case GP_STATUS_12_5G:
new_line_speed = SPEED_12500;
vars->link_status |= LINK_12_5GTFD;
break;
case GP_STATUS_13G:
new_line_speed = SPEED_13000;
vars->link_status |= LINK_13GTFD;
break;
case GP_STATUS_15G:
new_line_speed = SPEED_15000;
vars->link_status |= LINK_15GTFD;
break;
case GP_STATUS_16G:
new_line_speed = SPEED_16000;
vars->link_status |= LINK_16GTFD;
break;
default:
DP(NETIF_MSG_LINK,
"link speed unsupported gp_status 0x%x\n",
gp_status);
return -EINVAL;
}
vars->line_speed = new_line_speed;
} else {
DP(NETIF_MSG_LINK, "phy link down\n");
vars->phy_link_up = 0;
vars->duplex = DUPLEX_FULL;
vars->flow_ctrl = BNX2X_FLOW_CTRL_NONE;
vars->mac_type = MAC_TYPE_NONE;
if ((phy->req_line_speed == SPEED_AUTO_NEG) &&
SINGLE_MEDIA_DIRECT(params)) {
bnx2x_check_fallback_to_cl37(phy, params);
}
}
DP(NETIF_MSG_LINK, "gp_status 0x%x phy_link_up %x line_speed %x\n",
gp_status, vars->phy_link_up, vars->line_speed);
DP(NETIF_MSG_LINK, "duplex %x flow_ctrl 0x%x link_status 0x%x\n",
vars->duplex, vars->flow_ctrl, vars->link_status);
return rc;
}
static void bnx2x_set_gmii_tx_driver(struct link_params *params)
{
struct bnx2x *bp = params->bp;
struct bnx2x_phy *phy = &params->phy[INT_PHY];
u16 lp_up2;
u16 tx_driver;
u16 bank;
CL22_RD_OVER_CL45(bp, phy,
MDIO_REG_BANK_OVER_1G,
MDIO_OVER_1G_LP_UP2, &lp_up2);
lp_up2 = (((lp_up2 & MDIO_OVER_1G_LP_UP2_PREEMPHASIS_MASK) >>
MDIO_OVER_1G_LP_UP2_PREEMPHASIS_SHIFT) <<
MDIO_TX0_TX_DRIVER_PREEMPHASIS_SHIFT);
if (lp_up2 == 0)
return;
for (bank = MDIO_REG_BANK_TX0; bank <= MDIO_REG_BANK_TX3;
bank += (MDIO_REG_BANK_TX1 - MDIO_REG_BANK_TX0)) {
CL22_RD_OVER_CL45(bp, phy,
bank,
MDIO_TX0_TX_DRIVER, &tx_driver);
if (lp_up2 !=
(tx_driver & MDIO_TX0_TX_DRIVER_PREEMPHASIS_MASK)) {
tx_driver &= ~MDIO_TX0_TX_DRIVER_PREEMPHASIS_MASK;
tx_driver |= lp_up2;
CL22_WR_OVER_CL45(bp, phy,
bank,
MDIO_TX0_TX_DRIVER, tx_driver);
}
}
}
static u8 bnx2x_emac_program(struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u8 port = params->port;
u16 mode = 0;
DP(NETIF_MSG_LINK, "setting link speed & duplex\n");
bnx2x_bits_dis(bp, GRCBASE_EMAC0 + port*0x400 +
EMAC_REG_EMAC_MODE,
(EMAC_MODE_25G_MODE |
EMAC_MODE_PORT_MII_10M |
EMAC_MODE_HALF_DUPLEX));
switch (vars->line_speed) {
case SPEED_10:
mode |= EMAC_MODE_PORT_MII_10M;
break;
case SPEED_100:
mode |= EMAC_MODE_PORT_MII;
break;
case SPEED_1000:
mode |= EMAC_MODE_PORT_GMII;
break;
case SPEED_2500:
mode |= (EMAC_MODE_25G_MODE | EMAC_MODE_PORT_GMII);
break;
default:
DP(NETIF_MSG_LINK, "Invalid line_speed 0x%x\n",
vars->line_speed);
return -EINVAL;
}
if (vars->duplex == DUPLEX_HALF)
mode |= EMAC_MODE_HALF_DUPLEX;
bnx2x_bits_en(bp,
GRCBASE_EMAC0 + port*0x400 + EMAC_REG_EMAC_MODE,
mode);
bnx2x_set_led(params, vars, LED_MODE_OPER, vars->line_speed);
return 0;
}
static void bnx2x_set_preemphasis(struct bnx2x_phy *phy,
struct link_params *params)
{
u16 bank, i = 0;
struct bnx2x *bp = params->bp;
for (bank = MDIO_REG_BANK_RX0, i = 0; bank <= MDIO_REG_BANK_RX3;
bank += (MDIO_REG_BANK_RX1-MDIO_REG_BANK_RX0), i++) {
CL22_WR_OVER_CL45(bp, phy,
bank,
MDIO_RX0_RX_EQ_BOOST,
phy->rx_preemphasis[i]);
}
for (bank = MDIO_REG_BANK_TX0, i = 0; bank <= MDIO_REG_BANK_TX3;
bank += (MDIO_REG_BANK_TX1 - MDIO_REG_BANK_TX0), i++) {
CL22_WR_OVER_CL45(bp, phy,
bank,
MDIO_TX0_TX_DRIVER,
phy->tx_preemphasis[i]);
}
}
static void bnx2x_init_internal_phy(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u8 enable_cl73 = (SINGLE_MEDIA_DIRECT(params) ||
(params->loopback_mode == LOOPBACK_XGXS));
if (!(vars->phy_flags & PHY_SGMII_FLAG)) {
if (SINGLE_MEDIA_DIRECT(params) &&
(params->feature_config_flags &
FEATURE_CONFIG_OVERRIDE_PREEMPHASIS_ENABLED))
bnx2x_set_preemphasis(phy, params);
if (vars->line_speed != SPEED_AUTO_NEG ||
(SINGLE_MEDIA_DIRECT(params) &&
params->loopback_mode == LOOPBACK_EXT)) {
DP(NETIF_MSG_LINK, "not SGMII, no AN\n");
bnx2x_set_autoneg(phy, params, vars, 0);
bnx2x_program_serdes(phy, params, vars);
} else {
DP(NETIF_MSG_LINK, "not SGMII, AN\n");
bnx2x_set_brcm_cl37_advertisment(phy, params);
bnx2x_set_ieee_aneg_advertisment(phy, params,
vars->ieee_fc);
bnx2x_set_autoneg(phy, params, vars, enable_cl73);
bnx2x_restart_autoneg(phy, params, enable_cl73);
}
} else {
DP(NETIF_MSG_LINK, "SGMII\n");
bnx2x_initialize_sgmii_process(phy, params, vars);
}
}
static u8 bnx2x_init_serdes(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
u8 rc;
vars->phy_flags |= PHY_SGMII_FLAG;
bnx2x_calc_ieee_aneg_adv(phy, params, &vars->ieee_fc);
bnx2x_set_aer_mmd_serdes(params->bp, phy);
rc = bnx2x_reset_unicore(params, phy, 1);
if (rc != 0)
return rc;
bnx2x_set_aer_mmd_serdes(params->bp, phy);
return rc;
}
static u8 bnx2x_init_xgxs(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
u8 rc;
vars->phy_flags = PHY_XGXS_FLAG;
if ((phy->req_line_speed &&
((phy->req_line_speed == SPEED_100) ||
(phy->req_line_speed == SPEED_10))) ||
(!phy->req_line_speed &&
(phy->speed_cap_mask >=
PORT_HW_CFG_SPEED_CAPABILITY_D0_10M_FULL) &&
(phy->speed_cap_mask <
PORT_HW_CFG_SPEED_CAPABILITY_D0_1G)
))
vars->phy_flags |= PHY_SGMII_FLAG;
else
vars->phy_flags &= ~PHY_SGMII_FLAG;
bnx2x_calc_ieee_aneg_adv(phy, params, &vars->ieee_fc);
bnx2x_set_aer_mmd_xgxs(params, phy);
bnx2x_set_master_ln(params, phy);
rc = bnx2x_reset_unicore(params, phy, 0);
if (rc != 0)
return rc;
bnx2x_set_aer_mmd_xgxs(params, phy);
bnx2x_set_master_ln(params, phy);
bnx2x_set_swap_lanes(params, phy);
return rc;
}
static u16 bnx2x_wait_reset_complete(struct bnx2x *bp,
struct bnx2x_phy *phy,
struct link_params *params)
{
u16 cnt, ctrl;
for (cnt = 0; cnt < 1000; cnt++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, &ctrl);
if (!(ctrl & (1<<15)))
break;
msleep(1);
}
if (cnt == 1000)
netdev_err(bp->dev, "Warning: PHY was not initialized,"
" Port %d\n",
params->port);
DP(NETIF_MSG_LINK, "control reg 0x%x (after %d ms)\n", ctrl, cnt);
return cnt;
}
static void bnx2x_link_int_enable(struct link_params *params)
{
u8 port = params->port;
u32 mask;
struct bnx2x *bp = params->bp;
if (params->switch_cfg == SWITCH_CFG_10G) {
mask = (NIG_MASK_XGXS0_LINK10G |
NIG_MASK_XGXS0_LINK_STATUS);
DP(NETIF_MSG_LINK, "enabled XGXS interrupt\n");
if (!(SINGLE_MEDIA_DIRECT(params)) &&
params->phy[INT_PHY].type !=
PORT_HW_CFG_XGXS_EXT_PHY_TYPE_FAILURE) {
mask |= NIG_MASK_MI_INT;
DP(NETIF_MSG_LINK, "enabled external phy int\n");
}
} else {
mask = NIG_MASK_SERDES0_LINK_STATUS;
DP(NETIF_MSG_LINK, "enabled SerDes interrupt\n");
if (!(SINGLE_MEDIA_DIRECT(params)) &&
params->phy[INT_PHY].type !=
PORT_HW_CFG_SERDES_EXT_PHY_TYPE_NOT_CONN) {
mask |= NIG_MASK_MI_INT;
DP(NETIF_MSG_LINK, "enabled external phy int\n");
}
}
bnx2x_bits_en(bp,
NIG_REG_MASK_INTERRUPT_PORT0 + port*4,
mask);
DP(NETIF_MSG_LINK, "port %x, is_xgxs %x, int_status 0x%x\n", port,
(params->switch_cfg == SWITCH_CFG_10G),
REG_RD(bp, NIG_REG_STATUS_INTERRUPT_PORT0 + port*4));
DP(NETIF_MSG_LINK, " int_mask 0x%x, MI_INT %x, SERDES_LINK %x\n",
REG_RD(bp, NIG_REG_MASK_INTERRUPT_PORT0 + port*4),
REG_RD(bp, NIG_REG_EMAC0_STATUS_MISC_MI_INT + port*0x18),
REG_RD(bp, NIG_REG_SERDES0_STATUS_LINK_STATUS+port*0x3c));
DP(NETIF_MSG_LINK, " 10G %x, XGXS_LINK %x\n",
REG_RD(bp, NIG_REG_XGXS0_STATUS_LINK10G + port*0x68),
REG_RD(bp, NIG_REG_XGXS0_STATUS_LINK_STATUS + port*0x68));
}
static void bnx2x_rearm_latch_signal(struct bnx2x *bp, u8 port,
u8 exp_mi_int)
{
u32 latch_status = 0;
latch_status = REG_RD(bp,
NIG_REG_LATCH_STATUS_0 + port*8);
DP(NETIF_MSG_LINK, "latch_status = 0x%x\n", latch_status);
if (exp_mi_int)
bnx2x_bits_en(bp,
NIG_REG_STATUS_INTERRUPT_PORT0
+ port*4,
NIG_STATUS_EMAC0_MI_INT);
else
bnx2x_bits_dis(bp,
NIG_REG_STATUS_INTERRUPT_PORT0
+ port*4,
NIG_STATUS_EMAC0_MI_INT);
if (latch_status & 1) {
REG_WR(bp, NIG_REG_LATCH_STATUS_0 + port*8,
(latch_status & 0xfffe) | (latch_status & 1));
}
}
static void bnx2x_link_int_ack(struct link_params *params,
struct link_vars *vars, u8 is_10g)
{
struct bnx2x *bp = params->bp;
u8 port = params->port;
bnx2x_bits_dis(bp, NIG_REG_STATUS_INTERRUPT_PORT0 + port*4,
(NIG_STATUS_XGXS0_LINK10G |
NIG_STATUS_XGXS0_LINK_STATUS |
NIG_STATUS_SERDES0_LINK_STATUS));
if (vars->phy_link_up) {
if (is_10g) {
DP(NETIF_MSG_LINK, "10G XGXS phy link up\n");
bnx2x_bits_en(bp,
NIG_REG_STATUS_INTERRUPT_PORT0 + port*4,
NIG_STATUS_XGXS0_LINK10G);
} else if (params->switch_cfg == SWITCH_CFG_10G) {
u32 ser_lane = ((params->lane_config &
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_MASK) >>
PORT_HW_CFG_LANE_SWAP_CFG_MASTER_SHIFT);
DP(NETIF_MSG_LINK, "%d speed XGXS phy link up\n",
vars->line_speed);
bnx2x_bits_en(bp,
NIG_REG_STATUS_INTERRUPT_PORT0 + port*4,
((1 << ser_lane) <<
NIG_STATUS_XGXS0_LINK_STATUS_SIZE));
} else {
DP(NETIF_MSG_LINK, "SerDes phy link up\n");
bnx2x_bits_en(bp,
NIG_REG_STATUS_INTERRUPT_PORT0 + port*4,
NIG_STATUS_SERDES0_LINK_STATUS);
}
}
}
static u8 bnx2x_format_ver(u32 num, u8 *str, u16 *len)
{
u8 *str_ptr = str;
u32 mask = 0xf0000000;
u8 shift = 8*4;
u8 digit;
u8 remove_leading_zeros = 1;
if (*len < 10) {
*str_ptr = '\0';
(*len)--;
return -EINVAL;
}
while (shift > 0) {
shift -= 4;
digit = ((num & mask) >> shift);
if (digit == 0 && remove_leading_zeros) {
mask = mask >> 4;
continue;
} else if (digit < 0xa)
*str_ptr = digit + '0';
else
*str_ptr = digit - 0xa + 'a';
remove_leading_zeros = 0;
str_ptr++;
(*len)--;
mask = mask >> 4;
if (shift == 4*4) {
*str_ptr = '.';
str_ptr++;
(*len)--;
remove_leading_zeros = 1;
}
}
return 0;
}
static u8 bnx2x_null_format_ver(u32 spirom_ver, u8 *str, u16 *len)
{
str[0] = '\0';
(*len)--;
return 0;
}
u8 bnx2x_get_ext_phy_fw_version(struct link_params *params, u8 driver_loaded,
u8 *version, u16 len)
{
struct bnx2x *bp;
u32 spirom_ver = 0;
u8 status = 0;
u8 *ver_p = version;
u16 remain_len = len;
if (version == NULL || params == NULL)
return -EINVAL;
bp = params->bp;
version[0] = '\0';
spirom_ver = REG_RD(bp, params->phy[EXT_PHY1].ver_addr);
if (params->phy[EXT_PHY1].format_fw_ver) {
status |= params->phy[EXT_PHY1].format_fw_ver(spirom_ver,
ver_p,
&remain_len);
ver_p += (len - remain_len);
}
if ((params->num_phys == MAX_PHYS) &&
(params->phy[EXT_PHY2].ver_addr != 0)) {
spirom_ver = REG_RD(bp, params->phy[EXT_PHY2].ver_addr);
if (params->phy[EXT_PHY2].format_fw_ver) {
*ver_p = '/';
ver_p++;
remain_len--;
status |= params->phy[EXT_PHY2].format_fw_ver(
spirom_ver,
ver_p,
&remain_len);
ver_p = version + (len - remain_len);
}
}
*ver_p = '\0';
return status;
}
static void bnx2x_set_xgxs_loopback(struct bnx2x_phy *phy,
struct link_params *params)
{
u8 port = params->port;
struct bnx2x *bp = params->bp;
if (phy->req_line_speed != SPEED_1000) {
u32 md_devad;
DP(NETIF_MSG_LINK, "XGXS 10G loopback enable\n");
md_devad = REG_RD(bp, (NIG_REG_XGXS0_CTRL_MD_DEVAD +
port*0x18));
REG_WR(bp, NIG_REG_XGXS0_CTRL_MD_DEVAD + port*0x18, 0x5);
bnx2x_cl45_write(bp, phy,
5,
(MDIO_REG_BANK_AER_BLOCK +
(MDIO_AER_BLOCK_AER_REG & 0xf)),
0x2800);
bnx2x_cl45_write(bp, phy,
5,
(MDIO_REG_BANK_CL73_IEEEB0 +
(MDIO_CL73_IEEEB0_CL73_AN_CONTROL & 0xf)),
0x6041);
msleep(200);
bnx2x_set_aer_mmd_xgxs(params, phy);
REG_WR(bp, NIG_REG_XGXS0_CTRL_MD_DEVAD + port*0x18, md_devad);
} else {
u16 mii_ctrl;
DP(NETIF_MSG_LINK, "XGXS 1G loopback enable\n");
bnx2x_cl45_read(bp, phy, 5,
(MDIO_REG_BANK_COMBO_IEEE0 +
(MDIO_COMBO_IEEE0_MII_CONTROL & 0xf)),
&mii_ctrl);
bnx2x_cl45_write(bp, phy, 5,
(MDIO_REG_BANK_COMBO_IEEE0 +
(MDIO_COMBO_IEEE0_MII_CONTROL & 0xf)),
mii_ctrl |
MDIO_COMBO_IEEO_MII_CONTROL_LOOPBACK);
}
}
u8 bnx2x_set_led(struct link_params *params,
struct link_vars *vars, u8 mode, u32 speed)
{
u8 port = params->port;
u16 hw_led_mode = params->hw_led_mode;
u8 rc = 0, phy_idx;
u32 tmp;
u32 emac_base = port ? GRCBASE_EMAC1 : GRCBASE_EMAC0;
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "bnx2x_set_led: port %x, mode %d\n", port, mode);
DP(NETIF_MSG_LINK, "speed 0x%x, hw_led_mode 0x%x\n",
speed, hw_led_mode);
for (phy_idx = EXT_PHY1; phy_idx < MAX_PHYS; phy_idx++) {
if (params->phy[phy_idx].set_link_led) {
params->phy[phy_idx].set_link_led(
&params->phy[phy_idx], params, mode);
}
}
switch (mode) {
case LED_MODE_FRONT_PANEL_OFF:
case LED_MODE_OFF:
REG_WR(bp, NIG_REG_LED_10G_P0 + port*4, 0);
REG_WR(bp, NIG_REG_LED_MODE_P0 + port*4,
SHARED_HW_CFG_LED_MAC1);
tmp = EMAC_RD(bp, EMAC_REG_EMAC_LED);
EMAC_WR(bp, EMAC_REG_EMAC_LED, (tmp | EMAC_LED_OVERRIDE));
break;
case LED_MODE_OPER:
if (!vars->link_up)
break;
case LED_MODE_ON:
if (params->phy[EXT_PHY1].type ==
PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727 &&
CHIP_IS_E2(bp) && params->num_phys == 2) {
if (mode == LED_MODE_ON ||
speed == SPEED_10000){
REG_WR(bp, NIG_REG_LED_MODE_P0 + port*4, 0);
REG_WR(bp, NIG_REG_LED_10G_P0 + port*4, 1);
tmp = EMAC_RD(bp, EMAC_REG_EMAC_LED);
EMAC_WR(bp, EMAC_REG_EMAC_LED,
(tmp | EMAC_LED_OVERRIDE));
return rc;
}
} else if (SINGLE_MEDIA_DIRECT(params)) {
REG_WR(bp, NIG_REG_LED_MODE_P0 + port*4, 0);
REG_WR(bp, NIG_REG_LED_10G_P0 + port*4, 1);
} else {
REG_WR(bp, NIG_REG_LED_MODE_P0 + port*4, hw_led_mode);
}
REG_WR(bp, NIG_REG_LED_CONTROL_OVERRIDE_TRAFFIC_P0 + port*4, 0);
REG_WR(bp, NIG_REG_LED_CONTROL_BLINK_RATE_P0 + port*4,
LED_BLINK_RATE_VAL);
REG_WR(bp, NIG_REG_LED_CONTROL_BLINK_RATE_ENA_P0 +
port*4, 1);
tmp = EMAC_RD(bp, EMAC_REG_EMAC_LED);
EMAC_WR(bp, EMAC_REG_EMAC_LED, (tmp & (~EMAC_LED_OVERRIDE)));
if (CHIP_IS_E1(bp) &&
((speed == SPEED_2500) ||
(speed == SPEED_1000) ||
(speed == SPEED_100) ||
(speed == SPEED_10))) {
REG_WR(bp, NIG_REG_LED_CONTROL_OVERRIDE_TRAFFIC_P0
+ port*4, 1);
REG_WR(bp, NIG_REG_LED_CONTROL_TRAFFIC_P0 +
port*4, 0);
REG_WR(bp, NIG_REG_LED_CONTROL_BLINK_TRAFFIC_P0 +
port*4, 1);
}
break;
default:
rc = -EINVAL;
DP(NETIF_MSG_LINK, "bnx2x_set_led: Invalid led mode %d\n",
mode);
break;
}
return rc;
}
u8 bnx2x_test_link(struct link_params *params, struct link_vars *vars,
u8 is_serdes)
{
struct bnx2x *bp = params->bp;
u16 gp_status = 0, phy_index = 0;
u8 ext_phy_link_up = 0, serdes_phy_type;
struct link_vars temp_vars;
CL22_RD_OVER_CL45(bp, &params->phy[INT_PHY],
MDIO_REG_BANK_GP_STATUS,
MDIO_GP_STATUS_TOP_AN_STATUS1,
&gp_status);
if (!(gp_status & MDIO_GP_STATUS_TOP_AN_STATUS1_LINK_STATUS))
return -ESRCH;
switch (params->num_phys) {
case 1:
return 0;
case 2:
ext_phy_link_up = params->phy[EXT_PHY1].read_status(
&params->phy[EXT_PHY1],
params, &temp_vars);
break;
case 3:
for (phy_index = EXT_PHY1; phy_index < params->num_phys;
phy_index++) {
serdes_phy_type = ((params->phy[phy_index].media_type ==
ETH_PHY_SFP_FIBER) ||
(params->phy[phy_index].media_type ==
ETH_PHY_XFP_FIBER));
if (is_serdes != serdes_phy_type)
continue;
if (params->phy[phy_index].read_status) {
ext_phy_link_up |=
params->phy[phy_index].read_status(
&params->phy[phy_index],
params, &temp_vars);
}
}
break;
}
if (ext_phy_link_up)
return 0;
return -ESRCH;
}
static u8 bnx2x_link_initialize(struct link_params *params,
struct link_vars *vars)
{
u8 rc = 0;
u8 phy_index, non_ext_phy;
struct bnx2x *bp = params->bp;
vars->line_speed = params->phy[INT_PHY].req_line_speed;
if (params->phy[INT_PHY].config_init)
params->phy[INT_PHY].config_init(
&params->phy[INT_PHY],
params, vars);
non_ext_phy = (SINGLE_MEDIA_DIRECT(params) ||
(params->loopback_mode == LOOPBACK_XGXS));
if (non_ext_phy ||
(params->phy[EXT_PHY1].flags & FLAGS_INIT_XGXS_FIRST) ||
(params->loopback_mode == LOOPBACK_EXT_PHY)) {
struct bnx2x_phy *phy = &params->phy[INT_PHY];
if (vars->line_speed == SPEED_AUTO_NEG)
bnx2x_set_parallel_detection(phy, params);
bnx2x_init_internal_phy(phy, params, vars);
}
if (!non_ext_phy)
for (phy_index = EXT_PHY1; phy_index < params->num_phys;
phy_index++) {
if (phy_index == EXT_PHY2 &&
(bnx2x_phy_selection(params) ==
PORT_HW_CFG_PHY_SELECTION_FIRST_PHY)) {
DP(NETIF_MSG_LINK, "Ignoring second phy\n");
continue;
}
params->phy[phy_index].config_init(
&params->phy[phy_index],
params, vars);
}
bnx2x_bits_dis(bp, NIG_REG_STATUS_INTERRUPT_PORT0 +
params->port*4,
(NIG_STATUS_XGXS0_LINK10G |
NIG_STATUS_XGXS0_LINK_STATUS |
NIG_STATUS_SERDES0_LINK_STATUS |
NIG_MASK_MI_INT));
return rc;
}
static void bnx2x_int_link_reset(struct bnx2x_phy *phy,
struct link_params *params)
{
REG_WR(params->bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_3_CLEAR,
(0x1ff << (params->port*16)));
}
static void bnx2x_common_ext_link_reset(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u8 gpio_port;
if (CHIP_IS_E2(bp))
gpio_port = BP_PATH(bp);
else
gpio_port = params->port;
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_1,
MISC_REGISTERS_GPIO_OUTPUT_LOW,
gpio_port);
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_LOW,
gpio_port);
DP(NETIF_MSG_LINK, "reset external PHY\n");
}
static u8 bnx2x_update_link_down(struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u8 port = params->port;
DP(NETIF_MSG_LINK, "Port %x: Link is down\n", port);
bnx2x_set_led(params, vars, LED_MODE_OFF, 0);
vars->mac_type = MAC_TYPE_NONE;
vars->link_status = 0;
vars->line_speed = 0;
bnx2x_update_mng(params, vars->link_status);
REG_WR(bp, NIG_REG_EGRESS_DRAIN0_MODE + port*4, 1);
REG_WR(bp, NIG_REG_NIG_EMAC0_EN + port*4, 0);
msleep(10);
bnx2x_bmac_rx_disable(bp, params->port);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_CLEAR,
(MISC_REGISTERS_RESET_REG_2_RST_BMAC0 << port));
return 0;
}
static u8 bnx2x_update_link_up(struct link_params *params,
struct link_vars *vars,
u8 link_10g)
{
struct bnx2x *bp = params->bp;
u8 port = params->port;
u8 rc = 0;
vars->link_status |= LINK_STATUS_LINK_UP;
if (vars->flow_ctrl & BNX2X_FLOW_CTRL_TX)
vars->link_status |=
LINK_STATUS_TX_FLOW_CONTROL_ENABLED;
if (vars->flow_ctrl & BNX2X_FLOW_CTRL_RX)
vars->link_status |=
LINK_STATUS_RX_FLOW_CONTROL_ENABLED;
if (link_10g) {
bnx2x_bmac_enable(params, vars, 0);
bnx2x_set_led(params, vars,
LED_MODE_OPER, SPEED_10000);
} else {
rc = bnx2x_emac_program(params, vars);
bnx2x_emac_enable(params, vars, 0);
if ((vars->link_status & LINK_STATUS_AUTO_NEGOTIATE_COMPLETE)
&& (!(vars->phy_flags & PHY_SGMII_FLAG)) &&
SINGLE_MEDIA_DIRECT(params))
bnx2x_set_gmii_tx_driver(params);
}
if (!(CHIP_IS_E2(bp)))
rc |= bnx2x_pbf_update(params, vars->flow_ctrl,
vars->line_speed);
REG_WR(bp, NIG_REG_EGRESS_DRAIN0_MODE + port*4, 0);
bnx2x_update_mng(params, vars->link_status);
msleep(20);
return rc;
}
u8 bnx2x_link_update(struct link_params *params, struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
struct link_vars phy_vars[MAX_PHYS];
u8 port = params->port;
u8 link_10g, phy_index;
u8 ext_phy_link_up = 0, cur_link_up, rc = 0;
u8 is_mi_int = 0;
u16 ext_phy_line_speed = 0, prev_line_speed = vars->line_speed;
u8 active_external_phy = INT_PHY;
vars->link_status = 0;
for (phy_index = INT_PHY; phy_index < params->num_phys;
phy_index++) {
phy_vars[phy_index].flow_ctrl = 0;
phy_vars[phy_index].link_status = 0;
phy_vars[phy_index].line_speed = 0;
phy_vars[phy_index].duplex = DUPLEX_FULL;
phy_vars[phy_index].phy_link_up = 0;
phy_vars[phy_index].link_up = 0;
}
DP(NETIF_MSG_LINK, "port %x, XGXS?%x, int_status 0x%x\n",
port, (vars->phy_flags & PHY_XGXS_FLAG),
REG_RD(bp, NIG_REG_STATUS_INTERRUPT_PORT0 + port*4));
is_mi_int = (u8)(REG_RD(bp, NIG_REG_EMAC0_STATUS_MISC_MI_INT +
port*0x18) > 0);
DP(NETIF_MSG_LINK, "int_mask 0x%x MI_INT %x, SERDES_LINK %x\n",
REG_RD(bp, NIG_REG_MASK_INTERRUPT_PORT0 + port*4),
is_mi_int,
REG_RD(bp, NIG_REG_SERDES0_STATUS_LINK_STATUS + port*0x3c));
DP(NETIF_MSG_LINK, " 10G %x, XGXS_LINK %x\n",
REG_RD(bp, NIG_REG_XGXS0_STATUS_LINK10G + port*0x68),
REG_RD(bp, NIG_REG_XGXS0_STATUS_LINK_STATUS + port*0x68));
REG_WR(bp, NIG_REG_NIG_EMAC0_EN + port*4, 0);
for (phy_index = EXT_PHY1; phy_index < params->num_phys;
phy_index++) {
struct bnx2x_phy *phy = &params->phy[phy_index];
if (!phy->read_status)
continue;
cur_link_up = phy->read_status(phy, params,
&phy_vars[phy_index]);
if (cur_link_up) {
DP(NETIF_MSG_LINK, "phy in index %d link is up\n",
phy_index);
} else {
DP(NETIF_MSG_LINK, "phy in index %d link is down\n",
phy_index);
continue;
}
if (!ext_phy_link_up) {
ext_phy_link_up = 1;
active_external_phy = phy_index;
} else {
switch (bnx2x_phy_selection(params)) {
case PORT_HW_CFG_PHY_SELECTION_HARDWARE_DEFAULT:
case PORT_HW_CFG_PHY_SELECTION_FIRST_PHY_PRIORITY:
active_external_phy = EXT_PHY1;
break;
case PORT_HW_CFG_PHY_SELECTION_SECOND_PHY_PRIORITY:
active_external_phy = EXT_PHY2;
break;
default:
DP(NETIF_MSG_LINK, "Invalid link indication"
"mpc=0x%x. DISABLING LINK !!!\n",
params->multi_phy_config);
ext_phy_link_up = 0;
break;
}
}
}
prev_line_speed = vars->line_speed;
if (params->phy[INT_PHY].read_status)
params->phy[INT_PHY].read_status(
&params->phy[INT_PHY],
params, vars);
if (active_external_phy > INT_PHY) {
vars->flow_ctrl = phy_vars[active_external_phy].flow_ctrl;
vars->link_status |= phy_vars[active_external_phy].link_status;
if (active_external_phy == EXT_PHY1) {
if (params->phy[EXT_PHY2].phy_specific_func) {
DP(NETIF_MSG_LINK, "Disabling TX on"
" EXT_PHY2\n");
params->phy[EXT_PHY2].phy_specific_func(
&params->phy[EXT_PHY2],
params, DISABLE_TX);
}
}
ext_phy_line_speed = phy_vars[active_external_phy].line_speed;
vars->duplex = phy_vars[active_external_phy].duplex;
if (params->phy[active_external_phy].supported &
SUPPORTED_FIBRE)
vars->link_status |= LINK_STATUS_SERDES_LINK;
DP(NETIF_MSG_LINK, "Active external phy selected: %x\n",
active_external_phy);
}
for (phy_index = EXT_PHY1; phy_index < params->num_phys;
phy_index++) {
if (params->phy[phy_index].flags &
FLAGS_REARM_LATCH_SIGNAL) {
bnx2x_rearm_latch_signal(bp, port,
phy_index ==
active_external_phy);
break;
}
}
DP(NETIF_MSG_LINK, "vars->flow_ctrl = 0x%x, vars->link_status = 0x%x,"
" ext_phy_line_speed = %d\n", vars->flow_ctrl,
vars->link_status, ext_phy_line_speed);
if (vars->phy_link_up) {
if (!(SINGLE_MEDIA_DIRECT(params)) && ext_phy_link_up &&
(ext_phy_line_speed != vars->line_speed)) {
DP(NETIF_MSG_LINK, "Internal link speed %d is"
" different than the external"
" link speed %d\n", vars->line_speed,
ext_phy_line_speed);
vars->phy_link_up = 0;
} else if (prev_line_speed != vars->line_speed) {
REG_WR(bp, NIG_REG_EGRESS_DRAIN0_MODE + params->port*4,
0);
msleep(1);
}
}
link_10g = ((vars->line_speed == SPEED_10000) ||
(vars->line_speed == SPEED_12000) ||
(vars->line_speed == SPEED_12500) ||
(vars->line_speed == SPEED_13000) ||
(vars->line_speed == SPEED_15000) ||
(vars->line_speed == SPEED_16000));
bnx2x_link_int_ack(params, vars, link_10g);
if (!(SINGLE_MEDIA_DIRECT(params))) {
DP(NETIF_MSG_LINK, "ext_phy_link_up = %d, int_link_up = %d,"
" init_preceding = %d\n", ext_phy_link_up,
vars->phy_link_up,
params->phy[EXT_PHY1].flags &
FLAGS_INIT_XGXS_FIRST);
if (!(params->phy[EXT_PHY1].flags &
FLAGS_INIT_XGXS_FIRST)
&& ext_phy_link_up && !vars->phy_link_up) {
vars->line_speed = ext_phy_line_speed;
if (vars->line_speed < SPEED_1000)
vars->phy_flags |= PHY_SGMII_FLAG;
else
vars->phy_flags &= ~PHY_SGMII_FLAG;
bnx2x_init_internal_phy(&params->phy[INT_PHY],
params,
vars);
}
}
vars->link_up = (vars->phy_link_up &&
(ext_phy_link_up ||
SINGLE_MEDIA_DIRECT(params)));
if (vars->link_up)
rc = bnx2x_update_link_up(params, vars, link_10g);
else
rc = bnx2x_update_link_down(params, vars);
return rc;
}
void bnx2x_ext_phy_hw_reset(struct bnx2x *bp, u8 port)
{
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_1,
MISC_REGISTERS_GPIO_OUTPUT_LOW, port);
msleep(1);
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_1,
MISC_REGISTERS_GPIO_OUTPUT_HIGH, port);
}
static void bnx2x_save_spirom_version(struct bnx2x *bp, u8 port,
u32 spirom_ver, u32 ver_addr)
{
DP(NETIF_MSG_LINK, "FW version 0x%x:0x%x for port %d\n",
(u16)(spirom_ver>>16), (u16)spirom_ver, port);
if (ver_addr)
REG_WR(bp, ver_addr, spirom_ver);
}
static void bnx2x_save_bcm_spirom_ver(struct bnx2x *bp,
struct bnx2x_phy *phy,
u8 port)
{
u16 fw_ver1, fw_ver2;
bnx2x_cl45_read(bp, phy, MDIO_PMA_DEVAD,
MDIO_PMA_REG_ROM_VER1, &fw_ver1);
bnx2x_cl45_read(bp, phy, MDIO_PMA_DEVAD,
MDIO_PMA_REG_ROM_VER2, &fw_ver2);
bnx2x_save_spirom_version(bp, port, (u32)(fw_ver1<<16 | fw_ver2),
phy->ver_addr);
}
static void bnx2x_ext_phy_set_pause(struct link_params *params,
struct bnx2x_phy *phy,
struct link_vars *vars)
{
u16 val;
struct bnx2x *bp = params->bp;
bnx2x_cl45_read(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_ADV_PAUSE, &val);
val &= ~MDIO_AN_REG_ADV_PAUSE_BOTH;
bnx2x_calc_ieee_aneg_adv(phy, params, &vars->ieee_fc);
if ((vars->ieee_fc &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC) ==
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC) {
val |= MDIO_AN_REG_ADV_PAUSE_ASYMMETRIC;
}
if ((vars->ieee_fc &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH) ==
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH) {
val |= MDIO_AN_REG_ADV_PAUSE_PAUSE;
}
DP(NETIF_MSG_LINK, "Ext phy AN advertize 0x%x\n", val);
bnx2x_cl45_write(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_ADV_PAUSE, val);
}
static u8 bnx2x_ext_phy_resolve_fc(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u16 ld_pause;
u16 lp_pause;
u16 pause_result;
u8 ret = 0;
vars->flow_ctrl = BNX2X_FLOW_CTRL_NONE;
if (phy->req_flow_ctrl != BNX2X_FLOW_CTRL_AUTO)
vars->flow_ctrl = phy->req_flow_ctrl;
else if (phy->req_line_speed != SPEED_AUTO_NEG)
vars->flow_ctrl = params->req_fc_auto_adv;
else if (vars->link_status & LINK_STATUS_AUTO_NEGOTIATE_COMPLETE) {
ret = 1;
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_ADV_PAUSE, &ld_pause);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_LP_AUTO_NEG, &lp_pause);
pause_result = (ld_pause &
MDIO_AN_REG_ADV_PAUSE_MASK) >> 8;
pause_result |= (lp_pause &
MDIO_AN_REG_ADV_PAUSE_MASK) >> 10;
DP(NETIF_MSG_LINK, "Ext PHY pause result 0x%x\n",
pause_result);
bnx2x_pause_resolve(vars, pause_result);
}
return ret;
}
static void bnx2x_ext_phy_10G_an_resolve(struct bnx2x *bp,
struct bnx2x_phy *phy,
struct link_vars *vars)
{
u16 val;
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_STATUS, &val);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_STATUS, &val);
if (val & (1<<5))
vars->link_status |= LINK_STATUS_AUTO_NEGOTIATE_COMPLETE;
if ((val & (1<<0)) == 0)
vars->link_status |= LINK_STATUS_PARALLEL_DETECTION_USED;
}
static void bnx2x_8073_resolve_fc(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
if (phy->req_line_speed == SPEED_10 ||
phy->req_line_speed == SPEED_100) {
vars->flow_ctrl = phy->req_flow_ctrl;
return;
}
if (bnx2x_ext_phy_resolve_fc(phy, params, vars) &&
(vars->flow_ctrl == BNX2X_FLOW_CTRL_NONE)) {
u16 pause_result;
u16 ld_pause;
u16 lp_pause;
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_CL37_FC_LD, &ld_pause);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_CL37_FC_LP, &lp_pause);
pause_result = (ld_pause &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH) >> 5;
pause_result |= (lp_pause &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH) >> 7;
bnx2x_pause_resolve(vars, pause_result);
DP(NETIF_MSG_LINK, "Ext PHY CL37 pause result 0x%x\n",
pause_result);
}
}
static u8 bnx2x_8073_8727_external_rom_boot(struct bnx2x *bp,
struct bnx2x_phy *phy,
u8 port)
{
u32 count = 0;
u16 fw_ver1, fw_msgout;
u8 rc = 0;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_GEN_CTRL,
0x0001);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_GEN_CTRL,
0x008c);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_MISC_CTRL1, 0x0001);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_GEN_CTRL,
MDIO_PMA_REG_GEN_CTRL_ROM_MICRO_RESET);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_GEN_CTRL,
MDIO_PMA_REG_GEN_CTRL_ROM_RESET_INTERNAL_MP);
msleep(100);
do {
count++;
if (count > 300) {
DP(NETIF_MSG_LINK,
"bnx2x_8073_8727_external_rom_boot port %x:"
"Download failed. fw version = 0x%x\n",
port, fw_ver1);
rc = -EINVAL;
break;
}
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_ROM_VER1, &fw_ver1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_M8051_MSGOUT_REG, &fw_msgout);
msleep(1);
} while (fw_ver1 == 0 || fw_ver1 == 0x4321 ||
((fw_msgout & 0xff) != 0x03 && (phy->type ==
PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8073)));
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_MISC_CTRL1, 0x0000);
bnx2x_save_bcm_spirom_ver(bp, phy, port);
DP(NETIF_MSG_LINK,
"bnx2x_8073_8727_external_rom_boot port %x:"
"Download complete. fw version = 0x%x\n",
port, fw_ver1);
return rc;
}
static u8 bnx2x_8073_is_snr_needed(struct bnx2x *bp, struct bnx2x_phy *phy)
{
u16 val;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8073_CHIP_REV, &val);
if (val != 1) {
return 0;
}
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_ROM_VER2, &val);
if (val != 0x102)
return 0;
return 1;
}
static u8 bnx2x_8073_xaui_wa(struct bnx2x *bp, struct bnx2x_phy *phy)
{
u16 val, cnt, cnt1 ;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8073_CHIP_REV, &val);
if (val > 0) {
return 0;
}
for (cnt = 0; cnt < 1000; cnt++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8073_SPEED_LINK_STATUS,
&val);
if (!(val & (1<<14)) || !(val & (1<<13))) {
DP(NETIF_MSG_LINK, "XAUI work-around not required\n");
return 0;
} else if (!(val & (1<<15))) {
DP(NETIF_MSG_LINK, "bit 15 went off\n");
for (cnt1 = 0; cnt1 < 1000; cnt1++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8073_XAUI_WA, &val);
if (val & (1<<15)) {
DP(NETIF_MSG_LINK,
"XAUI workaround has completed\n");
return 0;
}
msleep(3);
}
break;
}
msleep(3);
}
DP(NETIF_MSG_LINK, "Warning: XAUI work-around timeout !!!\n");
return -EINVAL;
}
static void bnx2x_807x_force_10G(struct bnx2x *bp, struct bnx2x_phy *phy)
{
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 0x2040);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_10G_CTRL2, 0x000b);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_BCM_CTRL, 0x0000);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CTRL, 0x0000);
}
static void bnx2x_8073_set_pause_cl37(struct link_params *params,
struct bnx2x_phy *phy,
struct link_vars *vars)
{
u16 cl37_val;
struct bnx2x *bp = params->bp;
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_FC_LD, &cl37_val);
cl37_val &= ~MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH;
bnx2x_calc_ieee_aneg_adv(phy, params, &vars->ieee_fc);
if ((vars->ieee_fc &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_SYMMETRIC) ==
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_SYMMETRIC) {
cl37_val |= MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_SYMMETRIC;
}
if ((vars->ieee_fc &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC) ==
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC) {
cl37_val |= MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC;
}
if ((vars->ieee_fc &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH) ==
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH) {
cl37_val |= MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH;
}
DP(NETIF_MSG_LINK,
"Ext phy AN advertize cl37 0x%x\n", cl37_val);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_FC_LD, cl37_val);
msleep(500);
}
static u8 bnx2x_8073_config_init(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u16 val = 0, tmp1;
u8 gpio_port;
DP(NETIF_MSG_LINK, "Init 8073\n");
if (CHIP_IS_E2(bp))
gpio_port = BP_PATH(bp);
else
gpio_port = params->port;
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_HIGH, gpio_port);
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_1,
MISC_REGISTERS_GPIO_OUTPUT_HIGH, gpio_port);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM_CTRL, (1<<2));
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL, 0x0004);
bnx2x_8073_set_pause_cl37(params, phy, vars);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_M8051_MSGOUT_REG, &tmp1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM, &tmp1);
DP(NETIF_MSG_LINK, "Before rom RX_ALARM(port1): 0x%x\n", tmp1);
if (params->lane_config & PORT_HW_CFG_SWAP_PHY_POLARITY_ENABLED) {
DP(NETIF_MSG_LINK, "Swapping polarity for the 8073\n");
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8073_OPT_DIGITAL_CTRL, &val);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8073_OPT_DIGITAL_CTRL,
(val | (3<<9)));
}
if (REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region, dev_info.
port_hw_config[params->port].default_cfg)) &
PORT_HW_CFG_ENABLE_BAM_ON_KR_ENABLED) {
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_8073_BAM, &val);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_8073_BAM, val | 1);
DP(NETIF_MSG_LINK, "Enable CL37 BAM on KR\n");
}
if (params->loopback_mode == LOOPBACK_EXT) {
bnx2x_807x_force_10G(bp, phy);
DP(NETIF_MSG_LINK, "Forced speed 10G on 807X\n");
return 0;
} else {
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_BCM_CTRL, 0x0002);
}
if (phy->req_line_speed != SPEED_AUTO_NEG) {
if (phy->req_line_speed == SPEED_10000) {
val = (1<<7);
} else if (phy->req_line_speed == SPEED_2500) {
val = (1<<5);
} else
val = (1<<5);
} else {
val = 0;
if (phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G)
val |= (1<<7);
if (phy->speed_cap_mask &
(PORT_HW_CFG_SPEED_CAPABILITY_D0_1G |
PORT_HW_CFG_SPEED_CAPABILITY_D0_2_5G))
val |= (1<<5);
DP(NETIF_MSG_LINK, "807x autoneg val = 0x%x\n", val);
}
bnx2x_cl45_write(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_ADV, val);
bnx2x_cl45_read(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_8073_2_5G, &tmp1);
if (((phy->speed_cap_mask & PORT_HW_CFG_SPEED_CAPABILITY_D0_2_5G) &&
(phy->req_line_speed == SPEED_AUTO_NEG)) ||
(phy->req_line_speed == SPEED_2500)) {
u16 phy_ver;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8073_CHIP_REV,
&phy_ver);
DP(NETIF_MSG_LINK, "Add 2.5G\n");
if (phy_ver > 0)
tmp1 |= 1;
else
tmp1 &= 0xfffe;
} else {
DP(NETIF_MSG_LINK, "Disable 2.5G\n");
tmp1 &= 0xfffe;
}
bnx2x_cl45_write(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_8073_2_5G, tmp1);
bnx2x_cl45_read(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_CL37_FC_LD, &tmp1);
bnx2x_cl45_write(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_CL37_FC_LD,
(tmp1 | ((phy->req_duplex == DUPLEX_FULL) ?
0x20 : 0x40)));
bnx2x_cl45_write(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_CL37_AN, 0x1000);
if (bnx2x_8073_is_snr_needed(bp, phy))
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_EDC_FFE_MAIN,
0xFB0C);
bnx2x_cl45_read(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_ADV2, &tmp1);
tmp1 |= (1<<15);
bnx2x_cl45_write(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_ADV2, tmp1);
bnx2x_ext_phy_set_pause(params, phy, vars);
msleep(500);
bnx2x_cl45_write(bp, phy, MDIO_AN_DEVAD, MDIO_AN_REG_CTRL, 0x1200);
DP(NETIF_MSG_LINK, "807x Autoneg Restart: Advertise 1G=%x, 10G=%x\n",
((val & (1<<5)) > 0), ((val & (1<<7)) > 0));
return 0;
}
static u8 bnx2x_8073_read_status(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u8 link_up = 0;
u16 val1, val2;
u16 link_status = 0;
u16 an1000_status = 0;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_STATUS, &val1);
DP(NETIF_MSG_LINK, "8703 LASI status 0x%x\n", val1);
bnx2x_cl45_read(bp, phy,
MDIO_PCS_DEVAD, MDIO_PCS_REG_STATUS, &val2);
bnx2x_cl45_read(bp, phy,
MDIO_PCS_DEVAD, MDIO_PCS_REG_STATUS, &val1);
DP(NETIF_MSG_LINK, "807x PCS status 0x%x->0x%x\n", val2, val1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_M8051_MSGOUT_REG, &val1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM, &val2);
DP(NETIF_MSG_LINK, "KR 0x9003 0x%x\n", val2);
bnx2x_cl45_read(bp, phy,
MDIO_PCS_DEVAD, MDIO_PCS_REG_STATUS, &val2);
DP(NETIF_MSG_LINK, "KR PCS status 0x%x\n", val2);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_STATUS, &val2);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_STATUS, &val1);
link_up = ((val1 & 4) == 4);
DP(NETIF_MSG_LINK, "PMA_REG_STATUS=0x%x\n", val1);
if (link_up &&
((phy->req_line_speed != SPEED_10000))) {
if (bnx2x_8073_xaui_wa(bp, phy) != 0)
return 0;
}
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_LINK_STATUS, &an1000_status);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_LINK_STATUS, &an1000_status);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_STATUS, &val2);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_STATUS, &val1);
DP(NETIF_MSG_LINK, "KR PMA status 0x%x->0x%x,"
"an_link_status=0x%x\n", val2, val1, an1000_status);
link_up = (((val1 & 4) == 4) || (an1000_status & (1<<1)));
if (link_up && bnx2x_8073_is_snr_needed(bp, phy)) {
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_PLL_BANDWIDTH,
0x26BC);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_CDR_BANDWIDTH,
0x0333);
}
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8073_SPEED_LINK_STATUS,
&link_status);
if ((link_status & (1<<2)) && (!(link_status & (1<<15)))) {
link_up = 1;
vars->line_speed = SPEED_10000;
DP(NETIF_MSG_LINK, "port %x: External link up in 10G\n",
params->port);
} else if ((link_status & (1<<1)) && (!(link_status & (1<<14)))) {
link_up = 1;
vars->line_speed = SPEED_2500;
DP(NETIF_MSG_LINK, "port %x: External link up in 2.5G\n",
params->port);
} else if ((link_status & (1<<0)) && (!(link_status & (1<<13)))) {
link_up = 1;
vars->line_speed = SPEED_1000;
DP(NETIF_MSG_LINK, "port %x: External link up in 1G\n",
params->port);
} else {
link_up = 0;
DP(NETIF_MSG_LINK, "port %x: External link is down\n",
params->port);
}
if (link_up) {
if (params->lane_config &
PORT_HW_CFG_SWAP_PHY_POLARITY_ENABLED) {
bnx2x_cl45_read(bp, phy,
MDIO_XS_DEVAD,
MDIO_XS_REG_8073_RX_CTRL_PCIE, &val1);
if (vars->line_speed == SPEED_1000) {
DP(NETIF_MSG_LINK, "Swapping 1G polarity for"
"the 8073\n");
val1 |= (1<<3);
} else
val1 &= ~(1<<3);
bnx2x_cl45_write(bp, phy,
MDIO_XS_DEVAD,
MDIO_XS_REG_8073_RX_CTRL_PCIE,
val1);
}
bnx2x_ext_phy_10G_an_resolve(bp, phy, vars);
bnx2x_8073_resolve_fc(phy, params, vars);
vars->duplex = DUPLEX_FULL;
}
return link_up;
}
static void bnx2x_8073_link_reset(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u8 gpio_port;
if (CHIP_IS_E2(bp))
gpio_port = BP_PATH(bp);
else
gpio_port = params->port;
DP(NETIF_MSG_LINK, "Setting 8073 port %d into low power mode\n",
gpio_port);
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_LOW,
gpio_port);
}
static u8 bnx2x_8705_config_init(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "init 8705\n");
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_HIGH, params->port);
bnx2x_ext_phy_hw_reset(bp, params->port);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 0xa040);
bnx2x_wait_reset_complete(bp, phy, params);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_MISC_CTRL, 0x8288);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_PHY_IDENTIFIER, 0x7fbf);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_CMU_PLL_BYPASS, 0x0100);
bnx2x_cl45_write(bp, phy,
MDIO_WIS_DEVAD, MDIO_WIS_REG_LASI_CNTL, 0x1);
bnx2x_save_spirom_version(bp, params->port, params->shmem_base, 0);
return 0;
}
static u8 bnx2x_8705_read_status(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
u8 link_up = 0;
u16 val1, rx_sd;
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "read status 8705\n");
bnx2x_cl45_read(bp, phy,
MDIO_WIS_DEVAD, MDIO_WIS_REG_LASI_STATUS, &val1);
DP(NETIF_MSG_LINK, "8705 LASI status 0x%x\n", val1);
bnx2x_cl45_read(bp, phy,
MDIO_WIS_DEVAD, MDIO_WIS_REG_LASI_STATUS, &val1);
DP(NETIF_MSG_LINK, "8705 LASI status 0x%x\n", val1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_SD, &rx_sd);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, 0xc809, &val1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, 0xc809, &val1);
DP(NETIF_MSG_LINK, "8705 1.c809 val=0x%x\n", val1);
link_up = ((rx_sd & 0x1) && (val1 & (1<<9)) && ((val1 & (1<<8)) == 0));
if (link_up) {
vars->line_speed = SPEED_10000;
bnx2x_ext_phy_resolve_fc(phy, params, vars);
}
return link_up;
}
static u8 bnx2x_get_gpio_port(struct link_params *params)
{
u8 gpio_port;
u32 swap_val, swap_override;
struct bnx2x *bp = params->bp;
if (CHIP_IS_E2(bp))
gpio_port = BP_PATH(bp);
else
gpio_port = params->port;
swap_val = REG_RD(bp, NIG_REG_PORT_SWAP);
swap_override = REG_RD(bp, NIG_REG_STRAP_OVERRIDE);
return gpio_port ^ (swap_val && swap_override);
}
static void bnx2x_sfp_set_transmitter(struct link_params *params,
struct bnx2x_phy *phy,
u8 tx_en)
{
u16 val;
u8 port = params->port;
struct bnx2x *bp = params->bp;
u32 tx_en_mode;
tx_en_mode = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[port].sfp_ctrl)) &
PORT_HW_CFG_TX_LASER_MASK;
DP(NETIF_MSG_LINK, "Setting transmitter tx_en=%x for port %x "
"mode = %x\n", tx_en, port, tx_en_mode);
switch (tx_en_mode) {
case PORT_HW_CFG_TX_LASER_MDIO:
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER,
&val);
if (tx_en)
val &= ~(1<<15);
else
val |= (1<<15);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER,
val);
break;
case PORT_HW_CFG_TX_LASER_GPIO0:
case PORT_HW_CFG_TX_LASER_GPIO1:
case PORT_HW_CFG_TX_LASER_GPIO2:
case PORT_HW_CFG_TX_LASER_GPIO3:
{
u16 gpio_pin;
u8 gpio_port, gpio_mode;
if (tx_en)
gpio_mode = MISC_REGISTERS_GPIO_OUTPUT_HIGH;
else
gpio_mode = MISC_REGISTERS_GPIO_OUTPUT_LOW;
gpio_pin = tx_en_mode - PORT_HW_CFG_TX_LASER_GPIO0;
gpio_port = bnx2x_get_gpio_port(params);
bnx2x_set_gpio(bp, gpio_pin, gpio_mode, gpio_port);
break;
}
default:
DP(NETIF_MSG_LINK, "Invalid TX_LASER_MDIO 0x%x\n", tx_en_mode);
break;
}
}
static u8 bnx2x_8726_read_sfp_module_eeprom(struct bnx2x_phy *phy,
struct link_params *params,
u16 addr, u8 byte_cnt, u8 *o_buf)
{
struct bnx2x *bp = params->bp;
u16 val = 0;
u16 i;
if (byte_cnt > 16) {
DP(NETIF_MSG_LINK, "Reading from eeprom is"
" is limited to 0xf\n");
return -EINVAL;
}
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_SFP_TWO_WIRE_BYTE_CNT,
(byte_cnt | 0xa000));
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_SFP_TWO_WIRE_MEM_ADDR,
addr);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_SFP_TWO_WIRE_CTRL,
0x2c0f);
for (i = 0; i < 100; i++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_SFP_TWO_WIRE_CTRL, &val);
if ((val & MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK) ==
MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_COMPLETE)
break;
udelay(5);
}
if ((val & MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK) !=
MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_COMPLETE) {
DP(NETIF_MSG_LINK,
"Got bad status 0x%x when reading from SFP+ EEPROM\n",
(val & MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK));
return -EINVAL;
}
for (i = 0; i < byte_cnt; i++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8726_TWO_WIRE_DATA_BUF + i, &val);
o_buf[i] = (u8)(val & MDIO_PMA_REG_8726_TWO_WIRE_DATA_MASK);
}
for (i = 0; i < 100; i++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_SFP_TWO_WIRE_CTRL, &val);
if ((val & MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK) ==
MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_IDLE)
return 0;
msleep(1);
}
return -EINVAL;
}
static u8 bnx2x_8727_read_sfp_module_eeprom(struct bnx2x_phy *phy,
struct link_params *params,
u16 addr, u8 byte_cnt, u8 *o_buf)
{
struct bnx2x *bp = params->bp;
u16 val, i;
if (byte_cnt > 16) {
DP(NETIF_MSG_LINK, "Reading from eeprom is"
" is limited to 0xf\n");
return -EINVAL;
}
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_SFP_TWO_WIRE_CTRL,
&val);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_SFP_TWO_WIRE_BYTE_CNT,
((byte_cnt < 2) ? 2 : byte_cnt));
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_SFP_TWO_WIRE_MEM_ADDR,
addr);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
0x8004,
MDIO_PMA_REG_8727_TWO_WIRE_DATA_BUF);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_SFP_TWO_WIRE_CTRL,
0x8002);
msleep(1);
for (i = 0; i < 100; i++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_SFP_TWO_WIRE_CTRL, &val);
if ((val & MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK) ==
MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_COMPLETE)
break;
udelay(5);
}
if ((val & MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK) !=
MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_COMPLETE) {
DP(NETIF_MSG_LINK,
"Got bad status 0x%x when reading from SFP+ EEPROM\n",
(val & MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK));
return -EFAULT;
}
for (i = 0; i < byte_cnt; i++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_TWO_WIRE_DATA_BUF + i, &val);
o_buf[i] = (u8)(val & MDIO_PMA_REG_8727_TWO_WIRE_DATA_MASK);
}
for (i = 0; i < 100; i++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_SFP_TWO_WIRE_CTRL, &val);
if ((val & MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK) ==
MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_IDLE)
return 0;
msleep(1);
}
return -EINVAL;
}
u8 bnx2x_read_sfp_module_eeprom(struct bnx2x_phy *phy,
struct link_params *params, u16 addr,
u8 byte_cnt, u8 *o_buf)
{
if (phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8726)
return bnx2x_8726_read_sfp_module_eeprom(phy, params, addr,
byte_cnt, o_buf);
else if (phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727)
return bnx2x_8727_read_sfp_module_eeprom(phy, params, addr,
byte_cnt, o_buf);
return -EINVAL;
}
static u8 bnx2x_get_edc_mode(struct bnx2x_phy *phy,
struct link_params *params,
u16 *edc_mode)
{
struct bnx2x *bp = params->bp;
u8 val, check_limiting_mode = 0;
*edc_mode = EDC_MODE_LIMITING;
if (bnx2x_read_sfp_module_eeprom(phy,
params,
SFP_EEPROM_CON_TYPE_ADDR,
1,
&val) != 0) {
DP(NETIF_MSG_LINK, "Failed to read from SFP+ module EEPROM\n");
return -EINVAL;
}
switch (val) {
case SFP_EEPROM_CON_TYPE_VAL_COPPER:
{
u8 copper_module_type;
if (bnx2x_read_sfp_module_eeprom(phy,
params,
SFP_EEPROM_FC_TX_TECH_ADDR,
1,
&copper_module_type) !=
0) {
DP(NETIF_MSG_LINK,
"Failed to read copper-cable-type"
" from SFP+ EEPROM\n");
return -EINVAL;
}
if (copper_module_type &
SFP_EEPROM_FC_TX_TECH_BITMASK_COPPER_ACTIVE) {
DP(NETIF_MSG_LINK, "Active Copper cable detected\n");
check_limiting_mode = 1;
} else if (copper_module_type &
SFP_EEPROM_FC_TX_TECH_BITMASK_COPPER_PASSIVE) {
DP(NETIF_MSG_LINK, "Passive Copper"
" cable detected\n");
*edc_mode =
EDC_MODE_PASSIVE_DAC;
} else {
DP(NETIF_MSG_LINK, "Unknown copper-cable-"
"type 0x%x !!!\n", copper_module_type);
return -EINVAL;
}
break;
}
case SFP_EEPROM_CON_TYPE_VAL_LC:
DP(NETIF_MSG_LINK, "Optic module detected\n");
check_limiting_mode = 1;
break;
default:
DP(NETIF_MSG_LINK, "Unable to determine module type 0x%x !!!\n",
val);
return -EINVAL;
}
if (check_limiting_mode) {
u8 options[SFP_EEPROM_OPTIONS_SIZE];
if (bnx2x_read_sfp_module_eeprom(phy,
params,
SFP_EEPROM_OPTIONS_ADDR,
SFP_EEPROM_OPTIONS_SIZE,
options) != 0) {
DP(NETIF_MSG_LINK, "Failed to read Option"
" field from module EEPROM\n");
return -EINVAL;
}
if ((options[0] & SFP_EEPROM_OPTIONS_LINEAR_RX_OUT_MASK))
*edc_mode = EDC_MODE_LINEAR;
else
*edc_mode = EDC_MODE_LIMITING;
}
DP(NETIF_MSG_LINK, "EDC mode is set to 0x%x\n", *edc_mode);
return 0;
}
static u8 bnx2x_verify_sfp_module(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u32 val, cmd;
u32 fw_resp, fw_cmd_param;
char vendor_name[SFP_EEPROM_VENDOR_NAME_SIZE+1];
char vendor_pn[SFP_EEPROM_PART_NO_SIZE+1];
phy->flags &= ~FLAGS_SFP_NOT_APPROVED;
val = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region, dev_info.
port_feature_config[params->port].config));
if ((val & PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_MASK) ==
PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_NO_ENFORCEMENT) {
DP(NETIF_MSG_LINK, "NOT enforcing module verification\n");
return 0;
}
if (params->feature_config_flags &
FEATURE_CONFIG_BC_SUPPORTS_DUAL_PHY_OPT_MDL_VRFY) {
cmd = DRV_MSG_CODE_VRFY_SPECIFIC_PHY_OPT_MDL;
} else if (params->feature_config_flags &
FEATURE_CONFIG_BC_SUPPORTS_OPT_MDL_VRFY) {
if (DUAL_MEDIA(params)) {
DP(NETIF_MSG_LINK, "FW does not support OPT MDL "
"verification\n");
return -EINVAL;
}
cmd = DRV_MSG_CODE_VRFY_FIRST_PHY_OPT_MDL;
} else {
DP(NETIF_MSG_LINK, "FW does not support OPT MDL "
"verification\n");
return -EINVAL;
}
fw_cmd_param = FW_PARAM_SET(phy->addr, phy->type, phy->mdio_ctrl);
fw_resp = bnx2x_fw_command(bp, cmd, fw_cmd_param);
if (fw_resp == FW_MSG_CODE_VRFY_OPT_MDL_SUCCESS) {
DP(NETIF_MSG_LINK, "Approved module\n");
return 0;
}
if (bnx2x_read_sfp_module_eeprom(phy,
params,
SFP_EEPROM_VENDOR_NAME_ADDR,
SFP_EEPROM_VENDOR_NAME_SIZE,
(u8 *)vendor_name))
vendor_name[0] = '\0';
else
vendor_name[SFP_EEPROM_VENDOR_NAME_SIZE] = '\0';
if (bnx2x_read_sfp_module_eeprom(phy,
params,
SFP_EEPROM_PART_NO_ADDR,
SFP_EEPROM_PART_NO_SIZE,
(u8 *)vendor_pn))
vendor_pn[0] = '\0';
else
vendor_pn[SFP_EEPROM_PART_NO_SIZE] = '\0';
netdev_err(bp->dev, "Warning: Unqualified SFP+ module detected,"
" Port %d from %s part number %s\n",
params->port, vendor_name, vendor_pn);
phy->flags |= FLAGS_SFP_NOT_APPROVED;
return -EINVAL;
}
static u8 bnx2x_wait_for_sfp_module_initialized(struct bnx2x_phy *phy,
struct link_params *params)
{
u8 val;
struct bnx2x *bp = params->bp;
u16 timeout;
for (timeout = 0; timeout < 60; timeout++) {
if (bnx2x_read_sfp_module_eeprom(phy, params, 1, 1, &val)
== 0) {
DP(NETIF_MSG_LINK, "SFP+ module initialization "
"took %d ms\n", timeout * 5);
return 0;
}
msleep(5);
}
return -EINVAL;
}
static void bnx2x_8727_power_module(struct bnx2x *bp,
struct bnx2x_phy *phy,
u8 is_power_up) {
u16 val;
if (phy->flags & FLAGS_NOC)
return;
if (!(phy->flags &
FLAGS_NOC) && is_power_up)
val = (1<<4);
else
val = ((!(is_power_up)) << 1);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_GPIO_CTRL,
val);
}
static u8 bnx2x_8726_set_limiting_mode(struct bnx2x *bp,
struct bnx2x_phy *phy,
u16 edc_mode)
{
u16 cur_limiting_mode;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_ROM_VER2,
&cur_limiting_mode);
DP(NETIF_MSG_LINK, "Current Limiting mode is 0x%x\n",
cur_limiting_mode);
if (edc_mode == EDC_MODE_LIMITING) {
DP(NETIF_MSG_LINK, "Setting LIMITING MODE\n");
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_ROM_VER2,
EDC_MODE_LIMITING);
} else {
DP(NETIF_MSG_LINK, "Setting LRM MODE\n");
if (cur_limiting_mode != EDC_MODE_LIMITING)
return 0;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_LRM_MODE,
0);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_ROM_VER2,
0x128);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_MISC_CTRL0,
0x4008);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_LRM_MODE,
0xaaaa);
}
return 0;
}
static u8 bnx2x_8727_set_limiting_mode(struct bnx2x *bp,
struct bnx2x_phy *phy,
u16 edc_mode)
{
u16 phy_identifier;
u16 rom_ver2_val;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER,
&phy_identifier);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER,
(phy_identifier & ~(1<<9)));
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_ROM_VER2,
&rom_ver2_val);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_ROM_VER2,
(rom_ver2_val & 0xff00) | (edc_mode & 0x00ff));
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER,
(phy_identifier | (1<<9)));
return 0;
}
static void bnx2x_8727_specific_func(struct bnx2x_phy *phy,
struct link_params *params,
u32 action)
{
struct bnx2x *bp = params->bp;
switch (action) {
case DISABLE_TX:
bnx2x_sfp_set_transmitter(params, phy, 0);
break;
case ENABLE_TX:
if (!(phy->flags & FLAGS_SFP_NOT_APPROVED))
bnx2x_sfp_set_transmitter(params, phy, 1);
break;
default:
DP(NETIF_MSG_LINK, "Function 0x%x not supported by 8727\n",
action);
return;
}
}
static void bnx2x_set_sfp_module_fault_led(struct link_params *params,
u8 gpio_mode)
{
struct bnx2x *bp = params->bp;
u32 fault_led_gpio = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[params->port].sfp_ctrl)) &
PORT_HW_CFG_FAULT_MODULE_LED_MASK;
switch (fault_led_gpio) {
case PORT_HW_CFG_FAULT_MODULE_LED_DISABLED:
return;
case PORT_HW_CFG_FAULT_MODULE_LED_GPIO0:
case PORT_HW_CFG_FAULT_MODULE_LED_GPIO1:
case PORT_HW_CFG_FAULT_MODULE_LED_GPIO2:
case PORT_HW_CFG_FAULT_MODULE_LED_GPIO3:
{
u8 gpio_port = bnx2x_get_gpio_port(params);
u16 gpio_pin = fault_led_gpio -
PORT_HW_CFG_FAULT_MODULE_LED_GPIO0;
DP(NETIF_MSG_LINK, "Set fault module-detected led "
"pin %x port %x mode %x\n",
gpio_pin, gpio_port, gpio_mode);
bnx2x_set_gpio(bp, gpio_pin, gpio_mode, gpio_port);
}
break;
default:
DP(NETIF_MSG_LINK, "Error: Invalid fault led mode 0x%x\n",
fault_led_gpio);
}
}
static u8 bnx2x_sfp_module_detection(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u16 edc_mode;
u8 rc = 0;
u32 val = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region, dev_info.
port_feature_config[params->port].config));
DP(NETIF_MSG_LINK, "SFP+ module plugged in/out detected on port %d\n",
params->port);
if (bnx2x_get_edc_mode(phy, params, &edc_mode) != 0) {
DP(NETIF_MSG_LINK, "Failed to get valid module type\n");
return -EINVAL;
} else if (bnx2x_verify_sfp_module(phy, params) != 0) {
DP(NETIF_MSG_LINK, "Module verification failed!!\n");
rc = -EINVAL;
bnx2x_set_sfp_module_fault_led(params,
MISC_REGISTERS_GPIO_HIGH);
if ((phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727) &&
((val & PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_MASK) ==
PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_POWER_DOWN)) {
DP(NETIF_MSG_LINK, "Shutdown SFP+ module!!\n");
bnx2x_8727_power_module(bp, phy, 0);
return rc;
}
} else {
bnx2x_set_sfp_module_fault_led(params, MISC_REGISTERS_GPIO_LOW);
}
if (phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727)
bnx2x_8727_power_module(bp, phy, 1);
if (phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8726)
bnx2x_8726_set_limiting_mode(bp, phy, edc_mode);
else
bnx2x_8727_set_limiting_mode(bp, phy, edc_mode);
if (rc == 0 ||
(val & PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_MASK) !=
PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_DISABLE_TX_LASER)
bnx2x_sfp_set_transmitter(params, phy, 1);
else
bnx2x_sfp_set_transmitter(params, phy, 0);
return rc;
}
void bnx2x_handle_module_detect_int(struct link_params *params)
{
struct bnx2x *bp = params->bp;
struct bnx2x_phy *phy = &params->phy[EXT_PHY1];
u32 gpio_val;
u8 port = params->port;
bnx2x_set_sfp_module_fault_led(params, MISC_REGISTERS_GPIO_HIGH);
gpio_val = bnx2x_get_gpio(bp, MISC_REGISTERS_GPIO_3, port);
if (gpio_val == 0) {
bnx2x_set_gpio_int(bp, MISC_REGISTERS_GPIO_3,
MISC_REGISTERS_GPIO_INT_OUTPUT_CLR,
port);
if (bnx2x_wait_for_sfp_module_initialized(phy, params) == 0)
bnx2x_sfp_module_detection(phy, params);
else
DP(NETIF_MSG_LINK, "SFP+ module is not initialized\n");
} else {
u32 val = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region, dev_info.
port_feature_config[params->port].
config));
bnx2x_set_gpio_int(bp, MISC_REGISTERS_GPIO_3,
MISC_REGISTERS_GPIO_INT_OUTPUT_SET,
port);
if ((val & PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_MASK) ==
PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_DISABLE_TX_LASER)
bnx2x_sfp_set_transmitter(params, phy, 0);
}
}
static u8 bnx2x_8706_8726_read_status(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
u8 link_up = 0;
u16 val1, val2, rx_sd, pcs_status;
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "XGXS 8706/8726\n");
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM, &val2);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_STATUS, &val1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_STATUS, &val2);
DP(NETIF_MSG_LINK, "8706/8726 LASI status 0x%x--> 0x%x\n", val1, val2);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_SD, &rx_sd);
bnx2x_cl45_read(bp, phy,
MDIO_PCS_DEVAD, MDIO_PCS_REG_STATUS, &pcs_status);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_LINK_STATUS, &val2);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_LINK_STATUS, &val2);
DP(NETIF_MSG_LINK, "8706/8726 rx_sd 0x%x pcs_status 0x%x 1Gbps"
" link_status 0x%x\n", rx_sd, pcs_status, val2);
link_up = ((rx_sd & pcs_status & 0x1) || (val2 & (1<<1)));
if (link_up) {
if (val2 & (1<<1))
vars->line_speed = SPEED_1000;
else
vars->line_speed = SPEED_10000;
bnx2x_ext_phy_resolve_fc(phy, params, vars);
vars->duplex = DUPLEX_FULL;
}
return link_up;
}
static u8 bnx2x_8706_config_init(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
u32 tx_en_mode;
u16 cnt, val, tmp1;
struct bnx2x *bp = params->bp;
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_HIGH, params->port);
bnx2x_ext_phy_hw_reset(bp, params->port);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 0xa040);
bnx2x_wait_reset_complete(bp, phy, params);
for (cnt = 0; cnt < 100; cnt++) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_ROM_VER1, &val);
if (val)
break;
msleep(10);
}
DP(NETIF_MSG_LINK, "XGXS 8706 is initialized after %d ms\n", cnt);
if ((params->feature_config_flags &
FEATURE_CONFIG_OVERRIDE_PREEMPHASIS_ENABLED)) {
u8 i;
u16 reg;
for (i = 0; i < 4; i++) {
reg = MDIO_XS_8706_REG_BANK_RX0 +
i*(MDIO_XS_8706_REG_BANK_RX1 -
MDIO_XS_8706_REG_BANK_RX0);
bnx2x_cl45_read(bp, phy, MDIO_XS_DEVAD, reg, &val);
val &= ~0x7;
val |= (phy->rx_preemphasis[i] & 0x7);
DP(NETIF_MSG_LINK, "Setting RX Equalizer to BCM8706"
" reg 0x%x <-- val 0x%x\n", reg, val);
bnx2x_cl45_write(bp, phy, MDIO_XS_DEVAD, reg, val);
}
}
if (phy->req_line_speed == SPEED_10000) {
DP(NETIF_MSG_LINK, "XGXS 8706 force 10Gbps\n");
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_DIGITAL_CTRL, 0x400);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL, 1);
} else {
DP(NETIF_MSG_LINK, "XGXS 8706 AutoNeg\n");
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_CL73, 0x040c);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_FC_LP, 0x0020);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_AN, 0x1000);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_ADV, (1<<5));
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CTRL, 0x1200);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM_CTRL,
0x0400);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL,
0x0004);
}
bnx2x_save_bcm_spirom_ver(bp, phy, params->port);
tx_en_mode = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[params->port].sfp_ctrl))
& PORT_HW_CFG_TX_LASER_MASK;
if (tx_en_mode == PORT_HW_CFG_TX_LASER_GPIO0) {
DP(NETIF_MSG_LINK, "Enabling TXONOFF_PWRDN_DIS\n");
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_DIGITAL_CTRL, &tmp1);
tmp1 |= 0x1;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_DIGITAL_CTRL, tmp1);
}
return 0;
}
static u8 bnx2x_8706_read_status(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
return bnx2x_8706_8726_read_status(phy, params, vars);
}
static void bnx2x_8726_config_loopback(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "PMA/PMD ext_phy_loopback: 8726\n");
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 0x0001);
}
static void bnx2x_8726_external_rom_boot(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
msleep(100);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_GEN_CTRL, 0x018B);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_GEN_CTRL,
MDIO_PMA_REG_GEN_CTRL_ROM_MICRO_RESET);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_MISC_CTRL1, 0x0001);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_GEN_CTRL,
MDIO_PMA_REG_GEN_CTRL_ROM_RESET_INTERNAL_MP);
msleep(150);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_MISC_CTRL1, 0x0000);
msleep(200);
bnx2x_save_bcm_spirom_ver(bp, phy, params->port);
}
static u8 bnx2x_8726_read_status(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u16 val1;
u8 link_up = bnx2x_8706_8726_read_status(phy, params, vars);
if (link_up) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_PHY_IDENTIFIER,
&val1);
if (val1 & (1<<15)) {
DP(NETIF_MSG_LINK, "Tx is disabled\n");
link_up = 0;
vars->line_speed = 0;
}
}
return link_up;
}
static u8 bnx2x_8726_config_init(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u32 val;
u32 swap_val, swap_override, aeu_gpio_mask, offset;
DP(NETIF_MSG_LINK, "Initializing BCM8726\n");
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 1<<15);
bnx2x_wait_reset_complete(bp, phy, params);
bnx2x_8726_external_rom_boot(phy, params);
bnx2x_sfp_module_detection(phy, params);
if (phy->req_line_speed == SPEED_1000) {
DP(NETIF_MSG_LINK, "Setting 1G force\n");
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 0x40);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_10G_CTRL2, 0xD);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL, 0x5);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM_CTRL,
0x400);
} else if ((phy->req_line_speed == SPEED_AUTO_NEG) &&
(phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_1G) &&
((phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G) !=
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G)) {
DP(NETIF_MSG_LINK, "Setting 1G clause37\n");
bnx2x_ext_phy_set_pause(params, phy, vars);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_ADV, 0x20);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_CL73, 0x040c);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_FC_LD, 0x0020);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_AN, 0x1000);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CTRL, 0x1200);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL, 0x4);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM_CTRL,
0x400);
} else {
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL, 1);
}
if ((params->feature_config_flags &
FEATURE_CONFIG_OVERRIDE_PREEMPHASIS_ENABLED)) {
DP(NETIF_MSG_LINK, "Setting TX_CTRL1 0x%x,"
"TX_CTRL2 0x%x\n",
phy->tx_preemphasis[0],
phy->tx_preemphasis[1]);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8726_TX_CTRL1,
phy->tx_preemphasis[0]);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8726_TX_CTRL2,
phy->tx_preemphasis[1]);
}
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_3,
MISC_REGISTERS_GPIO_INPUT_HI_Z, params->port);
swap_val = REG_RD(bp, NIG_REG_PORT_SWAP);
swap_override = REG_RD(bp, NIG_REG_STRAP_OVERRIDE);
if (params->port == 0) {
offset = MISC_REG_AEU_ENABLE1_FUNC_0_OUT_0;
aeu_gpio_mask = (swap_val && swap_override) ?
AEU_INPUTS_ATTN_BITS_GPIO3_FUNCTION_1 :
AEU_INPUTS_ATTN_BITS_GPIO3_FUNCTION_0;
} else {
offset = MISC_REG_AEU_ENABLE1_FUNC_1_OUT_0;
aeu_gpio_mask = (swap_val && swap_override) ?
AEU_INPUTS_ATTN_BITS_GPIO3_FUNCTION_0 :
AEU_INPUTS_ATTN_BITS_GPIO3_FUNCTION_1;
}
val = REG_RD(bp, offset);
val |= aeu_gpio_mask;
REG_WR(bp, offset, val);
return 0;
}
static void bnx2x_8726_link_reset(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "bnx2x_8726_link_reset port %d\n", params->port);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_GEN_CTRL, 0x0001);
}
static void bnx2x_8727_set_link_led(struct bnx2x_phy *phy,
struct link_params *params, u8 mode)
{
struct bnx2x *bp = params->bp;
u16 led_mode_bitmask = 0;
u16 gpio_pins_bitmask = 0;
u16 val;
if (!(phy->flags & FLAGS_NOC))
return;
switch (mode) {
case LED_MODE_FRONT_PANEL_OFF:
case LED_MODE_OFF:
led_mode_bitmask = 0;
gpio_pins_bitmask = 0x03;
break;
case LED_MODE_ON:
led_mode_bitmask = 0;
gpio_pins_bitmask = 0x02;
break;
case LED_MODE_OPER:
led_mode_bitmask = 0x60;
gpio_pins_bitmask = 0x11;
break;
}
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_PCS_OPT_CTRL,
&val);
val &= 0xff8f;
val |= led_mode_bitmask;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_PCS_OPT_CTRL,
val);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_GPIO_CTRL,
&val);
val &= 0xffe0;
val |= gpio_pins_bitmask;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_GPIO_CTRL,
val);
}
static void bnx2x_8727_hw_reset(struct bnx2x_phy *phy,
struct link_params *params) {
u32 swap_val, swap_override;
u8 port;
struct bnx2x *bp = params->bp;
swap_val = REG_RD(bp, NIG_REG_PORT_SWAP);
swap_override = REG_RD(bp, NIG_REG_STRAP_OVERRIDE);
port = (swap_val && swap_override) ^ 1;
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_1,
MISC_REGISTERS_GPIO_OUTPUT_LOW, port);
}
static u8 bnx2x_8727_config_init(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
u32 tx_en_mode;
u16 tmp1, val, mod_abs, tmp2;
u16 rx_alarm_ctrl_val;
u16 lasi_ctrl_val;
struct bnx2x *bp = params->bp;
bnx2x_wait_reset_complete(bp, phy, params);
rx_alarm_ctrl_val = (1<<2) | (1<<5) ;
lasi_ctrl_val = 0x0004;
DP(NETIF_MSG_LINK, "Initializing BCM8727\n");
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM_CTRL,
rx_alarm_ctrl_val);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL, lasi_ctrl_val);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_PHY_IDENTIFIER, &mod_abs);
mod_abs &= ~(1<<8);
if (!(phy->flags & FLAGS_NOC))
mod_abs &= ~(1<<9);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_PHY_IDENTIFIER, mod_abs);
bnx2x_cl45_read(bp, phy, MDIO_PMA_DEVAD, MDIO_PMA_REG_8727_PCS_OPT_CTRL,
&val);
val |= (1<<12);
if (phy->flags & FLAGS_NOC)
val |= (3<<5);
if (!(phy->flags & FLAGS_NOC))
val &= 0xff8f;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8727_PCS_OPT_CTRL, val);
bnx2x_8727_power_module(bp, phy, 1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_M8051_MSGOUT_REG, &tmp1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM, &tmp1);
if (phy->req_line_speed == SPEED_1000) {
DP(NETIF_MSG_LINK, "Setting 1G force\n");
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 0x40);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_10G_CTRL2, 0xD);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_10G_CTRL2, &tmp1);
DP(NETIF_MSG_LINK, "1.7 = 0x%x\n", tmp1);
if (DUAL_MEDIA(params)) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_PCS_GP, &val);
val |= (3<<10);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_PCS_GP, val);
}
} else if ((phy->req_line_speed == SPEED_AUTO_NEG) &&
((phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_1G)) &&
((phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G) !=
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G)) {
DP(NETIF_MSG_LINK, "Setting 1G clause37\n");
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_8727_MISC_CTRL, 0);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_AN, 0x1300);
} else {
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_8727_MISC_CTRL,
0x0020);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CL37_AN, 0x0100);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 0x2040);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_10G_CTRL2,
0x0008);
}
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8727_TWO_WIRE_SLAVE_ADDR,
0xa001);
if ((params->feature_config_flags &
FEATURE_CONFIG_OVERRIDE_PREEMPHASIS_ENABLED)) {
DP(NETIF_MSG_LINK, "Setting TX_CTRL1 0x%x, TX_CTRL2 0x%x\n",
phy->tx_preemphasis[0],
phy->tx_preemphasis[1]);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8727_TX_CTRL1,
phy->tx_preemphasis[0]);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8727_TX_CTRL2,
phy->tx_preemphasis[1]);
}
tx_en_mode = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[params->port].sfp_ctrl))
& PORT_HW_CFG_TX_LASER_MASK;
if (tx_en_mode == PORT_HW_CFG_TX_LASER_GPIO0) {
DP(NETIF_MSG_LINK, "Enabling TXONOFF_PWRDN_DIS\n");
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8727_OPT_CFG_REG, &tmp2);
tmp2 |= 0x1000;
tmp2 &= 0xFFEF;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8727_OPT_CFG_REG, tmp2);
}
return 0;
}
static void bnx2x_8727_handle_mod_abs(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u16 mod_abs, rx_alarm_status;
u32 val = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region, dev_info.
port_feature_config[params->port].
config));
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER, &mod_abs);
if (mod_abs & (1<<8)) {
DP(NETIF_MSG_LINK, "MOD_ABS indication "
"show module is absent\n");
mod_abs &= ~(1<<8);
if (!(phy->flags & FLAGS_NOC))
mod_abs &= ~(1<<9);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER, mod_abs);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_RX_ALARM, &rx_alarm_status);
} else {
DP(NETIF_MSG_LINK, "MOD_ABS indication "
"show module is present\n");
mod_abs |= (1<<8);
if (!(phy->flags & FLAGS_NOC))
mod_abs |= (1<<9);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER, mod_abs);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_RX_ALARM, &rx_alarm_status);
if ((val & PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_MASK) ==
PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_DISABLE_TX_LASER)
bnx2x_sfp_set_transmitter(params, phy, 0);
if (bnx2x_wait_for_sfp_module_initialized(phy, params) == 0)
bnx2x_sfp_module_detection(phy, params);
else
DP(NETIF_MSG_LINK, "SFP+ module is not initialized\n");
}
DP(NETIF_MSG_LINK, "8727 RX_ALARM_STATUS 0x%x\n",
rx_alarm_status);
}
static u8 bnx2x_8727_read_status(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u8 link_up = 0;
u16 link_status = 0;
u16 rx_alarm_status, lasi_ctrl, val1;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL,
&lasi_ctrl);
if (!lasi_ctrl)
return 0;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM,
&rx_alarm_status);
vars->line_speed = 0;
DP(NETIF_MSG_LINK, "8727 RX_ALARM_STATUS 0x%x\n", rx_alarm_status);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_STATUS, &val1);
DP(NETIF_MSG_LINK, "8727 LASI status 0x%x\n", val1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_M8051_MSGOUT_REG, &val1);
if (!(phy->flags & FLAGS_NOC) && !(rx_alarm_status & (1<<5))) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8727_GPIO_CTRL,
&val1);
if ((val1 & (1<<8)) == 0) {
DP(NETIF_MSG_LINK, "8727 Power fault has been detected"
" on port %d\n", params->port);
netdev_err(bp->dev, "Error: Power fault on Port %d has"
" been detected and the power to "
"that SFP+ module has been removed"
" to prevent failure of the card."
" Please remove the SFP+ module and"
" restart the system to clear this"
" error.\n",
params->port);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_RX_ALARM_CTRL, (1<<5));
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER, &val1);
val1 |= (1<<8);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_PHY_IDENTIFIER, val1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_RX_ALARM, &rx_alarm_status);
return 0;
}
}
if (rx_alarm_status & (1<<5)) {
bnx2x_8727_handle_mod_abs(phy, params);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_RX_ALARM_CTRL,
((1<<5) | (1<<2)));
}
DP(NETIF_MSG_LINK, "Enabling 8727 TX laser if SFP is approved\n");
bnx2x_8727_specific_func(phy, params, ENABLE_TX);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_PHY_IDENTIFIER, &val1);
if (val1 & (1<<15)) {
DP(NETIF_MSG_LINK, "Tx is disabled\n");
return 0;
}
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8073_SPEED_LINK_STATUS, &link_status);
if ((link_status & (1<<2)) && (!(link_status & (1<<15)))) {
link_up = 1;
vars->line_speed = SPEED_10000;
DP(NETIF_MSG_LINK, "port %x: External link up in 10G\n",
params->port);
} else if ((link_status & (1<<0)) && (!(link_status & (1<<13)))) {
link_up = 1;
vars->line_speed = SPEED_1000;
DP(NETIF_MSG_LINK, "port %x: External link up in 1G\n",
params->port);
} else {
link_up = 0;
DP(NETIF_MSG_LINK, "port %x: External link is down\n",
params->port);
}
if (link_up) {
bnx2x_ext_phy_resolve_fc(phy, params, vars);
vars->duplex = DUPLEX_FULL;
DP(NETIF_MSG_LINK, "duplex = 0x%x\n", vars->duplex);
}
if ((DUAL_MEDIA(params)) &&
(phy->req_line_speed == SPEED_1000)) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_PCS_GP, &val1);
if (link_up)
val1 &= ~(3<<10);
else
val1 |= (3<<10);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8727_PCS_GP, val1);
}
return link_up;
}
static void bnx2x_8727_link_reset(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
bnx2x_sfp_set_transmitter(params, phy, 0);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL, 0);
}
static void bnx2x_save_848xx_spirom_version(struct bnx2x_phy *phy,
struct link_params *params)
{
u16 val, fw_ver1, fw_ver2, cnt, adj;
struct bnx2x *bp = params->bp;
adj = 0;
if (phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84833)
adj = -1;
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, 0xA819 + adj, 0x0014);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, 0xA81A + adj, 0xc200);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, 0xA81B + adj, 0x0000);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, 0xA81C + adj, 0x0300);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, 0xA817 + adj, 0x0009);
for (cnt = 0; cnt < 100; cnt++) {
bnx2x_cl45_read(bp, phy, MDIO_PMA_DEVAD, 0xA818 + adj, &val);
if (val & 1)
break;
udelay(5);
}
if (cnt == 100) {
DP(NETIF_MSG_LINK, "Unable to read 848xx phy fw version(1)\n");
bnx2x_save_spirom_version(bp, params->port, 0,
phy->ver_addr);
return;
}
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, 0xA819 + adj, 0x0000);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, 0xA81A + adj, 0xc200);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, 0xA817 + adj, 0x000A);
for (cnt = 0; cnt < 100; cnt++) {
bnx2x_cl45_read(bp, phy, MDIO_PMA_DEVAD, 0xA818 + adj, &val);
if (val & 1)
break;
udelay(5);
}
if (cnt == 100) {
DP(NETIF_MSG_LINK, "Unable to read 848xx phy fw version(2)\n");
bnx2x_save_spirom_version(bp, params->port, 0,
phy->ver_addr);
return;
}
bnx2x_cl45_read(bp, phy, MDIO_PMA_DEVAD, 0xA81B + adj, &fw_ver1);
bnx2x_cl45_read(bp, phy, MDIO_PMA_DEVAD, 0xA81C + adj, &fw_ver2);
bnx2x_save_spirom_version(bp, params->port, (fw_ver2<<16) | fw_ver1,
phy->ver_addr);
}
static void bnx2x_848xx_set_led(struct bnx2x *bp,
struct bnx2x_phy *phy)
{
u16 val, adj;
adj = 0;
if (phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84833)
adj = -1;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LINK_SIGNAL + adj, &val);
val &= 0xFE00;
val |= 0x0092;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LINK_SIGNAL + adj, val);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED1_MASK + adj,
0x80);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED2_MASK + adj,
0x18);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED3_MASK + adj,
0x0006);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED3_BLINK + adj,
0);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_84823_CTL_LED_CTL_1 + adj, &val);
val |= MDIO_PMA_REG_84823_LED3_STRETCH_EN;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_84823_CTL_LED_CTL_1 + adj, val);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD,
0xFFFB, 0xFFFD);
}
static u8 bnx2x_848xx_cmn_config_init(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u16 autoneg_val, an_1000_val, an_10_100_val;
bnx2x_bits_en(bp, NIG_REG_LATCH_BC_0 + params->port*4,
1 << NIG_LATCH_BC_ENABLE_MI_INT);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 0x0000);
bnx2x_848xx_set_led(bp, phy);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_8481_1000T_CTRL,
&an_1000_val);
bnx2x_ext_phy_set_pause(params, phy, vars);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_8481_LEGACY_AN_ADV,
&an_10_100_val);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_8481_LEGACY_MII_CTRL,
&autoneg_val);
autoneg_val &= ~((1<<6) | (1<<8) | (1<<9) | (1<<12) | (1<<13));
an_10_100_val &= ~((1<<5) | (1<<6) | (1<<7) | (1<<8));
if (((phy->req_line_speed == SPEED_AUTO_NEG) &&
(phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_1G)) ||
(phy->req_line_speed == SPEED_1000)) {
an_1000_val |= (1<<8);
autoneg_val |= (1<<9 | 1<<12);
if (phy->req_duplex == DUPLEX_FULL)
an_1000_val |= (1<<9);
DP(NETIF_MSG_LINK, "Advertising 1G\n");
} else
an_1000_val &= ~((1<<8) | (1<<9));
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_8481_1000T_CTRL,
an_1000_val);
if (((phy->req_line_speed == SPEED_AUTO_NEG) &&
(phy->speed_cap_mask &
(PORT_HW_CFG_SPEED_CAPABILITY_D0_100M_FULL |
PORT_HW_CFG_SPEED_CAPABILITY_D0_100M_HALF)))) {
an_10_100_val |= (1<<7);
autoneg_val |= (1<<9 | 1<<12);
if (phy->req_duplex == DUPLEX_FULL)
an_10_100_val |= (1<<8);
DP(NETIF_MSG_LINK, "Advertising 100M\n");
}
if (((phy->req_line_speed == SPEED_AUTO_NEG) &&
(phy->speed_cap_mask &
(PORT_HW_CFG_SPEED_CAPABILITY_D0_10M_FULL |
PORT_HW_CFG_SPEED_CAPABILITY_D0_10M_HALF)))) {
an_10_100_val |= (1<<5);
autoneg_val |= (1<<9 | 1<<12);
if (phy->req_duplex == DUPLEX_FULL)
an_10_100_val |= (1<<6);
DP(NETIF_MSG_LINK, "Advertising 10M\n");
}
if (phy->req_line_speed == SPEED_100) {
autoneg_val |= (1<<13);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_8481_AUX_CTRL,
(1<<15 | 1<<9 | 7<<0));
DP(NETIF_MSG_LINK, "Setting 100M force\n");
}
if (phy->req_line_speed == SPEED_10) {
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_8481_AUX_CTRL,
(1<<15 | 1<<9 | 7<<0));
DP(NETIF_MSG_LINK, "Setting 10M force\n");
}
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_8481_LEGACY_AN_ADV,
an_10_100_val);
if (phy->req_duplex == DUPLEX_FULL)
autoneg_val |= (1<<8);
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_8481_LEGACY_MII_CTRL, autoneg_val);
if (((phy->req_line_speed == SPEED_AUTO_NEG) &&
(phy->speed_cap_mask &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G)) ||
(phy->req_line_speed == SPEED_10000)) {
DP(NETIF_MSG_LINK, "Advertising 10G\n");
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CTRL,
0x3200);
} else if (phy->req_line_speed != SPEED_10 &&
phy->req_line_speed != SPEED_100) {
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_8481_10GBASE_T_AN_CTRL,
1);
}
bnx2x_save_848xx_spirom_version(phy, params);
return 0;
}
static u8 bnx2x_8481_config_init(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_HIGH, params->port);
bnx2x_ext_phy_hw_reset(bp, params->port);
bnx2x_wait_reset_complete(bp, phy, params);
bnx2x_cl45_write(bp, phy, MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 1<<15);
return bnx2x_848xx_cmn_config_init(phy, params, vars);
}
static u8 bnx2x_848x3_config_init(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u8 port, initialize = 1;
u16 val, adj;
u16 temp;
u32 actual_phy_selection, cms_enable;
u8 rc = 0;
adj = 0;
if (phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84833)
adj = 3;
msleep(1);
if (CHIP_IS_E2(bp))
port = BP_PATH(bp);
else
port = params->port;
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_3,
MISC_REGISTERS_GPIO_OUTPUT_HIGH,
port);
bnx2x_wait_reset_complete(bp, phy, params);
msleep(50);
temp = vars->line_speed;
vars->line_speed = SPEED_10000;
bnx2x_set_autoneg(&params->phy[INT_PHY], params, vars, 0);
bnx2x_program_serdes(&params->phy[INT_PHY], params, vars);
vars->line_speed = temp;
bnx2x_cl45_read(bp, phy, MDIO_CTL_DEVAD,
MDIO_CTL_REG_84823_MEDIA + adj, &val);
val &= ~(MDIO_CTL_REG_84823_MEDIA_MAC_MASK |
MDIO_CTL_REG_84823_MEDIA_LINE_MASK |
MDIO_CTL_REG_84823_MEDIA_COPPER_CORE_DOWN |
MDIO_CTL_REG_84823_MEDIA_PRIORITY_MASK |
MDIO_CTL_REG_84823_MEDIA_FIBER_1G);
val |= MDIO_CTL_REG_84823_CTRL_MAC_XFI |
MDIO_CTL_REG_84823_MEDIA_LINE_XAUI_L;
actual_phy_selection = bnx2x_phy_selection(params);
switch (actual_phy_selection) {
case PORT_HW_CFG_PHY_SELECTION_HARDWARE_DEFAULT:
break;
case PORT_HW_CFG_PHY_SELECTION_FIRST_PHY_PRIORITY:
val |= MDIO_CTL_REG_84823_MEDIA_PRIORITY_COPPER;
break;
case PORT_HW_CFG_PHY_SELECTION_SECOND_PHY_PRIORITY:
val |= MDIO_CTL_REG_84823_MEDIA_PRIORITY_FIBER;
break;
case PORT_HW_CFG_PHY_SELECTION_FIRST_PHY:
break;
case PORT_HW_CFG_PHY_SELECTION_SECOND_PHY:
val |= MDIO_CTL_REG_84823_MEDIA_COPPER_CORE_DOWN;
initialize = 0;
break;
}
if (params->phy[EXT_PHY2].req_line_speed == SPEED_1000)
val |= MDIO_CTL_REG_84823_MEDIA_FIBER_1G;
bnx2x_cl45_write(bp, phy, MDIO_CTL_DEVAD,
MDIO_CTL_REG_84823_MEDIA + adj, val);
DP(NETIF_MSG_LINK, "Multi_phy config = 0x%x, Media control = 0x%x\n",
params->multi_phy_config, val);
if (initialize)
rc = bnx2x_848xx_cmn_config_init(phy, params, vars);
else
bnx2x_save_848xx_spirom_version(phy, params);
cms_enable = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[params->port].default_cfg)) &
PORT_HW_CFG_ENABLE_CMS_MASK;
bnx2x_cl45_read(bp, phy, MDIO_CTL_DEVAD,
MDIO_CTL_REG_84823_USER_CTRL_REG, &val);
if (cms_enable)
val |= MDIO_CTL_REG_84823_USER_CTRL_CMS;
else
val &= ~MDIO_CTL_REG_84823_USER_CTRL_CMS;
bnx2x_cl45_write(bp, phy, MDIO_CTL_DEVAD,
MDIO_CTL_REG_84823_USER_CTRL_REG, val);
return rc;
}
static u8 bnx2x_848xx_read_status(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u16 val, val1, val2, adj;
u8 link_up = 0;
adj = 0;
if (phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84833)
adj = -1;
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, 0xFFFA, &val1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_8481_PMD_SIGNAL + adj,
&val2);
DP(NETIF_MSG_LINK, "BCM848xx: PMD_SIGNAL 1.a811 = 0x%x\n", val2);
if (val2 & (1<<11)) {
vars->line_speed = SPEED_10000;
vars->duplex = DUPLEX_FULL;
link_up = 1;
bnx2x_ext_phy_10G_an_resolve(bp, phy, vars);
} else {
u16 legacy_status, legacy_speed;
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_8481_EXPANSION_REG_ACCESS, 0xf42);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_8481_EXPANSION_REG_RD_RW,
&legacy_status);
DP(NETIF_MSG_LINK, "Legacy speed status"
" = 0x%x\n", legacy_status);
link_up = ((legacy_status & (1<<11)) == (1<<11));
if (link_up) {
legacy_speed = (legacy_status & (3<<9));
if (legacy_speed == (0<<9))
vars->line_speed = SPEED_10;
else if (legacy_speed == (1<<9))
vars->line_speed = SPEED_100;
else if (legacy_speed == (2<<9))
vars->line_speed = SPEED_1000;
else
vars->line_speed = 0;
if (legacy_status & (1<<8))
vars->duplex = DUPLEX_FULL;
else
vars->duplex = DUPLEX_HALF;
DP(NETIF_MSG_LINK, "Link is up in %dMbps,"
" is_duplex_full= %d\n", vars->line_speed,
(vars->duplex == DUPLEX_FULL));
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_8481_LEGACY_MII_STATUS,
&val);
if (val & (1<<5))
vars->link_status |=
LINK_STATUS_AUTO_NEGOTIATE_COMPLETE;
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD,
MDIO_AN_REG_8481_LEGACY_AN_EXPANSION,
&val);
if ((val & (1<<0)) == 0)
vars->link_status |=
LINK_STATUS_PARALLEL_DETECTION_USED;
}
}
if (link_up) {
DP(NETIF_MSG_LINK, "BCM84823: link speed is %d\n",
vars->line_speed);
bnx2x_ext_phy_resolve_fc(phy, params, vars);
}
return link_up;
}
static u8 bnx2x_848xx_format_ver(u32 raw_ver, u8 *str, u16 *len)
{
u8 status = 0;
u32 spirom_ver;
spirom_ver = ((raw_ver & 0xF80) >> 7) << 16 | (raw_ver & 0x7F);
status = bnx2x_format_ver(spirom_ver, str, len);
return status;
}
static void bnx2x_8481_hw_reset(struct bnx2x_phy *phy,
struct link_params *params)
{
bnx2x_set_gpio(params->bp, MISC_REGISTERS_GPIO_1,
MISC_REGISTERS_GPIO_OUTPUT_LOW, 0);
bnx2x_set_gpio(params->bp, MISC_REGISTERS_GPIO_1,
MISC_REGISTERS_GPIO_OUTPUT_LOW, 1);
}
static void bnx2x_8481_link_reset(struct bnx2x_phy *phy,
struct link_params *params)
{
bnx2x_cl45_write(params->bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CTRL, 0x0000);
bnx2x_cl45_write(params->bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 1);
}
static void bnx2x_848x3_link_reset(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
u8 port;
if (CHIP_IS_E2(bp))
port = BP_PATH(bp);
else
port = params->port;
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_3,
MISC_REGISTERS_GPIO_OUTPUT_LOW,
port);
}
static void bnx2x_848xx_set_link_led(struct bnx2x_phy *phy,
struct link_params *params, u8 mode)
{
struct bnx2x *bp = params->bp;
u16 val;
switch (mode) {
case LED_MODE_OFF:
DP(NETIF_MSG_LINK, "Port 0x%x: LED MODE OFF\n", params->port);
if ((params->hw_led_mode << SHARED_HW_CFG_LED_MODE_SHIFT) ==
SHARED_HW_CFG_LED_EXTPHY1) {
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED1_MASK,
0x0);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED2_MASK,
0x0);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED3_MASK,
0x0);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED5_MASK,
0x0);
} else {
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED1_MASK,
0x0);
}
break;
case LED_MODE_FRONT_PANEL_OFF:
DP(NETIF_MSG_LINK, "Port 0x%x: LED MODE FRONT PANEL OFF\n",
params->port);
if ((params->hw_led_mode << SHARED_HW_CFG_LED_MODE_SHIFT) ==
SHARED_HW_CFG_LED_EXTPHY1) {
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED1_MASK,
0x0);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED2_MASK,
0x0);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED3_MASK,
0x0);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED5_MASK,
0x20);
} else {
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED1_MASK,
0x0);
}
break;
case LED_MODE_ON:
DP(NETIF_MSG_LINK, "Port 0x%x: LED MODE ON\n", params->port);
if ((params->hw_led_mode << SHARED_HW_CFG_LED_MODE_SHIFT) ==
SHARED_HW_CFG_LED_EXTPHY1) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LINK_SIGNAL,
&val);
val &= 0x8000;
val |= 0x2492;
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LINK_SIGNAL,
val);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED1_MASK,
0x0);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED2_MASK,
0x20);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED3_MASK,
0x20);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED5_MASK,
0x0);
} else {
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED1_MASK,
0x20);
}
break;
case LED_MODE_OPER:
DP(NETIF_MSG_LINK, "Port 0x%x: LED MODE OPER\n", params->port);
if ((params->hw_led_mode << SHARED_HW_CFG_LED_MODE_SHIFT) ==
SHARED_HW_CFG_LED_EXTPHY1) {
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LINK_SIGNAL,
&val);
if (!((val &
MDIO_PMA_REG_8481_LINK_SIGNAL_LED4_ENABLE_MASK)
>> MDIO_PMA_REG_8481_LINK_SIGNAL_LED4_ENABLE_SHIFT)) {
DP(NETIF_MSG_LINK, "Setting LINK_SIGNAL\n");
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LINK_SIGNAL,
0xa492);
}
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED1_MASK,
0x10);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED2_MASK,
0x80);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED3_MASK,
0x98);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED5_MASK,
0x40);
} else {
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LED1_MASK,
0x80);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LINK_SIGNAL,
&val);
val &= ~(7<<6);
val |= (1<<6);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_8481_LINK_SIGNAL,
val);
}
break;
}
}
static void bnx2x_7101_config_loopback(struct bnx2x_phy *phy,
struct link_params *params)
{
struct bnx2x *bp = params->bp;
bnx2x_cl45_write(bp, phy,
MDIO_XS_DEVAD, MDIO_XS_SFX7101_XGXS_TEST1, 0x100);
}
static u8 bnx2x_7101_config_init(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
u16 fw_ver1, fw_ver2, val;
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "Setting the SFX7101 LASI indication\n");
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_HIGH, params->port);
bnx2x_ext_phy_hw_reset(bp, params->port);
bnx2x_wait_reset_complete(bp, phy, params);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_CTRL, 0x1);
DP(NETIF_MSG_LINK, "Setting the SFX7101 LED to blink on traffic\n");
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_7107_LED_CNTL, (1<<3));
bnx2x_ext_phy_set_pause(params, phy, vars);
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CTRL, &val);
val |= 0x200;
bnx2x_cl45_write(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_CTRL, val);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_7101_VER1, &fw_ver1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_7101_VER2, &fw_ver2);
bnx2x_save_spirom_version(bp, params->port,
(u32)(fw_ver1<<16 | fw_ver2), phy->ver_addr);
return 0;
}
static u8 bnx2x_7101_read_status(struct bnx2x_phy *phy,
struct link_params *params,
struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
u8 link_up;
u16 val1, val2;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_STATUS, &val2);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_LASI_STATUS, &val1);
DP(NETIF_MSG_LINK, "10G-base-T LASI status 0x%x->0x%x\n",
val2, val1);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_STATUS, &val2);
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_STATUS, &val1);
DP(NETIF_MSG_LINK, "10G-base-T PMA status 0x%x->0x%x\n",
val2, val1);
link_up = ((val1 & 4) == 4);
if (link_up) {
bnx2x_cl45_read(bp, phy,
MDIO_AN_DEVAD, MDIO_AN_REG_MASTER_STATUS,
&val2);
vars->line_speed = SPEED_10000;
vars->duplex = DUPLEX_FULL;
DP(NETIF_MSG_LINK, "SFX7101 AN status 0x%x->Master=%x\n",
val2, (val2 & (1<<14)));
bnx2x_ext_phy_10G_an_resolve(bp, phy, vars);
bnx2x_ext_phy_resolve_fc(phy, params, vars);
}
return link_up;
}
static u8 bnx2x_7101_format_ver(u32 spirom_ver, u8 *str, u16 *len)
{
if (*len < 5)
return -EINVAL;
str[0] = (spirom_ver & 0xFF);
str[1] = (spirom_ver & 0xFF00) >> 8;
str[2] = (spirom_ver & 0xFF0000) >> 16;
str[3] = (spirom_ver & 0xFF000000) >> 24;
str[4] = '\0';
*len -= 5;
return 0;
}
void bnx2x_sfx7101_sp_sw_reset(struct bnx2x *bp, struct bnx2x_phy *phy)
{
u16 val, cnt;
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_7101_RESET, &val);
for (cnt = 0; cnt < 10; cnt++) {
msleep(50);
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_7101_RESET,
(val | (1<<15)));
bnx2x_cl45_read(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_7101_RESET, &val);
if ((val & (1<<15)) == 0)
break;
}
}
static void bnx2x_7101_hw_reset(struct bnx2x_phy *phy,
struct link_params *params) {
bnx2x_set_gpio(params->bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_LOW, params->port);
bnx2x_set_gpio(params->bp, MISC_REGISTERS_GPIO_1,
MISC_REGISTERS_GPIO_OUTPUT_LOW, params->port);
}
static void bnx2x_7101_set_link_led(struct bnx2x_phy *phy,
struct link_params *params, u8 mode)
{
u16 val = 0;
struct bnx2x *bp = params->bp;
switch (mode) {
case LED_MODE_FRONT_PANEL_OFF:
case LED_MODE_OFF:
val = 2;
break;
case LED_MODE_ON:
val = 1;
break;
case LED_MODE_OPER:
val = 0;
break;
}
bnx2x_cl45_write(bp, phy,
MDIO_PMA_DEVAD,
MDIO_PMA_REG_7107_LINK_LED_CNTL,
val);
}
static void bnx2x_populate_preemphasis(struct bnx2x *bp, u32 shmem_base,
struct bnx2x_phy *phy, u8 port,
u8 phy_index)
{
u32 rx = 0, tx = 0, i;
for (i = 0; i < 2; i++) {
if (phy_index == INT_PHY || phy_index == EXT_PHY1) {
rx = REG_RD(bp, shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[port].xgxs_config_rx[i<<1]));
tx = REG_RD(bp, shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[port].xgxs_config_tx[i<<1]));
} else {
rx = REG_RD(bp, shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[port].xgxs_config2_rx[i<<1]));
tx = REG_RD(bp, shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[port].xgxs_config2_rx[i<<1]));
}
phy->rx_preemphasis[i << 1] = ((rx>>16) & 0xffff);
phy->rx_preemphasis[(i << 1) + 1] = (rx & 0xffff);
phy->tx_preemphasis[i << 1] = ((tx>>16) & 0xffff);
phy->tx_preemphasis[(i << 1) + 1] = (tx & 0xffff);
}
}
static u32 bnx2x_get_ext_phy_config(struct bnx2x *bp, u32 shmem_base,
u8 phy_index, u8 port)
{
u32 ext_phy_config = 0;
switch (phy_index) {
case EXT_PHY1:
ext_phy_config = REG_RD(bp, shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[port].external_phy_config));
break;
case EXT_PHY2:
ext_phy_config = REG_RD(bp, shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[port].external_phy_config2));
break;
default:
DP(NETIF_MSG_LINK, "Invalid phy_index %d\n", phy_index);
return -EINVAL;
}
return ext_phy_config;
}
static u8 bnx2x_populate_int_phy(struct bnx2x *bp, u32 shmem_base, u8 port,
struct bnx2x_phy *phy)
{
u32 phy_addr;
u32 chip_id;
u32 switch_cfg = (REG_RD(bp, shmem_base +
offsetof(struct shmem_region,
dev_info.port_feature_config[port].link_config)) &
PORT_FEATURE_CONNECTED_SWITCH_MASK);
chip_id = REG_RD(bp, MISC_REG_CHIP_NUM) << 16;
switch (switch_cfg) {
case SWITCH_CFG_1G:
phy_addr = REG_RD(bp,
NIG_REG_SERDES0_CTRL_PHY_ADDR +
port * 0x10);
*phy = phy_serdes;
break;
case SWITCH_CFG_10G:
phy_addr = REG_RD(bp,
NIG_REG_XGXS0_CTRL_PHY_ADDR +
port * 0x18);
*phy = phy_xgxs;
break;
default:
DP(NETIF_MSG_LINK, "Invalid switch_cfg\n");
return -EINVAL;
}
phy->addr = (u8)phy_addr;
phy->mdio_ctrl = bnx2x_get_emac_base(bp,
SHARED_HW_CFG_MDC_MDIO_ACCESS1_BOTH,
port);
if (CHIP_IS_E2(bp))
phy->def_md_devad = E2_DEFAULT_PHY_DEV_ADDR;
else
phy->def_md_devad = DEFAULT_PHY_DEV_ADDR;
DP(NETIF_MSG_LINK, "Internal phy port=%d, addr=0x%x, mdio_ctl=0x%x\n",
port, phy->addr, phy->mdio_ctrl);
bnx2x_populate_preemphasis(bp, shmem_base, phy, port, INT_PHY);
return 0;
}
static u8 bnx2x_populate_ext_phy(struct bnx2x *bp,
u8 phy_index,
u32 shmem_base,
u32 shmem2_base,
u8 port,
struct bnx2x_phy *phy)
{
u32 ext_phy_config, phy_type, config2;
u32 mdc_mdio_access = SHARED_HW_CFG_MDC_MDIO_ACCESS1_BOTH;
ext_phy_config = bnx2x_get_ext_phy_config(bp, shmem_base,
phy_index, port);
phy_type = XGXS_EXT_PHY_TYPE(ext_phy_config);
switch (phy_type) {
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8073:
mdc_mdio_access = SHARED_HW_CFG_MDC_MDIO_ACCESS1_SWAPPED;
*phy = phy_8073;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8705:
*phy = phy_8705;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8706:
*phy = phy_8706;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8726:
mdc_mdio_access = SHARED_HW_CFG_MDC_MDIO_ACCESS1_EMAC1;
*phy = phy_8726;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727_NOC:
mdc_mdio_access = SHARED_HW_CFG_MDC_MDIO_ACCESS1_EMAC1;
*phy = phy_8727;
phy->flags |= FLAGS_NOC;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727:
mdc_mdio_access = SHARED_HW_CFG_MDC_MDIO_ACCESS1_EMAC1;
*phy = phy_8727;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8481:
*phy = phy_8481;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84823:
*phy = phy_84823;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84833:
*phy = phy_84833;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_SFX7101:
*phy = phy_7101;
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_FAILURE:
*phy = phy_null;
return -EINVAL;
default:
*phy = phy_null;
return 0;
}
phy->addr = XGXS_EXT_PHY_ADDR(ext_phy_config);
bnx2x_populate_preemphasis(bp, shmem_base, phy, port, phy_index);
config2 = REG_RD(bp, shmem_base + offsetof(struct shmem_region,
dev_info.shared_hw_config.config2));
if (phy_index == EXT_PHY1) {
phy->ver_addr = shmem_base + offsetof(struct shmem_region,
port_mb[port].ext_phy_fw_version);
if (config2 & SHARED_HW_CFG_MDC_MDIO_ACCESS1_MASK)
mdc_mdio_access = config2 &
SHARED_HW_CFG_MDC_MDIO_ACCESS1_MASK;
} else {
u32 size = REG_RD(bp, shmem2_base);
if (size >
offsetof(struct shmem2_region, ext_phy_fw_version2)) {
phy->ver_addr = shmem2_base +
offsetof(struct shmem2_region,
ext_phy_fw_version2[port]);
}
if (config2 & SHARED_HW_CFG_MDC_MDIO_ACCESS2_MASK)
mdc_mdio_access = (config2 &
SHARED_HW_CFG_MDC_MDIO_ACCESS2_MASK) >>
(SHARED_HW_CFG_MDC_MDIO_ACCESS2_SHIFT -
SHARED_HW_CFG_MDC_MDIO_ACCESS1_SHIFT);
}
phy->mdio_ctrl = bnx2x_get_emac_base(bp, mdc_mdio_access, port);
if (mdc_mdio_access != SHARED_HW_CFG_MDC_MDIO_ACCESS1_BOTH)
phy->flags |= FLAGS_HW_LOCK_REQUIRED;
DP(NETIF_MSG_LINK, "phy_type 0x%x port %d found in index %d\n",
phy_type, port, phy_index);
DP(NETIF_MSG_LINK, " addr=0x%x, mdio_ctl=0x%x\n",
phy->addr, phy->mdio_ctrl);
return 0;
}
static u8 bnx2x_populate_phy(struct bnx2x *bp, u8 phy_index, u32 shmem_base,
u32 shmem2_base, u8 port, struct bnx2x_phy *phy)
{
u8 status = 0;
phy->type = PORT_HW_CFG_XGXS_EXT_PHY_TYPE_NOT_CONN;
if (phy_index == INT_PHY)
return bnx2x_populate_int_phy(bp, shmem_base, port, phy);
status = bnx2x_populate_ext_phy(bp, phy_index, shmem_base, shmem2_base,
port, phy);
return status;
}
static void bnx2x_phy_def_cfg(struct link_params *params,
struct bnx2x_phy *phy,
u8 phy_index)
{
struct bnx2x *bp = params->bp;
u32 link_config;
if (phy_index == EXT_PHY2) {
link_config = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region, dev_info.
port_feature_config[params->port].link_config2));
phy->speed_cap_mask = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region,
dev_info.
port_hw_config[params->port].speed_capability_mask2));
} else {
link_config = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region, dev_info.
port_feature_config[params->port].link_config));
phy->speed_cap_mask = REG_RD(bp, params->shmem_base +
offsetof(struct shmem_region,
dev_info.
port_hw_config[params->port].speed_capability_mask));
}
DP(NETIF_MSG_LINK, "Default config phy idx %x cfg 0x%x speed_cap_mask"
" 0x%x\n", phy_index, link_config, phy->speed_cap_mask);
phy->req_duplex = DUPLEX_FULL;
switch (link_config & PORT_FEATURE_LINK_SPEED_MASK) {
case PORT_FEATURE_LINK_SPEED_10M_HALF:
phy->req_duplex = DUPLEX_HALF;
case PORT_FEATURE_LINK_SPEED_10M_FULL:
phy->req_line_speed = SPEED_10;
break;
case PORT_FEATURE_LINK_SPEED_100M_HALF:
phy->req_duplex = DUPLEX_HALF;
case PORT_FEATURE_LINK_SPEED_100M_FULL:
phy->req_line_speed = SPEED_100;
break;
case PORT_FEATURE_LINK_SPEED_1G:
phy->req_line_speed = SPEED_1000;
break;
case PORT_FEATURE_LINK_SPEED_2_5G:
phy->req_line_speed = SPEED_2500;
break;
case PORT_FEATURE_LINK_SPEED_10G_CX4:
phy->req_line_speed = SPEED_10000;
break;
default:
phy->req_line_speed = SPEED_AUTO_NEG;
break;
}
switch (link_config & PORT_FEATURE_FLOW_CONTROL_MASK) {
case PORT_FEATURE_FLOW_CONTROL_AUTO:
phy->req_flow_ctrl = BNX2X_FLOW_CTRL_AUTO;
break;
case PORT_FEATURE_FLOW_CONTROL_TX:
phy->req_flow_ctrl = BNX2X_FLOW_CTRL_TX;
break;
case PORT_FEATURE_FLOW_CONTROL_RX:
phy->req_flow_ctrl = BNX2X_FLOW_CTRL_RX;
break;
case PORT_FEATURE_FLOW_CONTROL_BOTH:
phy->req_flow_ctrl = BNX2X_FLOW_CTRL_BOTH;
break;
default:
phy->req_flow_ctrl = BNX2X_FLOW_CTRL_NONE;
break;
}
}
u32 bnx2x_phy_selection(struct link_params *params)
{
u32 phy_config_swapped, prio_cfg;
u32 return_cfg = PORT_HW_CFG_PHY_SELECTION_HARDWARE_DEFAULT;
phy_config_swapped = params->multi_phy_config &
PORT_HW_CFG_PHY_SWAPPED_ENABLED;
prio_cfg = params->multi_phy_config &
PORT_HW_CFG_PHY_SELECTION_MASK;
if (phy_config_swapped) {
switch (prio_cfg) {
case PORT_HW_CFG_PHY_SELECTION_FIRST_PHY_PRIORITY:
return_cfg = PORT_HW_CFG_PHY_SELECTION_SECOND_PHY_PRIORITY;
break;
case PORT_HW_CFG_PHY_SELECTION_SECOND_PHY_PRIORITY:
return_cfg = PORT_HW_CFG_PHY_SELECTION_FIRST_PHY_PRIORITY;
break;
case PORT_HW_CFG_PHY_SELECTION_SECOND_PHY:
return_cfg = PORT_HW_CFG_PHY_SELECTION_FIRST_PHY;
break;
case PORT_HW_CFG_PHY_SELECTION_FIRST_PHY:
return_cfg = PORT_HW_CFG_PHY_SELECTION_SECOND_PHY;
break;
}
} else
return_cfg = prio_cfg;
return return_cfg;
}
u8 bnx2x_phy_probe(struct link_params *params)
{
u8 phy_index, actual_phy_idx, link_cfg_idx;
u32 phy_config_swapped;
struct bnx2x *bp = params->bp;
struct bnx2x_phy *phy;
params->num_phys = 0;
DP(NETIF_MSG_LINK, "Begin phy probe\n");
phy_config_swapped = params->multi_phy_config &
PORT_HW_CFG_PHY_SWAPPED_ENABLED;
for (phy_index = INT_PHY; phy_index < MAX_PHYS;
phy_index++) {
link_cfg_idx = LINK_CONFIG_IDX(phy_index);
actual_phy_idx = phy_index;
if (phy_config_swapped) {
if (phy_index == EXT_PHY1)
actual_phy_idx = EXT_PHY2;
else if (phy_index == EXT_PHY2)
actual_phy_idx = EXT_PHY1;
}
DP(NETIF_MSG_LINK, "phy_config_swapped %x, phy_index %x,"
" actual_phy_idx %x\n", phy_config_swapped,
phy_index, actual_phy_idx);
phy = &params->phy[actual_phy_idx];
if (bnx2x_populate_phy(bp, phy_index, params->shmem_base,
params->shmem2_base, params->port,
phy) != 0) {
params->num_phys = 0;
DP(NETIF_MSG_LINK, "phy probe failed in phy index %d\n",
phy_index);
for (phy_index = INT_PHY;
phy_index < MAX_PHYS;
phy_index++)
*phy = phy_null;
return -EINVAL;
}
if (phy->type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_NOT_CONN)
break;
bnx2x_phy_def_cfg(params, phy, phy_index);
params->num_phys++;
}
DP(NETIF_MSG_LINK, "End phy probe. #phys found %x\n", params->num_phys);
return 0;
}
static void set_phy_vars(struct link_params *params)
{
struct bnx2x *bp = params->bp;
u8 actual_phy_idx, phy_index, link_cfg_idx;
u8 phy_config_swapped = params->multi_phy_config &
PORT_HW_CFG_PHY_SWAPPED_ENABLED;
for (phy_index = INT_PHY; phy_index < params->num_phys;
phy_index++) {
link_cfg_idx = LINK_CONFIG_IDX(phy_index);
actual_phy_idx = phy_index;
if (phy_config_swapped) {
if (phy_index == EXT_PHY1)
actual_phy_idx = EXT_PHY2;
else if (phy_index == EXT_PHY2)
actual_phy_idx = EXT_PHY1;
}
params->phy[actual_phy_idx].req_flow_ctrl =
params->req_flow_ctrl[link_cfg_idx];
params->phy[actual_phy_idx].req_line_speed =
params->req_line_speed[link_cfg_idx];
params->phy[actual_phy_idx].speed_cap_mask =
params->speed_cap_mask[link_cfg_idx];
params->phy[actual_phy_idx].req_duplex =
params->req_duplex[link_cfg_idx];
DP(NETIF_MSG_LINK, "req_flow_ctrl %x, req_line_speed %x,"
" speed_cap_mask %x\n",
params->phy[actual_phy_idx].req_flow_ctrl,
params->phy[actual_phy_idx].req_line_speed,
params->phy[actual_phy_idx].speed_cap_mask);
}
}
u8 bnx2x_phy_init(struct link_params *params, struct link_vars *vars)
{
struct bnx2x *bp = params->bp;
DP(NETIF_MSG_LINK, "Phy Initialization started\n");
DP(NETIF_MSG_LINK, "(1) req_speed %d, req_flowctrl %d\n",
params->req_line_speed[0], params->req_flow_ctrl[0]);
DP(NETIF_MSG_LINK, "(2) req_speed %d, req_flowctrl %d\n",
params->req_line_speed[1], params->req_flow_ctrl[1]);
vars->link_status = 0;
vars->phy_link_up = 0;
vars->link_up = 0;
vars->line_speed = 0;
vars->duplex = DUPLEX_FULL;
vars->flow_ctrl = BNX2X_FLOW_CTRL_NONE;
vars->mac_type = MAC_TYPE_NONE;
vars->phy_flags = 0;
bnx2x_bits_dis(bp, NIG_REG_MASK_INTERRUPT_PORT0 + params->port*4,
(NIG_MASK_XGXS0_LINK_STATUS |
NIG_MASK_XGXS0_LINK10G |
NIG_MASK_SERDES0_LINK_STATUS |
NIG_MASK_MI_INT));
bnx2x_emac_init(params, vars);
if (params->num_phys == 0) {
DP(NETIF_MSG_LINK, "No phy found for initialization !!\n");
return -EINVAL;
}
set_phy_vars(params);
DP(NETIF_MSG_LINK, "Num of phys on board: %d\n", params->num_phys);
if (params->loopback_mode == LOOPBACK_BMAC) {
vars->link_up = 1;
vars->line_speed = SPEED_10000;
vars->duplex = DUPLEX_FULL;
vars->flow_ctrl = BNX2X_FLOW_CTRL_NONE;
vars->mac_type = MAC_TYPE_BMAC;
vars->phy_flags = PHY_XGXS_FLAG;
bnx2x_xgxs_deassert(params);
bnx2x_bmac_enable(params, vars, 1);
REG_WR(bp, NIG_REG_EGRESS_DRAIN0_MODE + params->port*4, 0);
} else if (params->loopback_mode == LOOPBACK_EMAC) {
vars->link_up = 1;
vars->line_speed = SPEED_1000;
vars->duplex = DUPLEX_FULL;
vars->flow_ctrl = BNX2X_FLOW_CTRL_NONE;
vars->mac_type = MAC_TYPE_EMAC;
vars->phy_flags = PHY_XGXS_FLAG;
bnx2x_xgxs_deassert(params);
bnx2x_emac_enable(params, vars, 1);
bnx2x_emac_program(params, vars);
REG_WR(bp, NIG_REG_EGRESS_DRAIN0_MODE + params->port*4, 0);
} else if ((params->loopback_mode == LOOPBACK_XGXS) ||
(params->loopback_mode == LOOPBACK_EXT_PHY)) {
vars->link_up = 1;
vars->flow_ctrl = BNX2X_FLOW_CTRL_NONE;
vars->duplex = DUPLEX_FULL;
if (params->req_line_speed[0] == SPEED_1000) {
vars->line_speed = SPEED_1000;
vars->mac_type = MAC_TYPE_EMAC;
} else {
vars->line_speed = SPEED_10000;
vars->mac_type = MAC_TYPE_BMAC;
}
bnx2x_xgxs_deassert(params);
bnx2x_link_initialize(params, vars);
if (params->req_line_speed[0] == SPEED_1000) {
bnx2x_emac_program(params, vars);
bnx2x_emac_enable(params, vars, 0);
} else
bnx2x_bmac_enable(params, vars, 0);
if (params->loopback_mode == LOOPBACK_XGXS) {
params->phy[INT_PHY].config_loopback(
&params->phy[INT_PHY],
params);
} else {
u8 phy_index;
for (phy_index = EXT_PHY1;
phy_index < params->num_phys; phy_index++) {
if (params->phy[phy_index].config_loopback)
params->phy[phy_index].config_loopback(
&params->phy[phy_index],
params);
}
}
REG_WR(bp, NIG_REG_EGRESS_DRAIN0_MODE + params->port*4, 0);
bnx2x_set_led(params, vars,
LED_MODE_OPER, vars->line_speed);
} else
{
if (params->switch_cfg == SWITCH_CFG_10G)
bnx2x_xgxs_deassert(params);
else
bnx2x_serdes_deassert(bp, params->port);
bnx2x_link_initialize(params, vars);
msleep(30);
bnx2x_link_int_enable(params);
}
return 0;
}
u8 bnx2x_link_reset(struct link_params *params, struct link_vars *vars,
u8 reset_ext_phy)
{
struct bnx2x *bp = params->bp;
u8 phy_index, port = params->port, clear_latch_ind = 0;
DP(NETIF_MSG_LINK, "Resetting the link of port %d\n", port);
vars->link_status = 0;
bnx2x_update_mng(params, vars->link_status);
bnx2x_bits_dis(bp, NIG_REG_MASK_INTERRUPT_PORT0 + port*4,
(NIG_MASK_XGXS0_LINK_STATUS |
NIG_MASK_XGXS0_LINK10G |
NIG_MASK_SERDES0_LINK_STATUS |
NIG_MASK_MI_INT));
REG_WR(bp, NIG_REG_EGRESS_DRAIN0_MODE + port*4, 1);
REG_WR(bp, NIG_REG_BMAC0_OUT_EN + port*4, 0);
REG_WR(bp, NIG_REG_EGRESS_EMAC0_OUT_EN + port*4, 0);
bnx2x_bmac_rx_disable(bp, port);
REG_WR(bp, NIG_REG_NIG_EMAC0_EN + port*4, 0);
msleep(10);
bnx2x_set_led(params, vars, LED_MODE_OFF, 0);
if (reset_ext_phy) {
for (phy_index = EXT_PHY1; phy_index < params->num_phys;
phy_index++) {
if (params->phy[phy_index].link_reset)
params->phy[phy_index].link_reset(
&params->phy[phy_index],
params);
if (params->phy[phy_index].flags &
FLAGS_REARM_LATCH_SIGNAL)
clear_latch_ind = 1;
}
}
if (clear_latch_ind) {
bnx2x_rearm_latch_signal(bp, port, 0);
bnx2x_bits_dis(bp, NIG_REG_LATCH_BC_0 + port*4,
1 << NIG_LATCH_BC_ENABLE_MI_INT);
}
if (params->phy[INT_PHY].link_reset)
params->phy[INT_PHY].link_reset(
&params->phy[INT_PHY], params);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_CLEAR,
(MISC_REGISTERS_RESET_REG_2_RST_BMAC0 << port));
REG_WR(bp, NIG_REG_BMAC0_IN_EN + port*4, 0);
REG_WR(bp, NIG_REG_EMAC0_IN_EN + port*4, 0);
REG_WR(bp, NIG_REG_BMAC0_OUT_EN + port*4, 0);
REG_WR(bp, NIG_REG_EGRESS_EMAC0_OUT_EN + port*4, 0);
vars->link_up = 0;
return 0;
}
static u8 bnx2x_8073_common_init_phy(struct bnx2x *bp,
u32 shmem_base_path[],
u32 shmem2_base_path[], u8 phy_index,
u32 chip_id)
{
struct bnx2x_phy phy[PORT_MAX];
struct bnx2x_phy *phy_blk[PORT_MAX];
u16 val;
s8 port = 0;
s8 port_of_path = 0;
u32 swap_val, swap_override;
swap_val = REG_RD(bp, NIG_REG_PORT_SWAP);
swap_override = REG_RD(bp, NIG_REG_STRAP_OVERRIDE);
port ^= (swap_val && swap_override);
bnx2x_ext_phy_hw_reset(bp, port);
for (port = PORT_MAX - 1; port >= PORT_0; port--) {
u32 shmem_base, shmem2_base;
if (CHIP_IS_E2(bp)) {
shmem_base = shmem_base_path[port];
shmem2_base = shmem2_base_path[port];
port_of_path = 0;
} else {
shmem_base = shmem_base_path[0];
shmem2_base = shmem2_base_path[0];
port_of_path = port;
}
if (bnx2x_populate_phy(bp, phy_index, shmem_base, shmem2_base,
port_of_path, &phy[port]) !=
0) {
DP(NETIF_MSG_LINK, "populate_phy failed\n");
return -EINVAL;
}
bnx2x_bits_dis(bp, NIG_REG_MASK_INTERRUPT_PORT0 +
port_of_path*4,
(NIG_MASK_XGXS0_LINK_STATUS |
NIG_MASK_XGXS0_LINK10G |
NIG_MASK_SERDES0_LINK_STATUS |
NIG_MASK_MI_INT));
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_HIGH,
port);
bnx2x_cl45_write(bp, &phy[port],
MDIO_PMA_DEVAD,
MDIO_PMA_REG_CTRL,
1<<15);
}
msleep(150);
if (phy[PORT_0].addr & 0x1) {
phy_blk[PORT_0] = &(phy[PORT_1]);
phy_blk[PORT_1] = &(phy[PORT_0]);
} else {
phy_blk[PORT_0] = &(phy[PORT_0]);
phy_blk[PORT_1] = &(phy[PORT_1]);
}
for (port = PORT_MAX - 1; port >= PORT_0; port--) {
if (CHIP_IS_E2(bp))
port_of_path = 0;
else
port_of_path = port;
DP(NETIF_MSG_LINK, "Loading spirom for phy address 0x%x\n",
phy_blk[port]->addr);
if (bnx2x_8073_8727_external_rom_boot(bp, phy_blk[port],
port_of_path))
return -EINVAL;
bnx2x_cl45_read(bp, phy_blk[port],
MDIO_PMA_DEVAD,
MDIO_PMA_REG_TX_POWER_DOWN, &val);
bnx2x_cl45_write(bp, phy_blk[port],
MDIO_PMA_DEVAD,
MDIO_PMA_REG_TX_POWER_DOWN,
(val | 1<<10));
}
msleep(600);
for (port = PORT_MAX - 1; port >= PORT_0; port--) {
bnx2x_cl45_read(bp, phy_blk[port],
MDIO_PMA_DEVAD,
MDIO_PMA_REG_TX_POWER_DOWN, &val);
bnx2x_cl45_write(bp, phy_blk[port],
MDIO_PMA_DEVAD,
MDIO_PMA_REG_TX_POWER_DOWN, (val & (~(1<<10))));
msleep(15);
bnx2x_cl45_read(bp, phy_blk[port],
MDIO_PMA_DEVAD,
MDIO_PMA_REG_EDC_FFE_MAIN, &val);
bnx2x_cl45_write(bp, phy_blk[port],
MDIO_PMA_DEVAD,
MDIO_PMA_REG_EDC_FFE_MAIN, (val | (1<<12)));
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_2,
MISC_REGISTERS_GPIO_OUTPUT_LOW, port);
}
return 0;
}
static u8 bnx2x_8726_common_init_phy(struct bnx2x *bp,
u32 shmem_base_path[],
u32 shmem2_base_path[], u8 phy_index,
u32 chip_id)
{
u32 val;
s8 port;
struct bnx2x_phy phy;
val = REG_RD(bp, MISC_REG_GPIO_EVENT_EN);
val |= ((1<<MISC_REGISTERS_GPIO_3)|
(1<<(MISC_REGISTERS_GPIO_3 + MISC_REGISTERS_GPIO_PORT_SHIFT)));
REG_WR(bp, MISC_REG_GPIO_EVENT_EN, val);
bnx2x_ext_phy_hw_reset(bp, 0);
msleep(5);
for (port = 0; port < PORT_MAX; port++) {
u32 shmem_base, shmem2_base;
if (CHIP_IS_E2(bp)) {
shmem_base = shmem_base_path[port];
shmem2_base = shmem2_base_path[port];
} else {
shmem_base = shmem_base_path[0];
shmem2_base = shmem2_base_path[0];
}
if (bnx2x_populate_phy(bp, phy_index, shmem_base, shmem2_base,
port, &phy) !=
0) {
DP(NETIF_MSG_LINK, "populate phy failed\n");
return -EINVAL;
}
bnx2x_cl45_write(bp, &phy,
MDIO_PMA_DEVAD, MDIO_PMA_REG_GEN_CTRL, 0x0001);
bnx2x_set_gpio(bp, MISC_REGISTERS_GPIO_0,
MISC_REGISTERS_GPIO_HIGH,
port);
}
return 0;
}
static void bnx2x_get_ext_phy_reset_gpio(struct bnx2x *bp, u32 shmem_base,
u8 *io_gpio, u8 *io_port)
{
u32 phy_gpio_reset = REG_RD(bp, shmem_base +
offsetof(struct shmem_region,
dev_info.port_hw_config[PORT_0].default_cfg));
switch (phy_gpio_reset) {
case PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO0_P0:
*io_gpio = 0;
*io_port = 0;
break;
case PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO1_P0:
*io_gpio = 1;
*io_port = 0;
break;
case PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO2_P0:
*io_gpio = 2;
*io_port = 0;
break;
case PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO3_P0:
*io_gpio = 3;
*io_port = 0;
break;
case PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO0_P1:
*io_gpio = 0;
*io_port = 1;
break;
case PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO1_P1:
*io_gpio = 1;
*io_port = 1;
break;
case PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO2_P1:
*io_gpio = 2;
*io_port = 1;
break;
case PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO3_P1:
*io_gpio = 3;
*io_port = 1;
break;
default:
break;
}
}
static u8 bnx2x_8727_common_init_phy(struct bnx2x *bp,
u32 shmem_base_path[],
u32 shmem2_base_path[], u8 phy_index,
u32 chip_id)
{
s8 port, reset_gpio;
u32 swap_val, swap_override;
struct bnx2x_phy phy[PORT_MAX];
struct bnx2x_phy *phy_blk[PORT_MAX];
s8 port_of_path;
swap_val = REG_RD(bp, NIG_REG_PORT_SWAP);
swap_override = REG_RD(bp, NIG_REG_STRAP_OVERRIDE);
reset_gpio = MISC_REGISTERS_GPIO_1;
port = 1;
bnx2x_get_ext_phy_reset_gpio(bp, shmem_base_path[0],
(u8 *)&reset_gpio, (u8 *)&port);
port ^= (swap_val && swap_override);
bnx2x_set_gpio(bp, reset_gpio, MISC_REGISTERS_GPIO_OUTPUT_LOW,
port);
msleep(1);
bnx2x_set_gpio(bp, reset_gpio, MISC_REGISTERS_GPIO_OUTPUT_HIGH,
port);
msleep(5);
for (port = PORT_MAX - 1; port >= PORT_0; port--) {
u32 shmem_base, shmem2_base;
if (CHIP_IS_E2(bp)) {
shmem_base = shmem_base_path[port];
shmem2_base = shmem2_base_path[port];
port_of_path = 0;
} else {
shmem_base = shmem_base_path[0];
shmem2_base = shmem2_base_path[0];
port_of_path = port;
}
if (bnx2x_populate_phy(bp, phy_index, shmem_base, shmem2_base,
port_of_path, &phy[port]) !=
0) {
DP(NETIF_MSG_LINK, "populate phy failed\n");
return -EINVAL;
}
bnx2x_bits_dis(bp, NIG_REG_MASK_INTERRUPT_PORT0 +
port_of_path*4,
(NIG_MASK_XGXS0_LINK_STATUS |
NIG_MASK_XGXS0_LINK10G |
NIG_MASK_SERDES0_LINK_STATUS |
NIG_MASK_MI_INT));
bnx2x_cl45_write(bp, &phy[port],
MDIO_PMA_DEVAD, MDIO_PMA_REG_CTRL, 1<<15);
}
msleep(150);
if (phy[PORT_0].addr & 0x1) {
phy_blk[PORT_0] = &(phy[PORT_1]);
phy_blk[PORT_1] = &(phy[PORT_0]);
} else {
phy_blk[PORT_0] = &(phy[PORT_0]);
phy_blk[PORT_1] = &(phy[PORT_1]);
}
for (port = PORT_MAX - 1; port >= PORT_0; port--) {
if (CHIP_IS_E2(bp))
port_of_path = 0;
else
port_of_path = port;
DP(NETIF_MSG_LINK, "Loading spirom for phy address 0x%x\n",
phy_blk[port]->addr);
if (bnx2x_8073_8727_external_rom_boot(bp, phy_blk[port],
port_of_path))
return -EINVAL;
}
return 0;
}
static u8 bnx2x_ext_phy_common_init(struct bnx2x *bp, u32 shmem_base_path[],
u32 shmem2_base_path[], u8 phy_index,
u32 ext_phy_type, u32 chip_id)
{
u8 rc = 0;
switch (ext_phy_type) {
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8073:
rc = bnx2x_8073_common_init_phy(bp, shmem_base_path,
shmem2_base_path,
phy_index, chip_id);
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727:
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727_NOC:
rc = bnx2x_8727_common_init_phy(bp, shmem_base_path,
shmem2_base_path,
phy_index, chip_id);
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8726:
rc = bnx2x_8726_common_init_phy(bp, shmem_base_path,
shmem2_base_path,
phy_index, chip_id);
break;
case PORT_HW_CFG_XGXS_EXT_PHY_TYPE_FAILURE:
rc = -EINVAL;
break;
default:
DP(NETIF_MSG_LINK,
"ext_phy 0x%x common init not required\n",
ext_phy_type);
break;
}
if (rc != 0)
netdev_err(bp->dev, "Warning: PHY was not initialized,"
" Port %d\n",
0);
return rc;
}
u8 bnx2x_common_init_phy(struct bnx2x *bp, u32 shmem_base_path[],
u32 shmem2_base_path[], u32 chip_id)
{
u8 rc = 0;
u32 phy_ver;
u8 phy_index;
u32 ext_phy_type, ext_phy_config;
DP(NETIF_MSG_LINK, "Begin common phy init\n");
phy_ver = REG_RD(bp, shmem_base_path[0] +
offsetof(struct shmem_region,
port_mb[PORT_0].ext_phy_fw_version));
if (phy_ver) {
DP(NETIF_MSG_LINK, "Not doing common init; phy ver is 0x%x\n",
phy_ver);
return 0;
}
for (phy_index = EXT_PHY1; phy_index < MAX_PHYS;
phy_index++) {
ext_phy_config = bnx2x_get_ext_phy_config(bp,
shmem_base_path[0],
phy_index, 0);
ext_phy_type = XGXS_EXT_PHY_TYPE(ext_phy_config);
rc |= bnx2x_ext_phy_common_init(bp, shmem_base_path,
shmem2_base_path,
phy_index, ext_phy_type,
chip_id);
}
return rc;
}
u8 bnx2x_hw_lock_required(struct bnx2x *bp, u32 shmem_base, u32 shmem2_base)
{
u8 phy_index;
struct bnx2x_phy phy;
for (phy_index = INT_PHY; phy_index < MAX_PHYS;
phy_index++) {
if (bnx2x_populate_phy(bp, phy_index, shmem_base, shmem2_base,
0, &phy) != 0) {
DP(NETIF_MSG_LINK, "populate phy failed\n");
return 0;
}
if (phy.flags & FLAGS_HW_LOCK_REQUIRED)
return 1;
}
return 0;
}
u8 bnx2x_fan_failure_det_req(struct bnx2x *bp,
u32 shmem_base,
u32 shmem2_base,
u8 port)
{
u8 phy_index, fan_failure_det_req = 0;
struct bnx2x_phy phy;
for (phy_index = EXT_PHY1; phy_index < MAX_PHYS;
phy_index++) {
if (bnx2x_populate_phy(bp, phy_index, shmem_base, shmem2_base,
port, &phy)
!= 0) {
DP(NETIF_MSG_LINK, "populate phy failed\n");
return 0;
}
fan_failure_det_req |= (phy.flags &
FLAGS_FAN_FAILURE_DET_REQ);
}
return fan_failure_det_req;
}
void bnx2x_hw_reset_phy(struct link_params *params)
{
u8 phy_index;
for (phy_index = EXT_PHY1; phy_index < MAX_PHYS;
phy_index++) {
if (params->phy[phy_index].hw_reset) {
params->phy[phy_index].hw_reset(
&params->phy[phy_index],
params);
params->phy[phy_index] = phy_null;
}
}
}
