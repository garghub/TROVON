static int em2800_i2c_send_bytes(struct em28xx *dev, u8 addr, u8 *buf, u16 len)
{
unsigned long timeout = jiffies + msecs_to_jiffies(EM28XX_I2C_XFER_TIMEOUT);
int ret;
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
dev_warn(&dev->intf->dev,
"failed to trigger write to i2c address 0x%x (error=%i)\n",
addr, ret);
return (ret < 0) ? ret : -EIO;
}
while (time_is_after_jiffies(timeout)) {
ret = dev->em28xx_read_reg(dev, 0x05);
if (ret == 0x80 + len - 1)
return len;
if (ret == 0x94 + len - 1) {
dprintk(1, "R05 returned 0x%02x: I2C ACK error\n", ret);
return -ENXIO;
}
if (ret < 0) {
dev_warn(&dev->intf->dev,
"failed to get i2c transfer status from bridge register (error=%i)\n",
ret);
return ret;
}
msleep(5);
}
dprintk(0, "write to i2c device at 0x%x timed out\n", addr);
return -ETIMEDOUT;
}
static int em2800_i2c_recv_bytes(struct em28xx *dev, u8 addr, u8 *buf, u16 len)
{
unsigned long timeout = jiffies + msecs_to_jiffies(EM28XX_I2C_XFER_TIMEOUT);
u8 buf2[4];
int ret;
int i;
if (len < 1 || len > 4)
return -EOPNOTSUPP;
buf2[1] = 0x84 + len - 1;
buf2[0] = addr;
ret = dev->em28xx_write_regs(dev, 0x04, buf2, 2);
if (ret != 2) {
dev_warn(&dev->intf->dev,
"failed to trigger read from i2c address 0x%x (error=%i)\n",
addr, ret);
return (ret < 0) ? ret : -EIO;
}
while (time_is_after_jiffies(timeout)) {
ret = dev->em28xx_read_reg(dev, 0x05);
if (ret == 0x84 + len - 1)
break;
if (ret == 0x94 + len - 1) {
dprintk(1, "R05 returned 0x%02x: I2C ACK error\n",
ret);
return -ENXIO;
}
if (ret < 0) {
dev_warn(&dev->intf->dev,
"failed to get i2c transfer status from bridge register (error=%i)\n",
ret);
return ret;
}
msleep(5);
}
if (ret != 0x84 + len - 1) {
dprintk(0, "read from i2c device at 0x%x timed out\n", addr);
}
ret = dev->em28xx_read_reg_req_len(dev, 0x00, 4-len, buf2, len);
if (ret != len) {
dev_warn(&dev->intf->dev,
"reading from i2c device at 0x%x failed: couldn't get the received message from the bridge (error=%i)\n",
addr, ret);
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
unsigned long timeout = jiffies + msecs_to_jiffies(EM28XX_I2C_XFER_TIMEOUT);
int ret;
if (len < 1 || len > 64)
return -EOPNOTSUPP;
ret = dev->em28xx_write_regs_req(dev, stop ? 2 : 3, addr, buf, len);
if (ret != len) {
if (ret < 0) {
dev_warn(&dev->intf->dev,
"writing to i2c device at 0x%x failed (error=%i)\n",
addr, ret);
return ret;
} else {
dev_warn(&dev->intf->dev,
"%i bytes write to i2c device at 0x%x requested, but %i bytes written\n",
len, addr, ret);
return -EIO;
}
}
while (time_is_after_jiffies(timeout)) {
ret = dev->em28xx_read_reg(dev, 0x05);
if (ret == 0)
return len;
if (ret == 0x10) {
dprintk(1, "I2C ACK error on writing to addr 0x%02x\n",
addr);
return -ENXIO;
}
if (ret < 0) {
dev_warn(&dev->intf->dev,
"failed to get i2c transfer status from bridge register (error=%i)\n",
ret);
return ret;
}
msleep(5);
}
if (ret == 0x02 || ret == 0x04) {
dprintk(0,
"write to i2c device at 0x%x timed out (status=%i)\n",
addr, ret);
return -ETIMEDOUT;
}
dev_warn(&dev->intf->dev,
"write to i2c device at 0x%x failed with unknown error (status=%i)\n",
addr, ret);
return -EIO;
}
static int em28xx_i2c_recv_bytes(struct em28xx *dev, u16 addr, u8 *buf, u16 len)
{
int ret;
if (len < 1 || len > 64)
return -EOPNOTSUPP;
ret = dev->em28xx_read_reg_req_len(dev, 2, addr, buf, len);
if (ret < 0) {
dev_warn(&dev->intf->dev,
"reading from i2c device at 0x%x failed (error=%i)\n",
addr, ret);
return ret;
}
ret = dev->em28xx_read_reg(dev, 0x05);
if (ret == 0)
return len;
if (ret < 0) {
dev_warn(&dev->intf->dev,
"failed to get i2c transfer status from bridge register (error=%i)\n",
ret);
return ret;
}
if (ret == 0x10) {
dprintk(1, "I2C ACK error on writing to addr 0x%02x\n",
addr);
return -ENXIO;
}
if (ret == 0x02 || ret == 0x04) {
dprintk(0,
"write to i2c device at 0x%x timed out (status=%i)\n",
addr, ret);
return -ETIMEDOUT;
}
dev_warn(&dev->intf->dev,
"write to i2c device at 0x%x failed with unknown error (status=%i)\n",
addr, ret);
return -EIO;
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
static int em25xx_bus_B_send_bytes(struct em28xx *dev, u16 addr, u8 *buf,
u16 len)
{
int ret;
if (len < 1 || len > 64)
return -EOPNOTSUPP;
ret = dev->em28xx_write_regs_req(dev, 0x06, addr, buf, len);
if (ret != len) {
if (ret < 0) {
dev_warn(&dev->intf->dev,
"writing to i2c device at 0x%x failed (error=%i)\n",
addr, ret);
return ret;
} else {
dev_warn(&dev->intf->dev,
"%i bytes write to i2c device at 0x%x requested, but %i bytes written\n",
len, addr, ret);
return -EIO;
}
}
ret = dev->em28xx_read_reg_req(dev, 0x08, 0x0000);
if (!ret)
return len;
else if (ret > 0) {
dprintk(1, "Bus B R08 returned 0x%02x: I2C ACK error\n", ret);
return -ENXIO;
}
return ret;
}
static int em25xx_bus_B_recv_bytes(struct em28xx *dev, u16 addr, u8 *buf,
u16 len)
{
int ret;
if (len < 1 || len > 64)
return -EOPNOTSUPP;
ret = dev->em28xx_read_reg_req_len(dev, 0x06, addr, buf, len);
if (ret < 0) {
dev_warn(&dev->intf->dev,
"reading from i2c device at 0x%x failed (error=%i)\n",
addr, ret);
return ret;
}
ret = dev->em28xx_read_reg_req(dev, 0x08, 0x0000);
if (!ret)
return len;
else if (ret > 0) {
dprintk(1, "Bus B R08 returned 0x%02x: I2C ACK error\n", ret);
return -ENXIO;
}
return ret;
}
static int em25xx_bus_B_check_for_device(struct em28xx *dev, u16 addr)
{
u8 buf;
int ret;
ret = em25xx_bus_B_recv_bytes(dev, addr, &buf, 1);
if (ret < 0)
return ret;
return 0;
}
static inline int i2c_check_for_device(struct em28xx_i2c_bus *i2c_bus, u16 addr)
{
struct em28xx *dev = i2c_bus->dev;
int rc = -EOPNOTSUPP;
if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM28XX)
rc = em28xx_i2c_check_for_device(dev, addr);
else if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM2800)
rc = em2800_i2c_check_for_device(dev, addr);
else if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM25XX_BUS_B)
rc = em25xx_bus_B_check_for_device(dev, addr);
return rc;
}
static inline int i2c_recv_bytes(struct em28xx_i2c_bus *i2c_bus,
struct i2c_msg msg)
{
struct em28xx *dev = i2c_bus->dev;
u16 addr = msg.addr << 1;
int rc = -EOPNOTSUPP;
if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM28XX)
rc = em28xx_i2c_recv_bytes(dev, addr, msg.buf, msg.len);
else if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM2800)
rc = em2800_i2c_recv_bytes(dev, addr, msg.buf, msg.len);
else if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM25XX_BUS_B)
rc = em25xx_bus_B_recv_bytes(dev, addr, msg.buf, msg.len);
return rc;
}
static inline int i2c_send_bytes(struct em28xx_i2c_bus *i2c_bus,
struct i2c_msg msg, int stop)
{
struct em28xx *dev = i2c_bus->dev;
u16 addr = msg.addr << 1;
int rc = -EOPNOTSUPP;
if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM28XX)
rc = em28xx_i2c_send_bytes(dev, addr, msg.buf, msg.len, stop);
else if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM2800)
rc = em2800_i2c_send_bytes(dev, addr, msg.buf, msg.len);
else if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM25XX_BUS_B)
rc = em25xx_bus_B_send_bytes(dev, addr, msg.buf, msg.len);
return rc;
}
static int em28xx_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg msgs[], int num)
{
struct em28xx_i2c_bus *i2c_bus = i2c_adap->algo_data;
struct em28xx *dev = i2c_bus->dev;
unsigned bus = i2c_bus->bus;
int addr, rc, i;
u8 reg;
if (dev->disconnected)
return -ENODEV;
if (!rt_mutex_trylock(&dev->i2c_bus_lock))
return -EAGAIN;
if (bus != dev->cur_i2c_bus &&
i2c_bus->algo_type == EM28XX_I2C_ALGO_EM28XX) {
if (bus == 1)
reg = EM2874_I2C_SECONDARY_BUS_SELECT;
else
reg = 0;
em28xx_write_reg_bits(dev, EM28XX_R06_I2C_CLK, reg,
EM2874_I2C_SECONDARY_BUS_SELECT);
dev->cur_i2c_bus = bus;
}
if (num <= 0) {
rt_mutex_unlock(&dev->i2c_bus_lock);
return 0;
}
for (i = 0; i < num; i++) {
addr = msgs[i].addr << 1;
if (!msgs[i].len) {
rc = i2c_check_for_device(i2c_bus, addr);
if (rc == -ENXIO)
rc = -ENODEV;
} else if (msgs[i].flags & I2C_M_RD) {
rc = i2c_recv_bytes(i2c_bus, msgs[i]);
} else {
rc = i2c_send_bytes(i2c_bus, msgs[i], i == num - 1);
}
if (rc < 0)
goto error;
dprintk(2, "%s %s addr=%02x len=%d: %*ph\n",
(msgs[i].flags & I2C_M_RD) ? "read" : "write",
i == num - 1 ? "stop" : "nonstop",
addr, msgs[i].len,
msgs[i].len, msgs[i].buf);
}
rt_mutex_unlock(&dev->i2c_bus_lock);
return num;
error:
dprintk(2, "%s %s addr=%02x len=%d: %sERROR: %i\n",
(msgs[i].flags & I2C_M_RD) ? "read" : "write",
i == num - 1 ? "stop" : "nonstop",
addr, msgs[i].len,
(rc == -ENODEV) ? "no device " : "",
rc);
rt_mutex_unlock(&dev->i2c_bus_lock);
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
static int em28xx_i2c_read_block(struct em28xx *dev, unsigned bus, u16 addr,
bool addr_w16, u16 len, u8 *data)
{
int remain = len, rsize, rsize_max, ret;
u8 buf[2];
if (addr + remain > (addr_w16 * 0xff00 + 0xff + 1))
return -EINVAL;
buf[0] = addr >> 8;
buf[1] = addr & 0xff;
ret = i2c_master_send(&dev->i2c_client[bus], buf + !addr_w16, 1 + addr_w16);
if (ret < 0)
return ret;
if (dev->board.is_em2800)
rsize_max = 4;
else
rsize_max = 64;
while (remain > 0) {
if (remain > rsize_max)
rsize = rsize_max;
else
rsize = remain;
ret = i2c_master_recv(&dev->i2c_client[bus], data, rsize);
if (ret < 0)
return ret;
remain -= rsize;
data += rsize;
}
return len;
}
static int em28xx_i2c_eeprom(struct em28xx *dev, unsigned bus,
u8 **eedata, u16 *eedata_len)
{
const u16 len = 256;
int err;
struct em28xx_eeprom *dev_config;
u8 buf, *data;
*eedata = NULL;
*eedata_len = 0;
dev->i2c_client[bus].addr = 0xa0 >> 1;
err = i2c_master_recv(&dev->i2c_client[bus], &buf, 0);
if (err < 0) {
dev_info(&dev->intf->dev, "board has no eeprom\n");
return -ENODEV;
}
data = kzalloc(len, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
err = em28xx_i2c_read_block(dev, bus, 0x0000,
dev->eeprom_addrwidth_16bit,
len, data);
if (err != len) {
dev_err(&dev->intf->dev,
"failed to read eeprom (err=%d)\n", err);
goto error;
}
if (i2c_debug) {
print_hex_dump(KERN_DEBUG, "em28xx eeprom ", DUMP_PREFIX_OFFSET,
16, 1, data, len, true);
if (dev->eeprom_addrwidth_16bit)
dev_info(&dev->intf->dev,
"eeprom %06x: ... (skipped)\n", 256);
}
if (dev->eeprom_addrwidth_16bit &&
data[0] == 0x26 && data[3] == 0x00) {
u16 mc_start;
u16 hwconf_offset;
dev->hash = em28xx_hash_mem(data, len, 32);
mc_start = (data[1] << 8) + 4;
dev_info(&dev->intf->dev,
"EEPROM ID = %02x %02x %02x %02x, EEPROM hash = 0x%08lx\n",
data[0], data[1], data[2], data[3], dev->hash);
dev_info(&dev->intf->dev,
"EEPROM info:\n");
dev_info(&dev->intf->dev,
"\tmicrocode start address = 0x%04x, boot configuration = 0x%02x\n",
mc_start, data[2]);
err = em28xx_i2c_read_block(dev, bus, mc_start + 46, 1, 2,
data);
if (err != 2) {
dev_err(&dev->intf->dev,
"failed to read hardware configuration data from eeprom (err=%d)\n",
err);
goto error;
}
hwconf_offset = mc_start + data[0] + (data[1] << 8);
err = em28xx_i2c_read_block(dev, bus, hwconf_offset, 1, len,
data);
if (err != len) {
dev_err(&dev->intf->dev,
"failed to read hardware configuration data from eeprom (err=%d)\n",
err);
goto error;
}
if (data[0] != 0x1a || data[1] != 0xeb ||
data[2] != 0x67 || data[3] != 0x95) {
dev_info(&dev->intf->dev,
"\tno hardware configuration dataset found in eeprom\n");
kfree(data);
return 0;
}
} else if (!dev->eeprom_addrwidth_16bit &&
data[0] == 0x1a && data[1] == 0xeb &&
data[2] == 0x67 && data[3] == 0x95) {
dev->hash = em28xx_hash_mem(data, len, 32);
dev_info(&dev->intf->dev,
"EEPROM ID = %02x %02x %02x %02x, EEPROM hash = 0x%08lx\n",
data[0], data[1], data[2], data[3], dev->hash);
dev_info(&dev->intf->dev,
"EEPROM info:\n");
} else {
dev_info(&dev->intf->dev,
"unknown eeprom format or eeprom corrupted !\n");
err = -ENODEV;
goto error;
}
*eedata = data;
*eedata_len = len;
dev_config = (void *)*eedata;
switch (le16_to_cpu(dev_config->chip_conf) >> 4 & 0x3) {
case 0:
dev_info(&dev->intf->dev, "\tNo audio on board.\n");
break;
case 1:
dev_info(&dev->intf->dev, "\tAC97 audio (5 sample rates)\n");
break;
case 2:
if (dev->chip_id < CHIP_ID_EM2860)
dev_info(&dev->intf->dev,
"\tI2S audio, sample rate=32k\n");
else
dev_info(&dev->intf->dev,
"\tI2S audio, 3 sample rates\n");
break;
case 3:
if (dev->chip_id < CHIP_ID_EM2860)
dev_info(&dev->intf->dev,
"\tI2S audio, 3 sample rates\n");
else
dev_info(&dev->intf->dev,
"\tI2S audio, 5 sample rates\n");
break;
}
if (le16_to_cpu(dev_config->chip_conf) & 1 << 3)
dev_info(&dev->intf->dev, "\tUSB Remote wakeup capable\n");
if (le16_to_cpu(dev_config->chip_conf) & 1 << 2)
dev_info(&dev->intf->dev, "\tUSB Self power capable\n");
switch (le16_to_cpu(dev_config->chip_conf) & 0x3) {
case 0:
dev_info(&dev->intf->dev, "\t500mA max power\n");
break;
case 1:
dev_info(&dev->intf->dev, "\t400mA max power\n");
break;
case 2:
dev_info(&dev->intf->dev, "\t300mA max power\n");
break;
case 3:
dev_info(&dev->intf->dev, "\t200mA max power\n");
break;
}
dev_info(&dev->intf->dev,
"\tTable at offset 0x%02x, strings=0x%04x, 0x%04x, 0x%04x\n",
dev_config->string_idx_table,
le16_to_cpu(dev_config->string1),
le16_to_cpu(dev_config->string2),
le16_to_cpu(dev_config->string3));
return 0;
error:
kfree(data);
return err;
}
static u32 functionality(struct i2c_adapter *i2c_adap)
{
struct em28xx_i2c_bus *i2c_bus = i2c_adap->algo_data;
if ((i2c_bus->algo_type == EM28XX_I2C_ALGO_EM28XX) ||
(i2c_bus->algo_type == EM28XX_I2C_ALGO_EM25XX_BUS_B)) {
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
} else if (i2c_bus->algo_type == EM28XX_I2C_ALGO_EM2800) {
return (I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL) &
~I2C_FUNC_SMBUS_WRITE_BLOCK_DATA;
}
WARN(1, "Unknown i2c bus algorithm.\n");
return 0;
}
void em28xx_do_i2c_scan(struct em28xx *dev, unsigned bus)
{
u8 i2c_devicelist[128];
unsigned char buf;
int i, rc;
memset(i2c_devicelist, 0, ARRAY_SIZE(i2c_devicelist));
for (i = 0; i < ARRAY_SIZE(i2c_devs); i++) {
dev->i2c_client[bus].addr = i;
rc = i2c_master_recv(&dev->i2c_client[bus], &buf, 0);
if (rc < 0)
continue;
i2c_devicelist[i] = i;
dev_info(&dev->intf->dev,
"found i2c device @ 0x%x on bus %d [%s]\n",
i << 1, bus, i2c_devs[i] ? i2c_devs[i] : "???");
}
if (bus == dev->def_i2c_bus)
dev->i2c_hash = em28xx_hash_mem(i2c_devicelist,
ARRAY_SIZE(i2c_devicelist), 32);
}
int em28xx_i2c_register(struct em28xx *dev, unsigned bus,
enum em28xx_i2c_algo_type algo_type)
{
int retval;
BUG_ON(!dev->em28xx_write_regs || !dev->em28xx_read_reg);
BUG_ON(!dev->em28xx_write_regs_req || !dev->em28xx_read_reg_req);
if (bus >= NUM_I2C_BUSES)
return -ENODEV;
dev->i2c_adap[bus] = em28xx_adap_template;
dev->i2c_adap[bus].dev.parent = &dev->intf->dev;
strcpy(dev->i2c_adap[bus].name, dev_name(&dev->intf->dev));
dev->i2c_bus[bus].bus = bus;
dev->i2c_bus[bus].algo_type = algo_type;
dev->i2c_bus[bus].dev = dev;
dev->i2c_adap[bus].algo_data = &dev->i2c_bus[bus];
retval = i2c_add_adapter(&dev->i2c_adap[bus]);
if (retval < 0) {
dev_err(&dev->intf->dev,
"%s: i2c_add_adapter failed! retval [%d]\n",
__func__, retval);
return retval;
}
dev->i2c_client[bus] = em28xx_client_template;
dev->i2c_client[bus].adapter = &dev->i2c_adap[bus];
if (!bus) {
retval = em28xx_i2c_eeprom(dev, bus, &dev->eedata, &dev->eedata_len);
if ((retval < 0) && (retval != -ENODEV)) {
dev_err(&dev->intf->dev,
"%s: em28xx_i2_eeprom failed! retval [%d]\n",
__func__, retval);
}
}
if (i2c_scan)
em28xx_do_i2c_scan(dev, bus);
return 0;
}
int em28xx_i2c_unregister(struct em28xx *dev, unsigned bus)
{
if (bus >= NUM_I2C_BUSES)
return -ENODEV;
i2c_del_adapter(&dev->i2c_adap[bus]);
return 0;
}
