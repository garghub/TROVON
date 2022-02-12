static void drbd_adm_send_reply(struct sk_buff *skb, struct genl_info *info)
{
genlmsg_end(skb, genlmsg_data(nlmsg_data(nlmsg_hdr(skb))));
if (genlmsg_reply(skb, info))
pr_err("error sending genl reply\n");
}
static int drbd_msg_put_info(struct sk_buff *skb, const char *info)
{
struct nlattr *nla;
int err = -EMSGSIZE;
if (!info || !info[0])
return 0;
nla = nla_nest_start(skb, DRBD_NLA_CFG_REPLY);
if (!nla)
return err;
err = nla_put_string(skb, T_info_text, info);
if (err) {
nla_nest_cancel(skb, nla);
return err;
} else
nla_nest_end(skb, nla);
return 0;
}
static int drbd_adm_prepare(struct drbd_config_context *adm_ctx,
struct sk_buff *skb, struct genl_info *info, unsigned flags)
{
struct drbd_genlmsghdr *d_in = info->userhdr;
const u8 cmd = info->genlhdr->cmd;
int err;
memset(adm_ctx, 0, sizeof(*adm_ctx));
if (cmd != DRBD_ADM_GET_STATUS && !capable(CAP_NET_ADMIN))
return -EPERM;
adm_ctx->reply_skb = genlmsg_new(NLMSG_GOODSIZE, GFP_KERNEL);
if (!adm_ctx->reply_skb) {
err = -ENOMEM;
goto fail;
}
adm_ctx->reply_dh = genlmsg_put_reply(adm_ctx->reply_skb,
info, &drbd_genl_family, 0, cmd);
if (!adm_ctx->reply_dh) {
err = -ENOMEM;
goto fail;
}
adm_ctx->reply_dh->minor = d_in->minor;
adm_ctx->reply_dh->ret_code = NO_ERROR;
adm_ctx->volume = VOLUME_UNSPECIFIED;
if (info->attrs[DRBD_NLA_CFG_CONTEXT]) {
struct nlattr *nla;
err = drbd_cfg_context_from_attrs(NULL, info);
if (err)
goto fail;
err = nla_put_nohdr(adm_ctx->reply_skb,
info->attrs[DRBD_NLA_CFG_CONTEXT]->nla_len,
info->attrs[DRBD_NLA_CFG_CONTEXT]);
if (err)
goto fail;
nla = nested_attr_tb[__nla_type(T_ctx_volume)];
if (nla)
adm_ctx->volume = nla_get_u32(nla);
nla = nested_attr_tb[__nla_type(T_ctx_resource_name)];
if (nla)
adm_ctx->resource_name = nla_data(nla);
adm_ctx->my_addr = nested_attr_tb[__nla_type(T_ctx_my_addr)];
adm_ctx->peer_addr = nested_attr_tb[__nla_type(T_ctx_peer_addr)];
if ((adm_ctx->my_addr &&
nla_len(adm_ctx->my_addr) > sizeof(adm_ctx->connection->my_addr)) ||
(adm_ctx->peer_addr &&
nla_len(adm_ctx->peer_addr) > sizeof(adm_ctx->connection->peer_addr))) {
err = -EINVAL;
goto fail;
}
}
adm_ctx->minor = d_in->minor;
adm_ctx->device = minor_to_device(d_in->minor);
if (adm_ctx->device)
kref_get(&adm_ctx->device->kref);
if (adm_ctx->resource_name) {
adm_ctx->resource = drbd_find_resource(adm_ctx->resource_name);
}
if (!adm_ctx->device && (flags & DRBD_ADM_NEED_MINOR)) {
drbd_msg_put_info(adm_ctx->reply_skb, "unknown minor");
return ERR_MINOR_INVALID;
}
if (!adm_ctx->resource && (flags & DRBD_ADM_NEED_RESOURCE)) {
drbd_msg_put_info(adm_ctx->reply_skb, "unknown resource");
if (adm_ctx->resource_name)
return ERR_RES_NOT_KNOWN;
return ERR_INVALID_REQUEST;
}
if (flags & DRBD_ADM_NEED_CONNECTION) {
if (adm_ctx->resource) {
drbd_msg_put_info(adm_ctx->reply_skb, "no resource name expected");
return ERR_INVALID_REQUEST;
}
if (adm_ctx->device) {
drbd_msg_put_info(adm_ctx->reply_skb, "no minor number expected");
return ERR_INVALID_REQUEST;
}
if (adm_ctx->my_addr && adm_ctx->peer_addr)
adm_ctx->connection = conn_get_by_addrs(nla_data(adm_ctx->my_addr),
nla_len(adm_ctx->my_addr),
nla_data(adm_ctx->peer_addr),
nla_len(adm_ctx->peer_addr));
if (!adm_ctx->connection) {
drbd_msg_put_info(adm_ctx->reply_skb, "unknown connection");
return ERR_INVALID_REQUEST;
}
}
if (adm_ctx->device && adm_ctx->resource &&
adm_ctx->device->resource != adm_ctx->resource) {
pr_warning("request: minor=%u, resource=%s; but that minor belongs to resource %s\n",
adm_ctx->minor, adm_ctx->resource->name,
adm_ctx->device->resource->name);
drbd_msg_put_info(adm_ctx->reply_skb, "minor exists in different resource");
return ERR_INVALID_REQUEST;
}
if (adm_ctx->device &&
adm_ctx->volume != VOLUME_UNSPECIFIED &&
adm_ctx->volume != adm_ctx->device->vnr) {
pr_warning("request: minor=%u, volume=%u; but that minor is volume %u in %s\n",
adm_ctx->minor, adm_ctx->volume,
adm_ctx->device->vnr,
adm_ctx->device->resource->name);
drbd_msg_put_info(adm_ctx->reply_skb, "minor exists as different volume");
return ERR_INVALID_REQUEST;
}
if (!adm_ctx->resource) {
adm_ctx->resource = adm_ctx->device ? adm_ctx->device->resource
: adm_ctx->connection ? adm_ctx->connection->resource : NULL;
if (adm_ctx->resource)
kref_get(&adm_ctx->resource->kref);
}
return NO_ERROR;
fail:
nlmsg_free(adm_ctx->reply_skb);
adm_ctx->reply_skb = NULL;
return err;
}
static int drbd_adm_finish(struct drbd_config_context *adm_ctx,
struct genl_info *info, int retcode)
{
if (adm_ctx->device) {
kref_put(&adm_ctx->device->kref, drbd_destroy_device);
adm_ctx->device = NULL;
}
if (adm_ctx->connection) {
kref_put(&adm_ctx->connection->kref, &drbd_destroy_connection);
adm_ctx->connection = NULL;
}
if (adm_ctx->resource) {
kref_put(&adm_ctx->resource->kref, drbd_destroy_resource);
adm_ctx->resource = NULL;
}
if (!adm_ctx->reply_skb)
return -ENOMEM;
adm_ctx->reply_dh->ret_code = retcode;
drbd_adm_send_reply(adm_ctx->reply_skb, info);
return 0;
}
static void setup_khelper_env(struct drbd_connection *connection, char **envp)
{
char *afs;
if (connection->my_addr_len == 0 || connection->peer_addr_len == 0)
return;
switch (((struct sockaddr *)&connection->peer_addr)->sa_family) {
case AF_INET6:
afs = "ipv6";
snprintf(envp[4], 60, "DRBD_PEER_ADDRESS=%pI6",
&((struct sockaddr_in6 *)&connection->peer_addr)->sin6_addr);
break;
case AF_INET:
afs = "ipv4";
snprintf(envp[4], 60, "DRBD_PEER_ADDRESS=%pI4",
&((struct sockaddr_in *)&connection->peer_addr)->sin_addr);
break;
default:
afs = "ssocks";
snprintf(envp[4], 60, "DRBD_PEER_ADDRESS=%pI4",
&((struct sockaddr_in *)&connection->peer_addr)->sin_addr);
}
snprintf(envp[3], 20, "DRBD_PEER_AF=%s", afs);
}
int drbd_khelper(struct drbd_device *device, char *cmd)
{
char *envp[] = { "HOME=/",
"TERM=linux",
"PATH=/sbin:/usr/sbin:/bin:/usr/bin",
(char[20]) { },
(char[60]) { },
NULL };
char mb[14];
char *argv[] = {usermode_helper, cmd, mb, NULL };
struct drbd_connection *connection = first_peer_device(device)->connection;
struct sib_info sib;
int ret;
if (current == connection->worker.task)
set_bit(CALLBACK_PENDING, &connection->flags);
snprintf(mb, 14, "minor-%d", device_to_minor(device));
setup_khelper_env(connection, envp);
drbd_md_sync(device);
drbd_info(device, "helper command: %s %s %s\n", usermode_helper, cmd, mb);
sib.sib_reason = SIB_HELPER_PRE;
sib.helper_name = cmd;
drbd_bcast_event(device, &sib);
notify_helper(NOTIFY_CALL, device, connection, cmd, 0);
ret = call_usermodehelper(usermode_helper, argv, envp, UMH_WAIT_PROC);
if (ret)
drbd_warn(device, "helper command: %s %s %s exit code %u (0x%x)\n",
usermode_helper, cmd, mb,
(ret >> 8) & 0xff, ret);
else
drbd_info(device, "helper command: %s %s %s exit code %u (0x%x)\n",
usermode_helper, cmd, mb,
(ret >> 8) & 0xff, ret);
sib.sib_reason = SIB_HELPER_POST;
sib.helper_exit_code = ret;
drbd_bcast_event(device, &sib);
notify_helper(NOTIFY_RESPONSE, device, connection, cmd, ret);
if (current == connection->worker.task)
clear_bit(CALLBACK_PENDING, &connection->flags);
if (ret < 0)
ret = 0;
return ret;
}
enum drbd_peer_state conn_khelper(struct drbd_connection *connection, char *cmd)
{
char *envp[] = { "HOME=/",
"TERM=linux",
"PATH=/sbin:/usr/sbin:/bin:/usr/bin",
(char[20]) { },
(char[60]) { },
NULL };
char *resource_name = connection->resource->name;
char *argv[] = {usermode_helper, cmd, resource_name, NULL };
int ret;
setup_khelper_env(connection, envp);
conn_md_sync(connection);
drbd_info(connection, "helper command: %s %s %s\n", usermode_helper, cmd, resource_name);
notify_helper(NOTIFY_CALL, NULL, connection, cmd, 0);
ret = call_usermodehelper(usermode_helper, argv, envp, UMH_WAIT_PROC);
if (ret)
drbd_warn(connection, "helper command: %s %s %s exit code %u (0x%x)\n",
usermode_helper, cmd, resource_name,
(ret >> 8) & 0xff, ret);
else
drbd_info(connection, "helper command: %s %s %s exit code %u (0x%x)\n",
usermode_helper, cmd, resource_name,
(ret >> 8) & 0xff, ret);
notify_helper(NOTIFY_RESPONSE, NULL, connection, cmd, ret);
if (ret < 0)
ret = 0;
return ret;
}
static enum drbd_fencing_p highest_fencing_policy(struct drbd_connection *connection)
{
enum drbd_fencing_p fp = FP_NOT_AVAIL;
struct drbd_peer_device *peer_device;
int vnr;
rcu_read_lock();
idr_for_each_entry(&connection->peer_devices, peer_device, vnr) {
struct drbd_device *device = peer_device->device;
if (get_ldev_if_state(device, D_CONSISTENT)) {
struct disk_conf *disk_conf =
rcu_dereference(peer_device->device->ldev->disk_conf);
fp = max_t(enum drbd_fencing_p, fp, disk_conf->fencing);
put_ldev(device);
}
}
rcu_read_unlock();
return fp;
}
static bool resource_is_supended(struct drbd_resource *resource)
{
return resource->susp || resource->susp_fen || resource->susp_nod;
}
bool conn_try_outdate_peer(struct drbd_connection *connection)
{
struct drbd_resource * const resource = connection->resource;
unsigned int connect_cnt;
union drbd_state mask = { };
union drbd_state val = { };
enum drbd_fencing_p fp;
char *ex_to_string;
int r;
spin_lock_irq(&resource->req_lock);
if (connection->cstate >= C_WF_REPORT_PARAMS) {
drbd_err(connection, "Expected cstate < C_WF_REPORT_PARAMS\n");
spin_unlock_irq(&resource->req_lock);
return false;
}
connect_cnt = connection->connect_cnt;
spin_unlock_irq(&resource->req_lock);
fp = highest_fencing_policy(connection);
switch (fp) {
case FP_NOT_AVAIL:
drbd_warn(connection, "Not fencing peer, I'm not even Consistent myself.\n");
spin_lock_irq(&resource->req_lock);
if (connection->cstate < C_WF_REPORT_PARAMS) {
_conn_request_state(connection,
(union drbd_state) { { .susp_fen = 1 } },
(union drbd_state) { { .susp_fen = 0 } },
CS_VERBOSE | CS_HARD | CS_DC_SUSP);
if (!resource_is_supended(resource))
_tl_restart(connection, CONNECTION_LOST_WHILE_PENDING);
}
spin_unlock_irq(&resource->req_lock);
return false;
case FP_DONT_CARE:
return true;
default: ;
}
r = conn_khelper(connection, "fence-peer");
switch ((r>>8) & 0xff) {
case P_INCONSISTENT:
ex_to_string = "peer is inconsistent or worse";
mask.pdsk = D_MASK;
val.pdsk = D_INCONSISTENT;
break;
case P_OUTDATED:
ex_to_string = "peer was fenced";
mask.pdsk = D_MASK;
val.pdsk = D_OUTDATED;
break;
case P_DOWN:
if (conn_highest_disk(connection) == D_UP_TO_DATE) {
ex_to_string = "peer is unreachable, assumed to be dead";
mask.pdsk = D_MASK;
val.pdsk = D_OUTDATED;
} else {
ex_to_string = "peer unreachable, doing nothing since disk != UpToDate";
}
break;
case P_PRIMARY:
ex_to_string = "peer is active";
drbd_warn(connection, "Peer is primary, outdating myself.\n");
mask.disk = D_MASK;
val.disk = D_OUTDATED;
break;
case P_FENCING:
if (fp != FP_STONITH)
drbd_err(connection, "fence-peer() = 7 && fencing != Stonith !!!\n");
ex_to_string = "peer was stonithed";
mask.pdsk = D_MASK;
val.pdsk = D_OUTDATED;
break;
default:
drbd_err(connection, "fence-peer helper broken, returned %d\n", (r>>8)&0xff);
return false;
}
drbd_info(connection, "fence-peer helper returned %d (%s)\n",
(r>>8) & 0xff, ex_to_string);
spin_lock_irq(&resource->req_lock);
if (connection->cstate < C_WF_REPORT_PARAMS && !test_bit(STATE_SENT, &connection->flags)) {
if (connection->connect_cnt != connect_cnt)
drbd_info(connection, "Ignoring fence-peer exit code\n");
else
_conn_request_state(connection, mask, val, CS_VERBOSE);
}
spin_unlock_irq(&resource->req_lock);
return conn_highest_pdsk(connection) <= D_OUTDATED;
}
static int _try_outdate_peer_async(void *data)
{
struct drbd_connection *connection = (struct drbd_connection *)data;
conn_try_outdate_peer(connection);
kref_put(&connection->kref, drbd_destroy_connection);
return 0;
}
void conn_try_outdate_peer_async(struct drbd_connection *connection)
{
struct task_struct *opa;
kref_get(&connection->kref);
flush_signals(current);
opa = kthread_run(_try_outdate_peer_async, connection, "drbd_async_h");
if (IS_ERR(opa)) {
drbd_err(connection, "out of mem, failed to invoke fence-peer helper\n");
kref_put(&connection->kref, drbd_destroy_connection);
}
}
enum drbd_state_rv
drbd_set_role(struct drbd_device *const device, enum drbd_role new_role, int force)
{
struct drbd_peer_device *const peer_device = first_peer_device(device);
struct drbd_connection *const connection = peer_device ? peer_device->connection : NULL;
const int max_tries = 4;
enum drbd_state_rv rv = SS_UNKNOWN_ERROR;
struct net_conf *nc;
int try = 0;
int forced = 0;
union drbd_state mask, val;
if (new_role == R_PRIMARY) {
struct drbd_connection *connection;
rcu_read_lock();
for_each_connection(connection, device->resource)
request_ping(connection);
rcu_read_unlock();
}
mutex_lock(device->state_mutex);
mask.i = 0; mask.role = R_MASK;
val.i = 0; val.role = new_role;
while (try++ < max_tries) {
rv = _drbd_request_state_holding_state_mutex(device, mask, val, CS_WAIT_COMPLETE);
if (rv == SS_CW_FAILED_BY_PEER && mask.pdsk != 0) {
val.pdsk = 0;
mask.pdsk = 0;
continue;
}
if (rv == SS_NO_UP_TO_DATE_DISK && force &&
(device->state.disk < D_UP_TO_DATE &&
device->state.disk >= D_INCONSISTENT)) {
mask.disk = D_MASK;
val.disk = D_UP_TO_DATE;
forced = 1;
continue;
}
if (rv == SS_NO_UP_TO_DATE_DISK &&
device->state.disk == D_CONSISTENT && mask.pdsk == 0) {
D_ASSERT(device, device->state.pdsk == D_UNKNOWN);
if (conn_try_outdate_peer(connection)) {
val.disk = D_UP_TO_DATE;
mask.disk = D_MASK;
}
continue;
}
if (rv == SS_NOTHING_TO_DO)
goto out;
if (rv == SS_PRIMARY_NOP && mask.pdsk == 0) {
if (!conn_try_outdate_peer(connection) && force) {
drbd_warn(device, "Forced into split brain situation!\n");
mask.pdsk = D_MASK;
val.pdsk = D_OUTDATED;
}
continue;
}
if (rv == SS_TWO_PRIMARIES) {
int timeo;
rcu_read_lock();
nc = rcu_dereference(connection->net_conf);
timeo = nc ? (nc->ping_timeo + 1) * HZ / 10 : 1;
rcu_read_unlock();
schedule_timeout_interruptible(timeo);
if (try < max_tries)
try = max_tries - 1;
continue;
}
if (rv < SS_SUCCESS) {
rv = _drbd_request_state(device, mask, val,
CS_VERBOSE + CS_WAIT_COMPLETE);
if (rv < SS_SUCCESS)
goto out;
}
break;
}
if (rv < SS_SUCCESS)
goto out;
if (forced)
drbd_warn(device, "Forced to consider local data as UpToDate!\n");
wait_event(device->misc_wait, atomic_read(&device->ap_pending_cnt) == 0);
if (new_role == R_SECONDARY) {
if (get_ldev(device)) {
device->ldev->md.uuid[UI_CURRENT] &= ~(u64)1;
put_ldev(device);
}
} else {
mutex_lock(&device->resource->conf_update);
nc = connection->net_conf;
if (nc)
nc->discard_my_data = 0;
mutex_unlock(&device->resource->conf_update);
if (get_ldev(device)) {
if (((device->state.conn < C_CONNECTED ||
device->state.pdsk <= D_FAILED)
&& device->ldev->md.uuid[UI_BITMAP] == 0) || forced)
drbd_uuid_new_current(device);
device->ldev->md.uuid[UI_CURRENT] |= (u64)1;
put_ldev(device);
}
}
if (device->state.conn >= C_WF_REPORT_PARAMS) {
if (forced)
drbd_send_uuids(peer_device);
drbd_send_current_state(peer_device);
}
drbd_md_sync(device);
set_disk_ro(device->vdisk, new_role == R_SECONDARY);
kobject_uevent(&disk_to_dev(device->vdisk)->kobj, KOBJ_CHANGE);
out:
mutex_unlock(device->state_mutex);
return rv;
}
static const char *from_attrs_err_to_txt(int err)
{
return err == -ENOMSG ? "required attribute missing" :
err == -EOPNOTSUPP ? "unknown mandatory attribute" :
err == -EEXIST ? "can not change invariant setting" :
"invalid attribute value";
}
int drbd_adm_set_role(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct set_role_parms parms;
int err;
enum drbd_ret_code retcode;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
memset(&parms, 0, sizeof(parms));
if (info->attrs[DRBD_NLA_SET_ROLE_PARMS]) {
err = set_role_parms_from_attrs(&parms, info);
if (err) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto out;
}
}
genl_unlock();
mutex_lock(&adm_ctx.resource->adm_mutex);
if (info->genlhdr->cmd == DRBD_ADM_PRIMARY)
retcode = drbd_set_role(adm_ctx.device, R_PRIMARY, parms.assume_uptodate);
else
retcode = drbd_set_role(adm_ctx.device, R_SECONDARY, 0);
mutex_unlock(&adm_ctx.resource->adm_mutex);
genl_lock();
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static void drbd_md_set_sector_offsets(struct drbd_device *device,
struct drbd_backing_dev *bdev)
{
sector_t md_size_sect = 0;
unsigned int al_size_sect = bdev->md.al_size_4k * 8;
bdev->md.md_offset = drbd_md_ss(bdev);
switch (bdev->md.meta_dev_idx) {
default:
bdev->md.md_size_sect = MD_128MB_SECT;
bdev->md.al_offset = MD_4kB_SECT;
bdev->md.bm_offset = MD_4kB_SECT + al_size_sect;
break;
case DRBD_MD_INDEX_FLEX_EXT:
bdev->md.md_size_sect = drbd_get_capacity(bdev->md_bdev);
bdev->md.al_offset = MD_4kB_SECT;
bdev->md.bm_offset = MD_4kB_SECT + al_size_sect;
break;
case DRBD_MD_INDEX_INTERNAL:
case DRBD_MD_INDEX_FLEX_INT:
bdev->md.al_offset = -al_size_sect;
md_size_sect = drbd_get_capacity(bdev->backing_bdev);
md_size_sect = ALIGN(md_size_sect, BM_SECT_PER_EXT);
md_size_sect = BM_SECT_TO_EXT(md_size_sect);
md_size_sect = ALIGN(md_size_sect, 8);
md_size_sect += MD_4kB_SECT + al_size_sect;
bdev->md.md_size_sect = md_size_sect;
bdev->md.bm_offset = -md_size_sect + MD_4kB_SECT;
break;
}
}
char *ppsize(char *buf, unsigned long long size)
{
static char units[] = { 'K', 'M', 'G', 'T', 'P', 'E' };
int base = 0;
while (size >= 10000 && base < sizeof(units)-1) {
size = (size >> 10) + !!(size & (1<<9));
base++;
}
sprintf(buf, "%u %cB", (unsigned)size, units[base]);
return buf;
}
void drbd_suspend_io(struct drbd_device *device)
{
atomic_inc(&device->suspend_cnt);
if (drbd_suspended(device))
return;
wait_event(device->misc_wait, !atomic_read(&device->ap_bio_cnt));
}
void drbd_resume_io(struct drbd_device *device)
{
if (atomic_dec_and_test(&device->suspend_cnt))
wake_up(&device->misc_wait);
}
enum determine_dev_size
drbd_determine_dev_size(struct drbd_device *device, enum dds_flags flags, struct resize_parms *rs) __must_hold(local)
{
struct md_offsets_and_sizes {
u64 last_agreed_sect;
u64 md_offset;
s32 al_offset;
s32 bm_offset;
u32 md_size_sect;
u32 al_stripes;
u32 al_stripe_size_4k;
} prev;
sector_t u_size, size;
struct drbd_md *md = &device->ldev->md;
char ppb[10];
void *buffer;
int md_moved, la_size_changed;
enum determine_dev_size rv = DS_UNCHANGED;
drbd_suspend_io(device);
buffer = drbd_md_get_buffer(device, __func__);
if (!buffer) {
drbd_resume_io(device);
return DS_ERROR;
}
prev.last_agreed_sect = md->la_size_sect;
prev.md_offset = md->md_offset;
prev.al_offset = md->al_offset;
prev.bm_offset = md->bm_offset;
prev.md_size_sect = md->md_size_sect;
prev.al_stripes = md->al_stripes;
prev.al_stripe_size_4k = md->al_stripe_size_4k;
if (rs) {
md->al_stripes = rs->al_stripes;
md->al_stripe_size_4k = rs->al_stripe_size / 4;
md->al_size_4k = (u64)rs->al_stripes * rs->al_stripe_size / 4;
}
drbd_md_set_sector_offsets(device, device->ldev);
rcu_read_lock();
u_size = rcu_dereference(device->ldev->disk_conf)->disk_size;
rcu_read_unlock();
size = drbd_new_dev_size(device, device->ldev, u_size, flags & DDSF_FORCED);
if (size < prev.last_agreed_sect) {
if (rs && u_size == 0) {
drbd_warn(device, "Implicit shrink not allowed. "
"Use --size=%llus for explicit shrink.\n",
(unsigned long long)size);
rv = DS_ERROR_SHRINK;
}
if (u_size > size)
rv = DS_ERROR_SPACE_MD;
if (rv != DS_UNCHANGED)
goto err_out;
}
if (drbd_get_capacity(device->this_bdev) != size ||
drbd_bm_capacity(device) != size) {
int err;
err = drbd_bm_resize(device, size, !(flags & DDSF_NO_RESYNC));
if (unlikely(err)) {
size = drbd_bm_capacity(device);
if (size == 0) {
drbd_err(device, "OUT OF MEMORY! "
"Could not allocate bitmap!\n");
} else {
drbd_err(device, "BM resizing failed. "
"Leaving size unchanged\n");
}
rv = DS_ERROR;
}
drbd_set_my_capacity(device, size);
md->la_size_sect = size;
drbd_info(device, "size = %s (%llu KB)\n", ppsize(ppb, size>>1),
(unsigned long long)size>>1);
}
if (rv <= DS_ERROR)
goto err_out;
la_size_changed = (prev.last_agreed_sect != md->la_size_sect);
md_moved = prev.md_offset != md->md_offset
|| prev.md_size_sect != md->md_size_sect;
if (la_size_changed || md_moved || rs) {
u32 prev_flags;
del_timer(&device->md_sync_timer);
wait_event(device->al_wait, lc_try_lock_for_transaction(device->act_log));
prev_flags = md->flags;
md->flags |= MDF_FULL_SYNC | MDF_AL_DISABLED;
drbd_md_write(device, buffer);
drbd_al_initialize(device, buffer);
drbd_info(device, "Writing the whole bitmap, %s\n",
la_size_changed && md_moved ? "size changed and md moved" :
la_size_changed ? "size changed" : "md moved");
drbd_bitmap_io(device, md_moved ? &drbd_bm_write_all : &drbd_bm_write,
"size changed", BM_LOCKED_MASK);
md->flags = prev_flags;
drbd_md_write(device, buffer);
if (rs)
drbd_info(device, "Changed AL layout to al-stripes = %d, al-stripe-size-kB = %d\n",
md->al_stripes, md->al_stripe_size_4k * 4);
}
if (size > prev.last_agreed_sect)
rv = prev.last_agreed_sect ? DS_GREW : DS_GREW_FROM_ZERO;
if (size < prev.last_agreed_sect)
rv = DS_SHRUNK;
if (0) {
err_out:
md->la_size_sect = prev.last_agreed_sect;
md->md_offset = prev.md_offset;
md->al_offset = prev.al_offset;
md->bm_offset = prev.bm_offset;
md->md_size_sect = prev.md_size_sect;
md->al_stripes = prev.al_stripes;
md->al_stripe_size_4k = prev.al_stripe_size_4k;
md->al_size_4k = (u64)prev.al_stripes * prev.al_stripe_size_4k;
}
lc_unlock(device->act_log);
wake_up(&device->al_wait);
drbd_md_put_buffer(device);
drbd_resume_io(device);
return rv;
}
sector_t
drbd_new_dev_size(struct drbd_device *device, struct drbd_backing_dev *bdev,
sector_t u_size, int assume_peer_has_space)
{
sector_t p_size = device->p_size;
sector_t la_size_sect = bdev->md.la_size_sect;
sector_t m_size;
sector_t size = 0;
m_size = drbd_get_max_capacity(bdev);
if (device->state.conn < C_CONNECTED && assume_peer_has_space) {
drbd_warn(device, "Resize while not connected was forced by the user!\n");
p_size = m_size;
}
if (p_size && m_size) {
size = min_t(sector_t, p_size, m_size);
} else {
if (la_size_sect) {
size = la_size_sect;
if (m_size && m_size < size)
size = m_size;
if (p_size && p_size < size)
size = p_size;
} else {
if (m_size)
size = m_size;
if (p_size)
size = p_size;
}
}
if (size == 0)
drbd_err(device, "Both nodes diskless!\n");
if (u_size) {
if (u_size > size)
drbd_err(device, "Requested disk size is too big (%lu > %lu)\n",
(unsigned long)u_size>>1, (unsigned long)size>>1);
else
size = u_size;
}
return size;
}
static int drbd_check_al_size(struct drbd_device *device, struct disk_conf *dc)
{
struct lru_cache *n, *t;
struct lc_element *e;
unsigned int in_use;
int i;
if (device->act_log &&
device->act_log->nr_elements == dc->al_extents)
return 0;
in_use = 0;
t = device->act_log;
n = lc_create("act_log", drbd_al_ext_cache, AL_UPDATES_PER_TRANSACTION,
dc->al_extents, sizeof(struct lc_element), 0);
if (n == NULL) {
drbd_err(device, "Cannot allocate act_log lru!\n");
return -ENOMEM;
}
spin_lock_irq(&device->al_lock);
if (t) {
for (i = 0; i < t->nr_elements; i++) {
e = lc_element_by_index(t, i);
if (e->refcnt)
drbd_err(device, "refcnt(%d)==%d\n",
e->lc_number, e->refcnt);
in_use += e->refcnt;
}
}
if (!in_use)
device->act_log = n;
spin_unlock_irq(&device->al_lock);
if (in_use) {
drbd_err(device, "Activity log still in use!\n");
lc_destroy(n);
return -EBUSY;
} else {
lc_destroy(t);
}
drbd_md_mark_dirty(device);
return 0;
}
static void blk_queue_discard_granularity(struct request_queue *q, unsigned int granularity)
{
q->limits.discard_granularity = granularity;
}
static unsigned int drbd_max_discard_sectors(struct drbd_connection *connection)
{
if (connection->agreed_features & DRBD_FF_WSAME)
return DRBD_MAX_BBIO_SECTORS;
return AL_EXTENT_SIZE >> 9;
}
static void decide_on_discard_support(struct drbd_device *device,
struct request_queue *q,
struct request_queue *b,
bool discard_zeroes_if_aligned)
{
struct drbd_connection *connection = first_peer_device(device)->connection;
bool can_do = b ? blk_queue_discard(b) : true;
if (can_do && connection->cstate >= C_CONNECTED && !(connection->agreed_features & DRBD_FF_TRIM)) {
can_do = false;
drbd_info(connection, "peer DRBD too old, does not support TRIM: disabling discards\n");
}
if (can_do) {
blk_queue_discard_granularity(q, 512);
q->limits.max_discard_sectors = drbd_max_discard_sectors(connection);
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, q);
q->limits.max_write_zeroes_sectors = drbd_max_discard_sectors(connection);
} else {
queue_flag_clear_unlocked(QUEUE_FLAG_DISCARD, q);
blk_queue_discard_granularity(q, 0);
q->limits.max_discard_sectors = 0;
q->limits.max_write_zeroes_sectors = 0;
}
}
static void fixup_discard_if_not_supported(struct request_queue *q)
{
if (!blk_queue_discard(q)) {
blk_queue_max_discard_sectors(q, 0);
blk_queue_discard_granularity(q, 0);
}
}
static void decide_on_write_same_support(struct drbd_device *device,
struct request_queue *q,
struct request_queue *b, struct o_qlim *o)
{
struct drbd_peer_device *peer_device = first_peer_device(device);
struct drbd_connection *connection = peer_device->connection;
bool can_do = b ? b->limits.max_write_same_sectors : true;
if (can_do && connection->cstate >= C_CONNECTED && !(connection->agreed_features & DRBD_FF_WSAME)) {
can_do = false;
drbd_info(peer_device, "peer does not support WRITE_SAME\n");
}
if (o) {
unsigned int peer_lbs = be32_to_cpu(o->logical_block_size);
unsigned int me_lbs_b = queue_logical_block_size(b);
unsigned int me_lbs = queue_logical_block_size(q);
if (me_lbs_b != me_lbs) {
drbd_warn(device,
"logical block size of local backend does not match (drbd:%u, backend:%u); was this a late attach?\n",
me_lbs, me_lbs_b);
can_do = false;
}
if (me_lbs_b != peer_lbs) {
drbd_warn(peer_device, "logical block sizes do not match (me:%u, peer:%u); this may cause problems.\n",
me_lbs, peer_lbs);
if (can_do) {
drbd_dbg(peer_device, "logical block size mismatch: WRITE_SAME disabled.\n");
can_do = false;
}
me_lbs = max(me_lbs, me_lbs_b);
if (peer_lbs > me_lbs) {
if (device->state.role != R_PRIMARY) {
blk_queue_logical_block_size(q, peer_lbs);
drbd_warn(peer_device, "logical block size set to %u\n", peer_lbs);
} else {
drbd_warn(peer_device,
"current Primary must NOT adjust logical block size (%u -> %u); hope for the best.\n",
me_lbs, peer_lbs);
}
}
}
if (can_do && !o->write_same_capable) {
drbd_dbg(peer_device, "WRITE_SAME disabled (peer device not capable)\n");
can_do = false;
}
}
blk_queue_max_write_same_sectors(q, can_do ? DRBD_MAX_BBIO_SECTORS : 0);
}
static void drbd_setup_queue_param(struct drbd_device *device, struct drbd_backing_dev *bdev,
unsigned int max_bio_size, struct o_qlim *o)
{
struct request_queue * const q = device->rq_queue;
unsigned int max_hw_sectors = max_bio_size >> 9;
unsigned int max_segments = 0;
struct request_queue *b = NULL;
struct disk_conf *dc;
bool discard_zeroes_if_aligned = true;
if (bdev) {
b = bdev->backing_bdev->bd_disk->queue;
max_hw_sectors = min(queue_max_hw_sectors(b), max_bio_size >> 9);
rcu_read_lock();
dc = rcu_dereference(device->ldev->disk_conf);
max_segments = dc->max_bio_bvecs;
discard_zeroes_if_aligned = dc->discard_zeroes_if_aligned;
rcu_read_unlock();
blk_set_stacking_limits(&q->limits);
}
blk_queue_max_hw_sectors(q, max_hw_sectors);
blk_queue_max_segments(q, max_segments ? max_segments : BLK_MAX_SEGMENTS);
blk_queue_segment_boundary(q, PAGE_SIZE-1);
decide_on_discard_support(device, q, b, discard_zeroes_if_aligned);
decide_on_write_same_support(device, q, b, o);
if (b) {
blk_queue_stack_limits(q, b);
if (q->backing_dev_info->ra_pages !=
b->backing_dev_info->ra_pages) {
drbd_info(device, "Adjusting my ra_pages to backing device's (%lu -> %lu)\n",
q->backing_dev_info->ra_pages,
b->backing_dev_info->ra_pages);
q->backing_dev_info->ra_pages =
b->backing_dev_info->ra_pages;
}
}
fixup_discard_if_not_supported(q);
}
void drbd_reconsider_queue_parameters(struct drbd_device *device, struct drbd_backing_dev *bdev, struct o_qlim *o)
{
unsigned int now, new, local, peer;
now = queue_max_hw_sectors(device->rq_queue) << 9;
local = device->local_max_bio_size;
peer = device->peer_max_bio_size;
if (bdev) {
local = queue_max_hw_sectors(bdev->backing_bdev->bd_disk->queue) << 9;
device->local_max_bio_size = local;
}
local = min(local, DRBD_MAX_BIO_SIZE);
if (device->state.conn >= C_WF_REPORT_PARAMS) {
if (first_peer_device(device)->connection->agreed_pro_version < 94)
peer = min(device->peer_max_bio_size, DRBD_MAX_SIZE_H80_PACKET);
else if (first_peer_device(device)->connection->agreed_pro_version == 94)
peer = DRBD_MAX_SIZE_H80_PACKET;
else if (first_peer_device(device)->connection->agreed_pro_version < 100)
peer = DRBD_MAX_BIO_SIZE_P95;
else
peer = DRBD_MAX_BIO_SIZE;
if (peer > device->peer_max_bio_size)
device->peer_max_bio_size = peer;
}
new = min(local, peer);
if (device->state.role == R_PRIMARY && new < now)
drbd_err(device, "ASSERT FAILED new < now; (%u < %u)\n", new, now);
if (new != now)
drbd_info(device, "max BIO size = %u\n", new);
drbd_setup_queue_param(device, bdev, new, o);
}
static void conn_reconfig_start(struct drbd_connection *connection)
{
drbd_thread_start(&connection->worker);
drbd_flush_workqueue(&connection->sender_work);
}
static void conn_reconfig_done(struct drbd_connection *connection)
{
bool stop_threads;
spin_lock_irq(&connection->resource->req_lock);
stop_threads = conn_all_vols_unconf(connection) &&
connection->cstate == C_STANDALONE;
spin_unlock_irq(&connection->resource->req_lock);
if (stop_threads) {
drbd_thread_stop(&connection->receiver);
drbd_thread_stop(&connection->worker);
}
}
static void drbd_suspend_al(struct drbd_device *device)
{
int s = 0;
if (!lc_try_lock(device->act_log)) {
drbd_warn(device, "Failed to lock al in drbd_suspend_al()\n");
return;
}
drbd_al_shrink(device);
spin_lock_irq(&device->resource->req_lock);
if (device->state.conn < C_CONNECTED)
s = !test_and_set_bit(AL_SUSPENDED, &device->flags);
spin_unlock_irq(&device->resource->req_lock);
lc_unlock(device->act_log);
if (s)
drbd_info(device, "Suspended AL updates\n");
}
static bool should_set_defaults(struct genl_info *info)
{
unsigned flags = ((struct drbd_genlmsghdr*)info->userhdr)->flags;
return 0 != (flags & DRBD_GENL_F_SET_DEFAULTS);
}
static unsigned int drbd_al_extents_max(struct drbd_backing_dev *bdev)
{
const unsigned int max_al_nr = DRBD_AL_EXTENTS_MAX;
const unsigned int sufficient_on_disk =
(max_al_nr + AL_CONTEXT_PER_TRANSACTION -1)
/AL_CONTEXT_PER_TRANSACTION;
unsigned int al_size_4k = bdev->md.al_size_4k;
if (al_size_4k > sufficient_on_disk)
return max_al_nr;
return (al_size_4k - 1) * AL_CONTEXT_PER_TRANSACTION;
}
static bool write_ordering_changed(struct disk_conf *a, struct disk_conf *b)
{
return a->disk_barrier != b->disk_barrier ||
a->disk_flushes != b->disk_flushes ||
a->disk_drain != b->disk_drain;
}
static void sanitize_disk_conf(struct drbd_device *device, struct disk_conf *disk_conf,
struct drbd_backing_dev *nbc)
{
struct request_queue * const q = nbc->backing_bdev->bd_disk->queue;
if (disk_conf->al_extents < DRBD_AL_EXTENTS_MIN)
disk_conf->al_extents = DRBD_AL_EXTENTS_MIN;
if (disk_conf->al_extents > drbd_al_extents_max(nbc))
disk_conf->al_extents = drbd_al_extents_max(nbc);
if (!blk_queue_discard(q)) {
if (disk_conf->rs_discard_granularity) {
disk_conf->rs_discard_granularity = 0;
drbd_info(device, "rs_discard_granularity feature disabled\n");
}
}
if (disk_conf->rs_discard_granularity) {
int orig_value = disk_conf->rs_discard_granularity;
int remainder;
if (q->limits.discard_granularity > disk_conf->rs_discard_granularity)
disk_conf->rs_discard_granularity = q->limits.discard_granularity;
remainder = disk_conf->rs_discard_granularity % q->limits.discard_granularity;
disk_conf->rs_discard_granularity += remainder;
if (disk_conf->rs_discard_granularity > q->limits.max_discard_sectors << 9)
disk_conf->rs_discard_granularity = q->limits.max_discard_sectors << 9;
if (disk_conf->rs_discard_granularity != orig_value)
drbd_info(device, "rs_discard_granularity changed to %d\n",
disk_conf->rs_discard_granularity);
}
}
int drbd_adm_disk_opts(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
struct drbd_device *device;
struct disk_conf *new_disk_conf, *old_disk_conf;
struct fifo_buffer *old_plan = NULL, *new_plan = NULL;
int err, fifo_size;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto finish;
device = adm_ctx.device;
mutex_lock(&adm_ctx.resource->adm_mutex);
if (!get_ldev(device)) {
retcode = ERR_NO_DISK;
goto out;
}
new_disk_conf = kmalloc(sizeof(struct disk_conf), GFP_KERNEL);
if (!new_disk_conf) {
retcode = ERR_NOMEM;
goto fail;
}
mutex_lock(&device->resource->conf_update);
old_disk_conf = device->ldev->disk_conf;
*new_disk_conf = *old_disk_conf;
if (should_set_defaults(info))
set_disk_conf_defaults(new_disk_conf);
err = disk_conf_from_attrs_for_change(new_disk_conf, info);
if (err && err != -ENOMSG) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto fail_unlock;
}
if (!expect(new_disk_conf->resync_rate >= 1))
new_disk_conf->resync_rate = 1;
sanitize_disk_conf(device, new_disk_conf, device->ldev);
if (new_disk_conf->c_plan_ahead > DRBD_C_PLAN_AHEAD_MAX)
new_disk_conf->c_plan_ahead = DRBD_C_PLAN_AHEAD_MAX;
fifo_size = (new_disk_conf->c_plan_ahead * 10 * SLEEP_TIME) / HZ;
if (fifo_size != device->rs_plan_s->size) {
new_plan = fifo_alloc(fifo_size);
if (!new_plan) {
drbd_err(device, "kmalloc of fifo_buffer failed");
retcode = ERR_NOMEM;
goto fail_unlock;
}
}
drbd_suspend_io(device);
wait_event(device->al_wait, lc_try_lock(device->act_log));
drbd_al_shrink(device);
err = drbd_check_al_size(device, new_disk_conf);
lc_unlock(device->act_log);
wake_up(&device->al_wait);
drbd_resume_io(device);
if (err) {
retcode = ERR_NOMEM;
goto fail_unlock;
}
lock_all_resources();
retcode = drbd_resync_after_valid(device, new_disk_conf->resync_after);
if (retcode == NO_ERROR) {
rcu_assign_pointer(device->ldev->disk_conf, new_disk_conf);
drbd_resync_after_changed(device);
}
unlock_all_resources();
if (retcode != NO_ERROR)
goto fail_unlock;
if (new_plan) {
old_plan = device->rs_plan_s;
rcu_assign_pointer(device->rs_plan_s, new_plan);
}
mutex_unlock(&device->resource->conf_update);
if (new_disk_conf->al_updates)
device->ldev->md.flags &= ~MDF_AL_DISABLED;
else
device->ldev->md.flags |= MDF_AL_DISABLED;
if (new_disk_conf->md_flushes)
clear_bit(MD_NO_FUA, &device->flags);
else
set_bit(MD_NO_FUA, &device->flags);
if (write_ordering_changed(old_disk_conf, new_disk_conf))
drbd_bump_write_ordering(device->resource, NULL, WO_BDEV_FLUSH);
if (old_disk_conf->discard_zeroes_if_aligned != new_disk_conf->discard_zeroes_if_aligned)
drbd_reconsider_queue_parameters(device, device->ldev, NULL);
drbd_md_sync(device);
if (device->state.conn >= C_CONNECTED) {
struct drbd_peer_device *peer_device;
for_each_peer_device(peer_device, device)
drbd_send_sync_param(peer_device);
}
synchronize_rcu();
kfree(old_disk_conf);
kfree(old_plan);
mod_timer(&device->request_timer, jiffies + HZ);
goto success;
fail_unlock:
mutex_unlock(&device->resource->conf_update);
fail:
kfree(new_disk_conf);
kfree(new_plan);
success:
put_ldev(device);
out:
mutex_unlock(&adm_ctx.resource->adm_mutex);
finish:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static struct block_device *open_backing_dev(struct drbd_device *device,
const char *bdev_path, void *claim_ptr, bool do_bd_link)
{
struct block_device *bdev;
int err = 0;
bdev = blkdev_get_by_path(bdev_path,
FMODE_READ | FMODE_WRITE | FMODE_EXCL, claim_ptr);
if (IS_ERR(bdev)) {
drbd_err(device, "open(\"%s\") failed with %ld\n",
bdev_path, PTR_ERR(bdev));
return bdev;
}
if (!do_bd_link)
return bdev;
err = bd_link_disk_holder(bdev, device->vdisk);
if (err) {
blkdev_put(bdev, FMODE_READ | FMODE_WRITE | FMODE_EXCL);
drbd_err(device, "bd_link_disk_holder(\"%s\", ...) failed with %d\n",
bdev_path, err);
bdev = ERR_PTR(err);
}
return bdev;
}
static int open_backing_devices(struct drbd_device *device,
struct disk_conf *new_disk_conf,
struct drbd_backing_dev *nbc)
{
struct block_device *bdev;
bdev = open_backing_dev(device, new_disk_conf->backing_dev, device, true);
if (IS_ERR(bdev))
return ERR_OPEN_DISK;
nbc->backing_bdev = bdev;
bdev = open_backing_dev(device, new_disk_conf->meta_dev,
(new_disk_conf->meta_dev_idx < 0) ? (void*)device : (void*)drbd_m_holder,
(new_disk_conf->meta_dev_idx != DRBD_MD_INDEX_FLEX_INT &&
new_disk_conf->meta_dev_idx != DRBD_MD_INDEX_INTERNAL));
if (IS_ERR(bdev))
return ERR_OPEN_MD_DISK;
nbc->md_bdev = bdev;
return NO_ERROR;
}
static void close_backing_dev(struct drbd_device *device, struct block_device *bdev,
bool do_bd_unlink)
{
if (!bdev)
return;
if (do_bd_unlink)
bd_unlink_disk_holder(bdev, device->vdisk);
blkdev_put(bdev, FMODE_READ | FMODE_WRITE | FMODE_EXCL);
}
void drbd_backing_dev_free(struct drbd_device *device, struct drbd_backing_dev *ldev)
{
if (ldev == NULL)
return;
close_backing_dev(device, ldev->md_bdev, ldev->md_bdev != ldev->backing_bdev);
close_backing_dev(device, ldev->backing_bdev, true);
kfree(ldev->disk_conf);
kfree(ldev);
}
int drbd_adm_attach(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct drbd_device *device;
struct drbd_peer_device *peer_device;
struct drbd_connection *connection;
int err;
enum drbd_ret_code retcode;
enum determine_dev_size dd;
sector_t max_possible_sectors;
sector_t min_md_device_sectors;
struct drbd_backing_dev *nbc = NULL;
struct disk_conf *new_disk_conf = NULL;
struct lru_cache *resync_lru = NULL;
struct fifo_buffer *new_plan = NULL;
union drbd_state ns, os;
enum drbd_state_rv rv;
struct net_conf *nc;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto finish;
device = adm_ctx.device;
mutex_lock(&adm_ctx.resource->adm_mutex);
peer_device = first_peer_device(device);
connection = peer_device->connection;
conn_reconfig_start(connection);
if (device->state.disk > D_DISKLESS) {
retcode = ERR_DISK_CONFIGURED;
goto fail;
}
wait_event(device->misc_wait, !test_bit(GOING_DISKLESS, &device->flags));
clear_bit(FORCE_DETACH, &device->flags);
clear_bit(WAS_IO_ERROR, &device->flags);
clear_bit(WAS_READ_ERROR, &device->flags);
device->rs_total = 0;
device->rs_failed = 0;
atomic_set(&device->rs_pending_cnt, 0);
nbc = kzalloc(sizeof(struct drbd_backing_dev), GFP_KERNEL);
if (!nbc) {
retcode = ERR_NOMEM;
goto fail;
}
spin_lock_init(&nbc->md.uuid_lock);
new_disk_conf = kzalloc(sizeof(struct disk_conf), GFP_KERNEL);
if (!new_disk_conf) {
retcode = ERR_NOMEM;
goto fail;
}
nbc->disk_conf = new_disk_conf;
set_disk_conf_defaults(new_disk_conf);
err = disk_conf_from_attrs(new_disk_conf, info);
if (err) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto fail;
}
if (new_disk_conf->c_plan_ahead > DRBD_C_PLAN_AHEAD_MAX)
new_disk_conf->c_plan_ahead = DRBD_C_PLAN_AHEAD_MAX;
new_plan = fifo_alloc((new_disk_conf->c_plan_ahead * 10 * SLEEP_TIME) / HZ);
if (!new_plan) {
retcode = ERR_NOMEM;
goto fail;
}
if (new_disk_conf->meta_dev_idx < DRBD_MD_INDEX_FLEX_INT) {
retcode = ERR_MD_IDX_INVALID;
goto fail;
}
rcu_read_lock();
nc = rcu_dereference(connection->net_conf);
if (nc) {
if (new_disk_conf->fencing == FP_STONITH && nc->wire_protocol == DRBD_PROT_A) {
rcu_read_unlock();
retcode = ERR_STONITH_AND_PROT_A;
goto fail;
}
}
rcu_read_unlock();
retcode = open_backing_devices(device, new_disk_conf, nbc);
if (retcode != NO_ERROR)
goto fail;
if ((nbc->backing_bdev == nbc->md_bdev) !=
(new_disk_conf->meta_dev_idx == DRBD_MD_INDEX_INTERNAL ||
new_disk_conf->meta_dev_idx == DRBD_MD_INDEX_FLEX_INT)) {
retcode = ERR_MD_IDX_INVALID;
goto fail;
}
resync_lru = lc_create("resync", drbd_bm_ext_cache,
1, 61, sizeof(struct bm_extent),
offsetof(struct bm_extent, lce));
if (!resync_lru) {
retcode = ERR_NOMEM;
goto fail;
}
retcode = drbd_md_read(device, nbc);
if (retcode != NO_ERROR)
goto fail;
sanitize_disk_conf(device, new_disk_conf, nbc);
if (drbd_get_max_capacity(nbc) < new_disk_conf->disk_size) {
drbd_err(device, "max capacity %llu smaller than disk size %llu\n",
(unsigned long long) drbd_get_max_capacity(nbc),
(unsigned long long) new_disk_conf->disk_size);
retcode = ERR_DISK_TOO_SMALL;
goto fail;
}
if (new_disk_conf->meta_dev_idx < 0) {
max_possible_sectors = DRBD_MAX_SECTORS_FLEX;
min_md_device_sectors = (2<<10);
} else {
max_possible_sectors = DRBD_MAX_SECTORS;
min_md_device_sectors = MD_128MB_SECT * (new_disk_conf->meta_dev_idx + 1);
}
if (drbd_get_capacity(nbc->md_bdev) < min_md_device_sectors) {
retcode = ERR_MD_DISK_TOO_SMALL;
drbd_warn(device, "refusing attach: md-device too small, "
"at least %llu sectors needed for this meta-disk type\n",
(unsigned long long) min_md_device_sectors);
goto fail;
}
if (drbd_get_max_capacity(nbc) <
drbd_get_capacity(device->this_bdev)) {
retcode = ERR_DISK_TOO_SMALL;
goto fail;
}
nbc->known_size = drbd_get_capacity(nbc->backing_bdev);
if (nbc->known_size > max_possible_sectors) {
drbd_warn(device, "==> truncating very big lower level device "
"to currently maximum possible %llu sectors <==\n",
(unsigned long long) max_possible_sectors);
if (new_disk_conf->meta_dev_idx >= 0)
drbd_warn(device, "==>> using internal or flexible "
"meta data may help <<==\n");
}
drbd_suspend_io(device);
wait_event(device->misc_wait, !atomic_read(&device->ap_pending_cnt) || drbd_suspended(device));
drbd_flush_workqueue(&connection->sender_work);
rv = _drbd_request_state(device, NS(disk, D_ATTACHING), CS_VERBOSE);
retcode = rv;
drbd_resume_io(device);
if (rv < SS_SUCCESS)
goto fail;
if (!get_ldev_if_state(device, D_ATTACHING))
goto force_diskless;
if (!device->bitmap) {
if (drbd_bm_init(device)) {
retcode = ERR_NOMEM;
goto force_diskless_dec;
}
}
if (device->state.conn < C_CONNECTED &&
device->state.role == R_PRIMARY && device->ed_uuid &&
(device->ed_uuid & ~((u64)1)) != (nbc->md.uuid[UI_CURRENT] & ~((u64)1))) {
drbd_err(device, "Can only attach to data with current UUID=%016llX\n",
(unsigned long long)device->ed_uuid);
retcode = ERR_DATA_NOT_CURRENT;
goto force_diskless_dec;
}
if (drbd_check_al_size(device, new_disk_conf)) {
retcode = ERR_NOMEM;
goto force_diskless_dec;
}
if (drbd_md_test_flag(nbc, MDF_CONSISTENT) &&
drbd_new_dev_size(device, nbc, nbc->disk_conf->disk_size, 0) < nbc->md.la_size_sect) {
drbd_warn(device, "refusing to truncate a consistent device\n");
retcode = ERR_DISK_TOO_SMALL;
goto force_diskless_dec;
}
lock_all_resources();
retcode = drbd_resync_after_valid(device, new_disk_conf->resync_after);
if (retcode != NO_ERROR) {
unlock_all_resources();
goto force_diskless_dec;
}
if (new_disk_conf->md_flushes)
clear_bit(MD_NO_FUA, &device->flags);
else
set_bit(MD_NO_FUA, &device->flags);
D_ASSERT(device, device->ldev == NULL);
device->ldev = nbc;
device->resync = resync_lru;
device->rs_plan_s = new_plan;
nbc = NULL;
resync_lru = NULL;
new_disk_conf = NULL;
new_plan = NULL;
drbd_resync_after_changed(device);
drbd_bump_write_ordering(device->resource, device->ldev, WO_BDEV_FLUSH);
unlock_all_resources();
if (drbd_md_test_flag(device->ldev, MDF_CRASHED_PRIMARY))
set_bit(CRASHED_PRIMARY, &device->flags);
else
clear_bit(CRASHED_PRIMARY, &device->flags);
if (drbd_md_test_flag(device->ldev, MDF_PRIMARY_IND) &&
!(device->state.role == R_PRIMARY && device->resource->susp_nod))
set_bit(CRASHED_PRIMARY, &device->flags);
device->send_cnt = 0;
device->recv_cnt = 0;
device->read_cnt = 0;
device->writ_cnt = 0;
drbd_reconsider_queue_parameters(device, device->ldev, NULL);
clear_bit(USE_DEGR_WFC_T, &device->flags);
if (device->state.role != R_PRIMARY &&
drbd_md_test_flag(device->ldev, MDF_PRIMARY_IND) &&
!drbd_md_test_flag(device->ldev, MDF_CONNECTED_IND))
set_bit(USE_DEGR_WFC_T, &device->flags);
dd = drbd_determine_dev_size(device, 0, NULL);
if (dd <= DS_ERROR) {
retcode = ERR_NOMEM_BITMAP;
goto force_diskless_dec;
} else if (dd == DS_GREW)
set_bit(RESYNC_AFTER_NEG, &device->flags);
if (drbd_md_test_flag(device->ldev, MDF_FULL_SYNC) ||
(test_bit(CRASHED_PRIMARY, &device->flags) &&
drbd_md_test_flag(device->ldev, MDF_AL_DISABLED))) {
drbd_info(device, "Assuming that all blocks are out of sync "
"(aka FullSync)\n");
if (drbd_bitmap_io(device, &drbd_bmio_set_n_write,
"set_n_write from attaching", BM_LOCKED_MASK)) {
retcode = ERR_IO_MD_DISK;
goto force_diskless_dec;
}
} else {
if (drbd_bitmap_io(device, &drbd_bm_read,
"read from attaching", BM_LOCKED_MASK)) {
retcode = ERR_IO_MD_DISK;
goto force_diskless_dec;
}
}
if (_drbd_bm_total_weight(device) == drbd_bm_bits(device))
drbd_suspend_al(device);
spin_lock_irq(&device->resource->req_lock);
os = drbd_read_state(device);
ns = os;
if (drbd_md_test_flag(device->ldev, MDF_CONSISTENT)) {
if (drbd_md_test_flag(device->ldev, MDF_WAS_UP_TO_DATE))
ns.disk = D_CONSISTENT;
else
ns.disk = D_OUTDATED;
} else {
ns.disk = D_INCONSISTENT;
}
if (drbd_md_test_flag(device->ldev, MDF_PEER_OUT_DATED))
ns.pdsk = D_OUTDATED;
rcu_read_lock();
if (ns.disk == D_CONSISTENT &&
(ns.pdsk == D_OUTDATED || rcu_dereference(device->ldev->disk_conf)->fencing == FP_DONT_CARE))
ns.disk = D_UP_TO_DATE;
if (rcu_dereference(device->ldev->disk_conf)->al_updates)
device->ldev->md.flags &= ~MDF_AL_DISABLED;
else
device->ldev->md.flags |= MDF_AL_DISABLED;
rcu_read_unlock();
if (device->state.conn == C_CONNECTED) {
device->new_state_tmp.i = ns.i;
ns.i = os.i;
ns.disk = D_NEGOTIATING;
kfree(device->p_uuid);
device->p_uuid = NULL;
}
rv = _drbd_set_state(device, ns, CS_VERBOSE, NULL);
spin_unlock_irq(&device->resource->req_lock);
if (rv < SS_SUCCESS)
goto force_diskless_dec;
mod_timer(&device->request_timer, jiffies + HZ);
if (device->state.role == R_PRIMARY)
device->ldev->md.uuid[UI_CURRENT] |= (u64)1;
else
device->ldev->md.uuid[UI_CURRENT] &= ~(u64)1;
drbd_md_mark_dirty(device);
drbd_md_sync(device);
kobject_uevent(&disk_to_dev(device->vdisk)->kobj, KOBJ_CHANGE);
put_ldev(device);
conn_reconfig_done(connection);
mutex_unlock(&adm_ctx.resource->adm_mutex);
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
force_diskless_dec:
put_ldev(device);
force_diskless:
drbd_force_state(device, NS(disk, D_DISKLESS));
drbd_md_sync(device);
fail:
conn_reconfig_done(connection);
if (nbc) {
close_backing_dev(device, nbc->md_bdev, nbc->md_bdev != nbc->backing_bdev);
close_backing_dev(device, nbc->backing_bdev, true);
kfree(nbc);
}
kfree(new_disk_conf);
lc_destroy(resync_lru);
kfree(new_plan);
mutex_unlock(&adm_ctx.resource->adm_mutex);
finish:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static int adm_detach(struct drbd_device *device, int force)
{
enum drbd_state_rv retcode;
void *buffer;
int ret;
if (force) {
set_bit(FORCE_DETACH, &device->flags);
drbd_force_state(device, NS(disk, D_FAILED));
retcode = SS_SUCCESS;
goto out;
}
drbd_suspend_io(device);
buffer = drbd_md_get_buffer(device, __func__);
if (buffer) {
retcode = drbd_request_state(device, NS(disk, D_FAILED));
drbd_md_put_buffer(device);
} else
retcode = SS_NOTHING_TO_DO;
drbd_resume_io(device);
ret = wait_event_interruptible(device->misc_wait,
device->state.disk != D_FAILED);
if ((int)retcode == (int)SS_IS_DISKLESS)
retcode = SS_NOTHING_TO_DO;
if (ret)
retcode = ERR_INTR;
out:
return retcode;
}
int drbd_adm_detach(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
struct detach_parms parms = { };
int err;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
if (info->attrs[DRBD_NLA_DETACH_PARMS]) {
err = detach_parms_from_attrs(&parms, info);
if (err) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto out;
}
}
mutex_lock(&adm_ctx.resource->adm_mutex);
retcode = adm_detach(adm_ctx.device, parms.force_detach);
mutex_unlock(&adm_ctx.resource->adm_mutex);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static bool conn_resync_running(struct drbd_connection *connection)
{
struct drbd_peer_device *peer_device;
bool rv = false;
int vnr;
rcu_read_lock();
idr_for_each_entry(&connection->peer_devices, peer_device, vnr) {
struct drbd_device *device = peer_device->device;
if (device->state.conn == C_SYNC_SOURCE ||
device->state.conn == C_SYNC_TARGET ||
device->state.conn == C_PAUSED_SYNC_S ||
device->state.conn == C_PAUSED_SYNC_T) {
rv = true;
break;
}
}
rcu_read_unlock();
return rv;
}
static bool conn_ov_running(struct drbd_connection *connection)
{
struct drbd_peer_device *peer_device;
bool rv = false;
int vnr;
rcu_read_lock();
idr_for_each_entry(&connection->peer_devices, peer_device, vnr) {
struct drbd_device *device = peer_device->device;
if (device->state.conn == C_VERIFY_S ||
device->state.conn == C_VERIFY_T) {
rv = true;
break;
}
}
rcu_read_unlock();
return rv;
}
static enum drbd_ret_code
_check_net_options(struct drbd_connection *connection, struct net_conf *old_net_conf, struct net_conf *new_net_conf)
{
struct drbd_peer_device *peer_device;
int i;
if (old_net_conf && connection->cstate == C_WF_REPORT_PARAMS && connection->agreed_pro_version < 100) {
if (new_net_conf->wire_protocol != old_net_conf->wire_protocol)
return ERR_NEED_APV_100;
if (new_net_conf->two_primaries != old_net_conf->two_primaries)
return ERR_NEED_APV_100;
if (strcmp(new_net_conf->integrity_alg, old_net_conf->integrity_alg))
return ERR_NEED_APV_100;
}
if (!new_net_conf->two_primaries &&
conn_highest_role(connection) == R_PRIMARY &&
conn_highest_peer(connection) == R_PRIMARY)
return ERR_NEED_ALLOW_TWO_PRI;
if (new_net_conf->two_primaries &&
(new_net_conf->wire_protocol != DRBD_PROT_C))
return ERR_NOT_PROTO_C;
idr_for_each_entry(&connection->peer_devices, peer_device, i) {
struct drbd_device *device = peer_device->device;
if (get_ldev(device)) {
enum drbd_fencing_p fp = rcu_dereference(device->ldev->disk_conf)->fencing;
put_ldev(device);
if (new_net_conf->wire_protocol == DRBD_PROT_A && fp == FP_STONITH)
return ERR_STONITH_AND_PROT_A;
}
if (device->state.role == R_PRIMARY && new_net_conf->discard_my_data)
return ERR_DISCARD_IMPOSSIBLE;
}
if (new_net_conf->on_congestion != OC_BLOCK && new_net_conf->wire_protocol != DRBD_PROT_A)
return ERR_CONG_NOT_PROTO_A;
return NO_ERROR;
}
static enum drbd_ret_code
check_net_options(struct drbd_connection *connection, struct net_conf *new_net_conf)
{
enum drbd_ret_code rv;
struct drbd_peer_device *peer_device;
int i;
rcu_read_lock();
rv = _check_net_options(connection, rcu_dereference(connection->net_conf), new_net_conf);
rcu_read_unlock();
idr_for_each_entry(&connection->peer_devices, peer_device, i) {
struct drbd_device *device = peer_device->device;
if (!device->bitmap) {
if (drbd_bm_init(device))
return ERR_NOMEM;
}
}
return rv;
}
static int
alloc_shash(struct crypto_shash **tfm, char *tfm_name, int err_alg)
{
if (!tfm_name[0])
return NO_ERROR;
*tfm = crypto_alloc_shash(tfm_name, 0, 0);
if (IS_ERR(*tfm)) {
*tfm = NULL;
return err_alg;
}
return NO_ERROR;
}
static int
alloc_ahash(struct crypto_ahash **tfm, char *tfm_name, int err_alg)
{
if (!tfm_name[0])
return NO_ERROR;
*tfm = crypto_alloc_ahash(tfm_name, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(*tfm)) {
*tfm = NULL;
return err_alg;
}
return NO_ERROR;
}
static enum drbd_ret_code
alloc_crypto(struct crypto *crypto, struct net_conf *new_net_conf)
{
char hmac_name[CRYPTO_MAX_ALG_NAME];
enum drbd_ret_code rv;
rv = alloc_ahash(&crypto->csums_tfm, new_net_conf->csums_alg,
ERR_CSUMS_ALG);
if (rv != NO_ERROR)
return rv;
rv = alloc_ahash(&crypto->verify_tfm, new_net_conf->verify_alg,
ERR_VERIFY_ALG);
if (rv != NO_ERROR)
return rv;
rv = alloc_ahash(&crypto->integrity_tfm, new_net_conf->integrity_alg,
ERR_INTEGRITY_ALG);
if (rv != NO_ERROR)
return rv;
if (new_net_conf->cram_hmac_alg[0] != 0) {
snprintf(hmac_name, CRYPTO_MAX_ALG_NAME, "hmac(%s)",
new_net_conf->cram_hmac_alg);
rv = alloc_shash(&crypto->cram_hmac_tfm, hmac_name,
ERR_AUTH_ALG);
}
return rv;
}
static void free_crypto(struct crypto *crypto)
{
crypto_free_shash(crypto->cram_hmac_tfm);
crypto_free_ahash(crypto->integrity_tfm);
crypto_free_ahash(crypto->csums_tfm);
crypto_free_ahash(crypto->verify_tfm);
}
int drbd_adm_net_opts(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
struct drbd_connection *connection;
struct net_conf *old_net_conf, *new_net_conf = NULL;
int err;
int ovr;
int rsr;
struct crypto crypto = { };
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_CONNECTION);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto finish;
connection = adm_ctx.connection;
mutex_lock(&adm_ctx.resource->adm_mutex);
new_net_conf = kzalloc(sizeof(struct net_conf), GFP_KERNEL);
if (!new_net_conf) {
retcode = ERR_NOMEM;
goto out;
}
conn_reconfig_start(connection);
mutex_lock(&connection->data.mutex);
mutex_lock(&connection->resource->conf_update);
old_net_conf = connection->net_conf;
if (!old_net_conf) {
drbd_msg_put_info(adm_ctx.reply_skb, "net conf missing, try connect");
retcode = ERR_INVALID_REQUEST;
goto fail;
}
*new_net_conf = *old_net_conf;
if (should_set_defaults(info))
set_net_conf_defaults(new_net_conf);
err = net_conf_from_attrs_for_change(new_net_conf, info);
if (err && err != -ENOMSG) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto fail;
}
retcode = check_net_options(connection, new_net_conf);
if (retcode != NO_ERROR)
goto fail;
rsr = conn_resync_running(connection);
if (rsr && strcmp(new_net_conf->csums_alg, old_net_conf->csums_alg)) {
retcode = ERR_CSUMS_RESYNC_RUNNING;
goto fail;
}
ovr = conn_ov_running(connection);
if (ovr && strcmp(new_net_conf->verify_alg, old_net_conf->verify_alg)) {
retcode = ERR_VERIFY_RUNNING;
goto fail;
}
retcode = alloc_crypto(&crypto, new_net_conf);
if (retcode != NO_ERROR)
goto fail;
rcu_assign_pointer(connection->net_conf, new_net_conf);
if (!rsr) {
crypto_free_ahash(connection->csums_tfm);
connection->csums_tfm = crypto.csums_tfm;
crypto.csums_tfm = NULL;
}
if (!ovr) {
crypto_free_ahash(connection->verify_tfm);
connection->verify_tfm = crypto.verify_tfm;
crypto.verify_tfm = NULL;
}
crypto_free_ahash(connection->integrity_tfm);
connection->integrity_tfm = crypto.integrity_tfm;
if (connection->cstate >= C_WF_REPORT_PARAMS && connection->agreed_pro_version >= 100)
__drbd_send_protocol(connection, P_PROTOCOL_UPDATE);
crypto_free_shash(connection->cram_hmac_tfm);
connection->cram_hmac_tfm = crypto.cram_hmac_tfm;
mutex_unlock(&connection->resource->conf_update);
mutex_unlock(&connection->data.mutex);
synchronize_rcu();
kfree(old_net_conf);
if (connection->cstate >= C_WF_REPORT_PARAMS) {
struct drbd_peer_device *peer_device;
int vnr;
idr_for_each_entry(&connection->peer_devices, peer_device, vnr)
drbd_send_sync_param(peer_device);
}
goto done;
fail:
mutex_unlock(&connection->resource->conf_update);
mutex_unlock(&connection->data.mutex);
free_crypto(&crypto);
kfree(new_net_conf);
done:
conn_reconfig_done(connection);
out:
mutex_unlock(&adm_ctx.resource->adm_mutex);
finish:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static void connection_to_info(struct connection_info *info,
struct drbd_connection *connection)
{
info->conn_connection_state = connection->cstate;
info->conn_role = conn_highest_peer(connection);
}
static void peer_device_to_info(struct peer_device_info *info,
struct drbd_peer_device *peer_device)
{
struct drbd_device *device = peer_device->device;
info->peer_repl_state =
max_t(enum drbd_conns, C_WF_REPORT_PARAMS, device->state.conn);
info->peer_disk_state = device->state.pdsk;
info->peer_resync_susp_user = device->state.user_isp;
info->peer_resync_susp_peer = device->state.peer_isp;
info->peer_resync_susp_dependency = device->state.aftr_isp;
}
int drbd_adm_connect(struct sk_buff *skb, struct genl_info *info)
{
struct connection_info connection_info;
enum drbd_notification_type flags;
unsigned int peer_devices = 0;
struct drbd_config_context adm_ctx;
struct drbd_peer_device *peer_device;
struct net_conf *old_net_conf, *new_net_conf = NULL;
struct crypto crypto = { };
struct drbd_resource *resource;
struct drbd_connection *connection;
enum drbd_ret_code retcode;
int i;
int err;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_RESOURCE);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
if (!(adm_ctx.my_addr && adm_ctx.peer_addr)) {
drbd_msg_put_info(adm_ctx.reply_skb, "connection endpoint(s) missing");
retcode = ERR_INVALID_REQUEST;
goto out;
}
for_each_resource(resource, &drbd_resources) {
for_each_connection(connection, resource) {
if (nla_len(adm_ctx.my_addr) == connection->my_addr_len &&
!memcmp(nla_data(adm_ctx.my_addr), &connection->my_addr,
connection->my_addr_len)) {
retcode = ERR_LOCAL_ADDR;
goto out;
}
if (nla_len(adm_ctx.peer_addr) == connection->peer_addr_len &&
!memcmp(nla_data(adm_ctx.peer_addr), &connection->peer_addr,
connection->peer_addr_len)) {
retcode = ERR_PEER_ADDR;
goto out;
}
}
}
mutex_lock(&adm_ctx.resource->adm_mutex);
connection = first_connection(adm_ctx.resource);
conn_reconfig_start(connection);
if (connection->cstate > C_STANDALONE) {
retcode = ERR_NET_CONFIGURED;
goto fail;
}
new_net_conf = kzalloc(sizeof(*new_net_conf), GFP_KERNEL);
if (!new_net_conf) {
retcode = ERR_NOMEM;
goto fail;
}
set_net_conf_defaults(new_net_conf);
err = net_conf_from_attrs(new_net_conf, info);
if (err && err != -ENOMSG) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto fail;
}
retcode = check_net_options(connection, new_net_conf);
if (retcode != NO_ERROR)
goto fail;
retcode = alloc_crypto(&crypto, new_net_conf);
if (retcode != NO_ERROR)
goto fail;
((char *)new_net_conf->shared_secret)[SHARED_SECRET_MAX-1] = 0;
drbd_flush_workqueue(&connection->sender_work);
mutex_lock(&adm_ctx.resource->conf_update);
old_net_conf = connection->net_conf;
if (old_net_conf) {
retcode = ERR_NET_CONFIGURED;
mutex_unlock(&adm_ctx.resource->conf_update);
goto fail;
}
rcu_assign_pointer(connection->net_conf, new_net_conf);
conn_free_crypto(connection);
connection->cram_hmac_tfm = crypto.cram_hmac_tfm;
connection->integrity_tfm = crypto.integrity_tfm;
connection->csums_tfm = crypto.csums_tfm;
connection->verify_tfm = crypto.verify_tfm;
connection->my_addr_len = nla_len(adm_ctx.my_addr);
memcpy(&connection->my_addr, nla_data(adm_ctx.my_addr), connection->my_addr_len);
connection->peer_addr_len = nla_len(adm_ctx.peer_addr);
memcpy(&connection->peer_addr, nla_data(adm_ctx.peer_addr), connection->peer_addr_len);
idr_for_each_entry(&connection->peer_devices, peer_device, i) {
peer_devices++;
}
connection_to_info(&connection_info, connection);
flags = (peer_devices--) ? NOTIFY_CONTINUES : 0;
mutex_lock(&notification_mutex);
notify_connection_state(NULL, 0, connection, &connection_info, NOTIFY_CREATE | flags);
idr_for_each_entry(&connection->peer_devices, peer_device, i) {
struct peer_device_info peer_device_info;
peer_device_to_info(&peer_device_info, peer_device);
flags = (peer_devices--) ? NOTIFY_CONTINUES : 0;
notify_peer_device_state(NULL, 0, peer_device, &peer_device_info, NOTIFY_CREATE | flags);
}
mutex_unlock(&notification_mutex);
mutex_unlock(&adm_ctx.resource->conf_update);
rcu_read_lock();
idr_for_each_entry(&connection->peer_devices, peer_device, i) {
struct drbd_device *device = peer_device->device;
device->send_cnt = 0;
device->recv_cnt = 0;
}
rcu_read_unlock();
retcode = conn_request_state(connection, NS(conn, C_UNCONNECTED), CS_VERBOSE);
conn_reconfig_done(connection);
mutex_unlock(&adm_ctx.resource->adm_mutex);
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
fail:
free_crypto(&crypto);
kfree(new_net_conf);
conn_reconfig_done(connection);
mutex_unlock(&adm_ctx.resource->adm_mutex);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static enum drbd_state_rv conn_try_disconnect(struct drbd_connection *connection, bool force)
{
enum drbd_state_rv rv;
rv = conn_request_state(connection, NS(conn, C_DISCONNECTING),
force ? CS_HARD : 0);
switch (rv) {
case SS_NOTHING_TO_DO:
break;
case SS_ALREADY_STANDALONE:
return SS_SUCCESS;
case SS_PRIMARY_NOP:
rv = conn_request_state(connection, NS2(conn, C_DISCONNECTING, pdsk, D_OUTDATED), 0);
if (rv == SS_OUTDATE_WO_CONN)
rv = conn_request_state(connection, NS(conn, C_DISCONNECTING), CS_VERBOSE);
break;
case SS_CW_FAILED_BY_PEER:
rv = conn_request_state(connection, NS2(conn, C_DISCONNECTING,
disk, D_OUTDATED), 0);
if (rv == SS_IS_DISKLESS || rv == SS_LOWER_THAN_OUTDATED) {
rv = conn_request_state(connection, NS(conn, C_DISCONNECTING),
CS_HARD);
}
break;
default:;
}
if (rv >= SS_SUCCESS) {
enum drbd_state_rv rv2;
drbd_thread_stop(&connection->receiver);
rv2 = conn_request_state(connection, NS(conn, C_STANDALONE),
CS_VERBOSE | CS_HARD);
if (rv2 < SS_SUCCESS)
drbd_err(connection,
"unexpected rv2=%d in conn_try_disconnect()\n",
rv2);
}
return rv;
}
int drbd_adm_disconnect(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct disconnect_parms parms;
struct drbd_connection *connection;
enum drbd_state_rv rv;
enum drbd_ret_code retcode;
int err;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_CONNECTION);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto fail;
connection = adm_ctx.connection;
memset(&parms, 0, sizeof(parms));
if (info->attrs[DRBD_NLA_DISCONNECT_PARMS]) {
err = disconnect_parms_from_attrs(&parms, info);
if (err) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto fail;
}
}
mutex_lock(&adm_ctx.resource->adm_mutex);
rv = conn_try_disconnect(connection, parms.force_disconnect);
if (rv < SS_SUCCESS)
retcode = rv;
else
retcode = NO_ERROR;
mutex_unlock(&adm_ctx.resource->adm_mutex);
fail:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
void resync_after_online_grow(struct drbd_device *device)
{
int iass;
drbd_info(device, "Resync of new storage after online grow\n");
if (device->state.role != device->state.peer)
iass = (device->state.role == R_PRIMARY);
else
iass = test_bit(RESOLVE_CONFLICTS, &first_peer_device(device)->connection->flags);
if (iass)
drbd_start_resync(device, C_SYNC_SOURCE);
else
_drbd_request_state(device, NS(conn, C_WF_SYNC_UUID), CS_VERBOSE + CS_SERIALIZE);
}
int drbd_adm_resize(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct disk_conf *old_disk_conf, *new_disk_conf = NULL;
struct resize_parms rs;
struct drbd_device *device;
enum drbd_ret_code retcode;
enum determine_dev_size dd;
bool change_al_layout = false;
enum dds_flags ddsf;
sector_t u_size;
int err;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto finish;
mutex_lock(&adm_ctx.resource->adm_mutex);
device = adm_ctx.device;
if (!get_ldev(device)) {
retcode = ERR_NO_DISK;
goto fail;
}
memset(&rs, 0, sizeof(struct resize_parms));
rs.al_stripes = device->ldev->md.al_stripes;
rs.al_stripe_size = device->ldev->md.al_stripe_size_4k * 4;
if (info->attrs[DRBD_NLA_RESIZE_PARMS]) {
err = resize_parms_from_attrs(&rs, info);
if (err) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto fail_ldev;
}
}
if (device->state.conn > C_CONNECTED) {
retcode = ERR_RESIZE_RESYNC;
goto fail_ldev;
}
if (device->state.role == R_SECONDARY &&
device->state.peer == R_SECONDARY) {
retcode = ERR_NO_PRIMARY;
goto fail_ldev;
}
if (rs.no_resync && first_peer_device(device)->connection->agreed_pro_version < 93) {
retcode = ERR_NEED_APV_93;
goto fail_ldev;
}
rcu_read_lock();
u_size = rcu_dereference(device->ldev->disk_conf)->disk_size;
rcu_read_unlock();
if (u_size != (sector_t)rs.resize_size) {
new_disk_conf = kmalloc(sizeof(struct disk_conf), GFP_KERNEL);
if (!new_disk_conf) {
retcode = ERR_NOMEM;
goto fail_ldev;
}
}
if (device->ldev->md.al_stripes != rs.al_stripes ||
device->ldev->md.al_stripe_size_4k != rs.al_stripe_size / 4) {
u32 al_size_k = rs.al_stripes * rs.al_stripe_size;
if (al_size_k > (16 * 1024 * 1024)) {
retcode = ERR_MD_LAYOUT_TOO_BIG;
goto fail_ldev;
}
if (al_size_k < MD_32kB_SECT/2) {
retcode = ERR_MD_LAYOUT_TOO_SMALL;
goto fail_ldev;
}
if (device->state.conn != C_CONNECTED && !rs.resize_force) {
retcode = ERR_MD_LAYOUT_CONNECTED;
goto fail_ldev;
}
change_al_layout = true;
}
if (device->ldev->known_size != drbd_get_capacity(device->ldev->backing_bdev))
device->ldev->known_size = drbd_get_capacity(device->ldev->backing_bdev);
if (new_disk_conf) {
mutex_lock(&device->resource->conf_update);
old_disk_conf = device->ldev->disk_conf;
*new_disk_conf = *old_disk_conf;
new_disk_conf->disk_size = (sector_t)rs.resize_size;
rcu_assign_pointer(device->ldev->disk_conf, new_disk_conf);
mutex_unlock(&device->resource->conf_update);
synchronize_rcu();
kfree(old_disk_conf);
new_disk_conf = NULL;
}
ddsf = (rs.resize_force ? DDSF_FORCED : 0) | (rs.no_resync ? DDSF_NO_RESYNC : 0);
dd = drbd_determine_dev_size(device, ddsf, change_al_layout ? &rs : NULL);
drbd_md_sync(device);
put_ldev(device);
if (dd == DS_ERROR) {
retcode = ERR_NOMEM_BITMAP;
goto fail;
} else if (dd == DS_ERROR_SPACE_MD) {
retcode = ERR_MD_LAYOUT_NO_FIT;
goto fail;
} else if (dd == DS_ERROR_SHRINK) {
retcode = ERR_IMPLICIT_SHRINK;
goto fail;
}
if (device->state.conn == C_CONNECTED) {
if (dd == DS_GREW)
set_bit(RESIZE_PENDING, &device->flags);
drbd_send_uuids(first_peer_device(device));
drbd_send_sizes(first_peer_device(device), 1, ddsf);
}
fail:
mutex_unlock(&adm_ctx.resource->adm_mutex);
finish:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
fail_ldev:
put_ldev(device);
kfree(new_disk_conf);
goto fail;
}
int drbd_adm_resource_opts(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
struct res_opts res_opts;
int err;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_RESOURCE);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto fail;
res_opts = adm_ctx.resource->res_opts;
if (should_set_defaults(info))
set_res_opts_defaults(&res_opts);
err = res_opts_from_attrs(&res_opts, info);
if (err && err != -ENOMSG) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto fail;
}
mutex_lock(&adm_ctx.resource->adm_mutex);
err = set_resource_options(adm_ctx.resource, &res_opts);
if (err) {
retcode = ERR_INVALID_REQUEST;
if (err == -ENOMEM)
retcode = ERR_NOMEM;
}
mutex_unlock(&adm_ctx.resource->adm_mutex);
fail:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
int drbd_adm_invalidate(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct drbd_device *device;
int retcode;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
device = adm_ctx.device;
if (!get_ldev(device)) {
retcode = ERR_NO_DISK;
goto out;
}
mutex_lock(&adm_ctx.resource->adm_mutex);
drbd_suspend_io(device);
wait_event(device->misc_wait, !test_bit(BITMAP_IO, &device->flags));
drbd_flush_workqueue(&first_peer_device(device)->connection->sender_work);
if (device->state.conn == C_STANDALONE && device->state.role == R_SECONDARY) {
retcode = drbd_request_state(device, NS(disk, D_INCONSISTENT));
if (retcode >= SS_SUCCESS) {
if (drbd_bitmap_io(device, &drbd_bmio_set_n_write,
"set_n_write from invalidate", BM_LOCKED_MASK))
retcode = ERR_IO_MD_DISK;
}
} else
retcode = drbd_request_state(device, NS(conn, C_STARTING_SYNC_T));
drbd_resume_io(device);
mutex_unlock(&adm_ctx.resource->adm_mutex);
put_ldev(device);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static int drbd_adm_simple_request_state(struct sk_buff *skb, struct genl_info *info,
union drbd_state mask, union drbd_state val)
{
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
mutex_lock(&adm_ctx.resource->adm_mutex);
retcode = drbd_request_state(adm_ctx.device, mask, val);
mutex_unlock(&adm_ctx.resource->adm_mutex);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static int drbd_bmio_set_susp_al(struct drbd_device *device) __must_hold(local)
{
int rv;
rv = drbd_bmio_set_n_write(device);
drbd_suspend_al(device);
return rv;
}
int drbd_adm_invalidate_peer(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
int retcode;
struct drbd_device *device;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
device = adm_ctx.device;
if (!get_ldev(device)) {
retcode = ERR_NO_DISK;
goto out;
}
mutex_lock(&adm_ctx.resource->adm_mutex);
drbd_suspend_io(device);
wait_event(device->misc_wait, !test_bit(BITMAP_IO, &device->flags));
drbd_flush_workqueue(&first_peer_device(device)->connection->sender_work);
if (device->state.conn == C_STANDALONE && device->state.role == R_PRIMARY) {
retcode = drbd_request_state(device, NS(pdsk, D_INCONSISTENT));
if (retcode >= SS_SUCCESS) {
if (drbd_bitmap_io(device, &drbd_bmio_set_susp_al,
"set_n_write from invalidate_peer",
BM_LOCKED_SET_ALLOWED))
retcode = ERR_IO_MD_DISK;
}
} else
retcode = drbd_request_state(device, NS(conn, C_STARTING_SYNC_S));
drbd_resume_io(device);
mutex_unlock(&adm_ctx.resource->adm_mutex);
put_ldev(device);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
int drbd_adm_pause_sync(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
mutex_lock(&adm_ctx.resource->adm_mutex);
if (drbd_request_state(adm_ctx.device, NS(user_isp, 1)) == SS_NOTHING_TO_DO)
retcode = ERR_PAUSE_IS_SET;
mutex_unlock(&adm_ctx.resource->adm_mutex);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
int drbd_adm_resume_sync(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
union drbd_dev_state s;
enum drbd_ret_code retcode;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
mutex_lock(&adm_ctx.resource->adm_mutex);
if (drbd_request_state(adm_ctx.device, NS(user_isp, 0)) == SS_NOTHING_TO_DO) {
s = adm_ctx.device->state;
if (s.conn == C_PAUSED_SYNC_S || s.conn == C_PAUSED_SYNC_T) {
retcode = s.aftr_isp ? ERR_PIC_AFTER_DEP :
s.peer_isp ? ERR_PIC_PEER_DEP : ERR_PAUSE_IS_CLEAR;
} else {
retcode = ERR_PAUSE_IS_CLEAR;
}
}
mutex_unlock(&adm_ctx.resource->adm_mutex);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
int drbd_adm_suspend_io(struct sk_buff *skb, struct genl_info *info)
{
return drbd_adm_simple_request_state(skb, info, NS(susp, 1));
}
int drbd_adm_resume_io(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct drbd_device *device;
int retcode;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
mutex_lock(&adm_ctx.resource->adm_mutex);
device = adm_ctx.device;
if (test_bit(NEW_CUR_UUID, &device->flags)) {
if (get_ldev_if_state(device, D_ATTACHING)) {
drbd_uuid_new_current(device);
put_ldev(device);
} else {
u64 val;
get_random_bytes(&val, sizeof(u64));
drbd_set_ed_uuid(device, val);
drbd_warn(device, "Resumed without access to data; please tear down before attempting to re-configure.\n");
}
clear_bit(NEW_CUR_UUID, &device->flags);
}
drbd_suspend_io(device);
retcode = drbd_request_state(device, NS3(susp, 0, susp_nod, 0, susp_fen, 0));
if (retcode == SS_SUCCESS) {
if (device->state.conn < C_CONNECTED)
tl_clear(first_peer_device(device)->connection);
if (device->state.disk == D_DISKLESS || device->state.disk == D_FAILED)
tl_restart(first_peer_device(device)->connection, FAIL_FROZEN_DISK_IO);
}
drbd_resume_io(device);
mutex_unlock(&adm_ctx.resource->adm_mutex);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
int drbd_adm_outdate(struct sk_buff *skb, struct genl_info *info)
{
return drbd_adm_simple_request_state(skb, info, NS(disk, D_OUTDATED));
}
static int nla_put_drbd_cfg_context(struct sk_buff *skb,
struct drbd_resource *resource,
struct drbd_connection *connection,
struct drbd_device *device)
{
struct nlattr *nla;
nla = nla_nest_start(skb, DRBD_NLA_CFG_CONTEXT);
if (!nla)
goto nla_put_failure;
if (device &&
nla_put_u32(skb, T_ctx_volume, device->vnr))
goto nla_put_failure;
if (nla_put_string(skb, T_ctx_resource_name, resource->name))
goto nla_put_failure;
if (connection) {
if (connection->my_addr_len &&
nla_put(skb, T_ctx_my_addr, connection->my_addr_len, &connection->my_addr))
goto nla_put_failure;
if (connection->peer_addr_len &&
nla_put(skb, T_ctx_peer_addr, connection->peer_addr_len, &connection->peer_addr))
goto nla_put_failure;
}
nla_nest_end(skb, nla);
return 0;
nla_put_failure:
if (nla)
nla_nest_cancel(skb, nla);
return -EMSGSIZE;
}
static struct nlattr *find_cfg_context_attr(const struct nlmsghdr *nlh, int attr)
{
const unsigned hdrlen = GENL_HDRLEN + GENL_MAGIC_FAMILY_HDRSZ;
const int maxtype = ARRAY_SIZE(drbd_cfg_context_nl_policy) - 1;
struct nlattr *nla;
nla = nla_find(nlmsg_attrdata(nlh, hdrlen), nlmsg_attrlen(nlh, hdrlen),
DRBD_NLA_CFG_CONTEXT);
if (!nla)
return NULL;
return drbd_nla_find_nested(maxtype, nla, __nla_type(attr));
}
int drbd_adm_dump_resources(struct sk_buff *skb, struct netlink_callback *cb)
{
struct drbd_genlmsghdr *dh;
struct drbd_resource *resource;
struct resource_info resource_info;
struct resource_statistics resource_statistics;
int err;
rcu_read_lock();
if (cb->args[0]) {
for_each_resource_rcu(resource, &drbd_resources)
if (resource == (struct drbd_resource *)cb->args[0])
goto found_resource;
err = 0;
goto out;
}
resource = list_entry(&drbd_resources,
struct drbd_resource, resources);
found_resource:
list_for_each_entry_continue_rcu(resource, &drbd_resources, resources) {
goto put_result;
}
err = 0;
goto out;
put_result:
dh = genlmsg_put(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, &drbd_genl_family,
NLM_F_MULTI, DRBD_ADM_GET_RESOURCES);
err = -ENOMEM;
if (!dh)
goto out;
dh->minor = -1U;
dh->ret_code = NO_ERROR;
err = nla_put_drbd_cfg_context(skb, resource, NULL, NULL);
if (err)
goto out;
err = res_opts_to_skb(skb, &resource->res_opts, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
resource_to_info(&resource_info, resource);
err = resource_info_to_skb(skb, &resource_info, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
resource_statistics.res_stat_write_ordering = resource->write_ordering;
err = resource_statistics_to_skb(skb, &resource_statistics, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
cb->args[0] = (long)resource;
genlmsg_end(skb, dh);
err = 0;
out:
rcu_read_unlock();
if (err)
return err;
return skb->len;
}
static void device_to_statistics(struct device_statistics *s,
struct drbd_device *device)
{
memset(s, 0, sizeof(*s));
s->dev_upper_blocked = !may_inc_ap_bio(device);
if (get_ldev(device)) {
struct drbd_md *md = &device->ldev->md;
u64 *history_uuids = (u64 *)s->history_uuids;
struct request_queue *q;
int n;
spin_lock_irq(&md->uuid_lock);
s->dev_current_uuid = md->uuid[UI_CURRENT];
BUILD_BUG_ON(sizeof(s->history_uuids) < UI_HISTORY_END - UI_HISTORY_START + 1);
for (n = 0; n < UI_HISTORY_END - UI_HISTORY_START + 1; n++)
history_uuids[n] = md->uuid[UI_HISTORY_START + n];
for (; n < HISTORY_UUIDS; n++)
history_uuids[n] = 0;
s->history_uuids_len = HISTORY_UUIDS;
spin_unlock_irq(&md->uuid_lock);
s->dev_disk_flags = md->flags;
q = bdev_get_queue(device->ldev->backing_bdev);
s->dev_lower_blocked =
bdi_congested(q->backing_dev_info,
(1 << WB_async_congested) |
(1 << WB_sync_congested));
put_ldev(device);
}
s->dev_size = drbd_get_capacity(device->this_bdev);
s->dev_read = device->read_cnt;
s->dev_write = device->writ_cnt;
s->dev_al_writes = device->al_writ_cnt;
s->dev_bm_writes = device->bm_writ_cnt;
s->dev_upper_pending = atomic_read(&device->ap_bio_cnt);
s->dev_lower_pending = atomic_read(&device->local_cnt);
s->dev_al_suspended = test_bit(AL_SUSPENDED, &device->flags);
s->dev_exposed_data_uuid = device->ed_uuid;
}
static int put_resource_in_arg0(struct netlink_callback *cb, int holder_nr)
{
if (cb->args[0]) {
struct drbd_resource *resource =
(struct drbd_resource *)cb->args[0];
kref_put(&resource->kref, drbd_destroy_resource);
}
return 0;
}
int drbd_adm_dump_devices_done(struct netlink_callback *cb) {
return put_resource_in_arg0(cb, 7);
}
int drbd_adm_dump_devices(struct sk_buff *skb, struct netlink_callback *cb)
{
struct nlattr *resource_filter;
struct drbd_resource *resource;
struct drbd_device *uninitialized_var(device);
int minor, err, retcode;
struct drbd_genlmsghdr *dh;
struct device_info device_info;
struct device_statistics device_statistics;
struct idr *idr_to_search;
resource = (struct drbd_resource *)cb->args[0];
if (!cb->args[0] && !cb->args[1]) {
resource_filter = find_cfg_context_attr(cb->nlh, T_ctx_resource_name);
if (resource_filter) {
retcode = ERR_RES_NOT_KNOWN;
resource = drbd_find_resource(nla_data(resource_filter));
if (!resource)
goto put_result;
cb->args[0] = (long)resource;
}
}
rcu_read_lock();
minor = cb->args[1];
idr_to_search = resource ? &resource->devices : &drbd_devices;
device = idr_get_next(idr_to_search, &minor);
if (!device) {
err = 0;
goto out;
}
idr_for_each_entry_continue(idr_to_search, device, minor) {
retcode = NO_ERROR;
goto put_result;
}
err = 0;
goto out;
put_result:
dh = genlmsg_put(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, &drbd_genl_family,
NLM_F_MULTI, DRBD_ADM_GET_DEVICES);
err = -ENOMEM;
if (!dh)
goto out;
dh->ret_code = retcode;
dh->minor = -1U;
if (retcode == NO_ERROR) {
dh->minor = device->minor;
err = nla_put_drbd_cfg_context(skb, device->resource, NULL, device);
if (err)
goto out;
if (get_ldev(device)) {
struct disk_conf *disk_conf =
rcu_dereference(device->ldev->disk_conf);
err = disk_conf_to_skb(skb, disk_conf, !capable(CAP_SYS_ADMIN));
put_ldev(device);
if (err)
goto out;
}
device_to_info(&device_info, device);
err = device_info_to_skb(skb, &device_info, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
device_to_statistics(&device_statistics, device);
err = device_statistics_to_skb(skb, &device_statistics, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
cb->args[1] = minor + 1;
}
genlmsg_end(skb, dh);
err = 0;
out:
rcu_read_unlock();
if (err)
return err;
return skb->len;
}
int drbd_adm_dump_connections_done(struct netlink_callback *cb)
{
return put_resource_in_arg0(cb, 6);
}
int drbd_adm_dump_connections(struct sk_buff *skb, struct netlink_callback *cb)
{
struct nlattr *resource_filter;
struct drbd_resource *resource = NULL, *next_resource;
struct drbd_connection *uninitialized_var(connection);
int err = 0, retcode;
struct drbd_genlmsghdr *dh;
struct connection_info connection_info;
struct connection_statistics connection_statistics;
rcu_read_lock();
resource = (struct drbd_resource *)cb->args[0];
if (!cb->args[0]) {
resource_filter = find_cfg_context_attr(cb->nlh, T_ctx_resource_name);
if (resource_filter) {
retcode = ERR_RES_NOT_KNOWN;
resource = drbd_find_resource(nla_data(resource_filter));
if (!resource)
goto put_result;
cb->args[0] = (long)resource;
cb->args[1] = SINGLE_RESOURCE;
}
}
if (!resource) {
if (list_empty(&drbd_resources))
goto out;
resource = list_first_entry(&drbd_resources, struct drbd_resource, resources);
kref_get(&resource->kref);
cb->args[0] = (long)resource;
cb->args[1] = ITERATE_RESOURCES;
}
next_resource:
rcu_read_unlock();
mutex_lock(&resource->conf_update);
rcu_read_lock();
if (cb->args[2]) {
for_each_connection_rcu(connection, resource)
if (connection == (struct drbd_connection *)cb->args[2])
goto found_connection;
goto no_more_connections;
}
connection = list_entry(&resource->connections, struct drbd_connection, connections);
found_connection:
list_for_each_entry_continue_rcu(connection, &resource->connections, connections) {
if (!has_net_conf(connection))
continue;
retcode = NO_ERROR;
goto put_result;
}
no_more_connections:
if (cb->args[1] == ITERATE_RESOURCES) {
for_each_resource_rcu(next_resource, &drbd_resources) {
if (next_resource == resource)
goto found_resource;
}
}
goto out;
found_resource:
list_for_each_entry_continue_rcu(next_resource, &drbd_resources, resources) {
mutex_unlock(&resource->conf_update);
kref_put(&resource->kref, drbd_destroy_resource);
resource = next_resource;
kref_get(&resource->kref);
cb->args[0] = (long)resource;
cb->args[2] = 0;
goto next_resource;
}
goto out;
put_result:
dh = genlmsg_put(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, &drbd_genl_family,
NLM_F_MULTI, DRBD_ADM_GET_CONNECTIONS);
err = -ENOMEM;
if (!dh)
goto out;
dh->ret_code = retcode;
dh->minor = -1U;
if (retcode == NO_ERROR) {
struct net_conf *net_conf;
err = nla_put_drbd_cfg_context(skb, resource, connection, NULL);
if (err)
goto out;
net_conf = rcu_dereference(connection->net_conf);
if (net_conf) {
err = net_conf_to_skb(skb, net_conf, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
}
connection_to_info(&connection_info, connection);
err = connection_info_to_skb(skb, &connection_info, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
connection_statistics.conn_congested = test_bit(NET_CONGESTED, &connection->flags);
err = connection_statistics_to_skb(skb, &connection_statistics, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
cb->args[2] = (long)connection;
}
genlmsg_end(skb, dh);
err = 0;
out:
rcu_read_unlock();
if (resource)
mutex_unlock(&resource->conf_update);
if (err)
return err;
return skb->len;
}
static void peer_device_to_statistics(struct peer_device_statistics *s,
struct drbd_peer_device *peer_device)
{
struct drbd_device *device = peer_device->device;
memset(s, 0, sizeof(*s));
s->peer_dev_received = device->recv_cnt;
s->peer_dev_sent = device->send_cnt;
s->peer_dev_pending = atomic_read(&device->ap_pending_cnt) +
atomic_read(&device->rs_pending_cnt);
s->peer_dev_unacked = atomic_read(&device->unacked_cnt);
s->peer_dev_out_of_sync = drbd_bm_total_weight(device) << (BM_BLOCK_SHIFT - 9);
s->peer_dev_resync_failed = device->rs_failed << (BM_BLOCK_SHIFT - 9);
if (get_ldev(device)) {
struct drbd_md *md = &device->ldev->md;
spin_lock_irq(&md->uuid_lock);
s->peer_dev_bitmap_uuid = md->uuid[UI_BITMAP];
spin_unlock_irq(&md->uuid_lock);
s->peer_dev_flags =
(drbd_md_test_flag(device->ldev, MDF_CONNECTED_IND) ?
MDF_PEER_CONNECTED : 0) +
(drbd_md_test_flag(device->ldev, MDF_CONSISTENT) &&
!drbd_md_test_flag(device->ldev, MDF_WAS_UP_TO_DATE) ?
MDF_PEER_OUTDATED : 0) +
(drbd_md_test_flag(device->ldev, MDF_FULL_SYNC) ?
MDF_PEER_FULL_SYNC : 0);
put_ldev(device);
}
}
int drbd_adm_dump_peer_devices_done(struct netlink_callback *cb)
{
return put_resource_in_arg0(cb, 9);
}
int drbd_adm_dump_peer_devices(struct sk_buff *skb, struct netlink_callback *cb)
{
struct nlattr *resource_filter;
struct drbd_resource *resource;
struct drbd_device *uninitialized_var(device);
struct drbd_peer_device *peer_device = NULL;
int minor, err, retcode;
struct drbd_genlmsghdr *dh;
struct idr *idr_to_search;
resource = (struct drbd_resource *)cb->args[0];
if (!cb->args[0] && !cb->args[1]) {
resource_filter = find_cfg_context_attr(cb->nlh, T_ctx_resource_name);
if (resource_filter) {
retcode = ERR_RES_NOT_KNOWN;
resource = drbd_find_resource(nla_data(resource_filter));
if (!resource)
goto put_result;
}
cb->args[0] = (long)resource;
}
rcu_read_lock();
minor = cb->args[1];
idr_to_search = resource ? &resource->devices : &drbd_devices;
device = idr_find(idr_to_search, minor);
if (!device) {
next_device:
minor++;
cb->args[2] = 0;
device = idr_get_next(idr_to_search, &minor);
if (!device) {
err = 0;
goto out;
}
}
if (cb->args[2]) {
for_each_peer_device(peer_device, device)
if (peer_device == (struct drbd_peer_device *)cb->args[2])
goto found_peer_device;
goto next_device;
}
peer_device = list_entry(&device->peer_devices, struct drbd_peer_device, peer_devices);
found_peer_device:
list_for_each_entry_continue_rcu(peer_device, &device->peer_devices, peer_devices) {
if (!has_net_conf(peer_device->connection))
continue;
retcode = NO_ERROR;
goto put_result;
}
goto next_device;
put_result:
dh = genlmsg_put(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, &drbd_genl_family,
NLM_F_MULTI, DRBD_ADM_GET_PEER_DEVICES);
err = -ENOMEM;
if (!dh)
goto out;
dh->ret_code = retcode;
dh->minor = -1U;
if (retcode == NO_ERROR) {
struct peer_device_info peer_device_info;
struct peer_device_statistics peer_device_statistics;
dh->minor = minor;
err = nla_put_drbd_cfg_context(skb, device->resource, peer_device->connection, device);
if (err)
goto out;
peer_device_to_info(&peer_device_info, peer_device);
err = peer_device_info_to_skb(skb, &peer_device_info, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
peer_device_to_statistics(&peer_device_statistics, peer_device);
err = peer_device_statistics_to_skb(skb, &peer_device_statistics, !capable(CAP_SYS_ADMIN));
if (err)
goto out;
cb->args[1] = minor;
cb->args[2] = (long)peer_device;
}
genlmsg_end(skb, dh);
err = 0;
out:
rcu_read_unlock();
if (err)
return err;
return skb->len;
}
static struct drbd_connection *the_only_connection(struct drbd_resource *resource)
{
struct list_head *connections = &resource->connections;
if (list_empty(connections) || connections->next->next != connections)
return NULL;
return list_first_entry(&resource->connections, struct drbd_connection, connections);
}
static int nla_put_status_info(struct sk_buff *skb, struct drbd_device *device,
const struct sib_info *sib)
{
struct drbd_resource *resource = device->resource;
struct state_info *si = NULL;
struct nlattr *nla;
int got_ldev;
int err = 0;
int exclude_sensitive;
exclude_sensitive = sib || !capable(CAP_SYS_ADMIN);
got_ldev = get_ldev(device);
if (nla_put_drbd_cfg_context(skb, resource, the_only_connection(resource), device))
goto nla_put_failure;
if (res_opts_to_skb(skb, &device->resource->res_opts, exclude_sensitive))
goto nla_put_failure;
rcu_read_lock();
if (got_ldev) {
struct disk_conf *disk_conf;
disk_conf = rcu_dereference(device->ldev->disk_conf);
err = disk_conf_to_skb(skb, disk_conf, exclude_sensitive);
}
if (!err) {
struct net_conf *nc;
nc = rcu_dereference(first_peer_device(device)->connection->net_conf);
if (nc)
err = net_conf_to_skb(skb, nc, exclude_sensitive);
}
rcu_read_unlock();
if (err)
goto nla_put_failure;
nla = nla_nest_start(skb, DRBD_NLA_STATE_INFO);
if (!nla)
goto nla_put_failure;
if (nla_put_u32(skb, T_sib_reason, sib ? sib->sib_reason : SIB_GET_STATUS_REPLY) ||
nla_put_u32(skb, T_current_state, device->state.i) ||
nla_put_u64_0pad(skb, T_ed_uuid, device->ed_uuid) ||
nla_put_u64_0pad(skb, T_capacity,
drbd_get_capacity(device->this_bdev)) ||
nla_put_u64_0pad(skb, T_send_cnt, device->send_cnt) ||
nla_put_u64_0pad(skb, T_recv_cnt, device->recv_cnt) ||
nla_put_u64_0pad(skb, T_read_cnt, device->read_cnt) ||
nla_put_u64_0pad(skb, T_writ_cnt, device->writ_cnt) ||
nla_put_u64_0pad(skb, T_al_writ_cnt, device->al_writ_cnt) ||
nla_put_u64_0pad(skb, T_bm_writ_cnt, device->bm_writ_cnt) ||
nla_put_u32(skb, T_ap_bio_cnt, atomic_read(&device->ap_bio_cnt)) ||
nla_put_u32(skb, T_ap_pending_cnt, atomic_read(&device->ap_pending_cnt)) ||
nla_put_u32(skb, T_rs_pending_cnt, atomic_read(&device->rs_pending_cnt)))
goto nla_put_failure;
if (got_ldev) {
int err;
spin_lock_irq(&device->ldev->md.uuid_lock);
err = nla_put(skb, T_uuids, sizeof(si->uuids), device->ldev->md.uuid);
spin_unlock_irq(&device->ldev->md.uuid_lock);
if (err)
goto nla_put_failure;
if (nla_put_u32(skb, T_disk_flags, device->ldev->md.flags) ||
nla_put_u64_0pad(skb, T_bits_total, drbd_bm_bits(device)) ||
nla_put_u64_0pad(skb, T_bits_oos,
drbd_bm_total_weight(device)))
goto nla_put_failure;
if (C_SYNC_SOURCE <= device->state.conn &&
C_PAUSED_SYNC_T >= device->state.conn) {
if (nla_put_u64_0pad(skb, T_bits_rs_total,
device->rs_total) ||
nla_put_u64_0pad(skb, T_bits_rs_failed,
device->rs_failed))
goto nla_put_failure;
}
}
if (sib) {
switch(sib->sib_reason) {
case SIB_SYNC_PROGRESS:
case SIB_GET_STATUS_REPLY:
break;
case SIB_STATE_CHANGE:
if (nla_put_u32(skb, T_prev_state, sib->os.i) ||
nla_put_u32(skb, T_new_state, sib->ns.i))
goto nla_put_failure;
break;
case SIB_HELPER_POST:
if (nla_put_u32(skb, T_helper_exit_code,
sib->helper_exit_code))
goto nla_put_failure;
case SIB_HELPER_PRE:
if (nla_put_string(skb, T_helper, sib->helper_name))
goto nla_put_failure;
break;
}
}
nla_nest_end(skb, nla);
if (0)
nla_put_failure:
err = -EMSGSIZE;
if (got_ldev)
put_ldev(device);
return err;
}
int drbd_adm_get_status(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
int err;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
err = nla_put_status_info(adm_ctx.reply_skb, adm_ctx.device, NULL);
if (err) {
nlmsg_free(adm_ctx.reply_skb);
return err;
}
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static int get_one_status(struct sk_buff *skb, struct netlink_callback *cb)
{
struct drbd_device *device;
struct drbd_genlmsghdr *dh;
struct drbd_resource *pos = (struct drbd_resource *)cb->args[0];
struct drbd_resource *resource = NULL;
struct drbd_resource *tmp;
unsigned volume = cb->args[1];
rcu_read_lock();
for_each_resource_rcu(tmp, &drbd_resources) {
if (pos == NULL) {
pos = tmp;
resource = pos;
break;
}
if (tmp == pos) {
resource = pos;
break;
}
}
if (resource) {
next_resource:
device = idr_get_next(&resource->devices, &volume);
if (!device) {
pos = list_entry_rcu(resource->resources.next,
struct drbd_resource, resources);
if (volume != 0) {
if (&pos->resources == &drbd_resources || cb->args[2])
goto out;
volume = 0;
resource = pos;
goto next_resource;
}
}
dh = genlmsg_put(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, &drbd_genl_family,
NLM_F_MULTI, DRBD_ADM_GET_STATUS);
if (!dh)
goto out;
if (!device) {
struct drbd_connection *connection;
dh->minor = -1U;
dh->ret_code = NO_ERROR;
connection = the_only_connection(resource);
if (nla_put_drbd_cfg_context(skb, resource, connection, NULL))
goto cancel;
if (connection) {
struct net_conf *nc;
nc = rcu_dereference(connection->net_conf);
if (nc && net_conf_to_skb(skb, nc, 1) != 0)
goto cancel;
}
goto done;
}
D_ASSERT(device, device->vnr == volume);
D_ASSERT(device, device->resource == resource);
dh->minor = device_to_minor(device);
dh->ret_code = NO_ERROR;
if (nla_put_status_info(skb, device, NULL)) {
cancel:
genlmsg_cancel(skb, dh);
goto out;
}
done:
genlmsg_end(skb, dh);
}
out:
rcu_read_unlock();
cb->args[0] = (long)pos;
cb->args[1] = (pos == resource) ? volume + 1 : 0;
return skb->len;
}
int drbd_adm_get_status_all(struct sk_buff *skb, struct netlink_callback *cb)
{
const unsigned hdrlen = GENL_HDRLEN + GENL_MAGIC_FAMILY_HDRSZ;
struct nlattr *nla;
const char *resource_name;
struct drbd_resource *resource;
int maxtype;
if (cb->args[0]) {
if (cb->args[2] && cb->args[2] != cb->args[0])
return 0;
goto dump;
}
nla = nla_find(nlmsg_attrdata(cb->nlh, hdrlen),
nlmsg_attrlen(cb->nlh, hdrlen),
DRBD_NLA_CFG_CONTEXT);
if (!nla)
goto dump;
maxtype = ARRAY_SIZE(drbd_cfg_context_nl_policy) - 1;
nla = drbd_nla_find_nested(maxtype, nla, __nla_type(T_ctx_resource_name));
if (IS_ERR(nla))
return PTR_ERR(nla);
if (!nla)
return -EINVAL;
resource_name = nla_data(nla);
if (!*resource_name)
return -ENODEV;
resource = drbd_find_resource(resource_name);
if (!resource)
return -ENODEV;
kref_put(&resource->kref, drbd_destroy_resource);
cb->args[0] = (long)resource;
cb->args[2] = (long)resource;
dump:
return get_one_status(skb, cb);
}
int drbd_adm_get_timeout_type(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
struct timeout_parms tp;
int err;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
tp.timeout_type =
adm_ctx.device->state.pdsk == D_OUTDATED ? UT_PEER_OUTDATED :
test_bit(USE_DEGR_WFC_T, &adm_ctx.device->flags) ? UT_DEGRADED :
UT_DEFAULT;
err = timeout_parms_to_priv_skb(adm_ctx.reply_skb, &tp);
if (err) {
nlmsg_free(adm_ctx.reply_skb);
return err;
}
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
int drbd_adm_start_ov(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct drbd_device *device;
enum drbd_ret_code retcode;
struct start_ov_parms parms;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
device = adm_ctx.device;
parms.ov_start_sector = device->ov_start_sector;
parms.ov_stop_sector = ULLONG_MAX;
if (info->attrs[DRBD_NLA_START_OV_PARMS]) {
int err = start_ov_parms_from_attrs(&parms, info);
if (err) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto out;
}
}
mutex_lock(&adm_ctx.resource->adm_mutex);
device->ov_start_sector = parms.ov_start_sector & ~(BM_SECT_PER_BIT-1);
device->ov_stop_sector = parms.ov_stop_sector;
drbd_suspend_io(device);
wait_event(device->misc_wait, !test_bit(BITMAP_IO, &device->flags));
retcode = drbd_request_state(device, NS(conn, C_VERIFY_S));
drbd_resume_io(device);
mutex_unlock(&adm_ctx.resource->adm_mutex);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
int drbd_adm_new_c_uuid(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct drbd_device *device;
enum drbd_ret_code retcode;
int skip_initial_sync = 0;
int err;
struct new_c_uuid_parms args;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out_nolock;
device = adm_ctx.device;
memset(&args, 0, sizeof(args));
if (info->attrs[DRBD_NLA_NEW_C_UUID_PARMS]) {
err = new_c_uuid_parms_from_attrs(&args, info);
if (err) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto out_nolock;
}
}
mutex_lock(&adm_ctx.resource->adm_mutex);
mutex_lock(device->state_mutex);
if (!get_ldev(device)) {
retcode = ERR_NO_DISK;
goto out;
}
if (device->state.conn == C_CONNECTED &&
first_peer_device(device)->connection->agreed_pro_version >= 90 &&
device->ldev->md.uuid[UI_CURRENT] == UUID_JUST_CREATED && args.clear_bm) {
drbd_info(device, "Preparing to skip initial sync\n");
skip_initial_sync = 1;
} else if (device->state.conn != C_STANDALONE) {
retcode = ERR_CONNECTED;
goto out_dec;
}
drbd_uuid_set(device, UI_BITMAP, 0);
drbd_uuid_new_current(device);
if (args.clear_bm) {
err = drbd_bitmap_io(device, &drbd_bmio_clear_n_write,
"clear_n_write from new_c_uuid", BM_LOCKED_MASK);
if (err) {
drbd_err(device, "Writing bitmap failed with %d\n", err);
retcode = ERR_IO_MD_DISK;
}
if (skip_initial_sync) {
drbd_send_uuids_skip_initial_sync(first_peer_device(device));
_drbd_uuid_set(device, UI_BITMAP, 0);
drbd_print_uuids(device, "cleared bitmap UUID");
spin_lock_irq(&device->resource->req_lock);
_drbd_set_state(_NS2(device, disk, D_UP_TO_DATE, pdsk, D_UP_TO_DATE),
CS_VERBOSE, NULL);
spin_unlock_irq(&device->resource->req_lock);
}
}
drbd_md_sync(device);
out_dec:
put_ldev(device);
out:
mutex_unlock(device->state_mutex);
mutex_unlock(&adm_ctx.resource->adm_mutex);
out_nolock:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static enum drbd_ret_code
drbd_check_resource_name(struct drbd_config_context *adm_ctx)
{
const char *name = adm_ctx->resource_name;
if (!name || !name[0]) {
drbd_msg_put_info(adm_ctx->reply_skb, "resource name missing");
return ERR_MANDATORY_TAG;
}
if (strchr(name, '/')) {
drbd_msg_put_info(adm_ctx->reply_skb, "invalid resource name");
return ERR_INVALID_REQUEST;
}
return NO_ERROR;
}
static void resource_to_info(struct resource_info *info,
struct drbd_resource *resource)
{
info->res_role = conn_highest_role(first_connection(resource));
info->res_susp = resource->susp;
info->res_susp_nod = resource->susp_nod;
info->res_susp_fen = resource->susp_fen;
}
int drbd_adm_new_resource(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_connection *connection;
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
struct res_opts res_opts;
int err;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, 0);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
set_res_opts_defaults(&res_opts);
err = res_opts_from_attrs(&res_opts, info);
if (err && err != -ENOMSG) {
retcode = ERR_MANDATORY_TAG;
drbd_msg_put_info(adm_ctx.reply_skb, from_attrs_err_to_txt(err));
goto out;
}
retcode = drbd_check_resource_name(&adm_ctx);
if (retcode != NO_ERROR)
goto out;
if (adm_ctx.resource) {
if (info->nlhdr->nlmsg_flags & NLM_F_EXCL) {
retcode = ERR_INVALID_REQUEST;
drbd_msg_put_info(adm_ctx.reply_skb, "resource exists");
}
goto out;
}
mutex_lock(&resources_mutex);
connection = conn_create(adm_ctx.resource_name, &res_opts);
mutex_unlock(&resources_mutex);
if (connection) {
struct resource_info resource_info;
mutex_lock(&notification_mutex);
resource_to_info(&resource_info, connection->resource);
notify_resource_state(NULL, 0, connection->resource,
&resource_info, NOTIFY_CREATE);
mutex_unlock(&notification_mutex);
} else
retcode = ERR_NOMEM;
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static void device_to_info(struct device_info *info,
struct drbd_device *device)
{
info->dev_disk_state = device->state.disk;
}
int drbd_adm_new_minor(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct drbd_genlmsghdr *dh = info->userhdr;
enum drbd_ret_code retcode;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_RESOURCE);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
if (dh->minor > MINORMASK) {
drbd_msg_put_info(adm_ctx.reply_skb, "requested minor out of range");
retcode = ERR_INVALID_REQUEST;
goto out;
}
if (adm_ctx.volume > DRBD_VOLUME_MAX) {
drbd_msg_put_info(adm_ctx.reply_skb, "requested volume id out of range");
retcode = ERR_INVALID_REQUEST;
goto out;
}
if (adm_ctx.device) {
if (info->nlhdr->nlmsg_flags & NLM_F_EXCL)
retcode = ERR_MINOR_OR_VOLUME_EXISTS;
goto out;
}
mutex_lock(&adm_ctx.resource->adm_mutex);
retcode = drbd_create_device(&adm_ctx, dh->minor);
if (retcode == NO_ERROR) {
struct drbd_device *device;
struct drbd_peer_device *peer_device;
struct device_info info;
unsigned int peer_devices = 0;
enum drbd_notification_type flags;
device = minor_to_device(dh->minor);
for_each_peer_device(peer_device, device) {
if (!has_net_conf(peer_device->connection))
continue;
peer_devices++;
}
device_to_info(&info, device);
mutex_lock(&notification_mutex);
flags = (peer_devices--) ? NOTIFY_CONTINUES : 0;
notify_device_state(NULL, 0, device, &info, NOTIFY_CREATE | flags);
for_each_peer_device(peer_device, device) {
struct peer_device_info peer_device_info;
if (!has_net_conf(peer_device->connection))
continue;
peer_device_to_info(&peer_device_info, peer_device);
flags = (peer_devices--) ? NOTIFY_CONTINUES : 0;
notify_peer_device_state(NULL, 0, peer_device, &peer_device_info,
NOTIFY_CREATE | flags);
}
mutex_unlock(&notification_mutex);
}
mutex_unlock(&adm_ctx.resource->adm_mutex);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static enum drbd_ret_code adm_del_minor(struct drbd_device *device)
{
struct drbd_peer_device *peer_device;
if (device->state.disk == D_DISKLESS &&
device->state.role == R_SECONDARY) {
struct drbd_connection *connection =
first_connection(device->resource);
_drbd_request_state(device, NS(conn, C_WF_REPORT_PARAMS),
CS_VERBOSE + CS_WAIT_COMPLETE);
if (get_t_state(&connection->worker) == RUNNING)
drbd_flush_workqueue(&connection->sender_work);
mutex_lock(&notification_mutex);
for_each_peer_device(peer_device, device) {
if (!has_net_conf(peer_device->connection))
continue;
notify_peer_device_state(NULL, 0, peer_device, NULL,
NOTIFY_DESTROY | NOTIFY_CONTINUES);
}
notify_device_state(NULL, 0, device, NULL, NOTIFY_DESTROY);
mutex_unlock(&notification_mutex);
drbd_delete_device(device);
return NO_ERROR;
} else
return ERR_MINOR_CONFIGURED;
}
int drbd_adm_del_minor(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
enum drbd_ret_code retcode;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_MINOR);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto out;
mutex_lock(&adm_ctx.resource->adm_mutex);
retcode = adm_del_minor(adm_ctx.device);
mutex_unlock(&adm_ctx.resource->adm_mutex);
out:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
static int adm_del_resource(struct drbd_resource *resource)
{
struct drbd_connection *connection;
for_each_connection(connection, resource) {
if (connection->cstate > C_STANDALONE)
return ERR_NET_CONFIGURED;
}
if (!idr_is_empty(&resource->devices))
return ERR_RES_IN_USE;
mutex_lock(&notification_mutex);
notify_resource_state(NULL, 0, resource, NULL, NOTIFY_DESTROY);
mutex_unlock(&notification_mutex);
mutex_lock(&resources_mutex);
list_del_rcu(&resource->resources);
mutex_unlock(&resources_mutex);
list_for_each_entry(connection, &resource->connections, connections)
drbd_thread_stop(&connection->worker);
synchronize_rcu();
drbd_free_resource(resource);
return NO_ERROR;
}
int drbd_adm_down(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct drbd_resource *resource;
struct drbd_connection *connection;
struct drbd_device *device;
int retcode;
unsigned i;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_RESOURCE);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto finish;
resource = adm_ctx.resource;
mutex_lock(&resource->adm_mutex);
for_each_connection(connection, resource) {
struct drbd_peer_device *peer_device;
idr_for_each_entry(&connection->peer_devices, peer_device, i) {
retcode = drbd_set_role(peer_device->device, R_SECONDARY, 0);
if (retcode < SS_SUCCESS) {
drbd_msg_put_info(adm_ctx.reply_skb, "failed to demote");
goto out;
}
}
retcode = conn_try_disconnect(connection, 0);
if (retcode < SS_SUCCESS) {
drbd_msg_put_info(adm_ctx.reply_skb, "failed to disconnect");
goto out;
}
}
idr_for_each_entry(&resource->devices, device, i) {
retcode = adm_detach(device, 0);
if (retcode < SS_SUCCESS || retcode > NO_ERROR) {
drbd_msg_put_info(adm_ctx.reply_skb, "failed to detach");
goto out;
}
}
idr_for_each_entry(&resource->devices, device, i) {
retcode = adm_del_minor(device);
if (retcode != NO_ERROR) {
drbd_msg_put_info(adm_ctx.reply_skb, "failed to delete volume");
goto out;
}
}
retcode = adm_del_resource(resource);
out:
mutex_unlock(&resource->adm_mutex);
finish:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
int drbd_adm_del_resource(struct sk_buff *skb, struct genl_info *info)
{
struct drbd_config_context adm_ctx;
struct drbd_resource *resource;
enum drbd_ret_code retcode;
retcode = drbd_adm_prepare(&adm_ctx, skb, info, DRBD_ADM_NEED_RESOURCE);
if (!adm_ctx.reply_skb)
return retcode;
if (retcode != NO_ERROR)
goto finish;
resource = adm_ctx.resource;
mutex_lock(&resource->adm_mutex);
retcode = adm_del_resource(resource);
mutex_unlock(&resource->adm_mutex);
finish:
drbd_adm_finish(&adm_ctx, info, retcode);
return 0;
}
void drbd_bcast_event(struct drbd_device *device, const struct sib_info *sib)
{
struct sk_buff *msg;
struct drbd_genlmsghdr *d_out;
unsigned seq;
int err = -ENOMEM;
seq = atomic_inc_return(&drbd_genl_seq);
msg = genlmsg_new(NLMSG_GOODSIZE, GFP_NOIO);
if (!msg)
goto failed;
err = -EMSGSIZE;
d_out = genlmsg_put(msg, 0, seq, &drbd_genl_family, 0, DRBD_EVENT);
if (!d_out)
goto nla_put_failure;
d_out->minor = device_to_minor(device);
d_out->ret_code = NO_ERROR;
if (nla_put_status_info(msg, device, sib))
goto nla_put_failure;
genlmsg_end(msg, d_out);
err = drbd_genl_multicast_events(msg, GFP_NOWAIT);
if (err && err != -ESRCH)
goto failed;
return;
nla_put_failure:
nlmsg_free(msg);
failed:
drbd_err(device, "Error %d while broadcasting event. "
"Event seq:%u sib_reason:%u\n",
err, seq, sib->sib_reason);
}
static int nla_put_notification_header(struct sk_buff *msg,
enum drbd_notification_type type)
{
struct drbd_notification_header nh = {
.nh_type = type,
};
return drbd_notification_header_to_skb(msg, &nh, true);
}
void notify_resource_state(struct sk_buff *skb,
unsigned int seq,
struct drbd_resource *resource,
struct resource_info *resource_info,
enum drbd_notification_type type)
{
struct resource_statistics resource_statistics;
struct drbd_genlmsghdr *dh;
bool multicast = false;
int err;
if (!skb) {
seq = atomic_inc_return(&notify_genl_seq);
skb = genlmsg_new(NLMSG_GOODSIZE, GFP_NOIO);
err = -ENOMEM;
if (!skb)
goto failed;
multicast = true;
}
err = -EMSGSIZE;
dh = genlmsg_put(skb, 0, seq, &drbd_genl_family, 0, DRBD_RESOURCE_STATE);
if (!dh)
goto nla_put_failure;
dh->minor = -1U;
dh->ret_code = NO_ERROR;
if (nla_put_drbd_cfg_context(skb, resource, NULL, NULL) ||
nla_put_notification_header(skb, type) ||
((type & ~NOTIFY_FLAGS) != NOTIFY_DESTROY &&
resource_info_to_skb(skb, resource_info, true)))
goto nla_put_failure;
resource_statistics.res_stat_write_ordering = resource->write_ordering;
err = resource_statistics_to_skb(skb, &resource_statistics, !capable(CAP_SYS_ADMIN));
if (err)
goto nla_put_failure;
genlmsg_end(skb, dh);
if (multicast) {
err = drbd_genl_multicast_events(skb, GFP_NOWAIT);
if (err && err != -ESRCH)
goto failed;
}
return;
nla_put_failure:
nlmsg_free(skb);
failed:
drbd_err(resource, "Error %d while broadcasting event. Event seq:%u\n",
err, seq);
}
void notify_device_state(struct sk_buff *skb,
unsigned int seq,
struct drbd_device *device,
struct device_info *device_info,
enum drbd_notification_type type)
{
struct device_statistics device_statistics;
struct drbd_genlmsghdr *dh;
bool multicast = false;
int err;
if (!skb) {
seq = atomic_inc_return(&notify_genl_seq);
skb = genlmsg_new(NLMSG_GOODSIZE, GFP_NOIO);
err = -ENOMEM;
if (!skb)
goto failed;
multicast = true;
}
err = -EMSGSIZE;
dh = genlmsg_put(skb, 0, seq, &drbd_genl_family, 0, DRBD_DEVICE_STATE);
if (!dh)
goto nla_put_failure;
dh->minor = device->minor;
dh->ret_code = NO_ERROR;
if (nla_put_drbd_cfg_context(skb, device->resource, NULL, device) ||
nla_put_notification_header(skb, type) ||
((type & ~NOTIFY_FLAGS) != NOTIFY_DESTROY &&
device_info_to_skb(skb, device_info, true)))
goto nla_put_failure;
device_to_statistics(&device_statistics, device);
device_statistics_to_skb(skb, &device_statistics, !capable(CAP_SYS_ADMIN));
genlmsg_end(skb, dh);
if (multicast) {
err = drbd_genl_multicast_events(skb, GFP_NOWAIT);
if (err && err != -ESRCH)
goto failed;
}
return;
nla_put_failure:
nlmsg_free(skb);
failed:
drbd_err(device, "Error %d while broadcasting event. Event seq:%u\n",
err, seq);
}
void notify_connection_state(struct sk_buff *skb,
unsigned int seq,
struct drbd_connection *connection,
struct connection_info *connection_info,
enum drbd_notification_type type)
{
struct connection_statistics connection_statistics;
struct drbd_genlmsghdr *dh;
bool multicast = false;
int err;
if (!skb) {
seq = atomic_inc_return(&notify_genl_seq);
skb = genlmsg_new(NLMSG_GOODSIZE, GFP_NOIO);
err = -ENOMEM;
if (!skb)
goto failed;
multicast = true;
}
err = -EMSGSIZE;
dh = genlmsg_put(skb, 0, seq, &drbd_genl_family, 0, DRBD_CONNECTION_STATE);
if (!dh)
goto nla_put_failure;
dh->minor = -1U;
dh->ret_code = NO_ERROR;
if (nla_put_drbd_cfg_context(skb, connection->resource, connection, NULL) ||
nla_put_notification_header(skb, type) ||
((type & ~NOTIFY_FLAGS) != NOTIFY_DESTROY &&
connection_info_to_skb(skb, connection_info, true)))
goto nla_put_failure;
connection_statistics.conn_congested = test_bit(NET_CONGESTED, &connection->flags);
connection_statistics_to_skb(skb, &connection_statistics, !capable(CAP_SYS_ADMIN));
genlmsg_end(skb, dh);
if (multicast) {
err = drbd_genl_multicast_events(skb, GFP_NOWAIT);
if (err && err != -ESRCH)
goto failed;
}
return;
nla_put_failure:
nlmsg_free(skb);
failed:
drbd_err(connection, "Error %d while broadcasting event. Event seq:%u\n",
err, seq);
}
void notify_peer_device_state(struct sk_buff *skb,
unsigned int seq,
struct drbd_peer_device *peer_device,
struct peer_device_info *peer_device_info,
enum drbd_notification_type type)
{
struct peer_device_statistics peer_device_statistics;
struct drbd_resource *resource = peer_device->device->resource;
struct drbd_genlmsghdr *dh;
bool multicast = false;
int err;
if (!skb) {
seq = atomic_inc_return(&notify_genl_seq);
skb = genlmsg_new(NLMSG_GOODSIZE, GFP_NOIO);
err = -ENOMEM;
if (!skb)
goto failed;
multicast = true;
}
err = -EMSGSIZE;
dh = genlmsg_put(skb, 0, seq, &drbd_genl_family, 0, DRBD_PEER_DEVICE_STATE);
if (!dh)
goto nla_put_failure;
dh->minor = -1U;
dh->ret_code = NO_ERROR;
if (nla_put_drbd_cfg_context(skb, resource, peer_device->connection, peer_device->device) ||
nla_put_notification_header(skb, type) ||
((type & ~NOTIFY_FLAGS) != NOTIFY_DESTROY &&
peer_device_info_to_skb(skb, peer_device_info, true)))
goto nla_put_failure;
peer_device_to_statistics(&peer_device_statistics, peer_device);
peer_device_statistics_to_skb(skb, &peer_device_statistics, !capable(CAP_SYS_ADMIN));
genlmsg_end(skb, dh);
if (multicast) {
err = drbd_genl_multicast_events(skb, GFP_NOWAIT);
if (err && err != -ESRCH)
goto failed;
}
return;
nla_put_failure:
nlmsg_free(skb);
failed:
drbd_err(peer_device, "Error %d while broadcasting event. Event seq:%u\n",
err, seq);
}
void notify_helper(enum drbd_notification_type type,
struct drbd_device *device, struct drbd_connection *connection,
const char *name, int status)
{
struct drbd_resource *resource = device ? device->resource : connection->resource;
struct drbd_helper_info helper_info;
unsigned int seq = atomic_inc_return(&notify_genl_seq);
struct sk_buff *skb = NULL;
struct drbd_genlmsghdr *dh;
int err;
strlcpy(helper_info.helper_name, name, sizeof(helper_info.helper_name));
helper_info.helper_name_len = min(strlen(name), sizeof(helper_info.helper_name));
helper_info.helper_status = status;
skb = genlmsg_new(NLMSG_GOODSIZE, GFP_NOIO);
err = -ENOMEM;
if (!skb)
goto fail;
err = -EMSGSIZE;
dh = genlmsg_put(skb, 0, seq, &drbd_genl_family, 0, DRBD_HELPER);
if (!dh)
goto fail;
dh->minor = device ? device->minor : -1;
dh->ret_code = NO_ERROR;
mutex_lock(&notification_mutex);
if (nla_put_drbd_cfg_context(skb, resource, connection, device) ||
nla_put_notification_header(skb, type) ||
drbd_helper_info_to_skb(skb, &helper_info, true))
goto unlock_fail;
genlmsg_end(skb, dh);
err = drbd_genl_multicast_events(skb, GFP_NOWAIT);
skb = NULL;
if (err && err != -ESRCH)
goto unlock_fail;
mutex_unlock(&notification_mutex);
return;
unlock_fail:
mutex_unlock(&notification_mutex);
fail:
nlmsg_free(skb);
drbd_err(resource, "Error %d while broadcasting event. Event seq:%u\n",
err, seq);
}
static void notify_initial_state_done(struct sk_buff *skb, unsigned int seq)
{
struct drbd_genlmsghdr *dh;
int err;
err = -EMSGSIZE;
dh = genlmsg_put(skb, 0, seq, &drbd_genl_family, 0, DRBD_INITIAL_STATE_DONE);
if (!dh)
goto nla_put_failure;
dh->minor = -1U;
dh->ret_code = NO_ERROR;
if (nla_put_notification_header(skb, NOTIFY_EXISTS))
goto nla_put_failure;
genlmsg_end(skb, dh);
return;
nla_put_failure:
nlmsg_free(skb);
pr_err("Error %d sending event. Event seq:%u\n", err, seq);
}
static void free_state_changes(struct list_head *list)
{
while (!list_empty(list)) {
struct drbd_state_change *state_change =
list_first_entry(list, struct drbd_state_change, list);
list_del(&state_change->list);
forget_state_change(state_change);
}
}
static unsigned int notifications_for_state_change(struct drbd_state_change *state_change)
{
return 1 +
state_change->n_connections +
state_change->n_devices +
state_change->n_devices * state_change->n_connections;
}
static int get_initial_state(struct sk_buff *skb, struct netlink_callback *cb)
{
struct drbd_state_change *state_change = (struct drbd_state_change *)cb->args[0];
unsigned int seq = cb->args[2];
unsigned int n;
enum drbd_notification_type flags = 0;
cb->args[5]--;
if (cb->args[5] == 1) {
notify_initial_state_done(skb, seq);
goto out;
}
n = cb->args[4]++;
if (cb->args[4] < cb->args[3])
flags |= NOTIFY_CONTINUES;
if (n < 1) {
notify_resource_state_change(skb, seq, state_change->resource,
NOTIFY_EXISTS | flags);
goto next;
}
n--;
if (n < state_change->n_connections) {
notify_connection_state_change(skb, seq, &state_change->connections[n],
NOTIFY_EXISTS | flags);
goto next;
}
n -= state_change->n_connections;
if (n < state_change->n_devices) {
notify_device_state_change(skb, seq, &state_change->devices[n],
NOTIFY_EXISTS | flags);
goto next;
}
n -= state_change->n_devices;
if (n < state_change->n_devices * state_change->n_connections) {
notify_peer_device_state_change(skb, seq, &state_change->peer_devices[n],
NOTIFY_EXISTS | flags);
goto next;
}
next:
if (cb->args[4] == cb->args[3]) {
struct drbd_state_change *next_state_change =
list_entry(state_change->list.next,
struct drbd_state_change, list);
cb->args[0] = (long)next_state_change;
cb->args[3] = notifications_for_state_change(next_state_change);
cb->args[4] = 0;
}
out:
return skb->len;
}
int drbd_adm_get_initial_state(struct sk_buff *skb, struct netlink_callback *cb)
{
struct drbd_resource *resource;
LIST_HEAD(head);
if (cb->args[5] >= 1) {
if (cb->args[5] > 1)
return get_initial_state(skb, cb);
if (cb->args[0]) {
struct drbd_state_change *state_change =
(struct drbd_state_change *)cb->args[0];
list_add(&head, &state_change->list);
free_state_changes(&head);
}
return 0;
}
cb->args[5] = 2;
mutex_lock(&resources_mutex);
for_each_resource(resource, &drbd_resources) {
struct drbd_state_change *state_change;
state_change = remember_old_state(resource, GFP_KERNEL);
if (!state_change) {
if (!list_empty(&head))
free_state_changes(&head);
mutex_unlock(&resources_mutex);
return -ENOMEM;
}
copy_old_to_new_state_change(state_change);
list_add_tail(&state_change->list, &head);
cb->args[5] += notifications_for_state_change(state_change);
}
mutex_unlock(&resources_mutex);
if (!list_empty(&head)) {
struct drbd_state_change *state_change =
list_entry(head.next, struct drbd_state_change, list);
cb->args[0] = (long)state_change;
cb->args[3] = notifications_for_state_change(state_change);
list_del(&head);
}
cb->args[2] = cb->nlh->nlmsg_seq;
return get_initial_state(skb, cb);
}
