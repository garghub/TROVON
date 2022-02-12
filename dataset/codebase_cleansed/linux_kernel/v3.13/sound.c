void snd_request_card(int card)
{
if (snd_card_locked(card))
return;
if (card < 0 || card >= cards_limit)
return;
request_module("snd-card-%i", card);
}
static void snd_request_other(int minor)
{
char *str;
switch (minor) {
case SNDRV_MINOR_SEQUENCER: str = "snd-seq"; break;
case SNDRV_MINOR_TIMER: str = "snd-timer"; break;
default: return;
}
request_module(str);
}
void *snd_lookup_minor_data(unsigned int minor, int type)
{
struct snd_minor *mreg;
void *private_data;
if (minor >= ARRAY_SIZE(snd_minors))
return NULL;
mutex_lock(&sound_mutex);
mreg = snd_minors[minor];
if (mreg && mreg->type == type) {
private_data = mreg->private_data;
if (private_data && mreg->card_ptr)
atomic_inc(&mreg->card_ptr->refcount);
} else
private_data = NULL;
mutex_unlock(&sound_mutex);
return private_data;
}
static struct snd_minor *autoload_device(unsigned int minor)
{
int dev;
mutex_unlock(&sound_mutex);
dev = SNDRV_MINOR_DEVICE(minor);
if (dev == SNDRV_MINOR_CONTROL) {
int card = SNDRV_MINOR_CARD(minor);
if (snd_cards[card] == NULL)
snd_request_card(card);
} else if (dev == SNDRV_MINOR_GLOBAL) {
snd_request_other(minor);
}
mutex_lock(&sound_mutex);
return snd_minors[minor];
}
static int snd_open(struct inode *inode, struct file *file)
{
unsigned int minor = iminor(inode);
struct snd_minor *mptr = NULL;
const struct file_operations *new_fops;
int err = 0;
if (minor >= ARRAY_SIZE(snd_minors))
return -ENODEV;
mutex_lock(&sound_mutex);
mptr = snd_minors[minor];
if (mptr == NULL) {
mptr = autoload_device(minor);
if (!mptr) {
mutex_unlock(&sound_mutex);
return -ENODEV;
}
}
new_fops = fops_get(mptr->f_ops);
mutex_unlock(&sound_mutex);
if (!new_fops)
return -ENODEV;
replace_fops(file, new_fops);
if (file->f_op->open)
err = file->f_op->open(inode, file);
return err;
}
static int snd_find_free_minor(int type)
{
int minor;
if (type == SNDRV_DEVICE_TYPE_SEQUENCER)
return SNDRV_MINOR_SEQUENCER;
if (type == SNDRV_DEVICE_TYPE_TIMER)
return SNDRV_MINOR_TIMER;
for (minor = 0; minor < ARRAY_SIZE(snd_minors); ++minor) {
if (SNDRV_MINOR_DEVICE(minor) == SNDRV_MINOR_CONTROL)
continue;
if (minor == SNDRV_MINOR_SEQUENCER ||
minor == SNDRV_MINOR_TIMER)
continue;
if (!snd_minors[minor])
return minor;
}
return -EBUSY;
}
static int snd_kernel_minor(int type, struct snd_card *card, int dev)
{
int minor;
switch (type) {
case SNDRV_DEVICE_TYPE_SEQUENCER:
case SNDRV_DEVICE_TYPE_TIMER:
minor = type;
break;
case SNDRV_DEVICE_TYPE_CONTROL:
if (snd_BUG_ON(!card))
return -EINVAL;
minor = SNDRV_MINOR(card->number, type);
break;
case SNDRV_DEVICE_TYPE_HWDEP:
case SNDRV_DEVICE_TYPE_RAWMIDI:
case SNDRV_DEVICE_TYPE_PCM_PLAYBACK:
case SNDRV_DEVICE_TYPE_PCM_CAPTURE:
case SNDRV_DEVICE_TYPE_COMPRESS:
if (snd_BUG_ON(!card))
return -EINVAL;
minor = SNDRV_MINOR(card->number, type + dev);
break;
default:
return -EINVAL;
}
if (snd_BUG_ON(minor < 0 || minor >= SNDRV_OS_MINORS))
return -EINVAL;
return minor;
}
int snd_register_device_for_dev(int type, struct snd_card *card, int dev,
const struct file_operations *f_ops,
void *private_data,
const char *name, struct device *device)
{
int minor;
struct snd_minor *preg;
if (snd_BUG_ON(!name))
return -EINVAL;
preg = kmalloc(sizeof *preg, GFP_KERNEL);
if (preg == NULL)
return -ENOMEM;
preg->type = type;
preg->card = card ? card->number : -1;
preg->device = dev;
preg->f_ops = f_ops;
preg->private_data = private_data;
preg->card_ptr = card;
mutex_lock(&sound_mutex);
#ifdef CONFIG_SND_DYNAMIC_MINORS
minor = snd_find_free_minor(type);
#else
minor = snd_kernel_minor(type, card, dev);
if (minor >= 0 && snd_minors[minor])
minor = -EBUSY;
#endif
if (minor < 0) {
mutex_unlock(&sound_mutex);
kfree(preg);
return minor;
}
snd_minors[minor] = preg;
preg->dev = device_create(sound_class, device, MKDEV(major, minor),
private_data, "%s", name);
if (IS_ERR(preg->dev)) {
snd_minors[minor] = NULL;
mutex_unlock(&sound_mutex);
minor = PTR_ERR(preg->dev);
kfree(preg);
return minor;
}
mutex_unlock(&sound_mutex);
return 0;
}
static int find_snd_minor(int type, struct snd_card *card, int dev)
{
int cardnum, minor;
struct snd_minor *mptr;
cardnum = card ? card->number : -1;
for (minor = 0; minor < ARRAY_SIZE(snd_minors); ++minor)
if ((mptr = snd_minors[minor]) != NULL &&
mptr->type == type &&
mptr->card == cardnum &&
mptr->device == dev)
return minor;
return -1;
}
int snd_unregister_device(int type, struct snd_card *card, int dev)
{
int minor;
mutex_lock(&sound_mutex);
minor = find_snd_minor(type, card, dev);
if (minor < 0) {
mutex_unlock(&sound_mutex);
return -EINVAL;
}
device_destroy(sound_class, MKDEV(major, minor));
kfree(snd_minors[minor]);
snd_minors[minor] = NULL;
mutex_unlock(&sound_mutex);
return 0;
}
int snd_add_device_sysfs_file(int type, struct snd_card *card, int dev,
struct device_attribute *attr)
{
int minor, ret = -EINVAL;
struct device *d;
mutex_lock(&sound_mutex);
minor = find_snd_minor(type, card, dev);
if (minor >= 0 && (d = snd_minors[minor]->dev) != NULL)
ret = device_create_file(d, attr);
mutex_unlock(&sound_mutex);
return ret;
}
static const char *snd_device_type_name(int type)
{
switch (type) {
case SNDRV_DEVICE_TYPE_CONTROL:
return "control";
case SNDRV_DEVICE_TYPE_HWDEP:
return "hardware dependent";
case SNDRV_DEVICE_TYPE_RAWMIDI:
return "raw midi";
case SNDRV_DEVICE_TYPE_PCM_PLAYBACK:
return "digital audio playback";
case SNDRV_DEVICE_TYPE_PCM_CAPTURE:
return "digital audio capture";
case SNDRV_DEVICE_TYPE_SEQUENCER:
return "sequencer";
case SNDRV_DEVICE_TYPE_TIMER:
return "timer";
default:
return "?";
}
}
static void snd_minor_info_read(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
int minor;
struct snd_minor *mptr;
mutex_lock(&sound_mutex);
for (minor = 0; minor < SNDRV_OS_MINORS; ++minor) {
if (!(mptr = snd_minors[minor]))
continue;
if (mptr->card >= 0) {
if (mptr->device >= 0)
snd_iprintf(buffer, "%3i: [%2i-%2i]: %s\n",
minor, mptr->card, mptr->device,
snd_device_type_name(mptr->type));
else
snd_iprintf(buffer, "%3i: [%2i] : %s\n",
minor, mptr->card,
snd_device_type_name(mptr->type));
} else
snd_iprintf(buffer, "%3i: : %s\n", minor,
snd_device_type_name(mptr->type));
}
mutex_unlock(&sound_mutex);
}
int __init snd_minor_info_init(void)
{
struct snd_info_entry *entry;
entry = snd_info_create_module_entry(THIS_MODULE, "devices", NULL);
if (entry) {
entry->c.text.read = snd_minor_info_read;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
entry = NULL;
}
}
snd_minor_info_entry = entry;
return 0;
}
int __exit snd_minor_info_done(void)
{
snd_info_free_entry(snd_minor_info_entry);
return 0;
}
static int __init alsa_sound_init(void)
{
snd_major = major;
snd_ecards_limit = cards_limit;
if (register_chrdev(major, "alsa", &snd_fops)) {
snd_printk(KERN_ERR "unable to register native major device number %d\n", major);
return -EIO;
}
if (snd_info_init() < 0) {
unregister_chrdev(major, "alsa");
return -ENOMEM;
}
snd_info_minor_register();
#ifndef MODULE
printk(KERN_INFO "Advanced Linux Sound Architecture Driver Initialized.\n");
#endif
return 0;
}
static void __exit alsa_sound_exit(void)
{
snd_info_minor_unregister();
snd_info_done();
unregister_chrdev(major, "alsa");
}
