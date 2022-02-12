int __iorpc_arm_pollfd(int fd, int pollfd_cookie)
{
struct arm_pollfd_param temp;
struct arm_pollfd_param *params = &temp;
params->pollfd.kernel.cookie = pollfd_cookie;
return hv_dev_pwrite(fd, 0, (HV_VirtAddr) params, sizeof(*params),
IORPC_OP_ARM_POLLFD);
}
int __iorpc_close_pollfd(int fd, int pollfd_cookie)
{
struct close_pollfd_param temp;
struct close_pollfd_param *params = &temp;
params->pollfd.kernel.cookie = pollfd_cookie;
return hv_dev_pwrite(fd, 0, (HV_VirtAddr) params, sizeof(*params),
IORPC_OP_CLOSE_POLLFD);
}
int __iorpc_get_mmio_base(int fd, HV_PTE *base)
{
int __result;
struct get_mmio_base_param temp;
struct get_mmio_base_param *params = &temp;
__result =
hv_dev_pread(fd, 0, (HV_VirtAddr) params, sizeof(*params),
IORPC_OP_GET_MMIO_BASE);
*base = params->base;
return __result;
}
int __iorpc_check_mmio_offset(int fd, unsigned long offset, unsigned long size)
{
struct check_mmio_offset_param temp;
struct check_mmio_offset_param *params = &temp;
params->offset = offset;
params->size = size;
return hv_dev_pwrite(fd, 0, (HV_VirtAddr) params, sizeof(*params),
IORPC_OP_CHECK_MMIO_OFFSET);
}
