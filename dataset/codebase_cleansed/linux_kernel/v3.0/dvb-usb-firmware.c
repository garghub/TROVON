static int usb_cypress_writemem(struct usb_device *udev,u16 addr,u8 *data, u8 len)
{
return usb_control_msg(udev, usb_sndctrlpipe(udev,0),
0xa0, USB_TYPE_VENDOR, addr, 0x00, data, len, 5000);
}
int usb_cypress_load_firmware(struct usb_device *udev, const struct firmware *fw, int type)
{
struct hexline hx;
u8 reset;
int ret,pos=0;
reset = 1;
if ((ret = usb_cypress_writemem(udev,cypress[type].cpu_cs_register,&reset,1)) != 1)
err("could not stop the USB controller CPU.");
while ((ret = dvb_usb_get_hexline(fw,&hx,&pos)) > 0) {
deb_fw("writing to address 0x%04x (buffer: 0x%02x %02x)\n",hx.addr,hx.len,hx.chk);
ret = usb_cypress_writemem(udev,hx.addr,hx.data,hx.len);
if (ret != hx.len) {
err("error while transferring firmware "
"(transferred size: %d, block size: %d)",
ret,hx.len);
ret = -EINVAL;
break;
}
}
if (ret < 0) {
err("firmware download failed at %d with %d",pos,ret);
return ret;
}
if (ret == 0) {
reset = 0;
if (ret || usb_cypress_writemem(udev,cypress[type].cpu_cs_register,&reset,1) != 1) {
err("could not restart the USB controller CPU.");
ret = -EINVAL;
}
} else
ret = -EIO;
return ret;
}
int dvb_usb_download_firmware(struct usb_device *udev, struct dvb_usb_device_properties *props)
{
int ret;
const struct firmware *fw = NULL;
if ((ret = request_firmware(&fw, props->firmware, &udev->dev)) != 0) {
err("did not find the firmware file. (%s) "
"Please see linux/Documentation/dvb/ for more details on firmware-problems. (%d)",
props->firmware,ret);
return ret;
}
info("downloading firmware from file '%s'",props->firmware);
switch (props->usb_ctrl) {
case CYPRESS_AN2135:
case CYPRESS_AN2235:
case CYPRESS_FX2:
ret = usb_cypress_load_firmware(udev, fw, props->usb_ctrl);
break;
case DEVICE_SPECIFIC:
if (props->download_firmware)
ret = props->download_firmware(udev,fw);
else {
err("BUG: driver didn't specified a download_firmware-callback, although it claims to have a DEVICE_SPECIFIC one.");
ret = -EINVAL;
}
break;
default:
ret = -EINVAL;
break;
}
release_firmware(fw);
return ret;
}
int dvb_usb_get_hexline(const struct firmware *fw, struct hexline *hx,
int *pos)
{
u8 *b = (u8 *) &fw->data[*pos];
int data_offs = 4;
if (*pos >= fw->size)
return 0;
memset(hx,0,sizeof(struct hexline));
hx->len = b[0];
if ((*pos + hx->len + 4) >= fw->size)
return -EINVAL;
hx->addr = b[1] | (b[2] << 8);
hx->type = b[3];
if (hx->type == 0x04) {
hx->addr |= (b[4] << 24) | (b[5] << 16);
}
memcpy(hx->data,&b[data_offs],hx->len);
hx->chk = b[hx->len + data_offs];
*pos += hx->len + 5;
return *pos;
}
