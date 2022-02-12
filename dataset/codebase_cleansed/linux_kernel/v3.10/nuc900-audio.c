static int __init nuc900evb_audio_init(void)
{
int ret;
ret = -ENOMEM;
nuc900evb_asoc_dev = platform_device_alloc("soc-audio", -1);
if (!nuc900evb_asoc_dev)
goto out;
platform_set_drvdata(nuc900evb_asoc_dev, &nuc900evb_audio_machine);
ret = platform_device_add(nuc900evb_asoc_dev);
if (ret) {
platform_device_put(nuc900evb_asoc_dev);
nuc900evb_asoc_dev = NULL;
}
out:
return ret;
}
static void __exit nuc900evb_audio_exit(void)
{
platform_device_unregister(nuc900evb_asoc_dev);
}
