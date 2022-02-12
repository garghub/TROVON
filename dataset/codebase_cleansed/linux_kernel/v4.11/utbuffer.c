void acpi_ut_dump_buffer(u8 *buffer, u32 count, u32 display, u32 base_offset)
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
acpi_os_printf("%6.4X: ", (base_offset + i));
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
buffer[(acpi_size)i + j]);
break;
case DB_WORD_DISPLAY:
ACPI_MOVE_16_TO_32(&temp32,
&buffer[(acpi_size)i + j]);
acpi_os_printf("%04X ", temp32);
break;
case DB_DWORD_DISPLAY:
ACPI_MOVE_32_TO_32(&temp32,
&buffer[(acpi_size)i + j]);
acpi_os_printf("%08X ", temp32);
break;
case DB_QWORD_DISPLAY:
ACPI_MOVE_32_TO_32(&temp32,
&buffer[(acpi_size)i + j]);
acpi_os_printf("%08X", temp32);
ACPI_MOVE_32_TO_32(&temp32,
&buffer[(acpi_size)i + j +
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
if (j == 0) {
acpi_os_printf("// ");
}
buf_char = buffer[(acpi_size)i + j];
if (isprint(buf_char)) {
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
void
acpi_ut_debug_dump_buffer(u8 *buffer, u32 count, u32 display, u32 component_id)
{
if (!((ACPI_LV_TABLES & acpi_dbg_level) &&
(component_id & acpi_dbg_layer))) {
return;
}
acpi_ut_dump_buffer(buffer, count, display, 0);
}
void
acpi_ut_dump_buffer_to_file(ACPI_FILE file,
u8 *buffer, u32 count, u32 display, u32 base_offset)
{
u32 i = 0;
u32 j;
u32 temp32;
u8 buf_char;
if (!buffer) {
fprintf(file, "Null Buffer Pointer in DumpBuffer!\n");
return;
}
if ((count < 4) || (count & 0x01)) {
display = DB_BYTE_DISPLAY;
}
while (i < count) {
fprintf(file, "%6.4X: ", (base_offset + i));
for (j = 0; j < 16;) {
if (i + j >= count) {
fprintf(file, "%*s", ((display * 2) + 1), " ");
j += display;
continue;
}
switch (display) {
case DB_BYTE_DISPLAY:
default:
fprintf(file, "%02X ",
buffer[(acpi_size)i + j]);
break;
case DB_WORD_DISPLAY:
ACPI_MOVE_16_TO_32(&temp32,
&buffer[(acpi_size)i + j]);
fprintf(file, "%04X ", temp32);
break;
case DB_DWORD_DISPLAY:
ACPI_MOVE_32_TO_32(&temp32,
&buffer[(acpi_size)i + j]);
fprintf(file, "%08X ", temp32);
break;
case DB_QWORD_DISPLAY:
ACPI_MOVE_32_TO_32(&temp32,
&buffer[(acpi_size)i + j]);
fprintf(file, "%08X", temp32);
ACPI_MOVE_32_TO_32(&temp32,
&buffer[(acpi_size)i + j +
4]);
fprintf(file, "%08X ", temp32);
break;
}
j += display;
}
fprintf(file, " ");
for (j = 0; j < 16; j++) {
if (i + j >= count) {
fprintf(file, "\n");
return;
}
buf_char = buffer[(acpi_size)i + j];
if (isprint(buf_char)) {
fprintf(file, "%c", buf_char);
} else {
fprintf(file, ".");
}
}
fprintf(file, "\n");
i += 16;
}
return;
}
