static void system_power_event(unsigned int keycode)
{
switch (keycode) {
case KEY_SUSPEND:
apm_queue_event(APM_USER_SUSPEND);
pr_info("Requesting system suspend...\n");
break;
default:
break;
}
}
static void apmpower_event(struct input_handle *handle, unsigned int type,
unsigned int code, int value)
{
if (value != 1)
return;
switch (type) {
case EV_PWR:
system_power_event(code);
break;
default:
break;
}
}
static int apmpower_connect(struct input_handler *handler,
struct input_dev *dev,
const struct input_device_id *id)
{
struct input_handle *handle;
int error;
handle = kzalloc(sizeof(struct input_handle), GFP_KERNEL);
if (!handle)
return -ENOMEM;
handle->dev = dev;
handle->handler = handler;
handle->name = "apm-power";
error = input_register_handle(handle);
if (error) {
pr_err("Failed to register input power handler, error %d\n",
error);
kfree(handle);
return error;
}
error = input_open_device(handle);
if (error) {
pr_err("Failed to open input power device, error %d\n", error);
input_unregister_handle(handle);
kfree(handle);
return error;
}
return 0;
}
static void apmpower_disconnect(struct input_handle *handle)
{
input_close_device(handle);
input_unregister_handle(handle);
kfree(handle);
}
static int __init apmpower_init(void)
{
return input_register_handler(&apmpower_handler);
}
static void __exit apmpower_exit(void)
{
input_unregister_handler(&apmpower_handler);
}
