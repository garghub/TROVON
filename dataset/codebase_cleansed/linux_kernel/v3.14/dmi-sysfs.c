static void dmi_entry_free(struct kobject *kobj)
{
kfree(kobj);
}
static struct dmi_sysfs_entry *to_entry(struct kobject *kobj)
{
return container_of(kobj, struct dmi_sysfs_entry, kobj);
}
static struct dmi_sysfs_attribute *to_attr(struct attribute *attr)
{
return container_of(attr, struct dmi_sysfs_attribute, attr);
}
static ssize_t dmi_sysfs_attr_show(struct kobject *kobj,
struct attribute *_attr, char *buf)
{
struct dmi_sysfs_entry *entry = to_entry(kobj);
struct dmi_sysfs_attribute *attr = to_attr(_attr);
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
return attr->show(entry, buf);
}
static void find_dmi_entry_helper(const struct dmi_header *dh,
void *_data)
{
struct find_dmi_data *data = _data;
struct dmi_sysfs_entry *entry = data->entry;
if (dh->type != entry->dh.type)
return;
if (data->instance_countdown != 0) {
data->instance_countdown--;
return;
}
data->instance_countdown--;
data->ret = data->callback(entry, dh, data->private);
}
static ssize_t find_dmi_entry(struct dmi_sysfs_entry *entry,
dmi_callback callback, void *private)
{
struct find_dmi_data data = {
.entry = entry,
.callback = callback,
.private = private,
.instance_countdown = entry->instance,
.ret = -EIO,
};
int ret;
ret = dmi_walk(find_dmi_entry_helper, &data);
if (ret)
return -EINVAL;
return data.ret;
}
static size_t dmi_entry_length(const struct dmi_header *dh)
{
const char *p = (const char *)dh;
p += dh->length;
while (p[0] || p[1])
p++;
return 2 + p - (const char *)dh;
}
static ssize_t dmi_entry_attr_show_helper(struct dmi_sysfs_entry *entry,
const struct dmi_header *dh,
void *_data)
{
struct dmi_entry_attr_show_data *data = _data;
struct dmi_sysfs_mapped_attribute *attr;
attr = container_of(data->attr,
struct dmi_sysfs_mapped_attribute, attr);
return attr->show(entry, dh, data->buf);
}
static ssize_t dmi_entry_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct dmi_entry_attr_show_data data = {
.attr = attr,
.buf = buf,
};
return find_dmi_entry(to_entry(kobj->parent),
dmi_entry_attr_show_helper, &data);
}
static u8 read_sel_8bit_indexed_io(const struct dmi_system_event_log *sel,
loff_t offset)
{
u8 ret;
mutex_lock(&io_port_lock);
outb((u8)offset, sel->io.index_addr);
ret = inb(sel->io.data_addr);
mutex_unlock(&io_port_lock);
return ret;
}
static u8 read_sel_2x8bit_indexed_io(const struct dmi_system_event_log *sel,
loff_t offset)
{
u8 ret;
mutex_lock(&io_port_lock);
outb((u8)offset, sel->io.index_addr);
outb((u8)(offset >> 8), sel->io.index_addr + 1);
ret = inb(sel->io.data_addr);
mutex_unlock(&io_port_lock);
return ret;
}
static u8 read_sel_16bit_indexed_io(const struct dmi_system_event_log *sel,
loff_t offset)
{
u8 ret;
mutex_lock(&io_port_lock);
outw((u16)offset, sel->io.index_addr);
ret = inb(sel->io.data_addr);
mutex_unlock(&io_port_lock);
return ret;
}
static ssize_t dmi_sel_raw_read_io(struct dmi_sysfs_entry *entry,
const struct dmi_system_event_log *sel,
char *buf, loff_t pos, size_t count)
{
ssize_t wrote = 0;
sel_io_reader io_reader = sel_io_readers[sel->access_method];
while (count && pos < sel->area_length) {
count--;
*(buf++) = io_reader(sel, pos++);
wrote++;
}
return wrote;
}
static ssize_t dmi_sel_raw_read_phys32(struct dmi_sysfs_entry *entry,
const struct dmi_system_event_log *sel,
char *buf, loff_t pos, size_t count)
{
u8 __iomem *mapped;
ssize_t wrote = 0;
mapped = ioremap(sel->access_method_address, sel->area_length);
if (!mapped)
return -EIO;
while (count && pos < sel->area_length) {
count--;
*(buf++) = readb(mapped + pos++);
wrote++;
}
iounmap(mapped);
return wrote;
}
static ssize_t dmi_sel_raw_read_helper(struct dmi_sysfs_entry *entry,
const struct dmi_header *dh,
void *_state)
{
struct dmi_read_state *state = _state;
struct dmi_system_event_log sel;
if (sizeof(sel) > dmi_entry_length(dh))
return -EIO;
memcpy(&sel, dh, sizeof(sel));
switch (sel.access_method) {
case DMI_SEL_ACCESS_METHOD_IO8:
case DMI_SEL_ACCESS_METHOD_IO2x8:
case DMI_SEL_ACCESS_METHOD_IO16:
return dmi_sel_raw_read_io(entry, &sel, state->buf,
state->pos, state->count);
case DMI_SEL_ACCESS_METHOD_PHYS32:
return dmi_sel_raw_read_phys32(entry, &sel, state->buf,
state->pos, state->count);
case DMI_SEL_ACCESS_METHOD_GPNV:
pr_info("dmi-sysfs: GPNV support missing.\n");
return -EIO;
default:
pr_info("dmi-sysfs: Unknown access method %02x\n",
sel.access_method);
return -EIO;
}
}
static ssize_t dmi_sel_raw_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
struct dmi_sysfs_entry *entry = to_entry(kobj->parent);
struct dmi_read_state state = {
.buf = buf,
.pos = pos,
.count = count,
};
return find_dmi_entry(entry, dmi_sel_raw_read_helper, &state);
}
static int dmi_system_event_log(struct dmi_sysfs_entry *entry)
{
int ret;
entry->child = kzalloc(sizeof(*entry->child), GFP_KERNEL);
if (!entry->child)
return -ENOMEM;
ret = kobject_init_and_add(entry->child,
&dmi_system_event_log_ktype,
&entry->kobj,
"system_event_log");
if (ret)
goto out_free;
ret = sysfs_create_bin_file(entry->child, &dmi_sel_raw_attr);
if (ret)
goto out_del;
return 0;
out_del:
kobject_del(entry->child);
out_free:
kfree(entry->child);
return ret;
}
static ssize_t dmi_sysfs_entry_length(struct dmi_sysfs_entry *entry, char *buf)
{
return sprintf(buf, "%d\n", entry->dh.length);
}
static ssize_t dmi_sysfs_entry_handle(struct dmi_sysfs_entry *entry, char *buf)
{
return sprintf(buf, "%d\n", entry->dh.handle);
}
static ssize_t dmi_sysfs_entry_type(struct dmi_sysfs_entry *entry, char *buf)
{
return sprintf(buf, "%d\n", entry->dh.type);
}
static ssize_t dmi_sysfs_entry_instance(struct dmi_sysfs_entry *entry,
char *buf)
{
return sprintf(buf, "%d\n", entry->instance);
}
static ssize_t dmi_sysfs_entry_position(struct dmi_sysfs_entry *entry,
char *buf)
{
return sprintf(buf, "%d\n", entry->position);
}
static ssize_t dmi_entry_raw_read_helper(struct dmi_sysfs_entry *entry,
const struct dmi_header *dh,
void *_state)
{
struct dmi_read_state *state = _state;
size_t entry_length;
entry_length = dmi_entry_length(dh);
return memory_read_from_buffer(state->buf, state->count,
&state->pos, dh, entry_length);
}
static ssize_t dmi_entry_raw_read(struct file *filp,
struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
struct dmi_sysfs_entry *entry = to_entry(kobj);
struct dmi_read_state state = {
.buf = buf,
.pos = pos,
.count = count,
};
return find_dmi_entry(entry, dmi_entry_raw_read_helper, &state);
}
static void dmi_sysfs_entry_release(struct kobject *kobj)
{
struct dmi_sysfs_entry *entry = to_entry(kobj);
spin_lock(&entry_list_lock);
list_del(&entry->list);
spin_unlock(&entry_list_lock);
kfree(entry);
}
static void __init dmi_sysfs_register_handle(const struct dmi_header *dh,
void *_ret)
{
struct dmi_sysfs_entry *entry;
int *ret = _ret;
if (*ret)
return;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry) {
*ret = -ENOMEM;
return;
}
memcpy(&entry->dh, dh, sizeof(*dh));
entry->instance = instance_counts[dh->type]++;
entry->position = position_count++;
entry->kobj.kset = dmi_kset;
*ret = kobject_init_and_add(&entry->kobj, &dmi_sysfs_entry_ktype, NULL,
"%d-%d", dh->type, entry->instance);
if (*ret) {
kfree(entry);
return;
}
spin_lock(&entry_list_lock);
list_add_tail(&entry->list, &entry_list);
spin_unlock(&entry_list_lock);
switch (dh->type) {
case DMI_ENTRY_SYSTEM_EVENT_LOG:
*ret = dmi_system_event_log(entry);
break;
default:
break;
}
if (*ret)
goto out_err;
*ret = sysfs_create_bin_file(&entry->kobj, &dmi_entry_raw_attr);
if (*ret)
goto out_err;
return;
out_err:
kobject_put(entry->child);
kobject_put(&entry->kobj);
return;
}
static void cleanup_entry_list(void)
{
struct dmi_sysfs_entry *entry, *next;
list_for_each_entry_safe(entry, next, &entry_list, list) {
kobject_put(entry->child);
kobject_put(&entry->kobj);
}
}
static int __init dmi_sysfs_init(void)
{
int error = -ENOMEM;
int val;
dmi_kobj = kobject_create_and_add("dmi", firmware_kobj);
if (!dmi_kobj)
goto err;
dmi_kset = kset_create_and_add("entries", NULL, dmi_kobj);
if (!dmi_kset)
goto err;
val = 0;
error = dmi_walk(dmi_sysfs_register_handle, &val);
if (error)
goto err;
if (val) {
error = val;
goto err;
}
pr_debug("dmi-sysfs: loaded.\n");
return 0;
err:
cleanup_entry_list();
kset_unregister(dmi_kset);
kobject_put(dmi_kobj);
return error;
}
static void __exit dmi_sysfs_exit(void)
{
pr_debug("dmi-sysfs: unloading.\n");
cleanup_entry_list();
kset_unregister(dmi_kset);
kobject_del(dmi_kobj);
kobject_put(dmi_kobj);
}
