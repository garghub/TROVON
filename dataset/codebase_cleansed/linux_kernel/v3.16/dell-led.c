static int dell_wmi_perform_query(struct app_wmi_args *args)
{
struct app_wmi_args *bios_return;
union acpi_object *obj;
struct acpi_buffer input;
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_status status;
u32 rc = -EINVAL;
input.length = 128;
input.pointer = args;
status = wmi_evaluate_method(DELL_APP_GUID, 0, 1, &input, &output);
if (!ACPI_SUCCESS(status))
goto err_out0;
obj = output.pointer;
if (!obj)
goto err_out0;
if (obj->type != ACPI_TYPE_BUFFER)
goto err_out1;
bios_return = (struct app_wmi_args *)obj->buffer.pointer;
rc = bios_return->res1;
if (rc)
goto err_out1;
memcpy(args, bios_return, sizeof(struct app_wmi_args));
rc = 0;
err_out1:
kfree(obj);
err_out0:
return rc;
}
static void __init find_micmute_tokens(const struct dmi_header *dm, void *dummy)
{
struct dell_bios_calling_interface *calling_interface;
struct dell_bios_data_token *token;
int token_size = sizeof(struct dell_bios_data_token);
int i = 0;
if (dm->type == 0xda && dm->length > 17) {
calling_interface = container_of(dm,
struct dell_bios_calling_interface, header);
token = &calling_interface->damap[i];
while (token->tokenid != 0xffff) {
if (token->tokenid == GLOBAL_MIC_MUTE_DISABLE)
memcpy(&dell_mic_tokens[0], token, token_size);
else if (token->tokenid == GLOBAL_MIC_MUTE_ENABLE)
memcpy(&dell_mic_tokens[1], token, token_size);
i++;
token = &calling_interface->damap[i];
}
}
}
static int dell_micmute_led_set(int state)
{
struct app_wmi_args args;
struct dell_bios_data_token *token;
if (!wmi_has_guid(DELL_APP_GUID))
return -ENODEV;
if (state == 0 || state == 1)
token = &dell_mic_tokens[state];
else
return -EINVAL;
memset(&args, 0, sizeof(struct app_wmi_args));
args.class = 1;
args.arg1 = token->location;
args.arg2 = token->value;
dell_wmi_perform_query(&args);
return state;
}
int dell_app_wmi_led_set(int whichled, int on)
{
int state = 0;
switch (whichled) {
case DELL_LED_MICMUTE:
state = dell_micmute_led_set(on);
break;
default:
pr_warn("led type %x is not supported\n", whichled);
break;
}
return state;
}
static int __init dell_micmute_led_init(void)
{
memset(dell_mic_tokens, 0, sizeof(struct dell_bios_data_token) * 2);
dmi_walk(find_micmute_tokens, NULL);
return 0;
}
static int dell_led_perform_fn(u8 length,
u8 result_code,
u8 device_id,
u8 command,
u8 on_time,
u8 off_time)
{
struct bios_args *bios_return;
u8 return_code;
union acpi_object *obj;
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer input;
acpi_status status;
struct bios_args args;
args.length = length;
args.result_code = result_code;
args.device_id = device_id;
args.command = command;
args.on_time = on_time;
args.off_time = off_time;
input.length = sizeof(struct bios_args);
input.pointer = &args;
status = wmi_evaluate_method(DELL_LED_BIOS_GUID,
1,
1,
&input,
&output);
if (ACPI_FAILURE(status))
return status;
obj = output.pointer;
if (!obj)
return -EINVAL;
else if (obj->type != ACPI_TYPE_BUFFER) {
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
static int led_blink(unsigned char on_eighths,
unsigned char off_eighths)
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
unsigned long *delay_on,
unsigned long *delay_off)
{
unsigned long on_eighths;
unsigned long off_eighths;
on_eighths = (*delay_on + 124) / 125;
if (0 == on_eighths)
on_eighths = 1;
if (on_eighths > 255)
on_eighths = 255;
*delay_on = on_eighths * 125;
off_eighths = (*delay_off + 124) / 125;
if (0 == off_eighths)
off_eighths = 1;
if (off_eighths > 255)
off_eighths = 255;
*delay_off = off_eighths * 125;
led_blink(on_eighths, off_eighths);
return 0;
}
static int __init dell_led_init(void)
{
int error = 0;
if (!wmi_has_guid(DELL_LED_BIOS_GUID) && !wmi_has_guid(DELL_APP_GUID))
return -ENODEV;
if (wmi_has_guid(DELL_APP_GUID))
error = dell_micmute_led_init();
if (wmi_has_guid(DELL_LED_BIOS_GUID)) {
error = led_off();
if (error != 0)
return -ENODEV;
error = led_classdev_register(NULL, &dell_led);
}
return error;
}
static void __exit dell_led_exit(void)
{
int error = 0;
if (wmi_has_guid(DELL_LED_BIOS_GUID)) {
error = led_off();
if (error == 0)
led_classdev_unregister(&dell_led);
}
}
