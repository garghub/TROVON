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
int dpmcp_create(struct fsl_mc_io *mc_io,
u32 cmd_flags,
const struct dpmcp_cfg *cfg,
u16 *token)
{
struct mc_command cmd = { 0 };
struct dpmcp_cmd_create *cmd_params;
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_CREATE,
cmd_flags, 0);
cmd_params = (struct dpmcp_cmd_create *)cmd.params;
cmd_params->portal_id = cpu_to_le32(cfg->portal_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = mc_cmd_hdr_read_token(&cmd);
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
struct dpmcp_cmd_set_irq *cmd_params;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_SET_IRQ,
cmd_flags, token);
cmd_params = (struct dpmcp_cmd_set_irq *)cmd.params;
cmd_params->irq_index = irq_index;
cmd_params->irq_val = cpu_to_le32(irq_cfg->val);
cmd_params->irq_addr = cpu_to_le64(irq_cfg->paddr);
cmd_params->irq_num = cpu_to_le32(irq_cfg->irq_num);
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
struct dpmcp_cmd_get_irq *cmd_params;
struct dpmcp_rsp_get_irq *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ,
cmd_flags, token);
cmd_params = (struct dpmcp_cmd_get_irq *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpmcp_rsp_get_irq *)cmd.params;
irq_cfg->val = le32_to_cpu(rsp_params->irq_val);
irq_cfg->paddr = le64_to_cpu(rsp_params->irq_paddr);
irq_cfg->irq_num = le32_to_cpu(rsp_params->irq_num);
*type = le32_to_cpu(rsp_params->type);
return 0;
}
int dpmcp_set_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 en)
{
struct mc_command cmd = { 0 };
struct dpmcp_cmd_set_irq_enable *cmd_params;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_SET_IRQ_ENABLE,
cmd_flags, token);
cmd_params = (struct dpmcp_cmd_set_irq_enable *)cmd.params;
cmd_params->enable = en & DPMCP_ENABLE;
cmd_params->irq_index = irq_index;
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 *en)
{
struct mc_command cmd = { 0 };
struct dpmcp_cmd_get_irq_enable *cmd_params;
struct dpmcp_rsp_get_irq_enable *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ_ENABLE,
cmd_flags, token);
cmd_params = (struct dpmcp_cmd_get_irq_enable *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpmcp_rsp_get_irq_enable *)cmd.params;
*en = rsp_params->enabled & DPMCP_ENABLE;
return 0;
}
int dpmcp_set_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 mask)
{
struct mc_command cmd = { 0 };
struct dpmcp_cmd_set_irq_mask *cmd_params;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_SET_IRQ_MASK,
cmd_flags, token);
cmd_params = (struct dpmcp_cmd_set_irq_mask *)cmd.params;
cmd_params->mask = cpu_to_le32(mask);
cmd_params->irq_index = irq_index;
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *mask)
{
struct mc_command cmd = { 0 };
struct dpmcp_cmd_get_irq_mask *cmd_params;
struct dpmcp_rsp_get_irq_mask *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ_MASK,
cmd_flags, token);
cmd_params = (struct dpmcp_cmd_get_irq_mask *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpmcp_rsp_get_irq_mask *)cmd.params;
*mask = le32_to_cpu(rsp_params->mask);
return 0;
}
int dpmcp_get_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *status)
{
struct mc_command cmd = { 0 };
struct dpmcp_cmd_get_irq_status *cmd_params;
struct dpmcp_rsp_get_irq_status *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ_STATUS,
cmd_flags, token);
cmd_params = (struct dpmcp_cmd_get_irq_status *)cmd.params;
cmd_params->status = cpu_to_le32(*status);
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpmcp_rsp_get_irq_status *)cmd.params;
*status = le32_to_cpu(rsp_params->status);
return 0;
}
int dpmcp_get_attributes(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpmcp_attr *attr)
{
struct mc_command cmd = { 0 };
struct dpmcp_rsp_get_attributes *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_ATTR,
cmd_flags, token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpmcp_rsp_get_attributes *)cmd.params;
attr->id = le32_to_cpu(rsp_params->id);
attr->version.major = le16_to_cpu(rsp_params->version_major);
attr->version.minor = le16_to_cpu(rsp_params->version_minor);
return 0;
}
