void acpi_db_set_scope(char *name)
{
acpi_status status;
struct acpi_namespace_node *node;
if (!name || name[0] == 0) {
acpi_os_printf("Current scope: %s\n", acpi_gbl_db_scope_buf);
return;
}
acpi_db_prep_namestring(name);
if (ACPI_IS_ROOT_PREFIX(name[0])) {
status = acpi_ns_get_node(acpi_gbl_root_node, name,
ACPI_NS_NO_UPSEARCH, &node);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
acpi_gbl_db_scope_buf[0] = 0;
} else {
status = acpi_ns_get_node(acpi_gbl_db_scope_node, name,
ACPI_NS_NO_UPSEARCH, &node);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
}
if (acpi_ut_safe_strcat
(acpi_gbl_db_scope_buf, sizeof(acpi_gbl_db_scope_buf), name)) {
status = AE_BUFFER_OVERFLOW;
goto error_exit;
}
if (acpi_ut_safe_strcat
(acpi_gbl_db_scope_buf, sizeof(acpi_gbl_db_scope_buf), "\\")) {
status = AE_BUFFER_OVERFLOW;
goto error_exit;
}
acpi_gbl_db_scope_node = node;
acpi_os_printf("New scope: %s\n", acpi_gbl_db_scope_buf);
return;
error_exit:
acpi_os_printf("Could not attach scope: %s, %s\n",
name, acpi_format_exception(status));
}
void acpi_db_dump_namespace(char *start_arg, char *depth_arg)
{
acpi_handle subtree_entry = acpi_gbl_root_node;
u32 max_depth = ACPI_UINT32_MAX;
if (start_arg) {
subtree_entry = acpi_db_convert_to_node(start_arg);
if (!subtree_entry) {
return;
}
if (depth_arg) {
max_depth = strtoul(depth_arg, NULL, 0);
}
}
acpi_db_set_output_destination(ACPI_DB_DUPLICATE_OUTPUT);
acpi_os_printf("ACPI Namespace (from %4.4s (%p) subtree):\n",
((struct acpi_namespace_node *)subtree_entry)->name.
ascii, subtree_entry);
acpi_db_set_output_destination(ACPI_DB_REDIRECTABLE_OUTPUT);
acpi_ns_dump_objects(ACPI_TYPE_ANY, ACPI_DISPLAY_SUMMARY, max_depth,
ACPI_OWNER_ID_MAX, subtree_entry);
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
}
void acpi_db_dump_namespace_paths(void)
{
acpi_db_set_output_destination(ACPI_DB_DUPLICATE_OUTPUT);
acpi_os_printf("ACPI Namespace (from root):\n");
acpi_db_set_output_destination(ACPI_DB_REDIRECTABLE_OUTPUT);
acpi_ns_dump_object_paths(ACPI_TYPE_ANY, ACPI_DISPLAY_SUMMARY,
ACPI_UINT32_MAX, ACPI_OWNER_ID_MAX,
acpi_gbl_root_node);
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
}
void acpi_db_dump_namespace_by_owner(char *owner_arg, char *depth_arg)
{
acpi_handle subtree_entry = acpi_gbl_root_node;
u32 max_depth = ACPI_UINT32_MAX;
acpi_owner_id owner_id;
owner_id = (acpi_owner_id) strtoul(owner_arg, NULL, 0);
if (depth_arg) {
max_depth = strtoul(depth_arg, NULL, 0);
}
acpi_db_set_output_destination(ACPI_DB_DUPLICATE_OUTPUT);
acpi_os_printf("ACPI Namespace by owner %X:\n", owner_id);
acpi_db_set_output_destination(ACPI_DB_REDIRECTABLE_OUTPUT);
acpi_ns_dump_objects(ACPI_TYPE_ANY, ACPI_DISPLAY_SUMMARY, max_depth,
owner_id, subtree_entry);
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
}
static acpi_status
acpi_db_walk_and_match_name(acpi_handle obj_handle,
u32 nesting_level,
void *context, void **return_value)
{
acpi_status status;
char *requested_name = (char *)context;
u32 i;
struct acpi_buffer buffer;
struct acpi_walk_info info;
for (i = 0; i < 4; i++) {
if ((requested_name[i] != '?') &&
(requested_name[i] != ((struct acpi_namespace_node *)
obj_handle)->name.ascii[i])) {
return (AE_OK);
}
}
buffer.length = ACPI_ALLOCATE_LOCAL_BUFFER;
status = acpi_ns_handle_to_pathname(obj_handle, &buffer, TRUE);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could Not get pathname for object %p\n",
obj_handle);
} else {
info.owner_id = ACPI_OWNER_ID_MAX;
info.debug_level = ACPI_UINT32_MAX;
info.display_type = ACPI_DISPLAY_SUMMARY | ACPI_DISPLAY_SHORT;
acpi_os_printf("%32s", (char *)buffer.pointer);
(void)acpi_ns_dump_one_object(obj_handle, nesting_level, &info,
NULL);
ACPI_FREE(buffer.pointer);
}
return (AE_OK);
}
acpi_status acpi_db_find_name_in_namespace(char *name_arg)
{
char acpi_name[5] = "____";
char *acpi_name_ptr = acpi_name;
if (strlen(name_arg) > ACPI_NAME_SIZE) {
acpi_os_printf("Name must be no longer than 4 characters\n");
return (AE_OK);
}
acpi_ut_strupr(name_arg);
while (*name_arg) {
*acpi_name_ptr = *name_arg;
acpi_name_ptr++;
name_arg++;
}
(void)acpi_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, acpi_db_walk_and_match_name,
NULL, acpi_name, NULL);
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
return (AE_OK);
}
static acpi_status
acpi_db_walk_for_predefined_names(acpi_handle obj_handle,
u32 nesting_level,
void *context, void **return_value)
{
struct acpi_namespace_node *node =
(struct acpi_namespace_node *)obj_handle;
u32 *count = (u32 *)context;
const union acpi_predefined_info *predefined;
const union acpi_predefined_info *package = NULL;
char *pathname;
char string_buffer[48];
predefined = acpi_ut_match_predefined_method(node->name.ascii);
if (!predefined) {
return (AE_OK);
}
pathname = acpi_ns_get_normalized_pathname(node, TRUE);
if (!pathname) {
return (AE_OK);
}
if (predefined->info.expected_btypes & ACPI_RTYPE_PACKAGE) {
package = predefined + 1;
}
acpi_ut_get_expected_return_types(string_buffer,
predefined->info.expected_btypes);
acpi_os_printf("%-32s Arguments %X, Return Types: %s", pathname,
METHOD_GET_ARG_COUNT(predefined->info.argument_list),
string_buffer);
if (package) {
acpi_os_printf(" (PkgType %2.2X, ObjType %2.2X, Count %2.2X)",
package->ret_info.type,
package->ret_info.object_type1,
package->ret_info.count1);
}
acpi_os_printf("\n");
acpi_ns_check_acpi_compliance(pathname, node, predefined);
ACPI_FREE(pathname);
(*count)++;
return (AE_OK);
}
void acpi_db_check_predefined_names(void)
{
u32 count = 0;
(void)acpi_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
acpi_db_walk_for_predefined_names, NULL,
(void *)&count, NULL);
acpi_os_printf("Found %u predefined names in the namespace\n", count);
}
static acpi_status
acpi_db_walk_for_object_counts(acpi_handle obj_handle,
u32 nesting_level,
void *context, void **return_value)
{
struct acpi_object_info *info = (struct acpi_object_info *)context;
struct acpi_namespace_node *node =
(struct acpi_namespace_node *)obj_handle;
if (node->type > ACPI_TYPE_NS_NODE_MAX) {
acpi_os_printf("[%4.4s]: Unknown object type %X\n",
node->name.ascii, node->type);
} else {
info->types[node->type]++;
}
return (AE_OK);
}
static acpi_status
acpi_db_walk_for_specific_objects(acpi_handle obj_handle,
u32 nesting_level,
void *context, void **return_value)
{
struct acpi_walk_info *info = (struct acpi_walk_info *)context;
struct acpi_buffer buffer;
acpi_status status;
info->count++;
buffer.length = ACPI_ALLOCATE_LOCAL_BUFFER;
status = acpi_ns_handle_to_pathname(obj_handle, &buffer, TRUE);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could Not get pathname for object %p\n",
obj_handle);
return (AE_OK);
}
acpi_os_printf("%32s", (char *)buffer.pointer);
ACPI_FREE(buffer.pointer);
(void)acpi_ns_dump_one_object(obj_handle, nesting_level, info, NULL);
return (AE_OK);
}
acpi_status acpi_db_display_objects(char *obj_type_arg, char *display_count_arg)
{
struct acpi_walk_info info;
acpi_object_type type;
struct acpi_object_info *object_info;
u32 i;
u32 total_objects = 0;
if (!obj_type_arg) {
object_info =
ACPI_ALLOCATE_ZEROED(sizeof(struct acpi_object_info));
(void)acpi_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
acpi_db_walk_for_object_counts, NULL,
(void *)object_info, NULL);
acpi_os_printf("\nSummary of namespace objects:\n\n");
for (i = 0; i < ACPI_TOTAL_TYPES; i++) {
acpi_os_printf("%8u %s\n", object_info->types[i],
acpi_ut_get_type_name(i));
total_objects += object_info->types[i];
}
acpi_os_printf("\n%8u Total namespace objects\n\n",
total_objects);
ACPI_FREE(object_info);
return (AE_OK);
}
type = acpi_db_match_argument(obj_type_arg, acpi_db_object_types);
if (type == ACPI_TYPE_NOT_FOUND) {
acpi_os_printf("Invalid or unsupported argument\n");
return (AE_OK);
}
acpi_db_set_output_destination(ACPI_DB_DUPLICATE_OUTPUT);
acpi_os_printf
("Objects of type [%s] defined in the current ACPI Namespace:\n",
acpi_ut_get_type_name(type));
acpi_db_set_output_destination(ACPI_DB_REDIRECTABLE_OUTPUT);
info.count = 0;
info.owner_id = ACPI_OWNER_ID_MAX;
info.debug_level = ACPI_UINT32_MAX;
info.display_type = ACPI_DISPLAY_SUMMARY | ACPI_DISPLAY_SHORT;
(void)acpi_walk_namespace(type, ACPI_ROOT_OBJECT, ACPI_UINT32_MAX,
acpi_db_walk_for_specific_objects, NULL,
(void *)&info, NULL);
acpi_os_printf
("\nFound %u objects of type [%s] in the current ACPI Namespace\n",
info.count, acpi_ut_get_type_name(type));
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
return (AE_OK);
}
static acpi_status
acpi_db_integrity_walk(acpi_handle obj_handle,
u32 nesting_level, void *context, void **return_value)
{
struct acpi_integrity_info *info =
(struct acpi_integrity_info *)context;
struct acpi_namespace_node *node =
(struct acpi_namespace_node *)obj_handle;
union acpi_operand_object *object;
u8 alias = TRUE;
info->nodes++;
while (alias) {
if (ACPI_GET_DESCRIPTOR_TYPE(node) != ACPI_DESC_TYPE_NAMED) {
acpi_os_printf
("Invalid Descriptor Type for Node %p [%s] - "
"is %2.2X should be %2.2X\n", node,
acpi_ut_get_descriptor_name(node),
ACPI_GET_DESCRIPTOR_TYPE(node),
ACPI_DESC_TYPE_NAMED);
return (AE_OK);
}
if ((node->type == ACPI_TYPE_LOCAL_ALIAS) ||
(node->type == ACPI_TYPE_LOCAL_METHOD_ALIAS)) {
node = (struct acpi_namespace_node *)node->object;
} else {
alias = FALSE;
}
}
if (node->type > ACPI_TYPE_LOCAL_MAX) {
acpi_os_printf("Invalid Object Type for Node %p, Type = %X\n",
node, node->type);
return (AE_OK);
}
if (!acpi_ut_valid_acpi_name(node->name.ascii)) {
acpi_os_printf("Invalid AcpiName for Node %p\n", node);
return (AE_OK);
}
object = acpi_ns_get_attached_object(node);
if (object) {
info->objects++;
if (ACPI_GET_DESCRIPTOR_TYPE(object) != ACPI_DESC_TYPE_OPERAND) {
acpi_os_printf
("Invalid Descriptor Type for Object %p [%s]\n",
object, acpi_ut_get_descriptor_name(object));
}
}
return (AE_OK);
}
void acpi_db_check_integrity(void)
{
struct acpi_integrity_info info = { 0, 0 };
(void)acpi_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, acpi_db_integrity_walk, NULL,
(void *)&info, NULL);
acpi_os_printf("Verified %u namespace nodes with %u Objects\n",
info.nodes, info.objects);
}
static acpi_status
acpi_db_walk_for_references(acpi_handle obj_handle,
u32 nesting_level,
void *context, void **return_value)
{
union acpi_operand_object *obj_desc =
(union acpi_operand_object *)context;
struct acpi_namespace_node *node =
(struct acpi_namespace_node *)obj_handle;
if (node == (void *)obj_desc) {
acpi_os_printf("Object is a Node [%4.4s]\n",
acpi_ut_get_node_name(node));
}
if (acpi_ns_get_attached_object(node) == obj_desc) {
acpi_os_printf("Reference at Node->Object %p [%4.4s]\n",
node, acpi_ut_get_node_name(node));
}
return (AE_OK);
}
void acpi_db_find_references(char *object_arg)
{
union acpi_operand_object *obj_desc;
acpi_size address;
address = strtoul(object_arg, NULL, 16);
obj_desc = ACPI_TO_POINTER(address);
(void)acpi_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, acpi_db_walk_for_references,
NULL, (void *)obj_desc, NULL);
}
static acpi_status
acpi_db_bus_walk(acpi_handle obj_handle,
u32 nesting_level, void *context, void **return_value)
{
struct acpi_namespace_node *node =
(struct acpi_namespace_node *)obj_handle;
acpi_status status;
struct acpi_buffer buffer;
struct acpi_namespace_node *temp_node;
struct acpi_device_info *info;
u32 i;
if ((node->type != ACPI_TYPE_DEVICE) &&
(node->type != ACPI_TYPE_PROCESSOR)) {
return (AE_OK);
}
status = acpi_get_handle(node, METHOD_NAME__PRT,
ACPI_CAST_PTR(acpi_handle, &temp_node));
if (ACPI_FAILURE(status)) {
return (AE_OK);
}
buffer.length = ACPI_ALLOCATE_LOCAL_BUFFER;
status = acpi_ns_handle_to_pathname(obj_handle, &buffer, TRUE);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could Not get pathname for object %p\n",
obj_handle);
return (AE_OK);
}
status = acpi_get_object_info(obj_handle, &info);
if (ACPI_FAILURE(status)) {
return (AE_OK);
}
acpi_os_printf("%-32s Type %X", (char *)buffer.pointer, node->type);
ACPI_FREE(buffer.pointer);
if (info->flags & ACPI_PCI_ROOT_BRIDGE) {
acpi_os_printf(" - Is PCI Root Bridge");
}
acpi_os_printf("\n");
acpi_os_printf("_PRT: %p\n", temp_node);
if (info->valid & ACPI_VALID_ADR) {
acpi_os_printf("_ADR: %8.8X%8.8X\n",
ACPI_FORMAT_UINT64(info->address));
} else {
acpi_os_printf("_ADR: <Not Present>\n");
}
if (info->valid & ACPI_VALID_HID) {
acpi_os_printf("_HID: %s\n", info->hardware_id.string);
} else {
acpi_os_printf("_HID: <Not Present>\n");
}
if (info->valid & ACPI_VALID_UID) {
acpi_os_printf("_UID: %s\n", info->unique_id.string);
} else {
acpi_os_printf("_UID: <Not Present>\n");
}
if (info->valid & ACPI_VALID_CID) {
for (i = 0; i < info->compatible_id_list.count; i++) {
acpi_os_printf("_CID: %s\n",
info->compatible_id_list.ids[i].string);
}
} else {
acpi_os_printf("_CID: <Not Present>\n");
}
ACPI_FREE(info);
return (AE_OK);
}
void acpi_db_get_bus_info(void)
{
(void)acpi_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, acpi_db_bus_walk, NULL, NULL,
NULL);
}
