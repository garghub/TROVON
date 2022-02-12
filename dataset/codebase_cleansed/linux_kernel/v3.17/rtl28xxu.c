static inline struct dvb_frontend *rtl2832_sdr_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c, const struct rtl2832_config *cfg,
struct v4l2_subdev *sd)
{
return NULL;
}
static int rtl28xxu_ctrl_msg(struct dvb_usb_device *d, struct rtl28xxu_req *req)
{
int ret;
unsigned int pipe;
u8 requesttype;
u8 *buf;
buf = kmalloc(req->size, GFP_KERNEL);
if (!buf) {
ret = -ENOMEM;
goto err;
}
if (req->index & CMD_WR_FLAG) {
memcpy(buf, req->data, req->size);
requesttype = (USB_TYPE_VENDOR | USB_DIR_OUT);
pipe = usb_sndctrlpipe(d->udev, 0);
} else {
requesttype = (USB_TYPE_VENDOR | USB_DIR_IN);
pipe = usb_rcvctrlpipe(d->udev, 0);
}
ret = usb_control_msg(d->udev, pipe, 0, requesttype, req->value,
req->index, buf, req->size, 1000);
dvb_usb_dbg_usb_control_msg(d->udev, 0, requesttype, req->value,
req->index, buf, req->size);
if (ret > 0)
ret = 0;
if (!ret && requesttype == (USB_TYPE_VENDOR | USB_DIR_IN))
memcpy(req->data, buf, req->size);
kfree(buf);
if (ret)
goto err;
return ret;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl28xx_wr_regs(struct dvb_usb_device *d, u16 reg, u8 *val, int len)
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
static int rtl2831_rd_regs(struct dvb_usb_device *d, u16 reg, u8 *val, int len)
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
static int rtl28xx_wr_reg(struct dvb_usb_device *d, u16 reg, u8 val)
{
return rtl28xx_wr_regs(d, reg, &val, 1);
}
static int rtl28xx_rd_reg(struct dvb_usb_device *d, u16 reg, u8 *val)
{
return rtl2831_rd_regs(d, reg, val, 1);
}
static int rtl28xx_wr_reg_mask(struct dvb_usb_device *d, u16 reg, u8 val,
u8 mask)
{
int ret;
u8 tmp;
if (mask != 0xff) {
ret = rtl28xx_rd_reg(d, reg, &tmp);
if (ret)
return ret;
val &= mask;
tmp &= ~mask;
val |= tmp;
}
return rtl28xx_wr_reg(d, reg, val);
}
static int rtl28xxu_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
int ret;
struct dvb_usb_device *d = i2c_get_adapdata(adap);
struct rtl28xxu_priv *priv = d->priv;
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
req.index = CMD_DEMOD_RD | priv->page;
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
priv->page = msg[0].buf[1];
ret = 0;
} else {
req.value = (msg[0].buf[0] << 8) |
(msg[0].addr << 1);
req.index = CMD_DEMOD_WR | priv->page;
req.size = msg[0].len-1;
req.data = &msg[0].buf[1];
ret = rtl28xxu_ctrl_msg(d, &req);
}
} else if (msg[0].len < 23) {
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
} else {
ret = -EINVAL;
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
struct rtl28xxu_priv *priv = d_to_priv(d);
int ret;
u8 buf[1];
struct rtl28xxu_req req_gate_open = {0x0120, 0x0011, 0x0001, "\x08"};
struct rtl28xxu_req req_mt2060 = {0x00c0, CMD_I2C_RD, 1, buf};
struct rtl28xxu_req req_qt1010 = {0x0fc4, CMD_I2C_RD, 1, buf};
dev_dbg(&d->udev->dev, "%s:\n", __func__);
ret = rtl28xx_wr_reg(d, SYS_GPIO_DIR, 0x0a);
if (ret)
goto err;
ret = rtl28xx_wr_reg(d, SYS_GPIO_OUT_EN, 0x15);
if (ret)
goto err;
msleep(20);
priv->tuner_name = "NONE";
ret = rtl28xxu_ctrl_msg(d, &req_gate_open);
if (ret)
goto err;
ret = rtl28xxu_ctrl_msg(d, &req_qt1010);
if (ret == 0 && buf[0] == 0x2c) {
priv->tuner = TUNER_RTL2830_QT1010;
priv->tuner_name = "QT1010";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_gate_open);
if (ret)
goto err;
ret = rtl28xxu_ctrl_msg(d, &req_mt2060);
if (ret == 0 && buf[0] == 0x63) {
priv->tuner = TUNER_RTL2830_MT2060;
priv->tuner_name = "MT2060";
goto found;
}
priv->tuner = TUNER_RTL2830_MXL5005S;
priv->tuner_name = "MXL5005S";
goto found;
found:
dev_dbg(&d->udev->dev, "%s: tuner=%s\n", __func__, priv->tuner_name);
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832u_read_config(struct dvb_usb_device *d)
{
struct rtl28xxu_priv *priv = d_to_priv(d);
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
dev_dbg(&d->udev->dev, "%s:\n", __func__);
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_DIR, 0x00, 0x40);
if (ret)
goto err;
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_OUT_EN, 0x48, 0x48);
if (ret)
goto err;
ret = rtl28xxu_ctrl_msg(d, &req_gate_open);
if (ret)
goto err;
priv->tuner_name = "NONE";
ret = rtl28xxu_ctrl_msg(d, &req_fc0012);
if (ret == 0 && buf[0] == 0xa1) {
priv->tuner = TUNER_RTL2832_FC0012;
priv->tuner_name = "FC0012";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_fc0013);
if (ret == 0 && buf[0] == 0xa3) {
priv->tuner = TUNER_RTL2832_FC0013;
priv->tuner_name = "FC0013";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_mt2266);
if (ret == 0 && buf[0] == 0x85) {
priv->tuner = TUNER_RTL2832_MT2266;
priv->tuner_name = "MT2266";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_fc2580);
if (ret == 0 && buf[0] == 0x56) {
priv->tuner = TUNER_RTL2832_FC2580;
priv->tuner_name = "FC2580";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_mt2063);
if (ret == 0 && (buf[0] == 0x9e || buf[0] == 0x9c)) {
priv->tuner = TUNER_RTL2832_MT2063;
priv->tuner_name = "MT2063";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_max3543);
if (ret == 0 && buf[0] == 0x38) {
priv->tuner = TUNER_RTL2832_MAX3543;
priv->tuner_name = "MAX3543";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_tua9001);
if (ret == 0 && buf[0] == 0x23 && buf[1] == 0x28) {
priv->tuner = TUNER_RTL2832_TUA9001;
priv->tuner_name = "TUA9001";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_mxl5007t);
if (ret == 0 && buf[0] == 0x14) {
priv->tuner = TUNER_RTL2832_MXL5007T;
priv->tuner_name = "MXL5007T";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_e4000);
if (ret == 0 && buf[0] == 0x40) {
priv->tuner = TUNER_RTL2832_E4000;
priv->tuner_name = "E4000";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_tda18272);
if (ret == 0 && (buf[0] == 0xc7 || buf[1] == 0x60)) {
priv->tuner = TUNER_RTL2832_TDA18272;
priv->tuner_name = "TDA18272";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_r820t);
if (ret == 0 && buf[0] == 0x69) {
priv->tuner = TUNER_RTL2832_R820T;
priv->tuner_name = "R820T";
goto found;
}
ret = rtl28xxu_ctrl_msg(d, &req_r828d);
if (ret == 0 && buf[0] == 0x69) {
priv->tuner = TUNER_RTL2832_R828D;
priv->tuner_name = "R828D";
goto found;
}
found:
dev_dbg(&d->udev->dev, "%s: tuner=%s\n", __func__, priv->tuner_name);
ret = rtl28xxu_ctrl_msg(d, &req_gate_close);
if (ret < 0)
goto err;
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2831u_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_priv *priv = d_to_priv(d);
const struct rtl2830_config *rtl2830_config;
int ret;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
switch (priv->tuner) {
case TUNER_RTL2830_QT1010:
rtl2830_config = &rtl28xxu_rtl2830_qt1010_config;
break;
case TUNER_RTL2830_MT2060:
rtl2830_config = &rtl28xxu_rtl2830_mt2060_config;
break;
case TUNER_RTL2830_MXL5005S:
rtl2830_config = &rtl28xxu_rtl2830_mxl5005s_config;
break;
default:
dev_err(&d->udev->dev, "%s: unknown tuner=%s\n",
KBUILD_MODNAME, priv->tuner_name);
ret = -ENODEV;
goto err;
}
adap->fe[0] = dvb_attach(rtl2830_attach, rtl2830_config, &d->i2c_adap);
if (!adap->fe[0]) {
ret = -ENODEV;
goto err;
}
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832u_fc0012_tuner_callback(struct dvb_usb_device *d,
int cmd, int arg)
{
int ret;
u8 val;
dev_dbg(&d->udev->dev, "%s: cmd=%d arg=%d\n", __func__, cmd, arg);
switch (cmd) {
case FC_FE_CALLBACK_VHF_ENABLE:
ret = rtl28xx_rd_reg(d, SYS_GPIO_OUT_VAL, &val);
if (ret)
goto err;
if (arg)
val &= 0xbf;
else
val |= 0x40;
ret = rtl28xx_wr_reg(d, SYS_GPIO_OUT_VAL, val);
if (ret)
goto err;
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
static int rtl2832u_tua9001_tuner_callback(struct dvb_usb_device *d,
int cmd, int arg)
{
int ret;
u8 val;
dev_dbg(&d->udev->dev, "%s: cmd=%d arg=%d\n", __func__, cmd, arg);
switch (cmd) {
case TUA9001_CMD_RESETN:
if (arg)
val = (1 << 4);
else
val = (0 << 4);
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_OUT_VAL, val, 0x10);
if (ret)
goto err;
break;
case TUA9001_CMD_RXEN:
if (arg)
val = (1 << 1);
else
val = (0 << 1);
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_OUT_VAL, val, 0x02);
if (ret)
goto err;
break;
}
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832u_tuner_callback(struct dvb_usb_device *d, int cmd, int arg)
{
struct rtl28xxu_priv *priv = d->priv;
switch (priv->tuner) {
case TUNER_RTL2832_FC0012:
return rtl2832u_fc0012_tuner_callback(d, cmd, arg);
case TUNER_RTL2832_TUA9001:
return rtl2832u_tua9001_tuner_callback(d, cmd, arg);
default:
break;
}
return 0;
}
static int rtl2832u_frontend_callback(void *adapter_priv, int component,
int cmd, int arg)
{
struct i2c_adapter *adap = adapter_priv;
struct dvb_usb_device *d = i2c_get_adapdata(adap);
dev_dbg(&d->udev->dev, "%s: component=%d cmd=%d arg=%d\n",
__func__, component, cmd, arg);
switch (component) {
case DVB_FRONTEND_COMPONENT_TUNER:
return rtl2832u_tuner_callback(d, cmd, arg);
default:
break;
}
return 0;
}
static int rtl2832u_frontend_attach(struct dvb_usb_adapter *adap)
{
int ret;
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_priv *priv = d_to_priv(d);
const struct rtl2832_config *rtl2832_config;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
switch (priv->tuner) {
case TUNER_RTL2832_FC0012:
rtl2832_config = &rtl28xxu_rtl2832_fc0012_config;
break;
case TUNER_RTL2832_FC0013:
rtl2832_config = &rtl28xxu_rtl2832_fc0013_config;
break;
case TUNER_RTL2832_FC2580:
rtl2832_config = &rtl28xxu_rtl2832_fc0012_config;
break;
case TUNER_RTL2832_TUA9001:
rtl2832_config = &rtl28xxu_rtl2832_tua9001_config;
break;
case TUNER_RTL2832_E4000:
rtl2832_config = &rtl28xxu_rtl2832_e4000_config;
break;
case TUNER_RTL2832_R820T:
case TUNER_RTL2832_R828D:
rtl2832_config = &rtl28xxu_rtl2832_r820t_config;
break;
default:
dev_err(&d->udev->dev, "%s: unknown tuner=%s\n",
KBUILD_MODNAME, priv->tuner_name);
ret = -ENODEV;
goto err;
}
adap->fe[0] = dvb_attach(rtl2832_attach, rtl2832_config, &d->i2c_adap);
if (!adap->fe[0]) {
ret = -ENODEV;
goto err;
}
priv->demod_i2c_adapter = rtl2832_get_i2c_adapter(adap->fe[0]);
adap->fe[0]->callback = rtl2832u_frontend_callback;
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2831u_tuner_attach(struct dvb_usb_adapter *adap)
{
int ret;
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_priv *priv = d_to_priv(d);
struct i2c_adapter *rtl2830_tuner_i2c;
struct dvb_frontend *fe;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
rtl2830_tuner_i2c = rtl2830_get_tuner_i2c_adapter(adap->fe[0]);
switch (priv->tuner) {
case TUNER_RTL2830_QT1010:
fe = dvb_attach(qt1010_attach, adap->fe[0],
rtl2830_tuner_i2c, &rtl28xxu_qt1010_config);
break;
case TUNER_RTL2830_MT2060:
fe = dvb_attach(mt2060_attach, adap->fe[0],
rtl2830_tuner_i2c, &rtl28xxu_mt2060_config,
1220);
break;
case TUNER_RTL2830_MXL5005S:
fe = dvb_attach(mxl5005s_attach, adap->fe[0],
rtl2830_tuner_i2c, &rtl28xxu_mxl5005s_config);
break;
default:
fe = NULL;
dev_err(&d->udev->dev, "%s: unknown tuner=%d\n", KBUILD_MODNAME,
priv->tuner);
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
static int rtl2832u_tuner_attach(struct dvb_usb_adapter *adap)
{
int ret;
struct dvb_usb_device *d = adap_to_d(adap);
struct rtl28xxu_priv *priv = d_to_priv(d);
struct dvb_frontend *fe = NULL;
struct i2c_board_info info;
struct i2c_client *client;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
memset(&info, 0, sizeof(struct i2c_board_info));
switch (priv->tuner) {
case TUNER_RTL2832_FC0012:
fe = dvb_attach(fc0012_attach, adap->fe[0],
&d->i2c_adap, &rtl2832u_fc0012_config);
adap->fe[0]->ops.read_signal_strength =
adap->fe[0]->ops.tuner_ops.get_rf_strength;
dvb_attach_sdr(rtl2832_sdr_attach, adap->fe[0], &d->i2c_adap,
&rtl28xxu_rtl2832_fc0012_config, NULL);
break;
case TUNER_RTL2832_FC0013:
fe = dvb_attach(fc0013_attach, adap->fe[0],
&d->i2c_adap, 0xc6>>1, 0, FC_XTAL_28_8_MHZ);
adap->fe[0]->ops.read_signal_strength =
adap->fe[0]->ops.tuner_ops.get_rf_strength;
dvb_attach_sdr(rtl2832_sdr_attach, adap->fe[0], &d->i2c_adap,
&rtl28xxu_rtl2832_fc0013_config, NULL);
break;
case TUNER_RTL2832_E4000: {
struct v4l2_subdev *sd;
struct i2c_adapter *i2c_adap_internal =
rtl2832_get_private_i2c_adapter(adap->fe[0]);
struct e4000_config e4000_config = {
.fe = adap->fe[0],
.clock = 28800000,
};
strlcpy(info.type, "e4000", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &e4000_config;
request_module(info.type);
client = i2c_new_device(priv->demod_i2c_adapter, &info);
if (client == NULL || client->dev.driver == NULL)
break;
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
break;
}
priv->client = client;
sd = i2c_get_clientdata(client);
i2c_set_adapdata(i2c_adap_internal, d);
dvb_attach_sdr(rtl2832_sdr_attach, adap->fe[0],
i2c_adap_internal,
&rtl28xxu_rtl2832_e4000_config, sd);
}
break;
case TUNER_RTL2832_FC2580:
fe = dvb_attach(fc2580_attach, adap->fe[0], &d->i2c_adap,
&rtl2832u_fc2580_config);
break;
case TUNER_RTL2832_TUA9001:
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_DIR, 0x00, 0x12);
if (ret)
goto err;
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_OUT_EN, 0x12, 0x12);
if (ret)
goto err;
fe = dvb_attach(tua9001_attach, adap->fe[0], &d->i2c_adap,
&rtl2832u_tua9001_config);
break;
case TUNER_RTL2832_R820T:
fe = dvb_attach(r820t_attach, adap->fe[0], &d->i2c_adap,
&rtl2832u_r820t_config);
adap->fe[0]->ops.read_signal_strength =
adap->fe[0]->ops.tuner_ops.get_rf_strength;
dvb_attach_sdr(rtl2832_sdr_attach, adap->fe[0], &d->i2c_adap,
&rtl28xxu_rtl2832_r820t_config, NULL);
break;
case TUNER_RTL2832_R828D:
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_OUT_VAL, 0x00, 0x01);
if (ret)
goto err;
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_DIR, 0x00, 0x01);
if (ret)
goto err;
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_OUT_EN, 0x01, 0x01);
if (ret)
goto err;
fe = dvb_attach(r820t_attach, adap->fe[0], &d->i2c_adap,
&rtl2832u_r828d_config);
adap->fe[0]->ops.read_signal_strength =
adap->fe[0]->ops.tuner_ops.get_rf_strength;
break;
default:
dev_err(&d->udev->dev, "%s: unknown tuner=%d\n", KBUILD_MODNAME,
priv->tuner);
}
if (fe == NULL && priv->client == NULL) {
ret = -ENODEV;
goto err;
}
return 0;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl28xxu_init(struct dvb_usb_device *d)
{
int ret;
u8 val;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
ret = rtl28xx_rd_reg(d, USB_SYSCTL_0, &val);
if (ret)
goto err;
val |= 0x09;
ret = rtl28xx_wr_reg(d, USB_SYSCTL_0, val);
if (ret)
goto err;
ret = rtl28xx_wr_regs(d, USB_EPA_MAXPKT, "\x00\x02\x00\x00", 4);
if (ret)
goto err;
ret = rtl28xx_wr_regs(d, USB_EPA_FIFO_CFG, "\x14\x00\x00\x00", 4);
if (ret)
goto err;
return ret;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static void rtl28xxu_exit(struct dvb_usb_device *d)
{
struct rtl28xxu_priv *priv = d->priv;
struct i2c_client *client = priv->client;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
return;
}
static int rtl2831u_power_ctrl(struct dvb_usb_device *d, int onoff)
{
int ret;
u8 gpio, sys0, epa_ctl[2];
dev_dbg(&d->udev->dev, "%s: onoff=%d\n", __func__, onoff);
ret = rtl28xx_rd_reg(d, SYS_SYS0, &sys0);
if (ret)
goto err;
ret = rtl28xx_rd_reg(d, SYS_GPIO_OUT_VAL, &gpio);
if (ret)
goto err;
dev_dbg(&d->udev->dev, "%s: RD SYS0=%02x GPIO_OUT_VAL=%02x\n", __func__,
sys0, gpio);
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
dev_dbg(&d->udev->dev, "%s: WR SYS0=%02x GPIO_OUT_VAL=%02x\n", __func__,
sys0, gpio);
ret = rtl28xx_wr_reg(d, SYS_SYS0, sys0);
if (ret)
goto err;
ret = rtl28xx_wr_reg(d, SYS_GPIO_OUT_VAL, gpio);
if (ret)
goto err;
ret = rtl28xx_wr_regs(d, USB_EPA_CTL, epa_ctl, 2);
if (ret)
goto err;
if (onoff)
usb_clear_halt(d->udev, usb_rcvbulkpipe(d->udev, 0x81));
return ret;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832u_power_ctrl(struct dvb_usb_device *d, int onoff)
{
int ret;
dev_dbg(&d->udev->dev, "%s: onoff=%d\n", __func__, onoff);
if (onoff) {
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_OUT_VAL, 0x08, 0x18);
if (ret)
goto err;
ret = rtl28xx_wr_reg_mask(d, SYS_DEMOD_CTL1, 0x00, 0x10);
if (ret)
goto err;
ret = rtl28xx_wr_reg_mask(d, SYS_DEMOD_CTL, 0x80, 0x80);
if (ret)
goto err;
ret = rtl28xx_wr_reg_mask(d, SYS_DEMOD_CTL, 0x20, 0x20);
if (ret)
goto err;
mdelay(5);
ret = rtl28xx_wr_reg_mask(d, SYS_DEMOD_CTL, 0x48, 0x48);
if (ret)
goto err;
ret = rtl28xx_wr_regs(d, USB_EPA_CTL, "\x00\x00", 2);
if (ret)
goto err;
ret = usb_clear_halt(d->udev, usb_rcvbulkpipe(d->udev, 0x81));
if (ret)
goto err;
} else {
ret = rtl28xx_wr_reg_mask(d, SYS_GPIO_OUT_VAL, 0x10, 0x10);
if (ret)
goto err;
ret = rtl28xx_wr_reg_mask(d, SYS_DEMOD_CTL, 0x00, 0x48);
if (ret)
goto err;
ret = rtl28xx_wr_reg_mask(d, SYS_DEMOD_CTL, 0x00, 0x80);
if (ret)
goto err;
ret = rtl28xx_wr_regs(d, USB_EPA_CTL, "\x10\x02", 2);
if (ret)
goto err;
}
return ret;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2831u_rc_query(struct dvb_usb_device *d)
{
int ret, i;
struct rtl28xxu_priv *priv = d->priv;
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
if (!priv->rc_active) {
for (i = 0; i < ARRAY_SIZE(rc_nec_tab); i++) {
ret = rtl28xx_wr_reg(d, rc_nec_tab[i].reg,
rc_nec_tab[i].val);
if (ret)
goto err;
}
priv->rc_active = true;
}
ret = rtl2831_rd_regs(d, SYS_IRRC_RP, buf, 5);
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
ret = rtl28xx_wr_reg(d, SYS_IRRC_SR, 1);
if (ret)
goto err;
ret = rtl28xx_wr_reg(d, SYS_IRRC_SR, 1);
if (ret)
goto err;
}
return ret;
err:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
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
struct rtl28xxu_priv *priv = d->priv;
struct ir_raw_event ev;
u8 buf[128];
static const struct rtl28xxu_reg_val_mask refresh_tab[] = {
{IR_RX_IF, 0x03, 0xff},
{IR_RX_BUF_CTRL, 0x80, 0xff},
{IR_RX_CTRL, 0x80, 0xff},
};
if (!priv->rc_active) {
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
ret = rtl28xx_wr_reg_mask(d, init_tab[i].reg,
init_tab[i].val, init_tab[i].mask);
if (ret)
goto err;
}
priv->rc_active = true;
}
ret = rtl28xx_rd_reg(d, IR_RX_IF, &buf[0]);
if (ret)
goto err;
if (buf[0] != 0x83)
goto exit;
ret = rtl28xx_rd_reg(d, IR_RX_BC, &buf[0]);
if (ret)
goto err;
len = buf[0];
ret = rtl2831_rd_regs(d, IR_RX_BUF, buf, len);
if (ret)
goto err;
for (i = 0; i < ARRAY_SIZE(refresh_tab); i++) {
ret = rtl28xx_wr_reg_mask(d, refresh_tab[i].reg,
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
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832u_get_rc_config(struct dvb_usb_device *d,
struct dvb_usb_rc *rc)
{
if (rtl28xxu_disable_rc)
return rtl28xx_wr_reg(d, IR_RX_IE, 0x00);
if (!rc->map_name)
rc->map_name = RC_MAP_EMPTY;
rc->allowed_protos = RC_BIT_ALL;
rc->driver_type = RC_DRIVER_IR_RAW;
rc->query = rtl2832u_rc_query;
rc->interval = 400;
return 0;
}
