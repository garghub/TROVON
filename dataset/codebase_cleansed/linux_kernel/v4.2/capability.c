static int __init file_caps_disable(char *str)
{
file_caps_enabled = 0;
return 1;
}
static void warn_legacy_capability_use(void)
{
char name[sizeof(current->comm)];
pr_info_once("warning: `%s' uses 32-bit capabilities (legacy support in use)\n",
get_task_comm(name, current));
}
static void warn_deprecated_v2(void)
{
char name[sizeof(current->comm)];
pr_info_once("warning: `%s' uses deprecated v2 capabilities in a way that may be insecure\n",
get_task_comm(name, current));
}
static int cap_validate_magic(cap_user_header_t header, unsigned *tocopy)
{
__u32 version;
if (get_user(version, &header->version))
return -EFAULT;
switch (version) {
case _LINUX_CAPABILITY_VERSION_1:
warn_legacy_capability_use();
*tocopy = _LINUX_CAPABILITY_U32S_1;
break;
case _LINUX_CAPABILITY_VERSION_2:
warn_deprecated_v2();
case _LINUX_CAPABILITY_VERSION_3:
*tocopy = _LINUX_CAPABILITY_U32S_3;
break;
default:
if (put_user((u32)_KERNEL_CAPABILITY_VERSION, &header->version))
return -EFAULT;
return -EINVAL;
}
return 0;
}
static inline int cap_get_target_pid(pid_t pid, kernel_cap_t *pEp,
kernel_cap_t *pIp, kernel_cap_t *pPp)
{
int ret;
if (pid && (pid != task_pid_vnr(current))) {
struct task_struct *target;
rcu_read_lock();
target = find_task_by_vpid(pid);
if (!target)
ret = -ESRCH;
else
ret = security_capget(target, pEp, pIp, pPp);
rcu_read_unlock();
} else
ret = security_capget(current, pEp, pIp, pPp);
return ret;
}
bool has_ns_capability(struct task_struct *t,
struct user_namespace *ns, int cap)
{
int ret;
rcu_read_lock();
ret = security_capable(__task_cred(t), ns, cap);
rcu_read_unlock();
return (ret == 0);
}
bool has_capability(struct task_struct *t, int cap)
{
return has_ns_capability(t, &init_user_ns, cap);
}
bool has_ns_capability_noaudit(struct task_struct *t,
struct user_namespace *ns, int cap)
{
int ret;
rcu_read_lock();
ret = security_capable_noaudit(__task_cred(t), ns, cap);
rcu_read_unlock();
return (ret == 0);
}
bool has_capability_noaudit(struct task_struct *t, int cap)
{
return has_ns_capability_noaudit(t, &init_user_ns, cap);
}
bool ns_capable(struct user_namespace *ns, int cap)
{
if (unlikely(!cap_valid(cap))) {
pr_crit("capable() called with invalid cap=%u\n", cap);
BUG();
}
if (security_capable(current_cred(), ns, cap) == 0) {
current->flags |= PF_SUPERPRIV;
return true;
}
return false;
}
bool capable(int cap)
{
return ns_capable(&init_user_ns, cap);
}
bool file_ns_capable(const struct file *file, struct user_namespace *ns,
int cap)
{
if (WARN_ON_ONCE(!cap_valid(cap)))
return false;
if (security_capable(file->f_cred, ns, cap) == 0)
return true;
return false;
}
bool capable_wrt_inode_uidgid(const struct inode *inode, int cap)
{
struct user_namespace *ns = current_user_ns();
return ns_capable(ns, cap) && kuid_has_mapping(ns, inode->i_uid) &&
kgid_has_mapping(ns, inode->i_gid);
}
