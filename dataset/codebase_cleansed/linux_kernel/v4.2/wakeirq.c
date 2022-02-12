static int dev_pm_attach_wake_irq(struct device *dev, int irq,
struct wake_irq *wirq)
{
unsigned long flags;
int err;
if (!dev || !wirq)
return -EINVAL;
spin_lock_irqsave(&dev->power.lock, flags);
if (dev_WARN_ONCE(dev, dev->power.wakeirq,
"wake irq already initialized\n")) {
spin_unlock_irqrestore(&dev->power.lock, flags);
return -EEXIST;
}
err = device_wakeup_attach_irq(dev, wirq);
if (!err)
dev->power.wakeirq = wirq;
spin_unlock_irqrestore(&dev->power.lock, flags);
return err;
}
int dev_pm_set_wake_irq(struct device *dev, int irq)
{
struct wake_irq *wirq;
int err;
wirq = kzalloc(sizeof(*wirq), GFP_KERNEL);
if (!wirq)
return -ENOMEM;
wirq->dev = dev;
wirq->irq = irq;
err = dev_pm_attach_wake_irq(dev, irq, wirq);
if (err)
kfree(wirq);
return err;
}
void dev_pm_clear_wake_irq(struct device *dev)
{
struct wake_irq *wirq = dev->power.wakeirq;
unsigned long flags;
if (!wirq)
return;
spin_lock_irqsave(&dev->power.lock, flags);
device_wakeup_detach_irq(dev);
dev->power.wakeirq = NULL;
spin_unlock_irqrestore(&dev->power.lock, flags);
if (wirq->dedicated_irq)
free_irq(wirq->irq, wirq);
kfree(wirq);
}
static irqreturn_t handle_threaded_wake_irq(int irq, void *_wirq)
{
struct wake_irq *wirq = _wirq;
int res;
res = pm_runtime_resume(wirq->dev);
if (res < 0)
dev_warn(wirq->dev,
"wake IRQ with no resume: %i\n", res);
return IRQ_HANDLED;
}
int dev_pm_set_dedicated_wake_irq(struct device *dev, int irq)
{
struct wake_irq *wirq;
int err;
wirq = kzalloc(sizeof(*wirq), GFP_KERNEL);
if (!wirq)
return -ENOMEM;
wirq->dev = dev;
wirq->irq = irq;
wirq->dedicated_irq = true;
irq_set_status_flags(irq, IRQ_NOAUTOEN);
err = request_threaded_irq(irq, NULL, handle_threaded_wake_irq,
IRQF_ONESHOT, dev_name(dev), wirq);
if (err)
goto err_free;
err = dev_pm_attach_wake_irq(dev, irq, wirq);
if (err)
goto err_free_irq;
return err;
err_free_irq:
free_irq(irq, wirq);
err_free:
kfree(wirq);
return err;
}
void dev_pm_enable_wake_irq(struct device *dev)
{
struct wake_irq *wirq = dev->power.wakeirq;
if (wirq && wirq->dedicated_irq)
enable_irq(wirq->irq);
}
void dev_pm_disable_wake_irq(struct device *dev)
{
struct wake_irq *wirq = dev->power.wakeirq;
if (wirq && wirq->dedicated_irq)
disable_irq_nosync(wirq->irq);
}
void dev_pm_arm_wake_irq(struct wake_irq *wirq)
{
if (!wirq)
return;
if (device_may_wakeup(wirq->dev))
enable_irq_wake(wirq->irq);
}
void dev_pm_disarm_wake_irq(struct wake_irq *wirq)
{
if (!wirq)
return;
if (device_may_wakeup(wirq->dev))
disable_irq_wake(wirq->irq);
}
