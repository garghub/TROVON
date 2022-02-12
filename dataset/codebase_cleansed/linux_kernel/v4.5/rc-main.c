static struct rc_map_list *seek_rc_map(const char *name)
{
struct rc_map_list *map = NULL;
spin_lock(&rc_map_lock);
list_for_each_entry(map, &rc_map_list, list) {
if (!strcmp(name, map->map.name)) {
spin_unlock(&rc_map_lock);
return map;
}
}
spin_unlock(&rc_map_lock);
return NULL;
}
struct rc_map *rc_map_get(const char *name)
{
struct rc_map_list *map;
map = seek_rc_map(name);
#ifdef CONFIG_MODULES
if (!map) {
int rc = request_module("%s", name);
if (rc < 0) {
printk(KERN_ERR "Couldn't load IR keymap %s\n", name);
return NULL;
}
msleep(20);
map = seek_rc_map(name);
}
#endif
if (!map) {
printk(KERN_ERR "IR keymap %s not found\n", name);
return NULL;
}
printk(KERN_INFO "Registered IR keymap %s\n", map->map.name);
return &map->map;
}
int rc_map_register(struct rc_map_list *map)
{
spin_lock(&rc_map_lock);
list_add_tail(&map->list, &rc_map_list);
spin_unlock(&rc_map_lock);
return 0;
}
void rc_map_unregister(struct rc_map_list *map)
{
spin_lock(&rc_map_lock);
list_del(&map->list);
spin_unlock(&rc_map_lock);
}
static int ir_create_table(struct rc_map *rc_map,
const char *name, u64 rc_type, size_t size)
{
rc_map->name = name;
rc_map->rc_type = rc_type;
rc_map->alloc = roundup_pow_of_two(size * sizeof(struct rc_map_table));
rc_map->size = rc_map->alloc / sizeof(struct rc_map_table);
rc_map->scan = kmalloc(rc_map->alloc, GFP_KERNEL);
if (!rc_map->scan)
return -ENOMEM;
IR_dprintk(1, "Allocated space for %u keycode entries (%u bytes)\n",
rc_map->size, rc_map->alloc);
return 0;
}
static void ir_free_table(struct rc_map *rc_map)
{
rc_map->size = 0;
kfree(rc_map->scan);
rc_map->scan = NULL;
}
static int ir_resize_table(struct rc_map *rc_map, gfp_t gfp_flags)
{
unsigned int oldalloc = rc_map->alloc;
unsigned int newalloc = oldalloc;
struct rc_map_table *oldscan = rc_map->scan;
struct rc_map_table *newscan;
if (rc_map->size == rc_map->len) {
if (rc_map->alloc >= IR_TAB_MAX_SIZE)
return -ENOMEM;
newalloc *= 2;
IR_dprintk(1, "Growing table to %u bytes\n", newalloc);
}
if ((rc_map->len * 3 < rc_map->size) && (oldalloc > IR_TAB_MIN_SIZE)) {
newalloc /= 2;
IR_dprintk(1, "Shrinking table to %u bytes\n", newalloc);
}
if (newalloc == oldalloc)
return 0;
newscan = kmalloc(newalloc, gfp_flags);
if (!newscan) {
IR_dprintk(1, "Failed to kmalloc %u bytes\n", newalloc);
return -ENOMEM;
}
memcpy(newscan, rc_map->scan, rc_map->len * sizeof(struct rc_map_table));
rc_map->scan = newscan;
rc_map->alloc = newalloc;
rc_map->size = rc_map->alloc / sizeof(struct rc_map_table);
kfree(oldscan);
return 0;
}
static unsigned int ir_update_mapping(struct rc_dev *dev,
struct rc_map *rc_map,
unsigned int index,
unsigned int new_keycode)
{
int old_keycode = rc_map->scan[index].keycode;
int i;
if (new_keycode == KEY_RESERVED || new_keycode == KEY_UNKNOWN) {
IR_dprintk(1, "#%d: Deleting scan 0x%04x\n",
index, rc_map->scan[index].scancode);
rc_map->len--;
memmove(&rc_map->scan[index], &rc_map->scan[index+ 1],
(rc_map->len - index) * sizeof(struct rc_map_table));
} else {
IR_dprintk(1, "#%d: %s scan 0x%04x with key 0x%04x\n",
index,
old_keycode == KEY_RESERVED ? "New" : "Replacing",
rc_map->scan[index].scancode, new_keycode);
rc_map->scan[index].keycode = new_keycode;
__set_bit(new_keycode, dev->input_dev->keybit);
}
if (old_keycode != KEY_RESERVED) {
__clear_bit(old_keycode, dev->input_dev->keybit);
for (i = 0; i < rc_map->len; i++) {
if (rc_map->scan[i].keycode == old_keycode) {
__set_bit(old_keycode, dev->input_dev->keybit);
break;
}
}
ir_resize_table(rc_map, GFP_ATOMIC);
}
return old_keycode;
}
static unsigned int ir_establish_scancode(struct rc_dev *dev,
struct rc_map *rc_map,
unsigned int scancode,
bool resize)
{
unsigned int i;
if (dev->scancode_mask)
scancode &= dev->scancode_mask;
for (i = 0; i < rc_map->len; i++) {
if (rc_map->scan[i].scancode == scancode)
return i;
if (rc_map->scan[i].scancode >= scancode)
break;
}
if (rc_map->size == rc_map->len) {
if (!resize || ir_resize_table(rc_map, GFP_ATOMIC))
return -1U;
}
if (i < rc_map->len)
memmove(&rc_map->scan[i + 1], &rc_map->scan[i],
(rc_map->len - i) * sizeof(struct rc_map_table));
rc_map->scan[i].scancode = scancode;
rc_map->scan[i].keycode = KEY_RESERVED;
rc_map->len++;
return i;
}
static int ir_setkeycode(struct input_dev *idev,
const struct input_keymap_entry *ke,
unsigned int *old_keycode)
{
struct rc_dev *rdev = input_get_drvdata(idev);
struct rc_map *rc_map = &rdev->rc_map;
unsigned int index;
unsigned int scancode;
int retval = 0;
unsigned long flags;
spin_lock_irqsave(&rc_map->lock, flags);
if (ke->flags & INPUT_KEYMAP_BY_INDEX) {
index = ke->index;
if (index >= rc_map->len) {
retval = -EINVAL;
goto out;
}
} else {
retval = input_scancode_to_scalar(ke, &scancode);
if (retval)
goto out;
index = ir_establish_scancode(rdev, rc_map, scancode, true);
if (index >= rc_map->len) {
retval = -ENOMEM;
goto out;
}
}
*old_keycode = ir_update_mapping(rdev, rc_map, index, ke->keycode);
out:
spin_unlock_irqrestore(&rc_map->lock, flags);
return retval;
}
static int ir_setkeytable(struct rc_dev *dev,
const struct rc_map *from)
{
struct rc_map *rc_map = &dev->rc_map;
unsigned int i, index;
int rc;
rc = ir_create_table(rc_map, from->name,
from->rc_type, from->size);
if (rc)
return rc;
IR_dprintk(1, "Allocated space for %u keycode entries (%u bytes)\n",
rc_map->size, rc_map->alloc);
for (i = 0; i < from->size; i++) {
index = ir_establish_scancode(dev, rc_map,
from->scan[i].scancode, false);
if (index >= rc_map->len) {
rc = -ENOMEM;
break;
}
ir_update_mapping(dev, rc_map, index,
from->scan[i].keycode);
}
if (rc)
ir_free_table(rc_map);
return rc;
}
static unsigned int ir_lookup_by_scancode(const struct rc_map *rc_map,
unsigned int scancode)
{
int start = 0;
int end = rc_map->len - 1;
int mid;
while (start <= end) {
mid = (start + end) / 2;
if (rc_map->scan[mid].scancode < scancode)
start = mid + 1;
else if (rc_map->scan[mid].scancode > scancode)
end = mid - 1;
else
return mid;
}
return -1U;
}
static int ir_getkeycode(struct input_dev *idev,
struct input_keymap_entry *ke)
{
struct rc_dev *rdev = input_get_drvdata(idev);
struct rc_map *rc_map = &rdev->rc_map;
struct rc_map_table *entry;
unsigned long flags;
unsigned int index;
unsigned int scancode;
int retval;
spin_lock_irqsave(&rc_map->lock, flags);
if (ke->flags & INPUT_KEYMAP_BY_INDEX) {
index = ke->index;
} else {
retval = input_scancode_to_scalar(ke, &scancode);
if (retval)
goto out;
index = ir_lookup_by_scancode(rc_map, scancode);
}
if (index < rc_map->len) {
entry = &rc_map->scan[index];
ke->index = index;
ke->keycode = entry->keycode;
ke->len = sizeof(entry->scancode);
memcpy(ke->scancode, &entry->scancode, sizeof(entry->scancode));
} else if (!(ke->flags & INPUT_KEYMAP_BY_INDEX)) {
ke->index = index;
ke->keycode = KEY_RESERVED;
} else {
retval = -EINVAL;
goto out;
}
retval = 0;
out:
spin_unlock_irqrestore(&rc_map->lock, flags);
return retval;
}
u32 rc_g_keycode_from_table(struct rc_dev *dev, u32 scancode)
{
struct rc_map *rc_map = &dev->rc_map;
unsigned int keycode;
unsigned int index;
unsigned long flags;
spin_lock_irqsave(&rc_map->lock, flags);
index = ir_lookup_by_scancode(rc_map, scancode);
keycode = index < rc_map->len ?
rc_map->scan[index].keycode : KEY_RESERVED;
spin_unlock_irqrestore(&rc_map->lock, flags);
if (keycode != KEY_RESERVED)
IR_dprintk(1, "%s: scancode 0x%04x keycode 0x%02x\n",
dev->input_name, scancode, keycode);
return keycode;
}
static void ir_do_keyup(struct rc_dev *dev, bool sync)
{
if (!dev->keypressed)
return;
IR_dprintk(1, "keyup key 0x%04x\n", dev->last_keycode);
input_report_key(dev->input_dev, dev->last_keycode, 0);
led_trigger_event(led_feedback, LED_OFF);
if (sync)
input_sync(dev->input_dev);
dev->keypressed = false;
}
void rc_keyup(struct rc_dev *dev)
{
unsigned long flags;
spin_lock_irqsave(&dev->keylock, flags);
ir_do_keyup(dev, true);
spin_unlock_irqrestore(&dev->keylock, flags);
}
static void ir_timer_keyup(unsigned long cookie)
{
struct rc_dev *dev = (struct rc_dev *)cookie;
unsigned long flags;
spin_lock_irqsave(&dev->keylock, flags);
if (time_is_before_eq_jiffies(dev->keyup_jiffies))
ir_do_keyup(dev, true);
spin_unlock_irqrestore(&dev->keylock, flags);
}
void rc_repeat(struct rc_dev *dev)
{
unsigned long flags;
spin_lock_irqsave(&dev->keylock, flags);
input_event(dev->input_dev, EV_MSC, MSC_SCAN, dev->last_scancode);
input_sync(dev->input_dev);
if (!dev->keypressed)
goto out;
dev->keyup_jiffies = jiffies + msecs_to_jiffies(IR_KEYPRESS_TIMEOUT);
mod_timer(&dev->timer_keyup, dev->keyup_jiffies);
out:
spin_unlock_irqrestore(&dev->keylock, flags);
}
static void ir_do_keydown(struct rc_dev *dev, enum rc_type protocol,
u32 scancode, u32 keycode, u8 toggle)
{
bool new_event = (!dev->keypressed ||
dev->last_protocol != protocol ||
dev->last_scancode != scancode ||
dev->last_toggle != toggle);
if (new_event && dev->keypressed)
ir_do_keyup(dev, false);
input_event(dev->input_dev, EV_MSC, MSC_SCAN, scancode);
if (new_event && keycode != KEY_RESERVED) {
dev->keypressed = true;
dev->last_protocol = protocol;
dev->last_scancode = scancode;
dev->last_toggle = toggle;
dev->last_keycode = keycode;
IR_dprintk(1, "%s: key down event, "
"key 0x%04x, protocol 0x%04x, scancode 0x%08x\n",
dev->input_name, keycode, protocol, scancode);
input_report_key(dev->input_dev, keycode, 1);
led_trigger_event(led_feedback, LED_FULL);
}
input_sync(dev->input_dev);
}
void rc_keydown(struct rc_dev *dev, enum rc_type protocol, u32 scancode, u8 toggle)
{
unsigned long flags;
u32 keycode = rc_g_keycode_from_table(dev, scancode);
spin_lock_irqsave(&dev->keylock, flags);
ir_do_keydown(dev, protocol, scancode, keycode, toggle);
if (dev->keypressed) {
dev->keyup_jiffies = jiffies + msecs_to_jiffies(IR_KEYPRESS_TIMEOUT);
mod_timer(&dev->timer_keyup, dev->keyup_jiffies);
}
spin_unlock_irqrestore(&dev->keylock, flags);
}
void rc_keydown_notimeout(struct rc_dev *dev, enum rc_type protocol,
u32 scancode, u8 toggle)
{
unsigned long flags;
u32 keycode = rc_g_keycode_from_table(dev, scancode);
spin_lock_irqsave(&dev->keylock, flags);
ir_do_keydown(dev, protocol, scancode, keycode, toggle);
spin_unlock_irqrestore(&dev->keylock, flags);
}
int rc_open(struct rc_dev *rdev)
{
int rval = 0;
if (!rdev)
return -EINVAL;
mutex_lock(&rdev->lock);
if (!rdev->users++ && rdev->open != NULL)
rval = rdev->open(rdev);
if (rval)
rdev->users--;
mutex_unlock(&rdev->lock);
return rval;
}
static int ir_open(struct input_dev *idev)
{
struct rc_dev *rdev = input_get_drvdata(idev);
return rc_open(rdev);
}
void rc_close(struct rc_dev *rdev)
{
if (rdev) {
mutex_lock(&rdev->lock);
if (!--rdev->users && rdev->close != NULL)
rdev->close(rdev);
mutex_unlock(&rdev->lock);
}
}
static void ir_close(struct input_dev *idev)
{
struct rc_dev *rdev = input_get_drvdata(idev);
rc_close(rdev);
}
static char *rc_devnode(struct device *dev, umode_t *mode)
{
return kasprintf(GFP_KERNEL, "rc/%s", dev_name(dev));
}
static bool lirc_is_present(void)
{
#if defined(CONFIG_LIRC_MODULE)
struct module *lirc;
mutex_lock(&module_mutex);
lirc = find_module("lirc_dev");
mutex_unlock(&module_mutex);
return lirc ? true : false;
#elif defined(CONFIG_LIRC)
return true;
#else
return false;
#endif
}
static ssize_t show_protocols(struct device *device,
struct device_attribute *mattr, char *buf)
{
struct rc_dev *dev = to_rc_dev(device);
struct rc_filter_attribute *fattr = to_rc_filter_attr(mattr);
u64 allowed, enabled;
char *tmp = buf;
int i;
if (!dev)
return -EINVAL;
mutex_lock(&dev->lock);
if (fattr->type == RC_FILTER_NORMAL) {
enabled = dev->enabled_protocols;
allowed = dev->allowed_protocols;
if (dev->raw && !allowed)
allowed = ir_raw_get_allowed_protocols();
} else {
enabled = dev->enabled_wakeup_protocols;
allowed = dev->allowed_wakeup_protocols;
}
mutex_unlock(&dev->lock);
IR_dprintk(1, "%s: allowed - 0x%llx, enabled - 0x%llx\n",
__func__, (long long)allowed, (long long)enabled);
for (i = 0; i < ARRAY_SIZE(proto_names); i++) {
if (allowed & enabled & proto_names[i].type)
tmp += sprintf(tmp, "[%s] ", proto_names[i].name);
else if (allowed & proto_names[i].type)
tmp += sprintf(tmp, "%s ", proto_names[i].name);
if (allowed & proto_names[i].type)
allowed &= ~proto_names[i].type;
}
if (dev->driver_type == RC_DRIVER_IR_RAW && lirc_is_present())
tmp += sprintf(tmp, "[lirc] ");
if (tmp != buf)
tmp--;
*tmp = '\n';
return tmp + 1 - buf;
}
static int parse_protocol_change(u64 *protocols, const char *buf)
{
const char *tmp;
unsigned count = 0;
bool enable, disable;
u64 mask;
int i;
while ((tmp = strsep((char **)&buf, " \n")) != NULL) {
if (!*tmp)
break;
if (*tmp == '+') {
enable = true;
disable = false;
tmp++;
} else if (*tmp == '-') {
enable = false;
disable = true;
tmp++;
} else {
enable = false;
disable = false;
}
for (i = 0; i < ARRAY_SIZE(proto_names); i++) {
if (!strcasecmp(tmp, proto_names[i].name)) {
mask = proto_names[i].type;
break;
}
}
if (i == ARRAY_SIZE(proto_names)) {
if (!strcasecmp(tmp, "lirc"))
mask = 0;
else {
IR_dprintk(1, "Unknown protocol: '%s'\n", tmp);
return -EINVAL;
}
}
count++;
if (enable)
*protocols |= mask;
else if (disable)
*protocols &= ~mask;
else
*protocols = mask;
}
if (!count) {
IR_dprintk(1, "Protocol not specified\n");
return -EINVAL;
}
return count;
}
static void ir_raw_load_modules(u64 *protocols)
{
u64 available;
int i, ret;
for (i = 0; i < ARRAY_SIZE(proto_names); i++) {
if (proto_names[i].type == RC_BIT_NONE ||
proto_names[i].type & (RC_BIT_OTHER | RC_BIT_UNKNOWN))
continue;
available = ir_raw_get_allowed_protocols();
if (!(*protocols & proto_names[i].type & ~available))
continue;
if (!proto_names[i].module_name) {
pr_err("Can't enable IR protocol %s\n",
proto_names[i].name);
*protocols &= ~proto_names[i].type;
continue;
}
ret = request_module("%s", proto_names[i].module_name);
if (ret < 0) {
pr_err("Couldn't load IR protocol module %s\n",
proto_names[i].module_name);
*protocols &= ~proto_names[i].type;
continue;
}
msleep(20);
available = ir_raw_get_allowed_protocols();
if (!(*protocols & proto_names[i].type & ~available))
continue;
pr_err("Loaded IR protocol module %s, \
but protocol %s still not available\n",
proto_names[i].module_name,
proto_names[i].name);
*protocols &= ~proto_names[i].type;
}
}
static ssize_t store_protocols(struct device *device,
struct device_attribute *mattr,
const char *buf, size_t len)
{
struct rc_dev *dev = to_rc_dev(device);
struct rc_filter_attribute *fattr = to_rc_filter_attr(mattr);
u64 *current_protocols;
int (*change_protocol)(struct rc_dev *dev, u64 *rc_type);
struct rc_scancode_filter *filter;
int (*set_filter)(struct rc_dev *dev, struct rc_scancode_filter *filter);
u64 old_protocols, new_protocols;
ssize_t rc;
if (!dev)
return -EINVAL;
if (fattr->type == RC_FILTER_NORMAL) {
IR_dprintk(1, "Normal protocol change requested\n");
current_protocols = &dev->enabled_protocols;
change_protocol = dev->change_protocol;
filter = &dev->scancode_filter;
set_filter = dev->s_filter;
} else {
IR_dprintk(1, "Wakeup protocol change requested\n");
current_protocols = &dev->enabled_wakeup_protocols;
change_protocol = dev->change_wakeup_protocol;
filter = &dev->scancode_wakeup_filter;
set_filter = dev->s_wakeup_filter;
}
if (!change_protocol) {
IR_dprintk(1, "Protocol switching not supported\n");
return -EINVAL;
}
mutex_lock(&dev->lock);
old_protocols = *current_protocols;
new_protocols = old_protocols;
rc = parse_protocol_change(&new_protocols, buf);
if (rc < 0)
goto out;
rc = change_protocol(dev, &new_protocols);
if (rc < 0) {
IR_dprintk(1, "Error setting protocols to 0x%llx\n",
(long long)new_protocols);
goto out;
}
if (dev->driver_type == RC_DRIVER_IR_RAW)
ir_raw_load_modules(&new_protocols);
if (new_protocols != old_protocols) {
*current_protocols = new_protocols;
IR_dprintk(1, "Protocols changed to 0x%llx\n",
(long long)new_protocols);
}
if (set_filter && filter->mask) {
if (new_protocols)
rc = set_filter(dev, filter);
else
rc = -1;
if (rc < 0) {
filter->data = 0;
filter->mask = 0;
set_filter(dev, filter);
}
}
rc = len;
out:
mutex_unlock(&dev->lock);
return rc;
}
static ssize_t show_filter(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct rc_dev *dev = to_rc_dev(device);
struct rc_filter_attribute *fattr = to_rc_filter_attr(attr);
struct rc_scancode_filter *filter;
u32 val;
if (!dev)
return -EINVAL;
if (fattr->type == RC_FILTER_NORMAL)
filter = &dev->scancode_filter;
else
filter = &dev->scancode_wakeup_filter;
mutex_lock(&dev->lock);
if (fattr->mask)
val = filter->mask;
else
val = filter->data;
mutex_unlock(&dev->lock);
return sprintf(buf, "%#x\n", val);
}
static ssize_t store_filter(struct device *device,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct rc_dev *dev = to_rc_dev(device);
struct rc_filter_attribute *fattr = to_rc_filter_attr(attr);
struct rc_scancode_filter new_filter, *filter;
int ret;
unsigned long val;
int (*set_filter)(struct rc_dev *dev, struct rc_scancode_filter *filter);
u64 *enabled_protocols;
if (!dev)
return -EINVAL;
ret = kstrtoul(buf, 0, &val);
if (ret < 0)
return ret;
if (fattr->type == RC_FILTER_NORMAL) {
set_filter = dev->s_filter;
enabled_protocols = &dev->enabled_protocols;
filter = &dev->scancode_filter;
} else {
set_filter = dev->s_wakeup_filter;
enabled_protocols = &dev->enabled_wakeup_protocols;
filter = &dev->scancode_wakeup_filter;
}
if (!set_filter)
return -EINVAL;
mutex_lock(&dev->lock);
new_filter = *filter;
if (fattr->mask)
new_filter.mask = val;
else
new_filter.data = val;
if (!*enabled_protocols && val) {
ret = -EINVAL;
goto unlock;
}
ret = set_filter(dev, &new_filter);
if (ret < 0)
goto unlock;
*filter = new_filter;
unlock:
mutex_unlock(&dev->lock);
return (ret < 0) ? ret : len;
}
static void rc_dev_release(struct device *device)
{
}
static int rc_dev_uevent(struct device *device, struct kobj_uevent_env *env)
{
struct rc_dev *dev = to_rc_dev(device);
if (dev->rc_map.name)
ADD_HOTPLUG_VAR("NAME=%s", dev->rc_map.name);
if (dev->driver_name)
ADD_HOTPLUG_VAR("DRV_NAME=%s", dev->driver_name);
return 0;
}
struct rc_dev *rc_allocate_device(void)
{
struct rc_dev *dev;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return NULL;
dev->input_dev = input_allocate_device();
if (!dev->input_dev) {
kfree(dev);
return NULL;
}
dev->input_dev->getkeycode = ir_getkeycode;
dev->input_dev->setkeycode = ir_setkeycode;
input_set_drvdata(dev->input_dev, dev);
spin_lock_init(&dev->rc_map.lock);
spin_lock_init(&dev->keylock);
mutex_init(&dev->lock);
setup_timer(&dev->timer_keyup, ir_timer_keyup, (unsigned long)dev);
dev->dev.type = &rc_dev_type;
dev->dev.class = &rc_class;
device_initialize(&dev->dev);
__module_get(THIS_MODULE);
return dev;
}
void rc_free_device(struct rc_dev *dev)
{
if (!dev)
return;
input_free_device(dev->input_dev);
put_device(&dev->dev);
kfree(dev);
module_put(THIS_MODULE);
}
int rc_register_device(struct rc_dev *dev)
{
static bool raw_init = false;
struct rc_map *rc_map;
const char *path;
int attr = 0;
int minor;
int rc;
if (!dev || !dev->map_name)
return -EINVAL;
rc_map = rc_map_get(dev->map_name);
if (!rc_map)
rc_map = rc_map_get(RC_MAP_EMPTY);
if (!rc_map || !rc_map->scan || rc_map->size == 0)
return -EINVAL;
set_bit(EV_KEY, dev->input_dev->evbit);
set_bit(EV_REP, dev->input_dev->evbit);
set_bit(EV_MSC, dev->input_dev->evbit);
set_bit(MSC_SCAN, dev->input_dev->mscbit);
if (dev->open)
dev->input_dev->open = ir_open;
if (dev->close)
dev->input_dev->close = ir_close;
minor = ida_simple_get(&rc_ida, 0, RC_DEV_MAX, GFP_KERNEL);
if (minor < 0)
return minor;
dev->minor = minor;
dev_set_name(&dev->dev, "rc%u", dev->minor);
dev_set_drvdata(&dev->dev, dev);
dev->dev.groups = dev->sysfs_groups;
dev->sysfs_groups[attr++] = &rc_dev_protocol_attr_grp;
if (dev->s_filter)
dev->sysfs_groups[attr++] = &rc_dev_filter_attr_grp;
if (dev->s_wakeup_filter)
dev->sysfs_groups[attr++] = &rc_dev_wakeup_filter_attr_grp;
if (dev->change_wakeup_protocol)
dev->sysfs_groups[attr++] = &rc_dev_wakeup_protocol_attr_grp;
dev->sysfs_groups[attr++] = NULL;
mutex_lock(&dev->lock);
rc = device_add(&dev->dev);
if (rc)
goto out_unlock;
rc = ir_setkeytable(dev, rc_map);
if (rc)
goto out_dev;
dev->input_dev->dev.parent = &dev->dev;
memcpy(&dev->input_dev->id, &dev->input_id, sizeof(dev->input_id));
dev->input_dev->phys = dev->input_phys;
dev->input_dev->name = dev->input_name;
mutex_unlock(&dev->lock);
rc = input_register_device(dev->input_dev);
mutex_lock(&dev->lock);
if (rc)
goto out_table;
dev->input_dev->rep[REP_DELAY] = 500;
dev->input_dev->rep[REP_PERIOD] = 125;
path = kobject_get_path(&dev->dev.kobj, GFP_KERNEL);
dev_info(&dev->dev, "%s as %s\n",
dev->input_name ?: "Unspecified device", path ?: "N/A");
kfree(path);
if (dev->driver_type == RC_DRIVER_IR_RAW) {
if (!raw_init) {
request_module_nowait("ir-lirc-codec");
raw_init = true;
}
mutex_unlock(&dev->lock);
rc = ir_raw_event_register(dev);
mutex_lock(&dev->lock);
if (rc < 0)
goto out_input;
}
if (dev->change_protocol) {
u64 rc_type = (1ll << rc_map->rc_type);
rc = dev->change_protocol(dev, &rc_type);
if (rc < 0)
goto out_raw;
dev->enabled_protocols = rc_type;
}
mutex_unlock(&dev->lock);
IR_dprintk(1, "Registered rc%u (driver: %s, remote: %s, mode %s)\n",
dev->minor,
dev->driver_name ? dev->driver_name : "unknown",
rc_map->name ? rc_map->name : "unknown",
dev->driver_type == RC_DRIVER_IR_RAW ? "raw" : "cooked");
return 0;
out_raw:
if (dev->driver_type == RC_DRIVER_IR_RAW)
ir_raw_event_unregister(dev);
out_input:
input_unregister_device(dev->input_dev);
dev->input_dev = NULL;
out_table:
ir_free_table(&dev->rc_map);
out_dev:
device_del(&dev->dev);
out_unlock:
mutex_unlock(&dev->lock);
ida_simple_remove(&rc_ida, minor);
return rc;
}
void rc_unregister_device(struct rc_dev *dev)
{
if (!dev)
return;
del_timer_sync(&dev->timer_keyup);
if (dev->driver_type == RC_DRIVER_IR_RAW)
ir_raw_event_unregister(dev);
ir_free_table(&dev->rc_map);
IR_dprintk(1, "Freed keycode table\n");
input_unregister_device(dev->input_dev);
dev->input_dev = NULL;
device_del(&dev->dev);
ida_simple_remove(&rc_ida, dev->minor);
rc_free_device(dev);
}
static int __init rc_core_init(void)
{
int rc = class_register(&rc_class);
if (rc) {
printk(KERN_ERR "rc_core: unable to register rc class\n");
return rc;
}
led_trigger_register_simple("rc-feedback", &led_feedback);
rc_map_register(&empty_map);
return 0;
}
static void __exit rc_core_exit(void)
{
class_unregister(&rc_class);
led_trigger_unregister_simple(led_feedback);
rc_map_unregister(&empty_map);
}
