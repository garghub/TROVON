static int intel_hid_set_enable(struct device *device, bool enable)
{
acpi_status status;
status = acpi_execute_simple_method(ACPI_HANDLE(device), "HDSM",
enable);
if (ACPI_FAILURE(status)) {
dev_warn(device, "failed to %sable hotkeys\n",
enable ? "en" : "dis");
return -EIO;
}
return 0;
}
static void intel_button_array_enable(struct device *device, bool enable)
{
struct intel_hid_priv *priv = dev_get_drvdata(device);
acpi_handle handle = ACPI_HANDLE(device);
unsigned long long button_cap;
acpi_status status;
if (!priv->array)
return;
status = acpi_evaluate_integer(handle, "BTNC", NULL, &button_cap);
if (ACPI_FAILURE(status)) {
dev_warn(device, "failed to get button capability\n");
return;
}
status = acpi_execute_simple_method(handle, "BTNE",
enable ? button_cap : 1);
if (ACPI_FAILURE(status))
dev_warn(device, "failed to set button capability\n");
}
static int intel_hid_pl_suspend_handler(struct device *device)
{
intel_hid_set_enable(device, false);
intel_button_array_enable(device, false);
return 0;
}
static int intel_hid_pl_resume_handler(struct device *device)
{
intel_hid_set_enable(device, true);
intel_button_array_enable(device, true);
return 0;
}
static int intel_hid_input_setup(struct platform_device *device)
{
struct intel_hid_priv *priv = dev_get_drvdata(&device->dev);
int ret;
priv->input_dev = devm_input_allocate_device(&device->dev);
if (!priv->input_dev)
return -ENOMEM;
ret = sparse_keymap_setup(priv->input_dev, intel_hid_keymap, NULL);
if (ret)
return ret;
priv->input_dev->name = "Intel HID events";
priv->input_dev->id.bustype = BUS_HOST;
return input_register_device(priv->input_dev);
}
static int intel_button_array_input_setup(struct platform_device *device)
{
struct intel_hid_priv *priv = dev_get_drvdata(&device->dev);
int ret;
priv->array = devm_input_allocate_device(&device->dev);
if (!priv->array)
return -ENOMEM;
ret = sparse_keymap_setup(priv->array, intel_array_keymap, NULL);
if (ret)
return ret;
priv->array->name = "Intel HID 5 button array";
priv->array->id.bustype = BUS_HOST;
return input_register_device(priv->array);
}
static void notify_handler(acpi_handle handle, u32 event, void *context)
{
struct platform_device *device = context;
struct intel_hid_priv *priv = dev_get_drvdata(&device->dev);
unsigned long long ev_index;
acpi_status status;
if (event != 0xc0) {
if (!priv->array ||
!sparse_keymap_report_event(priv->array, event, 1, true))
dev_info(&device->dev, "unknown event 0x%x\n", event);
return;
}
status = acpi_evaluate_integer(handle, "HDEM", NULL, &ev_index);
if (ACPI_FAILURE(status)) {
dev_warn(&device->dev, "failed to get event index\n");
return;
}
if (!sparse_keymap_report_event(priv->input_dev, ev_index, 1, true))
dev_info(&device->dev, "unknown event index 0x%llx\n",
ev_index);
}
static int intel_hid_probe(struct platform_device *device)
{
acpi_handle handle = ACPI_HANDLE(&device->dev);
unsigned long long event_cap, mode;
struct intel_hid_priv *priv;
acpi_status status;
int err;
status = acpi_evaluate_integer(handle, "HDMM", NULL, &mode);
if (ACPI_FAILURE(status)) {
dev_warn(&device->dev, "failed to read mode\n");
return -ENODEV;
}
if (mode != 0) {
dev_info(&device->dev, "platform is not in simple mode\n");
return -ENODEV;
}
priv = devm_kzalloc(&device->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev_set_drvdata(&device->dev, priv);
err = intel_hid_input_setup(device);
if (err) {
pr_err("Failed to setup Intel HID hotkeys\n");
return err;
}
status = acpi_evaluate_integer(handle, "HEBC", NULL, &event_cap);
if (ACPI_SUCCESS(status) && (event_cap & 0x20000)) {
dev_info(&device->dev, "platform supports 5 button array\n");
err = intel_button_array_input_setup(device);
if (err)
pr_err("Failed to setup Intel 5 button array hotkeys\n");
}
status = acpi_install_notify_handler(handle,
ACPI_DEVICE_NOTIFY,
notify_handler,
device);
if (ACPI_FAILURE(status))
return -EBUSY;
err = intel_hid_set_enable(&device->dev, true);
if (err)
goto err_remove_notify;
if (priv->array) {
intel_button_array_enable(&device->dev, true);
status = acpi_evaluate_object(handle, "BTNL", NULL, NULL);
if (ACPI_FAILURE(status))
dev_warn(&device->dev,
"failed to enable HID power button\n");
}
return 0;
err_remove_notify:
acpi_remove_notify_handler(handle, ACPI_DEVICE_NOTIFY, notify_handler);
return err;
}
static int intel_hid_remove(struct platform_device *device)
{
acpi_handle handle = ACPI_HANDLE(&device->dev);
acpi_remove_notify_handler(handle, ACPI_DEVICE_NOTIFY, notify_handler);
intel_hid_set_enable(&device->dev, false);
intel_button_array_enable(&device->dev, false);
return 0;
}
static acpi_status __init
check_acpi_dev(acpi_handle handle, u32 lvl, void *context, void **rv)
{
const struct acpi_device_id *ids = context;
struct acpi_device *dev;
if (acpi_bus_get_device(handle, &dev) != 0)
return AE_OK;
if (acpi_match_device_ids(dev, ids) == 0)
if (acpi_create_platform_device(dev, NULL))
dev_info(&dev->dev,
"intel-hid: created platform device\n");
return AE_OK;
}
static int __init intel_hid_init(void)
{
acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, check_acpi_dev, NULL,
(void *)intel_hid_ids, NULL);
return platform_driver_register(&intel_hid_pl_driver);
}
static void __exit intel_hid_exit(void)
{
platform_driver_unregister(&intel_hid_pl_driver);
}
