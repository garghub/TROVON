static int mlxsw_sp_port_attr_get(struct net_device *dev,
struct switchdev_attr *attr)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
switch (attr->id) {
case SWITCHDEV_ATTR_ID_PORT_PARENT_ID:
attr->u.ppid.id_len = sizeof(mlxsw_sp->base_mac);
memcpy(&attr->u.ppid.id, &mlxsw_sp->base_mac,
attr->u.ppid.id_len);
break;
case SWITCHDEV_ATTR_ID_PORT_BRIDGE_FLAGS:
attr->u.brport_flags =
(mlxsw_sp_port->learning ? BR_LEARNING : 0) |
(mlxsw_sp_port->learning_sync ? BR_LEARNING_SYNC : 0) |
(mlxsw_sp_port->uc_flood ? BR_FLOOD : 0);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int mlxsw_sp_port_stp_state_set(struct mlxsw_sp_port *mlxsw_sp_port,
u8 state)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
enum mlxsw_reg_spms_state spms_state;
char *spms_pl;
u16 vid;
int err;
switch (state) {
case BR_STATE_DISABLED:
case BR_STATE_FORWARDING:
spms_state = MLXSW_REG_SPMS_STATE_FORWARDING;
break;
case BR_STATE_LISTENING:
case BR_STATE_LEARNING:
spms_state = MLXSW_REG_SPMS_STATE_LEARNING;
break;
case BR_STATE_BLOCKING:
spms_state = MLXSW_REG_SPMS_STATE_DISCARDING;
break;
default:
BUG();
}
spms_pl = kmalloc(MLXSW_REG_SPMS_LEN, GFP_KERNEL);
if (!spms_pl)
return -ENOMEM;
mlxsw_reg_spms_pack(spms_pl, mlxsw_sp_port->local_port);
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
mlxsw_reg_spms_vid_pack(spms_pl, vid, spms_state);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(spms), spms_pl);
kfree(spms_pl);
return err;
}
static int mlxsw_sp_port_attr_stp_state_set(struct mlxsw_sp_port *mlxsw_sp_port,
struct switchdev_trans *trans,
u8 state)
{
if (switchdev_trans_ph_prepare(trans))
return 0;
mlxsw_sp_port->stp_state = state;
return mlxsw_sp_port_stp_state_set(mlxsw_sp_port, state);
}
static int __mlxsw_sp_port_flood_set(struct mlxsw_sp_port *mlxsw_sp_port,
u16 fid_begin, u16 fid_end, bool set,
bool only_uc)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
u16 range = fid_end - fid_begin + 1;
char *sftr_pl;
int err;
sftr_pl = kmalloc(MLXSW_REG_SFTR_LEN, GFP_KERNEL);
if (!sftr_pl)
return -ENOMEM;
mlxsw_reg_sftr_pack(sftr_pl, MLXSW_SP_FLOOD_TABLE_UC, fid_begin,
MLXSW_REG_SFGC_TABLE_TYPE_FID_OFFEST, range,
mlxsw_sp_port->local_port, set);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sftr), sftr_pl);
if (err)
goto buffer_out;
if (only_uc)
goto buffer_out;
mlxsw_reg_sftr_pack(sftr_pl, MLXSW_SP_FLOOD_TABLE_BM, fid_begin,
MLXSW_REG_SFGC_TABLE_TYPE_FID_OFFEST, range,
mlxsw_sp_port->local_port, set);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sftr), sftr_pl);
buffer_out:
kfree(sftr_pl);
return err;
}
static int mlxsw_sp_port_uc_flood_set(struct mlxsw_sp_port *mlxsw_sp_port,
bool set)
{
struct net_device *dev = mlxsw_sp_port->dev;
u16 vid, last_visited_vid;
int err;
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
err = __mlxsw_sp_port_flood_set(mlxsw_sp_port, vid, vid, set,
true);
if (err) {
last_visited_vid = vid;
goto err_port_flood_set;
}
}
return 0;
err_port_flood_set:
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, last_visited_vid)
__mlxsw_sp_port_flood_set(mlxsw_sp_port, vid, vid, !set, true);
netdev_err(dev, "Failed to configure unicast flooding\n");
return err;
}
static int mlxsw_sp_port_attr_br_flags_set(struct mlxsw_sp_port *mlxsw_sp_port,
struct switchdev_trans *trans,
unsigned long brport_flags)
{
unsigned long uc_flood = mlxsw_sp_port->uc_flood ? BR_FLOOD : 0;
bool set;
int err;
if (switchdev_trans_ph_prepare(trans))
return 0;
if ((uc_flood ^ brport_flags) & BR_FLOOD) {
set = mlxsw_sp_port->uc_flood ? false : true;
err = mlxsw_sp_port_uc_flood_set(mlxsw_sp_port, set);
if (err)
return err;
}
mlxsw_sp_port->uc_flood = brport_flags & BR_FLOOD ? 1 : 0;
mlxsw_sp_port->learning = brport_flags & BR_LEARNING ? 1 : 0;
mlxsw_sp_port->learning_sync = brport_flags & BR_LEARNING_SYNC ? 1 : 0;
return 0;
}
static int mlxsw_sp_ageing_set(struct mlxsw_sp *mlxsw_sp, u32 ageing_time)
{
char sfdat_pl[MLXSW_REG_SFDAT_LEN];
int err;
mlxsw_reg_sfdat_pack(sfdat_pl, ageing_time);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sfdat), sfdat_pl);
if (err)
return err;
mlxsw_sp->ageing_time = ageing_time;
return 0;
}
static int mlxsw_sp_port_attr_br_ageing_set(struct mlxsw_sp_port *mlxsw_sp_port,
struct switchdev_trans *trans,
unsigned long ageing_clock_t)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
unsigned long ageing_jiffies = clock_t_to_jiffies(ageing_clock_t);
u32 ageing_time = jiffies_to_msecs(ageing_jiffies) / 1000;
if (switchdev_trans_ph_prepare(trans))
return 0;
return mlxsw_sp_ageing_set(mlxsw_sp, ageing_time);
}
static int mlxsw_sp_port_attr_set(struct net_device *dev,
const struct switchdev_attr *attr,
struct switchdev_trans *trans)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
int err = 0;
switch (attr->id) {
case SWITCHDEV_ATTR_ID_PORT_STP_STATE:
err = mlxsw_sp_port_attr_stp_state_set(mlxsw_sp_port, trans,
attr->u.stp_state);
break;
case SWITCHDEV_ATTR_ID_PORT_BRIDGE_FLAGS:
err = mlxsw_sp_port_attr_br_flags_set(mlxsw_sp_port, trans,
attr->u.brport_flags);
break;
case SWITCHDEV_ATTR_ID_BRIDGE_AGEING_TIME:
err = mlxsw_sp_port_attr_br_ageing_set(mlxsw_sp_port, trans,
attr->u.ageing_time);
break;
default:
err = -EOPNOTSUPP;
break;
}
return err;
}
static int mlxsw_sp_port_pvid_set(struct mlxsw_sp_port *mlxsw_sp_port, u16 vid)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char spvid_pl[MLXSW_REG_SPVID_LEN];
mlxsw_reg_spvid_pack(spvid_pl, mlxsw_sp_port->local_port, vid);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(spvid), spvid_pl);
}
static int mlxsw_sp_fid_create(struct mlxsw_sp *mlxsw_sp, u16 fid)
{
char sfmr_pl[MLXSW_REG_SFMR_LEN];
int err;
mlxsw_reg_sfmr_pack(sfmr_pl, MLXSW_REG_SFMR_OP_CREATE_FID, fid, fid);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sfmr), sfmr_pl);
if (err)
return err;
set_bit(fid, mlxsw_sp->active_fids);
return 0;
}
static void mlxsw_sp_fid_destroy(struct mlxsw_sp *mlxsw_sp, u16 fid)
{
char sfmr_pl[MLXSW_REG_SFMR_LEN];
clear_bit(fid, mlxsw_sp->active_fids);
mlxsw_reg_sfmr_pack(sfmr_pl, MLXSW_REG_SFMR_OP_DESTROY_FID,
fid, fid);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sfmr), sfmr_pl);
}
static int mlxsw_sp_port_fid_map(struct mlxsw_sp_port *mlxsw_sp_port, u16 fid)
{
enum mlxsw_reg_svfa_mt mt;
if (mlxsw_sp_port->nr_vfids)
mt = MLXSW_REG_SVFA_MT_PORT_VID_TO_FID;
else
mt = MLXSW_REG_SVFA_MT_VID_TO_FID;
return mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port, mt, true, fid, fid);
}
static int mlxsw_sp_port_fid_unmap(struct mlxsw_sp_port *mlxsw_sp_port, u16 fid)
{
enum mlxsw_reg_svfa_mt mt;
if (!mlxsw_sp_port->nr_vfids)
return 0;
mt = MLXSW_REG_SVFA_MT_PORT_VID_TO_FID;
return mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port, mt, false, fid, fid);
}
static int mlxsw_sp_port_add_vids(struct net_device *dev, u16 vid_begin,
u16 vid_end)
{
u16 vid;
int err;
for (vid = vid_begin; vid <= vid_end; vid++) {
err = mlxsw_sp_port_add_vid(dev, 0, vid);
if (err)
goto err_port_add_vid;
}
return 0;
err_port_add_vid:
for (vid--; vid >= vid_begin; vid--)
mlxsw_sp_port_kill_vid(dev, 0, vid);
return err;
}
static int __mlxsw_sp_port_vlans_add(struct mlxsw_sp_port *mlxsw_sp_port,
u16 vid_begin, u16 vid_end,
bool flag_untagged, bool flag_pvid)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
struct net_device *dev = mlxsw_sp_port->dev;
enum mlxsw_reg_svfa_mt mt;
u16 vid, vid_e;
int err;
if (!mlxsw_sp_port->bridged)
return mlxsw_sp_port_add_vids(dev, vid_begin, vid_end);
for (vid = vid_begin; vid <= vid_end; vid++) {
if (!test_bit(vid, mlxsw_sp->active_fids)) {
err = mlxsw_sp_fid_create(mlxsw_sp, vid);
if (err) {
netdev_err(dev, "Failed to create FID=%d\n",
vid);
return err;
}
mt = MLXSW_REG_SVFA_MT_VID_TO_FID;
err = mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port, mt,
true, vid, vid);
if (err) {
netdev_err(dev, "Failed to create FID=VID=%d mapping\n",
vid);
return err;
}
}
err = mlxsw_sp_port_fid_map(mlxsw_sp_port, vid);
if (err) {
netdev_err(dev, "Failed to map FID=%d", vid);
return err;
}
}
err = __mlxsw_sp_port_flood_set(mlxsw_sp_port, vid_begin, vid_end,
true, false);
if (err) {
netdev_err(dev, "Failed to configure flooding\n");
return err;
}
for (vid = vid_begin; vid <= vid_end;
vid += MLXSW_REG_SPVM_REC_MAX_COUNT) {
vid_e = min((u16) (vid + MLXSW_REG_SPVM_REC_MAX_COUNT - 1),
vid_end);
err = mlxsw_sp_port_vlan_set(mlxsw_sp_port, vid, vid_e, true,
flag_untagged);
if (err) {
netdev_err(mlxsw_sp_port->dev, "Unable to add VIDs %d-%d\n",
vid, vid_e);
return err;
}
}
vid = vid_begin;
if (flag_pvid && mlxsw_sp_port->pvid != vid) {
err = mlxsw_sp_port_pvid_set(mlxsw_sp_port, vid);
if (err) {
netdev_err(mlxsw_sp_port->dev, "Unable to add PVID %d\n",
vid);
return err;
}
mlxsw_sp_port->pvid = vid;
}
for (vid = vid_begin; vid <= vid_end; vid++)
set_bit(vid, mlxsw_sp_port->active_vlans);
return mlxsw_sp_port_stp_state_set(mlxsw_sp_port,
mlxsw_sp_port->stp_state);
}
static int mlxsw_sp_port_vlans_add(struct mlxsw_sp_port *mlxsw_sp_port,
const struct switchdev_obj_port_vlan *vlan,
struct switchdev_trans *trans)
{
bool untagged_flag = vlan->flags & BRIDGE_VLAN_INFO_UNTAGGED;
bool pvid_flag = vlan->flags & BRIDGE_VLAN_INFO_PVID;
if (switchdev_trans_ph_prepare(trans))
return 0;
return __mlxsw_sp_port_vlans_add(mlxsw_sp_port,
vlan->vid_begin, vlan->vid_end,
untagged_flag, pvid_flag);
}
static int mlxsw_sp_port_fdb_op(struct mlxsw_sp_port *mlxsw_sp_port,
const char *mac, u16 vid, bool adding,
bool dynamic)
{
enum mlxsw_reg_sfd_rec_policy policy;
enum mlxsw_reg_sfd_op op;
char *sfd_pl;
int err;
if (!vid)
vid = mlxsw_sp_port->pvid;
sfd_pl = kmalloc(MLXSW_REG_SFD_LEN, GFP_KERNEL);
if (!sfd_pl)
return -ENOMEM;
policy = dynamic ? MLXSW_REG_SFD_REC_POLICY_DYNAMIC_ENTRY_INGRESS :
MLXSW_REG_SFD_REC_POLICY_STATIC_ENTRY;
op = adding ? MLXSW_REG_SFD_OP_WRITE_EDIT :
MLXSW_REG_SFD_OP_WRITE_REMOVE;
mlxsw_reg_sfd_pack(sfd_pl, op, 0);
mlxsw_reg_sfd_uc_pack(sfd_pl, 0, policy,
mac, vid, MLXSW_REG_SFD_REC_ACTION_NOP,
mlxsw_sp_port->local_port);
err = mlxsw_reg_write(mlxsw_sp_port->mlxsw_sp->core, MLXSW_REG(sfd),
sfd_pl);
kfree(sfd_pl);
return err;
}
static int
mlxsw_sp_port_fdb_static_add(struct mlxsw_sp_port *mlxsw_sp_port,
const struct switchdev_obj_port_fdb *fdb,
struct switchdev_trans *trans)
{
if (switchdev_trans_ph_prepare(trans))
return 0;
return mlxsw_sp_port_fdb_op(mlxsw_sp_port, fdb->addr, fdb->vid,
true, false);
}
static int mlxsw_sp_port_obj_add(struct net_device *dev,
const struct switchdev_obj *obj,
struct switchdev_trans *trans)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
int err = 0;
switch (obj->id) {
case SWITCHDEV_OBJ_ID_PORT_VLAN:
err = mlxsw_sp_port_vlans_add(mlxsw_sp_port,
SWITCHDEV_OBJ_PORT_VLAN(obj),
trans);
break;
case SWITCHDEV_OBJ_ID_PORT_FDB:
err = mlxsw_sp_port_fdb_static_add(mlxsw_sp_port,
SWITCHDEV_OBJ_PORT_FDB(obj),
trans);
break;
default:
err = -EOPNOTSUPP;
break;
}
return err;
}
static int mlxsw_sp_port_kill_vids(struct net_device *dev, u16 vid_begin,
u16 vid_end)
{
u16 vid;
int err;
for (vid = vid_begin; vid <= vid_end; vid++) {
err = mlxsw_sp_port_kill_vid(dev, 0, vid);
if (err)
return err;
}
return 0;
}
static int __mlxsw_sp_port_vlans_del(struct mlxsw_sp_port *mlxsw_sp_port,
u16 vid_begin, u16 vid_end, bool init)
{
struct net_device *dev = mlxsw_sp_port->dev;
u16 vid, vid_e;
int err;
if (!init && !mlxsw_sp_port->bridged)
return mlxsw_sp_port_kill_vids(dev, vid_begin, vid_end);
for (vid = vid_begin; vid <= vid_end;
vid += MLXSW_REG_SPVM_REC_MAX_COUNT) {
vid_e = min((u16) (vid + MLXSW_REG_SPVM_REC_MAX_COUNT - 1),
vid_end);
err = mlxsw_sp_port_vlan_set(mlxsw_sp_port, vid, vid_e, false,
false);
if (err) {
netdev_err(mlxsw_sp_port->dev, "Unable to del VIDs %d-%d\n",
vid, vid_e);
return err;
}
}
if ((mlxsw_sp_port->pvid >= vid_begin) &&
(mlxsw_sp_port->pvid <= vid_end)) {
mlxsw_sp_port->pvid = 1;
err = mlxsw_sp_port_pvid_set(mlxsw_sp_port,
mlxsw_sp_port->pvid);
if (err) {
netdev_err(mlxsw_sp_port->dev, "Unable to del PVID %d\n",
vid);
return err;
}
}
if (init)
goto out;
err = __mlxsw_sp_port_flood_set(mlxsw_sp_port, vid_begin, vid_end,
false, false);
if (err) {
netdev_err(dev, "Failed to clear flooding\n");
return err;
}
for (vid = vid_begin; vid <= vid_end; vid++) {
err = mlxsw_sp_port_fid_unmap(mlxsw_sp_port, vid);
if (err) {
netdev_err(dev, "Failed to unmap FID=%d", vid);
return err;
}
}
out:
for (vid = vid_begin; vid <= vid_end; vid++)
clear_bit(vid, mlxsw_sp_port->active_vlans);
return 0;
}
static int mlxsw_sp_port_vlans_del(struct mlxsw_sp_port *mlxsw_sp_port,
const struct switchdev_obj_port_vlan *vlan)
{
return __mlxsw_sp_port_vlans_del(mlxsw_sp_port,
vlan->vid_begin, vlan->vid_end, false);
}
static int
mlxsw_sp_port_fdb_static_del(struct mlxsw_sp_port *mlxsw_sp_port,
const struct switchdev_obj_port_fdb *fdb)
{
return mlxsw_sp_port_fdb_op(mlxsw_sp_port, fdb->addr, fdb->vid,
false, false);
}
static int mlxsw_sp_port_obj_del(struct net_device *dev,
const struct switchdev_obj *obj)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
int err = 0;
switch (obj->id) {
case SWITCHDEV_OBJ_ID_PORT_VLAN:
err = mlxsw_sp_port_vlans_del(mlxsw_sp_port,
SWITCHDEV_OBJ_PORT_VLAN(obj));
break;
case SWITCHDEV_OBJ_ID_PORT_FDB:
err = mlxsw_sp_port_fdb_static_del(mlxsw_sp_port,
SWITCHDEV_OBJ_PORT_FDB(obj));
break;
default:
err = -EOPNOTSUPP;
break;
}
return err;
}
static int mlxsw_sp_port_fdb_dump(struct mlxsw_sp_port *mlxsw_sp_port,
struct switchdev_obj_port_fdb *fdb,
switchdev_obj_dump_cb_t *cb)
{
char *sfd_pl;
char mac[ETH_ALEN];
u16 vid;
u8 local_port;
u8 num_rec;
int stored_err = 0;
int i;
int err;
sfd_pl = kmalloc(MLXSW_REG_SFD_LEN, GFP_KERNEL);
if (!sfd_pl)
return -ENOMEM;
mlxsw_reg_sfd_pack(sfd_pl, MLXSW_REG_SFD_OP_QUERY_DUMP, 0);
do {
mlxsw_reg_sfd_num_rec_set(sfd_pl, MLXSW_REG_SFD_REC_MAX_COUNT);
err = mlxsw_reg_query(mlxsw_sp_port->mlxsw_sp->core,
MLXSW_REG(sfd), sfd_pl);
if (err)
goto out;
num_rec = mlxsw_reg_sfd_num_rec_get(sfd_pl);
if (stored_err)
continue;
for (i = 0; i < num_rec; i++) {
switch (mlxsw_reg_sfd_rec_type_get(sfd_pl, i)) {
case MLXSW_REG_SFD_REC_TYPE_UNICAST:
mlxsw_reg_sfd_uc_unpack(sfd_pl, i, mac, &vid,
&local_port);
if (local_port == mlxsw_sp_port->local_port) {
ether_addr_copy(fdb->addr, mac);
fdb->ndm_state = NUD_REACHABLE;
fdb->vid = vid;
err = cb(&fdb->obj);
if (err)
stored_err = err;
}
}
}
} while (num_rec == MLXSW_REG_SFD_REC_MAX_COUNT);
out:
kfree(sfd_pl);
return stored_err ? stored_err : err;
}
static int mlxsw_sp_port_vlan_dump(struct mlxsw_sp_port *mlxsw_sp_port,
struct switchdev_obj_port_vlan *vlan,
switchdev_obj_dump_cb_t *cb)
{
u16 vid;
int err = 0;
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
vlan->flags = 0;
if (vid == mlxsw_sp_port->pvid)
vlan->flags |= BRIDGE_VLAN_INFO_PVID;
vlan->vid_begin = vid;
vlan->vid_end = vid;
err = cb(&vlan->obj);
if (err)
break;
}
return err;
}
static int mlxsw_sp_port_obj_dump(struct net_device *dev,
struct switchdev_obj *obj,
switchdev_obj_dump_cb_t *cb)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
int err = 0;
switch (obj->id) {
case SWITCHDEV_OBJ_ID_PORT_VLAN:
err = mlxsw_sp_port_vlan_dump(mlxsw_sp_port,
SWITCHDEV_OBJ_PORT_VLAN(obj), cb);
break;
case SWITCHDEV_OBJ_ID_PORT_FDB:
err = mlxsw_sp_port_fdb_dump(mlxsw_sp_port,
SWITCHDEV_OBJ_PORT_FDB(obj), cb);
break;
default:
err = -EOPNOTSUPP;
break;
}
return err;
}
static void mlxsw_sp_fdb_notify_mac_process(struct mlxsw_sp *mlxsw_sp,
char *sfn_pl, int rec_index,
bool adding)
{
struct mlxsw_sp_port *mlxsw_sp_port;
char mac[ETH_ALEN];
u8 local_port;
u16 vid;
int err;
mlxsw_reg_sfn_mac_unpack(sfn_pl, rec_index, mac, &vid, &local_port);
mlxsw_sp_port = mlxsw_sp->ports[local_port];
if (!mlxsw_sp_port) {
dev_err_ratelimited(mlxsw_sp->bus_info->dev, "Incorrect local port in FDB notification\n");
return;
}
err = mlxsw_sp_port_fdb_op(mlxsw_sp_port, mac, vid,
adding && mlxsw_sp_port->learning, true);
if (err) {
if (net_ratelimit())
netdev_err(mlxsw_sp_port->dev, "Failed to set FDB entry\n");
return;
}
if (mlxsw_sp_port->learning && mlxsw_sp_port->learning_sync) {
struct switchdev_notifier_fdb_info info;
unsigned long notifier_type;
info.addr = mac;
info.vid = vid;
notifier_type = adding ? SWITCHDEV_FDB_ADD : SWITCHDEV_FDB_DEL;
call_switchdev_notifiers(notifier_type, mlxsw_sp_port->dev,
&info.info);
}
}
static void mlxsw_sp_fdb_notify_rec_process(struct mlxsw_sp *mlxsw_sp,
char *sfn_pl, int rec_index)
{
switch (mlxsw_reg_sfn_rec_type_get(sfn_pl, rec_index)) {
case MLXSW_REG_SFN_REC_TYPE_LEARNED_MAC:
mlxsw_sp_fdb_notify_mac_process(mlxsw_sp, sfn_pl,
rec_index, true);
break;
case MLXSW_REG_SFN_REC_TYPE_AGED_OUT_MAC:
mlxsw_sp_fdb_notify_mac_process(mlxsw_sp, sfn_pl,
rec_index, false);
break;
}
}
static void mlxsw_sp_fdb_notify_work_schedule(struct mlxsw_sp *mlxsw_sp)
{
schedule_delayed_work(&mlxsw_sp->fdb_notify.dw,
msecs_to_jiffies(mlxsw_sp->fdb_notify.interval));
}
static void mlxsw_sp_fdb_notify_work(struct work_struct *work)
{
struct mlxsw_sp *mlxsw_sp;
char *sfn_pl;
u8 num_rec;
int i;
int err;
sfn_pl = kmalloc(MLXSW_REG_SFN_LEN, GFP_KERNEL);
if (!sfn_pl)
return;
mlxsw_sp = container_of(work, struct mlxsw_sp, fdb_notify.dw.work);
do {
mlxsw_reg_sfn_pack(sfn_pl);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(sfn), sfn_pl);
if (err) {
dev_err_ratelimited(mlxsw_sp->bus_info->dev, "Failed to get FDB notifications\n");
break;
}
num_rec = mlxsw_reg_sfn_num_rec_get(sfn_pl);
for (i = 0; i < num_rec; i++)
mlxsw_sp_fdb_notify_rec_process(mlxsw_sp, sfn_pl, i);
} while (num_rec);
kfree(sfn_pl);
mlxsw_sp_fdb_notify_work_schedule(mlxsw_sp);
}
static int mlxsw_sp_fdb_init(struct mlxsw_sp *mlxsw_sp)
{
int err;
err = mlxsw_sp_ageing_set(mlxsw_sp, MLXSW_SP_DEFAULT_AGEING_TIME);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to set default ageing time\n");
return err;
}
INIT_DELAYED_WORK(&mlxsw_sp->fdb_notify.dw, mlxsw_sp_fdb_notify_work);
mlxsw_sp->fdb_notify.interval = MLXSW_SP_DEFAULT_LEARNING_INTERVAL;
mlxsw_sp_fdb_notify_work_schedule(mlxsw_sp);
return 0;
}
static void mlxsw_sp_fdb_fini(struct mlxsw_sp *mlxsw_sp)
{
cancel_delayed_work_sync(&mlxsw_sp->fdb_notify.dw);
}
static void mlxsw_sp_fids_fini(struct mlxsw_sp *mlxsw_sp)
{
u16 fid;
for_each_set_bit(fid, mlxsw_sp->active_fids, VLAN_N_VID)
mlxsw_sp_fid_destroy(mlxsw_sp, fid);
}
int mlxsw_sp_switchdev_init(struct mlxsw_sp *mlxsw_sp)
{
return mlxsw_sp_fdb_init(mlxsw_sp);
}
void mlxsw_sp_switchdev_fini(struct mlxsw_sp *mlxsw_sp)
{
mlxsw_sp_fdb_fini(mlxsw_sp);
mlxsw_sp_fids_fini(mlxsw_sp);
}
int mlxsw_sp_port_vlan_init(struct mlxsw_sp_port *mlxsw_sp_port)
{
struct net_device *dev = mlxsw_sp_port->dev;
int err;
mlxsw_sp_port->pvid = 1;
err = __mlxsw_sp_port_vlans_del(mlxsw_sp_port, 0, VLAN_N_VID, true);
if (err) {
netdev_err(dev, "Unable to init VLANs\n");
return err;
}
err = mlxsw_sp_port_add_vid(dev, 0, 1);
if (err)
netdev_err(dev, "Failed to configure default vFID\n");
return err;
}
void mlxsw_sp_port_switchdev_init(struct mlxsw_sp_port *mlxsw_sp_port)
{
mlxsw_sp_port->dev->switchdev_ops = &mlxsw_sp_port_switchdev_ops;
}
void mlxsw_sp_port_switchdev_fini(struct mlxsw_sp_port *mlxsw_sp_port)
{
}
