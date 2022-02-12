static int enable_ecrc_checking(struct pci_dev *dev)
{
int pos;
u32 reg32;
if (!pci_is_pcie(dev))
return -ENODEV;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ERR);
if (!pos)
return -ENODEV;
pci_read_config_dword(dev, pos + PCI_ERR_CAP, &reg32);
if (reg32 & PCI_ERR_CAP_ECRC_GENC)
reg32 |= PCI_ERR_CAP_ECRC_GENE;
if (reg32 & PCI_ERR_CAP_ECRC_CHKC)
reg32 |= PCI_ERR_CAP_ECRC_CHKE;
pci_write_config_dword(dev, pos + PCI_ERR_CAP, reg32);
return 0;
}
static int disable_ecrc_checking(struct pci_dev *dev)
{
int pos;
u32 reg32;
if (!pci_is_pcie(dev))
return -ENODEV;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ERR);
if (!pos)
return -ENODEV;
pci_read_config_dword(dev, pos + PCI_ERR_CAP, &reg32);
reg32 &= ~(PCI_ERR_CAP_ECRC_GENE | PCI_ERR_CAP_ECRC_CHKE);
pci_write_config_dword(dev, pos + PCI_ERR_CAP, reg32);
return 0;
}
void pcie_set_ecrc_checking(struct pci_dev *dev)
{
switch (ecrc_policy) {
case ECRC_POLICY_DEFAULT:
return;
case ECRC_POLICY_OFF:
disable_ecrc_checking(dev);
break;
case ECRC_POLICY_ON:
enable_ecrc_checking(dev);
break;
default:
return;
}
}
void pcie_ecrc_get_policy(char *str)
{
int i;
for (i = 0; i < ARRAY_SIZE(ecrc_policy_str); i++)
if (!strncmp(str, ecrc_policy_str[i],
strlen(ecrc_policy_str[i])))
break;
if (i >= ARRAY_SIZE(ecrc_policy_str))
return;
ecrc_policy = i;
}
