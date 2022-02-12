static bool snd_ac97_check_id(struct snd_ac97 *ac97, unsigned int id,
unsigned int id_mask)
{
ac97->id = ac97->bus->ops->read(ac97, AC97_VENDOR_ID1) << 16;
ac97->id |= ac97->bus->ops->read(ac97, AC97_VENDOR_ID2);
if (ac97->id == 0x0 || ac97->id == 0xffffffff)
return false;
if (id != 0 && id != (ac97->id & id_mask))
return false;
return true;
}
int snd_ac97_reset(struct snd_ac97 *ac97, bool try_warm, unsigned int id,
unsigned int id_mask)
{
struct snd_ac97_bus_ops *ops = ac97->bus->ops;
if (try_warm && ops->warm_reset) {
ops->warm_reset(ac97);
if (snd_ac97_check_id(ac97, id, id_mask))
return 1;
}
if (ops->reset)
ops->reset(ac97);
if (ops->warm_reset)
ops->warm_reset(ac97);
if (snd_ac97_check_id(ac97, id, id_mask))
return 0;
return -ENODEV;
}
static int ac97_bus_match(struct device *dev, struct device_driver *drv)
{
return 1;
}
static int __init ac97_bus_init(void)
{
return bus_register(&ac97_bus_type);
}
static void __exit ac97_bus_exit(void)
{
bus_unregister(&ac97_bus_type);
}
