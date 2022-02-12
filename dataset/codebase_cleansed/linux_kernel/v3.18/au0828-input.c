static int au8522_rc_write(struct au0828_rc *ir, u16 reg, u8 data)
{
int rc;
char buf[] = { (reg >> 8) | 0x80, reg & 0xff, data };
struct i2c_msg msg = { .addr = ir->i2c_dev_addr, .flags = 0,
.buf = buf, .len = sizeof(buf) };
rc = i2c_transfer(ir->dev->i2c_client.adapter, &msg, 1);
if (rc < 0)
return rc;
return (rc == 1) ? 0 : -EIO;
}
static int au8522_rc_read(struct au0828_rc *ir, u16 reg, int val,
char *buf, int size)
{
int rc;
char obuf[3];
struct i2c_msg msg[2] = { { .addr = ir->i2c_dev_addr, .flags = 0,
.buf = obuf, .len = 2 },
{ .addr = ir->i2c_dev_addr, .flags = I2C_M_RD,
.buf = buf, .len = size } };
obuf[0] = 0x40 | reg >> 8;
obuf[1] = reg & 0xff;
if (val >= 0) {
obuf[2] = val;
msg[0].len++;
}
rc = i2c_transfer(ir->dev->i2c_client.adapter, msg, 2);
if (rc < 0)
return rc;
return (rc == 2) ? 0 : -EIO;
}
static int au8522_rc_andor(struct au0828_rc *ir, u16 reg, u8 mask, u8 value)
{
int rc;
char buf, oldbuf;
rc = au8522_rc_read(ir, reg, -1, &buf, 1);
if (rc < 0)
return rc;
oldbuf = buf;
buf = (buf & ~mask) | (value & mask);
if (buf == oldbuf)
return 0;
return au8522_rc_write(ir, reg, buf);
}
static int au0828_get_key_au8522(struct au0828_rc *ir)
{
unsigned char buf[40];
DEFINE_IR_RAW_EVENT(rawir);
int i, j, rc;
int prv_bit, bit, width;
bool first = true;
rc = au8522_rc_read(ir, 0xe1, -1, buf, 1);
if (rc < 0 || !(buf[0] & (1 << 4))) {
au8522_rc_set(ir, 0xe0, 1 << 4);
return 0;
}
rc = au8522_rc_read(ir, 0xe3, 0x11, buf, sizeof(buf));
if (rc < 0)
return rc;
au8522_rc_clear(ir, 0xe0, 1 << 4);
au8522_rc_set(ir, 0xe0, 1 << 4);
dprintk(16, "RC data received: %*ph\n", 40, buf);
prv_bit = (buf[0] >> 7) & 0x01;
width = 0;
for (i = 0; i < sizeof(buf); i++) {
for (j = 7; j >= 0; j--) {
bit = (buf[i] >> j) & 0x01;
if (bit == prv_bit) {
width++;
continue;
}
if (first) {
first = false;
init_ir_raw_event(&rawir);
rawir.pulse = true;
if (width > NEC_START_SPACE - 2 &&
width < NEC_START_SPACE + 2) {
rawir.duration = NEC_START_PULSE;
dprintk(16, "Storing NEC start %s with duration %d",
rawir.pulse ? "pulse" : "space",
rawir.duration);
} else {
rawir.duration = RC5_START_PULSE;
dprintk(16, "Storing RC5 start %s with duration %d",
rawir.pulse ? "pulse" : "space",
rawir.duration);
}
ir_raw_event_store(ir->rc, &rawir);
}
init_ir_raw_event(&rawir);
rawir.pulse = prv_bit ? false : true;
rawir.duration = AU8522_UNIT * width;
dprintk(16, "Storing %s with duration %d",
rawir.pulse ? "pulse" : "space",
rawir.duration);
ir_raw_event_store(ir->rc, &rawir);
width = 1;
prv_bit = bit;
}
}
init_ir_raw_event(&rawir);
rawir.pulse = prv_bit ? false : true;
rawir.duration = AU8522_UNIT * width;
dprintk(16, "Storing end %s with duration %d",
rawir.pulse ? "pulse" : "space",
rawir.duration);
ir_raw_event_store(ir->rc, &rawir);
ir_raw_event_handle(ir->rc);
return 1;
}
static void au0828_rc_work(struct work_struct *work)
{
struct au0828_rc *ir = container_of(work, struct au0828_rc, work.work);
int rc;
rc = ir->get_key_i2c(ir);
if (rc < 0)
pr_info("Error while getting RC scancode\n");
schedule_delayed_work(&ir->work, msecs_to_jiffies(ir->polling));
}
static int au0828_rc_start(struct rc_dev *rc)
{
struct au0828_rc *ir = rc->priv;
INIT_DELAYED_WORK(&ir->work, au0828_rc_work);
au8522_rc_set(ir, 0xe0, 1 << 4);
schedule_delayed_work(&ir->work, msecs_to_jiffies(ir->polling));
return 0;
}
static void au0828_rc_stop(struct rc_dev *rc)
{
struct au0828_rc *ir = rc->priv;
cancel_delayed_work_sync(&ir->work);
au8522_rc_clear(ir, 0xe0, 1 << 4);
}
static int au0828_probe_i2c_ir(struct au0828_dev *dev)
{
int i = 0;
const unsigned short addr_list[] = {
0x47, I2C_CLIENT_END
};
while (addr_list[i] != I2C_CLIENT_END) {
if (i2c_probe_func_quick_read(dev->i2c_client.adapter,
addr_list[i]) == 1)
return addr_list[i];
i++;
}
return -ENODEV;
}
int au0828_rc_register(struct au0828_dev *dev)
{
struct au0828_rc *ir;
struct rc_dev *rc;
int err = -ENOMEM;
u16 i2c_rc_dev_addr = 0;
if (!dev->board.has_ir_i2c || disable_ir)
return 0;
i2c_rc_dev_addr = au0828_probe_i2c_ir(dev);
if (!i2c_rc_dev_addr)
return -ENODEV;
ir = kzalloc(sizeof(*ir), GFP_KERNEL);
rc = rc_allocate_device();
if (!ir || !rc)
goto error;
ir->dev = dev;
dev->ir = ir;
ir->rc = rc;
rc->priv = ir;
rc->open = au0828_rc_start;
rc->close = au0828_rc_stop;
if (dev->board.has_ir_i2c) {
switch (dev->boardnr) {
case AU0828_BOARD_HAUPPAUGE_HVR950Q:
rc->map_name = RC_MAP_HAUPPAUGE;
ir->get_key_i2c = au0828_get_key_au8522;
break;
default:
err = -ENODEV;
goto error;
}
ir->i2c_dev_addr = i2c_rc_dev_addr;
}
ir->polling = 100;
snprintf(ir->name, sizeof(ir->name), "au0828 IR (%s)",
dev->board.name);
usb_make_path(dev->usbdev, ir->phys, sizeof(ir->phys));
strlcat(ir->phys, "/input0", sizeof(ir->phys));
rc->input_name = ir->name;
rc->input_phys = ir->phys;
rc->input_id.bustype = BUS_USB;
rc->input_id.version = 1;
rc->input_id.vendor = le16_to_cpu(dev->usbdev->descriptor.idVendor);
rc->input_id.product = le16_to_cpu(dev->usbdev->descriptor.idProduct);
rc->dev.parent = &dev->usbdev->dev;
rc->driver_name = "au0828-input";
rc->driver_type = RC_DRIVER_IR_RAW;
rc->allowed_protocols = RC_BIT_NEC | RC_BIT_RC5;
err = rc_register_device(rc);
if (err)
goto error;
pr_info("Remote controller %s initalized\n", ir->name);
return 0;
error:
dev->ir = NULL;
rc_free_device(rc);
kfree(ir);
return err;
}
void au0828_rc_unregister(struct au0828_dev *dev)
{
struct au0828_rc *ir = dev->ir;
if (!ir)
return;
if (ir->rc)
rc_unregister_device(ir->rc);
kfree(ir);
dev->ir = NULL;
}
int au0828_rc_suspend(struct au0828_dev *dev)
{
struct au0828_rc *ir = dev->ir;
if (!ir)
return 0;
pr_info("Stopping RC\n");
cancel_delayed_work_sync(&ir->work);
au8522_rc_clear(ir, 0xe0, 1 << 4);
return 0;
}
int au0828_rc_resume(struct au0828_dev *dev)
{
struct au0828_rc *ir = dev->ir;
if (!ir)
return 0;
pr_info("Restarting RC\n");
au8522_rc_set(ir, 0xe0, 1 << 4);
schedule_delayed_work(&ir->work, msecs_to_jiffies(ir->polling));
return 0;
}
