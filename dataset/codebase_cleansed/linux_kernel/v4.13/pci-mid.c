static bool mid_pci_power_manageable(struct pci_dev *dev)
{
return true;
}
static int mid_pci_set_power_state(struct pci_dev *pdev, pci_power_t state)
{
return intel_mid_pci_set_power_state(pdev, state);
}
static pci_power_t mid_pci_get_power_state(struct pci_dev *pdev)
{
return intel_mid_pci_get_power_state(pdev);
}
static pci_power_t mid_pci_choose_state(struct pci_dev *pdev)
{
return PCI_D3hot;
}
static int mid_pci_wakeup(struct pci_dev *dev, bool enable)
{
return 0;
}
static bool mid_pci_need_resume(struct pci_dev *dev)
{
return false;
}
static int __init mid_pci_init(void)
{
const struct x86_cpu_id *id;
id = x86_match_cpu(lpss_cpu_ids);
if (id)
pci_set_platform_pm(&mid_pci_platform_pm);
return 0;
}
