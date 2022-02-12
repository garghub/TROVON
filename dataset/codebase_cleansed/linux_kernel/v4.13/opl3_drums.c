static void snd_opl3_drum_voice_set(struct snd_opl3 *opl3,
struct snd_opl3_drum_voice *data)
{
unsigned char op_offset = snd_opl3_regmap[data->voice][data->op];
unsigned char voice_offset = data->voice;
unsigned short opl3_reg;
opl3_reg = OPL3_LEFT | (OPL3_REG_AM_VIB + op_offset);
opl3->command(opl3, opl3_reg, data->am_vib);
opl3_reg = OPL3_LEFT | (OPL3_REG_KSL_LEVEL + op_offset);
opl3->command(opl3, opl3_reg, data->ksl_level);
opl3_reg = OPL3_LEFT | (OPL3_REG_ATTACK_DECAY + op_offset);
opl3->command(opl3, opl3_reg, data->attack_decay);
opl3_reg = OPL3_LEFT | (OPL3_REG_SUSTAIN_RELEASE + op_offset);
opl3->command(opl3, opl3_reg, data->sustain_release);
opl3_reg = OPL3_LEFT | (OPL3_REG_FEEDBACK_CONNECTION + voice_offset);
opl3->command(opl3, opl3_reg, data->feedback_connection);
opl3_reg = OPL3_LEFT | (OPL3_REG_WAVE_SELECT + op_offset);
opl3->command(opl3, opl3_reg, data->wave_select);
}
static void snd_opl3_drum_note_set(struct snd_opl3 *opl3,
struct snd_opl3_drum_note *data)
{
unsigned char voice_offset = data->voice;
unsigned short opl3_reg;
opl3_reg = OPL3_LEFT | (OPL3_REG_FNUM_LOW + voice_offset);
opl3->command(opl3, opl3_reg, data->fnum);
opl3_reg = OPL3_LEFT | (OPL3_REG_KEYON_BLOCK + voice_offset);
opl3->command(opl3, opl3_reg, data->octave_f);
}
static void snd_opl3_drum_vol_set(struct snd_opl3 *opl3,
struct snd_opl3_drum_voice *data,
int vel, struct snd_midi_channel *chan)
{
unsigned char op_offset = snd_opl3_regmap[data->voice][data->op];
unsigned char voice_offset = data->voice;
unsigned char reg_val;
unsigned short opl3_reg;
reg_val = data->ksl_level;
snd_opl3_calc_volume(&reg_val, vel, chan);
opl3_reg = OPL3_LEFT | (OPL3_REG_KSL_LEVEL + op_offset);
opl3->command(opl3, opl3_reg, reg_val);
reg_val = data->feedback_connection | OPL3_STEREO_BITS;
if (chan->gm_pan < 43)
reg_val &= ~OPL3_VOICE_TO_RIGHT;
if (chan->gm_pan > 85)
reg_val &= ~OPL3_VOICE_TO_LEFT;
opl3_reg = OPL3_LEFT | (OPL3_REG_FEEDBACK_CONNECTION + voice_offset);
opl3->command(opl3, opl3_reg, reg_val);
}
void snd_opl3_load_drums(struct snd_opl3 *opl3)
{
snd_opl3_drum_voice_set(opl3, &bass_op0);
snd_opl3_drum_voice_set(opl3, &bass_op1);
snd_opl3_drum_note_set(opl3, &bass_note);
snd_opl3_drum_voice_set(opl3, &hihat);
snd_opl3_drum_voice_set(opl3, &snare);
snd_opl3_drum_note_set(opl3, &snare_note);
snd_opl3_drum_voice_set(opl3, &tomtom);
snd_opl3_drum_note_set(opl3, &tomtom_note);
snd_opl3_drum_voice_set(opl3, &cymbal);
}
void snd_opl3_drum_switch(struct snd_opl3 *opl3, int note, int vel, int on_off,
struct snd_midi_channel *chan)
{
unsigned char drum_mask;
struct snd_opl3_drum_voice *drum_voice;
if (!(opl3->drum_reg & OPL3_PERCUSSION_ENABLE))
return;
if ((note < 35) || (note > 81))
return;
drum_mask = snd_opl3_drum_table[note - 35];
if (on_off) {
switch (drum_mask) {
case OPL3_BASSDRUM_ON:
drum_voice = &bass_op1;
break;
case OPL3_HIHAT_ON:
drum_voice = &hihat;
break;
case OPL3_SNAREDRUM_ON:
drum_voice = &snare;
break;
case OPL3_TOMTOM_ON:
drum_voice = &tomtom;
break;
case OPL3_CYMBAL_ON:
drum_voice = &cymbal;
break;
default:
drum_voice = &tomtom;
}
snd_opl3_drum_vol_set(opl3, drum_voice, vel, chan);
opl3->drum_reg |= drum_mask;
} else {
opl3->drum_reg &= ~drum_mask;
}
opl3->command(opl3, OPL3_LEFT | OPL3_REG_PERCUSSION,
opl3->drum_reg);
}
