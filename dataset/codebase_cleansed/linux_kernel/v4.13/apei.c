int arch_apei_enable_cmcff(struct acpi_hest_header *hest_hdr, void *data)
{
#ifdef CONFIG_X86_MCE
int i;
struct acpi_hest_ia_corrected *cmc;
struct acpi_hest_ia_error_bank *mc_bank;
cmc = (struct acpi_hest_ia_corrected *)hest_hdr;
if (!cmc->enabled)
return 0;
if (!(cmc->flags & ACPI_HEST_FIRMWARE_FIRST) ||
!cmc->num_hardware_banks)
return 1;
pr_info("HEST: Enabling Firmware First mode for corrected errors.\n");
mc_bank = (struct acpi_hest_ia_error_bank *)(cmc + 1);
for (i = 0; i < cmc->num_hardware_banks; i++, mc_bank++)
mce_disable_bank(mc_bank->bank_number);
#endif
return 1;
}
void arch_apei_report_mem_error(int sev, struct cper_sec_mem_err *mem_err)
{
#ifdef CONFIG_X86_MCE
apei_mce_report_mem_error(sev, mem_err);
#endif
}
void arch_apei_flush_tlb_one(unsigned long addr)
{
__flush_tlb_one(addr);
}
