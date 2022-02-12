static char *get_initstring(void)
{
static char buf[40];
char *cp;
struct var_t *var;
memset(buf, 0, sizeof(buf));
cp = buf;
var = synth_soft.vars;
while (var->var_id != MAXVARS) {
if (var->var_id != CAPS_START && var->var_id != CAPS_STOP &&
var->var_id != DIRECT)
cp = cp + sprintf(cp, var->u.n.synth_fmt,
var->u.n.value);
var++;
}
cp = cp + sprintf(cp, "\n");
return buf;
}
static int softsynth_open(struct inode *inode, struct file *fp)
{
unsigned long flags;
spin_lock_irqsave(&speakup_info.spinlock, flags);
if (synth_soft.alive) {
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
return -EBUSY;
}
synth_soft.alive = 1;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
return 0;
}
static int softsynth_close(struct inode *inode, struct file *fp)
{
unsigned long flags;
spin_lock_irqsave(&speakup_info.spinlock, flags);
synth_soft.alive = 0;
init_pos = 0;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
speakup_start_ttys();
return 0;
}
static ssize_t softsynthx_read(struct file *fp, char __user *buf, size_t count,
loff_t *pos, int unicode)
{
int chars_sent = 0;
char __user *cp;
char *init;
u16 ch;
int empty;
unsigned long flags;
DEFINE_WAIT(wait);
spin_lock_irqsave(&speakup_info.spinlock, flags);
while (1) {
prepare_to_wait(&speakup_event, &wait, TASK_INTERRUPTIBLE);
if (!unicode)
synth_buffer_skip_nonlatin1();
if (!synth_buffer_empty() || speakup_info.flushing)
break;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (fp->f_flags & O_NONBLOCK) {
finish_wait(&speakup_event, &wait);
return -EAGAIN;
}
if (signal_pending(current)) {
finish_wait(&speakup_event, &wait);
return -ERESTARTSYS;
}
schedule();
spin_lock_irqsave(&speakup_info.spinlock, flags);
}
finish_wait(&speakup_event, &wait);
cp = buf;
init = get_initstring();
while (chars_sent <= count - 3) {
if (speakup_info.flushing) {
speakup_info.flushing = 0;
ch = '\x18';
} else if (init[init_pos]) {
ch = init[init_pos++];
} else {
if (!unicode)
synth_buffer_skip_nonlatin1();
if (synth_buffer_empty())
break;
ch = synth_buffer_getc();
}
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if ((!unicode && ch < 0x100) || (unicode && ch < 0x80)) {
u_char c = ch;
if (copy_to_user(cp, &c, 1))
return -EFAULT;
chars_sent++;
cp++;
} else if (unicode && ch < 0x800) {
u_char s[2] = {
0xc0 | (ch >> 6),
0x80 | (ch & 0x3f)
};
if (copy_to_user(cp, s, sizeof(s)))
return -EFAULT;
chars_sent += sizeof(s);
cp += sizeof(s);
} else if (unicode) {
u_char s[3] = {
0xe0 | (ch >> 12),
0x80 | ((ch >> 6) & 0x3f),
0x80 | (ch & 0x3f)
};
if (copy_to_user(cp, s, sizeof(s)))
return -EFAULT;
chars_sent += sizeof(s);
cp += sizeof(s);
}
spin_lock_irqsave(&speakup_info.spinlock, flags);
}
*pos += chars_sent;
empty = synth_buffer_empty();
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (empty) {
speakup_start_ttys();
*pos = 0;
}
return chars_sent;
}
static ssize_t softsynth_read(struct file *fp, char __user *buf, size_t count,
loff_t *pos)
{
return softsynthx_read(fp, buf, count, pos, 0);
}
static ssize_t softsynthu_read(struct file *fp, char __user *buf, size_t count,
loff_t *pos)
{
return softsynthx_read(fp, buf, count, pos, 1);
}
static ssize_t softsynth_write(struct file *fp, const char __user *buf,
size_t count, loff_t *pos)
{
unsigned long supplied_index = 0;
int converted;
converted = kstrtoul_from_user(buf, count, 0, &supplied_index);
if (converted < 0)
return converted;
last_index = supplied_index;
return count;
}
static unsigned int softsynth_poll(struct file *fp, struct poll_table_struct *wait)
{
unsigned long flags;
int ret = 0;
poll_wait(fp, &speakup_event, wait);
spin_lock_irqsave(&speakup_info.spinlock, flags);
if (!synth_buffer_empty() || speakup_info.flushing)
ret = POLLIN | POLLRDNORM;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
return ret;
}
static unsigned char get_index(void)
{
int rv;
rv = last_index;
last_index = 0;
return rv;
}
static int softsynth_probe(struct spk_synth *synth)
{
if (misc_registered != 0)
return 0;
memset(&synth_device, 0, sizeof(synth_device));
synth_device.minor = SOFTSYNTH_MINOR;
synth_device.name = "softsynth";
synth_device.fops = &softsynth_fops;
if (misc_register(&synth_device)) {
pr_warn("Couldn't initialize miscdevice /dev/softsynth.\n");
return -ENODEV;
}
memset(&synthu_device, 0, sizeof(synthu_device));
synthu_device.minor = SOFTSYNTHU_MINOR;
synthu_device.name = "softsynthu";
synthu_device.fops = &softsynthu_fops;
if (misc_register(&synthu_device)) {
pr_warn("Couldn't initialize miscdevice /dev/softsynth.\n");
return -ENODEV;
}
misc_registered = 1;
pr_info("initialized device: /dev/softsynth, node (MAJOR 10, MINOR 26)\n");
pr_info("initialized device: /dev/softsynthu, node (MAJOR 10, MINOR 27)\n");
return 0;
}
static void softsynth_release(void)
{
misc_deregister(&synth_device);
misc_deregister(&synthu_device);
misc_registered = 0;
pr_info("unregistered /dev/softsynth\n");
pr_info("unregistered /dev/softsynthu\n");
}
static int softsynth_is_alive(struct spk_synth *synth)
{
if (synth_soft.alive)
return 1;
return 0;
}
