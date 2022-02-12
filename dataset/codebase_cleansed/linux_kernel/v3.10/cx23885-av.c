void cx23885_av_work_handler(struct work_struct *work)
{
struct cx23885_dev *dev =
container_of(work, struct cx23885_dev, cx25840_work);
bool handled;
v4l2_subdev_call(dev->sd_cx25840, core, interrupt_service_routine,
PCI_MSK_AV_CORE, &handled);
cx23885_irq_enable(dev, PCI_MSK_AV_CORE);
}
