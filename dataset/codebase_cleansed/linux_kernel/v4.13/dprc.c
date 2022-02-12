int dprc_open(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int container_id,
u16 *token)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_open *cmd_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_OPEN, cmd_flags,
0);
cmd_params = (struct dprc_cmd_open *)cmd.params;
cmd_params->container_id = cpu_to_le32(container_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = mc_cmd_hdr_read_token(&cmd);
return 0;
}
int dprc_close(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPRC_CMDID_CLOSE, cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dprc_get_irq(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
int *type,
struct dprc_irq_cfg *irq_cfg)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_irq *cmd_params;
struct dprc_rsp_get_irq *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_IRQ,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_get_irq *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_irq *)cmd.params;
irq_cfg->val = le32_to_cpu(rsp_params->irq_val);
irq_cfg->paddr = le64_to_cpu(rsp_params->irq_addr);
irq_cfg->irq_num = le32_to_cpu(rsp_params->irq_num);
*type = le32_to_cpu(rsp_params->type);
return 0;
}
int dprc_set_irq(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
struct dprc_irq_cfg *irq_cfg)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_set_irq *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_SET_IRQ,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_set_irq *)cmd.params;
cmd_params->irq_val = cpu_to_le32(irq_cfg->val);
cmd_params->irq_index = irq_index;
cmd_params->irq_addr = cpu_to_le64(irq_cfg->paddr);
cmd_params->irq_num = cpu_to_le32(irq_cfg->irq_num);
return mc_send_command(mc_io, &cmd);
}
int dprc_get_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 *en)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_irq_enable *cmd_params;
struct dprc_rsp_get_irq_enable *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_IRQ_ENABLE,
cmd_flags, token);
cmd_params = (struct dprc_cmd_get_irq_enable *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_irq_enable *)cmd.params;
*en = rsp_params->enabled & DPRC_ENABLE;
return 0;
}
int dprc_set_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 en)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_set_irq_enable *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_SET_IRQ_ENABLE,
cmd_flags, token);
cmd_params = (struct dprc_cmd_set_irq_enable *)cmd.params;
cmd_params->enable = en & DPRC_ENABLE;
cmd_params->irq_index = irq_index;
return mc_send_command(mc_io, &cmd);
}
int dprc_get_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *mask)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_irq_mask *cmd_params;
struct dprc_rsp_get_irq_mask *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_IRQ_MASK,
cmd_flags, token);
cmd_params = (struct dprc_cmd_get_irq_mask *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_irq_mask *)cmd.params;
*mask = le32_to_cpu(rsp_params->mask);
return 0;
}
int dprc_set_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 mask)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_set_irq_mask *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_SET_IRQ_MASK,
cmd_flags, token);
cmd_params = (struct dprc_cmd_set_irq_mask *)cmd.params;
cmd_params->mask = cpu_to_le32(mask);
cmd_params->irq_index = irq_index;
return mc_send_command(mc_io, &cmd);
}
int dprc_get_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *status)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_irq_status *cmd_params;
struct dprc_rsp_get_irq_status *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_IRQ_STATUS,
cmd_flags, token);
cmd_params = (struct dprc_cmd_get_irq_status *)cmd.params;
cmd_params->status = cpu_to_le32(*status);
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_irq_status *)cmd.params;
*status = le32_to_cpu(rsp_params->status);
return 0;
}
int dprc_clear_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 status)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_clear_irq_status *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_CLEAR_IRQ_STATUS,
cmd_flags, token);
cmd_params = (struct dprc_cmd_clear_irq_status *)cmd.params;
cmd_params->status = cpu_to_le32(status);
cmd_params->irq_index = irq_index;
return mc_send_command(mc_io, &cmd);
}
int dprc_get_attributes(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dprc_attributes *attr)
{
struct mc_command cmd = { 0 };
struct dprc_rsp_get_attributes *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_ATTR,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_attributes *)cmd.params;
attr->container_id = le32_to_cpu(rsp_params->container_id);
attr->icid = le16_to_cpu(rsp_params->icid);
attr->options = le32_to_cpu(rsp_params->options);
attr->portal_id = le32_to_cpu(rsp_params->portal_id);
return 0;
}
int dprc_get_obj_count(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int *obj_count)
{
struct mc_command cmd = { 0 };
struct dprc_rsp_get_obj_count *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_OBJ_COUNT,
cmd_flags, token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_obj_count *)cmd.params;
*obj_count = le32_to_cpu(rsp_params->obj_count);
return 0;
}
int dprc_get_obj(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int obj_index,
struct fsl_mc_obj_desc *obj_desc)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_obj *cmd_params;
struct dprc_rsp_get_obj *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_OBJ,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_get_obj *)cmd.params;
cmd_params->obj_index = cpu_to_le32(obj_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_obj *)cmd.params;
obj_desc->id = le32_to_cpu(rsp_params->id);
obj_desc->vendor = le16_to_cpu(rsp_params->vendor);
obj_desc->irq_count = rsp_params->irq_count;
obj_desc->region_count = rsp_params->region_count;
obj_desc->state = le32_to_cpu(rsp_params->state);
obj_desc->ver_major = le16_to_cpu(rsp_params->version_major);
obj_desc->ver_minor = le16_to_cpu(rsp_params->version_minor);
obj_desc->flags = le16_to_cpu(rsp_params->flags);
strncpy(obj_desc->type, rsp_params->type, 16);
obj_desc->type[15] = '\0';
strncpy(obj_desc->label, rsp_params->label, 16);
obj_desc->label[15] = '\0';
return 0;
}
int dprc_set_obj_irq(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
char *obj_type,
int obj_id,
u8 irq_index,
struct dprc_irq_cfg *irq_cfg)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_set_obj_irq *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_SET_OBJ_IRQ,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_set_obj_irq *)cmd.params;
cmd_params->irq_val = cpu_to_le32(irq_cfg->val);
cmd_params->irq_index = irq_index;
cmd_params->irq_addr = cpu_to_le64(irq_cfg->paddr);
cmd_params->irq_num = cpu_to_le32(irq_cfg->irq_num);
cmd_params->obj_id = cpu_to_le32(obj_id);
strncpy(cmd_params->obj_type, obj_type, 16);
cmd_params->obj_type[15] = '\0';
return mc_send_command(mc_io, &cmd);
}
int dprc_get_obj_irq(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
char *obj_type,
int obj_id,
u8 irq_index,
int *type,
struct dprc_irq_cfg *irq_cfg)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_obj_irq *cmd_params;
struct dprc_rsp_get_obj_irq *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_OBJ_IRQ,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_get_obj_irq *)cmd.params;
cmd_params->obj_id = cpu_to_le32(obj_id);
cmd_params->irq_index = irq_index;
strncpy(cmd_params->obj_type, obj_type, 16);
cmd_params->obj_type[15] = '\0';
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_obj_irq *)cmd.params;
irq_cfg->val = le32_to_cpu(rsp_params->irq_val);
irq_cfg->paddr = le64_to_cpu(rsp_params->irq_addr);
irq_cfg->irq_num = le32_to_cpu(rsp_params->irq_num);
*type = le32_to_cpu(rsp_params->type);
return 0;
}
int dprc_get_res_count(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
char *type,
int *res_count)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_res_count *cmd_params;
struct dprc_rsp_get_res_count *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_RES_COUNT,
cmd_flags, token);
cmd_params = (struct dprc_cmd_get_res_count *)cmd.params;
strncpy(cmd_params->type, type, 16);
cmd_params->type[15] = '\0';
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_res_count *)cmd.params;
*res_count = le32_to_cpu(rsp_params->res_count);
return 0;
}
int dprc_get_obj_region(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
char *obj_type,
int obj_id,
u8 region_index,
struct dprc_region_desc *region_desc)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_obj_region *cmd_params;
struct dprc_rsp_get_obj_region *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_OBJ_REG,
cmd_flags, token);
cmd_params = (struct dprc_cmd_get_obj_region *)cmd.params;
cmd_params->obj_id = cpu_to_le32(obj_id);
cmd_params->region_index = region_index;
strncpy(cmd_params->obj_type, obj_type, 16);
cmd_params->obj_type[15] = '\0';
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_obj_region *)cmd.params;
region_desc->base_offset = le64_to_cpu(rsp_params->base_addr);
region_desc->size = le32_to_cpu(rsp_params->size);
return 0;
}
int dprc_get_api_version(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 *major_ver,
u16 *minor_ver)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_API_VERSION,
cmd_flags, 0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
mc_cmd_read_api_version(&cmd, major_ver, minor_ver);
return 0;
}
int dprc_get_container_id(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int *container_id)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_CONT_ID,
cmd_flags,
0);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*container_id = (int)mc_cmd_read_object_id(&cmd);
return 0;
}
