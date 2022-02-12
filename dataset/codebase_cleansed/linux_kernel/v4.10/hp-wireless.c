static int hp_wireless_input_setup(void)
{
int err;
hpwl_input_dev = input_allocate_device();
if (!hpwl_input_dev)
return -ENOMEM;
hpwl_input_dev->name = "HP Wireless hotkeys";
hpwl_input_dev->phys = "hpq6001/input0";
hpwl_input_dev->id.bustype = BUS_HOST;
hpwl_input_dev->evbit[0] = BIT(EV_KEY);
set_bit(KEY_RFKILL, hpwl_input_dev->keybit);
err = input_register_device(hpwl_input_dev);
if (err)
goto err_free_dev;
return 0;
err_free_dev:
input_free_device(hpwl_input_dev);
return err;
}
static void hp_wireless_input_destroy(void)
{
input_unregister_device(hpwl_input_dev);
}
static void hpwl_notify(struct acpi_device *acpi_dev, u32 event)
{
if (event != 0x80) {
pr_info("Received unknown event (0x%x)\n", event);
return;
}
input_report_key(hpwl_input_dev, KEY_RFKILL, 1);
input_sync(hpwl_input_dev);
input_report_key(hpwl_input_dev, KEY_RFKILL, 0);
input_sync(hpwl_input_dev);
}
static int hpwl_add(struct acpi_device *device)
{
int err;
err = hp_wireless_input_setup();
if (err)
pr_err("Failed to setup hp wireless hotkeys\n");
return err;
}
static int hpwl_remove(struct acpi_device *device)
{
hp_wireless_input_destroy();
return 0;
}
static int __init hpwl_init(void)
{
int err;
pr_info("Initializing HPQ6001 module\n");
err = acpi_bus_register_driver(&hpwl_driver);
if (err)
pr_err("Unable to register HP wireless control driver.\n");
return err;
}
static void __exit hpwl_exit(void)
{
pr_info("Exiting HPQ6001 module\n");
acpi_bus_unregister_driver(&hpwl_driver);
}
