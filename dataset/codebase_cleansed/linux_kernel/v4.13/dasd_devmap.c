static inline int
dasd_hash_busid(const char *bus_id)
{
int hash, i;
hash = 0;
for (i = 0; (i < DASD_BUS_ID_SIZE) && *bus_id; i++, bus_id++)
hash += *bus_id;
return hash & 0xff;
}
static int __init dasd_call_setup(char *opt)
{
static int i __initdata;
char *tmp;
while (i < DASD_MAX_PARAMS) {
tmp = strsep(&opt, ",");
if (!tmp)
break;
dasd[i++] = tmp;
}
return 1;
}
static int __init dasd_busid(char *str, int *id0, int *id1, int *devno)
{
unsigned int val;
char *tok;
if (strncmp(DASD_IPLDEV, str, strlen(DASD_IPLDEV)) == 0) {
if (ipl_info.type != IPL_TYPE_CCW) {
pr_err("The IPL device is not a CCW device\n");
return -EINVAL;
}
*id0 = 0;
*id1 = ipl_info.data.ccw.dev_id.ssid;
*devno = ipl_info.data.ccw.dev_id.devno;
return 0;
}
if (!kstrtouint(str, 16, &val)) {
*id0 = *id1 = 0;
if (val > 0xffff)
return -EINVAL;
*devno = val;
return 0;
}
tok = strsep(&str, ".");
if (kstrtouint(tok, 16, &val) || val > 0xff)
return -EINVAL;
*id0 = val;
tok = strsep(&str, ".");
if (kstrtouint(tok, 16, &val) || val > 0xff)
return -EINVAL;
*id1 = val;
tok = strsep(&str, ".");
if (kstrtouint(tok, 16, &val) || val > 0xffff)
return -EINVAL;
*devno = val;
return 0;
}
static int __init dasd_feature_list(char *str)
{
int features, len, rc;
features = 0;
rc = 0;
if (!str)
return DASD_FEATURE_DEFAULT;
while (1) {
for (len = 0;
str[len] && str[len] != ':' && str[len] != ')'; len++);
if (len == 2 && !strncmp(str, "ro", 2))
features |= DASD_FEATURE_READONLY;
else if (len == 4 && !strncmp(str, "diag", 4))
features |= DASD_FEATURE_USEDIAG;
else if (len == 3 && !strncmp(str, "raw", 3))
features |= DASD_FEATURE_USERAW;
else if (len == 6 && !strncmp(str, "erplog", 6))
features |= DASD_FEATURE_ERPLOG;
else if (len == 8 && !strncmp(str, "failfast", 8))
features |= DASD_FEATURE_FAILFAST;
else {
pr_warn("%*s is not a supported device option\n",
len, str);
rc = -EINVAL;
}
str += len;
if (*str != ':')
break;
str++;
}
return rc ? : features;
}
static int __init dasd_parse_keyword(char *keyword)
{
int length = strlen(keyword);
if (strncmp("autodetect", keyword, length) == 0) {
dasd_autodetect = 1;
pr_info("The autodetection mode has been activated\n");
return 0;
}
if (strncmp("probeonly", keyword, length) == 0) {
dasd_probeonly = 1;
pr_info("The probeonly mode has been activated\n");
return 0;
}
if (strncmp("nopav", keyword, length) == 0) {
if (MACHINE_IS_VM)
pr_info("'nopav' is not supported on z/VM\n");
else {
dasd_nopav = 1;
pr_info("PAV support has be deactivated\n");
}
return 0;
}
if (strncmp("nofcx", keyword, length) == 0) {
dasd_nofcx = 1;
pr_info("High Performance FICON support has been "
"deactivated\n");
return 0;
}
if (strncmp("fixedbuffers", keyword, length) == 0) {
if (dasd_page_cache)
return 0;
dasd_page_cache =
kmem_cache_create("dasd_page_cache", PAGE_SIZE,
PAGE_SIZE, SLAB_CACHE_DMA,
NULL);
if (!dasd_page_cache)
DBF_EVENT(DBF_WARNING, "%s", "Failed to create slab, "
"fixed buffer mode disabled.");
else
DBF_EVENT(DBF_INFO, "%s",
"turning on fixed buffer mode");
return 0;
}
return -EINVAL;
}
static int __init dasd_evaluate_range_param(char *range, char **from_str,
char **to_str, char **features_str)
{
int rc = 0;
if (strchr(range, '-')) {
*from_str = strsep(&range, "-");
*to_str = strsep(&range, "(");
*features_str = strsep(&range, ")");
} else {
*from_str = strsep(&range, "(");
*features_str = strsep(&range, ")");
}
if (*features_str && !range) {
pr_warn("A closing parenthesis ')' is missing in the dasd= parameter\n");
rc = -EINVAL;
}
return rc;
}
static int __init dasd_parse_range(const char *range)
{
struct dasd_devmap *devmap;
int from, from_id0, from_id1;
int to, to_id0, to_id1;
int features;
char bus_id[DASD_BUS_ID_SIZE + 1];
char *features_str = NULL;
char *from_str = NULL;
char *to_str = NULL;
int rc = 0;
char *tmp;
tmp = kstrdup(range, GFP_KERNEL);
if (!tmp)
return -ENOMEM;
if (dasd_evaluate_range_param(tmp, &from_str, &to_str, &features_str)) {
rc = -EINVAL;
goto out;
}
if (dasd_busid(from_str, &from_id0, &from_id1, &from)) {
rc = -EINVAL;
goto out;
}
to = from;
to_id0 = from_id0;
to_id1 = from_id1;
if (to_str) {
if (dasd_busid(to_str, &to_id0, &to_id1, &to)) {
rc = -EINVAL;
goto out;
}
if (from_id0 != to_id0 || from_id1 != to_id1 || from > to) {
pr_err("%s is not a valid device range\n", range);
rc = -EINVAL;
goto out;
}
}
features = dasd_feature_list(features_str);
if (features < 0) {
rc = -EINVAL;
goto out;
}
features |= DASD_FEATURE_INITIAL_ONLINE;
while (from <= to) {
sprintf(bus_id, "%01x.%01x.%04x", from_id0, from_id1, from++);
devmap = dasd_add_busid(bus_id, features);
if (IS_ERR(devmap)) {
rc = PTR_ERR(devmap);
goto out;
}
}
out:
kfree(tmp);
return rc;
}
int __init dasd_parse(void)
{
int rc, i;
char *cur;
rc = 0;
for (i = 0; i < DASD_MAX_PARAMS; i++) {
cur = dasd[i];
if (!cur)
break;
if (*cur == '\0')
continue;
rc = dasd_parse_keyword(cur);
if (rc)
rc = dasd_parse_range(cur);
if (rc)
break;
}
return rc;
}
static struct dasd_devmap *
dasd_add_busid(const char *bus_id, int features)
{
struct dasd_devmap *devmap, *new, *tmp;
int hash;
new = kzalloc(sizeof(struct dasd_devmap), GFP_KERNEL);
if (!new)
return ERR_PTR(-ENOMEM);
spin_lock(&dasd_devmap_lock);
devmap = NULL;
hash = dasd_hash_busid(bus_id);
list_for_each_entry(tmp, &dasd_hashlists[hash], list)
if (strncmp(tmp->bus_id, bus_id, DASD_BUS_ID_SIZE) == 0) {
devmap = tmp;
break;
}
if (!devmap) {
new->devindex = dasd_max_devindex++;
strncpy(new->bus_id, bus_id, DASD_BUS_ID_SIZE);
new->features = features;
new->device = NULL;
list_add(&new->list, &dasd_hashlists[hash]);
devmap = new;
new = NULL;
}
spin_unlock(&dasd_devmap_lock);
kfree(new);
return devmap;
}
static struct dasd_devmap *
dasd_find_busid(const char *bus_id)
{
struct dasd_devmap *devmap, *tmp;
int hash;
spin_lock(&dasd_devmap_lock);
devmap = ERR_PTR(-ENODEV);
hash = dasd_hash_busid(bus_id);
list_for_each_entry(tmp, &dasd_hashlists[hash], list) {
if (strncmp(tmp->bus_id, bus_id, DASD_BUS_ID_SIZE) == 0) {
devmap = tmp;
break;
}
}
spin_unlock(&dasd_devmap_lock);
return devmap;
}
int
dasd_busid_known(const char *bus_id)
{
return IS_ERR(dasd_find_busid(bus_id)) ? -ENOENT : 0;
}
static void
dasd_forget_ranges(void)
{
struct dasd_devmap *devmap, *n;
int i;
spin_lock(&dasd_devmap_lock);
for (i = 0; i < 256; i++) {
list_for_each_entry_safe(devmap, n, &dasd_hashlists[i], list) {
BUG_ON(devmap->device != NULL);
list_del(&devmap->list);
kfree(devmap);
}
}
spin_unlock(&dasd_devmap_lock);
}
struct dasd_device *
dasd_device_from_devindex(int devindex)
{
struct dasd_devmap *devmap, *tmp;
struct dasd_device *device;
int i;
spin_lock(&dasd_devmap_lock);
devmap = NULL;
for (i = 0; (i < 256) && !devmap; i++)
list_for_each_entry(tmp, &dasd_hashlists[i], list)
if (tmp->devindex == devindex) {
devmap = tmp;
break;
}
if (devmap && devmap->device) {
device = devmap->device;
dasd_get_device(device);
} else
device = ERR_PTR(-ENODEV);
spin_unlock(&dasd_devmap_lock);
return device;
}
static struct dasd_devmap *
dasd_devmap_from_cdev(struct ccw_device *cdev)
{
struct dasd_devmap *devmap;
devmap = dasd_find_busid(dev_name(&cdev->dev));
if (IS_ERR(devmap))
devmap = dasd_add_busid(dev_name(&cdev->dev),
DASD_FEATURE_DEFAULT);
return devmap;
}
struct dasd_device *
dasd_create_device(struct ccw_device *cdev)
{
struct dasd_devmap *devmap;
struct dasd_device *device;
unsigned long flags;
int rc;
devmap = dasd_devmap_from_cdev(cdev);
if (IS_ERR(devmap))
return (void *) devmap;
device = dasd_alloc_device();
if (IS_ERR(device))
return device;
atomic_set(&device->ref_count, 3);
spin_lock(&dasd_devmap_lock);
if (!devmap->device) {
devmap->device = device;
device->devindex = devmap->devindex;
device->features = devmap->features;
get_device(&cdev->dev);
device->cdev = cdev;
rc = 0;
} else
rc = -EBUSY;
spin_unlock(&dasd_devmap_lock);
if (rc) {
dasd_free_device(device);
return ERR_PTR(rc);
}
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
dev_set_drvdata(&cdev->dev, device);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
return device;
}
void
dasd_delete_device(struct dasd_device *device)
{
struct ccw_device *cdev;
struct dasd_devmap *devmap;
unsigned long flags;
devmap = dasd_find_busid(dev_name(&device->cdev->dev));
BUG_ON(IS_ERR(devmap));
spin_lock(&dasd_devmap_lock);
if (devmap->device != device) {
spin_unlock(&dasd_devmap_lock);
dasd_put_device(device);
return;
}
devmap->device = NULL;
spin_unlock(&dasd_devmap_lock);
spin_lock_irqsave(get_ccwdev_lock(device->cdev), flags);
dev_set_drvdata(&device->cdev->dev, NULL);
spin_unlock_irqrestore(get_ccwdev_lock(device->cdev), flags);
atomic_sub(3, &device->ref_count);
wait_event(dasd_delete_wq, atomic_read(&device->ref_count) == 0);
dasd_generic_free_discipline(device);
cdev = device->cdev;
device->cdev = NULL;
put_device(&cdev->dev);
dasd_free_device(device);
}
void
dasd_put_device_wake(struct dasd_device *device)
{
wake_up(&dasd_delete_wq);
}
struct dasd_device *
dasd_device_from_cdev_locked(struct ccw_device *cdev)
{
struct dasd_device *device = dev_get_drvdata(&cdev->dev);
if (!device)
return ERR_PTR(-ENODEV);
dasd_get_device(device);
return device;
}
struct dasd_device *
dasd_device_from_cdev(struct ccw_device *cdev)
{
struct dasd_device *device;
unsigned long flags;
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
device = dasd_device_from_cdev_locked(cdev);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
return device;
}
void dasd_add_link_to_gendisk(struct gendisk *gdp, struct dasd_device *device)
{
struct dasd_devmap *devmap;
devmap = dasd_find_busid(dev_name(&device->cdev->dev));
if (IS_ERR(devmap))
return;
spin_lock(&dasd_devmap_lock);
gdp->private_data = devmap;
spin_unlock(&dasd_devmap_lock);
}
struct dasd_device *dasd_device_from_gendisk(struct gendisk *gdp)
{
struct dasd_device *device;
struct dasd_devmap *devmap;
if (!gdp->private_data)
return NULL;
device = NULL;
spin_lock(&dasd_devmap_lock);
devmap = gdp->private_data;
if (devmap && devmap->device) {
device = devmap->device;
dasd_get_device(device);
}
spin_unlock(&dasd_devmap_lock);
return device;
}
static ssize_t dasd_ff_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct dasd_devmap *devmap;
int ff_flag;
devmap = dasd_find_busid(dev_name(dev));
if (!IS_ERR(devmap))
ff_flag = (devmap->features & DASD_FEATURE_FAILFAST) != 0;
else
ff_flag = (DASD_FEATURE_DEFAULT & DASD_FEATURE_FAILFAST) != 0;
return snprintf(buf, PAGE_SIZE, ff_flag ? "1\n" : "0\n");
}
static ssize_t dasd_ff_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned int val;
int rc;
if (kstrtouint(buf, 0, &val) || val > 1)
return -EINVAL;
rc = dasd_set_feature(to_ccwdev(dev), DASD_FEATURE_FAILFAST, val);
return rc ? : count;
}
static ssize_t
dasd_ro_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dasd_devmap *devmap;
struct dasd_device *device;
int ro_flag = 0;
devmap = dasd_find_busid(dev_name(dev));
if (IS_ERR(devmap))
goto out;
ro_flag = !!(devmap->features & DASD_FEATURE_READONLY);
spin_lock(&dasd_devmap_lock);
device = devmap->device;
if (device)
ro_flag |= test_bit(DASD_FLAG_DEVICE_RO, &device->flags);
spin_unlock(&dasd_devmap_lock);
out:
return snprintf(buf, PAGE_SIZE, ro_flag ? "1\n" : "0\n");
}
static ssize_t
dasd_ro_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ccw_device *cdev = to_ccwdev(dev);
struct dasd_device *device;
unsigned long flags;
unsigned int val;
int rc;
if (kstrtouint(buf, 0, &val) || val > 1)
return -EINVAL;
rc = dasd_set_feature(cdev, DASD_FEATURE_READONLY, val);
if (rc)
return rc;
device = dasd_device_from_cdev(cdev);
if (IS_ERR(device))
return count;
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
val = val || test_bit(DASD_FLAG_DEVICE_RO, &device->flags);
if (!device->block || !device->block->gdp ||
test_bit(DASD_FLAG_OFFLINE, &device->flags)) {
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
goto out;
}
atomic_inc(&device->block->open_count);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
set_disk_ro(device->block->gdp, val);
atomic_dec(&device->block->open_count);
out:
dasd_put_device(device);
return count;
}
static ssize_t
dasd_erplog_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dasd_devmap *devmap;
int erplog;
devmap = dasd_find_busid(dev_name(dev));
if (!IS_ERR(devmap))
erplog = (devmap->features & DASD_FEATURE_ERPLOG) != 0;
else
erplog = (DASD_FEATURE_DEFAULT & DASD_FEATURE_ERPLOG) != 0;
return snprintf(buf, PAGE_SIZE, erplog ? "1\n" : "0\n");
}
static ssize_t
dasd_erplog_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned int val;
int rc;
if (kstrtouint(buf, 0, &val) || val > 1)
return -EINVAL;
rc = dasd_set_feature(to_ccwdev(dev), DASD_FEATURE_ERPLOG, val);
return rc ? : count;
}
static ssize_t
dasd_use_diag_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dasd_devmap *devmap;
int use_diag;
devmap = dasd_find_busid(dev_name(dev));
if (!IS_ERR(devmap))
use_diag = (devmap->features & DASD_FEATURE_USEDIAG) != 0;
else
use_diag = (DASD_FEATURE_DEFAULT & DASD_FEATURE_USEDIAG) != 0;
return sprintf(buf, use_diag ? "1\n" : "0\n");
}
static ssize_t
dasd_use_diag_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_devmap *devmap;
unsigned int val;
ssize_t rc;
devmap = dasd_devmap_from_cdev(to_ccwdev(dev));
if (IS_ERR(devmap))
return PTR_ERR(devmap);
if (kstrtouint(buf, 0, &val) || val > 1)
return -EINVAL;
spin_lock(&dasd_devmap_lock);
rc = count;
if (!devmap->device && !(devmap->features & DASD_FEATURE_USERAW)) {
if (val)
devmap->features |= DASD_FEATURE_USEDIAG;
else
devmap->features &= ~DASD_FEATURE_USEDIAG;
} else
rc = -EPERM;
spin_unlock(&dasd_devmap_lock);
return rc;
}
static ssize_t
dasd_use_raw_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dasd_devmap *devmap;
int use_raw;
devmap = dasd_find_busid(dev_name(dev));
if (!IS_ERR(devmap))
use_raw = (devmap->features & DASD_FEATURE_USERAW) != 0;
else
use_raw = (DASD_FEATURE_DEFAULT & DASD_FEATURE_USERAW) != 0;
return sprintf(buf, use_raw ? "1\n" : "0\n");
}
static ssize_t
dasd_use_raw_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_devmap *devmap;
ssize_t rc;
unsigned long val;
devmap = dasd_devmap_from_cdev(to_ccwdev(dev));
if (IS_ERR(devmap))
return PTR_ERR(devmap);
if ((kstrtoul(buf, 10, &val) != 0) || val > 1)
return -EINVAL;
spin_lock(&dasd_devmap_lock);
rc = count;
if (!devmap->device && !(devmap->features & DASD_FEATURE_USEDIAG)) {
if (val)
devmap->features |= DASD_FEATURE_USERAW;
else
devmap->features &= ~DASD_FEATURE_USERAW;
} else
rc = -EPERM;
spin_unlock(&dasd_devmap_lock);
return rc;
}
static ssize_t
dasd_safe_offline_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ccw_device *cdev = to_ccwdev(dev);
struct dasd_device *device;
unsigned long flags;
int rc;
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
device = dasd_device_from_cdev_locked(cdev);
if (IS_ERR(device)) {
rc = PTR_ERR(device);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
goto out;
}
if (test_bit(DASD_FLAG_OFFLINE, &device->flags) ||
test_bit(DASD_FLAG_SAFE_OFFLINE_RUNNING, &device->flags)) {
dasd_put_device(device);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
rc = -EBUSY;
goto out;
}
set_bit(DASD_FLAG_SAFE_OFFLINE, &device->flags);
dasd_put_device(device);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
rc = ccw_device_set_offline(cdev);
out:
return rc ? rc : count;
}
static ssize_t
dasd_access_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct ccw_device *cdev = to_ccwdev(dev);
struct dasd_device *device;
int count;
device = dasd_device_from_cdev(cdev);
if (IS_ERR(device))
return PTR_ERR(device);
if (!device->discipline)
count = -ENODEV;
else if (!device->discipline->host_access_count)
count = -EOPNOTSUPP;
else
count = device->discipline->host_access_count(device);
dasd_put_device(device);
if (count < 0)
return count;
return sprintf(buf, "%d\n", count);
}
static ssize_t
dasd_discipline_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct dasd_device *device;
ssize_t len;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
goto out;
else if (!device->discipline) {
dasd_put_device(device);
goto out;
} else {
len = snprintf(buf, PAGE_SIZE, "%s\n",
device->discipline->name);
dasd_put_device(device);
return len;
}
out:
len = snprintf(buf, PAGE_SIZE, "none\n");
return len;
}
static ssize_t
dasd_device_status_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct dasd_device *device;
ssize_t len;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (!IS_ERR(device)) {
switch (device->state) {
case DASD_STATE_NEW:
len = snprintf(buf, PAGE_SIZE, "new\n");
break;
case DASD_STATE_KNOWN:
len = snprintf(buf, PAGE_SIZE, "detected\n");
break;
case DASD_STATE_BASIC:
len = snprintf(buf, PAGE_SIZE, "basic\n");
break;
case DASD_STATE_UNFMT:
len = snprintf(buf, PAGE_SIZE, "unformatted\n");
break;
case DASD_STATE_READY:
len = snprintf(buf, PAGE_SIZE, "ready\n");
break;
case DASD_STATE_ONLINE:
len = snprintf(buf, PAGE_SIZE, "online\n");
break;
default:
len = snprintf(buf, PAGE_SIZE, "no stat\n");
break;
}
dasd_put_device(device);
} else
len = snprintf(buf, PAGE_SIZE, "unknown\n");
return len;
}
static ssize_t dasd_alias_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dasd_device *device;
struct dasd_uid uid;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return sprintf(buf, "0\n");
if (device->discipline && device->discipline->get_uid &&
!device->discipline->get_uid(device, &uid)) {
if (uid.type == UA_BASE_PAV_ALIAS ||
uid.type == UA_HYPER_PAV_ALIAS) {
dasd_put_device(device);
return sprintf(buf, "1\n");
}
}
dasd_put_device(device);
return sprintf(buf, "0\n");
}
static ssize_t dasd_vendor_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dasd_device *device;
struct dasd_uid uid;
char *vendor;
device = dasd_device_from_cdev(to_ccwdev(dev));
vendor = "";
if (IS_ERR(device))
return snprintf(buf, PAGE_SIZE, "%s\n", vendor);
if (device->discipline && device->discipline->get_uid &&
!device->discipline->get_uid(device, &uid))
vendor = uid.vendor;
dasd_put_device(device);
return snprintf(buf, PAGE_SIZE, "%s\n", vendor);
}
static ssize_t
dasd_uid_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dasd_device *device;
struct dasd_uid uid;
char uid_string[UID_STRLEN];
char ua_string[3];
device = dasd_device_from_cdev(to_ccwdev(dev));
uid_string[0] = 0;
if (IS_ERR(device))
return snprintf(buf, PAGE_SIZE, "%s\n", uid_string);
if (device->discipline && device->discipline->get_uid &&
!device->discipline->get_uid(device, &uid)) {
switch (uid.type) {
case UA_BASE_DEVICE:
snprintf(ua_string, sizeof(ua_string), "%02x",
uid.real_unit_addr);
break;
case UA_BASE_PAV_ALIAS:
snprintf(ua_string, sizeof(ua_string), "%02x",
uid.base_unit_addr);
break;
case UA_HYPER_PAV_ALIAS:
snprintf(ua_string, sizeof(ua_string), "xx");
break;
default:
snprintf(ua_string, sizeof(ua_string), "%02x",
uid.real_unit_addr);
break;
}
if (strlen(uid.vduit) > 0)
snprintf(uid_string, sizeof(uid_string),
"%s.%s.%04x.%s.%s",
uid.vendor, uid.serial, uid.ssid, ua_string,
uid.vduit);
else
snprintf(uid_string, sizeof(uid_string),
"%s.%s.%04x.%s",
uid.vendor, uid.serial, uid.ssid, ua_string);
}
dasd_put_device(device);
return snprintf(buf, PAGE_SIZE, "%s\n", uid_string);
}
static ssize_t
dasd_eer_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dasd_devmap *devmap;
int eer_flag;
devmap = dasd_find_busid(dev_name(dev));
if (!IS_ERR(devmap) && devmap->device)
eer_flag = dasd_eer_enabled(devmap->device);
else
eer_flag = 0;
return snprintf(buf, PAGE_SIZE, eer_flag ? "1\n" : "0\n");
}
static ssize_t
dasd_eer_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_device *device;
unsigned int val;
int rc = 0;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return PTR_ERR(device);
if (kstrtouint(buf, 0, &val) || val > 1)
return -EINVAL;
if (val)
rc = dasd_eer_enable(device);
else
dasd_eer_disable(device);
dasd_put_device(device);
return rc ? : count;
}
static ssize_t
dasd_expires_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dasd_device *device;
int len;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
len = snprintf(buf, PAGE_SIZE, "%lu\n", device->default_expires);
dasd_put_device(device);
return len;
}
static ssize_t
dasd_expires_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_device *device;
unsigned long val;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
if ((kstrtoul(buf, 10, &val) != 0) ||
(val > DASD_EXPIRES_MAX) || val == 0) {
dasd_put_device(device);
return -EINVAL;
}
if (val)
device->default_expires = val;
dasd_put_device(device);
return count;
}
static ssize_t
dasd_retries_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dasd_device *device;
int len;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
len = snprintf(buf, PAGE_SIZE, "%lu\n", device->default_retries);
dasd_put_device(device);
return len;
}
static ssize_t
dasd_retries_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_device *device;
unsigned long val;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
if ((kstrtoul(buf, 10, &val) != 0) ||
(val > DASD_RETRIES_MAX)) {
dasd_put_device(device);
return -EINVAL;
}
if (val)
device->default_retries = val;
dasd_put_device(device);
return count;
}
static ssize_t
dasd_timeout_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct dasd_device *device;
int len;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
len = snprintf(buf, PAGE_SIZE, "%lu\n", device->blk_timeout);
dasd_put_device(device);
return len;
}
static ssize_t
dasd_timeout_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_device *device;
struct request_queue *q;
unsigned long val, flags;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device) || !device->block)
return -ENODEV;
if ((kstrtoul(buf, 10, &val) != 0) ||
val > UINT_MAX / HZ) {
dasd_put_device(device);
return -EINVAL;
}
q = device->block->request_queue;
if (!q) {
dasd_put_device(device);
return -ENODEV;
}
spin_lock_irqsave(&device->block->request_queue_lock, flags);
if (!val)
blk_queue_rq_timed_out(q, NULL);
else
blk_queue_rq_timed_out(q, dasd_times_out);
device->blk_timeout = val;
blk_queue_rq_timeout(q, device->blk_timeout * HZ);
spin_unlock_irqrestore(&device->block->request_queue_lock, flags);
dasd_put_device(device);
return count;
}
static ssize_t
dasd_path_reset_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_device *device;
unsigned int val;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
if ((kstrtouint(buf, 16, &val) != 0) || val > 0xff)
val = 0;
if (device->discipline && device->discipline->reset_path)
device->discipline->reset_path(device, (__u8) val);
dasd_put_device(device);
return count;
}
static ssize_t dasd_hpf_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct dasd_device *device;
int hpf;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
if (!device->discipline || !device->discipline->hpf_enabled) {
dasd_put_device(device);
return snprintf(buf, PAGE_SIZE, "%d\n", dasd_nofcx);
}
hpf = device->discipline->hpf_enabled(device);
dasd_put_device(device);
return snprintf(buf, PAGE_SIZE, "%d\n", hpf);
}
static ssize_t dasd_reservation_policy_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct dasd_devmap *devmap;
int rc = 0;
devmap = dasd_find_busid(dev_name(dev));
if (IS_ERR(devmap)) {
rc = snprintf(buf, PAGE_SIZE, "ignore\n");
} else {
spin_lock(&dasd_devmap_lock);
if (devmap->features & DASD_FEATURE_FAILONSLCK)
rc = snprintf(buf, PAGE_SIZE, "fail\n");
else
rc = snprintf(buf, PAGE_SIZE, "ignore\n");
spin_unlock(&dasd_devmap_lock);
}
return rc;
}
static ssize_t dasd_reservation_policy_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ccw_device *cdev = to_ccwdev(dev);
int rc;
if (sysfs_streq("ignore", buf))
rc = dasd_set_feature(cdev, DASD_FEATURE_FAILONSLCK, 0);
else if (sysfs_streq("fail", buf))
rc = dasd_set_feature(cdev, DASD_FEATURE_FAILONSLCK, 1);
else
rc = -EINVAL;
return rc ? : count;
}
static ssize_t dasd_reservation_state_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct dasd_device *device;
int rc = 0;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return snprintf(buf, PAGE_SIZE, "none\n");
if (test_bit(DASD_FLAG_IS_RESERVED, &device->flags))
rc = snprintf(buf, PAGE_SIZE, "reserved\n");
else if (test_bit(DASD_FLAG_LOCK_STOLEN, &device->flags))
rc = snprintf(buf, PAGE_SIZE, "lost\n");
else
rc = snprintf(buf, PAGE_SIZE, "none\n");
dasd_put_device(device);
return rc;
}
static ssize_t dasd_reservation_state_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_device *device;
int rc = 0;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
if (sysfs_streq("reset", buf))
clear_bit(DASD_FLAG_LOCK_STOLEN, &device->flags);
else
rc = -EINVAL;
dasd_put_device(device);
if (rc)
return rc;
else
return count;
}
static ssize_t dasd_pm_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dasd_device *device;
u8 opm, nppm, cablepm, cuirpm, hpfpm, ifccpm;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return sprintf(buf, "0\n");
opm = dasd_path_get_opm(device);
nppm = dasd_path_get_nppm(device);
cablepm = dasd_path_get_cablepm(device);
cuirpm = dasd_path_get_cuirpm(device);
hpfpm = dasd_path_get_hpfpm(device);
ifccpm = dasd_path_get_ifccpm(device);
dasd_put_device(device);
return sprintf(buf, "%02x %02x %02x %02x %02x %02x\n", opm, nppm,
cablepm, cuirpm, hpfpm, ifccpm);
}
static ssize_t
dasd_path_threshold_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dasd_device *device;
int len;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
len = snprintf(buf, PAGE_SIZE, "%lu\n", device->path_thrhld);
dasd_put_device(device);
return len;
}
static ssize_t
dasd_path_threshold_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_device *device;
unsigned long flags;
unsigned long val;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
if (kstrtoul(buf, 10, &val) != 0 || val > DASD_THRHLD_MAX) {
dasd_put_device(device);
return -EINVAL;
}
spin_lock_irqsave(get_ccwdev_lock(to_ccwdev(dev)), flags);
device->path_thrhld = val;
spin_unlock_irqrestore(get_ccwdev_lock(to_ccwdev(dev)), flags);
dasd_put_device(device);
return count;
}
static ssize_t
dasd_path_interval_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dasd_device *device;
int len;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
len = snprintf(buf, PAGE_SIZE, "%lu\n", device->path_interval);
dasd_put_device(device);
return len;
}
static ssize_t
dasd_path_interval_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct dasd_device *device;
unsigned long flags;
unsigned long val;
device = dasd_device_from_cdev(to_ccwdev(dev));
if (IS_ERR(device))
return -ENODEV;
if ((kstrtoul(buf, 10, &val) != 0) ||
(val > DASD_INTERVAL_MAX) || val == 0) {
dasd_put_device(device);
return -EINVAL;
}
spin_lock_irqsave(get_ccwdev_lock(to_ccwdev(dev)), flags);
if (val)
device->path_interval = val;
spin_unlock_irqrestore(get_ccwdev_lock(to_ccwdev(dev)), flags);
dasd_put_device(device);
return count;
}
int
dasd_get_feature(struct ccw_device *cdev, int feature)
{
struct dasd_devmap *devmap;
devmap = dasd_find_busid(dev_name(&cdev->dev));
if (IS_ERR(devmap))
return PTR_ERR(devmap);
return ((devmap->features & feature) != 0);
}
int
dasd_set_feature(struct ccw_device *cdev, int feature, int flag)
{
struct dasd_devmap *devmap;
devmap = dasd_devmap_from_cdev(cdev);
if (IS_ERR(devmap))
return PTR_ERR(devmap);
spin_lock(&dasd_devmap_lock);
if (flag)
devmap->features |= feature;
else
devmap->features &= ~feature;
if (devmap->device)
devmap->device->features = devmap->features;
spin_unlock(&dasd_devmap_lock);
return 0;
}
int
dasd_add_sysfs_files(struct ccw_device *cdev)
{
return sysfs_create_group(&cdev->dev.kobj, &dasd_attr_group);
}
void
dasd_remove_sysfs_files(struct ccw_device *cdev)
{
sysfs_remove_group(&cdev->dev.kobj, &dasd_attr_group);
}
int
dasd_devmap_init(void)
{
int i;
dasd_max_devindex = 0;
for (i = 0; i < 256; i++)
INIT_LIST_HEAD(&dasd_hashlists[i]);
return 0;
}
void
dasd_devmap_exit(void)
{
dasd_forget_ranges();
}
