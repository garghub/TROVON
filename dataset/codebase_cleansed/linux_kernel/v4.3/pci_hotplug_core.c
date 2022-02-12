static ssize_t power_read_file(struct pci_slot *pci_slot, char *buf)
{
int retval;
u8 value;
retval = get_power_status(pci_slot->hotplug, &value);
if (retval)
return retval;
return sprintf(buf, "%d\n", value);
}
static ssize_t power_write_file(struct pci_slot *pci_slot, const char *buf,
size_t count)
{
struct hotplug_slot *slot = pci_slot->hotplug;
unsigned long lpower;
u8 power;
int retval = 0;
lpower = simple_strtoul(buf, NULL, 10);
power = (u8)(lpower & 0xff);
dbg("power = %d\n", power);
if (!try_module_get(slot->ops->owner)) {
retval = -ENODEV;
goto exit;
}
switch (power) {
case 0:
if (slot->ops->disable_slot)
retval = slot->ops->disable_slot(slot);
break;
case 1:
if (slot->ops->enable_slot)
retval = slot->ops->enable_slot(slot);
break;
default:
err("Illegal value specified for power\n");
retval = -EINVAL;
}
module_put(slot->ops->owner);
exit:
if (retval)
return retval;
return count;
}
static ssize_t attention_read_file(struct pci_slot *pci_slot, char *buf)
{
int retval;
u8 value;
retval = get_attention_status(pci_slot->hotplug, &value);
if (retval)
return retval;
return sprintf(buf, "%d\n", value);
}
static ssize_t attention_write_file(struct pci_slot *pci_slot, const char *buf,
size_t count)
{
struct hotplug_slot_ops *ops = pci_slot->hotplug->ops;
unsigned long lattention;
u8 attention;
int retval = 0;
lattention = simple_strtoul(buf, NULL, 10);
attention = (u8)(lattention & 0xff);
dbg(" - attention = %d\n", attention);
if (!try_module_get(ops->owner)) {
retval = -ENODEV;
goto exit;
}
if (ops->set_attention_status)
retval = ops->set_attention_status(pci_slot->hotplug, attention);
module_put(ops->owner);
exit:
if (retval)
return retval;
return count;
}
static ssize_t latch_read_file(struct pci_slot *pci_slot, char *buf)
{
int retval;
u8 value;
retval = get_latch_status(pci_slot->hotplug, &value);
if (retval)
return retval;
return sprintf(buf, "%d\n", value);
}
static ssize_t presence_read_file(struct pci_slot *pci_slot, char *buf)
{
int retval;
u8 value;
retval = get_adapter_status(pci_slot->hotplug, &value);
if (retval)
return retval;
return sprintf(buf, "%d\n", value);
}
static ssize_t test_write_file(struct pci_slot *pci_slot, const char *buf,
size_t count)
{
struct hotplug_slot *slot = pci_slot->hotplug;
unsigned long ltest;
u32 test;
int retval = 0;
ltest = simple_strtoul (buf, NULL, 10);
test = (u32)(ltest & 0xffffffff);
dbg("test = %d\n", test);
if (!try_module_get(slot->ops->owner)) {
retval = -ENODEV;
goto exit;
}
if (slot->ops->hardware_test)
retval = slot->ops->hardware_test(slot, test);
module_put(slot->ops->owner);
exit:
if (retval)
return retval;
return count;
}
static bool has_power_file(struct pci_slot *pci_slot)
{
struct hotplug_slot *slot = pci_slot->hotplug;
if ((!slot) || (!slot->ops))
return false;
if ((slot->ops->enable_slot) ||
(slot->ops->disable_slot) ||
(slot->ops->get_power_status))
return true;
return false;
}
static bool has_attention_file(struct pci_slot *pci_slot)
{
struct hotplug_slot *slot = pci_slot->hotplug;
if ((!slot) || (!slot->ops))
return false;
if ((slot->ops->set_attention_status) ||
(slot->ops->get_attention_status))
return true;
return false;
}
static bool has_latch_file(struct pci_slot *pci_slot)
{
struct hotplug_slot *slot = pci_slot->hotplug;
if ((!slot) || (!slot->ops))
return false;
if (slot->ops->get_latch_status)
return true;
return false;
}
static bool has_adapter_file(struct pci_slot *pci_slot)
{
struct hotplug_slot *slot = pci_slot->hotplug;
if ((!slot) || (!slot->ops))
return false;
if (slot->ops->get_adapter_status)
return true;
return false;
}
static bool has_test_file(struct pci_slot *pci_slot)
{
struct hotplug_slot *slot = pci_slot->hotplug;
if ((!slot) || (!slot->ops))
return false;
if (slot->ops->hardware_test)
return true;
return false;
}
static int fs_add_slot(struct pci_slot *pci_slot)
{
int retval = 0;
pci_hp_create_module_link(pci_slot);
if (has_power_file(pci_slot)) {
retval = sysfs_create_file(&pci_slot->kobj,
&hotplug_slot_attr_power.attr);
if (retval)
goto exit_power;
}
if (has_attention_file(pci_slot)) {
retval = sysfs_create_file(&pci_slot->kobj,
&hotplug_slot_attr_attention.attr);
if (retval)
goto exit_attention;
}
if (has_latch_file(pci_slot)) {
retval = sysfs_create_file(&pci_slot->kobj,
&hotplug_slot_attr_latch.attr);
if (retval)
goto exit_latch;
}
if (has_adapter_file(pci_slot)) {
retval = sysfs_create_file(&pci_slot->kobj,
&hotplug_slot_attr_presence.attr);
if (retval)
goto exit_adapter;
}
if (has_test_file(pci_slot)) {
retval = sysfs_create_file(&pci_slot->kobj,
&hotplug_slot_attr_test.attr);
if (retval)
goto exit_test;
}
goto exit;
exit_test:
if (has_adapter_file(pci_slot))
sysfs_remove_file(&pci_slot->kobj,
&hotplug_slot_attr_presence.attr);
exit_adapter:
if (has_latch_file(pci_slot))
sysfs_remove_file(&pci_slot->kobj, &hotplug_slot_attr_latch.attr);
exit_latch:
if (has_attention_file(pci_slot))
sysfs_remove_file(&pci_slot->kobj,
&hotplug_slot_attr_attention.attr);
exit_attention:
if (has_power_file(pci_slot))
sysfs_remove_file(&pci_slot->kobj, &hotplug_slot_attr_power.attr);
exit_power:
pci_hp_remove_module_link(pci_slot);
exit:
return retval;
}
static void fs_remove_slot(struct pci_slot *pci_slot)
{
if (has_power_file(pci_slot))
sysfs_remove_file(&pci_slot->kobj, &hotplug_slot_attr_power.attr);
if (has_attention_file(pci_slot))
sysfs_remove_file(&pci_slot->kobj,
&hotplug_slot_attr_attention.attr);
if (has_latch_file(pci_slot))
sysfs_remove_file(&pci_slot->kobj, &hotplug_slot_attr_latch.attr);
if (has_adapter_file(pci_slot))
sysfs_remove_file(&pci_slot->kobj,
&hotplug_slot_attr_presence.attr);
if (has_test_file(pci_slot))
sysfs_remove_file(&pci_slot->kobj, &hotplug_slot_attr_test.attr);
pci_hp_remove_module_link(pci_slot);
}
static struct hotplug_slot *get_slot_from_name(const char *name)
{
struct hotplug_slot *slot;
struct list_head *tmp;
list_for_each(tmp, &pci_hotplug_slot_list) {
slot = list_entry(tmp, struct hotplug_slot, slot_list);
if (strcmp(hotplug_slot_name(slot), name) == 0)
return slot;
}
return NULL;
}
int __pci_hp_register(struct hotplug_slot *slot, struct pci_bus *bus,
int devnr, const char *name,
struct module *owner, const char *mod_name)
{
int result;
struct pci_slot *pci_slot;
if (slot == NULL)
return -ENODEV;
if ((slot->info == NULL) || (slot->ops == NULL))
return -EINVAL;
if (slot->release == NULL) {
dbg("Why are you trying to register a hotplug slot without a proper release function?\n");
return -EINVAL;
}
slot->ops->owner = owner;
slot->ops->mod_name = mod_name;
mutex_lock(&pci_hp_mutex);
pci_slot = pci_create_slot(bus, devnr, name, slot);
if (IS_ERR(pci_slot)) {
result = PTR_ERR(pci_slot);
goto out;
}
slot->pci_slot = pci_slot;
pci_slot->hotplug = slot;
list_add(&slot->slot_list, &pci_hotplug_slot_list);
result = fs_add_slot(pci_slot);
kobject_uevent(&pci_slot->kobj, KOBJ_ADD);
dbg("Added slot %s to the list\n", name);
out:
mutex_unlock(&pci_hp_mutex);
return result;
}
int pci_hp_deregister(struct hotplug_slot *slot)
{
struct hotplug_slot *temp;
struct pci_slot *pci_slot;
if (!slot)
return -ENODEV;
mutex_lock(&pci_hp_mutex);
temp = get_slot_from_name(hotplug_slot_name(slot));
if (temp != slot) {
mutex_unlock(&pci_hp_mutex);
return -ENODEV;
}
list_del(&slot->slot_list);
pci_slot = slot->pci_slot;
fs_remove_slot(pci_slot);
dbg("Removed slot %s from the list\n", hotplug_slot_name(slot));
slot->release(slot);
pci_slot->hotplug = NULL;
pci_destroy_slot(pci_slot);
mutex_unlock(&pci_hp_mutex);
return 0;
}
int pci_hp_change_slot_info(struct hotplug_slot *slot,
struct hotplug_slot_info *info)
{
if (!slot || !info)
return -ENODEV;
memcpy(slot->info, info, sizeof(struct hotplug_slot_info));
return 0;
}
static int __init pci_hotplug_init(void)
{
int result;
result = cpci_hotplug_init(debug);
if (result) {
err("cpci_hotplug_init with error %d\n", result);
return result;
}
info(DRIVER_DESC " version: " DRIVER_VERSION "\n");
return result;
}
static void __exit pci_hotplug_exit(void)
{
cpci_hotplug_exit();
}
