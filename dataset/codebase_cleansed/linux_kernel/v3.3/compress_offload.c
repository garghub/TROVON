static int snd_compr_open(struct inode *inode, struct file *f)
{
struct snd_compr *compr;
struct snd_compr_file *data;
struct snd_compr_runtime *runtime;
enum snd_compr_direction dirn;
int maj = imajor(inode);
int ret;
if (f->f_flags & O_WRONLY)
dirn = SND_COMPRESS_PLAYBACK;
else if (f->f_flags & O_RDONLY)
dirn = SND_COMPRESS_CAPTURE;
else {
pr_err("invalid direction\n");
return -EINVAL;
}
if (maj == snd_major)
compr = snd_lookup_minor_data(iminor(inode),
SNDRV_DEVICE_TYPE_COMPRESS);
else
return -EBADFD;
if (compr == NULL) {
pr_err("no device data!!!\n");
return -ENODEV;
}
if (dirn != compr->direction) {
pr_err("this device doesn't support this direction\n");
return -EINVAL;
}
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->stream.ops = compr->ops;
data->stream.direction = dirn;
data->stream.private_data = compr->private_data;
data->stream.device = compr;
runtime = kzalloc(sizeof(*runtime), GFP_KERNEL);
if (!runtime) {
kfree(data);
return -ENOMEM;
}
runtime->state = SNDRV_PCM_STATE_OPEN;
init_waitqueue_head(&runtime->sleep);
data->stream.runtime = runtime;
f->private_data = (void *)data;
mutex_lock(&compr->lock);
ret = compr->ops->open(&data->stream);
mutex_unlock(&compr->lock);
if (ret) {
kfree(runtime);
kfree(data);
}
return ret;
}
static int snd_compr_free(struct inode *inode, struct file *f)
{
struct snd_compr_file *data = f->private_data;
data->stream.ops->free(&data->stream);
kfree(data->stream.runtime->buffer);
kfree(data->stream.runtime);
kfree(data);
return 0;
}
static void snd_compr_update_tstamp(struct snd_compr_stream *stream,
struct snd_compr_tstamp *tstamp)
{
if (!stream->ops->pointer)
return;
stream->ops->pointer(stream, tstamp);
pr_debug("dsp consumed till %d total %d bytes\n",
tstamp->byte_offset, tstamp->copied_total);
stream->runtime->hw_pointer = tstamp->byte_offset;
stream->runtime->total_bytes_transferred = tstamp->copied_total;
}
static size_t snd_compr_calc_avail(struct snd_compr_stream *stream,
struct snd_compr_avail *avail)
{
long avail_calc;
snd_compr_update_tstamp(stream, &avail->tstamp);
if (stream->runtime->total_bytes_available == 0 &&
stream->runtime->state == SNDRV_PCM_STATE_SETUP) {
pr_debug("detected init and someone forgot to do a write\n");
return stream->runtime->buffer_size;
}
pr_debug("app wrote %lld, DSP consumed %lld\n",
stream->runtime->total_bytes_available,
stream->runtime->total_bytes_transferred);
if (stream->runtime->total_bytes_available ==
stream->runtime->total_bytes_transferred) {
pr_debug("both pointers are same, returning full avail\n");
return stream->runtime->buffer_size;
}
avail_calc = stream->runtime->buffer_size -
(stream->runtime->app_pointer - stream->runtime->hw_pointer);
pr_debug("calc avail as %ld, app_ptr %lld, hw+ptr %lld\n", avail_calc,
stream->runtime->app_pointer,
stream->runtime->hw_pointer);
if (avail_calc >= stream->runtime->buffer_size)
avail_calc -= stream->runtime->buffer_size;
pr_debug("ret avail as %ld\n", avail_calc);
avail->avail = avail_calc;
return avail_calc;
}
static inline size_t snd_compr_get_avail(struct snd_compr_stream *stream)
{
struct snd_compr_avail avail;
return snd_compr_calc_avail(stream, &avail);
}
static int
snd_compr_ioctl_avail(struct snd_compr_stream *stream, unsigned long arg)
{
struct snd_compr_avail ioctl_avail;
size_t avail;
avail = snd_compr_calc_avail(stream, &ioctl_avail);
ioctl_avail.avail = avail;
if (copy_to_user((__u64 __user *)arg,
&ioctl_avail, sizeof(ioctl_avail)))
return -EFAULT;
return 0;
}
static int snd_compr_write_data(struct snd_compr_stream *stream,
const char __user *buf, size_t count)
{
void *dstn;
size_t copy;
struct snd_compr_runtime *runtime = stream->runtime;
dstn = runtime->buffer + runtime->app_pointer;
pr_debug("copying %ld at %lld\n",
(unsigned long)count, runtime->app_pointer);
if (count < runtime->buffer_size - runtime->app_pointer) {
if (copy_from_user(dstn, buf, count))
return -EFAULT;
runtime->app_pointer += count;
} else {
copy = runtime->buffer_size - runtime->app_pointer;
if (copy_from_user(dstn, buf, copy))
return -EFAULT;
if (copy_from_user(runtime->buffer, buf + copy, count - copy))
return -EFAULT;
runtime->app_pointer = count - copy;
}
if (stream->ops->ack)
stream->ops->ack(stream, count);
return count;
}
static ssize_t snd_compr_write(struct file *f, const char __user *buf,
size_t count, loff_t *offset)
{
struct snd_compr_file *data = f->private_data;
struct snd_compr_stream *stream;
size_t avail;
int retval;
if (snd_BUG_ON(!data))
return -EFAULT;
stream = &data->stream;
mutex_lock(&stream->device->lock);
if (stream->runtime->state != SNDRV_PCM_STATE_SETUP &&
stream->runtime->state != SNDRV_PCM_STATE_RUNNING) {
mutex_unlock(&stream->device->lock);
return -EBADFD;
}
avail = snd_compr_get_avail(stream);
pr_debug("avail returned %ld\n", (unsigned long)avail);
if (avail > count)
avail = count;
if (stream->ops->copy)
retval = stream->ops->copy(stream, buf, avail);
else
retval = snd_compr_write_data(stream, buf, avail);
if (retval > 0)
stream->runtime->total_bytes_available += retval;
if (stream->runtime->state == SNDRV_PCM_STATE_SETUP) {
stream->runtime->state = SNDRV_PCM_STATE_PREPARED;
pr_debug("stream prepared, Houston we are good to go\n");
}
mutex_unlock(&stream->device->lock);
return retval;
}
static ssize_t snd_compr_read(struct file *f, char __user *buf,
size_t count, loff_t *offset)
{
return -ENXIO;
}
static int snd_compr_mmap(struct file *f, struct vm_area_struct *vma)
{
return -ENXIO;
}
static inline int snd_compr_get_poll(struct snd_compr_stream *stream)
{
if (stream->direction == SND_COMPRESS_PLAYBACK)
return POLLOUT | POLLWRNORM;
else
return POLLIN | POLLRDNORM;
}
static unsigned int snd_compr_poll(struct file *f, poll_table *wait)
{
struct snd_compr_file *data = f->private_data;
struct snd_compr_stream *stream;
size_t avail;
int retval = 0;
if (snd_BUG_ON(!data))
return -EFAULT;
stream = &data->stream;
if (snd_BUG_ON(!stream))
return -EFAULT;
mutex_lock(&stream->device->lock);
if (stream->runtime->state == SNDRV_PCM_STATE_PAUSED ||
stream->runtime->state == SNDRV_PCM_STATE_OPEN) {
retval = -EBADFD;
goto out;
}
poll_wait(f, &stream->runtime->sleep, wait);
avail = snd_compr_get_avail(stream);
pr_debug("avail is %ld\n", (unsigned long)avail);
switch (stream->runtime->state) {
case SNDRV_PCM_STATE_DRAINING:
retval = snd_compr_get_poll(stream);
stream->runtime->state = SNDRV_PCM_STATE_SETUP;
break;
case SNDRV_PCM_STATE_RUNNING:
case SNDRV_PCM_STATE_PREPARED:
case SNDRV_PCM_STATE_PAUSED:
if (avail >= stream->runtime->fragment_size)
retval = snd_compr_get_poll(stream);
break;
default:
if (stream->direction == SND_COMPRESS_PLAYBACK)
retval = POLLOUT | POLLWRNORM | POLLERR;
else
retval = POLLIN | POLLRDNORM | POLLERR;
break;
}
out:
mutex_unlock(&stream->device->lock);
return retval;
}
static int
snd_compr_get_caps(struct snd_compr_stream *stream, unsigned long arg)
{
int retval;
struct snd_compr_caps caps;
if (!stream->ops->get_caps)
return -ENXIO;
retval = stream->ops->get_caps(stream, &caps);
if (retval)
goto out;
if (copy_to_user((void __user *)arg, &caps, sizeof(caps)))
retval = -EFAULT;
out:
return retval;
}
static int
snd_compr_get_codec_caps(struct snd_compr_stream *stream, unsigned long arg)
{
int retval;
struct snd_compr_codec_caps *caps;
if (!stream->ops->get_codec_caps)
return -ENXIO;
caps = kmalloc(sizeof(*caps), GFP_KERNEL);
if (!caps)
return -ENOMEM;
retval = stream->ops->get_codec_caps(stream, caps);
if (retval)
goto out;
if (copy_to_user((void __user *)arg, caps, sizeof(*caps)))
retval = -EFAULT;
out:
kfree(caps);
return retval;
}
static int snd_compr_allocate_buffer(struct snd_compr_stream *stream,
struct snd_compr_params *params)
{
unsigned int buffer_size;
void *buffer;
buffer_size = params->buffer.fragment_size * params->buffer.fragments;
if (stream->ops->copy) {
buffer = NULL;
} else {
buffer = kmalloc(buffer_size, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
}
stream->runtime->fragment_size = params->buffer.fragment_size;
stream->runtime->fragments = params->buffer.fragments;
stream->runtime->buffer = buffer;
stream->runtime->buffer_size = buffer_size;
return 0;
}
static int
snd_compr_set_params(struct snd_compr_stream *stream, unsigned long arg)
{
struct snd_compr_params *params;
int retval;
if (stream->runtime->state == SNDRV_PCM_STATE_OPEN) {
params = kmalloc(sizeof(*params), GFP_KERNEL);
if (!params)
return -ENOMEM;
if (copy_from_user(params, (void __user *)arg, sizeof(*params))) {
retval = -EFAULT;
goto out;
}
retval = snd_compr_allocate_buffer(stream, params);
if (retval) {
retval = -ENOMEM;
goto out;
}
retval = stream->ops->set_params(stream, params);
if (retval)
goto out;
stream->runtime->state = SNDRV_PCM_STATE_SETUP;
} else {
return -EPERM;
}
out:
kfree(params);
return retval;
}
static int
snd_compr_get_params(struct snd_compr_stream *stream, unsigned long arg)
{
struct snd_codec *params;
int retval;
if (!stream->ops->get_params)
return -EBADFD;
params = kmalloc(sizeof(*params), GFP_KERNEL);
if (!params)
return -ENOMEM;
retval = stream->ops->get_params(stream, params);
if (retval)
goto out;
if (copy_to_user((char __user *)arg, params, sizeof(*params)))
retval = -EFAULT;
out:
kfree(params);
return retval;
}
static inline int
snd_compr_tstamp(struct snd_compr_stream *stream, unsigned long arg)
{
struct snd_compr_tstamp tstamp;
snd_compr_update_tstamp(stream, &tstamp);
return copy_to_user((struct snd_compr_tstamp __user *)arg,
&tstamp, sizeof(tstamp)) ? -EFAULT : 0;
}
static int snd_compr_pause(struct snd_compr_stream *stream)
{
int retval;
if (stream->runtime->state != SNDRV_PCM_STATE_RUNNING)
return -EPERM;
retval = stream->ops->trigger(stream, SNDRV_PCM_TRIGGER_PAUSE_PUSH);
if (!retval) {
stream->runtime->state = SNDRV_PCM_STATE_PAUSED;
wake_up(&stream->runtime->sleep);
}
return retval;
}
static int snd_compr_resume(struct snd_compr_stream *stream)
{
int retval;
if (stream->runtime->state != SNDRV_PCM_STATE_PAUSED)
return -EPERM;
retval = stream->ops->trigger(stream, SNDRV_PCM_TRIGGER_PAUSE_RELEASE);
if (!retval)
stream->runtime->state = SNDRV_PCM_STATE_RUNNING;
return retval;
}
static int snd_compr_start(struct snd_compr_stream *stream)
{
int retval;
if (stream->runtime->state != SNDRV_PCM_STATE_PREPARED)
return -EPERM;
retval = stream->ops->trigger(stream, SNDRV_PCM_TRIGGER_START);
if (!retval)
stream->runtime->state = SNDRV_PCM_STATE_RUNNING;
return retval;
}
static int snd_compr_stop(struct snd_compr_stream *stream)
{
int retval;
if (stream->runtime->state == SNDRV_PCM_STATE_PREPARED ||
stream->runtime->state == SNDRV_PCM_STATE_SETUP)
return -EPERM;
retval = stream->ops->trigger(stream, SNDRV_PCM_TRIGGER_STOP);
if (!retval) {
stream->runtime->state = SNDRV_PCM_STATE_SETUP;
wake_up(&stream->runtime->sleep);
}
return retval;
}
static int snd_compr_drain(struct snd_compr_stream *stream)
{
int retval;
if (stream->runtime->state == SNDRV_PCM_STATE_PREPARED ||
stream->runtime->state == SNDRV_PCM_STATE_SETUP)
return -EPERM;
retval = stream->ops->trigger(stream, SND_COMPR_TRIGGER_DRAIN);
if (!retval) {
stream->runtime->state = SNDRV_PCM_STATE_DRAINING;
wake_up(&stream->runtime->sleep);
}
return retval;
}
static long snd_compr_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
{
struct snd_compr_file *data = f->private_data;
struct snd_compr_stream *stream;
int retval = -ENOTTY;
if (snd_BUG_ON(!data))
return -EFAULT;
stream = &data->stream;
if (snd_BUG_ON(!stream))
return -EFAULT;
mutex_lock(&stream->device->lock);
switch (_IOC_NR(cmd)) {
case _IOC_NR(SNDRV_COMPRESS_IOCTL_VERSION):
put_user(SNDRV_COMPRESS_VERSION,
(int __user *)arg) ? -EFAULT : 0;
break;
case _IOC_NR(SNDRV_COMPRESS_GET_CAPS):
retval = snd_compr_get_caps(stream, arg);
break;
case _IOC_NR(SNDRV_COMPRESS_GET_CODEC_CAPS):
retval = snd_compr_get_codec_caps(stream, arg);
break;
case _IOC_NR(SNDRV_COMPRESS_SET_PARAMS):
retval = snd_compr_set_params(stream, arg);
break;
case _IOC_NR(SNDRV_COMPRESS_GET_PARAMS):
retval = snd_compr_get_params(stream, arg);
break;
case _IOC_NR(SNDRV_COMPRESS_TSTAMP):
retval = snd_compr_tstamp(stream, arg);
break;
case _IOC_NR(SNDRV_COMPRESS_AVAIL):
retval = snd_compr_ioctl_avail(stream, arg);
break;
case _IOC_NR(SNDRV_COMPRESS_PAUSE):
retval = snd_compr_pause(stream);
break;
case _IOC_NR(SNDRV_COMPRESS_RESUME):
retval = snd_compr_resume(stream);
break;
case _IOC_NR(SNDRV_COMPRESS_START):
retval = snd_compr_start(stream);
break;
case _IOC_NR(SNDRV_COMPRESS_STOP):
retval = snd_compr_stop(stream);
break;
case _IOC_NR(SNDRV_COMPRESS_DRAIN):
retval = snd_compr_drain(stream);
break;
}
mutex_unlock(&stream->device->lock);
return retval;
}
static int snd_compress_dev_register(struct snd_device *device)
{
int ret = -EINVAL;
char str[16];
struct snd_compr *compr;
if (snd_BUG_ON(!device || !device->device_data))
return -EBADFD;
compr = device->device_data;
sprintf(str, "comprC%iD%i", compr->card->number, compr->device);
pr_debug("reg %s for device %s, direction %d\n", str, compr->name,
compr->direction);
ret = snd_register_device(SNDRV_DEVICE_TYPE_COMPRESS, compr->card,
compr->device, &snd_compr_file_ops, compr, str);
if (ret < 0) {
pr_err("snd_register_device failed\n %d", ret);
return ret;
}
return ret;
}
static int snd_compress_dev_disconnect(struct snd_device *device)
{
struct snd_compr *compr;
compr = device->device_data;
snd_unregister_device(compr->direction, compr->card, compr->device);
return 0;
}
int snd_compress_new(struct snd_card *card, int device,
int dirn, struct snd_compr *compr)
{
static struct snd_device_ops ops = {
.dev_free = NULL,
.dev_register = snd_compress_dev_register,
.dev_disconnect = snd_compress_dev_disconnect,
};
compr->card = card;
compr->device = device;
compr->direction = dirn;
return snd_device_new(card, SNDRV_DEV_COMPRESS, compr, &ops);
}
static int snd_compress_add_device(struct snd_compr *device)
{
int ret;
if (!device->card)
return -EINVAL;
ret = snd_card_register(device->card);
if (ret)
goto out;
return 0;
out:
pr_err("failed with %d\n", ret);
return ret;
}
static int snd_compress_remove_device(struct snd_compr *device)
{
return snd_card_free(device->card);
}
int snd_compress_register(struct snd_compr *device)
{
int retval;
if (device->name == NULL || device->dev == NULL || device->ops == NULL)
return -EINVAL;
pr_debug("Registering compressed device %s\n", device->name);
if (snd_BUG_ON(!device->ops->open))
return -EINVAL;
if (snd_BUG_ON(!device->ops->free))
return -EINVAL;
if (snd_BUG_ON(!device->ops->set_params))
return -EINVAL;
if (snd_BUG_ON(!device->ops->trigger))
return -EINVAL;
mutex_init(&device->lock);
mutex_lock(&device_mutex);
retval = snd_compress_add_device(device);
mutex_unlock(&device_mutex);
return retval;
}
int snd_compress_deregister(struct snd_compr *device)
{
pr_debug("Removing compressed device %s\n", device->name);
mutex_lock(&device_mutex);
snd_compress_remove_device(device);
mutex_unlock(&device_mutex);
return 0;
}
static int __init snd_compress_init(void)
{
return 0;
}
static void __exit snd_compress_exit(void)
{
}
