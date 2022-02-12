static int zpci_fn_configured(enum zpci_state state)
{
return state == ZPCI_FN_STATE_CONFIGURED ||
state == ZPCI_FN_STATE_ONLINE;
}
static int enable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
int rc;
if (slot->zdev->state != ZPCI_FN_STATE_STANDBY)
return -EIO;
rc = sclp_pci_configure(slot->zdev->fid);
if (!rc) {
slot->zdev->state = ZPCI_FN_STATE_CONFIGURED;
zpci_enable_device(slot->zdev);
zpci_scan_device(slot->zdev);
}
return rc;
}
static int disable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
int rc;
if (!zpci_fn_configured(slot->zdev->state))
return -EIO;
rc = sclp_pci_deconfigure(slot->zdev->fid);
if (!rc) {
slot->zdev->fh &= 0x7fffffff;
slot->zdev->state = ZPCI_FN_STATE_STANDBY;
}
return rc;
}
static int get_power_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
switch (slot->zdev->state) {
case ZPCI_FN_STATE_STANDBY:
*value = 0;
break;
default:
*value = 1;
break;
}
return 0;
}
static int get_adapter_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
*value = 1;
return 0;
}
static void release_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
pr_debug("%s - physical_slot = %s\n", __func__, hotplug_slot_name(hotplug_slot));
kfree(slot->hotplug_slot->info);
kfree(slot->hotplug_slot);
kfree(slot);
}
static int init_pci_slot(struct zpci_dev *zdev)
{
struct hotplug_slot *hotplug_slot;
struct hotplug_slot_info *info;
char name[SLOT_NAME_SIZE];
struct slot *slot;
int rc;
if (!zdev)
return 0;
slot = kzalloc(sizeof(*slot), GFP_KERNEL);
if (!slot)
goto error;
hotplug_slot = kzalloc(sizeof(*hotplug_slot), GFP_KERNEL);
if (!hotplug_slot)
goto error_hp;
hotplug_slot->private = slot;
slot->hotplug_slot = hotplug_slot;
slot->zdev = zdev;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
goto error_info;
hotplug_slot->info = info;
hotplug_slot->ops = &s390_hotplug_slot_ops;
hotplug_slot->release = &release_slot;
get_power_status(hotplug_slot, &info->power_status);
get_adapter_status(hotplug_slot, &info->adapter_status);
snprintf(name, SLOT_NAME_SIZE, "%08x", zdev->fid);
rc = pci_hp_register(slot->hotplug_slot, zdev->bus,
ZPCI_DEVFN, name);
if (rc) {
pr_err("pci_hp_register failed with error %d\n", rc);
goto error_reg;
}
list_add(&slot->slot_list, &s390_hotplug_slot_list);
return 0;
error_reg:
kfree(info);
error_info:
kfree(hotplug_slot);
error_hp:
kfree(slot);
error:
return -ENOMEM;
}
static void exit_pci_slot(struct zpci_dev *zdev)
{
struct list_head *tmp, *n;
struct slot *slot;
list_for_each_safe(tmp, n, &s390_hotplug_slot_list) {
slot = list_entry(tmp, struct slot, slot_list);
if (slot->zdev != zdev)
continue;
list_del(&slot->slot_list);
pci_hp_deregister(slot->hotplug_slot);
}
}
static void __init init_pci_slots(void)
{
struct zpci_dev *zdev;
mutex_lock(&zpci_list_lock);
list_for_each_entry(zdev, &zpci_list, entry) {
init_pci_slot(zdev);
}
mutex_unlock(&zpci_list_lock);
}
static void __exit exit_pci_slots(void)
{
struct list_head *tmp, *n;
struct slot *slot;
list_for_each_safe(tmp, n, &s390_hotplug_slot_list) {
slot = list_entry(tmp, struct slot, slot_list);
list_del(&slot->slot_list);
pci_hp_deregister(slot->hotplug_slot);
}
}
static int __init pci_hotplug_s390_init(void)
{
if (!s390_pci_probe)
return -EOPNOTSUPP;
zpci_register_hp_ops(&hp_ops);
init_pci_slots();
return 0;
}
static void __exit pci_hotplug_s390_exit(void)
{
exit_pci_slots();
zpci_deregister_hp_ops();
}
