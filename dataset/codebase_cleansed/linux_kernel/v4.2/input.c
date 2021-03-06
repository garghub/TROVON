static inline int is_event_supported(unsigned int code,
unsigned long *bm, unsigned int max)
{
return code <= max && test_bit(code, bm);
}
static int input_defuzz_abs_event(int value, int old_val, int fuzz)
{
if (fuzz) {
if (value > old_val - fuzz / 2 && value < old_val + fuzz / 2)
return old_val;
if (value > old_val - fuzz && value < old_val + fuzz)
return (old_val * 3 + value) / 4;
if (value > old_val - fuzz * 2 && value < old_val + fuzz * 2)
return (old_val + value) / 2;
}
return value;
}
static void input_start_autorepeat(struct input_dev *dev, int code)
{
if (test_bit(EV_REP, dev->evbit) &&
dev->rep[REP_PERIOD] && dev->rep[REP_DELAY] &&
dev->timer.data) {
dev->repeat_key = code;
mod_timer(&dev->timer,
jiffies + msecs_to_jiffies(dev->rep[REP_DELAY]));
}
}
static void input_stop_autorepeat(struct input_dev *dev)
{
del_timer(&dev->timer);
}
static unsigned int input_to_handler(struct input_handle *handle,
struct input_value *vals, unsigned int count)
{
struct input_handler *handler = handle->handler;
struct input_value *end = vals;
struct input_value *v;
if (handler->filter) {
for (v = vals; v != vals + count; v++) {
if (handler->filter(handle, v->type, v->code, v->value))
continue;
if (end != v)
*end = *v;
end++;
}
count = end - vals;
}
if (!count)
return 0;
if (handler->events)
handler->events(handle, vals, count);
else if (handler->event)
for (v = vals; v != vals + count; v++)
handler->event(handle, v->type, v->code, v->value);
return count;
}
static void input_pass_values(struct input_dev *dev,
struct input_value *vals, unsigned int count)
{
struct input_handle *handle;
struct input_value *v;
if (!count)
return;
rcu_read_lock();
handle = rcu_dereference(dev->grab);
if (handle) {
count = input_to_handler(handle, vals, count);
} else {
list_for_each_entry_rcu(handle, &dev->h_list, d_node)
if (handle->open) {
count = input_to_handler(handle, vals, count);
if (!count)
break;
}
}
rcu_read_unlock();
add_input_randomness(vals->type, vals->code, vals->value);
if (test_bit(EV_REP, dev->evbit) && test_bit(EV_KEY, dev->evbit)) {
for (v = vals; v != vals + count; v++) {
if (v->type == EV_KEY && v->value != 2) {
if (v->value)
input_start_autorepeat(dev, v->code);
else
input_stop_autorepeat(dev);
}
}
}
}
static void input_pass_event(struct input_dev *dev,
unsigned int type, unsigned int code, int value)
{
struct input_value vals[] = { { type, code, value } };
input_pass_values(dev, vals, ARRAY_SIZE(vals));
}
static void input_repeat_key(unsigned long data)
{
struct input_dev *dev = (void *) data;
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
if (test_bit(dev->repeat_key, dev->key) &&
is_event_supported(dev->repeat_key, dev->keybit, KEY_MAX)) {
struct input_value vals[] = {
{ EV_KEY, dev->repeat_key, 2 },
input_value_sync
};
input_pass_values(dev, vals, ARRAY_SIZE(vals));
if (dev->rep[REP_PERIOD])
mod_timer(&dev->timer, jiffies +
msecs_to_jiffies(dev->rep[REP_PERIOD]));
}
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static int input_handle_abs_event(struct input_dev *dev,
unsigned int code, int *pval)
{
struct input_mt *mt = dev->mt;
bool is_mt_event;
int *pold;
if (code == ABS_MT_SLOT) {
if (mt && *pval >= 0 && *pval < mt->num_slots)
mt->slot = *pval;
return INPUT_IGNORE_EVENT;
}
is_mt_event = input_is_mt_value(code);
if (!is_mt_event) {
pold = &dev->absinfo[code].value;
} else if (mt) {
pold = &mt->slots[mt->slot].abs[code - ABS_MT_FIRST];
} else {
pold = NULL;
}
if (pold) {
*pval = input_defuzz_abs_event(*pval, *pold,
dev->absinfo[code].fuzz);
if (*pold == *pval)
return INPUT_IGNORE_EVENT;
*pold = *pval;
}
if (is_mt_event && mt && mt->slot != input_abs_get_val(dev, ABS_MT_SLOT)) {
input_abs_set_val(dev, ABS_MT_SLOT, mt->slot);
return INPUT_PASS_TO_HANDLERS | INPUT_SLOT;
}
return INPUT_PASS_TO_HANDLERS;
}
static int input_get_disposition(struct input_dev *dev,
unsigned int type, unsigned int code, int *pval)
{
int disposition = INPUT_IGNORE_EVENT;
int value = *pval;
switch (type) {
case EV_SYN:
switch (code) {
case SYN_CONFIG:
disposition = INPUT_PASS_TO_ALL;
break;
case SYN_REPORT:
disposition = INPUT_PASS_TO_HANDLERS | INPUT_FLUSH;
break;
case SYN_MT_REPORT:
disposition = INPUT_PASS_TO_HANDLERS;
break;
}
break;
case EV_KEY:
if (is_event_supported(code, dev->keybit, KEY_MAX)) {
if (value == 2) {
disposition = INPUT_PASS_TO_HANDLERS;
break;
}
if (!!test_bit(code, dev->key) != !!value) {
__change_bit(code, dev->key);
disposition = INPUT_PASS_TO_HANDLERS;
}
}
break;
case EV_SW:
if (is_event_supported(code, dev->swbit, SW_MAX) &&
!!test_bit(code, dev->sw) != !!value) {
__change_bit(code, dev->sw);
disposition = INPUT_PASS_TO_HANDLERS;
}
break;
case EV_ABS:
if (is_event_supported(code, dev->absbit, ABS_MAX))
disposition = input_handle_abs_event(dev, code, &value);
break;
case EV_REL:
if (is_event_supported(code, dev->relbit, REL_MAX) && value)
disposition = INPUT_PASS_TO_HANDLERS;
break;
case EV_MSC:
if (is_event_supported(code, dev->mscbit, MSC_MAX))
disposition = INPUT_PASS_TO_ALL;
break;
case EV_LED:
if (is_event_supported(code, dev->ledbit, LED_MAX) &&
!!test_bit(code, dev->led) != !!value) {
__change_bit(code, dev->led);
disposition = INPUT_PASS_TO_ALL;
}
break;
case EV_SND:
if (is_event_supported(code, dev->sndbit, SND_MAX)) {
if (!!test_bit(code, dev->snd) != !!value)
__change_bit(code, dev->snd);
disposition = INPUT_PASS_TO_ALL;
}
break;
case EV_REP:
if (code <= REP_MAX && value >= 0 && dev->rep[code] != value) {
dev->rep[code] = value;
disposition = INPUT_PASS_TO_ALL;
}
break;
case EV_FF:
if (value >= 0)
disposition = INPUT_PASS_TO_ALL;
break;
case EV_PWR:
disposition = INPUT_PASS_TO_ALL;
break;
}
*pval = value;
return disposition;
}
static void input_handle_event(struct input_dev *dev,
unsigned int type, unsigned int code, int value)
{
int disposition;
disposition = input_get_disposition(dev, type, code, &value);
if ((disposition & INPUT_PASS_TO_DEVICE) && dev->event)
dev->event(dev, type, code, value);
if (!dev->vals)
return;
if (disposition & INPUT_PASS_TO_HANDLERS) {
struct input_value *v;
if (disposition & INPUT_SLOT) {
v = &dev->vals[dev->num_vals++];
v->type = EV_ABS;
v->code = ABS_MT_SLOT;
v->value = dev->mt->slot;
}
v = &dev->vals[dev->num_vals++];
v->type = type;
v->code = code;
v->value = value;
}
if (disposition & INPUT_FLUSH) {
if (dev->num_vals >= 2)
input_pass_values(dev, dev->vals, dev->num_vals);
dev->num_vals = 0;
} else if (dev->num_vals >= dev->max_vals - 2) {
dev->vals[dev->num_vals++] = input_value_sync;
input_pass_values(dev, dev->vals, dev->num_vals);
dev->num_vals = 0;
}
}
void input_event(struct input_dev *dev,
unsigned int type, unsigned int code, int value)
{
unsigned long flags;
if (is_event_supported(type, dev->evbit, EV_MAX)) {
spin_lock_irqsave(&dev->event_lock, flags);
input_handle_event(dev, type, code, value);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
}
void input_inject_event(struct input_handle *handle,
unsigned int type, unsigned int code, int value)
{
struct input_dev *dev = handle->dev;
struct input_handle *grab;
unsigned long flags;
if (is_event_supported(type, dev->evbit, EV_MAX)) {
spin_lock_irqsave(&dev->event_lock, flags);
rcu_read_lock();
grab = rcu_dereference(dev->grab);
if (!grab || grab == handle)
input_handle_event(dev, type, code, value);
rcu_read_unlock();
spin_unlock_irqrestore(&dev->event_lock, flags);
}
}
void input_alloc_absinfo(struct input_dev *dev)
{
if (!dev->absinfo)
dev->absinfo = kcalloc(ABS_CNT, sizeof(struct input_absinfo),
GFP_KERNEL);
WARN(!dev->absinfo, "%s(): kcalloc() failed?\n", __func__);
}
void input_set_abs_params(struct input_dev *dev, unsigned int axis,
int min, int max, int fuzz, int flat)
{
struct input_absinfo *absinfo;
input_alloc_absinfo(dev);
if (!dev->absinfo)
return;
absinfo = &dev->absinfo[axis];
absinfo->minimum = min;
absinfo->maximum = max;
absinfo->fuzz = fuzz;
absinfo->flat = flat;
__set_bit(EV_ABS, dev->evbit);
__set_bit(axis, dev->absbit);
}
int input_grab_device(struct input_handle *handle)
{
struct input_dev *dev = handle->dev;
int retval;
retval = mutex_lock_interruptible(&dev->mutex);
if (retval)
return retval;
if (dev->grab) {
retval = -EBUSY;
goto out;
}
rcu_assign_pointer(dev->grab, handle);
out:
mutex_unlock(&dev->mutex);
return retval;
}
static void __input_release_device(struct input_handle *handle)
{
struct input_dev *dev = handle->dev;
struct input_handle *grabber;
grabber = rcu_dereference_protected(dev->grab,
lockdep_is_held(&dev->mutex));
if (grabber == handle) {
rcu_assign_pointer(dev->grab, NULL);
synchronize_rcu();
list_for_each_entry(handle, &dev->h_list, d_node)
if (handle->open && handle->handler->start)
handle->handler->start(handle);
}
}
void input_release_device(struct input_handle *handle)
{
struct input_dev *dev = handle->dev;
mutex_lock(&dev->mutex);
__input_release_device(handle);
mutex_unlock(&dev->mutex);
}
int input_open_device(struct input_handle *handle)
{
struct input_dev *dev = handle->dev;
int retval;
retval = mutex_lock_interruptible(&dev->mutex);
if (retval)
return retval;
if (dev->going_away) {
retval = -ENODEV;
goto out;
}
handle->open++;
if (!dev->users++ && dev->open)
retval = dev->open(dev);
if (retval) {
dev->users--;
if (!--handle->open) {
synchronize_rcu();
}
}
out:
mutex_unlock(&dev->mutex);
return retval;
}
int input_flush_device(struct input_handle *handle, struct file *file)
{
struct input_dev *dev = handle->dev;
int retval;
retval = mutex_lock_interruptible(&dev->mutex);
if (retval)
return retval;
if (dev->flush)
retval = dev->flush(dev, file);
mutex_unlock(&dev->mutex);
return retval;
}
void input_close_device(struct input_handle *handle)
{
struct input_dev *dev = handle->dev;
mutex_lock(&dev->mutex);
__input_release_device(handle);
if (!--dev->users && dev->close)
dev->close(dev);
if (!--handle->open) {
synchronize_rcu();
}
mutex_unlock(&dev->mutex);
}
static void input_dev_release_keys(struct input_dev *dev)
{
int code;
if (is_event_supported(EV_KEY, dev->evbit, EV_MAX)) {
for_each_set_bit(code, dev->key, KEY_CNT)
input_pass_event(dev, EV_KEY, code, 0);
memset(dev->key, 0, sizeof(dev->key));
input_pass_event(dev, EV_SYN, SYN_REPORT, 1);
}
}
static void input_disconnect_device(struct input_dev *dev)
{
struct input_handle *handle;
mutex_lock(&dev->mutex);
dev->going_away = true;
mutex_unlock(&dev->mutex);
spin_lock_irq(&dev->event_lock);
input_dev_release_keys(dev);
list_for_each_entry(handle, &dev->h_list, d_node)
handle->open = 0;
spin_unlock_irq(&dev->event_lock);
}
int input_scancode_to_scalar(const struct input_keymap_entry *ke,
unsigned int *scancode)
{
switch (ke->len) {
case 1:
*scancode = *((u8 *)ke->scancode);
break;
case 2:
*scancode = *((u16 *)ke->scancode);
break;
case 4:
*scancode = *((u32 *)ke->scancode);
break;
default:
return -EINVAL;
}
return 0;
}
static unsigned int input_fetch_keycode(struct input_dev *dev,
unsigned int index)
{
switch (dev->keycodesize) {
case 1:
return ((u8 *)dev->keycode)[index];
case 2:
return ((u16 *)dev->keycode)[index];
default:
return ((u32 *)dev->keycode)[index];
}
}
static int input_default_getkeycode(struct input_dev *dev,
struct input_keymap_entry *ke)
{
unsigned int index;
int error;
if (!dev->keycodesize)
return -EINVAL;
if (ke->flags & INPUT_KEYMAP_BY_INDEX)
index = ke->index;
else {
error = input_scancode_to_scalar(ke, &index);
if (error)
return error;
}
if (index >= dev->keycodemax)
return -EINVAL;
ke->keycode = input_fetch_keycode(dev, index);
ke->index = index;
ke->len = sizeof(index);
memcpy(ke->scancode, &index, sizeof(index));
return 0;
}
static int input_default_setkeycode(struct input_dev *dev,
const struct input_keymap_entry *ke,
unsigned int *old_keycode)
{
unsigned int index;
int error;
int i;
if (!dev->keycodesize)
return -EINVAL;
if (ke->flags & INPUT_KEYMAP_BY_INDEX) {
index = ke->index;
} else {
error = input_scancode_to_scalar(ke, &index);
if (error)
return error;
}
if (index >= dev->keycodemax)
return -EINVAL;
if (dev->keycodesize < sizeof(ke->keycode) &&
(ke->keycode >> (dev->keycodesize * 8)))
return -EINVAL;
switch (dev->keycodesize) {
case 1: {
u8 *k = (u8 *)dev->keycode;
*old_keycode = k[index];
k[index] = ke->keycode;
break;
}
case 2: {
u16 *k = (u16 *)dev->keycode;
*old_keycode = k[index];
k[index] = ke->keycode;
break;
}
default: {
u32 *k = (u32 *)dev->keycode;
*old_keycode = k[index];
k[index] = ke->keycode;
break;
}
}
__clear_bit(*old_keycode, dev->keybit);
__set_bit(ke->keycode, dev->keybit);
for (i = 0; i < dev->keycodemax; i++) {
if (input_fetch_keycode(dev, i) == *old_keycode) {
__set_bit(*old_keycode, dev->keybit);
break;
}
}
return 0;
}
int input_get_keycode(struct input_dev *dev, struct input_keymap_entry *ke)
{
unsigned long flags;
int retval;
spin_lock_irqsave(&dev->event_lock, flags);
retval = dev->getkeycode(dev, ke);
spin_unlock_irqrestore(&dev->event_lock, flags);
return retval;
}
int input_set_keycode(struct input_dev *dev,
const struct input_keymap_entry *ke)
{
unsigned long flags;
unsigned int old_keycode;
int retval;
if (ke->keycode > KEY_MAX)
return -EINVAL;
spin_lock_irqsave(&dev->event_lock, flags);
retval = dev->setkeycode(dev, ke, &old_keycode);
if (retval)
goto out;
__clear_bit(KEY_RESERVED, dev->keybit);
if (test_bit(EV_KEY, dev->evbit) &&
!is_event_supported(old_keycode, dev->keybit, KEY_MAX) &&
__test_and_clear_bit(old_keycode, dev->key)) {
struct input_value vals[] = {
{ EV_KEY, old_keycode, 0 },
input_value_sync
};
input_pass_values(dev, vals, ARRAY_SIZE(vals));
}
out:
spin_unlock_irqrestore(&dev->event_lock, flags);
return retval;
}
static const struct input_device_id *input_match_device(struct input_handler *handler,
struct input_dev *dev)
{
const struct input_device_id *id;
for (id = handler->id_table; id->flags || id->driver_info; id++) {
if (id->flags & INPUT_DEVICE_ID_MATCH_BUS)
if (id->bustype != dev->id.bustype)
continue;
if (id->flags & INPUT_DEVICE_ID_MATCH_VENDOR)
if (id->vendor != dev->id.vendor)
continue;
if (id->flags & INPUT_DEVICE_ID_MATCH_PRODUCT)
if (id->product != dev->id.product)
continue;
if (id->flags & INPUT_DEVICE_ID_MATCH_VERSION)
if (id->version != dev->id.version)
continue;
if (!bitmap_subset(id->evbit, dev->evbit, EV_MAX))
continue;
if (!bitmap_subset(id->keybit, dev->keybit, KEY_MAX))
continue;
if (!bitmap_subset(id->relbit, dev->relbit, REL_MAX))
continue;
if (!bitmap_subset(id->absbit, dev->absbit, ABS_MAX))
continue;
if (!bitmap_subset(id->mscbit, dev->mscbit, MSC_MAX))
continue;
if (!bitmap_subset(id->ledbit, dev->ledbit, LED_MAX))
continue;
if (!bitmap_subset(id->sndbit, dev->sndbit, SND_MAX))
continue;
if (!bitmap_subset(id->ffbit, dev->ffbit, FF_MAX))
continue;
if (!bitmap_subset(id->swbit, dev->swbit, SW_MAX))
continue;
if (!handler->match || handler->match(handler, dev))
return id;
}
return NULL;
}
static int input_attach_handler(struct input_dev *dev, struct input_handler *handler)
{
const struct input_device_id *id;
int error;
id = input_match_device(handler, dev);
if (!id)
return -ENODEV;
error = handler->connect(handler, dev, id);
if (error && error != -ENODEV)
pr_err("failed to attach handler %s to device %s, error: %d\n",
handler->name, kobject_name(&dev->dev.kobj), error);
return error;
}
static int input_bits_to_string(char *buf, int buf_size,
unsigned long bits, bool skip_empty)
{
int len = 0;
if (INPUT_COMPAT_TEST) {
u32 dword = bits >> 32;
if (dword || !skip_empty)
len += snprintf(buf, buf_size, "%x ", dword);
dword = bits & 0xffffffffUL;
if (dword || !skip_empty || len)
len += snprintf(buf + len, max(buf_size - len, 0),
"%x", dword);
} else {
if (bits || !skip_empty)
len += snprintf(buf, buf_size, "%lx", bits);
}
return len;
}
static int input_bits_to_string(char *buf, int buf_size,
unsigned long bits, bool skip_empty)
{
return bits || !skip_empty ?
snprintf(buf, buf_size, "%lx", bits) : 0;
}
static inline void input_wakeup_procfs_readers(void)
{
input_devices_state++;
wake_up(&input_devices_poll_wait);
}
static unsigned int input_proc_devices_poll(struct file *file, poll_table *wait)
{
poll_wait(file, &input_devices_poll_wait, wait);
if (file->f_version != input_devices_state) {
file->f_version = input_devices_state;
return POLLIN | POLLRDNORM;
}
return 0;
}
static void *input_devices_seq_start(struct seq_file *seq, loff_t *pos)
{
union input_seq_state *state = (union input_seq_state *)&seq->private;
int error;
BUILD_BUG_ON(sizeof(union input_seq_state) != sizeof(seq->private));
error = mutex_lock_interruptible(&input_mutex);
if (error) {
state->mutex_acquired = false;
return ERR_PTR(error);
}
state->mutex_acquired = true;
return seq_list_start(&input_dev_list, *pos);
}
static void *input_devices_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
return seq_list_next(v, &input_dev_list, pos);
}
static void input_seq_stop(struct seq_file *seq, void *v)
{
union input_seq_state *state = (union input_seq_state *)&seq->private;
if (state->mutex_acquired)
mutex_unlock(&input_mutex);
}
static void input_seq_print_bitmap(struct seq_file *seq, const char *name,
unsigned long *bitmap, int max)
{
int i;
bool skip_empty = true;
char buf[18];
seq_printf(seq, "B: %s=", name);
for (i = BITS_TO_LONGS(max) - 1; i >= 0; i--) {
if (input_bits_to_string(buf, sizeof(buf),
bitmap[i], skip_empty)) {
skip_empty = false;
seq_printf(seq, "%s%s", buf, i > 0 ? " " : "");
}
}
if (skip_empty)
seq_puts(seq, "0");
seq_putc(seq, '\n');
}
static int input_devices_seq_show(struct seq_file *seq, void *v)
{
struct input_dev *dev = container_of(v, struct input_dev, node);
const char *path = kobject_get_path(&dev->dev.kobj, GFP_KERNEL);
struct input_handle *handle;
seq_printf(seq, "I: Bus=%04x Vendor=%04x Product=%04x Version=%04x\n",
dev->id.bustype, dev->id.vendor, dev->id.product, dev->id.version);
seq_printf(seq, "N: Name=\"%s\"\n", dev->name ? dev->name : "");
seq_printf(seq, "P: Phys=%s\n", dev->phys ? dev->phys : "");
seq_printf(seq, "S: Sysfs=%s\n", path ? path : "");
seq_printf(seq, "U: Uniq=%s\n", dev->uniq ? dev->uniq : "");
seq_printf(seq, "H: Handlers=");
list_for_each_entry(handle, &dev->h_list, d_node)
seq_printf(seq, "%s ", handle->name);
seq_putc(seq, '\n');
input_seq_print_bitmap(seq, "PROP", dev->propbit, INPUT_PROP_MAX);
input_seq_print_bitmap(seq, "EV", dev->evbit, EV_MAX);
if (test_bit(EV_KEY, dev->evbit))
input_seq_print_bitmap(seq, "KEY", dev->keybit, KEY_MAX);
if (test_bit(EV_REL, dev->evbit))
input_seq_print_bitmap(seq, "REL", dev->relbit, REL_MAX);
if (test_bit(EV_ABS, dev->evbit))
input_seq_print_bitmap(seq, "ABS", dev->absbit, ABS_MAX);
if (test_bit(EV_MSC, dev->evbit))
input_seq_print_bitmap(seq, "MSC", dev->mscbit, MSC_MAX);
if (test_bit(EV_LED, dev->evbit))
input_seq_print_bitmap(seq, "LED", dev->ledbit, LED_MAX);
if (test_bit(EV_SND, dev->evbit))
input_seq_print_bitmap(seq, "SND", dev->sndbit, SND_MAX);
if (test_bit(EV_FF, dev->evbit))
input_seq_print_bitmap(seq, "FF", dev->ffbit, FF_MAX);
if (test_bit(EV_SW, dev->evbit))
input_seq_print_bitmap(seq, "SW", dev->swbit, SW_MAX);
seq_putc(seq, '\n');
kfree(path);
return 0;
}
static int input_proc_devices_open(struct inode *inode, struct file *file)
{
return seq_open(file, &input_devices_seq_ops);
}
static void *input_handlers_seq_start(struct seq_file *seq, loff_t *pos)
{
union input_seq_state *state = (union input_seq_state *)&seq->private;
int error;
BUILD_BUG_ON(sizeof(union input_seq_state) != sizeof(seq->private));
error = mutex_lock_interruptible(&input_mutex);
if (error) {
state->mutex_acquired = false;
return ERR_PTR(error);
}
state->mutex_acquired = true;
state->pos = *pos;
return seq_list_start(&input_handler_list, *pos);
}
static void *input_handlers_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
union input_seq_state *state = (union input_seq_state *)&seq->private;
state->pos = *pos + 1;
return seq_list_next(v, &input_handler_list, pos);
}
static int input_handlers_seq_show(struct seq_file *seq, void *v)
{
struct input_handler *handler = container_of(v, struct input_handler, node);
union input_seq_state *state = (union input_seq_state *)&seq->private;
seq_printf(seq, "N: Number=%u Name=%s", state->pos, handler->name);
if (handler->filter)
seq_puts(seq, " (filter)");
if (handler->legacy_minors)
seq_printf(seq, " Minor=%d", handler->minor);
seq_putc(seq, '\n');
return 0;
}
static int input_proc_handlers_open(struct inode *inode, struct file *file)
{
return seq_open(file, &input_handlers_seq_ops);
}
static int __init input_proc_init(void)
{
struct proc_dir_entry *entry;
proc_bus_input_dir = proc_mkdir("bus/input", NULL);
if (!proc_bus_input_dir)
return -ENOMEM;
entry = proc_create("devices", 0, proc_bus_input_dir,
&input_devices_fileops);
if (!entry)
goto fail1;
entry = proc_create("handlers", 0, proc_bus_input_dir,
&input_handlers_fileops);
if (!entry)
goto fail2;
return 0;
fail2: remove_proc_entry("devices", proc_bus_input_dir);
fail1: remove_proc_entry("bus/input", NULL);
return -ENOMEM;
}
static void input_proc_exit(void)
{
remove_proc_entry("devices", proc_bus_input_dir);
remove_proc_entry("handlers", proc_bus_input_dir);
remove_proc_entry("bus/input", NULL);
}
static inline void input_wakeup_procfs_readers(void) { }
static inline int input_proc_init(void) { return 0; }
static inline void input_proc_exit(void) { }
static int input_print_modalias_bits(char *buf, int size,
char name, unsigned long *bm,
unsigned int min_bit, unsigned int max_bit)
{
int len = 0, i;
len += snprintf(buf, max(size, 0), "%c", name);
for (i = min_bit; i < max_bit; i++)
if (bm[BIT_WORD(i)] & BIT_MASK(i))
len += snprintf(buf + len, max(size - len, 0), "%X,", i);
return len;
}
static int input_print_modalias(char *buf, int size, struct input_dev *id,
int add_cr)
{
int len;
len = snprintf(buf, max(size, 0),
"input:b%04Xv%04Xp%04Xe%04X-",
id->id.bustype, id->id.vendor,
id->id.product, id->id.version);
len += input_print_modalias_bits(buf + len, size - len,
'e', id->evbit, 0, EV_MAX);
len += input_print_modalias_bits(buf + len, size - len,
'k', id->keybit, KEY_MIN_INTERESTING, KEY_MAX);
len += input_print_modalias_bits(buf + len, size - len,
'r', id->relbit, 0, REL_MAX);
len += input_print_modalias_bits(buf + len, size - len,
'a', id->absbit, 0, ABS_MAX);
len += input_print_modalias_bits(buf + len, size - len,
'm', id->mscbit, 0, MSC_MAX);
len += input_print_modalias_bits(buf + len, size - len,
'l', id->ledbit, 0, LED_MAX);
len += input_print_modalias_bits(buf + len, size - len,
's', id->sndbit, 0, SND_MAX);
len += input_print_modalias_bits(buf + len, size - len,
'f', id->ffbit, 0, FF_MAX);
len += input_print_modalias_bits(buf + len, size - len,
'w', id->swbit, 0, SW_MAX);
if (add_cr)
len += snprintf(buf + len, max(size - len, 0), "\n");
return len;
}
static ssize_t input_dev_show_modalias(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct input_dev *id = to_input_dev(dev);
ssize_t len;
len = input_print_modalias(buf, PAGE_SIZE, id, 1);
return min_t(int, len, PAGE_SIZE);
}
static ssize_t input_dev_show_properties(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct input_dev *input_dev = to_input_dev(dev);
int len = input_print_bitmap(buf, PAGE_SIZE, input_dev->propbit,
INPUT_PROP_MAX, true);
return min_t(int, len, PAGE_SIZE);
}
static int input_print_bitmap(char *buf, int buf_size, unsigned long *bitmap,
int max, int add_cr)
{
int i;
int len = 0;
bool skip_empty = true;
for (i = BITS_TO_LONGS(max) - 1; i >= 0; i--) {
len += input_bits_to_string(buf + len, max(buf_size - len, 0),
bitmap[i], skip_empty);
if (len) {
skip_empty = false;
if (i > 0)
len += snprintf(buf + len, max(buf_size - len, 0), " ");
}
}
if (len == 0)
len = snprintf(buf, buf_size, "%d", 0);
if (add_cr)
len += snprintf(buf + len, max(buf_size - len, 0), "\n");
return len;
}
static void input_dev_release(struct device *device)
{
struct input_dev *dev = to_input_dev(device);
input_ff_destroy(dev);
input_mt_destroy_slots(dev);
kfree(dev->absinfo);
kfree(dev->vals);
kfree(dev);
module_put(THIS_MODULE);
}
static int input_add_uevent_bm_var(struct kobj_uevent_env *env,
const char *name, unsigned long *bitmap, int max)
{
int len;
if (add_uevent_var(env, "%s", name))
return -ENOMEM;
len = input_print_bitmap(&env->buf[env->buflen - 1],
sizeof(env->buf) - env->buflen,
bitmap, max, false);
if (len >= (sizeof(env->buf) - env->buflen))
return -ENOMEM;
env->buflen += len;
return 0;
}
static int input_add_uevent_modalias_var(struct kobj_uevent_env *env,
struct input_dev *dev)
{
int len;
if (add_uevent_var(env, "MODALIAS="))
return -ENOMEM;
len = input_print_modalias(&env->buf[env->buflen - 1],
sizeof(env->buf) - env->buflen,
dev, 0);
if (len >= (sizeof(env->buf) - env->buflen))
return -ENOMEM;
env->buflen += len;
return 0;
}
static int input_dev_uevent(struct device *device, struct kobj_uevent_env *env)
{
struct input_dev *dev = to_input_dev(device);
INPUT_ADD_HOTPLUG_VAR("PRODUCT=%x/%x/%x/%x",
dev->id.bustype, dev->id.vendor,
dev->id.product, dev->id.version);
if (dev->name)
INPUT_ADD_HOTPLUG_VAR("NAME=\"%s\"", dev->name);
if (dev->phys)
INPUT_ADD_HOTPLUG_VAR("PHYS=\"%s\"", dev->phys);
if (dev->uniq)
INPUT_ADD_HOTPLUG_VAR("UNIQ=\"%s\"", dev->uniq);
INPUT_ADD_HOTPLUG_BM_VAR("PROP=", dev->propbit, INPUT_PROP_MAX);
INPUT_ADD_HOTPLUG_BM_VAR("EV=", dev->evbit, EV_MAX);
if (test_bit(EV_KEY, dev->evbit))
INPUT_ADD_HOTPLUG_BM_VAR("KEY=", dev->keybit, KEY_MAX);
if (test_bit(EV_REL, dev->evbit))
INPUT_ADD_HOTPLUG_BM_VAR("REL=", dev->relbit, REL_MAX);
if (test_bit(EV_ABS, dev->evbit))
INPUT_ADD_HOTPLUG_BM_VAR("ABS=", dev->absbit, ABS_MAX);
if (test_bit(EV_MSC, dev->evbit))
INPUT_ADD_HOTPLUG_BM_VAR("MSC=", dev->mscbit, MSC_MAX);
if (test_bit(EV_LED, dev->evbit))
INPUT_ADD_HOTPLUG_BM_VAR("LED=", dev->ledbit, LED_MAX);
if (test_bit(EV_SND, dev->evbit))
INPUT_ADD_HOTPLUG_BM_VAR("SND=", dev->sndbit, SND_MAX);
if (test_bit(EV_FF, dev->evbit))
INPUT_ADD_HOTPLUG_BM_VAR("FF=", dev->ffbit, FF_MAX);
if (test_bit(EV_SW, dev->evbit))
INPUT_ADD_HOTPLUG_BM_VAR("SW=", dev->swbit, SW_MAX);
INPUT_ADD_HOTPLUG_MODALIAS_VAR(dev);
return 0;
}
static void input_dev_toggle(struct input_dev *dev, bool activate)
{
if (!dev->event)
return;
INPUT_DO_TOGGLE(dev, LED, led, activate);
INPUT_DO_TOGGLE(dev, SND, snd, activate);
if (activate && test_bit(EV_REP, dev->evbit)) {
dev->event(dev, EV_REP, REP_PERIOD, dev->rep[REP_PERIOD]);
dev->event(dev, EV_REP, REP_DELAY, dev->rep[REP_DELAY]);
}
}
void input_reset_device(struct input_dev *dev)
{
unsigned long flags;
mutex_lock(&dev->mutex);
spin_lock_irqsave(&dev->event_lock, flags);
input_dev_toggle(dev, true);
input_dev_release_keys(dev);
spin_unlock_irqrestore(&dev->event_lock, flags);
mutex_unlock(&dev->mutex);
}
static int input_dev_suspend(struct device *dev)
{
struct input_dev *input_dev = to_input_dev(dev);
spin_lock_irq(&input_dev->event_lock);
input_dev_release_keys(input_dev);
input_dev_toggle(input_dev, false);
spin_unlock_irq(&input_dev->event_lock);
return 0;
}
static int input_dev_resume(struct device *dev)
{
struct input_dev *input_dev = to_input_dev(dev);
spin_lock_irq(&input_dev->event_lock);
input_dev_toggle(input_dev, true);
spin_unlock_irq(&input_dev->event_lock);
return 0;
}
static int input_dev_freeze(struct device *dev)
{
struct input_dev *input_dev = to_input_dev(dev);
spin_lock_irq(&input_dev->event_lock);
input_dev_release_keys(input_dev);
spin_unlock_irq(&input_dev->event_lock);
return 0;
}
static int input_dev_poweroff(struct device *dev)
{
struct input_dev *input_dev = to_input_dev(dev);
spin_lock_irq(&input_dev->event_lock);
input_dev_toggle(input_dev, false);
spin_unlock_irq(&input_dev->event_lock);
return 0;
}
static char *input_devnode(struct device *dev, umode_t *mode)
{
return kasprintf(GFP_KERNEL, "input/%s", dev_name(dev));
}
struct input_dev *input_allocate_device(void)
{
static atomic_t input_no = ATOMIC_INIT(-1);
struct input_dev *dev;
dev = kzalloc(sizeof(struct input_dev), GFP_KERNEL);
if (dev) {
dev->dev.type = &input_dev_type;
dev->dev.class = &input_class;
device_initialize(&dev->dev);
mutex_init(&dev->mutex);
spin_lock_init(&dev->event_lock);
init_timer(&dev->timer);
INIT_LIST_HEAD(&dev->h_list);
INIT_LIST_HEAD(&dev->node);
dev_set_name(&dev->dev, "input%lu",
(unsigned long)atomic_inc_return(&input_no));
__module_get(THIS_MODULE);
}
return dev;
}
static int devm_input_device_match(struct device *dev, void *res, void *data)
{
struct input_devres *devres = res;
return devres->input == data;
}
static void devm_input_device_release(struct device *dev, void *res)
{
struct input_devres *devres = res;
struct input_dev *input = devres->input;
dev_dbg(dev, "%s: dropping reference to %s\n",
__func__, dev_name(&input->dev));
input_put_device(input);
}
struct input_dev *devm_input_allocate_device(struct device *dev)
{
struct input_dev *input;
struct input_devres *devres;
devres = devres_alloc(devm_input_device_release,
sizeof(struct input_devres), GFP_KERNEL);
if (!devres)
return NULL;
input = input_allocate_device();
if (!input) {
devres_free(devres);
return NULL;
}
input->dev.parent = dev;
input->devres_managed = true;
devres->input = input;
devres_add(dev, devres);
return input;
}
void input_free_device(struct input_dev *dev)
{
if (dev) {
if (dev->devres_managed)
WARN_ON(devres_destroy(dev->dev.parent,
devm_input_device_release,
devm_input_device_match,
dev));
input_put_device(dev);
}
}
void input_set_capability(struct input_dev *dev, unsigned int type, unsigned int code)
{
switch (type) {
case EV_KEY:
__set_bit(code, dev->keybit);
break;
case EV_REL:
__set_bit(code, dev->relbit);
break;
case EV_ABS:
input_alloc_absinfo(dev);
if (!dev->absinfo)
return;
__set_bit(code, dev->absbit);
break;
case EV_MSC:
__set_bit(code, dev->mscbit);
break;
case EV_SW:
__set_bit(code, dev->swbit);
break;
case EV_LED:
__set_bit(code, dev->ledbit);
break;
case EV_SND:
__set_bit(code, dev->sndbit);
break;
case EV_FF:
__set_bit(code, dev->ffbit);
break;
case EV_PWR:
break;
default:
pr_err("input_set_capability: unknown type %u (code %u)\n",
type, code);
dump_stack();
return;
}
__set_bit(type, dev->evbit);
}
static unsigned int input_estimate_events_per_packet(struct input_dev *dev)
{
int mt_slots;
int i;
unsigned int events;
if (dev->mt) {
mt_slots = dev->mt->num_slots;
} else if (test_bit(ABS_MT_TRACKING_ID, dev->absbit)) {
mt_slots = dev->absinfo[ABS_MT_TRACKING_ID].maximum -
dev->absinfo[ABS_MT_TRACKING_ID].minimum + 1,
mt_slots = clamp(mt_slots, 2, 32);
} else if (test_bit(ABS_MT_POSITION_X, dev->absbit)) {
mt_slots = 2;
} else {
mt_slots = 0;
}
events = mt_slots + 1;
if (test_bit(EV_ABS, dev->evbit))
for_each_set_bit(i, dev->absbit, ABS_CNT)
events += input_is_mt_axis(i) ? mt_slots : 1;
if (test_bit(EV_REL, dev->evbit))
events += bitmap_weight(dev->relbit, REL_CNT);
events += 7;
return events;
}
static void input_cleanse_bitmasks(struct input_dev *dev)
{
INPUT_CLEANSE_BITMASK(dev, KEY, key);
INPUT_CLEANSE_BITMASK(dev, REL, rel);
INPUT_CLEANSE_BITMASK(dev, ABS, abs);
INPUT_CLEANSE_BITMASK(dev, MSC, msc);
INPUT_CLEANSE_BITMASK(dev, LED, led);
INPUT_CLEANSE_BITMASK(dev, SND, snd);
INPUT_CLEANSE_BITMASK(dev, FF, ff);
INPUT_CLEANSE_BITMASK(dev, SW, sw);
}
static void __input_unregister_device(struct input_dev *dev)
{
struct input_handle *handle, *next;
input_disconnect_device(dev);
mutex_lock(&input_mutex);
list_for_each_entry_safe(handle, next, &dev->h_list, d_node)
handle->handler->disconnect(handle);
WARN_ON(!list_empty(&dev->h_list));
del_timer_sync(&dev->timer);
list_del_init(&dev->node);
input_wakeup_procfs_readers();
mutex_unlock(&input_mutex);
device_del(&dev->dev);
}
static void devm_input_device_unregister(struct device *dev, void *res)
{
struct input_devres *devres = res;
struct input_dev *input = devres->input;
dev_dbg(dev, "%s: unregistering device %s\n",
__func__, dev_name(&input->dev));
__input_unregister_device(input);
}
int input_register_device(struct input_dev *dev)
{
struct input_devres *devres = NULL;
struct input_handler *handler;
unsigned int packet_size;
const char *path;
int error;
if (dev->devres_managed) {
devres = devres_alloc(devm_input_device_unregister,
sizeof(struct input_devres), GFP_KERNEL);
if (!devres)
return -ENOMEM;
devres->input = dev;
}
__set_bit(EV_SYN, dev->evbit);
__clear_bit(KEY_RESERVED, dev->keybit);
input_cleanse_bitmasks(dev);
packet_size = input_estimate_events_per_packet(dev);
if (dev->hint_events_per_packet < packet_size)
dev->hint_events_per_packet = packet_size;
dev->max_vals = dev->hint_events_per_packet + 2;
dev->vals = kcalloc(dev->max_vals, sizeof(*dev->vals), GFP_KERNEL);
if (!dev->vals) {
error = -ENOMEM;
goto err_devres_free;
}
if (!dev->rep[REP_DELAY] && !dev->rep[REP_PERIOD]) {
dev->timer.data = (long) dev;
dev->timer.function = input_repeat_key;
dev->rep[REP_DELAY] = 250;
dev->rep[REP_PERIOD] = 33;
}
if (!dev->getkeycode)
dev->getkeycode = input_default_getkeycode;
if (!dev->setkeycode)
dev->setkeycode = input_default_setkeycode;
error = device_add(&dev->dev);
if (error)
goto err_free_vals;
path = kobject_get_path(&dev->dev.kobj, GFP_KERNEL);
pr_info("%s as %s\n",
dev->name ? dev->name : "Unspecified device",
path ? path : "N/A");
kfree(path);
error = mutex_lock_interruptible(&input_mutex);
if (error)
goto err_device_del;
list_add_tail(&dev->node, &input_dev_list);
list_for_each_entry(handler, &input_handler_list, node)
input_attach_handler(dev, handler);
input_wakeup_procfs_readers();
mutex_unlock(&input_mutex);
if (dev->devres_managed) {
dev_dbg(dev->dev.parent, "%s: registering %s with devres.\n",
__func__, dev_name(&dev->dev));
devres_add(dev->dev.parent, devres);
}
return 0;
err_device_del:
device_del(&dev->dev);
err_free_vals:
kfree(dev->vals);
dev->vals = NULL;
err_devres_free:
devres_free(devres);
return error;
}
void input_unregister_device(struct input_dev *dev)
{
if (dev->devres_managed) {
WARN_ON(devres_destroy(dev->dev.parent,
devm_input_device_unregister,
devm_input_device_match,
dev));
__input_unregister_device(dev);
} else {
__input_unregister_device(dev);
input_put_device(dev);
}
}
int input_register_handler(struct input_handler *handler)
{
struct input_dev *dev;
int error;
error = mutex_lock_interruptible(&input_mutex);
if (error)
return error;
INIT_LIST_HEAD(&handler->h_list);
list_add_tail(&handler->node, &input_handler_list);
list_for_each_entry(dev, &input_dev_list, node)
input_attach_handler(dev, handler);
input_wakeup_procfs_readers();
mutex_unlock(&input_mutex);
return 0;
}
void input_unregister_handler(struct input_handler *handler)
{
struct input_handle *handle, *next;
mutex_lock(&input_mutex);
list_for_each_entry_safe(handle, next, &handler->h_list, h_node)
handler->disconnect(handle);
WARN_ON(!list_empty(&handler->h_list));
list_del_init(&handler->node);
input_wakeup_procfs_readers();
mutex_unlock(&input_mutex);
}
int input_handler_for_each_handle(struct input_handler *handler, void *data,
int (*fn)(struct input_handle *, void *))
{
struct input_handle *handle;
int retval = 0;
rcu_read_lock();
list_for_each_entry_rcu(handle, &handler->h_list, h_node) {
retval = fn(handle, data);
if (retval)
break;
}
rcu_read_unlock();
return retval;
}
int input_register_handle(struct input_handle *handle)
{
struct input_handler *handler = handle->handler;
struct input_dev *dev = handle->dev;
int error;
error = mutex_lock_interruptible(&dev->mutex);
if (error)
return error;
if (handler->filter)
list_add_rcu(&handle->d_node, &dev->h_list);
else
list_add_tail_rcu(&handle->d_node, &dev->h_list);
mutex_unlock(&dev->mutex);
list_add_tail_rcu(&handle->h_node, &handler->h_list);
if (handler->start)
handler->start(handle);
return 0;
}
void input_unregister_handle(struct input_handle *handle)
{
struct input_dev *dev = handle->dev;
list_del_rcu(&handle->h_node);
mutex_lock(&dev->mutex);
list_del_rcu(&handle->d_node);
mutex_unlock(&dev->mutex);
synchronize_rcu();
}
int input_get_new_minor(int legacy_base, unsigned int legacy_num,
bool allow_dynamic)
{
if (legacy_base >= 0) {
int minor = ida_simple_get(&input_ida,
legacy_base,
legacy_base + legacy_num,
GFP_KERNEL);
if (minor >= 0 || !allow_dynamic)
return minor;
}
return ida_simple_get(&input_ida,
INPUT_FIRST_DYNAMIC_DEV, INPUT_MAX_CHAR_DEVICES,
GFP_KERNEL);
}
void input_free_minor(unsigned int minor)
{
ida_simple_remove(&input_ida, minor);
}
static int __init input_init(void)
{
int err;
err = class_register(&input_class);
if (err) {
pr_err("unable to register input_dev class\n");
return err;
}
err = input_proc_init();
if (err)
goto fail1;
err = register_chrdev_region(MKDEV(INPUT_MAJOR, 0),
INPUT_MAX_CHAR_DEVICES, "input");
if (err) {
pr_err("unable to register char major %d", INPUT_MAJOR);
goto fail2;
}
return 0;
fail2: input_proc_exit();
fail1: class_unregister(&input_class);
return err;
}
static void __exit input_exit(void)
{
input_proc_exit();
unregister_chrdev_region(MKDEV(INPUT_MAJOR, 0),
INPUT_MAX_CHAR_DEVICES);
class_unregister(&input_class);
}
