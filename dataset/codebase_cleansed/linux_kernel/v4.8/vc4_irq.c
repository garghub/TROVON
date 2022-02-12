static void
vc4_overflow_mem_work(struct work_struct *work)
{
struct vc4_dev *vc4 =
container_of(work, struct vc4_dev, overflow_mem_work);
struct drm_device *dev = vc4->dev;
struct vc4_bo *bo;
bo = vc4_bo_create(dev, 256 * 1024, true);
if (IS_ERR(bo)) {
DRM_ERROR("Couldn't allocate binner overflow mem\n");
return;
}
if (vc4->overflow_mem) {
struct vc4_exec_info *current_exec;
unsigned long irqflags;
spin_lock_irqsave(&vc4->job_lock, irqflags);
current_exec = vc4_first_bin_job(vc4);
if (!current_exec)
current_exec = vc4_last_render_job(vc4);
if (current_exec) {
vc4->overflow_mem->seqno = current_exec->seqno;
list_add_tail(&vc4->overflow_mem->unref_head,
&current_exec->unref_list);
vc4->overflow_mem = NULL;
}
spin_unlock_irqrestore(&vc4->job_lock, irqflags);
}
if (vc4->overflow_mem)
drm_gem_object_unreference_unlocked(&vc4->overflow_mem->base.base);
vc4->overflow_mem = bo;
V3D_WRITE(V3D_BPOA, bo->base.paddr);
V3D_WRITE(V3D_BPOS, bo->base.base.size);
V3D_WRITE(V3D_INTCTL, V3D_INT_OUTOMEM);
V3D_WRITE(V3D_INTENA, V3D_INT_OUTOMEM);
}
static void
vc4_irq_finish_bin_job(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_exec_info *exec = vc4_first_bin_job(vc4);
if (!exec)
return;
vc4_move_job_to_render(dev, exec);
vc4_submit_next_bin_job(dev);
}
static void
vc4_cancel_bin_job(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_exec_info *exec = vc4_first_bin_job(vc4);
if (!exec)
return;
list_move_tail(&exec->head, &vc4->bin_job_list);
vc4_submit_next_bin_job(dev);
}
static void
vc4_irq_finish_render_job(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_exec_info *exec = vc4_first_render_job(vc4);
if (!exec)
return;
vc4->finished_seqno++;
list_move_tail(&exec->head, &vc4->job_done_list);
vc4_submit_next_render_job(dev);
wake_up_all(&vc4->job_wait_queue);
schedule_work(&vc4->job_done_work);
}
irqreturn_t
vc4_irq(int irq, void *arg)
{
struct drm_device *dev = arg;
struct vc4_dev *vc4 = to_vc4_dev(dev);
uint32_t intctl;
irqreturn_t status = IRQ_NONE;
barrier();
intctl = V3D_READ(V3D_INTCTL);
V3D_WRITE(V3D_INTCTL, intctl);
if (intctl & V3D_INT_OUTOMEM) {
V3D_WRITE(V3D_INTDIS, V3D_INT_OUTOMEM);
schedule_work(&vc4->overflow_mem_work);
status = IRQ_HANDLED;
}
if (intctl & V3D_INT_FLDONE) {
spin_lock(&vc4->job_lock);
vc4_irq_finish_bin_job(dev);
spin_unlock(&vc4->job_lock);
status = IRQ_HANDLED;
}
if (intctl & V3D_INT_FRDONE) {
spin_lock(&vc4->job_lock);
vc4_irq_finish_render_job(dev);
spin_unlock(&vc4->job_lock);
status = IRQ_HANDLED;
}
return status;
}
void
vc4_irq_preinstall(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
init_waitqueue_head(&vc4->job_wait_queue);
INIT_WORK(&vc4->overflow_mem_work, vc4_overflow_mem_work);
V3D_WRITE(V3D_INTCTL, V3D_DRIVER_IRQS);
}
int
vc4_irq_postinstall(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
V3D_WRITE(V3D_INTENA, V3D_DRIVER_IRQS);
return 0;
}
void
vc4_irq_uninstall(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
V3D_WRITE(V3D_INTDIS, V3D_DRIVER_IRQS);
V3D_WRITE(V3D_INTCTL, V3D_DRIVER_IRQS);
cancel_work_sync(&vc4->overflow_mem_work);
}
void vc4_irq_reset(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
unsigned long irqflags;
V3D_WRITE(V3D_INTCTL, V3D_DRIVER_IRQS);
V3D_WRITE(V3D_INTENA, V3D_DRIVER_IRQS);
spin_lock_irqsave(&vc4->job_lock, irqflags);
vc4_cancel_bin_job(dev);
vc4_irq_finish_render_job(dev);
spin_unlock_irqrestore(&vc4->job_lock, irqflags);
}
