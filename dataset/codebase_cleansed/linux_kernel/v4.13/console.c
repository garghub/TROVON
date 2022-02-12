static int usb_console_setup(struct console *co, char *options)
{
struct usbcons_info *info = &usbcons_info;
int baud = 9600;
int bits = 8;
int parity = 'n';
int doflow = 0;
int cflag = CREAD | HUPCL | CLOCAL;
char *s;
struct usb_serial *serial;
struct usb_serial_port *port;
int retval;
struct tty_struct *tty = NULL;
struct ktermios dummy;
if (options) {
baud = simple_strtoul(options, NULL, 10);
s = options;
while (*s >= '0' && *s <= '9')
s++;
if (*s)
parity = *s++;
if (*s)
bits = *s++ - '0';
if (*s)
doflow = (*s++ == 'r');
}
if (baud == 0)
baud = 9600;
switch (bits) {
case 7:
cflag |= CS7;
break;
default:
case 8:
cflag |= CS8;
break;
}
switch (parity) {
case 'o': case 'O':
cflag |= PARODD;
break;
case 'e': case 'E':
cflag |= PARENB;
break;
}
co->cflag = cflag;
port = usb_serial_port_get_by_minor(co->index);
if (port == NULL) {
pr_err("No USB device connected to ttyUSB%i\n", co->index);
return -ENODEV;
}
serial = port->serial;
retval = usb_autopm_get_interface(serial->interface);
if (retval)
goto error_get_interface;
tty_port_tty_set(&port->port, NULL);
info->port = port;
++port->port.count;
if (!tty_port_initialized(&port->port)) {
if (serial->type->set_termios) {
tty = kzalloc(sizeof(*tty), GFP_KERNEL);
if (!tty) {
retval = -ENOMEM;
goto reset_open_count;
}
kref_init(&tty->kref);
tty->driver = usb_serial_tty_driver;
tty->index = co->index;
init_ldsem(&tty->ldisc_sem);
spin_lock_init(&tty->files_lock);
INIT_LIST_HEAD(&tty->tty_files);
kref_get(&tty->driver->kref);
__module_get(tty->driver->owner);
tty->ops = &usb_console_fake_tty_ops;
tty_init_termios(tty);
tty_port_tty_set(&port->port, tty);
}
retval = serial->type->open(NULL, port);
if (retval) {
dev_err(&port->dev, "could not open USB console port\n");
goto fail;
}
if (serial->type->set_termios) {
tty->termios.c_cflag = cflag;
tty_termios_encode_baud_rate(&tty->termios, baud, baud);
memset(&dummy, 0, sizeof(struct ktermios));
serial->type->set_termios(tty, port, &dummy);
tty_port_tty_set(&port->port, NULL);
tty_kref_put(tty);
}
tty_port_set_initialized(&port->port, 1);
}
--port->port.count;
port->port.console = 1;
mutex_unlock(&serial->disc_mutex);
return retval;
fail:
tty_port_tty_set(&port->port, NULL);
tty_kref_put(tty);
reset_open_count:
port->port.count = 0;
usb_autopm_put_interface(serial->interface);
error_get_interface:
usb_serial_put(serial);
mutex_unlock(&serial->disc_mutex);
return retval;
}
static void usb_console_write(struct console *co,
const char *buf, unsigned count)
{
static struct usbcons_info *info = &usbcons_info;
struct usb_serial_port *port = info->port;
struct usb_serial *serial;
int retval = -ENODEV;
if (!port || port->serial->dev->state == USB_STATE_NOTATTACHED)
return;
serial = port->serial;
if (count == 0)
return;
dev_dbg(&port->dev, "%s - %d byte(s)\n", __func__, count);
if (!port->port.console) {
dev_dbg(&port->dev, "%s - port not opened\n", __func__);
return;
}
while (count) {
unsigned int i;
unsigned int lf;
for (i = 0, lf = 0 ; i < count ; i++) {
if (*(buf + i) == 10) {
lf = 1;
i++;
break;
}
}
retval = serial->type->write(NULL, port, buf, i);
dev_dbg(&port->dev, "%s - write: %d\n", __func__, retval);
if (lf) {
unsigned char cr = 13;
retval = serial->type->write(NULL, port, &cr, 1);
dev_dbg(&port->dev, "%s - write cr: %d\n",
__func__, retval);
}
buf += i;
count -= i;
}
}
static struct tty_driver *usb_console_device(struct console *co, int *index)
{
struct tty_driver **p = (struct tty_driver **)co->data;
if (!*p)
return NULL;
*index = co->index;
return *p;
}
void usb_serial_console_disconnect(struct usb_serial *serial)
{
if (serial->port[0] == usbcons_info.port) {
usb_serial_console_exit();
usb_serial_put(serial);
}
}
void usb_serial_console_init(int minor)
{
if (minor == 0) {
pr_debug("registering the USB serial console.\n");
register_console(&usbcons);
}
}
void usb_serial_console_exit(void)
{
if (usbcons_info.port) {
unregister_console(&usbcons);
usbcons_info.port->port.console = 0;
usbcons_info.port = NULL;
}
}
