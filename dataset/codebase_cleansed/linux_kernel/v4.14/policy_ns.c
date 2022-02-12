bool aa_ns_visible(struct aa_ns *curr, struct aa_ns *view, bool subns)
{
if (curr == view)
return true;
if (!subns)
return false;
for ( ; view; view = view->parent) {
if (view->parent == curr)
return true;
}
return false;
}
const char *aa_ns_name(struct aa_ns *curr, struct aa_ns *view, bool subns)
{
if (curr == view)
return "";
if (aa_ns_visible(curr, view, subns)) {
return view->base.hname + strlen(curr->base.hname) + 2;
}
return aa_hidden_ns_name;
}
static struct aa_ns *alloc_ns(const char *prefix, const char *name)
{
struct aa_ns *ns;
ns = kzalloc(sizeof(*ns), GFP_KERNEL);
AA_DEBUG("%s(%p)\n", __func__, ns);
if (!ns)
return NULL;
if (!aa_policy_init(&ns->base, prefix, name, GFP_KERNEL))
goto fail_ns;
INIT_LIST_HEAD(&ns->sub_ns);
INIT_LIST_HEAD(&ns->rawdata_list);
mutex_init(&ns->lock);
init_waitqueue_head(&ns->wait);
ns->unconfined = aa_alloc_profile("unconfined", NULL, GFP_KERNEL);
if (!ns->unconfined)
goto fail_unconfined;
ns->unconfined->label.flags |= FLAG_IX_ON_NAME_ERROR |
FLAG_IMMUTIBLE | FLAG_NS_COUNT | FLAG_UNCONFINED;
ns->unconfined->mode = APPARMOR_UNCONFINED;
ns->unconfined->file.dfa = aa_get_dfa(nulldfa);
ns->unconfined->policy.dfa = aa_get_dfa(nulldfa);
ns->unconfined->ns = ns;
atomic_set(&ns->uniq_null, 0);
aa_labelset_init(&ns->labels);
return ns;
fail_unconfined:
kzfree(ns->base.hname);
fail_ns:
kzfree(ns);
return NULL;
}
void aa_free_ns(struct aa_ns *ns)
{
if (!ns)
return;
aa_policy_destroy(&ns->base);
aa_labelset_destroy(&ns->labels);
aa_put_ns(ns->parent);
ns->unconfined->ns = NULL;
aa_free_profile(ns->unconfined);
kzfree(ns);
}
struct aa_ns *aa_findn_ns(struct aa_ns *root, const char *name, size_t n)
{
struct aa_ns *ns = NULL;
rcu_read_lock();
ns = aa_get_ns(__aa_findn_ns(&root->sub_ns, name, n));
rcu_read_unlock();
return ns;
}
struct aa_ns *aa_find_ns(struct aa_ns *root, const char *name)
{
return aa_findn_ns(root, name, strlen(name));
}
struct aa_ns *__aa_lookupn_ns(struct aa_ns *view, const char *hname, size_t n)
{
struct aa_ns *ns = view;
const char *split;
for (split = strnstr(hname, "//", n); split;
split = strnstr(hname, "//", n)) {
ns = __aa_findn_ns(&ns->sub_ns, hname, split - hname);
if (!ns)
return NULL;
n -= split + 2 - hname;
hname = split + 2;
}
if (n)
return __aa_findn_ns(&ns->sub_ns, hname, n);
return NULL;
}
struct aa_ns *aa_lookupn_ns(struct aa_ns *view, const char *name, size_t n)
{
struct aa_ns *ns = NULL;
rcu_read_lock();
ns = aa_get_ns(__aa_lookupn_ns(view, name, n));
rcu_read_unlock();
return ns;
}
static struct aa_ns *__aa_create_ns(struct aa_ns *parent, const char *name,
struct dentry *dir)
{
struct aa_ns *ns;
int error;
AA_BUG(!parent);
AA_BUG(!name);
AA_BUG(!mutex_is_locked(&parent->lock));
ns = alloc_ns(parent->base.hname, name);
if (!ns)
return NULL;
mutex_lock(&ns->lock);
error = __aafs_ns_mkdir(ns, ns_subns_dir(parent), name, dir);
if (error) {
AA_ERROR("Failed to create interface for ns %s\n",
ns->base.name);
mutex_unlock(&ns->lock);
aa_free_ns(ns);
return ERR_PTR(error);
}
ns->parent = aa_get_ns(parent);
ns->level = parent->level + 1;
list_add_rcu(&ns->base.list, &parent->sub_ns);
aa_get_ns(ns);
mutex_unlock(&ns->lock);
return ns;
}
struct aa_ns *__aa_find_or_create_ns(struct aa_ns *parent, const char *name,
struct dentry *dir)
{
struct aa_ns *ns;
AA_BUG(!mutex_is_locked(&parent->lock));
ns = aa_get_ns(__aa_find_ns(&parent->sub_ns, name));
if (!ns)
ns = __aa_create_ns(parent, name, dir);
else
ns = ERR_PTR(-EEXIST);
return ns;
}
struct aa_ns *aa_prepare_ns(struct aa_ns *parent, const char *name)
{
struct aa_ns *ns;
mutex_lock(&parent->lock);
ns = aa_get_ns(__aa_find_ns(&parent->sub_ns, name));
if (!ns)
ns = __aa_create_ns(parent, name, NULL);
mutex_unlock(&parent->lock);
return ns;
}
static void destroy_ns(struct aa_ns *ns)
{
if (!ns)
return;
mutex_lock(&ns->lock);
__aa_profile_list_release(&ns->base.profiles);
__ns_list_release(&ns->sub_ns);
if (ns->parent) {
unsigned long flags;
write_lock_irqsave(&ns->labels.lock, flags);
__aa_proxy_redirect(ns_unconfined(ns),
ns_unconfined(ns->parent));
write_unlock_irqrestore(&ns->labels.lock, flags);
}
__aafs_ns_rmdir(ns);
mutex_unlock(&ns->lock);
}
void __aa_remove_ns(struct aa_ns *ns)
{
list_del_rcu(&ns->base.list);
destroy_ns(ns);
aa_put_ns(ns);
}
static void __ns_list_release(struct list_head *head)
{
struct aa_ns *ns, *tmp;
list_for_each_entry_safe(ns, tmp, head, base.list)
__aa_remove_ns(ns);
}
int __init aa_alloc_root_ns(void)
{
root_ns = alloc_ns(NULL, "root");
if (!root_ns)
return -ENOMEM;
return 0;
}
void __init aa_free_root_ns(void)
{
struct aa_ns *ns = root_ns;
root_ns = NULL;
destroy_ns(ns);
aa_put_ns(ns);
}
