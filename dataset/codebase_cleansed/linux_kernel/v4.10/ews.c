static void ewx_i2c_setlines(struct snd_i2c_bus *bus, int clk, int data)
{
struct snd_ice1712 *ice = bus->private_data;
unsigned char tmp = 0;
if (clk)
tmp |= ICE1712_EWX2496_SERIAL_CLOCK;
if (data)
tmp |= ICE1712_EWX2496_SERIAL_DATA;
snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
udelay(5);
}
static int ewx_i2c_getclock(struct snd_i2c_bus *bus)
{
struct snd_ice1712 *ice = bus->private_data;
return snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA) & ICE1712_EWX2496_SERIAL_CLOCK ? 1 : 0;
}
static int ewx_i2c_getdata(struct snd_i2c_bus *bus, int ack)
{
struct snd_ice1712 *ice = bus->private_data;
int bit;
snd_ice1712_write(ice, ICE1712_IREG_GPIO_WRITE_MASK, ~ICE1712_EWX2496_RW);
snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, 0);
if (ack)
udelay(5);
bit = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA) & ICE1712_EWX2496_SERIAL_DATA ? 1 : 0;
snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, ICE1712_EWX2496_RW);
snd_ice1712_write(ice, ICE1712_IREG_GPIO_WRITE_MASK, ~ICE1712_EWX2496_SERIAL_CLOCK);
return bit;
}
static void ewx_i2c_start(struct snd_i2c_bus *bus)
{
struct snd_ice1712 *ice = bus->private_data;
unsigned char mask;
snd_ice1712_save_gpio_status(ice);
mask = ICE1712_EWX2496_RW;
switch (ice->eeprom.subvendor) {
case ICE1712_SUBDEVICE_EWX2496:
mask |= ICE1712_EWX2496_AK4524_CS;
break;
case ICE1712_SUBDEVICE_DMX6FIRE:
mask |= ICE1712_6FIRE_AK4524_CS_MASK;
break;
}
snd_ice1712_gpio_write_bits(ice, mask, mask);
}
static void ewx_i2c_stop(struct snd_i2c_bus *bus)
{
struct snd_ice1712 *ice = bus->private_data;
snd_ice1712_restore_gpio_status(ice);
}
static void ewx_i2c_direction(struct snd_i2c_bus *bus, int clock, int data)
{
struct snd_ice1712 *ice = bus->private_data;
unsigned char mask = 0;
if (clock)
mask |= ICE1712_EWX2496_SERIAL_CLOCK;
if (data)
mask |= ICE1712_EWX2496_SERIAL_DATA;
ice->gpio.direction &= ~(ICE1712_EWX2496_SERIAL_CLOCK|ICE1712_EWX2496_SERIAL_DATA);
ice->gpio.direction |= mask;
snd_ice1712_write(ice, ICE1712_IREG_GPIO_DIRECTION, ice->gpio.direction);
snd_ice1712_write(ice, ICE1712_IREG_GPIO_WRITE_MASK, ~mask);
}
static int snd_ice1712_ews88mt_chip_select(struct snd_ice1712 *ice, int chip_mask)
{
struct ews_spec *spec = ice->spec;
unsigned char data, ndata;
if (snd_BUG_ON(chip_mask < 0 || chip_mask > 0x0f))
return -EINVAL;
snd_i2c_lock(ice->i2c);
if (snd_i2c_readbytes(spec->i2cdevs[EWS_I2C_PCF2], &data, 1) != 1)
goto __error;
ndata = (data & 0xf0) | chip_mask;
if (ndata != data)
if (snd_i2c_sendbytes(spec->i2cdevs[EWS_I2C_PCF2], &ndata, 1)
!= 1)
goto __error;
snd_i2c_unlock(ice->i2c);
return 0;
__error:
snd_i2c_unlock(ice->i2c);
dev_err(ice->card->dev,
"AK4524 chip select failed, check cable to the front module\n");
return -EIO;
}
static void ews88mt_ak4524_lock(struct snd_akm4xxx *ak, int chip)
{
struct snd_ice1712 *ice = ak->private_data[0];
unsigned char tmp;
if (snd_ice1712_ews88mt_chip_select(ice, ~(1 << chip) & 0x0f) < 0)
dev_err(ice->card->dev, "fatal error (ews88mt chip select)\n");
snd_ice1712_save_gpio_status(ice);
tmp = ICE1712_EWS88_SERIAL_DATA |
ICE1712_EWS88_SERIAL_CLOCK |
ICE1712_EWS88_RW;
snd_ice1712_write(ice, ICE1712_IREG_GPIO_DIRECTION,
ice->gpio.direction | tmp);
snd_ice1712_write(ice, ICE1712_IREG_GPIO_WRITE_MASK, ~tmp);
}
static void ews88mt_ak4524_unlock(struct snd_akm4xxx *ak, int chip)
{
struct snd_ice1712 *ice = ak->private_data[0];
snd_ice1712_restore_gpio_status(ice);
udelay(1);
snd_ice1712_ews88mt_chip_select(ice, 0x0f);
}
static void ewx2496_ak4524_lock(struct snd_akm4xxx *ak, int chip)
{
struct snd_ice1712 *ice = ak->private_data[0];
unsigned char tmp;
snd_ice1712_save_gpio_status(ice);
tmp = ICE1712_EWX2496_SERIAL_DATA |
ICE1712_EWX2496_SERIAL_CLOCK |
ICE1712_EWX2496_AK4524_CS |
ICE1712_EWX2496_RW;
snd_ice1712_write(ice, ICE1712_IREG_GPIO_DIRECTION,
ice->gpio.direction | tmp);
snd_ice1712_write(ice, ICE1712_IREG_GPIO_WRITE_MASK, ~tmp);
}
static void dmx6fire_ak4524_lock(struct snd_akm4xxx *ak, int chip)
{
struct snd_ak4xxx_private *priv = (void *)ak->private_value[0];
struct snd_ice1712 *ice = ak->private_data[0];
unsigned char tmp;
snd_ice1712_save_gpio_status(ice);
tmp = priv->cs_mask = priv->cs_addr = (1 << chip) & ICE1712_6FIRE_AK4524_CS_MASK;
tmp |= ICE1712_6FIRE_SERIAL_DATA |
ICE1712_6FIRE_SERIAL_CLOCK |
ICE1712_6FIRE_RW;
snd_ice1712_write(ice, ICE1712_IREG_GPIO_DIRECTION,
ice->gpio.direction | tmp);
snd_ice1712_write(ice, ICE1712_IREG_GPIO_WRITE_MASK, ~tmp);
}
static void snd_ice1712_ews_cs8404_spdif_write(struct snd_ice1712 *ice, unsigned char bits)
{
struct ews_spec *spec = ice->spec;
unsigned char bytes[2];
snd_i2c_lock(ice->i2c);
switch (ice->eeprom.subvendor) {
case ICE1712_SUBDEVICE_EWS88MT:
case ICE1712_SUBDEVICE_EWS88MT_NEW:
case ICE1712_SUBDEVICE_PHASE88:
case ICE1712_SUBDEVICE_TS88:
if (snd_i2c_sendbytes(spec->i2cdevs[EWS_I2C_CS8404], &bits, 1)
!= 1)
goto _error;
break;
case ICE1712_SUBDEVICE_EWS88D:
if (snd_i2c_readbytes(spec->i2cdevs[EWS_I2C_88D], bytes, 2)
!= 2)
goto _error;
if (bits != bytes[1]) {
bytes[1] = bits;
if (snd_i2c_sendbytes(spec->i2cdevs[EWS_I2C_88D],
bytes, 2) != 2)
goto _error;
}
break;
}
_error:
snd_i2c_unlock(ice->i2c);
}
static void ews88_spdif_default_get(struct snd_ice1712 *ice, struct snd_ctl_elem_value *ucontrol)
{
snd_cs8404_decode_spdif_bits(&ucontrol->value.iec958, ice->spdif.cs8403_bits);
}
static int ews88_spdif_default_put(struct snd_ice1712 *ice, struct snd_ctl_elem_value *ucontrol)
{
unsigned int val;
int change;
val = snd_cs8404_encode_spdif_bits(&ucontrol->value.iec958);
spin_lock_irq(&ice->reg_lock);
change = ice->spdif.cs8403_bits != val;
ice->spdif.cs8403_bits = val;
if (change && ice->playback_pro_substream == NULL) {
spin_unlock_irq(&ice->reg_lock);
snd_ice1712_ews_cs8404_spdif_write(ice, val);
} else {
spin_unlock_irq(&ice->reg_lock);
}
return change;
}
static void ews88_spdif_stream_get(struct snd_ice1712 *ice, struct snd_ctl_elem_value *ucontrol)
{
snd_cs8404_decode_spdif_bits(&ucontrol->value.iec958, ice->spdif.cs8403_stream_bits);
}
static int ews88_spdif_stream_put(struct snd_ice1712 *ice, struct snd_ctl_elem_value *ucontrol)
{
unsigned int val;
int change;
val = snd_cs8404_encode_spdif_bits(&ucontrol->value.iec958);
spin_lock_irq(&ice->reg_lock);
change = ice->spdif.cs8403_stream_bits != val;
ice->spdif.cs8403_stream_bits = val;
if (change && ice->playback_pro_substream != NULL) {
spin_unlock_irq(&ice->reg_lock);
snd_ice1712_ews_cs8404_spdif_write(ice, val);
} else {
spin_unlock_irq(&ice->reg_lock);
}
return change;
}
static void ews88_open_spdif(struct snd_ice1712 *ice, struct snd_pcm_substream *substream)
{
ice->spdif.cs8403_stream_bits = ice->spdif.cs8403_bits;
}
static void ews88_setup_spdif(struct snd_ice1712 *ice, int rate)
{
unsigned long flags;
unsigned char tmp;
int change;
spin_lock_irqsave(&ice->reg_lock, flags);
tmp = ice->spdif.cs8403_stream_bits;
if (tmp & 0x10)
tmp &= (tmp & 0x01) ? ~0x06 : ~0x60;
switch (rate) {
case 32000: tmp |= (tmp & 0x01) ? 0x02 : 0x00; break;
case 44100: tmp |= (tmp & 0x01) ? 0x06 : 0x40; break;
case 48000: tmp |= (tmp & 0x01) ? 0x04 : 0x20; break;
default: tmp |= (tmp & 0x01) ? 0x06 : 0x40; break;
}
change = ice->spdif.cs8403_stream_bits != tmp;
ice->spdif.cs8403_stream_bits = tmp;
spin_unlock_irqrestore(&ice->reg_lock, flags);
if (change)
snd_ctl_notify(ice->card, SNDRV_CTL_EVENT_MASK_VALUE, &ice->spdif.stream_ctl->id);
snd_ice1712_ews_cs8404_spdif_write(ice, tmp);
}
static int snd_ice1712_ews_init(struct snd_ice1712 *ice)
{
int err;
struct snd_akm4xxx *ak;
struct ews_spec *spec;
switch (ice->eeprom.subvendor) {
case ICE1712_SUBDEVICE_EWX2496:
ice->num_total_dacs = 2;
ice->num_total_adcs = 2;
break;
case ICE1712_SUBDEVICE_EWS88MT:
case ICE1712_SUBDEVICE_EWS88MT_NEW:
case ICE1712_SUBDEVICE_PHASE88:
case ICE1712_SUBDEVICE_TS88:
ice->num_total_dacs = 8;
ice->num_total_adcs = 8;
break;
case ICE1712_SUBDEVICE_EWS88D:
ice->num_total_dacs = 8;
ice->num_total_adcs = 8;
break;
case ICE1712_SUBDEVICE_DMX6FIRE:
ice->num_total_dacs = 6;
ice->num_total_adcs = 6;
break;
}
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
ice->spec = spec;
if ((err = snd_i2c_bus_create(ice->card, "ICE1712 GPIO 1", NULL, &ice->i2c)) < 0) {
dev_err(ice->card->dev, "unable to create I2C bus\n");
return err;
}
ice->i2c->private_data = ice;
ice->i2c->hw_ops.bit = &snd_ice1712_ewx_cs8427_bit_ops;
switch (ice->eeprom.subvendor) {
case ICE1712_SUBDEVICE_DMX6FIRE:
err = snd_i2c_device_create(ice->i2c, "PCF9554",
ICE1712_6FIRE_PCF9554_ADDR,
&spec->i2cdevs[EWS_I2C_6FIRE]);
if (err < 0) {
dev_err(ice->card->dev,
"PCF9554 initialization failed\n");
return err;
}
snd_ice1712_6fire_write_pca(ice, PCF9554_REG_CONFIG, 0x80);
break;
case ICE1712_SUBDEVICE_EWS88MT:
case ICE1712_SUBDEVICE_EWS88MT_NEW:
case ICE1712_SUBDEVICE_PHASE88:
case ICE1712_SUBDEVICE_TS88:
err = snd_i2c_device_create(ice->i2c, "CS8404",
ICE1712_EWS88MT_CS8404_ADDR,
&spec->i2cdevs[EWS_I2C_CS8404]);
if (err < 0)
return err;
err = snd_i2c_device_create(ice->i2c, "PCF8574 (1st)",
ICE1712_EWS88MT_INPUT_ADDR,
&spec->i2cdevs[EWS_I2C_PCF1]);
if (err < 0)
return err;
err = snd_i2c_device_create(ice->i2c, "PCF8574 (2nd)",
ICE1712_EWS88MT_OUTPUT_ADDR,
&spec->i2cdevs[EWS_I2C_PCF2]);
if (err < 0)
return err;
if ((err = snd_ice1712_ews88mt_chip_select(ice, 0x0f)) < 0)
return err;
break;
case ICE1712_SUBDEVICE_EWS88D:
err = snd_i2c_device_create(ice->i2c, "PCF8575",
ICE1712_EWS88D_PCF_ADDR,
&spec->i2cdevs[EWS_I2C_88D]);
if (err < 0)
return err;
break;
}
switch (ice->eeprom.subvendor) {
case ICE1712_SUBDEVICE_EWX2496:
if ((err = snd_ice1712_init_cs8427(ice, CS8427_BASE_ADDR)) < 0)
return err;
snd_cs8427_reg_write(ice->cs8427, CS8427_REG_RECVERRMASK, CS8427_UNLOCK | CS8427_CONF | CS8427_BIP | CS8427_PAR);
break;
case ICE1712_SUBDEVICE_DMX6FIRE:
if ((err = snd_ice1712_init_cs8427(ice, ICE1712_6FIRE_CS8427_ADDR)) < 0)
return err;
snd_cs8427_reg_write(ice->cs8427, CS8427_REG_RECVERRMASK, CS8427_UNLOCK | CS8427_CONF | CS8427_BIP | CS8427_PAR);
break;
case ICE1712_SUBDEVICE_EWS88MT:
case ICE1712_SUBDEVICE_EWS88MT_NEW:
case ICE1712_SUBDEVICE_PHASE88:
case ICE1712_SUBDEVICE_TS88:
case ICE1712_SUBDEVICE_EWS88D:
ice->spdif.ops.open = ews88_open_spdif;
ice->spdif.ops.setup_rate = ews88_setup_spdif;
ice->spdif.ops.default_get = ews88_spdif_default_get;
ice->spdif.ops.default_put = ews88_spdif_default_put;
ice->spdif.ops.stream_get = ews88_spdif_stream_get;
ice->spdif.ops.stream_put = ews88_spdif_stream_put;
snd_ice1712_ews_cs8404_spdif_write(ice, ice->spdif.cs8403_bits);
break;
}
switch (ice->eeprom.subvendor) {
case ICE1712_SUBDEVICE_EWS88D:
return 0;
}
ak = ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
if (! ak)
return -ENOMEM;
ice->akm_codecs = 1;
switch (ice->eeprom.subvendor) {
case ICE1712_SUBDEVICE_EWS88MT:
case ICE1712_SUBDEVICE_EWS88MT_NEW:
case ICE1712_SUBDEVICE_PHASE88:
case ICE1712_SUBDEVICE_TS88:
err = snd_ice1712_akm4xxx_init(ak, &akm_ews88mt, &akm_ews88mt_priv, ice);
break;
case ICE1712_SUBDEVICE_EWX2496:
err = snd_ice1712_akm4xxx_init(ak, &akm_ewx2496, &akm_ewx2496_priv, ice);
break;
case ICE1712_SUBDEVICE_DMX6FIRE:
err = snd_ice1712_akm4xxx_init(ak, &akm_6fire, &akm_6fire_priv, ice);
break;
default:
err = 0;
}
return err;
}
static int snd_ice1712_ewx_io_sense_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo){
static const char * const texts[2] = {
"+4dBu", "-10dBV",
};
return snd_ctl_enum_info(uinfo, 1, 2, texts);
}
static int snd_ice1712_ewx_io_sense_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char mask = kcontrol->private_value & 0xff;
snd_ice1712_save_gpio_status(ice);
ucontrol->value.enumerated.item[0] = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA) & mask ? 1 : 0;
snd_ice1712_restore_gpio_status(ice);
return 0;
}
static int snd_ice1712_ewx_io_sense_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char mask = kcontrol->private_value & 0xff;
int val, nval;
if (kcontrol->private_value & (1 << 31))
return -EPERM;
nval = ucontrol->value.enumerated.item[0] ? mask : 0;
snd_ice1712_save_gpio_status(ice);
val = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA);
nval |= val & ~mask;
snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, nval);
snd_ice1712_restore_gpio_status(ice);
return val != nval;
}
static int snd_ice1712_ews88mt_output_sense_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct ews_spec *spec = ice->spec;
unsigned char data;
snd_i2c_lock(ice->i2c);
if (snd_i2c_readbytes(spec->i2cdevs[EWS_I2C_PCF2], &data, 1) != 1) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
snd_i2c_unlock(ice->i2c);
ucontrol->value.enumerated.item[0] = data & ICE1712_EWS88MT_OUTPUT_SENSE ? 1 : 0;
return 0;
}
static int snd_ice1712_ews88mt_output_sense_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct ews_spec *spec = ice->spec;
unsigned char data, ndata;
snd_i2c_lock(ice->i2c);
if (snd_i2c_readbytes(spec->i2cdevs[EWS_I2C_PCF2], &data, 1) != 1) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
ndata = (data & ~ICE1712_EWS88MT_OUTPUT_SENSE) | (ucontrol->value.enumerated.item[0] ? ICE1712_EWS88MT_OUTPUT_SENSE : 0);
if (ndata != data && snd_i2c_sendbytes(spec->i2cdevs[EWS_I2C_PCF2],
&ndata, 1) != 1) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
snd_i2c_unlock(ice->i2c);
return ndata != data;
}
static int snd_ice1712_ews88mt_input_sense_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct ews_spec *spec = ice->spec;
int channel = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
unsigned char data;
if (snd_BUG_ON(channel < 0 || channel > 7))
return 0;
snd_i2c_lock(ice->i2c);
if (snd_i2c_readbytes(spec->i2cdevs[EWS_I2C_PCF1], &data, 1) != 1) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
ucontrol->value.enumerated.item[0] = data & (1 << channel) ? 0 : 1;
snd_i2c_unlock(ice->i2c);
return 0;
}
static int snd_ice1712_ews88mt_input_sense_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct ews_spec *spec = ice->spec;
int channel = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
unsigned char data, ndata;
if (snd_BUG_ON(channel < 0 || channel > 7))
return 0;
snd_i2c_lock(ice->i2c);
if (snd_i2c_readbytes(spec->i2cdevs[EWS_I2C_PCF1], &data, 1) != 1) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
ndata = (data & ~(1 << channel)) | (ucontrol->value.enumerated.item[0] ? 0 : (1 << channel));
if (ndata != data && snd_i2c_sendbytes(spec->i2cdevs[EWS_I2C_PCF1],
&ndata, 1) != 1) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
snd_i2c_unlock(ice->i2c);
return ndata != data;
}
static int snd_ice1712_ews88d_control_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct ews_spec *spec = ice->spec;
int shift = kcontrol->private_value & 0xff;
int invert = (kcontrol->private_value >> 8) & 1;
unsigned char data[2];
snd_i2c_lock(ice->i2c);
if (snd_i2c_readbytes(spec->i2cdevs[EWS_I2C_88D], data, 2) != 2) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
snd_i2c_unlock(ice->i2c);
data[0] = (data[shift >> 3] >> (shift & 7)) & 0x01;
if (invert)
data[0] ^= 0x01;
ucontrol->value.integer.value[0] = data[0];
return 0;
}
static int snd_ice1712_ews88d_control_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct ews_spec *spec = ice->spec;
int shift = kcontrol->private_value & 0xff;
int invert = (kcontrol->private_value >> 8) & 1;
unsigned char data[2], ndata[2];
int change;
snd_i2c_lock(ice->i2c);
if (snd_i2c_readbytes(spec->i2cdevs[EWS_I2C_88D], data, 2) != 2) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
ndata[shift >> 3] = data[shift >> 3] & ~(1 << (shift & 7));
if (invert) {
if (! ucontrol->value.integer.value[0])
ndata[shift >> 3] |= (1 << (shift & 7));
} else {
if (ucontrol->value.integer.value[0])
ndata[shift >> 3] |= (1 << (shift & 7));
}
change = (data[shift >> 3] != ndata[shift >> 3]);
if (change &&
snd_i2c_sendbytes(spec->i2cdevs[EWS_I2C_88D], data, 2) != 2) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
snd_i2c_unlock(ice->i2c);
return change;
}
static int snd_ice1712_6fire_read_pca(struct snd_ice1712 *ice, unsigned char reg)
{
unsigned char byte;
struct ews_spec *spec = ice->spec;
snd_i2c_lock(ice->i2c);
byte = reg;
snd_i2c_sendbytes(spec->i2cdevs[EWS_I2C_6FIRE], &byte, 1);
byte = 0;
if (snd_i2c_readbytes(spec->i2cdevs[EWS_I2C_6FIRE], &byte, 1) != 1) {
snd_i2c_unlock(ice->i2c);
dev_err(ice->card->dev, "cannot read pca\n");
return -EIO;
}
snd_i2c_unlock(ice->i2c);
return byte;
}
static int snd_ice1712_6fire_write_pca(struct snd_ice1712 *ice, unsigned char reg, unsigned char data)
{
unsigned char bytes[2];
struct ews_spec *spec = ice->spec;
snd_i2c_lock(ice->i2c);
bytes[0] = reg;
bytes[1] = data;
if (snd_i2c_sendbytes(spec->i2cdevs[EWS_I2C_6FIRE], bytes, 2) != 2) {
snd_i2c_unlock(ice->i2c);
return -EIO;
}
snd_i2c_unlock(ice->i2c);
return 0;
}
static int snd_ice1712_6fire_control_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int shift = kcontrol->private_value & 0xff;
int invert = (kcontrol->private_value >> 8) & 1;
int data;
if ((data = snd_ice1712_6fire_read_pca(ice, PCF9554_REG_OUTPUT)) < 0)
return data;
data = (data >> shift) & 1;
if (invert)
data ^= 1;
ucontrol->value.integer.value[0] = data;
return 0;
}
static int snd_ice1712_6fire_control_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int shift = kcontrol->private_value & 0xff;
int invert = (kcontrol->private_value >> 8) & 1;
int data, ndata;
if ((data = snd_ice1712_6fire_read_pca(ice, PCF9554_REG_OUTPUT)) < 0)
return data;
ndata = data & ~(1 << shift);
if (ucontrol->value.integer.value[0])
ndata |= (1 << shift);
if (invert)
ndata ^= (1 << shift);
if (data != ndata) {
snd_ice1712_6fire_write_pca(ice, PCF9554_REG_OUTPUT, (unsigned char)ndata);
return 1;
}
return 0;
}
static int snd_ice1712_6fire_select_input_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[4] = {
"Internal", "Front Input", "Rear Input", "Wave Table"
};
return snd_ctl_enum_info(uinfo, 1, 4, texts);
}
static int snd_ice1712_6fire_select_input_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int data;
if ((data = snd_ice1712_6fire_read_pca(ice, PCF9554_REG_OUTPUT)) < 0)
return data;
ucontrol->value.integer.value[0] = data & 3;
return 0;
}
static int snd_ice1712_6fire_select_input_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int data, ndata;
if ((data = snd_ice1712_6fire_read_pca(ice, PCF9554_REG_OUTPUT)) < 0)
return data;
ndata = data & ~3;
ndata |= (ucontrol->value.integer.value[0] & 3);
if (data != ndata) {
snd_ice1712_6fire_write_pca(ice, PCF9554_REG_OUTPUT, (unsigned char)ndata);
return 1;
}
return 0;
}
static int snd_ice1712_ews_add_controls(struct snd_ice1712 *ice)
{
unsigned int idx;
int err;
if (ice->cs8427 == NULL) {
err = snd_ice1712_spdif_build_controls(ice);
if (err < 0)
return err;
}
switch (ice->eeprom.subvendor) {
case ICE1712_SUBDEVICE_EWX2496:
case ICE1712_SUBDEVICE_EWS88MT:
case ICE1712_SUBDEVICE_EWS88MT_NEW:
case ICE1712_SUBDEVICE_PHASE88:
case ICE1712_SUBDEVICE_TS88:
case ICE1712_SUBDEVICE_DMX6FIRE:
err = snd_ice1712_akm4xxx_build_controls(ice);
if (err < 0)
return err;
break;
}
switch (ice->eeprom.subvendor) {
case ICE1712_SUBDEVICE_EWX2496:
for (idx = 0; idx < ARRAY_SIZE(snd_ice1712_ewx2496_controls); idx++) {
err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_ewx2496_controls[idx], ice));
if (err < 0)
return err;
}
break;
case ICE1712_SUBDEVICE_EWS88MT:
case ICE1712_SUBDEVICE_EWS88MT_NEW:
case ICE1712_SUBDEVICE_PHASE88:
case ICE1712_SUBDEVICE_TS88:
err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_ews88mt_input_sense, ice));
if (err < 0)
return err;
err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_ews88mt_output_sense, ice));
if (err < 0)
return err;
break;
case ICE1712_SUBDEVICE_EWS88D:
for (idx = 0; idx < ARRAY_SIZE(snd_ice1712_ews88d_controls); idx++) {
err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_ews88d_controls[idx], ice));
if (err < 0)
return err;
}
break;
case ICE1712_SUBDEVICE_DMX6FIRE:
for (idx = 0; idx < ARRAY_SIZE(snd_ice1712_6fire_controls); idx++) {
err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_6fire_controls[idx], ice));
if (err < 0)
return err;
}
break;
}
return 0;
}
