int pciehp_configure_device(struct slot *p_slot)
{
struct pci_dev *dev;
struct pci_dev *bridge = p_slot->ctrl->pcie->port;
struct pci_bus *parent = bridge->subordinate;
int num, ret = 0;
struct controller *ctrl = p_slot->ctrl;
pci_lock_rescan_remove();
dev = pci_get_slot(parent, PCI_DEVFN(0, 0));
if (dev) {
ctrl_err(ctrl, "Device %s already exists "
"at %04x:%02x:00, cannot hot-add\n", pci_name(dev),
pci_domain_nr(parent), parent->number);
pci_dev_put(dev);
ret = -EINVAL;
goto out;
}
num = pci_scan_slot(parent, PCI_DEVFN(0, 0));
if (num == 0) {
ctrl_err(ctrl, "No new device found\n");
ret = -ENODEV;
goto out;
}
list_for_each_entry(dev, &parent->devices, bus_list)
if ((dev->hdr_type == PCI_HEADER_TYPE_BRIDGE) ||
(dev->hdr_type == PCI_HEADER_TYPE_CARDBUS))
pci_hp_add_bridge(dev);
pci_assign_unassigned_bridge_resources(bridge);
list_for_each_entry(dev, &parent->devices, bus_list) {
if ((dev->class >> 16) == PCI_BASE_CLASS_DISPLAY)
continue;
pci_configure_slot(dev);
}
pci_bus_add_devices(parent);
out:
pci_unlock_rescan_remove();
return ret;
}
int pciehp_unconfigure_device(struct slot *p_slot)
{
int rc = 0;
u8 bctl = 0;
u8 presence = 0;
struct pci_dev *dev, *temp;
struct pci_bus *parent = p_slot->ctrl->pcie->port->subordinate;
u16 command;
struct controller *ctrl = p_slot->ctrl;
ctrl_dbg(ctrl, "%s: domain:bus:dev = %04x:%02x:00\n",
__func__, pci_domain_nr(parent), parent->number);
pciehp_get_adapter_status(p_slot, &presence);
pci_lock_rescan_remove();
list_for_each_entry_safe_reverse(dev, temp, &parent->devices,
bus_list) {
pci_dev_get(dev);
if (dev->hdr_type == PCI_HEADER_TYPE_BRIDGE && presence) {
pci_read_config_byte(dev, PCI_BRIDGE_CONTROL, &bctl);
if (bctl & PCI_BRIDGE_CTL_VGA) {
ctrl_err(ctrl,
"Cannot remove display device %s\n",
pci_name(dev));
pci_dev_put(dev);
rc = -EINVAL;
break;
}
}
pci_stop_and_remove_bus_device(dev);
if (presence) {
pci_read_config_word(dev, PCI_COMMAND, &command);
command &= ~(PCI_COMMAND_MASTER | PCI_COMMAND_SERR);
command |= PCI_COMMAND_INTX_DISABLE;
pci_write_config_word(dev, PCI_COMMAND, command);
}
pci_dev_put(dev);
}
pci_unlock_rescan_remove();
return rc;
}
