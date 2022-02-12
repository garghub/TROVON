static void snd_cs4236_ctrl_out(struct snd_wss *chip,
unsigned char reg, unsigned char val)
{
outb(reg, chip->cport + 3);
outb(chip->cimage[reg] = val, chip->cport + 4);
}
static unsigned char snd_cs4236_ctrl_in(struct snd_wss *chip, unsigned char reg)
{
outb(reg, chip->cport + 3);
return inb(chip->cport + 4);
}
static int snd_cs4236_xrate(struct snd_pcm_runtime *runtime)
{
return snd_pcm_hw_constraint_ratnums(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_clocks);
}
static unsigned char divisor_to_rate_register(unsigned int divisor)
{
switch (divisor) {
case 353: return 1;
case 529: return 2;
case 617: return 3;
case 1058: return 4;
case 1764: return 5;
case 2117: return 6;
case 2558: return 7;
default:
if (divisor < 21 || divisor > 192) {
snd_BUG();
return 192;
}
return divisor;
}
}
static void snd_cs4236_playback_format(struct snd_wss *chip,
struct snd_pcm_hw_params *params,
unsigned char pdfr)
{
unsigned long flags;
unsigned char rate = divisor_to_rate_register(params->rate_den);
spin_lock_irqsave(&chip->reg_lock, flags);
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1] | 0x10);
snd_wss_out(chip, CS4231_PLAYBK_FORMAT, pdfr & 0xf0);
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1] & ~0x10);
snd_cs4236_ext_out(chip, CS4236_DAC_RATE, rate);
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static void snd_cs4236_capture_format(struct snd_wss *chip,
struct snd_pcm_hw_params *params,
unsigned char cdfr)
{
unsigned long flags;
unsigned char rate = divisor_to_rate_register(params->rate_den);
spin_lock_irqsave(&chip->reg_lock, flags);
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1] | 0x20);
snd_wss_out(chip, CS4231_REC_FORMAT, cdfr & 0xf0);
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1] & ~0x20);
snd_cs4236_ext_out(chip, CS4236_ADC_RATE, rate);
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static void snd_cs4236_suspend(struct snd_wss *chip)
{
int reg;
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
for (reg = 0; reg < 32; reg++)
chip->image[reg] = snd_wss_in(chip, reg);
for (reg = 0; reg < 18; reg++)
chip->eimage[reg] = snd_cs4236_ext_in(chip, CS4236_I23VAL(reg));
for (reg = 2; reg < 9; reg++)
chip->cimage[reg] = snd_cs4236_ctrl_in(chip, reg);
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static void snd_cs4236_resume(struct snd_wss *chip)
{
int reg;
unsigned long flags;
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
for (reg = 0; reg < 32; reg++) {
switch (reg) {
case CS4236_EXT_REG:
case CS4231_VERSION:
case 27:
case 29:
break;
default:
snd_wss_out(chip, reg, chip->image[reg]);
break;
}
}
for (reg = 0; reg < 18; reg++)
snd_cs4236_ext_out(chip, CS4236_I23VAL(reg), chip->eimage[reg]);
for (reg = 2; reg < 9; reg++) {
switch (reg) {
case 7:
break;
default:
snd_cs4236_ctrl_out(chip, reg, chip->cimage[reg]);
}
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
}
int snd_cs4236_create(struct snd_card *card,
unsigned long port,
unsigned long cport,
int irq, int dma1, int dma2,
unsigned short hardware,
unsigned short hwshare,
struct snd_wss **rchip)
{
struct snd_wss *chip;
unsigned char ver1, ver2;
unsigned int reg;
int err;
*rchip = NULL;
if (hardware == WSS_HW_DETECT)
hardware = WSS_HW_DETECT3;
err = snd_wss_create(card, port, cport,
irq, dma1, dma2, hardware, hwshare, &chip);
if (err < 0)
return err;
if ((chip->hardware & WSS_HW_CS4236B_MASK) == 0) {
snd_printd("chip is not CS4236+, hardware=0x%x\n",
chip->hardware);
*rchip = chip;
return 0;
}
#if 0
{
int idx;
for (idx = 0; idx < 8; idx++)
snd_printk(KERN_DEBUG "CD%i = 0x%x\n",
idx, inb(chip->cport + idx));
for (idx = 0; idx < 9; idx++)
snd_printk(KERN_DEBUG "C%i = 0x%x\n",
idx, snd_cs4236_ctrl_in(chip, idx));
}
#endif
if (cport < 0x100 || cport == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR "please, specify control port "
"for CS4236+ chips\n");
snd_device_free(card, chip);
return -ENODEV;
}
ver1 = snd_cs4236_ctrl_in(chip, 1);
ver2 = snd_cs4236_ext_in(chip, CS4236_VERSION);
snd_printdd("CS4236: [0x%lx] C1 (version) = 0x%x, ext = 0x%x\n",
cport, ver1, ver2);
if (ver1 != ver2) {
snd_printk(KERN_ERR "CS4236+ chip detected, but "
"control port 0x%lx is not valid\n", cport);
snd_device_free(card, chip);
return -ENODEV;
}
snd_cs4236_ctrl_out(chip, 0, 0x00);
snd_cs4236_ctrl_out(chip, 2, 0xff);
snd_cs4236_ctrl_out(chip, 3, 0x00);
snd_cs4236_ctrl_out(chip, 4, 0x80);
reg = ((IEC958_AES1_CON_PCM_CODER & 3) << 6) |
IEC958_AES0_CON_EMPHASIS_NONE;
snd_cs4236_ctrl_out(chip, 5, reg);
snd_cs4236_ctrl_out(chip, 6, IEC958_AES1_CON_PCM_CODER >> 2);
snd_cs4236_ctrl_out(chip, 7, 0x00);
snd_cs4236_ctrl_out(chip, 8, 0x8c);
chip->rate_constraint = snd_cs4236_xrate;
chip->set_playback_format = snd_cs4236_playback_format;
chip->set_capture_format = snd_cs4236_capture_format;
#ifdef CONFIG_PM
chip->suspend = snd_cs4236_suspend;
chip->resume = snd_cs4236_resume;
#endif
for (reg = 0; reg < sizeof(snd_cs4236_ext_map); reg++)
snd_cs4236_ext_out(chip, CS4236_I23VAL(reg),
snd_cs4236_ext_map[reg]);
snd_wss_out(chip, CS4231_LEFT_INPUT, 0x40);
snd_wss_out(chip, CS4231_RIGHT_INPUT, 0x40);
snd_wss_out(chip, CS4231_AUX1_LEFT_INPUT, 0xff);
snd_wss_out(chip, CS4231_AUX1_RIGHT_INPUT, 0xff);
snd_wss_out(chip, CS4231_AUX2_LEFT_INPUT, 0xdf);
snd_wss_out(chip, CS4231_AUX2_RIGHT_INPUT, 0xdf);
snd_wss_out(chip, CS4231_RIGHT_LINE_IN, 0xff);
snd_wss_out(chip, CS4231_LEFT_LINE_IN, 0xff);
snd_wss_out(chip, CS4231_RIGHT_LINE_IN, 0xff);
switch (chip->hardware) {
case WSS_HW_CS4235:
case WSS_HW_CS4239:
snd_wss_out(chip, CS4235_LEFT_MASTER, 0xff);
snd_wss_out(chip, CS4235_RIGHT_MASTER, 0xff);
break;
}
*rchip = chip;
return 0;
}
int snd_cs4236_pcm(struct snd_wss *chip, int device, struct snd_pcm **rpcm)
{
struct snd_pcm *pcm;
int err;
err = snd_wss_pcm(chip, device, &pcm);
if (err < 0)
return err;
pcm->info_flags &= ~SNDRV_PCM_INFO_JOINT_DUPLEX;
if (rpcm)
*rpcm = pcm;
return 0;
}
static int snd_cs4236_info_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_cs4236_get_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = (chip->eimage[CS4236_REG(reg)] >> shift) & mask;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (invert)
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
return 0;
}
static int snd_cs4236_put_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
int change;
unsigned short val;
val = (ucontrol->value.integer.value[0] & mask);
if (invert)
val = mask - val;
val <<= shift;
spin_lock_irqsave(&chip->reg_lock, flags);
val = (chip->eimage[CS4236_REG(reg)] & ~(mask << shift)) | val;
change = val != chip->eimage[CS4236_REG(reg)];
snd_cs4236_ext_out(chip, reg, val);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
static int snd_cs4236_get_singlec(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = (chip->cimage[reg] >> shift) & mask;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (invert)
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
return 0;
}
static int snd_cs4236_put_singlec(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
int change;
unsigned short val;
val = (ucontrol->value.integer.value[0] & mask);
if (invert)
val = mask - val;
val <<= shift;
spin_lock_irqsave(&chip->reg_lock, flags);
val = (chip->cimage[reg] & ~(mask << shift)) | val;
change = val != chip->cimage[reg];
snd_cs4236_ctrl_out(chip, reg, val);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
static int snd_cs4236_info_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 24) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_cs4236_get_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = (chip->eimage[CS4236_REG(left_reg)] >> shift_left) & mask;
ucontrol->value.integer.value[1] = (chip->eimage[CS4236_REG(right_reg)] >> shift_right) & mask;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (invert) {
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
ucontrol->value.integer.value[1] = mask - ucontrol->value.integer.value[1];
}
return 0;
}
static int snd_cs4236_put_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
int change;
unsigned short val1, val2;
val1 = ucontrol->value.integer.value[0] & mask;
val2 = ucontrol->value.integer.value[1] & mask;
if (invert) {
val1 = mask - val1;
val2 = mask - val2;
}
val1 <<= shift_left;
val2 <<= shift_right;
spin_lock_irqsave(&chip->reg_lock, flags);
if (left_reg != right_reg) {
val1 = (chip->eimage[CS4236_REG(left_reg)] & ~(mask << shift_left)) | val1;
val2 = (chip->eimage[CS4236_REG(right_reg)] & ~(mask << shift_right)) | val2;
change = val1 != chip->eimage[CS4236_REG(left_reg)] || val2 != chip->eimage[CS4236_REG(right_reg)];
snd_cs4236_ext_out(chip, left_reg, val1);
snd_cs4236_ext_out(chip, right_reg, val2);
} else {
val1 = (chip->eimage[CS4236_REG(left_reg)] & ~((mask << shift_left) | (mask << shift_right))) | val1 | val2;
change = val1 != chip->eimage[CS4236_REG(left_reg)];
snd_cs4236_ext_out(chip, left_reg, val1);
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
static int snd_cs4236_get_double1(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = (chip->image[left_reg] >> shift_left) & mask;
ucontrol->value.integer.value[1] = (chip->eimage[CS4236_REG(right_reg)] >> shift_right) & mask;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (invert) {
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
ucontrol->value.integer.value[1] = mask - ucontrol->value.integer.value[1];
}
return 0;
}
static int snd_cs4236_put_double1(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
int change;
unsigned short val1, val2;
val1 = ucontrol->value.integer.value[0] & mask;
val2 = ucontrol->value.integer.value[1] & mask;
if (invert) {
val1 = mask - val1;
val2 = mask - val2;
}
val1 <<= shift_left;
val2 <<= shift_right;
spin_lock_irqsave(&chip->reg_lock, flags);
val1 = (chip->image[left_reg] & ~(mask << shift_left)) | val1;
val2 = (chip->eimage[CS4236_REG(right_reg)] & ~(mask << shift_right)) | val2;
change = val1 != chip->image[left_reg] || val2 != chip->eimage[CS4236_REG(right_reg)];
snd_wss_out(chip, left_reg, val1);
snd_cs4236_ext_out(chip, right_reg, val2);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
static inline int snd_cs4236_mixer_master_digital_invert_volume(int vol)
{
return (vol < 64) ? 63 - vol : 64 + (71 - vol);
}
static int snd_cs4236_get_master_digital(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = snd_cs4236_mixer_master_digital_invert_volume(chip->eimage[CS4236_REG(CS4236_LEFT_MASTER)] & 0x7f);
ucontrol->value.integer.value[1] = snd_cs4236_mixer_master_digital_invert_volume(chip->eimage[CS4236_REG(CS4236_RIGHT_MASTER)] & 0x7f);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
static int snd_cs4236_put_master_digital(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int change;
unsigned short val1, val2;
val1 = snd_cs4236_mixer_master_digital_invert_volume(ucontrol->value.integer.value[0] & 0x7f);
val2 = snd_cs4236_mixer_master_digital_invert_volume(ucontrol->value.integer.value[1] & 0x7f);
spin_lock_irqsave(&chip->reg_lock, flags);
val1 = (chip->eimage[CS4236_REG(CS4236_LEFT_MASTER)] & ~0x7f) | val1;
val2 = (chip->eimage[CS4236_REG(CS4236_RIGHT_MASTER)] & ~0x7f) | val2;
change = val1 != chip->eimage[CS4236_REG(CS4236_LEFT_MASTER)] || val2 != chip->eimage[CS4236_REG(CS4236_RIGHT_MASTER)];
snd_cs4236_ext_out(chip, CS4236_LEFT_MASTER, val1);
snd_cs4236_ext_out(chip, CS4236_RIGHT_MASTER, val2);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
static inline int snd_cs4235_mixer_output_accu_get_volume(int vol)
{
switch ((vol >> 5) & 3) {
case 0: return 1;
case 1: return 3;
case 2: return 2;
case 3: return 0;
}
return 3;
}
static inline int snd_cs4235_mixer_output_accu_set_volume(int vol)
{
switch (vol & 3) {
case 0: return 3 << 5;
case 1: return 0 << 5;
case 2: return 2 << 5;
case 3: return 1 << 5;
}
return 1 << 5;
}
static int snd_cs4235_get_output_accu(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = snd_cs4235_mixer_output_accu_get_volume(chip->image[CS4235_LEFT_MASTER]);
ucontrol->value.integer.value[1] = snd_cs4235_mixer_output_accu_get_volume(chip->image[CS4235_RIGHT_MASTER]);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
static int snd_cs4235_put_output_accu(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int change;
unsigned short val1, val2;
val1 = snd_cs4235_mixer_output_accu_set_volume(ucontrol->value.integer.value[0]);
val2 = snd_cs4235_mixer_output_accu_set_volume(ucontrol->value.integer.value[1]);
spin_lock_irqsave(&chip->reg_lock, flags);
val1 = (chip->image[CS4235_LEFT_MASTER] & ~(3 << 5)) | val1;
val2 = (chip->image[CS4235_RIGHT_MASTER] & ~(3 << 5)) | val2;
change = val1 != chip->image[CS4235_LEFT_MASTER] || val2 != chip->image[CS4235_RIGHT_MASTER];
snd_wss_out(chip, CS4235_LEFT_MASTER, val1);
snd_wss_out(chip, CS4235_RIGHT_MASTER, val2);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
static int snd_cs4236_get_iec958_switch(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = chip->image[CS4231_ALT_FEATURE_1] & 0x02 ? 1 : 0;
#if 0
printk(KERN_DEBUG "get valid: ALT = 0x%x, C3 = 0x%x, C4 = 0x%x, "
"C5 = 0x%x, C6 = 0x%x, C8 = 0x%x\n",
snd_wss_in(chip, CS4231_ALT_FEATURE_1),
snd_cs4236_ctrl_in(chip, 3),
snd_cs4236_ctrl_in(chip, 4),
snd_cs4236_ctrl_in(chip, 5),
snd_cs4236_ctrl_in(chip, 6),
snd_cs4236_ctrl_in(chip, 8));
#endif
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
static int snd_cs4236_put_iec958_switch(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int change;
unsigned short enable, val;
enable = ucontrol->value.integer.value[0] & 1;
mutex_lock(&chip->mce_mutex);
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
val = (chip->image[CS4231_ALT_FEATURE_1] & ~0x0e) | (0<<2) | (enable << 1);
change = val != chip->image[CS4231_ALT_FEATURE_1];
snd_wss_out(chip, CS4231_ALT_FEATURE_1, val);
val = snd_cs4236_ctrl_in(chip, 4) | 0xc0;
snd_cs4236_ctrl_out(chip, 4, val);
udelay(100);
val &= ~0x40;
snd_cs4236_ctrl_out(chip, 4, val);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
mutex_unlock(&chip->mce_mutex);
#if 0
printk(KERN_DEBUG "set valid: ALT = 0x%x, C3 = 0x%x, C4 = 0x%x, "
"C5 = 0x%x, C6 = 0x%x, C8 = 0x%x\n",
snd_wss_in(chip, CS4231_ALT_FEATURE_1),
snd_cs4236_ctrl_in(chip, 3),
snd_cs4236_ctrl_in(chip, 4),
snd_cs4236_ctrl_in(chip, 5),
snd_cs4236_ctrl_in(chip, 6),
snd_cs4236_ctrl_in(chip, 8));
#endif
return change;
}
int snd_cs4236_mixer(struct snd_wss *chip)
{
struct snd_card *card;
unsigned int idx, count;
int err;
struct snd_kcontrol_new *kcontrol;
if (snd_BUG_ON(!chip || !chip->card))
return -EINVAL;
card = chip->card;
strcpy(card->mixername, snd_wss_chip_id(chip));
if (chip->hardware == WSS_HW_CS4235 ||
chip->hardware == WSS_HW_CS4239) {
for (idx = 0; idx < ARRAY_SIZE(snd_cs4235_controls); idx++) {
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_cs4235_controls[idx], chip))) < 0)
return err;
}
} else {
for (idx = 0; idx < ARRAY_SIZE(snd_cs4236_controls); idx++) {
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_cs4236_controls[idx], chip))) < 0)
return err;
}
}
switch (chip->hardware) {
case WSS_HW_CS4235:
case WSS_HW_CS4239:
count = ARRAY_SIZE(snd_cs4236_3d_controls_cs4235);
kcontrol = snd_cs4236_3d_controls_cs4235;
break;
case WSS_HW_CS4237B:
count = ARRAY_SIZE(snd_cs4236_3d_controls_cs4237);
kcontrol = snd_cs4236_3d_controls_cs4237;
break;
case WSS_HW_CS4238B:
count = ARRAY_SIZE(snd_cs4236_3d_controls_cs4238);
kcontrol = snd_cs4236_3d_controls_cs4238;
break;
default:
count = 0;
kcontrol = NULL;
}
for (idx = 0; idx < count; idx++, kcontrol++) {
if ((err = snd_ctl_add(card, snd_ctl_new1(kcontrol, chip))) < 0)
return err;
}
if (chip->hardware == WSS_HW_CS4237B ||
chip->hardware == WSS_HW_CS4238B) {
for (idx = 0; idx < ARRAY_SIZE(snd_cs4236_iec958_controls); idx++) {
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_cs4236_iec958_controls[idx], chip))) < 0)
return err;
}
}
return 0;
}
