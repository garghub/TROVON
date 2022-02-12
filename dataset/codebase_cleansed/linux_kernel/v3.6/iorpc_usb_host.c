int gxio_usb_host_cfg_interrupt(gxio_usb_host_context_t * context, int inter_x,
int inter_y, int inter_ipi, int inter_event)
{
struct cfg_interrupt_param temp;
struct cfg_interrupt_param *params = &temp;
params->interrupt.kernel.x = inter_x;
params->interrupt.kernel.y = inter_y;
params->interrupt.kernel.ipi = inter_ipi;
params->interrupt.kernel.event = inter_event;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params), GXIO_USB_HOST_OP_CFG_INTERRUPT);
}
int gxio_usb_host_register_client_memory(gxio_usb_host_context_t * context,
HV_PTE pte, unsigned int flags)
{
struct register_client_memory_param temp;
struct register_client_memory_param *params = &temp;
params->pte = pte;
params->flags = flags;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params),
GXIO_USB_HOST_OP_REGISTER_CLIENT_MEMORY);
}
int gxio_usb_host_get_mmio_base(gxio_usb_host_context_t * context, HV_PTE *base)
{
int __result;
struct get_mmio_base_param temp;
struct get_mmio_base_param *params = &temp;
__result =
hv_dev_pread(context->fd, 0, (HV_VirtAddr) params, sizeof(*params),
GXIO_USB_HOST_OP_GET_MMIO_BASE);
*base = params->base;
return __result;
}
int gxio_usb_host_check_mmio_offset(gxio_usb_host_context_t * context,
unsigned long offset, unsigned long size)
{
struct check_mmio_offset_param temp;
struct check_mmio_offset_param *params = &temp;
params->offset = offset;
params->size = size;
return hv_dev_pwrite(context->fd, 0, (HV_VirtAddr) params,
sizeof(*params),
GXIO_USB_HOST_OP_CHECK_MMIO_OFFSET);
}
