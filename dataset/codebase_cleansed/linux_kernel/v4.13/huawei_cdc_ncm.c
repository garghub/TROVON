static int huawei_cdc_ncm_manage_power(struct usbnet *usbnet_dev, int on)
{
struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
int rv;
if ((on && atomic_add_return(1, &drvstate->pmcount) == 1) ||
(!on && atomic_dec_and_test(&drvstate->pmcount))) {
rv = usb_autopm_get_interface(usbnet_dev->intf);
usbnet_dev->intf->needs_remote_wakeup = on;
if (!rv)
usb_autopm_put_interface(usbnet_dev->intf);
}
return 0;
}
static int huawei_cdc_ncm_wdm_manage_power(struct usb_interface *intf,
int status)
{
struct usbnet *usbnet_dev = usb_get_intfdata(intf);
if (!usbnet_dev)
return 0;
return huawei_cdc_ncm_manage_power(usbnet_dev, status);
}
static int huawei_cdc_ncm_bind(struct usbnet *usbnet_dev,
struct usb_interface *intf)
{
struct cdc_ncm_ctx *ctx;
struct usb_driver *subdriver = ERR_PTR(-ENODEV);
int ret = -ENODEV;
struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
int drvflags = 0;
drvflags |= CDC_NCM_FLAG_NDP_TO_END;
drvflags |= CDC_NCM_FLAG_RESET_NTB16;
ret = cdc_ncm_bind_common(usbnet_dev, intf, 1, drvflags);
if (ret)
goto err;
ctx = drvstate->ctx;
if (usbnet_dev->status)
subdriver = usb_cdc_wdm_register(ctx->control,
&usbnet_dev->status->desc,
1024,
huawei_cdc_ncm_wdm_manage_power);
if (IS_ERR(subdriver)) {
ret = PTR_ERR(subdriver);
cdc_ncm_unbind(usbnet_dev, intf);
goto err;
}
usbnet_dev->status = NULL;
drvstate->subdriver = subdriver;
err:
return ret;
}
static void huawei_cdc_ncm_unbind(struct usbnet *usbnet_dev,
struct usb_interface *intf)
{
struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
struct cdc_ncm_ctx *ctx = drvstate->ctx;
if (drvstate->subdriver && drvstate->subdriver->disconnect)
drvstate->subdriver->disconnect(ctx->control);
drvstate->subdriver = NULL;
cdc_ncm_unbind(usbnet_dev, intf);
}
static int huawei_cdc_ncm_suspend(struct usb_interface *intf,
pm_message_t message)
{
int ret = 0;
struct usbnet *usbnet_dev = usb_get_intfdata(intf);
struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
struct cdc_ncm_ctx *ctx = drvstate->ctx;
if (ctx == NULL) {
ret = -ENODEV;
goto error;
}
ret = usbnet_suspend(intf, message);
if (ret < 0)
goto error;
if (intf == ctx->control &&
drvstate->subdriver &&
drvstate->subdriver->suspend)
ret = drvstate->subdriver->suspend(intf, message);
if (ret < 0)
usbnet_resume(intf);
error:
return ret;
}
static int huawei_cdc_ncm_resume(struct usb_interface *intf)
{
int ret = 0;
struct usbnet *usbnet_dev = usb_get_intfdata(intf);
struct huawei_cdc_ncm_state *drvstate = (void *)&usbnet_dev->data;
bool callsub;
struct cdc_ncm_ctx *ctx = drvstate->ctx;
callsub =
(intf == ctx->control &&
drvstate->subdriver &&
drvstate->subdriver->resume);
if (callsub)
ret = drvstate->subdriver->resume(intf);
if (ret < 0)
goto err;
ret = usbnet_resume(intf);
if (ret < 0 && callsub)
drvstate->subdriver->suspend(intf, PMSG_SUSPEND);
err:
return ret;
}
