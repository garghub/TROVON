static inline void writeq(__u64 val, volatile void __iomem *addr)
{
writel(val, addr);
writel(val >> 32, addr+4);
}
static void einj_exec_ctx_init(struct apei_exec_context *ctx)
{
apei_exec_ctx_init(ctx, einj_ins_type, ARRAY_SIZE(einj_ins_type),
EINJ_TAB_ENTRY(einj_tab), einj_tab->entries);
}
static int __einj_get_available_error_type(u32 *type)
{
struct apei_exec_context ctx;
int rc;
einj_exec_ctx_init(&ctx);
rc = apei_exec_run(&ctx, ACPI_EINJ_GET_ERROR_TYPE);
if (rc)
return rc;
*type = apei_exec_ctx_get_output(&ctx);
return 0;
}
static int einj_get_available_error_type(u32 *type)
{
int rc;
mutex_lock(&einj_mutex);
rc = __einj_get_available_error_type(type);
mutex_unlock(&einj_mutex);
return rc;
}
static int einj_timedout(u64 *t)
{
if ((s64)*t < SPIN_UNIT) {
pr_warning(FW_WARN EINJ_PFX
"Firmware does not respond in time\n");
return 1;
}
*t -= SPIN_UNIT;
ndelay(SPIN_UNIT);
touch_nmi_watchdog();
return 0;
}
static u64 einj_get_parameter_address(void)
{
int i;
u64 paddr = 0;
struct acpi_whea_header *entry;
entry = EINJ_TAB_ENTRY(einj_tab);
for (i = 0; i < einj_tab->entries; i++) {
if (entry->action == ACPI_EINJ_SET_ERROR_TYPE &&
entry->instruction == ACPI_EINJ_WRITE_REGISTER &&
entry->register_region.space_id ==
ACPI_ADR_SPACE_SYSTEM_MEMORY)
memcpy(&paddr, &entry->register_region.address,
sizeof(paddr));
entry++;
}
return paddr;
}
static int einj_check_trigger_header(struct acpi_einj_trigger *trigger_tab)
{
if (trigger_tab->header_size != sizeof(struct acpi_einj_trigger))
return -EINVAL;
if (trigger_tab->table_size > PAGE_SIZE ||
trigger_tab->table_size <= trigger_tab->header_size)
return -EINVAL;
if (trigger_tab->entry_count !=
(trigger_tab->table_size - trigger_tab->header_size) /
sizeof(struct acpi_einj_entry))
return -EINVAL;
return 0;
}
static int __einj_error_trigger(u64 trigger_paddr)
{
struct acpi_einj_trigger *trigger_tab = NULL;
struct apei_exec_context trigger_ctx;
struct apei_resources trigger_resources;
struct acpi_whea_header *trigger_entry;
struct resource *r;
u32 table_size;
int rc = -EIO;
r = request_mem_region(trigger_paddr, sizeof(*trigger_tab),
"APEI EINJ Trigger Table");
if (!r) {
pr_err(EINJ_PFX
"Can not request iomem region <%016llx-%016llx> for Trigger table.\n",
(unsigned long long)trigger_paddr,
(unsigned long long)trigger_paddr+sizeof(*trigger_tab));
goto out;
}
trigger_tab = ioremap_cache(trigger_paddr, sizeof(*trigger_tab));
if (!trigger_tab) {
pr_err(EINJ_PFX "Failed to map trigger table!\n");
goto out_rel_header;
}
rc = einj_check_trigger_header(trigger_tab);
if (rc) {
pr_warning(FW_BUG EINJ_PFX
"The trigger error action table is invalid\n");
goto out_rel_header;
}
rc = -EIO;
table_size = trigger_tab->table_size;
r = request_mem_region(trigger_paddr + sizeof(*trigger_tab),
table_size - sizeof(*trigger_tab),
"APEI EINJ Trigger Table");
if (!r) {
pr_err(EINJ_PFX
"Can not request iomem region <%016llx-%016llx> for Trigger Table Entry.\n",
(unsigned long long)trigger_paddr+sizeof(*trigger_tab),
(unsigned long long)trigger_paddr + table_size);
goto out_rel_header;
}
iounmap(trigger_tab);
trigger_tab = ioremap_cache(trigger_paddr, table_size);
if (!trigger_tab) {
pr_err(EINJ_PFX "Failed to map trigger table!\n");
goto out_rel_entry;
}
trigger_entry = (struct acpi_whea_header *)
((char *)trigger_tab + sizeof(struct acpi_einj_trigger));
apei_resources_init(&trigger_resources);
apei_exec_ctx_init(&trigger_ctx, einj_ins_type,
ARRAY_SIZE(einj_ins_type),
trigger_entry, trigger_tab->entry_count);
rc = apei_exec_collect_resources(&trigger_ctx, &trigger_resources);
if (rc)
goto out_fini;
rc = apei_resources_sub(&trigger_resources, &einj_resources);
if (rc)
goto out_fini;
rc = apei_resources_request(&trigger_resources, "APEI EINJ Trigger");
if (rc)
goto out_fini;
rc = apei_exec_pre_map_gars(&trigger_ctx);
if (rc)
goto out_release;
rc = apei_exec_run(&trigger_ctx, ACPI_EINJ_TRIGGER_ERROR);
apei_exec_post_unmap_gars(&trigger_ctx);
out_release:
apei_resources_release(&trigger_resources);
out_fini:
apei_resources_fini(&trigger_resources);
out_rel_entry:
release_mem_region(trigger_paddr + sizeof(*trigger_tab),
table_size - sizeof(*trigger_tab));
out_rel_header:
release_mem_region(trigger_paddr, sizeof(*trigger_tab));
out:
if (trigger_tab)
iounmap(trigger_tab);
return rc;
}
static int __einj_error_inject(u32 type, u64 param1, u64 param2)
{
struct apei_exec_context ctx;
u64 val, trigger_paddr, timeout = FIRMWARE_TIMEOUT;
int rc;
einj_exec_ctx_init(&ctx);
rc = apei_exec_run_optional(&ctx, ACPI_EINJ_BEGIN_OPERATION);
if (rc)
return rc;
apei_exec_ctx_set_input(&ctx, type);
rc = apei_exec_run(&ctx, ACPI_EINJ_SET_ERROR_TYPE);
if (rc)
return rc;
if (einj_param) {
writeq(param1, &einj_param->param1);
writeq(param2, &einj_param->param2);
}
rc = apei_exec_run(&ctx, ACPI_EINJ_EXECUTE_OPERATION);
if (rc)
return rc;
for (;;) {
rc = apei_exec_run(&ctx, ACPI_EINJ_CHECK_BUSY_STATUS);
if (rc)
return rc;
val = apei_exec_ctx_get_output(&ctx);
if (!(val & EINJ_OP_BUSY))
break;
if (einj_timedout(&timeout))
return -EIO;
}
rc = apei_exec_run(&ctx, ACPI_EINJ_GET_COMMAND_STATUS);
if (rc)
return rc;
val = apei_exec_ctx_get_output(&ctx);
if (val != EINJ_STATUS_SUCCESS)
return -EBUSY;
rc = apei_exec_run(&ctx, ACPI_EINJ_GET_TRIGGER_TABLE);
if (rc)
return rc;
trigger_paddr = apei_exec_ctx_get_output(&ctx);
rc = __einj_error_trigger(trigger_paddr);
if (rc)
return rc;
rc = apei_exec_run_optional(&ctx, ACPI_EINJ_END_OPERATION);
return rc;
}
static int einj_error_inject(u32 type, u64 param1, u64 param2)
{
int rc;
mutex_lock(&einj_mutex);
rc = __einj_error_inject(type, param1, param2);
mutex_unlock(&einj_mutex);
return rc;
}
static int available_error_type_show(struct seq_file *m, void *v)
{
int rc;
u32 available_error_type = 0;
rc = einj_get_available_error_type(&available_error_type);
if (rc)
return rc;
if (available_error_type & 0x0001)
seq_printf(m, "0x00000001\tProcessor Correctable\n");
if (available_error_type & 0x0002)
seq_printf(m, "0x00000002\tProcessor Uncorrectable non-fatal\n");
if (available_error_type & 0x0004)
seq_printf(m, "0x00000004\tProcessor Uncorrectable fatal\n");
if (available_error_type & 0x0008)
seq_printf(m, "0x00000008\tMemory Correctable\n");
if (available_error_type & 0x0010)
seq_printf(m, "0x00000010\tMemory Uncorrectable non-fatal\n");
if (available_error_type & 0x0020)
seq_printf(m, "0x00000020\tMemory Uncorrectable fatal\n");
if (available_error_type & 0x0040)
seq_printf(m, "0x00000040\tPCI Express Correctable\n");
if (available_error_type & 0x0080)
seq_printf(m, "0x00000080\tPCI Express Uncorrectable non-fatal\n");
if (available_error_type & 0x0100)
seq_printf(m, "0x00000100\tPCI Express Uncorrectable fatal\n");
if (available_error_type & 0x0200)
seq_printf(m, "0x00000200\tPlatform Correctable\n");
if (available_error_type & 0x0400)
seq_printf(m, "0x00000400\tPlatform Uncorrectable non-fatal\n");
if (available_error_type & 0x0800)
seq_printf(m, "0x00000800\tPlatform Uncorrectable fatal\n");
return 0;
}
static int available_error_type_open(struct inode *inode, struct file *file)
{
return single_open(file, available_error_type_show, NULL);
}
static int error_type_get(void *data, u64 *val)
{
*val = error_type;
return 0;
}
static int error_type_set(void *data, u64 val)
{
int rc;
u32 available_error_type = 0;
if (val & (val - 1))
return -EINVAL;
rc = einj_get_available_error_type(&available_error_type);
if (rc)
return rc;
if (!(val & available_error_type))
return -EINVAL;
error_type = val;
return 0;
}
static int error_inject_set(void *data, u64 val)
{
if (!error_type)
return -EINVAL;
return einj_error_inject(error_type, error_param1, error_param2);
}
static int einj_check_table(struct acpi_table_einj *einj_tab)
{
if ((einj_tab->header_length !=
(sizeof(struct acpi_table_einj) - sizeof(einj_tab->header)))
&& (einj_tab->header_length != sizeof(struct acpi_table_einj)))
return -EINVAL;
if (einj_tab->header.length < sizeof(struct acpi_table_einj))
return -EINVAL;
if (einj_tab->entries !=
(einj_tab->header.length - sizeof(struct acpi_table_einj)) /
sizeof(struct acpi_einj_entry))
return -EINVAL;
return 0;
}
static int __init einj_init(void)
{
int rc;
u64 param_paddr;
acpi_status status;
struct dentry *fentry;
struct apei_exec_context ctx;
if (acpi_disabled)
return -ENODEV;
status = acpi_get_table(ACPI_SIG_EINJ, 0,
(struct acpi_table_header **)&einj_tab);
if (status == AE_NOT_FOUND) {
pr_info(EINJ_PFX "Table is not found!\n");
return -ENODEV;
} else if (ACPI_FAILURE(status)) {
const char *msg = acpi_format_exception(status);
pr_err(EINJ_PFX "Failed to get table, %s\n", msg);
return -EINVAL;
}
rc = einj_check_table(einj_tab);
if (rc) {
pr_warning(FW_BUG EINJ_PFX "EINJ table is invalid\n");
return -EINVAL;
}
rc = -ENOMEM;
einj_debug_dir = debugfs_create_dir("einj", apei_get_debugfs_dir());
if (!einj_debug_dir)
goto err_cleanup;
fentry = debugfs_create_file("available_error_type", S_IRUSR,
einj_debug_dir, NULL,
&available_error_type_fops);
if (!fentry)
goto err_cleanup;
fentry = debugfs_create_file("error_type", S_IRUSR | S_IWUSR,
einj_debug_dir, NULL, &error_type_fops);
if (!fentry)
goto err_cleanup;
fentry = debugfs_create_file("error_inject", S_IWUSR,
einj_debug_dir, NULL, &error_inject_fops);
if (!fentry)
goto err_cleanup;
apei_resources_init(&einj_resources);
einj_exec_ctx_init(&ctx);
rc = apei_exec_collect_resources(&ctx, &einj_resources);
if (rc)
goto err_fini;
rc = apei_resources_request(&einj_resources, "APEI EINJ");
if (rc)
goto err_fini;
rc = apei_exec_pre_map_gars(&ctx);
if (rc)
goto err_release;
if (param_extension) {
param_paddr = einj_get_parameter_address();
if (param_paddr) {
einj_param = ioremap(param_paddr, sizeof(*einj_param));
rc = -ENOMEM;
if (!einj_param)
goto err_unmap;
fentry = debugfs_create_x64("param1", S_IRUSR | S_IWUSR,
einj_debug_dir, &error_param1);
if (!fentry)
goto err_unmap;
fentry = debugfs_create_x64("param2", S_IRUSR | S_IWUSR,
einj_debug_dir, &error_param2);
if (!fentry)
goto err_unmap;
} else
pr_warn(EINJ_PFX "Parameter extension is not supported.\n");
}
pr_info(EINJ_PFX "Error INJection is initialized.\n");
return 0;
err_unmap:
if (einj_param)
iounmap(einj_param);
apei_exec_post_unmap_gars(&ctx);
err_release:
apei_resources_release(&einj_resources);
err_fini:
apei_resources_fini(&einj_resources);
err_cleanup:
debugfs_remove_recursive(einj_debug_dir);
return rc;
}
static void __exit einj_exit(void)
{
struct apei_exec_context ctx;
if (einj_param)
iounmap(einj_param);
einj_exec_ctx_init(&ctx);
apei_exec_post_unmap_gars(&ctx);
apei_resources_release(&einj_resources);
apei_resources_fini(&einj_resources);
debugfs_remove_recursive(einj_debug_dir);
}
