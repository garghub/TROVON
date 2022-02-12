static void egalax_process_data(struct egalax *egalax)
{
struct input_dev *dev = egalax->input;
u8 *data = egalax->data;
u16 x, y;
u8 shift;
u8 mask;
shift = 3 - ((data[0] & EGALAX_FORMAT_RESOLUTION_MASK) >> 1);
mask = 0xff >> (shift + 1);
x = (((u16)(data[1] & mask) << 7) | (data[2] & 0x7f)) << shift;
y = (((u16)(data[3] & mask) << 7) | (data[4] & 0x7f)) << shift;
input_report_key(dev, BTN_TOUCH, data[0] & EGALAX_FORMAT_TOUCH_BIT);
input_report_abs(dev, ABS_X, x);
input_report_abs(dev, ABS_Y, y);
input_sync(dev);
}
static irqreturn_t egalax_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct egalax *egalax = serio_get_drvdata(serio);
int pkt_len;
egalax->data[egalax->idx++] = data;
if (likely(egalax->data[0] & EGALAX_FORMAT_START_BIT)) {
pkt_len = egalax->data[0] & EGALAX_FORMAT_PRESSURE_BIT ? 6 : 5;
if (pkt_len == egalax->idx) {
egalax_process_data(egalax);
egalax->idx = 0;
}
} else {
dev_dbg(&serio->dev, "unknown/unsynchronized data: %x\n",
egalax->data[0]);
egalax->idx = 0;
}
return IRQ_HANDLED;
}
static int egalax_connect(struct serio *serio, struct serio_driver *drv)
{
struct egalax *egalax;
struct input_dev *input_dev;
int error;
egalax = kzalloc(sizeof(struct egalax), GFP_KERNEL);
input_dev = input_allocate_device();
if (!egalax || !input_dev) {
error = -ENOMEM;
goto err_free_mem;
}
egalax->serio = serio;
egalax->input = input_dev;
snprintf(egalax->phys, sizeof(egalax->phys),
"%s/input0", serio->phys);
input_dev->name = "EETI eGalaxTouch Serial TouchScreen";
input_dev->phys = egalax->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_EGALAX;
input_dev->id.product = 0;
input_dev->id.version = 0x0001;
input_dev->dev.parent = &serio->dev;
input_set_capability(input_dev, EV_KEY, BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X,
EGALAX_MIN_XC, EGALAX_MAX_XC, 0, 0);
input_set_abs_params(input_dev, ABS_Y,
EGALAX_MIN_YC, EGALAX_MAX_YC, 0, 0);
serio_set_drvdata(serio, egalax);
error = serio_open(serio, drv);
if (error)
goto err_reset_drvdata;
error = input_register_device(input_dev);
if (error)
goto err_close_serio;
return 0;
err_close_serio:
serio_close(serio);
err_reset_drvdata:
serio_set_drvdata(serio, NULL);
err_free_mem:
input_free_device(input_dev);
kfree(egalax);
return error;
}
static void egalax_disconnect(struct serio *serio)
{
struct egalax *egalax = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(egalax->input);
kfree(egalax);
}
