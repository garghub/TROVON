static int af9015_ctrl_msg(struct dvb_usb_device *d, struct req_t *req)
{
#define REQ_HDR_LEN 8
#define ACK_HDR_LEN 2
struct af9015_state *state = d_to_priv(d);
int ret, wlen, rlen;
u8 write = 1;
mutex_lock(&d->usb_mutex);
state->buf[0] = req->cmd;
state->buf[1] = state->seq++;
state->buf[2] = req->i2c_addr;
state->buf[3] = req->addr >> 8;
state->buf[4] = req->addr & 0xff;
state->buf[5] = req->mbox;
state->buf[6] = req->addr_len;
state->buf[7] = req->data_len;
switch (req->cmd) {
case GET_CONFIG:
case READ_MEMORY:
case RECONNECT_USB:
write = 0;
break;
case READ_I2C:
write = 0;
state->buf[2] |= 0x01;
case WRITE_I2C:
state->buf[0] = READ_WRITE_I2C;
break;
case WRITE_MEMORY:
if (((req->addr & 0xff00) == 0xff00) ||
((req->addr & 0xff00) == 0xae00))
state->buf[0] = WRITE_VIRTUAL_MEMORY;
case WRITE_VIRTUAL_MEMORY:
case COPY_FIRMWARE:
case DOWNLOAD_FIRMWARE:
case BOOT:
break;
default:
dev_err(&d->udev->dev, "%s: unknown command=%d\n",
KBUILD_MODNAME, req->cmd);
ret = -EIO;
goto error;
}
if ((write && (req->data_len > BUF_LEN - REQ_HDR_LEN)) ||
(!write && (req->data_len > BUF_LEN - ACK_HDR_LEN))) {
dev_err(&d->udev->dev, "%s: too much data; cmd=%d len=%d\n",
KBUILD_MODNAME, req->cmd, req->data_len);
ret = -EINVAL;
goto error;
}
wlen = REQ_HDR_LEN;
rlen = ACK_HDR_LEN;
if (write) {
wlen += req->data_len;
memcpy(&state->buf[REQ_HDR_LEN], req->data, req->data_len);
} else {
rlen += req->data_len;
}
if (req->cmd == DOWNLOAD_FIRMWARE || req->cmd == RECONNECT_USB)
rlen = 0;
ret = dvb_usbv2_generic_rw_locked(d,
state->buf, wlen, state->buf, rlen);
if (ret)
goto error;
if (rlen && state->buf[1]) {
dev_err(&d->udev->dev, "%s: command failed=%d\n",
KBUILD_MODNAME, state->buf[1]);
ret = -EIO;
goto error;
}
if (!write)
memcpy(req->data, &state->buf[ACK_HDR_LEN], req->data_len);
error:
mutex_unlock(&d->usb_mutex);
return ret;
}
static int af9015_write_regs(struct dvb_usb_device *d, u16 addr, u8 *val,
u8 len)
{
struct req_t req = {WRITE_MEMORY, AF9015_I2C_DEMOD, addr, 0, 0, len,
val};
return af9015_ctrl_msg(d, &req);
}
static int af9015_read_regs(struct dvb_usb_device *d, u16 addr, u8 *val, u8 len)
{
struct req_t req = {READ_MEMORY, AF9015_I2C_DEMOD, addr, 0, 0, len,
val};
return af9015_ctrl_msg(d, &req);
}
static int af9015_write_reg(struct dvb_usb_device *d, u16 addr, u8 val)
{
return af9015_write_regs(d, addr, &val, 1);
}
static int af9015_read_reg(struct dvb_usb_device *d, u16 addr, u8 *val)
{
return af9015_read_regs(d, addr, val, 1);
}
static int af9015_write_reg_i2c(struct dvb_usb_device *d, u8 addr, u16 reg,
u8 val)
{
struct af9015_state *state = d_to_priv(d);
struct req_t req = {WRITE_I2C, addr, reg, 1, 1, 1, &val};
if (addr == state->af9013_config[0].i2c_addr ||
addr == state->af9013_config[1].i2c_addr)
req.addr_len = 3;
return af9015_ctrl_msg(d, &req);
}
static int af9015_read_reg_i2c(struct dvb_usb_device *d, u8 addr, u16 reg,
u8 *val)
{
struct af9015_state *state = d_to_priv(d);
struct req_t req = {READ_I2C, addr, reg, 0, 1, 1, val};
if (addr == state->af9013_config[0].i2c_addr ||
addr == state->af9013_config[1].i2c_addr)
req.addr_len = 3;
return af9015_ctrl_msg(d, &req);
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
static int af9015_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
struct af9015_state *state = d_to_priv(d);
int ret = 0, i = 0;
u16 addr;
u8 uninitialized_var(mbox), addr_len;
struct req_t req;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
while (i < num) {
if (msg[i].addr == state->af9013_config[0].i2c_addr ||
msg[i].addr == state->af9013_config[1].i2c_addr) {
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
if (msg[i].addr == state->af9013_config[0].i2c_addr)
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
if (msg[i].addr == state->af9013_config[0].i2c_addr) {
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
if (msg[i].addr == state->af9013_config[0].i2c_addr)
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
static int af9015_identify_state(struct dvb_usb_device *d, const char **name)
{
int ret;
u8 reply;
struct req_t req = {GET_CONFIG, 0, 0, 0, 0, 1, &reply};
ret = af9015_ctrl_msg(d, &req);
if (ret)
return ret;
dev_dbg(&d->udev->dev, "%s: reply=%02x\n", __func__, reply);
if (reply == 0x02)
ret = WARM;
else
ret = COLD;
return ret;
}
static int af9015_download_firmware(struct dvb_usb_device *d,
const struct firmware *fw)
{
struct af9015_state *state = d_to_priv(d);
int i, len, remaining, ret;
struct req_t req = {DOWNLOAD_FIRMWARE, 0, 0, 0, 0, 0, NULL};
u16 checksum = 0;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
for (i = 0; i < fw->size; i++)
checksum += fw->data[i];
state->firmware_size = fw->size;
state->firmware_checksum = checksum;
#define FW_ADDR 0x5100
#define LEN_MAX 55
for (remaining = fw->size; remaining > 0; remaining -= LEN_MAX) {
len = remaining;
if (len > LEN_MAX)
len = LEN_MAX;
req.data_len = len;
req.data = (u8 *) &fw->data[fw->size - remaining];
req.addr = FW_ADDR + fw->size - remaining;
ret = af9015_ctrl_msg(d, &req);
if (ret) {
dev_err(&d->udev->dev,
"%s: firmware download failed=%d\n",
KBUILD_MODNAME, ret);
goto error;
}
}
req.cmd = BOOT;
req.data_len = 0;
ret = af9015_ctrl_msg(d, &req);
if (ret) {
dev_err(&d->udev->dev, "%s: firmware boot failed=%d\n",
KBUILD_MODNAME, ret);
goto error;
}
error:
return ret;
}
static int af9015_eeprom_hash(struct dvb_usb_device *d)
{
struct af9015_state *state = d_to_priv(d);
int ret, i;
u8 buf[AF9015_EEPROM_SIZE];
struct req_t req = {READ_I2C, AF9015_I2C_EEPROM, 0, 0, 1, 1, NULL};
for (i = 0; i < AF9015_EEPROM_SIZE; i++) {
req.addr = i;
req.data = &buf[i];
ret = af9015_ctrl_msg(d, &req);
if (ret < 0)
goto err;
}
for (i = 0; i < AF9015_EEPROM_SIZE / sizeof(u32); i++) {
state->eeprom_sum *= GOLDEN_RATIO_PRIME_32;
state->eeprom_sum += le32_to_cpu(((u32 *)buf)[i]);
}
for (i = 0; i < AF9015_EEPROM_SIZE; i += 16)
dev_dbg(&d->udev->dev, "%s: %*ph\n", __func__, 16, buf + i);
dev_dbg(&d->udev->dev, "%s: eeprom sum=%.8x\n",
__func__, state->eeprom_sum);
return 0;
err:
dev_err(&d->udev->dev, "%s: eeprom failed=%d\n", KBUILD_MODNAME, ret);
return ret;
}
static int af9015_read_config(struct dvb_usb_device *d)
{
struct af9015_state *state = d_to_priv(d);
int ret;
u8 val, i, offset = 0;
struct req_t req = {READ_I2C, AF9015_I2C_EEPROM, 0, 0, 1, 1, &val};
dev_dbg(&d->udev->dev, "%s:\n", __func__);
req.addr = AF9015_EEPROM_IR_MODE;
for (i = 0; i < 4; i++) {
ret = af9015_ctrl_msg(d, &req);
if (!ret)
break;
}
if (ret)
goto error;
ret = af9015_eeprom_hash(d);
if (ret)
goto error;
state->ir_mode = val;
dev_dbg(&d->udev->dev, "%s: IR mode=%d\n", __func__, val);
req.addr = AF9015_EEPROM_TS_MODE;
ret = af9015_ctrl_msg(d, &req);
if (ret)
goto error;
state->dual_mode = val;
dev_dbg(&d->udev->dev, "%s: TS mode=%d\n", __func__, state->dual_mode);
if (d->udev->speed == USB_SPEED_FULL)
state->dual_mode = 0;
if (state->dual_mode) {
req.addr = AF9015_EEPROM_DEMOD2_I2C;
ret = af9015_ctrl_msg(d, &req);
if (ret)
goto error;
state->af9013_config[1].i2c_addr = val;
}
for (i = 0; i < state->dual_mode + 1; i++) {
if (i == 1)
offset = AF9015_EEPROM_OFFSET;
req.addr = AF9015_EEPROM_XTAL_TYPE1 + offset;
ret = af9015_ctrl_msg(d, &req);
if (ret)
goto error;
switch (val) {
case 0:
state->af9013_config[i].clock = 28800000;
break;
case 1:
state->af9013_config[i].clock = 20480000;
break;
case 2:
state->af9013_config[i].clock = 28000000;
break;
case 3:
state->af9013_config[i].clock = 25000000;
break;
}
dev_dbg(&d->udev->dev, "%s: [%d] xtal=%d set clock=%d\n",
__func__, i, val,
state->af9013_config[i].clock);
req.addr = AF9015_EEPROM_IF1H + offset;
ret = af9015_ctrl_msg(d, &req);
if (ret)
goto error;
state->af9013_config[i].if_frequency = val << 8;
req.addr = AF9015_EEPROM_IF1L + offset;
ret = af9015_ctrl_msg(d, &req);
if (ret)
goto error;
state->af9013_config[i].if_frequency += val;
state->af9013_config[i].if_frequency *= 1000;
dev_dbg(&d->udev->dev, "%s: [%d] IF frequency=%d\n", __func__,
i, state->af9013_config[i].if_frequency);
req.addr = AF9015_EEPROM_MT2060_IF1H + offset;
ret = af9015_ctrl_msg(d, &req);
if (ret)
goto error;
state->mt2060_if1[i] = val << 8;
req.addr = AF9015_EEPROM_MT2060_IF1L + offset;
ret = af9015_ctrl_msg(d, &req);
if (ret)
goto error;
state->mt2060_if1[i] += val;
dev_dbg(&d->udev->dev, "%s: [%d] MT2060 IF1=%d\n", __func__, i,
state->mt2060_if1[i]);
req.addr = AF9015_EEPROM_TUNER_ID1 + offset;
ret = af9015_ctrl_msg(d, &req);
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
state->af9013_config[i].spec_inv = 1;
break;
case AF9013_TUNER_MXL5003D:
case AF9013_TUNER_MXL5005D:
case AF9013_TUNER_MXL5005R:
case AF9013_TUNER_MXL5007T:
state->af9013_config[i].spec_inv = 0;
break;
case AF9013_TUNER_MC44S803:
state->af9013_config[i].gpio[1] = AF9013_GPIO_LO;
state->af9013_config[i].spec_inv = 1;
break;
default:
dev_err(&d->udev->dev, "%s: tuner id=%d not " \
"supported, please report!\n",
KBUILD_MODNAME, val);
return -ENODEV;
}
state->af9013_config[i].tuner = val;
dev_dbg(&d->udev->dev, "%s: [%d] tuner id=%d\n",
__func__, i, val);
}
error:
if (ret)
dev_err(&d->udev->dev, "%s: eeprom read failed=%d\n",
KBUILD_MODNAME, ret);
if (le16_to_cpu(d->udev->descriptor.idVendor) == USB_VID_AVERMEDIA &&
((le16_to_cpu(d->udev->descriptor.idProduct) ==
USB_PID_AVERMEDIA_A850) ||
(le16_to_cpu(d->udev->descriptor.idProduct) ==
USB_PID_AVERMEDIA_A850T))) {
dev_dbg(&d->udev->dev,
"%s: AverMedia A850: overriding config\n",
__func__);
state->dual_mode = 0;
state->af9013_config[0].if_frequency = 4570000;
}
return ret;
}
static int af9015_get_stream_config(struct dvb_frontend *fe, u8 *ts_type,
struct usb_data_stream_properties *stream)
{
struct dvb_usb_device *d = fe_to_d(fe);
dev_dbg(&d->udev->dev, "%s: adap=%d\n", __func__, fe_to_adap(fe)->id);
if (d->udev->speed == USB_SPEED_FULL)
stream->u.bulk.buffersize = TS_USB11_FRAME_SIZE;
return 0;
}
static int af9015_get_adapter_count(struct dvb_usb_device *d)
{
struct af9015_state *state = d_to_priv(d);
return state->dual_mode + 1;
}
static int af9015_af9013_set_frontend(struct dvb_frontend *fe)
{
int ret;
struct af9015_state *state = fe_to_priv(fe);
if (mutex_lock_interruptible(&state->fe_mutex))
return -EAGAIN;
ret = state->set_frontend[fe_to_adap(fe)->id](fe);
mutex_unlock(&state->fe_mutex);
return ret;
}
static int af9015_af9013_read_status(struct dvb_frontend *fe,
fe_status_t *status)
{
int ret;
struct af9015_state *state = fe_to_priv(fe);
if (mutex_lock_interruptible(&state->fe_mutex))
return -EAGAIN;
ret = state->read_status[fe_to_adap(fe)->id](fe, status);
mutex_unlock(&state->fe_mutex);
return ret;
}
static int af9015_af9013_init(struct dvb_frontend *fe)
{
int ret;
struct af9015_state *state = fe_to_priv(fe);
if (mutex_lock_interruptible(&state->fe_mutex))
return -EAGAIN;
ret = state->init[fe_to_adap(fe)->id](fe);
mutex_unlock(&state->fe_mutex);
return ret;
}
static int af9015_af9013_sleep(struct dvb_frontend *fe)
{
int ret;
struct af9015_state *state = fe_to_priv(fe);
if (mutex_lock_interruptible(&state->fe_mutex))
return -EAGAIN;
ret = state->sleep[fe_to_adap(fe)->id](fe);
mutex_unlock(&state->fe_mutex);
return ret;
}
static int af9015_tuner_init(struct dvb_frontend *fe)
{
int ret;
struct af9015_state *state = fe_to_priv(fe);
if (mutex_lock_interruptible(&state->fe_mutex))
return -EAGAIN;
ret = state->tuner_init[fe_to_adap(fe)->id](fe);
mutex_unlock(&state->fe_mutex);
return ret;
}
static int af9015_tuner_sleep(struct dvb_frontend *fe)
{
int ret;
struct af9015_state *state = fe_to_priv(fe);
if (mutex_lock_interruptible(&state->fe_mutex))
return -EAGAIN;
ret = state->tuner_sleep[fe_to_adap(fe)->id](fe);
mutex_unlock(&state->fe_mutex);
return ret;
}
static int af9015_copy_firmware(struct dvb_usb_device *d)
{
struct af9015_state *state = d_to_priv(d);
int ret;
u8 fw_params[4];
u8 val, i;
struct req_t req = {COPY_FIRMWARE, 0, 0x5100, 0, 0, sizeof(fw_params),
fw_params };
dev_dbg(&d->udev->dev, "%s:\n", __func__);
fw_params[0] = state->firmware_size >> 8;
fw_params[1] = state->firmware_size & 0xff;
fw_params[2] = state->firmware_checksum >> 8;
fw_params[3] = state->firmware_checksum & 0xff;
msleep(100);
ret = af9015_read_reg_i2c(d, state->af9013_config[1].i2c_addr,
0x98be, &val);
if (ret)
goto error;
else
dev_dbg(&d->udev->dev, "%s: firmware status=%02x\n",
__func__, val);
if (val == 0x0c)
goto exit;
ret = af9015_write_reg(d, 0xd416, 0x04);
if (ret)
goto error;
msleep(50);
ret = af9015_ctrl_msg(d, &req);
if (ret)
dev_err(&d->udev->dev, "%s: firmware copy cmd failed=%d\n",
KBUILD_MODNAME, ret);
dev_dbg(&d->udev->dev, "%s: firmware copy done\n", __func__);
ret = af9015_write_reg(d, 0xd416, 0x14);
if (ret)
goto error;
ret = af9015_write_reg_i2c(d, state->af9013_config[1].i2c_addr,
0xe205, 1);
dev_dbg(&d->udev->dev, "%s: firmware boot cmd status=%d\n",
__func__, ret);
if (ret)
goto error;
for (i = 0; i < 15; i++) {
msleep(100);
ret = af9015_read_reg_i2c(d, state->af9013_config[1].i2c_addr,
0x98be, &val);
dev_dbg(&d->udev->dev, "%s: firmware status cmd status=%d " \
"firmware status=%02x\n", __func__, ret, val);
if (ret)
goto error;
if (val == 0x0c || val == 0x04)
break;
}
if (val == 0x04) {
dev_err(&d->udev->dev, "%s: firmware did not run\n",
KBUILD_MODNAME);
ret = -ETIMEDOUT;
} else if (val != 0x0c) {
dev_err(&d->udev->dev, "%s: firmware boot timeout\n",
KBUILD_MODNAME);
ret = -ETIMEDOUT;
}
error:
exit:
return ret;
}
static int af9015_af9013_frontend_attach(struct dvb_usb_adapter *adap)
{
int ret;
struct af9015_state *state = adap_to_priv(adap);
if (adap->id == 0) {
state->af9013_config[0].ts_mode = AF9013_TS_USB;
memcpy(state->af9013_config[0].api_version, "\x0\x1\x9\x0", 4);
state->af9013_config[0].gpio[0] = AF9013_GPIO_HI;
state->af9013_config[0].gpio[3] = AF9013_GPIO_TUNER_ON;
} else if (adap->id == 1) {
state->af9013_config[1].ts_mode = AF9013_TS_SERIAL;
memcpy(state->af9013_config[1].api_version, "\x0\x1\x9\x0", 4);
state->af9013_config[1].gpio[0] = AF9013_GPIO_TUNER_ON;
state->af9013_config[1].gpio[1] = AF9013_GPIO_LO;
if (state->dual_mode) {
ret = af9015_copy_firmware(adap_to_d(adap));
if (ret) {
dev_err(&adap_to_d(adap)->udev->dev,
"%s: firmware copy to 2nd " \
"frontend failed, will " \
"disable it\n", KBUILD_MODNAME);
state->dual_mode = 0;
return -ENODEV;
}
} else {
return -ENODEV;
}
}
adap->fe[0] = dvb_attach(af9013_attach,
&state->af9013_config[adap->id], &adap_to_d(adap)->i2c_adap);
if (adap->fe[0]) {
state->set_frontend[adap->id] =
adap->fe[0]->ops.set_frontend;
adap->fe[0]->ops.set_frontend =
af9015_af9013_set_frontend;
state->read_status[adap->id] =
adap->fe[0]->ops.read_status;
adap->fe[0]->ops.read_status =
af9015_af9013_read_status;
state->init[adap->id] = adap->fe[0]->ops.init;
adap->fe[0]->ops.init = af9015_af9013_init;
state->sleep[adap->id] = adap->fe[0]->ops.sleep;
adap->fe[0]->ops.sleep = af9015_af9013_sleep;
}
return adap->fe[0] == NULL ? -ENODEV : 0;
}
static int af9015_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
struct af9015_state *state = d_to_priv(d);
int ret;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
switch (state->af9013_config[adap->id].tuner) {
case AF9013_TUNER_MT2060:
case AF9013_TUNER_MT2060_2:
ret = dvb_attach(mt2060_attach, adap->fe[0],
&adap_to_d(adap)->i2c_adap, &af9015_mt2060_config,
state->mt2060_if1[adap->id])
== NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_QT1010:
case AF9013_TUNER_QT1010A:
ret = dvb_attach(qt1010_attach, adap->fe[0],
&adap_to_d(adap)->i2c_adap,
&af9015_qt1010_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_TDA18271:
ret = dvb_attach(tda18271_attach, adap->fe[0], 0xc0,
&adap_to_d(adap)->i2c_adap,
&af9015_tda18271_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_TDA18218:
ret = dvb_attach(tda18218_attach, adap->fe[0],
&adap_to_d(adap)->i2c_adap,
&af9015_tda18218_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_MXL5003D:
ret = dvb_attach(mxl5005s_attach, adap->fe[0],
&adap_to_d(adap)->i2c_adap,
&af9015_mxl5003_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_MXL5005D:
case AF9013_TUNER_MXL5005R:
ret = dvb_attach(mxl5005s_attach, adap->fe[0],
&adap_to_d(adap)->i2c_adap,
&af9015_mxl5005_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_ENV77H11D5:
ret = dvb_attach(dvb_pll_attach, adap->fe[0], 0xc0,
&adap_to_d(adap)->i2c_adap,
DVB_PLL_TDA665X) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_MC44S803:
ret = dvb_attach(mc44s803_attach, adap->fe[0],
&adap_to_d(adap)->i2c_adap,
&af9015_mc44s803_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_MXL5007T:
ret = dvb_attach(mxl5007t_attach, adap->fe[0],
&adap_to_d(adap)->i2c_adap,
0xc0, &af9015_mxl5007t_config) == NULL ? -ENODEV : 0;
break;
case AF9013_TUNER_UNKNOWN:
default:
dev_err(&d->udev->dev, "%s: unknown tuner id=%d\n",
KBUILD_MODNAME,
state->af9013_config[adap->id].tuner);
ret = -ENODEV;
}
if (adap->fe[0]->ops.tuner_ops.init) {
state->tuner_init[adap->id] =
adap->fe[0]->ops.tuner_ops.init;
adap->fe[0]->ops.tuner_ops.init = af9015_tuner_init;
}
if (adap->fe[0]->ops.tuner_ops.sleep) {
state->tuner_sleep[adap->id] =
adap->fe[0]->ops.tuner_ops.sleep;
adap->fe[0]->ops.tuner_ops.sleep = af9015_tuner_sleep;
}
return ret;
}
static int af9015_pid_filter_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct dvb_usb_device *d = adap_to_d(adap);
int ret;
dev_dbg(&d->udev->dev, "%s: onoff=%d\n", __func__, onoff);
if (onoff)
ret = af9015_set_reg_bit(d, 0xd503, 0);
else
ret = af9015_clear_reg_bit(d, 0xd503, 0);
return ret;
}
static int af9015_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid,
int onoff)
{
struct dvb_usb_device *d = adap_to_d(adap);
int ret;
u8 idx;
dev_dbg(&d->udev->dev, "%s: index=%d pid=%04x onoff=%d\n",
__func__, index, pid, onoff);
ret = af9015_write_reg(d, 0xd505, (pid & 0xff));
if (ret)
goto error;
ret = af9015_write_reg(d, 0xd506, (pid >> 8));
if (ret)
goto error;
idx = ((index & 0x1f) | (1 << 5));
ret = af9015_write_reg(d, 0xd504, idx);
error:
return ret;
}
static int af9015_init_endpoint(struct dvb_usb_device *d)
{
struct af9015_state *state = d_to_priv(d);
int ret;
u16 frame_size;
u8 packet_size;
dev_dbg(&d->udev->dev, "%s: USB speed=%d\n", __func__, d->udev->speed);
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
if (state->dual_mode) {
ret = af9015_set_reg_bit(d, 0xdd11, 6);
if (ret)
goto error;
}
ret = af9015_clear_reg_bit(d, 0xdd13, 5);
if (ret)
goto error;
if (state->dual_mode) {
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
if (state->dual_mode) {
ret = af9015_clear_reg_bit(d, 0xd50b, 1);
if (ret)
goto error;
}
if (state->dual_mode)
ret = af9015_set_reg_bit(d, 0xd50b, 0);
else
ret = af9015_clear_reg_bit(d, 0xd50b, 0);
error:
if (ret)
dev_err(&d->udev->dev, "%s: endpoint init failed=%d\n",
KBUILD_MODNAME, ret);
return ret;
}
static int af9015_init(struct dvb_usb_device *d)
{
struct af9015_state *state = d_to_priv(d);
int ret;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
mutex_init(&state->fe_mutex);
ret = af9015_write_reg(d, 0x98e9, 0xff);
if (ret)
goto error;
ret = af9015_init_endpoint(d);
if (ret)
goto error;
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
static int af9015_rc_query(struct dvb_usb_device *d)
{
struct af9015_state *state = d_to_priv(d);
int ret;
u8 buf[17];
ret = af9015_read_regs(d, 0x98d9, buf, sizeof(buf));
if (ret)
goto error;
if (buf[1] || buf[2] || buf[3]) {
dev_dbg(&d->udev->dev, "%s: invalid data\n", __func__);
return ret;
}
if ((state->rc_repeat != buf[6] || buf[0]) &&
!memcmp(&buf[12], state->rc_last, 4)) {
dev_dbg(&d->udev->dev, "%s: key repeated\n", __func__);
rc_repeat(d->rc_dev);
state->rc_repeat = buf[6];
return ret;
}
if (buf[16] != 0xff && buf[0] != 0x01) {
dev_dbg(&d->udev->dev, "%s: key pressed %*ph\n",
__func__, 4, buf + 12);
ret = af9015_write_reg(d, 0x98e9, 0xff);
if (ret)
goto error;
memcpy(state->rc_last, &buf[12], 4);
if (buf[14] == (u8) ~buf[15]) {
if (buf[12] == (u8) ~buf[13]) {
state->rc_keycode = RC_SCANCODE_NEC(buf[12],
buf[14]);
} else {
state->rc_keycode = RC_SCANCODE_NECX(buf[12] << 8 |
buf[13],
buf[14]);
}
} else {
state->rc_keycode = RC_SCANCODE_NEC32(buf[12] << 24 |
buf[13] << 16 |
buf[14] << 8 |
buf[15]);
}
rc_keydown(d->rc_dev, RC_TYPE_NEC, state->rc_keycode, 0);
} else {
dev_dbg(&d->udev->dev, "%s: no key press\n", __func__);
state->rc_last[2] = state->rc_last[3];
}
state->rc_repeat = buf[6];
state->rc_failed = false;
error:
if (ret) {
dev_warn(&d->udev->dev, "%s: rc query failed=%d\n",
KBUILD_MODNAME, ret);
if (!state->rc_failed)
ret = 0;
state->rc_failed = true;
}
return ret;
}
static int af9015_get_rc_config(struct dvb_usb_device *d, struct dvb_usb_rc *rc)
{
struct af9015_state *state = d_to_priv(d);
u16 vid = le16_to_cpu(d->udev->descriptor.idVendor);
if (state->ir_mode == AF9015_IR_MODE_DISABLED)
return 0;
if (!rc->map_name)
rc->map_name = af9015_rc_setup_match(dvb_usb_af9015_remote,
af9015_rc_setup_modparam);
if (!rc->map_name)
rc->map_name = af9015_rc_setup_match(state->eeprom_sum,
af9015_rc_setup_hashes);
if (!rc->map_name && vid == USB_VID_AFATECH) {
char manufacturer[10];
memset(manufacturer, 0, sizeof(manufacturer));
usb_string(d->udev, d->udev->descriptor.iManufacturer,
manufacturer, sizeof(manufacturer));
if (!strcmp("MSI", manufacturer)) {
rc->map_name = af9015_rc_setup_match(
AF9015_REMOTE_MSI_DIGIVOX_MINI_II_V3,
af9015_rc_setup_modparam);
}
}
if (!rc->map_name)
rc->map_name = RC_MAP_EMPTY;
rc->allowed_protos = RC_BIT_NEC;
rc->query = af9015_rc_query;
rc->interval = 500;
return 0;
}
static int af9015_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
char manufacturer[sizeof("ITE Technologies, Inc.")];
memset(manufacturer, 0, sizeof(manufacturer));
usb_string(udev, udev->descriptor.iManufacturer,
manufacturer, sizeof(manufacturer));
if ((le16_to_cpu(udev->descriptor.idVendor) == USB_VID_TERRATEC) &&
(le16_to_cpu(udev->descriptor.idProduct) == 0x0099)) {
if (!strcmp("ITE Technologies, Inc.", manufacturer)) {
dev_dbg(&udev->dev, "%s: rejecting device\n", __func__);
return -ENODEV;
}
}
return dvb_usbv2_probe(intf, id);
}
