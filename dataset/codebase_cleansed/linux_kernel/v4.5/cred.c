static inline void set_cred_subscribers(struct cred *cred, int n)
{
#ifdef CONFIG_DEBUG_CREDENTIALS
atomic_set(&cred->subscribers, n);
#endif
}
static inline int read_cred_subscribers(const struct cred *cred)
{
#ifdef CONFIG_DEBUG_CREDENTIALS
return atomic_read(&cred->subscribers);
#else
return 0;
#endif
}
static inline void alter_cred_subscribers(const struct cred *_cred, int n)
{
#ifdef CONFIG_DEBUG_CREDENTIALS
struct cred *cred = (struct cred *) _cred;
atomic_add(n, &cred->subscribers);
#endif
}
static void put_cred_rcu(struct rcu_head *rcu)
{
struct cred *cred = container_of(rcu, struct cred, rcu);
kdebug("put_cred_rcu(%p)", cred);
#ifdef CONFIG_DEBUG_CREDENTIALS
if (cred->magic != CRED_MAGIC_DEAD ||
atomic_read(&cred->usage) != 0 ||
read_cred_subscribers(cred) != 0)
panic("CRED: put_cred_rcu() sees %p with"
" mag %x, put %p, usage %d, subscr %d\n",
cred, cred->magic, cred->put_addr,
atomic_read(&cred->usage),
read_cred_subscribers(cred));
#else
if (atomic_read(&cred->usage) != 0)
panic("CRED: put_cred_rcu() sees %p with usage %d\n",
cred, atomic_read(&cred->usage));
#endif
security_cred_free(cred);
key_put(cred->session_keyring);
key_put(cred->process_keyring);
key_put(cred->thread_keyring);
key_put(cred->request_key_auth);
if (cred->group_info)
put_group_info(cred->group_info);
free_uid(cred->user);
put_user_ns(cred->user_ns);
kmem_cache_free(cred_jar, cred);
}
void __put_cred(struct cred *cred)
{
kdebug("__put_cred(%p{%d,%d})", cred,
atomic_read(&cred->usage),
read_cred_subscribers(cred));
BUG_ON(atomic_read(&cred->usage) != 0);
#ifdef CONFIG_DEBUG_CREDENTIALS
BUG_ON(read_cred_subscribers(cred) != 0);
cred->magic = CRED_MAGIC_DEAD;
cred->put_addr = __builtin_return_address(0);
#endif
BUG_ON(cred == current->cred);
BUG_ON(cred == current->real_cred);
call_rcu(&cred->rcu, put_cred_rcu);
}
void exit_creds(struct task_struct *tsk)
{
struct cred *cred;
kdebug("exit_creds(%u,%p,%p,{%d,%d})", tsk->pid, tsk->real_cred, tsk->cred,
atomic_read(&tsk->cred->usage),
read_cred_subscribers(tsk->cred));
cred = (struct cred *) tsk->real_cred;
tsk->real_cred = NULL;
validate_creds(cred);
alter_cred_subscribers(cred, -1);
put_cred(cred);
cred = (struct cred *) tsk->cred;
tsk->cred = NULL;
validate_creds(cred);
alter_cred_subscribers(cred, -1);
put_cred(cred);
}
const struct cred *get_task_cred(struct task_struct *task)
{
const struct cred *cred;
rcu_read_lock();
do {
cred = __task_cred((task));
BUG_ON(!cred);
} while (!atomic_inc_not_zero(&((struct cred *)cred)->usage));
rcu_read_unlock();
return cred;
}
struct cred *cred_alloc_blank(void)
{
struct cred *new;
new = kmem_cache_zalloc(cred_jar, GFP_KERNEL);
if (!new)
return NULL;
atomic_set(&new->usage, 1);
#ifdef CONFIG_DEBUG_CREDENTIALS
new->magic = CRED_MAGIC;
#endif
if (security_cred_alloc_blank(new, GFP_KERNEL) < 0)
goto error;
return new;
error:
abort_creds(new);
return NULL;
}
struct cred *prepare_creds(void)
{
struct task_struct *task = current;
const struct cred *old;
struct cred *new;
validate_process_creds();
new = kmem_cache_alloc(cred_jar, GFP_KERNEL);
if (!new)
return NULL;
kdebug("prepare_creds() alloc %p", new);
old = task->cred;
memcpy(new, old, sizeof(struct cred));
atomic_set(&new->usage, 1);
set_cred_subscribers(new, 0);
get_group_info(new->group_info);
get_uid(new->user);
get_user_ns(new->user_ns);
#ifdef CONFIG_KEYS
key_get(new->session_keyring);
key_get(new->process_keyring);
key_get(new->thread_keyring);
key_get(new->request_key_auth);
#endif
#ifdef CONFIG_SECURITY
new->security = NULL;
#endif
if (security_prepare_creds(new, old, GFP_KERNEL) < 0)
goto error;
validate_creds(new);
return new;
error:
abort_creds(new);
return NULL;
}
struct cred *prepare_exec_creds(void)
{
struct cred *new;
new = prepare_creds();
if (!new)
return new;
#ifdef CONFIG_KEYS
key_put(new->thread_keyring);
new->thread_keyring = NULL;
key_put(new->process_keyring);
new->process_keyring = NULL;
#endif
return new;
}
int copy_creds(struct task_struct *p, unsigned long clone_flags)
{
struct cred *new;
int ret;
if (
#ifdef CONFIG_KEYS
!p->cred->thread_keyring &&
#endif
clone_flags & CLONE_THREAD
) {
p->real_cred = get_cred(p->cred);
get_cred(p->cred);
alter_cred_subscribers(p->cred, 2);
kdebug("share_creds(%p{%d,%d})",
p->cred, atomic_read(&p->cred->usage),
read_cred_subscribers(p->cred));
atomic_inc(&p->cred->user->processes);
return 0;
}
new = prepare_creds();
if (!new)
return -ENOMEM;
if (clone_flags & CLONE_NEWUSER) {
ret = create_user_ns(new);
if (ret < 0)
goto error_put;
}
#ifdef CONFIG_KEYS
if (new->thread_keyring) {
key_put(new->thread_keyring);
new->thread_keyring = NULL;
if (clone_flags & CLONE_THREAD)
install_thread_keyring_to_cred(new);
}
if (!(clone_flags & CLONE_THREAD)) {
key_put(new->process_keyring);
new->process_keyring = NULL;
}
#endif
atomic_inc(&new->user->processes);
p->cred = p->real_cred = get_cred(new);
alter_cred_subscribers(new, 2);
validate_creds(new);
return 0;
error_put:
put_cred(new);
return ret;
}
static bool cred_cap_issubset(const struct cred *set, const struct cred *subset)
{
const struct user_namespace *set_ns = set->user_ns;
const struct user_namespace *subset_ns = subset->user_ns;
if (set_ns == subset_ns)
return cap_issubset(subset->cap_permitted, set->cap_permitted);
for (;subset_ns != &init_user_ns; subset_ns = subset_ns->parent) {
if ((set_ns == subset_ns->parent) &&
uid_eq(subset_ns->owner, set->euid))
return true;
}
return false;
}
int commit_creds(struct cred *new)
{
struct task_struct *task = current;
const struct cred *old = task->real_cred;
kdebug("commit_creds(%p{%d,%d})", new,
atomic_read(&new->usage),
read_cred_subscribers(new));
BUG_ON(task->cred != old);
#ifdef CONFIG_DEBUG_CREDENTIALS
BUG_ON(read_cred_subscribers(old) < 2);
validate_creds(old);
validate_creds(new);
#endif
BUG_ON(atomic_read(&new->usage) < 1);
get_cred(new);
if (!uid_eq(old->euid, new->euid) ||
!gid_eq(old->egid, new->egid) ||
!uid_eq(old->fsuid, new->fsuid) ||
!gid_eq(old->fsgid, new->fsgid) ||
!cred_cap_issubset(old, new)) {
if (task->mm)
set_dumpable(task->mm, suid_dumpable);
task->pdeath_signal = 0;
smp_wmb();
}
if (!uid_eq(new->fsuid, old->fsuid))
key_fsuid_changed(task);
if (!gid_eq(new->fsgid, old->fsgid))
key_fsgid_changed(task);
alter_cred_subscribers(new, 2);
if (new->user != old->user)
atomic_inc(&new->user->processes);
rcu_assign_pointer(task->real_cred, new);
rcu_assign_pointer(task->cred, new);
if (new->user != old->user)
atomic_dec(&old->user->processes);
alter_cred_subscribers(old, -2);
if (!uid_eq(new->uid, old->uid) ||
!uid_eq(new->euid, old->euid) ||
!uid_eq(new->suid, old->suid) ||
!uid_eq(new->fsuid, old->fsuid))
proc_id_connector(task, PROC_EVENT_UID);
if (!gid_eq(new->gid, old->gid) ||
!gid_eq(new->egid, old->egid) ||
!gid_eq(new->sgid, old->sgid) ||
!gid_eq(new->fsgid, old->fsgid))
proc_id_connector(task, PROC_EVENT_GID);
put_cred(old);
put_cred(old);
return 0;
}
void abort_creds(struct cred *new)
{
kdebug("abort_creds(%p{%d,%d})", new,
atomic_read(&new->usage),
read_cred_subscribers(new));
#ifdef CONFIG_DEBUG_CREDENTIALS
BUG_ON(read_cred_subscribers(new) != 0);
#endif
BUG_ON(atomic_read(&new->usage) < 1);
put_cred(new);
}
const struct cred *override_creds(const struct cred *new)
{
const struct cred *old = current->cred;
kdebug("override_creds(%p{%d,%d})", new,
atomic_read(&new->usage),
read_cred_subscribers(new));
validate_creds(old);
validate_creds(new);
get_cred(new);
alter_cred_subscribers(new, 1);
rcu_assign_pointer(current->cred, new);
alter_cred_subscribers(old, -1);
kdebug("override_creds() = %p{%d,%d}", old,
atomic_read(&old->usage),
read_cred_subscribers(old));
return old;
}
void revert_creds(const struct cred *old)
{
const struct cred *override = current->cred;
kdebug("revert_creds(%p{%d,%d})", old,
atomic_read(&old->usage),
read_cred_subscribers(old));
validate_creds(old);
validate_creds(override);
alter_cred_subscribers(old, 1);
rcu_assign_pointer(current->cred, old);
alter_cred_subscribers(override, -1);
put_cred(override);
}
void __init cred_init(void)
{
cred_jar = kmem_cache_create("cred_jar", sizeof(struct cred), 0,
SLAB_HWCACHE_ALIGN|SLAB_PANIC|SLAB_ACCOUNT, NULL);
}
struct cred *prepare_kernel_cred(struct task_struct *daemon)
{
const struct cred *old;
struct cred *new;
new = kmem_cache_alloc(cred_jar, GFP_KERNEL);
if (!new)
return NULL;
kdebug("prepare_kernel_cred() alloc %p", new);
if (daemon)
old = get_task_cred(daemon);
else
old = get_cred(&init_cred);
validate_creds(old);
*new = *old;
atomic_set(&new->usage, 1);
set_cred_subscribers(new, 0);
get_uid(new->user);
get_user_ns(new->user_ns);
get_group_info(new->group_info);
#ifdef CONFIG_KEYS
new->session_keyring = NULL;
new->process_keyring = NULL;
new->thread_keyring = NULL;
new->request_key_auth = NULL;
new->jit_keyring = KEY_REQKEY_DEFL_THREAD_KEYRING;
#endif
#ifdef CONFIG_SECURITY
new->security = NULL;
#endif
if (security_prepare_creds(new, old, GFP_KERNEL) < 0)
goto error;
put_cred(old);
validate_creds(new);
return new;
error:
put_cred(new);
put_cred(old);
return NULL;
}
int set_security_override(struct cred *new, u32 secid)
{
return security_kernel_act_as(new, secid);
}
int set_security_override_from_ctx(struct cred *new, const char *secctx)
{
u32 secid;
int ret;
ret = security_secctx_to_secid(secctx, strlen(secctx), &secid);
if (ret < 0)
return ret;
return set_security_override(new, secid);
}
int set_create_files_as(struct cred *new, struct inode *inode)
{
new->fsuid = inode->i_uid;
new->fsgid = inode->i_gid;
return security_kernel_create_files_as(new, inode);
}
bool creds_are_invalid(const struct cred *cred)
{
if (cred->magic != CRED_MAGIC)
return true;
#ifdef CONFIG_SECURITY_SELINUX
if (selinux_is_enabled() && cred->security) {
if ((unsigned long) cred->security < PAGE_SIZE)
return true;
if ((*(u32 *)cred->security & 0xffffff00) ==
(POISON_FREE << 24 | POISON_FREE << 16 | POISON_FREE << 8))
return true;
}
#endif
return false;
}
static void dump_invalid_creds(const struct cred *cred, const char *label,
const struct task_struct *tsk)
{
printk(KERN_ERR "CRED: %s credentials: %p %s%s%s\n",
label, cred,
cred == &init_cred ? "[init]" : "",
cred == tsk->real_cred ? "[real]" : "",
cred == tsk->cred ? "[eff]" : "");
printk(KERN_ERR "CRED: ->magic=%x, put_addr=%p\n",
cred->magic, cred->put_addr);
printk(KERN_ERR "CRED: ->usage=%d, subscr=%d\n",
atomic_read(&cred->usage),
read_cred_subscribers(cred));
printk(KERN_ERR "CRED: ->*uid = { %d,%d,%d,%d }\n",
from_kuid_munged(&init_user_ns, cred->uid),
from_kuid_munged(&init_user_ns, cred->euid),
from_kuid_munged(&init_user_ns, cred->suid),
from_kuid_munged(&init_user_ns, cred->fsuid));
printk(KERN_ERR "CRED: ->*gid = { %d,%d,%d,%d }\n",
from_kgid_munged(&init_user_ns, cred->gid),
from_kgid_munged(&init_user_ns, cred->egid),
from_kgid_munged(&init_user_ns, cred->sgid),
from_kgid_munged(&init_user_ns, cred->fsgid));
#ifdef CONFIG_SECURITY
printk(KERN_ERR "CRED: ->security is %p\n", cred->security);
if ((unsigned long) cred->security >= PAGE_SIZE &&
(((unsigned long) cred->security & 0xffffff00) !=
(POISON_FREE << 24 | POISON_FREE << 16 | POISON_FREE << 8)))
printk(KERN_ERR "CRED: ->security {%x, %x}\n",
((u32*)cred->security)[0],
((u32*)cred->security)[1]);
#endif
}
void __invalid_creds(const struct cred *cred, const char *file, unsigned line)
{
printk(KERN_ERR "CRED: Invalid credentials\n");
printk(KERN_ERR "CRED: At %s:%u\n", file, line);
dump_invalid_creds(cred, "Specified", current);
BUG();
}
void __validate_process_creds(struct task_struct *tsk,
const char *file, unsigned line)
{
if (tsk->cred == tsk->real_cred) {
if (unlikely(read_cred_subscribers(tsk->cred) < 2 ||
creds_are_invalid(tsk->cred)))
goto invalid_creds;
} else {
if (unlikely(read_cred_subscribers(tsk->real_cred) < 1 ||
read_cred_subscribers(tsk->cred) < 1 ||
creds_are_invalid(tsk->real_cred) ||
creds_are_invalid(tsk->cred)))
goto invalid_creds;
}
return;
invalid_creds:
printk(KERN_ERR "CRED: Invalid process credentials\n");
printk(KERN_ERR "CRED: At %s:%u\n", file, line);
dump_invalid_creds(tsk->real_cred, "Real", tsk);
if (tsk->cred != tsk->real_cred)
dump_invalid_creds(tsk->cred, "Effective", tsk);
else
printk(KERN_ERR "CRED: Effective creds == Real creds\n");
BUG();
}
void validate_creds_for_do_exit(struct task_struct *tsk)
{
kdebug("validate_creds_for_do_exit(%p,%p{%d,%d})",
tsk->real_cred, tsk->cred,
atomic_read(&tsk->cred->usage),
read_cred_subscribers(tsk->cred));
__validate_process_creds(tsk, __FILE__, __LINE__);
}
