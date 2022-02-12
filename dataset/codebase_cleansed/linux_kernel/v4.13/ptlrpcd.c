void ptlrpcd_wake(struct ptlrpc_request *req)
{
struct ptlrpc_request_set *set = req->rq_set;
wake_up(&set->set_waitq);
}
static struct ptlrpcd_ctl *
ptlrpcd_select_pc(struct ptlrpc_request *req)
{
struct ptlrpcd *pd;
int cpt;
int idx;
if (req && req->rq_send_state != LUSTRE_IMP_FULL)
return &ptlrpcd_rcv;
cpt = cfs_cpt_current(cfs_cpt_table, 1);
if (!ptlrpcds_cpt_idx)
idx = cpt;
else
idx = ptlrpcds_cpt_idx[cpt];
pd = ptlrpcds[idx];
idx = pd->pd_cursor;
if (++idx == pd->pd_nthreads)
idx = 0;
pd->pd_cursor = idx;
return &pd->pd_threads[idx];
}
static int ptlrpcd_steal_rqset(struct ptlrpc_request_set *des,
struct ptlrpc_request_set *src)
{
struct list_head *tmp, *pos;
struct ptlrpc_request *req;
int rc = 0;
spin_lock(&src->set_new_req_lock);
if (likely(!list_empty(&src->set_new_requests))) {
list_for_each_safe(pos, tmp, &src->set_new_requests) {
req = list_entry(pos, struct ptlrpc_request,
rq_set_chain);
req->rq_set = des;
}
list_splice_init(&src->set_new_requests, &des->set_requests);
rc = atomic_read(&src->set_new_count);
atomic_add(rc, &des->set_remaining);
atomic_set(&src->set_new_count, 0);
}
spin_unlock(&src->set_new_req_lock);
return rc;
}
void ptlrpcd_add_req(struct ptlrpc_request *req)
{
struct ptlrpcd_ctl *pc;
if (req->rq_reqmsg)
lustre_msg_set_jobid(req->rq_reqmsg, NULL);
spin_lock(&req->rq_lock);
if (req->rq_invalid_rqset) {
struct l_wait_info lwi = LWI_TIMEOUT(cfs_time_seconds(5),
back_to_sleep, NULL);
req->rq_invalid_rqset = 0;
spin_unlock(&req->rq_lock);
l_wait_event(req->rq_set_waitq, !req->rq_set, &lwi);
} else if (req->rq_set) {
LASSERT(req->rq_phase == RQ_PHASE_NEW);
LASSERT(req->rq_send_state == LUSTRE_IMP_REPLAY);
atomic_inc(&req->rq_set->set_remaining);
spin_unlock(&req->rq_lock);
wake_up(&req->rq_set->set_waitq);
return;
} else {
spin_unlock(&req->rq_lock);
}
pc = ptlrpcd_select_pc(req);
DEBUG_REQ(D_INFO, req, "add req [%p] to pc [%s:%d]",
req, pc->pc_name, pc->pc_index);
ptlrpc_set_add_new_req(pc, req);
}
static inline void ptlrpc_reqset_get(struct ptlrpc_request_set *set)
{
atomic_inc(&set->set_refcount);
}
static int ptlrpcd_check(struct lu_env *env, struct ptlrpcd_ctl *pc)
{
struct list_head *tmp, *pos;
struct ptlrpc_request *req;
struct ptlrpc_request_set *set = pc->pc_set;
int rc = 0;
int rc2;
if (atomic_read(&set->set_new_count)) {
spin_lock(&set->set_new_req_lock);
if (likely(!list_empty(&set->set_new_requests))) {
list_splice_init(&set->set_new_requests,
&set->set_requests);
atomic_add(atomic_read(&set->set_new_count),
&set->set_remaining);
atomic_set(&set->set_new_count, 0);
rc = 1;
}
spin_unlock(&set->set_new_req_lock);
}
rc2 = lu_env_refill(env);
if (rc2 != 0) {
CERROR("Failure to refill session: %d\n", rc2);
return rc;
}
if (atomic_read(&set->set_remaining))
rc |= ptlrpc_check_set(env, set);
list_for_each_safe(pos, tmp, &set->set_requests) {
req = list_entry(pos, struct ptlrpc_request, rq_set_chain);
if (req->rq_phase != RQ_PHASE_COMPLETE)
break;
list_del_init(&req->rq_set_chain);
req->rq_set = NULL;
ptlrpc_req_finished(req);
}
if (rc == 0) {
rc = atomic_read(&set->set_new_count);
if (rc == 0 && pc->pc_npartners > 0) {
struct ptlrpcd_ctl *partner;
struct ptlrpc_request_set *ps;
int first = pc->pc_cursor;
do {
partner = pc->pc_partners[pc->pc_cursor++];
if (pc->pc_cursor >= pc->pc_npartners)
pc->pc_cursor = 0;
if (!partner)
continue;
spin_lock(&partner->pc_lock);
ps = partner->pc_set;
if (!ps) {
spin_unlock(&partner->pc_lock);
continue;
}
ptlrpc_reqset_get(ps);
spin_unlock(&partner->pc_lock);
if (atomic_read(&ps->set_new_count)) {
rc = ptlrpcd_steal_rqset(set, ps);
if (rc > 0)
CDEBUG(D_RPCTRACE, "transfer %d async RPCs [%d->%d]\n",
rc, partner->pc_index,
pc->pc_index);
}
ptlrpc_reqset_put(ps);
} while (rc == 0 && pc->pc_cursor != first);
}
}
return rc;
}
static int ptlrpcd(void *arg)
{
struct ptlrpcd_ctl *pc = arg;
struct ptlrpc_request_set *set;
struct lu_context ses = { 0 };
struct lu_env env = { .le_ses = &ses };
int rc = 0;
int exit = 0;
unshare_fs_struct();
if (cfs_cpt_bind(cfs_cpt_table, pc->pc_cpt) != 0)
CWARN("Failed to bind %s on CPT %d\n", pc->pc_name, pc->pc_cpt);
set = ptlrpc_prep_set();
if (!set) {
rc = -ENOMEM;
goto failed;
}
spin_lock(&pc->pc_lock);
pc->pc_set = set;
spin_unlock(&pc->pc_lock);
rc = lu_context_init(&env.le_ctx,
LCT_CL_THREAD | LCT_REMEMBER | LCT_NOREF);
if (rc == 0) {
rc = lu_context_init(env.le_ses,
LCT_SESSION | LCT_REMEMBER | LCT_NOREF);
if (rc != 0)
lu_context_fini(&env.le_ctx);
}
if (rc != 0)
goto failed;
complete(&pc->pc_starting);
do {
struct l_wait_info lwi;
int timeout;
timeout = ptlrpc_set_next_timeout(set);
lwi = LWI_TIMEOUT(cfs_time_seconds(timeout ? timeout : 1),
ptlrpc_expired_set, set);
lu_context_enter(&env.le_ctx);
lu_context_enter(env.le_ses);
l_wait_event(set->set_waitq, ptlrpcd_check(&env, pc), &lwi);
lu_context_exit(&env.le_ctx);
lu_context_exit(env.le_ses);
if (test_bit(LIOD_STOP, &pc->pc_flags)) {
if (test_bit(LIOD_FORCE, &pc->pc_flags))
ptlrpc_abort_set(set);
exit++;
}
} while (exit < 2);
if (!list_empty(&set->set_requests))
ptlrpc_set_wait(set);
lu_context_fini(&env.le_ctx);
lu_context_fini(env.le_ses);
complete(&pc->pc_finishing);
return 0;
failed:
pc->pc_error = rc;
complete(&pc->pc_starting);
return rc;
}
static void ptlrpcd_ctl_init(struct ptlrpcd_ctl *pc, int index, int cpt)
{
pc->pc_index = index;
pc->pc_cpt = cpt;
init_completion(&pc->pc_starting);
init_completion(&pc->pc_finishing);
spin_lock_init(&pc->pc_lock);
if (index < 0) {
snprintf(pc->pc_name, sizeof(pc->pc_name), "ptlrpcd_rcv");
} else {
snprintf(pc->pc_name, sizeof(pc->pc_name),
"ptlrpcd_%02d_%02d", cpt, index);
}
}
static int ptlrpcd_partners(struct ptlrpcd *pd, int index)
{
struct ptlrpcd_ctl *pc;
struct ptlrpcd_ctl **ppc;
int first;
int i;
int rc = 0;
int size;
LASSERT(index >= 0 && index < pd->pd_nthreads);
pc = &pd->pd_threads[index];
pc->pc_npartners = pd->pd_groupsize - 1;
if (pc->pc_npartners <= 0)
goto out;
size = sizeof(struct ptlrpcd_ctl *) * pc->pc_npartners;
pc->pc_partners = kzalloc_node(size, GFP_NOFS,
cfs_cpt_spread_node(cfs_cpt_table,
pc->pc_cpt));
if (!pc->pc_partners) {
pc->pc_npartners = 0;
rc = -ENOMEM;
goto out;
}
first = index - index % pd->pd_groupsize;
ppc = pc->pc_partners;
for (i = first; i < first + pd->pd_groupsize; i++) {
if (i != index)
*ppc++ = &pd->pd_threads[i];
}
out:
return rc;
}
int ptlrpcd_start(struct ptlrpcd_ctl *pc)
{
struct task_struct *task;
int rc = 0;
if (test_and_set_bit(LIOD_START, &pc->pc_flags)) {
CWARN("Starting second thread (%s) for same pc %p\n",
pc->pc_name, pc);
return 0;
}
task = kthread_run(ptlrpcd, pc, "%s", pc->pc_name);
if (IS_ERR(task)) {
rc = PTR_ERR(task);
goto out_set;
}
wait_for_completion(&pc->pc_starting);
rc = pc->pc_error;
if (rc != 0)
goto out_set;
return 0;
out_set:
if (pc->pc_set) {
struct ptlrpc_request_set *set = pc->pc_set;
spin_lock(&pc->pc_lock);
pc->pc_set = NULL;
spin_unlock(&pc->pc_lock);
ptlrpc_set_destroy(set);
}
clear_bit(LIOD_START, &pc->pc_flags);
return rc;
}
void ptlrpcd_stop(struct ptlrpcd_ctl *pc, int force)
{
if (!test_bit(LIOD_START, &pc->pc_flags)) {
CWARN("Thread for pc %p was not started\n", pc);
return;
}
set_bit(LIOD_STOP, &pc->pc_flags);
if (force)
set_bit(LIOD_FORCE, &pc->pc_flags);
wake_up(&pc->pc_set->set_waitq);
}
void ptlrpcd_free(struct ptlrpcd_ctl *pc)
{
struct ptlrpc_request_set *set = pc->pc_set;
if (!test_bit(LIOD_START, &pc->pc_flags)) {
CWARN("Thread for pc %p was not started\n", pc);
goto out;
}
wait_for_completion(&pc->pc_finishing);
spin_lock(&pc->pc_lock);
pc->pc_set = NULL;
spin_unlock(&pc->pc_lock);
ptlrpc_set_destroy(set);
clear_bit(LIOD_START, &pc->pc_flags);
clear_bit(LIOD_STOP, &pc->pc_flags);
clear_bit(LIOD_FORCE, &pc->pc_flags);
out:
if (pc->pc_npartners > 0) {
LASSERT(pc->pc_partners);
kfree(pc->pc_partners);
pc->pc_partners = NULL;
}
pc->pc_npartners = 0;
pc->pc_error = 0;
}
static void ptlrpcd_fini(void)
{
int i;
int j;
if (ptlrpcds) {
for (i = 0; i < ptlrpcds_num; i++) {
if (!ptlrpcds[i])
break;
for (j = 0; j < ptlrpcds[i]->pd_nthreads; j++)
ptlrpcd_stop(&ptlrpcds[i]->pd_threads[j], 0);
for (j = 0; j < ptlrpcds[i]->pd_nthreads; j++)
ptlrpcd_free(&ptlrpcds[i]->pd_threads[j]);
kfree(ptlrpcds[i]);
ptlrpcds[i] = NULL;
}
kfree(ptlrpcds);
}
ptlrpcds_num = 0;
ptlrpcd_stop(&ptlrpcd_rcv, 0);
ptlrpcd_free(&ptlrpcd_rcv);
kfree(ptlrpcds_cpt_idx);
ptlrpcds_cpt_idx = NULL;
}
static int ptlrpcd_init(void)
{
int nthreads;
int groupsize;
int size;
int i;
int j;
int rc = 0;
struct cfs_cpt_table *cptable;
__u32 *cpts = NULL;
int ncpts;
int cpt;
struct ptlrpcd *pd;
cptable = cfs_cpt_table;
ncpts = cfs_cpt_number(cptable);
if (ptlrpcd_cpts) {
struct cfs_expr_list *el;
size = ncpts * sizeof(ptlrpcds_cpt_idx[0]);
ptlrpcds_cpt_idx = kzalloc(size, GFP_KERNEL);
if (!ptlrpcds_cpt_idx) {
rc = -ENOMEM;
goto out;
}
rc = cfs_expr_list_parse(ptlrpcd_cpts,
strlen(ptlrpcd_cpts),
0, ncpts - 1, &el);
if (rc != 0) {
CERROR("ptlrpcd_cpts: invalid CPT pattern string: %s",
ptlrpcd_cpts);
rc = -EINVAL;
goto out;
}
rc = cfs_expr_list_values(el, ncpts, &cpts);
cfs_expr_list_free(el);
if (rc <= 0) {
CERROR("ptlrpcd_cpts: failed to parse CPT array %s: %d\n",
ptlrpcd_cpts, rc);
if (rc == 0)
rc = -EINVAL;
goto out;
}
for (cpt = 0; cpt < ncpts; cpt++) {
for (i = 0; i < rc; i++)
if (cpts[i] == cpt)
break;
if (i >= rc)
i = cpt % rc;
ptlrpcds_cpt_idx[cpt] = i;
}
cfs_expr_list_values_free(cpts, rc);
ncpts = rc;
}
ptlrpcds_num = ncpts;
size = ncpts * sizeof(ptlrpcds[0]);
ptlrpcds = kzalloc(size, GFP_KERNEL);
if (!ptlrpcds) {
rc = -ENOMEM;
goto out;
}
if (max_ptlrpcds != 0) {
CWARN("max_ptlrpcds is obsolete.\n");
if (ptlrpcd_per_cpt_max == 0) {
ptlrpcd_per_cpt_max = max_ptlrpcds / ncpts;
if (max_ptlrpcds % ncpts != 0)
ptlrpcd_per_cpt_max++;
CWARN("Setting ptlrpcd_per_cpt_max = %d\n",
ptlrpcd_per_cpt_max);
} else {
CWARN("ptlrpd_per_cpt_max is also set!\n");
}
}
if (ptlrpcd_bind_policy != 0) {
CWARN("ptlrpcd_bind_policy is obsolete.\n");
if (ptlrpcd_partner_group_size == 0) {
switch (ptlrpcd_bind_policy) {
case 1:
case 2:
ptlrpcd_partner_group_size = 1;
break;
case 3:
ptlrpcd_partner_group_size = 2;
break;
case 4:
#ifdef CONFIG_NUMA
ptlrpcd_partner_group_size = -1;
#else
ptlrpcd_partner_group_size = 3;
#endif
break;
default:
ptlrpcd_partner_group_size = 2;
break;
}
CWARN("Setting ptlrpcd_partner_group_size = %d\n",
ptlrpcd_partner_group_size);
} else {
CWARN("ptlrpcd_partner_group_size is also set!\n");
}
}
if (ptlrpcd_partner_group_size == 0)
ptlrpcd_partner_group_size = 2;
else if (ptlrpcd_partner_group_size < 0)
ptlrpcd_partner_group_size = -1;
else if (ptlrpcd_per_cpt_max > 0 &&
ptlrpcd_partner_group_size > ptlrpcd_per_cpt_max)
ptlrpcd_partner_group_size = ptlrpcd_per_cpt_max;
set_bit(LIOD_RECOVERY, &ptlrpcd_rcv.pc_flags);
ptlrpcd_ctl_init(&ptlrpcd_rcv, -1, CFS_CPT_ANY);
rc = ptlrpcd_start(&ptlrpcd_rcv);
if (rc < 0)
goto out;
for (i = 0; i < ncpts; i++) {
if (!cpts)
cpt = i;
else
cpt = cpts[i];
nthreads = cfs_cpt_weight(cptable, cpt);
if (ptlrpcd_per_cpt_max > 0 && ptlrpcd_per_cpt_max < nthreads)
nthreads = ptlrpcd_per_cpt_max;
if (nthreads < 2)
nthreads = 2;
if (ptlrpcd_partner_group_size <= 0) {
groupsize = nthreads;
} else if (nthreads <= ptlrpcd_partner_group_size) {
groupsize = nthreads;
} else {
groupsize = ptlrpcd_partner_group_size;
if (nthreads % groupsize != 0)
nthreads += groupsize - (nthreads % groupsize);
}
size = offsetof(struct ptlrpcd, pd_threads[nthreads]);
pd = kzalloc_node(size, GFP_NOFS,
cfs_cpt_spread_node(cfs_cpt_table, cpt));
if (!pd) {
rc = -ENOMEM;
goto out;
}
pd->pd_size = size;
pd->pd_index = i;
pd->pd_cpt = cpt;
pd->pd_cursor = 0;
pd->pd_nthreads = nthreads;
pd->pd_groupsize = groupsize;
ptlrpcds[i] = pd;
for (j = 0; j < nthreads; j++) {
ptlrpcd_ctl_init(&pd->pd_threads[j], j, cpt);
rc = ptlrpcd_partners(pd, j);
if (rc < 0)
goto out;
}
for (j = 0; j < nthreads; j++) {
rc = ptlrpcd_start(&pd->pd_threads[j]);
if (rc < 0)
goto out;
}
}
out:
if (rc != 0)
ptlrpcd_fini();
return rc;
}
int ptlrpcd_addref(void)
{
int rc = 0;
mutex_lock(&ptlrpcd_mutex);
if (++ptlrpcd_users == 1) {
rc = ptlrpcd_init();
if (rc < 0)
ptlrpcd_users--;
}
mutex_unlock(&ptlrpcd_mutex);
return rc;
}
void ptlrpcd_decref(void)
{
mutex_lock(&ptlrpcd_mutex);
if (--ptlrpcd_users == 0)
ptlrpcd_fini();
mutex_unlock(&ptlrpcd_mutex);
}
