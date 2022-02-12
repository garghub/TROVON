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
void __init sem_init (void)
{
sem_init_ns(&init_ipc_ns);
ipc_init_proc_interface("sysvipc/sem",
" key semid perms nsems uid gid cuid cgid otime ctime\n",
IPC_SEM_IDS, sysvipc_sem_proc_show);
}
static inline int sem_lock(struct sem_array *sma, struct sembuf *sops,
int nsops)
{
int locknum;
again:
if (nsops == 1 && !sma->complex_count) {
struct sem *sem = sma->sem_base + sops->sem_num;
spin_lock(&sem->lock);
if (unlikely(sma->complex_count)) {
spin_unlock(&sem->lock);
goto lock_array;
}
if (unlikely(spin_is_locked(&sma->sem_perm.lock))) {
spin_unlock(&sem->lock);
spin_unlock_wait(&sma->sem_perm.lock);
goto again;
}
locknum = sops->sem_num;
} else {
int i;
lock_array:
spin_lock(&sma->sem_perm.lock);
for (i = 0; i < sma->sem_nsems; i++) {
struct sem *sem = sma->sem_base + i;
spin_unlock_wait(&sem->lock);
}
locknum = -1;
}
return locknum;
}
static inline void sem_unlock(struct sem_array *sma, int locknum)
{
if (locknum == -1) {
spin_unlock(&sma->sem_perm.lock);
} else {
struct sem *sem = sma->sem_base + locknum;
spin_unlock(&sem->lock);
}
}
static inline struct sem_array *sem_obtain_lock(struct ipc_namespace *ns,
int id, struct sembuf *sops, int nsops, int *locknum)
{
struct kern_ipc_perm *ipcp;
struct sem_array *sma;
ipcp = ipc_obtain_object(&sem_ids(ns), id);
if (IS_ERR(ipcp))
return ERR_CAST(ipcp);
sma = container_of(ipcp, struct sem_array, sem_perm);
*locknum = sem_lock(sma, sops, nsops);
if (!ipcp->deleted)
return container_of(ipcp, struct sem_array, sem_perm);
sem_unlock(sma, *locknum);
return ERR_PTR(-EINVAL);
}
static inline struct sem_array *sem_obtain_object(struct ipc_namespace *ns, int id)
{
struct kern_ipc_perm *ipcp = ipc_obtain_object(&sem_ids(ns), id);
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
ipc_rcu_putref(sma);
}
static inline void sem_putref(struct sem_array *sma)
{
ipc_rcu_putref(sma);
}
static inline void sem_rmid(struct ipc_namespace *ns, struct sem_array *s)
{
ipc_rmid(&sem_ids(ns), &s->sem_perm);
}
static int newary(struct ipc_namespace *ns, struct ipc_params *params)
{
int id;
int retval;
struct sem_array *sma;
int size;
key_t key = params->key;
int nsems = params->u.nsems;
int semflg = params->flg;
int i;
if (!nsems)
return -EINVAL;
if (ns->used_sems + nsems > ns->sc_semmns)
return -ENOSPC;
size = sizeof (*sma) + nsems * sizeof (struct sem);
sma = ipc_rcu_alloc(size);
if (!sma) {
return -ENOMEM;
}
memset (sma, 0, size);
sma->sem_perm.mode = (semflg & S_IRWXUGO);
sma->sem_perm.key = key;
sma->sem_perm.security = NULL;
retval = security_sem_alloc(sma);
if (retval) {
ipc_rcu_putref(sma);
return retval;
}
id = ipc_addid(&sem_ids(ns), &sma->sem_perm, ns->sc_semmni);
if (id < 0) {
security_sem_free(sma);
ipc_rcu_putref(sma);
return id;
}
ns->used_sems += nsems;
sma->sem_base = (struct sem *) &sma[1];
for (i = 0; i < nsems; i++) {
INIT_LIST_HEAD(&sma->sem_base[i].sem_pending);
spin_lock_init(&sma->sem_base[i].lock);
}
sma->complex_count = 0;
INIT_LIST_HEAD(&sma->sem_pending);
INIT_LIST_HEAD(&sma->list_id);
sma->sem_nsems = nsems;
sma->sem_ctime = get_seconds();
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
static int try_atomic_semop (struct sem_array * sma, struct sembuf * sops,
int nsops, struct sem_undo *un, int pid)
{
int result, sem_op;
struct sembuf *sop;
struct sem * curr;
for (sop = sops; sop < sops + nsops; sop++) {
curr = sma->sem_base + sop->sem_num;
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
}
curr->semval = result;
}
sop--;
while (sop >= sops) {
sma->sem_base[sop->sem_num].sempid = pid;
if (sop->sem_flg & SEM_UNDO)
un->semadj[sop->sem_num] -= sop->sem_op;
sop--;
}
return 0;
out_of_range:
result = -ERANGE;
goto undo;
would_block:
if (sop->sem_flg & IPC_NOWAIT)
result = -EAGAIN;
else
result = 1;
undo:
sop--;
while (sop >= sops) {
sma->sem_base[sop->sem_num].semval -= sop->sem_op;
sop--;
}
return result;
}
static void wake_up_sem_queue_prepare(struct list_head *pt,
struct sem_queue *q, int error)
{
if (list_empty(pt)) {
preempt_disable();
}
q->status = IN_WAKEUP;
q->pid = error;
list_add_tail(&q->list, pt);
}
static void wake_up_sem_queue_do(struct list_head *pt)
{
struct sem_queue *q, *t;
int did_something;
did_something = !list_empty(pt);
list_for_each_entry_safe(q, t, pt, list) {
wake_up_process(q->sleeper);
smp_wmb();
q->status = q->pid;
}
if (did_something)
preempt_enable();
}
static void unlink_queue(struct sem_array *sma, struct sem_queue *q)
{
list_del(&q->list);
if (q->nsops > 1)
sma->complex_count--;
}
static int check_restart(struct sem_array *sma, struct sem_queue *q)
{
struct sem *curr;
struct sem_queue *h;
if (q->alter == 0)
return 0;
if (sma->complex_count)
return 1;
if (q->nsops > 1)
return 1;
curr = sma->sem_base + q->sops[0].sem_num;
if (list_empty(&curr->sem_pending))
return 0;
if (curr->semval) {
BUG_ON(q->sops[0].sem_op >= 0);
return 0;
}
h = list_first_entry(&curr->sem_pending, struct sem_queue, list);
BUG_ON(h->nsops != 1);
BUG_ON(h->sops[0].sem_num != q->sops[0].sem_num);
if (h->sops[0].sem_op == 0)
return 1;
return 0;
}
static int update_queue(struct sem_array *sma, int semnum, struct list_head *pt)
{
struct sem_queue *q;
struct list_head *walk;
struct list_head *pending_list;
int semop_completed = 0;
if (semnum == -1)
pending_list = &sma->sem_pending;
else
pending_list = &sma->sem_base[semnum].sem_pending;
again:
walk = pending_list->next;
while (walk != pending_list) {
int error, restart;
q = container_of(walk, struct sem_queue, list);
walk = walk->next;
if (semnum != -1 && sma->sem_base[semnum].semval == 0 &&
q->alter)
break;
error = try_atomic_semop(sma, q->sops, q->nsops,
q->undo, q->pid);
if (error > 0)
continue;
unlink_queue(sma, q);
if (error) {
restart = 0;
} else {
semop_completed = 1;
restart = check_restart(sma, q);
}
wake_up_sem_queue_prepare(pt, q, error);
if (restart)
goto again;
}
return semop_completed;
}
static void do_smart_update(struct sem_array *sma, struct sembuf *sops, int nsops,
int otime, struct list_head *pt)
{
int i;
int progress;
progress = 1;
retry_global:
if (sma->complex_count) {
if (update_queue(sma, -1, pt)) {
progress = 1;
otime = 1;
sops = NULL;
}
}
if (!progress)
goto done;
if (!sops) {
for (i = 0; i < sma->sem_nsems; i++) {
if (update_queue(sma, i, pt)) {
otime = 1;
progress = 1;
}
}
goto done_checkretry;
}
for (i = 0; i < nsops; i++) {
if (sops[i].sem_op > 0 ||
(sops[i].sem_op < 0 &&
sma->sem_base[sops[i].sem_num].semval == 0))
if (update_queue(sma, sops[i].sem_num, pt)) {
otime = 1;
progress = 1;
}
}
done_checkretry:
if (progress) {
progress = 0;
goto retry_global;
}
done:
if (otime)
sma->sem_otime = get_seconds();
}
static int count_semncnt (struct sem_array * sma, ushort semnum)
{
int semncnt;
struct sem_queue * q;
semncnt = 0;
list_for_each_entry(q, &sma->sem_base[semnum].sem_pending, list) {
struct sembuf * sops = q->sops;
BUG_ON(sops->sem_num != semnum);
if ((sops->sem_op < 0) && !(sops->sem_flg & IPC_NOWAIT))
semncnt++;
}
list_for_each_entry(q, &sma->sem_pending, list) {
struct sembuf * sops = q->sops;
int nsops = q->nsops;
int i;
for (i = 0; i < nsops; i++)
if (sops[i].sem_num == semnum
&& (sops[i].sem_op < 0)
&& !(sops[i].sem_flg & IPC_NOWAIT))
semncnt++;
}
return semncnt;
}
static int count_semzcnt (struct sem_array * sma, ushort semnum)
{
int semzcnt;
struct sem_queue * q;
semzcnt = 0;
list_for_each_entry(q, &sma->sem_base[semnum].sem_pending, list) {
struct sembuf * sops = q->sops;
BUG_ON(sops->sem_num != semnum);
if ((sops->sem_op == 0) && !(sops->sem_flg & IPC_NOWAIT))
semzcnt++;
}
list_for_each_entry(q, &sma->sem_pending, list) {
struct sembuf * sops = q->sops;
int nsops = q->nsops;
int i;
for (i = 0; i < nsops; i++)
if (sops[i].sem_num == semnum
&& (sops[i].sem_op == 0)
&& !(sops[i].sem_flg & IPC_NOWAIT))
semzcnt++;
}
return semzcnt;
}
static void freeary(struct ipc_namespace *ns, struct kern_ipc_perm *ipcp)
{
struct sem_undo *un, *tu;
struct sem_queue *q, *tq;
struct sem_array *sma = container_of(ipcp, struct sem_array, sem_perm);
struct list_head tasks;
int i;
assert_spin_locked(&sma->sem_perm.lock);
list_for_each_entry_safe(un, tu, &sma->list_id, list_id) {
list_del(&un->list_id);
spin_lock(&un->ulp->lock);
un->semid = -1;
list_del_rcu(&un->list_proc);
spin_unlock(&un->ulp->lock);
kfree_rcu(un, rcu);
}
INIT_LIST_HEAD(&tasks);
list_for_each_entry_safe(q, tq, &sma->sem_pending, list) {
unlink_queue(sma, q);
wake_up_sem_queue_prepare(&tasks, q, -EIDRM);
}
for (i = 0; i < sma->sem_nsems; i++) {
struct sem *sem = sma->sem_base + i;
list_for_each_entry_safe(q, tq, &sem->sem_pending, list) {
unlink_queue(sma, q);
wake_up_sem_queue_prepare(&tasks, q, -EIDRM);
}
}
sem_rmid(ns, sma);
sem_unlock(sma, -1);
rcu_read_unlock();
wake_up_sem_queue_do(&tasks);
ns->used_sems -= sma->sem_nsems;
security_sem_free(sma);
ipc_rcu_putref(sma);
}
static unsigned long copy_semid_to_user(void __user *buf, struct semid64_ds *in, int version)
{
switch(version) {
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
static int semctl_nolock(struct ipc_namespace *ns, int semid,
int cmd, int version, void __user *p)
{
int err;
struct sem_array *sma;
switch(cmd) {
case IPC_INFO:
case SEM_INFO:
{
struct seminfo seminfo;
int max_id;
err = security_sem_semctl(NULL, cmd);
if (err)
return err;
memset(&seminfo,0,sizeof(seminfo));
seminfo.semmni = ns->sc_semmni;
seminfo.semmns = ns->sc_semmns;
seminfo.semmsl = ns->sc_semmsl;
seminfo.semopm = ns->sc_semopm;
seminfo.semvmx = SEMVMX;
seminfo.semmnu = SEMMNU;
seminfo.semmap = SEMMAP;
seminfo.semume = SEMUME;
down_read(&sem_ids(ns).rw_mutex);
if (cmd == SEM_INFO) {
seminfo.semusz = sem_ids(ns).in_use;
seminfo.semaem = ns->used_sems;
} else {
seminfo.semusz = SEMUSZ;
seminfo.semaem = SEMAEM;
}
max_id = ipc_get_maxid(&sem_ids(ns));
up_read(&sem_ids(ns).rw_mutex);
if (copy_to_user(p, &seminfo, sizeof(struct seminfo)))
return -EFAULT;
return (max_id < 0) ? 0: max_id;
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
tbuf.sem_otime = sma->sem_otime;
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
struct sem* curr;
int err;
struct list_head tasks;
int val;
#if defined(CONFIG_64BIT) && defined(__BIG_ENDIAN)
val = arg >> 32;
#else
val = arg;
#endif
if (val > SEMVMX || val < 0)
return -ERANGE;
INIT_LIST_HEAD(&tasks);
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
curr = &sma->sem_base[semnum];
assert_spin_locked(&sma->sem_perm.lock);
list_for_each_entry(un, &sma->list_id, list_id)
un->semadj[semnum] = 0;
curr->semval = val;
curr->sempid = task_tgid_vnr(current);
sma->sem_ctime = get_seconds();
do_smart_update(sma, NULL, 0, 0, &tasks);
sem_unlock(sma, -1);
rcu_read_unlock();
wake_up_sem_queue_do(&tasks);
return 0;
}
static int semctl_main(struct ipc_namespace *ns, int semid, int semnum,
int cmd, void __user *p)
{
struct sem_array *sma;
struct sem* curr;
int err, nsems;
ushort fast_sem_io[SEMMSL_FAST];
ushort* sem_io = fast_sem_io;
struct list_head tasks;
INIT_LIST_HEAD(&tasks);
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
if(nsems > SEMMSL_FAST) {
if (!ipc_rcu_getref(sma)) {
sem_unlock(sma, -1);
rcu_read_unlock();
err = -EIDRM;
goto out_free;
}
sem_unlock(sma, -1);
rcu_read_unlock();
sem_io = ipc_alloc(sizeof(ushort)*nsems);
if(sem_io == NULL) {
sem_putref(sma);
return -ENOMEM;
}
rcu_read_lock();
sem_lock_and_putref(sma);
if (sma->sem_perm.deleted) {
sem_unlock(sma, -1);
rcu_read_unlock();
err = -EIDRM;
goto out_free;
}
}
for (i = 0; i < sma->sem_nsems; i++)
sem_io[i] = sma->sem_base[i].semval;
sem_unlock(sma, -1);
rcu_read_unlock();
err = 0;
if(copy_to_user(array, sem_io, nsems*sizeof(ushort)))
err = -EFAULT;
goto out_free;
}
case SETALL:
{
int i;
struct sem_undo *un;
if (!ipc_rcu_getref(sma)) {
rcu_read_unlock();
return -EIDRM;
}
rcu_read_unlock();
if(nsems > SEMMSL_FAST) {
sem_io = ipc_alloc(sizeof(ushort)*nsems);
if(sem_io == NULL) {
sem_putref(sma);
return -ENOMEM;
}
}
if (copy_from_user (sem_io, p, nsems*sizeof(ushort))) {
sem_putref(sma);
err = -EFAULT;
goto out_free;
}
for (i = 0; i < nsems; i++) {
if (sem_io[i] > SEMVMX) {
sem_putref(sma);
err = -ERANGE;
goto out_free;
}
}
rcu_read_lock();
sem_lock_and_putref(sma);
if (sma->sem_perm.deleted) {
sem_unlock(sma, -1);
rcu_read_unlock();
err = -EIDRM;
goto out_free;
}
for (i = 0; i < nsems; i++)
sma->sem_base[i].semval = sem_io[i];
assert_spin_locked(&sma->sem_perm.lock);
list_for_each_entry(un, &sma->list_id, list_id) {
for (i = 0; i < nsems; i++)
un->semadj[i] = 0;
}
sma->sem_ctime = get_seconds();
do_smart_update(sma, NULL, 0, 0, &tasks);
err = 0;
goto out_unlock;
}
}
err = -EINVAL;
if (semnum < 0 || semnum >= nsems)
goto out_rcu_wakeup;
sem_lock(sma, NULL, -1);
curr = &sma->sem_base[semnum];
switch (cmd) {
case GETVAL:
err = curr->semval;
goto out_unlock;
case GETPID:
err = curr->sempid;
goto out_unlock;
case GETNCNT:
err = count_semncnt(sma,semnum);
goto out_unlock;
case GETZCNT:
err = count_semzcnt(sma,semnum);
goto out_unlock;
}
out_unlock:
sem_unlock(sma, -1);
out_rcu_wakeup:
rcu_read_unlock();
wake_up_sem_queue_do(&tasks);
out_free:
if(sem_io != fast_sem_io)
ipc_free(sem_io, sizeof(ushort)*nsems);
return err;
}
static inline unsigned long
copy_semid_from_user(struct semid64_ds *out, void __user *buf, int version)
{
switch(version) {
case IPC_64:
if (copy_from_user(out, buf, sizeof(*out)))
return -EFAULT;
return 0;
case IPC_OLD:
{
struct semid_ds tbuf_old;
if(copy_from_user(&tbuf_old, buf, sizeof(tbuf_old)))
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
if(cmd == IPC_SET) {
if (copy_semid_from_user(&semid64, p, version))
return -EFAULT;
}
ipcp = ipcctl_pre_down_nolock(ns, &sem_ids(ns), semid, cmd,
&semid64.sem_perm, 0);
if (IS_ERR(ipcp))
return PTR_ERR(ipcp);
sma = container_of(ipcp, struct sem_array, sem_perm);
err = security_sem_semctl(sma, cmd);
if (err) {
rcu_read_unlock();
goto out_up;
}
switch(cmd){
case IPC_RMID:
sem_lock(sma, NULL, -1);
freeary(ns, ipcp);
goto out_up;
case IPC_SET:
sem_lock(sma, NULL, -1);
err = ipc_update_perm(&semid64.sem_perm, ipcp);
if (err)
goto out_unlock;
sma->sem_ctime = get_seconds();
break;
default:
rcu_read_unlock();
err = -EINVAL;
goto out_up;
}
out_unlock:
sem_unlock(sma, -1);
rcu_read_unlock();
out_up:
up_write(&sem_ids(ns).rw_mutex);
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
if (likely(un!=NULL))
goto out;
sma = sem_obtain_object_check(ns, semid);
if (IS_ERR(sma)) {
rcu_read_unlock();
return ERR_CAST(sma);
}
nsems = sma->sem_nsems;
if (!ipc_rcu_getref(sma)) {
rcu_read_unlock();
un = ERR_PTR(-EIDRM);
goto out;
}
rcu_read_unlock();
new = kzalloc(sizeof(struct sem_undo) + sizeof(short)*nsems, GFP_KERNEL);
if (!new) {
sem_putref(sma);
return ERR_PTR(-ENOMEM);
}
rcu_read_lock();
sem_lock_and_putref(sma);
if (sma->sem_perm.deleted) {
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
assert_spin_locked(&sma->sem_perm.lock);
list_add(&new->list_id, &sma->list_id);
un = new;
success:
spin_unlock(&ulp->lock);
sem_unlock(sma, -1);
out:
return un;
}
static int get_queue_result(struct sem_queue *q)
{
int error;
error = q->status;
while (unlikely(error == IN_WAKEUP)) {
cpu_relax();
error = q->status;
}
return error;
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
struct list_head tasks;
int semid, i;
rcu_read_lock();
un = list_entry_rcu(ulp->list_proc.next,
struct sem_undo, list_proc);
if (&un->list_proc == &ulp->list_proc)
semid = -1;
else
semid = un->semid;
if (semid == -1) {
rcu_read_unlock();
break;
}
sma = sem_obtain_object_check(tsk->nsproxy->ipc_ns, un->semid);
if (IS_ERR(sma)) {
rcu_read_unlock();
continue;
}
sem_lock(sma, NULL, -1);
un = __lookup_undo(ulp, semid);
if (un == NULL) {
sem_unlock(sma, -1);
rcu_read_unlock();
continue;
}
assert_spin_locked(&sma->sem_perm.lock);
list_del(&un->list_id);
spin_lock(&ulp->lock);
list_del_rcu(&un->list_proc);
spin_unlock(&ulp->lock);
for (i = 0; i < sma->sem_nsems; i++) {
struct sem * semaphore = &sma->sem_base[i];
if (un->semadj[i]) {
semaphore->semval += un->semadj[i];
if (semaphore->semval < 0)
semaphore->semval = 0;
if (semaphore->semval > SEMVMX)
semaphore->semval = SEMVMX;
semaphore->sempid = task_tgid_vnr(current);
}
}
INIT_LIST_HEAD(&tasks);
do_smart_update(sma, NULL, 0, 1, &tasks);
sem_unlock(sma, -1);
rcu_read_unlock();
wake_up_sem_queue_do(&tasks);
kfree_rcu(un, rcu);
}
kfree(ulp);
}
static int sysvipc_sem_proc_show(struct seq_file *s, void *it)
{
struct user_namespace *user_ns = seq_user_ns(s);
struct sem_array *sma = it;
return seq_printf(s,
"%10d %10d %4o %10u %5u %5u %5u %5u %10lu %10lu\n",
sma->sem_perm.key,
sma->sem_perm.id,
sma->sem_perm.mode,
sma->sem_nsems,
from_kuid_munged(user_ns, sma->sem_perm.uid),
from_kgid_munged(user_ns, sma->sem_perm.gid),
from_kuid_munged(user_ns, sma->sem_perm.cuid),
from_kgid_munged(user_ns, sma->sem_perm.cgid),
sma->sem_otime,
sma->sem_ctime);
}
