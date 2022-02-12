static bool asus_q500a_i8042_filter(unsigned char data, unsigned char str,
struct serio *port)
{
static bool extended;
bool ret = false;
if (str & I8042_STR_AUXDATA)
return false;
if (unlikely(data == 0xe1)) {
extended = true;
ret = true;
} else if (unlikely(extended)) {
extended = false;
ret = true;
}
return ret;
}
static int dmi_matched(const struct dmi_system_id *dmi)
{
quirks = dmi->driver_data;
return 1;
}
static void asus_nb_wmi_quirks(struct asus_wmi_driver *driver)
{
int ret;
quirks = &quirk_asus_unknown;
dmi_check_system(asus_quirks);
driver->quirks = quirks;
driver->panel_power = FB_BLANK_UNBLANK;
if (wapf != -1)
quirks->wapf = wapf;
else
wapf = quirks->wapf;
if (quirks->i8042_filter) {
ret = i8042_install_filter(quirks->i8042_filter);
if (ret) {
pr_warn("Unable to install key filter\n");
return;
}
pr_info("Using i8042 filter function for receiving events\n");
}
}
static int __init asus_nb_wmi_init(void)
{
return asus_wmi_register_driver(&asus_nb_wmi_driver);
}
static void __exit asus_nb_wmi_exit(void)
{
asus_wmi_unregister_driver(&asus_nb_wmi_driver);
}
