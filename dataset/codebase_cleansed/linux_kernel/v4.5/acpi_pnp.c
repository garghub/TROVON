static bool matching_id(const char *idstr, const char *list_id)
{
int i;
if (memcmp(idstr, list_id, 3))
return false;
for (i = 3; i < 7; i++) {
char c = toupper(idstr[i]);
if (!isxdigit(c)
|| (list_id[i] != 'X' && c != toupper(list_id[i])))
return false;
}
return true;
}
static bool acpi_pnp_match(const char *idstr, const struct acpi_device_id **matchid)
{
const struct acpi_device_id *devid;
for (devid = acpi_pnp_device_ids; devid->id[0]; devid++)
if (matching_id(idstr, (char *)devid->id)) {
if (matchid)
*matchid = devid;
return true;
}
return false;
}
static int acpi_pnp_attach(struct acpi_device *adev,
const struct acpi_device_id *id)
{
return 1;
}
static int is_cmos_rtc_device(struct acpi_device *adev)
{
static const struct acpi_device_id ids[] = {
{ "PNP0B00" },
{ "PNP0B01" },
{ "PNP0B02" },
{""},
};
return !acpi_match_device_ids(adev, ids);
}
bool acpi_is_pnp_device(struct acpi_device *adev)
{
return adev->handler == &acpi_pnp_handler || is_cmos_rtc_device(adev);
}
void __init acpi_pnp_init(void)
{
acpi_scan_add_handler(&acpi_pnp_handler);
}
