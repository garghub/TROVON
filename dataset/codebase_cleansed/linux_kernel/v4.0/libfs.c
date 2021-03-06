static inline int simple_positive(struct dentry *dentry)
{
return dentry->d_inode && !d_unhashed(dentry);
}
int simple_getattr(struct vfsmount *mnt, struct dentry *dentry,
struct kstat *stat)
{
struct inode *inode = dentry->d_inode;
generic_fillattr(inode, stat);
stat->blocks = inode->i_mapping->nrpages << (PAGE_CACHE_SHIFT - 9);
return 0;
}
int simple_statfs(struct dentry *dentry, struct kstatfs *buf)
{
buf->f_type = dentry->d_sb->s_magic;
buf->f_bsize = PAGE_CACHE_SIZE;
buf->f_namelen = NAME_MAX;
return 0;
}
int always_delete_dentry(const struct dentry *dentry)
{
return 1;
}
struct dentry *simple_lookup(struct inode *dir, struct dentry *dentry, unsigned int flags)
{
if (dentry->d_name.len > NAME_MAX)
return ERR_PTR(-ENAMETOOLONG);
if (!dentry->d_sb->s_d_op)
d_set_d_op(dentry, &simple_dentry_operations);
d_add(dentry, NULL);
return NULL;
}
int dcache_dir_open(struct inode *inode, struct file *file)
{
static struct qstr cursor_name = QSTR_INIT(".", 1);
file->private_data = d_alloc(file->f_path.dentry, &cursor_name);
return file->private_data ? 0 : -ENOMEM;
}
int dcache_dir_close(struct inode *inode, struct file *file)
{
dput(file->private_data);
return 0;
}
loff_t dcache_dir_lseek(struct file *file, loff_t offset, int whence)
{
struct dentry *dentry = file->f_path.dentry;
mutex_lock(&dentry->d_inode->i_mutex);
switch (whence) {
case 1:
offset += file->f_pos;
case 0:
if (offset >= 0)
break;
default:
mutex_unlock(&dentry->d_inode->i_mutex);
return -EINVAL;
}
if (offset != file->f_pos) {
file->f_pos = offset;
if (file->f_pos >= 2) {
struct list_head *p;
struct dentry *cursor = file->private_data;
loff_t n = file->f_pos - 2;
spin_lock(&dentry->d_lock);
list_del(&cursor->d_child);
p = dentry->d_subdirs.next;
while (n && p != &dentry->d_subdirs) {
struct dentry *next;
next = list_entry(p, struct dentry, d_child);
spin_lock_nested(&next->d_lock, DENTRY_D_LOCK_NESTED);
if (simple_positive(next))
n--;
spin_unlock(&next->d_lock);
p = p->next;
}
list_add_tail(&cursor->d_child, p);
spin_unlock(&dentry->d_lock);
}
}
mutex_unlock(&dentry->d_inode->i_mutex);
return offset;
}
static inline unsigned char dt_type(struct inode *inode)
{
return (inode->i_mode >> 12) & 15;
}
int dcache_readdir(struct file *file, struct dir_context *ctx)
{
struct dentry *dentry = file->f_path.dentry;
struct dentry *cursor = file->private_data;
struct list_head *p, *q = &cursor->d_child;
if (!dir_emit_dots(file, ctx))
return 0;
spin_lock(&dentry->d_lock);
if (ctx->pos == 2)
list_move(q, &dentry->d_subdirs);
for (p = q->next; p != &dentry->d_subdirs; p = p->next) {
struct dentry *next = list_entry(p, struct dentry, d_child);
spin_lock_nested(&next->d_lock, DENTRY_D_LOCK_NESTED);
if (!simple_positive(next)) {
spin_unlock(&next->d_lock);
continue;
}
spin_unlock(&next->d_lock);
spin_unlock(&dentry->d_lock);
if (!dir_emit(ctx, next->d_name.name, next->d_name.len,
next->d_inode->i_ino, dt_type(next->d_inode)))
return 0;
spin_lock(&dentry->d_lock);
spin_lock_nested(&next->d_lock, DENTRY_D_LOCK_NESTED);
list_move(q, p);
spin_unlock(&next->d_lock);
p = q;
ctx->pos++;
}
spin_unlock(&dentry->d_lock);
return 0;
}
ssize_t generic_read_dir(struct file *filp, char __user *buf, size_t siz, loff_t *ppos)
{
return -EISDIR;
}
struct dentry *mount_pseudo(struct file_system_type *fs_type, char *name,
const struct super_operations *ops,
const struct dentry_operations *dops, unsigned long magic)
{
struct super_block *s;
struct dentry *dentry;
struct inode *root;
struct qstr d_name = QSTR_INIT(name, strlen(name));
s = sget(fs_type, NULL, set_anon_super, MS_NOUSER, NULL);
if (IS_ERR(s))
return ERR_CAST(s);
s->s_maxbytes = MAX_LFS_FILESIZE;
s->s_blocksize = PAGE_SIZE;
s->s_blocksize_bits = PAGE_SHIFT;
s->s_magic = magic;
s->s_op = ops ? ops : &simple_super_operations;
s->s_time_gran = 1;
root = new_inode(s);
if (!root)
goto Enomem;
root->i_ino = 1;
root->i_mode = S_IFDIR | S_IRUSR | S_IWUSR;
root->i_atime = root->i_mtime = root->i_ctime = CURRENT_TIME;
dentry = __d_alloc(s, &d_name);
if (!dentry) {
iput(root);
goto Enomem;
}
d_instantiate(dentry, root);
s->s_root = dentry;
s->s_d_op = dops;
s->s_flags |= MS_ACTIVE;
return dget(s->s_root);
Enomem:
deactivate_locked_super(s);
return ERR_PTR(-ENOMEM);
}
int simple_open(struct inode *inode, struct file *file)
{
if (inode->i_private)
file->private_data = inode->i_private;
return 0;
}
int simple_link(struct dentry *old_dentry, struct inode *dir, struct dentry *dentry)
{
struct inode *inode = old_dentry->d_inode;
inode->i_ctime = dir->i_ctime = dir->i_mtime = CURRENT_TIME;
inc_nlink(inode);
ihold(inode);
dget(dentry);
d_instantiate(dentry, inode);
return 0;
}
int simple_empty(struct dentry *dentry)
{
struct dentry *child;
int ret = 0;
spin_lock(&dentry->d_lock);
list_for_each_entry(child, &dentry->d_subdirs, d_child) {
spin_lock_nested(&child->d_lock, DENTRY_D_LOCK_NESTED);
if (simple_positive(child)) {
spin_unlock(&child->d_lock);
goto out;
}
spin_unlock(&child->d_lock);
}
ret = 1;
out:
spin_unlock(&dentry->d_lock);
return ret;
}
int simple_unlink(struct inode *dir, struct dentry *dentry)
{
struct inode *inode = dentry->d_inode;
inode->i_ctime = dir->i_ctime = dir->i_mtime = CURRENT_TIME;
drop_nlink(inode);
dput(dentry);
return 0;
}
int simple_rmdir(struct inode *dir, struct dentry *dentry)
{
if (!simple_empty(dentry))
return -ENOTEMPTY;
drop_nlink(dentry->d_inode);
simple_unlink(dir, dentry);
drop_nlink(dir);
return 0;
}
int simple_rename(struct inode *old_dir, struct dentry *old_dentry,
struct inode *new_dir, struct dentry *new_dentry)
{
struct inode *inode = old_dentry->d_inode;
int they_are_dirs = d_is_dir(old_dentry);
if (!simple_empty(new_dentry))
return -ENOTEMPTY;
if (new_dentry->d_inode) {
simple_unlink(new_dir, new_dentry);
if (they_are_dirs) {
drop_nlink(new_dentry->d_inode);
drop_nlink(old_dir);
}
} else if (they_are_dirs) {
drop_nlink(old_dir);
inc_nlink(new_dir);
}
old_dir->i_ctime = old_dir->i_mtime = new_dir->i_ctime =
new_dir->i_mtime = inode->i_ctime = CURRENT_TIME;
return 0;
}
int simple_setattr(struct dentry *dentry, struct iattr *iattr)
{
struct inode *inode = dentry->d_inode;
int error;
error = inode_change_ok(inode, iattr);
if (error)
return error;
if (iattr->ia_valid & ATTR_SIZE)
truncate_setsize(inode, iattr->ia_size);
setattr_copy(inode, iattr);
mark_inode_dirty(inode);
return 0;
}
int simple_readpage(struct file *file, struct page *page)
{
clear_highpage(page);
flush_dcache_page(page);
SetPageUptodate(page);
unlock_page(page);
return 0;
}
int simple_write_begin(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned flags,
struct page **pagep, void **fsdata)
{
struct page *page;
pgoff_t index;
index = pos >> PAGE_CACHE_SHIFT;
page = grab_cache_page_write_begin(mapping, index, flags);
if (!page)
return -ENOMEM;
*pagep = page;
if (!PageUptodate(page) && (len != PAGE_CACHE_SIZE)) {
unsigned from = pos & (PAGE_CACHE_SIZE - 1);
zero_user_segments(page, 0, from, from + len, PAGE_CACHE_SIZE);
}
return 0;
}
int simple_write_end(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned copied,
struct page *page, void *fsdata)
{
struct inode *inode = page->mapping->host;
loff_t last_pos = pos + copied;
if (copied < len) {
unsigned from = pos & (PAGE_CACHE_SIZE - 1);
zero_user(page, from + copied, len - copied);
}
if (!PageUptodate(page))
SetPageUptodate(page);
if (last_pos > inode->i_size)
i_size_write(inode, last_pos);
set_page_dirty(page);
unlock_page(page);
page_cache_release(page);
return copied;
}
int simple_fill_super(struct super_block *s, unsigned long magic,
struct tree_descr *files)
{
struct inode *inode;
struct dentry *root;
struct dentry *dentry;
int i;
s->s_blocksize = PAGE_CACHE_SIZE;
s->s_blocksize_bits = PAGE_CACHE_SHIFT;
s->s_magic = magic;
s->s_op = &simple_super_operations;
s->s_time_gran = 1;
inode = new_inode(s);
if (!inode)
return -ENOMEM;
inode->i_ino = 1;
inode->i_mode = S_IFDIR | 0755;
inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;
inode->i_op = &simple_dir_inode_operations;
inode->i_fop = &simple_dir_operations;
set_nlink(inode, 2);
root = d_make_root(inode);
if (!root)
return -ENOMEM;
for (i = 0; !files->name || files->name[0]; i++, files++) {
if (!files->name)
continue;
if (unlikely(i == 1))
printk(KERN_WARNING "%s: %s passed in a files array"
"with an index of 1!\n", __func__,
s->s_type->name);
dentry = d_alloc_name(root, files->name);
if (!dentry)
goto out;
inode = new_inode(s);
if (!inode) {
dput(dentry);
goto out;
}
inode->i_mode = S_IFREG | files->mode;
inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;
inode->i_fop = files->ops;
inode->i_ino = i;
d_add(dentry, inode);
}
s->s_root = root;
return 0;
out:
d_genocide(root);
shrink_dcache_parent(root);
dput(root);
return -ENOMEM;
}
int simple_pin_fs(struct file_system_type *type, struct vfsmount **mount, int *count)
{
struct vfsmount *mnt = NULL;
spin_lock(&pin_fs_lock);
if (unlikely(!*mount)) {
spin_unlock(&pin_fs_lock);
mnt = vfs_kern_mount(type, MS_KERNMOUNT, type->name, NULL);
if (IS_ERR(mnt))
return PTR_ERR(mnt);
spin_lock(&pin_fs_lock);
if (!*mount)
*mount = mnt;
}
mntget(*mount);
++*count;
spin_unlock(&pin_fs_lock);
mntput(mnt);
return 0;
}
void simple_release_fs(struct vfsmount **mount, int *count)
{
struct vfsmount *mnt;
spin_lock(&pin_fs_lock);
mnt = *mount;
if (!--*count)
*mount = NULL;
spin_unlock(&pin_fs_lock);
mntput(mnt);
}
ssize_t simple_read_from_buffer(void __user *to, size_t count, loff_t *ppos,
const void *from, size_t available)
{
loff_t pos = *ppos;
size_t ret;
if (pos < 0)
return -EINVAL;
if (pos >= available || !count)
return 0;
if (count > available - pos)
count = available - pos;
ret = copy_to_user(to, from + pos, count);
if (ret == count)
return -EFAULT;
count -= ret;
*ppos = pos + count;
return count;
}
ssize_t simple_write_to_buffer(void *to, size_t available, loff_t *ppos,
const void __user *from, size_t count)
{
loff_t pos = *ppos;
size_t res;
if (pos < 0)
return -EINVAL;
if (pos >= available || !count)
return 0;
if (count > available - pos)
count = available - pos;
res = copy_from_user(to + pos, from, count);
if (res == count)
return -EFAULT;
count -= res;
*ppos = pos + count;
return count;
}
ssize_t memory_read_from_buffer(void *to, size_t count, loff_t *ppos,
const void *from, size_t available)
{
loff_t pos = *ppos;
if (pos < 0)
return -EINVAL;
if (pos >= available)
return 0;
if (count > available - pos)
count = available - pos;
memcpy(to, from + pos, count);
*ppos = pos + count;
return count;
}
void simple_transaction_set(struct file *file, size_t n)
{
struct simple_transaction_argresp *ar = file->private_data;
BUG_ON(n > SIMPLE_TRANSACTION_LIMIT);
smp_mb();
ar->size = n;
}
char *simple_transaction_get(struct file *file, const char __user *buf, size_t size)
{
struct simple_transaction_argresp *ar;
static DEFINE_SPINLOCK(simple_transaction_lock);
if (size > SIMPLE_TRANSACTION_LIMIT - 1)
return ERR_PTR(-EFBIG);
ar = (struct simple_transaction_argresp *)get_zeroed_page(GFP_KERNEL);
if (!ar)
return ERR_PTR(-ENOMEM);
spin_lock(&simple_transaction_lock);
if (file->private_data) {
spin_unlock(&simple_transaction_lock);
free_page((unsigned long)ar);
return ERR_PTR(-EBUSY);
}
file->private_data = ar;
spin_unlock(&simple_transaction_lock);
if (copy_from_user(ar->data, buf, size))
return ERR_PTR(-EFAULT);
return ar->data;
}
ssize_t simple_transaction_read(struct file *file, char __user *buf, size_t size, loff_t *pos)
{
struct simple_transaction_argresp *ar = file->private_data;
if (!ar)
return 0;
return simple_read_from_buffer(buf, size, pos, ar->data, ar->size);
}
int simple_transaction_release(struct inode *inode, struct file *file)
{
free_page((unsigned long)file->private_data);
return 0;
}
int simple_attr_open(struct inode *inode, struct file *file,
int (*get)(void *, u64 *), int (*set)(void *, u64),
const char *fmt)
{
struct simple_attr *attr;
attr = kmalloc(sizeof(*attr), GFP_KERNEL);
if (!attr)
return -ENOMEM;
attr->get = get;
attr->set = set;
attr->data = inode->i_private;
attr->fmt = fmt;
mutex_init(&attr->mutex);
file->private_data = attr;
return nonseekable_open(inode, file);
}
int simple_attr_release(struct inode *inode, struct file *file)
{
kfree(file->private_data);
return 0;
}
ssize_t simple_attr_read(struct file *file, char __user *buf,
size_t len, loff_t *ppos)
{
struct simple_attr *attr;
size_t size;
ssize_t ret;
attr = file->private_data;
if (!attr->get)
return -EACCES;
ret = mutex_lock_interruptible(&attr->mutex);
if (ret)
return ret;
if (*ppos) {
size = strlen(attr->get_buf);
} else {
u64 val;
ret = attr->get(attr->data, &val);
if (ret)
goto out;
size = scnprintf(attr->get_buf, sizeof(attr->get_buf),
attr->fmt, (unsigned long long)val);
}
ret = simple_read_from_buffer(buf, len, ppos, attr->get_buf, size);
out:
mutex_unlock(&attr->mutex);
return ret;
}
ssize_t simple_attr_write(struct file *file, const char __user *buf,
size_t len, loff_t *ppos)
{
struct simple_attr *attr;
u64 val;
size_t size;
ssize_t ret;
attr = file->private_data;
if (!attr->set)
return -EACCES;
ret = mutex_lock_interruptible(&attr->mutex);
if (ret)
return ret;
ret = -EFAULT;
size = min(sizeof(attr->set_buf) - 1, len);
if (copy_from_user(attr->set_buf, buf, size))
goto out;
attr->set_buf[size] = '\0';
val = simple_strtoll(attr->set_buf, NULL, 0);
ret = attr->set(attr->data, val);
if (ret == 0)
ret = len;
out:
mutex_unlock(&attr->mutex);
return ret;
}
int __generic_file_fsync(struct file *file, loff_t start, loff_t end,
int datasync)
{
struct inode *inode = file->f_mapping->host;
int err;
int ret;
err = filemap_write_and_wait_range(inode->i_mapping, start, end);
if (err)
return err;
mutex_lock(&inode->i_mutex);
ret = sync_mapping_buffers(inode->i_mapping);
if (!(inode->i_state & I_DIRTY_ALL))
goto out;
if (datasync && !(inode->i_state & I_DIRTY_DATASYNC))
goto out;
err = sync_inode_metadata(inode, 1);
if (ret == 0)
ret = err;
out:
mutex_unlock(&inode->i_mutex);
return ret;
}
int generic_file_fsync(struct file *file, loff_t start, loff_t end,
int datasync)
{
struct inode *inode = file->f_mapping->host;
int err;
err = __generic_file_fsync(file, start, end, datasync);
if (err)
return err;
return blkdev_issue_flush(inode->i_sb->s_bdev, GFP_KERNEL, NULL);
}
int generic_check_addressable(unsigned blocksize_bits, u64 num_blocks)
{
u64 last_fs_block = num_blocks - 1;
u64 last_fs_page =
last_fs_block >> (PAGE_CACHE_SHIFT - blocksize_bits);
if (unlikely(num_blocks == 0))
return 0;
if ((blocksize_bits < 9) || (blocksize_bits > PAGE_CACHE_SHIFT))
return -EINVAL;
if ((last_fs_block > (sector_t)(~0ULL) >> (blocksize_bits - 9)) ||
(last_fs_page > (pgoff_t)(~0ULL))) {
return -EFBIG;
}
return 0;
}
int noop_fsync(struct file *file, loff_t start, loff_t end, int datasync)
{
return 0;
}
void kfree_put_link(struct dentry *dentry, struct nameidata *nd,
void *cookie)
{
char *s = nd_get_link(nd);
if (!IS_ERR(s))
kfree(s);
}
static int anon_set_page_dirty(struct page *page)
{
return 0;
}
struct inode *alloc_anon_inode(struct super_block *s)
{
static const struct address_space_operations anon_aops = {
.set_page_dirty = anon_set_page_dirty,
};
struct inode *inode = new_inode_pseudo(s);
if (!inode)
return ERR_PTR(-ENOMEM);
inode->i_ino = get_next_ino();
inode->i_mapping->a_ops = &anon_aops;
inode->i_state = I_DIRTY;
inode->i_mode = S_IRUSR | S_IWUSR;
inode->i_uid = current_fsuid();
inode->i_gid = current_fsgid();
inode->i_flags |= S_PRIVATE;
inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;
return inode;
}
int
simple_nosetlease(struct file *filp, long arg, struct file_lock **flp,
void **priv)
{
return -EINVAL;
}
