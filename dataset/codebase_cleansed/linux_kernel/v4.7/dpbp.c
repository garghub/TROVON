int dpbp_open(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int dpbp_id,
u16 *token)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_OPEN,
cmd_flags, 0);
cmd.params[0] |= mc_enc(0, 32, dpbp_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = MC_CMD_HDR_READ_TOKEN(cmd.header);
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
int dpbp_create(struct fsl_mc_io *mc_io,
u32 cmd_flags,
const struct dpbp_cfg *cfg,
u16 *token)
{
struct mc_command cmd = { 0 };
int err;
(void)(cfg);
cmd.header = mc_encode_cmd_header(DPBP_CMDID_CREATE,
cmd_flags, 0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = MC_CMD_HDR_READ_TOKEN(cmd.header);
return 0;
}
int dpbp_destroy(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_DESTROY,
cmd_flags, token);
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
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_IS_ENABLED, cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*en = (int)mc_dec(cmd.params[0], 0, 1);
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
int dpbp_set_irq(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
struct dpbp_irq_cfg *irq_cfg)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_SET_IRQ,
cmd_flags, token);
cmd.params[0] |= mc_enc(0, 8, irq_index);
cmd.params[0] |= mc_enc(32, 32, irq_cfg->val);
cmd.params[1] |= mc_enc(0, 64, irq_cfg->addr);
cmd.params[2] |= mc_enc(0, 32, irq_cfg->irq_num);
return mc_send_command(mc_io, &cmd);
}
int dpbp_get_irq(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
int *type,
struct dpbp_irq_cfg *irq_cfg)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_IRQ,
cmd_flags, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
irq_cfg->val = (u32)mc_dec(cmd.params[0], 0, 32);
irq_cfg->addr = (u64)mc_dec(cmd.params[1], 0, 64);
irq_cfg->irq_num = (int)mc_dec(cmd.params[2], 0, 32);
*type = (int)mc_dec(cmd.params[2], 32, 32);
return 0;
}
int dpbp_set_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 en)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_SET_IRQ_ENABLE,
cmd_flags, token);
cmd.params[0] |= mc_enc(0, 8, en);
cmd.params[0] |= mc_enc(32, 8, irq_index);
return mc_send_command(mc_io, &cmd);
}
int dpbp_get_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 *en)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_IRQ_ENABLE,
cmd_flags, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*en = (u8)mc_dec(cmd.params[0], 0, 8);
return 0;
}
int dpbp_set_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 mask)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_SET_IRQ_MASK,
cmd_flags, token);
cmd.params[0] |= mc_enc(0, 32, mask);
cmd.params[0] |= mc_enc(32, 8, irq_index);
return mc_send_command(mc_io, &cmd);
}
int dpbp_get_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *mask)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_IRQ_MASK,
cmd_flags, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*mask = (u32)mc_dec(cmd.params[0], 0, 32);
return 0;
}
int dpbp_get_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *status)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_IRQ_STATUS,
cmd_flags, token);
cmd.params[0] |= mc_enc(0, 32, *status);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*status = (u32)mc_dec(cmd.params[0], 0, 32);
return 0;
}
int dpbp_clear_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 status)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_CLEAR_IRQ_STATUS,
cmd_flags, token);
cmd.params[0] |= mc_enc(0, 32, status);
cmd.params[0] |= mc_enc(32, 8, irq_index);
return mc_send_command(mc_io, &cmd);
}
int dpbp_get_attributes(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpbp_attr *attr)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_ATTR,
cmd_flags, token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
attr->bpid = (u16)mc_dec(cmd.params[0], 16, 16);
attr->id = (int)mc_dec(cmd.params[0], 32, 32);
attr->version.major = (u16)mc_dec(cmd.params[1], 0, 16);
attr->version.minor = (u16)mc_dec(cmd.params[1], 16, 16);
return 0;
}
int dpbp_set_notifications(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpbp_notification_cfg *cfg)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_SET_NOTIFICATIONS,
cmd_flags,
token);
cmd.params[0] |= mc_enc(0, 32, cfg->depletion_entry);
cmd.params[0] |= mc_enc(32, 32, cfg->depletion_exit);
cmd.params[1] |= mc_enc(0, 32, cfg->surplus_entry);
cmd.params[1] |= mc_enc(32, 32, cfg->surplus_exit);
cmd.params[2] |= mc_enc(0, 16, cfg->options);
cmd.params[3] |= mc_enc(0, 64, cfg->message_ctx);
cmd.params[4] |= mc_enc(0, 64, cfg->message_iova);
return mc_send_command(mc_io, &cmd);
}
int dpbp_get_notifications(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpbp_notification_cfg *cfg)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_NOTIFICATIONS,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
cfg->depletion_entry = (u32)mc_dec(cmd.params[0], 0, 32);
cfg->depletion_exit = (u32)mc_dec(cmd.params[0], 32, 32);
cfg->surplus_entry = (u32)mc_dec(cmd.params[1], 0, 32);
cfg->surplus_exit = (u32)mc_dec(cmd.params[1], 32, 32);
cfg->options = (u16)mc_dec(cmd.params[2], 0, 16);
cfg->message_ctx = (u64)mc_dec(cmd.params[3], 0, 64);
cfg->message_iova = (u64)mc_dec(cmd.params[4], 0, 64);
return 0;
}
