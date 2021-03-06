int pm_generic_runtime_suspend(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int ret;
ret = pm && pm->runtime_suspend ? pm->runtime_suspend(dev) : 0;
return ret;
}
int pm_generic_runtime_resume(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int ret;
ret = pm && pm->runtime_resume ? pm->runtime_resume(dev) : 0;
return ret;
}
int pm_generic_prepare(struct device *dev)
{
struct device_driver *drv = dev->driver;
int ret = 0;
if (drv && drv->pm && drv->pm->prepare)
ret = drv->pm->prepare(dev);
return ret;
}
int pm_generic_suspend_noirq(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->suspend_noirq ? pm->suspend_noirq(dev) : 0;
}
int pm_generic_suspend_late(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->suspend_late ? pm->suspend_late(dev) : 0;
}
int pm_generic_suspend(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->suspend ? pm->suspend(dev) : 0;
}
int pm_generic_freeze_noirq(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->freeze_noirq ? pm->freeze_noirq(dev) : 0;
}
int pm_generic_freeze_late(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->freeze_late ? pm->freeze_late(dev) : 0;
}
int pm_generic_freeze(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->freeze ? pm->freeze(dev) : 0;
}
int pm_generic_poweroff_noirq(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->poweroff_noirq ? pm->poweroff_noirq(dev) : 0;
}
int pm_generic_poweroff_late(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->poweroff_late ? pm->poweroff_late(dev) : 0;
}
int pm_generic_poweroff(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->poweroff ? pm->poweroff(dev) : 0;
}
int pm_generic_thaw_noirq(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->thaw_noirq ? pm->thaw_noirq(dev) : 0;
}
int pm_generic_thaw_early(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->thaw_early ? pm->thaw_early(dev) : 0;
}
int pm_generic_thaw(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->thaw ? pm->thaw(dev) : 0;
}
int pm_generic_resume_noirq(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->resume_noirq ? pm->resume_noirq(dev) : 0;
}
int pm_generic_resume_early(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->resume_early ? pm->resume_early(dev) : 0;
}
int pm_generic_resume(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->resume ? pm->resume(dev) : 0;
}
int pm_generic_restore_noirq(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->restore_noirq ? pm->restore_noirq(dev) : 0;
}
int pm_generic_restore_early(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->restore_early ? pm->restore_early(dev) : 0;
}
int pm_generic_restore(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return pm && pm->restore ? pm->restore(dev) : 0;
}
void pm_generic_complete(struct device *dev)
{
struct device_driver *drv = dev->driver;
if (drv && drv->pm && drv->pm->complete)
drv->pm->complete(dev);
}
void pm_complete_with_resume_check(struct device *dev)
{
pm_generic_complete(dev);
if (dev->power.direct_complete && pm_resume_via_firmware())
pm_request_resume(dev);
}
