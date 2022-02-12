static int serport_serio_write(struct serio *serio, unsigned char data)
{
struct serport *serport = serio->port_data;
return -(serport->tty->ops->write(serport->tty, &data, 1) != 1);
}
static int serport_serio_open(struct serio *serio)
{
struct serport *serport = serio->port_data;
unsigned long flags;
spin_lock_irqsave(&serport->lock, flags);
set_bit(SERPORT_ACTIVE, &serport->flags);
spin_unlock_irqrestore(&serport->lock, flags);
return 0;
}
static void serport_serio_close(struct serio *serio)
{
struct serport *serport = serio->port_data;
unsigned long flags;
spin_lock_irqsave(&serport->lock, flags);
clear_bit(SERPORT_ACTIVE, &serport->flags);
set_bit(SERPORT_DEAD, &serport->flags);
spin_unlock_irqrestore(&serport->lock, flags);
wake_up_interruptible(&serport->wait);
}
static int serport_ldisc_open(struct tty_struct *tty)
{
struct serport *serport;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
serport = kzalloc(sizeof(struct serport), GFP_KERNEL);
if (!serport)
return -ENOMEM;
serport->tty = tty;
spin_lock_init(&serport->lock);
init_waitqueue_head(&serport->wait);
tty->disc_data = serport;
tty->receive_room = 256;
set_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
return 0;
}
static void serport_ldisc_close(struct tty_struct *tty)
{
struct serport *serport = (struct serport *) tty->disc_data;
kfree(serport);
}
static void serport_ldisc_receive(struct tty_struct *tty, const unsigned char *cp, char *fp, int count)
{
struct serport *serport = (struct serport*) tty->disc_data;
unsigned long flags;
unsigned int ch_flags = 0;
int i;
spin_lock_irqsave(&serport->lock, flags);
if (!test_bit(SERPORT_ACTIVE, &serport->flags))
goto out;
for (i = 0; i < count; i++) {
if (fp) {
switch (fp[i]) {
case TTY_FRAME:
ch_flags = SERIO_FRAME;
break;
case TTY_PARITY:
ch_flags = SERIO_PARITY;
break;
default:
ch_flags = 0;
break;
}
}
serio_interrupt(serport->serio, cp[i], ch_flags);
}
out:
spin_unlock_irqrestore(&serport->lock, flags);
}
static ssize_t serport_ldisc_read(struct tty_struct * tty, struct file * file, unsigned char __user * buf, size_t nr)
{
struct serport *serport = (struct serport*) tty->disc_data;
struct serio *serio;
char name[64];
if (test_and_set_bit(SERPORT_BUSY, &serport->flags))
return -EBUSY;
serport->serio = serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!serio)
return -ENOMEM;
strlcpy(serio->name, "Serial port", sizeof(serio->name));
snprintf(serio->phys, sizeof(serio->phys), "%s/serio0", tty_name(tty, name));
serio->id = serport->id;
serio->id.type = SERIO_RS232;
serio->write = serport_serio_write;
serio->open = serport_serio_open;
serio->close = serport_serio_close;
serio->port_data = serport;
serio->dev.parent = tty->dev;
serio_register_port(serport->serio);
printk(KERN_INFO "serio: Serial port %s\n", tty_name(tty, name));
wait_event_interruptible(serport->wait, test_bit(SERPORT_DEAD, &serport->flags));
serio_unregister_port(serport->serio);
serport->serio = NULL;
clear_bit(SERPORT_DEAD, &serport->flags);
clear_bit(SERPORT_BUSY, &serport->flags);
return 0;
}
static void serport_set_type(struct tty_struct *tty, unsigned long type)
{
struct serport *serport = tty->disc_data;
serport->id.proto = type & 0x000000ff;
serport->id.id = (type & 0x0000ff00) >> 8;
serport->id.extra = (type & 0x00ff0000) >> 16;
}
static int serport_ldisc_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
if (cmd == SPIOCSTYPE) {
unsigned long type;
if (get_user(type, (unsigned long __user *) arg))
return -EFAULT;
serport_set_type(tty, type);
return 0;
}
return -EINVAL;
}
static long serport_ldisc_compat_ioctl(struct tty_struct *tty,
struct file *file,
unsigned int cmd, unsigned long arg)
{
if (cmd == COMPAT_SPIOCSTYPE) {
void __user *uarg = compat_ptr(arg);
compat_ulong_t compat_type;
if (get_user(compat_type, (compat_ulong_t __user *)uarg))
return -EFAULT;
serport_set_type(tty, compat_type);
return 0;
}
return -EINVAL;
}
static void serport_ldisc_write_wakeup(struct tty_struct * tty)
{
struct serport *serport = (struct serport *) tty->disc_data;
unsigned long flags;
spin_lock_irqsave(&serport->lock, flags);
if (test_bit(SERPORT_ACTIVE, &serport->flags))
serio_drv_write_wakeup(serport->serio);
spin_unlock_irqrestore(&serport->lock, flags);
}
static int __init serport_init(void)
{
int retval;
retval = tty_register_ldisc(N_MOUSE, &serport_ldisc);
if (retval)
printk(KERN_ERR "serport.c: Error registering line discipline.\n");
return retval;
}
static void __exit serport_exit(void)
{
tty_unregister_ldisc(N_MOUSE);
}
