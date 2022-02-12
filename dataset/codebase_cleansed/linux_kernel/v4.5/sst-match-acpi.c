static acpi_status sst_acpi_mach_match(acpi_handle handle, u32 level,
void *context, void **ret)
{
*(bool *)context = true;
return AE_OK;
}
struct sst_acpi_mach *sst_acpi_find_machine(struct sst_acpi_mach *machines)
{
struct sst_acpi_mach *mach;
bool found = false;
for (mach = machines; mach->id[0]; mach++)
if (ACPI_SUCCESS(acpi_get_devices(mach->id,
sst_acpi_mach_match,
&found, NULL)) && found)
return mach;
return NULL;
}
