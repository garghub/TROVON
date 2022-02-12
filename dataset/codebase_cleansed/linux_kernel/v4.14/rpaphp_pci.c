int rpaphp_get_sensor_state(struct slot *slot, int *state)
{
int rc;
int setlevel;
rc = rtas_get_sensor(DR_ENTITY_SENSE, slot->index, state);
if (rc < 0) {
if (rc == -EFAULT || rc == -EEXIST) {
dbg("%s: slot must be power up to get sensor-state\n",
__func__);
rc = rtas_set_power_level(slot->power_domain, POWER_ON,
&setlevel);
if (rc < 0) {
dbg("%s: power on slot[%s] failed rc=%d.\n",
__func__, slot->name, rc);
} else {
rc = rtas_get_sensor(DR_ENTITY_SENSE,
slot->index, state);
}
} else if (rc == -ENODEV)
info("%s: slot is unusable\n", __func__);
else
err("%s failed to get sensor state\n", __func__);
}
return rc;
}
int rpaphp_enable_slot(struct slot *slot)
{
int rc, level, state;
struct pci_bus *bus;
struct hotplug_slot_info *info = slot->hotplug_slot->info;
info->adapter_status = NOT_VALID;
slot->state = EMPTY;
rc = rtas_get_power_level(slot->power_domain, &level);
if (rc)
return rc;
info->power_status = level;
rc = rpaphp_get_sensor_state(slot, &state);
if (rc)
return rc;
bus = pci_find_bus_by_node(slot->dn);
if (!bus) {
err("%s: no pci_bus for dn %pOF\n", __func__, slot->dn);
return -EINVAL;
}
info->adapter_status = EMPTY;
slot->bus = bus;
slot->pci_devs = &bus->devices;
if (state == PRESENT) {
info->adapter_status = NOT_CONFIGURED;
slot->state = NOT_CONFIGURED;
if (!slot->dn->child) {
err("%s: slot[%s]'s device_node doesn't have child for adapter\n",
__func__, slot->name);
return -EINVAL;
}
if (list_empty(&bus->devices))
pci_hp_add_devices(bus);
if (!list_empty(&bus->devices)) {
info->adapter_status = CONFIGURED;
slot->state = CONFIGURED;
}
if (rpaphp_debug) {
struct pci_dev *dev;
dbg("%s: pci_devs of slot[%pOF]\n", __func__, slot->dn);
list_for_each_entry(dev, &bus->devices, bus_list)
dbg("\t%s\n", pci_name(dev));
}
}
return 0;
}
