static const char *hname_tail(const char *hname)
{
char *split;
hname = strim((char *)hname);
for (split = strstr(hname, "//"); split; split = strstr(hname, "//"))
hname = split + 2;
return hname;
}
static bool policy_init(struct aa_policy *policy, const char *prefix,
const char *name)
{
if (prefix) {
policy->hname = kmalloc(strlen(prefix) + strlen(name) + 3,
GFP_KERNEL);
if (policy->hname)
sprintf(policy->hname, "%s//%s", prefix, name);
} else
policy->hname = kstrdup(name, GFP_KERNEL);
if (!policy->hname)
return 0;
policy->name = (char *)hname_tail(policy->hname);
INIT_LIST_HEAD(&policy->list);
INIT_LIST_HEAD(&policy->profiles);
return 1;
}
static void policy_destroy(struct aa_policy *policy)
{
if (on_list_rcu(&policy->profiles)) {
AA_ERROR("%s: internal error, "
"policy '%s' still contains profiles\n",
__func__, policy->name);
BUG();
}
if (on_list_rcu(&policy->list)) {
AA_ERROR("%s: internal error, policy '%s' still on list\n",
__func__, policy->name);
BUG();
}
kzfree(policy->hname);
}
static struct aa_policy *__policy_find(struct list_head *head, const char *name)
{
struct aa_policy *policy;
list_for_each_entry_rcu(policy, head, list) {
if (!strcmp(policy->name, name))
return policy;
}
return NULL;
}
static struct aa_policy *__policy_strn_find(struct list_head *head,
const char *str, int len)
{
struct aa_policy *policy;
list_for_each_entry_rcu(policy, head, list) {
if (aa_strneq(policy->name, str, len))
return policy;
}
return NULL;
}
bool aa_ns_visible(struct aa_namespace *curr, struct aa_namespace *view)
{
if (curr == view)
return true;
for ( ; view; view = view->parent) {
if (view->parent == curr)
return true;
}
return false;
}
const char *aa_ns_name(struct aa_namespace *curr, struct aa_namespace *view)
{
if (curr == view)
return "";
if (aa_ns_visible(curr, view)) {
return view->base.hname + strlen(curr->base.hname) + 2;
} else
return hidden_ns_name;
}
static struct aa_namespace *alloc_namespace(const char *prefix,
const char *name)
{
struct aa_namespace *ns;
ns = kzalloc(sizeof(*ns), GFP_KERNEL);
AA_DEBUG("%s(%p)\n", __func__, ns);
if (!ns)
return NULL;
if (!policy_init(&ns->base, prefix, name))
goto fail_ns;
INIT_LIST_HEAD(&ns->sub_ns);
mutex_init(&ns->lock);
ns->unconfined = aa_alloc_profile("unconfined");
if (!ns->unconfined)
goto fail_unconfined;
ns->unconfined->flags = PFLAG_IX_ON_NAME_ERROR |
PFLAG_IMMUTABLE | PFLAG_NS_COUNT;
ns->unconfined->mode = APPARMOR_UNCONFINED;
ns->unconfined->ns = ns;
atomic_set(&ns->uniq_null, 0);
return ns;
fail_unconfined:
kzfree(ns->base.hname);
fail_ns:
kzfree(ns);
return NULL;
}
static void free_namespace(struct aa_namespace *ns)
{
if (!ns)
return;
policy_destroy(&ns->base);
aa_put_namespace(ns->parent);
ns->unconfined->ns = NULL;
aa_free_profile(ns->unconfined);
kzfree(ns);
}
static struct aa_namespace *__aa_find_namespace(struct list_head *head,
const char *name)
{
return (struct aa_namespace *)__policy_find(head, name);
}
struct aa_namespace *aa_find_namespace(struct aa_namespace *root,
const char *name)
{
struct aa_namespace *ns = NULL;
rcu_read_lock();
ns = aa_get_namespace(__aa_find_namespace(&root->sub_ns, name));
rcu_read_unlock();
return ns;
}
static struct aa_namespace *aa_prepare_namespace(const char *name)
{
struct aa_namespace *ns, *root;
root = aa_current_profile()->ns;
mutex_lock(&root->lock);
if (!name) {
ns = aa_get_namespace(root);
goto out;
}
ns = aa_get_namespace(__aa_find_namespace(&root->sub_ns, name));
if (!ns) {
ns = alloc_namespace(root->base.hname, name);
if (!ns)
goto out;
if (__aa_fs_namespace_mkdir(ns, ns_subns_dir(root), name)) {
AA_ERROR("Failed to create interface for ns %s\n",
ns->base.name);
free_namespace(ns);
ns = NULL;
goto out;
}
ns->parent = aa_get_namespace(root);
list_add_rcu(&ns->base.list, &root->sub_ns);
aa_get_namespace(ns);
}
out:
mutex_unlock(&root->lock);
return ns;
}
static void __list_add_profile(struct list_head *list,
struct aa_profile *profile)
{
list_add_rcu(&profile->base.list, list);
aa_get_profile(profile);
}
static void __list_remove_profile(struct aa_profile *profile)
{
list_del_rcu(&profile->base.list);
aa_put_profile(profile);
}
static void __remove_profile(struct aa_profile *profile)
{
__profile_list_release(&profile->base.profiles);
__aa_update_replacedby(profile, profile->ns->unconfined);
__aa_fs_profile_rmdir(profile);
__list_remove_profile(profile);
}
static void __profile_list_release(struct list_head *head)
{
struct aa_profile *profile, *tmp;
list_for_each_entry_safe(profile, tmp, head, base.list)
__remove_profile(profile);
}
static void destroy_namespace(struct aa_namespace *ns)
{
if (!ns)
return;
mutex_lock(&ns->lock);
__profile_list_release(&ns->base.profiles);
__ns_list_release(&ns->sub_ns);
if (ns->parent)
__aa_update_replacedby(ns->unconfined, ns->parent->unconfined);
__aa_fs_namespace_rmdir(ns);
mutex_unlock(&ns->lock);
}
static void __remove_namespace(struct aa_namespace *ns)
{
list_del_rcu(&ns->base.list);
destroy_namespace(ns);
aa_put_namespace(ns);
}
static void __ns_list_release(struct list_head *head)
{
struct aa_namespace *ns, *tmp;
list_for_each_entry_safe(ns, tmp, head, base.list)
__remove_namespace(ns);
}
int __init aa_alloc_root_ns(void)
{
root_ns = alloc_namespace(NULL, "root");
if (!root_ns)
return -ENOMEM;
return 0;
}
void __init aa_free_root_ns(void)
{
struct aa_namespace *ns = root_ns;
root_ns = NULL;
destroy_namespace(ns);
aa_put_namespace(ns);
}
static void free_replacedby(struct aa_replacedby *r)
{
if (r) {
aa_put_profile(rcu_dereference_protected(r->profile, true));
kzfree(r);
}
}
void aa_free_replacedby_kref(struct kref *kref)
{
struct aa_replacedby *r = container_of(kref, struct aa_replacedby,
count);
free_replacedby(r);
}
void aa_free_profile(struct aa_profile *profile)
{
AA_DEBUG("%s(%p)\n", __func__, profile);
if (!profile)
return;
policy_destroy(&profile->base);
aa_put_profile(rcu_access_pointer(profile->parent));
aa_put_namespace(profile->ns);
kzfree(profile->rename);
aa_free_file_rules(&profile->file);
aa_free_cap_rules(&profile->caps);
aa_free_rlimit_rules(&profile->rlimits);
kzfree(profile->dirname);
aa_put_dfa(profile->xmatch);
aa_put_dfa(profile->policy.dfa);
aa_put_replacedby(profile->replacedby);
kzfree(profile->hash);
kzfree(profile);
}
static void aa_free_profile_rcu(struct rcu_head *head)
{
struct aa_profile *p = container_of(head, struct aa_profile, rcu);
if (p->flags & PFLAG_NS_COUNT)
free_namespace(p->ns);
else
aa_free_profile(p);
}
void aa_free_profile_kref(struct kref *kref)
{
struct aa_profile *p = container_of(kref, struct aa_profile, count);
call_rcu(&p->rcu, aa_free_profile_rcu);
}
struct aa_profile *aa_alloc_profile(const char *hname)
{
struct aa_profile *profile;
profile = kzalloc(sizeof(*profile), GFP_KERNEL);
if (!profile)
return NULL;
profile->replacedby = kzalloc(sizeof(struct aa_replacedby), GFP_KERNEL);
if (!profile->replacedby)
goto fail;
kref_init(&profile->replacedby->count);
if (!policy_init(&profile->base, NULL, hname))
goto fail;
kref_init(&profile->count);
return profile;
fail:
kzfree(profile->replacedby);
kzfree(profile);
return NULL;
}
struct aa_profile *aa_new_null_profile(struct aa_profile *parent, int hat)
{
struct aa_profile *profile = NULL;
char *name;
int uniq = atomic_inc_return(&parent->ns->uniq_null);
name = kmalloc(strlen(parent->base.hname) + 2 + 7 + 8, GFP_KERNEL);
if (!name)
goto fail;
sprintf(name, "%s//null-%x", parent->base.hname, uniq);
profile = aa_alloc_profile(name);
kfree(name);
if (!profile)
goto fail;
profile->mode = APPARMOR_COMPLAIN;
profile->flags = PFLAG_NULL;
if (hat)
profile->flags |= PFLAG_HAT;
rcu_assign_pointer(profile->parent, aa_get_profile(parent));
profile->ns = aa_get_namespace(parent->ns);
mutex_lock(&profile->ns->lock);
__list_add_profile(&parent->base.profiles, profile);
mutex_unlock(&profile->ns->lock);
return profile;
fail:
return NULL;
}
static struct aa_profile *__find_child(struct list_head *head, const char *name)
{
return (struct aa_profile *)__policy_find(head, name);
}
static struct aa_profile *__strn_find_child(struct list_head *head,
const char *name, int len)
{
return (struct aa_profile *)__policy_strn_find(head, name, len);
}
struct aa_profile *aa_find_child(struct aa_profile *parent, const char *name)
{
struct aa_profile *profile;
rcu_read_lock();
profile = aa_get_profile(__find_child(&parent->base.profiles, name));
rcu_read_unlock();
return profile;
}
static struct aa_policy *__lookup_parent(struct aa_namespace *ns,
const char *hname)
{
struct aa_policy *policy;
struct aa_profile *profile = NULL;
char *split;
policy = &ns->base;
for (split = strstr(hname, "//"); split;) {
profile = __strn_find_child(&policy->profiles, hname,
split - hname);
if (!profile)
return NULL;
policy = &profile->base;
hname = split + 2;
split = strstr(hname, "//");
}
if (!profile)
return &ns->base;
return &profile->base;
}
static struct aa_profile *__lookup_profile(struct aa_policy *base,
const char *hname)
{
struct aa_profile *profile = NULL;
char *split;
for (split = strstr(hname, "//"); split;) {
profile = __strn_find_child(&base->profiles, hname,
split - hname);
if (!profile)
return NULL;
base = &profile->base;
hname = split + 2;
split = strstr(hname, "//");
}
profile = __find_child(&base->profiles, hname);
return profile;
}
struct aa_profile *aa_lookup_profile(struct aa_namespace *ns, const char *hname)
{
struct aa_profile *profile;
rcu_read_lock();
do {
profile = __lookup_profile(&ns->base, hname);
} while (profile && !aa_get_profile_not0(profile));
rcu_read_unlock();
if (!profile && strcmp(hname, "unconfined") == 0)
profile = aa_get_newest_profile(ns->unconfined);
return profile;
}
static int replacement_allowed(struct aa_profile *profile, int noreplace,
const char **info)
{
if (profile) {
if (profile->flags & PFLAG_IMMUTABLE) {
*info = "cannot replace immutible profile";
return -EPERM;
} else if (noreplace) {
*info = "profile already exists";
return -EEXIST;
}
}
return 0;
}
static int audit_policy(int op, gfp_t gfp, const char *name, const char *info,
int error)
{
struct common_audit_data sa;
struct apparmor_audit_data aad = {0,};
sa.type = LSM_AUDIT_DATA_NONE;
sa.aad = &aad;
aad.op = op;
aad.name = name;
aad.info = info;
aad.error = error;
return aa_audit(AUDIT_APPARMOR_STATUS, __aa_current_profile(), gfp,
&sa, NULL);
}
bool aa_may_manage_policy(int op)
{
if (aa_g_lock_policy) {
audit_policy(op, GFP_KERNEL, NULL, "policy_locked", -EACCES);
return 0;
}
if (!capable(CAP_MAC_ADMIN)) {
audit_policy(op, GFP_KERNEL, NULL, "not policy admin", -EACCES);
return 0;
}
return 1;
}
static struct aa_profile *__list_lookup_parent(struct list_head *lh,
struct aa_profile *profile)
{
const char *base = hname_tail(profile->base.hname);
long len = base - profile->base.hname;
struct aa_load_ent *ent;
if (len <= 2)
return NULL;
len -= 2;
list_for_each_entry(ent, lh, list) {
if (ent->new == profile)
continue;
if (strncmp(ent->new->base.hname, profile->base.hname, len) ==
0 && ent->new->base.hname[len] == 0)
return ent->new;
}
return NULL;
}
static void __replace_profile(struct aa_profile *old, struct aa_profile *new,
bool share_replacedby)
{
struct aa_profile *child, *tmp;
if (!list_empty(&old->base.profiles)) {
LIST_HEAD(lh);
list_splice_init_rcu(&old->base.profiles, &lh, synchronize_rcu);
list_for_each_entry_safe(child, tmp, &lh, base.list) {
struct aa_profile *p;
list_del_init(&child->base.list);
p = __find_child(&new->base.profiles, child->base.name);
if (p) {
__replace_profile(child, p, share_replacedby);
continue;
}
p = aa_deref_parent(child);
rcu_assign_pointer(child->parent, aa_get_profile(new));
list_add_rcu(&child->base.list, &new->base.profiles);
aa_put_profile(p);
}
}
if (!rcu_access_pointer(new->parent)) {
struct aa_profile *parent = aa_deref_parent(old);
rcu_assign_pointer(new->parent, aa_get_profile(parent));
}
__aa_update_replacedby(old, new);
if (share_replacedby) {
aa_put_replacedby(new->replacedby);
new->replacedby = aa_get_replacedby(old->replacedby);
} else if (!rcu_access_pointer(new->replacedby->profile))
rcu_assign_pointer(new->replacedby->profile,
aa_get_profile(new));
__aa_fs_profile_migrate_dents(old, new);
if (list_empty(&new->base.list)) {
list_replace_rcu(&old->base.list, &new->base.list);
aa_get_profile(new);
aa_put_profile(old);
} else
__list_remove_profile(old);
}
static int __lookup_replace(struct aa_namespace *ns, const char *hname,
bool noreplace, struct aa_profile **p,
const char **info)
{
*p = aa_get_profile(__lookup_profile(&ns->base, hname));
if (*p) {
int error = replacement_allowed(*p, noreplace, info);
if (error) {
*info = "profile can not be replaced";
return error;
}
}
return 0;
}
ssize_t aa_replace_profiles(void *udata, size_t size, bool noreplace)
{
const char *ns_name, *name = NULL, *info = NULL;
struct aa_namespace *ns = NULL;
struct aa_load_ent *ent, *tmp;
int op = OP_PROF_REPL;
ssize_t error;
LIST_HEAD(lh);
error = aa_unpack(udata, size, &lh, &ns_name);
if (error)
goto out;
ns = aa_prepare_namespace(ns_name);
if (!ns) {
info = "failed to prepare namespace";
error = -ENOMEM;
name = ns_name;
goto fail;
}
mutex_lock(&ns->lock);
list_for_each_entry(ent, &lh, list) {
struct aa_policy *policy;
name = ent->new->base.hname;
error = __lookup_replace(ns, ent->new->base.hname, noreplace,
&ent->old, &info);
if (error)
goto fail_lock;
if (ent->new->rename) {
error = __lookup_replace(ns, ent->new->rename,
noreplace, &ent->rename,
&info);
if (error)
goto fail_lock;
}
ent->new->ns = aa_get_namespace(ns);
if (ent->old || ent->rename)
continue;
policy = __lookup_parent(ns, ent->new->base.hname);
if (!policy) {
struct aa_profile *p;
p = __list_lookup_parent(&lh, ent->new);
if (!p) {
error = -ENOENT;
info = "parent does not exist";
name = ent->new->base.hname;
goto fail_lock;
}
rcu_assign_pointer(ent->new->parent, aa_get_profile(p));
} else if (policy != &ns->base) {
struct aa_profile *p = (struct aa_profile *) policy;
rcu_assign_pointer(ent->new->parent, aa_get_profile(p));
}
}
list_for_each_entry(ent, &lh, list) {
if (ent->old) {
} else {
struct dentry *parent;
if (rcu_access_pointer(ent->new->parent)) {
struct aa_profile *p;
p = aa_deref_parent(ent->new);
parent = prof_child_dir(p);
} else
parent = ns_subprofs_dir(ent->new->ns);
error = __aa_fs_profile_mkdir(ent->new, parent);
}
if (error) {
info = "failed to create ";
goto fail_lock;
}
}
list_for_each_entry_safe(ent, tmp, &lh, list) {
list_del_init(&ent->list);
op = (!ent->old && !ent->rename) ? OP_PROF_LOAD : OP_PROF_REPL;
audit_policy(op, GFP_ATOMIC, ent->new->base.name, NULL, error);
if (ent->old) {
__replace_profile(ent->old, ent->new, 1);
if (ent->rename) {
struct aa_replacedby *r = ent->new->replacedby;
rcu_assign_pointer(r->profile,
aa_get_profile(ent->new));
__replace_profile(ent->rename, ent->new, 0);
}
} else if (ent->rename) {
rcu_assign_pointer(ent->new->replacedby->profile,
aa_get_profile(ent->new));
__replace_profile(ent->rename, ent->new, 0);
} else if (ent->new->parent) {
struct aa_profile *parent, *newest;
parent = aa_deref_parent(ent->new);
newest = aa_get_newest_profile(parent);
if (newest != parent) {
aa_get_profile(newest);
aa_put_profile(parent);
rcu_assign_pointer(ent->new->parent, newest);
} else
aa_put_profile(newest);
rcu_assign_pointer(ent->new->replacedby->profile,
aa_get_profile(ent->new));
__list_add_profile(&parent->base.profiles, ent->new);
} else {
rcu_assign_pointer(ent->new->replacedby->profile,
aa_get_profile(ent->new));
__list_add_profile(&ns->base.profiles, ent->new);
}
aa_load_ent_free(ent);
}
mutex_unlock(&ns->lock);
out:
aa_put_namespace(ns);
if (error)
return error;
return size;
fail_lock:
mutex_unlock(&ns->lock);
fail:
error = audit_policy(op, GFP_KERNEL, name, info, error);
list_for_each_entry_safe(ent, tmp, &lh, list) {
list_del_init(&ent->list);
aa_load_ent_free(ent);
}
goto out;
}
ssize_t aa_remove_profiles(char *fqname, size_t size)
{
struct aa_namespace *root, *ns = NULL;
struct aa_profile *profile = NULL;
const char *name = fqname, *info = NULL;
ssize_t error = 0;
if (*fqname == 0) {
info = "no profile specified";
error = -ENOENT;
goto fail;
}
root = aa_current_profile()->ns;
if (fqname[0] == ':') {
char *ns_name;
name = aa_split_fqname(fqname, &ns_name);
ns = aa_find_namespace(root, ns_name);
if (!ns) {
info = "namespace does not exist";
error = -ENOENT;
goto fail;
}
} else
ns = aa_get_namespace(root);
if (!name) {
mutex_lock(&ns->parent->lock);
__remove_namespace(ns);
mutex_unlock(&ns->parent->lock);
} else {
mutex_lock(&ns->lock);
profile = aa_get_profile(__lookup_profile(&ns->base, name));
if (!profile) {
error = -ENOENT;
info = "profile does not exist";
goto fail_ns_lock;
}
name = profile->base.hname;
__remove_profile(profile);
mutex_unlock(&ns->lock);
}
(void) audit_policy(OP_PROF_RM, GFP_KERNEL, name, info, error);
aa_put_namespace(ns);
aa_put_profile(profile);
return size;
fail_ns_lock:
mutex_unlock(&ns->lock);
aa_put_namespace(ns);
fail:
(void) audit_policy(OP_PROF_RM, GFP_KERNEL, name, info, error);
return error;
}
