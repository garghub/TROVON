void acpi_db_delete_objects(u32 count, union acpi_object *objects)
{
u32 i;
for (i = 0; i < count; i++) {
switch (objects[i].type) {
case ACPI_TYPE_BUFFER:
ACPI_FREE(objects[i].buffer.pointer);
break;
case ACPI_TYPE_PACKAGE:
acpi_db_delete_objects(objects[i].package.count,
objects[i].package.elements);
ACPI_FREE(objects[i].package.elements);
break;
default:
break;
}
}
}
static acpi_status
acpi_db_execute_method(struct acpi_db_method_info *info,
struct acpi_buffer *return_obj)
{
acpi_status status;
struct acpi_object_list param_objects;
union acpi_object params[ACPI_DEBUGGER_MAX_ARGS + 1];
u32 i;
ACPI_FUNCTION_TRACE(db_execute_method);
if (acpi_gbl_db_output_to_file && !acpi_dbg_level) {
acpi_os_printf("Warning: debug output is not enabled!\n");
}
param_objects.count = 0;
param_objects.pointer = NULL;
if (info->args && info->args[0]) {
for (i = 0; (info->args[i] && *(info->args[i])); i++) {
status = acpi_db_convert_to_object(info->types[i],
info->args[i],
&params[i]);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"While parsing method arguments"));
goto cleanup;
}
}
param_objects.count = i;
param_objects.pointer = params;
}
return_obj->pointer = acpi_gbl_db_buffer;
return_obj->length = ACPI_DEBUG_BUFFER_SIZE;
acpi_gbl_method_executing = TRUE;
status = acpi_evaluate_object(NULL, info->pathname,
&param_objects, return_obj);
acpi_gbl_cm_single_step = FALSE;
acpi_gbl_method_executing = FALSE;
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"while executing %s from debugger",
info->pathname));
if (status == AE_BUFFER_OVERFLOW) {
ACPI_ERROR((AE_INFO,
"Possible overflow of internal debugger "
"buffer (size 0x%X needed 0x%X)",
ACPI_DEBUG_BUFFER_SIZE,
(u32)return_obj->length));
}
}
cleanup:
acpi_db_delete_objects(param_objects.count, params);
return_ACPI_STATUS(status);
}
static acpi_status acpi_db_execute_setup(struct acpi_db_method_info *info)
{
acpi_status status;
ACPI_FUNCTION_NAME(db_execute_setup);
info->pathname[0] = 0;
if ((info->name[0] != '\\') && (info->name[0] != '/')) {
if (acpi_ut_safe_strcat(info->pathname, sizeof(info->pathname),
acpi_gbl_db_scope_buf)) {
status = AE_BUFFER_OVERFLOW;
goto error_exit;
}
}
if (acpi_ut_safe_strcat(info->pathname, sizeof(info->pathname),
info->name)) {
status = AE_BUFFER_OVERFLOW;
goto error_exit;
}
acpi_db_prep_namestring(info->pathname);
acpi_db_set_output_destination(ACPI_DB_DUPLICATE_OUTPUT);
acpi_os_printf("Evaluating %s\n", info->pathname);
if (info->flags & EX_SINGLE_STEP) {
acpi_gbl_cm_single_step = TRUE;
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
}
else {
acpi_db_set_output_destination(ACPI_DB_REDIRECTABLE_OUTPUT);
}
return (AE_OK);
error_exit:
ACPI_EXCEPTION((AE_INFO, status, "During setup for method execution"));
return (status);
}
u32 acpi_db_get_cache_info(struct acpi_memory_list *cache)
{
return (cache->total_allocated - cache->total_freed -
cache->current_depth);
}
static u32 acpi_db_get_outstanding_allocations(void)
{
u32 outstanding = 0;
#ifdef ACPI_DBG_TRACK_ALLOCATIONS
outstanding += acpi_db_get_cache_info(acpi_gbl_state_cache);
outstanding += acpi_db_get_cache_info(acpi_gbl_ps_node_cache);
outstanding += acpi_db_get_cache_info(acpi_gbl_ps_node_ext_cache);
outstanding += acpi_db_get_cache_info(acpi_gbl_operand_cache);
#endif
return (outstanding);
}
static acpi_status
acpi_db_execution_walk(acpi_handle obj_handle,
u32 nesting_level, void *context, void **return_value)
{
union acpi_operand_object *obj_desc;
struct acpi_namespace_node *node =
(struct acpi_namespace_node *)obj_handle;
struct acpi_buffer return_obj;
acpi_status status;
obj_desc = acpi_ns_get_attached_object(node);
if (obj_desc->method.param_count) {
return (AE_OK);
}
return_obj.pointer = NULL;
return_obj.length = ACPI_ALLOCATE_BUFFER;
acpi_ns_print_node_pathname(node, "Evaluating");
acpi_os_printf("\n");
acpi_gbl_method_executing = TRUE;
status = acpi_evaluate_object(node, NULL, NULL, &return_obj);
acpi_os_printf("Evaluation of [%4.4s] returned %s\n",
acpi_ut_get_node_name(node),
acpi_format_exception(status));
acpi_gbl_method_executing = FALSE;
return (AE_OK);
}
void
acpi_db_execute(char *name, char **args, acpi_object_type *types, u32 flags)
{
acpi_status status;
struct acpi_buffer return_obj;
char *name_string;
#ifdef ACPI_DEBUG_OUTPUT
u32 previous_allocations;
u32 allocations;
#endif
if (acpi_gbl_method_executing) {
acpi_os_printf("Only one debugger execution is allowed.\n");
return;
}
#ifdef ACPI_DEBUG_OUTPUT
previous_allocations = acpi_db_get_outstanding_allocations();
#endif
if (*name == '*') {
(void)acpi_walk_namespace(ACPI_TYPE_METHOD, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
acpi_db_execution_walk, NULL, NULL,
NULL);
return;
}
name_string = ACPI_ALLOCATE(strlen(name) + 1);
if (!name_string) {
return;
}
memset(&acpi_gbl_db_method_info, 0, sizeof(struct acpi_db_method_info));
strcpy(name_string, name);
acpi_ut_strupr(name_string);
if (!strncmp(name_string, "PREDEF", 6)) {
acpi_db_evaluate_predefined_names();
ACPI_FREE(name_string);
return;
}
acpi_gbl_db_method_info.name = name_string;
acpi_gbl_db_method_info.args = args;
acpi_gbl_db_method_info.types = types;
acpi_gbl_db_method_info.flags = flags;
return_obj.pointer = NULL;
return_obj.length = ACPI_ALLOCATE_BUFFER;
status = acpi_db_execute_setup(&acpi_gbl_db_method_info);
if (ACPI_FAILURE(status)) {
ACPI_FREE(name_string);
return;
}
status = acpi_get_handle(NULL, acpi_gbl_db_method_info.pathname,
&acpi_gbl_db_method_info.method);
if (ACPI_SUCCESS(status)) {
status = acpi_db_execute_method(&acpi_gbl_db_method_info,
&return_obj);
}
ACPI_FREE(name_string);
acpi_os_sleep((u64)10);
#ifdef ACPI_DEBUG_OUTPUT
allocations =
acpi_db_get_outstanding_allocations() - previous_allocations;
acpi_db_set_output_destination(ACPI_DB_DUPLICATE_OUTPUT);
if (allocations > 0) {
acpi_os_printf
("0x%X Outstanding allocations after evaluation of %s\n",
allocations, acpi_gbl_db_method_info.pathname);
}
#endif
if (ACPI_FAILURE(status)) {
acpi_os_printf("Evaluation of %s failed with status %s\n",
acpi_gbl_db_method_info.pathname,
acpi_format_exception(status));
} else {
if (return_obj.length) {
acpi_os_printf("Evaluation of %s returned object %p, "
"external buffer length %X\n",
acpi_gbl_db_method_info.pathname,
return_obj.pointer,
(u32)return_obj.length);
acpi_db_dump_external_object(return_obj.pointer, 1);
if (ACPI_COMPARE_NAME
((ACPI_CAST_PTR
(struct acpi_namespace_node,
acpi_gbl_db_method_info.method)->name.ascii),
METHOD_NAME__PLD)) {
acpi_db_dump_pld_buffer(return_obj.pointer);
}
} else {
acpi_os_printf
("No object was returned from evaluation of %s\n",
acpi_gbl_db_method_info.pathname);
}
}
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
}
static void ACPI_SYSTEM_XFACE acpi_db_method_thread(void *context)
{
acpi_status status;
struct acpi_db_method_info *info = context;
struct acpi_db_method_info local_info;
u32 i;
u8 allow;
struct acpi_buffer return_obj;
(void)acpi_os_wait_semaphore(info->info_gate, 1, ACPI_WAIT_FOREVER);
if (info->init_args) {
acpi_db_uint32_to_hex_string(info->num_created,
info->index_of_thread_str);
acpi_db_uint32_to_hex_string((u32)acpi_os_get_thread_id(),
info->id_of_thread_str);
}
if (info->threads && (info->num_created < info->num_threads)) {
info->threads[info->num_created++] = acpi_os_get_thread_id();
}
local_info = *info;
local_info.args = local_info.arguments;
local_info.arguments[0] = local_info.num_threads_str;
local_info.arguments[1] = local_info.id_of_thread_str;
local_info.arguments[2] = local_info.index_of_thread_str;
local_info.arguments[3] = NULL;
local_info.types = local_info.arg_types;
(void)acpi_os_signal_semaphore(info->info_gate, 1);
for (i = 0; i < info->num_loops; i++) {
status = acpi_db_execute_method(&local_info, &return_obj);
if (ACPI_FAILURE(status)) {
acpi_os_printf
("%s During evaluation of %s at iteration %X\n",
acpi_format_exception(status), info->pathname, i);
if (status == AE_ABORT_METHOD) {
break;
}
}
#if 0
if ((i % 100) == 0) {
acpi_os_printf("%u loops, Thread 0x%x\n",
i, acpi_os_get_thread_id());
}
if (return_obj.length) {
acpi_os_printf
("Evaluation of %s returned object %p Buflen %X\n",
info->pathname, return_obj.pointer,
(u32)return_obj.length);
acpi_db_dump_external_object(return_obj.pointer, 1);
}
#endif
}
allow = 0;
(void)acpi_os_wait_semaphore(info->thread_complete_gate,
1, ACPI_WAIT_FOREVER);
info->num_completed++;
if (info->num_completed == info->num_threads) {
allow = 1;
}
(void)acpi_os_signal_semaphore(info->thread_complete_gate, 1);
if (allow) {
status = acpi_os_signal_semaphore(info->main_thread_gate, 1);
if (ACPI_FAILURE(status)) {
acpi_os_printf
("Could not signal debugger thread sync semaphore, %s\n",
acpi_format_exception(status));
}
}
}
void
acpi_db_create_execution_threads(char *num_threads_arg,
char *num_loops_arg, char *method_name_arg)
{
acpi_status status;
u32 num_threads;
u32 num_loops;
u32 i;
u32 size;
acpi_mutex main_thread_gate;
acpi_mutex thread_complete_gate;
acpi_mutex info_gate;
num_threads = strtoul(num_threads_arg, NULL, 0);
num_loops = strtoul(num_loops_arg, NULL, 0);
if (!num_threads || !num_loops) {
acpi_os_printf("Bad argument: Threads %X, Loops %X\n",
num_threads, num_loops);
return;
}
status = acpi_os_create_semaphore(1, 0, &main_thread_gate);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not create semaphore for "
"synchronization with the main thread, %s\n",
acpi_format_exception(status));
return;
}
status = acpi_os_create_semaphore(1, 1, &thread_complete_gate);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not create semaphore for "
"synchronization between the created threads, %s\n",
acpi_format_exception(status));
(void)acpi_os_delete_semaphore(main_thread_gate);
return;
}
status = acpi_os_create_semaphore(1, 1, &info_gate);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not create semaphore for "
"synchronization of AcpiGbl_DbMethodInfo, %s\n",
acpi_format_exception(status));
(void)acpi_os_delete_semaphore(thread_complete_gate);
(void)acpi_os_delete_semaphore(main_thread_gate);
return;
}
memset(&acpi_gbl_db_method_info, 0, sizeof(struct acpi_db_method_info));
acpi_gbl_db_method_info.num_threads = num_threads;
size = sizeof(acpi_thread_id) * acpi_gbl_db_method_info.num_threads;
acpi_gbl_db_method_info.threads = acpi_os_allocate(size);
if (acpi_gbl_db_method_info.threads == NULL) {
acpi_os_printf("No memory for thread IDs array\n");
(void)acpi_os_delete_semaphore(main_thread_gate);
(void)acpi_os_delete_semaphore(thread_complete_gate);
(void)acpi_os_delete_semaphore(info_gate);
return;
}
memset(acpi_gbl_db_method_info.threads, 0, size);
acpi_gbl_db_method_info.name = method_name_arg;
acpi_gbl_db_method_info.flags = 0;
acpi_gbl_db_method_info.num_loops = num_loops;
acpi_gbl_db_method_info.main_thread_gate = main_thread_gate;
acpi_gbl_db_method_info.thread_complete_gate = thread_complete_gate;
acpi_gbl_db_method_info.info_gate = info_gate;
acpi_gbl_db_method_info.init_args = 1;
acpi_gbl_db_method_info.args = acpi_gbl_db_method_info.arguments;
acpi_gbl_db_method_info.arguments[0] =
acpi_gbl_db_method_info.num_threads_str;
acpi_gbl_db_method_info.arguments[1] =
acpi_gbl_db_method_info.id_of_thread_str;
acpi_gbl_db_method_info.arguments[2] =
acpi_gbl_db_method_info.index_of_thread_str;
acpi_gbl_db_method_info.arguments[3] = NULL;
acpi_gbl_db_method_info.types = acpi_gbl_db_method_info.arg_types;
acpi_gbl_db_method_info.arg_types[0] = ACPI_TYPE_INTEGER;
acpi_gbl_db_method_info.arg_types[1] = ACPI_TYPE_INTEGER;
acpi_gbl_db_method_info.arg_types[2] = ACPI_TYPE_INTEGER;
acpi_db_uint32_to_hex_string(num_threads,
acpi_gbl_db_method_info.num_threads_str);
status = acpi_db_execute_setup(&acpi_gbl_db_method_info);
if (ACPI_FAILURE(status)) {
goto cleanup_and_exit;
}
status = acpi_get_handle(NULL, acpi_gbl_db_method_info.pathname,
&acpi_gbl_db_method_info.method);
if (ACPI_FAILURE(status)) {
acpi_os_printf("%s Could not get handle for %s\n",
acpi_format_exception(status),
acpi_gbl_db_method_info.pathname);
goto cleanup_and_exit;
}
acpi_os_printf("Creating %X threads to execute %X times each\n",
num_threads, num_loops);
for (i = 0; i < (num_threads); i++) {
status =
acpi_os_execute(OSL_DEBUGGER_EXEC_THREAD,
acpi_db_method_thread,
&acpi_gbl_db_method_info);
if (ACPI_FAILURE(status)) {
break;
}
}
(void)acpi_os_wait_semaphore(main_thread_gate, 1, ACPI_WAIT_FOREVER);
acpi_db_set_output_destination(ACPI_DB_DUPLICATE_OUTPUT);
acpi_os_printf("All threads (%X) have completed\n", num_threads);
acpi_db_set_output_destination(ACPI_DB_CONSOLE_OUTPUT);
cleanup_and_exit:
(void)acpi_os_delete_semaphore(main_thread_gate);
(void)acpi_os_delete_semaphore(thread_complete_gate);
(void)acpi_os_delete_semaphore(info_gate);
acpi_os_free(acpi_gbl_db_method_info.threads);
acpi_gbl_db_method_info.threads = NULL;
}
