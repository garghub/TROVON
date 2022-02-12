static int __init txx9aclc_generic_probe(struct platform_device *pdev)
{
int ret;
soc_pdev = platform_device_alloc("soc-audio", -1);
if (!soc_pdev)
return -ENOMEM;
platform_set_drvdata(soc_pdev, &txx9aclc_generic_card);
ret = platform_device_add(soc_pdev);
if (ret) {
platform_device_put(soc_pdev);
return ret;
}
return 0;
}
static int __exit txx9aclc_generic_remove(struct platform_device *pdev)
{
platform_device_unregister(soc_pdev);
return 0;
}
static int __init txx9aclc_generic_init(void)
{
return platform_driver_probe(&txx9aclc_generic_driver,
txx9aclc_generic_probe);
}
static void __exit txx9aclc_generic_exit(void)
{
platform_driver_unregister(&txx9aclc_generic_driver);
}
