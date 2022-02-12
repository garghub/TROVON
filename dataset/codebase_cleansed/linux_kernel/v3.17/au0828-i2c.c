static inline int i2c_slave_did_write_ack(struct i2c_adapter *i2c_adap)
{
struct au0828_dev *dev = i2c_adap->algo_data;
return au0828_read(dev, AU0828_I2C_STATUS_201) &
AU0828_I2C_STATUS_NO_WRITE_ACK ? 0 : 1;
}
static inline int i2c_slave_did_read_ack(struct i2c_adapter *i2c_adap)
{
struct au0828_dev *dev = i2c_adap->algo_data;
return au0828_read(dev, AU0828_I2C_STATUS_201) &
AU0828_I2C_STATUS_NO_READ_ACK ? 0 : 1;
}
static int i2c_wait_read_ack(struct i2c_adapter *i2c_adap)
{
int count;
for (count = 0; count < I2C_WAIT_RETRY; count++) {
if (!i2c_slave_did_read_ack(i2c_adap))
break;
udelay(I2C_WAIT_DELAY);
}
if (I2C_WAIT_RETRY == count)
return 0;
return 1;
}
static inline int i2c_is_read_busy(struct i2c_adapter *i2c_adap)
{
struct au0828_dev *dev = i2c_adap->algo_data;
return au0828_read(dev, AU0828_I2C_STATUS_201) &
AU0828_I2C_STATUS_READ_DONE ? 0 : 1;
}
static int i2c_wait_read_done(struct i2c_adapter *i2c_adap)
{
int count;
for (count = 0; count < I2C_WAIT_RETRY; count++) {
if (!i2c_is_read_busy(i2c_adap))
break;
udelay(I2C_WAIT_DELAY);
}
if (I2C_WAIT_RETRY == count)
return 0;
return 1;
}
static inline int i2c_is_write_done(struct i2c_adapter *i2c_adap)
{
struct au0828_dev *dev = i2c_adap->algo_data;
return au0828_read(dev, AU0828_I2C_STATUS_201) &
AU0828_I2C_STATUS_WRITE_DONE ? 1 : 0;
}
static int i2c_wait_write_done(struct i2c_adapter *i2c_adap)
{
int count;
for (count = 0; count < I2C_WAIT_RETRY; count++) {
if (i2c_is_write_done(i2c_adap))
break;
udelay(I2C_WAIT_DELAY);
}
if (I2C_WAIT_RETRY == count)
return 0;
return 1;
}
static inline int i2c_is_busy(struct i2c_adapter *i2c_adap)
{
struct au0828_dev *dev = i2c_adap->algo_data;
return au0828_read(dev, AU0828_I2C_STATUS_201) &
AU0828_I2C_STATUS_BUSY ? 1 : 0;
}
static int i2c_wait_done(struct i2c_adapter *i2c_adap)
{
int count;
for (count = 0; count < I2C_WAIT_RETRY; count++) {
if (!i2c_is_busy(i2c_adap))
break;
udelay(I2C_WAIT_DELAY);
}
if (I2C_WAIT_RETRY == count)
return 0;
return 1;
}
static int i2c_sendbytes(struct i2c_adapter *i2c_adap,
const struct i2c_msg *msg, int joined_rlen)
{
int i, strobe = 0;
struct au0828_dev *dev = i2c_adap->algo_data;
u8 i2c_speed = dev->board.i2c_clk_divider;
dprintk(4, "%s()\n", __func__);
au0828_write(dev, AU0828_I2C_MULTIBYTE_MODE_2FF, 0x01);
if (((dev->board.tuner_type == TUNER_XC5000) ||
(dev->board.tuner_type == TUNER_XC5000C)) &&
(dev->board.tuner_addr == msg->addr)) {
if (msg->len == 64)
i2c_speed = AU0828_I2C_CLK_250KHZ;
else
i2c_speed = AU0828_I2C_CLK_20KHZ;
}
au0828_write(dev, AU0828_I2C_CLK_DIVIDER_202, i2c_speed);
au0828_write(dev, AU0828_I2C_DEST_ADDR_203, msg->addr << 1);
dprintk(4, "SEND: %02x\n", msg->addr);
if (msg->len == 0) {
au0828_write(dev, AU0828_I2C_TRIGGER_200,
AU0828_I2C_TRIGGER_READ);
if (!i2c_wait_done(i2c_adap))
return -EIO;
if (i2c_wait_read_ack(i2c_adap))
return -EIO;
return 0;
}
for (i = 0; i < msg->len;) {
dprintk(4, " %02x\n", msg->buf[i]);
au0828_write(dev, AU0828_I2C_WRITE_FIFO_205, msg->buf[i]);
strobe++;
i++;
if ((strobe >= 4) || (i >= msg->len)) {
if (i < msg->len)
au0828_write(dev, AU0828_I2C_TRIGGER_200,
AU0828_I2C_TRIGGER_WRITE |
AU0828_I2C_TRIGGER_HOLD);
else
au0828_write(dev, AU0828_I2C_TRIGGER_200,
AU0828_I2C_TRIGGER_WRITE);
strobe = 0;
if (!i2c_wait_write_done(i2c_adap))
return -EIO;
}
}
if (!i2c_wait_done(i2c_adap))
return -EIO;
dprintk(4, "\n");
return msg->len;
}
static int i2c_readbytes(struct i2c_adapter *i2c_adap,
const struct i2c_msg *msg, int joined)
{
struct au0828_dev *dev = i2c_adap->algo_data;
u8 i2c_speed = dev->board.i2c_clk_divider;
int i;
dprintk(4, "%s()\n", __func__);
au0828_write(dev, AU0828_I2C_MULTIBYTE_MODE_2FF, 0x01);
if (((dev->board.tuner_type == TUNER_XC5000) ||
(dev->board.tuner_type == TUNER_XC5000C)) &&
(dev->board.tuner_addr == msg->addr))
i2c_speed = AU0828_I2C_CLK_20KHZ;
au0828_write(dev, AU0828_I2C_CLK_DIVIDER_202, i2c_speed);
au0828_write(dev, AU0828_I2C_DEST_ADDR_203, msg->addr << 1);
dprintk(4, " RECV:\n");
if (msg->len == 0) {
au0828_write(dev, AU0828_I2C_TRIGGER_200,
AU0828_I2C_TRIGGER_READ);
if (i2c_wait_read_ack(i2c_adap))
return -EIO;
return 0;
}
for (i = 0; i < msg->len;) {
i++;
if (i < msg->len)
au0828_write(dev, AU0828_I2C_TRIGGER_200,
AU0828_I2C_TRIGGER_READ |
AU0828_I2C_TRIGGER_HOLD);
else
au0828_write(dev, AU0828_I2C_TRIGGER_200,
AU0828_I2C_TRIGGER_READ);
if (!i2c_wait_read_done(i2c_adap))
return -EIO;
msg->buf[i-1] = au0828_read(dev, AU0828_I2C_READ_FIFO_209) &
0xff;
dprintk(4, " %02x\n", msg->buf[i-1]);
}
if (!i2c_wait_done(i2c_adap))
return -EIO;
dprintk(4, "\n");
return msg->len;
}
static int i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg *msgs, int num)
{
int i, retval = 0;
dprintk(4, "%s(num = %d)\n", __func__, num);
for (i = 0; i < num; i++) {
dprintk(4, "%s(num = %d) addr = 0x%02x len = 0x%x\n",
__func__, num, msgs[i].addr, msgs[i].len);
if (msgs[i].flags & I2C_M_RD) {
retval = i2c_readbytes(i2c_adap, &msgs[i], 0);
} else if (i + 1 < num && (msgs[i + 1].flags & I2C_M_RD) &&
msgs[i].addr == msgs[i + 1].addr) {
retval = i2c_sendbytes(i2c_adap, &msgs[i],
msgs[i + 1].len);
if (retval < 0)
goto err;
i++;
retval = i2c_readbytes(i2c_adap, &msgs[i], 1);
} else {
retval = i2c_sendbytes(i2c_adap, &msgs[i], 0);
}
if (retval < 0)
goto err;
}
return num;
err:
return retval;
}
static u32 au0828_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_SMBUS_EMUL | I2C_FUNC_I2C;
}
static void do_i2c_scan(char *name, struct i2c_client *c)
{
unsigned char buf;
int i, rc;
for (i = 0; i < 128; i++) {
c->addr = i;
rc = i2c_master_recv(c, &buf, 0);
if (rc < 0)
continue;
printk(KERN_INFO "%s: i2c scan: found device @ 0x%x [%s]\n",
name, i << 1, i2c_devs[i] ? i2c_devs[i] : "???");
}
}
int au0828_i2c_register(struct au0828_dev *dev)
{
dprintk(1, "%s()\n", __func__);
dev->i2c_adap = au0828_i2c_adap_template;
dev->i2c_algo = au0828_i2c_algo_template;
dev->i2c_client = au0828_i2c_client_template;
dev->i2c_adap.dev.parent = &dev->usbdev->dev;
strlcpy(dev->i2c_adap.name, DRIVER_NAME,
sizeof(dev->i2c_adap.name));
dev->i2c_adap.algo = &dev->i2c_algo;
dev->i2c_adap.algo_data = dev;
#ifdef CONFIG_VIDEO_AU0828_V4L2
i2c_set_adapdata(&dev->i2c_adap, &dev->v4l2_dev);
#else
i2c_set_adapdata(&dev->i2c_adap, dev);
#endif
i2c_add_adapter(&dev->i2c_adap);
dev->i2c_client.adapter = &dev->i2c_adap;
if (0 == dev->i2c_rc) {
printk(KERN_INFO "%s: i2c bus registered\n", DRIVER_NAME);
if (i2c_scan)
do_i2c_scan(DRIVER_NAME, &dev->i2c_client);
} else
printk(KERN_INFO "%s: i2c bus register FAILED\n", DRIVER_NAME);
return dev->i2c_rc;
}
int au0828_i2c_unregister(struct au0828_dev *dev)
{
i2c_del_adapter(&dev->i2c_adap);
return 0;
}
