static void evbug_event(struct input_handle *handle, unsigned int type, unsigned int code, int value)
{
printk(KERN_DEBUG pr_fmt("Event. Dev: %s, Type: %d, Code: %d, Value: %d\n"),
dev_name(&handle->dev->dev), type, code, value);
}
static int evbug_connect(struct input_handler *handler, struct input_dev *dev,
const struct input_device_id *id)
{
struct input_handle *handle;
int error;
handle = kzalloc(sizeof(struct input_handle), GFP_KERNEL);
if (!handle)
return -ENOMEM;
handle->dev = dev;
handle->handler = handler;
handle->name = "evbug";
error = input_register_handle(handle);
if (error)
goto err_free_handle;
error = input_open_device(handle);
if (error)
goto err_unregister_handle;
printk(KERN_DEBUG pr_fmt("Connected device: %s (%s at %s)\n"),
dev_name(&dev->dev),
dev->name ?: "unknown",
dev->phys ?: "unknown");
return 0;
err_unregister_handle:
input_unregister_handle(handle);
err_free_handle:
kfree(handle);
return error;
}
static void evbug_disconnect(struct input_handle *handle)
{
printk(KERN_DEBUG pr_fmt("Disconnected device: %s\n"),
dev_name(&handle->dev->dev));
input_close_device(handle);
input_unregister_handle(handle);
kfree(handle);
}
static int __init evbug_init(void)
{
return input_register_handler(&evbug_handler);
}
static void __exit evbug_exit(void)
{
input_unregister_handler(&evbug_handler);
}
