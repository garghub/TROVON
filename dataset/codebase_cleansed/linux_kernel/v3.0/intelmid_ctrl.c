static inline int snd_intelmad_volume_info(struct snd_ctl_elem_info *uinfo,
int control_type, int max, int min)
{
WARN_ON(!uinfo);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = control_type;
uinfo->value.integer.min = min;
uinfo->value.integer.max = max;
return 0;
}
static int snd_intelmad_mute_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
WARN_ON(!uinfo);
WARN_ON(!kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = MONO_CNTL;
uinfo->value.integer.min = MIN_MUTE;
uinfo->value.integer.max = MAX_MUTE;
return 0;
}
static int snd_intelmad_capture_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
snd_intelmad_volume_info(uinfo, MONO_CNTL,
intelmad_ctrl_val[sst_card_vendor_id].capture_vol_max,
intelmad_ctrl_val[sst_card_vendor_id].capture_vol_min);
return 0;
}
static int snd_intelmad_playback_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
snd_intelmad_volume_info(uinfo, STEREO_CNTL,
intelmad_ctrl_val[sst_card_vendor_id].playback_vol_max,
intelmad_ctrl_val[sst_card_vendor_id].playback_vol_min);
return 0;
}
static int snd_intelmad_master_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
snd_intelmad_volume_info(uinfo, STEREO_CNTL,
intelmad_ctrl_val[sst_card_vendor_id].master_vol_max,
intelmad_ctrl_val[sst_card_vendor_id].master_vol_min);
return 0;
}
static int snd_intelmad_device_info_mrst(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
WARN_ON(!kcontrol);
WARN_ON(!uinfo);
if (kcontrol->id.numid == OUTPUT_SEL)
uinfo->value.enumerated.items = ARRAY_SIZE(out_names_mrst);
else
uinfo->value.enumerated.items = ARRAY_SIZE(in_names_mrst);
uinfo->count = MONO_CNTL;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = 1;
if (kcontrol->id.numid == OUTPUT_SEL)
strncpy(uinfo->value.enumerated.name,
out_names_mrst[uinfo->value.enumerated.item],
sizeof(uinfo->value.enumerated.name)-1);
else
strncpy(uinfo->value.enumerated.name,
in_names_mrst[uinfo->value.enumerated.item],
sizeof(uinfo->value.enumerated.name)-1);
return 0;
}
static int snd_intelmad_device_info_mfld(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_pmic_ops *scard_ops;
struct snd_intelmad *intelmaddata;
WARN_ON(!kcontrol);
WARN_ON(!uinfo);
intelmaddata = kcontrol->private_data;
WARN_ON(!intelmaddata->sstdrv_ops);
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
if (kcontrol->id.numid == OUTPUT_SEL)
uinfo->value.enumerated.items = ARRAY_SIZE(out_names_mfld);
else if (kcontrol->id.numid == INPUT_SEL)
uinfo->value.enumerated.items = ARRAY_SIZE(in_names_mfld);
else if (kcontrol->id.numid == LINEOUT_SEL_MFLD) {
uinfo->value.enumerated.items = ARRAY_SIZE(line_out_names_mfld);
scard_ops->line_out_names_cnt = uinfo->value.enumerated.items;
} else
return -EINVAL;
uinfo->count = MONO_CNTL;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = 1;
if (kcontrol->id.numid == OUTPUT_SEL)
strncpy(uinfo->value.enumerated.name,
out_names_mfld[uinfo->value.enumerated.item],
sizeof(uinfo->value.enumerated.name)-1);
else if (kcontrol->id.numid == INPUT_SEL)
strncpy(uinfo->value.enumerated.name,
in_names_mfld[uinfo->value.enumerated.item],
sizeof(uinfo->value.enumerated.name)-1);
else if (kcontrol->id.numid == LINEOUT_SEL_MFLD)
strncpy(uinfo->value.enumerated.name,
line_out_names_mfld[uinfo->value.enumerated.item],
sizeof(uinfo->value.enumerated.name)-1);
else
return -EINVAL;
return 0;
}
static int snd_intelmad_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uval)
{
int ret_val = 0, cntl_list[2] = {0,};
int value = 0;
struct snd_intelmad *intelmaddata;
struct snd_pmic_ops *scard_ops;
pr_debug("snd_intelmad_volume_get called\n");
WARN_ON(!uval);
WARN_ON(!kcontrol);
intelmaddata = kcontrol->private_data;
WARN_ON(!intelmaddata->sstdrv_ops);
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
WARN_ON(!scard_ops);
switch (kcontrol->id.numid) {
case PLAYBACK_VOL:
cntl_list[0] = PMIC_SND_RIGHT_PB_VOL;
cntl_list[1] = PMIC_SND_LEFT_PB_VOL;
break;
case CAPTURE_VOL:
cntl_list[0] = PMIC_SND_CAPTURE_VOL;
break;
case MASTER_VOL:
cntl_list[0] = PMIC_SND_RIGHT_MASTER_VOL;
cntl_list[1] = PMIC_SND_LEFT_MASTER_VOL;
break;
default:
return -EINVAL;
}
ret_val = scard_ops->get_vol(cntl_list[0], &value);
uval->value.integer.value[0] = value;
if (ret_val)
return ret_val;
if (kcontrol->id.numid == PLAYBACK_VOL ||
kcontrol->id.numid == MASTER_VOL) {
ret_val = scard_ops->get_vol(cntl_list[1], &value);
uval->value.integer.value[1] = value;
}
return ret_val;
}
static int snd_intelmad_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uval)
{
int cntl_list = 0, ret_val = 0;
u8 value = 0;
struct snd_intelmad *intelmaddata;
struct snd_pmic_ops *scard_ops;
pr_debug("Mute_get called\n");
WARN_ON(!uval);
WARN_ON(!kcontrol);
intelmaddata = kcontrol->private_data;
WARN_ON(!intelmaddata->sstdrv_ops);
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
WARN_ON(!scard_ops);
switch (kcontrol->id.numid) {
case PLAYBACK_MUTE:
if (intelmaddata->output_sel == STEREO_HEADPHONE)
cntl_list = PMIC_SND_LEFT_HP_MUTE;
else if ((intelmaddata->output_sel == INTERNAL_SPKR) ||
(intelmaddata->output_sel == MONO_EARPIECE))
cntl_list = PMIC_SND_LEFT_SPEAKER_MUTE;
break;
case CAPTURE_MUTE:
if (intelmaddata->input_sel == DMIC)
cntl_list = PMIC_SND_DMIC_MUTE;
else if (intelmaddata->input_sel == AMIC)
cntl_list = PMIC_SND_AMIC_MUTE;
else if (intelmaddata->input_sel == HS_MIC)
cntl_list = PMIC_SND_HP_MIC_MUTE;
break;
case MASTER_MUTE:
uval->value.integer.value[0] = intelmaddata->master_mute;
return 0;
default:
return -EINVAL;
}
ret_val = scard_ops->get_mute(cntl_list, &value);
uval->value.integer.value[0] = value;
return ret_val;
}
static int snd_intelmad_volume_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uval)
{
int ret_val, cntl_list[2] = {0,};
struct snd_intelmad *intelmaddata;
struct snd_pmic_ops *scard_ops;
pr_debug("volume set called:%ld %ld\n",
uval->value.integer.value[0],
uval->value.integer.value[1]);
WARN_ON(!uval);
WARN_ON(!kcontrol);
intelmaddata = kcontrol->private_data;
WARN_ON(!intelmaddata->sstdrv_ops);
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
WARN_ON(!scard_ops);
switch (kcontrol->id.numid) {
case PLAYBACK_VOL:
cntl_list[0] = PMIC_SND_LEFT_PB_VOL;
cntl_list[1] = PMIC_SND_RIGHT_PB_VOL;
break;
case CAPTURE_VOL:
cntl_list[0] = PMIC_SND_CAPTURE_VOL;
break;
case MASTER_VOL:
cntl_list[0] = PMIC_SND_LEFT_MASTER_VOL;
cntl_list[1] = PMIC_SND_RIGHT_MASTER_VOL;
break;
default:
return -EINVAL;
}
ret_val = scard_ops->set_vol(cntl_list[0],
uval->value.integer.value[0]);
if (ret_val)
return ret_val;
if (kcontrol->id.numid == PLAYBACK_VOL ||
kcontrol->id.numid == MASTER_VOL)
ret_val = scard_ops->set_vol(cntl_list[1],
uval->value.integer.value[1]);
return ret_val;
}
static int snd_intelmad_mute_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uval)
{
int cntl_list[2] = {0,}, ret_val;
struct snd_intelmad *intelmaddata;
struct snd_pmic_ops *scard_ops;
pr_debug("snd_intelmad_mute_set called\n");
WARN_ON(!uval);
WARN_ON(!kcontrol);
intelmaddata = kcontrol->private_data;
WARN_ON(!intelmaddata->sstdrv_ops);
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
WARN_ON(!scard_ops);
kcontrol->private_value = uval->value.integer.value[0];
switch (kcontrol->id.numid) {
case PLAYBACK_MUTE:
if (intelmaddata->output_sel == STEREO_HEADPHONE) {
cntl_list[0] = PMIC_SND_LEFT_HP_MUTE;
cntl_list[1] = PMIC_SND_RIGHT_HP_MUTE;
} else if ((intelmaddata->output_sel == INTERNAL_SPKR) ||
(intelmaddata->output_sel == MONO_EARPIECE)) {
cntl_list[0] = PMIC_SND_LEFT_SPEAKER_MUTE;
cntl_list[1] = PMIC_SND_RIGHT_SPEAKER_MUTE;
}
break;
case CAPTURE_MUTE:
if (intelmaddata->input_sel == DMIC)
cntl_list[0] = PMIC_SND_DMIC_MUTE;
else if (intelmaddata->input_sel == AMIC)
cntl_list[0] = PMIC_SND_AMIC_MUTE;
else if (intelmaddata->input_sel == HS_MIC)
cntl_list[0] = PMIC_SND_HP_MIC_MUTE;
break;
case MASTER_MUTE:
cntl_list[0] = PMIC_SND_MUTE_ALL;
intelmaddata->master_mute = uval->value.integer.value[0];
break;
default:
return -EINVAL;
}
ret_val = scard_ops->set_mute(cntl_list[0],
uval->value.integer.value[0]);
if (ret_val)
return ret_val;
if (kcontrol->id.numid == PLAYBACK_MUTE)
ret_val = scard_ops->set_mute(cntl_list[1],
uval->value.integer.value[0]);
return ret_val;
}
static int snd_intelmad_device_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uval)
{
struct snd_intelmad *intelmaddata;
struct snd_pmic_ops *scard_ops;
pr_debug("device_get called\n");
WARN_ON(!uval);
WARN_ON(!kcontrol);
intelmaddata = kcontrol->private_data;
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
if (intelmaddata->cpu_id == CPU_CHIP_PENWELL) {
if (kcontrol->id.numid == OUTPUT_SEL)
uval->value.enumerated.item[0] =
scard_ops->output_dev_id;
else if (kcontrol->id.numid == INPUT_SEL)
uval->value.enumerated.item[0] =
scard_ops->input_dev_id;
else if (kcontrol->id.numid == LINEOUT_SEL_MFLD)
uval->value.enumerated.item[0] =
scard_ops->lineout_dev_id;
else
return -EINVAL;
} else if (intelmaddata->cpu_id == CPU_CHIP_LINCROFT) {
if (kcontrol->id.numid == OUTPUT_SEL)
if (scard_ops->output_dev_id == MONO_EARPIECE ||
scard_ops->output_dev_id == INTERNAL_SPKR)
uval->value.enumerated.item[0] = MONO_EARPIECE;
else if (scard_ops->output_dev_id == STEREO_HEADPHONE)
uval->value.enumerated.item[0] =
STEREO_HEADPHONE;
else
return -EINVAL;
else if (kcontrol->id.numid == INPUT_SEL)
uval->value.enumerated.item[0] =
scard_ops->input_dev_id;
else
return -EINVAL;
} else
uval->value.enumerated.item[0] = kcontrol->private_value;
return 0;
}
static int snd_intelmad_device_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uval)
{
struct snd_intelmad *intelmaddata;
struct snd_pmic_ops *scard_ops;
int ret_val = 0, vendor, status;
struct intel_sst_pcm_control *pcm_control;
pr_debug("snd_intelmad_device_set called\n");
WARN_ON(!uval);
WARN_ON(!kcontrol);
status = -1;
intelmaddata = kcontrol->private_data;
WARN_ON(!intelmaddata->sstdrv_ops);
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
WARN_ON(!scard_ops);
kcontrol->private_value = uval->value.enumerated.item[0];
switch (kcontrol->id.numid) {
case OUTPUT_SEL:
ret_val = scard_ops->set_output_dev(
uval->value.enumerated.item[0]);
intelmaddata->output_sel = uval->value.enumerated.item[0];
break;
case INPUT_SEL:
vendor = intelmaddata->sstdrv_ops->vendor_id;
if ((vendor == SND_MX) || (vendor == SND_FS)) {
pcm_control = intelmaddata->sstdrv_ops->pcm_control;
if (uval->value.enumerated.item[0] == HS_MIC)
status = 1;
else
status = 0;
pcm_control->device_control(
SST_ENABLE_RX_TIME_SLOT, &status);
}
ret_val = scard_ops->set_input_dev(
uval->value.enumerated.item[0]);
intelmaddata->input_sel = uval->value.enumerated.item[0];
break;
case LINEOUT_SEL_MFLD:
ret_val = scard_ops->set_lineout_dev(
uval->value.enumerated.item[0]);
intelmaddata->lineout_sel = uval->value.enumerated.item[0];
break;
default:
return -EINVAL;
}
kcontrol->private_value = uval->value.enumerated.item[0];
return ret_val;
}
static int snd_intelmad_device_dmic_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uval)
{
struct snd_intelmad *intelmaddata;
struct snd_pmic_ops *scard_ops;
WARN_ON(!uval);
WARN_ON(!kcontrol);
intelmaddata = kcontrol->private_data;
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
if (scard_ops->input_dev_id != DMIC) {
pr_debug("input dev = 0x%x\n", scard_ops->input_dev_id);
return 0;
}
if (intelmaddata->cpu_id == CPU_CHIP_PENWELL)
uval->value.enumerated.item[0] = kcontrol->private_value;
else
pr_debug(" CPU id = 0x%xis invalid.\n",
intelmaddata->cpu_id);
return 0;
}
void msic_set_bit(u8 index, unsigned int *available_dmics)
{
*available_dmics |= (1 << index);
}
void msic_clear_bit(u8 index, unsigned int *available_dmics)
{
*available_dmics &= ~(1 << index);
}
int msic_is_set_bit(u8 index, unsigned int *available_dmics)
{
int ret_val;
ret_val = (*available_dmics & (1 << index));
return ret_val;
}
static int snd_intelmad_device_dmic_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uval)
{
struct snd_intelmad *intelmaddata;
struct snd_pmic_ops *scard_ops;
int i, dmic_index;
unsigned int available_dmics;
int jump_count;
int max_dmics = ARRAY_SIZE(router_dmics);
WARN_ON(!uval);
WARN_ON(!kcontrol);
intelmaddata = kcontrol->private_data;
WARN_ON(!intelmaddata->sstdrv_ops);
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
WARN_ON(!scard_ops);
if (scard_ops->input_dev_id != DMIC) {
pr_debug("input dev = 0x%x\n", scard_ops->input_dev_id);
return 0;
}
available_dmics = scard_ops->available_dmics;
if (kcontrol->private_value > uval->value.enumerated.item[0]) {
pr_debug("jump count -1.\n");
jump_count = -1;
} else {
pr_debug("jump count 1.\n");
jump_count = 1;
}
dmic_index = uval->value.enumerated.item[0];
pr_debug("set function. dmic_index = %d, avl_dmic = 0x%x\n",
dmic_index, available_dmics);
for (i = 0; i < max_dmics; i++) {
pr_debug("set function. loop index = 0x%x. dmic_index = 0x%x\n",
i, dmic_index);
if (!msic_is_set_bit(dmic_index, &available_dmics)) {
msic_clear_bit(kcontrol->private_value,
&available_dmics);
msic_set_bit(dmic_index, &available_dmics);
kcontrol->private_value = dmic_index;
scard_ops->available_dmics = available_dmics;
scard_ops->hw_dmic_map[kcontrol->id.numid-HW_CH_BASE] =
kcontrol->private_value;
scard_ops->set_hw_dmic_route
(kcontrol->id.numid-HW_CH_BASE);
return 0;
}
dmic_index += jump_count;
if (dmic_index > (max_dmics - 1) && jump_count == 1) {
pr_debug("Resettingthe dmic index to 0.\n");
dmic_index = 0;
} else if (dmic_index == -1 && jump_count == -1) {
pr_debug("Resetting the dmic index to 5.\n");
dmic_index = max_dmics - 1;
}
}
return -EINVAL;
}
static int snd_intelmad_device_dmic_info_mfld(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_intelmad *intelmaddata;
struct snd_pmic_ops *scard_ops;
uinfo->count = MONO_CNTL;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->value.enumerated.items = ARRAY_SIZE(router_dmics);
intelmaddata = kcontrol->private_data;
WARN_ON(!intelmaddata->sstdrv_ops);
scard_ops = intelmaddata->sstdrv_ops->scard_ops;
WARN_ON(!scard_ops);
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item =
uinfo->value.enumerated.items - 1;
strncpy(uinfo->value.enumerated.name,
router_dmics[uinfo->value.enumerated.item],
sizeof(uinfo->value.enumerated.name)-1);
msic_set_bit(kcontrol->private_value, &scard_ops->available_dmics);
pr_debug("info function. avl_dmic = 0x%x",
scard_ops->available_dmics);
scard_ops->hw_dmic_map[kcontrol->id.numid-HW_CH_BASE] =
kcontrol->private_value;
return 0;
}
