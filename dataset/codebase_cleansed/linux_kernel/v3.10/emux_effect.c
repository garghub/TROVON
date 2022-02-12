static void
effect_set_byte(unsigned char *valp, struct snd_midi_channel *chan, int type)
{
short effect;
struct snd_emux_effect_table *fx = chan->private;
effect = fx->val[type];
if (fx->flag[type] == EMUX_FX_FLAG_ADD) {
if (parm_defs[type].type & PARM_IS_SIGNED)
effect += *(char*)valp;
else
effect += *valp;
}
if (effect < parm_defs[type].low)
effect = parm_defs[type].low;
else if (effect > parm_defs[type].high)
effect = parm_defs[type].high;
*valp = (unsigned char)effect;
}
static void
effect_set_word(unsigned short *valp, struct snd_midi_channel *chan, int type)
{
int effect;
struct snd_emux_effect_table *fx = chan->private;
effect = *(unsigned short*)&fx->val[type];
if (fx->flag[type] == EMUX_FX_FLAG_ADD)
effect += *valp;
if (effect < parm_defs[type].low)
effect = parm_defs[type].low;
else if (effect > parm_defs[type].high)
effect = parm_defs[type].high;
*valp = (unsigned short)effect;
}
static int
effect_get_offset(struct snd_midi_channel *chan, int lo, int hi, int mode)
{
int addr = 0;
struct snd_emux_effect_table *fx = chan->private;
if (fx->flag[hi])
addr = (short)fx->val[hi];
addr = addr << 15;
if (fx->flag[lo])
addr += (short)fx->val[lo];
if (!(mode & SNDRV_SFNT_SAMPLE_8BITS))
addr /= 2;
return addr;
}
void
snd_emux_send_effect_oss(struct snd_emux_port *port,
struct snd_midi_channel *chan, int type, int val)
{
int mode;
if (type & 0x40)
mode = EMUX_FX_FLAG_OFF;
else if (type & 0x80)
mode = EMUX_FX_FLAG_ADD;
else
mode = EMUX_FX_FLAG_SET;
type &= 0x3f;
snd_emux_send_effect(port, chan, type, val, mode);
}
void
snd_emux_send_effect(struct snd_emux_port *port, struct snd_midi_channel *chan,
int type, int val, int mode)
{
int i;
int offset;
unsigned char *srcp, *origp;
struct snd_emux *emu;
struct snd_emux_effect_table *fx;
unsigned long flags;
emu = port->emu;
fx = chan->private;
if (emu == NULL || fx == NULL)
return;
if (type < 0 || type >= EMUX_NUM_EFFECTS)
return;
fx->val[type] = val;
fx->flag[type] = mode;
if (! parm_defs[type].update || (offset = parm_defs[type].offset) < 0)
return;
#ifdef SNDRV_LITTLE_ENDIAN
if (parm_defs[type].type & PARM_IS_ALIGN_HI)
offset++;
#else
if (parm_defs[type].type & PARM_IS_ALIGN_LO)
offset++;
#endif
spin_lock_irqsave(&emu->voice_lock, flags);
for (i = 0; i < emu->max_voices; i++) {
struct snd_emux_voice *vp = &emu->voices[i];
if (!STATE_IS_PLAYING(vp->state) || vp->chan != chan)
continue;
srcp = (unsigned char*)&vp->reg.parm + offset;
origp = (unsigned char*)&vp->zone->v.parm + offset;
if (parm_defs[i].type & PARM_IS_BYTE) {
*srcp = *origp;
effect_set_byte(srcp, chan, type);
} else {
*(unsigned short*)srcp = *(unsigned short*)origp;
effect_set_word((unsigned short*)srcp, chan, type);
}
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
snd_emux_update_channel(port, chan, parm_defs[type].update);
}
void
snd_emux_setup_effect(struct snd_emux_voice *vp)
{
struct snd_midi_channel *chan = vp->chan;
struct snd_emux_effect_table *fx;
unsigned char *srcp;
int i;
if (! (fx = chan->private))
return;
for (i = 0; i < EMUX_FX_END; i++) {
int offset;
if (! fx->flag[i] || (offset = parm_defs[i].offset) < 0)
continue;
#ifdef SNDRV_LITTLE_ENDIAN
if (parm_defs[i].type & PARM_IS_ALIGN_HI)
offset++;
#else
if (parm_defs[i].type & PARM_IS_ALIGN_LO)
offset++;
#endif
srcp = (unsigned char*)&vp->reg.parm + offset;
if (parm_defs[i].type & PARM_IS_BYTE)
effect_set_byte(srcp, chan, i);
else
effect_set_word((unsigned short*)srcp, chan, i);
}
vp->reg.start += effect_get_offset(chan, EMUX_FX_SAMPLE_START,
EMUX_FX_COARSE_SAMPLE_START,
vp->reg.sample_mode);
vp->reg.loopstart += effect_get_offset(chan, EMUX_FX_LOOP_START,
EMUX_FX_COARSE_LOOP_START,
vp->reg.sample_mode);
vp->reg.loopend += effect_get_offset(chan, EMUX_FX_LOOP_END,
EMUX_FX_COARSE_LOOP_END,
vp->reg.sample_mode);
}
void
snd_emux_create_effect(struct snd_emux_port *p)
{
int i;
p->effect = kcalloc(p->chset.max_channels,
sizeof(struct snd_emux_effect_table), GFP_KERNEL);
if (p->effect) {
for (i = 0; i < p->chset.max_channels; i++)
p->chset.channels[i].private = p->effect + i;
} else {
for (i = 0; i < p->chset.max_channels; i++)
p->chset.channels[i].private = NULL;
}
}
void
snd_emux_delete_effect(struct snd_emux_port *p)
{
kfree(p->effect);
p->effect = NULL;
}
void
snd_emux_clear_effect(struct snd_emux_port *p)
{
if (p->effect) {
memset(p->effect, 0, sizeof(struct snd_emux_effect_table) *
p->chset.max_channels);
}
}
