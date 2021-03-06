int vfio_ccw_sch_quiesce(struct subchannel *sch)
{
struct vfio_ccw_private *private = dev_get_drvdata(&sch->dev);
DECLARE_COMPLETION_ONSTACK(completion);
int iretry, ret = 0;
spin_lock_irq(sch->lock);
if (!sch->schib.pmcw.ena)
goto out_unlock;
ret = cio_disable_subchannel(sch);
if (ret != -EBUSY)
goto out_unlock;
do {
iretry = 255;
ret = cio_cancel_halt_clear(sch, &iretry);
while (ret == -EBUSY) {
private->completion = &completion;
spin_unlock_irq(sch->lock);
wait_for_completion_timeout(&completion, 3*HZ);
spin_lock_irq(sch->lock);
private->completion = NULL;
flush_workqueue(vfio_ccw_work_q);
ret = cio_cancel_halt_clear(sch, &iretry);
};
ret = cio_disable_subchannel(sch);
} while (ret == -EBUSY);
out_unlock:
private->state = VFIO_CCW_STATE_NOT_OPER;
spin_unlock_irq(sch->lock);
return ret;
}
static void vfio_ccw_sch_io_todo(struct work_struct *work)
{
struct vfio_ccw_private *private;
struct irb *irb;
private = container_of(work, struct vfio_ccw_private, io_work);
irb = &private->irb;
if (scsw_is_solicited(&irb->scsw)) {
cp_update_scsw(&private->cp, &irb->scsw);
cp_free(&private->cp);
}
memcpy(private->io_region.irb_area, irb, sizeof(*irb));
if (private->io_trigger)
eventfd_signal(private->io_trigger, 1);
if (private->mdev)
private->state = VFIO_CCW_STATE_IDLE;
}
static void vfio_ccw_sch_irq(struct subchannel *sch)
{
struct vfio_ccw_private *private = dev_get_drvdata(&sch->dev);
inc_irq_stat(IRQIO_CIO);
vfio_ccw_fsm_event(private, VFIO_CCW_EVENT_INTERRUPT);
}
static int vfio_ccw_sch_probe(struct subchannel *sch)
{
struct pmcw *pmcw = &sch->schib.pmcw;
struct vfio_ccw_private *private;
int ret;
if (pmcw->qf) {
dev_warn(&sch->dev, "vfio: ccw: does not support QDIO: %s\n",
dev_name(&sch->dev));
return -ENODEV;
}
private = kzalloc(sizeof(*private), GFP_KERNEL | GFP_DMA);
if (!private)
return -ENOMEM;
private->sch = sch;
dev_set_drvdata(&sch->dev, private);
spin_lock_irq(sch->lock);
private->state = VFIO_CCW_STATE_NOT_OPER;
sch->isc = VFIO_CCW_ISC;
ret = cio_enable_subchannel(sch, (u32)(unsigned long)sch);
spin_unlock_irq(sch->lock);
if (ret)
goto out_free;
ret = vfio_ccw_mdev_reg(sch);
if (ret)
goto out_disable;
INIT_WORK(&private->io_work, vfio_ccw_sch_io_todo);
atomic_set(&private->avail, 1);
private->state = VFIO_CCW_STATE_STANDBY;
return 0;
out_disable:
cio_disable_subchannel(sch);
out_free:
dev_set_drvdata(&sch->dev, NULL);
kfree(private);
return ret;
}
static int vfio_ccw_sch_remove(struct subchannel *sch)
{
struct vfio_ccw_private *private = dev_get_drvdata(&sch->dev);
vfio_ccw_sch_quiesce(sch);
vfio_ccw_mdev_unreg(sch);
dev_set_drvdata(&sch->dev, NULL);
kfree(private);
return 0;
}
static void vfio_ccw_sch_shutdown(struct subchannel *sch)
{
vfio_ccw_sch_quiesce(sch);
}
static int vfio_ccw_sch_event(struct subchannel *sch, int process)
{
struct vfio_ccw_private *private = dev_get_drvdata(&sch->dev);
unsigned long flags;
spin_lock_irqsave(sch->lock, flags);
if (!device_is_registered(&sch->dev))
goto out_unlock;
if (work_pending(&sch->todo_work))
goto out_unlock;
if (cio_update_schib(sch)) {
vfio_ccw_fsm_event(private, VFIO_CCW_EVENT_NOT_OPER);
goto out_unlock;
}
private = dev_get_drvdata(&sch->dev);
if (private->state == VFIO_CCW_STATE_NOT_OPER) {
private->state = private->mdev ? VFIO_CCW_STATE_IDLE :
VFIO_CCW_STATE_STANDBY;
}
out_unlock:
spin_unlock_irqrestore(sch->lock, flags);
return 0;
}
static int __init vfio_ccw_sch_init(void)
{
int ret;
vfio_ccw_work_q = create_singlethread_workqueue("vfio-ccw");
if (!vfio_ccw_work_q)
return -ENOMEM;
isc_register(VFIO_CCW_ISC);
ret = css_driver_register(&vfio_ccw_sch_driver);
if (ret) {
isc_unregister(VFIO_CCW_ISC);
destroy_workqueue(vfio_ccw_work_q);
}
return ret;
}
static void __exit vfio_ccw_sch_exit(void)
{
css_driver_unregister(&vfio_ccw_sch_driver);
isc_unregister(VFIO_CCW_ISC);
destroy_workqueue(vfio_ccw_work_q);
}
