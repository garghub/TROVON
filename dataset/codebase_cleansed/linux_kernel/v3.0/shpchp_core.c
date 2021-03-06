static void release_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
kfree(slot->hotplug_slot->info);
kfree(slot->hotplug_slot);
kfree(slot);
}
static int init_slots(struct controller *ctrl)
{
struct slot *slot;
struct hotplug_slot *hotplug_slot;
struct hotplug_slot_info *info;
char name[SLOT_NAME_SIZE];
int retval = -ENOMEM;
int i;
for (i = 0; i < ctrl->num_slots; i++) {
slot = kzalloc(sizeof(*slot), GFP_KERNEL);
if (!slot)
goto error;
hotplug_slot = kzalloc(sizeof(*hotplug_slot), GFP_KERNEL);
if (!hotplug_slot)
goto error_slot;
slot->hotplug_slot = hotplug_slot;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
goto error_hpslot;
hotplug_slot->info = info;
slot->hp_slot = i;
slot->ctrl = ctrl;
slot->bus = ctrl->pci_dev->subordinate->number;
slot->device = ctrl->slot_device_offset + i;
slot->hpc_ops = ctrl->hpc_ops;
slot->number = ctrl->first_slot + (ctrl->slot_num_inc * i);
mutex_init(&slot->lock);
INIT_DELAYED_WORK(&slot->work, shpchp_queue_pushbutton_work);
hotplug_slot->private = slot;
hotplug_slot->release = &release_slot;
snprintf(name, SLOT_NAME_SIZE, "%d", slot->number);
hotplug_slot->ops = &shpchp_hotplug_slot_ops;
ctrl_dbg(ctrl, "Registering domain:bus:dev=%04x:%02x:%02x "
"hp_slot=%x sun=%x slot_device_offset=%x\n",
pci_domain_nr(ctrl->pci_dev->subordinate),
slot->bus, slot->device, slot->hp_slot, slot->number,
ctrl->slot_device_offset);
retval = pci_hp_register(slot->hotplug_slot,
ctrl->pci_dev->subordinate, slot->device, name);
if (retval) {
ctrl_err(ctrl, "pci_hp_register failed with error %d\n",
retval);
goto error_info;
}
get_power_status(hotplug_slot, &info->power_status);
get_attention_status(hotplug_slot, &info->attention_status);
get_latch_status(hotplug_slot, &info->latch_status);
get_adapter_status(hotplug_slot, &info->adapter_status);
list_add(&slot->slot_list, &ctrl->slot_list);
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
void cleanup_slots(struct controller *ctrl)
{
struct list_head *tmp;
struct list_head *next;
struct slot *slot;
list_for_each_safe(tmp, next, &ctrl->slot_list) {
slot = list_entry(tmp, struct slot, slot_list);
list_del(&slot->slot_list);
cancel_delayed_work(&slot->work);
flush_workqueue(shpchp_wq);
flush_workqueue(shpchp_ordered_wq);
pci_hp_deregister(slot->hotplug_slot);
}
}
static int set_attention_status (struct hotplug_slot *hotplug_slot, u8 status)
{
struct slot *slot = get_slot(hotplug_slot);
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
hotplug_slot->info->attention_status = status;
slot->hpc_ops->set_attention_status(slot, status);
return 0;
}
static int enable_slot (struct hotplug_slot *hotplug_slot)
{
struct slot *slot = get_slot(hotplug_slot);
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
return shpchp_sysfs_enable_slot(slot);
}
static int disable_slot (struct hotplug_slot *hotplug_slot)
{
struct slot *slot = get_slot(hotplug_slot);
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
return shpchp_sysfs_disable_slot(slot);
}
static int get_power_status (struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = get_slot(hotplug_slot);
int retval;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
retval = slot->hpc_ops->get_power_status(slot, value);
if (retval < 0)
*value = hotplug_slot->info->power_status;
return 0;
}
static int get_attention_status (struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = get_slot(hotplug_slot);
int retval;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
retval = slot->hpc_ops->get_attention_status(slot, value);
if (retval < 0)
*value = hotplug_slot->info->attention_status;
return 0;
}
static int get_latch_status (struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = get_slot(hotplug_slot);
int retval;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
retval = slot->hpc_ops->get_latch_status(slot, value);
if (retval < 0)
*value = hotplug_slot->info->latch_status;
return 0;
}
static int get_adapter_status (struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = get_slot(hotplug_slot);
int retval;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
retval = slot->hpc_ops->get_adapter_status(slot, value);
if (retval < 0)
*value = hotplug_slot->info->adapter_status;
return 0;
}
static int is_shpc_capable(struct pci_dev *dev)
{
if ((dev->vendor == PCI_VENDOR_ID_AMD) || (dev->device ==
PCI_DEVICE_ID_AMD_GOLAM_7450))
return 1;
if (!pci_find_capability(dev, PCI_CAP_ID_SHPC))
return 0;
if (get_hp_hw_control_from_firmware(dev))
return 0;
return 1;
}
static int shpc_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc;
struct controller *ctrl;
if (!is_shpc_capable(pdev))
return -ENODEV;
ctrl = kzalloc(sizeof(*ctrl), GFP_KERNEL);
if (!ctrl) {
dev_err(&pdev->dev, "%s: Out of memory\n", __func__);
goto err_out_none;
}
INIT_LIST_HEAD(&ctrl->slot_list);
rc = shpc_init(ctrl, pdev);
if (rc) {
ctrl_dbg(ctrl, "Controller initialization failed\n");
goto err_out_free_ctrl;
}
pci_set_drvdata(pdev, ctrl);
rc = init_slots(ctrl);
if (rc) {
ctrl_err(ctrl, "Slot initialization failed\n");
goto err_out_release_ctlr;
}
rc = shpchp_create_ctrl_files(ctrl);
if (rc)
goto err_cleanup_slots;
return 0;
err_cleanup_slots:
cleanup_slots(ctrl);
err_out_release_ctlr:
ctrl->hpc_ops->release_ctlr(ctrl);
err_out_free_ctrl:
kfree(ctrl);
err_out_none:
return -ENODEV;
}
static void shpc_remove(struct pci_dev *dev)
{
struct controller *ctrl = pci_get_drvdata(dev);
shpchp_remove_ctrl_files(ctrl);
ctrl->hpc_ops->release_ctlr(ctrl);
kfree(ctrl);
}
static int __init shpcd_init(void)
{
int retval = 0;
shpchp_wq = alloc_ordered_workqueue("shpchp", 0);
if (!shpchp_wq)
return -ENOMEM;
shpchp_ordered_wq = alloc_ordered_workqueue("shpchp_ordered", 0);
if (!shpchp_ordered_wq) {
destroy_workqueue(shpchp_wq);
return -ENOMEM;
}
retval = pci_register_driver(&shpc_driver);
dbg("%s: pci_register_driver = %d\n", __func__, retval);
info(DRIVER_DESC " version: " DRIVER_VERSION "\n");
if (retval) {
destroy_workqueue(shpchp_ordered_wq);
destroy_workqueue(shpchp_wq);
}
return retval;
}
static void __exit shpcd_cleanup(void)
{
dbg("unload_shpchpd()\n");
pci_unregister_driver(&shpc_driver);
destroy_workqueue(shpchp_ordered_wq);
destroy_workqueue(shpchp_wq);
info(DRIVER_DESC " version: " DRIVER_VERSION " unloaded\n");
}
