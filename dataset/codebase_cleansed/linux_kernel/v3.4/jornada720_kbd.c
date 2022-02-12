static irqreturn_t jornada720_kbd_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct jornadakbd *jornadakbd = platform_get_drvdata(pdev);
struct input_dev *input = jornadakbd->input;
u8 count, kbd_data, scan_code;
jornada_ssp_start();
if (jornada_ssp_inout(GETSCANKEYCODE) != TXDUMMY) {
printk(KERN_DEBUG
"jornada720_kbd: "
"GetKeycode command failed with ETIMEDOUT, "
"flushed bus\n");
} else {
count = jornada_ssp_byte(TXDUMMY);
while (count--) {
kbd_data = jornada_ssp_byte(TXDUMMY);
scan_code = kbd_data & 0x7f;
input_event(input, EV_MSC, MSC_SCAN, scan_code);
input_report_key(input, jornadakbd->keymap[scan_code],
!(kbd_data & 0x80));
input_sync(input);
}
}
jornada_ssp_end();
return IRQ_HANDLED;
}
static int __devinit jornada720_kbd_probe(struct platform_device *pdev)
{
struct jornadakbd *jornadakbd;
struct input_dev *input_dev;
int i, err;
jornadakbd = kzalloc(sizeof(struct jornadakbd), GFP_KERNEL);
input_dev = input_allocate_device();
if (!jornadakbd || !input_dev) {
err = -ENOMEM;
goto fail1;
}
platform_set_drvdata(pdev, jornadakbd);
memcpy(jornadakbd->keymap, jornada_std_keymap,
sizeof(jornada_std_keymap));
jornadakbd->input = input_dev;
input_dev->evbit[0] = BIT(EV_KEY) | BIT(EV_REP);
input_dev->name = "HP Jornada 720 keyboard";
input_dev->phys = "jornadakbd/input0";
input_dev->keycode = jornadakbd->keymap;
input_dev->keycodesize = sizeof(unsigned short);
input_dev->keycodemax = ARRAY_SIZE(jornada_std_keymap);
input_dev->id.bustype = BUS_HOST;
input_dev->dev.parent = &pdev->dev;
for (i = 0; i < ARRAY_SIZE(jornadakbd->keymap); i++)
__set_bit(jornadakbd->keymap[i], input_dev->keybit);
__clear_bit(KEY_RESERVED, input_dev->keybit);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
err = request_irq(IRQ_GPIO0,
jornada720_kbd_interrupt,
IRQF_TRIGGER_FALLING,
"jornadakbd", pdev);
if (err) {
printk(KERN_INFO "jornadakbd720_kbd: Unable to grab IRQ\n");
goto fail1;
}
err = input_register_device(jornadakbd->input);
if (err)
goto fail2;
return 0;
fail2:
free_irq(IRQ_GPIO0, pdev);
fail1:
platform_set_drvdata(pdev, NULL);
input_free_device(input_dev);
kfree(jornadakbd);
return err;
}
static int __devexit jornada720_kbd_remove(struct platform_device *pdev)
{
struct jornadakbd *jornadakbd = platform_get_drvdata(pdev);
free_irq(IRQ_GPIO0, pdev);
platform_set_drvdata(pdev, NULL);
input_unregister_device(jornadakbd->input);
kfree(jornadakbd);
return 0;
}
