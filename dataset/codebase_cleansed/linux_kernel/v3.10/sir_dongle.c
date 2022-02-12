int irda_register_dongle(struct dongle_driver *new)
{
struct list_head *entry;
struct dongle_driver *drv;
IRDA_DEBUG(0, "%s : registering dongle \"%s\" (%d).\n",
__func__, new->driver_name, new->type);
mutex_lock(&dongle_list_lock);
list_for_each(entry, &dongle_list) {
drv = list_entry(entry, struct dongle_driver, dongle_list);
if (new->type == drv->type) {
mutex_unlock(&dongle_list_lock);
return -EEXIST;
}
}
list_add(&new->dongle_list, &dongle_list);
mutex_unlock(&dongle_list_lock);
return 0;
}
int irda_unregister_dongle(struct dongle_driver *drv)
{
mutex_lock(&dongle_list_lock);
list_del(&drv->dongle_list);
mutex_unlock(&dongle_list_lock);
return 0;
}
int sirdev_get_dongle(struct sir_dev *dev, IRDA_DONGLE type)
{
struct list_head *entry;
const struct dongle_driver *drv = NULL;
int err = -EINVAL;
request_module("irda-dongle-%d", type);
if (dev->dongle_drv != NULL)
return -EBUSY;
mutex_lock(&dongle_list_lock);
list_for_each(entry, &dongle_list) {
drv = list_entry(entry, struct dongle_driver, dongle_list);
if (drv->type == type)
break;
else
drv = NULL;
}
if (!drv) {
err = -ENODEV;
goto out_unlock;
}
if (!try_module_get(drv->owner)) {
err = -ESTALE;
goto out_unlock;
}
dev->dongle_drv = drv;
if (!drv->open || (err=drv->open(dev))!=0)
goto out_reject;
mutex_unlock(&dongle_list_lock);
return 0;
out_reject:
dev->dongle_drv = NULL;
module_put(drv->owner);
out_unlock:
mutex_unlock(&dongle_list_lock);
return err;
}
int sirdev_put_dongle(struct sir_dev *dev)
{
const struct dongle_driver *drv = dev->dongle_drv;
if (drv) {
if (drv->close)
drv->close(dev);
dev->dongle_drv = NULL;
module_put(drv->owner);
}
return 0;
}
