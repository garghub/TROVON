int obd_connect_flags2str(char *page, int count, __u64 flags, char *sep)
{
__u64 mask = 1;
int i, ret = 0;
for (i = 0; obd_connect_names[i] != NULL; i++, mask <<= 1) {
if (flags & mask)
ret += snprintf(page + ret, count - ret, "%s%s",
ret ? sep : "", obd_connect_names[i]);
}
if (flags & ~(mask - 1))
ret += snprintf(page + ret, count - ret,
"%sunknown flags %#llx",
ret ? sep : "", flags & ~(mask - 1));
return ret;
}
int lprocfs_read_frac_helper(char *buffer, unsigned long count, long val,
int mult)
{
long decimal_val, frac_val;
int prtn;
if (count < 10)
return -EINVAL;
decimal_val = val / mult;
prtn = snprintf(buffer, count, "%ld", decimal_val);
frac_val = val % mult;
if (prtn < (count - 4) && frac_val > 0) {
long temp_frac;
int i, temp_mult = 1, frac_bits = 0;
temp_frac = frac_val * 10;
buffer[prtn++] = '.';
while (frac_bits < 2 && (temp_frac / mult) < 1) {
buffer[prtn++] = '0';
temp_frac *= 10;
frac_bits++;
}
for (i = 0; i < (5 - prtn); i++)
temp_mult *= 10;
frac_bits = min((int)count - prtn, 3 - frac_bits);
prtn += snprintf(buffer + prtn, frac_bits, "%ld",
frac_val * temp_mult / mult);
prtn--;
while (buffer[prtn] < '1' || buffer[prtn] > '9') {
prtn--;
if (buffer[prtn] == '.') {
prtn--;
break;
}
}
prtn++;
}
buffer[prtn++] = '\n';
return prtn;
}
int lprocfs_write_frac_helper(const char __user *buffer, unsigned long count,
int *val, int mult)
{
char kernbuf[20], *end, *pbuf;
if (count > (sizeof(kernbuf) - 1))
return -EINVAL;
if (copy_from_user(kernbuf, buffer, count))
return -EFAULT;
kernbuf[count] = '\0';
pbuf = kernbuf;
if (*pbuf == '-') {
mult = -mult;
pbuf++;
}
*val = (int)simple_strtoul(pbuf, &end, 10) * mult;
if (pbuf == end)
return -EINVAL;
if (end != NULL && *end == '.') {
int temp_val, pow = 1;
int i;
pbuf = end + 1;
if (strlen(pbuf) > 5)
pbuf[5] = '\0';
temp_val = (int)simple_strtoul(pbuf, &end, 10) * mult;
if (pbuf < end) {
for (i = 0; i < (end - pbuf); i++)
pow *= 10;
*val += temp_val / pow;
}
}
return 0;
}
int lprocfs_single_release(struct inode *inode, struct file *file)
{
return single_release(inode, file);
}
int lprocfs_seq_release(struct inode *inode, struct file *file)
{
return seq_release(inode, file);
}
struct dentry *ldebugfs_add_simple(struct dentry *root,
char *name, void *data,
struct file_operations *fops)
{
struct dentry *entry;
umode_t mode = 0;
if (root == NULL || name == NULL || fops == NULL)
return ERR_PTR(-EINVAL);
if (fops->read)
mode = 0444;
if (fops->write)
mode |= 0200;
entry = debugfs_create_file(name, mode, root, data, fops);
if (IS_ERR_OR_NULL(entry)) {
CERROR("LprocFS: No memory to create <debugfs> entry %s", name);
return entry ?: ERR_PTR(-ENOMEM);
}
return entry;
}
struct dentry *ldebugfs_add_symlink(const char *name, struct dentry *parent,
const char *format, ...)
{
struct dentry *entry;
char *dest;
va_list ap;
if (parent == NULL || format == NULL)
return NULL;
dest = kzalloc(MAX_STRING_SIZE + 1, GFP_KERNEL);
if (dest == NULL)
return NULL;
va_start(ap, format);
vsnprintf(dest, MAX_STRING_SIZE, format, ap);
va_end(ap);
entry = debugfs_create_symlink(name, parent, dest);
if (IS_ERR_OR_NULL(entry)) {
CERROR("LdebugFS: Could not create symbolic link from %s to %s",
name, dest);
entry = NULL;
}
kfree(dest);
return entry;
}
int ldebugfs_add_vars(struct dentry *parent,
struct lprocfs_vars *list,
void *data)
{
if (IS_ERR_OR_NULL(parent) || IS_ERR_OR_NULL(list))
return -EINVAL;
while (list->name != NULL) {
struct dentry *entry;
umode_t mode = 0;
if (list->proc_mode != 0000) {
mode = list->proc_mode;
} else if (list->fops) {
if (list->fops->read)
mode = 0444;
if (list->fops->write)
mode |= 0200;
}
entry = debugfs_create_file(list->name, mode, parent,
list->data ?: data,
list->fops ?: &lprocfs_generic_fops
);
if (IS_ERR_OR_NULL(entry))
return entry ? PTR_ERR(entry) : -ENOMEM;
list++;
}
return 0;
}
void ldebugfs_remove(struct dentry **entryp)
{
debugfs_remove(*entryp);
*entryp = NULL;
}
struct dentry *ldebugfs_register(const char *name,
struct dentry *parent,
struct lprocfs_vars *list, void *data)
{
struct dentry *entry;
entry = debugfs_create_dir(name, parent);
if (IS_ERR_OR_NULL(entry)) {
entry = entry ?: ERR_PTR(-ENOMEM);
goto out;
}
if (!IS_ERR_OR_NULL(list)) {
int rc;
rc = ldebugfs_add_vars(entry, list, data);
if (rc != 0) {
debugfs_remove(entry);
entry = ERR_PTR(rc);
}
}
out:
return entry;
}
int lprocfs_rd_uint(struct seq_file *m, void *data)
{
seq_printf(m, "%u\n", *(unsigned int *)data);
return 0;
}
int lprocfs_wr_uint(struct file *file, const char __user *buffer,
unsigned long count, void *data)
{
unsigned *p = data;
char dummy[MAX_STRING_SIZE + 1], *end;
unsigned long tmp;
dummy[MAX_STRING_SIZE] = '\0';
if (copy_from_user(dummy, buffer, MAX_STRING_SIZE))
return -EFAULT;
tmp = simple_strtoul(dummy, &end, 0);
if (dummy == end)
return -EINVAL;
*p = (unsigned int)tmp;
return count;
}
int lprocfs_rd_u64(struct seq_file *m, void *data)
{
seq_printf(m, "%llu\n", *(__u64 *)data);
return 0;
}
int lprocfs_rd_atomic(struct seq_file *m, void *data)
{
atomic_t *atom = data;
LASSERT(atom != NULL);
seq_printf(m, "%d\n", atomic_read(atom));
return 0;
}
int lprocfs_wr_atomic(struct file *file, const char __user *buffer,
unsigned long count, void *data)
{
atomic_t *atm = data;
int val = 0;
int rc;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc < 0)
return rc;
if (val <= 0)
return -ERANGE;
atomic_set(atm, val);
return count;
}
static ssize_t uuid_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *obd = container_of(kobj, struct obd_device,
obd_kobj);
return sprintf(buf, "%s\n", obd->obd_uuid.uuid);
}
int lprocfs_rd_name(struct seq_file *m, void *data)
{
struct obd_device *dev = data;
LASSERT(dev != NULL);
seq_printf(m, "%s\n", dev->obd_name);
return 0;
}
static ssize_t blocksize_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *obd = container_of(kobj, struct obd_device,
obd_kobj);
struct obd_statfs osfs;
int rc = obd_statfs(NULL, obd->obd_self_export, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc)
return sprintf(buf, "%u\n", osfs.os_bsize);
return rc;
}
static ssize_t kbytestotal_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *obd = container_of(kobj, struct obd_device,
obd_kobj);
struct obd_statfs osfs;
int rc = obd_statfs(NULL, obd->obd_self_export, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc) {
__u32 blk_size = osfs.os_bsize >> 10;
__u64 result = osfs.os_blocks;
while (blk_size >>= 1)
result <<= 1;
return sprintf(buf, "%llu\n", result);
}
return rc;
}
static ssize_t kbytesfree_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *obd = container_of(kobj, struct obd_device,
obd_kobj);
struct obd_statfs osfs;
int rc = obd_statfs(NULL, obd->obd_self_export, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc) {
__u32 blk_size = osfs.os_bsize >> 10;
__u64 result = osfs.os_bfree;
while (blk_size >>= 1)
result <<= 1;
return sprintf(buf, "%llu\n", result);
}
return rc;
}
static ssize_t kbytesavail_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *obd = container_of(kobj, struct obd_device,
obd_kobj);
struct obd_statfs osfs;
int rc = obd_statfs(NULL, obd->obd_self_export, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc) {
__u32 blk_size = osfs.os_bsize >> 10;
__u64 result = osfs.os_bavail;
while (blk_size >>= 1)
result <<= 1;
return sprintf(buf, "%llu\n", result);
}
return rc;
}
static ssize_t filestotal_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *obd = container_of(kobj, struct obd_device,
obd_kobj);
struct obd_statfs osfs;
int rc = obd_statfs(NULL, obd->obd_self_export, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc)
return sprintf(buf, "%llu\n", osfs.os_files);
return rc;
}
static ssize_t filesfree_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *obd = container_of(kobj, struct obd_device,
obd_kobj);
struct obd_statfs osfs;
int rc = obd_statfs(NULL, obd->obd_self_export, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc)
return sprintf(buf, "%llu\n", osfs.os_ffree);
return rc;
}
int lprocfs_rd_server_uuid(struct seq_file *m, void *data)
{
struct obd_device *obd = data;
struct obd_import *imp;
char *imp_state_name = NULL;
LASSERT(obd != NULL);
LPROCFS_CLIMP_CHECK(obd);
imp = obd->u.cli.cl_import;
imp_state_name = ptlrpc_import_state_name(imp->imp_state);
seq_printf(m, "%s\t%s%s\n",
obd2cli_tgt(obd), imp_state_name,
imp->imp_deactive ? "\tDEACTIVATED" : "");
LPROCFS_CLIMP_EXIT(obd);
return 0;
}
int lprocfs_rd_conn_uuid(struct seq_file *m, void *data)
{
struct obd_device *obd = data;
struct ptlrpc_connection *conn;
LASSERT(obd != NULL);
LPROCFS_CLIMP_CHECK(obd);
conn = obd->u.cli.cl_import->imp_connection;
if (conn && obd->u.cli.cl_import)
seq_printf(m, "%s\n", conn->c_remote_uuid.uuid);
else
seq_puts(m, "<none>\n");
LPROCFS_CLIMP_EXIT(obd);
return 0;
}
void lprocfs_stats_collect(struct lprocfs_stats *stats, int idx,
struct lprocfs_counter *cnt)
{
unsigned int num_entry;
struct lprocfs_counter *percpu_cntr;
int i;
unsigned long flags = 0;
memset(cnt, 0, sizeof(*cnt));
if (stats == NULL) {
cnt->lc_count = 1;
return;
}
cnt->lc_min = LC_MIN_INIT;
num_entry = lprocfs_stats_lock(stats, LPROCFS_GET_NUM_CPU, &flags);
for (i = 0; i < num_entry; i++) {
if (stats->ls_percpu[i] == NULL)
continue;
percpu_cntr = lprocfs_stats_counter_get(stats, i, idx);
cnt->lc_count += percpu_cntr->lc_count;
cnt->lc_sum += percpu_cntr->lc_sum;
if (percpu_cntr->lc_min < cnt->lc_min)
cnt->lc_min = percpu_cntr->lc_min;
if (percpu_cntr->lc_max > cnt->lc_max)
cnt->lc_max = percpu_cntr->lc_max;
cnt->lc_sumsquare += percpu_cntr->lc_sumsquare;
}
lprocfs_stats_unlock(stats, LPROCFS_GET_NUM_CPU, &flags);
}
static int obd_import_flags2str(struct obd_import *imp, struct seq_file *m)
{
bool first = true;
if (imp->imp_obd->obd_no_recov) {
seq_printf(m, "no_recov");
first = false;
}
flag2str(invalid, first);
first = false;
flag2str(deactive, first);
flag2str(replayable, first);
flag2str(pingable, first);
return 0;
}
static void obd_connect_seq_flags2str(struct seq_file *m, __u64 flags, char *sep)
{
__u64 mask = 1;
int i;
bool first = true;
for (i = 0; obd_connect_names[i] != NULL; i++, mask <<= 1) {
if (flags & mask) {
seq_printf(m, "%s%s",
first ? sep : "", obd_connect_names[i]);
first = false;
}
}
if (flags & ~(mask - 1))
seq_printf(m, "%sunknown flags %#llx",
first ? sep : "", flags & ~(mask - 1));
}
int lprocfs_rd_import(struct seq_file *m, void *data)
{
struct lprocfs_counter ret;
struct lprocfs_counter_header *header;
struct obd_device *obd = (struct obd_device *)data;
struct obd_import *imp;
struct obd_import_conn *conn;
int j;
int k;
int rw = 0;
LASSERT(obd != NULL);
LPROCFS_CLIMP_CHECK(obd);
imp = obd->u.cli.cl_import;
seq_printf(m,
"import:\n"
" name: %s\n"
" target: %s\n"
" state: %s\n"
" instance: %u\n"
" connect_flags: [",
obd->obd_name,
obd2cli_tgt(obd),
ptlrpc_import_state_name(imp->imp_state),
imp->imp_connect_data.ocd_instance);
obd_connect_seq_flags2str(m, imp->imp_connect_data.ocd_connect_flags, ", ");
seq_printf(m,
"]\n"
" import_flags: [");
obd_import_flags2str(imp, m);
seq_printf(m,
"]\n"
" connection:\n"
" failover_nids: [");
spin_lock(&imp->imp_lock);
j = 0;
list_for_each_entry(conn, &imp->imp_conn_list, oic_item) {
seq_printf(m, "%s%s", j ? ", " : "",
libcfs_nid2str(conn->oic_conn->c_peer.nid));
j++;
}
seq_printf(m,
"]\n"
" current_connection: %s\n"
" connection_attempts: %u\n"
" generation: %u\n"
" in-progress_invalidations: %u\n",
imp->imp_connection == NULL ? "<none>" :
libcfs_nid2str(imp->imp_connection->c_peer.nid),
imp->imp_conn_cnt,
imp->imp_generation,
atomic_read(&imp->imp_inval_count));
spin_unlock(&imp->imp_lock);
if (obd->obd_svc_stats == NULL)
goto out_climp;
header = &obd->obd_svc_stats->ls_cnt_header[PTLRPC_REQWAIT_CNTR];
lprocfs_stats_collect(obd->obd_svc_stats, PTLRPC_REQWAIT_CNTR, &ret);
if (ret.lc_count != 0) {
__u64 sum = ret.lc_sum;
do_div(sum, ret.lc_count);
ret.lc_sum = sum;
} else
ret.lc_sum = 0;
seq_printf(m,
" rpcs:\n"
" inflight: %u\n"
" unregistering: %u\n"
" timeouts: %u\n"
" avg_waittime: %llu %s\n",
atomic_read(&imp->imp_inflight),
atomic_read(&imp->imp_unregistering),
atomic_read(&imp->imp_timeouts),
ret.lc_sum, header->lc_units);
k = 0;
for (j = 0; j < IMP_AT_MAX_PORTALS; j++) {
if (imp->imp_at.iat_portal[j] == 0)
break;
k = max_t(unsigned int, k,
at_get(&imp->imp_at.iat_service_estimate[j]));
}
seq_printf(m,
" service_estimates:\n"
" services: %u sec\n"
" network: %u sec\n",
k,
at_get(&imp->imp_at.iat_net_latency));
seq_printf(m,
" transactions:\n"
" last_replay: %llu\n"
" peer_committed: %llu\n"
" last_checked: %llu\n",
imp->imp_last_replay_transno,
imp->imp_peer_committed_transno,
imp->imp_last_transno_checked);
for (rw = 0; rw <= 1; rw++) {
lprocfs_stats_collect(obd->obd_svc_stats,
PTLRPC_LAST_CNTR + BRW_READ_BYTES + rw,
&ret);
if (ret.lc_sum > 0 && ret.lc_count > 0) {
__u64 sum = ret.lc_sum;
do_div(sum, ret.lc_count);
ret.lc_sum = sum;
seq_printf(m,
" %s_data_averages:\n"
" bytes_per_rpc: %llu\n",
rw ? "write" : "read",
ret.lc_sum);
}
k = (int)ret.lc_sum;
j = opcode_offset(OST_READ + rw) + EXTRA_MAX_OPCODES;
header = &obd->obd_svc_stats->ls_cnt_header[j];
lprocfs_stats_collect(obd->obd_svc_stats, j, &ret);
if (ret.lc_sum > 0 && ret.lc_count != 0) {
__u64 sum = ret.lc_sum;
do_div(sum, ret.lc_count);
ret.lc_sum = sum;
seq_printf(m,
" %s_per_rpc: %llu\n",
header->lc_units, ret.lc_sum);
j = (int)ret.lc_sum;
if (j > 0)
seq_printf(m,
" MB_per_sec: %u.%.02u\n",
k / j, (100 * k / j) % 100);
}
}
out_climp:
LPROCFS_CLIMP_EXIT(obd);
return 0;
}
int lprocfs_rd_state(struct seq_file *m, void *data)
{
struct obd_device *obd = (struct obd_device *)data;
struct obd_import *imp;
int j, k;
LASSERT(obd != NULL);
LPROCFS_CLIMP_CHECK(obd);
imp = obd->u.cli.cl_import;
seq_printf(m, "current_state: %s\n",
ptlrpc_import_state_name(imp->imp_state));
seq_printf(m, "state_history:\n");
k = imp->imp_state_hist_idx;
for (j = 0; j < IMP_STATE_HIST_LEN; j++) {
struct import_state_hist *ish =
&imp->imp_state_hist[(k + j) % IMP_STATE_HIST_LEN];
if (ish->ish_state == 0)
continue;
seq_printf(m, " - ["CFS_TIME_T", %s]\n",
ish->ish_time,
ptlrpc_import_state_name(ish->ish_state));
}
LPROCFS_CLIMP_EXIT(obd);
return 0;
}
int lprocfs_at_hist_helper(struct seq_file *m, struct adaptive_timeout *at)
{
int i;
for (i = 0; i < AT_BINS; i++)
seq_printf(m, "%3u ", at->at_hist[i]);
seq_printf(m, "\n");
return 0;
}
int lprocfs_rd_timeouts(struct seq_file *m, void *data)
{
struct obd_device *obd = (struct obd_device *)data;
struct obd_import *imp;
unsigned int cur, worst;
time_t now, worstt;
struct dhms ts;
int i;
LASSERT(obd != NULL);
LPROCFS_CLIMP_CHECK(obd);
imp = obd->u.cli.cl_import;
now = get_seconds();
s2dhms(&ts, now - imp->imp_last_reply_time);
seq_printf(m, "%-10s : %ld, "DHMS_FMT" ago\n",
"last reply", imp->imp_last_reply_time, DHMS_VARS(&ts));
cur = at_get(&imp->imp_at.iat_net_latency);
worst = imp->imp_at.iat_net_latency.at_worst_ever;
worstt = imp->imp_at.iat_net_latency.at_worst_time;
s2dhms(&ts, now - worstt);
seq_printf(m, "%-10s : cur %3u worst %3u (at %ld, "DHMS_FMT" ago) ",
"network", cur, worst, worstt, DHMS_VARS(&ts));
lprocfs_at_hist_helper(m, &imp->imp_at.iat_net_latency);
for (i = 0; i < IMP_AT_MAX_PORTALS; i++) {
if (imp->imp_at.iat_portal[i] == 0)
break;
cur = at_get(&imp->imp_at.iat_service_estimate[i]);
worst = imp->imp_at.iat_service_estimate[i].at_worst_ever;
worstt = imp->imp_at.iat_service_estimate[i].at_worst_time;
s2dhms(&ts, now - worstt);
seq_printf(m, "portal %-2d : cur %3u worst %3u (at %ld, "
DHMS_FMT" ago) ", imp->imp_at.iat_portal[i],
cur, worst, worstt, DHMS_VARS(&ts));
lprocfs_at_hist_helper(m, &imp->imp_at.iat_service_estimate[i]);
}
LPROCFS_CLIMP_EXIT(obd);
return 0;
}
int lprocfs_rd_connect_flags(struct seq_file *m, void *data)
{
struct obd_device *obd = data;
__u64 flags;
LPROCFS_CLIMP_CHECK(obd);
flags = obd->u.cli.cl_import->imp_connect_data.ocd_connect_flags;
seq_printf(m, "flags=%#llx\n", flags);
obd_connect_seq_flags2str(m, flags, "\n");
seq_printf(m, "\n");
LPROCFS_CLIMP_EXIT(obd);
return 0;
}
static void obd_sysfs_release(struct kobject *kobj)
{
struct obd_device *obd = container_of(kobj, struct obd_device,
obd_kobj);
complete(&obd->obd_kobj_unregister);
}
int lprocfs_obd_setup(struct obd_device *obd, struct lprocfs_vars *list,
struct attribute_group *attrs)
{
int rc = 0;
init_completion(&obd->obd_kobj_unregister);
rc = kobject_init_and_add(&obd->obd_kobj, &obd_ktype,
obd->obd_type->typ_kobj,
"%s", obd->obd_name);
if (rc)
return rc;
if (attrs) {
rc = sysfs_create_group(&obd->obd_kobj, attrs);
if (rc) {
kobject_put(&obd->obd_kobj);
return rc;
}
}
obd->obd_debugfs_entry = ldebugfs_register(obd->obd_name,
obd->obd_type->typ_debugfs_entry,
list, obd);
if (IS_ERR_OR_NULL(obd->obd_debugfs_entry)) {
rc = obd->obd_debugfs_entry ? PTR_ERR(obd->obd_debugfs_entry)
: -ENOMEM;
CERROR("error %d setting up lprocfs for %s\n",
rc, obd->obd_name);
obd->obd_debugfs_entry = NULL;
}
return rc;
}
int lprocfs_obd_cleanup(struct obd_device *obd)
{
if (!obd)
return -EINVAL;
if (!IS_ERR_OR_NULL(obd->obd_debugfs_entry))
ldebugfs_remove(&obd->obd_debugfs_entry);
kobject_put(&obd->obd_kobj);
wait_for_completion(&obd->obd_kobj_unregister);
return 0;
}
int lprocfs_stats_alloc_one(struct lprocfs_stats *stats, unsigned int cpuid)
{
struct lprocfs_counter *cntr;
unsigned int percpusize;
int rc = -ENOMEM;
unsigned long flags = 0;
int i;
LASSERT(stats->ls_percpu[cpuid] == NULL);
LASSERT((stats->ls_flags & LPROCFS_STATS_FLAG_NOPERCPU) == 0);
percpusize = lprocfs_stats_counter_size(stats);
LIBCFS_ALLOC_ATOMIC(stats->ls_percpu[cpuid], percpusize);
if (stats->ls_percpu[cpuid] != NULL) {
rc = 0;
if (unlikely(stats->ls_biggest_alloc_num <= cpuid)) {
if (stats->ls_flags & LPROCFS_STATS_FLAG_IRQ_SAFE)
spin_lock_irqsave(&stats->ls_lock, flags);
else
spin_lock(&stats->ls_lock);
if (stats->ls_biggest_alloc_num <= cpuid)
stats->ls_biggest_alloc_num = cpuid + 1;
if (stats->ls_flags & LPROCFS_STATS_FLAG_IRQ_SAFE)
spin_unlock_irqrestore(&stats->ls_lock, flags);
else
spin_unlock(&stats->ls_lock);
}
for (i = 0; i < stats->ls_num; ++i) {
cntr = lprocfs_stats_counter_get(stats, cpuid, i);
cntr->lc_min = LC_MIN_INIT;
}
}
return rc;
}
struct lprocfs_stats *lprocfs_alloc_stats(unsigned int num,
enum lprocfs_stats_flags flags)
{
struct lprocfs_stats *stats;
unsigned int num_entry;
unsigned int percpusize = 0;
int i;
if (num == 0)
return NULL;
if (lprocfs_no_percpu_stats != 0)
flags |= LPROCFS_STATS_FLAG_NOPERCPU;
if (flags & LPROCFS_STATS_FLAG_NOPERCPU)
num_entry = 1;
else
num_entry = num_possible_cpus();
LIBCFS_ALLOC(stats, offsetof(typeof(*stats), ls_percpu[num_entry]));
if (stats == NULL)
return NULL;
stats->ls_num = num;
stats->ls_flags = flags;
spin_lock_init(&stats->ls_lock);
LIBCFS_ALLOC(stats->ls_cnt_header,
stats->ls_num * sizeof(struct lprocfs_counter_header));
if (stats->ls_cnt_header == NULL)
goto fail;
if ((flags & LPROCFS_STATS_FLAG_NOPERCPU) != 0) {
percpusize = lprocfs_stats_counter_size(stats);
LIBCFS_ALLOC_ATOMIC(stats->ls_percpu[0], percpusize);
if (stats->ls_percpu[0] == NULL)
goto fail;
stats->ls_biggest_alloc_num = 1;
} else if ((flags & LPROCFS_STATS_FLAG_IRQ_SAFE) != 0) {
for (i = 0; i < num_entry; ++i)
if (lprocfs_stats_alloc_one(stats, i) < 0)
goto fail;
}
return stats;
fail:
lprocfs_free_stats(&stats);
return NULL;
}
void lprocfs_free_stats(struct lprocfs_stats **statsh)
{
struct lprocfs_stats *stats = *statsh;
unsigned int num_entry;
unsigned int percpusize;
unsigned int i;
if (stats == NULL || stats->ls_num == 0)
return;
*statsh = NULL;
if (stats->ls_flags & LPROCFS_STATS_FLAG_NOPERCPU)
num_entry = 1;
else
num_entry = num_possible_cpus();
percpusize = lprocfs_stats_counter_size(stats);
for (i = 0; i < num_entry; i++)
if (stats->ls_percpu[i] != NULL)
LIBCFS_FREE(stats->ls_percpu[i], percpusize);
if (stats->ls_cnt_header != NULL)
LIBCFS_FREE(stats->ls_cnt_header, stats->ls_num *
sizeof(struct lprocfs_counter_header));
LIBCFS_FREE(stats, offsetof(typeof(*stats), ls_percpu[num_entry]));
}
void lprocfs_clear_stats(struct lprocfs_stats *stats)
{
struct lprocfs_counter *percpu_cntr;
int i;
int j;
unsigned int num_entry;
unsigned long flags = 0;
num_entry = lprocfs_stats_lock(stats, LPROCFS_GET_NUM_CPU, &flags);
for (i = 0; i < num_entry; i++) {
if (stats->ls_percpu[i] == NULL)
continue;
for (j = 0; j < stats->ls_num; j++) {
percpu_cntr = lprocfs_stats_counter_get(stats, i, j);
percpu_cntr->lc_count = 0;
percpu_cntr->lc_min = LC_MIN_INIT;
percpu_cntr->lc_max = 0;
percpu_cntr->lc_sumsquare = 0;
percpu_cntr->lc_sum = 0;
if (stats->ls_flags & LPROCFS_STATS_FLAG_IRQ_SAFE)
percpu_cntr->lc_sum_irq = 0;
}
}
lprocfs_stats_unlock(stats, LPROCFS_GET_NUM_CPU, &flags);
}
static ssize_t lprocfs_stats_seq_write(struct file *file,
const char __user *buf,
size_t len, loff_t *off)
{
struct seq_file *seq = file->private_data;
struct lprocfs_stats *stats = seq->private;
lprocfs_clear_stats(stats);
return len;
}
static void *lprocfs_stats_seq_start(struct seq_file *p, loff_t *pos)
{
struct lprocfs_stats *stats = p->private;
return (*pos < stats->ls_num) ? pos : NULL;
}
static void lprocfs_stats_seq_stop(struct seq_file *p, void *v)
{
}
static void *lprocfs_stats_seq_next(struct seq_file *p, void *v, loff_t *pos)
{
(*pos)++;
return lprocfs_stats_seq_start(p, pos);
}
static int lprocfs_stats_seq_show(struct seq_file *p, void *v)
{
struct lprocfs_stats *stats = p->private;
struct lprocfs_counter_header *hdr;
struct lprocfs_counter ctr;
int idx = *(loff_t *)v;
if (idx == 0) {
struct timeval now;
do_gettimeofday(&now);
seq_printf(p, "%-25s %lu.%lu secs.usecs\n",
"snapshot_time",
now.tv_sec, (unsigned long)now.tv_usec);
}
hdr = &stats->ls_cnt_header[idx];
lprocfs_stats_collect(stats, idx, &ctr);
if (ctr.lc_count != 0) {
seq_printf(p, "%-25s %lld samples [%s]",
hdr->lc_name, ctr.lc_count, hdr->lc_units);
if ((hdr->lc_config & LPROCFS_CNTR_AVGMINMAX) &&
(ctr.lc_count > 0)) {
seq_printf(p, " %lld %lld %lld",
ctr.lc_min, ctr.lc_max, ctr.lc_sum);
if (hdr->lc_config & LPROCFS_CNTR_STDDEV)
seq_printf(p, " %lld", ctr.lc_sumsquare);
}
seq_putc(p, '\n');
}
return 0;
}
static int lprocfs_stats_seq_open(struct inode *inode, struct file *file)
{
struct seq_file *seq;
int rc;
rc = seq_open(file, &lprocfs_stats_seq_sops);
if (rc)
return rc;
seq = file->private_data;
seq->private = inode->i_private;
return 0;
}
int ldebugfs_register_stats(struct dentry *parent, const char *name,
struct lprocfs_stats *stats)
{
struct dentry *entry;
LASSERT(!IS_ERR_OR_NULL(parent));
entry = debugfs_create_file(name, 0644, parent, stats,
&lprocfs_stats_seq_fops);
if (IS_ERR_OR_NULL(entry))
return entry ? PTR_ERR(entry) : -ENOMEM;
return 0;
}
void lprocfs_counter_init(struct lprocfs_stats *stats, int index,
unsigned conf, const char *name, const char *units)
{
struct lprocfs_counter_header *header;
struct lprocfs_counter *percpu_cntr;
unsigned long flags = 0;
unsigned int i;
unsigned int num_cpu;
LASSERT(stats != NULL);
header = &stats->ls_cnt_header[index];
LASSERTF(header != NULL, "Failed to allocate stats header:[%d]%s/%s\n",
index, name, units);
header->lc_config = conf;
header->lc_name = name;
header->lc_units = units;
num_cpu = lprocfs_stats_lock(stats, LPROCFS_GET_NUM_CPU, &flags);
for (i = 0; i < num_cpu; ++i) {
if (stats->ls_percpu[i] == NULL)
continue;
percpu_cntr = lprocfs_stats_counter_get(stats, i, index);
percpu_cntr->lc_count = 0;
percpu_cntr->lc_min = LC_MIN_INIT;
percpu_cntr->lc_max = 0;
percpu_cntr->lc_sumsquare = 0;
percpu_cntr->lc_sum = 0;
if ((stats->ls_flags & LPROCFS_STATS_FLAG_IRQ_SAFE) != 0)
percpu_cntr->lc_sum_irq = 0;
}
lprocfs_stats_unlock(stats, LPROCFS_GET_NUM_CPU, &flags);
}
void lprocfs_init_ops_stats(int num_private_stats, struct lprocfs_stats *stats)
{
LPROCFS_OBD_OP_INIT(num_private_stats, stats, iocontrol);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, get_info);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, set_info_async);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, attach);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, detach);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, setup);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, precleanup);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, cleanup);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, process_config);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, postrecov);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, add_conn);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, del_conn);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, connect);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, reconnect);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, disconnect);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, fid_init);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, fid_fini);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, fid_alloc);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, statfs);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, statfs_async);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, packmd);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, unpackmd);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, preallocate);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, create);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, destroy);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, setattr);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, setattr_async);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, getattr);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, getattr_async);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, adjust_kms);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, preprw);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, commitrw);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, find_cbdata);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, init_export);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, destroy_export);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, import_event);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, notify);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, health_check);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, get_uuid);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, quotacheck);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, quotactl);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, pool_new);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, pool_rem);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, pool_add);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, pool_del);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, getref);
LPROCFS_OBD_OP_INIT(num_private_stats, stats, putref);
}
int lprocfs_alloc_obd_stats(struct obd_device *obd, unsigned num_private_stats)
{
struct lprocfs_stats *stats;
unsigned int num_stats;
int rc, i;
LASSERT(obd->obd_stats == NULL);
LASSERT(obd->obd_debugfs_entry != NULL);
LASSERT(obd->obd_cntr_base == 0);
num_stats = ((int)sizeof(*obd->obd_type->typ_dt_ops) / sizeof(void *)) +
num_private_stats - 1 ;
stats = lprocfs_alloc_stats(num_stats, 0);
if (stats == NULL)
return -ENOMEM;
lprocfs_init_ops_stats(num_private_stats, stats);
for (i = num_private_stats; i < num_stats; i++) {
LASSERTF(stats->ls_cnt_header[i].lc_name != NULL,
"Missing obd_stat initializer obd_op operation at offset %d.\n",
i - num_private_stats);
}
rc = ldebugfs_register_stats(obd->obd_debugfs_entry, "stats", stats);
if (rc < 0) {
lprocfs_free_stats(&stats);
} else {
obd->obd_stats = stats;
obd->obd_cntr_base = num_private_stats;
}
return rc;
}
void lprocfs_free_obd_stats(struct obd_device *obd)
{
if (obd->obd_stats)
lprocfs_free_stats(&obd->obd_stats);
}
void lprocfs_init_mps_stats(int num_private_stats, struct lprocfs_stats *stats)
{
LPROCFS_MD_OP_INIT(num_private_stats, stats, getstatus);
LPROCFS_MD_OP_INIT(num_private_stats, stats, null_inode);
LPROCFS_MD_OP_INIT(num_private_stats, stats, find_cbdata);
LPROCFS_MD_OP_INIT(num_private_stats, stats, close);
LPROCFS_MD_OP_INIT(num_private_stats, stats, create);
LPROCFS_MD_OP_INIT(num_private_stats, stats, done_writing);
LPROCFS_MD_OP_INIT(num_private_stats, stats, enqueue);
LPROCFS_MD_OP_INIT(num_private_stats, stats, getattr);
LPROCFS_MD_OP_INIT(num_private_stats, stats, getattr_name);
LPROCFS_MD_OP_INIT(num_private_stats, stats, intent_lock);
LPROCFS_MD_OP_INIT(num_private_stats, stats, link);
LPROCFS_MD_OP_INIT(num_private_stats, stats, rename);
LPROCFS_MD_OP_INIT(num_private_stats, stats, is_subdir);
LPROCFS_MD_OP_INIT(num_private_stats, stats, setattr);
LPROCFS_MD_OP_INIT(num_private_stats, stats, sync);
LPROCFS_MD_OP_INIT(num_private_stats, stats, readpage);
LPROCFS_MD_OP_INIT(num_private_stats, stats, unlink);
LPROCFS_MD_OP_INIT(num_private_stats, stats, setxattr);
LPROCFS_MD_OP_INIT(num_private_stats, stats, getxattr);
LPROCFS_MD_OP_INIT(num_private_stats, stats, init_ea_size);
LPROCFS_MD_OP_INIT(num_private_stats, stats, get_lustre_md);
LPROCFS_MD_OP_INIT(num_private_stats, stats, free_lustre_md);
LPROCFS_MD_OP_INIT(num_private_stats, stats, set_open_replay_data);
LPROCFS_MD_OP_INIT(num_private_stats, stats, clear_open_replay_data);
LPROCFS_MD_OP_INIT(num_private_stats, stats, set_lock_data);
LPROCFS_MD_OP_INIT(num_private_stats, stats, lock_match);
LPROCFS_MD_OP_INIT(num_private_stats, stats, cancel_unused);
LPROCFS_MD_OP_INIT(num_private_stats, stats, renew_capa);
LPROCFS_MD_OP_INIT(num_private_stats, stats, unpack_capa);
LPROCFS_MD_OP_INIT(num_private_stats, stats, get_remote_perm);
LPROCFS_MD_OP_INIT(num_private_stats, stats, intent_getattr_async);
LPROCFS_MD_OP_INIT(num_private_stats, stats, revalidate_lock);
}
int lprocfs_alloc_md_stats(struct obd_device *obd,
unsigned num_private_stats)
{
struct lprocfs_stats *stats;
unsigned int num_stats;
int rc, i;
LASSERT(obd->md_stats == NULL);
LASSERT(obd->obd_debugfs_entry != NULL);
LASSERT(obd->md_cntr_base == 0);
num_stats = 1 + MD_COUNTER_OFFSET(revalidate_lock) +
num_private_stats;
stats = lprocfs_alloc_stats(num_stats, 0);
if (stats == NULL)
return -ENOMEM;
lprocfs_init_mps_stats(num_private_stats, stats);
for (i = num_private_stats; i < num_stats; i++) {
if (stats->ls_cnt_header[i].lc_name == NULL) {
CERROR("Missing md_stat initializer md_op operation at offset %d. Aborting.\n",
i - num_private_stats);
LBUG();
}
}
rc = ldebugfs_register_stats(obd->obd_debugfs_entry, "md_stats", stats);
if (rc < 0) {
lprocfs_free_stats(&stats);
} else {
obd->md_stats = stats;
obd->md_cntr_base = num_private_stats;
}
return rc;
}
void lprocfs_free_md_stats(struct obd_device *obd)
{
struct lprocfs_stats *stats = obd->md_stats;
if (stats != NULL) {
obd->md_stats = NULL;
obd->md_cntr_base = 0;
lprocfs_free_stats(&stats);
}
}
void lprocfs_init_ldlm_stats(struct lprocfs_stats *ldlm_stats)
{
lprocfs_counter_init(ldlm_stats,
LDLM_ENQUEUE - LDLM_FIRST_OPC,
0, "ldlm_enqueue", "reqs");
lprocfs_counter_init(ldlm_stats,
LDLM_CONVERT - LDLM_FIRST_OPC,
0, "ldlm_convert", "reqs");
lprocfs_counter_init(ldlm_stats,
LDLM_CANCEL - LDLM_FIRST_OPC,
0, "ldlm_cancel", "reqs");
lprocfs_counter_init(ldlm_stats,
LDLM_BL_CALLBACK - LDLM_FIRST_OPC,
0, "ldlm_bl_callback", "reqs");
lprocfs_counter_init(ldlm_stats,
LDLM_CP_CALLBACK - LDLM_FIRST_OPC,
0, "ldlm_cp_callback", "reqs");
lprocfs_counter_init(ldlm_stats,
LDLM_GL_CALLBACK - LDLM_FIRST_OPC,
0, "ldlm_gl_callback", "reqs");
}
int lprocfs_exp_cleanup(struct obd_export *exp)
{
return 0;
}
__s64 lprocfs_read_helper(struct lprocfs_counter *lc,
struct lprocfs_counter_header *header,
enum lprocfs_stats_flags flags,
enum lprocfs_fields_flags field)
{
__s64 ret = 0;
if (lc == NULL || header == NULL)
return 0;
switch (field) {
case LPROCFS_FIELDS_FLAGS_CONFIG:
ret = header->lc_config;
break;
case LPROCFS_FIELDS_FLAGS_SUM:
ret = lc->lc_sum;
if ((flags & LPROCFS_STATS_FLAG_IRQ_SAFE) != 0)
ret += lc->lc_sum_irq;
break;
case LPROCFS_FIELDS_FLAGS_MIN:
ret = lc->lc_min;
break;
case LPROCFS_FIELDS_FLAGS_MAX:
ret = lc->lc_max;
break;
case LPROCFS_FIELDS_FLAGS_AVG:
ret = (lc->lc_max - lc->lc_min) / 2;
break;
case LPROCFS_FIELDS_FLAGS_SUMSQUARE:
ret = lc->lc_sumsquare;
break;
case LPROCFS_FIELDS_FLAGS_COUNT:
ret = lc->lc_count;
break;
default:
break;
}
return 0;
}
int lprocfs_write_helper(const char __user *buffer, unsigned long count,
int *val)
{
return lprocfs_write_frac_helper(buffer, count, val, 1);
}
int lprocfs_seq_read_frac_helper(struct seq_file *m, long val, int mult)
{
long decimal_val, frac_val;
decimal_val = val / mult;
seq_printf(m, "%ld", decimal_val);
frac_val = val % mult;
if (frac_val > 0) {
frac_val *= 100;
frac_val /= mult;
}
if (frac_val > 0) {
if ((frac_val % 10) != 0)
seq_printf(m, ".%ld", frac_val);
else
seq_printf(m, ".%ld", frac_val / 10);
}
seq_printf(m, "\n");
return 0;
}
int lprocfs_write_u64_helper(const char __user *buffer, unsigned long count,
__u64 *val)
{
return lprocfs_write_frac_u64_helper(buffer, count, val, 1);
}
int lprocfs_write_frac_u64_helper(const char *buffer, unsigned long count,
__u64 *val, int mult)
{
char kernbuf[22], *end, *pbuf;
__u64 whole, frac = 0, units;
unsigned frac_d = 1;
int sign = 1;
if (count > (sizeof(kernbuf) - 1))
return -EINVAL;
if (copy_from_user(kernbuf, buffer, count))
return -EFAULT;
kernbuf[count] = '\0';
pbuf = kernbuf;
if (*pbuf == '-') {
sign = -1;
pbuf++;
}
whole = simple_strtoull(pbuf, &end, 10);
if (pbuf == end)
return -EINVAL;
if (*end == '.') {
int i;
pbuf = end + 1;
if (strlen(pbuf) > 10)
pbuf[10] = '\0';
frac = simple_strtoull(pbuf, &end, 10);
for (i = 0; i < (end - pbuf); i++)
frac_d *= 10;
}
units = 1;
switch (tolower(*end)) {
case 'p':
units <<= 10;
case 't':
units <<= 10;
case 'g':
units <<= 10;
case 'm':
units <<= 10;
case 'k':
units <<= 10;
}
if (units > 1)
mult = units;
frac *= mult;
do_div(frac, frac_d);
*val = sign * (whole * mult + frac);
return 0;
}
static char *lprocfs_strnstr(const char *s1, const char *s2, size_t len)
{
size_t l2;
l2 = strlen(s2);
if (!l2)
return (char *)s1;
while (len >= l2) {
len--;
if (!memcmp(s1, s2, l2))
return (char *)s1;
s1++;
}
return NULL;
}
char *lprocfs_find_named_value(const char *buffer, const char *name,
size_t *count)
{
char *val;
size_t buflen = *count;
val = lprocfs_strnstr(buffer, name, buflen);
if (val == NULL)
return (char *)buffer;
val += strlen(name);
while (val < buffer + buflen && isspace(*val))
val++;
*count = 0;
while (val < buffer + buflen && isalnum(*val)) {
++*count;
++val;
}
return val - *count;
}
int ldebugfs_seq_create(struct dentry *parent,
const char *name,
umode_t mode,
const struct file_operations *seq_fops,
void *data)
{
struct dentry *entry;
LASSERT((seq_fops->write == NULL) == ((mode & 0222) == 0));
entry = debugfs_create_file(name, mode, parent, data, seq_fops);
if (IS_ERR_OR_NULL(entry))
return entry ? PTR_ERR(entry) : -ENOMEM;
return 0;
}
int ldebugfs_obd_seq_create(struct obd_device *dev,
const char *name,
umode_t mode,
const struct file_operations *seq_fops,
void *data)
{
return ldebugfs_seq_create(dev->obd_debugfs_entry, name,
mode, seq_fops, data);
}
void lprocfs_oh_tally(struct obd_histogram *oh, unsigned int value)
{
if (value >= OBD_HIST_MAX)
value = OBD_HIST_MAX - 1;
spin_lock(&oh->oh_lock);
oh->oh_buckets[value]++;
spin_unlock(&oh->oh_lock);
}
void lprocfs_oh_tally_log2(struct obd_histogram *oh, unsigned int value)
{
unsigned int val;
for (val = 0; ((1 << val) < value) && (val <= OBD_HIST_MAX); val++)
;
lprocfs_oh_tally(oh, val);
}
unsigned long lprocfs_oh_sum(struct obd_histogram *oh)
{
unsigned long ret = 0;
int i;
for (i = 0; i < OBD_HIST_MAX; i++)
ret += oh->oh_buckets[i];
return ret;
}
void lprocfs_oh_clear(struct obd_histogram *oh)
{
spin_lock(&oh->oh_lock);
memset(oh->oh_buckets, 0, sizeof(oh->oh_buckets));
spin_unlock(&oh->oh_lock);
}
int lprocfs_obd_rd_max_pages_per_rpc(struct seq_file *m, void *data)
{
struct obd_device *dev = data;
struct client_obd *cli = &dev->u.cli;
client_obd_list_lock(&cli->cl_loi_list_lock);
seq_printf(m, "%d\n", cli->cl_max_pages_per_rpc);
client_obd_list_unlock(&cli->cl_loi_list_lock);
return 0;
}
ssize_t lustre_attr_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct lustre_attr *a = container_of(attr, struct lustre_attr, attr);
return a->show ? a->show(kobj, attr, buf) : 0;
}
ssize_t lustre_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t len)
{
struct lustre_attr *a = container_of(attr, struct lustre_attr, attr);
return a->store ? a->store(kobj, attr, buf, len) : len;
}
