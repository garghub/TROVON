static void pdc_console_write(struct console *co, const char *s, unsigned count)
{
int i = 0;
unsigned long flags;
spin_lock_irqsave(&pdc_console_lock, flags);
do {
i += pdc_iodc_print(s + i, count - i);
} while (i < count);
spin_unlock_irqrestore(&pdc_console_lock, flags);
}
int pdc_console_poll_key(struct console *co)
{
int c;
unsigned long flags;
spin_lock_irqsave(&pdc_console_lock, flags);
c = pdc_iodc_getc();
spin_unlock_irqrestore(&pdc_console_lock, flags);
return c;
}
static int pdc_console_setup(struct console *co, char *options)
{
return 0;
}
static int pdc_console_tty_open(struct tty_struct *tty, struct file *filp)
{
tty_port_tty_set(&tty_port, tty);
mod_timer(&pdc_console_timer, jiffies + PDC_CONS_POLL_DELAY);
return 0;
}
static void pdc_console_tty_close(struct tty_struct *tty, struct file *filp)
{
if (tty->count == 1) {
del_timer_sync(&pdc_console_timer);
tty_port_tty_set(&tty_port, NULL);
}
}
static int pdc_console_tty_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
pdc_console_write(NULL, buf, count);
return count;
}
static int pdc_console_tty_write_room(struct tty_struct *tty)
{
return 32768;
}
static int pdc_console_tty_chars_in_buffer(struct tty_struct *tty)
{
return 0;
}
static void pdc_console_poll(unsigned long unused)
{
int data, count = 0;
struct tty_struct *tty = tty_port_tty_get(&tty_port);
if (!tty)
return;
while (1) {
data = pdc_console_poll_key(NULL);
if (data == -1)
break;
tty_insert_flip_char(tty, data & 0xFF, TTY_NORMAL);
count ++;
}
if (count)
tty_flip_buffer_push(tty);
tty_kref_put(tty);
if (pdc_cons.flags & CON_ENABLED)
mod_timer(&pdc_console_timer, jiffies + PDC_CONS_POLL_DELAY);
}
static int __init pdc_console_tty_driver_init(void)
{
int err;
struct console *tmp;
console_lock();
for_each_console(tmp)
if (tmp == &pdc_cons)
break;
console_unlock();
if (!tmp) {
printk(KERN_INFO "PDC console driver not registered anymore, not creating %s\n", pdc_cons.name);
return -ENODEV;
}
printk(KERN_INFO "The PDC console driver is still registered, removing CON_BOOT flag\n");
pdc_cons.flags &= ~CON_BOOT;
tty_port_init(&tty_port);
pdc_console_tty_driver = alloc_tty_driver(1);
if (!pdc_console_tty_driver)
return -ENOMEM;
pdc_console_tty_driver->driver_name = "pdc_cons";
pdc_console_tty_driver->name = "ttyB";
pdc_console_tty_driver->major = MUX_MAJOR;
pdc_console_tty_driver->minor_start = 0;
pdc_console_tty_driver->type = TTY_DRIVER_TYPE_SYSTEM;
pdc_console_tty_driver->init_termios = tty_std_termios;
pdc_console_tty_driver->flags = TTY_DRIVER_REAL_RAW |
TTY_DRIVER_RESET_TERMIOS;
tty_set_operations(pdc_console_tty_driver, &pdc_console_tty_ops);
err = tty_register_driver(pdc_console_tty_driver);
if (err) {
printk(KERN_ERR "Unable to register the PDC console TTY driver\n");
return err;
}
return 0;
}
static struct tty_driver * pdc_console_device (struct console *c, int *index)
{
*index = c->index;
return pdc_console_tty_driver;
}
static void pdc_console_init_force(void)
{
if (pdc_console_initialized)
return;
++pdc_console_initialized;
if (PAGE0->mem_cons.cl_class == CL_DUPLEX)
memcpy(&PAGE0->mem_kbd, &PAGE0->mem_cons, sizeof(PAGE0->mem_cons));
register_console(&pdc_cons);
}
void __init pdc_console_init(void)
{
#if defined(EARLY_BOOTUP_DEBUG) || defined(CONFIG_PDC_CONSOLE)
pdc_console_init_force();
#endif
#ifdef EARLY_BOOTUP_DEBUG
printk(KERN_INFO "Initialized PDC Console for debugging.\n");
#endif
}
void pdc_console_restart(void)
{
struct console *console;
if (pdc_console_initialized)
return;
if (console_drivers != NULL)
pdc_cons.flags &= ~CON_PRINTBUFFER;
while ((console = console_drivers) != NULL)
unregister_console(console_drivers);
pdc_console_init_force();
}
