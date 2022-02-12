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
int dpbp_create(struct fsl_mc_io *mc_io,
u16 dprc_token,
u32 cmd_flags,
const struct dpbp_cfg *cfg,
u32 *obj_id)
{
struct mc_command cmd = { 0 };
int err;
(void)(cfg);
cmd.header = mc_encode_cmd_header(DPBP_CMDID_CREATE,
cmd_flags, dprc_token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*obj_id = mc_cmd_read_object_id(&cmd);
return 0;
}
int dpbp_destroy(struct fsl_mc_io *mc_io,
u16 dprc_token,
u32 cmd_flags,
u32 obj_id)
{
struct dpbp_cmd_destroy *cmd_params;
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPBP_CMDID_DESTROY,
cmd_flags, dprc_token);
cmd_params = (struct dpbp_cmd_destroy *)cmd.params;
cmd_params->object_id = cpu_to_le32(obj_id);
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
int dpbp_set_irq(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
struct dpbp_irq_cfg *irq_cfg)
{
struct mc_command cmd = { 0 };
struct dpbp_cmd_set_irq *cmd_params;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_SET_IRQ,
cmd_flags, token);
cmd_params = (struct dpbp_cmd_set_irq *)cmd.params;
cmd_params->irq_index = irq_index;
cmd_params->irq_val = cpu_to_le32(irq_cfg->val);
cmd_params->irq_addr = cpu_to_le64(irq_cfg->addr);
cmd_params->irq_num = cpu_to_le32(irq_cfg->irq_num);
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
struct dpbp_cmd_get_irq *cmd_params;
struct dpbp_rsp_get_irq *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_IRQ,
cmd_flags, token);
cmd_params = (struct dpbp_cmd_get_irq *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpbp_rsp_get_irq *)cmd.params;
irq_cfg->val = le32_to_cpu(rsp_params->irq_val);
irq_cfg->addr = le64_to_cpu(rsp_params->irq_addr);
irq_cfg->irq_num = le32_to_cpu(rsp_params->irq_num);
*type = le32_to_cpu(rsp_params->type);
return 0;
}
int dpbp_set_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 en)
{
struct mc_command cmd = { 0 };
struct dpbp_cmd_set_irq_enable *cmd_params;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_SET_IRQ_ENABLE,
cmd_flags, token);
cmd_params = (struct dpbp_cmd_set_irq_enable *)cmd.params;
cmd_params->enable = en & DPBP_ENABLE;
cmd_params->irq_index = irq_index;
return mc_send_command(mc_io, &cmd);
}
int dpbp_get_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 *en)
{
struct mc_command cmd = { 0 };
struct dpbp_cmd_get_irq_enable *cmd_params;
struct dpbp_rsp_get_irq_enable *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_IRQ_ENABLE,
cmd_flags, token);
cmd_params = (struct dpbp_cmd_get_irq_enable *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpbp_rsp_get_irq_enable *)cmd.params;
*en = rsp_params->enabled & DPBP_ENABLE;
return 0;
}
int dpbp_set_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 mask)
{
struct mc_command cmd = { 0 };
struct dpbp_cmd_set_irq_mask *cmd_params;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_SET_IRQ_MASK,
cmd_flags, token);
cmd_params = (struct dpbp_cmd_set_irq_mask *)cmd.params;
cmd_params->mask = cpu_to_le32(mask);
cmd_params->irq_index = irq_index;
return mc_send_command(mc_io, &cmd);
}
int dpbp_get_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *mask)
{
struct mc_command cmd = { 0 };
struct dpbp_cmd_get_irq_mask *cmd_params;
struct dpbp_rsp_get_irq_mask *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_IRQ_MASK,
cmd_flags, token);
cmd_params = (struct dpbp_cmd_get_irq_mask *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpbp_rsp_get_irq_mask *)cmd.params;
*mask = le32_to_cpu(rsp_params->mask);
return 0;
}
int dpbp_get_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *status)
{
struct mc_command cmd = { 0 };
struct dpbp_cmd_get_irq_status *cmd_params;
struct dpbp_rsp_get_irq_status *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_IRQ_STATUS,
cmd_flags, token);
cmd_params = (struct dpbp_cmd_get_irq_status *)cmd.params;
cmd_params->status = cpu_to_le32(*status);
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpbp_rsp_get_irq_status *)cmd.params;
*status = le32_to_cpu(rsp_params->status);
return 0;
}
int dpbp_clear_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 status)
{
struct mc_command cmd = { 0 };
struct dpbp_cmd_clear_irq_status *cmd_params;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_CLEAR_IRQ_STATUS,
cmd_flags, token);
cmd_params = (struct dpbp_cmd_clear_irq_status *)cmd.params;
cmd_params->status = cpu_to_le32(status);
cmd_params->irq_index = irq_index;
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
int dpbp_set_notifications(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpbp_notification_cfg *cfg)
{
struct mc_command cmd = { 0 };
struct dpbp_cmd_set_notifications *cmd_params;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_SET_NOTIFICATIONS,
cmd_flags, token);
cmd_params = (struct dpbp_cmd_set_notifications *)cmd.params;
cmd_params->depletion_entry = cpu_to_le32(cfg->depletion_entry);
cmd_params->depletion_exit = cpu_to_le32(cfg->depletion_exit);
cmd_params->surplus_entry = cpu_to_le32(cfg->surplus_entry);
cmd_params->surplus_exit = cpu_to_le32(cfg->surplus_exit);
cmd_params->options = cpu_to_le16(cfg->options);
cmd_params->message_ctx = cpu_to_le64(cfg->message_ctx);
cmd_params->message_iova = cpu_to_le64(cfg->message_iova);
return mc_send_command(mc_io, &cmd);
}
int dpbp_get_notifications(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpbp_notification_cfg *cfg)
{
struct mc_command cmd = { 0 };
struct dpbp_rsp_get_notifications *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPBP_CMDID_GET_NOTIFICATIONS,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpbp_rsp_get_notifications *)cmd.params;
cfg->depletion_entry = le32_to_cpu(rsp_params->depletion_entry);
cfg->depletion_exit = le32_to_cpu(rsp_params->depletion_exit);
cfg->surplus_entry = le32_to_cpu(rsp_params->surplus_entry);
cfg->surplus_exit = le32_to_cpu(rsp_params->surplus_exit);
cfg->options = le16_to_cpu(rsp_params->options);
cfg->message_ctx = le64_to_cpu(rsp_params->message_ctx);
cfg->message_iova = le64_to_cpu(rsp_params->message_iova);
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
