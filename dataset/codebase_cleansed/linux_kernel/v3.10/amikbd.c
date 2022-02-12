static irqreturn_t amikbd_interrupt(int irq, void *data)
{
struct input_dev *dev = data;
unsigned char scancode, down;
scancode = ~ciaa.sdr;
ciaa.cra |= 0x40;
udelay(85);
ciaa.cra &= ~0x40;
down = !(scancode & 1);
scancode >>= 1;
if (scancode < 0x78) {
if (scancode == 98) {
input_report_key(dev, scancode, 1);
input_report_key(dev, scancode, 0);
} else {
input_report_key(dev, scancode, down);
}
input_sync(dev);
} else
printk(amikbd_messages[scancode - 0x78]);
return IRQ_HANDLED;
}
static int __init amikbd_probe(struct platform_device *pdev)
{
struct input_dev *dev;
int i, j, err;
dev = input_allocate_device();
if (!dev) {
dev_err(&pdev->dev, "Not enough memory for input device\n");
return -ENOMEM;
}
dev->name = pdev->name;
dev->phys = "amikbd/input0";
dev->id.bustype = BUS_AMIGA;
dev->id.vendor = 0x0001;
dev->id.product = 0x0001;
dev->id.version = 0x0100;
dev->dev.parent = &pdev->dev;
dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
for (i = 0; i < 0x78; i++)
set_bit(i, dev->keybit);
for (i = 0; i < MAX_NR_KEYMAPS; i++) {
static u_short temp_map[NR_KEYS] __initdata;
if (!key_maps[i])
continue;
memset(temp_map, 0, sizeof(temp_map));
for (j = 0; j < 0x78; j++) {
if (!amikbd_keycode[j])
continue;
temp_map[j] = key_maps[i][amikbd_keycode[j]];
}
for (j = 0; j < NR_KEYS; j++) {
if (!temp_map[j])
temp_map[j] = 0xf200;
}
memcpy(key_maps[i], temp_map, sizeof(temp_map));
}
ciaa.cra &= ~0x41;
err = request_irq(IRQ_AMIGA_CIAA_SP, amikbd_interrupt, 0, "amikbd",
dev);
if (err)
goto fail2;
err = input_register_device(dev);
if (err)
goto fail3;
platform_set_drvdata(pdev, dev);
return 0;
fail3: free_irq(IRQ_AMIGA_CIAA_SP, dev);
fail2: input_free_device(dev);
return err;
}
static int __exit amikbd_remove(struct platform_device *pdev)
{
struct input_dev *dev = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
free_irq(IRQ_AMIGA_CIAA_SP, dev);
input_unregister_device(dev);
return 0;
}
