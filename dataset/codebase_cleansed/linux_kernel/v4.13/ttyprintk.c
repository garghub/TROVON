static void tpk_flush(void)
{
if (tpk_curr > 0) {
tpk_buffer[tpk_curr] = '\0';
pr_info("[U] %s\n", tpk_buffer);
tpk_curr = 0;
}
}
static int tpk_printk(const unsigned char *buf, int count)
{
int i = tpk_curr;
if (buf == NULL) {
tpk_flush();
return i;
}
for (i = 0; i < count; i++) {
if (tpk_curr >= TPK_STR_SIZE) {
tpk_buffer[tpk_curr++] = '\\';
tpk_flush();
}
switch (buf[i]) {
case '\r':
tpk_flush();
if ((i + 1) < count && buf[i + 1] == '\n')
i++;
break;
case '\n':
tpk_flush();
break;
default:
tpk_buffer[tpk_curr++] = buf[i];
break;
}
}
return count;
}
static int tpk_open(struct tty_struct *tty, struct file *filp)
{
tty->driver_data = &tpk_port;
return tty_port_open(&tpk_port.port, tty, filp);
}
static void tpk_close(struct tty_struct *tty, struct file *filp)
{
struct ttyprintk_port *tpkp = tty->driver_data;
mutex_lock(&tpkp->port_write_mutex);
tpk_printk(NULL, 0);
mutex_unlock(&tpkp->port_write_mutex);
tty_port_close(&tpkp->port, tty, filp);
}
static int tpk_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct ttyprintk_port *tpkp = tty->driver_data;
int ret;
mutex_lock(&tpkp->port_write_mutex);
ret = tpk_printk(buf, count);
mutex_unlock(&tpkp->port_write_mutex);
return ret;
}
static int tpk_write_room(struct tty_struct *tty)
{
return TPK_MAX_ROOM;
}
static int tpk_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct ttyprintk_port *tpkp = tty->driver_data;
if (!tpkp)
return -EINVAL;
switch (cmd) {
case TIOCCONS:
return -EOPNOTSUPP;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static int __init ttyprintk_init(void)
{
int ret = -ENOMEM;
mutex_init(&tpk_port.port_write_mutex);
ttyprintk_driver = tty_alloc_driver(1,
TTY_DRIVER_RESET_TERMIOS |
TTY_DRIVER_REAL_RAW |
TTY_DRIVER_UNNUMBERED_NODE);
if (IS_ERR(ttyprintk_driver))
return PTR_ERR(ttyprintk_driver);
tty_port_init(&tpk_port.port);
tpk_port.port.ops = &null_ops;
ttyprintk_driver->driver_name = "ttyprintk";
ttyprintk_driver->name = "ttyprintk";
ttyprintk_driver->major = TTYAUX_MAJOR;
ttyprintk_driver->minor_start = 3;
ttyprintk_driver->type = TTY_DRIVER_TYPE_CONSOLE;
ttyprintk_driver->init_termios = tty_std_termios;
ttyprintk_driver->init_termios.c_oflag = OPOST | OCRNL | ONOCR | ONLRET;
tty_set_operations(ttyprintk_driver, &ttyprintk_ops);
tty_port_link_device(&tpk_port.port, ttyprintk_driver, 0);
ret = tty_register_driver(ttyprintk_driver);
if (ret < 0) {
printk(KERN_ERR "Couldn't register ttyprintk driver\n");
goto error;
}
return 0;
error:
put_tty_driver(ttyprintk_driver);
tty_port_destroy(&tpk_port.port);
return ret;
}
static void __exit ttyprintk_exit(void)
{
tty_unregister_driver(ttyprintk_driver);
put_tty_driver(ttyprintk_driver);
tty_port_destroy(&tpk_port.port);
}
