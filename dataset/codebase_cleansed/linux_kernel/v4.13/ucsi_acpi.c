static int ucsi_acpi_dsm(struct ucsi_acpi *ua, int func)
{
union acpi_object *obj;
obj = acpi_evaluate_dsm(ACPI_HANDLE(ua->dev), &ua->guid, 1, func,
NULL);
if (!obj) {
dev_err(ua->dev, "%s: failed to evaluate _DSM %d\n",
__func__, func);
return -EIO;
}
ACPI_FREE(obj);
return 0;
}
static int ucsi_acpi_cmd(struct ucsi_ppm *ppm, struct ucsi_control *ctrl)
{
struct ucsi_acpi *ua = container_of(ppm, struct ucsi_acpi, ppm);
ppm->data->ctrl.raw_cmd = ctrl->raw_cmd;
return ucsi_acpi_dsm(ua, UCSI_DSM_FUNC_WRITE);
}
static int ucsi_acpi_sync(struct ucsi_ppm *ppm)
{
struct ucsi_acpi *ua = container_of(ppm, struct ucsi_acpi, ppm);
return ucsi_acpi_dsm(ua, UCSI_DSM_FUNC_READ);
}
static void ucsi_acpi_notify(acpi_handle handle, u32 event, void *data)
{
struct ucsi_acpi *ua = data;
ucsi_notify(ua->ucsi);
}
static int ucsi_acpi_probe(struct platform_device *pdev)
{
struct ucsi_acpi *ua;
struct resource *res;
acpi_status status;
int ret;
ua = devm_kzalloc(&pdev->dev, sizeof(*ua), GFP_KERNEL);
if (!ua)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "missing memory resource\n");
return -ENODEV;
}
ua->ppm.data = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!ua->ppm.data)
return -ENOMEM;
if (!ua->ppm.data->version)
return -ENODEV;
ret = guid_parse(UCSI_DSM_UUID, &ua->guid);
if (ret)
return ret;
ua->ppm.cmd = ucsi_acpi_cmd;
ua->ppm.sync = ucsi_acpi_sync;
ua->dev = &pdev->dev;
status = acpi_install_notify_handler(ACPI_HANDLE(&pdev->dev),
ACPI_DEVICE_NOTIFY,
ucsi_acpi_notify, ua);
if (ACPI_FAILURE(status)) {
dev_err(&pdev->dev, "failed to install notify handler\n");
return -ENODEV;
}
ua->ucsi = ucsi_register_ppm(&pdev->dev, &ua->ppm);
if (IS_ERR(ua->ucsi)) {
acpi_remove_notify_handler(ACPI_HANDLE(&pdev->dev),
ACPI_DEVICE_NOTIFY,
ucsi_acpi_notify);
return PTR_ERR(ua->ucsi);
}
platform_set_drvdata(pdev, ua);
return 0;
}
static int ucsi_acpi_remove(struct platform_device *pdev)
{
struct ucsi_acpi *ua = platform_get_drvdata(pdev);
ucsi_unregister_ppm(ua->ucsi);
acpi_remove_notify_handler(ACPI_HANDLE(&pdev->dev), ACPI_DEVICE_NOTIFY,
ucsi_acpi_notify);
return 0;
}
