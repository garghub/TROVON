static void umc_device_release(struct device *dev)
{
struct umc_dev *umc = to_umc_dev(dev);
kfree(umc);
}
struct umc_dev *umc_device_create(struct device *parent, int n)
{
struct umc_dev *umc;
umc = kzalloc(sizeof(struct umc_dev), GFP_KERNEL);
if (umc) {
dev_set_name(&umc->dev, "%s-%d", dev_name(parent), n);
umc->dev.parent = parent;
umc->dev.bus = &umc_bus_type;
umc->dev.release = umc_device_release;
umc->dev.dma_mask = parent->dma_mask;
}
return umc;
}
int umc_device_register(struct umc_dev *umc)
{
int err;
err = request_resource(umc->resource.parent, &umc->resource);
if (err < 0) {
dev_err(&umc->dev, "can't allocate resource range %pR: %d\n",
&umc->resource, err);
goto error_request_resource;
}
err = device_register(&umc->dev);
if (err < 0)
goto error_device_register;
return 0;
error_device_register:
release_resource(&umc->resource);
error_request_resource:
return err;
}
void umc_device_unregister(struct umc_dev *umc)
{
struct device *dev;
if (!umc)
return;
dev = get_device(&umc->dev);
device_unregister(&umc->dev);
release_resource(&umc->resource);
put_device(dev);
}
