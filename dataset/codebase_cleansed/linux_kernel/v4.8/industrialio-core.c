const struct iio_chan_spec
*iio_find_channel_from_si(struct iio_dev *indio_dev, int si)
{
int i;
for (i = 0; i < indio_dev->num_channels; i++)
if (indio_dev->channels[i].scan_index == si)
return &indio_dev->channels[i];
return NULL;
}
ssize_t iio_read_const_attr(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%s\n", to_iio_const_attr(attr)->string);
}
static int iio_device_set_clock(struct iio_dev *indio_dev, clockid_t clock_id)
{
int ret;
const struct iio_event_interface *ev_int = indio_dev->event_interface;
ret = mutex_lock_interruptible(&indio_dev->mlock);
if (ret)
return ret;
if ((ev_int && iio_event_enabled(ev_int)) ||
iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
indio_dev->clock_id = clock_id;
mutex_unlock(&indio_dev->mlock);
return 0;
}
s64 iio_get_time_ns(const struct iio_dev *indio_dev)
{
struct timespec tp;
switch (iio_device_get_clock(indio_dev)) {
case CLOCK_REALTIME:
ktime_get_real_ts(&tp);
break;
case CLOCK_MONOTONIC:
ktime_get_ts(&tp);
break;
case CLOCK_MONOTONIC_RAW:
getrawmonotonic(&tp);
break;
case CLOCK_REALTIME_COARSE:
tp = current_kernel_time();
break;
case CLOCK_MONOTONIC_COARSE:
tp = get_monotonic_coarse();
break;
case CLOCK_BOOTTIME:
get_monotonic_boottime(&tp);
break;
case CLOCK_TAI:
timekeeping_clocktai(&tp);
break;
default:
BUG();
}
return timespec_to_ns(&tp);
}
unsigned int iio_get_time_res(const struct iio_dev *indio_dev)
{
switch (iio_device_get_clock(indio_dev)) {
case CLOCK_REALTIME:
case CLOCK_MONOTONIC:
case CLOCK_MONOTONIC_RAW:
case CLOCK_BOOTTIME:
case CLOCK_TAI:
return hrtimer_resolution;
case CLOCK_REALTIME_COARSE:
case CLOCK_MONOTONIC_COARSE:
return LOW_RES_NSEC;
default:
BUG();
}
}
static int __init iio_init(void)
{
int ret;
ret = bus_register(&iio_bus_type);
if (ret < 0) {
pr_err("could not register bus type\n");
goto error_nothing;
}
ret = alloc_chrdev_region(&iio_devt, 0, IIO_DEV_MAX, "iio");
if (ret < 0) {
pr_err("failed to allocate char dev region\n");
goto error_unregister_bus_type;
}
iio_debugfs_dentry = debugfs_create_dir("iio", NULL);
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
debugfs_remove(iio_debugfs_dentry);
}
static ssize_t iio_debugfs_read_reg(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct iio_dev *indio_dev = file->private_data;
char buf[20];
unsigned val = 0;
ssize_t len;
int ret;
ret = indio_dev->info->debugfs_reg_access(indio_dev,
indio_dev->cached_reg_addr,
0, &val);
if (ret)
dev_err(indio_dev->dev.parent, "%s: read failed\n", __func__);
len = snprintf(buf, sizeof(buf), "0x%X\n", val);
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static ssize_t iio_debugfs_write_reg(struct file *file,
const char __user *userbuf, size_t count, loff_t *ppos)
{
struct iio_dev *indio_dev = file->private_data;
unsigned reg, val;
char buf[80];
int ret;
count = min_t(size_t, count, (sizeof(buf)-1));
if (copy_from_user(buf, userbuf, count))
return -EFAULT;
buf[count] = 0;
ret = sscanf(buf, "%i %i", &reg, &val);
switch (ret) {
case 1:
indio_dev->cached_reg_addr = reg;
break;
case 2:
indio_dev->cached_reg_addr = reg;
ret = indio_dev->info->debugfs_reg_access(indio_dev, reg,
val, NULL);
if (ret) {
dev_err(indio_dev->dev.parent, "%s: write failed\n",
__func__);
return ret;
}
break;
default:
return -EINVAL;
}
return count;
}
static void iio_device_unregister_debugfs(struct iio_dev *indio_dev)
{
debugfs_remove_recursive(indio_dev->debugfs_dentry);
}
static int iio_device_register_debugfs(struct iio_dev *indio_dev)
{
struct dentry *d;
if (indio_dev->info->debugfs_reg_access == NULL)
return 0;
if (!iio_debugfs_dentry)
return 0;
indio_dev->debugfs_dentry =
debugfs_create_dir(dev_name(&indio_dev->dev),
iio_debugfs_dentry);
if (indio_dev->debugfs_dentry == NULL) {
dev_warn(indio_dev->dev.parent,
"Failed to create debugfs directory\n");
return -EFAULT;
}
d = debugfs_create_file("direct_reg_access", 0644,
indio_dev->debugfs_dentry,
indio_dev, &iio_debugfs_reg_fops);
if (!d) {
iio_device_unregister_debugfs(indio_dev);
return -ENOMEM;
}
return 0;
}
static int iio_device_register_debugfs(struct iio_dev *indio_dev)
{
return 0;
}
static void iio_device_unregister_debugfs(struct iio_dev *indio_dev)
{
}
static ssize_t iio_read_channel_ext_info(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
const struct iio_chan_spec_ext_info *ext_info;
ext_info = &this_attr->c->ext_info[this_attr->address];
return ext_info->read(indio_dev, ext_info->private, this_attr->c, buf);
}
static ssize_t iio_write_channel_ext_info(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
const struct iio_chan_spec_ext_info *ext_info;
ext_info = &this_attr->c->ext_info[this_attr->address];
return ext_info->write(indio_dev, ext_info->private,
this_attr->c, buf, len);
}
ssize_t iio_enum_available_read(struct iio_dev *indio_dev,
uintptr_t priv, const struct iio_chan_spec *chan, char *buf)
{
const struct iio_enum *e = (const struct iio_enum *)priv;
unsigned int i;
size_t len = 0;
if (!e->num_items)
return 0;
for (i = 0; i < e->num_items; ++i)
len += scnprintf(buf + len, PAGE_SIZE - len, "%s ", e->items[i]);
buf[len - 1] = '\n';
return len;
}
ssize_t iio_enum_read(struct iio_dev *indio_dev,
uintptr_t priv, const struct iio_chan_spec *chan, char *buf)
{
const struct iio_enum *e = (const struct iio_enum *)priv;
int i;
if (!e->get)
return -EINVAL;
i = e->get(indio_dev, chan);
if (i < 0)
return i;
else if (i >= e->num_items)
return -EINVAL;
return snprintf(buf, PAGE_SIZE, "%s\n", e->items[i]);
}
ssize_t iio_enum_write(struct iio_dev *indio_dev,
uintptr_t priv, const struct iio_chan_spec *chan, const char *buf,
size_t len)
{
const struct iio_enum *e = (const struct iio_enum *)priv;
unsigned int i;
int ret;
if (!e->set)
return -EINVAL;
for (i = 0; i < e->num_items; i++) {
if (sysfs_streq(buf, e->items[i]))
break;
}
if (i == e->num_items)
return -EINVAL;
ret = e->set(indio_dev, chan, i);
return ret ? ret : len;
}
static int iio_setup_mount_idmatrix(const struct device *dev,
struct iio_mount_matrix *matrix)
{
*matrix = iio_mount_idmatrix;
dev_info(dev, "mounting matrix not found: using identity...\n");
return 0;
}
ssize_t iio_show_mount_matrix(struct iio_dev *indio_dev, uintptr_t priv,
const struct iio_chan_spec *chan, char *buf)
{
const struct iio_mount_matrix *mtx = ((iio_get_mount_matrix_t *)
priv)(indio_dev, chan);
if (IS_ERR(mtx))
return PTR_ERR(mtx);
if (!mtx)
mtx = &iio_mount_idmatrix;
return snprintf(buf, PAGE_SIZE, "%s, %s, %s; %s, %s, %s; %s, %s, %s\n",
mtx->rotation[0], mtx->rotation[1], mtx->rotation[2],
mtx->rotation[3], mtx->rotation[4], mtx->rotation[5],
mtx->rotation[6], mtx->rotation[7], mtx->rotation[8]);
}
int of_iio_read_mount_matrix(const struct device *dev,
const char *propname,
struct iio_mount_matrix *matrix)
{
if (dev->of_node) {
int err = of_property_read_string_array(dev->of_node,
propname, matrix->rotation,
ARRAY_SIZE(iio_mount_idmatrix.rotation));
if (err == ARRAY_SIZE(iio_mount_idmatrix.rotation))
return 0;
if (err >= 0)
return -EINVAL;
if (err != -EINVAL)
return err;
}
return iio_setup_mount_idmatrix(dev, matrix);
}
int of_iio_read_mount_matrix(const struct device *dev,
const char *propname,
struct iio_mount_matrix *matrix)
{
return iio_setup_mount_idmatrix(dev, matrix);
}
ssize_t iio_format_value(char *buf, unsigned int type, int size, int *vals)
{
unsigned long long tmp;
bool scale_db = false;
switch (type) {
case IIO_VAL_INT:
return sprintf(buf, "%d\n", vals[0]);
case IIO_VAL_INT_PLUS_MICRO_DB:
scale_db = true;
case IIO_VAL_INT_PLUS_MICRO:
if (vals[1] < 0)
return sprintf(buf, "-%d.%06u%s\n", abs(vals[0]),
-vals[1], scale_db ? " dB" : "");
else
return sprintf(buf, "%d.%06u%s\n", vals[0], vals[1],
scale_db ? " dB" : "");
case IIO_VAL_INT_PLUS_NANO:
if (vals[1] < 0)
return sprintf(buf, "-%d.%09u\n", abs(vals[0]),
-vals[1]);
else
return sprintf(buf, "%d.%09u\n", vals[0], vals[1]);
case IIO_VAL_FRACTIONAL:
tmp = div_s64((s64)vals[0] * 1000000000LL, vals[1]);
vals[0] = (int)div_s64_rem(tmp, 1000000000, &vals[1]);
return sprintf(buf, "%d.%09u\n", vals[0], abs(vals[1]));
case IIO_VAL_FRACTIONAL_LOG2:
tmp = (s64)vals[0] * 1000000000LL >> vals[1];
vals[1] = do_div(tmp, 1000000000LL);
vals[0] = tmp;
return sprintf(buf, "%d.%09u\n", vals[0], vals[1]);
case IIO_VAL_INT_MULTIPLE:
{
int i;
int len = 0;
for (i = 0; i < size; ++i)
len += snprintf(&buf[len], PAGE_SIZE - len, "%d ",
vals[i]);
len += snprintf(&buf[len], PAGE_SIZE - len, "\n");
return len;
}
default:
return 0;
}
}
static ssize_t iio_read_channel_info(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int vals[INDIO_MAX_RAW_ELEMENTS];
int ret;
int val_len = 2;
if (indio_dev->info->read_raw_multi)
ret = indio_dev->info->read_raw_multi(indio_dev, this_attr->c,
INDIO_MAX_RAW_ELEMENTS,
vals, &val_len,
this_attr->address);
else
ret = indio_dev->info->read_raw(indio_dev, this_attr->c,
&vals[0], &vals[1], this_attr->address);
if (ret < 0)
return ret;
return iio_format_value(buf, ret, val_len, vals);
}
int iio_str_to_fixpoint(const char *str, int fract_mult,
int *integer, int *fract)
{
int i = 0, f = 0;
bool integer_part = true, negative = false;
if (fract_mult == 0) {
*fract = 0;
return kstrtoint(str, 0, integer);
}
if (str[0] == '-') {
negative = true;
str++;
} else if (str[0] == '+') {
str++;
}
while (*str) {
if ('0' <= *str && *str <= '9') {
if (integer_part) {
i = i * 10 + *str - '0';
} else {
f += fract_mult * (*str - '0');
fract_mult /= 10;
}
} else if (*str == '\n') {
if (*(str + 1) == '\0')
break;
else
return -EINVAL;
} else if (*str == '.' && integer_part) {
integer_part = false;
} else {
return -EINVAL;
}
str++;
}
if (negative) {
if (i)
i = -i;
else
f = -f;
}
*integer = i;
*fract = f;
return 0;
}
static ssize_t iio_write_channel_info(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret, fract_mult = 100000;
int integer, fract;
if (!indio_dev->info->write_raw)
return -EINVAL;
if (indio_dev->info->write_raw_get_fmt)
switch (indio_dev->info->write_raw_get_fmt(indio_dev,
this_attr->c, this_attr->address)) {
case IIO_VAL_INT:
fract_mult = 0;
break;
case IIO_VAL_INT_PLUS_MICRO:
fract_mult = 100000;
break;
case IIO_VAL_INT_PLUS_NANO:
fract_mult = 100000000;
break;
default:
return -EINVAL;
}
ret = iio_str_to_fixpoint(buf, fract_mult, &integer, &fract);
if (ret)
return ret;
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
enum iio_shared_by shared_by)
{
int ret = 0;
char *name = NULL;
char *full_postfix;
sysfs_attr_init(&dev_attr->attr);
if (chan->modified && (shared_by == IIO_SEPARATE)) {
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
if (chan->extend_name == NULL || shared_by != IIO_SEPARATE)
full_postfix = kstrdup(postfix, GFP_KERNEL);
else
full_postfix = kasprintf(GFP_KERNEL,
"%s_%s",
chan->extend_name,
postfix);
}
if (full_postfix == NULL)
return -ENOMEM;
if (chan->differential) {
switch (shared_by) {
case IIO_SHARED_BY_ALL:
name = kasprintf(GFP_KERNEL, "%s", full_postfix);
break;
case IIO_SHARED_BY_DIR:
name = kasprintf(GFP_KERNEL, "%s_%s",
iio_direction[chan->output],
full_postfix);
break;
case IIO_SHARED_BY_TYPE:
name = kasprintf(GFP_KERNEL, "%s_%s-%s_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
iio_chan_type_name_spec[chan->type],
full_postfix);
break;
case IIO_SEPARATE:
if (!chan->indexed) {
WARN(1, "Differential channels must be indexed\n");
ret = -EINVAL;
goto error_free_full_postfix;
}
name = kasprintf(GFP_KERNEL,
"%s_%s%d-%s%d_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
chan->channel,
iio_chan_type_name_spec[chan->type],
chan->channel2,
full_postfix);
break;
}
} else {
switch (shared_by) {
case IIO_SHARED_BY_ALL:
name = kasprintf(GFP_KERNEL, "%s", full_postfix);
break;
case IIO_SHARED_BY_DIR:
name = kasprintf(GFP_KERNEL, "%s_%s",
iio_direction[chan->output],
full_postfix);
break;
case IIO_SHARED_BY_TYPE:
name = kasprintf(GFP_KERNEL, "%s_%s_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
full_postfix);
break;
case IIO_SEPARATE:
if (chan->indexed)
name = kasprintf(GFP_KERNEL, "%s_%s%d_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
chan->channel,
full_postfix);
else
name = kasprintf(GFP_KERNEL, "%s_%s_%s",
iio_direction[chan->output],
iio_chan_type_name_spec[chan->type],
full_postfix);
break;
}
}
if (name == NULL) {
ret = -ENOMEM;
goto error_free_full_postfix;
}
dev_attr->attr.name = name;
if (readfunc) {
dev_attr->attr.mode |= S_IRUGO;
dev_attr->show = readfunc;
}
if (writefunc) {
dev_attr->attr.mode |= S_IWUSR;
dev_attr->store = writefunc;
}
error_free_full_postfix:
kfree(full_postfix);
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
enum iio_shared_by shared_by,
struct device *dev,
struct list_head *attr_list)
{
int ret;
struct iio_dev_attr *iio_attr, *t;
iio_attr = kzalloc(sizeof(*iio_attr), GFP_KERNEL);
if (iio_attr == NULL)
return -ENOMEM;
ret = __iio_device_attr_init(&iio_attr->dev_attr,
postfix, chan,
readfunc, writefunc, shared_by);
if (ret)
goto error_iio_dev_attr_free;
iio_attr->c = chan;
iio_attr->address = mask;
list_for_each_entry(t, attr_list, l)
if (strcmp(t->dev_attr.attr.name,
iio_attr->dev_attr.attr.name) == 0) {
if (shared_by == IIO_SEPARATE)
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
return ret;
}
static int iio_device_add_info_mask_type(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
enum iio_shared_by shared_by,
const long *infomask)
{
int i, ret, attrcount = 0;
for_each_set_bit(i, infomask, sizeof(infomask)*8) {
if (i >= ARRAY_SIZE(iio_chan_info_postfix))
return -EINVAL;
ret = __iio_add_chan_devattr(iio_chan_info_postfix[i],
chan,
&iio_read_channel_info,
&iio_write_channel_info,
i,
shared_by,
&indio_dev->dev,
&indio_dev->channel_attr_list);
if ((ret == -EBUSY) && (shared_by != IIO_SEPARATE))
continue;
else if (ret < 0)
return ret;
attrcount++;
}
return attrcount;
}
static int iio_device_add_channel_sysfs(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan)
{
int ret, attrcount = 0;
const struct iio_chan_spec_ext_info *ext_info;
if (chan->channel < 0)
return 0;
ret = iio_device_add_info_mask_type(indio_dev, chan,
IIO_SEPARATE,
&chan->info_mask_separate);
if (ret < 0)
return ret;
attrcount += ret;
ret = iio_device_add_info_mask_type(indio_dev, chan,
IIO_SHARED_BY_TYPE,
&chan->info_mask_shared_by_type);
if (ret < 0)
return ret;
attrcount += ret;
ret = iio_device_add_info_mask_type(indio_dev, chan,
IIO_SHARED_BY_DIR,
&chan->info_mask_shared_by_dir);
if (ret < 0)
return ret;
attrcount += ret;
ret = iio_device_add_info_mask_type(indio_dev, chan,
IIO_SHARED_BY_ALL,
&chan->info_mask_shared_by_all);
if (ret < 0)
return ret;
attrcount += ret;
if (chan->ext_info) {
unsigned int i = 0;
for (ext_info = chan->ext_info; ext_info->name; ext_info++) {
ret = __iio_add_chan_devattr(ext_info->name,
chan,
ext_info->read ?
&iio_read_channel_ext_info : NULL,
ext_info->write ?
&iio_write_channel_ext_info : NULL,
i,
ext_info->shared,
&indio_dev->dev,
&indio_dev->channel_attr_list);
i++;
if (ret == -EBUSY && ext_info->shared)
continue;
if (ret)
return ret;
attrcount++;
}
}
return attrcount;
}
void iio_free_chan_devattr_list(struct list_head *attr_list)
{
struct iio_dev_attr *p, *n;
list_for_each_entry_safe(p, n, attr_list, l) {
kfree(p->dev_attr.attr.name);
list_del(&p->l);
kfree(p);
}
}
static ssize_t iio_show_dev_name(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
return snprintf(buf, PAGE_SIZE, "%s\n", indio_dev->name);
}
static ssize_t iio_show_timestamp_clock(struct device *dev,
struct device_attribute *attr,
char *buf)
{
const struct iio_dev *indio_dev = dev_to_iio_dev(dev);
const clockid_t clk = iio_device_get_clock(indio_dev);
const char *name;
ssize_t sz;
switch (clk) {
case CLOCK_REALTIME:
name = "realtime\n";
sz = sizeof("realtime\n");
break;
case CLOCK_MONOTONIC:
name = "monotonic\n";
sz = sizeof("monotonic\n");
break;
case CLOCK_MONOTONIC_RAW:
name = "monotonic_raw\n";
sz = sizeof("monotonic_raw\n");
break;
case CLOCK_REALTIME_COARSE:
name = "realtime_coarse\n";
sz = sizeof("realtime_coarse\n");
break;
case CLOCK_MONOTONIC_COARSE:
name = "monotonic_coarse\n";
sz = sizeof("monotonic_coarse\n");
break;
case CLOCK_BOOTTIME:
name = "boottime\n";
sz = sizeof("boottime\n");
break;
case CLOCK_TAI:
name = "tai\n";
sz = sizeof("tai\n");
break;
default:
BUG();
}
memcpy(buf, name, sz);
return sz;
}
static ssize_t iio_store_timestamp_clock(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
clockid_t clk;
int ret;
if (sysfs_streq(buf, "realtime"))
clk = CLOCK_REALTIME;
else if (sysfs_streq(buf, "monotonic"))
clk = CLOCK_MONOTONIC;
else if (sysfs_streq(buf, "monotonic_raw"))
clk = CLOCK_MONOTONIC_RAW;
else if (sysfs_streq(buf, "realtime_coarse"))
clk = CLOCK_REALTIME_COARSE;
else if (sysfs_streq(buf, "monotonic_coarse"))
clk = CLOCK_MONOTONIC_COARSE;
else if (sysfs_streq(buf, "boottime"))
clk = CLOCK_BOOTTIME;
else if (sysfs_streq(buf, "tai"))
clk = CLOCK_TAI;
else
return -EINVAL;
ret = iio_device_set_clock(dev_to_iio_dev(dev), clk);
if (ret)
return ret;
return len;
}
static int iio_device_register_sysfs(struct iio_dev *indio_dev)
{
int i, ret = 0, attrcount, attrn, attrcount_orig = 0;
struct iio_dev_attr *p;
struct attribute **attr, *clk = NULL;
if (indio_dev->info->attrs) {
attr = indio_dev->info->attrs->attrs;
while (*attr++ != NULL)
attrcount_orig++;
}
attrcount = attrcount_orig;
if (indio_dev->channels)
for (i = 0; i < indio_dev->num_channels; i++) {
const struct iio_chan_spec *chan =
&indio_dev->channels[i];
if (chan->type == IIO_TIMESTAMP)
clk = &dev_attr_current_timestamp_clock.attr;
ret = iio_device_add_channel_sysfs(indio_dev, chan);
if (ret < 0)
goto error_clear_attrs;
attrcount += ret;
}
if (indio_dev->event_interface)
clk = &dev_attr_current_timestamp_clock.attr;
if (indio_dev->name)
attrcount++;
if (clk)
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
if (clk)
indio_dev->chan_attr_group.attrs[attrn++] = clk;
indio_dev->groups[indio_dev->groupcounter++] =
&indio_dev->chan_attr_group;
return 0;
error_clear_attrs:
iio_free_chan_devattr_list(&indio_dev->channel_attr_list);
return ret;
}
static void iio_device_unregister_sysfs(struct iio_dev *indio_dev)
{
iio_free_chan_devattr_list(&indio_dev->channel_attr_list);
kfree(indio_dev->chan_attr_group.attrs);
indio_dev->chan_attr_group.attrs = NULL;
}
static void iio_dev_release(struct device *device)
{
struct iio_dev *indio_dev = dev_to_iio_dev(device);
if (indio_dev->modes & (INDIO_BUFFER_TRIGGERED | INDIO_EVENT_TRIGGERED))
iio_device_unregister_trigger_consumer(indio_dev);
iio_device_unregister_eventset(indio_dev);
iio_device_unregister_sysfs(indio_dev);
iio_buffer_put(indio_dev->buffer);
ida_simple_remove(&iio_ida, indio_dev->id);
kfree(indio_dev);
}
struct iio_dev *iio_device_alloc(int sizeof_priv)
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
dev->dev.type = &iio_device_type;
dev->dev.bus = &iio_bus_type;
device_initialize(&dev->dev);
dev_set_drvdata(&dev->dev, (void *)dev);
mutex_init(&dev->mlock);
mutex_init(&dev->info_exist_lock);
INIT_LIST_HEAD(&dev->channel_attr_list);
dev->id = ida_simple_get(&iio_ida, 0, 0, GFP_KERNEL);
if (dev->id < 0) {
pr_err("failed to get device id\n");
kfree(dev);
return NULL;
}
dev_set_name(&dev->dev, "iio:device%d", dev->id);
INIT_LIST_HEAD(&dev->buffer_list);
}
return dev;
}
void iio_device_free(struct iio_dev *dev)
{
if (dev)
put_device(&dev->dev);
}
static void devm_iio_device_release(struct device *dev, void *res)
{
iio_device_free(*(struct iio_dev **)res);
}
static int devm_iio_device_match(struct device *dev, void *res, void *data)
{
struct iio_dev **r = res;
if (!r || !*r) {
WARN_ON(!r || !*r);
return 0;
}
return *r == data;
}
struct iio_dev *devm_iio_device_alloc(struct device *dev, int sizeof_priv)
{
struct iio_dev **ptr, *iio_dev;
ptr = devres_alloc(devm_iio_device_release, sizeof(*ptr),
GFP_KERNEL);
if (!ptr)
return NULL;
iio_dev = iio_device_alloc(sizeof_priv);
if (iio_dev) {
*ptr = iio_dev;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return iio_dev;
}
void devm_iio_device_free(struct device *dev, struct iio_dev *iio_dev)
{
int rc;
rc = devres_release(dev, devm_iio_device_release,
devm_iio_device_match, iio_dev);
WARN_ON(rc);
}
static int iio_chrdev_open(struct inode *inode, struct file *filp)
{
struct iio_dev *indio_dev = container_of(inode->i_cdev,
struct iio_dev, chrdev);
if (test_and_set_bit(IIO_BUSY_BIT_POS, &indio_dev->flags))
return -EBUSY;
iio_device_get(indio_dev);
filp->private_data = indio_dev;
return 0;
}
static int iio_chrdev_release(struct inode *inode, struct file *filp)
{
struct iio_dev *indio_dev = container_of(inode->i_cdev,
struct iio_dev, chrdev);
clear_bit(IIO_BUSY_BIT_POS, &indio_dev->flags);
iio_device_put(indio_dev);
return 0;
}
static long iio_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
struct iio_dev *indio_dev = filp->private_data;
int __user *ip = (int __user *)arg;
int fd;
if (!indio_dev->info)
return -ENODEV;
if (cmd == IIO_GET_EVENT_FD_IOCTL) {
fd = iio_event_getfd(indio_dev);
if (fd < 0)
return fd;
if (copy_to_user(ip, &fd, sizeof(fd)))
return -EFAULT;
return 0;
}
return -EINVAL;
}
static int iio_check_unique_scan_index(struct iio_dev *indio_dev)
{
int i, j;
const struct iio_chan_spec *channels = indio_dev->channels;
if (!(indio_dev->modes & INDIO_ALL_BUFFER_MODES))
return 0;
for (i = 0; i < indio_dev->num_channels - 1; i++) {
if (channels[i].scan_index < 0)
continue;
for (j = i + 1; j < indio_dev->num_channels; j++)
if (channels[i].scan_index == channels[j].scan_index) {
dev_err(&indio_dev->dev,
"Duplicate scan index %d\n",
channels[i].scan_index);
return -EINVAL;
}
}
return 0;
}
int iio_device_register(struct iio_dev *indio_dev)
{
int ret;
if (!indio_dev->dev.of_node && indio_dev->dev.parent)
indio_dev->dev.of_node = indio_dev->dev.parent->of_node;
ret = iio_check_unique_scan_index(indio_dev);
if (ret < 0)
return ret;
indio_dev->dev.devt = MKDEV(MAJOR(iio_devt), indio_dev->id);
ret = iio_device_register_debugfs(indio_dev);
if (ret) {
dev_err(indio_dev->dev.parent,
"Failed to register debugfs interfaces\n");
return ret;
}
ret = iio_buffer_alloc_sysfs_and_mask(indio_dev);
if (ret) {
dev_err(indio_dev->dev.parent,
"Failed to create buffer sysfs interfaces\n");
goto error_unreg_debugfs;
}
ret = iio_device_register_sysfs(indio_dev);
if (ret) {
dev_err(indio_dev->dev.parent,
"Failed to register sysfs interfaces\n");
goto error_buffer_free_sysfs;
}
ret = iio_device_register_eventset(indio_dev);
if (ret) {
dev_err(indio_dev->dev.parent,
"Failed to register event set\n");
goto error_free_sysfs;
}
if (indio_dev->modes & (INDIO_BUFFER_TRIGGERED | INDIO_EVENT_TRIGGERED))
iio_device_register_trigger_consumer(indio_dev);
if ((indio_dev->modes & INDIO_ALL_BUFFER_MODES) &&
indio_dev->setup_ops == NULL)
indio_dev->setup_ops = &noop_ring_setup_ops;
cdev_init(&indio_dev->chrdev, &iio_buffer_fileops);
indio_dev->chrdev.owner = indio_dev->info->driver_module;
indio_dev->chrdev.kobj.parent = &indio_dev->dev.kobj;
ret = cdev_add(&indio_dev->chrdev, indio_dev->dev.devt, 1);
if (ret < 0)
goto error_unreg_eventset;
ret = device_add(&indio_dev->dev);
if (ret < 0)
goto error_cdev_del;
return 0;
error_cdev_del:
cdev_del(&indio_dev->chrdev);
error_unreg_eventset:
iio_device_unregister_eventset(indio_dev);
error_free_sysfs:
iio_device_unregister_sysfs(indio_dev);
error_buffer_free_sysfs:
iio_buffer_free_sysfs_and_mask(indio_dev);
error_unreg_debugfs:
iio_device_unregister_debugfs(indio_dev);
return ret;
}
void iio_device_unregister(struct iio_dev *indio_dev)
{
mutex_lock(&indio_dev->info_exist_lock);
device_del(&indio_dev->dev);
if (indio_dev->chrdev.dev)
cdev_del(&indio_dev->chrdev);
iio_device_unregister_debugfs(indio_dev);
iio_disable_all_buffers(indio_dev);
indio_dev->info = NULL;
iio_device_wakeup_eventset(indio_dev);
iio_buffer_wakeup_poll(indio_dev);
mutex_unlock(&indio_dev->info_exist_lock);
iio_buffer_free_sysfs_and_mask(indio_dev);
}
static void devm_iio_device_unreg(struct device *dev, void *res)
{
iio_device_unregister(*(struct iio_dev **)res);
}
int devm_iio_device_register(struct device *dev, struct iio_dev *indio_dev)
{
struct iio_dev **ptr;
int ret;
ptr = devres_alloc(devm_iio_device_unreg, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return -ENOMEM;
*ptr = indio_dev;
ret = iio_device_register(indio_dev);
if (!ret)
devres_add(dev, ptr);
else
devres_free(ptr);
return ret;
}
void devm_iio_device_unregister(struct device *dev, struct iio_dev *indio_dev)
{
int rc;
rc = devres_release(dev, devm_iio_device_unreg,
devm_iio_device_match, indio_dev);
WARN_ON(rc);
}
int iio_device_claim_direct_mode(struct iio_dev *indio_dev)
{
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
return 0;
}
void iio_device_release_direct_mode(struct iio_dev *indio_dev)
{
mutex_unlock(&indio_dev->mlock);
}
