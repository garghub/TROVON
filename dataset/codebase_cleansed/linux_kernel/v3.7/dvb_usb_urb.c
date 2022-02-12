int dvb_usbv2_generic_rw(struct dvb_usb_device *d, u8 *wbuf, u16 wlen, u8 *rbuf,
u16 rlen)
{
int ret, actual_length;
if (!d || !wbuf || !wlen || !d->props->generic_bulk_ctrl_endpoint ||
!d->props->generic_bulk_ctrl_endpoint_response) {
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, -EINVAL);
return -EINVAL;
}
mutex_lock(&d->usb_mutex);
dev_dbg(&d->udev->dev, "%s: >>> %*ph\n", __func__, wlen, wbuf);
ret = usb_bulk_msg(d->udev, usb_sndbulkpipe(d->udev,
d->props->generic_bulk_ctrl_endpoint), wbuf, wlen,
&actual_length, 2000);
if (ret < 0)
dev_err(&d->udev->dev, "%s: usb_bulk_msg() failed=%d\n",
KBUILD_MODNAME, ret);
else
ret = actual_length != wlen ? -EIO : 0;
if (!ret && rbuf && rlen) {
if (d->props->generic_bulk_ctrl_delay)
usleep_range(d->props->generic_bulk_ctrl_delay,
d->props->generic_bulk_ctrl_delay
+ 20000);
ret = usb_bulk_msg(d->udev, usb_rcvbulkpipe(d->udev,
d->props->generic_bulk_ctrl_endpoint_response),
rbuf, rlen, &actual_length, 2000);
if (ret)
dev_err(&d->udev->dev, "%s: 2nd usb_bulk_msg() " \
"failed=%d\n", KBUILD_MODNAME, ret);
dev_dbg(&d->udev->dev, "%s: <<< %*ph\n", __func__,
actual_length, rbuf);
}
mutex_unlock(&d->usb_mutex);
return ret;
}
int dvb_usbv2_generic_write(struct dvb_usb_device *d, u8 *buf, u16 len)
{
return dvb_usbv2_generic_rw(d, buf, len, NULL, 0);
}
