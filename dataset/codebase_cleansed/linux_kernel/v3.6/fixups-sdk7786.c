char *__init pcibios_setup(char *str)
{
if (strcmp(str, "slot4en") == 0) {
slot4en = 1;
return NULL;
}
return str;
}
static int __init sdk7786_pci_init(void)
{
u16 data = fpga_read_reg(PCIECR);
slot4en ?: (!(data & PCIECR_PRST4) && (data & PCIECR_PRST3));
if (slot4en) {
pr_info("Activating PCIe slot#4 (disabling slot#3)\n");
data &= ~PCIECR_PCIEMUX1;
fpga_write_reg(data, PCIECR);
if ((data & PCIECR_PRST3) == 0) {
pr_warning("Unreachable card detected in slot#3\n");
return -EBUSY;
}
} else
pr_info("PCIe slot#4 disabled\n");
return 0;
}
