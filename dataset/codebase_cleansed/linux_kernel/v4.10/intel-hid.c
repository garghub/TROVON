static int intel_hid_set_enable(struct device *device, int enable)
{
union acpi_object arg0 = { ACPI_TYPE_INTEGER };
struct acpi_object_list args = { 1, &arg0 };
acpi_status status;
arg0.integer.value = enable;
status = acpi_evaluate_object(ACPI_HANDLE(device), "HDSM", &args, NULL);
if (ACPI_FAILURE(status)) {
dev_warn(device, "failed to %sable hotkeys\n",
enable ? "en" : "dis");
return -EIO;
}
return 0;
}
static int intel_hid_pl_suspend_handler(struct device *device)
{
intel_hid_set_enable(device, 0);
return 0;
}
static int intel_hid_pl_resume_handler(struct device *device)
{
intel_hid_set_enable(device, 1);
return 0;
}
static int intel_hid_input_setup(struct platform_device *device)
{
struct intel_hid_priv *priv = dev_get_drvdata(&device->dev);
int ret;
priv->input_dev = input_allocate_device();
if (!priv->input_dev)
return -ENOMEM;
ret = sparse_keymap_setup(priv->input_dev, intel_hid_keymap, NULL);
if (ret)
goto err_free_device;
priv->input_dev->dev.parent = &device->dev;
priv->input_dev->name = "Intel HID events";
priv->input_dev->id.bustype = BUS_HOST;
set_bit(KEY_RFKILL, priv->input_dev->keybit);
ret = input_register_device(priv->input_dev);
if (ret)
goto err_free_device;
return 0;
err_free_device:
input_free_device(priv->input_dev);
return ret;
}
static void intel_hid_input_destroy(struct platform_device *device)
{
struct intel_hid_priv *priv = dev_get_drvdata(&device->dev);
input_unregister_device(priv->input_dev);
}
static void notify_handler(acpi_handle handle, u32 event, void *context)
{
struct platform_device *device = context;
struct intel_hid_priv *priv = dev_get_drvdata(&device->dev);
unsigned long long ev_index;
acpi_status status;
if (event != 0xc0) {
dev_warn(&device->dev, "received unknown event (0x%x)\n",
event);
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
struct intel_hid_priv *priv;
unsigned long long mode;
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
status = acpi_install_notify_handler(handle,
ACPI_DEVICE_NOTIFY,
notify_handler,
device);
if (ACPI_FAILURE(status)) {
err = -EBUSY;
goto err_remove_input;
}
err = intel_hid_set_enable(&device->dev, 1);
if (err)
goto err_remove_notify;
return 0;
err_remove_notify:
acpi_remove_notify_handler(handle, ACPI_DEVICE_NOTIFY, notify_handler);
err_remove_input:
intel_hid_input_destroy(device);
return err;
}
static int intel_hid_remove(struct platform_device *device)
{
acpi_handle handle = ACPI_HANDLE(&device->dev);
acpi_remove_notify_handler(handle, ACPI_DEVICE_NOTIFY, notify_handler);
intel_hid_input_destroy(device);
intel_hid_set_enable(&device->dev, 0);
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
