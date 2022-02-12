static int snd_seq_call_port_info_ioctl(struct snd_seq_client *client, unsigned int cmd,
struct snd_seq_port_info32 __user *data32)
{
int err = -EFAULT;
struct snd_seq_port_info *data;
mm_segment_t fs;
data = kmalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (copy_from_user(data, data32, sizeof(*data32)) ||
get_user(data->flags, &data32->flags) ||
get_user(data->time_queue, &data32->time_queue))
goto error;
data->kernel = NULL;
fs = snd_enter_user();
err = snd_seq_do_ioctl(client, cmd, data);
snd_leave_user(fs);
if (err < 0)
goto error;
if (copy_to_user(data32, data, sizeof(*data32)) ||
put_user(data->flags, &data32->flags) ||
put_user(data->time_queue, &data32->time_queue))
err = -EFAULT;
error:
kfree(data);
return err;
}
static long snd_seq_ioctl_compat(struct file *file, unsigned int cmd, unsigned long arg)
{
struct snd_seq_client *client = file->private_data;
void __user *argp = compat_ptr(arg);
if (snd_BUG_ON(!client))
return -ENXIO;
switch (cmd) {
case SNDRV_SEQ_IOCTL_PVERSION:
case SNDRV_SEQ_IOCTL_CLIENT_ID:
case SNDRV_SEQ_IOCTL_SYSTEM_INFO:
case SNDRV_SEQ_IOCTL_GET_CLIENT_INFO:
case SNDRV_SEQ_IOCTL_SET_CLIENT_INFO:
case SNDRV_SEQ_IOCTL_SUBSCRIBE_PORT:
case SNDRV_SEQ_IOCTL_UNSUBSCRIBE_PORT:
case SNDRV_SEQ_IOCTL_CREATE_QUEUE:
case SNDRV_SEQ_IOCTL_DELETE_QUEUE:
case SNDRV_SEQ_IOCTL_GET_QUEUE_INFO:
case SNDRV_SEQ_IOCTL_SET_QUEUE_INFO:
case SNDRV_SEQ_IOCTL_GET_NAMED_QUEUE:
case SNDRV_SEQ_IOCTL_GET_QUEUE_STATUS:
case SNDRV_SEQ_IOCTL_GET_QUEUE_TEMPO:
case SNDRV_SEQ_IOCTL_SET_QUEUE_TEMPO:
case SNDRV_SEQ_IOCTL_GET_QUEUE_TIMER:
case SNDRV_SEQ_IOCTL_SET_QUEUE_TIMER:
case SNDRV_SEQ_IOCTL_GET_QUEUE_CLIENT:
case SNDRV_SEQ_IOCTL_SET_QUEUE_CLIENT:
case SNDRV_SEQ_IOCTL_GET_CLIENT_POOL:
case SNDRV_SEQ_IOCTL_SET_CLIENT_POOL:
case SNDRV_SEQ_IOCTL_REMOVE_EVENTS:
case SNDRV_SEQ_IOCTL_QUERY_SUBS:
case SNDRV_SEQ_IOCTL_GET_SUBSCRIPTION:
case SNDRV_SEQ_IOCTL_QUERY_NEXT_CLIENT:
case SNDRV_SEQ_IOCTL_RUNNING_MODE:
return snd_seq_do_ioctl(client, cmd, argp);
case SNDRV_SEQ_IOCTL_CREATE_PORT32:
return snd_seq_call_port_info_ioctl(client, SNDRV_SEQ_IOCTL_CREATE_PORT, argp);
case SNDRV_SEQ_IOCTL_DELETE_PORT32:
return snd_seq_call_port_info_ioctl(client, SNDRV_SEQ_IOCTL_DELETE_PORT, argp);
case SNDRV_SEQ_IOCTL_GET_PORT_INFO32:
return snd_seq_call_port_info_ioctl(client, SNDRV_SEQ_IOCTL_GET_PORT_INFO, argp);
case SNDRV_SEQ_IOCTL_SET_PORT_INFO32:
return snd_seq_call_port_info_ioctl(client, SNDRV_SEQ_IOCTL_SET_PORT_INFO, argp);
case SNDRV_SEQ_IOCTL_QUERY_NEXT_PORT32:
return snd_seq_call_port_info_ioctl(client, SNDRV_SEQ_IOCTL_QUERY_NEXT_PORT, argp);
}
return -ENOIOCTLCMD;
}
