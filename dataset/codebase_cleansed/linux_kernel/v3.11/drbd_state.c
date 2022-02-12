static inline bool is_susp(union drbd_state s)
{
return s.susp || s.susp_nod || s.susp_fen;
}
bool conn_all_vols_unconf(struct drbd_tconn *tconn)
{
struct drbd_conf *mdev;
bool rv = true;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
if (mdev->state.disk != D_DISKLESS ||
mdev->state.conn != C_STANDALONE ||
mdev->state.role != R_SECONDARY) {
rv = false;
break;
}
}
rcu_read_unlock();
return rv;
}
static enum drbd_role max_role(enum drbd_role role1, enum drbd_role role2)
{
if (role1 == R_PRIMARY || role2 == R_PRIMARY)
return R_PRIMARY;
if (role1 == R_SECONDARY || role2 == R_SECONDARY)
return R_SECONDARY;
return R_UNKNOWN;
}
static enum drbd_role min_role(enum drbd_role role1, enum drbd_role role2)
{
if (role1 == R_UNKNOWN || role2 == R_UNKNOWN)
return R_UNKNOWN;
if (role1 == R_SECONDARY || role2 == R_SECONDARY)
return R_SECONDARY;
return R_PRIMARY;
}
enum drbd_role conn_highest_role(struct drbd_tconn *tconn)
{
enum drbd_role role = R_UNKNOWN;
struct drbd_conf *mdev;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr)
role = max_role(role, mdev->state.role);
rcu_read_unlock();
return role;
}
enum drbd_role conn_highest_peer(struct drbd_tconn *tconn)
{
enum drbd_role peer = R_UNKNOWN;
struct drbd_conf *mdev;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr)
peer = max_role(peer, mdev->state.peer);
rcu_read_unlock();
return peer;
}
enum drbd_disk_state conn_highest_disk(struct drbd_tconn *tconn)
{
enum drbd_disk_state ds = D_DISKLESS;
struct drbd_conf *mdev;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr)
ds = max_t(enum drbd_disk_state, ds, mdev->state.disk);
rcu_read_unlock();
return ds;
}
enum drbd_disk_state conn_lowest_disk(struct drbd_tconn *tconn)
{
enum drbd_disk_state ds = D_MASK;
struct drbd_conf *mdev;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr)
ds = min_t(enum drbd_disk_state, ds, mdev->state.disk);
rcu_read_unlock();
return ds;
}
enum drbd_disk_state conn_highest_pdsk(struct drbd_tconn *tconn)
{
enum drbd_disk_state ds = D_DISKLESS;
struct drbd_conf *mdev;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr)
ds = max_t(enum drbd_disk_state, ds, mdev->state.pdsk);
rcu_read_unlock();
return ds;
}
enum drbd_conns conn_lowest_conn(struct drbd_tconn *tconn)
{
enum drbd_conns conn = C_MASK;
struct drbd_conf *mdev;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr)
conn = min_t(enum drbd_conns, conn, mdev->state.conn);
rcu_read_unlock();
return conn;
}
static bool no_peer_wf_report_params(struct drbd_tconn *tconn)
{
struct drbd_conf *mdev;
int vnr;
bool rv = true;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr)
if (mdev->state.conn == C_WF_REPORT_PARAMS) {
rv = false;
break;
}
rcu_read_unlock();
return rv;
}
static int cl_wide_st_chg(struct drbd_conf *mdev,
union drbd_state os, union drbd_state ns)
{
return (os.conn >= C_CONNECTED && ns.conn >= C_CONNECTED &&
((os.role != R_PRIMARY && ns.role == R_PRIMARY) ||
(os.conn != C_STARTING_SYNC_T && ns.conn == C_STARTING_SYNC_T) ||
(os.conn != C_STARTING_SYNC_S && ns.conn == C_STARTING_SYNC_S) ||
(os.disk != D_FAILED && ns.disk == D_FAILED))) ||
(os.conn >= C_CONNECTED && ns.conn == C_DISCONNECTING) ||
(os.conn == C_CONNECTED && ns.conn == C_VERIFY_S) ||
(os.conn == C_CONNECTED && ns.conn == C_WF_REPORT_PARAMS);
}
static union drbd_state
apply_mask_val(union drbd_state os, union drbd_state mask, union drbd_state val)
{
union drbd_state ns;
ns.i = (os.i & ~mask.i) | val.i;
return ns;
}
enum drbd_state_rv
drbd_change_state(struct drbd_conf *mdev, enum chg_state_flags f,
union drbd_state mask, union drbd_state val)
{
unsigned long flags;
union drbd_state ns;
enum drbd_state_rv rv;
spin_lock_irqsave(&mdev->tconn->req_lock, flags);
ns = apply_mask_val(drbd_read_state(mdev), mask, val);
rv = _drbd_set_state(mdev, ns, f, NULL);
spin_unlock_irqrestore(&mdev->tconn->req_lock, flags);
return rv;
}
void drbd_force_state(struct drbd_conf *mdev,
union drbd_state mask, union drbd_state val)
{
drbd_change_state(mdev, CS_HARD, mask, val);
}
static enum drbd_state_rv
_req_st_cond(struct drbd_conf *mdev, union drbd_state mask,
union drbd_state val)
{
union drbd_state os, ns;
unsigned long flags;
enum drbd_state_rv rv;
if (test_and_clear_bit(CL_ST_CHG_SUCCESS, &mdev->flags))
return SS_CW_SUCCESS;
if (test_and_clear_bit(CL_ST_CHG_FAIL, &mdev->flags))
return SS_CW_FAILED_BY_PEER;
spin_lock_irqsave(&mdev->tconn->req_lock, flags);
os = drbd_read_state(mdev);
ns = sanitize_state(mdev, apply_mask_val(os, mask, val), NULL);
rv = is_valid_transition(os, ns);
if (rv >= SS_SUCCESS)
rv = SS_UNKNOWN_ERROR;
if (!cl_wide_st_chg(mdev, os, ns))
rv = SS_CW_NO_NEED;
if (rv == SS_UNKNOWN_ERROR) {
rv = is_valid_state(mdev, ns);
if (rv >= SS_SUCCESS) {
rv = is_valid_soft_transition(os, ns, mdev->tconn);
if (rv >= SS_SUCCESS)
rv = SS_UNKNOWN_ERROR;
}
}
spin_unlock_irqrestore(&mdev->tconn->req_lock, flags);
return rv;
}
static enum drbd_state_rv
drbd_req_state(struct drbd_conf *mdev, union drbd_state mask,
union drbd_state val, enum chg_state_flags f)
{
struct completion done;
unsigned long flags;
union drbd_state os, ns;
enum drbd_state_rv rv;
init_completion(&done);
if (f & CS_SERIALIZE)
mutex_lock(mdev->state_mutex);
spin_lock_irqsave(&mdev->tconn->req_lock, flags);
os = drbd_read_state(mdev);
ns = sanitize_state(mdev, apply_mask_val(os, mask, val), NULL);
rv = is_valid_transition(os, ns);
if (rv < SS_SUCCESS) {
spin_unlock_irqrestore(&mdev->tconn->req_lock, flags);
goto abort;
}
if (cl_wide_st_chg(mdev, os, ns)) {
rv = is_valid_state(mdev, ns);
if (rv == SS_SUCCESS)
rv = is_valid_soft_transition(os, ns, mdev->tconn);
spin_unlock_irqrestore(&mdev->tconn->req_lock, flags);
if (rv < SS_SUCCESS) {
if (f & CS_VERBOSE)
print_st_err(mdev, os, ns, rv);
goto abort;
}
if (drbd_send_state_req(mdev, mask, val)) {
rv = SS_CW_FAILED_BY_PEER;
if (f & CS_VERBOSE)
print_st_err(mdev, os, ns, rv);
goto abort;
}
wait_event(mdev->state_wait,
(rv = _req_st_cond(mdev, mask, val)));
if (rv < SS_SUCCESS) {
if (f & CS_VERBOSE)
print_st_err(mdev, os, ns, rv);
goto abort;
}
spin_lock_irqsave(&mdev->tconn->req_lock, flags);
ns = apply_mask_val(drbd_read_state(mdev), mask, val);
rv = _drbd_set_state(mdev, ns, f, &done);
} else {
rv = _drbd_set_state(mdev, ns, f, &done);
}
spin_unlock_irqrestore(&mdev->tconn->req_lock, flags);
if (f & CS_WAIT_COMPLETE && rv == SS_SUCCESS) {
D_ASSERT(current != mdev->tconn->worker.task);
wait_for_completion(&done);
}
abort:
if (f & CS_SERIALIZE)
mutex_unlock(mdev->state_mutex);
return rv;
}
enum drbd_state_rv
_drbd_request_state(struct drbd_conf *mdev, union drbd_state mask,
union drbd_state val, enum chg_state_flags f)
{
enum drbd_state_rv rv;
wait_event(mdev->state_wait,
(rv = drbd_req_state(mdev, mask, val, f)) != SS_IN_TRANSIENT_STATE);
return rv;
}
static void print_st(struct drbd_conf *mdev, char *name, union drbd_state ns)
{
dev_err(DEV, " %s = { cs:%s ro:%s/%s ds:%s/%s %c%c%c%c%c%c }\n",
name,
drbd_conn_str(ns.conn),
drbd_role_str(ns.role),
drbd_role_str(ns.peer),
drbd_disk_str(ns.disk),
drbd_disk_str(ns.pdsk),
is_susp(ns) ? 's' : 'r',
ns.aftr_isp ? 'a' : '-',
ns.peer_isp ? 'p' : '-',
ns.user_isp ? 'u' : '-',
ns.susp_fen ? 'F' : '-',
ns.susp_nod ? 'N' : '-'
);
}
void print_st_err(struct drbd_conf *mdev, union drbd_state os,
union drbd_state ns, enum drbd_state_rv err)
{
if (err == SS_IN_TRANSIENT_STATE)
return;
dev_err(DEV, "State change failed: %s\n", drbd_set_st_err_str(err));
print_st(mdev, " state", os);
print_st(mdev, "wanted", ns);
}
static long print_state_change(char *pb, union drbd_state os, union drbd_state ns,
enum chg_state_flags flags)
{
char *pbp;
pbp = pb;
*pbp = 0;
if (ns.role != os.role && flags & CS_DC_ROLE)
pbp += sprintf(pbp, "role( %s -> %s ) ",
drbd_role_str(os.role),
drbd_role_str(ns.role));
if (ns.peer != os.peer && flags & CS_DC_PEER)
pbp += sprintf(pbp, "peer( %s -> %s ) ",
drbd_role_str(os.peer),
drbd_role_str(ns.peer));
if (ns.conn != os.conn && flags & CS_DC_CONN)
pbp += sprintf(pbp, "conn( %s -> %s ) ",
drbd_conn_str(os.conn),
drbd_conn_str(ns.conn));
if (ns.disk != os.disk && flags & CS_DC_DISK)
pbp += sprintf(pbp, "disk( %s -> %s ) ",
drbd_disk_str(os.disk),
drbd_disk_str(ns.disk));
if (ns.pdsk != os.pdsk && flags & CS_DC_PDSK)
pbp += sprintf(pbp, "pdsk( %s -> %s ) ",
drbd_disk_str(os.pdsk),
drbd_disk_str(ns.pdsk));
return pbp - pb;
}
static void drbd_pr_state_change(struct drbd_conf *mdev, union drbd_state os, union drbd_state ns,
enum chg_state_flags flags)
{
char pb[300];
char *pbp = pb;
pbp += print_state_change(pbp, os, ns, flags ^ CS_DC_MASK);
if (ns.aftr_isp != os.aftr_isp)
pbp += sprintf(pbp, "aftr_isp( %d -> %d ) ",
os.aftr_isp,
ns.aftr_isp);
if (ns.peer_isp != os.peer_isp)
pbp += sprintf(pbp, "peer_isp( %d -> %d ) ",
os.peer_isp,
ns.peer_isp);
if (ns.user_isp != os.user_isp)
pbp += sprintf(pbp, "user_isp( %d -> %d ) ",
os.user_isp,
ns.user_isp);
if (pbp != pb)
dev_info(DEV, "%s\n", pb);
}
static void conn_pr_state_change(struct drbd_tconn *tconn, union drbd_state os, union drbd_state ns,
enum chg_state_flags flags)
{
char pb[300];
char *pbp = pb;
pbp += print_state_change(pbp, os, ns, flags);
if (is_susp(ns) != is_susp(os) && flags & CS_DC_SUSP)
pbp += sprintf(pbp, "susp( %d -> %d ) ",
is_susp(os),
is_susp(ns));
if (pbp != pb)
conn_info(tconn, "%s\n", pb);
}
static enum drbd_state_rv
is_valid_state(struct drbd_conf *mdev, union drbd_state ns)
{
enum drbd_fencing_p fp;
enum drbd_state_rv rv = SS_SUCCESS;
struct net_conf *nc;
rcu_read_lock();
fp = FP_DONT_CARE;
if (get_ldev(mdev)) {
fp = rcu_dereference(mdev->ldev->disk_conf)->fencing;
put_ldev(mdev);
}
nc = rcu_dereference(mdev->tconn->net_conf);
if (nc) {
if (!nc->two_primaries && ns.role == R_PRIMARY) {
if (ns.peer == R_PRIMARY)
rv = SS_TWO_PRIMARIES;
else if (conn_highest_peer(mdev->tconn) == R_PRIMARY)
rv = SS_O_VOL_PEER_PRI;
}
}
if (rv <= 0)
;
else if (ns.role == R_SECONDARY && mdev->open_cnt)
rv = SS_DEVICE_IN_USE;
else if (ns.role == R_PRIMARY && ns.conn < C_CONNECTED && ns.disk < D_UP_TO_DATE)
rv = SS_NO_UP_TO_DATE_DISK;
else if (fp >= FP_RESOURCE &&
ns.role == R_PRIMARY && ns.conn < C_CONNECTED && ns.pdsk >= D_UNKNOWN)
rv = SS_PRIMARY_NOP;
else if (ns.role == R_PRIMARY && ns.disk <= D_INCONSISTENT && ns.pdsk <= D_INCONSISTENT)
rv = SS_NO_UP_TO_DATE_DISK;
else if (ns.conn > C_CONNECTED && ns.disk < D_INCONSISTENT)
rv = SS_NO_LOCAL_DISK;
else if (ns.conn > C_CONNECTED && ns.pdsk < D_INCONSISTENT)
rv = SS_NO_REMOTE_DISK;
else if (ns.conn > C_CONNECTED && ns.disk < D_UP_TO_DATE && ns.pdsk < D_UP_TO_DATE)
rv = SS_NO_UP_TO_DATE_DISK;
else if ((ns.conn == C_CONNECTED ||
ns.conn == C_WF_BITMAP_S ||
ns.conn == C_SYNC_SOURCE ||
ns.conn == C_PAUSED_SYNC_S) &&
ns.disk == D_OUTDATED)
rv = SS_CONNECTED_OUTDATES;
else if ((ns.conn == C_VERIFY_S || ns.conn == C_VERIFY_T) &&
(nc->verify_alg[0] == 0))
rv = SS_NO_VERIFY_ALG;
else if ((ns.conn == C_VERIFY_S || ns.conn == C_VERIFY_T) &&
mdev->tconn->agreed_pro_version < 88)
rv = SS_NOT_SUPPORTED;
else if (ns.role == R_PRIMARY && ns.disk < D_UP_TO_DATE && ns.pdsk < D_UP_TO_DATE)
rv = SS_NO_UP_TO_DATE_DISK;
else if ((ns.conn == C_STARTING_SYNC_S || ns.conn == C_STARTING_SYNC_T) &&
ns.pdsk == D_UNKNOWN)
rv = SS_NEED_CONNECTION;
else if (ns.conn >= C_CONNECTED && ns.pdsk == D_UNKNOWN)
rv = SS_CONNECTED_OUTDATES;
rcu_read_unlock();
return rv;
}
static enum drbd_state_rv
is_valid_soft_transition(union drbd_state os, union drbd_state ns, struct drbd_tconn *tconn)
{
enum drbd_state_rv rv = SS_SUCCESS;
if ((ns.conn == C_STARTING_SYNC_T || ns.conn == C_STARTING_SYNC_S) &&
os.conn > C_CONNECTED)
rv = SS_RESYNC_RUNNING;
if (ns.conn == C_DISCONNECTING && os.conn == C_STANDALONE)
rv = SS_ALREADY_STANDALONE;
if (ns.disk > D_ATTACHING && os.disk == D_DISKLESS)
rv = SS_IS_DISKLESS;
if (ns.conn == C_WF_CONNECTION && os.conn < C_UNCONNECTED)
rv = SS_NO_NET_CONFIG;
if (ns.disk == D_OUTDATED && os.disk < D_OUTDATED && os.disk != D_ATTACHING)
rv = SS_LOWER_THAN_OUTDATED;
if (ns.conn == C_DISCONNECTING && os.conn == C_UNCONNECTED)
rv = SS_IN_TRANSIENT_STATE;
if (test_bit(STATE_SENT, &tconn->flags) &&
!(os.conn == C_WF_REPORT_PARAMS ||
(ns.conn == C_WF_REPORT_PARAMS && os.conn == C_WF_CONNECTION)))
rv = SS_IN_TRANSIENT_STATE;
if ((ns.conn == C_VERIFY_S || ns.conn == C_VERIFY_T) && os.conn < C_CONNECTED)
rv = SS_NEED_CONNECTION;
if ((ns.conn == C_VERIFY_S || ns.conn == C_VERIFY_T) &&
ns.conn != os.conn && os.conn > C_CONNECTED)
rv = SS_RESYNC_RUNNING;
if ((ns.conn == C_STARTING_SYNC_S || ns.conn == C_STARTING_SYNC_T) &&
os.conn < C_CONNECTED)
rv = SS_NEED_CONNECTION;
if ((ns.conn == C_SYNC_TARGET || ns.conn == C_SYNC_SOURCE)
&& os.conn < C_WF_REPORT_PARAMS)
rv = SS_NEED_CONNECTION;
if (ns.conn == C_DISCONNECTING && ns.pdsk == D_OUTDATED &&
os.conn < C_CONNECTED && os.pdsk > D_OUTDATED)
rv = SS_OUTDATE_WO_CONN;
return rv;
}
static enum drbd_state_rv
is_valid_conn_transition(enum drbd_conns oc, enum drbd_conns nc)
{
if (oc == nc)
return SS_NOTHING_TO_DO;
if (oc == C_STANDALONE && nc == C_DISCONNECTING)
return SS_ALREADY_STANDALONE;
if (oc == C_STANDALONE && nc != C_UNCONNECTED)
return SS_NEED_CONNECTION;
if (oc < C_WF_REPORT_PARAMS && nc >= C_CONNECTED)
return SS_NEED_CONNECTION;
if (oc >= C_TIMEOUT && oc <= C_TEAR_DOWN && nc != C_UNCONNECTED && nc != C_DISCONNECTING)
return SS_IN_TRANSIENT_STATE;
if (oc == C_DISCONNECTING && nc != C_STANDALONE)
return SS_IN_TRANSIENT_STATE;
return SS_SUCCESS;
}
static enum drbd_state_rv
is_valid_transition(union drbd_state os, union drbd_state ns)
{
enum drbd_state_rv rv;
rv = is_valid_conn_transition(os.conn, ns.conn);
if (ns.disk == D_FAILED && os.disk == D_DISKLESS)
rv = SS_IS_DISKLESS;
return rv;
}
static void print_sanitize_warnings(struct drbd_conf *mdev, enum sanitize_state_warnings warn)
{
static const char *msg_table[] = {
[NO_WARNING] = "",
[ABORTED_ONLINE_VERIFY] = "Online-verify aborted.",
[ABORTED_RESYNC] = "Resync aborted.",
[CONNECTION_LOST_NEGOTIATING] = "Connection lost while negotiating, no data!",
[IMPLICITLY_UPGRADED_DISK] = "Implicitly upgraded disk",
[IMPLICITLY_UPGRADED_PDSK] = "Implicitly upgraded pdsk",
};
if (warn != NO_WARNING)
dev_warn(DEV, "%s\n", msg_table[warn]);
}
static union drbd_state sanitize_state(struct drbd_conf *mdev, union drbd_state ns,
enum sanitize_state_warnings *warn)
{
enum drbd_fencing_p fp;
enum drbd_disk_state disk_min, disk_max, pdsk_min, pdsk_max;
if (warn)
*warn = NO_WARNING;
fp = FP_DONT_CARE;
if (get_ldev(mdev)) {
rcu_read_lock();
fp = rcu_dereference(mdev->ldev->disk_conf)->fencing;
rcu_read_unlock();
put_ldev(mdev);
}
if (ns.conn < C_CONNECTED) {
ns.peer_isp = 0;
ns.peer = R_UNKNOWN;
if (ns.pdsk > D_UNKNOWN || ns.pdsk < D_INCONSISTENT)
ns.pdsk = D_UNKNOWN;
}
if (ns.conn == C_STANDALONE && ns.disk == D_DISKLESS && ns.role == R_SECONDARY)
ns.aftr_isp = 0;
if (ns.conn > C_CONNECTED && (ns.disk <= D_FAILED || ns.pdsk <= D_FAILED)) {
if (warn)
*warn = ns.conn == C_VERIFY_S || ns.conn == C_VERIFY_T ?
ABORTED_ONLINE_VERIFY : ABORTED_RESYNC;
ns.conn = C_CONNECTED;
}
if (ns.conn < C_CONNECTED && ns.disk == D_NEGOTIATING &&
get_ldev_if_state(mdev, D_NEGOTIATING)) {
if (mdev->ed_uuid == mdev->ldev->md.uuid[UI_CURRENT]) {
ns.disk = mdev->new_state_tmp.disk;
ns.pdsk = mdev->new_state_tmp.pdsk;
} else {
if (warn)
*warn = CONNECTION_LOST_NEGOTIATING;
ns.disk = D_DISKLESS;
ns.pdsk = D_UNKNOWN;
}
put_ldev(mdev);
}
if (ns.conn >= C_CONNECTED && ns.conn < C_AHEAD) {
if (ns.disk == D_CONSISTENT || ns.disk == D_OUTDATED)
ns.disk = D_UP_TO_DATE;
if (ns.pdsk == D_CONSISTENT || ns.pdsk == D_OUTDATED)
ns.pdsk = D_UP_TO_DATE;
}
disk_min = D_DISKLESS;
disk_max = D_UP_TO_DATE;
pdsk_min = D_INCONSISTENT;
pdsk_max = D_UNKNOWN;
switch ((enum drbd_conns)ns.conn) {
case C_WF_BITMAP_T:
case C_PAUSED_SYNC_T:
case C_STARTING_SYNC_T:
case C_WF_SYNC_UUID:
case C_BEHIND:
disk_min = D_INCONSISTENT;
disk_max = D_OUTDATED;
pdsk_min = D_UP_TO_DATE;
pdsk_max = D_UP_TO_DATE;
break;
case C_VERIFY_S:
case C_VERIFY_T:
disk_min = D_UP_TO_DATE;
disk_max = D_UP_TO_DATE;
pdsk_min = D_UP_TO_DATE;
pdsk_max = D_UP_TO_DATE;
break;
case C_CONNECTED:
disk_min = D_DISKLESS;
disk_max = D_UP_TO_DATE;
pdsk_min = D_DISKLESS;
pdsk_max = D_UP_TO_DATE;
break;
case C_WF_BITMAP_S:
case C_PAUSED_SYNC_S:
case C_STARTING_SYNC_S:
case C_AHEAD:
disk_min = D_UP_TO_DATE;
disk_max = D_UP_TO_DATE;
pdsk_min = D_INCONSISTENT;
pdsk_max = D_CONSISTENT;
break;
case C_SYNC_TARGET:
disk_min = D_INCONSISTENT;
disk_max = D_INCONSISTENT;
pdsk_min = D_UP_TO_DATE;
pdsk_max = D_UP_TO_DATE;
break;
case C_SYNC_SOURCE:
disk_min = D_UP_TO_DATE;
disk_max = D_UP_TO_DATE;
pdsk_min = D_INCONSISTENT;
pdsk_max = D_INCONSISTENT;
break;
case C_STANDALONE:
case C_DISCONNECTING:
case C_UNCONNECTED:
case C_TIMEOUT:
case C_BROKEN_PIPE:
case C_NETWORK_FAILURE:
case C_PROTOCOL_ERROR:
case C_TEAR_DOWN:
case C_WF_CONNECTION:
case C_WF_REPORT_PARAMS:
case C_MASK:
break;
}
if (ns.disk > disk_max)
ns.disk = disk_max;
if (ns.disk < disk_min) {
if (warn)
*warn = IMPLICITLY_UPGRADED_DISK;
ns.disk = disk_min;
}
if (ns.pdsk > pdsk_max)
ns.pdsk = pdsk_max;
if (ns.pdsk < pdsk_min) {
if (warn)
*warn = IMPLICITLY_UPGRADED_PDSK;
ns.pdsk = pdsk_min;
}
if (fp == FP_STONITH &&
(ns.role == R_PRIMARY && ns.conn < C_CONNECTED && ns.pdsk > D_OUTDATED))
ns.susp_fen = 1;
if (mdev->tconn->res_opts.on_no_data == OND_SUSPEND_IO &&
(ns.role == R_PRIMARY && ns.disk < D_UP_TO_DATE && ns.pdsk < D_UP_TO_DATE))
ns.susp_nod = 1;
if (ns.aftr_isp || ns.peer_isp || ns.user_isp) {
if (ns.conn == C_SYNC_SOURCE)
ns.conn = C_PAUSED_SYNC_S;
if (ns.conn == C_SYNC_TARGET)
ns.conn = C_PAUSED_SYNC_T;
} else {
if (ns.conn == C_PAUSED_SYNC_S)
ns.conn = C_SYNC_SOURCE;
if (ns.conn == C_PAUSED_SYNC_T)
ns.conn = C_SYNC_TARGET;
}
return ns;
}
void drbd_resume_al(struct drbd_conf *mdev)
{
if (test_and_clear_bit(AL_SUSPENDED, &mdev->flags))
dev_info(DEV, "Resumed AL updates\n");
}
static void set_ov_position(struct drbd_conf *mdev, enum drbd_conns cs)
{
if (mdev->tconn->agreed_pro_version < 90)
mdev->ov_start_sector = 0;
mdev->rs_total = drbd_bm_bits(mdev);
mdev->ov_position = 0;
if (cs == C_VERIFY_T) {
mdev->ov_start_sector = ~(sector_t)0;
} else {
unsigned long bit = BM_SECT_TO_BIT(mdev->ov_start_sector);
if (bit >= mdev->rs_total) {
mdev->ov_start_sector =
BM_BIT_TO_SECT(mdev->rs_total - 1);
mdev->rs_total = 1;
} else
mdev->rs_total -= bit;
mdev->ov_position = mdev->ov_start_sector;
}
mdev->ov_left = mdev->rs_total;
}
enum drbd_state_rv
__drbd_set_state(struct drbd_conf *mdev, union drbd_state ns,
enum chg_state_flags flags, struct completion *done)
{
union drbd_state os;
enum drbd_state_rv rv = SS_SUCCESS;
enum sanitize_state_warnings ssw;
struct after_state_chg_work *ascw;
bool did_remote, should_do_remote;
os = drbd_read_state(mdev);
ns = sanitize_state(mdev, ns, &ssw);
if (ns.i == os.i)
return SS_NOTHING_TO_DO;
rv = is_valid_transition(os, ns);
if (rv < SS_SUCCESS)
return rv;
if (!(flags & CS_HARD)) {
rv = is_valid_state(mdev, ns);
if (rv < SS_SUCCESS) {
if (is_valid_state(mdev, os) == rv)
rv = is_valid_soft_transition(os, ns, mdev->tconn);
} else
rv = is_valid_soft_transition(os, ns, mdev->tconn);
}
if (rv < SS_SUCCESS) {
if (flags & CS_VERBOSE)
print_st_err(mdev, os, ns, rv);
return rv;
}
print_sanitize_warnings(mdev, ssw);
drbd_pr_state_change(mdev, os, ns, flags);
if (!(flags & CS_DC_SUSP))
conn_pr_state_change(mdev->tconn, os, ns, (flags & ~CS_DC_MASK) | CS_DC_SUSP);
if ((os.disk != D_FAILED && ns.disk == D_FAILED) ||
(os.disk != D_DISKLESS && ns.disk == D_DISKLESS))
atomic_inc(&mdev->local_cnt);
did_remote = drbd_should_do_remote(mdev->state);
mdev->state.i = ns.i;
should_do_remote = drbd_should_do_remote(mdev->state);
mdev->tconn->susp = ns.susp;
mdev->tconn->susp_nod = ns.susp_nod;
mdev->tconn->susp_fen = ns.susp_fen;
if (did_remote != should_do_remote)
start_new_tl_epoch(mdev->tconn);
if (os.disk == D_ATTACHING && ns.disk >= D_NEGOTIATING)
drbd_print_uuids(mdev, "attached to UUIDs");
if (os.conn == C_WF_REPORT_PARAMS && ns.conn != C_WF_REPORT_PARAMS &&
no_peer_wf_report_params(mdev->tconn))
clear_bit(STATE_SENT, &mdev->tconn->flags);
wake_up(&mdev->misc_wait);
wake_up(&mdev->state_wait);
wake_up(&mdev->tconn->ping_wait);
if ((os.conn == C_VERIFY_S || os.conn == C_VERIFY_T) &&
ns.conn <= C_CONNECTED) {
mdev->ov_start_sector =
BM_BIT_TO_SECT(drbd_bm_bits(mdev) - mdev->ov_left);
if (mdev->ov_left)
dev_info(DEV, "Online Verify reached sector %llu\n",
(unsigned long long)mdev->ov_start_sector);
}
if ((os.conn == C_PAUSED_SYNC_T || os.conn == C_PAUSED_SYNC_S) &&
(ns.conn == C_SYNC_TARGET || ns.conn == C_SYNC_SOURCE)) {
dev_info(DEV, "Syncer continues.\n");
mdev->rs_paused += (long)jiffies
-(long)mdev->rs_mark_time[mdev->rs_last_mark];
if (ns.conn == C_SYNC_TARGET)
mod_timer(&mdev->resync_timer, jiffies);
}
if ((os.conn == C_SYNC_TARGET || os.conn == C_SYNC_SOURCE) &&
(ns.conn == C_PAUSED_SYNC_T || ns.conn == C_PAUSED_SYNC_S)) {
dev_info(DEV, "Resync suspended\n");
mdev->rs_mark_time[mdev->rs_last_mark] = jiffies;
}
if (os.conn == C_CONNECTED &&
(ns.conn == C_VERIFY_S || ns.conn == C_VERIFY_T)) {
unsigned long now = jiffies;
int i;
set_ov_position(mdev, ns.conn);
mdev->rs_start = now;
mdev->rs_last_events = 0;
mdev->rs_last_sect_ev = 0;
mdev->ov_last_oos_size = 0;
mdev->ov_last_oos_start = 0;
for (i = 0; i < DRBD_SYNC_MARKS; i++) {
mdev->rs_mark_left[i] = mdev->ov_left;
mdev->rs_mark_time[i] = now;
}
drbd_rs_controller_reset(mdev);
if (ns.conn == C_VERIFY_S) {
dev_info(DEV, "Starting Online Verify from sector %llu\n",
(unsigned long long)mdev->ov_position);
mod_timer(&mdev->resync_timer, jiffies);
}
}
if (get_ldev(mdev)) {
u32 mdf = mdev->ldev->md.flags & ~(MDF_CONSISTENT|MDF_PRIMARY_IND|
MDF_CONNECTED_IND|MDF_WAS_UP_TO_DATE|
MDF_PEER_OUT_DATED|MDF_CRASHED_PRIMARY);
mdf &= ~MDF_AL_CLEAN;
if (test_bit(CRASHED_PRIMARY, &mdev->flags))
mdf |= MDF_CRASHED_PRIMARY;
if (mdev->state.role == R_PRIMARY ||
(mdev->state.pdsk < D_INCONSISTENT && mdev->state.peer == R_PRIMARY))
mdf |= MDF_PRIMARY_IND;
if (mdev->state.conn > C_WF_REPORT_PARAMS)
mdf |= MDF_CONNECTED_IND;
if (mdev->state.disk > D_INCONSISTENT)
mdf |= MDF_CONSISTENT;
if (mdev->state.disk > D_OUTDATED)
mdf |= MDF_WAS_UP_TO_DATE;
if (mdev->state.pdsk <= D_OUTDATED && mdev->state.pdsk >= D_INCONSISTENT)
mdf |= MDF_PEER_OUT_DATED;
if (mdf != mdev->ldev->md.flags) {
mdev->ldev->md.flags = mdf;
drbd_md_mark_dirty(mdev);
}
if (os.disk < D_CONSISTENT && ns.disk >= D_CONSISTENT)
drbd_set_ed_uuid(mdev, mdev->ldev->md.uuid[UI_CURRENT]);
put_ldev(mdev);
}
if (os.disk == D_INCONSISTENT && os.pdsk == D_INCONSISTENT &&
os.peer == R_SECONDARY && ns.peer == R_PRIMARY)
set_bit(CONSIDER_RESYNC, &mdev->flags);
if (os.conn != C_DISCONNECTING && ns.conn == C_DISCONNECTING)
drbd_thread_stop_nowait(&mdev->tconn->receiver);
if (os.conn != C_STANDALONE && ns.conn == C_STANDALONE)
drbd_thread_stop_nowait(&mdev->tconn->receiver);
if (os.conn > C_WF_CONNECTION &&
ns.conn <= C_TEAR_DOWN && ns.conn >= C_TIMEOUT)
drbd_thread_restart_nowait(&mdev->tconn->receiver);
if (os.conn < C_CONNECTED && ns.conn >= C_CONNECTED) {
drbd_resume_al(mdev);
mdev->tconn->connect_cnt++;
}
if ((os.disk == D_ATTACHING || os.disk == D_NEGOTIATING) &&
ns.disk > D_NEGOTIATING)
mdev->last_reattach_jif = jiffies;
ascw = kmalloc(sizeof(*ascw), GFP_ATOMIC);
if (ascw) {
ascw->os = os;
ascw->ns = ns;
ascw->flags = flags;
ascw->w.cb = w_after_state_ch;
ascw->w.mdev = mdev;
ascw->done = done;
drbd_queue_work(&mdev->tconn->sender_work, &ascw->w);
} else {
dev_err(DEV, "Could not kmalloc an ascw\n");
}
return rv;
}
static int w_after_state_ch(struct drbd_work *w, int unused)
{
struct after_state_chg_work *ascw =
container_of(w, struct after_state_chg_work, w);
struct drbd_conf *mdev = w->mdev;
after_state_ch(mdev, ascw->os, ascw->ns, ascw->flags);
if (ascw->flags & CS_WAIT_COMPLETE) {
D_ASSERT(ascw->done != NULL);
complete(ascw->done);
}
kfree(ascw);
return 0;
}
static void abw_start_sync(struct drbd_conf *mdev, int rv)
{
if (rv) {
dev_err(DEV, "Writing the bitmap failed not starting resync.\n");
_drbd_request_state(mdev, NS(conn, C_CONNECTED), CS_VERBOSE);
return;
}
switch (mdev->state.conn) {
case C_STARTING_SYNC_T:
_drbd_request_state(mdev, NS(conn, C_WF_SYNC_UUID), CS_VERBOSE);
break;
case C_STARTING_SYNC_S:
drbd_start_resync(mdev, C_SYNC_SOURCE);
break;
}
}
int drbd_bitmap_io_from_worker(struct drbd_conf *mdev,
int (*io_fn)(struct drbd_conf *),
char *why, enum bm_flag flags)
{
int rv;
D_ASSERT(current == mdev->tconn->worker.task);
set_bit(SUSPEND_IO, &mdev->flags);
drbd_bm_lock(mdev, why, flags);
rv = io_fn(mdev);
drbd_bm_unlock(mdev);
drbd_resume_io(mdev);
return rv;
}
static void after_state_ch(struct drbd_conf *mdev, union drbd_state os,
union drbd_state ns, enum chg_state_flags flags)
{
struct sib_info sib;
sib.sib_reason = SIB_STATE_CHANGE;
sib.os = os;
sib.ns = ns;
if (os.conn != C_CONNECTED && ns.conn == C_CONNECTED) {
clear_bit(CRASHED_PRIMARY, &mdev->flags);
if (mdev->p_uuid)
mdev->p_uuid[UI_FLAGS] &= ~((u64)2);
}
drbd_bcast_event(mdev, &sib);
if (!(os.role == R_PRIMARY && os.disk < D_UP_TO_DATE && os.pdsk < D_UP_TO_DATE) &&
(ns.role == R_PRIMARY && ns.disk < D_UP_TO_DATE && ns.pdsk < D_UP_TO_DATE))
drbd_khelper(mdev, "pri-on-incon-degr");
if (ns.susp_nod) {
struct drbd_tconn *tconn = mdev->tconn;
enum drbd_req_event what = NOTHING;
spin_lock_irq(&tconn->req_lock);
if (os.conn < C_CONNECTED && conn_lowest_conn(tconn) >= C_CONNECTED)
what = RESEND;
if ((os.disk == D_ATTACHING || os.disk == D_NEGOTIATING) &&
conn_lowest_disk(tconn) > D_NEGOTIATING)
what = RESTART_FROZEN_DISK_IO;
if (tconn->susp_nod && what != NOTHING) {
_tl_restart(tconn, what);
_conn_request_state(tconn,
(union drbd_state) { { .susp_nod = 1 } },
(union drbd_state) { { .susp_nod = 0 } },
CS_VERBOSE);
}
spin_unlock_irq(&tconn->req_lock);
}
if (ns.susp_fen) {
struct drbd_tconn *tconn = mdev->tconn;
spin_lock_irq(&tconn->req_lock);
if (tconn->susp_fen && conn_lowest_conn(tconn) >= C_CONNECTED) {
struct drbd_conf *odev;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, odev, vnr)
clear_bit(NEW_CUR_UUID, &odev->flags);
rcu_read_unlock();
_tl_restart(tconn, RESEND);
_conn_request_state(tconn,
(union drbd_state) { { .susp_fen = 1 } },
(union drbd_state) { { .susp_fen = 0 } },
CS_VERBOSE);
}
spin_unlock_irq(&tconn->req_lock);
}
if ((os.conn != C_SYNC_SOURCE && os.conn != C_PAUSED_SYNC_S) &&
(ns.conn == C_SYNC_SOURCE || ns.conn == C_PAUSED_SYNC_S) &&
mdev->tconn->agreed_pro_version >= 96 && get_ldev(mdev)) {
drbd_gen_and_send_sync_uuid(mdev);
put_ldev(mdev);
}
if (os.pdsk == D_DISKLESS &&
ns.pdsk > D_DISKLESS && ns.pdsk != D_UNKNOWN) {
mdev->rs_total = 0;
mdev->rs_failed = 0;
atomic_set(&mdev->rs_pending_cnt, 0);
drbd_rs_cancel_all(mdev);
drbd_send_uuids(mdev);
drbd_send_state(mdev, ns);
}
if (os.conn != C_WF_BITMAP_S && ns.conn == C_WF_BITMAP_S &&
mdev->state.conn == C_WF_BITMAP_S)
drbd_queue_bitmap_io(mdev, &drbd_send_bitmap, NULL,
"send_bitmap (WFBitMapS)",
BM_LOCKED_TEST_ALLOWED);
if ((os.pdsk >= D_INCONSISTENT &&
os.pdsk != D_UNKNOWN &&
os.pdsk != D_OUTDATED)
&& (ns.pdsk < D_INCONSISTENT ||
ns.pdsk == D_UNKNOWN ||
ns.pdsk == D_OUTDATED)) {
if (get_ldev(mdev)) {
if ((ns.role == R_PRIMARY || ns.peer == R_PRIMARY) &&
mdev->ldev->md.uuid[UI_BITMAP] == 0 && ns.disk >= D_UP_TO_DATE) {
if (drbd_suspended(mdev)) {
set_bit(NEW_CUR_UUID, &mdev->flags);
} else {
drbd_uuid_new_current(mdev);
drbd_send_uuids(mdev);
}
}
put_ldev(mdev);
}
}
if (ns.pdsk < D_INCONSISTENT && get_ldev(mdev)) {
if (os.peer == R_SECONDARY && ns.peer == R_PRIMARY &&
mdev->ldev->md.uuid[UI_BITMAP] == 0 && ns.disk >= D_UP_TO_DATE) {
drbd_uuid_new_current(mdev);
drbd_send_uuids(mdev);
}
if (os.peer == R_PRIMARY && ns.peer == R_SECONDARY)
drbd_bitmap_io_from_worker(mdev, &drbd_bm_write,
"demote diskless peer", BM_LOCKED_SET_ALLOWED);
put_ldev(mdev);
}
if (os.role == R_PRIMARY && ns.role == R_SECONDARY &&
mdev->state.conn <= C_CONNECTED && get_ldev(mdev)) {
drbd_bitmap_io_from_worker(mdev, &drbd_bm_write,
"demote", BM_LOCKED_TEST_ALLOWED);
put_ldev(mdev);
}
if (ns.conn >= C_CONNECTED &&
os.disk == D_ATTACHING && ns.disk == D_NEGOTIATING) {
drbd_send_sizes(mdev, 0, 0);
drbd_send_uuids(mdev);
drbd_send_state(mdev, ns);
}
if (ns.conn >= C_CONNECTED &&
((os.aftr_isp != ns.aftr_isp) ||
(os.user_isp != ns.user_isp)))
drbd_send_state(mdev, ns);
if ((!os.aftr_isp && !os.peer_isp && !os.user_isp) &&
(ns.aftr_isp || ns.peer_isp || ns.user_isp))
suspend_other_sg(mdev);
if (os.conn == C_WF_REPORT_PARAMS && ns.conn >= C_CONNECTED)
drbd_send_state(mdev, ns);
if (os.conn != C_AHEAD && ns.conn == C_AHEAD)
drbd_send_state(mdev, ns);
if ((os.conn != C_STARTING_SYNC_T && ns.conn == C_STARTING_SYNC_T) ||
(os.conn != C_STARTING_SYNC_S && ns.conn == C_STARTING_SYNC_S))
drbd_queue_bitmap_io(mdev,
&drbd_bmio_set_n_write, &abw_start_sync,
"set_n_write from StartingSync", BM_LOCKED_TEST_ALLOWED);
if (os.disk != D_FAILED && ns.disk == D_FAILED) {
enum drbd_io_error_p eh = EP_PASS_ON;
int was_io_error = 0;
if (mdev->ldev) {
rcu_read_lock();
eh = rcu_dereference(mdev->ldev->disk_conf)->on_io_error;
rcu_read_unlock();
was_io_error = test_and_clear_bit(WAS_IO_ERROR, &mdev->flags);
if (was_io_error && eh == EP_CALL_HELPER)
drbd_khelper(mdev, "local-io-error");
if (test_and_clear_bit(FORCE_DETACH, &mdev->flags))
tl_abort_disk_io(mdev);
if (mdev->state.disk != D_FAILED)
dev_err(DEV,
"ASSERT FAILED: disk is %s during detach\n",
drbd_disk_str(mdev->state.disk));
if (ns.conn >= C_CONNECTED)
drbd_send_state(mdev, ns);
drbd_rs_cancel_all(mdev);
drbd_md_sync(mdev);
}
put_ldev(mdev);
}
if (os.disk != D_DISKLESS && ns.disk == D_DISKLESS) {
if (mdev->state.disk != D_DISKLESS)
dev_err(DEV,
"ASSERT FAILED: disk is %s while going diskless\n",
drbd_disk_str(mdev->state.disk));
if (ns.conn >= C_CONNECTED)
drbd_send_state(mdev, ns);
put_ldev(mdev);
}
if (os.disk == D_UP_TO_DATE && ns.disk == D_INCONSISTENT && ns.conn >= C_CONNECTED)
drbd_send_state(mdev, ns);
if (ns.disk > D_NEGOTIATING && ns.pdsk > D_NEGOTIATING &&
test_and_clear_bit(RESYNC_AFTER_NEG, &mdev->flags)) {
if (ns.conn == C_CONNECTED)
resync_after_online_grow(mdev);
}
if ((os.conn > C_CONNECTED && ns.conn <= C_CONNECTED) ||
(os.peer_isp && !ns.peer_isp) ||
(os.user_isp && !ns.user_isp))
resume_next_sg(mdev);
if (os.disk < D_UP_TO_DATE && os.conn >= C_SYNC_SOURCE && ns.conn == C_CONNECTED)
drbd_send_state(mdev, ns);
if (os.conn == C_VERIFY_S && ns.conn == C_CONNECTED
&& verify_can_do_stop_sector(mdev))
drbd_send_state(mdev, ns);
if (os.conn > C_CONNECTED && ns.conn <= C_CONNECTED && get_ldev(mdev)) {
drbd_queue_bitmap_io(mdev, &drbd_bm_write_copy_pages, NULL,
"write from resync_finished", BM_LOCKED_CHANGE_ALLOWED);
put_ldev(mdev);
}
if (ns.disk == D_DISKLESS &&
ns.conn == C_STANDALONE &&
ns.role == R_SECONDARY) {
if (os.aftr_isp != ns.aftr_isp)
resume_next_sg(mdev);
}
drbd_md_sync(mdev);
}
static int w_after_conn_state_ch(struct drbd_work *w, int unused)
{
struct after_conn_state_chg_work *acscw =
container_of(w, struct after_conn_state_chg_work, w);
struct drbd_tconn *tconn = w->tconn;
enum drbd_conns oc = acscw->oc;
union drbd_state ns_max = acscw->ns_max;
struct drbd_conf *mdev;
int vnr;
kfree(acscw);
if (oc == C_STANDALONE && ns_max.conn == C_UNCONNECTED)
drbd_thread_start(&tconn->receiver);
if (oc == C_DISCONNECTING && ns_max.conn == C_STANDALONE) {
struct net_conf *old_conf;
mutex_lock(&tconn->conf_update);
old_conf = tconn->net_conf;
tconn->my_addr_len = 0;
tconn->peer_addr_len = 0;
rcu_assign_pointer(tconn->net_conf, NULL);
conn_free_crypto(tconn);
mutex_unlock(&tconn->conf_update);
synchronize_rcu();
kfree(old_conf);
}
if (ns_max.susp_fen) {
if (ns_max.pdsk <= D_OUTDATED) {
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
if (test_bit(NEW_CUR_UUID, &mdev->flags)) {
drbd_uuid_new_current(mdev);
clear_bit(NEW_CUR_UUID, &mdev->flags);
}
}
rcu_read_unlock();
spin_lock_irq(&tconn->req_lock);
_tl_restart(tconn, CONNECTION_LOST_WHILE_PENDING);
_conn_request_state(tconn,
(union drbd_state) { { .susp_fen = 1 } },
(union drbd_state) { { .susp_fen = 0 } },
CS_VERBOSE);
spin_unlock_irq(&tconn->req_lock);
}
}
kref_put(&tconn->kref, &conn_destroy);
conn_md_sync(tconn);
return 0;
}
void conn_old_common_state(struct drbd_tconn *tconn, union drbd_state *pcs, enum chg_state_flags *pf)
{
enum chg_state_flags flags = ~0;
struct drbd_conf *mdev;
int vnr, first_vol = 1;
union drbd_dev_state os, cs = {
{ .role = R_SECONDARY,
.peer = R_UNKNOWN,
.conn = tconn->cstate,
.disk = D_DISKLESS,
.pdsk = D_UNKNOWN,
} };
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
os = mdev->state;
if (first_vol) {
cs = os;
first_vol = 0;
continue;
}
if (cs.role != os.role)
flags &= ~CS_DC_ROLE;
if (cs.peer != os.peer)
flags &= ~CS_DC_PEER;
if (cs.conn != os.conn)
flags &= ~CS_DC_CONN;
if (cs.disk != os.disk)
flags &= ~CS_DC_DISK;
if (cs.pdsk != os.pdsk)
flags &= ~CS_DC_PDSK;
}
rcu_read_unlock();
*pf |= CS_DC_MASK;
*pf &= flags;
(*pcs).i = cs.i;
}
static enum drbd_state_rv
conn_is_valid_transition(struct drbd_tconn *tconn, union drbd_state mask, union drbd_state val,
enum chg_state_flags flags)
{
enum drbd_state_rv rv = SS_SUCCESS;
union drbd_state ns, os;
struct drbd_conf *mdev;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
os = drbd_read_state(mdev);
ns = sanitize_state(mdev, apply_mask_val(os, mask, val), NULL);
if (flags & CS_IGN_OUTD_FAIL && ns.disk == D_OUTDATED && os.disk < D_OUTDATED)
ns.disk = os.disk;
if (ns.i == os.i)
continue;
rv = is_valid_transition(os, ns);
if (rv < SS_SUCCESS)
break;
if (!(flags & CS_HARD)) {
rv = is_valid_state(mdev, ns);
if (rv < SS_SUCCESS) {
if (is_valid_state(mdev, os) == rv)
rv = is_valid_soft_transition(os, ns, tconn);
} else
rv = is_valid_soft_transition(os, ns, tconn);
}
if (rv < SS_SUCCESS)
break;
}
rcu_read_unlock();
if (rv < SS_SUCCESS && flags & CS_VERBOSE)
print_st_err(mdev, os, ns, rv);
return rv;
}
void
conn_set_state(struct drbd_tconn *tconn, union drbd_state mask, union drbd_state val,
union drbd_state *pns_min, union drbd_state *pns_max, enum chg_state_flags flags)
{
union drbd_state ns, os, ns_max = { };
union drbd_state ns_min = {
{ .role = R_MASK,
.peer = R_MASK,
.conn = val.conn,
.disk = D_MASK,
.pdsk = D_MASK
} };
struct drbd_conf *mdev;
enum drbd_state_rv rv;
int vnr, number_of_volumes = 0;
if (mask.conn == C_MASK) {
if (tconn->cstate != C_WF_REPORT_PARAMS && val.conn == C_WF_REPORT_PARAMS)
tconn->last_reconnect_jif = jiffies;
tconn->cstate = val.conn;
}
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
number_of_volumes++;
os = drbd_read_state(mdev);
ns = apply_mask_val(os, mask, val);
ns = sanitize_state(mdev, ns, NULL);
if (flags & CS_IGN_OUTD_FAIL && ns.disk == D_OUTDATED && os.disk < D_OUTDATED)
ns.disk = os.disk;
rv = __drbd_set_state(mdev, ns, flags, NULL);
if (rv < SS_SUCCESS)
BUG();
ns.i = mdev->state.i;
ns_max.role = max_role(ns.role, ns_max.role);
ns_max.peer = max_role(ns.peer, ns_max.peer);
ns_max.conn = max_t(enum drbd_conns, ns.conn, ns_max.conn);
ns_max.disk = max_t(enum drbd_disk_state, ns.disk, ns_max.disk);
ns_max.pdsk = max_t(enum drbd_disk_state, ns.pdsk, ns_max.pdsk);
ns_min.role = min_role(ns.role, ns_min.role);
ns_min.peer = min_role(ns.peer, ns_min.peer);
ns_min.conn = min_t(enum drbd_conns, ns.conn, ns_min.conn);
ns_min.disk = min_t(enum drbd_disk_state, ns.disk, ns_min.disk);
ns_min.pdsk = min_t(enum drbd_disk_state, ns.pdsk, ns_min.pdsk);
}
rcu_read_unlock();
if (number_of_volumes == 0) {
ns_min = ns_max = (union drbd_state) { {
.role = R_SECONDARY,
.peer = R_UNKNOWN,
.conn = val.conn,
.disk = D_DISKLESS,
.pdsk = D_UNKNOWN
} };
}
ns_min.susp = ns_max.susp = tconn->susp;
ns_min.susp_nod = ns_max.susp_nod = tconn->susp_nod;
ns_min.susp_fen = ns_max.susp_fen = tconn->susp_fen;
*pns_min = ns_min;
*pns_max = ns_max;
}
static enum drbd_state_rv
_conn_rq_cond(struct drbd_tconn *tconn, union drbd_state mask, union drbd_state val)
{
enum drbd_state_rv rv;
if (test_and_clear_bit(CONN_WD_ST_CHG_OKAY, &tconn->flags))
return SS_CW_SUCCESS;
if (test_and_clear_bit(CONN_WD_ST_CHG_FAIL, &tconn->flags))
return SS_CW_FAILED_BY_PEER;
rv = conn_is_valid_transition(tconn, mask, val, 0);
if (rv == SS_SUCCESS && tconn->cstate == C_WF_REPORT_PARAMS)
rv = SS_UNKNOWN_ERROR;
return rv;
}
enum drbd_state_rv
_conn_request_state(struct drbd_tconn *tconn, union drbd_state mask, union drbd_state val,
enum chg_state_flags flags)
{
enum drbd_state_rv rv = SS_SUCCESS;
struct after_conn_state_chg_work *acscw;
enum drbd_conns oc = tconn->cstate;
union drbd_state ns_max, ns_min, os;
bool have_mutex = false;
if (mask.conn) {
rv = is_valid_conn_transition(oc, val.conn);
if (rv < SS_SUCCESS)
goto abort;
}
rv = conn_is_valid_transition(tconn, mask, val, flags);
if (rv < SS_SUCCESS)
goto abort;
if (oc == C_WF_REPORT_PARAMS && val.conn == C_DISCONNECTING &&
!(flags & (CS_LOCAL_ONLY | CS_HARD))) {
spin_unlock_irq(&tconn->req_lock);
mutex_lock(&tconn->cstate_mutex);
have_mutex = true;
set_bit(CONN_WD_ST_CHG_REQ, &tconn->flags);
if (conn_send_state_req(tconn, mask, val)) {
clear_bit(CONN_WD_ST_CHG_REQ, &tconn->flags);
rv = SS_CW_FAILED_BY_PEER;
goto abort_unlocked;
}
if (val.conn == C_DISCONNECTING)
set_bit(DISCONNECT_SENT, &tconn->flags);
spin_lock_irq(&tconn->req_lock);
wait_event_lock_irq(tconn->ping_wait,
(rv = _conn_rq_cond(tconn, mask, val)),
tconn->req_lock);
clear_bit(CONN_WD_ST_CHG_REQ, &tconn->flags);
if (rv < SS_SUCCESS)
goto abort;
}
conn_old_common_state(tconn, &os, &flags);
flags |= CS_DC_SUSP;
conn_set_state(tconn, mask, val, &ns_min, &ns_max, flags);
conn_pr_state_change(tconn, os, ns_max, flags);
acscw = kmalloc(sizeof(*acscw), GFP_ATOMIC);
if (acscw) {
acscw->oc = os.conn;
acscw->ns_min = ns_min;
acscw->ns_max = ns_max;
acscw->flags = flags;
acscw->w.cb = w_after_conn_state_ch;
kref_get(&tconn->kref);
acscw->w.tconn = tconn;
drbd_queue_work(&tconn->sender_work, &acscw->w);
} else {
conn_err(tconn, "Could not kmalloc an acscw\n");
}
abort:
if (have_mutex) {
spin_unlock_irq(&tconn->req_lock);
abort_unlocked:
mutex_unlock(&tconn->cstate_mutex);
spin_lock_irq(&tconn->req_lock);
}
if (rv < SS_SUCCESS && flags & CS_VERBOSE) {
conn_err(tconn, "State change failed: %s\n", drbd_set_st_err_str(rv));
conn_err(tconn, " mask = 0x%x val = 0x%x\n", mask.i, val.i);
conn_err(tconn, " old_conn:%s wanted_conn:%s\n", drbd_conn_str(oc), drbd_conn_str(val.conn));
}
return rv;
}
enum drbd_state_rv
conn_request_state(struct drbd_tconn *tconn, union drbd_state mask, union drbd_state val,
enum chg_state_flags flags)
{
enum drbd_state_rv rv;
spin_lock_irq(&tconn->req_lock);
rv = _conn_request_state(tconn, mask, val, flags);
spin_unlock_irq(&tconn->req_lock);
return rv;
}
