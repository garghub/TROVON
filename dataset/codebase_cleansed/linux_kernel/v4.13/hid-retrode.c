static int retrode_input_configured(struct hid_device *hdev,
struct hid_input *hi)
{
struct hid_field *field = hi->report->field[0];
const char *suffix;
int number = 0;
char *name;
switch (field->report->id) {
case 0:
suffix = "SNES Mouse";
break;
case 1:
case 2:
suffix = "SNES / N64";
number = field->report->id;
break;
case 3:
case 4:
suffix = "Mega Drive";
number = field->report->id - 2;
break;
default:
hid_err(hdev, "Got unhandled report id %d\n", field->report->id);
suffix = "Unknown";
}
if (number)
name = devm_kasprintf(&hdev->dev, GFP_KERNEL,
"%s %s #%d", CONTROLLER_NAME_BASE,
suffix, number);
else
name = devm_kasprintf(&hdev->dev, GFP_KERNEL,
"%s %s", CONTROLLER_NAME_BASE, suffix);
if (!name)
return -ENOMEM;
hi->input->name = name;
return 0;
}
static int retrode_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int ret;
hdev->quirks |= HID_QUIRK_MULTI_INPUT;
ret = hid_parse(hdev);
if (ret)
return ret;
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret)
return ret;
return 0;
}
