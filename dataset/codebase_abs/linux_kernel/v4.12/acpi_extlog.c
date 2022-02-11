static struct V_1 * F_1 ( int V_2 , int V_3 )
{
int V_4 ;
T_1 V_5 ;
struct V_1 * V_6 ;
F_2 ( V_2 < 0 ) ;
V_4 = F_3 ( V_2 , V_3 ) ;
V_5 = F_4 ( V_4 ) ;
if ( ( V_5 & V_7 ) == 0 )
return NULL ;
V_5 &= V_8 ;
V_6 = (struct V_1 * ) F_5 ( V_5 ) ;
if ( V_6 -> V_9 == 0 )
return NULL ;
return V_6 ;
}
static void F_6 ( const char * V_10 ,
struct V_1 * V_6 , int V_2 )
{
static T_2 V_11 ;
unsigned int V_12 ;
char V_13 [ 64 ] ;
if ( ! V_10 ) {
if ( V_6 -> V_14 <= V_15 )
V_10 = V_16 ;
else
V_10 = V_17 ;
}
V_12 = F_7 ( & V_11 ) ;
snprintf ( V_13 , sizeof( V_13 ) , L_1 , V_10 , V_12 ) ;
F_8 ( L_2Hardware error detected on CPU%d\nL_3;
uuid_le *sec_type;
static u32 err_seq;
estatus = extlog_elog_entry_check(cpu, bank);
if (estatus == NULL)
return NOTIFY_DONE;
memcpy(elog_buf, (void *)estatus, ELOG_ENTRY_LEN);
estatus->block_status = 0;
tmp = (struct acpi_hest_generic_status *)elog_buf;
if (!ras_userspace_consumers()) {
print_extlog_rcd(NULL, tmp, cpu);
goto out;
}
err_seq++;
gdata = (struct acpi_hest_generic_data *)(tmp + 1);
if (gdata->validation_bits & CPER_SEC_VALID_FRU_ID)
fru_id = (uuid_le *)gdata->fru_id;
if (gdata->validation_bits & CPER_SEC_VALID_FRU_TEXT)
fru_text = gdata->fru_text;
sec_type = (uuid_le *)gdata->section_type;
if (!uuid_le_cmp(*sec_type, CPER_SEC_PLATFORM_MEM)) {
struct cper_sec_mem_err *mem = (void *)(gdata + 1);
if (gdata->error_data_length >= sizeof(*mem))
trace_extlog_mem_event(mem, err_seq, fru_id, fru_text,
(u8)gdata->error_severity);
}
out:
return NOTIFY_STOP;
}
static bool __init extlog_get_l1addr(void)
{
u8 uuid[16];
acpi_handle handle;
union acpi_object *obj;
acpi_str_to_uuid(extlog_dsm_uuid, uuid);
if (ACPI_FAILURE(acpi_get_handle(NULL, L_4, &handle)))
return false;
if (!acpi_check_dsm(handle, uuid, EXTLOG_DSM_REV, 1 << EXTLOG_FN_ADDR))
return false;
obj = acpi_evaluate_dsm_typed(handle, uuid, EXTLOG_DSM_REV,
EXTLOG_FN_ADDR, NULL, ACPI_TYPE_INTEGER);
if (!obj) {
return false;
} else {
l1_dirbase = obj->integer.value;
ACPI_FREE(obj);
}
if (l1_dirbase & ((1 << 12) - 1)) {
pr_warn(FW_BUG L_5,
l1_dirbase);
return false;
}
return true;
}
static struct notifier_block extlog_mce_dec = {
.notifier_call = extlog_print,
.priority = MCE_PRIO_EXTLOG,
};
static int __init extlog_init(void)
{
struct extlog_l1_head *l1_head;
void __iomem *extlog_l1_hdr;
size_t l1_hdr_size;
struct resource *r;
u64 cap;
int rc;
rdmsrl(MSR_IA32_MCG_CAP, cap);
if (!(cap & MCG_ELOG_P) || !extlog_get_l1addr())
return -ENODEV;
if (edac_get_report_status() == EDAC_REPORTING_FORCE) {
pr_warn(L_6);
return -EPERM;
}
rc = -EINVAL;
l1_hdr_size = sizeof(struct extlog_l1_head);
r = request_mem_region(l1_dirbase, l1_hdr_size, L_7);
if (!r) {
pr_warn(FW_BUG EMCA_BUG,
(unsigned long long)l1_dirbase,
(unsigned long long)l1_dirbase + l1_hdr_size);
goto err;
}
extlog_l1_hdr = acpi_os_map_iomem(l1_dirbase, l1_hdr_size);
l1_head = (struct extlog_l1_head *)extlog_l1_hdr;
l1_size = l1_head->total_len;
l1_percpu_entry = l1_head->entries;
elog_base = l1_head->elog_base;
elog_size = l1_head->elog_len;
acpi_os_unmap_iomem(extlog_l1_hdr, l1_hdr_size);
release_mem_region(l1_dirbase, l1_hdr_size);
r = request_mem_region(l1_dirbase, l1_size, L_8);
if (!r) {
pr_warn(FW_BUG EMCA_BUG,
(unsigned long long)l1_dirbase,
(unsigned long long)l1_dirbase + l1_size);
goto err;
}
extlog_l1_addr = acpi_os_map_iomem(l1_dirbase, l1_size);
l1_entry_base = (u64 *)((u8 *)extlog_l1_addr + l1_hdr_size);
r = request_mem_region(elog_base, elog_size, L_9);
if (!r) {
pr_warn(FW_BUG EMCA_BUG,
(unsigned long long)elog_base,
(unsigned long long)elog_base + elog_size);
goto err_release_l1_dir;
}
elog_addr = acpi_os_map_iomem(elog_base, elog_size);
rc = -ENOMEM;
elog_buf = kmalloc(ELOG_ENTRY_LEN, GFP_KERNEL);
if (elog_buf == NULL)
goto err_release_elog;
old_edac_report_status = edac_get_report_status();
edac_set_report_status(EDAC_REPORTING_DISABLED);
mce_register_decode_chain(&extlog_mce_dec);
((struct extlog_l1_head *)extlog_l1_addr)->flags |= FLAG_OS_OPTIN;
return 0;
err_release_elog:
if (elog_addr)
acpi_os_unmap_iomem(elog_addr, elog_size);
release_mem_region(elog_base, elog_size);
err_release_l1_dir:
if (extlog_l1_addr)
acpi_os_unmap_iomem(extlog_l1_addr, l1_size);
release_mem_region(l1_dirbase, l1_size);
err:
pr_warn(FW_BUG L_10);
return rc;
}
static void __exit extlog_exit(void)
{
edac_set_report_status(old_edac_report_status);
mce_unregister_decode_chain(&extlog_mce_dec);
((struct extlog_l1_head *)extlog_l1_addr)->flags &= ~FLAG_OS_OPTIN;
if (extlog_l1_addr)
acpi_os_unmap_iomem(extlog_l1_addr, l1_size);
if (elog_addr)
acpi_os_unmap_iomem(elog_addr, elog_size);
release_mem_region(elog_base, elog_size);
release_mem_region(l1_dirbase, l1_size);
kfree(elog_buf);
}
module_init(extlog_init);
module_exit(extlog_exit);
MODULE_AUTHOR(L_11);
MODULE_DESCRIPTION(L_12);
MODULE_LICENSE(L_13);
