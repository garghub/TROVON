static int sst_fill_byte_control(struct sst_data *drv,
u8 ipc_msg, u8 block,
u8 task_id, u8 pipe_id,
u16 len, void *cmd_data)
{
struct snd_sst_bytes_v2 *byte_data = drv->byte_stream;
byte_data->type = SST_CMD_BYTES_SET;
byte_data->ipc_msg = ipc_msg;
byte_data->block = block;
byte_data->task_id = task_id;
byte_data->pipe_id = pipe_id;
if (len > SST_MAX_BIN_BYTES - sizeof(*byte_data)) {
dev_err(&drv->pdev->dev, "command length too big (%u)", len);
return -EINVAL;
}
byte_data->len = len;
memcpy(byte_data->bytes, cmd_data, len);
print_hex_dump_bytes("writing to lpe: ", DUMP_PREFIX_OFFSET,
byte_data, len + sizeof(*byte_data));
return 0;
}
static int sst_fill_and_send_cmd_unlocked(struct sst_data *drv,
u8 ipc_msg, u8 block, u8 task_id, u8 pipe_id,
void *cmd_data, u16 len)
{
int ret = 0;
ret = sst_fill_byte_control(drv, ipc_msg,
block, task_id, pipe_id, len, cmd_data);
if (ret < 0)
return ret;
return sst->ops->send_byte_stream(sst->dev, drv->byte_stream);
}
static int sst_fill_and_send_cmd(struct sst_data *drv,
u8 ipc_msg, u8 block, u8 task_id, u8 pipe_id,
void *cmd_data, u16 len)
{
int ret;
mutex_lock(&drv->lock);
ret = sst_fill_and_send_cmd_unlocked(drv, ipc_msg, block,
task_id, pipe_id, cmd_data, len);
mutex_unlock(&drv->lock);
return ret;
}
static int sst_send_slot_map(struct sst_data *drv)
{
struct sst_param_sba_ssp_slot_map cmd;
SST_FILL_DEFAULT_DESTINATION(cmd.header.dst);
cmd.header.command_id = SBA_SET_SSP_SLOT_MAP;
cmd.header.length = sizeof(struct sst_param_sba_ssp_slot_map)
- sizeof(struct sst_dsp_header);
cmd.param_id = SBA_SET_SSP_SLOT_MAP;
cmd.param_len = sizeof(cmd.rx_slot_map) + sizeof(cmd.tx_slot_map)
+ sizeof(cmd.ssp_index);
cmd.ssp_index = SSP_CODEC;
memcpy(cmd.rx_slot_map, &sst_ssp_tx_map[0], sizeof(cmd.rx_slot_map));
memcpy(cmd.tx_slot_map, &sst_ssp_rx_map[0], sizeof(cmd.tx_slot_map));
return sst_fill_and_send_cmd_unlocked(drv, SST_IPC_IA_SET_PARAMS,
SST_FLAG_BLOCKED, SST_TASK_SBA, 0, &cmd,
sizeof(cmd.header) + cmd.header.length);
}
int sst_slot_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct sst_enum *e = (struct sst_enum *)kcontrol->private_value;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = e->max;
if (uinfo->value.enumerated.item > e->max - 1)
uinfo->value.enumerated.item = e->max - 1;
strcpy(uinfo->value.enumerated.name,
e->texts[uinfo->value.enumerated.item]);
return 0;
}
static int sst_slot_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct sst_enum *e = (void *)kcontrol->private_value;
struct snd_soc_component *c = snd_kcontrol_chip(kcontrol);
struct sst_data *drv = snd_soc_component_get_drvdata(c);
unsigned int ctl_no = e->reg;
unsigned int is_tx = e->tx;
unsigned int val, mux;
u8 *map = is_tx ? sst_ssp_rx_map : sst_ssp_tx_map;
mutex_lock(&drv->lock);
val = 1 << ctl_no;
for (mux = e->max; mux > 0; mux--)
if (map[mux - 1] & val)
break;
ucontrol->value.enumerated.item[0] = mux;
mutex_unlock(&drv->lock);
dev_dbg(c->dev, "%s - %s map = %#x\n",
is_tx ? "tx channel" : "rx slot",
e->texts[mux], mux ? map[mux - 1] : -1);
return 0;
}
static int sst_check_and_send_slot_map(struct sst_data *drv, struct snd_kcontrol *kcontrol)
{
struct sst_enum *e = (void *)kcontrol->private_value;
int ret = 0;
if (e->w && e->w->power)
ret = sst_send_slot_map(drv);
else
dev_err(&drv->pdev->dev, "Slot control: %s doesn't have DAPM widget!!!\n",
kcontrol->id.name);
return ret;
}
static int sst_slot_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *c = snd_soc_kcontrol_component(kcontrol);
struct sst_data *drv = snd_soc_component_get_drvdata(c);
struct sst_enum *e = (void *)kcontrol->private_value;
int i, ret = 0;
unsigned int ctl_no = e->reg;
unsigned int is_tx = e->tx;
unsigned int slot_channel_no;
unsigned int val, mux;
u8 *map;
map = is_tx ? sst_ssp_rx_map : sst_ssp_tx_map;
val = 1 << ctl_no;
mux = ucontrol->value.enumerated.item[0];
if (mux > e->max - 1)
return -EINVAL;
mutex_lock(&drv->lock);
for (i = 0; i < e->max; i++)
map[i] &= ~val;
if (mux == 0) {
ret = sst_check_and_send_slot_map(drv, kcontrol);
mutex_unlock(&drv->lock);
return ret;
}
slot_channel_no = mux - 1;
map[slot_channel_no] |= val;
dev_dbg(c->dev, "%s %s map = %#x\n",
is_tx ? "tx channel" : "rx slot",
e->texts[mux], map[slot_channel_no]);
ret = sst_check_and_send_slot_map(drv, kcontrol);
mutex_unlock(&drv->lock);
return ret;
}
static int sst_send_algo_cmd(struct sst_data *drv,
struct sst_algo_control *bc)
{
int len, ret = 0;
struct sst_cmd_set_params *cmd;
len = sizeof(cmd->dst) + sizeof(cmd->command_id) + bc->max;
cmd = kzalloc(len, GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
SST_FILL_DESTINATION(2, cmd->dst, bc->pipe_id, bc->module_id);
cmd->command_id = bc->cmd_id;
memcpy(cmd->params, bc->params, bc->max);
ret = sst_fill_and_send_cmd_unlocked(drv, SST_IPC_IA_SET_PARAMS,
SST_FLAG_BLOCKED, bc->task_id, 0, cmd, len);
kfree(cmd);
return ret;
}
static int sst_find_and_send_pipe_algo(struct sst_data *drv,
const char *pipe, struct sst_ids *ids)
{
int ret = 0;
struct sst_algo_control *bc;
struct sst_module *algo = NULL;
dev_dbg(&drv->pdev->dev, "Enter: widget=%s\n", pipe);
list_for_each_entry(algo, &ids->algo_list, node) {
bc = (void *)algo->kctl->private_value;
dev_dbg(&drv->pdev->dev, "Found algo control name=%s pipe=%s\n",
algo->kctl->id.name, pipe);
ret = sst_send_algo_cmd(drv, bc);
if (ret)
return ret;
}
return ret;
}
static int sst_algo_bytes_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct sst_algo_control *bc = (void *)kcontrol->private_value;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
uinfo->count = bc->max;
return 0;
}
static int sst_algo_control_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct sst_algo_control *bc = (void *)kcontrol->private_value;
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
switch (bc->type) {
case SST_ALGO_PARAMS:
memcpy(ucontrol->value.bytes.data, bc->params, bc->max);
break;
default:
dev_err(component->dev, "Invalid Input- algo type:%d\n",
bc->type);
return -EINVAL;
}
return 0;
}
static int sst_algo_control_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int ret = 0;
struct snd_soc_component *cmpnt = snd_soc_kcontrol_component(kcontrol);
struct sst_data *drv = snd_soc_component_get_drvdata(cmpnt);
struct sst_algo_control *bc = (void *)kcontrol->private_value;
dev_dbg(cmpnt->dev, "control_name=%s\n", kcontrol->id.name);
mutex_lock(&drv->lock);
switch (bc->type) {
case SST_ALGO_PARAMS:
memcpy(bc->params, ucontrol->value.bytes.data, bc->max);
break;
default:
mutex_unlock(&drv->lock);
dev_err(cmpnt->dev, "Invalid Input- algo type:%d\n",
bc->type);
return -EINVAL;
}
if (bc->w && bc->w->power)
ret = sst_send_algo_cmd(drv, bc);
mutex_unlock(&drv->lock);
return ret;
}
static int sst_gain_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct sst_gain_mixer_control *mc = (void *)kcontrol->private_value;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = mc->stereo ? 2 : 1;
uinfo->value.integer.min = mc->min;
uinfo->value.integer.max = mc->max;
return 0;
}
static int sst_send_gain_cmd(struct sst_data *drv, struct sst_gain_value *gv,
u16 task_id, u16 loc_id, u16 module_id, int mute)
{
struct sst_cmd_set_gain_dual cmd;
dev_dbg(&drv->pdev->dev, "Enter\n");
cmd.header.command_id = MMX_SET_GAIN;
SST_FILL_DEFAULT_DESTINATION(cmd.header.dst);
cmd.gain_cell_num = 1;
if (mute || gv->mute) {
cmd.cell_gains[0].cell_gain_left = SST_GAIN_MIN_VALUE;
cmd.cell_gains[0].cell_gain_right = SST_GAIN_MIN_VALUE;
} else {
cmd.cell_gains[0].cell_gain_left = gv->l_gain;
cmd.cell_gains[0].cell_gain_right = gv->r_gain;
}
SST_FILL_DESTINATION(2, cmd.cell_gains[0].dest,
loc_id, module_id);
cmd.cell_gains[0].gain_time_constant = gv->ramp_duration;
cmd.header.length = sizeof(struct sst_cmd_set_gain_dual)
- sizeof(struct sst_dsp_header);
return sst_fill_and_send_cmd_unlocked(drv, SST_IPC_IA_SET_PARAMS,
SST_FLAG_BLOCKED, task_id, 0, &cmd,
sizeof(cmd.header) + cmd.header.length);
}
static int sst_gain_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct sst_gain_mixer_control *mc = (void *)kcontrol->private_value;
struct sst_gain_value *gv = mc->gain_val;
switch (mc->type) {
case SST_GAIN_TLV:
ucontrol->value.integer.value[0] = gv->l_gain;
ucontrol->value.integer.value[1] = gv->r_gain;
break;
case SST_GAIN_MUTE:
ucontrol->value.integer.value[0] = gv->mute ? 1 : 0;
break;
case SST_GAIN_RAMP_DURATION:
ucontrol->value.integer.value[0] = gv->ramp_duration;
break;
default:
dev_err(component->dev, "Invalid Input- gain type:%d\n",
mc->type);
return -EINVAL;
}
return 0;
}
static int sst_gain_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int ret = 0;
struct snd_soc_component *cmpnt = snd_soc_kcontrol_component(kcontrol);
struct sst_data *drv = snd_soc_component_get_drvdata(cmpnt);
struct sst_gain_mixer_control *mc = (void *)kcontrol->private_value;
struct sst_gain_value *gv = mc->gain_val;
mutex_lock(&drv->lock);
switch (mc->type) {
case SST_GAIN_TLV:
gv->l_gain = ucontrol->value.integer.value[0];
gv->r_gain = ucontrol->value.integer.value[1];
dev_dbg(cmpnt->dev, "%s: Volume %d, %d\n",
mc->pname, gv->l_gain, gv->r_gain);
break;
case SST_GAIN_MUTE:
gv->mute = !!ucontrol->value.integer.value[0];
dev_dbg(cmpnt->dev, "%s: Mute %d\n", mc->pname, gv->mute);
break;
case SST_GAIN_RAMP_DURATION:
gv->ramp_duration = ucontrol->value.integer.value[0];
dev_dbg(cmpnt->dev, "%s: Ramp Delay%d\n",
mc->pname, gv->ramp_duration);
break;
default:
mutex_unlock(&drv->lock);
dev_err(cmpnt->dev, "Invalid Input- gain type:%d\n",
mc->type);
return -EINVAL;
}
if (mc->w && mc->w->power)
ret = sst_send_gain_cmd(drv, gv, mc->task_id,
mc->pipe_id | mc->instance_id, mc->module_id, 0);
mutex_unlock(&drv->lock);
return ret;
}
static int sst_send_pipe_module_params(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol)
{
struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
struct sst_data *drv = snd_soc_component_get_drvdata(c);
struct sst_ids *ids = w->priv;
mutex_lock(&drv->lock);
sst_find_and_send_pipe_algo(drv, w->name, ids);
sst_set_pipe_gain(ids, drv, 0);
mutex_unlock(&drv->lock);
return 0;
}
static int sst_generic_modules_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
if (SND_SOC_DAPM_EVENT_ON(event))
return sst_send_pipe_module_params(w, k);
return 0;
}
static int fill_swm_input(struct snd_soc_component *cmpnt,
struct swm_input_ids *swm_input, unsigned int reg)
{
uint i, is_set, nb_inputs = 0;
u16 input_loc_id;
dev_dbg(cmpnt->dev, "reg: %#x\n", reg);
for (i = 0; i < SST_SWM_INPUT_COUNT; i++) {
is_set = reg & BIT(i);
if (!is_set)
continue;
input_loc_id = swm_mixer_input_ids[i];
SST_FILL_DESTINATION(2, swm_input->input_id,
input_loc_id, SST_DEFAULT_MODULE_ID);
nb_inputs++;
swm_input++;
dev_dbg(cmpnt->dev, "input id: %#x, nb_inputs: %d\n",
input_loc_id, nb_inputs);
if (nb_inputs == SST_CMD_SWM_MAX_INPUTS) {
dev_warn(cmpnt->dev, "SET_SWM cmd max inputs reached");
break;
}
}
return nb_inputs;
}
static int sst_set_pipe_gain(struct sst_ids *ids,
struct sst_data *drv, int mute)
{
int ret = 0;
struct sst_gain_mixer_control *mc;
struct sst_gain_value *gv;
struct sst_module *gain = NULL;
list_for_each_entry(gain, &ids->gain_list, node) {
struct snd_kcontrol *kctl = gain->kctl;
dev_dbg(&drv->pdev->dev, "control name=%s\n", kctl->id.name);
mc = (void *)kctl->private_value;
gv = mc->gain_val;
ret = sst_send_gain_cmd(drv, gv, mc->task_id,
mc->pipe_id | mc->instance_id, mc->module_id, mute);
if (ret)
return ret;
}
return ret;
}
static int sst_swm_mixer_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct sst_cmd_set_swm cmd;
struct snd_soc_component *cmpnt = snd_soc_dapm_to_component(w->dapm);
struct sst_data *drv = snd_soc_component_get_drvdata(cmpnt);
struct sst_ids *ids = w->priv;
bool set_mixer = false;
struct soc_mixer_control *mc;
int val = 0;
int i = 0;
dev_dbg(cmpnt->dev, "widget = %s\n", w->name);
for (i = 0; i < w->num_kcontrols; i++) {
if (dapm_kcontrol_get_value(w->kcontrols[i])) {
mc = (struct soc_mixer_control *)(w->kcontrols[i])->private_value;
val |= 1 << mc->shift;
}
}
dev_dbg(cmpnt->dev, "val = %#x\n", val);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
case SND_SOC_DAPM_POST_PMD:
set_mixer = true;
break;
case SND_SOC_DAPM_POST_REG:
if (w->power)
set_mixer = true;
break;
default:
set_mixer = false;
}
if (set_mixer == false)
return 0;
if (SND_SOC_DAPM_EVENT_ON(event) ||
event == SND_SOC_DAPM_POST_REG)
cmd.switch_state = SST_SWM_ON;
else
cmd.switch_state = SST_SWM_OFF;
SST_FILL_DEFAULT_DESTINATION(cmd.header.dst);
cmd.header.command_id = SBA_SET_SWM;
SST_FILL_DESTINATION(2, cmd.output_id,
ids->location_id, SST_DEFAULT_MODULE_ID);
cmd.nb_inputs = fill_swm_input(cmpnt, &cmd.input[0], val);
cmd.header.length = offsetof(struct sst_cmd_set_swm, input)
- sizeof(struct sst_dsp_header)
+ (cmd.nb_inputs * sizeof(cmd.input[0]));
return sst_fill_and_send_cmd(drv, SST_IPC_IA_CMD, SST_FLAG_BLOCKED,
ids->task_id, 0, &cmd,
sizeof(cmd.header) + cmd.header.length);
}
int sst_handle_vb_timer(struct snd_soc_dai *dai, bool enable)
{
int ret = 0;
struct sst_cmd_generic cmd;
struct sst_data *drv = snd_soc_dai_get_drvdata(dai);
static int timer_usage;
if (enable)
cmd.header.command_id = SBA_VB_START;
else
cmd.header.command_id = SBA_IDLE;
dev_dbg(dai->dev, "enable=%u, usage=%d\n", enable, timer_usage);
SST_FILL_DEFAULT_DESTINATION(cmd.header.dst);
cmd.header.length = 0;
if (enable) {
ret = sst->ops->power(sst->dev, true);
if (ret < 0)
return ret;
}
mutex_lock(&drv->lock);
if (enable)
timer_usage++;
else
timer_usage--;
if ((enable && (timer_usage == 1)) ||
(!enable && (timer_usage == 0))) {
ret = sst_fill_and_send_cmd_unlocked(drv, SST_IPC_IA_CMD,
SST_FLAG_BLOCKED, SST_TASK_SBA, 0, &cmd,
sizeof(cmd.header) + cmd.header.length);
if (ret && enable) {
timer_usage--;
enable = false;
}
}
mutex_unlock(&drv->lock);
if (!enable)
sst->ops->power(sst->dev, false);
return ret;
}
int sst_fill_ssp_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct sst_data *ctx = snd_soc_dai_get_drvdata(dai);
ctx->ssp_cmd.nb_slots = slots;
ctx->ssp_cmd.active_tx_slot_map = tx_mask;
ctx->ssp_cmd.active_rx_slot_map = rx_mask;
ctx->ssp_cmd.nb_bits_per_slots = slot_width;
return 0;
}
static int sst_get_frame_sync_polarity(struct snd_soc_dai *dai,
unsigned int fmt)
{
int format;
format = fmt & SND_SOC_DAIFMT_INV_MASK;
dev_dbg(dai->dev, "Enter:%s, format=%x\n", __func__, format);
switch (format) {
case SND_SOC_DAIFMT_NB_NF:
return SSP_FS_ACTIVE_LOW;
case SND_SOC_DAIFMT_NB_IF:
return SSP_FS_ACTIVE_HIGH;
case SND_SOC_DAIFMT_IB_IF:
return SSP_FS_ACTIVE_LOW;
case SND_SOC_DAIFMT_IB_NF:
return SSP_FS_ACTIVE_HIGH;
default:
dev_err(dai->dev, "Invalid frame sync polarity %d\n", format);
}
return -EINVAL;
}
static int sst_get_ssp_mode(struct snd_soc_dai *dai, unsigned int fmt)
{
int format;
format = (fmt & SND_SOC_DAIFMT_MASTER_MASK);
dev_dbg(dai->dev, "Enter:%s, format=%x\n", __func__, format);
switch (format) {
case SND_SOC_DAIFMT_CBS_CFS:
return SSP_MODE_MASTER;
case SND_SOC_DAIFMT_CBM_CFM:
return SSP_MODE_SLAVE;
default:
dev_err(dai->dev, "Invalid ssp protocol: %d\n", format);
}
return -EINVAL;
}
int sst_fill_ssp_config(struct snd_soc_dai *dai, unsigned int fmt)
{
unsigned int mode;
int fs_polarity;
struct sst_data *ctx = snd_soc_dai_get_drvdata(dai);
mode = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
switch (mode) {
case SND_SOC_DAIFMT_DSP_B:
ctx->ssp_cmd.ssp_protocol = SSP_MODE_PCM;
ctx->ssp_cmd.mode = sst_get_ssp_mode(dai, fmt) | (SSP_PCM_MODE_NETWORK << 1);
ctx->ssp_cmd.start_delay = 0;
ctx->ssp_cmd.data_polarity = 1;
ctx->ssp_cmd.frame_sync_width = 1;
break;
case SND_SOC_DAIFMT_DSP_A:
ctx->ssp_cmd.ssp_protocol = SSP_MODE_PCM;
ctx->ssp_cmd.mode = sst_get_ssp_mode(dai, fmt) | (SSP_PCM_MODE_NETWORK << 1);
ctx->ssp_cmd.start_delay = 1;
ctx->ssp_cmd.data_polarity = 1;
ctx->ssp_cmd.frame_sync_width = 1;
break;
case SND_SOC_DAIFMT_I2S:
ctx->ssp_cmd.ssp_protocol = SSP_MODE_I2S;
ctx->ssp_cmd.mode = sst_get_ssp_mode(dai, fmt) | (SSP_PCM_MODE_NORMAL << 1);
ctx->ssp_cmd.start_delay = 1;
ctx->ssp_cmd.data_polarity = 0;
ctx->ssp_cmd.frame_sync_width = ctx->ssp_cmd.nb_bits_per_slots;
break;
case SND_SOC_DAIFMT_LEFT_J:
ctx->ssp_cmd.ssp_protocol = SSP_MODE_I2S;
ctx->ssp_cmd.mode = sst_get_ssp_mode(dai, fmt) | (SSP_PCM_MODE_NORMAL << 1);
ctx->ssp_cmd.start_delay = 0;
ctx->ssp_cmd.data_polarity = 0;
ctx->ssp_cmd.frame_sync_width = ctx->ssp_cmd.nb_bits_per_slots;
break;
default:
dev_dbg(dai->dev, "using default ssp configs\n");
}
fs_polarity = sst_get_frame_sync_polarity(dai, fmt);
if (fs_polarity < 0)
return fs_polarity;
ctx->ssp_cmd.frame_sync_polarity = fs_polarity;
return 0;
}
void sst_fill_ssp_defaults(struct snd_soc_dai *dai)
{
const struct sst_ssp_config *config;
struct sst_data *ctx = snd_soc_dai_get_drvdata(dai);
config = &sst_ssp_configs;
ctx->ssp_cmd.selection = config->ssp_id;
ctx->ssp_cmd.nb_bits_per_slots = config->bits_per_slot;
ctx->ssp_cmd.nb_slots = config->slots;
ctx->ssp_cmd.mode = config->ssp_mode | (config->pcm_mode << 1);
ctx->ssp_cmd.duplex = config->duplex;
ctx->ssp_cmd.active_tx_slot_map = config->active_slot_map;
ctx->ssp_cmd.active_rx_slot_map = config->active_slot_map;
ctx->ssp_cmd.frame_sync_frequency = config->fs_frequency;
ctx->ssp_cmd.frame_sync_polarity = config->frame_sync_polarity;
ctx->ssp_cmd.data_polarity = config->data_polarity;
ctx->ssp_cmd.frame_sync_width = config->fs_width;
ctx->ssp_cmd.ssp_protocol = config->ssp_protocol;
ctx->ssp_cmd.start_delay = config->start_delay;
ctx->ssp_cmd.reserved1 = ctx->ssp_cmd.reserved2 = 0xFF;
}
int send_ssp_cmd(struct snd_soc_dai *dai, const char *id, bool enable)
{
struct sst_data *drv = snd_soc_dai_get_drvdata(dai);
const struct sst_ssp_config *config;
dev_info(dai->dev, "Enter: enable=%d port_name=%s\n", enable, id);
SST_FILL_DEFAULT_DESTINATION(drv->ssp_cmd.header.dst);
drv->ssp_cmd.header.command_id = SBA_HW_SET_SSP;
drv->ssp_cmd.header.length = sizeof(struct sst_cmd_sba_hw_set_ssp)
- sizeof(struct sst_dsp_header);
config = &sst_ssp_configs;
dev_dbg(dai->dev, "ssp_id: %u\n", config->ssp_id);
if (enable)
drv->ssp_cmd.switch_state = SST_SWITCH_ON;
else
drv->ssp_cmd.switch_state = SST_SWITCH_OFF;
return sst_fill_and_send_cmd(drv, SST_IPC_IA_CMD, SST_FLAG_BLOCKED,
SST_TASK_SBA, 0, &drv->ssp_cmd,
sizeof(drv->ssp_cmd.header) + drv->ssp_cmd.header.length);
}
static int sst_set_be_modules(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
int ret = 0;
struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
struct sst_data *drv = snd_soc_component_get_drvdata(c);
dev_dbg(c->dev, "Enter: widget=%s\n", w->name);
if (SND_SOC_DAPM_EVENT_ON(event)) {
ret = sst_send_slot_map(drv);
if (ret)
return ret;
ret = sst_send_pipe_module_params(w, k);
}
return ret;
}
static int sst_set_media_path(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
int ret = 0;
struct sst_cmd_set_media_path cmd;
struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
struct sst_data *drv = snd_soc_component_get_drvdata(c);
struct sst_ids *ids = w->priv;
dev_dbg(c->dev, "widget=%s\n", w->name);
dev_dbg(c->dev, "task=%u, location=%#x\n",
ids->task_id, ids->location_id);
if (SND_SOC_DAPM_EVENT_ON(event))
cmd.switch_state = SST_PATH_ON;
else
cmd.switch_state = SST_PATH_OFF;
SST_FILL_DESTINATION(2, cmd.header.dst,
ids->location_id, SST_DEFAULT_MODULE_ID);
cmd.header.command_id = MMX_SET_MEDIA_PATH;
cmd.header.length = sizeof(struct sst_cmd_set_media_path)
- sizeof(struct sst_dsp_header);
ret = sst_fill_and_send_cmd(drv, SST_IPC_IA_CMD, SST_FLAG_BLOCKED,
ids->task_id, 0, &cmd,
sizeof(cmd.header) + cmd.header.length);
if (ret)
return ret;
if (SND_SOC_DAPM_EVENT_ON(event))
ret = sst_send_pipe_module_params(w, k);
return ret;
}
static int sst_set_media_loop(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
int ret = 0;
struct sst_cmd_sba_set_media_loop_map cmd;
struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
struct sst_data *drv = snd_soc_component_get_drvdata(c);
struct sst_ids *ids = w->priv;
dev_dbg(c->dev, "Enter:widget=%s\n", w->name);
if (SND_SOC_DAPM_EVENT_ON(event))
cmd.switch_state = SST_SWITCH_ON;
else
cmd.switch_state = SST_SWITCH_OFF;
SST_FILL_DESTINATION(2, cmd.header.dst,
ids->location_id, SST_DEFAULT_MODULE_ID);
cmd.header.command_id = SBA_SET_MEDIA_LOOP_MAP;
cmd.header.length = sizeof(struct sst_cmd_sba_set_media_loop_map)
- sizeof(struct sst_dsp_header);
cmd.param.part.cfg.rate = 2;
cmd.param.part.cfg.format = ids->format;
cmd.param.part.cfg.s_length = 1;
cmd.map = 0;
ret = sst_fill_and_send_cmd(drv, SST_IPC_IA_CMD, SST_FLAG_BLOCKED,
SST_TASK_SBA, 0, &cmd,
sizeof(cmd.header) + cmd.header.length);
if (ret)
return ret;
if (SND_SOC_DAPM_EVENT_ON(event))
ret = sst_send_pipe_module_params(w, k);
return ret;
}
static int sst_algo_control_init(struct device *dev)
{
int i = 0;
struct sst_algo_control *bc;
for (i = 0; i < ARRAY_SIZE(sst_algo_controls); i++) {
bc = (struct sst_algo_control *)sst_algo_controls[i].private_value;
bc->params = devm_kzalloc(dev, bc->max, GFP_KERNEL);
if (bc->params == NULL)
return -ENOMEM;
}
return 0;
}
static bool is_sst_dapm_widget(struct snd_soc_dapm_widget *w)
{
switch (w->id) {
case snd_soc_dapm_pga:
case snd_soc_dapm_aif_in:
case snd_soc_dapm_aif_out:
case snd_soc_dapm_input:
case snd_soc_dapm_output:
case snd_soc_dapm_mixer:
return true;
default:
return false;
}
}
int sst_send_pipe_gains(struct snd_soc_dai *dai, int stream, int mute)
{
struct sst_data *drv = snd_soc_dai_get_drvdata(dai);
struct snd_soc_dapm_widget *w;
struct snd_soc_dapm_path *p = NULL;
dev_dbg(dai->dev, "enter, dai-name=%s dir=%d\n", dai->name, stream);
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
dev_dbg(dai->dev, "Stream name=%s\n",
dai->playback_widget->name);
w = dai->playback_widget;
list_for_each_entry(p, &w->sinks, list_source) {
if (p->connected && !p->connected(w, p->sink))
continue;
if (p->connect && p->sink->power &&
is_sst_dapm_widget(p->sink)) {
struct sst_ids *ids = p->sink->priv;
dev_dbg(dai->dev, "send gains for widget=%s\n",
p->sink->name);
mutex_lock(&drv->lock);
sst_set_pipe_gain(ids, drv, mute);
mutex_unlock(&drv->lock);
}
}
} else {
dev_dbg(dai->dev, "Stream name=%s\n",
dai->capture_widget->name);
w = dai->capture_widget;
list_for_each_entry(p, &w->sources, list_sink) {
if (p->connected && !p->connected(w, p->sink))
continue;
if (p->connect && p->source->power &&
is_sst_dapm_widget(p->source)) {
struct sst_ids *ids = p->source->priv;
dev_dbg(dai->dev, "send gain for widget=%s\n",
p->source->name);
mutex_lock(&drv->lock);
sst_set_pipe_gain(ids, drv, mute);
mutex_unlock(&drv->lock);
}
}
}
return 0;
}
static int sst_fill_module_list(struct snd_kcontrol *kctl,
struct snd_soc_dapm_widget *w, int type)
{
struct sst_module *module = NULL;
struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
struct sst_ids *ids = w->priv;
int ret = 0;
module = devm_kzalloc(c->dev, sizeof(*module), GFP_KERNEL);
if (!module)
return -ENOMEM;
if (type == SST_MODULE_GAIN) {
struct sst_gain_mixer_control *mc = (void *)kctl->private_value;
mc->w = w;
module->kctl = kctl;
list_add_tail(&module->node, &ids->gain_list);
} else if (type == SST_MODULE_ALGO) {
struct sst_algo_control *bc = (void *)kctl->private_value;
bc->w = w;
module->kctl = kctl;
list_add_tail(&module->node, &ids->algo_list);
} else {
dev_err(c->dev, "invoked for unknown type %d module %s",
type, kctl->id.name);
ret = -EINVAL;
}
return ret;
}
static int sst_fill_widget_module_info(struct snd_soc_dapm_widget *w,
struct snd_soc_platform *platform)
{
struct snd_kcontrol *kctl;
int index, ret = 0;
struct snd_card *card = platform->component.card->snd_card;
char *idx;
down_read(&card->controls_rwsem);
list_for_each_entry(kctl, &card->controls, list) {
idx = strchr(kctl->id.name, ' ');
if (idx == NULL)
continue;
index = idx - (char*)kctl->id.name;
if (strncmp(kctl->id.name, w->name, index))
continue;
if (strstr(kctl->id.name, "Volume"))
ret = sst_fill_module_list(kctl, w, SST_MODULE_GAIN);
else if (strstr(kctl->id.name, "params"))
ret = sst_fill_module_list(kctl, w, SST_MODULE_ALGO);
else if (strstr(kctl->id.name, "Switch") &&
strstr(kctl->id.name, "Gain")) {
struct sst_gain_mixer_control *mc =
(void *)kctl->private_value;
mc->w = w;
} else if (strstr(kctl->id.name, "interleaver")) {
struct sst_enum *e = (void *)kctl->private_value;
e->w = w;
} else if (strstr(kctl->id.name, "deinterleaver")) {
struct sst_enum *e = (void *)kctl->private_value;
e->w = w;
}
if (ret < 0) {
up_read(&card->controls_rwsem);
return ret;
}
}
up_read(&card->controls_rwsem);
return 0;
}
static void sst_fill_linked_widgets(struct snd_soc_platform *platform,
struct sst_ids *ids)
{
struct snd_soc_dapm_widget *w;
unsigned int len = strlen(ids->parent_wname);
list_for_each_entry(w, &platform->component.card->widgets, list) {
if (!strncmp(ids->parent_wname, w->name, len)) {
ids->parent_w = w;
break;
}
}
}
static int sst_map_modules_to_pipe(struct snd_soc_platform *platform)
{
struct snd_soc_dapm_widget *w;
int ret = 0;
list_for_each_entry(w, &platform->component.card->widgets, list) {
if (is_sst_dapm_widget(w) && (w->priv)) {
struct sst_ids *ids = w->priv;
dev_dbg(platform->dev, "widget type=%d name=%s\n",
w->id, w->name);
INIT_LIST_HEAD(&ids->algo_list);
INIT_LIST_HEAD(&ids->gain_list);
ret = sst_fill_widget_module_info(w, platform);
if (ret < 0)
return ret;
if (ids->parent_wname != NULL)
sst_fill_linked_widgets(platform, ids);
}
}
return 0;
}
int sst_dsp_init_v2_dpcm(struct snd_soc_platform *platform)
{
int i, ret = 0;
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(&platform->component);
struct sst_data *drv = snd_soc_platform_get_drvdata(platform);
unsigned int gains = ARRAY_SIZE(sst_gain_controls)/3;
drv->byte_stream = devm_kzalloc(platform->dev,
SST_MAX_BIN_BYTES, GFP_KERNEL);
if (!drv->byte_stream)
return -ENOMEM;
snd_soc_dapm_new_controls(dapm, sst_dapm_widgets,
ARRAY_SIZE(sst_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon,
ARRAY_SIZE(intercon));
snd_soc_dapm_new_widgets(dapm->card);
for (i = 0; i < gains; i++) {
sst_gains[i].mute = SST_GAIN_MUTE_DEFAULT;
sst_gains[i].l_gain = SST_GAIN_VOLUME_DEFAULT;
sst_gains[i].r_gain = SST_GAIN_VOLUME_DEFAULT;
sst_gains[i].ramp_duration = SST_GAIN_RAMP_DURATION_DEFAULT;
}
ret = snd_soc_add_platform_controls(platform, sst_gain_controls,
ARRAY_SIZE(sst_gain_controls));
if (ret)
return ret;
ret = sst_algo_control_init(platform->dev);
if (ret)
return ret;
ret = snd_soc_add_platform_controls(platform, sst_algo_controls,
ARRAY_SIZE(sst_algo_controls));
if (ret)
return ret;
ret = snd_soc_add_platform_controls(platform, sst_slot_controls,
ARRAY_SIZE(sst_slot_controls));
if (ret)
return ret;
ret = sst_map_modules_to_pipe(platform);
return ret;
}
