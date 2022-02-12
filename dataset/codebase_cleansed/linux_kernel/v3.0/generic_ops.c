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
static int __pm_generic_call(struct device *dev, int event)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int (*callback)(struct device *);
if (!pm || pm_runtime_suspended(dev))
return 0;
switch (event) {
case PM_EVENT_SUSPEND:
callback = pm->suspend;
break;
case PM_EVENT_FREEZE:
callback = pm->freeze;
break;
case PM_EVENT_HIBERNATE:
callback = pm->poweroff;
break;
case PM_EVENT_THAW:
callback = pm->thaw;
break;
default:
callback = NULL;
break;
}
return callback ? callback(dev) : 0;
}
int pm_generic_suspend(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_SUSPEND);
}
int pm_generic_freeze(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_FREEZE);
}
int pm_generic_poweroff(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_HIBERNATE);
}
int pm_generic_thaw(struct device *dev)
{
return __pm_generic_call(dev, PM_EVENT_THAW);
}
static int __pm_generic_resume(struct device *dev, int event)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int (*callback)(struct device *);
int ret;
if (!pm)
return 0;
switch (event) {
case PM_EVENT_RESUME:
callback = pm->resume;
break;
case PM_EVENT_RESTORE:
callback = pm->restore;
break;
default:
callback = NULL;
break;
}
if (!callback)
return 0;
ret = callback(dev);
if (!ret && pm_runtime_enabled(dev)) {
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
}
return ret;
}
int pm_generic_resume(struct device *dev)
{
return __pm_generic_resume(dev, PM_EVENT_RESUME);
}
int pm_generic_restore(struct device *dev)
{
return __pm_generic_resume(dev, PM_EVENT_RESTORE);
}
void pm_generic_complete(struct device *dev)
{
struct device_driver *drv = dev->driver;
if (drv && drv->pm && drv->pm->complete)
drv->pm->complete(dev);
pm_runtime_idle(dev);
}
