void cxgb4_dcb_state_init(struct net_device *dev)
{
struct port_info *pi = netdev2pinfo(dev);
struct port_dcb_info *dcb = &pi->dcb;
int version_temp = dcb->dcb_version;
memset(dcb, 0, sizeof(struct port_dcb_info));
dcb->state = CXGB4_DCB_STATE_START;
if (version_temp)
dcb->dcb_version = version_temp;
netdev_dbg(dev, "%s: Initializing DCB state for port[%d]\n",
__func__, pi->port_id);
}
void cxgb4_dcb_version_init(struct net_device *dev)
{
struct port_info *pi = netdev2pinfo(dev);
struct port_dcb_info *dcb = &pi->dcb;
dcb->dcb_version = FW_PORT_DCB_VER_AUTO;
}
static void cxgb4_dcb_cleanup_apps(struct net_device *dev)
{
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
struct port_dcb_info *dcb = &pi->dcb;
struct dcb_app app;
int i, err;
app.priority = 0;
for (i = 0; i < CXGB4_MAX_DCBX_APP_SUPPORTED; i++) {
if (!dcb->app_priority[i].protocolid)
break;
app.protocol = dcb->app_priority[i].protocolid;
if (dcb->dcb_version == FW_PORT_DCB_VER_IEEE) {
app.priority = dcb->app_priority[i].user_prio_map;
app.selector = dcb->app_priority[i].sel_field + 1;
err = dcb_ieee_delapp(dev, &app);
} else {
app.selector = !!(dcb->app_priority[i].sel_field);
err = dcb_setapp(dev, &app);
}
if (err) {
dev_err(adap->pdev_dev,
"Failed DCB Clear %s Application Priority: sel=%d, prot=%d, , err=%d\n",
dcb_ver_array[dcb->dcb_version], app.selector,
app.protocol, -err);
break;
}
}
}
void cxgb4_dcb_state_fsm(struct net_device *dev,
enum cxgb4_dcb_state_input transition_to)
{
struct port_info *pi = netdev2pinfo(dev);
struct port_dcb_info *dcb = &pi->dcb;
struct adapter *adap = pi->adapter;
enum cxgb4_dcb_state current_state = dcb->state;
netdev_dbg(dev, "%s: State change from %d to %d for %s\n",
__func__, dcb->state, transition_to, dev->name);
switch (current_state) {
case CXGB4_DCB_STATE_START: {
switch (transition_to) {
case CXGB4_DCB_INPUT_FW_DISABLED: {
dcb->state = CXGB4_DCB_STATE_HOST;
dcb->supported = CXGB4_DCBX_HOST_SUPPORT;
break;
}
case CXGB4_DCB_INPUT_FW_ENABLED: {
dcb->state = CXGB4_DCB_STATE_FW_INCOMPLETE;
dcb->supported = DCB_CAP_DCBX_LLD_MANAGED;
if (dcb->dcb_version == FW_PORT_DCB_VER_IEEE)
dcb->supported |= DCB_CAP_DCBX_VER_IEEE;
else
dcb->supported |= DCB_CAP_DCBX_VER_CEE;
break;
}
case CXGB4_DCB_INPUT_FW_INCOMPLETE: {
break;
}
case CXGB4_DCB_INPUT_FW_ALLSYNCED: {
dcb->state = CXGB4_DCB_STATE_FW_ALLSYNCED;
break;
}
default:
goto bad_state_input;
}
break;
}
case CXGB4_DCB_STATE_FW_INCOMPLETE: {
switch (transition_to) {
case CXGB4_DCB_INPUT_FW_ENABLED: {
break;
}
case CXGB4_DCB_INPUT_FW_INCOMPLETE: {
break;
}
case CXGB4_DCB_INPUT_FW_ALLSYNCED: {
dcb->state = CXGB4_DCB_STATE_FW_ALLSYNCED;
dcb->enabled = 1;
linkwatch_fire_event(dev);
break;
}
default:
goto bad_state_input;
}
break;
}
case CXGB4_DCB_STATE_FW_ALLSYNCED: {
switch (transition_to) {
case CXGB4_DCB_INPUT_FW_ENABLED: {
break;
}
case CXGB4_DCB_INPUT_FW_INCOMPLETE: {
cxgb4_dcb_cleanup_apps(dev);
cxgb4_dcb_state_init(dev);
dcb->state = CXGB4_DCB_STATE_FW_INCOMPLETE;
dcb->supported = CXGB4_DCBX_FW_SUPPORT;
linkwatch_fire_event(dev);
break;
}
case CXGB4_DCB_INPUT_FW_ALLSYNCED: {
dcb->enabled = 1;
linkwatch_fire_event(dev);
break;
}
default:
goto bad_state_input;
}
break;
}
case CXGB4_DCB_STATE_HOST: {
switch (transition_to) {
case CXGB4_DCB_INPUT_FW_DISABLED: {
break;
}
default:
goto bad_state_input;
}
break;
}
default:
goto bad_state_transition;
}
return;
bad_state_input:
dev_err(adap->pdev_dev, "cxgb4_dcb_state_fsm: illegal input symbol %d\n",
transition_to);
return;
bad_state_transition:
dev_err(adap->pdev_dev, "cxgb4_dcb_state_fsm: bad state transition, state = %d, input = %d\n",
current_state, transition_to);
}
void cxgb4_dcb_handle_fw_update(struct adapter *adap,
const struct fw_port_cmd *pcmd)
{
const union fw_port_dcb *fwdcb = &pcmd->u.dcb;
int port = FW_PORT_CMD_PORTID_G(be32_to_cpu(pcmd->op_to_portid));
struct net_device *dev = adap->port[port];
struct port_info *pi = netdev_priv(dev);
struct port_dcb_info *dcb = &pi->dcb;
int dcb_type = pcmd->u.dcb.pgid.type;
int dcb_running_version;
if (dcb_type == FW_PORT_DCB_TYPE_CONTROL) {
enum cxgb4_dcb_state_input input =
((pcmd->u.dcb.control.all_syncd_pkd &
FW_PORT_CMD_ALL_SYNCD_F)
? CXGB4_DCB_STATE_FW_ALLSYNCED
: CXGB4_DCB_STATE_FW_INCOMPLETE);
if (dcb->dcb_version != FW_PORT_DCB_VER_UNKNOWN) {
dcb_running_version = FW_PORT_CMD_DCB_VERSION_G(
be16_to_cpu(
pcmd->u.dcb.control.dcb_version_to_app_state));
if (dcb_running_version == FW_PORT_DCB_VER_CEE1D01 ||
dcb_running_version == FW_PORT_DCB_VER_IEEE) {
dcb->dcb_version = dcb_running_version;
dev_warn(adap->pdev_dev, "Interface %s is running %s\n",
dev->name,
dcb_ver_array[dcb->dcb_version]);
} else {
dev_warn(adap->pdev_dev,
"Something screwed up, requested firmware for %s, but firmware returned %s instead\n",
dcb_ver_array[dcb->dcb_version],
dcb_ver_array[dcb_running_version]);
dcb->dcb_version = FW_PORT_DCB_VER_UNKNOWN;
}
}
cxgb4_dcb_state_fsm(dev, input);
return;
}
if (dcb->state == CXGB4_DCB_STATE_START ||
dcb->state == CXGB4_DCB_STATE_HOST) {
dev_err(adap->pdev_dev, "Receiving Firmware DCB messages in State %d\n",
dcb->state);
return;
}
switch (dcb_type) {
case FW_PORT_DCB_TYPE_PGID:
dcb->pgid = be32_to_cpu(fwdcb->pgid.pgid);
dcb->msgs |= CXGB4_DCB_FW_PGID;
break;
case FW_PORT_DCB_TYPE_PGRATE:
dcb->pg_num_tcs_supported = fwdcb->pgrate.num_tcs_supported;
memcpy(dcb->pgrate, &fwdcb->pgrate.pgrate,
sizeof(dcb->pgrate));
memcpy(dcb->tsa, &fwdcb->pgrate.tsa,
sizeof(dcb->tsa));
dcb->msgs |= CXGB4_DCB_FW_PGRATE;
if (dcb->msgs & CXGB4_DCB_FW_PGID)
IEEE_FAUX_SYNC(dev, dcb);
break;
case FW_PORT_DCB_TYPE_PRIORATE:
memcpy(dcb->priorate, &fwdcb->priorate.strict_priorate,
sizeof(dcb->priorate));
dcb->msgs |= CXGB4_DCB_FW_PRIORATE;
break;
case FW_PORT_DCB_TYPE_PFC:
dcb->pfcen = fwdcb->pfc.pfcen;
dcb->pfc_num_tcs_supported = fwdcb->pfc.max_pfc_tcs;
dcb->msgs |= CXGB4_DCB_FW_PFC;
IEEE_FAUX_SYNC(dev, dcb);
break;
case FW_PORT_DCB_TYPE_APP_ID: {
const struct fw_port_app_priority *fwap = &fwdcb->app_priority;
int idx = fwap->idx;
struct app_priority *ap = &dcb->app_priority[idx];
struct dcb_app app = {
.protocol = be16_to_cpu(fwap->protocolid),
};
int err;
if (dcb->dcb_version == FW_PORT_DCB_VER_IEEE) {
app.selector = (fwap->sel_field + 1);
app.priority = ffs(fwap->user_prio_map) - 1;
err = dcb_ieee_setapp(dev, &app);
IEEE_FAUX_SYNC(dev, dcb);
} else {
app.selector = !!(fwap->sel_field);
app.priority = fwap->user_prio_map;
err = dcb_setapp(dev, &app);
}
if (err)
dev_err(adap->pdev_dev,
"Failed DCB Set Application Priority: sel=%d, prot=%d, prio=%d, err=%d\n",
app.selector, app.protocol, app.priority, -err);
ap->user_prio_map = fwap->user_prio_map;
ap->sel_field = fwap->sel_field;
ap->protocolid = be16_to_cpu(fwap->protocolid);
dcb->msgs |= CXGB4_DCB_FW_APP_ID;
break;
}
default:
dev_err(adap->pdev_dev, "Unknown DCB update type received %x\n",
dcb_type);
break;
}
}
static u8 cxgb4_getstate(struct net_device *dev)
{
struct port_info *pi = netdev2pinfo(dev);
return pi->dcb.enabled;
}
static u8 cxgb4_setstate(struct net_device *dev, u8 enabled)
{
struct port_info *pi = netdev2pinfo(dev);
if (pi->dcb.state == CXGB4_DCB_STATE_HOST) {
pi->dcb.enabled = enabled;
return 0;
}
if (enabled != (pi->dcb.state == CXGB4_DCB_STATE_FW_ALLSYNCED))
return 1;
return 0;
}
static void cxgb4_getpgtccfg(struct net_device *dev, int tc,
u8 *prio_type, u8 *pgid, u8 *bw_per,
u8 *up_tc_map, int local)
{
struct fw_port_cmd pcmd;
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
int err;
*prio_type = *pgid = *bw_per = *up_tc_map = 0;
if (local)
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
else
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
pcmd.u.dcb.pgid.type = FW_PORT_DCB_TYPE_PGID;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGID failed with %d\n", -err);
return;
}
*pgid = (be32_to_cpu(pcmd.u.dcb.pgid.pgid) >> (tc * 4)) & 0xf;
if (local)
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
else
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
pcmd.u.dcb.pgrate.type = FW_PORT_DCB_TYPE_PGRATE;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGRATE failed with %d\n",
-err);
return;
}
*bw_per = pcmd.u.dcb.pgrate.pgrate[*pgid];
*up_tc_map = (1 << tc);
if (*pgid != 0xF)
*prio_type = 0x2;
}
static void cxgb4_getpgtccfg_tx(struct net_device *dev, int tc,
u8 *prio_type, u8 *pgid, u8 *bw_per,
u8 *up_tc_map)
{
return cxgb4_getpgtccfg(dev, (7 - tc), prio_type, pgid, bw_per,
up_tc_map, 1);
}
static void cxgb4_getpgtccfg_rx(struct net_device *dev, int tc,
u8 *prio_type, u8 *pgid, u8 *bw_per,
u8 *up_tc_map)
{
return cxgb4_getpgtccfg(dev, (7 - tc), prio_type, pgid, bw_per,
up_tc_map, 0);
}
static void cxgb4_setpgtccfg_tx(struct net_device *dev, int tc,
u8 prio_type, u8 pgid, u8 bw_per,
u8 up_tc_map)
{
struct fw_port_cmd pcmd;
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
int fw_tc = 7 - tc;
u32 _pgid;
int err;
if (pgid == DCB_ATTR_VALUE_UNDEFINED)
return;
if (bw_per == DCB_ATTR_VALUE_UNDEFINED)
return;
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
pcmd.u.dcb.pgid.type = FW_PORT_DCB_TYPE_PGID;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGID failed with %d\n", -err);
return;
}
_pgid = be32_to_cpu(pcmd.u.dcb.pgid.pgid);
_pgid &= ~(0xF << (fw_tc * 4));
_pgid |= pgid << (fw_tc * 4);
pcmd.u.dcb.pgid.pgid = cpu_to_be32(_pgid);
INIT_PORT_DCB_WRITE_CMD(pcmd, pi->port_id);
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB write PGID failed with %d\n",
-err);
return;
}
memset(&pcmd, 0, sizeof(struct fw_port_cmd));
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
pcmd.u.dcb.pgrate.type = FW_PORT_DCB_TYPE_PGRATE;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGRATE failed with %d\n",
-err);
return;
}
pcmd.u.dcb.pgrate.pgrate[pgid] = bw_per;
INIT_PORT_DCB_WRITE_CMD(pcmd, pi->port_id);
if (pi->dcb.state == CXGB4_DCB_STATE_HOST)
pcmd.op_to_portid |= cpu_to_be32(FW_PORT_CMD_APPLY_F);
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS)
dev_err(adap->pdev_dev, "DCB write PGRATE failed with %d\n",
-err);
}
static void cxgb4_getpgbwgcfg(struct net_device *dev, int pgid, u8 *bw_per,
int local)
{
struct fw_port_cmd pcmd;
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
int err;
if (local)
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
else
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
pcmd.u.dcb.pgrate.type = FW_PORT_DCB_TYPE_PGRATE;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGRATE failed with %d\n",
-err);
return;
}
*bw_per = pcmd.u.dcb.pgrate.pgrate[pgid];
}
static void cxgb4_getpgbwgcfg_tx(struct net_device *dev, int pgid, u8 *bw_per)
{
return cxgb4_getpgbwgcfg(dev, pgid, bw_per, 1);
}
static void cxgb4_getpgbwgcfg_rx(struct net_device *dev, int pgid, u8 *bw_per)
{
return cxgb4_getpgbwgcfg(dev, pgid, bw_per, 0);
}
static void cxgb4_setpgbwgcfg_tx(struct net_device *dev, int pgid,
u8 bw_per)
{
struct fw_port_cmd pcmd;
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
int err;
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
pcmd.u.dcb.pgrate.type = FW_PORT_DCB_TYPE_PGRATE;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGRATE failed with %d\n",
-err);
return;
}
pcmd.u.dcb.pgrate.pgrate[pgid] = bw_per;
INIT_PORT_DCB_WRITE_CMD(pcmd, pi->port_id);
if (pi->dcb.state == CXGB4_DCB_STATE_HOST)
pcmd.op_to_portid |= cpu_to_be32(FW_PORT_CMD_APPLY_F);
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS)
dev_err(adap->pdev_dev, "DCB write PGRATE failed with %d\n",
-err);
}
static void cxgb4_getpfccfg(struct net_device *dev, int priority, u8 *pfccfg)
{
struct port_info *pi = netdev2pinfo(dev);
struct port_dcb_info *dcb = &pi->dcb;
if (dcb->state != CXGB4_DCB_STATE_FW_ALLSYNCED ||
priority >= CXGB4_MAX_PRIORITY)
*pfccfg = 0;
else
*pfccfg = (pi->dcb.pfcen >> (7 - priority)) & 1;
}
static void cxgb4_setpfccfg(struct net_device *dev, int priority, u8 pfccfg)
{
struct fw_port_cmd pcmd;
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
int err;
if (pi->dcb.state != CXGB4_DCB_STATE_FW_ALLSYNCED ||
priority >= CXGB4_MAX_PRIORITY)
return;
INIT_PORT_DCB_WRITE_CMD(pcmd, pi->port_id);
if (pi->dcb.state == CXGB4_DCB_STATE_HOST)
pcmd.op_to_portid |= cpu_to_be32(FW_PORT_CMD_APPLY_F);
pcmd.u.dcb.pfc.type = FW_PORT_DCB_TYPE_PFC;
pcmd.u.dcb.pfc.pfcen = pi->dcb.pfcen;
if (pfccfg)
pcmd.u.dcb.pfc.pfcen |= (1 << (7 - priority));
else
pcmd.u.dcb.pfc.pfcen &= (~(1 << (7 - priority)));
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB PFC write failed with %d\n", -err);
return;
}
pi->dcb.pfcen = pcmd.u.dcb.pfc.pfcen;
}
static u8 cxgb4_setall(struct net_device *dev)
{
return 0;
}
static u8 cxgb4_getcap(struct net_device *dev, int cap_id, u8 *caps)
{
struct port_info *pi = netdev2pinfo(dev);
switch (cap_id) {
case DCB_CAP_ATTR_PG:
case DCB_CAP_ATTR_PFC:
*caps = true;
break;
case DCB_CAP_ATTR_PG_TCS:
*caps = 0x80;
break;
case DCB_CAP_ATTR_PFC_TCS:
*caps = 0x80;
break;
case DCB_CAP_ATTR_GSP:
*caps = true;
break;
case DCB_CAP_ATTR_UP2TC:
case DCB_CAP_ATTR_BCN:
*caps = false;
break;
case DCB_CAP_ATTR_DCBX:
*caps = pi->dcb.supported;
break;
default:
*caps = false;
}
return 0;
}
static int cxgb4_getnumtcs(struct net_device *dev, int tcs_id, u8 *num)
{
struct port_info *pi = netdev2pinfo(dev);
switch (tcs_id) {
case DCB_NUMTCS_ATTR_PG:
if (pi->dcb.msgs & CXGB4_DCB_FW_PGRATE)
*num = pi->dcb.pg_num_tcs_supported;
else
*num = 0x8;
break;
case DCB_NUMTCS_ATTR_PFC:
*num = 0x8;
break;
default:
return -EINVAL;
}
return 0;
}
static int cxgb4_setnumtcs(struct net_device *dev, int tcs_id, u8 num)
{
return -ENOSYS;
}
static u8 cxgb4_getpfcstate(struct net_device *dev)
{
struct port_info *pi = netdev2pinfo(dev);
if (pi->dcb.state != CXGB4_DCB_STATE_FW_ALLSYNCED)
return false;
return pi->dcb.pfcen != 0;
}
static void cxgb4_setpfcstate(struct net_device *dev, u8 state)
{
}
static int __cxgb4_getapp(struct net_device *dev, u8 app_idtype, u16 app_id,
int peer)
{
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
int i;
if (pi->dcb.state != CXGB4_DCB_STATE_FW_ALLSYNCED)
return 0;
for (i = 0; i < CXGB4_MAX_DCBX_APP_SUPPORTED; i++) {
struct fw_port_cmd pcmd;
int err;
if (peer)
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
else
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
pcmd.u.dcb.app_priority.type = FW_PORT_DCB_TYPE_APP_ID;
pcmd.u.dcb.app_priority.idx = i;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB APP read failed with %d\n",
-err);
return err;
}
if (be16_to_cpu(pcmd.u.dcb.app_priority.protocolid) == app_id)
if (pcmd.u.dcb.app_priority.sel_field == app_idtype)
return pcmd.u.dcb.app_priority.user_prio_map;
if (!pcmd.u.dcb.app_priority.protocolid)
break;
}
return -EEXIST;
}
static int cxgb4_getapp(struct net_device *dev, u8 app_idtype, u16 app_id)
{
return __cxgb4_getapp(dev, app_idtype, app_id, 0);
}
static int __cxgb4_setapp(struct net_device *dev, u8 app_idtype, u16 app_id,
u8 app_prio)
{
struct fw_port_cmd pcmd;
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
int i, err;
if (pi->dcb.state != CXGB4_DCB_STATE_FW_ALLSYNCED)
return -EINVAL;
if (!netif_carrier_ok(dev))
return -ENOLINK;
for (i = 0; i < CXGB4_MAX_DCBX_APP_SUPPORTED; i++) {
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
pcmd.u.dcb.app_priority.type = FW_PORT_DCB_TYPE_APP_ID;
pcmd.u.dcb.app_priority.idx = i;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB app table read failed with %d\n",
-err);
return err;
}
if (be16_to_cpu(pcmd.u.dcb.app_priority.protocolid) == app_id) {
pcmd.u.dcb.app_priority.protocolid = 0;
break;
}
if (!pcmd.u.dcb.app_priority.protocolid)
break;
}
if (i == CXGB4_MAX_DCBX_APP_SUPPORTED) {
dev_err(adap->pdev_dev, "DCB app table full\n");
return -EBUSY;
}
INIT_PORT_DCB_WRITE_CMD(pcmd, pi->port_id);
if (pi->dcb.state == CXGB4_DCB_STATE_HOST)
pcmd.op_to_portid |= cpu_to_be32(FW_PORT_CMD_APPLY_F);
pcmd.u.dcb.app_priority.type = FW_PORT_DCB_TYPE_APP_ID;
pcmd.u.dcb.app_priority.protocolid = cpu_to_be16(app_id);
pcmd.u.dcb.app_priority.sel_field = app_idtype;
pcmd.u.dcb.app_priority.user_prio_map = app_prio;
pcmd.u.dcb.app_priority.idx = i;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB app table write failed with %d\n",
-err);
return err;
}
return 0;
}
static int cxgb4_setapp(struct net_device *dev, u8 app_idtype, u16 app_id,
u8 app_prio)
{
int ret;
struct dcb_app app = {
.selector = app_idtype,
.protocol = app_id,
.priority = app_prio,
};
if (app_idtype != DCB_APP_IDTYPE_ETHTYPE &&
app_idtype != DCB_APP_IDTYPE_PORTNUM)
return -EINVAL;
ret = __cxgb4_setapp(dev, app_idtype == DCB_APP_IDTYPE_ETHTYPE ?
app_idtype : 3, app_id, app_prio);
if (ret)
return ret;
return dcb_setapp(dev, &app);
}
static inline int
cxgb4_ieee_negotiation_complete(struct net_device *dev,
enum cxgb4_dcb_fw_msgs dcb_subtype)
{
struct port_info *pi = netdev2pinfo(dev);
struct port_dcb_info *dcb = &pi->dcb;
if (dcb_subtype && !(dcb->msgs & dcb_subtype))
return 0;
return (dcb->state == CXGB4_DCB_STATE_FW_ALLSYNCED &&
(dcb->supported & DCB_CAP_DCBX_VER_IEEE));
}
static int cxgb4_ieee_read_ets(struct net_device *dev, struct ieee_ets *ets,
int local)
{
struct port_info *pi = netdev2pinfo(dev);
struct port_dcb_info *dcb = &pi->dcb;
struct adapter *adap = pi->adapter;
uint32_t tc_info;
struct fw_port_cmd pcmd;
int i, bwg, err;
if (!(dcb->msgs & (CXGB4_DCB_FW_PGID | CXGB4_DCB_FW_PGRATE)))
return 0;
ets->ets_cap = dcb->pg_num_tcs_supported;
if (local) {
ets->willing = 1;
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
} else {
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
}
pcmd.u.dcb.pgid.type = FW_PORT_DCB_TYPE_PGID;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGID failed with %d\n", -err);
return err;
}
tc_info = be32_to_cpu(pcmd.u.dcb.pgid.pgid);
if (local)
INIT_PORT_DCB_READ_LOCAL_CMD(pcmd, pi->port_id);
else
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
pcmd.u.dcb.pgrate.type = FW_PORT_DCB_TYPE_PGRATE;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGRATE failed with %d\n",
-err);
return err;
}
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
bwg = (tc_info >> ((7 - i) * 4)) & 0xF;
ets->prio_tc[i] = bwg;
ets->tc_tx_bw[i] = pcmd.u.dcb.pgrate.pgrate[i];
ets->tc_rx_bw[i] = ets->tc_tx_bw[i];
ets->tc_tsa[i] = pcmd.u.dcb.pgrate.tsa[i];
}
return 0;
}
static int cxgb4_ieee_get_ets(struct net_device *dev, struct ieee_ets *ets)
{
return cxgb4_ieee_read_ets(dev, ets, 1);
}
static int cxgb4_ieee_get_pfc(struct net_device *dev, struct ieee_pfc *pfc)
{
struct port_info *pi = netdev2pinfo(dev);
struct port_dcb_info *dcb = &pi->dcb;
memset(pfc, 0, sizeof(struct ieee_pfc));
if (!(dcb->msgs & CXGB4_DCB_FW_PFC))
return 0;
pfc->pfc_cap = dcb->pfc_num_tcs_supported;
pfc->pfc_en = bitswap_1(dcb->pfcen);
return 0;
}
static int cxgb4_ieee_peer_ets(struct net_device *dev, struct ieee_ets *ets)
{
return cxgb4_ieee_read_ets(dev, ets, 0);
}
static int cxgb4_ieee_getapp(struct net_device *dev, struct dcb_app *app)
{
int prio;
if (!cxgb4_ieee_negotiation_complete(dev, CXGB4_DCB_FW_APP_ID))
return -EINVAL;
if (!(app->selector && app->protocol))
return -EINVAL;
prio = __cxgb4_getapp(dev, app->selector - 1, app->protocol, 0);
if (prio < 0)
prio = dcb_ieee_getapp_mask(dev, app);
app->priority = ffs(prio) - 1;
return 0;
}
static int cxgb4_ieee_setapp(struct net_device *dev, struct dcb_app *app)
{
int ret;
if (!cxgb4_ieee_negotiation_complete(dev, CXGB4_DCB_FW_APP_ID))
return -EINVAL;
if (!(app->selector && app->protocol))
return -EINVAL;
if (!(app->selector > IEEE_8021QAZ_APP_SEL_ETHERTYPE &&
app->selector < IEEE_8021QAZ_APP_SEL_ANY))
return -EINVAL;
ret = __cxgb4_setapp(dev, app->selector - 1, app->protocol,
(1 << app->priority));
if (ret)
return ret;
return dcb_ieee_setapp(dev, app);
}
static u8 cxgb4_getdcbx(struct net_device *dev)
{
struct port_info *pi = netdev2pinfo(dev);
return pi->dcb.supported;
}
static u8 cxgb4_setdcbx(struct net_device *dev, u8 dcb_request)
{
struct port_info *pi = netdev2pinfo(dev);
if ((dcb_request & (CXGB4_DCBX_FW_SUPPORT | CXGB4_DCBX_HOST_SUPPORT))
!= dcb_request)
return 1;
if (pi->dcb.state != CXGB4_DCB_STATE_FW_ALLSYNCED)
return 1;
if (dcb_request != pi->dcb.supported)
return 1;
pi->dcb.supported = dcb_request;
return 0;
}
static int cxgb4_getpeer_app(struct net_device *dev,
struct dcb_peer_app_info *info, u16 *app_count)
{
struct fw_port_cmd pcmd;
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
int i, err = 0;
if (pi->dcb.state != CXGB4_DCB_STATE_FW_ALLSYNCED)
return 1;
info->willing = 0;
info->error = 0;
*app_count = 0;
for (i = 0; i < CXGB4_MAX_DCBX_APP_SUPPORTED; i++) {
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
pcmd.u.dcb.app_priority.type = FW_PORT_DCB_TYPE_APP_ID;
pcmd.u.dcb.app_priority.idx = *app_count;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB app table read failed with %d\n",
-err);
return err;
}
if (!pcmd.u.dcb.app_priority.protocolid)
break;
}
*app_count = i;
return err;
}
static int cxgb4_getpeerapp_tbl(struct net_device *dev, struct dcb_app *table)
{
struct fw_port_cmd pcmd;
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
int i, err = 0;
if (pi->dcb.state != CXGB4_DCB_STATE_FW_ALLSYNCED)
return 1;
for (i = 0; i < CXGB4_MAX_DCBX_APP_SUPPORTED; i++) {
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
pcmd.u.dcb.app_priority.type = FW_PORT_DCB_TYPE_APP_ID;
pcmd.u.dcb.app_priority.idx = i;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB app table read failed with %d\n",
-err);
return err;
}
if (!pcmd.u.dcb.app_priority.protocolid)
break;
table[i].selector = pcmd.u.dcb.app_priority.sel_field;
table[i].protocol =
be16_to_cpu(pcmd.u.dcb.app_priority.protocolid);
table[i].priority =
ffs(pcmd.u.dcb.app_priority.user_prio_map) - 1;
}
return err;
}
static int cxgb4_cee_peer_getpg(struct net_device *dev, struct cee_pg *pg)
{
struct fw_port_cmd pcmd;
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = pi->adapter;
u32 pgid;
int i, err;
pg->willing = true;
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
pcmd.u.dcb.pgid.type = FW_PORT_DCB_TYPE_PGID;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGID failed with %d\n", -err);
return err;
}
pgid = be32_to_cpu(pcmd.u.dcb.pgid.pgid);
for (i = 0; i < CXGB4_MAX_PRIORITY; i++)
pg->prio_pg[7 - i] = (pgid >> (i * 4)) & 0xF;
INIT_PORT_DCB_READ_PEER_CMD(pcmd, pi->port_id);
pcmd.u.dcb.pgrate.type = FW_PORT_DCB_TYPE_PGRATE;
err = t4_wr_mbox(adap, adap->mbox, &pcmd, sizeof(pcmd), &pcmd);
if (err != FW_PORT_DCB_CFG_SUCCESS) {
dev_err(adap->pdev_dev, "DCB read PGRATE failed with %d\n",
-err);
return err;
}
for (i = 0; i < CXGB4_MAX_PRIORITY; i++)
pg->pg_bw[i] = pcmd.u.dcb.pgrate.pgrate[i];
return 0;
}
static int cxgb4_cee_peer_getpfc(struct net_device *dev, struct cee_pfc *pfc)
{
struct port_info *pi = netdev2pinfo(dev);
cxgb4_getnumtcs(dev, DCB_NUMTCS_ATTR_PFC, &(pfc->tcs_supported));
pfc->pfc_en = bitswap_1(pi->dcb.pfcen);
return 0;
}
