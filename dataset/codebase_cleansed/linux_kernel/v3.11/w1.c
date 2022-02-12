static int w1_master_match(struct device *dev, struct device_driver *drv)
{
return 1;
}
static int w1_master_probe(struct device *dev)
{
return -ENODEV;
}
static void w1_master_release(struct device *dev)
{
struct w1_master *md = dev_to_w1_master(dev);
dev_dbg(dev, "%s: Releasing %s.\n", __func__, md->name);
memset(md, 0, sizeof(struct w1_master) + sizeof(struct w1_bus_master));
kfree(md);
}
static void w1_slave_release(struct device *dev)
{
struct w1_slave *sl = dev_to_w1_slave(dev);
dev_dbg(dev, "%s: Releasing %s.\n", __func__, sl->name);
while (atomic_read(&sl->refcnt)) {
dev_dbg(dev, "Waiting for %s to become free: refcnt=%d.\n",
sl->name, atomic_read(&sl->refcnt));
if (msleep_interruptible(1000))
flush_signals(current);
}
w1_family_put(sl->family);
sl->master->slave_count--;
complete(&sl->released);
}
static ssize_t w1_slave_read_name(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w1_slave *sl = dev_to_w1_slave(dev);
return sprintf(buf, "%s\n", sl->name);
}
static ssize_t w1_slave_read_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct w1_slave *sl = dev_to_w1_slave(dev);
ssize_t count = sizeof(sl->reg_num);
memcpy(buf, (u8 *)&sl->reg_num, count);
return count;
}
static ssize_t w1_default_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
mutex_lock(&sl->master->mutex);
if (w1_reset_select_slave(sl)) {
count = 0;
goto out_up;
}
w1_write_block(sl->master, buf, count);
out_up:
mutex_unlock(&sl->master->mutex);
return count;
}
static ssize_t w1_default_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
mutex_lock(&sl->master->mutex);
w1_read_block(sl->master, buf, count);
mutex_unlock(&sl->master->mutex);
return count;
}
static int w1_default_add_slave(struct w1_slave *sl)
{
return sysfs_create_bin_file(&sl->dev.kobj, &w1_default_attr);
}
static void w1_default_remove_slave(struct w1_slave *sl)
{
sysfs_remove_bin_file(&sl->dev.kobj, &w1_default_attr);
}
static ssize_t w1_master_attribute_show_name(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w1_master *md = dev_to_w1_master(dev);
ssize_t count;
mutex_lock(&md->mutex);
count = sprintf(buf, "%s\n", md->name);
mutex_unlock(&md->mutex);
return count;
}
static ssize_t w1_master_attribute_store_search(struct device * dev,
struct device_attribute *attr,
const char * buf, size_t count)
{
long tmp;
struct w1_master *md = dev_to_w1_master(dev);
if (strict_strtol(buf, 0, &tmp) == -EINVAL)
return -EINVAL;
mutex_lock(&md->mutex);
md->search_count = tmp;
mutex_unlock(&md->mutex);
wake_up_process(md->thread);
return count;
}
static ssize_t w1_master_attribute_show_search(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct w1_master *md = dev_to_w1_master(dev);
ssize_t count;
mutex_lock(&md->mutex);
count = sprintf(buf, "%d\n", md->search_count);
mutex_unlock(&md->mutex);
return count;
}
static ssize_t w1_master_attribute_store_pullup(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
long tmp;
struct w1_master *md = dev_to_w1_master(dev);
if (strict_strtol(buf, 0, &tmp) == -EINVAL)
return -EINVAL;
mutex_lock(&md->mutex);
md->enable_pullup = tmp;
mutex_unlock(&md->mutex);
wake_up_process(md->thread);
return count;
}
static ssize_t w1_master_attribute_show_pullup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct w1_master *md = dev_to_w1_master(dev);
ssize_t count;
mutex_lock(&md->mutex);
count = sprintf(buf, "%d\n", md->enable_pullup);
mutex_unlock(&md->mutex);
return count;
}
static ssize_t w1_master_attribute_show_pointer(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w1_master *md = dev_to_w1_master(dev);
ssize_t count;
mutex_lock(&md->mutex);
count = sprintf(buf, "0x%p\n", md->bus_master);
mutex_unlock(&md->mutex);
return count;
}
static ssize_t w1_master_attribute_show_timeout(struct device *dev, struct device_attribute *attr, char *buf)
{
ssize_t count;
count = sprintf(buf, "%d\n", w1_timeout);
return count;
}
static ssize_t w1_master_attribute_show_max_slave_count(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w1_master *md = dev_to_w1_master(dev);
ssize_t count;
mutex_lock(&md->mutex);
count = sprintf(buf, "%d\n", md->max_slave_count);
mutex_unlock(&md->mutex);
return count;
}
static ssize_t w1_master_attribute_show_attempts(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w1_master *md = dev_to_w1_master(dev);
ssize_t count;
mutex_lock(&md->mutex);
count = sprintf(buf, "%lu\n", md->attempts);
mutex_unlock(&md->mutex);
return count;
}
static ssize_t w1_master_attribute_show_slave_count(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w1_master *md = dev_to_w1_master(dev);
ssize_t count;
mutex_lock(&md->mutex);
count = sprintf(buf, "%d\n", md->slave_count);
mutex_unlock(&md->mutex);
return count;
}
static ssize_t w1_master_attribute_show_slaves(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct w1_master *md = dev_to_w1_master(dev);
int c = PAGE_SIZE;
mutex_lock(&md->mutex);
if (md->slave_count == 0)
c -= snprintf(buf + PAGE_SIZE - c, c, "not found.\n");
else {
struct list_head *ent, *n;
struct w1_slave *sl;
list_for_each_safe(ent, n, &md->slist) {
sl = list_entry(ent, struct w1_slave, w1_slave_entry);
c -= snprintf(buf + PAGE_SIZE - c, c, "%s\n", sl->name);
}
}
mutex_unlock(&md->mutex);
return PAGE_SIZE - c;
}
static ssize_t w1_master_attribute_show_add(struct device *dev,
struct device_attribute *attr, char *buf)
{
int c = PAGE_SIZE;
c -= snprintf(buf+PAGE_SIZE - c, c,
"write device id xx-xxxxxxxxxxxx to add slave\n");
return PAGE_SIZE - c;
}
static int w1_atoreg_num(struct device *dev, const char *buf, size_t count,
struct w1_reg_num *rn)
{
unsigned int family;
unsigned long long id;
int i;
u64 rn64_le;
const char *error_msg = "bad slave string format, expecting "
"ff-dddddddddddd\n";
if (buf[2] != '-') {
dev_err(dev, "%s", error_msg);
return -EINVAL;
}
i = sscanf(buf, "%02x-%012llx", &family, &id);
if (i != 2) {
dev_err(dev, "%s", error_msg);
return -EINVAL;
}
rn->family = family;
rn->id = id;
rn64_le = cpu_to_le64(*(u64 *)rn);
rn->crc = w1_calc_crc8((u8 *)&rn64_le, 7);
#if 0
dev_info(dev, "With CRC device is %02x.%012llx.%02x.\n",
rn->family, (unsigned long long)rn->id, rn->crc);
#endif
return 0;
}
static struct w1_slave *w1_slave_search_device(struct w1_master *dev,
struct w1_reg_num *rn)
{
struct w1_slave *sl;
list_for_each_entry(sl, &dev->slist, w1_slave_entry) {
if (sl->reg_num.family == rn->family &&
sl->reg_num.id == rn->id &&
sl->reg_num.crc == rn->crc) {
return sl;
}
}
return NULL;
}
static ssize_t w1_master_attribute_store_add(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct w1_master *md = dev_to_w1_master(dev);
struct w1_reg_num rn;
struct w1_slave *sl;
ssize_t result = count;
if (w1_atoreg_num(dev, buf, count, &rn))
return -EINVAL;
mutex_lock(&md->mutex);
sl = w1_slave_search_device(md, &rn);
if (sl) {
dev_info(dev, "Device %s already exists\n", sl->name);
result = -EINVAL;
} else {
w1_attach_slave_device(md, &rn);
}
mutex_unlock(&md->mutex);
return result;
}
static ssize_t w1_master_attribute_show_remove(struct device *dev,
struct device_attribute *attr, char *buf)
{
int c = PAGE_SIZE;
c -= snprintf(buf+PAGE_SIZE - c, c,
"write device id xx-xxxxxxxxxxxx to remove slave\n");
return PAGE_SIZE - c;
}
static ssize_t w1_master_attribute_store_remove(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct w1_master *md = dev_to_w1_master(dev);
struct w1_reg_num rn;
struct w1_slave *sl;
ssize_t result = count;
if (w1_atoreg_num(dev, buf, count, &rn))
return -EINVAL;
mutex_lock(&md->mutex);
sl = w1_slave_search_device(md, &rn);
if (sl) {
w1_slave_detach(sl);
} else {
dev_info(dev, "Device %02x-%012llx doesn't exists\n", rn.family,
(unsigned long long)rn.id);
result = -EINVAL;
}
mutex_unlock(&md->mutex);
return result;
}
int w1_create_master_attributes(struct w1_master *master)
{
return sysfs_create_group(&master->dev.kobj, &w1_master_defattr_group);
}
void w1_destroy_master_attributes(struct w1_master *master)
{
sysfs_remove_group(&master->dev.kobj, &w1_master_defattr_group);
}
static int w1_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct w1_master *md = NULL;
struct w1_slave *sl = NULL;
char *event_owner, *name;
int err = 0;
if (dev->driver == &w1_master_driver) {
md = container_of(dev, struct w1_master, dev);
event_owner = "master";
name = md->name;
} else if (dev->driver == &w1_slave_driver) {
sl = container_of(dev, struct w1_slave, dev);
event_owner = "slave";
name = sl->name;
} else {
dev_dbg(dev, "Unknown event.\n");
return -EINVAL;
}
dev_dbg(dev, "Hotplug event for %s %s, bus_id=%s.\n",
event_owner, name, dev_name(dev));
if (dev->driver != &w1_slave_driver || !sl)
goto end;
err = add_uevent_var(env, "W1_FID=%02X", sl->reg_num.family);
if (err)
goto end;
err = add_uevent_var(env, "W1_SLAVE_ID=%024LX",
(unsigned long long)sl->reg_num.id);
end:
return err;
}
static int __w1_attach_slave_device(struct w1_slave *sl)
{
int err;
sl->dev.parent = &sl->master->dev;
sl->dev.driver = &w1_slave_driver;
sl->dev.bus = &w1_bus_type;
sl->dev.release = &w1_slave_release;
dev_set_name(&sl->dev, "%02x-%012llx",
(unsigned int) sl->reg_num.family,
(unsigned long long) sl->reg_num.id);
snprintf(&sl->name[0], sizeof(sl->name),
"%02x-%012llx",
(unsigned int) sl->reg_num.family,
(unsigned long long) sl->reg_num.id);
dev_dbg(&sl->dev, "%s: registering %s as %p.\n", __func__,
dev_name(&sl->dev), sl);
err = device_register(&sl->dev);
if (err < 0) {
dev_err(&sl->dev,
"Device registration [%s] failed. err=%d\n",
dev_name(&sl->dev), err);
return err;
}
err = device_create_file(&sl->dev, &w1_slave_attr_name);
if (err < 0) {
dev_err(&sl->dev,
"sysfs file creation for [%s] failed. err=%d\n",
dev_name(&sl->dev), err);
goto out_unreg;
}
err = device_create_file(&sl->dev, &w1_slave_attr_id);
if (err < 0) {
dev_err(&sl->dev,
"sysfs file creation for [%s] failed. err=%d\n",
dev_name(&sl->dev), err);
goto out_rem1;
}
if (sl->family->fops && sl->family->fops->add_slave &&
((err = sl->family->fops->add_slave(sl)) < 0)) {
dev_err(&sl->dev,
"sysfs file creation for [%s] failed. err=%d\n",
dev_name(&sl->dev), err);
goto out_rem2;
}
list_add_tail(&sl->w1_slave_entry, &sl->master->slist);
return 0;
out_rem2:
device_remove_file(&sl->dev, &w1_slave_attr_id);
out_rem1:
device_remove_file(&sl->dev, &w1_slave_attr_name);
out_unreg:
device_unregister(&sl->dev);
return err;
}
static int w1_attach_slave_device(struct w1_master *dev, struct w1_reg_num *rn)
{
struct w1_slave *sl;
struct w1_family *f;
int err;
struct w1_netlink_msg msg;
sl = kzalloc(sizeof(struct w1_slave), GFP_KERNEL);
if (!sl) {
dev_err(&dev->dev,
"%s: failed to allocate new slave device.\n",
__func__);
return -ENOMEM;
}
sl->owner = THIS_MODULE;
sl->master = dev;
set_bit(W1_SLAVE_ACTIVE, (long *)&sl->flags);
memset(&msg, 0, sizeof(msg));
memcpy(&sl->reg_num, rn, sizeof(sl->reg_num));
atomic_set(&sl->refcnt, 0);
init_completion(&sl->released);
request_module("w1-family-0x%0x", rn->family);
spin_lock(&w1_flock);
f = w1_family_registered(rn->family);
if (!f) {
f= &w1_default_family;
dev_info(&dev->dev, "Family %x for %02x.%012llx.%02x is not registered.\n",
rn->family, rn->family,
(unsigned long long)rn->id, rn->crc);
}
__w1_family_get(f);
spin_unlock(&w1_flock);
sl->family = f;
err = __w1_attach_slave_device(sl);
if (err < 0) {
dev_err(&dev->dev, "%s: Attaching %s failed.\n", __func__,
sl->name);
w1_family_put(sl->family);
kfree(sl);
return err;
}
sl->ttl = dev->slave_ttl;
dev->slave_count++;
memcpy(msg.id.id, rn, sizeof(msg.id));
msg.type = W1_SLAVE_ADD;
w1_netlink_send(dev, &msg);
return 0;
}
void w1_slave_detach(struct w1_slave *sl)
{
struct w1_netlink_msg msg;
dev_dbg(&sl->dev, "%s: detaching %s [%p].\n", __func__, sl->name, sl);
list_del(&sl->w1_slave_entry);
if (sl->family->fops && sl->family->fops->remove_slave)
sl->family->fops->remove_slave(sl);
memset(&msg, 0, sizeof(msg));
memcpy(msg.id.id, &sl->reg_num, sizeof(msg.id));
msg.type = W1_SLAVE_REMOVE;
w1_netlink_send(sl->master, &msg);
device_remove_file(&sl->dev, &w1_slave_attr_id);
device_remove_file(&sl->dev, &w1_slave_attr_name);
device_unregister(&sl->dev);
wait_for_completion(&sl->released);
kfree(sl);
}
struct w1_master *w1_search_master_id(u32 id)
{
struct w1_master *dev;
int found = 0;
mutex_lock(&w1_mlock);
list_for_each_entry(dev, &w1_masters, w1_master_entry) {
if (dev->id == id) {
found = 1;
atomic_inc(&dev->refcnt);
break;
}
}
mutex_unlock(&w1_mlock);
return (found)?dev:NULL;
}
struct w1_slave *w1_search_slave(struct w1_reg_num *id)
{
struct w1_master *dev;
struct w1_slave *sl = NULL;
int found = 0;
mutex_lock(&w1_mlock);
list_for_each_entry(dev, &w1_masters, w1_master_entry) {
mutex_lock(&dev->mutex);
list_for_each_entry(sl, &dev->slist, w1_slave_entry) {
if (sl->reg_num.family == id->family &&
sl->reg_num.id == id->id &&
sl->reg_num.crc == id->crc) {
found = 1;
atomic_inc(&dev->refcnt);
atomic_inc(&sl->refcnt);
break;
}
}
mutex_unlock(&dev->mutex);
if (found)
break;
}
mutex_unlock(&w1_mlock);
return (found)?sl:NULL;
}
void w1_reconnect_slaves(struct w1_family *f, int attach)
{
struct w1_slave *sl, *sln;
struct w1_master *dev;
mutex_lock(&w1_mlock);
list_for_each_entry(dev, &w1_masters, w1_master_entry) {
dev_dbg(&dev->dev, "Reconnecting slaves in device %s "
"for family %02x.\n", dev->name, f->fid);
mutex_lock(&dev->mutex);
list_for_each_entry_safe(sl, sln, &dev->slist, w1_slave_entry) {
if ((attach && sl->family->fid == W1_FAMILY_DEFAULT
&& sl->reg_num.family == f->fid) ||
(!attach && sl->family->fid == f->fid)) {
struct w1_reg_num rn;
memcpy(&rn, &sl->reg_num, sizeof(rn));
w1_slave_detach(sl);
w1_attach_slave_device(dev, &rn);
}
}
dev_dbg(&dev->dev, "Reconnecting slaves in device %s "
"has been finished.\n", dev->name);
mutex_unlock(&dev->mutex);
}
mutex_unlock(&w1_mlock);
}
void w1_slave_found(struct w1_master *dev, u64 rn)
{
struct w1_slave *sl;
struct w1_reg_num *tmp;
u64 rn_le = cpu_to_le64(rn);
atomic_inc(&dev->refcnt);
tmp = (struct w1_reg_num *) &rn;
sl = w1_slave_search_device(dev, tmp);
if (sl) {
set_bit(W1_SLAVE_ACTIVE, (long *)&sl->flags);
} else {
if (rn && tmp->crc == w1_calc_crc8((u8 *)&rn_le, 7))
w1_attach_slave_device(dev, tmp);
}
atomic_dec(&dev->refcnt);
}
void w1_search(struct w1_master *dev, u8 search_type, w1_slave_found_callback cb)
{
u64 last_rn, rn, tmp64;
int i, slave_count = 0;
int last_zero, last_device;
int search_bit, desc_bit;
u8 triplet_ret = 0;
search_bit = 0;
rn = last_rn = 0;
last_device = 0;
last_zero = -1;
desc_bit = 64;
while ( !last_device && (slave_count++ < dev->max_slave_count) ) {
last_rn = rn;
rn = 0;
mutex_lock(&dev->bus_mutex);
if (w1_reset_bus(dev)) {
mutex_unlock(&dev->bus_mutex);
dev_dbg(&dev->dev, "No devices present on the wire.\n");
break;
}
if (dev->max_slave_count == 1) {
int rv;
w1_write_8(dev, W1_READ_ROM);
rv = w1_read_block(dev, (u8 *)&rn, 8);
mutex_unlock(&dev->bus_mutex);
if (rv == 8 && rn)
cb(dev, rn);
break;
}
w1_write_8(dev, search_type);
for (i = 0; i < 64; ++i) {
if (i == desc_bit)
search_bit = 1;
else if (i > desc_bit)
search_bit = 0;
else
search_bit = ((last_rn >> i) & 0x1);
triplet_ret = w1_triplet(dev, search_bit);
if ( (triplet_ret & 0x03) == 0x03 )
break;
if (triplet_ret == 0)
last_zero = i;
tmp64 = (triplet_ret >> 2);
rn |= (tmp64 << i);
if (!dev->priv && kthread_should_stop()) {
mutex_unlock(&dev->bus_mutex);
dev_dbg(&dev->dev, "Abort w1_search\n");
return;
}
}
mutex_unlock(&dev->bus_mutex);
if ( (triplet_ret & 0x03) != 0x03 ) {
if ( (desc_bit == last_zero) || (last_zero < 0))
last_device = 1;
desc_bit = last_zero;
cb(dev, rn);
}
}
}
void w1_search_process_cb(struct w1_master *dev, u8 search_type,
w1_slave_found_callback cb)
{
struct w1_slave *sl, *sln;
list_for_each_entry(sl, &dev->slist, w1_slave_entry)
clear_bit(W1_SLAVE_ACTIVE, (long *)&sl->flags);
w1_search_devices(dev, search_type, cb);
list_for_each_entry_safe(sl, sln, &dev->slist, w1_slave_entry) {
if (!test_bit(W1_SLAVE_ACTIVE, (unsigned long *)&sl->flags) && !--sl->ttl)
w1_slave_detach(sl);
else if (test_bit(W1_SLAVE_ACTIVE, (unsigned long *)&sl->flags))
sl->ttl = dev->slave_ttl;
}
if (dev->search_count > 0)
dev->search_count--;
}
static void w1_search_process(struct w1_master *dev, u8 search_type)
{
w1_search_process_cb(dev, search_type, w1_slave_found);
}
int w1_process(void *data)
{
struct w1_master *dev = (struct w1_master *) data;
const unsigned long jtime = msecs_to_jiffies(w1_timeout * 1000);
while (!kthread_should_stop()) {
if (dev->search_count) {
mutex_lock(&dev->mutex);
w1_search_process(dev, W1_SEARCH);
mutex_unlock(&dev->mutex);
}
try_to_freeze();
__set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop())
break;
if (dev->search_count)
schedule_timeout(jtime);
else
schedule();
}
atomic_dec(&dev->refcnt);
return 0;
}
static int __init w1_init(void)
{
int retval;
printk(KERN_INFO "Driver for 1-wire Dallas network protocol.\n");
w1_init_netlink();
retval = bus_register(&w1_bus_type);
if (retval) {
printk(KERN_ERR "Failed to register bus. err=%d.\n", retval);
goto err_out_exit_init;
}
retval = driver_register(&w1_master_driver);
if (retval) {
printk(KERN_ERR
"Failed to register master driver. err=%d.\n",
retval);
goto err_out_bus_unregister;
}
retval = driver_register(&w1_slave_driver);
if (retval) {
printk(KERN_ERR
"Failed to register slave driver. err=%d.\n",
retval);
goto err_out_master_unregister;
}
return 0;
#if 0
err_out_slave_unregister:
driver_unregister(&w1_slave_driver);
#endif
err_out_master_unregister:
driver_unregister(&w1_master_driver);
err_out_bus_unregister:
bus_unregister(&w1_bus_type);
err_out_exit_init:
return retval;
}
static void __exit w1_fini(void)
{
struct w1_master *dev;
list_for_each_entry(dev, &w1_masters, w1_master_entry)
__w1_remove_master_device(dev);
w1_fini_netlink();
driver_unregister(&w1_slave_driver);
driver_unregister(&w1_master_driver);
bus_unregister(&w1_bus_type);
}
