static int dell_led_perform_fn(u8 length, u8 result_code, u8 device_id,
u8 command, u8 on_time, u8 off_time)
{
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
struct bios_args *bios_return;
struct acpi_buffer input;
union acpi_object *obj;
acpi_status status;
u8 return_code;
struct bios_args args = {
.length = length,
.result_code = result_code,
.device_id = device_id,
.command = command,
.on_time = on_time,
.off_time = off_time
};
input.length = sizeof(struct bios_args);
input.pointer = &args;
status = wmi_evaluate_method(DELL_LED_BIOS_GUID, 1, 1, &input, &output);
if (ACPI_FAILURE(status))
return status;
obj = output.pointer;
if (!obj)
return -EINVAL;
if (obj->type != ACPI_TYPE_BUFFER) {
kfree(obj);
return -EINVAL;
}
bios_return = ((struct bios_args *)obj->buffer.pointer);
return_code = bios_return->result_code;
kfree(obj);
return return_code;
}
static int led_on(void)
{
return dell_led_perform_fn(3,
INTERFACE_ERROR,
DEVICE_ID_PANEL_BACK,
CMD_LED_ON,
0,
0);
}
static int led_off(void)
{
return dell_led_perform_fn(3,
INTERFACE_ERROR,
DEVICE_ID_PANEL_BACK,
CMD_LED_OFF,
0,
0);
}
static int led_blink(unsigned char on_eighths, unsigned char off_eighths)
{
return dell_led_perform_fn(5,
INTERFACE_ERROR,
DEVICE_ID_PANEL_BACK,
CMD_LED_BLINK,
on_eighths,
off_eighths);
}
static void dell_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value == LED_OFF)
led_off();
else
led_on();
}
static int dell_led_blink(struct led_classdev *led_cdev,
unsigned long *delay_on, unsigned long *delay_off)
{
unsigned long on_eighths;
unsigned long off_eighths;
on_eighths = DIV_ROUND_UP(*delay_on, 125);
on_eighths = clamp_t(unsigned long, on_eighths, 1, 255);
*delay_on = on_eighths * 125;
off_eighths = DIV_ROUND_UP(*delay_off, 125);
off_eighths = clamp_t(unsigned long, off_eighths, 1, 255);
*delay_off = off_eighths * 125;
led_blink(on_eighths, off_eighths);
return 0;
}
static int __init dell_led_init(void)
{
int error = 0;
if (!wmi_has_guid(DELL_LED_BIOS_GUID))
return -ENODEV;
error = led_off();
if (error != 0)
return -ENODEV;
return led_classdev_register(NULL, &dell_led);
}
static void __exit dell_led_exit(void)
{
led_classdev_unregister(&dell_led);
led_off();
}
