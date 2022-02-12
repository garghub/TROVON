u32 cm_get_file_size(FILE * file)
{
long file_size;
long current_offset;
current_offset = ftell(file);
if (current_offset < 0) {
goto offset_error;
}
if (fseek(file, 0, SEEK_END)) {
goto seek_error;
}
file_size = ftell(file);
if (file_size < 0) {
goto offset_error;
}
if (fseek(file, current_offset, SEEK_SET)) {
goto seek_error;
}
return ((u32)file_size);
offset_error:
perror("Could not get file offset");
return (ACPI_UINT32_MAX);
seek_error:
perror("Could not seek file");
return (ACPI_UINT32_MAX);
}
