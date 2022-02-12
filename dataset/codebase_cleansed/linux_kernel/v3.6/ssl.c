static void ssl_announce(char *dev_name, int dev)
{
printk(KERN_INFO "Serial line %d assigned device '%s'\n", dev,
dev_name);
}
static int ssl_config(char *str, char **error_out)
{
return line_config(serial_lines, ARRAY_SIZE(serial_lines), str, &opts,
error_out);
}
static int ssl_get_config(char *dev, char *str, int size, char **error_out)
{
return line_get_config(dev, serial_lines, ARRAY_SIZE(serial_lines), str,
size, error_out);
}
static int ssl_remove(int n, char **error_out)
{
return line_remove(serial_lines, ARRAY_SIZE(serial_lines), n,
error_out);
}
static int ssl_install(struct tty_driver *driver, struct tty_struct *tty)
{
return line_install(driver, tty, &serial_lines[tty->index]);
}
static void ssl_console_write(struct console *c, const char *string,
unsigned len)
{
struct line *line = &serial_lines[c->index];
unsigned long flags;
spin_lock_irqsave(&line->lock, flags);
console_write_chan(line->chan_out, string, len);
spin_unlock_irqrestore(&line->lock, flags);
}
static struct tty_driver *ssl_console_device(struct console *c, int *index)
{
*index = c->index;
return driver.driver;
}
static int ssl_console_setup(struct console *co, char *options)
{
struct line *line = &serial_lines[co->index];
return console_open_chan(line, co);
}
static int ssl_init(void)
{
char *new_title;
int err;
int i;
printk(KERN_INFO "Initializing software serial port version %d\n",
ssl_version);
err = register_lines(&driver, &ssl_ops, serial_lines,
ARRAY_SIZE(serial_lines));
if (err)
return err;
new_title = add_xterm_umid(opts.xterm_title);
if (new_title != NULL)
opts.xterm_title = new_title;
for (i = 0; i < NR_PORTS; i++) {
char *error;
char *s = conf[i];
if (!s)
s = def_conf;
if (setup_one_line(serial_lines, i, s, &opts, &error))
printk(KERN_ERR "setup_one_line failed for "
"device %d : %s\n", i, error);
}
ssl_init_done = 1;
register_console(&ssl_cons);
return 0;
}
static void ssl_exit(void)
{
if (!ssl_init_done)
return;
close_lines(serial_lines, ARRAY_SIZE(serial_lines));
}
static int ssl_chan_setup(char *str)
{
line_setup(conf, NR_PORTS, &def_conf, str, "serial line");
return 1;
}
