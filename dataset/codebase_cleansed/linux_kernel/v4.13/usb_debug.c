static void usb_debug_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
if (!break_state)
return;
usb_serial_generic_write(tty, port, USB_DEBUG_BRK, USB_DEBUG_BRK_SIZE);
}
static void usb_debug_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
if (urb->actual_length == USB_DEBUG_BRK_SIZE &&
memcmp(urb->transfer_buffer, USB_DEBUG_BRK,
USB_DEBUG_BRK_SIZE) == 0) {
usb_serial_handle_break(port);
return;
}
usb_serial_generic_process_read_urb(urb);
}
