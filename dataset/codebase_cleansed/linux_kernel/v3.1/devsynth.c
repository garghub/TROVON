static ssize_t speakup_file_write(struct file *fp, const char *buffer,
size_t nbytes, loff_t *ppos)
{
size_t count = nbytes;
const char *ptr = buffer;
size_t bytes;
unsigned long flags;
u_char buf[256];
if (synth == NULL)
return -ENODEV;
while (count > 0) {
bytes = min(count, sizeof(buf));
if (copy_from_user(buf, ptr, bytes))
return -EFAULT;
count -= bytes;
ptr += bytes;
spk_lock(flags);
synth_write(buf, bytes);
spk_unlock(flags);
}
return (ssize_t) nbytes;
}
static ssize_t speakup_file_read(struct file *fp, char *buf, size_t nbytes,
loff_t *ppos)
{
return 0;
}
static int speakup_file_open(struct inode *ip, struct file *fp)
{
if (synth == NULL)
return -ENODEV;
if (xchg(&dev_opened, 1))
return -EBUSY;
return 0;
}
static int speakup_file_release(struct inode *ip, struct file *fp)
{
dev_opened = 0;
return 0;
}
void speakup_register_devsynth(void)
{
if (misc_registered != 0)
return;
if (misc_register(&synth_device))
pr_warn("Couldn't initialize miscdevice /dev/synth.\n");
else {
pr_info("initialized device: /dev/synth, node (MAJOR %d, MINOR %d)\n",
MISC_MAJOR, SYNTH_MINOR);
misc_registered = 1;
}
}
void speakup_unregister_devsynth(void)
{
if (!misc_registered)
return;
pr_info("speakup: unregistering synth device /dev/synth\n");
misc_deregister(&synth_device);
misc_registered = 0;
}
