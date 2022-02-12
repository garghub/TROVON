void snd_emu8000_poke(struct snd_emu8000 *emu, unsigned int port, unsigned int reg, unsigned int val)
{
unsigned long flags;
spin_lock_irqsave(&emu->reg_lock, flags);
if (reg != emu->last_reg) {
outw((unsigned short)reg, EMU8000_PTR(emu));
emu->last_reg = reg;
}
outw((unsigned short)val, port);
spin_unlock_irqrestore(&emu->reg_lock, flags);
}
unsigned short snd_emu8000_peek(struct snd_emu8000 *emu, unsigned int port, unsigned int reg)
{
unsigned short res;
unsigned long flags;
spin_lock_irqsave(&emu->reg_lock, flags);
if (reg != emu->last_reg) {
outw((unsigned short)reg, EMU8000_PTR(emu));
emu->last_reg = reg;
}
res = inw(port);
spin_unlock_irqrestore(&emu->reg_lock, flags);
return res;
}
void snd_emu8000_poke_dw(struct snd_emu8000 *emu, unsigned int port, unsigned int reg, unsigned int val)
{
unsigned long flags;
spin_lock_irqsave(&emu->reg_lock, flags);
if (reg != emu->last_reg) {
outw((unsigned short)reg, EMU8000_PTR(emu));
emu->last_reg = reg;
}
outw((unsigned short)val, port);
outw((unsigned short)(val>>16), port+2);
spin_unlock_irqrestore(&emu->reg_lock, flags);
}
unsigned int snd_emu8000_peek_dw(struct snd_emu8000 *emu, unsigned int port, unsigned int reg)
{
unsigned short low;
unsigned int res;
unsigned long flags;
spin_lock_irqsave(&emu->reg_lock, flags);
if (reg != emu->last_reg) {
outw((unsigned short)reg, EMU8000_PTR(emu));
emu->last_reg = reg;
}
low = inw(port);
res = low + (inw(port+2) << 16);
spin_unlock_irqrestore(&emu->reg_lock, flags);
return res;
}
void
snd_emu8000_dma_chan(struct snd_emu8000 *emu, int ch, int mode)
{
unsigned right_bit = (mode & EMU8000_RAM_RIGHT) ? 0x01000000 : 0;
mode &= EMU8000_RAM_MODE_MASK;
if (mode == EMU8000_RAM_CLOSE) {
EMU8000_CCCA_WRITE(emu, ch, 0);
EMU8000_DCYSUSV_WRITE(emu, ch, 0x807F);
return;
}
EMU8000_DCYSUSV_WRITE(emu, ch, 0x80);
EMU8000_VTFT_WRITE(emu, ch, 0);
EMU8000_CVCF_WRITE(emu, ch, 0);
EMU8000_PTRX_WRITE(emu, ch, 0x40000000);
EMU8000_CPF_WRITE(emu, ch, 0x40000000);
EMU8000_PSST_WRITE(emu, ch, 0);
EMU8000_CSL_WRITE(emu, ch, 0);
if (mode == EMU8000_RAM_WRITE)
EMU8000_CCCA_WRITE(emu, ch, 0x06000000 | right_bit);
else
EMU8000_CCCA_WRITE(emu, ch, 0x04000000 | right_bit);
}
static void
snd_emu8000_read_wait(struct snd_emu8000 *emu)
{
while ((EMU8000_SMALR_READ(emu) & 0x80000000) != 0) {
schedule_timeout_interruptible(1);
if (signal_pending(current))
break;
}
}
static void
snd_emu8000_write_wait(struct snd_emu8000 *emu)
{
while ((EMU8000_SMALW_READ(emu) & 0x80000000) != 0) {
schedule_timeout_interruptible(1);
if (signal_pending(current))
break;
}
}
static int
snd_emu8000_detect(struct snd_emu8000 *emu)
{
EMU8000_HWCF1_WRITE(emu, 0x0059);
EMU8000_HWCF2_WRITE(emu, 0x0020);
EMU8000_HWCF3_WRITE(emu, 0x0000);
if ((EMU8000_HWCF1_READ(emu) & 0x007e) != 0x0058)
return -ENODEV;
if ((EMU8000_HWCF2_READ(emu) & 0x0003) != 0x0003)
return -ENODEV;
snd_printdd("EMU8000 [0x%lx]: Synth chip found\n",
emu->port1);
return 0;
}
static void
init_audio(struct snd_emu8000 *emu)
{
int ch;
for (ch = 0; ch < EMU8000_CHANNELS; ch++)
EMU8000_DCYSUSV_WRITE(emu, ch, 0x80);
for (ch = 0; ch < EMU8000_CHANNELS; ch++) {
EMU8000_ENVVOL_WRITE(emu, ch, 0);
EMU8000_ENVVAL_WRITE(emu, ch, 0);
EMU8000_DCYSUS_WRITE(emu, ch, 0);
EMU8000_ATKHLDV_WRITE(emu, ch, 0);
EMU8000_LFO1VAL_WRITE(emu, ch, 0);
EMU8000_ATKHLD_WRITE(emu, ch, 0);
EMU8000_LFO2VAL_WRITE(emu, ch, 0);
EMU8000_IP_WRITE(emu, ch, 0);
EMU8000_IFATN_WRITE(emu, ch, 0);
EMU8000_PEFE_WRITE(emu, ch, 0);
EMU8000_FMMOD_WRITE(emu, ch, 0);
EMU8000_TREMFRQ_WRITE(emu, ch, 0);
EMU8000_FM2FRQ2_WRITE(emu, ch, 0);
EMU8000_PTRX_WRITE(emu, ch, 0);
EMU8000_VTFT_WRITE(emu, ch, 0);
EMU8000_PSST_WRITE(emu, ch, 0);
EMU8000_CSL_WRITE(emu, ch, 0);
EMU8000_CCCA_WRITE(emu, ch, 0);
}
for (ch = 0; ch < EMU8000_CHANNELS; ch++) {
EMU8000_CPF_WRITE(emu, ch, 0);
EMU8000_CVCF_WRITE(emu, ch, 0);
}
}
static void
init_dma(struct snd_emu8000 *emu)
{
EMU8000_SMALR_WRITE(emu, 0);
EMU8000_SMARR_WRITE(emu, 0);
EMU8000_SMALW_WRITE(emu, 0);
EMU8000_SMARW_WRITE(emu, 0);
}
static void
send_array(struct snd_emu8000 *emu, unsigned short *data, int size)
{
int i;
unsigned short *p;
p = data;
for (i = 0; i < size; i++, p++)
EMU8000_INIT1_WRITE(emu, i, *p);
for (i = 0; i < size; i++, p++)
EMU8000_INIT2_WRITE(emu, i, *p);
for (i = 0; i < size; i++, p++)
EMU8000_INIT3_WRITE(emu, i, *p);
for (i = 0; i < size; i++, p++)
EMU8000_INIT4_WRITE(emu, i, *p);
}
static void
init_arrays(struct snd_emu8000 *emu)
{
send_array(emu, init1, ARRAY_SIZE(init1)/4);
msleep((1024 * 1000) / 44100);
send_array(emu, init2, ARRAY_SIZE(init2)/4);
send_array(emu, init3, ARRAY_SIZE(init3)/4);
EMU8000_HWCF4_WRITE(emu, 0);
EMU8000_HWCF5_WRITE(emu, 0x83);
EMU8000_HWCF6_WRITE(emu, 0x8000);
send_array(emu, init4, ARRAY_SIZE(init4)/4);
}
static void
size_dram(struct snd_emu8000 *emu)
{
int i, size;
if (emu->dram_checked)
return;
size = 0;
snd_emu8000_dma_chan(emu, 0, EMU8000_RAM_WRITE);
snd_emu8000_dma_chan(emu, 1, EMU8000_RAM_READ);
EMU8000_SMALW_WRITE(emu, EMU8000_DRAM_OFFSET);
EMU8000_SMLD_WRITE(emu, UNIQUE_ID1);
snd_emu8000_init_fm(emu);
snd_emu8000_write_wait(emu);
EMU8000_SMALR_WRITE(emu, EMU8000_DRAM_OFFSET);
EMU8000_SMLD_READ(emu);
if (EMU8000_SMLD_READ(emu) != UNIQUE_ID1)
goto skip_detect;
snd_emu8000_read_wait(emu);
for (size = 512 * 1024; size < EMU8000_MAX_DRAM; size += 512 * 1024) {
EMU8000_SMALW_WRITE(emu, EMU8000_DRAM_OFFSET + (size>>1));
EMU8000_SMLD_WRITE(emu, UNIQUE_ID2);
snd_emu8000_write_wait(emu);
EMU8000_SMALR_WRITE(emu, EMU8000_DRAM_OFFSET + (size>>1));
EMU8000_SMLD_READ(emu);
if (EMU8000_SMLD_READ(emu) != UNIQUE_ID2)
break;
snd_emu8000_read_wait(emu);
EMU8000_SMALR_WRITE(emu, EMU8000_DRAM_OFFSET);
EMU8000_SMLD_READ(emu);
if (EMU8000_SMLD_READ(emu) != UNIQUE_ID1)
break;
snd_emu8000_read_wait(emu);
}
skip_detect:
for (i = 0; i < 10000; i++) {
if ((EMU8000_SMALW_READ(emu) & 0x80000000) == 0)
break;
schedule_timeout_interruptible(1);
if (signal_pending(current))
break;
}
snd_emu8000_dma_chan(emu, 0, EMU8000_RAM_CLOSE);
snd_emu8000_dma_chan(emu, 1, EMU8000_RAM_CLOSE);
pr_info("EMU8000 [0x%lx]: %d KiB on-board DRAM detected\n",
emu->port1, size/1024);
emu->mem_size = size;
emu->dram_checked = 1;
}
void
snd_emu8000_init_fm(struct snd_emu8000 *emu)
{
unsigned long flags;
EMU8000_DCYSUSV_WRITE(emu, 30, 0x80);
EMU8000_PSST_WRITE(emu, 30, 0xFFFFFFE0);
EMU8000_CSL_WRITE(emu, 30, 0x00FFFFE8 | (emu->fm_chorus_depth << 24));
EMU8000_PTRX_WRITE(emu, 30, (emu->fm_reverb_depth << 8));
EMU8000_CPF_WRITE(emu, 30, 0);
EMU8000_CCCA_WRITE(emu, 30, 0x00FFFFE3);
EMU8000_DCYSUSV_WRITE(emu, 31, 0x80);
EMU8000_PSST_WRITE(emu, 31, 0x00FFFFF0);
EMU8000_CSL_WRITE(emu, 31, 0x00FFFFF8 | (emu->fm_chorus_depth << 24));
EMU8000_PTRX_WRITE(emu, 31, (emu->fm_reverb_depth << 8));
EMU8000_CPF_WRITE(emu, 31, 0x8000);
EMU8000_CCCA_WRITE(emu, 31, 0x00FFFFF3);
snd_emu8000_poke((emu), EMU8000_DATA0(emu), EMU8000_CMD(1, (30)), 0);
spin_lock_irqsave(&emu->reg_lock, flags);
while (!(inw(EMU8000_PTR(emu)) & 0x1000))
;
while ((inw(EMU8000_PTR(emu)) & 0x1000))
;
spin_unlock_irqrestore(&emu->reg_lock, flags);
snd_emu8000_poke((emu), EMU8000_DATA0(emu), EMU8000_CMD(1, (30)), 0x4828);
outb(0x3C, EMU8000_PTR(emu));
outb(0, EMU8000_DATA1(emu));
EMU8000_VTFT_WRITE(emu, 30, 0x8000FFFF);
EMU8000_VTFT_WRITE(emu, 31, 0x8000FFFF);
}
static void
snd_emu8000_init_hw(struct snd_emu8000 *emu)
{
int i;
emu->last_reg = 0xffff;
EMU8000_HWCF1_WRITE(emu, 0x0059);
EMU8000_HWCF2_WRITE(emu, 0x0020);
EMU8000_HWCF3_WRITE(emu, 0);
init_audio(emu);
init_dma(emu);
init_arrays(emu);
snd_emu8000_init_fm(emu);
for (i = 0; i < EMU8000_DRAM_VOICES; i++)
EMU8000_DCYSUSV_WRITE(emu, 0, 0x807F);
size_dram(emu);
EMU8000_HWCF3_WRITE(emu, 0x4);
snd_emu8000_update_equalizer(emu);
snd_emu8000_update_chorus_mode(emu);
snd_emu8000_update_reverb_mode(emu);
}
void
snd_emu8000_update_equalizer(struct snd_emu8000 *emu)
{
unsigned short w;
int bass = emu->bass_level;
int treble = emu->treble_level;
if (bass < 0 || bass > 11 || treble < 0 || treble > 11)
return;
EMU8000_INIT4_WRITE(emu, 0x01, bass_parm[bass][0]);
EMU8000_INIT4_WRITE(emu, 0x11, bass_parm[bass][1]);
EMU8000_INIT3_WRITE(emu, 0x11, treble_parm[treble][0]);
EMU8000_INIT3_WRITE(emu, 0x13, treble_parm[treble][1]);
EMU8000_INIT3_WRITE(emu, 0x1b, treble_parm[treble][2]);
EMU8000_INIT4_WRITE(emu, 0x07, treble_parm[treble][3]);
EMU8000_INIT4_WRITE(emu, 0x0b, treble_parm[treble][4]);
EMU8000_INIT4_WRITE(emu, 0x0d, treble_parm[treble][5]);
EMU8000_INIT4_WRITE(emu, 0x17, treble_parm[treble][6]);
EMU8000_INIT4_WRITE(emu, 0x19, treble_parm[treble][7]);
w = bass_parm[bass][2] + treble_parm[treble][8];
EMU8000_INIT4_WRITE(emu, 0x15, (unsigned short)(w + 0x0262));
EMU8000_INIT4_WRITE(emu, 0x1d, (unsigned short)(w + 0x8362));
}
int
snd_emu8000_load_chorus_fx(struct snd_emu8000 *emu, int mode, const void __user *buf, long len)
{
struct soundfont_chorus_fx rec;
if (mode < SNDRV_EMU8000_CHORUS_PREDEFINED || mode >= SNDRV_EMU8000_CHORUS_NUMBERS) {
snd_printk(KERN_WARNING "invalid chorus mode %d for uploading\n", mode);
return -EINVAL;
}
if (len < (long)sizeof(rec) || copy_from_user(&rec, buf, sizeof(rec)))
return -EFAULT;
chorus_parm[mode] = rec;
chorus_defined[mode] = 1;
return 0;
}
void
snd_emu8000_update_chorus_mode(struct snd_emu8000 *emu)
{
int effect = emu->chorus_mode;
if (effect < 0 || effect >= SNDRV_EMU8000_CHORUS_NUMBERS ||
(effect >= SNDRV_EMU8000_CHORUS_PREDEFINED && !chorus_defined[effect]))
return;
EMU8000_INIT3_WRITE(emu, 0x09, chorus_parm[effect].feedback);
EMU8000_INIT3_WRITE(emu, 0x0c, chorus_parm[effect].delay_offset);
EMU8000_INIT4_WRITE(emu, 0x03, chorus_parm[effect].lfo_depth);
EMU8000_HWCF4_WRITE(emu, chorus_parm[effect].delay);
EMU8000_HWCF5_WRITE(emu, chorus_parm[effect].lfo_freq);
EMU8000_HWCF6_WRITE(emu, 0x8000);
EMU8000_HWCF7_WRITE(emu, 0x0000);
}
int
snd_emu8000_load_reverb_fx(struct snd_emu8000 *emu, int mode, const void __user *buf, long len)
{
struct soundfont_reverb_fx rec;
if (mode < SNDRV_EMU8000_REVERB_PREDEFINED || mode >= SNDRV_EMU8000_REVERB_NUMBERS) {
snd_printk(KERN_WARNING "invalid reverb mode %d for uploading\n", mode);
return -EINVAL;
}
if (len < (long)sizeof(rec) || copy_from_user(&rec, buf, sizeof(rec)))
return -EFAULT;
reverb_parm[mode] = rec;
reverb_defined[mode] = 1;
return 0;
}
void
snd_emu8000_update_reverb_mode(struct snd_emu8000 *emu)
{
int effect = emu->reverb_mode;
int i;
if (effect < 0 || effect >= SNDRV_EMU8000_REVERB_NUMBERS ||
(effect >= SNDRV_EMU8000_REVERB_PREDEFINED && !reverb_defined[effect]))
return;
for (i = 0; i < 28; i++) {
int port;
if (reverb_cmds[i].port == DATA1)
port = EMU8000_DATA1(emu);
else
port = EMU8000_DATA2(emu);
snd_emu8000_poke(emu, port, reverb_cmds[i].cmd, reverb_parm[effect].parms[i]);
}
}
static int mixer_bass_treble_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 11;
return 0;
}
static int mixer_bass_treble_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu8000 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = kcontrol->private_value ? emu->treble_level : emu->bass_level;
return 0;
}
static int mixer_bass_treble_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu8000 *emu = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int change;
unsigned short val1;
val1 = ucontrol->value.integer.value[0] % 12;
spin_lock_irqsave(&emu->control_lock, flags);
if (kcontrol->private_value) {
change = val1 != emu->treble_level;
emu->treble_level = val1;
} else {
change = val1 != emu->bass_level;
emu->bass_level = val1;
}
spin_unlock_irqrestore(&emu->control_lock, flags);
snd_emu8000_update_equalizer(emu);
return change;
}
static int mixer_chorus_reverb_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = kcontrol->private_value ? (SNDRV_EMU8000_CHORUS_NUMBERS-1) : (SNDRV_EMU8000_REVERB_NUMBERS-1);
return 0;
}
static int mixer_chorus_reverb_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu8000 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = kcontrol->private_value ? emu->chorus_mode : emu->reverb_mode;
return 0;
}
static int mixer_chorus_reverb_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu8000 *emu = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int change;
unsigned short val1;
spin_lock_irqsave(&emu->control_lock, flags);
if (kcontrol->private_value) {
val1 = ucontrol->value.integer.value[0] % SNDRV_EMU8000_CHORUS_NUMBERS;
change = val1 != emu->chorus_mode;
emu->chorus_mode = val1;
} else {
val1 = ucontrol->value.integer.value[0] % SNDRV_EMU8000_REVERB_NUMBERS;
change = val1 != emu->reverb_mode;
emu->reverb_mode = val1;
}
spin_unlock_irqrestore(&emu->control_lock, flags);
if (change) {
if (kcontrol->private_value)
snd_emu8000_update_chorus_mode(emu);
else
snd_emu8000_update_reverb_mode(emu);
}
return change;
}
static int mixer_fm_depth_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 255;
return 0;
}
static int mixer_fm_depth_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu8000 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = kcontrol->private_value ? emu->fm_chorus_depth : emu->fm_reverb_depth;
return 0;
}
static int mixer_fm_depth_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu8000 *emu = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int change;
unsigned short val1;
val1 = ucontrol->value.integer.value[0] % 256;
spin_lock_irqsave(&emu->control_lock, flags);
if (kcontrol->private_value) {
change = val1 != emu->fm_chorus_depth;
emu->fm_chorus_depth = val1;
} else {
change = val1 != emu->fm_reverb_depth;
emu->fm_reverb_depth = val1;
}
spin_unlock_irqrestore(&emu->control_lock, flags);
if (change)
snd_emu8000_init_fm(emu);
return change;
}
static int
snd_emu8000_create_mixer(struct snd_card *card, struct snd_emu8000 *emu)
{
int i, err = 0;
if (snd_BUG_ON(!emu || !card))
return -EINVAL;
spin_lock_init(&emu->control_lock);
memset(emu->controls, 0, sizeof(emu->controls));
for (i = 0; i < EMU8000_NUM_CONTROLS; i++) {
if ((err = snd_ctl_add(card, emu->controls[i] = snd_ctl_new1(mixer_defs[i], emu))) < 0)
goto __error;
}
return 0;
__error:
for (i = 0; i < EMU8000_NUM_CONTROLS; i++) {
down_write(&card->controls_rwsem);
if (emu->controls[i])
snd_ctl_remove(card, emu->controls[i]);
up_write(&card->controls_rwsem);
}
return err;
}
static int snd_emu8000_free(struct snd_emu8000 *hw)
{
release_and_free_resource(hw->res_port1);
release_and_free_resource(hw->res_port2);
release_and_free_resource(hw->res_port3);
kfree(hw);
return 0;
}
static int snd_emu8000_dev_free(struct snd_device *device)
{
struct snd_emu8000 *hw = device->device_data;
return snd_emu8000_free(hw);
}
int
snd_emu8000_new(struct snd_card *card, int index, long port, int seq_ports,
struct snd_seq_device **awe_ret)
{
struct snd_seq_device *awe;
struct snd_emu8000 *hw;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_emu8000_dev_free,
};
if (awe_ret)
*awe_ret = NULL;
if (seq_ports <= 0)
return 0;
hw = kzalloc(sizeof(*hw), GFP_KERNEL);
if (hw == NULL)
return -ENOMEM;
spin_lock_init(&hw->reg_lock);
hw->index = index;
hw->port1 = port;
hw->port2 = port + 0x400;
hw->port3 = port + 0x800;
if (!(hw->res_port1 = request_region(hw->port1, 4, "Emu8000-1")) ||
!(hw->res_port2 = request_region(hw->port2, 4, "Emu8000-2")) ||
!(hw->res_port3 = request_region(hw->port3, 4, "Emu8000-3"))) {
snd_printk(KERN_ERR "sbawe: can't grab ports 0x%lx, 0x%lx, 0x%lx\n", hw->port1, hw->port2, hw->port3);
snd_emu8000_free(hw);
return -EBUSY;
}
hw->mem_size = 0;
hw->card = card;
hw->seq_ports = seq_ports;
hw->bass_level = 5;
hw->treble_level = 9;
hw->chorus_mode = 2;
hw->reverb_mode = 4;
hw->fm_chorus_depth = 0;
hw->fm_reverb_depth = 0;
if (snd_emu8000_detect(hw) < 0) {
snd_emu8000_free(hw);
return -ENODEV;
}
snd_emu8000_init_hw(hw);
if ((err = snd_emu8000_create_mixer(card, hw)) < 0) {
snd_emu8000_free(hw);
return err;
}
if ((err = snd_device_new(card, SNDRV_DEV_CODEC, hw, &ops)) < 0) {
snd_emu8000_free(hw);
return err;
}
#if IS_ENABLED(CONFIG_SND_SEQUENCER)
if (snd_seq_device_new(card, index, SNDRV_SEQ_DEV_ID_EMU8000,
sizeof(struct snd_emu8000*), &awe) >= 0) {
strcpy(awe->name, "EMU-8000");
*(struct snd_emu8000 **)SNDRV_SEQ_DEVICE_ARGPTR(awe) = hw;
}
#else
awe = NULL;
#endif
if (awe_ret)
*awe_ret = awe;
return 0;
}
