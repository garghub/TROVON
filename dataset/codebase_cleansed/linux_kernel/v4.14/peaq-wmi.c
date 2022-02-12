static void peaq_wmi_poll(struct input_polled_dev *dev)
{
union acpi_object obj;
acpi_status status;
u32 dummy = 0;
struct acpi_buffer input = { sizeof(dummy), &dummy };
struct acpi_buffer output = { sizeof(obj), &obj };
status = wmi_evaluate_method(PEAQ_DOLBY_BUTTON_GUID, 0,
PEAQ_DOLBY_BUTTON_METHOD_ID,
&input, &output);
if (ACPI_FAILURE(status))
return;
if (obj.type != ACPI_TYPE_INTEGER) {
dev_err(&peaq_poll_dev->input->dev,
"Error WMBC did not return an integer\n");
return;
}
if (peaq_ignore_events_counter && peaq_ignore_events_counter--)
return;
if (obj.integer.value) {
input_event(peaq_poll_dev->input, EV_KEY, KEY_SOUND, 1);
input_sync(peaq_poll_dev->input);
input_event(peaq_poll_dev->input, EV_KEY, KEY_SOUND, 0);
input_sync(peaq_poll_dev->input);
peaq_ignore_events_counter = max(1u,
PEAQ_POLL_IGNORE_MS / peaq_poll_dev->poll_interval);
}
}
static int __init peaq_wmi_init(void)
{
if (!wmi_has_guid(PEAQ_DOLBY_BUTTON_GUID))
return -ENODEV;
peaq_poll_dev = input_allocate_polled_device();
if (!peaq_poll_dev)
return -ENOMEM;
peaq_poll_dev->poll = peaq_wmi_poll;
peaq_poll_dev->poll_interval = PEAQ_POLL_INTERVAL_MS;
peaq_poll_dev->poll_interval_max = PEAQ_POLL_MAX_MS;
peaq_poll_dev->input->name = "PEAQ WMI hotkeys";
peaq_poll_dev->input->phys = "wmi/input0";
peaq_poll_dev->input->id.bustype = BUS_HOST;
input_set_capability(peaq_poll_dev->input, EV_KEY, KEY_SOUND);
return input_register_polled_device(peaq_poll_dev);
}
static void __exit peaq_wmi_exit(void)
{
if (!wmi_has_guid(PEAQ_DOLBY_BUTTON_GUID))
return;
input_unregister_polled_device(peaq_poll_dev);
}
