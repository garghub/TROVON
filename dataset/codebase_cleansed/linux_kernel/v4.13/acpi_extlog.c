static struct acpi_hest_generic_status *extlog_elog_entry_check(int cpu, int bank)
{
int idx;
u64 data;
struct acpi_hest_generic_status *estatus;
WARN_ON(cpu < 0);
idx = ELOG_IDX(cpu, bank);
data = ELOG_ENTRY_DATA(idx);
if ((data & ELOG_ENTRY_VALID) == 0)
return NULL;
data &= EXT_ELOG_ENTRY_MASK;
estatus = (struct acpi_hest_generic_status *)ELOG_ENTRY_ADDR(data);
if (estatus->block_status == 0)
return NULL;
return estatus;
}
static void __print_extlog_rcd(const char *pfx,
struct acpi_hest_generic_status *estatus, int cpu)
{
static atomic_t seqno;
unsigned int curr_seqno;
char pfx_seq[64];
if (!pfx) {
if (estatus->error_severity <= CPER_SEV_CORRECTED)
pfx = KERN_INFO;
else
pfx = KERN_ERR;
}
curr_seqno = atomic_inc_return(&seqno);
snprintf(pfx_seq, sizeof(pfx_seq), "%s{%u}", pfx, curr_seqno);
printk("%s""Hardware error detected on CPU%d\n", pfx_seq, cpu);
cper_estatus_print(pfx_seq, estatus);
}
static int print_extlog_rcd(const char *pfx,
struct acpi_hest_generic_status *estatus, int cpu)
{
/* Not more than 2 messages every 5 seconds */
static DEFINE_RATELIMIT_STATE(ratelimit_corrected, 5*HZ, 2);
static DEFINE_RATELIMIT_STATE(ratelimit_uncorrected, 5*HZ, 2);
struct ratelimit_state *ratelimit;
if (estatus->error_severity == CPER_SEV_CORRECTED ||
(estatus->error_severity == CPER_SEV_INFORMATIONAL))
ratelimit = &ratelimit_corrected;
else
ratelimit = &ratelimit_uncorrected;
if (__ratelimit(ratelimit)) {
__print_extlog_rcd(pfx, estatus, cpu);
return 0;
}
return 1;
}
static int extlog_print(struct notifier_block *nb, unsigned long val,
void *data)
{
struct mce *mce = (struct mce *)data;
int bank = mce->bank;
int cpu = mce->extcpu;
struct acpi_hest_generic_status *estatus, *tmp;
struct acpi_hest_generic_data *gdata;
const guid_t *fru_id = &guid_null;
char *fru_text = "";
guid_t *sec_type;
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
fru_id = (guid_t *)gdata->fru_id;
if (gdata->validation_bits & CPER_SEC_VALID_FRU_TEXT)
fru_text = gdata->fru_text;
sec_type = (guid_t *)gdata->section_type;
if (guid_equal(sec_type, &CPER_SEC_PLATFORM_MEM)) {
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
guid_t guid;
acpi_handle handle;
union acpi_object *obj;
if (guid_parse(extlog_dsm_uuid, &guid))
return false;
if (ACPI_FAILURE(acpi_get_handle(NULL, "\\_SB", &handle)))
return false;
if (!acpi_check_dsm(handle, &guid, EXTLOG_DSM_REV, 1 << EXTLOG_FN_ADDR))
return false;
obj = acpi_evaluate_dsm_typed(handle, &guid, EXTLOG_DSM_REV,
EXTLOG_FN_ADDR, NULL, ACPI_TYPE_INTEGER);
if (!obj) {
return false;
} else {
l1_dirbase = obj->integer.value;
ACPI_FREE(obj);
}
if (l1_dirbase & ((1 << 12) - 1)) {
pr_warn(FW_BUG "L1 Directory is invalid at physical %llx\n",
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
pr_warn("Not loading eMCA, error reporting force-enabled through EDAC.\n");
return -EPERM;
}
rc = -EINVAL;
l1_hdr_size = sizeof(struct extlog_l1_head);
r = request_mem_region(l1_dirbase, l1_hdr_size, "L1 DIR HDR");
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
r = request_mem_region(l1_dirbase, l1_size, "L1 Table");
if (!r) {
pr_warn(FW_BUG EMCA_BUG,
(unsigned long long)l1_dirbase,
(unsigned long long)l1_dirbase + l1_size);
goto err;
}
extlog_l1_addr = acpi_os_map_iomem(l1_dirbase, l1_size);
l1_entry_base = (u64 *)((u8 *)extlog_l1_addr + l1_hdr_size);
r = request_mem_region(elog_base, elog_size, "Elog Table");
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
pr_warn(FW_BUG "Extended error log disabled because of problems parsing f/w tables\n");
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
MODULE_AUTHOR("Chen, Gong <gong.chen@intel.com>");
MODULE_DESCRIPTION("Extended MCA Error Log Driver");
MODULE_LICENSE("GPL");
