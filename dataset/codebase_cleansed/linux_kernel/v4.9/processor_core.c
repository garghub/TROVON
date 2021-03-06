static struct acpi_table_madt *get_madt_table(void)
{
static struct acpi_table_madt *madt;
static int read_madt;
if (!read_madt) {
if (ACPI_FAILURE(acpi_get_table(ACPI_SIG_MADT, 0,
(struct acpi_table_header **)&madt)))
madt = NULL;
read_madt++;
}
return madt;
}
static int map_lapic_id(struct acpi_subtable_header *entry,
u32 acpi_id, phys_cpuid_t *apic_id, bool ignore_disabled)
{
struct acpi_madt_local_apic *lapic =
container_of(entry, struct acpi_madt_local_apic, header);
if (ignore_disabled && !(lapic->lapic_flags & ACPI_MADT_ENABLED))
return -ENODEV;
if (lapic->processor_id != acpi_id)
return -EINVAL;
*apic_id = lapic->id;
return 0;
}
static int map_x2apic_id(struct acpi_subtable_header *entry,
int device_declaration, u32 acpi_id, phys_cpuid_t *apic_id,
bool ignore_disabled)
{
struct acpi_madt_local_x2apic *apic =
container_of(entry, struct acpi_madt_local_x2apic, header);
if (ignore_disabled && !(apic->lapic_flags & ACPI_MADT_ENABLED))
return -ENODEV;
if (device_declaration && (apic->uid == acpi_id)) {
*apic_id = apic->local_apic_id;
return 0;
}
return -EINVAL;
}
static int map_lsapic_id(struct acpi_subtable_header *entry,
int device_declaration, u32 acpi_id, phys_cpuid_t *apic_id,
bool ignore_disabled)
{
struct acpi_madt_local_sapic *lsapic =
container_of(entry, struct acpi_madt_local_sapic, header);
if (ignore_disabled && !(lsapic->lapic_flags & ACPI_MADT_ENABLED))
return -ENODEV;
if (device_declaration) {
if ((entry->length < 16) || (lsapic->uid != acpi_id))
return -EINVAL;
} else if (lsapic->processor_id != acpi_id)
return -EINVAL;
*apic_id = (lsapic->id << 8) | lsapic->eid;
return 0;
}
static int map_gicc_mpidr(struct acpi_subtable_header *entry,
int device_declaration, u32 acpi_id, phys_cpuid_t *mpidr,
bool ignore_disabled)
{
struct acpi_madt_generic_interrupt *gicc =
container_of(entry, struct acpi_madt_generic_interrupt, header);
if (ignore_disabled && !(gicc->flags & ACPI_MADT_ENABLED))
return -ENODEV;
if (device_declaration && (gicc->uid == acpi_id)) {
*mpidr = gicc->arm_mpidr;
return 0;
}
return -EINVAL;
}
static phys_cpuid_t map_madt_entry(struct acpi_table_madt *madt,
int type, u32 acpi_id, bool ignore_disabled)
{
unsigned long madt_end, entry;
phys_cpuid_t phys_id = PHYS_CPUID_INVALID;
if (!madt)
return phys_id;
entry = (unsigned long)madt;
madt_end = entry + madt->header.length;
entry += sizeof(struct acpi_table_madt);
while (entry + sizeof(struct acpi_subtable_header) < madt_end) {
struct acpi_subtable_header *header =
(struct acpi_subtable_header *)entry;
if (header->type == ACPI_MADT_TYPE_LOCAL_APIC) {
if (!map_lapic_id(header, acpi_id, &phys_id,
ignore_disabled))
break;
} else if (header->type == ACPI_MADT_TYPE_LOCAL_X2APIC) {
if (!map_x2apic_id(header, type, acpi_id, &phys_id,
ignore_disabled))
break;
} else if (header->type == ACPI_MADT_TYPE_LOCAL_SAPIC) {
if (!map_lsapic_id(header, type, acpi_id, &phys_id,
ignore_disabled))
break;
} else if (header->type == ACPI_MADT_TYPE_GENERIC_INTERRUPT) {
if (!map_gicc_mpidr(header, type, acpi_id, &phys_id,
ignore_disabled))
break;
}
entry += header->length;
}
return phys_id;
}
phys_cpuid_t __init acpi_map_madt_entry(u32 acpi_id)
{
struct acpi_table_madt *madt = NULL;
acpi_size tbl_size;
phys_cpuid_t rv;
acpi_get_table_with_size(ACPI_SIG_MADT, 0,
(struct acpi_table_header **)&madt,
&tbl_size);
if (!madt)
return PHYS_CPUID_INVALID;
rv = map_madt_entry(madt, 1, acpi_id, true);
early_acpi_os_unmap_memory(madt, tbl_size);
return rv;
}
static phys_cpuid_t map_mat_entry(acpi_handle handle, int type, u32 acpi_id,
bool ignore_disabled)
{
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
struct acpi_subtable_header *header;
phys_cpuid_t phys_id = PHYS_CPUID_INVALID;
if (ACPI_FAILURE(acpi_evaluate_object(handle, "_MAT", NULL, &buffer)))
goto exit;
if (!buffer.length || !buffer.pointer)
goto exit;
obj = buffer.pointer;
if (obj->type != ACPI_TYPE_BUFFER ||
obj->buffer.length < sizeof(struct acpi_subtable_header)) {
goto exit;
}
header = (struct acpi_subtable_header *)obj->buffer.pointer;
if (header->type == ACPI_MADT_TYPE_LOCAL_APIC)
map_lapic_id(header, acpi_id, &phys_id, ignore_disabled);
else if (header->type == ACPI_MADT_TYPE_LOCAL_SAPIC)
map_lsapic_id(header, type, acpi_id, &phys_id, ignore_disabled);
else if (header->type == ACPI_MADT_TYPE_LOCAL_X2APIC)
map_x2apic_id(header, type, acpi_id, &phys_id, ignore_disabled);
else if (header->type == ACPI_MADT_TYPE_GENERIC_INTERRUPT)
map_gicc_mpidr(header, type, acpi_id, &phys_id,
ignore_disabled);
exit:
kfree(buffer.pointer);
return phys_id;
}
static phys_cpuid_t __acpi_get_phys_id(acpi_handle handle, int type,
u32 acpi_id, bool ignore_disabled)
{
phys_cpuid_t phys_id;
phys_id = map_mat_entry(handle, type, acpi_id, ignore_disabled);
if (invalid_phys_cpuid(phys_id))
phys_id = map_madt_entry(get_madt_table(), type, acpi_id,
ignore_disabled);
return phys_id;
}
phys_cpuid_t acpi_get_phys_id(acpi_handle handle, int type, u32 acpi_id)
{
return __acpi_get_phys_id(handle, type, acpi_id, true);
}
int acpi_map_cpuid(phys_cpuid_t phys_id, u32 acpi_id)
{
#ifdef CONFIG_SMP
int i;
#endif
if (invalid_phys_cpuid(phys_id)) {
if (nr_cpu_ids <= 1 && acpi_id == 0)
return acpi_id;
else
return -EINVAL;
}
#ifdef CONFIG_SMP
for_each_possible_cpu(i) {
if (cpu_physical_id(i) == phys_id)
return i;
}
#else
if (phys_id == 0)
return phys_id;
#endif
return -ENODEV;
}
int acpi_get_cpuid(acpi_handle handle, int type, u32 acpi_id)
{
phys_cpuid_t phys_id;
phys_id = acpi_get_phys_id(handle, type, acpi_id);
return acpi_map_cpuid(phys_id, acpi_id);
}
static bool __init
map_processor(acpi_handle handle, phys_cpuid_t *phys_id, int *cpuid)
{
int type, id;
u32 acpi_id;
acpi_status status;
acpi_object_type acpi_type;
unsigned long long tmp;
union acpi_object object = { 0 };
struct acpi_buffer buffer = { sizeof(union acpi_object), &object };
status = acpi_get_type(handle, &acpi_type);
if (ACPI_FAILURE(status))
return false;
switch (acpi_type) {
case ACPI_TYPE_PROCESSOR:
status = acpi_evaluate_object(handle, NULL, NULL, &buffer);
if (ACPI_FAILURE(status))
return false;
acpi_id = object.processor.proc_id;
if(acpi_processor_validate_proc_id(acpi_id))
return false;
break;
case ACPI_TYPE_DEVICE:
status = acpi_evaluate_integer(handle, "_UID", NULL, &tmp);
if (ACPI_FAILURE(status))
return false;
acpi_id = tmp;
break;
default:
return false;
}
type = (acpi_type == ACPI_TYPE_DEVICE) ? 1 : 0;
*phys_id = __acpi_get_phys_id(handle, type, acpi_id, false);
id = acpi_map_cpuid(*phys_id, acpi_id);
if (id < 0)
return false;
*cpuid = id;
return true;
}
static acpi_status __init
set_processor_node_mapping(acpi_handle handle, u32 lvl, void *context,
void **rv)
{
phys_cpuid_t phys_id;
int cpu_id;
if (!map_processor(handle, &phys_id, &cpu_id))
return AE_ERROR;
acpi_map_cpu2node(handle, cpu_id, phys_id);
return AE_OK;
}
void __init acpi_set_processor_mapping(void)
{
acpi_walk_namespace(ACPI_TYPE_PROCESSOR, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, set_processor_node_mapping,
NULL, NULL, NULL);
}
void __init acpi_set_processor_mapping(void) {}
static int get_ioapic_id(struct acpi_subtable_header *entry, u32 gsi_base,
u64 *phys_addr, int *ioapic_id)
{
struct acpi_madt_io_apic *ioapic = (struct acpi_madt_io_apic *)entry;
if (ioapic->global_irq_base != gsi_base)
return 0;
*phys_addr = ioapic->address;
*ioapic_id = ioapic->id;
return 1;
}
static int parse_madt_ioapic_entry(u32 gsi_base, u64 *phys_addr)
{
struct acpi_subtable_header *hdr;
unsigned long madt_end, entry;
struct acpi_table_madt *madt;
int apic_id = -1;
madt = get_madt_table();
if (!madt)
return apic_id;
entry = (unsigned long)madt;
madt_end = entry + madt->header.length;
entry += sizeof(struct acpi_table_madt);
while (entry + sizeof(struct acpi_subtable_header) < madt_end) {
hdr = (struct acpi_subtable_header *)entry;
if (hdr->type == ACPI_MADT_TYPE_IO_APIC &&
get_ioapic_id(hdr, gsi_base, phys_addr, &apic_id))
break;
else
entry += hdr->length;
}
return apic_id;
}
static int parse_mat_ioapic_entry(acpi_handle handle, u32 gsi_base,
u64 *phys_addr)
{
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_subtable_header *header;
union acpi_object *obj;
int apic_id = -1;
if (ACPI_FAILURE(acpi_evaluate_object(handle, "_MAT", NULL, &buffer)))
goto exit;
if (!buffer.length || !buffer.pointer)
goto exit;
obj = buffer.pointer;
if (obj->type != ACPI_TYPE_BUFFER ||
obj->buffer.length < sizeof(struct acpi_subtable_header))
goto exit;
header = (struct acpi_subtable_header *)obj->buffer.pointer;
if (header->type == ACPI_MADT_TYPE_IO_APIC)
get_ioapic_id(header, gsi_base, phys_addr, &apic_id);
exit:
kfree(buffer.pointer);
return apic_id;
}
int acpi_get_ioapic_id(acpi_handle handle, u32 gsi_base, u64 *phys_addr)
{
int apic_id;
apic_id = parse_mat_ioapic_entry(handle, gsi_base, phys_addr);
if (apic_id == -1)
apic_id = parse_madt_ioapic_entry(gsi_base, phys_addr);
return apic_id;
}
