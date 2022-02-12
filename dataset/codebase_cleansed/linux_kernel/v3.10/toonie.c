static int toonie_dev_register(struct snd_device *dev)
{
return 0;
}
static int toonie_usable(struct codec_info_item *cii,
struct transfer_info *ti,
struct transfer_info *out)
{
return 1;
}
static int toonie_suspend(struct codec_info_item *cii, pm_message_t state)
{
return 0;
}
static int toonie_resume(struct codec_info_item *cii)
{
return 0;
}
static int toonie_init_codec(struct aoa_codec *codec)
{
struct toonie *toonie = codec_to_toonie(codec);
if (toonie->codec.connected != 1)
return -ENOTCONN;
if (aoa_snd_device_new(SNDRV_DEV_LOWLEVEL, toonie, &ops)) {
printk(KERN_ERR PFX "failed to create toonie snd device!\n");
return -ENODEV;
}
if (toonie->codec.soundbus_dev->attach_codec(toonie->codec.soundbus_dev,
aoa_get_card(),
&toonie_codec_info, toonie)) {
printk(KERN_ERR PFX "error creating toonie pcm\n");
snd_device_free(aoa_get_card(), toonie);
return -ENODEV;
}
return 0;
}
static void toonie_exit_codec(struct aoa_codec *codec)
{
struct toonie *toonie = codec_to_toonie(codec);
if (!toonie->codec.soundbus_dev) {
printk(KERN_ERR PFX "toonie_exit_codec called without soundbus_dev!\n");
return;
}
toonie->codec.soundbus_dev->detach_codec(toonie->codec.soundbus_dev, toonie);
}
static int __init toonie_init(void)
{
toonie = kzalloc(sizeof(struct toonie), GFP_KERNEL);
if (!toonie)
return -ENOMEM;
strlcpy(toonie->codec.name, "toonie", sizeof(toonie->codec.name));
toonie->codec.owner = THIS_MODULE;
toonie->codec.init = toonie_init_codec;
toonie->codec.exit = toonie_exit_codec;
if (aoa_codec_register(&toonie->codec)) {
kfree(toonie);
return -EINVAL;
}
return 0;
}
static void __exit toonie_exit(void)
{
aoa_codec_unregister(&toonie->codec);
kfree(toonie);
}
