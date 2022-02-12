int dpmcp_open(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int dpmcp_id,
u16 *token)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_OPEN,
cmd_flags, 0);
cmd.params[0] |= mc_enc(0, 32, dpmcp_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = MC_CMD_HDR_READ_TOKEN(cmd.header);
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
int dpmcp_create(struct fsl_mc_io *mc_io,
u32 cmd_flags,
const struct dpmcp_cfg *cfg,
u16 *token)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_CREATE,
cmd_flags, 0);
cmd.params[0] |= mc_enc(0, 32, cfg->portal_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = MC_CMD_HDR_READ_TOKEN(cmd.header);
return 0;
}
int dpmcp_destroy(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_DESTROY,
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
int dpmcp_set_irq(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
struct dpmcp_irq_cfg *irq_cfg)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_SET_IRQ,
cmd_flags, token);
cmd.params[0] |= mc_enc(0, 8, irq_index);
cmd.params[0] |= mc_enc(32, 32, irq_cfg->val);
cmd.params[1] |= mc_enc(0, 64, irq_cfg->paddr);
cmd.params[2] |= mc_enc(0, 32, irq_cfg->irq_num);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_irq(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
int *type,
struct dpmcp_irq_cfg *irq_cfg)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ,
cmd_flags, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
irq_cfg->val = (u32)mc_dec(cmd.params[0], 0, 32);
irq_cfg->paddr = (u64)mc_dec(cmd.params[1], 0, 64);
irq_cfg->irq_num = (int)mc_dec(cmd.params[2], 0, 32);
*type = (int)mc_dec(cmd.params[2], 32, 32);
return 0;
}
int dpmcp_set_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 en)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_SET_IRQ_ENABLE,
cmd_flags, token);
cmd.params[0] |= mc_enc(0, 8, en);
cmd.params[0] |= mc_enc(32, 8, irq_index);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 *en)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ_ENABLE,
cmd_flags, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*en = (u8)mc_dec(cmd.params[0], 0, 8);
return 0;
}
int dpmcp_set_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 mask)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_SET_IRQ_MASK,
cmd_flags, token);
cmd.params[0] |= mc_enc(0, 32, mask);
cmd.params[0] |= mc_enc(32, 8, irq_index);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *mask)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ_MASK,
cmd_flags, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*mask = (u32)mc_dec(cmd.params[0], 0, 32);
return 0;
}
int dpmcp_get_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *status)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ_STATUS,
cmd_flags, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*status = (u32)mc_dec(cmd.params[0], 0, 32);
return 0;
}
int dpmcp_get_attributes(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpmcp_attr *attr)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_ATTR,
cmd_flags, token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
attr->id = (int)mc_dec(cmd.params[0], 32, 32);
attr->version.major = (u16)mc_dec(cmd.params[1], 0, 16);
attr->version.minor = (u16)mc_dec(cmd.params[1], 16, 16);
return 0;
}
