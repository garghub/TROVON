static bool iio_buffer_is_active(struct iio_buffer *buf)
{
return !list_empty(&buf->buffer_list);
}
static bool iio_buffer_data_available(struct iio_buffer *buf)
{
if (buf->access->data_available)
return buf->access->data_available(buf);
return buf->stufftoread;
}
ssize_t iio_buffer_read_first_n_outer(struct file *filp, char __user *buf,
size_t n, loff_t *f_ps)
{
struct iio_dev *indio_dev = filp->private_data;
struct iio_buffer *rb = indio_dev->buffer;
int ret;
if (!indio_dev->info)
return -ENODEV;
if (!rb || !rb->access->read_first_n)
return -EINVAL;
do {
if (!iio_buffer_data_available(rb)) {
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
ret = wait_event_interruptible(rb->pollq,
iio_buffer_data_available(rb) ||
indio_dev->info == NULL);
if (ret)
return ret;
if (indio_dev->info == NULL)
return -ENODEV;
}
ret = rb->access->read_first_n(rb, n, buf);
if (ret == 0 && (filp->f_flags & O_NONBLOCK))
ret = -EAGAIN;
} while (ret == 0);
return ret;
}
unsigned int iio_buffer_poll(struct file *filp,
struct poll_table_struct *wait)
{
struct iio_dev *indio_dev = filp->private_data;
struct iio_buffer *rb = indio_dev->buffer;
if (!indio_dev->info)
return -ENODEV;
poll_wait(filp, &rb->pollq, wait);
if (iio_buffer_data_available(rb))
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
int iio_buffer_register(struct iio_dev *indio_dev,
const struct iio_chan_spec *channels,
int num_channels)
{
struct iio_dev_attr *p;
struct attribute **attr;
struct iio_buffer *buffer = indio_dev->buffer;
int ret, i, attrn, attrcount, attrcount_orig = 0;
if (buffer->attrs)
indio_dev->groups[indio_dev->groupcounter++] = buffer->attrs;
if (buffer->scan_el_attrs != NULL) {
attr = buffer->scan_el_attrs->attrs;
while (*attr++ != NULL)
attrcount_orig++;
}
attrcount = attrcount_orig;
INIT_LIST_HEAD(&buffer->scan_el_dev_attr_list);
if (channels) {
for (i = 0; i < num_channels; i++) {
if (channels[i].scan_index < 0)
continue;
if (channels[i].scan_index >
(int)indio_dev->masklength - 1)
indio_dev->masklength
= channels[i].scan_index + 1;
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
return ret;
}
void iio_buffer_unregister(struct iio_dev *indio_dev)
{
kfree(indio_dev->buffer->scan_mask);
kfree(indio_dev->buffer->scan_el_group.attrs);
iio_free_chan_devattr_list(&indio_dev->buffer->scan_el_dev_attr_list);
}
ssize_t iio_buffer_read_length(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_buffer *buffer = indio_dev->buffer;
if (buffer->access->get_length)
return sprintf(buf, "%d\n",
buffer->access->get_length(buffer));
return 0;
}
ssize_t iio_buffer_write_length(struct device *dev,
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
if (buffer->access->get_length)
if (val == buffer->access->get_length(buffer))
return len;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_is_active(indio_dev->buffer)) {
ret = -EBUSY;
} else {
if (buffer->access->set_length)
buffer->access->set_length(buffer, val);
ret = 0;
}
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
ssize_t iio_buffer_show_enable(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
return sprintf(buf, "%d\n", iio_buffer_is_active(indio_dev->buffer));
}
static const unsigned long *iio_scan_mask_match(const unsigned long *av_masks,
unsigned int masklength,
const unsigned long *mask)
{
if (bitmap_empty(mask, masklength))
return NULL;
while (*av_masks) {
if (bitmap_subset(mask, av_masks, masklength))
return av_masks;
av_masks += BITS_TO_LONGS(masklength);
}
return NULL;
}
static int iio_compute_scan_bytes(struct iio_dev *indio_dev,
const unsigned long *mask, bool timestamp)
{
const struct iio_chan_spec *ch;
unsigned bytes = 0;
int length, i;
for_each_set_bit(i, mask,
indio_dev->masklength) {
ch = iio_find_channel_from_si(indio_dev, i);
if (ch->scan_type.repeat > 1)
length = ch->scan_type.storagebits / 8 *
ch->scan_type.repeat;
else
length = ch->scan_type.storagebits / 8;
bytes = ALIGN(bytes, length);
bytes += length;
}
if (timestamp) {
ch = iio_find_channel_from_si(indio_dev,
indio_dev->scan_index_timestamp);
if (ch->scan_type.repeat > 1)
length = ch->scan_type.storagebits / 8 *
ch->scan_type.repeat;
else
length = ch->scan_type.storagebits / 8;
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
iio_buffer_put(buffer);
}
void iio_disable_all_buffers(struct iio_dev *indio_dev)
{
struct iio_buffer *buffer, *_buffer;
if (list_empty(&indio_dev->buffer_list))
return;
if (indio_dev->setup_ops->predisable)
indio_dev->setup_ops->predisable(indio_dev);
list_for_each_entry_safe(buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
iio_buffer_deactivate(buffer);
indio_dev->currentmode = INDIO_DIRECT_MODE;
if (indio_dev->setup_ops->postdisable)
indio_dev->setup_ops->postdisable(indio_dev);
if (indio_dev->available_scan_masks == NULL)
kfree(indio_dev->active_scan_mask);
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
static int __iio_update_buffers(struct iio_dev *indio_dev,
struct iio_buffer *insert_buffer,
struct iio_buffer *remove_buffer)
{
int ret;
int success = 0;
struct iio_buffer *buffer;
unsigned long *compound_mask;
const unsigned long *old_mask;
if (!list_empty(&indio_dev->buffer_list)) {
if (indio_dev->setup_ops->predisable) {
ret = indio_dev->setup_ops->predisable(indio_dev);
if (ret)
return ret;
}
indio_dev->currentmode = INDIO_DIRECT_MODE;
if (indio_dev->setup_ops->postdisable) {
ret = indio_dev->setup_ops->postdisable(indio_dev);
if (ret)
return ret;
}
}
old_mask = indio_dev->active_scan_mask;
if (!indio_dev->available_scan_masks)
indio_dev->active_scan_mask = NULL;
if (remove_buffer)
iio_buffer_deactivate(remove_buffer);
if (insert_buffer)
iio_buffer_activate(indio_dev, insert_buffer);
if (list_empty(&indio_dev->buffer_list)) {
indio_dev->currentmode = INDIO_DIRECT_MODE;
if (indio_dev->available_scan_masks == NULL)
kfree(old_mask);
return 0;
}
compound_mask = kcalloc(BITS_TO_LONGS(indio_dev->masklength),
sizeof(long), GFP_KERNEL);
if (compound_mask == NULL) {
if (indio_dev->available_scan_masks == NULL)
kfree(old_mask);
return -ENOMEM;
}
indio_dev->scan_timestamp = 0;
list_for_each_entry(buffer, &indio_dev->buffer_list, buffer_list) {
bitmap_or(compound_mask, compound_mask, buffer->scan_mask,
indio_dev->masklength);
indio_dev->scan_timestamp |= buffer->scan_timestamp;
}
if (indio_dev->available_scan_masks) {
indio_dev->active_scan_mask =
iio_scan_mask_match(indio_dev->available_scan_masks,
indio_dev->masklength,
compound_mask);
if (indio_dev->active_scan_mask == NULL) {
iio_buffer_deactivate(insert_buffer);
if (old_mask) {
indio_dev->active_scan_mask = old_mask;
success = -EINVAL;
}
else {
kfree(compound_mask);
ret = -EINVAL;
return ret;
}
}
} else {
indio_dev->active_scan_mask = compound_mask;
}
iio_update_demux(indio_dev);
if (indio_dev->setup_ops->preenable) {
ret = indio_dev->setup_ops->preenable(indio_dev);
if (ret) {
printk(KERN_ERR
"Buffer not started: buffer preenable failed (%d)\n", ret);
goto error_remove_inserted;
}
}
indio_dev->scan_bytes =
iio_compute_scan_bytes(indio_dev,
indio_dev->active_scan_mask,
indio_dev->scan_timestamp);
list_for_each_entry(buffer, &indio_dev->buffer_list, buffer_list) {
iio_buffer_update_bytes_per_datum(indio_dev, buffer);
if (buffer->access->request_update) {
ret = buffer->access->request_update(buffer);
if (ret) {
printk(KERN_INFO
"Buffer not started: buffer parameter update failed (%d)\n", ret);
goto error_run_postdisable;
}
}
}
if (indio_dev->info->update_scan_mode) {
ret = indio_dev->info
->update_scan_mode(indio_dev,
indio_dev->active_scan_mask);
if (ret < 0) {
printk(KERN_INFO "Buffer not started: update scan mode failed (%d)\n", ret);
goto error_run_postdisable;
}
}
if (indio_dev->modes & INDIO_BUFFER_TRIGGERED) {
if (!indio_dev->trig) {
printk(KERN_INFO "Buffer not started: no trigger\n");
ret = -EINVAL;
goto error_run_postdisable;
}
indio_dev->currentmode = INDIO_BUFFER_TRIGGERED;
} else if (indio_dev->modes & INDIO_BUFFER_HARDWARE) {
indio_dev->currentmode = INDIO_BUFFER_HARDWARE;
} else {
ret = -EINVAL;
goto error_run_postdisable;
}
if (indio_dev->setup_ops->postenable) {
ret = indio_dev->setup_ops->postenable(indio_dev);
if (ret) {
printk(KERN_INFO
"Buffer not started: postenable failed (%d)\n", ret);
indio_dev->currentmode = INDIO_DIRECT_MODE;
if (indio_dev->setup_ops->postdisable)
indio_dev->setup_ops->postdisable(indio_dev);
goto error_disable_all_buffers;
}
}
if (indio_dev->available_scan_masks)
kfree(compound_mask);
else
kfree(old_mask);
return success;
error_disable_all_buffers:
indio_dev->currentmode = INDIO_DIRECT_MODE;
error_run_postdisable:
if (indio_dev->setup_ops->postdisable)
indio_dev->setup_ops->postdisable(indio_dev);
error_remove_inserted:
if (insert_buffer)
iio_buffer_deactivate(insert_buffer);
indio_dev->active_scan_mask = old_mask;
kfree(compound_mask);
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
ssize_t iio_buffer_store_enable(struct device *dev,
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
if (ret < 0)
goto done;
done:
mutex_unlock(&indio_dev->mlock);
return (ret < 0) ? ret : len;
}
bool iio_validate_scan_mask_onehot(struct iio_dev *indio_dev,
const unsigned long *mask)
{
return bitmap_weight(mask, indio_dev->masklength) == 1;
}
static bool iio_validate_scan_mask(struct iio_dev *indio_dev,
const unsigned long *mask)
{
if (!indio_dev->setup_ops->validate_scan_mask)
return true;
return indio_dev->setup_ops->validate_scan_mask(indio_dev, mask);
}
int iio_scan_mask_set(struct iio_dev *indio_dev,
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
WARN_ON("Trying to set scanmask prior to registering buffer\n");
goto err_invalid_mask;
}
bitmap_copy(trialmask, buffer->scan_mask, indio_dev->masklength);
set_bit(bit, trialmask);
if (!iio_validate_scan_mask(indio_dev, trialmask))
goto err_invalid_mask;
if (indio_dev->available_scan_masks) {
mask = iio_scan_mask_match(indio_dev->available_scan_masks,
indio_dev->masklength,
trialmask);
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
return buffer->access->store_to(buffer, dataout);
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
static int iio_buffer_update_demux(struct iio_dev *indio_dev,
struct iio_buffer *buffer)
{
const struct iio_chan_spec *ch;
int ret, in_ind = -1, out_ind, length;
unsigned in_loc = 0, out_loc = 0;
struct iio_demux_table *p;
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
ch = iio_find_channel_from_si(indio_dev, in_ind);
if (ch->scan_type.repeat > 1)
length = ch->scan_type.storagebits / 8 *
ch->scan_type.repeat;
else
length = ch->scan_type.storagebits / 8;
in_loc += length;
if (in_loc % length)
in_loc += length - in_loc % length;
}
p = kmalloc(sizeof(*p), GFP_KERNEL);
if (p == NULL) {
ret = -ENOMEM;
goto error_clear_mux_table;
}
ch = iio_find_channel_from_si(indio_dev, in_ind);
if (ch->scan_type.repeat > 1)
length = ch->scan_type.storagebits / 8 *
ch->scan_type.repeat;
else
length = ch->scan_type.storagebits / 8;
if (out_loc % length)
out_loc += length - out_loc % length;
if (in_loc % length)
in_loc += length - in_loc % length;
p->from = in_loc;
p->to = out_loc;
p->length = length;
list_add_tail(&p->l, &buffer->demux_list);
out_loc += length;
in_loc += length;
}
if (buffer->scan_timestamp) {
p = kmalloc(sizeof(*p), GFP_KERNEL);
if (p == NULL) {
ret = -ENOMEM;
goto error_clear_mux_table;
}
ch = iio_find_channel_from_si(indio_dev,
indio_dev->scan_index_timestamp);
if (ch->scan_type.repeat > 1)
length = ch->scan_type.storagebits / 8 *
ch->scan_type.repeat;
else
length = ch->scan_type.storagebits / 8;
if (out_loc % length)
out_loc += length - out_loc % length;
if (in_loc % length)
in_loc += length - in_loc % length;
p->from = in_loc;
p->to = out_loc;
p->length = length;
list_add_tail(&p->l, &buffer->demux_list);
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
