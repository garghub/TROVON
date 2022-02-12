static int verb_write_ioctl(struct hda_codec *codec,
struct hda_verb_ioctl __user *arg)
{
u32 verb, res;
if (get_user(verb, &arg->verb))
return -EFAULT;
res = snd_hda_codec_read(codec, verb >> 24, 0,
(verb >> 8) & 0xffff, verb & 0xff);
if (put_user(res, &arg->res))
return -EFAULT;
return 0;
}
static int get_wcap_ioctl(struct hda_codec *codec,
struct hda_verb_ioctl __user *arg)
{
u32 verb, res;
if (get_user(verb, &arg->verb))
return -EFAULT;
res = get_wcaps(codec, verb >> 24);
if (put_user(res, &arg->res))
return -EFAULT;
return 0;
}
static int hda_hwdep_ioctl(struct snd_hwdep *hw, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct hda_codec *codec = hw->private_data;
void __user *argp = (void __user *)arg;
switch (cmd) {
case HDA_IOCTL_PVERSION:
return put_user(HDA_HWDEP_VERSION, (int __user *)argp);
case HDA_IOCTL_VERB_WRITE:
return verb_write_ioctl(codec, argp);
case HDA_IOCTL_GET_WCAP:
return get_wcap_ioctl(codec, argp);
}
return -ENOIOCTLCMD;
}
static int hda_hwdep_ioctl_compat(struct snd_hwdep *hw, struct file *file,
unsigned int cmd, unsigned long arg)
{
return hda_hwdep_ioctl(hw, file, cmd, (unsigned long)compat_ptr(arg));
}
static int hda_hwdep_open(struct snd_hwdep *hw, struct file *file)
{
#ifndef CONFIG_SND_DEBUG_VERBOSE
if (!capable(CAP_SYS_RAWIO))
return -EACCES;
#endif
return 0;
}
int snd_hda_create_hwdep(struct hda_codec *codec)
{
char hwname[16];
struct snd_hwdep *hwdep;
int err;
sprintf(hwname, "HDA Codec %d", codec->addr);
err = snd_hwdep_new(codec->bus->card, hwname, codec->addr, &hwdep);
if (err < 0)
return err;
codec->hwdep = hwdep;
sprintf(hwdep->name, "HDA Codec %d", codec->addr);
hwdep->iface = SNDRV_HWDEP_IFACE_HDA;
hwdep->private_data = codec;
hwdep->exclusive = 1;
hwdep->ops.open = hda_hwdep_open;
hwdep->ops.ioctl = hda_hwdep_ioctl;
#ifdef CONFIG_COMPAT
hwdep->ops.ioctl_compat = hda_hwdep_ioctl_compat;
#endif
hwdep->dev.parent = &codec->dev;
hwdep->dev.groups = snd_hda_dev_attr_groups;
dev_set_drvdata(&hwdep->dev, codec);
return 0;
}
