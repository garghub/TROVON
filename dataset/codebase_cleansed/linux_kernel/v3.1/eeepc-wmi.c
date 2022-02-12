static void eeepc_wmi_key_filter(struct asus_wmi_driver *asus_wmi, int *code,
unsigned int *value, bool *autorelease)
{
switch (*code) {
case HOME_PRESS:
*value = 1;
*autorelease = 0;
break;
case HOME_HOLD:
*code = ASUS_WMI_KEY_IGNORE;
break;
case HOME_RELEASE:
*code = HOME_PRESS;
*value = 0;
*autorelease = 0;
break;
}
}
static acpi_status eeepc_wmi_parse_device(acpi_handle handle, u32 level,
void *context, void **retval)
{
pr_warn("Found legacy ATKD device (%s)\n", EEEPC_ACPI_HID);
*(bool *)context = true;
return AE_CTRL_TERMINATE;
}
static int eeepc_wmi_check_atkd(void)
{
acpi_status status;
bool found = false;
status = acpi_get_devices(EEEPC_ACPI_HID, eeepc_wmi_parse_device,
&found, NULL);
if (ACPI_FAILURE(status) || !found)
return 0;
return -1;
}
static int eeepc_wmi_probe(struct platform_device *pdev)
{
if (eeepc_wmi_check_atkd()) {
pr_warn("WMI device present, but legacy ATKD device is also "
"present and enabled\n");
pr_warn("You probably booted with acpi_osi=\"Linux\" or "
"acpi_osi=\"!Windows 2009\"\n");
pr_warn("Can't load eeepc-wmi, use default acpi_osi "
"(preferred) or eeepc-laptop\n");
return -EBUSY;
}
return 0;
}
static void eeepc_dmi_check(struct asus_wmi_driver *driver)
{
const char *model;
model = dmi_get_system_info(DMI_PRODUCT_NAME);
if (!model)
return;
if (strcmp(model, "1000H") == 0) {
driver->hotplug_wireless = true;
pr_info("wlan hotplug enabled\n");
}
}
static void eeepc_wmi_quirks(struct asus_wmi_driver *driver)
{
driver->hotplug_wireless = hotplug_wireless;
driver->wapf = -1;
eeepc_dmi_check(driver);
}
static int __init eeepc_wmi_init(void)
{
return asus_wmi_register_driver(&asus_wmi_driver);
}
static void __exit eeepc_wmi_exit(void)
{
asus_wmi_unregister_driver(&asus_wmi_driver);
}
