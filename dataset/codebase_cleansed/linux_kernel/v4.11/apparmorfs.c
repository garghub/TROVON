static int mangle_name(const char *name, char *target)
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
static struct aa_loaddata *aa_simple_write_to_buffer(const char __user *userbuf,
size_t alloc_size,
size_t copy_size,
loff_t *pos)
{
struct aa_loaddata *data;
AA_BUG(copy_size > alloc_size);
if (*pos != 0)
return ERR_PTR(-ESPIPE);
data = kvmalloc(sizeof(*data) + alloc_size);
if (data == NULL)
return ERR_PTR(-ENOMEM);
kref_init(&data->count);
data->size = copy_size;
data->hash = NULL;
data->abi = 0;
if (copy_from_user(data->data, userbuf, copy_size)) {
kvfree(data);
return ERR_PTR(-EFAULT);
}
return data;
}
static ssize_t policy_update(int binop, const char __user *buf, size_t size,
loff_t *pos, struct aa_ns *ns)
{
ssize_t error;
struct aa_loaddata *data;
struct aa_profile *profile = aa_current_profile();
const char *op = binop == PROF_ADD ? OP_PROF_LOAD : OP_PROF_REPL;
error = aa_may_manage_policy(profile, ns, op);
if (error)
return error;
data = aa_simple_write_to_buffer(buf, size, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
error = aa_replace_profiles(ns ? ns : profile->ns, profile,
binop, data);
aa_put_loaddata(data);
}
return error;
}
static ssize_t profile_load(struct file *f, const char __user *buf, size_t size,
loff_t *pos)
{
struct aa_ns *ns = aa_get_ns(f->f_inode->i_private);
int error = policy_update(PROF_ADD, buf, size, pos, ns);
aa_put_ns(ns);
return error;
}
static ssize_t profile_replace(struct file *f, const char __user *buf,
size_t size, loff_t *pos)
{
struct aa_ns *ns = aa_get_ns(f->f_inode->i_private);
int error = policy_update(PROF_REPLACE, buf, size, pos, ns);
aa_put_ns(ns);
return error;
}
static ssize_t profile_remove(struct file *f, const char __user *buf,
size_t size, loff_t *pos)
{
struct aa_loaddata *data;
struct aa_profile *profile;
ssize_t error;
struct aa_ns *ns = aa_get_ns(f->f_inode->i_private);
profile = aa_current_profile();
error = aa_may_manage_policy(profile, ns, OP_PROF_RM);
if (error)
goto out;
data = aa_simple_write_to_buffer(buf, size + 1, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
data->data[size] = 0;
error = aa_remove_profiles(ns ? ns : profile->ns, profile,
data->data, size);
aa_put_loaddata(data);
}
out:
aa_put_ns(ns);
return error;
}
static ssize_t query_data(char *buf, size_t buf_len,
char *query, size_t query_len)
{
char *out;
const char *key;
struct aa_profile *profile;
struct aa_data *data;
u32 bytes, blocks;
__le32 outle32;
if (!query_len)
return -EINVAL;
key = query + strnlen(query, query_len) + 1;
if (key + 1 >= query + query_len)
return -EINVAL;
if (key + strnlen(key, query + query_len - key) >= query + query_len)
return -EINVAL;
if (buf_len < sizeof(bytes) + sizeof(blocks))
return -EINVAL;
profile = aa_current_profile();
memset(buf, 0, sizeof(bytes) + sizeof(blocks));
out = buf + sizeof(bytes) + sizeof(blocks);
blocks = 0;
if (profile->data) {
data = rhashtable_lookup_fast(profile->data, &key,
profile->data->p);
if (data) {
if (out + sizeof(outle32) + data->size > buf + buf_len)
return -EINVAL;
outle32 = __cpu_to_le32(data->size);
memcpy(out, &outle32, sizeof(outle32));
out += sizeof(outle32);
memcpy(out, data->data, data->size);
out += data->size;
blocks++;
}
}
outle32 = __cpu_to_le32(out - buf - sizeof(bytes));
memcpy(buf, &outle32, sizeof(outle32));
outle32 = __cpu_to_le32(blocks);
memcpy(buf + sizeof(bytes), &outle32, sizeof(outle32));
return out - buf;
}
static ssize_t aa_write_access(struct file *file, const char __user *ubuf,
size_t count, loff_t *ppos)
{
char *buf;
ssize_t len;
if (*ppos)
return -ESPIPE;
buf = simple_transaction_get(file, ubuf, count);
if (IS_ERR(buf))
return PTR_ERR(buf);
if (count > QUERY_CMD_DATA_LEN &&
!memcmp(buf, QUERY_CMD_DATA, QUERY_CMD_DATA_LEN)) {
len = query_data(buf, SIMPLE_TRANSACTION_LIMIT,
buf + QUERY_CMD_DATA_LEN,
count - QUERY_CMD_DATA_LEN);
} else
len = -EINVAL;
if (len < 0)
return len;
simple_transaction_set(file, len);
return count;
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
struct aa_proxy *proxy = aa_get_proxy(inode->i_private);
int error = single_open(file, show, proxy);
if (error) {
file->private_data = NULL;
aa_put_proxy(proxy);
}
return error;
}
static int aa_fs_seq_profile_release(struct inode *inode, struct file *file)
{
struct seq_file *seq = (struct seq_file *) file->private_data;
if (seq)
aa_put_proxy(seq->private);
return single_release(inode, file);
}
static int aa_fs_seq_profname_show(struct seq_file *seq, void *v)
{
struct aa_proxy *proxy = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&proxy->profile);
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
struct aa_proxy *proxy = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&proxy->profile);
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
struct aa_proxy *proxy = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&proxy->profile);
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
struct aa_proxy *proxy = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&proxy->profile);
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
static int aa_fs_seq_show_ns_level(struct seq_file *seq, void *v)
{
struct aa_ns *ns = aa_current_profile()->ns;
seq_printf(seq, "%d\n", ns->level);
return 0;
}
static int aa_fs_seq_open_ns_level(struct inode *inode, struct file *file)
{
return single_open(file, aa_fs_seq_show_ns_level, inode->i_private);
}
static int aa_fs_seq_show_ns_name(struct seq_file *seq, void *v)
{
struct aa_ns *ns = aa_current_profile()->ns;
seq_printf(seq, "%s\n", ns->base.name);
return 0;
}
static int aa_fs_seq_open_ns_name(struct inode *inode, struct file *file)
{
return single_open(file, aa_fs_seq_show_ns_name, inode->i_private);
}
static int rawdata_release(struct inode *inode, struct file *file)
{
aa_put_loaddata(file->private_data);
return 0;
}
static int aa_fs_seq_raw_abi_show(struct seq_file *seq, void *v)
{
struct aa_proxy *proxy = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&proxy->profile);
if (profile->rawdata->abi) {
seq_printf(seq, "v%d", profile->rawdata->abi);
seq_puts(seq, "\n");
}
aa_put_profile(profile);
return 0;
}
static int aa_fs_seq_raw_abi_open(struct inode *inode, struct file *file)
{
return aa_fs_seq_profile_open(inode, file, aa_fs_seq_raw_abi_show);
}
static int aa_fs_seq_raw_hash_show(struct seq_file *seq, void *v)
{
struct aa_proxy *proxy = seq->private;
struct aa_profile *profile = aa_get_profile_rcu(&proxy->profile);
unsigned int i, size = aa_hash_size();
if (profile->rawdata->hash) {
for (i = 0; i < size; i++)
seq_printf(seq, "%.2x", profile->rawdata->hash[i]);
seq_puts(seq, "\n");
}
aa_put_profile(profile);
return 0;
}
static int aa_fs_seq_raw_hash_open(struct inode *inode, struct file *file)
{
return aa_fs_seq_profile_open(inode, file, aa_fs_seq_raw_hash_show);
}
static ssize_t rawdata_read(struct file *file, char __user *buf, size_t size,
loff_t *ppos)
{
struct aa_loaddata *rawdata = file->private_data;
return simple_read_from_buffer(buf, size, ppos, rawdata->data,
rawdata->size);
}
static int rawdata_open(struct inode *inode, struct file *file)
{
struct aa_proxy *proxy = inode->i_private;
struct aa_profile *profile;
if (!policy_view_capable(NULL))
return -EACCES;
profile = aa_get_profile_rcu(&proxy->profile);
file->private_data = aa_get_loaddata(profile->rawdata);
aa_put_profile(profile);
return 0;
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
struct aa_proxy *proxy;
if (!profile->dents[i])
continue;
proxy = d_inode(profile->dents[i])->i_private;
securityfs_remove(profile->dents[i]);
aa_put_proxy(proxy);
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
new->dents[i]->d_inode->i_mtime = current_time(new->dents[i]->d_inode);
old->dents[i] = NULL;
}
}
static struct dentry *create_profile_file(struct dentry *dir, const char *name,
struct aa_profile *profile,
const struct file_operations *fops)
{
struct aa_proxy *proxy = aa_get_proxy(profile->proxy);
struct dentry *dent;
dent = securityfs_create_file(name, S_IFREG | 0444, dir, proxy, fops);
if (IS_ERR(dent))
aa_put_proxy(proxy);
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
if (profile->rawdata) {
dent = create_profile_file(dir, "raw_sha1", profile,
&aa_fs_seq_raw_hash_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_RAW_HASH] = dent;
dent = create_profile_file(dir, "raw_abi", profile,
&aa_fs_seq_raw_abi_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_RAW_ABI] = dent;
dent = securityfs_create_file("raw_data", S_IFREG | 0444, dir,
profile->proxy,
&aa_fs_rawdata_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_RAW_DATA] = dent;
d_inode(dent)->i_size = profile->rawdata->size;
aa_get_proxy(profile->proxy);
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
void __aa_fs_ns_rmdir(struct aa_ns *ns)
{
struct aa_ns *sub;
struct aa_profile *child;
int i;
if (!ns)
return;
list_for_each_entry(child, &ns->base.profiles, base.list)
__aa_fs_profile_rmdir(child);
list_for_each_entry(sub, &ns->sub_ns, base.list) {
mutex_lock(&sub->lock);
__aa_fs_ns_rmdir(sub);
mutex_unlock(&sub->lock);
}
if (ns_subns_dir(ns)) {
sub = d_inode(ns_subns_dir(ns))->i_private;
aa_put_ns(sub);
}
if (ns_subload(ns)) {
sub = d_inode(ns_subload(ns))->i_private;
aa_put_ns(sub);
}
if (ns_subreplace(ns)) {
sub = d_inode(ns_subreplace(ns))->i_private;
aa_put_ns(sub);
}
if (ns_subremove(ns)) {
sub = d_inode(ns_subremove(ns))->i_private;
aa_put_ns(sub);
}
for (i = AAFS_NS_SIZEOF - 1; i >= 0; --i) {
securityfs_remove(ns->dents[i]);
ns->dents[i] = NULL;
}
}
static int __aa_fs_ns_mkdir_entries(struct aa_ns *ns, struct dentry *dir)
{
struct dentry *dent;
AA_BUG(!ns);
AA_BUG(!dir);
dent = securityfs_create_dir("profiles", dir);
if (IS_ERR(dent))
return PTR_ERR(dent);
ns_subprofs_dir(ns) = dent;
dent = securityfs_create_dir("raw_data", dir);
if (IS_ERR(dent))
return PTR_ERR(dent);
ns_subdata_dir(ns) = dent;
dent = securityfs_create_file(".load", 0640, dir, ns,
&aa_fs_profile_load);
if (IS_ERR(dent))
return PTR_ERR(dent);
aa_get_ns(ns);
ns_subload(ns) = dent;
dent = securityfs_create_file(".replace", 0640, dir, ns,
&aa_fs_profile_replace);
if (IS_ERR(dent))
return PTR_ERR(dent);
aa_get_ns(ns);
ns_subreplace(ns) = dent;
dent = securityfs_create_file(".remove", 0640, dir, ns,
&aa_fs_profile_remove);
if (IS_ERR(dent))
return PTR_ERR(dent);
aa_get_ns(ns);
ns_subremove(ns) = dent;
dent = securityfs_create_dir("namespaces", dir);
if (IS_ERR(dent))
return PTR_ERR(dent);
aa_get_ns(ns);
ns_subns_dir(ns) = dent;
return 0;
}
int __aa_fs_ns_mkdir(struct aa_ns *ns, struct dentry *parent, const char *name)
{
struct aa_ns *sub;
struct aa_profile *child;
struct dentry *dent, *dir;
int error;
AA_BUG(!ns);
AA_BUG(!parent);
AA_BUG(!mutex_is_locked(&ns->lock));
if (!name)
name = ns->base.name;
dent = securityfs_create_dir(name, parent);
if (IS_ERR(dent))
goto fail;
ns_dir(ns) = dir = dent;
error = __aa_fs_ns_mkdir_entries(ns, dir);
if (error)
goto fail2;
list_for_each_entry(child, &ns->base.profiles, base.list) {
error = __aa_fs_profile_mkdir(child, ns_subprofs_dir(ns));
if (error)
goto fail2;
}
list_for_each_entry(sub, &ns->sub_ns, base.list) {
mutex_lock(&sub->lock);
error = __aa_fs_ns_mkdir(sub, ns_subns_dir(ns), NULL);
mutex_unlock(&sub->lock);
if (error)
goto fail2;
}
return 0;
fail:
error = PTR_ERR(dent);
fail2:
__aa_fs_ns_rmdir(ns);
return error;
}
static struct aa_ns *__next_ns(struct aa_ns *root, struct aa_ns *ns)
{
struct aa_ns *parent, *next;
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
static struct aa_profile *__first_profile(struct aa_ns *root,
struct aa_ns *ns)
{
for (; ns; ns = __next_ns(root, ns)) {
if (!list_empty(&ns->base.profiles))
return list_first_entry(&ns->base.profiles,
struct aa_profile, base.list);
}
return NULL;
}
static struct aa_profile *__next_profile(struct aa_profile *p)
{
struct aa_profile *parent;
struct aa_ns *ns = p->ns;
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
static struct aa_profile *next_profile(struct aa_ns *root,
struct aa_profile *profile)
{
struct aa_profile *next = __next_profile(profile);
if (next)
return next;
return __first_profile(root, __next_ns(root, profile->ns));
}
static void *p_start(struct seq_file *f, loff_t *pos)
{
struct aa_profile *profile = NULL;
struct aa_ns *root = aa_current_profile()->ns;
loff_t l = *pos;
f->private = aa_get_ns(root);
mutex_lock(&root->lock);
profile = __first_profile(root, root);
for (; profile && l > 0; l--)
profile = next_profile(root, profile);
return profile;
}
static void *p_next(struct seq_file *f, void *p, loff_t *pos)
{
struct aa_profile *profile = p;
struct aa_ns *ns = f->private;
(*pos)++;
return next_profile(ns, profile);
}
static void p_stop(struct seq_file *f, void *p)
{
struct aa_profile *profile = p;
struct aa_ns *root = f->private, *ns;
if (profile) {
for (ns = profile->ns; ns && ns != root; ns = ns->parent)
mutex_unlock(&ns->lock);
}
mutex_unlock(&root->lock);
aa_put_ns(root);
}
static int seq_show_profile(struct seq_file *f, void *p)
{
struct aa_profile *profile = (struct aa_profile *)p;
struct aa_ns *root = f->private;
if (profile->ns != root)
seq_printf(f, ":%s://", aa_ns_name(root, profile->ns, true));
seq_printf(f, "%s (%s)\n", profile->base.hname,
aa_profile_mode_names[profile->mode]);
return 0;
}
static int profiles_open(struct inode *inode, struct file *file)
{
if (!policy_view_capable(NULL))
return -EACCES;
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
static int aa_mk_null_file(struct dentry *parent)
{
struct vfsmount *mount = NULL;
struct dentry *dentry;
struct inode *inode;
int count = 0;
int error = simple_pin_fs(parent->d_sb->s_type, &mount, &count);
if (error)
return error;
inode_lock(d_inode(parent));
dentry = lookup_one_len(NULL_FILE_NAME, parent, strlen(NULL_FILE_NAME));
if (IS_ERR(dentry)) {
error = PTR_ERR(dentry);
goto out;
}
inode = new_inode(parent->d_inode->i_sb);
if (!inode) {
error = -ENOMEM;
goto out1;
}
inode->i_ino = get_next_ino();
inode->i_mode = S_IFCHR | S_IRUGO | S_IWUGO;
inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;
init_special_inode(inode, S_IFCHR | S_IRUGO | S_IWUGO,
MKDEV(MEM_MAJOR, 3));
d_instantiate(dentry, inode);
aa_null.dentry = dget(dentry);
aa_null.mnt = mntget(mount);
error = 0;
out1:
dput(dentry);
out:
inode_unlock(d_inode(parent));
simple_release_fs(&mount, &count);
return error;
}
static int __init aa_create_aafs(void)
{
struct dentry *dent;
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
dent = securityfs_create_file(".load", 0666, aa_fs_entry.dentry,
NULL, &aa_fs_profile_load);
if (IS_ERR(dent)) {
error = PTR_ERR(dent);
goto error;
}
ns_subload(root_ns) = dent;
dent = securityfs_create_file(".replace", 0666, aa_fs_entry.dentry,
NULL, &aa_fs_profile_replace);
if (IS_ERR(dent)) {
error = PTR_ERR(dent);
goto error;
}
ns_subreplace(root_ns) = dent;
dent = securityfs_create_file(".remove", 0666, aa_fs_entry.dentry,
NULL, &aa_fs_profile_remove);
if (IS_ERR(dent)) {
error = PTR_ERR(dent);
goto error;
}
ns_subremove(root_ns) = dent;
mutex_lock(&root_ns->lock);
error = __aa_fs_ns_mkdir(root_ns, aa_fs_entry.dentry, "policy");
mutex_unlock(&root_ns->lock);
if (error)
goto error;
error = aa_mk_null_file(aa_fs_entry.dentry);
if (error)
goto error;
aa_info_message("AppArmor Filesystem Enabled");
return 0;
error:
aa_destroy_aafs();
AA_ERROR("Error creating AppArmor securityfs\n");
return error;
}
