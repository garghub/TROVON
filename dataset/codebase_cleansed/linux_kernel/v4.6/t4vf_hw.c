int t4vf_wait_dev_ready(struct adapter *adapter)
{
const u32 whoami = T4VF_PL_BASE_ADDR + PL_VF_WHOAMI;
const u32 notready1 = 0xffffffff;
const u32 notready2 = 0xeeeeeeee;
u32 val;
val = t4_read_reg(adapter, whoami);
if (val != notready1 && val != notready2)
return 0;
msleep(500);
val = t4_read_reg(adapter, whoami);
if (val != notready1 && val != notready2)
return 0;
else
return -EIO;
}
static void get_mbox_rpl(struct adapter *adapter, __be64 *rpl, int size,
u32 mbox_data)
{
for ( ; size; size -= 8, mbox_data += 8)
*rpl++ = cpu_to_be64(t4_read_reg64(adapter, mbox_data));
}
static void dump_mbox(struct adapter *adapter, const char *tag, u32 mbox_data)
{
dev_err(adapter->pdev_dev,
"mbox %s: %llx %llx %llx %llx %llx %llx %llx %llx\n", tag,
(unsigned long long)t4_read_reg64(adapter, mbox_data + 0),
(unsigned long long)t4_read_reg64(adapter, mbox_data + 8),
(unsigned long long)t4_read_reg64(adapter, mbox_data + 16),
(unsigned long long)t4_read_reg64(adapter, mbox_data + 24),
(unsigned long long)t4_read_reg64(adapter, mbox_data + 32),
(unsigned long long)t4_read_reg64(adapter, mbox_data + 40),
(unsigned long long)t4_read_reg64(adapter, mbox_data + 48),
(unsigned long long)t4_read_reg64(adapter, mbox_data + 56));
}
int t4vf_wr_mbox_core(struct adapter *adapter, const void *cmd, int size,
void *rpl, bool sleep_ok)
{
static const int delay[] = {
1, 1, 3, 5, 10, 10, 20, 50, 100
};
u32 v, mbox_data;
int i, ms, delay_idx;
const __be64 *p;
u32 mbox_ctl = T4VF_CIM_BASE_ADDR + CIM_VF_EXT_MAILBOX_CTRL;
if (CHELSIO_CHIP_VERSION(adapter->params.chip) <= CHELSIO_T5)
mbox_data = T4VF_MBDATA_BASE_ADDR;
else
mbox_data = T6VF_MBDATA_BASE_ADDR;
if ((size % 16) != 0 ||
size > NUM_CIM_VF_MAILBOX_DATA_INSTANCES * 4)
return -EINVAL;
v = MBOWNER_G(t4_read_reg(adapter, mbox_ctl));
for (i = 0; v == MBOX_OWNER_NONE && i < 3; i++)
v = MBOWNER_G(t4_read_reg(adapter, mbox_ctl));
if (v != MBOX_OWNER_DRV)
return v == MBOX_OWNER_FW ? -EBUSY : -ETIMEDOUT;
for (i = 0, p = cmd; i < size; i += 8)
t4_write_reg64(adapter, mbox_data + i, be64_to_cpu(*p++));
t4_read_reg(adapter, mbox_data);
t4_write_reg(adapter, mbox_ctl,
MBMSGVALID_F | MBOWNER_V(MBOX_OWNER_FW));
t4_read_reg(adapter, mbox_ctl);
delay_idx = 0;
ms = delay[0];
for (i = 0; i < FW_CMD_MAX_TIMEOUT; i += ms) {
if (sleep_ok) {
ms = delay[delay_idx];
if (delay_idx < ARRAY_SIZE(delay) - 1)
delay_idx++;
msleep(ms);
} else
mdelay(ms);
v = t4_read_reg(adapter, mbox_ctl);
if (MBOWNER_G(v) == MBOX_OWNER_DRV) {
if ((v & MBMSGVALID_F) == 0) {
t4_write_reg(adapter, mbox_ctl,
MBOWNER_V(MBOX_OWNER_NONE));
continue;
}
v = t4_read_reg(adapter, mbox_data);
if (FW_CMD_RETVAL_G(v))
dump_mbox(adapter, "FW Error", mbox_data);
if (rpl) {
WARN_ON((be32_to_cpu(*(const __be32 *)cmd)
& FW_CMD_REQUEST_F) == 0);
get_mbox_rpl(adapter, rpl, size, mbox_data);
WARN_ON((be32_to_cpu(*(__be32 *)rpl)
& FW_CMD_REQUEST_F) != 0);
}
t4_write_reg(adapter, mbox_ctl,
MBOWNER_V(MBOX_OWNER_NONE));
return -FW_CMD_RETVAL_G(v);
}
}
dump_mbox(adapter, "FW Timeout", mbox_data);
return -ETIMEDOUT;
}
static void init_link_config(struct link_config *lc, unsigned int caps)
{
lc->supported = caps;
lc->requested_speed = 0;
lc->speed = 0;
lc->requested_fc = lc->fc = PAUSE_RX | PAUSE_TX;
if (lc->supported & FW_PORT_CAP_ANEG) {
lc->advertising = lc->supported & ADVERT_MASK;
lc->autoneg = AUTONEG_ENABLE;
lc->requested_fc |= PAUSE_AUTONEG;
} else {
lc->advertising = 0;
lc->autoneg = AUTONEG_DISABLE;
}
}
int t4vf_port_init(struct adapter *adapter, int pidx)
{
struct port_info *pi = adap2pinfo(adapter, pidx);
struct fw_vi_cmd vi_cmd, vi_rpl;
struct fw_port_cmd port_cmd, port_rpl;
int v;
memset(&vi_cmd, 0, sizeof(vi_cmd));
vi_cmd.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_VI_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F);
vi_cmd.alloc_to_len16 = cpu_to_be32(FW_LEN16(vi_cmd));
vi_cmd.type_viid = cpu_to_be16(FW_VI_CMD_VIID_V(pi->viid));
v = t4vf_wr_mbox(adapter, &vi_cmd, sizeof(vi_cmd), &vi_rpl);
if (v)
return v;
BUG_ON(pi->port_id != FW_VI_CMD_PORTID_G(vi_rpl.portid_pkd));
pi->rss_size = FW_VI_CMD_RSSSIZE_G(be16_to_cpu(vi_rpl.rsssize_pkd));
t4_os_set_hw_addr(adapter, pidx, vi_rpl.mac);
if (!(adapter->params.vfres.r_caps & FW_CMD_CAP_PORT))
return 0;
memset(&port_cmd, 0, sizeof(port_cmd));
port_cmd.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PORT_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F |
FW_PORT_CMD_PORTID_V(pi->port_id));
port_cmd.action_to_len16 =
cpu_to_be32(FW_PORT_CMD_ACTION_V(FW_PORT_ACTION_GET_PORT_INFO) |
FW_LEN16(port_cmd));
v = t4vf_wr_mbox(adapter, &port_cmd, sizeof(port_cmd), &port_rpl);
if (v)
return v;
v = be32_to_cpu(port_rpl.u.info.lstatus_to_modtype);
pi->mdio_addr = (v & FW_PORT_CMD_MDIOCAP_F) ?
FW_PORT_CMD_MDIOADDR_G(v) : -1;
pi->port_type = FW_PORT_CMD_PTYPE_G(v);
pi->mod_type = FW_PORT_MOD_TYPE_NA;
init_link_config(&pi->link_cfg, be16_to_cpu(port_rpl.u.info.pcap));
return 0;
}
int t4vf_fw_reset(struct adapter *adapter)
{
struct fw_reset_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_write = cpu_to_be32(FW_CMD_OP_V(FW_RESET_CMD) |
FW_CMD_WRITE_F);
cmd.retval_len16 = cpu_to_be32(FW_LEN16(cmd));
return t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), NULL);
}
static int t4vf_query_params(struct adapter *adapter, unsigned int nparams,
const u32 *params, u32 *vals)
{
int i, ret;
struct fw_params_cmd cmd, rpl;
struct fw_params_param *p;
size_t len16;
if (nparams > 7)
return -EINVAL;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_PARAMS_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F);
len16 = DIV_ROUND_UP(offsetof(struct fw_params_cmd,
param[nparams].mnem), 16);
cmd.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(len16));
for (i = 0, p = &cmd.param[0]; i < nparams; i++, p++)
p->mnem = htonl(*params++);
ret = t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), &rpl);
if (ret == 0)
for (i = 0, p = &rpl.param[0]; i < nparams; i++, p++)
*vals++ = be32_to_cpu(p->val);
return ret;
}
int t4vf_set_params(struct adapter *adapter, unsigned int nparams,
const u32 *params, const u32 *vals)
{
int i;
struct fw_params_cmd cmd;
struct fw_params_param *p;
size_t len16;
if (nparams > 7)
return -EINVAL;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_PARAMS_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F);
len16 = DIV_ROUND_UP(offsetof(struct fw_params_cmd,
param[nparams]), 16);
cmd.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(len16));
for (i = 0, p = &cmd.param[0]; i < nparams; i++, p++) {
p->mnem = cpu_to_be32(*params++);
p->val = cpu_to_be32(*vals++);
}
return t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), NULL);
}
int t4vf_fl_pkt_align(struct adapter *adapter)
{
u32 sge_control, sge_control2;
unsigned int ingpadboundary, ingpackboundary, fl_align, ingpad_shift;
sge_control = adapter->params.sge.sge_control;
if (CHELSIO_CHIP_VERSION(adapter->params.chip) <= CHELSIO_T5)
ingpad_shift = INGPADBOUNDARY_SHIFT_X;
else
ingpad_shift = T6_INGPADBOUNDARY_SHIFT_X;
ingpadboundary = 1 << (INGPADBOUNDARY_G(sge_control) + ingpad_shift);
fl_align = ingpadboundary;
if (!is_t4(adapter->params.chip)) {
sge_control2 = adapter->params.sge.sge_control2;
ingpackboundary = INGPACKBOUNDARY_G(sge_control2);
if (ingpackboundary == INGPACKBOUNDARY_16B_X)
ingpackboundary = 16;
else
ingpackboundary = 1 << (ingpackboundary +
INGPACKBOUNDARY_SHIFT_X);
fl_align = max(ingpadboundary, ingpackboundary);
}
return fl_align;
}
int t4vf_bar2_sge_qregs(struct adapter *adapter,
unsigned int qid,
enum t4_bar2_qtype qtype,
u64 *pbar2_qoffset,
unsigned int *pbar2_qid)
{
unsigned int page_shift, page_size, qpp_shift, qpp_mask;
u64 bar2_page_offset, bar2_qoffset;
unsigned int bar2_qid, bar2_qid_offset, bar2_qinferred;
if (is_t4(adapter->params.chip))
return -EINVAL;
page_shift = adapter->params.sge.sge_vf_hps + 10;
page_size = 1 << page_shift;
qpp_shift = (qtype == T4_BAR2_QTYPE_EGRESS
? adapter->params.sge.sge_vf_eq_qpp
: adapter->params.sge.sge_vf_iq_qpp);
qpp_mask = (1 << qpp_shift) - 1;
bar2_page_offset = ((u64)(qid >> qpp_shift) << page_shift);
bar2_qid = qid & qpp_mask;
bar2_qid_offset = bar2_qid * SGE_UDB_SIZE;
bar2_qoffset = bar2_page_offset;
bar2_qinferred = (bar2_qid_offset < page_size);
if (bar2_qinferred) {
bar2_qoffset += bar2_qid_offset;
bar2_qid = 0;
}
*pbar2_qoffset = bar2_qoffset;
*pbar2_qid = bar2_qid;
return 0;
}
int t4vf_get_sge_params(struct adapter *adapter)
{
struct sge_params *sge_params = &adapter->params.sge;
u32 params[7], vals[7];
int v;
params[0] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_CONTROL_A));
params[1] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_HOST_PAGE_SIZE_A));
params[2] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_FL_BUFFER_SIZE0_A));
params[3] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_FL_BUFFER_SIZE1_A));
params[4] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_TIMER_VALUE_0_AND_1_A));
params[5] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_TIMER_VALUE_2_AND_3_A));
params[6] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_TIMER_VALUE_4_AND_5_A));
v = t4vf_query_params(adapter, 7, params, vals);
if (v)
return v;
sge_params->sge_control = vals[0];
sge_params->sge_host_page_size = vals[1];
sge_params->sge_fl_buffer_size[0] = vals[2];
sge_params->sge_fl_buffer_size[1] = vals[3];
sge_params->sge_timer_value_0_and_1 = vals[4];
sge_params->sge_timer_value_2_and_3 = vals[5];
sge_params->sge_timer_value_4_and_5 = vals[6];
if (!is_t4(adapter->params.chip)) {
params[0] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_CONTROL2_A));
v = t4vf_query_params(adapter, 1, params, vals);
if (v != FW_SUCCESS) {
dev_err(adapter->pdev_dev,
"Unable to get SGE Control2; "
"probably old firmware.\n");
return v;
}
sge_params->sge_control2 = vals[0];
}
params[0] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_INGRESS_RX_THRESHOLD_A));
params[1] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(SGE_CONM_CTRL_A));
v = t4vf_query_params(adapter, 2, params, vals);
if (v)
return v;
sge_params->sge_ingress_rx_threshold = vals[0];
sge_params->sge_congestion_control = vals[1];
if (!is_t4(adapter->params.chip)) {
u32 whoami;
unsigned int pf, s_hps, s_qpp;
params[0] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(
SGE_EGRESS_QUEUES_PER_PAGE_VF_A));
params[1] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_REG) |
FW_PARAMS_PARAM_XYZ_V(
SGE_INGRESS_QUEUES_PER_PAGE_VF_A));
v = t4vf_query_params(adapter, 2, params, vals);
if (v != FW_SUCCESS) {
dev_warn(adapter->pdev_dev,
"Unable to get VF SGE Queues/Page; "
"probably old firmware.\n");
return v;
}
sge_params->sge_egress_queues_per_page = vals[0];
sge_params->sge_ingress_queues_per_page = vals[1];
whoami = t4_read_reg(adapter,
T4VF_PL_BASE_ADDR + PL_VF_WHOAMI_A);
pf = CHELSIO_CHIP_VERSION(adapter->params.chip) <= CHELSIO_T5 ?
SOURCEPF_G(whoami) : T6_SOURCEPF_G(whoami);
s_hps = (HOSTPAGESIZEPF0_S +
(HOSTPAGESIZEPF1_S - HOSTPAGESIZEPF0_S) * pf);
sge_params->sge_vf_hps =
((sge_params->sge_host_page_size >> s_hps)
& HOSTPAGESIZEPF0_M);
s_qpp = (QUEUESPERPAGEPF0_S +
(QUEUESPERPAGEPF1_S - QUEUESPERPAGEPF0_S) * pf);
sge_params->sge_vf_eq_qpp =
((sge_params->sge_egress_queues_per_page >> s_qpp)
& QUEUESPERPAGEPF0_M);
sge_params->sge_vf_iq_qpp =
((sge_params->sge_ingress_queues_per_page >> s_qpp)
& QUEUESPERPAGEPF0_M);
}
return 0;
}
int t4vf_get_vpd_params(struct adapter *adapter)
{
struct vpd_params *vpd_params = &adapter->params.vpd;
u32 params[7], vals[7];
int v;
params[0] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_CCLK));
v = t4vf_query_params(adapter, 1, params, vals);
if (v)
return v;
vpd_params->cclk = vals[0];
return 0;
}
int t4vf_get_dev_params(struct adapter *adapter)
{
struct dev_params *dev_params = &adapter->params.dev;
u32 params[7], vals[7];
int v;
params[0] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_FWREV));
params[1] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_TPREV));
v = t4vf_query_params(adapter, 2, params, vals);
if (v)
return v;
dev_params->fwrev = vals[0];
dev_params->tprev = vals[1];
return 0;
}
int t4vf_get_rss_glb_config(struct adapter *adapter)
{
struct rss_params *rss = &adapter->params.rss;
struct fw_rss_glb_config_cmd cmd, rpl;
int v;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_write = cpu_to_be32(FW_CMD_OP_V(FW_RSS_GLB_CONFIG_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F);
cmd.retval_len16 = cpu_to_be32(FW_LEN16(cmd));
v = t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), &rpl);
if (v)
return v;
rss->mode = FW_RSS_GLB_CONFIG_CMD_MODE_G(
be32_to_cpu(rpl.u.manual.mode_pkd));
switch (rss->mode) {
case FW_RSS_GLB_CONFIG_CMD_MODE_BASICVIRTUAL: {
u32 word = be32_to_cpu(
rpl.u.basicvirtual.synmapen_to_hashtoeplitz);
rss->u.basicvirtual.synmapen =
((word & FW_RSS_GLB_CONFIG_CMD_SYNMAPEN_F) != 0);
rss->u.basicvirtual.syn4tupenipv6 =
((word & FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6_F) != 0);
rss->u.basicvirtual.syn2tupenipv6 =
((word & FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6_F) != 0);
rss->u.basicvirtual.syn4tupenipv4 =
((word & FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4_F) != 0);
rss->u.basicvirtual.syn2tupenipv4 =
((word & FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4_F) != 0);
rss->u.basicvirtual.ofdmapen =
((word & FW_RSS_GLB_CONFIG_CMD_OFDMAPEN_F) != 0);
rss->u.basicvirtual.tnlmapen =
((word & FW_RSS_GLB_CONFIG_CMD_TNLMAPEN_F) != 0);
rss->u.basicvirtual.tnlalllookup =
((word & FW_RSS_GLB_CONFIG_CMD_TNLALLLKP_F) != 0);
rss->u.basicvirtual.hashtoeplitz =
((word & FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ_F) != 0);
if (!rss->u.basicvirtual.tnlmapen)
return -EINVAL;
break;
}
default:
return -EINVAL;
}
return 0;
}
int t4vf_get_vfres(struct adapter *adapter)
{
struct vf_resources *vfres = &adapter->params.vfres;
struct fw_pfvf_cmd cmd, rpl;
int v;
u32 word;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_PFVF_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F);
cmd.retval_len16 = cpu_to_be32(FW_LEN16(cmd));
v = t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), &rpl);
if (v)
return v;
word = be32_to_cpu(rpl.niqflint_niq);
vfres->niqflint = FW_PFVF_CMD_NIQFLINT_G(word);
vfres->niq = FW_PFVF_CMD_NIQ_G(word);
word = be32_to_cpu(rpl.type_to_neq);
vfres->neq = FW_PFVF_CMD_NEQ_G(word);
vfres->pmask = FW_PFVF_CMD_PMASK_G(word);
word = be32_to_cpu(rpl.tc_to_nexactf);
vfres->tc = FW_PFVF_CMD_TC_G(word);
vfres->nvi = FW_PFVF_CMD_NVI_G(word);
vfres->nexactf = FW_PFVF_CMD_NEXACTF_G(word);
word = be32_to_cpu(rpl.r_caps_to_nethctrl);
vfres->r_caps = FW_PFVF_CMD_R_CAPS_G(word);
vfres->wx_caps = FW_PFVF_CMD_WX_CAPS_G(word);
vfres->nethctrl = FW_PFVF_CMD_NETHCTRL_G(word);
return 0;
}
int t4vf_read_rss_vi_config(struct adapter *adapter, unsigned int viid,
union rss_vi_config *config)
{
struct fw_rss_vi_config_cmd cmd, rpl;
int v;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_RSS_VI_CONFIG_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F |
FW_RSS_VI_CONFIG_CMD_VIID(viid));
cmd.retval_len16 = cpu_to_be32(FW_LEN16(cmd));
v = t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), &rpl);
if (v)
return v;
switch (adapter->params.rss.mode) {
case FW_RSS_GLB_CONFIG_CMD_MODE_BASICVIRTUAL: {
u32 word = be32_to_cpu(rpl.u.basicvirtual.defaultq_to_udpen);
config->basicvirtual.ip6fourtupen =
((word & FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_F) != 0);
config->basicvirtual.ip6twotupen =
((word & FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_F) != 0);
config->basicvirtual.ip4fourtupen =
((word & FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_F) != 0);
config->basicvirtual.ip4twotupen =
((word & FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_F) != 0);
config->basicvirtual.udpen =
((word & FW_RSS_VI_CONFIG_CMD_UDPEN_F) != 0);
config->basicvirtual.defaultq =
FW_RSS_VI_CONFIG_CMD_DEFAULTQ_G(word);
break;
}
default:
return -EINVAL;
}
return 0;
}
int t4vf_write_rss_vi_config(struct adapter *adapter, unsigned int viid,
union rss_vi_config *config)
{
struct fw_rss_vi_config_cmd cmd, rpl;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_RSS_VI_CONFIG_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_RSS_VI_CONFIG_CMD_VIID(viid));
cmd.retval_len16 = cpu_to_be32(FW_LEN16(cmd));
switch (adapter->params.rss.mode) {
case FW_RSS_GLB_CONFIG_CMD_MODE_BASICVIRTUAL: {
u32 word = 0;
if (config->basicvirtual.ip6fourtupen)
word |= FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_F;
if (config->basicvirtual.ip6twotupen)
word |= FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_F;
if (config->basicvirtual.ip4fourtupen)
word |= FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_F;
if (config->basicvirtual.ip4twotupen)
word |= FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_F;
if (config->basicvirtual.udpen)
word |= FW_RSS_VI_CONFIG_CMD_UDPEN_F;
word |= FW_RSS_VI_CONFIG_CMD_DEFAULTQ_V(
config->basicvirtual.defaultq);
cmd.u.basicvirtual.defaultq_to_udpen = cpu_to_be32(word);
break;
}
default:
return -EINVAL;
}
return t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), &rpl);
}
int t4vf_config_rss_range(struct adapter *adapter, unsigned int viid,
int start, int n, const u16 *rspq, int nrspq)
{
const u16 *rsp = rspq;
const u16 *rsp_end = rspq+nrspq;
struct fw_rss_ind_tbl_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_RSS_IND_TBL_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_RSS_IND_TBL_CMD_VIID_V(viid));
cmd.retval_len16 = cpu_to_be32(FW_LEN16(cmd));
while (n > 0) {
__be32 *qp = &cmd.iq0_to_iq2;
int nq = min(n, 32);
int ret;
cmd.niqid = cpu_to_be16(nq);
cmd.startidx = cpu_to_be16(start);
start += nq;
n -= nq;
while (nq > 0) {
u16 qbuf[3];
u16 *qbp = qbuf;
int nqbuf = min(3, nq);
nq -= nqbuf;
qbuf[0] = qbuf[1] = qbuf[2] = 0;
while (nqbuf) {
nqbuf--;
*qbp++ = *rsp++;
if (rsp >= rsp_end)
rsp = rspq;
}
*qp++ = cpu_to_be32(FW_RSS_IND_TBL_CMD_IQ0_V(qbuf[0]) |
FW_RSS_IND_TBL_CMD_IQ1_V(qbuf[1]) |
FW_RSS_IND_TBL_CMD_IQ2_V(qbuf[2]));
}
ret = t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), NULL);
if (ret)
return ret;
}
return 0;
}
int t4vf_alloc_vi(struct adapter *adapter, int port_id)
{
struct fw_vi_cmd cmd, rpl;
int v;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_VI_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_CMD_EXEC_F);
cmd.alloc_to_len16 = cpu_to_be32(FW_LEN16(cmd) |
FW_VI_CMD_ALLOC_F);
cmd.portid_pkd = FW_VI_CMD_PORTID_V(port_id);
v = t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), &rpl);
if (v)
return v;
return FW_VI_CMD_VIID_G(be16_to_cpu(rpl.type_viid));
}
int t4vf_free_vi(struct adapter *adapter, int viid)
{
struct fw_vi_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_VI_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_EXEC_F);
cmd.alloc_to_len16 = cpu_to_be32(FW_LEN16(cmd) |
FW_VI_CMD_FREE_F);
cmd.type_viid = cpu_to_be16(FW_VI_CMD_VIID_V(viid));
return t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), NULL);
}
int t4vf_enable_vi(struct adapter *adapter, unsigned int viid,
bool rx_en, bool tx_en)
{
struct fw_vi_enable_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_ENABLE_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_EXEC_F |
FW_VI_ENABLE_CMD_VIID_V(viid));
cmd.ien_to_len16 = cpu_to_be32(FW_VI_ENABLE_CMD_IEN_V(rx_en) |
FW_VI_ENABLE_CMD_EEN_V(tx_en) |
FW_LEN16(cmd));
return t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), NULL);
}
int t4vf_identify_port(struct adapter *adapter, unsigned int viid,
unsigned int nblinks)
{
struct fw_vi_enable_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_ENABLE_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_EXEC_F |
FW_VI_ENABLE_CMD_VIID_V(viid));
cmd.ien_to_len16 = cpu_to_be32(FW_VI_ENABLE_CMD_LED_F |
FW_LEN16(cmd));
cmd.blinkdur = cpu_to_be16(nblinks);
return t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), NULL);
}
int t4vf_set_rxmode(struct adapter *adapter, unsigned int viid,
int mtu, int promisc, int all_multi, int bcast, int vlanex,
bool sleep_ok)
{
struct fw_vi_rxmode_cmd cmd;
if (mtu < 0)
mtu = FW_VI_RXMODE_CMD_MTU_M;
if (promisc < 0)
promisc = FW_VI_RXMODE_CMD_PROMISCEN_M;
if (all_multi < 0)
all_multi = FW_VI_RXMODE_CMD_ALLMULTIEN_M;
if (bcast < 0)
bcast = FW_VI_RXMODE_CMD_BROADCASTEN_M;
if (vlanex < 0)
vlanex = FW_VI_RXMODE_CMD_VLANEXEN_M;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_RXMODE_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_VI_RXMODE_CMD_VIID_V(viid));
cmd.retval_len16 = cpu_to_be32(FW_LEN16(cmd));
cmd.mtu_to_vlanexen =
cpu_to_be32(FW_VI_RXMODE_CMD_MTU_V(mtu) |
FW_VI_RXMODE_CMD_PROMISCEN_V(promisc) |
FW_VI_RXMODE_CMD_ALLMULTIEN_V(all_multi) |
FW_VI_RXMODE_CMD_BROADCASTEN_V(bcast) |
FW_VI_RXMODE_CMD_VLANEXEN_V(vlanex));
return t4vf_wr_mbox_core(adapter, &cmd, sizeof(cmd), NULL, sleep_ok);
}
int t4vf_alloc_mac_filt(struct adapter *adapter, unsigned int viid, bool free,
unsigned int naddr, const u8 **addr, u16 *idx,
u64 *hash, bool sleep_ok)
{
int offset, ret = 0;
unsigned nfilters = 0;
unsigned int rem = naddr;
struct fw_vi_mac_cmd cmd, rpl;
unsigned int max_naddr = adapter->params.arch.mps_tcam_size;
if (naddr > max_naddr)
return -EINVAL;
for (offset = 0; offset < naddr; ) {
unsigned int fw_naddr = (rem < ARRAY_SIZE(cmd.u.exact)
? rem
: ARRAY_SIZE(cmd.u.exact));
size_t len16 = DIV_ROUND_UP(offsetof(struct fw_vi_mac_cmd,
u.exact[fw_naddr]), 16);
struct fw_vi_mac_exact *p;
int i;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_MAC_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
(free ? FW_CMD_EXEC_F : 0) |
FW_VI_MAC_CMD_VIID_V(viid));
cmd.freemacs_to_len16 =
cpu_to_be32(FW_VI_MAC_CMD_FREEMACS_V(free) |
FW_CMD_LEN16_V(len16));
for (i = 0, p = cmd.u.exact; i < fw_naddr; i++, p++) {
p->valid_to_idx = cpu_to_be16(
FW_VI_MAC_CMD_VALID_F |
FW_VI_MAC_CMD_IDX_V(FW_VI_MAC_ADD_MAC));
memcpy(p->macaddr, addr[offset+i], sizeof(p->macaddr));
}
ret = t4vf_wr_mbox_core(adapter, &cmd, sizeof(cmd), &rpl,
sleep_ok);
if (ret && ret != -ENOMEM)
break;
for (i = 0, p = rpl.u.exact; i < fw_naddr; i++, p++) {
u16 index = FW_VI_MAC_CMD_IDX_G(
be16_to_cpu(p->valid_to_idx));
if (idx)
idx[offset+i] =
(index >= max_naddr
? 0xffff
: index);
if (index < max_naddr)
nfilters++;
else if (hash)
*hash |= (1ULL << hash_mac_addr(addr[offset+i]));
}
free = false;
offset += fw_naddr;
rem -= fw_naddr;
}
if (ret == 0 || ret == -ENOMEM)
ret = nfilters;
return ret;
}
int t4vf_free_mac_filt(struct adapter *adapter, unsigned int viid,
unsigned int naddr, const u8 **addr, bool sleep_ok)
{
int offset, ret = 0;
struct fw_vi_mac_cmd cmd;
unsigned int nfilters = 0;
unsigned int max_naddr = adapter->params.arch.mps_tcam_size;
unsigned int rem = naddr;
if (naddr > max_naddr)
return -EINVAL;
for (offset = 0; offset < (int)naddr ; ) {
unsigned int fw_naddr = (rem < ARRAY_SIZE(cmd.u.exact) ?
rem : ARRAY_SIZE(cmd.u.exact));
size_t len16 = DIV_ROUND_UP(offsetof(struct fw_vi_mac_cmd,
u.exact[fw_naddr]), 16);
struct fw_vi_mac_exact *p;
int i;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_MAC_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_CMD_EXEC_V(0) |
FW_VI_MAC_CMD_VIID_V(viid));
cmd.freemacs_to_len16 =
cpu_to_be32(FW_VI_MAC_CMD_FREEMACS_V(0) |
FW_CMD_LEN16_V(len16));
for (i = 0, p = cmd.u.exact; i < (int)fw_naddr; i++, p++) {
p->valid_to_idx = cpu_to_be16(
FW_VI_MAC_CMD_VALID_F |
FW_VI_MAC_CMD_IDX_V(FW_VI_MAC_MAC_BASED_FREE));
memcpy(p->macaddr, addr[offset+i], sizeof(p->macaddr));
}
ret = t4vf_wr_mbox_core(adapter, &cmd, sizeof(cmd), &cmd,
sleep_ok);
if (ret)
break;
for (i = 0, p = cmd.u.exact; i < fw_naddr; i++, p++) {
u16 index = FW_VI_MAC_CMD_IDX_G(
be16_to_cpu(p->valid_to_idx));
if (index < max_naddr)
nfilters++;
}
offset += fw_naddr;
rem -= fw_naddr;
}
if (ret == 0)
ret = nfilters;
return ret;
}
int t4vf_change_mac(struct adapter *adapter, unsigned int viid,
int idx, const u8 *addr, bool persist)
{
int ret;
struct fw_vi_mac_cmd cmd, rpl;
struct fw_vi_mac_exact *p = &cmd.u.exact[0];
size_t len16 = DIV_ROUND_UP(offsetof(struct fw_vi_mac_cmd,
u.exact[1]), 16);
unsigned int max_mac_addr = adapter->params.arch.mps_tcam_size;
if (idx < 0)
idx = persist ? FW_VI_MAC_ADD_PERSIST_MAC : FW_VI_MAC_ADD_MAC;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_MAC_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_VI_MAC_CMD_VIID_V(viid));
cmd.freemacs_to_len16 = cpu_to_be32(FW_CMD_LEN16_V(len16));
p->valid_to_idx = cpu_to_be16(FW_VI_MAC_CMD_VALID_F |
FW_VI_MAC_CMD_IDX_V(idx));
memcpy(p->macaddr, addr, sizeof(p->macaddr));
ret = t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), &rpl);
if (ret == 0) {
p = &rpl.u.exact[0];
ret = FW_VI_MAC_CMD_IDX_G(be16_to_cpu(p->valid_to_idx));
if (ret >= max_mac_addr)
ret = -ENOMEM;
}
return ret;
}
int t4vf_set_addr_hash(struct adapter *adapter, unsigned int viid,
bool ucast, u64 vec, bool sleep_ok)
{
struct fw_vi_mac_cmd cmd;
size_t len16 = DIV_ROUND_UP(offsetof(struct fw_vi_mac_cmd,
u.exact[0]), 16);
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_MAC_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_VI_ENABLE_CMD_VIID_V(viid));
cmd.freemacs_to_len16 = cpu_to_be32(FW_VI_MAC_CMD_HASHVECEN_F |
FW_VI_MAC_CMD_HASHUNIEN_V(ucast) |
FW_CMD_LEN16_V(len16));
cmd.u.hash.hashvec = cpu_to_be64(vec);
return t4vf_wr_mbox_core(adapter, &cmd, sizeof(cmd), NULL, sleep_ok);
}
int t4vf_get_port_stats(struct adapter *adapter, int pidx,
struct t4vf_port_stats *s)
{
struct port_info *pi = adap2pinfo(adapter, pidx);
struct fw_vi_stats_vf fwstats;
unsigned int rem = VI_VF_NUM_STATS;
__be64 *fwsp = (__be64 *)&fwstats;
while (rem) {
unsigned int ix = VI_VF_NUM_STATS - rem;
unsigned int nstats = min(6U, rem);
struct fw_vi_stats_cmd cmd, rpl;
size_t len = (offsetof(struct fw_vi_stats_cmd, u) +
sizeof(struct fw_vi_stats_ctl));
size_t len16 = DIV_ROUND_UP(len, 16);
int ret;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_STATS_CMD) |
FW_VI_STATS_CMD_VIID_V(pi->viid) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F);
cmd.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(len16));
cmd.u.ctl.nstats_ix =
cpu_to_be16(FW_VI_STATS_CMD_IX_V(ix) |
FW_VI_STATS_CMD_NSTATS_V(nstats));
ret = t4vf_wr_mbox_ns(adapter, &cmd, len, &rpl);
if (ret)
return ret;
memcpy(fwsp, &rpl.u.ctl.stat0, sizeof(__be64) * nstats);
rem -= nstats;
fwsp += nstats;
}
s->tx_bcast_bytes = be64_to_cpu(fwstats.tx_bcast_bytes);
s->tx_bcast_frames = be64_to_cpu(fwstats.tx_bcast_frames);
s->tx_mcast_bytes = be64_to_cpu(fwstats.tx_mcast_bytes);
s->tx_mcast_frames = be64_to_cpu(fwstats.tx_mcast_frames);
s->tx_ucast_bytes = be64_to_cpu(fwstats.tx_ucast_bytes);
s->tx_ucast_frames = be64_to_cpu(fwstats.tx_ucast_frames);
s->tx_drop_frames = be64_to_cpu(fwstats.tx_drop_frames);
s->tx_offload_bytes = be64_to_cpu(fwstats.tx_offload_bytes);
s->tx_offload_frames = be64_to_cpu(fwstats.tx_offload_frames);
s->rx_bcast_bytes = be64_to_cpu(fwstats.rx_bcast_bytes);
s->rx_bcast_frames = be64_to_cpu(fwstats.rx_bcast_frames);
s->rx_mcast_bytes = be64_to_cpu(fwstats.rx_mcast_bytes);
s->rx_mcast_frames = be64_to_cpu(fwstats.rx_mcast_frames);
s->rx_ucast_bytes = be64_to_cpu(fwstats.rx_ucast_bytes);
s->rx_ucast_frames = be64_to_cpu(fwstats.rx_ucast_frames);
s->rx_err_frames = be64_to_cpu(fwstats.rx_err_frames);
return 0;
}
int t4vf_iq_free(struct adapter *adapter, unsigned int iqtype,
unsigned int iqid, unsigned int fl0id, unsigned int fl1id)
{
struct fw_iq_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_IQ_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_EXEC_F);
cmd.alloc_to_len16 = cpu_to_be32(FW_IQ_CMD_FREE_F |
FW_LEN16(cmd));
cmd.type_to_iqandstindex =
cpu_to_be32(FW_IQ_CMD_TYPE_V(iqtype));
cmd.iqid = cpu_to_be16(iqid);
cmd.fl0id = cpu_to_be16(fl0id);
cmd.fl1id = cpu_to_be16(fl1id);
return t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), NULL);
}
int t4vf_eth_eq_free(struct adapter *adapter, unsigned int eqid)
{
struct fw_eq_eth_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_EQ_ETH_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_EXEC_F);
cmd.alloc_to_len16 = cpu_to_be32(FW_EQ_ETH_CMD_FREE_F |
FW_LEN16(cmd));
cmd.eqid_pkd = cpu_to_be32(FW_EQ_ETH_CMD_EQID_V(eqid));
return t4vf_wr_mbox(adapter, &cmd, sizeof(cmd), NULL);
}
int t4vf_handle_fw_rpl(struct adapter *adapter, const __be64 *rpl)
{
const struct fw_cmd_hdr *cmd_hdr = (const struct fw_cmd_hdr *)rpl;
u8 opcode = FW_CMD_OP_G(be32_to_cpu(cmd_hdr->hi));
switch (opcode) {
case FW_PORT_CMD: {
const struct fw_port_cmd *port_cmd =
(const struct fw_port_cmd *)rpl;
u32 stat, mod;
int action, port_id, link_ok, speed, fc, pidx;
action = FW_PORT_CMD_ACTION_G(
be32_to_cpu(port_cmd->action_to_len16));
if (action != FW_PORT_ACTION_GET_PORT_INFO) {
dev_err(adapter->pdev_dev,
"Unknown firmware PORT reply action %x\n",
action);
break;
}
port_id = FW_PORT_CMD_PORTID_G(
be32_to_cpu(port_cmd->op_to_portid));
stat = be32_to_cpu(port_cmd->u.info.lstatus_to_modtype);
link_ok = (stat & FW_PORT_CMD_LSTATUS_F) != 0;
speed = 0;
fc = 0;
if (stat & FW_PORT_CMD_RXPAUSE_F)
fc |= PAUSE_RX;
if (stat & FW_PORT_CMD_TXPAUSE_F)
fc |= PAUSE_TX;
if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_100M))
speed = 100;
else if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_1G))
speed = 1000;
else if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_10G))
speed = 10000;
else if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_40G))
speed = 40000;
for_each_port(adapter, pidx) {
struct port_info *pi = adap2pinfo(adapter, pidx);
struct link_config *lc;
if (pi->port_id != port_id)
continue;
lc = &pi->link_cfg;
mod = FW_PORT_CMD_MODTYPE_G(stat);
if (mod != pi->mod_type) {
pi->mod_type = mod;
t4vf_os_portmod_changed(adapter, pidx);
}
if (link_ok != lc->link_ok || speed != lc->speed ||
fc != lc->fc) {
lc->link_ok = link_ok;
lc->speed = speed;
lc->fc = fc;
lc->supported =
be16_to_cpu(port_cmd->u.info.pcap);
t4vf_os_link_changed(adapter, pidx, link_ok);
}
}
break;
}
default:
dev_err(adapter->pdev_dev, "Unknown firmware reply %X\n",
opcode);
}
return 0;
}
int t4vf_prep_adapter(struct adapter *adapter)
{
int err;
unsigned int chipid;
err = t4vf_wait_dev_ready(adapter);
if (err)
return err;
adapter->params.nports = 1;
adapter->params.vfres.pmask = 1;
adapter->params.vpd.cclk = 50000;
adapter->params.chip = 0;
switch (CHELSIO_PCI_ID_VER(adapter->pdev->device)) {
case CHELSIO_T4:
adapter->params.chip |= CHELSIO_CHIP_CODE(CHELSIO_T4, 0);
adapter->params.arch.sge_fl_db = DBPRIO_F;
adapter->params.arch.mps_tcam_size =
NUM_MPS_CLS_SRAM_L_INSTANCES;
break;
case CHELSIO_T5:
chipid = REV_G(t4_read_reg(adapter, PL_VF_REV_A));
adapter->params.chip |= CHELSIO_CHIP_CODE(CHELSIO_T5, chipid);
adapter->params.arch.sge_fl_db = DBPRIO_F | DBTYPE_F;
adapter->params.arch.mps_tcam_size =
NUM_MPS_T5_CLS_SRAM_L_INSTANCES;
break;
case CHELSIO_T6:
chipid = REV_G(t4_read_reg(adapter, PL_VF_REV_A));
adapter->params.chip |= CHELSIO_CHIP_CODE(CHELSIO_T6, chipid);
adapter->params.arch.sge_fl_db = 0;
adapter->params.arch.mps_tcam_size =
NUM_MPS_T5_CLS_SRAM_L_INSTANCES;
break;
}
return 0;
}
