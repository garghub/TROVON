static u8
acpi_db_match_command_help(const char *command,
const struct acpi_db_command_help *help)
{
char *invocation = help->invocation;
u32 line_count;
if (*invocation != ' ') {
return (FALSE);
}
while (*invocation == ' ') {
invocation++;
}
while ((*command) && (*invocation) && (*invocation != ' ')) {
if (tolower((int)*command) != tolower((int)*invocation)) {
return (FALSE);
}
invocation++;
command++;
}
line_count = help->line_count;
while (line_count) {
acpi_os_printf("%-38s : %s", help->invocation,
help->description);
help++;
line_count--;
}
return (TRUE);
}
static void acpi_db_display_command_info(const char *command, u8 display_all)
{
const struct acpi_db_command_help *next;
u8 matched;
next = acpi_gbl_db_command_help;
while (next->invocation) {
matched = acpi_db_match_command_help(command, next);
if (!display_all && matched) {
return;
}
next++;
}
}
static void acpi_db_display_help(char *command)
{
const struct acpi_db_command_help *next = acpi_gbl_db_command_help;
if (!command) {
while (next->invocation) {
acpi_os_printf("%-38s%s", next->invocation,
next->description);
next++;
}
} else {
acpi_db_display_command_info(command, TRUE);
}
}
char *acpi_db_get_next_token(char *string,
char **next, acpi_object_type *return_type)
{
char *start;
u32 depth;
acpi_object_type type = ACPI_TYPE_INTEGER;
if (!string || !(*string)) {
return (NULL);
}
if (*string == ' ') {
while (*string && (*string == ' ')) {
string++;
}
if (!(*string)) {
return (NULL);
}
}
switch (*string) {
case '"':
string++;
start = string;
type = ACPI_TYPE_STRING;
while (*string && (*string != '"')) {
string++;
}
break;
case '(':
string++;
start = string;
type = ACPI_TYPE_BUFFER;
while (*string && (*string != ')')) {
string++;
}
break;
case '[':
string++;
depth = 1;
start = string;
type = ACPI_TYPE_PACKAGE;
while (*string) {
if (*string == '"') {
string++;
while (*string && (*string != '"')) {
string++;
}
if (!(*string)) {
break;
}
} else if (*string == '[') {
depth++;
} else if (*string == ']') {
depth--;
if (depth == 0) {
break;
}
}
string++;
}
break;
default:
start = string;
while (*string && (*string != ' ')) {
string++;
}
break;
}
if (!(*string)) {
*next = NULL;
} else {
*string = 0;
*next = string + 1;
}
*return_type = type;
return (start);
}
static u32 acpi_db_get_line(char *input_buffer)
{
u32 i;
u32 count;
char *next;
char *this;
if (acpi_ut_safe_strcpy
(acpi_gbl_db_parsed_buf, sizeof(acpi_gbl_db_parsed_buf),
input_buffer)) {
acpi_os_printf
("Buffer overflow while parsing input line (max %u characters)\n",
sizeof(acpi_gbl_db_parsed_buf));
return (0);
}
this = acpi_gbl_db_parsed_buf;
for (i = 0; i < ACPI_DEBUGGER_MAX_ARGS; i++) {
acpi_gbl_db_args[i] = acpi_db_get_next_token(this, &next,
&acpi_gbl_db_arg_types
[i]);
if (!acpi_gbl_db_args[i]) {
break;
}
this = next;
}
acpi_ut_strupr(acpi_gbl_db_args[0]);
count = i;
if (count) {
count--;
}
return (count);
}
static u32 acpi_db_match_command(char *user_command)
{
u32 i;
if (!user_command || user_command[0] == 0) {
return (CMD_NULL);
}
for (i = CMD_FIRST_VALID; acpi_gbl_db_commands[i].name; i++) {
if (strstr
(ACPI_CAST_PTR(char, acpi_gbl_db_commands[i].name),
user_command) == acpi_gbl_db_commands[i].name) {
return (i);
}
}
return (CMD_NOT_FOUND);
}
acpi_status
acpi_db_command_dispatch(char *input_buffer,
struct acpi_walk_state *walk_state,
union acpi_parse_object *op)
{
u32 temp;
u32 command_index;
u32 param_count;
char *command_line;
acpi_status status = AE_CTRL_TRUE;
if (acpi_gbl_db_terminate_loop) {
return (AE_CTRL_TERMINATE);
}
param_count = acpi_db_get_line(input_buffer);
command_index = acpi_db_match_command(acpi_gbl_db_args[0]);
temp = 0;
if (command_index != CMD_HISTORY_LAST) {
acpi_db_add_to_history(input_buffer);
}
if (param_count < acpi_gbl_db_commands[command_index].min_args) {
acpi_os_printf
("%u parameters entered, [%s] requires %u parameters\n",
param_count, acpi_gbl_db_commands[command_index].name,
acpi_gbl_db_commands[command_index].min_args);
acpi_db_display_command_info(acpi_gbl_db_commands
[command_index].name, FALSE);
return (AE_CTRL_TRUE);
}
switch (command_index) {
case CMD_NULL:
if (op) {
return (AE_OK);
}
break;
case CMD_ALLOCATIONS:
#ifdef ACPI_DBG_TRACK_ALLOCATIONS
acpi_ut_dump_allocations((u32)-1, NULL);
#endif
break;
case CMD_ARGS:
case CMD_ARGUMENTS:
acpi_db_display_arguments();
break;
case CMD_BREAKPOINT:
acpi_db_set_method_breakpoint(acpi_gbl_db_args[1], walk_state,
op);
break;
case CMD_BUSINFO:
acpi_db_get_bus_info();
break;
case CMD_CALL:
acpi_db_set_method_call_breakpoint(op);
status = AE_OK;
break;
case CMD_DEBUG:
acpi_db_execute(acpi_gbl_db_args[1],
&acpi_gbl_db_args[2], &acpi_gbl_db_arg_types[2],
EX_SINGLE_STEP);
break;
case CMD_DISASSEMBLE:
case CMD_DISASM:
(void)acpi_db_disassemble_method(acpi_gbl_db_args[1]);
break;
case CMD_DUMP:
acpi_db_decode_and_display_object(acpi_gbl_db_args[1],
acpi_gbl_db_args[2]);
break;
case CMD_EVALUATE:
case CMD_EXECUTE:
acpi_db_execute(acpi_gbl_db_args[1],
&acpi_gbl_db_args[2], &acpi_gbl_db_arg_types[2],
EX_NO_SINGLE_STEP);
break;
case CMD_FIND:
status = acpi_db_find_name_in_namespace(acpi_gbl_db_args[1]);
break;
case CMD_GO:
acpi_gbl_cm_single_step = FALSE;
return (AE_OK);
case CMD_HANDLERS:
acpi_db_display_handlers();
break;
case CMD_HELP:
case CMD_HELP2:
acpi_db_display_help(acpi_gbl_db_args[1]);
break;
case CMD_HISTORY:
acpi_db_display_history();
break;
case CMD_HISTORY_EXE:
command_line = acpi_db_get_from_history(acpi_gbl_db_args[1]);
if (!command_line) {
return (AE_CTRL_TRUE);
}
status = acpi_db_command_dispatch(command_line, walk_state, op);
return (status);
case CMD_HISTORY_LAST:
command_line = acpi_db_get_from_history(NULL);
if (!command_line) {
return (AE_CTRL_TRUE);
}
status = acpi_db_command_dispatch(command_line, walk_state, op);
return (status);
case CMD_INFORMATION:
acpi_db_display_method_info(op);
break;
case CMD_INTEGRITY:
acpi_db_check_integrity();
break;
case CMD_INTO:
if (op) {
acpi_gbl_cm_single_step = TRUE;
return (AE_OK);
}
break;
case CMD_LEVEL:
if (param_count == 0) {
acpi_os_printf
("Current debug level for file output is: %8.8lX\n",
acpi_gbl_db_debug_level);
acpi_os_printf
("Current debug level for console output is: %8.8lX\n",
acpi_gbl_db_console_debug_level);
} else if (param_count == 2) {
temp = acpi_gbl_db_console_debug_level;
acpi_gbl_db_console_debug_level =
strtoul(acpi_gbl_db_args[1], NULL, 16);
acpi_os_printf
("Debug Level for console output was %8.8lX, now %8.8lX\n",
temp, acpi_gbl_db_console_debug_level);
} else {
temp = acpi_gbl_db_debug_level;
acpi_gbl_db_debug_level =
strtoul(acpi_gbl_db_args[1], NULL, 16);
acpi_os_printf
("Debug Level for file output was %8.8lX, now %8.8lX\n",
temp, acpi_gbl_db_debug_level);
}
break;
case CMD_LIST:
acpi_db_disassemble_aml(acpi_gbl_db_args[1], op);
break;
case CMD_LOCKS:
acpi_db_display_locks();
break;
case CMD_LOCALS:
acpi_db_display_locals();
break;
case CMD_METHODS:
status = acpi_db_display_objects("METHOD", acpi_gbl_db_args[1]);
break;
case CMD_NAMESPACE:
acpi_db_dump_namespace(acpi_gbl_db_args[1],
acpi_gbl_db_args[2]);
break;
case CMD_NOTIFY:
temp = strtoul(acpi_gbl_db_args[2], NULL, 0);
acpi_db_send_notify(acpi_gbl_db_args[1], temp);
break;
case CMD_OBJECTS:
acpi_ut_strupr(acpi_gbl_db_args[1]);
status =
acpi_db_display_objects(acpi_gbl_db_args[1],
acpi_gbl_db_args[2]);
break;
case CMD_OSI:
acpi_db_display_interfaces(acpi_gbl_db_args[1],
acpi_gbl_db_args[2]);
break;
case CMD_OWNER:
acpi_db_dump_namespace_by_owner(acpi_gbl_db_args[1],
acpi_gbl_db_args[2]);
break;
case CMD_PATHS:
acpi_db_dump_namespace_paths();
break;
case CMD_PREFIX:
acpi_db_set_scope(acpi_gbl_db_args[1]);
break;
case CMD_REFERENCES:
acpi_db_find_references(acpi_gbl_db_args[1]);
break;
case CMD_RESOURCES:
acpi_db_display_resources(acpi_gbl_db_args[1]);
break;
case CMD_RESULTS:
acpi_db_display_results();
break;
case CMD_SET:
acpi_db_set_method_data(acpi_gbl_db_args[1],
acpi_gbl_db_args[2],
acpi_gbl_db_args[3]);
break;
case CMD_STATS:
status = acpi_db_display_statistics(acpi_gbl_db_args[1]);
break;
case CMD_STOP:
return (AE_NOT_IMPLEMENTED);
case CMD_TABLES:
acpi_db_display_table_info(acpi_gbl_db_args[1]);
break;
case CMD_TEMPLATE:
acpi_db_display_template(acpi_gbl_db_args[1]);
break;
case CMD_TRACE:
acpi_db_trace(acpi_gbl_db_args[1], acpi_gbl_db_args[2],
acpi_gbl_db_args[3]);
break;
case CMD_TREE:
acpi_db_display_calling_tree();
break;
case CMD_TYPE:
acpi_db_display_object_type(acpi_gbl_db_args[1]);
break;
#ifdef ACPI_APPLICATION
case CMD_ENABLEACPI:
#if (!ACPI_REDUCED_HARDWARE)
status = acpi_enable();
if (ACPI_FAILURE(status)) {
acpi_os_printf("AcpiEnable failed (Status=%X)\n",
status);
return (status);
}
#endif
break;
case CMD_EVENT:
acpi_os_printf("Event command not implemented\n");
break;
case CMD_GPE:
acpi_db_generate_gpe(acpi_gbl_db_args[1], acpi_gbl_db_args[2]);
break;
case CMD_GPES:
acpi_db_display_gpes();
break;
case CMD_SCI:
acpi_db_generate_sci();
break;
case CMD_SLEEP:
status = acpi_db_sleep(acpi_gbl_db_args[1]);
break;
case CMD_CLOSE:
acpi_db_close_debug_file();
break;
case CMD_LOAD:{
struct acpi_new_table_desc *list_head = NULL;
status =
ac_get_all_tables_from_file(acpi_gbl_db_args[1],
ACPI_GET_ALL_TABLES,
&list_head);
if (ACPI_SUCCESS(status)) {
acpi_db_load_tables(list_head);
}
}
break;
case CMD_OPEN:
acpi_db_open_debug_file(acpi_gbl_db_args[1]);
break;
case CMD_TERMINATE:
acpi_db_set_output_destination(ACPI_DB_REDIRECTABLE_OUTPUT);
acpi_ut_subsystem_shutdown();
acpi_gbl_db_terminate_loop = TRUE;
break;
case CMD_THREADS:
acpi_db_create_execution_threads(acpi_gbl_db_args[1],
acpi_gbl_db_args[2],
acpi_gbl_db_args[3]);
break;
case CMD_PREDEFINED:
acpi_db_check_predefined_names();
break;
case CMD_TEST:
acpi_db_execute_test(acpi_gbl_db_args[1]);
break;
case CMD_UNLOAD:
acpi_db_unload_acpi_table(acpi_gbl_db_args[1]);
break;
#endif
case CMD_EXIT:
case CMD_QUIT:
if (op) {
acpi_os_printf("Method execution terminated\n");
return (AE_CTRL_TERMINATE);
}
if (!acpi_gbl_db_output_to_file) {
acpi_dbg_level = ACPI_DEBUG_DEFAULT;
}
#ifdef ACPI_APPLICATION
acpi_db_close_debug_file();
#endif
acpi_gbl_db_terminate_loop = TRUE;
return (AE_CTRL_TERMINATE);
case CMD_NOT_FOUND:
default:
acpi_os_printf("%s: unknown command\n", acpi_gbl_db_args[0]);
return (AE_CTRL_TRUE);
}
if (ACPI_SUCCESS(status)) {
status = AE_CTRL_TRUE;
}
return (status);
}
void ACPI_SYSTEM_XFACE acpi_db_execute_thread(void *context)
{
(void)acpi_db_user_commands();
acpi_gbl_db_threads_terminated = TRUE;
}
acpi_status acpi_db_user_commands(void)
{
acpi_status status = AE_OK;
acpi_os_printf("\n");
while (!acpi_gbl_db_terminate_loop) {
status = acpi_os_wait_command_ready();
if (ACPI_FAILURE(status)) {
break;
}
acpi_gbl_method_executing = FALSE;
acpi_gbl_step_to_next_call = FALSE;
(void)acpi_db_command_dispatch(acpi_gbl_db_line_buf, NULL,
NULL);
status = acpi_os_notify_command_complete();
if (ACPI_FAILURE(status)) {
break;
}
}
if (ACPI_FAILURE(status) && status != AE_CTRL_TERMINATE) {
ACPI_EXCEPTION((AE_INFO, status, "While parsing command line"));
}
return (status);
}
