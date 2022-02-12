int __init wil_platform_modinit(void)
{
return 0;
}
void wil_platform_modexit(void)
{
}
void *wil_platform_init(struct device *dev, struct wil_platform_ops *ops,
const struct wil_platform_rops *rops, void *wil_handle)
{
void *handle = ops;
if (!ops) {
dev_err(dev,
"Invalid parameter. Cannot init platform module\n");
return NULL;
}
return handle;
}
