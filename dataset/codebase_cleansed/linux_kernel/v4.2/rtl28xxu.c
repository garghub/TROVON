static int rtl28xxu_ctrl_msg(struct dvb_usb_device *d, struct rtl28xxu_req *req)
{
struct rtl28xxu_dev *dev = d->priv;
int ret;
unsigned int pipe;
u8 requesttype;
if (req->index & CMD_WR_FLAG) {
memcpy(dev->buf, req->data, req->size);
requesttype = (USB_TYPE_VENDOR | USB_DIR_OUT);
pipe = usb_sndctrlpipe(d->udev, 0);
} else {
requesttype = (USB_TYPE_VENDOR | USB_DIR_IN);
pipe = usb_rcvctrlpipe(d->udev, 0);
}
ret = usb_control_msg(d->udev, pipe, 0, requesttype, req->value,
req->index, dev->buf, req->size, 1000);
dvb_usb_dbg_usb_control_msg(d->udev, 0, requesttype, req->value,
req->index, dev->buf, req->size);
if (ret < 0)
goto err;
if (requesttype == (USB_TYPE_VENDOR | USB_DIR_IN))
memcpy(req->data, dev->buf, req->size);
return 0;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl28xxu_wr_regs(struct dvb_usb_device *d, u16 reg, u8 *val, int len)
{
struct rtl28xxu_req req;
if (reg < 0x3000)
req.index = CMD_USB_WR;
else if (reg < 0x4000)
req.index = CMD_SYS_WR;
else
req.index = CMD_IR_WR;
req.value = reg;
req.size = len;
req.data = val;
return rtl28xxu_ctrl_msg(d, &req);
}
static int rtl28xxu_rd_regs(struct dvb_usb_device *d, u16 reg, u8 *val, int len)
{
struct rtl28xxu_req req;
if (reg < 0x3000)
req.index = CMD_USB_RD;
else if (reg < 0x4000)
req.index = CMD_SYS_RD;
else
req.index = CMD_IR_RD;
req.value = reg;
req.size = len;
req.data = val;
return rtl28xxu_ctrl_msg(d, &req);
}
static int rtl28xxu_wr_reg(struct dvb_usb_device *d, u16 reg, u8 val)
{
return rtl28xxu_wr_regs(d, reg, &val, 1);
}
static int rtl28xxu_rd_reg(struct dvb_usb_device *d, u16 reg, u8 *val)
{
return rtl28xxu_rd_regs(d, reg, val, 1);
}
static int rtl28xxu_wr_reg_mask(struct dvb_usb_device *d, u16 reg, u8 val,
u8 mask)
{
int ret;
u8 tmp;
if (mask != 0xff) {
ret = rtl28xxu_rd_reg(d, reg, &tmp);
if (ret)
return ret;
val &= mask;
tmp &= ~mask;
val |= tmp;
}
return rtl28xxu_wr_reg(d, reg, val);
}
static int rtl28xxu_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
int ret;
struct dvb_usb_device *d = i2c_get_adapdata(adap);
struct rtl28xxu_dev *dev = d->priv;
struct rtl28xxu_req req;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
if (num == 2 && !(msg[0].flags & I2C_M_RD) &&
(msg[1].flags & I2C_M_RD)) {
if (msg[0].len > 24 || msg[1].len > 24) {
ret = -EOPNOTSUPP;
goto err_mutex_unlock;
} else if (msg[0].addr == 0x10) {
req.value = (msg[0].buf[0] << 8) | (msg[0].addr << 1);
req.index = CMD_DEMOD_RD | dev->page;
req.size = msg[1].len;
req.data = &msg[1].buf[0];
ret = rtl28xxu_ctrl_msg(d, &req);
} else if (msg[0].len < 2) {
req.value = (msg[0].buf[0] << 8) | (msg[0].addr << 1);
req.index = CMD_I2C_RD;
req.size = msg[1].len;
req.data = &msg[1].buf[0];
ret = rtl28xxu_ctrl_msg(d, &req);
} else {
req.value = (msg[0].addr << 1);
req.index = CMD_I2C_DA_WR;
req.size = msg[0].len;
req.data = msg[0].buf;
ret = rtl28xxu_ctrl_msg(d, &req);
if (ret)
goto err_mutex_unlock;
req.value = (msg[0].addr << 1);
req.index = CMD_I2C_DA_RD;
req.size = msg[1].len;
req.data = msg[1].buf;
ret = rtl28xxu_ctrl_msg(d, &req);
}
} else if (num == 1 && !(msg[0].flags & I2C_M_RD)) {
if (msg[0].len > 22) {
ret = -EOPNOTSUPP;
goto err_mutex_unlock;
} else if (msg[0].addr == 0x10) {
if (msg[0].buf[0] == 0x00) {
dev->page = msg[0].buf[1];
ret = 0;
} else {
req.value = (msg[0].buf[0] << 8) |
(msg[0].addr << 1);
req.index = CMD_DEMOD_WR | dev->page;
req.size = msg[0].len-1;
req.data = &msg[0].buf[1];
ret = rtl28xxu_ctrl_msg(d, &req);
}
} else if ((msg[0].len < 23) && (!dev->new_i2c_write)) {
req.value = (msg[0].buf[0] << 8) | (msg[0].addr << 1);
req.index = CMD_I2C_WR;
req.size = msg[0].len-1;
req.data = &msg[0].buf[1];
ret = rtl28xxu_ctrl_msg(d, &req);
} else {
req.value = (msg[0].addr << 1);
req.index = CMD_I2C_DA_WR;
req.size = msg[0].len;
req.data = msg[0].buf;
ret = rtl28xxu_ctrl_msg(d, &req);
}
} else if (num == 1 && (msg[0].flags & I2C_M_RD)) {
req.value = (msg[0].addr << 1);
req.index = CMD_I2C_DA_RD;
req.size = msg[0].len;
req.data = msg[0].buf;
ret = rtl28xxu_ctrl_msg(d, &req);
} else {
ret = -EOPNOTSUPP;
}
err_mutex_unlock:
mutex_unlock(&d->i2c_mutex);
return ret ? ret : num;
}
static u32 rtl28xxu_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int rtl2831u_read_config(struct dvb_usb_device *d)
{
struct rtl28xxu_dev *dev = d_to_priv(d);
int ret;
u8 buf[1];
struct rtl28xxu_req req_gate_open = {0x0120, 0x0011, 0x0001, "\x08"};
struct rtl28xxu_req req_mt2060 = {0x00c0, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_qt1010 = {0x0fc4, CMD_I2C_RD, 1, buf};
dev_dbg(&d->intf->dev, "\n");
ret = rtl28xxu_wr_reg(d, SYS_GPIO_DIR, 0x0a);
if (ret)
goto err;
ret = rtl28xxu_wr_reg(d, SYS_GPIO_OUT_EN, 0x15);
if (ret)
goto err;
msleep(20);
dev->tuner_name = "NONE";
ret = rtl28xxu_ctrl_msg(d, &req_gate_open);
if (ret)
goto err;
ret = rtl28xxu_ctrl_msg(d, &req_qt1010);
if (ret == 0 && buf[0] == 0x2c) {
dev->tuner = TUNER_RTL2830_QT1010;
dev->tuner_name = "QT1010";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_gate_open);
if (ret)
goto err;
ret = rtl28xxu_ctrl_msg(d, &req_mt2060);
if (ret == 0 && buf[0] == 0x63) {
dev->tuner = TUNER_RTL2830_MT2060;
dev->tuner_name = "MT2060";
goto found;
}
dev->tuner = TUNER_RTL2830_MXL5005S;
dev->tuner_name = "MXL5005S";
goto found;
found:
dev_dbg(&d->intf->dev, "tuner=%s\n", dev->tuner_name);
return 0;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832u_read_config(struct dvb_usb_device *d)
{
struct rtl28xxu_dev *dev = d_to_priv(d);
int ret;
u8 buf[2];
struct rtl28xxu_req req_gate_open = {0x0120, 0x0011, 0x0001, "\x18"};
struct rtl28xxu_req req_gate_close = {0x0120, 0x0011, 0x0001, "\x10"};
struct rtl28xxu_req req_fc0012 = {0x00c6, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_fc0013 = {0x00c6, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_mt2266 = {0x00c0, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_fc2580 = {0x01ac, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_mt2063 = {0x00c0, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_max3543 = {0x00c0, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_tua9001 = {0x7ec0, CMD_I2C_RD, 2, buf};
struct rtl28xxu_req req_mxl5007t = {0xd9c0, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_e4000 = {0x02c8, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_tda18272 = {0x00c0, CMD_I2C_RD, 2, buf};
struct rtl28xxu_req req_r820t = {0x0034, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_r828d = {0x0074, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_mn88472 = {0xff38, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_mn88473 = {0xff38, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_si2157 = {0x00c0, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_si2168 = {0x00c8, CMD_I2C_RD, 1, buf};
dev_dbg(&d->intf->dev, "\n");
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_DIR, 0x00, 0x40);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_EN, 0x48, 0x48);
if (ret)
goto err;
ret = rtl28xxu_ctrl_msg(d, &req_gate_open);
if (ret)
goto err;
dev->tuner_name = "NONE";
ret = rtl28xxu_ctrl_msg(d, &req_fc0012);
if (ret == 0 && buf[0] == 0xa1) {
dev->tuner = TUNER_RTL2832_FC0012;
dev->tuner_name = "FC0012";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_fc0013);
if (ret == 0 && buf[0] == 0xa3) {
dev->tuner = TUNER_RTL2832_FC0013;
dev->tuner_name = "FC0013";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_mt2266);
if (ret == 0 && buf[0] == 0x85) {
dev->tuner = TUNER_RTL2832_MT2266;
dev->tuner_name = "MT2266";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_fc2580);
if (ret == 0 && buf[0] == 0x56) {
dev->tuner = TUNER_RTL2832_FC2580;
dev->tuner_name = "FC2580";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_mt2063);
if (ret == 0 && (buf[0] == 0x9e || buf[0] == 0x9c)) {
dev->tuner = TUNER_RTL2832_MT2063;
dev->tuner_name = "MT2063";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_max3543);
if (ret == 0 && buf[0] == 0x38) {
dev->tuner = TUNER_RTL2832_MAX3543;
dev->tuner_name = "MAX3543";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_tua9001);
if (ret == 0 && buf[0] == 0x23 && buf[1] == 0x28) {
dev->tuner = TUNER_RTL2832_TUA9001;
dev->tuner_name = "TUA9001";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_mxl5007t);
if (ret == 0 && buf[0] == 0x14) {
dev->tuner = TUNER_RTL2832_MXL5007T;
dev->tuner_name = "MXL5007T";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_e4000);
if (ret == 0 && buf[0] == 0x40) {
dev->tuner = TUNER_RTL2832_E4000;
dev->tuner_name = "E4000";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_tda18272);
if (ret == 0 && (buf[0] == 0xc7 || buf[1] == 0x60)) {
dev->tuner = TUNER_RTL2832_TDA18272;
dev->tuner_name = "TDA18272";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_r820t);
if (ret == 0 && buf[0] == 0x69) {
dev->tuner = TUNER_RTL2832_R820T;
dev->tuner_name = "R820T";
goto tuner_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_r828d);
if (ret == 0 && buf[0] == 0x69) {
dev->tuner = TUNER_RTL2832_R828D;
dev->tuner_name = "R828D";
goto tuner_found;
}
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_VAL, 0x00, 0x21);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_EN, 0x00, 0x21);
if (ret)
goto err;
msleep(50);
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_VAL, 0x21, 0x21);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_EN, 0x21, 0x21);
if (ret)
goto err;
msleep(50);
ret = rtl28xxu_ctrl_msg(d, &req_si2157);
if (ret == 0 && ((buf[0] & 0x80) == 0x80)) {
dev->tuner = TUNER_RTL2832_SI2157;
dev->tuner_name = "SI2157";
goto tuner_found;
}
tuner_found:
dev_dbg(&d->intf->dev, "tuner=%s\n", dev->tuner_name);
if (dev->tuner == TUNER_RTL2832_R828D) {
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_VAL, 0x01, 0x01);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_DIR, 0x00, 0x01);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_EN, 0x01, 0x01);
if (ret)
goto err;
ret = rtl28xxu_ctrl_msg(d, &req_mn88472);
if (ret == 0 && buf[0] == 0x02) {
dev_dbg(&d->intf->dev, "MN88472 found\n");
dev->slave_demod = SLAVE_DEMOD_MN88472;
goto demod_found;
}
ret = rtl28xxu_ctrl_msg(d, &req_mn88473);
if (ret == 0 && buf[0] == 0x03) {
dev_dbg(&d->intf->dev, "MN88473 found\n");
dev->slave_demod = SLAVE_DEMOD_MN88473;
goto demod_found;
}
}
if (dev->tuner == TUNER_RTL2832_SI2157) {
ret = rtl28xxu_ctrl_msg(d, &req_si2168);
if (ret == 0 && ((buf[0] & 0x80) == 0x80)) {
dev_dbg(&d->intf->dev, "Si2168 found\n");
dev->slave_demod = SLAVE_DEMOD_SI2168;
goto demod_found;
}
}
demod_found:
ret = rtl28xxu_ctrl_msg(d, &req_gate_close);
if (ret < 0)
goto err;
return 0;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl28xxu_read_config(struct dvb_usb_device *d)
{
struct rtl28xxu_dev *dev = d_to_priv(d);
if (dev->chip_id == CHIP_ID_RTL2831U)
return rtl2831u_read_config(d);
else
return rtl2832u_read_config(d);
}
static int rtl28xxu_identify_state(struct dvb_usb_device *d, const char **name)
{
struct rtl28xxu_dev *dev = d_to_priv(d);
int ret;
struct rtl28xxu_req req_demod_i2c = {0x0020, CMD_I2C_DA_RD, 0, NULL};
dev_dbg(&d->intf->dev, "\n");
ret = rtl28xxu_ctrl_msg(d, &req_demod_i2c);
if (ret == -EPIPE) {
dev->chip_id = CHIP_ID_RTL2831U;
} else if (ret == 0) {
dev->chip_id = CHIP_ID_RTL2832U;
} else {
dev_err(&d->intf->dev, "chip type detection failed %d\n", ret);
goto err;
}
dev_dbg(&d->intf->dev, "chip_id=%u\n", dev->chip_id);
return WARM;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2831u_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_dev *dev = d_to_priv(d);
struct rtl2830_platform_data *pdata = &dev->rtl2830_platform_data;
struct i2c_board_info board_info;
struct i2c_client *client;
int ret;
dev_dbg(&d->intf->dev, "\n");
switch (dev->tuner) {
case TUNER_RTL2830_QT1010:
*pdata = rtl2830_qt1010_platform_data;
break;
case TUNER_RTL2830_MT2060:
*pdata = rtl2830_mt2060_platform_data;
break;
case TUNER_RTL2830_MXL5005S:
*pdata = rtl2830_mxl5005s_platform_data;
break;
default:
dev_err(&d->intf->dev, "unknown tuner %s\n", dev->tuner_name);
ret = -ENODEV;
goto err;
}
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "rtl2830", I2C_NAME_SIZE);
board_info.addr = 0x10;
board_info.platform_data = pdata;
request_module("%s", board_info.type);
client = i2c_new_device(&d->i2c_adap, &board_info);
if (client == NULL || client->dev.driver == NULL) {
ret = -ENODEV;
goto err;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
ret = -ENODEV;
goto err;
}
adap->fe[0] = pdata->get_dvb_frontend(client);
dev->demod_i2c_adapter = pdata->get_i2c_adapter(client);
dev->i2c_client_demod = client;
return 0;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832u_fc0012_tuner_callback(struct dvb_usb_device *d,
int cmd, int arg)
{
int ret;
u8 val;
dev_dbg(&d->intf->dev, "cmd=%d arg=%d\n", cmd, arg);
switch (cmd) {
case FC_FE_CALLBACK_VHF_ENABLE:
ret = rtl28xxu_rd_reg(d, SYS_GPIO_OUT_VAL, &val);
if (ret)
goto err;
if (arg)
val &= 0xbf;
else
val |= 0x40;
ret = rtl28xxu_wr_reg(d, SYS_GPIO_OUT_VAL, val);
if (ret)
goto err;
break;
default:
ret = -EINVAL;
goto err;
}
return 0;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832u_tua9001_tuner_callback(struct dvb_usb_device *d,
int cmd, int arg)
{
int ret;
u8 val;
dev_dbg(&d->intf->dev, "cmd=%d arg=%d\n", cmd, arg);
switch (cmd) {
case TUA9001_CMD_RESETN:
if (arg)
val = (1 << 4);
else
val = (0 << 4);
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_VAL, val, 0x10);
if (ret)
goto err;
break;
case TUA9001_CMD_RXEN:
if (arg)
val = (1 << 1);
else
val = (0 << 1);
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_VAL, val, 0x02);
if (ret)
goto err;
break;
}
return 0;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832u_frontend_callback(void *adapter_priv, int component,
int cmd, int arg)
{
struct i2c_adapter *adapter = adapter_priv;
struct device *parent = adapter->dev.parent;
struct i2c_adapter *parent_adapter;
struct dvb_usb_device *d;
struct rtl28xxu_dev *dev;
if (parent != NULL && parent->type == &i2c_adapter_type)
parent_adapter = to_i2c_adapter(parent);
else
return -EINVAL;
d = i2c_get_adapdata(parent_adapter);
dev = d->priv;
dev_dbg(&d->intf->dev, "component=%d cmd=%d arg=%d\n",
component, cmd, arg);
switch (component) {
case DVB_FRONTEND_COMPONENT_TUNER:
switch (dev->tuner) {
case TUNER_RTL2832_FC0012:
return rtl2832u_fc0012_tuner_callback(d, cmd, arg);
case TUNER_RTL2832_TUA9001:
return rtl2832u_tua9001_tuner_callback(d, cmd, arg);
}
}
return 0;
}
static int rtl2832u_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_dev *dev = d_to_priv(d);
struct rtl2832_platform_data *pdata = &dev->rtl2832_platform_data;
struct i2c_board_info board_info;
struct i2c_client *client;
int ret;
dev_dbg(&d->intf->dev, "\n");
switch (dev->tuner) {
case TUNER_RTL2832_FC0012:
*pdata = rtl2832_fc0012_platform_data;
break;
case TUNER_RTL2832_FC0013:
*pdata = rtl2832_fc0013_platform_data;
break;
case TUNER_RTL2832_FC2580:
*pdata = rtl2832_fc2580_platform_data;
break;
case TUNER_RTL2832_TUA9001:
*pdata = rtl2832_tua9001_platform_data;
break;
case TUNER_RTL2832_E4000:
*pdata = rtl2832_e4000_platform_data;
break;
case TUNER_RTL2832_R820T:
case TUNER_RTL2832_R828D:
*pdata = rtl2832_r820t_platform_data;
break;
case TUNER_RTL2832_SI2157:
*pdata = rtl2832_si2157_platform_data;
break;
default:
dev_err(&d->intf->dev, "unknown tuner %s\n", dev->tuner_name);
ret = -ENODEV;
goto err;
}
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "rtl2832", I2C_NAME_SIZE);
board_info.addr = 0x10;
board_info.platform_data = pdata;
request_module("%s", board_info.type);
client = i2c_new_device(&d->i2c_adap, &board_info);
if (client == NULL || client->dev.driver == NULL) {
ret = -ENODEV;
goto err;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
ret = -ENODEV;
goto err;
}
adap->fe[0] = pdata->get_dvb_frontend(client);
dev->demod_i2c_adapter = pdata->get_i2c_adapter(client);
dev->i2c_client_demod = client;
adap->fe[0]->callback = rtl2832u_frontend_callback;
if (dev->slave_demod) {
struct i2c_board_info info = {};
ret = 0;
if (dev->slave_demod == SLAVE_DEMOD_MN88472) {
struct mn88472_config mn88472_config = {};
mn88472_config.fe = &adap->fe[1];
mn88472_config.i2c_wr_max = 22,
strlcpy(info.type, "mn88472", I2C_NAME_SIZE);
mn88472_config.xtal = 20500000;
mn88472_config.ts_mode = SERIAL_TS_MODE;
mn88472_config.ts_clock = VARIABLE_TS_CLOCK;
info.addr = 0x18;
info.platform_data = &mn88472_config;
request_module(info.type);
client = i2c_new_device(&d->i2c_adap, &info);
if (client == NULL || client->dev.driver == NULL) {
dev->slave_demod = SLAVE_DEMOD_NONE;
goto err_slave_demod_failed;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
dev->slave_demod = SLAVE_DEMOD_NONE;
goto err_slave_demod_failed;
}
dev->i2c_client_slave_demod = client;
} else if (dev->slave_demod == SLAVE_DEMOD_MN88473) {
struct mn88473_config mn88473_config = {};
mn88473_config.fe = &adap->fe[1];
mn88473_config.i2c_wr_max = 22,
strlcpy(info.type, "mn88473", I2C_NAME_SIZE);
info.addr = 0x18;
info.platform_data = &mn88473_config;
request_module(info.type);
client = i2c_new_device(&d->i2c_adap, &info);
if (client == NULL || client->dev.driver == NULL) {
dev->slave_demod = SLAVE_DEMOD_NONE;
goto err_slave_demod_failed;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
dev->slave_demod = SLAVE_DEMOD_NONE;
goto err_slave_demod_failed;
}
dev->i2c_client_slave_demod = client;
} else {
struct si2168_config si2168_config = {};
struct i2c_adapter *adapter;
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &adap->fe[1];
si2168_config.ts_mode = SI2168_TS_SERIAL;
si2168_config.ts_clock_inv = false;
si2168_config.ts_clock_gapped = true;
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2168_config;
request_module(info.type);
client = i2c_new_device(&d->i2c_adap, &info);
if (client == NULL || client->dev.driver == NULL) {
dev->slave_demod = SLAVE_DEMOD_NONE;
goto err_slave_demod_failed;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
dev->slave_demod = SLAVE_DEMOD_NONE;
goto err_slave_demod_failed;
}
dev->i2c_client_slave_demod = client;
dev->new_i2c_write = true;
}
}
return 0;
err_slave_demod_failed:
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl28xxu_frontend_attach(struct dvb_usb_adapter *adap)
{
struct rtl28xxu_dev *dev = adap_to_priv(adap);
if (dev->chip_id == CHIP_ID_RTL2831U)
return rtl2831u_frontend_attach(adap);
else
return rtl2832u_frontend_attach(adap);
}
static int rtl28xxu_frontend_detach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_dev *dev = d_to_priv(d);
struct i2c_client *client;
dev_dbg(&d->intf->dev, "\n");
client = dev->i2c_client_slave_demod;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
client = dev->i2c_client_demod;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
return 0;
}
static int rtl2831u_tuner_attach(struct dvb_usb_adapter *adap)
{
int ret;
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_dev *dev = d_to_priv(d);
struct dvb_frontend *fe;
dev_dbg(&d->intf->dev, "\n");
switch (dev->tuner) {
case TUNER_RTL2830_QT1010:
fe = dvb_attach(qt1010_attach, adap->fe[0],
dev->demod_i2c_adapter,
&rtl28xxu_qt1010_config);
break;
case TUNER_RTL2830_MT2060:
fe = dvb_attach(mt2060_attach, adap->fe[0],
dev->demod_i2c_adapter,
&rtl28xxu_mt2060_config, 1220);
break;
case TUNER_RTL2830_MXL5005S:
fe = dvb_attach(mxl5005s_attach, adap->fe[0],
dev->demod_i2c_adapter,
&rtl28xxu_mxl5005s_config);
break;
default:
fe = NULL;
dev_err(&d->intf->dev, "unknown tuner %d\n", dev->tuner);
}
if (fe == NULL) {
ret = -ENODEV;
goto err;
}
return 0;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832u_tuner_attach(struct dvb_usb_adapter *adap)
{
int ret;
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_dev *dev = d_to_priv(d);
struct dvb_frontend *fe = NULL;
struct i2c_board_info info;
struct i2c_client *client;
struct v4l2_subdev *subdev = NULL;
struct platform_device *pdev;
struct rtl2832_sdr_platform_data pdata;
dev_dbg(&d->intf->dev, "\n");
memset(&info, 0, sizeof(struct i2c_board_info));
memset(&pdata, 0, sizeof(pdata));
switch (dev->tuner) {
case TUNER_RTL2832_FC0012:
fe = dvb_attach(fc0012_attach, adap->fe[0],
dev->demod_i2c_adapter, &rtl2832u_fc0012_config);
adap->fe[0]->ops.read_signal_strength =
adap->fe[0]->ops.tuner_ops.get_rf_strength;
break;
case TUNER_RTL2832_FC0013:
fe = dvb_attach(fc0013_attach, adap->fe[0],
dev->demod_i2c_adapter, 0xc6>>1, 0, FC_XTAL_28_8_MHZ);
adap->fe[0]->ops.read_signal_strength =
adap->fe[0]->ops.tuner_ops.get_rf_strength;
break;
case TUNER_RTL2832_E4000: {
struct e4000_config e4000_config = {
.fe = adap->fe[0],
.clock = 28800000,
};
strlcpy(info.type, "e4000", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &e4000_config;
request_module(info.type);
client = i2c_new_device(dev->demod_i2c_adapter, &info);
if (client == NULL || client->dev.driver == NULL)
break;
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
break;
}
dev->i2c_client_tuner = client;
subdev = i2c_get_clientdata(client);
}
break;
case TUNER_RTL2832_FC2580: {
struct fc2580_platform_data fc2580_pdata = {
.dvb_frontend = adap->fe[0],
};
struct i2c_board_info board_info = {};
strlcpy(board_info.type, "fc2580", I2C_NAME_SIZE);
board_info.addr = 0x56;
board_info.platform_data = &fc2580_pdata;
request_module("fc2580");
client = i2c_new_device(dev->demod_i2c_adapter,
&board_info);
if (client == NULL || client->dev.driver == NULL)
break;
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
break;
}
dev->i2c_client_tuner = client;
subdev = fc2580_pdata.get_v4l2_subdev(client);
}
break;
case TUNER_RTL2832_TUA9001: {
struct tua9001_platform_data tua9001_pdata = {
.dvb_frontend = adap->fe[0],
};
struct i2c_board_info board_info = {};
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_DIR, 0x00, 0x12);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_EN, 0x12, 0x12);
if (ret)
goto err;
strlcpy(board_info.type, "tua9001", I2C_NAME_SIZE);
board_info.addr = 0x60;
board_info.platform_data = &tua9001_pdata;
request_module("tua9001");
client = i2c_new_device(dev->demod_i2c_adapter, &board_info);
if (client == NULL || client->dev.driver == NULL)
break;
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
break;
}
dev->i2c_client_tuner = client;
break;
}
case TUNER_RTL2832_R820T:
fe = dvb_attach(r820t_attach, adap->fe[0],
dev->demod_i2c_adapter,
&rtl2832u_r820t_config);
adap->fe[0]->ops.read_signal_strength =
adap->fe[0]->ops.tuner_ops.get_rf_strength;
break;
case TUNER_RTL2832_R828D:
fe = dvb_attach(r820t_attach, adap->fe[0],
dev->demod_i2c_adapter,
&rtl2832u_r828d_config);
adap->fe[0]->ops.read_signal_strength =
adap->fe[0]->ops.tuner_ops.get_rf_strength;
if (adap->fe[1]) {
fe = dvb_attach(r820t_attach, adap->fe[1],
dev->demod_i2c_adapter,
&rtl2832u_r828d_config);
adap->fe[1]->ops.read_signal_strength =
adap->fe[1]->ops.tuner_ops.get_rf_strength;
}
break;
case TUNER_RTL2832_SI2157: {
struct si2157_config si2157_config = {
.fe = adap->fe[0],
.if_port = 0,
.inversion = false,
};
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module(info.type);
client = i2c_new_device(&d->i2c_adap, &info);
if (client == NULL || client->dev.driver == NULL)
break;
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
break;
}
dev->i2c_client_tuner = client;
subdev = i2c_get_clientdata(client);
if (adap->fe[1]) {
adap->fe[1]->tuner_priv =
adap->fe[0]->tuner_priv;
memcpy(&adap->fe[1]->ops.tuner_ops,
&adap->fe[0]->ops.tuner_ops,
sizeof(struct dvb_tuner_ops));
}
}
break;
default:
dev_err(&d->intf->dev, "unknown tuner %d\n", dev->tuner);
}
if (fe == NULL && dev->i2c_client_tuner == NULL) {
ret = -ENODEV;
goto err;
}
switch (dev->tuner) {
case TUNER_RTL2832_FC2580:
case TUNER_RTL2832_FC0012:
case TUNER_RTL2832_FC0013:
case TUNER_RTL2832_E4000:
case TUNER_RTL2832_R820T:
case TUNER_RTL2832_R828D:
pdata.clk = dev->rtl2832_platform_data.clk;
pdata.tuner = dev->tuner;
pdata.i2c_client = dev->i2c_client_demod;
pdata.bulk_read = dev->rtl2832_platform_data.bulk_read;
pdata.bulk_write = dev->rtl2832_platform_data.bulk_write;
pdata.update_bits = dev->rtl2832_platform_data.update_bits;
pdata.dvb_frontend = adap->fe[0];
pdata.dvb_usb_device = d;
pdata.v4l2_subdev = subdev;
request_module("%s", "rtl2832_sdr");
pdev = platform_device_register_data(&d->intf->dev,
"rtl2832_sdr",
PLATFORM_DEVID_AUTO,
&pdata, sizeof(pdata));
if (IS_ERR(pdev) || pdev->dev.driver == NULL)
break;
dev->platform_device_sdr = pdev;
break;
default:
dev_dbg(&d->intf->dev, "no SDR for tuner=%d\n", dev->tuner);
}
return 0;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl28xxu_tuner_attach(struct dvb_usb_adapter *adap)
{
struct rtl28xxu_dev *dev = adap_to_priv(adap);
if (dev->chip_id == CHIP_ID_RTL2831U)
return rtl2831u_tuner_attach(adap);
else
return rtl2832u_tuner_attach(adap);
}
static int rtl28xxu_tuner_detach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_dev *dev = d_to_priv(d);
struct i2c_client *client;
struct platform_device *pdev;
dev_dbg(&d->intf->dev, "\n");
pdev = dev->platform_device_sdr;
if (pdev)
platform_device_unregister(pdev);
client = dev->i2c_client_tuner;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
return 0;
}
static int rtl28xxu_init(struct dvb_usb_device *d)
{
int ret;
u8 val;
dev_dbg(&d->intf->dev, "\n");
ret = rtl28xxu_rd_reg(d, USB_SYSCTL_0, &val);
if (ret)
goto err;
val |= 0x09;
ret = rtl28xxu_wr_reg(d, USB_SYSCTL_0, val);
if (ret)
goto err;
ret = rtl28xxu_wr_regs(d, USB_EPA_MAXPKT, "\x00\x02\x00\x00", 4);
if (ret)
goto err;
ret = rtl28xxu_wr_regs(d, USB_EPA_FIFO_CFG, "\x14\x00\x00\x00", 4);
if (ret)
goto err;
return ret;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2831u_power_ctrl(struct dvb_usb_device *d, int onoff)
{
int ret;
u8 gpio, sys0, epa_ctl[2];
dev_dbg(&d->intf->dev, "onoff=%d\n", onoff);
ret = rtl28xxu_rd_reg(d, SYS_SYS0, &sys0);
if (ret)
goto err;
ret = rtl28xxu_rd_reg(d, SYS_GPIO_OUT_VAL, &gpio);
if (ret)
goto err;
dev_dbg(&d->intf->dev, "RD SYS0=%02x GPIO_OUT_VAL=%02x\n", sys0, gpio);
if (onoff) {
gpio |= 0x01;
gpio &= (~0x10);
gpio |= 0x04;
sys0 = sys0 & 0x0f;
sys0 |= 0xe0;
epa_ctl[0] = 0x00;
epa_ctl[1] = 0x00;
} else {
gpio &= (~0x01);
gpio |= 0x10;
gpio &= (~0x04);
sys0 = sys0 & (~0xc0);
epa_ctl[0] = 0x10;
epa_ctl[1] = 0x02;
}
dev_dbg(&d->intf->dev, "WR SYS0=%02x GPIO_OUT_VAL=%02x\n", sys0, gpio);
ret = rtl28xxu_wr_reg(d, SYS_SYS0, sys0);
if (ret)
goto err;
ret = rtl28xxu_wr_reg(d, SYS_GPIO_OUT_VAL, gpio);
if (ret)
goto err;
ret = rtl28xxu_wr_regs(d, USB_EPA_CTL, epa_ctl, 2);
if (ret)
goto err;
if (onoff)
usb_clear_halt(d->udev, usb_rcvbulkpipe(d->udev, 0x81));
return ret;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832u_power_ctrl(struct dvb_usb_device *d, int onoff)
{
int ret;
dev_dbg(&d->intf->dev, "onoff=%d\n", onoff);
if (onoff) {
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_VAL, 0x08, 0x18);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_DEMOD_CTL1, 0x00, 0x10);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_DEMOD_CTL, 0x80, 0x80);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_DEMOD_CTL, 0x20, 0x20);
if (ret)
goto err;
ret = rtl28xxu_wr_regs(d, USB_EPA_CTL, "\x00\x00", 2);
if (ret)
goto err;
ret = usb_clear_halt(d->udev, usb_rcvbulkpipe(d->udev, 0x81));
if (ret)
goto err;
} else {
ret = rtl28xxu_wr_reg_mask(d, SYS_GPIO_OUT_VAL, 0x10, 0x10);
if (ret)
goto err;
ret = rtl28xxu_wr_reg_mask(d, SYS_DEMOD_CTL, 0x00, 0x80);
if (ret)
goto err;
ret = rtl28xxu_wr_regs(d, USB_EPA_CTL, "\x10\x02", 2);
if (ret)
goto err;
}
return ret;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl28xxu_power_ctrl(struct dvb_usb_device *d, int onoff)
{
struct rtl28xxu_dev *dev = d_to_priv(d);
if (dev->chip_id == CHIP_ID_RTL2831U)
return rtl2831u_power_ctrl(d, onoff);
else
return rtl2832u_power_ctrl(d, onoff);
}
static int rtl28xxu_frontend_ctrl(struct dvb_frontend *fe, int onoff)
{
struct dvb_usb_device *d = fe_to_d(fe);
struct rtl28xxu_dev *dev = fe_to_priv(fe);
struct rtl2832_platform_data *pdata = &dev->rtl2832_platform_data;
int ret;
u8 val;
dev_dbg(&d->intf->dev, "fe=%d onoff=%d\n", fe->id, onoff);
if (dev->chip_id == CHIP_ID_RTL2831U)
return 0;
if (fe->id == 0 && onoff)
val = 0x48;
else
val = 0x00;
ret = rtl28xxu_wr_reg_mask(d, SYS_DEMOD_CTL, val, 0x48);
if (ret)
goto err;
if (fe->id == 1 && onoff) {
ret = pdata->enable_slave_ts(dev->i2c_client_demod);
if (ret)
goto err;
}
return 0;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2831u_rc_query(struct dvb_usb_device *d)
{
int ret, i;
struct rtl28xxu_dev *dev = d->priv;
u8 buf[5];
u32 rc_code;
struct rtl28xxu_reg_val rc_nec_tab[] = {
{ 0x3033, 0x80 },
{ 0x3020, 0x43 },
{ 0x3021, 0x16 },
{ 0x3022, 0x16 },
{ 0x3023, 0x5a },
{ 0x3024, 0x2d },
{ 0x3025, 0x16 },
{ 0x3026, 0x01 },
{ 0x3028, 0xb0 },
{ 0x3029, 0x04 },
{ 0x302c, 0x88 },
{ 0x302e, 0x13 },
{ 0x3030, 0xdf },
{ 0x3031, 0x05 },
};
if (!dev->rc_active) {
for (i = 0; i < ARRAY_SIZE(rc_nec_tab); i++) {
ret = rtl28xxu_wr_reg(d, rc_nec_tab[i].reg,
rc_nec_tab[i].val);
if (ret)
goto err;
}
dev->rc_active = true;
}
ret = rtl28xxu_rd_regs(d, SYS_IRRC_RP, buf, 5);
if (ret)
goto err;
if (buf[4] & 0x01) {
if (buf[2] == (u8) ~buf[3]) {
if (buf[0] == (u8) ~buf[1]) {
rc_code = RC_SCANCODE_NEC(buf[0], buf[2]);
} else {
rc_code = RC_SCANCODE_NECX(buf[0] << 8 | buf[1],
buf[2]);
}
} else {
rc_code = RC_SCANCODE_NEC32(buf[0] << 24 | buf[1] << 16 |
buf[2] << 8 | buf[3]);
}
rc_keydown(d->rc_dev, RC_TYPE_NEC, rc_code, 0);
ret = rtl28xxu_wr_reg(d, SYS_IRRC_SR, 1);
if (ret)
goto err;
ret = rtl28xxu_wr_reg(d, SYS_IRRC_SR, 1);
if (ret)
goto err;
}
return ret;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2831u_get_rc_config(struct dvb_usb_device *d,
struct dvb_usb_rc *rc)
{
rc->map_name = RC_MAP_EMPTY;
rc->allowed_protos = RC_BIT_NEC;
rc->query = rtl2831u_rc_query;
rc->interval = 400;
return 0;
}
static int rtl2832u_rc_query(struct dvb_usb_device *d)
{
int ret, i, len;
struct rtl28xxu_dev *dev = d->priv;
struct ir_raw_event ev;
u8 buf[128];
static const struct rtl28xxu_reg_val_mask refresh_tab[] = {
{IR_RX_IF, 0x03, 0xff},
{IR_RX_BUF_CTRL, 0x80, 0xff},
{IR_RX_CTRL, 0x80, 0xff},
};
if (!dev->rc_active) {
static const struct rtl28xxu_reg_val_mask init_tab[] = {
{SYS_DEMOD_CTL1, 0x00, 0x04},
{SYS_DEMOD_CTL1, 0x00, 0x08},
{USB_CTRL, 0x20, 0x20},
{SYS_GPIO_DIR, 0x00, 0x08},
{SYS_GPIO_OUT_EN, 0x08, 0x08},
{SYS_GPIO_OUT_VAL, 0x08, 0x08},
{IR_MAX_DURATION0, 0xd0, 0xff},
{IR_MAX_DURATION1, 0x07, 0xff},
{IR_IDLE_LEN0, 0xc0, 0xff},
{IR_IDLE_LEN1, 0x00, 0xff},
{IR_GLITCH_LEN, 0x03, 0xff},
{IR_RX_CLK, 0x09, 0xff},
{IR_RX_CFG, 0x1c, 0xff},
{IR_MAX_H_TOL_LEN, 0x1e, 0xff},
{IR_MAX_L_TOL_LEN, 0x1e, 0xff},
{IR_RX_CTRL, 0x80, 0xff},
};
for (i = 0; i < ARRAY_SIZE(init_tab); i++) {
ret = rtl28xxu_wr_reg_mask(d, init_tab[i].reg,
init_tab[i].val, init_tab[i].mask);
if (ret)
goto err;
}
dev->rc_active = true;
}
ret = rtl28xxu_rd_reg(d, IR_RX_IF, &buf[0]);
if (ret)
goto err;
if (buf[0] != 0x83)
goto exit;
ret = rtl28xxu_rd_reg(d, IR_RX_BC, &buf[0]);
if (ret)
goto err;
len = buf[0];
ret = rtl28xxu_rd_regs(d, IR_RX_BUF, buf, len);
if (ret)
goto err;
for (i = 0; i < ARRAY_SIZE(refresh_tab); i++) {
ret = rtl28xxu_wr_reg_mask(d, refresh_tab[i].reg,
refresh_tab[i].val, refresh_tab[i].mask);
if (ret)
goto err;
}
init_ir_raw_event(&ev);
for (i = 0; i < len; i++) {
ev.pulse = buf[i] >> 7;
ev.duration = 50800 * (buf[i] & 0x7f);
ir_raw_event_store_with_filter(d->rc_dev, &ev);
}
ir_raw_event_set_idle(d->rc_dev, true);
ir_raw_event_handle(d->rc_dev);
exit:
return ret;
err:
dev_dbg(&d->intf->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832u_get_rc_config(struct dvb_usb_device *d,
struct dvb_usb_rc *rc)
{
if (rtl28xxu_disable_rc)
return rtl28xxu_wr_reg(d, IR_RX_IE, 0x00);
if (!rc->map_name)
rc->map_name = RC_MAP_EMPTY;
rc->allowed_protos = RC_BIT_ALL;
rc->driver_type = RC_DRIVER_IR_RAW;
rc->query = rtl2832u_rc_query;
rc->interval = 200;
return 0;
}
static int rtl28xxu_get_rc_config(struct dvb_usb_device *d,
struct dvb_usb_rc *rc)
{
struct rtl28xxu_dev *dev = d_to_priv(d);
if (dev->chip_id == CHIP_ID_RTL2831U)
return rtl2831u_get_rc_config(d, rc);
else
return rtl2832u_get_rc_config(d, rc);
}
static int rtl28xxu_pid_filter_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct rtl28xxu_dev *dev = adap_to_priv(adap);
if (dev->chip_id == CHIP_ID_RTL2831U) {
struct rtl2830_platform_data *pdata = &dev->rtl2830_platform_data;
return pdata->pid_filter_ctrl(adap->fe[0], onoff);
} else {
struct rtl2832_platform_data *pdata = &dev->rtl2832_platform_data;
return pdata->pid_filter_ctrl(adap->fe[0], onoff);
}
}
static int rtl28xxu_pid_filter(struct dvb_usb_adapter *adap, int index,
u16 pid, int onoff)
{
struct rtl28xxu_dev *dev = adap_to_priv(adap);
if (dev->chip_id == CHIP_ID_RTL2831U) {
struct rtl2830_platform_data *pdata = &dev->rtl2830_platform_data;
return pdata->pid_filter(adap->fe[0], index, pid, onoff);
} else {
struct rtl2832_platform_data *pdata = &dev->rtl2832_platform_data;
return pdata->pid_filter(adap->fe[0], index, pid, onoff);
}
}
