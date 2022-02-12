int __init vfio_pci_virqfd_init(void)
{
vfio_irqfd_cleanup_wq =
create_singlethread_workqueue("vfio-irqfd-cleanup");
if (!vfio_irqfd_cleanup_wq)
return -ENOMEM;
return 0;
}
void vfio_pci_virqfd_exit(void)
{
destroy_workqueue(vfio_irqfd_cleanup_wq);
}
static void virqfd_deactivate(struct virqfd *virqfd)
{
queue_work(vfio_irqfd_cleanup_wq, &virqfd->shutdown);
}
static int virqfd_wakeup(wait_queue_t *wait, unsigned mode, int sync, void *key)
{
struct virqfd *virqfd = container_of(wait, struct virqfd, wait);
unsigned long flags = (unsigned long)key;
if (flags & POLLIN) {
if ((!virqfd->handler ||
virqfd->handler(virqfd->vdev, virqfd->data)) &&
virqfd->thread)
schedule_work(&virqfd->inject);
}
if (flags & POLLHUP) {
unsigned long flags;
spin_lock_irqsave(&virqfd->vdev->irqlock, flags);
if (*(virqfd->pvirqfd) == virqfd) {
*(virqfd->pvirqfd) = NULL;
virqfd_deactivate(virqfd);
}
spin_unlock_irqrestore(&virqfd->vdev->irqlock, flags);
}
return 0;
}
static void virqfd_ptable_queue_proc(struct file *file,
wait_queue_head_t *wqh, poll_table *pt)
{
struct virqfd *virqfd = container_of(pt, struct virqfd, pt);
add_wait_queue(wqh, &virqfd->wait);
}
static void virqfd_shutdown(struct work_struct *work)
{
struct virqfd *virqfd = container_of(work, struct virqfd, shutdown);
u64 cnt;
eventfd_ctx_remove_wait_queue(virqfd->eventfd, &virqfd->wait, &cnt);
flush_work(&virqfd->inject);
eventfd_ctx_put(virqfd->eventfd);
kfree(virqfd);
}
static void virqfd_inject(struct work_struct *work)
{
struct virqfd *virqfd = container_of(work, struct virqfd, inject);
if (virqfd->thread)
virqfd->thread(virqfd->vdev, virqfd->data);
}
static int virqfd_enable(struct vfio_pci_device *vdev,
int (*handler)(struct vfio_pci_device *, void *),
void (*thread)(struct vfio_pci_device *, void *),
void *data, struct virqfd **pvirqfd, int fd)
{
struct file *file = NULL;
struct eventfd_ctx *ctx = NULL;
struct virqfd *virqfd;
int ret = 0;
unsigned int events;
virqfd = kzalloc(sizeof(*virqfd), GFP_KERNEL);
if (!virqfd)
return -ENOMEM;
virqfd->pvirqfd = pvirqfd;
virqfd->vdev = vdev;
virqfd->handler = handler;
virqfd->thread = thread;
virqfd->data = data;
INIT_WORK(&virqfd->shutdown, virqfd_shutdown);
INIT_WORK(&virqfd->inject, virqfd_inject);
file = eventfd_fget(fd);
if (IS_ERR(file)) {
ret = PTR_ERR(file);
goto fail;
}
ctx = eventfd_ctx_fileget(file);
if (IS_ERR(ctx)) {
ret = PTR_ERR(ctx);
goto fail;
}
virqfd->eventfd = ctx;
spin_lock_irq(&vdev->irqlock);
if (*pvirqfd) {
spin_unlock_irq(&vdev->irqlock);
ret = -EBUSY;
goto fail;
}
*pvirqfd = virqfd;
spin_unlock_irq(&vdev->irqlock);
init_waitqueue_func_entry(&virqfd->wait, virqfd_wakeup);
init_poll_funcptr(&virqfd->pt, virqfd_ptable_queue_proc);
events = file->f_op->poll(file, &virqfd->pt);
if (events & POLLIN) {
if ((!handler || handler(vdev, data)) && thread)
schedule_work(&virqfd->inject);
}
fput(file);
return 0;
fail:
if (ctx && !IS_ERR(ctx))
eventfd_ctx_put(ctx);
if (file && !IS_ERR(file))
fput(file);
kfree(virqfd);
return ret;
}
static void virqfd_disable(struct vfio_pci_device *vdev,
struct virqfd **pvirqfd)
{
unsigned long flags;
spin_lock_irqsave(&vdev->irqlock, flags);
if (*pvirqfd) {
virqfd_deactivate(*pvirqfd);
*pvirqfd = NULL;
}
spin_unlock_irqrestore(&vdev->irqlock, flags);
flush_workqueue(vfio_irqfd_cleanup_wq);
}
static void vfio_send_intx_eventfd(struct vfio_pci_device *vdev, void *unused)
{
if (likely(is_intx(vdev) && !vdev->virq_disabled))
eventfd_signal(vdev->ctx[0].trigger, 1);
}
void vfio_pci_intx_mask(struct vfio_pci_device *vdev)
{
struct pci_dev *pdev = vdev->pdev;
unsigned long flags;
spin_lock_irqsave(&vdev->irqlock, flags);
if (unlikely(!is_intx(vdev))) {
if (vdev->pci_2_3)
pci_intx(pdev, 0);
} else if (!vdev->ctx[0].masked) {
if (vdev->pci_2_3)
pci_intx(pdev, 0);
else
disable_irq_nosync(pdev->irq);
vdev->ctx[0].masked = true;
}
spin_unlock_irqrestore(&vdev->irqlock, flags);
}
int vfio_pci_intx_unmask_handler(struct vfio_pci_device *vdev, void *unused)
{
struct pci_dev *pdev = vdev->pdev;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&vdev->irqlock, flags);
if (unlikely(!is_intx(vdev))) {
if (vdev->pci_2_3)
pci_intx(pdev, 1);
} else if (vdev->ctx[0].masked && !vdev->virq_disabled) {
if (vdev->pci_2_3) {
if (!pci_check_and_unmask_intx(pdev))
ret = 1;
} else
enable_irq(pdev->irq);
vdev->ctx[0].masked = (ret > 0);
}
spin_unlock_irqrestore(&vdev->irqlock, flags);
return ret;
}
void vfio_pci_intx_unmask(struct vfio_pci_device *vdev)
{
if (vfio_pci_intx_unmask_handler(vdev, NULL) > 0)
vfio_send_intx_eventfd(vdev, NULL);
}
static irqreturn_t vfio_intx_handler(int irq, void *dev_id)
{
struct vfio_pci_device *vdev = dev_id;
unsigned long flags;
int ret = IRQ_NONE;
spin_lock_irqsave(&vdev->irqlock, flags);
if (!vdev->pci_2_3) {
disable_irq_nosync(vdev->pdev->irq);
vdev->ctx[0].masked = true;
ret = IRQ_HANDLED;
} else if (!vdev->ctx[0].masked &&
pci_check_and_mask_intx(vdev->pdev)) {
vdev->ctx[0].masked = true;
ret = IRQ_HANDLED;
}
spin_unlock_irqrestore(&vdev->irqlock, flags);
if (ret == IRQ_HANDLED)
vfio_send_intx_eventfd(vdev, NULL);
return ret;
}
static int vfio_intx_enable(struct vfio_pci_device *vdev)
{
if (!is_irq_none(vdev))
return -EINVAL;
if (!vdev->pdev->irq)
return -ENODEV;
vdev->ctx = kzalloc(sizeof(struct vfio_pci_irq_ctx), GFP_KERNEL);
if (!vdev->ctx)
return -ENOMEM;
vdev->num_ctx = 1;
vdev->ctx[0].masked = vdev->virq_disabled;
if (vdev->pci_2_3)
pci_intx(vdev->pdev, !vdev->ctx[0].masked);
vdev->irq_type = VFIO_PCI_INTX_IRQ_INDEX;
return 0;
}
static int vfio_intx_set_signal(struct vfio_pci_device *vdev, int fd)
{
struct pci_dev *pdev = vdev->pdev;
unsigned long irqflags = IRQF_SHARED;
struct eventfd_ctx *trigger;
unsigned long flags;
int ret;
if (vdev->ctx[0].trigger) {
free_irq(pdev->irq, vdev);
kfree(vdev->ctx[0].name);
eventfd_ctx_put(vdev->ctx[0].trigger);
vdev->ctx[0].trigger = NULL;
}
if (fd < 0)
return 0;
vdev->ctx[0].name = kasprintf(GFP_KERNEL, "vfio-intx(%s)",
pci_name(pdev));
if (!vdev->ctx[0].name)
return -ENOMEM;
trigger = eventfd_ctx_fdget(fd);
if (IS_ERR(trigger)) {
kfree(vdev->ctx[0].name);
return PTR_ERR(trigger);
}
vdev->ctx[0].trigger = trigger;
if (!vdev->pci_2_3)
irqflags = 0;
ret = request_irq(pdev->irq, vfio_intx_handler,
irqflags, vdev->ctx[0].name, vdev);
if (ret) {
vdev->ctx[0].trigger = NULL;
kfree(vdev->ctx[0].name);
eventfd_ctx_put(trigger);
return ret;
}
spin_lock_irqsave(&vdev->irqlock, flags);
if (!vdev->pci_2_3 && vdev->ctx[0].masked)
disable_irq_nosync(pdev->irq);
spin_unlock_irqrestore(&vdev->irqlock, flags);
return 0;
}
static void vfio_intx_disable(struct vfio_pci_device *vdev)
{
vfio_intx_set_signal(vdev, -1);
virqfd_disable(vdev, &vdev->ctx[0].unmask);
virqfd_disable(vdev, &vdev->ctx[0].mask);
vdev->irq_type = VFIO_PCI_NUM_IRQS;
vdev->num_ctx = 0;
kfree(vdev->ctx);
}
static irqreturn_t vfio_msihandler(int irq, void *arg)
{
struct eventfd_ctx *trigger = arg;
eventfd_signal(trigger, 1);
return IRQ_HANDLED;
}
static int vfio_msi_enable(struct vfio_pci_device *vdev, int nvec, bool msix)
{
struct pci_dev *pdev = vdev->pdev;
int ret;
if (!is_irq_none(vdev))
return -EINVAL;
vdev->ctx = kzalloc(nvec * sizeof(struct vfio_pci_irq_ctx), GFP_KERNEL);
if (!vdev->ctx)
return -ENOMEM;
if (msix) {
int i;
vdev->msix = kzalloc(nvec * sizeof(struct msix_entry),
GFP_KERNEL);
if (!vdev->msix) {
kfree(vdev->ctx);
return -ENOMEM;
}
for (i = 0; i < nvec; i++)
vdev->msix[i].entry = i;
ret = pci_enable_msix(pdev, vdev->msix, nvec);
if (ret) {
kfree(vdev->msix);
kfree(vdev->ctx);
return ret;
}
} else {
ret = pci_enable_msi_block(pdev, nvec);
if (ret) {
kfree(vdev->ctx);
return ret;
}
}
vdev->num_ctx = nvec;
vdev->irq_type = msix ? VFIO_PCI_MSIX_IRQ_INDEX :
VFIO_PCI_MSI_IRQ_INDEX;
if (!msix) {
vdev->msi_qmax = fls(nvec * 2 - 1) - 1;
}
return 0;
}
static int vfio_msi_set_vector_signal(struct vfio_pci_device *vdev,
int vector, int fd, bool msix)
{
struct pci_dev *pdev = vdev->pdev;
int irq = msix ? vdev->msix[vector].vector : pdev->irq + vector;
char *name = msix ? "vfio-msix" : "vfio-msi";
struct eventfd_ctx *trigger;
int ret;
if (vector >= vdev->num_ctx)
return -EINVAL;
if (vdev->ctx[vector].trigger) {
free_irq(irq, vdev->ctx[vector].trigger);
kfree(vdev->ctx[vector].name);
eventfd_ctx_put(vdev->ctx[vector].trigger);
vdev->ctx[vector].trigger = NULL;
}
if (fd < 0)
return 0;
vdev->ctx[vector].name = kasprintf(GFP_KERNEL, "%s[%d](%s)",
name, vector, pci_name(pdev));
if (!vdev->ctx[vector].name)
return -ENOMEM;
trigger = eventfd_ctx_fdget(fd);
if (IS_ERR(trigger)) {
kfree(vdev->ctx[vector].name);
return PTR_ERR(trigger);
}
ret = request_irq(irq, vfio_msihandler, 0,
vdev->ctx[vector].name, trigger);
if (ret) {
kfree(vdev->ctx[vector].name);
eventfd_ctx_put(trigger);
return ret;
}
vdev->ctx[vector].trigger = trigger;
return 0;
}
static int vfio_msi_set_block(struct vfio_pci_device *vdev, unsigned start,
unsigned count, int32_t *fds, bool msix)
{
int i, j, ret = 0;
if (start + count > vdev->num_ctx)
return -EINVAL;
for (i = 0, j = start; i < count && !ret; i++, j++) {
int fd = fds ? fds[i] : -1;
ret = vfio_msi_set_vector_signal(vdev, j, fd, msix);
}
if (ret) {
for (--j; j >= start; j--)
vfio_msi_set_vector_signal(vdev, j, -1, msix);
}
return ret;
}
static void vfio_msi_disable(struct vfio_pci_device *vdev, bool msix)
{
struct pci_dev *pdev = vdev->pdev;
int i;
vfio_msi_set_block(vdev, 0, vdev->num_ctx, NULL, msix);
for (i = 0; i < vdev->num_ctx; i++) {
virqfd_disable(vdev, &vdev->ctx[i].unmask);
virqfd_disable(vdev, &vdev->ctx[i].mask);
}
if (msix) {
pci_disable_msix(vdev->pdev);
kfree(vdev->msix);
} else
pci_disable_msi(pdev);
vdev->irq_type = VFIO_PCI_NUM_IRQS;
vdev->num_ctx = 0;
kfree(vdev->ctx);
}
static int vfio_pci_set_intx_unmask(struct vfio_pci_device *vdev,
unsigned index, unsigned start,
unsigned count, uint32_t flags, void *data)
{
if (!is_intx(vdev) || start != 0 || count != 1)
return -EINVAL;
if (flags & VFIO_IRQ_SET_DATA_NONE) {
vfio_pci_intx_unmask(vdev);
} else if (flags & VFIO_IRQ_SET_DATA_BOOL) {
uint8_t unmask = *(uint8_t *)data;
if (unmask)
vfio_pci_intx_unmask(vdev);
} else if (flags & VFIO_IRQ_SET_DATA_EVENTFD) {
int32_t fd = *(int32_t *)data;
if (fd >= 0)
return virqfd_enable(vdev, vfio_pci_intx_unmask_handler,
vfio_send_intx_eventfd, NULL,
&vdev->ctx[0].unmask, fd);
virqfd_disable(vdev, &vdev->ctx[0].unmask);
}
return 0;
}
static int vfio_pci_set_intx_mask(struct vfio_pci_device *vdev,
unsigned index, unsigned start,
unsigned count, uint32_t flags, void *data)
{
if (!is_intx(vdev) || start != 0 || count != 1)
return -EINVAL;
if (flags & VFIO_IRQ_SET_DATA_NONE) {
vfio_pci_intx_mask(vdev);
} else if (flags & VFIO_IRQ_SET_DATA_BOOL) {
uint8_t mask = *(uint8_t *)data;
if (mask)
vfio_pci_intx_mask(vdev);
} else if (flags & VFIO_IRQ_SET_DATA_EVENTFD) {
return -ENOTTY;
}
return 0;
}
static int vfio_pci_set_intx_trigger(struct vfio_pci_device *vdev,
unsigned index, unsigned start,
unsigned count, uint32_t flags, void *data)
{
if (is_intx(vdev) && !count && (flags & VFIO_IRQ_SET_DATA_NONE)) {
vfio_intx_disable(vdev);
return 0;
}
if (!(is_intx(vdev) || is_irq_none(vdev)) || start != 0 || count != 1)
return -EINVAL;
if (flags & VFIO_IRQ_SET_DATA_EVENTFD) {
int32_t fd = *(int32_t *)data;
int ret;
if (is_intx(vdev))
return vfio_intx_set_signal(vdev, fd);
ret = vfio_intx_enable(vdev);
if (ret)
return ret;
ret = vfio_intx_set_signal(vdev, fd);
if (ret)
vfio_intx_disable(vdev);
return ret;
}
if (!is_intx(vdev))
return -EINVAL;
if (flags & VFIO_IRQ_SET_DATA_NONE) {
vfio_send_intx_eventfd(vdev, NULL);
} else if (flags & VFIO_IRQ_SET_DATA_BOOL) {
uint8_t trigger = *(uint8_t *)data;
if (trigger)
vfio_send_intx_eventfd(vdev, NULL);
}
return 0;
}
static int vfio_pci_set_msi_trigger(struct vfio_pci_device *vdev,
unsigned index, unsigned start,
unsigned count, uint32_t flags, void *data)
{
int i;
bool msix = (index == VFIO_PCI_MSIX_IRQ_INDEX) ? true : false;
if (irq_is(vdev, index) && !count && (flags & VFIO_IRQ_SET_DATA_NONE)) {
vfio_msi_disable(vdev, msix);
return 0;
}
if (!(irq_is(vdev, index) || is_irq_none(vdev)))
return -EINVAL;
if (flags & VFIO_IRQ_SET_DATA_EVENTFD) {
int32_t *fds = data;
int ret;
if (vdev->irq_type == index)
return vfio_msi_set_block(vdev, start, count,
fds, msix);
ret = vfio_msi_enable(vdev, start + count, msix);
if (ret)
return ret;
ret = vfio_msi_set_block(vdev, start, count, fds, msix);
if (ret)
vfio_msi_disable(vdev, msix);
return ret;
}
if (!irq_is(vdev, index) || start + count > vdev->num_ctx)
return -EINVAL;
for (i = start; i < start + count; i++) {
if (!vdev->ctx[i].trigger)
continue;
if (flags & VFIO_IRQ_SET_DATA_NONE) {
eventfd_signal(vdev->ctx[i].trigger, 1);
} else if (flags & VFIO_IRQ_SET_DATA_BOOL) {
uint8_t *bools = data;
if (bools[i - start])
eventfd_signal(vdev->ctx[i].trigger, 1);
}
}
return 0;
}
int vfio_pci_set_irqs_ioctl(struct vfio_pci_device *vdev, uint32_t flags,
unsigned index, unsigned start, unsigned count,
void *data)
{
int (*func)(struct vfio_pci_device *vdev, unsigned index,
unsigned start, unsigned count, uint32_t flags,
void *data) = NULL;
switch (index) {
case VFIO_PCI_INTX_IRQ_INDEX:
switch (flags & VFIO_IRQ_SET_ACTION_TYPE_MASK) {
case VFIO_IRQ_SET_ACTION_MASK:
func = vfio_pci_set_intx_mask;
break;
case VFIO_IRQ_SET_ACTION_UNMASK:
func = vfio_pci_set_intx_unmask;
break;
case VFIO_IRQ_SET_ACTION_TRIGGER:
func = vfio_pci_set_intx_trigger;
break;
}
break;
case VFIO_PCI_MSI_IRQ_INDEX:
case VFIO_PCI_MSIX_IRQ_INDEX:
switch (flags & VFIO_IRQ_SET_ACTION_TYPE_MASK) {
case VFIO_IRQ_SET_ACTION_MASK:
case VFIO_IRQ_SET_ACTION_UNMASK:
break;
case VFIO_IRQ_SET_ACTION_TRIGGER:
func = vfio_pci_set_msi_trigger;
break;
}
break;
}
if (!func)
return -ENOTTY;
return func(vdev, index, start, count, flags, data);
}
