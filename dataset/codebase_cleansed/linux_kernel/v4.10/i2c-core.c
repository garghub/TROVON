int i2c_transfer_trace_reg(void)
{
static_key_slow_inc(&i2c_trace_msg);
return 0;
}
void i2c_transfer_trace_unreg(void)
{
static_key_slow_dec(&i2c_trace_msg);
}
static int i2c_acpi_fill_info(struct acpi_resource *ares, void *data)
{
struct i2c_acpi_lookup *lookup = data;
struct i2c_board_info *info = lookup->info;
struct acpi_resource_i2c_serialbus *sb;
acpi_status status;
if (info->addr || ares->type != ACPI_RESOURCE_TYPE_SERIAL_BUS)
return 1;
sb = &ares->data.i2c_serial_bus;
if (sb->type != ACPI_RESOURCE_SERIAL_TYPE_I2C)
return 1;
status = acpi_get_handle(lookup->device_handle,
sb->resource_source.string_ptr,
&lookup->adapter_handle);
if (!ACPI_SUCCESS(status))
return 1;
info->addr = sb->slave_address;
lookup->speed = sb->connection_speed;
if (sb->access_mode == ACPI_I2C_10BIT_MODE)
info->flags |= I2C_CLIENT_TEN;
return 1;
}
static int i2c_acpi_do_lookup(struct acpi_device *adev,
struct i2c_acpi_lookup *lookup)
{
struct i2c_board_info *info = lookup->info;
struct list_head resource_list;
int ret;
if (acpi_bus_get_status(adev) || !adev->status.present ||
acpi_device_enumerated(adev))
return -EINVAL;
memset(info, 0, sizeof(*info));
lookup->device_handle = acpi_device_handle(adev);
INIT_LIST_HEAD(&resource_list);
ret = acpi_dev_get_resources(adev, &resource_list,
i2c_acpi_fill_info, lookup);
acpi_dev_free_resource_list(&resource_list);
if (ret < 0 || !info->addr)
return -EINVAL;
return 0;
}
static int i2c_acpi_get_info(struct acpi_device *adev,
struct i2c_board_info *info,
struct i2c_adapter *adapter,
acpi_handle *adapter_handle)
{
struct list_head resource_list;
struct resource_entry *entry;
struct i2c_acpi_lookup lookup;
int ret;
memset(&lookup, 0, sizeof(lookup));
lookup.info = info;
ret = i2c_acpi_do_lookup(adev, &lookup);
if (ret)
return ret;
if (adapter) {
if (ACPI_HANDLE(&adapter->dev) != lookup.adapter_handle)
return -ENODEV;
} else {
struct acpi_device *adapter_adev;
if (acpi_bus_get_device(lookup.adapter_handle, &adapter_adev))
return -ENODEV;
if (acpi_bus_get_status(adapter_adev) ||
!adapter_adev->status.present)
return -ENODEV;
}
info->fwnode = acpi_fwnode_handle(adev);
if (adapter_handle)
*adapter_handle = lookup.adapter_handle;
INIT_LIST_HEAD(&resource_list);
ret = acpi_dev_get_resources(adev, &resource_list, NULL, NULL);
if (ret < 0)
return -EINVAL;
resource_list_for_each_entry(entry, &resource_list) {
if (resource_type(entry->res) == IORESOURCE_IRQ) {
info->irq = entry->res->start;
break;
}
}
acpi_dev_free_resource_list(&resource_list);
strlcpy(info->type, dev_name(&adev->dev), sizeof(info->type));
return 0;
}
static void i2c_acpi_register_device(struct i2c_adapter *adapter,
struct acpi_device *adev,
struct i2c_board_info *info)
{
adev->power.flags.ignore_parent = true;
acpi_device_set_enumerated(adev);
if (!i2c_new_device(adapter, info)) {
adev->power.flags.ignore_parent = false;
dev_err(&adapter->dev,
"failed to add I2C device %s from ACPI\n",
dev_name(&adev->dev));
}
}
static acpi_status i2c_acpi_add_device(acpi_handle handle, u32 level,
void *data, void **return_value)
{
struct i2c_adapter *adapter = data;
struct acpi_device *adev;
struct i2c_board_info info;
if (acpi_bus_get_device(handle, &adev))
return AE_OK;
if (i2c_acpi_get_info(adev, &info, adapter, NULL))
return AE_OK;
i2c_acpi_register_device(adapter, adev, &info);
return AE_OK;
}
static void i2c_acpi_register_devices(struct i2c_adapter *adap)
{
acpi_status status;
if (!has_acpi_companion(&adap->dev))
return;
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
I2C_ACPI_MAX_SCAN_DEPTH,
i2c_acpi_add_device, NULL,
adap, NULL);
if (ACPI_FAILURE(status))
dev_warn(&adap->dev, "failed to enumerate I2C slaves\n");
}
static acpi_status i2c_acpi_lookup_speed(acpi_handle handle, u32 level,
void *data, void **return_value)
{
struct i2c_acpi_lookup *lookup = data;
struct acpi_device *adev;
if (acpi_bus_get_device(handle, &adev))
return AE_OK;
if (i2c_acpi_do_lookup(adev, lookup))
return AE_OK;
if (lookup->search_handle != lookup->adapter_handle)
return AE_OK;
if (lookup->speed <= lookup->min_speed)
lookup->min_speed = lookup->speed;
return AE_OK;
}
u32 i2c_acpi_find_bus_speed(struct device *dev)
{
struct i2c_acpi_lookup lookup;
struct i2c_board_info dummy;
acpi_status status;
if (!has_acpi_companion(dev))
return 0;
memset(&lookup, 0, sizeof(lookup));
lookup.search_handle = ACPI_HANDLE(dev);
lookup.min_speed = UINT_MAX;
lookup.info = &dummy;
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
I2C_ACPI_MAX_SCAN_DEPTH,
i2c_acpi_lookup_speed, NULL,
&lookup, NULL);
if (ACPI_FAILURE(status)) {
dev_warn(dev, "unable to find I2C bus speed from ACPI\n");
return 0;
}
return lookup.min_speed != UINT_MAX ? lookup.min_speed : 0;
}
static int i2c_acpi_match_adapter(struct device *dev, void *data)
{
struct i2c_adapter *adapter = i2c_verify_adapter(dev);
if (!adapter)
return 0;
return ACPI_HANDLE(dev) == (acpi_handle)data;
}
static int i2c_acpi_match_device(struct device *dev, void *data)
{
return ACPI_COMPANION(dev) == data;
}
static struct i2c_adapter *i2c_acpi_find_adapter_by_handle(acpi_handle handle)
{
struct device *dev;
dev = bus_find_device(&i2c_bus_type, NULL, handle,
i2c_acpi_match_adapter);
return dev ? i2c_verify_adapter(dev) : NULL;
}
static struct i2c_client *i2c_acpi_find_client_by_adev(struct acpi_device *adev)
{
struct device *dev;
dev = bus_find_device(&i2c_bus_type, NULL, adev, i2c_acpi_match_device);
return dev ? i2c_verify_client(dev) : NULL;
}
static int i2c_acpi_notify(struct notifier_block *nb, unsigned long value,
void *arg)
{
struct acpi_device *adev = arg;
struct i2c_board_info info;
acpi_handle adapter_handle;
struct i2c_adapter *adapter;
struct i2c_client *client;
switch (value) {
case ACPI_RECONFIG_DEVICE_ADD:
if (i2c_acpi_get_info(adev, &info, NULL, &adapter_handle))
break;
adapter = i2c_acpi_find_adapter_by_handle(adapter_handle);
if (!adapter)
break;
i2c_acpi_register_device(adapter, adev, &info);
break;
case ACPI_RECONFIG_DEVICE_REMOVE:
if (!acpi_device_enumerated(adev))
break;
client = i2c_acpi_find_client_by_adev(adev);
if (!client)
break;
i2c_unregister_device(client);
put_device(&client->dev);
break;
}
return NOTIFY_OK;
}
static inline void i2c_acpi_register_devices(struct i2c_adapter *adap) { }
static int acpi_gsb_i2c_read_bytes(struct i2c_client *client,
u8 cmd, u8 *data, u8 data_len)
{
struct i2c_msg msgs[2];
int ret;
u8 *buffer;
buffer = kzalloc(data_len, GFP_KERNEL);
if (!buffer)
return AE_NO_MEMORY;
msgs[0].addr = client->addr;
msgs[0].flags = client->flags;
msgs[0].len = 1;
msgs[0].buf = &cmd;
msgs[1].addr = client->addr;
msgs[1].flags = client->flags | I2C_M_RD;
msgs[1].len = data_len;
msgs[1].buf = buffer;
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0)
dev_err(&client->adapter->dev, "i2c read failed\n");
else
memcpy(data, buffer, data_len);
kfree(buffer);
return ret;
}
static int acpi_gsb_i2c_write_bytes(struct i2c_client *client,
u8 cmd, u8 *data, u8 data_len)
{
struct i2c_msg msgs[1];
u8 *buffer;
int ret = AE_OK;
buffer = kzalloc(data_len + 1, GFP_KERNEL);
if (!buffer)
return AE_NO_MEMORY;
buffer[0] = cmd;
memcpy(buffer + 1, data, data_len);
msgs[0].addr = client->addr;
msgs[0].flags = client->flags;
msgs[0].len = data_len + 1;
msgs[0].buf = buffer;
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0)
dev_err(&client->adapter->dev, "i2c write failed\n");
kfree(buffer);
return ret;
}
static acpi_status
i2c_acpi_space_handler(u32 function, acpi_physical_address command,
u32 bits, u64 *value64,
void *handler_context, void *region_context)
{
struct gsb_buffer *gsb = (struct gsb_buffer *)value64;
struct i2c_acpi_handler_data *data = handler_context;
struct acpi_connection_info *info = &data->info;
struct acpi_resource_i2c_serialbus *sb;
struct i2c_adapter *adapter = data->adapter;
struct i2c_client *client;
struct acpi_resource *ares;
u32 accessor_type = function >> 16;
u8 action = function & ACPI_IO_MASK;
acpi_status ret;
int status;
ret = acpi_buffer_to_resource(info->connection, info->length, &ares);
if (ACPI_FAILURE(ret))
return ret;
client = kzalloc(sizeof(*client), GFP_KERNEL);
if (!client) {
ret = AE_NO_MEMORY;
goto err;
}
if (!value64 || ares->type != ACPI_RESOURCE_TYPE_SERIAL_BUS) {
ret = AE_BAD_PARAMETER;
goto err;
}
sb = &ares->data.i2c_serial_bus;
if (sb->type != ACPI_RESOURCE_SERIAL_TYPE_I2C) {
ret = AE_BAD_PARAMETER;
goto err;
}
client->adapter = adapter;
client->addr = sb->slave_address;
if (sb->access_mode == ACPI_I2C_10BIT_MODE)
client->flags |= I2C_CLIENT_TEN;
switch (accessor_type) {
case ACPI_GSB_ACCESS_ATTRIB_SEND_RCV:
if (action == ACPI_READ) {
status = i2c_smbus_read_byte(client);
if (status >= 0) {
gsb->bdata = status;
status = 0;
}
} else {
status = i2c_smbus_write_byte(client, gsb->bdata);
}
break;
case ACPI_GSB_ACCESS_ATTRIB_BYTE:
if (action == ACPI_READ) {
status = i2c_smbus_read_byte_data(client, command);
if (status >= 0) {
gsb->bdata = status;
status = 0;
}
} else {
status = i2c_smbus_write_byte_data(client, command,
gsb->bdata);
}
break;
case ACPI_GSB_ACCESS_ATTRIB_WORD:
if (action == ACPI_READ) {
status = i2c_smbus_read_word_data(client, command);
if (status >= 0) {
gsb->wdata = status;
status = 0;
}
} else {
status = i2c_smbus_write_word_data(client, command,
gsb->wdata);
}
break;
case ACPI_GSB_ACCESS_ATTRIB_BLOCK:
if (action == ACPI_READ) {
status = i2c_smbus_read_block_data(client, command,
gsb->data);
if (status >= 0) {
gsb->len = status;
status = 0;
}
} else {
status = i2c_smbus_write_block_data(client, command,
gsb->len, gsb->data);
}
break;
case ACPI_GSB_ACCESS_ATTRIB_MULTIBYTE:
if (action == ACPI_READ) {
status = acpi_gsb_i2c_read_bytes(client, command,
gsb->data, info->access_length);
if (status > 0)
status = 0;
} else {
status = acpi_gsb_i2c_write_bytes(client, command,
gsb->data, info->access_length);
}
break;
default:
dev_warn(&adapter->dev, "protocol 0x%02x not supported for client 0x%02x\n",
accessor_type, client->addr);
ret = AE_BAD_PARAMETER;
goto err;
}
gsb->status = status;
err:
kfree(client);
ACPI_FREE(ares);
return ret;
}
static int i2c_acpi_install_space_handler(struct i2c_adapter *adapter)
{
acpi_handle handle;
struct i2c_acpi_handler_data *data;
acpi_status status;
if (!adapter->dev.parent)
return -ENODEV;
handle = ACPI_HANDLE(adapter->dev.parent);
if (!handle)
return -ENODEV;
data = kzalloc(sizeof(struct i2c_acpi_handler_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->adapter = adapter;
status = acpi_bus_attach_private_data(handle, (void *)data);
if (ACPI_FAILURE(status)) {
kfree(data);
return -ENOMEM;
}
status = acpi_install_address_space_handler(handle,
ACPI_ADR_SPACE_GSBUS,
&i2c_acpi_space_handler,
NULL,
data);
if (ACPI_FAILURE(status)) {
dev_err(&adapter->dev, "Error installing i2c space handler\n");
acpi_bus_detach_private_data(handle);
kfree(data);
return -ENOMEM;
}
acpi_walk_dep_device_list(handle);
return 0;
}
static void i2c_acpi_remove_space_handler(struct i2c_adapter *adapter)
{
acpi_handle handle;
struct i2c_acpi_handler_data *data;
acpi_status status;
if (!adapter->dev.parent)
return;
handle = ACPI_HANDLE(adapter->dev.parent);
if (!handle)
return;
acpi_remove_address_space_handler(handle,
ACPI_ADR_SPACE_GSBUS,
&i2c_acpi_space_handler);
status = acpi_bus_get_private_data(handle, (void **)&data);
if (ACPI_SUCCESS(status))
kfree(data);
acpi_bus_detach_private_data(handle);
}
static inline void i2c_acpi_remove_space_handler(struct i2c_adapter *adapter)
{ }
static inline int i2c_acpi_install_space_handler(struct i2c_adapter *adapter)
{ return 0; }
const struct i2c_device_id *i2c_match_id(const struct i2c_device_id *id,
const struct i2c_client *client)
{
if (!(id && client))
return NULL;
while (id->name[0]) {
if (strcmp(client->name, id->name) == 0)
return id;
id++;
}
return NULL;
}
static int i2c_device_match(struct device *dev, struct device_driver *drv)
{
struct i2c_client *client = i2c_verify_client(dev);
struct i2c_driver *driver;
if (i2c_of_match_device(drv->of_match_table, client))
return 1;
if (acpi_driver_match_device(dev, drv))
return 1;
driver = to_i2c_driver(drv);
if (i2c_match_id(driver->id_table, client))
return 1;
return 0;
}
static int i2c_device_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct i2c_client *client = to_i2c_client(dev);
int rc;
rc = acpi_device_uevent_modalias(dev, env);
if (rc != -ENODEV)
return rc;
return add_uevent_var(env, "MODALIAS=%s%s", I2C_MODULE_PREFIX, client->name);
}
static int get_scl_gpio_value(struct i2c_adapter *adap)
{
return gpio_get_value(adap->bus_recovery_info->scl_gpio);
}
static void set_scl_gpio_value(struct i2c_adapter *adap, int val)
{
gpio_set_value(adap->bus_recovery_info->scl_gpio, val);
}
static int get_sda_gpio_value(struct i2c_adapter *adap)
{
return gpio_get_value(adap->bus_recovery_info->sda_gpio);
}
static int i2c_get_gpios_for_recovery(struct i2c_adapter *adap)
{
struct i2c_bus_recovery_info *bri = adap->bus_recovery_info;
struct device *dev = &adap->dev;
int ret = 0;
ret = gpio_request_one(bri->scl_gpio, GPIOF_OPEN_DRAIN |
GPIOF_OUT_INIT_HIGH, "i2c-scl");
if (ret) {
dev_warn(dev, "Can't get SCL gpio: %d\n", bri->scl_gpio);
return ret;
}
if (bri->get_sda) {
if (gpio_request_one(bri->sda_gpio, GPIOF_IN, "i2c-sda")) {
dev_warn(dev, "Can't get SDA gpio: %d. Not using SDA polling\n",
bri->sda_gpio);
bri->get_sda = NULL;
}
}
return ret;
}
static void i2c_put_gpios_for_recovery(struct i2c_adapter *adap)
{
struct i2c_bus_recovery_info *bri = adap->bus_recovery_info;
if (bri->get_sda)
gpio_free(bri->sda_gpio);
gpio_free(bri->scl_gpio);
}
static int i2c_generic_recovery(struct i2c_adapter *adap)
{
struct i2c_bus_recovery_info *bri = adap->bus_recovery_info;
int i = 0, val = 1, ret = 0;
if (bri->prepare_recovery)
bri->prepare_recovery(adap);
bri->set_scl(adap, val);
ndelay(RECOVERY_NDELAY);
while (i++ < RECOVERY_CLK_CNT * 2) {
if (val) {
if (bri->get_sda && bri->get_sda(adap))
break;
if (!bri->get_scl(adap)) {
dev_err(&adap->dev,
"SCL is stuck low, exit recovery\n");
ret = -EBUSY;
break;
}
}
val = !val;
bri->set_scl(adap, val);
ndelay(RECOVERY_NDELAY);
}
if (bri->unprepare_recovery)
bri->unprepare_recovery(adap);
return ret;
}
int i2c_generic_scl_recovery(struct i2c_adapter *adap)
{
return i2c_generic_recovery(adap);
}
int i2c_generic_gpio_recovery(struct i2c_adapter *adap)
{
int ret;
ret = i2c_get_gpios_for_recovery(adap);
if (ret)
return ret;
ret = i2c_generic_recovery(adap);
i2c_put_gpios_for_recovery(adap);
return ret;
}
int i2c_recover_bus(struct i2c_adapter *adap)
{
if (!adap->bus_recovery_info)
return -EOPNOTSUPP;
dev_dbg(&adap->dev, "Trying i2c bus recovery\n");
return adap->bus_recovery_info->recover_bus(adap);
}
static void i2c_init_recovery(struct i2c_adapter *adap)
{
struct i2c_bus_recovery_info *bri = adap->bus_recovery_info;
char *err_str;
if (!bri)
return;
if (!bri->recover_bus) {
err_str = "no recover_bus() found";
goto err;
}
if (bri->recover_bus == i2c_generic_gpio_recovery) {
if (!gpio_is_valid(bri->scl_gpio)) {
err_str = "invalid SCL gpio";
goto err;
}
if (gpio_is_valid(bri->sda_gpio))
bri->get_sda = get_sda_gpio_value;
else
bri->get_sda = NULL;
bri->get_scl = get_scl_gpio_value;
bri->set_scl = set_scl_gpio_value;
} else if (bri->recover_bus == i2c_generic_scl_recovery) {
if (!bri->set_scl || !bri->get_scl) {
err_str = "no {get|set}_scl() found";
goto err;
}
}
return;
err:
dev_err(&adap->dev, "Not using recovery: %s\n", err_str);
adap->bus_recovery_info = NULL;
}
static int i2c_smbus_host_notify_to_irq(const struct i2c_client *client)
{
struct i2c_adapter *adap = client->adapter;
unsigned int irq;
if (!adap->host_notify_domain)
return -ENXIO;
if (client->flags & I2C_CLIENT_TEN)
return -EINVAL;
irq = irq_find_mapping(adap->host_notify_domain, client->addr);
if (!irq)
irq = irq_create_mapping(adap->host_notify_domain,
client->addr);
return irq > 0 ? irq : -ENXIO;
}
static int i2c_device_probe(struct device *dev)
{
struct i2c_client *client = i2c_verify_client(dev);
struct i2c_driver *driver;
int status;
if (!client)
return 0;
if (!client->irq) {
int irq = -ENOENT;
if (client->flags & I2C_CLIENT_HOST_NOTIFY) {
dev_dbg(dev, "Using Host Notify IRQ\n");
irq = i2c_smbus_host_notify_to_irq(client);
} else if (dev->of_node) {
irq = of_irq_get_byname(dev->of_node, "irq");
if (irq == -EINVAL || irq == -ENODATA)
irq = of_irq_get(dev->of_node, 0);
} else if (ACPI_COMPANION(dev)) {
irq = acpi_dev_gpio_irq_get(ACPI_COMPANION(dev), 0);
}
if (irq == -EPROBE_DEFER)
return irq;
if (irq < 0)
irq = 0;
client->irq = irq;
}
driver = to_i2c_driver(dev->driver);
if (!driver->id_table &&
!i2c_of_match_device(dev->driver->of_match_table, client))
return -ENODEV;
if (client->flags & I2C_CLIENT_WAKE) {
int wakeirq = -ENOENT;
if (dev->of_node) {
wakeirq = of_irq_get_byname(dev->of_node, "wakeup");
if (wakeirq == -EPROBE_DEFER)
return wakeirq;
}
device_init_wakeup(&client->dev, true);
if (wakeirq > 0 && wakeirq != client->irq)
status = dev_pm_set_dedicated_wake_irq(dev, wakeirq);
else if (client->irq > 0)
status = dev_pm_set_wake_irq(dev, client->irq);
else
status = 0;
if (status)
dev_warn(&client->dev, "failed to set up wakeup irq\n");
}
dev_dbg(dev, "probe\n");
status = of_clk_set_defaults(dev->of_node, false);
if (status < 0)
goto err_clear_wakeup_irq;
status = dev_pm_domain_attach(&client->dev, true);
if (status == -EPROBE_DEFER)
goto err_clear_wakeup_irq;
if (driver->probe_new)
status = driver->probe_new(client);
else if (driver->probe)
status = driver->probe(client,
i2c_match_id(driver->id_table, client));
else
status = -EINVAL;
if (status)
goto err_detach_pm_domain;
return 0;
err_detach_pm_domain:
dev_pm_domain_detach(&client->dev, true);
err_clear_wakeup_irq:
dev_pm_clear_wake_irq(&client->dev);
device_init_wakeup(&client->dev, false);
return status;
}
static int i2c_device_remove(struct device *dev)
{
struct i2c_client *client = i2c_verify_client(dev);
struct i2c_driver *driver;
int status = 0;
if (!client || !dev->driver)
return 0;
driver = to_i2c_driver(dev->driver);
if (driver->remove) {
dev_dbg(dev, "remove\n");
status = driver->remove(client);
}
dev_pm_domain_detach(&client->dev, true);
dev_pm_clear_wake_irq(&client->dev);
device_init_wakeup(&client->dev, false);
return status;
}
static void i2c_device_shutdown(struct device *dev)
{
struct i2c_client *client = i2c_verify_client(dev);
struct i2c_driver *driver;
if (!client || !dev->driver)
return;
driver = to_i2c_driver(dev->driver);
if (driver->shutdown)
driver->shutdown(client);
}
static void i2c_client_dev_release(struct device *dev)
{
kfree(to_i2c_client(dev));
}
static ssize_t
show_name(struct device *dev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", dev->type == &i2c_client_type ?
to_i2c_client(dev)->name : to_i2c_adapter(dev)->name);
}
static ssize_t
show_modalias(struct device *dev, struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
int len;
len = acpi_device_modalias(dev, buf, PAGE_SIZE -1);
if (len != -ENODEV)
return len;
return sprintf(buf, "%s%s\n", I2C_MODULE_PREFIX, client->name);
}
struct i2c_client *i2c_verify_client(struct device *dev)
{
return (dev->type == &i2c_client_type)
? to_i2c_client(dev)
: NULL;
}
static unsigned short i2c_encode_flags_to_addr(struct i2c_client *client)
{
unsigned short addr = client->addr;
if (client->flags & I2C_CLIENT_TEN)
addr |= I2C_ADDR_OFFSET_TEN_BIT;
if (client->flags & I2C_CLIENT_SLAVE)
addr |= I2C_ADDR_OFFSET_SLAVE;
return addr;
}
static int i2c_check_addr_validity(unsigned addr, unsigned short flags)
{
if (flags & I2C_CLIENT_TEN) {
if (addr > 0x3ff)
return -EINVAL;
} else {
if (addr == 0x00 || addr > 0x7f)
return -EINVAL;
}
return 0;
}
static int i2c_check_7bit_addr_validity_strict(unsigned short addr)
{
if (addr < 0x08 || addr > 0x77)
return -EINVAL;
return 0;
}
static int __i2c_check_addr_busy(struct device *dev, void *addrp)
{
struct i2c_client *client = i2c_verify_client(dev);
int addr = *(int *)addrp;
if (client && i2c_encode_flags_to_addr(client) == addr)
return -EBUSY;
return 0;
}
static int i2c_check_mux_parents(struct i2c_adapter *adapter, int addr)
{
struct i2c_adapter *parent = i2c_parent_is_i2c_adapter(adapter);
int result;
result = device_for_each_child(&adapter->dev, &addr,
__i2c_check_addr_busy);
if (!result && parent)
result = i2c_check_mux_parents(parent, addr);
return result;
}
static int i2c_check_mux_children(struct device *dev, void *addrp)
{
int result;
if (dev->type == &i2c_adapter_type)
result = device_for_each_child(dev, addrp,
i2c_check_mux_children);
else
result = __i2c_check_addr_busy(dev, addrp);
return result;
}
static int i2c_check_addr_busy(struct i2c_adapter *adapter, int addr)
{
struct i2c_adapter *parent = i2c_parent_is_i2c_adapter(adapter);
int result = 0;
if (parent)
result = i2c_check_mux_parents(parent, addr);
if (!result)
result = device_for_each_child(&adapter->dev, &addr,
i2c_check_mux_children);
return result;
}
static void i2c_adapter_lock_bus(struct i2c_adapter *adapter,
unsigned int flags)
{
rt_mutex_lock(&adapter->bus_lock);
}
static int i2c_adapter_trylock_bus(struct i2c_adapter *adapter,
unsigned int flags)
{
return rt_mutex_trylock(&adapter->bus_lock);
}
static void i2c_adapter_unlock_bus(struct i2c_adapter *adapter,
unsigned int flags)
{
rt_mutex_unlock(&adapter->bus_lock);
}
static void i2c_dev_set_name(struct i2c_adapter *adap,
struct i2c_client *client)
{
struct acpi_device *adev = ACPI_COMPANION(&client->dev);
if (adev) {
dev_set_name(&client->dev, "i2c-%s", acpi_dev_name(adev));
return;
}
dev_set_name(&client->dev, "%d-%04x", i2c_adapter_id(adap),
i2c_encode_flags_to_addr(client));
}
struct i2c_client *
i2c_new_device(struct i2c_adapter *adap, struct i2c_board_info const *info)
{
struct i2c_client *client;
int status;
client = kzalloc(sizeof *client, GFP_KERNEL);
if (!client)
return NULL;
client->adapter = adap;
client->dev.platform_data = info->platform_data;
if (info->archdata)
client->dev.archdata = *info->archdata;
client->flags = info->flags;
client->addr = info->addr;
client->irq = info->irq;
strlcpy(client->name, info->type, sizeof(client->name));
status = i2c_check_addr_validity(client->addr, client->flags);
if (status) {
dev_err(&adap->dev, "Invalid %d-bit I2C address 0x%02hx\n",
client->flags & I2C_CLIENT_TEN ? 10 : 7, client->addr);
goto out_err_silent;
}
status = i2c_check_addr_busy(adap, i2c_encode_flags_to_addr(client));
if (status)
goto out_err;
client->dev.parent = &client->adapter->dev;
client->dev.bus = &i2c_bus_type;
client->dev.type = &i2c_client_type;
client->dev.of_node = info->of_node;
client->dev.fwnode = info->fwnode;
i2c_dev_set_name(adap, client);
status = device_register(&client->dev);
if (status)
goto out_err;
dev_dbg(&adap->dev, "client [%s] registered with bus id %s\n",
client->name, dev_name(&client->dev));
return client;
out_err:
dev_err(&adap->dev,
"Failed to register i2c client %s at 0x%02x (%d)\n",
client->name, client->addr, status);
out_err_silent:
kfree(client);
return NULL;
}
void i2c_unregister_device(struct i2c_client *client)
{
if (client->dev.of_node)
of_node_clear_flag(client->dev.of_node, OF_POPULATED);
if (ACPI_COMPANION(&client->dev))
acpi_device_clear_enumerated(ACPI_COMPANION(&client->dev));
device_unregister(&client->dev);
}
static int dummy_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return 0;
}
static int dummy_remove(struct i2c_client *client)
{
return 0;
}
struct i2c_client *i2c_new_dummy(struct i2c_adapter *adapter, u16 address)
{
struct i2c_board_info info = {
I2C_BOARD_INFO("dummy", address),
};
return i2c_new_device(adapter, &info);
}
struct i2c_client *i2c_new_secondary_device(struct i2c_client *client,
const char *name,
u16 default_addr)
{
struct device_node *np = client->dev.of_node;
u32 addr = default_addr;
int i;
if (np) {
i = of_property_match_string(np, "reg-names", name);
if (i >= 0)
of_property_read_u32_index(np, "reg", i, &addr);
}
dev_dbg(&client->adapter->dev, "Address for %s : 0x%x\n", name, addr);
return i2c_new_dummy(client->adapter, addr);
}
static void i2c_adapter_dev_release(struct device *dev)
{
struct i2c_adapter *adap = to_i2c_adapter(dev);
complete(&adap->dev_released);
}
unsigned int i2c_adapter_depth(struct i2c_adapter *adapter)
{
unsigned int depth = 0;
while ((adapter = i2c_parent_is_i2c_adapter(adapter)))
depth++;
WARN_ONCE(depth >= MAX_LOCKDEP_SUBCLASSES,
"adapter depth exceeds lockdep subclass limit\n");
return depth;
}
static ssize_t
i2c_sysfs_new_device(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_adapter *adap = to_i2c_adapter(dev);
struct i2c_board_info info;
struct i2c_client *client;
char *blank, end;
int res;
memset(&info, 0, sizeof(struct i2c_board_info));
blank = strchr(buf, ' ');
if (!blank) {
dev_err(dev, "%s: Missing parameters\n", "new_device");
return -EINVAL;
}
if (blank - buf > I2C_NAME_SIZE - 1) {
dev_err(dev, "%s: Invalid device name\n", "new_device");
return -EINVAL;
}
memcpy(info.type, buf, blank - buf);
res = sscanf(++blank, "%hi%c", &info.addr, &end);
if (res < 1) {
dev_err(dev, "%s: Can't parse I2C address\n", "new_device");
return -EINVAL;
}
if (res > 1 && end != '\n') {
dev_err(dev, "%s: Extra parameters\n", "new_device");
return -EINVAL;
}
if ((info.addr & I2C_ADDR_OFFSET_TEN_BIT) == I2C_ADDR_OFFSET_TEN_BIT) {
info.addr &= ~I2C_ADDR_OFFSET_TEN_BIT;
info.flags |= I2C_CLIENT_TEN;
}
if (info.addr & I2C_ADDR_OFFSET_SLAVE) {
info.addr &= ~I2C_ADDR_OFFSET_SLAVE;
info.flags |= I2C_CLIENT_SLAVE;
}
client = i2c_new_device(adap, &info);
if (!client)
return -EINVAL;
mutex_lock(&adap->userspace_clients_lock);
list_add_tail(&client->detected, &adap->userspace_clients);
mutex_unlock(&adap->userspace_clients_lock);
dev_info(dev, "%s: Instantiated device %s at 0x%02hx\n", "new_device",
info.type, info.addr);
return count;
}
static ssize_t
i2c_sysfs_delete_device(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_adapter *adap = to_i2c_adapter(dev);
struct i2c_client *client, *next;
unsigned short addr;
char end;
int res;
res = sscanf(buf, "%hi%c", &addr, &end);
if (res < 1) {
dev_err(dev, "%s: Can't parse I2C address\n", "delete_device");
return -EINVAL;
}
if (res > 1 && end != '\n') {
dev_err(dev, "%s: Extra parameters\n", "delete_device");
return -EINVAL;
}
res = -ENOENT;
mutex_lock_nested(&adap->userspace_clients_lock,
i2c_adapter_depth(adap));
list_for_each_entry_safe(client, next, &adap->userspace_clients,
detected) {
if (i2c_encode_flags_to_addr(client) == addr) {
dev_info(dev, "%s: Deleting device %s at 0x%02hx\n",
"delete_device", client->name, client->addr);
list_del(&client->detected);
i2c_unregister_device(client);
res = count;
break;
}
}
mutex_unlock(&adap->userspace_clients_lock);
if (res < 0)
dev_err(dev, "%s: Can't find device in list\n",
"delete_device");
return res;
}
struct i2c_adapter *i2c_verify_adapter(struct device *dev)
{
return (dev->type == &i2c_adapter_type)
? to_i2c_adapter(dev)
: NULL;
}
static void i2c_scan_static_board_info(struct i2c_adapter *adapter)
{
struct i2c_devinfo *devinfo;
down_read(&__i2c_board_lock);
list_for_each_entry(devinfo, &__i2c_board_list, list) {
if (devinfo->busnum == adapter->nr
&& !i2c_new_device(adapter,
&devinfo->board_info))
dev_err(&adapter->dev,
"Can't create device at 0x%02x\n",
devinfo->board_info.addr);
}
up_read(&__i2c_board_lock);
}
static struct i2c_client *of_i2c_register_device(struct i2c_adapter *adap,
struct device_node *node)
{
struct i2c_client *result;
struct i2c_board_info info = {};
struct dev_archdata dev_ad = {};
const __be32 *addr_be;
u32 addr;
int len;
dev_dbg(&adap->dev, "of_i2c: register %s\n", node->full_name);
if (of_modalias_node(node, info.type, sizeof(info.type)) < 0) {
dev_err(&adap->dev, "of_i2c: modalias failure on %s\n",
node->full_name);
return ERR_PTR(-EINVAL);
}
addr_be = of_get_property(node, "reg", &len);
if (!addr_be || (len < sizeof(*addr_be))) {
dev_err(&adap->dev, "of_i2c: invalid reg on %s\n",
node->full_name);
return ERR_PTR(-EINVAL);
}
addr = be32_to_cpup(addr_be);
if (addr & I2C_TEN_BIT_ADDRESS) {
addr &= ~I2C_TEN_BIT_ADDRESS;
info.flags |= I2C_CLIENT_TEN;
}
if (addr & I2C_OWN_SLAVE_ADDRESS) {
addr &= ~I2C_OWN_SLAVE_ADDRESS;
info.flags |= I2C_CLIENT_SLAVE;
}
if (i2c_check_addr_validity(addr, info.flags)) {
dev_err(&adap->dev, "of_i2c: invalid addr=%x on %s\n",
addr, node->full_name);
return ERR_PTR(-EINVAL);
}
info.addr = addr;
info.of_node = of_node_get(node);
info.archdata = &dev_ad;
if (of_property_read_bool(node, "host-notify"))
info.flags |= I2C_CLIENT_HOST_NOTIFY;
if (of_get_property(node, "wakeup-source", NULL))
info.flags |= I2C_CLIENT_WAKE;
result = i2c_new_device(adap, &info);
if (result == NULL) {
dev_err(&adap->dev, "of_i2c: Failure registering %s\n",
node->full_name);
of_node_put(node);
return ERR_PTR(-EINVAL);
}
return result;
}
static void of_i2c_register_devices(struct i2c_adapter *adap)
{
struct device_node *bus, *node;
struct i2c_client *client;
if (!adap->dev.of_node)
return;
dev_dbg(&adap->dev, "of_i2c: walking child nodes\n");
bus = of_get_child_by_name(adap->dev.of_node, "i2c-bus");
if (!bus)
bus = of_node_get(adap->dev.of_node);
for_each_available_child_of_node(bus, node) {
if (of_node_test_and_set_flag(node, OF_POPULATED))
continue;
client = of_i2c_register_device(adap, node);
if (IS_ERR(client)) {
dev_warn(&adap->dev,
"Failed to create I2C device for %s\n",
node->full_name);
of_node_clear_flag(node, OF_POPULATED);
}
}
of_node_put(bus);
}
static int of_dev_node_match(struct device *dev, void *data)
{
return dev->of_node == data;
}
struct i2c_client *of_find_i2c_device_by_node(struct device_node *node)
{
struct device *dev;
struct i2c_client *client;
dev = bus_find_device(&i2c_bus_type, NULL, node, of_dev_node_match);
if (!dev)
return NULL;
client = i2c_verify_client(dev);
if (!client)
put_device(dev);
return client;
}
struct i2c_adapter *of_find_i2c_adapter_by_node(struct device_node *node)
{
struct device *dev;
struct i2c_adapter *adapter;
dev = bus_find_device(&i2c_bus_type, NULL, node, of_dev_node_match);
if (!dev)
return NULL;
adapter = i2c_verify_adapter(dev);
if (!adapter)
put_device(dev);
return adapter;
}
struct i2c_adapter *of_get_i2c_adapter_by_node(struct device_node *node)
{
struct i2c_adapter *adapter;
adapter = of_find_i2c_adapter_by_node(node);
if (!adapter)
return NULL;
if (!try_module_get(adapter->owner)) {
put_device(&adapter->dev);
adapter = NULL;
}
return adapter;
}
static const struct of_device_id*
i2c_of_match_device_sysfs(const struct of_device_id *matches,
struct i2c_client *client)
{
const char *name;
for (; matches->compatible[0]; matches++) {
if (sysfs_streq(client->name, matches->compatible))
return matches;
name = strchr(matches->compatible, ',');
if (!name)
name = matches->compatible;
else
name++;
if (sysfs_streq(client->name, name))
return matches;
}
return NULL;
}
const struct of_device_id
*i2c_of_match_device(const struct of_device_id *matches,
struct i2c_client *client)
{
const struct of_device_id *match;
if (!(client && matches))
return NULL;
match = of_match_device(matches, &client->dev);
if (match)
return match;
return i2c_of_match_device_sysfs(matches, client);
}
static void of_i2c_register_devices(struct i2c_adapter *adap) { }
static int i2c_do_add_adapter(struct i2c_driver *driver,
struct i2c_adapter *adap)
{
i2c_detect(adap, driver);
if (driver->attach_adapter) {
dev_warn(&adap->dev, "%s: attach_adapter method is deprecated\n",
driver->driver.name);
dev_warn(&adap->dev,
"Please use another way to instantiate your i2c_client\n");
driver->attach_adapter(adap);
}
return 0;
}
static int __process_new_adapter(struct device_driver *d, void *data)
{
return i2c_do_add_adapter(to_i2c_driver(d), data);
}
static void i2c_host_notify_irq_teardown(struct i2c_adapter *adap)
{
struct irq_domain *domain = adap->host_notify_domain;
irq_hw_number_t hwirq;
if (!domain)
return;
for (hwirq = 0 ; hwirq < I2C_ADDR_7BITS_COUNT ; hwirq++)
irq_dispose_mapping(irq_find_mapping(domain, hwirq));
irq_domain_remove(domain);
adap->host_notify_domain = NULL;
}
static int i2c_host_notify_irq_map(struct irq_domain *h,
unsigned int virq,
irq_hw_number_t hw_irq_num)
{
irq_set_chip_and_handler(virq, &dummy_irq_chip, handle_simple_irq);
return 0;
}
static int i2c_setup_host_notify_irq_domain(struct i2c_adapter *adap)
{
struct irq_domain *domain;
if (!i2c_check_functionality(adap, I2C_FUNC_SMBUS_HOST_NOTIFY))
return 0;
domain = irq_domain_create_linear(adap->dev.fwnode,
I2C_ADDR_7BITS_COUNT,
&i2c_host_notify_irq_ops, adap);
if (!domain)
return -ENOMEM;
adap->host_notify_domain = domain;
return 0;
}
int i2c_handle_smbus_host_notify(struct i2c_adapter *adap, unsigned short addr)
{
int irq;
if (!adap)
return -EINVAL;
irq = irq_find_mapping(adap->host_notify_domain, addr);
if (irq <= 0)
return -ENXIO;
generic_handle_irq(irq);
return 0;
}
static int i2c_register_adapter(struct i2c_adapter *adap)
{
int res = -EINVAL;
if (WARN_ON(!is_registered)) {
res = -EAGAIN;
goto out_list;
}
if (WARN(!adap->name[0], "i2c adapter has no name"))
goto out_list;
if (!adap->algo) {
pr_err("adapter '%s': no algo supplied!\n", adap->name);
goto out_list;
}
if (!adap->lock_ops)
adap->lock_ops = &i2c_adapter_lock_ops;
rt_mutex_init(&adap->bus_lock);
rt_mutex_init(&adap->mux_lock);
mutex_init(&adap->userspace_clients_lock);
INIT_LIST_HEAD(&adap->userspace_clients);
if (adap->timeout == 0)
adap->timeout = HZ;
res = i2c_setup_host_notify_irq_domain(adap);
if (res) {
pr_err("adapter '%s': can't create Host Notify IRQs (%d)\n",
adap->name, res);
goto out_list;
}
dev_set_name(&adap->dev, "i2c-%d", adap->nr);
adap->dev.bus = &i2c_bus_type;
adap->dev.type = &i2c_adapter_type;
res = device_register(&adap->dev);
if (res) {
pr_err("adapter '%s': can't register device (%d)\n", adap->name, res);
goto out_list;
}
dev_dbg(&adap->dev, "adapter [%s] registered\n", adap->name);
pm_runtime_no_callbacks(&adap->dev);
pm_suspend_ignore_children(&adap->dev, true);
pm_runtime_enable(&adap->dev);
#ifdef CONFIG_I2C_COMPAT
res = class_compat_create_link(i2c_adapter_compat_class, &adap->dev,
adap->dev.parent);
if (res)
dev_warn(&adap->dev,
"Failed to create compatibility class link\n");
#endif
i2c_init_recovery(adap);
of_i2c_register_devices(adap);
i2c_acpi_register_devices(adap);
i2c_acpi_install_space_handler(adap);
if (adap->nr < __i2c_first_dynamic_bus_num)
i2c_scan_static_board_info(adap);
mutex_lock(&core_lock);
bus_for_each_drv(&i2c_bus_type, NULL, adap, __process_new_adapter);
mutex_unlock(&core_lock);
return 0;
out_list:
mutex_lock(&core_lock);
idr_remove(&i2c_adapter_idr, adap->nr);
mutex_unlock(&core_lock);
return res;
}
static int __i2c_add_numbered_adapter(struct i2c_adapter *adap)
{
int id;
mutex_lock(&core_lock);
id = idr_alloc(&i2c_adapter_idr, adap, adap->nr, adap->nr + 1, GFP_KERNEL);
mutex_unlock(&core_lock);
if (WARN(id < 0, "couldn't get idr"))
return id == -ENOSPC ? -EBUSY : id;
return i2c_register_adapter(adap);
}
int i2c_add_adapter(struct i2c_adapter *adapter)
{
struct device *dev = &adapter->dev;
int id;
if (dev->of_node) {
id = of_alias_get_id(dev->of_node, "i2c");
if (id >= 0) {
adapter->nr = id;
return __i2c_add_numbered_adapter(adapter);
}
}
mutex_lock(&core_lock);
id = idr_alloc(&i2c_adapter_idr, adapter,
__i2c_first_dynamic_bus_num, 0, GFP_KERNEL);
mutex_unlock(&core_lock);
if (WARN(id < 0, "couldn't get idr"))
return id;
adapter->nr = id;
return i2c_register_adapter(adapter);
}
int i2c_add_numbered_adapter(struct i2c_adapter *adap)
{
if (adap->nr == -1)
return i2c_add_adapter(adap);
return __i2c_add_numbered_adapter(adap);
}
static void i2c_do_del_adapter(struct i2c_driver *driver,
struct i2c_adapter *adapter)
{
struct i2c_client *client, *_n;
list_for_each_entry_safe(client, _n, &driver->clients, detected) {
if (client->adapter == adapter) {
dev_dbg(&adapter->dev, "Removing %s at 0x%x\n",
client->name, client->addr);
list_del(&client->detected);
i2c_unregister_device(client);
}
}
}
static int __unregister_client(struct device *dev, void *dummy)
{
struct i2c_client *client = i2c_verify_client(dev);
if (client && strcmp(client->name, "dummy"))
i2c_unregister_device(client);
return 0;
}
static int __unregister_dummy(struct device *dev, void *dummy)
{
struct i2c_client *client = i2c_verify_client(dev);
if (client)
i2c_unregister_device(client);
return 0;
}
static int __process_removed_adapter(struct device_driver *d, void *data)
{
i2c_do_del_adapter(to_i2c_driver(d), data);
return 0;
}
void i2c_del_adapter(struct i2c_adapter *adap)
{
struct i2c_adapter *found;
struct i2c_client *client, *next;
mutex_lock(&core_lock);
found = idr_find(&i2c_adapter_idr, adap->nr);
mutex_unlock(&core_lock);
if (found != adap) {
pr_debug("attempting to delete unregistered adapter [%s]\n", adap->name);
return;
}
i2c_acpi_remove_space_handler(adap);
mutex_lock(&core_lock);
bus_for_each_drv(&i2c_bus_type, NULL, adap,
__process_removed_adapter);
mutex_unlock(&core_lock);
mutex_lock_nested(&adap->userspace_clients_lock,
i2c_adapter_depth(adap));
list_for_each_entry_safe(client, next, &adap->userspace_clients,
detected) {
dev_dbg(&adap->dev, "Removing %s at 0x%x\n", client->name,
client->addr);
list_del(&client->detected);
i2c_unregister_device(client);
}
mutex_unlock(&adap->userspace_clients_lock);
device_for_each_child(&adap->dev, NULL, __unregister_client);
device_for_each_child(&adap->dev, NULL, __unregister_dummy);
#ifdef CONFIG_I2C_COMPAT
class_compat_remove_link(i2c_adapter_compat_class, &adap->dev,
adap->dev.parent);
#endif
dev_dbg(&adap->dev, "adapter [%s] unregistered\n", adap->name);
pm_runtime_disable(&adap->dev);
i2c_host_notify_irq_teardown(adap);
init_completion(&adap->dev_released);
device_unregister(&adap->dev);
wait_for_completion(&adap->dev_released);
mutex_lock(&core_lock);
idr_remove(&i2c_adapter_idr, adap->nr);
mutex_unlock(&core_lock);
memset(&adap->dev, 0, sizeof(adap->dev));
}
void i2c_parse_fw_timings(struct device *dev, struct i2c_timings *t, bool use_defaults)
{
int ret;
memset(t, 0, sizeof(*t));
ret = device_property_read_u32(dev, "clock-frequency", &t->bus_freq_hz);
if (ret && use_defaults)
t->bus_freq_hz = 100000;
ret = device_property_read_u32(dev, "i2c-scl-rising-time-ns", &t->scl_rise_ns);
if (ret && use_defaults) {
if (t->bus_freq_hz <= 100000)
t->scl_rise_ns = 1000;
else if (t->bus_freq_hz <= 400000)
t->scl_rise_ns = 300;
else
t->scl_rise_ns = 120;
}
ret = device_property_read_u32(dev, "i2c-scl-falling-time-ns", &t->scl_fall_ns);
if (ret && use_defaults) {
if (t->bus_freq_hz <= 400000)
t->scl_fall_ns = 300;
else
t->scl_fall_ns = 120;
}
device_property_read_u32(dev, "i2c-scl-internal-delay-ns", &t->scl_int_delay_ns);
ret = device_property_read_u32(dev, "i2c-sda-falling-time-ns", &t->sda_fall_ns);
if (ret && use_defaults)
t->sda_fall_ns = t->scl_fall_ns;
}
int i2c_for_each_dev(void *data, int (*fn)(struct device *, void *))
{
int res;
mutex_lock(&core_lock);
res = bus_for_each_dev(&i2c_bus_type, NULL, data, fn);
mutex_unlock(&core_lock);
return res;
}
static int __process_new_driver(struct device *dev, void *data)
{
if (dev->type != &i2c_adapter_type)
return 0;
return i2c_do_add_adapter(data, to_i2c_adapter(dev));
}
int i2c_register_driver(struct module *owner, struct i2c_driver *driver)
{
int res;
if (WARN_ON(!is_registered))
return -EAGAIN;
driver->driver.owner = owner;
driver->driver.bus = &i2c_bus_type;
INIT_LIST_HEAD(&driver->clients);
res = driver_register(&driver->driver);
if (res)
return res;
pr_debug("driver [%s] registered\n", driver->driver.name);
i2c_for_each_dev(driver, __process_new_driver);
return 0;
}
static int __process_removed_driver(struct device *dev, void *data)
{
if (dev->type == &i2c_adapter_type)
i2c_do_del_adapter(data, to_i2c_adapter(dev));
return 0;
}
void i2c_del_driver(struct i2c_driver *driver)
{
i2c_for_each_dev(driver, __process_removed_driver);
driver_unregister(&driver->driver);
pr_debug("driver [%s] unregistered\n", driver->driver.name);
}
struct i2c_client *i2c_use_client(struct i2c_client *client)
{
if (client && get_device(&client->dev))
return client;
return NULL;
}
void i2c_release_client(struct i2c_client *client)
{
if (client)
put_device(&client->dev);
}
static int i2c_cmd(struct device *dev, void *_arg)
{
struct i2c_client *client = i2c_verify_client(dev);
struct i2c_cmd_arg *arg = _arg;
struct i2c_driver *driver;
if (!client || !client->dev.driver)
return 0;
driver = to_i2c_driver(client->dev.driver);
if (driver->command)
driver->command(client, arg->cmd, arg->arg);
return 0;
}
void i2c_clients_command(struct i2c_adapter *adap, unsigned int cmd, void *arg)
{
struct i2c_cmd_arg cmd_arg;
cmd_arg.cmd = cmd;
cmd_arg.arg = arg;
device_for_each_child(&adap->dev, &cmd_arg, i2c_cmd);
}
static int of_i2c_notify(struct notifier_block *nb, unsigned long action,
void *arg)
{
struct of_reconfig_data *rd = arg;
struct i2c_adapter *adap;
struct i2c_client *client;
switch (of_reconfig_get_state_change(action, rd)) {
case OF_RECONFIG_CHANGE_ADD:
adap = of_find_i2c_adapter_by_node(rd->dn->parent);
if (adap == NULL)
return NOTIFY_OK;
if (of_node_test_and_set_flag(rd->dn, OF_POPULATED)) {
put_device(&adap->dev);
return NOTIFY_OK;
}
client = of_i2c_register_device(adap, rd->dn);
put_device(&adap->dev);
if (IS_ERR(client)) {
dev_err(&adap->dev, "failed to create client for '%s'\n",
rd->dn->full_name);
of_node_clear_flag(rd->dn, OF_POPULATED);
return notifier_from_errno(PTR_ERR(client));
}
break;
case OF_RECONFIG_CHANGE_REMOVE:
if (!of_node_check_flag(rd->dn, OF_POPULATED))
return NOTIFY_OK;
client = of_find_i2c_device_by_node(rd->dn);
if (client == NULL)
return NOTIFY_OK;
i2c_unregister_device(client);
put_device(&client->dev);
break;
}
return NOTIFY_OK;
}
static int __init i2c_init(void)
{
int retval;
retval = of_alias_get_highest_id("i2c");
down_write(&__i2c_board_lock);
if (retval >= __i2c_first_dynamic_bus_num)
__i2c_first_dynamic_bus_num = retval + 1;
up_write(&__i2c_board_lock);
retval = bus_register(&i2c_bus_type);
if (retval)
return retval;
is_registered = true;
#ifdef CONFIG_I2C_COMPAT
i2c_adapter_compat_class = class_compat_register("i2c-adapter");
if (!i2c_adapter_compat_class) {
retval = -ENOMEM;
goto bus_err;
}
#endif
retval = i2c_add_driver(&dummy_driver);
if (retval)
goto class_err;
if (IS_ENABLED(CONFIG_OF_DYNAMIC))
WARN_ON(of_reconfig_notifier_register(&i2c_of_notifier));
if (IS_ENABLED(CONFIG_ACPI))
WARN_ON(acpi_reconfig_notifier_register(&i2c_acpi_notifier));
return 0;
class_err:
#ifdef CONFIG_I2C_COMPAT
class_compat_unregister(i2c_adapter_compat_class);
bus_err:
#endif
is_registered = false;
bus_unregister(&i2c_bus_type);
return retval;
}
static void __exit i2c_exit(void)
{
if (IS_ENABLED(CONFIG_ACPI))
WARN_ON(acpi_reconfig_notifier_unregister(&i2c_acpi_notifier));
if (IS_ENABLED(CONFIG_OF_DYNAMIC))
WARN_ON(of_reconfig_notifier_unregister(&i2c_of_notifier));
i2c_del_driver(&dummy_driver);
#ifdef CONFIG_I2C_COMPAT
class_compat_unregister(i2c_adapter_compat_class);
#endif
bus_unregister(&i2c_bus_type);
tracepoint_synchronize_unregister();
}
static int i2c_quirk_error(struct i2c_adapter *adap, struct i2c_msg *msg, char *err_msg)
{
dev_err_ratelimited(&adap->dev, "adapter quirk: %s (addr 0x%04x, size %u, %s)\n",
err_msg, msg->addr, msg->len,
msg->flags & I2C_M_RD ? "read" : "write");
return -EOPNOTSUPP;
}
static int i2c_check_for_quirks(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
const struct i2c_adapter_quirks *q = adap->quirks;
int max_num = q->max_num_msgs, i;
bool do_len_check = true;
if (q->flags & I2C_AQ_COMB) {
max_num = 2;
if (num == 2) {
if (q->flags & I2C_AQ_COMB_WRITE_FIRST && msgs[0].flags & I2C_M_RD)
return i2c_quirk_error(adap, &msgs[0], "1st comb msg must be write");
if (q->flags & I2C_AQ_COMB_READ_SECOND && !(msgs[1].flags & I2C_M_RD))
return i2c_quirk_error(adap, &msgs[1], "2nd comb msg must be read");
if (q->flags & I2C_AQ_COMB_SAME_ADDR && msgs[0].addr != msgs[1].addr)
return i2c_quirk_error(adap, &msgs[0], "comb msg only to same addr");
if (i2c_quirk_exceeded(msgs[0].len, q->max_comb_1st_msg_len))
return i2c_quirk_error(adap, &msgs[0], "msg too long");
if (i2c_quirk_exceeded(msgs[1].len, q->max_comb_2nd_msg_len))
return i2c_quirk_error(adap, &msgs[1], "msg too long");
do_len_check = false;
}
}
if (i2c_quirk_exceeded(num, max_num))
return i2c_quirk_error(adap, &msgs[0], "too many messages");
for (i = 0; i < num; i++) {
u16 len = msgs[i].len;
if (msgs[i].flags & I2C_M_RD) {
if (do_len_check && i2c_quirk_exceeded(len, q->max_read_len))
return i2c_quirk_error(adap, &msgs[i], "msg too long");
} else {
if (do_len_check && i2c_quirk_exceeded(len, q->max_write_len))
return i2c_quirk_error(adap, &msgs[i], "msg too long");
}
}
return 0;
}
int __i2c_transfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
unsigned long orig_jiffies;
int ret, try;
if (adap->quirks && i2c_check_for_quirks(adap, msgs, num))
return -EOPNOTSUPP;
if (static_key_false(&i2c_trace_msg)) {
int i;
for (i = 0; i < num; i++)
if (msgs[i].flags & I2C_M_RD)
trace_i2c_read(adap, &msgs[i], i);
else
trace_i2c_write(adap, &msgs[i], i);
}
orig_jiffies = jiffies;
for (ret = 0, try = 0; try <= adap->retries; try++) {
ret = adap->algo->master_xfer(adap, msgs, num);
if (ret != -EAGAIN)
break;
if (time_after(jiffies, orig_jiffies + adap->timeout))
break;
}
if (static_key_false(&i2c_trace_msg)) {
int i;
for (i = 0; i < ret; i++)
if (msgs[i].flags & I2C_M_RD)
trace_i2c_reply(adap, &msgs[i], i);
trace_i2c_result(adap, i, ret);
}
return ret;
}
int i2c_transfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
int ret;
if (adap->algo->master_xfer) {
#ifdef DEBUG
for (ret = 0; ret < num; ret++) {
dev_dbg(&adap->dev,
"master_xfer[%d] %c, addr=0x%02x, len=%d%s\n",
ret, (msgs[ret].flags & I2C_M_RD) ? 'R' : 'W',
msgs[ret].addr, msgs[ret].len,
(msgs[ret].flags & I2C_M_RECV_LEN) ? "+" : "");
}
#endif
if (in_atomic() || irqs_disabled()) {
ret = i2c_trylock_bus(adap, I2C_LOCK_SEGMENT);
if (!ret)
return -EAGAIN;
} else {
i2c_lock_bus(adap, I2C_LOCK_SEGMENT);
}
ret = __i2c_transfer(adap, msgs, num);
i2c_unlock_bus(adap, I2C_LOCK_SEGMENT);
return ret;
} else {
dev_dbg(&adap->dev, "I2C level transfers not supported\n");
return -EOPNOTSUPP;
}
}
int i2c_master_send(const struct i2c_client *client, const char *buf, int count)
{
int ret;
struct i2c_adapter *adap = client->adapter;
struct i2c_msg msg;
msg.addr = client->addr;
msg.flags = client->flags & I2C_M_TEN;
msg.len = count;
msg.buf = (char *)buf;
ret = i2c_transfer(adap, &msg, 1);
return (ret == 1) ? count : ret;
}
int i2c_master_recv(const struct i2c_client *client, char *buf, int count)
{
struct i2c_adapter *adap = client->adapter;
struct i2c_msg msg;
int ret;
msg.addr = client->addr;
msg.flags = client->flags & I2C_M_TEN;
msg.flags |= I2C_M_RD;
msg.len = count;
msg.buf = buf;
ret = i2c_transfer(adap, &msg, 1);
return (ret == 1) ? count : ret;
}
static int i2c_default_probe(struct i2c_adapter *adap, unsigned short addr)
{
int err;
union i2c_smbus_data dummy;
#ifdef CONFIG_X86
if (addr == 0x73 && (adap->class & I2C_CLASS_HWMON)
&& i2c_check_functionality(adap, I2C_FUNC_SMBUS_READ_BYTE_DATA))
err = i2c_smbus_xfer(adap, addr, 0, I2C_SMBUS_READ, 0,
I2C_SMBUS_BYTE_DATA, &dummy);
else
#endif
if (!((addr & ~0x07) == 0x30 || (addr & ~0x0f) == 0x50)
&& i2c_check_functionality(adap, I2C_FUNC_SMBUS_QUICK))
err = i2c_smbus_xfer(adap, addr, 0, I2C_SMBUS_WRITE, 0,
I2C_SMBUS_QUICK, NULL);
else if (i2c_check_functionality(adap, I2C_FUNC_SMBUS_READ_BYTE))
err = i2c_smbus_xfer(adap, addr, 0, I2C_SMBUS_READ, 0,
I2C_SMBUS_BYTE, &dummy);
else {
dev_warn(&adap->dev, "No suitable probing method supported for address 0x%02X\n",
addr);
err = -EOPNOTSUPP;
}
return err >= 0;
}
static int i2c_detect_address(struct i2c_client *temp_client,
struct i2c_driver *driver)
{
struct i2c_board_info info;
struct i2c_adapter *adapter = temp_client->adapter;
int addr = temp_client->addr;
int err;
err = i2c_check_7bit_addr_validity_strict(addr);
if (err) {
dev_warn(&adapter->dev, "Invalid probe address 0x%02x\n",
addr);
return err;
}
if (i2c_check_addr_busy(adapter, addr))
return 0;
if (!i2c_default_probe(adapter, addr))
return 0;
memset(&info, 0, sizeof(struct i2c_board_info));
info.addr = addr;
err = driver->detect(temp_client, &info);
if (err) {
return err == -ENODEV ? 0 : err;
}
if (info.type[0] == '\0') {
dev_err(&adapter->dev,
"%s detection function provided no name for 0x%x\n",
driver->driver.name, addr);
} else {
struct i2c_client *client;
if (adapter->class & I2C_CLASS_DEPRECATED)
dev_warn(&adapter->dev,
"This adapter will soon drop class based instantiation of devices. "
"Please make sure client 0x%02x gets instantiated by other means. "
"Check 'Documentation/i2c/instantiating-devices' for details.\n",
info.addr);
dev_dbg(&adapter->dev, "Creating %s at 0x%02x\n",
info.type, info.addr);
client = i2c_new_device(adapter, &info);
if (client)
list_add_tail(&client->detected, &driver->clients);
else
dev_err(&adapter->dev, "Failed creating %s at 0x%02x\n",
info.type, info.addr);
}
return 0;
}
static int i2c_detect(struct i2c_adapter *adapter, struct i2c_driver *driver)
{
const unsigned short *address_list;
struct i2c_client *temp_client;
int i, err = 0;
int adap_id = i2c_adapter_id(adapter);
address_list = driver->address_list;
if (!driver->detect || !address_list)
return 0;
if (adapter->class == I2C_CLASS_DEPRECATED) {
dev_dbg(&adapter->dev,
"This adapter dropped support for I2C classes and won't auto-detect %s devices anymore. "
"If you need it, check 'Documentation/i2c/instantiating-devices' for alternatives.\n",
driver->driver.name);
return 0;
}
if (!(adapter->class & driver->class))
return 0;
temp_client = kzalloc(sizeof(struct i2c_client), GFP_KERNEL);
if (!temp_client)
return -ENOMEM;
temp_client->adapter = adapter;
for (i = 0; address_list[i] != I2C_CLIENT_END; i += 1) {
dev_dbg(&adapter->dev,
"found normal entry for adapter %d, addr 0x%02x\n",
adap_id, address_list[i]);
temp_client->addr = address_list[i];
err = i2c_detect_address(temp_client, driver);
if (unlikely(err))
break;
}
kfree(temp_client);
return err;
}
int i2c_probe_func_quick_read(struct i2c_adapter *adap, unsigned short addr)
{
return i2c_smbus_xfer(adap, addr, 0, I2C_SMBUS_READ, 0,
I2C_SMBUS_QUICK, NULL) >= 0;
}
struct i2c_client *
i2c_new_probed_device(struct i2c_adapter *adap,
struct i2c_board_info *info,
unsigned short const *addr_list,
int (*probe)(struct i2c_adapter *, unsigned short addr))
{
int i;
if (!probe)
probe = i2c_default_probe;
for (i = 0; addr_list[i] != I2C_CLIENT_END; i++) {
if (i2c_check_7bit_addr_validity_strict(addr_list[i]) < 0) {
dev_warn(&adap->dev, "Invalid 7-bit address 0x%02x\n",
addr_list[i]);
continue;
}
if (i2c_check_addr_busy(adap, addr_list[i])) {
dev_dbg(&adap->dev,
"Address 0x%02x already in use, not probing\n",
addr_list[i]);
continue;
}
if (probe(adap, addr_list[i]))
break;
}
if (addr_list[i] == I2C_CLIENT_END) {
dev_dbg(&adap->dev, "Probing failed, no device found\n");
return NULL;
}
info->addr = addr_list[i];
return i2c_new_device(adap, info);
}
struct i2c_adapter *i2c_get_adapter(int nr)
{
struct i2c_adapter *adapter;
mutex_lock(&core_lock);
adapter = idr_find(&i2c_adapter_idr, nr);
if (!adapter)
goto exit;
if (try_module_get(adapter->owner))
get_device(&adapter->dev);
else
adapter = NULL;
exit:
mutex_unlock(&core_lock);
return adapter;
}
void i2c_put_adapter(struct i2c_adapter *adap)
{
if (!adap)
return;
put_device(&adap->dev);
module_put(adap->owner);
}
static u8 crc8(u16 data)
{
int i;
for (i = 0; i < 8; i++) {
if (data & 0x8000)
data = data ^ POLY;
data = data << 1;
}
return (u8)(data >> 8);
}
static u8 i2c_smbus_pec(u8 crc, u8 *p, size_t count)
{
int i;
for (i = 0; i < count; i++)
crc = crc8((crc ^ p[i]) << 8);
return crc;
}
static u8 i2c_smbus_msg_pec(u8 pec, struct i2c_msg *msg)
{
u8 addr = i2c_8bit_addr_from_msg(msg);
pec = i2c_smbus_pec(pec, &addr, 1);
return i2c_smbus_pec(pec, msg->buf, msg->len);
}
static inline void i2c_smbus_add_pec(struct i2c_msg *msg)
{
msg->buf[msg->len] = i2c_smbus_msg_pec(0, msg);
msg->len++;
}
static int i2c_smbus_check_pec(u8 cpec, struct i2c_msg *msg)
{
u8 rpec = msg->buf[--msg->len];
cpec = i2c_smbus_msg_pec(cpec, msg);
if (rpec != cpec) {
pr_debug("Bad PEC 0x%02x vs. 0x%02x\n",
rpec, cpec);
return -EBADMSG;
}
return 0;
}
s32 i2c_smbus_read_byte(const struct i2c_client *client)
{
union i2c_smbus_data data;
int status;
status = i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_READ, 0,
I2C_SMBUS_BYTE, &data);
return (status < 0) ? status : data.byte;
}
s32 i2c_smbus_write_byte(const struct i2c_client *client, u8 value)
{
return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_WRITE, value, I2C_SMBUS_BYTE, NULL);
}
s32 i2c_smbus_read_byte_data(const struct i2c_client *client, u8 command)
{
union i2c_smbus_data data;
int status;
status = i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_READ, command,
I2C_SMBUS_BYTE_DATA, &data);
return (status < 0) ? status : data.byte;
}
s32 i2c_smbus_write_byte_data(const struct i2c_client *client, u8 command,
u8 value)
{
union i2c_smbus_data data;
data.byte = value;
return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_WRITE, command,
I2C_SMBUS_BYTE_DATA, &data);
}
s32 i2c_smbus_read_word_data(const struct i2c_client *client, u8 command)
{
union i2c_smbus_data data;
int status;
status = i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_READ, command,
I2C_SMBUS_WORD_DATA, &data);
return (status < 0) ? status : data.word;
}
s32 i2c_smbus_write_word_data(const struct i2c_client *client, u8 command,
u16 value)
{
union i2c_smbus_data data;
data.word = value;
return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_WRITE, command,
I2C_SMBUS_WORD_DATA, &data);
}
s32 i2c_smbus_read_block_data(const struct i2c_client *client, u8 command,
u8 *values)
{
union i2c_smbus_data data;
int status;
status = i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_READ, command,
I2C_SMBUS_BLOCK_DATA, &data);
if (status)
return status;
memcpy(values, &data.block[1], data.block[0]);
return data.block[0];
}
s32 i2c_smbus_write_block_data(const struct i2c_client *client, u8 command,
u8 length, const u8 *values)
{
union i2c_smbus_data data;
if (length > I2C_SMBUS_BLOCK_MAX)
length = I2C_SMBUS_BLOCK_MAX;
data.block[0] = length;
memcpy(&data.block[1], values, length);
return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_WRITE, command,
I2C_SMBUS_BLOCK_DATA, &data);
}
s32 i2c_smbus_read_i2c_block_data(const struct i2c_client *client, u8 command,
u8 length, u8 *values)
{
union i2c_smbus_data data;
int status;
if (length > I2C_SMBUS_BLOCK_MAX)
length = I2C_SMBUS_BLOCK_MAX;
data.block[0] = length;
status = i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_READ, command,
I2C_SMBUS_I2C_BLOCK_DATA, &data);
if (status < 0)
return status;
memcpy(values, &data.block[1], data.block[0]);
return data.block[0];
}
s32 i2c_smbus_write_i2c_block_data(const struct i2c_client *client, u8 command,
u8 length, const u8 *values)
{
union i2c_smbus_data data;
if (length > I2C_SMBUS_BLOCK_MAX)
length = I2C_SMBUS_BLOCK_MAX;
data.block[0] = length;
memcpy(data.block + 1, values, length);
return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_WRITE, command,
I2C_SMBUS_I2C_BLOCK_DATA, &data);
}
static s32 i2c_smbus_xfer_emulated(struct i2c_adapter *adapter, u16 addr,
unsigned short flags,
char read_write, u8 command, int size,
union i2c_smbus_data *data)
{
unsigned char msgbuf0[I2C_SMBUS_BLOCK_MAX+3];
unsigned char msgbuf1[I2C_SMBUS_BLOCK_MAX+2];
int num = read_write == I2C_SMBUS_READ ? 2 : 1;
int i;
u8 partial_pec = 0;
int status;
struct i2c_msg msg[2] = {
{
.addr = addr,
.flags = flags,
.len = 1,
.buf = msgbuf0,
}, {
.addr = addr,
.flags = flags | I2C_M_RD,
.len = 0,
.buf = msgbuf1,
},
};
msgbuf0[0] = command;
switch (size) {
case I2C_SMBUS_QUICK:
msg[0].len = 0;
msg[0].flags = flags | (read_write == I2C_SMBUS_READ ?
I2C_M_RD : 0);
num = 1;
break;
case I2C_SMBUS_BYTE:
if (read_write == I2C_SMBUS_READ) {
msg[0].flags = I2C_M_RD | flags;
num = 1;
}
break;
case I2C_SMBUS_BYTE_DATA:
if (read_write == I2C_SMBUS_READ)
msg[1].len = 1;
else {
msg[0].len = 2;
msgbuf0[1] = data->byte;
}
break;
case I2C_SMBUS_WORD_DATA:
if (read_write == I2C_SMBUS_READ)
msg[1].len = 2;
else {
msg[0].len = 3;
msgbuf0[1] = data->word & 0xff;
msgbuf0[2] = data->word >> 8;
}
break;
case I2C_SMBUS_PROC_CALL:
num = 2;
read_write = I2C_SMBUS_READ;
msg[0].len = 3;
msg[1].len = 2;
msgbuf0[1] = data->word & 0xff;
msgbuf0[2] = data->word >> 8;
break;
case I2C_SMBUS_BLOCK_DATA:
if (read_write == I2C_SMBUS_READ) {
msg[1].flags |= I2C_M_RECV_LEN;
msg[1].len = 1;
} else {
msg[0].len = data->block[0] + 2;
if (msg[0].len > I2C_SMBUS_BLOCK_MAX + 2) {
dev_err(&adapter->dev,
"Invalid block write size %d\n",
data->block[0]);
return -EINVAL;
}
for (i = 1; i < msg[0].len; i++)
msgbuf0[i] = data->block[i-1];
}
break;
case I2C_SMBUS_BLOCK_PROC_CALL:
num = 2;
read_write = I2C_SMBUS_READ;
if (data->block[0] > I2C_SMBUS_BLOCK_MAX) {
dev_err(&adapter->dev,
"Invalid block write size %d\n",
data->block[0]);
return -EINVAL;
}
msg[0].len = data->block[0] + 2;
for (i = 1; i < msg[0].len; i++)
msgbuf0[i] = data->block[i-1];
msg[1].flags |= I2C_M_RECV_LEN;
msg[1].len = 1;
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
if (read_write == I2C_SMBUS_READ) {
msg[1].len = data->block[0];
} else {
msg[0].len = data->block[0] + 1;
if (msg[0].len > I2C_SMBUS_BLOCK_MAX + 1) {
dev_err(&adapter->dev,
"Invalid block write size %d\n",
data->block[0]);
return -EINVAL;
}
for (i = 1; i <= data->block[0]; i++)
msgbuf0[i] = data->block[i];
}
break;
default:
dev_err(&adapter->dev, "Unsupported transaction %d\n", size);
return -EOPNOTSUPP;
}
i = ((flags & I2C_CLIENT_PEC) && size != I2C_SMBUS_QUICK
&& size != I2C_SMBUS_I2C_BLOCK_DATA);
if (i) {
if (!(msg[0].flags & I2C_M_RD)) {
if (num == 1)
i2c_smbus_add_pec(&msg[0]);
else
partial_pec = i2c_smbus_msg_pec(0, &msg[0]);
}
if (msg[num-1].flags & I2C_M_RD)
msg[num-1].len++;
}
status = i2c_transfer(adapter, msg, num);
if (status < 0)
return status;
if (i && (msg[num-1].flags & I2C_M_RD)) {
status = i2c_smbus_check_pec(partial_pec, &msg[num-1]);
if (status < 0)
return status;
}
if (read_write == I2C_SMBUS_READ)
switch (size) {
case I2C_SMBUS_BYTE:
data->byte = msgbuf0[0];
break;
case I2C_SMBUS_BYTE_DATA:
data->byte = msgbuf1[0];
break;
case I2C_SMBUS_WORD_DATA:
case I2C_SMBUS_PROC_CALL:
data->word = msgbuf1[0] | (msgbuf1[1] << 8);
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
for (i = 0; i < data->block[0]; i++)
data->block[i+1] = msgbuf1[i];
break;
case I2C_SMBUS_BLOCK_DATA:
case I2C_SMBUS_BLOCK_PROC_CALL:
for (i = 0; i < msgbuf1[0] + 1; i++)
data->block[i] = msgbuf1[i];
break;
}
return 0;
}
s32 i2c_smbus_xfer(struct i2c_adapter *adapter, u16 addr, unsigned short flags,
char read_write, u8 command, int protocol,
union i2c_smbus_data *data)
{
unsigned long orig_jiffies;
int try;
s32 res;
trace_smbus_write(adapter, addr, flags, read_write,
command, protocol, data);
trace_smbus_read(adapter, addr, flags, read_write,
command, protocol);
flags &= I2C_M_TEN | I2C_CLIENT_PEC | I2C_CLIENT_SCCB;
if (adapter->algo->smbus_xfer) {
i2c_lock_bus(adapter, I2C_LOCK_SEGMENT);
orig_jiffies = jiffies;
for (res = 0, try = 0; try <= adapter->retries; try++) {
res = adapter->algo->smbus_xfer(adapter, addr, flags,
read_write, command,
protocol, data);
if (res != -EAGAIN)
break;
if (time_after(jiffies,
orig_jiffies + adapter->timeout))
break;
}
i2c_unlock_bus(adapter, I2C_LOCK_SEGMENT);
if (res != -EOPNOTSUPP || !adapter->algo->master_xfer)
goto trace;
}
res = i2c_smbus_xfer_emulated(adapter, addr, flags, read_write,
command, protocol, data);
trace:
trace_smbus_reply(adapter, addr, flags, read_write,
command, protocol, data);
trace_smbus_result(adapter, addr, flags, read_write,
command, protocol, res);
return res;
}
s32 i2c_smbus_read_i2c_block_data_or_emulated(const struct i2c_client *client,
u8 command, u8 length, u8 *values)
{
u8 i = 0;
int status;
if (length > I2C_SMBUS_BLOCK_MAX)
length = I2C_SMBUS_BLOCK_MAX;
if (i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_READ_I2C_BLOCK))
return i2c_smbus_read_i2c_block_data(client, command, length, values);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_READ_BYTE_DATA))
return -EOPNOTSUPP;
if (i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_READ_WORD_DATA)) {
while ((i + 2) <= length) {
status = i2c_smbus_read_word_data(client, command + i);
if (status < 0)
return status;
values[i] = status & 0xff;
values[i + 1] = status >> 8;
i += 2;
}
}
while (i < length) {
status = i2c_smbus_read_byte_data(client, command + i);
if (status < 0)
return status;
values[i] = status;
i++;
}
return i;
}
int i2c_slave_register(struct i2c_client *client, i2c_slave_cb_t slave_cb)
{
int ret;
if (!client || !slave_cb) {
WARN(1, "insufficient data\n");
return -EINVAL;
}
if (!(client->flags & I2C_CLIENT_SLAVE))
dev_warn(&client->dev, "%s: client slave flag not set. You might see address collisions\n",
__func__);
if (!(client->flags & I2C_CLIENT_TEN)) {
ret = i2c_check_7bit_addr_validity_strict(client->addr);
if (ret) {
dev_err(&client->dev, "%s: invalid address\n", __func__);
return ret;
}
}
if (!client->adapter->algo->reg_slave) {
dev_err(&client->dev, "%s: not supported by adapter\n", __func__);
return -EOPNOTSUPP;
}
client->slave_cb = slave_cb;
i2c_lock_adapter(client->adapter);
ret = client->adapter->algo->reg_slave(client);
i2c_unlock_adapter(client->adapter);
if (ret) {
client->slave_cb = NULL;
dev_err(&client->dev, "%s: adapter returned error %d\n", __func__, ret);
}
return ret;
}
int i2c_slave_unregister(struct i2c_client *client)
{
int ret;
if (!client->adapter->algo->unreg_slave) {
dev_err(&client->dev, "%s: not supported by adapter\n", __func__);
return -EOPNOTSUPP;
}
i2c_lock_adapter(client->adapter);
ret = client->adapter->algo->unreg_slave(client);
i2c_unlock_adapter(client->adapter);
if (ret == 0)
client->slave_cb = NULL;
else
dev_err(&client->dev, "%s: adapter returned error %d\n", __func__, ret);
return ret;
}
