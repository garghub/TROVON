static void keyboard_led_set_brightness(struct led_classdev *cdev,
enum led_brightness brightness)
{
union acpi_object param;
struct acpi_object_list input;
acpi_status status;
param.type = ACPI_TYPE_INTEGER;
param.integer.value = brightness;
input.count = 1;
input.pointer = &param;
status = acpi_evaluate_object(NULL, ACPI_KEYBOARD_BACKLIGHT_WRITE,
&input, NULL);
if (ACPI_FAILURE(status))
dev_err(cdev->dev, "Error setting keyboard LED value: %d\n",
status);
}
static enum led_brightness
keyboard_led_get_brightness(struct led_classdev *cdev)
{
unsigned long long brightness;
acpi_status status;
status = acpi_evaluate_integer(NULL, ACPI_KEYBOARD_BACKLIGHT_READ,
NULL, &brightness);
if (ACPI_FAILURE(status)) {
dev_err(cdev->dev, "Error getting keyboard LED value: %d\n",
status);
return -EIO;
}
return brightness;
}
static int keyboard_led_probe(struct platform_device *pdev)
{
struct led_classdev *cdev;
acpi_handle handle;
acpi_status status;
int error;
status = acpi_get_handle(ACPI_ROOT_OBJECT,
ACPI_KEYBOARD_BACKLIGHT_DEVICE,
&handle);
if (ACPI_FAILURE(status)) {
dev_err(&pdev->dev, "Unable to find ACPI device %s: %d\n",
ACPI_KEYBOARD_BACKLIGHT_DEVICE, status);
return -ENXIO;
}
cdev = devm_kzalloc(&pdev->dev, sizeof(*cdev), GFP_KERNEL);
if (!cdev)
return -ENOMEM;
cdev->name = "chromeos::kbd_backlight";
cdev->max_brightness = ACPI_KEYBOARD_BACKLIGHT_MAX;
cdev->flags |= LED_CORE_SUSPENDRESUME;
cdev->brightness_set = keyboard_led_set_brightness;
cdev->brightness_get = keyboard_led_get_brightness;
error = devm_led_classdev_register(&pdev->dev, cdev);
if (error)
return error;
return 0;
}
