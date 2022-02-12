int gxio_mpipe_info_enumerate_aux(gxio_mpipe_info_context_t * context,
unsigned int idx,
_gxio_mpipe_link_name_t * name,
_gxio_mpipe_link_mac_t * mac)
{
int __result;
struct enumerate_aux_param temp;
struct enumerate_aux_param *params = &temp;
__result =
hv_dev_pread(context->fd, 0, (HV_VirtAddr) params, sizeof(*params),
(((uint64_t) idx << 32) |
GXIO_MPIPE_INFO_OP_ENUMERATE_AUX));
*name = params->name;
*mac = params->mac;
return __result;
}
int gxio_mpipe_info_get_mmio_base(gxio_mpipe_info_context_t * context,
HV_PTE *base)
{
int __result;
struct get_mmio_base_param temp;
struct get_mmio_base_param *params = &temp;
__result =
hv_dev_pread(context->fd, 0, (HV_VirtAddr) params, sizeof(*params),
GXIO_MPIPE_INFO_OP_GET_MMIO_BASE);
*base = params->base;
return __result;
}
int gxio_mpipe_info_check_mmio_offset(gxio_mpipe_info_context_t * context,
unsigned long offset, unsigned long size)
{
struct check_mmio_offset_param temp;
struct check_mmio_offset_param *params = &temp;
params->offset = offset;
params->size = size;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params),
GXIO_MPIPE_INFO_OP_CHECK_MMIO_OFFSET);
}
