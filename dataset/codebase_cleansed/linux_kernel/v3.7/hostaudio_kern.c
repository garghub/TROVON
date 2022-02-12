static int set_dsp(char *name, int *add)
{
dsp = name;
return 0;
}
static int set_mixer(char *name, int *add)
{
mixer = name;
return 0;
}
static ssize_t hostaudio_read(struct file *file, char __user *buffer,
size_t count, loff_t *ppos)
{
struct hostaudio_state *state = file->private_data;
void *kbuf;
int err;
#ifdef DEBUG
printk(KERN_DEBUG "hostaudio: read called, count = %d\n", count);
#endif
kbuf = kmalloc(count, GFP_KERNEL);
if (kbuf == NULL)
return -ENOMEM;
err = os_read_file(state->fd, kbuf, count);
if (err < 0)
goto out;
if (copy_to_user(buffer, kbuf, err))
err = -EFAULT;
out:
kfree(kbuf);
return err;
}
static ssize_t hostaudio_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
struct hostaudio_state *state = file->private_data;
void *kbuf;
int err;
#ifdef DEBUG
printk(KERN_DEBUG "hostaudio: write called, count = %d\n", count);
#endif
kbuf = kmalloc(count, GFP_KERNEL);
if (kbuf == NULL)
return -ENOMEM;
err = -EFAULT;
if (copy_from_user(kbuf, buffer, count))
goto out;
err = os_write_file(state->fd, kbuf, count);
if (err < 0)
goto out;
*ppos += err;
out:
kfree(kbuf);
return err;
}
static unsigned int hostaudio_poll(struct file *file,
struct poll_table_struct *wait)
{
unsigned int mask = 0;
#ifdef DEBUG
printk(KERN_DEBUG "hostaudio: poll called (unimplemented)\n");
#endif
return mask;
}
static long hostaudio_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
struct hostaudio_state *state = file->private_data;
unsigned long data = 0;
int err;
#ifdef DEBUG
printk(KERN_DEBUG "hostaudio: ioctl called, cmd = %u\n", cmd);
#endif
switch(cmd){
case SNDCTL_DSP_SPEED:
case SNDCTL_DSP_STEREO:
case SNDCTL_DSP_GETBLKSIZE:
case SNDCTL_DSP_CHANNELS:
case SNDCTL_DSP_SUBDIVIDE:
case SNDCTL_DSP_SETFRAGMENT:
if (get_user(data, (int __user *) arg))
return -EFAULT;
break;
default:
break;
}
err = os_ioctl_generic(state->fd, cmd, (unsigned long) &data);
switch(cmd){
case SNDCTL_DSP_SPEED:
case SNDCTL_DSP_STEREO:
case SNDCTL_DSP_GETBLKSIZE:
case SNDCTL_DSP_CHANNELS:
case SNDCTL_DSP_SUBDIVIDE:
case SNDCTL_DSP_SETFRAGMENT:
if (put_user(data, (int __user *) arg))
return -EFAULT;
break;
default:
break;
}
return err;
}
static int hostaudio_open(struct inode *inode, struct file *file)
{
struct hostaudio_state *state;
int r = 0, w = 0;
int ret;
#ifdef DEBUG
kparam_block_sysfs_write(dsp);
printk(KERN_DEBUG "hostaudio: open called (host: %s)\n", dsp);
kparam_unblock_sysfs_write(dsp);
#endif
state = kmalloc(sizeof(struct hostaudio_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
if (file->f_mode & FMODE_READ)
r = 1;
if (file->f_mode & FMODE_WRITE)
w = 1;
kparam_block_sysfs_write(dsp);
mutex_lock(&hostaudio_mutex);
ret = os_open_file(dsp, of_set_rw(OPENFLAGS(), r, w), 0);
mutex_unlock(&hostaudio_mutex);
kparam_unblock_sysfs_write(dsp);
if (ret < 0) {
kfree(state);
return ret;
}
state->fd = ret;
file->private_data = state;
return 0;
}
static int hostaudio_release(struct inode *inode, struct file *file)
{
struct hostaudio_state *state = file->private_data;
#ifdef DEBUG
printk(KERN_DEBUG "hostaudio: release called\n");
#endif
os_close_file(state->fd);
kfree(state);
return 0;
}
static long hostmixer_ioctl_mixdev(struct file *file,
unsigned int cmd, unsigned long arg)
{
struct hostmixer_state *state = file->private_data;
#ifdef DEBUG
printk(KERN_DEBUG "hostmixer: ioctl called\n");
#endif
return os_ioctl_generic(state->fd, cmd, arg);
}
static int hostmixer_open_mixdev(struct inode *inode, struct file *file)
{
struct hostmixer_state *state;
int r = 0, w = 0;
int ret;
#ifdef DEBUG
printk(KERN_DEBUG "hostmixer: open called (host: %s)\n", mixer);
#endif
state = kmalloc(sizeof(struct hostmixer_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
if (file->f_mode & FMODE_READ)
r = 1;
if (file->f_mode & FMODE_WRITE)
w = 1;
kparam_block_sysfs_write(mixer);
mutex_lock(&hostaudio_mutex);
ret = os_open_file(mixer, of_set_rw(OPENFLAGS(), r, w), 0);
mutex_unlock(&hostaudio_mutex);
kparam_unblock_sysfs_write(mixer);
if (ret < 0) {
kparam_block_sysfs_write(dsp);
printk(KERN_ERR "hostaudio_open_mixdev failed to open '%s', "
"err = %d\n", dsp, -ret);
kparam_unblock_sysfs_write(dsp);
kfree(state);
return ret;
}
file->private_data = state;
return 0;
}
static int hostmixer_release(struct inode *inode, struct file *file)
{
struct hostmixer_state *state = file->private_data;
#ifdef DEBUG
printk(KERN_DEBUG "hostmixer: release called\n");
#endif
os_close_file(state->fd);
kfree(state);
return 0;
}
static int __init hostaudio_init_module(void)
{
__kernel_param_lock();
printk(KERN_INFO "UML Audio Relay (host dsp = %s, host mixer = %s)\n",
dsp, mixer);
__kernel_param_unlock();
module_data.dev_audio = register_sound_dsp(&hostaudio_fops, -1);
if (module_data.dev_audio < 0) {
printk(KERN_ERR "hostaudio: couldn't register DSP device!\n");
return -ENODEV;
}
module_data.dev_mixer = register_sound_mixer(&hostmixer_fops, -1);
if (module_data.dev_mixer < 0) {
printk(KERN_ERR "hostmixer: couldn't register mixer "
"device!\n");
unregister_sound_dsp(module_data.dev_audio);
return -ENODEV;
}
return 0;
}
static void __exit hostaudio_cleanup_module (void)
{
unregister_sound_mixer(module_data.dev_mixer);
unregister_sound_dsp(module_data.dev_audio);
}
