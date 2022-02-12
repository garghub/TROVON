static void hv_pci_generic_compl(void *context, struct pci_response *resp,
int resp_packet_size)
{
struct hv_pci_compl *comp_pkt = context;
if (resp_packet_size >= offsetofend(struct pci_response, status))
comp_pkt->completion_status = resp->status;
else
comp_pkt->completion_status = -1;
complete(&comp_pkt->host_event);
}
static void hv_tmpcpumap_init_cpu(void *_unused)
{
int cpu = smp_processor_id();
u64 vp_index;
hv_get_vp_index(vp_index);
hv_tmpcpumap.vp_index[cpu] = vp_index;
}
static void hv_tmpcpumap_init(void)
{
if (hv_tmpcpumap.initialized)
return;
memset(hv_tmpcpumap.vp_index, -1, sizeof(hv_tmpcpumap.vp_index));
on_each_cpu(hv_tmpcpumap_init_cpu, NULL, true);
hv_tmpcpumap.initialized = true;
}
static u32 hv_tmp_cpu_nr_to_vp_nr(int cpu)
{
return hv_tmpcpumap.vp_index[cpu];
}
static u32 devfn_to_wslot(int devfn)
{
union win_slot_encoding wslot;
wslot.slot = 0;
wslot.bits.dev = PCI_SLOT(devfn);
wslot.bits.func = PCI_FUNC(devfn);
return wslot.slot;
}
static int wslot_to_devfn(u32 wslot)
{
union win_slot_encoding slot_no;
slot_no.slot = wslot;
return PCI_DEVFN(slot_no.bits.dev, slot_no.bits.func);
}
static void _hv_pcifront_read_config(struct hv_pci_dev *hpdev, int where,
int size, u32 *val)
{
unsigned long flags;
void __iomem *addr = hpdev->hbus->cfg_addr + CFG_PAGE_OFFSET + where;
if (where + size <= PCI_COMMAND) {
memcpy(val, ((u8 *)&hpdev->desc.v_id) + where, size);
} else if (where >= PCI_CLASS_REVISION && where + size <=
PCI_CACHE_LINE_SIZE) {
memcpy(val, ((u8 *)&hpdev->desc.rev) + where -
PCI_CLASS_REVISION, size);
} else if (where >= PCI_SUBSYSTEM_VENDOR_ID && where + size <=
PCI_ROM_ADDRESS) {
memcpy(val, (u8 *)&hpdev->desc.subsystem_id + where -
PCI_SUBSYSTEM_VENDOR_ID, size);
} else if (where >= PCI_ROM_ADDRESS && where + size <=
PCI_CAPABILITY_LIST) {
*val = 0;
} else if (where >= PCI_INTERRUPT_LINE && where + size <=
PCI_INTERRUPT_PIN) {
*val = 0;
} else if (where + size <= CFG_PAGE_SIZE) {
spin_lock_irqsave(&hpdev->hbus->config_lock, flags);
writel(hpdev->desc.win_slot.slot, hpdev->hbus->cfg_addr);
mb();
switch (size) {
case 1:
*val = readb(addr);
break;
case 2:
*val = readw(addr);
break;
default:
*val = readl(addr);
break;
}
mb();
spin_unlock_irqrestore(&hpdev->hbus->config_lock, flags);
} else {
dev_err(&hpdev->hbus->hdev->device,
"Attempt to read beyond a function's config space.\n");
}
}
static void _hv_pcifront_write_config(struct hv_pci_dev *hpdev, int where,
int size, u32 val)
{
unsigned long flags;
void __iomem *addr = hpdev->hbus->cfg_addr + CFG_PAGE_OFFSET + where;
if (where >= PCI_SUBSYSTEM_VENDOR_ID &&
where + size <= PCI_CAPABILITY_LIST) {
} else if (where >= PCI_COMMAND && where + size <= CFG_PAGE_SIZE) {
spin_lock_irqsave(&hpdev->hbus->config_lock, flags);
writel(hpdev->desc.win_slot.slot, hpdev->hbus->cfg_addr);
wmb();
switch (size) {
case 1:
writeb(val, addr);
break;
case 2:
writew(val, addr);
break;
default:
writel(val, addr);
break;
}
mb();
spin_unlock_irqrestore(&hpdev->hbus->config_lock, flags);
} else {
dev_err(&hpdev->hbus->hdev->device,
"Attempt to write beyond a function's config space.\n");
}
}
static int hv_pcifront_read_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
struct hv_pcibus_device *hbus =
container_of(bus->sysdata, struct hv_pcibus_device, sysdata);
struct hv_pci_dev *hpdev;
hpdev = get_pcichild_wslot(hbus, devfn_to_wslot(devfn));
if (!hpdev)
return PCIBIOS_DEVICE_NOT_FOUND;
_hv_pcifront_read_config(hpdev, where, size, val);
put_pcichild(hpdev, hv_pcidev_ref_by_slot);
return PCIBIOS_SUCCESSFUL;
}
static int hv_pcifront_write_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct hv_pcibus_device *hbus =
container_of(bus->sysdata, struct hv_pcibus_device, sysdata);
struct hv_pci_dev *hpdev;
hpdev = get_pcichild_wslot(hbus, devfn_to_wslot(devfn));
if (!hpdev)
return PCIBIOS_DEVICE_NOT_FOUND;
_hv_pcifront_write_config(hpdev, where, size, val);
put_pcichild(hpdev, hv_pcidev_ref_by_slot);
return PCIBIOS_SUCCESSFUL;
}
static void hv_int_desc_free(struct hv_pci_dev *hpdev,
struct tran_int_desc *int_desc)
{
struct pci_delete_interrupt *int_pkt;
struct {
struct pci_packet pkt;
u8 buffer[sizeof(struct pci_delete_interrupt)];
} ctxt;
memset(&ctxt, 0, sizeof(ctxt));
int_pkt = (struct pci_delete_interrupt *)&ctxt.pkt.message;
int_pkt->message_type.type =
PCI_DELETE_INTERRUPT_MESSAGE;
int_pkt->wslot.slot = hpdev->desc.win_slot.slot;
int_pkt->int_desc = *int_desc;
vmbus_sendpacket(hpdev->hbus->hdev->channel, int_pkt, sizeof(*int_pkt),
(unsigned long)&ctxt.pkt, VM_PKT_DATA_INBAND, 0);
kfree(int_desc);
}
static void hv_msi_free(struct irq_domain *domain, struct msi_domain_info *info,
unsigned int irq)
{
struct hv_pcibus_device *hbus;
struct hv_pci_dev *hpdev;
struct pci_dev *pdev;
struct tran_int_desc *int_desc;
struct irq_data *irq_data = irq_domain_get_irq_data(domain, irq);
struct msi_desc *msi = irq_data_get_msi_desc(irq_data);
pdev = msi_desc_to_pci_dev(msi);
hbus = info->data;
int_desc = irq_data_get_irq_chip_data(irq_data);
if (!int_desc)
return;
irq_data->chip_data = NULL;
hpdev = get_pcichild_wslot(hbus, devfn_to_wslot(pdev->devfn));
if (!hpdev) {
kfree(int_desc);
return;
}
hv_int_desc_free(hpdev, int_desc);
put_pcichild(hpdev, hv_pcidev_ref_by_slot);
}
static int hv_set_affinity(struct irq_data *data, const struct cpumask *dest,
bool force)
{
struct irq_data *parent = data->parent_data;
return parent->chip->irq_set_affinity(parent, dest, force);
}
static void hv_irq_mask(struct irq_data *data)
{
pci_msi_mask_irq(data);
}
static void hv_irq_unmask(struct irq_data *data)
{
struct msi_desc *msi_desc = irq_data_get_msi_desc(data);
struct irq_cfg *cfg = irqd_cfg(data);
struct retarget_msi_interrupt *params;
struct hv_pcibus_device *hbus;
struct cpumask *dest;
struct pci_bus *pbus;
struct pci_dev *pdev;
unsigned long flags;
u32 var_size = 0;
int cpu_vmbus;
int cpu;
u64 res;
dest = irq_data_get_affinity_mask(data);
pdev = msi_desc_to_pci_dev(msi_desc);
pbus = pdev->bus;
hbus = container_of(pbus->sysdata, struct hv_pcibus_device, sysdata);
spin_lock_irqsave(&hbus->retarget_msi_interrupt_lock, flags);
params = &hbus->retarget_msi_interrupt_params;
memset(params, 0, sizeof(*params));
params->partition_id = HV_PARTITION_ID_SELF;
params->int_entry.source = 1;
params->int_entry.address = msi_desc->msg.address_lo;
params->int_entry.data = msi_desc->msg.data;
params->device_id = (hbus->hdev->dev_instance.b[5] << 24) |
(hbus->hdev->dev_instance.b[4] << 16) |
(hbus->hdev->dev_instance.b[7] << 8) |
(hbus->hdev->dev_instance.b[6] & 0xf8) |
PCI_FUNC(pdev->devfn);
params->int_target.vector = cfg->vector;
if (pci_protocol_version >= PCI_PROTOCOL_VERSION_1_2) {
params->int_target.flags |=
HV_DEVICE_INTERRUPT_TARGET_PROCESSOR_SET;
params->int_target.vp_set.valid_banks =
(1ull << HV_VP_SET_BANK_COUNT_MAX) - 1;
var_size = 1 + HV_VP_SET_BANK_COUNT_MAX;
for_each_cpu_and(cpu, dest, cpu_online_mask) {
cpu_vmbus = hv_tmp_cpu_nr_to_vp_nr(cpu);
if (cpu_vmbus >= HV_VP_SET_BANK_COUNT_MAX * 64) {
dev_err(&hbus->hdev->device,
"too high CPU %d", cpu_vmbus);
res = 1;
goto exit_unlock;
}
params->int_target.vp_set.masks[cpu_vmbus / 64] |=
(1ULL << (cpu_vmbus & 63));
}
} else {
for_each_cpu_and(cpu, dest, cpu_online_mask) {
params->int_target.vp_mask |=
(1ULL << hv_tmp_cpu_nr_to_vp_nr(cpu));
}
}
res = hv_do_hypercall(HVCALL_RETARGET_INTERRUPT | (var_size << 17),
params, NULL);
exit_unlock:
spin_unlock_irqrestore(&hbus->retarget_msi_interrupt_lock, flags);
if (res) {
dev_err(&hbus->hdev->device,
"%s() failed: %#llx", __func__, res);
return;
}
pci_msi_unmask_irq(data);
}
static void hv_pci_compose_compl(void *context, struct pci_response *resp,
int resp_packet_size)
{
struct compose_comp_ctxt *comp_pkt = context;
struct pci_create_int_response *int_resp =
(struct pci_create_int_response *)resp;
comp_pkt->comp_pkt.completion_status = resp->status;
comp_pkt->int_desc = int_resp->int_desc;
complete(&comp_pkt->comp_pkt.host_event);
}
static u32 hv_compose_msi_req_v1(
struct pci_create_interrupt *int_pkt, struct cpumask *affinity,
u32 slot, u8 vector)
{
int_pkt->message_type.type = PCI_CREATE_INTERRUPT_MESSAGE;
int_pkt->wslot.slot = slot;
int_pkt->int_desc.vector = vector;
int_pkt->int_desc.vector_count = 1;
int_pkt->int_desc.delivery_mode =
(apic->irq_delivery_mode == dest_LowestPrio) ?
dest_LowestPrio : dest_Fixed;
int_pkt->int_desc.cpu_mask = CPU_AFFINITY_ALL;
return sizeof(*int_pkt);
}
static u32 hv_compose_msi_req_v2(
struct pci_create_interrupt2 *int_pkt, struct cpumask *affinity,
u32 slot, u8 vector)
{
int cpu;
int_pkt->message_type.type = PCI_CREATE_INTERRUPT_MESSAGE2;
int_pkt->wslot.slot = slot;
int_pkt->int_desc.vector = vector;
int_pkt->int_desc.vector_count = 1;
int_pkt->int_desc.delivery_mode =
(apic->irq_delivery_mode == dest_LowestPrio) ?
dest_LowestPrio : dest_Fixed;
cpu = cpumask_first_and(affinity, cpu_online_mask);
int_pkt->int_desc.processor_array[0] =
hv_tmp_cpu_nr_to_vp_nr(cpu);
int_pkt->int_desc.processor_count = 1;
return sizeof(*int_pkt);
}
static void hv_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
struct irq_cfg *cfg = irqd_cfg(data);
struct hv_pcibus_device *hbus;
struct hv_pci_dev *hpdev;
struct pci_bus *pbus;
struct pci_dev *pdev;
struct compose_comp_ctxt comp;
struct tran_int_desc *int_desc;
struct {
struct pci_packet pci_pkt;
union {
struct pci_create_interrupt v1;
struct pci_create_interrupt2 v2;
} int_pkts;
} __packed ctxt;
u32 size;
int ret;
pdev = msi_desc_to_pci_dev(irq_data_get_msi_desc(data));
pbus = pdev->bus;
hbus = container_of(pbus->sysdata, struct hv_pcibus_device, sysdata);
hpdev = get_pcichild_wslot(hbus, devfn_to_wslot(pdev->devfn));
if (!hpdev)
goto return_null_message;
if (data->chip_data) {
int_desc = data->chip_data;
data->chip_data = NULL;
hv_int_desc_free(hpdev, int_desc);
}
int_desc = kzalloc(sizeof(*int_desc), GFP_ATOMIC);
if (!int_desc)
goto drop_reference;
memset(&ctxt, 0, sizeof(ctxt));
init_completion(&comp.comp_pkt.host_event);
ctxt.pci_pkt.completion_func = hv_pci_compose_compl;
ctxt.pci_pkt.compl_ctxt = &comp;
switch (pci_protocol_version) {
case PCI_PROTOCOL_VERSION_1_1:
size = hv_compose_msi_req_v1(&ctxt.int_pkts.v1,
irq_data_get_affinity_mask(data),
hpdev->desc.win_slot.slot,
cfg->vector);
break;
case PCI_PROTOCOL_VERSION_1_2:
size = hv_compose_msi_req_v2(&ctxt.int_pkts.v2,
irq_data_get_affinity_mask(data),
hpdev->desc.win_slot.slot,
cfg->vector);
break;
default:
dev_err(&hbus->hdev->device,
"Unexpected vPCI protocol, update driver.");
goto free_int_desc;
}
ret = vmbus_sendpacket(hpdev->hbus->hdev->channel, &ctxt.int_pkts,
size, (unsigned long)&ctxt.pci_pkt,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret) {
dev_err(&hbus->hdev->device,
"Sending request for interrupt failed: 0x%x",
comp.comp_pkt.completion_status);
goto free_int_desc;
}
wait_for_completion(&comp.comp_pkt.host_event);
if (comp.comp_pkt.completion_status < 0) {
dev_err(&hbus->hdev->device,
"Request for interrupt failed: 0x%x",
comp.comp_pkt.completion_status);
goto free_int_desc;
}
*int_desc = comp.int_desc;
data->chip_data = int_desc;
msg->address_hi = comp.int_desc.address >> 32;
msg->address_lo = comp.int_desc.address & 0xffffffff;
msg->data = comp.int_desc.data;
put_pcichild(hpdev, hv_pcidev_ref_by_slot);
return;
free_int_desc:
kfree(int_desc);
drop_reference:
put_pcichild(hpdev, hv_pcidev_ref_by_slot);
return_null_message:
msg->address_hi = 0;
msg->address_lo = 0;
msg->data = 0;
}
static irq_hw_number_t hv_msi_domain_ops_get_hwirq(struct msi_domain_info *info,
msi_alloc_info_t *arg)
{
return arg->msi_hwirq;
}
static int hv_pcie_init_irq_domain(struct hv_pcibus_device *hbus)
{
hbus->msi_info.chip = &hv_msi_irq_chip;
hbus->msi_info.ops = &hv_msi_ops;
hbus->msi_info.flags = (MSI_FLAG_USE_DEF_DOM_OPS |
MSI_FLAG_USE_DEF_CHIP_OPS | MSI_FLAG_MULTI_PCI_MSI |
MSI_FLAG_PCI_MSIX);
hbus->msi_info.handler = handle_edge_irq;
hbus->msi_info.handler_name = "edge";
hbus->msi_info.data = hbus;
hbus->irq_domain = pci_msi_create_irq_domain(hbus->sysdata.fwnode,
&hbus->msi_info,
x86_vector_domain);
if (!hbus->irq_domain) {
dev_err(&hbus->hdev->device,
"Failed to build an MSI IRQ domain\n");
return -ENODEV;
}
return 0;
}
static u64 get_bar_size(u64 bar_val)
{
return round_up((1 + ~(bar_val & PCI_BASE_ADDRESS_MEM_MASK)),
PAGE_SIZE);
}
static void survey_child_resources(struct hv_pcibus_device *hbus)
{
struct list_head *iter;
struct hv_pci_dev *hpdev;
resource_size_t bar_size = 0;
unsigned long flags;
struct completion *event;
u64 bar_val;
int i;
event = xchg(&hbus->survey_event, NULL);
if (!event)
return;
if (hbus->low_mmio_space || hbus->high_mmio_space) {
complete(event);
return;
}
spin_lock_irqsave(&hbus->device_list_lock, flags);
list_for_each(iter, &hbus->children) {
hpdev = container_of(iter, struct hv_pci_dev, list_entry);
for (i = 0; i < 6; i++) {
if (hpdev->probed_bar[i] & PCI_BASE_ADDRESS_SPACE_IO)
dev_err(&hbus->hdev->device,
"There's an I/O BAR in this list!\n");
if (hpdev->probed_bar[i] != 0) {
bar_val = hpdev->probed_bar[i];
if (bar_val & PCI_BASE_ADDRESS_MEM_TYPE_64)
bar_val |=
((u64)hpdev->probed_bar[++i] << 32);
else
bar_val |= 0xffffffff00000000ULL;
bar_size = get_bar_size(bar_val);
if (bar_val & PCI_BASE_ADDRESS_MEM_TYPE_64)
hbus->high_mmio_space += bar_size;
else
hbus->low_mmio_space += bar_size;
}
}
}
spin_unlock_irqrestore(&hbus->device_list_lock, flags);
complete(event);
}
static void prepopulate_bars(struct hv_pcibus_device *hbus)
{
resource_size_t high_size = 0;
resource_size_t low_size = 0;
resource_size_t high_base = 0;
resource_size_t low_base = 0;
resource_size_t bar_size;
struct hv_pci_dev *hpdev;
struct list_head *iter;
unsigned long flags;
u64 bar_val;
u32 command;
bool high;
int i;
if (hbus->low_mmio_space) {
low_size = 1ULL << (63 - __builtin_clzll(hbus->low_mmio_space));
low_base = hbus->low_mmio_res->start;
}
if (hbus->high_mmio_space) {
high_size = 1ULL <<
(63 - __builtin_clzll(hbus->high_mmio_space));
high_base = hbus->high_mmio_res->start;
}
spin_lock_irqsave(&hbus->device_list_lock, flags);
do {
list_for_each(iter, &hbus->children) {
hpdev = container_of(iter, struct hv_pci_dev,
list_entry);
for (i = 0; i < 6; i++) {
bar_val = hpdev->probed_bar[i];
if (bar_val == 0)
continue;
high = bar_val & PCI_BASE_ADDRESS_MEM_TYPE_64;
if (high) {
bar_val |=
((u64)hpdev->probed_bar[i + 1]
<< 32);
} else {
bar_val |= 0xffffffffULL << 32;
}
bar_size = get_bar_size(bar_val);
if (high) {
if (high_size != bar_size) {
i++;
continue;
}
_hv_pcifront_write_config(hpdev,
PCI_BASE_ADDRESS_0 + (4 * i),
4,
(u32)(high_base & 0xffffff00));
i++;
_hv_pcifront_write_config(hpdev,
PCI_BASE_ADDRESS_0 + (4 * i),
4, (u32)(high_base >> 32));
high_base += bar_size;
} else {
if (low_size != bar_size)
continue;
_hv_pcifront_write_config(hpdev,
PCI_BASE_ADDRESS_0 + (4 * i),
4,
(u32)(low_base & 0xffffff00));
low_base += bar_size;
}
}
if (high_size <= 1 && low_size <= 1) {
_hv_pcifront_read_config(hpdev, PCI_COMMAND, 2,
&command);
command |= PCI_COMMAND_MEMORY;
_hv_pcifront_write_config(hpdev, PCI_COMMAND, 2,
command);
break;
}
}
high_size >>= 1;
low_size >>= 1;
} while (high_size || low_size);
spin_unlock_irqrestore(&hbus->device_list_lock, flags);
}
static int create_root_hv_pci_bus(struct hv_pcibus_device *hbus)
{
hbus->pci_bus = pci_create_root_bus(&hbus->hdev->device,
0,
&hv_pcifront_ops,
&hbus->sysdata,
&hbus->resources_for_children);
if (!hbus->pci_bus)
return -ENODEV;
hbus->pci_bus->msi = &hbus->msi_chip;
hbus->pci_bus->msi->dev = &hbus->hdev->device;
pci_lock_rescan_remove();
pci_scan_child_bus(hbus->pci_bus);
pci_bus_assign_resources(hbus->pci_bus);
pci_bus_add_devices(hbus->pci_bus);
pci_unlock_rescan_remove();
hbus->state = hv_pcibus_installed;
return 0;
}
static void q_resource_requirements(void *context, struct pci_response *resp,
int resp_packet_size)
{
struct q_res_req_compl *completion = context;
struct pci_q_res_req_response *q_res_req =
(struct pci_q_res_req_response *)resp;
int i;
if (resp->status < 0) {
dev_err(&completion->hpdev->hbus->hdev->device,
"query resource requirements failed: %x\n",
resp->status);
} else {
for (i = 0; i < 6; i++) {
completion->hpdev->probed_bar[i] =
q_res_req->probed_bar[i];
}
}
complete(&completion->host_event);
}
static void get_pcichild(struct hv_pci_dev *hpdev,
enum hv_pcidev_ref_reason reason)
{
refcount_inc(&hpdev->refs);
}
static void put_pcichild(struct hv_pci_dev *hpdev,
enum hv_pcidev_ref_reason reason)
{
if (refcount_dec_and_test(&hpdev->refs))
kfree(hpdev);
}
static struct hv_pci_dev *new_pcichild_device(struct hv_pcibus_device *hbus,
struct pci_function_description *desc)
{
struct hv_pci_dev *hpdev;
struct pci_child_message *res_req;
struct q_res_req_compl comp_pkt;
struct {
struct pci_packet init_packet;
u8 buffer[sizeof(struct pci_child_message)];
} pkt;
unsigned long flags;
int ret;
hpdev = kzalloc(sizeof(*hpdev), GFP_ATOMIC);
if (!hpdev)
return NULL;
hpdev->hbus = hbus;
memset(&pkt, 0, sizeof(pkt));
init_completion(&comp_pkt.host_event);
comp_pkt.hpdev = hpdev;
pkt.init_packet.compl_ctxt = &comp_pkt;
pkt.init_packet.completion_func = q_resource_requirements;
res_req = (struct pci_child_message *)&pkt.init_packet.message;
res_req->message_type.type = PCI_QUERY_RESOURCE_REQUIREMENTS;
res_req->wslot.slot = desc->win_slot.slot;
ret = vmbus_sendpacket(hbus->hdev->channel, res_req,
sizeof(struct pci_child_message),
(unsigned long)&pkt.init_packet,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret)
goto error;
wait_for_completion(&comp_pkt.host_event);
hpdev->desc = *desc;
refcount_set(&hpdev->refs, 1);
get_pcichild(hpdev, hv_pcidev_ref_childlist);
spin_lock_irqsave(&hbus->device_list_lock, flags);
if (list_empty(&hbus->children))
hbus->sysdata.domain = desc->ser;
list_add_tail(&hpdev->list_entry, &hbus->children);
spin_unlock_irqrestore(&hbus->device_list_lock, flags);
return hpdev;
error:
kfree(hpdev);
return NULL;
}
static struct hv_pci_dev *get_pcichild_wslot(struct hv_pcibus_device *hbus,
u32 wslot)
{
unsigned long flags;
struct hv_pci_dev *iter, *hpdev = NULL;
spin_lock_irqsave(&hbus->device_list_lock, flags);
list_for_each_entry(iter, &hbus->children, list_entry) {
if (iter->desc.win_slot.slot == wslot) {
hpdev = iter;
get_pcichild(hpdev, hv_pcidev_ref_by_slot);
break;
}
}
spin_unlock_irqrestore(&hbus->device_list_lock, flags);
return hpdev;
}
static void pci_devices_present_work(struct work_struct *work)
{
u32 child_no;
bool found;
struct list_head *iter;
struct pci_function_description *new_desc;
struct hv_pci_dev *hpdev;
struct hv_pcibus_device *hbus;
struct list_head removed;
struct hv_dr_work *dr_wrk;
struct hv_dr_state *dr = NULL;
unsigned long flags;
dr_wrk = container_of(work, struct hv_dr_work, wrk);
hbus = dr_wrk->bus;
kfree(dr_wrk);
INIT_LIST_HEAD(&removed);
if (down_interruptible(&hbus->enum_sem)) {
put_hvpcibus(hbus);
return;
}
spin_lock_irqsave(&hbus->device_list_lock, flags);
while (!list_empty(&hbus->dr_list)) {
dr = list_first_entry(&hbus->dr_list, struct hv_dr_state,
list_entry);
list_del(&dr->list_entry);
if (!list_empty(&hbus->dr_list)) {
kfree(dr);
continue;
}
}
spin_unlock_irqrestore(&hbus->device_list_lock, flags);
if (!dr) {
up(&hbus->enum_sem);
put_hvpcibus(hbus);
return;
}
spin_lock_irqsave(&hbus->device_list_lock, flags);
list_for_each(iter, &hbus->children) {
hpdev = container_of(iter, struct hv_pci_dev,
list_entry);
hpdev->reported_missing = true;
}
spin_unlock_irqrestore(&hbus->device_list_lock, flags);
for (child_no = 0; child_no < dr->device_count; child_no++) {
found = false;
new_desc = &dr->func[child_no];
spin_lock_irqsave(&hbus->device_list_lock, flags);
list_for_each(iter, &hbus->children) {
hpdev = container_of(iter, struct hv_pci_dev,
list_entry);
if ((hpdev->desc.win_slot.slot ==
new_desc->win_slot.slot) &&
(hpdev->desc.v_id == new_desc->v_id) &&
(hpdev->desc.d_id == new_desc->d_id) &&
(hpdev->desc.ser == new_desc->ser)) {
hpdev->reported_missing = false;
found = true;
}
}
spin_unlock_irqrestore(&hbus->device_list_lock, flags);
if (!found) {
hpdev = new_pcichild_device(hbus, new_desc);
if (!hpdev)
dev_err(&hbus->hdev->device,
"couldn't record a child device.\n");
}
}
spin_lock_irqsave(&hbus->device_list_lock, flags);
do {
found = false;
list_for_each(iter, &hbus->children) {
hpdev = container_of(iter, struct hv_pci_dev,
list_entry);
if (hpdev->reported_missing) {
found = true;
put_pcichild(hpdev, hv_pcidev_ref_childlist);
list_move_tail(&hpdev->list_entry, &removed);
break;
}
}
} while (found);
spin_unlock_irqrestore(&hbus->device_list_lock, flags);
while (!list_empty(&removed)) {
hpdev = list_first_entry(&removed, struct hv_pci_dev,
list_entry);
list_del(&hpdev->list_entry);
put_pcichild(hpdev, hv_pcidev_ref_initial);
}
switch (hbus->state) {
case hv_pcibus_installed:
pci_lock_rescan_remove();
pci_scan_child_bus(hbus->pci_bus);
pci_unlock_rescan_remove();
break;
case hv_pcibus_init:
case hv_pcibus_probed:
survey_child_resources(hbus);
break;
default:
break;
}
up(&hbus->enum_sem);
put_hvpcibus(hbus);
kfree(dr);
}
static void hv_pci_devices_present(struct hv_pcibus_device *hbus,
struct pci_bus_relations *relations)
{
struct hv_dr_state *dr;
struct hv_dr_work *dr_wrk;
unsigned long flags;
dr_wrk = kzalloc(sizeof(*dr_wrk), GFP_NOWAIT);
if (!dr_wrk)
return;
dr = kzalloc(offsetof(struct hv_dr_state, func) +
(sizeof(struct pci_function_description) *
(relations->device_count)), GFP_NOWAIT);
if (!dr) {
kfree(dr_wrk);
return;
}
INIT_WORK(&dr_wrk->wrk, pci_devices_present_work);
dr_wrk->bus = hbus;
dr->device_count = relations->device_count;
if (dr->device_count != 0) {
memcpy(dr->func, relations->func,
sizeof(struct pci_function_description) *
dr->device_count);
}
spin_lock_irqsave(&hbus->device_list_lock, flags);
list_add_tail(&dr->list_entry, &hbus->dr_list);
spin_unlock_irqrestore(&hbus->device_list_lock, flags);
get_hvpcibus(hbus);
schedule_work(&dr_wrk->wrk);
}
static void hv_eject_device_work(struct work_struct *work)
{
struct pci_eject_response *ejct_pkt;
struct hv_pci_dev *hpdev;
struct pci_dev *pdev;
unsigned long flags;
int wslot;
struct {
struct pci_packet pkt;
u8 buffer[sizeof(struct pci_eject_response)];
} ctxt;
hpdev = container_of(work, struct hv_pci_dev, wrk);
if (hpdev->state != hv_pcichild_ejecting) {
put_pcichild(hpdev, hv_pcidev_ref_pnp);
return;
}
wslot = wslot_to_devfn(hpdev->desc.win_slot.slot);
pdev = pci_get_domain_bus_and_slot(hpdev->hbus->sysdata.domain, 0,
wslot);
if (pdev) {
pci_lock_rescan_remove();
pci_stop_and_remove_bus_device(pdev);
pci_dev_put(pdev);
pci_unlock_rescan_remove();
}
spin_lock_irqsave(&hpdev->hbus->device_list_lock, flags);
list_del(&hpdev->list_entry);
spin_unlock_irqrestore(&hpdev->hbus->device_list_lock, flags);
memset(&ctxt, 0, sizeof(ctxt));
ejct_pkt = (struct pci_eject_response *)&ctxt.pkt.message;
ejct_pkt->message_type.type = PCI_EJECTION_COMPLETE;
ejct_pkt->wslot.slot = hpdev->desc.win_slot.slot;
vmbus_sendpacket(hpdev->hbus->hdev->channel, ejct_pkt,
sizeof(*ejct_pkt), (unsigned long)&ctxt.pkt,
VM_PKT_DATA_INBAND, 0);
put_pcichild(hpdev, hv_pcidev_ref_childlist);
put_pcichild(hpdev, hv_pcidev_ref_pnp);
put_hvpcibus(hpdev->hbus);
}
static void hv_pci_eject_device(struct hv_pci_dev *hpdev)
{
hpdev->state = hv_pcichild_ejecting;
get_pcichild(hpdev, hv_pcidev_ref_pnp);
INIT_WORK(&hpdev->wrk, hv_eject_device_work);
get_hvpcibus(hpdev->hbus);
schedule_work(&hpdev->wrk);
}
static void hv_pci_onchannelcallback(void *context)
{
const int packet_size = 0x100;
int ret;
struct hv_pcibus_device *hbus = context;
u32 bytes_recvd;
u64 req_id;
struct vmpacket_descriptor *desc;
unsigned char *buffer;
int bufferlen = packet_size;
struct pci_packet *comp_packet;
struct pci_response *response;
struct pci_incoming_message *new_message;
struct pci_bus_relations *bus_rel;
struct pci_dev_incoming *dev_message;
struct hv_pci_dev *hpdev;
buffer = kmalloc(bufferlen, GFP_ATOMIC);
if (!buffer)
return;
while (1) {
ret = vmbus_recvpacket_raw(hbus->hdev->channel, buffer,
bufferlen, &bytes_recvd, &req_id);
if (ret == -ENOBUFS) {
kfree(buffer);
bufferlen = bytes_recvd;
buffer = kmalloc(bytes_recvd, GFP_ATOMIC);
if (!buffer)
return;
continue;
}
if (ret || !bytes_recvd)
break;
if (bytes_recvd <= sizeof(struct pci_response))
continue;
desc = (struct vmpacket_descriptor *)buffer;
switch (desc->type) {
case VM_PKT_COMP:
comp_packet = (struct pci_packet *)req_id;
response = (struct pci_response *)buffer;
comp_packet->completion_func(comp_packet->compl_ctxt,
response,
bytes_recvd);
break;
case VM_PKT_DATA_INBAND:
new_message = (struct pci_incoming_message *)buffer;
switch (new_message->message_type.type) {
case PCI_BUS_RELATIONS:
bus_rel = (struct pci_bus_relations *)buffer;
if (bytes_recvd <
offsetof(struct pci_bus_relations, func) +
(sizeof(struct pci_function_description) *
(bus_rel->device_count))) {
dev_err(&hbus->hdev->device,
"bus relations too small\n");
break;
}
hv_pci_devices_present(hbus, bus_rel);
break;
case PCI_EJECT:
dev_message = (struct pci_dev_incoming *)buffer;
hpdev = get_pcichild_wslot(hbus,
dev_message->wslot.slot);
if (hpdev) {
hv_pci_eject_device(hpdev);
put_pcichild(hpdev,
hv_pcidev_ref_by_slot);
}
break;
default:
dev_warn(&hbus->hdev->device,
"Unimplemented protocol message %x\n",
new_message->message_type.type);
break;
}
break;
default:
dev_err(&hbus->hdev->device,
"unhandled packet type %d, tid %llx len %d\n",
desc->type, req_id, bytes_recvd);
break;
}
}
kfree(buffer);
}
static int hv_pci_protocol_negotiation(struct hv_device *hdev)
{
struct pci_version_request *version_req;
struct hv_pci_compl comp_pkt;
struct pci_packet *pkt;
int ret;
int i;
pkt = kzalloc(sizeof(*pkt) + sizeof(*version_req), GFP_KERNEL);
if (!pkt)
return -ENOMEM;
init_completion(&comp_pkt.host_event);
pkt->completion_func = hv_pci_generic_compl;
pkt->compl_ctxt = &comp_pkt;
version_req = (struct pci_version_request *)&pkt->message;
version_req->message_type.type = PCI_QUERY_PROTOCOL_VERSION;
for (i = 0; i < ARRAY_SIZE(pci_protocol_versions); i++) {
version_req->protocol_version = pci_protocol_versions[i];
ret = vmbus_sendpacket(hdev->channel, version_req,
sizeof(struct pci_version_request),
(unsigned long)pkt, VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret) {
dev_err(&hdev->device,
"PCI Pass-through VSP failed sending version reqquest: %#x",
ret);
goto exit;
}
wait_for_completion(&comp_pkt.host_event);
if (comp_pkt.completion_status >= 0) {
pci_protocol_version = pci_protocol_versions[i];
dev_info(&hdev->device,
"PCI VMBus probing: Using version %#x\n",
pci_protocol_version);
goto exit;
}
if (comp_pkt.completion_status != STATUS_REVISION_MISMATCH) {
dev_err(&hdev->device,
"PCI Pass-through VSP failed version request: %#x",
comp_pkt.completion_status);
ret = -EPROTO;
goto exit;
}
reinit_completion(&comp_pkt.host_event);
}
dev_err(&hdev->device,
"PCI pass-through VSP failed to find supported version");
ret = -EPROTO;
exit:
kfree(pkt);
return ret;
}
static void hv_pci_free_bridge_windows(struct hv_pcibus_device *hbus)
{
if (hbus->low_mmio_space && hbus->low_mmio_res) {
hbus->low_mmio_res->flags |= IORESOURCE_BUSY;
vmbus_free_mmio(hbus->low_mmio_res->start,
resource_size(hbus->low_mmio_res));
}
if (hbus->high_mmio_space && hbus->high_mmio_res) {
hbus->high_mmio_res->flags |= IORESOURCE_BUSY;
vmbus_free_mmio(hbus->high_mmio_res->start,
resource_size(hbus->high_mmio_res));
}
}
static int hv_pci_allocate_bridge_windows(struct hv_pcibus_device *hbus)
{
resource_size_t align;
int ret;
if (hbus->low_mmio_space) {
align = 1ULL << (63 - __builtin_clzll(hbus->low_mmio_space));
ret = vmbus_allocate_mmio(&hbus->low_mmio_res, hbus->hdev, 0,
(u64)(u32)0xffffffff,
hbus->low_mmio_space,
align, false);
if (ret) {
dev_err(&hbus->hdev->device,
"Need %#llx of low MMIO space. Consider reconfiguring the VM.\n",
hbus->low_mmio_space);
return ret;
}
hbus->low_mmio_res->flags |= IORESOURCE_WINDOW;
hbus->low_mmio_res->flags &= ~IORESOURCE_BUSY;
pci_add_resource(&hbus->resources_for_children,
hbus->low_mmio_res);
}
if (hbus->high_mmio_space) {
align = 1ULL << (63 - __builtin_clzll(hbus->high_mmio_space));
ret = vmbus_allocate_mmio(&hbus->high_mmio_res, hbus->hdev,
0x100000000, -1,
hbus->high_mmio_space, align,
false);
if (ret) {
dev_err(&hbus->hdev->device,
"Need %#llx of high MMIO space. Consider reconfiguring the VM.\n",
hbus->high_mmio_space);
goto release_low_mmio;
}
hbus->high_mmio_res->flags |= IORESOURCE_WINDOW;
hbus->high_mmio_res->flags &= ~IORESOURCE_BUSY;
pci_add_resource(&hbus->resources_for_children,
hbus->high_mmio_res);
}
return 0;
release_low_mmio:
if (hbus->low_mmio_res) {
vmbus_free_mmio(hbus->low_mmio_res->start,
resource_size(hbus->low_mmio_res));
}
return ret;
}
static int hv_allocate_config_window(struct hv_pcibus_device *hbus)
{
int ret;
ret = vmbus_allocate_mmio(&hbus->mem_config, hbus->hdev, 0, -1,
PCI_CONFIG_MMIO_LENGTH, 0x1000, false);
if (ret)
return ret;
hbus->mem_config->flags |= IORESOURCE_BUSY;
return 0;
}
static void hv_free_config_window(struct hv_pcibus_device *hbus)
{
vmbus_free_mmio(hbus->mem_config->start, PCI_CONFIG_MMIO_LENGTH);
}
static int hv_pci_enter_d0(struct hv_device *hdev)
{
struct hv_pcibus_device *hbus = hv_get_drvdata(hdev);
struct pci_bus_d0_entry *d0_entry;
struct hv_pci_compl comp_pkt;
struct pci_packet *pkt;
int ret;
pkt = kzalloc(sizeof(*pkt) + sizeof(*d0_entry), GFP_KERNEL);
if (!pkt)
return -ENOMEM;
init_completion(&comp_pkt.host_event);
pkt->completion_func = hv_pci_generic_compl;
pkt->compl_ctxt = &comp_pkt;
d0_entry = (struct pci_bus_d0_entry *)&pkt->message;
d0_entry->message_type.type = PCI_BUS_D0ENTRY;
d0_entry->mmio_base = hbus->mem_config->start;
ret = vmbus_sendpacket(hdev->channel, d0_entry, sizeof(*d0_entry),
(unsigned long)pkt, VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret)
goto exit;
wait_for_completion(&comp_pkt.host_event);
if (comp_pkt.completion_status < 0) {
dev_err(&hdev->device,
"PCI Pass-through VSP failed D0 Entry with status %x\n",
comp_pkt.completion_status);
ret = -EPROTO;
goto exit;
}
ret = 0;
exit:
kfree(pkt);
return ret;
}
static int hv_pci_query_relations(struct hv_device *hdev)
{
struct hv_pcibus_device *hbus = hv_get_drvdata(hdev);
struct pci_message message;
struct completion comp;
int ret;
init_completion(&comp);
if (cmpxchg(&hbus->survey_event, NULL, &comp))
return -ENOTEMPTY;
memset(&message, 0, sizeof(message));
message.type = PCI_QUERY_BUS_RELATIONS;
ret = vmbus_sendpacket(hdev->channel, &message, sizeof(message),
0, VM_PKT_DATA_INBAND, 0);
if (ret)
return ret;
wait_for_completion(&comp);
return 0;
}
static int hv_send_resources_allocated(struct hv_device *hdev)
{
struct hv_pcibus_device *hbus = hv_get_drvdata(hdev);
struct pci_resources_assigned *res_assigned;
struct pci_resources_assigned2 *res_assigned2;
struct hv_pci_compl comp_pkt;
struct hv_pci_dev *hpdev;
struct pci_packet *pkt;
size_t size_res;
u32 wslot;
int ret;
size_res = (pci_protocol_version < PCI_PROTOCOL_VERSION_1_2)
? sizeof(*res_assigned) : sizeof(*res_assigned2);
pkt = kmalloc(sizeof(*pkt) + size_res, GFP_KERNEL);
if (!pkt)
return -ENOMEM;
ret = 0;
for (wslot = 0; wslot < 256; wslot++) {
hpdev = get_pcichild_wslot(hbus, wslot);
if (!hpdev)
continue;
memset(pkt, 0, sizeof(*pkt) + size_res);
init_completion(&comp_pkt.host_event);
pkt->completion_func = hv_pci_generic_compl;
pkt->compl_ctxt = &comp_pkt;
if (pci_protocol_version < PCI_PROTOCOL_VERSION_1_2) {
res_assigned =
(struct pci_resources_assigned *)&pkt->message;
res_assigned->message_type.type =
PCI_RESOURCES_ASSIGNED;
res_assigned->wslot.slot = hpdev->desc.win_slot.slot;
} else {
res_assigned2 =
(struct pci_resources_assigned2 *)&pkt->message;
res_assigned2->message_type.type =
PCI_RESOURCES_ASSIGNED2;
res_assigned2->wslot.slot = hpdev->desc.win_slot.slot;
}
put_pcichild(hpdev, hv_pcidev_ref_by_slot);
ret = vmbus_sendpacket(hdev->channel, &pkt->message,
size_res, (unsigned long)pkt,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret)
break;
wait_for_completion(&comp_pkt.host_event);
if (comp_pkt.completion_status < 0) {
ret = -EPROTO;
dev_err(&hdev->device,
"resource allocated returned 0x%x",
comp_pkt.completion_status);
break;
}
}
kfree(pkt);
return ret;
}
static int hv_send_resources_released(struct hv_device *hdev)
{
struct hv_pcibus_device *hbus = hv_get_drvdata(hdev);
struct pci_child_message pkt;
struct hv_pci_dev *hpdev;
u32 wslot;
int ret;
for (wslot = 0; wslot < 256; wslot++) {
hpdev = get_pcichild_wslot(hbus, wslot);
if (!hpdev)
continue;
memset(&pkt, 0, sizeof(pkt));
pkt.message_type.type = PCI_RESOURCES_RELEASED;
pkt.wslot.slot = hpdev->desc.win_slot.slot;
put_pcichild(hpdev, hv_pcidev_ref_by_slot);
ret = vmbus_sendpacket(hdev->channel, &pkt, sizeof(pkt), 0,
VM_PKT_DATA_INBAND, 0);
if (ret)
return ret;
}
return 0;
}
static void get_hvpcibus(struct hv_pcibus_device *hbus)
{
atomic_inc(&hbus->remove_lock);
}
static void put_hvpcibus(struct hv_pcibus_device *hbus)
{
if (atomic_dec_and_test(&hbus->remove_lock))
complete(&hbus->remove_event);
}
static int hv_pci_probe(struct hv_device *hdev,
const struct hv_vmbus_device_id *dev_id)
{
struct hv_pcibus_device *hbus;
int ret;
BUILD_BUG_ON(sizeof(*hbus) > PAGE_SIZE);
hbus = (struct hv_pcibus_device *)get_zeroed_page(GFP_KERNEL);
if (!hbus)
return -ENOMEM;
hbus->state = hv_pcibus_init;
hv_tmpcpumap_init();
hbus->sysdata.domain = hdev->dev_instance.b[9] |
hdev->dev_instance.b[8] << 8;
hbus->hdev = hdev;
atomic_inc(&hbus->remove_lock);
INIT_LIST_HEAD(&hbus->children);
INIT_LIST_HEAD(&hbus->dr_list);
INIT_LIST_HEAD(&hbus->resources_for_children);
spin_lock_init(&hbus->config_lock);
spin_lock_init(&hbus->device_list_lock);
spin_lock_init(&hbus->retarget_msi_interrupt_lock);
sema_init(&hbus->enum_sem, 1);
init_completion(&hbus->remove_event);
ret = vmbus_open(hdev->channel, pci_ring_size, pci_ring_size, NULL, 0,
hv_pci_onchannelcallback, hbus);
if (ret)
goto free_bus;
hv_set_drvdata(hdev, hbus);
ret = hv_pci_protocol_negotiation(hdev);
if (ret)
goto close;
ret = hv_allocate_config_window(hbus);
if (ret)
goto close;
hbus->cfg_addr = ioremap(hbus->mem_config->start,
PCI_CONFIG_MMIO_LENGTH);
if (!hbus->cfg_addr) {
dev_err(&hdev->device,
"Unable to map a virtual address for config space\n");
ret = -ENOMEM;
goto free_config;
}
hbus->sysdata.fwnode = irq_domain_alloc_fwnode(hbus);
if (!hbus->sysdata.fwnode) {
ret = -ENOMEM;
goto unmap;
}
ret = hv_pcie_init_irq_domain(hbus);
if (ret)
goto free_fwnode;
ret = hv_pci_query_relations(hdev);
if (ret)
goto free_irq_domain;
ret = hv_pci_enter_d0(hdev);
if (ret)
goto free_irq_domain;
ret = hv_pci_allocate_bridge_windows(hbus);
if (ret)
goto free_irq_domain;
ret = hv_send_resources_allocated(hdev);
if (ret)
goto free_windows;
prepopulate_bars(hbus);
hbus->state = hv_pcibus_probed;
ret = create_root_hv_pci_bus(hbus);
if (ret)
goto free_windows;
return 0;
free_windows:
hv_pci_free_bridge_windows(hbus);
free_irq_domain:
irq_domain_remove(hbus->irq_domain);
free_fwnode:
irq_domain_free_fwnode(hbus->sysdata.fwnode);
unmap:
iounmap(hbus->cfg_addr);
free_config:
hv_free_config_window(hbus);
close:
vmbus_close(hdev->channel);
free_bus:
free_page((unsigned long)hbus);
return ret;
}
static void hv_pci_bus_exit(struct hv_device *hdev)
{
struct hv_pcibus_device *hbus = hv_get_drvdata(hdev);
struct {
struct pci_packet teardown_packet;
u8 buffer[sizeof(struct pci_message)];
} pkt;
struct pci_bus_relations relations;
struct hv_pci_compl comp_pkt;
int ret;
if (hdev->channel->rescind)
return;
memset(&relations, 0, sizeof(relations));
hv_pci_devices_present(hbus, &relations);
ret = hv_send_resources_released(hdev);
if (ret)
dev_err(&hdev->device,
"Couldn't send resources released packet(s)\n");
memset(&pkt.teardown_packet, 0, sizeof(pkt.teardown_packet));
init_completion(&comp_pkt.host_event);
pkt.teardown_packet.completion_func = hv_pci_generic_compl;
pkt.teardown_packet.compl_ctxt = &comp_pkt;
pkt.teardown_packet.message[0].type = PCI_BUS_D0EXIT;
ret = vmbus_sendpacket(hdev->channel, &pkt.teardown_packet.message,
sizeof(struct pci_message),
(unsigned long)&pkt.teardown_packet,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (!ret)
wait_for_completion_timeout(&comp_pkt.host_event, 10 * HZ);
}
static int hv_pci_remove(struct hv_device *hdev)
{
struct hv_pcibus_device *hbus;
hbus = hv_get_drvdata(hdev);
if (hbus->state == hv_pcibus_installed) {
pci_lock_rescan_remove();
pci_stop_root_bus(hbus->pci_bus);
pci_remove_root_bus(hbus->pci_bus);
pci_unlock_rescan_remove();
hbus->state = hv_pcibus_removed;
}
hv_pci_bus_exit(hdev);
vmbus_close(hdev->channel);
iounmap(hbus->cfg_addr);
hv_free_config_window(hbus);
pci_free_resource_list(&hbus->resources_for_children);
hv_pci_free_bridge_windows(hbus);
irq_domain_remove(hbus->irq_domain);
irq_domain_free_fwnode(hbus->sysdata.fwnode);
put_hvpcibus(hbus);
wait_for_completion(&hbus->remove_event);
free_page((unsigned long)hbus);
return 0;
}
static void __exit exit_hv_pci_drv(void)
{
vmbus_driver_unregister(&hv_pci_drv);
}
static int __init init_hv_pci_drv(void)
{
return vmbus_driver_register(&hv_pci_drv);
}
