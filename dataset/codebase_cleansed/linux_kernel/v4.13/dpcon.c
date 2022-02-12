int dpcon_open(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int dpcon_id,
u16 *token)
{
struct mc_command cmd = { 0 };
struct dpcon_cmd_open *dpcon_cmd;
int err;
cmd.header = mc_encode_cmd_header(DPCON_CMDID_OPEN,
cmd_flags,
0);
dpcon_cmd = (struct dpcon_cmd_open *)cmd.params;
dpcon_cmd->dpcon_id = cpu_to_le32(dpcon_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = mc_cmd_hdr_read_token(&cmd);
return 0;
}
int dpcon_close(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPCON_CMDID_CLOSE,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpcon_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPCON_CMDID_ENABLE,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpcon_disable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPCON_CMDID_DISABLE,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpcon_is_enabled(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int *en)
{
struct mc_command cmd = { 0 };
struct dpcon_rsp_is_enabled *dpcon_rsp;
int err;
cmd.header = mc_encode_cmd_header(DPCON_CMDID_IS_ENABLED,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
dpcon_rsp = (struct dpcon_rsp_is_enabled *)cmd.params;
*en = dpcon_rsp->enabled & DPCON_ENABLE;
return 0;
}
int dpcon_reset(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPCON_CMDID_RESET,
cmd_flags, token);
return mc_send_command(mc_io, &cmd);
}
int dpcon_get_attributes(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpcon_attr *attr)
{
struct mc_command cmd = { 0 };
struct dpcon_rsp_get_attr *dpcon_rsp;
int err;
cmd.header = mc_encode_cmd_header(DPCON_CMDID_GET_ATTR,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
dpcon_rsp = (struct dpcon_rsp_get_attr *)cmd.params;
attr->id = le32_to_cpu(dpcon_rsp->id);
attr->qbman_ch_id = le16_to_cpu(dpcon_rsp->qbman_ch_id);
attr->num_priorities = dpcon_rsp->num_priorities;
return 0;
}
int dpcon_set_notification(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpcon_notification_cfg *cfg)
{
struct mc_command cmd = { 0 };
struct dpcon_cmd_set_notification *dpcon_cmd;
cmd.header = mc_encode_cmd_header(DPCON_CMDID_SET_NOTIFICATION,
cmd_flags,
token);
dpcon_cmd = (struct dpcon_cmd_set_notification *)cmd.params;
dpcon_cmd->dpio_id = cpu_to_le32(cfg->dpio_id);
dpcon_cmd->priority = cfg->priority;
dpcon_cmd->user_ctx = cpu_to_le64(cfg->user_ctx);
return mc_send_command(mc_io, &cmd);
}
int dpcon_get_api_version(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 *major_ver,
u16 *minor_ver)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPCON_CMDID_GET_API_VERSION,
cmd_flags, 0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
mc_cmd_read_api_version(&cmd, major_ver, minor_ver);
return 0;
}
