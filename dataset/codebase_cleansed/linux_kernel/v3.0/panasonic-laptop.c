static int acpi_pcc_write_sset(struct pcc_acpi *pcc, int func, int val)
{
union acpi_object in_objs[] = {
{ .integer.type = ACPI_TYPE_INTEGER,
.integer.value = func, },
{ .integer.type = ACPI_TYPE_INTEGER,
.integer.value = val, },
};
struct acpi_object_list params = {
.count = ARRAY_SIZE(in_objs),
.pointer = in_objs,
};
acpi_status status = AE_OK;
status = acpi_evaluate_object(pcc->handle, METHOD_HKEY_SSET,
&params, NULL);
return (status == AE_OK) ? 0 : -EIO;
}
static inline int acpi_pcc_get_sqty(struct acpi_device *device)
{
unsigned long long s;
acpi_status status;
status = acpi_evaluate_integer(device->handle, METHOD_HKEY_SQTY,
NULL, &s);
if (ACPI_SUCCESS(status))
return s;
else {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"evaluation error HKEY.SQTY\n"));
return -EINVAL;
}
}
static int acpi_pcc_retrieve_biosdata(struct pcc_acpi *pcc)
{
acpi_status status;
struct acpi_buffer buffer = {ACPI_ALLOCATE_BUFFER, NULL};
union acpi_object *hkey = NULL;
int i;
status = acpi_evaluate_object(pcc->handle, METHOD_HKEY_SINF, NULL,
&buffer);
if (ACPI_FAILURE(status)) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"evaluation error HKEY.SINF\n"));
return 0;
}
hkey = buffer.pointer;
if (!hkey || (hkey->type != ACPI_TYPE_PACKAGE)) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR, "Invalid HKEY.SINF\n"));
status = AE_ERROR;
goto end;
}
if (pcc->num_sifr < hkey->package.count) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"SQTY reports bad SINF length\n"));
status = AE_ERROR;
goto end;
}
for (i = 0; i < hkey->package.count; i++) {
union acpi_object *element = &(hkey->package.elements[i]);
if (likely(element->type == ACPI_TYPE_INTEGER)) {
pcc->sinf[i] = element->integer.value;
} else
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"Invalid HKEY.SINF data\n"));
}
pcc->sinf[hkey->package.count] = -1;
end:
kfree(buffer.pointer);
return status == AE_OK;
}
static int bl_get(struct backlight_device *bd)
{
struct pcc_acpi *pcc = bl_get_data(bd);
if (!acpi_pcc_retrieve_biosdata(pcc))
return -EIO;
return pcc->sinf[SINF_AC_CUR_BRIGHT];
}
static int bl_set_status(struct backlight_device *bd)
{
struct pcc_acpi *pcc = bl_get_data(bd);
int bright = bd->props.brightness;
int rc;
if (!acpi_pcc_retrieve_biosdata(pcc))
return -EIO;
if (bright < pcc->sinf[SINF_AC_MIN_BRIGHT])
bright = pcc->sinf[SINF_AC_MIN_BRIGHT];
if (bright < pcc->sinf[SINF_DC_MIN_BRIGHT])
bright = pcc->sinf[SINF_DC_MIN_BRIGHT];
if (bright < pcc->sinf[SINF_AC_MIN_BRIGHT] ||
bright > pcc->sinf[SINF_AC_MAX_BRIGHT])
return -EINVAL;
rc = acpi_pcc_write_sset(pcc, SINF_AC_CUR_BRIGHT, bright);
if (rc < 0)
return rc;
return acpi_pcc_write_sset(pcc, SINF_DC_CUR_BRIGHT, bright);
}
static ssize_t show_numbatt(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct acpi_device *acpi = to_acpi_device(dev);
struct pcc_acpi *pcc = acpi_driver_data(acpi);
if (!acpi_pcc_retrieve_biosdata(pcc))
return -EIO;
return snprintf(buf, PAGE_SIZE, "%u\n", pcc->sinf[SINF_NUM_BATTERIES]);
}
static ssize_t show_lcdtype(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct acpi_device *acpi = to_acpi_device(dev);
struct pcc_acpi *pcc = acpi_driver_data(acpi);
if (!acpi_pcc_retrieve_biosdata(pcc))
return -EIO;
return snprintf(buf, PAGE_SIZE, "%u\n", pcc->sinf[SINF_LCD_TYPE]);
}
static ssize_t show_mute(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct acpi_device *acpi = to_acpi_device(dev);
struct pcc_acpi *pcc = acpi_driver_data(acpi);
if (!acpi_pcc_retrieve_biosdata(pcc))
return -EIO;
return snprintf(buf, PAGE_SIZE, "%u\n", pcc->sinf[SINF_MUTE]);
}
static ssize_t show_sticky(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct acpi_device *acpi = to_acpi_device(dev);
struct pcc_acpi *pcc = acpi_driver_data(acpi);
if (!acpi_pcc_retrieve_biosdata(pcc))
return -EIO;
return snprintf(buf, PAGE_SIZE, "%u\n", pcc->sinf[SINF_STICKY_KEY]);
}
static ssize_t set_sticky(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct acpi_device *acpi = to_acpi_device(dev);
struct pcc_acpi *pcc = acpi_driver_data(acpi);
int val;
if (count && sscanf(buf, "%i", &val) == 1 &&
(val == 0 || val == 1)) {
acpi_pcc_write_sset(pcc, SINF_STICKY_KEY, val);
pcc->sticky_mode = val;
}
return count;
}
static void acpi_pcc_generate_keyinput(struct pcc_acpi *pcc)
{
struct input_dev *hotk_input_dev = pcc->input_dev;
int rc;
unsigned long long result;
rc = acpi_evaluate_integer(pcc->handle, METHOD_HKEY_QUERY,
NULL, &result);
if (!ACPI_SUCCESS(rc)) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"error getting hotkey status\n"));
return;
}
acpi_bus_generate_proc_event(pcc->device, HKEY_NOTIFY, result);
if (!sparse_keymap_report_event(hotk_input_dev,
result & 0xf, result & 0x80, false))
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"Unknown hotkey event: %d\n", result));
}
static void acpi_pcc_hotkey_notify(struct acpi_device *device, u32 event)
{
struct pcc_acpi *pcc = acpi_driver_data(device);
switch (event) {
case HKEY_NOTIFY:
acpi_pcc_generate_keyinput(pcc);
break;
default:
break;
}
}
static int acpi_pcc_init_input(struct pcc_acpi *pcc)
{
struct input_dev *input_dev;
int error;
input_dev = input_allocate_device();
if (!input_dev) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"Couldn't allocate input device for hotkey"));
return -ENOMEM;
}
input_dev->name = ACPI_PCC_DRIVER_NAME;
input_dev->phys = ACPI_PCC_INPUT_PHYS;
input_dev->id.bustype = BUS_HOST;
input_dev->id.vendor = 0x0001;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
error = sparse_keymap_setup(input_dev, panasonic_keymap, NULL);
if (error) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"Unable to setup input device keymap\n"));
goto err_free_dev;
}
error = input_register_device(input_dev);
if (error) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"Unable to register input device\n"));
goto err_free_keymap;
}
pcc->input_dev = input_dev;
return 0;
err_free_keymap:
sparse_keymap_free(input_dev);
err_free_dev:
input_free_device(input_dev);
return error;
}
static void acpi_pcc_destroy_input(struct pcc_acpi *pcc)
{
sparse_keymap_free(pcc->input_dev);
input_unregister_device(pcc->input_dev);
}
static int acpi_pcc_hotkey_resume(struct acpi_device *device)
{
struct pcc_acpi *pcc = acpi_driver_data(device);
if (device == NULL || pcc == NULL)
return -EINVAL;
ACPI_DEBUG_PRINT((ACPI_DB_ERROR, "Sticky mode restore: %d\n",
pcc->sticky_mode));
return acpi_pcc_write_sset(pcc, SINF_STICKY_KEY, pcc->sticky_mode);
}
static int acpi_pcc_hotkey_add(struct acpi_device *device)
{
struct backlight_properties props;
struct pcc_acpi *pcc;
int num_sifr, result;
if (!device)
return -EINVAL;
num_sifr = acpi_pcc_get_sqty(device);
if (num_sifr > 255) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR, "num_sifr too large"));
return -ENODEV;
}
pcc = kzalloc(sizeof(struct pcc_acpi), GFP_KERNEL);
if (!pcc) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"Couldn't allocate mem for pcc"));
return -ENOMEM;
}
pcc->sinf = kzalloc(sizeof(u32) * (num_sifr + 1), GFP_KERNEL);
if (!pcc->sinf) {
result = -ENOMEM;
goto out_hotkey;
}
pcc->device = device;
pcc->handle = device->handle;
pcc->num_sifr = num_sifr;
device->driver_data = pcc;
strcpy(acpi_device_name(device), ACPI_PCC_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_PCC_CLASS);
result = acpi_pcc_init_input(pcc);
if (result) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"Error installing keyinput handler\n"));
goto out_sinf;
}
if (!acpi_pcc_retrieve_biosdata(pcc)) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"Couldn't retrieve BIOS data\n"));
result = -EIO;
goto out_input;
}
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = pcc->sinf[SINF_AC_MAX_BRIGHT];
pcc->backlight = backlight_device_register("panasonic", NULL, pcc,
&pcc_backlight_ops, &props);
if (IS_ERR(pcc->backlight)) {
result = PTR_ERR(pcc->backlight);
goto out_input;
}
pcc->backlight->props.brightness = pcc->sinf[SINF_AC_CUR_BRIGHT];
pcc->sticky_mode = pcc->sinf[SINF_STICKY_KEY];
result = sysfs_create_group(&device->dev.kobj, &pcc_attr_group);
if (result)
goto out_backlight;
return 0;
out_backlight:
backlight_device_unregister(pcc->backlight);
out_input:
acpi_pcc_destroy_input(pcc);
out_sinf:
kfree(pcc->sinf);
out_hotkey:
kfree(pcc);
return result;
}
static int __init acpi_pcc_init(void)
{
int result = 0;
if (acpi_disabled)
return -ENODEV;
result = acpi_bus_register_driver(&acpi_pcc_driver);
if (result < 0) {
ACPI_DEBUG_PRINT((ACPI_DB_ERROR,
"Error registering hotkey driver\n"));
return -ENODEV;
}
return 0;
}
static int acpi_pcc_hotkey_remove(struct acpi_device *device, int type)
{
struct pcc_acpi *pcc = acpi_driver_data(device);
if (!device || !pcc)
return -EINVAL;
sysfs_remove_group(&device->dev.kobj, &pcc_attr_group);
backlight_device_unregister(pcc->backlight);
acpi_pcc_destroy_input(pcc);
kfree(pcc->sinf);
kfree(pcc);
return 0;
}
static void __exit acpi_pcc_exit(void)
{
acpi_bus_unregister_driver(&acpi_pcc_driver);
}
