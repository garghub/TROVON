static const struct rio_device_id *rio_match_device(const struct rio_device_id
*id,
const struct rio_dev *rdev)
{
while (id->vid || id->asm_vid) {
if (((id->vid == RIO_ANY_ID) || (id->vid == rdev->vid)) &&
((id->did == RIO_ANY_ID) || (id->did == rdev->did)) &&
((id->asm_vid == RIO_ANY_ID)
|| (id->asm_vid == rdev->asm_vid))
&& ((id->asm_did == RIO_ANY_ID)
|| (id->asm_did == rdev->asm_did)))
return id;
id++;
}
return NULL;
}
struct rio_dev *rio_dev_get(struct rio_dev *rdev)
{
if (rdev)
get_device(&rdev->dev);
return rdev;
}
void rio_dev_put(struct rio_dev *rdev)
{
if (rdev)
put_device(&rdev->dev);
}
static int rio_device_probe(struct device *dev)
{
struct rio_driver *rdrv = to_rio_driver(dev->driver);
struct rio_dev *rdev = to_rio_dev(dev);
int error = -ENODEV;
const struct rio_device_id *id;
if (!rdev->driver && rdrv->probe) {
if (!rdrv->id_table)
return error;
id = rio_match_device(rdrv->id_table, rdev);
rio_dev_get(rdev);
if (id)
error = rdrv->probe(rdev, id);
if (error >= 0) {
rdev->driver = rdrv;
error = 0;
} else
rio_dev_put(rdev);
}
return error;
}
static int rio_device_remove(struct device *dev)
{
struct rio_dev *rdev = to_rio_dev(dev);
struct rio_driver *rdrv = rdev->driver;
if (rdrv) {
if (rdrv->remove)
rdrv->remove(rdev);
rdev->driver = NULL;
}
rio_dev_put(rdev);
return 0;
}
static void rio_device_shutdown(struct device *dev)
{
struct rio_dev *rdev = to_rio_dev(dev);
struct rio_driver *rdrv = rdev->driver;
dev_dbg(dev, "RIO: %s\n", __func__);
if (rdrv && rdrv->shutdown)
rdrv->shutdown(rdev);
}
int rio_register_driver(struct rio_driver *rdrv)
{
rdrv->driver.name = rdrv->name;
rdrv->driver.bus = &rio_bus_type;
return driver_register(&rdrv->driver);
}
void rio_unregister_driver(struct rio_driver *rdrv)
{
driver_unregister(&rdrv->driver);
}
void rio_attach_device(struct rio_dev *rdev)
{
rdev->dev.bus = &rio_bus_type;
}
static int rio_match_bus(struct device *dev, struct device_driver *drv)
{
struct rio_dev *rdev = to_rio_dev(dev);
struct rio_driver *rdrv = to_rio_driver(drv);
const struct rio_device_id *id = rdrv->id_table;
const struct rio_device_id *found_id;
if (!id)
goto out;
found_id = rio_match_device(id, rdev);
if (found_id)
return 1;
out:return 0;
}
static int rio_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct rio_dev *rdev;
if (!dev)
return -ENODEV;
rdev = to_rio_dev(dev);
if (!rdev)
return -ENODEV;
if (add_uevent_var(env, "MODALIAS=rapidio:v%04Xd%04Xav%04Xad%04X",
rdev->vid, rdev->did, rdev->asm_vid, rdev->asm_did))
return -ENOMEM;
return 0;
}
static int __init rio_bus_init(void)
{
int ret;
ret = class_register(&rio_mport_class);
if (!ret) {
ret = bus_register(&rio_bus_type);
if (ret)
class_unregister(&rio_mport_class);
}
return ret;
}
