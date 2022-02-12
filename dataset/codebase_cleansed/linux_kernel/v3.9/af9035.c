static u16 af9035_checksum(const u8 *buf, size_t len)
{
size_t i;
u16 checksum = 0;
for (i = 1; i < len; i++) {
if (i % 2)
checksum += buf[i] << 8;
else
checksum += buf[i];
}
checksum = ~checksum;
return checksum;
}
static int af9035_ctrl_msg(struct dvb_usb_device *d, struct usb_req *req)
{
#define BUF_LEN 64
#define REQ_HDR_LEN 4
#define ACK_HDR_LEN 3
#define CHECKSUM_LEN 2
#define USB_TIMEOUT 2000
struct state *state = d_to_priv(d);
int ret, wlen, rlen;
u8 buf[BUF_LEN];
u16 checksum, tmp_checksum;
if (req->wlen > (BUF_LEN - REQ_HDR_LEN - CHECKSUM_LEN) ||
req->rlen > (BUF_LEN - ACK_HDR_LEN - CHECKSUM_LEN)) {
dev_err(&d->udev->dev, "%s: too much data wlen=%d rlen=%d\n",
__func__, req->wlen, req->rlen);
return -EINVAL;
}
buf[0] = REQ_HDR_LEN + req->wlen + CHECKSUM_LEN - 1;
buf[1] = req->mbox;
buf[2] = req->cmd;
buf[3] = state->seq++;
memcpy(&buf[REQ_HDR_LEN], req->wbuf, req->wlen);
wlen = REQ_HDR_LEN + req->wlen + CHECKSUM_LEN;
rlen = ACK_HDR_LEN + req->rlen + CHECKSUM_LEN;
checksum = af9035_checksum(buf, buf[0] - 1);
buf[buf[0] - 1] = (checksum >> 8);
buf[buf[0] - 0] = (checksum & 0xff);
if (req->cmd == CMD_FW_DL)
rlen = 0;
ret = dvb_usbv2_generic_rw(d, buf, wlen, buf, rlen);
if (ret)
goto err;
if (req->cmd == CMD_FW_DL)
goto exit;
checksum = af9035_checksum(buf, rlen - 2);
tmp_checksum = (buf[rlen - 2] << 8) | buf[rlen - 1];
if (tmp_checksum != checksum) {
dev_err(&d->udev->dev, "%s: command=%02x checksum mismatch " \
"(%04x != %04x)\n", KBUILD_MODNAME, req->cmd,
tmp_checksum, checksum);
ret = -EIO;
goto err;
}
if (buf[2]) {
dev_dbg(&d->udev->dev, "%s: command=%02x failed fw error=%d\n",
__func__, req->cmd, buf[2]);
ret = -EIO;
goto err;
}
if (req->rlen)
memcpy(req->rbuf, &buf[ACK_HDR_LEN], req->rlen);
exit:
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_wr_regs(struct dvb_usb_device *d, u32 reg, u8 *val, int len)
{
u8 wbuf[6 + len];
u8 mbox = (reg >> 16) & 0xff;
struct usb_req req = { CMD_MEM_WR, mbox, sizeof(wbuf), wbuf, 0, NULL };
wbuf[0] = len;
wbuf[1] = 2;
wbuf[2] = 0;
wbuf[3] = 0;
wbuf[4] = (reg >> 8) & 0xff;
wbuf[5] = (reg >> 0) & 0xff;
memcpy(&wbuf[6], val, len);
return af9035_ctrl_msg(d, &req);
}
static int af9035_rd_regs(struct dvb_usb_device *d, u32 reg, u8 *val, int len)
{
u8 wbuf[] = { len, 2, 0, 0, (reg >> 8) & 0xff, reg & 0xff };
u8 mbox = (reg >> 16) & 0xff;
struct usb_req req = { CMD_MEM_RD, mbox, sizeof(wbuf), wbuf, len, val };
return af9035_ctrl_msg(d, &req);
}
static int af9035_wr_reg(struct dvb_usb_device *d, u32 reg, u8 val)
{
return af9035_wr_regs(d, reg, &val, 1);
}
static int af9035_rd_reg(struct dvb_usb_device *d, u32 reg, u8 *val)
{
return af9035_rd_regs(d, reg, val, 1);
}
static int af9035_wr_reg_mask(struct dvb_usb_device *d, u32 reg, u8 val,
u8 mask)
{
int ret;
u8 tmp;
if (mask != 0xff) {
ret = af9035_rd_regs(d, reg, &tmp, 1);
if (ret)
return ret;
val &= mask;
tmp &= ~mask;
val |= tmp;
}
return af9035_wr_regs(d, reg, &val, 1);
}
static int af9035_i2c_master_xfer(struct i2c_adapter *adap,
struct i2c_msg msg[], int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
struct state *state = d_to_priv(d);
int ret;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
if (num == 2 && !(msg[0].flags & I2C_M_RD) &&
(msg[1].flags & I2C_M_RD)) {
if (msg[0].len > 40 || msg[1].len > 40) {
ret = -EOPNOTSUPP;
} else if ((msg[0].addr == state->af9033_config[0].i2c_addr) ||
(msg[0].addr == state->af9033_config[1].i2c_addr)) {
u32 reg = msg[0].buf[0] << 16 | msg[0].buf[1] << 8 |
msg[0].buf[2];
if (msg[0].addr == state->af9033_config[1].i2c_addr)
reg |= 0x100000;
ret = af9035_rd_regs(d, reg, &msg[1].buf[0],
msg[1].len);
} else {
u8 buf[5 + msg[0].len];
struct usb_req req = { CMD_I2C_RD, 0, sizeof(buf),
buf, msg[1].len, msg[1].buf };
req.mbox |= ((msg[0].addr & 0x80) >> 3);
buf[0] = msg[1].len;
buf[1] = msg[0].addr << 1;
buf[2] = 0x00;
buf[3] = 0x00;
buf[4] = 0x00;
memcpy(&buf[5], msg[0].buf, msg[0].len);
ret = af9035_ctrl_msg(d, &req);
}
} else if (num == 1 && !(msg[0].flags & I2C_M_RD)) {
if (msg[0].len > 40) {
ret = -EOPNOTSUPP;
} else if ((msg[0].addr == state->af9033_config[0].i2c_addr) ||
(msg[0].addr == state->af9033_config[1].i2c_addr)) {
u32 reg = msg[0].buf[0] << 16 | msg[0].buf[1] << 8 |
msg[0].buf[2];
if (msg[0].addr == state->af9033_config[1].i2c_addr)
reg |= 0x100000;
ret = af9035_wr_regs(d, reg, &msg[0].buf[3],
msg[0].len - 3);
} else {
u8 buf[5 + msg[0].len];
struct usb_req req = { CMD_I2C_WR, 0, sizeof(buf), buf,
0, NULL };
req.mbox |= ((msg[0].addr & 0x80) >> 3);
buf[0] = msg[0].len;
buf[1] = msg[0].addr << 1;
buf[2] = 0x00;
buf[3] = 0x00;
buf[4] = 0x00;
memcpy(&buf[5], msg[0].buf, msg[0].len);
ret = af9035_ctrl_msg(d, &req);
}
} else {
ret = -EOPNOTSUPP;
}
mutex_unlock(&d->i2c_mutex);
if (ret < 0)
return ret;
else
return num;
}
static u32 af9035_i2c_functionality(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int af9035_identify_state(struct dvb_usb_device *d, const char **name)
{
int ret;
u8 wbuf[1] = { 1 };
u8 rbuf[4];
struct usb_req req = { CMD_FW_QUERYINFO, 0, sizeof(wbuf), wbuf,
sizeof(rbuf), rbuf };
ret = af9035_ctrl_msg(d, &req);
if (ret < 0)
goto err;
dev_dbg(&d->udev->dev, "%s: reply=%*ph\n", __func__, 4, rbuf);
if (rbuf[0] || rbuf[1] || rbuf[2] || rbuf[3])
ret = WARM;
else
ret = COLD;
return ret;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_download_firmware(struct dvb_usb_device *d,
const struct firmware *fw)
{
int ret, i, j, len;
u8 wbuf[1];
u8 rbuf[4];
struct usb_req req = { 0, 0, 0, NULL, 0, NULL };
struct usb_req req_fw_dl = { CMD_FW_DL, 0, 0, wbuf, 0, NULL };
struct usb_req req_fw_ver = { CMD_FW_QUERYINFO, 0, 1, wbuf, 4, rbuf } ;
u8 hdr_core, tmp;
u16 hdr_addr, hdr_data_len, hdr_checksum;
#define MAX_DATA 58
#define HDR_SIZE 7
ret = af9035_rd_reg(d, EEPROM_DUAL_MODE, &tmp);
if (ret < 0)
goto err;
if (tmp) {
ret = af9035_wr_reg_mask(d, 0x00d8b0, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0x00d8b1, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0x00d8af, 0x00, 0x01);
if (ret < 0)
goto err;
usleep_range(10000, 50000);
ret = af9035_wr_reg_mask(d, 0x00d8af, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_rd_reg(d, EEPROM_2ND_DEMOD_ADDR, &tmp);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00417f, tmp);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0x00d81a, 0x01, 0x01);
if (ret < 0)
goto err;
}
for (i = fw->size; i > HDR_SIZE;) {
hdr_core = fw->data[fw->size - i + 0];
hdr_addr = fw->data[fw->size - i + 1] << 8;
hdr_addr |= fw->data[fw->size - i + 2] << 0;
hdr_data_len = fw->data[fw->size - i + 3] << 8;
hdr_data_len |= fw->data[fw->size - i + 4] << 0;
hdr_checksum = fw->data[fw->size - i + 5] << 8;
hdr_checksum |= fw->data[fw->size - i + 6] << 0;
dev_dbg(&d->udev->dev, "%s: core=%d addr=%04x data_len=%d " \
"checksum=%04x\n", __func__, hdr_core, hdr_addr,
hdr_data_len, hdr_checksum);
if (((hdr_core != 1) && (hdr_core != 2)) ||
(hdr_data_len > i)) {
dev_dbg(&d->udev->dev, "%s: bad firmware\n", __func__);
break;
}
req.cmd = CMD_FW_DL_BEGIN;
ret = af9035_ctrl_msg(d, &req);
if (ret < 0)
goto err;
for (j = HDR_SIZE + hdr_data_len; j > 0; j -= MAX_DATA) {
len = j;
if (len > MAX_DATA)
len = MAX_DATA;
req_fw_dl.wlen = len;
req_fw_dl.wbuf = (u8 *) &fw->data[fw->size - i +
HDR_SIZE + hdr_data_len - j];
ret = af9035_ctrl_msg(d, &req_fw_dl);
if (ret < 0)
goto err;
}
req.cmd = CMD_FW_DL_END;
ret = af9035_ctrl_msg(d, &req);
if (ret < 0)
goto err;
i -= hdr_data_len + HDR_SIZE;
dev_dbg(&d->udev->dev, "%s: data uploaded=%zu\n",
__func__, fw->size - i);
}
if (i)
dev_warn(&d->udev->dev, "%s: bad firmware\n", KBUILD_MODNAME);
req.cmd = CMD_FW_BOOT;
ret = af9035_ctrl_msg(d, &req);
if (ret < 0)
goto err;
wbuf[0] = 1;
ret = af9035_ctrl_msg(d, &req_fw_ver);
if (ret < 0)
goto err;
if (!(rbuf[0] || rbuf[1] || rbuf[2] || rbuf[3])) {
dev_err(&d->udev->dev, "%s: firmware did not run\n",
KBUILD_MODNAME);
ret = -ENODEV;
goto err;
}
dev_info(&d->udev->dev, "%s: firmware version=%d.%d.%d.%d",
KBUILD_MODNAME, rbuf[0], rbuf[1], rbuf[2], rbuf[3]);
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_download_firmware_it9135(struct dvb_usb_device *d,
const struct firmware *fw)
{
int ret, i, i_prev;
u8 wbuf[1];
u8 rbuf[4];
struct usb_req req = { 0, 0, 0, NULL, 0, NULL };
struct usb_req req_fw_dl = { CMD_FW_SCATTER_WR, 0, 0, NULL, 0, NULL };
struct usb_req req_fw_ver = { CMD_FW_QUERYINFO, 0, 1, wbuf, 4, rbuf } ;
#define HDR_SIZE 7
for (i = HDR_SIZE, i_prev = 0; i <= fw->size; i++) {
if (i == fw->size ||
(fw->data[i + 0] == 0x03 &&
(fw->data[i + 1] == 0x00 ||
fw->data[i + 1] == 0x01) &&
fw->data[i + 2] == 0x00)) {
req_fw_dl.wlen = i - i_prev;
req_fw_dl.wbuf = (u8 *) &fw->data[i_prev];
i_prev = i;
ret = af9035_ctrl_msg(d, &req_fw_dl);
if (ret < 0)
goto err;
dev_dbg(&d->udev->dev, "%s: data uploaded=%d\n",
__func__, i);
}
}
req.cmd = CMD_FW_BOOT;
ret = af9035_ctrl_msg(d, &req);
if (ret < 0)
goto err;
wbuf[0] = 1;
ret = af9035_ctrl_msg(d, &req_fw_ver);
if (ret < 0)
goto err;
if (!(rbuf[0] || rbuf[1] || rbuf[2] || rbuf[3])) {
dev_err(&d->udev->dev, "%s: firmware did not run\n",
KBUILD_MODNAME);
ret = -ENODEV;
goto err;
}
dev_info(&d->udev->dev, "%s: firmware version=%d.%d.%d.%d",
KBUILD_MODNAME, rbuf[0], rbuf[1], rbuf[2], rbuf[3]);
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_read_config(struct dvb_usb_device *d)
{
struct state *state = d_to_priv(d);
int ret, i, eeprom_shift = 0;
u8 tmp;
u16 tmp16;
state->af9033_config[0].i2c_addr = 0x38;
ret = af9035_rd_reg(d, EEPROM_DUAL_MODE, &tmp);
if (ret < 0)
goto err;
state->dual_mode = tmp;
dev_dbg(&d->udev->dev, "%s: dual mode=%d\n", __func__,
state->dual_mode);
if (state->dual_mode) {
ret = af9035_rd_reg(d, EEPROM_2ND_DEMOD_ADDR, &tmp);
if (ret < 0)
goto err;
state->af9033_config[1].i2c_addr = tmp;
dev_dbg(&d->udev->dev, "%s: 2nd demod I2C addr=%02x\n",
__func__, tmp);
}
for (i = 0; i < state->dual_mode + 1; i++) {
ret = af9035_rd_reg(d, EEPROM_1_TUNER_ID + eeprom_shift, &tmp);
if (ret < 0)
goto err;
state->af9033_config[i].tuner = tmp;
dev_dbg(&d->udev->dev, "%s: [%d]tuner=%02x\n",
__func__, i, tmp);
switch (tmp) {
case AF9033_TUNER_TUA9001:
case AF9033_TUNER_FC0011:
case AF9033_TUNER_MXL5007T:
case AF9033_TUNER_TDA18218:
case AF9033_TUNER_FC2580:
case AF9033_TUNER_FC0012:
state->af9033_config[i].spec_inv = 1;
break;
default:
dev_warn(&d->udev->dev, "%s: tuner id=%02x not " \
"supported, please report!",
KBUILD_MODNAME, tmp);
}
if (i == 1)
switch (tmp) {
case AF9033_TUNER_FC0012:
break;
default:
state->dual_mode = false;
dev_info(&d->udev->dev, "%s: driver does not " \
"support 2nd tuner and will " \
"disable it", KBUILD_MODNAME);
}
ret = af9035_rd_reg(d, EEPROM_1_IFFREQ_L + eeprom_shift, &tmp);
if (ret < 0)
goto err;
tmp16 = tmp;
ret = af9035_rd_reg(d, EEPROM_1_IFFREQ_H + eeprom_shift, &tmp);
if (ret < 0)
goto err;
tmp16 |= tmp << 8;
dev_dbg(&d->udev->dev, "%s: [%d]IF=%d\n", __func__, i, tmp16);
eeprom_shift = 0x10;
}
ret = af9035_rd_reg(d, 0x00d800, &tmp);
if (ret < 0)
goto err;
tmp = (tmp >> 0) & 0x0f;
for (i = 0; i < ARRAY_SIZE(state->af9033_config); i++)
state->af9033_config[i].clock = clock_lut[tmp];
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_read_config_it9135(struct dvb_usb_device *d)
{
struct state *state = d_to_priv(d);
int ret, i;
u8 tmp;
state->dual_mode = false;
ret = af9035_rd_reg(d, 0x00d800, &tmp);
if (ret < 0)
goto err;
tmp = (tmp >> 0) & 0x0f;
for (i = 0; i < ARRAY_SIZE(state->af9033_config); i++)
state->af9033_config[i].clock = clock_lut_it9135[tmp];
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_tua9001_tuner_callback(struct dvb_usb_device *d,
int cmd, int arg)
{
int ret;
u8 val;
dev_dbg(&d->udev->dev, "%s: cmd=%d arg=%d\n", __func__, cmd, arg);
switch (cmd) {
case TUA9001_CMD_RESETN:
if (arg)
val = 0x00;
else
val = 0x01;
ret = af9035_wr_reg_mask(d, 0x00d8e7, val, 0x01);
if (ret < 0)
goto err;
break;
case TUA9001_CMD_RXEN:
if (arg)
val = 0x01;
else
val = 0x00;
ret = af9035_wr_reg_mask(d, 0x00d8eb, val, 0x01);
if (ret < 0)
goto err;
break;
}
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_fc0011_tuner_callback(struct dvb_usb_device *d,
int cmd, int arg)
{
int ret;
switch (cmd) {
case FC0011_FE_CALLBACK_POWER:
ret = af9035_wr_reg_mask(d, 0xd8eb, 1, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8ec, 1, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8ed, 1, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8d0, 1, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8d1, 1, 1);
if (ret < 0)
goto err;
usleep_range(10000, 50000);
break;
case FC0011_FE_CALLBACK_RESET:
ret = af9035_wr_reg(d, 0xd8e9, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0xd8e8, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0xd8e7, 1);
if (ret < 0)
goto err;
usleep_range(10000, 20000);
ret = af9035_wr_reg(d, 0xd8e7, 0);
if (ret < 0)
goto err;
usleep_range(10000, 20000);
break;
default:
ret = -EINVAL;
goto err;
}
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_tuner_callback(struct dvb_usb_device *d, int cmd, int arg)
{
struct state *state = d_to_priv(d);
switch (state->af9033_config[0].tuner) {
case AF9033_TUNER_FC0011:
return af9035_fc0011_tuner_callback(d, cmd, arg);
case AF9033_TUNER_TUA9001:
return af9035_tua9001_tuner_callback(d, cmd, arg);
default:
break;
}
return 0;
}
static int af9035_frontend_callback(void *adapter_priv, int component,
int cmd, int arg)
{
struct i2c_adapter *adap = adapter_priv;
struct dvb_usb_device *d = i2c_get_adapdata(adap);
dev_dbg(&d->udev->dev, "%s: component=%d cmd=%d arg=%d\n",
__func__, component, cmd, arg);
switch (component) {
case DVB_FRONTEND_COMPONENT_TUNER:
return af9035_tuner_callback(d, cmd, arg);
default:
break;
}
return 0;
}
static int af9035_get_adapter_count(struct dvb_usb_device *d)
{
struct state *state = d_to_priv(d);
return state->dual_mode + 1;
}
static int af9035_frontend_attach(struct dvb_usb_adapter *adap)
{
struct state *state = adap_to_priv(adap);
struct dvb_usb_device *d = adap_to_d(adap);
int ret;
if (!state->af9033_config[adap->id].tuner) {
ret = -ENODEV;
goto err;
}
if (adap->id == 0) {
state->af9033_config[0].ts_mode = AF9033_TS_MODE_USB;
state->af9033_config[1].ts_mode = AF9033_TS_MODE_SERIAL;
ret = af9035_wr_reg(d, 0x00417f,
state->af9033_config[1].i2c_addr);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00d81a, state->dual_mode);
if (ret < 0)
goto err;
}
adap->fe[0] = dvb_attach(af9033_attach, &state->af9033_config[adap->id],
&d->i2c_adap);
if (adap->fe[0] == NULL) {
ret = -ENODEV;
goto err;
}
adap->fe[0]->ops.i2c_gate_ctrl = NULL;
adap->fe[0]->callback = af9035_frontend_callback;
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_tuner_attach(struct dvb_usb_adapter *adap)
{
struct state *state = adap_to_priv(adap);
struct dvb_usb_device *d = adap_to_d(adap);
int ret;
struct dvb_frontend *fe;
struct i2c_msg msg[1];
u8 tuner_addr;
switch (state->af9033_config[adap->id].tuner) {
case AF9033_TUNER_TUA9001:
ret = af9035_wr_reg_mask(d, 0x00d8ec, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0x00d8ed, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0x00d8e8, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0x00d8e9, 0x01, 0x01);
if (ret < 0)
goto err;
fe = dvb_attach(tua9001_attach, adap->fe[0],
&d->i2c_adap, &af9035_tua9001_config);
break;
case AF9033_TUNER_FC0011:
fe = dvb_attach(fc0011_attach, adap->fe[0],
&d->i2c_adap, &af9035_fc0011_config);
break;
case AF9033_TUNER_MXL5007T:
if (adap->id == 0) {
ret = af9035_wr_reg(d, 0x00d8e0, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00d8e1, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00d8df, 0);
if (ret < 0)
goto err;
msleep(30);
ret = af9035_wr_reg(d, 0x00d8df, 1);
if (ret < 0)
goto err;
msleep(300);
ret = af9035_wr_reg(d, 0x00d8c0, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00d8c1, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00d8bf, 0);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00d8b4, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00d8b5, 1);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00d8b3, 1);
if (ret < 0)
goto err;
tuner_addr = 0x60;
} else {
tuner_addr = 0x60 | 0x80;
}
fe = dvb_attach(mxl5007t_attach, adap->fe[0], &d->i2c_adap,
tuner_addr, &af9035_mxl5007t_config[adap->id]);
break;
case AF9033_TUNER_TDA18218:
fe = dvb_attach(tda18218_attach, adap->fe[0],
&d->i2c_adap, &af9035_tda18218_config);
break;
case AF9033_TUNER_FC2580:
ret = af9035_wr_reg_mask(d, 0xd8eb, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8ec, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8ed, 0x01, 0x01);
if (ret < 0)
goto err;
usleep_range(10000, 50000);
fe = dvb_attach(fc2580_attach, adap->fe[0],
&d->i2c_adap, &af9035_fc2580_config);
break;
case AF9033_TUNER_FC0012:
if (adap->id == 0) {
ret = af9035_wr_reg_mask(d, 0xd8eb, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8ec, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8ed, 0x01, 0x01);
if (ret < 0)
goto err;
} else {
msg[0].addr = 0x63;
msg[0].flags = 0;
msg[0].len = 2;
msg[0].buf = "\x0d\x02";
ret = i2c_transfer(&d->i2c_adap, msg, 1);
if (ret < 0)
goto err;
}
usleep_range(10000, 50000);
fe = dvb_attach(fc0012_attach, adap->fe[0], &d->i2c_adap,
&af9035_fc0012_config[adap->id]);
break;
default:
fe = NULL;
}
if (fe == NULL) {
ret = -ENODEV;
goto err;
}
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_init(struct dvb_usb_device *d)
{
struct state *state = d_to_priv(d);
int ret, i;
u16 frame_size = 87 * 188 / 4;
u8 packet_size = 512 / 4;
struct reg_val_mask tab[] = {
{ 0x80f99d, 0x01, 0x01 },
{ 0x80f9a4, 0x01, 0x01 },
{ 0x00dd11, 0x00, 0x20 },
{ 0x00dd11, 0x00, 0x40 },
{ 0x00dd13, 0x00, 0x20 },
{ 0x00dd13, 0x00, 0x40 },
{ 0x00dd11, 0x20, 0x20 },
{ 0x00dd88, (frame_size >> 0) & 0xff, 0xff},
{ 0x00dd89, (frame_size >> 8) & 0xff, 0xff},
{ 0x00dd0c, packet_size, 0xff},
{ 0x00dd11, state->dual_mode << 6, 0x40 },
{ 0x00dd8a, (frame_size >> 0) & 0xff, 0xff},
{ 0x00dd8b, (frame_size >> 8) & 0xff, 0xff},
{ 0x00dd0d, packet_size, 0xff },
{ 0x80f9a3, state->dual_mode, 0x01 },
{ 0x80f9cd, state->dual_mode, 0x01 },
{ 0x80f99d, 0x00, 0x01 },
{ 0x80f9a4, 0x00, 0x01 },
};
dev_dbg(&d->udev->dev, "%s: USB speed=%d frame_size=%04x " \
"packet_size=%02x\n", __func__,
d->udev->speed, frame_size, packet_size);
for (i = 0; i < ARRAY_SIZE(tab); i++) {
ret = af9035_wr_reg_mask(d, tab[i].reg, tab[i].val,
tab[i].mask);
if (ret < 0)
goto err;
}
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int af9035_rc_query(struct dvb_usb_device *d)
{
unsigned int key;
unsigned char b[4];
int ret;
struct usb_req req = { CMD_IR_GET, 0, 0, NULL, 4, b };
ret = af9035_ctrl_msg(d, &req);
if (ret < 0)
goto err;
if ((b[2] + b[3]) == 0xff) {
if ((b[0] + b[1]) == 0xff) {
key = b[0] << 8 | b[2];
} else {
key = b[0] << 16 | b[1] << 8 | b[2];
}
} else {
key = b[0] << 24 | b[1] << 16 | b[2] << 8 | b[3];
}
rc_keydown(d->rc_dev, key, 0);
err:
return 0;
}
static int af9035_get_rc_config(struct dvb_usb_device *d, struct dvb_usb_rc *rc)
{
int ret;
u8 tmp;
ret = af9035_rd_reg(d, EEPROM_IR_MODE, &tmp);
if (ret < 0)
goto err;
dev_dbg(&d->udev->dev, "%s: ir_mode=%02x\n", __func__, tmp);
if (tmp == 5) {
ret = af9035_rd_reg(d, EEPROM_IR_TYPE, &tmp);
if (ret < 0)
goto err;
dev_dbg(&d->udev->dev, "%s: ir_type=%02x\n", __func__, tmp);
switch (tmp) {
case 0:
default:
rc->allowed_protos = RC_BIT_NEC;
break;
case 1:
rc->allowed_protos = RC_BIT_RC6_MCE;
break;
}
rc->query = af9035_rc_query;
rc->interval = 500;
if (!rc->map_name)
rc->map_name = RC_MAP_EMPTY;
}
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
