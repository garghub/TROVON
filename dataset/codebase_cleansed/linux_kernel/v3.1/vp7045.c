int vp7045_usb_op(struct dvb_usb_device *d, u8 cmd, u8 *out, int outlen, u8 *in, int inlen, int msec)
{
int ret = 0;
u8 *buf = d->priv;
buf[0] = cmd;
if (outlen > 19)
outlen = 19;
if (inlen > 11)
inlen = 11;
ret = mutex_lock_interruptible(&d->usb_mutex);
if (ret)
return ret;
if (out != NULL && outlen > 0)
memcpy(&buf[1], out, outlen);
deb_xfer("out buffer: ");
debug_dump(buf, outlen+1, deb_xfer);
if (usb_control_msg(d->udev,
usb_sndctrlpipe(d->udev,0),
TH_COMMAND_OUT, USB_TYPE_VENDOR | USB_DIR_OUT, 0, 0,
buf, 20, 2000) != 20) {
err("USB control message 'out' went wrong.");
ret = -EIO;
goto unlock;
}
msleep(msec);
if (usb_control_msg(d->udev,
usb_rcvctrlpipe(d->udev,0),
TH_COMMAND_IN, USB_TYPE_VENDOR | USB_DIR_IN, 0, 0,
buf, 12, 2000) != 12) {
err("USB control message 'in' went wrong.");
ret = -EIO;
goto unlock;
}
deb_xfer("in buffer: ");
debug_dump(buf, 12, deb_xfer);
if (in != NULL && inlen > 0)
memcpy(in, &buf[1], inlen);
unlock:
mutex_unlock(&d->usb_mutex);
return ret;
}
u8 vp7045_read_reg(struct dvb_usb_device *d, u8 reg)
{
u8 obuf[2] = { 0 },v;
obuf[1] = reg;
vp7045_usb_op(d,TUNER_REG_READ,obuf,2,&v,1,30);
return v;
}
static int vp7045_power_ctrl(struct dvb_usb_device *d, int onoff)
{
u8 v = onoff;
return vp7045_usb_op(d,SET_TUNER_POWER,&v,1,NULL,0,150);
}
static int vp7045_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
u8 key;
int i;
vp7045_usb_op(d,RC_VAL_READ,NULL,0,&key,1,20);
deb_rc("remote query key: %x %d\n",key,key);
if (key == 0x44) {
*state = REMOTE_NO_KEY_PRESSED;
return 0;
}
for (i = 0; i < ARRAY_SIZE(rc_map_vp7045_table); i++)
if (rc5_data(&rc_map_vp7045_table[i]) == key) {
*state = REMOTE_KEY_PRESSED;
*event = rc_map_vp7045_table[i].keycode;
break;
}
return 0;
}
static int vp7045_read_eeprom(struct dvb_usb_device *d,u8 *buf, int len, int offset)
{
int i = 0;
u8 v,br[2];
for (i=0; i < len; i++) {
v = offset + i;
vp7045_usb_op(d,GET_EE_VALUE,&v,1,br,2,5);
buf[i] = br[1];
}
deb_info("VP7045 EEPROM read (offs: %d, len: %d) : ",offset, i);
debug_dump(buf,i,deb_info);
return 0;
}
static int vp7045_read_mac_addr(struct dvb_usb_device *d,u8 mac[6])
{
return vp7045_read_eeprom(d,mac, 6, MAC_0_ADDR);
}
static int vp7045_frontend_attach(struct dvb_usb_adapter *adap)
{
u8 buf[255] = { 0 };
vp7045_usb_op(adap->dev,VENDOR_STRING_READ,NULL,0,buf,20,0);
buf[10] = '\0';
deb_info("firmware says: %s ",buf);
vp7045_usb_op(adap->dev,PRODUCT_STRING_READ,NULL,0,buf,20,0);
buf[10] = '\0';
deb_info("%s ",buf);
vp7045_usb_op(adap->dev,FW_VERSION_READ,NULL,0,buf,20,0);
buf[10] = '\0';
deb_info("v%s\n",buf);
adap->fe = vp7045_fe_attach(adap->dev);
return 0;
}
static int vp7045_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return dvb_usb_device_init(intf, &vp7045_properties,
THIS_MODULE, NULL, adapter_nr);
}
static int __init vp7045_usb_module_init(void)
{
int result;
if ((result = usb_register(&vp7045_usb_driver))) {
err("usb_register failed. (%d)",result);
return result;
}
return 0;
}
static void __exit vp7045_usb_module_exit(void)
{
usb_deregister(&vp7045_usb_driver);
}
