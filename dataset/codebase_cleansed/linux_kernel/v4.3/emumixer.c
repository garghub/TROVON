static int snd_emu10k1_spdif_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_emu10k1_spdif_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
unsigned long flags;
if (idx >= 3)
return -EINVAL;
spin_lock_irqsave(&emu->reg_lock, flags);
ucontrol->value.iec958.status[0] = (emu->spdif_bits[idx] >> 0) & 0xff;
ucontrol->value.iec958.status[1] = (emu->spdif_bits[idx] >> 8) & 0xff;
ucontrol->value.iec958.status[2] = (emu->spdif_bits[idx] >> 16) & 0xff;
ucontrol->value.iec958.status[3] = (emu->spdif_bits[idx] >> 24) & 0xff;
spin_unlock_irqrestore(&emu->reg_lock, flags);
return 0;
}
static int snd_emu10k1_spdif_get_mask(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = 0xff;
ucontrol->value.iec958.status[1] = 0xff;
ucontrol->value.iec958.status[2] = 0xff;
ucontrol->value.iec958.status[3] = 0xff;
return 0;
}
static int snd_emu1010_input_output_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
if (emu->card_capabilities->emu_model == EMU_MODEL_EMU1616)
return snd_ctl_enum_info(uinfo, 1, 49, emu1616_src_texts);
else
return snd_ctl_enum_info(uinfo, 1, 53, emu1010_src_texts);
}
static int snd_emu1010_output_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int channel;
channel = (kcontrol->private_value) & 0xff;
if (channel >= 24 ||
(emu->card_capabilities->emu_model == EMU_MODEL_EMU1616 &&
channel >= 18))
return -EINVAL;
ucontrol->value.enumerated.item[0] = emu->emu1010.output_source[channel];
return 0;
}
static int snd_emu1010_output_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
unsigned int channel;
val = ucontrol->value.enumerated.item[0];
if (val >= 53 ||
(emu->card_capabilities->emu_model == EMU_MODEL_EMU1616 &&
val >= 49))
return -EINVAL;
channel = (kcontrol->private_value) & 0xff;
if (channel >= 24 ||
(emu->card_capabilities->emu_model == EMU_MODEL_EMU1616 &&
channel >= 18))
return -EINVAL;
if (emu->emu1010.output_source[channel] == val)
return 0;
emu->emu1010.output_source[channel] = val;
if (emu->card_capabilities->emu_model == EMU_MODEL_EMU1616)
snd_emu1010_fpga_link_dst_src_write(emu,
emu1616_output_dst[channel], emu1616_src_regs[val]);
else
snd_emu1010_fpga_link_dst_src_write(emu,
emu1010_output_dst[channel], emu1010_src_regs[val]);
return 1;
}
static int snd_emu1010_input_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int channel;
channel = (kcontrol->private_value) & 0xff;
if (channel >= 22)
return -EINVAL;
ucontrol->value.enumerated.item[0] = emu->emu1010.input_source[channel];
return 0;
}
static int snd_emu1010_input_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
unsigned int channel;
val = ucontrol->value.enumerated.item[0];
if (val >= 53 ||
(emu->card_capabilities->emu_model == EMU_MODEL_EMU1616 &&
val >= 49))
return -EINVAL;
channel = (kcontrol->private_value) & 0xff;
if (channel >= 22)
return -EINVAL;
if (emu->emu1010.input_source[channel] == val)
return 0;
emu->emu1010.input_source[channel] = val;
if (emu->card_capabilities->emu_model == EMU_MODEL_EMU1616)
snd_emu1010_fpga_link_dst_src_write(emu,
emu1010_input_dst[channel], emu1616_src_regs[val]);
else
snd_emu1010_fpga_link_dst_src_write(emu,
emu1010_input_dst[channel], emu1010_src_regs[val]);
return 1;
}
static int snd_emu1010_adc_pads_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int mask = kcontrol->private_value & 0xff;
ucontrol->value.integer.value[0] = (emu->emu1010.adc_pads & mask) ? 1 : 0;
return 0;
}
static int snd_emu1010_adc_pads_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int mask = kcontrol->private_value & 0xff;
unsigned int val, cache;
val = ucontrol->value.integer.value[0];
cache = emu->emu1010.adc_pads;
if (val == 1)
cache = cache | mask;
else
cache = cache & ~mask;
if (cache != emu->emu1010.adc_pads) {
snd_emu1010_fpga_write(emu, EMU_HANA_ADC_PADS, cache );
emu->emu1010.adc_pads = cache;
}
return 0;
}
static int snd_emu1010_dac_pads_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int mask = kcontrol->private_value & 0xff;
ucontrol->value.integer.value[0] = (emu->emu1010.dac_pads & mask) ? 1 : 0;
return 0;
}
static int snd_emu1010_dac_pads_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int mask = kcontrol->private_value & 0xff;
unsigned int val, cache;
val = ucontrol->value.integer.value[0];
cache = emu->emu1010.dac_pads;
if (val == 1)
cache = cache | mask;
else
cache = cache & ~mask;
if (cache != emu->emu1010.dac_pads) {
snd_emu1010_fpga_write(emu, EMU_HANA_DAC_PADS, cache );
emu->emu1010.dac_pads = cache;
}
return 0;
}
static int snd_emu1010_internal_clock_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[4] = {
"44100", "48000", "SPDIF", "ADAT"
};
return snd_ctl_enum_info(uinfo, 1, 4, texts);
}
static int snd_emu1010_internal_clock_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = emu->emu1010.internal_clock;
return 0;
}
static int snd_emu1010_internal_clock_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change = 0;
val = ucontrol->value.enumerated.item[0] ;
if (val >= 4)
return -EINVAL;
change = (emu->emu1010.internal_clock != val);
if (change) {
emu->emu1010.internal_clock = val;
switch (val) {
case 0:
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, EMU_MUTE );
snd_emu1010_fpga_write(emu, EMU_HANA_DEFCLOCK, EMU_HANA_DEFCLOCK_44_1K );
snd_emu1010_fpga_write(emu, EMU_HANA_WCLOCK,
EMU_HANA_WCLOCK_INT_44_1K | EMU_HANA_WCLOCK_1X );
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_LEDS_2,
EMU_HANA_DOCK_LEDS_2_44K | EMU_HANA_DOCK_LEDS_2_LOCK );
msleep(10);
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, EMU_UNMUTE );
break;
case 1:
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, EMU_MUTE );
snd_emu1010_fpga_write(emu, EMU_HANA_DEFCLOCK, EMU_HANA_DEFCLOCK_48K );
snd_emu1010_fpga_write(emu, EMU_HANA_WCLOCK,
EMU_HANA_WCLOCK_INT_48K | EMU_HANA_WCLOCK_1X );
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_LEDS_2,
EMU_HANA_DOCK_LEDS_2_48K | EMU_HANA_DOCK_LEDS_2_LOCK );
msleep(10);
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, EMU_UNMUTE );
break;
case 2:
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, EMU_MUTE );
snd_emu1010_fpga_write(emu, EMU_HANA_DEFCLOCK, EMU_HANA_DEFCLOCK_48K );
snd_emu1010_fpga_write(emu, EMU_HANA_WCLOCK,
EMU_HANA_WCLOCK_HANA_SPDIF_IN | EMU_HANA_WCLOCK_1X );
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_LEDS_2,
EMU_HANA_DOCK_LEDS_2_EXT | EMU_HANA_DOCK_LEDS_2_LOCK );
msleep(10);
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, EMU_UNMUTE );
break;
case 3:
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, EMU_MUTE );
snd_emu1010_fpga_write(emu, EMU_HANA_DEFCLOCK, EMU_HANA_DEFCLOCK_48K );
snd_emu1010_fpga_write(emu, EMU_HANA_WCLOCK,
EMU_HANA_WCLOCK_HANA_ADAT_IN | EMU_HANA_WCLOCK_1X );
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_LEDS_2, EMU_HANA_DOCK_LEDS_2_EXT | EMU_HANA_DOCK_LEDS_2_LOCK );
msleep(10);
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, EMU_UNMUTE );
break;
}
}
return change;
}
static int snd_emu1010_optical_out_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[2] = {
"SPDIF", "ADAT"
};
return snd_ctl_enum_info(uinfo, 1, 2, texts);
}
static int snd_emu1010_optical_out_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = emu->emu1010.optical_out;
return 0;
}
static int snd_emu1010_optical_out_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
u32 tmp;
int change = 0;
val = ucontrol->value.enumerated.item[0];
if (val >= 2)
return -EINVAL;
change = (emu->emu1010.optical_out != val);
if (change) {
emu->emu1010.optical_out = val;
tmp = (emu->emu1010.optical_in ? EMU_HANA_OPTICAL_IN_ADAT : 0) |
(emu->emu1010.optical_out ? EMU_HANA_OPTICAL_OUT_ADAT : 0);
snd_emu1010_fpga_write(emu, EMU_HANA_OPTICAL_TYPE, tmp);
}
return change;
}
static int snd_emu1010_optical_in_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[2] = {
"SPDIF", "ADAT"
};
return snd_ctl_enum_info(uinfo, 1, 2, texts);
}
static int snd_emu1010_optical_in_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = emu->emu1010.optical_in;
return 0;
}
static int snd_emu1010_optical_in_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
u32 tmp;
int change = 0;
val = ucontrol->value.enumerated.item[0];
if (val >= 2)
return -EINVAL;
change = (emu->emu1010.optical_in != val);
if (change) {
emu->emu1010.optical_in = val;
tmp = (emu->emu1010.optical_in ? EMU_HANA_OPTICAL_IN_ADAT : 0) |
(emu->emu1010.optical_out ? EMU_HANA_OPTICAL_OUT_ADAT : 0);
snd_emu1010_fpga_write(emu, EMU_HANA_OPTICAL_TYPE, tmp);
}
return change;
}
static int snd_audigy_i2c_capture_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
#if 0
static const char * const texts[4] = {
"Unknown1", "Unknown2", "Mic", "Line"
};
#endif
static const char * const texts[2] = {
"Mic", "Line"
};
return snd_ctl_enum_info(uinfo, 1, 2, texts);
}
static int snd_audigy_i2c_capture_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = emu->i2c_capture_source;
return 0;
}
static int snd_audigy_i2c_capture_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int source_id;
unsigned int ngain, ogain;
u32 gpio;
int change = 0;
unsigned long flags;
u32 source;
source_id = ucontrol->value.enumerated.item[0];
if (source_id >= 2)
return -EINVAL;
change = (emu->i2c_capture_source != source_id);
if (change) {
snd_emu10k1_i2c_write(emu, ADC_MUX, 0);
spin_lock_irqsave(&emu->emu_lock, flags);
gpio = inl(emu->port + A_IOCFG);
if (source_id==0)
outl(gpio | 0x4, emu->port + A_IOCFG);
else
outl(gpio & ~0x4, emu->port + A_IOCFG);
spin_unlock_irqrestore(&emu->emu_lock, flags);
ngain = emu->i2c_capture_volume[source_id][0];
ogain = emu->i2c_capture_volume[emu->i2c_capture_source][0];
if (ngain != ogain)
snd_emu10k1_i2c_write(emu, ADC_ATTEN_ADCL, ((ngain) & 0xff));
ngain = emu->i2c_capture_volume[source_id][1];
ogain = emu->i2c_capture_volume[emu->i2c_capture_source][1];
if (ngain != ogain)
snd_emu10k1_i2c_write(emu, ADC_ATTEN_ADCR, ((ngain) & 0xff));
source = 1 << (source_id + 2);
snd_emu10k1_i2c_write(emu, ADC_MUX, source);
emu->i2c_capture_source = source_id;
}
return change;
}
static int snd_audigy_i2c_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 255;
return 0;
}
static int snd_audigy_i2c_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int source_id;
source_id = kcontrol->private_value;
if (source_id >= 2)
return -EINVAL;
ucontrol->value.integer.value[0] = emu->i2c_capture_volume[source_id][0];
ucontrol->value.integer.value[1] = emu->i2c_capture_volume[source_id][1];
return 0;
}
static int snd_audigy_i2c_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int ogain;
unsigned int ngain;
unsigned int source_id;
int change = 0;
source_id = kcontrol->private_value;
if (source_id >= 2)
return -EINVAL;
ogain = emu->i2c_capture_volume[source_id][0];
ngain = ucontrol->value.integer.value[0];
if (ngain > 0xff)
return 0;
if (ogain != ngain) {
if (emu->i2c_capture_source == source_id)
snd_emu10k1_i2c_write(emu, ADC_ATTEN_ADCL, ((ngain) & 0xff) );
emu->i2c_capture_volume[source_id][0] = ngain;
change = 1;
}
ogain = emu->i2c_capture_volume[source_id][1];
ngain = ucontrol->value.integer.value[1];
if (ngain > 0xff)
return 0;
if (ogain != ngain) {
if (emu->i2c_capture_source == source_id)
snd_emu10k1_i2c_write(emu, ADC_ATTEN_ADCR, ((ngain) & 0xff));
emu->i2c_capture_volume[source_id][1] = ngain;
change = 1;
}
return change;
}
static int snd_emu10k1_spdif_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
int change;
unsigned int val;
unsigned long flags;
if (idx >= 3)
return -EINVAL;
val = (ucontrol->value.iec958.status[0] << 0) |
(ucontrol->value.iec958.status[1] << 8) |
(ucontrol->value.iec958.status[2] << 16) |
(ucontrol->value.iec958.status[3] << 24);
spin_lock_irqsave(&emu->reg_lock, flags);
change = val != emu->spdif_bits[idx];
if (change) {
snd_emu10k1_ptr_write(emu, SPCS0 + idx, 0, val);
emu->spdif_bits[idx] = val;
}
spin_unlock_irqrestore(&emu->reg_lock, flags);
return change;
}
static void update_emu10k1_fxrt(struct snd_emu10k1 *emu, int voice, unsigned char *route)
{
if (emu->audigy) {
snd_emu10k1_ptr_write(emu, A_FXRT1, voice,
snd_emu10k1_compose_audigy_fxrt1(route));
snd_emu10k1_ptr_write(emu, A_FXRT2, voice,
snd_emu10k1_compose_audigy_fxrt2(route));
} else {
snd_emu10k1_ptr_write(emu, FXRT, voice,
snd_emu10k1_compose_send_routing(route));
}
}
static void update_emu10k1_send_volume(struct snd_emu10k1 *emu, int voice, unsigned char *volume)
{
snd_emu10k1_ptr_write(emu, PTRX_FXSENDAMOUNT_A, voice, volume[0]);
snd_emu10k1_ptr_write(emu, PTRX_FXSENDAMOUNT_B, voice, volume[1]);
snd_emu10k1_ptr_write(emu, PSST_FXSENDAMOUNT_C, voice, volume[2]);
snd_emu10k1_ptr_write(emu, DSL_FXSENDAMOUNT_D, voice, volume[3]);
if (emu->audigy) {
unsigned int val = ((unsigned int)volume[4] << 24) |
((unsigned int)volume[5] << 16) |
((unsigned int)volume[6] << 8) |
(unsigned int)volume[7];
snd_emu10k1_ptr_write(emu, A_SENDAMOUNTS, voice, val);
}
}
static int snd_emu10k1_send_routing_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = emu->audigy ? 3*8 : 3*4;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = emu->audigy ? 0x3f : 0x0f;
return 0;
}
static int snd_emu10k1_send_routing_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_pcm_mixer *mix =
&emu->pcm_mixer[snd_ctl_get_ioffidx(kcontrol, &ucontrol->id)];
int voice, idx;
int num_efx = emu->audigy ? 8 : 4;
int mask = emu->audigy ? 0x3f : 0x0f;
spin_lock_irqsave(&emu->reg_lock, flags);
for (voice = 0; voice < 3; voice++)
for (idx = 0; idx < num_efx; idx++)
ucontrol->value.integer.value[(voice * num_efx) + idx] =
mix->send_routing[voice][idx] & mask;
spin_unlock_irqrestore(&emu->reg_lock, flags);
return 0;
}
static int snd_emu10k1_send_routing_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_pcm_mixer *mix =
&emu->pcm_mixer[snd_ctl_get_ioffidx(kcontrol, &ucontrol->id)];
int change = 0, voice, idx, val;
int num_efx = emu->audigy ? 8 : 4;
int mask = emu->audigy ? 0x3f : 0x0f;
spin_lock_irqsave(&emu->reg_lock, flags);
for (voice = 0; voice < 3; voice++)
for (idx = 0; idx < num_efx; idx++) {
val = ucontrol->value.integer.value[(voice * num_efx) + idx] & mask;
if (mix->send_routing[voice][idx] != val) {
mix->send_routing[voice][idx] = val;
change = 1;
}
}
if (change && mix->epcm) {
if (mix->epcm->voices[0] && mix->epcm->voices[1]) {
update_emu10k1_fxrt(emu, mix->epcm->voices[0]->number,
&mix->send_routing[1][0]);
update_emu10k1_fxrt(emu, mix->epcm->voices[1]->number,
&mix->send_routing[2][0]);
} else if (mix->epcm->voices[0]) {
update_emu10k1_fxrt(emu, mix->epcm->voices[0]->number,
&mix->send_routing[0][0]);
}
}
spin_unlock_irqrestore(&emu->reg_lock, flags);
return change;
}
static int snd_emu10k1_send_volume_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = emu->audigy ? 3*8 : 3*4;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 255;
return 0;
}
static int snd_emu10k1_send_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_pcm_mixer *mix =
&emu->pcm_mixer[snd_ctl_get_ioffidx(kcontrol, &ucontrol->id)];
int idx;
int num_efx = emu->audigy ? 8 : 4;
spin_lock_irqsave(&emu->reg_lock, flags);
for (idx = 0; idx < 3*num_efx; idx++)
ucontrol->value.integer.value[idx] = mix->send_volume[idx/num_efx][idx%num_efx];
spin_unlock_irqrestore(&emu->reg_lock, flags);
return 0;
}
static int snd_emu10k1_send_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_pcm_mixer *mix =
&emu->pcm_mixer[snd_ctl_get_ioffidx(kcontrol, &ucontrol->id)];
int change = 0, idx, val;
int num_efx = emu->audigy ? 8 : 4;
spin_lock_irqsave(&emu->reg_lock, flags);
for (idx = 0; idx < 3*num_efx; idx++) {
val = ucontrol->value.integer.value[idx] & 255;
if (mix->send_volume[idx/num_efx][idx%num_efx] != val) {
mix->send_volume[idx/num_efx][idx%num_efx] = val;
change = 1;
}
}
if (change && mix->epcm) {
if (mix->epcm->voices[0] && mix->epcm->voices[1]) {
update_emu10k1_send_volume(emu, mix->epcm->voices[0]->number,
&mix->send_volume[1][0]);
update_emu10k1_send_volume(emu, mix->epcm->voices[1]->number,
&mix->send_volume[2][0]);
} else if (mix->epcm->voices[0]) {
update_emu10k1_send_volume(emu, mix->epcm->voices[0]->number,
&mix->send_volume[0][0]);
}
}
spin_unlock_irqrestore(&emu->reg_lock, flags);
return change;
}
static int snd_emu10k1_attn_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 3;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0xffff;
return 0;
}
static int snd_emu10k1_attn_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_pcm_mixer *mix =
&emu->pcm_mixer[snd_ctl_get_ioffidx(kcontrol, &ucontrol->id)];
unsigned long flags;
int idx;
spin_lock_irqsave(&emu->reg_lock, flags);
for (idx = 0; idx < 3; idx++)
ucontrol->value.integer.value[idx] = mix->attn[idx];
spin_unlock_irqrestore(&emu->reg_lock, flags);
return 0;
}
static int snd_emu10k1_attn_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_pcm_mixer *mix =
&emu->pcm_mixer[snd_ctl_get_ioffidx(kcontrol, &ucontrol->id)];
int change = 0, idx, val;
spin_lock_irqsave(&emu->reg_lock, flags);
for (idx = 0; idx < 3; idx++) {
val = ucontrol->value.integer.value[idx] & 0xffff;
if (mix->attn[idx] != val) {
mix->attn[idx] = val;
change = 1;
}
}
if (change && mix->epcm) {
if (mix->epcm->voices[0] && mix->epcm->voices[1]) {
snd_emu10k1_ptr_write(emu, VTFT_VOLUMETARGET, mix->epcm->voices[0]->number, mix->attn[1]);
snd_emu10k1_ptr_write(emu, VTFT_VOLUMETARGET, mix->epcm->voices[1]->number, mix->attn[2]);
} else if (mix->epcm->voices[0]) {
snd_emu10k1_ptr_write(emu, VTFT_VOLUMETARGET, mix->epcm->voices[0]->number, mix->attn[0]);
}
}
spin_unlock_irqrestore(&emu->reg_lock, flags);
return change;
}
static int snd_emu10k1_efx_send_routing_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = emu->audigy ? 8 : 4;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = emu->audigy ? 0x3f : 0x0f;
return 0;
}
static int snd_emu10k1_efx_send_routing_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_pcm_mixer *mix =
&emu->efx_pcm_mixer[snd_ctl_get_ioffidx(kcontrol, &ucontrol->id)];
int idx;
int num_efx = emu->audigy ? 8 : 4;
int mask = emu->audigy ? 0x3f : 0x0f;
spin_lock_irqsave(&emu->reg_lock, flags);
for (idx = 0; idx < num_efx; idx++)
ucontrol->value.integer.value[idx] =
mix->send_routing[0][idx] & mask;
spin_unlock_irqrestore(&emu->reg_lock, flags);
return 0;
}
static int snd_emu10k1_efx_send_routing_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
int ch = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
struct snd_emu10k1_pcm_mixer *mix = &emu->efx_pcm_mixer[ch];
int change = 0, idx, val;
int num_efx = emu->audigy ? 8 : 4;
int mask = emu->audigy ? 0x3f : 0x0f;
spin_lock_irqsave(&emu->reg_lock, flags);
for (idx = 0; idx < num_efx; idx++) {
val = ucontrol->value.integer.value[idx] & mask;
if (mix->send_routing[0][idx] != val) {
mix->send_routing[0][idx] = val;
change = 1;
}
}
if (change && mix->epcm) {
if (mix->epcm->voices[ch]) {
update_emu10k1_fxrt(emu, mix->epcm->voices[ch]->number,
&mix->send_routing[0][0]);
}
}
spin_unlock_irqrestore(&emu->reg_lock, flags);
return change;
}
static int snd_emu10k1_efx_send_volume_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = emu->audigy ? 8 : 4;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 255;
return 0;
}
static int snd_emu10k1_efx_send_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_pcm_mixer *mix =
&emu->efx_pcm_mixer[snd_ctl_get_ioffidx(kcontrol, &ucontrol->id)];
int idx;
int num_efx = emu->audigy ? 8 : 4;
spin_lock_irqsave(&emu->reg_lock, flags);
for (idx = 0; idx < num_efx; idx++)
ucontrol->value.integer.value[idx] = mix->send_volume[0][idx];
spin_unlock_irqrestore(&emu->reg_lock, flags);
return 0;
}
static int snd_emu10k1_efx_send_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
int ch = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
struct snd_emu10k1_pcm_mixer *mix = &emu->efx_pcm_mixer[ch];
int change = 0, idx, val;
int num_efx = emu->audigy ? 8 : 4;
spin_lock_irqsave(&emu->reg_lock, flags);
for (idx = 0; idx < num_efx; idx++) {
val = ucontrol->value.integer.value[idx] & 255;
if (mix->send_volume[0][idx] != val) {
mix->send_volume[0][idx] = val;
change = 1;
}
}
if (change && mix->epcm) {
if (mix->epcm->voices[ch]) {
update_emu10k1_send_volume(emu, mix->epcm->voices[ch]->number,
&mix->send_volume[0][0]);
}
}
spin_unlock_irqrestore(&emu->reg_lock, flags);
return change;
}
static int snd_emu10k1_efx_attn_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0xffff;
return 0;
}
static int snd_emu10k1_efx_attn_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_pcm_mixer *mix =
&emu->efx_pcm_mixer[snd_ctl_get_ioffidx(kcontrol, &ucontrol->id)];
unsigned long flags;
spin_lock_irqsave(&emu->reg_lock, flags);
ucontrol->value.integer.value[0] = mix->attn[0];
spin_unlock_irqrestore(&emu->reg_lock, flags);
return 0;
}
static int snd_emu10k1_efx_attn_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
int ch = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
struct snd_emu10k1_pcm_mixer *mix = &emu->efx_pcm_mixer[ch];
int change = 0, val;
spin_lock_irqsave(&emu->reg_lock, flags);
val = ucontrol->value.integer.value[0] & 0xffff;
if (mix->attn[0] != val) {
mix->attn[0] = val;
change = 1;
}
if (change && mix->epcm) {
if (mix->epcm->voices[ch]) {
snd_emu10k1_ptr_write(emu, VTFT_VOLUMETARGET, mix->epcm->voices[ch]->number, mix->attn[0]);
}
}
spin_unlock_irqrestore(&emu->reg_lock, flags);
return change;
}
static int snd_emu10k1_shared_spdif_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
if (emu->audigy)
ucontrol->value.integer.value[0] = inl(emu->port + A_IOCFG) & A_IOCFG_GPOUT0 ? 1 : 0;
else
ucontrol->value.integer.value[0] = inl(emu->port + HCFG) & HCFG_GPOUT0 ? 1 : 0;
if (emu->card_capabilities->invert_shared_spdif)
ucontrol->value.integer.value[0] =
!ucontrol->value.integer.value[0];
return 0;
}
static int snd_emu10k1_shared_spdif_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned long flags;
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int reg, val, sw;
int change = 0;
sw = ucontrol->value.integer.value[0];
if (emu->card_capabilities->invert_shared_spdif)
sw = !sw;
spin_lock_irqsave(&emu->reg_lock, flags);
if ( emu->card_capabilities->i2c_adc) {
} else if (emu->audigy) {
reg = inl(emu->port + A_IOCFG);
val = sw ? A_IOCFG_GPOUT0 : 0;
change = (reg & A_IOCFG_GPOUT0) != val;
if (change) {
reg &= ~A_IOCFG_GPOUT0;
reg |= val;
outl(reg | val, emu->port + A_IOCFG);
}
}
reg = inl(emu->port + HCFG);
val = sw ? HCFG_GPOUT0 : 0;
change |= (reg & HCFG_GPOUT0) != val;
if (change) {
reg &= ~HCFG_GPOUT0;
reg |= val;
outl(reg | val, emu->port + HCFG);
}
spin_unlock_irqrestore(&emu->reg_lock, flags);
return change;
}
static int snd_audigy_capture_boost_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
val = snd_ac97_read(emu->ac97, AC97_REC_GAIN);
ucontrol->value.integer.value[0] = !!val;
return 0;
}
static int snd_audigy_capture_boost_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
if (ucontrol->value.integer.value[0])
val = 0x0f0f;
else
val = 0;
return snd_ac97_update(emu->ac97, AC97_REC_GAIN, val);
}
static void snd_emu10k1_mixer_free_ac97(struct snd_ac97 *ac97)
{
struct snd_emu10k1 *emu = ac97->private_data;
emu->ac97 = NULL;
}
static int remove_ctl(struct snd_card *card, const char *name)
{
struct snd_ctl_elem_id id;
memset(&id, 0, sizeof(id));
strcpy(id.name, name);
id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
return snd_ctl_remove_id(card, &id);
}
static struct snd_kcontrol *ctl_find(struct snd_card *card, const char *name)
{
struct snd_ctl_elem_id sid;
memset(&sid, 0, sizeof(sid));
strcpy(sid.name, name);
sid.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
return snd_ctl_find_id(card, &sid);
}
static int rename_ctl(struct snd_card *card, const char *src, const char *dst)
{
struct snd_kcontrol *kctl = ctl_find(card, src);
if (kctl) {
strcpy(kctl->id.name, dst);
return 0;
}
return -ENOENT;
}
int snd_emu10k1_mixer(struct snd_emu10k1 *emu,
int pcm_device, int multi_device)
{
int err, pcm;
struct snd_kcontrol *kctl;
struct snd_card *card = emu->card;
char **c;
static char *emu10k1_remove_ctls[] = {
"Master Mono Playback Switch",
"Master Mono Playback Volume",
"PCM Out Path & Mute",
"Mono Output Select",
"Surround Playback Switch",
"Surround Playback Volume",
"Center Playback Switch",
"Center Playback Volume",
"LFE Playback Switch",
"LFE Playback Volume",
NULL
};
static char *emu10k1_rename_ctls[] = {
"Surround Digital Playback Volume", "Surround Playback Volume",
"Center Digital Playback Volume", "Center Playback Volume",
"LFE Digital Playback Volume", "LFE Playback Volume",
NULL
};
static char *audigy_remove_ctls[] = {
"PCM Playback Switch",
"PCM Playback Volume",
"Master Playback Switch",
"Master Playback Volume",
"PCM Out Path & Mute",
"Mono Output Select",
"Capture Source",
"Capture Switch",
"Capture Volume",
"Mic Select",
"Headphone Playback Switch",
"Headphone Playback Volume",
"3D Control - Center",
"3D Control - Depth",
"3D Control - Switch",
"Video Playback Switch",
"Video Playback Volume",
"Mic Playback Switch",
"Mic Playback Volume",
"External Amplifier",
NULL
};
static char *audigy_rename_ctls[] = {
"Wave Playback Volume", "PCM Playback Volume",
"Wave Master Playback Volume", "Master Playback Volume",
"AMic Playback Volume", "Mic Playback Volume",
"Master Mono Playback Switch", "Phone Output Playback Switch",
"Master Mono Playback Volume", "Phone Output Playback Volume",
NULL
};
static char *audigy_rename_ctls_i2c_adc[] = {
"Line Capture Volume", "Analog Mix Capture Volume",
"Wave Playback Volume", "OLD PCM Playback Volume",
"Wave Master Playback Volume", "Master Playback Volume",
"AMic Playback Volume", "Old Mic Playback Volume",
"CD Capture Volume", "IEC958 Optical Capture Volume",
NULL
};
static char *audigy_remove_ctls_i2c_adc[] = {
"Mic Capture Volume",
"Analog Mix Capture Volume",
"Aux Capture Volume",
"IEC958 Optical Capture Volume",
NULL
};
static char *audigy_remove_ctls_1361t_adc[] = {
"PCM Playback Switch",
"PCM Playback Volume",
"Capture Source",
"Capture Switch",
"Capture Volume",
"Mic Capture Volume",
"Headphone Playback Switch",
"Headphone Playback Volume",
"3D Control - Center",
"3D Control - Depth",
"3D Control - Switch",
"Line2 Playback Volume",
"Line2 Capture Volume",
NULL
};
static char *audigy_rename_ctls_1361t_adc[] = {
"Master Playback Switch", "Master Capture Switch",
"Master Playback Volume", "Master Capture Volume",
"Wave Master Playback Volume", "Master Playback Volume",
"Beep Playback Switch", "Beep Capture Switch",
"Beep Playback Volume", "Beep Capture Volume",
"Phone Playback Switch", "Phone Capture Switch",
"Phone Playback Volume", "Phone Capture Volume",
"Mic Playback Switch", "Mic Capture Switch",
"Mic Playback Volume", "Mic Capture Volume",
"Line Playback Switch", "Line Capture Switch",
"Line Playback Volume", "Line Capture Volume",
"CD Playback Switch", "CD Capture Switch",
"CD Playback Volume", "CD Capture Volume",
"Aux Playback Switch", "Aux Capture Switch",
"Aux Playback Volume", "Aux Capture Volume",
"Video Playback Switch", "Video Capture Switch",
"Video Playback Volume", "Video Capture Volume",
"Master Mono Playback Switch", "Phone Output Playback Switch",
"Master Mono Playback Volume", "Phone Output Playback Volume",
NULL
};
if (emu->card_capabilities->ac97_chip) {
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
static struct snd_ac97_bus_ops ops = {
.write = snd_emu10k1_ac97_write,
.read = snd_emu10k1_ac97_read,
};
if ((err = snd_ac97_bus(emu->card, 0, &ops, NULL, &pbus)) < 0)
return err;
pbus->no_vra = 1;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = emu;
ac97.private_free = snd_emu10k1_mixer_free_ac97;
ac97.scaps = AC97_SCAP_NO_SPDIF;
if ((err = snd_ac97_mixer(pbus, &ac97, &emu->ac97)) < 0) {
if (emu->card_capabilities->ac97_chip == 1)
return err;
dev_info(emu->card->dev,
"AC97 is optional on this board\n");
dev_info(emu->card->dev,
"Proceeding without ac97 mixers...\n");
snd_device_free(emu->card, pbus);
goto no_ac97;
}
if (emu->audigy) {
snd_ac97_write_cache(emu->ac97, AC97_MASTER, 0x0000);
snd_ac97_write_cache(emu->ac97, AC97_REC_SEL, 0x0000);
snd_ac97_update_bits(emu->ac97, AC97_GENERAL_PURPOSE,
0x0200, 0x0200);
if (emu->card_capabilities->adc_1361t)
c = audigy_remove_ctls_1361t_adc;
else
c = audigy_remove_ctls;
} else {
if (emu->ac97->id == AC97_ID_STAC9758) {
emu->rear_ac97 = 1;
snd_emu10k1_ptr_write(emu, AC97SLOT, 0, AC97SLOT_CNTR|AC97SLOT_LFE|AC97SLOT_REAR_LEFT|AC97SLOT_REAR_RIGHT);
snd_ac97_write_cache(emu->ac97, AC97_HEADPHONE, 0x0202);
remove_ctl(card,"Front Playback Volume");
remove_ctl(card,"Front Playback Switch");
}
snd_ac97_write_cache(emu->ac97, AC97_SURROUND_MASTER, 0x0202);
snd_ac97_write_cache(emu->ac97, AC97_CENTER_LFE_MASTER, 0x0202);
c = emu10k1_remove_ctls;
}
for (; *c; c++)
remove_ctl(card, *c);
} else if (emu->card_capabilities->i2c_adc) {
c = audigy_remove_ctls_i2c_adc;
for (; *c; c++)
remove_ctl(card, *c);
} else {
no_ac97:
if (emu->card_capabilities->ecard)
strcpy(emu->card->mixername, "EMU APS");
else if (emu->audigy)
strcpy(emu->card->mixername, "SB Audigy");
else
strcpy(emu->card->mixername, "Emu10k1");
}
if (emu->audigy)
if (emu->card_capabilities->adc_1361t)
c = audigy_rename_ctls_1361t_adc;
else if (emu->card_capabilities->i2c_adc)
c = audigy_rename_ctls_i2c_adc;
else
c = audigy_rename_ctls;
else
c = emu10k1_rename_ctls;
for (; *c; c += 2)
rename_ctl(card, c[0], c[1]);
if (emu->card_capabilities->subsystem == 0x80401102) {
remove_ctl(card, "Center Playback Volume");
remove_ctl(card, "LFE Playback Volume");
remove_ctl(card, "Wave Center Playback Volume");
remove_ctl(card, "Wave LFE Playback Volume");
}
if (emu->card_capabilities->subsystem == 0x20071102) {
rename_ctl(card, "Line2 Capture Volume", "Line1/Mic Capture Volume");
rename_ctl(card, "Analog Mix Capture Volume", "Line2 Capture Volume");
rename_ctl(card, "Aux2 Capture Volume", "Line3 Capture Volume");
rename_ctl(card, "Mic Capture Volume", "Unknown1 Capture Volume");
}
if ((kctl = emu->ctl_send_routing = snd_ctl_new1(&snd_emu10k1_send_routing_control, emu)) == NULL)
return -ENOMEM;
kctl->id.device = pcm_device;
if ((err = snd_ctl_add(card, kctl)))
return err;
if ((kctl = emu->ctl_send_volume = snd_ctl_new1(&snd_emu10k1_send_volume_control, emu)) == NULL)
return -ENOMEM;
kctl->id.device = pcm_device;
if ((err = snd_ctl_add(card, kctl)))
return err;
if ((kctl = emu->ctl_attn = snd_ctl_new1(&snd_emu10k1_attn_control, emu)) == NULL)
return -ENOMEM;
kctl->id.device = pcm_device;
if ((err = snd_ctl_add(card, kctl)))
return err;
if ((kctl = emu->ctl_efx_send_routing = snd_ctl_new1(&snd_emu10k1_efx_send_routing_control, emu)) == NULL)
return -ENOMEM;
kctl->id.device = multi_device;
if ((err = snd_ctl_add(card, kctl)))
return err;
if ((kctl = emu->ctl_efx_send_volume = snd_ctl_new1(&snd_emu10k1_efx_send_volume_control, emu)) == NULL)
return -ENOMEM;
kctl->id.device = multi_device;
if ((err = snd_ctl_add(card, kctl)))
return err;
if ((kctl = emu->ctl_efx_attn = snd_ctl_new1(&snd_emu10k1_efx_attn_control, emu)) == NULL)
return -ENOMEM;
kctl->id.device = multi_device;
if ((err = snd_ctl_add(card, kctl)))
return err;
for (pcm = 0; pcm < 32; pcm++) {
struct snd_emu10k1_pcm_mixer *mix;
int v;
mix = &emu->pcm_mixer[pcm];
mix->epcm = NULL;
for (v = 0; v < 4; v++)
mix->send_routing[0][v] =
mix->send_routing[1][v] =
mix->send_routing[2][v] = v;
memset(&mix->send_volume, 0, sizeof(mix->send_volume));
mix->send_volume[0][0] = mix->send_volume[0][1] =
mix->send_volume[1][0] = mix->send_volume[2][1] = 255;
mix->attn[0] = mix->attn[1] = mix->attn[2] = 0xffff;
}
for (pcm = 0; pcm < NUM_EFX_PLAYBACK; pcm++) {
struct snd_emu10k1_pcm_mixer *mix;
int v;
mix = &emu->efx_pcm_mixer[pcm];
mix->epcm = NULL;
mix->send_routing[0][0] = pcm;
mix->send_routing[0][1] = (pcm == 0) ? 1 : 0;
for (v = 0; v < 2; v++)
mix->send_routing[0][2+v] = 13+v;
if (emu->audigy)
for (v = 0; v < 4; v++)
mix->send_routing[0][4+v] = 60+v;
memset(&mix->send_volume, 0, sizeof(mix->send_volume));
mix->send_volume[0][0] = 255;
mix->attn[0] = 0xffff;
}
if (! emu->card_capabilities->ecard) {
if ((kctl = snd_ctl_new1(&snd_emu10k1_spdif_mask_control, emu)) == NULL)
return -ENOMEM;
if (!emu->audigy)
kctl->id.device = emu->pcm_efx->device;
if ((err = snd_ctl_add(card, kctl)))
return err;
if ((kctl = snd_ctl_new1(&snd_emu10k1_spdif_control, emu)) == NULL)
return -ENOMEM;
if (!emu->audigy)
kctl->id.device = emu->pcm_efx->device;
if ((err = snd_ctl_add(card, kctl)))
return err;
}
if (emu->card_capabilities->emu_model) {
;
} else if (emu->audigy) {
if ((kctl = snd_ctl_new1(&snd_audigy_shared_spdif, emu)) == NULL)
return -ENOMEM;
if ((err = snd_ctl_add(card, kctl)))
return err;
#if 0
if ((kctl = snd_ctl_new1(&snd_audigy_spdif_output_rate, emu)) == NULL)
return -ENOMEM;
if ((err = snd_ctl_add(card, kctl)))
return err;
#endif
} else if (! emu->card_capabilities->ecard) {
if ((kctl = snd_ctl_new1(&snd_emu10k1_shared_spdif, emu)) == NULL)
return -ENOMEM;
if ((err = snd_ctl_add(card, kctl)))
return err;
}
if (emu->card_capabilities->ca0151_chip) {
if ((err = snd_p16v_mixer(emu)))
return err;
}
if (emu->card_capabilities->emu_model == EMU_MODEL_EMU1616) {
int i;
for (i = 0; i < ARRAY_SIZE(snd_emu1616_output_enum_ctls); i++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1616_output_enum_ctls[i],
emu));
if (err < 0)
return err;
}
for (i = 0; i < ARRAY_SIZE(snd_emu1010_input_enum_ctls); i++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_input_enum_ctls[i],
emu));
if (err < 0)
return err;
}
for (i = 0; i < ARRAY_SIZE(snd_emu1010_adc_pads) - 2; i++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_adc_pads[i], emu));
if (err < 0)
return err;
}
for (i = 0; i < ARRAY_SIZE(snd_emu1010_dac_pads) - 2; i++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_dac_pads[i], emu));
if (err < 0)
return err;
}
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_internal_clock, emu));
if (err < 0)
return err;
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_optical_out, emu));
if (err < 0)
return err;
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_optical_in, emu));
if (err < 0)
return err;
} else if (emu->card_capabilities->emu_model) {
int i;
for (i = 0; i < ARRAY_SIZE(snd_emu1010_output_enum_ctls); i++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_output_enum_ctls[i],
emu));
if (err < 0)
return err;
}
for (i = 0; i < ARRAY_SIZE(snd_emu1010_input_enum_ctls); i++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_input_enum_ctls[i],
emu));
if (err < 0)
return err;
}
for (i = 0; i < ARRAY_SIZE(snd_emu1010_adc_pads); i++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_adc_pads[i], emu));
if (err < 0)
return err;
}
for (i = 0; i < ARRAY_SIZE(snd_emu1010_dac_pads); i++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_dac_pads[i], emu));
if (err < 0)
return err;
}
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_internal_clock, emu));
if (err < 0)
return err;
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_optical_out, emu));
if (err < 0)
return err;
err = snd_ctl_add(card,
snd_ctl_new1(&snd_emu1010_optical_in, emu));
if (err < 0)
return err;
}
if ( emu->card_capabilities->i2c_adc) {
int i;
err = snd_ctl_add(card, snd_ctl_new1(&snd_audigy_i2c_capture_source, emu));
if (err < 0)
return err;
for (i = 0; i < ARRAY_SIZE(snd_audigy_i2c_volume_ctls); i++) {
err = snd_ctl_add(card, snd_ctl_new1(&snd_audigy_i2c_volume_ctls[i], emu));
if (err < 0)
return err;
}
}
if (emu->card_capabilities->ac97_chip && emu->audigy) {
err = snd_ctl_add(card, snd_ctl_new1(&snd_audigy_capture_boost,
emu));
if (err < 0)
return err;
}
return 0;
}
