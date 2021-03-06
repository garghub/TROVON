static int snd_rawmidi_ioctl_params_compat(struct snd_rawmidi_file *rfile,
struct snd_rawmidi_params32 __user *src)
{
struct snd_rawmidi_params params;
unsigned int val;
if (rfile->output == NULL)
return -EINVAL;
if (get_user(params.stream, &src->stream) ||
get_user(params.buffer_size, &src->buffer_size) ||
get_user(params.avail_min, &src->avail_min) ||
get_user(val, &src->no_active_sensing))
return -EFAULT;
params.no_active_sensing = val;
switch (params.stream) {
case SNDRV_RAWMIDI_STREAM_OUTPUT:
return snd_rawmidi_output_params(rfile->output, &params);
case SNDRV_RAWMIDI_STREAM_INPUT:
return snd_rawmidi_input_params(rfile->input, &params);
}
return -EINVAL;
}
static int snd_rawmidi_ioctl_status_compat(struct snd_rawmidi_file *rfile,
struct snd_rawmidi_status32 __user *src)
{
int err;
struct snd_rawmidi_status status;
if (rfile->output == NULL)
return -EINVAL;
if (get_user(status.stream, &src->stream))
return -EFAULT;
switch (status.stream) {
case SNDRV_RAWMIDI_STREAM_OUTPUT:
err = snd_rawmidi_output_status(rfile->output, &status);
break;
case SNDRV_RAWMIDI_STREAM_INPUT:
err = snd_rawmidi_input_status(rfile->input, &status);
break;
default:
return -EINVAL;
}
if (err < 0)
return err;
if (compat_put_timespec(&status.tstamp, &src->tstamp) ||
put_user(status.avail, &src->avail) ||
put_user(status.xruns, &src->xruns))
return -EFAULT;
return 0;
}
static int snd_rawmidi_ioctl_status_x32(struct snd_rawmidi_file *rfile,
struct snd_rawmidi_status_x32 __user *src)
{
int err;
struct snd_rawmidi_status status;
if (rfile->output == NULL)
return -EINVAL;
if (get_user(status.stream, &src->stream))
return -EFAULT;
switch (status.stream) {
case SNDRV_RAWMIDI_STREAM_OUTPUT:
err = snd_rawmidi_output_status(rfile->output, &status);
break;
case SNDRV_RAWMIDI_STREAM_INPUT:
err = snd_rawmidi_input_status(rfile->input, &status);
break;
default:
return -EINVAL;
}
if (err < 0)
return err;
if (put_timespec(&status.tstamp, &src->tstamp) ||
put_user(status.avail, &src->avail) ||
put_user(status.xruns, &src->xruns))
return -EFAULT;
return 0;
}
static long snd_rawmidi_ioctl_compat(struct file *file, unsigned int cmd, unsigned long arg)
{
struct snd_rawmidi_file *rfile;
void __user *argp = compat_ptr(arg);
rfile = file->private_data;
switch (cmd) {
case SNDRV_RAWMIDI_IOCTL_PVERSION:
case SNDRV_RAWMIDI_IOCTL_INFO:
case SNDRV_RAWMIDI_IOCTL_DROP:
case SNDRV_RAWMIDI_IOCTL_DRAIN:
return snd_rawmidi_ioctl(file, cmd, (unsigned long)argp);
case SNDRV_RAWMIDI_IOCTL_PARAMS32:
return snd_rawmidi_ioctl_params_compat(rfile, argp);
case SNDRV_RAWMIDI_IOCTL_STATUS32:
return snd_rawmidi_ioctl_status_compat(rfile, argp);
#ifdef CONFIG_X86_X32
case SNDRV_RAWMIDI_IOCTL_STATUS_X32:
return snd_rawmidi_ioctl_status_x32(rfile, argp);
#endif
}
return -ENOIOCTLCMD;
}
