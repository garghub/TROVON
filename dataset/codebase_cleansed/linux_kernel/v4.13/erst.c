static inline int erst_errno(int command_status)
{
switch (command_status) {
case ERST_STATUS_SUCCESS:
return 0;
case ERST_STATUS_HARDWARE_NOT_AVAILABLE:
return -ENODEV;
case ERST_STATUS_NOT_ENOUGH_SPACE:
return -ENOSPC;
case ERST_STATUS_RECORD_STORE_EMPTY:
case ERST_STATUS_RECORD_NOT_FOUND:
return -ENOENT;
default:
return -EINVAL;
}
}
static int erst_timedout(u64 *t, u64 spin_unit)
{
if ((s64)*t < spin_unit) {
pr_warn(FW_WARN "Firmware does not respond in time.\n");
return 1;
}
*t -= spin_unit;
ndelay(spin_unit);
touch_nmi_watchdog();
return 0;
}
static int erst_exec_load_var1(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
return __apei_exec_read_register(entry, &ctx->var1);
}
static int erst_exec_load_var2(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
return __apei_exec_read_register(entry, &ctx->var2);
}
static int erst_exec_store_var1(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
return __apei_exec_write_register(entry, ctx->var1);
}
static int erst_exec_add(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
ctx->var1 += ctx->var2;
return 0;
}
static int erst_exec_subtract(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
ctx->var1 -= ctx->var2;
return 0;
}
static int erst_exec_add_value(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
int rc;
u64 val;
rc = __apei_exec_read_register(entry, &val);
if (rc)
return rc;
val += ctx->value;
rc = __apei_exec_write_register(entry, val);
return rc;
}
static int erst_exec_subtract_value(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
int rc;
u64 val;
rc = __apei_exec_read_register(entry, &val);
if (rc)
return rc;
val -= ctx->value;
rc = __apei_exec_write_register(entry, val);
return rc;
}
static int erst_exec_stall(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
u64 stall_time;
if (ctx->value > FIRMWARE_MAX_STALL) {
if (!in_nmi())
pr_warn(FW_WARN
"Too long stall time for stall instruction: 0x%llx.\n",
ctx->value);
stall_time = FIRMWARE_MAX_STALL;
} else
stall_time = ctx->value;
udelay(stall_time);
return 0;
}
static int erst_exec_stall_while_true(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
int rc;
u64 val;
u64 timeout = FIRMWARE_TIMEOUT;
u64 stall_time;
if (ctx->var1 > FIRMWARE_MAX_STALL) {
if (!in_nmi())
pr_warn(FW_WARN
"Too long stall time for stall while true instruction: 0x%llx.\n",
ctx->var1);
stall_time = FIRMWARE_MAX_STALL;
} else
stall_time = ctx->var1;
for (;;) {
rc = __apei_exec_read_register(entry, &val);
if (rc)
return rc;
if (val != ctx->value)
break;
if (erst_timedout(&timeout, stall_time * NSEC_PER_USEC))
return -EIO;
}
return 0;
}
static int erst_exec_skip_next_instruction_if_true(
struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
int rc;
u64 val;
rc = __apei_exec_read_register(entry, &val);
if (rc)
return rc;
if (val == ctx->value) {
ctx->ip += 2;
return APEI_EXEC_SET_IP;
}
return 0;
}
static int erst_exec_goto(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
ctx->ip = ctx->value;
return APEI_EXEC_SET_IP;
}
static int erst_exec_set_src_address_base(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
return __apei_exec_read_register(entry, &ctx->src_base);
}
static int erst_exec_set_dst_address_base(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
return __apei_exec_read_register(entry, &ctx->dst_base);
}
static int erst_exec_move_data(struct apei_exec_context *ctx,
struct acpi_whea_header *entry)
{
int rc;
u64 offset;
void *src, *dst;
if (in_interrupt()) {
pr_warn("MOVE_DATA can not be used in interrupt context.\n");
return -EBUSY;
}
rc = __apei_exec_read_register(entry, &offset);
if (rc)
return rc;
src = ioremap(ctx->src_base + offset, ctx->var2);
if (!src)
return -ENOMEM;
dst = ioremap(ctx->dst_base + offset, ctx->var2);
if (!dst) {
iounmap(src);
return -ENOMEM;
}
memmove(dst, src, ctx->var2);
iounmap(src);
iounmap(dst);
return 0;
}
static inline void erst_exec_ctx_init(struct apei_exec_context *ctx)
{
apei_exec_ctx_init(ctx, erst_ins_type, ARRAY_SIZE(erst_ins_type),
ERST_TAB_ENTRY(erst_tab), erst_tab->entries);
}
static int erst_get_erange(struct erst_erange *range)
{
struct apei_exec_context ctx;
int rc;
erst_exec_ctx_init(&ctx);
rc = apei_exec_run(&ctx, ACPI_ERST_GET_ERROR_RANGE);
if (rc)
return rc;
range->base = apei_exec_ctx_get_output(&ctx);
rc = apei_exec_run(&ctx, ACPI_ERST_GET_ERROR_LENGTH);
if (rc)
return rc;
range->size = apei_exec_ctx_get_output(&ctx);
rc = apei_exec_run(&ctx, ACPI_ERST_GET_ERROR_ATTRIBUTES);
if (rc)
return rc;
range->attr = apei_exec_ctx_get_output(&ctx);
return 0;
}
static ssize_t __erst_get_record_count(void)
{
struct apei_exec_context ctx;
int rc;
erst_exec_ctx_init(&ctx);
rc = apei_exec_run(&ctx, ACPI_ERST_GET_RECORD_COUNT);
if (rc)
return rc;
return apei_exec_ctx_get_output(&ctx);
}
ssize_t erst_get_record_count(void)
{
ssize_t count;
unsigned long flags;
if (erst_disable)
return -ENODEV;
raw_spin_lock_irqsave(&erst_lock, flags);
count = __erst_get_record_count();
raw_spin_unlock_irqrestore(&erst_lock, flags);
return count;
}
static int __erst_get_next_record_id(u64 *record_id)
{
struct apei_exec_context ctx;
int rc;
erst_exec_ctx_init(&ctx);
rc = apei_exec_run(&ctx, ACPI_ERST_GET_RECORD_ID);
if (rc)
return rc;
*record_id = apei_exec_ctx_get_output(&ctx);
return 0;
}
int erst_get_record_id_begin(int *pos)
{
int rc;
if (erst_disable)
return -ENODEV;
rc = mutex_lock_interruptible(&erst_record_id_cache.lock);
if (rc)
return rc;
erst_record_id_cache.refcount++;
mutex_unlock(&erst_record_id_cache.lock);
*pos = 0;
return 0;
}
static int __erst_record_id_cache_add_one(void)
{
u64 id, prev_id, first_id;
int i, rc;
u64 *entries;
unsigned long flags;
id = prev_id = first_id = APEI_ERST_INVALID_RECORD_ID;
retry:
raw_spin_lock_irqsave(&erst_lock, flags);
rc = __erst_get_next_record_id(&id);
raw_spin_unlock_irqrestore(&erst_lock, flags);
if (rc == -ENOENT)
return 0;
if (rc)
return rc;
if (id == APEI_ERST_INVALID_RECORD_ID)
return 0;
if (id == prev_id || id == first_id)
return 0;
if (first_id == APEI_ERST_INVALID_RECORD_ID)
first_id = id;
prev_id = id;
entries = erst_record_id_cache.entries;
for (i = 0; i < erst_record_id_cache.len; i++) {
if (entries[i] == id)
break;
}
if (i < erst_record_id_cache.len)
goto retry;
if (erst_record_id_cache.len >= erst_record_id_cache.size) {
int new_size;
u64 *new_entries;
new_size = erst_record_id_cache.size * 2;
new_size = clamp_val(new_size, ERST_RECORD_ID_CACHE_SIZE_MIN,
ERST_RECORD_ID_CACHE_SIZE_MAX);
if (new_size <= erst_record_id_cache.size) {
if (printk_ratelimit())
pr_warn(FW_WARN "too many record IDs!\n");
return 0;
}
new_entries = kvmalloc(new_size * sizeof(entries[0]), GFP_KERNEL);
if (!new_entries)
return -ENOMEM;
memcpy(new_entries, entries,
erst_record_id_cache.len * sizeof(entries[0]));
kvfree(entries);
erst_record_id_cache.entries = entries = new_entries;
erst_record_id_cache.size = new_size;
}
entries[i] = id;
erst_record_id_cache.len++;
return 1;
}
int erst_get_record_id_next(int *pos, u64 *record_id)
{
int rc = 0;
u64 *entries;
if (erst_disable)
return -ENODEV;
BUG_ON(!erst_record_id_cache.refcount);
BUG_ON(*pos < 0 || *pos > erst_record_id_cache.len);
mutex_lock(&erst_record_id_cache.lock);
entries = erst_record_id_cache.entries;
for (; *pos < erst_record_id_cache.len; (*pos)++)
if (entries[*pos] != APEI_ERST_INVALID_RECORD_ID)
break;
if (*pos < erst_record_id_cache.len) {
*record_id = entries[*pos];
(*pos)++;
goto out_unlock;
}
rc = __erst_record_id_cache_add_one();
if (rc < 0)
goto out_unlock;
if (rc == 1) {
*record_id = erst_record_id_cache.entries[*pos];
(*pos)++;
rc = 0;
} else {
*pos = -1;
*record_id = APEI_ERST_INVALID_RECORD_ID;
}
out_unlock:
mutex_unlock(&erst_record_id_cache.lock);
return rc;
}
static void __erst_record_id_cache_compact(void)
{
int i, wpos = 0;
u64 *entries;
if (erst_record_id_cache.refcount)
return;
entries = erst_record_id_cache.entries;
for (i = 0; i < erst_record_id_cache.len; i++) {
if (entries[i] == APEI_ERST_INVALID_RECORD_ID)
continue;
if (wpos != i)
entries[wpos] = entries[i];
wpos++;
}
erst_record_id_cache.len = wpos;
}
void erst_get_record_id_end(void)
{
BUG_ON(erst_disable);
mutex_lock(&erst_record_id_cache.lock);
erst_record_id_cache.refcount--;
BUG_ON(erst_record_id_cache.refcount < 0);
__erst_record_id_cache_compact();
mutex_unlock(&erst_record_id_cache.lock);
}
static int __erst_write_to_storage(u64 offset)
{
struct apei_exec_context ctx;
u64 timeout = FIRMWARE_TIMEOUT;
u64 val;
int rc;
erst_exec_ctx_init(&ctx);
rc = apei_exec_run_optional(&ctx, ACPI_ERST_BEGIN_WRITE);
if (rc)
return rc;
apei_exec_ctx_set_input(&ctx, offset);
rc = apei_exec_run(&ctx, ACPI_ERST_SET_RECORD_OFFSET);
if (rc)
return rc;
rc = apei_exec_run(&ctx, ACPI_ERST_EXECUTE_OPERATION);
if (rc)
return rc;
for (;;) {
rc = apei_exec_run(&ctx, ACPI_ERST_CHECK_BUSY_STATUS);
if (rc)
return rc;
val = apei_exec_ctx_get_output(&ctx);
if (!val)
break;
if (erst_timedout(&timeout, SPIN_UNIT))
return -EIO;
}
rc = apei_exec_run(&ctx, ACPI_ERST_GET_COMMAND_STATUS);
if (rc)
return rc;
val = apei_exec_ctx_get_output(&ctx);
rc = apei_exec_run_optional(&ctx, ACPI_ERST_END);
if (rc)
return rc;
return erst_errno(val);
}
static int __erst_read_from_storage(u64 record_id, u64 offset)
{
struct apei_exec_context ctx;
u64 timeout = FIRMWARE_TIMEOUT;
u64 val;
int rc;
erst_exec_ctx_init(&ctx);
rc = apei_exec_run_optional(&ctx, ACPI_ERST_BEGIN_READ);
if (rc)
return rc;
apei_exec_ctx_set_input(&ctx, offset);
rc = apei_exec_run(&ctx, ACPI_ERST_SET_RECORD_OFFSET);
if (rc)
return rc;
apei_exec_ctx_set_input(&ctx, record_id);
rc = apei_exec_run(&ctx, ACPI_ERST_SET_RECORD_ID);
if (rc)
return rc;
rc = apei_exec_run(&ctx, ACPI_ERST_EXECUTE_OPERATION);
if (rc)
return rc;
for (;;) {
rc = apei_exec_run(&ctx, ACPI_ERST_CHECK_BUSY_STATUS);
if (rc)
return rc;
val = apei_exec_ctx_get_output(&ctx);
if (!val)
break;
if (erst_timedout(&timeout, SPIN_UNIT))
return -EIO;
};
rc = apei_exec_run(&ctx, ACPI_ERST_GET_COMMAND_STATUS);
if (rc)
return rc;
val = apei_exec_ctx_get_output(&ctx);
rc = apei_exec_run_optional(&ctx, ACPI_ERST_END);
if (rc)
return rc;
return erst_errno(val);
}
static int __erst_clear_from_storage(u64 record_id)
{
struct apei_exec_context ctx;
u64 timeout = FIRMWARE_TIMEOUT;
u64 val;
int rc;
erst_exec_ctx_init(&ctx);
rc = apei_exec_run_optional(&ctx, ACPI_ERST_BEGIN_CLEAR);
if (rc)
return rc;
apei_exec_ctx_set_input(&ctx, record_id);
rc = apei_exec_run(&ctx, ACPI_ERST_SET_RECORD_ID);
if (rc)
return rc;
rc = apei_exec_run(&ctx, ACPI_ERST_EXECUTE_OPERATION);
if (rc)
return rc;
for (;;) {
rc = apei_exec_run(&ctx, ACPI_ERST_CHECK_BUSY_STATUS);
if (rc)
return rc;
val = apei_exec_ctx_get_output(&ctx);
if (!val)
break;
if (erst_timedout(&timeout, SPIN_UNIT))
return -EIO;
}
rc = apei_exec_run(&ctx, ACPI_ERST_GET_COMMAND_STATUS);
if (rc)
return rc;
val = apei_exec_ctx_get_output(&ctx);
rc = apei_exec_run_optional(&ctx, ACPI_ERST_END);
if (rc)
return rc;
return erst_errno(val);
}
static void pr_unimpl_nvram(void)
{
if (printk_ratelimit())
pr_warn("NVRAM ERST Log Address Range not implemented yet.\n");
}
static int __erst_write_to_nvram(const struct cper_record_header *record)
{
return -ENOSYS;
}
static int __erst_read_to_erange_from_nvram(u64 record_id, u64 *offset)
{
pr_unimpl_nvram();
return -ENOSYS;
}
static int __erst_clear_from_nvram(u64 record_id)
{
pr_unimpl_nvram();
return -ENOSYS;
}
int erst_write(const struct cper_record_header *record)
{
int rc;
unsigned long flags;
struct cper_record_header *rcd_erange;
if (erst_disable)
return -ENODEV;
if (memcmp(record->signature, CPER_SIG_RECORD, CPER_SIG_SIZE))
return -EINVAL;
if (erst_erange.attr & ERST_RANGE_NVRAM) {
if (!raw_spin_trylock_irqsave(&erst_lock, flags))
return -EBUSY;
rc = __erst_write_to_nvram(record);
raw_spin_unlock_irqrestore(&erst_lock, flags);
return rc;
}
if (record->record_length > erst_erange.size)
return -EINVAL;
if (!raw_spin_trylock_irqsave(&erst_lock, flags))
return -EBUSY;
memcpy(erst_erange.vaddr, record, record->record_length);
rcd_erange = erst_erange.vaddr;
memcpy(&rcd_erange->persistence_information, "ER", 2);
rc = __erst_write_to_storage(0);
raw_spin_unlock_irqrestore(&erst_lock, flags);
return rc;
}
static int __erst_read_to_erange(u64 record_id, u64 *offset)
{
int rc;
if (erst_erange.attr & ERST_RANGE_NVRAM)
return __erst_read_to_erange_from_nvram(
record_id, offset);
rc = __erst_read_from_storage(record_id, 0);
if (rc)
return rc;
*offset = 0;
return 0;
}
static ssize_t __erst_read(u64 record_id, struct cper_record_header *record,
size_t buflen)
{
int rc;
u64 offset, len = 0;
struct cper_record_header *rcd_tmp;
rc = __erst_read_to_erange(record_id, &offset);
if (rc)
return rc;
rcd_tmp = erst_erange.vaddr + offset;
len = rcd_tmp->record_length;
if (len <= buflen)
memcpy(record, rcd_tmp, len);
return len;
}
ssize_t erst_read(u64 record_id, struct cper_record_header *record,
size_t buflen)
{
ssize_t len;
unsigned long flags;
if (erst_disable)
return -ENODEV;
raw_spin_lock_irqsave(&erst_lock, flags);
len = __erst_read(record_id, record, buflen);
raw_spin_unlock_irqrestore(&erst_lock, flags);
return len;
}
int erst_clear(u64 record_id)
{
int rc, i;
unsigned long flags;
u64 *entries;
if (erst_disable)
return -ENODEV;
rc = mutex_lock_interruptible(&erst_record_id_cache.lock);
if (rc)
return rc;
raw_spin_lock_irqsave(&erst_lock, flags);
if (erst_erange.attr & ERST_RANGE_NVRAM)
rc = __erst_clear_from_nvram(record_id);
else
rc = __erst_clear_from_storage(record_id);
raw_spin_unlock_irqrestore(&erst_lock, flags);
if (rc)
goto out;
entries = erst_record_id_cache.entries;
for (i = 0; i < erst_record_id_cache.len; i++) {
if (entries[i] == record_id)
entries[i] = APEI_ERST_INVALID_RECORD_ID;
}
__erst_record_id_cache_compact();
out:
mutex_unlock(&erst_record_id_cache.lock);
return rc;
}
static int __init setup_erst_disable(char *str)
{
erst_disable = 1;
return 0;
}
static int erst_check_table(struct acpi_table_erst *erst_tab)
{
if ((erst_tab->header_length !=
(sizeof(struct acpi_table_erst) - sizeof(erst_tab->header)))
&& (erst_tab->header_length != sizeof(struct acpi_table_erst)))
return -EINVAL;
if (erst_tab->header.length < sizeof(struct acpi_table_erst))
return -EINVAL;
if (erst_tab->entries !=
(erst_tab->header.length - sizeof(struct acpi_table_erst)) /
sizeof(struct acpi_erst_entry))
return -EINVAL;
return 0;
}
static int erst_open_pstore(struct pstore_info *psi)
{
int rc;
if (erst_disable)
return -ENODEV;
rc = erst_get_record_id_begin(&reader_pos);
return rc;
}
static int erst_close_pstore(struct pstore_info *psi)
{
erst_get_record_id_end();
return 0;
}
static ssize_t erst_reader(struct pstore_record *record)
{
int rc;
ssize_t len = 0;
u64 record_id;
struct cper_pstore_record *rcd;
size_t rcd_len = sizeof(*rcd) + erst_info.bufsize;
if (erst_disable)
return -ENODEV;
rcd = kmalloc(rcd_len, GFP_KERNEL);
if (!rcd) {
rc = -ENOMEM;
goto out;
}
skip:
rc = erst_get_record_id_next(&reader_pos, &record_id);
if (rc)
goto out;
if (record_id == APEI_ERST_INVALID_RECORD_ID) {
rc = -EINVAL;
goto out;
}
len = erst_read(record_id, &rcd->hdr, rcd_len);
if (len == -ENOENT)
goto skip;
else if (len < sizeof(*rcd)) {
rc = -EIO;
goto out;
}
if (uuid_le_cmp(rcd->hdr.creator_id, CPER_CREATOR_PSTORE) != 0)
goto skip;
record->buf = kmalloc(len, GFP_KERNEL);
if (record->buf == NULL) {
rc = -ENOMEM;
goto out;
}
memcpy(record->buf, rcd->data, len - sizeof(*rcd));
record->id = record_id;
record->compressed = false;
record->ecc_notice_size = 0;
if (uuid_le_cmp(rcd->sec_hdr.section_type,
CPER_SECTION_TYPE_DMESG_Z) == 0) {
record->type = PSTORE_TYPE_DMESG;
record->compressed = true;
} else if (uuid_le_cmp(rcd->sec_hdr.section_type,
CPER_SECTION_TYPE_DMESG) == 0)
record->type = PSTORE_TYPE_DMESG;
else if (uuid_le_cmp(rcd->sec_hdr.section_type,
CPER_SECTION_TYPE_MCE) == 0)
record->type = PSTORE_TYPE_MCE;
else
record->type = PSTORE_TYPE_UNKNOWN;
if (rcd->hdr.validation_bits & CPER_VALID_TIMESTAMP)
record->time.tv_sec = rcd->hdr.timestamp;
else
record->time.tv_sec = 0;
record->time.tv_nsec = 0;
out:
kfree(rcd);
return (rc < 0) ? rc : (len - sizeof(*rcd));
}
static int erst_writer(struct pstore_record *record)
{
struct cper_pstore_record *rcd = (struct cper_pstore_record *)
(erst_info.buf - sizeof(*rcd));
int ret;
memset(rcd, 0, sizeof(*rcd));
memcpy(rcd->hdr.signature, CPER_SIG_RECORD, CPER_SIG_SIZE);
rcd->hdr.revision = CPER_RECORD_REV;
rcd->hdr.signature_end = CPER_SIG_END;
rcd->hdr.section_count = 1;
rcd->hdr.error_severity = CPER_SEV_FATAL;
rcd->hdr.validation_bits = CPER_VALID_TIMESTAMP;
rcd->hdr.timestamp = get_seconds();
rcd->hdr.record_length = sizeof(*rcd) + record->size;
rcd->hdr.creator_id = CPER_CREATOR_PSTORE;
rcd->hdr.notification_type = CPER_NOTIFY_MCE;
rcd->hdr.record_id = cper_next_record_id();
rcd->hdr.flags = CPER_HW_ERROR_FLAGS_PREVERR;
rcd->sec_hdr.section_offset = sizeof(*rcd);
rcd->sec_hdr.section_length = record->size;
rcd->sec_hdr.revision = CPER_SEC_REV;
rcd->sec_hdr.validation_bits = 0;
rcd->sec_hdr.flags = CPER_SEC_PRIMARY;
switch (record->type) {
case PSTORE_TYPE_DMESG:
if (record->compressed)
rcd->sec_hdr.section_type = CPER_SECTION_TYPE_DMESG_Z;
else
rcd->sec_hdr.section_type = CPER_SECTION_TYPE_DMESG;
break;
case PSTORE_TYPE_MCE:
rcd->sec_hdr.section_type = CPER_SECTION_TYPE_MCE;
break;
default:
return -EINVAL;
}
rcd->sec_hdr.section_severity = CPER_SEV_FATAL;
ret = erst_write(&rcd->hdr);
record->id = rcd->hdr.record_id;
return ret;
}
static int erst_clearer(struct pstore_record *record)
{
return erst_clear(record->id);
}
static int __init erst_init(void)
{
int rc = 0;
acpi_status status;
struct apei_exec_context ctx;
struct apei_resources erst_resources;
struct resource *r;
char *buf;
if (acpi_disabled)
goto err;
if (erst_disable) {
pr_info(
"Error Record Serialization Table (ERST) support is disabled.\n");
goto err;
}
status = acpi_get_table(ACPI_SIG_ERST, 0,
(struct acpi_table_header **)&erst_tab);
if (status == AE_NOT_FOUND)
goto err;
else if (ACPI_FAILURE(status)) {
const char *msg = acpi_format_exception(status);
pr_err("Failed to get table, %s\n", msg);
rc = -EINVAL;
goto err;
}
rc = erst_check_table(erst_tab);
if (rc) {
pr_err(FW_BUG "ERST table is invalid.\n");
goto err;
}
apei_resources_init(&erst_resources);
erst_exec_ctx_init(&ctx);
rc = apei_exec_collect_resources(&ctx, &erst_resources);
if (rc)
goto err_fini;
rc = apei_resources_request(&erst_resources, "APEI ERST");
if (rc)
goto err_fini;
rc = apei_exec_pre_map_gars(&ctx);
if (rc)
goto err_release;
rc = erst_get_erange(&erst_erange);
if (rc) {
if (rc == -ENODEV)
pr_info(
"The corresponding hardware device or firmware implementation "
"is not available.\n");
else
pr_err("Failed to get Error Log Address Range.\n");
goto err_unmap_reg;
}
r = request_mem_region(erst_erange.base, erst_erange.size, "APEI ERST");
if (!r) {
pr_err("Can not request [mem %#010llx-%#010llx] for ERST.\n",
(unsigned long long)erst_erange.base,
(unsigned long long)erst_erange.base + erst_erange.size - 1);
rc = -EIO;
goto err_unmap_reg;
}
rc = -ENOMEM;
erst_erange.vaddr = ioremap_cache(erst_erange.base,
erst_erange.size);
if (!erst_erange.vaddr)
goto err_release_erange;
pr_info(
"Error Record Serialization Table (ERST) support is initialized.\n");
buf = kmalloc(erst_erange.size, GFP_KERNEL);
spin_lock_init(&erst_info.buf_lock);
if (buf) {
erst_info.buf = buf + sizeof(struct cper_pstore_record);
erst_info.bufsize = erst_erange.size -
sizeof(struct cper_pstore_record);
rc = pstore_register(&erst_info);
if (rc) {
if (rc != -EPERM)
pr_info(
"Could not register with persistent store.\n");
erst_info.buf = NULL;
erst_info.bufsize = 0;
kfree(buf);
}
} else
pr_err(
"Failed to allocate %lld bytes for persistent store error log.\n",
erst_erange.size);
apei_resources_fini(&erst_resources);
return 0;
err_release_erange:
release_mem_region(erst_erange.base, erst_erange.size);
err_unmap_reg:
apei_exec_post_unmap_gars(&ctx);
err_release:
apei_resources_release(&erst_resources);
err_fini:
apei_resources_fini(&erst_resources);
err:
erst_disable = 1;
return rc;
}
