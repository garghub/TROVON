int dpbp_open(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int dpbp_id,
u16 *token)
{
struct mc_command cmd = { 0 };
struct dpbp_cmd_open *cmd_params;
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_OPEN,
cmd_flags, 0);
cmd_params = (struct dpbp_cmd_open *)cmd.params;
cmd_params->dpbp_id = cpu_to_le32(dpbp_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = mc_cmd_hdr_read_token(&cmd);
return err;
}
int dpbp_close(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_CLOSE, cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpbp_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_ENABLE, cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpbp_disable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_DISABLE,
cmd_flags, token);
return mc_send_command(mc_io, &cmd);
}
int dpbp_is_enabled(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int *en)
{
struct mc_command cmd = { 0 };
struct dpbp_rsp_is_enabled *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_IS_ENABLED, cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpbp_rsp_is_enabled *)cmd.params;
*en = rsp_params->enabled & DPBP_ENABLE;
return 0;
}
int dpbp_reset(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_RESET,
cmd_flags, token);
return mc_send_command(mc_io, &cmd);
}
int dpbp_get_attributes(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpbp_attr *attr)
{
struct mc_command cmd = { 0 };
struct dpbp_rsp_get_attributes *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_ATTR,
cmd_flags, token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpbp_rsp_get_attributes *)cmd.params;
attr->bpid = le16_to_cpu(rsp_params->bpid);
attr->id = le32_to_cpu(rsp_params->id);
return 0;
}
int dpbp_get_api_version(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 *major_ver,
u16 *minor_ver)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_API_VERSION,
cmd_flags, 0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
mc_cmd_read_api_version(&cmd, major_ver, minor_ver);
return 0;
}
