u32 cm_get_file_size(ACPI_FILE file)
{
long file_size;
long current_offset;
acpi_status status;
current_offset = acpi_os_get_file_offset(file);
if (current_offset < 0) {
goto offset_error;
}
status = acpi_os_set_file_offset(file, 0, ACPI_FILE_END);
if (ACPI_FAILURE(status)) {
goto seek_error;
}
file_size = acpi_os_get_file_offset(file);
if (file_size < 0) {
goto offset_error;
}
status = acpi_os_set_file_offset(file, current_offset, ACPI_FILE_BEGIN);
if (ACPI_FAILURE(status)) {
goto seek_error;
}
return ((u32)file_size);
offset_error:
acpi_log_error("Could not get file offset");
return (ACPI_UINT32_MAX);
seek_error:
acpi_log_error("Could not set file offset");
return (ACPI_UINT32_MAX);
}
