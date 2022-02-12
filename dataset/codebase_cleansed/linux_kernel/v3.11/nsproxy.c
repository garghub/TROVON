static inline struct nsproxy *create_nsproxy(void)
{
struct nsproxy *nsproxy;
nsproxy = kmem_cache_alloc(nsproxy_cachep, GFP_KERNEL);
if (nsproxy)
atomic_set(&nsproxy->count, 1);
return nsproxy;
}
static struct nsproxy *create_new_namespaces(unsigned long flags,
struct task_struct *tsk, struct user_namespace *user_ns,
struct fs_struct *new_fs)
{
struct nsproxy *new_nsp;
int err;
new_nsp = create_nsproxy();
if (!new_nsp)
return ERR_PTR(-ENOMEM);
new_nsp->mnt_ns = copy_mnt_ns(flags, tsk->nsproxy->mnt_ns, user_ns, new_fs);
if (IS_ERR(new_nsp->mnt_ns)) {
err = PTR_ERR(new_nsp->mnt_ns);
goto out_ns;
}
new_nsp->uts_ns = copy_utsname(flags, user_ns, tsk->nsproxy->uts_ns);
if (IS_ERR(new_nsp->uts_ns)) {
err = PTR_ERR(new_nsp->uts_ns);
goto out_uts;
}
new_nsp->ipc_ns = copy_ipcs(flags, user_ns, tsk->nsproxy->ipc_ns);
if (IS_ERR(new_nsp->ipc_ns)) {
err = PTR_ERR(new_nsp->ipc_ns);
goto out_ipc;
}
new_nsp->pid_ns_for_children =
copy_pid_ns(flags, user_ns, tsk->nsproxy->pid_ns_for_children);
if (IS_ERR(new_nsp->pid_ns_for_children)) {
err = PTR_ERR(new_nsp->pid_ns_for_children);
goto out_pid;
}
new_nsp->net_ns = copy_net_ns(flags, user_ns, tsk->nsproxy->net_ns);
if (IS_ERR(new_nsp->net_ns)) {
err = PTR_ERR(new_nsp->net_ns);
goto out_net;
}
return new_nsp;
out_net:
if (new_nsp->pid_ns_for_children)
put_pid_ns(new_nsp->pid_ns_for_children);
out_pid:
if (new_nsp->ipc_ns)
put_ipc_ns(new_nsp->ipc_ns);
out_ipc:
if (new_nsp->uts_ns)
put_uts_ns(new_nsp->uts_ns);
out_uts:
if (new_nsp->mnt_ns)
put_mnt_ns(new_nsp->mnt_ns);
out_ns:
kmem_cache_free(nsproxy_cachep, new_nsp);
return ERR_PTR(err);
}
int copy_namespaces(unsigned long flags, struct task_struct *tsk)
{
struct nsproxy *old_ns = tsk->nsproxy;
struct user_namespace *user_ns = task_cred_xxx(tsk, user_ns);
struct nsproxy *new_ns;
int err = 0;
if (!old_ns)
return 0;
get_nsproxy(old_ns);
if (!(flags & (CLONE_NEWNS | CLONE_NEWUTS | CLONE_NEWIPC |
CLONE_NEWPID | CLONE_NEWNET)))
return 0;
if (!ns_capable(user_ns, CAP_SYS_ADMIN)) {
err = -EPERM;
goto out;
}
if ((flags & CLONE_NEWIPC) && (flags & CLONE_SYSVSEM)) {
err = -EINVAL;
goto out;
}
new_ns = create_new_namespaces(flags, tsk, user_ns, tsk->fs);
if (IS_ERR(new_ns)) {
err = PTR_ERR(new_ns);
goto out;
}
tsk->nsproxy = new_ns;
out:
put_nsproxy(old_ns);
return err;
}
void free_nsproxy(struct nsproxy *ns)
{
if (ns->mnt_ns)
put_mnt_ns(ns->mnt_ns);
if (ns->uts_ns)
put_uts_ns(ns->uts_ns);
if (ns->ipc_ns)
put_ipc_ns(ns->ipc_ns);
if (ns->pid_ns_for_children)
put_pid_ns(ns->pid_ns_for_children);
put_net(ns->net_ns);
kmem_cache_free(nsproxy_cachep, ns);
}
int unshare_nsproxy_namespaces(unsigned long unshare_flags,
struct nsproxy **new_nsp, struct cred *new_cred, struct fs_struct *new_fs)
{
struct user_namespace *user_ns;
int err = 0;
if (!(unshare_flags & (CLONE_NEWNS | CLONE_NEWUTS | CLONE_NEWIPC |
CLONE_NEWNET | CLONE_NEWPID)))
return 0;
user_ns = new_cred ? new_cred->user_ns : current_user_ns();
if (!ns_capable(user_ns, CAP_SYS_ADMIN))
return -EPERM;
*new_nsp = create_new_namespaces(unshare_flags, current, user_ns,
new_fs ? new_fs : current->fs);
if (IS_ERR(*new_nsp)) {
err = PTR_ERR(*new_nsp);
goto out;
}
out:
return err;
}
void switch_task_namespaces(struct task_struct *p, struct nsproxy *new)
{
struct nsproxy *ns;
might_sleep();
ns = p->nsproxy;
rcu_assign_pointer(p->nsproxy, new);
if (ns && atomic_dec_and_test(&ns->count)) {
synchronize_rcu();
free_nsproxy(ns);
}
}
void exit_task_namespaces(struct task_struct *p)
{
switch_task_namespaces(p, NULL);
}
int __init nsproxy_cache_init(void)
{
nsproxy_cachep = KMEM_CACHE(nsproxy, SLAB_PANIC);
return 0;
}
