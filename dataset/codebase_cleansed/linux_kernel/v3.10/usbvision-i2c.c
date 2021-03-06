static inline int try_write_address(struct i2c_adapter *i2c_adap,
unsigned char addr, int retries)
{
struct usb_usbvision *usbvision;
int i, ret = -1;
char buf[4];
usbvision = (struct usb_usbvision *)i2c_get_adapdata(i2c_adap);
buf[0] = 0x00;
for (i = 0; i <= retries; i++) {
ret = (usbvision_i2c_write(usbvision, addr, buf, 1));
if (ret == 1)
break;
udelay(5);
if (i == retries)
break;
udelay(10);
}
if (i) {
PDEBUG(DBG_I2C, "Needed %d retries for address %#2x", i, addr);
PDEBUG(DBG_I2C, "Maybe there's no device at this address");
}
return ret;
}
static inline int try_read_address(struct i2c_adapter *i2c_adap,
unsigned char addr, int retries)
{
struct usb_usbvision *usbvision;
int i, ret = -1;
char buf[4];
usbvision = (struct usb_usbvision *)i2c_get_adapdata(i2c_adap);
for (i = 0; i <= retries; i++) {
ret = (usbvision_i2c_read(usbvision, addr, buf, 1));
if (ret == 1)
break;
udelay(5);
if (i == retries)
break;
udelay(10);
}
if (i) {
PDEBUG(DBG_I2C, "Needed %d retries for address %#2x", i, addr);
PDEBUG(DBG_I2C, "Maybe there's no device at this address");
}
return ret;
}
static inline int usb_find_address(struct i2c_adapter *i2c_adap,
struct i2c_msg *msg, int retries,
unsigned char *add)
{
unsigned short flags = msg->flags;
unsigned char addr;
int ret;
addr = (msg->addr << 1);
if (flags & I2C_M_RD)
addr |= 1;
add[0] = addr;
if (flags & I2C_M_RD)
ret = try_read_address(i2c_adap, addr, retries);
else
ret = try_write_address(i2c_adap, addr, retries);
if (ret != 1)
return -EREMOTEIO;
return 0;
}
static int
usbvision_i2c_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg msgs[], int num)
{
struct i2c_msg *pmsg;
struct usb_usbvision *usbvision;
int i, ret;
unsigned char addr = 0;
usbvision = (struct usb_usbvision *)i2c_get_adapdata(i2c_adap);
for (i = 0; i < num; i++) {
pmsg = &msgs[i];
ret = usb_find_address(i2c_adap, pmsg, i2c_adap->retries, &addr);
if (ret != 0) {
PDEBUG(DBG_I2C, "got NAK from device, message #%d", i);
return (ret < 0) ? ret : -EREMOTEIO;
}
if (pmsg->flags & I2C_M_RD) {
ret = (usbvision_i2c_read(usbvision, addr, pmsg->buf, pmsg->len));
if (ret < pmsg->len)
return (ret < 0) ? ret : -EREMOTEIO;
} else {
ret = (usbvision_i2c_write(usbvision, addr, pmsg->buf, pmsg->len));
if (ret < pmsg->len)
return (ret < 0) ? ret : -EREMOTEIO;
}
}
return num;
}
static u32 functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
int usbvision_i2c_register(struct usb_usbvision *usbvision)
{
static unsigned short saa711x_addrs[] = {
0x4a >> 1, 0x48 >> 1,
0x42 >> 1, 0x40 >> 1,
I2C_CLIENT_END };
if (usbvision->registered_i2c)
return 0;
usbvision->i2c_adap = i2c_adap_template;
sprintf(usbvision->i2c_adap.name, "%s-%d-%s", i2c_adap_template.name,
usbvision->dev->bus->busnum, usbvision->dev->devpath);
PDEBUG(DBG_I2C, "Adaptername: %s", usbvision->i2c_adap.name);
usbvision->i2c_adap.dev.parent = &usbvision->dev->dev;
i2c_set_adapdata(&usbvision->i2c_adap, &usbvision->v4l2_dev);
if (usbvision_write_reg(usbvision, USBVISION_SER_MODE, USBVISION_IIC_LRNACK) < 0) {
printk(KERN_ERR "usbvision_i2c_register: can't write reg\n");
return -EBUSY;
}
PDEBUG(DBG_I2C, "I2C debugging is enabled [i2c]");
PDEBUG(DBG_I2C, "ALGO debugging is enabled [i2c]");
usbvision->i2c_adap.algo = &usbvision_algo;
usbvision->i2c_adap.timeout = 100;
usbvision->i2c_adap.retries = 3;
i2c_add_adapter(&usbvision->i2c_adap);
PDEBUG(DBG_I2C, "i2c bus for %s registered", usbvision->i2c_adap.name);
switch (usbvision_device_data[usbvision->dev_model].codec) {
case CODEC_SAA7113:
case CODEC_SAA7111:
mdelay(10);
v4l2_i2c_new_subdev(&usbvision->v4l2_dev,
&usbvision->i2c_adap,
"saa7115_auto", 0, saa711x_addrs);
break;
}
if (usbvision_device_data[usbvision->dev_model].tuner == 1) {
struct v4l2_subdev *sd;
enum v4l2_i2c_tuner_type type;
struct tuner_setup tun_setup;
sd = v4l2_i2c_new_subdev(&usbvision->v4l2_dev,
&usbvision->i2c_adap,
"tuner", 0, v4l2_i2c_tuner_addrs(ADDRS_DEMOD));
type = sd ? ADDRS_TV_WITH_DEMOD : ADDRS_TV;
sd = v4l2_i2c_new_subdev(&usbvision->v4l2_dev,
&usbvision->i2c_adap,
"tuner", 0, v4l2_i2c_tuner_addrs(type));
if (sd == NULL)
return -ENODEV;
if (usbvision->tuner_type != -1) {
tun_setup.mode_mask = T_ANALOG_TV | T_RADIO;
tun_setup.type = usbvision->tuner_type;
tun_setup.addr = v4l2_i2c_subdev_addr(sd);
call_all(usbvision, tuner, s_type_addr, &tun_setup);
}
}
usbvision->registered_i2c = 1;
return 0;
}
int usbvision_i2c_unregister(struct usb_usbvision *usbvision)
{
if (!usbvision->registered_i2c)
return 0;
i2c_del_adapter(&(usbvision->i2c_adap));
usbvision->registered_i2c = 0;
PDEBUG(DBG_I2C, "i2c bus for %s unregistered", usbvision->i2c_adap.name);
return 0;
}
static int
usbvision_i2c_read_max4(struct usb_usbvision *usbvision, unsigned char addr,
char *buf, short len)
{
int rc, retries;
for (retries = 5;;) {
rc = usbvision_write_reg(usbvision, USBVISION_SER_ADRS, addr);
if (rc < 0)
return rc;
rc = usbvision_write_reg(usbvision, USBVISION_SER_CONT,
(len & 0x07) | 0x18);
if (rc < 0)
return rc;
do {
rc = usbvision_read_reg(usbvision, USBVISION_SER_CONT);
} while (rc > 0 && ((rc & 0x10) != 0));
if (rc < 0)
return rc;
if ((rc & 0x20) == 0)
break;
rc = usbvision_write_reg(usbvision, USBVISION_SER_CONT, 0x00);
if (rc < 0)
return rc;
if (--retries < 0)
return -1;
}
switch (len) {
case 4:
buf[3] = usbvision_read_reg(usbvision, USBVISION_SER_DAT4);
case 3:
buf[2] = usbvision_read_reg(usbvision, USBVISION_SER_DAT3);
case 2:
buf[1] = usbvision_read_reg(usbvision, USBVISION_SER_DAT2);
case 1:
buf[0] = usbvision_read_reg(usbvision, USBVISION_SER_DAT1);
break;
default:
printk(KERN_ERR
"usbvision_i2c_read_max4: buffer length > 4\n");
}
if (i2c_debug & DBG_I2C) {
int idx;
for (idx = 0; idx < len; idx++)
PDEBUG(DBG_I2C, "read %x from address %x", (unsigned char)buf[idx], addr);
}
return len;
}
static int usbvision_i2c_write_max4(struct usb_usbvision *usbvision,
unsigned char addr, const char *buf,
short len)
{
int rc, retries;
int i;
unsigned char value[6];
unsigned char ser_cont;
ser_cont = (len & 0x07) | 0x10;
value[0] = addr;
value[1] = ser_cont;
for (i = 0; i < len; i++)
value[i + 2] = buf[i];
for (retries = 5;;) {
rc = usb_control_msg(usbvision->dev,
usb_sndctrlpipe(usbvision->dev, 1),
USBVISION_OP_CODE,
USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_ENDPOINT, 0,
(__u16) USBVISION_SER_ADRS, value,
len + 2, HZ);
if (rc < 0)
return rc;
rc = usbvision_write_reg(usbvision, USBVISION_SER_CONT,
(len & 0x07) | 0x10);
if (rc < 0)
return rc;
do {
rc = usbvision_read_reg(usbvision, USBVISION_SER_CONT);
} while (rc > 0 && ((rc & 0x10) != 0));
if (rc < 0)
return rc;
if ((rc & 0x20) == 0)
break;
usbvision_write_reg(usbvision, USBVISION_SER_CONT, 0x00);
if (--retries < 0)
return -1;
}
if (i2c_debug & DBG_I2C) {
int idx;
for (idx = 0; idx < len; idx++)
PDEBUG(DBG_I2C, "wrote %x at address %x", (unsigned char)buf[idx], addr);
}
return len;
}
static int usbvision_i2c_write(struct usb_usbvision *usbvision, unsigned char addr, char *buf,
short len)
{
char *buf_ptr = buf;
int retval;
int wrcount = 0;
int count;
int max_len = 4;
while (len > 0) {
count = (len > max_len) ? max_len : len;
retval = usbvision_i2c_write_max4(usbvision, addr, buf_ptr, count);
if (retval > 0) {
len -= count;
buf_ptr += count;
wrcount += count;
} else
return (retval < 0) ? retval : -EFAULT;
}
return wrcount;
}
static int usbvision_i2c_read(struct usb_usbvision *usbvision, unsigned char addr, char *buf,
short len)
{
char temp[4];
int retval, i;
int rdcount = 0;
int count;
while (len > 0) {
count = (len > 3) ? 4 : len;
retval = usbvision_i2c_read_max4(usbvision, addr, temp, count);
if (retval > 0) {
for (i = 0; i < len; i++)
buf[rdcount + i] = temp[i];
len -= count;
rdcount += count;
} else
return (retval < 0) ? retval : -EFAULT;
}
return rdcount;
}
