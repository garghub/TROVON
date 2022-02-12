static void nvec_kbd_toggle_led(void)
{
keys_dev.caps_lock = !keys_dev.caps_lock;
if (keys_dev.caps_lock)
nvec_write_async(keys_dev.nvec, led_on, sizeof(led_on));
else
nvec_write_async(keys_dev.nvec, led_off, sizeof(led_off));
}
static int nvec_keys_notifier(struct notifier_block *nb,
unsigned long event_type, void *data)
{
int code, state;
unsigned char *msg = (unsigned char *)data;
if (event_type == NVEC_KB_EVT) {
int _size = (msg[0] & (3 << 5)) >> 5;
if (_size == NVEC_VAR_SIZE)
return NOTIFY_STOP;
if (_size == NVEC_3BYTES)
msg++;
code = msg[1] & 0x7f;
state = msg[1] & 0x80;
if (code_tabs[_size][code] == KEY_CAPSLOCK && state)
nvec_kbd_toggle_led();
input_report_key(keys_dev.input, code_tabs[_size][code],
!state);
input_sync(keys_dev.input);
return NOTIFY_STOP;
}
return NOTIFY_DONE;
}
static int nvec_kbd_event(struct input_dev *dev, unsigned int type,
unsigned int code, int value)
{
unsigned char buf[] = ACK_KBD_EVENT;
struct nvec_chip *nvec = keys_dev.nvec;
if (type == EV_REP)
return 0;
if (type != EV_LED)
return -1;
if (code != LED_CAPSL)
return -1;
buf[2] = !!value;
nvec_write_async(nvec, buf, sizeof(buf));
return 0;
}
static int nvec_kbd_probe(struct platform_device *pdev)
{
struct nvec_chip *nvec = dev_get_drvdata(pdev->dev.parent);
int i, j, err;
struct input_dev *idev;
j = 0;
for (i = 0; i < ARRAY_SIZE(code_tab_102us); ++i)
keycodes[j++] = code_tab_102us[i];
for (i = 0; i < ARRAY_SIZE(extcode_tab_us102); ++i)
keycodes[j++] = extcode_tab_us102[i];
idev = input_allocate_device();
idev->name = "nvec keyboard";
idev->phys = "nvec";
idev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP) | BIT_MASK(EV_LED);
idev->ledbit[0] = BIT_MASK(LED_CAPSL);
idev->event = nvec_kbd_event;
idev->keycode = keycodes;
idev->keycodesize = sizeof(unsigned char);
idev->keycodemax = ARRAY_SIZE(keycodes);
for (i = 0; i < ARRAY_SIZE(keycodes); ++i)
set_bit(keycodes[i], idev->keybit);
clear_bit(0, idev->keybit);
err = input_register_device(idev);
if (err)
goto fail;
keys_dev.input = idev;
keys_dev.notifier.notifier_call = nvec_keys_notifier;
keys_dev.nvec = nvec;
nvec_register_notifier(nvec, &keys_dev.notifier, 0);
nvec_write_async(nvec, "\x05\xf4", 2);
nvec_write_async(nvec, "\x05\x03\x01\x01", 4);
nvec_write_async(nvec, "\x05\x04\x01", 3);
nvec_write_async(nvec, "\x06\x01\xff\x03", 4);
mdelay(1000);
nvec_write_async(nvec, led_off, sizeof(led_off));
return 0;
fail:
input_free_device(idev);
return err;
}
static int nvec_kbd_remove(struct platform_device *pdev)
{
input_unregister_device(keys_dev.input);
input_free_device(keys_dev.input);
return 0;
}
