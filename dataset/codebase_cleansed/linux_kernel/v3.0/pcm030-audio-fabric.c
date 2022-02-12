static __init int pcm030_fabric_init(void)
{
struct platform_device *pdev;
int rc;
if (!of_machine_is_compatible("phytec,pcm030"))
return -ENODEV;
card.name = "pcm030";
card.dai_link = pcm030_fabric_dai;
card.num_links = ARRAY_SIZE(pcm030_fabric_dai);
pdev = platform_device_alloc("soc-audio", 1);
if (!pdev) {
pr_err("pcm030_fabric_init: platform_device_alloc() failed\n");
return -ENODEV;
}
platform_set_drvdata(pdev, &card);
rc = platform_device_add(pdev);
if (rc) {
pr_err("pcm030_fabric_init: platform_device_add() failed\n");
platform_device_put(pdev);
return -ENODEV;
}
return 0;
}
