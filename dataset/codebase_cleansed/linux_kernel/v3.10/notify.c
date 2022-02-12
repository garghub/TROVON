void usb_register_notify(struct notifier_block *nb)
{
blocking_notifier_chain_register(&usb_notifier_list, nb);
}
void usb_unregister_notify(struct notifier_block *nb)
{
blocking_notifier_chain_unregister(&usb_notifier_list, nb);
}
void usb_notify_add_device(struct usb_device *udev)
{
blocking_notifier_call_chain(&usb_notifier_list, USB_DEVICE_ADD, udev);
}
void usb_notify_remove_device(struct usb_device *udev)
{
mutex_lock(&usbfs_mutex);
blocking_notifier_call_chain(&usb_notifier_list,
USB_DEVICE_REMOVE, udev);
mutex_unlock(&usbfs_mutex);
}
void usb_notify_add_bus(struct usb_bus *ubus)
{
blocking_notifier_call_chain(&usb_notifier_list, USB_BUS_ADD, ubus);
}
void usb_notify_remove_bus(struct usb_bus *ubus)
{
blocking_notifier_call_chain(&usb_notifier_list, USB_BUS_REMOVE, ubus);
}
