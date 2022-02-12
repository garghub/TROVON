int gxio_trio_init(gxio_trio_context_t *context, unsigned int trio_index)
{
char file[32];
int fd;
snprintf(file, sizeof(file), "trio/%d/iorpc", trio_index);
fd = hv_dev_open((HV_VirtAddr) file, 0);
if (fd < 0) {
context->fd = -1;
if (fd >= GXIO_ERR_MIN && fd <= GXIO_ERR_MAX)
return fd;
else
return -ENODEV;
}
context->fd = fd;
return 0;
}
