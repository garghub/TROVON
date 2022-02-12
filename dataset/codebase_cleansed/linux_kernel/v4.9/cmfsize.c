u32 cm_get_file_size(ACPI_FILE file)
{
long file_size;
long current_offset;
acpi_status status;
current_offset = ftell(file);
if (current_offset < 0) {
goto offset_error;
}
status = fseek(file, 0, SEEK_END);
if (ACPI_FAILURE(status)) {
goto seek_error;
}
file_size = ftell(file);
if (file_size < 0) {
goto offset_error;
}
status = fseek(file, current_offset, SEEK_SET);
if (ACPI_FAILURE(status)) {
goto seek_error;
}
return ((u32)file_size);
offset_error:
fprintf(stderr, "Could not get file offset\n");
return (ACPI_UINT32_MAX);
seek_error:
fprintf(stderr, "Could not set file offset\n");
return (ACPI_UINT32_MAX);
}
