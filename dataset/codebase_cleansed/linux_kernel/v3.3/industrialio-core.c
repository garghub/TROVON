const struct iio_chan_spec
*iio_find_channel_from_si(struct iio_dev *indio_dev, int si)
{
int i;
for (i = 0; i < indio_dev->num_channels; i++)
if (indio_dev->channels[i].scan_index == si)
return &indio_dev->channels[i];
return NULL;
}
int iio_push_event(struct iio_dev *indio_dev, u64 ev_code, s64 timestamp)
{
struct iio_event_interface *ev_int = indio_dev->event_interface;
struct iio_detected_event_list *ev;
int ret = 0;
mutex_lock(&ev_int->event_list_lock);
if (test_bit(IIO_BUSY_BIT_POS, &ev_int->flags)) {
if (ev_int->current_events == ev_int->max_events) {
mutex_unlock(&ev_int->event_list_lock);
return 0;
}
ev = kmalloc(sizeof(*ev), GFP_KERNEL);
if (ev == NULL) {
ret = -ENOMEM;
mutex_unlock(&ev_int->event_list_lock);
goto error_ret;
}
ev->ev.id = ev_code;
ev->ev.timestamp = timestamp;
list_add_tail(&ev->list, &ev_int->det_events);
ev_int->current_events++;
mutex_unlock(&ev_int->event_list_lock);
wake_up_interruptible(&ev_int->wait);
} else
mutex_unlock(&ev_int->event_list_lock);
error_ret:
return ret;
}
ssize_t iio_read_const_attr(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%s\n", to_iio_const_attr(attr)->string);
}
static ssize_t iio_event_chrdev_read(struct file *filep,
char __user *buf,
size_t count,
loff_t *f_ps)
{
struct iio_event_interface *ev_int = filep->private_data;
struct iio_detected_event_list *el;
size_t len = sizeof(el->ev);
int ret;
if (count < len)
return -EINVAL;
mutex_lock(&ev_int->event_list_lock);
if (list_empty(&ev_int->det_events)) {
if (filep->f_flags & O_NONBLOCK) {
ret = -EAGAIN;
goto error_mutex_unlock;
}
mutex_unlock(&ev_int->event_list_lock);
ret = wait_event_interruptible(ev_int->wait,
!list_empty(&ev_int
->det_events));
if (ret)
goto error_ret;
mutex_lock(&ev_int->event_list_lock);
}
el = list_first_entry(&ev_int->det_events,
struct iio_detected_event_list,
list);
if (copy_to_user(buf, &(el->ev), len)) {
ret = -EFAULT;
goto error_mutex_unlock;
}
list_del(&el->list);
ev_int->current_events--;
mutex_unlock(&ev_int->event_list_lock);
kfree(el);
return len;
error_mutex_unlock:
mutex_unlock(&ev_int->event_list_lock);
error_ret:
return ret;
}
static int iio_event_chrdev_release(struct inode *inode, struct file *filep)
{
struct iio_event_interface *ev_int = filep->private_data;
struct iio_detected_event_list *el, *t;
mutex_lock(&ev_int->event_list_lock);
clear_bit(IIO_BUSY_BIT_POS, &ev_int->flags);
list_for_each_entry_safe(el, t, &ev_int->det_events, list) {
list_del(&el->list);
kfree(el);
}
ev_int->current_events = 0;
mutex_unlock(&ev_int->event_list_lock);
return 0;
}
static int iio_event_getfd(struct iio_dev *indio_dev)
{
struct iio_event_interface *ev_int = indio_dev->event_interface;
int fd;
if (ev_int == NULL)
return -ENODEV;
mutex_lock(&ev_int->event_list_lock);
if (test_and_set_bit(IIO_BUSY_BIT_POS, &ev_int->flags)) {
mutex_unlock(&ev_int->event_list_lock);
return -EBUSY;
}
mutex_unlock(&ev_int->event_list_lock);
fd = anon_inode_getfd("iio:event",
&iio_event_chrdev_fileops, ev_int, O_RDONLY);
if (fd < 0) {
mutex_lock(&ev_int->event_list_lock);
clear_bit(IIO_BUSY_BIT_POS, &ev_int->flags);
mutex_unlock(&ev_int->event_list_lock);
}
return fd;
}
static int __init iio_init(void)
{
int ret;
ret = bus_register(&iio_bus_type);
if (ret < 0) {
printk(KERN_ERR
"%s could not register bus type\n",
__FILE__);
goto error_nothing;
}
ret = alloc_chrdev_region(&iio_devt, 0, IIO_DEV_MAX, "iio");
if (ret < 0) {
printk(KERN_ERR "%s: failed to allocate char dev region\n",
__FILE__);
goto error_unregister_bus_type;
}
return 0;
error_unregister_bus_type:
bus_unregister(&iio_bus_type);
error_nothing:
return ret;
}
static void __exit iio_exit(void)
{
if (iio_devt)
unregister_chrdev_region(iio_devt, IIO_DEV_MAX);
bus_unregister(&iio_bus_type);
}
static ssize_t iio_read_channel_info(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int val, val2;
int ret = indio_dev->info->read_raw(indio_dev, this_attr->c,
&val, &val2, this_attr->address);
if (ret < 0)
return ret;
if (ret == IIO_VAL_INT)
return sprintf(buf, "%d\n", val);
else if (ret == IIO_VAL_INT_PLUS_MICRO) {
if (val2 < 0)
return sprintf(buf, "-%d.%06u\n", val, -val2);
else
return sprintf(buf, "%d.%06u\n", val, val2);
} else if (ret == IIO_VAL_INT_PLUS_NANO) {
if (val2 < 0)
return sprintf(buf, "-%d.%09u\n", val, -val2);
else
return sprintf(buf, "%d.%09u\n", val, val2);
} else
return 0;
}
static ssize_t iio_write_channel_info(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret, integer = 0, fract = 0, fract_mult = 100000;
bool integer_part = true, negative = false;
if (!indio_dev->info->write_raw)
return -EINVAL;
if (indio_dev->info->write_raw_get_fmt)
switch (indio_dev->info->write_raw_get_fmt(indio_dev,
this_attr->c, this_attr->address)) {
case IIO_VAL_INT_PLUS_MICRO:
fract_mult = 100000;
break;
case IIO_VAL_INT_PLUS_NANO:
fract_mult = 100000000;
break;
default:
return -EINVAL;
}
if (buf[0] == '-') {
negative = true;
buf++;
}
while (*buf) {
if ('0' <= *buf && *buf <= '9') {
if (integer_part)
integer = integer*10 + *buf - '0';
else {
fract += fract_mult*(*buf - '0');
if (fract_mult == 1)
break;
fract_mult /= 10;
}
} else if (*buf == '\n') {
if (*(buf + 1) == '\0')
break;
else
return -EINVAL;
} else if (*buf == '.') {
integer_part = false;
} else {
return -EINVAL;
}
buf++;
}
if (negative) {
if (integer)
integer = -integer;
else
fract = -fract;
}
ret = indio_dev->info->write_raw(indio_dev, this_attr->c,
integer, fract, this_attr->address);
if (ret)
return ret;
return len;
}
static
int __iio_device_attr_init(struct device_attribute *dev_attr,
const char *postfix,
struct iio_chan_spec const *chan,
ssize_t (*readfunc)(struct device *dev,
struct device_attribute *attr,
char *buf),
ssize_t (*writefunc)(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len),
bool generic)
{
int ret;
char *name_format, *full_postfix;
sysfs_attr_init(&dev_attr->attr);
if (chan->modified && !generic) {
if (chan->extend_name)
full_postfix = kasprintf(GFP_KERNEL, "%s_%s_%s",
iio_modifier_names[chan
->channel2],
chan->extend_name,
postfix);
else
full_postfix = kasprintf(GFP_KERNEL, "%s_%s",
iio_modifier_names[chan
->channel2],
postfix);
} else {
if (chan->extend_name == NULL)
full_postfix = kstrdup(postfix, GFP_KERNEL);
else
full_postfix = kasprintf(GFP_KERNEL,
"%s_%s",
chan->extend_name,
postfix);
}
if (full_postfix == NULL) {
ret = -ENOMEM;
goto error_ret;
}
if (chan->differential) {
if (generic)
name_format
= kasprintf(GFP_KERNEL, "%s_%s-%s_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
iio_chan_type_name_spec[chan->type],
full_postfix);
else if (chan->indexed)
name_format
= kasprintf(GFP_KERNEL, "%s_%s%d-%s%d_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
chan->channel,
iio_chan_type_name_spec[chan->type],
chan->channel2,
full_postfix);
else {
WARN_ON("Differential channels must be indexed\n");
ret = -EINVAL;
goto error_free_full_postfix;
}
} else {
if (generic)
name_format
= kasprintf(GFP_KERNEL, "%s_%s_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
full_postfix);
else if (chan->indexed)
name_format
= kasprintf(GFP_KERNEL, "%s_%s%d_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
chan->channel,
full_postfix);
else
name_format
= kasprintf(GFP_KERNEL, "%s_%s_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
full_postfix);
}
if (name_format == NULL) {
ret = -ENOMEM;
goto error_free_full_postfix;
}
dev_attr->attr.name = kasprintf(GFP_KERNEL,
name_format,
chan->channel,
chan->channel2);
if (dev_attr->attr.name == NULL) {
ret = -ENOMEM;
goto error_free_name_format;
}
if (readfunc) {
dev_attr->attr.mode |= S_IRUGO;
dev_attr->show = readfunc;
}
if (writefunc) {
dev_attr->attr.mode |= S_IWUSR;
dev_attr->store = writefunc;
}
kfree(name_format);
kfree(full_postfix);
return 0;
error_free_name_format:
kfree(name_format);
error_free_full_postfix:
kfree(full_postfix);
error_ret:
return ret;
}
static void __iio_device_attr_deinit(struct device_attribute *dev_attr)
{
kfree(dev_attr->attr.name);
}
int __iio_add_chan_devattr(const char *postfix,
struct iio_chan_spec const *chan,
ssize_t (*readfunc)(struct device *dev,
struct device_attribute *attr,
char *buf),
ssize_t (*writefunc)(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len),
u64 mask,
bool generic,
struct device *dev,
struct list_head *attr_list)
{
int ret;
struct iio_dev_attr *iio_attr, *t;
iio_attr = kzalloc(sizeof *iio_attr, GFP_KERNEL);
if (iio_attr == NULL) {
ret = -ENOMEM;
goto error_ret;
}
ret = __iio_device_attr_init(&iio_attr->dev_attr,
postfix, chan,
readfunc, writefunc, generic);
if (ret)
goto error_iio_dev_attr_free;
iio_attr->c = chan;
iio_attr->address = mask;
list_for_each_entry(t, attr_list, l)
if (strcmp(t->dev_attr.attr.name,
iio_attr->dev_attr.attr.name) == 0) {
if (!generic)
dev_err(dev, "tried to double register : %s\n",
t->dev_attr.attr.name);
ret = -EBUSY;
goto error_device_attr_deinit;
}
list_add(&iio_attr->l, attr_list);
return 0;
error_device_attr_deinit:
__iio_device_attr_deinit(&iio_attr->dev_attr);
error_iio_dev_attr_free:
kfree(iio_attr);
error_ret:
return ret;
}
static int iio_device_add_channel_sysfs(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan)
{
int ret, i, attrcount = 0;
if (chan->channel < 0)
return 0;
ret = __iio_add_chan_devattr(iio_data_type_name[chan->processed_val],
chan,
&iio_read_channel_info,
(chan->output ?
&iio_write_channel_info : NULL),
0,
0,
&indio_dev->dev,
&indio_dev->channel_attr_list);
if (ret)
goto error_ret;
attrcount++;
for_each_set_bit(i, &chan->info_mask, sizeof(long)*8) {
ret = __iio_add_chan_devattr(iio_chan_info_postfix[i/2],
chan,
&iio_read_channel_info,
&iio_write_channel_info,
i/2,
!(i%2),
&indio_dev->dev,
&indio_dev->channel_attr_list);
if (ret == -EBUSY && (i%2 == 0)) {
ret = 0;
continue;
}
if (ret < 0)
goto error_ret;
attrcount++;
}
ret = attrcount;
error_ret:
return ret;
}
static void iio_device_remove_and_free_read_attr(struct iio_dev *indio_dev,
struct iio_dev_attr *p)
{
kfree(p->dev_attr.attr.name);
kfree(p);
}
static ssize_t iio_show_dev_name(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", indio_dev->name);
}
static int iio_device_register_sysfs(struct iio_dev *indio_dev)
{
int i, ret = 0, attrcount, attrn, attrcount_orig = 0;
struct iio_dev_attr *p, *n;
struct attribute **attr;
if (indio_dev->info->attrs) {
attr = indio_dev->info->attrs->attrs;
while (*attr++ != NULL)
attrcount_orig++;
}
attrcount = attrcount_orig;
INIT_LIST_HEAD(&indio_dev->channel_attr_list);
if (indio_dev->channels)
for (i = 0; i < indio_dev->num_channels; i++) {
ret = iio_device_add_channel_sysfs(indio_dev,
&indio_dev
->channels[i]);
if (ret < 0)
goto error_clear_attrs;
attrcount += ret;
}
if (indio_dev->name)
attrcount++;
indio_dev->chan_attr_group.attrs = kcalloc(attrcount + 1,
sizeof(indio_dev->chan_attr_group.attrs[0]),
GFP_KERNEL);
if (indio_dev->chan_attr_group.attrs == NULL) {
ret = -ENOMEM;
goto error_clear_attrs;
}
if (indio_dev->info->attrs)
memcpy(indio_dev->chan_attr_group.attrs,
indio_dev->info->attrs->attrs,
sizeof(indio_dev->chan_attr_group.attrs[0])
*attrcount_orig);
attrn = attrcount_orig;
list_for_each_entry(p, &indio_dev->channel_attr_list, l)
indio_dev->chan_attr_group.attrs[attrn++] = &p->dev_attr.attr;
if (indio_dev->name)
indio_dev->chan_attr_group.attrs[attrn++] = &dev_attr_name.attr;
indio_dev->groups[indio_dev->groupcounter++] =
&indio_dev->chan_attr_group;
return 0;
error_clear_attrs:
list_for_each_entry_safe(p, n,
&indio_dev->channel_attr_list, l) {
list_del(&p->l);
iio_device_remove_and_free_read_attr(indio_dev, p);
}
return ret;
}
static void iio_device_unregister_sysfs(struct iio_dev *indio_dev)
{
struct iio_dev_attr *p, *n;
list_for_each_entry_safe(p, n, &indio_dev->channel_attr_list, l) {
list_del(&p->l);
iio_device_remove_and_free_read_attr(indio_dev, p);
}
kfree(indio_dev->chan_attr_group.attrs);
}
static ssize_t iio_ev_state_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
bool val;
ret = strtobool(buf, &val);
if (ret < 0)
return ret;
ret = indio_dev->info->write_event_config(indio_dev,
this_attr->address,
val);
return (ret < 0) ? ret : len;
}
static ssize_t iio_ev_state_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int val = indio_dev->info->read_event_config(indio_dev,
this_attr->address);
if (val < 0)
return val;
else
return sprintf(buf, "%d\n", val);
}
static ssize_t iio_ev_value_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int val, ret;
ret = indio_dev->info->read_event_value(indio_dev,
this_attr->address, &val);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", val);
}
static ssize_t iio_ev_value_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
unsigned long val;
int ret;
if (!indio_dev->info->write_event_value)
return -EINVAL;
ret = strict_strtoul(buf, 10, &val);
if (ret)
return ret;
ret = indio_dev->info->write_event_value(indio_dev, this_attr->address,
val);
if (ret < 0)
return ret;
return len;
}
static int iio_device_add_event_sysfs(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan)
{
int ret = 0, i, attrcount = 0;
u64 mask = 0;
char *postfix;
if (!chan->event_mask)
return 0;
for_each_set_bit(i, &chan->event_mask, sizeof(chan->event_mask)*8) {
postfix = kasprintf(GFP_KERNEL, "%s_%s_en",
iio_ev_type_text[i/IIO_EV_DIR_MAX],
iio_ev_dir_text[i%IIO_EV_DIR_MAX]);
if (postfix == NULL) {
ret = -ENOMEM;
goto error_ret;
}
if (chan->modified)
mask = IIO_MOD_EVENT_CODE(chan->type, 0, chan->channel,
i/IIO_EV_DIR_MAX,
i%IIO_EV_DIR_MAX);
else if (chan->differential)
mask = IIO_EVENT_CODE(chan->type,
0, 0,
i%IIO_EV_DIR_MAX,
i/IIO_EV_DIR_MAX,
0,
chan->channel,
chan->channel2);
else
mask = IIO_UNMOD_EVENT_CODE(chan->type,
chan->channel,
i/IIO_EV_DIR_MAX,
i%IIO_EV_DIR_MAX);
ret = __iio_add_chan_devattr(postfix,
chan,
&iio_ev_state_show,
iio_ev_state_store,
mask,
0,
&indio_dev->dev,
&indio_dev->event_interface->
dev_attr_list);
kfree(postfix);
if (ret)
goto error_ret;
attrcount++;
postfix = kasprintf(GFP_KERNEL, "%s_%s_value",
iio_ev_type_text[i/IIO_EV_DIR_MAX],
iio_ev_dir_text[i%IIO_EV_DIR_MAX]);
if (postfix == NULL) {
ret = -ENOMEM;
goto error_ret;
}
ret = __iio_add_chan_devattr(postfix, chan,
iio_ev_value_show,
iio_ev_value_store,
mask,
0,
&indio_dev->dev,
&indio_dev->event_interface->
dev_attr_list);
kfree(postfix);
if (ret)
goto error_ret;
attrcount++;
}
ret = attrcount;
error_ret:
return ret;
}
static inline void __iio_remove_event_config_attrs(struct iio_dev *indio_dev)
{
struct iio_dev_attr *p, *n;
list_for_each_entry_safe(p, n,
&indio_dev->event_interface->
dev_attr_list, l) {
kfree(p->dev_attr.attr.name);
kfree(p);
}
}
static inline int __iio_add_event_config_attrs(struct iio_dev *indio_dev)
{
int j, ret, attrcount = 0;
INIT_LIST_HEAD(&indio_dev->event_interface->dev_attr_list);
for (j = 0; j < indio_dev->num_channels; j++) {
ret = iio_device_add_event_sysfs(indio_dev,
&indio_dev->channels[j]);
if (ret < 0)
goto error_clear_attrs;
attrcount += ret;
}
return attrcount;
error_clear_attrs:
__iio_remove_event_config_attrs(indio_dev);
return ret;
}
static bool iio_check_for_dynamic_events(struct iio_dev *indio_dev)
{
int j;
for (j = 0; j < indio_dev->num_channels; j++)
if (indio_dev->channels[j].event_mask != 0)
return true;
return false;
}
static void iio_setup_ev_int(struct iio_event_interface *ev_int)
{
mutex_init(&ev_int->event_list_lock);
ev_int->max_events = 10;
ev_int->current_events = 0;
INIT_LIST_HEAD(&ev_int->det_events);
init_waitqueue_head(&ev_int->wait);
}
static int iio_device_register_eventset(struct iio_dev *indio_dev)
{
struct iio_dev_attr *p;
int ret = 0, attrcount_orig = 0, attrcount, attrn;
struct attribute **attr;
if (!(indio_dev->info->event_attrs ||
iio_check_for_dynamic_events(indio_dev)))
return 0;
indio_dev->event_interface =
kzalloc(sizeof(struct iio_event_interface), GFP_KERNEL);
if (indio_dev->event_interface == NULL) {
ret = -ENOMEM;
goto error_ret;
}
iio_setup_ev_int(indio_dev->event_interface);
if (indio_dev->info->event_attrs != NULL) {
attr = indio_dev->info->event_attrs->attrs;
while (*attr++ != NULL)
attrcount_orig++;
}
attrcount = attrcount_orig;
if (indio_dev->channels) {
ret = __iio_add_event_config_attrs(indio_dev);
if (ret < 0)
goto error_free_setup_event_lines;
attrcount += ret;
}
indio_dev->event_interface->group.name = iio_event_group_name;
indio_dev->event_interface->group.attrs = kcalloc(attrcount + 1,
sizeof(indio_dev->event_interface->group.attrs[0]),
GFP_KERNEL);
if (indio_dev->event_interface->group.attrs == NULL) {
ret = -ENOMEM;
goto error_free_setup_event_lines;
}
if (indio_dev->info->event_attrs)
memcpy(indio_dev->event_interface->group.attrs,
indio_dev->info->event_attrs->attrs,
sizeof(indio_dev->event_interface->group.attrs[0])
*attrcount_orig);
attrn = attrcount_orig;
list_for_each_entry(p,
&indio_dev->event_interface->dev_attr_list,
l)
indio_dev->event_interface->group.attrs[attrn++] =
&p->dev_attr.attr;
indio_dev->groups[indio_dev->groupcounter++] =
&indio_dev->event_interface->group;
return 0;
error_free_setup_event_lines:
__iio_remove_event_config_attrs(indio_dev);
kfree(indio_dev->event_interface);
error_ret:
return ret;
}
static void iio_device_unregister_eventset(struct iio_dev *indio_dev)
{
if (indio_dev->event_interface == NULL)
return;
__iio_remove_event_config_attrs(indio_dev);
kfree(indio_dev->event_interface->group.attrs);
kfree(indio_dev->event_interface);
}
static void iio_dev_release(struct device *device)
{
struct iio_dev *indio_dev = container_of(device, struct iio_dev, dev);
cdev_del(&indio_dev->chrdev);
if (indio_dev->modes & INDIO_BUFFER_TRIGGERED)
iio_device_unregister_trigger_consumer(indio_dev);
iio_device_unregister_eventset(indio_dev);
iio_device_unregister_sysfs(indio_dev);
}
struct iio_dev *iio_allocate_device(int sizeof_priv)
{
struct iio_dev *dev;
size_t alloc_size;
alloc_size = sizeof(struct iio_dev);
if (sizeof_priv) {
alloc_size = ALIGN(alloc_size, IIO_ALIGN);
alloc_size += sizeof_priv;
}
alloc_size += IIO_ALIGN - 1;
dev = kzalloc(alloc_size, GFP_KERNEL);
if (dev) {
dev->dev.groups = dev->groups;
dev->dev.type = &iio_dev_type;
dev->dev.bus = &iio_bus_type;
device_initialize(&dev->dev);
dev_set_drvdata(&dev->dev, (void *)dev);
mutex_init(&dev->mlock);
dev->id = ida_simple_get(&iio_ida, 0, 0, GFP_KERNEL);
if (dev->id < 0) {
printk(KERN_ERR "Failed to get id\n");
kfree(dev);
return NULL;
}
dev_set_name(&dev->dev, "iio:device%d", dev->id);
}
return dev;
}
void iio_free_device(struct iio_dev *dev)
{
if (dev) {
ida_simple_remove(&iio_ida, dev->id);
kfree(dev);
}
}
static int iio_chrdev_open(struct inode *inode, struct file *filp)
{
struct iio_dev *indio_dev = container_of(inode->i_cdev,
struct iio_dev, chrdev);
if (test_and_set_bit(IIO_BUSY_BIT_POS, &indio_dev->flags))
return -EBUSY;
filp->private_data = indio_dev;
return 0;
}
static int iio_chrdev_release(struct inode *inode, struct file *filp)
{
struct iio_dev *indio_dev = container_of(inode->i_cdev,
struct iio_dev, chrdev);
clear_bit(IIO_BUSY_BIT_POS, &indio_dev->flags);
return 0;
}
static long iio_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
struct iio_dev *indio_dev = filp->private_data;
int __user *ip = (int __user *)arg;
int fd;
if (cmd == IIO_GET_EVENT_FD_IOCTL) {
fd = iio_event_getfd(indio_dev);
if (copy_to_user(ip, &fd, sizeof(fd)))
return -EFAULT;
return 0;
}
return -EINVAL;
}
int iio_device_register(struct iio_dev *indio_dev)
{
int ret;
indio_dev->dev.devt = MKDEV(MAJOR(iio_devt), indio_dev->id);
ret = iio_device_register_sysfs(indio_dev);
if (ret) {
dev_err(indio_dev->dev.parent,
"Failed to register sysfs interfaces\n");
goto error_ret;
}
ret = iio_device_register_eventset(indio_dev);
if (ret) {
dev_err(indio_dev->dev.parent,
"Failed to register event set\n");
goto error_free_sysfs;
}
if (indio_dev->modes & INDIO_BUFFER_TRIGGERED)
iio_device_register_trigger_consumer(indio_dev);
ret = device_add(&indio_dev->dev);
if (ret < 0)
goto error_unreg_eventset;
cdev_init(&indio_dev->chrdev, &iio_buffer_fileops);
indio_dev->chrdev.owner = indio_dev->info->driver_module;
ret = cdev_add(&indio_dev->chrdev, indio_dev->dev.devt, 1);
if (ret < 0)
goto error_del_device;
return 0;
error_del_device:
device_del(&indio_dev->dev);
error_unreg_eventset:
iio_device_unregister_eventset(indio_dev);
error_free_sysfs:
iio_device_unregister_sysfs(indio_dev);
error_ret:
return ret;
}
void iio_device_unregister(struct iio_dev *indio_dev)
{
device_unregister(&indio_dev->dev);
}
