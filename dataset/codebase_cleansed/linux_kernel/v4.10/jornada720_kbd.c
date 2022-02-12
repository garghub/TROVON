static irqreturn_t jornada720_kbd_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct jornadakbd *jornadakbd = platform_get_drvdata(pdev);
struct input_dev *input = jornadakbd->input;
u8 count, kbd_data, scan_code;
jornada_ssp_start();
if (jornada_ssp_inout(GETSCANKEYCODE) != TXDUMMY) {
dev_dbg(&pdev->dev,
"GetKeycode command failed with ETIMEDOUT, flushed bus\n");
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
static int jornada720_kbd_probe(struct platform_device *pdev)
{
struct jornadakbd *jornadakbd;
struct input_dev *input_dev;
int i, err, irq;
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return irq < 0 ? irq : -EINVAL;
jornadakbd = devm_kzalloc(&pdev->dev, sizeof(*jornadakbd), GFP_KERNEL);
input_dev = devm_input_allocate_device(&pdev->dev);
if (!jornadakbd || !input_dev)
return -ENOMEM;
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
err = devm_request_irq(&pdev->dev, irq, jornada720_kbd_interrupt,
IRQF_TRIGGER_FALLING, "jornadakbd", pdev);
if (err) {
dev_err(&pdev->dev, "unable to grab IRQ%d: %d\n", irq, err);
return err;
}
return input_register_device(jornadakbd->input);
}
