static int vprbrd_iio_read_raw(struct iio_dev *iio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long info)
{
int ret, error = 0;
struct vprbrd_adc *adc = iio_priv(iio_dev);
struct vprbrd *vb = adc->vb;
struct vprbrd_adc_msg *admsg = (struct vprbrd_adc_msg *)vb->buf;
switch (info) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&vb->lock);
admsg->cmd = VPRBRD_ADC_CMD_GET;
admsg->chan = chan->scan_index;
admsg->val = 0x00;
ret = usb_control_msg(vb->usb_dev,
usb_sndctrlpipe(vb->usb_dev, 0), VPRBRD_USB_REQUEST_ADC,
VPRBRD_USB_TYPE_OUT, 0x0000, 0x0000, admsg,
sizeof(struct vprbrd_adc_msg), VPRBRD_USB_TIMEOUT_MS);
if (ret != sizeof(struct vprbrd_adc_msg)) {
dev_err(&iio_dev->dev, "usb send error on adc read\n");
error = -EREMOTEIO;
}
ret = usb_control_msg(vb->usb_dev,
usb_rcvctrlpipe(vb->usb_dev, 0), VPRBRD_USB_REQUEST_ADC,
VPRBRD_USB_TYPE_IN, 0x0000, 0x0000, admsg,
sizeof(struct vprbrd_adc_msg), VPRBRD_USB_TIMEOUT_MS);
*val = admsg->val;
mutex_unlock(&vb->lock);
if (ret != sizeof(struct vprbrd_adc_msg)) {
dev_err(&iio_dev->dev, "usb recv error on adc read\n");
error = -EREMOTEIO;
}
if (error)
goto error;
return IIO_VAL_INT;
default:
error = -EINVAL;
break;
}
error:
return error;
}
static int vprbrd_adc_probe(struct platform_device *pdev)
{
struct vprbrd *vb = dev_get_drvdata(pdev->dev.parent);
struct vprbrd_adc *adc;
struct iio_dev *indio_dev;
int ret;
indio_dev = iio_device_alloc(sizeof(*adc));
if (!indio_dev) {
dev_err(&pdev->dev, "failed allocating iio device\n");
return -ENOMEM;
}
adc = iio_priv(indio_dev);
adc->vb = vb;
indio_dev->name = "viperboard adc";
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &vprbrd_adc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = vprbrd_adc_iio_channels;
indio_dev->num_channels = ARRAY_SIZE(vprbrd_adc_iio_channels);
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "could not register iio (adc)");
goto error;
}
platform_set_drvdata(pdev, indio_dev);
return 0;
error:
iio_device_free(indio_dev);
return ret;
}
static int vprbrd_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
iio_device_unregister(indio_dev);
iio_device_free(indio_dev);
return 0;
}
