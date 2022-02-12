static int enable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot->name);
return retval;
}
static int disable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot->name);
return retval;
}
static int set_attention_status(struct hotplug_slot *hotplug_slot, u8 status)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot->name);
switch (status) {
case 0:
break;
case 1:
default:
break;
}
return retval;
}
static int hardware_test(struct hotplug_slot *hotplug_slot, u32 value)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot->name);
switch (value) {
case 0:
break;
case 1:
break;
}
return retval;
}
static int get_power_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot->name);
return retval;
}
static int get_attention_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot->name);
return retval;
}
static int get_latch_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot->name);
return retval;
}
static int get_adapter_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot->name);
return retval;
}
static void release_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot->name);
kfree(slot->hotplug_slot->info);
kfree(slot->hotplug_slot);
kfree(slot);
}
static void make_slot_name(struct slot *slot)
{
snprintf(slot->hotplug_slot->name, SLOT_NAME_SIZE, "%d", slot->number);
}
static int __init init_slots(void)
{
struct slot *slot;
struct hotplug_slot *hotplug_slot;
struct hotplug_slot_info *info;
int retval;
int i;
for (i = 0; i < num_slots; ++i) {
slot = kzalloc(sizeof(*slot), GFP_KERNEL);
if (!slot) {
retval = -ENOMEM;
goto error;
}
hotplug_slot = kzalloc(sizeof(*hotplug_slot), GFP_KERNEL);
if (!hotplug_slot) {
retval = -ENOMEM;
goto error_slot;
}
slot->hotplug_slot = hotplug_slot;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
retval = -ENOMEM;
goto error_hpslot;
}
hotplug_slot->info = info;
slot->number = i;
hotplug_slot->name = slot->name;
hotplug_slot->private = slot;
hotplug_slot->release = &release_slot;
make_slot_name(slot);
hotplug_slot->ops = &skel_hotplug_slot_ops;
get_power_status(hotplug_slot, &info->power_status);
get_attention_status(hotplug_slot, &info->attention_status);
get_latch_status(hotplug_slot, &info->latch_status);
get_adapter_status(hotplug_slot, &info->adapter_status);
dbg("registering slot %d\n", i);
retval = pci_hp_register(slot->hotplug_slot);
if (retval) {
err("pci_hp_register failed with error %d\n", retval);
goto error_info;
}
list_add(&slot->slot_list, &slot_list);
}
return 0;
error_info:
kfree(info);
error_hpslot:
kfree(hotplug_slot);
error_slot:
kfree(slot);
error:
return retval;
}
static void __exit cleanup_slots(void)
{
struct list_head *tmp;
struct list_head *next;
struct slot *slot;
list_for_each_safe(tmp, next, &slot_list) {
slot = list_entry(tmp, struct slot, slot_list);
list_del(&slot->slot_list);
pci_hp_deregister(slot->hotplug_slot);
}
}
static int __init pcihp_skel_init(void)
{
int retval;
info(DRIVER_DESC " version: " DRIVER_VERSION "\n");
num_slots = 5;
return init_slots();
}
static void __exit pcihp_skel_exit(void)
{
cleanup_slots();
}
