static inline int m920x_read(struct usb_device *udev, u8 request, u16 value,
u16 index, void *data, int size)
{
int ret;
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
request, USB_TYPE_VENDOR | USB_DIR_IN,
value, index, data, size, 2000);
if (ret < 0) {
printk(KERN_INFO "m920x_read = error: %d\n", ret);
return ret;
}
if (ret != size) {
deb("m920x_read = no data\n");
return -EIO;
}
return 0;
}
static inline int m920x_write(struct usb_device *udev, u8 request,
u16 value, u16 index)
{
int ret;
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
request, USB_TYPE_VENDOR | USB_DIR_OUT,
value, index, NULL, 0, 2000);
return ret;
}
static int m920x_init(struct dvb_usb_device *d, struct m920x_inits *rc_seq)
{
int ret = 0, i, epi, flags = 0;
int adap_enabled[M9206_MAX_ADAPTERS] = { 0 };
if (d->props.rc.legacy.rc_query) {
deb("Initialising remote control\n");
while (rc_seq->address) {
if ((ret = m920x_write(d->udev, M9206_CORE,
rc_seq->data,
rc_seq->address)) != 0) {
deb("Initialising remote control failed\n");
return ret;
}
rc_seq++;
}
deb("Initialising remote control success\n");
}
for (i = 0; i < d->props.num_adapters; i++)
flags |= d->adapter[i].props.caps;
if (flags & DVB_USB_ADAP_HAS_PID_FILTER) {
for (i = 0; i < d->props.num_adapters; i++) {
epi = d->adapter[i].props.stream.endpoint - 0x81;
if (epi < 0 || epi >= M9206_MAX_ADAPTERS) {
printk(KERN_INFO "m920x: Unexpected adapter endpoint!\n");
return -EINVAL;
}
adap_enabled[epi] = 1;
}
for (i = 0; i < M9206_MAX_ADAPTERS; i++) {
if (adap_enabled[i])
continue;
if ((ret = m920x_set_filter(d, 0x81 + i, 0, 0x0)) != 0)
return ret;
if ((ret = m920x_set_filter(d, 0x81 + i, 0, 0x02f5)) != 0)
return ret;
}
}
return ret;
}
static int m920x_init_ep(struct usb_interface *intf)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct usb_host_interface *alt;
if ((alt = usb_altnum_to_altsetting(intf, 1)) == NULL) {
deb("No alt found!\n");
return -ENODEV;
}
return usb_set_interface(udev, alt->desc.bInterfaceNumber,
alt->desc.bAlternateSetting);
}
static int m920x_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
struct m920x_state *m = d->priv;
int i, ret = 0;
u8 *rc_state;
rc_state = kmalloc(2, GFP_KERNEL);
if (!rc_state)
return -ENOMEM;
if ((ret = m920x_read(d->udev, M9206_CORE, 0x0, M9206_RC_STATE, rc_state, 1)) != 0)
goto out;
if ((ret = m920x_read(d->udev, M9206_CORE, 0x0, M9206_RC_KEY, rc_state + 1, 1)) != 0)
goto out;
for (i = 0; i < d->props.rc.legacy.rc_map_size; i++)
if (rc5_data(&d->props.rc.legacy.rc_map_table[i]) == rc_state[1]) {
*event = d->props.rc.legacy.rc_map_table[i].keycode;
switch(rc_state[0]) {
case 0x80:
*state = REMOTE_NO_KEY_PRESSED;
goto out;
case 0x88:
case 0x99:
case 0xc0:
case 0xd8:
*state = REMOTE_NO_KEY_PRESSED;
m->rep_count = 0;
goto out;
case 0x93:
case 0x92:
case 0x83:
case 0x82:
m->rep_count = 0;
*state = REMOTE_KEY_PRESSED;
goto out;
case 0x91:
case 0x81:
if (++m->rep_count > 2)
*state = REMOTE_KEY_REPEAT;
else
*state = REMOTE_NO_KEY_PRESSED;
goto out;
default:
deb("Unexpected rc state %02x\n", rc_state[0]);
*state = REMOTE_NO_KEY_PRESSED;
goto out;
}
}
if (rc_state[1] != 0)
deb("Unknown rc key %02x\n", rc_state[1]);
*state = REMOTE_NO_KEY_PRESSED;
out:
kfree(rc_state);
return ret;
}
static int m920x_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[], int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int i, j;
int ret = 0;
if (!num)
return -EINVAL;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (i = 0; i < num; i++) {
if (msg[i].flags & (I2C_M_NO_RD_ACK | I2C_M_IGNORE_NAK | I2C_M_TEN) || msg[i].len == 0) {
ret = -ENOTSUPP;
goto unlock;
}
if (!(msg[i].flags & I2C_M_NOSTART)) {
if ((ret = m920x_write(d->udev, M9206_I2C,
(msg[i].addr << 1) |
(msg[i].flags & I2C_M_RD ? 0x01 : 0), 0x80)) != 0)
goto unlock;
}
if (msg[i].flags & I2C_M_RD) {
for (j = 0; j < msg[i].len; j++) {
int stop = (i+1 == num && j+1 == msg[i].len) ? 0x40 : 0x01;
if ((ret = m920x_read(d->udev, M9206_I2C, 0x0,
0x20 | stop,
&msg[i].buf[j], 1)) != 0)
goto unlock;
}
} else {
for (j = 0; j < msg[i].len; j++) {
int stop = (i+1 == num && j+1 == msg[i].len) ? 0x40 : 0x00;
if ((ret = m920x_write(d->udev, M9206_I2C, msg[i].buf[j], stop)) != 0)
goto unlock;
}
}
}
ret = num;
unlock:
mutex_unlock(&d->i2c_mutex);
return ret;
}
static u32 m920x_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int m920x_set_filter(struct dvb_usb_device *d, int type, int idx, int pid)
{
int ret = 0;
if (pid >= 0x8000)
return -EINVAL;
pid |= 0x8000;
if ((ret = m920x_write(d->udev, M9206_FILTER, pid, (type << 8) | (idx * 4) )) != 0)
return ret;
if ((ret = m920x_write(d->udev, M9206_FILTER, 0, (type << 8) | (idx * 4) )) != 0)
return ret;
return ret;
}
static int m920x_update_filters(struct dvb_usb_adapter *adap)
{
struct m920x_state *m = adap->dev->priv;
int enabled = m->filtering_enabled[adap->id];
int i, ret = 0, filter = 0;
int ep = adap->props.stream.endpoint;
for (i = 0; i < M9206_MAX_FILTERS; i++)
if (m->filters[adap->id][i] == 8192)
enabled = 0;
if ((ret = m920x_set_filter(adap->dev, ep, 1, enabled)) != 0)
return ret;
for (i = 0; i < M9206_MAX_FILTERS; i++)
if ((ret = m920x_set_filter(adap->dev, ep, i + 2, 0)) != 0)
return ret;
if (enabled) {
for (i = 0; i < M9206_MAX_FILTERS; i++) {
if (m->filters[adap->id][i] == 0)
continue;
if ((ret = m920x_set_filter(adap->dev, ep, filter + 2, m->filters[adap->id][i])) != 0)
return ret;
filter++;
}
}
return ret;
}
static int m920x_pid_filter_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct m920x_state *m = adap->dev->priv;
m->filtering_enabled[adap->id] = onoff ? 1 : 0;
return m920x_update_filters(adap);
}
static int m920x_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid, int onoff)
{
struct m920x_state *m = adap->dev->priv;
m->filters[adap->id][index] = onoff ? pid : 0;
return m920x_update_filters(adap);
}
static int m920x_firmware_download(struct usb_device *udev, const struct firmware *fw)
{
u16 value, index, size;
u8 *read, *buff;
int i, pass, ret = 0;
buff = kmalloc(65536, GFP_KERNEL);
if (buff == NULL)
return -ENOMEM;
read = kmalloc(4, GFP_KERNEL);
if (!read) {
kfree(buff);
return -ENOMEM;
}
if ((ret = m920x_read(udev, M9206_FILTER, 0x0, 0x8000, read, 4)) != 0)
goto done;
deb("%x %x %x %x\n", read[0], read[1], read[2], read[3]);
if ((ret = m920x_read(udev, M9206_FW, 0x0, 0x0, read, 1)) != 0)
goto done;
deb("%x\n", read[0]);
for (pass = 0; pass < 2; pass++) {
for (i = 0; i + (sizeof(u16) * 3) < fw->size;) {
value = get_unaligned_le16(fw->data + i);
i += sizeof(u16);
index = get_unaligned_le16(fw->data + i);
i += sizeof(u16);
size = get_unaligned_le16(fw->data + i);
i += sizeof(u16);
if (pass == 1) {
memcpy(buff, fw->data + i, size);
ret = usb_control_msg(udev, usb_sndctrlpipe(udev,0),
M9206_FW,
USB_TYPE_VENDOR | USB_DIR_OUT,
value, index, buff, size, 20);
if (ret != size) {
deb("error while uploading fw!\n");
ret = -EIO;
goto done;
}
msleep(3);
}
i += size;
}
if (i != fw->size) {
deb("bad firmware file!\n");
ret = -EINVAL;
goto done;
}
}
msleep(36);
(void) m920x_write(udev, M9206_CORE, 0x01, M9206_FW_GO);
deb("firmware uploaded!\n");
done:
kfree(read);
kfree(buff);
return ret;
}
static int m920x_identify_state(struct usb_device *udev,
struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc,
int *cold)
{
struct usb_host_interface *alt;
alt = usb_altnum_to_altsetting(usb_ifnum_to_if(udev, 0), 1);
*cold = (alt == NULL) ? 1 : 0;
return 0;
}
static int m920x_mt352_demod_init(struct dvb_frontend *fe)
{
int ret;
u8 config[] = { CONFIG, 0x3d };
u8 clock[] = { CLOCK_CTL, 0x30 };
u8 reset[] = { RESET, 0x80 };
u8 adc_ctl[] = { ADC_CTL_1, 0x40 };
u8 agc[] = { AGC_TARGET, 0x1c, 0x20 };
u8 sec_agc[] = { 0x69, 0x00, 0xff, 0xff, 0x40, 0xff, 0x00, 0x40, 0x40 };
u8 unk1[] = { 0x93, 0x1a };
u8 unk2[] = { 0xb5, 0x7a };
deb("Demod init!\n");
if ((ret = mt352_write(fe, config, ARRAY_SIZE(config))) != 0)
return ret;
if ((ret = mt352_write(fe, clock, ARRAY_SIZE(clock))) != 0)
return ret;
if ((ret = mt352_write(fe, reset, ARRAY_SIZE(reset))) != 0)
return ret;
if ((ret = mt352_write(fe, adc_ctl, ARRAY_SIZE(adc_ctl))) != 0)
return ret;
if ((ret = mt352_write(fe, agc, ARRAY_SIZE(agc))) != 0)
return ret;
if ((ret = mt352_write(fe, sec_agc, ARRAY_SIZE(sec_agc))) != 0)
return ret;
if ((ret = mt352_write(fe, unk1, ARRAY_SIZE(unk1))) != 0)
return ret;
if ((ret = mt352_write(fe, unk2, ARRAY_SIZE(unk2))) != 0)
return ret;
return 0;
}
static int m920x_mt352_frontend_attach(struct dvb_usb_adapter *adap)
{
deb("%s\n",__func__);
if ((adap->fe = dvb_attach(mt352_attach,
&m920x_mt352_config,
&adap->dev->i2c_adap)) == NULL)
return -EIO;
return 0;
}
static int m920x_tda10046_08_frontend_attach(struct dvb_usb_adapter *adap)
{
deb("%s\n",__func__);
if ((adap->fe = dvb_attach(tda10046_attach,
&m920x_tda10046_08_config,
&adap->dev->i2c_adap)) == NULL)
return -EIO;
return 0;
}
static int m920x_tda10046_0b_frontend_attach(struct dvb_usb_adapter *adap)
{
deb("%s\n",__func__);
if ((adap->fe = dvb_attach(tda10046_attach,
&m920x_tda10046_0b_config,
&adap->dev->i2c_adap)) == NULL)
return -EIO;
return 0;
}
static int m920x_qt1010_tuner_attach(struct dvb_usb_adapter *adap)
{
deb("%s\n",__func__);
if (dvb_attach(qt1010_attach, adap->fe, &adap->dev->i2c_adap, &m920x_qt1010_config) == NULL)
return -ENODEV;
return 0;
}
static int m920x_tda8275_60_tuner_attach(struct dvb_usb_adapter *adap)
{
deb("%s\n",__func__);
if (dvb_attach(tda827x_attach, adap->fe, 0x60, &adap->dev->i2c_adap, NULL) == NULL)
return -ENODEV;
return 0;
}
static int m920x_tda8275_61_tuner_attach(struct dvb_usb_adapter *adap)
{
deb("%s\n",__func__);
if (dvb_attach(tda827x_attach, adap->fe, 0x61, &adap->dev->i2c_adap, NULL) == NULL)
return -ENODEV;
return 0;
}
static int m920x_fmd1216me_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(simple_tuner_attach, adap->fe,
&adap->dev->i2c_adap, 0x61,
TUNER_PHILIPS_FMD1216ME_MK3);
return 0;
}
static int m920x_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct dvb_usb_device *d = NULL;
int ret;
struct m920x_inits *rc_init_seq = NULL;
int bInterfaceNumber = intf->cur_altsetting->desc.bInterfaceNumber;
deb("Probing for m920x device at interface %d\n", bInterfaceNumber);
if (bInterfaceNumber == 0) {
ret = dvb_usb_device_init(intf, &megasky_properties,
THIS_MODULE, &d, adapter_nr);
if (ret == 0) {
rc_init_seq = megasky_rc_init;
goto found;
}
ret = dvb_usb_device_init(intf, &digivox_mini_ii_properties,
THIS_MODULE, &d, adapter_nr);
if (ret == 0) {
goto found;
}
ret = dvb_usb_device_init(intf, &tvwalkertwin_properties,
THIS_MODULE, &d, adapter_nr);
if (ret == 0) {
rc_init_seq = tvwalkertwin_rc_init;
goto found;
}
ret = dvb_usb_device_init(intf, &dposh_properties,
THIS_MODULE, &d, adapter_nr);
if (ret == 0) {
goto found;
}
ret = dvb_usb_device_init(intf, &pinnacle_pctv310e_properties,
THIS_MODULE, &d, adapter_nr);
if (ret == 0) {
rc_init_seq = pinnacle310e_init;
goto found;
}
return ret;
} else {
}
found:
if ((ret = m920x_init_ep(intf)) < 0)
return ret;
if (d && (ret = m920x_init(d, rc_init_seq)) != 0)
return ret;
return ret;
}
static int __init m920x_module_init(void)
{
int ret;
if ((ret = usb_register(&m920x_driver))) {
err("usb_register failed. Error number %d", ret);
return ret;
}
return 0;
}
static void __exit m920x_module_exit(void)
{
usb_deregister(&m920x_driver);
}
