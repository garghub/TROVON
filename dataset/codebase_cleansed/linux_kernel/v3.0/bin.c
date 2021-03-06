static int
fill_read(struct file *file, char *buffer, loff_t off, size_t count)
{
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
struct bin_attribute *attr = attr_sd->s_bin_attr.bin_attr;
struct kobject *kobj = attr_sd->s_parent->s_dir.kobj;
int rc;
if (!sysfs_get_active(attr_sd))
return -ENODEV;
rc = -EIO;
if (attr->read)
rc = attr->read(file, kobj, attr, buffer, off, count);
sysfs_put_active(attr_sd);
return rc;
}
static ssize_t
read(struct file *file, char __user *userbuf, size_t bytes, loff_t *off)
{
struct bin_buffer *bb = file->private_data;
int size = file->f_path.dentry->d_inode->i_size;
loff_t offs = *off;
int count = min_t(size_t, bytes, PAGE_SIZE);
char *temp;
if (!bytes)
return 0;
if (size) {
if (offs > size)
return 0;
if (offs + count > size)
count = size - offs;
}
temp = kmalloc(count, GFP_KERNEL);
if (!temp)
return -ENOMEM;
mutex_lock(&bb->mutex);
count = fill_read(file, bb->buffer, offs, count);
if (count < 0) {
mutex_unlock(&bb->mutex);
goto out_free;
}
memcpy(temp, bb->buffer, count);
mutex_unlock(&bb->mutex);
if (copy_to_user(userbuf, temp, count)) {
count = -EFAULT;
goto out_free;
}
pr_debug("offs = %lld, *off = %lld, count = %d\n", offs, *off, count);
*off = offs + count;
out_free:
kfree(temp);
return count;
}
static int
flush_write(struct file *file, char *buffer, loff_t offset, size_t count)
{
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
struct bin_attribute *attr = attr_sd->s_bin_attr.bin_attr;
struct kobject *kobj = attr_sd->s_parent->s_dir.kobj;
int rc;
if (!sysfs_get_active(attr_sd))
return -ENODEV;
rc = -EIO;
if (attr->write)
rc = attr->write(file, kobj, attr, buffer, offset, count);
sysfs_put_active(attr_sd);
return rc;
}
static ssize_t write(struct file *file, const char __user *userbuf,
size_t bytes, loff_t *off)
{
struct bin_buffer *bb = file->private_data;
int size = file->f_path.dentry->d_inode->i_size;
loff_t offs = *off;
int count = min_t(size_t, bytes, PAGE_SIZE);
char *temp;
if (!bytes)
return 0;
if (size) {
if (offs > size)
return 0;
if (offs + count > size)
count = size - offs;
}
temp = memdup_user(userbuf, count);
if (IS_ERR(temp))
return PTR_ERR(temp);
mutex_lock(&bb->mutex);
memcpy(bb->buffer, temp, count);
count = flush_write(file, bb->buffer, offs, count);
mutex_unlock(&bb->mutex);
if (count > 0)
*off = offs + count;
kfree(temp);
return count;
}
static void bin_vma_open(struct vm_area_struct *vma)
{
struct file *file = vma->vm_file;
struct bin_buffer *bb = file->private_data;
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
if (!bb->vm_ops)
return;
if (!sysfs_get_active(attr_sd))
return;
if (bb->vm_ops->open)
bb->vm_ops->open(vma);
sysfs_put_active(attr_sd);
}
static int bin_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct file *file = vma->vm_file;
struct bin_buffer *bb = file->private_data;
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
int ret;
if (!bb->vm_ops)
return VM_FAULT_SIGBUS;
if (!sysfs_get_active(attr_sd))
return VM_FAULT_SIGBUS;
ret = VM_FAULT_SIGBUS;
if (bb->vm_ops->fault)
ret = bb->vm_ops->fault(vma, vmf);
sysfs_put_active(attr_sd);
return ret;
}
static int bin_page_mkwrite(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct file *file = vma->vm_file;
struct bin_buffer *bb = file->private_data;
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
int ret;
if (!bb->vm_ops)
return VM_FAULT_SIGBUS;
if (!sysfs_get_active(attr_sd))
return VM_FAULT_SIGBUS;
ret = 0;
if (bb->vm_ops->page_mkwrite)
ret = bb->vm_ops->page_mkwrite(vma, vmf);
sysfs_put_active(attr_sd);
return ret;
}
static int bin_access(struct vm_area_struct *vma, unsigned long addr,
void *buf, int len, int write)
{
struct file *file = vma->vm_file;
struct bin_buffer *bb = file->private_data;
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
int ret;
if (!bb->vm_ops)
return -EINVAL;
if (!sysfs_get_active(attr_sd))
return -EINVAL;
ret = -EINVAL;
if (bb->vm_ops->access)
ret = bb->vm_ops->access(vma, addr, buf, len, write);
sysfs_put_active(attr_sd);
return ret;
}
static int bin_set_policy(struct vm_area_struct *vma, struct mempolicy *new)
{
struct file *file = vma->vm_file;
struct bin_buffer *bb = file->private_data;
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
int ret;
if (!bb->vm_ops)
return 0;
if (!sysfs_get_active(attr_sd))
return -EINVAL;
ret = 0;
if (bb->vm_ops->set_policy)
ret = bb->vm_ops->set_policy(vma, new);
sysfs_put_active(attr_sd);
return ret;
}
static struct mempolicy *bin_get_policy(struct vm_area_struct *vma,
unsigned long addr)
{
struct file *file = vma->vm_file;
struct bin_buffer *bb = file->private_data;
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
struct mempolicy *pol;
if (!bb->vm_ops)
return vma->vm_policy;
if (!sysfs_get_active(attr_sd))
return vma->vm_policy;
pol = vma->vm_policy;
if (bb->vm_ops->get_policy)
pol = bb->vm_ops->get_policy(vma, addr);
sysfs_put_active(attr_sd);
return pol;
}
static int bin_migrate(struct vm_area_struct *vma, const nodemask_t *from,
const nodemask_t *to, unsigned long flags)
{
struct file *file = vma->vm_file;
struct bin_buffer *bb = file->private_data;
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
int ret;
if (!bb->vm_ops)
return 0;
if (!sysfs_get_active(attr_sd))
return 0;
ret = 0;
if (bb->vm_ops->migrate)
ret = bb->vm_ops->migrate(vma, from, to, flags);
sysfs_put_active(attr_sd);
return ret;
}
static int mmap(struct file *file, struct vm_area_struct *vma)
{
struct bin_buffer *bb = file->private_data;
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
struct bin_attribute *attr = attr_sd->s_bin_attr.bin_attr;
struct kobject *kobj = attr_sd->s_parent->s_dir.kobj;
int rc;
mutex_lock(&bb->mutex);
rc = -ENODEV;
if (!sysfs_get_active(attr_sd))
goto out_unlock;
rc = -EINVAL;
if (!attr->mmap)
goto out_put;
rc = attr->mmap(file, kobj, attr, vma);
if (rc)
goto out_put;
if (vma->vm_file != file)
goto out_put;
rc = -EINVAL;
if (bb->mmapped && bb->vm_ops != vma->vm_ops)
goto out_put;
rc = -EINVAL;
if (vma->vm_ops && vma->vm_ops->close)
goto out_put;
rc = 0;
bb->mmapped = 1;
bb->vm_ops = vma->vm_ops;
vma->vm_ops = &bin_vm_ops;
out_put:
sysfs_put_active(attr_sd);
out_unlock:
mutex_unlock(&bb->mutex);
return rc;
}
static int open(struct inode * inode, struct file * file)
{
struct sysfs_dirent *attr_sd = file->f_path.dentry->d_fsdata;
struct bin_attribute *attr = attr_sd->s_bin_attr.bin_attr;
struct bin_buffer *bb = NULL;
int error;
if (!sysfs_get_active(attr_sd))
return -ENODEV;
error = -EACCES;
if ((file->f_mode & FMODE_WRITE) && !(attr->write || attr->mmap))
goto err_out;
if ((file->f_mode & FMODE_READ) && !(attr->read || attr->mmap))
goto err_out;
error = -ENOMEM;
bb = kzalloc(sizeof(*bb), GFP_KERNEL);
if (!bb)
goto err_out;
bb->buffer = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!bb->buffer)
goto err_out;
mutex_init(&bb->mutex);
bb->file = file;
file->private_data = bb;
mutex_lock(&sysfs_bin_lock);
hlist_add_head(&bb->list, &attr_sd->s_bin_attr.buffers);
mutex_unlock(&sysfs_bin_lock);
sysfs_put_active(attr_sd);
return 0;
err_out:
sysfs_put_active(attr_sd);
kfree(bb);
return error;
}
static int release(struct inode * inode, struct file * file)
{
struct bin_buffer *bb = file->private_data;
mutex_lock(&sysfs_bin_lock);
hlist_del(&bb->list);
mutex_unlock(&sysfs_bin_lock);
kfree(bb->buffer);
kfree(bb);
return 0;
}
void unmap_bin_file(struct sysfs_dirent *attr_sd)
{
struct bin_buffer *bb;
struct hlist_node *tmp;
if (sysfs_type(attr_sd) != SYSFS_KOBJ_BIN_ATTR)
return;
mutex_lock(&sysfs_bin_lock);
hlist_for_each_entry(bb, tmp, &attr_sd->s_bin_attr.buffers, list) {
struct inode *inode = bb->file->f_path.dentry->d_inode;
unmap_mapping_range(inode->i_mapping, 0, 0, 1);
}
mutex_unlock(&sysfs_bin_lock);
}
int sysfs_create_bin_file(struct kobject *kobj,
const struct bin_attribute *attr)
{
BUG_ON(!kobj || !kobj->sd || !attr);
return sysfs_add_file(kobj->sd, &attr->attr, SYSFS_KOBJ_BIN_ATTR);
}
void sysfs_remove_bin_file(struct kobject *kobj,
const struct bin_attribute *attr)
{
sysfs_hash_and_remove(kobj->sd, NULL, attr->attr.name);
}
