static int cros_ec_pd_command(struct cros_ec_extcon_info *info,
unsigned int command,
unsigned int version,
void *outdata,
unsigned int outsize,
void *indata,
unsigned int insize)
{
struct cros_ec_command *msg;
int ret;
msg = kzalloc(sizeof(*msg) + max(outsize, insize), GFP_KERNEL);
if (!msg)
return -ENOMEM;
msg->version = version;
msg->command = command;
msg->outsize = outsize;
msg->insize = insize;
if (outsize)
memcpy(msg->data, outdata, outsize);
ret = cros_ec_cmd_xfer_status(info->ec, msg);
if (ret >= 0 && insize)
memcpy(indata, msg->data, insize);
kfree(msg);
return ret;
}
static int cros_ec_usb_get_power_type(struct cros_ec_extcon_info *info)
{
struct ec_params_usb_pd_power_info req;
struct ec_response_usb_pd_power_info resp;
int ret;
req.port = info->port_id;
ret = cros_ec_pd_command(info, EC_CMD_USB_PD_POWER_INFO, 0,
&req, sizeof(req), &resp, sizeof(resp));
if (ret < 0)
return ret;
return resp.type;
}
static int cros_ec_usb_get_pd_mux_state(struct cros_ec_extcon_info *info)
{
struct ec_params_usb_pd_mux_info req;
struct ec_response_usb_pd_mux_info resp;
int ret;
req.port = info->port_id;
ret = cros_ec_pd_command(info, EC_CMD_USB_PD_MUX_INFO, 0,
&req, sizeof(req),
&resp, sizeof(resp));
if (ret < 0)
return ret;
return resp.flags;
}
static int cros_ec_usb_get_role(struct cros_ec_extcon_info *info,
bool *polarity)
{
struct ec_params_usb_pd_control pd_control;
struct ec_response_usb_pd_control_v1 resp;
int ret;
pd_control.port = info->port_id;
pd_control.role = USB_PD_CTRL_ROLE_NO_CHANGE;
pd_control.mux = USB_PD_CTRL_MUX_NO_CHANGE;
ret = cros_ec_pd_command(info, EC_CMD_USB_PD_CONTROL, 1,
&pd_control, sizeof(pd_control),
&resp, sizeof(resp));
if (ret < 0)
return ret;
if (!(resp.enabled & PD_CTRL_RESP_ENABLED_CONNECTED))
return -ENOTCONN;
*polarity = resp.polarity;
return resp.role;
}
static int cros_ec_pd_get_num_ports(struct cros_ec_extcon_info *info)
{
struct ec_response_usb_pd_ports resp;
int ret;
ret = cros_ec_pd_command(info, EC_CMD_USB_PD_PORTS,
0, NULL, 0, &resp, sizeof(resp));
if (ret < 0)
return ret;
return resp.num_ports;
}
static int extcon_cros_ec_detect_cable(struct cros_ec_extcon_info *info,
bool force)
{
struct device *dev = info->dev;
int role, power_type;
bool polarity = false;
bool dp = false;
bool mux = false;
bool hpd = false;
power_type = cros_ec_usb_get_power_type(info);
if (power_type < 0) {
dev_err(dev, "failed getting power type err = %d\n",
power_type);
return power_type;
}
role = cros_ec_usb_get_role(info, &polarity);
if (role < 0) {
if (role != -ENOTCONN) {
dev_err(dev, "failed getting role err = %d\n", role);
return role;
}
} else {
int pd_mux_state;
pd_mux_state = cros_ec_usb_get_pd_mux_state(info);
if (pd_mux_state < 0)
pd_mux_state = USB_PD_MUX_USB_ENABLED;
dp = pd_mux_state & USB_PD_MUX_DP_ENABLED;
mux = pd_mux_state & USB_PD_MUX_USB_ENABLED;
hpd = pd_mux_state & USB_PD_MUX_HPD_IRQ;
}
if (force || info->dp != dp || info->mux != mux ||
info->power_type != power_type) {
info->dp = dp;
info->mux = mux;
info->power_type = power_type;
extcon_set_state(info->edev, EXTCON_DISP_DP, dp);
extcon_set_property(info->edev, EXTCON_DISP_DP,
EXTCON_PROP_USB_TYPEC_POLARITY,
(union extcon_property_value)(int)polarity);
extcon_set_property(info->edev, EXTCON_DISP_DP,
EXTCON_PROP_USB_SS,
(union extcon_property_value)(int)mux);
extcon_set_property(info->edev, EXTCON_DISP_DP,
EXTCON_PROP_DISP_HPD,
(union extcon_property_value)(int)hpd);
extcon_sync(info->edev, EXTCON_DISP_DP);
} else if (hpd) {
extcon_set_property(info->edev, EXTCON_DISP_DP,
EXTCON_PROP_DISP_HPD,
(union extcon_property_value)(int)hpd);
extcon_sync(info->edev, EXTCON_DISP_DP);
}
return 0;
}
static int extcon_cros_ec_event(struct notifier_block *nb,
unsigned long queued_during_suspend,
void *_notify)
{
struct cros_ec_extcon_info *info;
struct cros_ec_device *ec;
u32 host_event;
info = container_of(nb, struct cros_ec_extcon_info, notifier);
ec = info->ec;
host_event = cros_ec_get_host_event(ec);
if (host_event & (EC_HOST_EVENT_MASK(EC_HOST_EVENT_PD_MCU) |
EC_HOST_EVENT_MASK(EC_HOST_EVENT_USB_MUX))) {
extcon_cros_ec_detect_cable(info, false);
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static int extcon_cros_ec_probe(struct platform_device *pdev)
{
struct cros_ec_extcon_info *info;
struct cros_ec_device *ec = dev_get_drvdata(pdev->dev.parent);
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
int numports, ret;
info = devm_kzalloc(dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->dev = dev;
info->ec = ec;
if (np) {
u32 port;
ret = of_property_read_u32(np, "google,usb-port-id", &port);
if (ret < 0) {
dev_err(dev, "Missing google,usb-port-id property\n");
return ret;
}
info->port_id = port;
} else {
info->port_id = pdev->id;
}
numports = cros_ec_pd_get_num_ports(info);
if (numports < 0) {
dev_err(dev, "failed getting number of ports! ret = %d\n",
numports);
return numports;
}
if (info->port_id >= numports) {
dev_err(dev, "This system only supports %d ports\n", numports);
return -ENODEV;
}
info->edev = devm_extcon_dev_allocate(dev, usb_type_c_cable);
if (IS_ERR(info->edev)) {
dev_err(dev, "failed to allocate extcon device\n");
return -ENOMEM;
}
ret = devm_extcon_dev_register(dev, info->edev);
if (ret < 0) {
dev_err(dev, "failed to register extcon device\n");
return ret;
}
extcon_set_property_capability(info->edev, EXTCON_DISP_DP,
EXTCON_PROP_USB_TYPEC_POLARITY);
extcon_set_property_capability(info->edev, EXTCON_DISP_DP,
EXTCON_PROP_USB_SS);
extcon_set_property_capability(info->edev, EXTCON_DISP_DP,
EXTCON_PROP_DISP_HPD);
platform_set_drvdata(pdev, info);
info->notifier.notifier_call = extcon_cros_ec_event;
ret = blocking_notifier_chain_register(&info->ec->event_notifier,
&info->notifier);
if (ret < 0) {
dev_err(dev, "failed to register notifier\n");
return ret;
}
ret = extcon_cros_ec_detect_cable(info, true);
if (ret < 0) {
dev_err(dev, "failed to detect initial cable state\n");
goto unregister_notifier;
}
return 0;
unregister_notifier:
blocking_notifier_chain_unregister(&info->ec->event_notifier,
&info->notifier);
return ret;
}
static int extcon_cros_ec_remove(struct platform_device *pdev)
{
struct cros_ec_extcon_info *info = platform_get_drvdata(pdev);
blocking_notifier_chain_unregister(&info->ec->event_notifier,
&info->notifier);
return 0;
}
static int extcon_cros_ec_suspend(struct device *dev)
{
return 0;
}
static int extcon_cros_ec_resume(struct device *dev)
{
int ret;
struct cros_ec_extcon_info *info = dev_get_drvdata(dev);
ret = extcon_cros_ec_detect_cable(info, true);
if (ret < 0)
dev_err(dev, "failed to detect cable state on resume\n");
return 0;
}
