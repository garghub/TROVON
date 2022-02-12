static int rmi_f01_read_properties(struct rmi_device *rmi_dev,
u16 query_base_addr,
struct f01_basic_properties *props)
{
u8 queries[RMI_F01_BASIC_QUERY_LEN];
int ret;
int query_offset = query_base_addr;
bool has_ds4_queries = false;
bool has_query42 = false;
bool has_sensor_id = false;
bool has_package_id_query = false;
bool has_build_id_query = false;
u16 prod_info_addr;
u8 ds4_query_len;
ret = rmi_read_block(rmi_dev, query_offset,
queries, RMI_F01_BASIC_QUERY_LEN);
if (ret) {
dev_err(&rmi_dev->dev,
"Failed to read device query registers: %d\n", ret);
return ret;
}
prod_info_addr = query_offset + 17;
query_offset += RMI_F01_BASIC_QUERY_LEN;
props->manufacturer_id = queries[0];
props->has_lts = queries[1] & RMI_F01_QRY1_HAS_LTS;
props->has_adjustable_doze =
queries[1] & RMI_F01_QRY1_HAS_ADJ_DOZE;
props->has_adjustable_doze_holdoff =
queries[1] & RMI_F01_QRY1_HAS_ADJ_DOZE_HOFF;
has_query42 = queries[1] & RMI_F01_QRY1_HAS_QUERY42;
has_sensor_id = queries[1] & RMI_F01_QRY1_HAS_SENSOR_ID;
snprintf(props->dom, sizeof(props->dom), "20%02d/%02d/%02d",
queries[5] & RMI_F01_QRY5_YEAR_MASK,
queries[6] & RMI_F01_QRY6_MONTH_MASK,
queries[7] & RMI_F01_QRY7_DAY_MASK);
memcpy(props->product_id, &queries[11],
RMI_PRODUCT_ID_LENGTH);
props->product_id[RMI_PRODUCT_ID_LENGTH] = '\0';
props->productinfo =
((queries[2] & RMI_F01_QRY2_PRODINFO_MASK) << 7) |
(queries[3] & RMI_F01_QRY2_PRODINFO_MASK);
if (has_sensor_id)
query_offset++;
if (has_query42) {
ret = rmi_read(rmi_dev, query_offset, queries);
if (ret) {
dev_err(&rmi_dev->dev,
"Failed to read query 42 register: %d\n", ret);
return ret;
}
has_ds4_queries = !!(queries[0] & BIT(0));
query_offset++;
}
if (has_ds4_queries) {
ret = rmi_read(rmi_dev, query_offset, &ds4_query_len);
if (ret) {
dev_err(&rmi_dev->dev,
"Failed to read DS4 queries length: %d\n", ret);
return ret;
}
query_offset++;
if (ds4_query_len > 0) {
ret = rmi_read(rmi_dev, query_offset, queries);
if (ret) {
dev_err(&rmi_dev->dev,
"Failed to read DS4 queries: %d\n",
ret);
return ret;
}
has_package_id_query = !!(queries[0] & BIT(0));
has_build_id_query = !!(queries[0] & BIT(1));
}
if (has_package_id_query)
prod_info_addr++;
if (has_build_id_query) {
ret = rmi_read_block(rmi_dev, prod_info_addr, queries,
3);
if (ret) {
dev_err(&rmi_dev->dev,
"Failed to read product info: %d\n",
ret);
return ret;
}
props->firmware_id = queries[1] << 8 | queries[0];
props->firmware_id += queries[2] * 65536;
}
}
return 0;
}
char *rmi_f01_get_product_ID(struct rmi_function *fn)
{
struct f01_data *f01 = dev_get_drvdata(&fn->dev);
return f01->properties.product_id;
}
static int rmi_f01_of_probe(struct device *dev,
struct rmi_device_platform_data *pdata)
{
int retval;
u32 val;
retval = rmi_of_property_read_u32(dev,
(u32 *)&pdata->power_management.nosleep,
"syna,nosleep-mode", 1);
if (retval)
return retval;
retval = rmi_of_property_read_u32(dev, &val,
"syna,wakeup-threshold", 1);
if (retval)
return retval;
pdata->power_management.wakeup_threshold = val;
retval = rmi_of_property_read_u32(dev, &val,
"syna,doze-holdoff-ms", 1);
if (retval)
return retval;
pdata->power_management.doze_holdoff = val * 100;
retval = rmi_of_property_read_u32(dev, &val,
"syna,doze-interval-ms", 1);
if (retval)
return retval;
pdata->power_management.doze_interval = val / 10;
return 0;
}
static inline int rmi_f01_of_probe(struct device *dev,
struct rmi_device_platform_data *pdata)
{
return -ENODEV;
}
static int rmi_f01_probe(struct rmi_function *fn)
{
struct rmi_device *rmi_dev = fn->rmi_dev;
struct rmi_driver_data *driver_data = dev_get_drvdata(&rmi_dev->dev);
struct rmi_device_platform_data *pdata = rmi_get_platform_data(rmi_dev);
struct f01_data *f01;
int error;
u16 ctrl_base_addr = fn->fd.control_base_addr;
u8 device_status;
u8 temp;
if (fn->dev.of_node) {
error = rmi_f01_of_probe(&fn->dev, pdata);
if (error)
return error;
}
f01 = devm_kzalloc(&fn->dev, sizeof(struct f01_data), GFP_KERNEL);
if (!f01)
return -ENOMEM;
f01->num_of_irq_regs = driver_data->num_of_irq_regs;
error = rmi_read(rmi_dev, fn->fd.control_base_addr,
&f01->device_control.ctrl0);
if (error) {
dev_err(&fn->dev, "Failed to read F01 control: %d\n", error);
return error;
}
switch (pdata->power_management.nosleep) {
case RMI_F01_NOSLEEP_DEFAULT:
break;
case RMI_F01_NOSLEEP_OFF:
f01->device_control.ctrl0 &= ~RMI_F01_CRTL0_NOSLEEP_BIT;
break;
case RMI_F01_NOSLEEP_ON:
f01->device_control.ctrl0 |= RMI_F01_CRTL0_NOSLEEP_BIT;
break;
}
if ((f01->device_control.ctrl0 & RMI_F01_CTRL0_SLEEP_MODE_MASK) !=
RMI_SLEEP_MODE_NORMAL) {
dev_warn(&fn->dev,
"WARNING: Non-zero sleep mode found. Clearing...\n");
f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_SLEEP_MODE_MASK;
}
f01->device_control.ctrl0 |= RMI_F01_CRTL0_CONFIGURED_BIT;
error = rmi_write(rmi_dev, fn->fd.control_base_addr,
f01->device_control.ctrl0);
if (error) {
dev_err(&fn->dev, "Failed to write F01 control: %d\n", error);
return error;
}
error = rmi_read(rmi_dev, fn->fd.data_base_addr + 1, &temp);
if (error < 0) {
dev_err(&fn->dev, "Failed to read Interrupt Status.\n");
return error;
}
error = rmi_f01_read_properties(rmi_dev, fn->fd.query_base_addr,
&f01->properties);
if (error < 0) {
dev_err(&fn->dev, "Failed to read F01 properties.\n");
return error;
}
dev_info(&fn->dev, "found RMI device, manufacturer: %s, product: %s, fw id: %d\n",
f01->properties.manufacturer_id == 1 ? "Synaptics" : "unknown",
f01->properties.product_id, f01->properties.firmware_id);
ctrl_base_addr++;
ctrl_base_addr += f01->num_of_irq_regs;
if (f01->properties.has_adjustable_doze) {
f01->doze_interval_addr = ctrl_base_addr;
ctrl_base_addr++;
if (pdata->power_management.doze_interval) {
f01->device_control.doze_interval =
pdata->power_management.doze_interval;
error = rmi_write(rmi_dev, f01->doze_interval_addr,
f01->device_control.doze_interval);
if (error) {
dev_err(&fn->dev,
"Failed to configure F01 doze interval register: %d\n",
error);
return error;
}
} else {
error = rmi_read(rmi_dev, f01->doze_interval_addr,
&f01->device_control.doze_interval);
if (error) {
dev_err(&fn->dev,
"Failed to read F01 doze interval register: %d\n",
error);
return error;
}
}
f01->wakeup_threshold_addr = ctrl_base_addr;
ctrl_base_addr++;
if (pdata->power_management.wakeup_threshold) {
f01->device_control.wakeup_threshold =
pdata->power_management.wakeup_threshold;
error = rmi_write(rmi_dev, f01->wakeup_threshold_addr,
f01->device_control.wakeup_threshold);
if (error) {
dev_err(&fn->dev,
"Failed to configure F01 wakeup threshold register: %d\n",
error);
return error;
}
} else {
error = rmi_read(rmi_dev, f01->wakeup_threshold_addr,
&f01->device_control.wakeup_threshold);
if (error < 0) {
dev_err(&fn->dev,
"Failed to read F01 wakeup threshold register: %d\n",
error);
return error;
}
}
}
if (f01->properties.has_lts)
ctrl_base_addr++;
if (f01->properties.has_adjustable_doze_holdoff) {
f01->doze_holdoff_addr = ctrl_base_addr;
ctrl_base_addr++;
if (pdata->power_management.doze_holdoff) {
f01->device_control.doze_holdoff =
pdata->power_management.doze_holdoff;
error = rmi_write(rmi_dev, f01->doze_holdoff_addr,
f01->device_control.doze_holdoff);
if (error) {
dev_err(&fn->dev,
"Failed to configure F01 doze holdoff register: %d\n",
error);
return error;
}
} else {
error = rmi_read(rmi_dev, f01->doze_holdoff_addr,
&f01->device_control.doze_holdoff);
if (error) {
dev_err(&fn->dev,
"Failed to read F01 doze holdoff register: %d\n",
error);
return error;
}
}
}
error = rmi_read(rmi_dev, fn->fd.data_base_addr, &device_status);
if (error < 0) {
dev_err(&fn->dev,
"Failed to read device status: %d\n", error);
return error;
}
if (RMI_F01_STATUS_UNCONFIGURED(device_status)) {
dev_err(&fn->dev,
"Device was reset during configuration process, status: %#02x!\n",
RMI_F01_STATUS_CODE(device_status));
return -EINVAL;
}
dev_set_drvdata(&fn->dev, f01);
return 0;
}
static int rmi_f01_config(struct rmi_function *fn)
{
struct f01_data *f01 = dev_get_drvdata(&fn->dev);
int error;
error = rmi_write(fn->rmi_dev, fn->fd.control_base_addr,
f01->device_control.ctrl0);
if (error) {
dev_err(&fn->dev,
"Failed to write device_control register: %d\n", error);
return error;
}
if (f01->properties.has_adjustable_doze) {
error = rmi_write(fn->rmi_dev, f01->doze_interval_addr,
f01->device_control.doze_interval);
if (error) {
dev_err(&fn->dev,
"Failed to write doze interval: %d\n", error);
return error;
}
error = rmi_write_block(fn->rmi_dev,
f01->wakeup_threshold_addr,
&f01->device_control.wakeup_threshold,
sizeof(u8));
if (error) {
dev_err(&fn->dev,
"Failed to write wakeup threshold: %d\n",
error);
return error;
}
}
if (f01->properties.has_adjustable_doze_holdoff) {
error = rmi_write(fn->rmi_dev, f01->doze_holdoff_addr,
f01->device_control.doze_holdoff);
if (error) {
dev_err(&fn->dev,
"Failed to write doze holdoff: %d\n", error);
return error;
}
}
return 0;
}
static int rmi_f01_suspend(struct rmi_function *fn)
{
struct f01_data *f01 = dev_get_drvdata(&fn->dev);
int error;
f01->old_nosleep =
f01->device_control.ctrl0 & RMI_F01_CRTL0_NOSLEEP_BIT;
f01->device_control.ctrl0 &= ~RMI_F01_CRTL0_NOSLEEP_BIT;
f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_SLEEP_MODE_MASK;
if (device_may_wakeup(fn->rmi_dev->xport->dev))
f01->device_control.ctrl0 |= RMI_SLEEP_MODE_RESERVED1;
else
f01->device_control.ctrl0 |= RMI_SLEEP_MODE_SENSOR_SLEEP;
error = rmi_write(fn->rmi_dev, fn->fd.control_base_addr,
f01->device_control.ctrl0);
if (error) {
dev_err(&fn->dev, "Failed to write sleep mode: %d.\n", error);
if (f01->old_nosleep)
f01->device_control.ctrl0 |= RMI_F01_CRTL0_NOSLEEP_BIT;
f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_SLEEP_MODE_MASK;
f01->device_control.ctrl0 |= RMI_SLEEP_MODE_NORMAL;
return error;
}
return 0;
}
static int rmi_f01_resume(struct rmi_function *fn)
{
struct f01_data *f01 = dev_get_drvdata(&fn->dev);
int error;
if (f01->old_nosleep)
f01->device_control.ctrl0 |= RMI_F01_CRTL0_NOSLEEP_BIT;
f01->device_control.ctrl0 &= ~RMI_F01_CTRL0_SLEEP_MODE_MASK;
f01->device_control.ctrl0 |= RMI_SLEEP_MODE_NORMAL;
error = rmi_write(fn->rmi_dev, fn->fd.control_base_addr,
f01->device_control.ctrl0);
if (error) {
dev_err(&fn->dev,
"Failed to restore normal operation: %d.\n", error);
return error;
}
return 0;
}
static int rmi_f01_attention(struct rmi_function *fn,
unsigned long *irq_bits)
{
struct rmi_device *rmi_dev = fn->rmi_dev;
int error;
u8 device_status;
error = rmi_read(rmi_dev, fn->fd.data_base_addr, &device_status);
if (error) {
dev_err(&fn->dev,
"Failed to read device status: %d.\n", error);
return error;
}
if (RMI_F01_STATUS_UNCONFIGURED(device_status)) {
dev_warn(&fn->dev, "Device reset detected.\n");
error = rmi_dev->driver->reset_handler(rmi_dev);
if (error) {
dev_err(&fn->dev, "Device reset failed: %d\n", error);
return error;
}
}
return 0;
}
