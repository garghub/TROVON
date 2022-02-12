static int em2800_i2c_send_bytes(struct em28xx *dev, u8 addr, u8 *buf, u16 len)
{
int ret;
int write_timeout;
u8 b2[6];
if (len < 1 || len > 4)
return -EOPNOTSUPP;
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
em28xx_warn("failed to trigger write to i2c address 0x%x "
"(error=%i)\n", addr, ret);
return (ret < 0) ? ret : -EIO;
}
for (write_timeout = EM2800_I2C_XFER_TIMEOUT; write_timeout > 0;
write_timeout -= 5) {
ret = dev->em28xx_read_reg(dev, 0x05);
if (ret == 0x80 + len - 1) {
return len;
} else if (ret == 0x94 + len - 1) {
return -ENODEV;
} else if (ret < 0) {
em28xx_warn("failed to get i2c transfer status from "
"bridge register (error=%i)\n", ret);
return ret;
}
msleep(5);
}
em28xx_warn("write to i2c device at 0x%x timed out\n", addr);
return -EIO;
}
static int em2800_i2c_recv_bytes(struct em28xx *dev, u8 addr, u8 *buf, u16 len)
{
u8 buf2[4];
int ret;
int read_timeout;
int i;
if (len < 1 || len > 4)
return -EOPNOTSUPP;
buf2[1] = 0x84 + len - 1;
buf2[0] = addr;
ret = dev->em28xx_write_regs(dev, 0x04, buf2, 2);
if (ret != 2) {
em28xx_warn("failed to trigger read from i2c address 0x%x "
"(error=%i)\n", addr, ret);
return (ret < 0) ? ret : -EIO;
}
for (read_timeout = EM2800_I2C_XFER_TIMEOUT; read_timeout > 0;
read_timeout -= 5) {
ret = dev->em28xx_read_reg(dev, 0x05);
if (ret == 0x84 + len - 1) {
break;
} else if (ret == 0x94 + len - 1) {
return -ENODEV;
} else if (ret < 0) {
em28xx_warn("failed to get i2c transfer status from "
"bridge register (error=%i)\n", ret);
return ret;
}
msleep(5);
}
if (ret != 0x84 + len - 1)
em28xx_warn("read from i2c device at 0x%x timed out\n", addr);
ret = dev->em28xx_read_reg_req_len(dev, 0x00, 4-len, buf2, len);
if (ret != len) {
em28xx_warn("reading from i2c device at 0x%x failed: "
"couldn't get the received message from the bridge "
"(error=%i)\n", addr, ret);
return (ret < 0) ? ret : -EIO;
}
for (i = 0; i < len; i++)
buf[i] = buf2[len - 1 - i];
return ret;
}
static int em2800_i2c_check_for_device(struct em28xx *dev, u8 addr)
{
u8 buf;
int ret;
ret = em2800_i2c_recv_bytes(dev, addr, &buf, 1);
if (ret == 1)
return 0;
return (ret < 0) ? ret : -EIO;
}
static int em28xx_i2c_send_bytes(struct em28xx *dev, u16 addr, u8 *buf,
u16 len, int stop)
{
int write_timeout, ret;
if (len < 1 || len > 64)
return -EOPNOTSUPP;
ret = dev->em28xx_write_regs_req(dev, stop ? 2 : 3, addr, buf, len);
if (ret != len) {
if (ret < 0) {
em28xx_warn("writing to i2c device at 0x%x failed "
"(error=%i)\n", addr, ret);
return ret;
} else {
em28xx_warn("%i bytes write to i2c device at 0x%x "
"requested, but %i bytes written\n",
len, addr, ret);
return -EIO;
}
}
for (write_timeout = EM2800_I2C_XFER_TIMEOUT; write_timeout > 0;
write_timeout -= 5) {
ret = dev->em28xx_read_reg(dev, 0x05);
if (ret == 0) {
return len;
} else if (ret == 0x10) {
return -ENODEV;
} else if (ret < 0) {
em28xx_warn("failed to read i2c transfer status from "
"bridge (error=%i)\n", ret);
return ret;
}
msleep(5);
}
em28xx_warn("write to i2c device at 0x%x timed out\n", addr);
return -EIO;
}
static int em28xx_i2c_recv_bytes(struct em28xx *dev, u16 addr, u8 *buf, u16 len)
{
int ret;
if (len < 1 || len > 64)
return -EOPNOTSUPP;
ret = dev->em28xx_read_reg_req_len(dev, 2, addr, buf, len);
if (ret != len) {
if (ret < 0) {
em28xx_warn("reading from i2c device at 0x%x failed "
"(error=%i)\n", addr, ret);
return ret;
} else {
em28xx_warn("%i bytes requested from i2c device at "
"0x%x, but %i bytes received\n",
len, addr, ret);
return -EIO;
}
}
ret = dev->em28xx_read_reg(dev, 0x05);
if (ret < 0) {
em28xx_warn("failed to read i2c transfer status from "
"bridge (error=%i)\n", ret);
return ret;
}
if (ret > 0) {
if (ret == 0x10) {
return -ENODEV;
} else {
em28xx_warn("unknown i2c error (status=%i)\n", ret);
return -EIO;
}
}
return len;
}
static int em28xx_i2c_check_for_device(struct em28xx *dev, u16 addr)
{
int ret;
u8 buf;
ret = em28xx_i2c_recv_bytes(dev, addr, &buf, 1);
if (ret == 1)
return 0;
return (ret < 0) ? ret : -EIO;
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
if (rc == -ENODEV) {
if (i2c_debug >= 2)
printk(" no device\n");
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
if (rc < 0) {
if (i2c_debug >= 2)
printk(" ERROR: %i\n", rc);
return rc;
}
if (i2c_debug >= 2)
printk("\n");
}
return num;
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
int i, err, size = len, block, block_max;
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
if (dev->board.is_em2800)
block_max = 4;
else
block_max = 64;
while (size > 0) {
if (size > block_max)
block = block_max;
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
struct em28xx *dev = adap->algo_data;
u32 func_flags = I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
if (dev->board.is_em2800)
func_flags &= ~I2C_FUNC_SMBUS_WRITE_BLOCK_DATA;
return func_flags;
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
return 0;
}
int em28xx_i2c_unregister(struct em28xx *dev)
{
i2c_del_adapter(&dev->i2c_adap);
return 0;
}
