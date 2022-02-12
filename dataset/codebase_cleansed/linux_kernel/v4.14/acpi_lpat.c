int acpi_lpat_raw_to_temp(struct acpi_lpat_conversion_table *lpat_table,
int raw)
{
int i, delta_temp, delta_raw, temp;
struct acpi_lpat *lpat = lpat_table->lpat;
for (i = 0; i < lpat_table->lpat_count - 1; i++) {
if ((raw >= lpat[i].raw && raw <= lpat[i+1].raw) ||
(raw <= lpat[i].raw && raw >= lpat[i+1].raw))
break;
}
if (i == lpat_table->lpat_count - 1)
return -ENOENT;
delta_temp = lpat[i+1].temp - lpat[i].temp;
delta_raw = lpat[i+1].raw - lpat[i].raw;
temp = lpat[i].temp + (raw - lpat[i].raw) * delta_temp / delta_raw;
return temp;
}
int acpi_lpat_temp_to_raw(struct acpi_lpat_conversion_table *lpat_table,
int temp)
{
int i, delta_temp, delta_raw, raw;
struct acpi_lpat *lpat = lpat_table->lpat;
for (i = 0; i < lpat_table->lpat_count - 1; i++) {
if (temp >= lpat[i].temp && temp <= lpat[i+1].temp)
break;
}
if (i == lpat_table->lpat_count - 1)
return -ENOENT;
delta_temp = lpat[i+1].temp - lpat[i].temp;
delta_raw = lpat[i+1].raw - lpat[i].raw;
raw = lpat[i].raw + (temp - lpat[i].temp) * delta_raw / delta_temp;
return raw;
}
struct acpi_lpat_conversion_table *acpi_lpat_get_conversion_table(acpi_handle
handle)
{
struct acpi_lpat_conversion_table *lpat_table = NULL;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj_p, *obj_e;
int *lpat, i;
acpi_status status;
status = acpi_evaluate_object(handle, "LPAT", NULL, &buffer);
if (ACPI_FAILURE(status))
return NULL;
obj_p = (union acpi_object *)buffer.pointer;
if (!obj_p || (obj_p->type != ACPI_TYPE_PACKAGE) ||
(obj_p->package.count % 2) || (obj_p->package.count < 4))
goto out;
lpat = kcalloc(obj_p->package.count, sizeof(int), GFP_KERNEL);
if (!lpat)
goto out;
for (i = 0; i < obj_p->package.count; i++) {
obj_e = &obj_p->package.elements[i];
if (obj_e->type != ACPI_TYPE_INTEGER) {
kfree(lpat);
goto out;
}
lpat[i] = (s64)obj_e->integer.value;
}
lpat_table = kzalloc(sizeof(*lpat_table), GFP_KERNEL);
if (!lpat_table) {
kfree(lpat);
goto out;
}
lpat_table->lpat = (struct acpi_lpat *)lpat;
lpat_table->lpat_count = obj_p->package.count / 2;
out:
kfree(buffer.pointer);
return lpat_table;
}
void acpi_lpat_free_conversion_table(struct acpi_lpat_conversion_table
*lpat_table)
{
if (lpat_table) {
kfree(lpat_table->lpat);
kfree(lpat_table);
}
}
