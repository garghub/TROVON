static int prism2sta_probe_usb(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *dev;
wlandevice_t *wlandev = NULL;
hfa384x_t *hw = NULL;
int result = 0;
dev = interface_to_usbdev(interface);
wlandev = create_wlan();
if (wlandev == NULL) {
printk(KERN_ERR "%s: Memory allocation failure.\n", dev_info);
result = -EIO;
goto failed;
}
hw = wlandev->priv;
if (wlan_setup(wlandev, &(interface->dev)) != 0) {
printk(KERN_ERR "%s: wlan_setup() failed.\n", dev_info);
result = -EIO;
goto failed;
}
hfa384x_create(hw, dev);
hw->wlandev = wlandev;
SET_NETDEV_DEV(wlandev->netdev, &(interface->dev));
if (prism2_doreset) {
result = hfa384x_corereset(hw,
prism2_reset_holdtime,
prism2_reset_settletime, 0);
if (result != 0) {
unregister_wlandev(wlandev);
hfa384x_destroy(hw);
result = -EIO;
printk(KERN_ERR
"%s: hfa384x_corereset() failed.\n", dev_info);
goto failed;
}
}
usb_get_dev(dev);
wlandev->msdstate = WLAN_MSD_HWPRESENT;
prism2_fwtry(dev, wlandev);
prism2sta_ifstate(wlandev, P80211ENUM_ifstate_enable);
if (register_wlandev(wlandev) != 0) {
printk(KERN_ERR "%s: register_wlandev() failed.\n", dev_info);
result = -EIO;
goto failed;
}
goto done;
failed:
kfree(wlandev);
kfree(hw);
wlandev = NULL;
done:
usb_set_intfdata(interface, wlandev);
return result;
}
static void prism2sta_disconnect_usb(struct usb_interface *interface)
{
wlandevice_t *wlandev;
wlandev = (wlandevice_t *) usb_get_intfdata(interface);
if (wlandev != NULL) {
LIST_HEAD(cleanlist);
struct list_head *entry;
struct list_head *temp;
unsigned long flags;
hfa384x_t *hw = wlandev->priv;
if (!hw)
goto exit;
spin_lock_irqsave(&hw->ctlxq.lock, flags);
p80211netdev_hwremoved(wlandev);
list_splice_init(&hw->ctlxq.reapable, &cleanlist);
list_splice_init(&hw->ctlxq.completing, &cleanlist);
list_splice_init(&hw->ctlxq.pending, &cleanlist);
list_splice_init(&hw->ctlxq.active, &cleanlist);
spin_unlock_irqrestore(&hw->ctlxq.lock, flags);
prism2sta_ifstate(wlandev, P80211ENUM_ifstate_disable);
del_singleshot_timer_sync(&hw->throttle);
del_singleshot_timer_sync(&hw->reqtimer);
del_singleshot_timer_sync(&hw->resptimer);
usb_kill_urb(&hw->rx_urb);
usb_kill_urb(&hw->tx_urb);
usb_kill_urb(&hw->ctlx_urb);
tasklet_kill(&hw->completion_bh);
tasklet_kill(&hw->reaper_bh);
flush_scheduled_work();
list_for_each(entry, &cleanlist) {
hfa384x_usbctlx_t *ctlx;
ctlx = list_entry(entry, hfa384x_usbctlx_t, list);
complete(&ctlx->done);
}
msleep(100);
list_for_each_safe(entry, temp, &cleanlist) {
hfa384x_usbctlx_t *ctlx;
ctlx = list_entry(entry, hfa384x_usbctlx_t, list);
kfree(ctlx);
}
unregister_wlandev(wlandev);
wlan_unsetup(wlandev);
usb_put_dev(hw->usb);
hfa384x_destroy(hw);
kfree(hw);
kfree(wlandev);
}
exit:
usb_set_intfdata(interface, NULL);
}
static int prism2sta_suspend(struct usb_interface *interface,
pm_message_t message)
{
hfa384x_t *hw = NULL;
wlandevice_t *wlandev;
wlandev = (wlandevice_t *) usb_get_intfdata(interface);
if (!wlandev)
return -ENODEV;
hw = wlandev->priv;
if (!hw)
return -ENODEV;
prism2sta_ifstate(wlandev, P80211ENUM_ifstate_disable);
usb_kill_urb(&hw->rx_urb);
usb_kill_urb(&hw->tx_urb);
usb_kill_urb(&hw->ctlx_urb);
return 0;
}
static int prism2sta_resume(struct usb_interface *interface)
{
int result = 0;
hfa384x_t *hw = NULL;
wlandevice_t *wlandev;
wlandev = (wlandevice_t *) usb_get_intfdata(interface);
if (!wlandev)
return -ENODEV;
hw = wlandev->priv;
if (!hw)
return -ENODEV;
if (prism2_doreset) {
result = hfa384x_corereset(hw,
prism2_reset_holdtime,
prism2_reset_settletime, 0);
if (result != 0) {
unregister_wlandev(wlandev);
hfa384x_destroy(hw);
printk(KERN_ERR
"%s: hfa384x_corereset() failed.\n", dev_info);
kfree(wlandev);
kfree(hw);
wlandev = NULL;
return -ENODEV;
}
}
prism2sta_ifstate(wlandev, P80211ENUM_ifstate_enable);
return 0;
}
static int __init prism2usb_init(void)
{
return usb_register(&prism2_usb_driver);
}
static void __exit prism2usb_cleanup(void)
{
usb_deregister(&prism2_usb_driver);
}
