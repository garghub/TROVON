static inline void
cfs_wi_sched_lock(cfs_wi_sched_t *sched)
{
spin_lock(&sched->ws_lock);
}
static inline void
cfs_wi_sched_unlock(cfs_wi_sched_t *sched)
{
spin_unlock(&sched->ws_lock);
}
static inline int
cfs_wi_sched_cansleep(cfs_wi_sched_t *sched)
{
cfs_wi_sched_lock(sched);
if (sched->ws_stopping) {
cfs_wi_sched_unlock(sched);
return 0;
}
if (!list_empty(&sched->ws_runq)) {
cfs_wi_sched_unlock(sched);
return 0;
}
cfs_wi_sched_unlock(sched);
return 1;
}
void
cfs_wi_exit(struct cfs_wi_sched *sched, cfs_workitem_t *wi)
{
LASSERT(!in_interrupt());
LASSERT(!sched->ws_stopping);
cfs_wi_sched_lock(sched);
LASSERT(wi->wi_running);
if (wi->wi_scheduled) {
LASSERT(!list_empty(&wi->wi_list));
list_del_init(&wi->wi_list);
LASSERT(sched->ws_nscheduled > 0);
sched->ws_nscheduled--;
}
LASSERT(list_empty(&wi->wi_list));
wi->wi_scheduled = 1;
cfs_wi_sched_unlock(sched);
return;
}
int
cfs_wi_deschedule(struct cfs_wi_sched *sched, cfs_workitem_t *wi)
{
int rc;
LASSERT(!in_interrupt());
LASSERT(!sched->ws_stopping);
cfs_wi_sched_lock(sched);
rc = !(wi->wi_running);
if (wi->wi_scheduled) {
LASSERT(!list_empty(&wi->wi_list));
list_del_init(&wi->wi_list);
LASSERT(sched->ws_nscheduled > 0);
sched->ws_nscheduled--;
wi->wi_scheduled = 0;
}
LASSERT (list_empty(&wi->wi_list));
cfs_wi_sched_unlock(sched);
return rc;
}
void
cfs_wi_schedule(struct cfs_wi_sched *sched, cfs_workitem_t *wi)
{
LASSERT(!in_interrupt());
LASSERT(!sched->ws_stopping);
cfs_wi_sched_lock(sched);
if (!wi->wi_scheduled) {
LASSERT (list_empty(&wi->wi_list));
wi->wi_scheduled = 1;
sched->ws_nscheduled++;
if (!wi->wi_running) {
list_add_tail(&wi->wi_list, &sched->ws_runq);
wake_up(&sched->ws_waitq);
} else {
list_add(&wi->wi_list, &sched->ws_rerunq);
}
}
LASSERT (!list_empty(&wi->wi_list));
cfs_wi_sched_unlock(sched);
return;
}
static int
cfs_wi_scheduler (void *arg)
{
struct cfs_wi_sched *sched = (cfs_wi_sched_t *)arg;
cfs_block_allsigs();
if (sched->ws_cptab != NULL)
cfs_cpt_bind(sched->ws_cptab, sched->ws_cpt);
spin_lock(&cfs_wi_data.wi_glock);
LASSERT(sched->ws_starting == 1);
sched->ws_starting--;
sched->ws_nthreads++;
spin_unlock(&cfs_wi_data.wi_glock);
cfs_wi_sched_lock(sched);
while (!sched->ws_stopping) {
int nloops = 0;
int rc;
cfs_workitem_t *wi;
while (!list_empty(&sched->ws_runq) &&
nloops < CFS_WI_RESCHED) {
wi = list_entry(sched->ws_runq.next,
cfs_workitem_t, wi_list);
LASSERT(wi->wi_scheduled && !wi->wi_running);
list_del_init(&wi->wi_list);
LASSERT(sched->ws_nscheduled > 0);
sched->ws_nscheduled--;
wi->wi_running = 1;
wi->wi_scheduled = 0;
cfs_wi_sched_unlock(sched);
nloops++;
rc = (*wi->wi_action) (wi);
cfs_wi_sched_lock(sched);
if (rc != 0)
continue;
wi->wi_running = 0;
if (list_empty(&wi->wi_list))
continue;
LASSERT(wi->wi_scheduled);
list_move_tail(&wi->wi_list, &sched->ws_runq);
}
if (!list_empty(&sched->ws_runq)) {
cfs_wi_sched_unlock(sched);
cond_resched();
cfs_wi_sched_lock(sched);
continue;
}
cfs_wi_sched_unlock(sched);
cfs_wait_event_interruptible_exclusive(sched->ws_waitq,
!cfs_wi_sched_cansleep(sched), rc);
cfs_wi_sched_lock(sched);
}
cfs_wi_sched_unlock(sched);
spin_lock(&cfs_wi_data.wi_glock);
sched->ws_nthreads--;
spin_unlock(&cfs_wi_data.wi_glock);
return 0;
}
void
cfs_wi_sched_destroy(struct cfs_wi_sched *sched)
{
int i;
LASSERT(cfs_wi_data.wi_init);
LASSERT(!cfs_wi_data.wi_stopping);
spin_lock(&cfs_wi_data.wi_glock);
if (sched->ws_stopping) {
CDEBUG(D_INFO, "%s is in progress of stopping\n",
sched->ws_name);
spin_unlock(&cfs_wi_data.wi_glock);
return;
}
LASSERT(!list_empty(&sched->ws_list));
sched->ws_stopping = 1;
spin_unlock(&cfs_wi_data.wi_glock);
i = 2;
wake_up_all(&sched->ws_waitq);
spin_lock(&cfs_wi_data.wi_glock);
while (sched->ws_nthreads > 0) {
CDEBUG(IS_PO2(++i) ? D_WARNING : D_NET,
"waiting for %d threads of WI sched[%s] to terminate\n",
sched->ws_nthreads, sched->ws_name);
spin_unlock(&cfs_wi_data.wi_glock);
cfs_pause(cfs_time_seconds(1) / 20);
spin_lock(&cfs_wi_data.wi_glock);
}
list_del(&sched->ws_list);
spin_unlock(&cfs_wi_data.wi_glock);
LASSERT(sched->ws_nscheduled == 0);
LIBCFS_FREE(sched, sizeof(*sched));
}
int
cfs_wi_sched_create(char *name, struct cfs_cpt_table *cptab,
int cpt, int nthrs, struct cfs_wi_sched **sched_pp)
{
struct cfs_wi_sched *sched;
int rc;
LASSERT(cfs_wi_data.wi_init);
LASSERT(!cfs_wi_data.wi_stopping);
LASSERT(cptab == NULL || cpt == CFS_CPT_ANY ||
(cpt >= 0 && cpt < cfs_cpt_number(cptab)));
LIBCFS_ALLOC(sched, sizeof(*sched));
if (sched == NULL)
return -ENOMEM;
strncpy(sched->ws_name, name, CFS_WS_NAME_LEN);
sched->ws_cptab = cptab;
sched->ws_cpt = cpt;
spin_lock_init(&sched->ws_lock);
init_waitqueue_head(&sched->ws_waitq);
INIT_LIST_HEAD(&sched->ws_runq);
INIT_LIST_HEAD(&sched->ws_rerunq);
INIT_LIST_HEAD(&sched->ws_list);
rc = 0;
while (nthrs > 0) {
char name[16];
struct task_struct *task;
spin_lock(&cfs_wi_data.wi_glock);
while (sched->ws_starting > 0) {
spin_unlock(&cfs_wi_data.wi_glock);
schedule();
spin_lock(&cfs_wi_data.wi_glock);
}
sched->ws_starting++;
spin_unlock(&cfs_wi_data.wi_glock);
if (sched->ws_cptab != NULL && sched->ws_cpt >= 0) {
snprintf(name, sizeof(name), "%s_%02d_%02d",
sched->ws_name, sched->ws_cpt,
sched->ws_nthreads);
} else {
snprintf(name, sizeof(name), "%s_%02d",
sched->ws_name, sched->ws_nthreads);
}
task = kthread_run(cfs_wi_scheduler, sched, "%s", name);
if (!IS_ERR(task)) {
nthrs--;
continue;
}
rc = PTR_ERR(task);
CERROR("Failed to create thread for WI scheduler %s: %d\n",
name, rc);
spin_lock(&cfs_wi_data.wi_glock);
list_add(&sched->ws_list, &cfs_wi_data.wi_scheds);
sched->ws_starting--;
spin_unlock(&cfs_wi_data.wi_glock);
cfs_wi_sched_destroy(sched);
return rc;
}
spin_lock(&cfs_wi_data.wi_glock);
list_add(&sched->ws_list, &cfs_wi_data.wi_scheds);
spin_unlock(&cfs_wi_data.wi_glock);
*sched_pp = sched;
return 0;
}
int
cfs_wi_startup(void)
{
memset(&cfs_wi_data, 0, sizeof(cfs_wi_data));
spin_lock_init(&cfs_wi_data.wi_glock);
INIT_LIST_HEAD(&cfs_wi_data.wi_scheds);
cfs_wi_data.wi_init = 1;
return 0;
}
void
cfs_wi_shutdown (void)
{
struct cfs_wi_sched *sched;
spin_lock(&cfs_wi_data.wi_glock);
cfs_wi_data.wi_stopping = 1;
spin_unlock(&cfs_wi_data.wi_glock);
list_for_each_entry(sched, &cfs_wi_data.wi_scheds, ws_list) {
sched->ws_stopping = 1;
wake_up_all(&sched->ws_waitq);
}
list_for_each_entry(sched, &cfs_wi_data.wi_scheds, ws_list) {
spin_lock(&cfs_wi_data.wi_glock);
while (sched->ws_nthreads != 0) {
spin_unlock(&cfs_wi_data.wi_glock);
cfs_pause(cfs_time_seconds(1) / 20);
spin_lock(&cfs_wi_data.wi_glock);
}
spin_unlock(&cfs_wi_data.wi_glock);
}
while (!list_empty(&cfs_wi_data.wi_scheds)) {
sched = list_entry(cfs_wi_data.wi_scheds.next,
struct cfs_wi_sched, ws_list);
list_del(&sched->ws_list);
LIBCFS_FREE(sched, sizeof(*sched));
}
cfs_wi_data.wi_stopping = 0;
cfs_wi_data.wi_init = 0;
}
