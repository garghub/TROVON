static void usb_debug_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
if (!break_state)
return;
usb_serial_generic_write(tty, port, USB_DEBUG_BRK, USB_DEBUG_BRK_SIZE);
}
static void usb_debug_read_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
if (urb->actual_length == USB_DEBUG_BRK_SIZE &&
memcmp(urb->transfer_buffer, USB_DEBUG_BRK,
USB_DEBUG_BRK_SIZE) == 0) {
usb_serial_handle_break(port);
usb_serial_generic_submit_read_urb(port, GFP_ATOMIC);
return;
}
usb_serial_generic_read_bulk_callback(urb);
}
static int __init debug_init(void)
{
int retval;
retval = usb_serial_register(&debug_device);
if (retval)
return retval;
retval = usb_register(&debug_driver);
if (retval)
usb_serial_deregister(&debug_device);
return retval;
}
static void __exit debug_exit(void)
{
usb_deregister(&debug_driver);
usb_serial_deregister(&debug_device);
}
