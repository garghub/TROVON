static void acpi_video_parse_cmdline(void)
{
if (!strcmp("vendor", acpi_video_backlight_string))
acpi_backlight_cmdline = acpi_backlight_vendor;
if (!strcmp("video", acpi_video_backlight_string))
acpi_backlight_cmdline = acpi_backlight_video;
if (!strcmp("native", acpi_video_backlight_string))
acpi_backlight_cmdline = acpi_backlight_native;
if (!strcmp("none", acpi_video_backlight_string))
acpi_backlight_cmdline = acpi_backlight_none;
}
static acpi_status
find_video(acpi_handle handle, u32 lvl, void *context, void **rv)
{
long *cap = context;
struct pci_dev *dev;
struct acpi_device *acpi_dev;
static const struct acpi_device_id video_ids[] = {
{ACPI_VIDEO_HID, 0},
{"", 0},
};
if (acpi_bus_get_device(handle, &acpi_dev))
return AE_OK;
if (!acpi_match_device_ids(acpi_dev, video_ids)) {
dev = acpi_get_pci_dev(handle);
if (!dev)
return AE_OK;
pci_dev_put(dev);
*cap |= acpi_is_video_device(handle);
}
return AE_OK;
}
static int video_detect_force_vendor(const struct dmi_system_id *d)
{
acpi_backlight_dmi = acpi_backlight_vendor;
return 0;
}
static int video_detect_force_video(const struct dmi_system_id *d)
{
acpi_backlight_dmi = acpi_backlight_video;
return 0;
}
static int video_detect_force_native(const struct dmi_system_id *d)
{
acpi_backlight_dmi = acpi_backlight_native;
return 0;
}
static int video_detect_force_none(const struct dmi_system_id *d)
{
acpi_backlight_dmi = acpi_backlight_none;
return 0;
}
static void acpi_video_backlight_notify_work(struct work_struct *work)
{
if (acpi_video_get_backlight_type() != acpi_backlight_video)
acpi_video_unregister_backlight();
}
static int acpi_video_backlight_notify(struct notifier_block *nb,
unsigned long val, void *bd)
{
struct backlight_device *backlight = bd;
if (backlight->props.type == BACKLIGHT_RAW &&
val == BACKLIGHT_REGISTERED)
schedule_work(&backlight_notify_work);
return NOTIFY_OK;
}
enum acpi_backlight_type acpi_video_get_backlight_type(void)
{
static DEFINE_MUTEX(init_mutex);
static bool init_done;
static long video_caps;
mutex_lock(&init_mutex);
if (!init_done) {
acpi_video_parse_cmdline();
dmi_check_system(video_detect_dmi_table);
acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, find_video, NULL,
&video_caps, NULL);
INIT_WORK(&backlight_notify_work,
acpi_video_backlight_notify_work);
backlight_nb.notifier_call = acpi_video_backlight_notify;
backlight_nb.priority = 0;
if (backlight_register_notifier(&backlight_nb) == 0)
backlight_notifier_registered = true;
init_done = true;
}
mutex_unlock(&init_mutex);
if (acpi_backlight_cmdline != acpi_backlight_undef)
return acpi_backlight_cmdline;
if (acpi_backlight_dmi != acpi_backlight_undef)
return acpi_backlight_dmi;
if (!(video_caps & ACPI_VIDEO_BACKLIGHT))
return acpi_backlight_vendor;
if (acpi_osi_is_win8() && backlight_device_get_by_type(BACKLIGHT_RAW))
return acpi_backlight_native;
return acpi_backlight_video;
}
void acpi_video_set_dmi_backlight_type(enum acpi_backlight_type type)
{
acpi_backlight_dmi = type;
if (acpi_video_get_backlight_type() != acpi_backlight_video)
acpi_video_unregister_backlight();
}
void __exit acpi_video_detect_exit(void)
{
if (backlight_notifier_registered)
backlight_unregister_notifier(&backlight_nb);
}
