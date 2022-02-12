static int vmbus_exists(void)
{
if (hv_acpi_dev == NULL)
return -ENODEV;
return 0;
}
static void get_channel_info(struct hv_device *device,
struct hv_device_info *info)
{
struct vmbus_channel_debug_info debug_info;
if (!device->channel)
return;
vmbus_get_debug_info(device->channel, &debug_info);
info->chn_id = debug_info.relid;
info->chn_state = debug_info.state;
memcpy(&info->chn_type, &debug_info.interfacetype,
sizeof(uuid_le));
memcpy(&info->chn_instance, &debug_info.interface_instance,
sizeof(uuid_le));
info->monitor_id = debug_info.monitorid;
info->server_monitor_pending = debug_info.servermonitor_pending;
info->server_monitor_latency = debug_info.servermonitor_latency;
info->server_monitor_conn_id = debug_info.servermonitor_connectionid;
info->client_monitor_pending = debug_info.clientmonitor_pending;
info->client_monitor_latency = debug_info.clientmonitor_latency;
info->client_monitor_conn_id = debug_info.clientmonitor_connectionid;
info->inbound.int_mask = debug_info.inbound.current_interrupt_mask;
info->inbound.read_idx = debug_info.inbound.current_read_index;
info->inbound.write_idx = debug_info.inbound.current_write_index;
info->inbound.bytes_avail_toread =
debug_info.inbound.bytes_avail_toread;
info->inbound.bytes_avail_towrite =
debug_info.inbound.bytes_avail_towrite;
info->outbound.int_mask =
debug_info.outbound.current_interrupt_mask;
info->outbound.read_idx = debug_info.outbound.current_read_index;
info->outbound.write_idx = debug_info.outbound.current_write_index;
info->outbound.bytes_avail_toread =
debug_info.outbound.bytes_avail_toread;
info->outbound.bytes_avail_towrite =
debug_info.outbound.bytes_avail_towrite;
}
static void print_alias_name(struct hv_device *hv_dev, char *alias_name)
{
int i;
for (i = 0; i < VMBUS_ALIAS_LEN; i += 2)
sprintf(&alias_name[i], "%02x", hv_dev->dev_type.b[i/2]);
}
static ssize_t vmbus_show_device_attr(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_device_info *device_info;
char alias_name[VMBUS_ALIAS_LEN + 1];
int ret = 0;
device_info = kzalloc(sizeof(struct hv_device_info), GFP_KERNEL);
if (!device_info)
return ret;
get_channel_info(hv_dev, device_info);
if (!strcmp(dev_attr->attr.name, "class_id")) {
ret = sprintf(buf, "{%pUl}\n", device_info->chn_type.b);
} else if (!strcmp(dev_attr->attr.name, "device_id")) {
ret = sprintf(buf, "{%pUl}\n", device_info->chn_instance.b);
} else if (!strcmp(dev_attr->attr.name, "modalias")) {
print_alias_name(hv_dev, alias_name);
ret = sprintf(buf, "vmbus:%s\n", alias_name);
} else if (!strcmp(dev_attr->attr.name, "state")) {
ret = sprintf(buf, "%d\n", device_info->chn_state);
} else if (!strcmp(dev_attr->attr.name, "id")) {
ret = sprintf(buf, "%d\n", device_info->chn_id);
} else if (!strcmp(dev_attr->attr.name, "out_intr_mask")) {
ret = sprintf(buf, "%d\n", device_info->outbound.int_mask);
} else if (!strcmp(dev_attr->attr.name, "out_read_index")) {
ret = sprintf(buf, "%d\n", device_info->outbound.read_idx);
} else if (!strcmp(dev_attr->attr.name, "out_write_index")) {
ret = sprintf(buf, "%d\n", device_info->outbound.write_idx);
} else if (!strcmp(dev_attr->attr.name, "out_read_bytes_avail")) {
ret = sprintf(buf, "%d\n",
device_info->outbound.bytes_avail_toread);
} else if (!strcmp(dev_attr->attr.name, "out_write_bytes_avail")) {
ret = sprintf(buf, "%d\n",
device_info->outbound.bytes_avail_towrite);
} else if (!strcmp(dev_attr->attr.name, "in_intr_mask")) {
ret = sprintf(buf, "%d\n", device_info->inbound.int_mask);
} else if (!strcmp(dev_attr->attr.name, "in_read_index")) {
ret = sprintf(buf, "%d\n", device_info->inbound.read_idx);
} else if (!strcmp(dev_attr->attr.name, "in_write_index")) {
ret = sprintf(buf, "%d\n", device_info->inbound.write_idx);
} else if (!strcmp(dev_attr->attr.name, "in_read_bytes_avail")) {
ret = sprintf(buf, "%d\n",
device_info->inbound.bytes_avail_toread);
} else if (!strcmp(dev_attr->attr.name, "in_write_bytes_avail")) {
ret = sprintf(buf, "%d\n",
device_info->inbound.bytes_avail_towrite);
} else if (!strcmp(dev_attr->attr.name, "monitor_id")) {
ret = sprintf(buf, "%d\n", device_info->monitor_id);
} else if (!strcmp(dev_attr->attr.name, "server_monitor_pending")) {
ret = sprintf(buf, "%d\n", device_info->server_monitor_pending);
} else if (!strcmp(dev_attr->attr.name, "server_monitor_latency")) {
ret = sprintf(buf, "%d\n", device_info->server_monitor_latency);
} else if (!strcmp(dev_attr->attr.name, "server_monitor_conn_id")) {
ret = sprintf(buf, "%d\n",
device_info->server_monitor_conn_id);
} else if (!strcmp(dev_attr->attr.name, "client_monitor_pending")) {
ret = sprintf(buf, "%d\n", device_info->client_monitor_pending);
} else if (!strcmp(dev_attr->attr.name, "client_monitor_latency")) {
ret = sprintf(buf, "%d\n", device_info->client_monitor_latency);
} else if (!strcmp(dev_attr->attr.name, "client_monitor_conn_id")) {
ret = sprintf(buf, "%d\n",
device_info->client_monitor_conn_id);
}
kfree(device_info);
return ret;
}
static int vmbus_uevent(struct device *device, struct kobj_uevent_env *env)
{
struct hv_device *dev = device_to_hv_device(device);
int ret;
char alias_name[VMBUS_ALIAS_LEN + 1];
print_alias_name(dev, alias_name);
ret = add_uevent_var(env, "MODALIAS=vmbus:%s", alias_name);
return ret;
}
static inline bool is_null_guid(const __u8 *guid)
{
if (memcmp(guid, &null_guid, sizeof(uuid_le)))
return false;
return true;
}
static const struct hv_vmbus_device_id *hv_vmbus_get_id(
const struct hv_vmbus_device_id *id,
__u8 *guid)
{
for (; !is_null_guid(id->guid); id++)
if (!memcmp(&id->guid, guid, sizeof(uuid_le)))
return id;
return NULL;
}
static int vmbus_match(struct device *device, struct device_driver *driver)
{
struct hv_driver *drv = drv_to_hv_drv(driver);
struct hv_device *hv_dev = device_to_hv_device(device);
if (hv_vmbus_get_id(drv->id_table, hv_dev->dev_type.b))
return 1;
return 0;
}
static int vmbus_probe(struct device *child_device)
{
int ret = 0;
struct hv_driver *drv =
drv_to_hv_drv(child_device->driver);
struct hv_device *dev = device_to_hv_device(child_device);
const struct hv_vmbus_device_id *dev_id;
dev_id = hv_vmbus_get_id(drv->id_table, dev->dev_type.b);
if (drv->probe) {
ret = drv->probe(dev, dev_id);
if (ret != 0)
pr_err("probe failed for device %s (%d)\n",
dev_name(child_device), ret);
} else {
pr_err("probe not set for driver %s\n",
dev_name(child_device));
ret = -ENODEV;
}
return ret;
}
static int vmbus_remove(struct device *child_device)
{
struct hv_driver *drv = drv_to_hv_drv(child_device->driver);
struct hv_device *dev = device_to_hv_device(child_device);
if (drv->remove)
drv->remove(dev);
else
pr_err("remove not set for driver %s\n",
dev_name(child_device));
return 0;
}
static void vmbus_shutdown(struct device *child_device)
{
struct hv_driver *drv;
struct hv_device *dev = device_to_hv_device(child_device);
if (!child_device->driver)
return;
drv = drv_to_hv_drv(child_device->driver);
if (drv->shutdown)
drv->shutdown(dev);
return;
}
static void vmbus_device_release(struct device *device)
{
struct hv_device *hv_dev = device_to_hv_device(device);
kfree(hv_dev);
}
static void vmbus_onmessage_work(struct work_struct *work)
{
struct onmessage_work_context *ctx;
ctx = container_of(work, struct onmessage_work_context,
work);
vmbus_onmessage(&ctx->msg);
kfree(ctx);
}
static void vmbus_on_msg_dpc(unsigned long data)
{
int cpu = smp_processor_id();
void *page_addr = hv_context.synic_message_page[cpu];
struct hv_message *msg = (struct hv_message *)page_addr +
VMBUS_MESSAGE_SINT;
struct onmessage_work_context *ctx;
while (1) {
if (msg->header.message_type == HVMSG_NONE) {
break;
} else {
ctx = kmalloc(sizeof(*ctx), GFP_ATOMIC);
if (ctx == NULL)
continue;
INIT_WORK(&ctx->work, vmbus_onmessage_work);
memcpy(&ctx->msg, msg, sizeof(*msg));
queue_work(vmbus_connection.work_queue, &ctx->work);
}
msg->header.message_type = HVMSG_NONE;
smp_mb();
if (msg->header.message_flags.msg_pending) {
wrmsrl(HV_X64_MSR_EOM, 0);
}
}
}
static irqreturn_t vmbus_isr(int irq, void *dev_id)
{
int cpu = smp_processor_id();
void *page_addr;
struct hv_message *msg;
union hv_synic_event_flags *event;
bool handled = false;
page_addr = hv_context.synic_event_page[cpu];
if (page_addr == NULL)
return IRQ_NONE;
event = (union hv_synic_event_flags *)page_addr +
VMBUS_MESSAGE_SINT;
if ((vmbus_proto_version == VERSION_WS2008) ||
(vmbus_proto_version == VERSION_WIN7)) {
if (sync_test_and_clear_bit(0,
(unsigned long *) &event->flags32[0])) {
handled = true;
}
} else {
handled = true;
}
if (handled)
tasklet_schedule(hv_context.event_dpc[cpu]);
page_addr = hv_context.synic_message_page[cpu];
msg = (struct hv_message *)page_addr + VMBUS_MESSAGE_SINT;
if (msg->header.message_type != HVMSG_NONE) {
handled = true;
tasklet_schedule(&msg_dpc);
}
if (handled)
return IRQ_HANDLED;
else
return IRQ_NONE;
}
static void vmbus_flow_handler(unsigned int irq, struct irq_desc *desc)
{
kstat_incr_irqs_this_cpu(irq, desc);
desc->action->handler(irq, desc->action->dev_id);
}
static int vmbus_bus_init(int irq)
{
int ret;
ret = hv_init();
if (ret != 0) {
pr_err("Unable to initialize the hypervisor - 0x%x\n", ret);
return ret;
}
tasklet_init(&msg_dpc, vmbus_on_msg_dpc, 0);
ret = bus_register(&hv_bus);
if (ret)
goto err_cleanup;
ret = request_irq(irq, vmbus_isr, 0, driver_name, hv_acpi_dev);
if (ret != 0) {
pr_err("Unable to request IRQ %d\n",
irq);
goto err_unregister;
}
irq_set_handler(irq, vmbus_flow_handler);
hv_register_vmbus_handler(irq, vmbus_isr);
on_each_cpu(hv_synic_init, NULL, 1);
ret = vmbus_connect();
if (ret)
goto err_irq;
vmbus_request_offers();
return 0;
err_irq:
free_irq(irq, hv_acpi_dev);
err_unregister:
bus_unregister(&hv_bus);
err_cleanup:
hv_cleanup();
return ret;
}
int __vmbus_driver_register(struct hv_driver *hv_driver, struct module *owner, const char *mod_name)
{
int ret;
pr_info("registering driver %s\n", hv_driver->name);
ret = vmbus_exists();
if (ret < 0)
return ret;
hv_driver->driver.name = hv_driver->name;
hv_driver->driver.owner = owner;
hv_driver->driver.mod_name = mod_name;
hv_driver->driver.bus = &hv_bus;
ret = driver_register(&hv_driver->driver);
return ret;
}
void vmbus_driver_unregister(struct hv_driver *hv_driver)
{
pr_info("unregistering driver %s\n", hv_driver->name);
if (!vmbus_exists())
driver_unregister(&hv_driver->driver);
}
struct hv_device *vmbus_device_create(uuid_le *type,
uuid_le *instance,
struct vmbus_channel *channel)
{
struct hv_device *child_device_obj;
child_device_obj = kzalloc(sizeof(struct hv_device), GFP_KERNEL);
if (!child_device_obj) {
pr_err("Unable to allocate device object for child device\n");
return NULL;
}
child_device_obj->channel = channel;
memcpy(&child_device_obj->dev_type, type, sizeof(uuid_le));
memcpy(&child_device_obj->dev_instance, instance,
sizeof(uuid_le));
return child_device_obj;
}
int vmbus_device_register(struct hv_device *child_device_obj)
{
int ret = 0;
static atomic_t device_num = ATOMIC_INIT(0);
dev_set_name(&child_device_obj->device, "vmbus_0_%d",
atomic_inc_return(&device_num));
child_device_obj->device.bus = &hv_bus;
child_device_obj->device.parent = &hv_acpi_dev->dev;
child_device_obj->device.release = vmbus_device_release;
ret = device_register(&child_device_obj->device);
if (ret)
pr_err("Unable to register child device\n");
else
pr_info("child device %s registered\n",
dev_name(&child_device_obj->device));
return ret;
}
void vmbus_device_unregister(struct hv_device *device_obj)
{
device_unregister(&device_obj->device);
pr_info("child device %s unregistered\n",
dev_name(&device_obj->device));
}
static acpi_status vmbus_walk_resources(struct acpi_resource *res, void *irq)
{
if (res->type == ACPI_RESOURCE_TYPE_IRQ) {
struct acpi_resource_irq *irqp;
irqp = &res->data.irq;
*((unsigned int *)irq) = irqp->interrupts[0];
}
return AE_OK;
}
static int vmbus_acpi_add(struct acpi_device *device)
{
acpi_status result;
hv_acpi_dev = device;
result = acpi_walk_resources(device->handle, METHOD_NAME__CRS,
vmbus_walk_resources, &irq);
if (ACPI_FAILURE(result)) {
complete(&probe_event);
return -ENODEV;
}
complete(&probe_event);
return 0;
}
static int __init hv_acpi_init(void)
{
int ret, t;
if (x86_hyper != &x86_hyper_ms_hyperv)
return -ENODEV;
init_completion(&probe_event);
ret = acpi_bus_register_driver(&vmbus_acpi_driver);
if (ret)
return ret;
t = wait_for_completion_timeout(&probe_event, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto cleanup;
}
if (irq <= 0) {
ret = -ENODEV;
goto cleanup;
}
ret = vmbus_bus_init(irq);
if (ret)
goto cleanup;
return 0;
cleanup:
acpi_bus_unregister_driver(&vmbus_acpi_driver);
hv_acpi_dev = NULL;
return ret;
}
static void __exit vmbus_exit(void)
{
free_irq(irq, hv_acpi_dev);
vmbus_free_channels();
bus_unregister(&hv_bus);
hv_cleanup();
acpi_bus_unregister_driver(&vmbus_acpi_driver);
}
