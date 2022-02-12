void *wil_platform_init(struct device *dev, struct wil_platform_ops *ops)
{
void *handle = NULL;
if (!ops) {
dev_err(dev, "Invalid parameter. Cannot init platform module\n");
return NULL;
}
return handle;
}
