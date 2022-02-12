static int onyx_read_register(struct onyx *onyx, u8 reg, u8 *value)
{
s32 v;
if (reg != ONYX_REG_CONTROL) {
*value = onyx->cache[reg-FIRSTREGISTER];
return 0;
}
v = i2c_smbus_read_byte_data(onyx->i2c, reg);
if (v < 0)
return -1;
*value = (u8)v;
onyx->cache[ONYX_REG_CONTROL-FIRSTREGISTER] = *value;
return 0;
}
static int onyx_write_register(struct onyx *onyx, u8 reg, u8 value)
{
int result;
result = i2c_smbus_write_byte_data(onyx->i2c, reg, value);
if (!result)
onyx->cache[reg-FIRSTREGISTER] = value;
return result;
}
static int onyx_dev_register(struct snd_device *dev)
{
return 0;
}
static int onyx_snd_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = -128 + VOLUME_RANGE_SHIFT;
uinfo->value.integer.max = -1 + VOLUME_RANGE_SHIFT;
return 0;
}
static int onyx_snd_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
s8 l, r;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_DAC_ATTEN_LEFT, &l);
onyx_read_register(onyx, ONYX_REG_DAC_ATTEN_RIGHT, &r);
mutex_unlock(&onyx->mutex);
ucontrol->value.integer.value[0] = l + VOLUME_RANGE_SHIFT;
ucontrol->value.integer.value[1] = r + VOLUME_RANGE_SHIFT;
return 0;
}
static int onyx_snd_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
s8 l, r;
if (ucontrol->value.integer.value[0] < -128 + VOLUME_RANGE_SHIFT ||
ucontrol->value.integer.value[0] > -1 + VOLUME_RANGE_SHIFT)
return -EINVAL;
if (ucontrol->value.integer.value[1] < -128 + VOLUME_RANGE_SHIFT ||
ucontrol->value.integer.value[1] > -1 + VOLUME_RANGE_SHIFT)
return -EINVAL;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_DAC_ATTEN_LEFT, &l);
onyx_read_register(onyx, ONYX_REG_DAC_ATTEN_RIGHT, &r);
if (l + VOLUME_RANGE_SHIFT == ucontrol->value.integer.value[0] &&
r + VOLUME_RANGE_SHIFT == ucontrol->value.integer.value[1]) {
mutex_unlock(&onyx->mutex);
return 0;
}
onyx_write_register(onyx, ONYX_REG_DAC_ATTEN_LEFT,
ucontrol->value.integer.value[0]
- VOLUME_RANGE_SHIFT);
onyx_write_register(onyx, ONYX_REG_DAC_ATTEN_RIGHT,
ucontrol->value.integer.value[1]
- VOLUME_RANGE_SHIFT);
mutex_unlock(&onyx->mutex);
return 1;
}
static int onyx_snd_inputgain_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 3 + INPUTGAIN_RANGE_SHIFT;
uinfo->value.integer.max = 28 + INPUTGAIN_RANGE_SHIFT;
return 0;
}
static int onyx_snd_inputgain_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
u8 ig;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_ADC_CONTROL, &ig);
mutex_unlock(&onyx->mutex);
ucontrol->value.integer.value[0] =
(ig & ONYX_ADC_PGA_GAIN_MASK) + INPUTGAIN_RANGE_SHIFT;
return 0;
}
static int onyx_snd_inputgain_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
u8 v, n;
if (ucontrol->value.integer.value[0] < 3 + INPUTGAIN_RANGE_SHIFT ||
ucontrol->value.integer.value[0] > 28 + INPUTGAIN_RANGE_SHIFT)
return -EINVAL;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_ADC_CONTROL, &v);
n = v;
n &= ~ONYX_ADC_PGA_GAIN_MASK;
n |= (ucontrol->value.integer.value[0] - INPUTGAIN_RANGE_SHIFT)
& ONYX_ADC_PGA_GAIN_MASK;
onyx_write_register(onyx, ONYX_REG_ADC_CONTROL, n);
mutex_unlock(&onyx->mutex);
return n != v;
}
static int onyx_snd_capture_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[] = { "Line-In", "Microphone" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item > 1)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int onyx_snd_capture_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
s8 v;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_ADC_CONTROL, &v);
mutex_unlock(&onyx->mutex);
ucontrol->value.enumerated.item[0] = !!(v&ONYX_ADC_INPUT_MIC);
return 0;
}
static void onyx_set_capture_source(struct onyx *onyx, int mic)
{
s8 v;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_ADC_CONTROL, &v);
v &= ~ONYX_ADC_INPUT_MIC;
if (mic)
v |= ONYX_ADC_INPUT_MIC;
onyx_write_register(onyx, ONYX_REG_ADC_CONTROL, v);
mutex_unlock(&onyx->mutex);
}
static int onyx_snd_capture_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
if (ucontrol->value.enumerated.item[0] > 1)
return -EINVAL;
onyx_set_capture_source(snd_kcontrol_chip(kcontrol),
ucontrol->value.enumerated.item[0]);
return 1;
}
static int onyx_snd_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
u8 c;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_DAC_CONTROL, &c);
mutex_unlock(&onyx->mutex);
ucontrol->value.integer.value[0] = !(c & ONYX_MUTE_LEFT);
ucontrol->value.integer.value[1] = !(c & ONYX_MUTE_RIGHT);
return 0;
}
static int onyx_snd_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
u8 v = 0, c = 0;
int err = -EBUSY;
mutex_lock(&onyx->mutex);
if (onyx->analog_locked)
goto out_unlock;
onyx_read_register(onyx, ONYX_REG_DAC_CONTROL, &v);
c = v;
c &= ~(ONYX_MUTE_RIGHT | ONYX_MUTE_LEFT);
if (!ucontrol->value.integer.value[0])
c |= ONYX_MUTE_LEFT;
if (!ucontrol->value.integer.value[1])
c |= ONYX_MUTE_RIGHT;
err = onyx_write_register(onyx, ONYX_REG_DAC_CONTROL, c);
out_unlock:
mutex_unlock(&onyx->mutex);
return !err ? (v != c) : err;
}
static int onyx_snd_single_bit_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
u8 c;
long int pv = kcontrol->private_value;
u8 polarity = (pv >> 16) & FLAG_POLARITY_INVERT;
u8 address = (pv >> 8) & 0xff;
u8 mask = pv & 0xff;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, address, &c);
mutex_unlock(&onyx->mutex);
ucontrol->value.integer.value[0] = !!(c & mask) ^ polarity;
return 0;
}
static int onyx_snd_single_bit_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
u8 v = 0, c = 0;
int err;
long int pv = kcontrol->private_value;
u8 polarity = (pv >> 16) & FLAG_POLARITY_INVERT;
u8 spdiflock = (pv >> 16) & FLAG_SPDIFLOCK;
u8 address = (pv >> 8) & 0xff;
u8 mask = pv & 0xff;
mutex_lock(&onyx->mutex);
if (spdiflock && onyx->spdif_locked) {
err = -EBUSY;
goto out_unlock;
}
onyx_read_register(onyx, address, &v);
c = v;
c &= ~(mask);
if (!!ucontrol->value.integer.value[0] ^ polarity)
c |= mask;
err = onyx_write_register(onyx, address, c);
out_unlock:
mutex_unlock(&onyx->mutex);
return !err ? (v != c) : err;
}
static int onyx_spdif_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int onyx_spdif_mask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = 0x3e;
ucontrol->value.iec958.status[1] = 0xff;
ucontrol->value.iec958.status[3] = 0x3f;
ucontrol->value.iec958.status[4] = 0x0f;
return 0;
}
static int onyx_spdif_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
u8 v;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_DIG_INFO1, &v);
ucontrol->value.iec958.status[0] = v & 0x3e;
onyx_read_register(onyx, ONYX_REG_DIG_INFO2, &v);
ucontrol->value.iec958.status[1] = v;
onyx_read_register(onyx, ONYX_REG_DIG_INFO3, &v);
ucontrol->value.iec958.status[3] = v & 0x3f;
onyx_read_register(onyx, ONYX_REG_DIG_INFO4, &v);
ucontrol->value.iec958.status[4] = v & 0x0f;
mutex_unlock(&onyx->mutex);
return 0;
}
static int onyx_spdif_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct onyx *onyx = snd_kcontrol_chip(kcontrol);
u8 v;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_DIG_INFO1, &v);
v = (v & ~0x3e) | (ucontrol->value.iec958.status[0] & 0x3e);
onyx_write_register(onyx, ONYX_REG_DIG_INFO1, v);
v = ucontrol->value.iec958.status[1];
onyx_write_register(onyx, ONYX_REG_DIG_INFO2, v);
onyx_read_register(onyx, ONYX_REG_DIG_INFO3, &v);
v = (v & ~0x3f) | (ucontrol->value.iec958.status[3] & 0x3f);
onyx_write_register(onyx, ONYX_REG_DIG_INFO3, v);
onyx_read_register(onyx, ONYX_REG_DIG_INFO4, &v);
v = (v & ~0x0f) | (ucontrol->value.iec958.status[4] & 0x0f);
onyx_write_register(onyx, ONYX_REG_DIG_INFO4, v);
mutex_unlock(&onyx->mutex);
return 1;
}
static int onyx_register_init(struct onyx *onyx)
{
int i;
u8 val;
u8 regs[sizeof(initial_values)];
if (!onyx->initialised) {
memcpy(regs, initial_values, sizeof(initial_values));
if (onyx_read_register(onyx, ONYX_REG_CONTROL, &val))
return -1;
val &= ~ONYX_SILICONVERSION;
val |= initial_values[3];
regs[3] = val;
} else {
for (i=0; i<sizeof(register_map); i++)
regs[i] = onyx->cache[register_map[i]-FIRSTREGISTER];
}
for (i=0; i<sizeof(register_map); i++) {
if (onyx_write_register(onyx, register_map[i], regs[i]))
return -1;
}
onyx->initialised = 1;
return 0;
}
static int onyx_usable(struct codec_info_item *cii,
struct transfer_info *ti,
struct transfer_info *out)
{
u8 v;
struct onyx *onyx = cii->codec_data;
int spdif_enabled, analog_enabled;
mutex_lock(&onyx->mutex);
onyx_read_register(onyx, ONYX_REG_DIG_INFO4, &v);
spdif_enabled = !!(v & ONYX_SPDIF_ENABLE);
onyx_read_register(onyx, ONYX_REG_DAC_CONTROL, &v);
analog_enabled =
(v & (ONYX_MUTE_RIGHT|ONYX_MUTE_LEFT))
!= (ONYX_MUTE_RIGHT|ONYX_MUTE_LEFT);
mutex_unlock(&onyx->mutex);
switch (ti->tag) {
case 0: return 1;
case 1: return analog_enabled;
case 2: return spdif_enabled;
}
return 1;
}
static int onyx_prepare(struct codec_info_item *cii,
struct bus_info *bi,
struct snd_pcm_substream *substream)
{
u8 v;
struct onyx *onyx = cii->codec_data;
int err = -EBUSY;
mutex_lock(&onyx->mutex);
#ifdef SNDRV_PCM_FMTBIT_COMPRESSED_16BE
if (substream->runtime->format == SNDRV_PCM_FMTBIT_COMPRESSED_16BE) {
onyx_read_register(onyx, ONYX_REG_DAC_CONTROL, &v);
if (onyx_write_register(onyx,
ONYX_REG_DAC_CONTROL,
v | ONYX_MUTE_RIGHT | ONYX_MUTE_LEFT))
goto out_unlock;
onyx->analog_locked = 1;
err = 0;
goto out_unlock;
}
#endif
switch (substream->runtime->rate) {
case 32000:
case 44100:
case 48000:
err = 0;
goto out_unlock;
default:
onyx_read_register(cii->codec_data, ONYX_REG_DIG_INFO4, &v);
if (onyx_write_register(onyx,
ONYX_REG_DIG_INFO4,
v & ~ONYX_SPDIF_ENABLE))
goto out_unlock;
onyx->spdif_locked = 1;
err = 0;
goto out_unlock;
}
out_unlock:
mutex_unlock(&onyx->mutex);
return err;
}
static int onyx_open(struct codec_info_item *cii,
struct snd_pcm_substream *substream)
{
struct onyx *onyx = cii->codec_data;
mutex_lock(&onyx->mutex);
onyx->open_count++;
mutex_unlock(&onyx->mutex);
return 0;
}
static int onyx_close(struct codec_info_item *cii,
struct snd_pcm_substream *substream)
{
struct onyx *onyx = cii->codec_data;
mutex_lock(&onyx->mutex);
onyx->open_count--;
if (!onyx->open_count)
onyx->spdif_locked = onyx->analog_locked = 0;
mutex_unlock(&onyx->mutex);
return 0;
}
static int onyx_switch_clock(struct codec_info_item *cii,
enum clock_switch what)
{
struct onyx *onyx = cii->codec_data;
mutex_lock(&onyx->mutex);
switch (what) {
case CLOCK_SWITCH_PREPARE_SLAVE:
onyx->codec.gpio->methods->all_amps_off(onyx->codec.gpio);
break;
case CLOCK_SWITCH_SLAVE:
onyx->codec.gpio->methods->all_amps_restore(onyx->codec.gpio);
break;
default:
break;
}
mutex_unlock(&onyx->mutex);
return 0;
}
static int onyx_suspend(struct codec_info_item *cii, pm_message_t state)
{
struct onyx *onyx = cii->codec_data;
u8 v;
int err = -ENXIO;
mutex_lock(&onyx->mutex);
if (onyx_read_register(onyx, ONYX_REG_CONTROL, &v))
goto out_unlock;
onyx_write_register(onyx, ONYX_REG_CONTROL, v | ONYX_ADPSV | ONYX_DAPSV);
err = 0;
out_unlock:
mutex_unlock(&onyx->mutex);
return err;
}
static int onyx_resume(struct codec_info_item *cii)
{
struct onyx *onyx = cii->codec_data;
u8 v;
int err = -ENXIO;
mutex_lock(&onyx->mutex);
onyx->codec.gpio->methods->set_hw_reset(onyx->codec.gpio, 0);
msleep(1);
onyx->codec.gpio->methods->set_hw_reset(onyx->codec.gpio, 1);
msleep(1);
onyx->codec.gpio->methods->set_hw_reset(onyx->codec.gpio, 0);
msleep(1);
if (onyx_read_register(onyx, ONYX_REG_CONTROL, &v))
goto out_unlock;
onyx_write_register(onyx, ONYX_REG_CONTROL, v & ~(ONYX_ADPSV | ONYX_DAPSV));
msleep(2205000/8000);
onyx_register_init(onyx);
err = 0;
out_unlock:
mutex_unlock(&onyx->mutex);
return err;
}
static int onyx_init_codec(struct aoa_codec *codec)
{
struct onyx *onyx = codec_to_onyx(codec);
struct snd_kcontrol *ctl;
struct codec_info *ci = &onyx_codec_info;
u8 v;
int err;
if (!onyx->codec.gpio || !onyx->codec.gpio->methods) {
printk(KERN_ERR PFX "gpios not assigned!!\n");
return -EINVAL;
}
onyx->codec.gpio->methods->set_hw_reset(onyx->codec.gpio, 0);
msleep(1);
onyx->codec.gpio->methods->set_hw_reset(onyx->codec.gpio, 1);
msleep(1);
onyx->codec.gpio->methods->set_hw_reset(onyx->codec.gpio, 0);
msleep(1);
if (onyx_register_init(onyx)) {
printk(KERN_ERR PFX "failed to initialise onyx registers\n");
return -ENODEV;
}
if (aoa_snd_device_new(SNDRV_DEV_LOWLEVEL, onyx, &ops)) {
printk(KERN_ERR PFX "failed to create onyx snd device!\n");
return -ENODEV;
}
if ((onyx->codec.connected & 0xF) == 0)
return -ENOTCONN;
if ((onyx->codec.connected & 0xC) == 0) {
if (!onyx->codec_info)
onyx->codec_info = kmalloc(sizeof(struct codec_info), GFP_KERNEL);
if (!onyx->codec_info)
return -ENOMEM;
ci = onyx->codec_info;
*ci = onyx_codec_info;
ci->transfers++;
}
if ((onyx->codec.connected & 3) == 0) {
if (!onyx->codec_info)
onyx->codec_info = kmalloc(sizeof(struct codec_info), GFP_KERNEL);
if (!onyx->codec_info)
return -ENOMEM;
ci = onyx->codec_info;
*ci = onyx_codec_info;
ci->transfers[1].formats = 0;
}
if (onyx->codec.soundbus_dev->attach_codec(onyx->codec.soundbus_dev,
aoa_get_card(),
ci, onyx)) {
printk(KERN_ERR PFX "error creating onyx pcm\n");
return -ENODEV;
}
#define ADDCTL(n) \
do { \
ctl = snd_ctl_new1(&n, onyx); \
if (ctl) { \
ctl->id.device = \
onyx->codec.soundbus_dev->pcm->device; \
err = aoa_snd_ctl_add(ctl); \
if (err) \
goto error; \
} \
} while (0)
if (onyx->codec.soundbus_dev->pcm) {
if ((onyx->codec.connected & 0xC) == 0xC)
ADDCTL(capture_source_control);
else if (onyx->codec.connected & 4)
onyx_set_capture_source(onyx, 0);
else
onyx_set_capture_source(onyx, 1);
if (onyx->codec.connected & 0xC)
ADDCTL(inputgain_control);
if (onyx->codec.connected & 1) {
ADDCTL(volume_control);
ADDCTL(mute_control);
ADDCTL(ovr1_control);
ADDCTL(flt0_control);
ADDCTL(hpf_control);
ADDCTL(dm12_control);
}
if (onyx->codec.connected & 2) {
ADDCTL(onyx_spdif_mask);
ADDCTL(onyx_spdif_ctrl);
}
if ((onyx->codec.connected & 3) == 3)
ADDCTL(spdif_control);
if ((onyx->codec.connected & 3) == 2) {
onyx_read_register(onyx, ONYX_REG_DIG_INFO4, &v);
v |= ONYX_SPDIF_ENABLE;
onyx_write_register(onyx, ONYX_REG_DIG_INFO4, v);
}
}
#undef ADDCTL
printk(KERN_INFO PFX "attached to onyx codec via i2c\n");
return 0;
error:
onyx->codec.soundbus_dev->detach_codec(onyx->codec.soundbus_dev, onyx);
snd_device_free(aoa_get_card(), onyx);
return err;
}
static void onyx_exit_codec(struct aoa_codec *codec)
{
struct onyx *onyx = codec_to_onyx(codec);
if (!onyx->codec.soundbus_dev) {
printk(KERN_ERR PFX "onyx_exit_codec called without soundbus_dev!\n");
return;
}
onyx->codec.soundbus_dev->detach_codec(onyx->codec.soundbus_dev, onyx);
}
static int onyx_create(struct i2c_adapter *adapter,
struct device_node *node,
int addr)
{
struct i2c_board_info info;
struct i2c_client *client;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "aoa_codec_onyx", I2C_NAME_SIZE);
info.addr = addr;
info.platform_data = node;
client = i2c_new_device(adapter, &info);
if (!client)
return -ENODEV;
if (!client->driver) {
i2c_unregister_device(client);
return -ENODEV;
}
list_add_tail(&client->detected, &client->driver->clients);
return 0;
}
static int onyx_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device_node *node = client->dev.platform_data;
struct onyx *onyx;
u8 dummy;
onyx = kzalloc(sizeof(struct onyx), GFP_KERNEL);
if (!onyx)
return -ENOMEM;
mutex_init(&onyx->mutex);
onyx->i2c = client;
i2c_set_clientdata(client, onyx);
if (onyx_read_register(onyx, ONYX_REG_CONTROL, &dummy) != 0) {
printk(KERN_ERR PFX "failed to read control register\n");
goto fail;
}
strlcpy(onyx->codec.name, "onyx", MAX_CODEC_NAME_LEN);
onyx->codec.owner = THIS_MODULE;
onyx->codec.init = onyx_init_codec;
onyx->codec.exit = onyx_exit_codec;
onyx->codec.node = of_node_get(node);
if (aoa_codec_register(&onyx->codec)) {
goto fail;
}
printk(KERN_DEBUG PFX "created and attached onyx instance\n");
return 0;
fail:
i2c_set_clientdata(client, NULL);
kfree(onyx);
return -ENODEV;
}
static int onyx_i2c_attach(struct i2c_adapter *adapter)
{
struct device_node *busnode, *dev = NULL;
struct pmac_i2c_bus *bus;
bus = pmac_i2c_adapter_to_bus(adapter);
if (bus == NULL)
return -ENODEV;
busnode = pmac_i2c_get_bus_node(bus);
while ((dev = of_get_next_child(busnode, dev)) != NULL) {
if (of_device_is_compatible(dev, "pcm3052")) {
const u32 *addr;
printk(KERN_DEBUG PFX "found pcm3052\n");
addr = of_get_property(dev, "reg", NULL);
if (!addr)
return -ENODEV;
return onyx_create(adapter, dev, (*addr)>>1);
}
}
if (!of_device_is_compatible(busnode, "k2-i2c"))
return -ENODEV;
printk(KERN_DEBUG PFX "found k2-i2c, checking if onyx chip is on it\n");
if (onyx_create(adapter, NULL, 0x46) == 0)
return 0;
return onyx_create(adapter, NULL, 0x47);
}
static int onyx_i2c_remove(struct i2c_client *client)
{
struct onyx *onyx = i2c_get_clientdata(client);
aoa_codec_unregister(&onyx->codec);
of_node_put(onyx->codec.node);
if (onyx->codec_info)
kfree(onyx->codec_info);
kfree(onyx);
return 0;
}
static int __init onyx_init(void)
{
return i2c_add_driver(&onyx_driver);
}
static void __exit onyx_exit(void)
{
i2c_del_driver(&onyx_driver);
}
