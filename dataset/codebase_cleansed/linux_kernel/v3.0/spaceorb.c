static void spaceorb_process_packet(struct spaceorb *spaceorb)
{
struct input_dev *dev = spaceorb->dev;
unsigned char *data = spaceorb->data;
unsigned char c = 0;
int axes[6];
int i;
if (spaceorb->idx < 2) return;
for (i = 0; i < spaceorb->idx; i++) c ^= data[i];
if (c) return;
switch (data[0]) {
case 'R':
spaceorb->data[spaceorb->idx - 1] = 0;
for (i = 1; i < spaceorb->idx && spaceorb->data[i] == ' '; i++);
printk(KERN_INFO "input: %s [%s] is %s\n",
dev->name, spaceorb->data + i, spaceorb->phys);
break;
case 'D':
if (spaceorb->idx != 12) return;
for (i = 0; i < 9; i++) spaceorb->data[i+2] ^= spaceorb_xor[i];
axes[0] = ( data[2] << 3) | (data[ 3] >> 4);
axes[1] = ((data[3] & 0x0f) << 6) | (data[ 4] >> 1);
axes[2] = ((data[4] & 0x01) << 9) | (data[ 5] << 2) | (data[4] >> 5);
axes[3] = ((data[6] & 0x1f) << 5) | (data[ 7] >> 2);
axes[4] = ((data[7] & 0x03) << 8) | (data[ 8] << 1) | (data[7] >> 6);
axes[5] = ((data[9] & 0x3f) << 4) | (data[10] >> 3);
for (i = 0; i < 6; i++)
input_report_abs(dev, spaceorb_axes[i], axes[i] - ((axes[i] & 0x200) ? 1024 : 0));
for (i = 0; i < 6; i++)
input_report_key(dev, spaceorb_buttons[i], (data[1] >> i) & 1);
break;
case 'K':
if (spaceorb->idx != 5) return;
for (i = 0; i < 6; i++)
input_report_key(dev, spaceorb_buttons[i], (data[2] >> i) & 1);
break;
case 'E':
if (spaceorb->idx != 4) return;
printk(KERN_ERR "spaceorb: Device error. [ ");
for (i = 0; i < 7; i++) if (data[1] & (1 << i)) printk("%s ", spaceorb_errors[i]);
printk("]\n");
break;
}
input_sync(dev);
}
static irqreturn_t spaceorb_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct spaceorb* spaceorb = serio_get_drvdata(serio);
if (~data & 0x80) {
if (spaceorb->idx) spaceorb_process_packet(spaceorb);
spaceorb->idx = 0;
}
if (spaceorb->idx < SPACEORB_MAX_LENGTH)
spaceorb->data[spaceorb->idx++] = data & 0x7f;
return IRQ_HANDLED;
}
static void spaceorb_disconnect(struct serio *serio)
{
struct spaceorb* spaceorb = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(spaceorb->dev);
kfree(spaceorb);
}
static int spaceorb_connect(struct serio *serio, struct serio_driver *drv)
{
struct spaceorb *spaceorb;
struct input_dev *input_dev;
int err = -ENOMEM;
int i;
spaceorb = kzalloc(sizeof(struct spaceorb), GFP_KERNEL);
input_dev = input_allocate_device();
if (!spaceorb || !input_dev)
goto fail1;
spaceorb->dev = input_dev;
snprintf(spaceorb->phys, sizeof(spaceorb->phys), "%s/input0", serio->phys);
input_dev->name = "SpaceTec SpaceOrb 360 / Avenger";
input_dev->phys = spaceorb->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_SPACEORB;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
for (i = 0; i < 6; i++)
set_bit(spaceorb_buttons[i], input_dev->keybit);
for (i = 0; i < 6; i++)
input_set_abs_params(input_dev, spaceorb_axes[i], -508, 508, 0, 0);
serio_set_drvdata(serio, spaceorb);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(spaceorb->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(spaceorb);
return err;
}
static int __init spaceorb_init(void)
{
return serio_register_driver(&spaceorb_drv);
}
static void __exit spaceorb_exit(void)
{
serio_unregister_driver(&spaceorb_drv);
}
