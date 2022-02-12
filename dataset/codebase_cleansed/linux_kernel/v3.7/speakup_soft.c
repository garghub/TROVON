static char *get_initstring(void)
{
static char buf[40];
char *cp;
struct var_t *var;
memset(buf, 0, sizeof(buf));
cp = buf;
var = synth_soft.vars;
while (var->var_id != MAXVARS) {
if (var->var_id != CAPS_START && var->var_id != CAPS_STOP
&& var->var_id != DIRECT)
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
spk_lock(flags);
if (synth_soft.alive) {
spk_unlock(flags);
return -EBUSY;
}
synth_soft.alive = 1;
spk_unlock(flags);
return 0;
}
static int softsynth_close(struct inode *inode, struct file *fp)
{
unsigned long flags;
spk_lock(flags);
synth_soft.alive = 0;
init_pos = 0;
spk_unlock(flags);
speakup_start_ttys();
return 0;
}
static ssize_t softsynth_read(struct file *fp, char *buf, size_t count,
loff_t *pos)
{
int chars_sent = 0;
char *cp;
char *init;
char ch;
int empty;
unsigned long flags;
DEFINE_WAIT(wait);
spk_lock(flags);
while (1) {
prepare_to_wait(&speakup_event, &wait, TASK_INTERRUPTIBLE);
if (!synth_buffer_empty() || speakup_info.flushing)
break;
spk_unlock(flags);
if (fp->f_flags & O_NONBLOCK) {
finish_wait(&speakup_event, &wait);
return -EAGAIN;
}
if (signal_pending(current)) {
finish_wait(&speakup_event, &wait);
return -ERESTARTSYS;
}
schedule();
spk_lock(flags);
}
finish_wait(&speakup_event, &wait);
cp = buf;
init = get_initstring();
while (chars_sent < count) {
if (speakup_info.flushing) {
speakup_info.flushing = 0;
ch = '\x18';
} else if (synth_buffer_empty()) {
break;
} else if (init[init_pos]) {
ch = init[init_pos++];
} else {
ch = synth_buffer_getc();
}
spk_unlock(flags);
if (copy_to_user(cp, &ch, 1))
return -EFAULT;
spk_lock(flags);
chars_sent++;
cp++;
}
*pos += chars_sent;
empty = synth_buffer_empty();
spk_unlock(flags);
if (empty) {
speakup_start_ttys();
*pos = 0;
}
return chars_sent;
}
static ssize_t softsynth_write(struct file *fp, const char *buf, size_t count,
loff_t *pos)
{
unsigned long supplied_index = 0;
int converted;
converted = kstrtoul_from_user(buf, count, 0, &supplied_index);
if (converted < 0)
return converted;
last_index = supplied_index;
return count;
}
static unsigned int softsynth_poll(struct file *fp,
struct poll_table_struct *wait)
{
unsigned long flags;
int ret = 0;
poll_wait(fp, &speakup_event, wait);
spk_lock(flags);
if (!synth_buffer_empty() || speakup_info.flushing)
ret = POLLIN | POLLRDNORM;
spk_unlock(flags);
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
misc_registered = 1;
pr_info("initialized device: /dev/softsynth, node (MAJOR 10, MINOR 26)\n");
return 0;
}
static void softsynth_release(void)
{
misc_deregister(&synth_device);
misc_registered = 0;
pr_info("unregistered /dev/softsynth\n");
}
static int softsynth_is_alive(struct spk_synth *synth)
{
if (synth_soft.alive)
return 1;
return 0;
}
static int __init soft_init(void)
{
return synth_add(&synth_soft);
}
static void __exit soft_exit(void)
{
synth_remove(&synth_soft);
}
