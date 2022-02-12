static int mangle_name(char *name, char *target)
{
char *t = target;
while (*name == '/' || *name == '.')
name++;
if (target) {
for (; *name; name++) {
if (*name == '/')
*(t)++ = '.';
else if (isspace(*name))
*(t)++ = '_';
else if (isalnum(*name) || strchr("._-", *name))
*(t)++ = *name;
}
*t = 0;
} else {
int len = 0;
for (; *name; name++) {
if (isalnum(*name) || isspace(*name) ||
strchr("/._-", *name))
len++;
}
return len;
}
return t - target;
}
static char *aa_simple_write_to_buffer(int op, const char __user *userbuf,
size_t alloc_size, size_t copy_size,
loff_t *pos)
{
char *data;
BUG_ON(copy_size > alloc_size);
if (*pos != 0)
return ERR_PTR(-ESPIPE);
if (!aa_may_manage_policy(op))
return ERR_PTR(-EACCES);
data = kvmalloc(alloc_size);
if (data == NULL)
return ERR_PTR(-ENOMEM);
if (copy_from_user(data, userbuf, copy_size)) {
kvfree(data);
return ERR_PTR(-EFAULT);
}
return data;
}
static ssize_t profile_load(struct file *f, const char __user *buf, size_t size,
loff_t *pos)
{
char *data;
ssize_t error;
data = aa_simple_write_to_buffer(OP_PROF_LOAD, buf, size, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
error = aa_replace_profiles(data, size, PROF_ADD);
kvfree(data);
}
return error;
}
static ssize_t profile_replace(struct file *f, const char __user *buf,
size_t size, loff_t *pos)
{
char *data;
ssize_t error;
data = aa_simple_write_to_buffer(OP_PROF_REPL, buf, size, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
error = aa_replace_profiles(data, size, PROF_REPLACE);
kvfree(data);
}
return error;
}
static ssize_t profile_remove(struct file *f, const char __user *buf,
size_t size, loff_t *pos)
{
char *data;
ssize_t error;
data = aa_simple_write_to_buffer(OP_PROF_RM, buf, size + 1, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
data[size] = 0;
error = aa_remove_profiles(data, size);
kvfree(data);
}
return error;
}
static int aa_fs_seq_show(struct seq_file *seq, void *v)
{
struct aa_fs_entry *fs_file = seq->private;
if (!fs_file)
return 0;
switch (fs_file->v_type) {
case AA_FS_TYPE_BOOLEAN:
seq_printf(seq, "%s\n", fs_file->v.boolean ? "yes" : "no");
break;
case AA_FS_TYPE_STRING:
seq_printf(seq, "%s\n", fs_file->v.string);
break;
case AA_FS_TYPE_U64:
seq_printf(seq, "%#08lx\n", fs_file->v.u64);
break;
default:
break;
}
return 0;
}
static int aa_fs_seq_open(struct inode *inode, struct file *file)
{
return single_open(file, aa_fs_seq_show, inode->i_private);
}
static int aa_fs_seq_profile_open(struct inode *inode, struct file *file,
int (*show)(struct seq_file *, void *))
{
struct aa_replacedby *r = aa_get_replacedby(inode->i_private);
int error = single_open(file, show, r);
if (error) {
file->private_data = NULL;
aa_put_replacedby(r);
}
return error;
}
static int aa_fs_seq_profile_release(struct inode *inode, struct file *file)
{
struct seq_file *seq = (struct seq_file *) file->private_data;
if (seq)
aa_put_replacedby(seq->private);
return single_release(inode, file);
}
static int aa_fs_seq_profname_show(struct seq_file *seq, void *v)
{
struct aa_replacedby *r = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&r->profile);
seq_printf(seq, "%s\n", profile->base.name);
aa_put_profile(profile);
return 0;
}
static int aa_fs_seq_profname_open(struct inode *inode, struct file *file)
{
return aa_fs_seq_profile_open(inode, file, aa_fs_seq_profname_show);
}
static int aa_fs_seq_profmode_show(struct seq_file *seq, void *v)
{
struct aa_replacedby *r = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&r->profile);
seq_printf(seq, "%s\n", aa_profile_mode_names[profile->mode]);
aa_put_profile(profile);
return 0;
}
static int aa_fs_seq_profmode_open(struct inode *inode, struct file *file)
{
return aa_fs_seq_profile_open(inode, file, aa_fs_seq_profmode_show);
}
static int aa_fs_seq_profattach_show(struct seq_file *seq, void *v)
{
struct aa_replacedby *r = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&r->profile);
if (profile->attach)
seq_printf(seq, "%s\n", profile->attach);
else if (profile->xmatch)
seq_puts(seq, "<unknown>\n");
else
seq_printf(seq, "%s\n", profile->base.name);
aa_put_profile(profile);
return 0;
}
static int aa_fs_seq_profattach_open(struct inode *inode, struct file *file)
{
return aa_fs_seq_profile_open(inode, file, aa_fs_seq_profattach_show);
}
static int aa_fs_seq_hash_show(struct seq_file *seq, void *v)
{
struct aa_replacedby *r = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&r->profile);
unsigned int i, size = aa_hash_size();
if (profile->hash) {
for (i = 0; i < size; i++)
seq_printf(seq, "%.2x", profile->hash[i]);
seq_puts(seq, "\n");
}
aa_put_profile(profile);
return 0;
}
static int aa_fs_seq_hash_open(struct inode *inode, struct file *file)
{
return single_open(file, aa_fs_seq_hash_show, inode->i_private);
}
void __aa_fs_profile_rmdir(struct aa_profile *profile)
{
struct aa_profile *child;
int i;
if (!profile)
return;
list_for_each_entry(child, &profile->base.profiles, base.list)
__aa_fs_profile_rmdir(child);
for (i = AAFS_PROF_SIZEOF - 1; i >= 0; --i) {
struct aa_replacedby *r;
if (!profile->dents[i])
continue;
r = d_inode(profile->dents[i])->i_private;
securityfs_remove(profile->dents[i]);
aa_put_replacedby(r);
profile->dents[i] = NULL;
}
}
void __aa_fs_profile_migrate_dents(struct aa_profile *old,
struct aa_profile *new)
{
int i;
for (i = 0; i < AAFS_PROF_SIZEOF; i++) {
new->dents[i] = old->dents[i];
if (new->dents[i])
new->dents[i]->d_inode->i_mtime = CURRENT_TIME;
old->dents[i] = NULL;
}
}
static struct dentry *create_profile_file(struct dentry *dir, const char *name,
struct aa_profile *profile,
const struct file_operations *fops)
{
struct aa_replacedby *r = aa_get_replacedby(profile->replacedby);
struct dentry *dent;
dent = securityfs_create_file(name, S_IFREG | 0444, dir, r, fops);
if (IS_ERR(dent))
aa_put_replacedby(r);
return dent;
}
int __aa_fs_profile_mkdir(struct aa_profile *profile, struct dentry *parent)
{
struct aa_profile *child;
struct dentry *dent = NULL, *dir;
int error;
if (!parent) {
struct aa_profile *p;
p = aa_deref_parent(profile);
dent = prof_dir(p);
dent = securityfs_create_dir("profiles", dent);
if (IS_ERR(dent))
goto fail;
prof_child_dir(p) = parent = dent;
}
if (!profile->dirname) {
int len, id_len;
len = mangle_name(profile->base.name, NULL);
id_len = snprintf(NULL, 0, ".%ld", profile->ns->uniq_id);
profile->dirname = kmalloc(len + id_len + 1, GFP_KERNEL);
if (!profile->dirname)
goto fail;
mangle_name(profile->base.name, profile->dirname);
sprintf(profile->dirname + len, ".%ld", profile->ns->uniq_id++);
}
dent = securityfs_create_dir(profile->dirname, parent);
if (IS_ERR(dent))
goto fail;
prof_dir(profile) = dir = dent;
dent = create_profile_file(dir, "name", profile, &aa_fs_profname_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_NAME] = dent;
dent = create_profile_file(dir, "mode", profile, &aa_fs_profmode_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_MODE] = dent;
dent = create_profile_file(dir, "attach", profile,
&aa_fs_profattach_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_ATTACH] = dent;
if (profile->hash) {
dent = create_profile_file(dir, "sha1", profile,
&aa_fs_seq_hash_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_HASH] = dent;
}
list_for_each_entry(child, &profile->base.profiles, base.list) {
error = __aa_fs_profile_mkdir(child, prof_child_dir(profile));
if (error)
goto fail2;
}
return 0;
fail:
error = PTR_ERR(dent);
fail2:
__aa_fs_profile_rmdir(profile);
return error;
}
void __aa_fs_namespace_rmdir(struct aa_namespace *ns)
{
struct aa_namespace *sub;
struct aa_profile *child;
int i;
if (!ns)
return;
list_for_each_entry(child, &ns->base.profiles, base.list)
__aa_fs_profile_rmdir(child);
list_for_each_entry(sub, &ns->sub_ns, base.list) {
mutex_lock(&sub->lock);
__aa_fs_namespace_rmdir(sub);
mutex_unlock(&sub->lock);
}
for (i = AAFS_NS_SIZEOF - 1; i >= 0; --i) {
securityfs_remove(ns->dents[i]);
ns->dents[i] = NULL;
}
}
int __aa_fs_namespace_mkdir(struct aa_namespace *ns, struct dentry *parent,
const char *name)
{
struct aa_namespace *sub;
struct aa_profile *child;
struct dentry *dent, *dir;
int error;
if (!name)
name = ns->base.name;
dent = securityfs_create_dir(name, parent);
if (IS_ERR(dent))
goto fail;
ns_dir(ns) = dir = dent;
dent = securityfs_create_dir("profiles", dir);
if (IS_ERR(dent))
goto fail;
ns_subprofs_dir(ns) = dent;
dent = securityfs_create_dir("namespaces", dir);
if (IS_ERR(dent))
goto fail;
ns_subns_dir(ns) = dent;
list_for_each_entry(child, &ns->base.profiles, base.list) {
error = __aa_fs_profile_mkdir(child, ns_subprofs_dir(ns));
if (error)
goto fail2;
}
list_for_each_entry(sub, &ns->sub_ns, base.list) {
mutex_lock(&sub->lock);
error = __aa_fs_namespace_mkdir(sub, ns_subns_dir(ns), NULL);
mutex_unlock(&sub->lock);
if (error)
goto fail2;
}
return 0;
fail:
error = PTR_ERR(dent);
fail2:
__aa_fs_namespace_rmdir(ns);
return error;
}
static struct aa_namespace *__next_namespace(struct aa_namespace *root,
struct aa_namespace *ns)
{
struct aa_namespace *parent, *next;
if (!list_empty(&ns->sub_ns)) {
next = list_first_entry(&ns->sub_ns, typeof(*ns), base.list);
mutex_lock(&next->lock);
return next;
}
parent = ns->parent;
while (ns != root) {
mutex_unlock(&ns->lock);
next = list_next_entry(ns, base.list);
if (!list_entry_is_head(next, &parent->sub_ns, base.list)) {
mutex_lock(&next->lock);
return next;
}
ns = parent;
parent = parent->parent;
}
return NULL;
}
static struct aa_profile *__first_profile(struct aa_namespace *root,
struct aa_namespace *ns)
{
for (; ns; ns = __next_namespace(root, ns)) {
if (!list_empty(&ns->base.profiles))
return list_first_entry(&ns->base.profiles,
struct aa_profile, base.list);
}
return NULL;
}
static struct aa_profile *__next_profile(struct aa_profile *p)
{
struct aa_profile *parent;
struct aa_namespace *ns = p->ns;
if (!list_empty(&p->base.profiles))
return list_first_entry(&p->base.profiles, typeof(*p),
base.list);
parent = rcu_dereference_protected(p->parent,
mutex_is_locked(&p->ns->lock));
while (parent) {
p = list_next_entry(p, base.list);
if (!list_entry_is_head(p, &parent->base.profiles, base.list))
return p;
p = parent;
parent = rcu_dereference_protected(parent->parent,
mutex_is_locked(&parent->ns->lock));
}
p = list_next_entry(p, base.list);
if (!list_entry_is_head(p, &ns->base.profiles, base.list))
return p;
return NULL;
}
static struct aa_profile *next_profile(struct aa_namespace *root,
struct aa_profile *profile)
{
struct aa_profile *next = __next_profile(profile);
if (next)
return next;
return __first_profile(root, __next_namespace(root, profile->ns));
}
static void *p_start(struct seq_file *f, loff_t *pos)
{
struct aa_profile *profile = NULL;
struct aa_namespace *root = aa_current_profile()->ns;
loff_t l = *pos;
f->private = aa_get_namespace(root);
mutex_lock(&root->lock);
profile = __first_profile(root, root);
for (; profile && l > 0; l--)
profile = next_profile(root, profile);
return profile;
}
static void *p_next(struct seq_file *f, void *p, loff_t *pos)
{
struct aa_profile *profile = p;
struct aa_namespace *ns = f->private;
(*pos)++;
return next_profile(ns, profile);
}
static void p_stop(struct seq_file *f, void *p)
{
struct aa_profile *profile = p;
struct aa_namespace *root = f->private, *ns;
if (profile) {
for (ns = profile->ns; ns && ns != root; ns = ns->parent)
mutex_unlock(&ns->lock);
}
mutex_unlock(&root->lock);
aa_put_namespace(root);
}
static int seq_show_profile(struct seq_file *f, void *p)
{
struct aa_profile *profile = (struct aa_profile *)p;
struct aa_namespace *root = f->private;
if (profile->ns != root)
seq_printf(f, ":%s://", aa_ns_name(root, profile->ns));
seq_printf(f, "%s (%s)\n", profile->base.hname,
aa_profile_mode_names[profile->mode]);
return 0;
}
static int profiles_open(struct inode *inode, struct file *file)
{
return seq_open(file, &aa_fs_profiles_op);
}
static int profiles_release(struct inode *inode, struct file *file)
{
return seq_release(inode, file);
}
static int __init aafs_create_file(struct aa_fs_entry *fs_file,
struct dentry *parent)
{
int error = 0;
fs_file->dentry = securityfs_create_file(fs_file->name,
S_IFREG | fs_file->mode,
parent, fs_file,
fs_file->file_ops);
if (IS_ERR(fs_file->dentry)) {
error = PTR_ERR(fs_file->dentry);
fs_file->dentry = NULL;
}
return error;
}
static int __init aafs_create_dir(struct aa_fs_entry *fs_dir,
struct dentry *parent)
{
struct aa_fs_entry *fs_file;
struct dentry *dir;
int error;
dir = securityfs_create_dir(fs_dir->name, parent);
if (IS_ERR(dir))
return PTR_ERR(dir);
fs_dir->dentry = dir;
for (fs_file = fs_dir->v.files; fs_file && fs_file->name; ++fs_file) {
if (fs_file->v_type == AA_FS_TYPE_DIR)
error = aafs_create_dir(fs_file, fs_dir->dentry);
else
error = aafs_create_file(fs_file, fs_dir->dentry);
if (error)
goto failed;
}
return 0;
failed:
aafs_remove_dir(fs_dir);
return error;
}
static void __init aafs_remove_file(struct aa_fs_entry *fs_file)
{
if (!fs_file->dentry)
return;
securityfs_remove(fs_file->dentry);
fs_file->dentry = NULL;
}
static void __init aafs_remove_dir(struct aa_fs_entry *fs_dir)
{
struct aa_fs_entry *fs_file;
for (fs_file = fs_dir->v.files; fs_file && fs_file->name; ++fs_file) {
if (fs_file->v_type == AA_FS_TYPE_DIR)
aafs_remove_dir(fs_file);
else
aafs_remove_file(fs_file);
}
aafs_remove_file(fs_dir);
}
void __init aa_destroy_aafs(void)
{
aafs_remove_dir(&aa_fs_entry);
}
static int __init aa_create_aafs(void)
{
int error;
if (!apparmor_initialized)
return 0;
if (aa_fs_entry.dentry) {
AA_ERROR("%s: AppArmor securityfs already exists\n", __func__);
return -EEXIST;
}
error = aafs_create_dir(&aa_fs_entry, NULL);
if (error)
goto error;
error = __aa_fs_namespace_mkdir(root_ns, aa_fs_entry.dentry,
"policy");
if (error)
goto error;
aa_info_message("AppArmor Filesystem Enabled");
return 0;
error:
aa_destroy_aafs();
AA_ERROR("Error creating AppArmor securityfs\n");
return error;
}
