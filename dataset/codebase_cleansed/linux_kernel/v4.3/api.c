struct cxl_context *cxl_dev_context_init(struct pci_dev *dev)
{
struct address_space *mapping;
struct cxl_afu *afu;
struct cxl_context *ctx;
int rc;
afu = cxl_pci_to_afu(dev);
get_device(&afu->dev);
ctx = cxl_context_alloc();
if (IS_ERR(ctx)) {
rc = PTR_ERR(ctx);
goto err_dev;
}
ctx->kernelapi = true;
mapping = kmalloc(sizeof(struct address_space), GFP_KERNEL);
if (!mapping) {
rc = -ENOMEM;
goto err_ctx;
}
address_space_init_once(mapping);
rc = cxl_context_init(ctx, afu, false, mapping);
if (rc)
goto err_mapping;
cxl_assign_psn_space(ctx);
return ctx;
err_mapping:
kfree(mapping);
err_ctx:
kfree(ctx);
err_dev:
put_device(&afu->dev);
return ERR_PTR(rc);
}
struct cxl_context *cxl_get_context(struct pci_dev *dev)
{
return dev->dev.archdata.cxl_ctx;
}
struct device *cxl_get_phys_dev(struct pci_dev *dev)
{
struct cxl_afu *afu;
afu = cxl_pci_to_afu(dev);
return afu->adapter->dev.parent;
}
int cxl_release_context(struct cxl_context *ctx)
{
if (ctx->status >= STARTED)
return -EBUSY;
put_device(&ctx->afu->dev);
cxl_context_free(ctx);
return 0;
}
int cxl_allocate_afu_irqs(struct cxl_context *ctx, int num)
{
if (num == 0)
num = ctx->afu->pp_irqs;
return afu_allocate_irqs(ctx, num);
}
void cxl_free_afu_irqs(struct cxl_context *ctx)
{
afu_irq_name_free(ctx);
cxl_release_irq_ranges(&ctx->irqs, ctx->afu->adapter);
}
static irq_hw_number_t cxl_find_afu_irq(struct cxl_context *ctx, int num)
{
__u16 range;
int r;
WARN_ON(num == 0);
for (r = 0; r < CXL_IRQ_RANGES; r++) {
range = ctx->irqs.range[r];
if (num < range) {
return ctx->irqs.offset[r] + num;
}
num -= range;
}
return 0;
}
int cxl_map_afu_irq(struct cxl_context *ctx, int num,
irq_handler_t handler, void *cookie, char *name)
{
irq_hw_number_t hwirq;
hwirq = cxl_find_afu_irq(ctx, num);
if (!hwirq)
return -ENOENT;
return cxl_map_irq(ctx->afu->adapter, hwirq, handler, cookie, name);
}
void cxl_unmap_afu_irq(struct cxl_context *ctx, int num, void *cookie)
{
irq_hw_number_t hwirq;
unsigned int virq;
hwirq = cxl_find_afu_irq(ctx, num);
if (!hwirq)
return;
virq = irq_find_mapping(NULL, hwirq);
if (virq)
cxl_unmap_irq(virq, cookie);
}
int cxl_start_context(struct cxl_context *ctx, u64 wed,
struct task_struct *task)
{
int rc = 0;
bool kernel = true;
pr_devel("%s: pe: %i\n", __func__, ctx->pe);
mutex_lock(&ctx->status_mutex);
if (ctx->status == STARTED)
goto out;
if (task) {
ctx->pid = get_task_pid(task, PIDTYPE_PID);
get_pid(ctx->pid);
kernel = false;
}
cxl_ctx_get();
if ((rc = cxl_attach_process(ctx, kernel, wed , 0))) {
put_pid(ctx->pid);
cxl_ctx_put();
goto out;
}
ctx->status = STARTED;
out:
mutex_unlock(&ctx->status_mutex);
return rc;
}
int cxl_process_element(struct cxl_context *ctx)
{
return ctx->pe;
}
int cxl_stop_context(struct cxl_context *ctx)
{
return __detach_context(ctx);
}
void cxl_set_master(struct cxl_context *ctx)
{
ctx->master = true;
cxl_assign_psn_space(ctx);
}
int cxl_fd_open(struct inode *inode, struct file *file)
{
return afu_open(inode, file);
}
int cxl_fd_release(struct inode *inode, struct file *file)
{
return afu_release(inode, file);
}
long cxl_fd_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
return afu_ioctl(file, cmd, arg);
}
int cxl_fd_mmap(struct file *file, struct vm_area_struct *vm)
{
return afu_mmap(file, vm);
}
unsigned int cxl_fd_poll(struct file *file, struct poll_table_struct *poll)
{
return afu_poll(file, poll);
}
ssize_t cxl_fd_read(struct file *file, char __user *buf, size_t count,
loff_t *off)
{
return afu_read(file, buf, count, off);
}
struct file *cxl_get_fd(struct cxl_context *ctx, struct file_operations *fops,
int *fd)
{
struct file *file;
int rc, flags, fdtmp;
flags = O_RDWR | O_CLOEXEC;
rc = get_unused_fd_flags(flags);
if (rc < 0)
return ERR_PTR(rc);
fdtmp = rc;
if (fops) {
PATCH_FOPS(open);
PATCH_FOPS(poll);
PATCH_FOPS(read);
PATCH_FOPS(release);
PATCH_FOPS(unlocked_ioctl);
PATCH_FOPS(compat_ioctl);
PATCH_FOPS(mmap);
} else
fops = (struct file_operations *)&afu_fops;
file = anon_inode_getfile("cxl", fops, ctx, flags);
if (IS_ERR(file))
goto err_fd;
file->f_mapping = ctx->mapping;
*fd = fdtmp;
return file;
err_fd:
put_unused_fd(fdtmp);
return NULL;
}
struct cxl_context *cxl_fops_get_context(struct file *file)
{
return file->private_data;
}
int cxl_start_work(struct cxl_context *ctx,
struct cxl_ioctl_start_work *work)
{
int rc;
if (!(work->flags & CXL_START_WORK_NUM_IRQS))
work->num_interrupts = ctx->afu->pp_irqs;
else if ((work->num_interrupts < ctx->afu->pp_irqs) ||
(work->num_interrupts > ctx->afu->irqs_max)) {
return -EINVAL;
}
rc = afu_register_irqs(ctx, work->num_interrupts);
if (rc)
return rc;
rc = cxl_start_context(ctx, work->work_element_descriptor, current);
if (rc < 0) {
afu_release_irqs(ctx, ctx);
return rc;
}
return 0;
}
void __iomem *cxl_psa_map(struct cxl_context *ctx)
{
struct cxl_afu *afu = ctx->afu;
int rc;
rc = cxl_afu_check_and_enable(afu);
if (rc)
return NULL;
pr_devel("%s: psn_phys%llx size:%llx\n",
__func__, afu->psn_phys, afu->adapter->ps_size);
return ioremap(ctx->psn_phys, ctx->psn_size);
}
void cxl_psa_unmap(void __iomem *addr)
{
iounmap(addr);
}
int cxl_afu_reset(struct cxl_context *ctx)
{
struct cxl_afu *afu = ctx->afu;
int rc;
rc = __cxl_afu_reset(afu);
if (rc)
return rc;
return cxl_afu_check_and_enable(afu);
}
void cxl_perst_reloads_same_image(struct cxl_afu *afu,
bool perst_reloads_same_image)
{
afu->adapter->perst_same_image = perst_reloads_same_image;
}
