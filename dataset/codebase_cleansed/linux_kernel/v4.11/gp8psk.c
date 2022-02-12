static int gp8psk_usb_in_op(struct dvb_usb_device *d, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
struct gp8psk_state *st = d->priv;
int ret = 0,try = 0;
if (blen > sizeof(st->data))
return -EIO;
if ((ret = mutex_lock_interruptible(&d->usb_mutex)))
return ret;
while (ret >= 0 && ret != blen && try < 3) {
ret = usb_control_msg(d->udev,
usb_rcvctrlpipe(d->udev,0),
req,
USB_TYPE_VENDOR | USB_DIR_IN,
value, index, st->data, blen,
2000);
deb_info("reading number %d (ret: %d)\n",try,ret);
try++;
}
if (ret < 0 || ret != blen) {
warn("usb in %d operation failed.", req);
ret = -EIO;
} else {
ret = 0;
memcpy(b, st->data, blen);
}
deb_xfer("in: req. %x, val: %x, ind: %x, buffer: ",req,value,index);
debug_dump(b,blen,deb_xfer);
mutex_unlock(&d->usb_mutex);
return ret;
}
static int gp8psk_usb_out_op(struct dvb_usb_device *d, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
struct gp8psk_state *st = d->priv;
int ret;
deb_xfer("out: req. %x, val: %x, ind: %x, buffer: ",req,value,index);
debug_dump(b,blen,deb_xfer);
if (blen > sizeof(st->data))
return -EIO;
if ((ret = mutex_lock_interruptible(&d->usb_mutex)))
return ret;
memcpy(st->data, b, blen);
if (usb_control_msg(d->udev,
usb_sndctrlpipe(d->udev,0),
req,
USB_TYPE_VENDOR | USB_DIR_OUT,
value, index, st->data, blen,
2000) != blen) {
warn("usb out operation failed.");
ret = -EIO;
} else
ret = 0;
mutex_unlock(&d->usb_mutex);
return ret;
}
static int gp8psk_get_fw_version(struct dvb_usb_device *d, u8 *fw_vers)
{
return gp8psk_usb_in_op(d, GET_FW_VERS, 0, 0, fw_vers, 6);
}
static int gp8psk_get_fpga_version(struct dvb_usb_device *d, u8 *fpga_vers)
{
return gp8psk_usb_in_op(d, GET_FPGA_VERS, 0, 0, fpga_vers, 1);
}
static void gp8psk_info(struct dvb_usb_device *d)
{
u8 fpga_vers, fw_vers[6];
if (!gp8psk_get_fw_version(d, fw_vers))
info("FW Version = %i.%02i.%i (0x%x) Build %4i/%02i/%02i",
fw_vers[2], fw_vers[1], fw_vers[0], GP8PSK_FW_VERS(fw_vers),
2000 + fw_vers[5], fw_vers[4], fw_vers[3]);
else
info("failed to get FW version");
if (!gp8psk_get_fpga_version(d, &fpga_vers))
info("FPGA Version = %i", fpga_vers);
else
info("failed to get FPGA version");
}
static int gp8psk_load_bcm4500fw(struct dvb_usb_device *d)
{
int ret;
const struct firmware *fw = NULL;
const u8 *ptr;
u8 *buf;
if ((ret = request_firmware(&fw, bcm4500_firmware,
&d->udev->dev)) != 0) {
err("did not find the bcm4500 firmware file. (%s) Please see linux/Documentation/dvb/ for more details on firmware-problems. (%d)",
bcm4500_firmware,ret);
return ret;
}
ret = -EINVAL;
if (gp8psk_usb_out_op(d, LOAD_BCM4500,1,0,NULL, 0))
goto out_rel_fw;
info("downloading bcm4500 firmware from file '%s'",bcm4500_firmware);
ptr = fw->data;
buf = kmalloc(64, GFP_KERNEL | GFP_DMA);
if (!buf) {
ret = -ENOMEM;
goto out_rel_fw;
}
while (ptr[0] != 0xff) {
u16 buflen = ptr[0] + 4;
if (ptr + buflen >= fw->data + fw->size) {
err("failed to load bcm4500 firmware.");
goto out_free;
}
if (buflen > 64) {
err("firmware chunk size bigger than 64 bytes.");
goto out_free;
}
memcpy(buf, ptr, buflen);
if (dvb_usb_generic_write(d, buf, buflen)) {
err("failed to load bcm4500 firmware.");
goto out_free;
}
ptr += buflen;
}
ret = 0;
out_free:
kfree(buf);
out_rel_fw:
release_firmware(fw);
return ret;
}
static int gp8psk_power_ctrl(struct dvb_usb_device *d, int onoff)
{
u8 status, buf;
int gp_product_id = le16_to_cpu(d->udev->descriptor.idProduct);
if (onoff) {
gp8psk_usb_in_op(d, GET_8PSK_CONFIG,0,0,&status,1);
if (! (status & bm8pskStarted)) {
if(gp_product_id == USB_PID_GENPIX_SKYWALKER_CW3K)
gp8psk_usb_out_op(d, CW3K_INIT, 1, 0, NULL, 0);
if (gp8psk_usb_in_op(d, BOOT_8PSK, 1, 0, &buf, 1))
return -EINVAL;
gp8psk_info(d);
}
if (gp_product_id == USB_PID_GENPIX_8PSK_REV_1_WARM)
if (! (status & bm8pskFW_Loaded))
if(gp8psk_load_bcm4500fw(d))
return -EINVAL;
if (! (status & bmIntersilOn))
if (gp8psk_usb_in_op(d, START_INTERSIL, 1, 0,
&buf, 1))
return -EINVAL;
if (gp_product_id == USB_PID_GENPIX_8PSK_REV_1_WARM)
if (gp8psk_usb_out_op(d, SET_DVB_MODE, 1, 0, NULL, 0))
return -EINVAL;
if (gp8psk_usb_out_op(d, ARM_TRANSFER, 0, 0, NULL, 0))
return -EINVAL;
} else {
if (gp8psk_usb_in_op(d, START_INTERSIL, 0, 0, &buf, 1))
return -EINVAL;
if (gp8psk_usb_in_op(d, BOOT_8PSK, 0, 0, &buf, 1))
return -EINVAL;
if(gp_product_id == USB_PID_GENPIX_SKYWALKER_CW3K)
gp8psk_usb_out_op(d, CW3K_INIT, 0, 0, NULL, 0);
}
return 0;
}
static int gp8psk_bcm4500_reload(struct dvb_usb_device *d)
{
u8 buf;
int gp_product_id = le16_to_cpu(d->udev->descriptor.idProduct);
deb_xfer("reloading firmware\n");
if (gp8psk_usb_in_op(d, BOOT_8PSK, 0, 0, &buf, 1))
return -EINVAL;
if (gp8psk_usb_in_op(d, BOOT_8PSK, 1, 0, &buf, 1))
return -EINVAL;
if (gp_product_id == USB_PID_GENPIX_8PSK_REV_1_WARM)
if (gp8psk_load_bcm4500fw(d))
return -EINVAL;
return 0;
}
static int gp8psk_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
return gp8psk_usb_out_op(adap->dev, ARM_TRANSFER, onoff, 0 , NULL, 0);
}
static int gp8psk_fe_in(void *priv, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
struct dvb_usb_device *d = priv;
return gp8psk_usb_in_op(d, req, value, index, b, blen);
}
static int gp8psk_fe_out(void *priv, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
struct dvb_usb_device *d = priv;
return gp8psk_usb_out_op(d, req, value, index, b, blen);
}
static int gp8psk_fe_reload(void *priv)
{
struct dvb_usb_device *d = priv;
return gp8psk_bcm4500_reload(d);
}
static int gp8psk_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
int id = le16_to_cpu(d->udev->descriptor.idProduct);
int is_rev1;
is_rev1 = (id == USB_PID_GENPIX_8PSK_REV_1_WARM) ? true : false;
adap->fe_adap[0].fe = dvb_attach(gp8psk_fe_attach,
&gp8psk_fe_ops, d, is_rev1);
return 0;
}
static int gp8psk_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int ret;
struct usb_device *udev = interface_to_usbdev(intf);
ret = dvb_usb_device_init(intf, &gp8psk_properties,
THIS_MODULE, NULL, adapter_nr);
if (ret == 0) {
info("found Genpix USB device pID = %x (hex)",
le16_to_cpu(udev->descriptor.idProduct));
}
return ret;
}
