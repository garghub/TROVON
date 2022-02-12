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
int sst_dsp_init_v2_dpcm(struct snd_soc_platform *platform)
{
int ret = 0;
struct sst_data *drv = snd_soc_platform_get_drvdata(platform);
drv->byte_stream = devm_kzalloc(platform->dev,
SST_MAX_BIN_BYTES, GFP_KERNEL);
if (!drv->byte_stream)
return -ENOMEM;
ret = sst_algo_control_init(platform->dev);
if (ret)
return ret;
ret = snd_soc_add_platform_controls(platform, sst_algo_controls,
ARRAY_SIZE(sst_algo_controls));
return ret;
}
