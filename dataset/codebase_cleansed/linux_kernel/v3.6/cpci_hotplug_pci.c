u8 cpci_get_attention_status(struct slot* slot)
{
int hs_cap;
u16 hs_csr;
hs_cap = pci_bus_find_capability(slot->bus,
slot->devfn,
PCI_CAP_ID_CHSWP);
if (!hs_cap)
return 0;
if (pci_bus_read_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
&hs_csr))
return 0;
return hs_csr & 0x0008 ? 1 : 0;
}
int cpci_set_attention_status(struct slot* slot, int status)
{
int hs_cap;
u16 hs_csr;
hs_cap = pci_bus_find_capability(slot->bus,
slot->devfn,
PCI_CAP_ID_CHSWP);
if (!hs_cap)
return 0;
if (pci_bus_read_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
&hs_csr))
return 0;
if (status)
hs_csr |= HS_CSR_LOO;
else
hs_csr &= ~HS_CSR_LOO;
if (pci_bus_write_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
hs_csr))
return 0;
return 1;
}
u16 cpci_get_hs_csr(struct slot* slot)
{
int hs_cap;
u16 hs_csr;
hs_cap = pci_bus_find_capability(slot->bus,
slot->devfn,
PCI_CAP_ID_CHSWP);
if (!hs_cap)
return 0xFFFF;
if (pci_bus_read_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
&hs_csr))
return 0xFFFF;
return hs_csr;
}
int cpci_check_and_clear_ins(struct slot* slot)
{
int hs_cap;
u16 hs_csr;
int ins = 0;
hs_cap = pci_bus_find_capability(slot->bus,
slot->devfn,
PCI_CAP_ID_CHSWP);
if (!hs_cap)
return 0;
if (pci_bus_read_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
&hs_csr))
return 0;
if (hs_csr & HS_CSR_INS) {
if (pci_bus_write_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
hs_csr))
ins = 0;
else
ins = 1;
}
return ins;
}
int cpci_check_ext(struct slot* slot)
{
int hs_cap;
u16 hs_csr;
int ext = 0;
hs_cap = pci_bus_find_capability(slot->bus,
slot->devfn,
PCI_CAP_ID_CHSWP);
if (!hs_cap)
return 0;
if (pci_bus_read_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
&hs_csr))
return 0;
if (hs_csr & HS_CSR_EXT)
ext = 1;
return ext;
}
int cpci_clear_ext(struct slot* slot)
{
int hs_cap;
u16 hs_csr;
hs_cap = pci_bus_find_capability(slot->bus,
slot->devfn,
PCI_CAP_ID_CHSWP);
if (!hs_cap)
return -ENODEV;
if (pci_bus_read_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
&hs_csr))
return -ENODEV;
if (hs_csr & HS_CSR_EXT) {
if (pci_bus_write_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
hs_csr))
return -ENODEV;
}
return 0;
}
int cpci_led_on(struct slot* slot)
{
int hs_cap;
u16 hs_csr;
hs_cap = pci_bus_find_capability(slot->bus,
slot->devfn,
PCI_CAP_ID_CHSWP);
if (!hs_cap)
return -ENODEV;
if (pci_bus_read_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
&hs_csr))
return -ENODEV;
if ((hs_csr & HS_CSR_LOO) != HS_CSR_LOO) {
hs_csr |= HS_CSR_LOO;
if (pci_bus_write_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
hs_csr)) {
err("Could not set LOO for slot %s",
hotplug_slot_name(slot->hotplug_slot));
return -ENODEV;
}
}
return 0;
}
int cpci_led_off(struct slot* slot)
{
int hs_cap;
u16 hs_csr;
hs_cap = pci_bus_find_capability(slot->bus,
slot->devfn,
PCI_CAP_ID_CHSWP);
if (!hs_cap)
return -ENODEV;
if (pci_bus_read_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
&hs_csr))
return -ENODEV;
if (hs_csr & HS_CSR_LOO) {
hs_csr &= ~HS_CSR_LOO;
if (pci_bus_write_config_word(slot->bus,
slot->devfn,
hs_cap + 2,
hs_csr)) {
err("Could not clear LOO for slot %s",
hotplug_slot_name(slot->hotplug_slot));
return -ENODEV;
}
}
return 0;
}
int __ref cpci_configure_slot(struct slot *slot)
{
struct pci_bus *parent;
int fn;
dbg("%s - enter", __func__);
if (slot->dev == NULL) {
dbg("pci_dev null, finding %02x:%02x:%x",
slot->bus->number, PCI_SLOT(slot->devfn), PCI_FUNC(slot->devfn));
slot->dev = pci_get_slot(slot->bus, slot->devfn);
}
if (slot->dev == NULL) {
int n;
dbg("pci_dev still null");
n = pci_scan_slot(slot->bus, slot->devfn);
dbg("%s: pci_scan_slot returned %d", __func__, n);
slot->dev = pci_get_slot(slot->bus, slot->devfn);
if (slot->dev == NULL) {
err("Could not find PCI device for slot %02x", slot->number);
return -ENODEV;
}
}
parent = slot->dev->bus;
for (fn = 0; fn < 8; fn++) {
struct pci_dev *dev;
dev = pci_get_slot(parent,
PCI_DEVFN(PCI_SLOT(slot->devfn), fn));
if (!dev)
continue;
if ((dev->hdr_type == PCI_HEADER_TYPE_BRIDGE) ||
(dev->hdr_type == PCI_HEADER_TYPE_CARDBUS))
pci_hp_add_bridge(dev);
pci_dev_put(dev);
}
pci_assign_unassigned_bridge_resources(parent->self);
pci_bus_add_devices(parent);
dbg("%s - exit", __func__);
return 0;
}
int cpci_unconfigure_slot(struct slot* slot)
{
int i;
struct pci_dev *dev;
dbg("%s - enter", __func__);
if (!slot->dev) {
err("No device for slot %02x\n", slot->number);
return -ENODEV;
}
for (i = 0; i < 8; i++) {
dev = pci_get_slot(slot->bus,
PCI_DEVFN(PCI_SLOT(slot->devfn), i));
if (dev) {
pci_stop_and_remove_bus_device(dev);
pci_dev_put(dev);
}
}
pci_dev_put(slot->dev);
slot->dev = NULL;
dbg("%s - exit", __func__);
return 0;
}
