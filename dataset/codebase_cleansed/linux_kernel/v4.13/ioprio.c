int set_task_ioprio(struct task_struct *task, int ioprio)
{
int err;
struct io_context *ioc;
const struct cred *cred = current_cred(), *tcred;
rcu_read_lock();
tcred = __task_cred(task);
if (!uid_eq(tcred->uid, cred->euid) &&
!uid_eq(tcred->uid, cred->uid) && !capable(CAP_SYS_NICE)) {
rcu_read_unlock();
return -EPERM;
}
rcu_read_unlock();
err = security_task_setioprio(task, ioprio);
if (err)
return err;
ioc = get_task_io_context(task, GFP_ATOMIC, NUMA_NO_NODE);
if (ioc) {
ioc->ioprio = ioprio;
put_io_context(ioc);
}
return err;
}
static int get_task_ioprio(struct task_struct *p)
{
int ret;
ret = security_task_getioprio(p);
if (ret)
goto out;
ret = IOPRIO_PRIO_VALUE(IOPRIO_CLASS_NONE, IOPRIO_NORM);
task_lock(p);
if (p->io_context)
ret = p->io_context->ioprio;
task_unlock(p);
out:
return ret;
}
int ioprio_best(unsigned short aprio, unsigned short bprio)
{
if (!ioprio_valid(aprio))
aprio = IOPRIO_PRIO_VALUE(IOPRIO_CLASS_BE, IOPRIO_NORM);
if (!ioprio_valid(bprio))
bprio = IOPRIO_PRIO_VALUE(IOPRIO_CLASS_BE, IOPRIO_NORM);
return min(aprio, bprio);
}
