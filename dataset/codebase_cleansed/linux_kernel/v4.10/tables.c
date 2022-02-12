void acpi_table_print_madt_entry(struct acpi_subtable_header *header)
{
if (!header)
return;
switch (header->type) {
case ACPI_MADT_TYPE_LOCAL_APIC:
{
struct acpi_madt_local_apic *p =
(struct acpi_madt_local_apic *)header;
pr_debug("LAPIC (acpi_id[0x%02x] lapic_id[0x%02x] %s)\n",
p->processor_id, p->id,
(p->lapic_flags & ACPI_MADT_ENABLED) ? "enabled" : "disabled");
}
break;
case ACPI_MADT_TYPE_LOCAL_X2APIC:
{
struct acpi_madt_local_x2apic *p =
(struct acpi_madt_local_x2apic *)header;
pr_debug("X2APIC (apic_id[0x%02x] uid[0x%02x] %s)\n",
p->local_apic_id, p->uid,
(p->lapic_flags & ACPI_MADT_ENABLED) ? "enabled" : "disabled");
}
break;
case ACPI_MADT_TYPE_IO_APIC:
{
struct acpi_madt_io_apic *p =
(struct acpi_madt_io_apic *)header;
pr_debug("IOAPIC (id[0x%02x] address[0x%08x] gsi_base[%d])\n",
p->id, p->address, p->global_irq_base);
}
break;
case ACPI_MADT_TYPE_INTERRUPT_OVERRIDE:
{
struct acpi_madt_interrupt_override *p =
(struct acpi_madt_interrupt_override *)header;
pr_info("INT_SRC_OVR (bus %d bus_irq %d global_irq %d %s %s)\n",
p->bus, p->source_irq, p->global_irq,
mps_inti_flags_polarity[p->inti_flags & ACPI_MADT_POLARITY_MASK],
mps_inti_flags_trigger[(p->inti_flags & ACPI_MADT_TRIGGER_MASK) >> 2]);
if (p->inti_flags &
~(ACPI_MADT_POLARITY_MASK | ACPI_MADT_TRIGGER_MASK))
pr_info("INT_SRC_OVR unexpected reserved flags: 0x%x\n",
p->inti_flags &
~(ACPI_MADT_POLARITY_MASK | ACPI_MADT_TRIGGER_MASK));
}
break;
case ACPI_MADT_TYPE_NMI_SOURCE:
{
struct acpi_madt_nmi_source *p =
(struct acpi_madt_nmi_source *)header;
pr_info("NMI_SRC (%s %s global_irq %d)\n",
mps_inti_flags_polarity[p->inti_flags & ACPI_MADT_POLARITY_MASK],
mps_inti_flags_trigger[(p->inti_flags & ACPI_MADT_TRIGGER_MASK) >> 2],
p->global_irq);
}
break;
case ACPI_MADT_TYPE_LOCAL_APIC_NMI:
{
struct acpi_madt_local_apic_nmi *p =
(struct acpi_madt_local_apic_nmi *)header;
pr_info("LAPIC_NMI (acpi_id[0x%02x] %s %s lint[0x%x])\n",
p->processor_id,
mps_inti_flags_polarity[p->inti_flags & ACPI_MADT_POLARITY_MASK ],
mps_inti_flags_trigger[(p->inti_flags & ACPI_MADT_TRIGGER_MASK) >> 2],
p->lint);
}
break;
case ACPI_MADT_TYPE_LOCAL_X2APIC_NMI:
{
u16 polarity, trigger;
struct acpi_madt_local_x2apic_nmi *p =
(struct acpi_madt_local_x2apic_nmi *)header;
polarity = p->inti_flags & ACPI_MADT_POLARITY_MASK;
trigger = (p->inti_flags & ACPI_MADT_TRIGGER_MASK) >> 2;
pr_info("X2APIC_NMI (uid[0x%02x] %s %s lint[0x%x])\n",
p->uid,
mps_inti_flags_polarity[polarity],
mps_inti_flags_trigger[trigger],
p->lint);
}
break;
case ACPI_MADT_TYPE_LOCAL_APIC_OVERRIDE:
{
struct acpi_madt_local_apic_override *p =
(struct acpi_madt_local_apic_override *)header;
pr_info("LAPIC_ADDR_OVR (address[%p])\n",
(void *)(unsigned long)p->address);
}
break;
case ACPI_MADT_TYPE_IO_SAPIC:
{
struct acpi_madt_io_sapic *p =
(struct acpi_madt_io_sapic *)header;
pr_debug("IOSAPIC (id[0x%x] address[%p] gsi_base[%d])\n",
p->id, (void *)(unsigned long)p->address,
p->global_irq_base);
}
break;
case ACPI_MADT_TYPE_LOCAL_SAPIC:
{
struct acpi_madt_local_sapic *p =
(struct acpi_madt_local_sapic *)header;
pr_debug("LSAPIC (acpi_id[0x%02x] lsapic_id[0x%02x] lsapic_eid[0x%02x] %s)\n",
p->processor_id, p->id, p->eid,
(p->lapic_flags & ACPI_MADT_ENABLED) ? "enabled" : "disabled");
}
break;
case ACPI_MADT_TYPE_INTERRUPT_SOURCE:
{
struct acpi_madt_interrupt_source *p =
(struct acpi_madt_interrupt_source *)header;
pr_info("PLAT_INT_SRC (%s %s type[0x%x] id[0x%04x] eid[0x%x] iosapic_vector[0x%x] global_irq[0x%x]\n",
mps_inti_flags_polarity[p->inti_flags & ACPI_MADT_POLARITY_MASK],
mps_inti_flags_trigger[(p->inti_flags & ACPI_MADT_TRIGGER_MASK) >> 2],
p->type, p->id, p->eid, p->io_sapic_vector,
p->global_irq);
}
break;
case ACPI_MADT_TYPE_GENERIC_INTERRUPT:
{
struct acpi_madt_generic_interrupt *p =
(struct acpi_madt_generic_interrupt *)header;
pr_debug("GICC (acpi_id[0x%04x] address[%llx] MPIDR[0x%llx] %s)\n",
p->uid, p->base_address,
p->arm_mpidr,
(p->flags & ACPI_MADT_ENABLED) ? "enabled" : "disabled");
}
break;
case ACPI_MADT_TYPE_GENERIC_DISTRIBUTOR:
{
struct acpi_madt_generic_distributor *p =
(struct acpi_madt_generic_distributor *)header;
pr_debug("GIC Distributor (gic_id[0x%04x] address[%llx] gsi_base[%d])\n",
p->gic_id, p->base_address,
p->global_irq_base);
}
break;
default:
pr_warn("Found unsupported MADT entry (type = 0x%x)\n",
header->type);
break;
}
}
static int __init
acpi_parse_entries_array(char *id, unsigned long table_size,
struct acpi_table_header *table_header,
struct acpi_subtable_proc *proc, int proc_num,
unsigned int max_entries)
{
struct acpi_subtable_header *entry;
unsigned long table_end;
int count = 0;
int errs = 0;
int i;
if (acpi_disabled)
return -ENODEV;
if (!id)
return -EINVAL;
if (!table_size)
return -EINVAL;
if (!table_header) {
pr_warn("%4.4s not present\n", id);
return -ENODEV;
}
table_end = (unsigned long)table_header + table_header->length;
entry = (struct acpi_subtable_header *)
((unsigned long)table_header + table_size);
while (((unsigned long)entry) + sizeof(struct acpi_subtable_header) <
table_end) {
if (max_entries && count >= max_entries)
break;
for (i = 0; i < proc_num; i++) {
if (entry->type != proc[i].id)
continue;
if (!proc[i].handler ||
(!errs && proc[i].handler(entry, table_end))) {
errs++;
continue;
}
proc[i].count++;
break;
}
if (i != proc_num)
count++;
if (entry->length == 0) {
pr_err("[%4.4s:0x%02x] Invalid zero length\n", id, proc->id);
return -EINVAL;
}
entry = (struct acpi_subtable_header *)
((unsigned long)entry + entry->length);
}
if (max_entries && count > max_entries) {
pr_warn("[%4.4s:0x%02x] found the maximum %i entries\n",
id, proc->id, count);
}
return errs ? -EINVAL : count;
}
int __init
acpi_parse_entries(char *id,
unsigned long table_size,
acpi_tbl_entry_handler handler,
struct acpi_table_header *table_header,
int entry_id, unsigned int max_entries)
{
struct acpi_subtable_proc proc = {
.id = entry_id,
.handler = handler,
};
return acpi_parse_entries_array(id, table_size, table_header,
&proc, 1, max_entries);
}
int __init
acpi_table_parse_entries_array(char *id,
unsigned long table_size,
struct acpi_subtable_proc *proc, int proc_num,
unsigned int max_entries)
{
struct acpi_table_header *table_header = NULL;
int count;
u32 instance = 0;
if (acpi_disabled)
return -ENODEV;
if (!id)
return -EINVAL;
if (!strncmp(id, ACPI_SIG_MADT, 4))
instance = acpi_apic_instance;
acpi_get_table(id, instance, &table_header);
if (!table_header) {
pr_warn("%4.4s not present\n", id);
return -ENODEV;
}
count = acpi_parse_entries_array(id, table_size, table_header,
proc, proc_num, max_entries);
acpi_put_table(table_header);
return count;
}
int __init
acpi_table_parse_entries(char *id,
unsigned long table_size,
int entry_id,
acpi_tbl_entry_handler handler,
unsigned int max_entries)
{
struct acpi_subtable_proc proc = {
.id = entry_id,
.handler = handler,
};
return acpi_table_parse_entries_array(id, table_size, &proc, 1,
max_entries);
}
int __init
acpi_table_parse_madt(enum acpi_madt_type id,
acpi_tbl_entry_handler handler, unsigned int max_entries)
{
return acpi_table_parse_entries(ACPI_SIG_MADT,
sizeof(struct acpi_table_madt), id,
handler, max_entries);
}
int __init acpi_table_parse(char *id, acpi_tbl_table_handler handler)
{
struct acpi_table_header *table = NULL;
if (acpi_disabled)
return -ENODEV;
if (!id || !handler)
return -EINVAL;
if (strncmp(id, ACPI_SIG_MADT, 4) == 0)
acpi_get_table(id, acpi_apic_instance, &table);
else
acpi_get_table(id, 0, &table);
if (table) {
handler(table);
acpi_put_table(table);
return 0;
} else
return -ENODEV;
}
static void __init check_multiple_madt(void)
{
struct acpi_table_header *table = NULL;
acpi_get_table(ACPI_SIG_MADT, 2, &table);
if (table) {
pr_warn("BIOS bug: multiple APIC/MADT found, using %d\n",
acpi_apic_instance);
pr_warn("If \"acpi_apic_instance=%d\" works better, "
"notify linux-acpi@vger.kernel.org\n",
acpi_apic_instance ? 0 : 2);
acpi_put_table(table);
} else
acpi_apic_instance = 0;
return;
}
static void acpi_table_taint(struct acpi_table_header *table)
{
pr_warn("Override [%4.4s-%8.8s], this is unsafe: tainting kernel\n",
table->signature, table->oem_table_id);
add_taint(TAINT_OVERRIDDEN_ACPI_TABLE, LOCKDEP_NOW_UNRELIABLE);
}
static u8 __init acpi_table_checksum(u8 *buffer, u32 length)
{
u8 sum = 0;
u8 *end = buffer + length;
while (buffer < end)
sum = (u8) (sum + *(buffer++));
return sum;
}
void __init acpi_table_upgrade(void)
{
void *data = (void *)initrd_start;
size_t size = initrd_end - initrd_start;
int sig, no, table_nr = 0, total_offset = 0;
long offset = 0;
struct acpi_table_header *table;
char cpio_path[32] = "kernel/firmware/acpi/";
struct cpio_data file;
if (data == NULL || size == 0)
return;
for (no = 0; no < NR_ACPI_INITRD_TABLES; no++) {
file = find_cpio_data(cpio_path, data, size, &offset);
if (!file.data)
break;
data += offset;
size -= offset;
if (file.size < sizeof(struct acpi_table_header)) {
pr_err("ACPI OVERRIDE: Table smaller than ACPI header [%s%s]\n",
cpio_path, file.name);
continue;
}
table = file.data;
for (sig = 0; table_sigs[sig]; sig++)
if (!memcmp(table->signature, table_sigs[sig], 4))
break;
if (!table_sigs[sig]) {
pr_err("ACPI OVERRIDE: Unknown signature [%s%s]\n",
cpio_path, file.name);
continue;
}
if (file.size != table->length) {
pr_err("ACPI OVERRIDE: File length does not match table length [%s%s]\n",
cpio_path, file.name);
continue;
}
if (acpi_table_checksum(file.data, table->length)) {
pr_err("ACPI OVERRIDE: Bad table checksum [%s%s]\n",
cpio_path, file.name);
continue;
}
pr_info("%4.4s ACPI table found in initrd [%s%s][0x%x]\n",
table->signature, cpio_path, file.name, table->length);
all_tables_size += table->length;
acpi_initrd_files[table_nr].data = file.data;
acpi_initrd_files[table_nr].size = file.size;
table_nr++;
}
if (table_nr == 0)
return;
acpi_tables_addr =
memblock_find_in_range(0, ACPI_TABLE_UPGRADE_MAX_PHYS,
all_tables_size, PAGE_SIZE);
if (!acpi_tables_addr) {
WARN_ON(1);
return;
}
memblock_reserve(acpi_tables_addr, all_tables_size);
arch_reserve_mem_area(acpi_tables_addr, all_tables_size);
for (no = 0; no < table_nr; no++) {
unsigned char *src_p = acpi_initrd_files[no].data;
phys_addr_t size = acpi_initrd_files[no].size;
phys_addr_t dest_addr = acpi_tables_addr + total_offset;
phys_addr_t slop, clen;
char *dest_p;
total_offset += size;
while (size) {
slop = dest_addr & ~PAGE_MASK;
clen = size;
if (clen > MAP_CHUNK_SIZE - slop)
clen = MAP_CHUNK_SIZE - slop;
dest_p = early_memremap(dest_addr & PAGE_MASK,
clen + slop);
memcpy(dest_p + slop, src_p, clen);
early_memunmap(dest_p, clen + slop);
src_p += clen;
dest_addr += clen;
size -= clen;
}
}
}
static acpi_status
acpi_table_initrd_override(struct acpi_table_header *existing_table,
acpi_physical_address *address, u32 *length)
{
int table_offset = 0;
int table_index = 0;
struct acpi_table_header *table;
u32 table_length;
*length = 0;
*address = 0;
if (!acpi_tables_addr)
return AE_OK;
while (table_offset + ACPI_HEADER_SIZE <= all_tables_size) {
table = acpi_os_map_memory(acpi_tables_addr + table_offset,
ACPI_HEADER_SIZE);
if (table_offset + table->length > all_tables_size) {
acpi_os_unmap_memory(table, ACPI_HEADER_SIZE);
WARN_ON(1);
return AE_OK;
}
table_length = table->length;
if (memcmp(existing_table->signature, table->signature, 4) ||
memcmp(table->oem_id, existing_table->oem_id,
ACPI_OEM_ID_SIZE) ||
memcmp(table->oem_table_id, existing_table->oem_table_id,
ACPI_OEM_TABLE_ID_SIZE)) {
acpi_os_unmap_memory(table, ACPI_HEADER_SIZE);
goto next_table;
}
if (test_and_set_bit(table_index, acpi_initrd_installed) ||
existing_table->oem_revision >= table->oem_revision) {
acpi_os_unmap_memory(table, ACPI_HEADER_SIZE);
goto next_table;
}
*length = table_length;
*address = acpi_tables_addr + table_offset;
pr_info("Table Upgrade: override [%4.4s-%6.6s-%8.8s]\n",
table->signature, table->oem_id,
table->oem_table_id);
acpi_os_unmap_memory(table, ACPI_HEADER_SIZE);
break;
next_table:
table_offset += table_length;
table_index++;
}
return AE_OK;
}
static void __init acpi_table_initrd_scan(void)
{
int table_offset = 0;
int table_index = 0;
u32 table_length;
struct acpi_table_header *table;
if (!acpi_tables_addr)
return;
while (table_offset + ACPI_HEADER_SIZE <= all_tables_size) {
table = acpi_os_map_memory(acpi_tables_addr + table_offset,
ACPI_HEADER_SIZE);
if (table_offset + table->length > all_tables_size) {
acpi_os_unmap_memory(table, ACPI_HEADER_SIZE);
WARN_ON(1);
return;
}
table_length = table->length;
if (ACPI_COMPARE_NAME(table->signature, ACPI_SIG_RSDT) ||
ACPI_COMPARE_NAME(table->signature, ACPI_SIG_XSDT)) {
acpi_os_unmap_memory(table, ACPI_HEADER_SIZE);
goto next_table;
}
if (test_and_set_bit(table_index, acpi_initrd_installed)) {
acpi_os_unmap_memory(table, ACPI_HEADER_SIZE);
goto next_table;
}
pr_info("Table Upgrade: install [%4.4s-%6.6s-%8.8s]\n",
table->signature, table->oem_id,
table->oem_table_id);
acpi_os_unmap_memory(table, ACPI_HEADER_SIZE);
acpi_install_table(acpi_tables_addr + table_offset, TRUE);
next_table:
table_offset += table_length;
table_index++;
}
}
static acpi_status
acpi_table_initrd_override(struct acpi_table_header *existing_table,
acpi_physical_address *address,
u32 *table_length)
{
*table_length = 0;
*address = 0;
return AE_OK;
}
static void __init acpi_table_initrd_scan(void)
{
}
acpi_status
acpi_os_physical_table_override(struct acpi_table_header *existing_table,
acpi_physical_address *address,
u32 *table_length)
{
return acpi_table_initrd_override(existing_table, address,
table_length);
}
acpi_status
acpi_os_table_override(struct acpi_table_header *existing_table,
struct acpi_table_header **new_table)
{
if (!existing_table || !new_table)
return AE_BAD_PARAMETER;
*new_table = NULL;
#ifdef CONFIG_ACPI_CUSTOM_DSDT
if (strncmp(existing_table->signature, "DSDT", 4) == 0)
*new_table = (struct acpi_table_header *)AmlCode;
#endif
if (*new_table != NULL)
acpi_table_taint(existing_table);
return AE_OK;
}
int __init acpi_table_init(void)
{
acpi_status status;
if (acpi_verify_table_checksum) {
pr_info("Early table checksum verification enabled\n");
acpi_gbl_verify_table_checksum = TRUE;
} else {
pr_info("Early table checksum verification disabled\n");
acpi_gbl_verify_table_checksum = FALSE;
}
status = acpi_initialize_tables(initial_tables, ACPI_MAX_TABLES, 0);
if (ACPI_FAILURE(status))
return -EINVAL;
acpi_table_initrd_scan();
check_multiple_madt();
return 0;
}
static int __init acpi_parse_apic_instance(char *str)
{
if (!str)
return -EINVAL;
if (kstrtoint(str, 0, &acpi_apic_instance))
return -EINVAL;
pr_notice("Shall use APIC/MADT table %d\n", acpi_apic_instance);
return 0;
}
static int __init acpi_force_table_verification_setup(char *s)
{
acpi_verify_table_checksum = true;
return 0;
}
static int __init acpi_force_32bit_fadt_addr(char *s)
{
pr_info("Forcing 32 Bit FADT addresses\n");
acpi_gbl_use32_bit_fadt_addresses = TRUE;
return 0;
}
