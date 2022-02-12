int mc_get_version(struct fsl_mc_io *mc_io, struct mc_version *mc_ver_info)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMNG_CMDID_GET_VERSION,
MC_CMD_PRI_LOW, 0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
mc_ver_info->revision = mc_dec(cmd.params[0], 0, 32);
mc_ver_info->major = mc_dec(cmd.params[0], 32, 32);
mc_ver_info->minor = mc_dec(cmd.params[1], 0, 32);
return 0;
}
int dpmng_get_container_id(struct fsl_mc_io *mc_io, int *container_id)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMNG_CMDID_GET_CONT_ID,
MC_CMD_PRI_LOW, 0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*container_id = mc_dec(cmd.params[0], 0, 32);
return 0;
}
