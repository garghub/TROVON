static
int i2400mu_notification_grok(struct i2400mu *i2400mu, const void *buf,
size_t buf_len)
{
int ret;
struct device *dev = &i2400mu->usb_iface->dev;
struct i2400m *i2400m = &i2400mu->i2400m;
d_fnstart(4, dev, "(i2400m %p buf %p buf_len %zu)\n",
i2400mu, buf, buf_len);
ret = -EIO;
if (buf_len < sizeof(i2400m_ZERO_BARKER))
goto error_bad_size;
ret = 0;
if (!memcmp(i2400m_ZERO_BARKER, buf, sizeof(i2400m_ZERO_BARKER))) {
i2400mu_rx_kick(i2400mu);
goto out;
}
ret = i2400m_is_boot_barker(i2400m, buf, buf_len);
if (unlikely(ret >= 0))
ret = i2400m_dev_reset_handle(i2400m, "device rebooted");
else
i2400m_unknown_barker(i2400m, buf, buf_len);
error_bad_size:
out:
d_fnend(4, dev, "(i2400m %p buf %p buf_len %zu) = %d\n",
i2400mu, buf, buf_len, ret);
return ret;
}
static
void i2400mu_notification_cb(struct urb *urb)
{
int ret;
struct i2400mu *i2400mu = urb->context;
struct device *dev = &i2400mu->usb_iface->dev;
d_fnstart(4, dev, "(urb %p status %d actual_length %d)\n",
urb, urb->status, urb->actual_length);
ret = urb->status;
switch (ret) {
case 0:
ret = i2400mu_notification_grok(i2400mu, urb->transfer_buffer,
urb->actual_length);
if (ret == -EIO && edc_inc(&i2400mu->urb_edc, EDC_MAX_ERRORS,
EDC_ERROR_TIMEFRAME))
goto error_exceeded;
if (ret == -ENOMEM)
goto error_exceeded;
break;
case -EINVAL:
case -ENODEV:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNRESET:
goto out;
default:
if (edc_inc(&i2400mu->urb_edc,
EDC_MAX_ERRORS, EDC_ERROR_TIMEFRAME))
goto error_exceeded;
dev_err(dev, "notification: URB error %d, retrying\n",
urb->status);
}
usb_mark_last_busy(i2400mu->usb_dev);
ret = usb_submit_urb(i2400mu->notif_urb, GFP_ATOMIC);
switch (ret) {
case 0:
case -EINVAL:
case -ENODEV:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNRESET:
break;
default:
dev_err(dev, "notification: cannot submit URB: %d\n", ret);
goto error_submit;
}
d_fnend(4, dev, "(urb %p status %d actual_length %d) = void\n",
urb, urb->status, urb->actual_length);
return;
error_exceeded:
dev_err(dev, "maximum errors in notification URB exceeded; "
"resetting device\n");
error_submit:
usb_queue_reset_device(i2400mu->usb_iface);
out:
d_fnend(4, dev, "(urb %p status %d actual_length %d) = void\n",
urb, urb->status, urb->actual_length);
}
int i2400mu_notification_setup(struct i2400mu *i2400mu)
{
struct device *dev = &i2400mu->usb_iface->dev;
int usb_pipe, ret = 0;
struct usb_endpoint_descriptor *epd;
char *buf;
d_fnstart(4, dev, "(i2400m %p)\n", i2400mu);
buf = kmalloc(I2400MU_MAX_NOTIFICATION_LEN, GFP_KERNEL | GFP_DMA);
if (buf == NULL) {
ret = -ENOMEM;
goto error_buf_alloc;
}
i2400mu->notif_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!i2400mu->notif_urb) {
ret = -ENOMEM;
goto error_alloc_urb;
}
epd = usb_get_epd(i2400mu->usb_iface,
i2400mu->endpoint_cfg.notification);
usb_pipe = usb_rcvintpipe(i2400mu->usb_dev, epd->bEndpointAddress);
usb_fill_int_urb(i2400mu->notif_urb, i2400mu->usb_dev, usb_pipe,
buf, I2400MU_MAX_NOTIFICATION_LEN,
i2400mu_notification_cb, i2400mu, epd->bInterval);
ret = usb_submit_urb(i2400mu->notif_urb, GFP_KERNEL);
if (ret != 0) {
dev_err(dev, "notification: cannot submit URB: %d\n", ret);
goto error_submit;
}
d_fnend(4, dev, "(i2400m %p) = %d\n", i2400mu, ret);
return ret;
error_submit:
usb_free_urb(i2400mu->notif_urb);
error_alloc_urb:
kfree(buf);
error_buf_alloc:
d_fnend(4, dev, "(i2400m %p) = %d\n", i2400mu, ret);
return ret;
}
void i2400mu_notification_release(struct i2400mu *i2400mu)
{
struct device *dev = &i2400mu->usb_iface->dev;
d_fnstart(4, dev, "(i2400mu %p)\n", i2400mu);
if (i2400mu->notif_urb != NULL) {
usb_kill_urb(i2400mu->notif_urb);
kfree(i2400mu->notif_urb->transfer_buffer);
usb_free_urb(i2400mu->notif_urb);
i2400mu->notif_urb = NULL;
}
d_fnend(4, dev, "(i2400mu %p)\n", i2400mu);
}
