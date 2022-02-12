static int tm6000_i2c_send_regs(struct tm6000_core *dev, unsigned char addr,
__u8 reg, char *buf, int len)
{
int rc;
unsigned int tsleep;
unsigned int i2c_packet_limit = 16;
if (dev->dev_type == TM6010)
i2c_packet_limit = 64;
if (!buf)
return -1;
if (len < 1 || len > i2c_packet_limit) {
printk(KERN_ERR "Incorrect length of i2c packet = %d, limit set to %d\n",
len, i2c_packet_limit);
return -1;
}
rc = tm6000_read_write_usb(dev, USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE, REQ_16_SET_GET_I2C_WR1_RDN,
addr | reg << 8, 0, buf, len);
if (rc < 0) {
return rc;
}
tsleep = ((len * 200) + 200 + 1000) / 1000;
msleep(tsleep);
return rc;
}
static int tm6000_i2c_recv_regs(struct tm6000_core *dev, unsigned char addr,
__u8 reg, char *buf, int len)
{
int rc;
u8 b[2];
unsigned int i2c_packet_limit = 16;
if (dev->dev_type == TM6010)
i2c_packet_limit = 64;
if (!buf)
return -1;
if (len < 1 || len > i2c_packet_limit) {
printk(KERN_ERR "Incorrect length of i2c packet = %d, limit set to %d\n",
len, i2c_packet_limit);
return -1;
}
if ((dev->caps.has_zl10353) && (dev->demod_addr << 1 == addr) && (reg % 2 == 0)) {
reg -= 1;
len += 1;
rc = tm6000_read_write_usb(dev, USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
REQ_16_SET_GET_I2C_WR1_RDN, addr | reg << 8, 0, b, len);
*buf = b[1];
} else {
rc = tm6000_read_write_usb(dev, USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
REQ_16_SET_GET_I2C_WR1_RDN, addr | reg << 8, 0, buf, len);
}
return rc;
}
static int tm6000_i2c_recv_regs16(struct tm6000_core *dev, unsigned char addr,
__u16 reg, char *buf, int len)
{
int rc;
unsigned char ureg;
if (!buf || len != 2)
return -1;
if (dev->dev_type == TM6010) {
ureg = reg & 0xFF;
rc = tm6000_read_write_usb(dev, USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE, REQ_16_SET_GET_I2C_WR1_RDN,
addr | (reg & 0xFF00), 0, &ureg, 1);
if (rc < 0) {
return rc;
}
msleep(1400 / 1000);
rc = tm6000_read_write_usb(dev, USB_DIR_IN | USB_TYPE_VENDOR |
USB_RECIP_DEVICE, REQ_35_AFTEK_TUNER_READ,
reg, 0, buf, len);
} else {
rc = tm6000_read_write_usb(dev, USB_DIR_IN | USB_TYPE_VENDOR |
USB_RECIP_DEVICE, REQ_14_SET_GET_I2C_WR2_RDN,
addr, reg, buf, len);
}
return rc;
}
static int tm6000_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg msgs[], int num)
{
struct tm6000_core *dev = i2c_adap->algo_data;
int addr, rc, i, byte;
if (num <= 0)
return 0;
for (i = 0; i < num; i++) {
addr = (msgs[i].addr << 1) & 0xff;
i2c_dprintk(2, "%s %s addr=0x%x len=%d:",
(msgs[i].flags & I2C_M_RD) ? "read" : "write",
i == num - 1 ? "stop" : "nonstop", addr, msgs[i].len);
if (msgs[i].flags & I2C_M_RD) {
i2c_dprintk(2, " read without preceding write not"
" supported");
rc = -EOPNOTSUPP;
goto err;
} else if (i + 1 < num && msgs[i].len <= 2 &&
(msgs[i + 1].flags & I2C_M_RD) &&
msgs[i].addr == msgs[i + 1].addr) {
if (i2c_debug >= 2)
for (byte = 0; byte < msgs[i].len; byte++)
printk(" %02x", msgs[i].buf[byte]);
i2c_dprintk(2, "; joined to read %s len=%d:",
i == num - 2 ? "stop" : "nonstop",
msgs[i + 1].len);
if (msgs[i].len == 2) {
rc = tm6000_i2c_recv_regs16(dev, addr,
msgs[i].buf[0] << 8 | msgs[i].buf[1],
msgs[i + 1].buf, msgs[i + 1].len);
} else {
rc = tm6000_i2c_recv_regs(dev, addr, msgs[i].buf[0],
msgs[i + 1].buf, msgs[i + 1].len);
}
i++;
if (addr == dev->tuner_addr << 1) {
tm6000_set_reg(dev, REQ_50_SET_START, 0, 0);
tm6000_set_reg(dev, REQ_51_SET_STOP, 0, 0);
}
if (i2c_debug >= 2)
for (byte = 0; byte < msgs[i].len; byte++)
printk(" %02x", msgs[i].buf[byte]);
} else {
if (i2c_debug >= 2)
for (byte = 0; byte < msgs[i].len; byte++)
printk(" %02x", msgs[i].buf[byte]);
rc = tm6000_i2c_send_regs(dev, addr, msgs[i].buf[0],
msgs[i].buf + 1, msgs[i].len - 1);
if (addr == dev->tuner_addr << 1) {
tm6000_set_reg(dev, REQ_50_SET_START, 0, 0);
tm6000_set_reg(dev, REQ_51_SET_STOP, 0, 0);
}
}
if (i2c_debug >= 2)
printk("\n");
if (rc < 0)
goto err;
}
return num;
err:
i2c_dprintk(2, " ERROR: %i\n", rc);
return rc;
}
static int tm6000_i2c_eeprom(struct tm6000_core *dev)
{
int i, rc;
unsigned char *p = dev->eedata;
unsigned char bytes[17];
dev->i2c_client.addr = 0xa0 >> 1;
dev->eedata_size = 0;
bytes[16] = '\0';
for (i = 0; i < sizeof(dev->eedata); ) {
*p = i;
rc = tm6000_i2c_recv_regs(dev, 0xa0, i, p, 1);
if (rc < 1) {
if (p == dev->eedata)
goto noeeprom;
else {
printk(KERN_WARNING
"%s: i2c eeprom read error (err=%d)\n",
dev->name, rc);
}
return -EINVAL;
}
dev->eedata_size++;
p++;
if (0 == (i % 16))
printk(KERN_INFO "%s: i2c eeprom %02x:", dev->name, i);
printk(" %02x", dev->eedata[i]);
if ((dev->eedata[i] >= ' ') && (dev->eedata[i] <= 'z'))
bytes[i%16] = dev->eedata[i];
else
bytes[i%16] = '.';
i++;
if (0 == (i % 16)) {
bytes[16] = '\0';
printk(" %s\n", bytes);
}
}
if (0 != (i%16)) {
bytes[i%16] = '\0';
for (i %= 16; i < 16; i++)
printk(" ");
printk(" %s\n", bytes);
}
return 0;
noeeprom:
printk(KERN_INFO "%s: Huh, no eeprom present (err=%d)?\n",
dev->name, rc);
return -EINVAL;
}
static u32 functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_SMBUS_EMUL;
}
int tm6000_i2c_register(struct tm6000_core *dev)
{
int rc;
dev->i2c_adap.owner = THIS_MODULE;
dev->i2c_adap.algo = &tm6000_algo;
dev->i2c_adap.dev.parent = &dev->udev->dev;
strlcpy(dev->i2c_adap.name, dev->name, sizeof(dev->i2c_adap.name));
dev->i2c_adap.algo_data = dev;
i2c_set_adapdata(&dev->i2c_adap, &dev->v4l2_dev);
rc = i2c_add_adapter(&dev->i2c_adap);
if (rc)
return rc;
dev->i2c_client.adapter = &dev->i2c_adap;
strlcpy(dev->i2c_client.name, "tm6000 internal", I2C_NAME_SIZE);
tm6000_i2c_eeprom(dev);
return 0;
}
int tm6000_i2c_unregister(struct tm6000_core *dev)
{
i2c_del_adapter(&dev->i2c_adap);
return 0;
}
