static int dmi_matched(const struct dmi_system_id *dmi)
{
quirks = dmi->driver_data;
return 1;
}
static void asus_nb_wmi_quirks(struct asus_wmi_driver *driver)
{
quirks = &quirk_asus_unknown;
dmi_check_system(asus_quirks);
driver->quirks = quirks;
driver->panel_power = FB_BLANK_UNBLANK;
if (wapf != -1)
quirks->wapf = wapf;
else
wapf = quirks->wapf;
}
static int __init asus_nb_wmi_init(void)
{
return asus_wmi_register_driver(&asus_nb_wmi_driver);
}
static void __exit asus_nb_wmi_exit(void)
{
asus_wmi_unregister_driver(&asus_nb_wmi_driver);
}
