int dpio_open(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int dpio_id,
u16 *token)
{
struct mc_command cmd = { 0 };
struct dpio_cmd_open *dpio_cmd;
int err;
cmd.header = mc_encode_cmd_header(DPIO_CMDID_OPEN,
cmd_flags,
0);
dpio_cmd = (struct dpio_cmd_open *)cmd.params;
dpio_cmd->dpio_id = cpu_to_le32(dpio_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = mc_cmd_hdr_read_token(&cmd);
return 0;
}
int dpio_close(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPIO_CMDID_CLOSE,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpio_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPIO_CMDID_ENABLE,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpio_disable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPIO_CMDID_DISABLE,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpio_get_attributes(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpio_attr *attr)
{
struct mc_command cmd = { 0 };
struct dpio_rsp_get_attr *dpio_rsp;
int err;
cmd.header = mc_encode_cmd_header(DPIO_CMDID_GET_ATTR,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
dpio_rsp = (struct dpio_rsp_get_attr *)cmd.params;
attr->id = le32_to_cpu(dpio_rsp->id);
attr->qbman_portal_id = le16_to_cpu(dpio_rsp->qbman_portal_id);
attr->num_priorities = dpio_rsp->num_priorities;
attr->channel_mode = dpio_rsp->channel_mode & DPIO_CHANNEL_MODE_MASK;
attr->qbman_portal_ce_offset =
le64_to_cpu(dpio_rsp->qbman_portal_ce_addr);
attr->qbman_portal_ci_offset =
le64_to_cpu(dpio_rsp->qbman_portal_ci_addr);
attr->qbman_version = le32_to_cpu(dpio_rsp->qbman_version);
return 0;
}
int dpio_get_api_version(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 *major_ver,
u16 *minor_ver)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPIO_CMDID_GET_API_VERSION,
cmd_flags, 0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
mc_cmd_read_api_version(&cmd, major_ver, minor_ver);
return 0;
}
