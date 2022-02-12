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
int dprc_create_container(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dprc_cfg *cfg,
int *child_container_id,
u64 *child_portal_offset)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_create_container *cmd_params;
struct dprc_rsp_create_container *rsp_params;
int err;
cmd_params = (struct dprc_cmd_create_container *)cmd.params;
cmd_params->options = cpu_to_le32(cfg->options);
cmd_params->icid = cpu_to_le16(cfg->icid);
cmd_params->portal_id = cpu_to_le32(cfg->portal_id);
strncpy(cmd_params->label, cfg->label, 16);
cmd_params->label[15] = '\0';
cmd.header = mc_encode_cmd_header(DPRC_CMDID_CREATE_CONT,
cmd_flags, token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_create_container *)cmd.params;
*child_container_id = le32_to_cpu(rsp_params->child_container_id);
*child_portal_offset = le64_to_cpu(rsp_params->child_portal_addr);
return 0;
}
int dprc_destroy_container(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int child_container_id)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_destroy_container *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_DESTROY_CONT,
cmd_flags, token);
cmd_params = (struct dprc_cmd_destroy_container *)cmd.params;
cmd_params->child_container_id = cpu_to_le32(child_container_id);
return mc_send_command(mc_io, &cmd);
}
int dprc_reset_container(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int child_container_id)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_reset_container *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_RESET_CONT,
cmd_flags, token);
cmd_params = (struct dprc_cmd_reset_container *)cmd.params;
cmd_params->child_container_id = cpu_to_le32(child_container_id);
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
attr->version.major = le16_to_cpu(rsp_params->version_major);
attr->version.minor = le16_to_cpu(rsp_params->version_minor);
return 0;
}
int dprc_set_res_quota(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int child_container_id,
char *type,
u16 quota)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_set_res_quota *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_SET_RES_QUOTA,
cmd_flags, token);
cmd_params = (struct dprc_cmd_set_res_quota *)cmd.params;
cmd_params->child_container_id = cpu_to_le32(child_container_id);
cmd_params->quota = cpu_to_le16(quota);
strncpy(cmd_params->type, type, 16);
cmd_params->type[15] = '\0';
return mc_send_command(mc_io, &cmd);
}
int dprc_get_res_quota(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int child_container_id,
char *type,
u16 *quota)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_res_quota *cmd_params;
struct dprc_rsp_get_res_quota *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_RES_QUOTA,
cmd_flags, token);
cmd_params = (struct dprc_cmd_get_res_quota *)cmd.params;
cmd_params->child_container_id = cpu_to_le32(child_container_id);
strncpy(cmd_params->type, type, 16);
cmd_params->type[15] = '\0';
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_res_quota *)cmd.params;
*quota = le16_to_cpu(rsp_params->quota);
return 0;
}
int dprc_assign(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int container_id,
struct dprc_res_req *res_req)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_assign *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_ASSIGN,
cmd_flags, token);
cmd_params = (struct dprc_cmd_assign *)cmd.params;
cmd_params->container_id = cpu_to_le32(container_id);
cmd_params->options = cpu_to_le32(res_req->options);
cmd_params->num = cpu_to_le32(res_req->num);
cmd_params->id_base_align = cpu_to_le32(res_req->id_base_align);
strncpy(cmd_params->type, res_req->type, 16);
cmd_params->type[15] = '\0';
return mc_send_command(mc_io, &cmd);
}
int dprc_unassign(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int child_container_id,
struct dprc_res_req *res_req)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_unassign *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_UNASSIGN,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_unassign *)cmd.params;
cmd_params->child_container_id = cpu_to_le32(child_container_id);
cmd_params->options = cpu_to_le32(res_req->options);
cmd_params->num = cpu_to_le32(res_req->num);
cmd_params->id_base_align = cpu_to_le32(res_req->id_base_align);
strncpy(cmd_params->type, res_req->type, 16);
cmd_params->type[15] = '\0';
return mc_send_command(mc_io, &cmd);
}
int dprc_get_pool_count(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int *pool_count)
{
struct mc_command cmd = { 0 };
struct dprc_rsp_get_pool_count *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_POOL_COUNT,
cmd_flags, token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_pool_count *)cmd.params;
*pool_count = le32_to_cpu(rsp_params->pool_count);
return 0;
}
int dprc_get_pool(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int pool_index,
char *type)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_pool *cmd_params;
struct dprc_rsp_get_pool *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_POOL,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_get_pool *)cmd.params;
cmd_params->pool_index = cpu_to_le32(pool_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_pool *)cmd.params;
strncpy(type, rsp_params->type, 16);
type[15] = '\0';
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
struct dprc_obj_desc *obj_desc)
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
int dprc_get_obj_desc(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
char *obj_type,
int obj_id,
struct dprc_obj_desc *obj_desc)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_obj_desc *cmd_params;
struct dprc_rsp_get_obj_desc *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_OBJ_DESC,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_get_obj_desc *)cmd.params;
cmd_params->obj_id = cpu_to_le32(obj_id);
strncpy(cmd_params->type, obj_type, 16);
cmd_params->type[15] = '\0';
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_obj_desc *)cmd.params;
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
int dprc_get_res_ids(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
char *type,
struct dprc_res_ids_range_desc *range_desc)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_res_ids *cmd_params;
struct dprc_rsp_get_res_ids *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_RES_IDS,
cmd_flags, token);
cmd_params = (struct dprc_cmd_get_res_ids *)cmd.params;
cmd_params->iter_status = range_desc->iter_status;
cmd_params->base_id = cpu_to_le32(range_desc->base_id);
cmd_params->last_id = cpu_to_le32(range_desc->last_id);
strncpy(cmd_params->type, type, 16);
cmd_params->type[15] = '\0';
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_res_ids *)cmd.params;
range_desc->iter_status = rsp_params->iter_status;
range_desc->base_id = le32_to_cpu(rsp_params->base_id);
range_desc->last_id = le32_to_cpu(rsp_params->last_id);
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
int dprc_set_obj_label(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
char *obj_type,
int obj_id,
char *label)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_set_obj_label *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_SET_OBJ_LABEL,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_set_obj_label *)cmd.params;
cmd_params->obj_id = cpu_to_le32(obj_id);
strncpy(cmd_params->label, label, 16);
cmd_params->label[15] = '\0';
strncpy(cmd_params->obj_type, obj_type, 16);
cmd_params->obj_type[15] = '\0';
return mc_send_command(mc_io, &cmd);
}
int dprc_connect(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
const struct dprc_endpoint *endpoint1,
const struct dprc_endpoint *endpoint2,
const struct dprc_connection_cfg *cfg)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_connect *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_CONNECT,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_connect *)cmd.params;
cmd_params->ep1_id = cpu_to_le32(endpoint1->id);
cmd_params->ep1_interface_id = cpu_to_le32(endpoint1->if_id);
cmd_params->ep2_id = cpu_to_le32(endpoint2->id);
cmd_params->ep2_interface_id = cpu_to_le32(endpoint2->if_id);
strncpy(cmd_params->ep1_type, endpoint1->type, 16);
cmd_params->ep1_type[15] = '\0';
cmd_params->max_rate = cpu_to_le32(cfg->max_rate);
cmd_params->committed_rate = cpu_to_le32(cfg->committed_rate);
strncpy(cmd_params->ep2_type, endpoint2->type, 16);
cmd_params->ep2_type[15] = '\0';
return mc_send_command(mc_io, &cmd);
}
int dprc_disconnect(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
const struct dprc_endpoint *endpoint)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_disconnect *cmd_params;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_DISCONNECT,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_disconnect *)cmd.params;
cmd_params->id = cpu_to_le32(endpoint->id);
cmd_params->interface_id = cpu_to_le32(endpoint->if_id);
strncpy(cmd_params->type, endpoint->type, 16);
cmd_params->type[15] = '\0';
return mc_send_command(mc_io, &cmd);
}
int dprc_get_connection(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
const struct dprc_endpoint *endpoint1,
struct dprc_endpoint *endpoint2,
int *state)
{
struct mc_command cmd = { 0 };
struct dprc_cmd_get_connection *cmd_params;
struct dprc_rsp_get_connection *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPRC_CMDID_GET_CONNECTION,
cmd_flags,
token);
cmd_params = (struct dprc_cmd_get_connection *)cmd.params;
cmd_params->ep1_id = cpu_to_le32(endpoint1->id);
cmd_params->ep1_interface_id = cpu_to_le32(endpoint1->if_id);
strncpy(cmd_params->ep1_type, endpoint1->type, 16);
cmd_params->ep1_type[15] = '\0';
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dprc_rsp_get_connection *)cmd.params;
endpoint2->id = le32_to_cpu(rsp_params->ep2_id);
endpoint2->if_id = le32_to_cpu(rsp_params->ep2_interface_id);
strncpy(endpoint2->type, rsp_params->ep2_type, 16);
endpoint2->type[15] = '\0';
*state = le32_to_cpu(rsp_params->state);
return 0;
}
