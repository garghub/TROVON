struct acpi_namespace_node *acpi_db_convert_to_node(char *in_string)
{
struct acpi_namespace_node *node;
acpi_size address;
if ((*in_string >= 0x30) && (*in_string <= 0x39)) {
address = strtoul(in_string, NULL, 16);
node = ACPI_TO_POINTER(address);
if (!acpi_os_readable(node, sizeof(struct acpi_namespace_node))) {
acpi_os_printf("Address %p is invalid", node);
return (NULL);
}
if (ACPI_GET_DESCRIPTOR_TYPE(node) != ACPI_DESC_TYPE_NAMED) {
acpi_os_printf
("Address %p is not a valid namespace node [%s]\n",
node, acpi_ut_get_descriptor_name(node));
return (NULL);
}
} else {
node = acpi_db_local_ns_lookup(in_string);
if (!node) {
acpi_os_printf
("Could not find [%s] in namespace, defaulting to root node\n",
in_string);
node = acpi_gbl_root_node;
}
}
return (node);
}
acpi_status acpi_db_sleep(char *object_arg)
{
u8 sleep_state;
u32 i;
ACPI_FUNCTION_TRACE(acpi_db_sleep);
if (!object_arg) {
acpi_os_printf("Invoking all possible sleep states, 0-%d\n",
ACPI_S_STATES_MAX);
for (i = 0; i <= ACPI_S_STATES_MAX; i++) {
acpi_db_do_one_sleep_state((u8)i);
}
return_ACPI_STATUS(AE_OK);
}
sleep_state = (u8)strtoul(object_arg, NULL, 0);
acpi_db_do_one_sleep_state(sleep_state);
return_ACPI_STATUS(AE_OK);
}
static void acpi_db_do_one_sleep_state(u8 sleep_state)
{
acpi_status status;
u8 sleep_type_a;
u8 sleep_type_b;
if (sleep_state > ACPI_S_STATES_MAX) {
acpi_os_printf("Sleep state %d out of range (%d max)\n",
sleep_state, ACPI_S_STATES_MAX);
return;
}
acpi_os_printf("\n---- Invoking sleep state S%d (%s):\n",
sleep_state, acpi_gbl_sleep_state_names[sleep_state]);
status =
acpi_get_sleep_type_data(sleep_state, &sleep_type_a, &sleep_type_b);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not evaluate [%s] method, %s\n",
acpi_gbl_sleep_state_names[sleep_state],
acpi_format_exception(status));
return;
}
acpi_os_printf
("Register values for sleep state S%d: Sleep-A: %.2X, Sleep-B: %.2X\n",
sleep_state, sleep_type_a, sleep_type_b);
acpi_os_printf("**** Sleep: Prepare to sleep (S%d) ****\n",
sleep_state);
status = acpi_enter_sleep_state_prep(sleep_state);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
acpi_os_printf("**** Sleep: Going to sleep (S%d) ****\n", sleep_state);
status = acpi_enter_sleep_state(sleep_state);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
acpi_os_printf("**** Wake: Prepare to return from sleep (S%d) ****\n",
sleep_state);
status = acpi_leave_sleep_state_prep(sleep_state);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
acpi_os_printf("**** Wake: Return from sleep (S%d) ****\n",
sleep_state);
status = acpi_leave_sleep_state(sleep_state);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
return;
error_exit:
ACPI_EXCEPTION((AE_INFO, status, "During invocation of sleep state S%d",
sleep_state));
}
void acpi_db_display_locks(void)
{
u32 i;
for (i = 0; i < ACPI_MAX_MUTEX; i++) {
acpi_os_printf("%26s : %s\n", acpi_ut_get_mutex_name(i),
acpi_gbl_mutex_info[i].thread_id ==
ACPI_MUTEX_NOT_ACQUIRED ? "Locked" : "Unlocked");
}
}
void acpi_db_display_table_info(char *table_arg)
{
u32 i;
struct acpi_table_desc *table_desc;
acpi_status status;
acpi_os_printf("Idx ID Status Type "
"TableHeader (Sig, Address, Length, Misc)\n");
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; i++) {
table_desc = &acpi_gbl_root_table_list.tables[i];
acpi_os_printf("%3u %.2u ", i, table_desc->owner_id);
if (!(table_desc->flags & ACPI_TABLE_IS_LOADED)) {
acpi_os_printf("NotLoaded ");
} else {
acpi_os_printf(" Loaded ");
}
switch (table_desc->flags & ACPI_TABLE_ORIGIN_MASK) {
case ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL:
acpi_os_printf("External/virtual ");
break;
case ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL:
acpi_os_printf("Internal/physical ");
break;
case ACPI_TABLE_ORIGIN_INTERNAL_VIRTUAL:
acpi_os_printf("Internal/virtual ");
break;
default:
acpi_os_printf("INVALID TYPE ");
break;
}
status = acpi_tb_validate_table(table_desc);
if (ACPI_FAILURE(status)) {
return;
}
if (table_desc->pointer) {
acpi_tb_print_table_header(table_desc->address,
table_desc->pointer);
} else {
ACPI_INFO((AE_INFO, "%4.4s - Table has been unloaded",
table_desc->signature.ascii));
}
}
}
void acpi_db_unload_acpi_table(char *object_name)
{
struct acpi_namespace_node *node;
acpi_status status;
node = acpi_db_convert_to_node(object_name);
if (!node) {
return;
}
status = acpi_unload_parent_table(ACPI_CAST_PTR(acpi_handle, node));
if (ACPI_SUCCESS(status)) {
acpi_os_printf("Parent of [%s] (%p) unloaded and uninstalled\n",
object_name, node);
} else {
acpi_os_printf("%s, while unloading parent table of [%s]\n",
acpi_format_exception(status), object_name);
}
}
void acpi_db_send_notify(char *name, u32 value)
{
struct acpi_namespace_node *node;
acpi_status status;
node = acpi_db_convert_to_node(name);
if (!node) {
return;
}
if (acpi_ev_is_notify_object(node)) {
status = acpi_ev_queue_notify_request(node, value);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not queue notify\n");
}
} else {
acpi_os_printf("Named object [%4.4s] Type %s, "
"must be Device/Thermal/Processor type\n",
acpi_ut_get_node_name(node),
acpi_ut_get_type_name(node->type));
}
}
void acpi_db_display_interfaces(char *action_arg, char *interface_name_arg)
{
struct acpi_interface_info *next_interface;
char *sub_string;
acpi_status status;
if (!action_arg) {
(void)acpi_os_acquire_mutex(acpi_gbl_osi_mutex,
ACPI_WAIT_FOREVER);
next_interface = acpi_gbl_supported_interfaces;
while (next_interface) {
if (!(next_interface->flags & ACPI_OSI_INVALID)) {
acpi_os_printf("%s\n", next_interface->name);
}
next_interface = next_interface->next;
}
acpi_os_release_mutex(acpi_gbl_osi_mutex);
return;
}
if (!interface_name_arg) {
acpi_os_printf("Missing Interface Name argument\n");
return;
}
acpi_ut_strupr(action_arg);
sub_string = strstr("INSTALL", action_arg);
if (sub_string) {
status = acpi_install_interface(interface_name_arg);
if (ACPI_FAILURE(status)) {
acpi_os_printf("%s, while installing \"%s\"\n",
acpi_format_exception(status),
interface_name_arg);
}
return;
}
sub_string = strstr("REMOVE", action_arg);
if (sub_string) {
status = acpi_remove_interface(interface_name_arg);
if (ACPI_FAILURE(status)) {
acpi_os_printf("%s, while removing \"%s\"\n",
acpi_format_exception(status),
interface_name_arg);
}
return;
}
acpi_os_printf("Invalid action argument: %s\n", action_arg);
return;
}
void acpi_db_display_template(char *buffer_arg)
{
struct acpi_namespace_node *node;
acpi_status status;
struct acpi_buffer return_buffer;
node = acpi_db_convert_to_node(buffer_arg);
if (!node || (node == acpi_gbl_root_node)) {
acpi_os_printf("Invalid argument: %s\n", buffer_arg);
return;
}
if (node->type != ACPI_TYPE_BUFFER) {
acpi_os_printf
("Not a Buffer object, cannot be a template: %s\n",
buffer_arg);
return;
}
return_buffer.length = ACPI_DEBUG_BUFFER_SIZE;
return_buffer.pointer = acpi_gbl_db_buffer;
status = acpi_rs_create_resource_list(node->object, &return_buffer);
acpi_db_set_output_destination(ACPI_DB_REDIRECTABLE_OUTPUT);
acpi_dbg_level |= ACPI_LV_RESOURCES;
if (ACPI_FAILURE(status)) {
acpi_os_printf
("Could not convert Buffer to a resource list: %s, %s\n",
buffer_arg, acpi_format_exception(status));
goto dump_buffer;
}
acpi_rs_dump_resource_list(ACPI_CAST_PTR(struct acpi_resource,
return_buffer.pointer));
dump_buffer:
acpi_os_printf("\nRaw data buffer:\n");
acpi_ut_debug_dump_buffer((u8 *)node->object->buffer.pointer,
node->object->buffer.length,
DB_BYTE_DISPLAY, ACPI_UINT32_MAX);
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
return;
}
static void
acpi_dm_compare_aml_resources(u8 *aml1_buffer,
acpi_rsdesc_size aml1_buffer_length,
u8 *aml2_buffer,
acpi_rsdesc_size aml2_buffer_length)
{
u8 *aml1;
u8 *aml2;
u8 *aml1_end;
u8 *aml2_end;
acpi_rsdesc_size aml1_length;
acpi_rsdesc_size aml2_length;
acpi_rsdesc_size offset = 0;
u8 resource_type;
u32 count = 0;
u32 i;
if (aml1_buffer_length != aml2_buffer_length) {
acpi_os_printf("**** Buffer length mismatch in converted "
"AML: Original %X, New %X ****\n",
aml1_buffer_length, aml2_buffer_length);
}
aml1 = aml1_buffer;
aml2 = aml2_buffer;
aml1_end = aml1_buffer + aml1_buffer_length;
aml2_end = aml2_buffer + aml2_buffer_length;
while ((aml1 < aml1_end) && (aml2 < aml2_end)) {
aml1_length = acpi_ut_get_descriptor_length(aml1);
aml2_length = acpi_ut_get_descriptor_length(aml2);
resource_type = acpi_ut_get_resource_type(aml1);
if (aml1_length != aml2_length) {
acpi_os_printf
("**** Length mismatch in descriptor [%.2X] type %2.2X, "
"Offset %8.8X Len1 %X, Len2 %X ****\n", count,
resource_type, offset, aml1_length, aml2_length);
}
else if (memcmp(aml1, aml2, aml1_length)) {
acpi_os_printf
("**** Data mismatch in descriptor [%.2X] type %2.2X, "
"Offset %8.8X ****\n", count, resource_type,
offset);
for (i = 0; i < aml1_length; i++) {
if (aml1[i] != aml2[i]) {
acpi_os_printf
("Mismatch at byte offset %.2X: is %2.2X, "
"should be %2.2X\n", i, aml2[i],
aml1[i]);
}
}
}
if (resource_type == ACPI_RESOURCE_NAME_END_TAG) {
return;
}
count++;
offset += aml1_length;
aml1 += aml1_length;
aml2 += aml2_length;
}
}
static acpi_status
acpi_dm_test_resource_conversion(struct acpi_namespace_node *node, char *name)
{
acpi_status status;
struct acpi_buffer return_buffer;
struct acpi_buffer resource_buffer;
struct acpi_buffer new_aml;
union acpi_object *original_aml;
acpi_os_printf("Resource Conversion Comparison:\n");
new_aml.length = ACPI_ALLOCATE_LOCAL_BUFFER;
return_buffer.length = ACPI_ALLOCATE_LOCAL_BUFFER;
resource_buffer.length = ACPI_ALLOCATE_LOCAL_BUFFER;
status = acpi_evaluate_object(node, name, NULL, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not obtain %s: %s\n",
name, acpi_format_exception(status));
return (status);
}
status = acpi_get_current_resources(node, &resource_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("AcpiGetCurrentResources failed: %s\n",
acpi_format_exception(status));
goto exit1;
}
status = acpi_rs_create_aml_resources(&resource_buffer, &new_aml);
if (ACPI_FAILURE(status)) {
acpi_os_printf("AcpiRsCreateAmlResources failed: %s\n",
acpi_format_exception(status));
goto exit2;
}
original_aml = return_buffer.pointer;
acpi_dm_compare_aml_resources(original_aml->buffer.pointer,
(acpi_rsdesc_size) original_aml->buffer.
length, new_aml.pointer,
(acpi_rsdesc_size) new_aml.length);
ACPI_FREE(new_aml.pointer);
exit2:
ACPI_FREE(resource_buffer.pointer);
exit1:
ACPI_FREE(return_buffer.pointer);
return (status);
}
static acpi_status
acpi_db_resource_callback(struct acpi_resource *resource, void *context)
{
return (AE_OK);
}
static acpi_status
acpi_db_device_resources(acpi_handle obj_handle,
u32 nesting_level, void *context, void **return_value)
{
struct acpi_namespace_node *node;
struct acpi_namespace_node *prt_node = NULL;
struct acpi_namespace_node *crs_node = NULL;
struct acpi_namespace_node *prs_node = NULL;
struct acpi_namespace_node *aei_node = NULL;
char *parent_path;
struct acpi_buffer return_buffer;
acpi_status status;
node = ACPI_CAST_PTR(struct acpi_namespace_node, obj_handle);
parent_path = acpi_ns_get_normalized_pathname(node, TRUE);
if (!parent_path) {
return (AE_NO_MEMORY);
}
(void)acpi_get_handle(node, METHOD_NAME__PRT,
ACPI_CAST_PTR(acpi_handle, &prt_node));
(void)acpi_get_handle(node, METHOD_NAME__CRS,
ACPI_CAST_PTR(acpi_handle, &crs_node));
(void)acpi_get_handle(node, METHOD_NAME__PRS,
ACPI_CAST_PTR(acpi_handle, &prs_node));
(void)acpi_get_handle(node, METHOD_NAME__AEI,
ACPI_CAST_PTR(acpi_handle, &aei_node));
if (!prt_node && !crs_node && !prs_node && !aei_node) {
goto cleanup;
}
acpi_os_printf("\nDevice: %s\n", parent_path);
return_buffer.pointer = acpi_gbl_db_buffer;
return_buffer.length = ACPI_DEBUG_BUFFER_SIZE;
if (prt_node) {
acpi_os_printf("Evaluating _PRT\n");
status =
acpi_evaluate_object(prt_node, NULL, NULL, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not evaluate _PRT: %s\n",
acpi_format_exception(status));
goto get_crs;
}
return_buffer.pointer = acpi_gbl_db_buffer;
return_buffer.length = ACPI_DEBUG_BUFFER_SIZE;
status = acpi_get_irq_routing_table(node, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("GetIrqRoutingTable failed: %s\n",
acpi_format_exception(status));
goto get_crs;
}
acpi_rs_dump_irq_list(ACPI_CAST_PTR(u8, acpi_gbl_db_buffer));
}
get_crs:
if (crs_node) {
acpi_os_printf("Evaluating _CRS\n");
return_buffer.pointer = acpi_gbl_db_buffer;
return_buffer.length = ACPI_DEBUG_BUFFER_SIZE;
status =
acpi_evaluate_object(crs_node, NULL, NULL, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not evaluate _CRS: %s\n",
acpi_format_exception(status));
goto get_prs;
}
status = acpi_walk_resources(node, METHOD_NAME__CRS,
acpi_db_resource_callback, NULL);
if (ACPI_FAILURE(status)) {
acpi_os_printf("AcpiWalkResources failed: %s\n",
acpi_format_exception(status));
goto get_prs;
}
return_buffer.pointer = NULL;
return_buffer.length = ACPI_ALLOCATE_LOCAL_BUFFER;
status = acpi_get_current_resources(node, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("AcpiGetCurrentResources failed: %s\n",
acpi_format_exception(status));
goto get_prs;
}
status = acpi_walk_resource_buffer(&return_buffer,
acpi_db_resource_callback,
NULL);
if (ACPI_FAILURE(status)) {
acpi_os_printf("AcpiWalkResourceBuffer failed: %s\n",
acpi_format_exception(status));
goto end_crs;
}
acpi_rs_dump_resource_list(ACPI_CAST_PTR(struct acpi_resource,
return_buffer.
pointer));
(void)acpi_dm_test_resource_conversion(node, METHOD_NAME__CRS);
acpi_os_printf("Evaluating _SRS\n");
status = acpi_set_current_resources(node, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("AcpiSetCurrentResources failed: %s\n",
acpi_format_exception(status));
goto end_crs;
}
end_crs:
ACPI_FREE(return_buffer.pointer);
}
get_prs:
if (prs_node) {
acpi_os_printf("Evaluating _PRS\n");
return_buffer.pointer = acpi_gbl_db_buffer;
return_buffer.length = ACPI_DEBUG_BUFFER_SIZE;
status =
acpi_evaluate_object(prs_node, NULL, NULL, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not evaluate _PRS: %s\n",
acpi_format_exception(status));
goto get_aei;
}
return_buffer.pointer = acpi_gbl_db_buffer;
return_buffer.length = ACPI_DEBUG_BUFFER_SIZE;
status = acpi_get_possible_resources(node, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("AcpiGetPossibleResources failed: %s\n",
acpi_format_exception(status));
goto get_aei;
}
acpi_rs_dump_resource_list(ACPI_CAST_PTR
(struct acpi_resource,
acpi_gbl_db_buffer));
}
get_aei:
if (aei_node) {
acpi_os_printf("Evaluating _AEI\n");
return_buffer.pointer = acpi_gbl_db_buffer;
return_buffer.length = ACPI_DEBUG_BUFFER_SIZE;
status =
acpi_evaluate_object(aei_node, NULL, NULL, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not evaluate _AEI: %s\n",
acpi_format_exception(status));
goto cleanup;
}
return_buffer.pointer = acpi_gbl_db_buffer;
return_buffer.length = ACPI_DEBUG_BUFFER_SIZE;
status = acpi_get_event_resources(node, &return_buffer);
if (ACPI_FAILURE(status)) {
acpi_os_printf("AcpiGetEventResources failed: %s\n",
acpi_format_exception(status));
goto cleanup;
}
acpi_rs_dump_resource_list(ACPI_CAST_PTR
(struct acpi_resource,
acpi_gbl_db_buffer));
}
cleanup:
ACPI_FREE(parent_path);
return (AE_OK);
}
void acpi_db_display_resources(char *object_arg)
{
struct acpi_namespace_node *node;
acpi_db_set_output_destination(ACPI_DB_REDIRECTABLE_OUTPUT);
acpi_dbg_level |= ACPI_LV_RESOURCES;
if (!object_arg || (!strcmp(object_arg, "*"))) {
(void)acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
acpi_db_device_resources, NULL, NULL,
NULL);
} else {
node = acpi_db_convert_to_node(object_arg);
if (node) {
if (node->type != ACPI_TYPE_DEVICE) {
acpi_os_printf
("%4.4s: Name is not a device object (%s)\n",
node->name.ascii,
acpi_ut_get_type_name(node->type));
} else {
(void)acpi_db_device_resources(node, 0, NULL,
NULL);
}
}
}
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
}
void acpi_db_generate_gpe(char *gpe_arg, char *block_arg)
{
u32 block_number = 0;
u32 gpe_number;
struct acpi_gpe_event_info *gpe_event_info;
gpe_number = strtoul(gpe_arg, NULL, 0);
if (block_arg) {
block_number = strtoul(block_arg, NULL, 0);
if (block_number == 1) {
block_number = 0;
}
}
gpe_event_info =
acpi_ev_get_gpe_event_info(ACPI_TO_POINTER(block_number),
gpe_number);
if (!gpe_event_info) {
acpi_os_printf("Invalid GPE\n");
return;
}
(void)acpi_ev_gpe_dispatch(NULL, gpe_event_info, gpe_number);
}
void acpi_db_generate_sci(void)
{
acpi_ev_sci_dispatch();
}
void acpi_db_trace(char *enable_arg, char *method_arg, char *once_arg)
{
u32 debug_level = 0;
u32 debug_layer = 0;
u32 flags = 0;
acpi_ut_strupr(enable_arg);
acpi_ut_strupr(once_arg);
if (method_arg) {
if (acpi_db_trace_method_name) {
ACPI_FREE(acpi_db_trace_method_name);
acpi_db_trace_method_name = NULL;
}
acpi_db_trace_method_name =
ACPI_ALLOCATE(strlen(method_arg) + 1);
if (!acpi_db_trace_method_name) {
acpi_os_printf("Failed to allocate method name (%s)\n",
method_arg);
return;
}
strcpy(acpi_db_trace_method_name, method_arg);
}
if (!strcmp(enable_arg, "ENABLE") ||
!strcmp(enable_arg, "METHOD") || !strcmp(enable_arg, "OPCODE")) {
if (!strcmp(enable_arg, "ENABLE")) {
debug_level = acpi_gbl_db_console_debug_level;
debug_layer = acpi_dbg_layer;
} else {
debug_level = ACPI_LV_TRACE_POINT;
debug_layer = ACPI_EXECUTER;
}
flags = ACPI_TRACE_ENABLED;
if (!strcmp(enable_arg, "OPCODE")) {
flags |= ACPI_TRACE_OPCODE;
}
if (once_arg && !strcmp(once_arg, "ONCE")) {
flags |= ACPI_TRACE_ONESHOT;
}
}
(void)acpi_debug_trace(acpi_db_trace_method_name,
debug_level, debug_layer, flags);
}
