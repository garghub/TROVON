static inline void register_capability(struct xen_pcibk_config_capability *cap)
{
list_add_tail(&cap->cap_list, &capabilities);
}
int xen_pcibk_config_capability_add_fields(struct pci_dev *dev)
{
int err = 0;
struct xen_pcibk_config_capability *cap;
int cap_offset;
list_for_each_entry(cap, &capabilities, cap_list) {
cap_offset = pci_find_capability(dev, cap->capability);
if (cap_offset) {
dev_dbg(&dev->dev, "Found capability 0x%x at 0x%x\n",
cap->capability, cap_offset);
err = xen_pcibk_config_add_fields_offset(dev,
caplist_header,
cap_offset);
if (err)
goto out;
err = xen_pcibk_config_add_fields_offset(dev,
cap->fields,
cap_offset);
if (err)
goto out;
}
}
out:
return err;
}
static int vpd_address_write(struct pci_dev *dev, int offset, u16 value,
void *data)
{
if (value & PCI_VPD_ADDR_F)
return PCIBIOS_SET_FAILED;
else
return pci_write_config_word(dev, offset, value);
}
static int pm_caps_read(struct pci_dev *dev, int offset, u16 *value,
void *data)
{
int err;
u16 real_value;
err = pci_read_config_word(dev, offset, &real_value);
if (err)
goto out;
*value = real_value & ~PCI_PM_CAP_PME_MASK;
out:
return err;
}
static int pm_ctrl_write(struct pci_dev *dev, int offset, u16 new_value,
void *data)
{
int err;
u16 old_value;
pci_power_t new_state, old_state;
err = pci_read_config_word(dev, offset, &old_value);
if (err)
goto out;
old_state = (pci_power_t)(old_value & PCI_PM_CTRL_STATE_MASK);
new_state = (pci_power_t)(new_value & PCI_PM_CTRL_STATE_MASK);
new_value &= PM_OK_BITS;
if ((old_value & PM_OK_BITS) != new_value) {
new_value = (old_value & ~PM_OK_BITS) | new_value;
err = pci_write_config_word(dev, offset, new_value);
if (err)
goto out;
}
dev_dbg(&dev->dev, "set power state to %x\n", new_state);
err = pci_set_power_state(dev, new_state);
if (err) {
err = PCIBIOS_SET_FAILED;
goto out;
}
out:
return err;
}
static void *pm_ctrl_init(struct pci_dev *dev, int offset)
{
int err;
u16 value;
err = pci_read_config_word(dev, offset, &value);
if (err)
goto out;
if (value & PCI_PM_CTRL_PME_ENABLE) {
value &= ~PCI_PM_CTRL_PME_ENABLE;
err = pci_write_config_word(dev, offset, value);
}
out:
return ERR_PTR(err);
}
int xen_pcibk_config_capability_init(void)
{
register_capability(&xen_pcibk_config_capability_vpd);
register_capability(&xen_pcibk_config_capability_pm);
return 0;
}
