static void release_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, hotplug_slot_name(hotplug_slot));
kfree(hotplug_slot->ops);
kfree(hotplug_slot->info);
kfree(hotplug_slot);
}
static int init_slot(struct controller *ctrl)
{
struct slot *slot = ctrl->slot;
struct hotplug_slot *hotplug = NULL;
struct hotplug_slot_info *info = NULL;
struct hotplug_slot_ops *ops = NULL;
char name[SLOT_NAME_SIZE];
int retval = -ENOMEM;
hotplug = kzalloc(sizeof(*hotplug), GFP_KERNEL);
if (!hotplug)
goto out;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
goto out;
ops = kzalloc(sizeof(*ops), GFP_KERNEL);
if (!ops)
goto out;
ops->enable_slot = enable_slot;
ops->disable_slot = disable_slot;
ops->get_power_status = get_power_status;
ops->get_adapter_status = get_adapter_status;
if (MRL_SENS(ctrl))
ops->get_latch_status = get_latch_status;
if (ATTN_LED(ctrl)) {
ops->get_attention_status = get_attention_status;
ops->set_attention_status = set_attention_status;
}
hotplug->info = info;
hotplug->private = slot;
hotplug->release = &release_slot;
hotplug->ops = ops;
slot->hotplug_slot = hotplug;
snprintf(name, SLOT_NAME_SIZE, "%u", PSN(ctrl));
ctrl_dbg(ctrl, "Registering domain:bus:dev=%04x:%02x:00 sun=%x\n",
pci_domain_nr(ctrl->pcie->port->subordinate),
ctrl->pcie->port->subordinate->number, PSN(ctrl));
retval = pci_hp_register(hotplug,
ctrl->pcie->port->subordinate, 0, name);
if (retval)
ctrl_err(ctrl,
"pci_hp_register failed with error %d\n", retval);
out:
if (retval) {
kfree(ops);
kfree(info);
kfree(hotplug);
}
return retval;
}
static void cleanup_slot(struct controller *ctrl)
{
pci_hp_deregister(ctrl->slot->hotplug_slot);
}
static int set_attention_status(struct hotplug_slot *hotplug_slot, u8 status)
{
struct slot *slot = hotplug_slot->private;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
return pciehp_set_attention_status(slot, status);
}
static int enable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
return pciehp_sysfs_enable_slot(slot);
}
static int disable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
return pciehp_sysfs_disable_slot(slot);
}
static int get_power_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
return pciehp_get_power_status(slot, value);
}
static int get_attention_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
return pciehp_get_attention_status(slot, value);
}
static int get_latch_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
return pciehp_get_latch_status(slot, value);
}
static int get_adapter_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
ctrl_dbg(slot->ctrl, "%s: physical_slot = %s\n",
__func__, slot_name(slot));
return pciehp_get_adapter_status(slot, value);
}
static int pciehp_probe(struct pcie_device *dev)
{
int rc;
struct controller *ctrl;
struct slot *slot;
u8 occupied, poweron;
if (pciehp_force)
dev_info(&dev->device,
"Bypassing BIOS check for pciehp use on %s\n",
pci_name(dev->port));
else if (pciehp_acpi_slot_detection_check(dev->port))
goto err_out_none;
ctrl = pcie_init(dev);
if (!ctrl) {
dev_err(&dev->device, "Controller initialization failed\n");
goto err_out_none;
}
set_service_data(dev, ctrl);
rc = init_slot(ctrl);
if (rc) {
if (rc == -EBUSY)
ctrl_warn(ctrl, "Slot already registered by another "
"hotplug driver\n");
else
ctrl_err(ctrl, "Slot initialization failed\n");
goto err_out_release_ctlr;
}
rc = pcie_init_notification(ctrl);
if (rc) {
ctrl_err(ctrl, "Notification initialization failed\n");
goto err_out_free_ctrl_slot;
}
slot = ctrl->slot;
pciehp_get_adapter_status(slot, &occupied);
pciehp_get_power_status(slot, &poweron);
if (occupied && pciehp_force)
pciehp_enable_slot(slot);
if (!occupied && poweron && POWER_CTRL(ctrl))
pciehp_power_off_slot(slot);
return 0;
err_out_free_ctrl_slot:
cleanup_slot(ctrl);
err_out_release_ctlr:
pciehp_release_ctrl(ctrl);
err_out_none:
return -ENODEV;
}
static void pciehp_remove(struct pcie_device *dev)
{
struct controller *ctrl = get_service_data(dev);
cleanup_slot(ctrl);
pciehp_release_ctrl(ctrl);
}
static int pciehp_suspend (struct pcie_device *dev)
{
dev_info(&dev->device, "%s ENTRY\n", __func__);
return 0;
}
static int pciehp_resume (struct pcie_device *dev)
{
dev_info(&dev->device, "%s ENTRY\n", __func__);
if (pciehp_force) {
struct controller *ctrl = get_service_data(dev);
struct slot *slot;
u8 status;
pcie_enable_notification(ctrl);
slot = ctrl->slot;
pciehp_get_adapter_status(slot, &status);
if (status)
pciehp_enable_slot(slot);
else
pciehp_disable_slot(slot);
}
return 0;
}
static int __init pcied_init(void)
{
int retval = 0;
pciehp_wq = alloc_workqueue("pciehp", 0, 0);
if (!pciehp_wq)
return -ENOMEM;
pciehp_ordered_wq = alloc_ordered_workqueue("pciehp_ordered", 0);
if (!pciehp_ordered_wq) {
destroy_workqueue(pciehp_wq);
return -ENOMEM;
}
pciehp_firmware_init();
retval = pcie_port_service_register(&hpdriver_portdrv);
dbg("pcie_port_service_register = %d\n", retval);
info(DRIVER_DESC " version: " DRIVER_VERSION "\n");
if (retval) {
destroy_workqueue(pciehp_ordered_wq);
destroy_workqueue(pciehp_wq);
dbg("Failure to register service\n");
}
return retval;
}
static void __exit pcied_cleanup(void)
{
dbg("unload_pciehpd()\n");
destroy_workqueue(pciehp_ordered_wq);
destroy_workqueue(pciehp_wq);
pcie_port_service_unregister(&hpdriver_portdrv);
info(DRIVER_DESC " version: " DRIVER_VERSION " unloaded\n");
}
