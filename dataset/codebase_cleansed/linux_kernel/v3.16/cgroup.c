static int cgroup_idr_alloc(struct idr *idr, void *ptr, int start, int end,
gfp_t gfp_mask)
{
int ret;
idr_preload(gfp_mask);
spin_lock_bh(&cgroup_idr_lock);
ret = idr_alloc(idr, ptr, start, end, gfp_mask);
spin_unlock_bh(&cgroup_idr_lock);
idr_preload_end();
return ret;
}
static void *cgroup_idr_replace(struct idr *idr, void *ptr, int id)
{
void *ret;
spin_lock_bh(&cgroup_idr_lock);
ret = idr_replace(idr, ptr, id);
spin_unlock_bh(&cgroup_idr_lock);
return ret;
}
static void cgroup_idr_remove(struct idr *idr, int id)
{
spin_lock_bh(&cgroup_idr_lock);
idr_remove(idr, id);
spin_unlock_bh(&cgroup_idr_lock);
}
static struct cgroup *cgroup_parent(struct cgroup *cgrp)
{
struct cgroup_subsys_state *parent_css = cgrp->self.parent;
if (parent_css)
return container_of(parent_css, struct cgroup, self);
return NULL;
}
static struct cgroup_subsys_state *cgroup_css(struct cgroup *cgrp,
struct cgroup_subsys *ss)
{
if (ss)
return rcu_dereference_check(cgrp->subsys[ss->id],
lockdep_is_held(&cgroup_mutex));
else
return &cgrp->self;
}
static struct cgroup_subsys_state *cgroup_e_css(struct cgroup *cgrp,
struct cgroup_subsys *ss)
{
lockdep_assert_held(&cgroup_mutex);
if (!ss)
return &cgrp->self;
if (!(cgrp->root->subsys_mask & (1 << ss->id)))
return NULL;
while (cgroup_parent(cgrp) &&
!(cgroup_parent(cgrp)->child_subsys_mask & (1 << ss->id)))
cgrp = cgroup_parent(cgrp);
return cgroup_css(cgrp, ss);
}
static inline bool cgroup_is_dead(const struct cgroup *cgrp)
{
return !(cgrp->self.flags & CSS_ONLINE);
}
struct cgroup_subsys_state *of_css(struct kernfs_open_file *of)
{
struct cgroup *cgrp = of->kn->parent->priv;
struct cftype *cft = of_cft(of);
if (cft->ss)
return rcu_dereference_raw(cgrp->subsys[cft->ss->id]);
else
return &cgrp->self;
}
bool cgroup_is_descendant(struct cgroup *cgrp, struct cgroup *ancestor)
{
while (cgrp) {
if (cgrp == ancestor)
return true;
cgrp = cgroup_parent(cgrp);
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
static void cgroup_update_populated(struct cgroup *cgrp, bool populated)
{
lockdep_assert_held(&css_set_rwsem);
do {
bool trigger;
if (populated)
trigger = !cgrp->populated_cnt++;
else
trigger = !--cgrp->populated_cnt;
if (!trigger)
break;
if (cgrp->populated_kn)
kernfs_notify(cgrp->populated_kn);
cgrp = cgroup_parent(cgrp);
} while (cgrp);
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
static void put_css_set_locked(struct css_set *cset, bool taskexit)
{
struct cgrp_cset_link *link, *tmp_link;
struct cgroup_subsys *ss;
int ssid;
lockdep_assert_held(&css_set_rwsem);
if (!atomic_dec_and_test(&cset->refcount))
return;
for_each_subsys(ss, ssid)
list_del(&cset->e_cset_node[ssid]);
hash_del(&cset->hlist);
css_set_count--;
list_for_each_entry_safe(link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct cgroup *cgrp = link->cgrp;
list_del(&link->cset_link);
list_del(&link->cgrp_link);
if (list_empty(&cgrp->cset_links)) {
cgroup_update_populated(cgrp, false);
if (notify_on_release(cgrp)) {
if (taskexit)
set_bit(CGRP_RELEASABLE, &cgrp->flags);
check_for_release(cgrp);
}
}
kfree(link);
}
kfree_rcu(cset, rcu_head);
}
static void put_css_set(struct css_set *cset, bool taskexit)
{
if (atomic_add_unless(&cset->refcount, -1, 1))
return;
down_write(&css_set_rwsem);
put_css_set_locked(cset, taskexit);
up_write(&css_set_rwsem);
}
static inline void get_css_set(struct css_set *cset)
{
atomic_inc(&cset->refcount);
}
static bool compare_css_sets(struct css_set *cset,
struct css_set *old_cset,
struct cgroup *new_cgrp,
struct cgroup_subsys_state *template[])
{
struct list_head *l1, *l2;
if (memcmp(template, cset->subsys, sizeof(cset->subsys)))
return false;
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
struct cgroup_root *root = cgrp->root;
struct cgroup_subsys *ss;
struct css_set *cset;
unsigned long key;
int i;
for_each_subsys(ss, i) {
if (root->subsys_mask & (1UL << i)) {
template[i] = cgroup_e_css(cgrp, ss);
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
if (cgroup_on_dfl(cgrp))
cset->dfl_cgrp = cgrp;
link = list_first_entry(tmp_links, struct cgrp_cset_link, cset_link);
link->cset = cset;
link->cgrp = cgrp;
if (list_empty(&cgrp->cset_links))
cgroup_update_populated(cgrp, true);
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
struct cgroup_subsys *ss;
unsigned long key;
int ssid;
lockdep_assert_held(&cgroup_mutex);
down_read(&css_set_rwsem);
cset = find_existing_css_set(old_cset, cgrp, template);
if (cset)
get_css_set(cset);
up_read(&css_set_rwsem);
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
INIT_LIST_HEAD(&cset->mg_tasks);
INIT_LIST_HEAD(&cset->mg_preload_node);
INIT_LIST_HEAD(&cset->mg_node);
INIT_HLIST_NODE(&cset->hlist);
memcpy(cset->subsys, template, sizeof(cset->subsys));
down_write(&css_set_rwsem);
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
for_each_subsys(ss, ssid)
list_add_tail(&cset->e_cset_node[ssid],
&cset->subsys[ssid]->cgroup->e_csets[ssid]);
up_write(&css_set_rwsem);
return cset;
}
static struct cgroup_root *cgroup_root_from_kf(struct kernfs_root *kf_root)
{
struct cgroup *root_cgrp = kf_root->kn->priv;
return root_cgrp->root;
}
static int cgroup_init_root_id(struct cgroup_root *root)
{
int id;
lockdep_assert_held(&cgroup_mutex);
id = idr_alloc_cyclic(&cgroup_hierarchy_idr, root, 0, 0, GFP_KERNEL);
if (id < 0)
return id;
root->hierarchy_id = id;
return 0;
}
static void cgroup_exit_root_id(struct cgroup_root *root)
{
lockdep_assert_held(&cgroup_mutex);
if (root->hierarchy_id) {
idr_remove(&cgroup_hierarchy_idr, root->hierarchy_id);
root->hierarchy_id = 0;
}
}
static void cgroup_free_root(struct cgroup_root *root)
{
if (root) {
WARN_ON_ONCE(root->hierarchy_id);
idr_destroy(&root->cgroup_idr);
kfree(root);
}
}
static void cgroup_destroy_root(struct cgroup_root *root)
{
struct cgroup *cgrp = &root->cgrp;
struct cgrp_cset_link *link, *tmp_link;
mutex_lock(&cgroup_mutex);
BUG_ON(atomic_read(&root->nr_cgrps));
BUG_ON(!list_empty(&cgrp->self.children));
rebind_subsystems(&cgrp_dfl_root, root->subsys_mask);
down_write(&css_set_rwsem);
list_for_each_entry_safe(link, tmp_link, &cgrp->cset_links, cset_link) {
list_del(&link->cset_link);
list_del(&link->cgrp_link);
kfree(link);
}
up_write(&css_set_rwsem);
if (!list_empty(&root->root_list)) {
list_del(&root->root_list);
cgroup_root_count--;
}
cgroup_exit_root_id(root);
mutex_unlock(&cgroup_mutex);
kernfs_destroy_root(root->kf_root);
cgroup_free_root(root);
}
static struct cgroup *cset_cgroup_from_root(struct css_set *cset,
struct cgroup_root *root)
{
struct cgroup *res = NULL;
lockdep_assert_held(&cgroup_mutex);
lockdep_assert_held(&css_set_rwsem);
if (cset == &init_css_set) {
res = &root->cgrp;
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
BUG_ON(!res);
return res;
}
static struct cgroup *task_cgroup_from_root(struct task_struct *task,
struct cgroup_root *root)
{
return cset_cgroup_from_root(task_css_set(task), root);
}
static char *cgroup_file_name(struct cgroup *cgrp, const struct cftype *cft,
char *buf)
{
if (cft->ss && !(cft->flags & CFTYPE_NO_PREFIX) &&
!(cgrp->root->flags & CGRP_ROOT_NOPREFIX))
snprintf(buf, CGROUP_FILE_NAME_MAX, "%s.%s",
cft->ss->name, cft->name);
else
strncpy(buf, cft->name, CGROUP_FILE_NAME_MAX);
return buf;
}
static umode_t cgroup_file_mode(const struct cftype *cft)
{
umode_t mode = 0;
if (cft->mode)
return cft->mode;
if (cft->read_u64 || cft->read_s64 || cft->seq_show)
mode |= S_IRUGO;
if (cft->write_u64 || cft->write_s64 || cft->write)
mode |= S_IWUSR;
return mode;
}
static void cgroup_get(struct cgroup *cgrp)
{
WARN_ON_ONCE(cgroup_is_dead(cgrp));
css_get(&cgrp->self);
}
static void cgroup_put(struct cgroup *cgrp)
{
css_put(&cgrp->self);
}
static void cgroup_kn_unlock(struct kernfs_node *kn)
{
struct cgroup *cgrp;
if (kernfs_type(kn) == KERNFS_DIR)
cgrp = kn->priv;
else
cgrp = kn->parent->priv;
mutex_unlock(&cgroup_mutex);
kernfs_unbreak_active_protection(kn);
cgroup_put(cgrp);
}
static struct cgroup *cgroup_kn_lock_live(struct kernfs_node *kn)
{
struct cgroup *cgrp;
if (kernfs_type(kn) == KERNFS_DIR)
cgrp = kn->priv;
else
cgrp = kn->parent->priv;
cgroup_get(cgrp);
kernfs_break_active_protection(kn);
mutex_lock(&cgroup_mutex);
if (!cgroup_is_dead(cgrp))
return cgrp;
cgroup_kn_unlock(kn);
return NULL;
}
static void cgroup_rm_file(struct cgroup *cgrp, const struct cftype *cft)
{
char name[CGROUP_FILE_NAME_MAX];
lockdep_assert_held(&cgroup_mutex);
kernfs_remove_by_name(cgrp->kn, cgroup_file_name(cgrp, cft, name));
}
static void cgroup_clear_dir(struct cgroup *cgrp, unsigned int subsys_mask)
{
struct cgroup_subsys *ss;
int i;
for_each_subsys(ss, i) {
struct cftype *cfts;
if (!(subsys_mask & (1 << i)))
continue;
list_for_each_entry(cfts, &ss->cfts, node)
cgroup_addrm_files(cgrp, cfts, false);
}
}
static int rebind_subsystems(struct cgroup_root *dst_root, unsigned int ss_mask)
{
struct cgroup_subsys *ss;
unsigned int tmp_ss_mask;
int ssid, i, ret;
lockdep_assert_held(&cgroup_mutex);
for_each_subsys(ss, ssid) {
if (!(ss_mask & (1 << ssid)))
continue;
if (css_next_child(NULL, cgroup_css(&ss->root->cgrp, ss)))
return -EBUSY;
if (ss->root != &cgrp_dfl_root && dst_root != &cgrp_dfl_root)
return -EBUSY;
}
tmp_ss_mask = ss_mask;
if (dst_root == &cgrp_dfl_root)
tmp_ss_mask &= ~cgrp_dfl_root_inhibit_ss_mask;
ret = cgroup_populate_dir(&dst_root->cgrp, tmp_ss_mask);
if (ret) {
if (dst_root != &cgrp_dfl_root)
return ret;
if (cgrp_dfl_root_visible) {
pr_warn("failed to create files (%d) while rebinding 0x%x to default root\n",
ret, ss_mask);
pr_warn("you may retry by moving them to a different hierarchy and unbinding\n");
}
}
for_each_subsys(ss, ssid)
if (ss_mask & (1 << ssid))
cgroup_clear_dir(&ss->root->cgrp, 1 << ssid);
for_each_subsys(ss, ssid) {
struct cgroup_root *src_root;
struct cgroup_subsys_state *css;
struct css_set *cset;
if (!(ss_mask & (1 << ssid)))
continue;
src_root = ss->root;
css = cgroup_css(&src_root->cgrp, ss);
WARN_ON(!css || cgroup_css(&dst_root->cgrp, ss));
RCU_INIT_POINTER(src_root->cgrp.subsys[ssid], NULL);
rcu_assign_pointer(dst_root->cgrp.subsys[ssid], css);
ss->root = dst_root;
css->cgroup = &dst_root->cgrp;
down_write(&css_set_rwsem);
hash_for_each(css_set_table, i, cset, hlist)
list_move_tail(&cset->e_cset_node[ss->id],
&dst_root->cgrp.e_csets[ss->id]);
up_write(&css_set_rwsem);
src_root->subsys_mask &= ~(1 << ssid);
src_root->cgrp.child_subsys_mask &= ~(1 << ssid);
dst_root->subsys_mask |= 1 << ssid;
if (dst_root != &cgrp_dfl_root)
dst_root->cgrp.child_subsys_mask |= 1 << ssid;
if (ss->bind)
ss->bind(css);
}
kernfs_activate(dst_root->cgrp.kn);
return 0;
}
static int cgroup_show_options(struct seq_file *seq,
struct kernfs_root *kf_root)
{
struct cgroup_root *root = cgroup_root_from_kf(kf_root);
struct cgroup_subsys *ss;
int ssid;
for_each_subsys(ss, ssid)
if (root->subsys_mask & (1 << ssid))
seq_printf(seq, ",%s", ss->name);
if (root->flags & CGRP_ROOT_SANE_BEHAVIOR)
seq_puts(seq, ",sane_behavior");
if (root->flags & CGRP_ROOT_NOPREFIX)
seq_puts(seq, ",noprefix");
if (root->flags & CGRP_ROOT_XATTR)
seq_puts(seq, ",xattr");
spin_lock(&release_agent_path_lock);
if (strlen(root->release_agent_path))
seq_printf(seq, ",release_agent=%s", root->release_agent_path);
spin_unlock(&release_agent_path_lock);
if (test_bit(CGRP_CPUSET_CLONE_CHILDREN, &root->cgrp.flags))
seq_puts(seq, ",clone_children");
if (strlen(root->name))
seq_printf(seq, ",name=%s", root->name);
return 0;
}
static int parse_cgroupfs_options(char *data, struct cgroup_sb_opts *opts)
{
char *token, *o = data;
bool all_ss = false, one_ss = false;
unsigned int mask = -1U;
struct cgroup_subsys *ss;
int i;
#ifdef CONFIG_CPUSETS
mask = ~(1U << cpuset_cgrp_id);
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
opts->subsys_mask |= (1 << i);
one_ss = true;
break;
}
if (i == CGROUP_SUBSYS_COUNT)
return -ENOENT;
}
if (opts->flags & CGRP_ROOT_SANE_BEHAVIOR) {
pr_warn("sane_behavior: this is still under development and its behaviors will change, proceed at your own risk\n");
if ((opts->flags & (CGRP_ROOT_NOPREFIX | CGRP_ROOT_XATTR)) ||
opts->cpuset_clone_children || opts->release_agent ||
opts->name) {
pr_err("sane_behavior: noprefix, xattr, clone_children, release_agent and name are not allowed\n");
return -EINVAL;
}
} else {
if (all_ss || (!one_ss && !opts->none && !opts->name))
for_each_subsys(ss, i)
if (!ss->disabled)
opts->subsys_mask |= (1 << i);
if (!opts->subsys_mask && !opts->name)
return -EINVAL;
}
if ((opts->flags & CGRP_ROOT_NOPREFIX) && (opts->subsys_mask & mask))
return -EINVAL;
if (opts->subsys_mask && opts->none)
return -EINVAL;
return 0;
}
static int cgroup_remount(struct kernfs_root *kf_root, int *flags, char *data)
{
int ret = 0;
struct cgroup_root *root = cgroup_root_from_kf(kf_root);
struct cgroup_sb_opts opts;
unsigned int added_mask, removed_mask;
if (root->flags & CGRP_ROOT_SANE_BEHAVIOR) {
pr_err("sane_behavior: remount is not allowed\n");
return -EINVAL;
}
mutex_lock(&cgroup_mutex);
ret = parse_cgroupfs_options(data, &opts);
if (ret)
goto out_unlock;
if (opts.subsys_mask != root->subsys_mask || opts.release_agent)
pr_warn("option changes via remount are deprecated (pid=%d comm=%s)\n",
task_tgid_nr(current), current->comm);
added_mask = opts.subsys_mask & ~root->subsys_mask;
removed_mask = root->subsys_mask & ~opts.subsys_mask;
if (((opts.flags ^ root->flags) & CGRP_ROOT_OPTION_MASK) ||
(opts.name && strcmp(opts.name, root->name))) {
pr_err("option or name mismatch, new: 0x%x \"%s\", old: 0x%x \"%s\"\n",
opts.flags & CGRP_ROOT_OPTION_MASK, opts.name ?: "",
root->flags & CGRP_ROOT_OPTION_MASK, root->name);
ret = -EINVAL;
goto out_unlock;
}
if (!list_empty(&root->cgrp.self.children)) {
ret = -EBUSY;
goto out_unlock;
}
ret = rebind_subsystems(root, added_mask);
if (ret)
goto out_unlock;
rebind_subsystems(&cgrp_dfl_root, removed_mask);
if (opts.release_agent) {
spin_lock(&release_agent_path_lock);
strcpy(root->release_agent_path, opts.release_agent);
spin_unlock(&release_agent_path_lock);
}
out_unlock:
kfree(opts.release_agent);
kfree(opts.name);
mutex_unlock(&cgroup_mutex);
return ret;
}
static void cgroup_enable_task_cg_lists(void)
{
struct task_struct *p, *g;
down_write(&css_set_rwsem);
if (use_task_css_set_links)
goto out_unlock;
use_task_css_set_links = true;
read_lock(&tasklist_lock);
do_each_thread(g, p) {
WARN_ON_ONCE(!list_empty(&p->cg_list) ||
task_css_set(p) != &init_css_set);
spin_lock_irq(&p->sighand->siglock);
if (!(p->flags & PF_EXITING)) {
struct css_set *cset = task_css_set(p);
list_add(&p->cg_list, &cset->tasks);
get_css_set(cset);
}
spin_unlock_irq(&p->sighand->siglock);
} while_each_thread(g, p);
read_unlock(&tasklist_lock);
out_unlock:
up_write(&css_set_rwsem);
}
static void init_cgroup_housekeeping(struct cgroup *cgrp)
{
struct cgroup_subsys *ss;
int ssid;
INIT_LIST_HEAD(&cgrp->self.sibling);
INIT_LIST_HEAD(&cgrp->self.children);
INIT_LIST_HEAD(&cgrp->cset_links);
INIT_LIST_HEAD(&cgrp->release_list);
INIT_LIST_HEAD(&cgrp->pidlists);
mutex_init(&cgrp->pidlist_mutex);
cgrp->self.cgroup = cgrp;
cgrp->self.flags |= CSS_ONLINE;
for_each_subsys(ss, ssid)
INIT_LIST_HEAD(&cgrp->e_csets[ssid]);
init_waitqueue_head(&cgrp->offline_waitq);
}
static void init_cgroup_root(struct cgroup_root *root,
struct cgroup_sb_opts *opts)
{
struct cgroup *cgrp = &root->cgrp;
INIT_LIST_HEAD(&root->root_list);
atomic_set(&root->nr_cgrps, 1);
cgrp->root = root;
init_cgroup_housekeeping(cgrp);
idr_init(&root->cgroup_idr);
root->flags = opts->flags;
if (opts->release_agent)
strcpy(root->release_agent_path, opts->release_agent);
if (opts->name)
strcpy(root->name, opts->name);
if (opts->cpuset_clone_children)
set_bit(CGRP_CPUSET_CLONE_CHILDREN, &root->cgrp.flags);
}
static int cgroup_setup_root(struct cgroup_root *root, unsigned int ss_mask)
{
LIST_HEAD(tmp_links);
struct cgroup *root_cgrp = &root->cgrp;
struct css_set *cset;
int i, ret;
lockdep_assert_held(&cgroup_mutex);
ret = cgroup_idr_alloc(&root->cgroup_idr, root_cgrp, 1, 2, GFP_NOWAIT);
if (ret < 0)
goto out;
root_cgrp->id = ret;
ret = percpu_ref_init(&root_cgrp->self.refcnt, css_release);
if (ret)
goto out;
ret = allocate_cgrp_cset_links(css_set_count, &tmp_links);
if (ret)
goto cancel_ref;
ret = cgroup_init_root_id(root);
if (ret)
goto cancel_ref;
root->kf_root = kernfs_create_root(&cgroup_kf_syscall_ops,
KERNFS_ROOT_CREATE_DEACTIVATED,
root_cgrp);
if (IS_ERR(root->kf_root)) {
ret = PTR_ERR(root->kf_root);
goto exit_root_id;
}
root_cgrp->kn = root->kf_root->kn;
ret = cgroup_addrm_files(root_cgrp, cgroup_base_files, true);
if (ret)
goto destroy_root;
ret = rebind_subsystems(root, ss_mask);
if (ret)
goto destroy_root;
list_add(&root->root_list, &cgroup_roots);
cgroup_root_count++;
down_write(&css_set_rwsem);
hash_for_each(css_set_table, i, cset, hlist)
link_css_set(&tmp_links, cset, root_cgrp);
up_write(&css_set_rwsem);
BUG_ON(!list_empty(&root_cgrp->self.children));
BUG_ON(atomic_read(&root->nr_cgrps) != 1);
kernfs_activate(root_cgrp->kn);
ret = 0;
goto out;
destroy_root:
kernfs_destroy_root(root->kf_root);
root->kf_root = NULL;
exit_root_id:
cgroup_exit_root_id(root);
cancel_ref:
percpu_ref_cancel_init(&root_cgrp->self.refcnt);
out:
free_cgrp_cset_links(&tmp_links);
return ret;
}
static struct dentry *cgroup_mount(struct file_system_type *fs_type,
int flags, const char *unused_dev_name,
void *data)
{
struct super_block *pinned_sb = NULL;
struct cgroup_subsys *ss;
struct cgroup_root *root;
struct cgroup_sb_opts opts;
struct dentry *dentry;
int ret;
int i;
bool new_sb;
if (!use_task_css_set_links)
cgroup_enable_task_cg_lists();
mutex_lock(&cgroup_mutex);
ret = parse_cgroupfs_options(data, &opts);
if (ret)
goto out_unlock;
if (!opts.subsys_mask && !opts.none && !opts.name) {
cgrp_dfl_root_visible = true;
root = &cgrp_dfl_root;
cgroup_get(&root->cgrp);
ret = 0;
goto out_unlock;
}
for_each_subsys(ss, i) {
if (!(opts.subsys_mask & (1 << i)) ||
ss->root == &cgrp_dfl_root)
continue;
if (!percpu_ref_tryget_live(&ss->root->cgrp.self.refcnt)) {
mutex_unlock(&cgroup_mutex);
msleep(10);
ret = restart_syscall();
goto out_free;
}
cgroup_put(&ss->root->cgrp);
}
for_each_root(root) {
bool name_match = false;
if (root == &cgrp_dfl_root)
continue;
if (opts.name) {
if (strcmp(opts.name, root->name))
continue;
name_match = true;
}
if ((opts.subsys_mask || opts.none) &&
(opts.subsys_mask != root->subsys_mask)) {
if (!name_match)
continue;
ret = -EBUSY;
goto out_unlock;
}
if ((root->flags ^ opts.flags) & CGRP_ROOT_OPTION_MASK) {
if ((root->flags | opts.flags) & CGRP_ROOT_SANE_BEHAVIOR) {
pr_err("sane_behavior: new mount options should match the existing superblock\n");
ret = -EINVAL;
goto out_unlock;
} else {
pr_warn("new mount options do not match the existing superblock, will be ignored\n");
}
}
pinned_sb = kernfs_pin_sb(root->kf_root, NULL);
if (IS_ERR(pinned_sb) ||
!percpu_ref_tryget_live(&root->cgrp.self.refcnt)) {
mutex_unlock(&cgroup_mutex);
if (!IS_ERR_OR_NULL(pinned_sb))
deactivate_super(pinned_sb);
msleep(10);
ret = restart_syscall();
goto out_free;
}
ret = 0;
goto out_unlock;
}
if (!opts.subsys_mask && !opts.none) {
ret = -EINVAL;
goto out_unlock;
}
root = kzalloc(sizeof(*root), GFP_KERNEL);
if (!root) {
ret = -ENOMEM;
goto out_unlock;
}
init_cgroup_root(root, &opts);
ret = cgroup_setup_root(root, opts.subsys_mask);
if (ret)
cgroup_free_root(root);
out_unlock:
mutex_unlock(&cgroup_mutex);
out_free:
kfree(opts.release_agent);
kfree(opts.name);
if (ret)
return ERR_PTR(ret);
dentry = kernfs_mount(fs_type, flags, root->kf_root,
CGROUP_SUPER_MAGIC, &new_sb);
if (IS_ERR(dentry) || !new_sb)
cgroup_put(&root->cgrp);
if (pinned_sb) {
WARN_ON(new_sb);
deactivate_super(pinned_sb);
}
return dentry;
}
static void cgroup_kill_sb(struct super_block *sb)
{
struct kernfs_root *kf_root = kernfs_root_from_sb(sb);
struct cgroup_root *root = cgroup_root_from_kf(kf_root);
if (css_has_online_children(&root->cgrp.self) ||
root == &cgrp_dfl_root)
cgroup_put(&root->cgrp);
else
percpu_ref_kill(&root->cgrp.self.refcnt);
kernfs_kill_sb(sb);
}
char *task_cgroup_path(struct task_struct *task, char *buf, size_t buflen)
{
struct cgroup_root *root;
struct cgroup *cgrp;
int hierarchy_id = 1;
char *path = NULL;
mutex_lock(&cgroup_mutex);
down_read(&css_set_rwsem);
root = idr_get_next(&cgroup_hierarchy_idr, &hierarchy_id);
if (root) {
cgrp = task_cgroup_from_root(task, root);
path = cgroup_path(cgrp, buf, buflen);
} else {
if (strlcpy(buf, "/", buflen) < buflen)
path = buf;
}
up_read(&css_set_rwsem);
mutex_unlock(&cgroup_mutex);
return path;
}
struct task_struct *cgroup_taskset_first(struct cgroup_taskset *tset)
{
tset->cur_cset = list_first_entry(tset->csets, struct css_set, mg_node);
tset->cur_task = NULL;
return cgroup_taskset_next(tset);
}
struct task_struct *cgroup_taskset_next(struct cgroup_taskset *tset)
{
struct css_set *cset = tset->cur_cset;
struct task_struct *task = tset->cur_task;
while (&cset->mg_node != tset->csets) {
if (!task)
task = list_first_entry(&cset->mg_tasks,
struct task_struct, cg_list);
else
task = list_next_entry(task, cg_list);
if (&task->cg_list != &cset->mg_tasks) {
tset->cur_cset = cset;
tset->cur_task = task;
return task;
}
cset = list_next_entry(cset, mg_node);
task = NULL;
}
return NULL;
}
static void cgroup_task_migrate(struct cgroup *old_cgrp,
struct task_struct *tsk,
struct css_set *new_cset)
{
struct css_set *old_cset;
lockdep_assert_held(&cgroup_mutex);
lockdep_assert_held(&css_set_rwsem);
WARN_ON_ONCE(tsk->flags & PF_EXITING);
old_cset = task_css_set(tsk);
get_css_set(new_cset);
rcu_assign_pointer(tsk->cgroups, new_cset);
list_move_tail(&tsk->cg_list, &new_cset->mg_tasks);
set_bit(CGRP_RELEASABLE, &old_cgrp->flags);
put_css_set_locked(old_cset, false);
}
static void cgroup_migrate_finish(struct list_head *preloaded_csets)
{
struct css_set *cset, *tmp_cset;
lockdep_assert_held(&cgroup_mutex);
down_write(&css_set_rwsem);
list_for_each_entry_safe(cset, tmp_cset, preloaded_csets, mg_preload_node) {
cset->mg_src_cgrp = NULL;
cset->mg_dst_cset = NULL;
list_del_init(&cset->mg_preload_node);
put_css_set_locked(cset, false);
}
up_write(&css_set_rwsem);
}
static void cgroup_migrate_add_src(struct css_set *src_cset,
struct cgroup *dst_cgrp,
struct list_head *preloaded_csets)
{
struct cgroup *src_cgrp;
lockdep_assert_held(&cgroup_mutex);
lockdep_assert_held(&css_set_rwsem);
src_cgrp = cset_cgroup_from_root(src_cset, dst_cgrp->root);
if (!list_empty(&src_cset->mg_preload_node))
return;
WARN_ON(src_cset->mg_src_cgrp);
WARN_ON(!list_empty(&src_cset->mg_tasks));
WARN_ON(!list_empty(&src_cset->mg_node));
src_cset->mg_src_cgrp = src_cgrp;
get_css_set(src_cset);
list_add(&src_cset->mg_preload_node, preloaded_csets);
}
static int cgroup_migrate_prepare_dst(struct cgroup *dst_cgrp,
struct list_head *preloaded_csets)
{
LIST_HEAD(csets);
struct css_set *src_cset, *tmp_cset;
lockdep_assert_held(&cgroup_mutex);
if (dst_cgrp && cgroup_on_dfl(dst_cgrp) && cgroup_parent(dst_cgrp) &&
dst_cgrp->child_subsys_mask)
return -EBUSY;
list_for_each_entry_safe(src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct css_set *dst_cset;
dst_cset = find_css_set(src_cset,
dst_cgrp ?: src_cset->dfl_cgrp);
if (!dst_cset)
goto err;
WARN_ON_ONCE(src_cset->mg_dst_cset || dst_cset->mg_dst_cset);
if (src_cset == dst_cset) {
src_cset->mg_src_cgrp = NULL;
list_del_init(&src_cset->mg_preload_node);
put_css_set(src_cset, false);
put_css_set(dst_cset, false);
continue;
}
src_cset->mg_dst_cset = dst_cset;
if (list_empty(&dst_cset->mg_preload_node))
list_add(&dst_cset->mg_preload_node, &csets);
else
put_css_set(dst_cset, false);
}
list_splice_tail(&csets, preloaded_csets);
return 0;
err:
cgroup_migrate_finish(&csets);
return -ENOMEM;
}
static int cgroup_migrate(struct cgroup *cgrp, struct task_struct *leader,
bool threadgroup)
{
struct cgroup_taskset tset = {
.src_csets = LIST_HEAD_INIT(tset.src_csets),
.dst_csets = LIST_HEAD_INIT(tset.dst_csets),
.csets = &tset.src_csets,
};
struct cgroup_subsys_state *css, *failed_css = NULL;
struct css_set *cset, *tmp_cset;
struct task_struct *task, *tmp_task;
int i, ret;
down_write(&css_set_rwsem);
rcu_read_lock();
task = leader;
do {
if (task->flags & PF_EXITING)
goto next;
if (list_empty(&task->cg_list))
goto next;
cset = task_css_set(task);
if (!cset->mg_src_cgrp)
goto next;
list_move_tail(&task->cg_list, &cset->mg_tasks);
if (list_empty(&cset->mg_node))
list_add_tail(&cset->mg_node, &tset.src_csets);
if (list_empty(&cset->mg_dst_cset->mg_node))
list_move_tail(&cset->mg_dst_cset->mg_node,
&tset.dst_csets);
next:
if (!threadgroup)
break;
} while_each_thread(leader, task);
int cgroup_attach_task(struct cgroup *dst_cgrp,
struct task_struct *leader, bool threadgroup)
{
LIST_HEAD(preloaded_csets);
struct task_struct *task;
int ret;
down_read(&css_set_rwsem);
rcu_read_lock();
task = leader;
do {
cgroup_migrate_add_src(task_css_set(task), dst_cgrp,
&preloaded_csets);
if (!threadgroup)
break;
} while_each_thread(leader, task);
ssize_t __cgroup_procs_write(struct kernfs_open_file *of, char *buf,
size_t nbytes, loff_t off, bool threadgroup)
{
struct task_struct *tsk;
const struct cred *cred = current_cred(), *tcred;
struct cgroup *cgrp;
pid_t pid;
int ret;
if (kstrtoint(strstrip(buf), 0, &pid) || pid < 0)
return -EINVAL;
cgrp = cgroup_kn_lock_live(of->kn);
if (!cgrp)
return -ENODEV;
retry_find_task:
rcu_read_lock();
if (pid) {
tsk = find_task_by_vpid(pid);
if (!tsk) {
rcu_read_unlock();
ret = -ESRCH;
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
cgroup_kn_unlock(of->kn);
return ret ?: nbytes;
}
int cgroup_attach_task_all(struct task_struct *from, struct task_struct *tsk)
{
struct cgroup_root *root;
int retval = 0;
mutex_lock(&cgroup_mutex);
for_each_root(root) {
struct cgroup *from_cgrp;
if (root == &cgrp_dfl_root)
continue;
down_read(&css_set_rwsem);
from_cgrp = task_cgroup_from_root(from, root);
up_read(&css_set_rwsem);
retval = cgroup_attach_task(from_cgrp, tsk, false);
if (retval)
break;
}
mutex_unlock(&cgroup_mutex);
return retval;
}
static ssize_t cgroup_tasks_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
return __cgroup_procs_write(of, buf, nbytes, off, false);
}
static ssize_t cgroup_procs_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
return __cgroup_procs_write(of, buf, nbytes, off, true);
}
static ssize_t cgroup_release_agent_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct cgroup *cgrp;
BUILD_BUG_ON(sizeof(cgrp->root->release_agent_path) < PATH_MAX);
cgrp = cgroup_kn_lock_live(of->kn);
if (!cgrp)
return -ENODEV;
spin_lock(&release_agent_path_lock);
strlcpy(cgrp->root->release_agent_path, strstrip(buf),
sizeof(cgrp->root->release_agent_path));
spin_unlock(&release_agent_path_lock);
cgroup_kn_unlock(of->kn);
return nbytes;
}
static int cgroup_release_agent_show(struct seq_file *seq, void *v)
{
struct cgroup *cgrp = seq_css(seq)->cgroup;
spin_lock(&release_agent_path_lock);
seq_puts(seq, cgrp->root->release_agent_path);
spin_unlock(&release_agent_path_lock);
seq_putc(seq, '\n');
return 0;
}
static int cgroup_sane_behavior_show(struct seq_file *seq, void *v)
{
struct cgroup *cgrp = seq_css(seq)->cgroup;
seq_printf(seq, "%d\n", cgroup_sane_behavior(cgrp));
return 0;
}
static void cgroup_print_ss_mask(struct seq_file *seq, unsigned int ss_mask)
{
struct cgroup_subsys *ss;
bool printed = false;
int ssid;
for_each_subsys(ss, ssid) {
if (ss_mask & (1 << ssid)) {
if (printed)
seq_putc(seq, ' ');
seq_printf(seq, "%s", ss->name);
printed = true;
}
}
if (printed)
seq_putc(seq, '\n');
}
static int cgroup_root_controllers_show(struct seq_file *seq, void *v)
{
struct cgroup *cgrp = seq_css(seq)->cgroup;
cgroup_print_ss_mask(seq, cgrp->root->subsys_mask &
~cgrp_dfl_root_inhibit_ss_mask);
return 0;
}
static int cgroup_controllers_show(struct seq_file *seq, void *v)
{
struct cgroup *cgrp = seq_css(seq)->cgroup;
cgroup_print_ss_mask(seq, cgroup_parent(cgrp)->child_subsys_mask);
return 0;
}
static int cgroup_subtree_control_show(struct seq_file *seq, void *v)
{
struct cgroup *cgrp = seq_css(seq)->cgroup;
cgroup_print_ss_mask(seq, cgrp->child_subsys_mask);
return 0;
}
static int cgroup_update_dfl_csses(struct cgroup *cgrp)
{
LIST_HEAD(preloaded_csets);
struct cgroup_subsys_state *css;
struct css_set *src_cset;
int ret;
lockdep_assert_held(&cgroup_mutex);
down_read(&css_set_rwsem);
css_for_each_descendant_pre(css, cgroup_css(cgrp, NULL)) {
struct cgrp_cset_link *link;
if (css->cgroup == cgrp)
continue;
list_for_each_entry(link, &css->cgroup->cset_links, cset_link)
cgroup_migrate_add_src(link->cset, cgrp,
&preloaded_csets);
}
up_read(&css_set_rwsem);
ret = cgroup_migrate_prepare_dst(NULL, &preloaded_csets);
if (ret)
goto out_finish;
list_for_each_entry(src_cset, &preloaded_csets, mg_preload_node) {
struct task_struct *last_task = NULL, *task;
if (!src_cset->mg_src_cgrp)
break;
while (true) {
down_read(&css_set_rwsem);
task = list_first_entry_or_null(&src_cset->tasks,
struct task_struct, cg_list);
if (task) {
task = task->group_leader;
WARN_ON_ONCE(!task_css_set(task)->mg_src_cgrp);
get_task_struct(task);
}
up_read(&css_set_rwsem);
if (!task)
break;
if (WARN(last_task == task,
"cgroup: update_dfl_csses failed to make progress, aborting in inconsistent state\n"))
goto out_finish;
last_task = task;
threadgroup_lock(task);
if (!thread_group_leader(task)) {
threadgroup_unlock(task);
put_task_struct(task);
continue;
}
ret = cgroup_migrate(src_cset->dfl_cgrp, task, true);
threadgroup_unlock(task);
put_task_struct(task);
if (WARN(ret, "cgroup: failed to update controllers for the default hierarchy (%d), further operations may crash or hang\n", ret))
goto out_finish;
}
}
out_finish:
cgroup_migrate_finish(&preloaded_csets);
return ret;
}
static ssize_t cgroup_subtree_control_write(struct kernfs_open_file *of,
char *buf, size_t nbytes,
loff_t off)
{
unsigned int enable = 0, disable = 0;
struct cgroup *cgrp, *child;
struct cgroup_subsys *ss;
char *tok;
int ssid, ret;
buf = strstrip(buf);
while ((tok = strsep(&buf, " "))) {
if (tok[0] == '\0')
continue;
for_each_subsys(ss, ssid) {
if (ss->disabled || strcmp(tok + 1, ss->name) ||
((1 << ss->id) & cgrp_dfl_root_inhibit_ss_mask))
continue;
if (*tok == '+') {
enable |= 1 << ssid;
disable &= ~(1 << ssid);
} else if (*tok == '-') {
disable |= 1 << ssid;
enable &= ~(1 << ssid);
} else {
return -EINVAL;
}
break;
}
if (ssid == CGROUP_SUBSYS_COUNT)
return -EINVAL;
}
cgrp = cgroup_kn_lock_live(of->kn);
if (!cgrp)
return -ENODEV;
for_each_subsys(ss, ssid) {
if (enable & (1 << ssid)) {
if (cgrp->child_subsys_mask & (1 << ssid)) {
enable &= ~(1 << ssid);
continue;
}
cgroup_for_each_live_child(child, cgrp) {
DEFINE_WAIT(wait);
if (!cgroup_css(child, ss))
continue;
cgroup_get(child);
prepare_to_wait(&child->offline_waitq, &wait,
TASK_UNINTERRUPTIBLE);
cgroup_kn_unlock(of->kn);
schedule();
finish_wait(&child->offline_waitq, &wait);
cgroup_put(child);
return restart_syscall();
}
if (!(cgrp_dfl_root.subsys_mask & (1 << ssid)) ||
(cgroup_parent(cgrp) &&
!(cgroup_parent(cgrp)->child_subsys_mask & (1 << ssid)))) {
ret = -ENOENT;
goto out_unlock;
}
} else if (disable & (1 << ssid)) {
if (!(cgrp->child_subsys_mask & (1 << ssid))) {
disable &= ~(1 << ssid);
continue;
}
cgroup_for_each_live_child(child, cgrp) {
if (child->child_subsys_mask & (1 << ssid)) {
ret = -EBUSY;
goto out_unlock;
}
}
}
}
if (!enable && !disable) {
ret = 0;
goto out_unlock;
}
if (enable && cgroup_parent(cgrp) && !list_empty(&cgrp->cset_links)) {
ret = -EBUSY;
goto out_unlock;
}
for_each_subsys(ss, ssid) {
if (!(enable & (1 << ssid)))
continue;
cgroup_for_each_live_child(child, cgrp) {
ret = create_css(child, ss);
if (ret)
goto err_undo_css;
}
}
cgrp->child_subsys_mask |= enable;
cgrp->child_subsys_mask &= ~disable;
ret = cgroup_update_dfl_csses(cgrp);
if (ret)
goto err_undo_css;
for_each_subsys(ss, ssid) {
if (!(disable & (1 << ssid)))
continue;
cgroup_for_each_live_child(child, cgrp)
kill_css(cgroup_css(child, ss));
}
kernfs_activate(cgrp->kn);
ret = 0;
out_unlock:
cgroup_kn_unlock(of->kn);
return ret ?: nbytes;
err_undo_css:
cgrp->child_subsys_mask &= ~enable;
cgrp->child_subsys_mask |= disable;
for_each_subsys(ss, ssid) {
if (!(enable & (1 << ssid)))
continue;
cgroup_for_each_live_child(child, cgrp) {
struct cgroup_subsys_state *css = cgroup_css(child, ss);
if (css)
kill_css(css);
}
}
goto out_unlock;
}
static int cgroup_populated_show(struct seq_file *seq, void *v)
{
seq_printf(seq, "%d\n", (bool)seq_css(seq)->cgroup->populated_cnt);
return 0;
}
static ssize_t cgroup_file_write(struct kernfs_open_file *of, char *buf,
size_t nbytes, loff_t off)
{
struct cgroup *cgrp = of->kn->parent->priv;
struct cftype *cft = of->kn->priv;
struct cgroup_subsys_state *css;
int ret;
if (cft->write)
return cft->write(of, buf, nbytes, off);
rcu_read_lock();
css = cgroup_css(cgrp, cft->ss);
rcu_read_unlock();
if (cft->write_u64) {
unsigned long long v;
ret = kstrtoull(buf, 0, &v);
if (!ret)
ret = cft->write_u64(css, cft, v);
} else if (cft->write_s64) {
long long v;
ret = kstrtoll(buf, 0, &v);
if (!ret)
ret = cft->write_s64(css, cft, v);
} else {
ret = -EINVAL;
}
return ret ?: nbytes;
}
static void *cgroup_seqfile_start(struct seq_file *seq, loff_t *ppos)
{
return seq_cft(seq)->seq_start(seq, ppos);
}
static void *cgroup_seqfile_next(struct seq_file *seq, void *v, loff_t *ppos)
{
return seq_cft(seq)->seq_next(seq, v, ppos);
}
static void cgroup_seqfile_stop(struct seq_file *seq, void *v)
{
seq_cft(seq)->seq_stop(seq, v);
}
static int cgroup_seqfile_show(struct seq_file *m, void *arg)
{
struct cftype *cft = seq_cft(m);
struct cgroup_subsys_state *css = seq_css(m);
if (cft->seq_show)
return cft->seq_show(m, arg);
if (cft->read_u64)
seq_printf(m, "%llu\n", cft->read_u64(css, cft));
else if (cft->read_s64)
seq_printf(m, "%lld\n", cft->read_s64(css, cft));
else
return -EINVAL;
return 0;
}
static int cgroup_rename(struct kernfs_node *kn, struct kernfs_node *new_parent,
const char *new_name_str)
{
struct cgroup *cgrp = kn->priv;
int ret;
if (kernfs_type(kn) != KERNFS_DIR)
return -ENOTDIR;
if (kn->parent != new_parent)
return -EIO;
if (cgroup_sane_behavior(cgrp))
return -EPERM;
kernfs_break_active_protection(new_parent);
kernfs_break_active_protection(kn);
mutex_lock(&cgroup_mutex);
ret = kernfs_rename(kn, new_parent, new_name_str);
mutex_unlock(&cgroup_mutex);
kernfs_unbreak_active_protection(kn);
kernfs_unbreak_active_protection(new_parent);
return ret;
}
static int cgroup_kn_set_ugid(struct kernfs_node *kn)
{
struct iattr iattr = { .ia_valid = ATTR_UID | ATTR_GID,
.ia_uid = current_fsuid(),
.ia_gid = current_fsgid(), };
if (uid_eq(iattr.ia_uid, GLOBAL_ROOT_UID) &&
gid_eq(iattr.ia_gid, GLOBAL_ROOT_GID))
return 0;
return kernfs_setattr(kn, &iattr);
}
static int cgroup_add_file(struct cgroup *cgrp, struct cftype *cft)
{
char name[CGROUP_FILE_NAME_MAX];
struct kernfs_node *kn;
struct lock_class_key *key = NULL;
int ret;
#ifdef CONFIG_DEBUG_LOCK_ALLOC
key = &cft->lockdep_key;
#endif
kn = __kernfs_create_file(cgrp->kn, cgroup_file_name(cgrp, cft, name),
cgroup_file_mode(cft), 0, cft->kf_ops, cft,
NULL, false, key);
if (IS_ERR(kn))
return PTR_ERR(kn);
ret = cgroup_kn_set_ugid(kn);
if (ret) {
kernfs_remove(kn);
return ret;
}
if (cft->seq_show == cgroup_populated_show)
cgrp->populated_kn = kn;
return 0;
}
static int cgroup_addrm_files(struct cgroup *cgrp, struct cftype cfts[],
bool is_add)
{
struct cftype *cft;
int ret;
lockdep_assert_held(&cgroup_mutex);
for (cft = cfts; cft->name[0] != '\0'; cft++) {
if ((cft->flags & CFTYPE_ONLY_ON_DFL) && !cgroup_on_dfl(cgrp))
continue;
if ((cft->flags & CFTYPE_INSANE) && cgroup_sane_behavior(cgrp))
continue;
if ((cft->flags & CFTYPE_NOT_ON_ROOT) && !cgroup_parent(cgrp))
continue;
if ((cft->flags & CFTYPE_ONLY_ON_ROOT) && cgroup_parent(cgrp))
continue;
if (is_add) {
ret = cgroup_add_file(cgrp, cft);
if (ret) {
pr_warn("%s: failed to add %s, err=%d\n",
__func__, cft->name, ret);
return ret;
}
} else {
cgroup_rm_file(cgrp, cft);
}
}
return 0;
}
static int cgroup_apply_cftypes(struct cftype *cfts, bool is_add)
{
LIST_HEAD(pending);
struct cgroup_subsys *ss = cfts[0].ss;
struct cgroup *root = &ss->root->cgrp;
struct cgroup_subsys_state *css;
int ret = 0;
lockdep_assert_held(&cgroup_mutex);
css_for_each_descendant_pre(css, cgroup_css(root, ss)) {
struct cgroup *cgrp = css->cgroup;
if (cgroup_is_dead(cgrp))
continue;
ret = cgroup_addrm_files(cgrp, cfts, is_add);
if (ret)
break;
}
if (is_add && !ret)
kernfs_activate(root->kn);
return ret;
}
static void cgroup_exit_cftypes(struct cftype *cfts)
{
struct cftype *cft;
for (cft = cfts; cft->name[0] != '\0'; cft++) {
if (cft->max_write_len && cft->max_write_len != PAGE_SIZE)
kfree(cft->kf_ops);
cft->kf_ops = NULL;
cft->ss = NULL;
}
}
static int cgroup_init_cftypes(struct cgroup_subsys *ss, struct cftype *cfts)
{
struct cftype *cft;
for (cft = cfts; cft->name[0] != '\0'; cft++) {
struct kernfs_ops *kf_ops;
WARN_ON(cft->ss || cft->kf_ops);
if (cft->seq_start)
kf_ops = &cgroup_kf_ops;
else
kf_ops = &cgroup_kf_single_ops;
if (cft->max_write_len && cft->max_write_len != PAGE_SIZE) {
kf_ops = kmemdup(kf_ops, sizeof(*kf_ops), GFP_KERNEL);
if (!kf_ops) {
cgroup_exit_cftypes(cfts);
return -ENOMEM;
}
kf_ops->atomic_write_len = cft->max_write_len;
}
cft->kf_ops = kf_ops;
cft->ss = ss;
}
return 0;
}
static int cgroup_rm_cftypes_locked(struct cftype *cfts)
{
lockdep_assert_held(&cgroup_mutex);
if (!cfts || !cfts[0].ss)
return -ENOENT;
list_del(&cfts->node);
cgroup_apply_cftypes(cfts, false);
cgroup_exit_cftypes(cfts);
return 0;
}
int cgroup_rm_cftypes(struct cftype *cfts)
{
int ret;
mutex_lock(&cgroup_mutex);
ret = cgroup_rm_cftypes_locked(cfts);
mutex_unlock(&cgroup_mutex);
return ret;
}
int cgroup_add_cftypes(struct cgroup_subsys *ss, struct cftype *cfts)
{
int ret;
if (ss->disabled)
return 0;
if (!cfts || cfts[0].name[0] == '\0')
return 0;
ret = cgroup_init_cftypes(ss, cfts);
if (ret)
return ret;
mutex_lock(&cgroup_mutex);
list_add_tail(&cfts->node, &ss->cfts);
ret = cgroup_apply_cftypes(cfts, true);
if (ret)
cgroup_rm_cftypes_locked(cfts);
mutex_unlock(&cgroup_mutex);
return ret;
}
static int cgroup_task_count(const struct cgroup *cgrp)
{
int count = 0;
struct cgrp_cset_link *link;
down_read(&css_set_rwsem);
list_for_each_entry(link, &cgrp->cset_links, cset_link)
count += atomic_read(&link->cset->refcount);
up_read(&css_set_rwsem);
return count;
}
struct cgroup_subsys_state *css_next_child(struct cgroup_subsys_state *pos,
struct cgroup_subsys_state *parent)
{
struct cgroup_subsys_state *next;
cgroup_assert_mutex_or_rcu_locked();
if (!pos) {
next = list_entry_rcu(parent->children.next, struct cgroup_subsys_state, sibling);
} else if (likely(!(pos->flags & CSS_RELEASED))) {
next = list_entry_rcu(pos->sibling.next, struct cgroup_subsys_state, sibling);
} else {
list_for_each_entry_rcu(next, &parent->children, sibling)
if (next->serial_nr > pos->serial_nr)
break;
}
if (&next->sibling != &parent->children)
return next;
return NULL;
}
struct cgroup_subsys_state *
css_next_descendant_pre(struct cgroup_subsys_state *pos,
struct cgroup_subsys_state *root)
{
struct cgroup_subsys_state *next;
cgroup_assert_mutex_or_rcu_locked();
if (!pos)
return root;
next = css_next_child(NULL, pos);
if (next)
return next;
while (pos != root) {
next = css_next_child(pos, pos->parent);
if (next)
return next;
pos = pos->parent;
}
return NULL;
}
struct cgroup_subsys_state *
css_rightmost_descendant(struct cgroup_subsys_state *pos)
{
struct cgroup_subsys_state *last, *tmp;
cgroup_assert_mutex_or_rcu_locked();
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
cgroup_assert_mutex_or_rcu_locked();
if (!pos)
return css_leftmost_descendant(root);
if (pos == root)
return NULL;
next = css_next_child(pos, pos->parent);
if (next)
return css_leftmost_descendant(next);
return pos->parent;
}
bool css_has_online_children(struct cgroup_subsys_state *css)
{
struct cgroup_subsys_state *child;
bool ret = false;
rcu_read_lock();
css_for_each_child(child, css) {
if (child->flags & CSS_ONLINE) {
ret = true;
break;
}
}
rcu_read_unlock();
return ret;
}
static void css_advance_task_iter(struct css_task_iter *it)
{
struct list_head *l = it->cset_pos;
struct cgrp_cset_link *link;
struct css_set *cset;
do {
l = l->next;
if (l == it->cset_head) {
it->cset_pos = NULL;
return;
}
if (it->ss) {
cset = container_of(l, struct css_set,
e_cset_node[it->ss->id]);
} else {
link = list_entry(l, struct cgrp_cset_link, cset_link);
cset = link->cset;
}
} while (list_empty(&cset->tasks) && list_empty(&cset->mg_tasks));
it->cset_pos = l;
if (!list_empty(&cset->tasks))
it->task_pos = cset->tasks.next;
else
it->task_pos = cset->mg_tasks.next;
it->tasks_head = &cset->tasks;
it->mg_tasks_head = &cset->mg_tasks;
}
void css_task_iter_start(struct cgroup_subsys_state *css,
struct css_task_iter *it)
__acquires(css_set_rwsem)
{
WARN_ON_ONCE(!use_task_css_set_links);
down_read(&css_set_rwsem);
it->ss = css->ss;
if (it->ss)
it->cset_pos = &css->cgroup->e_csets[css->ss->id];
else
it->cset_pos = &css->cgroup->cset_links;
it->cset_head = it->cset_pos;
css_advance_task_iter(it);
}
struct task_struct *css_task_iter_next(struct css_task_iter *it)
{
struct task_struct *res;
struct list_head *l = it->task_pos;
if (!it->cset_pos)
return NULL;
res = list_entry(l, struct task_struct, cg_list);
l = l->next;
if (l == it->tasks_head)
l = it->mg_tasks_head->next;
if (l == it->mg_tasks_head)
css_advance_task_iter(it);
else
it->task_pos = l;
return res;
}
void css_task_iter_end(struct css_task_iter *it)
__releases(css_set_rwsem)
{
up_read(&css_set_rwsem);
}
int cgroup_transfer_tasks(struct cgroup *to, struct cgroup *from)
{
LIST_HEAD(preloaded_csets);
struct cgrp_cset_link *link;
struct css_task_iter it;
struct task_struct *task;
int ret;
mutex_lock(&cgroup_mutex);
down_read(&css_set_rwsem);
list_for_each_entry(link, &from->cset_links, cset_link)
cgroup_migrate_add_src(link->cset, to, &preloaded_csets);
up_read(&css_set_rwsem);
ret = cgroup_migrate_prepare_dst(to, &preloaded_csets);
if (ret)
goto out_err;
do {
css_task_iter_start(&from->self, &it);
task = css_task_iter_next(&it);
if (task)
get_task_struct(task);
css_task_iter_end(&it);
if (task) {
ret = cgroup_migrate(to, task, false);
put_task_struct(task);
}
} while (task && !ret);
out_err:
cgroup_migrate_finish(&preloaded_csets);
mutex_unlock(&cgroup_mutex);
return ret;
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
static void cgroup_pidlist_destroy_all(struct cgroup *cgrp)
{
struct cgroup_pidlist *l, *tmp_l;
mutex_lock(&cgrp->pidlist_mutex);
list_for_each_entry_safe(l, tmp_l, &cgrp->pidlists, links)
mod_delayed_work(cgroup_pidlist_destroy_wq, &l->destroy_dwork, 0);
mutex_unlock(&cgrp->pidlist_mutex);
flush_workqueue(cgroup_pidlist_destroy_wq);
BUG_ON(!list_empty(&cgrp->pidlists));
}
static void cgroup_pidlist_destroy_work_fn(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct cgroup_pidlist *l = container_of(dwork, struct cgroup_pidlist,
destroy_dwork);
struct cgroup_pidlist *tofree = NULL;
mutex_lock(&l->owner->pidlist_mutex);
if (!delayed_work_pending(dwork)) {
list_del(&l->links);
pidlist_free(l->list);
put_pid_ns(l->key.ns);
tofree = l;
}
mutex_unlock(&l->owner->pidlist_mutex);
kfree(tofree);
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
static pid_t pid_fry(pid_t pid)
{
unsigned a = pid & 0x55555555;
unsigned b = pid & 0xAAAAAAAA;
return (a << 1) | (b >> 1);
}
static pid_t cgroup_pid_fry(struct cgroup *cgrp, pid_t pid)
{
if (cgroup_sane_behavior(cgrp))
return pid_fry(pid);
else
return pid;
}
static int cmppid(const void *a, const void *b)
{
return *(pid_t *)a - *(pid_t *)b;
}
static int fried_cmppid(const void *a, const void *b)
{
return pid_fry(*(pid_t *)a) - pid_fry(*(pid_t *)b);
}
static struct cgroup_pidlist *cgroup_pidlist_find(struct cgroup *cgrp,
enum cgroup_filetype type)
{
struct cgroup_pidlist *l;
struct pid_namespace *ns = task_active_pid_ns(current);
lockdep_assert_held(&cgrp->pidlist_mutex);
list_for_each_entry(l, &cgrp->pidlists, links)
if (l->key.type == type && l->key.ns == ns)
return l;
return NULL;
}
static struct cgroup_pidlist *cgroup_pidlist_find_create(struct cgroup *cgrp,
enum cgroup_filetype type)
{
struct cgroup_pidlist *l;
lockdep_assert_held(&cgrp->pidlist_mutex);
l = cgroup_pidlist_find(cgrp, type);
if (l)
return l;
l = kzalloc(sizeof(struct cgroup_pidlist), GFP_KERNEL);
if (!l)
return l;
INIT_DELAYED_WORK(&l->destroy_dwork, cgroup_pidlist_destroy_work_fn);
l->key.type = type;
l->key.ns = get_pid_ns(task_active_pid_ns(current));
l->owner = cgrp;
list_add(&l->links, &cgrp->pidlists);
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
lockdep_assert_held(&cgrp->pidlist_mutex);
length = cgroup_task_count(cgrp);
array = pidlist_allocate(length);
if (!array)
return -ENOMEM;
css_task_iter_start(&cgrp->self, &it);
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
if (cgroup_sane_behavior(cgrp))
sort(array, length, sizeof(pid_t), fried_cmppid, NULL);
else
sort(array, length, sizeof(pid_t), cmppid, NULL);
if (type == CGROUP_FILE_PROCS)
length = pidlist_uniq(array, length);
l = cgroup_pidlist_find_create(cgrp, type);
if (!l) {
mutex_unlock(&cgrp->pidlist_mutex);
pidlist_free(array);
return -ENOMEM;
}
pidlist_free(l->list);
l->list = array;
l->length = length;
*lp = l;
return 0;
}
int cgroupstats_build(struct cgroupstats *stats, struct dentry *dentry)
{
struct kernfs_node *kn = kernfs_node_from_dentry(dentry);
struct cgroup *cgrp;
struct css_task_iter it;
struct task_struct *tsk;
if (dentry->d_sb->s_type != &cgroup_fs_type || !kn ||
kernfs_type(kn) != KERNFS_DIR)
return -EINVAL;
mutex_lock(&cgroup_mutex);
rcu_read_lock();
cgrp = rcu_dereference(kn->priv);
if (!cgrp || cgroup_is_dead(cgrp)) {
rcu_read_unlock();
mutex_unlock(&cgroup_mutex);
return -ENOENT;
}
rcu_read_unlock();
css_task_iter_start(&cgrp->self, &it);
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
mutex_unlock(&cgroup_mutex);
return 0;
}
static void *cgroup_pidlist_start(struct seq_file *s, loff_t *pos)
{
struct kernfs_open_file *of = s->private;
struct cgroup *cgrp = seq_css(s)->cgroup;
struct cgroup_pidlist *l;
enum cgroup_filetype type = seq_cft(s)->private;
int index = 0, pid = *pos;
int *iter, ret;
mutex_lock(&cgrp->pidlist_mutex);
if (of->priv)
of->priv = cgroup_pidlist_find(cgrp, type);
if (!of->priv) {
ret = pidlist_array_load(cgrp, type,
(struct cgroup_pidlist **)&of->priv);
if (ret)
return ERR_PTR(ret);
}
l = of->priv;
if (pid) {
int end = l->length;
while (index < end) {
int mid = (index + end) / 2;
if (cgroup_pid_fry(cgrp, l->list[mid]) == pid) {
index = mid;
break;
} else if (cgroup_pid_fry(cgrp, l->list[mid]) <= pid)
index = mid + 1;
else
end = mid;
}
}
if (index >= l->length)
return NULL;
iter = l->list + index;
*pos = cgroup_pid_fry(cgrp, *iter);
return iter;
}
static void cgroup_pidlist_stop(struct seq_file *s, void *v)
{
struct kernfs_open_file *of = s->private;
struct cgroup_pidlist *l = of->priv;
if (l)
mod_delayed_work(cgroup_pidlist_destroy_wq, &l->destroy_dwork,
CGROUP_PIDLIST_DESTROY_DELAY);
mutex_unlock(&seq_css(s)->cgroup->pidlist_mutex);
}
static void *cgroup_pidlist_next(struct seq_file *s, void *v, loff_t *pos)
{
struct kernfs_open_file *of = s->private;
struct cgroup_pidlist *l = of->priv;
pid_t *p = v;
pid_t *end = l->list + l->length;
p++;
if (p >= end) {
return NULL;
} else {
*pos = cgroup_pid_fry(seq_css(s)->cgroup, *p);
return p;
}
}
static int cgroup_pidlist_show(struct seq_file *s, void *v)
{
return seq_printf(s, "%d\n", *(int *)v);
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
static int cgroup_populate_dir(struct cgroup *cgrp, unsigned int subsys_mask)
{
struct cgroup_subsys *ss;
int i, ret = 0;
for_each_subsys(ss, i) {
struct cftype *cfts;
if (!(subsys_mask & (1 << i)))
continue;
list_for_each_entry(cfts, &ss->cfts, node) {
ret = cgroup_addrm_files(cgrp, cfts, true);
if (ret < 0)
goto err;
}
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
if (css->ss) {
if (css->parent)
css_put(css->parent);
css->ss->css_free(css);
cgroup_put(cgrp);
} else {
atomic_dec(&cgrp->root->nr_cgrps);
cgroup_pidlist_destroy_all(cgrp);
if (cgroup_parent(cgrp)) {
cgroup_put(cgroup_parent(cgrp));
kernfs_put(cgrp->kn);
kfree(cgrp);
} else {
cgroup_destroy_root(cgrp->root);
}
}
}
static void css_free_rcu_fn(struct rcu_head *rcu_head)
{
struct cgroup_subsys_state *css =
container_of(rcu_head, struct cgroup_subsys_state, rcu_head);
INIT_WORK(&css->destroy_work, css_free_work_fn);
queue_work(cgroup_destroy_wq, &css->destroy_work);
}
static void css_release_work_fn(struct work_struct *work)
{
struct cgroup_subsys_state *css =
container_of(work, struct cgroup_subsys_state, destroy_work);
struct cgroup_subsys *ss = css->ss;
struct cgroup *cgrp = css->cgroup;
mutex_lock(&cgroup_mutex);
css->flags |= CSS_RELEASED;
list_del_rcu(&css->sibling);
if (ss) {
cgroup_idr_remove(&ss->css_idr, css->id);
} else {
cgroup_idr_remove(&cgrp->root->cgroup_idr, cgrp->id);
cgrp->id = -1;
}
mutex_unlock(&cgroup_mutex);
call_rcu(&css->rcu_head, css_free_rcu_fn);
}
static void css_release(struct percpu_ref *ref)
{
struct cgroup_subsys_state *css =
container_of(ref, struct cgroup_subsys_state, refcnt);
INIT_WORK(&css->destroy_work, css_release_work_fn);
queue_work(cgroup_destroy_wq, &css->destroy_work);
}
static void init_and_link_css(struct cgroup_subsys_state *css,
struct cgroup_subsys *ss, struct cgroup *cgrp)
{
lockdep_assert_held(&cgroup_mutex);
cgroup_get(cgrp);
memset(css, 0, sizeof(*css));
css->cgroup = cgrp;
css->ss = ss;
INIT_LIST_HEAD(&css->sibling);
INIT_LIST_HEAD(&css->children);
css->serial_nr = css_serial_nr_next++;
if (cgroup_parent(cgrp)) {
css->parent = cgroup_css(cgroup_parent(cgrp), ss);
css_get(css->parent);
}
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
rcu_assign_pointer(css->cgroup->subsys[ss->id], css);
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
RCU_INIT_POINTER(css->cgroup->subsys[ss->id], NULL);
wake_up_all(&css->cgroup->offline_waitq);
}
static int create_css(struct cgroup *cgrp, struct cgroup_subsys *ss)
{
struct cgroup *parent = cgroup_parent(cgrp);
struct cgroup_subsys_state *parent_css = cgroup_css(parent, ss);
struct cgroup_subsys_state *css;
int err;
lockdep_assert_held(&cgroup_mutex);
css = ss->css_alloc(parent_css);
if (IS_ERR(css))
return PTR_ERR(css);
init_and_link_css(css, ss, cgrp);
err = percpu_ref_init(&css->refcnt, css_release);
if (err)
goto err_free_css;
err = cgroup_idr_alloc(&ss->css_idr, NULL, 2, 0, GFP_NOWAIT);
if (err < 0)
goto err_free_percpu_ref;
css->id = err;
err = cgroup_populate_dir(cgrp, 1 << ss->id);
if (err)
goto err_free_id;
list_add_tail_rcu(&css->sibling, &parent_css->children);
cgroup_idr_replace(&ss->css_idr, css, css->id);
err = online_css(css);
if (err)
goto err_list_del;
if (ss->broken_hierarchy && !ss->warned_broken_hierarchy &&
cgroup_parent(parent)) {
pr_warn("%s (%d) created nested cgroup for controller \"%s\" which has incomplete hierarchy support. Nested cgroups may change behavior in the future.\n",
current->comm, current->pid, ss->name);
if (!strcmp(ss->name, "memory"))
pr_warn("\"memory\" requires setting use_hierarchy to 1 on the root\n");
ss->warned_broken_hierarchy = true;
}
return 0;
err_list_del:
list_del_rcu(&css->sibling);
cgroup_clear_dir(css->cgroup, 1 << css->ss->id);
err_free_id:
cgroup_idr_remove(&ss->css_idr, css->id);
err_free_percpu_ref:
percpu_ref_cancel_init(&css->refcnt);
err_free_css:
call_rcu(&css->rcu_head, css_free_rcu_fn);
return err;
}
static int cgroup_mkdir(struct kernfs_node *parent_kn, const char *name,
umode_t mode)
{
struct cgroup *parent, *cgrp;
struct cgroup_root *root;
struct cgroup_subsys *ss;
struct kernfs_node *kn;
int ssid, ret;
parent = cgroup_kn_lock_live(parent_kn);
if (!parent)
return -ENODEV;
root = parent->root;
cgrp = kzalloc(sizeof(*cgrp), GFP_KERNEL);
if (!cgrp) {
ret = -ENOMEM;
goto out_unlock;
}
ret = percpu_ref_init(&cgrp->self.refcnt, css_release);
if (ret)
goto out_free_cgrp;
cgrp->id = cgroup_idr_alloc(&root->cgroup_idr, NULL, 2, 0, GFP_NOWAIT);
if (cgrp->id < 0) {
ret = -ENOMEM;
goto out_cancel_ref;
}
init_cgroup_housekeeping(cgrp);
cgrp->self.parent = &parent->self;
cgrp->root = root;
if (notify_on_release(parent))
set_bit(CGRP_NOTIFY_ON_RELEASE, &cgrp->flags);
if (test_bit(CGRP_CPUSET_CLONE_CHILDREN, &parent->flags))
set_bit(CGRP_CPUSET_CLONE_CHILDREN, &cgrp->flags);
kn = kernfs_create_dir(parent->kn, name, mode, cgrp);
if (IS_ERR(kn)) {
ret = PTR_ERR(kn);
goto out_free_id;
}
cgrp->kn = kn;
kernfs_get(kn);
cgrp->self.serial_nr = css_serial_nr_next++;
list_add_tail_rcu(&cgrp->self.sibling, &cgroup_parent(cgrp)->self.children);
atomic_inc(&root->nr_cgrps);
cgroup_get(parent);
cgroup_idr_replace(&root->cgroup_idr, cgrp, cgrp->id);
ret = cgroup_kn_set_ugid(kn);
if (ret)
goto out_destroy;
ret = cgroup_addrm_files(cgrp, cgroup_base_files, true);
if (ret)
goto out_destroy;
for_each_subsys(ss, ssid) {
if (parent->child_subsys_mask & (1 << ssid)) {
ret = create_css(cgrp, ss);
if (ret)
goto out_destroy;
}
}
if (!cgroup_on_dfl(cgrp))
cgrp->child_subsys_mask = parent->child_subsys_mask;
kernfs_activate(kn);
ret = 0;
goto out_unlock;
out_free_id:
cgroup_idr_remove(&root->cgroup_idr, cgrp->id);
out_cancel_ref:
percpu_ref_cancel_init(&cgrp->self.refcnt);
out_free_cgrp:
kfree(cgrp);
out_unlock:
cgroup_kn_unlock(parent_kn);
return ret;
out_destroy:
cgroup_destroy_locked(cgrp);
goto out_unlock;
}
static void css_killed_work_fn(struct work_struct *work)
{
struct cgroup_subsys_state *css =
container_of(work, struct cgroup_subsys_state, destroy_work);
mutex_lock(&cgroup_mutex);
offline_css(css);
mutex_unlock(&cgroup_mutex);
css_put(css);
}
static void css_killed_ref_fn(struct percpu_ref *ref)
{
struct cgroup_subsys_state *css =
container_of(ref, struct cgroup_subsys_state, refcnt);
INIT_WORK(&css->destroy_work, css_killed_work_fn);
queue_work(cgroup_destroy_wq, &css->destroy_work);
}
static void kill_css(struct cgroup_subsys_state *css)
{
lockdep_assert_held(&cgroup_mutex);
cgroup_clear_dir(css->cgroup, 1 << css->ss->id);
css_get(css);
percpu_ref_kill_and_confirm(&css->refcnt, css_killed_ref_fn);
}
static int cgroup_destroy_locked(struct cgroup *cgrp)
__releases(&cgroup_mutex
static int cgroup_rmdir(struct kernfs_node *kn)
{
struct cgroup *cgrp;
int ret = 0;
cgrp = cgroup_kn_lock_live(kn);
if (!cgrp)
return 0;
cgroup_get(cgrp);
ret = cgroup_destroy_locked(cgrp);
cgroup_kn_unlock(kn);
if (!ret)
RCU_INIT_POINTER(*(void __rcu __force **)&kn->priv, NULL);
cgroup_put(cgrp);
return ret;
}
static void __init cgroup_init_subsys(struct cgroup_subsys *ss, bool early)
{
struct cgroup_subsys_state *css;
printk(KERN_INFO "Initializing cgroup subsys %s\n", ss->name);
mutex_lock(&cgroup_mutex);
idr_init(&ss->css_idr);
INIT_LIST_HEAD(&ss->cfts);
ss->root = &cgrp_dfl_root;
css = ss->css_alloc(cgroup_css(&cgrp_dfl_root.cgrp, ss));
BUG_ON(IS_ERR(css));
init_and_link_css(css, ss, &cgrp_dfl_root.cgrp);
css->flags |= CSS_NO_REF;
if (early) {
css->id = 1;
} else {
css->id = cgroup_idr_alloc(&ss->css_idr, css, 1, 2, GFP_KERNEL);
BUG_ON(css->id < 0);
}
init_css_set.subsys[ss->id] = css;
need_forkexit_callback |= ss->fork || ss->exit;
BUG_ON(!list_empty(&init_task.tasks));
BUG_ON(online_css(css));
mutex_unlock(&cgroup_mutex);
}
int __init cgroup_init_early(void)
{
static struct cgroup_sb_opts __initdata opts =
{ .flags = CGRP_ROOT_SANE_BEHAVIOR };
struct cgroup_subsys *ss;
int i;
init_cgroup_root(&cgrp_dfl_root, &opts);
cgrp_dfl_root.cgrp.self.flags |= CSS_NO_REF;
RCU_INIT_POINTER(init_task.cgroups, &init_css_set);
for_each_subsys(ss, i) {
WARN(!ss->css_alloc || !ss->css_free || ss->name || ss->id,
"invalid cgroup_subsys %d:%s css_alloc=%p css_free=%p name:id=%d:%s\n",
i, cgroup_subsys_name[i], ss->css_alloc, ss->css_free,
ss->id, ss->name);
WARN(strlen(cgroup_subsys_name[i]) > MAX_CGROUP_TYPE_NAMELEN,
"cgroup_subsys_name %s too long\n", cgroup_subsys_name[i]);
ss->id = i;
ss->name = cgroup_subsys_name[i];
if (ss->early_init)
cgroup_init_subsys(ss, true);
}
return 0;
}
int __init cgroup_init(void)
{
struct cgroup_subsys *ss;
unsigned long key;
int ssid, err;
BUG_ON(cgroup_init_cftypes(NULL, cgroup_base_files));
mutex_lock(&cgroup_mutex);
key = css_set_hash(init_css_set.subsys);
hash_add(css_set_table, &init_css_set.hlist, key);
BUG_ON(cgroup_setup_root(&cgrp_dfl_root, 0));
mutex_unlock(&cgroup_mutex);
for_each_subsys(ss, ssid) {
if (ss->early_init) {
struct cgroup_subsys_state *css =
init_css_set.subsys[ss->id];
css->id = cgroup_idr_alloc(&ss->css_idr, css, 1, 2,
GFP_KERNEL);
BUG_ON(css->id < 0);
} else {
cgroup_init_subsys(ss, false);
}
list_add_tail(&init_css_set.e_cset_node[ssid],
&cgrp_dfl_root.cgrp.e_csets[ssid]);
if (!ss->disabled) {
cgrp_dfl_root.subsys_mask |= 1 << ss->id;
WARN_ON(cgroup_add_cftypes(ss, ss->base_cftypes));
}
}
cgroup_kobj = kobject_create_and_add("cgroup", fs_kobj);
if (!cgroup_kobj)
return -ENOMEM;
err = register_filesystem(&cgroup_fs_type);
if (err < 0) {
kobject_put(cgroup_kobj);
return err;
}
proc_create("cgroups", 0, NULL, &proc_cgroupstats_operations);
return 0;
}
static int __init cgroup_wq_init(void)
{
cgroup_destroy_wq = alloc_workqueue("cgroup_destroy", 0, 1);
BUG_ON(!cgroup_destroy_wq);
cgroup_pidlist_destroy_wq = alloc_workqueue("cgroup_pidlist_destroy",
0, 1);
BUG_ON(!cgroup_pidlist_destroy_wq);
return 0;
}
int proc_cgroup_show(struct seq_file *m, void *v)
{
struct pid *pid;
struct task_struct *tsk;
char *buf, *path;
int retval;
struct cgroup_root *root;
retval = -ENOMEM;
buf = kmalloc(PATH_MAX, GFP_KERNEL);
if (!buf)
goto out;
retval = -ESRCH;
pid = m->private;
tsk = get_pid_task(pid, PIDTYPE_PID);
if (!tsk)
goto out_free;
retval = 0;
mutex_lock(&cgroup_mutex);
down_read(&css_set_rwsem);
for_each_root(root) {
struct cgroup_subsys *ss;
struct cgroup *cgrp;
int ssid, count = 0;
if (root == &cgrp_dfl_root && !cgrp_dfl_root_visible)
continue;
seq_printf(m, "%d:", root->hierarchy_id);
for_each_subsys(ss, ssid)
if (root->subsys_mask & (1 << ssid))
seq_printf(m, "%s%s", count++ ? "," : "", ss->name);
if (strlen(root->name))
seq_printf(m, "%sname=%s", count ? "," : "",
root->name);
seq_putc(m, ':');
cgrp = task_cgroup_from_root(tsk, root);
path = cgroup_path(cgrp, buf, PATH_MAX);
if (!path) {
retval = -ENAMETOOLONG;
goto out_unlock;
}
seq_puts(m, path);
seq_putc(m, '\n');
}
out_unlock:
up_read(&css_set_rwsem);
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
atomic_read(&ss->root->nr_cgrps), !ss->disabled);
mutex_unlock(&cgroup_mutex);
return 0;
}
static int cgroupstats_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_cgroupstats_show, NULL);
}
void cgroup_fork(struct task_struct *child)
{
RCU_INIT_POINTER(child->cgroups, &init_css_set);
INIT_LIST_HEAD(&child->cg_list);
}
void cgroup_post_fork(struct task_struct *child)
{
struct cgroup_subsys *ss;
int i;
if (use_task_css_set_links) {
struct css_set *cset;
down_write(&css_set_rwsem);
cset = task_css_set(current);
if (list_empty(&child->cg_list)) {
rcu_assign_pointer(child->cgroups, cset);
list_add(&child->cg_list, &cset->tasks);
get_css_set(cset);
}
up_write(&css_set_rwsem);
}
if (need_forkexit_callback) {
for_each_subsys(ss, i)
if (ss->fork)
ss->fork(child);
}
}
void cgroup_exit(struct task_struct *tsk)
{
struct cgroup_subsys *ss;
struct css_set *cset;
bool put_cset = false;
int i;
if (!list_empty(&tsk->cg_list)) {
down_write(&css_set_rwsem);
list_del_init(&tsk->cg_list);
up_write(&css_set_rwsem);
put_cset = true;
}
cset = task_css_set(tsk);
RCU_INIT_POINTER(tsk->cgroups, &init_css_set);
if (need_forkexit_callback) {
for_each_subsys(ss, i) {
if (ss->exit) {
struct cgroup_subsys_state *old_css = cset->subsys[i];
struct cgroup_subsys_state *css = task_css(tsk, i);
ss->exit(css, old_css, tsk);
}
}
}
if (put_cset)
put_css_set(cset, true);
}
static void check_for_release(struct cgroup *cgrp)
{
if (cgroup_is_releasable(cgrp) && list_empty(&cgrp->cset_links) &&
!css_has_online_children(&cgrp->self)) {
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
char *pathbuf = NULL, *agentbuf = NULL, *path;
struct cgroup *cgrp = list_entry(release_list.next,
struct cgroup,
release_list);
list_del_init(&cgrp->release_list);
raw_spin_unlock(&release_list_lock);
pathbuf = kmalloc(PATH_MAX, GFP_KERNEL);
if (!pathbuf)
goto continue_free;
path = cgroup_path(cgrp, pathbuf, PATH_MAX);
if (!path)
goto continue_free;
agentbuf = kstrdup(cgrp->root->release_agent_path, GFP_KERNEL);
if (!agentbuf)
goto continue_free;
i = 0;
argv[i++] = agentbuf;
argv[i++] = path;
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
for_each_subsys(ss, i) {
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
struct cgroup_subsys_state *css_tryget_online_from_dir(struct dentry *dentry,
struct cgroup_subsys *ss)
{
struct kernfs_node *kn = kernfs_node_from_dentry(dentry);
struct cgroup_subsys_state *css = NULL;
struct cgroup *cgrp;
if (dentry->d_sb->s_type != &cgroup_fs_type || !kn ||
kernfs_type(kn) != KERNFS_DIR)
return ERR_PTR(-EBADF);
rcu_read_lock();
cgrp = rcu_dereference(kn->priv);
if (cgrp)
css = cgroup_css(cgrp, ss);
if (!css || !css_tryget_online(css))
css = ERR_PTR(-ENOENT);
rcu_read_unlock();
return css;
}
struct cgroup_subsys_state *css_from_id(int id, struct cgroup_subsys *ss)
{
WARN_ON_ONCE(!rcu_read_lock_held());
return idr_find(&ss->css_idr, id);
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
static int current_css_set_cg_links_read(struct seq_file *seq, void *v)
{
struct cgrp_cset_link *link;
struct css_set *cset;
char *name_buf;
name_buf = kmalloc(NAME_MAX + 1, GFP_KERNEL);
if (!name_buf)
return -ENOMEM;
down_read(&css_set_rwsem);
rcu_read_lock();
cset = rcu_dereference(current->cgroups);
list_for_each_entry(link, &cset->cgrp_links, cgrp_link) {
struct cgroup *c = link->cgrp;
cgroup_name(c, name_buf, NAME_MAX + 1);
seq_printf(seq, "Root %d group %s\n",
c->root->hierarchy_id, name_buf);
}
rcu_read_unlock();
up_read(&css_set_rwsem);
kfree(name_buf);
return 0;
}
static int cgroup_css_links_read(struct seq_file *seq, void *v)
{
struct cgroup_subsys_state *css = seq_css(seq);
struct cgrp_cset_link *link;
down_read(&css_set_rwsem);
list_for_each_entry(link, &css->cgroup->cset_links, cset_link) {
struct css_set *cset = link->cset;
struct task_struct *task;
int count = 0;
seq_printf(seq, "css_set %p\n", cset);
list_for_each_entry(task, &cset->tasks, cg_list) {
if (count++ > MAX_TASKS_SHOWN_PER_CSS)
goto overflow;
seq_printf(seq, " task %d\n", task_pid_vnr(task));
}
list_for_each_entry(task, &cset->mg_tasks, cg_list) {
if (count++ > MAX_TASKS_SHOWN_PER_CSS)
goto overflow;
seq_printf(seq, " task %d\n", task_pid_vnr(task));
}
continue;
overflow:
seq_puts(seq, " ...\n");
}
up_read(&css_set_rwsem);
return 0;
}
static u64 releasable_read(struct cgroup_subsys_state *css, struct cftype *cft)
{
return test_bit(CGRP_RELEASABLE, &css->cgroup->flags);
}
