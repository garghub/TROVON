static void do_cleanup(void)
{
struct gntalloc_gref *gref, *n;
list_for_each_entry_safe(gref, n, &gref_list, next_gref) {
if (!gref->users)
__del_gref(gref);
}
}
static int add_grefs(struct ioctl_gntalloc_alloc_gref *op,
uint32_t *gref_ids, struct gntalloc_file_private_data *priv)
{
int i, rc, readonly;
LIST_HEAD(queue_gref);
LIST_HEAD(queue_file);
struct gntalloc_gref *gref;
readonly = !(op->flags & GNTALLOC_FLAG_WRITABLE);
rc = -ENOMEM;
for (i = 0; i < op->count; i++) {
gref = kzalloc(sizeof(*gref), GFP_KERNEL);
if (!gref)
goto undo;
list_add_tail(&gref->next_gref, &queue_gref);
list_add_tail(&gref->next_file, &queue_file);
gref->users = 1;
gref->file_index = op->index + i * PAGE_SIZE;
gref->page = alloc_page(GFP_KERNEL|__GFP_ZERO);
if (!gref->page)
goto undo;
gref->gref_id = gnttab_grant_foreign_access(op->domid,
pfn_to_mfn(page_to_pfn(gref->page)), readonly);
if ((int)gref->gref_id < 0) {
rc = gref->gref_id;
goto undo;
}
gref_ids[i] = gref->gref_id;
}
spin_lock(&gref_lock);
list_splice_tail(&queue_gref, &gref_list);
list_splice_tail(&queue_file, &priv->list);
spin_unlock(&gref_lock);
return 0;
undo:
spin_lock(&gref_lock);
gref_size -= (op->count - i);
list_for_each_entry(gref, &queue_file, next_file) {
__del_gref(gref);
}
if (unlikely(!list_empty(&queue_gref)))
list_splice_tail(&queue_gref, &gref_list);
spin_unlock(&gref_lock);
return rc;
}
static void __del_gref(struct gntalloc_gref *gref)
{
if (gref->notify.flags & UNMAP_NOTIFY_CLEAR_BYTE) {
uint8_t *tmp = kmap(gref->page);
tmp[gref->notify.pgoff] = 0;
kunmap(gref->page);
}
if (gref->notify.flags & UNMAP_NOTIFY_SEND_EVENT)
notify_remote_via_evtchn(gref->notify.event);
gref->notify.flags = 0;
if (gref->gref_id > 0) {
if (gnttab_query_foreign_access(gref->gref_id))
return;
if (!gnttab_end_foreign_access_ref(gref->gref_id, 0))
return;
}
gref_size--;
list_del(&gref->next_gref);
if (gref->page)
__free_page(gref->page);
kfree(gref);
}
static struct gntalloc_gref *find_grefs(struct gntalloc_file_private_data *priv,
uint64_t index, uint32_t count)
{
struct gntalloc_gref *rv = NULL, *gref;
list_for_each_entry(gref, &priv->list, next_file) {
if (gref->file_index == index && !rv)
rv = gref;
if (rv) {
if (gref->file_index != index)
return NULL;
index += PAGE_SIZE;
count--;
if (count == 0)
return rv;
}
}
return NULL;
}
static int gntalloc_open(struct inode *inode, struct file *filp)
{
struct gntalloc_file_private_data *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
goto out_nomem;
INIT_LIST_HEAD(&priv->list);
filp->private_data = priv;
pr_debug("%s: priv %p\n", __func__, priv);
return 0;
out_nomem:
return -ENOMEM;
}
static int gntalloc_release(struct inode *inode, struct file *filp)
{
struct gntalloc_file_private_data *priv = filp->private_data;
struct gntalloc_gref *gref;
pr_debug("%s: priv %p\n", __func__, priv);
spin_lock(&gref_lock);
while (!list_empty(&priv->list)) {
gref = list_entry(priv->list.next,
struct gntalloc_gref, next_file);
list_del(&gref->next_file);
gref->users--;
if (gref->users == 0)
__del_gref(gref);
}
kfree(priv);
spin_unlock(&gref_lock);
return 0;
}
static long gntalloc_ioctl_alloc(struct gntalloc_file_private_data *priv,
struct ioctl_gntalloc_alloc_gref __user *arg)
{
int rc = 0;
struct ioctl_gntalloc_alloc_gref op;
uint32_t *gref_ids;
pr_debug("%s: priv %p\n", __func__, priv);
if (copy_from_user(&op, arg, sizeof(op))) {
rc = -EFAULT;
goto out;
}
gref_ids = kcalloc(op.count, sizeof(gref_ids[0]), GFP_TEMPORARY);
if (!gref_ids) {
rc = -ENOMEM;
goto out;
}
spin_lock(&gref_lock);
do_cleanup();
if (gref_size + op.count > limit) {
spin_unlock(&gref_lock);
rc = -ENOSPC;
goto out_free;
}
gref_size += op.count;
op.index = priv->index;
priv->index += op.count * PAGE_SIZE;
spin_unlock(&gref_lock);
rc = add_grefs(&op, gref_ids, priv);
if (rc < 0)
goto out_free;
if (copy_to_user(arg, &op, sizeof(op))) {
rc = -EFAULT;
goto out_free;
}
if (copy_to_user(arg->gref_ids, gref_ids,
sizeof(gref_ids[0]) * op.count)) {
rc = -EFAULT;
goto out_free;
}
out_free:
kfree(gref_ids);
out:
return rc;
}
static long gntalloc_ioctl_dealloc(struct gntalloc_file_private_data *priv,
void __user *arg)
{
int i, rc = 0;
struct ioctl_gntalloc_dealloc_gref op;
struct gntalloc_gref *gref, *n;
pr_debug("%s: priv %p\n", __func__, priv);
if (copy_from_user(&op, arg, sizeof(op))) {
rc = -EFAULT;
goto dealloc_grant_out;
}
spin_lock(&gref_lock);
gref = find_grefs(priv, op.index, op.count);
if (gref) {
for (i = 0; i < op.count; i++) {
n = list_entry(gref->next_file.next,
struct gntalloc_gref, next_file);
list_del(&gref->next_file);
gref->users--;
gref = n;
}
} else {
rc = -EINVAL;
}
do_cleanup();
spin_unlock(&gref_lock);
dealloc_grant_out:
return rc;
}
static long gntalloc_ioctl_unmap_notify(struct gntalloc_file_private_data *priv,
void __user *arg)
{
struct ioctl_gntalloc_unmap_notify op;
struct gntalloc_gref *gref;
uint64_t index;
int pgoff;
int rc;
if (copy_from_user(&op, arg, sizeof(op)))
return -EFAULT;
index = op.index & ~(PAGE_SIZE - 1);
pgoff = op.index & (PAGE_SIZE - 1);
spin_lock(&gref_lock);
gref = find_grefs(priv, index, 1);
if (!gref) {
rc = -ENOENT;
goto unlock_out;
}
if (op.action & ~(UNMAP_NOTIFY_CLEAR_BYTE|UNMAP_NOTIFY_SEND_EVENT)) {
rc = -EINVAL;
goto unlock_out;
}
gref->notify.flags = op.action;
gref->notify.pgoff = pgoff;
gref->notify.event = op.event_channel_port;
rc = 0;
unlock_out:
spin_unlock(&gref_lock);
return rc;
}
static long gntalloc_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct gntalloc_file_private_data *priv = filp->private_data;
switch (cmd) {
case IOCTL_GNTALLOC_ALLOC_GREF:
return gntalloc_ioctl_alloc(priv, (void __user *)arg);
case IOCTL_GNTALLOC_DEALLOC_GREF:
return gntalloc_ioctl_dealloc(priv, (void __user *)arg);
case IOCTL_GNTALLOC_SET_UNMAP_NOTIFY:
return gntalloc_ioctl_unmap_notify(priv, (void __user *)arg);
default:
return -ENOIOCTLCMD;
}
return 0;
}
static void gntalloc_vma_open(struct vm_area_struct *vma)
{
struct gntalloc_gref *gref = vma->vm_private_data;
if (!gref)
return;
spin_lock(&gref_lock);
gref->users++;
spin_unlock(&gref_lock);
}
static void gntalloc_vma_close(struct vm_area_struct *vma)
{
struct gntalloc_gref *gref = vma->vm_private_data;
if (!gref)
return;
spin_lock(&gref_lock);
gref->users--;
if (gref->users == 0)
__del_gref(gref);
spin_unlock(&gref_lock);
}
static int gntalloc_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct gntalloc_file_private_data *priv = filp->private_data;
struct gntalloc_gref *gref;
int count = (vma->vm_end - vma->vm_start) >> PAGE_SHIFT;
int rv, i;
pr_debug("%s: priv %p, page %lu+%d\n", __func__,
priv, vma->vm_pgoff, count);
if (!(vma->vm_flags & VM_SHARED)) {
printk(KERN_ERR "%s: Mapping must be shared.\n", __func__);
return -EINVAL;
}
spin_lock(&gref_lock);
gref = find_grefs(priv, vma->vm_pgoff << PAGE_SHIFT, count);
if (gref == NULL) {
rv = -ENOENT;
pr_debug("%s: Could not find grant reference",
__func__);
goto out_unlock;
}
vma->vm_private_data = gref;
vma->vm_flags |= VM_RESERVED;
vma->vm_ops = &gntalloc_vmops;
for (i = 0; i < count; i++) {
gref->users++;
rv = vm_insert_page(vma, vma->vm_start + i * PAGE_SIZE,
gref->page);
if (rv)
goto out_unlock;
gref = list_entry(gref->next_file.next,
struct gntalloc_gref, next_file);
}
rv = 0;
out_unlock:
spin_unlock(&gref_lock);
return rv;
}
static int __init gntalloc_init(void)
{
int err;
if (!xen_domain())
return -ENODEV;
err = misc_register(&gntalloc_miscdev);
if (err != 0) {
printk(KERN_ERR "Could not register misc gntalloc device\n");
return err;
}
pr_debug("Created grant allocation device at %d,%d\n",
MISC_MAJOR, gntalloc_miscdev.minor);
return 0;
}
static void __exit gntalloc_exit(void)
{
misc_deregister(&gntalloc_miscdev);
}
