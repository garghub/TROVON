static struct sdhci_pci_data *
mrfld_sdhci_pci_get_data(struct pci_dev *pdev, int slotno)
{
unsigned int func = PCI_FUNC(pdev->devfn);
if (func == INTEL_MRFLD_SD)
return &mrfld_sdhci_pci_data;
return NULL;
}
static int __init mrfld_sd_init(void)
{
if (intel_mid_identify_cpu() != INTEL_MID_CPU_CHIP_TANGIER)
return -ENODEV;
sdhci_pci_get_data = mrfld_sdhci_pci_get_data;
return 0;
}
