int mc_get_version(struct fsl_mc_io *mc_io,
u32 cmd_flags,
struct mc_version *mc_ver_info)
{
struct mc_command cmd = { 0 };
struct dpmng_rsp_get_version *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPMNG_CMDID_GET_VERSION,
cmd_flags,
0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpmng_rsp_get_version *)cmd.params;
mc_ver_info->revision = le32_to_cpu(rsp_params->revision);
mc_ver_info->major = le32_to_cpu(rsp_params->version_major);
mc_ver_info->minor = le32_to_cpu(rsp_params->version_minor);
return 0;
}
int dpmng_get_container_id(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int *container_id)
{
struct mc_command cmd = { 0 };
struct dpmng_rsp_get_container_id *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPMNG_CMDID_GET_CONT_ID,
cmd_flags,
0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpmng_rsp_get_container_id *)cmd.params;
*container_id = le32_to_cpu(rsp_params->container_id);
return 0;
}
