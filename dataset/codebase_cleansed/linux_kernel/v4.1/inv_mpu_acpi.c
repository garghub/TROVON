static int __init asus_t100_matched(const struct dmi_system_id *d)
{
matched_product_name = INV_MPU_ASUS_T100TA;
return 0;
}
static int asus_acpi_get_sensor_info(struct acpi_device *adev,
struct i2c_client *client,
struct i2c_board_info *info)
{
struct acpi_buffer buffer = {ACPI_ALLOCATE_BUFFER, NULL};
int i;
acpi_status status;
union acpi_object *cpm;
status = acpi_evaluate_object(adev->handle, "CNF0", NULL, &buffer);
if (ACPI_FAILURE(status))
return -ENODEV;
cpm = buffer.pointer;
for (i = 0; i < cpm->package.count; ++i) {
union acpi_object *elem;
int j;
elem = &(cpm->package.elements[i]);
for (j = 0; j < elem->package.count; ++j) {
union acpi_object *sub_elem;
sub_elem = &(elem->package.elements[j]);
if (sub_elem->type == ACPI_TYPE_STRING)
strlcpy(info->type, sub_elem->string.pointer,
sizeof(info->type));
else if (sub_elem->type == ACPI_TYPE_INTEGER) {
if (sub_elem->integer.value != client->addr) {
info->addr = sub_elem->integer.value;
break;
}
}
}
}
kfree(buffer.pointer);
return cpm->package.count;
}
static int acpi_i2c_check_resource(struct acpi_resource *ares, void *data)
{
u32 *addr = data;
if (ares->type == ACPI_RESOURCE_TYPE_SERIAL_BUS) {
struct acpi_resource_i2c_serialbus *sb;
sb = &ares->data.i2c_serial_bus;
if (sb->type == ACPI_RESOURCE_SERIAL_TYPE_I2C) {
if (*addr)
*addr |= (sb->slave_address << 16);
else
*addr = sb->slave_address;
}
}
return 1;
}
static int inv_mpu_process_acpi_config(struct i2c_client *client,
unsigned short *primary_addr,
unsigned short *secondary_addr)
{
const struct acpi_device_id *id;
struct acpi_device *adev;
u32 i2c_addr = 0;
LIST_HEAD(resources);
int ret;
id = acpi_match_device(client->dev.driver->acpi_match_table,
&client->dev);
if (!id)
return -ENODEV;
adev = ACPI_COMPANION(&client->dev);
if (!adev)
return -ENODEV;
ret = acpi_dev_get_resources(adev, &resources,
acpi_i2c_check_resource, &i2c_addr);
if (ret < 0)
return ret;
acpi_dev_free_resource_list(&resources);
*primary_addr = i2c_addr & 0x0000ffff;
*secondary_addr = (i2c_addr & 0xffff0000) >> 16;
return 0;
}
int inv_mpu_acpi_create_mux_client(struct inv_mpu6050_state *st)
{
st->mux_client = NULL;
if (ACPI_HANDLE(&st->client->dev)) {
struct i2c_board_info info;
struct acpi_device *adev;
int ret = -1;
adev = ACPI_COMPANION(&st->client->dev);
memset(&info, 0, sizeof(info));
dmi_check_system(inv_mpu_dev_list);
switch (matched_product_name) {
case INV_MPU_ASUS_T100TA:
ret = asus_acpi_get_sensor_info(adev, st->client,
&info);
break;
default:
break;
}
if (ret < 0) {
unsigned short primary, secondary;
ret = inv_mpu_process_acpi_config(st->client, &primary,
&secondary);
if (!ret && secondary) {
char *name;
info.addr = secondary;
strlcpy(info.type, dev_name(&adev->dev),
sizeof(info.type));
name = strchr(info.type, ':');
if (name)
*name = '\0';
strlcat(info.type, "-client",
sizeof(info.type));
} else
return 0;
}
st->mux_client = i2c_new_device(st->mux_adapter, &info);
if (!st->mux_client)
return -ENODEV;
}
return 0;
}
void inv_mpu_acpi_delete_mux_client(struct inv_mpu6050_state *st)
{
if (st->mux_client)
i2c_unregister_device(st->mux_client);
}
int inv_mpu_acpi_create_mux_client(struct inv_mpu6050_state *st)
{
return 0;
}
void inv_mpu_acpi_delete_mux_client(struct inv_mpu6050_state *st)
{
}
