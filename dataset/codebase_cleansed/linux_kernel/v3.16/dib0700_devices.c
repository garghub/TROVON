static int bristol_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_state *st = adap->dev->priv;
if (adap->id == 0) {
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0); msleep(10);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1); msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0); msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1); msleep(10);
if (force_lna_activation)
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
else
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 0);
if (dib3000mc_i2c_enumeration(&adap->dev->i2c_adap, 2, DEFAULT_DIB3000P_I2C_ADDRESS, bristol_dib3000mc_config) != 0) {
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0); msleep(10);
return -ENODEV;
}
}
st->mt2060_if1[adap->id] = 1220;
return (adap->fe_adap[0].fe = dvb_attach(dib3000mc_attach, &adap->dev->i2c_adap,
(10 + adap->id) << 1, &bristol_dib3000mc_config[adap->id])) == NULL ? -ENODEV : 0;
}
static int eeprom_read(struct i2c_adapter *adap,u8 adrs,u8 *pval)
{
struct i2c_msg msg[2] = {
{ .addr = 0x50, .flags = 0, .buf = &adrs, .len = 1 },
{ .addr = 0x50, .flags = I2C_M_RD, .buf = pval, .len = 1 },
};
if (i2c_transfer(adap, msg, 2) != 2) return -EREMOTEIO;
return 0;
}
static int bristol_tuner_attach(struct dvb_usb_adapter *adap)
{
struct i2c_adapter *prim_i2c = &adap->dev->i2c_adap;
struct i2c_adapter *tun_i2c = dib3000mc_get_tuner_i2c_master(adap->fe_adap[0].fe, 1);
s8 a;
int if1=1220;
if (adap->dev->udev->descriptor.idVendor == cpu_to_le16(USB_VID_HAUPPAUGE) &&
adap->dev->udev->descriptor.idProduct == cpu_to_le16(USB_PID_HAUPPAUGE_NOVA_T_500_2)) {
if (!eeprom_read(prim_i2c,0x59 + adap->id,&a)) if1=1220+a;
}
return dvb_attach(mt2060_attach, adap->fe_adap[0].fe, tun_i2c,
&bristol_mt2060_config[adap->id], if1) == NULL ?
-ENODEV : 0;
}
static int stk7700P2_frontend_attach(struct dvb_usb_adapter *adap)
{
if (adap->id == 0) {
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(10);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap, 1, 18,
stk7700d_dib7000p_mt2266_config)
!= 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n", __func__);
return -ENODEV;
}
}
adap->fe_adap[0].fe =
dvb_attach(dib7000p_attach, &adap->dev->i2c_adap,
0x80 + (adap->id << 1),
&stk7700d_dib7000p_mt2266_config[adap->id]);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int stk7700d_frontend_attach(struct dvb_usb_adapter *adap)
{
if (adap->id == 0) {
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap, 2, 18,
stk7700d_dib7000p_mt2266_config)
!= 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n", __func__);
return -ENODEV;
}
}
adap->fe_adap[0].fe =
dvb_attach(dib7000p_attach, &adap->dev->i2c_adap,
0x80 + (adap->id << 1),
&stk7700d_dib7000p_mt2266_config[adap->id]);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int stk7700d_tuner_attach(struct dvb_usb_adapter *adap)
{
struct i2c_adapter *tun_i2c;
tun_i2c = dib7000p_get_i2c_master(adap->fe_adap[0].fe, DIBX000_I2C_INTERFACE_TUNER, 1);
return dvb_attach(mt2266_attach, adap->fe_adap[0].fe, tun_i2c,
&stk7700d_mt2266_config[adap->id]) == NULL ? -ENODEV : 0;
}
static int stk7700ph_xc3028_callback(void *ptr, int component,
int command, int arg)
{
struct dvb_usb_adapter *adap = ptr;
switch (command) {
case XC2028_TUNER_RESET:
dib7000p_set_gpio(adap->fe_adap[0].fe, 8, 0, 0); msleep(10);
dib7000p_set_gpio(adap->fe_adap[0].fe, 8, 0, 1);
break;
case XC2028_RESET_CLK:
break;
default:
err("%s: unknown command %d, arg %d\n", __func__,
command, arg);
return -EINVAL;
}
return 0;
}
static int stk7700ph_frontend_attach(struct dvb_usb_adapter *adap)
{
struct usb_device_descriptor *desc = &adap->dev->udev->descriptor;
if (desc->idVendor == cpu_to_le16(USB_VID_PINNACLE) &&
desc->idProduct == cpu_to_le16(USB_PID_PINNACLE_EXPRESSCARD_320CX))
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0);
else
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
msleep(10);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap, 1, 18,
&stk7700ph_dib7700_xc3028_config) != 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n",
__func__);
return -ENODEV;
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 0x80,
&stk7700ph_dib7700_xc3028_config);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int stk7700ph_tuner_attach(struct dvb_usb_adapter *adap)
{
struct i2c_adapter *tun_i2c;
tun_i2c = dib7000p_get_i2c_master(adap->fe_adap[0].fe,
DIBX000_I2C_INTERFACE_TUNER, 1);
stk7700ph_xc3028_config.i2c_adap = tun_i2c;
adap->fe_adap[0].fe->callback = stk7700ph_xc3028_callback;
return dvb_attach(xc2028_attach, adap->fe_adap[0].fe, &stk7700ph_xc3028_config)
== NULL ? -ENODEV : 0;
}
static int dib0700_rc_query_old_firmware(struct dvb_usb_device *d)
{
u8 key[4];
u32 keycode;
u8 toggle;
int i;
struct dib0700_state *st = d->priv;
if (st->fw_version >= 0x10200) {
return 0;
}
i = dib0700_ctrl_rd(d, rc_request, 2, key, 4);
if (i <= 0) {
err("RC Query Failed");
return -1;
}
if (key[0] == 0 && key[1] == 0 && key[2] == 0 && key[3] == 0)
return 0;
dib0700_rc_setup(d, NULL);
d->last_event = 0;
switch (d->props.rc.core.protocol) {
case RC_BIT_NEC:
if ((key[3-2] == 0x00) && (key[3-3] == 0x00) &&
(key[3] == 0xff))
keycode = d->last_event;
else {
keycode = key[3-2] << 8 | key[3-3];
d->last_event = keycode;
}
rc_keydown(d->rc_dev, keycode, 0);
break;
default:
keycode = key[3-2] << 8 | key[3-3];
toggle = key[3-1];
rc_keydown(d->rc_dev, keycode, toggle);
break;
}
return 0;
}
static int stk7700p_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_state *st = adap->dev->priv;
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0); msleep(50);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1); msleep(10);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0); msleep(10);
dib0700_ctrl_clock(adap->dev, 72, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1); msleep(100);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
st->mt2060_if1[0] = 1220;
if (dib7000pc_detection(&adap->dev->i2c_adap)) {
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 18, &stk7700p_dib7000p_config);
st->is_dib7000pc = 1;
} else
adap->fe_adap[0].fe = dvb_attach(dib7000m_attach, &adap->dev->i2c_adap, 18, &stk7700p_dib7000m_config);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int stk7700p_tuner_attach(struct dvb_usb_adapter *adap)
{
struct i2c_adapter *prim_i2c = &adap->dev->i2c_adap;
struct dib0700_state *st = adap->dev->priv;
struct i2c_adapter *tun_i2c;
s8 a;
int if1=1220;
if (adap->dev->udev->descriptor.idVendor == cpu_to_le16(USB_VID_HAUPPAUGE) &&
adap->dev->udev->descriptor.idProduct == cpu_to_le16(USB_PID_HAUPPAUGE_NOVA_T_STICK)) {
if (!eeprom_read(prim_i2c,0x58,&a)) if1=1220+a;
}
if (st->is_dib7000pc)
tun_i2c = dib7000p_get_i2c_master(adap->fe_adap[0].fe, DIBX000_I2C_INTERFACE_TUNER, 1);
else
tun_i2c = dib7000m_get_i2c_master(adap->fe_adap[0].fe, DIBX000_I2C_INTERFACE_TUNER, 1);
return dvb_attach(mt2060_attach, adap->fe_adap[0].fe, tun_i2c, &stk7700p_mt2060_config,
if1) == NULL ? -ENODEV : 0;
}
static int dib7070_tuner_reset(struct dvb_frontend *fe, int onoff)
{
deb_info("reset: %d", onoff);
return dib7000p_set_gpio(fe, 8, 0, !onoff);
}
static int dib7070_tuner_sleep(struct dvb_frontend *fe, int onoff)
{
deb_info("sleep: %d", onoff);
return dib7000p_set_gpio(fe, 9, 0, onoff);
}
static int dib7070_set_param_override(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dib0700_adapter_state *state = adap->priv;
u16 offset;
u8 band = BAND_OF_FREQUENCY(p->frequency/1000);
switch (band) {
case BAND_VHF: offset = 950; break;
case BAND_UHF:
default: offset = 550; break;
}
deb_info("WBD for DiB7000P: %d\n", offset + dib0070_wbd_offset(fe));
dib7000p_set_wbd_ref(fe, offset + dib0070_wbd_offset(fe));
return state->set_param_save(fe);
}
static int dib7770_set_param_override(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dib0700_adapter_state *state = adap->priv;
u16 offset;
u8 band = BAND_OF_FREQUENCY(p->frequency/1000);
switch (band) {
case BAND_VHF:
dib7000p_set_gpio(fe, 0, 0, 1);
offset = 850;
break;
case BAND_UHF:
default:
dib7000p_set_gpio(fe, 0, 0, 0);
offset = 250;
break;
}
deb_info("WBD for DiB7000P: %d\n", offset + dib0070_wbd_offset(fe));
dib7000p_set_wbd_ref(fe, offset + dib0070_wbd_offset(fe));
return state->set_param_save(fe);
}
static int dib7770p_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c = dib7000p_get_i2c_master(adap->fe_adap[0].fe,
DIBX000_I2C_INTERFACE_TUNER, 1);
if (dvb_attach(dib0070_attach, adap->fe_adap[0].fe, tun_i2c,
&dib7770p_dib0070_config) == NULL)
return -ENODEV;
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib7770_set_param_override;
return 0;
}
static int dib7070p_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c = dib7000p_get_i2c_master(adap->fe_adap[0].fe, DIBX000_I2C_INTERFACE_TUNER, 1);
if (adap->id == 0) {
if (dvb_attach(dib0070_attach, adap->fe_adap[0].fe, tun_i2c, &dib7070p_dib0070_config[0]) == NULL)
return -ENODEV;
} else {
if (dvb_attach(dib0070_attach, adap->fe_adap[0].fe, tun_i2c, &dib7070p_dib0070_config[1]) == NULL)
return -ENODEV;
}
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib7070_set_param_override;
return 0;
}
static int stk7700p_pid_filter(struct dvb_usb_adapter *adapter, int index,
u16 pid, int onoff)
{
struct dib0700_state *st = adapter->dev->priv;
if (st->is_dib7000pc)
return dib7000p_pid_filter(adapter->fe_adap[0].fe, index, pid, onoff);
return dib7000m_pid_filter(adapter->fe_adap[0].fe, index, pid, onoff);
}
static int stk7700p_pid_filter_ctrl(struct dvb_usb_adapter *adapter, int onoff)
{
struct dib0700_state *st = adapter->dev->priv;
if (st->is_dib7000pc)
return dib7000p_pid_filter_ctrl(adapter->fe_adap[0].fe, onoff);
return dib7000m_pid_filter_ctrl(adapter->fe_adap[0].fe, onoff);
}
static int stk70x0p_pid_filter(struct dvb_usb_adapter *adapter, int index, u16 pid, int onoff)
{
return dib7000p_pid_filter(adapter->fe_adap[0].fe, index, pid, onoff);
}
static int stk70x0p_pid_filter_ctrl(struct dvb_usb_adapter *adapter, int onoff)
{
return dib7000p_pid_filter_ctrl(adapter->fe_adap[0].fe, onoff);
}
static int stk7070p_frontend_attach(struct dvb_usb_adapter *adap)
{
struct usb_device_descriptor *p = &adap->dev->udev->descriptor;
if (p->idVendor == cpu_to_le16(USB_VID_PINNACLE) &&
p->idProduct == cpu_to_le16(USB_PID_PINNACLE_PCTV72E))
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0);
else
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap, 1, 18,
&dib7070p_dib7000p_config) != 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n",
__func__);
return -ENODEV;
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 0x80,
&dib7070p_dib7000p_config);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int stk7770p_frontend_attach(struct dvb_usb_adapter *adap)
{
struct usb_device_descriptor *p = &adap->dev->udev->descriptor;
if (p->idVendor == cpu_to_le16(USB_VID_PINNACLE) &&
p->idProduct == cpu_to_le16(USB_PID_PINNACLE_PCTV72E))
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0);
else
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap, 1, 18,
&dib7770p_dib7000p_config) != 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n",
__func__);
return -ENODEV;
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 0x80,
&dib7770p_dib7000p_config);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int dib80xx_tuner_reset(struct dvb_frontend *fe, int onoff)
{
return dib8000_set_gpio(fe, 5, 0, !onoff);
}
static int dib80xx_tuner_sleep(struct dvb_frontend *fe, int onoff)
{
return dib8000_set_gpio(fe, 0, 0, onoff);
}
static int dib807x_set_param_override(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dib0700_adapter_state *state = adap->priv;
u16 offset = dib0070_wbd_offset(fe);
u8 band = BAND_OF_FREQUENCY(p->frequency/1000);
switch (band) {
case BAND_VHF:
offset += 750;
break;
case BAND_UHF:
default:
offset += 250; break;
}
deb_info("WBD for DiB8000: %d\n", offset);
dib8000_set_wbd_ref(fe, offset);
return state->set_param_save(fe);
}
static int dib807x_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c = dib8000_get_i2c_master(adap->fe_adap[0].fe,
DIBX000_I2C_INTERFACE_TUNER, 1);
if (adap->id == 0) {
if (dvb_attach(dib0070_attach, adap->fe_adap[0].fe, tun_i2c,
&dib807x_dib0070_config[0]) == NULL)
return -ENODEV;
} else {
if (dvb_attach(dib0070_attach, adap->fe_adap[0].fe, tun_i2c,
&dib807x_dib0070_config[1]) == NULL)
return -ENODEV;
}
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib807x_set_param_override;
return 0;
}
static int stk80xx_pid_filter(struct dvb_usb_adapter *adapter, int index,
u16 pid, int onoff)
{
return dib8000_pid_filter(adapter->fe_adap[0].fe, index, pid, onoff);
}
static int stk80xx_pid_filter_ctrl(struct dvb_usb_adapter *adapter,
int onoff)
{
return dib8000_pid_filter_ctrl(adapter->fe_adap[0].fe, onoff);
}
static int stk807x_frontend_attach(struct dvb_usb_adapter *adap)
{
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
dib8000_i2c_enumeration(&adap->dev->i2c_adap, 1, 18,
0x80, 0);
adap->fe_adap[0].fe = dvb_attach(dib8000_attach, &adap->dev->i2c_adap, 0x80,
&dib807x_dib8000_config[0]);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int stk807xpvr_frontend_attach0(struct dvb_usb_adapter *adap)
{
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0);
msleep(30);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(500);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
dib8000_i2c_enumeration(&adap->dev->i2c_adap, 1, 0x22, 0x80, 0);
adap->fe_adap[0].fe = dvb_attach(dib8000_attach, &adap->dev->i2c_adap, 0x80,
&dib807x_dib8000_config[0]);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int stk807xpvr_frontend_attach1(struct dvb_usb_adapter *adap)
{
dib8000_i2c_enumeration(&adap->dev->i2c_adap, 1, 0x12, 0x82, 0);
adap->fe_adap[0].fe = dvb_attach(dib8000_attach, &adap->dev->i2c_adap, 0x82,
&dib807x_dib8000_config[1]);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int dib8090_get_adc_power(struct dvb_frontend *fe)
{
return dib8000_get_adc_power(fe, 1);
}
static void dib8090_agc_control(struct dvb_frontend *fe, u8 restart)
{
deb_info("AGC control callback: %i\n", restart);
dib0090_dcc_freq(fe, restart);
if (restart == 0)
dib0090_set_dc_servo(fe, 1);
}
static u8 dib8090_compute_pll_parameters(struct dvb_frontend *fe)
{
u8 optimal_pll_ratio = 20;
u32 freq_adc, ratio, rest, max = 0;
u8 pll_ratio;
for (pll_ratio = 17; pll_ratio <= 20; pll_ratio++) {
freq_adc = 12 * pll_ratio * (1 << 8) / 16;
ratio = ((fe->dtv_property_cache.frequency / 1000) * (1 << 8) / 1000) / freq_adc;
rest = ((fe->dtv_property_cache.frequency / 1000) * (1 << 8) / 1000) - ratio * freq_adc;
if (rest > freq_adc / 2)
rest = freq_adc - rest;
deb_info("PLL ratio=%i rest=%i\n", pll_ratio, rest);
if ((rest > max) && (rest > 717)) {
optimal_pll_ratio = pll_ratio;
max = rest;
}
}
deb_info("optimal PLL ratio=%i\n", optimal_pll_ratio);
return optimal_pll_ratio;
}
static int dib8096_set_param_override(struct dvb_frontend *fe)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dib0700_adapter_state *state = adap->priv;
u8 pll_ratio, band = BAND_OF_FREQUENCY(fe->dtv_property_cache.frequency / 1000);
u16 target, ltgain, rf_gain_limit;
u32 timf;
int ret = 0;
enum frontend_tune_state tune_state = CT_SHUTDOWN;
switch (band) {
default:
deb_info("Warning : Rf frequency (%iHz) is not in the supported range, using VHF switch ", fe->dtv_property_cache.frequency);
case BAND_VHF:
dib8000_set_gpio(fe, 3, 0, 1);
break;
case BAND_UHF:
dib8000_set_gpio(fe, 3, 0, 0);
break;
}
ret = state->set_param_save(fe);
if (ret < 0)
return ret;
if (fe->dtv_property_cache.bandwidth_hz != 6000000) {
deb_info("only 6MHz bandwidth is supported\n");
return -EINVAL;
}
dib8000_update_pll(fe, &dib8090_pll_config_12mhz, fe->dtv_property_cache.bandwidth_hz / 1000, 0);
pll_ratio = dib8090_compute_pll_parameters(fe);
if (pll_ratio == 17)
timf = 21387946;
else if (pll_ratio == 18)
timf = 20199727;
else if (pll_ratio == 19)
timf = 19136583;
else
timf = 18179756;
dib8000_update_pll(fe, &dib8090_pll_config_12mhz, fe->dtv_property_cache.bandwidth_hz / 1000, pll_ratio);
dib8000_ctrl_timf(fe, DEMOD_TIMF_SET, timf);
if (band != BAND_CBAND) {
target = (dib0090_get_wbd_target(fe) * 8 * 18 / 33 + 1) / 2;
dib8000_set_wbd_ref(fe, target);
}
if (band == BAND_CBAND) {
deb_info("tuning in CBAND - soft-AGC startup\n");
dib0090_set_tune_state(fe, CT_AGC_START);
do {
ret = dib0090_gain_control(fe);
msleep(ret);
tune_state = dib0090_get_tune_state(fe);
if (tune_state == CT_AGC_STEP_0)
dib8000_set_gpio(fe, 6, 0, 1);
else if (tune_state == CT_AGC_STEP_1) {
dib0090_get_current_gain(fe, NULL, NULL, &rf_gain_limit, &ltgain);
if (rf_gain_limit < 2000)
dib8000_set_gpio(fe, 6, 0, 0);
}
} while (tune_state < CT_AGC_STOP);
deb_info("switching to PWM AGC\n");
dib0090_pwm_gain_reset(fe);
dib8000_pwm_agc_reset(fe);
dib8000_set_tune_state(fe, CT_DEMOD_START);
} else {
deb_info("not tuning in CBAND - standard AGC startup\n");
dib0090_pwm_gain_reset(fe);
}
return 0;
}
static int dib809x_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c = dib8000_get_i2c_master(adap->fe_adap[0].fe, DIBX000_I2C_INTERFACE_TUNER, 1);
if (dvb_attach(dib0090_register, adap->fe_adap[0].fe, tun_i2c, &dib809x_dib0090_config) == NULL)
return -ENODEV;
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib8096_set_param_override;
return 0;
}
static int stk809x_frontend_attach(struct dvb_usb_adapter *adap)
{
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
dib8000_i2c_enumeration(&adap->dev->i2c_adap, 1, 18, 0x80, 0);
adap->fe_adap[0].fe = dvb_attach(dib8000_attach, &adap->dev->i2c_adap, 0x80, &dib809x_dib8000_config[0]);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int nim8096md_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c;
struct dvb_frontend *fe_slave = dib8000_get_slave_frontend(adap->fe_adap[0].fe, 1);
if (fe_slave) {
tun_i2c = dib8000_get_i2c_master(fe_slave, DIBX000_I2C_INTERFACE_TUNER, 1);
if (dvb_attach(dib0090_register, fe_slave, tun_i2c, &dib809x_dib0090_config) == NULL)
return -ENODEV;
fe_slave->dvb = adap->fe_adap[0].fe->dvb;
fe_slave->ops.tuner_ops.set_params = dib8096_set_param_override;
}
tun_i2c = dib8000_get_i2c_master(adap->fe_adap[0].fe, DIBX000_I2C_INTERFACE_TUNER, 1);
if (dvb_attach(dib0090_register, adap->fe_adap[0].fe, tun_i2c, &dib809x_dib0090_config) == NULL)
return -ENODEV;
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib8096_set_param_override;
return 0;
}
static int nim8096md_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_frontend *fe_slave;
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(1000);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
dib8000_i2c_enumeration(&adap->dev->i2c_adap, 2, 18, 0x80, 0);
adap->fe_adap[0].fe = dvb_attach(dib8000_attach, &adap->dev->i2c_adap, 0x80, &dib809x_dib8000_config[0]);
if (adap->fe_adap[0].fe == NULL)
return -ENODEV;
fe_slave = dvb_attach(dib8000_attach, &adap->dev->i2c_adap, 0x82, &dib809x_dib8000_config[1]);
dib8000_set_slave_frontend(adap->fe_adap[0].fe, fe_slave);
return fe_slave == NULL ? -ENODEV : 0;
}
static int dib8096p_get_best_sampling(struct dvb_frontend *fe, struct dibx090p_best_adc *adc)
{
u8 spur = 0, prediv = 0, loopdiv = 0, min_prediv = 1, max_prediv = 1;
u16 xtal = 12000;
u16 fcp_min = 1900;
u16 fcp_max = 20000;
u32 fmem_max = 140000;
u32 fdem_min = 66000;
u32 fcp = 0, fs = 0, fdem = 0, fmem = 0;
u32 harmonic_id = 0;
adc->timf = 0;
adc->pll_loopdiv = loopdiv;
adc->pll_prediv = prediv;
deb_info("bandwidth = %d", fe->dtv_property_cache.bandwidth_hz);
while ((xtal / max_prediv) >= fcp_min)
max_prediv++;
max_prediv--;
min_prediv = max_prediv;
while ((xtal / min_prediv) <= fcp_max) {
min_prediv--;
if (min_prediv == 1)
break;
}
deb_info("MIN prediv = %d : MAX prediv = %d", min_prediv, max_prediv);
min_prediv = 1;
for (prediv = min_prediv; prediv < max_prediv; prediv++) {
fcp = xtal / prediv;
if (fcp > fcp_min && fcp < fcp_max) {
for (loopdiv = 1; loopdiv < 64; loopdiv++) {
fmem = ((xtal/prediv) * loopdiv);
fdem = fmem / 2;
fs = fdem / 4;
if ((fdem >= fdem_min) && (fmem <= fmem_max) && (fs >= fe->dtv_property_cache.bandwidth_hz / 1000)) {
spur = 0;
for (harmonic_id = (fe->dtv_property_cache.frequency / (1000 * fs)); harmonic_id <= ((fe->dtv_property_cache.frequency / (1000 * fs)) + 1); harmonic_id++) {
if (((fs * harmonic_id) >= (fe->dtv_property_cache.frequency / 1000 - (fe->dtv_property_cache.bandwidth_hz / 2000))) && ((fs * harmonic_id) <= (fe->dtv_property_cache.frequency / 1000 + (fe->dtv_property_cache.bandwidth_hz / 2000)))) {
spur = 1;
break;
}
}
if (!spur) {
adc->pll_loopdiv = loopdiv;
adc->pll_prediv = prediv;
adc->timf = (4260880253U / fdem) * (1 << 8);
adc->timf += ((4260880253U % fdem) << 8) / fdem;
deb_info("RF %6d; BW %6d; Xtal %6d; Fmem %6d; Fdem %6d; Fs %6d; Prediv %2d; Loopdiv %2d; Timf %8d;", fe->dtv_property_cache.frequency, fe->dtv_property_cache.bandwidth_hz, xtal, fmem, fdem, fs, prediv, loopdiv, adc->timf);
break;
}
}
}
}
if (!spur)
break;
}
if (adc->pll_loopdiv == 0 && adc->pll_prediv == 0)
return -EINVAL;
return 0;
}
static int dib8096p_agc_startup(struct dvb_frontend *fe)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dib0700_adapter_state *state = adap->priv;
struct dibx000_bandwidth_config pll;
struct dibx090p_best_adc adc;
u16 target;
int ret;
ret = state->set_param_save(fe);
if (ret < 0)
return ret;
memset(&pll, 0, sizeof(struct dibx000_bandwidth_config));
dib0090_pwm_gain_reset(fe);
target = (dib0090_get_wbd_target(fe) * 8 + 1) / 2;
dib8000_set_wbd_ref(fe, target);
if (dib8096p_get_best_sampling(fe, &adc) == 0) {
pll.pll_ratio = adc.pll_loopdiv;
pll.pll_prediv = adc.pll_prediv;
dib0700_set_i2c_speed(adap->dev, 200);
dib8000_update_pll(fe, &pll, fe->dtv_property_cache.bandwidth_hz / 1000, 0);
dib8000_ctrl_timf(fe, DEMOD_TIMF_SET, adc.timf);
dib0700_set_i2c_speed(adap->dev, 1000);
}
return 0;
}
static int tfe8096p_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_state *st = adap->dev->priv;
u32 fw_version;
dib0700_get_version(adap->dev, NULL, NULL, &fw_version, NULL);
if (fw_version >= 0x10200)
st->fw_use_new_i2c_api = 1;
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
dib8000_i2c_enumeration(&adap->dev->i2c_adap, 1, 0x10, 0x80, 1);
adap->fe_adap[0].fe = dvb_attach(dib8000_attach,
&adap->dev->i2c_adap, 0x80, &tfe8096p_dib8000_config);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int tfe8096p_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c = dib8096p_get_i2c_tuner(adap->fe_adap[0].fe);
if (dvb_attach(dib0090_register, adap->fe_adap[0].fe, tun_i2c,
&tfe8096p_dib0090_config) == NULL)
return -ENODEV;
dib8000_set_gpio(adap->fe_adap[0].fe, 8, 0, 1);
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib8096p_agc_startup;
return 0;
}
static int dib90x0_pid_filter(struct dvb_usb_adapter *adapter, int index, u16 pid, int onoff)
{
return dib9000_fw_pid_filter(adapter->fe_adap[0].fe, index, pid, onoff);
}
static int dib90x0_pid_filter_ctrl(struct dvb_usb_adapter *adapter, int onoff)
{
return dib9000_fw_pid_filter_ctrl(adapter->fe_adap[0].fe, onoff);
}
static int dib90x0_tuner_reset(struct dvb_frontend *fe, int onoff)
{
return dib9000_set_gpio(fe, 5, 0, !onoff);
}
static int dib90x0_tuner_sleep(struct dvb_frontend *fe, int onoff)
{
return dib9000_set_gpio(fe, 0, 0, onoff);
}
static int dib01x0_pmu_update(struct i2c_adapter *i2c, u16 *data, u8 len)
{
u8 wb[4] = { 0xc >> 8, 0xc & 0xff, 0, 0 };
u8 rb[2];
struct i2c_msg msg[2] = {
{.addr = 0x1e >> 1, .flags = 0, .buf = wb, .len = 2},
{.addr = 0x1e >> 1, .flags = I2C_M_RD, .buf = rb, .len = 2},
};
u8 index_data;
dibx000_i2c_set_speed(i2c, 250);
if (i2c_transfer(i2c, msg, 2) != 2)
return -EIO;
switch (rb[0] << 8 | rb[1]) {
case 0:
deb_info("Found DiB0170 rev1: This version of DiB0170 is not supported any longer.\n");
return -EIO;
case 1:
deb_info("Found DiB0170 rev2");
break;
case 2:
deb_info("Found DiB0190 rev2");
break;
default:
deb_info("DiB01x0 not found");
return -EIO;
}
for (index_data = 0; index_data < len; index_data += 2) {
wb[2] = (data[index_data + 1] >> 8) & 0xff;
wb[3] = (data[index_data + 1]) & 0xff;
if (data[index_data] == 0) {
wb[0] = (data[index_data] >> 8) & 0xff;
wb[1] = (data[index_data]) & 0xff;
msg[0].len = 2;
if (i2c_transfer(i2c, msg, 2) != 2)
return -EIO;
wb[2] |= rb[0];
wb[3] |= rb[1] & ~(3 << 4);
}
wb[0] = (data[index_data] >> 8)&0xff;
wb[1] = (data[index_data])&0xff;
msg[0].len = 4;
if (i2c_transfer(i2c, &msg[0], 1) != 1)
return -EIO;
}
return 0;
}
static int stk9090m_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *state = adap->priv;
struct dib0700_state *st = adap->dev->priv;
u32 fw_version;
dib0700_get_version(adap->dev, NULL, NULL, &fw_version, NULL);
if (fw_version >= 0x10200)
st->fw_use_new_i2c_api = 1;
dib0700_set_i2c_speed(adap->dev, 340);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
dib9000_i2c_enumeration(&adap->dev->i2c_adap, 1, 0x10, 0x80);
if (request_firmware(&state->frontend_firmware, "dib9090.fw", &adap->dev->udev->dev)) {
deb_info("%s: Upload failed. (file not found?)\n", __func__);
return -ENODEV;
} else {
deb_info("%s: firmware read %Zu bytes.\n", __func__, state->frontend_firmware->size);
}
stk9090m_config.microcode_B_fe_size = state->frontend_firmware->size;
stk9090m_config.microcode_B_fe_buffer = state->frontend_firmware->data;
adap->fe_adap[0].fe = dvb_attach(dib9000_attach, &adap->dev->i2c_adap, 0x80, &stk9090m_config);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int dib9090_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *state = adap->priv;
struct i2c_adapter *i2c = dib9000_get_tuner_interface(adap->fe_adap[0].fe);
u16 data_dib190[10] = {
1, 0x1374,
2, 0x01a2,
7, 0x0020,
0, 0x00ef,
8, 0x0486,
};
if (dvb_attach(dib0090_fw_register, adap->fe_adap[0].fe, i2c, &dib9090_dib0090_config) == NULL)
return -ENODEV;
i2c = dib9000_get_i2c_master(adap->fe_adap[0].fe, DIBX000_I2C_INTERFACE_GPIO_1_2, 0);
if (dib01x0_pmu_update(i2c, data_dib190, 10) != 0)
return -ENODEV;
dib0700_set_i2c_speed(adap->dev, 1500);
if (dib9000_firmware_post_pll_init(adap->fe_adap[0].fe) < 0)
return -ENODEV;
release_firmware(state->frontend_firmware);
return 0;
}
static int nim9090md_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *state = adap->priv;
struct dib0700_state *st = adap->dev->priv;
struct i2c_adapter *i2c;
struct dvb_frontend *fe_slave;
u32 fw_version;
dib0700_get_version(adap->dev, NULL, NULL, &fw_version, NULL);
if (fw_version >= 0x10200)
st->fw_use_new_i2c_api = 1;
dib0700_set_i2c_speed(adap->dev, 340);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
if (request_firmware(&state->frontend_firmware, "dib9090.fw", &adap->dev->udev->dev)) {
deb_info("%s: Upload failed. (file not found?)\n", __func__);
return -EIO;
} else {
deb_info("%s: firmware read %Zu bytes.\n", __func__, state->frontend_firmware->size);
}
nim9090md_config[0].microcode_B_fe_size = state->frontend_firmware->size;
nim9090md_config[0].microcode_B_fe_buffer = state->frontend_firmware->data;
nim9090md_config[1].microcode_B_fe_size = state->frontend_firmware->size;
nim9090md_config[1].microcode_B_fe_buffer = state->frontend_firmware->data;
dib9000_i2c_enumeration(&adap->dev->i2c_adap, 1, 0x20, 0x80);
adap->fe_adap[0].fe = dvb_attach(dib9000_attach, &adap->dev->i2c_adap, 0x80, &nim9090md_config[0]);
if (adap->fe_adap[0].fe == NULL)
return -ENODEV;
i2c = dib9000_get_i2c_master(adap->fe_adap[0].fe, DIBX000_I2C_INTERFACE_GPIO_3_4, 0);
dib9000_i2c_enumeration(i2c, 1, 0x12, 0x82);
fe_slave = dvb_attach(dib9000_attach, i2c, 0x82, &nim9090md_config[1]);
dib9000_set_slave_frontend(adap->fe_adap[0].fe, fe_slave);
return fe_slave == NULL ? -ENODEV : 0;
}
static int nim9090md_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *state = adap->priv;
struct i2c_adapter *i2c;
struct dvb_frontend *fe_slave;
u16 data_dib190[10] = {
1, 0x5374,
2, 0x01ae,
7, 0x0020,
0, 0x00ef,
8, 0x0406,
};
i2c = dib9000_get_tuner_interface(adap->fe_adap[0].fe);
if (dvb_attach(dib0090_fw_register, adap->fe_adap[0].fe, i2c, &nim9090md_dib0090_config[0]) == NULL)
return -ENODEV;
i2c = dib9000_get_i2c_master(adap->fe_adap[0].fe, DIBX000_I2C_INTERFACE_GPIO_1_2, 0);
if (dib01x0_pmu_update(i2c, data_dib190, 10) < 0)
return -ENODEV;
dib0700_set_i2c_speed(adap->dev, 1500);
if (dib9000_firmware_post_pll_init(adap->fe_adap[0].fe) < 0)
return -ENODEV;
fe_slave = dib9000_get_slave_frontend(adap->fe_adap[0].fe, 1);
if (fe_slave != NULL) {
i2c = dib9000_get_component_bus_interface(adap->fe_adap[0].fe);
dib9000_set_i2c_adapter(fe_slave, i2c);
i2c = dib9000_get_tuner_interface(fe_slave);
if (dvb_attach(dib0090_fw_register, fe_slave, i2c, &nim9090md_dib0090_config[1]) == NULL)
return -ENODEV;
fe_slave->dvb = adap->fe_adap[0].fe->dvb;
dib9000_fw_set_component_bus_speed(adap->fe_adap[0].fe, 1500);
if (dib9000_firmware_post_pll_init(fe_slave) < 0)
return -ENODEV;
}
release_firmware(state->frontend_firmware);
return 0;
}
static int dib7090p_get_best_sampling(struct dvb_frontend *fe , struct dibx090p_best_adc *adc)
{
u8 spur = 0, prediv = 0, loopdiv = 0, min_prediv = 1, max_prediv = 1;
u16 xtal = 12000;
u32 fcp_min = 1900;
u32 fcp_max = 20000;
u32 fdem_max = 76000;
u32 fdem_min = 69500;
u32 fcp = 0, fs = 0, fdem = 0;
u32 harmonic_id = 0;
adc->pll_loopdiv = loopdiv;
adc->pll_prediv = prediv;
adc->timf = 0;
deb_info("bandwidth = %d fdem_min =%d", fe->dtv_property_cache.bandwidth_hz, fdem_min);
while ((xtal/max_prediv) >= fcp_min)
max_prediv++;
max_prediv--;
min_prediv = max_prediv;
while ((xtal/min_prediv) <= fcp_max) {
min_prediv--;
if (min_prediv == 1)
break;
}
deb_info("MIN prediv = %d : MAX prediv = %d", min_prediv, max_prediv);
min_prediv = 2;
for (prediv = min_prediv ; prediv < max_prediv; prediv++) {
fcp = xtal / prediv;
if (fcp > fcp_min && fcp < fcp_max) {
for (loopdiv = 1 ; loopdiv < 64 ; loopdiv++) {
fdem = ((xtal/prediv) * loopdiv);
fs = fdem / 4;
if ((fdem >= fdem_min) && (fdem <= fdem_max) && (fs >= fe->dtv_property_cache.bandwidth_hz/1000)) {
spur = 0;
for (harmonic_id = (fe->dtv_property_cache.frequency / (1000*fs)) ; harmonic_id <= ((fe->dtv_property_cache.frequency / (1000*fs))+1) ; harmonic_id++) {
if (((fs*harmonic_id) >= ((fe->dtv_property_cache.frequency/1000) - (fe->dtv_property_cache.bandwidth_hz/2000))) && ((fs*harmonic_id) <= ((fe->dtv_property_cache.frequency/1000) + (fe->dtv_property_cache.bandwidth_hz/2000)))) {
spur = 1;
break;
}
}
if (!spur) {
adc->pll_loopdiv = loopdiv;
adc->pll_prediv = prediv;
adc->timf = 2396745143UL/fdem*(1 << 9);
adc->timf += ((2396745143UL%fdem) << 9)/fdem;
deb_info("loopdiv=%i prediv=%i timf=%i", loopdiv, prediv, adc->timf);
break;
}
}
}
}
if (!spur)
break;
}
if (adc->pll_loopdiv == 0 && adc->pll_prediv == 0)
return -EINVAL;
else
return 0;
}
static int dib7090_agc_startup(struct dvb_frontend *fe)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dib0700_adapter_state *state = adap->priv;
struct dibx000_bandwidth_config pll;
u16 target;
struct dibx090p_best_adc adc;
int ret;
ret = state->set_param_save(fe);
if (ret < 0)
return ret;
memset(&pll, 0, sizeof(struct dibx000_bandwidth_config));
dib0090_pwm_gain_reset(fe);
target = (dib0090_get_wbd_target(fe) * 8 + 1) / 2;
dib7000p_set_wbd_ref(fe, target);
if (dib7090p_get_best_sampling(fe, &adc) == 0) {
pll.pll_ratio = adc.pll_loopdiv;
pll.pll_prediv = adc.pll_prediv;
dib7000p_update_pll(fe, &pll);
dib7000p_ctrl_timf(fe, DEMOD_TIMF_SET, adc.timf);
}
return 0;
}
static int dib7090_agc_restart(struct dvb_frontend *fe, u8 restart)
{
deb_info("AGC restart callback: %d", restart);
if (restart == 0)
dib0090_set_dc_servo(fe, 1);
return 0;
}
static int tfe7790p_update_lna(struct dvb_frontend *fe, u16 agc_global)
{
deb_info("update LNA: agc global=%i", agc_global);
if (agc_global < 25000) {
dib7000p_set_gpio(fe, 8, 0, 0);
dib7000p_set_agc1_min(fe, 0);
} else {
dib7000p_set_gpio(fe, 8, 0, 1);
dib7000p_set_agc1_min(fe, 32768);
}
return 0;
}
static int tfe7090p_pvr_update_lna(struct dvb_frontend *fe, u16 agc_global)
{
deb_info("TFE7090P-PVR update LNA: agc global=%i", agc_global);
if (agc_global < 25000) {
dib7000p_set_gpio(fe, 5, 0, 0);
dib7000p_set_agc1_min(fe, 0);
} else {
dib7000p_set_gpio(fe, 5, 0, 1);
dib7000p_set_agc1_min(fe, 32768);
}
return 0;
}
static int nim7090_frontend_attach(struct dvb_usb_adapter *adap)
{
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap, 1, 0x10, &nim7090_dib7000p_config) != 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n", __func__);
return -ENODEV;
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 0x80, &nim7090_dib7000p_config);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int nim7090_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c = dib7090_get_i2c_tuner(adap->fe_adap[0].fe);
if (dvb_attach(dib0090_register, adap->fe_adap[0].fe, tun_i2c, &nim7090_dib0090_config) == NULL)
return -ENODEV;
dib7000p_set_gpio(adap->fe_adap[0].fe, 8, 0, 1);
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib7090_agc_startup;
return 0;
}
static int tfe7090pvr_frontend0_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_state *st = adap->dev->priv;
st->disable_streaming_master_mode = 1;
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap, 1, 0x20, &tfe7090pvr_dib7000p_config[0]) != 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n", __func__);
return -ENODEV;
}
dib0700_set_i2c_speed(adap->dev, 340);
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 0x90, &tfe7090pvr_dib7000p_config[0]);
if (adap->fe_adap[0].fe == NULL)
return -ENODEV;
dib7090_slave_reset(adap->fe_adap[0].fe);
return 0;
}
static int tfe7090pvr_frontend1_attach(struct dvb_usb_adapter *adap)
{
struct i2c_adapter *i2c;
if (adap->dev->adapter[0].fe_adap[0].fe == NULL) {
err("the master dib7090 has to be initialized first");
return -ENODEV;
}
i2c = dib7000p_get_i2c_master(adap->dev->adapter[0].fe_adap[0].fe, DIBX000_I2C_INTERFACE_GPIO_6_7, 1);
if (dib7000p_i2c_enumeration(i2c, 1, 0x10, &tfe7090pvr_dib7000p_config[1]) != 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n", __func__);
return -ENODEV;
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, i2c, 0x92, &tfe7090pvr_dib7000p_config[1]);
dib0700_set_i2c_speed(adap->dev, 200);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int tfe7090pvr_tuner0_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c = dib7090_get_i2c_tuner(adap->fe_adap[0].fe);
if (dvb_attach(dib0090_register, adap->fe_adap[0].fe, tun_i2c, &tfe7090pvr_dib0090_config[0]) == NULL)
return -ENODEV;
dib7000p_set_gpio(adap->fe_adap[0].fe, 8, 0, 1);
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib7090_agc_startup;
return 0;
}
static int tfe7090pvr_tuner1_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c = dib7090_get_i2c_tuner(adap->fe_adap[0].fe);
if (dvb_attach(dib0090_register, adap->fe_adap[0].fe, tun_i2c, &tfe7090pvr_dib0090_config[1]) == NULL)
return -ENODEV;
dib7000p_set_gpio(adap->fe_adap[0].fe, 8, 0, 1);
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib7090_agc_startup;
return 0;
}
static int tfe7790p_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_state *st = adap->dev->priv;
st->disable_streaming_master_mode = 1;
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
msleep(20);
dib0700_ctrl_clock(adap->dev, 72, 1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(20);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap,
1, 0x10, &tfe7790p_dib7000p_config) != 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n",
__func__);
return -ENODEV;
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap,
0x80, &tfe7790p_dib7000p_config);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int tfe7790p_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c =
dib7090_get_i2c_tuner(adap->fe_adap[0].fe);
if (dvb_attach(dib0090_register, adap->fe_adap[0].fe, tun_i2c,
&tfe7790p_dib0090_config) == NULL)
return -ENODEV;
dib7000p_set_gpio(adap->fe_adap[0].fe, 8, 0, 1);
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib7090_agc_startup;
return 0;
}
static void stk7070pd_init(struct dvb_usb_device *dev)
{
dib0700_set_gpio(dev, GPIO6, GPIO_OUT, 1);
msleep(10);
dib0700_set_gpio(dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(dev, GPIO10, GPIO_OUT, 0);
dib0700_ctrl_clock(dev, 72, 1);
msleep(10);
dib0700_set_gpio(dev, GPIO10, GPIO_OUT, 1);
}
static int stk7070pd_frontend_attach0(struct dvb_usb_adapter *adap)
{
stk7070pd_init(adap->dev);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap, 2, 18,
stk7070pd_dib7000p_config) != 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n",
__func__);
return -ENODEV;
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 0x80, &stk7070pd_dib7000p_config[0]);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int stk7070pd_frontend_attach1(struct dvb_usb_adapter *adap)
{
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 0x82, &stk7070pd_dib7000p_config[1]);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int novatd_read_status_override(struct dvb_frontend *fe,
fe_status_t *stat)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dvb_usb_device *dev = adap->dev;
struct dib0700_state *state = dev->priv;
int ret;
ret = state->read_status(fe, stat);
if (!ret)
dib0700_set_gpio(dev, adap->id == 0 ? GPIO1 : GPIO0, GPIO_OUT,
!!(*stat & FE_HAS_LOCK));
return ret;
}
static int novatd_sleep_override(struct dvb_frontend* fe)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dvb_usb_device *dev = adap->dev;
struct dib0700_state *state = dev->priv;
dib0700_set_gpio(dev, adap->id == 0 ? GPIO1 : GPIO0, GPIO_OUT, 0);
return state->sleep(fe);
}
static int novatd_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *dev = adap->dev;
struct dib0700_state *st = dev->priv;
if (adap->id == 0) {
stk7070pd_init(dev);
dib0700_set_gpio(dev, GPIO0, GPIO_OUT, 0);
dib0700_set_gpio(dev, GPIO1, GPIO_OUT, 0);
dib0700_set_gpio(dev, GPIO2, GPIO_OUT, 1);
if (dib7000p_i2c_enumeration(&dev->i2c_adap, 2, 18,
stk7070pd_dib7000p_config) != 0) {
err("%s: dib7000p_i2c_enumeration failed. Cannot continue\n",
__func__);
return -ENODEV;
}
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &dev->i2c_adap,
adap->id == 0 ? 0x80 : 0x82,
&stk7070pd_dib7000p_config[adap->id]);
if (adap->fe_adap[0].fe == NULL)
return -ENODEV;
st->read_status = adap->fe_adap[0].fe->ops.read_status;
adap->fe_adap[0].fe->ops.read_status = novatd_read_status_override;
st->sleep = adap->fe_adap[0].fe->ops.sleep;
adap->fe_adap[0].fe->ops.sleep = novatd_sleep_override;
return 0;
}
static int s5h1411_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_state *st = adap->dev->priv;
st->fw_use_new_i2c_api = 1;
st->disable_streaming_master_mode = 1;
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 0);
dib0700_set_gpio(adap->dev, GPIO3, GPIO_OUT, 0);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(400);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
msleep(60);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(30);
dib0700_set_gpio(adap->dev, GPIO0, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO9, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO4, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO7, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO2, GPIO_OUT, 0);
msleep(30);
dib0700_set_gpio(adap->dev, GPIO2, GPIO_OUT, 1);
adap->fe_adap[0].fe = dvb_attach(s5h1411_attach, &pinnacle_801e_config,
&adap->dev->i2c_adap);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int dib0700_xc5000_tuner_callback(void *priv, int component,
int command, int arg)
{
struct dvb_usb_adapter *adap = priv;
if (command == XC5000_TUNER_RESET) {
dib0700_set_gpio(adap->dev, GPIO1, GPIO_OUT, 0);
msleep(10);
dib0700_set_gpio(adap->dev, GPIO1, GPIO_OUT, 1);
msleep(10);
} else {
err("xc5000: unknown tuner callback command: %d\n", command);
return -EINVAL;
}
return 0;
}
static int xc5000_tuner_attach(struct dvb_usb_adapter *adap)
{
adap->fe_adap[0].fe->callback = dib0700_xc5000_tuner_callback;
return dvb_attach(xc5000_attach, adap->fe_adap[0].fe, &adap->dev->i2c_adap,
&s5h1411_xc5000_tunerconfig)
== NULL ? -ENODEV : 0;
}
static int dib0700_xc4000_tuner_callback(void *priv, int component,
int command, int arg)
{
struct dvb_usb_adapter *adap = priv;
if (command == XC4000_TUNER_RESET) {
dib7000p_set_gpio(adap->fe_adap[0].fe, 8, 0, 0);
msleep(10);
dib7000p_set_gpio(adap->fe_adap[0].fe, 8, 0, 1);
} else {
err("xc4000: unknown tuner callback command: %d\n", command);
return -EINVAL;
}
return 0;
}
static int pctv340e_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_state *st = adap->dev->priv;
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0);
msleep(50);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(100);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
msleep(1);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO8, GPIO_OUT, 1);
dib0700_set_gpio(adap->dev, GPIO2, GPIO_OUT, 1);
dib0700_ctrl_clock(adap->dev, 72, 1);
msleep(500);
if (dib7000pc_detection(&adap->dev->i2c_adap) == 0) {
return -ENODEV;
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 0x12,
&pctv_340e_config);
st->is_dib7000pc = 1;
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int xc4000_tuner_attach(struct dvb_usb_adapter *adap)
{
struct i2c_adapter *tun_i2c;
tun_i2c = dib7000p_get_i2c_master(adap->fe_adap[0].fe,
DIBX000_I2C_INTERFACE_TUNER, 1);
if (tun_i2c == NULL) {
printk(KERN_ERR "Could not reach tuner i2c bus\n");
return 0;
}
adap->fe_adap[0].fe->callback = dib0700_xc4000_tuner_callback;
return dvb_attach(xc4000_attach, adap->fe_adap[0].fe, tun_i2c,
&dib7000p_xc4000_tunerconfig)
== NULL ? -ENODEV : 0;
}
static int lgdt3305_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_state *st = adap->dev->priv;
st->fw_use_new_i2c_api = 1;
st->disable_streaming_master_mode = 1;
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 0);
msleep(30);
dib0700_set_gpio(adap->dev, GPIO6, GPIO_OUT, 1);
msleep(30);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(30);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 0);
msleep(30);
dib0700_set_gpio(adap->dev, GPIO10, GPIO_OUT, 1);
msleep(30);
adap->fe_adap[0].fe = dvb_attach(lgdt3305_attach,
&hcw_lgdt3305_config,
&adap->dev->i2c_adap);
return adap->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int mxl5007t_tuner_attach(struct dvb_usb_adapter *adap)
{
return dvb_attach(mxl5007t_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap, 0x60,
&hcw_mxl5007t_config) == NULL ? -ENODEV : 0;
}
