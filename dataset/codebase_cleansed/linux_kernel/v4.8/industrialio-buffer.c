static bool iio_buffer_is_active(struct iio_buffer *buf)
{
return !list_empty(&buf->buffer_list);
}
static size_t iio_buffer_data_available(struct iio_buffer *buf)
{
return buf->access->data_available(buf);
}
static int iio_buffer_flush_hwfifo(struct iio_dev *indio_dev,
struct iio_buffer *buf, size_t required)
{
if (!indio_dev->info->hwfifo_flush_to_buffer)
return -ENODEV;
return indio_dev->info->hwfifo_flush_to_buffer(indio_dev, required);
}
static bool iio_buffer_ready(struct iio_dev *indio_dev, struct iio_buffer *buf,
size_t to_wait, int to_flush)
{
size_t avail;
int flushed = 0;
if (!indio_dev->info)
return true;
if (!iio_buffer_is_active(buf)) {
to_wait = min_t(size_t, to_wait, 1);
to_flush = 0;
}
avail = iio_buffer_data_available(buf);
if (avail >= to_wait) {
if (!to_wait && avail < to_flush)
iio_buffer_flush_hwfifo(indio_dev, buf,
to_flush - avail);
return true;
}
if (to_flush)
flushed = iio_buffer_flush_hwfifo(indio_dev, buf,
to_wait - avail);
if (flushed <= 0)
return false;
if (avail + flushed >= to_wait)
return true;
return false;
}
ssize_t iio_buffer_read_first_n_outer(struct file *filp, char __user *buf,
size_t n, loff_t *f_ps)
{
struct iio_dev *indio_dev = filp->private_data;
struct iio_buffer *rb = indio_dev->buffer;
DEFINE_WAIT_FUNC(wait, woken_wake_function);
size_t datum_size;
size_t to_wait;
int ret = 0;
if (!indio_dev->info)
return -ENODEV;
if (!rb || !rb->access->read_first_n)
return -EINVAL;
datum_size = rb->bytes_per_datum;
if (!datum_size)
return 0;
if (filp->f_flags & O_NONBLOCK)
to_wait = 0;
else
to_wait = min_t(size_t, n / datum_size, rb->watermark);
add_wait_queue(&rb->pollq, &wait);
do {
if (!indio_dev->info) {
ret = -ENODEV;
break;
}
if (!iio_buffer_ready(indio_dev, rb, to_wait, n / datum_size)) {
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
wait_woken(&wait, TASK_INTERRUPTIBLE,
MAX_SCHEDULE_TIMEOUT);
continue;
}
ret = rb->access->read_first_n(rb, n, buf);
if (ret == 0 && (filp->f_flags & O_NONBLOCK))
ret = -EAGAIN;
} while (ret == 0);
remove_wait_queue(&rb->pollq, &wait);
return ret;
}
unsigned int iio_buffer_poll(struct file *filp,
struct poll_table_struct *wait)
{
struct iio_dev *indio_dev = filp->private_data;
struct iio_buffer *rb = indio_dev->buffer;
if (!indio_dev->info)
return 0;
poll_wait(filp, &rb->pollq, wait);
if (iio_buffer_ready(indio_dev, rb, rb->watermark, 0))
return POLLIN | POLLRDNORM;
return 0;
}
void iio_buffer_wakeup_poll(struct iio_dev *indio_dev)
{
if (!indio_dev->buffer)
return;
wake_up(&indio_dev->buffer->pollq);
}
void iio_buffer_init(struct iio_buffer *buffer)
{
INIT_LIST_HEAD(&buffer->demux_list);
INIT_LIST_HEAD(&buffer->buffer_list);
init_waitqueue_head(&buffer->pollq);
kref_init(&buffer->ref);
if (!buffer->watermark)
buffer->watermark = 1;
}
static ssize_t iio_show_scan_index(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", to_iio_dev_attr(attr)->c->scan_index);
}
static ssize_t iio_show_fixed_type(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
u8 type = this_attr->c->scan_type.endianness;
if (type == IIO_CPU) {
#ifdef __LITTLE_ENDIAN
type = IIO_LE;
#else
type = IIO_BE;
#endif
}
if (this_attr->c->scan_type.repeat > 1)
return sprintf(buf, "%s:%c%d/%dX%d>>%u\n",
iio_endian_prefix[type],
this_attr->c->scan_type.sign,
this_attr->c->scan_type.realbits,
this_attr->c->scan_type.storagebits,
this_attr->c->scan_type.repeat,
this_attr->c->scan_type.shift);
else
return sprintf(buf, "%s:%c%d/%d>>%u\n",
iio_endian_prefix[type],
this_attr->c->scan_type.sign,
this_attr->c->scan_type.realbits,
this_attr->c->scan_type.storagebits,
this_attr->c->scan_type.shift);
}
static ssize_t iio_scan_el_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
ret = !!test_bit(to_iio_dev_attr(attr)->address,
indio_dev->buffer->scan_mask);
return sprintf(buf, "%d\n", ret);
}
static const unsigned long *iio_scan_mask_match(const unsigned long *av_masks,
unsigned int masklength,
const unsigned long *mask,
bool strict)
{
if (bitmap_empty(mask, masklength))
return NULL;
while (*av_masks) {
if (strict) {
if (bitmap_equal(mask, av_masks, masklength))
return av_masks;
} else {
if (bitmap_subset(mask, av_masks, masklength))
return av_masks;
}
av_masks += BITS_TO_LONGS(masklength);
}
return NULL;
}
static bool iio_validate_scan_mask(struct iio_dev *indio_dev,
const unsigned long *mask)
{
if (!indio_dev->setup_ops->validate_scan_mask)
return true;
return indio_dev->setup_ops->validate_scan_mask(indio_dev, mask);
}
static int iio_scan_mask_set(struct iio_dev *indio_dev,
struct iio_buffer *buffer, int bit)
{
const unsigned long *mask;
unsigned long *trialmask;
trialmask = kmalloc(sizeof(*trialmask)*
BITS_TO_LONGS(indio_dev->masklength),
GFP_KERNEL);
if (trialmask == NULL)
return -ENOMEM;
if (!indio_dev->masklength) {
WARN(1, "Trying to set scanmask prior to registering buffer\n");
goto err_invalid_mask;
}
bitmap_copy(trialmask, buffer->scan_mask, indio_dev->masklength);
set_bit(bit, trialmask);
if (!iio_validate_scan_mask(indio_dev, trialmask))
goto err_invalid_mask;
if (indio_dev->available_scan_masks) {
mask = iio_scan_mask_match(indio_dev->available_scan_masks,
indio_dev->masklength,
trialmask, false);
if (!mask)
goto err_invalid_mask;
}
bitmap_copy(buffer->scan_mask, trialmask, indio_dev->masklength);
kfree(trialmask);
return 0;
err_invalid_mask:
kfree(trialmask);
return -EINVAL;
}
static int iio_scan_mask_clear(struct iio_buffer *buffer, int bit)
{
clear_bit(bit, buffer->scan_mask);
return 0;
}
static ssize_t iio_scan_el_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
int ret;
bool state;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_buffer *buffer = indio_dev->buffer;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = strtobool(buf, &state);
if (ret < 0)
return ret;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_is_active(indio_dev->buffer)) {
ret = -EBUSY;
goto error_ret;
}
ret = iio_scan_mask_query(indio_dev, buffer, this_attr->address);
if (ret < 0)
goto error_ret;
if (!state && ret) {
ret = iio_scan_mask_clear(buffer, this_attr->address);
if (ret)
goto error_ret;
} else if (state && !ret) {
ret = iio_scan_mask_set(indio_dev, buffer, this_attr->address);
if (ret)
goto error_ret;
}
error_ret:
mutex_unlock(&indio_dev->mlock);
return ret < 0 ? ret : len;
}
static ssize_t iio_scan_el_ts_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
return sprintf(buf, "%d\n", indio_dev->buffer->scan_timestamp);
}
static ssize_t iio_scan_el_ts_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
int ret;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
bool state;
ret = strtobool(buf, &state);
if (ret < 0)
return ret;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_is_active(indio_dev->buffer)) {
ret = -EBUSY;
goto error_ret;
}
indio_dev->buffer->scan_timestamp = state;
error_ret:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int iio_buffer_add_channel_sysfs(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
int ret, attrcount = 0;
struct iio_buffer *buffer = indio_dev->buffer;
ret = __iio_add_chan_devattr("index",
chan,
&iio_show_scan_index,
NULL,
0,
IIO_SEPARATE,
&indio_dev->dev,
&buffer->scan_el_dev_attr_list);
if (ret)
return ret;
attrcount++;
ret = __iio_add_chan_devattr("type",
chan,
&iio_show_fixed_type,
NULL,
0,
0,
&indio_dev->dev,
&buffer->scan_el_dev_attr_list);
if (ret)
return ret;
attrcount++;
if (chan->type != IIO_TIMESTAMP)
ret = __iio_add_chan_devattr("en",
chan,
&iio_scan_el_show,
&iio_scan_el_store,
chan->scan_index,
0,
&indio_dev->dev,
&buffer->scan_el_dev_attr_list);
else
ret = __iio_add_chan_devattr("en",
chan,
&iio_scan_el_ts_show,
&iio_scan_el_ts_store,
chan->scan_index,
0,
&indio_dev->dev,
&buffer->scan_el_dev_attr_list);
if (ret)
return ret;
attrcount++;
ret = attrcount;
return ret;
}
static ssize_t iio_buffer_read_length(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_buffer *buffer = indio_dev->buffer;
return sprintf(buf, "%d\n", buffer->length);
}
static ssize_t iio_buffer_write_length(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_buffer *buffer = indio_dev->buffer;
unsigned int val;
int ret;
ret = kstrtouint(buf, 10, &val);
if (ret)
return ret;
if (val == buffer->length)
return len;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_is_active(indio_dev->buffer)) {
ret = -EBUSY;
} else {
buffer->access->set_length(buffer, val);
ret = 0;
}
if (ret)
goto out;
if (buffer->length && buffer->length < buffer->watermark)
buffer->watermark = buffer->length;
out:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static ssize_t iio_buffer_show_enable(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
return sprintf(buf, "%d\n", iio_buffer_is_active(indio_dev->buffer));
}
static unsigned int iio_storage_bytes_for_si(struct iio_dev *indio_dev,
unsigned int scan_index)
{
const struct iio_chan_spec *ch;
unsigned int bytes;
ch = iio_find_channel_from_si(indio_dev, scan_index);
bytes = ch->scan_type.storagebits / 8;
if (ch->scan_type.repeat > 1)
bytes *= ch->scan_type.repeat;
return bytes;
}
static unsigned int iio_storage_bytes_for_timestamp(struct iio_dev *indio_dev)
{
return iio_storage_bytes_for_si(indio_dev,
indio_dev->scan_index_timestamp);
}
static int iio_compute_scan_bytes(struct iio_dev *indio_dev,
const unsigned long *mask, bool timestamp)
{
unsigned bytes = 0;
int length, i;
for_each_set_bit(i, mask,
indio_dev->masklength) {
length = iio_storage_bytes_for_si(indio_dev, i);
bytes = ALIGN(bytes, length);
bytes += length;
}
if (timestamp) {
length = iio_storage_bytes_for_timestamp(indio_dev);
bytes = ALIGN(bytes, length);
bytes += length;
}
return bytes;
}
static void iio_buffer_activate(struct iio_dev *indio_dev,
struct iio_buffer *buffer)
{
iio_buffer_get(buffer);
list_add(&buffer->buffer_list, &indio_dev->buffer_list);
}
static void iio_buffer_deactivate(struct iio_buffer *buffer)
{
list_del_init(&buffer->buffer_list);
wake_up_interruptible(&buffer->pollq);
iio_buffer_put(buffer);
}
static void iio_buffer_deactivate_all(struct iio_dev *indio_dev)
{
struct iio_buffer *buffer, *_buffer;
list_for_each_entry_safe(buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
iio_buffer_deactivate(buffer);
}
static int iio_buffer_enable(struct iio_buffer *buffer,
struct iio_dev *indio_dev)
{
if (!buffer->access->enable)
return 0;
return buffer->access->enable(buffer, indio_dev);
}
static int iio_buffer_disable(struct iio_buffer *buffer,
struct iio_dev *indio_dev)
{
if (!buffer->access->disable)
return 0;
return buffer->access->disable(buffer, indio_dev);
}
static void iio_buffer_update_bytes_per_datum(struct iio_dev *indio_dev,
struct iio_buffer *buffer)
{
unsigned int bytes;
if (!buffer->access->set_bytes_per_datum)
return;
bytes = iio_compute_scan_bytes(indio_dev, buffer->scan_mask,
buffer->scan_timestamp);
buffer->access->set_bytes_per_datum(buffer, bytes);
}
static int iio_buffer_request_update(struct iio_dev *indio_dev,
struct iio_buffer *buffer)
{
int ret;
iio_buffer_update_bytes_per_datum(indio_dev, buffer);
if (buffer->access->request_update) {
ret = buffer->access->request_update(buffer);
if (ret) {
dev_dbg(&indio_dev->dev,
"Buffer not started: buffer parameter update failed (%d)\n",
ret);
return ret;
}
}
return 0;
}
static void iio_free_scan_mask(struct iio_dev *indio_dev,
const unsigned long *mask)
{
if (!indio_dev->available_scan_masks)
kfree(mask);
}
static int iio_verify_update(struct iio_dev *indio_dev,
struct iio_buffer *insert_buffer, struct iio_buffer *remove_buffer,
struct iio_device_config *config)
{
unsigned long *compound_mask;
const unsigned long *scan_mask;
bool strict_scanmask = false;
struct iio_buffer *buffer;
bool scan_timestamp;
unsigned int modes;
memset(config, 0, sizeof(*config));
config->watermark = ~0;
if (remove_buffer && !insert_buffer &&
list_is_singular(&indio_dev->buffer_list))
return 0;
modes = indio_dev->modes;
list_for_each_entry(buffer, &indio_dev->buffer_list, buffer_list) {
if (buffer == remove_buffer)
continue;
modes &= buffer->access->modes;
config->watermark = min(config->watermark, buffer->watermark);
}
if (insert_buffer) {
modes &= insert_buffer->access->modes;
config->watermark = min(config->watermark,
insert_buffer->watermark);
}
if ((modes & INDIO_BUFFER_TRIGGERED) && indio_dev->trig) {
config->mode = INDIO_BUFFER_TRIGGERED;
} else if (modes & INDIO_BUFFER_HARDWARE) {
if (insert_buffer && !list_empty(&indio_dev->buffer_list))
return -EINVAL;
config->mode = INDIO_BUFFER_HARDWARE;
strict_scanmask = true;
} else if (modes & INDIO_BUFFER_SOFTWARE) {
config->mode = INDIO_BUFFER_SOFTWARE;
} else {
if (indio_dev->modes & INDIO_BUFFER_TRIGGERED)
dev_dbg(&indio_dev->dev, "Buffer not started: no trigger\n");
return -EINVAL;
}
compound_mask = kcalloc(BITS_TO_LONGS(indio_dev->masklength),
sizeof(long), GFP_KERNEL);
if (compound_mask == NULL)
return -ENOMEM;
scan_timestamp = false;
list_for_each_entry(buffer, &indio_dev->buffer_list, buffer_list) {
if (buffer == remove_buffer)
continue;
bitmap_or(compound_mask, compound_mask, buffer->scan_mask,
indio_dev->masklength);
scan_timestamp |= buffer->scan_timestamp;
}
if (insert_buffer) {
bitmap_or(compound_mask, compound_mask,
insert_buffer->scan_mask, indio_dev->masklength);
scan_timestamp |= insert_buffer->scan_timestamp;
}
if (indio_dev->available_scan_masks) {
scan_mask = iio_scan_mask_match(indio_dev->available_scan_masks,
indio_dev->masklength,
compound_mask,
strict_scanmask);
kfree(compound_mask);
if (scan_mask == NULL)
return -EINVAL;
} else {
scan_mask = compound_mask;
}
config->scan_bytes = iio_compute_scan_bytes(indio_dev,
scan_mask, scan_timestamp);
config->scan_mask = scan_mask;
config->scan_timestamp = scan_timestamp;
return 0;
}
static int iio_enable_buffers(struct iio_dev *indio_dev,
struct iio_device_config *config)
{
struct iio_buffer *buffer;
int ret;
indio_dev->active_scan_mask = config->scan_mask;
indio_dev->scan_timestamp = config->scan_timestamp;
indio_dev->scan_bytes = config->scan_bytes;
iio_update_demux(indio_dev);
if (indio_dev->setup_ops->preenable) {
ret = indio_dev->setup_ops->preenable(indio_dev);
if (ret) {
dev_dbg(&indio_dev->dev,
"Buffer not started: buffer preenable failed (%d)\n", ret);
goto err_undo_config;
}
}
if (indio_dev->info->update_scan_mode) {
ret = indio_dev->info
->update_scan_mode(indio_dev,
indio_dev->active_scan_mask);
if (ret < 0) {
dev_dbg(&indio_dev->dev,
"Buffer not started: update scan mode failed (%d)\n",
ret);
goto err_run_postdisable;
}
}
if (indio_dev->info->hwfifo_set_watermark)
indio_dev->info->hwfifo_set_watermark(indio_dev,
config->watermark);
list_for_each_entry(buffer, &indio_dev->buffer_list, buffer_list) {
ret = iio_buffer_enable(buffer, indio_dev);
if (ret)
goto err_disable_buffers;
}
indio_dev->currentmode = config->mode;
if (indio_dev->setup_ops->postenable) {
ret = indio_dev->setup_ops->postenable(indio_dev);
if (ret) {
dev_dbg(&indio_dev->dev,
"Buffer not started: postenable failed (%d)\n", ret);
goto err_disable_buffers;
}
}
return 0;
err_disable_buffers:
list_for_each_entry_continue_reverse(buffer, &indio_dev->buffer_list,
buffer_list)
iio_buffer_disable(buffer, indio_dev);
err_run_postdisable:
indio_dev->currentmode = INDIO_DIRECT_MODE;
if (indio_dev->setup_ops->postdisable)
indio_dev->setup_ops->postdisable(indio_dev);
err_undo_config:
indio_dev->active_scan_mask = NULL;
return ret;
}
static int iio_disable_buffers(struct iio_dev *indio_dev)
{
struct iio_buffer *buffer;
int ret = 0;
int ret2;
if (list_empty(&indio_dev->buffer_list))
return 0;
if (indio_dev->setup_ops->predisable) {
ret2 = indio_dev->setup_ops->predisable(indio_dev);
if (ret2 && !ret)
ret = ret2;
}
list_for_each_entry(buffer, &indio_dev->buffer_list, buffer_list) {
ret2 = iio_buffer_disable(buffer, indio_dev);
if (ret2 && !ret)
ret = ret2;
}
indio_dev->currentmode = INDIO_DIRECT_MODE;
if (indio_dev->setup_ops->postdisable) {
ret2 = indio_dev->setup_ops->postdisable(indio_dev);
if (ret2 && !ret)
ret = ret2;
}
iio_free_scan_mask(indio_dev, indio_dev->active_scan_mask);
indio_dev->active_scan_mask = NULL;
return ret;
}
static int __iio_update_buffers(struct iio_dev *indio_dev,
struct iio_buffer *insert_buffer,
struct iio_buffer *remove_buffer)
{
struct iio_device_config new_config;
int ret;
ret = iio_verify_update(indio_dev, insert_buffer, remove_buffer,
&new_config);
if (ret)
return ret;
if (insert_buffer) {
ret = iio_buffer_request_update(indio_dev, insert_buffer);
if (ret)
goto err_free_config;
}
ret = iio_disable_buffers(indio_dev);
if (ret)
goto err_deactivate_all;
if (remove_buffer)
iio_buffer_deactivate(remove_buffer);
if (insert_buffer)
iio_buffer_activate(indio_dev, insert_buffer);
if (list_empty(&indio_dev->buffer_list))
return 0;
ret = iio_enable_buffers(indio_dev, &new_config);
if (ret)
goto err_deactivate_all;
return 0;
err_deactivate_all:
iio_buffer_deactivate_all(indio_dev);
err_free_config:
iio_free_scan_mask(indio_dev, new_config.scan_mask);
return ret;
}
int iio_update_buffers(struct iio_dev *indio_dev,
struct iio_buffer *insert_buffer,
struct iio_buffer *remove_buffer)
{
int ret;
if (insert_buffer == remove_buffer)
return 0;
mutex_lock(&indio_dev->info_exist_lock);
mutex_lock(&indio_dev->mlock);
if (insert_buffer && iio_buffer_is_active(insert_buffer))
insert_buffer = NULL;
if (remove_buffer && !iio_buffer_is_active(remove_buffer))
remove_buffer = NULL;
if (!insert_buffer && !remove_buffer) {
ret = 0;
goto out_unlock;
}
if (indio_dev->info == NULL) {
ret = -ENODEV;
goto out_unlock;
}
ret = __iio_update_buffers(indio_dev, insert_buffer, remove_buffer);
out_unlock:
mutex_unlock(&indio_dev->mlock);
mutex_unlock(&indio_dev->info_exist_lock);
return ret;
}
void iio_disable_all_buffers(struct iio_dev *indio_dev)
{
iio_disable_buffers(indio_dev);
iio_buffer_deactivate_all(indio_dev);
}
static ssize_t iio_buffer_store_enable(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
int ret;
bool requested_state;
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
bool inlist;
ret = strtobool(buf, &requested_state);
if (ret < 0)
return ret;
mutex_lock(&indio_dev->mlock);
inlist = iio_buffer_is_active(indio_dev->buffer);
if (inlist == requested_state)
goto done;
if (requested_state)
ret = __iio_update_buffers(indio_dev,
indio_dev->buffer, NULL);
else
ret = __iio_update_buffers(indio_dev,
NULL, indio_dev->buffer);
done:
mutex_unlock(&indio_dev->mlock);
return (ret < 0) ? ret : len;
}
static ssize_t iio_buffer_show_watermark(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_buffer *buffer = indio_dev->buffer;
return sprintf(buf, "%u\n", buffer->watermark);
}
static ssize_t iio_buffer_store_watermark(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_buffer *buffer = indio_dev->buffer;
unsigned int val;
int ret;
ret = kstrtouint(buf, 10, &val);
if (ret)
return ret;
if (!val)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
if (val > buffer->length) {
ret = -EINVAL;
goto out;
}
if (iio_buffer_is_active(indio_dev->buffer)) {
ret = -EBUSY;
goto out;
}
buffer->watermark = val;
out:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
int iio_buffer_alloc_sysfs_and_mask(struct iio_dev *indio_dev)
{
struct iio_dev_attr *p;
struct attribute **attr;
struct iio_buffer *buffer = indio_dev->buffer;
int ret, i, attrn, attrcount, attrcount_orig = 0;
const struct iio_chan_spec *channels;
channels = indio_dev->channels;
if (channels) {
int ml = indio_dev->masklength;
for (i = 0; i < indio_dev->num_channels; i++)
ml = max(ml, channels[i].scan_index + 1);
indio_dev->masklength = ml;
}
if (!buffer)
return 0;
attrcount = 0;
if (buffer->attrs) {
while (buffer->attrs[attrcount] != NULL)
attrcount++;
}
attr = kcalloc(attrcount + ARRAY_SIZE(iio_buffer_attrs) + 1,
sizeof(struct attribute *), GFP_KERNEL);
if (!attr)
return -ENOMEM;
memcpy(attr, iio_buffer_attrs, sizeof(iio_buffer_attrs));
if (!buffer->access->set_length)
attr[0] = &dev_attr_length_ro.attr;
if (buffer->access->flags & INDIO_BUFFER_FLAG_FIXED_WATERMARK)
attr[2] = &dev_attr_watermark_ro.attr;
if (buffer->attrs)
memcpy(&attr[ARRAY_SIZE(iio_buffer_attrs)], buffer->attrs,
sizeof(struct attribute *) * attrcount);
attr[attrcount + ARRAY_SIZE(iio_buffer_attrs)] = NULL;
buffer->buffer_group.name = "buffer";
buffer->buffer_group.attrs = attr;
indio_dev->groups[indio_dev->groupcounter++] = &buffer->buffer_group;
if (buffer->scan_el_attrs != NULL) {
attr = buffer->scan_el_attrs->attrs;
while (*attr++ != NULL)
attrcount_orig++;
}
attrcount = attrcount_orig;
INIT_LIST_HEAD(&buffer->scan_el_dev_attr_list);
channels = indio_dev->channels;
if (channels) {
for (i = 0; i < indio_dev->num_channels; i++) {
if (channels[i].scan_index < 0)
continue;
ret = iio_buffer_add_channel_sysfs(indio_dev,
&channels[i]);
if (ret < 0)
goto error_cleanup_dynamic;
attrcount += ret;
if (channels[i].type == IIO_TIMESTAMP)
indio_dev->scan_index_timestamp =
channels[i].scan_index;
}
if (indio_dev->masklength && buffer->scan_mask == NULL) {
buffer->scan_mask = kcalloc(BITS_TO_LONGS(indio_dev->masklength),
sizeof(*buffer->scan_mask),
GFP_KERNEL);
if (buffer->scan_mask == NULL) {
ret = -ENOMEM;
goto error_cleanup_dynamic;
}
}
}
buffer->scan_el_group.name = iio_scan_elements_group_name;
buffer->scan_el_group.attrs = kcalloc(attrcount + 1,
sizeof(buffer->scan_el_group.attrs[0]),
GFP_KERNEL);
if (buffer->scan_el_group.attrs == NULL) {
ret = -ENOMEM;
goto error_free_scan_mask;
}
if (buffer->scan_el_attrs)
memcpy(buffer->scan_el_group.attrs, buffer->scan_el_attrs,
sizeof(buffer->scan_el_group.attrs[0])*attrcount_orig);
attrn = attrcount_orig;
list_for_each_entry(p, &buffer->scan_el_dev_attr_list, l)
buffer->scan_el_group.attrs[attrn++] = &p->dev_attr.attr;
indio_dev->groups[indio_dev->groupcounter++] = &buffer->scan_el_group;
return 0;
error_free_scan_mask:
kfree(buffer->scan_mask);
error_cleanup_dynamic:
iio_free_chan_devattr_list(&buffer->scan_el_dev_attr_list);
kfree(indio_dev->buffer->buffer_group.attrs);
return ret;
}
void iio_buffer_free_sysfs_and_mask(struct iio_dev *indio_dev)
{
if (!indio_dev->buffer)
return;
kfree(indio_dev->buffer->scan_mask);
kfree(indio_dev->buffer->buffer_group.attrs);
kfree(indio_dev->buffer->scan_el_group.attrs);
iio_free_chan_devattr_list(&indio_dev->buffer->scan_el_dev_attr_list);
}
bool iio_validate_scan_mask_onehot(struct iio_dev *indio_dev,
const unsigned long *mask)
{
return bitmap_weight(mask, indio_dev->masklength) == 1;
}
int iio_scan_mask_query(struct iio_dev *indio_dev,
struct iio_buffer *buffer, int bit)
{
if (bit > indio_dev->masklength)
return -EINVAL;
if (!buffer->scan_mask)
return 0;
return !!test_bit(bit, buffer->scan_mask);
}
static const void *iio_demux(struct iio_buffer *buffer,
const void *datain)
{
struct iio_demux_table *t;
if (list_empty(&buffer->demux_list))
return datain;
list_for_each_entry(t, &buffer->demux_list, l)
memcpy(buffer->demux_bounce + t->to,
datain + t->from, t->length);
return buffer->demux_bounce;
}
static int iio_push_to_buffer(struct iio_buffer *buffer, const void *data)
{
const void *dataout = iio_demux(buffer, data);
int ret;
ret = buffer->access->store_to(buffer, dataout);
if (ret)
return ret;
wake_up_interruptible_poll(&buffer->pollq, POLLIN | POLLRDNORM);
return 0;
}
static void iio_buffer_demux_free(struct iio_buffer *buffer)
{
struct iio_demux_table *p, *q;
list_for_each_entry_safe(p, q, &buffer->demux_list, l) {
list_del(&p->l);
kfree(p);
}
}
int iio_push_to_buffers(struct iio_dev *indio_dev, const void *data)
{
int ret;
struct iio_buffer *buf;
list_for_each_entry(buf, &indio_dev->buffer_list, buffer_list) {
ret = iio_push_to_buffer(buf, data);
if (ret < 0)
return ret;
}
return 0;
}
static int iio_buffer_add_demux(struct iio_buffer *buffer,
struct iio_demux_table **p, unsigned int in_loc, unsigned int out_loc,
unsigned int length)
{
if (*p && (*p)->from + (*p)->length == in_loc &&
(*p)->to + (*p)->length == out_loc) {
(*p)->length += length;
} else {
*p = kmalloc(sizeof(**p), GFP_KERNEL);
if (*p == NULL)
return -ENOMEM;
(*p)->from = in_loc;
(*p)->to = out_loc;
(*p)->length = length;
list_add_tail(&(*p)->l, &buffer->demux_list);
}
return 0;
}
static int iio_buffer_update_demux(struct iio_dev *indio_dev,
struct iio_buffer *buffer)
{
int ret, in_ind = -1, out_ind, length;
unsigned in_loc = 0, out_loc = 0;
struct iio_demux_table *p = NULL;
iio_buffer_demux_free(buffer);
kfree(buffer->demux_bounce);
buffer->demux_bounce = NULL;
if (bitmap_equal(indio_dev->active_scan_mask,
buffer->scan_mask,
indio_dev->masklength))
return 0;
for_each_set_bit(out_ind,
buffer->scan_mask,
indio_dev->masklength) {
in_ind = find_next_bit(indio_dev->active_scan_mask,
indio_dev->masklength,
in_ind + 1);
while (in_ind != out_ind) {
in_ind = find_next_bit(indio_dev->active_scan_mask,
indio_dev->masklength,
in_ind + 1);
length = iio_storage_bytes_for_si(indio_dev, in_ind);
in_loc = roundup(in_loc, length) + length;
}
length = iio_storage_bytes_for_si(indio_dev, in_ind);
out_loc = roundup(out_loc, length);
in_loc = roundup(in_loc, length);
ret = iio_buffer_add_demux(buffer, &p, in_loc, out_loc, length);
if (ret)
goto error_clear_mux_table;
out_loc += length;
in_loc += length;
}
if (buffer->scan_timestamp) {
length = iio_storage_bytes_for_timestamp(indio_dev);
out_loc = roundup(out_loc, length);
in_loc = roundup(in_loc, length);
ret = iio_buffer_add_demux(buffer, &p, in_loc, out_loc, length);
if (ret)
goto error_clear_mux_table;
out_loc += length;
in_loc += length;
}
buffer->demux_bounce = kzalloc(out_loc, GFP_KERNEL);
if (buffer->demux_bounce == NULL) {
ret = -ENOMEM;
goto error_clear_mux_table;
}
return 0;
error_clear_mux_table:
iio_buffer_demux_free(buffer);
return ret;
}
int iio_update_demux(struct iio_dev *indio_dev)
{
struct iio_buffer *buffer;
int ret;
list_for_each_entry(buffer, &indio_dev->buffer_list, buffer_list) {
ret = iio_buffer_update_demux(indio_dev, buffer);
if (ret < 0)
goto error_clear_mux_table;
}
return 0;
error_clear_mux_table:
list_for_each_entry(buffer, &indio_dev->buffer_list, buffer_list)
iio_buffer_demux_free(buffer);
return ret;
}
static void iio_buffer_release(struct kref *ref)
{
struct iio_buffer *buffer = container_of(ref, struct iio_buffer, ref);
buffer->access->release(buffer);
}
struct iio_buffer *iio_buffer_get(struct iio_buffer *buffer)
{
if (buffer)
kref_get(&buffer->ref);
return buffer;
}
void iio_buffer_put(struct iio_buffer *buffer)
{
if (buffer)
kref_put(&buffer->ref, iio_buffer_release);
}
