int pwr_sleep_dsp(const u32 sleep_code, const u32 timeout)
{
struct bridge_drv_interface *intf_fxns;
struct bridge_dev_context *dw_context;
int status = -EPERM;
struct dev_object *hdev_obj = NULL;
u32 ioctlcode = 0;
u32 arg = timeout;
for (hdev_obj = (struct dev_object *)drv_get_first_dev_object();
hdev_obj != NULL;
hdev_obj =
(struct dev_object *)drv_get_next_dev_object((u32) hdev_obj)) {
if (dev_get_bridge_context(hdev_obj,
(struct bridge_dev_context **)
&dw_context)) {
continue;
}
if (dev_get_intf_fxns(hdev_obj,
(struct bridge_drv_interface **)
&intf_fxns)) {
continue;
}
if (sleep_code == PWR_DEEPSLEEP)
ioctlcode = BRDIOCTL_DEEPSLEEP;
else if (sleep_code == PWR_EMERGENCYDEEPSLEEP)
ioctlcode = BRDIOCTL_EMERGENCYSLEEP;
else
status = -EINVAL;
if (status != -EINVAL) {
status = (*intf_fxns->dev_cntrl) (dw_context,
ioctlcode,
(void *)&arg);
}
}
return status;
}
int pwr_wake_dsp(const u32 timeout)
{
struct bridge_drv_interface *intf_fxns;
struct bridge_dev_context *dw_context;
int status = -EPERM;
struct dev_object *hdev_obj = NULL;
u32 arg = timeout;
for (hdev_obj = (struct dev_object *)drv_get_first_dev_object();
hdev_obj != NULL;
hdev_obj = (struct dev_object *)drv_get_next_dev_object
((u32) hdev_obj)) {
if (!(dev_get_bridge_context(hdev_obj,
(struct bridge_dev_context
**)&dw_context))) {
if (!(dev_get_intf_fxns(hdev_obj,
(struct bridge_drv_interface **)&intf_fxns))) {
status =
(*intf_fxns->dev_cntrl) (dw_context,
BRDIOCTL_WAKEUP,
(void *)&arg);
}
}
}
return status;
}
int pwr_pm_pre_scale(u16 voltage_domain, u32 level)
{
struct bridge_drv_interface *intf_fxns;
struct bridge_dev_context *dw_context;
int status = -EPERM;
struct dev_object *hdev_obj = NULL;
u32 arg[2];
arg[0] = voltage_domain;
arg[1] = level;
for (hdev_obj = (struct dev_object *)drv_get_first_dev_object();
hdev_obj != NULL;
hdev_obj = (struct dev_object *)drv_get_next_dev_object
((u32) hdev_obj)) {
if (!(dev_get_bridge_context(hdev_obj,
(struct bridge_dev_context
**)&dw_context))) {
if (!(dev_get_intf_fxns(hdev_obj,
(struct bridge_drv_interface **)&intf_fxns))) {
status =
(*intf_fxns->dev_cntrl) (dw_context,
BRDIOCTL_PRESCALE_NOTIFY,
(void *)&arg);
}
}
}
return status;
}
int pwr_pm_post_scale(u16 voltage_domain, u32 level)
{
struct bridge_drv_interface *intf_fxns;
struct bridge_dev_context *dw_context;
int status = -EPERM;
struct dev_object *hdev_obj = NULL;
u32 arg[2];
arg[0] = voltage_domain;
arg[1] = level;
for (hdev_obj = (struct dev_object *)drv_get_first_dev_object();
hdev_obj != NULL;
hdev_obj = (struct dev_object *)drv_get_next_dev_object
((u32) hdev_obj)) {
if (!(dev_get_bridge_context(hdev_obj,
(struct bridge_dev_context
**)&dw_context))) {
if (!(dev_get_intf_fxns(hdev_obj,
(struct bridge_drv_interface **)&intf_fxns))) {
status =
(*intf_fxns->dev_cntrl) (dw_context,
BRDIOCTL_POSTSCALE_NOTIFY,
(void *)&arg);
}
}
}
return status;
}
