static void vfio_send_intx_eventfd(void *opaque, void *unused)
{
struct vfio_pci_device *vdev = opaque;
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
static int vfio_pci_intx_unmask_handler(void *opaque, void *unused)
{
struct vfio_pci_device *vdev = opaque;
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
vfio_virqfd_disable(&vdev->ctx[0].unmask);
vfio_virqfd_disable(&vdev->ctx[0].mask);
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
ret = pci_enable_msix_range(pdev, vdev->msix, 1, nvec);
if (ret < nvec) {
if (ret > 0)
pci_disable_msix(pdev);
kfree(vdev->msix);
kfree(vdev->ctx);
return ret;
}
} else {
ret = pci_enable_msi_range(pdev, 1, nvec);
if (ret < nvec) {
if (ret > 0)
pci_disable_msi(pdev);
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
if (msix) {
struct msi_msg msg;
get_cached_msi_msg(irq, &msg);
pci_write_msi_msg(irq, &msg);
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
vfio_virqfd_disable(&vdev->ctx[i].unmask);
vfio_virqfd_disable(&vdev->ctx[i].mask);
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
return vfio_virqfd_enable((void *) vdev,
vfio_pci_intx_unmask_handler,
vfio_send_intx_eventfd, NULL,
&vdev->ctx[0].unmask, fd);
vfio_virqfd_disable(&vdev->ctx[0].unmask);
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
static int vfio_pci_set_ctx_trigger_single(struct eventfd_ctx **ctx,
uint32_t flags, void *data)
{
int32_t fd = *(int32_t *)data;
if (!(flags & VFIO_IRQ_SET_DATA_TYPE_MASK))
return -EINVAL;
if (flags & VFIO_IRQ_SET_DATA_NONE) {
if (*ctx)
eventfd_signal(*ctx, 1);
return 0;
} else if (flags & VFIO_IRQ_SET_DATA_BOOL) {
uint8_t trigger = *(uint8_t *)data;
if (trigger && *ctx)
eventfd_signal(*ctx, 1);
return 0;
}
if (fd == -1) {
if (*ctx)
eventfd_ctx_put(*ctx);
*ctx = NULL;
return 0;
} else if (fd >= 0) {
struct eventfd_ctx *efdctx;
efdctx = eventfd_ctx_fdget(fd);
if (IS_ERR(efdctx))
return PTR_ERR(efdctx);
if (*ctx)
eventfd_ctx_put(*ctx);
*ctx = efdctx;
return 0;
} else
return -EINVAL;
}
static int vfio_pci_set_err_trigger(struct vfio_pci_device *vdev,
unsigned index, unsigned start,
unsigned count, uint32_t flags, void *data)
{
if (index != VFIO_PCI_ERR_IRQ_INDEX)
return -EINVAL;
return vfio_pci_set_ctx_trigger_single(&vdev->err_trigger, flags, data);
}
static int vfio_pci_set_req_trigger(struct vfio_pci_device *vdev,
unsigned index, unsigned start,
unsigned count, uint32_t flags, void *data)
{
if (index != VFIO_PCI_REQ_IRQ_INDEX || start != 0 || count != 1)
return -EINVAL;
return vfio_pci_set_ctx_trigger_single(&vdev->req_trigger, flags, data);
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
case VFIO_PCI_ERR_IRQ_INDEX:
switch (flags & VFIO_IRQ_SET_ACTION_TYPE_MASK) {
case VFIO_IRQ_SET_ACTION_TRIGGER:
if (pci_is_pcie(vdev->pdev))
func = vfio_pci_set_err_trigger;
break;
}
break;
case VFIO_PCI_REQ_IRQ_INDEX:
switch (flags & VFIO_IRQ_SET_ACTION_TYPE_MASK) {
case VFIO_IRQ_SET_ACTION_TRIGGER:
func = vfio_pci_set_req_trigger;
break;
}
break;
}
if (!func)
return -ENOTTY;
return func(vdev, index, start, count, flags, data);
}
