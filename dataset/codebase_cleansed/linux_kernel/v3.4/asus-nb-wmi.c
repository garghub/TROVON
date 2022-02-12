static void asus_nb_wmi_quirks(struct asus_wmi_driver *driver)
{
driver->quirks = &quirk_asus_unknown;
driver->quirks->wapf = wapf;
driver->panel_power = FB_BLANK_UNBLANK;
}
static int __init asus_nb_wmi_init(void)
{
return asus_wmi_register_driver(&asus_nb_wmi_driver);
}
static void __exit asus_nb_wmi_exit(void)
{
asus_wmi_unregister_driver(&asus_nb_wmi_driver);
}
