static void nfputs(const char *str, unsigned int count)
{
char buf[68];
buf[64] = 0;
while (count > 64) {
memcpy(buf, str, 64);
nf_call(stderr_id, buf);
str += 64;
count -= 64;
}
memcpy(buf, str, count);
buf[count] = 0;
nf_call(stderr_id, buf);
}
static void nfcon_write(struct console *con, const char *str,
unsigned int count)
{
nfputs(str, count);
}
static struct tty_driver *nfcon_device(struct console *con, int *index)
{
*index = 0;
return (con->flags & CON_ENABLED) ? nfcon_tty_driver : NULL;
}
static int nfcon_tty_open(struct tty_struct *tty, struct file *filp)
{
return 0;
}
static void nfcon_tty_close(struct tty_struct *tty, struct file *filp)
{
}
static int nfcon_tty_write(struct tty_struct *tty, const unsigned char *buf,
int count)
{
nfputs(buf, count);
return count;
}
static int nfcon_tty_put_char(struct tty_struct *tty, unsigned char ch)
{
char temp[2] = { ch, 0 };
nf_call(stderr_id, temp);
return 1;
}
static int nfcon_tty_write_room(struct tty_struct *tty)
{
return 64;
}
static int __init nf_debug_setup(char *arg)
{
if (strcmp(arg, "nfcon"))
return 0;
stderr_id = nf_get_id("NF_STDERR");
if (stderr_id) {
nf_console.flags |= CON_ENABLED;
register_console(&nf_console);
}
return 0;
}
static int __init nfcon_init(void)
{
int res;
stderr_id = nf_get_id("NF_STDERR");
if (!stderr_id)
return -ENODEV;
nfcon_tty_driver = alloc_tty_driver(1);
if (!nfcon_tty_driver)
return -ENOMEM;
nfcon_tty_driver->driver_name = "nfcon";
nfcon_tty_driver->name = "nfcon";
nfcon_tty_driver->type = TTY_DRIVER_TYPE_SYSTEM;
nfcon_tty_driver->subtype = SYSTEM_TYPE_TTY;
nfcon_tty_driver->init_termios = tty_std_termios;
nfcon_tty_driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(nfcon_tty_driver, &nfcon_tty_ops);
res = tty_register_driver(nfcon_tty_driver);
if (res) {
pr_err("failed to register nfcon tty driver\n");
put_tty_driver(nfcon_tty_driver);
return res;
}
if (!(nf_console.flags & CON_ENABLED))
register_console(&nf_console);
return 0;
}
static void __exit nfcon_exit(void)
{
unregister_console(&nf_console);
tty_unregister_driver(nfcon_tty_driver);
put_tty_driver(nfcon_tty_driver);
}
