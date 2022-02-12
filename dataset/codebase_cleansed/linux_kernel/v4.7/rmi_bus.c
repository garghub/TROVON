void rmi_dbg(int flags, struct device *dev, const char *fmt, ...)
{
struct va_format vaf;
va_list args;
if (flags & debug_flags) {
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
dev_printk(KERN_DEBUG, dev, "%pV", &vaf);
va_end(args);
}
}
static void rmi_release_device(struct device *dev)
{
struct rmi_device *rmi_dev = to_rmi_device(dev);
kfree(rmi_dev);
}
bool rmi_is_physical_device(struct device *dev)
{
return dev->type == &rmi_device_type;
}
int rmi_register_transport_device(struct rmi_transport_dev *xport)
{
static atomic_t transport_device_count = ATOMIC_INIT(0);
struct rmi_device *rmi_dev;
int error;
rmi_dev = kzalloc(sizeof(struct rmi_device), GFP_KERNEL);
if (!rmi_dev)
return -ENOMEM;
device_initialize(&rmi_dev->dev);
rmi_dev->xport = xport;
rmi_dev->number = atomic_inc_return(&transport_device_count) - 1;
dev_set_name(&rmi_dev->dev, "rmi4-%02d", rmi_dev->number);
rmi_dev->dev.bus = &rmi_bus_type;
rmi_dev->dev.type = &rmi_device_type;
xport->rmi_dev = rmi_dev;
error = device_add(&rmi_dev->dev);
if (error)
goto err_put_device;
rmi_dbg(RMI_DEBUG_CORE, xport->dev,
"%s: Registered %s as %s.\n", __func__,
dev_name(rmi_dev->xport->dev), dev_name(&rmi_dev->dev));
return 0;
err_put_device:
put_device(&rmi_dev->dev);
return error;
}
void rmi_unregister_transport_device(struct rmi_transport_dev *xport)
{
struct rmi_device *rmi_dev = xport->rmi_dev;
device_del(&rmi_dev->dev);
put_device(&rmi_dev->dev);
}
static void rmi_release_function(struct device *dev)
{
struct rmi_function *fn = to_rmi_function(dev);
kfree(fn);
}
bool rmi_is_function_device(struct device *dev)
{
return dev->type == &rmi_function_type;
}
static int rmi_function_match(struct device *dev, struct device_driver *drv)
{
struct rmi_function_handler *handler = to_rmi_function_handler(drv);
struct rmi_function *fn = to_rmi_function(dev);
return fn->fd.function_number == handler->func;
}
static void rmi_function_of_probe(struct rmi_function *fn)
{
char of_name[9];
struct device_node *node = fn->rmi_dev->xport->dev->of_node;
snprintf(of_name, sizeof(of_name), "rmi4-f%02x",
fn->fd.function_number);
fn->dev.of_node = of_get_child_by_name(node, of_name);
}
static inline void rmi_function_of_probe(struct rmi_function *fn)
{}
static int rmi_function_probe(struct device *dev)
{
struct rmi_function *fn = to_rmi_function(dev);
struct rmi_function_handler *handler =
to_rmi_function_handler(dev->driver);
int error;
rmi_function_of_probe(fn);
if (handler->probe) {
error = handler->probe(fn);
return error;
}
return 0;
}
static int rmi_function_remove(struct device *dev)
{
struct rmi_function *fn = to_rmi_function(dev);
struct rmi_function_handler *handler =
to_rmi_function_handler(dev->driver);
if (handler->remove)
handler->remove(fn);
return 0;
}
int rmi_register_function(struct rmi_function *fn)
{
struct rmi_device *rmi_dev = fn->rmi_dev;
int error;
device_initialize(&fn->dev);
dev_set_name(&fn->dev, "%s.fn%02x",
dev_name(&rmi_dev->dev), fn->fd.function_number);
fn->dev.parent = &rmi_dev->dev;
fn->dev.type = &rmi_function_type;
fn->dev.bus = &rmi_bus_type;
error = device_add(&fn->dev);
if (error) {
dev_err(&rmi_dev->dev,
"Failed device_register function device %s\n",
dev_name(&fn->dev));
goto err_put_device;
}
rmi_dbg(RMI_DEBUG_CORE, &rmi_dev->dev, "Registered F%02X.\n",
fn->fd.function_number);
return 0;
err_put_device:
put_device(&fn->dev);
return error;
}
void rmi_unregister_function(struct rmi_function *fn)
{
device_del(&fn->dev);
if (fn->dev.of_node)
of_node_put(fn->dev.of_node);
put_device(&fn->dev);
}
int __rmi_register_function_handler(struct rmi_function_handler *handler,
struct module *owner,
const char *mod_name)
{
struct device_driver *driver = &handler->driver;
int error;
driver->bus = &rmi_bus_type;
driver->owner = owner;
driver->mod_name = mod_name;
driver->probe = rmi_function_probe;
driver->remove = rmi_function_remove;
error = driver_register(&handler->driver);
if (error) {
pr_err("driver_register() failed for %s, error: %d\n",
handler->driver.name, error);
return error;
}
return 0;
}
void rmi_unregister_function_handler(struct rmi_function_handler *handler)
{
driver_unregister(&handler->driver);
}
static int rmi_bus_match(struct device *dev, struct device_driver *drv)
{
bool physical = rmi_is_physical_device(dev);
if (physical != rmi_is_physical_driver(drv))
return 0;
return physical || rmi_function_match(dev, drv);
}
static void __rmi_unregister_function_handlers(int start_idx)
{
int i;
for (i = start_idx; i >= 0; i--)
rmi_unregister_function_handler(fn_handlers[i]);
}
static void rmi_unregister_function_handlers(void)
{
__rmi_unregister_function_handlers(ARRAY_SIZE(fn_handlers) - 1);
}
static int rmi_register_function_handlers(void)
{
int ret;
int i;
for (i = 0; i < ARRAY_SIZE(fn_handlers); i++) {
ret = rmi_register_function_handler(fn_handlers[i]);
if (ret) {
pr_err("%s: error registering the RMI F%02x handler: %d\n",
__func__, fn_handlers[i]->func, ret);
goto err_unregister_function_handlers;
}
}
return 0;
err_unregister_function_handlers:
__rmi_unregister_function_handlers(i - 1);
return ret;
}
int rmi_of_property_read_u32(struct device *dev, u32 *result,
const char *prop, bool optional)
{
int retval;
u32 val = 0;
retval = of_property_read_u32(dev->of_node, prop, &val);
if (retval && (!optional && retval == -EINVAL)) {
dev_err(dev, "Failed to get %s value: %d\n",
prop, retval);
return retval;
}
*result = val;
return 0;
}
static int __init rmi_bus_init(void)
{
int error;
error = bus_register(&rmi_bus_type);
if (error) {
pr_err("%s: error registering the RMI bus: %d\n",
__func__, error);
return error;
}
error = rmi_register_function_handlers();
if (error)
goto err_unregister_bus;
error = rmi_register_physical_driver();
if (error) {
pr_err("%s: error registering the RMI physical driver: %d\n",
__func__, error);
goto err_unregister_bus;
}
return 0;
err_unregister_bus:
bus_unregister(&rmi_bus_type);
return error;
}
static void __exit rmi_bus_exit(void)
{
rmi_unregister_physical_driver();
rmi_unregister_function_handlers();
bus_unregister(&rmi_bus_type);
}
