static void zhenhua_process_packet(struct zhenhua *zhenhua)
{
struct input_dev *dev = zhenhua->dev;
unsigned char *data = zhenhua->data;
input_report_abs(dev, ABS_Y, data[1]);
input_report_abs(dev, ABS_X, data[2]);
input_report_abs(dev, ABS_RZ, data[3]);
input_report_abs(dev, ABS_Z, data[4]);
input_sync(dev);
}
static irqreturn_t zhenhua_interrupt(struct serio *serio, unsigned char data, unsigned int flags)
{
struct zhenhua *zhenhua = serio_get_drvdata(serio);
if (data == 0xef)
zhenhua->idx = 0;
else if (zhenhua->idx == 0)
return IRQ_HANDLED;
if (zhenhua->idx < ZHENHUA_MAX_LENGTH)
zhenhua->data[zhenhua->idx++] = bitrev8(data);
if (zhenhua->idx == ZHENHUA_MAX_LENGTH) {
zhenhua_process_packet(zhenhua);
zhenhua->idx = 0;
}
return IRQ_HANDLED;
}
static void zhenhua_disconnect(struct serio *serio)
{
struct zhenhua *zhenhua = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(zhenhua->dev);
kfree(zhenhua);
}
static int zhenhua_connect(struct serio *serio, struct serio_driver *drv)
{
struct zhenhua *zhenhua;
struct input_dev *input_dev;
int err = -ENOMEM;
zhenhua = kzalloc(sizeof(struct zhenhua), GFP_KERNEL);
input_dev = input_allocate_device();
if (!zhenhua || !input_dev)
goto fail1;
zhenhua->dev = input_dev;
snprintf(zhenhua->phys, sizeof(zhenhua->phys), "%s/input0", serio->phys);
input_dev->name = "Zhen Hua 5-byte device";
input_dev->phys = zhenhua->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_ZHENHUA;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT(EV_ABS);
input_set_abs_params(input_dev, ABS_X, 50, 200, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 50, 200, 0, 0);
input_set_abs_params(input_dev, ABS_Z, 50, 200, 0, 0);
input_set_abs_params(input_dev, ABS_RZ, 50, 200, 0, 0);
serio_set_drvdata(serio, zhenhua);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(zhenhua->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(zhenhua);
return err;
}
