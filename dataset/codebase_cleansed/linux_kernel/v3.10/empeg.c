static int empeg_startup(struct usb_serial *serial)
{
int r;
if (serial->dev->actconfig->desc.bConfigurationValue != 1) {
dev_err(&serial->dev->dev, "active config #%d != 1 ??\n",
serial->dev->actconfig->desc.bConfigurationValue);
return -ENODEV;
}
r = usb_reset_configuration(serial->dev);
return r;
}
static void empeg_init_termios(struct tty_struct *tty)
{
struct ktermios *termios = &tty->termios;
termios->c_iflag
&= ~(IGNBRK
| BRKINT
| PARMRK
| ISTRIP
| INLCR
| IGNCR
| ICRNL
| IXON);
termios->c_oflag
&= ~OPOST;
termios->c_lflag
&= ~(ECHO
| ECHONL
| ICANON
| ISIG
| IEXTEN);
termios->c_cflag
&= ~(CSIZE
| PARENB
| CBAUD);
termios->c_cflag
|= CS8;
tty_encode_baud_rate(tty, 115200, 115200);
}
