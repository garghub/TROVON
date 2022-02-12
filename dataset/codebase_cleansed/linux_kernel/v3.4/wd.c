void mei_wd_set_start_timeout(struct mei_device *dev, u16 timeout)
{
dev_dbg(&dev->pdev->dev, "timeout=%d.\n", timeout);
memcpy(dev->wd_data, mei_start_wd_params, MEI_WD_PARAMS_SIZE);
memcpy(dev->wd_data + MEI_WD_PARAMS_SIZE,
&timeout, sizeof(u16));
}
bool mei_wd_host_init(struct mei_device *dev)
{
bool ret = false;
mei_cl_init(&dev->wd_cl, dev);
dev->wd_cl.state = MEI_FILE_DISCONNECTED;
dev->wd_timeout = AMT_WD_DEFAULT_TIMEOUT;
mei_find_me_client_update_filext(dev, &dev->wd_cl,
&mei_wd_guid, MEI_WD_HOST_CLIENT_ID);
dev_dbg(&dev->pdev->dev, "check wd_cl\n");
if (MEI_FILE_CONNECTING == dev->wd_cl.state) {
if (mei_connect(dev, &dev->wd_cl)) {
dev_dbg(&dev->pdev->dev, "Failed to connect to WD client\n");
dev->wd_cl.state = MEI_FILE_DISCONNECTED;
dev->wd_cl.host_client_id = 0;
ret = false;
goto end;
} else {
dev->wd_cl.timer_count = CONNECT_TIMEOUT;
}
} else {
dev_dbg(&dev->pdev->dev, "Failed to find WD client\n");
ret = false;
goto end;
}
end:
return ret;
}
int mei_wd_send(struct mei_device *dev)
{
struct mei_msg_hdr *mei_hdr;
mei_hdr = (struct mei_msg_hdr *) &dev->wr_msg_buf[0];
mei_hdr->host_addr = dev->wd_cl.host_client_id;
mei_hdr->me_addr = dev->wd_cl.me_client_id;
mei_hdr->msg_complete = 1;
mei_hdr->reserved = 0;
if (!memcmp(dev->wd_data, mei_start_wd_params, MEI_WD_PARAMS_SIZE))
mei_hdr->length = MEI_START_WD_DATA_SIZE;
else if (!memcmp(dev->wd_data, mei_stop_wd_params, MEI_WD_PARAMS_SIZE))
mei_hdr->length = MEI_WD_PARAMS_SIZE;
else
return -EINVAL;
return mei_write_message(dev, mei_hdr, dev->wd_data, mei_hdr->length);
}
int mei_wd_stop(struct mei_device *dev, bool preserve)
{
int ret;
u16 wd_timeout = dev->wd_timeout;
cancel_delayed_work(&dev->timer_work);
if (dev->wd_cl.state != MEI_FILE_CONNECTED || !dev->wd_timeout)
return 0;
dev->wd_timeout = 0;
dev->wd_due_counter = 0;
memcpy(dev->wd_data, mei_stop_wd_params, MEI_WD_PARAMS_SIZE);
dev->stop = true;
ret = mei_flow_ctrl_creds(dev, &dev->wd_cl);
if (ret < 0)
goto out;
if (ret && dev->mei_host_buffer_is_empty) {
ret = 0;
dev->mei_host_buffer_is_empty = false;
if (!mei_wd_send(dev)) {
ret = mei_flow_ctrl_reduce(dev, &dev->wd_cl);
if (ret)
goto out;
} else {
dev_dbg(&dev->pdev->dev, "send stop WD failed\n");
}
dev->wd_pending = false;
} else {
dev->wd_pending = true;
}
dev->wd_stopped = false;
mutex_unlock(&dev->device_lock);
ret = wait_event_interruptible_timeout(dev->wait_stop_wd,
dev->wd_stopped, 10 * HZ);
mutex_lock(&dev->device_lock);
if (dev->wd_stopped) {
dev_dbg(&dev->pdev->dev, "stop wd complete ret=%d.\n", ret);
ret = 0;
} else {
if (!ret)
ret = -ETIMEDOUT;
dev_warn(&dev->pdev->dev,
"stop wd failed to complete ret=%d.\n", ret);
}
if (preserve)
dev->wd_timeout = wd_timeout;
out:
return ret;
}
static int mei_wd_ops_start(struct watchdog_device *wd_dev)
{
int err = -ENODEV;
struct mei_device *dev;
dev = pci_get_drvdata(mei_device);
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
if (dev->mei_state != MEI_ENABLED) {
dev_dbg(&dev->pdev->dev, "mei_state != MEI_ENABLED mei_state= %d\n",
dev->mei_state);
goto end_unlock;
}
if (dev->wd_cl.state != MEI_FILE_CONNECTED) {
dev_dbg(&dev->pdev->dev, "MEI Driver is not connected to Watchdog Client\n");
goto end_unlock;
}
mei_wd_set_start_timeout(dev, dev->wd_timeout);
err = 0;
end_unlock:
mutex_unlock(&dev->device_lock);
return err;
}
static int mei_wd_ops_stop(struct watchdog_device *wd_dev)
{
struct mei_device *dev;
dev = pci_get_drvdata(mei_device);
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
mei_wd_stop(dev, false);
mutex_unlock(&dev->device_lock);
return 0;
}
static int mei_wd_ops_ping(struct watchdog_device *wd_dev)
{
int ret = 0;
struct mei_device *dev;
dev = pci_get_drvdata(mei_device);
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
if (dev->wd_cl.state != MEI_FILE_CONNECTED) {
dev_dbg(&dev->pdev->dev, "wd is not connected.\n");
ret = -ENODEV;
goto end;
}
if (dev->mei_host_buffer_is_empty &&
mei_flow_ctrl_creds(dev, &dev->wd_cl) > 0) {
dev->mei_host_buffer_is_empty = false;
dev_dbg(&dev->pdev->dev, "sending watchdog ping\n");
if (mei_wd_send(dev)) {
dev_dbg(&dev->pdev->dev, "wd send failed.\n");
ret = -EIO;
goto end;
}
if (mei_flow_ctrl_reduce(dev, &dev->wd_cl)) {
dev_dbg(&dev->pdev->dev, "mei_flow_ctrl_reduce() failed.\n");
ret = -EIO;
goto end;
}
} else {
dev->wd_pending = true;
}
end:
mutex_unlock(&dev->device_lock);
return ret;
}
static int mei_wd_ops_set_timeout(struct watchdog_device *wd_dev, unsigned int timeout)
{
struct mei_device *dev;
dev = pci_get_drvdata(mei_device);
if (!dev)
return -ENODEV;
if (timeout < AMT_WD_MIN_TIMEOUT || timeout > AMT_WD_MAX_TIMEOUT)
return -EINVAL;
mutex_lock(&dev->device_lock);
dev->wd_timeout = timeout;
wd_dev->timeout = timeout;
mei_wd_set_start_timeout(dev, dev->wd_timeout);
mutex_unlock(&dev->device_lock);
return 0;
}
void mei_watchdog_register(struct mei_device *dev)
{
dev_dbg(&dev->pdev->dev, "dev->wd_timeout =%d.\n", dev->wd_timeout);
dev->wd_due_counter = !!dev->wd_timeout;
if (watchdog_register_device(&amt_wd_dev)) {
dev_err(&dev->pdev->dev, "unable to register watchdog device.\n");
dev->wd_interface_reg = false;
} else {
dev_dbg(&dev->pdev->dev, "successfully register watchdog interface.\n");
dev->wd_interface_reg = true;
}
}
void mei_watchdog_unregister(struct mei_device *dev)
{
if (dev->wd_interface_reg)
watchdog_unregister_device(&amt_wd_dev);
dev->wd_interface_reg = false;
}
