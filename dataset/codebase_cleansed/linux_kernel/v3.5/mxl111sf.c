int mxl111sf_ctrl_msg(struct dvb_usb_device *d,
u8 cmd, u8 *wbuf, int wlen, u8 *rbuf, int rlen)
{
int wo = (rbuf == NULL || rlen == 0);
int ret;
u8 sndbuf[1+wlen];
deb_adv("%s(wlen = %d, rlen = %d)\n", __func__, wlen, rlen);
memset(sndbuf, 0, 1+wlen);
sndbuf[0] = cmd;
memcpy(&sndbuf[1], wbuf, wlen);
ret = (wo) ? dvb_usb_generic_write(d, sndbuf, 1+wlen) :
dvb_usb_generic_rw(d, sndbuf, 1+wlen, rbuf, rlen, 0);
mxl_fail(ret);
return ret;
}
int mxl111sf_read_reg(struct mxl111sf_state *state, u8 addr, u8 *data)
{
u8 buf[2];
int ret;
ret = mxl111sf_ctrl_msg(state->d, MXL_CMD_REG_READ, &addr, 1, buf, 2);
if (mxl_fail(ret)) {
mxl_debug("error reading reg: 0x%02x", addr);
goto fail;
}
if (buf[0] == addr)
*data = buf[1];
else {
err("invalid response reading reg: 0x%02x != 0x%02x, 0x%02x",
addr, buf[0], buf[1]);
ret = -EINVAL;
}
deb_reg("R: (0x%02x, 0x%02x)\n", addr, *data);
fail:
return ret;
}
int mxl111sf_write_reg(struct mxl111sf_state *state, u8 addr, u8 data)
{
u8 buf[] = { addr, data };
int ret;
deb_reg("W: (0x%02x, 0x%02x)\n", addr, data);
ret = mxl111sf_ctrl_msg(state->d, MXL_CMD_REG_WRITE, buf, 2, NULL, 0);
if (mxl_fail(ret))
err("error writing reg: 0x%02x, val: 0x%02x", addr, data);
return ret;
}
int mxl111sf_write_reg_mask(struct mxl111sf_state *state,
u8 addr, u8 mask, u8 data)
{
int ret;
u8 val;
if (mask != 0xff) {
ret = mxl111sf_read_reg(state, addr, &val);
#if 1
if (mxl_fail(ret))
err("error writing addr: 0x%02x, mask: 0x%02x, "
"data: 0x%02x, retrying...", addr, mask, data);
ret = mxl111sf_read_reg(state, addr, &val);
#endif
if (mxl_fail(ret))
goto fail;
}
val &= ~mask;
val |= data;
ret = mxl111sf_write_reg(state, addr, val);
mxl_fail(ret);
fail:
return ret;
}
int mxl111sf_ctrl_program_regs(struct mxl111sf_state *state,
struct mxl111sf_reg_ctrl_info *ctrl_reg_info)
{
int i, ret = 0;
for (i = 0; ctrl_reg_info[i].addr |
ctrl_reg_info[i].mask |
ctrl_reg_info[i].data; i++) {
ret = mxl111sf_write_reg_mask(state,
ctrl_reg_info[i].addr,
ctrl_reg_info[i].mask,
ctrl_reg_info[i].data);
if (mxl_fail(ret)) {
err("failed on reg #%d (0x%02x)", i,
ctrl_reg_info[i].addr);
break;
}
}
return ret;
}
static int mxl1x1sf_get_chip_info(struct mxl111sf_state *state)
{
int ret;
u8 id, ver;
char *mxl_chip, *mxl_rev;
if ((state->chip_id) && (state->chip_ver))
return 0;
ret = mxl111sf_read_reg(state, CHIP_ID_REG, &id);
if (mxl_fail(ret))
goto fail;
state->chip_id = id;
ret = mxl111sf_read_reg(state, TOP_CHIP_REV_ID_REG, &ver);
if (mxl_fail(ret))
goto fail;
state->chip_ver = ver;
switch (id) {
case 0x61:
mxl_chip = "MxL101SF";
break;
case 0x63:
mxl_chip = "MxL111SF";
break;
default:
mxl_chip = "UNKNOWN MxL1X1";
break;
}
switch (ver) {
case 0x36:
state->chip_rev = MXL111SF_V6;
mxl_rev = "v6";
break;
case 0x08:
state->chip_rev = MXL111SF_V8_100;
mxl_rev = "v8_100";
break;
case 0x18:
state->chip_rev = MXL111SF_V8_200;
mxl_rev = "v8_200";
break;
default:
state->chip_rev = 0;
mxl_rev = "UNKNOWN REVISION";
break;
}
info("%s detected, %s (0x%x)", mxl_chip, mxl_rev, ver);
fail:
return ret;
}
static int mxl111sf_power_ctrl(struct dvb_usb_device *d, int onoff)
{
return 0;
}
static int mxl111sf_adap_fe_init(struct dvb_frontend *fe)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
struct mxl111sf_adap_state *adap_state = adap->fe_adap[fe->id].priv;
int err;
if (!state->chip_id) {
mxl_debug("driver not yet initialized, exit.");
goto fail;
}
deb_info("%s()\n", __func__);
mutex_lock(&state->fe_lock);
state->alt_mode = adap_state->alt_mode;
if (usb_set_interface(adap->dev->udev, 0, state->alt_mode) < 0)
err("set interface failed");
err = mxl1x1sf_soft_reset(state);
mxl_fail(err);
err = mxl111sf_init_tuner_demod(state);
mxl_fail(err);
err = mxl1x1sf_set_device_mode(state, adap_state->device_mode);
mxl_fail(err);
mxl111sf_enable_usb_output(state);
mxl_fail(err);
mxl1x1sf_top_master_ctrl(state, 1);
mxl_fail(err);
if ((MXL111SF_GPIO_MOD_DVBT != adap_state->gpio_mode) &&
(state->chip_rev > MXL111SF_V6)) {
mxl111sf_config_pin_mux_modes(state,
PIN_MUX_TS_SPI_IN_MODE_1);
mxl_fail(err);
}
err = mxl111sf_init_port_expander(state);
if (!mxl_fail(err)) {
state->gpio_mode = adap_state->gpio_mode;
err = mxl111sf_gpio_mode_switch(state, state->gpio_mode);
mxl_fail(err);
#if 0
err = fe->ops.init(fe);
#endif
msleep(100);
}
return (adap_state->fe_init) ? adap_state->fe_init(fe) : 0;
fail:
return -ENODEV;
}
static int mxl111sf_adap_fe_sleep(struct dvb_frontend *fe)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
struct mxl111sf_adap_state *adap_state = adap->fe_adap[fe->id].priv;
int err;
if (!state->chip_id) {
mxl_debug("driver not yet initialized, exit.");
goto fail;
}
deb_info("%s()\n", __func__);
err = (adap_state->fe_sleep) ? adap_state->fe_sleep(fe) : 0;
mutex_unlock(&state->fe_lock);
return err;
fail:
return -ENODEV;
}
static int mxl111sf_ep6_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
struct mxl111sf_adap_state *adap_state = adap->fe_adap[adap->active_fe].priv;
int ret = 0;
deb_info("%s(%d)\n", __func__, onoff);
if (onoff) {
ret = mxl111sf_enable_usb_output(state);
mxl_fail(ret);
ret = mxl111sf_config_mpeg_in(state, 1, 1,
adap_state->ep6_clockphase,
0, 0);
mxl_fail(ret);
#if 0
} else {
ret = mxl111sf_disable_656_port(state);
mxl_fail(ret);
#endif
}
return ret;
}
static int mxl111sf_ep5_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
int ret = 0;
deb_info("%s(%d)\n", __func__, onoff);
if (onoff) {
ret = mxl111sf_enable_usb_output(state);
mxl_fail(ret);
ret = mxl111sf_init_i2s_port(state, 200);
mxl_fail(ret);
ret = mxl111sf_config_i2s(state, 0, 15);
mxl_fail(ret);
} else {
ret = mxl111sf_disable_i2s_port(state);
mxl_fail(ret);
}
if (state->chip_rev > MXL111SF_V6)
ret = mxl111sf_config_spi(state, onoff);
mxl_fail(ret);
return ret;
}
static int mxl111sf_ep4_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
int ret = 0;
deb_info("%s(%d)\n", __func__, onoff);
if (onoff) {
ret = mxl111sf_enable_usb_output(state);
mxl_fail(ret);
}
return ret;
}
static int mxl111sf_lgdt3305_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
int fe_id = adap->num_frontends_initialized;
struct mxl111sf_adap_state *adap_state = adap->fe_adap[fe_id].priv;
int ret;
deb_adv("%s()\n", __func__);
state->d = d;
adap_state->alt_mode = (dvb_usb_mxl111sf_isoc) ? 2 : 1;
state->alt_mode = adap_state->alt_mode;
if (usb_set_interface(adap->dev->udev, 0, state->alt_mode) < 0)
err("set interface failed");
state->gpio_mode = MXL111SF_GPIO_MOD_ATSC;
adap_state->gpio_mode = state->gpio_mode;
adap_state->device_mode = MXL_TUNER_MODE;
adap_state->ep6_clockphase = 1;
ret = mxl1x1sf_soft_reset(state);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_init_tuner_demod(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_set_device_mode(state, adap_state->device_mode);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_enable_usb_output(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_top_master_ctrl(state, 1);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_init_port_expander(state);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_gpio_mode_switch(state, state->gpio_mode);
if (mxl_fail(ret))
goto fail;
adap->fe_adap[fe_id].fe = dvb_attach(lgdt3305_attach,
&hauppauge_lgdt3305_config,
&adap->dev->i2c_adap);
if (adap->fe_adap[fe_id].fe) {
adap_state->fe_init = adap->fe_adap[fe_id].fe->ops.init;
adap->fe_adap[fe_id].fe->ops.init = mxl111sf_adap_fe_init;
adap_state->fe_sleep = adap->fe_adap[fe_id].fe->ops.sleep;
adap->fe_adap[fe_id].fe->ops.sleep = mxl111sf_adap_fe_sleep;
return 0;
}
ret = -EIO;
fail:
return ret;
}
static int mxl111sf_lg2160_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
int fe_id = adap->num_frontends_initialized;
struct mxl111sf_adap_state *adap_state = adap->fe_adap[fe_id].priv;
int ret;
deb_adv("%s()\n", __func__);
state->d = d;
adap_state->alt_mode = (dvb_usb_mxl111sf_isoc) ? 2 : 1;
state->alt_mode = adap_state->alt_mode;
if (usb_set_interface(adap->dev->udev, 0, state->alt_mode) < 0)
err("set interface failed");
state->gpio_mode = MXL111SF_GPIO_MOD_MH;
adap_state->gpio_mode = state->gpio_mode;
adap_state->device_mode = MXL_TUNER_MODE;
adap_state->ep6_clockphase = 1;
ret = mxl1x1sf_soft_reset(state);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_init_tuner_demod(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_set_device_mode(state, adap_state->device_mode);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_enable_usb_output(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_top_master_ctrl(state, 1);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_init_port_expander(state);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_gpio_mode_switch(state, state->gpio_mode);
if (mxl_fail(ret))
goto fail;
ret = get_chip_info(state);
if (mxl_fail(ret))
goto fail;
adap->fe_adap[fe_id].fe = dvb_attach(lg2160_attach,
&hauppauge_lg2160_config,
&adap->dev->i2c_adap);
if (adap->fe_adap[fe_id].fe) {
adap_state->fe_init = adap->fe_adap[fe_id].fe->ops.init;
adap->fe_adap[fe_id].fe->ops.init = mxl111sf_adap_fe_init;
adap_state->fe_sleep = adap->fe_adap[fe_id].fe->ops.sleep;
adap->fe_adap[fe_id].fe->ops.sleep = mxl111sf_adap_fe_sleep;
return 0;
}
ret = -EIO;
fail:
return ret;
}
static int mxl111sf_lg2161_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
int fe_id = adap->num_frontends_initialized;
struct mxl111sf_adap_state *adap_state = adap->fe_adap[fe_id].priv;
int ret;
deb_adv("%s()\n", __func__);
state->d = d;
adap_state->alt_mode = (dvb_usb_mxl111sf_isoc) ? 2 : 1;
state->alt_mode = adap_state->alt_mode;
if (usb_set_interface(adap->dev->udev, 0, state->alt_mode) < 0)
err("set interface failed");
state->gpio_mode = MXL111SF_GPIO_MOD_MH;
adap_state->gpio_mode = state->gpio_mode;
adap_state->device_mode = MXL_TUNER_MODE;
adap_state->ep6_clockphase = 1;
ret = mxl1x1sf_soft_reset(state);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_init_tuner_demod(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_set_device_mode(state, adap_state->device_mode);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_enable_usb_output(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_top_master_ctrl(state, 1);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_init_port_expander(state);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_gpio_mode_switch(state, state->gpio_mode);
if (mxl_fail(ret))
goto fail;
ret = get_chip_info(state);
if (mxl_fail(ret))
goto fail;
adap->fe_adap[fe_id].fe = dvb_attach(lg2160_attach,
(MXL111SF_V8_200 == state->chip_rev) ?
&hauppauge_lg2161_1040_config :
&hauppauge_lg2161_1019_config,
&adap->dev->i2c_adap);
if (adap->fe_adap[fe_id].fe) {
adap_state->fe_init = adap->fe_adap[fe_id].fe->ops.init;
adap->fe_adap[fe_id].fe->ops.init = mxl111sf_adap_fe_init;
adap_state->fe_sleep = adap->fe_adap[fe_id].fe->ops.sleep;
adap->fe_adap[fe_id].fe->ops.sleep = mxl111sf_adap_fe_sleep;
return 0;
}
ret = -EIO;
fail:
return ret;
}
static int mxl111sf_lg2161_ep6_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
int fe_id = adap->num_frontends_initialized;
struct mxl111sf_adap_state *adap_state = adap->fe_adap[fe_id].priv;
int ret;
deb_adv("%s()\n", __func__);
state->d = d;
adap_state->alt_mode = (dvb_usb_mxl111sf_isoc) ? 2 : 1;
state->alt_mode = adap_state->alt_mode;
if (usb_set_interface(adap->dev->udev, 0, state->alt_mode) < 0)
err("set interface failed");
state->gpio_mode = MXL111SF_GPIO_MOD_MH;
adap_state->gpio_mode = state->gpio_mode;
adap_state->device_mode = MXL_TUNER_MODE;
adap_state->ep6_clockphase = 0;
ret = mxl1x1sf_soft_reset(state);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_init_tuner_demod(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_set_device_mode(state, adap_state->device_mode);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_enable_usb_output(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_top_master_ctrl(state, 1);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_init_port_expander(state);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_gpio_mode_switch(state, state->gpio_mode);
if (mxl_fail(ret))
goto fail;
ret = get_chip_info(state);
if (mxl_fail(ret))
goto fail;
adap->fe_adap[fe_id].fe = dvb_attach(lg2160_attach,
(MXL111SF_V8_200 == state->chip_rev) ?
&hauppauge_lg2161_1040_ep6_config :
&hauppauge_lg2161_1019_ep6_config,
&adap->dev->i2c_adap);
if (adap->fe_adap[fe_id].fe) {
adap_state->fe_init = adap->fe_adap[fe_id].fe->ops.init;
adap->fe_adap[fe_id].fe->ops.init = mxl111sf_adap_fe_init;
adap_state->fe_sleep = adap->fe_adap[fe_id].fe->ops.sleep;
adap->fe_adap[fe_id].fe->ops.sleep = mxl111sf_adap_fe_sleep;
return 0;
}
ret = -EIO;
fail:
return ret;
}
static int mxl111sf_attach_demod(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
int fe_id = adap->num_frontends_initialized;
struct mxl111sf_adap_state *adap_state = adap->fe_adap[fe_id].priv;
int ret;
deb_adv("%s()\n", __func__);
state->d = d;
adap_state->alt_mode = (dvb_usb_mxl111sf_isoc) ? 1 : 2;
state->alt_mode = adap_state->alt_mode;
if (usb_set_interface(adap->dev->udev, 0, state->alt_mode) < 0)
err("set interface failed");
state->gpio_mode = MXL111SF_GPIO_MOD_DVBT;
adap_state->gpio_mode = state->gpio_mode;
adap_state->device_mode = MXL_SOC_MODE;
adap_state->ep6_clockphase = 1;
ret = mxl1x1sf_soft_reset(state);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_init_tuner_demod(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_set_device_mode(state, adap_state->device_mode);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_enable_usb_output(state);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_top_master_ctrl(state, 1);
if (mxl_fail(ret))
goto fail;
mxl111sf_init_port_expander(state);
adap->fe_adap[fe_id].fe = dvb_attach(mxl111sf_demod_attach, state,
&mxl_demod_config);
if (adap->fe_adap[fe_id].fe) {
adap_state->fe_init = adap->fe_adap[fe_id].fe->ops.init;
adap->fe_adap[fe_id].fe->ops.init = mxl111sf_adap_fe_init;
adap_state->fe_sleep = adap->fe_adap[fe_id].fe->ops.sleep;
adap->fe_adap[fe_id].fe->ops.sleep = mxl111sf_adap_fe_sleep;
return 0;
}
ret = -EIO;
fail:
return ret;
}
static inline int mxl111sf_set_ant_path(struct mxl111sf_state *state,
int antpath)
{
return mxl111sf_idac_config(state, 1, 1,
(antpath == ANT_PATH_INTERNAL) ?
0x3f : 0x00, 0);
}
static int mxl111sf_ant_hunt(struct dvb_frontend *fe)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
int antctrl = dvb_usb_mxl111sf_rfswitch;
u16 rxPwrA, rxPwr0, rxPwr1, rxPwr2;
mxl111sf_set_ant_path(state, antctrl == ANT_PATH_AUTO ?
ANT_PATH_EXTERNAL : antctrl);
if (antctrl == ANT_PATH_AUTO) {
#if 0
msleep(ANT_HUNT_SLEEP);
#endif
fe->ops.tuner_ops.get_rf_strength(fe, &rxPwrA);
mxl111sf_set_ant_path(state, ANT_PATH_EXTERNAL);
msleep(ANT_HUNT_SLEEP);
fe->ops.tuner_ops.get_rf_strength(fe, &rxPwr0);
mxl111sf_set_ant_path(state, ANT_PATH_EXTERNAL);
msleep(ANT_HUNT_SLEEP);
fe->ops.tuner_ops.get_rf_strength(fe, &rxPwr1);
mxl111sf_set_ant_path(state, ANT_PATH_INTERNAL);
msleep(ANT_HUNT_SLEEP);
fe->ops.tuner_ops.get_rf_strength(fe, &rxPwr2);
if (rxPwr1+ANT_EXT_TWEAK >= rxPwr2) {
mxl111sf_set_ant_path(state, ANT_PATH_EXTERNAL);
DbgAntHunt(ANT_PATH_EXTERNAL, rxPwrA,
rxPwr0, rxPwr1, rxPwr2);
} else {
DbgAntHunt(ANT_PATH_INTERNAL, rxPwrA,
rxPwr0, rxPwr1, rxPwr2);
}
}
return 0;
}
static int mxl111sf_attach_tuner(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
struct mxl111sf_state *state = d->priv;
int fe_id = adap->num_frontends_initialized;
deb_adv("%s()\n", __func__);
if (NULL != dvb_attach(mxl111sf_tuner_attach,
adap->fe_adap[fe_id].fe, state,
&mxl_tuner_config))
return 0;
return -EIO;
}
static int mxl111sf_fe_ioctl_override(struct dvb_frontend *fe,
unsigned int cmd, void *parg,
unsigned int stage)
{
int err = 0;
switch (stage) {
case DVB_FE_IOCTL_PRE:
switch (cmd) {
case FE_READ_SIGNAL_STRENGTH:
err = fe->ops.tuner_ops.get_rf_strength(fe, parg);
if (0 == err)
err = 1;
break;
}
break;
case DVB_FE_IOCTL_POST:
break;
}
return err;
}
static u32 mxl111sf_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int mxl111sf_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct dvb_usb_device *d = NULL;
deb_adv("%s()\n", __func__);
if (((dvb_usb_mxl111sf_isoc) &&
(0 == dvb_usb_device_init(intf,
&mxl111sf_dvbt_isoc_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_atsc_isoc_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_atsc_mh_isoc_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_mh_isoc_properties,
THIS_MODULE, &d, adapter_nr) ||
((dvb_usb_mxl111sf_spi) &&
(0 == dvb_usb_device_init(intf,
&mxl111sf_mercury_spi_isoc_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_mercury_mh_spi_isoc_properties,
THIS_MODULE, &d, adapter_nr))) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_mercury_tp_isoc_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_mercury_mh_tp_isoc_properties,
THIS_MODULE, &d, adapter_nr))) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_dvbt_bulk_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_atsc_bulk_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_atsc_mh_bulk_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_mh_bulk_properties,
THIS_MODULE, &d, adapter_nr) ||
((dvb_usb_mxl111sf_spi) &&
(0 == dvb_usb_device_init(intf,
&mxl111sf_mercury_spi_bulk_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_mercury_mh_spi_bulk_properties,
THIS_MODULE, &d, adapter_nr))) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_mercury_tp_bulk_properties,
THIS_MODULE, &d, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&mxl111sf_mercury_mh_tp_bulk_properties,
THIS_MODULE, &d, adapter_nr) || 0) {
struct mxl111sf_state *state = d->priv;
static u8 eeprom[256];
struct i2c_client c;
int ret;
ret = get_chip_info(state);
if (mxl_fail(ret))
err("failed to get chip info during probe");
mutex_init(&state->fe_lock);
if (state->chip_rev > MXL111SF_V6)
mxl111sf_config_pin_mux_modes(state,
PIN_MUX_TS_SPI_IN_MODE_1);
c.adapter = &d->i2c_adap;
c.addr = 0xa0 >> 1;
ret = tveeprom_read(&c, eeprom, sizeof(eeprom));
if (mxl_fail(ret))
return 0;
tveeprom_hauppauge_analog(&c, &state->tv,
(0x84 == eeprom[0xa0]) ?
eeprom + 0xa0 : eeprom + 0x80);
#if 0
switch (state->tv.model) {
case 117001:
case 126001:
case 138001:
break;
default:
printk(KERN_WARNING "%s: warning: "
"unknown hauppauge model #%d\n",
__func__, state->tv.model);
}
#endif
return 0;
}
err("Your device is not yet supported by this driver. "
"See kernellabs.com for more info");
return -EINVAL;
}
