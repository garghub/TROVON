static void et2012_quirks(void)
{
const struct dmi_device *dev = NULL;
char oemstring[30];
while ((dev = dmi_find_device(DMI_DEV_TYPE_OEM_STRING, NULL, dev))) {
if (sscanf(dev->name, "AEMS%24c", oemstring) == 1) {
if (oemstring[18] == '1')
quirks = &quirk_asus_et2012_type1;
else if (oemstring[18] == '3')
quirks = &quirk_asus_et2012_type3;
break;
}
}
}
static int dmi_matched(const struct dmi_system_id *dmi)
{
char *model;
quirks = dmi->driver_data;
model = (char *)dmi->matches[1].substr;
if (unlikely(strncmp(model, "ET2012", 6) == 0))
et2012_quirks();
return 1;
}
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
static int eeepc_wmi_probe(struct platform_device *pdev)
{
if (acpi_dev_found(EEEPC_ACPI_HID)) {
pr_warn("Found legacy ATKD device (%s)\n", EEEPC_ACPI_HID);
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
static void eeepc_wmi_quirks(struct asus_wmi_driver *driver)
{
quirks = &quirk_asus_unknown;
quirks->hotplug_wireless = hotplug_wireless;
dmi_check_system(asus_quirks);
driver->quirks = quirks;
driver->quirks->wapf = -1;
driver->panel_power = FB_BLANK_UNBLANK;
}
static int __init eeepc_wmi_init(void)
{
return asus_wmi_register_driver(&asus_wmi_driver);
}
static void __exit eeepc_wmi_exit(void)
{
asus_wmi_unregister_driver(&asus_wmi_driver);
}
