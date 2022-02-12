static int usb_cypress_writemem(struct usb_device *udev, u16 addr, u8 *data,
u8 len)
{
dvb_usb_dbg_usb_control_msg(udev,
0xa0, USB_TYPE_VENDOR, addr, 0x00, data, len);
return usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0xa0, USB_TYPE_VENDOR, addr, 0x00, data, len, 5000);
}
int usbv2_cypress_load_firmware(struct usb_device *udev,
const struct firmware *fw, int type)
{
struct hexline *hx;
int ret, pos = 0;
hx = kmalloc(sizeof(struct hexline), GFP_KERNEL);
if (!hx) {
dev_err(&udev->dev, "%s: kmalloc() failed\n", KBUILD_MODNAME);
return -ENOMEM;
}
hx->data[0] = 1;
ret = usb_cypress_writemem(udev, cypress[type].cs_reg, hx->data, 1);
if (ret != 1) {
dev_err(&udev->dev, "%s: CPU stop failed=%d\n",
KBUILD_MODNAME, ret);
ret = -EIO;
goto err_kfree;
}
for (;;) {
ret = dvb_usbv2_get_hexline(fw, hx, &pos);
if (ret < 0)
goto err_kfree;
else if (ret == 0)
break;
ret = usb_cypress_writemem(udev, hx->addr, hx->data, hx->len);
if (ret < 0) {
goto err_kfree;
} else if (ret != hx->len) {
dev_err(&udev->dev, "%s: error while transferring " \
"firmware (transferred size=%d, " \
"block size=%d)\n",
KBUILD_MODNAME, ret, hx->len);
ret = -EIO;
goto err_kfree;
}
}
hx->data[0] = 0;
ret = usb_cypress_writemem(udev, cypress[type].cs_reg, hx->data, 1);
if (ret != 1) {
dev_err(&udev->dev, "%s: CPU start failed=%d\n",
KBUILD_MODNAME, ret);
ret = -EIO;
goto err_kfree;
}
ret = 0;
err_kfree:
kfree(hx);
return ret;
}
int dvb_usbv2_get_hexline(const struct firmware *fw, struct hexline *hx,
int *pos)
{
u8 *b = (u8 *) &fw->data[*pos];
int data_offs = 4;
if (*pos >= fw->size)
return 0;
memset(hx, 0, sizeof(struct hexline));
hx->len = b[0];
if ((*pos + hx->len + 4) >= fw->size)
return -EINVAL;
hx->addr = b[1] | (b[2] << 8);
hx->type = b[3];
if (hx->type == 0x04) {
hx->addr |= (b[4] << 24) | (b[5] << 16);
}
memcpy(hx->data, &b[data_offs], hx->len);
hx->chk = b[hx->len + data_offs];
*pos += hx->len + 5;
return *pos;
}
