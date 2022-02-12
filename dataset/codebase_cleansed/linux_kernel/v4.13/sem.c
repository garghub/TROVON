void sem_init_ns(struct ipc_namespace *ns)
{
ns->sc_semmsl = SEMMSL;
ns->sc_semmns = SEMMNS;
ns->sc_semopm = SEMOPM;
ns->sc_semmni = SEMMNI;
ns->used_sems = 0;
ipc_init_ids(&ns->ids[IPC_SEM_IDS]);
}
void sem_exit_ns(struct ipc_namespace *ns)
{
free_ipcs(ns, &sem_ids(ns), freeary);
idr_destroy(&ns->ids[IPC_SEM_IDS].ipcs_idr);
}
void __init sem_init(void)
{
sem_init_ns(&init_ipc_ns);
ipc_init_proc_interface("sysvipc/sem",
" key semid perms nsems uid gid cuid cgid otime ctime\n",
IPC_SEM_IDS, sysvipc_sem_proc_show);
}
static void unmerge_queues(struct sem_array *sma)
{
struct sem_queue *q, *tq;
if (sma->complex_count)
return;
list_for_each_entry_safe(q, tq, &sma->pending_alter, list) {
struct sem *curr;
curr = &sma->sems[q->sops[0].sem_num];
list_add_tail(&q->list, &curr->pending_alter);
}
INIT_LIST_HEAD(&sma->pending_alter);
}
static void merge_queues(struct sem_array *sma)
{
int i;
for (i = 0; i < sma->sem_nsems; i++) {
struct sem *sem = &sma->sems[i];
list_splice_init(&sem->pending_alter, &sma->pending_alter);
}
}
static void sem_rcu_free(struct rcu_head *head)
{
struct kern_ipc_perm *p = container_of(head, struct kern_ipc_perm, rcu);
struct sem_array *sma = container_of(p, struct sem_array, sem_perm);
security_sem_free(sma);
kvfree(sma);
}
static void complexmode_enter(struct sem_array *sma)
{
int i;
struct sem *sem;
if (sma->use_global_lock > 0) {
sma->use_global_lock = USE_GLOBAL_LOCK_HYSTERESIS;
return;
}
sma->use_global_lock = USE_GLOBAL_LOCK_HYSTERESIS;
for (i = 0; i < sma->sem_nsems; i++) {
sem = &sma->sems[i];
spin_lock(&sem->lock);
spin_unlock(&sem->lock);
}
}
static void complexmode_tryleave(struct sem_array *sma)
{
if (sma->complex_count) {
return;
}
if (sma->use_global_lock == 1) {
smp_store_release(&sma->use_global_lock, 0);
} else {
sma->use_global_lock--;
}
}
static inline int sem_lock(struct sem_array *sma, struct sembuf *sops,
int nsops)
{
struct sem *sem;
if (nsops != 1) {
ipc_lock_object(&sma->sem_perm);
complexmode_enter(sma);
return SEM_GLOBAL_LOCK;
}
sem = &sma->sems[sops->sem_num];
if (!sma->use_global_lock) {
spin_lock(&sem->lock);
if (!smp_load_acquire(&sma->use_global_lock)) {
return sops->sem_num;
}
spin_unlock(&sem->lock);
}
ipc_lock_object(&sma->sem_perm);
if (sma->use_global_lock == 0) {
spin_lock(&sem->lock);
ipc_unlock_object(&sma->sem_perm);
return sops->sem_num;
} else {
return SEM_GLOBAL_LOCK;
}
}
static inline void sem_unlock(struct sem_array *sma, int locknum)
{
if (locknum == SEM_GLOBAL_LOCK) {
unmerge_queues(sma);
complexmode_tryleave(sma);
ipc_unlock_object(&sma->sem_perm);
} else {
struct sem *sem = &sma->sems[locknum];
spin_unlock(&sem->lock);
}
}
static inline struct sem_array *sem_obtain_object(struct ipc_namespace *ns, int id)
{
struct kern_ipc_perm *ipcp = ipc_obtain_object_idr(&sem_ids(ns), id);
if (IS_ERR(ipcp))
return ERR_CAST(ipcp);
return container_of(ipcp, struct sem_array, sem_perm);
}
static inline struct sem_array *sem_obtain_object_check(struct ipc_namespace *ns,
int id)
{
struct kern_ipc_perm *ipcp = ipc_obtain_object_check(&sem_ids(ns), id);
if (IS_ERR(ipcp))
return ERR_CAST(ipcp);
return container_of(ipcp, struct sem_array, sem_perm);
}
static inline void sem_lock_and_putref(struct sem_array *sma)
{
sem_lock(sma, NULL, -1);
ipc_rcu_putref(&sma->sem_perm, sem_rcu_free);
}
static inline void sem_rmid(struct ipc_namespace *ns, struct sem_array *s)
{
ipc_rmid(&sem_ids(ns), &s->sem_perm);
}
static struct sem_array *sem_alloc(size_t nsems)
{
struct sem_array *sma;
size_t size;
if (nsems > (INT_MAX - sizeof(*sma)) / sizeof(sma->sems[0]))
return NULL;
size = sizeof(*sma) + nsems * sizeof(sma->sems[0]);
sma = kvmalloc(size, GFP_KERNEL);
if (unlikely(!sma))
return NULL;
memset(sma, 0, size);
return sma;
}
static int newary(struct ipc_namespace *ns, struct ipc_params *params)
{
int retval;
struct sem_array *sma;
key_t key = params->key;
int nsems = params->u.nsems;
int semflg = params->flg;
int i;
if (!nsems)
return -EINVAL;
if (ns->used_sems + nsems > ns->sc_semmns)
return -ENOSPC;
sma = sem_alloc(nsems);
if (!sma)
return -ENOMEM;
sma->sem_perm.mode = (semflg & S_IRWXUGO);
sma->sem_perm.key = key;
sma->sem_perm.security = NULL;
retval = security_sem_alloc(sma);
if (retval) {
kvfree(sma);
return retval;
}
for (i = 0; i < nsems; i++) {
INIT_LIST_HEAD(&sma->sems[i].pending_alter);
INIT_LIST_HEAD(&sma->sems[i].pending_const);
spin_lock_init(&sma->sems[i].lock);
}
sma->complex_count = 0;
sma->use_global_lock = USE_GLOBAL_LOCK_HYSTERESIS;
INIT_LIST_HEAD(&sma->pending_alter);
INIT_LIST_HEAD(&sma->pending_const);
INIT_LIST_HEAD(&sma->list_id);
sma->sem_nsems = nsems;
sma->sem_ctime = get_seconds();
retval = ipc_addid(&sem_ids(ns), &sma->sem_perm, ns->sc_semmni);
if (retval < 0) {
call_rcu(&sma->sem_perm.rcu, sem_rcu_free);
return retval;
}
ns->used_sems += nsems;
sem_unlock(sma, -1);
rcu_read_unlock();
return sma->sem_perm.id;
}
static inline int sem_security(struct kern_ipc_perm *ipcp, int semflg)
{
struct sem_array *sma;
sma = container_of(ipcp, struct sem_array, sem_perm);
return security_sem_associate(sma, semflg);
}
static inline int sem_more_checks(struct kern_ipc_perm *ipcp,
struct ipc_params *params)
{
struct sem_array *sma;
sma = container_of(ipcp, struct sem_array, sem_perm);
if (params->u.nsems > sma->sem_nsems)
return -EINVAL;
return 0;
}
static int perform_atomic_semop_slow(struct sem_array *sma, struct sem_queue *q)
{
int result, sem_op, nsops, pid;
struct sembuf *sop;
struct sem *curr;
struct sembuf *sops;
struct sem_undo *un;
sops = q->sops;
nsops = q->nsops;
un = q->undo;
for (sop = sops; sop < sops + nsops; sop++) {
curr = &sma->sems[sop->sem_num];
sem_op = sop->sem_op;
result = curr->semval;
if (!sem_op && result)
goto would_block;
result += sem_op;
if (result < 0)
goto would_block;
if (result > SEMVMX)
goto out_of_range;
if (sop->sem_flg & SEM_UNDO) {
int undo = un->semadj[sop->sem_num] - sem_op;
if (undo < (-SEMAEM - 1) || undo > SEMAEM)
goto out_of_range;
un->semadj[sop->sem_num] = undo;
}
curr->semval = result;
}
sop--;
pid = q->pid;
while (sop >= sops) {
sma->sems[sop->sem_num].sempid = pid;
sop--;
}
return 0;
out_of_range:
result = -ERANGE;
goto undo;
would_block:
q->blocking = sop;
if (sop->sem_flg & IPC_NOWAIT)
result = -EAGAIN;
else
result = 1;
undo:
sop--;
while (sop >= sops) {
sem_op = sop->sem_op;
sma->sems[sop->sem_num].semval -= sem_op;
if (sop->sem_flg & SEM_UNDO)
un->semadj[sop->sem_num] += sem_op;
sop--;
}
return result;
}
static int perform_atomic_semop(struct sem_array *sma, struct sem_queue *q)
{
int result, sem_op, nsops;
struct sembuf *sop;
struct sem *curr;
struct sembuf *sops;
struct sem_undo *un;
sops = q->sops;
nsops = q->nsops;
un = q->undo;
if (unlikely(q->dupsop))
return perform_atomic_semop_slow(sma, q);
for (sop = sops; sop < sops + nsops; sop++) {
curr = &sma->sems[sop->sem_num];
sem_op = sop->sem_op;
result = curr->semval;
if (!sem_op && result)
goto would_block;
result += sem_op;
if (result < 0)
goto would_block;
if (result > SEMVMX)
return -ERANGE;
if (sop->sem_flg & SEM_UNDO) {
int undo = un->semadj[sop->sem_num] - sem_op;
if (undo < (-SEMAEM - 1) || undo > SEMAEM)
return -ERANGE;
}
}
for (sop = sops; sop < sops + nsops; sop++) {
curr = &sma->sems[sop->sem_num];
sem_op = sop->sem_op;
result = curr->semval;
if (sop->sem_flg & SEM_UNDO) {
int undo = un->semadj[sop->sem_num] - sem_op;
un->semadj[sop->sem_num] = undo;
}
curr->semval += sem_op;
curr->sempid = q->pid;
}
return 0;
would_block:
q->blocking = sop;
return sop->sem_flg & IPC_NOWAIT ? -EAGAIN : 1;
}
static inline void wake_up_sem_queue_prepare(struct sem_queue *q, int error,
struct wake_q_head *wake_q)
{
wake_q_add(wake_q, q->sleeper);
WRITE_ONCE(q->status, error);
}
static void unlink_queue(struct sem_array *sma, struct sem_queue *q)
{
list_del(&q->list);
if (q->nsops > 1)
sma->complex_count--;
}
static inline int check_restart(struct sem_array *sma, struct sem_queue *q)
{
if (!list_empty(&sma->pending_alter))
return 1;
if (q->nsops > 1)
return 1;
return 0;
}
static int wake_const_ops(struct sem_array *sma, int semnum,
struct wake_q_head *wake_q)
{
struct sem_queue *q, *tmp;
struct list_head *pending_list;
int semop_completed = 0;
if (semnum == -1)
pending_list = &sma->pending_const;
else
pending_list = &sma->sems[semnum].pending_const;
list_for_each_entry_safe(q, tmp, pending_list, list) {
int error = perform_atomic_semop(sma, q);
if (error > 0)
continue;
unlink_queue(sma, q);
wake_up_sem_queue_prepare(q, error, wake_q);
if (error == 0)
semop_completed = 1;
}
return semop_completed;
}
static int do_smart_wakeup_zero(struct sem_array *sma, struct sembuf *sops,
int nsops, struct wake_q_head *wake_q)
{
int i;
int semop_completed = 0;
int got_zero = 0;
if (sops) {
for (i = 0; i < nsops; i++) {
int num = sops[i].sem_num;
if (sma->sems[num].semval == 0) {
got_zero = 1;
semop_completed |= wake_const_ops(sma, num, wake_q);
}
}
} else {
for (i = 0; i < sma->sem_nsems; i++) {
if (sma->sems[i].semval == 0) {
got_zero = 1;
semop_completed |= wake_const_ops(sma, i, wake_q);
}
}
}
if (got_zero)
semop_completed |= wake_const_ops(sma, -1, wake_q);
return semop_completed;
}
static int update_queue(struct sem_array *sma, int semnum, struct wake_q_head *wake_q)
{
struct sem_queue *q, *tmp;
struct list_head *pending_list;
int semop_completed = 0;
if (semnum == -1)
pending_list = &sma->pending_alter;
else
pending_list = &sma->sems[semnum].pending_alter;
again:
list_for_each_entry_safe(q, tmp, pending_list, list) {
int error, restart;
if (semnum != -1 && sma->sems[semnum].semval == 0)
break;
error = perform_atomic_semop(sma, q);
if (error > 0)
continue;
unlink_queue(sma, q);
if (error) {
restart = 0;
} else {
semop_completed = 1;
do_smart_wakeup_zero(sma, q->sops, q->nsops, wake_q);
restart = check_restart(sma, q);
}
wake_up_sem_queue_prepare(q, error, wake_q);
if (restart)
goto again;
}
return semop_completed;
}
static void set_semotime(struct sem_array *sma, struct sembuf *sops)
{
if (sops == NULL) {
sma->sems[0].sem_otime = get_seconds();
} else {
sma->sems[sops[0].sem_num].sem_otime =
get_seconds();
}
}
static void do_smart_update(struct sem_array *sma, struct sembuf *sops, int nsops,
int otime, struct wake_q_head *wake_q)
{
int i;
otime |= do_smart_wakeup_zero(sma, sops, nsops, wake_q);
if (!list_empty(&sma->pending_alter)) {
otime |= update_queue(sma, -1, wake_q);
} else {
if (!sops) {
for (i = 0; i < sma->sem_nsems; i++)
otime |= update_queue(sma, i, wake_q);
} else {
for (i = 0; i < nsops; i++) {
if (sops[i].sem_op > 0) {
otime |= update_queue(sma,
sops[i].sem_num, wake_q);
}
}
}
}
if (otime)
set_semotime(sma, sops);
}
static int check_qop(struct sem_array *sma, int semnum, struct sem_queue *q,
bool count_zero)
{
struct sembuf *sop = q->blocking;
pr_info_once("semctl(GETNCNT/GETZCNT) is since 3.16 Single Unix Specification compliant.\n"
"The task %s (%d) triggered the difference, watch for misbehavior.\n",
current->comm, task_pid_nr(current));
if (sop->sem_num != semnum)
return 0;
if (count_zero && sop->sem_op == 0)
return 1;
if (!count_zero && sop->sem_op < 0)
return 1;
return 0;
}
static int count_semcnt(struct sem_array *sma, ushort semnum,
bool count_zero)
{
struct list_head *l;
struct sem_queue *q;
int semcnt;
semcnt = 0;
if (count_zero)
l = &sma->sems[semnum].pending_const;
else
l = &sma->sems[semnum].pending_alter;
list_for_each_entry(q, l, list) {
semcnt++;
}
list_for_each_entry(q, &sma->pending_alter, list) {
semcnt += check_qop(sma, semnum, q, count_zero);
}
if (count_zero) {
list_for_each_entry(q, &sma->pending_const, list) {
semcnt += check_qop(sma, semnum, q, count_zero);
}
}
return semcnt;
}
static void freeary(struct ipc_namespace *ns, struct kern_ipc_perm *ipcp)
{
struct sem_undo *un, *tu;
struct sem_queue *q, *tq;
struct sem_array *sma = container_of(ipcp, struct sem_array, sem_perm);
int i;
DEFINE_WAKE_Q(wake_q);
ipc_assert_locked_object(&sma->sem_perm);
list_for_each_entry_safe(un, tu, &sma->list_id, list_id) {
list_del(&un->list_id);
spin_lock(&un->ulp->lock);
un->semid = -1;
list_del_rcu(&un->list_proc);
spin_unlock(&un->ulp->lock);
kfree_rcu(un, rcu);
}
list_for_each_entry_safe(q, tq, &sma->pending_const, list) {
unlink_queue(sma, q);
wake_up_sem_queue_prepare(q, -EIDRM, &wake_q);
}
list_for_each_entry_safe(q, tq, &sma->pending_alter, list) {
unlink_queue(sma, q);
wake_up_sem_queue_prepare(q, -EIDRM, &wake_q);
}
for (i = 0; i < sma->sem_nsems; i++) {
struct sem *sem = &sma->sems[i];
list_for_each_entry_safe(q, tq, &sem->pending_const, list) {
unlink_queue(sma, q);
wake_up_sem_queue_prepare(q, -EIDRM, &wake_q);
}
list_for_each_entry_safe(q, tq, &sem->pending_alter, list) {
unlink_queue(sma, q);
wake_up_sem_queue_prepare(q, -EIDRM, &wake_q);
}
}
sem_rmid(ns, sma);
sem_unlock(sma, -1);
rcu_read_unlock();
wake_up_q(&wake_q);
ns->used_sems -= sma->sem_nsems;
ipc_rcu_putref(&sma->sem_perm, sem_rcu_free);
}
static unsigned long copy_semid_to_user(void __user *buf, struct semid64_ds *in, int version)
{
switch (version) {
case IPC_64:
return copy_to_user(buf, in, sizeof(*in));
case IPC_OLD:
{
struct semid_ds out;
memset(&out, 0, sizeof(out));
ipc64_perm_to_ipc_perm(&in->sem_perm, &out.sem_perm);
out.sem_otime = in->sem_otime;
out.sem_ctime = in->sem_ctime;
out.sem_nsems = in->sem_nsems;
return copy_to_user(buf, &out, sizeof(out));
}
default:
return -EINVAL;
}
}
static time_t get_semotime(struct sem_array *sma)
{
int i;
time_t res;
res = sma->sems[0].sem_otime;
for (i = 1; i < sma->sem_nsems; i++) {
time_t to = sma->sems[i].sem_otime;
if (to > res)
res = to;
}
return res;
}
static int semctl_nolock(struct ipc_namespace *ns, int semid,
int cmd, int version, void __user *p)
{
int err;
struct sem_array *sma;
switch (cmd) {
case IPC_INFO:
case SEM_INFO:
{
struct seminfo seminfo;
int max_id;
err = security_sem_semctl(NULL, cmd);
if (err)
return err;
memset(&seminfo, 0, sizeof(seminfo));
seminfo.semmni = ns->sc_semmni;
seminfo.semmns = ns->sc_semmns;
seminfo.semmsl = ns->sc_semmsl;
seminfo.semopm = ns->sc_semopm;
seminfo.semvmx = SEMVMX;
seminfo.semmnu = SEMMNU;
seminfo.semmap = SEMMAP;
seminfo.semume = SEMUME;
down_read(&sem_ids(ns).rwsem);
if (cmd == SEM_INFO) {
seminfo.semusz = sem_ids(ns).in_use;
seminfo.semaem = ns->used_sems;
} else {
seminfo.semusz = SEMUSZ;
seminfo.semaem = SEMAEM;
}
max_id = ipc_get_maxid(&sem_ids(ns));
up_read(&sem_ids(ns).rwsem);
if (copy_to_user(p, &seminfo, sizeof(struct seminfo)))
return -EFAULT;
return (max_id < 0) ? 0 : max_id;
}
case IPC_STAT:
case SEM_STAT:
{
struct semid64_ds tbuf;
int id = 0;
memset(&tbuf, 0, sizeof(tbuf));
rcu_read_lock();
if (cmd == SEM_STAT) {
sma = sem_obtain_object(ns, semid);
if (IS_ERR(sma)) {
err = PTR_ERR(sma);
goto out_unlock;
}
id = sma->sem_perm.id;
} else {
sma = sem_obtain_object_check(ns, semid);
if (IS_ERR(sma)) {
err = PTR_ERR(sma);
goto out_unlock;
}
}
err = -EACCES;
if (ipcperms(ns, &sma->sem_perm, S_IRUGO))
goto out_unlock;
err = security_sem_semctl(sma, cmd);
if (err)
goto out_unlock;
kernel_to_ipc64_perm(&sma->sem_perm, &tbuf.sem_perm);
tbuf.sem_otime = get_semotime(sma);
tbuf.sem_ctime = sma->sem_ctime;
tbuf.sem_nsems = sma->sem_nsems;
rcu_read_unlock();
if (copy_semid_to_user(p, &tbuf, version))
return -EFAULT;
return id;
}
default:
return -EINVAL;
}
out_unlock:
rcu_read_unlock();
return err;
}
static int semctl_setval(struct ipc_namespace *ns, int semid, int semnum,
unsigned long arg)
{
struct sem_undo *un;
struct sem_array *sma;
struct sem *curr;
int err, val;
DEFINE_WAKE_Q(wake_q);
#if defined(CONFIG_64BIT) && defined(__BIG_ENDIAN)
val = arg >> 32;
#else
val = arg;
#endif
if (val > SEMVMX || val < 0)
return -ERANGE;
rcu_read_lock();
sma = sem_obtain_object_check(ns, semid);
if (IS_ERR(sma)) {
rcu_read_unlock();
return PTR_ERR(sma);
}
if (semnum < 0 || semnum >= sma->sem_nsems) {
rcu_read_unlock();
return -EINVAL;
}
if (ipcperms(ns, &sma->sem_perm, S_IWUGO)) {
rcu_read_unlock();
return -EACCES;
}
err = security_sem_semctl(sma, SETVAL);
if (err) {
rcu_read_unlock();
return -EACCES;
}
sem_lock(sma, NULL, -1);
if (!ipc_valid_object(&sma->sem_perm)) {
sem_unlock(sma, -1);
rcu_read_unlock();
return -EIDRM;
}
curr = &sma->sems[semnum];
ipc_assert_locked_object(&sma->sem_perm);
list_for_each_entry(un, &sma->list_id, list_id)
un->semadj[semnum] = 0;
curr->semval = val;
curr->sempid = task_tgid_vnr(current);
sma->sem_ctime = get_seconds();
do_smart_update(sma, NULL, 0, 0, &wake_q);
sem_unlock(sma, -1);
rcu_read_unlock();
wake_up_q(&wake_q);
return 0;
}
static int semctl_main(struct ipc_namespace *ns, int semid, int semnum,
int cmd, void __user *p)
{
struct sem_array *sma;
struct sem *curr;
int err, nsems;
ushort fast_sem_io[SEMMSL_FAST];
ushort *sem_io = fast_sem_io;
DEFINE_WAKE_Q(wake_q);
rcu_read_lock();
sma = sem_obtain_object_check(ns, semid);
if (IS_ERR(sma)) {
rcu_read_unlock();
return PTR_ERR(sma);
}
nsems = sma->sem_nsems;
err = -EACCES;
if (ipcperms(ns, &sma->sem_perm, cmd == SETALL ? S_IWUGO : S_IRUGO))
goto out_rcu_wakeup;
err = security_sem_semctl(sma, cmd);
if (err)
goto out_rcu_wakeup;
err = -EACCES;
switch (cmd) {
case GETALL:
{
ushort __user *array = p;
int i;
sem_lock(sma, NULL, -1);
if (!ipc_valid_object(&sma->sem_perm)) {
err = -EIDRM;
goto out_unlock;
}
if (nsems > SEMMSL_FAST) {
if (!ipc_rcu_getref(&sma->sem_perm)) {
err = -EIDRM;
goto out_unlock;
}
sem_unlock(sma, -1);
rcu_read_unlock();
sem_io = kvmalloc_array(nsems, sizeof(ushort),
GFP_KERNEL);
if (sem_io == NULL) {
ipc_rcu_putref(&sma->sem_perm, sem_rcu_free);
return -ENOMEM;
}
rcu_read_lock();
sem_lock_and_putref(sma);
if (!ipc_valid_object(&sma->sem_perm)) {
err = -EIDRM;
goto out_unlock;
}
}
for (i = 0; i < sma->sem_nsems; i++)
sem_io[i] = sma->sems[i].semval;
sem_unlock(sma, -1);
rcu_read_unlock();
err = 0;
if (copy_to_user(array, sem_io, nsems*sizeof(ushort)))
err = -EFAULT;
goto out_free;
}
case SETALL:
{
int i;
struct sem_undo *un;
if (!ipc_rcu_getref(&sma->sem_perm)) {
err = -EIDRM;
goto out_rcu_wakeup;
}
rcu_read_unlock();
if (nsems > SEMMSL_FAST) {
sem_io = kvmalloc_array(nsems, sizeof(ushort),
GFP_KERNEL);
if (sem_io == NULL) {
ipc_rcu_putref(&sma->sem_perm, sem_rcu_free);
return -ENOMEM;
}
}
if (copy_from_user(sem_io, p, nsems*sizeof(ushort))) {
ipc_rcu_putref(&sma->sem_perm, sem_rcu_free);
err = -EFAULT;
goto out_free;
}
for (i = 0; i < nsems; i++) {
if (sem_io[i] > SEMVMX) {
ipc_rcu_putref(&sma->sem_perm, sem_rcu_free);
err = -ERANGE;
goto out_free;
}
}
rcu_read_lock();
sem_lock_and_putref(sma);
if (!ipc_valid_object(&sma->sem_perm)) {
err = -EIDRM;
goto out_unlock;
}
for (i = 0; i < nsems; i++) {
sma->sems[i].semval = sem_io[i];
sma->sems[i].sempid = task_tgid_vnr(current);
}
ipc_assert_locked_object(&sma->sem_perm);
list_for_each_entry(un, &sma->list_id, list_id) {
for (i = 0; i < nsems; i++)
un->semadj[i] = 0;
}
sma->sem_ctime = get_seconds();
do_smart_update(sma, NULL, 0, 0, &wake_q);
err = 0;
goto out_unlock;
}
}
err = -EINVAL;
if (semnum < 0 || semnum >= nsems)
goto out_rcu_wakeup;
sem_lock(sma, NULL, -1);
if (!ipc_valid_object(&sma->sem_perm)) {
err = -EIDRM;
goto out_unlock;
}
curr = &sma->sems[semnum];
switch (cmd) {
case GETVAL:
err = curr->semval;
goto out_unlock;
case GETPID:
err = curr->sempid;
goto out_unlock;
case GETNCNT:
err = count_semcnt(sma, semnum, 0);
goto out_unlock;
case GETZCNT:
err = count_semcnt(sma, semnum, 1);
goto out_unlock;
}
out_unlock:
sem_unlock(sma, -1);
out_rcu_wakeup:
rcu_read_unlock();
wake_up_q(&wake_q);
out_free:
if (sem_io != fast_sem_io)
kvfree(sem_io);
return err;
}
static inline unsigned long
copy_semid_from_user(struct semid64_ds *out, void __user *buf, int version)
{
switch (version) {
case IPC_64:
if (copy_from_user(out, buf, sizeof(*out)))
return -EFAULT;
return 0;
case IPC_OLD:
{
struct semid_ds tbuf_old;
if (copy_from_user(&tbuf_old, buf, sizeof(tbuf_old)))
return -EFAULT;
out->sem_perm.uid = tbuf_old.sem_perm.uid;
out->sem_perm.gid = tbuf_old.sem_perm.gid;
out->sem_perm.mode = tbuf_old.sem_perm.mode;
return 0;
}
default:
return -EINVAL;
}
}
static int semctl_down(struct ipc_namespace *ns, int semid,
int cmd, int version, void __user *p)
{
struct sem_array *sma;
int err;
struct semid64_ds semid64;
struct kern_ipc_perm *ipcp;
if (cmd == IPC_SET) {
if (copy_semid_from_user(&semid64, p, version))
return -EFAULT;
}
down_write(&sem_ids(ns).rwsem);
rcu_read_lock();
ipcp = ipcctl_pre_down_nolock(ns, &sem_ids(ns), semid, cmd,
&semid64.sem_perm, 0);
if (IS_ERR(ipcp)) {
err = PTR_ERR(ipcp);
goto out_unlock1;
}
sma = container_of(ipcp, struct sem_array, sem_perm);
err = security_sem_semctl(sma, cmd);
if (err)
goto out_unlock1;
switch (cmd) {
case IPC_RMID:
sem_lock(sma, NULL, -1);
freeary(ns, ipcp);
goto out_up;
case IPC_SET:
sem_lock(sma, NULL, -1);
err = ipc_update_perm(&semid64.sem_perm, ipcp);
if (err)
goto out_unlock0;
sma->sem_ctime = get_seconds();
break;
default:
err = -EINVAL;
goto out_unlock1;
}
out_unlock0:
sem_unlock(sma, -1);
out_unlock1:
rcu_read_unlock();
out_up:
up_write(&sem_ids(ns).rwsem);
return err;
}
static inline int get_undo_list(struct sem_undo_list **undo_listp)
{
struct sem_undo_list *undo_list;
undo_list = current->sysvsem.undo_list;
if (!undo_list) {
undo_list = kzalloc(sizeof(*undo_list), GFP_KERNEL);
if (undo_list == NULL)
return -ENOMEM;
spin_lock_init(&undo_list->lock);
atomic_set(&undo_list->refcnt, 1);
INIT_LIST_HEAD(&undo_list->list_proc);
current->sysvsem.undo_list = undo_list;
}
*undo_listp = undo_list;
return 0;
}
static struct sem_undo *__lookup_undo(struct sem_undo_list *ulp, int semid)
{
struct sem_undo *un;
list_for_each_entry_rcu(un, &ulp->list_proc, list_proc) {
if (un->semid == semid)
return un;
}
return NULL;
}
static struct sem_undo *lookup_undo(struct sem_undo_list *ulp, int semid)
{
struct sem_undo *un;
assert_spin_locked(&ulp->lock);
un = __lookup_undo(ulp, semid);
if (un) {
list_del_rcu(&un->list_proc);
list_add_rcu(&un->list_proc, &ulp->list_proc);
}
return un;
}
static struct sem_undo *find_alloc_undo(struct ipc_namespace *ns, int semid)
{
struct sem_array *sma;
struct sem_undo_list *ulp;
struct sem_undo *un, *new;
int nsems, error;
error = get_undo_list(&ulp);
if (error)
return ERR_PTR(error);
rcu_read_lock();
spin_lock(&ulp->lock);
un = lookup_undo(ulp, semid);
spin_unlock(&ulp->lock);
if (likely(un != NULL))
goto out;
sma = sem_obtain_object_check(ns, semid);
if (IS_ERR(sma)) {
rcu_read_unlock();
return ERR_CAST(sma);
}
nsems = sma->sem_nsems;
if (!ipc_rcu_getref(&sma->sem_perm)) {
rcu_read_unlock();
un = ERR_PTR(-EIDRM);
goto out;
}
rcu_read_unlock();
new = kzalloc(sizeof(struct sem_undo) + sizeof(short)*nsems, GFP_KERNEL);
if (!new) {
ipc_rcu_putref(&sma->sem_perm, sem_rcu_free);
return ERR_PTR(-ENOMEM);
}
rcu_read_lock();
sem_lock_and_putref(sma);
if (!ipc_valid_object(&sma->sem_perm)) {
sem_unlock(sma, -1);
rcu_read_unlock();
kfree(new);
un = ERR_PTR(-EIDRM);
goto out;
}
spin_lock(&ulp->lock);
un = lookup_undo(ulp, semid);
if (un) {
kfree(new);
goto success;
}
new->semadj = (short *) &new[1];
new->ulp = ulp;
new->semid = semid;
assert_spin_locked(&ulp->lock);
list_add_rcu(&new->list_proc, &ulp->list_proc);
ipc_assert_locked_object(&sma->sem_perm);
list_add(&new->list_id, &sma->list_id);
un = new;
success:
spin_unlock(&ulp->lock);
sem_unlock(sma, -1);
out:
return un;
}
int copy_semundo(unsigned long clone_flags, struct task_struct *tsk)
{
struct sem_undo_list *undo_list;
int error;
if (clone_flags & CLONE_SYSVSEM) {
error = get_undo_list(&undo_list);
if (error)
return error;
atomic_inc(&undo_list->refcnt);
tsk->sysvsem.undo_list = undo_list;
} else
tsk->sysvsem.undo_list = NULL;
return 0;
}
void exit_sem(struct task_struct *tsk)
{
struct sem_undo_list *ulp;
ulp = tsk->sysvsem.undo_list;
if (!ulp)
return;
tsk->sysvsem.undo_list = NULL;
if (!atomic_dec_and_test(&ulp->refcnt))
return;
for (;;) {
struct sem_array *sma;
struct sem_undo *un;
int semid, i;
DEFINE_WAKE_Q(wake_q);
cond_resched();
rcu_read_lock();
un = list_entry_rcu(ulp->list_proc.next,
struct sem_undo, list_proc);
if (&un->list_proc == &ulp->list_proc) {
spin_unlock_wait(&ulp->lock);
rcu_read_unlock();
break;
}
spin_lock(&ulp->lock);
semid = un->semid;
spin_unlock(&ulp->lock);
if (semid == -1) {
rcu_read_unlock();
continue;
}
sma = sem_obtain_object_check(tsk->nsproxy->ipc_ns, semid);
if (IS_ERR(sma)) {
rcu_read_unlock();
continue;
}
sem_lock(sma, NULL, -1);
if (!ipc_valid_object(&sma->sem_perm)) {
sem_unlock(sma, -1);
rcu_read_unlock();
continue;
}
un = __lookup_undo(ulp, semid);
if (un == NULL) {
sem_unlock(sma, -1);
rcu_read_unlock();
continue;
}
ipc_assert_locked_object(&sma->sem_perm);
list_del(&un->list_id);
list_del_rcu(&un->list_proc);
for (i = 0; i < sma->sem_nsems; i++) {
struct sem *semaphore = &sma->sems[i];
if (un->semadj[i]) {
semaphore->semval += un->semadj[i];
if (semaphore->semval < 0)
semaphore->semval = 0;
if (semaphore->semval > SEMVMX)
semaphore->semval = SEMVMX;
semaphore->sempid = task_tgid_vnr(current);
}
}
do_smart_update(sma, NULL, 0, 1, &wake_q);
sem_unlock(sma, -1);
rcu_read_unlock();
wake_up_q(&wake_q);
kfree_rcu(un, rcu);
}
kfree(ulp);
}
static int sysvipc_sem_proc_show(struct seq_file *s, void *it)
{
struct user_namespace *user_ns = seq_user_ns(s);
struct kern_ipc_perm *ipcp = it;
struct sem_array *sma = container_of(ipcp, struct sem_array, sem_perm);
time_t sem_otime;
complexmode_enter(sma);
sem_otime = get_semotime(sma);
seq_printf(s,
"%10d %10d %4o %10u %5u %5u %5u %5u %10lu %10lu\n",
sma->sem_perm.key,
sma->sem_perm.id,
sma->sem_perm.mode,
sma->sem_nsems,
from_kuid_munged(user_ns, sma->sem_perm.uid),
from_kgid_munged(user_ns, sma->sem_perm.gid),
from_kuid_munged(user_ns, sma->sem_perm.cuid),
from_kgid_munged(user_ns, sma->sem_perm.cgid),
sem_otime,
sma->sem_ctime);
complexmode_tryleave(sma);
return 0;
}
