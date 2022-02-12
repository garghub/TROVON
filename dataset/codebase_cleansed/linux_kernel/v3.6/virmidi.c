static int __devinit snd_virmidi_probe(struct platform_device *devptr)
{
struct snd_card *card;
struct snd_card_virmidi *vmidi;
int idx, err;
int dev = devptr->id;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct snd_card_virmidi), &card);
if (err < 0)
return err;
vmidi = card->private_data;
vmidi->card = card;
if (midi_devs[dev] > MAX_MIDI_DEVICES) {
snd_printk(KERN_WARNING
"too much midi devices for virmidi %d: "
"force to use %d\n", dev, MAX_MIDI_DEVICES);
midi_devs[dev] = MAX_MIDI_DEVICES;
}
for (idx = 0; idx < midi_devs[dev]; idx++) {
struct snd_rawmidi *rmidi;
struct snd_virmidi_dev *rdev;
if ((err = snd_virmidi_new(card, idx, &rmidi)) < 0)
goto __nodev;
rdev = rmidi->private_data;
vmidi->midi[idx] = rmidi;
strcpy(rmidi->name, "Virtual Raw MIDI");
rdev->seq_mode = SNDRV_VIRMIDI_SEQ_DISPATCH;
}
strcpy(card->driver, "VirMIDI");
strcpy(card->shortname, "VirMIDI");
sprintf(card->longname, "Virtual MIDI Card %i", dev + 1);
snd_card_set_dev(card, &devptr->dev);
if ((err = snd_card_register(card)) == 0) {
platform_set_drvdata(devptr, card);
return 0;
}
__nodev:
snd_card_free(card);
return err;
}
static int __devexit snd_virmidi_remove(struct platform_device *devptr)
{
snd_card_free(platform_get_drvdata(devptr));
platform_set_drvdata(devptr, NULL);
return 0;
}
static void snd_virmidi_unregister_all(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(devices); ++i)
platform_device_unregister(devices[i]);
platform_driver_unregister(&snd_virmidi_driver);
}
static int __init alsa_card_virmidi_init(void)
{
int i, cards, err;
if ((err = platform_driver_register(&snd_virmidi_driver)) < 0)
return err;
cards = 0;
for (i = 0; i < SNDRV_CARDS; i++) {
struct platform_device *device;
if (! enable[i])
continue;
device = platform_device_register_simple(SND_VIRMIDI_DRIVER,
i, NULL, 0);
if (IS_ERR(device))
continue;
if (!platform_get_drvdata(device)) {
platform_device_unregister(device);
continue;
}
devices[i] = device;
cards++;
}
if (!cards) {
#ifdef MODULE
printk(KERN_ERR "Card-VirMIDI soundcard not found or device busy\n");
#endif
snd_virmidi_unregister_all();
return -ENODEV;
}
return 0;
}
static void __exit alsa_card_virmidi_exit(void)
{
snd_virmidi_unregister_all();
}
