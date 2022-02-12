const char *ll_opcode2str(__u32 opcode)
{
__u32 offset = opcode_offset(opcode);
LASSERTF(offset < LUSTRE_MAX_OPCODES,
"offset %u >= LUSTRE_MAX_OPCODES %u\n",
offset, LUSTRE_MAX_OPCODES);
LASSERTF(ll_rpc_opcode_table[offset].opcode == opcode,
"ll_rpc_opcode_table[%u].opcode %u != opcode %u\n",
offset, ll_rpc_opcode_table[offset].opcode, opcode);
return ll_rpc_opcode_table[offset].opname;
}
const char *ll_eopcode2str(__u32 opcode)
{
LASSERT(ll_eopcode_table[opcode].opcode == opcode);
return ll_eopcode_table[opcode].opname;
}
void ptlrpc_lprocfs_register(struct proc_dir_entry *root, char *dir,
char *name, struct proc_dir_entry **procroot_ret,
struct lprocfs_stats **stats_ret)
{
struct proc_dir_entry *svc_procroot;
struct lprocfs_stats *svc_stats;
int i, rc;
unsigned int svc_counter_config = LPROCFS_CNTR_AVGMINMAX |
LPROCFS_CNTR_STDDEV;
LASSERT(*procroot_ret == NULL);
LASSERT(*stats_ret == NULL);
svc_stats = lprocfs_alloc_stats(EXTRA_MAX_OPCODES+LUSTRE_MAX_OPCODES,
0);
if (svc_stats == NULL)
return;
if (dir) {
svc_procroot = lprocfs_register(dir, root, NULL, NULL);
if (IS_ERR(svc_procroot)) {
lprocfs_free_stats(&svc_stats);
return;
}
} else {
svc_procroot = root;
}
lprocfs_counter_init(svc_stats, PTLRPC_REQWAIT_CNTR,
svc_counter_config, "req_waittime", "usec");
lprocfs_counter_init(svc_stats, PTLRPC_REQQDEPTH_CNTR,
svc_counter_config, "req_qdepth", "reqs");
lprocfs_counter_init(svc_stats, PTLRPC_REQACTIVE_CNTR,
svc_counter_config, "req_active", "reqs");
lprocfs_counter_init(svc_stats, PTLRPC_TIMEOUT,
svc_counter_config, "req_timeout", "sec");
lprocfs_counter_init(svc_stats, PTLRPC_REQBUF_AVAIL_CNTR,
svc_counter_config, "reqbuf_avail", "bufs");
for (i = 0; i < EXTRA_LAST_OPC; i++) {
char *units;
switch (i) {
case BRW_WRITE_BYTES:
case BRW_READ_BYTES:
units = "bytes";
break;
default:
units = "reqs";
break;
}
lprocfs_counter_init(svc_stats, PTLRPC_LAST_CNTR + i,
svc_counter_config,
ll_eopcode2str(i), units);
}
for (i = 0; i < LUSTRE_MAX_OPCODES; i++) {
__u32 opcode = ll_rpc_opcode_table[i].opcode;
lprocfs_counter_init(svc_stats,
EXTRA_MAX_OPCODES + i, svc_counter_config,
ll_opcode2str(opcode), "usec");
}
rc = lprocfs_register_stats(svc_procroot, name, svc_stats);
if (rc < 0) {
if (dir)
lprocfs_remove(&svc_procroot);
lprocfs_free_stats(&svc_stats);
} else {
if (dir)
*procroot_ret = svc_procroot;
*stats_ret = svc_stats;
}
}
static int
ptlrpc_lprocfs_req_history_len_seq_show(struct seq_file *m, void *v)
{
struct ptlrpc_service *svc = m->private;
struct ptlrpc_service_part *svcpt;
int total = 0;
int i;
ptlrpc_service_for_each_part(svcpt, i, svc)
total += svcpt->scp_hist_nrqbds;
return seq_printf(m, "%d\n", total);
}
static int
ptlrpc_lprocfs_req_history_max_seq_show(struct seq_file *m, void *n)
{
struct ptlrpc_service *svc = m->private;
struct ptlrpc_service_part *svcpt;
int total = 0;
int i;
ptlrpc_service_for_each_part(svcpt, i, svc)
total += svc->srv_hist_nrqbds_cpt_max;
return seq_printf(m, "%d\n", total);
}
static ssize_t
ptlrpc_lprocfs_req_history_max_seq_write(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct ptlrpc_service *svc = ((struct seq_file *)file->private_data)->private;
int bufpages;
int val;
int rc;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc < 0)
return rc;
if (val < 0)
return -ERANGE;
bufpages = (svc->srv_buf_size + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;
if (val > totalram_pages / (2 * bufpages))
return -ERANGE;
spin_lock(&svc->srv_lock);
if (val == 0)
svc->srv_hist_nrqbds_cpt_max = 0;
else
svc->srv_hist_nrqbds_cpt_max = max(1, (val / svc->srv_ncpts));
spin_unlock(&svc->srv_lock);
return count;
}
static int
ptlrpc_lprocfs_threads_min_seq_show(struct seq_file *m, void *n)
{
struct ptlrpc_service *svc = m->private;
return seq_printf(m, "%d\n",
svc->srv_nthrs_cpt_init * svc->srv_ncpts);
}
static ssize_t
ptlrpc_lprocfs_threads_min_seq_write(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct ptlrpc_service *svc = ((struct seq_file *)file->private_data)->private;
int val;
int rc = lprocfs_write_helper(buffer, count, &val);
if (rc < 0)
return rc;
if (val / svc->srv_ncpts < PTLRPC_NTHRS_INIT)
return -ERANGE;
spin_lock(&svc->srv_lock);
if (val > svc->srv_nthrs_cpt_limit * svc->srv_ncpts) {
spin_unlock(&svc->srv_lock);
return -ERANGE;
}
svc->srv_nthrs_cpt_init = val / svc->srv_ncpts;
spin_unlock(&svc->srv_lock);
return count;
}
static int
ptlrpc_lprocfs_threads_started_seq_show(struct seq_file *m, void *n)
{
struct ptlrpc_service *svc = m->private;
struct ptlrpc_service_part *svcpt;
int total = 0;
int i;
ptlrpc_service_for_each_part(svcpt, i, svc)
total += svcpt->scp_nthrs_running;
return seq_printf(m, "%d\n", total);
}
static int
ptlrpc_lprocfs_threads_max_seq_show(struct seq_file *m, void *n)
{
struct ptlrpc_service *svc = m->private;
return seq_printf(m, "%d\n",
svc->srv_nthrs_cpt_limit * svc->srv_ncpts);
}
static ssize_t
ptlrpc_lprocfs_threads_max_seq_write(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct ptlrpc_service *svc = ((struct seq_file *)file->private_data)->private;
int val;
int rc = lprocfs_write_helper(buffer, count, &val);
if (rc < 0)
return rc;
if (val / svc->srv_ncpts < PTLRPC_NTHRS_INIT)
return -ERANGE;
spin_lock(&svc->srv_lock);
if (val < svc->srv_nthrs_cpt_init * svc->srv_ncpts) {
spin_unlock(&svc->srv_lock);
return -ERANGE;
}
svc->srv_nthrs_cpt_limit = val / svc->srv_ncpts;
spin_unlock(&svc->srv_lock);
return count;
}
static const char *nrs_state2str(enum ptlrpc_nrs_pol_state state)
{
switch (state) {
default:
LBUG();
case NRS_POL_STATE_INVALID:
return "invalid";
case NRS_POL_STATE_STOPPED:
return "stopped";
case NRS_POL_STATE_STOPPING:
return "stopping";
case NRS_POL_STATE_STARTING:
return "starting";
case NRS_POL_STATE_STARTED:
return "started";
}
}
void nrs_policy_get_info_locked(struct ptlrpc_nrs_policy *policy,
struct ptlrpc_nrs_pol_info *info)
{
LASSERT(policy != NULL);
LASSERT(info != NULL);
assert_spin_locked(&policy->pol_nrs->nrs_lock);
memcpy(info->pi_name, policy->pol_desc->pd_name, NRS_POL_NAME_MAX);
info->pi_fallback = !!(policy->pol_flags & PTLRPC_NRS_FL_FALLBACK);
info->pi_state = policy->pol_state;
info->pi_req_queued = policy->pol_req_queued;
info->pi_req_started = policy->pol_req_started;
}
static int ptlrpc_lprocfs_nrs_seq_show(struct seq_file *m, void *n)
{
struct ptlrpc_service *svc = m->private;
struct ptlrpc_service_part *svcpt;
struct ptlrpc_nrs *nrs;
struct ptlrpc_nrs_policy *policy;
struct ptlrpc_nrs_pol_info *infos;
struct ptlrpc_nrs_pol_info tmp;
unsigned num_pols;
unsigned pol_idx = 0;
bool hp = false;
int i;
int rc = 0;
mutex_lock(&nrs_core.nrs_mutex);
nrs = nrs_svcpt2nrs(svc->srv_parts[0], false);
spin_lock(&nrs->nrs_lock);
num_pols = svc->srv_parts[0]->scp_nrs_reg.nrs_num_pols;
spin_unlock(&nrs->nrs_lock);
OBD_ALLOC(infos, num_pols * sizeof(*infos));
if (infos == NULL) {
rc = -ENOMEM;
goto out;
}
again:
ptlrpc_service_for_each_part(svcpt, i, svc) {
nrs = nrs_svcpt2nrs(svcpt, hp);
spin_lock(&nrs->nrs_lock);
pol_idx = 0;
list_for_each_entry(policy, &nrs->nrs_policy_list,
pol_list) {
LASSERT(pol_idx < num_pols);
nrs_policy_get_info_locked(policy, &tmp);
if (i == 0) {
memcpy(infos[pol_idx].pi_name, tmp.pi_name,
NRS_POL_NAME_MAX);
memcpy(&infos[pol_idx].pi_state, &tmp.pi_state,
sizeof(tmp.pi_state));
infos[pol_idx].pi_fallback = tmp.pi_fallback;
} else {
LASSERT(strncmp(infos[pol_idx].pi_name,
tmp.pi_name,
NRS_POL_NAME_MAX) == 0);
LASSERT(infos[pol_idx].pi_fallback ==
tmp.pi_fallback);
}
infos[pol_idx].pi_req_queued += tmp.pi_req_queued;
infos[pol_idx].pi_req_started += tmp.pi_req_started;
pol_idx++;
}
spin_unlock(&nrs->nrs_lock);
}
seq_printf(m, "%s\n",
!hp ? "\nregular_requests:" : "high_priority_requests:");
for (pol_idx = 0; pol_idx < num_pols; pol_idx++) {
seq_printf(m, " - name: %s\n"
" state: %s\n"
" fallback: %s\n"
" queued: %-20d\n"
" active: %-20d\n\n",
infos[pol_idx].pi_name,
nrs_state2str(infos[pol_idx].pi_state),
infos[pol_idx].pi_fallback ? "yes" : "no",
(int)infos[pol_idx].pi_req_queued,
(int)infos[pol_idx].pi_req_started);
}
if (!hp && nrs_svc_has_hp(svc)) {
memset(infos, 0, num_pols * sizeof(*infos));
hp = true;
goto again;
}
out:
if (infos)
OBD_FREE(infos, num_pols * sizeof(*infos));
mutex_unlock(&nrs_core.nrs_mutex);
return rc;
}
static ssize_t ptlrpc_lprocfs_nrs_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct ptlrpc_service *svc = ((struct seq_file *)file->private_data)->private;
enum ptlrpc_nrs_queue_type queue = PTLRPC_NRS_QUEUE_BOTH;
char *cmd;
char *cmd_copy = NULL;
char *token;
int rc = 0;
if (count >= LPROCFS_NRS_WR_MAX_CMD) {
rc = -EINVAL;
goto out;
}
OBD_ALLOC(cmd, LPROCFS_NRS_WR_MAX_CMD);
if (cmd == NULL) {
rc = -ENOMEM;
goto out;
}
cmd_copy = cmd;
if (copy_from_user(cmd, buffer, count)) {
rc = -EFAULT;
goto out;
}
cmd[count] = '\0';
token = strsep(&cmd, " ");
if (strlen(token) > NRS_POL_NAME_MAX - 1) {
rc = -EINVAL;
goto out;
}
if (cmd == NULL)
goto default_queue;
if (strcmp(cmd, "reg") == 0)
queue = PTLRPC_NRS_QUEUE_REG;
else if (strcmp(cmd, "hp") == 0)
queue = PTLRPC_NRS_QUEUE_HP;
else {
rc = -EINVAL;
goto out;
}
default_queue:
if (queue == PTLRPC_NRS_QUEUE_HP && !nrs_svc_has_hp(svc)) {
rc = -ENODEV;
goto out;
} else if (queue == PTLRPC_NRS_QUEUE_BOTH && !nrs_svc_has_hp(svc))
queue = PTLRPC_NRS_QUEUE_REG;
mutex_lock(&nrs_core.nrs_mutex);
rc = ptlrpc_nrs_policy_control(svc, queue, token, PTLRPC_NRS_CTL_START,
false, NULL);
mutex_unlock(&nrs_core.nrs_mutex);
out:
if (cmd_copy)
OBD_FREE(cmd_copy, LPROCFS_NRS_WR_MAX_CMD);
return rc < 0 ? rc : count;
}
int
ptlrpc_lprocfs_svc_req_history_seek(struct ptlrpc_service_part *svcpt,
struct ptlrpc_srh_iterator *srhi,
__u64 seq)
{
struct list_head *e;
struct ptlrpc_request *req;
if (srhi->srhi_req != NULL &&
srhi->srhi_seq > svcpt->scp_hist_seq_culled &&
srhi->srhi_seq <= seq) {
LASSERTF(srhi->srhi_seq == srhi->srhi_req->rq_history_seq,
"%s:%d: seek seq %llu, request seq %llu\n",
svcpt->scp_service->srv_name, svcpt->scp_cpt,
srhi->srhi_seq, srhi->srhi_req->rq_history_seq);
LASSERTF(!list_empty(&svcpt->scp_hist_reqs),
"%s:%d: seek offset %llu, request seq %llu, last culled %llu\n",
svcpt->scp_service->srv_name, svcpt->scp_cpt,
seq, srhi->srhi_seq, svcpt->scp_hist_seq_culled);
e = &srhi->srhi_req->rq_history_list;
} else {
e = svcpt->scp_hist_reqs.next;
}
while (e != &svcpt->scp_hist_reqs) {
req = list_entry(e, struct ptlrpc_request, rq_history_list);
if (req->rq_history_seq >= seq) {
srhi->srhi_seq = req->rq_history_seq;
srhi->srhi_req = req;
return 0;
}
e = e->next;
}
return -ENOENT;
}
static void *
ptlrpc_lprocfs_svc_req_history_start(struct seq_file *s, loff_t *pos)
{
struct ptlrpc_service *svc = s->private;
struct ptlrpc_service_part *svcpt;
struct ptlrpc_srh_iterator *srhi;
unsigned int cpt;
int rc;
int i;
if (sizeof(loff_t) != sizeof(__u64)) {
CWARN("Failed to read request history because size of loff_t %d can't match size of u64\n",
(int)sizeof(loff_t));
return NULL;
}
OBD_ALLOC(srhi, sizeof(*srhi));
if (srhi == NULL)
return NULL;
srhi->srhi_seq = 0;
srhi->srhi_req = NULL;
cpt = PTLRPC_REQ_POS2CPT(svc, *pos);
ptlrpc_service_for_each_part(svcpt, i, svc) {
if (i < cpt)
continue;
if (i > cpt)
*pos = PTLRPC_REQ_CPT2POS(svc, i);
spin_lock(&svcpt->scp_lock);
rc = ptlrpc_lprocfs_svc_req_history_seek(svcpt, srhi,
PTLRPC_REQ_POS2SEQ(svc, *pos));
spin_unlock(&svcpt->scp_lock);
if (rc == 0) {
*pos = PTLRPC_REQ_SEQ2POS(svc, srhi->srhi_seq);
srhi->srhi_idx = i;
return srhi;
}
}
OBD_FREE(srhi, sizeof(*srhi));
return NULL;
}
static void
ptlrpc_lprocfs_svc_req_history_stop(struct seq_file *s, void *iter)
{
struct ptlrpc_srh_iterator *srhi = iter;
if (srhi != NULL)
OBD_FREE(srhi, sizeof(*srhi));
}
static void *
ptlrpc_lprocfs_svc_req_history_next(struct seq_file *s,
void *iter, loff_t *pos)
{
struct ptlrpc_service *svc = s->private;
struct ptlrpc_srh_iterator *srhi = iter;
struct ptlrpc_service_part *svcpt;
__u64 seq;
int rc;
int i;
for (i = srhi->srhi_idx; i < svc->srv_ncpts; i++) {
svcpt = svc->srv_parts[i];
if (i > srhi->srhi_idx) {
srhi->srhi_req = NULL;
seq = srhi->srhi_seq = 0;
} else {
seq = srhi->srhi_seq + (1 << svc->srv_cpt_bits);
}
spin_lock(&svcpt->scp_lock);
rc = ptlrpc_lprocfs_svc_req_history_seek(svcpt, srhi, seq);
spin_unlock(&svcpt->scp_lock);
if (rc == 0) {
*pos = PTLRPC_REQ_SEQ2POS(svc, srhi->srhi_seq);
srhi->srhi_idx = i;
return srhi;
}
}
OBD_FREE(srhi, sizeof(*srhi));
return NULL;
}
void target_print_req(void *seq_file, struct ptlrpc_request *req)
{
struct seq_file *sf = seq_file;
switch (req->rq_phase) {
case RQ_PHASE_NEW:
seq_printf(sf, "<not swabbed>\n");
break;
case RQ_PHASE_INTERPRET:
case RQ_PHASE_COMPLETE:
seq_printf(sf, "opc %d\n", lustre_msg_get_opc(req->rq_reqmsg));
break;
default:
DEBUG_REQ(D_ERROR, req, "bad phase %d", req->rq_phase);
}
}
static int ptlrpc_lprocfs_svc_req_history_show(struct seq_file *s, void *iter)
{
struct ptlrpc_service *svc = s->private;
struct ptlrpc_srh_iterator *srhi = iter;
struct ptlrpc_service_part *svcpt;
struct ptlrpc_request *req;
int rc;
LASSERT(srhi->srhi_idx < svc->srv_ncpts);
svcpt = svc->srv_parts[srhi->srhi_idx];
spin_lock(&svcpt->scp_lock);
rc = ptlrpc_lprocfs_svc_req_history_seek(svcpt, srhi, srhi->srhi_seq);
if (rc == 0) {
req = srhi->srhi_req;
seq_printf(s, "%lld:%s:%s:x%llu:%d:%s:%ld:%lds(%+lds) ",
req->rq_history_seq, libcfs_nid2str(req->rq_self),
libcfs_id2str(req->rq_peer), req->rq_xid,
req->rq_reqlen, ptlrpc_rqphase2str(req),
req->rq_arrival_time.tv_sec,
req->rq_sent - req->rq_arrival_time.tv_sec,
req->rq_sent - req->rq_deadline);
if (svc->srv_ops.so_req_printer == NULL)
seq_printf(s, "\n");
else
svc->srv_ops.so_req_printer(s, srhi->srhi_req);
}
spin_unlock(&svcpt->scp_lock);
return rc;
}
static int
ptlrpc_lprocfs_svc_req_history_open(struct inode *inode, struct file *file)
{
static struct seq_operations sops = {
.start = ptlrpc_lprocfs_svc_req_history_start,
.stop = ptlrpc_lprocfs_svc_req_history_stop,
.next = ptlrpc_lprocfs_svc_req_history_next,
.show = ptlrpc_lprocfs_svc_req_history_show,
};
struct seq_file *seqf;
int rc;
rc = seq_open(file, &sops);
if (rc)
return rc;
seqf = file->private_data;
seqf->private = PDE_DATA(inode);
return 0;
}
static int ptlrpc_lprocfs_timeouts_seq_show(struct seq_file *m, void *n)
{
struct ptlrpc_service *svc = m->private;
struct ptlrpc_service_part *svcpt;
struct dhms ts;
time_t worstt;
unsigned int cur;
unsigned int worst;
int i;
if (AT_OFF) {
seq_printf(m, "adaptive timeouts off, using obd_timeout %u\n",
obd_timeout);
return 0;
}
ptlrpc_service_for_each_part(svcpt, i, svc) {
cur = at_get(&svcpt->scp_at_estimate);
worst = svcpt->scp_at_estimate.at_worst_ever;
worstt = svcpt->scp_at_estimate.at_worst_time;
s2dhms(&ts, get_seconds() - worstt);
seq_printf(m, "%10s : cur %3u worst %3u (at %ld, "
DHMS_FMT" ago) ", "service",
cur, worst, worstt, DHMS_VARS(&ts));
lprocfs_at_hist_helper(m, &svcpt->scp_at_estimate);
}
return 0;
}
static int ptlrpc_lprocfs_hp_ratio_seq_show(struct seq_file *m, void *v)
{
struct ptlrpc_service *svc = m->private;
return seq_printf(m, "%d", svc->srv_hpreq_ratio);
}
static ssize_t ptlrpc_lprocfs_hp_ratio_seq_write(struct file *file,
const char *buffer,
size_t count,
loff_t *off)
{
struct ptlrpc_service *svc = ((struct seq_file *)file->private_data)->private;
int rc;
int val;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc < 0)
return rc;
if (val < 0)
return -ERANGE;
spin_lock(&svc->srv_lock);
svc->srv_hpreq_ratio = val;
spin_unlock(&svc->srv_lock);
return count;
}
void ptlrpc_lprocfs_register_service(struct proc_dir_entry *entry,
struct ptlrpc_service *svc)
{
struct lprocfs_vars lproc_vars[] = {
{.name = "high_priority_ratio",
.fops = &ptlrpc_lprocfs_hp_ratio_fops,
.data = svc},
{.name = "req_buffer_history_len",
.fops = &ptlrpc_lprocfs_req_history_len_fops,
.data = svc},
{.name = "req_buffer_history_max",
.fops = &ptlrpc_lprocfs_req_history_max_fops,
.data = svc},
{.name = "threads_min",
.fops = &ptlrpc_lprocfs_threads_min_fops,
.data = svc},
{.name = "threads_max",
.fops = &ptlrpc_lprocfs_threads_max_fops,
.data = svc},
{.name = "threads_started",
.fops = &ptlrpc_lprocfs_threads_started_fops,
.data = svc},
{.name = "timeouts",
.fops = &ptlrpc_lprocfs_timeouts_fops,
.data = svc},
{.name = "nrs_policies",
.fops = &ptlrpc_lprocfs_nrs_fops,
.data = svc},
{NULL}
};
static struct file_operations req_history_fops = {
.owner = THIS_MODULE,
.open = ptlrpc_lprocfs_svc_req_history_open,
.read = seq_read,
.llseek = seq_lseek,
.release = lprocfs_seq_release,
};
int rc;
ptlrpc_lprocfs_register(entry, svc->srv_name,
"stats", &svc->srv_procroot,
&svc->srv_stats);
if (svc->srv_procroot == NULL)
return;
lprocfs_add_vars(svc->srv_procroot, lproc_vars, NULL);
rc = lprocfs_seq_create(svc->srv_procroot, "req_history",
0400, &req_history_fops, svc);
if (rc)
CWARN("Error adding the req_history file\n");
}
void ptlrpc_lprocfs_register_obd(struct obd_device *obddev)
{
ptlrpc_lprocfs_register(obddev->obd_proc_entry, NULL, "stats",
&obddev->obd_svc_procroot,
&obddev->obd_svc_stats);
}
void ptlrpc_lprocfs_rpc_sent(struct ptlrpc_request *req, long amount)
{
struct lprocfs_stats *svc_stats;
__u32 op = lustre_msg_get_opc(req->rq_reqmsg);
int opc = opcode_offset(op);
svc_stats = req->rq_import->imp_obd->obd_svc_stats;
if (svc_stats == NULL || opc <= 0)
return;
LASSERT(opc < LUSTRE_MAX_OPCODES);
if (!(op == LDLM_ENQUEUE || op == MDS_REINT))
lprocfs_counter_add(svc_stats, opc + EXTRA_MAX_OPCODES, amount);
}
void ptlrpc_lprocfs_brw(struct ptlrpc_request *req, int bytes)
{
struct lprocfs_stats *svc_stats;
int idx;
if (!req->rq_import)
return;
svc_stats = req->rq_import->imp_obd->obd_svc_stats;
if (!svc_stats)
return;
idx = lustre_msg_get_opc(req->rq_reqmsg);
switch (idx) {
case OST_READ:
idx = BRW_READ_BYTES + PTLRPC_LAST_CNTR;
break;
case OST_WRITE:
idx = BRW_WRITE_BYTES + PTLRPC_LAST_CNTR;
break;
default:
LASSERTF(0, "unsupported opcode %u\n", idx);
break;
}
lprocfs_counter_add(svc_stats, idx, bytes);
}
void ptlrpc_lprocfs_unregister_service(struct ptlrpc_service *svc)
{
if (svc->srv_procroot != NULL)
lprocfs_remove(&svc->srv_procroot);
if (svc->srv_stats)
lprocfs_free_stats(&svc->srv_stats);
}
void ptlrpc_lprocfs_unregister_obd(struct obd_device *obd)
{
if (obd->obd_svc_procroot)
lprocfs_remove(&obd->obd_svc_procroot);
if (obd->obd_svc_stats)
lprocfs_free_stats(&obd->obd_svc_stats);
}
int lprocfs_wr_evict_client(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct obd_device *obd = ((struct seq_file *)file->private_data)->private;
char *kbuf;
char *tmpbuf;
OBD_ALLOC(kbuf, BUFLEN);
if (kbuf == NULL)
return -ENOMEM;
if (copy_from_user(kbuf, buffer,
min_t(unsigned long, BUFLEN - 1, count))) {
count = -EFAULT;
goto out;
}
tmpbuf = cfs_firststr(kbuf, min_t(unsigned long, BUFLEN - 1, count));
class_incref(obd, __func__, current);
if (strncmp(tmpbuf, "nid:", 4) == 0)
obd_export_evict_by_nid(obd, tmpbuf + 4);
else if (strncmp(tmpbuf, "uuid:", 5) == 0)
obd_export_evict_by_uuid(obd, tmpbuf + 5);
else
obd_export_evict_by_uuid(obd, tmpbuf);
class_decref(obd, __func__, current);
out:
OBD_FREE(kbuf, BUFLEN);
return count;
}
int lprocfs_wr_ping(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct obd_device *obd = ((struct seq_file *)file->private_data)->private;
struct ptlrpc_request *req;
int rc;
LPROCFS_CLIMP_CHECK(obd);
req = ptlrpc_prep_ping(obd->u.cli.cl_import);
LPROCFS_CLIMP_EXIT(obd);
if (req == NULL)
return -ENOMEM;
req->rq_send_state = LUSTRE_IMP_FULL;
rc = ptlrpc_queue_wait(req);
ptlrpc_req_finished(req);
if (rc >= 0)
return count;
return rc;
}
int lprocfs_wr_import(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct obd_device *obd = ((struct seq_file *)file->private_data)->private;
struct obd_import *imp = obd->u.cli.cl_import;
char *kbuf = NULL;
char *uuid;
char *ptr;
int do_reconn = 1;
const char prefix[] = "connection=";
const int prefix_len = sizeof(prefix) - 1;
if (count > PAGE_CACHE_SIZE - 1 || count <= prefix_len)
return -EINVAL;
OBD_ALLOC(kbuf, count + 1);
if (kbuf == NULL)
return -ENOMEM;
if (copy_from_user(kbuf, buffer, count)) {
count = -EFAULT;
goto out;
}
kbuf[count] = 0;
if (strncmp(prefix, kbuf, prefix_len) != 0) {
count = -EINVAL;
goto out;
}
uuid = kbuf + prefix_len;
ptr = strstr(uuid, "::");
if (ptr) {
__u32 inst;
char *endptr;
*ptr = 0;
do_reconn = 0;
ptr += strlen("::");
inst = simple_strtol(ptr, &endptr, 10);
if (*endptr) {
CERROR("config: wrong instance # %s\n", ptr);
} else if (inst != imp->imp_connect_data.ocd_instance) {
CDEBUG(D_INFO, "IR: %s is connecting to an obsoleted target(%u/%u), reconnecting...\n",
imp->imp_obd->obd_name,
imp->imp_connect_data.ocd_instance, inst);
do_reconn = 1;
} else {
CDEBUG(D_INFO, "IR: %s has already been connecting to new target(%u)\n",
imp->imp_obd->obd_name, inst);
}
}
if (do_reconn)
ptlrpc_recover_import(imp, uuid, 1);
out:
OBD_FREE(kbuf, count + 1);
return count;
}
int lprocfs_rd_pinger_recov(struct seq_file *m, void *n)
{
struct obd_device *obd = m->private;
struct obd_import *imp = obd->u.cli.cl_import;
int rc;
LPROCFS_CLIMP_CHECK(obd);
rc = seq_printf(m, "%d\n", !imp->imp_no_pinger_recover);
LPROCFS_CLIMP_EXIT(obd);
return rc;
}
int lprocfs_wr_pinger_recov(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct obd_device *obd = ((struct seq_file *)file->private_data)->private;
struct client_obd *cli = &obd->u.cli;
struct obd_import *imp = cli->cl_import;
int rc, val;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc < 0)
return rc;
if (val != 0 && val != 1)
return -ERANGE;
LPROCFS_CLIMP_CHECK(obd);
spin_lock(&imp->imp_lock);
imp->imp_no_pinger_recover = !val;
spin_unlock(&imp->imp_lock);
LPROCFS_CLIMP_EXIT(obd);
return count;
}
