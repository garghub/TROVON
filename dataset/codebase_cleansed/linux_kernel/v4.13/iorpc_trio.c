int gxio_trio_alloc_asids(gxio_trio_context_t *context, unsigned int count,
unsigned int first, unsigned int flags)
{
struct alloc_asids_param temp;
struct alloc_asids_param *params = &temp;
params->count = count;
params->first = first;
params->flags = flags;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_ALLOC_ASIDS);
}
int gxio_trio_alloc_memory_maps(gxio_trio_context_t *context,
unsigned int count, unsigned int first,
unsigned int flags)
{
struct alloc_memory_maps_param temp;
struct alloc_memory_maps_param *params = &temp;
params->count = count;
params->first = first;
params->flags = flags;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_ALLOC_MEMORY_MAPS);
}
int gxio_trio_alloc_scatter_queues(gxio_trio_context_t *context,
unsigned int count, unsigned int first,
unsigned int flags)
{
struct alloc_scatter_queues_param temp;
struct alloc_scatter_queues_param *params = &temp;
params->count = count;
params->first = first;
params->flags = flags;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params),
GXIO_TRIO_OP_ALLOC_SCATTER_QUEUES);
}
int gxio_trio_alloc_pio_regions(gxio_trio_context_t *context,
unsigned int count, unsigned int first,
unsigned int flags)
{
struct alloc_pio_regions_param temp;
struct alloc_pio_regions_param *params = &temp;
params->count = count;
params->first = first;
params->flags = flags;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_ALLOC_PIO_REGIONS);
}
int gxio_trio_init_pio_region_aux(gxio_trio_context_t *context,
unsigned int pio_region, unsigned int mac,
uint32_t bus_address_hi, unsigned int flags)
{
struct init_pio_region_aux_param temp;
struct init_pio_region_aux_param *params = &temp;
params->pio_region = pio_region;
params->mac = mac;
params->bus_address_hi = bus_address_hi;
params->flags = flags;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_INIT_PIO_REGION_AUX);
}
int gxio_trio_init_memory_map_mmu_aux(gxio_trio_context_t *context,
unsigned int map, unsigned long va,
uint64_t size, unsigned int asid,
unsigned int mac, uint64_t bus_address,
unsigned int node,
unsigned int order_mode)
{
struct init_memory_map_mmu_aux_param temp;
struct init_memory_map_mmu_aux_param *params = &temp;
params->map = map;
params->va = va;
params->size = size;
params->asid = asid;
params->mac = mac;
params->bus_address = bus_address;
params->node = node;
params->order_mode = order_mode;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params),
GXIO_TRIO_OP_INIT_MEMORY_MAP_MMU_AUX);
}
int gxio_trio_get_port_property(gxio_trio_context_t *context,
struct pcie_trio_ports_property *trio_ports)
{
int __result;
struct get_port_property_param temp;
struct get_port_property_param *params = &temp;
__result =
hv_dev_pread(context->fd, 0, (HV_VirtAddr) params, sizeof(*params),
GXIO_TRIO_OP_GET_PORT_PROPERTY);
*trio_ports = params->trio_ports;
return __result;
}
int gxio_trio_config_legacy_intr(gxio_trio_context_t *context, int inter_x,
int inter_y, int inter_ipi, int inter_event,
unsigned int mac, unsigned int intx)
{
struct config_legacy_intr_param temp;
struct config_legacy_intr_param *params = &temp;
params->interrupt.kernel.x = inter_x;
params->interrupt.kernel.y = inter_y;
params->interrupt.kernel.ipi = inter_ipi;
params->interrupt.kernel.event = inter_event;
params->mac = mac;
params->intx = intx;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_CONFIG_LEGACY_INTR);
}
int gxio_trio_config_msi_intr(gxio_trio_context_t *context, int inter_x,
int inter_y, int inter_ipi, int inter_event,
unsigned int mac, unsigned int mem_map,
uint64_t mem_map_base, uint64_t mem_map_limit,
unsigned int asid)
{
struct config_msi_intr_param temp;
struct config_msi_intr_param *params = &temp;
params->interrupt.kernel.x = inter_x;
params->interrupt.kernel.y = inter_y;
params->interrupt.kernel.ipi = inter_ipi;
params->interrupt.kernel.event = inter_event;
params->mac = mac;
params->mem_map = mem_map;
params->mem_map_base = mem_map_base;
params->mem_map_limit = mem_map_limit;
params->asid = asid;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_CONFIG_MSI_INTR);
}
int gxio_trio_set_mps_mrs(gxio_trio_context_t *context, uint16_t mps,
uint16_t mrs, unsigned int mac)
{
struct set_mps_mrs_param temp;
struct set_mps_mrs_param *params = &temp;
params->mps = mps;
params->mrs = mrs;
params->mac = mac;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_SET_MPS_MRS);
}
int gxio_trio_force_rc_link_up(gxio_trio_context_t *context, unsigned int mac)
{
struct force_rc_link_up_param temp;
struct force_rc_link_up_param *params = &temp;
params->mac = mac;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_FORCE_RC_LINK_UP);
}
int gxio_trio_force_ep_link_up(gxio_trio_context_t *context, unsigned int mac)
{
struct force_ep_link_up_param temp;
struct force_ep_link_up_param *params = &temp;
params->mac = mac;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_FORCE_EP_LINK_UP);
}
int gxio_trio_get_mmio_base(gxio_trio_context_t *context, HV_PTE *base)
{
int __result;
struct get_mmio_base_param temp;
struct get_mmio_base_param *params = &temp;
__result =
hv_dev_pread(context->fd, 0, (HV_VirtAddr) params, sizeof(*params),
GXIO_TRIO_OP_GET_MMIO_BASE);
*base = params->base;
return __result;
}
int gxio_trio_check_mmio_offset(gxio_trio_context_t *context,
unsigned long offset, unsigned long size)
{
struct check_mmio_offset_param temp;
struct check_mmio_offset_param *params = &temp;
params->offset = offset;
params->size = size;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_TRIO_OP_CHECK_MMIO_OFFSET);
}
