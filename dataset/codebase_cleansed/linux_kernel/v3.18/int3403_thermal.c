static int sys_get_curr_temp(struct thermal_zone_device *tzone,
unsigned long *temp)
{
struct int3403_priv *priv = tzone->devdata;
struct acpi_device *device = priv->adev;
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
struct int3403_priv *priv = tzone->devdata;
struct acpi_device *device = priv->adev;
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
struct int3403_priv *priv = tzone->devdata;
struct int3403_sensor *obj = priv->priv;
if (priv->type != INT3403_TYPE_SENSOR || !obj)
return -EINVAL;
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
struct int3403_priv *priv = thermal->devdata;
struct int3403_sensor *obj = priv->priv;
if (trip == obj->crit_trip_id)
*type = THERMAL_TRIP_CRITICAL;
else
*type = THERMAL_TRIP_PASSIVE;
return 0;
}
int sys_set_trip_temp(struct thermal_zone_device *tzone, int trip,
unsigned long temp)
{
struct int3403_priv *priv = tzone->devdata;
struct acpi_device *device = priv->adev;
struct int3403_sensor *obj = priv->priv;
acpi_status status;
char name[10];
int ret = 0;
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
static void int3403_notify(acpi_handle handle,
u32 event, void *data)
{
struct int3403_priv *priv = data;
struct int3403_sensor *obj;
if (!priv)
return;
obj = priv->priv;
if (priv->type != INT3403_TYPE_SENSOR || !obj)
return;
switch (event) {
case INT3403_PERF_CHANGED_EVENT:
break;
case INT3403_THERMAL_EVENT:
thermal_zone_device_update(obj->tzone);
break;
default:
dev_err(&priv->pdev->dev, "Unsupported event [0x%x]\n", event);
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
static int int3403_sensor_add(struct int3403_priv *priv)
{
int result = 0;
acpi_status status;
struct int3403_sensor *obj;
unsigned long long trip_cnt;
int trip_mask = 0;
obj = devm_kzalloc(&priv->pdev->dev, sizeof(*obj), GFP_KERNEL);
if (!obj)
return -ENOMEM;
priv->priv = obj;
status = acpi_evaluate_integer(priv->adev->handle, "PATC", NULL,
&trip_cnt);
if (ACPI_FAILURE(status))
trip_cnt = 0;
if (trip_cnt) {
obj->thresholds = devm_kzalloc(&priv->pdev->dev,
sizeof(*obj->thresholds) * trip_cnt,
GFP_KERNEL);
if (!obj->thresholds) {
result = -ENOMEM;
goto err_free_obj;
}
trip_mask = BIT(trip_cnt) - 1;
}
obj->psv_trip_id = -1;
if (!sys_get_trip_psv(priv->adev, &obj->psv_temp))
obj->psv_trip_id = trip_cnt++;
obj->crit_trip_id = -1;
if (!sys_get_trip_crt(priv->adev, &obj->crit_temp))
obj->crit_trip_id = trip_cnt++;
obj->tzone = thermal_zone_device_register(acpi_device_bid(priv->adev),
trip_cnt, trip_mask, priv, &tzone_ops,
&int3403_thermal_params, 0, 0);
if (IS_ERR(obj->tzone)) {
result = PTR_ERR(obj->tzone);
obj->tzone = NULL;
goto err_free_obj;
}
result = acpi_install_notify_handler(priv->adev->handle,
ACPI_DEVICE_NOTIFY, int3403_notify,
(void *)priv);
if (result)
goto err_free_obj;
return 0;
err_free_obj:
if (obj->tzone)
thermal_zone_device_unregister(obj->tzone);
return result;
}
static int int3403_sensor_remove(struct int3403_priv *priv)
{
struct int3403_sensor *obj = priv->priv;
thermal_zone_device_unregister(obj->tzone);
return 0;
}
static int int3403_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct int3403_priv *priv = cdev->devdata;
struct int3403_cdev *obj = priv->priv;
*state = obj->max_state;
return 0;
}
static int int3403_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct int3403_priv *priv = cdev->devdata;
unsigned long long level;
acpi_status status;
status = acpi_evaluate_integer(priv->adev->handle, "PPPC", NULL, &level);
if (ACPI_SUCCESS(status)) {
*state = level;
return 0;
} else
return -EINVAL;
}
static int
int3403_set_cur_state(struct thermal_cooling_device *cdev, unsigned long state)
{
struct int3403_priv *priv = cdev->devdata;
acpi_status status;
status = acpi_execute_simple_method(priv->adev->handle, "SPPC", state);
if (ACPI_SUCCESS(status))
return 0;
else
return -EINVAL;
}
static int int3403_cdev_add(struct int3403_priv *priv)
{
int result = 0;
acpi_status status;
struct int3403_cdev *obj;
struct acpi_buffer buf = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *p;
obj = devm_kzalloc(&priv->pdev->dev, sizeof(*obj), GFP_KERNEL);
if (!obj)
return -ENOMEM;
status = acpi_evaluate_object(priv->adev->handle, "PPSS", NULL, &buf);
if (ACPI_FAILURE(status))
return -ENODEV;
p = buf.pointer;
if (!p || (p->type != ACPI_TYPE_PACKAGE)) {
printk(KERN_WARNING "Invalid PPSS data\n");
return -EFAULT;
}
obj->max_state = p->package.count - 1;
obj->cdev =
thermal_cooling_device_register(acpi_device_bid(priv->adev),
priv, &int3403_cooling_ops);
if (IS_ERR(obj->cdev))
result = PTR_ERR(obj->cdev);
priv->priv = obj;
return result;
}
static int int3403_cdev_remove(struct int3403_priv *priv)
{
struct int3403_cdev *obj = priv->priv;
thermal_cooling_device_unregister(obj->cdev);
return 0;
}
static int int3403_add(struct platform_device *pdev)
{
struct int3403_priv *priv;
int result = 0;
acpi_status status;
priv = devm_kzalloc(&pdev->dev, sizeof(struct int3403_priv),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->pdev = pdev;
priv->adev = ACPI_COMPANION(&(pdev->dev));
if (!priv->adev) {
result = -EINVAL;
goto err;
}
status = acpi_evaluate_integer(priv->adev->handle, "PTYP",
NULL, &priv->type);
if (ACPI_FAILURE(status)) {
result = -EINVAL;
goto err;
}
platform_set_drvdata(pdev, priv);
switch (priv->type) {
case INT3403_TYPE_SENSOR:
result = int3403_sensor_add(priv);
break;
case INT3403_TYPE_CHARGER:
case INT3403_TYPE_BATTERY:
result = int3403_cdev_add(priv);
break;
default:
result = -EINVAL;
}
if (result)
goto err;
return result;
err:
return result;
}
static int int3403_remove(struct platform_device *pdev)
{
struct int3403_priv *priv = platform_get_drvdata(pdev);
switch (priv->type) {
case INT3403_TYPE_SENSOR:
int3403_sensor_remove(priv);
break;
case INT3403_TYPE_CHARGER:
case INT3403_TYPE_BATTERY:
int3403_cdev_remove(priv);
break;
default:
break;
}
return 0;
}
