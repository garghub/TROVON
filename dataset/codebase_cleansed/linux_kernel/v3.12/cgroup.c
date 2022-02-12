static struct cgroup_subsys_state *cgroup_css(struct cgroup *cgrp,
struct cgroup_subsys *ss)
{
if (ss)
return rcu_dereference_check(cgrp->subsys[ss->subsys_id],
lockdep_is_held(&cgroup_mutex));
else
return &cgrp->dummy_css;
}
static inline bool cgroup_is_dead(const struct cgroup *cgrp)
{
return test_bit(CGRP_DEAD, &cgrp->flags);
}
bool cgroup_is_descendant(struct cgroup *cgrp, struct cgroup *ancestor)
{
while (cgrp) {
if (cgrp == ancestor)
return true;
cgrp = cgrp->parent;
}
return false;
}
static int cgroup_is_releasable(const struct cgroup *cgrp)
{
const int bits =
(1 << CGRP_RELEASABLE) |
(1 << CGRP_NOTIFY_ON_RELEASE);
return (cgrp->flags & bits) == bits;
}
static int notify_on_release(const struct cgroup *cgrp)
{
return test_bit(CGRP_NOTIFY_ON_RELEASE, &cgrp->flags);
}
static inline struct cgroup *__d_cgrp(struct dentry *dentry)
{
return dentry->d_fsdata;
}
static inline struct cfent *__d_cfe(struct dentry *dentry)
{
return dentry->d_fsdata;
}
static inline struct cftype *__d_cft(struct dentry *dentry)
{
return __d_cfe(dentry)->type;
}
static bool cgroup_lock_live_group(struct cgroup *cgrp)
{
mutex_lock(&cgroup_mutex);
if (cgroup_is_dead(cgrp)) {
mutex_unlock(&cgroup_mutex);
return false;
}
return true;
}
static unsigned long css_set_hash(struct cgroup_subsys_state *css[])
{
unsigned long key = 0UL;
struct cgroup_subsys *ss;
int i;
for_each_subsys(ss, i)
key += (unsigned long)css[i];
key = (key >> 16) ^ key;
return key;
}
static void __put_css_set(struct css_set *cset, int taskexit)
{
struct cgrp_cset_link *link, *tmp_link;
if (atomic_add_unless(&cset->refcount, -1, 1))
return;
write_lock(&css_set_lock);
if (!atomic_dec_and_test(&cset->refcount)) {
write_unlock(&css_set_lock);
return;
}
hash_del(&cset->hlist);
css_set_count--;
list_for_each_entry_safe(link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct cgroup *cgrp = link->cgrp;
list_del(&link->cset_link);
list_del(&link->cgrp_link);
if (list_empty(&cgrp->cset_links) && notify_on_release(cgrp)) {
if (taskexit)
set_bit(CGRP_RELEASABLE, &cgrp->flags);
check_for_release(cgrp);
}
kfree(link);
}
write_unlock(&css_set_lock);
kfree_rcu(cset, rcu_head);
}
static inline void get_css_set(struct css_set *cset)
{
atomic_inc(&cset->refcount);
}
static inline void put_css_set(struct css_set *cset)
{
__put_css_set(cset, 0);
}
static inline void put_css_set_taskexit(struct css_set *cset)
{
__put_css_set(cset, 1);
}
static bool compare_css_sets(struct css_set *cset,
struct css_set *old_cset,
struct cgroup *new_cgrp,
struct cgroup_subsys_state *template[])
{
struct list_head *l1, *l2;
if (memcmp(template, cset->subsys, sizeof(cset->subsys))) {
return false;
}
l1 = &cset->cgrp_links;
l2 = &old_cset->cgrp_links;
while (1) {
struct cgrp_cset_link *link1, *link2;
struct cgroup *cgrp1, *cgrp2;
l1 = l1->next;
l2 = l2->next;
if (l1 == &cset->cgrp_links) {
BUG_ON(l2 != &old_cset->cgrp_links);
break;
} else {
BUG_ON(l2 == &old_cset->cgrp_links);
}
link1 = list_entry(l1, struct cgrp_cset_link, cgrp_link);
link2 = list_entry(l2, struct cgrp_cset_link, cgrp_link);
cgrp1 = link1->cgrp;
cgrp2 = link2->cgrp;
BUG_ON(cgrp1->root != cgrp2->root);
if (cgrp1->root == new_cgrp->root) {
if (cgrp1 != new_cgrp)
return false;
} else {
if (cgrp1 != cgrp2)
return false;
}
}
return true;
}
static struct css_set *find_existing_css_set(struct css_set *old_cset,
struct cgroup *cgrp,
struct cgroup_subsys_state *template[])
{
struct cgroupfs_root *root = cgrp->root;
struct cgroup_subsys *ss;
struct css_set *cset;
unsigned long key;
int i;
for_each_subsys(ss, i) {
if (root->subsys_mask & (1UL << i)) {
template[i] = cgroup_css(cgrp, ss);
} else {
template[i] = old_cset->subsys[i];
}
}
key = css_set_hash(template);
hash_for_each_possible(css_set_table, cset, hlist, key) {
if (!compare_css_sets(cset, old_cset, cgrp, template))
continue;
return cset;
}
return NULL;
}
static void free_cgrp_cset_links(struct list_head *links_to_free)
{
struct cgrp_cset_link *link, *tmp_link;
list_for_each_entry_safe(link, tmp_link, links_to_free, cset_link) {
list_del(&link->cset_link);
kfree(link);
}
}
static int allocate_cgrp_cset_links(int count, struct list_head *tmp_links)
{
struct cgrp_cset_link *link;
int i;
INIT_LIST_HEAD(tmp_links);
for (i = 0; i < count; i++) {
link = kzalloc(sizeof(*link), GFP_KERNEL);
if (!link) {
free_cgrp_cset_links(tmp_links);
return -ENOMEM;
}
list_add(&link->cset_link, tmp_links);
}
return 0;
}
static void link_css_set(struct list_head *tmp_links, struct css_set *cset,
struct cgroup *cgrp)
{
struct cgrp_cset_link *link;
BUG_ON(list_empty(tmp_links));
link = list_first_entry(tmp_links, struct cgrp_cset_link, cset_link);
link->cset = cset;
link->cgrp = cgrp;
list_move(&link->cset_link, &cgrp->cset_links);
list_add_tail(&link->cgrp_link, &cset->cgrp_links);
}
static struct css_set *find_css_set(struct css_set *old_cset,
struct cgroup *cgrp)
{
struct cgroup_subsys_state *template[CGROUP_SUBSYS_COUNT] = { };
struct css_set *cset;
struct list_head tmp_links;
struct cgrp_cset_link *link;
unsigned long key;
lockdep_assert_held(&cgroup_mutex);
read_lock(&css_set_lock);
cset = find_existing_css_set(old_cset, cgrp, template);
if (cset)
get_css_set(cset);
read_unlock(&css_set_lock);
if (cset)
return cset;
cset = kzalloc(sizeof(*cset), GFP_KERNEL);
if (!cset)
return NULL;
if (allocate_cgrp_cset_links(cgroup_root_count, &tmp_links) < 0) {
kfree(cset);
return NULL;
}
atomic_set(&cset->refcount, 1);
INIT_LIST_HEAD(&cset->cgrp_links);
INIT_LIST_HEAD(&cset->tasks);
INIT_HLIST_NODE(&cset->hlist);
memcpy(cset->subsys, template, sizeof(cset->subsys));
write_lock(&css_set_lock);
list_for_each_entry(link, &old_cset->cgrp_links, cgrp_link) {
struct cgroup *c = link->cgrp;
if (c->root == cgrp->root)
c = cgrp;
link_css_set(&tmp_links, cset, c);
}
BUG_ON(!list_empty(&tmp_links));
css_set_count++;
key = css_set_hash(cset->subsys);
hash_add(css_set_table, &cset->hlist, key);
write_unlock(&css_set_lock);
return cset;
}
static struct cgroup *task_cgroup_from_root(struct task_struct *task,
struct cgroupfs_root *root)
{
struct css_set *cset;
struct cgroup *res = NULL;
BUG_ON(!mutex_is_locked(&cgroup_mutex));
read_lock(&css_set_lock);
cset = task_css_set(task);
if (cset == &init_css_set) {
res = &root->top_cgroup;
} else {
struct cgrp_cset_link *link;
list_for_each_entry(link, &cset->cgrp_links, cgrp_link) {
struct cgroup *c = link->cgrp;
if (c->root == root) {
res = c;
break;
}
}
}
read_unlock(&css_set_lock);
BUG_ON(!res);
return res;
}
static struct inode *cgroup_new_inode(umode_t mode, struct super_block *sb)
{
struct inode *inode = new_inode(sb);
if (inode) {
inode->i_ino = get_next_ino();
inode->i_mode = mode;
inode->i_uid = current_fsuid();
inode->i_gid = current_fsgid();
inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;
inode->i_mapping->backing_dev_info = &cgroup_backing_dev_info;
}
return inode;
}
static struct cgroup_name *cgroup_alloc_name(struct dentry *dentry)
{
struct cgroup_name *name;
name = kmalloc(sizeof(*name) + dentry->d_name.len + 1, GFP_KERNEL);
if (!name)
return NULL;
strcpy(name->name, dentry->d_name.name);
return name;
}
static void cgroup_free_fn(struct work_struct *work)
{
struct cgroup *cgrp = container_of(work, struct cgroup, destroy_work);
mutex_lock(&cgroup_mutex);
cgrp->root->number_of_cgroups--;
mutex_unlock(&cgroup_mutex);
dput(cgrp->parent->dentry);
deactivate_super(cgrp->root->sb);
BUG_ON(!list_empty(&cgrp->pidlists));
simple_xattrs_free(&cgrp->xattrs);
kfree(rcu_dereference_raw(cgrp->name));
kfree(cgrp);
}
static void cgroup_free_rcu(struct rcu_head *head)
{
struct cgroup *cgrp = container_of(head, struct cgroup, rcu_head);
INIT_WORK(&cgrp->destroy_work, cgroup_free_fn);
schedule_work(&cgrp->destroy_work);
}
static void cgroup_diput(struct dentry *dentry, struct inode *inode)
{
if (S_ISDIR(inode->i_mode)) {
struct cgroup *cgrp = dentry->d_fsdata;
BUG_ON(!(cgroup_is_dead(cgrp)));
call_rcu(&cgrp->rcu_head, cgroup_free_rcu);
} else {
struct cfent *cfe = __d_cfe(dentry);
struct cgroup *cgrp = dentry->d_parent->d_fsdata;
WARN_ONCE(!list_empty(&cfe->node) &&
cgrp != &cgrp->root->top_cgroup,
"cfe still linked for %s\n", cfe->type->name);
simple_xattrs_free(&cfe->xattrs);
kfree(cfe);
}
iput(inode);
}
static int cgroup_delete(const struct dentry *d)
{
return 1;
}
static void remove_dir(struct dentry *d)
{
struct dentry *parent = dget(d->d_parent);
d_delete(d);
simple_rmdir(parent->d_inode, d);
dput(parent);
}
static void cgroup_rm_file(struct cgroup *cgrp, const struct cftype *cft)
{
struct cfent *cfe;
lockdep_assert_held(&cgrp->dentry->d_inode->i_mutex);
lockdep_assert_held(&cgroup_mutex);
list_for_each_entry(cfe, &cgrp->files, node) {
struct dentry *d = cfe->dentry;
if (cft && cfe->type != cft)
continue;
dget(d);
d_delete(d);
simple_unlink(cgrp->dentry->d_inode, d);
list_del_init(&cfe->node);
dput(d);
break;
}
}
static void cgroup_clear_dir(struct cgroup *cgrp, unsigned long subsys_mask)
{
struct cgroup_subsys *ss;
int i;
for_each_subsys(ss, i) {
struct cftype_set *set;
if (!test_bit(i, &subsys_mask))
continue;
list_for_each_entry(set, &ss->cftsets, node)
cgroup_addrm_files(cgrp, set->cfts, false);
}
}
static void cgroup_d_remove_dir(struct dentry *dentry)
{
struct dentry *parent;
parent = dentry->d_parent;
spin_lock(&parent->d_lock);
spin_lock_nested(&dentry->d_lock, DENTRY_D_LOCK_NESTED);
list_del_init(&dentry->d_u.d_child);
spin_unlock(&dentry->d_lock);
spin_unlock(&parent->d_lock);
remove_dir(dentry);
}
static int rebind_subsystems(struct cgroupfs_root *root,
unsigned long added_mask, unsigned removed_mask)
{
struct cgroup *cgrp = &root->top_cgroup;
struct cgroup_subsys *ss;
unsigned long pinned = 0;
int i, ret;
BUG_ON(!mutex_is_locked(&cgroup_mutex));
BUG_ON(!mutex_is_locked(&cgroup_root_mutex));
for_each_subsys(ss, i) {
if (!(added_mask & (1 << i)))
continue;
if (ss->root != &cgroup_dummy_root) {
ret = -EBUSY;
goto out_put;
}
if (!try_module_get(ss->module)) {
ret = -ENOENT;
goto out_put;
}
pinned |= 1 << i;
}
if (added_mask != pinned) {
ret = -ENOENT;
goto out_put;
}
ret = cgroup_populate_dir(cgrp, added_mask);
if (ret)
goto out_put;
cgroup_clear_dir(cgrp, removed_mask);
for_each_subsys(ss, i) {
unsigned long bit = 1UL << i;
if (bit & added_mask) {
BUG_ON(cgroup_css(cgrp, ss));
BUG_ON(!cgroup_css(cgroup_dummy_top, ss));
BUG_ON(cgroup_css(cgroup_dummy_top, ss)->cgroup != cgroup_dummy_top);
rcu_assign_pointer(cgrp->subsys[i],
cgroup_css(cgroup_dummy_top, ss));
cgroup_css(cgrp, ss)->cgroup = cgrp;
list_move(&ss->sibling, &root->subsys_list);
ss->root = root;
if (ss->bind)
ss->bind(cgroup_css(cgrp, ss));
root->subsys_mask |= bit;
} else if (bit & removed_mask) {
BUG_ON(cgroup_css(cgrp, ss) != cgroup_css(cgroup_dummy_top, ss));
BUG_ON(cgroup_css(cgrp, ss)->cgroup != cgrp);
if (ss->bind)
ss->bind(cgroup_css(cgroup_dummy_top, ss));
cgroup_css(cgroup_dummy_top, ss)->cgroup = cgroup_dummy_top;
RCU_INIT_POINTER(cgrp->subsys[i], NULL);
cgroup_subsys[i]->root = &cgroup_dummy_root;
list_move(&ss->sibling, &cgroup_dummy_root.subsys_list);
module_put(ss->module);
root->subsys_mask &= ~bit;
}
}
root->flags |= CGRP_ROOT_SUBSYS_BOUND;
return 0;
out_put:
for_each_subsys(ss, i)
if (pinned & (1 << i))
module_put(ss->module);
return ret;
}
static int cgroup_show_options(struct seq_file *seq, struct dentry *dentry)
{
struct cgroupfs_root *root = dentry->d_sb->s_fs_info;
struct cgroup_subsys *ss;
mutex_lock(&cgroup_root_mutex);
for_each_root_subsys(root, ss)
seq_printf(seq, ",%s", ss->name);
if (root->flags & CGRP_ROOT_SANE_BEHAVIOR)
seq_puts(seq, ",sane_behavior");
if (root->flags & CGRP_ROOT_NOPREFIX)
seq_puts(seq, ",noprefix");
if (root->flags & CGRP_ROOT_XATTR)
seq_puts(seq, ",xattr");
if (strlen(root->release_agent_path))
seq_printf(seq, ",release_agent=%s", root->release_agent_path);
if (test_bit(CGRP_CPUSET_CLONE_CHILDREN, &root->top_cgroup.flags))
seq_puts(seq, ",clone_children");
if (strlen(root->name))
seq_printf(seq, ",name=%s", root->name);
mutex_unlock(&cgroup_root_mutex);
return 0;
}
static int parse_cgroupfs_options(char *data, struct cgroup_sb_opts *opts)
{
char *token, *o = data;
bool all_ss = false, one_ss = false;
unsigned long mask = (unsigned long)-1;
struct cgroup_subsys *ss;
int i;
BUG_ON(!mutex_is_locked(&cgroup_mutex));
#ifdef CONFIG_CPUSETS
mask = ~(1UL << cpuset_subsys_id);
#endif
memset(opts, 0, sizeof(*opts));
while ((token = strsep(&o, ",")) != NULL) {
if (!*token)
return -EINVAL;
if (!strcmp(token, "none")) {
opts->none = true;
continue;
}
if (!strcmp(token, "all")) {
if (one_ss)
return -EINVAL;
all_ss = true;
continue;
}
if (!strcmp(token, "__DEVEL__sane_behavior")) {
opts->flags |= CGRP_ROOT_SANE_BEHAVIOR;
continue;
}
if (!strcmp(token, "noprefix")) {
opts->flags |= CGRP_ROOT_NOPREFIX;
continue;
}
if (!strcmp(token, "clone_children")) {
opts->cpuset_clone_children = true;
continue;
}
if (!strcmp(token, "xattr")) {
opts->flags |= CGRP_ROOT_XATTR;
continue;
}
if (!strncmp(token, "release_agent=", 14)) {
if (opts->release_agent)
return -EINVAL;
opts->release_agent =
kstrndup(token + 14, PATH_MAX - 1, GFP_KERNEL);
if (!opts->release_agent)
return -ENOMEM;
continue;
}
if (!strncmp(token, "name=", 5)) {
const char *name = token + 5;
if (!strlen(name))
return -EINVAL;
for (i = 0; i < strlen(name); i++) {
char c = name[i];
if (isalnum(c))
continue;
if ((c == '.') || (c == '-') || (c == '_'))
continue;
return -EINVAL;
}
if (opts->name)
return -EINVAL;
opts->name = kstrndup(name,
MAX_CGROUP_ROOT_NAMELEN - 1,
GFP_KERNEL);
if (!opts->name)
return -ENOMEM;
continue;
}
for_each_subsys(ss, i) {
if (strcmp(token, ss->name))
continue;
if (ss->disabled)
continue;
if (all_ss)
return -EINVAL;
set_bit(i, &opts->subsys_mask);
one_ss = true;
break;
}
if (i == CGROUP_SUBSYS_COUNT)
return -ENOENT;
}
if (all_ss || (!one_ss && !opts->none && !opts->name))
for_each_subsys(ss, i)
if (!ss->disabled)
set_bit(i, &opts->subsys_mask);
if (opts->flags & CGRP_ROOT_SANE_BEHAVIOR) {
pr_warning("cgroup: sane_behavior: this is still under development and its behaviors will change, proceed at your own risk\n");
if (opts->flags & CGRP_ROOT_NOPREFIX) {
pr_err("cgroup: sane_behavior: noprefix is not allowed\n");
return -EINVAL;
}
if (opts->cpuset_clone_children) {
pr_err("cgroup: sane_behavior: clone_children is not allowed\n");
return -EINVAL;
}
}
if ((opts->flags & CGRP_ROOT_NOPREFIX) && (opts->subsys_mask & mask))
return -EINVAL;
if (opts->subsys_mask && opts->none)
return -EINVAL;
if (!opts->subsys_mask && !opts->name)
return -EINVAL;
return 0;
}
static int cgroup_remount(struct super_block *sb, int *flags, char *data)
{
int ret = 0;
struct cgroupfs_root *root = sb->s_fs_info;
struct cgroup *cgrp = &root->top_cgroup;
struct cgroup_sb_opts opts;
unsigned long added_mask, removed_mask;
if (root->flags & CGRP_ROOT_SANE_BEHAVIOR) {
pr_err("cgroup: sane_behavior: remount is not allowed\n");
return -EINVAL;
}
mutex_lock(&cgrp->dentry->d_inode->i_mutex);
mutex_lock(&cgroup_mutex);
mutex_lock(&cgroup_root_mutex);
ret = parse_cgroupfs_options(data, &opts);
if (ret)
goto out_unlock;
if (opts.subsys_mask != root->subsys_mask || opts.release_agent)
pr_warning("cgroup: option changes via remount are deprecated (pid=%d comm=%s)\n",
task_tgid_nr(current), current->comm);
added_mask = opts.subsys_mask & ~root->subsys_mask;
removed_mask = root->subsys_mask & ~opts.subsys_mask;
if (((opts.flags ^ root->flags) & CGRP_ROOT_OPTION_MASK) ||
(opts.name && strcmp(opts.name, root->name))) {
pr_err("cgroup: option or name mismatch, new: 0x%lx \"%s\", old: 0x%lx \"%s\"\n",
opts.flags & CGRP_ROOT_OPTION_MASK, opts.name ?: "",
root->flags & CGRP_ROOT_OPTION_MASK, root->name);
ret = -EINVAL;
goto out_unlock;
}
if (root->number_of_cgroups > 1) {
ret = -EBUSY;
goto out_unlock;
}
ret = rebind_subsystems(root, added_mask, removed_mask);
if (ret)
goto out_unlock;
if (opts.release_agent)
strcpy(root->release_agent_path, opts.release_agent);
out_unlock:
kfree(opts.release_agent);
kfree(opts.name);
mutex_unlock(&cgroup_root_mutex);
mutex_unlock(&cgroup_mutex);
mutex_unlock(&cgrp->dentry->d_inode->i_mutex);
return ret;
}
static void init_cgroup_housekeeping(struct cgroup *cgrp)
{
INIT_LIST_HEAD(&cgrp->sibling);
INIT_LIST_HEAD(&cgrp->children);
INIT_LIST_HEAD(&cgrp->files);
INIT_LIST_HEAD(&cgrp->cset_links);
INIT_LIST_HEAD(&cgrp->release_list);
INIT_LIST_HEAD(&cgrp->pidlists);
mutex_init(&cgrp->pidlist_mutex);
cgrp->dummy_css.cgroup = cgrp;
INIT_LIST_HEAD(&cgrp->event_list);
spin_lock_init(&cgrp->event_list_lock);
simple_xattrs_init(&cgrp->xattrs);
}
static void init_cgroup_root(struct cgroupfs_root *root)
{
struct cgroup *cgrp = &root->top_cgroup;
INIT_LIST_HEAD(&root->subsys_list);
INIT_LIST_HEAD(&root->root_list);
root->number_of_cgroups = 1;
cgrp->root = root;
RCU_INIT_POINTER(cgrp->name, &root_cgroup_name);
init_cgroup_housekeeping(cgrp);
idr_init(&root->cgroup_idr);
}
static int cgroup_init_root_id(struct cgroupfs_root *root, int start, int end)
{
int id;
lockdep_assert_held(&cgroup_mutex);
lockdep_assert_held(&cgroup_root_mutex);
id = idr_alloc_cyclic(&cgroup_hierarchy_idr, root, start, end,
GFP_KERNEL);
if (id < 0)
return id;
root->hierarchy_id = id;
return 0;
}
static void cgroup_exit_root_id(struct cgroupfs_root *root)
{
lockdep_assert_held(&cgroup_mutex);
lockdep_assert_held(&cgroup_root_mutex);
if (root->hierarchy_id) {
idr_remove(&cgroup_hierarchy_idr, root->hierarchy_id);
root->hierarchy_id = 0;
}
}
static int cgroup_test_super(struct super_block *sb, void *data)
{
struct cgroup_sb_opts *opts = data;
struct cgroupfs_root *root = sb->s_fs_info;
if (opts->name && strcmp(opts->name, root->name))
return 0;
if ((opts->subsys_mask || opts->none)
&& (opts->subsys_mask != root->subsys_mask))
return 0;
return 1;
}
static struct cgroupfs_root *cgroup_root_from_opts(struct cgroup_sb_opts *opts)
{
struct cgroupfs_root *root;
if (!opts->subsys_mask && !opts->none)
return NULL;
root = kzalloc(sizeof(*root), GFP_KERNEL);
if (!root)
return ERR_PTR(-ENOMEM);
init_cgroup_root(root);
root->subsys_mask = opts->subsys_mask;
root->flags = opts->flags;
if (opts->release_agent)
strcpy(root->release_agent_path, opts->release_agent);
if (opts->name)
strcpy(root->name, opts->name);
if (opts->cpuset_clone_children)
set_bit(CGRP_CPUSET_CLONE_CHILDREN, &root->top_cgroup.flags);
return root;
}
static void cgroup_free_root(struct cgroupfs_root *root)
{
if (root) {
WARN_ON_ONCE(root->hierarchy_id);
idr_destroy(&root->cgroup_idr);
kfree(root);
}
}
static int cgroup_set_super(struct super_block *sb, void *data)
{
int ret;
struct cgroup_sb_opts *opts = data;
if (!opts->new_root)
return -EINVAL;
BUG_ON(!opts->subsys_mask && !opts->none);
ret = set_anon_super(sb, NULL);
if (ret)
return ret;
sb->s_fs_info = opts->new_root;
opts->new_root->sb = sb;
sb->s_blocksize = PAGE_CACHE_SIZE;
sb->s_blocksize_bits = PAGE_CACHE_SHIFT;
sb->s_magic = CGROUP_SUPER_MAGIC;
sb->s_op = &cgroup_ops;
return 0;
}
static int cgroup_get_rootdir(struct super_block *sb)
{
static const struct dentry_operations cgroup_dops = {
.d_iput = cgroup_diput,
.d_delete = cgroup_delete,
};
struct inode *inode =
cgroup_new_inode(S_IFDIR | S_IRUGO | S_IXUGO | S_IWUSR, sb);
if (!inode)
return -ENOMEM;
inode->i_fop = &simple_dir_operations;
inode->i_op = &cgroup_dir_inode_operations;
inc_nlink(inode);
sb->s_root = d_make_root(inode);
if (!sb->s_root)
return -ENOMEM;
sb->s_d_op = &cgroup_dops;
return 0;
}
static struct dentry *cgroup_mount(struct file_system_type *fs_type,
int flags, const char *unused_dev_name,
void *data)
{
struct cgroup_sb_opts opts;
struct cgroupfs_root *root;
int ret = 0;
struct super_block *sb;
struct cgroupfs_root *new_root;
struct list_head tmp_links;
struct inode *inode;
const struct cred *cred;
mutex_lock(&cgroup_mutex);
ret = parse_cgroupfs_options(data, &opts);
mutex_unlock(&cgroup_mutex);
if (ret)
goto out_err;
new_root = cgroup_root_from_opts(&opts);
if (IS_ERR(new_root)) {
ret = PTR_ERR(new_root);
goto out_err;
}
opts.new_root = new_root;
sb = sget(fs_type, cgroup_test_super, cgroup_set_super, 0, &opts);
if (IS_ERR(sb)) {
ret = PTR_ERR(sb);
cgroup_free_root(opts.new_root);
goto out_err;
}
root = sb->s_fs_info;
BUG_ON(!root);
if (root == opts.new_root) {
struct cgroup *root_cgrp = &root->top_cgroup;
struct cgroupfs_root *existing_root;
int i;
struct css_set *cset;
BUG_ON(sb->s_root != NULL);
ret = cgroup_get_rootdir(sb);
if (ret)
goto drop_new_super;
inode = sb->s_root->d_inode;
mutex_lock(&inode->i_mutex);
mutex_lock(&cgroup_mutex);
mutex_lock(&cgroup_root_mutex);
root_cgrp->id = idr_alloc(&root->cgroup_idr, root_cgrp,
0, 1, GFP_KERNEL);
if (root_cgrp->id < 0)
goto unlock_drop;
ret = -EBUSY;
if (strlen(root->name))
for_each_active_root(existing_root)
if (!strcmp(existing_root->name, root->name))
goto unlock_drop;
ret = allocate_cgrp_cset_links(css_set_count, &tmp_links);
if (ret)
goto unlock_drop;
ret = cgroup_init_root_id(root, 2, 0);
if (ret)
goto unlock_drop;
sb->s_root->d_fsdata = root_cgrp;
root_cgrp->dentry = sb->s_root;
cred = override_creds(&init_cred);
ret = cgroup_addrm_files(root_cgrp, cgroup_base_files, true);
if (ret)
goto rm_base_files;
ret = rebind_subsystems(root, root->subsys_mask, 0);
if (ret)
goto rm_base_files;
revert_creds(cred);
list_add(&root->root_list, &cgroup_roots);
cgroup_root_count++;
write_lock(&css_set_lock);
hash_for_each(css_set_table, i, cset, hlist)
link_css_set(&tmp_links, cset, root_cgrp);
write_unlock(&css_set_lock);
free_cgrp_cset_links(&tmp_links);
BUG_ON(!list_empty(&root_cgrp->children));
BUG_ON(root->number_of_cgroups != 1);
mutex_unlock(&cgroup_root_mutex);
mutex_unlock(&cgroup_mutex);
mutex_unlock(&inode->i_mutex);
} else {
cgroup_free_root(opts.new_root);
if ((root->flags ^ opts.flags) & CGRP_ROOT_OPTION_MASK) {
if ((root->flags | opts.flags) & CGRP_ROOT_SANE_BEHAVIOR) {
pr_err("cgroup: sane_behavior: new mount options should match the existing superblock\n");
ret = -EINVAL;
goto drop_new_super;
} else {
pr_warning("cgroup: new mount options do not match the existing superblock, will be ignored\n");
}
}
}
kfree(opts.release_agent);
kfree(opts.name);
return dget(sb->s_root);
rm_base_files:
free_cgrp_cset_links(&tmp_links);
cgroup_addrm_files(&root->top_cgroup, cgroup_base_files, false);
revert_creds(cred);
unlock_drop:
cgroup_exit_root_id(root);
mutex_unlock(&cgroup_root_mutex);
mutex_unlock(&cgroup_mutex);
mutex_unlock(&inode->i_mutex);
drop_new_super:
deactivate_locked_super(sb);
out_err:
kfree(opts.release_agent);
kfree(opts.name);
return ERR_PTR(ret);
}
static void cgroup_kill_sb(struct super_block *sb) {
struct cgroupfs_root *root = sb->s_fs_info;
struct cgroup *cgrp = &root->top_cgroup;
struct cgrp_cset_link *link, *tmp_link;
int ret;
BUG_ON(!root);
BUG_ON(root->number_of_cgroups != 1);
BUG_ON(!list_empty(&cgrp->children));
mutex_lock(&cgrp->dentry->d_inode->i_mutex);
mutex_lock(&cgroup_mutex);
mutex_lock(&cgroup_root_mutex);
if (root->flags & CGRP_ROOT_SUBSYS_BOUND) {
ret = rebind_subsystems(root, 0, root->subsys_mask);
BUG_ON(ret);
}
write_lock(&css_set_lock);
list_for_each_entry_safe(link, tmp_link, &cgrp->cset_links, cset_link) {
list_del(&link->cset_link);
list_del(&link->cgrp_link);
kfree(link);
}
write_unlock(&css_set_lock);
if (!list_empty(&root->root_list)) {
list_del(&root->root_list);
cgroup_root_count--;
}
cgroup_exit_root_id(root);
mutex_unlock(&cgroup_root_mutex);
mutex_unlock(&cgroup_mutex);
mutex_unlock(&cgrp->dentry->d_inode->i_mutex);
simple_xattrs_free(&cgrp->xattrs);
kill_litter_super(sb);
cgroup_free_root(root);
}
int cgroup_path(const struct cgroup *cgrp, char *buf, int buflen)
{
int ret = -ENAMETOOLONG;
char *start;
if (!cgrp->parent) {
if (strlcpy(buf, "/", buflen) >= buflen)
return -ENAMETOOLONG;
return 0;
}
start = buf + buflen - 1;
*start = '\0';
rcu_read_lock();
do {
const char *name = cgroup_name(cgrp);
int len;
len = strlen(name);
if ((start -= len) < buf)
goto out;
memcpy(start, name, len);
if (--start < buf)
goto out;
*start = '/';
cgrp = cgrp->parent;
} while (cgrp->parent);
ret = 0;
memmove(buf, start, buf + buflen - start);
out:
rcu_read_unlock();
return ret;
}
int task_cgroup_path(struct task_struct *task, char *buf, size_t buflen)
{
struct cgroupfs_root *root;
struct cgroup *cgrp;
int hierarchy_id = 1, ret = 0;
if (buflen < 2)
return -ENAMETOOLONG;
mutex_lock(&cgroup_mutex);
root = idr_get_next(&cgroup_hierarchy_idr, &hierarchy_id);
if (root) {
cgrp = task_cgroup_from_root(task, root);
ret = cgroup_path(cgrp, buf, buflen);
} else {
memcpy(buf, "/", 2);
}
mutex_unlock(&cgroup_mutex);
return ret;
}
struct task_struct *cgroup_taskset_first(struct cgroup_taskset *tset)
{
if (tset->tc_array) {
tset->idx = 0;
return cgroup_taskset_next(tset);
} else {
tset->cur_cgrp = tset->single.cgrp;
return tset->single.task;
}
}
struct task_struct *cgroup_taskset_next(struct cgroup_taskset *tset)
{
struct task_and_cgroup *tc;
if (!tset->tc_array || tset->idx >= tset->tc_array_len)
return NULL;
tc = flex_array_get(tset->tc_array, tset->idx++);
tset->cur_cgrp = tc->cgrp;
return tc->task;
}
struct cgroup_subsys_state *cgroup_taskset_cur_css(struct cgroup_taskset *tset,
int subsys_id)
{
return cgroup_css(tset->cur_cgrp, cgroup_subsys[subsys_id]);
}
int cgroup_taskset_size(struct cgroup_taskset *tset)
{
return tset->tc_array ? tset->tc_array_len : 1;
}
static void cgroup_task_migrate(struct cgroup *old_cgrp,
struct task_struct *tsk,
struct css_set *new_cset)
{
struct css_set *old_cset;
WARN_ON_ONCE(tsk->flags & PF_EXITING);
old_cset = task_css_set(tsk);
task_lock(tsk);
rcu_assign_pointer(tsk->cgroups, new_cset);
task_unlock(tsk);
write_lock(&css_set_lock);
if (!list_empty(&tsk->cg_list))
list_move(&tsk->cg_list, &new_cset->tasks);
write_unlock(&css_set_lock);
set_bit(CGRP_RELEASABLE, &old_cgrp->flags);
put_css_set(old_cset);
}
static int cgroup_attach_task(struct cgroup *cgrp, struct task_struct *tsk,
bool threadgroup)
{
int retval, i, group_size;
struct cgroup_subsys *ss, *failed_ss = NULL;
struct cgroupfs_root *root = cgrp->root;
struct task_struct *leader = tsk;
struct task_and_cgroup *tc;
struct flex_array *group;
struct cgroup_taskset tset = { };
if (threadgroup)
group_size = get_nr_threads(tsk);
else
group_size = 1;
group = flex_array_alloc(sizeof(*tc), group_size, GFP_KERNEL);
if (!group)
return -ENOMEM;
retval = flex_array_prealloc(group, 0, group_size, GFP_KERNEL);
if (retval)
goto out_free_group_list;
i = 0;
rcu_read_lock();
do {
struct task_and_cgroup ent;
if (tsk->flags & PF_EXITING)
goto next;
BUG_ON(i >= group_size);
ent.task = tsk;
ent.cgrp = task_cgroup_from_root(tsk, root);
if (ent.cgrp == cgrp)
goto next;
retval = flex_array_put(group, i, &ent, GFP_ATOMIC);
BUG_ON(retval != 0);
i++;
next:
if (!threadgroup)
break;
} while_each_thread(leader, tsk);
int attach_task_by_pid(struct cgroup *cgrp, u64 pid, bool threadgroup)
{
struct task_struct *tsk;
const struct cred *cred = current_cred(), *tcred;
int ret;
if (!cgroup_lock_live_group(cgrp))
return -ENODEV;
retry_find_task:
rcu_read_lock();
if (pid) {
tsk = find_task_by_vpid(pid);
if (!tsk) {
rcu_read_unlock();
ret= -ESRCH;
goto out_unlock_cgroup;
}
tcred = __task_cred(tsk);
if (!uid_eq(cred->euid, GLOBAL_ROOT_UID) &&
!uid_eq(cred->euid, tcred->uid) &&
!uid_eq(cred->euid, tcred->suid)) {
rcu_read_unlock();
ret = -EACCES;
goto out_unlock_cgroup;
}
} else
tsk = current;
if (threadgroup)
tsk = tsk->group_leader;
if (tsk == kthreadd_task || (tsk->flags & PF_NO_SETAFFINITY)) {
ret = -EINVAL;
rcu_read_unlock();
goto out_unlock_cgroup;
}
get_task_struct(tsk);
rcu_read_unlock();
threadgroup_lock(tsk);
if (threadgroup) {
if (!thread_group_leader(tsk)) {
threadgroup_unlock(tsk);
put_task_struct(tsk);
goto retry_find_task;
}
}
ret = cgroup_attach_task(cgrp, tsk, threadgroup);
threadgroup_unlock(tsk);
put_task_struct(tsk);
out_unlock_cgroup:
mutex_unlock(&cgroup_mutex);
return ret;
}
int cgroup_attach_task_all(struct task_struct *from, struct task_struct *tsk)
{
struct cgroupfs_root *root;
int retval = 0;
mutex_lock(&cgroup_mutex);
for_each_active_root(root) {
struct cgroup *from_cgrp = task_cgroup_from_root(from, root);
retval = cgroup_attach_task(from_cgrp, tsk, false);
if (retval)
break;
}
mutex_unlock(&cgroup_mutex);
return retval;
}
static int cgroup_tasks_write(struct cgroup_subsys_state *css,
struct cftype *cft, u64 pid)
{
return attach_task_by_pid(css->cgroup, pid, false);
}
static int cgroup_procs_write(struct cgroup_subsys_state *css,
struct cftype *cft, u64 tgid)
{
return attach_task_by_pid(css->cgroup, tgid, true);
}
static int cgroup_release_agent_write(struct cgroup_subsys_state *css,
struct cftype *cft, const char *buffer)
{
BUILD_BUG_ON(sizeof(css->cgroup->root->release_agent_path) < PATH_MAX);
if (strlen(buffer) >= PATH_MAX)
return -EINVAL;
if (!cgroup_lock_live_group(css->cgroup))
return -ENODEV;
mutex_lock(&cgroup_root_mutex);
strcpy(css->cgroup->root->release_agent_path, buffer);
mutex_unlock(&cgroup_root_mutex);
mutex_unlock(&cgroup_mutex);
return 0;
}
static int cgroup_release_agent_show(struct cgroup_subsys_state *css,
struct cftype *cft, struct seq_file *seq)
{
struct cgroup *cgrp = css->cgroup;
if (!cgroup_lock_live_group(cgrp))
return -ENODEV;
seq_puts(seq, cgrp->root->release_agent_path);
seq_putc(seq, '\n');
mutex_unlock(&cgroup_mutex);
return 0;
}
static int cgroup_sane_behavior_show(struct cgroup_subsys_state *css,
struct cftype *cft, struct seq_file *seq)
{
seq_printf(seq, "%d\n", cgroup_sane_behavior(css->cgroup));
return 0;
}
static ssize_t cgroup_write_X64(struct cgroup_subsys_state *css,
struct cftype *cft, struct file *file,
const char __user *userbuf, size_t nbytes,
loff_t *unused_ppos)
{
char buffer[CGROUP_LOCAL_BUFFER_SIZE];
int retval = 0;
char *end;
if (!nbytes)
return -EINVAL;
if (nbytes >= sizeof(buffer))
return -E2BIG;
if (copy_from_user(buffer, userbuf, nbytes))
return -EFAULT;
buffer[nbytes] = 0;
if (cft->write_u64) {
u64 val = simple_strtoull(strstrip(buffer), &end, 0);
if (*end)
return -EINVAL;
retval = cft->write_u64(css, cft, val);
} else {
s64 val = simple_strtoll(strstrip(buffer), &end, 0);
if (*end)
return -EINVAL;
retval = cft->write_s64(css, cft, val);
}
if (!retval)
retval = nbytes;
return retval;
}
static ssize_t cgroup_write_string(struct cgroup_subsys_state *css,
struct cftype *cft, struct file *file,
const char __user *userbuf, size_t nbytes,
loff_t *unused_ppos)
{
char local_buffer[CGROUP_LOCAL_BUFFER_SIZE];
int retval = 0;
size_t max_bytes = cft->max_write_len;
char *buffer = local_buffer;
if (!max_bytes)
max_bytes = sizeof(local_buffer) - 1;
if (nbytes >= max_bytes)
return -E2BIG;
if (nbytes >= sizeof(local_buffer)) {
buffer = kmalloc(nbytes + 1, GFP_KERNEL);
if (buffer == NULL)
return -ENOMEM;
}
if (nbytes && copy_from_user(buffer, userbuf, nbytes)) {
retval = -EFAULT;
goto out;
}
buffer[nbytes] = 0;
retval = cft->write_string(css, cft, strstrip(buffer));
if (!retval)
retval = nbytes;
out:
if (buffer != local_buffer)
kfree(buffer);
return retval;
}
static ssize_t cgroup_file_write(struct file *file, const char __user *buf,
size_t nbytes, loff_t *ppos)
{
struct cfent *cfe = __d_cfe(file->f_dentry);
struct cftype *cft = __d_cft(file->f_dentry);
struct cgroup_subsys_state *css = cfe->css;
if (cft->write)
return cft->write(css, cft, file, buf, nbytes, ppos);
if (cft->write_u64 || cft->write_s64)
return cgroup_write_X64(css, cft, file, buf, nbytes, ppos);
if (cft->write_string)
return cgroup_write_string(css, cft, file, buf, nbytes, ppos);
if (cft->trigger) {
int ret = cft->trigger(css, (unsigned int)cft->private);
return ret ? ret : nbytes;
}
return -EINVAL;
}
static ssize_t cgroup_read_u64(struct cgroup_subsys_state *css,
struct cftype *cft, struct file *file,
char __user *buf, size_t nbytes, loff_t *ppos)
{
char tmp[CGROUP_LOCAL_BUFFER_SIZE];
u64 val = cft->read_u64(css, cft);
int len = sprintf(tmp, "%llu\n", (unsigned long long) val);
return simple_read_from_buffer(buf, nbytes, ppos, tmp, len);
}
static ssize_t cgroup_read_s64(struct cgroup_subsys_state *css,
struct cftype *cft, struct file *file,
char __user *buf, size_t nbytes, loff_t *ppos)
{
char tmp[CGROUP_LOCAL_BUFFER_SIZE];
s64 val = cft->read_s64(css, cft);
int len = sprintf(tmp, "%lld\n", (long long) val);
return simple_read_from_buffer(buf, nbytes, ppos, tmp, len);
}
static ssize_t cgroup_file_read(struct file *file, char __user *buf,
size_t nbytes, loff_t *ppos)
{
struct cfent *cfe = __d_cfe(file->f_dentry);
struct cftype *cft = __d_cft(file->f_dentry);
struct cgroup_subsys_state *css = cfe->css;
if (cft->read)
return cft->read(css, cft, file, buf, nbytes, ppos);
if (cft->read_u64)
return cgroup_read_u64(css, cft, file, buf, nbytes, ppos);
if (cft->read_s64)
return cgroup_read_s64(css, cft, file, buf, nbytes, ppos);
return -EINVAL;
}
static int cgroup_map_add(struct cgroup_map_cb *cb, const char *key, u64 value)
{
struct seq_file *sf = cb->state;
return seq_printf(sf, "%s %llu\n", key, (unsigned long long)value);
}
static int cgroup_seqfile_show(struct seq_file *m, void *arg)
{
struct cfent *cfe = m->private;
struct cftype *cft = cfe->type;
struct cgroup_subsys_state *css = cfe->css;
if (cft->read_map) {
struct cgroup_map_cb cb = {
.fill = cgroup_map_add,
.state = m,
};
return cft->read_map(css, cft, &cb);
}
return cft->read_seq_string(css, cft, m);
}
static int cgroup_file_open(struct inode *inode, struct file *file)
{
struct cfent *cfe = __d_cfe(file->f_dentry);
struct cftype *cft = __d_cft(file->f_dentry);
struct cgroup *cgrp = __d_cgrp(cfe->dentry->d_parent);
struct cgroup_subsys_state *css;
int err;
err = generic_file_open(inode, file);
if (err)
return err;
rcu_read_lock();
css = cgroup_css(cgrp, cft->ss);
if (cft->ss && !css_tryget(css))
css = NULL;
rcu_read_unlock();
if (!css)
return -ENODEV;
WARN_ON_ONCE(cfe->css && cfe->css != css);
cfe->css = css;
if (cft->read_map || cft->read_seq_string) {
file->f_op = &cgroup_seqfile_operations;
err = single_open(file, cgroup_seqfile_show, cfe);
} else if (cft->open) {
err = cft->open(inode, file);
}
if (css->ss && err)
css_put(css);
return err;
}
static int cgroup_file_release(struct inode *inode, struct file *file)
{
struct cfent *cfe = __d_cfe(file->f_dentry);
struct cftype *cft = __d_cft(file->f_dentry);
struct cgroup_subsys_state *css = cfe->css;
int ret = 0;
if (cft->release)
ret = cft->release(inode, file);
if (css->ss)
css_put(css);
return ret;
}
static int cgroup_rename(struct inode *old_dir, struct dentry *old_dentry,
struct inode *new_dir, struct dentry *new_dentry)
{
int ret;
struct cgroup_name *name, *old_name;
struct cgroup *cgrp;
lockdep_assert_held(&old_dir->i_mutex);
if (!S_ISDIR(old_dentry->d_inode->i_mode))
return -ENOTDIR;
if (new_dentry->d_inode)
return -EEXIST;
if (old_dir != new_dir)
return -EIO;
cgrp = __d_cgrp(old_dentry);
if (cgroup_sane_behavior(cgrp))
return -EPERM;
name = cgroup_alloc_name(new_dentry);
if (!name)
return -ENOMEM;
ret = simple_rename(old_dir, old_dentry, new_dir, new_dentry);
if (ret) {
kfree(name);
return ret;
}
old_name = rcu_dereference_protected(cgrp->name, true);
rcu_assign_pointer(cgrp->name, name);
kfree_rcu(old_name, rcu_head);
return 0;
}
static struct simple_xattrs *__d_xattrs(struct dentry *dentry)
{
if (S_ISDIR(dentry->d_inode->i_mode))
return &__d_cgrp(dentry)->xattrs;
else
return &__d_cfe(dentry)->xattrs;
}
static inline int xattr_enabled(struct dentry *dentry)
{
struct cgroupfs_root *root = dentry->d_sb->s_fs_info;
return root->flags & CGRP_ROOT_XATTR;
}
static bool is_valid_xattr(const char *name)
{
if (!strncmp(name, XATTR_TRUSTED_PREFIX, XATTR_TRUSTED_PREFIX_LEN) ||
!strncmp(name, XATTR_SECURITY_PREFIX, XATTR_SECURITY_PREFIX_LEN))
return true;
return false;
}
static int cgroup_setxattr(struct dentry *dentry, const char *name,
const void *val, size_t size, int flags)
{
if (!xattr_enabled(dentry))
return -EOPNOTSUPP;
if (!is_valid_xattr(name))
return -EINVAL;
return simple_xattr_set(__d_xattrs(dentry), name, val, size, flags);
}
static int cgroup_removexattr(struct dentry *dentry, const char *name)
{
if (!xattr_enabled(dentry))
return -EOPNOTSUPP;
if (!is_valid_xattr(name))
return -EINVAL;
return simple_xattr_remove(__d_xattrs(dentry), name);
}
static ssize_t cgroup_getxattr(struct dentry *dentry, const char *name,
void *buf, size_t size)
{
if (!xattr_enabled(dentry))
return -EOPNOTSUPP;
if (!is_valid_xattr(name))
return -EINVAL;
return simple_xattr_get(__d_xattrs(dentry), name, buf, size);
}
static ssize_t cgroup_listxattr(struct dentry *dentry, char *buf, size_t size)
{
if (!xattr_enabled(dentry))
return -EOPNOTSUPP;
return simple_xattr_list(__d_xattrs(dentry), buf, size);
}
static inline struct cftype *__file_cft(struct file *file)
{
if (file_inode(file)->i_fop != &cgroup_file_operations)
return ERR_PTR(-EINVAL);
return __d_cft(file->f_dentry);
}
static int cgroup_create_file(struct dentry *dentry, umode_t mode,
struct super_block *sb)
{
struct inode *inode;
if (!dentry)
return -ENOENT;
if (dentry->d_inode)
return -EEXIST;
inode = cgroup_new_inode(mode, sb);
if (!inode)
return -ENOMEM;
if (S_ISDIR(mode)) {
inode->i_op = &cgroup_dir_inode_operations;
inode->i_fop = &simple_dir_operations;
inc_nlink(inode);
inc_nlink(dentry->d_parent->d_inode);
WARN_ON_ONCE(!mutex_trylock(&inode->i_mutex));
} else if (S_ISREG(mode)) {
inode->i_size = 0;
inode->i_fop = &cgroup_file_operations;
inode->i_op = &cgroup_file_inode_operations;
}
d_instantiate(dentry, inode);
dget(dentry);
return 0;
}
static umode_t cgroup_file_mode(const struct cftype *cft)
{
umode_t mode = 0;
if (cft->mode)
return cft->mode;
if (cft->read || cft->read_u64 || cft->read_s64 ||
cft->read_map || cft->read_seq_string)
mode |= S_IRUGO;
if (cft->write || cft->write_u64 || cft->write_s64 ||
cft->write_string || cft->trigger)
mode |= S_IWUSR;
return mode;
}
static int cgroup_add_file(struct cgroup *cgrp, struct cftype *cft)
{
struct dentry *dir = cgrp->dentry;
struct cgroup *parent = __d_cgrp(dir);
struct dentry *dentry;
struct cfent *cfe;
int error;
umode_t mode;
char name[MAX_CGROUP_TYPE_NAMELEN + MAX_CFTYPE_NAME + 2] = { 0 };
if (cft->ss && !(cft->flags & CFTYPE_NO_PREFIX) &&
!(cgrp->root->flags & CGRP_ROOT_NOPREFIX)) {
strcpy(name, cft->ss->name);
strcat(name, ".");
}
strcat(name, cft->name);
BUG_ON(!mutex_is_locked(&dir->d_inode->i_mutex));
cfe = kzalloc(sizeof(*cfe), GFP_KERNEL);
if (!cfe)
return -ENOMEM;
dentry = lookup_one_len(name, dir, strlen(name));
if (IS_ERR(dentry)) {
error = PTR_ERR(dentry);
goto out;
}
cfe->type = (void *)cft;
cfe->dentry = dentry;
dentry->d_fsdata = cfe;
simple_xattrs_init(&cfe->xattrs);
mode = cgroup_file_mode(cft);
error = cgroup_create_file(dentry, mode | S_IFREG, cgrp->root->sb);
if (!error) {
list_add_tail(&cfe->node, &parent->files);
cfe = NULL;
}
dput(dentry);
out:
kfree(cfe);
return error;
}
static int cgroup_addrm_files(struct cgroup *cgrp, struct cftype cfts[],
bool is_add)
{
struct cftype *cft;
int ret;
lockdep_assert_held(&cgrp->dentry->d_inode->i_mutex);
lockdep_assert_held(&cgroup_mutex);
for (cft = cfts; cft->name[0] != '\0'; cft++) {
if ((cft->flags & CFTYPE_INSANE) && cgroup_sane_behavior(cgrp))
continue;
if ((cft->flags & CFTYPE_NOT_ON_ROOT) && !cgrp->parent)
continue;
if ((cft->flags & CFTYPE_ONLY_ON_ROOT) && cgrp->parent)
continue;
if (is_add) {
ret = cgroup_add_file(cgrp, cft);
if (ret) {
pr_warn("cgroup_addrm_files: failed to add %s, err=%d\n",
cft->name, ret);
return ret;
}
} else {
cgroup_rm_file(cgrp, cft);
}
}
return 0;
}
static void cgroup_cfts_prepare(void)
__acquires(&cgroup_mutex
static int cgroup_cfts_commit(struct cftype *cfts, bool is_add)
__releases(&cgroup_mutex
int cgroup_add_cftypes(struct cgroup_subsys *ss, struct cftype *cfts)
{
struct cftype_set *set;
struct cftype *cft;
int ret;
set = kzalloc(sizeof(*set), GFP_KERNEL);
if (!set)
return -ENOMEM;
for (cft = cfts; cft->name[0] != '\0'; cft++)
cft->ss = ss;
cgroup_cfts_prepare();
set->cfts = cfts;
list_add_tail(&set->node, &ss->cftsets);
ret = cgroup_cfts_commit(cfts, true);
if (ret)
cgroup_rm_cftypes(cfts);
return ret;
}
int cgroup_rm_cftypes(struct cftype *cfts)
{
struct cftype_set *set;
if (!cfts || !cfts[0].ss)
return -ENOENT;
cgroup_cfts_prepare();
list_for_each_entry(set, &cfts[0].ss->cftsets, node) {
if (set->cfts == cfts) {
list_del(&set->node);
kfree(set);
cgroup_cfts_commit(cfts, false);
return 0;
}
}
cgroup_cfts_commit(NULL, false);
return -ENOENT;
}
int cgroup_task_count(const struct cgroup *cgrp)
{
int count = 0;
struct cgrp_cset_link *link;
read_lock(&css_set_lock);
list_for_each_entry(link, &cgrp->cset_links, cset_link)
count += atomic_read(&link->cset->refcount);
read_unlock(&css_set_lock);
return count;
}
static void cgroup_enable_task_cg_lists(void)
{
struct task_struct *p, *g;
write_lock(&css_set_lock);
use_task_css_set_links = 1;
read_lock(&tasklist_lock);
do_each_thread(g, p) {
task_lock(p);
if (!(p->flags & PF_EXITING) && list_empty(&p->cg_list))
list_add(&p->cg_list, &task_css_set(p)->tasks);
task_unlock(p);
} while_each_thread(g, p);
read_unlock(&tasklist_lock);
write_unlock(&css_set_lock);
}
struct cgroup_subsys_state *
css_next_child(struct cgroup_subsys_state *pos_css,
struct cgroup_subsys_state *parent_css)
{
struct cgroup *pos = pos_css ? pos_css->cgroup : NULL;
struct cgroup *cgrp = parent_css->cgroup;
struct cgroup *next;
WARN_ON_ONCE(!rcu_read_lock_held());
if (!pos) {
next = list_entry_rcu(cgrp->children.next, struct cgroup, sibling);
} else if (likely(!cgroup_is_dead(pos))) {
next = list_entry_rcu(pos->sibling.next, struct cgroup, sibling);
} else {
list_for_each_entry_rcu(next, &cgrp->children, sibling)
if (next->serial_nr > pos->serial_nr)
break;
}
if (&next->sibling == &cgrp->children)
return NULL;
return cgroup_css(next, parent_css->ss);
}
struct cgroup_subsys_state *
css_next_descendant_pre(struct cgroup_subsys_state *pos,
struct cgroup_subsys_state *root)
{
struct cgroup_subsys_state *next;
WARN_ON_ONCE(!rcu_read_lock_held());
if (!pos)
return root;
next = css_next_child(NULL, pos);
if (next)
return next;
while (pos != root) {
next = css_next_child(pos, css_parent(pos));
if (next)
return next;
pos = css_parent(pos);
}
return NULL;
}
struct cgroup_subsys_state *
css_rightmost_descendant(struct cgroup_subsys_state *pos)
{
struct cgroup_subsys_state *last, *tmp;
WARN_ON_ONCE(!rcu_read_lock_held());
do {
last = pos;
pos = NULL;
css_for_each_child(tmp, last)
pos = tmp;
} while (pos);
return last;
}
static struct cgroup_subsys_state *
css_leftmost_descendant(struct cgroup_subsys_state *pos)
{
struct cgroup_subsys_state *last;
do {
last = pos;
pos = css_next_child(NULL, pos);
} while (pos);
return last;
}
struct cgroup_subsys_state *
css_next_descendant_post(struct cgroup_subsys_state *pos,
struct cgroup_subsys_state *root)
{
struct cgroup_subsys_state *next;
WARN_ON_ONCE(!rcu_read_lock_held());
if (!pos)
return css_leftmost_descendant(root);
if (pos == root)
return NULL;
next = css_next_child(pos, css_parent(pos));
if (next)
return css_leftmost_descendant(next);
return css_parent(pos);
}
static void css_advance_task_iter(struct css_task_iter *it)
{
struct list_head *l = it->cset_link;
struct cgrp_cset_link *link;
struct css_set *cset;
do {
l = l->next;
if (l == &it->origin_css->cgroup->cset_links) {
it->cset_link = NULL;
return;
}
link = list_entry(l, struct cgrp_cset_link, cset_link);
cset = link->cset;
} while (list_empty(&cset->tasks));
it->cset_link = l;
it->task = cset->tasks.next;
}
void css_task_iter_start(struct cgroup_subsys_state *css,
struct css_task_iter *it)
__acquires(css_set_lock)
{
if (!use_task_css_set_links)
cgroup_enable_task_cg_lists();
read_lock(&css_set_lock);
it->origin_css = css;
it->cset_link = &css->cgroup->cset_links;
css_advance_task_iter(it);
}
struct task_struct *css_task_iter_next(struct css_task_iter *it)
{
struct task_struct *res;
struct list_head *l = it->task;
struct cgrp_cset_link *link;
if (!it->cset_link)
return NULL;
res = list_entry(l, struct task_struct, cg_list);
l = l->next;
link = list_entry(it->cset_link, struct cgrp_cset_link, cset_link);
if (l == &link->cset->tasks) {
css_advance_task_iter(it);
} else {
it->task = l;
}
return res;
}
void css_task_iter_end(struct css_task_iter *it)
__releases(css_set_lock)
{
read_unlock(&css_set_lock);
}
static inline int started_after_time(struct task_struct *t1,
struct timespec *time,
struct task_struct *t2)
{
int start_diff = timespec_compare(&t1->start_time, time);
if (start_diff > 0) {
return 1;
} else if (start_diff < 0) {
return 0;
} else {
return t1 > t2;
}
}
static inline int started_after(void *p1, void *p2)
{
struct task_struct *t1 = p1;
struct task_struct *t2 = p2;
return started_after_time(t1, &t2->start_time, t2);
}
int css_scan_tasks(struct cgroup_subsys_state *css,
bool (*test)(struct task_struct *, void *),
void (*process)(struct task_struct *, void *),
void *data, struct ptr_heap *heap)
{
int retval, i;
struct css_task_iter it;
struct task_struct *p, *dropped;
struct task_struct *latest_task = NULL;
struct ptr_heap tmp_heap;
struct timespec latest_time = { 0, 0 };
if (heap) {
heap->gt = &started_after;
} else {
heap = &tmp_heap;
retval = heap_init(heap, PAGE_SIZE, GFP_KERNEL, &started_after);
if (retval)
return retval;
}
again:
heap->size = 0;
css_task_iter_start(css, &it);
while ((p = css_task_iter_next(&it))) {
if (test && !test(p, data))
continue;
if (!started_after_time(p, &latest_time, latest_task))
continue;
dropped = heap_insert(heap, p);
if (dropped == NULL) {
get_task_struct(p);
} else if (dropped != p) {
get_task_struct(p);
put_task_struct(dropped);
}
}
css_task_iter_end(&it);
if (heap->size) {
for (i = 0; i < heap->size; i++) {
struct task_struct *q = heap->ptrs[i];
if (i == 0) {
latest_time = q->start_time;
latest_task = q;
}
process(q, data);
put_task_struct(q);
}
goto again;
}
if (heap == &tmp_heap)
heap_free(&tmp_heap);
return 0;
}
static void cgroup_transfer_one_task(struct task_struct *task, void *data)
{
struct cgroup *new_cgroup = data;
mutex_lock(&cgroup_mutex);
cgroup_attach_task(new_cgroup, task, false);
mutex_unlock(&cgroup_mutex);
}
int cgroup_transfer_tasks(struct cgroup *to, struct cgroup *from)
{
return css_scan_tasks(&from->dummy_css, NULL, cgroup_transfer_one_task,
to, NULL);
}
static void *pidlist_allocate(int count)
{
if (PIDLIST_TOO_LARGE(count))
return vmalloc(count * sizeof(pid_t));
else
return kmalloc(count * sizeof(pid_t), GFP_KERNEL);
}
static void pidlist_free(void *p)
{
if (is_vmalloc_addr(p))
vfree(p);
else
kfree(p);
}
static int pidlist_uniq(pid_t *list, int length)
{
int src, dest = 1;
if (length == 0 || length == 1)
return length;
for (src = 1; src < length; src++) {
while (list[src] == list[src-1]) {
src++;
if (src == length)
goto after;
}
list[dest] = list[src];
dest++;
}
after:
return dest;
}
static int cmppid(const void *a, const void *b)
{
return *(pid_t *)a - *(pid_t *)b;
}
static struct cgroup_pidlist *cgroup_pidlist_find(struct cgroup *cgrp,
enum cgroup_filetype type)
{
struct cgroup_pidlist *l;
struct pid_namespace *ns = task_active_pid_ns(current);
mutex_lock(&cgrp->pidlist_mutex);
list_for_each_entry(l, &cgrp->pidlists, links) {
if (l->key.type == type && l->key.ns == ns) {
down_write(&l->rwsem);
mutex_unlock(&cgrp->pidlist_mutex);
return l;
}
}
l = kzalloc(sizeof(struct cgroup_pidlist), GFP_KERNEL);
if (!l) {
mutex_unlock(&cgrp->pidlist_mutex);
return l;
}
init_rwsem(&l->rwsem);
down_write(&l->rwsem);
l->key.type = type;
l->key.ns = get_pid_ns(ns);
l->owner = cgrp;
list_add(&l->links, &cgrp->pidlists);
mutex_unlock(&cgrp->pidlist_mutex);
return l;
}
static int pidlist_array_load(struct cgroup *cgrp, enum cgroup_filetype type,
struct cgroup_pidlist **lp)
{
pid_t *array;
int length;
int pid, n = 0;
struct css_task_iter it;
struct task_struct *tsk;
struct cgroup_pidlist *l;
length = cgroup_task_count(cgrp);
array = pidlist_allocate(length);
if (!array)
return -ENOMEM;
css_task_iter_start(&cgrp->dummy_css, &it);
while ((tsk = css_task_iter_next(&it))) {
if (unlikely(n == length))
break;
if (type == CGROUP_FILE_PROCS)
pid = task_tgid_vnr(tsk);
else
pid = task_pid_vnr(tsk);
if (pid > 0)
array[n++] = pid;
}
css_task_iter_end(&it);
length = n;
sort(array, length, sizeof(pid_t), cmppid, NULL);
if (type == CGROUP_FILE_PROCS)
length = pidlist_uniq(array, length);
l = cgroup_pidlist_find(cgrp, type);
if (!l) {
pidlist_free(array);
return -ENOMEM;
}
pidlist_free(l->list);
l->list = array;
l->length = length;
l->use_count++;
up_write(&l->rwsem);
*lp = l;
return 0;
}
int cgroupstats_build(struct cgroupstats *stats, struct dentry *dentry)
{
int ret = -EINVAL;
struct cgroup *cgrp;
struct css_task_iter it;
struct task_struct *tsk;
if (dentry->d_sb->s_op != &cgroup_ops ||
!S_ISDIR(dentry->d_inode->i_mode))
goto err;
ret = 0;
cgrp = dentry->d_fsdata;
css_task_iter_start(&cgrp->dummy_css, &it);
while ((tsk = css_task_iter_next(&it))) {
switch (tsk->state) {
case TASK_RUNNING:
stats->nr_running++;
break;
case TASK_INTERRUPTIBLE:
stats->nr_sleeping++;
break;
case TASK_UNINTERRUPTIBLE:
stats->nr_uninterruptible++;
break;
case TASK_STOPPED:
stats->nr_stopped++;
break;
default:
if (delayacct_is_task_waiting_on_io(tsk))
stats->nr_io_wait++;
break;
}
}
css_task_iter_end(&it);
err:
return ret;
}
static void *cgroup_pidlist_start(struct seq_file *s, loff_t *pos)
{
struct cgroup_pidlist *l = s->private;
int index = 0, pid = *pos;
int *iter;
down_read(&l->rwsem);
if (pid) {
int end = l->length;
while (index < end) {
int mid = (index + end) / 2;
if (l->list[mid] == pid) {
index = mid;
break;
} else if (l->list[mid] <= pid)
index = mid + 1;
else
end = mid;
}
}
if (index >= l->length)
return NULL;
iter = l->list + index;
*pos = *iter;
return iter;
}
static void cgroup_pidlist_stop(struct seq_file *s, void *v)
{
struct cgroup_pidlist *l = s->private;
up_read(&l->rwsem);
}
static void *cgroup_pidlist_next(struct seq_file *s, void *v, loff_t *pos)
{
struct cgroup_pidlist *l = s->private;
pid_t *p = v;
pid_t *end = l->list + l->length;
p++;
if (p >= end) {
return NULL;
} else {
*pos = *p;
return p;
}
}
static int cgroup_pidlist_show(struct seq_file *s, void *v)
{
return seq_printf(s, "%d\n", *(int *)v);
}
static void cgroup_release_pid_array(struct cgroup_pidlist *l)
{
mutex_lock(&l->owner->pidlist_mutex);
down_write(&l->rwsem);
BUG_ON(!l->use_count);
if (!--l->use_count) {
list_del(&l->links);
mutex_unlock(&l->owner->pidlist_mutex);
pidlist_free(l->list);
put_pid_ns(l->key.ns);
up_write(&l->rwsem);
kfree(l);
return;
}
mutex_unlock(&l->owner->pidlist_mutex);
up_write(&l->rwsem);
}
static int cgroup_pidlist_release(struct inode *inode, struct file *file)
{
struct cgroup_pidlist *l;
if (!(file->f_mode & FMODE_READ))
return 0;
l = ((struct seq_file *)file->private_data)->private;
cgroup_release_pid_array(l);
return seq_release(inode, file);
}
static int cgroup_pidlist_open(struct file *file, enum cgroup_filetype type)
{
struct cgroup *cgrp = __d_cgrp(file->f_dentry->d_parent);
struct cgroup_pidlist *l;
int retval;
if (!(file->f_mode & FMODE_READ))
return 0;
retval = pidlist_array_load(cgrp, type, &l);
if (retval)
return retval;
file->f_op = &cgroup_pidlist_operations;
retval = seq_open(file, &cgroup_pidlist_seq_operations);
if (retval) {
cgroup_release_pid_array(l);
return retval;
}
((struct seq_file *)file->private_data)->private = l;
return 0;
}
static int cgroup_tasks_open(struct inode *unused, struct file *file)
{
return cgroup_pidlist_open(file, CGROUP_FILE_TASKS);
}
static int cgroup_procs_open(struct inode *unused, struct file *file)
{
return cgroup_pidlist_open(file, CGROUP_FILE_PROCS);
}
static u64 cgroup_read_notify_on_release(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return notify_on_release(css->cgroup);
}
static int cgroup_write_notify_on_release(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
clear_bit(CGRP_RELEASABLE, &css->cgroup->flags);
if (val)
set_bit(CGRP_NOTIFY_ON_RELEASE, &css->cgroup->flags);
else
clear_bit(CGRP_NOTIFY_ON_RELEASE, &css->cgroup->flags);
return 0;
}
static void cgroup_dput(struct cgroup *cgrp)
{
struct super_block *sb = cgrp->root->sb;
atomic_inc(&sb->s_active);
dput(cgrp->dentry);
deactivate_super(sb);
}
static void cgroup_event_remove(struct work_struct *work)
{
struct cgroup_event *event = container_of(work, struct cgroup_event,
remove);
struct cgroup_subsys_state *css = event->css;
remove_wait_queue(event->wqh, &event->wait);
event->cft->unregister_event(css, event->cft, event->eventfd);
eventfd_signal(event->eventfd, 1);
eventfd_ctx_put(event->eventfd);
kfree(event);
css_put(css);
}
static int cgroup_event_wake(wait_queue_t *wait, unsigned mode,
int sync, void *key)
{
struct cgroup_event *event = container_of(wait,
struct cgroup_event, wait);
struct cgroup *cgrp = event->css->cgroup;
unsigned long flags = (unsigned long)key;
if (flags & POLLHUP) {
spin_lock(&cgrp->event_list_lock);
if (!list_empty(&event->list)) {
list_del_init(&event->list);
schedule_work(&event->remove);
}
spin_unlock(&cgrp->event_list_lock);
}
return 0;
}
static void cgroup_event_ptable_queue_proc(struct file *file,
wait_queue_head_t *wqh, poll_table *pt)
{
struct cgroup_event *event = container_of(pt,
struct cgroup_event, pt);
event->wqh = wqh;
add_wait_queue(wqh, &event->wait);
}
static int cgroup_write_event_control(struct cgroup_subsys_state *dummy_css,
struct cftype *cft, const char *buffer)
{
struct cgroup *cgrp = dummy_css->cgroup;
struct cgroup_event *event;
struct cgroup_subsys_state *cfile_css;
unsigned int efd, cfd;
struct fd efile;
struct fd cfile;
char *endp;
int ret;
efd = simple_strtoul(buffer, &endp, 10);
if (*endp != ' ')
return -EINVAL;
buffer = endp + 1;
cfd = simple_strtoul(buffer, &endp, 10);
if ((*endp != ' ') && (*endp != '\0'))
return -EINVAL;
buffer = endp + 1;
event = kzalloc(sizeof(*event), GFP_KERNEL);
if (!event)
return -ENOMEM;
INIT_LIST_HEAD(&event->list);
init_poll_funcptr(&event->pt, cgroup_event_ptable_queue_proc);
init_waitqueue_func_entry(&event->wait, cgroup_event_wake);
INIT_WORK(&event->remove, cgroup_event_remove);
efile = fdget(efd);
if (!efile.file) {
ret = -EBADF;
goto out_kfree;
}
event->eventfd = eventfd_ctx_fileget(efile.file);
if (IS_ERR(event->eventfd)) {
ret = PTR_ERR(event->eventfd);
goto out_put_efile;
}
cfile = fdget(cfd);
if (!cfile.file) {
ret = -EBADF;
goto out_put_eventfd;
}
ret = inode_permission(file_inode(cfile.file), MAY_READ);
if (ret < 0)
goto out_put_cfile;
event->cft = __file_cft(cfile.file);
if (IS_ERR(event->cft)) {
ret = PTR_ERR(event->cft);
goto out_put_cfile;
}
if (!event->cft->ss) {
ret = -EBADF;
goto out_put_cfile;
}
rcu_read_lock();
ret = -EINVAL;
event->css = cgroup_css(cgrp, event->cft->ss);
cfile_css = css_from_dir(cfile.file->f_dentry->d_parent, event->cft->ss);
if (event->css && event->css == cfile_css && css_tryget(event->css))
ret = 0;
rcu_read_unlock();
if (ret)
goto out_put_cfile;
if (!event->cft->register_event || !event->cft->unregister_event) {
ret = -EINVAL;
goto out_put_css;
}
ret = event->cft->register_event(event->css, event->cft,
event->eventfd, buffer);
if (ret)
goto out_put_css;
efile.file->f_op->poll(efile.file, &event->pt);
spin_lock(&cgrp->event_list_lock);
list_add(&event->list, &cgrp->event_list);
spin_unlock(&cgrp->event_list_lock);
fdput(cfile);
fdput(efile);
return 0;
out_put_css:
css_put(event->css);
out_put_cfile:
fdput(cfile);
out_put_eventfd:
eventfd_ctx_put(event->eventfd);
out_put_efile:
fdput(efile);
out_kfree:
kfree(event);
return ret;
}
static u64 cgroup_clone_children_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return test_bit(CGRP_CPUSET_CLONE_CHILDREN, &css->cgroup->flags);
}
static int cgroup_clone_children_write(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
if (val)
set_bit(CGRP_CPUSET_CLONE_CHILDREN, &css->cgroup->flags);
else
clear_bit(CGRP_CPUSET_CLONE_CHILDREN, &css->cgroup->flags);
return 0;
}
static int cgroup_populate_dir(struct cgroup *cgrp, unsigned long subsys_mask)
{
struct cgroup_subsys *ss;
int i, ret = 0;
for_each_subsys(ss, i) {
struct cftype_set *set;
if (!test_bit(i, &subsys_mask))
continue;
list_for_each_entry(set, &ss->cftsets, node) {
ret = cgroup_addrm_files(cgrp, set->cfts, true);
if (ret < 0)
goto err;
}
}
for_each_root_subsys(cgrp->root, ss) {
struct cgroup_subsys_state *css = cgroup_css(cgrp, ss);
struct css_id *id = rcu_dereference_protected(css->id, true);
if (id)
rcu_assign_pointer(id->css, css);
}
return 0;
err:
cgroup_clear_dir(cgrp, subsys_mask);
return ret;
}
static void css_free_work_fn(struct work_struct *work)
{
struct cgroup_subsys_state *css =
container_of(work, struct cgroup_subsys_state, destroy_work);
struct cgroup *cgrp = css->cgroup;
if (css->parent)
css_put(css->parent);
css->ss->css_free(css);
cgroup_dput(cgrp);
}
static void css_free_rcu_fn(struct rcu_head *rcu_head)
{
struct cgroup_subsys_state *css =
container_of(rcu_head, struct cgroup_subsys_state, rcu_head);
INIT_WORK(&css->destroy_work, css_free_work_fn);
schedule_work(&css->destroy_work);
}
static void css_release(struct percpu_ref *ref)
{
struct cgroup_subsys_state *css =
container_of(ref, struct cgroup_subsys_state, refcnt);
call_rcu(&css->rcu_head, css_free_rcu_fn);
}
static void init_css(struct cgroup_subsys_state *css, struct cgroup_subsys *ss,
struct cgroup *cgrp)
{
css->cgroup = cgrp;
css->ss = ss;
css->flags = 0;
css->id = NULL;
if (cgrp->parent)
css->parent = cgroup_css(cgrp->parent, ss);
else
css->flags |= CSS_ROOT;
BUG_ON(cgroup_css(cgrp, ss));
}
static int online_css(struct cgroup_subsys_state *css)
{
struct cgroup_subsys *ss = css->ss;
int ret = 0;
lockdep_assert_held(&cgroup_mutex);
if (ss->css_online)
ret = ss->css_online(css);
if (!ret) {
css->flags |= CSS_ONLINE;
css->cgroup->nr_css++;
rcu_assign_pointer(css->cgroup->subsys[ss->subsys_id], css);
}
return ret;
}
static void offline_css(struct cgroup_subsys_state *css)
{
struct cgroup_subsys *ss = css->ss;
lockdep_assert_held(&cgroup_mutex);
if (!(css->flags & CSS_ONLINE))
return;
if (ss->css_offline)
ss->css_offline(css);
css->flags &= ~CSS_ONLINE;
css->cgroup->nr_css--;
RCU_INIT_POINTER(css->cgroup->subsys[ss->subsys_id], css);
}
static long cgroup_create(struct cgroup *parent, struct dentry *dentry,
umode_t mode)
{
struct cgroup_subsys_state *css_ar[CGROUP_SUBSYS_COUNT] = { };
struct cgroup *cgrp;
struct cgroup_name *name;
struct cgroupfs_root *root = parent->root;
int err = 0;
struct cgroup_subsys *ss;
struct super_block *sb = root->sb;
cgrp = kzalloc(sizeof(*cgrp), GFP_KERNEL);
if (!cgrp)
return -ENOMEM;
name = cgroup_alloc_name(dentry);
if (!name)
goto err_free_cgrp;
rcu_assign_pointer(cgrp->name, name);
cgrp->id = idr_alloc(&root->cgroup_idr, NULL, 1, 0, GFP_KERNEL);
if (cgrp->id < 0)
goto err_free_name;
if (!cgroup_lock_live_group(parent)) {
err = -ENODEV;
goto err_free_id;
}
atomic_inc(&sb->s_active);
init_cgroup_housekeeping(cgrp);
dentry->d_fsdata = cgrp;
cgrp->dentry = dentry;
cgrp->parent = parent;
cgrp->dummy_css.parent = &parent->dummy_css;
cgrp->root = parent->root;
if (notify_on_release(parent))
set_bit(CGRP_NOTIFY_ON_RELEASE, &cgrp->flags);
if (test_bit(CGRP_CPUSET_CLONE_CHILDREN, &parent->flags))
set_bit(CGRP_CPUSET_CLONE_CHILDREN, &cgrp->flags);
for_each_root_subsys(root, ss) {
struct cgroup_subsys_state *css;
css = ss->css_alloc(cgroup_css(parent, ss));
if (IS_ERR(css)) {
err = PTR_ERR(css);
goto err_free_all;
}
css_ar[ss->subsys_id] = css;
err = percpu_ref_init(&css->refcnt, css_release);
if (err)
goto err_free_all;
init_css(css, ss, cgrp);
if (ss->use_id) {
err = alloc_css_id(css);
if (err)
goto err_free_all;
}
}
err = cgroup_create_file(dentry, S_IFDIR | mode, sb);
if (err < 0)
goto err_free_all;
lockdep_assert_held(&dentry->d_inode->i_mutex);
cgrp->serial_nr = cgroup_serial_nr_next++;
list_add_tail_rcu(&cgrp->sibling, &cgrp->parent->children);
root->number_of_cgroups++;
for_each_root_subsys(root, ss) {
struct cgroup_subsys_state *css = css_ar[ss->subsys_id];
dget(dentry);
css_get(css->parent);
}
dget(parent->dentry);
for_each_root_subsys(root, ss) {
struct cgroup_subsys_state *css = css_ar[ss->subsys_id];
err = online_css(css);
if (err)
goto err_destroy;
if (ss->broken_hierarchy && !ss->warned_broken_hierarchy &&
parent->parent) {
pr_warning("cgroup: %s (%d) created nested cgroup for controller \"%s\" which has incomplete hierarchy support. Nested cgroups may change behavior in the future.\n",
current->comm, current->pid, ss->name);
if (!strcmp(ss->name, "memory"))
pr_warning("cgroup: \"memory\" requires setting use_hierarchy to 1 on the root.\n");
ss->warned_broken_hierarchy = true;
}
}
idr_replace(&root->cgroup_idr, cgrp, cgrp->id);
err = cgroup_addrm_files(cgrp, cgroup_base_files, true);
if (err)
goto err_destroy;
err = cgroup_populate_dir(cgrp, root->subsys_mask);
if (err)
goto err_destroy;
mutex_unlock(&cgroup_mutex);
mutex_unlock(&cgrp->dentry->d_inode->i_mutex);
return 0;
err_free_all:
for_each_root_subsys(root, ss) {
struct cgroup_subsys_state *css = css_ar[ss->subsys_id];
if (css) {
percpu_ref_cancel_init(&css->refcnt);
ss->css_free(css);
}
}
mutex_unlock(&cgroup_mutex);
deactivate_super(sb);
err_free_id:
idr_remove(&root->cgroup_idr, cgrp->id);
err_free_name:
kfree(rcu_dereference_raw(cgrp->name));
err_free_cgrp:
kfree(cgrp);
return err;
err_destroy:
cgroup_destroy_locked(cgrp);
mutex_unlock(&cgroup_mutex);
mutex_unlock(&dentry->d_inode->i_mutex);
return err;
}
static int cgroup_mkdir(struct inode *dir, struct dentry *dentry, umode_t mode)
{
struct cgroup *c_parent = dentry->d_parent->d_fsdata;
return cgroup_create(c_parent, dentry, mode | S_IFDIR);
}
static void css_killed_work_fn(struct work_struct *work)
{
struct cgroup_subsys_state *css =
container_of(work, struct cgroup_subsys_state, destroy_work);
struct cgroup *cgrp = css->cgroup;
mutex_lock(&cgroup_mutex);
offline_css(css);
if (!cgrp->nr_css && cgroup_is_dead(cgrp))
cgroup_destroy_css_killed(cgrp);
mutex_unlock(&cgroup_mutex);
css_put(css);
}
static void css_killed_ref_fn(struct percpu_ref *ref)
{
struct cgroup_subsys_state *css =
container_of(ref, struct cgroup_subsys_state, refcnt);
INIT_WORK(&css->destroy_work, css_killed_work_fn);
schedule_work(&css->destroy_work);
}
static void kill_css(struct cgroup_subsys_state *css)
{
cgroup_clear_dir(css->cgroup, 1 << css->ss->subsys_id);
css_get(css);
percpu_ref_kill_and_confirm(&css->refcnt, css_killed_ref_fn);
}
static int cgroup_destroy_locked(struct cgroup *cgrp)
__releases(&cgroup_mutex
static void cgroup_destroy_css_killed(struct cgroup *cgrp)
{
struct cgroup *parent = cgrp->parent;
struct dentry *d = cgrp->dentry;
lockdep_assert_held(&cgroup_mutex);
list_del_rcu(&cgrp->sibling);
idr_remove(&cgrp->root->cgroup_idr, cgrp->id);
cgrp->id = -1;
dput(d);
set_bit(CGRP_RELEASABLE, &parent->flags);
check_for_release(parent);
}
static int cgroup_rmdir(struct inode *unused_dir, struct dentry *dentry)
{
int ret;
mutex_lock(&cgroup_mutex);
ret = cgroup_destroy_locked(dentry->d_fsdata);
mutex_unlock(&cgroup_mutex);
return ret;
}
static void __init_or_module cgroup_init_cftsets(struct cgroup_subsys *ss)
{
INIT_LIST_HEAD(&ss->cftsets);
if (ss->base_cftypes) {
struct cftype *cft;
for (cft = ss->base_cftypes; cft->name[0] != '\0'; cft++)
cft->ss = ss;
ss->base_cftset.cfts = ss->base_cftypes;
list_add_tail(&ss->base_cftset.node, &ss->cftsets);
}
}
static void __init cgroup_init_subsys(struct cgroup_subsys *ss)
{
struct cgroup_subsys_state *css;
printk(KERN_INFO "Initializing cgroup subsys %s\n", ss->name);
mutex_lock(&cgroup_mutex);
cgroup_init_cftsets(ss);
list_add(&ss->sibling, &cgroup_dummy_root.subsys_list);
ss->root = &cgroup_dummy_root;
css = ss->css_alloc(cgroup_css(cgroup_dummy_top, ss));
BUG_ON(IS_ERR(css));
init_css(css, ss, cgroup_dummy_top);
init_css_set.subsys[ss->subsys_id] = css;
need_forkexit_callback |= ss->fork || ss->exit;
BUG_ON(!list_empty(&init_task.tasks));
BUG_ON(online_css(css));
mutex_unlock(&cgroup_mutex);
BUG_ON(ss->module);
}
int __init_or_module cgroup_load_subsys(struct cgroup_subsys *ss)
{
struct cgroup_subsys_state *css;
int i, ret;
struct hlist_node *tmp;
struct css_set *cset;
unsigned long key;
if (ss->name == NULL || strlen(ss->name) > MAX_CGROUP_TYPE_NAMELEN ||
ss->css_alloc == NULL || ss->css_free == NULL)
return -EINVAL;
if (ss->fork || ss->exit)
return -EINVAL;
if (ss->module == NULL) {
BUG_ON(cgroup_subsys[ss->subsys_id] != ss);
return 0;
}
cgroup_init_cftsets(ss);
mutex_lock(&cgroup_mutex);
cgroup_subsys[ss->subsys_id] = ss;
css = ss->css_alloc(cgroup_css(cgroup_dummy_top, ss));
if (IS_ERR(css)) {
cgroup_subsys[ss->subsys_id] = NULL;
mutex_unlock(&cgroup_mutex);
return PTR_ERR(css);
}
list_add(&ss->sibling, &cgroup_dummy_root.subsys_list);
ss->root = &cgroup_dummy_root;
init_css(css, ss, cgroup_dummy_top);
if (ss->use_id) {
ret = cgroup_init_idr(ss, css);
if (ret)
goto err_unload;
}
write_lock(&css_set_lock);
hash_for_each_safe(css_set_table, i, tmp, cset, hlist) {
if (cset->subsys[ss->subsys_id])
continue;
hash_del(&cset->hlist);
cset->subsys[ss->subsys_id] = css;
key = css_set_hash(cset->subsys);
hash_add(css_set_table, &cset->hlist, key);
}
write_unlock(&css_set_lock);
ret = online_css(css);
if (ret)
goto err_unload;
mutex_unlock(&cgroup_mutex);
return 0;
err_unload:
mutex_unlock(&cgroup_mutex);
cgroup_unload_subsys(ss);
return ret;
}
void cgroup_unload_subsys(struct cgroup_subsys *ss)
{
struct cgrp_cset_link *link;
BUG_ON(ss->module == NULL);
BUG_ON(ss->root != &cgroup_dummy_root);
mutex_lock(&cgroup_mutex);
offline_css(cgroup_css(cgroup_dummy_top, ss));
if (ss->use_id)
idr_destroy(&ss->idr);
cgroup_subsys[ss->subsys_id] = NULL;
list_del_init(&ss->sibling);
write_lock(&css_set_lock);
list_for_each_entry(link, &cgroup_dummy_top->cset_links, cset_link) {
struct css_set *cset = link->cset;
unsigned long key;
hash_del(&cset->hlist);
cset->subsys[ss->subsys_id] = NULL;
key = css_set_hash(cset->subsys);
hash_add(css_set_table, &cset->hlist, key);
}
write_unlock(&css_set_lock);
ss->css_free(cgroup_css(cgroup_dummy_top, ss));
RCU_INIT_POINTER(cgroup_dummy_top->subsys[ss->subsys_id], NULL);
mutex_unlock(&cgroup_mutex);
}
int __init cgroup_init_early(void)
{
struct cgroup_subsys *ss;
int i;
atomic_set(&init_css_set.refcount, 1);
INIT_LIST_HEAD(&init_css_set.cgrp_links);
INIT_LIST_HEAD(&init_css_set.tasks);
INIT_HLIST_NODE(&init_css_set.hlist);
css_set_count = 1;
init_cgroup_root(&cgroup_dummy_root);
cgroup_root_count = 1;
RCU_INIT_POINTER(init_task.cgroups, &init_css_set);
init_cgrp_cset_link.cset = &init_css_set;
init_cgrp_cset_link.cgrp = cgroup_dummy_top;
list_add(&init_cgrp_cset_link.cset_link, &cgroup_dummy_top->cset_links);
list_add(&init_cgrp_cset_link.cgrp_link, &init_css_set.cgrp_links);
for_each_builtin_subsys(ss, i) {
BUG_ON(!ss->name);
BUG_ON(strlen(ss->name) > MAX_CGROUP_TYPE_NAMELEN);
BUG_ON(!ss->css_alloc);
BUG_ON(!ss->css_free);
if (ss->subsys_id != i) {
printk(KERN_ERR "cgroup: Subsys %s id == %d\n",
ss->name, ss->subsys_id);
BUG();
}
if (ss->early_init)
cgroup_init_subsys(ss);
}
return 0;
}
int __init cgroup_init(void)
{
struct cgroup_subsys *ss;
unsigned long key;
int i, err;
err = bdi_init(&cgroup_backing_dev_info);
if (err)
return err;
for_each_builtin_subsys(ss, i) {
if (!ss->early_init)
cgroup_init_subsys(ss);
if (ss->use_id)
cgroup_init_idr(ss, init_css_set.subsys[ss->subsys_id]);
}
mutex_lock(&cgroup_mutex);
mutex_lock(&cgroup_root_mutex);
key = css_set_hash(init_css_set.subsys);
hash_add(css_set_table, &init_css_set.hlist, key);
BUG_ON(cgroup_init_root_id(&cgroup_dummy_root, 0, 1));
err = idr_alloc(&cgroup_dummy_root.cgroup_idr, cgroup_dummy_top,
0, 1, GFP_KERNEL);
BUG_ON(err < 0);
mutex_unlock(&cgroup_root_mutex);
mutex_unlock(&cgroup_mutex);
cgroup_kobj = kobject_create_and_add("cgroup", fs_kobj);
if (!cgroup_kobj) {
err = -ENOMEM;
goto out;
}
err = register_filesystem(&cgroup_fs_type);
if (err < 0) {
kobject_put(cgroup_kobj);
goto out;
}
proc_create("cgroups", 0, NULL, &proc_cgroupstats_operations);
out:
if (err)
bdi_destroy(&cgroup_backing_dev_info);
return err;
}
int proc_cgroup_show(struct seq_file *m, void *v)
{
struct pid *pid;
struct task_struct *tsk;
char *buf;
int retval;
struct cgroupfs_root *root;
retval = -ENOMEM;
buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!buf)
goto out;
retval = -ESRCH;
pid = m->private;
tsk = get_pid_task(pid, PIDTYPE_PID);
if (!tsk)
goto out_free;
retval = 0;
mutex_lock(&cgroup_mutex);
for_each_active_root(root) {
struct cgroup_subsys *ss;
struct cgroup *cgrp;
int count = 0;
seq_printf(m, "%d:", root->hierarchy_id);
for_each_root_subsys(root, ss)
seq_printf(m, "%s%s", count++ ? "," : "", ss->name);
if (strlen(root->name))
seq_printf(m, "%sname=%s", count ? "," : "",
root->name);
seq_putc(m, ':');
cgrp = task_cgroup_from_root(tsk, root);
retval = cgroup_path(cgrp, buf, PAGE_SIZE);
if (retval < 0)
goto out_unlock;
seq_puts(m, buf);
seq_putc(m, '\n');
}
out_unlock:
mutex_unlock(&cgroup_mutex);
put_task_struct(tsk);
out_free:
kfree(buf);
out:
return retval;
}
static int proc_cgroupstats_show(struct seq_file *m, void *v)
{
struct cgroup_subsys *ss;
int i;
seq_puts(m, "#subsys_name\thierarchy\tnum_cgroups\tenabled\n");
mutex_lock(&cgroup_mutex);
for_each_subsys(ss, i)
seq_printf(m, "%s\t%d\t%d\t%d\n",
ss->name, ss->root->hierarchy_id,
ss->root->number_of_cgroups, !ss->disabled);
mutex_unlock(&cgroup_mutex);
return 0;
}
static int cgroupstats_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_cgroupstats_show, NULL);
}
void cgroup_fork(struct task_struct *child)
{
task_lock(current);
get_css_set(task_css_set(current));
child->cgroups = current->cgroups;
task_unlock(current);
INIT_LIST_HEAD(&child->cg_list);
}
void cgroup_post_fork(struct task_struct *child)
{
struct cgroup_subsys *ss;
int i;
if (use_task_css_set_links) {
write_lock(&css_set_lock);
task_lock(child);
if (list_empty(&child->cg_list))
list_add(&child->cg_list, &task_css_set(child)->tasks);
task_unlock(child);
write_unlock(&css_set_lock);
}
if (need_forkexit_callback) {
for_each_builtin_subsys(ss, i)
if (ss->fork)
ss->fork(child);
}
}
void cgroup_exit(struct task_struct *tsk, int run_callbacks)
{
struct cgroup_subsys *ss;
struct css_set *cset;
int i;
if (!list_empty(&tsk->cg_list)) {
write_lock(&css_set_lock);
if (!list_empty(&tsk->cg_list))
list_del_init(&tsk->cg_list);
write_unlock(&css_set_lock);
}
task_lock(tsk);
cset = task_css_set(tsk);
RCU_INIT_POINTER(tsk->cgroups, &init_css_set);
if (run_callbacks && need_forkexit_callback) {
for_each_builtin_subsys(ss, i) {
if (ss->exit) {
struct cgroup_subsys_state *old_css = cset->subsys[i];
struct cgroup_subsys_state *css = task_css(tsk, i);
ss->exit(css, old_css, tsk);
}
}
}
task_unlock(tsk);
put_css_set_taskexit(cset);
}
static void check_for_release(struct cgroup *cgrp)
{
if (cgroup_is_releasable(cgrp) &&
list_empty(&cgrp->cset_links) && list_empty(&cgrp->children)) {
int need_schedule_work = 0;
raw_spin_lock(&release_list_lock);
if (!cgroup_is_dead(cgrp) &&
list_empty(&cgrp->release_list)) {
list_add(&cgrp->release_list, &release_list);
need_schedule_work = 1;
}
raw_spin_unlock(&release_list_lock);
if (need_schedule_work)
schedule_work(&release_agent_work);
}
}
static void cgroup_release_agent(struct work_struct *work)
{
BUG_ON(work != &release_agent_work);
mutex_lock(&cgroup_mutex);
raw_spin_lock(&release_list_lock);
while (!list_empty(&release_list)) {
char *argv[3], *envp[3];
int i;
char *pathbuf = NULL, *agentbuf = NULL;
struct cgroup *cgrp = list_entry(release_list.next,
struct cgroup,
release_list);
list_del_init(&cgrp->release_list);
raw_spin_unlock(&release_list_lock);
pathbuf = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!pathbuf)
goto continue_free;
if (cgroup_path(cgrp, pathbuf, PAGE_SIZE) < 0)
goto continue_free;
agentbuf = kstrdup(cgrp->root->release_agent_path, GFP_KERNEL);
if (!agentbuf)
goto continue_free;
i = 0;
argv[i++] = agentbuf;
argv[i++] = pathbuf;
argv[i] = NULL;
i = 0;
envp[i++] = "HOME=/";
envp[i++] = "PATH=/sbin:/bin:/usr/sbin:/usr/bin";
envp[i] = NULL;
mutex_unlock(&cgroup_mutex);
call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
mutex_lock(&cgroup_mutex);
continue_free:
kfree(pathbuf);
kfree(agentbuf);
raw_spin_lock(&release_list_lock);
}
raw_spin_unlock(&release_list_lock);
mutex_unlock(&cgroup_mutex);
}
static int __init cgroup_disable(char *str)
{
struct cgroup_subsys *ss;
char *token;
int i;
while ((token = strsep(&str, ",")) != NULL) {
if (!*token)
continue;
for_each_builtin_subsys(ss, i) {
if (!strcmp(token, ss->name)) {
ss->disabled = 1;
printk(KERN_INFO "Disabling %s control group"
" subsystem\n", ss->name);
break;
}
}
}
return 1;
}
unsigned short css_id(struct cgroup_subsys_state *css)
{
struct css_id *cssid;
cssid = rcu_dereference_raw(css->id);
if (cssid)
return cssid->id;
return 0;
}
bool css_is_ancestor(struct cgroup_subsys_state *child,
const struct cgroup_subsys_state *root)
{
struct css_id *child_id;
struct css_id *root_id;
child_id = rcu_dereference(child->id);
if (!child_id)
return false;
root_id = rcu_dereference(root->id);
if (!root_id)
return false;
if (child_id->depth < root_id->depth)
return false;
if (child_id->stack[root_id->depth] != root_id->id)
return false;
return true;
}
void free_css_id(struct cgroup_subsys *ss, struct cgroup_subsys_state *css)
{
struct css_id *id = rcu_dereference_protected(css->id, true);
if (!id)
return;
BUG_ON(!ss->use_id);
rcu_assign_pointer(id->css, NULL);
rcu_assign_pointer(css->id, NULL);
spin_lock(&ss->id_lock);
idr_remove(&ss->idr, id->id);
spin_unlock(&ss->id_lock);
kfree_rcu(id, rcu_head);
}
static struct css_id *get_new_cssid(struct cgroup_subsys *ss, int depth)
{
struct css_id *newid;
int ret, size;
BUG_ON(!ss->use_id);
size = sizeof(*newid) + sizeof(unsigned short) * (depth + 1);
newid = kzalloc(size, GFP_KERNEL);
if (!newid)
return ERR_PTR(-ENOMEM);
idr_preload(GFP_KERNEL);
spin_lock(&ss->id_lock);
ret = idr_alloc(&ss->idr, newid, 1, CSS_ID_MAX + 1, GFP_NOWAIT);
spin_unlock(&ss->id_lock);
idr_preload_end();
if (ret < 0)
goto err_out;
newid->id = ret;
newid->depth = depth;
return newid;
err_out:
kfree(newid);
return ERR_PTR(ret);
}
static int __init_or_module cgroup_init_idr(struct cgroup_subsys *ss,
struct cgroup_subsys_state *rootcss)
{
struct css_id *newid;
spin_lock_init(&ss->id_lock);
idr_init(&ss->idr);
newid = get_new_cssid(ss, 0);
if (IS_ERR(newid))
return PTR_ERR(newid);
newid->stack[0] = newid->id;
RCU_INIT_POINTER(newid->css, rootcss);
RCU_INIT_POINTER(rootcss->id, newid);
return 0;
}
static int alloc_css_id(struct cgroup_subsys_state *child_css)
{
struct cgroup_subsys_state *parent_css = css_parent(child_css);
struct css_id *child_id, *parent_id;
int i, depth;
parent_id = rcu_dereference_protected(parent_css->id, true);
depth = parent_id->depth + 1;
child_id = get_new_cssid(child_css->ss, depth);
if (IS_ERR(child_id))
return PTR_ERR(child_id);
for (i = 0; i < depth; i++)
child_id->stack[i] = parent_id->stack[i];
child_id->stack[depth] = child_id->id;
rcu_assign_pointer(child_css->id, child_id);
return 0;
}
struct cgroup_subsys_state *css_lookup(struct cgroup_subsys *ss, int id)
{
struct css_id *cssid = NULL;
BUG_ON(!ss->use_id);
cssid = idr_find(&ss->idr, id);
if (unlikely(!cssid))
return NULL;
return rcu_dereference(cssid->css);
}
struct cgroup_subsys_state *css_from_dir(struct dentry *dentry,
struct cgroup_subsys *ss)
{
struct cgroup *cgrp;
WARN_ON_ONCE(!rcu_read_lock_held());
if (!dentry->d_inode ||
dentry->d_inode->i_op != &cgroup_dir_inode_operations)
return ERR_PTR(-EBADF);
cgrp = __d_cgrp(dentry);
return cgroup_css(cgrp, ss) ?: ERR_PTR(-ENOENT);
}
struct cgroup_subsys_state *css_from_id(int id, struct cgroup_subsys *ss)
{
struct cgroup *cgrp;
rcu_lockdep_assert(rcu_read_lock_held() ||
lockdep_is_held(&cgroup_mutex),
"css_from_id() needs proper protection");
cgrp = idr_find(&ss->root->cgroup_idr, id);
if (cgrp)
return cgroup_css(cgrp, ss);
return NULL;
}
static struct cgroup_subsys_state *
debug_css_alloc(struct cgroup_subsys_state *parent_css)
{
struct cgroup_subsys_state *css = kzalloc(sizeof(*css), GFP_KERNEL);
if (!css)
return ERR_PTR(-ENOMEM);
return css;
}
static void debug_css_free(struct cgroup_subsys_state *css)
{
kfree(css);
}
static u64 debug_taskcount_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return cgroup_task_count(css->cgroup);
}
static u64 current_css_set_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return (u64)(unsigned long)current->cgroups;
}
static u64 current_css_set_refcount_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
u64 count;
rcu_read_lock();
count = atomic_read(&task_css_set(current)->refcount);
rcu_read_unlock();
return count;
}
static int current_css_set_cg_links_read(struct cgroup_subsys_state *css,
struct cftype *cft,
struct seq_file *seq)
{
struct cgrp_cset_link *link;
struct css_set *cset;
read_lock(&css_set_lock);
rcu_read_lock();
cset = rcu_dereference(current->cgroups);
list_for_each_entry(link, &cset->cgrp_links, cgrp_link) {
struct cgroup *c = link->cgrp;
const char *name;
if (c->dentry)
name = c->dentry->d_name.name;
else
name = "?";
seq_printf(seq, "Root %d group %s\n",
c->root->hierarchy_id, name);
}
rcu_read_unlock();
read_unlock(&css_set_lock);
return 0;
}
static int cgroup_css_links_read(struct cgroup_subsys_state *css,
struct cftype *cft, struct seq_file *seq)
{
struct cgrp_cset_link *link;
read_lock(&css_set_lock);
list_for_each_entry(link, &css->cgroup->cset_links, cset_link) {
struct css_set *cset = link->cset;
struct task_struct *task;
int count = 0;
seq_printf(seq, "css_set %p\n", cset);
list_for_each_entry(task, &cset->tasks, cg_list) {
if (count++ > MAX_TASKS_SHOWN_PER_CSS) {
seq_puts(seq, " ...\n");
break;
} else {
seq_printf(seq, " task %d\n",
task_pid_vnr(task));
}
}
}
read_unlock(&css_set_lock);
return 0;
}
static u64 releasable_read(struct cgroup_subsys_state *css, struct cftype *cft)
{
return test_bit(CGRP_RELEASABLE, &css->cgroup->flags);
}
