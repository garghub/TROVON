int __request_module(bool wait, const char *fmt, ...)
{
va_list args;
char module_name[MODULE_NAME_LEN];
unsigned int max_modprobes;
int ret;
char *argv[] = { modprobe_path, "-q", "--", module_name, NULL };
static char *envp[] = { "HOME=/",
"TERM=linux",
"PATH=/sbin:/usr/sbin:/bin:/usr/bin",
NULL };
static atomic_t kmod_concurrent = ATOMIC_INIT(0);
#define MAX_KMOD_CONCURRENT 50
static int kmod_loop_msg;
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
if (kmod_loop_msg++ < 5)
printk(KERN_ERR
"request_module: runaway loop modprobe %s\n",
module_name);
atomic_dec(&kmod_concurrent);
return -ENOMEM;
}
trace_module_request(module_name, wait, _RET_IP_);
ret = call_usermodehelper_fns(modprobe_path, argv, envp,
wait ? UMH_WAIT_PROC : UMH_WAIT_EXEC,
NULL, NULL, NULL);
atomic_dec(&kmod_concurrent);
return ret;
}
static int ____call_usermodehelper(void *data)
{
struct subprocess_info *sub_info = data;
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
goto fail;
spin_lock(&umh_sysctl_lock);
new->cap_bset = cap_intersect(usermodehelper_bset, new->cap_bset);
new->cap_inheritable = cap_intersect(usermodehelper_inheritable,
new->cap_inheritable);
spin_unlock(&umh_sysctl_lock);
if (sub_info->init) {
retval = sub_info->init(sub_info, new);
if (retval) {
abort_creds(new);
goto fail;
}
}
commit_creds(new);
retval = kernel_execve(sub_info->path,
(const char *const *)sub_info->argv,
(const char *const *)sub_info->envp);
fail:
sub_info->retval = retval;
do_exit(0);
}
void call_usermodehelper_freeinfo(struct subprocess_info *info)
{
if (info->cleanup)
(*info->cleanup)(info);
kfree(info);
}
static int wait_for_helper(void *data)
{
struct subprocess_info *sub_info = data;
pid_t pid;
spin_lock_irq(&current->sighand->siglock);
current->sighand->action[SIGCHLD-1].sa.sa_handler = SIG_DFL;
spin_unlock_irq(&current->sighand->siglock);
pid = kernel_thread(____call_usermodehelper, sub_info, SIGCHLD);
if (pid < 0) {
sub_info->retval = pid;
} else {
int ret = -ECHILD;
sys_wait4(pid, (int __user *)&ret, 0, NULL);
if (ret)
sub_info->retval = ret;
}
complete(sub_info->complete);
return 0;
}
static void __call_usermodehelper(struct work_struct *work)
{
struct subprocess_info *sub_info =
container_of(work, struct subprocess_info, work);
enum umh_wait wait = sub_info->wait;
pid_t pid;
if (wait == UMH_WAIT_PROC)
pid = kernel_thread(wait_for_helper, sub_info,
CLONE_FS | CLONE_FILES | SIGCHLD);
else
pid = kernel_thread(____call_usermodehelper, sub_info,
CLONE_VFORK | SIGCHLD);
switch (wait) {
case UMH_NO_WAIT:
call_usermodehelper_freeinfo(sub_info);
break;
case UMH_WAIT_PROC:
if (pid > 0)
break;
case UMH_WAIT_EXEC:
if (pid < 0)
sub_info->retval = pid;
complete(sub_info->complete);
}
}
int usermodehelper_disable(void)
{
long retval;
usermodehelper_disabled = 1;
smp_mb();
retval = wait_event_timeout(running_helpers_waitq,
atomic_read(&running_helpers) == 0,
RUNNING_HELPERS_TIMEOUT);
if (retval)
return 0;
usermodehelper_disabled = 0;
return -EAGAIN;
}
void usermodehelper_enable(void)
{
usermodehelper_disabled = 0;
}
bool usermodehelper_is_disabled(void)
{
return usermodehelper_disabled;
}
static void helper_lock(void)
{
atomic_inc(&running_helpers);
smp_mb__after_atomic_inc();
}
static void helper_unlock(void)
{
if (atomic_dec_and_test(&running_helpers))
wake_up(&running_helpers_waitq);
}
struct subprocess_info *call_usermodehelper_setup(char *path, char **argv,
char **envp, gfp_t gfp_mask)
{
struct subprocess_info *sub_info;
sub_info = kzalloc(sizeof(struct subprocess_info), gfp_mask);
if (!sub_info)
goto out;
INIT_WORK(&sub_info->work, __call_usermodehelper);
sub_info->path = path;
sub_info->argv = argv;
sub_info->envp = envp;
out:
return sub_info;
}
void call_usermodehelper_setfns(struct subprocess_info *info,
int (*init)(struct subprocess_info *info, struct cred *new),
void (*cleanup)(struct subprocess_info *info),
void *data)
{
info->cleanup = cleanup;
info->init = init;
info->data = data;
}
int call_usermodehelper_exec(struct subprocess_info *sub_info,
enum umh_wait wait)
{
DECLARE_COMPLETION_ONSTACK(done);
int retval = 0;
helper_lock();
if (sub_info->path[0] == '\0')
goto out;
if (!khelper_wq || usermodehelper_disabled) {
retval = -EBUSY;
goto out;
}
sub_info->complete = &done;
sub_info->wait = wait;
queue_work(khelper_wq, &sub_info->work);
if (wait == UMH_NO_WAIT)
goto unlock;
wait_for_completion(&done);
retval = sub_info->retval;
out:
call_usermodehelper_freeinfo(sub_info);
unlock:
helper_unlock();
return retval;
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
