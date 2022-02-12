void notrace __sanitizer_cov_trace_pc(void)
{
struct task_struct *t;
enum kcov_mode mode;
t = current;
if (!t || (preempt_count() & (HARDIRQ_MASK | SOFTIRQ_OFFSET
| NMI_MASK)))
return;
mode = READ_ONCE(t->kcov_mode);
if (mode == KCOV_MODE_TRACE) {
unsigned long *area;
unsigned long pos;
unsigned long ip = _RET_IP_;
#ifdef CONFIG_RANDOMIZE_BASE
ip -= kaslr_offset();
#endif
barrier();
area = t->kcov_area;
pos = READ_ONCE(area[0]) + 1;
if (likely(pos < t->kcov_size)) {
area[pos] = ip;
WRITE_ONCE(area[0], pos);
}
}
}
static void kcov_get(struct kcov *kcov)
{
atomic_inc(&kcov->refcount);
}
static void kcov_put(struct kcov *kcov)
{
if (atomic_dec_and_test(&kcov->refcount)) {
vfree(kcov->area);
kfree(kcov);
}
}
void kcov_task_init(struct task_struct *t)
{
t->kcov_mode = KCOV_MODE_DISABLED;
t->kcov_size = 0;
t->kcov_area = NULL;
t->kcov = NULL;
}
void kcov_task_exit(struct task_struct *t)
{
struct kcov *kcov;
kcov = t->kcov;
if (kcov == NULL)
return;
spin_lock(&kcov->lock);
if (WARN_ON(kcov->t != t)) {
spin_unlock(&kcov->lock);
return;
}
kcov_task_init(t);
kcov->t = NULL;
spin_unlock(&kcov->lock);
kcov_put(kcov);
}
static int kcov_mmap(struct file *filep, struct vm_area_struct *vma)
{
int res = 0;
void *area;
struct kcov *kcov = vma->vm_file->private_data;
unsigned long size, off;
struct page *page;
area = vmalloc_user(vma->vm_end - vma->vm_start);
if (!area)
return -ENOMEM;
spin_lock(&kcov->lock);
size = kcov->size * sizeof(unsigned long);
if (kcov->mode == KCOV_MODE_DISABLED || vma->vm_pgoff != 0 ||
vma->vm_end - vma->vm_start != size) {
res = -EINVAL;
goto exit;
}
if (!kcov->area) {
kcov->area = area;
vma->vm_flags |= VM_DONTEXPAND;
spin_unlock(&kcov->lock);
for (off = 0; off < size; off += PAGE_SIZE) {
page = vmalloc_to_page(kcov->area + off);
if (vm_insert_page(vma, vma->vm_start + off, page))
WARN_ONCE(1, "vm_insert_page() failed");
}
return 0;
}
exit:
spin_unlock(&kcov->lock);
vfree(area);
return res;
}
static int kcov_open(struct inode *inode, struct file *filep)
{
struct kcov *kcov;
kcov = kzalloc(sizeof(*kcov), GFP_KERNEL);
if (!kcov)
return -ENOMEM;
atomic_set(&kcov->refcount, 1);
spin_lock_init(&kcov->lock);
filep->private_data = kcov;
return nonseekable_open(inode, filep);
}
static int kcov_close(struct inode *inode, struct file *filep)
{
kcov_put(filep->private_data);
return 0;
}
static int kcov_ioctl_locked(struct kcov *kcov, unsigned int cmd,
unsigned long arg)
{
struct task_struct *t;
unsigned long size, unused;
switch (cmd) {
case KCOV_INIT_TRACE:
if (kcov->mode != KCOV_MODE_DISABLED)
return -EBUSY;
size = arg;
if (size < 2 || size > INT_MAX / sizeof(unsigned long))
return -EINVAL;
kcov->size = size;
kcov->mode = KCOV_MODE_TRACE;
return 0;
case KCOV_ENABLE:
unused = arg;
if (unused != 0 || kcov->mode == KCOV_MODE_DISABLED ||
kcov->area == NULL)
return -EINVAL;
if (kcov->t != NULL)
return -EBUSY;
t = current;
t->kcov_size = kcov->size;
t->kcov_area = kcov->area;
barrier();
WRITE_ONCE(t->kcov_mode, kcov->mode);
t->kcov = kcov;
kcov->t = t;
kcov_get(kcov);
return 0;
case KCOV_DISABLE:
unused = arg;
if (unused != 0 || current->kcov != kcov)
return -EINVAL;
t = current;
if (WARN_ON(kcov->t != t))
return -EINVAL;
kcov_task_init(t);
kcov->t = NULL;
kcov_put(kcov);
return 0;
default:
return -ENOTTY;
}
}
static long kcov_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
struct kcov *kcov;
int res;
kcov = filep->private_data;
spin_lock(&kcov->lock);
res = kcov_ioctl_locked(kcov, cmd, arg);
spin_unlock(&kcov->lock);
return res;
}
static int __init kcov_init(void)
{
if (!debugfs_create_file_unsafe("kcov", 0600, NULL, NULL, &kcov_fops)) {
pr_err("failed to create kcov in debugfs\n");
return -ENOMEM;
}
return 0;
}
