int dpmcp_open(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int dpmcp_id,
u16 *token)
{
struct mc_command cmd = { 0 };
struct dpmcp_cmd_open *cmd_params;
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_OPEN,
cmd_flags, 0);
cmd_params = (struct dpmcp_cmd_open *)cmd.params;
cmd_params->dpmcp_id = cpu_to_le32(dpmcp_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = mc_cmd_hdr_read_token(&cmd);
return err;
}
int dpmcp_close(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_CLOSE,
cmd_flags, token);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_reset(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_RESET,
cmd_flags, token);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_api_version(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 *major_ver,
u16 *minor_ver)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_API_VERSION,
cmd_flags, 0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
mc_cmd_read_api_version(&cmd, major_ver, minor_ver);
return 0;
}
