int dpni_prepare_key_cfg(const struct dpkg_profile_cfg *cfg, u8 *key_cfg_buf)
{
int i, j;
struct dpni_ext_set_rx_tc_dist *dpni_ext;
struct dpni_dist_extract *extr;
if (cfg->num_extracts > DPKG_MAX_NUM_OF_EXTRACTS)
return -EINVAL;
dpni_ext = (struct dpni_ext_set_rx_tc_dist *)key_cfg_buf;
dpni_ext->num_extracts = cfg->num_extracts;
for (i = 0; i < cfg->num_extracts; i++) {
extr = &dpni_ext->extracts[i];
switch (cfg->extracts[i].type) {
case DPKG_EXTRACT_FROM_HDR:
extr->prot = cfg->extracts[i].extract.from_hdr.prot;
dpni_set_field(extr->efh_type, EFH_TYPE,
cfg->extracts[i].extract.from_hdr.type);
extr->size = cfg->extracts[i].extract.from_hdr.size;
extr->offset = cfg->extracts[i].extract.from_hdr.offset;
extr->field = cpu_to_le32(
cfg->extracts[i].extract.from_hdr.field);
extr->hdr_index =
cfg->extracts[i].extract.from_hdr.hdr_index;
break;
case DPKG_EXTRACT_FROM_DATA:
extr->size = cfg->extracts[i].extract.from_data.size;
extr->offset =
cfg->extracts[i].extract.from_data.offset;
break;
case DPKG_EXTRACT_FROM_PARSE:
extr->size = cfg->extracts[i].extract.from_parse.size;
extr->offset =
cfg->extracts[i].extract.from_parse.offset;
break;
default:
return -EINVAL;
}
extr->num_of_byte_masks = cfg->extracts[i].num_of_byte_masks;
dpni_set_field(extr->extract_type, EXTRACT_TYPE,
cfg->extracts[i].type);
for (j = 0; j < DPKG_NUM_OF_MASKS; j++) {
extr->masks[j].mask = cfg->extracts[i].masks[j].mask;
extr->masks[j].offset =
cfg->extracts[i].masks[j].offset;
}
}
return 0;
}
int dpni_open(struct fsl_mc_io *mc_io,
u32 cmd_flags,
int dpni_id,
u16 *token)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_open *cmd_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_OPEN,
cmd_flags,
0);
cmd_params = (struct dpni_cmd_open *)cmd.params;
cmd_params->dpni_id = cpu_to_le32(dpni_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = mc_cmd_hdr_read_token(&cmd);
return 0;
}
int dpni_close(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPNI_CMDID_CLOSE,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpni_set_pools(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
const struct dpni_pools_cfg *cfg)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_pools *cmd_params;
int i;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_POOLS,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_pools *)cmd.params;
cmd_params->num_dpbp = cfg->num_dpbp;
for (i = 0; i < DPNI_MAX_DPBP; i++) {
cmd_params->dpbp_id[i] = cpu_to_le32(cfg->pools[i].dpbp_id);
cmd_params->buffer_size[i] =
cpu_to_le16(cfg->pools[i].buffer_size);
cmd_params->backup_pool_mask |=
DPNI_BACKUP_POOL(cfg->pools[i].backup_pool, i);
}
return mc_send_command(mc_io, &cmd);
}
int dpni_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPNI_CMDID_ENABLE,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpni_disable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPNI_CMDID_DISABLE,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpni_is_enabled(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int *en)
{
struct mc_command cmd = { 0 };
struct dpni_rsp_is_enabled *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_IS_ENABLED,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_is_enabled *)cmd.params;
*en = dpni_get_field(rsp_params->enabled, ENABLE);
return 0;
}
int dpni_reset(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPNI_CMDID_RESET,
cmd_flags,
token);
return mc_send_command(mc_io, &cmd);
}
int dpni_set_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 en)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_irq_enable *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_IRQ_ENABLE,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_irq_enable *)cmd.params;
dpni_set_field(cmd_params->enable, ENABLE, en);
cmd_params->irq_index = irq_index;
return mc_send_command(mc_io, &cmd);
}
int dpni_get_irq_enable(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u8 *en)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_get_irq_enable *cmd_params;
struct dpni_rsp_get_irq_enable *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_IRQ_ENABLE,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_get_irq_enable *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_irq_enable *)cmd.params;
*en = dpni_get_field(rsp_params->enabled, ENABLE);
return 0;
}
int dpni_set_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 mask)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_irq_mask *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_IRQ_MASK,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_irq_mask *)cmd.params;
cmd_params->mask = cpu_to_le32(mask);
cmd_params->irq_index = irq_index;
return mc_send_command(mc_io, &cmd);
}
int dpni_get_irq_mask(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *mask)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_get_irq_mask *cmd_params;
struct dpni_rsp_get_irq_mask *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_IRQ_MASK,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_get_irq_mask *)cmd.params;
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_irq_mask *)cmd.params;
*mask = le32_to_cpu(rsp_params->mask);
return 0;
}
int dpni_get_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 *status)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_get_irq_status *cmd_params;
struct dpni_rsp_get_irq_status *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_IRQ_STATUS,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_get_irq_status *)cmd.params;
cmd_params->status = cpu_to_le32(*status);
cmd_params->irq_index = irq_index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_irq_status *)cmd.params;
*status = le32_to_cpu(rsp_params->status);
return 0;
}
int dpni_clear_irq_status(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 irq_index,
u32 status)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_clear_irq_status *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_CLEAR_IRQ_STATUS,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_clear_irq_status *)cmd.params;
cmd_params->irq_index = irq_index;
cmd_params->status = cpu_to_le32(status);
return mc_send_command(mc_io, &cmd);
}
int dpni_get_attributes(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpni_attr *attr)
{
struct mc_command cmd = { 0 };
struct dpni_rsp_get_attr *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_ATTR,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_attr *)cmd.params;
attr->options = le32_to_cpu(rsp_params->options);
attr->num_queues = rsp_params->num_queues;
attr->num_tcs = rsp_params->num_tcs;
attr->mac_filter_entries = rsp_params->mac_filter_entries;
attr->vlan_filter_entries = rsp_params->vlan_filter_entries;
attr->qos_entries = rsp_params->qos_entries;
attr->fs_entries = le16_to_cpu(rsp_params->fs_entries);
attr->qos_key_size = rsp_params->qos_key_size;
attr->fs_key_size = rsp_params->fs_key_size;
attr->wriop_version = le16_to_cpu(rsp_params->wriop_version);
return 0;
}
int dpni_set_errors_behavior(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpni_error_cfg *cfg)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_errors_behavior *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_ERRORS_BEHAVIOR,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_errors_behavior *)cmd.params;
cmd_params->errors = cpu_to_le32(cfg->errors);
dpni_set_field(cmd_params->flags, ERROR_ACTION, cfg->error_action);
dpni_set_field(cmd_params->flags, FRAME_ANN, cfg->set_frame_annotation);
return mc_send_command(mc_io, &cmd);
}
int dpni_get_buffer_layout(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
enum dpni_queue_type qtype,
struct dpni_buffer_layout *layout)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_get_buffer_layout *cmd_params;
struct dpni_rsp_get_buffer_layout *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_BUFFER_LAYOUT,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_get_buffer_layout *)cmd.params;
cmd_params->qtype = qtype;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_buffer_layout *)cmd.params;
layout->pass_timestamp = dpni_get_field(rsp_params->flags, PASS_TS);
layout->pass_parser_result = dpni_get_field(rsp_params->flags, PASS_PR);
layout->pass_frame_status = dpni_get_field(rsp_params->flags, PASS_FS);
layout->private_data_size = le16_to_cpu(rsp_params->private_data_size);
layout->data_align = le16_to_cpu(rsp_params->data_align);
layout->data_head_room = le16_to_cpu(rsp_params->head_room);
layout->data_tail_room = le16_to_cpu(rsp_params->tail_room);
return 0;
}
int dpni_set_buffer_layout(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
enum dpni_queue_type qtype,
const struct dpni_buffer_layout *layout)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_buffer_layout *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_BUFFER_LAYOUT,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_buffer_layout *)cmd.params;
cmd_params->qtype = qtype;
cmd_params->options = cpu_to_le16(layout->options);
dpni_set_field(cmd_params->flags, PASS_TS, layout->pass_timestamp);
dpni_set_field(cmd_params->flags, PASS_PR, layout->pass_parser_result);
dpni_set_field(cmd_params->flags, PASS_FS, layout->pass_frame_status);
cmd_params->private_data_size = cpu_to_le16(layout->private_data_size);
cmd_params->data_align = cpu_to_le16(layout->data_align);
cmd_params->head_room = cpu_to_le16(layout->data_head_room);
cmd_params->tail_room = cpu_to_le16(layout->data_tail_room);
return mc_send_command(mc_io, &cmd);
}
int dpni_set_offload(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
enum dpni_offload type,
u32 config)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_offload *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_OFFLOAD,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_offload *)cmd.params;
cmd_params->dpni_offload = type;
cmd_params->config = cpu_to_le32(config);
return mc_send_command(mc_io, &cmd);
}
int dpni_get_offload(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
enum dpni_offload type,
u32 *config)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_get_offload *cmd_params;
struct dpni_rsp_get_offload *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_OFFLOAD,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_get_offload *)cmd.params;
cmd_params->dpni_offload = type;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_offload *)cmd.params;
*config = le32_to_cpu(rsp_params->config);
return 0;
}
int dpni_get_qdid(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
enum dpni_queue_type qtype,
u16 *qdid)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_get_qdid *cmd_params;
struct dpni_rsp_get_qdid *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_QDID,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_get_qdid *)cmd.params;
cmd_params->qtype = qtype;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_qdid *)cmd.params;
*qdid = le16_to_cpu(rsp_params->qdid);
return 0;
}
int dpni_get_tx_data_offset(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u16 *data_offset)
{
struct mc_command cmd = { 0 };
struct dpni_rsp_get_tx_data_offset *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_TX_DATA_OFFSET,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_tx_data_offset *)cmd.params;
*data_offset = le16_to_cpu(rsp_params->data_offset);
return 0;
}
int dpni_set_link_cfg(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
const struct dpni_link_cfg *cfg)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_link_cfg *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_LINK_CFG,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_link_cfg *)cmd.params;
cmd_params->rate = cpu_to_le32(cfg->rate);
cmd_params->options = cpu_to_le64(cfg->options);
return mc_send_command(mc_io, &cmd);
}
int dpni_get_link_state(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
struct dpni_link_state *state)
{
struct mc_command cmd = { 0 };
struct dpni_rsp_get_link_state *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_LINK_STATE,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_link_state *)cmd.params;
state->up = dpni_get_field(rsp_params->flags, LINK_STATE);
state->rate = le32_to_cpu(rsp_params->rate);
state->options = le64_to_cpu(rsp_params->options);
return 0;
}
int dpni_set_max_frame_length(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u16 max_frame_length)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_max_frame_length *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_MAX_FRAME_LENGTH,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_max_frame_length *)cmd.params;
cmd_params->max_frame_length = cpu_to_le16(max_frame_length);
return mc_send_command(mc_io, &cmd);
}
int dpni_get_max_frame_length(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u16 *max_frame_length)
{
struct mc_command cmd = { 0 };
struct dpni_rsp_get_max_frame_length *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_MAX_FRAME_LENGTH,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_max_frame_length *)cmd.params;
*max_frame_length = le16_to_cpu(rsp_params->max_frame_length);
return 0;
}
int dpni_set_multicast_promisc(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int en)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_multicast_promisc *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_MCAST_PROMISC,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_multicast_promisc *)cmd.params;
dpni_set_field(cmd_params->enable, ENABLE, en);
return mc_send_command(mc_io, &cmd);
}
int dpni_get_multicast_promisc(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int *en)
{
struct mc_command cmd = { 0 };
struct dpni_rsp_get_multicast_promisc *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_MCAST_PROMISC,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_multicast_promisc *)cmd.params;
*en = dpni_get_field(rsp_params->enabled, ENABLE);
return 0;
}
int dpni_set_unicast_promisc(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int en)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_unicast_promisc *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_UNICAST_PROMISC,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_unicast_promisc *)cmd.params;
dpni_set_field(cmd_params->enable, ENABLE, en);
return mc_send_command(mc_io, &cmd);
}
int dpni_get_unicast_promisc(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int *en)
{
struct mc_command cmd = { 0 };
struct dpni_rsp_get_unicast_promisc *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_UNICAST_PROMISC,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_unicast_promisc *)cmd.params;
*en = dpni_get_field(rsp_params->enabled, ENABLE);
return 0;
}
int dpni_set_primary_mac_addr(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
const u8 mac_addr[6])
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_primary_mac_addr *cmd_params;
int i;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_PRIM_MAC,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_primary_mac_addr *)cmd.params;
for (i = 0; i < 6; i++)
cmd_params->mac_addr[i] = mac_addr[5 - i];
return mc_send_command(mc_io, &cmd);
}
int dpni_get_primary_mac_addr(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 mac_addr[6])
{
struct mc_command cmd = { 0 };
struct dpni_rsp_get_primary_mac_addr *rsp_params;
int i, err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_PRIM_MAC,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_primary_mac_addr *)cmd.params;
for (i = 0; i < 6; i++)
mac_addr[5 - i] = rsp_params->mac_addr[i];
return 0;
}
int dpni_get_port_mac_addr(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 mac_addr[6])
{
struct mc_command cmd = { 0 };
struct dpni_rsp_get_port_mac_addr *rsp_params;
int i, err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_PORT_MAC_ADDR,
cmd_flags,
token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_port_mac_addr *)cmd.params;
for (i = 0; i < 6; i++)
mac_addr[5 - i] = rsp_params->mac_addr[i];
return 0;
}
int dpni_add_mac_addr(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
const u8 mac_addr[6])
{
struct mc_command cmd = { 0 };
struct dpni_cmd_add_mac_addr *cmd_params;
int i;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_ADD_MAC_ADDR,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_add_mac_addr *)cmd.params;
for (i = 0; i < 6; i++)
cmd_params->mac_addr[i] = mac_addr[5 - i];
return mc_send_command(mc_io, &cmd);
}
int dpni_remove_mac_addr(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
const u8 mac_addr[6])
{
struct mc_command cmd = { 0 };
struct dpni_cmd_remove_mac_addr *cmd_params;
int i;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_REMOVE_MAC_ADDR,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_remove_mac_addr *)cmd.params;
for (i = 0; i < 6; i++)
cmd_params->mac_addr[i] = mac_addr[5 - i];
return mc_send_command(mc_io, &cmd);
}
int dpni_clear_mac_filters(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
int unicast,
int multicast)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_clear_mac_filters *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_CLR_MAC_FILTERS,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_clear_mac_filters *)cmd.params;
dpni_set_field(cmd_params->flags, UNICAST_FILTERS, unicast);
dpni_set_field(cmd_params->flags, MULTICAST_FILTERS, multicast);
return mc_send_command(mc_io, &cmd);
}
int dpni_set_rx_tc_dist(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 tc_id,
const struct dpni_rx_tc_dist_cfg *cfg)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_rx_tc_dist *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_RX_TC_DIST,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_rx_tc_dist *)cmd.params;
cmd_params->dist_size = cpu_to_le16(cfg->dist_size);
cmd_params->tc_id = tc_id;
dpni_set_field(cmd_params->flags, DIST_MODE, cfg->dist_mode);
dpni_set_field(cmd_params->flags, MISS_ACTION, cfg->fs_cfg.miss_action);
cmd_params->default_flow_id = cpu_to_le16(cfg->fs_cfg.default_flow_id);
cmd_params->key_cfg_iova = cpu_to_le64(cfg->key_cfg_iova);
return mc_send_command(mc_io, &cmd);
}
int dpni_set_queue(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
enum dpni_queue_type qtype,
u8 tc,
u8 index,
u8 options,
const struct dpni_queue *queue)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_queue *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_QUEUE,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_queue *)cmd.params;
cmd_params->qtype = qtype;
cmd_params->tc = tc;
cmd_params->index = index;
cmd_params->options = options;
cmd_params->dest_id = cpu_to_le32(queue->destination.id);
cmd_params->dest_prio = queue->destination.priority;
dpni_set_field(cmd_params->flags, DEST_TYPE, queue->destination.type);
dpni_set_field(cmd_params->flags, STASH_CTRL, queue->flc.stash_control);
dpni_set_field(cmd_params->flags, HOLD_ACTIVE,
queue->destination.hold_active);
cmd_params->flc = cpu_to_le64(queue->flc.value);
cmd_params->user_context = cpu_to_le64(queue->user_context);
return mc_send_command(mc_io, &cmd);
}
int dpni_get_queue(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
enum dpni_queue_type qtype,
u8 tc,
u8 index,
struct dpni_queue *queue,
struct dpni_queue_id *qid)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_get_queue *cmd_params;
struct dpni_rsp_get_queue *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_QUEUE,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_get_queue *)cmd.params;
cmd_params->qtype = qtype;
cmd_params->tc = tc;
cmd_params->index = index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_queue *)cmd.params;
queue->destination.id = le32_to_cpu(rsp_params->dest_id);
queue->destination.priority = rsp_params->dest_prio;
queue->destination.type = dpni_get_field(rsp_params->flags,
DEST_TYPE);
queue->flc.stash_control = dpni_get_field(rsp_params->flags,
STASH_CTRL);
queue->destination.hold_active = dpni_get_field(rsp_params->flags,
HOLD_ACTIVE);
queue->flc.value = le64_to_cpu(rsp_params->flc);
queue->user_context = le64_to_cpu(rsp_params->user_context);
qid->fqid = le32_to_cpu(rsp_params->fqid);
qid->qdbin = le16_to_cpu(rsp_params->qdbin);
return 0;
}
int dpni_get_statistics(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
u8 page,
union dpni_statistics *stat)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_get_statistics *cmd_params;
struct dpni_rsp_get_statistics *rsp_params;
int i, err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_STATISTICS,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_get_statistics *)cmd.params;
cmd_params->page_number = page;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_statistics *)cmd.params;
for (i = 0; i < DPNI_STATISTICS_CNT; i++)
stat->raw.counter[i] = le64_to_cpu(rsp_params->counter[i]);
return 0;
}
int dpni_set_taildrop(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
enum dpni_congestion_point cg_point,
enum dpni_queue_type qtype,
u8 tc,
u8 index,
struct dpni_taildrop *taildrop)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_set_taildrop *cmd_params;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_TAILDROP,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_set_taildrop *)cmd.params;
cmd_params->congestion_point = cg_point;
cmd_params->qtype = qtype;
cmd_params->tc = tc;
cmd_params->index = index;
dpni_set_field(cmd_params->enable, ENABLE, taildrop->enable);
cmd_params->units = taildrop->units;
cmd_params->threshold = cpu_to_le32(taildrop->threshold);
return mc_send_command(mc_io, &cmd);
}
int dpni_get_taildrop(struct fsl_mc_io *mc_io,
u32 cmd_flags,
u16 token,
enum dpni_congestion_point cg_point,
enum dpni_queue_type qtype,
u8 tc,
u8 index,
struct dpni_taildrop *taildrop)
{
struct mc_command cmd = { 0 };
struct dpni_cmd_get_taildrop *cmd_params;
struct dpni_rsp_get_taildrop *rsp_params;
int err;
cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_TAILDROP,
cmd_flags,
token);
cmd_params = (struct dpni_cmd_get_taildrop *)cmd.params;
cmd_params->congestion_point = cg_point;
cmd_params->qtype = qtype;
cmd_params->tc = tc;
cmd_params->index = index;
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
rsp_params = (struct dpni_rsp_get_taildrop *)cmd.params;
taildrop->enable = dpni_get_field(rsp_params->enable, ENABLE);
taildrop->units = rsp_params->units;
taildrop->threshold = le32_to_cpu(rsp_params->threshold);
return 0;
}
