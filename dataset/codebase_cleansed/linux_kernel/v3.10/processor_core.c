static int __init set_no_mwait(const struct dmi_system_id *id)
{
printk(KERN_NOTICE PREFIX "%s detected - "
"disabling mwait for CPU C-states\n", id->ident);
boot_option_idle_override = IDLE_NOMWAIT;
return 0;
}
static int map_lapic_id(struct acpi_subtable_header *entry,
u32 acpi_id, int *apic_id)
{
struct acpi_madt_local_apic *lapic =
(struct acpi_madt_local_apic *)entry;
if (!(lapic->lapic_flags & ACPI_MADT_ENABLED))
return 0;
if (lapic->processor_id != acpi_id)
return 0;
*apic_id = lapic->id;
return 1;
}
static int map_x2apic_id(struct acpi_subtable_header *entry,
int device_declaration, u32 acpi_id, int *apic_id)
{
struct acpi_madt_local_x2apic *apic =
(struct acpi_madt_local_x2apic *)entry;
if (!(apic->lapic_flags & ACPI_MADT_ENABLED))
return 0;
if (device_declaration && (apic->uid == acpi_id)) {
*apic_id = apic->local_apic_id;
return 1;
}
return 0;
}
static int map_lsapic_id(struct acpi_subtable_header *entry,
int device_declaration, u32 acpi_id, int *apic_id)
{
struct acpi_madt_local_sapic *lsapic =
(struct acpi_madt_local_sapic *)entry;
if (!(lsapic->lapic_flags & ACPI_MADT_ENABLED))
return 0;
if (device_declaration) {
if ((entry->length < 16) || (lsapic->uid != acpi_id))
return 0;
} else if (lsapic->processor_id != acpi_id)
return 0;
*apic_id = (lsapic->id << 8) | lsapic->eid;
return 1;
}
static int map_madt_entry(int type, u32 acpi_id)
{
unsigned long madt_end, entry;
static struct acpi_table_madt *madt;
static int read_madt;
int apic_id = -1;
if (!read_madt) {
if (ACPI_FAILURE(acpi_get_table(ACPI_SIG_MADT, 0,
(struct acpi_table_header **)&madt)))
madt = NULL;
read_madt++;
}
if (!madt)
return apic_id;
entry = (unsigned long)madt;
madt_end = entry + madt->header.length;
entry += sizeof(struct acpi_table_madt);
while (entry + sizeof(struct acpi_subtable_header) < madt_end) {
struct acpi_subtable_header *header =
(struct acpi_subtable_header *)entry;
if (header->type == ACPI_MADT_TYPE_LOCAL_APIC) {
if (map_lapic_id(header, acpi_id, &apic_id))
break;
} else if (header->type == ACPI_MADT_TYPE_LOCAL_X2APIC) {
if (map_x2apic_id(header, type, acpi_id, &apic_id))
break;
} else if (header->type == ACPI_MADT_TYPE_LOCAL_SAPIC) {
if (map_lsapic_id(header, type, acpi_id, &apic_id))
break;
}
entry += header->length;
}
return apic_id;
}
static int map_mat_entry(acpi_handle handle, int type, u32 acpi_id)
{
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
struct acpi_subtable_header *header;
int apic_id = -1;
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
if (header->type == ACPI_MADT_TYPE_LOCAL_APIC) {
map_lapic_id(header, acpi_id, &apic_id);
} else if (header->type == ACPI_MADT_TYPE_LOCAL_SAPIC) {
map_lsapic_id(header, type, acpi_id, &apic_id);
}
exit:
kfree(buffer.pointer);
return apic_id;
}
int acpi_get_cpuid(acpi_handle handle, int type, u32 acpi_id)
{
#ifdef CONFIG_SMP
int i;
#endif
int apic_id = -1;
apic_id = map_mat_entry(handle, type, acpi_id);
if (apic_id == -1)
apic_id = map_madt_entry(type, acpi_id);
if (apic_id == -1) {
if (nr_cpu_ids <= 1 && acpi_id == 0)
return acpi_id;
else
return apic_id;
}
#ifdef CONFIG_SMP
for_each_possible_cpu(i) {
if (cpu_physical_id(i) == apic_id)
return i;
}
#else
if (apic_id == 0)
return apic_id;
#endif
return -1;
}
static bool __init processor_physically_present(acpi_handle handle)
{
int cpuid, type;
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
cpuid = acpi_get_cpuid(handle, type, acpi_id);
if (cpuid == -1)
return false;
return true;
}
static void __cpuinit acpi_set_pdc_bits(u32 *buf)
{
buf[0] = ACPI_PDC_REVISION_ID;
buf[1] = 1;
buf[2] = ACPI_PDC_SMP_T_SWCOORD;
arch_acpi_set_pdc_bits(buf);
}
static struct acpi_object_list *__cpuinit acpi_processor_alloc_pdc(void)
{
struct acpi_object_list *obj_list;
union acpi_object *obj;
u32 *buf;
obj_list = kmalloc(sizeof(struct acpi_object_list), GFP_KERNEL);
if (!obj_list) {
printk(KERN_ERR "Memory allocation error\n");
return NULL;
}
obj = kmalloc(sizeof(union acpi_object), GFP_KERNEL);
if (!obj) {
printk(KERN_ERR "Memory allocation error\n");
kfree(obj_list);
return NULL;
}
buf = kmalloc(12, GFP_KERNEL);
if (!buf) {
printk(KERN_ERR "Memory allocation error\n");
kfree(obj);
kfree(obj_list);
return NULL;
}
acpi_set_pdc_bits(buf);
obj->type = ACPI_TYPE_BUFFER;
obj->buffer.length = 12;
obj->buffer.pointer = (u8 *) buf;
obj_list->count = 1;
obj_list->pointer = obj;
return obj_list;
}
static int __cpuinit
acpi_processor_eval_pdc(acpi_handle handle, struct acpi_object_list *pdc_in)
{
acpi_status status = AE_OK;
if (boot_option_idle_override == IDLE_NOMWAIT) {
union acpi_object *obj;
u32 *buffer = NULL;
obj = pdc_in->pointer;
buffer = (u32 *)(obj->buffer.pointer);
buffer[2] &= ~(ACPI_PDC_C_C2C3_FFH | ACPI_PDC_C_C1_FFH);
}
status = acpi_evaluate_object(handle, "_PDC", pdc_in, NULL);
if (ACPI_FAILURE(status))
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Could not evaluate _PDC, using legacy perf. control.\n"));
return status;
}
void __cpuinit acpi_processor_set_pdc(acpi_handle handle)
{
struct acpi_object_list *obj_list;
if (arch_has_acpi_pdc() == false)
return;
obj_list = acpi_processor_alloc_pdc();
if (!obj_list)
return;
acpi_processor_eval_pdc(handle, obj_list);
kfree(obj_list->pointer->buffer.pointer);
kfree(obj_list->pointer);
kfree(obj_list);
}
static acpi_status __init
early_init_pdc(acpi_handle handle, u32 lvl, void *context, void **rv)
{
if (processor_physically_present(handle) == false)
return AE_OK;
acpi_processor_set_pdc(handle);
return AE_OK;
}
void __init acpi_early_processor_set_pdc(void)
{
dmi_check_system(processor_idle_dmi_table);
acpi_walk_namespace(ACPI_TYPE_PROCESSOR, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
early_init_pdc, NULL, NULL, NULL);
acpi_get_devices("ACPI0007", early_init_pdc, NULL, NULL);
}
