static acpi_status sst_acpi_find_name(acpi_handle handle, u32 level,
void *context, void **ret)
{
struct acpi_device *adev;
const char *name = NULL;
if (acpi_bus_get_device(handle, &adev))
return AE_OK;
if (adev->status.present && adev->status.functional) {
name = acpi_dev_name(adev);
*(const char **)ret = name;
return AE_CTRL_TERMINATE;
}
return AE_OK;
}
const char *sst_acpi_find_name_from_hid(const u8 hid[ACPI_ID_LEN])
{
const char *name = NULL;
acpi_status status;
status = acpi_get_devices(hid, sst_acpi_find_name, NULL,
(void **)&name);
if (ACPI_FAILURE(status) || name[0] == '\0')
return NULL;
return name;
}
static acpi_status sst_acpi_mach_match(acpi_handle handle, u32 level,
void *context, void **ret)
{
unsigned long long sta;
acpi_status status;
*(bool *)context = true;
status = acpi_evaluate_integer(handle, "_STA", NULL, &sta);
if (ACPI_FAILURE(status) || !(sta & ACPI_STA_DEVICE_PRESENT))
*(bool *)context = false;
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
static acpi_status sst_acpi_find_package(acpi_handle handle, u32 level,
void *context, void **ret)
{
struct acpi_device *adev;
acpi_status status = AE_OK;
struct sst_acpi_package_context *pkg_ctx = context;
pkg_ctx->data_valid = false;
if (acpi_bus_get_device(handle, &adev))
return AE_OK;
if (adev->status.present && adev->status.functional) {
struct acpi_buffer buffer = {ACPI_ALLOCATE_BUFFER, NULL};
union acpi_object *myobj = NULL;
status = acpi_evaluate_object_typed(handle, pkg_ctx->name,
NULL, &buffer,
ACPI_TYPE_PACKAGE);
if (ACPI_FAILURE(status))
return AE_OK;
myobj = buffer.pointer;
if (!myobj || myobj->package.count != pkg_ctx->length) {
kfree(buffer.pointer);
return AE_OK;
}
status = acpi_extract_package(myobj,
pkg_ctx->format, pkg_ctx->state);
if (ACPI_FAILURE(status)) {
kfree(buffer.pointer);
return AE_OK;
}
kfree(buffer.pointer);
pkg_ctx->data_valid = true;
return AE_CTRL_TERMINATE;
}
return AE_OK;
}
bool sst_acpi_find_package_from_hid(const u8 hid[ACPI_ID_LEN],
struct sst_acpi_package_context *ctx)
{
acpi_status status;
status = acpi_get_devices(hid, sst_acpi_find_package, ctx, NULL);
if (ACPI_FAILURE(status) || !ctx->data_valid)
return false;
return true;
}
