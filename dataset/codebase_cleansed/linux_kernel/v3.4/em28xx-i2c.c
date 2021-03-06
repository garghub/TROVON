static int em2800_i2c_send_max4(struct em28xx *dev, unsigned char addr,
char *buf, int len)
{
int ret;
int write_timeout;
unsigned char b2[6];
BUG_ON(len < 1 || len > 4);
b2[5] = 0x80 + len - 1;
b2[4] = addr;
b2[3] = buf[0];
if (len > 1)
b2[2] = buf[1];
if (len > 2)
b2[1] = buf[2];
if (len > 3)
b2[0] = buf[3];
ret = dev->em28xx_write_regs(dev, 4 - len, &b2[4 - len], 2 + len);
if (ret != 2 + len) {
em28xx_warn("writing to i2c device failed (error=%i)\n", ret);
return -EIO;
}
for (write_timeout = EM2800_I2C_WRITE_TIMEOUT; write_timeout > 0;
write_timeout -= 5) {
ret = dev->em28xx_read_reg(dev, 0x05);
if (ret == 0x80 + len - 1)
return len;
msleep(5);
}
em28xx_warn("i2c write timed out\n");
return -EIO;
}
static int em2800_i2c_send_bytes(void *data, unsigned char addr, char *buf,
short len)
{
char *bufPtr = buf;
int ret;
int wrcount = 0;
int count;
int maxLen = 4;
struct em28xx *dev = (struct em28xx *)data;
while (len > 0) {
count = (len > maxLen) ? maxLen : len;
ret = em2800_i2c_send_max4(dev, addr, bufPtr, count);
if (ret > 0) {
len -= count;
bufPtr += count;
wrcount += count;
} else
return (ret < 0) ? ret : -EFAULT;
}
return wrcount;
}
static int em2800_i2c_check_for_device(struct em28xx *dev, unsigned char addr)
{
char msg;
int ret;
int write_timeout;
msg = addr;
ret = dev->em28xx_write_regs(dev, 0x04, &msg, 1);
if (ret < 0) {
em28xx_warn("setting i2c device address failed (error=%i)\n",
ret);
return ret;
}
msg = 0x84;
ret = dev->em28xx_write_regs(dev, 0x05, &msg, 1);
if (ret < 0) {
em28xx_warn("preparing i2c read failed (error=%i)\n", ret);
return ret;
}
for (write_timeout = EM2800_I2C_WRITE_TIMEOUT; write_timeout > 0;
write_timeout -= 5) {
unsigned reg = dev->em28xx_read_reg(dev, 0x5);
if (reg == 0x94)
return -ENODEV;
else if (reg == 0x84)
return 0;
msleep(5);
}
return -ENODEV;
}
static int em2800_i2c_recv_bytes(struct em28xx *dev, unsigned char addr,
char *buf, int len)
{
int ret;
ret = em2800_i2c_check_for_device(dev, addr);
if (ret) {
em28xx_warn
("preparing read at i2c address 0x%x failed (error=%i)\n",
addr, ret);
return ret;
}
ret = dev->em28xx_read_reg_req_len(dev, 0x0, 0x3, buf, len);
if (ret < 0) {
em28xx_warn("reading from i2c device at 0x%x failed (error=%i)",
addr, ret);
return ret;
}
return ret;
}
static int em28xx_i2c_send_bytes(void *data, unsigned char addr, char *buf,
short len, int stop)
{
int wrcount = 0;
struct em28xx *dev = (struct em28xx *)data;
int write_timeout, ret;
wrcount = dev->em28xx_write_regs_req(dev, stop ? 2 : 3, addr, buf, len);
for (write_timeout = EM2800_I2C_WRITE_TIMEOUT; write_timeout > 0;
write_timeout -= 5) {
ret = dev->em28xx_read_reg(dev, 0x05);
if (!ret)
break;
msleep(5);
}
return wrcount;
}
static int em28xx_i2c_recv_bytes(struct em28xx *dev, unsigned char addr,
char *buf, int len)
{
int ret;
ret = dev->em28xx_read_reg_req_len(dev, 2, addr, buf, len);
if (ret < 0) {
em28xx_warn("reading i2c device failed (error=%i)\n", ret);
return ret;
}
if (dev->em28xx_read_reg(dev, 0x5) != 0)
return -ENODEV;
return ret;
}
static int em28xx_i2c_check_for_device(struct em28xx *dev, unsigned char addr)
{
int ret;
ret = dev->em28xx_read_reg_req(dev, 2, addr);
if (ret < 0) {
em28xx_warn("reading from i2c device failed (error=%i)\n", ret);
return ret;
}
if (dev->em28xx_read_reg(dev, 0x5) != 0)
return -ENODEV;
return 0;
}
static int em28xx_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg msgs[], int num)
{
struct em28xx *dev = i2c_adap->algo_data;
int addr, rc, i, byte;
if (num <= 0)
return 0;
for (i = 0; i < num; i++) {
addr = msgs[i].addr << 1;
dprintk2(2, "%s %s addr=%x len=%d:",
(msgs[i].flags & I2C_M_RD) ? "read" : "write",
i == num - 1 ? "stop" : "nonstop", addr, msgs[i].len);
if (!msgs[i].len) {
if (dev->board.is_em2800)
rc = em2800_i2c_check_for_device(dev, addr);
else
rc = em28xx_i2c_check_for_device(dev, addr);
if (rc < 0) {
dprintk2(2, " no device\n");
return rc;
}
} else if (msgs[i].flags & I2C_M_RD) {
if (dev->board.is_em2800)
rc = em2800_i2c_recv_bytes(dev, addr,
msgs[i].buf,
msgs[i].len);
else
rc = em28xx_i2c_recv_bytes(dev, addr,
msgs[i].buf,
msgs[i].len);
if (i2c_debug >= 2) {
for (byte = 0; byte < msgs[i].len; byte++)
printk(" %02x", msgs[i].buf[byte]);
}
} else {
if (i2c_debug >= 2) {
for (byte = 0; byte < msgs[i].len; byte++)
printk(" %02x", msgs[i].buf[byte]);
}
if (dev->board.is_em2800)
rc = em2800_i2c_send_bytes(dev, addr,
msgs[i].buf,
msgs[i].len);
else
rc = em28xx_i2c_send_bytes(dev, addr,
msgs[i].buf,
msgs[i].len,
i == num - 1);
}
if (rc < 0)
goto err;
if (i2c_debug >= 2)
printk("\n");
}
return num;
err:
dprintk2(2, " ERROR: %i\n", rc);
return rc;
}
static inline unsigned long em28xx_hash_mem(char *buf, int length, int bits)
{
unsigned long hash = 0;
unsigned long l = 0;
int len = 0;
unsigned char c;
do {
if (len == length) {
c = (char)len;
len = -1;
} else
c = *buf++;
l = (l << 8) | c;
len++;
if ((len & (32 / 8 - 1)) == 0)
hash = ((hash^l) * 0x9e370001UL);
} while (len);
return (hash >> (32 - bits)) & 0xffffffffUL;
}
static int em28xx_i2c_eeprom(struct em28xx *dev, unsigned char *eedata, int len)
{
unsigned char buf, *p = eedata;
struct em28xx_eeprom *em_eeprom = (void *)eedata;
int i, err, size = len, block;
if (dev->chip_id == CHIP_ID_EM2874 ||
dev->chip_id == CHIP_ID_EM28174 ||
dev->chip_id == CHIP_ID_EM2884) {
return 0;
}
dev->i2c_client.addr = 0xa0 >> 1;
err = i2c_master_recv(&dev->i2c_client, &buf, 0);
if (err < 0) {
em28xx_errdev("board has no eeprom\n");
memset(eedata, 0, len);
return -ENODEV;
}
buf = 0;
err = i2c_master_send(&dev->i2c_client, &buf, 1);
if (err != 1) {
printk(KERN_INFO "%s: Huh, no eeprom present (err=%d)?\n",
dev->name, err);
return err;
}
while (size > 0) {
if (size > 16)
block = 16;
else
block = size;
if (block !=
(err = i2c_master_recv(&dev->i2c_client, p, block))) {
printk(KERN_WARNING
"%s: i2c eeprom read error (err=%d)\n",
dev->name, err);
return err;
}
size -= block;
p += block;
}
for (i = 0; i < len; i++) {
if (0 == (i % 16))
printk(KERN_INFO "%s: i2c eeprom %02x:", dev->name, i);
printk(" %02x", eedata[i]);
if (15 == (i % 16))
printk("\n");
}
if (em_eeprom->id == 0x9567eb1a)
dev->hash = em28xx_hash_mem(eedata, len, 32);
printk(KERN_INFO "%s: EEPROM ID= 0x%08x, EEPROM hash = 0x%08lx\n",
dev->name, em_eeprom->id, dev->hash);
printk(KERN_INFO "%s: EEPROM info:\n", dev->name);
switch (em_eeprom->chip_conf >> 4 & 0x3) {
case 0:
printk(KERN_INFO "%s:\tNo audio on board.\n", dev->name);
break;
case 1:
printk(KERN_INFO "%s:\tAC97 audio (5 sample rates)\n",
dev->name);
break;
case 2:
printk(KERN_INFO "%s:\tI2S audio, sample rate=32k\n",
dev->name);
break;
case 3:
printk(KERN_INFO "%s:\tI2S audio, 3 sample rates\n",
dev->name);
break;
}
if (em_eeprom->chip_conf & 1 << 3)
printk(KERN_INFO "%s:\tUSB Remote wakeup capable\n", dev->name);
if (em_eeprom->chip_conf & 1 << 2)
printk(KERN_INFO "%s:\tUSB Self power capable\n", dev->name);
switch (em_eeprom->chip_conf & 0x3) {
case 0:
printk(KERN_INFO "%s:\t500mA max power\n", dev->name);
break;
case 1:
printk(KERN_INFO "%s:\t400mA max power\n", dev->name);
break;
case 2:
printk(KERN_INFO "%s:\t300mA max power\n", dev->name);
break;
case 3:
printk(KERN_INFO "%s:\t200mA max power\n", dev->name);
break;
}
printk(KERN_INFO "%s:\tTable at 0x%02x, strings=0x%04x, 0x%04x, 0x%04x\n",
dev->name,
em_eeprom->string_idx_table,
em_eeprom->string1,
em_eeprom->string2,
em_eeprom->string3);
return 0;
}
static u32 functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_SMBUS_EMUL;
}
void em28xx_do_i2c_scan(struct em28xx *dev)
{
u8 i2c_devicelist[128];
unsigned char buf;
int i, rc;
memset(i2c_devicelist, 0, ARRAY_SIZE(i2c_devicelist));
for (i = 0; i < ARRAY_SIZE(i2c_devs); i++) {
dev->i2c_client.addr = i;
rc = i2c_master_recv(&dev->i2c_client, &buf, 0);
if (rc < 0)
continue;
i2c_devicelist[i] = i;
printk(KERN_INFO "%s: found i2c device @ 0x%x [%s]\n",
dev->name, i << 1, i2c_devs[i] ? i2c_devs[i] : "???");
}
dev->i2c_hash = em28xx_hash_mem(i2c_devicelist,
ARRAY_SIZE(i2c_devicelist), 32);
}
int em28xx_i2c_register(struct em28xx *dev)
{
int retval;
BUG_ON(!dev->em28xx_write_regs || !dev->em28xx_read_reg);
BUG_ON(!dev->em28xx_write_regs_req || !dev->em28xx_read_reg_req);
dev->i2c_adap = em28xx_adap_template;
dev->i2c_adap.dev.parent = &dev->udev->dev;
strcpy(dev->i2c_adap.name, dev->name);
dev->i2c_adap.algo_data = dev;
i2c_set_adapdata(&dev->i2c_adap, &dev->v4l2_dev);
retval = i2c_add_adapter(&dev->i2c_adap);
if (retval < 0) {
em28xx_errdev("%s: i2c_add_adapter failed! retval [%d]\n",
__func__, retval);
return retval;
}
dev->i2c_client = em28xx_client_template;
dev->i2c_client.adapter = &dev->i2c_adap;
retval = em28xx_i2c_eeprom(dev, dev->eedata, sizeof(dev->eedata));
if ((retval < 0) && (retval != -ENODEV)) {
em28xx_errdev("%s: em28xx_i2_eeprom failed! retval [%d]\n",
__func__, retval);
return retval;
}
if (i2c_scan)
em28xx_do_i2c_scan(dev);
em28xx_register_i2c_ir(dev);
return 0;
}
int em28xx_i2c_unregister(struct em28xx *dev)
{
i2c_del_adapter(&dev->i2c_adap);
return 0;
}
