static const char *
scsi_dh_find_driver(struct scsi_device *sdev)
{
const struct scsi_dh_blist *b;
if (scsi_device_tpgs(sdev))
return "alua";
for (b = scsi_dh_blist; b->vendor; b++) {
if (!strncmp(sdev->vendor, b->vendor, strlen(b->vendor)) &&
!strncmp(sdev->model, b->model, strlen(b->model))) {
return b->driver;
}
}
return NULL;
}
static struct scsi_device_handler *__scsi_dh_lookup(const char *name)
{
struct scsi_device_handler *tmp, *found = NULL;
spin_lock(&list_lock);
list_for_each_entry(tmp, &scsi_dh_list, list) {
if (!strncmp(tmp->name, name, strlen(tmp->name))) {
found = tmp;
break;
}
}
spin_unlock(&list_lock);
return found;
}
static struct scsi_device_handler *scsi_dh_lookup(const char *name)
{
struct scsi_device_handler *dh;
dh = __scsi_dh_lookup(name);
if (!dh) {
request_module("scsi_dh_%s", name);
dh = __scsi_dh_lookup(name);
}
return dh;
}
static int scsi_dh_handler_attach(struct scsi_device *sdev,
struct scsi_device_handler *scsi_dh)
{
int error;
if (!try_module_get(scsi_dh->module))
return -EINVAL;
error = scsi_dh->attach(sdev);
if (error) {
sdev_printk(KERN_ERR, sdev, "%s: Attach failed (%d)\n",
scsi_dh->name, error);
module_put(scsi_dh->module);
} else
sdev->handler = scsi_dh;
return error;
}
static void scsi_dh_handler_detach(struct scsi_device *sdev)
{
sdev->handler->detach(sdev);
sdev_printk(KERN_NOTICE, sdev, "%s: Detached\n", sdev->handler->name);
module_put(sdev->handler->module);
}
int scsi_dh_add_device(struct scsi_device *sdev)
{
struct scsi_device_handler *devinfo = NULL;
const char *drv;
int err = 0;
drv = scsi_dh_find_driver(sdev);
if (drv)
devinfo = __scsi_dh_lookup(drv);
if (devinfo)
err = scsi_dh_handler_attach(sdev, devinfo);
return err;
}
void scsi_dh_release_device(struct scsi_device *sdev)
{
if (sdev->handler)
scsi_dh_handler_detach(sdev);
}
int scsi_register_device_handler(struct scsi_device_handler *scsi_dh)
{
if (__scsi_dh_lookup(scsi_dh->name))
return -EBUSY;
if (!scsi_dh->attach || !scsi_dh->detach)
return -EINVAL;
spin_lock(&list_lock);
list_add(&scsi_dh->list, &scsi_dh_list);
spin_unlock(&list_lock);
printk(KERN_INFO "%s: device handler registered\n", scsi_dh->name);
return SCSI_DH_OK;
}
int scsi_unregister_device_handler(struct scsi_device_handler *scsi_dh)
{
if (!__scsi_dh_lookup(scsi_dh->name))
return -ENODEV;
spin_lock(&list_lock);
list_del(&scsi_dh->list);
spin_unlock(&list_lock);
printk(KERN_INFO "%s: device handler unregistered\n", scsi_dh->name);
return SCSI_DH_OK;
}
static struct scsi_device *get_sdev_from_queue(struct request_queue *q)
{
struct scsi_device *sdev;
unsigned long flags;
spin_lock_irqsave(q->queue_lock, flags);
sdev = q->queuedata;
if (!sdev || !get_device(&sdev->sdev_gendev))
sdev = NULL;
spin_unlock_irqrestore(q->queue_lock, flags);
return sdev;
}
int scsi_dh_activate(struct request_queue *q, activate_complete fn, void *data)
{
struct scsi_device *sdev;
int err = SCSI_DH_NOSYS;
sdev = get_sdev_from_queue(q);
if (!sdev) {
if (fn)
fn(data, err);
return err;
}
if (!sdev->handler)
goto out_fn;
err = SCSI_DH_NOTCONN;
if (sdev->sdev_state == SDEV_CANCEL ||
sdev->sdev_state == SDEV_DEL)
goto out_fn;
err = SCSI_DH_DEV_OFFLINED;
if (sdev->sdev_state == SDEV_OFFLINE)
goto out_fn;
if (sdev->handler->activate)
err = sdev->handler->activate(sdev, fn, data);
out_put_device:
put_device(&sdev->sdev_gendev);
return err;
out_fn:
if (fn)
fn(data, err);
goto out_put_device;
}
int scsi_dh_set_params(struct request_queue *q, const char *params)
{
struct scsi_device *sdev;
int err = -SCSI_DH_NOSYS;
sdev = get_sdev_from_queue(q);
if (!sdev)
return err;
if (sdev->handler && sdev->handler->set_params)
err = sdev->handler->set_params(sdev, params);
put_device(&sdev->sdev_gendev);
return err;
}
int scsi_dh_attach(struct request_queue *q, const char *name)
{
struct scsi_device *sdev;
struct scsi_device_handler *scsi_dh;
int err = 0;
sdev = get_sdev_from_queue(q);
if (!sdev)
return -ENODEV;
scsi_dh = scsi_dh_lookup(name);
if (!scsi_dh) {
err = -EINVAL;
goto out_put_device;
}
if (sdev->handler) {
if (sdev->handler != scsi_dh)
err = -EBUSY;
goto out_put_device;
}
err = scsi_dh_handler_attach(sdev, scsi_dh);
out_put_device:
put_device(&sdev->sdev_gendev);
return err;
}
const char *scsi_dh_attached_handler_name(struct request_queue *q, gfp_t gfp)
{
struct scsi_device *sdev;
const char *handler_name = NULL;
sdev = get_sdev_from_queue(q);
if (!sdev)
return NULL;
if (sdev->handler)
handler_name = kstrdup(sdev->handler->name, gfp);
put_device(&sdev->sdev_gendev);
return handler_name;
}
