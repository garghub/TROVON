static int sys_get_curr_temp(struct thermal_zone_device *tzone,
unsigned long *temp)
{
struct acpi_device *device = tzone->devdata;
unsigned long long tmp;
acpi_status status;
status = acpi_evaluate_integer(device->handle, "_TMP", NULL, &tmp);
if (ACPI_FAILURE(status))
return -EIO;
*temp = DECI_KELVIN_TO_MILLI_CELSIUS(tmp, KELVIN_OFFSET);
return 0;
}
static int sys_get_trip_hyst(struct thermal_zone_device *tzone,
int trip, unsigned long *temp)
{
struct acpi_device *device = tzone->devdata;
unsigned long long hyst;
acpi_status status;
status = acpi_evaluate_integer(device->handle, "GTSH", NULL, &hyst);
if (ACPI_FAILURE(status))
return -EIO;
*temp = hyst * 100;
return 0;
}
static int sys_get_trip_temp(struct thermal_zone_device *tzone,
int trip, unsigned long *temp)
{
struct acpi_device *device = tzone->devdata;
struct int3403_sensor *obj = acpi_driver_data(device);
if (trip == obj->crit_trip_id)
*temp = obj->crit_temp;
else if (trip == obj->psv_trip_id)
*temp = obj->psv_temp;
else {
*temp = obj->thresholds[trip];
}
return 0;
}
static int sys_get_trip_type(struct thermal_zone_device *thermal,
int trip, enum thermal_trip_type *type)
{
struct acpi_device *device = thermal->devdata;
struct int3403_sensor *obj = acpi_driver_data(device);
if (trip == obj->crit_trip_id)
*type = THERMAL_TRIP_CRITICAL;
else
*type = THERMAL_TRIP_PASSIVE;
return 0;
}
int sys_set_trip_temp(struct thermal_zone_device *tzone, int trip,
unsigned long temp)
{
struct acpi_device *device = tzone->devdata;
acpi_status status;
char name[10];
int ret = 0;
struct int3403_sensor *obj = acpi_driver_data(device);
snprintf(name, sizeof(name), "PAT%d", trip);
if (acpi_has_method(device->handle, name)) {
status = acpi_execute_simple_method(device->handle, name,
MILLI_CELSIUS_TO_DECI_KELVIN(temp,
KELVIN_OFFSET));
if (ACPI_FAILURE(status))
ret = -EIO;
else
obj->thresholds[trip] = temp;
} else {
ret = -EIO;
dev_err(&device->dev, "sys_set_trip_temp: method not found\n");
}
return ret;
}
static void acpi_thermal_notify(struct acpi_device *device, u32 event)
{
struct int3403_sensor *obj;
if (!device)
return;
obj = acpi_driver_data(device);
if (!obj)
return;
switch (event) {
case INT3403_PERF_CHANGED_EVENT:
break;
case INT3403_THERMAL_EVENT:
thermal_zone_device_update(obj->tzone);
break;
default:
dev_err(&device->dev, "Unsupported event [0x%x]\n", event);
break;
}
}
static int sys_get_trip_crt(struct acpi_device *device, unsigned long *temp)
{
unsigned long long crt;
acpi_status status;
status = acpi_evaluate_integer(device->handle, "_CRT", NULL, &crt);
if (ACPI_FAILURE(status))
return -EIO;
*temp = DECI_KELVIN_TO_MILLI_CELSIUS(crt, KELVIN_OFFSET);
return 0;
}
static int sys_get_trip_psv(struct acpi_device *device, unsigned long *temp)
{
unsigned long long psv;
acpi_status status;
status = acpi_evaluate_integer(device->handle, "_PSV", NULL, &psv);
if (ACPI_FAILURE(status))
return -EIO;
*temp = DECI_KELVIN_TO_MILLI_CELSIUS(psv, KELVIN_OFFSET);
return 0;
}
static int acpi_int3403_add(struct acpi_device *device)
{
int result = 0;
unsigned long long ptyp;
acpi_status status;
struct int3403_sensor *obj;
unsigned long long trip_cnt;
int trip_mask = 0;
if (!device)
return -EINVAL;
status = acpi_evaluate_integer(device->handle, "PTYP", NULL, &ptyp);
if (ACPI_FAILURE(status))
return -EINVAL;
if (ptyp != INT3403_TYPE_SENSOR)
return -EINVAL;
obj = devm_kzalloc(&device->dev, sizeof(*obj), GFP_KERNEL);
if (!obj)
return -ENOMEM;
device->driver_data = obj;
status = acpi_evaluate_integer(device->handle, "PATC", NULL,
&trip_cnt);
if (ACPI_FAILURE(status))
trip_cnt = 0;
if (trip_cnt) {
obj->thresholds = devm_kzalloc(&device->dev,
sizeof(*obj->thresholds) * trip_cnt,
GFP_KERNEL);
if (!obj->thresholds)
return -ENOMEM;
trip_mask = BIT(trip_cnt) - 1;
}
obj->psv_trip_id = -1;
if (!sys_get_trip_psv(device, &obj->psv_temp))
obj->psv_trip_id = trip_cnt++;
obj->crit_trip_id = -1;
if (!sys_get_trip_crt(device, &obj->crit_temp))
obj->crit_trip_id = trip_cnt++;
obj->tzone = thermal_zone_device_register(acpi_device_bid(device),
trip_cnt, trip_mask, device, &tzone_ops,
NULL, 0, 0);
if (IS_ERR(obj->tzone)) {
result = PTR_ERR(obj->tzone);
return result;
}
strcpy(acpi_device_name(device), "INT3403");
strcpy(acpi_device_class(device), ACPI_INT3403_CLASS);
return 0;
}
static int acpi_int3403_remove(struct acpi_device *device)
{
struct int3403_sensor *obj;
obj = acpi_driver_data(device);
thermal_zone_device_unregister(obj->tzone);
return 0;
}
