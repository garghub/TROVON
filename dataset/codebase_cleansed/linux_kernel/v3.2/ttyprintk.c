static int tpk_printk(const unsigned char *buf, int count)
{
static char tmp[TPK_STR_SIZE + 4];
int i = tpk_curr;
if (buf == NULL) {
if (tpk_curr > 0) {
tmp[tpk_curr + 0] = '\n';
tmp[tpk_curr + 1] = '\0';
printk(KERN_INFO "%s%s", tpk_tag, tmp);
tpk_curr = 0;
}
return i;
}
for (i = 0; i < count; i++) {
tmp[tpk_curr] = buf[i];
if (tpk_curr < TPK_STR_SIZE) {
switch (buf[i]) {
case '\r':
tmp[tpk_curr + 0] = '\n';
tmp[tpk_curr + 1] = '\0';
printk(KERN_INFO "%s%s", tpk_tag, tmp);
tpk_curr = 0;
if (buf[i + 1] == '\n')
i++;
break;
case '\n':
tmp[tpk_curr + 1] = '\0';
printk(KERN_INFO "%s%s", tpk_tag, tmp);
tpk_curr = 0;
break;
default:
tpk_curr++;
}
} else {
tmp[tpk_curr + 1] = '\\';
tmp[tpk_curr + 2] = '\n';
tmp[tpk_curr + 3] = '\0';
printk(KERN_INFO "%s%s", tpk_tag, tmp);
tpk_curr = 0;
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
void *rp;
ttyprintk_driver = alloc_tty_driver(1);
if (!ttyprintk_driver)
return ret;
ttyprintk_driver->owner = THIS_MODULE;
ttyprintk_driver->driver_name = "ttyprintk";
ttyprintk_driver->name = "ttyprintk";
ttyprintk_driver->major = TTYAUX_MAJOR;
ttyprintk_driver->minor_start = 3;
ttyprintk_driver->num = 1;
ttyprintk_driver->type = TTY_DRIVER_TYPE_CONSOLE;
ttyprintk_driver->init_termios = tty_std_termios;
ttyprintk_driver->init_termios.c_oflag = OPOST | OCRNL | ONOCR | ONLRET;
ttyprintk_driver->flags = TTY_DRIVER_RESET_TERMIOS |
TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
tty_set_operations(ttyprintk_driver, &ttyprintk_ops);
ret = tty_register_driver(ttyprintk_driver);
if (ret < 0) {
printk(KERN_ERR "Couldn't register ttyprintk driver\n");
goto error;
}
rp = device_create(tty_class, NULL, MKDEV(TTYAUX_MAJOR, 3), NULL,
ttyprintk_driver->name);
if (IS_ERR(rp)) {
printk(KERN_ERR "Couldn't create ttyprintk device\n");
ret = PTR_ERR(rp);
goto error;
}
tty_port_init(&tpk_port.port);
tpk_port.port.ops = &null_ops;
mutex_init(&tpk_port.port_write_mutex);
return 0;
error:
put_tty_driver(ttyprintk_driver);
ttyprintk_driver = NULL;
return ret;
}
