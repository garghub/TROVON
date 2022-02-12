static acpi_size acpi_os_get_page_size(void)
{
#ifdef PAGE_SIZE
return PAGE_SIZE;
#else
return sysconf(_SC_PAGESIZE);
#endif
}
void *acpi_os_map_memory(acpi_physical_address where, acpi_size length)
{
u8 *mapped_memory;
acpi_physical_address offset;
acpi_size page_size;
int fd;
fd = open(SYSTEM_MEMORY, O_RDONLY | O_BINARY);
if (fd < 0) {
fprintf(stderr, "Cannot open %s\n", SYSTEM_MEMORY);
return (NULL);
}
page_size = acpi_os_get_page_size();
offset = where % page_size;
mapped_memory = mmap(NULL, (length + offset), PROT_READ, MMAP_FLAGS,
fd, (where - offset));
if (mapped_memory == MAP_FAILED) {
fprintf(stderr, "Cannot map %s\n", SYSTEM_MEMORY);
close(fd);
return (NULL);
}
close(fd);
return (ACPI_CAST8(mapped_memory + offset));
}
void acpi_os_unmap_memory(void *where, acpi_size length)
{
acpi_physical_address offset;
acpi_size page_size;
page_size = acpi_os_get_page_size();
offset = ACPI_TO_INTEGER(where) % page_size;
munmap((u8 *)where - offset, (length + offset));
}
