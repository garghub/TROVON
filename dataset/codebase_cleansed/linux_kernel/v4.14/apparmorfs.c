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
static int aafs_show_path(struct seq_file *seq, struct dentry *dentry)
{
struct inode *inode = d_inode(dentry);
seq_printf(seq, "%s:[%lu]", AAFS_NAME, inode->i_ino);
return 0;
}
static void aafs_evict_inode(struct inode *inode)
{
truncate_inode_pages_final(&inode->i_data);
clear_inode(inode);
if (S_ISLNK(inode->i_mode))
kfree(inode->i_link);
}
static int fill_super(struct super_block *sb, void *data, int silent)
{
static struct tree_descr files[] = { {""} };
int error;
error = simple_fill_super(sb, AAFS_MAGIC, files);
if (error)
return error;
sb->s_op = &aafs_super_ops;
return 0;
}
static struct dentry *aafs_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
return mount_single(fs_type, flags, data, fill_super);
}
static int __aafs_setup_d_inode(struct inode *dir, struct dentry *dentry,
umode_t mode, void *data, char *link,
const struct file_operations *fops,
const struct inode_operations *iops)
{
struct inode *inode = new_inode(dir->i_sb);
AA_BUG(!dir);
AA_BUG(!dentry);
if (!inode)
return -ENOMEM;
inode->i_ino = get_next_ino();
inode->i_mode = mode;
inode->i_atime = inode->i_mtime = inode->i_ctime = current_time(inode);
inode->i_private = data;
if (S_ISDIR(mode)) {
inode->i_op = iops ? iops : &simple_dir_inode_operations;
inode->i_fop = &simple_dir_operations;
inc_nlink(inode);
inc_nlink(dir);
} else if (S_ISLNK(mode)) {
inode->i_op = iops ? iops : &simple_symlink_inode_operations;
inode->i_link = link;
} else {
inode->i_fop = fops;
}
d_instantiate(dentry, inode);
dget(dentry);
return 0;
}
static struct dentry *aafs_create(const char *name, umode_t mode,
struct dentry *parent, void *data, void *link,
const struct file_operations *fops,
const struct inode_operations *iops)
{
struct dentry *dentry;
struct inode *dir;
int error;
AA_BUG(!name);
AA_BUG(!parent);
if (!(mode & S_IFMT))
mode = (mode & S_IALLUGO) | S_IFREG;
error = simple_pin_fs(&aafs_ops, &aafs_mnt, &aafs_count);
if (error)
return ERR_PTR(error);
dir = d_inode(parent);
inode_lock(dir);
dentry = lookup_one_len(name, parent, strlen(name));
if (IS_ERR(dentry)) {
error = PTR_ERR(dentry);
goto fail_lock;
}
if (d_really_is_positive(dentry)) {
error = -EEXIST;
goto fail_dentry;
}
error = __aafs_setup_d_inode(dir, dentry, mode, data, link, fops, iops);
if (error)
goto fail_dentry;
inode_unlock(dir);
return dentry;
fail_dentry:
dput(dentry);
fail_lock:
inode_unlock(dir);
simple_release_fs(&aafs_mnt, &aafs_count);
return ERR_PTR(error);
}
static struct dentry *aafs_create_file(const char *name, umode_t mode,
struct dentry *parent, void *data,
const struct file_operations *fops)
{
return aafs_create(name, mode, parent, data, NULL, fops, NULL);
}
static struct dentry *aafs_create_dir(const char *name, struct dentry *parent)
{
return aafs_create(name, S_IFDIR | 0755, parent, NULL, NULL, NULL,
NULL);
}
static struct dentry *aafs_create_symlink(const char *name,
struct dentry *parent,
const char *target,
const struct inode_operations *iops)
{
struct dentry *dent;
char *link = NULL;
if (target) {
link = kstrdup(target, GFP_KERNEL);
if (!link)
return ERR_PTR(-ENOMEM);
}
dent = aafs_create(name, S_IFLNK | 0444, parent, NULL, link, NULL,
iops);
if (IS_ERR(dent))
kfree(link);
return dent;
}
static void aafs_remove(struct dentry *dentry)
{
struct inode *dir;
if (!dentry || IS_ERR(dentry))
return;
dir = d_inode(dentry->d_parent);
inode_lock(dir);
if (simple_positive(dentry)) {
if (d_is_dir(dentry))
simple_rmdir(dir, dentry);
else
simple_unlink(dir, dentry);
dput(dentry);
}
inode_unlock(dir);
simple_release_fs(&aafs_mnt, &aafs_count);
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
data = aa_loaddata_alloc(alloc_size);
if (IS_ERR(data))
return data;
data->size = copy_size;
if (copy_from_user(data->data, userbuf, copy_size)) {
kvfree(data);
return ERR_PTR(-EFAULT);
}
return data;
}
static ssize_t policy_update(u32 mask, const char __user *buf, size_t size,
loff_t *pos, struct aa_ns *ns)
{
struct aa_loaddata *data;
struct aa_label *label;
ssize_t error;
label = begin_current_label_crit_section();
error = aa_may_manage_policy(label, ns, mask);
if (error)
return error;
data = aa_simple_write_to_buffer(buf, size, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
error = aa_replace_profiles(ns, label, mask, data);
aa_put_loaddata(data);
}
end_current_label_crit_section(label);
return error;
}
static ssize_t profile_load(struct file *f, const char __user *buf, size_t size,
loff_t *pos)
{
struct aa_ns *ns = aa_get_ns(f->f_inode->i_private);
int error = policy_update(AA_MAY_LOAD_POLICY, buf, size, pos, ns);
aa_put_ns(ns);
return error;
}
static ssize_t profile_replace(struct file *f, const char __user *buf,
size_t size, loff_t *pos)
{
struct aa_ns *ns = aa_get_ns(f->f_inode->i_private);
int error = policy_update(AA_MAY_LOAD_POLICY | AA_MAY_REPLACE_POLICY,
buf, size, pos, ns);
aa_put_ns(ns);
return error;
}
static ssize_t profile_remove(struct file *f, const char __user *buf,
size_t size, loff_t *pos)
{
struct aa_loaddata *data;
struct aa_label *label;
ssize_t error;
struct aa_ns *ns = aa_get_ns(f->f_inode->i_private);
label = begin_current_label_crit_section();
error = aa_may_manage_policy(label, ns, AA_MAY_REMOVE_POLICY);
if (error)
goto out;
data = aa_simple_write_to_buffer(buf, size + 1, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
data->data[size] = 0;
error = aa_remove_profiles(ns, label, data->data, size);
aa_put_loaddata(data);
}
out:
end_current_label_crit_section(label);
aa_put_ns(ns);
return error;
}
static int ns_revision_release(struct inode *inode, struct file *file)
{
struct aa_revision *rev = file->private_data;
if (rev) {
aa_put_ns(rev->ns);
kfree(rev);
}
return 0;
}
static ssize_t ns_revision_read(struct file *file, char __user *buf,
size_t size, loff_t *ppos)
{
struct aa_revision *rev = file->private_data;
char buffer[32];
long last_read;
int avail;
mutex_lock(&rev->ns->lock);
last_read = rev->last_read;
if (last_read == rev->ns->revision) {
mutex_unlock(&rev->ns->lock);
if (file->f_flags & O_NONBLOCK)
return -EAGAIN;
if (wait_event_interruptible(rev->ns->wait,
last_read !=
READ_ONCE(rev->ns->revision)))
return -ERESTARTSYS;
mutex_lock(&rev->ns->lock);
}
avail = sprintf(buffer, "%ld\n", rev->ns->revision);
if (*ppos + size > avail) {
rev->last_read = rev->ns->revision;
*ppos = 0;
}
mutex_unlock(&rev->ns->lock);
return simple_read_from_buffer(buf, size, ppos, buffer, avail);
}
static int ns_revision_open(struct inode *inode, struct file *file)
{
struct aa_revision *rev = kzalloc(sizeof(*rev), GFP_KERNEL);
if (!rev)
return -ENOMEM;
rev->ns = aa_get_ns(inode->i_private);
if (!rev->ns)
rev->ns = aa_get_current_ns();
file->private_data = rev;
return 0;
}
static unsigned int ns_revision_poll(struct file *file, poll_table *pt)
{
struct aa_revision *rev = file->private_data;
unsigned int mask = 0;
if (rev) {
mutex_lock(&rev->ns->lock);
poll_wait(file, &rev->ns->wait, pt);
if (rev->last_read < rev->ns->revision)
mask |= POLLIN | POLLRDNORM;
mutex_unlock(&rev->ns->lock);
}
return mask;
}
void __aa_bump_ns_revision(struct aa_ns *ns)
{
ns->revision++;
wake_up_interruptible(&ns->wait);
}
static void profile_query_cb(struct aa_profile *profile, struct aa_perms *perms,
const char *match_str, size_t match_len)
{
struct aa_perms tmp;
struct aa_dfa *dfa;
unsigned int state = 0;
if (profile_unconfined(profile))
return;
if (profile->file.dfa && *match_str == AA_CLASS_FILE) {
dfa = profile->file.dfa;
state = aa_dfa_match_len(dfa, profile->file.start,
match_str + 1, match_len - 1);
tmp = nullperms;
if (state) {
struct path_cond cond = { };
tmp = aa_compute_fperms(dfa, state, &cond);
}
} else if (profile->policy.dfa) {
if (!PROFILE_MEDIATES_SAFE(profile, *match_str))
return;
dfa = profile->policy.dfa;
state = aa_dfa_match_len(dfa, profile->policy.start[0],
match_str, match_len);
if (state)
aa_compute_perms(dfa, state, &tmp);
else
tmp = nullperms;
}
aa_apply_modes_to_perms(profile, &tmp);
aa_perms_accum_raw(perms, &tmp);
}
static ssize_t query_data(char *buf, size_t buf_len,
char *query, size_t query_len)
{
char *out;
const char *key;
struct label_it i;
struct aa_label *label, *curr;
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
curr = begin_current_label_crit_section();
label = aa_label_parse(curr, query, GFP_KERNEL, false, false);
end_current_label_crit_section(curr);
if (IS_ERR(label))
return PTR_ERR(label);
memset(buf, 0, sizeof(bytes) + sizeof(blocks));
out = buf + sizeof(bytes) + sizeof(blocks);
blocks = 0;
label_for_each_confined(i, label, profile) {
if (!profile->data)
continue;
data = rhashtable_lookup_fast(profile->data, &key,
profile->data->p);
if (data) {
if (out + sizeof(outle32) + data->size > buf +
buf_len) {
aa_put_label(label);
return -EINVAL;
}
outle32 = __cpu_to_le32(data->size);
memcpy(out, &outle32, sizeof(outle32));
out += sizeof(outle32);
memcpy(out, data->data, data->size);
out += data->size;
blocks++;
}
}
aa_put_label(label);
outle32 = __cpu_to_le32(out - buf - sizeof(bytes));
memcpy(buf, &outle32, sizeof(outle32));
outle32 = __cpu_to_le32(blocks);
memcpy(buf + sizeof(bytes), &outle32, sizeof(outle32));
return out - buf;
}
static ssize_t query_label(char *buf, size_t buf_len,
char *query, size_t query_len, bool view_only)
{
struct aa_profile *profile;
struct aa_label *label, *curr;
char *label_name, *match_str;
size_t label_name_len, match_len;
struct aa_perms perms;
struct label_it i;
if (!query_len)
return -EINVAL;
label_name = query;
label_name_len = strnlen(query, query_len);
if (!label_name_len || label_name_len == query_len)
return -EINVAL;
match_str = label_name + label_name_len + 1;
match_len = query_len - label_name_len - 1;
curr = begin_current_label_crit_section();
label = aa_label_parse(curr, label_name, GFP_KERNEL, false, false);
end_current_label_crit_section(curr);
if (IS_ERR(label))
return PTR_ERR(label);
perms = allperms;
if (view_only) {
label_for_each_in_ns(i, labels_ns(label), label, profile) {
profile_query_cb(profile, &perms, match_str, match_len);
}
} else {
label_for_each(i, label, profile) {
profile_query_cb(profile, &perms, match_str, match_len);
}
}
aa_put_label(label);
return scnprintf(buf, buf_len,
"allow 0x%08x\ndeny 0x%08x\naudit 0x%08x\nquiet 0x%08x\n",
perms.allow, perms.deny, perms.audit, perms.quiet);
}
static void multi_transaction_kref(struct kref *kref)
{
struct multi_transaction *t;
t = container_of(kref, struct multi_transaction, count);
free_page((unsigned long) t);
}
static struct multi_transaction *
get_multi_transaction(struct multi_transaction *t)
{
if (t)
kref_get(&(t->count));
return t;
}
static void put_multi_transaction(struct multi_transaction *t)
{
if (t)
kref_put(&(t->count), multi_transaction_kref);
}
static void multi_transaction_set(struct file *file,
struct multi_transaction *new, size_t n)
{
struct multi_transaction *old;
AA_BUG(n > MULTI_TRANSACTION_LIMIT);
new->size = n;
spin_lock(&multi_transaction_lock);
old = (struct multi_transaction *) file->private_data;
file->private_data = new;
spin_unlock(&multi_transaction_lock);
put_multi_transaction(old);
}
static struct multi_transaction *multi_transaction_new(struct file *file,
const char __user *buf,
size_t size)
{
struct multi_transaction *t;
if (size > MULTI_TRANSACTION_LIMIT - 1)
return ERR_PTR(-EFBIG);
t = (struct multi_transaction *)get_zeroed_page(GFP_KERNEL);
if (!t)
return ERR_PTR(-ENOMEM);
kref_init(&t->count);
if (copy_from_user(t->data, buf, size))
return ERR_PTR(-EFAULT);
return t;
}
static ssize_t multi_transaction_read(struct file *file, char __user *buf,
size_t size, loff_t *pos)
{
struct multi_transaction *t;
ssize_t ret;
spin_lock(&multi_transaction_lock);
t = get_multi_transaction(file->private_data);
spin_unlock(&multi_transaction_lock);
if (!t)
return 0;
ret = simple_read_from_buffer(buf, size, pos, t->data, t->size);
put_multi_transaction(t);
return ret;
}
static int multi_transaction_release(struct inode *inode, struct file *file)
{
put_multi_transaction(file->private_data);
return 0;
}
static ssize_t aa_write_access(struct file *file, const char __user *ubuf,
size_t count, loff_t *ppos)
{
struct multi_transaction *t;
ssize_t len;
if (*ppos)
return -ESPIPE;
t = multi_transaction_new(file, ubuf, count);
if (IS_ERR(t))
return PTR_ERR(t);
if (count > QUERY_CMD_PROFILE_LEN &&
!memcmp(t->data, QUERY_CMD_PROFILE, QUERY_CMD_PROFILE_LEN)) {
len = query_label(t->data, MULTI_TRANSACTION_LIMIT,
t->data + QUERY_CMD_PROFILE_LEN,
count - QUERY_CMD_PROFILE_LEN, true);
} else if (count > QUERY_CMD_LABEL_LEN &&
!memcmp(t->data, QUERY_CMD_LABEL, QUERY_CMD_LABEL_LEN)) {
len = query_label(t->data, MULTI_TRANSACTION_LIMIT,
t->data + QUERY_CMD_LABEL_LEN,
count - QUERY_CMD_LABEL_LEN, true);
} else if (count > QUERY_CMD_LABELALL_LEN &&
!memcmp(t->data, QUERY_CMD_LABELALL,
QUERY_CMD_LABELALL_LEN)) {
len = query_label(t->data, MULTI_TRANSACTION_LIMIT,
t->data + QUERY_CMD_LABELALL_LEN,
count - QUERY_CMD_LABELALL_LEN, false);
} else if (count > QUERY_CMD_DATA_LEN &&
!memcmp(t->data, QUERY_CMD_DATA, QUERY_CMD_DATA_LEN)) {
len = query_data(t->data, MULTI_TRANSACTION_LIMIT,
t->data + QUERY_CMD_DATA_LEN,
count - QUERY_CMD_DATA_LEN);
} else
len = -EINVAL;
if (len < 0) {
put_multi_transaction(t);
return len;
}
multi_transaction_set(file, t, len);
return count;
}
static int aa_sfs_seq_show(struct seq_file *seq, void *v)
{
struct aa_sfs_entry *fs_file = seq->private;
if (!fs_file)
return 0;
switch (fs_file->v_type) {
case AA_SFS_TYPE_BOOLEAN:
seq_printf(seq, "%s\n", fs_file->v.boolean ? "yes" : "no");
break;
case AA_SFS_TYPE_STRING:
seq_printf(seq, "%s\n", fs_file->v.string);
break;
case AA_SFS_TYPE_U64:
seq_printf(seq, "%#08lx\n", fs_file->v.u64);
break;
default:
break;
}
return 0;
}
static int aa_sfs_seq_open(struct inode *inode, struct file *file)
{
return single_open(file, aa_sfs_seq_show, inode->i_private);
}
int (*show)(struct seq_file *, void *)
static int seq_profile_release(struct inode *inode, struct file *file)
{
struct seq_file *seq = (struct seq_file *) file->private_data;
if (seq)
aa_put_proxy(seq->private);
return single_release(inode, file);
}
static int seq_profile_name_show(struct seq_file *seq, void *v)
{
struct aa_proxy *proxy = seq->private;
struct aa_label *label = aa_get_label_rcu(&proxy->label);
struct aa_profile *profile = labels_profile(label);
seq_printf(seq, "%s\n", profile->base.name);
aa_put_label(label);
return 0;
}
static int seq_profile_mode_show(struct seq_file *seq, void *v)
{
struct aa_proxy *proxy = seq->private;
struct aa_label *label = aa_get_label_rcu(&proxy->label);
struct aa_profile *profile = labels_profile(label);
seq_printf(seq, "%s\n", aa_profile_mode_names[profile->mode]);
aa_put_label(label);
return 0;
}
static int seq_profile_attach_show(struct seq_file *seq, void *v)
{
struct aa_proxy *proxy = seq->private;
struct aa_label *label = aa_get_label_rcu(&proxy->label);
struct aa_profile *profile = labels_profile(label);
if (profile->attach)
seq_printf(seq, "%s\n", profile->attach);
else if (profile->xmatch)
seq_puts(seq, "<unknown>\n");
else
seq_printf(seq, "%s\n", profile->base.name);
aa_put_label(label);
return 0;
}
static int seq_profile_hash_show(struct seq_file *seq, void *v)
{
struct aa_proxy *proxy = seq->private;
struct aa_label *label = aa_get_label_rcu(&proxy->label);
struct aa_profile *profile = labels_profile(label);
unsigned int i, size = aa_hash_size();
if (profile->hash) {
for (i = 0; i < size; i++)
seq_printf(seq, "%.2x", profile->hash[i]);
seq_putc(seq, '\n');
}
aa_put_label(label);
return 0;
}
static int seq_ns_nsstacked_show(struct seq_file *seq, void *v)
{
struct aa_label *label;
struct aa_profile *profile;
struct label_it it;
int count = 1;
label = begin_current_label_crit_section();
if (label->size > 1) {
label_for_each(it, label, profile)
if (profile->ns != labels_ns(label)) {
count++;
break;
}
}
seq_printf(seq, "%s\n", count > 1 ? "yes" : "no");
end_current_label_crit_section(label);
return 0;
}
static int seq_ns_level_show(struct seq_file *seq, void *v)
{
struct aa_label *label;
label = begin_current_label_crit_section();
seq_printf(seq, "%d\n", labels_ns(label)->level);
end_current_label_crit_section(label);
return 0;
}
static int seq_ns_name_show(struct seq_file *seq, void *v)
{
struct aa_label *label = begin_current_label_crit_section();
seq_printf(seq, "%s\n", aa_ns_name(labels_ns(label),
labels_ns(label), true));
end_current_label_crit_section(label);
return 0;
}
int (*show)(struct seq_file *, void *)
static int seq_rawdata_release(struct inode *inode, struct file *file)
{
struct seq_file *seq = (struct seq_file *) file->private_data;
if (seq)
aa_put_loaddata(seq->private);
return single_release(inode, file);
}
static int seq_rawdata_abi_show(struct seq_file *seq, void *v)
{
struct aa_loaddata *data = seq->private;
seq_printf(seq, "v%d\n", data->abi);
return 0;
}
static int seq_rawdata_revision_show(struct seq_file *seq, void *v)
{
struct aa_loaddata *data = seq->private;
seq_printf(seq, "%ld\n", data->revision);
return 0;
}
static int seq_rawdata_hash_show(struct seq_file *seq, void *v)
{
struct aa_loaddata *data = seq->private;
unsigned int i, size = aa_hash_size();
if (data->hash) {
for (i = 0; i < size; i++)
seq_printf(seq, "%.2x", data->hash[i]);
seq_putc(seq, '\n');
}
return 0;
}
static ssize_t rawdata_read(struct file *file, char __user *buf, size_t size,
loff_t *ppos)
{
struct aa_loaddata *rawdata = file->private_data;
return simple_read_from_buffer(buf, size, ppos, rawdata->data,
rawdata->size);
}
static int rawdata_release(struct inode *inode, struct file *file)
{
aa_put_loaddata(file->private_data);
return 0;
}
static int rawdata_open(struct inode *inode, struct file *file)
{
if (!policy_view_capable(NULL))
return -EACCES;
file->private_data = __aa_get_loaddata(inode->i_private);
if (!file->private_data)
return -ENOENT;
return 0;
}
static void remove_rawdata_dents(struct aa_loaddata *rawdata)
{
int i;
for (i = 0; i < AAFS_LOADDATA_NDENTS; i++) {
if (!IS_ERR_OR_NULL(rawdata->dents[i])) {
aafs_remove(rawdata->dents[i]);
rawdata->dents[i] = NULL;
}
}
}
void __aa_fs_remove_rawdata(struct aa_loaddata *rawdata)
{
AA_BUG(rawdata->ns && !mutex_is_locked(&rawdata->ns->lock));
if (rawdata->ns) {
remove_rawdata_dents(rawdata);
list_del_init(&rawdata->list);
aa_put_ns(rawdata->ns);
rawdata->ns = NULL;
}
}
int __aa_fs_create_rawdata(struct aa_ns *ns, struct aa_loaddata *rawdata)
{
struct dentry *dent, *dir;
AA_BUG(!ns);
AA_BUG(!rawdata);
AA_BUG(!mutex_is_locked(&ns->lock));
AA_BUG(!ns_subdata_dir(ns));
rawdata->name = kasprintf(GFP_KERNEL, "%ld", ns->revision);
if (!rawdata->name)
return -ENOMEM;
dir = aafs_create_dir(rawdata->name, ns_subdata_dir(ns));
if (IS_ERR(dir))
return PTR_ERR(dir);
rawdata->dents[AAFS_LOADDATA_DIR] = dir;
dent = aafs_create_file("abi", S_IFREG | 0444, dir, rawdata,
&seq_rawdata_abi_fops);
if (IS_ERR(dent))
goto fail;
rawdata->dents[AAFS_LOADDATA_ABI] = dent;
dent = aafs_create_file("revision", S_IFREG | 0444, dir, rawdata,
&seq_rawdata_revision_fops);
if (IS_ERR(dent))
goto fail;
rawdata->dents[AAFS_LOADDATA_REVISION] = dent;
if (aa_g_hash_policy) {
dent = aafs_create_file("sha1", S_IFREG | 0444, dir,
rawdata, &seq_rawdata_hash_fops);
if (IS_ERR(dent))
goto fail;
rawdata->dents[AAFS_LOADDATA_HASH] = dent;
}
dent = aafs_create_file("raw_data", S_IFREG | 0444,
dir, rawdata, &rawdata_fops);
if (IS_ERR(dent))
goto fail;
rawdata->dents[AAFS_LOADDATA_DATA] = dent;
d_inode(dent)->i_size = rawdata->size;
rawdata->ns = aa_get_ns(ns);
list_add(&rawdata->list, &ns->rawdata_list);
return 0;
fail:
remove_rawdata_dents(rawdata);
return PTR_ERR(dent);
}
void __aafs_profile_rmdir(struct aa_profile *profile)
{
struct aa_profile *child;
int i;
if (!profile)
return;
list_for_each_entry(child, &profile->base.profiles, base.list)
__aafs_profile_rmdir(child);
for (i = AAFS_PROF_SIZEOF - 1; i >= 0; --i) {
struct aa_proxy *proxy;
if (!profile->dents[i])
continue;
proxy = d_inode(profile->dents[i])->i_private;
aafs_remove(profile->dents[i]);
aa_put_proxy(proxy);
profile->dents[i] = NULL;
}
}
void __aafs_profile_migrate_dents(struct aa_profile *old,
struct aa_profile *new)
{
int i;
AA_BUG(!old);
AA_BUG(!new);
AA_BUG(!mutex_is_locked(&profiles_ns(old)->lock));
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
struct aa_proxy *proxy = aa_get_proxy(profile->label.proxy);
struct dentry *dent;
dent = aafs_create_file(name, S_IFREG | 0444, dir, proxy, fops);
if (IS_ERR(dent))
aa_put_proxy(proxy);
return dent;
}
static int profile_depth(struct aa_profile *profile)
{
int depth = 0;
rcu_read_lock();
for (depth = 0; profile; profile = rcu_access_pointer(profile->parent))
depth++;
rcu_read_unlock();
return depth;
}
static int gen_symlink_name(char *buffer, size_t bsize, int depth,
const char *dirname, const char *fname)
{
int error;
for (; depth > 0; depth--) {
if (bsize < 7)
return -ENAMETOOLONG;
strcpy(buffer, "../../");
buffer += 6;
bsize -= 6;
}
error = snprintf(buffer, bsize, "raw_data/%s/%s", dirname, fname);
if (error >= bsize || error < 0)
return -ENAMETOOLONG;
return 0;
}
int __aafs_profile_mkdir(struct aa_profile *profile, struct dentry *parent)
{
struct aa_profile *child;
struct dentry *dent = NULL, *dir;
int error;
AA_BUG(!profile);
AA_BUG(!mutex_is_locked(&profiles_ns(profile)->lock));
if (!parent) {
struct aa_profile *p;
p = aa_deref_parent(profile);
dent = prof_dir(p);
dent = aafs_create_dir("profiles", dent);
if (IS_ERR(dent))
goto fail;
prof_child_dir(p) = parent = dent;
}
if (!profile->dirname) {
int len, id_len;
len = mangle_name(profile->base.name, NULL);
id_len = snprintf(NULL, 0, ".%ld", profile->ns->uniq_id);
profile->dirname = kmalloc(len + id_len + 1, GFP_KERNEL);
if (!profile->dirname) {
error = -ENOMEM;
goto fail2;
}
mangle_name(profile->base.name, profile->dirname);
sprintf(profile->dirname + len, ".%ld", profile->ns->uniq_id++);
}
dent = aafs_create_dir(profile->dirname, parent);
if (IS_ERR(dent))
goto fail;
prof_dir(profile) = dir = dent;
dent = create_profile_file(dir, "name", profile,
&seq_profile_name_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_NAME] = dent;
dent = create_profile_file(dir, "mode", profile,
&seq_profile_mode_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_MODE] = dent;
dent = create_profile_file(dir, "attach", profile,
&seq_profile_attach_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_ATTACH] = dent;
if (profile->hash) {
dent = create_profile_file(dir, "sha1", profile,
&seq_profile_hash_fops);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_HASH] = dent;
}
if (profile->rawdata) {
char target[64];
int depth = profile_depth(profile);
error = gen_symlink_name(target, sizeof(target), depth,
profile->rawdata->name, "sha1");
if (error < 0)
goto fail2;
dent = aafs_create_symlink("raw_sha1", dir, target, NULL);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_RAW_HASH] = dent;
error = gen_symlink_name(target, sizeof(target), depth,
profile->rawdata->name, "abi");
if (error < 0)
goto fail2;
dent = aafs_create_symlink("raw_abi", dir, target, NULL);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_RAW_ABI] = dent;
error = gen_symlink_name(target, sizeof(target), depth,
profile->rawdata->name, "raw_data");
if (error < 0)
goto fail2;
dent = aafs_create_symlink("raw_data", dir, target, NULL);
if (IS_ERR(dent))
goto fail;
profile->dents[AAFS_PROF_RAW_DATA] = dent;
}
list_for_each_entry(child, &profile->base.profiles, base.list) {
error = __aafs_profile_mkdir(child, prof_child_dir(profile));
if (error)
goto fail2;
}
return 0;
fail:
error = PTR_ERR(dent);
fail2:
__aafs_profile_rmdir(profile);
return error;
}
static int ns_mkdir_op(struct inode *dir, struct dentry *dentry, umode_t mode)
{
struct aa_ns *ns, *parent;
struct aa_label *label;
int error;
label = begin_current_label_crit_section();
error = aa_may_manage_policy(label, NULL, AA_MAY_LOAD_POLICY);
end_current_label_crit_section(label);
if (error)
return error;
parent = aa_get_ns(dir->i_private);
AA_BUG(d_inode(ns_subns_dir(parent)) != dir);
inode_unlock(dir);
error = simple_pin_fs(&aafs_ops, &aafs_mnt, &aafs_count);
mutex_lock(&parent->lock);
inode_lock_nested(dir, I_MUTEX_PARENT);
if (error)
goto out;
error = __aafs_setup_d_inode(dir, dentry, mode | S_IFDIR, NULL,
NULL, NULL, NULL);
if (error)
goto out_pin;
ns = __aa_find_or_create_ns(parent, READ_ONCE(dentry->d_name.name),
dentry);
if (IS_ERR(ns)) {
error = PTR_ERR(ns);
ns = NULL;
}
aa_put_ns(ns);
out_pin:
if (error)
simple_release_fs(&aafs_mnt, &aafs_count);
out:
mutex_unlock(&parent->lock);
aa_put_ns(parent);
return error;
}
static int ns_rmdir_op(struct inode *dir, struct dentry *dentry)
{
struct aa_ns *ns, *parent;
struct aa_label *label;
int error;
label = begin_current_label_crit_section();
error = aa_may_manage_policy(label, NULL, AA_MAY_LOAD_POLICY);
end_current_label_crit_section(label);
if (error)
return error;
parent = aa_get_ns(dir->i_private);
inode_unlock(dir);
inode_unlock(dentry->d_inode);
mutex_lock(&parent->lock);
ns = aa_get_ns(__aa_findn_ns(&parent->sub_ns, dentry->d_name.name,
dentry->d_name.len));
if (!ns) {
error = -ENOENT;
goto out;
}
AA_BUG(ns_dir(ns) != dentry);
__aa_remove_ns(ns);
aa_put_ns(ns);
out:
mutex_unlock(&parent->lock);
inode_lock_nested(dir, I_MUTEX_PARENT);
inode_lock(dentry->d_inode);
aa_put_ns(parent);
return error;
}
static void __aa_fs_list_remove_rawdata(struct aa_ns *ns)
{
struct aa_loaddata *ent, *tmp;
AA_BUG(!mutex_is_locked(&ns->lock));
list_for_each_entry_safe(ent, tmp, &ns->rawdata_list, list)
__aa_fs_remove_rawdata(ent);
}
void __aafs_ns_rmdir(struct aa_ns *ns)
{
struct aa_ns *sub;
struct aa_profile *child;
int i;
if (!ns)
return;
AA_BUG(!mutex_is_locked(&ns->lock));
list_for_each_entry(child, &ns->base.profiles, base.list)
__aafs_profile_rmdir(child);
list_for_each_entry(sub, &ns->sub_ns, base.list) {
mutex_lock(&sub->lock);
__aafs_ns_rmdir(sub);
mutex_unlock(&sub->lock);
}
__aa_fs_list_remove_rawdata(ns);
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
if (ns_subrevision(ns)) {
sub = d_inode(ns_subrevision(ns))->i_private;
aa_put_ns(sub);
}
for (i = AAFS_NS_SIZEOF - 1; i >= 0; --i) {
aafs_remove(ns->dents[i]);
ns->dents[i] = NULL;
}
}
static int __aafs_ns_mkdir_entries(struct aa_ns *ns, struct dentry *dir)
{
struct dentry *dent;
AA_BUG(!ns);
AA_BUG(!dir);
dent = aafs_create_dir("profiles", dir);
if (IS_ERR(dent))
return PTR_ERR(dent);
ns_subprofs_dir(ns) = dent;
dent = aafs_create_dir("raw_data", dir);
if (IS_ERR(dent))
return PTR_ERR(dent);
ns_subdata_dir(ns) = dent;
dent = aafs_create_file("revision", 0444, dir, ns,
&aa_fs_ns_revision_fops);
if (IS_ERR(dent))
return PTR_ERR(dent);
aa_get_ns(ns);
ns_subrevision(ns) = dent;
dent = aafs_create_file(".load", 0640, dir, ns,
&aa_fs_profile_load);
if (IS_ERR(dent))
return PTR_ERR(dent);
aa_get_ns(ns);
ns_subload(ns) = dent;
dent = aafs_create_file(".replace", 0640, dir, ns,
&aa_fs_profile_replace);
if (IS_ERR(dent))
return PTR_ERR(dent);
aa_get_ns(ns);
ns_subreplace(ns) = dent;
dent = aafs_create_file(".remove", 0640, dir, ns,
&aa_fs_profile_remove);
if (IS_ERR(dent))
return PTR_ERR(dent);
aa_get_ns(ns);
ns_subremove(ns) = dent;
dent = aafs_create("namespaces", S_IFDIR | 0755, dir, ns, NULL, NULL,
&ns_dir_inode_operations);
if (IS_ERR(dent))
return PTR_ERR(dent);
aa_get_ns(ns);
ns_subns_dir(ns) = dent;
return 0;
}
int __aafs_ns_mkdir(struct aa_ns *ns, struct dentry *parent, const char *name,
struct dentry *dent)
{
struct aa_ns *sub;
struct aa_profile *child;
struct dentry *dir;
int error;
AA_BUG(!ns);
AA_BUG(!parent);
AA_BUG(!mutex_is_locked(&ns->lock));
if (!name)
name = ns->base.name;
if (!dent) {
dent = aafs_create_dir(name, parent);
if (IS_ERR(dent))
goto fail;
} else
dget(dent);
ns_dir(ns) = dir = dent;
error = __aafs_ns_mkdir_entries(ns, dir);
if (error)
goto fail2;
list_for_each_entry(child, &ns->base.profiles, base.list) {
error = __aafs_profile_mkdir(child, ns_subprofs_dir(ns));
if (error)
goto fail2;
}
list_for_each_entry(sub, &ns->sub_ns, base.list) {
mutex_lock(&sub->lock);
error = __aafs_ns_mkdir(sub, ns_subns_dir(ns), NULL, NULL);
mutex_unlock(&sub->lock);
if (error)
goto fail2;
}
return 0;
fail:
error = PTR_ERR(dent);
fail2:
__aafs_ns_rmdir(ns);
return error;
}
static struct aa_ns *__next_ns(struct aa_ns *root, struct aa_ns *ns)
{
struct aa_ns *parent, *next;
AA_BUG(!root);
AA_BUG(!ns);
AA_BUG(ns != root && !mutex_is_locked(&ns->parent->lock));
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
AA_BUG(!root);
AA_BUG(ns && !mutex_is_locked(&ns->lock));
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
AA_BUG(!mutex_is_locked(&profiles_ns(p)->lock));
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
struct aa_ns *root = aa_get_current_ns();
loff_t l = *pos;
f->private = root;
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
aa_label_seq_xprint(f, root, &profile->label,
FLAG_SHOW_MODE | FLAG_VIEW_SUBNS, GFP_KERNEL);
seq_putc(f, '\n');
return 0;
}
static int profiles_open(struct inode *inode, struct file *file)
{
if (!policy_view_capable(NULL))
return -EACCES;
return seq_open(file, &aa_sfs_profiles_op);
}
static int profiles_release(struct inode *inode, struct file *file)
{
return seq_release(inode, file);
}
static int __init entry_create_file(struct aa_sfs_entry *fs_file,
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
static int __init entry_create_dir(struct aa_sfs_entry *fs_dir,
struct dentry *parent)
{
struct aa_sfs_entry *fs_file;
struct dentry *dir;
int error;
dir = securityfs_create_dir(fs_dir->name, parent);
if (IS_ERR(dir))
return PTR_ERR(dir);
fs_dir->dentry = dir;
for (fs_file = fs_dir->v.files; fs_file && fs_file->name; ++fs_file) {
if (fs_file->v_type == AA_SFS_TYPE_DIR)
error = entry_create_dir(fs_file, fs_dir->dentry);
else
error = entry_create_file(fs_file, fs_dir->dentry);
if (error)
goto failed;
}
return 0;
failed:
entry_remove_dir(fs_dir);
return error;
}
static void __init entry_remove_file(struct aa_sfs_entry *fs_file)
{
if (!fs_file->dentry)
return;
securityfs_remove(fs_file->dentry);
fs_file->dentry = NULL;
}
static void __init entry_remove_dir(struct aa_sfs_entry *fs_dir)
{
struct aa_sfs_entry *fs_file;
for (fs_file = fs_dir->v.files; fs_file && fs_file->name; ++fs_file) {
if (fs_file->v_type == AA_SFS_TYPE_DIR)
entry_remove_dir(fs_file);
else
entry_remove_file(fs_file);
}
entry_remove_file(fs_dir);
}
void __init aa_destroy_aafs(void)
{
entry_remove_dir(&aa_sfs_entry);
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
inode->i_atime = inode->i_mtime = inode->i_ctime = current_time(inode);
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
static const char *policy_get_link(struct dentry *dentry,
struct inode *inode,
struct delayed_call *done)
{
struct aa_ns *ns;
struct path path;
if (!dentry)
return ERR_PTR(-ECHILD);
ns = aa_get_current_ns();
path.mnt = mntget(aafs_mnt);
path.dentry = dget(ns_dir(ns));
nd_jump_link(&path);
aa_put_ns(ns);
return NULL;
}
static int ns_get_name(char *buf, size_t size, struct aa_ns *ns,
struct inode *inode)
{
int res = snprintf(buf, size, "%s:[%lu]", AAFS_NAME, inode->i_ino);
if (res < 0 || res >= size)
res = -ENOENT;
return res;
}
static int policy_readlink(struct dentry *dentry, char __user *buffer,
int buflen)
{
struct aa_ns *ns;
char name[32];
int res;
ns = aa_get_current_ns();
res = ns_get_name(name, sizeof(name), ns, d_inode(dentry));
if (res >= 0)
res = readlink_copy(buffer, buflen, name);
aa_put_ns(ns);
return res;
}
static int __init aa_create_aafs(void)
{
struct dentry *dent;
int error;
if (!apparmor_initialized)
return 0;
if (aa_sfs_entry.dentry) {
AA_ERROR("%s: AppArmor securityfs already exists\n", __func__);
return -EEXIST;
}
aafs_mnt = kern_mount(&aafs_ops);
if (IS_ERR(aafs_mnt))
panic("can't set apparmorfs up\n");
aafs_mnt->mnt_sb->s_flags &= ~MS_NOUSER;
error = entry_create_dir(&aa_sfs_entry, NULL);
if (error)
goto error;
dent = securityfs_create_file(".load", 0666, aa_sfs_entry.dentry,
NULL, &aa_fs_profile_load);
if (IS_ERR(dent)) {
error = PTR_ERR(dent);
goto error;
}
ns_subload(root_ns) = dent;
dent = securityfs_create_file(".replace", 0666, aa_sfs_entry.dentry,
NULL, &aa_fs_profile_replace);
if (IS_ERR(dent)) {
error = PTR_ERR(dent);
goto error;
}
ns_subreplace(root_ns) = dent;
dent = securityfs_create_file(".remove", 0666, aa_sfs_entry.dentry,
NULL, &aa_fs_profile_remove);
if (IS_ERR(dent)) {
error = PTR_ERR(dent);
goto error;
}
ns_subremove(root_ns) = dent;
dent = securityfs_create_file("revision", 0444, aa_sfs_entry.dentry,
NULL, &aa_fs_ns_revision_fops);
if (IS_ERR(dent)) {
error = PTR_ERR(dent);
goto error;
}
ns_subrevision(root_ns) = dent;
mutex_lock(&root_ns->lock);
error = __aafs_ns_mkdir(root_ns, aafs_mnt->mnt_root, ".policy",
aafs_mnt->mnt_root);
mutex_unlock(&root_ns->lock);
if (error)
goto error;
dent = securityfs_create_symlink("policy", aa_sfs_entry.dentry,
NULL, &policy_link_iops);
if (IS_ERR(dent)) {
error = PTR_ERR(dent);
goto error;
}
error = aa_mk_null_file(aa_sfs_entry.dentry);
if (error)
goto error;
aa_info_message("AppArmor Filesystem Enabled");
return 0;
error:
aa_destroy_aafs();
AA_ERROR("Error creating AppArmor securityfs\n");
return error;
}
