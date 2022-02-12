static int aem_init_ipmi_data(struct aem_ipmi_data *data, int iface,
struct device *bmc)
{
int err;
init_completion(&data->read_complete);
data->bmc_device = bmc;
data->address.addr_type = IPMI_SYSTEM_INTERFACE_ADDR_TYPE;
data->address.channel = IPMI_BMC_CHANNEL;
data->address.data[0] = 0;
data->interface = iface;
data->tx_msgid = 0;
data->tx_message.netfn = AEM_NETFN;
err = ipmi_create_user(data->interface, &driver_data.ipmi_hndlrs,
data, &data->user);
if (err < 0) {
dev_err(bmc, "Unable to register user with IPMI "
"interface %d\n", data->interface);
return -EACCES;
}
return 0;
}
static int aem_send_message(struct aem_ipmi_data *data)
{
int err;
err = ipmi_validate_addr(&data->address, sizeof(data->address));
if (err)
goto out;
data->tx_msgid++;
err = ipmi_request_settime(data->user, &data->address, data->tx_msgid,
&data->tx_message, data, 0, 0, 0);
if (err)
goto out1;
return 0;
out1:
dev_err(data->bmc_device, "request_settime=%x\n", err);
return err;
out:
dev_err(data->bmc_device, "validate_addr=%x\n", err);
return err;
}
static void aem_msg_handler(struct ipmi_recv_msg *msg, void *user_msg_data)
{
unsigned short rx_len;
struct aem_ipmi_data *data = user_msg_data;
if (msg->msgid != data->tx_msgid) {
dev_err(data->bmc_device, "Mismatch between received msgid "
"(%02x) and transmitted msgid (%02x)!\n",
(int)msg->msgid,
(int)data->tx_msgid);
ipmi_free_recv_msg(msg);
return;
}
data->rx_recv_type = msg->recv_type;
if (msg->msg.data_len > 0)
data->rx_result = msg->msg.data[0];
else
data->rx_result = IPMI_UNKNOWN_ERR_COMPLETION_CODE;
if (msg->msg.data_len > 1) {
rx_len = msg->msg.data_len - 1;
if (data->rx_msg_len < rx_len)
rx_len = data->rx_msg_len;
data->rx_msg_len = rx_len;
memcpy(data->rx_msg_data, msg->msg.data + 1, data->rx_msg_len);
} else
data->rx_msg_len = 0;
ipmi_free_recv_msg(msg);
complete(&data->read_complete);
}
static int aem_idr_get(int *id)
{
int i, err;
again:
if (unlikely(!idr_pre_get(&aem_idr, GFP_KERNEL)))
return -ENOMEM;
spin_lock(&aem_idr_lock);
err = idr_get_new(&aem_idr, NULL, &i);
spin_unlock(&aem_idr_lock);
if (unlikely(err == -EAGAIN))
goto again;
else if (unlikely(err))
return err;
*id = i & MAX_ID_MASK;
return 0;
}
static void aem_idr_put(int id)
{
spin_lock(&aem_idr_lock);
idr_remove(&aem_idr, id);
spin_unlock(&aem_idr_lock);
}
static int aem_read_sensor(struct aem_data *data, u8 elt, u8 reg,
void *buf, size_t size)
{
int rs_size, res;
struct aem_read_sensor_req rs_req;
struct aem_read_sensor_resp *rs_resp;
struct aem_ipmi_data *ipmi = &data->ipmi;
switch (size) {
case 1:
case 2:
case 4:
case 8:
break;
default:
return -EINVAL;
}
rs_req.id = system_x_id;
rs_req.module_handle = data->module_handle;
rs_req.element = elt;
rs_req.subcommand = AEM_READ_REGISTER;
rs_req.reg = reg;
rs_req.rx_buf_size = size;
ipmi->tx_message.cmd = AEM_ELEMENT_CMD;
ipmi->tx_message.data = (char *)&rs_req;
ipmi->tx_message.data_len = sizeof(rs_req);
rs_size = sizeof(*rs_resp) + size;
rs_resp = kzalloc(rs_size, GFP_KERNEL);
if (!rs_resp)
return -ENOMEM;
ipmi->rx_msg_data = rs_resp;
ipmi->rx_msg_len = rs_size;
aem_send_message(ipmi);
res = wait_for_completion_timeout(&ipmi->read_complete, IPMI_TIMEOUT);
if (!res) {
res = -ETIMEDOUT;
goto out;
}
if (ipmi->rx_result || ipmi->rx_msg_len != rs_size ||
memcmp(&rs_resp->id, &system_x_id, sizeof(system_x_id))) {
res = -ENOENT;
goto out;
}
switch (size) {
case 1: {
u8 *x = buf;
*x = rs_resp->bytes[0];
break;
}
case 2: {
u16 *x = buf;
*x = be16_to_cpup((__be16 *)rs_resp->bytes);
break;
}
case 4: {
u32 *x = buf;
*x = be32_to_cpup((__be32 *)rs_resp->bytes);
break;
}
case 8: {
u64 *x = buf;
*x = be64_to_cpup((__be64 *)rs_resp->bytes);
break;
}
}
res = 0;
out:
kfree(rs_resp);
return res;
}
static void update_aem_energy_one(struct aem_data *data, int which)
{
aem_read_sensor(data, AEM_ENERGY_ELEMENT, which,
&data->energy[which], 8);
}
static void update_aem_energy(struct aem_data *data)
{
update_aem_energy_one(data, 0);
if (data->ver_major < 2)
return;
update_aem_energy_one(data, 1);
}
static void update_aem1_sensors(struct aem_data *data)
{
mutex_lock(&data->lock);
if (time_before(jiffies, data->last_updated + REFRESH_INTERVAL) &&
data->valid)
goto out;
update_aem_energy(data);
out:
mutex_unlock(&data->lock);
}
static void update_aem2_sensors(struct aem_data *data)
{
int i;
mutex_lock(&data->lock);
if (time_before(jiffies, data->last_updated + REFRESH_INTERVAL) &&
data->valid)
goto out;
update_aem_energy(data);
aem_read_sensor(data, AEM_EXHAUST_ELEMENT, 0, &data->temp[0], 1);
aem_read_sensor(data, AEM_EXHAUST_ELEMENT, 1, &data->temp[1], 1);
for (i = POWER_CAP; i <= POWER_AUX; i++)
aem_read_sensor(data, AEM_POWER_CAP_ELEMENT, i,
&data->pcap[i], 2);
out:
mutex_unlock(&data->lock);
}
static void aem_delete(struct aem_data *data)
{
list_del(&data->list);
aem_remove_sensors(data);
hwmon_device_unregister(data->hwmon_dev);
ipmi_destroy_user(data->ipmi.user);
platform_set_drvdata(data->pdev, NULL);
platform_device_unregister(data->pdev);
aem_idr_put(data->id);
kfree(data);
}
static int aem_find_aem1_count(struct aem_ipmi_data *data)
{
int res;
struct aem_find_firmware_req ff_req;
struct aem_find_firmware_resp ff_resp;
ff_req.id = system_x_id;
ff_req.index = 0;
ff_req.module_type_id = cpu_to_be16(AEM_MODULE_TYPE_ID);
data->tx_message.cmd = AEM_FIND_FW_CMD;
data->tx_message.data = (char *)&ff_req;
data->tx_message.data_len = sizeof(ff_req);
data->rx_msg_data = &ff_resp;
data->rx_msg_len = sizeof(ff_resp);
aem_send_message(data);
res = wait_for_completion_timeout(&data->read_complete, IPMI_TIMEOUT);
if (!res)
return -ETIMEDOUT;
if (data->rx_result || data->rx_msg_len != sizeof(ff_resp) ||
memcmp(&ff_resp.id, &system_x_id, sizeof(system_x_id)))
return -ENOENT;
return ff_resp.num_instances;
}
static int aem_init_aem1_inst(struct aem_ipmi_data *probe, u8 module_handle)
{
struct aem_data *data;
int i;
int res = -ENOMEM;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return res;
mutex_init(&data->lock);
data->ver_major = 1;
data->ver_minor = 0;
data->module_handle = module_handle;
for (i = 0; i < AEM1_NUM_ENERGY_REGS; i++)
data->power_period[i] = AEM_DEFAULT_POWER_INTERVAL;
if (aem_idr_get(&data->id))
goto id_err;
data->pdev = platform_device_alloc(DRVNAME, data->id);
if (!data->pdev)
goto dev_err;
data->pdev->dev.driver = &aem_driver.driver;
res = platform_device_add(data->pdev);
if (res)
goto ipmi_err;
platform_set_drvdata(data->pdev, data);
if (aem_init_ipmi_data(&data->ipmi, probe->interface,
probe->bmc_device))
goto ipmi_err;
data->hwmon_dev = hwmon_device_register(&data->pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
dev_err(&data->pdev->dev, "Unable to register hwmon "
"device for IPMI interface %d\n",
probe->interface);
goto hwmon_reg_err;
}
data->update = update_aem1_sensors;
if (aem1_find_sensors(data))
goto sensor_err;
list_add_tail(&data->list, &driver_data.aem_devices);
dev_info(data->ipmi.bmc_device, "Found AEM v%d.%d at 0x%X\n",
data->ver_major, data->ver_minor,
data->module_handle);
return 0;
sensor_err:
hwmon_device_unregister(data->hwmon_dev);
hwmon_reg_err:
ipmi_destroy_user(data->ipmi.user);
ipmi_err:
platform_set_drvdata(data->pdev, NULL);
platform_device_unregister(data->pdev);
dev_err:
aem_idr_put(data->id);
id_err:
kfree(data);
return res;
}
static int aem_init_aem1(struct aem_ipmi_data *probe)
{
int num, i, err;
num = aem_find_aem1_count(probe);
for (i = 0; i < num; i++) {
err = aem_init_aem1_inst(probe, i);
if (err) {
dev_err(probe->bmc_device,
"Error %d initializing AEM1 0x%X\n",
err, i);
return err;
}
}
return 0;
}
static int aem_find_aem2(struct aem_ipmi_data *data,
struct aem_find_instance_resp *fi_resp,
int instance_num)
{
int res;
struct aem_find_instance_req fi_req;
fi_req.id = system_x_id;
fi_req.instance_number = instance_num;
fi_req.module_type_id = cpu_to_be16(AEM_MODULE_TYPE_ID);
data->tx_message.cmd = AEM_FW_INSTANCE_CMD;
data->tx_message.data = (char *)&fi_req;
data->tx_message.data_len = sizeof(fi_req);
data->rx_msg_data = fi_resp;
data->rx_msg_len = sizeof(*fi_resp);
aem_send_message(data);
res = wait_for_completion_timeout(&data->read_complete, IPMI_TIMEOUT);
if (!res)
return -ETIMEDOUT;
if (data->rx_result || data->rx_msg_len != sizeof(*fi_resp) ||
memcmp(&fi_resp->id, &system_x_id, sizeof(system_x_id)) ||
fi_resp->num_instances <= instance_num)
return -ENOENT;
return 0;
}
static int aem_init_aem2_inst(struct aem_ipmi_data *probe,
struct aem_find_instance_resp *fi_resp)
{
struct aem_data *data;
int i;
int res = -ENOMEM;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return res;
mutex_init(&data->lock);
data->ver_major = fi_resp->major;
data->ver_minor = fi_resp->minor;
data->module_handle = fi_resp->module_handle;
for (i = 0; i < AEM2_NUM_ENERGY_REGS; i++)
data->power_period[i] = AEM_DEFAULT_POWER_INTERVAL;
if (aem_idr_get(&data->id))
goto id_err;
data->pdev = platform_device_alloc(DRVNAME, data->id);
if (!data->pdev)
goto dev_err;
data->pdev->dev.driver = &aem_driver.driver;
res = platform_device_add(data->pdev);
if (res)
goto ipmi_err;
platform_set_drvdata(data->pdev, data);
if (aem_init_ipmi_data(&data->ipmi, probe->interface,
probe->bmc_device))
goto ipmi_err;
data->hwmon_dev = hwmon_device_register(&data->pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
dev_err(&data->pdev->dev, "Unable to register hwmon "
"device for IPMI interface %d\n",
probe->interface);
goto hwmon_reg_err;
}
data->update = update_aem2_sensors;
if (aem2_find_sensors(data))
goto sensor_err;
list_add_tail(&data->list, &driver_data.aem_devices);
dev_info(data->ipmi.bmc_device, "Found AEM v%d.%d at 0x%X\n",
data->ver_major, data->ver_minor,
data->module_handle);
return 0;
sensor_err:
hwmon_device_unregister(data->hwmon_dev);
hwmon_reg_err:
ipmi_destroy_user(data->ipmi.user);
ipmi_err:
platform_set_drvdata(data->pdev, NULL);
platform_device_unregister(data->pdev);
dev_err:
aem_idr_put(data->id);
id_err:
kfree(data);
return res;
}
static int aem_init_aem2(struct aem_ipmi_data *probe)
{
struct aem_find_instance_resp fi_resp;
int err;
int i = 0;
while (!aem_find_aem2(probe, &fi_resp, i)) {
if (fi_resp.major != 2) {
dev_err(probe->bmc_device, "Unknown AEM v%d; please "
"report this to the maintainer.\n",
fi_resp.major);
i++;
continue;
}
err = aem_init_aem2_inst(probe, &fi_resp);
if (err) {
dev_err(probe->bmc_device,
"Error %d initializing AEM2 0x%X\n",
err, fi_resp.module_handle);
return err;
}
i++;
}
return 0;
}
static void aem_register_bmc(int iface, struct device *dev)
{
struct aem_ipmi_data probe;
if (aem_init_ipmi_data(&probe, iface, dev))
return;
aem_init_aem1(&probe);
aem_init_aem2(&probe);
ipmi_destroy_user(probe.user);
}
static void aem_bmc_gone(int iface)
{
struct aem_data *p1, *next1;
list_for_each_entry_safe(p1, next1, &driver_data.aem_devices, list)
if (p1->ipmi.interface == iface)
aem_delete(p1);
}
static ssize_t show_name(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct aem_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s%d\n", DRVNAME, data->ver_major);
}
static ssize_t show_version(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct aem_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d.%d\n", data->ver_major, data->ver_minor);
}
static ssize_t aem_show_power(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct aem_data *data = dev_get_drvdata(dev);
u64 before, after, delta, time;
signed long leftover;
struct timespec b, a;
mutex_lock(&data->lock);
update_aem_energy_one(data, attr->index);
getnstimeofday(&b);
before = data->energy[attr->index];
leftover = schedule_timeout_interruptible(
msecs_to_jiffies(data->power_period[attr->index])
);
if (leftover) {
mutex_unlock(&data->lock);
return 0;
}
update_aem_energy_one(data, attr->index);
getnstimeofday(&a);
after = data->energy[attr->index];
mutex_unlock(&data->lock);
time = timespec_to_ns(&a) - timespec_to_ns(&b);
delta = (after - before) * UJ_PER_MJ;
return sprintf(buf, "%llu\n",
(unsigned long long)div64_u64(delta * NSEC_PER_SEC, time));
}
static ssize_t aem_show_energy(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct aem_data *a = dev_get_drvdata(dev);
mutex_lock(&a->lock);
update_aem_energy_one(a, attr->index);
mutex_unlock(&a->lock);
return sprintf(buf, "%llu\n",
(unsigned long long)a->energy[attr->index] * 1000);
}
static ssize_t aem_show_power_period(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct aem_data *a = dev_get_drvdata(dev);
a->update(a);
return sprintf(buf, "%lu\n", a->power_period[attr->index]);
}
static ssize_t aem_set_power_period(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct aem_data *a = dev_get_drvdata(dev);
unsigned long temp;
int res;
res = strict_strtoul(buf, 10, &temp);
if (res)
return res;
if (temp < AEM_MIN_POWER_INTERVAL)
return -EINVAL;
mutex_lock(&a->lock);
a->power_period[attr->index] = temp;
mutex_unlock(&a->lock);
return count;
}
static int aem_register_sensors(struct aem_data *data,
struct aem_ro_sensor_template *ro,
struct aem_rw_sensor_template *rw)
{
struct device *dev = &data->pdev->dev;
struct sensor_device_attribute *sensors = data->sensors;
int err;
while (ro->label) {
sysfs_attr_init(&sensors->dev_attr.attr);
sensors->dev_attr.attr.name = ro->label;
sensors->dev_attr.attr.mode = S_IRUGO;
sensors->dev_attr.show = ro->show;
sensors->index = ro->index;
err = device_create_file(dev, &sensors->dev_attr);
if (err) {
sensors->dev_attr.attr.name = NULL;
goto error;
}
sensors++;
ro++;
}
while (rw->label) {
sysfs_attr_init(&sensors->dev_attr.attr);
sensors->dev_attr.attr.name = rw->label;
sensors->dev_attr.attr.mode = S_IRUGO | S_IWUSR;
sensors->dev_attr.show = rw->show;
sensors->dev_attr.store = rw->set;
sensors->index = rw->index;
err = device_create_file(dev, &sensors->dev_attr);
if (err) {
sensors->dev_attr.attr.name = NULL;
goto error;
}
sensors++;
rw++;
}
err = device_create_file(dev, &sensor_dev_attr_name.dev_attr);
if (err)
goto error;
err = device_create_file(dev, &sensor_dev_attr_version.dev_attr);
return err;
error:
aem_remove_sensors(data);
return err;
}
static ssize_t aem2_show_temp(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct aem_data *a = dev_get_drvdata(dev);
a->update(a);
return sprintf(buf, "%u\n", a->temp[attr->index] * 1000);
}
static ssize_t aem2_show_pcap_value(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct aem_data *a = dev_get_drvdata(dev);
a->update(a);
return sprintf(buf, "%u\n", a->pcap[attr->index] * 100000);
}
static void aem_remove_sensors(struct aem_data *data)
{
int i;
for (i = 0; i < AEM_NUM_SENSORS; i++) {
if (!data->sensors[i].dev_attr.attr.name)
continue;
device_remove_file(&data->pdev->dev,
&data->sensors[i].dev_attr);
}
device_remove_file(&data->pdev->dev,
&sensor_dev_attr_name.dev_attr);
device_remove_file(&data->pdev->dev,
&sensor_dev_attr_version.dev_attr);
}
static int aem1_find_sensors(struct aem_data *data)
{
return aem_register_sensors(data, aem1_ro_sensors, aem1_rw_sensors);
}
static int aem2_find_sensors(struct aem_data *data)
{
return aem_register_sensors(data, aem2_ro_sensors, aem2_rw_sensors);
}
static int __init aem_init(void)
{
int res;
res = driver_register(&aem_driver.driver);
if (res) {
pr_err("Can't register aem driver\n");
return res;
}
res = ipmi_smi_watcher_register(&driver_data.bmc_events);
if (res)
goto ipmi_reg_err;
return 0;
ipmi_reg_err:
driver_unregister(&aem_driver.driver);
return res;
}
static void __exit aem_exit(void)
{
struct aem_data *p1, *next1;
ipmi_smi_watcher_unregister(&driver_data.bmc_events);
driver_unregister(&aem_driver.driver);
list_for_each_entry_safe(p1, next1, &driver_data.aem_devices, list)
aem_delete(p1);
}
