static int qcom_apcs_ipc_send_data(struct mbox_chan *chan, void *data)
{
struct qcom_apcs_ipc *apcs = container_of(chan->mbox,
struct qcom_apcs_ipc, mbox);
unsigned long idx = (unsigned long)chan->con_priv;
writel(BIT(idx), apcs->reg);
return 0;
}
static int qcom_apcs_ipc_probe(struct platform_device *pdev)
{
struct qcom_apcs_ipc *apcs;
struct resource *res;
unsigned long offset;
void __iomem *base;
unsigned long i;
int ret;
apcs = devm_kzalloc(&pdev->dev, sizeof(*apcs), GFP_KERNEL);
if (!apcs)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
offset = (unsigned long)of_device_get_match_data(&pdev->dev);
apcs->reg = base + offset;
for (i = 0; i < ARRAY_SIZE(apcs->mbox_chans); i++)
apcs->mbox_chans[i].con_priv = (void *)i;
apcs->mbox.dev = &pdev->dev;
apcs->mbox.ops = &qcom_apcs_ipc_ops;
apcs->mbox.chans = apcs->mbox_chans;
apcs->mbox.num_chans = ARRAY_SIZE(apcs->mbox_chans);
ret = mbox_controller_register(&apcs->mbox);
if (ret) {
dev_err(&pdev->dev, "failed to register APCS IPC controller\n");
return ret;
}
platform_set_drvdata(pdev, apcs);
return 0;
}
static int qcom_apcs_ipc_remove(struct platform_device *pdev)
{
struct qcom_apcs_ipc *apcs = platform_get_drvdata(pdev);
mbox_controller_unregister(&apcs->mbox);
return 0;
}
static int __init qcom_apcs_ipc_init(void)
{
return platform_driver_register(&qcom_apcs_ipc_driver);
}
static void __exit qcom_apcs_ipc_exit(void)
{
platform_driver_unregister(&qcom_apcs_ipc_driver);
}
