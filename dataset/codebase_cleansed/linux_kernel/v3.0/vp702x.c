static int vp702x_usb_in_op_unlocked(struct dvb_usb_device *d, u8 req,
u16 value, u16 index, u8 *b, int blen)
{
int ret;
ret = usb_control_msg(d->udev,
usb_rcvctrlpipe(d->udev, 0),
req,
USB_TYPE_VENDOR | USB_DIR_IN,
value, index, b, blen,
2000);
if (ret < 0) {
warn("usb in operation failed. (%d)", ret);
ret = -EIO;
} else
ret = 0;
deb_xfer("in: req. %02x, val: %04x, ind: %04x, buffer: ",req,value,index);
debug_dump(b,blen,deb_xfer);
return ret;
}
int vp702x_usb_in_op(struct dvb_usb_device *d, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
int ret;
mutex_lock(&d->usb_mutex);
ret = vp702x_usb_in_op_unlocked(d, req, value, index, b, blen);
mutex_unlock(&d->usb_mutex);
return ret;
}
int vp702x_usb_out_op_unlocked(struct dvb_usb_device *d, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
int ret;
deb_xfer("out: req. %02x, val: %04x, ind: %04x, buffer: ",req,value,index);
debug_dump(b,blen,deb_xfer);
if ((ret = usb_control_msg(d->udev,
usb_sndctrlpipe(d->udev,0),
req,
USB_TYPE_VENDOR | USB_DIR_OUT,
value,index,b,blen,
2000)) != blen) {
warn("usb out operation failed. (%d)",ret);
return -EIO;
} else
return 0;
}
int vp702x_usb_out_op(struct dvb_usb_device *d, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
int ret;
mutex_lock(&d->usb_mutex);
ret = vp702x_usb_out_op_unlocked(d, req, value, index, b, blen);
mutex_unlock(&d->usb_mutex);
return ret;
}
int vp702x_usb_inout_op(struct dvb_usb_device *d, u8 *o, int olen, u8 *i, int ilen, int msec)
{
int ret;
if ((ret = mutex_lock_interruptible(&d->usb_mutex)))
return ret;
ret = vp702x_usb_out_op_unlocked(d, REQUEST_OUT, 0, 0, o, olen);
msleep(msec);
ret = vp702x_usb_in_op_unlocked(d, REQUEST_IN, 0, 0, i, ilen);
mutex_unlock(&d->usb_mutex);
return ret;
}
static int vp702x_usb_inout_cmd(struct dvb_usb_device *d, u8 cmd, u8 *o,
int olen, u8 *i, int ilen, int msec)
{
struct vp702x_device_state *st = d->priv;
int ret = 0;
u8 *buf;
int buflen = max(olen + 2, ilen + 1);
ret = mutex_lock_interruptible(&st->buf_mutex);
if (ret < 0)
return ret;
if (buflen > st->buf_len) {
buf = kmalloc(buflen, GFP_KERNEL);
if (!buf) {
mutex_unlock(&st->buf_mutex);
return -ENOMEM;
}
info("successfully reallocated a bigger buffer");
kfree(st->buf);
st->buf = buf;
st->buf_len = buflen;
} else {
buf = st->buf;
}
buf[0] = 0x00;
buf[1] = cmd;
memcpy(&buf[2], o, olen);
ret = vp702x_usb_inout_op(d, buf, olen+2, buf, ilen+1, msec);
if (ret == 0)
memcpy(i, &buf[1], ilen);
mutex_unlock(&st->buf_mutex);
return ret;
}
static int vp702x_set_pld_mode(struct dvb_usb_adapter *adap, u8 bypass)
{
int ret;
struct vp702x_device_state *st = adap->dev->priv;
u8 *buf;
mutex_lock(&st->buf_mutex);
buf = st->buf;
memset(buf, 0, 16);
ret = vp702x_usb_in_op(adap->dev, 0xe0, (bypass << 8) | 0x0e,
0, buf, 16);
mutex_unlock(&st->buf_mutex);
return ret;
}
static int vp702x_set_pld_state(struct dvb_usb_adapter *adap, u8 state)
{
int ret;
struct vp702x_device_state *st = adap->dev->priv;
u8 *buf;
mutex_lock(&st->buf_mutex);
buf = st->buf;
memset(buf, 0, 16);
ret = vp702x_usb_in_op(adap->dev, 0xe0, (state << 8) | 0x0f,
0, buf, 16);
mutex_unlock(&st->buf_mutex);
return ret;
}
static int vp702x_set_pid(struct dvb_usb_adapter *adap, u16 pid, u8 id, int onoff)
{
struct vp702x_adapter_state *st = adap->priv;
struct vp702x_device_state *dst = adap->dev->priv;
u8 *buf;
if (onoff)
st->pid_filter_state |= (1 << id);
else {
st->pid_filter_state &= ~(1 << id);
pid = 0xffff;
}
id = 0x10 + id*2;
vp702x_set_pld_state(adap, st->pid_filter_state);
mutex_lock(&dst->buf_mutex);
buf = dst->buf;
memset(buf, 0, 16);
vp702x_usb_in_op(adap->dev, 0xe0, (((pid >> 8) & 0xff) << 8) | (id), 0, buf, 16);
vp702x_usb_in_op(adap->dev, 0xe0, (((pid ) & 0xff) << 8) | (id+1), 0, buf, 16);
mutex_unlock(&dst->buf_mutex);
return 0;
}
static int vp702x_init_pid_filter(struct dvb_usb_adapter *adap)
{
struct vp702x_adapter_state *st = adap->priv;
struct vp702x_device_state *dst = adap->dev->priv;
int i;
u8 *b;
st->pid_filter_count = 8;
st->pid_filter_can_bypass = 1;
st->pid_filter_state = 0x00;
vp702x_set_pld_mode(adap, 1);
for (i = 0; i < st->pid_filter_count; i++)
vp702x_set_pid(adap, 0xffff, i, 1);
mutex_lock(&dst->buf_mutex);
b = dst->buf;
memset(b, 0, 10);
vp702x_usb_in_op(adap->dev, 0xb5, 3, 0, b, 10);
vp702x_usb_in_op(adap->dev, 0xb5, 0, 0, b, 10);
vp702x_usb_in_op(adap->dev, 0xb5, 1, 0, b, 10);
mutex_unlock(&dst->buf_mutex);
return 0;
}
static int vp702x_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
return 0;
}
static int vp702x_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
u8 *key;
int i;
return 0;
key = kmalloc(10, GFP_KERNEL);
if (!key)
return -ENOMEM;
vp702x_usb_in_op(d,READ_REMOTE_REQ,0,0,key,10);
deb_rc("remote query key: %x %d\n",key[1],key[1]);
if (key[1] == 0x44) {
*state = REMOTE_NO_KEY_PRESSED;
kfree(key);
return 0;
}
for (i = 0; i < ARRAY_SIZE(rc_map_vp702x_table); i++)
if (rc5_custom(&rc_map_vp702x_table[i]) == key[1]) {
*state = REMOTE_KEY_PRESSED;
*event = rc_map_vp702x_table[i].keycode;
break;
}
kfree(key);
return 0;
}
static int vp702x_read_mac_addr(struct dvb_usb_device *d,u8 mac[6])
{
u8 i, *buf;
struct vp702x_device_state *st = d->priv;
mutex_lock(&st->buf_mutex);
buf = st->buf;
for (i = 6; i < 12; i++)
vp702x_usb_in_op(d, READ_EEPROM_REQ, i, 1, &buf[i - 6], 1);
memcpy(mac, buf, 6);
mutex_unlock(&st->buf_mutex);
return 0;
}
static int vp702x_frontend_attach(struct dvb_usb_adapter *adap)
{
u8 buf[10] = { 0 };
vp702x_usb_out_op(adap->dev, SET_TUNER_POWER_REQ, 0, 7, NULL, 0);
if (vp702x_usb_inout_cmd(adap->dev, GET_SYSTEM_STRING, NULL, 0,
buf, 10, 10))
return -EIO;
buf[9] = '\0';
info("system string: %s",&buf[1]);
vp702x_init_pid_filter(adap);
adap->fe = vp702x_fe_attach(adap->dev);
vp702x_usb_out_op(adap->dev, SET_TUNER_POWER_REQ, 1, 7, NULL, 0);
return 0;
}
static int vp702x_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct dvb_usb_device *d;
struct vp702x_device_state *st;
int ret;
ret = dvb_usb_device_init(intf, &vp702x_properties,
THIS_MODULE, &d, adapter_nr);
if (ret)
goto out;
st = d->priv;
st->buf_len = 16;
st->buf = kmalloc(st->buf_len, GFP_KERNEL);
if (!st->buf) {
ret = -ENOMEM;
dvb_usb_device_exit(intf);
goto out;
}
mutex_init(&st->buf_mutex);
out:
return ret;
}
static void vp702x_usb_disconnect(struct usb_interface *intf)
{
struct dvb_usb_device *d = usb_get_intfdata(intf);
struct vp702x_device_state *st = d->priv;
mutex_lock(&st->buf_mutex);
kfree(st->buf);
mutex_unlock(&st->buf_mutex);
dvb_usb_device_exit(intf);
}
static int __init vp702x_usb_module_init(void)
{
int result;
if ((result = usb_register(&vp702x_usb_driver))) {
err("usb_register failed. (%d)",result);
return result;
}
return 0;
}
static void __exit vp702x_usb_module_exit(void)
{
usb_deregister(&vp702x_usb_driver);
}
