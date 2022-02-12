static struct acpi_generic_status *extlog_elog_entry_check(int cpu, int bank)
{
int idx;
u64 data;
struct acpi_generic_status *estatus;
WARN_ON(cpu < 0);
idx = ELOG_IDX(cpu, bank);
data = ELOG_ENTRY_DATA(idx);
if ((data & ELOG_ENTRY_VALID) == 0)
return NULL;
data &= EXT_ELOG_ENTRY_MASK;
estatus = (struct acpi_generic_status *)ELOG_ENTRY_ADDR(data);
if (estatus->block_status == 0)
return NULL;
return estatus;
}
static void __print_extlog_rcd(const char *pfx,
struct acpi_generic_status *estatus, int cpu)
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
struct acpi_generic_status *estatus, int cpu)
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
struct acpi_generic_status *estatus;
int rc;
estatus = extlog_elog_entry_check(cpu, bank);
if (estatus == NULL)
return NOTIFY_DONE;
memcpy(elog_buf, (void *)estatus, ELOG_ENTRY_LEN);
/* clear record status to enable BIOS to update it again */
estatus->block_status = 0;
rc = print_extlog_rcd(NULL, (struct acpi_generic_status *)elog_buf, cpu);
return NOTIFY_STOP;
}
static bool __init extlog_get_l1addr(void)
{
u8 uuid[16];
acpi_handle handle;
union acpi_object *obj;
acpi_str_to_uuid(extlog_dsm_uuid, uuid);
if (ACPI_FAILURE(acpi_get_handle(NULL, "\\_SB", &handle)))
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
/* Spec says L1 directory must be 4K aligned, bail out if it isn't */
if (l1_dirbase & ((1 << 12) - 1)) {
pr_warn(FW_BUG "L1 Directory is invalid at physical %llx\n",
l1_dirbase);
return false;
}
return true;
}
static struct notifier_block extlog_mce_dec = {
.notifier_call = extlog_print,
};
static int __init extlog_init(void)
{
struct extlog_l1_head *l1_head;
void __iomem *extlog_l1_hdr;
size_t l1_hdr_size;
struct resource *r;
u64 cap;
int rc;
if (get_edac_report_status() == EDAC_REPORTING_FORCE) {
pr_warn("Not loading eMCA, error reporting force-enabled through EDAC.\n");
return -EPERM;
}
rc = -ENODEV;
rdmsrl(MSR_IA32_MCG_CAP, cap);
if (!(cap & MCG_ELOG_P))
return rc;
if (!extlog_get_l1addr())
return rc;
rc = -EINVAL;
/* get L1 header to fetch necessary information */
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
/* remap L1 header again based on completed information */
r = request_mem_region(l1_dirbase, l1_size, "L1 Table");
if (!r) {
pr_warn(FW_BUG EMCA_BUG,
(unsigned long long)l1_dirbase,
(unsigned long long)l1_dirbase + l1_size);
goto err;
}
extlog_l1_addr = acpi_os_map_iomem(l1_dirbase, l1_size);
l1_entry_base = (u64 *)((u8 *)extlog_l1_addr + l1_hdr_size);
/* remap elog table */
r = request_mem_region(elog_base, elog_size, "Elog Table");
if (!r) {
pr_warn(FW_BUG EMCA_BUG,
(unsigned long long)elog_base,
(unsigned long long)elog_base + elog_size);
goto err_release_l1_dir;
}
elog_addr = acpi_os_map_iomem(elog_base, elog_size);
rc = -ENOMEM;
/* allocate buffer to save elog record */
elog_buf = kmalloc(ELOG_ENTRY_LEN, GFP_KERNEL);
if (elog_buf == NULL)
goto err_release_elog;
/*
* eMCA event report method has higher priority than EDAC method,
* unless EDAC event report method is mandatory.
*/
old_edac_report_status = get_edac_report_status();
set_edac_report_status(EDAC_REPORTING_DISABLED);
mce_register_decode_chain(&extlog_mce_dec);
/* enable OS to be involved to take over management from BIOS */
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
set_edac_report_status(old_edac_report_status);
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
MODULE_LICENSE("GPL"
