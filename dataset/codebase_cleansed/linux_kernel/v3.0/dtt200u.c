static int dtt200u_power_ctrl(struct dvb_usb_device *d, int onoff)
{
u8 b = SET_INIT;
if (onoff)
dvb_usb_generic_write(d,&b,2);
return 0;
}
static int dtt200u_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
u8 b_streaming[2] = { SET_STREAMING, onoff };
u8 b_rst_pid = RESET_PID_FILTER;
dvb_usb_generic_write(adap->dev, b_streaming, 2);
if (onoff == 0)
dvb_usb_generic_write(adap->dev, &b_rst_pid, 1);
return 0;
}
static int dtt200u_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid, int onoff)
{
u8 b_pid[4];
pid = onoff ? pid : 0;
b_pid[0] = SET_PID_FILTER;
b_pid[1] = index;
b_pid[2] = pid & 0xff;
b_pid[3] = (pid >> 8) & 0x1f;
return dvb_usb_generic_write(adap->dev, b_pid, 4);
}
static int dtt200u_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
u8 key[5],cmd = GET_RC_CODE;
dvb_usb_generic_rw(d,&cmd,1,key,5,0);
dvb_usb_nec_rc_key_to_event(d,key,event,state);
if (key[0] != 0)
deb_info("key: %x %x %x %x %x\n",key[0],key[1],key[2],key[3],key[4]);
return 0;
}
static int dtt200u_frontend_attach(struct dvb_usb_adapter *adap)
{
adap->fe = dtt200u_fe_attach(adap->dev);
return 0;
}
static int dtt200u_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
if (0 == dvb_usb_device_init(intf, &dtt200u_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &wt220u_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &wt220u_fc_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &wt220u_zl0353_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &wt220u_miglia_properties,
THIS_MODULE, NULL, adapter_nr))
return 0;
return -ENODEV;
}
static int __init dtt200u_usb_module_init(void)
{
int result;
if ((result = usb_register(&dtt200u_usb_driver))) {
err("usb_register failed. (%d)",result);
return result;
}
return 0;
}
static void __exit dtt200u_usb_module_exit(void)
{
usb_deregister(&dtt200u_usb_driver);
}
