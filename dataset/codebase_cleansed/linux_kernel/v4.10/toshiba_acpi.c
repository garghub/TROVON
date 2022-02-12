static inline void _set_bit(u32 *word, u32 mask, int value)
{
*word = (*word & ~mask) | (mask * value);
}
static int write_acpi_int(const char *methodName, int val)
{
acpi_status status;
status = acpi_execute_simple_method(NULL, (char *)methodName, val);
return (status == AE_OK) ? 0 : -EIO;
}
static acpi_status tci_raw(struct toshiba_acpi_dev *dev,
const u32 in[TCI_WORDS], u32 out[TCI_WORDS])
{
union acpi_object in_objs[TCI_WORDS], out_objs[TCI_WORDS + 1];
struct acpi_object_list params;
struct acpi_buffer results;
acpi_status status;
int i;
params.count = TCI_WORDS;
params.pointer = in_objs;
for (i = 0; i < TCI_WORDS; ++i) {
in_objs[i].type = ACPI_TYPE_INTEGER;
in_objs[i].integer.value = in[i];
}
results.length = sizeof(out_objs);
results.pointer = out_objs;
status = acpi_evaluate_object(dev->acpi_dev->handle,
(char *)dev->method_hci, &params,
&results);
if ((status == AE_OK) && (out_objs->package.count <= TCI_WORDS)) {
for (i = 0; i < out_objs->package.count; ++i)
out[i] = out_objs->package.elements[i].integer.value;
}
return status;
}
static u32 hci_write(struct toshiba_acpi_dev *dev, u32 reg, u32 in1)
{
u32 in[TCI_WORDS] = { HCI_SET, reg, in1, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status = tci_raw(dev, in, out);
return ACPI_SUCCESS(status) ? out[0] : TOS_FAILURE;
}
static u32 hci_read(struct toshiba_acpi_dev *dev, u32 reg, u32 *out1)
{
u32 in[TCI_WORDS] = { HCI_GET, reg, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status))
return TOS_FAILURE;
*out1 = out[2];
return out[0];
}
static int sci_open(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { SCI_OPEN, 0, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to open SCI failed\n");
return 0;
}
if (out[0] == TOS_OPEN_CLOSE_OK) {
return 1;
} else if (out[0] == TOS_ALREADY_OPEN) {
pr_info("Toshiba SCI already opened\n");
return 1;
} else if (out[0] == TOS_NOT_SUPPORTED) {
return 1;
} else if (out[0] == TOS_NOT_PRESENT) {
pr_info("Toshiba SCI is not present\n");
}
return 0;
}
static void sci_close(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { SCI_CLOSE, 0, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to close SCI failed\n");
return;
}
if (out[0] == TOS_OPEN_CLOSE_OK)
return;
else if (out[0] == TOS_NOT_OPENED)
pr_info("Toshiba SCI not opened\n");
else if (out[0] == TOS_NOT_PRESENT)
pr_info("Toshiba SCI is not present\n");
}
static u32 sci_read(struct toshiba_acpi_dev *dev, u32 reg, u32 *out1)
{
u32 in[TCI_WORDS] = { SCI_GET, reg, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status))
return TOS_FAILURE;
*out1 = out[2];
return out[0];
}
static u32 sci_write(struct toshiba_acpi_dev *dev, u32 reg, u32 in1)
{
u32 in[TCI_WORDS] = { SCI_SET, reg, in1, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status = tci_raw(dev, in, out);
return ACPI_SUCCESS(status) ? out[0] : TOS_FAILURE;
}
static void toshiba_illumination_available(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { SCI_GET, SCI_ILLUMINATION, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
dev->illumination_supported = 0;
dev->illumination_led_registered = false;
if (!sci_open(dev))
return;
status = tci_raw(dev, in, out);
sci_close(dev);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to query Illumination support failed\n");
return;
}
if (out[0] != TOS_SUCCESS)
return;
dev->illumination_supported = 1;
}
static void toshiba_illumination_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct toshiba_acpi_dev *dev = container_of(cdev,
struct toshiba_acpi_dev, led_dev);
u32 result;
u32 state;
if (!sci_open(dev))
return;
state = brightness ? 1 : 0;
result = sci_write(dev, SCI_ILLUMINATION, state);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call for illumination failed\n");
}
static enum led_brightness toshiba_illumination_get(struct led_classdev *cdev)
{
struct toshiba_acpi_dev *dev = container_of(cdev,
struct toshiba_acpi_dev, led_dev);
u32 result;
u32 state;
if (!sci_open(dev))
return LED_OFF;
result = sci_read(dev, SCI_ILLUMINATION, &state);
sci_close(dev);
if (result == TOS_FAILURE) {
pr_err("ACPI call for illumination failed\n");
return LED_OFF;
} else if (result != TOS_SUCCESS) {
return LED_OFF;
}
return state ? LED_FULL : LED_OFF;
}
static void toshiba_kbd_illum_available(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { SCI_GET, SCI_KBD_ILLUM_STATUS, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
dev->kbd_illum_supported = 0;
dev->kbd_led_registered = false;
dev->kbd_event_generated = false;
if (!sci_open(dev))
return;
status = tci_raw(dev, in, out);
sci_close(dev);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to query kbd illumination support failed\n");
return;
}
if (out[0] != TOS_SUCCESS)
return;
if (out[3] == SCI_KBD_TIME_MAX)
dev->kbd_type = 2;
else
dev->kbd_type = 1;
dev->kbd_mode = out[2] & SCI_KBD_MODE_MASK;
dev->kbd_time = out[2] >> HCI_MISC_SHIFT;
dev->kbd_illum_supported = 1;
}
static int toshiba_kbd_illum_status_set(struct toshiba_acpi_dev *dev, u32 time)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_write(dev, SCI_KBD_ILLUM_STATUS, time);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to set KBD backlight status failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int toshiba_kbd_illum_status_get(struct toshiba_acpi_dev *dev, u32 *time)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_read(dev, SCI_KBD_ILLUM_STATUS, time);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to get KBD backlight status failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static enum led_brightness toshiba_kbd_backlight_get(struct led_classdev *cdev)
{
struct toshiba_acpi_dev *dev = container_of(cdev,
struct toshiba_acpi_dev, kbd_led);
u32 result;
u32 state;
result = hci_read(dev, HCI_KBD_ILLUMINATION, &state);
if (result == TOS_FAILURE) {
pr_err("ACPI call to get the keyboard backlight failed\n");
return LED_OFF;
} else if (result != TOS_SUCCESS) {
return LED_OFF;
}
return state ? LED_FULL : LED_OFF;
}
static void toshiba_kbd_backlight_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct toshiba_acpi_dev *dev = container_of(cdev,
struct toshiba_acpi_dev, kbd_led);
u32 result;
u32 state;
state = brightness ? 1 : 0;
result = hci_write(dev, HCI_KBD_ILLUMINATION, state);
if (result == TOS_FAILURE)
pr_err("ACPI call to set KBD Illumination mode failed\n");
}
static int toshiba_touchpad_set(struct toshiba_acpi_dev *dev, u32 state)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_write(dev, SCI_TOUCHPAD, state);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to set the touchpad failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int toshiba_touchpad_get(struct toshiba_acpi_dev *dev, u32 *state)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_read(dev, SCI_TOUCHPAD, state);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to query the touchpad failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static void toshiba_eco_mode_available(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { HCI_GET, HCI_ECO_MODE, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
dev->eco_supported = 0;
dev->eco_led_registered = false;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get ECO led failed\n");
return;
}
if (out[0] == TOS_INPUT_DATA_ERROR) {
in[3] = 1;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get ECO led failed\n");
return;
}
if (out[0] != TOS_SUCCESS)
return;
dev->eco_supported = 1;
}
}
static enum led_brightness
toshiba_eco_mode_get_status(struct led_classdev *cdev)
{
struct toshiba_acpi_dev *dev = container_of(cdev,
struct toshiba_acpi_dev, eco_led);
u32 in[TCI_WORDS] = { HCI_GET, HCI_ECO_MODE, 0, 1, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get ECO led failed\n");
return LED_OFF;
}
if (out[0] != TOS_SUCCESS)
return LED_OFF;
return out[2] ? LED_FULL : LED_OFF;
}
static void toshiba_eco_mode_set_status(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct toshiba_acpi_dev *dev = container_of(cdev,
struct toshiba_acpi_dev, eco_led);
u32 in[TCI_WORDS] = { HCI_SET, HCI_ECO_MODE, 0, 1, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
in[2] = (brightness) ? 1 : 0;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status))
pr_err("ACPI call to set ECO led failed\n");
}
static void toshiba_accelerometer_available(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { HCI_GET, HCI_ACCELEROMETER2, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
dev->accelerometer_supported = 0;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to query the accelerometer failed\n");
return;
}
if (out[0] != TOS_SUCCESS)
return;
dev->accelerometer_supported = 1;
}
static int toshiba_accelerometer_get(struct toshiba_acpi_dev *dev,
u32 *xy, u32 *z)
{
u32 in[TCI_WORDS] = { HCI_GET, HCI_ACCELEROMETER, 0, 1, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to query the accelerometer failed\n");
return -EIO;
}
if (out[0] == TOS_NOT_SUPPORTED)
return -ENODEV;
if (out[0] != TOS_SUCCESS)
return -EIO;
*xy = out[2];
*z = out[4];
return 0;
}
static void toshiba_usb_sleep_charge_available(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { SCI_GET, SCI_USB_SLEEP_CHARGE, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
dev->usb_sleep_charge_supported = 0;
if (!sci_open(dev))
return;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get USB Sleep and Charge mode failed\n");
sci_close(dev);
return;
}
if (out[0] != TOS_SUCCESS) {
sci_close(dev);
return;
}
dev->usbsc_mode_base = out[4];
in[5] = SCI_USB_CHARGE_BAT_LVL;
status = tci_raw(dev, in, out);
sci_close(dev);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get USB Sleep and Charge mode failed\n");
return;
}
if (out[0] != TOS_SUCCESS)
return;
dev->usbsc_bat_level = out[2];
dev->usb_sleep_charge_supported = 1;
}
static int toshiba_usb_sleep_charge_get(struct toshiba_acpi_dev *dev,
u32 *mode)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_read(dev, SCI_USB_SLEEP_CHARGE, mode);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to set USB S&C mode failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int toshiba_usb_sleep_charge_set(struct toshiba_acpi_dev *dev,
u32 mode)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_write(dev, SCI_USB_SLEEP_CHARGE, mode);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to set USB S&C mode failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int toshiba_sleep_functions_status_get(struct toshiba_acpi_dev *dev,
u32 *mode)
{
u32 in[TCI_WORDS] = { SCI_GET, SCI_USB_SLEEP_CHARGE, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
if (!sci_open(dev))
return -EIO;
in[5] = SCI_USB_CHARGE_BAT_LVL;
status = tci_raw(dev, in, out);
sci_close(dev);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get USB S&C battery level failed\n");
return -EIO;
}
if (out[0] == TOS_NOT_SUPPORTED)
return -ENODEV;
if (out[0] != TOS_SUCCESS)
return -EIO;
*mode = out[2];
return 0;
}
static int toshiba_sleep_functions_status_set(struct toshiba_acpi_dev *dev,
u32 mode)
{
u32 in[TCI_WORDS] = { SCI_SET, SCI_USB_SLEEP_CHARGE, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
if (!sci_open(dev))
return -EIO;
in[2] = mode;
in[5] = SCI_USB_CHARGE_BAT_LVL;
status = tci_raw(dev, in, out);
sci_close(dev);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to set USB S&C battery level failed\n");
return -EIO;
}
if (out[0] == TOS_NOT_SUPPORTED)
return -ENODEV;
return out[0] == TOS_SUCCESS ? 0 : -EIO;
}
static int toshiba_usb_rapid_charge_get(struct toshiba_acpi_dev *dev,
u32 *state)
{
u32 in[TCI_WORDS] = { SCI_GET, SCI_USB_SLEEP_CHARGE, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
if (!sci_open(dev))
return -EIO;
in[5] = SCI_USB_CHARGE_RAPID_DSP;
status = tci_raw(dev, in, out);
sci_close(dev);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get USB Rapid Charge failed\n");
return -EIO;
}
if (out[0] == TOS_NOT_SUPPORTED)
return -ENODEV;
if (out[0] != TOS_SUCCESS && out[0] != TOS_SUCCESS2)
return -EIO;
*state = out[2];
return 0;
}
static int toshiba_usb_rapid_charge_set(struct toshiba_acpi_dev *dev,
u32 state)
{
u32 in[TCI_WORDS] = { SCI_SET, SCI_USB_SLEEP_CHARGE, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
if (!sci_open(dev))
return -EIO;
in[2] = state;
in[5] = SCI_USB_CHARGE_RAPID_DSP;
status = tci_raw(dev, in, out);
sci_close(dev);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to set USB Rapid Charge failed\n");
return -EIO;
}
if (out[0] == TOS_NOT_SUPPORTED)
return -ENODEV;
return (out[0] == TOS_SUCCESS || out[0] == TOS_SUCCESS2) ? 0 : -EIO;
}
static int toshiba_usb_sleep_music_get(struct toshiba_acpi_dev *dev, u32 *state)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_read(dev, SCI_USB_SLEEP_MUSIC, state);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to get Sleep and Music failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int toshiba_usb_sleep_music_set(struct toshiba_acpi_dev *dev, u32 state)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_write(dev, SCI_USB_SLEEP_MUSIC, state);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to set Sleep and Music failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int toshiba_function_keys_get(struct toshiba_acpi_dev *dev, u32 *mode)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_read(dev, SCI_KBD_FUNCTION_KEYS, mode);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to get KBD function keys failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return (result == TOS_SUCCESS || result == TOS_SUCCESS2) ? 0 : -EIO;
}
static int toshiba_function_keys_set(struct toshiba_acpi_dev *dev, u32 mode)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_write(dev, SCI_KBD_FUNCTION_KEYS, mode);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to set KBD function keys failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return (result == TOS_SUCCESS || result == TOS_SUCCESS2) ? 0 : -EIO;
}
static int toshiba_panel_power_on_get(struct toshiba_acpi_dev *dev, u32 *state)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_read(dev, SCI_PANEL_POWER_ON, state);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to get Panel Power ON failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int toshiba_panel_power_on_set(struct toshiba_acpi_dev *dev, u32 state)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_write(dev, SCI_PANEL_POWER_ON, state);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to set Panel Power ON failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int toshiba_usb_three_get(struct toshiba_acpi_dev *dev, u32 *state)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_read(dev, SCI_USB_THREE, state);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to get USB 3 failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return (result == TOS_SUCCESS || result == TOS_SUCCESS2) ? 0 : -EIO;
}
static int toshiba_usb_three_set(struct toshiba_acpi_dev *dev, u32 state)
{
u32 result;
if (!sci_open(dev))
return -EIO;
result = sci_write(dev, SCI_USB_THREE, state);
sci_close(dev);
if (result == TOS_FAILURE)
pr_err("ACPI call to set USB 3 failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return (result == TOS_SUCCESS || result == TOS_SUCCESS2) ? 0 : -EIO;
}
static int toshiba_hotkey_event_type_get(struct toshiba_acpi_dev *dev,
u32 *type)
{
u32 in[TCI_WORDS] = { HCI_GET, HCI_SYSTEM_INFO, 0x03, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get System type failed\n");
return -EIO;
}
if (out[0] == TOS_NOT_SUPPORTED)
return -ENODEV;
if (out[0] != TOS_SUCCESS)
return -EIO;
*type = out[3];
return 0;
}
static int toshiba_wireless_status(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { HCI_GET, HCI_WIRELESS, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
in[3] = HCI_WIRELESS_STATUS;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get Wireless status failed\n");
return -EIO;
}
if (out[0] == TOS_NOT_SUPPORTED)
return -ENODEV;
if (out[0] != TOS_SUCCESS)
return -EIO;
dev->killswitch = !!(out[2] & HCI_WIRELESS_STATUS);
return 0;
}
static void toshiba_wwan_available(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { HCI_GET, HCI_WIRELESS, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
dev->wwan_supported = 0;
in[3] = HCI_WIRELESS_WWAN;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get WWAN status failed\n");
return;
}
if (out[0] != TOS_SUCCESS)
return;
dev->wwan_supported = (out[2] == HCI_WIRELESS_WWAN_STATUS);
}
static int toshiba_wwan_set(struct toshiba_acpi_dev *dev, u32 state)
{
u32 in[TCI_WORDS] = { HCI_SET, HCI_WIRELESS, state, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
in[3] = HCI_WIRELESS_WWAN_STATUS;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to set WWAN status failed\n");
return -EIO;
}
if (out[0] == TOS_NOT_SUPPORTED)
return -ENODEV;
if (out[0] != TOS_SUCCESS)
return -EIO;
in[3] = HCI_WIRELESS_WWAN_POWER;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to set WWAN power failed\n");
return -EIO;
}
if (out[0] == TOS_NOT_SUPPORTED)
return -ENODEV;
return out[0] == TOS_SUCCESS ? 0 : -EIO;
}
static void toshiba_cooling_method_available(struct toshiba_acpi_dev *dev)
{
u32 in[TCI_WORDS] = { HCI_GET, HCI_COOLING_METHOD, 0, 0, 0, 0 };
u32 out[TCI_WORDS];
acpi_status status;
dev->cooling_method_supported = 0;
dev->max_cooling_method = 0;
status = tci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to get Cooling Method failed\n");
return;
}
if (out[0] != TOS_SUCCESS && out[0] != TOS_SUCCESS2)
return;
dev->cooling_method_supported = 1;
dev->max_cooling_method = out[3];
}
static int toshiba_cooling_method_get(struct toshiba_acpi_dev *dev, u32 *state)
{
u32 result = hci_read(dev, HCI_COOLING_METHOD, state);
if (result == TOS_FAILURE)
pr_err("ACPI call to get Cooling Method failed\n");
if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return (result == TOS_SUCCESS || result == TOS_SUCCESS2) ? 0 : -EIO;
}
static int toshiba_cooling_method_set(struct toshiba_acpi_dev *dev, u32 state)
{
u32 result = hci_write(dev, HCI_COOLING_METHOD, state);
if (result == TOS_FAILURE)
pr_err("ACPI call to set Cooling Method failed\n");
if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return (result == TOS_SUCCESS || result == TOS_SUCCESS2) ? 0 : -EIO;
}
static int get_tr_backlight_status(struct toshiba_acpi_dev *dev, u32 *status)
{
u32 result = hci_read(dev, HCI_TR_BACKLIGHT, status);
if (result == TOS_FAILURE)
pr_err("ACPI call to get Transflective Backlight failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int set_tr_backlight_status(struct toshiba_acpi_dev *dev, u32 status)
{
u32 result = hci_write(dev, HCI_TR_BACKLIGHT, !status);
if (result == TOS_FAILURE)
pr_err("ACPI call to set Transflective Backlight failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int __get_lcd_brightness(struct toshiba_acpi_dev *dev)
{
int brightness = 0;
u32 result;
u32 value;
if (dev->tr_backlight_supported) {
int ret = get_tr_backlight_status(dev, &value);
if (ret)
return ret;
if (value)
return 0;
brightness++;
}
result = hci_read(dev, HCI_LCD_BRIGHTNESS, &value);
if (result == TOS_FAILURE)
pr_err("ACPI call to get LCD Brightness failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ?
brightness + (value >> HCI_LCD_BRIGHTNESS_SHIFT) :
-EIO;
}
static int get_lcd_brightness(struct backlight_device *bd)
{
struct toshiba_acpi_dev *dev = bl_get_data(bd);
return __get_lcd_brightness(dev);
}
static int lcd_proc_show(struct seq_file *m, void *v)
{
struct toshiba_acpi_dev *dev = m->private;
int levels;
int value;
if (!dev->backlight_dev)
return -ENODEV;
levels = dev->backlight_dev->props.max_brightness + 1;
value = get_lcd_brightness(dev->backlight_dev);
if (value < 0) {
pr_err("Error reading LCD brightness\n");
return value;
}
seq_printf(m, "brightness: %d\n", value);
seq_printf(m, "brightness_levels: %d\n", levels);
return 0;
}
static int lcd_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, lcd_proc_show, PDE_DATA(inode));
}
static int set_lcd_brightness(struct toshiba_acpi_dev *dev, int value)
{
u32 result;
if (dev->tr_backlight_supported) {
int ret = set_tr_backlight_status(dev, !value);
if (ret)
return ret;
if (value)
value--;
}
value = value << HCI_LCD_BRIGHTNESS_SHIFT;
result = hci_write(dev, HCI_LCD_BRIGHTNESS, value);
if (result == TOS_FAILURE)
pr_err("ACPI call to set LCD Brightness failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int set_lcd_status(struct backlight_device *bd)
{
struct toshiba_acpi_dev *dev = bl_get_data(bd);
return set_lcd_brightness(dev, bd->props.brightness);
}
static ssize_t lcd_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
struct toshiba_acpi_dev *dev = PDE_DATA(file_inode(file));
char cmd[42];
size_t len;
int levels;
int value;
len = min(count, sizeof(cmd) - 1);
if (copy_from_user(cmd, buf, len))
return -EFAULT;
cmd[len] = '\0';
levels = dev->backlight_dev->props.max_brightness + 1;
if (sscanf(cmd, " brightness : %i", &value) != 1 &&
value < 0 && value > levels)
return -EINVAL;
if (set_lcd_brightness(dev, value))
return -EIO;
return count;
}
static int get_video_status(struct toshiba_acpi_dev *dev, u32 *status)
{
u32 result = hci_read(dev, HCI_VIDEO_OUT, status);
if (result == TOS_FAILURE)
pr_err("ACPI call to get Video-Out failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int video_proc_show(struct seq_file *m, void *v)
{
struct toshiba_acpi_dev *dev = m->private;
int is_lcd, is_crt, is_tv;
u32 value;
if (get_video_status(dev, &value))
return -EIO;
is_lcd = (value & HCI_VIDEO_OUT_LCD) ? 1 : 0;
is_crt = (value & HCI_VIDEO_OUT_CRT) ? 1 : 0;
is_tv = (value & HCI_VIDEO_OUT_TV) ? 1 : 0;
seq_printf(m, "lcd_out: %d\n", is_lcd);
seq_printf(m, "crt_out: %d\n", is_crt);
seq_printf(m, "tv_out: %d\n", is_tv);
return 0;
}
static int video_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, video_proc_show, PDE_DATA(inode));
}
static ssize_t video_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
struct toshiba_acpi_dev *dev = PDE_DATA(file_inode(file));
char *buffer;
char *cmd;
int lcd_out, crt_out, tv_out;
int remain = count;
int value;
int ret;
u32 video_out;
cmd = kmalloc(count + 1, GFP_KERNEL);
if (!cmd)
return -ENOMEM;
if (copy_from_user(cmd, buf, count)) {
kfree(cmd);
return -EFAULT;
}
cmd[count] = '\0';
buffer = cmd;
while (remain) {
if (sscanf(buffer, " lcd_out : %i", &value) == 1)
lcd_out = value & 1;
else if (sscanf(buffer, " crt_out : %i", &value) == 1)
crt_out = value & 1;
else if (sscanf(buffer, " tv_out : %i", &value) == 1)
tv_out = value & 1;
do {
++buffer;
--remain;
} while (remain && *(buffer - 1) != ';');
}
kfree(cmd);
lcd_out = crt_out = tv_out = -1;
ret = get_video_status(dev, &video_out);
if (!ret) {
unsigned int new_video_out = video_out;
if (lcd_out != -1)
_set_bit(&new_video_out, HCI_VIDEO_OUT_LCD, lcd_out);
if (crt_out != -1)
_set_bit(&new_video_out, HCI_VIDEO_OUT_CRT, crt_out);
if (tv_out != -1)
_set_bit(&new_video_out, HCI_VIDEO_OUT_TV, tv_out);
if (new_video_out != video_out)
ret = write_acpi_int(METHOD_VIDEO_OUT, new_video_out);
}
return ret ? -EIO : count;
}
static int get_fan_status(struct toshiba_acpi_dev *dev, u32 *status)
{
u32 result = hci_read(dev, HCI_FAN, status);
if (result == TOS_FAILURE)
pr_err("ACPI call to get Fan status failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int set_fan_status(struct toshiba_acpi_dev *dev, u32 status)
{
u32 result = hci_write(dev, HCI_FAN, status);
if (result == TOS_FAILURE)
pr_err("ACPI call to set Fan status failed\n");
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return result == TOS_SUCCESS ? 0 : -EIO;
}
static int fan_proc_show(struct seq_file *m, void *v)
{
struct toshiba_acpi_dev *dev = m->private;
u32 value;
if (get_fan_status(dev, &value))
return -EIO;
seq_printf(m, "running: %d\n", (value > 0));
seq_printf(m, "force_on: %d\n", dev->force_fan);
return 0;
}
static int fan_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, fan_proc_show, PDE_DATA(inode));
}
static ssize_t fan_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
struct toshiba_acpi_dev *dev = PDE_DATA(file_inode(file));
char cmd[42];
size_t len;
int value;
len = min(count, sizeof(cmd) - 1);
if (copy_from_user(cmd, buf, len))
return -EFAULT;
cmd[len] = '\0';
if (sscanf(cmd, " force_on : %i", &value) != 1 &&
value != 0 && value != 1)
return -EINVAL;
if (set_fan_status(dev, value))
return -EIO;
dev->force_fan = value;
return count;
}
static int keys_proc_show(struct seq_file *m, void *v)
{
struct toshiba_acpi_dev *dev = m->private;
seq_printf(m, "hotkey_ready: %d\n", dev->key_event_valid);
seq_printf(m, "hotkey: 0x%04x\n", dev->last_key_event);
return 0;
}
static int keys_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, keys_proc_show, PDE_DATA(inode));
}
static ssize_t keys_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
struct toshiba_acpi_dev *dev = PDE_DATA(file_inode(file));
char cmd[42];
size_t len;
int value;
len = min(count, sizeof(cmd) - 1);
if (copy_from_user(cmd, buf, len))
return -EFAULT;
cmd[len] = '\0';
if (sscanf(cmd, " hotkey_ready : %i", &value) == 1 && value == 0)
dev->key_event_valid = 0;
else
return -EINVAL;
return count;
}
static int version_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "driver: %s\n", TOSHIBA_ACPI_VERSION);
seq_printf(m, "proc_interface: %d\n", PROC_INTERFACE_VERSION);
return 0;
}
static int version_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, version_proc_show, PDE_DATA(inode));
}
static void create_toshiba_proc_entries(struct toshiba_acpi_dev *dev)
{
if (dev->backlight_dev)
proc_create_data("lcd", S_IRUGO | S_IWUSR, toshiba_proc_dir,
&lcd_proc_fops, dev);
if (dev->video_supported)
proc_create_data("video", S_IRUGO | S_IWUSR, toshiba_proc_dir,
&video_proc_fops, dev);
if (dev->fan_supported)
proc_create_data("fan", S_IRUGO | S_IWUSR, toshiba_proc_dir,
&fan_proc_fops, dev);
if (dev->hotkey_dev)
proc_create_data("keys", S_IRUGO | S_IWUSR, toshiba_proc_dir,
&keys_proc_fops, dev);
proc_create_data("version", S_IRUGO, toshiba_proc_dir,
&version_proc_fops, dev);
}
static void remove_toshiba_proc_entries(struct toshiba_acpi_dev *dev)
{
if (dev->backlight_dev)
remove_proc_entry("lcd", toshiba_proc_dir);
if (dev->video_supported)
remove_proc_entry("video", toshiba_proc_dir);
if (dev->fan_supported)
remove_proc_entry("fan", toshiba_proc_dir);
if (dev->hotkey_dev)
remove_proc_entry("keys", toshiba_proc_dir);
remove_proc_entry("version", toshiba_proc_dir);
}
static ssize_t version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", TOSHIBA_ACPI_VERSION);
}
static ssize_t fan_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int state;
int ret;
ret = kstrtoint(buf, 0, &state);
if (ret)
return ret;
if (state != 0 && state != 1)
return -EINVAL;
ret = set_fan_status(toshiba, state);
if (ret)
return ret;
return count;
}
static ssize_t fan_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 value;
int ret;
ret = get_fan_status(toshiba, &value);
if (ret)
return ret;
return sprintf(buf, "%d\n", value);
}
static ssize_t kbd_backlight_mode_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int mode;
int ret;
ret = kstrtoint(buf, 0, &mode);
if (ret)
return ret;
if (toshiba->kbd_type == 1) {
if (mode != SCI_KBD_MODE_FNZ && mode != SCI_KBD_MODE_AUTO)
return -EINVAL;
} else if (toshiba->kbd_type == 2) {
if (mode != SCI_KBD_MODE_AUTO && mode != SCI_KBD_MODE_ON &&
mode != SCI_KBD_MODE_OFF)
return -EINVAL;
}
if (toshiba->kbd_mode != mode) {
int time = toshiba->kbd_time << HCI_MISC_SHIFT;
if (toshiba->kbd_type == 1) {
time |= toshiba->kbd_mode;
} else if (toshiba->kbd_type == 2) {
time |= mode;
}
ret = toshiba_kbd_illum_status_set(toshiba, time);
if (ret)
return ret;
toshiba->kbd_mode = mode;
if (toshiba->kbd_type == 2 &&
!toshiba_acpi->kbd_event_generated)
schedule_work(&kbd_bl_work);
}
return count;
}
static ssize_t kbd_backlight_mode_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 time;
if (toshiba_kbd_illum_status_get(toshiba, &time) < 0)
return -EIO;
return sprintf(buf, "%i\n", time & SCI_KBD_MODE_MASK);
}
static ssize_t kbd_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", toshiba->kbd_type);
}
static ssize_t available_kbd_modes_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
if (toshiba->kbd_type == 1)
return sprintf(buf, "0x%x 0x%x\n",
SCI_KBD_MODE_FNZ, SCI_KBD_MODE_AUTO);
return sprintf(buf, "0x%x 0x%x 0x%x\n",
SCI_KBD_MODE_AUTO, SCI_KBD_MODE_ON, SCI_KBD_MODE_OFF);
}
static ssize_t kbd_backlight_timeout_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int time;
int ret;
ret = kstrtoint(buf, 0, &time);
if (ret)
return ret;
if (toshiba->kbd_type == 1) {
if (time < 0 || time > 60)
return -EINVAL;
} else if (toshiba->kbd_type == 2) {
if (time < 1 || time > 60)
return -EINVAL;
}
if (toshiba->kbd_time != time) {
time = time << HCI_MISC_SHIFT;
if (toshiba->kbd_type == 1)
time |= SCI_KBD_MODE_FNZ;
else if (toshiba->kbd_type == 2)
time |= SCI_KBD_MODE_AUTO;
ret = toshiba_kbd_illum_status_set(toshiba, time);
if (ret)
return ret;
toshiba->kbd_time = time >> HCI_MISC_SHIFT;
}
return count;
}
static ssize_t kbd_backlight_timeout_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 time;
if (toshiba_kbd_illum_status_get(toshiba, &time) < 0)
return -EIO;
return sprintf(buf, "%i\n", time >> HCI_MISC_SHIFT);
}
static ssize_t touchpad_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int state;
int ret;
ret = kstrtoint(buf, 0, &state);
if (ret)
return ret;
if (state != 0 && state != 1)
return -EINVAL;
ret = toshiba_touchpad_set(toshiba, state);
if (ret)
return ret;
return count;
}
static ssize_t touchpad_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 state;
int ret;
ret = toshiba_touchpad_get(toshiba, &state);
if (ret < 0)
return ret;
return sprintf(buf, "%i\n", state);
}
static ssize_t usb_sleep_charge_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 mode;
int ret;
ret = toshiba_usb_sleep_charge_get(toshiba, &mode);
if (ret < 0)
return ret;
return sprintf(buf, "%x\n", mode & SCI_USB_CHARGE_MODE_MASK);
}
static ssize_t usb_sleep_charge_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int state;
u32 mode;
int ret;
ret = kstrtoint(buf, 0, &state);
if (ret)
return ret;
if (state != 0 && state != 1 && state != 2 && state != 3)
return -EINVAL;
mode = toshiba->usbsc_mode_base;
if (state == 0)
mode |= SCI_USB_CHARGE_DISABLED;
else if (state == 1)
mode |= SCI_USB_CHARGE_ALTERNATE;
else if (state == 2)
mode |= SCI_USB_CHARGE_AUTO;
else if (state == 3)
mode |= SCI_USB_CHARGE_TYPICAL;
ret = toshiba_usb_sleep_charge_set(toshiba, mode);
if (ret)
return ret;
return count;
}
static ssize_t sleep_functions_on_battery_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int bat_lvl, status;
u32 state;
int ret;
int tmp;
ret = toshiba_sleep_functions_status_get(toshiba, &state);
if (ret < 0)
return ret;
tmp = state & SCI_USB_CHARGE_BAT_MASK;
status = (tmp == 0x4) ? 1 : 0;
bat_lvl = state >> HCI_MISC_SHIFT;
return sprintf(buf, "%d %d\n", status, bat_lvl);
}
static ssize_t sleep_functions_on_battery_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 status;
int value;
int ret;
int tmp;
ret = kstrtoint(buf, 0, &value);
if (ret)
return ret;
if (value < 0 || value > 100)
return -EINVAL;
if (value == 0) {
tmp = toshiba->usbsc_bat_level << HCI_MISC_SHIFT;
status = tmp | SCI_USB_CHARGE_BAT_LVL_OFF;
} else {
tmp = value << HCI_MISC_SHIFT;
status = tmp | SCI_USB_CHARGE_BAT_LVL_ON;
}
ret = toshiba_sleep_functions_status_set(toshiba, status);
if (ret < 0)
return ret;
toshiba->usbsc_bat_level = status >> HCI_MISC_SHIFT;
return count;
}
static ssize_t usb_rapid_charge_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 state;
int ret;
ret = toshiba_usb_rapid_charge_get(toshiba, &state);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", state);
}
static ssize_t usb_rapid_charge_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int state;
int ret;
ret = kstrtoint(buf, 0, &state);
if (ret)
return ret;
if (state != 0 && state != 1)
return -EINVAL;
ret = toshiba_usb_rapid_charge_set(toshiba, state);
if (ret)
return ret;
return count;
}
static ssize_t usb_sleep_music_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 state;
int ret;
ret = toshiba_usb_sleep_music_get(toshiba, &state);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", state);
}
static ssize_t usb_sleep_music_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int state;
int ret;
ret = kstrtoint(buf, 0, &state);
if (ret)
return ret;
if (state != 0 && state != 1)
return -EINVAL;
ret = toshiba_usb_sleep_music_set(toshiba, state);
if (ret)
return ret;
return count;
}
static ssize_t kbd_function_keys_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int mode;
int ret;
ret = toshiba_function_keys_get(toshiba, &mode);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", mode);
}
static ssize_t kbd_function_keys_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int mode;
int ret;
ret = kstrtoint(buf, 0, &mode);
if (ret)
return ret;
if (mode != 0 && mode != 1)
return -EINVAL;
ret = toshiba_function_keys_set(toshiba, mode);
if (ret)
return ret;
pr_info("Reboot for changes to KBD Function Keys to take effect");
return count;
}
static ssize_t panel_power_on_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 state;
int ret;
ret = toshiba_panel_power_on_get(toshiba, &state);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", state);
}
static ssize_t panel_power_on_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int state;
int ret;
ret = kstrtoint(buf, 0, &state);
if (ret)
return ret;
if (state != 0 && state != 1)
return -EINVAL;
ret = toshiba_panel_power_on_set(toshiba, state);
if (ret)
return ret;
pr_info("Reboot for changes to Panel Power ON to take effect");
return count;
}
static ssize_t usb_three_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
u32 state;
int ret;
ret = toshiba_usb_three_get(toshiba, &state);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", state);
}
static ssize_t usb_three_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int state;
int ret;
ret = kstrtoint(buf, 0, &state);
if (ret)
return ret;
if (state != 0 && state != 1)
return -EINVAL;
ret = toshiba_usb_three_set(toshiba, state);
if (ret)
return ret;
pr_info("Reboot for changes to USB 3 to take effect");
return count;
}
static ssize_t cooling_method_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int state;
int ret;
ret = toshiba_cooling_method_get(toshiba, &state);
if (ret < 0)
return ret;
return sprintf(buf, "%d %d\n", state, toshiba->max_cooling_method);
}
static ssize_t cooling_method_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_acpi_dev *toshiba = dev_get_drvdata(dev);
int state;
int ret;
ret = kstrtoint(buf, 0, &state);
if (ret)
return ret;
if (state < 0 || state > toshiba->max_cooling_method)
return -EINVAL;
ret = toshiba_cooling_method_set(toshiba, state);
if (ret)
return ret;
return count;
}
static umode_t toshiba_sysfs_is_visible(struct kobject *kobj,
struct attribute *attr, int idx)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct toshiba_acpi_dev *drv = dev_get_drvdata(dev);
bool exists = true;
if (attr == &dev_attr_fan.attr)
exists = (drv->fan_supported) ? true : false;
else if (attr == &dev_attr_kbd_backlight_mode.attr)
exists = (drv->kbd_illum_supported) ? true : false;
else if (attr == &dev_attr_kbd_backlight_timeout.attr)
exists = (drv->kbd_mode == SCI_KBD_MODE_AUTO) ? true : false;
else if (attr == &dev_attr_touchpad.attr)
exists = (drv->touchpad_supported) ? true : false;
else if (attr == &dev_attr_usb_sleep_charge.attr)
exists = (drv->usb_sleep_charge_supported) ? true : false;
else if (attr == &dev_attr_sleep_functions_on_battery.attr)
exists = (drv->usb_sleep_charge_supported) ? true : false;
else if (attr == &dev_attr_usb_rapid_charge.attr)
exists = (drv->usb_rapid_charge_supported) ? true : false;
else if (attr == &dev_attr_usb_sleep_music.attr)
exists = (drv->usb_sleep_music_supported) ? true : false;
else if (attr == &dev_attr_kbd_function_keys.attr)
exists = (drv->kbd_function_keys_supported) ? true : false;
else if (attr == &dev_attr_panel_power_on.attr)
exists = (drv->panel_power_on_supported) ? true : false;
else if (attr == &dev_attr_usb_three.attr)
exists = (drv->usb_three_supported) ? true : false;
else if (attr == &dev_attr_cooling_method.attr)
exists = (drv->cooling_method_supported) ? true : false;
return exists ? attr->mode : 0;
}
static void toshiba_acpi_kbd_bl_work(struct work_struct *work)
{
struct acpi_device *acpi_dev = toshiba_acpi->acpi_dev;
if (sysfs_update_group(&acpi_dev->dev.kobj,
&toshiba_attr_group))
pr_err("Unable to update sysfs entries\n");
acpi_bus_generate_netlink_event(acpi_dev->pnp.device_class,
dev_name(&acpi_dev->dev),
0x92, 0);
}
static int toshiba_iio_accel_get_axis(enum toshiba_iio_accel_chan chan)
{
u32 xyval, zval;
int ret;
ret = toshiba_accelerometer_get(toshiba_acpi, &xyval, &zval);
if (ret < 0)
return ret;
switch (chan) {
case AXIS_X:
return xyval & HCI_ACCEL_DIRECTION_MASK ?
-(xyval & HCI_ACCEL_MASK) : xyval & HCI_ACCEL_MASK;
case AXIS_Y:
return (xyval >> HCI_MISC_SHIFT) & HCI_ACCEL_DIRECTION_MASK ?
-((xyval >> HCI_MISC_SHIFT) & HCI_ACCEL_MASK) :
(xyval >> HCI_MISC_SHIFT) & HCI_ACCEL_MASK;
case AXIS_Z:
return zval & HCI_ACCEL_DIRECTION_MASK ?
-(zval & HCI_ACCEL_MASK) : zval & HCI_ACCEL_MASK;
}
return ret;
}
static int toshiba_iio_accel_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = toshiba_iio_accel_get_axis(chan->channel);
if (ret == -EIO || ret == -ENODEV)
return ret;
*val = ret;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int toshiba_acpi_smm_bridge(SMMRegisters *regs)
{
u32 in[TCI_WORDS] = { regs->eax, regs->ebx, regs->ecx,
regs->edx, regs->esi, regs->edi };
u32 out[TCI_WORDS];
acpi_status status;
status = tci_raw(toshiba_acpi, in, out);
if (ACPI_FAILURE(status)) {
pr_err("ACPI call to query SMM registers failed\n");
return -EIO;
}
regs->eax = out[0];
regs->ebx = out[1];
regs->ecx = out[2];
regs->edx = out[3];
regs->esi = out[4];
regs->edi = out[5];
return 0;
}
static long toshiba_acpi_ioctl(struct file *fp, unsigned int cmd,
unsigned long arg)
{
SMMRegisters __user *argp = (SMMRegisters __user *)arg;
SMMRegisters regs;
int ret;
if (!argp)
return -EINVAL;
switch (cmd) {
case TOSH_SMM:
if (copy_from_user(&regs, argp, sizeof(SMMRegisters)))
return -EFAULT;
ret = toshiba_acpi_smm_bridge(&regs);
if (ret)
return ret;
if (copy_to_user(argp, &regs, sizeof(SMMRegisters)))
return -EFAULT;
break;
case TOSHIBA_ACPI_SCI:
if (copy_from_user(&regs, argp, sizeof(SMMRegisters)))
return -EFAULT;
if (regs.eax != SCI_GET && regs.eax != SCI_SET)
return -EINVAL;
if (!sci_open(toshiba_acpi))
return -EIO;
ret = toshiba_acpi_smm_bridge(&regs);
sci_close(toshiba_acpi);
if (ret)
return ret;
if (copy_to_user(argp, &regs, sizeof(SMMRegisters)))
return -EFAULT;
break;
default:
return -EINVAL;
}
return 0;
}
static int toshiba_acpi_wwan_set_block(void *data, bool blocked)
{
struct toshiba_acpi_dev *dev = data;
int ret;
ret = toshiba_wireless_status(dev);
if (ret)
return ret;
if (!dev->killswitch)
return 0;
return toshiba_wwan_set(dev, !blocked);
}
static void toshiba_acpi_wwan_poll(struct rfkill *rfkill, void *data)
{
struct toshiba_acpi_dev *dev = data;
if (toshiba_wireless_status(dev))
return;
rfkill_set_hw_state(dev->wwan_rfk, !dev->killswitch);
}
static int toshiba_acpi_setup_wwan_rfkill(struct toshiba_acpi_dev *dev)
{
int ret = toshiba_wireless_status(dev);
if (ret)
return ret;
dev->wwan_rfk = rfkill_alloc("Toshiba WWAN",
&dev->acpi_dev->dev,
RFKILL_TYPE_WWAN,
&wwan_rfk_ops,
dev);
if (!dev->wwan_rfk) {
pr_err("Unable to allocate WWAN rfkill device\n");
return -ENOMEM;
}
rfkill_set_hw_state(dev->wwan_rfk, !dev->killswitch);
ret = rfkill_register(dev->wwan_rfk);
if (ret) {
pr_err("Unable to register WWAN rfkill device\n");
rfkill_destroy(dev->wwan_rfk);
}
return ret;
}
static int toshiba_acpi_enable_hotkeys(struct toshiba_acpi_dev *dev)
{
acpi_status status;
u32 result;
status = acpi_evaluate_object(dev->acpi_dev->handle,
"ENAB", NULL, NULL);
if (ACPI_FAILURE(status))
return -ENODEV;
if (dev->kbd_function_keys_supported && dev->special_functions)
result = hci_write(dev, HCI_HOTKEY_EVENT,
HCI_HOTKEY_SPECIAL_FUNCTIONS);
else
result = hci_write(dev, HCI_HOTKEY_EVENT, HCI_HOTKEY_ENABLE);
if (result == TOS_FAILURE)
return -EIO;
else if (result == TOS_NOT_SUPPORTED)
return -ENODEV;
return 0;
}
static bool toshiba_acpi_i8042_filter(unsigned char data, unsigned char str,
struct serio *port)
{
if (str & I8042_STR_AUXDATA)
return false;
if (unlikely(data == 0xe0))
return false;
if ((data & 0x7f) == TOS1900_FN_SCAN) {
schedule_work(&toshiba_acpi->hotkey_work);
return true;
}
return false;
}
static void toshiba_acpi_hotkey_work(struct work_struct *work)
{
acpi_handle ec_handle = ec_get_handle();
acpi_status status;
if (!ec_handle)
return;
status = acpi_evaluate_object(ec_handle, "NTFY", NULL, NULL);
if (ACPI_FAILURE(status))
pr_err("ACPI NTFY method execution failed\n");
}
static int toshiba_acpi_query_hotkey(struct toshiba_acpi_dev *dev)
{
unsigned long long value;
acpi_status status;
status = acpi_evaluate_integer(dev->acpi_dev->handle, "INFO",
NULL, &value);
if (ACPI_FAILURE(status)) {
pr_err("ACPI INFO method execution failed\n");
return -EIO;
}
return value;
}
static void toshiba_acpi_report_hotkey(struct toshiba_acpi_dev *dev,
int scancode)
{
if (scancode == 0x100)
return;
if (scancode & 0x80)
return;
if (!sparse_keymap_report_event(dev->hotkey_dev, scancode, 1, true))
pr_info("Unknown key %x\n", scancode);
}
static void toshiba_acpi_process_hotkeys(struct toshiba_acpi_dev *dev)
{
if (dev->info_supported) {
int scancode = toshiba_acpi_query_hotkey(dev);
if (scancode < 0) {
pr_err("Failed to query hotkey event\n");
} else if (scancode != 0) {
toshiba_acpi_report_hotkey(dev, scancode);
dev->key_event_valid = 1;
dev->last_key_event = scancode;
}
} else if (dev->system_event_supported) {
u32 result;
u32 value;
int retries = 3;
do {
result = hci_read(dev, HCI_SYSTEM_EVENT, &value);
switch (result) {
case TOS_SUCCESS:
toshiba_acpi_report_hotkey(dev, (int)value);
dev->key_event_valid = 1;
dev->last_key_event = value;
break;
case TOS_NOT_SUPPORTED:
result = hci_write(dev, HCI_SYSTEM_EVENT, 1);
if (result == TOS_SUCCESS)
pr_notice("Re-enabled hotkeys\n");
default:
retries--;
break;
}
} while (retries && result != TOS_FIFO_EMPTY);
}
}
static int toshiba_acpi_setup_keyboard(struct toshiba_acpi_dev *dev)
{
const struct key_entry *keymap = toshiba_acpi_keymap;
acpi_handle ec_handle;
int error;
if (disable_hotkeys) {
pr_info("Hotkeys disabled by module parameter\n");
return 0;
}
if (wmi_has_guid(TOSHIBA_WMI_EVENT_GUID)) {
pr_info("WMI event detected, hotkeys will not be monitored\n");
return 0;
}
error = toshiba_acpi_enable_hotkeys(dev);
if (error)
return error;
if (toshiba_hotkey_event_type_get(dev, &dev->hotkey_event_type))
pr_notice("Unable to query Hotkey Event Type\n");
dev->hotkey_dev = input_allocate_device();
if (!dev->hotkey_dev)
return -ENOMEM;
dev->hotkey_dev->name = "Toshiba input device";
dev->hotkey_dev->phys = "toshiba_acpi/input0";
dev->hotkey_dev->id.bustype = BUS_HOST;
if (dev->hotkey_event_type == HCI_SYSTEM_TYPE1 ||
!dev->kbd_function_keys_supported)
keymap = toshiba_acpi_keymap;
else if (dev->hotkey_event_type == HCI_SYSTEM_TYPE2 ||
dev->kbd_function_keys_supported)
keymap = toshiba_acpi_alt_keymap;
else
pr_info("Unknown event type received %x\n",
dev->hotkey_event_type);
error = sparse_keymap_setup(dev->hotkey_dev, keymap, NULL);
if (error)
goto err_free_dev;
ec_handle = ec_get_handle();
if (ec_handle && acpi_has_method(ec_handle, "NTFY")) {
INIT_WORK(&dev->hotkey_work, toshiba_acpi_hotkey_work);
error = i8042_install_filter(toshiba_acpi_i8042_filter);
if (error) {
pr_err("Error installing key filter\n");
goto err_free_keymap;
}
dev->ntfy_supported = 1;
}
if (acpi_has_method(dev->acpi_dev->handle, "INFO"))
dev->info_supported = 1;
else if (hci_write(dev, HCI_SYSTEM_EVENT, 1) == TOS_SUCCESS)
dev->system_event_supported = 1;
if (!dev->info_supported && !dev->system_event_supported) {
pr_warn("No hotkey query interface found\n");
goto err_remove_filter;
}
error = input_register_device(dev->hotkey_dev);
if (error) {
pr_info("Unable to register input device\n");
goto err_remove_filter;
}
return 0;
err_remove_filter:
if (dev->ntfy_supported)
i8042_remove_filter(toshiba_acpi_i8042_filter);
err_free_keymap:
sparse_keymap_free(dev->hotkey_dev);
err_free_dev:
input_free_device(dev->hotkey_dev);
dev->hotkey_dev = NULL;
return error;
}
static int toshiba_acpi_setup_backlight(struct toshiba_acpi_dev *dev)
{
struct backlight_properties props;
int brightness;
int ret;
brightness = __get_lcd_brightness(dev);
if (brightness < 0)
return 0;
if (dev->tr_backlight_supported && brightness == 0)
brightness++;
ret = set_lcd_brightness(dev, brightness);
if (ret) {
pr_debug("Backlight method is read-only, disabling backlight support\n");
return 0;
}
if (dev->tr_backlight_supported ||
dmi_check_system(toshiba_vendor_backlight_dmi))
acpi_video_set_dmi_backlight_type(acpi_backlight_vendor);
if (acpi_video_get_backlight_type() != acpi_backlight_vendor)
return 0;
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = HCI_LCD_BRIGHTNESS_LEVELS - 1;
if (dev->tr_backlight_supported)
props.max_brightness++;
dev->backlight_dev = backlight_device_register("toshiba",
&dev->acpi_dev->dev,
dev,
&toshiba_backlight_data,
&props);
if (IS_ERR(dev->backlight_dev)) {
ret = PTR_ERR(dev->backlight_dev);
pr_err("Could not register toshiba backlight device\n");
dev->backlight_dev = NULL;
return ret;
}
dev->backlight_dev->props.brightness = brightness;
return 0;
}
static void print_supported_features(struct toshiba_acpi_dev *dev)
{
pr_info("Supported laptop features:");
if (dev->hotkey_dev)
pr_cont(" hotkeys");
if (dev->backlight_dev)
pr_cont(" backlight");
if (dev->video_supported)
pr_cont(" video-out");
if (dev->fan_supported)
pr_cont(" fan");
if (dev->tr_backlight_supported)
pr_cont(" transflective-backlight");
if (dev->illumination_supported)
pr_cont(" illumination");
if (dev->kbd_illum_supported)
pr_cont(" keyboard-backlight");
if (dev->touchpad_supported)
pr_cont(" touchpad");
if (dev->eco_supported)
pr_cont(" eco-led");
if (dev->accelerometer_supported)
pr_cont(" accelerometer-axes");
if (dev->usb_sleep_charge_supported)
pr_cont(" usb-sleep-charge");
if (dev->usb_rapid_charge_supported)
pr_cont(" usb-rapid-charge");
if (dev->usb_sleep_music_supported)
pr_cont(" usb-sleep-music");
if (dev->kbd_function_keys_supported)
pr_cont(" special-function-keys");
if (dev->panel_power_on_supported)
pr_cont(" panel-power-on");
if (dev->usb_three_supported)
pr_cont(" usb3");
if (dev->wwan_supported)
pr_cont(" wwan");
if (dev->cooling_method_supported)
pr_cont(" cooling-method");
pr_cont("\n");
}
static int toshiba_acpi_remove(struct acpi_device *acpi_dev)
{
struct toshiba_acpi_dev *dev = acpi_driver_data(acpi_dev);
misc_deregister(&dev->miscdev);
remove_toshiba_proc_entries(dev);
if (dev->accelerometer_supported && dev->indio_dev) {
iio_device_unregister(dev->indio_dev);
iio_device_free(dev->indio_dev);
}
if (dev->sysfs_created)
sysfs_remove_group(&dev->acpi_dev->dev.kobj,
&toshiba_attr_group);
if (dev->ntfy_supported) {
i8042_remove_filter(toshiba_acpi_i8042_filter);
cancel_work_sync(&dev->hotkey_work);
}
if (dev->hotkey_dev) {
input_unregister_device(dev->hotkey_dev);
sparse_keymap_free(dev->hotkey_dev);
}
backlight_device_unregister(dev->backlight_dev);
if (dev->illumination_led_registered)
led_classdev_unregister(&dev->led_dev);
if (dev->kbd_led_registered)
led_classdev_unregister(&dev->kbd_led);
if (dev->eco_led_registered)
led_classdev_unregister(&dev->eco_led);
if (dev->wwan_rfk) {
rfkill_unregister(dev->wwan_rfk);
rfkill_destroy(dev->wwan_rfk);
}
if (toshiba_acpi)
toshiba_acpi = NULL;
kfree(dev);
return 0;
}
static const char *find_hci_method(acpi_handle handle)
{
if (acpi_has_method(handle, "GHCI"))
return "GHCI";
if (acpi_has_method(handle, "SPFC"))
return "SPFC";
return NULL;
}
static int toshiba_acpi_add(struct acpi_device *acpi_dev)
{
struct toshiba_acpi_dev *dev;
const char *hci_method;
u32 dummy;
int ret = 0;
if (toshiba_acpi)
return -EBUSY;
pr_info("Toshiba Laptop ACPI Extras version %s\n",
TOSHIBA_ACPI_VERSION);
hci_method = find_hci_method(acpi_dev->handle);
if (!hci_method) {
pr_err("HCI interface not found\n");
return -ENODEV;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->acpi_dev = acpi_dev;
dev->method_hci = hci_method;
dev->miscdev.minor = MISC_DYNAMIC_MINOR;
dev->miscdev.name = "toshiba_acpi";
dev->miscdev.fops = &toshiba_acpi_fops;
ret = misc_register(&dev->miscdev);
if (ret) {
pr_err("Failed to register miscdevice\n");
kfree(dev);
return ret;
}
acpi_dev->driver_data = dev;
dev_set_drvdata(&acpi_dev->dev, dev);
ret = toshiba_function_keys_get(dev, &dev->special_functions);
dev->kbd_function_keys_supported = !ret;
dev->hotkey_event_type = 0;
if (toshiba_acpi_setup_keyboard(dev))
pr_info("Unable to activate hotkeys\n");
ret = get_tr_backlight_status(dev, &dummy);
dev->tr_backlight_supported = !ret;
ret = toshiba_acpi_setup_backlight(dev);
if (ret)
goto error;
toshiba_illumination_available(dev);
if (dev->illumination_supported) {
dev->led_dev.name = "toshiba::illumination";
dev->led_dev.max_brightness = 1;
dev->led_dev.brightness_set = toshiba_illumination_set;
dev->led_dev.brightness_get = toshiba_illumination_get;
if (!led_classdev_register(&acpi_dev->dev, &dev->led_dev))
dev->illumination_led_registered = true;
}
toshiba_eco_mode_available(dev);
if (dev->eco_supported) {
dev->eco_led.name = "toshiba::eco_mode";
dev->eco_led.max_brightness = 1;
dev->eco_led.brightness_set = toshiba_eco_mode_set_status;
dev->eco_led.brightness_get = toshiba_eco_mode_get_status;
if (!led_classdev_register(&dev->acpi_dev->dev, &dev->eco_led))
dev->eco_led_registered = true;
}
toshiba_kbd_illum_available(dev);
if (dev->kbd_illum_supported && dev->kbd_mode == SCI_KBD_MODE_FNZ) {
dev->kbd_led.name = "toshiba::kbd_backlight";
dev->kbd_led.max_brightness = 1;
dev->kbd_led.brightness_set = toshiba_kbd_backlight_set;
dev->kbd_led.brightness_get = toshiba_kbd_backlight_get;
if (!led_classdev_register(&dev->acpi_dev->dev, &dev->kbd_led))
dev->kbd_led_registered = true;
}
ret = toshiba_touchpad_get(dev, &dummy);
dev->touchpad_supported = !ret;
toshiba_accelerometer_available(dev);
if (dev->accelerometer_supported) {
dev->indio_dev = iio_device_alloc(sizeof(*dev));
if (!dev->indio_dev) {
pr_err("Unable to allocate iio device\n");
goto iio_error;
}
pr_info("Registering Toshiba accelerometer iio device\n");
dev->indio_dev->info = &toshiba_iio_accel_info;
dev->indio_dev->name = "Toshiba accelerometer";
dev->indio_dev->dev.parent = &acpi_dev->dev;
dev->indio_dev->modes = INDIO_DIRECT_MODE;
dev->indio_dev->channels = toshiba_iio_accel_channels;
dev->indio_dev->num_channels =
ARRAY_SIZE(toshiba_iio_accel_channels);
ret = iio_device_register(dev->indio_dev);
if (ret < 0) {
pr_err("Unable to register iio device\n");
iio_device_free(dev->indio_dev);
}
}
iio_error:
toshiba_usb_sleep_charge_available(dev);
ret = toshiba_usb_rapid_charge_get(dev, &dummy);
dev->usb_rapid_charge_supported = !ret;
ret = toshiba_usb_sleep_music_get(dev, &dummy);
dev->usb_sleep_music_supported = !ret;
ret = toshiba_panel_power_on_get(dev, &dummy);
dev->panel_power_on_supported = !ret;
ret = toshiba_usb_three_get(dev, &dummy);
dev->usb_three_supported = !ret;
ret = get_video_status(dev, &dummy);
dev->video_supported = !ret;
ret = get_fan_status(dev, &dummy);
dev->fan_supported = !ret;
toshiba_wwan_available(dev);
if (dev->wwan_supported)
toshiba_acpi_setup_wwan_rfkill(dev);
toshiba_cooling_method_available(dev);
print_supported_features(dev);
ret = sysfs_create_group(&dev->acpi_dev->dev.kobj,
&toshiba_attr_group);
if (ret) {
dev->sysfs_created = 0;
goto error;
}
dev->sysfs_created = !ret;
create_toshiba_proc_entries(dev);
toshiba_acpi = dev;
return 0;
error:
toshiba_acpi_remove(acpi_dev);
return ret;
}
static void toshiba_acpi_notify(struct acpi_device *acpi_dev, u32 event)
{
struct toshiba_acpi_dev *dev = acpi_driver_data(acpi_dev);
switch (event) {
case 0x80:
if (wmi_has_guid(TOSHIBA_WMI_EVENT_GUID))
return;
toshiba_acpi_process_hotkeys(dev);
break;
case 0x81:
case 0x82:
case 0x83:
pr_info("Dock event received %x\n", event);
break;
case 0x88:
pr_info("Thermal event received\n");
break;
case 0x8f:
case 0x90:
break;
case 0x8c:
case 0x8b:
pr_info("SATA power event received %x\n", event);
break;
case 0x92:
toshiba_acpi->kbd_event_generated = true;
if (sysfs_update_group(&acpi_dev->dev.kobj,
&toshiba_attr_group))
pr_err("Unable to update sysfs entries\n");
break;
case 0x85:
case 0x8d:
case 0x8e:
case 0x94:
case 0x95:
default:
pr_info("Unknown event received %x\n", event);
break;
}
acpi_bus_generate_netlink_event(acpi_dev->pnp.device_class,
dev_name(&acpi_dev->dev),
event, (event == 0x80) ?
dev->last_key_event : 0);
}
static int toshiba_acpi_suspend(struct device *device)
{
struct toshiba_acpi_dev *dev = acpi_driver_data(to_acpi_device(device));
if (dev->hotkey_dev) {
u32 result;
result = hci_write(dev, HCI_HOTKEY_EVENT, HCI_HOTKEY_DISABLE);
if (result != TOS_SUCCESS)
pr_info("Unable to disable hotkeys\n");
}
return 0;
}
static int toshiba_acpi_resume(struct device *device)
{
struct toshiba_acpi_dev *dev = acpi_driver_data(to_acpi_device(device));
if (dev->hotkey_dev) {
if (toshiba_acpi_enable_hotkeys(dev))
pr_info("Unable to re-enable hotkeys\n");
}
if (dev->wwan_rfk) {
if (!toshiba_wireless_status(dev))
rfkill_set_hw_state(dev->wwan_rfk, !dev->killswitch);
}
return 0;
}
static int __init toshiba_acpi_init(void)
{
int ret;
toshiba_proc_dir = proc_mkdir(PROC_TOSHIBA, acpi_root_dir);
if (!toshiba_proc_dir) {
pr_err("Unable to create proc dir " PROC_TOSHIBA "\n");
return -ENODEV;
}
ret = acpi_bus_register_driver(&toshiba_acpi_driver);
if (ret) {
pr_err("Failed to register ACPI driver: %d\n", ret);
remove_proc_entry(PROC_TOSHIBA, acpi_root_dir);
}
return ret;
}
static void __exit toshiba_acpi_exit(void)
{
acpi_bus_unregister_driver(&toshiba_acpi_driver);
if (toshiba_proc_dir)
remove_proc_entry(PROC_TOSHIBA, acpi_root_dir);
}
