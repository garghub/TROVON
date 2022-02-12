static void program_hpp_type0(struct pci_dev *dev, struct hpp_type0 *hpp)
{
u16 pci_cmd, pci_bctl;
if (!hpp) {
if (pci_is_pcie(dev))
return;
dev_info(&dev->dev, "using default PCI settings\n");
hpp = &pci_default_type0;
}
if (hpp->revision > 1) {
dev_warn(&dev->dev,
"PCI settings rev %d not supported; using defaults\n",
hpp->revision);
hpp = &pci_default_type0;
}
pci_write_config_byte(dev, PCI_CACHE_LINE_SIZE, hpp->cache_line_size);
pci_write_config_byte(dev, PCI_LATENCY_TIMER, hpp->latency_timer);
pci_read_config_word(dev, PCI_COMMAND, &pci_cmd);
if (hpp->enable_serr)
pci_cmd |= PCI_COMMAND_SERR;
else
pci_cmd &= ~PCI_COMMAND_SERR;
if (hpp->enable_perr)
pci_cmd |= PCI_COMMAND_PARITY;
else
pci_cmd &= ~PCI_COMMAND_PARITY;
pci_write_config_word(dev, PCI_COMMAND, pci_cmd);
if ((dev->class >> 8) == PCI_CLASS_BRIDGE_PCI) {
pci_write_config_byte(dev, PCI_SEC_LATENCY_TIMER,
hpp->latency_timer);
pci_read_config_word(dev, PCI_BRIDGE_CONTROL, &pci_bctl);
if (hpp->enable_serr)
pci_bctl |= PCI_BRIDGE_CTL_SERR;
else
pci_bctl &= ~PCI_BRIDGE_CTL_SERR;
if (hpp->enable_perr)
pci_bctl |= PCI_BRIDGE_CTL_PARITY;
else
pci_bctl &= ~PCI_BRIDGE_CTL_PARITY;
pci_write_config_word(dev, PCI_BRIDGE_CONTROL, pci_bctl);
}
}
static void program_hpp_type1(struct pci_dev *dev, struct hpp_type1 *hpp)
{
if (hpp)
dev_warn(&dev->dev, "PCI-X settings not supported\n");
}
static void program_hpp_type2(struct pci_dev *dev, struct hpp_type2 *hpp)
{
int pos;
u32 reg32;
if (!hpp)
return;
if (hpp->revision > 1) {
dev_warn(&dev->dev, "PCIe settings rev %d not supported\n",
hpp->revision);
return;
}
pcie_capability_clear_and_set_word(dev, PCI_EXP_DEVCTL,
~hpp->pci_exp_devctl_and, hpp->pci_exp_devctl_or);
if (dev->subordinate)
pcie_capability_clear_and_set_word(dev, PCI_EXP_LNKCTL,
~hpp->pci_exp_lnkctl_and, hpp->pci_exp_lnkctl_or);
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ERR);
if (!pos)
return;
pci_read_config_dword(dev, pos + PCI_ERR_UNCOR_MASK, &reg32);
reg32 = (reg32 & hpp->unc_err_mask_and) | hpp->unc_err_mask_or;
pci_write_config_dword(dev, pos + PCI_ERR_UNCOR_MASK, reg32);
pci_read_config_dword(dev, pos + PCI_ERR_UNCOR_SEVER, &reg32);
reg32 = (reg32 & hpp->unc_err_sever_and) | hpp->unc_err_sever_or;
pci_write_config_dword(dev, pos + PCI_ERR_UNCOR_SEVER, reg32);
pci_read_config_dword(dev, pos + PCI_ERR_COR_MASK, &reg32);
reg32 = (reg32 & hpp->cor_err_mask_and) | hpp->cor_err_mask_or;
pci_write_config_dword(dev, pos + PCI_ERR_COR_MASK, reg32);
pci_read_config_dword(dev, pos + PCI_ERR_CAP, &reg32);
reg32 = (reg32 & hpp->adv_err_cap_and) | hpp->adv_err_cap_or;
pci_write_config_dword(dev, pos + PCI_ERR_CAP, reg32);
}
void pci_configure_slot(struct pci_dev *dev)
{
struct pci_dev *cdev;
struct hotplug_params hpp;
int ret;
if (!(dev->hdr_type == PCI_HEADER_TYPE_NORMAL ||
(dev->hdr_type == PCI_HEADER_TYPE_BRIDGE &&
(dev->class >> 8) == PCI_CLASS_BRIDGE_PCI)))
return;
if (dev->bus && dev->bus->self)
pcie_bus_configure_settings(dev->bus,
dev->bus->self->pcie_mpss);
memset(&hpp, 0, sizeof(hpp));
ret = pci_get_hp_params(dev, &hpp);
if (ret)
dev_warn(&dev->dev, "no hotplug settings from platform\n");
program_hpp_type2(dev, hpp.t2);
program_hpp_type1(dev, hpp.t1);
program_hpp_type0(dev, hpp.t0);
if (dev->subordinate) {
list_for_each_entry(cdev, &dev->subordinate->devices,
bus_list)
pci_configure_slot(cdev);
}
}
