static int fpga_bridge_of_node_match(struct device *dev, const void *data)
{
return dev->of_node == data;
}
int fpga_bridge_enable(struct fpga_bridge *bridge)
{
dev_dbg(&bridge->dev, "enable\n");
if (bridge->br_ops && bridge->br_ops->enable_set)
return bridge->br_ops->enable_set(bridge, 1);
return 0;
}
int fpga_bridge_disable(struct fpga_bridge *bridge)
{
dev_dbg(&bridge->dev, "disable\n");
if (bridge->br_ops && bridge->br_ops->enable_set)
return bridge->br_ops->enable_set(bridge, 0);
return 0;
}
struct fpga_bridge *of_fpga_bridge_get(struct device_node *np,
struct fpga_image_info *info)
{
struct device *dev;
struct fpga_bridge *bridge;
int ret = -ENODEV;
dev = class_find_device(fpga_bridge_class, NULL, np,
fpga_bridge_of_node_match);
if (!dev)
goto err_dev;
bridge = to_fpga_bridge(dev);
if (!bridge)
goto err_dev;
bridge->info = info;
if (!mutex_trylock(&bridge->mutex)) {
ret = -EBUSY;
goto err_dev;
}
if (!try_module_get(dev->parent->driver->owner))
goto err_ll_mod;
dev_dbg(&bridge->dev, "get\n");
return bridge;
err_ll_mod:
mutex_unlock(&bridge->mutex);
err_dev:
put_device(dev);
return ERR_PTR(ret);
}
void fpga_bridge_put(struct fpga_bridge *bridge)
{
dev_dbg(&bridge->dev, "put\n");
bridge->info = NULL;
module_put(bridge->dev.parent->driver->owner);
mutex_unlock(&bridge->mutex);
put_device(&bridge->dev);
}
int fpga_bridges_enable(struct list_head *bridge_list)
{
struct fpga_bridge *bridge;
int ret;
list_for_each_entry(bridge, bridge_list, node) {
ret = fpga_bridge_enable(bridge);
if (ret)
return ret;
}
return 0;
}
int fpga_bridges_disable(struct list_head *bridge_list)
{
struct fpga_bridge *bridge;
int ret;
list_for_each_entry(bridge, bridge_list, node) {
ret = fpga_bridge_disable(bridge);
if (ret)
return ret;
}
return 0;
}
void fpga_bridges_put(struct list_head *bridge_list)
{
struct fpga_bridge *bridge, *next;
unsigned long flags;
list_for_each_entry_safe(bridge, next, bridge_list, node) {
fpga_bridge_put(bridge);
spin_lock_irqsave(&bridge_list_lock, flags);
list_del(&bridge->node);
spin_unlock_irqrestore(&bridge_list_lock, flags);
}
}
int fpga_bridge_get_to_list(struct device_node *np,
struct fpga_image_info *info,
struct list_head *bridge_list)
{
struct fpga_bridge *bridge;
unsigned long flags;
bridge = of_fpga_bridge_get(np, info);
if (IS_ERR(bridge))
return PTR_ERR(bridge);
spin_lock_irqsave(&bridge_list_lock, flags);
list_add(&bridge->node, bridge_list);
spin_unlock_irqrestore(&bridge_list_lock, flags);
return 0;
}
static ssize_t name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fpga_bridge *bridge = to_fpga_bridge(dev);
return sprintf(buf, "%s\n", bridge->name);
}
static ssize_t state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fpga_bridge *bridge = to_fpga_bridge(dev);
int enable = 1;
if (bridge->br_ops && bridge->br_ops->enable_show)
enable = bridge->br_ops->enable_show(bridge);
return sprintf(buf, "%s\n", enable ? "enabled" : "disabled");
}
int fpga_bridge_register(struct device *dev, const char *name,
const struct fpga_bridge_ops *br_ops, void *priv)
{
struct fpga_bridge *bridge;
int id, ret = 0;
if (!name || !strlen(name)) {
dev_err(dev, "Attempt to register with no name!\n");
return -EINVAL;
}
bridge = kzalloc(sizeof(*bridge), GFP_KERNEL);
if (!bridge)
return -ENOMEM;
id = ida_simple_get(&fpga_bridge_ida, 0, 0, GFP_KERNEL);
if (id < 0) {
ret = id;
goto error_kfree;
}
mutex_init(&bridge->mutex);
INIT_LIST_HEAD(&bridge->node);
bridge->name = name;
bridge->br_ops = br_ops;
bridge->priv = priv;
device_initialize(&bridge->dev);
bridge->dev.class = fpga_bridge_class;
bridge->dev.parent = dev;
bridge->dev.of_node = dev->of_node;
bridge->dev.id = id;
dev_set_drvdata(dev, bridge);
ret = dev_set_name(&bridge->dev, "br%d", id);
if (ret)
goto error_device;
ret = device_add(&bridge->dev);
if (ret)
goto error_device;
of_platform_populate(dev->of_node, NULL, NULL, dev);
dev_info(bridge->dev.parent, "fpga bridge [%s] registered\n",
bridge->name);
return 0;
error_device:
ida_simple_remove(&fpga_bridge_ida, id);
error_kfree:
kfree(bridge);
return ret;
}
void fpga_bridge_unregister(struct device *dev)
{
struct fpga_bridge *bridge = dev_get_drvdata(dev);
if (bridge->br_ops && bridge->br_ops->fpga_bridge_remove)
bridge->br_ops->fpga_bridge_remove(bridge);
device_unregister(&bridge->dev);
}
static void fpga_bridge_dev_release(struct device *dev)
{
struct fpga_bridge *bridge = to_fpga_bridge(dev);
ida_simple_remove(&fpga_bridge_ida, bridge->dev.id);
kfree(bridge);
}
static int __init fpga_bridge_dev_init(void)
{
spin_lock_init(&bridge_list_lock);
fpga_bridge_class = class_create(THIS_MODULE, "fpga_bridge");
if (IS_ERR(fpga_bridge_class))
return PTR_ERR(fpga_bridge_class);
fpga_bridge_class->dev_groups = fpga_bridge_groups;
fpga_bridge_class->dev_release = fpga_bridge_dev_release;
return 0;
}
static void __exit fpga_bridge_dev_exit(void)
{
class_destroy(fpga_bridge_class);
ida_destroy(&fpga_bridge_ida);
}
