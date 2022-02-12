int acpiphp_register_attention(struct acpiphp_attention_info *info)
{
int retval = -EINVAL;
if (info && info->owner && info->set_attn &&
info->get_attn && !attention_info) {
retval = 0;
attention_info = info;
}
return retval;
}
int acpiphp_unregister_attention(struct acpiphp_attention_info *info)
{
int retval = -EINVAL;
if (info && attention_info == info) {
attention_info = NULL;
retval = 0;
}
return retval;
}
static int enable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
dbg("%s - physical_slot = %s\n", __func__, slot_name(slot));
return acpiphp_enable_slot(slot->acpi_slot);
}
static int disable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
int retval;
dbg("%s - physical_slot = %s\n", __func__, slot_name(slot));
retval = acpiphp_disable_slot(slot->acpi_slot);
if (!retval)
retval = acpiphp_eject_slot(slot->acpi_slot);
return retval;
}
static int set_attention_status(struct hotplug_slot *hotplug_slot, u8 status)
{
int retval = -ENODEV;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot_name(hotplug_slot));
if (attention_info && try_module_get(attention_info->owner)) {
retval = attention_info->set_attn(hotplug_slot, status);
module_put(attention_info->owner);
} else
attention_info = NULL;
return retval;
}
static int get_power_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
dbg("%s - physical_slot = %s\n", __func__, slot_name(slot));
*value = acpiphp_get_power_status(slot->acpi_slot);
return 0;
}
static int get_attention_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
int retval = -EINVAL;
dbg("%s - physical_slot = %s\n", __func__, hotplug_slot_name(hotplug_slot));
if (attention_info && try_module_get(attention_info->owner)) {
retval = attention_info->get_attn(hotplug_slot, value);
module_put(attention_info->owner);
} else
attention_info = NULL;
return retval;
}
static int get_latch_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
dbg("%s - physical_slot = %s\n", __func__, slot_name(slot));
*value = acpiphp_get_latch_status(slot->acpi_slot);
return 0;
}
static int get_adapter_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
dbg("%s - physical_slot = %s\n", __func__, slot_name(slot));
*value = acpiphp_get_adapter_status(slot->acpi_slot);
return 0;
}
static int __init init_acpi(void)
{
int retval;
retval = acpiphp_glue_init();
if (!retval) {
num_slots = acpiphp_get_num_slots();
if (num_slots == 0) {
acpiphp_glue_exit();
retval = -ENODEV;
}
}
return retval;
}
static void release_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
dbg("%s - physical_slot = %s\n", __func__, slot_name(slot));
kfree(slot->hotplug_slot);
kfree(slot);
}
int acpiphp_register_hotplug_slot(struct acpiphp_slot *acpiphp_slot)
{
struct slot *slot;
int retval = -ENOMEM;
char name[SLOT_NAME_SIZE];
slot = kzalloc(sizeof(*slot), GFP_KERNEL);
if (!slot)
goto error;
slot->hotplug_slot = kzalloc(sizeof(*slot->hotplug_slot), GFP_KERNEL);
if (!slot->hotplug_slot)
goto error_slot;
slot->hotplug_slot->info = &slot->info;
slot->hotplug_slot->private = slot;
slot->hotplug_slot->release = &release_slot;
slot->hotplug_slot->ops = &acpi_hotplug_slot_ops;
slot->acpi_slot = acpiphp_slot;
slot->hotplug_slot->info->power_status = acpiphp_get_power_status(slot->acpi_slot);
slot->hotplug_slot->info->attention_status = 0;
slot->hotplug_slot->info->latch_status = acpiphp_get_latch_status(slot->acpi_slot);
slot->hotplug_slot->info->adapter_status = acpiphp_get_adapter_status(slot->acpi_slot);
acpiphp_slot->slot = slot;
snprintf(name, SLOT_NAME_SIZE, "%llu", slot->acpi_slot->sun);
retval = pci_hp_register(slot->hotplug_slot,
acpiphp_slot->bridge->pci_bus,
acpiphp_slot->device,
name);
if (retval == -EBUSY)
goto error_hpslot;
if (retval) {
err("pci_hp_register failed with error %d\n", retval);
goto error_hpslot;
}
info("Slot [%s] registered\n", slot_name(slot));
return 0;
error_hpslot:
kfree(slot->hotplug_slot);
error_slot:
kfree(slot);
error:
return retval;
}
void acpiphp_unregister_hotplug_slot(struct acpiphp_slot *acpiphp_slot)
{
struct slot *slot = acpiphp_slot->slot;
int retval = 0;
info("Slot [%s] unregistered\n", slot_name(slot));
retval = pci_hp_deregister(slot->hotplug_slot);
if (retval)
err("pci_hp_deregister failed with error %d\n", retval);
}
static int __init acpiphp_init(void)
{
info(DRIVER_DESC " version: " DRIVER_VERSION "\n");
if (acpi_pci_disabled)
return 0;
return init_acpi();
}
static void __exit acpiphp_exit(void)
{
if (acpi_pci_disabled)
return;
acpiphp_glue_exit();
}
