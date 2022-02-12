static int turn_off(struct gb_vibrator_device *vib)
{
struct gb_bundle *bundle = vib->connection->bundle;
int ret;
ret = gb_operation_sync(vib->connection, GB_VIBRATOR_TYPE_OFF,
NULL, 0, NULL, 0);
gb_pm_runtime_put_autosuspend(bundle);
return ret;
}
static int turn_on(struct gb_vibrator_device *vib, u16 timeout_ms)
{
struct gb_bundle *bundle = vib->connection->bundle;
int ret;
ret = gb_pm_runtime_get_sync(bundle);
if (ret)
return ret;
if (cancel_delayed_work_sync(&vib->delayed_work))
turn_off(vib);
ret = gb_operation_sync(vib->connection, GB_VIBRATOR_TYPE_ON,
NULL, 0, NULL, 0);
if (ret) {
gb_pm_runtime_put_autosuspend(bundle);
return ret;
}
schedule_delayed_work(&vib->delayed_work, msecs_to_jiffies(timeout_ms));
return 0;
}
static void gb_vibrator_worker(struct work_struct *work)
{
struct delayed_work *delayed_work = to_delayed_work(work);
struct gb_vibrator_device *vib =
container_of(delayed_work,
struct gb_vibrator_device,
delayed_work);
turn_off(vib);
}
static ssize_t timeout_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct gb_vibrator_device *vib = dev_get_drvdata(dev);
unsigned long val;
int retval;
retval = kstrtoul(buf, 10, &val);
if (retval < 0) {
dev_err(dev, "could not parse timeout value %d\n", retval);
return retval;
}
if (val)
retval = turn_on(vib, (u16)val);
else
retval = turn_off(vib);
if (retval)
return retval;
return count;
}
static int gb_vibrator_probe(struct gb_bundle *bundle,
const struct greybus_bundle_id *id)
{
struct greybus_descriptor_cport *cport_desc;
struct gb_connection *connection;
struct gb_vibrator_device *vib;
struct device *dev;
int retval;
if (bundle->num_cports != 1)
return -ENODEV;
cport_desc = &bundle->cport_desc[0];
if (cport_desc->protocol_id != GREYBUS_PROTOCOL_VIBRATOR)
return -ENODEV;
vib = kzalloc(sizeof(*vib), GFP_KERNEL);
if (!vib)
return -ENOMEM;
connection = gb_connection_create(bundle, le16_to_cpu(cport_desc->id),
NULL);
if (IS_ERR(connection)) {
retval = PTR_ERR(connection);
goto err_free_vib;
}
gb_connection_set_data(connection, vib);
vib->connection = connection;
greybus_set_drvdata(bundle, vib);
retval = gb_connection_enable(connection);
if (retval)
goto err_connection_destroy;
vib->minor = ida_simple_get(&minors, 0, 0, GFP_KERNEL);
if (vib->minor < 0) {
retval = vib->minor;
goto err_connection_disable;
}
dev = device_create(&vibrator_class, &bundle->dev,
MKDEV(0, 0), vib, "vibrator%d", vib->minor);
if (IS_ERR(dev)) {
retval = -EINVAL;
goto err_ida_remove;
}
vib->dev = dev;
INIT_DELAYED_WORK(&vib->delayed_work, gb_vibrator_worker);
gb_pm_runtime_put_autosuspend(bundle);
return 0;
err_ida_remove:
ida_simple_remove(&minors, vib->minor);
err_connection_disable:
gb_connection_disable(connection);
err_connection_destroy:
gb_connection_destroy(connection);
err_free_vib:
kfree(vib);
return retval;
}
static void gb_vibrator_disconnect(struct gb_bundle *bundle)
{
struct gb_vibrator_device *vib = greybus_get_drvdata(bundle);
int ret;
ret = gb_pm_runtime_get_sync(bundle);
if (ret)
gb_pm_runtime_get_noresume(bundle);
if (cancel_delayed_work_sync(&vib->delayed_work))
turn_off(vib);
device_unregister(vib->dev);
ida_simple_remove(&minors, vib->minor);
gb_connection_disable(vib->connection);
gb_connection_destroy(vib->connection);
kfree(vib);
}
static __init int gb_vibrator_init(void)
{
int retval;
retval = class_register(&vibrator_class);
if (retval)
return retval;
retval = greybus_register(&gb_vibrator_driver);
if (retval)
goto err_class_unregister;
return 0;
err_class_unregister:
class_unregister(&vibrator_class);
return retval;
}
static __exit void gb_vibrator_exit(void)
{
greybus_deregister(&gb_vibrator_driver);
class_unregister(&vibrator_class);
ida_destroy(&minors);
}
