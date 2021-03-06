static void snd_devm_unregister_child(struct device *dev, void *res)
{
struct device *childdev = *(struct device **)res;
device_unregister(childdev);
}
static int snd_devm_add_child(struct device *dev, struct device *child)
{
struct device **dr;
int ret;
dr = devres_alloc(snd_devm_unregister_child, sizeof(*dr), GFP_KERNEL);
if (!dr)
return -ENOMEM;
ret = device_add(child);
if (ret) {
devres_free(dr);
return ret;
}
*dr = child;
devres_add(dev, dr);
return 0;
}
static struct device *
snd_create_device(struct device *parent,
struct device_driver *driver,
const char *name)
{
struct device *device;
int ret;
device = devm_kzalloc(parent, sizeof(*device), GFP_KERNEL);
if (!device)
return ERR_PTR(-ENOMEM);
device_initialize(device);
device->parent = parent;
device->driver = driver;
dev_set_name(device, "%s", name);
ret = snd_devm_add_child(parent, device);
if (ret)
return ERR_PTR(ret);
return device;
}
static int snd_bcm2835_free(struct bcm2835_chip *chip)
{
kfree(chip);
return 0;
}
static int snd_bcm2835_dev_free(struct snd_device *device)
{
return snd_bcm2835_free(device->device_data);
}
static int snd_bcm2835_create(struct snd_card *card,
struct bcm2835_chip **rchip)
{
struct bcm2835_chip *chip;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_bcm2835_dev_free,
};
*rchip = NULL;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->card = card;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err) {
snd_bcm2835_free(chip);
return err;
}
*rchip = chip;
return 0;
}
static void snd_devm_card_free(struct device *dev, void *res)
{
struct snd_card *snd_card = *(struct snd_card **)res;
snd_card_free(snd_card);
}
static struct snd_card *snd_devm_card_new(struct device *dev)
{
struct snd_card **dr;
struct snd_card *card;
int ret;
dr = devres_alloc(snd_devm_card_free, sizeof(*dr), GFP_KERNEL);
if (!dr)
return ERR_PTR(-ENOMEM);
ret = snd_card_new(dev, -1, NULL, THIS_MODULE, 0, &card);
if (ret) {
devres_free(dr);
return ERR_PTR(ret);
}
*dr = card;
devres_add(dev, dr);
return card;
}
static int bcm2835_audio_alsa_newpcm(struct bcm2835_chip *chip,
const char *name,
enum snd_bcm2835_route route,
u32 numchannels)
{
int err;
err = snd_bcm2835_new_pcm(chip, numchannels - 1);
if (err)
return err;
err = snd_bcm2835_new_spdif_pcm(chip);
if (err)
return err;
return 0;
}
static int snd_add_child_device(struct device *device,
struct bcm2835_audio_driver *audio_driver,
u32 numchans)
{
struct snd_card *card;
struct device *child;
struct bcm2835_chip *chip;
int err, i;
child = snd_create_device(device, &audio_driver->driver,
audio_driver->driver.name);
if (IS_ERR(child)) {
dev_err(device,
"Unable to create child device %p, error %ld",
audio_driver->driver.name,
PTR_ERR(child));
return PTR_ERR(child);
}
card = snd_devm_card_new(child);
if (IS_ERR(card)) {
dev_err(child, "Failed to create card");
return PTR_ERR(card);
}
snd_card_set_dev(card, child);
strcpy(card->driver, audio_driver->driver.name);
strcpy(card->shortname, audio_driver->shortname);
strcpy(card->longname, audio_driver->longname);
err = snd_bcm2835_create(card, &chip);
if (err) {
dev_err(child, "Failed to create chip, error %d\n", err);
return err;
}
chip->dev = child;
err = audio_driver->newpcm(chip, audio_driver->shortname,
audio_driver->route,
numchans);
if (err) {
dev_err(child, "Failed to create pcm, error %d\n", err);
return err;
}
err = audio_driver->newctl(chip);
if (err) {
dev_err(child, "Failed to create controls, error %d\n", err);
return err;
}
for (i = 0; i < numchans; i++)
chip->avail_substreams |= (1 << i);
err = snd_card_register(card);
if (err) {
dev_err(child, "Failed to register card, error %d\n", err);
return err;
}
dev_set_drvdata(child, card);
dev_info(child, "card created with %d channels\n", numchans);
return 0;
}
static int snd_add_child_devices(struct device *device, u32 numchans)
{
int i;
int count_devices = 0;
int minchannels = 0;
int extrachannels = 0;
int extrachannels_per_driver = 0;
int extrachannels_remainder = 0;
for (i = 0; i < ARRAY_SIZE(children_devices); i++)
if (*children_devices[i].is_enabled)
count_devices++;
if (!count_devices)
return 0;
for (i = 0; i < ARRAY_SIZE(children_devices); i++)
if (*children_devices[i].is_enabled)
minchannels +=
children_devices[i].audio_driver->minchannels;
if (minchannels < numchans) {
extrachannels = numchans - minchannels;
extrachannels_per_driver = extrachannels / count_devices;
extrachannels_remainder = extrachannels % count_devices;
}
dev_dbg(device, "minchannels %d\n", minchannels);
dev_dbg(device, "extrachannels %d\n", extrachannels);
dev_dbg(device, "extrachannels_per_driver %d\n",
extrachannels_per_driver);
dev_dbg(device, "extrachannels_remainder %d\n",
extrachannels_remainder);
for (i = 0; i < ARRAY_SIZE(children_devices); i++) {
int err;
int numchannels_this_device;
struct bcm2835_audio_driver *audio_driver;
if (!*children_devices[i].is_enabled)
continue;
audio_driver = children_devices[i].audio_driver;
if (audio_driver->minchannels > numchans) {
dev_err(device,
"Out of channels, needed %d but only %d left\n",
audio_driver->minchannels,
numchans);
continue;
}
numchannels_this_device =
audio_driver->minchannels + extrachannels_per_driver +
extrachannels_remainder;
extrachannels_remainder = 0;
numchans -= numchannels_this_device;
err = snd_add_child_device(device, audio_driver,
numchannels_this_device);
if (err)
return err;
}
return 0;
}
static int snd_bcm2835_alsa_probe_dt(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
u32 numchans;
int err;
err = of_property_read_u32(dev->of_node, "brcm,pwm-channels",
&numchans);
if (err) {
dev_err(dev, "Failed to get DT property 'brcm,pwm-channels'");
return err;
}
if (numchans == 0 || numchans > MAX_SUBSTREAMS) {
numchans = MAX_SUBSTREAMS;
dev_warn(dev,
"Illegal 'brcm,pwm-channels' value, will use %u\n",
numchans);
}
err = snd_add_child_devices(dev, numchans);
if (err)
return err;
return 0;
}
static int snd_bcm2835_alsa_suspend(struct platform_device *pdev,
pm_message_t state)
{
return 0;
}
static int snd_bcm2835_alsa_resume(struct platform_device *pdev)
{
return 0;
}
static int bcm2835_alsa_device_init(void)
{
int retval;
retval = platform_driver_register(&bcm2835_alsa0_driver);
if (retval)
pr_err("Error registering bcm2835_audio driver %d .\n", retval);
return retval;
}
static void bcm2835_alsa_device_exit(void)
{
platform_driver_unregister(&bcm2835_alsa0_driver);
}
