static int af9015_rw_udev(struct usb_device *udev, struct req_t *req)
{
#define BUF_LEN 63
#define REQ_HDR_LEN 8
#define ACK_HDR_LEN 2
int act_len, ret;
u8 buf[BUF_LEN];
u8 write = 1;
u8 msg_len = REQ_HDR_LEN;
static u8 seq;
if (mutex_lock_interruptible(&af9015_usb_mutex) < 0)
return -EAGAIN;
buf[0] = req->cmd;
buf[1] = seq++;
buf[2] = req->i2c_addr;
buf[3] = req->addr >> 8;
buf[4] = req->addr & 0xff;
buf[5] = req->mbox;
buf[6] = req->addr_len;
buf[7] = req->data_len;
switch (req->cmd) {
case GET_CONFIG:
case READ_MEMORY:
case RECONNECT_USB:
write = 0;
break;
case READ_I2C:
write = 0;
buf[2] |= 0x01;
case WRITE_I2C:
buf[0] = READ_WRITE_I2C;
break;
case WRITE_MEMORY:
if (((req->addr & 0xff00) == 0xff00) ||
((req->addr & 0xff00) == 0xae00))
buf[0] = WRITE_VIRTUAL_MEMORY;
case WRITE_VIRTUAL_MEMORY:
case COPY_FIRMWARE:
case DOWNLOAD_FIRMWARE:
case BOOT:
break;
default:
err("unknown command:%d", req->cmd);
ret = -1;
goto error_unlock;
}
if ((write && (req->data_len > BUF_LEN - REQ_HDR_LEN)) ||
(!write && (req->data_len > BUF_LEN - ACK_HDR_LEN))) {
err("too much data; cmd:%d len:%d", req->cmd, req->data_len);
ret = -EINVAL;
goto error_unlock;
}
if (write) {
memcpy(&buf[REQ_HDR_LEN], req->data, req->data_len);
msg_len += req->data_len;
}
deb_xfer(">>> ");
debug_dump(buf, msg_len, deb_xfer);
ret = usb_bulk_msg(udev, usb_sndbulkpipe(udev, 0x02), buf, msg_len,
&act_len, AF9015_USB_TIMEOUT);
if (ret)
err("bulk message failed:%d (%d/%d)", ret, msg_len, act_len);
else
if (act_len != msg_len)
ret = -1;
if (ret)
goto error_unlock;
if (req->cmd == DOWNLOAD_FIRMWARE || req->cmd == RECONNECT_USB)
goto exit_unlock;
msg_len = ACK_HDR_LEN;
if (!write)
msg_len += req->data_len;
ret = usb_bulk_msg(udev, usb_rcvbulkpipe(udev, 0x81), buf, msg_len,
&act_len, AF9015_USB_TIMEOUT);
if (ret) {
err("recv bulk message failed:%d", ret);
ret = -1;
goto error_unlock;
}
deb_xfer("<<< ");
debug_dump(buf, act_len, deb_xfer);
if (buf[1]) {
err("command failed:%d", buf[1]);
ret = -1;
goto error_unlock;
}
if (!write)
memcpy(req->data, &buf[ACK_HDR_LEN], req->data_len);
error_unlock:
exit_unlock:
mutex_unlock(&af9015_usb_mutex);
return ret;
}
static int af9015_ctrl_msg(struct dvb_usb_device *d, struct req_t *req)
{
return af9015_rw_udev(d->udev, req);
}
static int af9015_write_regs(struct dvb_usb_device *d, u16 addr, u8 *val,
u8 len)
{
struct req_t req = {WRITE_MEMORY, AF9015_I2C_DEMOD, addr, 0, 0, len,
val};
return af9015_ctrl_msg(d, &req);
}
static int af9015_write_reg(struct dvb_usb_device *d, u16 addr, u8 val)
{
return af9015_write_regs(d, addr, &val, 1);
}
static int af9015_read_regs(struct dvb_usb_device *d, u16 addr, u8 *val, u8 len)
{
struct req_t req = {READ_MEMORY, AF9015_I2C_DEMOD, addr, 0, 0, len,
val};
return af9015_ctrl_msg(d, &req);
}
static int af9015_read_reg(struct dvb_usb_device *d, u16 addr, u8 *val)
{
return af9015_read_regs(d, addr, val, 1);
}
static int af9015_write_reg_i2c(struct dvb_usb_device *d, u8 addr, u16 reg,
u8 val)
{
struct req_t req = {WRITE_I2C, addr, reg, 1, 1, 1, &val};
if (addr == af9015_af9013_config[0].i2c_addr ||
addr == af9015_af9013_config[1].i2c_addr)
req.addr_len = 3;
return af9015_ctrl_msg(d, &req);
}
static int af9015_read_reg_i2c(struct dvb_usb_device *d, u8 addr, u16 reg,
u8 *val)
{
struct req_t req = {READ_I2C, addr, reg, 0, 1, 1, val};
if (addr == af9015_af9013_config[0].i2c_addr ||
addr == af9015_af9013_config[1].i2c_addr)
req.addr_len = 3;
return af9015_ctrl_msg(d, &req);
}
static int af9015_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int ret = 0, i = 0;
u16 addr;
u8 uninitialized_var(mbox), addr_len;
struct req_t req;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
while (i < num) {
if (msg[i].addr == af9015_af9013_config[0].i2c_addr ||
msg[i].addr == af9015_af9013_config[1].i2c_addr) {
addr = msg[i].buf[0] << 8;
addr += msg[i].buf[1];
mbox = msg[i].buf[2];
addr_len = 3;
} else {
addr = msg[i].buf[0];
addr_len = 1;
}
if (num > i + 1 && (msg[i+1].flags & I2C_M_RD)) {
if (msg[i].len > 3 || msg[i+1].len > 61) {
ret = -EOPNOTSUPP;
goto error;
}
if (msg[i].addr == af9015_af9013_config[0].i2c_addr)
req.cmd = READ_MEMORY;
else
req.cmd = READ_I2C;
req.i2c_addr = msg[i].addr;
req.addr = addr;
req.mbox = mbox;
req.addr_len = addr_len;
req.data_len = msg[i+1].len;
req.data = &msg[i+1].buf[0];
ret = af9015_ctrl_msg(d, &req);
i += 2;
} else if (msg[i].flags & I2C_M_RD) {
if (msg[i].len > 61) {
ret = -EOPNOTSUPP;
goto error;
}
if (msg[i].addr ==
af9015_af9013_config[0].i2c_addr) {
ret = -EINVAL;
goto error;
}
req.cmd = READ_I2C;
req.i2c_addr = msg[i].addr;
req.addr = addr;
req.mbox = mbox;
req.addr_len = addr_len;
req.data_len = msg[i].len;
req.data = &msg[i].buf[0];
ret = af9015_ctrl_msg(d, &req);
i += 1;
} else {
if (msg[i].len > 21) {
ret = -EOPNOTSUPP;
goto error;
}
if (msg[i].addr == af9015_af9013_config[0].i2c_addr)
req.cmd = WRITE_MEMORY;
else
req.cmd = WRITE_I2C;
req.i2c_addr = msg[i].addr;
req.addr = addr;
req.mbox = mbox;
req.addr_len = addr_len;
req.data_len = msg[i].len-addr_len;
req.data = &msg[i].buf[addr_len];
ret = af9015_ctrl_msg(d, &req);
i += 1;
}
if (ret)
goto error;
}
ret = i;
error:
mutex_unlock(&d->i2c_mutex);
return ret;
}
static u32 af9015_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int af9015_do_reg_bit(struct dvb_usb_device *d, u16 addr, u8 bit, u8 op)
{
int ret;
u8 val, mask = 0x01;
ret = af9015_read_reg(d, addr, &val);
if (ret)
return ret;
mask <<= bit;
if (op) {
val |= mask;
} else {
mask ^= 0xff;
val &= mask;
}
return af9015_write_reg(d, addr, val);
}
static int af9015_set_reg_bit(struct dvb_usb_device *d, u16 addr, u8 bit)
{
return af9015_do_reg_bit(d, addr, bit, 1);
}
static int af9015_clear_reg_bit(struct dvb_usb_device *d, u16 addr, u8 bit)
{
return af9015_do_reg_bit(d, addr, bit, 0);
}
static int af9015_init_endpoint(struct dvb_usb_device *d)
{
int ret;
u16 frame_size;
u8 packet_size;
deb_info("%s: USB speed:%d\n", __func__, d->udev->speed);
#define TS_PACKET_SIZE 188
#define TS_USB20_PACKET_COUNT 87
#define TS_USB20_FRAME_SIZE (TS_PACKET_SIZE*TS_USB20_PACKET_COUNT)
#define TS_USB11_PACKET_COUNT 5
#define TS_USB11_FRAME_SIZE (TS_PACKET_SIZE*TS_USB11_PACKET_COUNT)
#define TS_USB20_MAX_PACKET_SIZE 512
#define TS_USB11_MAX_PACKET_SIZE 64
if (d->udev->speed == USB_SPEED_FULL) {
frame_size = TS_USB11_FRAME_SIZE/4;
packet_size = TS_USB11_MAX_PACKET_SIZE/4;
} else {
frame_size = TS_USB20_FRAME_SIZE/4;
packet_size = TS_USB20_MAX_PACKET_SIZE/4;
}
ret = af9015_set_reg_bit(d, 0xd507, 2);
if (ret)
goto error;
ret = af9015_set_reg_bit(d, 0xd50b, 1);
if (ret)
goto error;
ret = af9015_clear_reg_bit(d, 0xdd11, 5);
if (ret)
goto error;
ret = af9015_clear_reg_bit(d, 0xdd11, 6);
if (ret)
goto error;
ret = af9015_set_reg_bit(d, 0xdd11, 5);
if (ret)
goto error;
if (af9015_config.dual_mode) {
ret = af9015_set_reg_bit(d, 0xdd11, 6);
if (ret)
goto error;
}
ret = af9015_clear_reg_bit(d, 0xdd13, 5);
if (ret)
goto error;
if (af9015_config.dual_mode) {
ret = af9015_clear_reg_bit(d, 0xdd13, 6);
if (ret)
goto error;
}
ret = af9015_write_reg(d, 0xdd88, frame_size & 0xff);
if (ret)
goto error;
ret = af9015_write_reg(d, 0xdd89, frame_size >> 8);
if (ret)
goto error;
ret = af9015_write_reg(d, 0xdd8a, frame_size & 0xff);
if (ret)
goto error;
ret = af9015_write_reg(d, 0xdd8b, frame_size >> 8);
if (ret)
goto error;
ret = af9015_write_reg(d, 0xdd0c, packet_size);
if (ret)
goto error;
ret = af9015_write_reg(d, 0xdd0d, packet_size);
if (ret)
goto error;
ret = af9015_clear_reg_bit(d, 0xd507, 2);
if (ret)
goto error;
if (af9015_config.dual_mode) {
ret = af9015_clear_reg_bit(d, 0xd50b, 1);
if (ret)
goto error;
}
if (af9015_config.dual_mode)
ret = af9015_set_reg_bit(d, 0xd50b, 0);
else
ret = af9015_clear_reg_bit(d, 0xd50b, 0);
error:
if (ret)
err("endpoint init failed:%d", ret);
return ret;
}
static int af9015_copy_firmware(struct dvb_usb_device *d)
{
int ret;
u8 fw_params[4];
u8 val, i;
struct req_t req = {COPY_FIRMWARE, 0, 0x5100, 0, 0, sizeof(fw_params),
fw_params };
deb_info("%s:\n", __func__);
fw_params[0] = af9015_config.firmware_size >> 8;
fw_params[1] = af9015_config.firmware_size & 0xff;
fw_params[2] = af9015_config.firmware_checksum >> 8;
fw_params[3] = af9015_config.firmware_checksum & 0xff;
msleep(100);
ret = af9015_read_reg_i2c(d,
af9015_af9013_config[1].i2c_addr, 0x98be, &val);
if (ret)
goto error;
else
deb_info("%s: firmware status:%02x\n", __func__, val);
if (val == 0x0c)
goto exit;
ret = af9015_write_reg(d, 0xd416, 0x04);
if (ret)
goto error;
msleep(50);
ret = af9015_ctrl_msg(d, &req);
if (ret)
err("firmware copy cmd failed:%d", ret);
deb_info("%s: firmware copy done\n", __func__);
ret = af9015_write_reg(d, 0xd416, 0x14);
if (ret)
goto error;
ret = af9015_write_reg_i2c(d, af9015_af9013_config[1].i2c_addr,
0xe205, 1);
deb_info("%s: firmware boot cmd status:%d\n", __func__, ret);
if (ret)
goto error;
for (i = 0; i < 15; i++) {
msleep(100);
ret = af9015_read_reg_i2c(d,
af9015_af9013_config[1].i2c_addr, 0x98be, &val);
deb_info("%s: firmware status cmd status:%d fw status:%02x\n",
__func__, ret, val);
if (ret)
goto error;
if (val == 0x0c || val == 0x04)
break;
}
if (val == 0x04) {
err("firmware did not run");
ret = -1;
} else if (val != 0x0c) {
err("firmware boot timeout");
ret = -1;
}
error:
exit:
return ret;
}
static int af9015_eeprom_hash(struct usb_device *udev)
{
static const unsigned int eeprom_size = 256;
unsigned int reg;
int ret;
u8 val, *eeprom;
struct req_t req = {READ_I2C, AF9015_I2C_EEPROM, 0, 0, 1, 1, &val};
eeprom = kmalloc(eeprom_size, GFP_KERNEL);
if (eeprom == NULL)
return -ENOMEM;
for (reg = 0; reg < eeprom_size; reg++) {
req.addr = reg;
ret = af9015_rw_udev(udev, &req);
if (ret)
goto free;
eeprom[reg] = val;
}
if (dvb_usb_af9015_debug & 0x01)
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, eeprom,
eeprom_size);
BUG_ON(eeprom_size % 4);
af9015_config.eeprom_sum = 0;
for (reg = 0; reg < eeprom_size / sizeof(u32); reg++) {
af9015_config.eeprom_sum *= GOLDEN_RATIO_PRIME_32;
af9015_config.eeprom_sum += le32_to_cpu(((u32 *)eeprom)[reg]);
}
deb_info("%s: eeprom sum=%.8x\n", __func__, af9015_config.eeprom_sum);
ret = 0;
free:
kfree(eeprom);
return ret;
}
static int af9015_init(struct dvb_usb_device *d)
{
int ret;
deb_info("%s:\n", __func__);
ret = af9015_write_reg(d, 0x98e9, 0xff);
if (ret)
goto error;
ret = af9015_init_endpoint(d);
if (ret)
goto error;
error:
return ret;
}
static int af9015_pid_filter_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
int ret;
deb_info("%s: onoff:%d\n", __func__, onoff);
if (onoff)
ret = af9015_set_reg_bit(adap->dev, 0xd503, 0);
else
ret = af9015_clear_reg_bit(adap->dev, 0xd503, 0);
return ret;
}
static int af9015_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid,
int onoff)
{
int ret;
u8 idx;
deb_info("%s: set pid filter, index %d, pid %x, onoff %d\n",
__func__, index, pid, onoff);
ret = af9015_write_reg(adap->dev, 0xd505, (pid & 0xff));
if (ret)
goto error;
ret = af9015_write_reg(adap->dev, 0xd506, (pid >> 8));
if (ret)
goto error;
idx = ((index & 0x1f) | (1 << 5));
ret = af9015_write_reg(adap->dev, 0xd504, idx);
error:
return ret;
}
static int af9015_download_firmware(struct usb_device *udev,
const struct firmware *fw)
{
int i, len, remaining, ret;
struct req_t req = {DOWNLOAD_FIRMWARE, 0, 0, 0, 0, 0, NULL};
u16 checksum = 0;
deb_info("%s:\n", __func__);
for (i = 0; i < fw->size; i++)
checksum += fw->data[i];
af9015_config.firmware_size = fw->size;
af9015_config.firmware_checksum = checksum;
#define FW_ADDR 0x5100
#define LEN_MAX 55
for (remaining = fw->size; remaining > 0; remaining -= LEN_MAX) {
len = remaining;
if (len > LEN_MAX)
len = LEN_MAX;
req.data_len = len;
req.data = (u8 *) &fw->data[fw->size - remaining];
req.addr = FW_ADDR + fw->size - remaining;
ret = af9015_rw_udev(udev, &req);
if (ret) {
err("firmware download failed:%d", ret);
goto error;
}
}
req.cmd = BOOT;
ret = af9015_rw_udev(udev, &req);
if (ret) {
err("firmware boot failed:%d", ret);
goto error;
}
error:
return ret;
}
static char *af9015_rc_setup_match(unsigned int id,
const struct af9015_rc_setup *table)
{
for (; table->rc_codes; table++)
if (table->id == id)
return table->rc_codes;
return NULL;
}
static void af9015_set_remote_config(struct usb_device *udev,
struct dvb_usb_device_properties *props)
{
u16 vid = le16_to_cpu(udev->descriptor.idVendor);
u16 pid = le16_to_cpu(udev->descriptor.idProduct);
props->rc.core.rc_codes = af9015_rc_setup_match(
dvb_usb_af9015_remote, af9015_rc_setup_modparam);
if (!props->rc.core.rc_codes)
props->rc.core.rc_codes = af9015_rc_setup_match(
af9015_config.eeprom_sum, af9015_rc_setup_hashes);
if (!props->rc.core.rc_codes)
props->rc.core.rc_codes = af9015_rc_setup_match(
(vid << 16) + pid, af9015_rc_setup_usbids);
if (!props->rc.core.rc_codes && vid == USB_VID_AFATECH) {
char manufacturer[10];
memset(manufacturer, 0, sizeof(manufacturer));
usb_string(udev, udev->descriptor.iManufacturer,
manufacturer, sizeof(manufacturer));
if (!strcmp("MSI", manufacturer)) {
props->rc.core.rc_codes = af9015_rc_setup_match(
AF9015_REMOTE_MSI_DIGIVOX_MINI_II_V3,
af9015_rc_setup_modparam);
}
}
if (!props->rc.core.rc_codes)
props->rc.core.rc_codes = RC_MAP_EMPTY;
return;
}
static int af9015_read_config(struct usb_device *udev)
{
int ret;
u8 val, i, offset = 0;
struct req_t req = {READ_I2C, AF9015_I2C_EEPROM, 0, 0, 1, 1, &val};
req.addr = AF9015_EEPROM_IR_MODE;
for (i = 0; i < 4; i++) {
ret = af9015_rw_udev(udev, &req);
if (!ret)
break;
}
if (ret)
goto error;
ret = af9015_eeprom_hash(udev);
if (ret)
goto error;
deb_info("%s: IR mode=%d\n", __func__, val);
for (i = 0; i < af9015_properties_count; i++) {
if (val == AF9015_IR_MODE_DISABLED)
af9015_properties[i].rc.core.rc_codes = NULL;
else
af9015_set_remote_config(udev, &af9015_properties[i]);
}
req.addr = AF9015_EEPROM_TS_MODE;
ret = af9015_rw_udev(udev, &req);
if (ret)
goto error;
af9015_config.dual_mode = val;
deb_info("%s: TS mode=%d\n", __func__, af9015_config.dual_mode);
for (i = 0; i < af9015_properties_count; i++) {
if (udev->speed == USB_SPEED_FULL) {
af9015_properties[i].adapter[0].fe[0].stream.u.bulk.buffersize
= TS_USB11_FRAME_SIZE;
af9015_config.dual_mode = 0;
} else {
af9015_properties[i].adapter[0].fe[0].stream.u.bulk.buffersize
= TS_USB20_FRAME_SIZE;
}
}
if (af9015_config.dual_mode) {
req.addr = AF9015_EEPROM_DEMOD2_I2C;
ret = af9015_rw_udev(udev, &req);
if (ret)
goto error;
af9015_af9013_config[1].i2c_addr = val;
for (i = 0; i < af9015_properties_count; i++)
af9015_properties[i].num_adapters = 2;
} else {
for (i = 0; i < af9015_properties_count; i++)
af9015_properties[i].num_adapters = 1;
}
for (i = 0; i < af9015_properties[0].num_adapters; i++) {
if (i == 1)
offset = AF9015_EEPROM_OFFSET;
req.addr = AF9015_EEPROM_XTAL_TYPE1 + offset;
ret = af9015_rw_udev(udev, &req);
if (ret)
goto error;
switch (val) {
case 0:
af9015_af9013_config[i].clock = 28800000;
break;
case 1:
af9015_af9013_config[i].clock = 20480000;
break;
case 2:
af9015_af9013_config[i].clock = 28000000;
break;
case 3:
af9015_af9013_config[i].clock = 25000000;
break;
};
deb_info("%s: [%d] xtal=%d set clock=%d\n", __func__, i,
val, af9015_af9013_config[i].clock);
req.addr = AF9015_EEPROM_IF1H + offset;
ret = af9015_rw_udev(udev, &req);
if (ret)
goto error;
af9015_af9013_config[i].if_frequency = val << 8;
req.addr = AF9015_EEPROM_IF1L + offset;
ret = af9015_rw_udev(udev, &req);
if (ret)
goto error;
af9015_af9013_config[i].if_frequency += val;
af9015_af9013_config[i].if_frequency *= 1000;
deb_info("%s: [%d] IF frequency=%d\n", __func__, i,
af9015_af9013_config[0].if_frequency);
req.addr = AF9015_EEPROM_MT2060_IF1H + offset;
ret = af9015_rw_udev(udev, &req);
if (ret)
goto error;
af9015_config.mt2060_if1[i] = val << 8;
req.addr = AF9015_EEPROM_MT2060_IF1L + offset;
ret = af9015_rw_udev(udev, &req);
if (ret)
goto error;
af9015_config.mt2060_if1[i] += val;
deb_info("%s: [%d] MT2060 IF1=%d\n", __func__, i,
af9015_config.mt2060_if1[i]);
req.addr = AF9015_EEPROM_TUNER_ID1 + offset;
ret = af9015_rw_udev(udev, &req);
if (ret)
goto error;
switch (val) {
case AF9013_TUNER_ENV77H11D5:
case AF9013_TUNER_MT2060:
case AF9013_TUNER_QT1010:
case AF9013_TUNER_UNKNOWN:
case AF9013_TUNER_MT2060_2:
case AF9013_TUNER_TDA18271:
case AF9013_TUNER_QT1010A:
case AF9013_TUNER_TDA18218:
af9015_af9013_config[i].spec_inv = 1;
break;
case AF9013_TUNER_MXL5003D:
case AF9013_TUNER_MXL5005D:
case AF9013_TUNER_MXL5005R:
case AF9013_TUNER_MXL5007T:
af9015_af9013_config[i].spec_inv = 0;
break;
case AF9013_TUNER_MC44S803:
af9015_af9013_config[i].gpio[1] = AF9013_GPIO_LO;
af9015_af9013_config[i].spec_inv = 1;
break;
default:
warn("tuner id=%d not supported, please report!", val);
return -ENODEV;
};
af9015_af9013_config[i].tuner = val;
deb_info("%s: [%d] tuner id=%d\n", __func__, i, val);
}
error:
if (ret)
err("eeprom read failed=%d", ret);
if (le16_to_cpu(udev->descriptor.idVendor) == USB_VID_AVERMEDIA &&
((le16_to_cpu(udev->descriptor.idProduct) ==
USB_PID_AVERMEDIA_A850) ||
(le16_to_cpu(udev->descriptor.idProduct) ==
USB_PID_AVERMEDIA_A850T))) {
deb_info("%s: AverMedia A850: overriding config\n", __func__);
af9015_config.dual_mode = 0;
for (i = 0; i < af9015_properties_count; i++)
af9015_properties[i].num_adapters = 1;
af9015_af9013_config[0].if_frequency = 4570000;
}
return ret;
}
static int af9015_identify_state(struct usb_device *udev,
struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc,
int *cold)
{
int ret;
u8 reply;
struct req_t req = {GET_CONFIG, 0, 0, 0, 0, 1, &reply};
ret = af9015_rw_udev(udev, &req);
if (ret)
return ret;
deb_info("%s: reply:%02x\n", __func__, reply);
if (reply == 0x02)
*cold = 0;
else
*cold = 1;
return ret;
}
static int af9015_rc_query(struct dvb_usb_device *d)
{
struct af9015_state *priv = d->priv;
int ret;
u8 buf[17];
ret = af9015_read_regs(d, 0x98d9, buf, sizeof(buf));
if (ret)
goto error;
if (buf[1] || buf[2] || buf[3])
return ret;
if ((priv->rc_repeat != buf[6] || buf[0]) &&
!memcmp(&buf[12], priv->rc_last, 4)) {
deb_rc("%s: key repeated\n", __func__);
rc_keydown(d->rc_dev, priv->rc_keycode, 0);
priv->rc_repeat = buf[6];
return ret;
}
if (buf[16] != 0xff && buf[0] != 0x01) {
deb_rc("%s: key pressed %02x %02x %02x %02x\n", __func__,
buf[12], buf[13], buf[14], buf[15]);
ret = af9015_write_reg(d, 0x98e9, 0xff);
if (ret)
goto error;
memcpy(priv->rc_last, &buf[12], 4);
if (buf[14] == (u8) ~buf[15]) {
if (buf[12] == (u8) ~buf[13]) {
priv->rc_keycode = buf[12] << 8 | buf[14];
} else {
priv->rc_keycode = buf[12] << 16 |
buf[13] << 8 | buf[14];
}
} else {
priv->rc_keycode = buf[12] << 24 | buf[13] << 16 |
buf[14] << 8 | buf[15];
}
rc_keydown(d->rc_dev, priv->rc_keycode, 0);
} else {
deb_rc("%s: no key press\n", __func__);
priv->rc_last[2] = priv->rc_last[3];
}
priv->rc_repeat = buf[6];
error:
if (ret)
err("%s: failed:%d", __func__, ret);
return ret;
}
static int af9015_af9013_set_frontend(struct dvb_frontend *fe)
{
int ret;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct af9015_state *priv = adap->dev->priv;
if (mutex_lock_interruptible(&adap->dev->usb_mutex))
return -EAGAIN;
ret = priv->set_frontend[adap->id](fe);
mutex_unlock(&adap->dev->usb_mutex);
return ret;
}
static int af9015_af9013_read_status(struct dvb_frontend *fe,
fe_status_t *status)
{
int ret;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct af9015_state *priv = adap->dev->priv;
if (mutex_lock_interruptible(&adap->dev->usb_mutex))
return -EAGAIN;
ret = priv->read_status[adap->id](fe, status);
mutex_unlock(&adap->dev->usb_mutex);
return ret;
}
static int af9015_af9013_init(struct dvb_frontend *fe)
{
int ret;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct af9015_state *priv = adap->dev->priv;
if (mutex_lock_interruptible(&adap->dev->usb_mutex))
return -EAGAIN;
ret = priv->init[adap->id](fe);
mutex_unlock(&adap->dev->usb_mutex);
return ret;
}
static int af9015_af9013_sleep(struct dvb_frontend *fe)
{
int ret;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct af9015_state *priv = adap->dev->priv;
if (mutex_lock_interruptible(&adap->dev->usb_mutex))
return -EAGAIN;
ret = priv->sleep[adap->id](fe);
mutex_unlock(&adap->dev->usb_mutex);
return ret;
}
static int af9015_tuner_init(struct dvb_frontend *fe)
{
int ret;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct af9015_state *priv = adap->dev->priv;
if (mutex_lock_interruptible(&adap->dev->usb_mutex))
return -EAGAIN;
ret = priv->tuner_init[adap->id](fe);
mutex_unlock(&adap->dev->usb_mutex);
return ret;
}
static int af9015_tuner_sleep(struct dvb_frontend *fe)
{
int ret;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct af9015_state *priv = adap->dev->priv;
if (mutex_lock_interruptible(&adap->dev->usb_mutex))
return -EAGAIN;
ret = priv->tuner_sleep[adap->id](fe);
mutex_unlock(&adap->dev->usb_mutex);
return ret;
}
static int af9015_af9013_frontend_attach(struct dvb_usb_adapter *adap)
{
int ret;
struct af9015_state *state = adap->dev->priv;
if (adap->id == 1) {
if (af9015_config.dual_mode) {
ret = af9015_copy_firmware(adap->dev);
if (ret) {
err("firmware copy to 2nd frontend " \
"failed, will disable it");
af9015_config.dual_mode = 0;
return -ENODEV;
}
} else {
return -ENODEV;
}
}
adap->fe_adap[0].fe = dvb_attach(af9013_attach, &af9015_af9013_config[adap->id],
&adap->dev->i2c_adap);
if (adap->fe_adap[0].fe) {
state->set_frontend[adap->id] =
adap->fe_adap[0].fe->ops.set_frontend;
adap->fe_adap[0].fe->ops.set_frontend =
af9015_af9013_set_frontend;
state->read_status[adap->id] =
adap->fe_adap[0].fe->ops.read_status;
adap->fe_adap[0].fe->ops.read_status =
af9015_af9013_read_status;
state->init[adap->id] = adap->fe_adap[0].fe->ops.init;
adap->fe_adap[0].fe->ops.init = af9015_af9013_init;
state->sleep[adap->id] = adap->fe_adap[0].fe->ops.sleep;
adap->fe_adap[0].fe->ops.sleep = af9015_af9013_sleep;
}
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int af9015_tuner_attach(struct dvb_usb_adapter *adap)
{
int ret;
struct af9015_state *state = adap->dev->priv;
deb_info("%s:\n", __func__);
switch (af9015_af9013_config[adap->id].tuner) {
case AF9013_TUNER_MT2060:
case AF9013_TUNER_MT2060_2:
ret = dvb_attach(mt2060_attach, adap->fe_adap[0].fe, &adap->dev->i2c_adap,
&af9015_mt2060_config,
af9015_config.mt2060_if1[adap->id])
== NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_QT1010:
case AF9013_TUNER_QT1010A:
ret = dvb_attach(qt1010_attach, adap->fe_adap[0].fe, &adap->dev->i2c_adap,
&af9015_qt1010_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_TDA18271:
ret = dvb_attach(tda18271_attach, adap->fe_adap[0].fe, 0xc0,
&adap->dev->i2c_adap,
&af9015_tda18271_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_TDA18218:
ret = dvb_attach(tda18218_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap,
&af9015_tda18218_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_MXL5003D:
ret = dvb_attach(mxl5005s_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap,
&af9015_mxl5003_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_MXL5005D:
case AF9013_TUNER_MXL5005R:
ret = dvb_attach(mxl5005s_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap,
&af9015_mxl5005_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_ENV77H11D5:
ret = dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0xc0,
&adap->dev->i2c_adap,
DVB_PLL_TDA665X) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_MC44S803:
ret = dvb_attach(mc44s803_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap,
&af9015_mc44s803_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_MXL5007T:
ret = dvb_attach(mxl5007t_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap,
0xc0, &af9015_mxl5007t_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_UNKNOWN:
default:
ret = -ENODEV;
err("Unknown tuner id:%d",
af9015_af9013_config[adap->id].tuner);
}
if (adap->fe_adap[0].fe->ops.tuner_ops.init) {
state->tuner_init[adap->id] =
adap->fe_adap[0].fe->ops.tuner_ops.init;
adap->fe_adap[0].fe->ops.tuner_ops.init = af9015_tuner_init;
}
if (adap->fe_adap[0].fe->ops.tuner_ops.sleep) {
state->tuner_sleep[adap->id] =
adap->fe_adap[0].fe->ops.tuner_ops.sleep;
adap->fe_adap[0].fe->ops.tuner_ops.sleep = af9015_tuner_sleep;
}
return ret;
}
static int af9015_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int ret = 0;
struct dvb_usb_device *d = NULL;
struct usb_device *udev = interface_to_usbdev(intf);
u8 i;
deb_info("%s: interface:%d\n", __func__,
intf->cur_altsetting->desc.bInterfaceNumber);
if (intf->cur_altsetting->desc.bInterfaceNumber == 0) {
ret = af9015_read_config(udev);
if (ret)
return ret;
for (i = 0; i < af9015_properties_count; i++) {
ret = dvb_usb_device_init(intf, &af9015_properties[i],
THIS_MODULE, &d, adapter_nr);
if (!ret)
break;
if (ret != -ENODEV)
return ret;
}
if (ret)
return ret;
if (d)
ret = af9015_init(d);
}
return ret;
}
