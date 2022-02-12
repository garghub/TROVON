static const char *tifm_media_type_name(unsigned char type, unsigned char nt)
{
const char *card_type_name[3][3] = {
{ "SmartMedia/xD", "MemoryStick", "MMC/SD" },
{ "XD", "MS", "SD"},
{ "xd", "ms", "sd"}
};
if (nt > 2 || type < 1 || type > 3)
return NULL;
return card_type_name[nt][type - 1];
}
static int tifm_dev_match(struct tifm_dev *sock, struct tifm_device_id *id)
{
if (sock->type == id->type)
return 1;
return 0;
}
static int tifm_bus_match(struct device *dev, struct device_driver *drv)
{
struct tifm_dev *sock = container_of(dev, struct tifm_dev, dev);
struct tifm_driver *fm_drv = container_of(drv, struct tifm_driver,
driver);
struct tifm_device_id *ids = fm_drv->id_table;
if (ids) {
while (ids->type) {
if (tifm_dev_match(sock, ids))
return 1;
++ids;
}
}
return 0;
}
static int tifm_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct tifm_dev *sock = container_of(dev, struct tifm_dev, dev);
if (add_uevent_var(env, "TIFM_CARD_TYPE=%s", tifm_media_type_name(sock->type, 1)))
return -ENOMEM;
return 0;
}
static int tifm_device_probe(struct device *dev)
{
struct tifm_dev *sock = container_of(dev, struct tifm_dev, dev);
struct tifm_driver *drv = container_of(dev->driver, struct tifm_driver,
driver);
int rc = -ENODEV;
get_device(dev);
if (dev->driver && drv->probe) {
rc = drv->probe(sock);
if (!rc)
return 0;
}
put_device(dev);
return rc;
}
static void tifm_dummy_event(struct tifm_dev *sock)
{
return;
}
static int tifm_device_remove(struct device *dev)
{
struct tifm_dev *sock = container_of(dev, struct tifm_dev, dev);
struct tifm_driver *drv = container_of(dev->driver, struct tifm_driver,
driver);
if (dev->driver && drv->remove) {
sock->card_event = tifm_dummy_event;
sock->data_event = tifm_dummy_event;
drv->remove(sock);
sock->dev.driver = NULL;
}
put_device(dev);
return 0;
}
static int tifm_device_suspend(struct device *dev, pm_message_t state)
{
struct tifm_dev *sock = container_of(dev, struct tifm_dev, dev);
struct tifm_driver *drv = container_of(dev->driver, struct tifm_driver,
driver);
if (dev->driver && drv->suspend)
return drv->suspend(sock, state);
return 0;
}
static int tifm_device_resume(struct device *dev)
{
struct tifm_dev *sock = container_of(dev, struct tifm_dev, dev);
struct tifm_driver *drv = container_of(dev->driver, struct tifm_driver,
driver);
if (dev->driver && drv->resume)
return drv->resume(sock);
return 0;
}
static ssize_t type_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct tifm_dev *sock = container_of(dev, struct tifm_dev, dev);
return sprintf(buf, "%x", sock->type);
}
static void tifm_free(struct device *dev)
{
struct tifm_adapter *fm = container_of(dev, struct tifm_adapter, dev);
kfree(fm);
}
struct tifm_adapter *tifm_alloc_adapter(unsigned int num_sockets,
struct device *dev)
{
struct tifm_adapter *fm;
fm = kzalloc(sizeof(struct tifm_adapter)
+ sizeof(struct tifm_dev*) * num_sockets, GFP_KERNEL);
if (fm) {
fm->dev.class = &tifm_adapter_class;
fm->dev.parent = dev;
device_initialize(&fm->dev);
spin_lock_init(&fm->lock);
fm->num_sockets = num_sockets;
}
return fm;
}
int tifm_add_adapter(struct tifm_adapter *fm)
{
int rc;
idr_preload(GFP_KERNEL);
spin_lock(&tifm_adapter_lock);
rc = idr_alloc(&tifm_adapter_idr, fm, 0, 0, GFP_NOWAIT);
if (rc >= 0)
fm->id = rc;
spin_unlock(&tifm_adapter_lock);
idr_preload_end();
if (rc < 0)
return rc;
dev_set_name(&fm->dev, "tifm%u", fm->id);
rc = device_add(&fm->dev);
if (rc) {
spin_lock(&tifm_adapter_lock);
idr_remove(&tifm_adapter_idr, fm->id);
spin_unlock(&tifm_adapter_lock);
}
return rc;
}
void tifm_remove_adapter(struct tifm_adapter *fm)
{
unsigned int cnt;
flush_workqueue(workqueue);
for (cnt = 0; cnt < fm->num_sockets; ++cnt) {
if (fm->sockets[cnt])
device_unregister(&fm->sockets[cnt]->dev);
}
spin_lock(&tifm_adapter_lock);
idr_remove(&tifm_adapter_idr, fm->id);
spin_unlock(&tifm_adapter_lock);
device_del(&fm->dev);
}
void tifm_free_adapter(struct tifm_adapter *fm)
{
put_device(&fm->dev);
}
void tifm_free_device(struct device *dev)
{
struct tifm_dev *sock = container_of(dev, struct tifm_dev, dev);
kfree(sock);
}
struct tifm_dev *tifm_alloc_device(struct tifm_adapter *fm, unsigned int id,
unsigned char type)
{
struct tifm_dev *sock = NULL;
if (!tifm_media_type_name(type, 0))
return sock;
sock = kzalloc(sizeof(struct tifm_dev), GFP_KERNEL);
if (sock) {
spin_lock_init(&sock->lock);
sock->type = type;
sock->socket_id = id;
sock->card_event = tifm_dummy_event;
sock->data_event = tifm_dummy_event;
sock->dev.parent = fm->dev.parent;
sock->dev.bus = &tifm_bus_type;
sock->dev.dma_mask = fm->dev.parent->dma_mask;
sock->dev.release = tifm_free_device;
dev_set_name(&sock->dev, "tifm_%s%u:%u",
tifm_media_type_name(type, 2), fm->id, id);
printk(KERN_INFO DRIVER_NAME
": %s card detected in socket %u:%u\n",
tifm_media_type_name(type, 0), fm->id, id);
}
return sock;
}
void tifm_eject(struct tifm_dev *sock)
{
struct tifm_adapter *fm = dev_get_drvdata(sock->dev.parent);
fm->eject(fm, sock);
}
int tifm_has_ms_pif(struct tifm_dev *sock)
{
struct tifm_adapter *fm = dev_get_drvdata(sock->dev.parent);
return fm->has_ms_pif(fm, sock);
}
int tifm_map_sg(struct tifm_dev *sock, struct scatterlist *sg, int nents,
int direction)
{
return pci_map_sg(to_pci_dev(sock->dev.parent), sg, nents, direction);
}
void tifm_unmap_sg(struct tifm_dev *sock, struct scatterlist *sg, int nents,
int direction)
{
pci_unmap_sg(to_pci_dev(sock->dev.parent), sg, nents, direction);
}
void tifm_queue_work(struct work_struct *work)
{
queue_work(workqueue, work);
}
int tifm_register_driver(struct tifm_driver *drv)
{
drv->driver.bus = &tifm_bus_type;
return driver_register(&drv->driver);
}
void tifm_unregister_driver(struct tifm_driver *drv)
{
driver_unregister(&drv->driver);
}
static int __init tifm_init(void)
{
int rc;
workqueue = create_freezable_workqueue("tifm");
if (!workqueue)
return -ENOMEM;
rc = bus_register(&tifm_bus_type);
if (rc)
goto err_out_wq;
rc = class_register(&tifm_adapter_class);
if (!rc)
return 0;
bus_unregister(&tifm_bus_type);
err_out_wq:
destroy_workqueue(workqueue);
return rc;
}
static void __exit tifm_exit(void)
{
class_unregister(&tifm_adapter_class);
bus_unregister(&tifm_bus_type);
destroy_workqueue(workqueue);
}
