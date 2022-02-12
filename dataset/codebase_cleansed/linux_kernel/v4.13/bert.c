static void __init bert_print_all(struct acpi_bert_region *region,
unsigned int region_len)
{
struct acpi_hest_generic_status *estatus =
(struct acpi_hest_generic_status *)region;
int remain = region_len;
u32 estatus_len;
if (!estatus->block_status)
return;
while (remain > sizeof(struct acpi_bert_region)) {
if (cper_estatus_check(estatus)) {
pr_err(FW_BUG "Invalid error record.\n");
return;
}
estatus_len = cper_estatus_len(estatus);
if (remain < estatus_len) {
pr_err(FW_BUG "Truncated status block (length: %u).\n",
estatus_len);
return;
}
pr_info_once("Error records from previous boot:\n");
cper_estatus_print(KERN_INFO HW_ERR, estatus);
estatus->block_status = 0;
estatus = (void *)estatus + estatus_len;
if (!estatus->block_status)
return;
remain -= estatus_len;
}
}
static int __init setup_bert_disable(char *str)
{
bert_disable = 1;
return 0;
}
static int __init bert_check_table(struct acpi_table_bert *bert_tab)
{
if (bert_tab->header.length < sizeof(struct acpi_table_bert) ||
bert_tab->region_length < sizeof(struct acpi_bert_region))
return -EINVAL;
return 0;
}
static int __init bert_init(void)
{
struct apei_resources bert_resources;
struct acpi_bert_region *boot_error_region;
struct acpi_table_bert *bert_tab;
unsigned int region_len;
acpi_status status;
int rc = 0;
if (acpi_disabled)
return 0;
if (bert_disable) {
pr_info("Boot Error Record Table support is disabled.\n");
return 0;
}
status = acpi_get_table(ACPI_SIG_BERT, 0, (struct acpi_table_header **)&bert_tab);
if (status == AE_NOT_FOUND)
return 0;
if (ACPI_FAILURE(status)) {
pr_err("get table failed, %s.\n", acpi_format_exception(status));
return -EINVAL;
}
rc = bert_check_table(bert_tab);
if (rc) {
pr_err(FW_BUG "table invalid.\n");
return rc;
}
region_len = bert_tab->region_length;
apei_resources_init(&bert_resources);
rc = apei_resources_add(&bert_resources, bert_tab->address,
region_len, true);
if (rc)
return rc;
rc = apei_resources_request(&bert_resources, "APEI BERT");
if (rc)
goto out_fini;
boot_error_region = ioremap_cache(bert_tab->address, region_len);
if (boot_error_region) {
bert_print_all(boot_error_region, region_len);
iounmap(boot_error_region);
} else {
rc = -ENOMEM;
}
apei_resources_release(&bert_resources);
out_fini:
apei_resources_fini(&bert_resources);
return rc;
}
