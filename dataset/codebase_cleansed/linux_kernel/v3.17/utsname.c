static struct uts_namespace *create_uts_ns(void)
{
struct uts_namespace *uts_ns;
uts_ns = kmalloc(sizeof(struct uts_namespace), GFP_KERNEL);
if (uts_ns)
kref_init(&uts_ns->kref);
return uts_ns;
}
static struct uts_namespace *clone_uts_ns(struct user_namespace *user_ns,
struct uts_namespace *old_ns)
{
struct uts_namespace *ns;
int err;
ns = create_uts_ns();
if (!ns)
return ERR_PTR(-ENOMEM);
err = proc_alloc_inum(&ns->proc_inum);
if (err) {
kfree(ns);
return ERR_PTR(err);
}
down_read(&uts_sem);
memcpy(&ns->name, &old_ns->name, sizeof(ns->name));
ns->user_ns = get_user_ns(user_ns);
up_read(&uts_sem);
return ns;
}
struct uts_namespace *copy_utsname(unsigned long flags,
struct user_namespace *user_ns, struct uts_namespace *old_ns)
{
struct uts_namespace *new_ns;
BUG_ON(!old_ns);
get_uts_ns(old_ns);
if (!(flags & CLONE_NEWUTS))
return old_ns;
new_ns = clone_uts_ns(user_ns, old_ns);
put_uts_ns(old_ns);
return new_ns;
}
void free_uts_ns(struct kref *kref)
{
struct uts_namespace *ns;
ns = container_of(kref, struct uts_namespace, kref);
put_user_ns(ns->user_ns);
proc_free_inum(ns->proc_inum);
kfree(ns);
}
static void *utsns_get(struct task_struct *task)
{
struct uts_namespace *ns = NULL;
struct nsproxy *nsproxy;
task_lock(task);
nsproxy = task->nsproxy;
if (nsproxy) {
ns = nsproxy->uts_ns;
get_uts_ns(ns);
}
task_unlock(task);
return ns;
}
static void utsns_put(void *ns)
{
put_uts_ns(ns);
}
static int utsns_install(struct nsproxy *nsproxy, void *new)
{
struct uts_namespace *ns = new;
if (!ns_capable(ns->user_ns, CAP_SYS_ADMIN) ||
!ns_capable(current_user_ns(), CAP_SYS_ADMIN))
return -EPERM;
get_uts_ns(ns);
put_uts_ns(nsproxy->uts_ns);
nsproxy->uts_ns = ns;
return 0;
}
static unsigned int utsns_inum(void *vp)
{
struct uts_namespace *ns = vp;
return ns->proc_inum;
}
