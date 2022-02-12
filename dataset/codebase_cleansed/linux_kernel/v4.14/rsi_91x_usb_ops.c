void rsi_usb_rx_thread(struct rsi_common *common)
{
struct rsi_hw *adapter = common->priv;
struct rsi_91x_usbdev *dev = (struct rsi_91x_usbdev *)adapter->rsi_dev;
int status;
do {
rsi_wait_event(&dev->rx_thread.event, EVENT_WAIT_FOREVER);
if (atomic_read(&dev->rx_thread.thread_done))
goto out;
mutex_lock(&common->rx_lock);
status = rsi_read_pkt(common, 0);
if (status) {
rsi_dbg(ERR_ZONE, "%s: Failed To read data", __func__);
mutex_unlock(&common->rx_lock);
return;
}
mutex_unlock(&common->rx_lock);
rsi_reset_event(&dev->rx_thread.event);
if (adapter->rx_urb_submit(adapter)) {
rsi_dbg(ERR_ZONE,
"%s: Failed in urb submission", __func__);
return;
}
} while (1);
out:
rsi_dbg(INFO_ZONE, "%s: Terminated thread\n", __func__);
complete_and_exit(&dev->rx_thread.completion, 0);
}
