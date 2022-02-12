int ezusb_writememory(struct usb_serial *serial, int address,
unsigned char *data, int length, __u8 request)
{
int result;
unsigned char *transfer_buffer;
if (!serial->dev) {
printk(KERN_ERR "ezusb: %s - no physical device present, "
"failing.\n", __func__);
return -ENODEV;
}
transfer_buffer = kmemdup(data, length, GFP_KERNEL);
if (!transfer_buffer) {
dev_err(&serial->dev->dev, "%s - kmalloc(%d) failed.\n",
__func__, length);
return -ENOMEM;
}
result = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
request, 0x40, address, 0, transfer_buffer, length, 3000);
kfree(transfer_buffer);
return result;
}
int ezusb_set_reset(struct usb_serial *serial, unsigned char reset_bit)
{
int response;
response = ezusb_writememory(serial, CPUCS_REG, &reset_bit, 1, 0xa0);
if (response < 0)
dev_err(&serial->dev->dev, "%s- %d failed\n",
__func__, reset_bit);
return response;
}
