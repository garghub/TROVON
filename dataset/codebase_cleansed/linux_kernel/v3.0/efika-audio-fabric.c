static __init int efika_fabric_init(void)
{
struct platform_device *pdev;
int rc;
if (!of_machine_is_compatible("bplan,efika"))
return -ENODEV;
card.name = "Efika";
card.dai_link = efika_fabric_dai;
card.num_links = ARRAY_SIZE(efika_fabric_dai);
pdev = platform_device_alloc("soc-audio", 1);
if (!pdev) {
pr_err("efika_fabric_init: platform_device_alloc() failed\n");
return -ENODEV;
}
platform_set_drvdata(pdev, &card);
rc = platform_device_add(pdev);
if (rc) {
pr_err("efika_fabric_init: platform_device_add() failed\n");
platform_device_put(pdev);
return -ENODEV;
}
return 0;
}
