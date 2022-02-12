int set_task_ioprio(struct task_struct *task, int ioprio)
{
int err;
struct io_context *ioc;
const struct cred *cred = current_cred(), *tcred;
rcu_read_lock();
tcred = __task_cred(task);
if (tcred->uid != cred->euid &&
tcred->uid != cred->uid && !capable(CAP_SYS_NICE)) {
rcu_read_unlock();
return -EPERM;
}
rcu_read_unlock();
err = security_task_setioprio(task, ioprio);
if (err)
return err;
task_lock(task);
do {
ioc = task->io_context;
smp_read_barrier_depends();
if (ioc)
break;
ioc = alloc_io_context(GFP_ATOMIC, -1);
if (!ioc) {
err = -ENOMEM;
break;
}
task->io_context = ioc;
} while (1);
if (!err) {
ioc->ioprio = ioprio;
ioc->ioprio_changed = 1;
}
task_unlock(task);
return err;
}
static int get_task_ioprio(struct task_struct *p)
{
int ret;
ret = security_task_getioprio(p);
if (ret)
goto out;
ret = IOPRIO_PRIO_VALUE(IOPRIO_CLASS_NONE, IOPRIO_NORM);
if (p->io_context)
ret = p->io_context->ioprio;
out:
return ret;
}
int ioprio_best(unsigned short aprio, unsigned short bprio)
{
unsigned short aclass = IOPRIO_PRIO_CLASS(aprio);
unsigned short bclass = IOPRIO_PRIO_CLASS(bprio);
if (aclass == IOPRIO_CLASS_NONE)
aclass = IOPRIO_CLASS_BE;
if (bclass == IOPRIO_CLASS_NONE)
bclass = IOPRIO_CLASS_BE;
if (aclass == bclass)
return min(aprio, bprio);
if (aclass > bclass)
return bprio;
else
return aprio;
}
