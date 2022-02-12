static void smd_tty_notify(void *priv, unsigned event)
{
unsigned char *ptr;
int avail;
struct smd_tty_info *info = priv;
struct tty_struct *tty;
if (event != SMD_EVENT_DATA)
return;
tty = tty_port_tty_get(&info->port);
if (!tty)
return;
for (;;) {
if (test_bit(TTY_THROTTLED, &tty->flags))
break;
avail = smd_read_avail(info->ch);
if (avail == 0)
break;
avail = tty_prepare_flip_string(&info->port, &ptr, avail);
if (smd_read(info->ch, ptr, avail) != avail) {
pr_err("OOPS - smd_tty_buffer mismatch?!");
}
tty_flip_buffer_push(&info->port);
}
tty_wakeup(tty);
tty_kref_put(tty);
}
static int smd_tty_port_activate(struct tty_port *tport, struct tty_struct *tty)
{
int i, res = 0;
int n = tty->index;
const char *name = NULL;
struct smd_tty_info *info = smd_tty + n;
for (i = 0; i < smd_tty_channels_len; i++) {
if (smd_tty_channels[i].id == n) {
name = smd_tty_channels[i].name;
break;
}
}
if (!name)
return -ENODEV;
if (info->ch)
smd_kick(info->ch);
else
res = smd_open(name, &info->ch, info, smd_tty_notify);
if (!res)
tty->driver_data = info;
return res;
}
static void smd_tty_port_shutdown(struct tty_port *tport)
{
struct smd_tty_info *info;
struct tty_struct *tty = tty_port_tty_get(tport);
info = tty->driver_data;
if (info->ch) {
smd_close(info->ch);
info->ch = 0;
}
tty->driver_data = 0;
tty_kref_put(tty);
}
static int smd_tty_open(struct tty_struct *tty, struct file *f)
{
struct smd_tty_info *info = smd_tty + tty->index;
return tty_port_open(&info->port, tty, f);
}
static void smd_tty_close(struct tty_struct *tty, struct file *f)
{
struct smd_tty_info *info = tty->driver_data;
tty_port_close(&info->port, tty, f);
}
static int smd_tty_write(struct tty_struct *tty,
const unsigned char *buf, int len)
{
struct smd_tty_info *info = tty->driver_data;
int avail;
avail = smd_write_avail(info->ch);
if (len > avail)
len = avail;
return smd_write(info->ch, buf, len);
}
static int smd_tty_write_room(struct tty_struct *tty)
{
struct smd_tty_info *info = tty->driver_data;
return smd_write_avail(info->ch);
}
static int smd_tty_chars_in_buffer(struct tty_struct *tty)
{
struct smd_tty_info *info = tty->driver_data;
return smd_read_avail(info->ch);
}
static void smd_tty_unthrottle(struct tty_struct *tty)
{
struct smd_tty_info *info = tty->driver_data;
smd_kick(info->ch);
}
static int __init smd_tty_init(void)
{
int ret, i;
smd_tty_driver = alloc_tty_driver(MAX_SMD_TTYS);
if (smd_tty_driver == 0)
return -ENOMEM;
smd_tty_driver->driver_name = "smd_tty_driver";
smd_tty_driver->name = "smd";
smd_tty_driver->major = 0;
smd_tty_driver->minor_start = 0;
smd_tty_driver->type = TTY_DRIVER_TYPE_SERIAL;
smd_tty_driver->subtype = SERIAL_TYPE_NORMAL;
smd_tty_driver->init_termios = tty_std_termios;
smd_tty_driver->init_termios.c_iflag = 0;
smd_tty_driver->init_termios.c_oflag = 0;
smd_tty_driver->init_termios.c_cflag = B38400 | CS8 | CREAD;
smd_tty_driver->init_termios.c_lflag = 0;
smd_tty_driver->flags = TTY_DRIVER_RESET_TERMIOS |
TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
tty_set_operations(smd_tty_driver, &smd_tty_ops);
ret = tty_register_driver(smd_tty_driver);
if (ret)
return ret;
for (i = 0; i < smd_tty_channels_len; i++) {
struct tty_port *port = &smd_tty[smd_tty_channels[i].id].port;
tty_port_init(port);
port->ops = &smd_tty_port_ops;
tty_port_register_device(port, smd_tty_driver,
smd_tty_channels[i].id, NULL);
}
return 0;
}
