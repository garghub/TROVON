bool regmap_ac97_default_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case AC97_RESET:
case AC97_POWERDOWN:
case AC97_INT_PAGING:
case AC97_EXTENDED_ID:
case AC97_EXTENDED_STATUS:
case AC97_EXTENDED_MID:
case AC97_EXTENDED_MSTATUS:
case AC97_GPIO_STATUS:
case AC97_MISC_AFE:
case AC97_VENDOR_ID1:
case AC97_VENDOR_ID2:
case AC97_CODEC_CLASS_REV:
case AC97_PCI_SVID:
case AC97_PCI_SID:
case AC97_FUNC_SELECT:
case AC97_FUNC_INFO:
case AC97_SENSE_INFO:
return true;
default:
return false;
}
}
static int regmap_ac97_reg_read(void *context, unsigned int reg,
unsigned int *val)
{
struct snd_ac97 *ac97 = context;
*val = ac97->bus->ops->read(ac97, reg);
return 0;
}
static int regmap_ac97_reg_write(void *context, unsigned int reg,
unsigned int val)
{
struct snd_ac97 *ac97 = context;
ac97->bus->ops->write(ac97, reg, val);
return 0;
}
struct regmap *regmap_init_ac97(struct snd_ac97 *ac97,
const struct regmap_config *config)
{
return regmap_init(&ac97->dev, &ac97_regmap_bus, ac97, config);
}
struct regmap *devm_regmap_init_ac97(struct snd_ac97 *ac97,
const struct regmap_config *config)
{
return devm_regmap_init(&ac97->dev, &ac97_regmap_bus, ac97, config);
}
