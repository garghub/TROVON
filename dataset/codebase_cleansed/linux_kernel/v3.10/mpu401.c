static int snd_mpu401_create(int dev, struct snd_card **rcard)
{
struct snd_card *card;
int err;
if (!uart_enter[dev])
snd_printk(KERN_ERR "the uart_enter option is obsolete; remove it\n");
*rcard = NULL;
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
strcpy(card->driver, "MPU-401 UART");
strcpy(card->shortname, card->driver);
sprintf(card->longname, "%s at %#lx, ", card->shortname, port[dev]);
if (irq[dev] >= 0) {
sprintf(card->longname + strlen(card->longname), "irq %d", irq[dev]);
} else {
strcat(card->longname, "polled");
}
err = snd_mpu401_uart_new(card, 0, MPU401_HW_MPU401, port[dev], 0,
irq[dev], NULL);
if (err < 0) {
printk(KERN_ERR "MPU401 not detected at 0x%lx\n", port[dev]);
goto _err;
}
*rcard = card;
return 0;
_err:
snd_card_free(card);
return err;
}
static int snd_mpu401_probe(struct platform_device *devptr)
{
int dev = devptr->id;
int err;
struct snd_card *card;
if (port[dev] == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR "specify port\n");
return -EINVAL;
}
if (irq[dev] == SNDRV_AUTO_IRQ) {
snd_printk(KERN_ERR "specify or disable IRQ\n");
return -EINVAL;
}
err = snd_mpu401_create(dev, &card);
if (err < 0)
return err;
snd_card_set_dev(card, &devptr->dev);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
platform_set_drvdata(devptr, card);
return 0;
}
static int snd_mpu401_remove(struct platform_device *devptr)
{
snd_card_free(platform_get_drvdata(devptr));
platform_set_drvdata(devptr, NULL);
return 0;
}
static int snd_mpu401_pnp(int dev, struct pnp_dev *device,
const struct pnp_device_id *id)
{
if (!pnp_port_valid(device, 0) ||
pnp_port_flags(device, 0) & IORESOURCE_DISABLED) {
snd_printk(KERN_ERR "no PnP port\n");
return -ENODEV;
}
if (pnp_port_len(device, 0) < IO_EXTENT) {
snd_printk(KERN_ERR "PnP port length is %llu, expected %d\n",
(unsigned long long)pnp_port_len(device, 0),
IO_EXTENT);
return -ENODEV;
}
port[dev] = pnp_port_start(device, 0);
if (!pnp_irq_valid(device, 0) ||
pnp_irq_flags(device, 0) & IORESOURCE_DISABLED) {
snd_printk(KERN_WARNING "no PnP irq, using polling\n");
irq[dev] = -1;
} else {
irq[dev] = pnp_irq(device, 0);
}
return 0;
}
static int snd_mpu401_pnp_probe(struct pnp_dev *pnp_dev,
const struct pnp_device_id *id)
{
static int dev;
struct snd_card *card;
int err;
for ( ; dev < SNDRV_CARDS; ++dev) {
if (!enable[dev] || !pnp[dev])
continue;
err = snd_mpu401_pnp(dev, pnp_dev, id);
if (err < 0)
return err;
err = snd_mpu401_create(dev, &card);
if (err < 0)
return err;
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
snd_card_set_dev(card, &pnp_dev->dev);
pnp_set_drvdata(pnp_dev, card);
snd_mpu401_devices++;
++dev;
return 0;
}
return -ENODEV;
}
static void snd_mpu401_pnp_remove(struct pnp_dev *dev)
{
struct snd_card *card = (struct snd_card *) pnp_get_drvdata(dev);
snd_card_disconnect(card);
snd_card_free_when_closed(card);
}
static void snd_mpu401_unregister_all(void)
{
int i;
if (pnp_registered)
pnp_unregister_driver(&snd_mpu401_pnp_driver);
for (i = 0; i < ARRAY_SIZE(platform_devices); ++i)
platform_device_unregister(platform_devices[i]);
platform_driver_unregister(&snd_mpu401_driver);
}
static int __init alsa_card_mpu401_init(void)
{
int i, err;
if ((err = platform_driver_register(&snd_mpu401_driver)) < 0)
return err;
for (i = 0; i < SNDRV_CARDS; i++) {
struct platform_device *device;
if (! enable[i])
continue;
#ifdef CONFIG_PNP
if (pnp[i])
continue;
#endif
device = platform_device_register_simple(SND_MPU401_DRIVER,
i, NULL, 0);
if (IS_ERR(device))
continue;
if (!platform_get_drvdata(device)) {
platform_device_unregister(device);
continue;
}
platform_devices[i] = device;
snd_mpu401_devices++;
}
err = pnp_register_driver(&snd_mpu401_pnp_driver);
if (!err)
pnp_registered = 1;
if (!snd_mpu401_devices) {
#ifdef MODULE
printk(KERN_ERR "MPU-401 device not found or device busy\n");
#endif
snd_mpu401_unregister_all();
return -ENODEV;
}
return 0;
}
static void __exit alsa_card_mpu401_exit(void)
{
snd_mpu401_unregister_all();
}
