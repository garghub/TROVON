static void stdio_announce(char *dev_name, int dev)
{
printk(KERN_INFO "Virtual console %d assigned device '%s'\n", dev,
dev_name);
}
static int con_config(char *str, char **error_out)
{
return line_config(vts, ARRAY_SIZE(vts), str, &opts, error_out);
}
static int con_get_config(char *dev, char *str, int size, char **error_out)
{
return line_get_config(dev, vts, ARRAY_SIZE(vts), str, size, error_out);
}
static int con_remove(int n, char **error_out)
{
return line_remove(vts, ARRAY_SIZE(vts), n, error_out);
}
static int con_open(struct tty_struct *tty, struct file *filp)
{
int err = line_open(vts, tty);
if (err)
printk(KERN_ERR "Failed to open console %d, err = %d\n",
tty->index, err);
return err;
}
static void uml_console_write(struct console *console, const char *string,
unsigned len)
{
struct line *line = &vts[console->index];
unsigned long flags;
spin_lock_irqsave(&line->lock, flags);
console_write_chan(line->chan_out, string, len);
spin_unlock_irqrestore(&line->lock, flags);
}
static struct tty_driver *uml_console_device(struct console *c, int *index)
{
*index = c->index;
return driver.driver;
}
static int uml_console_setup(struct console *co, char *options)
{
struct line *line = &vts[co->index];
return console_open_chan(line, co);
}
static int stdio_init(void)
{
char *new_title;
int err;
int i;
err = register_lines(&driver, &console_ops, vts,
ARRAY_SIZE(vts));
if (err)
return err;
printk(KERN_INFO "Initialized stdio console driver\n");
new_title = add_xterm_umid(opts.xterm_title);
if(new_title != NULL)
opts.xterm_title = new_title;
for (i = 0; i < MAX_TTYS; i++) {
char *error;
char *s = vt_conf[i];
if (!s)
s = def_conf;
if (!s)
s = i ? CONFIG_CON_CHAN : CONFIG_CON_ZERO_CHAN;
if (setup_one_line(vts, i, s, &opts, &error))
printk(KERN_ERR "setup_one_line failed for "
"device %d : %s\n", i, error);
}
con_init_done = 1;
register_console(&stdiocons);
return 0;
}
static void console_exit(void)
{
if (!con_init_done)
return;
close_lines(vts, ARRAY_SIZE(vts));
}
static int console_chan_setup(char *str)
{
line_setup(vt_conf, MAX_TTYS, &def_conf, str, "console");
return 1;
}
