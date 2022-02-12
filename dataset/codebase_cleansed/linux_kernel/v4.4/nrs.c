static int nrs_policy_init(struct ptlrpc_nrs_policy *policy)
{
return policy->pol_desc->pd_ops->op_policy_init != NULL ?
policy->pol_desc->pd_ops->op_policy_init(policy) : 0;
}
static void nrs_policy_fini(struct ptlrpc_nrs_policy *policy)
{
LASSERT(policy->pol_ref == 0);
LASSERT(policy->pol_req_queued == 0);
if (policy->pol_desc->pd_ops->op_policy_fini != NULL)
policy->pol_desc->pd_ops->op_policy_fini(policy);
}
static int nrs_policy_ctl_locked(struct ptlrpc_nrs_policy *policy,
enum ptlrpc_nrs_ctl opc, void *arg)
{
if (policy->pol_state == NRS_POL_STATE_STOPPED)
return -ENODEV;
return policy->pol_desc->pd_ops->op_policy_ctl != NULL ?
policy->pol_desc->pd_ops->op_policy_ctl(policy, opc, arg) :
-ENOSYS;
}
static void nrs_policy_stop0(struct ptlrpc_nrs_policy *policy)
{
struct ptlrpc_nrs *nrs = policy->pol_nrs;
if (policy->pol_desc->pd_ops->op_policy_stop != NULL) {
spin_unlock(&nrs->nrs_lock);
policy->pol_desc->pd_ops->op_policy_stop(policy);
spin_lock(&nrs->nrs_lock);
}
LASSERT(list_empty(&policy->pol_list_queued));
LASSERT(policy->pol_req_queued == 0 &&
policy->pol_req_started == 0);
policy->pol_private = NULL;
policy->pol_state = NRS_POL_STATE_STOPPED;
if (atomic_dec_and_test(&policy->pol_desc->pd_refs))
module_put(policy->pol_desc->pd_owner);
}
static int nrs_policy_stop_locked(struct ptlrpc_nrs_policy *policy)
{
struct ptlrpc_nrs *nrs = policy->pol_nrs;
if (nrs->nrs_policy_fallback == policy && !nrs->nrs_stopping)
return -EPERM;
if (policy->pol_state == NRS_POL_STATE_STARTING)
return -EAGAIN;
if (policy->pol_state != NRS_POL_STATE_STARTED)
return 0;
policy->pol_state = NRS_POL_STATE_STOPPING;
if (nrs->nrs_policy_primary == policy) {
nrs->nrs_policy_primary = NULL;
} else {
LASSERT(nrs->nrs_policy_fallback == policy);
nrs->nrs_policy_fallback = NULL;
}
if (policy->pol_ref == 1)
nrs_policy_stop0(policy);
return 0;
}
static void nrs_policy_stop_primary(struct ptlrpc_nrs *nrs)
{
struct ptlrpc_nrs_policy *tmp = nrs->nrs_policy_primary;
if (tmp == NULL)
return;
nrs->nrs_policy_primary = NULL;
LASSERT(tmp->pol_state == NRS_POL_STATE_STARTED);
tmp->pol_state = NRS_POL_STATE_STOPPING;
if (tmp->pol_ref == 0)
nrs_policy_stop0(tmp);
}
static int nrs_policy_start_locked(struct ptlrpc_nrs_policy *policy)
{
struct ptlrpc_nrs *nrs = policy->pol_nrs;
int rc = 0;
if (nrs->nrs_policy_starting)
return -EAGAIN;
LASSERT(policy->pol_state != NRS_POL_STATE_STARTING);
if (policy->pol_state == NRS_POL_STATE_STOPPING)
return -EAGAIN;
if (policy->pol_flags & PTLRPC_NRS_FL_FALLBACK) {
if (policy == nrs->nrs_policy_fallback) {
nrs_policy_stop_primary(nrs);
return 0;
}
LASSERT(nrs->nrs_policy_fallback == NULL);
} else {
if (nrs->nrs_policy_fallback == NULL)
return -EPERM;
if (policy->pol_state == NRS_POL_STATE_STARTED)
return 0;
}
if (atomic_inc_return(&policy->pol_desc->pd_refs) == 1 &&
!try_module_get(policy->pol_desc->pd_owner)) {
atomic_dec(&policy->pol_desc->pd_refs);
CERROR("NRS: cannot get module for policy %s; is it alive?\n",
policy->pol_desc->pd_name);
return -ENODEV;
}
nrs->nrs_policy_starting = 1;
policy->pol_state = NRS_POL_STATE_STARTING;
if (policy->pol_desc->pd_ops->op_policy_start) {
spin_unlock(&nrs->nrs_lock);
rc = policy->pol_desc->pd_ops->op_policy_start(policy);
spin_lock(&nrs->nrs_lock);
if (rc != 0) {
if (atomic_dec_and_test(&policy->pol_desc->pd_refs))
module_put(policy->pol_desc->pd_owner);
policy->pol_state = NRS_POL_STATE_STOPPED;
goto out;
}
}
policy->pol_state = NRS_POL_STATE_STARTED;
if (policy->pol_flags & PTLRPC_NRS_FL_FALLBACK) {
nrs->nrs_policy_fallback = policy;
} else {
nrs_policy_stop_primary(nrs);
nrs->nrs_policy_primary = policy;
}
out:
nrs->nrs_policy_starting = 0;
return rc;
}
static inline void nrs_policy_get_locked(struct ptlrpc_nrs_policy *policy)
{
policy->pol_ref++;
}
static void nrs_policy_put_locked(struct ptlrpc_nrs_policy *policy)
{
LASSERT(policy->pol_ref > 0);
policy->pol_ref--;
if (unlikely(policy->pol_ref == 0 &&
policy->pol_state == NRS_POL_STATE_STOPPING))
nrs_policy_stop0(policy);
}
static void nrs_policy_put(struct ptlrpc_nrs_policy *policy)
{
spin_lock(&policy->pol_nrs->nrs_lock);
nrs_policy_put_locked(policy);
spin_unlock(&policy->pol_nrs->nrs_lock);
}
static struct ptlrpc_nrs_policy *nrs_policy_find_locked(struct ptlrpc_nrs *nrs,
char *name)
{
struct ptlrpc_nrs_policy *tmp;
list_for_each_entry(tmp, &nrs->nrs_policy_list, pol_list) {
if (strncmp(tmp->pol_desc->pd_name, name,
NRS_POL_NAME_MAX) == 0) {
nrs_policy_get_locked(tmp);
return tmp;
}
}
return NULL;
}
static void nrs_resource_put(struct ptlrpc_nrs_resource *res)
{
struct ptlrpc_nrs_policy *policy = res->res_policy;
if (policy->pol_desc->pd_ops->op_res_put != NULL) {
struct ptlrpc_nrs_resource *parent;
for (; res != NULL; res = parent) {
parent = res->res_parent;
policy->pol_desc->pd_ops->op_res_put(policy, res);
}
}
}
static
struct ptlrpc_nrs_resource *nrs_resource_get(struct ptlrpc_nrs_policy *policy,
struct ptlrpc_nrs_request *nrq,
bool moving_req)
{
struct ptlrpc_nrs_resource *res = NULL;
struct ptlrpc_nrs_resource *tmp = NULL;
int rc;
while (1) {
rc = policy->pol_desc->pd_ops->op_res_get(policy, nrq, res,
&tmp, moving_req);
if (rc < 0) {
if (res != NULL)
nrs_resource_put(res);
return NULL;
}
LASSERT(tmp != NULL);
tmp->res_parent = res;
tmp->res_policy = policy;
res = tmp;
tmp = NULL;
if (rc > 0)
return res;
}
}
static void nrs_resource_get_safe(struct ptlrpc_nrs *nrs,
struct ptlrpc_nrs_request *nrq,
struct ptlrpc_nrs_resource **resp,
bool moving_req)
{
struct ptlrpc_nrs_policy *primary = NULL;
struct ptlrpc_nrs_policy *fallback = NULL;
memset(resp, 0, sizeof(resp[0]) * NRS_RES_MAX);
spin_lock(&nrs->nrs_lock);
fallback = nrs->nrs_policy_fallback;
nrs_policy_get_locked(fallback);
primary = nrs->nrs_policy_primary;
if (primary != NULL)
nrs_policy_get_locked(primary);
spin_unlock(&nrs->nrs_lock);
resp[NRS_RES_FALLBACK] = nrs_resource_get(fallback, nrq, moving_req);
LASSERT(resp[NRS_RES_FALLBACK] != NULL);
if (primary != NULL) {
resp[NRS_RES_PRIMARY] = nrs_resource_get(primary, nrq,
moving_req);
if (resp[NRS_RES_PRIMARY] == NULL)
nrs_policy_put(primary);
}
}
static void nrs_resource_put_safe(struct ptlrpc_nrs_resource **resp)
{
struct ptlrpc_nrs_policy *pols[NRS_RES_MAX];
struct ptlrpc_nrs *nrs = NULL;
int i;
for (i = 0; i < NRS_RES_MAX; i++) {
if (resp[i] != NULL) {
pols[i] = resp[i]->res_policy;
nrs_resource_put(resp[i]);
resp[i] = NULL;
} else {
pols[i] = NULL;
}
}
for (i = 0; i < NRS_RES_MAX; i++) {
if (pols[i] == NULL)
continue;
if (nrs == NULL) {
nrs = pols[i]->pol_nrs;
spin_lock(&nrs->nrs_lock);
}
nrs_policy_put_locked(pols[i]);
}
if (nrs != NULL)
spin_unlock(&nrs->nrs_lock);
}
static inline
struct ptlrpc_nrs_request *nrs_request_get(struct ptlrpc_nrs_policy *policy,
bool peek, bool force)
{
struct ptlrpc_nrs_request *nrq;
LASSERT(policy->pol_req_queued > 0);
nrq = policy->pol_desc->pd_ops->op_req_get(policy, peek, force);
LASSERT(ergo(nrq != NULL, nrs_request_policy(nrq) == policy));
return nrq;
}
static inline void nrs_request_enqueue(struct ptlrpc_nrs_request *nrq)
{
struct ptlrpc_nrs_policy *policy;
int rc;
int i;
for (i = NRS_RES_MAX - 1; i >= 0; i--) {
if (nrq->nr_res_ptrs[i] == NULL)
continue;
nrq->nr_res_idx = i;
policy = nrq->nr_res_ptrs[i]->res_policy;
rc = policy->pol_desc->pd_ops->op_req_enqueue(policy, nrq);
if (rc == 0) {
policy->pol_nrs->nrs_req_queued++;
policy->pol_req_queued++;
return;
}
}
LBUG();
}
static inline void nrs_request_stop(struct ptlrpc_nrs_request *nrq)
{
struct ptlrpc_nrs_policy *policy = nrs_request_policy(nrq);
if (policy->pol_desc->pd_ops->op_req_stop)
policy->pol_desc->pd_ops->op_req_stop(policy, nrq);
LASSERT(policy->pol_nrs->nrs_req_started > 0);
LASSERT(policy->pol_req_started > 0);
policy->pol_nrs->nrs_req_started--;
policy->pol_req_started--;
}
static int nrs_policy_ctl(struct ptlrpc_nrs *nrs, char *name,
enum ptlrpc_nrs_ctl opc, void *arg)
{
struct ptlrpc_nrs_policy *policy;
int rc = 0;
spin_lock(&nrs->nrs_lock);
policy = nrs_policy_find_locked(nrs, name);
if (policy == NULL) {
rc = -ENOENT;
goto out;
}
switch (opc) {
default:
rc = nrs_policy_ctl_locked(policy, opc, arg);
break;
case PTLRPC_NRS_CTL_START:
rc = nrs_policy_start_locked(policy);
break;
}
out:
if (policy != NULL)
nrs_policy_put_locked(policy);
spin_unlock(&nrs->nrs_lock);
return rc;
}
static int nrs_policy_unregister(struct ptlrpc_nrs *nrs, char *name)
{
struct ptlrpc_nrs_policy *policy = NULL;
spin_lock(&nrs->nrs_lock);
policy = nrs_policy_find_locked(nrs, name);
if (policy == NULL) {
spin_unlock(&nrs->nrs_lock);
CERROR("Can't find NRS policy %s\n", name);
return -ENOENT;
}
if (policy->pol_ref > 1) {
CERROR("Policy %s is busy with %d references\n", name,
(int)policy->pol_ref);
nrs_policy_put_locked(policy);
spin_unlock(&nrs->nrs_lock);
return -EBUSY;
}
LASSERT(policy->pol_req_queued == 0);
LASSERT(policy->pol_req_started == 0);
if (policy->pol_state != NRS_POL_STATE_STOPPED) {
nrs_policy_stop_locked(policy);
LASSERT(policy->pol_state == NRS_POL_STATE_STOPPED);
}
list_del(&policy->pol_list);
nrs->nrs_num_pols--;
nrs_policy_put_locked(policy);
spin_unlock(&nrs->nrs_lock);
nrs_policy_fini(policy);
LASSERT(policy->pol_private == NULL);
kfree(policy);
return 0;
}
static int nrs_policy_register(struct ptlrpc_nrs *nrs,
struct ptlrpc_nrs_pol_desc *desc)
{
struct ptlrpc_nrs_policy *policy;
struct ptlrpc_nrs_policy *tmp;
struct ptlrpc_service_part *svcpt = nrs->nrs_svcpt;
int rc;
LASSERT(svcpt != NULL);
LASSERT(desc->pd_ops != NULL);
LASSERT(desc->pd_ops->op_res_get != NULL);
LASSERT(desc->pd_ops->op_req_get != NULL);
LASSERT(desc->pd_ops->op_req_enqueue != NULL);
LASSERT(desc->pd_ops->op_req_dequeue != NULL);
LASSERT(desc->pd_compat != NULL);
policy = kzalloc_node(sizeof(*policy), GFP_NOFS,
cfs_cpt_spread_node(svcpt->scp_service->srv_cptable,
svcpt->scp_cpt));
if (policy == NULL)
return -ENOMEM;
policy->pol_nrs = nrs;
policy->pol_desc = desc;
policy->pol_state = NRS_POL_STATE_STOPPED;
policy->pol_flags = desc->pd_flags;
INIT_LIST_HEAD(&policy->pol_list);
INIT_LIST_HEAD(&policy->pol_list_queued);
rc = nrs_policy_init(policy);
if (rc != 0) {
kfree(policy);
return rc;
}
spin_lock(&nrs->nrs_lock);
tmp = nrs_policy_find_locked(nrs, policy->pol_desc->pd_name);
if (tmp != NULL) {
CERROR("NRS policy %s has been registered, can't register it for %s\n",
policy->pol_desc->pd_name,
svcpt->scp_service->srv_name);
nrs_policy_put_locked(tmp);
spin_unlock(&nrs->nrs_lock);
nrs_policy_fini(policy);
kfree(policy);
return -EEXIST;
}
list_add_tail(&policy->pol_list, &nrs->nrs_policy_list);
nrs->nrs_num_pols++;
if (policy->pol_flags & PTLRPC_NRS_FL_REG_START)
rc = nrs_policy_start_locked(policy);
spin_unlock(&nrs->nrs_lock);
if (rc != 0)
(void) nrs_policy_unregister(nrs, policy->pol_desc->pd_name);
return rc;
}
static void ptlrpc_nrs_req_add_nolock(struct ptlrpc_request *req)
{
struct ptlrpc_nrs_policy *policy;
LASSERT(req->rq_nrq.nr_initialized);
LASSERT(!req->rq_nrq.nr_enqueued);
nrs_request_enqueue(&req->rq_nrq);
req->rq_nrq.nr_enqueued = 1;
policy = nrs_request_policy(&req->rq_nrq);
if (unlikely(list_empty(&policy->pol_list_queued)))
list_add_tail(&policy->pol_list_queued,
&policy->pol_nrs->nrs_policy_queued);
}
static void ptlrpc_nrs_hpreq_add_nolock(struct ptlrpc_request *req)
{
int opc = lustre_msg_get_opc(req->rq_reqmsg);
spin_lock(&req->rq_lock);
req->rq_hp = 1;
ptlrpc_nrs_req_add_nolock(req);
if (opc != OBD_PING)
DEBUG_REQ(D_NET, req, "high priority req");
spin_unlock(&req->rq_lock);
}
static inline bool nrs_policy_compatible(const struct ptlrpc_service *svc,
const struct ptlrpc_nrs_pol_desc *desc)
{
return desc->pd_compat(svc, desc);
}
static int nrs_register_policies_locked(struct ptlrpc_nrs *nrs)
{
struct ptlrpc_nrs_pol_desc *desc;
struct ptlrpc_service_part *svcpt = nrs->nrs_svcpt;
struct ptlrpc_service *svc = svcpt->scp_service;
int rc = -EINVAL;
LASSERT(mutex_is_locked(&nrs_core.nrs_mutex));
list_for_each_entry(desc, &nrs_core.nrs_policies, pd_list) {
if (nrs_policy_compatible(svc, desc)) {
rc = nrs_policy_register(nrs, desc);
if (rc != 0) {
CERROR("Failed to register NRS policy %s for partition %d of service %s: %d\n",
desc->pd_name, svcpt->scp_cpt,
svc->srv_name, rc);
break;
}
}
}
return rc;
}
static int nrs_svcpt_setup_locked0(struct ptlrpc_nrs *nrs,
struct ptlrpc_service_part *svcpt)
{
enum ptlrpc_nrs_queue_type queue;
LASSERT(mutex_is_locked(&nrs_core.nrs_mutex));
if (nrs == &svcpt->scp_nrs_reg)
queue = PTLRPC_NRS_QUEUE_REG;
else if (nrs == svcpt->scp_nrs_hp)
queue = PTLRPC_NRS_QUEUE_HP;
else
LBUG();
nrs->nrs_svcpt = svcpt;
nrs->nrs_queue_type = queue;
spin_lock_init(&nrs->nrs_lock);
INIT_LIST_HEAD(&nrs->nrs_policy_list);
INIT_LIST_HEAD(&nrs->nrs_policy_queued);
return nrs_register_policies_locked(nrs);
}
static int nrs_svcpt_setup_locked(struct ptlrpc_service_part *svcpt)
{
struct ptlrpc_nrs *nrs;
int rc;
LASSERT(mutex_is_locked(&nrs_core.nrs_mutex));
nrs = nrs_svcpt2nrs(svcpt, false);
rc = nrs_svcpt_setup_locked0(nrs, svcpt);
if (rc < 0)
goto out;
if (svcpt->scp_service->srv_ops.so_hpreq_handler == NULL)
goto out;
svcpt->scp_nrs_hp =
kzalloc_node(sizeof(*svcpt->scp_nrs_hp), GFP_NOFS,
cfs_cpt_spread_node(svcpt->scp_service->srv_cptable,
svcpt->scp_cpt));
if (svcpt->scp_nrs_hp == NULL) {
rc = -ENOMEM;
goto out;
}
nrs = nrs_svcpt2nrs(svcpt, true);
rc = nrs_svcpt_setup_locked0(nrs, svcpt);
out:
return rc;
}
static void nrs_svcpt_cleanup_locked(struct ptlrpc_service_part *svcpt)
{
struct ptlrpc_nrs *nrs;
struct ptlrpc_nrs_policy *policy;
struct ptlrpc_nrs_policy *tmp;
int rc;
bool hp = false;
LASSERT(mutex_is_locked(&nrs_core.nrs_mutex));
again:
nrs = nrs_svcpt2nrs(svcpt, hp);
nrs->nrs_stopping = 1;
list_for_each_entry_safe(policy, tmp, &nrs->nrs_policy_list,
pol_list) {
rc = nrs_policy_unregister(nrs, policy->pol_desc->pd_name);
LASSERT(rc == 0);
}
if (!hp && nrs_svcpt_has_hp(svcpt)) {
hp = true;
goto again;
}
if (hp)
kfree(nrs);
}
static struct ptlrpc_nrs_pol_desc *nrs_policy_find_desc_locked(const char *name)
{
struct ptlrpc_nrs_pol_desc *tmp;
list_for_each_entry(tmp, &nrs_core.nrs_policies, pd_list) {
if (strncmp(tmp->pd_name, name, NRS_POL_NAME_MAX) == 0)
return tmp;
}
return NULL;
}
static int nrs_policy_unregister_locked(struct ptlrpc_nrs_pol_desc *desc)
{
struct ptlrpc_nrs *nrs;
struct ptlrpc_service *svc;
struct ptlrpc_service_part *svcpt;
int i;
int rc = 0;
LASSERT(mutex_is_locked(&nrs_core.nrs_mutex));
LASSERT(mutex_is_locked(&ptlrpc_all_services_mutex));
list_for_each_entry(svc, &ptlrpc_all_services, srv_list) {
if (!nrs_policy_compatible(svc, desc) ||
unlikely(svc->srv_is_stopping))
continue;
ptlrpc_service_for_each_part(svcpt, i, svc) {
bool hp = false;
again:
nrs = nrs_svcpt2nrs(svcpt, hp);
rc = nrs_policy_unregister(nrs, desc->pd_name);
if (rc == -ENOENT) {
rc = 0;
} else if (rc != 0) {
CERROR("Failed to unregister NRS policy %s for partition %d of service %s: %d\n",
desc->pd_name, svcpt->scp_cpt,
svcpt->scp_service->srv_name, rc);
return rc;
}
if (!hp && nrs_svc_has_hp(svc)) {
hp = true;
goto again;
}
}
if (desc->pd_ops->op_lprocfs_fini != NULL)
desc->pd_ops->op_lprocfs_fini(svc);
}
return rc;
}
static int ptlrpc_nrs_policy_register(struct ptlrpc_nrs_pol_conf *conf)
{
struct ptlrpc_service *svc;
struct ptlrpc_nrs_pol_desc *desc;
int rc = 0;
LASSERT(conf != NULL);
LASSERT(conf->nc_ops != NULL);
LASSERT(conf->nc_compat != NULL);
LASSERT(ergo(conf->nc_compat == nrs_policy_compat_one,
conf->nc_compat_svc_name != NULL));
LASSERT(ergo((conf->nc_flags & PTLRPC_NRS_FL_REG_EXTERN) != 0,
conf->nc_owner != NULL));
conf->nc_name[NRS_POL_NAME_MAX - 1] = '\0';
if ((conf->nc_flags & PTLRPC_NRS_FL_REG_EXTERN) &&
(conf->nc_flags & (PTLRPC_NRS_FL_FALLBACK |
PTLRPC_NRS_FL_REG_START))) {
CERROR("NRS: failing to register policy %s. Please check policy flags; external policies cannot act as fallback policies, or be started immediately upon registration without interaction with lprocfs\n",
conf->nc_name);
return -EINVAL;
}
mutex_lock(&nrs_core.nrs_mutex);
if (nrs_policy_find_desc_locked(conf->nc_name) != NULL) {
CERROR("NRS: failing to register policy %s which has already been registered with NRS core!\n",
conf->nc_name);
rc = -EEXIST;
goto fail;
}
desc = kzalloc(sizeof(*desc), GFP_NOFS);
if (!desc) {
rc = -ENOMEM;
goto fail;
}
strncpy(desc->pd_name, conf->nc_name, NRS_POL_NAME_MAX);
desc->pd_ops = conf->nc_ops;
desc->pd_compat = conf->nc_compat;
desc->pd_compat_svc_name = conf->nc_compat_svc_name;
if ((conf->nc_flags & PTLRPC_NRS_FL_REG_EXTERN) != 0)
desc->pd_owner = conf->nc_owner;
desc->pd_flags = conf->nc_flags;
atomic_set(&desc->pd_refs, 0);
if ((conf->nc_flags & PTLRPC_NRS_FL_REG_EXTERN) == 0)
goto internal;
mutex_lock(&ptlrpc_all_services_mutex);
list_for_each_entry(svc, &ptlrpc_all_services, srv_list) {
struct ptlrpc_service_part *svcpt;
int i;
int rc2;
if (!nrs_policy_compatible(svc, desc) ||
unlikely(svc->srv_is_stopping))
continue;
ptlrpc_service_for_each_part(svcpt, i, svc) {
struct ptlrpc_nrs *nrs;
bool hp = false;
again:
nrs = nrs_svcpt2nrs(svcpt, hp);
rc = nrs_policy_register(nrs, desc);
if (rc != 0) {
CERROR("Failed to register NRS policy %s for partition %d of service %s: %d\n",
desc->pd_name, svcpt->scp_cpt,
svcpt->scp_service->srv_name, rc);
rc2 = nrs_policy_unregister_locked(desc);
LASSERT(rc2 == 0);
mutex_unlock(&ptlrpc_all_services_mutex);
kfree(desc);
goto fail;
}
if (!hp && nrs_svc_has_hp(svc)) {
hp = true;
goto again;
}
}
if (desc->pd_ops->op_lprocfs_init != NULL) {
rc = desc->pd_ops->op_lprocfs_init(svc);
if (rc != 0) {
rc2 = nrs_policy_unregister_locked(desc);
LASSERT(rc2 == 0);
mutex_unlock(&ptlrpc_all_services_mutex);
kfree(desc);
goto fail;
}
}
}
mutex_unlock(&ptlrpc_all_services_mutex);
internal:
list_add_tail(&desc->pd_list, &nrs_core.nrs_policies);
fail:
mutex_unlock(&nrs_core.nrs_mutex);
return rc;
}
int ptlrpc_service_nrs_setup(struct ptlrpc_service *svc)
{
struct ptlrpc_service_part *svcpt;
const struct ptlrpc_nrs_pol_desc *desc;
int i;
int rc = 0;
mutex_lock(&nrs_core.nrs_mutex);
ptlrpc_service_for_each_part(svcpt, i, svc) {
rc = nrs_svcpt_setup_locked(svcpt);
if (rc != 0)
goto failed;
}
list_for_each_entry(desc, &nrs_core.nrs_policies, pd_list) {
if (!nrs_policy_compatible(svc, desc))
continue;
if (desc->pd_ops->op_lprocfs_init != NULL) {
rc = desc->pd_ops->op_lprocfs_init(svc);
if (rc != 0)
goto failed;
}
}
failed:
mutex_unlock(&nrs_core.nrs_mutex);
return rc;
}
void ptlrpc_service_nrs_cleanup(struct ptlrpc_service *svc)
{
struct ptlrpc_service_part *svcpt;
const struct ptlrpc_nrs_pol_desc *desc;
int i;
mutex_lock(&nrs_core.nrs_mutex);
ptlrpc_service_for_each_part(svcpt, i, svc)
nrs_svcpt_cleanup_locked(svcpt);
list_for_each_entry(desc, &nrs_core.nrs_policies, pd_list) {
if (!nrs_policy_compatible(svc, desc))
continue;
if (desc->pd_ops->op_lprocfs_fini != NULL)
desc->pd_ops->op_lprocfs_fini(svc);
}
mutex_unlock(&nrs_core.nrs_mutex);
}
void ptlrpc_nrs_req_initialize(struct ptlrpc_service_part *svcpt,
struct ptlrpc_request *req, bool hp)
{
struct ptlrpc_nrs *nrs = nrs_svcpt2nrs(svcpt, hp);
memset(&req->rq_nrq, 0, sizeof(req->rq_nrq));
nrs_resource_get_safe(nrs, &req->rq_nrq, req->rq_nrq.nr_res_ptrs,
false);
req->rq_nrq.nr_initialized = 1;
}
void ptlrpc_nrs_req_finalize(struct ptlrpc_request *req)
{
if (req->rq_nrq.nr_initialized) {
nrs_resource_put_safe(req->rq_nrq.nr_res_ptrs);
req->rq_nrq.nr_finalized = 1;
}
}
void ptlrpc_nrs_req_stop_nolock(struct ptlrpc_request *req)
{
if (req->rq_nrq.nr_started)
nrs_request_stop(&req->rq_nrq);
}
void ptlrpc_nrs_req_add(struct ptlrpc_service_part *svcpt,
struct ptlrpc_request *req, bool hp)
{
spin_lock(&svcpt->scp_req_lock);
if (hp)
ptlrpc_nrs_hpreq_add_nolock(req);
else
ptlrpc_nrs_req_add_nolock(req);
spin_unlock(&svcpt->scp_req_lock);
}
static void nrs_request_removed(struct ptlrpc_nrs_policy *policy)
{
LASSERT(policy->pol_nrs->nrs_req_queued > 0);
LASSERT(policy->pol_req_queued > 0);
policy->pol_nrs->nrs_req_queued--;
policy->pol_req_queued--;
if (unlikely(policy->pol_req_queued == 0)) {
list_del_init(&policy->pol_list_queued);
} else if (policy->pol_req_queued != policy->pol_nrs->nrs_req_queued) {
LASSERT(policy->pol_req_queued <
policy->pol_nrs->nrs_req_queued);
list_move_tail(&policy->pol_list_queued,
&policy->pol_nrs->nrs_policy_queued);
}
}
struct ptlrpc_request *
ptlrpc_nrs_req_get_nolock0(struct ptlrpc_service_part *svcpt, bool hp,
bool peek, bool force)
{
struct ptlrpc_nrs *nrs = nrs_svcpt2nrs(svcpt, hp);
struct ptlrpc_nrs_policy *policy;
struct ptlrpc_nrs_request *nrq;
list_for_each_entry(policy, &nrs->nrs_policy_queued,
pol_list_queued) {
nrq = nrs_request_get(policy, peek, force);
if (nrq != NULL) {
if (likely(!peek)) {
nrq->nr_started = 1;
policy->pol_req_started++;
policy->pol_nrs->nrs_req_started++;
nrs_request_removed(policy);
}
return container_of(nrq, struct ptlrpc_request, rq_nrq);
}
}
return NULL;
}
bool ptlrpc_nrs_req_pending_nolock(struct ptlrpc_service_part *svcpt, bool hp)
{
struct ptlrpc_nrs *nrs = nrs_svcpt2nrs(svcpt, hp);
return nrs->nrs_req_queued > 0;
}
int ptlrpc_nrs_policy_control(const struct ptlrpc_service *svc,
enum ptlrpc_nrs_queue_type queue, char *name,
enum ptlrpc_nrs_ctl opc, bool single, void *arg)
{
struct ptlrpc_service_part *svcpt;
int i;
int rc = 0;
LASSERT(opc != PTLRPC_NRS_CTL_INVALID);
if ((queue & PTLRPC_NRS_QUEUE_BOTH) == 0)
return -EINVAL;
ptlrpc_service_for_each_part(svcpt, i, svc) {
if ((queue & PTLRPC_NRS_QUEUE_REG) != 0) {
rc = nrs_policy_ctl(nrs_svcpt2nrs(svcpt, false), name,
opc, arg);
if (rc != 0 || (queue == PTLRPC_NRS_QUEUE_REG &&
single))
goto out;
}
if ((queue & PTLRPC_NRS_QUEUE_HP) != 0) {
rc = nrs_policy_ctl(nrs_svcpt2nrs(svcpt, true), name,
opc, arg);
if (rc != 0 || single)
goto out;
}
}
out:
return rc;
}
int ptlrpc_nrs_init(void)
{
int rc;
mutex_init(&nrs_core.nrs_mutex);
INIT_LIST_HEAD(&nrs_core.nrs_policies);
rc = ptlrpc_nrs_policy_register(&nrs_conf_fifo);
if (rc != 0)
goto fail;
return rc;
fail:
ptlrpc_nrs_fini();
return rc;
}
void ptlrpc_nrs_fini(void)
{
struct ptlrpc_nrs_pol_desc *desc;
struct ptlrpc_nrs_pol_desc *tmp;
list_for_each_entry_safe(desc, tmp, &nrs_core.nrs_policies,
pd_list) {
list_del_init(&desc->pd_list);
kfree(desc);
}
}
