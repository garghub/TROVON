char acpi_ut_hex_to_ascii_char(u64 integer, u32 position)
{
return (acpi_gbl_hex_to_ascii[(integer >> position) & 0xF]);
}
char *acpi_ut_get_region_name(u8 space_id)
{
if (space_id >= ACPI_USER_REGION_BEGIN) {
return ("UserDefinedRegion");
} else if (space_id == ACPI_ADR_SPACE_DATA_TABLE) {
return ("DataTable");
} else if (space_id == ACPI_ADR_SPACE_FIXED_HARDWARE) {
return ("FunctionalFixedHW");
} else if (space_id >= ACPI_NUM_PREDEFINED_REGIONS) {
return ("InvalidSpaceId");
}
return (ACPI_CAST_PTR(char, acpi_gbl_region_types[space_id]));
}
char *acpi_ut_get_event_name(u32 event_id)
{
if (event_id > ACPI_EVENT_MAX) {
return ("InvalidEventID");
}
return (ACPI_CAST_PTR(char, acpi_gbl_event_types[event_id]));
}
char *acpi_ut_get_type_name(acpi_object_type type)
{
if (type > ACPI_TYPE_INVALID) {
return (ACPI_CAST_PTR(char, acpi_gbl_bad_type));
}
return (ACPI_CAST_PTR(char, acpi_gbl_ns_type_names[type]));
}
char *acpi_ut_get_object_type_name(union acpi_operand_object *obj_desc)
{
if (!obj_desc) {
return ("[NULL Object Descriptor]");
}
return (acpi_ut_get_type_name(obj_desc->common.type));
}
char *acpi_ut_get_node_name(void *object)
{
struct acpi_namespace_node *node = (struct acpi_namespace_node *)object;
if (!object) {
return ("NULL");
}
if ((object == ACPI_ROOT_OBJECT) || (object == acpi_gbl_root_node)) {
return ("\"\\\" ");
}
if (ACPI_GET_DESCRIPTOR_TYPE(node) != ACPI_DESC_TYPE_NAMED) {
return ("####");
}
acpi_ut_repair_name(node->name.ascii);
return (node->name.ascii);
}
char *acpi_ut_get_descriptor_name(void *object)
{
if (!object) {
return ("NULL OBJECT");
}
if (ACPI_GET_DESCRIPTOR_TYPE(object) > ACPI_DESC_TYPE_MAX) {
return ("Not a Descriptor");
}
return (ACPI_CAST_PTR(char,
acpi_gbl_desc_type_names[ACPI_GET_DESCRIPTOR_TYPE
(object)]));
}
const char *acpi_ut_get_reference_name(union acpi_operand_object *object)
{
if (!object) {
return ("NULL Object");
}
if (ACPI_GET_DESCRIPTOR_TYPE(object) != ACPI_DESC_TYPE_OPERAND) {
return ("Not an Operand object");
}
if (object->common.type != ACPI_TYPE_LOCAL_REFERENCE) {
return ("Not a Reference object");
}
if (object->reference.class > ACPI_REFCLASS_MAX) {
return ("Unknown Reference class");
}
return (acpi_gbl_ref_class_names[object->reference.class]);
}
char *acpi_ut_get_mutex_name(u32 mutex_id)
{
if (mutex_id > ACPI_MAX_MUTEX) {
return ("Invalid Mutex ID");
}
return (acpi_gbl_mutex_names[mutex_id]);
}
const char *acpi_ut_get_notify_name(u32 notify_value)
{
if (notify_value <= ACPI_NOTIFY_MAX) {
return (acpi_gbl_notify_value_names[notify_value]);
} else if (notify_value <= ACPI_MAX_SYS_NOTIFY) {
return ("Reserved");
} else if (notify_value <= ACPI_MAX_DEVICE_SPECIFIC_NOTIFY) {
return ("Device Specific");
} else {
return ("Hardware Specific");
}
}
u8 acpi_ut_valid_object_type(acpi_object_type type)
{
if (type > ACPI_TYPE_LOCAL_MAX) {
return (FALSE);
}
return (TRUE);
}
