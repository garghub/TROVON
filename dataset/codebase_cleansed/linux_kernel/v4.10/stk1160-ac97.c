static void stk1160_write_ac97(struct snd_ac97 *ac97, u16 reg, u16 value)
{
struct stk1160 *dev = ac97->private_data;
stk1160_write_reg(dev, STK1160_AC97_ADDR, reg);
stk1160_write_reg(dev, STK1160_AC97_CMD, value & 0xff);
stk1160_write_reg(dev, STK1160_AC97_CMD + 1, (value & 0xff00) >> 8);
stk1160_write_reg(dev, STK1160_AC97CTL_0, 0x8c);
}
static u16 stk1160_read_ac97(struct snd_ac97 *ac97, u16 reg)
{
struct stk1160 *dev = ac97->private_data;
u8 vall = 0;
u8 valh = 0;
stk1160_write_reg(dev, STK1160_AC97_ADDR, reg);
stk1160_write_reg(dev, STK1160_AC97CTL_0, 0x8b);
stk1160_read_reg(dev, STK1160_AC97_CMD, &vall);
stk1160_read_reg(dev, STK1160_AC97_CMD + 1, &valh);
return (valh << 8) | vall;
}
static void stk1160_reset_ac97(struct snd_ac97 *ac97)
{
struct stk1160 *dev = ac97->private_data;
stk1160_write_reg(dev, STK1160_AC97CTL_0, 0x94);
stk1160_write_reg(dev, STK1160_AC97CTL_0, 0x88);
stk1160_write_reg(dev, STK1160_AC97CTL_1 + 2, 0x01);
}
int stk1160_ac97_register(struct stk1160 *dev)
{
struct snd_card *card = NULL;
struct snd_ac97_bus *ac97_bus;
struct snd_ac97_template ac97_template;
int rc;
rc = snd_card_new(dev->dev, SNDRV_DEFAULT_IDX1, SNDRV_DEFAULT_STR1,
THIS_MODULE, 0, &card);
if (rc < 0)
return rc;
snprintf(card->shortname, sizeof(card->shortname),
"stk1160-mixer");
snprintf(card->longname, sizeof(card->longname),
"stk1160 ac97 codec mixer control");
strlcpy(card->driver, dev->dev->driver->name, sizeof(card->driver));
rc = snd_ac97_bus(card, 0, &stk1160_ac97_ops, NULL, &ac97_bus);
if (rc)
goto err;
memset(&ac97_template, 0, sizeof(ac97_template));
ac97_template.private_data = dev;
ac97_template.scaps = AC97_SCAP_SKIP_MODEM;
rc = snd_ac97_mixer(ac97_bus, &ac97_template, &stk1160_ac97);
if (rc)
goto err;
dev->snd_card = card;
rc = snd_card_register(card);
if (rc)
goto err;
return 0;
err:
dev->snd_card = NULL;
snd_card_free(card);
return rc;
}
int stk1160_ac97_unregister(struct stk1160 *dev)
{
struct snd_card *card = dev->snd_card;
if (card && dev->udev)
snd_card_free(card);
return 0;
}
