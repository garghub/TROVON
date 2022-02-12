static int intel_vbtn_input_setup(struct platform_device *device)
{
struct intel_vbtn_priv *priv = dev_get_drvdata(&device->dev);
int ret;
priv->input_dev = devm_input_allocate_device(&device->dev);
if (!priv->input_dev)
return -ENOMEM;
ret = sparse_keymap_setup(priv->input_dev, intel_vbtn_keymap, NULL);
if (ret)
return ret;
priv->input_dev->dev.parent = &device->dev;
priv->input_dev->name = "Intel Virtual Button driver";
priv->input_dev->id.bustype = BUS_HOST;
return input_register_device(priv->input_dev);
}
static void notify_handler(acpi_handle handle, u32 event, void *context)
{
struct platform_device *device = context;
struct intel_vbtn_priv *priv = dev_get_drvdata(&device->dev);
if (!sparse_keymap_report_event(priv->input_dev, event, 1, true))
dev_info(&device->dev, "unknown event index 0x%x\n",
event);
}
static int intel_vbtn_probe(struct platform_device *device)
{
acpi_handle handle = ACPI_HANDLE(&device->dev);
struct intel_vbtn_priv *priv;
acpi_status status;
int err;
status = acpi_evaluate_object(handle, "VBDL", NULL, NULL);
if (ACPI_FAILURE(status)) {
dev_warn(&device->dev, "failed to read Intel Virtual Button driver\n");
return -ENODEV;
}
priv = devm_kzalloc(&device->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev_set_drvdata(&device->dev, priv);
err = intel_vbtn_input_setup(device);
if (err) {
pr_err("Failed to setup Intel Virtual Button\n");
return err;
}
status = acpi_install_notify_handler(handle,
ACPI_DEVICE_NOTIFY,
notify_handler,
device);
if (ACPI_FAILURE(status))
return -EBUSY;
return 0;
}
static int intel_vbtn_remove(struct platform_device *device)
{
acpi_handle handle = ACPI_HANDLE(&device->dev);
acpi_remove_notify_handler(handle, ACPI_DEVICE_NOTIFY, notify_handler);
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
"intel-vbtn: created platform device\n");
return AE_OK;
}
static int __init intel_vbtn_init(void)
{
acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, check_acpi_dev, NULL,
(void *)intel_vbtn_ids, NULL);
return platform_driver_register(&intel_vbtn_pl_driver);
}
static void __exit intel_vbtn_exit(void)
{
platform_driver_unregister(&intel_vbtn_pl_driver);
}
