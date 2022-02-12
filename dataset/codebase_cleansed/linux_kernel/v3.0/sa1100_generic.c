static int __devinit sa11x0_drv_pcmcia_probe(struct platform_device *dev)
{
int i, ret = -ENODEV;
for (i = 0; i < ARRAY_SIZE(sa11x0_pcmcia_hw_init); i++) {
ret = sa11x0_pcmcia_hw_init[i](&dev->dev);
if (ret == 0)
break;
}
return ret;
}
static int sa11x0_drv_pcmcia_remove(struct platform_device *dev)
{
struct skt_dev_info *sinfo = platform_get_drvdata(dev);
int i;
platform_set_drvdata(dev, NULL);
for (i = 0; i < sinfo->nskt; i++)
soc_pcmcia_remove_one(&sinfo->skt[i]);
kfree(sinfo);
return 0;
}
static int __init sa11x0_pcmcia_init(void)
{
return platform_driver_register(&sa11x0_pcmcia_driver);
}
static void __exit sa11x0_pcmcia_exit(void)
{
platform_driver_unregister(&sa11x0_pcmcia_driver);
}
