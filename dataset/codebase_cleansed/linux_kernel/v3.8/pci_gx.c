resource_size_t pcibios_align_resource(void *data, const struct resource *res,
resource_size_t size, resource_size_t align)
{
return res->start;
}
static int tile_irq_cpu(int irq)
{
unsigned int count;
int i = 0;
int cpu;
count = cpumask_weight(&intr_cpus_map);
if (unlikely(count == 0)) {
pr_warning("intr_cpus_map empty, interrupts will be"
" delievered to dataplane tiles\n");
return irq % (smp_height * smp_width);
}
count = irq % count;
for_each_cpu(cpu, &intr_cpus_map) {
if (i++ == count)
break;
}
return cpu;
}
static int tile_pcie_open(int trio_index)
{
gxio_trio_context_t *context = &trio_contexts[trio_index];
int ret;
ret = gxio_trio_init(context, trio_index);
if (ret < 0)
return ret;
ret = gxio_trio_alloc_asids(context, 1, 0, 0);
if (ret < 0) {
pr_err("PCI: ASID alloc failure on TRIO %d, give up\n",
trio_index);
goto asid_alloc_failure;
}
context->asid = ret;
#ifdef USE_SHARED_PCIE_CONFIG_REGION
ret = gxio_trio_alloc_pio_regions(context, 1, 0, 0);
if (ret < 0) {
pr_err("PCI: CFG PIO alloc failure on TRIO %d, give up\n",
trio_index);
goto pio_alloc_failure;
}
context->pio_cfg_index = ret;
ret = gxio_trio_init_pio_region_aux(context, context->pio_cfg_index,
0, 0, HV_TRIO_PIO_FLAG_CONFIG_SPACE);
if (ret < 0) {
pr_err("PCI: CFG PIO init failure on TRIO %d, give up\n",
trio_index);
goto pio_alloc_failure;
}
#endif
return ret;
asid_alloc_failure:
#ifdef USE_SHARED_PCIE_CONFIG_REGION
pio_alloc_failure:
#endif
hv_dev_close(context->fd);
return ret;
}
static void
tilegx_legacy_irq_ack(struct irq_data *d)
{
__insn_mtspr(SPR_IPI_EVENT_RESET_K, 1UL << d->irq);
}
static void
tilegx_legacy_irq_mask(struct irq_data *d)
{
__insn_mtspr(SPR_IPI_MASK_SET_K, 1UL << d->irq);
}
static void
tilegx_legacy_irq_unmask(struct irq_data *d)
{
__insn_mtspr(SPR_IPI_MASK_RESET_K, 1UL << d->irq);
}
static void
trio_handle_level_irq(unsigned int irq, struct irq_desc *desc)
{
struct pci_controller *controller = irq_desc_get_handler_data(desc);
gxio_trio_context_t *trio_context = controller->trio;
uint64_t intx = (uint64_t)irq_desc_get_chip_data(desc);
int mac = controller->mac;
unsigned int reg_offset;
uint64_t level_mask;
handle_level_irq(irq, desc);
reg_offset = (TRIO_PCIE_INTFC_MAC_INT_STS <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_INTERFACE <<
TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(mac << TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
level_mask = TRIO_PCIE_INTFC_MAC_INT_STS__INT_LEVEL_MASK << intx;
__gxio_mmio_write(trio_context->mmio_base_mac + reg_offset, level_mask);
}
static int tile_init_irqs(struct pci_controller *controller)
{
int i;
int j;
int irq;
int result;
cpumask_copy(&intr_cpus_map, cpu_online_mask);
for (i = 0; i < 4; i++) {
gxio_trio_context_t *context = controller->trio;
int cpu;
irq = create_irq();
if (irq < 0) {
pr_err("PCI: no free irq vectors, failed for %d\n", i);
goto free_irqs;
}
controller->irq_intx_table[i] = irq;
cpu = tile_irq_cpu(irq);
result = gxio_trio_config_legacy_intr(context, cpu_x(cpu),
cpu_y(cpu), KERNEL_PL,
irq, controller->mac, i);
if (result < 0) {
pr_err("PCI: MAC intx config failed for %d\n", i);
goto free_irqs;
}
irq_set_chip_and_handler(irq, &tilegx_legacy_irq_chip,
trio_handle_level_irq);
irq_set_chip_data(irq, (void *)(uint64_t)i);
irq_set_handler_data(irq, controller);
}
return 0;
free_irqs:
for (j = 0; j < i; j++)
destroy_irq(controller->irq_intx_table[j]);
return -1;
}
int __init tile_pci_init(void)
{
int num_trio_shims = 0;
int ctl_index = 0;
int i, j;
if (!pci_probe) {
pr_info("PCI: disabled by boot argument\n");
return 0;
}
pr_info("PCI: Searching for controllers...\n");
for (i = 0; i < TILEGX_NUM_TRIO; i++) {
int ret;
ret = tile_pcie_open(i);
if (ret < 0)
continue;
num_trio_shims++;
}
if (num_trio_shims == 0 || sim_is_simulator())
return 0;
for (i = 0; i < TILEGX_NUM_TRIO; i++) {
gxio_trio_context_t *context = &trio_contexts[i];
int ret;
if (context->fd < 0)
continue;
ret = hv_dev_pread(context->fd, 0,
(HV_VirtAddr)&pcie_ports[i][0],
sizeof(struct pcie_port_property) * TILEGX_TRIO_PCIES,
GXIO_TRIO_OP_GET_PORT_PROPERTY);
if (ret < 0) {
pr_err("PCI: PCIE_GET_PORT_PROPERTY failure, error %d,"
" on TRIO %d\n", ret, i);
continue;
}
for (j = 0; j < TILEGX_TRIO_PCIES; j++) {
if (pcie_ports[i][j].allow_rc) {
pcie_rc[i][j] = 1;
num_rc_controllers++;
}
else if (pcie_ports[i][j].allow_ep) {
num_ep_controllers++;
}
}
}
if (num_rc_controllers == 0)
return 0;
for (i = 0; i < TILEGX_NUM_TRIO; i++) {
for (j = 0; j < TILEGX_TRIO_PCIES; j++) {
if (pcie_rc[i][j]) {
pci_controllers[ctl_index].trio =
&trio_contexts[i];
pci_controllers[ctl_index].mac = j;
pci_controllers[ctl_index].trio_index = i;
ctl_index++;
if (ctl_index == num_rc_controllers)
goto out;
}
}
}
out:
for (i = 0; i < num_rc_controllers; i++) {
struct pci_controller *controller = &pci_controllers[i];
controller->index = i;
controller->ops = &tile_cfg_ops;
controller->mem_offset = TILE_PCI_MEM_START +
(i * TILE_PCI_BAR_WINDOW_TOP);
controller->mem_space.start = controller->mem_offset +
TILE_PCI_BAR_WINDOW_TOP - TILE_PCI_BAR_WINDOW_SIZE;
controller->mem_space.end = controller->mem_offset +
TILE_PCI_BAR_WINDOW_TOP - 1;
controller->mem_space.flags = IORESOURCE_MEM;
snprintf(controller->mem_space_name,
sizeof(controller->mem_space_name),
"PCI mem domain %d", i);
controller->mem_space.name = controller->mem_space_name;
}
return num_rc_controllers;
}
static int tile_map_irq(const struct pci_dev *dev, u8 device, u8 pin)
{
struct pci_controller *controller =
(struct pci_controller *)dev->sysdata;
return controller->irq_intx_table[pin - 1];
}
static void fixup_read_and_payload_sizes(struct pci_controller *controller)
{
gxio_trio_context_t *trio_context = controller->trio;
struct pci_bus *root_bus = controller->root_bus;
TRIO_PCIE_RC_DEVICE_CONTROL_t dev_control;
TRIO_PCIE_RC_DEVICE_CAP_t rc_dev_cap;
unsigned int reg_offset;
struct pci_bus *child;
int mac;
int err;
mac = controller->mac;
reg_offset =
(TRIO_PCIE_RC_DEVICE_CONTROL <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_STANDARD <<
TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(mac << TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
dev_control.word = __gxio_mmio_read32(trio_context->mmio_base_mac +
reg_offset);
dev_control.max_read_req_sz = 5;
__gxio_mmio_write32(trio_context->mmio_base_mac + reg_offset,
dev_control.word);
reg_offset =
(TRIO_PCIE_RC_DEVICE_CAP <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_STANDARD <<
TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(mac << TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
rc_dev_cap.word = __gxio_mmio_read32(trio_context->mmio_base_mac +
reg_offset);
rc_dev_cap.mps_sup = 1;
__gxio_mmio_write32(trio_context->mmio_base_mac + reg_offset,
rc_dev_cap.word);
list_for_each_entry(child, &root_bus->children, node) {
struct pci_dev *self = child->self;
if (!self)
continue;
pcie_bus_configure_settings(child, self->pcie_mpss);
}
reg_offset =
(TRIO_PCIE_RC_DEVICE_CONTROL <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_STANDARD <<
TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(mac << TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
dev_control.word = __gxio_mmio_read32(trio_context->mmio_base_mac +
reg_offset);
err = gxio_trio_set_mps_mrs(trio_context,
dev_control.max_payload_size,
dev_control.max_read_req_sz,
mac);
if (err < 0) {
pr_err("PCI: PCIE_CONFIGURE_MAC_MPS_MRS failure, "
"MAC %d on TRIO %d\n",
mac, controller->trio_index);
}
}
static int setup_pcie_rc_delay(char *str)
{
unsigned long delay = 0;
unsigned long trio_index;
unsigned long mac;
if (str == NULL || !isdigit(*str))
return -EINVAL;
trio_index = simple_strtoul(str, (char **)&str, 10);
if (trio_index >= TILEGX_NUM_TRIO)
return -EINVAL;
if (*str != ',')
return -EINVAL;
str++;
if (!isdigit(*str))
return -EINVAL;
mac = simple_strtoul(str, (char **)&str, 10);
if (mac >= TILEGX_TRIO_PCIES)
return -EINVAL;
if (*str != '\0') {
if (*str != ',')
return -EINVAL;
str++;
if (!isdigit(*str))
return -EINVAL;
delay = simple_strtoul(str, (char **)&str, 10);
if (delay > MAX_RC_DELAY)
return -EINVAL;
}
rc_delay[trio_index][mac] = delay ? : DEFAULT_RC_DELAY;
pr_info("Delaying PCIe RC link training for %u sec"
" on MAC %lu on TRIO %lu\n", rc_delay[trio_index][mac],
mac, trio_index);
return 0;
}
int __init pcibios_init(void)
{
resource_size_t offset;
LIST_HEAD(resources);
int next_busno;
int i;
tile_pci_init();
if (num_rc_controllers == 0 && num_ep_controllers == 0)
return 0;
for (i = 0; i < TILEGX_NUM_TRIO; i++) {
gxio_trio_context_t *context = &trio_contexts[i];
if (context->fd < 0)
continue;
offset = 0;
context->mmio_base_mac =
iorpc_ioremap(context->fd, offset,
HV_TRIO_CONFIG_IOREMAP_SIZE);
if (context->mmio_base_mac == NULL) {
pr_err("PCI: MAC map failure on TRIO %d\n", i);
hv_dev_close(context->fd);
context->fd = -1;
continue;
}
}
msleep(250);
for (next_busno = 0, i = 0; i < num_rc_controllers; i++) {
struct pci_controller *controller = &pci_controllers[i];
gxio_trio_context_t *trio_context = controller->trio;
TRIO_PCIE_INTFC_PORT_CONFIG_t port_config;
TRIO_PCIE_INTFC_PORT_STATUS_t port_status;
TRIO_PCIE_INTFC_TX_FIFO_CTL_t tx_fifo_ctl;
struct pci_bus *bus;
unsigned int reg_offset;
unsigned int class_code_revision;
int trio_index;
int mac;
int ret;
if (trio_context->fd < 0)
continue;
trio_index = controller->trio_index;
mac = controller->mac;
reg_offset =
(TRIO_PCIE_INTFC_PORT_CONFIG <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_INTERFACE <<
TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(mac << TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
port_config.word =
__gxio_mmio_read(trio_context->mmio_base_mac +
reg_offset);
if ((port_config.strap_state !=
TRIO_PCIE_INTFC_PORT_CONFIG__STRAP_STATE_VAL_AUTO_CONFIG_RC) &&
(port_config.strap_state !=
TRIO_PCIE_INTFC_PORT_CONFIG__STRAP_STATE_VAL_AUTO_CONFIG_RC_G1)) {
if (port_config.strap_state ==
TRIO_PCIE_INTFC_PORT_CONFIG__STRAP_STATE_VAL_AUTO_CONFIG_ENDPOINT ||
port_config.strap_state ==
TRIO_PCIE_INTFC_PORT_CONFIG__STRAP_STATE_VAL_AUTO_CONFIG_ENDPOINT_G1)
pcie_ports[trio_index][mac].allow_ep = 1;
continue;
}
if (rc_delay[trio_index][mac])
msleep(rc_delay[trio_index][mac] * 1000);
ret = gxio_trio_force_rc_link_up(trio_context, mac);
if (ret < 0)
pr_err("PCI: PCIE_FORCE_LINK_UP failure, "
"MAC %d on TRIO %d\n", mac, trio_index);
pr_info("PCI: Found PCI controller #%d on TRIO %d MAC %d\n", i,
trio_index, controller->mac);
msleep(1000);
reg_offset =
(TRIO_PCIE_INTFC_PORT_STATUS <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_INTERFACE <<
TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(mac << TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
port_status.word =
__gxio_mmio_read(trio_context->mmio_base_mac +
reg_offset);
if (!port_status.dl_up) {
pr_err("PCI: link is down, MAC %d on TRIO %d\n",
mac, trio_index);
continue;
}
reg_offset =
(TRIO_PCIE_INTFC_TX_FIFO_CTL <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_INTERFACE <<
TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(mac << TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
tx_fifo_ctl.word =
__gxio_mmio_read(trio_context->mmio_base_mac +
reg_offset);
tx_fifo_ctl.min_p_credits = 0;
__gxio_mmio_write(trio_context->mmio_base_mac + reg_offset,
tx_fifo_ctl.word);
reg_offset =
(TRIO_PCIE_RC_DEVICE_ID_VEN_ID <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_STANDARD <<
TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(mac << TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
__gxio_mmio_write32(trio_context->mmio_base_mac + reg_offset,
(TILERA_GX36_RC_DEV_ID <<
TRIO_PCIE_RC_DEVICE_ID_VEN_ID__DEV_ID_SHIFT) |
TILERA_VENDOR_ID);
reg_offset =
(TRIO_PCIE_RC_REVISION_ID <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_STANDARD <<
TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(mac << TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
class_code_revision =
__gxio_mmio_read32(trio_context->mmio_base_mac +
reg_offset);
class_code_revision = (class_code_revision & 0xff ) |
(PCI_CLASS_BRIDGE_PCI << 16);
__gxio_mmio_write32(trio_context->mmio_base_mac +
reg_offset, class_code_revision);
#ifdef USE_SHARED_PCIE_CONFIG_REGION
offset = HV_TRIO_PIO_OFFSET(trio_context->pio_cfg_index) |
(((unsigned long long)mac) <<
TRIO_TILE_PIO_REGION_SETUP_CFG_ADDR__MAC_SHIFT);
#else
ret = gxio_trio_alloc_pio_regions(trio_context, 1, 0, 0);
if (ret < 0) {
pr_err("PCI: PCI CFG PIO alloc failure for mac %d "
"on TRIO %d, give up\n", mac, trio_index);
continue;
}
trio_context->pio_cfg_index[mac] = ret;
ret = gxio_trio_init_pio_region_aux(trio_context,
trio_context->pio_cfg_index[mac],
mac, 0, HV_TRIO_PIO_FLAG_CONFIG_SPACE);
if (ret < 0) {
pr_err("PCI: PCI CFG PIO init failure for mac %d "
"on TRIO %d, give up\n", mac, trio_index);
continue;
}
offset = HV_TRIO_PIO_OFFSET(trio_context->pio_cfg_index[mac]) |
(((unsigned long long)mac) <<
TRIO_TILE_PIO_REGION_SETUP_CFG_ADDR__MAC_SHIFT);
#endif
trio_context->mmio_base_pio_cfg[mac] =
iorpc_ioremap(trio_context->fd, offset,
(1 << TRIO_TILE_PIO_REGION_SETUP_CFG_ADDR__MAC_SHIFT));
if (trio_context->mmio_base_pio_cfg[mac] == NULL) {
pr_err("PCI: PIO map failure for mac %d on TRIO %d\n",
mac, trio_index);
continue;
}
if (tile_init_irqs(controller)) {
pr_err("PCI: IRQs init failure for mac %d on TRIO %d\n",
mac, trio_index);
continue;
}
pci_add_resource_offset(&resources, &controller->mem_space,
controller->mem_offset);
controller->first_busno = next_busno;
bus = pci_scan_root_bus(NULL, next_busno, controller->ops,
controller, &resources);
controller->root_bus = bus;
next_busno = bus->busn_res.end + 1;
}
pci_fixup_irqs(pci_common_swizzle, tile_map_irq);
pci_assign_unassigned_resources();
for (i = 0; i < num_rc_controllers; i++) {
struct pci_controller *controller = &pci_controllers[i];
gxio_trio_context_t *trio_context = controller->trio;
struct pci_bus *root_bus = pci_controllers[i].root_bus;
struct pci_bus *next_bus;
uint32_t bus_address_hi;
struct pci_dev *dev;
int ret;
int j;
if (root_bus == NULL)
continue;
fixup_read_and_payload_sizes(controller);
list_for_each_entry(dev, &root_bus->devices, bus_list) {
if ((dev->class >> 8) == PCI_CLASS_BRIDGE_PCI &&
(PCI_SLOT(dev->devfn) == 0)) {
next_bus = dev->subordinate;
pci_controllers[i].mem_resources[0] =
*next_bus->resource[0];
pci_controllers[i].mem_resources[1] =
*next_bus->resource[1];
pci_controllers[i].mem_resources[2] =
*next_bus->resource[2];
break;
}
}
if (pci_controllers[i].mem_resources[1].flags & IORESOURCE_MEM)
bus_address_hi =
pci_controllers[i].mem_resources[1].start >> 32;
else if (pci_controllers[i].mem_resources[2].flags & IORESOURCE_PREFETCH)
bus_address_hi =
pci_controllers[i].mem_resources[2].start >> 32;
else {
pr_err("PCI: no memory resources on TRIO %d mac %d\n",
controller->trio_index, controller->mac);
continue;
}
ret = gxio_trio_alloc_pio_regions(trio_context, 1, 0, 0);
if (ret < 0) {
pr_err("PCI: MEM PIO alloc failure on TRIO %d mac %d, "
"give up\n", controller->trio_index,
controller->mac);
continue;
}
controller->pio_mem_index = ret;
ret = gxio_trio_init_pio_region_aux(trio_context,
controller->pio_mem_index,
controller->mac,
0,
0);
if (ret < 0) {
pr_err("PCI: MEM PIO init failure on TRIO %d mac %d, "
"give up\n", controller->trio_index,
controller->mac);
continue;
}
for_each_online_node(j) {
unsigned long start_pfn = node_start_pfn[j];
unsigned long end_pfn = node_end_pfn[j];
unsigned long nr_pages = end_pfn - start_pfn;
ret = gxio_trio_alloc_memory_maps(trio_context, 1, 0,
0);
if (ret < 0) {
pr_err("PCI: Mem-Map alloc failure on TRIO %d "
"mac %d for MC %d, give up\n",
controller->trio_index,
controller->mac, j);
goto alloc_mem_map_failed;
}
controller->mem_maps[j] = ret;
ret = gxio_trio_init_memory_map_mmu_aux(trio_context,
controller->mem_maps[j],
start_pfn << PAGE_SHIFT,
nr_pages << PAGE_SHIFT,
trio_context->asid,
controller->mac,
(start_pfn << PAGE_SHIFT) +
TILE_PCI_MEM_MAP_BASE_OFFSET,
j,
GXIO_TRIO_ORDER_MODE_UNORDERED);
if (ret < 0) {
pr_err("PCI: Mem-Map init failure on TRIO %d "
"mac %d for MC %d, give up\n",
controller->trio_index,
controller->mac, j);
goto alloc_mem_map_failed;
}
continue;
alloc_mem_map_failed:
break;
}
}
return 0;
}
void pcibios_fixup_bus(struct pci_bus *bus)
{
}
char *pcibios_setup(char *str)
{
if (!strcmp(str, "off")) {
pci_probe = 0;
return NULL;
}
return str;
}
int pcibios_enable_device(struct pci_dev *dev, int mask)
{
return pci_enable_resources(dev, mask);
}
static void pcibios_fixup_final(struct pci_dev *pdev)
{
set_dma_ops(&pdev->dev, gx_pci_dma_map_ops);
set_dma_offset(&pdev->dev, TILE_PCI_MEM_MAP_BASE_OFFSET);
pdev->dev.archdata.max_direct_dma_addr =
TILE_PCI_MAX_DIRECT_DMA_ADDRESS;
}
void __iomem *ioremap(resource_size_t phys_addr, unsigned long size)
{
struct pci_controller *controller = NULL;
resource_size_t bar_start;
resource_size_t bar_end;
resource_size_t offset;
resource_size_t start;
resource_size_t end;
int trio_fd;
int i, j;
start = phys_addr;
end = phys_addr + size - 1;
for (i = 0; i < num_rc_controllers; i++) {
if (pci_controllers[i].root_bus == NULL)
continue;
for (j = 1; j < 3; j++) {
bar_start =
pci_controllers[i].mem_resources[j].start;
bar_end =
pci_controllers[i].mem_resources[j].end;
if ((start >= bar_start) && (end <= bar_end)) {
controller = &pci_controllers[i];
goto got_it;
}
}
}
if (controller == NULL)
return NULL;
got_it:
trio_fd = controller->trio->fd;
start = phys_addr - controller->mem_offset;
offset = HV_TRIO_PIO_OFFSET(controller->pio_mem_index) + start;
return iorpc_ioremap(trio_fd, offset, size) +
(phys_addr & (PAGE_SIZE - 1));
}
void pci_iounmap(struct pci_dev *dev, void __iomem *addr)
{
iounmap(addr);
}
static int tile_cfg_read(struct pci_bus *bus, unsigned int devfn, int offset,
int size, u32 *val)
{
struct pci_controller *controller = bus->sysdata;
gxio_trio_context_t *trio_context = controller->trio;
int busnum = bus->number & 0xff;
int device = PCI_SLOT(devfn);
int function = PCI_FUNC(devfn);
int config_type = 1;
TRIO_TILE_PIO_REGION_SETUP_CFG_ADDR_t cfg_addr;
void *mmio_addr;
if (pci_is_root_bus(bus)) {
if (device == 0) {
unsigned int reg_offset;
reg_offset = ((offset & 0xFFF) <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_PROTECTED
<< TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(controller->mac <<
TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
mmio_addr = trio_context->mmio_base_mac + reg_offset;
goto valid_device;
} else {
goto invalid_device;
}
}
if (busnum == (controller->first_busno + 1)) {
if (device != 0)
goto invalid_device;
config_type = 0;
}
cfg_addr.word = 0;
cfg_addr.reg_addr = (offset & 0xFFF);
cfg_addr.fn = function;
cfg_addr.dev = device;
cfg_addr.bus = busnum;
cfg_addr.type = config_type;
mmio_addr = trio_context->mmio_base_pio_cfg[controller->mac] +
cfg_addr.word;
valid_device:
switch (size) {
case 4:
*val = __gxio_mmio_read32(mmio_addr);
break;
case 2:
*val = __gxio_mmio_read16(mmio_addr);
break;
case 1:
*val = __gxio_mmio_read8(mmio_addr);
break;
default:
return PCIBIOS_FUNC_NOT_SUPPORTED;
}
TRACE_CFG_RD(size, *val, busnum, device, function, offset);
return 0;
invalid_device:
switch (size) {
case 4:
*val = 0xFFFFFFFF;
break;
case 2:
*val = 0xFFFF;
break;
case 1:
*val = 0xFF;
break;
default:
return PCIBIOS_FUNC_NOT_SUPPORTED;
}
return 0;
}
static int tile_cfg_write(struct pci_bus *bus, unsigned int devfn, int offset,
int size, u32 val)
{
struct pci_controller *controller = bus->sysdata;
gxio_trio_context_t *trio_context = controller->trio;
int busnum = bus->number & 0xff;
int device = PCI_SLOT(devfn);
int function = PCI_FUNC(devfn);
int config_type = 1;
TRIO_TILE_PIO_REGION_SETUP_CFG_ADDR_t cfg_addr;
void *mmio_addr;
u32 val_32 = (u32)val;
u16 val_16 = (u16)val;
u8 val_8 = (u8)val;
if (pci_is_root_bus(bus)) {
if (device == 0) {
unsigned int reg_offset;
reg_offset = ((offset & 0xFFF) <<
TRIO_CFG_REGION_ADDR__REG_SHIFT) |
(TRIO_CFG_REGION_ADDR__INTFC_VAL_MAC_PROTECTED
<< TRIO_CFG_REGION_ADDR__INTFC_SHIFT ) |
(controller->mac <<
TRIO_CFG_REGION_ADDR__MAC_SEL_SHIFT);
mmio_addr = trio_context->mmio_base_mac + reg_offset;
goto valid_device;
} else {
goto invalid_device;
}
}
if (busnum == (controller->first_busno + 1)) {
if (device != 0)
goto invalid_device;
config_type = 0;
}
cfg_addr.word = 0;
cfg_addr.reg_addr = (offset & 0xFFF);
cfg_addr.fn = function;
cfg_addr.dev = device;
cfg_addr.bus = busnum;
cfg_addr.type = config_type;
mmio_addr = trio_context->mmio_base_pio_cfg[controller->mac] +
cfg_addr.word;
valid_device:
switch (size) {
case 4:
__gxio_mmio_write32(mmio_addr, val_32);
TRACE_CFG_WR(size, val_32, busnum, device, function, offset);
break;
case 2:
__gxio_mmio_write16(mmio_addr, val_16);
TRACE_CFG_WR(size, val_16, busnum, device, function, offset);
break;
case 1:
__gxio_mmio_write8(mmio_addr, val_8);
TRACE_CFG_WR(size, val_8, busnum, device, function, offset);
break;
default:
return PCIBIOS_FUNC_NOT_SUPPORTED;
}
invalid_device:
return 0;
}
static unsigned int
tilegx_msi_startup(struct irq_data *d)
{
if (d->msi_desc)
unmask_msi_irq(d);
return 0;
}
static void
tilegx_msi_ack(struct irq_data *d)
{
__insn_mtspr(SPR_IPI_EVENT_RESET_K, 1UL << d->irq);
}
static void
tilegx_msi_mask(struct irq_data *d)
{
mask_msi_irq(d);
__insn_mtspr(SPR_IPI_MASK_SET_K, 1UL << d->irq);
}
static void
tilegx_msi_unmask(struct irq_data *d)
{
__insn_mtspr(SPR_IPI_MASK_RESET_K, 1UL << d->irq);
unmask_msi_irq(d);
}
int arch_setup_msi_irq(struct pci_dev *pdev, struct msi_desc *desc)
{
struct pci_controller *controller;
gxio_trio_context_t *trio_context;
struct msi_msg msg;
int default_irq;
uint64_t mem_map_base;
uint64_t mem_map_limit;
u64 msi_addr;
int mem_map;
int cpu;
int irq;
int ret;
irq = create_irq();
if (irq < 0)
return irq;
if (desc->msi_attrib.is_64 == 0) {
dev_printk(KERN_INFO, &pdev->dev,
"64-bit MSI message address not supported, "
"falling back to legacy interrupts.\n");
ret = -ENOMEM;
goto is_64_failure;
}
default_irq = desc->msi_attrib.default_irq;
controller = irq_get_handler_data(default_irq);
BUG_ON(!controller);
trio_context = controller->trio;
mem_map = gxio_trio_alloc_memory_maps(trio_context, 1, 0, 0);
if (mem_map < 0) {
dev_printk(KERN_INFO, &pdev->dev,
"%s Mem-Map alloc failure. "
"Failed to initialize MSI interrupts. "
"Falling back to legacy interrupts.\n",
desc->msi_attrib.is_msix ? "MSI-X" : "MSI");
ret = -ENOMEM;
goto msi_mem_map_alloc_failure;
}
cpu = tile_irq_cpu(irq);
mem_map_base = MEM_MAP_INTR_REGIONS_BASE +
mem_map * MEM_MAP_INTR_REGION_SIZE;
mem_map_limit = mem_map_base + MEM_MAP_INTR_REGION_SIZE - 1;
ret = gxio_trio_config_msi_intr(trio_context, cpu_x(cpu), cpu_y(cpu),
KERNEL_PL, irq, controller->mac,
mem_map, mem_map_base, mem_map_limit,
trio_context->asid);
if (ret < 0) {
dev_printk(KERN_INFO, &pdev->dev, "HV MSI config failed.\n");
goto hv_msi_config_failure;
}
irq_set_msi_desc(irq, desc);
msi_addr = mem_map_base + TRIO_MAP_MEM_REG_INT3 - TRIO_MAP_MEM_REG_INT0;
msg.address_hi = msi_addr >> 32;
msg.address_lo = msi_addr & 0xffffffff;
msg.data = mem_map;
write_msi_msg(irq, &msg);
irq_set_chip_and_handler(irq, &tilegx_msi_chip, handle_level_irq);
irq_set_handler_data(irq, controller);
return 0;
hv_msi_config_failure:
msi_mem_map_alloc_failure:
is_64_failure:
destroy_irq(irq);
return ret;
}
void arch_teardown_msi_irq(unsigned int irq)
{
destroy_irq(irq);
}
