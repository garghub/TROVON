int pm_generic_runtime_idle(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
if (pm && pm->runtime_idle) {
int ret = pm->runtime_idle(dev);
if (ret)
return ret;
}
pm_runtime_suspend(dev);
return 0;
}
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
static int __pm_generic_call(struct device *dev, int event, bool noirq)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int (*callback)(struct device *);
if (!pm || pm_runtime_suspended(dev))
return 0;
switch (event) {
case PM_EVENT_SUSPEND:
callback = noirq ? pm->suspend_noirq : pm->suspend;
break;
case PM_EVENT_FREEZE:
callback = noirq ? pm->freeze_noirq : pm->freeze;
break;
case PM_EVENT_HIBERNATE:
callback = noirq ? pm->poweroff_noirq : pm->poweroff;
break;
case PM_EVENT_THAW:
callback = noirq ? pm->thaw_noirq : pm->thaw;
break;
default:
callback = NULL;
break;
}
return callback ? callback(dev) : 0;
}
int pm_generic_suspend_noirq(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_SUSPEND, true);
}
int pm_generic_suspend(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_SUSPEND, false);
}
int pm_generic_freeze_noirq(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_FREEZE, true);
}
int pm_generic_freeze(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_FREEZE, false);
}
int pm_generic_poweroff_noirq(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_HIBERNATE, true);
}
int pm_generic_poweroff(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_HIBERNATE, false);
}
int pm_generic_thaw_noirq(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_THAW, true);
}
int pm_generic_thaw(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_THAW, false);
}
static int __pm_generic_resume(struct device *dev, int event, bool noirq)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int (*callback)(struct device *);
int ret;
if (!pm)
return 0;
switch (event) {
case PM_EVENT_RESUME:
callback = noirq ? pm->resume_noirq : pm->resume;
break;
case PM_EVENT_RESTORE:
callback = noirq ? pm->restore_noirq : pm->restore;
break;
default:
callback = NULL;
break;
}
if (!callback)
return 0;
ret = callback(dev);
if (!ret && !noirq && pm_runtime_enabled(dev)) {
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
}
return ret;
}
int pm_generic_resume_noirq(struct device *dev)
{
return __pm_generic_resume(dev, PM_EVENT_RESUME, true);
}
int pm_generic_resume(struct device *dev)
{
return __pm_generic_resume(dev, PM_EVENT_RESUME, false);
}
int pm_generic_restore_noirq(struct device *dev)
{
return __pm_generic_resume(dev, PM_EVENT_RESTORE, true);
}
int pm_generic_restore(struct device *dev)
{
return __pm_generic_resume(dev, PM_EVENT_RESTORE, false);
}
void pm_generic_complete(struct device *dev)
{
struct device_driver *drv = dev->driver;
if (drv && drv->pm && drv->pm->complete)
drv->pm->complete(dev);
pm_runtime_idle(dev);
}
