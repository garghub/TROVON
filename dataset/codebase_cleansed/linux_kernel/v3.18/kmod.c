static void free_modprobe_argv(struct subprocess_info *info)
{
kfree(info->argv[3]);
kfree(info->argv);
}
static int call_modprobe(char *module_name, int wait)
{
struct subprocess_info *info;
static char *envp[] = {
"HOME=/",
"TERM=linux",
"PATH=/sbin:/usr/sbin:/bin:/usr/bin",
NULL
};
char **argv = kmalloc(sizeof(char *[5]), GFP_KERNEL);
if (!argv)
goto out;
module_name = kstrdup(module_name, GFP_KERNEL);
if (!module_name)
goto free_argv;
argv[0] = modprobe_path;
argv[1] = "-q";
argv[2] = "--";
argv[3] = module_name;
argv[4] = NULL;
info = call_usermodehelper_setup(modprobe_path, argv, envp, GFP_KERNEL,
NULL, free_modprobe_argv, NULL);
if (!info)
goto free_module_name;
return call_usermodehelper_exec(info, wait | UMH_KILLABLE);
free_module_name:
kfree(module_name);
free_argv:
kfree(argv);
out:
return -ENOMEM;
}
int __request_module(bool wait, const char *fmt, ...)
{
va_list args;
char module_name[MODULE_NAME_LEN];
unsigned int max_modprobes;
int ret;
static atomic_t kmod_concurrent = ATOMIC_INIT(0);
#define MAX_KMOD_CONCURRENT 50
static int kmod_loop_msg;
WARN_ON_ONCE(wait && current_is_async());
if (!modprobe_path[0])
return 0;
va_start(args, fmt);
ret = vsnprintf(module_name, MODULE_NAME_LEN, fmt, args);
va_end(args);
if (ret >= MODULE_NAME_LEN)
return -ENAMETOOLONG;
ret = security_kernel_module_request(module_name);
if (ret)
return ret;
max_modprobes = min(max_threads/2, MAX_KMOD_CONCURRENT);
atomic_inc(&kmod_concurrent);
if (atomic_read(&kmod_concurrent) > max_modprobes) {
if (kmod_loop_msg < 5) {
printk(KERN_ERR
"request_module: runaway loop modprobe %s\n",
module_name);
kmod_loop_msg++;
}
atomic_dec(&kmod_concurrent);
return -ENOMEM;
}
trace_module_request(module_name, wait, _RET_IP_);
ret = call_modprobe(module_name, wait ? UMH_WAIT_PROC : UMH_WAIT_EXEC);
atomic_dec(&kmod_concurrent);
return ret;
}
static void call_usermodehelper_freeinfo(struct subprocess_info *info)
{
if (info->cleanup)
(*info->cleanup)(info);
kfree(info);
}
static void umh_complete(struct subprocess_info *sub_info)
{
struct completion *comp = xchg(&sub_info->complete, NULL);
if (comp)
complete(comp);
else
call_usermodehelper_freeinfo(sub_info);
}
static int ____call_usermodehelper(void *data)
{
struct subprocess_info *sub_info = data;
int wait = sub_info->wait & ~UMH_KILLABLE;
struct cred *new;
int retval;
spin_lock_irq(&current->sighand->siglock);
flush_signal_handlers(current, 1);
spin_unlock_irq(&current->sighand->siglock);
set_cpus_allowed_ptr(current, cpu_all_mask);
set_user_nice(current, 0);
retval = -ENOMEM;
new = prepare_kernel_cred(current);
if (!new)
goto out;
spin_lock(&umh_sysctl_lock);
new->cap_bset = cap_intersect(usermodehelper_bset, new->cap_bset);
new->cap_inheritable = cap_intersect(usermodehelper_inheritable,
new->cap_inheritable);
spin_unlock(&umh_sysctl_lock);
if (sub_info->init) {
retval = sub_info->init(sub_info, new);
if (retval) {
abort_creds(new);
goto out;
}
}
commit_creds(new);
retval = do_execve(getname_kernel(sub_info->path),
(const char __user *const __user *)sub_info->argv,
(const char __user *const __user *)sub_info->envp);
out:
sub_info->retval = retval;
if (wait != UMH_WAIT_PROC)
umh_complete(sub_info);
if (!retval)
return 0;
do_exit(0);
}
static int call_helper(void *data)
{
kmod_thread_locker = current;
return ____call_usermodehelper(data);
}
static int wait_for_helper(void *data)
{
struct subprocess_info *sub_info = data;
pid_t pid;
kernel_sigaction(SIGCHLD, SIG_DFL);
pid = kernel_thread(____call_usermodehelper, sub_info, SIGCHLD);
if (pid < 0) {
sub_info->retval = pid;
} else {
int ret = -ECHILD;
sys_wait4(pid, (int __user *)&ret, 0, NULL);
if (ret)
sub_info->retval = ret;
}
umh_complete(sub_info);
do_exit(0);
}
static void __call_usermodehelper(struct work_struct *work)
{
struct subprocess_info *sub_info =
container_of(work, struct subprocess_info, work);
int wait = sub_info->wait & ~UMH_KILLABLE;
pid_t pid;
if (wait == UMH_WAIT_PROC)
pid = kernel_thread(wait_for_helper, sub_info,
CLONE_FS | CLONE_FILES | SIGCHLD);
else {
pid = kernel_thread(call_helper, sub_info,
CLONE_VFORK | SIGCHLD);
kmod_thread_locker = NULL;
}
if (pid < 0) {
sub_info->retval = pid;
umh_complete(sub_info);
}
}
int usermodehelper_read_trylock(void)
{
DEFINE_WAIT(wait);
int ret = 0;
down_read(&umhelper_sem);
for (;;) {
prepare_to_wait(&usermodehelper_disabled_waitq, &wait,
TASK_INTERRUPTIBLE);
if (!usermodehelper_disabled)
break;
if (usermodehelper_disabled == UMH_DISABLED)
ret = -EAGAIN;
up_read(&umhelper_sem);
if (ret)
break;
schedule();
try_to_freeze();
down_read(&umhelper_sem);
}
finish_wait(&usermodehelper_disabled_waitq, &wait);
return ret;
}
long usermodehelper_read_lock_wait(long timeout)
{
DEFINE_WAIT(wait);
if (timeout < 0)
return -EINVAL;
down_read(&umhelper_sem);
for (;;) {
prepare_to_wait(&usermodehelper_disabled_waitq, &wait,
TASK_UNINTERRUPTIBLE);
if (!usermodehelper_disabled)
break;
up_read(&umhelper_sem);
timeout = schedule_timeout(timeout);
if (!timeout)
break;
down_read(&umhelper_sem);
}
finish_wait(&usermodehelper_disabled_waitq, &wait);
return timeout;
}
void usermodehelper_read_unlock(void)
{
up_read(&umhelper_sem);
}
void __usermodehelper_set_disable_depth(enum umh_disable_depth depth)
{
down_write(&umhelper_sem);
usermodehelper_disabled = depth;
wake_up(&usermodehelper_disabled_waitq);
up_write(&umhelper_sem);
}
int __usermodehelper_disable(enum umh_disable_depth depth)
{
long retval;
if (!depth)
return -EINVAL;
down_write(&umhelper_sem);
usermodehelper_disabled = depth;
up_write(&umhelper_sem);
retval = wait_event_timeout(running_helpers_waitq,
atomic_read(&running_helpers) == 0,
RUNNING_HELPERS_TIMEOUT);
if (retval)
return 0;
__usermodehelper_set_disable_depth(UMH_ENABLED);
return -EAGAIN;
}
static void helper_lock(void)
{
atomic_inc(&running_helpers);
smp_mb__after_atomic();
}
static void helper_unlock(void)
{
if (atomic_dec_and_test(&running_helpers))
wake_up(&running_helpers_waitq);
}
struct subprocess_info *call_usermodehelper_setup(char *path, char **argv,
char **envp, gfp_t gfp_mask,
int (*init)(struct subprocess_info *info, struct cred *new),
void (*cleanup)(struct subprocess_info *info),
void *data)
{
struct subprocess_info *sub_info;
sub_info = kzalloc(sizeof(struct subprocess_info), gfp_mask);
if (!sub_info)
goto out;
INIT_WORK(&sub_info->work, __call_usermodehelper);
sub_info->path = path;
sub_info->argv = argv;
sub_info->envp = envp;
sub_info->cleanup = cleanup;
sub_info->init = init;
sub_info->data = data;
out:
return sub_info;
}
int call_usermodehelper_exec(struct subprocess_info *sub_info, int wait)
{
DECLARE_COMPLETION_ONSTACK(done);
int retval = 0;
if (!sub_info->path) {
call_usermodehelper_freeinfo(sub_info);
return -EINVAL;
}
helper_lock();
if (!khelper_wq || usermodehelper_disabled) {
retval = -EBUSY;
goto out;
}
if (wait != UMH_NO_WAIT && current == kmod_thread_locker) {
retval = -EBUSY;
goto out;
}
sub_info->complete = (wait == UMH_NO_WAIT) ? NULL : &done;
sub_info->wait = wait;
queue_work(khelper_wq, &sub_info->work);
if (wait == UMH_NO_WAIT)
goto unlock;
if (wait & UMH_KILLABLE) {
retval = wait_for_completion_killable(&done);
if (!retval)
goto wait_done;
if (xchg(&sub_info->complete, NULL))
goto unlock;
}
wait_for_completion(&done);
wait_done:
retval = sub_info->retval;
out:
call_usermodehelper_freeinfo(sub_info);
unlock:
helper_unlock();
return retval;
}
int call_usermodehelper(char *path, char **argv, char **envp, int wait)
{
struct subprocess_info *info;
gfp_t gfp_mask = (wait == UMH_NO_WAIT) ? GFP_ATOMIC : GFP_KERNEL;
info = call_usermodehelper_setup(path, argv, envp, gfp_mask,
NULL, NULL, NULL);
if (info == NULL)
return -ENOMEM;
return call_usermodehelper_exec(info, wait);
}
static int proc_cap_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table t;
unsigned long cap_array[_KERNEL_CAPABILITY_U32S];
kernel_cap_t new_cap;
int err, i;
if (write && (!capable(CAP_SETPCAP) ||
!capable(CAP_SYS_MODULE)))
return -EPERM;
spin_lock(&umh_sysctl_lock);
for (i = 0; i < _KERNEL_CAPABILITY_U32S; i++) {
if (table->data == CAP_BSET)
cap_array[i] = usermodehelper_bset.cap[i];
else if (table->data == CAP_PI)
cap_array[i] = usermodehelper_inheritable.cap[i];
else
BUG();
}
spin_unlock(&umh_sysctl_lock);
t = *table;
t.data = &cap_array;
err = proc_doulongvec_minmax(&t, write, buffer, lenp, ppos);
if (err < 0)
return err;
for (i = 0; i < _KERNEL_CAPABILITY_U32S; i++)
new_cap.cap[i] = cap_array[i];
spin_lock(&umh_sysctl_lock);
if (write) {
if (table->data == CAP_BSET)
usermodehelper_bset = cap_intersect(usermodehelper_bset, new_cap);
if (table->data == CAP_PI)
usermodehelper_inheritable = cap_intersect(usermodehelper_inheritable, new_cap);
}
spin_unlock(&umh_sysctl_lock);
return 0;
}
void __init usermodehelper_init(void)
{
khelper_wq = create_singlethread_workqueue("khelper");
BUG_ON(!khelper_wq);
}
