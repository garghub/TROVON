static int qibfs_mknod(struct inode *dir, struct dentry *dentry,
umode_t mode, const struct file_operations *fops,
void *data)
{
int error;
struct inode *inode = new_inode(dir->i_sb);
if (!inode) {
error = -EPERM;
goto bail;
}
inode->i_ino = get_next_ino();
inode->i_mode = mode;
inode->i_uid = GLOBAL_ROOT_UID;
inode->i_gid = GLOBAL_ROOT_GID;
inode->i_blocks = 0;
inode->i_atime = CURRENT_TIME;
inode->i_mtime = inode->i_atime;
inode->i_ctime = inode->i_atime;
inode->i_private = data;
if (S_ISDIR(mode)) {
inode->i_op = &simple_dir_inode_operations;
inc_nlink(inode);
inc_nlink(dir);
}
inode->i_fop = fops;
d_instantiate(dentry, inode);
error = 0;
bail:
return error;
}
static int create_file(const char *name, umode_t mode,
struct dentry *parent, struct dentry **dentry,
const struct file_operations *fops, void *data)
{
int error;
inode_lock(d_inode(parent));
*dentry = lookup_one_len(name, parent, strlen(name));
if (!IS_ERR(*dentry))
error = qibfs_mknod(d_inode(parent), *dentry,
mode, fops, data);
else
error = PTR_ERR(*dentry);
inode_unlock(d_inode(parent));
return error;
}
static ssize_t driver_stats_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
qib_stats.sps_ints = qib_sps_ints();
return simple_read_from_buffer(buf, count, ppos, &qib_stats,
sizeof(qib_stats));
}
static ssize_t driver_names_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
return simple_read_from_buffer(buf, count, ppos, qib_statnames,
sizeof(qib_statnames) - 1);
}
static ssize_t dev_counters_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
u64 *counters;
size_t avail;
struct qib_devdata *dd = private2dd(file);
avail = dd->f_read_cntrs(dd, *ppos, NULL, &counters);
return simple_read_from_buffer(buf, count, ppos, counters, avail);
}
static ssize_t dev_names_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
char *names;
size_t avail;
struct qib_devdata *dd = private2dd(file);
avail = dd->f_read_cntrs(dd, *ppos, &names, NULL);
return simple_read_from_buffer(buf, count, ppos, names, avail);
}
static ssize_t portnames_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
char *names;
size_t avail;
struct qib_devdata *dd = private2dd(file);
avail = dd->f_read_portcntrs(dd, *ppos, 0, &names, NULL);
return simple_read_from_buffer(buf, count, ppos, names, avail);
}
static ssize_t portcntrs_1_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
u64 *counters;
size_t avail;
struct qib_devdata *dd = private2dd(file);
avail = dd->f_read_portcntrs(dd, *ppos, 0, NULL, &counters);
return simple_read_from_buffer(buf, count, ppos, counters, avail);
}
static ssize_t portcntrs_2_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
u64 *counters;
size_t avail;
struct qib_devdata *dd = private2dd(file);
avail = dd->f_read_portcntrs(dd, *ppos, 1, NULL, &counters);
return simple_read_from_buffer(buf, count, ppos, counters, avail);
}
static ssize_t qsfp_1_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct qib_devdata *dd = private2dd(file);
char *tmp;
int ret;
tmp = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!tmp)
return -ENOMEM;
ret = qib_qsfp_dump(dd->pport, tmp, PAGE_SIZE);
if (ret > 0)
ret = simple_read_from_buffer(buf, count, ppos, tmp, ret);
kfree(tmp);
return ret;
}
static ssize_t qsfp_2_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct qib_devdata *dd = private2dd(file);
char *tmp;
int ret;
if (dd->num_pports < 2)
return -ENODEV;
tmp = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!tmp)
return -ENOMEM;
ret = qib_qsfp_dump(dd->pport + 1, tmp, PAGE_SIZE);
if (ret > 0)
ret = simple_read_from_buffer(buf, count, ppos, tmp, ret);
kfree(tmp);
return ret;
}
static ssize_t flash_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct qib_devdata *dd;
ssize_t ret;
loff_t pos;
char *tmp;
pos = *ppos;
if (pos < 0) {
ret = -EINVAL;
goto bail;
}
if (pos >= sizeof(struct qib_flash)) {
ret = 0;
goto bail;
}
if (count > sizeof(struct qib_flash) - pos)
count = sizeof(struct qib_flash) - pos;
tmp = kmalloc(count, GFP_KERNEL);
if (!tmp) {
ret = -ENOMEM;
goto bail;
}
dd = private2dd(file);
if (qib_eeprom_read(dd, pos, tmp, count)) {
qib_dev_err(dd, "failed to read from flash\n");
ret = -ENXIO;
goto bail_tmp;
}
if (copy_to_user(buf, tmp, count)) {
ret = -EFAULT;
goto bail_tmp;
}
*ppos = pos + count;
ret = count;
bail_tmp:
kfree(tmp);
bail:
return ret;
}
static ssize_t flash_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct qib_devdata *dd;
ssize_t ret;
loff_t pos;
char *tmp;
pos = *ppos;
if (pos != 0) {
ret = -EINVAL;
goto bail;
}
if (count != sizeof(struct qib_flash)) {
ret = -EINVAL;
goto bail;
}
tmp = kmalloc(count, GFP_KERNEL);
if (!tmp) {
ret = -ENOMEM;
goto bail;
}
if (copy_from_user(tmp, buf, count)) {
ret = -EFAULT;
goto bail_tmp;
}
dd = private2dd(file);
if (qib_eeprom_write(dd, pos, tmp, count)) {
ret = -ENXIO;
qib_dev_err(dd, "failed to write to flash\n");
goto bail_tmp;
}
*ppos = pos + count;
ret = count;
bail_tmp:
kfree(tmp);
bail:
return ret;
}
static int add_cntr_files(struct super_block *sb, struct qib_devdata *dd)
{
struct dentry *dir, *tmp;
char unit[10];
int ret, i;
snprintf(unit, sizeof(unit), "%u", dd->unit);
ret = create_file(unit, S_IFDIR|S_IRUGO|S_IXUGO, sb->s_root, &dir,
&simple_dir_operations, dd);
if (ret) {
pr_err("create_file(%s) failed: %d\n", unit, ret);
goto bail;
}
ret = create_file("counters", S_IFREG|S_IRUGO, dir, &tmp,
&cntr_ops[0], dd);
if (ret) {
pr_err("create_file(%s/counters) failed: %d\n",
unit, ret);
goto bail;
}
ret = create_file("counter_names", S_IFREG|S_IRUGO, dir, &tmp,
&cntr_ops[1], dd);
if (ret) {
pr_err("create_file(%s/counter_names) failed: %d\n",
unit, ret);
goto bail;
}
ret = create_file("portcounter_names", S_IFREG|S_IRUGO, dir, &tmp,
&portcntr_ops[0], dd);
if (ret) {
pr_err("create_file(%s/%s) failed: %d\n",
unit, "portcounter_names", ret);
goto bail;
}
for (i = 1; i <= dd->num_pports; i++) {
char fname[24];
sprintf(fname, "port%dcounters", i);
ret = create_file(fname, S_IFREG|S_IRUGO, dir, &tmp,
&portcntr_ops[i], dd);
if (ret) {
pr_err("create_file(%s/%s) failed: %d\n",
unit, fname, ret);
goto bail;
}
if (!(dd->flags & QIB_HAS_QSFP))
continue;
sprintf(fname, "qsfp%d", i);
ret = create_file(fname, S_IFREG|S_IRUGO, dir, &tmp,
&qsfp_ops[i - 1], dd);
if (ret) {
pr_err("create_file(%s/%s) failed: %d\n",
unit, fname, ret);
goto bail;
}
}
ret = create_file("flash", S_IFREG|S_IWUSR|S_IRUGO, dir, &tmp,
&flash_ops, dd);
if (ret)
pr_err("create_file(%s/flash) failed: %d\n",
unit, ret);
bail:
return ret;
}
static int remove_file(struct dentry *parent, char *name)
{
struct dentry *tmp;
int ret;
tmp = lookup_one_len(name, parent, strlen(name));
if (IS_ERR(tmp)) {
ret = PTR_ERR(tmp);
goto bail;
}
spin_lock(&tmp->d_lock);
if (simple_positive(tmp)) {
__d_drop(tmp);
spin_unlock(&tmp->d_lock);
simple_unlink(d_inode(parent), tmp);
} else {
spin_unlock(&tmp->d_lock);
}
dput(tmp);
ret = 0;
bail:
return ret;
}
static int remove_device_files(struct super_block *sb,
struct qib_devdata *dd)
{
struct dentry *dir, *root;
char unit[10];
int ret, i;
root = dget(sb->s_root);
inode_lock(d_inode(root));
snprintf(unit, sizeof(unit), "%u", dd->unit);
dir = lookup_one_len(unit, root, strlen(unit));
if (IS_ERR(dir)) {
ret = PTR_ERR(dir);
pr_err("Lookup of %s failed\n", unit);
goto bail;
}
inode_lock(d_inode(dir));
remove_file(dir, "counters");
remove_file(dir, "counter_names");
remove_file(dir, "portcounter_names");
for (i = 0; i < dd->num_pports; i++) {
char fname[24];
sprintf(fname, "port%dcounters", i + 1);
remove_file(dir, fname);
if (dd->flags & QIB_HAS_QSFP) {
sprintf(fname, "qsfp%d", i + 1);
remove_file(dir, fname);
}
}
remove_file(dir, "flash");
inode_unlock(d_inode(dir));
ret = simple_rmdir(d_inode(root), dir);
d_delete(dir);
dput(dir);
bail:
inode_unlock(d_inode(root));
dput(root);
return ret;
}
static int qibfs_fill_super(struct super_block *sb, void *data, int silent)
{
struct qib_devdata *dd, *tmp;
unsigned long flags;
int ret;
static struct tree_descr files[] = {
[2] = {"driver_stats", &driver_ops[0], S_IRUGO},
[3] = {"driver_stats_names", &driver_ops[1], S_IRUGO},
{""},
};
ret = simple_fill_super(sb, QIBFS_MAGIC, files);
if (ret) {
pr_err("simple_fill_super failed: %d\n", ret);
goto bail;
}
spin_lock_irqsave(&qib_devs_lock, flags);
list_for_each_entry_safe(dd, tmp, &qib_dev_list, list) {
spin_unlock_irqrestore(&qib_devs_lock, flags);
ret = add_cntr_files(sb, dd);
if (ret)
goto bail;
spin_lock_irqsave(&qib_devs_lock, flags);
}
spin_unlock_irqrestore(&qib_devs_lock, flags);
bail:
return ret;
}
static struct dentry *qibfs_mount(struct file_system_type *fs_type, int flags,
const char *dev_name, void *data)
{
struct dentry *ret;
ret = mount_single(fs_type, flags, data, qibfs_fill_super);
if (!IS_ERR(ret))
qib_super = ret->d_sb;
return ret;
}
static void qibfs_kill_super(struct super_block *s)
{
kill_litter_super(s);
qib_super = NULL;
}
int qibfs_add(struct qib_devdata *dd)
{
int ret;
if (qib_super == NULL)
ret = 0;
else
ret = add_cntr_files(qib_super, dd);
return ret;
}
int qibfs_remove(struct qib_devdata *dd)
{
int ret = 0;
if (qib_super)
ret = remove_device_files(qib_super, dd);
return ret;
}
int __init qib_init_qibfs(void)
{
return register_filesystem(&qibfs_fs_type);
}
int __exit qib_exit_qibfs(void)
{
return unregister_filesystem(&qibfs_fs_type);
}
