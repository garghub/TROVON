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
sizeof(struct hv_guid));
memcpy(&info->chn_instance, &debug_info.interface_instance,
sizeof(struct hv_guid));
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
static ssize_t vmbus_show_device_attr(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_device_info device_info;
memset(&device_info, 0, sizeof(struct hv_device_info));
get_channel_info(hv_dev, &device_info);
if (!strcmp(dev_attr->attr.name, "class_id")) {
return sprintf(buf, "{%02x%02x%02x%02x-%02x%02x-%02x%02x-"
"%02x%02x%02x%02x%02x%02x%02x%02x}\n",
device_info.chn_type.data[3],
device_info.chn_type.data[2],
device_info.chn_type.data[1],
device_info.chn_type.data[0],
device_info.chn_type.data[5],
device_info.chn_type.data[4],
device_info.chn_type.data[7],
device_info.chn_type.data[6],
device_info.chn_type.data[8],
device_info.chn_type.data[9],
device_info.chn_type.data[10],
device_info.chn_type.data[11],
device_info.chn_type.data[12],
device_info.chn_type.data[13],
device_info.chn_type.data[14],
device_info.chn_type.data[15]);
} else if (!strcmp(dev_attr->attr.name, "device_id")) {
return sprintf(buf, "{%02x%02x%02x%02x-%02x%02x-%02x%02x-"
"%02x%02x%02x%02x%02x%02x%02x%02x}\n",
device_info.chn_instance.data[3],
device_info.chn_instance.data[2],
device_info.chn_instance.data[1],
device_info.chn_instance.data[0],
device_info.chn_instance.data[5],
device_info.chn_instance.data[4],
device_info.chn_instance.data[7],
device_info.chn_instance.data[6],
device_info.chn_instance.data[8],
device_info.chn_instance.data[9],
device_info.chn_instance.data[10],
device_info.chn_instance.data[11],
device_info.chn_instance.data[12],
device_info.chn_instance.data[13],
device_info.chn_instance.data[14],
device_info.chn_instance.data[15]);
} else if (!strcmp(dev_attr->attr.name, "state")) {
return sprintf(buf, "%d\n", device_info.chn_state);
} else if (!strcmp(dev_attr->attr.name, "id")) {
return sprintf(buf, "%d\n", device_info.chn_id);
} else if (!strcmp(dev_attr->attr.name, "out_intr_mask")) {
return sprintf(buf, "%d\n", device_info.outbound.int_mask);
} else if (!strcmp(dev_attr->attr.name, "out_read_index")) {
return sprintf(buf, "%d\n", device_info.outbound.read_idx);
} else if (!strcmp(dev_attr->attr.name, "out_write_index")) {
return sprintf(buf, "%d\n", device_info.outbound.write_idx);
} else if (!strcmp(dev_attr->attr.name, "out_read_bytes_avail")) {
return sprintf(buf, "%d\n",
device_info.outbound.bytes_avail_toread);
} else if (!strcmp(dev_attr->attr.name, "out_write_bytes_avail")) {
return sprintf(buf, "%d\n",
device_info.outbound.bytes_avail_towrite);
} else if (!strcmp(dev_attr->attr.name, "in_intr_mask")) {
return sprintf(buf, "%d\n", device_info.inbound.int_mask);
} else if (!strcmp(dev_attr->attr.name, "in_read_index")) {
return sprintf(buf, "%d\n", device_info.inbound.read_idx);
} else if (!strcmp(dev_attr->attr.name, "in_write_index")) {
return sprintf(buf, "%d\n", device_info.inbound.write_idx);
} else if (!strcmp(dev_attr->attr.name, "in_read_bytes_avail")) {
return sprintf(buf, "%d\n",
device_info.inbound.bytes_avail_toread);
} else if (!strcmp(dev_attr->attr.name, "in_write_bytes_avail")) {
return sprintf(buf, "%d\n",
device_info.inbound.bytes_avail_towrite);
} else if (!strcmp(dev_attr->attr.name, "monitor_id")) {
return sprintf(buf, "%d\n", device_info.monitor_id);
} else if (!strcmp(dev_attr->attr.name, "server_monitor_pending")) {
return sprintf(buf, "%d\n", device_info.server_monitor_pending);
} else if (!strcmp(dev_attr->attr.name, "server_monitor_latency")) {
return sprintf(buf, "%d\n", device_info.server_monitor_latency);
} else if (!strcmp(dev_attr->attr.name, "server_monitor_conn_id")) {
return sprintf(buf, "%d\n",
device_info.server_monitor_conn_id);
} else if (!strcmp(dev_attr->attr.name, "client_monitor_pending")) {
return sprintf(buf, "%d\n", device_info.client_monitor_pending);
} else if (!strcmp(dev_attr->attr.name, "client_monitor_latency")) {
return sprintf(buf, "%d\n", device_info.client_monitor_latency);
} else if (!strcmp(dev_attr->attr.name, "client_monitor_conn_id")) {
return sprintf(buf, "%d\n",
device_info.client_monitor_conn_id);
} else {
return 0;
}
}
static int vmbus_uevent(struct device *device, struct kobj_uevent_env *env)
{
struct hv_device *dev = device_to_hv_device(device);
int ret;
ret = add_uevent_var(env, "VMBUS_DEVICE_CLASS_GUID={"
"%02x%02x%02x%02x-%02x%02x-%02x%02x-"
"%02x%02x%02x%02x%02x%02x%02x%02x}",
dev->dev_type.data[3],
dev->dev_type.data[2],
dev->dev_type.data[1],
dev->dev_type.data[0],
dev->dev_type.data[5],
dev->dev_type.data[4],
dev->dev_type.data[7],
dev->dev_type.data[6],
dev->dev_type.data[8],
dev->dev_type.data[9],
dev->dev_type.data[10],
dev->dev_type.data[11],
dev->dev_type.data[12],
dev->dev_type.data[13],
dev->dev_type.data[14],
dev->dev_type.data[15]);
if (ret)
return ret;
ret = add_uevent_var(env, "VMBUS_DEVICE_DEVICE_GUID={"
"%02x%02x%02x%02x-%02x%02x-%02x%02x-"
"%02x%02x%02x%02x%02x%02x%02x%02x}",
dev->dev_instance.data[3],
dev->dev_instance.data[2],
dev->dev_instance.data[1],
dev->dev_instance.data[0],
dev->dev_instance.data[5],
dev->dev_instance.data[4],
dev->dev_instance.data[7],
dev->dev_instance.data[6],
dev->dev_instance.data[8],
dev->dev_instance.data[9],
dev->dev_instance.data[10],
dev->dev_instance.data[11],
dev->dev_instance.data[12],
dev->dev_instance.data[13],
dev->dev_instance.data[14],
dev->dev_instance.data[15]);
if (ret)
return ret;
return 0;
}
static int vmbus_match(struct device *device, struct device_driver *driver)
{
int match = 0;
struct hv_driver *drv = drv_to_hv_drv(driver);
struct hv_device *hv_dev = device_to_hv_device(device);
if (memcmp(&hv_dev->dev_type, &drv->dev_type,
sizeof(struct hv_guid)) == 0)
match = 1;
return match;
}
static int vmbus_probe(struct device *child_device)
{
int ret = 0;
struct hv_driver *drv =
drv_to_hv_drv(child_device->driver);
struct hv_device *dev = device_to_hv_device(child_device);
if (drv->probe) {
ret = drv->probe(dev);
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
int ret;
struct hv_driver *drv;
struct hv_device *dev = device_to_hv_device(child_device);
if (child_device->driver) {
drv = drv_to_hv_drv(child_device->driver);
if (drv->remove) {
ret = drv->remove(dev);
} else {
pr_err("remove not set for driver %s\n",
dev_name(child_device));
ret = -ENODEV;
}
}
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
static int vmbus_on_isr(void)
{
int ret = 0;
int cpu = smp_processor_id();
void *page_addr;
struct hv_message *msg;
union hv_synic_event_flags *event;
page_addr = hv_context.synic_message_page[cpu];
msg = (struct hv_message *)page_addr + VMBUS_MESSAGE_SINT;
if (msg->header.message_type != HVMSG_NONE)
ret |= 0x1;
page_addr = hv_context.synic_event_page[cpu];
event = (union hv_synic_event_flags *)page_addr + VMBUS_MESSAGE_SINT;
if (sync_test_and_clear_bit(0, (unsigned long *) &event->flags32[0]))
ret |= 0x2;
return ret;
}
static irqreturn_t vmbus_isr(int irq, void *dev_id)
{
int ret;
ret = vmbus_on_isr();
if (ret > 0) {
if (test_bit(0, (unsigned long *)&ret))
tasklet_schedule(&msg_dpc);
if (test_bit(1, (unsigned long *)&ret))
tasklet_schedule(&event_dpc);
return IRQ_HANDLED;
} else {
return IRQ_NONE;
}
}
static int vmbus_bus_init(int irq)
{
int ret;
unsigned int vector;
ret = hv_init();
if (ret != 0) {
pr_err("Unable to initialize the hypervisor - 0x%x\n", ret);
return ret;
}
tasklet_init(&msg_dpc, vmbus_on_msg_dpc, 0);
tasklet_init(&event_dpc, vmbus_on_event, 0);
ret = bus_register(&hv_bus);
if (ret)
return ret;
ret = request_irq(irq, vmbus_isr, IRQF_SAMPLE_RANDOM,
driver_name, hv_acpi_dev);
if (ret != 0) {
pr_err("Unable to request IRQ %d\n",
irq);
bus_unregister(&hv_bus);
return ret;
}
vector = IRQ0_VECTOR + irq;
on_each_cpu(hv_synic_init, (void *)&vector, 1);
ret = vmbus_connect();
if (ret) {
free_irq(irq, hv_acpi_dev);
bus_unregister(&hv_bus);
return ret;
}
vmbus_request_offers();
return 0;
}
int vmbus_child_driver_register(struct device_driver *drv)
{
int ret;
pr_info("child driver registering - name %s\n", drv->name);
drv->bus = &hv_bus;
ret = driver_register(drv);
vmbus_request_offers();
return ret;
}
void vmbus_child_driver_unregister(struct device_driver *drv)
{
pr_info("child driver unregistering - name %s\n", drv->name);
driver_unregister(drv);
}
struct hv_device *vmbus_child_device_create(struct hv_guid *type,
struct hv_guid *instance,
struct vmbus_channel *channel)
{
struct hv_device *child_device_obj;
child_device_obj = kzalloc(sizeof(struct hv_device), GFP_KERNEL);
if (!child_device_obj) {
pr_err("Unable to allocate device object for child device\n");
return NULL;
}
child_device_obj->channel = channel;
memcpy(&child_device_obj->dev_type, type, sizeof(struct hv_guid));
memcpy(&child_device_obj->dev_instance, instance,
sizeof(struct hv_guid));
return child_device_obj;
}
int vmbus_child_device_register(struct hv_device *child_device_obj)
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
void vmbus_child_device_unregister(struct hv_device *device_obj)
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
result =
acpi_walk_resources(device->handle, METHOD_NAME__CRS,
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
int ret;
init_completion(&probe_event);
ret = acpi_bus_register_driver(&vmbus_acpi_driver);
if (ret)
return ret;
wait_for_completion(&probe_event);
if (irq <= 0) {
acpi_bus_unregister_driver(&vmbus_acpi_driver);
return -ENODEV;
}
ret = vmbus_bus_init(irq);
if (ret)
acpi_bus_unregister_driver(&vmbus_acpi_driver);
return ret;
}
