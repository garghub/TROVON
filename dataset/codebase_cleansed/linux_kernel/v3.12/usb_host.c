int gxio_usb_host_init(gxio_usb_host_context_t *context, int usb_index,
int is_ehci)
{
char file[32];
int fd;
if (is_ehci)
snprintf(file, sizeof(file), "usb_host/%d/iorpc/ehci",
usb_index);
else
snprintf(file, sizeof(file), "usb_host/%d/iorpc/ohci",
usb_index);
fd = hv_dev_open((HV_VirtAddr) file, 0);
if (fd < 0) {
if (fd >= GXIO_ERR_MIN && fd <= GXIO_ERR_MAX)
return fd;
else
return -ENODEV;
}
context->fd = fd;
context->mmio_base =
(void __force *)iorpc_ioremap(fd, 0, HV_USB_HOST_MMIO_SIZE);
if (context->mmio_base == NULL) {
hv_dev_close(context->fd);
return -ENODEV;
}
return 0;
}
int gxio_usb_host_destroy(gxio_usb_host_context_t *context)
{
iounmap((void __force __iomem *)(context->mmio_base));
hv_dev_close(context->fd);
context->mmio_base = NULL;
context->fd = -1;
return 0;
}
void *gxio_usb_host_get_reg_start(gxio_usb_host_context_t *context)
{
return context->mmio_base;
}
size_t gxio_usb_host_get_reg_len(gxio_usb_host_context_t *context)
{
return HV_USB_HOST_MMIO_SIZE;
}
