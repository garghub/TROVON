static int snd_timer_user_gparams_compat(struct file *file,
struct snd_timer_gparams32 __user *user)
{
struct snd_timer_gparams gparams;
if (copy_from_user(&gparams.tid, &user->tid, sizeof(gparams.tid)) ||
get_user(gparams.period_num, &user->period_num) ||
get_user(gparams.period_den, &user->period_den))
return -EFAULT;
return timer_set_gparams(&gparams);
}
static int snd_timer_user_info_compat(struct file *file,
struct snd_timer_info32 __user *_info)
{
struct snd_timer_user *tu;
struct snd_timer_info32 info;
struct snd_timer *t;
tu = file->private_data;
if (snd_BUG_ON(!tu->timeri))
return -ENXIO;
t = tu->timeri->timer;
if (snd_BUG_ON(!t))
return -ENXIO;
memset(&info, 0, sizeof(info));
info.card = t->card ? t->card->number : -1;
if (t->hw.flags & SNDRV_TIMER_HW_SLAVE)
info.flags |= SNDRV_TIMER_FLG_SLAVE;
strlcpy(info.id, t->id, sizeof(info.id));
strlcpy(info.name, t->name, sizeof(info.name));
info.resolution = t->hw.resolution;
if (copy_to_user(_info, &info, sizeof(*_info)))
return -EFAULT;
return 0;
}
static int snd_timer_user_status_compat(struct file *file,
struct snd_timer_status32 __user *_status)
{
struct snd_timer_user *tu;
struct snd_timer_status32 status;
tu = file->private_data;
if (snd_BUG_ON(!tu->timeri))
return -ENXIO;
memset(&status, 0, sizeof(status));
status.tstamp.tv_sec = tu->tstamp.tv_sec;
status.tstamp.tv_nsec = tu->tstamp.tv_nsec;
status.resolution = snd_timer_resolution(tu->timeri);
status.lost = tu->timeri->lost;
status.overrun = tu->overrun;
spin_lock_irq(&tu->qlock);
status.queue = tu->qused;
spin_unlock_irq(&tu->qlock);
if (copy_to_user(_status, &status, sizeof(status)))
return -EFAULT;
return 0;
}
static long __snd_timer_user_ioctl_compat(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = compat_ptr(arg);
switch (cmd) {
case SNDRV_TIMER_IOCTL_PVERSION:
case SNDRV_TIMER_IOCTL_TREAD:
case SNDRV_TIMER_IOCTL_GINFO:
case SNDRV_TIMER_IOCTL_GSTATUS:
case SNDRV_TIMER_IOCTL_SELECT:
case SNDRV_TIMER_IOCTL_PARAMS:
case SNDRV_TIMER_IOCTL_START:
case SNDRV_TIMER_IOCTL_START_OLD:
case SNDRV_TIMER_IOCTL_STOP:
case SNDRV_TIMER_IOCTL_STOP_OLD:
case SNDRV_TIMER_IOCTL_CONTINUE:
case SNDRV_TIMER_IOCTL_CONTINUE_OLD:
case SNDRV_TIMER_IOCTL_PAUSE:
case SNDRV_TIMER_IOCTL_PAUSE_OLD:
case SNDRV_TIMER_IOCTL_NEXT_DEVICE:
return __snd_timer_user_ioctl(file, cmd, (unsigned long)argp);
case SNDRV_TIMER_IOCTL_GPARAMS32:
return snd_timer_user_gparams_compat(file, argp);
case SNDRV_TIMER_IOCTL_INFO32:
return snd_timer_user_info_compat(file, argp);
case SNDRV_TIMER_IOCTL_STATUS32:
return snd_timer_user_status_compat(file, argp);
#ifdef CONFIG_X86_X32
case SNDRV_TIMER_IOCTL_STATUS_X32:
return snd_timer_user_status_x32(file, argp);
#endif
}
return -ENOIOCTLCMD;
}
static long snd_timer_user_ioctl_compat(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct snd_timer_user *tu = file->private_data;
long ret;
mutex_lock(&tu->ioctl_lock);
ret = __snd_timer_user_ioctl_compat(file, cmd, arg);
mutex_unlock(&tu->ioctl_lock);
return ret;
}
