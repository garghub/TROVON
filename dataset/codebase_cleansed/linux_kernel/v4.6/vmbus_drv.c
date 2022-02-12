static void hyperv_report_panic(struct pt_regs *regs)
{
static bool panic_reported;
if (panic_reported)
return;
panic_reported = true;
wrmsrl(HV_X64_MSR_CRASH_P0, regs->ip);
wrmsrl(HV_X64_MSR_CRASH_P1, regs->ax);
wrmsrl(HV_X64_MSR_CRASH_P2, regs->bx);
wrmsrl(HV_X64_MSR_CRASH_P3, regs->cx);
wrmsrl(HV_X64_MSR_CRASH_P4, regs->dx);
wrmsrl(HV_X64_MSR_CRASH_CTL, HV_CRASH_CTL_CRASH_NOTIFY);
}
static int hyperv_panic_event(struct notifier_block *nb, unsigned long val,
void *args)
{
struct pt_regs *regs;
regs = current_pt_regs();
hyperv_report_panic(regs);
return NOTIFY_DONE;
}
static int hyperv_die_event(struct notifier_block *nb, unsigned long val,
void *args)
{
struct die_args *die = (struct die_args *)args;
struct pt_regs *regs = die->regs;
hyperv_report_panic(regs);
return NOTIFY_DONE;
}
static int vmbus_exists(void)
{
if (hv_acpi_dev == NULL)
return -ENODEV;
return 0;
}
static void print_alias_name(struct hv_device *hv_dev, char *alias_name)
{
int i;
for (i = 0; i < VMBUS_ALIAS_LEN; i += 2)
sprintf(&alias_name[i], "%02x", hv_dev->dev_type.b[i/2]);
}
static u8 channel_monitor_group(struct vmbus_channel *channel)
{
return (u8)channel->offermsg.monitorid / 32;
}
static u8 channel_monitor_offset(struct vmbus_channel *channel)
{
return (u8)channel->offermsg.monitorid % 32;
}
static u32 channel_pending(struct vmbus_channel *channel,
struct hv_monitor_page *monitor_page)
{
u8 monitor_group = channel_monitor_group(channel);
return monitor_page->trigger_group[monitor_group].pending;
}
static u32 channel_latency(struct vmbus_channel *channel,
struct hv_monitor_page *monitor_page)
{
u8 monitor_group = channel_monitor_group(channel);
u8 monitor_offset = channel_monitor_offset(channel);
return monitor_page->latency[monitor_group][monitor_offset];
}
static u32 channel_conn_id(struct vmbus_channel *channel,
struct hv_monitor_page *monitor_page)
{
u8 monitor_group = channel_monitor_group(channel);
u8 monitor_offset = channel_monitor_offset(channel);
return monitor_page->parameter[monitor_group][monitor_offset].connectionid.u.id;
}
static ssize_t id_show(struct device *dev, struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "%d\n", hv_dev->channel->offermsg.child_relid);
}
static ssize_t state_show(struct device *dev, struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "%d\n", hv_dev->channel->state);
}
static ssize_t monitor_id_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "%d\n", hv_dev->channel->offermsg.monitorid);
}
static ssize_t class_id_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "{%pUl}\n",
hv_dev->channel->offermsg.offer.if_type.b);
}
static ssize_t device_id_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "{%pUl}\n",
hv_dev->channel->offermsg.offer.if_instance.b);
}
static ssize_t modalias_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
char alias_name[VMBUS_ALIAS_LEN + 1];
print_alias_name(hv_dev, alias_name);
return sprintf(buf, "vmbus:%s\n", alias_name);
}
static ssize_t server_monitor_pending_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "%d\n",
channel_pending(hv_dev->channel,
vmbus_connection.monitor_pages[1]));
}
static ssize_t client_monitor_pending_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "%d\n",
channel_pending(hv_dev->channel,
vmbus_connection.monitor_pages[1]));
}
static ssize_t server_monitor_latency_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "%d\n",
channel_latency(hv_dev->channel,
vmbus_connection.monitor_pages[0]));
}
static ssize_t client_monitor_latency_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "%d\n",
channel_latency(hv_dev->channel,
vmbus_connection.monitor_pages[1]));
}
static ssize_t server_monitor_conn_id_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "%d\n",
channel_conn_id(hv_dev->channel,
vmbus_connection.monitor_pages[0]));
}
static ssize_t client_monitor_conn_id_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
if (!hv_dev->channel)
return -ENODEV;
return sprintf(buf, "%d\n",
channel_conn_id(hv_dev->channel,
vmbus_connection.monitor_pages[1]));
}
static ssize_t out_intr_mask_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info outbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->outbound, &outbound);
return sprintf(buf, "%d\n", outbound.current_interrupt_mask);
}
static ssize_t out_read_index_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info outbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->outbound, &outbound);
return sprintf(buf, "%d\n", outbound.current_read_index);
}
static ssize_t out_write_index_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info outbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->outbound, &outbound);
return sprintf(buf, "%d\n", outbound.current_write_index);
}
static ssize_t out_read_bytes_avail_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info outbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->outbound, &outbound);
return sprintf(buf, "%d\n", outbound.bytes_avail_toread);
}
static ssize_t out_write_bytes_avail_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info outbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->outbound, &outbound);
return sprintf(buf, "%d\n", outbound.bytes_avail_towrite);
}
static ssize_t in_intr_mask_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info inbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->inbound, &inbound);
return sprintf(buf, "%d\n", inbound.current_interrupt_mask);
}
static ssize_t in_read_index_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info inbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->inbound, &inbound);
return sprintf(buf, "%d\n", inbound.current_read_index);
}
static ssize_t in_write_index_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info inbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->inbound, &inbound);
return sprintf(buf, "%d\n", inbound.current_write_index);
}
static ssize_t in_read_bytes_avail_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info inbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->inbound, &inbound);
return sprintf(buf, "%d\n", inbound.bytes_avail_toread);
}
static ssize_t in_write_bytes_avail_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct hv_ring_buffer_debug_info inbound;
if (!hv_dev->channel)
return -ENODEV;
hv_ringbuffer_get_debuginfo(&hv_dev->channel->inbound, &inbound);
return sprintf(buf, "%d\n", inbound.bytes_avail_towrite);
}
static ssize_t channel_vp_mapping_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
struct vmbus_channel *channel = hv_dev->channel, *cur_sc;
unsigned long flags;
int buf_size = PAGE_SIZE, n_written, tot_written;
struct list_head *cur;
if (!channel)
return -ENODEV;
tot_written = snprintf(buf, buf_size, "%u:%u\n",
channel->offermsg.child_relid, channel->target_cpu);
spin_lock_irqsave(&channel->lock, flags);
list_for_each(cur, &channel->sc_list) {
if (tot_written >= buf_size - 1)
break;
cur_sc = list_entry(cur, struct vmbus_channel, sc_list);
n_written = scnprintf(buf + tot_written,
buf_size - tot_written,
"%u:%u\n",
cur_sc->offermsg.child_relid,
cur_sc->target_cpu);
tot_written += n_written;
}
spin_unlock_irqrestore(&channel->lock, flags);
return tot_written;
}
static ssize_t vendor_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
return sprintf(buf, "0x%x\n", hv_dev->vendor_id);
}
static ssize_t device_show(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct hv_device *hv_dev = device_to_hv_device(dev);
return sprintf(buf, "0x%x\n", hv_dev->device_id);
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
static inline bool is_null_guid(const uuid_le *guid)
{
if (uuid_le_cmp(*guid, null_guid))
return false;
return true;
}
static const struct hv_vmbus_device_id *hv_vmbus_get_id(
const struct hv_vmbus_device_id *id,
const uuid_le *guid)
{
for (; !is_null_guid(&id->guid); id++)
if (!uuid_le_cmp(id->guid, *guid))
return id;
return NULL;
}
static int vmbus_match(struct device *device, struct device_driver *driver)
{
struct hv_driver *drv = drv_to_hv_drv(driver);
struct hv_device *hv_dev = device_to_hv_device(device);
if (is_hvsock_channel(hv_dev->channel))
return drv->hvsock;
if (hv_vmbus_get_id(drv->id_table, &hv_dev->dev_type))
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
dev_id = hv_vmbus_get_id(drv->id_table, &dev->dev_type);
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
struct hv_driver *drv;
struct hv_device *dev = device_to_hv_device(child_device);
if (child_device->driver) {
drv = drv_to_hv_drv(child_device->driver);
if (drv->remove)
drv->remove(dev);
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
struct vmbus_channel *channel = hv_dev->channel;
hv_process_channel_removal(channel,
channel->offermsg.child_relid);
kfree(hv_dev);
}
static void vmbus_onmessage_work(struct work_struct *work)
{
struct onmessage_work_context *ctx;
if (vmbus_connection.conn_state == DISCONNECTED)
return;
ctx = container_of(work, struct onmessage_work_context,
work);
vmbus_onmessage(&ctx->msg);
kfree(ctx);
}
static void hv_process_timer_expiration(struct hv_message *msg, int cpu)
{
struct clock_event_device *dev = hv_context.clk_evt[cpu];
if (dev->event_handler)
dev->event_handler(dev);
vmbus_signal_eom(msg);
}
void vmbus_on_msg_dpc(unsigned long data)
{
int cpu = smp_processor_id();
void *page_addr = hv_context.synic_message_page[cpu];
struct hv_message *msg = (struct hv_message *)page_addr +
VMBUS_MESSAGE_SINT;
struct vmbus_channel_message_header *hdr;
struct vmbus_channel_message_table_entry *entry;
struct onmessage_work_context *ctx;
if (msg->header.message_type == HVMSG_NONE)
return;
hdr = (struct vmbus_channel_message_header *)msg->u.payload;
if (hdr->msgtype >= CHANNELMSG_COUNT) {
WARN_ONCE(1, "unknown msgtype=%d\n", hdr->msgtype);
goto msg_handled;
}
entry = &channel_message_table[hdr->msgtype];
if (entry->handler_type == VMHT_BLOCKING) {
ctx = kmalloc(sizeof(*ctx), GFP_ATOMIC);
if (ctx == NULL)
return;
INIT_WORK(&ctx->work, vmbus_onmessage_work);
memcpy(&ctx->msg, msg, sizeof(*msg));
queue_work(vmbus_connection.work_queue, &ctx->work);
} else
entry->message_handler(hdr);
msg_handled:
vmbus_signal_eom(msg);
}
static void vmbus_isr(void)
{
int cpu = smp_processor_id();
void *page_addr;
struct hv_message *msg;
union hv_synic_event_flags *event;
bool handled = false;
page_addr = hv_context.synic_event_page[cpu];
if (page_addr == NULL)
return;
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
if (msg->header.message_type == HVMSG_TIMER_EXPIRED)
hv_process_timer_expiration(msg, cpu);
else
tasklet_schedule(hv_context.msg_dpc[cpu]);
}
}
static int vmbus_bus_init(void)
{
int ret;
ret = hv_init();
if (ret != 0) {
pr_err("Unable to initialize the hypervisor - 0x%x\n", ret);
return ret;
}
ret = bus_register(&hv_bus);
if (ret)
goto err_cleanup;
hv_setup_vmbus_irq(vmbus_isr);
ret = hv_synic_alloc();
if (ret)
goto err_alloc;
on_each_cpu(hv_synic_init, NULL, 1);
ret = vmbus_connect();
if (ret)
goto err_connect;
if (vmbus_proto_version > VERSION_WIN7)
cpu_hotplug_disable();
if (ms_hyperv.misc_features & HV_FEATURE_GUEST_CRASH_MSR_AVAILABLE) {
register_die_notifier(&hyperv_die_block);
atomic_notifier_chain_register(&panic_notifier_list,
&hyperv_panic_block);
}
vmbus_request_offers();
return 0;
err_connect:
on_each_cpu(hv_synic_cleanup, NULL, 1);
err_alloc:
hv_synic_free();
hv_remove_vmbus_irq();
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
struct hv_device *vmbus_device_create(const uuid_le *type,
const uuid_le *instance,
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
child_device_obj->vendor_id = 0x1414;
return child_device_obj;
}
int vmbus_device_register(struct hv_device *child_device_obj)
{
int ret = 0;
dev_set_name(&child_device_obj->device, "vmbus_%d",
child_device_obj->channel->id);
child_device_obj->device.bus = &hv_bus;
child_device_obj->device.parent = &hv_acpi_dev->dev;
child_device_obj->device.release = vmbus_device_release;
ret = device_register(&child_device_obj->device);
if (ret)
pr_err("Unable to register child device\n");
else
pr_debug("child device %s registered\n",
dev_name(&child_device_obj->device));
return ret;
}
void vmbus_device_unregister(struct hv_device *device_obj)
{
pr_debug("child device %s unregistered\n",
dev_name(&device_obj->device));
device_unregister(&device_obj->device);
}
static acpi_status vmbus_walk_resources(struct acpi_resource *res, void *ctx)
{
resource_size_t start = 0;
resource_size_t end = 0;
struct resource *new_res;
struct resource **old_res = &hyperv_mmio;
struct resource **prev_res = NULL;
switch (res->type) {
case ACPI_RESOURCE_TYPE_ADDRESS32:
start = res->data.address32.address.minimum;
end = res->data.address32.address.maximum;
break;
case ACPI_RESOURCE_TYPE_ADDRESS64:
start = res->data.address64.address.minimum;
end = res->data.address64.address.maximum;
break;
default:
return AE_OK;
}
if (end < 0x100000)
return AE_OK;
new_res = kzalloc(sizeof(*new_res), GFP_ATOMIC);
if (!new_res)
return AE_NO_MEMORY;
if (end > VTPM_BASE_ADDRESS && start < VTPM_BASE_ADDRESS)
end = VTPM_BASE_ADDRESS;
new_res->name = "hyperv mmio";
new_res->flags = IORESOURCE_MEM;
new_res->start = start;
new_res->end = end;
do {
if (!*old_res) {
*old_res = new_res;
break;
}
if (((*old_res)->end + 1) == new_res->start) {
(*old_res)->end = new_res->end;
kfree(new_res);
break;
}
if ((*old_res)->start == new_res->end + 1) {
(*old_res)->start = new_res->start;
kfree(new_res);
break;
}
if ((*old_res)->end < new_res->start) {
new_res->sibling = *old_res;
if (prev_res)
(*prev_res)->sibling = new_res;
*old_res = new_res;
break;
}
prev_res = old_res;
old_res = &(*old_res)->sibling;
} while (1);
return AE_OK;
}
static int vmbus_acpi_remove(struct acpi_device *device)
{
struct resource *cur_res;
struct resource *next_res;
if (hyperv_mmio) {
for (cur_res = hyperv_mmio; cur_res; cur_res = next_res) {
next_res = cur_res->sibling;
kfree(cur_res);
}
}
return 0;
}
int vmbus_allocate_mmio(struct resource **new, struct hv_device *device_obj,
resource_size_t min, resource_size_t max,
resource_size_t size, resource_size_t align,
bool fb_overlap_ok)
{
struct resource *iter;
resource_size_t range_min, range_max, start, local_min, local_max;
const char *dev_n = dev_name(&device_obj->device);
u32 fb_end = screen_info.lfb_base + (screen_info.lfb_size << 1);
int i;
for (iter = hyperv_mmio; iter; iter = iter->sibling) {
if ((iter->start >= max) || (iter->end <= min))
continue;
range_min = iter->start;
range_max = iter->end;
for (i = 0; i < 2; i++) {
local_min = range_min;
local_max = range_max;
if (fb_overlap_ok || (range_min >= fb_end) ||
(range_max <= screen_info.lfb_base)) {
i++;
} else {
if ((range_min <= screen_info.lfb_base) &&
(range_max >= screen_info.lfb_base)) {
local_max = screen_info.lfb_base - 1;
range_min = fb_end;
} else {
range_min = fb_end;
continue;
}
}
start = (local_min + align - 1) & ~(align - 1);
for (; start + size - 1 <= local_max; start += align) {
*new = request_mem_region_exclusive(start, size,
dev_n);
if (*new)
return 0;
}
}
}
return -ENXIO;
}
int vmbus_cpu_number_to_vp_number(int cpu_number)
{
return hv_context.vp_index[cpu_number];
}
static int vmbus_acpi_add(struct acpi_device *device)
{
acpi_status result;
int ret_val = -ENODEV;
struct acpi_device *ancestor;
hv_acpi_dev = device;
result = acpi_walk_resources(device->handle, METHOD_NAME__CRS,
vmbus_walk_resources, NULL);
if (ACPI_FAILURE(result))
goto acpi_walk_err;
for (ancestor = device->parent; ancestor; ancestor = ancestor->parent) {
result = acpi_walk_resources(ancestor->handle, METHOD_NAME__CRS,
vmbus_walk_resources, NULL);
if (ACPI_FAILURE(result))
continue;
if (hyperv_mmio)
break;
}
ret_val = 0;
acpi_walk_err:
complete(&probe_event);
if (ret_val)
vmbus_acpi_remove(device);
return ret_val;
}
static void hv_kexec_handler(void)
{
int cpu;
hv_synic_clockevents_cleanup();
vmbus_initiate_unload(false);
for_each_online_cpu(cpu)
smp_call_function_single(cpu, hv_synic_cleanup, NULL, 1);
hv_cleanup();
}
static void hv_crash_handler(struct pt_regs *regs)
{
vmbus_initiate_unload(true);
hv_synic_cleanup(NULL);
hv_cleanup();
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
ret = vmbus_bus_init();
if (ret)
goto cleanup;
hv_setup_kexec_handler(hv_kexec_handler);
hv_setup_crash_handler(hv_crash_handler);
return 0;
cleanup:
acpi_bus_unregister_driver(&vmbus_acpi_driver);
hv_acpi_dev = NULL;
return ret;
}
static void __exit vmbus_exit(void)
{
int cpu;
hv_remove_kexec_handler();
hv_remove_crash_handler();
vmbus_connection.conn_state = DISCONNECTED;
hv_synic_clockevents_cleanup();
vmbus_disconnect();
hv_remove_vmbus_irq();
for_each_online_cpu(cpu)
tasklet_kill(hv_context.msg_dpc[cpu]);
vmbus_free_channels();
if (ms_hyperv.misc_features & HV_FEATURE_GUEST_CRASH_MSR_AVAILABLE) {
unregister_die_notifier(&hyperv_die_block);
atomic_notifier_chain_unregister(&panic_notifier_list,
&hyperv_panic_block);
}
bus_unregister(&hv_bus);
hv_cleanup();
for_each_online_cpu(cpu) {
tasklet_kill(hv_context.event_dpc[cpu]);
smp_call_function_single(cpu, hv_synic_cleanup, NULL, 1);
}
hv_synic_free();
acpi_bus_unregister_driver(&vmbus_acpi_driver);
if (vmbus_proto_version > VERSION_WIN7)
cpu_hotplug_enable();
}
