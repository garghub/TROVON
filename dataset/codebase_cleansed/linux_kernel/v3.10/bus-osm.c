static int i2o_bus_scan(struct i2o_device *dev)
{
struct i2o_message *msg;
msg = i2o_msg_get_wait(dev->iop, I2O_TIMEOUT_MESSAGE_GET);
if (IS_ERR(msg))
return -ETIMEDOUT;
msg->u.head[0] = cpu_to_le32(FIVE_WORD_MSG_SIZE | SGL_OFFSET_0);
msg->u.head[1] =
cpu_to_le32(I2O_CMD_BUS_SCAN << 24 | HOST_TID << 12 | dev->lct_data.
tid);
return i2o_msg_post_wait(dev->iop, msg, 60);
}
static ssize_t i2o_bus_store_scan(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2o_device *i2o_dev = to_i2o_device(d);
int rc;
if ((rc = i2o_bus_scan(i2o_dev)))
osm_warn("bus scan failed %d\n", rc);
return count;
}
static int i2o_bus_probe(struct device *dev)
{
struct i2o_device *i2o_dev = to_i2o_device(get_device(dev));
int rc;
rc = device_create_file(dev, &dev_attr_scan);
if (rc)
goto err_out;
osm_info("device added (TID: %03x)\n", i2o_dev->lct_data.tid);
return 0;
err_out:
put_device(dev);
return rc;
}
static int i2o_bus_remove(struct device *dev)
{
struct i2o_device *i2o_dev = to_i2o_device(dev);
device_remove_file(dev, &dev_attr_scan);
put_device(dev);
osm_info("device removed (TID: %03x)\n", i2o_dev->lct_data.tid);
return 0;
}
static int __init i2o_bus_init(void)
{
int rc;
printk(KERN_INFO OSM_DESCRIPTION " v" OSM_VERSION "\n");
rc = i2o_driver_register(&i2o_bus_driver);
if (rc) {
osm_err("Could not register Bus Adapter OSM\n");
return rc;
}
return 0;
}
static void __exit i2o_bus_exit(void)
{
i2o_driver_unregister(&i2o_bus_driver);
}
