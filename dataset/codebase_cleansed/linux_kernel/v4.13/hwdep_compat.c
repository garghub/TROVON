static int snd_hwdep_dsp_load_compat(struct snd_hwdep *hw,
struct snd_hwdep_dsp_image32 __user *src)
{
struct snd_hwdep_dsp_image __user *dst;
compat_caddr_t ptr;
u32 val;
dst = compat_alloc_user_space(sizeof(*dst));
if (copy_in_user(dst, src, 4 + 64))
return -EFAULT;
if (get_user(ptr, &src->image) ||
put_user(compat_ptr(ptr), &dst->image))
return -EFAULT;
if (get_user(val, &src->length) ||
put_user(val, &dst->length))
return -EFAULT;
if (get_user(val, &src->driver_data) ||
put_user(val, &dst->driver_data))
return -EFAULT;
return snd_hwdep_dsp_load(hw, dst);
}
static long snd_hwdep_ioctl_compat(struct file * file, unsigned int cmd,
unsigned long arg)
{
struct snd_hwdep *hw = file->private_data;
void __user *argp = compat_ptr(arg);
switch (cmd) {
case SNDRV_HWDEP_IOCTL_PVERSION:
case SNDRV_HWDEP_IOCTL_INFO:
case SNDRV_HWDEP_IOCTL_DSP_STATUS:
return snd_hwdep_ioctl(file, cmd, (unsigned long)argp);
case SNDRV_HWDEP_IOCTL_DSP_LOAD32:
return snd_hwdep_dsp_load_compat(hw, argp);
}
if (hw->ops.ioctl_compat)
return hw->ops.ioctl_compat(hw, file, cmd, arg);
return -ENOIOCTLCMD;
}
