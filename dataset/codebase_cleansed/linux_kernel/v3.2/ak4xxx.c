static void snd_ice1712_akm4xxx_lock(struct snd_akm4xxx *ak, int chip)
{
struct snd_ice1712 *ice = ak->private_data[0];
snd_ice1712_save_gpio_status(ice);
}
static void snd_ice1712_akm4xxx_unlock(struct snd_akm4xxx *ak, int chip)
{
struct snd_ice1712 *ice = ak->private_data[0];
snd_ice1712_restore_gpio_status(ice);
}
static void snd_ice1712_akm4xxx_write(struct snd_akm4xxx *ak, int chip,
unsigned char addr, unsigned char data)
{
unsigned int tmp;
int idx;
unsigned int addrdata;
struct snd_ak4xxx_private *priv = (void *)ak->private_value[0];
struct snd_ice1712 *ice = ak->private_data[0];
if (snd_BUG_ON(chip < 0 || chip >= 4))
return;
tmp = snd_ice1712_gpio_read(ice);
tmp |= priv->add_flags;
tmp &= ~priv->mask_flags;
if (priv->cs_mask == priv->cs_addr) {
if (priv->cif) {
tmp |= priv->cs_mask;
} else {
tmp &= ~priv->cs_mask;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
} else {
tmp &= ~priv->cs_mask;
tmp |= priv->cs_addr;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
addrdata = (priv->caddr << 6) | 0x20 | (addr & 0x1f);
addrdata = (addrdata << 8) | data;
for (idx = 15; idx >= 0; idx--) {
tmp &= ~priv->clk_mask;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
if (addrdata & (1 << idx))
tmp |= priv->data_mask;
else
tmp &= ~priv->data_mask;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= priv->clk_mask;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
if (priv->cs_mask == priv->cs_addr) {
if (priv->cif) {
tmp &= ~priv->cs_mask;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
tmp |= priv->cs_mask;
} else {
tmp &= ~priv->cs_mask;
tmp |= priv->cs_none;
}
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
int snd_ice1712_akm4xxx_init(struct snd_akm4xxx *ak, const struct snd_akm4xxx *temp,
const struct snd_ak4xxx_private *_priv, struct snd_ice1712 *ice)
{
struct snd_ak4xxx_private *priv;
if (_priv != NULL) {
priv = kmalloc(sizeof(*priv), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
*priv = *_priv;
} else {
priv = NULL;
}
*ak = *temp;
ak->card = ice->card;
ak->private_value[0] = (unsigned long)priv;
ak->private_data[0] = ice;
if (ak->ops.lock == NULL)
ak->ops.lock = snd_ice1712_akm4xxx_lock;
if (ak->ops.unlock == NULL)
ak->ops.unlock = snd_ice1712_akm4xxx_unlock;
if (ak->ops.write == NULL)
ak->ops.write = snd_ice1712_akm4xxx_write;
snd_akm4xxx_init(ak);
return 0;
}
void snd_ice1712_akm4xxx_free(struct snd_ice1712 *ice)
{
unsigned int akidx;
if (ice->akm == NULL)
return;
for (akidx = 0; akidx < ice->akm_codecs; akidx++) {
struct snd_akm4xxx *ak = &ice->akm[akidx];
kfree((void*)ak->private_value[0]);
}
kfree(ice->akm);
}
int snd_ice1712_akm4xxx_build_controls(struct snd_ice1712 *ice)
{
unsigned int akidx;
int err;
for (akidx = 0; akidx < ice->akm_codecs; akidx++) {
struct snd_akm4xxx *ak = &ice->akm[akidx];
err = snd_akm4xxx_build_controls(ak);
if (err < 0)
return err;
}
return 0;
}
static int __init alsa_ice1712_akm4xxx_module_init(void)
{
return 0;
}
static void __exit alsa_ice1712_akm4xxx_module_exit(void)
{
}
