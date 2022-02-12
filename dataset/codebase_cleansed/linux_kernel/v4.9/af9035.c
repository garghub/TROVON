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
#define REQ_HDR_LEN 4
#define ACK_HDR_LEN 3
#define CHECKSUM_LEN 2
#define USB_TIMEOUT 2000
struct state *state = d_to_priv(d);
struct usb_interface *intf = d->intf;
int ret, wlen, rlen;
u16 checksum, tmp_checksum;
mutex_lock(&d->usb_mutex);
if (req->wlen > (BUF_LEN - REQ_HDR_LEN - CHECKSUM_LEN) ||
req->rlen > (BUF_LEN - ACK_HDR_LEN - CHECKSUM_LEN)) {
dev_err(&intf->dev, "too much data wlen=%d rlen=%d\n",
req->wlen, req->rlen);
ret = -EINVAL;
goto exit;
}
state->buf[0] = REQ_HDR_LEN + req->wlen + CHECKSUM_LEN - 1;
state->buf[1] = req->mbox;
state->buf[2] = req->cmd;
state->buf[3] = state->seq++;
memcpy(&state->buf[REQ_HDR_LEN], req->wbuf, req->wlen);
wlen = REQ_HDR_LEN + req->wlen + CHECKSUM_LEN;
rlen = ACK_HDR_LEN + req->rlen + CHECKSUM_LEN;
checksum = af9035_checksum(state->buf, state->buf[0] - 1);
state->buf[state->buf[0] - 1] = (checksum >> 8);
state->buf[state->buf[0] - 0] = (checksum & 0xff);
if (req->cmd == CMD_FW_DL)
rlen = 0;
ret = dvb_usbv2_generic_rw_locked(d,
state->buf, wlen, state->buf, rlen);
if (ret)
goto exit;
if (req->cmd == CMD_FW_DL)
goto exit;
checksum = af9035_checksum(state->buf, rlen - 2);
tmp_checksum = (state->buf[rlen - 2] << 8) | state->buf[rlen - 1];
if (tmp_checksum != checksum) {
dev_err(&intf->dev, "command=%02x checksum mismatch (%04x != %04x)\n",
req->cmd, tmp_checksum, checksum);
ret = -EIO;
goto exit;
}
if (state->buf[2]) {
if (req->cmd == CMD_IR_GET || state->buf[2] == 1) {
ret = 1;
goto exit;
}
dev_dbg(&intf->dev, "command=%02x failed fw error=%d\n",
req->cmd, state->buf[2]);
ret = -EIO;
goto exit;
}
if (req->rlen)
memcpy(req->rbuf, &state->buf[ACK_HDR_LEN], req->rlen);
exit:
mutex_unlock(&d->usb_mutex);
if (ret < 0)
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_wr_regs(struct dvb_usb_device *d, u32 reg, u8 *val, int len)
{
struct usb_interface *intf = d->intf;
u8 wbuf[MAX_XFER_SIZE];
u8 mbox = (reg >> 16) & 0xff;
struct usb_req req = { CMD_MEM_WR, mbox, 6 + len, wbuf, 0, NULL };
if (6 + len > sizeof(wbuf)) {
dev_warn(&intf->dev, "i2c wr: len=%d is too big!\n", len);
return -EOPNOTSUPP;
}
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
static int af9035_add_i2c_dev(struct dvb_usb_device *d, const char *type,
u8 addr, void *platform_data, struct i2c_adapter *adapter)
{
int ret, num;
struct state *state = d_to_priv(d);
struct usb_interface *intf = d->intf;
struct i2c_client *client;
struct i2c_board_info board_info = {
.addr = addr,
.platform_data = platform_data,
};
strlcpy(board_info.type, type, I2C_NAME_SIZE);
for (num = 0; num < AF9035_I2C_CLIENT_MAX; num++) {
if (state->i2c_client[num] == NULL)
break;
}
dev_dbg(&intf->dev, "num=%d\n", num);
if (num == AF9035_I2C_CLIENT_MAX) {
dev_err(&intf->dev, "I2C client out of index\n");
ret = -ENODEV;
goto err;
}
request_module("%s", board_info.type);
client = i2c_new_device(adapter, &board_info);
if (client == NULL || client->dev.driver == NULL) {
ret = -ENODEV;
goto err;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
ret = -ENODEV;
goto err;
}
state->i2c_client[num] = client;
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static void af9035_del_i2c_dev(struct dvb_usb_device *d)
{
int num;
struct state *state = d_to_priv(d);
struct usb_interface *intf = d->intf;
struct i2c_client *client;
num = AF9035_I2C_CLIENT_MAX;
while (num--) {
if (state->i2c_client[num] != NULL)
break;
}
dev_dbg(&intf->dev, "num=%d\n", num);
if (num == -1) {
dev_err(&intf->dev, "I2C client out of index\n");
goto err;
}
client = state->i2c_client[num];
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
state->i2c_client[num] = NULL;
return;
err:
dev_dbg(&intf->dev, "failed\n");
}
static int af9035_i2c_master_xfer(struct i2c_adapter *adap,
struct i2c_msg msg[], int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
struct state *state = d_to_priv(d);
int ret;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
#define AF9035_IS_I2C_XFER_WRITE_READ(_msg, _num) \
(_num == 2 && !(_msg[0].flags & I2C_M_RD) && (_msg[1].flags & I2C_M_RD))
#define AF9035_IS_I2C_XFER_WRITE(_msg, _num) \
(_num == 1 && !(_msg[0].flags & I2C_M_RD))
#define AF9035_IS_I2C_XFER_READ(_msg, _num) \
(_num == 1 && (_msg[0].flags & I2C_M_RD))
if (AF9035_IS_I2C_XFER_WRITE_READ(msg, num)) {
if (msg[0].len > 40 || msg[1].len > 40) {
ret = -EOPNOTSUPP;
} else if ((msg[0].addr == state->af9033_i2c_addr[0]) ||
(msg[0].addr == state->af9033_i2c_addr[1]) ||
(state->chip_type == 0x9135)) {
u32 reg = msg[0].buf[0] << 16 | msg[0].buf[1] << 8 |
msg[0].buf[2];
if (msg[0].addr == state->af9033_i2c_addr[1] ||
msg[0].addr == (state->af9033_i2c_addr[1] >> 1))
reg |= 0x100000;
ret = af9035_rd_regs(d, reg, &msg[1].buf[0],
msg[1].len);
} else if (state->no_read) {
memset(msg[1].buf, 0, msg[1].len);
ret = 0;
} else {
u8 buf[MAX_XFER_SIZE];
struct usb_req req = { CMD_I2C_RD, 0, 5 + msg[0].len,
buf, msg[1].len, msg[1].buf };
if (state->chip_type == 0x9306) {
req.cmd = CMD_GENERIC_I2C_RD;
req.wlen = 3 + msg[0].len;
}
req.mbox |= ((msg[0].addr & 0x80) >> 3);
buf[0] = msg[1].len;
if (state->chip_type == 0x9306) {
buf[1] = 0x03;
buf[2] = msg[0].addr << 1;
memcpy(&buf[3], msg[0].buf, msg[0].len);
} else {
buf[1] = msg[0].addr << 1;
buf[3] = 0x00;
buf[4] = 0x00;
if (msg[0].len > 2) {
buf[2] = 0x00;
memcpy(&buf[5], msg[0].buf, msg[0].len);
} else {
req.wlen = 5;
buf[2] = msg[0].len;
if (msg[0].len == 2) {
buf[3] = msg[0].buf[0];
buf[4] = msg[0].buf[1];
} else if (msg[0].len == 1) {
buf[4] = msg[0].buf[0];
}
}
}
ret = af9035_ctrl_msg(d, &req);
}
} else if (AF9035_IS_I2C_XFER_WRITE(msg, num)) {
if (msg[0].len > 40) {
ret = -EOPNOTSUPP;
} else if ((msg[0].addr == state->af9033_i2c_addr[0]) ||
(msg[0].addr == state->af9033_i2c_addr[1]) ||
(state->chip_type == 0x9135)) {
u32 reg = msg[0].buf[0] << 16 | msg[0].buf[1] << 8 |
msg[0].buf[2];
if (msg[0].addr == state->af9033_i2c_addr[1] ||
msg[0].addr == (state->af9033_i2c_addr[1] >> 1))
reg |= 0x100000;
ret = af9035_wr_regs(d, reg, &msg[0].buf[3],
msg[0].len - 3);
} else {
u8 buf[MAX_XFER_SIZE];
struct usb_req req = { CMD_I2C_WR, 0, 5 + msg[0].len,
buf, 0, NULL };
if (state->chip_type == 0x9306) {
req.cmd = CMD_GENERIC_I2C_WR;
req.wlen = 3 + msg[0].len;
}
req.mbox |= ((msg[0].addr & 0x80) >> 3);
buf[0] = msg[0].len;
if (state->chip_type == 0x9306) {
buf[1] = 0x03;
buf[2] = msg[0].addr << 1;
memcpy(&buf[3], msg[0].buf, msg[0].len);
} else {
buf[1] = msg[0].addr << 1;
buf[2] = 0x00;
buf[3] = 0x00;
buf[4] = 0x00;
memcpy(&buf[5], msg[0].buf, msg[0].len);
}
ret = af9035_ctrl_msg(d, &req);
}
} else if (AF9035_IS_I2C_XFER_READ(msg, num)) {
if (msg[0].len > 40) {
ret = -EOPNOTSUPP;
} else if (state->no_read) {
memset(msg[0].buf, 0, msg[0].len);
ret = 0;
} else {
u8 buf[5];
struct usb_req req = { CMD_I2C_RD, 0, sizeof(buf),
buf, msg[0].len, msg[0].buf };
if (state->chip_type == 0x9306) {
req.cmd = CMD_GENERIC_I2C_RD;
req.wlen = 3;
}
req.mbox |= ((msg[0].addr & 0x80) >> 3);
buf[0] = msg[0].len;
if (state->chip_type == 0x9306) {
buf[1] = 0x03;
buf[2] = msg[0].addr << 1;
} else {
buf[1] = msg[0].addr << 1;
buf[2] = 0x00;
buf[3] = 0x00;
buf[4] = 0x00;
}
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
struct state *state = d_to_priv(d);
struct usb_interface *intf = d->intf;
int ret, ts_mode_invalid;
u8 tmp;
u8 wbuf[1] = { 1 };
u8 rbuf[4];
struct usb_req req = { CMD_FW_QUERYINFO, 0, sizeof(wbuf), wbuf,
sizeof(rbuf), rbuf };
ret = af9035_rd_regs(d, 0x1222, rbuf, 3);
if (ret < 0)
goto err;
state->chip_version = rbuf[0];
state->chip_type = rbuf[2] << 8 | rbuf[1] << 0;
ret = af9035_rd_reg(d, 0x384f, &state->prechip_version);
if (ret < 0)
goto err;
dev_info(&intf->dev, "prechip_version=%02x chip_version=%02x chip_type=%04x\n",
state->prechip_version, state->chip_version, state->chip_type);
if (state->chip_type == 0x9135) {
if (state->chip_version == 0x02)
*name = AF9035_FIRMWARE_IT9135_V2;
else
*name = AF9035_FIRMWARE_IT9135_V1;
state->eeprom_addr = EEPROM_BASE_IT9135;
} else if (state->chip_type == 0x9306) {
*name = AF9035_FIRMWARE_IT9303;
state->eeprom_addr = EEPROM_BASE_IT9135;
} else {
*name = AF9035_FIRMWARE_AF9035;
state->eeprom_addr = EEPROM_BASE_AF9035;
}
ret = af9035_rd_reg(d, state->eeprom_addr + EEPROM_TS_MODE, &tmp);
if (ret < 0)
goto err;
ts_mode_invalid = 0;
switch (tmp) {
case 0:
break;
case 1:
case 3:
state->dual_mode = true;
break;
case 5:
if (state->chip_type != 0x9135 && state->chip_type != 0x9306)
state->dual_mode = true;
else
ts_mode_invalid = 1;
break;
default:
ts_mode_invalid = 1;
}
dev_dbg(&intf->dev, "ts mode=%d dual mode=%d\n", tmp, state->dual_mode);
if (ts_mode_invalid)
dev_info(&intf->dev, "ts mode=%d not supported, defaulting to single tuner mode!", tmp);
ret = af9035_ctrl_msg(d, &req);
if (ret < 0)
goto err;
dev_dbg(&intf->dev, "reply=%*ph\n", 4, rbuf);
if (rbuf[0] || rbuf[1] || rbuf[2] || rbuf[3])
ret = WARM;
else
ret = COLD;
return ret;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_download_firmware_old(struct dvb_usb_device *d,
const struct firmware *fw)
{
struct usb_interface *intf = d->intf;
int ret, i, j, len;
u8 wbuf[1];
struct usb_req req = { 0, 0, 0, NULL, 0, NULL };
struct usb_req req_fw_dl = { CMD_FW_DL, 0, 0, wbuf, 0, NULL };
u8 hdr_core;
u16 hdr_addr, hdr_data_len, hdr_checksum;
#define MAX_DATA 58
#define HDR_SIZE 7
for (i = fw->size; i > HDR_SIZE;) {
hdr_core = fw->data[fw->size - i + 0];
hdr_addr = fw->data[fw->size - i + 1] << 8;
hdr_addr |= fw->data[fw->size - i + 2] << 0;
hdr_data_len = fw->data[fw->size - i + 3] << 8;
hdr_data_len |= fw->data[fw->size - i + 4] << 0;
hdr_checksum = fw->data[fw->size - i + 5] << 8;
hdr_checksum |= fw->data[fw->size - i + 6] << 0;
dev_dbg(&intf->dev, "core=%d addr=%04x data_len=%d checksum=%04x\n",
hdr_core, hdr_addr, hdr_data_len, hdr_checksum);
if (((hdr_core != 1) && (hdr_core != 2)) ||
(hdr_data_len > i)) {
dev_dbg(&intf->dev, "bad firmware\n");
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
dev_dbg(&intf->dev, "data uploaded=%zu\n", fw->size - i);
}
if (i)
dev_warn(&intf->dev, "bad firmware\n");
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_download_firmware_new(struct dvb_usb_device *d,
const struct firmware *fw)
{
struct usb_interface *intf = d->intf;
int ret, i, i_prev;
struct usb_req req_fw_dl = { CMD_FW_SCATTER_WR, 0, 0, NULL, 0, NULL };
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
dev_dbg(&intf->dev, "data uploaded=%d\n", i);
}
}
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_download_firmware(struct dvb_usb_device *d,
const struct firmware *fw)
{
struct usb_interface *intf = d->intf;
struct state *state = d_to_priv(d);
int ret;
u8 wbuf[1];
u8 rbuf[4];
u8 tmp;
struct usb_req req = { 0, 0, 0, NULL, 0, NULL };
struct usb_req req_fw_ver = { CMD_FW_QUERYINFO, 0, 1, wbuf, 4, rbuf };
dev_dbg(&intf->dev, "\n");
if (state->dual_mode) {
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
ret = af9035_rd_reg(d,
state->eeprom_addr + EEPROM_2ND_DEMOD_ADDR,
&tmp);
if (ret < 0)
goto err;
if (!tmp)
tmp = 0x3a;
if ((state->chip_type == 0x9135) ||
(state->chip_type == 0x9306)) {
ret = af9035_wr_reg(d, 0x004bfb, tmp);
if (ret < 0)
goto err;
} else {
ret = af9035_wr_reg(d, 0x00417f, tmp);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0x00d81a, 0x01, 0x01);
if (ret < 0)
goto err;
}
}
if (fw->data[0] == 0x01)
ret = af9035_download_firmware_old(d, fw);
else
ret = af9035_download_firmware_new(d, fw);
if (ret < 0)
goto err;
req.cmd = CMD_FW_BOOT;
ret = af9035_ctrl_msg(d, &req);
if (ret < 0)
goto err;
wbuf[0] = 1;
ret = af9035_ctrl_msg(d, &req_fw_ver);
if (ret < 0)
goto err;
if (!(rbuf[0] || rbuf[1] || rbuf[2] || rbuf[3])) {
dev_err(&intf->dev, "firmware did not run\n");
ret = -ENODEV;
goto err;
}
dev_info(&intf->dev, "firmware version=%d.%d.%d.%d",
rbuf[0], rbuf[1], rbuf[2], rbuf[3]);
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_read_config(struct dvb_usb_device *d)
{
struct usb_interface *intf = d->intf;
struct state *state = d_to_priv(d);
int ret, i;
u8 tmp;
u16 tmp16, addr;
state->af9033_i2c_addr[0] = 0x38;
state->af9033_i2c_addr[1] = 0x3a;
state->af9033_config[0].adc_multiplier = AF9033_ADC_MULTIPLIER_2X;
state->af9033_config[1].adc_multiplier = AF9033_ADC_MULTIPLIER_2X;
state->af9033_config[0].ts_mode = AF9033_TS_MODE_USB;
state->af9033_config[1].ts_mode = AF9033_TS_MODE_SERIAL;
if (state->chip_type == 0x9135) {
state->af9033_config[0].dyn0_clk = true;
state->af9033_config[1].dyn0_clk = true;
if (state->chip_version == 0x02) {
state->af9033_config[0].tuner = AF9033_TUNER_IT9135_60;
state->af9033_config[1].tuner = AF9033_TUNER_IT9135_60;
tmp16 = 0x00461d;
} else {
state->af9033_config[0].tuner = AF9033_TUNER_IT9135_38;
state->af9033_config[1].tuner = AF9033_TUNER_IT9135_38;
tmp16 = 0x00461b;
}
ret = af9035_rd_reg(d, tmp16, &tmp);
if (ret < 0)
goto err;
if (tmp == 0x00) {
dev_dbg(&intf->dev, "no eeprom\n");
goto skip_eeprom;
}
} else if (state->chip_type == 0x9306) {
return 0;
}
if (state->dual_mode) {
ret = af9035_rd_reg(d,
state->eeprom_addr + EEPROM_2ND_DEMOD_ADDR,
&tmp);
if (ret < 0)
goto err;
if (tmp)
state->af9033_i2c_addr[1] = tmp;
dev_dbg(&intf->dev, "2nd demod I2C addr=%02x\n", tmp);
}
addr = state->eeprom_addr;
for (i = 0; i < state->dual_mode + 1; i++) {
ret = af9035_rd_reg(d, addr + EEPROM_1_TUNER_ID, &tmp);
if (ret < 0)
goto err;
dev_dbg(&intf->dev, "[%d]tuner=%02x\n", i, tmp);
if (state->chip_type == 0x9135) {
if (state->chip_version == 0x02) {
switch (tmp) {
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
state->af9033_config[i].tuner = tmp;
break;
}
} else {
switch (tmp) {
case AF9033_TUNER_IT9135_38:
case AF9033_TUNER_IT9135_51:
case AF9033_TUNER_IT9135_52:
state->af9033_config[i].tuner = tmp;
break;
}
}
} else {
state->af9033_config[i].tuner = tmp;
}
if (state->af9033_config[i].tuner != tmp) {
dev_info(&intf->dev, "[%d] overriding tuner from %02x to %02x\n",
i, tmp, state->af9033_config[i].tuner);
}
switch (state->af9033_config[i].tuner) {
case AF9033_TUNER_TUA9001:
case AF9033_TUNER_FC0011:
case AF9033_TUNER_MXL5007T:
case AF9033_TUNER_TDA18218:
case AF9033_TUNER_FC2580:
case AF9033_TUNER_FC0012:
state->af9033_config[i].spec_inv = 1;
break;
case AF9033_TUNER_IT9135_38:
case AF9033_TUNER_IT9135_51:
case AF9033_TUNER_IT9135_52:
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
break;
default:
dev_warn(&intf->dev, "tuner id=%02x not supported, please report!",
tmp);
}
if (i == 1)
switch (state->af9033_config[i].tuner) {
case AF9033_TUNER_FC0012:
case AF9033_TUNER_IT9135_38:
case AF9033_TUNER_IT9135_51:
case AF9033_TUNER_IT9135_52:
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
case AF9033_TUNER_MXL5007T:
break;
default:
state->dual_mode = false;
dev_info(&intf->dev, "driver does not support 2nd tuner and will disable it");
}
ret = af9035_rd_reg(d, addr + EEPROM_1_IF_L, &tmp);
if (ret < 0)
goto err;
tmp16 = tmp;
ret = af9035_rd_reg(d, addr + EEPROM_1_IF_H, &tmp);
if (ret < 0)
goto err;
tmp16 |= tmp << 8;
dev_dbg(&intf->dev, "[%d]IF=%d\n", i, tmp16);
addr += 0x10;
}
skip_eeprom:
ret = af9035_rd_reg(d, 0x00d800, &tmp);
if (ret < 0)
goto err;
tmp = (tmp >> 0) & 0x0f;
for (i = 0; i < ARRAY_SIZE(state->af9033_config); i++) {
if (state->chip_type == 0x9135)
state->af9033_config[i].clock = clock_lut_it9135[tmp];
else
state->af9033_config[i].clock = clock_lut_af9035[tmp];
}
state->no_read = false;
if (state->af9033_config[0].tuner == AF9033_TUNER_MXL5007T &&
le16_to_cpu(d->udev->descriptor.idVendor) == USB_VID_AVERMEDIA)
switch (le16_to_cpu(d->udev->descriptor.idProduct)) {
case USB_PID_AVERMEDIA_A867:
case USB_PID_AVERMEDIA_TWINSTAR:
dev_info(&intf->dev,
"Device may have issues with I2C read operations. Enabling fix.\n");
state->no_read = true;
break;
}
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_tua9001_tuner_callback(struct dvb_usb_device *d,
int cmd, int arg)
{
struct usb_interface *intf = d->intf;
int ret;
u8 val;
dev_dbg(&intf->dev, "cmd=%d arg=%d\n", cmd, arg);
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
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_fc0011_tuner_callback(struct dvb_usb_device *d,
int cmd, int arg)
{
struct usb_interface *intf = d->intf;
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
dev_dbg(&intf->dev, "failed=%d\n", ret);
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
struct usb_interface *intf = d->intf;
dev_dbg(&intf->dev, "component=%d cmd=%d arg=%d\n",
component, cmd, arg);
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
struct usb_interface *intf = d->intf;
int ret;
dev_dbg(&intf->dev, "adap->id=%d\n", adap->id);
if (!state->af9033_config[adap->id].tuner) {
ret = -ENODEV;
goto err;
}
state->af9033_config[adap->id].fe = &adap->fe[0];
state->af9033_config[adap->id].ops = &state->ops;
ret = af9035_add_i2c_dev(d, "af9033", state->af9033_i2c_addr[adap->id],
&state->af9033_config[adap->id], &d->i2c_adap);
if (ret)
goto err;
if (adap->fe[0] == NULL) {
ret = -ENODEV;
goto err;
}
adap->fe[0]->ops.i2c_gate_ctrl = NULL;
adap->fe[0]->callback = af9035_frontend_callback;
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int it930x_frontend_attach(struct dvb_usb_adapter *adap)
{
struct state *state = adap_to_priv(adap);
struct dvb_usb_device *d = adap_to_d(adap);
struct usb_interface *intf = d->intf;
int ret;
struct si2168_config si2168_config;
struct i2c_adapter *adapter;
dev_dbg(&intf->dev, "adap->id=%d\n", adap->id);
memset(&si2168_config, 0, sizeof(si2168_config));
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &adap->fe[0];
si2168_config.ts_mode = SI2168_TS_SERIAL;
state->af9033_config[adap->id].fe = &adap->fe[0];
state->af9033_config[adap->id].ops = &state->ops;
ret = af9035_add_i2c_dev(d, "si2168", 0x67, &si2168_config,
&d->i2c_adap);
if (ret)
goto err;
if (adap->fe[0] == NULL) {
ret = -ENODEV;
goto err;
}
state->i2c_adapter_demod = adapter;
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_frontend_detach(struct dvb_usb_adapter *adap)
{
struct state *state = adap_to_priv(adap);
struct dvb_usb_device *d = adap_to_d(adap);
struct usb_interface *intf = d->intf;
int demod2;
dev_dbg(&intf->dev, "adap->id=%d\n", adap->id);
switch (state->af9033_config[adap->id].tuner) {
case AF9033_TUNER_IT9135_38:
case AF9033_TUNER_IT9135_51:
case AF9033_TUNER_IT9135_52:
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
demod2 = 2;
break;
default:
demod2 = 1;
}
if (adap->id == 1) {
if (state->i2c_client[demod2])
af9035_del_i2c_dev(d);
} else if (adap->id == 0) {
if (state->i2c_client[0])
af9035_del_i2c_dev(d);
}
return 0;
}
static int af9035_tuner_attach(struct dvb_usb_adapter *adap)
{
struct state *state = adap_to_priv(adap);
struct dvb_usb_device *d = adap_to_d(adap);
struct usb_interface *intf = d->intf;
int ret;
struct dvb_frontend *fe;
struct i2c_msg msg[1];
u8 tuner_addr;
dev_dbg(&intf->dev, "adap->id=%d\n", adap->id);
switch (state->af9033_config[adap->id].tuner) {
case AF9033_TUNER_TUA9001: {
struct tua9001_platform_data tua9001_pdata = {
.dvb_frontend = adap->fe[0],
};
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
ret = af9035_add_i2c_dev(d, "tua9001", 0x60, &tua9001_pdata,
&d->i2c_adap);
if (ret)
goto err;
fe = adap->fe[0];
break;
}
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
case AF9033_TUNER_FC2580: {
struct fc2580_platform_data fc2580_pdata = {
.dvb_frontend = adap->fe[0],
};
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
ret = af9035_add_i2c_dev(d, "fc2580", 0x56, &fc2580_pdata,
&d->i2c_adap);
if (ret)
goto err;
fe = adap->fe[0];
break;
}
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
case AF9033_TUNER_IT9135_38:
case AF9033_TUNER_IT9135_51:
case AF9033_TUNER_IT9135_52:
{
struct it913x_config it913x_config = {
.fe = adap->fe[0],
.chip_ver = 1,
};
if (state->dual_mode) {
if (adap->id == 0)
it913x_config.role = IT913X_ROLE_DUAL_MASTER;
else
it913x_config.role = IT913X_ROLE_DUAL_SLAVE;
}
ret = af9035_add_i2c_dev(d, "it913x",
state->af9033_i2c_addr[adap->id] >> 1,
&it913x_config, &d->i2c_adap);
if (ret)
goto err;
fe = adap->fe[0];
break;
}
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
{
struct it913x_config it913x_config = {
.fe = adap->fe[0],
.chip_ver = 2,
};
if (state->dual_mode) {
if (adap->id == 0)
it913x_config.role = IT913X_ROLE_DUAL_MASTER;
else
it913x_config.role = IT913X_ROLE_DUAL_SLAVE;
}
ret = af9035_add_i2c_dev(d, "it913x",
state->af9033_i2c_addr[adap->id] >> 1,
&it913x_config, &d->i2c_adap);
if (ret)
goto err;
fe = adap->fe[0];
break;
}
default:
fe = NULL;
}
if (fe == NULL) {
ret = -ENODEV;
goto err;
}
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int it930x_tuner_attach(struct dvb_usb_adapter *adap)
{
struct state *state = adap_to_priv(adap);
struct dvb_usb_device *d = adap_to_d(adap);
struct usb_interface *intf = d->intf;
int ret;
struct si2157_config si2157_config;
dev_dbg(&intf->dev, "adap->id=%d\n", adap->id);
ret = af9035_wr_reg(d, 0x00f6a7, 0x07);
if (ret < 0)
goto err;
ret = af9035_wr_reg(d, 0x00f103, 0x07);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8d4, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8d5, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8d3, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8b8, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8b9, 0x01, 0x01);
if (ret < 0)
goto err;
ret = af9035_wr_reg_mask(d, 0xd8b7, 0x00, 0x01);
if (ret < 0)
goto err;
msleep(200);
ret = af9035_wr_reg_mask(d, 0xd8b7, 0x01, 0x01);
if (ret < 0)
goto err;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = adap->fe[0];
si2157_config.if_port = 1;
ret = af9035_add_i2c_dev(d, "si2157", 0x63,
&si2157_config, state->i2c_adapter_demod);
if (ret)
goto err;
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int it930x_tuner_detach(struct dvb_usb_adapter *adap)
{
struct state *state = adap_to_priv(adap);
struct dvb_usb_device *d = adap_to_d(adap);
struct usb_interface *intf = d->intf;
dev_dbg(&intf->dev, "adap->id=%d\n", adap->id);
if (adap->id == 1) {
if (state->i2c_client[3])
af9035_del_i2c_dev(d);
} else if (adap->id == 0) {
if (state->i2c_client[1])
af9035_del_i2c_dev(d);
}
return 0;
}
static int af9035_tuner_detach(struct dvb_usb_adapter *adap)
{
struct state *state = adap_to_priv(adap);
struct dvb_usb_device *d = adap_to_d(adap);
struct usb_interface *intf = d->intf;
dev_dbg(&intf->dev, "adap->id=%d\n", adap->id);
switch (state->af9033_config[adap->id].tuner) {
case AF9033_TUNER_TUA9001:
case AF9033_TUNER_FC2580:
case AF9033_TUNER_IT9135_38:
case AF9033_TUNER_IT9135_51:
case AF9033_TUNER_IT9135_52:
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
if (adap->id == 1) {
if (state->i2c_client[3])
af9035_del_i2c_dev(d);
} else if (adap->id == 0) {
if (state->i2c_client[1])
af9035_del_i2c_dev(d);
}
}
return 0;
}
static int af9035_init(struct dvb_usb_device *d)
{
struct state *state = d_to_priv(d);
struct usb_interface *intf = d->intf;
int ret, i;
u16 frame_size = (d->udev->speed == USB_SPEED_FULL ? 5 : 87) * 188 / 4;
u8 packet_size = (d->udev->speed == USB_SPEED_FULL ? 64 : 512) / 4;
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
dev_dbg(&intf->dev, "USB speed=%d frame_size=%04x packet_size=%02x\n",
d->udev->speed, frame_size, packet_size);
for (i = 0; i < ARRAY_SIZE(tab); i++) {
ret = af9035_wr_reg_mask(d, tab[i].reg, tab[i].val,
tab[i].mask);
if (ret < 0)
goto err;
}
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int it930x_init(struct dvb_usb_device *d)
{
struct state *state = d_to_priv(d);
struct usb_interface *intf = d->intf;
int ret, i;
u16 frame_size = (d->udev->speed == USB_SPEED_FULL ? 5 : 816) * 188 / 4;
u8 packet_size = (d->udev->speed == USB_SPEED_FULL ? 64 : 512) / 4;
struct reg_val_mask tab[] = {
{ 0x00da1a, 0x00, 0x01 },
{ 0x00f41f, 0x04, 0x04 },
{ 0x00da10, 0x00, 0x01 },
{ 0x00f41a, 0x01, 0x01 },
{ 0x00da1d, 0x01, 0x01 },
{ 0x00dd11, 0x00, 0x20 },
{ 0x00dd13, 0x00, 0x20 },
{ 0x00dd11, 0x20, 0x20 },
{ 0x00dd11, 0x00, 0x40 },
{ 0x00dd13, 0x00, 0x40 },
{ 0x00dd11, state->dual_mode << 6, 0x40 },
{ 0x00dd88, (frame_size >> 0) & 0xff, 0xff},
{ 0x00dd89, (frame_size >> 8) & 0xff, 0xff},
{ 0x00dd0c, packet_size, 0xff},
{ 0x00dd8a, (frame_size >> 0) & 0xff, 0xff},
{ 0x00dd8b, (frame_size >> 8) & 0xff, 0xff},
{ 0x00dd0d, packet_size, 0xff },
{ 0x00da1d, 0x00, 0x01 },
{ 0x00d833, 0x01, 0xff },
{ 0x00d830, 0x00, 0xff },
{ 0x00d831, 0x01, 0xff },
{ 0x00d832, 0x00, 0xff },
{ 0x00d8b0, 0x01, 0xff },
{ 0x00d8b1, 0x01, 0xff },
{ 0x00d8af, 0x00, 0xff },
{ 0x00d8c4, 0x01, 0xff },
{ 0x00d8c5, 0x01, 0xff },
{ 0x00d8c3, 0x00, 0xff },
{ 0x00d8dc, 0x01, 0xff },
{ 0x00d8dd, 0x01, 0xff },
{ 0x00d8db, 0x00, 0xff },
{ 0x00d8e4, 0x01, 0xff },
{ 0x00d8e5, 0x01, 0xff },
{ 0x00d8e3, 0x00, 0xff },
{ 0x00d8e8, 0x01, 0xff },
{ 0x00d8e9, 0x01, 0xff },
{ 0x00d8e7, 0x00, 0xff },
{ 0x00da58, 0x00, 0x01 },
{ 0x00da73, 0x01, 0xff },
{ 0x00da78, 0x47, 0xff },
{ 0x00da4c, 0x01, 0xff },
{ 0x00da5a, 0x1f, 0xff },
};
dev_dbg(&intf->dev, "USB speed=%d frame_size=%04x packet_size=%02x\n",
d->udev->speed, frame_size, packet_size);
for (i = 0; i < ARRAY_SIZE(tab); i++) {
ret = af9035_wr_reg_mask(d, tab[i].reg,
tab[i].val, tab[i].mask);
if (ret < 0)
goto err;
}
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_rc_query(struct dvb_usb_device *d)
{
struct usb_interface *intf = d->intf;
int ret;
enum rc_type proto;
u32 key;
u8 buf[4];
struct usb_req req = { CMD_IR_GET, 0, 0, NULL, 4, buf };
ret = af9035_ctrl_msg(d, &req);
if (ret == 1)
return 0;
else if (ret < 0)
goto err;
if ((buf[2] + buf[3]) == 0xff) {
if ((buf[0] + buf[1]) == 0xff) {
key = RC_SCANCODE_NEC(buf[0], buf[2]);
proto = RC_TYPE_NEC;
} else {
key = RC_SCANCODE_NECX(buf[0] << 8 | buf[1], buf[2]);
proto = RC_TYPE_NECX;
}
} else {
key = RC_SCANCODE_NEC32(buf[0] << 24 | buf[1] << 16 |
buf[2] << 8 | buf[3]);
proto = RC_TYPE_NEC32;
}
dev_dbg(&intf->dev, "%*ph\n", 4, buf);
rc_keydown(d->rc_dev, proto, key, 0);
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_get_rc_config(struct dvb_usb_device *d, struct dvb_usb_rc *rc)
{
struct state *state = d_to_priv(d);
struct usb_interface *intf = d->intf;
int ret;
u8 tmp;
ret = af9035_rd_reg(d, state->eeprom_addr + EEPROM_IR_MODE, &tmp);
if (ret < 0)
goto err;
dev_dbg(&intf->dev, "ir_mode=%02x\n", tmp);
if (tmp == 5) {
ret = af9035_rd_reg(d, state->eeprom_addr + EEPROM_IR_TYPE,
&tmp);
if (ret < 0)
goto err;
dev_dbg(&intf->dev, "ir_type=%02x\n", tmp);
switch (tmp) {
case 0:
default:
rc->allowed_protos = RC_BIT_NEC | RC_BIT_NECX |
RC_BIT_NEC32;
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
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int af9035_get_stream_config(struct dvb_frontend *fe, u8 *ts_type,
struct usb_data_stream_properties *stream)
{
struct dvb_usb_device *d = fe_to_d(fe);
struct usb_interface *intf = d->intf;
dev_dbg(&intf->dev, "adap=%d\n", fe_to_adap(fe)->id);
if (d->udev->speed == USB_SPEED_FULL)
stream->u.bulk.buffersize = 5 * 188;
return 0;
}
static int af9035_pid_filter_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct state *state = adap_to_priv(adap);
return state->ops.pid_filter_ctrl(adap->fe[0], onoff);
}
static int af9035_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid,
int onoff)
{
struct state *state = adap_to_priv(adap);
return state->ops.pid_filter(adap->fe[0], index, pid, onoff);
}
static int af9035_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
char manufacturer[sizeof("Afatech")];
memset(manufacturer, 0, sizeof(manufacturer));
usb_string(udev, udev->descriptor.iManufacturer,
manufacturer, sizeof(manufacturer));
if ((le16_to_cpu(udev->descriptor.idVendor) == USB_VID_TERRATEC) &&
(le16_to_cpu(udev->descriptor.idProduct) == 0x0099)) {
if (!strcmp("Afatech", manufacturer)) {
dev_dbg(&udev->dev, "rejecting device\n");
return -ENODEV;
}
}
return dvb_usbv2_probe(intf, id);
}
