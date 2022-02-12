static int mlxfw_fsm_state_wait(struct mlxfw_dev *mlxfw_dev, u32 fwhandle,
enum mlxfw_fsm_state fsm_state)
{
enum mlxfw_fsm_state_err fsm_state_err;
enum mlxfw_fsm_state curr_fsm_state;
int times;
int err;
times = MLXFW_FSM_STATE_WAIT_ROUNDS;
retry:
err = mlxfw_dev->ops->fsm_query_state(mlxfw_dev, fwhandle,
&curr_fsm_state, &fsm_state_err);
if (err)
return err;
if (fsm_state_err != MLXFW_FSM_STATE_ERR_OK) {
pr_err("Firmware flash failed: %s\n",
mlxfw_fsm_state_err_str[fsm_state_err]);
return -EINVAL;
}
if (curr_fsm_state != fsm_state) {
if (--times == 0) {
pr_err("Timeout reached on FSM state change");
return -ETIMEDOUT;
}
msleep(MLXFW_FSM_STATE_WAIT_CYCLE_MS);
goto retry;
}
return 0;
}
static int mlxfw_flash_component(struct mlxfw_dev *mlxfw_dev,
u32 fwhandle,
struct mlxfw_mfa2_component *comp)
{
u16 comp_max_write_size;
u8 comp_align_bits;
u32 comp_max_size;
u16 block_size;
u8 *block_ptr;
u32 offset;
int err;
err = mlxfw_dev->ops->component_query(mlxfw_dev, comp->index,
&comp_max_size, &comp_align_bits,
&comp_max_write_size);
if (err)
return err;
comp_max_size = min_t(u32, comp_max_size, MLXFW_FSM_MAX_COMPONENT_SIZE);
if (comp->data_size > comp_max_size) {
pr_err("Component %d is of size %d which is bigger than limit %d\n",
comp->index, comp->data_size, comp_max_size);
return -EINVAL;
}
comp_max_write_size = MLXFW_ALIGN_DOWN(comp_max_write_size,
comp_align_bits);
pr_debug("Component update\n");
err = mlxfw_dev->ops->fsm_component_update(mlxfw_dev, fwhandle,
comp->index,
comp->data_size);
if (err)
return err;
err = mlxfw_fsm_state_wait(mlxfw_dev, fwhandle,
MLXFW_FSM_STATE_DOWNLOAD);
if (err)
goto err_out;
pr_debug("Component download\n");
for (offset = 0;
offset < MLXFW_ALIGN_UP(comp->data_size, comp_align_bits);
offset += comp_max_write_size) {
block_ptr = comp->data + offset;
block_size = (u16) min_t(u32, comp->data_size - offset,
comp_max_write_size);
err = mlxfw_dev->ops->fsm_block_download(mlxfw_dev, fwhandle,
block_ptr, block_size,
offset);
if (err)
goto err_out;
}
pr_debug("Component verify\n");
err = mlxfw_dev->ops->fsm_component_verify(mlxfw_dev, fwhandle,
comp->index);
if (err)
goto err_out;
err = mlxfw_fsm_state_wait(mlxfw_dev, fwhandle, MLXFW_FSM_STATE_LOCKED);
if (err)
goto err_out;
return 0;
err_out:
mlxfw_dev->ops->fsm_cancel(mlxfw_dev, fwhandle);
return err;
}
static int mlxfw_flash_components(struct mlxfw_dev *mlxfw_dev, u32 fwhandle,
struct mlxfw_mfa2_file *mfa2_file)
{
u32 component_count;
int err;
int i;
err = mlxfw_mfa2_file_component_count(mfa2_file, mlxfw_dev->psid,
mlxfw_dev->psid_size,
&component_count);
if (err) {
pr_err("Could not find device PSID in MFA2 file\n");
return err;
}
for (i = 0; i < component_count; i++) {
struct mlxfw_mfa2_component *comp;
comp = mlxfw_mfa2_file_component_get(mfa2_file, mlxfw_dev->psid,
mlxfw_dev->psid_size, i);
if (IS_ERR(comp))
return PTR_ERR(comp);
pr_info("Flashing component type %d\n", comp->index);
err = mlxfw_flash_component(mlxfw_dev, fwhandle, comp);
mlxfw_mfa2_file_component_put(comp);
if (err)
return err;
}
return 0;
}
int mlxfw_firmware_flash(struct mlxfw_dev *mlxfw_dev,
const struct firmware *firmware)
{
struct mlxfw_mfa2_file *mfa2_file;
u32 fwhandle;
int err;
if (!mlxfw_mfa2_check(firmware)) {
pr_err("Firmware file is not MFA2\n");
return -EINVAL;
}
mfa2_file = mlxfw_mfa2_file_init(firmware);
if (IS_ERR(mfa2_file))
return PTR_ERR(mfa2_file);
pr_info("Initialize firmware flash process\n");
err = mlxfw_dev->ops->fsm_lock(mlxfw_dev, &fwhandle);
if (err) {
pr_err("Could not lock the firmware FSM\n");
goto err_fsm_lock;
}
err = mlxfw_fsm_state_wait(mlxfw_dev, fwhandle,
MLXFW_FSM_STATE_LOCKED);
if (err)
goto err_state_wait_idle_to_locked;
err = mlxfw_flash_components(mlxfw_dev, fwhandle, mfa2_file);
if (err)
goto err_flash_components;
pr_debug("Activate image\n");
err = mlxfw_dev->ops->fsm_activate(mlxfw_dev, fwhandle);
if (err) {
pr_err("Could not activate the downloaded image\n");
goto err_fsm_activate;
}
err = mlxfw_fsm_state_wait(mlxfw_dev, fwhandle, MLXFW_FSM_STATE_LOCKED);
if (err)
goto err_state_wait_activate_to_locked;
pr_debug("Handle release\n");
mlxfw_dev->ops->fsm_release(mlxfw_dev, fwhandle);
pr_info("Firmware flash done.\n");
mlxfw_mfa2_file_fini(mfa2_file);
return 0;
err_state_wait_activate_to_locked:
err_fsm_activate:
err_flash_components:
err_state_wait_idle_to_locked:
mlxfw_dev->ops->fsm_release(mlxfw_dev, fwhandle);
err_fsm_lock:
mlxfw_mfa2_file_fini(mfa2_file);
return err;
}
