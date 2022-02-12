static bool acpi_property_value_ok(const union acpi_object *value)
{
int j;
switch (value->type) {
case ACPI_TYPE_INTEGER:
case ACPI_TYPE_STRING:
case ACPI_TYPE_LOCAL_REFERENCE:
return true;
case ACPI_TYPE_PACKAGE:
for (j = 0; j < value->package.count; j++)
switch (value->package.elements[j].type) {
case ACPI_TYPE_INTEGER:
case ACPI_TYPE_STRING:
case ACPI_TYPE_LOCAL_REFERENCE:
continue;
default:
return false;
}
return true;
}
return false;
}
static bool acpi_properties_format_valid(const union acpi_object *properties)
{
int i;
for (i = 0; i < properties->package.count; i++) {
const union acpi_object *property;
property = &properties->package.elements[i];
if (property->package.count != 2
|| property->package.elements[0].type != ACPI_TYPE_STRING
|| !acpi_property_value_ok(&property->package.elements[1]))
return false;
}
return true;
}
static void acpi_init_of_compatible(struct acpi_device *adev)
{
const union acpi_object *of_compatible;
int ret;
ret = acpi_dev_get_property_array(adev, "compatible", ACPI_TYPE_STRING,
&of_compatible);
if (ret) {
ret = acpi_dev_get_property(adev, "compatible",
ACPI_TYPE_STRING, &of_compatible);
if (ret) {
if (adev->parent
&& adev->parent->flags.of_compatible_ok)
goto out;
return;
}
}
adev->data.of_compatible = of_compatible;
out:
adev->flags.of_compatible_ok = 1;
}
void acpi_init_properties(struct acpi_device *adev)
{
struct acpi_buffer buf = { ACPI_ALLOCATE_BUFFER };
bool acpi_of = false;
struct acpi_hardware_id *hwid;
const union acpi_object *desc;
acpi_status status;
int i;
list_for_each_entry(hwid, &adev->pnp.ids, list) {
if (!strcmp(hwid->id, ACPI_DT_NAMESPACE_HID)) {
acpi_of = true;
break;
}
}
status = acpi_evaluate_object_typed(adev->handle, "_DSD", NULL, &buf,
ACPI_TYPE_PACKAGE);
if (ACPI_FAILURE(status))
goto out;
desc = buf.pointer;
if (desc->package.count % 2)
goto fail;
for (i = 0; i < desc->package.count; i += 2) {
const union acpi_object *uuid, *properties;
uuid = &desc->package.elements[i];
properties = &desc->package.elements[i + 1];
if (uuid->type != ACPI_TYPE_BUFFER || uuid->buffer.length != 16
|| properties->type != ACPI_TYPE_PACKAGE)
break;
if (memcmp(uuid->buffer.pointer, prp_uuid, sizeof(prp_uuid)))
continue;
if (!acpi_properties_format_valid(properties))
break;
adev->data.pointer = buf.pointer;
adev->data.properties = properties;
if (acpi_of)
acpi_init_of_compatible(adev);
goto out;
}
fail:
dev_dbg(&adev->dev, "Returned _DSD data is not valid, skipping\n");
ACPI_FREE(buf.pointer);
out:
if (acpi_of && !adev->flags.of_compatible_ok)
acpi_handle_info(adev->handle,
ACPI_DT_NAMESPACE_HID " requires 'compatible' property\n");
}
void acpi_free_properties(struct acpi_device *adev)
{
ACPI_FREE((void *)adev->data.pointer);
adev->data.of_compatible = NULL;
adev->data.pointer = NULL;
adev->data.properties = NULL;
}
int acpi_dev_get_property(struct acpi_device *adev, const char *name,
acpi_object_type type, const union acpi_object **obj)
{
const union acpi_object *properties;
int i;
if (!adev || !name)
return -EINVAL;
if (!adev->data.pointer || !adev->data.properties)
return -ENODATA;
properties = adev->data.properties;
for (i = 0; i < properties->package.count; i++) {
const union acpi_object *propname, *propvalue;
const union acpi_object *property;
property = &properties->package.elements[i];
propname = &property->package.elements[0];
propvalue = &property->package.elements[1];
if (!strcmp(name, propname->string.pointer)) {
if (type != ACPI_TYPE_ANY && propvalue->type != type)
return -EPROTO;
else if (obj)
*obj = propvalue;
return 0;
}
}
return -ENODATA;
}
int acpi_dev_get_property_array(struct acpi_device *adev, const char *name,
acpi_object_type type,
const union acpi_object **obj)
{
const union acpi_object *prop;
int ret, i;
ret = acpi_dev_get_property(adev, name, ACPI_TYPE_PACKAGE, &prop);
if (ret)
return ret;
if (type != ACPI_TYPE_ANY) {
for (i = 0; i < prop->package.count; i++)
if (prop->package.elements[i].type != type)
return -EPROTO;
}
if (obj)
*obj = prop;
return 0;
}
int acpi_dev_get_property_reference(struct acpi_device *adev,
const char *name, size_t index,
struct acpi_reference_args *args)
{
const union acpi_object *element, *end;
const union acpi_object *obj;
struct acpi_device *device;
int ret, idx = 0;
ret = acpi_dev_get_property(adev, name, ACPI_TYPE_ANY, &obj);
if (ret)
return ret;
if (obj->type == ACPI_TYPE_LOCAL_REFERENCE) {
if (index)
return -EINVAL;
ret = acpi_bus_get_device(obj->reference.handle, &device);
if (ret)
return ret;
args->adev = device;
args->nargs = 0;
return 0;
}
if (obj->type != ACPI_TYPE_PACKAGE || index >= obj->package.count)
return -EPROTO;
element = obj->package.elements;
end = element + obj->package.count;
while (element < end) {
u32 nargs, i;
if (element->type != ACPI_TYPE_LOCAL_REFERENCE)
return -EPROTO;
ret = acpi_bus_get_device(element->reference.handle, &device);
if (ret)
return -ENODEV;
element++;
nargs = 0;
for (i = 0; element + i < end; i++) {
int type = element[i].type;
if (type == ACPI_TYPE_INTEGER)
nargs++;
else if (type == ACPI_TYPE_LOCAL_REFERENCE)
break;
else
return -EPROTO;
}
if (idx++ == index) {
args->adev = device;
args->nargs = nargs;
for (i = 0; i < nargs; i++)
args->args[i] = element[i].integer.value;
return 0;
}
element += nargs;
}
return -EPROTO;
}
int acpi_dev_prop_get(struct acpi_device *adev, const char *propname,
void **valptr)
{
return acpi_dev_get_property(adev, propname, ACPI_TYPE_ANY,
(const union acpi_object **)valptr);
}
int acpi_dev_prop_read_single(struct acpi_device *adev, const char *propname,
enum dev_prop_type proptype, void *val)
{
const union acpi_object *obj;
int ret;
if (!val)
return -EINVAL;
if (proptype >= DEV_PROP_U8 && proptype <= DEV_PROP_U64) {
ret = acpi_dev_get_property(adev, propname, ACPI_TYPE_INTEGER, &obj);
if (ret)
return ret;
switch (proptype) {
case DEV_PROP_U8:
if (obj->integer.value > U8_MAX)
return -EOVERFLOW;
*(u8 *)val = obj->integer.value;
break;
case DEV_PROP_U16:
if (obj->integer.value > U16_MAX)
return -EOVERFLOW;
*(u16 *)val = obj->integer.value;
break;
case DEV_PROP_U32:
if (obj->integer.value > U32_MAX)
return -EOVERFLOW;
*(u32 *)val = obj->integer.value;
break;
default:
*(u64 *)val = obj->integer.value;
break;
}
} else if (proptype == DEV_PROP_STRING) {
ret = acpi_dev_get_property(adev, propname, ACPI_TYPE_STRING, &obj);
if (ret)
return ret;
*(char **)val = obj->string.pointer;
} else {
ret = -EINVAL;
}
return ret;
}
static int acpi_copy_property_array_u8(const union acpi_object *items, u8 *val,
size_t nval)
{
int i;
for (i = 0; i < nval; i++) {
if (items[i].type != ACPI_TYPE_INTEGER)
return -EPROTO;
if (items[i].integer.value > U8_MAX)
return -EOVERFLOW;
val[i] = items[i].integer.value;
}
return 0;
}
static int acpi_copy_property_array_u16(const union acpi_object *items,
u16 *val, size_t nval)
{
int i;
for (i = 0; i < nval; i++) {
if (items[i].type != ACPI_TYPE_INTEGER)
return -EPROTO;
if (items[i].integer.value > U16_MAX)
return -EOVERFLOW;
val[i] = items[i].integer.value;
}
return 0;
}
static int acpi_copy_property_array_u32(const union acpi_object *items,
u32 *val, size_t nval)
{
int i;
for (i = 0; i < nval; i++) {
if (items[i].type != ACPI_TYPE_INTEGER)
return -EPROTO;
if (items[i].integer.value > U32_MAX)
return -EOVERFLOW;
val[i] = items[i].integer.value;
}
return 0;
}
static int acpi_copy_property_array_u64(const union acpi_object *items,
u64 *val, size_t nval)
{
int i;
for (i = 0; i < nval; i++) {
if (items[i].type != ACPI_TYPE_INTEGER)
return -EPROTO;
val[i] = items[i].integer.value;
}
return 0;
}
static int acpi_copy_property_array_string(const union acpi_object *items,
char **val, size_t nval)
{
int i;
for (i = 0; i < nval; i++) {
if (items[i].type != ACPI_TYPE_STRING)
return -EPROTO;
val[i] = items[i].string.pointer;
}
return 0;
}
int acpi_dev_prop_read(struct acpi_device *adev, const char *propname,
enum dev_prop_type proptype, void *val, size_t nval)
{
const union acpi_object *obj;
const union acpi_object *items;
int ret;
if (val && nval == 1) {
ret = acpi_dev_prop_read_single(adev, propname, proptype, val);
if (!ret)
return ret;
}
ret = acpi_dev_get_property_array(adev, propname, ACPI_TYPE_ANY, &obj);
if (ret)
return ret;
if (!val)
return obj->package.count;
else if (nval <= 0)
return -EINVAL;
if (nval > obj->package.count)
return -EOVERFLOW;
items = obj->package.elements;
switch (proptype) {
case DEV_PROP_U8:
ret = acpi_copy_property_array_u8(items, (u8 *)val, nval);
break;
case DEV_PROP_U16:
ret = acpi_copy_property_array_u16(items, (u16 *)val, nval);
break;
case DEV_PROP_U32:
ret = acpi_copy_property_array_u32(items, (u32 *)val, nval);
break;
case DEV_PROP_U64:
ret = acpi_copy_property_array_u64(items, (u64 *)val, nval);
break;
case DEV_PROP_STRING:
ret = acpi_copy_property_array_string(items, (char **)val, nval);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
