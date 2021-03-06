static int mx_init_card(void)
{
struct sc_reg_access sc_access[] = {
{0x200, 0x80, 0x00},
{0x201, 0xC0, 0x00},
{0x202, 0x00, 0x00},
{0x203, 0x00, 0x00},
{0x204, 0x02, 0x00},
{0x205, 0x10, 0x00},
{0x206, 0x60, 0x00},
{0x207, 0x00, 0x00},
{0x208, 0x90, 0x00},
{0x209, 0x51, 0x00},
{0x20a, 0x00, 0x00},
{0x20b, 0x10, 0x00},
{0x20c, 0x00, 0x00},
{0x20d, 0x00, 0x00},
{0x20e, 0x21, 0x00},
{0x20f, 0x00, 0x00},
{0x210, 0x84, 0x00},
{0x211, 0xB3, 0x00},
{0x212, 0x00, 0x00},
{0x213, 0x00, 0x00},
{0x214, 0x41, 0x00},
{0x215, 0x00, 0x00},
{0x216, 0x00, 0x00},
{0x217, 0x00, 0x00},
{0x218, 0x03, 0x00},
{0x219, 0x03, 0x00},
{0x21a, 0x00, 0x00},
{0x21b, 0x00, 0x00},
{0x21c, 0x00, 0x00},
{0x21d, 0x00, 0x00},
{0x21e, 0x00, 0x00},
{0x21f, 0x00, 0x00},
{0x220, 0x20, 0x00},
{0x221, 0x20, 0x00},
{0x222, 0x51, 0x00},
{0x223, 0x20, 0x00},
{0x224, 0x04, 0x00},
{0x225, 0x80, 0x00},
{0x226, 0x0F, 0x00},
{0x227, 0x08, 0x00},
{0xf9, 0x40, 0x00},
{0xfa, 0x1f, 0x00},
{0xfb, 0x1f, 0x00},
{0xfc, 0x1f, 0x00},
{0xfd, 0x1f, 0x00},
{0xfe, 0x00, 0x00},
{0xff, 0x0c, 0x00},
};
snd_pmic_ops_mx.card_status = SND_CARD_INIT_DONE;
snd_pmic_ops_mx.num_channel = 2;
snd_pmic_ops_mx.master_mute = UNMUTE;
snd_pmic_ops_mx.mute_status = UNMUTE;
return sst_sc_reg_access(sc_access, PMIC_WRITE, 47);
}
static int mx_enable_audiodac(int value)
{
struct sc_reg_access sc_access[3];
int mute_val = 0;
int mute_val1 = 0;
int retval = 0;
sc_access[0].reg_addr = AS_LEFT_HP_VOL_CTL;
sc_access[1].reg_addr = AS_RIGHT_HP_VOL_CTL;
if (value == UNMUTE) {
mute_val = 0x1F;
mute_val1 = 0x00;
} else {
mute_val = 0x00;
mute_val1 = 0x40;
}
sc_access[0].mask = sc_access[1].mask = MASK0|MASK1|MASK2|MASK3|MASK4;
sc_access[0].value = sc_access[1].value = (u8)mute_val;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 2);
if (retval)
return retval;
pr_debug("mute status = %d\n", snd_pmic_ops_mx.mute_status);
if (snd_pmic_ops_mx.mute_status == MUTE ||
snd_pmic_ops_mx.master_mute == MUTE)
return retval;
sc_access[0].reg_addr = VOL_CTRL_LT;
sc_access[1].reg_addr = VOL_CTRL_RT;
sc_access[0].mask = sc_access[1].mask = MASK6;
sc_access[0].value = sc_access[1].value = mute_val1;
if (snd_pmic_ops_mx.num_channel == 1)
sc_access[1].value = 0x40;
return sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 2);
}
static int mx_power_up_pb(unsigned int port)
{
int retval = 0;
struct sc_reg_access sc_access[3];
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
retval = mx_enable_audiodac(MUTE);
if (retval)
return retval;
msleep(10);
sc_access[0].reg_addr = AS_CONFIG;
sc_access[0].mask = MASK7;
sc_access[0].value = 0x80;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 1);
if (retval)
return retval;
sc_access[0].reg_addr = ENABLE_OPDEV_CTRL;
sc_access[0].mask = 0xff;
sc_access[0].value = 0x3C;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 1);
if (retval)
return retval;
sc_access[0].reg_addr = ENABLE_DEV_AND_USE_XTAL;
sc_access[0].mask = 0x80;
sc_access[0].value = 0x80;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 1);
if (retval)
return retval;
return mx_enable_audiodac(UNMUTE);
}
static int mx_power_down_pb(unsigned int device)
{
struct sc_reg_access sc_access[3];
int retval = 0;
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
retval = mx_enable_audiodac(MUTE);
if (retval)
return retval;
sc_access[0].reg_addr = ENABLE_OPDEV_CTRL;
sc_access[0].mask = MASK3|MASK2;
sc_access[0].value = 0x00;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 1);
if (retval)
return retval;
return mx_enable_audiodac(UNMUTE);
}
static int mx_power_up_cp(unsigned int port)
{
int retval = 0;
struct sc_reg_access sc_access[] = {
{ENABLE_DEV_AND_USE_XTAL, 0x80, MASK7},
{ENABLE_OPDEV_CTRL, 0x3, 0x3},
};
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
return sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 2);
}
static int mx_power_down_cp(unsigned int device)
{
struct sc_reg_access sc_access[] = {
{ENABLE_OPDEV_CTRL, 0x00, MASK1|MASK0},
};
int retval = 0;
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
return sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 1);
}
static int mx_power_down(void)
{
int retval = 0;
struct sc_reg_access sc_access[3];
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
retval = mx_enable_audiodac(MUTE);
if (retval)
return retval;
sc_access[0].reg_addr = AS_CONFIG;
sc_access[0].mask = MASK7;
sc_access[0].value = 0x00;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 1);
if (retval)
return retval;
sc_access[0].reg_addr = ENABLE_DEV_AND_USE_XTAL;
sc_access[0].mask = MASK7;
sc_access[0].value = 0x00;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 1);
if (retval)
return retval;
sc_access[0].reg_addr = ENABLE_OPDEV_CTRL;
sc_access[0].mask = MASK3|MASK2;
sc_access[0].value = 0x00;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 1);
if (retval)
return retval;
return mx_enable_audiodac(UNMUTE);
}
static int mx_set_pcm_voice_params(void)
{
int retval = 0;
struct sc_reg_access sc_access[] = {
{0x200, 0x80, 0x00},
{0x201, 0xC0, 0x00},
{0x202, 0x00, 0x00},
{0x203, 0x00, 0x00},
{0x204, 0x0e, 0x00},
{0x205, 0x20, 0x00},
{0x206, 0x8f, 0x00},
{0x207, 0x21, 0x00},
{0x208, 0x18, 0x00},
{0x209, 0x32, 0x00},
{0x20a, 0x00, 0x00},
{0x20b, 0x5A, 0x00},
{0x20c, 0xBE, 0x00},
{0x20d, 0x00, 0x00},
{0x20e, 0x40, 0x00},
{0x20f, 0x00, 0x00},
{0x210, 0x84, 0x00},
{0x211, 0x33, 0x00},
{0x212, 0x00, 0x00},
{0x213, 0x00, 0x00},
{0x214, 0x41, 0x00},
{0x215, 0x00, 0x00},
{0x216, 0x00, 0x00},
{0x217, 0x20, 0x00},
{0x218, 0x00, 0x00},
{0x219, 0x00, 0x00},
{0x21a, 0x40, 0x00},
{0x21b, 0x40, 0x00},
{0x21c, 0x09, 0x00},
{0x21d, 0x09, 0x00},
{0x21e, 0x00, 0x00},
{0x21f, 0x00, 0x00},
{0x220, 0x00, 0x00},
{0x221, 0x00, 0x00},
{0x222, 0x50, 0x00},
{0x223, 0x21, 0x00},
{0x224, 0x00, 0x00},
{0x225, 0x80, 0x00},
{0xf9, 0x40, 0x00},
{0xfa, 0x19, 0x00},
{0xfb, 0x19, 0x00},
{0xfc, 0x12, 0x00},
{0xfd, 0x12, 0x00},
{0xfe, 0x00, 0x00},
};
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
pr_debug("SST DBG:mx_set_pcm_voice_params called\n");
return sst_sc_reg_access(sc_access, PMIC_WRITE, 44);
}
static int mx_set_pcm_audio_params(int sfreq, int word_size, int num_channel)
{
int retval = 0;
int config1 = 0, config2 = 0, filter = 0xB3;
struct sc_reg_access sc_access[5];
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
switch (sfreq) {
case 8000:
config1 = 0x10;
config2 = 0x00;
filter = 0x33;
break;
case 11025:
config1 = 0x16;
config2 = 0x0d;
break;
case 12000:
config1 = 0x18;
config2 = 0x00;
break;
case 16000:
config1 = 0x20;
config2 = 0x00;
break;
case 22050:
config1 = 0x2c;
config2 = 0x1a;
break;
case 24000:
config1 = 0x30;
config2 = 0x00;
break;
case 32000:
config1 = 0x40;
config2 = 0x00;
break;
case 44100:
config1 = 0x58;
config2 = 0x33;
break;
case 48000:
config1 = 0x60;
config2 = 0x00;
break;
}
snd_pmic_ops_mx.num_channel = num_channel;
if (snd_pmic_ops_mx.num_channel == 1) {
sc_access[0].reg_addr = VOL_CTRL_RT;
sc_access[0].value = 0x40;
sc_access[0].mask = MASK6;
sc_access[1].reg_addr = 0x224;
sc_access[1].value = 0x05;
sc_access[1].mask = MASK0|MASK1|MASK2;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 2);
if (retval)
return retval;
} else {
sc_access[0].reg_addr = VOL_CTRL_RT;
sc_access[0].value = 0x00;
sc_access[0].mask = MASK6;
sc_access[1].reg_addr = 0x224;
sc_access[1].value = 0x04;
sc_access[1].mask = MASK0|MASK1|MASK2;
retval = sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, 2);
if (retval)
return retval;
}
sc_access[0].reg_addr = 0x206;
sc_access[0].value = config1;
sc_access[1].reg_addr = 0x207;
sc_access[1].value = config2;
if (word_size == 16) {
sc_access[2].value = 0x51;
sc_access[3].value = 0x31;
} else if (word_size == 24) {
sc_access[2].value = 0x52;
sc_access[3].value = 0x92;
}
sc_access[2].reg_addr = 0x209;
sc_access[3].reg_addr = 0x20e;
sc_access[4].reg_addr = 0x211;
sc_access[4].value = filter;
return sst_sc_reg_access(sc_access, PMIC_WRITE, 5);
}
static int mx_set_selected_output_dev(u8 dev_id)
{
struct sc_reg_access sc_access[2];
int num_reg = 0;
int retval = 0;
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
pr_debug("mx_set_selected_output_dev dev_id:0x%x\n", dev_id);
snd_pmic_ops_mx.output_dev_id = dev_id;
switch (dev_id) {
case STEREO_HEADPHONE:
sc_access[0].reg_addr = 0xFF;
sc_access[0].value = 0x8C;
sc_access[0].mask =
MASK2|MASK3|MASK5|MASK6|MASK4;
num_reg = 1;
break;
case MONO_EARPIECE:
case INTERNAL_SPKR:
sc_access[0].reg_addr = 0xFF;
sc_access[0].value = 0xb0;
sc_access[0].mask = MASK2|MASK3|MASK5|MASK6|MASK4;
num_reg = 1;
break;
case RECEIVER:
pr_debug("RECEIVER Koski selected\n");
sc_access[0].reg_addr = 0xFF;
sc_access[0].value = 0x81;
sc_access[0].mask = 0xff;
num_reg = 1;
break;
default:
pr_err("Not a valid output dev\n");
return 0;
}
return sst_sc_reg_access(sc_access, PMIC_WRITE, num_reg);
}
static int mx_set_voice_port(int status)
{
int retval = 0;
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
if (status == ACTIVATE)
retval = mx_set_pcm_voice_params();
return retval;
}
static int mx_set_audio_port(int status)
{
return 0;
}
static int mx_set_selected_input_dev(u8 dev_id)
{
struct sc_reg_access sc_access[2];
int num_reg = 0;
int retval = 0;
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
snd_pmic_ops_mx.input_dev_id = dev_id;
pr_debug("mx_set_selected_input_dev dev_id:0x%x\n", dev_id);
switch (dev_id) {
case AMIC:
sc_access[0].reg_addr = 0x223;
sc_access[0].value = 0x00;
sc_access[0].mask = MASK7|MASK6|MASK5|MASK4|MASK0;
sc_access[1].reg_addr = 0x222;
sc_access[1].value = 0x50;
sc_access[1].mask = MASK7|MASK6|MASK5|MASK4;
num_reg = 2;
break;
case HS_MIC:
sc_access[0].reg_addr = 0x223;
sc_access[0].value = 0x20;
sc_access[0].mask = MASK7|MASK6|MASK5|MASK4|MASK0;
sc_access[1].reg_addr = 0x222;
sc_access[1].value = 0x51;
sc_access[1].mask = MASK7|MASK6|MASK5|MASK4;
num_reg = 2;
break;
case DMIC:
sc_access[1].reg_addr = 0x222;
sc_access[1].value = 0x00;
sc_access[1].mask = MASK7|MASK6|MASK5|MASK4|MASK0;
sc_access[0].reg_addr = 0x223;
sc_access[0].value = 0x20;
sc_access[0].mask = MASK7|MASK6|MASK5|MASK4|MASK0;
num_reg = 2;
break;
}
return sst_sc_reg_access(sc_access, PMIC_WRITE, num_reg);
}
static int mx_set_mute(int dev_id, u8 value)
{
struct sc_reg_access sc_access[5];
int num_reg = 0;
int retval = 0;
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
pr_debug("set_mute dev_id:0x%x , value:%d\n", dev_id, value);
switch (dev_id) {
case PMIC_SND_DMIC_MUTE:
case PMIC_SND_AMIC_MUTE:
case PMIC_SND_HP_MIC_MUTE:
sc_access[0].reg_addr = 0x220;
sc_access[1].reg_addr = 0x221;
sc_access[2].reg_addr = 0x223;
if (value == MUTE) {
sc_access[0].value = 0x00;
sc_access[1].value = 0x00;
if (snd_pmic_ops_mx.input_dev_id == DMIC)
sc_access[2].value = 0x00;
else
sc_access[2].value = 0x20;
} else {
sc_access[0].value = 0x20;
sc_access[1].value = 0x20;
if (snd_pmic_ops_mx.input_dev_id == DMIC)
sc_access[2].value = 0x20;
else
sc_access[2].value = 0x00;
}
sc_access[0].mask = MASK5|MASK6;
sc_access[1].mask = MASK5|MASK6;
sc_access[2].mask = MASK5|MASK6;
num_reg = 3;
break;
case PMIC_SND_LEFT_SPEAKER_MUTE:
case PMIC_SND_LEFT_HP_MUTE:
sc_access[0].reg_addr = VOL_CTRL_LT;
if (value == MUTE)
sc_access[0].value = 0x40;
else
sc_access[0].value = 0x00;
sc_access[0].mask = MASK6;
num_reg = 1;
snd_pmic_ops_mx.mute_status = value;
break;
case PMIC_SND_RIGHT_SPEAKER_MUTE:
case PMIC_SND_RIGHT_HP_MUTE:
sc_access[0].reg_addr = VOL_CTRL_RT;
if (snd_pmic_ops_mx.num_channel == 1)
value = MUTE;
if (value == MUTE)
sc_access[0].value = 0x40;
else
sc_access[0].value = 0x00;
sc_access[0].mask = MASK6;
num_reg = 1;
snd_pmic_ops_mx.mute_status = value;
break;
case PMIC_SND_MUTE_ALL:
sc_access[0].reg_addr = VOL_CTRL_RT;
sc_access[1].reg_addr = VOL_CTRL_LT;
sc_access[2].reg_addr = 0x220;
sc_access[3].reg_addr = 0x221;
sc_access[4].reg_addr = 0x223;
snd_pmic_ops_mx.master_mute = value;
if (value == MUTE) {
sc_access[0].value = sc_access[1].value = 0x40;
sc_access[2].value = 0x00;
sc_access[3].value = 0x00;
if (snd_pmic_ops_mx.input_dev_id == DMIC)
sc_access[4].value = 0x00;
else
sc_access[4].value = 0x20;
} else {
sc_access[0].value = sc_access[1].value = 0x00;
sc_access[2].value = sc_access[3].value = 0x20;
sc_access[4].value = 0x20;
if (snd_pmic_ops_mx.input_dev_id == DMIC)
sc_access[4].value = 0x20;
else
sc_access[4].value = 0x00;
}
if (snd_pmic_ops_mx.num_channel == 1)
sc_access[0].value = 0x40;
sc_access[0].mask = sc_access[1].mask = MASK6;
sc_access[2].mask = MASK5|MASK6;
sc_access[3].mask = MASK5|MASK6|MASK2|MASK4;
sc_access[4].mask = MASK5|MASK6|MASK4;
num_reg = 5;
break;
case PMIC_SND_RECEIVER_MUTE:
sc_access[0].reg_addr = VOL_CTRL_RT;
if (value == MUTE)
sc_access[0].value = 0x40;
else
sc_access[0].value = 0x00;
sc_access[0].mask = MASK6;
num_reg = 1;
break;
}
return sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, num_reg);
}
static int mx_set_vol(int dev_id, int value)
{
struct sc_reg_access sc_access[2] = {{0},};
int num_reg = 0;
int retval = 0;
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
pr_debug("set_vol dev_id:0x%x ,value:%d\n", dev_id, value);
switch (dev_id) {
case PMIC_SND_RECEIVER_VOL:
return 0;
break;
case PMIC_SND_CAPTURE_VOL:
sc_access[0].reg_addr = 0x220;
sc_access[1].reg_addr = 0x221;
sc_access[0].value = sc_access[1].value = -value;
sc_access[0].mask = sc_access[1].mask =
(MASK0|MASK1|MASK2|MASK3|MASK4);
num_reg = 2;
break;
case PMIC_SND_LEFT_PB_VOL:
sc_access[0].value = -value;
sc_access[0].reg_addr = VOL_CTRL_LT;
sc_access[0].mask = (MASK0|MASK1|MASK2|MASK3|MASK4|MASK5);
num_reg = 1;
break;
case PMIC_SND_RIGHT_PB_VOL:
sc_access[0].value = -value;
sc_access[0].reg_addr = VOL_CTRL_RT;
sc_access[0].mask = (MASK0|MASK1|MASK2|MASK3|MASK4|MASK5);
if (snd_pmic_ops_mx.num_channel == 1) {
sc_access[0].value = 0x40;
sc_access[0].mask = MASK6;
sc_access[0].reg_addr = VOL_CTRL_RT;
}
num_reg = 1;
break;
}
return sst_sc_reg_access(sc_access, PMIC_READ_MODIFY, num_reg);
}
static int mx_get_mute(int dev_id, u8 *value)
{
struct sc_reg_access sc_access[4] = {{0},};
int retval = 0, num_reg = 0, mask = 0;
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
switch (dev_id) {
case PMIC_SND_DMIC_MUTE:
case PMIC_SND_AMIC_MUTE:
case PMIC_SND_HP_MIC_MUTE:
sc_access[0].reg_addr = 0x220;
mask = MASK5|MASK6;
num_reg = 1;
retval = sst_sc_reg_access(sc_access, PMIC_READ, num_reg);
if (retval)
return retval;
*value = sc_access[0].value & mask;
if (*value)
*value = UNMUTE;
else
*value = MUTE;
return retval;
case PMIC_SND_LEFT_HP_MUTE:
case PMIC_SND_LEFT_SPEAKER_MUTE:
sc_access[0].reg_addr = VOL_CTRL_LT;
num_reg = 1;
mask = MASK6;
break;
case PMIC_SND_RIGHT_HP_MUTE:
case PMIC_SND_RIGHT_SPEAKER_MUTE:
sc_access[0].reg_addr = VOL_CTRL_RT;
num_reg = 1;
mask = MASK6;
break;
}
retval = sst_sc_reg_access(sc_access, PMIC_READ, num_reg);
if (retval)
return retval;
*value = sc_access[0].value & mask;
if (*value)
*value = MUTE;
else
*value = UNMUTE;
return retval;
}
static int mx_get_vol(int dev_id, int *value)
{
struct sc_reg_access sc_access = {0,};
int retval = 0, mask = 0, num_reg = 0;
if (snd_pmic_ops_mx.card_status == SND_CARD_UN_INIT) {
retval = mx_init_card();
if (retval)
return retval;
}
switch (dev_id) {
case PMIC_SND_CAPTURE_VOL:
sc_access.reg_addr = 0x220;
mask = MASK0|MASK1|MASK2|MASK3|MASK4;
num_reg = 1;
break;
case PMIC_SND_LEFT_PB_VOL:
sc_access.reg_addr = VOL_CTRL_LT;
mask = MASK0|MASK1|MASK2|MASK3|MASK4|MASK5;
num_reg = 1;
break;
case PMIC_SND_RIGHT_PB_VOL:
sc_access.reg_addr = VOL_CTRL_RT;
mask = MASK0|MASK1|MASK2|MASK3|MASK4|MASK5;
num_reg = 1;
break;
}
retval = sst_sc_reg_access(&sc_access, PMIC_READ, num_reg);
if (retval)
return retval;
*value = -(sc_access.value & mask);
pr_debug("get volume value extracted %d\n", *value);
return retval;
}
static u8 mx_get_jack_status(void)
{
struct sc_reg_access sc_access_read = {0,};
sc_access_read.reg_addr = 0x201;
sst_sc_reg_access(&sc_access_read, PMIC_READ, 1);
pr_debug("value returned = 0x%x\n", sc_access_read.value);
return sc_access_read.value;
}
static void mx_pmic_irq_enable(void *data)
{
struct snd_intelmad *intelmaddata = data;
intelmaddata->jack_prev_state = 0xc0;
return;
}
static void mx_pmic_irq_cb(void *cb_data, u8 intsts)
{
u8 jack_cur_status, jack_prev_state = 0;
struct mad_jack *mjack = NULL;
unsigned int present = 0, jack_event_flag = 0, buttonpressflag = 0;
time_t timediff;
struct snd_intelmad *intelmaddata = cb_data;
mjack = &intelmaddata->jack[0];
if (intsts & 0x2) {
jack_cur_status = mx_get_jack_status();
jack_prev_state = intelmaddata->jack_prev_state;
if ((jack_prev_state == 0xc0) && (jack_cur_status == 0x40)) {
pr_debug("MAD headset inserted\n");
present = 1;
jack_event_flag = 1;
mjack->jack_status = 1;
mjack->jack.type = SND_JACK_HEADSET;
}
if ((jack_prev_state == 0xc0) && (jack_cur_status == 0x00)) {
pr_debug("MAD headphone inserted\n");
present = 1;
jack_event_flag = 1;
mjack->jack.type = SND_JACK_HEADPHONE;
}
if ((jack_prev_state == 0x40) && (jack_cur_status == 0xc0)) {
pr_debug("MAD headset removed\n");
present = 0;
jack_event_flag = 1;
mjack->jack_status = 0;
mjack->jack.type = SND_JACK_HEADSET;
}
if ((jack_prev_state == 0x00) && (jack_cur_status == 0xc0)) {
pr_debug("MAD headphone removed\n");
present = 0;
jack_event_flag = 1;
mjack->jack.type = SND_JACK_HEADPHONE;
}
if ((jack_prev_state == 0x40) && (jack_cur_status == 0x00)) {
do_gettimeofday(&mjack->buttonpressed);
pr_debug("MAD button press detected\n");
}
if ((jack_prev_state == 0x00) && (jack_cur_status == 0x40)) {
if (mjack->jack_status) {
do_gettimeofday(
&mjack->buttonreleased);
pr_debug("MAD Button Released detected\n");
timediff = mjack->buttonreleased.tv_sec -
mjack->buttonpressed.tv_sec;
buttonpressflag = 1;
if (timediff > 1) {
pr_debug("MAD long press dtd\n");
present = 1;
jack_event_flag = 1;
mjack->jack.type =
MID_JACK_HS_LONG_PRESS;
} else {
pr_debug("MAD short press dtd\n");
present = 1;
jack_event_flag = 1;
mjack->jack.type =
MID_JACK_HS_SHORT_PRESS;
}
} else {
pr_debug("MAD headset inserted\n");
present = 1;
jack_event_flag = 1;
mjack->jack_status = 1;
mjack->jack.type = SND_JACK_HEADSET;
}
}
intelmaddata->jack_prev_state = jack_cur_status;
pr_debug("mx_pmic_irq_cb prv_state= 0x%x\n",
intelmaddata->jack_prev_state);
}
if (jack_event_flag)
sst_mad_send_jack_report(&mjack->jack,
buttonpressflag, present);
}
static int mx_jack_enable(void)
{
return 0;
}
