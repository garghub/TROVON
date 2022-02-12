int pcie_port_acpi_setup(struct pci_dev *port, int *srv_mask)
{
struct acpi_pci_root *root;
acpi_handle handle;
u32 flags;
if (acpi_pci_disabled)
return 0;
handle = acpi_find_root_bridge_handle(port);
if (!handle)
return -EINVAL;
root = acpi_pci_find_root(handle);
if (!root)
return -ENODEV;
flags = root->osc_control_set;
*srv_mask = PCIE_PORT_SERVICE_VC;
if (flags & OSC_PCI_EXPRESS_NATIVE_HP_CONTROL)
*srv_mask |= PCIE_PORT_SERVICE_HP;
if (flags & OSC_PCI_EXPRESS_PME_CONTROL)
*srv_mask |= PCIE_PORT_SERVICE_PME;
if (flags & OSC_PCI_EXPRESS_AER_CONTROL)
*srv_mask |= PCIE_PORT_SERVICE_AER;
return 0;
}
