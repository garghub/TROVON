void acpi_ut_init_stack_ptr_trace(void)
{
acpi_size current_sp;
acpi_gbl_entry_stack_pointer = &current_sp;
}
void acpi_ut_track_stack_ptr(void)
{
acpi_size current_sp;
if (&current_sp < acpi_gbl_lowest_stack_pointer) {
acpi_gbl_lowest_stack_pointer = &current_sp;
}
if (acpi_gbl_nesting_level > acpi_gbl_deepest_nesting) {
acpi_gbl_deepest_nesting = acpi_gbl_nesting_level;
}
}
static const char *acpi_ut_trim_function_name(const char *function_name)
{
if (*(ACPI_CAST_PTR(u32, function_name)) == ACPI_PREFIX_MIXED) {
return (function_name + 4);
}
if (*(ACPI_CAST_PTR(u32, function_name)) == ACPI_PREFIX_LOWER) {
return (function_name + 5);
}
return (function_name);
}
void ACPI_INTERNAL_VAR_XFACE
acpi_debug_print(u32 requested_debug_level,
u32 line_number,
const char *function_name,
const char *module_name,
u32 component_id, const char *format, ...)
{
acpi_thread_id thread_id;
va_list args;
if (!(requested_debug_level & acpi_dbg_level) ||
!(component_id & acpi_dbg_layer)) {
return;
}
thread_id = acpi_os_get_thread_id();
if (thread_id != acpi_gbl_prev_thread_id) {
if (ACPI_LV_THREADS & acpi_dbg_level) {
acpi_os_printf
("\n**** Context Switch from TID %u to TID %u ****\n\n",
(u32)acpi_gbl_prev_thread_id, (u32)thread_id);
}
acpi_gbl_prev_thread_id = thread_id;
}
acpi_os_printf("%8s-%04ld ", module_name, line_number);
if (ACPI_LV_THREADS & acpi_dbg_level) {
acpi_os_printf("[%u] ", (u32)thread_id);
}
acpi_os_printf("[%02ld] %-22.22s: ",
acpi_gbl_nesting_level,
acpi_ut_trim_function_name(function_name));
va_start(args, format);
acpi_os_vprintf(format, args);
va_end(args);
}
void ACPI_INTERNAL_VAR_XFACE
acpi_debug_print_raw(u32 requested_debug_level,
u32 line_number,
const char *function_name,
const char *module_name,
u32 component_id, const char *format, ...)
{
va_list args;
if (!(requested_debug_level & acpi_dbg_level) ||
!(component_id & acpi_dbg_layer)) {
return;
}
va_start(args, format);
acpi_os_vprintf(format, args);
va_end(args);
}
void
acpi_ut_trace(u32 line_number,
const char *function_name,
const char *module_name, u32 component_id)
{
acpi_gbl_nesting_level++;
acpi_ut_track_stack_ptr();
acpi_debug_print(ACPI_LV_FUNCTIONS,
line_number, function_name, module_name, component_id,
"%s\n", acpi_gbl_fn_entry_str);
}
void
acpi_ut_trace_ptr(u32 line_number,
const char *function_name,
const char *module_name, u32 component_id, void *pointer)
{
acpi_gbl_nesting_level++;
acpi_ut_track_stack_ptr();
acpi_debug_print(ACPI_LV_FUNCTIONS,
line_number, function_name, module_name, component_id,
"%s %p\n", acpi_gbl_fn_entry_str, pointer);
}
void
acpi_ut_trace_str(u32 line_number,
const char *function_name,
const char *module_name, u32 component_id, char *string)
{
acpi_gbl_nesting_level++;
acpi_ut_track_stack_ptr();
acpi_debug_print(ACPI_LV_FUNCTIONS,
line_number, function_name, module_name, component_id,
"%s %s\n", acpi_gbl_fn_entry_str, string);
}
void
acpi_ut_trace_u32(u32 line_number,
const char *function_name,
const char *module_name, u32 component_id, u32 integer)
{
acpi_gbl_nesting_level++;
acpi_ut_track_stack_ptr();
acpi_debug_print(ACPI_LV_FUNCTIONS,
line_number, function_name, module_name, component_id,
"%s %08X\n", acpi_gbl_fn_entry_str, integer);
}
void
acpi_ut_exit(u32 line_number,
const char *function_name,
const char *module_name, u32 component_id)
{
acpi_debug_print(ACPI_LV_FUNCTIONS,
line_number, function_name, module_name, component_id,
"%s\n", acpi_gbl_fn_exit_str);
acpi_gbl_nesting_level--;
}
void
acpi_ut_status_exit(u32 line_number,
const char *function_name,
const char *module_name,
u32 component_id, acpi_status status)
{
if (ACPI_SUCCESS(status)) {
acpi_debug_print(ACPI_LV_FUNCTIONS,
line_number, function_name, module_name,
component_id, "%s %s\n", acpi_gbl_fn_exit_str,
acpi_format_exception(status));
} else {
acpi_debug_print(ACPI_LV_FUNCTIONS,
line_number, function_name, module_name,
component_id, "%s ****Exception****: %s\n",
acpi_gbl_fn_exit_str,
acpi_format_exception(status));
}
acpi_gbl_nesting_level--;
}
void
acpi_ut_value_exit(u32 line_number,
const char *function_name,
const char *module_name, u32 component_id, u64 value)
{
acpi_debug_print(ACPI_LV_FUNCTIONS,
line_number, function_name, module_name, component_id,
"%s %8.8X%8.8X\n", acpi_gbl_fn_exit_str,
ACPI_FORMAT_UINT64(value));
acpi_gbl_nesting_level--;
}
void
acpi_ut_ptr_exit(u32 line_number,
const char *function_name,
const char *module_name, u32 component_id, u8 *ptr)
{
acpi_debug_print(ACPI_LV_FUNCTIONS,
line_number, function_name, module_name, component_id,
"%s %p\n", acpi_gbl_fn_exit_str, ptr);
acpi_gbl_nesting_level--;
}
void acpi_ut_dump_buffer2(u8 * buffer, u32 count, u32 display)
{
u32 i = 0;
u32 j;
u32 temp32;
u8 buf_char;
if (!buffer) {
acpi_os_printf("Null Buffer Pointer in DumpBuffer!\n");
return;
}
if ((count < 4) || (count & 0x01)) {
display = DB_BYTE_DISPLAY;
}
while (i < count) {
acpi_os_printf("%6.4X: ", i);
for (j = 0; j < 16;) {
if (i + j >= count) {
acpi_os_printf("%*s", ((display * 2) + 1), " ");
j += display;
continue;
}
switch (display) {
case DB_BYTE_DISPLAY:
default:
acpi_os_printf("%02X ",
buffer[(acpi_size) i + j]);
break;
case DB_WORD_DISPLAY:
ACPI_MOVE_16_TO_32(&temp32,
&buffer[(acpi_size) i + j]);
acpi_os_printf("%04X ", temp32);
break;
case DB_DWORD_DISPLAY:
ACPI_MOVE_32_TO_32(&temp32,
&buffer[(acpi_size) i + j]);
acpi_os_printf("%08X ", temp32);
break;
case DB_QWORD_DISPLAY:
ACPI_MOVE_32_TO_32(&temp32,
&buffer[(acpi_size) i + j]);
acpi_os_printf("%08X", temp32);
ACPI_MOVE_32_TO_32(&temp32,
&buffer[(acpi_size) i + j +
4]);
acpi_os_printf("%08X ", temp32);
break;
}
j += display;
}
acpi_os_printf(" ");
for (j = 0; j < 16; j++) {
if (i + j >= count) {
acpi_os_printf("\n");
return;
}
buf_char = buffer[(acpi_size) i + j];
if (ACPI_IS_PRINT(buf_char)) {
acpi_os_printf("%c", buf_char);
} else {
acpi_os_printf(".");
}
}
acpi_os_printf("\n");
i += 16;
}
return;
}
void acpi_ut_dump_buffer(u8 * buffer, u32 count, u32 display, u32 component_id)
{
if (!((ACPI_LV_TABLES & acpi_dbg_level) &&
(component_id & acpi_dbg_layer))) {
return;
}
acpi_ut_dump_buffer2(buffer, count, display);
}
