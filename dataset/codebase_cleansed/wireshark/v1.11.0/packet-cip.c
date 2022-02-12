static void add_cip_service_to_info_column(packet_info *pinfo, guint8 service, const value_string* service_vals)
{
cip_req_info_t *preq_info;
preq_info = (cip_req_info_t*)p_get_proto_data( pinfo->fd, proto_cip, 0 );
if ((preq_info == NULL) || (preq_info->isUnconnectedSend == FALSE))
{
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " | ", "%s",
val_to_str( service & 0x7F,
service_vals, "Unknown Service (0x%02x)") );
col_set_fence(pinfo->cinfo, COL_INFO);
}
else
{
col_append_str( pinfo->cinfo, COL_INFO,
val_to_str(service & 0x7F,
service_vals, "Unknown Service (0x%02x)") );
col_set_fence(pinfo->cinfo, COL_INFO);
preq_info->isUnconnectedSend = FALSE;
}
}
static int dissect_id_revision(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_identity_revision);
return total_len;
}
proto_tree_add_item( tree, hf_id_major_rev, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_id_minor_rev, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
return 2;
}
static int dissect_msg_rout_num_classes(packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, tvbuff_t *tvb,
int offset, int total_len _U_)
{
guint16 i, num_classes;
num_classes = tvb_get_letohs( tvb, offset);
proto_tree_add_item( tree, hf_msg_rout_num_classes, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (total_len < (2+(num_classes*2)))
{
expert_add_info(pinfo, item, &ei_mal_msg_rout_num_classes);
return total_len;
}
for (i = 0; i < num_classes; i++)
proto_tree_add_item( tree, hf_msg_rout_classes, tvb, offset+2+(i*2), 2, ENC_LITTLE_ENDIAN);
return (2+(num_classes*2));
}
static int dissect_time_sync_grandmaster_clock(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
proto_item* ti;
proto_tree* flag_tree;
if (total_len < 24)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_gm_clock);
return total_len;
}
proto_tree_add_item( tree, hf_time_sync_gm_clock_clock_id, tvb, offset, 8, ENC_NA);
proto_tree_add_item( tree, hf_time_sync_gm_clock_clock_class, tvb, offset+8, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_gm_clock_time_accuracy, tvb, offset+10, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_gm_clock_offset_scaled_log_variance, tvb, offset+12, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_gm_clock_current_utc_offset, tvb, offset+14, 2, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_item( tree, hf_time_sync_gm_clock_time_property_flags, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
flag_tree = proto_item_add_subtree(ti, ett_time_sync_gm_clock_flags);
proto_tree_add_item( flag_tree, hf_time_sync_gm_clock_time_property_flags_leap61, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_gm_clock_time_property_flags_leap59, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_gm_clock_time_property_flags_current_utc_valid, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_gm_clock_time_property_flags_ptp_timescale, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_gm_clock_time_property_flags_time_traceable, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_gm_clock_time_property_flags_freq_traceable, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_gm_clock_time_source, tvb, offset+18, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_gm_clock_priority1, tvb, offset+20, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_gm_clock_priority2, tvb, offset+22, 2, ENC_LITTLE_ENDIAN);
return 24;
}
static int dissect_time_sync_parent_clock(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
if (total_len < 16)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_parent_clock);
return total_len;
}
proto_tree_add_item( tree, hf_time_sync_parent_clock_clock_id, tvb, offset, 8, ENC_NA);
proto_tree_add_item( tree, hf_time_sync_parent_clock_port_number, tvb, offset+8, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_parent_clock_observed_offset_scaled_log_variance, tvb, offset+10, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_parent_clock_observed_phase_change_rate, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
return 16;
}
static int dissect_time_sync_local_clock(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
proto_item* ti;
proto_tree* flag_tree;
if (total_len < 20)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_local_clock);
return total_len;
}
proto_tree_add_item( tree, hf_time_sync_local_clock_clock_id, tvb, offset, 8, ENC_NA);
proto_tree_add_item( tree, hf_time_sync_local_clock_clock_class, tvb, offset+8, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_local_clock_time_accuracy, tvb, offset+10, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_local_clock_offset_scaled_log_variance, tvb, offset+12, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_local_clock_current_utc_offset, tvb, offset+14, 2, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_item( tree, hf_time_sync_local_clock_time_property_flags, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
flag_tree = proto_item_add_subtree(ti, ett_time_sync_local_clock_flags);
proto_tree_add_item( flag_tree, hf_time_sync_local_clock_time_property_flags_leap61, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_local_clock_time_property_flags_leap59, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_local_clock_time_property_flags_current_utc_valid, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_local_clock_time_property_flags_ptp_timescale, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_local_clock_time_property_flags_time_traceable, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_local_clock_time_property_flags_freq_traceable, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_local_clock_time_source, tvb, offset+18, 2, ENC_LITTLE_ENDIAN);
return 20;
}
static int dissect_time_sync_port_state_info(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint16 i, num_ports;
proto_item* ti;
proto_tree* port_tree;
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_state_info);
return total_len;
}
num_ports = tvb_get_letohs( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_port_state_info_num_ports, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (2+num_ports*4 < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_state_info_ports);
return total_len;
}
for (i = 0; i < num_ports; i++)
{
ti = proto_tree_add_text(tree, NULL, offset+2+i*4, 4, "Port #%d", i+1);
port_tree = proto_item_add_subtree(ti, ett_time_sync_port_state_info);
proto_tree_add_item(port_tree, hf_time_sync_port_state_info_port_num, tvb, offset+2+i*4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_state_info_port_state, tvb, offset+4+i*4, 2, ENC_LITTLE_ENDIAN);
}
return 2+num_ports*4;
}
static int dissect_time_sync_port_enable_cfg(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint16 i, num_ports;
proto_item* ti;
proto_tree* port_tree;
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_enable_cfg);
return total_len;
}
num_ports = tvb_get_letohs( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_port_enable_cfg_num_ports, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (2+num_ports*4 < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_enable_cfg_ports);
return total_len;
}
for (i = 0; i < num_ports; i++)
{
ti = proto_tree_add_text(tree, NULL, offset+2+i*4, 4, "Port #%d", i+1);
port_tree = proto_item_add_subtree(ti, ett_time_sync_port_enable_cfg);
proto_tree_add_item(port_tree, hf_time_sync_port_enable_cfg_port_num, tvb, offset+2+i*4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_enable_cfg_port_enable, tvb, offset+4+i*4, 2, ENC_LITTLE_ENDIAN);
}
return 2+num_ports*4;
}
static int dissect_time_sync_port_log_announce(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint16 i, num_ports;
proto_item* ti;
proto_tree* port_tree;
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_log_announce);
return total_len;
}
num_ports = tvb_get_letohs( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_port_log_announce_num_ports, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (2+num_ports*4 < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_log_announce_ports);
return total_len;
}
for (i = 0; i < num_ports; i++)
{
ti = proto_tree_add_text(tree, NULL, offset+2+i*4, 4, "Port #%d", i+1);
port_tree = proto_item_add_subtree(ti, ett_time_sync_port_log_announce);
proto_tree_add_item(port_tree, hf_time_sync_port_log_announce_port_num, tvb, offset+2+i*4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_log_announce_interval, tvb, offset+4+i*4, 2, ENC_LITTLE_ENDIAN);
}
return 2+num_ports*4;
}
static int dissect_time_sync_port_log_sync(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint16 i, num_ports;
proto_item* ti;
proto_tree* port_tree;
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_log_sync);
return total_len;
}
num_ports = tvb_get_letohs( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_port_log_sync_num_ports, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (2+num_ports*4 < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_log_sync_ports);
return total_len;
}
for (i = 0; i < num_ports; i++)
{
ti = proto_tree_add_text(tree, NULL, offset+2+i*4, 4, "Port #%d", i+1);
port_tree = proto_item_add_subtree(ti, ett_time_sync_port_log_sync);
proto_tree_add_item(port_tree, hf_time_sync_port_log_sync_port_num, tvb, offset+2+i*4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_log_sync_port_log_sync_interval, tvb, offset+4+i*4, 2, ENC_LITTLE_ENDIAN);
}
return 2+num_ports*4;
}
static int dissect_time_sync_clock_type(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
proto_item* ti;
proto_tree* flag_tree;
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_clock_type);
return total_len;
}
ti = proto_tree_add_item( tree, hf_time_sync_clock_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
flag_tree = proto_item_add_subtree(ti, ett_time_sync_clock_type);
proto_tree_add_item( flag_tree, hf_time_sync_clock_type_management, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_clock_type_end_to_end, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_clock_type_boundary, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_clock_type_ordinary, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( flag_tree, hf_time_sync_clock_type_slave_only, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return 2;
}
static int dissect_time_sync_manufacture_id(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
if (total_len < 4)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_manufacture_id);
return total_len;
}
proto_tree_add_item( tree, hf_time_sync_manufacture_id_oui, tvb, offset, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_manufacture_id_reserved, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
return 4;
}
static int dissect_time_sync_prod_desc(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint32 size;
if (total_len < 4)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_prod_desc);
return total_len;
}
size = tvb_get_letohl( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_prod_desc_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (size > 64)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_prod_desc_64);
return total_len;
}
if ((int)(size+4) < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_prod_desc_size);
return total_len;
}
proto_tree_add_item( tree, hf_time_sync_prod_desc_str, tvb, offset+4, size, ENC_ASCII|ENC_NA);
return size+4;
}
static int dissect_time_sync_revision_data(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint32 size;
if (total_len < 4)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_revision_data);
return total_len;
}
size = tvb_get_letohl( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_revision_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (size > 32)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_revision_data_32);
return total_len;
}
if ((int)(size+4) < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_revision_data_size);
return total_len;
}
proto_tree_add_item( tree, hf_time_sync_revision_data_str, tvb, offset+4, size, ENC_ASCII|ENC_NA);
return size+4;
}
static int dissect_time_sync_user_desc(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint32 size;
if (total_len < 4)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_user_desc);
return total_len;
}
size = tvb_get_letohl( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_user_desc_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (size > 128)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_user_desc_128);
return total_len;
}
if ((int)(size+4) < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_user_desc_size);
return total_len;
}
proto_tree_add_item( tree, hf_time_sync_user_desc_str, tvb, offset+4, size, ENC_ASCII|ENC_NA);
return size+4;
}
static int dissect_time_sync_port_profile_id_info(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint16 i, num_ports;
proto_item* ti;
proto_tree* port_tree;
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_profile_id_info);
return total_len;
}
num_ports = tvb_get_letohs( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_port_profile_id_info_num_ports, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (2+num_ports*10 < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_profile_id_info_ports);
return total_len;
}
for (i = 0; i < num_ports; i++)
{
ti = proto_tree_add_text(tree, NULL, offset+2+i*10, 10, "Port #%d", i+1);
port_tree = proto_item_add_subtree(ti, ett_time_sync_port_profile_id_info);
proto_tree_add_item(port_tree, hf_time_sync_port_profile_id_info_port_num, tvb, offset+2+i*10, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_profile_id_info_profile_id, tvb, offset+4+i*10, 8, ENC_NA);
}
return 2+num_ports*10;
}
static int dissect_time_sync_port_phys_addr_info(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint16 i, num_ports;
proto_item* ti;
proto_tree* port_tree;
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_phys_addr_info);
return total_len;
}
num_ports = tvb_get_letohs( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_port_phys_addr_info_num_ports, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (2+num_ports*36 < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_phys_addr_info_ports);
return total_len;
}
for (i = 0; i < num_ports; i++)
{
ti = proto_tree_add_text(tree, NULL, offset+2+i*36, 36, "Port #%d", i+1);
port_tree = proto_item_add_subtree(ti, ett_time_sync_port_phys_addr_info);
proto_tree_add_item(port_tree, hf_time_sync_port_phys_addr_info_port_num, tvb, offset+2+i*36, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_phys_addr_info_phys_proto, tvb, offset+4+i*36, 16, ENC_NA);
proto_tree_add_item(port_tree, hf_time_sync_port_phys_addr_info_addr_size, tvb, offset+20+i*36, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_phys_addr_info_phys_proto, tvb, offset+22+i*36, 16, ENC_NA);
}
return 2+num_ports*36;
}
static int dissect_time_sync_port_proto_addr_info(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
guint16 i, num_ports;
proto_item* ti;
proto_tree* port_tree;
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_proto_addr_info);
return total_len;
}
num_ports = tvb_get_letohs( tvb, offset);
proto_tree_add_item( tree, hf_time_sync_port_proto_addr_info_num_ports, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (2+num_ports*22 < total_len)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_port_proto_addr_info_ports);
return total_len;
}
for (i = 0; i < num_ports; i++)
{
ti = proto_tree_add_text(tree, NULL, offset+2+i*22, 22, "Port #%d", i+1);
port_tree = proto_item_add_subtree(ti, ett_time_sync_port_proto_addr_info);
proto_tree_add_item(port_tree, hf_time_sync_port_proto_addr_info_port_num, tvb, offset+2+i*22, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_proto_addr_info_network_proto, tvb, offset+4+i*22, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_proto_addr_info_addr_size, tvb, offset+6+i*22, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(port_tree, hf_time_sync_port_proto_addr_info_port_proto_addr, tvb, offset+8+i*22, 16, ENC_NA);
}
return 2+num_ports*22;
}
static int dissect_time_sync_sys_time_and_offset(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
if (total_len < 16)
{
expert_add_info(pinfo, item, &ei_mal_time_sync_sys_time_and_offset);
return total_len;
}
proto_tree_add_item( tree, hf_time_sync_sys_time_and_offset_time, tvb, offset, 8, ENC_LITTLE_ENDIAN);
proto_tree_add_item( tree, hf_time_sync_sys_time_and_offset_offset, tvb, offset+8, 8, ENC_LITTLE_ENDIAN);
return 16;
}
static attribute_info_t* cip_get_attribute(guint class_id, guint instance, guint attribute)
{
size_t i, j;
attribute_val_array_t* att_array;
attribute_info_t* pattr;
for (i = 0; i < sizeof(all_attribute_vals)/sizeof(attribute_val_array_t); i++)
{
att_array = &all_attribute_vals[i];
for (j = 0; j < att_array->size; j++)
{
pattr = &att_array->attrs[j];
if ((pattr->class_id == class_id) &&
(instance != (guint)-1) &&
(((instance == 0) && (pattr->class_instance == TRUE)) || ((instance != 0) && (pattr->class_instance == FALSE))) &&
(pattr->attribute == attribute))
{
return pattr;
}
}
}
return NULL;
}
static gboolean
dissect_cia(tvbuff_t *tvb, int offset, int* pathpos, unsigned char segment_type,
gboolean generate, gboolean packed, packet_info *pinfo, proto_item *epath_item,
proto_item *item, proto_tree *tree, proto_item *path_item, proto_item ** ret_item,
const char* segment_name, const value_string* vals, int* value,
int hf8, int hf16, int hf32)
{
int temp_data;
wmem_strbuf_t *strbuf;
switch (segment_type)
{
case CI_LOGICAL_SEG_8_BIT:
temp_data = tvb_get_guint8( tvb, offset + *pathpos + 1 );
if ( generate )
{
*ret_item = proto_tree_add_uint(item, hf8, NULL, 0, 0, temp_data );
PROTO_ITEM_SET_GENERATED(*ret_item);
}
else
{
*ret_item = proto_tree_add_item(tree, hf8, tvb, offset + *pathpos + 1, 1, ENC_LITTLE_ENDIAN);
}
if (vals == NULL)
{
proto_item_append_text( epath_item, "%s: 0x%02X", segment_name, temp_data);
}
else
{
strbuf = wmem_strbuf_new(wmem_packet_scope(), segment_name);
wmem_strbuf_append(strbuf, ": 0x%02X");
proto_item_append_text( epath_item, "%s", val_to_str( temp_data, vals , wmem_strbuf_get_str(strbuf)) );
}
if (value != NULL)
*value = temp_data;
proto_item_set_len( item, 2);
proto_item_set_len( path_item, 2);
(*pathpos) += 2;
break;
case CI_LOGICAL_SEG_16_BIT:
if (packed)
{
temp_data = tvb_get_letohs( tvb, offset + *pathpos + 1 );
}
else
{
temp_data = tvb_get_letohs( tvb, offset + *pathpos + 2 );
}
if ( generate )
{
*ret_item = proto_tree_add_uint(tree, hf16, NULL, 0, 0, temp_data );
PROTO_ITEM_SET_GENERATED(*ret_item);
}
else
{
if (packed)
{
*ret_item = proto_tree_add_item( tree, hf16, tvb, offset + *pathpos + 1, 2, ENC_LITTLE_ENDIAN);
}
else
{
*ret_item = proto_tree_add_item( tree, hf16, tvb, offset + *pathpos + 2, 2, ENC_LITTLE_ENDIAN);
}
}
if (vals == NULL)
{
proto_item_append_text( epath_item, "%s: 0x%04X", segment_name, temp_data);
}
else
{
strbuf = wmem_strbuf_new(wmem_packet_scope(), segment_name);
wmem_strbuf_append(strbuf, ": 0x%04X");
proto_item_append_text( epath_item, "%s", val_to_str( temp_data, vals , wmem_strbuf_get_str(strbuf)) );
}
if (value != NULL)
*value = temp_data;
if (packed)
{
proto_item_set_len( item, 3);
proto_item_set_len( path_item, 3);
(*pathpos) += 3;
}
else
{
proto_item_set_len( item, 4);
proto_item_set_len( path_item, 4);
(*pathpos) += 4;
}
break;
case CI_LOGICAL_SEG_32_BIT:
if (packed)
{
temp_data = tvb_get_letohl( tvb, offset + *pathpos + 1 );
}
else
{
temp_data = tvb_get_letohl( tvb, offset + *pathpos + 2 );
}
if ( generate )
{
*ret_item = proto_tree_add_uint(tree, hf32, NULL, 0, 0, temp_data );
PROTO_ITEM_SET_GENERATED(*ret_item);
}
else
{
if (packed)
{
*ret_item = proto_tree_add_item( tree, hf32, tvb, offset + *pathpos + 1, 4, ENC_LITTLE_ENDIAN);
}
else
{
*ret_item = proto_tree_add_item( tree, hf32, tvb, offset + *pathpos + 2, 4, ENC_LITTLE_ENDIAN);
}
}
if (vals == NULL)
{
proto_item_append_text( epath_item, "%s: 0x%08X", segment_name, temp_data);
}
else
{
strbuf = wmem_strbuf_new(wmem_packet_scope(), segment_name);
wmem_strbuf_append(strbuf, ": 0x%08X");
proto_item_append_text( epath_item, "%s", val_to_str( temp_data, vals , wmem_strbuf_get_str(strbuf)) );
}
if (value != NULL)
*value = temp_data;
if (packed)
{
proto_item_set_len( item, 5);
proto_item_set_len( path_item, 5);
(*pathpos) += 5;
}
else
{
proto_item_set_len( item, 6);
proto_item_set_len( path_item, 6);
(*pathpos) += 6;
}
break;
default:
expert_add_info(pinfo, epath_item, &ei_proto_log_seg_format);
return FALSE;
}
return TRUE;
}
static void
dissect_deviceid(tvbuff_t *tvb, int offset, proto_tree *tree,
int hf_vendor, int hf_devtype, int hf_prodcode,
int hf_compatibility, int hf_comp_bit, int hf_majrev, int hf_minrev)
{
guint compatibility;
proto_item *compatibility_item;
proto_item *compatibility_tree;
proto_tree_add_item(tree, hf_vendor, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_devtype, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_prodcode, tvb, offset+4, 2, ENC_LITTLE_ENDIAN);
compatibility = tvb_get_guint8( tvb, offset+6);
compatibility_item = proto_tree_add_uint_format_value(tree, hf_compatibility,
tvb, offset+6, 1, compatibility, "%s, Major Revision: %d",
val_to_str_const( ( compatibility & 0x80 )>>7, cip_com_bit_vals , "" ),
compatibility & 0x7F);
compatibility_tree = proto_item_add_subtree(compatibility_item, ett_mcsc);
proto_tree_add_item(compatibility_tree, hf_comp_bit, tvb, offset+6, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(compatibility_tree, hf_majrev, tvb, offset+6, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(tree, hf_minrev, tvb, offset+7, 1, ENC_LITTLE_ENDIAN );
}
static void
dissect_net_param16(tvbuff_t *tvb, int offset, proto_tree *tree,
int hf_net_param16, int hf_owner, int hf_type,
int hf_priority, int hf_fixed_var, int hf_con_size, gint ncp_ett)
{
proto_item *net_param_item;
proto_tree *net_param_tree;
net_param_item = proto_tree_add_item(tree, hf_net_param16, tvb, offset, 2, ENC_LITTLE_ENDIAN );
net_param_tree = proto_item_add_subtree(net_param_item, ncp_ett);
proto_tree_add_item(net_param_tree, hf_owner, tvb, offset, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(net_param_tree, hf_type, tvb, offset, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(net_param_tree, hf_priority, tvb, offset, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(net_param_tree, hf_fixed_var, tvb, offset, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(net_param_tree, hf_con_size, tvb, offset, 2, ENC_LITTLE_ENDIAN );
}
static void
dissect_net_param32(tvbuff_t *tvb, int offset, proto_tree *tree,
int hf_net_param16, int hf_owner, int hf_type,
int hf_priority, int hf_fixed_var, int hf_con_size, gint ncp_ett)
{
proto_item *net_param_item;
proto_tree *net_param_tree;
net_param_item = proto_tree_add_item(tree, hf_net_param16, tvb, offset, 4, ENC_LITTLE_ENDIAN );
net_param_tree = proto_item_add_subtree(net_param_item, ncp_ett);
proto_tree_add_item(net_param_tree, hf_owner, tvb, offset, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(net_param_tree, hf_type, tvb, offset, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(net_param_tree, hf_priority, tvb, offset, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(net_param_tree, hf_fixed_var, tvb, offset, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(net_param_tree, hf_con_size, tvb, offset, 4, ENC_LITTLE_ENDIAN );
}
static void
dissect_transport_type_trigger(tvbuff_t *tvb, int offset, proto_tree *tree,
int hf_ttt, int hf_direction, int hf_trigger, int hf_class, gint ett)
{
proto_item *ttt_item;
proto_tree *ttt_tree;
ttt_item = proto_tree_add_item(tree, hf_ttt, tvb, offset, 1, ENC_LITTLE_ENDIAN );
ttt_tree = proto_item_add_subtree(ttt_item, ett);
proto_tree_add_item(ttt_tree, hf_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(ttt_tree, hf_trigger, tvb, offset, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(ttt_tree, hf_class, tvb, offset, 1, ENC_LITTLE_ENDIAN );
}
void dissect_epath( tvbuff_t *tvb, packet_info *pinfo, proto_item *epath_item, int offset, int path_length,
gboolean generate, gboolean packed, cip_simple_request_info_t* req_data, cip_safety_epath_info_t* safety)
{
int pathpos, temp_data, temp_data2, seg_size, i;
unsigned char segment_type, opt_link_size;
proto_tree *path_tree, *port_tree, *net_tree;
proto_tree *cia_tree, *ds_tree, *ds_data_tree, *path_seg_tree, *safety_tree;
proto_item *it, *cia_item, *cia_ret_item, *port_item, *ds_item, *ds_data_item;
proto_item *net_item, *hidden_item, *path_seg_item, *safety_item;
attribute_info_t* att_info;
path_tree = proto_item_add_subtree( epath_item, ett_path );
if (req_data != NULL)
{
req_data->iClass = (guint32)-1;
req_data->iInstance = (guint32)-1;
req_data->iAttribute = (guint32)-1;
req_data->iMember = (guint32)-1;
}
if (safety != NULL)
safety->safety_seg = FALSE;
if ( !generate )
{
hidden_item = proto_tree_add_item(path_tree, hf_cip_epath,
tvb, offset, path_length, ENC_NA );
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
pathpos = 0;
while( pathpos < path_length )
{
if (tvb_reported_length_remaining(tvb, offset + pathpos) <= 0)
{
expert_add_info(pinfo, epath_item, &ei_mal_incomplete_epath);
return;
}
segment_type = tvb_get_guint8( tvb, offset + pathpos );
if ( generate )
{
path_seg_item = proto_tree_add_uint(path_tree, hf_cip_path_segment, NULL, 0, 0, segment_type );
PROTO_ITEM_SET_GENERATED(path_seg_item);
path_seg_tree = proto_item_add_subtree( path_seg_item, ett_path_seg );
it = proto_tree_add_uint(path_seg_tree, hf_cip_path_segment_type, NULL, 0, 0, segment_type&CI_SEGMENT_TYPE_MASK);
PROTO_ITEM_SET_GENERATED(it);
}
else
{
path_seg_item = proto_tree_add_item(path_tree, hf_cip_path_segment, tvb, offset + pathpos, 1, ENC_LITTLE_ENDIAN);
path_seg_tree = proto_item_add_subtree( path_seg_item, ett_path_seg );
proto_tree_add_item(path_seg_tree, hf_cip_path_segment_type, tvb, offset + pathpos, 1, ENC_LITTLE_ENDIAN);
}
switch( segment_type & CI_SEGMENT_TYPE_MASK )
{
case CI_PORT_SEGMENT:
if ( generate )
{
it = proto_tree_add_boolean(path_seg_tree, hf_cip_port_ex_link_addr, NULL, 0, 0, segment_type & CI_PORT_SEG_EX_LINK_ADDRESS);
PROTO_ITEM_SET_GENERATED(it);
it = proto_tree_add_uint(path_seg_tree, hf_cip_port, NULL, 0, 0, ( segment_type & 0x0F ) );
PROTO_ITEM_SET_GENERATED(it);
port_item = proto_tree_add_text(path_seg_tree, NULL, 0, 0, "Port Segment");
PROTO_ITEM_SET_GENERATED(port_item);
}
else
{
proto_tree_add_item(path_seg_tree, hf_cip_port_ex_link_addr, tvb, offset+pathpos, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(path_seg_tree, hf_cip_port, tvb, offset + pathpos, 1, ENC_LITTLE_ENDIAN);
port_item = proto_tree_add_text(path_seg_tree, tvb, offset + pathpos, 1, "Port Segment");
}
proto_item_append_text( path_seg_item, " (Port Segment)");
proto_item_append_text( epath_item, "Port: %d", ( segment_type & CI_PORT_SEG_PORT_ID_MASK ) );
port_tree = proto_item_add_subtree( port_item, ett_port_path );
if( segment_type & CI_PORT_SEG_EX_LINK_ADDRESS )
{
opt_link_size = tvb_get_guint8( tvb, offset + pathpos + 1 );
if ( generate )
{
it = proto_tree_add_uint(port_tree, hf_cip_link_address_size, NULL, 0, 0, opt_link_size);
PROTO_ITEM_SET_GENERATED(it);
it = proto_tree_add_string(port_tree, hf_cip_link_address_string, NULL, 0, 0, tvb_format_text(tvb, offset+pathpos+2, opt_link_size) );
PROTO_ITEM_SET_GENERATED(it);
}
else
{
proto_tree_add_item( port_tree, hf_cip_link_address_size, tvb, offset+pathpos+1, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item( port_tree, hf_cip_link_address_string, tvb, offset+pathpos+2, opt_link_size, ENC_ASCII|ENC_NA );
}
proto_item_append_text( epath_item, ", Address: %s", tvb_format_text(tvb, offset+pathpos+2, opt_link_size) );
if( opt_link_size % 2 )
{
proto_item_set_len( port_item, 3 + opt_link_size );
proto_item_set_len( path_seg_item, 3 + opt_link_size );
pathpos += (3 + opt_link_size);
}
else
{
proto_item_set_len( port_item, 2 + opt_link_size );
proto_item_set_len( path_seg_item, 2 + opt_link_size );
pathpos += (2 + opt_link_size);
}
}
else
{
if ( generate )
{
it = proto_tree_add_uint(port_tree, hf_cip_link_address_byte, NULL, 0, 0, tvb_get_guint8( tvb, offset + pathpos + 1 ) );
PROTO_ITEM_SET_GENERATED(it);
}
else
{
proto_tree_add_item(port_tree, hf_cip_link_address_byte, tvb, offset+pathpos+1, 1, ENC_LITTLE_ENDIAN );
}
proto_item_append_text( epath_item, ", Address: %d",tvb_get_guint8( tvb, offset + pathpos + 1 ) );
proto_item_set_len( port_item, 2 );
proto_item_set_len( path_seg_item, 2);
pathpos += 2;
}
break;
case CI_LOGICAL_SEGMENT:
if ( generate )
{
it = proto_tree_add_uint(path_seg_tree, hf_cip_logical_seg_type, NULL, 0, 0, segment_type & CI_LOGICAL_SEG_TYPE_MASK);
PROTO_ITEM_SET_GENERATED(it);
if ((segment_type & CI_LOGICAL_SEG_TYPE_MASK) <= CI_LOGICAL_SEG_ATTR_ID)
{
it = proto_tree_add_uint(path_seg_tree, hf_cip_logical_seg_format, NULL, 0, 0, segment_type & CI_LOGICAL_SEG_FORMAT_MASK);
PROTO_ITEM_SET_GENERATED(it);
}
cia_item = proto_tree_add_text(path_seg_tree, NULL, 0, 0, "%s", val_to_str_const( ((segment_type & (CI_LOGICAL_SEG_TYPE_MASK|CI_LOGICAL_SEG_FORMAT_MASK))), cip_logical_seg_vals, "Reserved"));
PROTO_ITEM_SET_GENERATED(cia_item);
}
else
{
proto_tree_add_item(path_seg_tree, hf_cip_logical_seg_type, tvb, offset+pathpos, 1, ENC_LITTLE_ENDIAN );
if ((segment_type & CI_LOGICAL_SEG_TYPE_MASK) <= CI_LOGICAL_SEG_ATTR_ID)
proto_tree_add_item(path_seg_tree, hf_cip_logical_seg_format, tvb, offset + pathpos, 1, ENC_LITTLE_ENDIAN);
cia_item = proto_tree_add_text(path_seg_tree, tvb, offset + pathpos, 1, "%s", val_to_str_const( ((segment_type & (CI_LOGICAL_SEG_TYPE_MASK|CI_LOGICAL_SEG_FORMAT_MASK))), cip_logical_seg_vals, "Reserved"));
}
proto_item_append_text( path_seg_item, " (%s)", val_to_str_const( ((segment_type & (CI_LOGICAL_SEG_TYPE_MASK|CI_LOGICAL_SEG_FORMAT_MASK))), cip_logical_seg_vals, "Reserved"));
cia_tree = proto_item_add_subtree( cia_item, ett_cia_path );
switch( segment_type & CI_LOGICAL_SEG_TYPE_MASK )
{
case CI_LOGICAL_SEG_CLASS_ID:
if (dissect_cia(tvb, offset, &pathpos, segment_type & CI_LOGICAL_SEG_FORMAT_MASK, generate, packed, pinfo,
epath_item, cia_item, cia_tree, path_seg_item, &cia_ret_item,
"Class", cip_class_names_vals, (req_data == NULL) ? NULL : &req_data->iClass,
hf_cip_class8, hf_cip_class16, hf_cip_class32) == FALSE)
return;
break;
case CI_LOGICAL_SEG_INST_ID:
if (dissect_cia(tvb, offset, &pathpos, segment_type & CI_LOGICAL_SEG_FORMAT_MASK, generate, packed, pinfo,
epath_item, cia_item, cia_tree, path_seg_item, &cia_ret_item,
"Instance", NULL, (req_data == NULL) ? NULL : &req_data->iInstance,
hf_cip_instance8, hf_cip_instance16, hf_cip_instance32) == FALSE)
return;
break;
case CI_LOGICAL_SEG_MBR_ID:
if (dissect_cia(tvb, offset, &pathpos, segment_type & CI_LOGICAL_SEG_FORMAT_MASK, generate, packed, pinfo,
epath_item, cia_item, cia_tree, path_seg_item, &cia_ret_item,
"Member", NULL, (req_data == NULL) ? NULL : &req_data->iMember,
hf_cip_member8, hf_cip_member16, hf_cip_member32) == FALSE)
return;
break;
case CI_LOGICAL_SEG_ATTR_ID:
if (dissect_cia(tvb, offset, &pathpos, segment_type & CI_LOGICAL_SEG_FORMAT_MASK, generate, packed, pinfo,
epath_item, cia_item, cia_tree, path_seg_item, &cia_ret_item,
"Attribute", NULL, (req_data == NULL) ? NULL : &req_data->iAttribute,
hf_cip_attribute8, hf_cip_attribute16, hf_cip_attribute32) == FALSE)
return;
if (req_data != NULL)
{
att_info = cip_get_attribute(req_data->iClass, req_data->iInstance,
req_data->iAttribute);
if (att_info != NULL)
{
proto_item_append_text(cia_ret_item, " (%s)", att_info->text);
proto_item_append_text(epath_item, " (%s)", att_info->text);
}
}
break;
case CI_LOGICAL_SEG_CON_POINT:
if (dissect_cia(tvb, offset, &pathpos, segment_type & CI_LOGICAL_SEG_FORMAT_MASK, generate, packed, pinfo,
epath_item, cia_item, cia_tree, path_seg_item, &cia_ret_item,
"Connection Point", NULL, NULL,
hf_cip_conpoint8, hf_cip_conpoint16, hf_cip_conpoint32) == FALSE)
return;
break;
case CI_LOGICAL_SEG_SPECIAL:
if( ( segment_type & CI_LOGICAL_SEG_FORMAT_MASK ) == CI_LOGICAL_SEG_E_KEY )
{
temp_data = tvb_get_guint8( tvb, offset + pathpos + 1 );
if( temp_data == CI_E_KEY_FORMAT_VAL )
{
proto_item_set_len(path_seg_item, 10);
proto_item_set_len(cia_item, 10);
proto_tree_add_item( cia_tree, hf_cip_ekey_format, tvb, offset + pathpos+1, 1, ENC_LITTLE_ENDIAN);
dissect_deviceid(tvb, offset + pathpos + 2, cia_tree,
hf_cip_ekey_vendor, hf_cip_ekey_devtype, hf_cip_ekey_prodcode,
hf_cip_ekey_compatibility, hf_cip_ekey_comp_bit, hf_cip_ekey_majorrev, hf_cip_ekey_minorrev);
temp_data = tvb_get_letohs( tvb, offset + pathpos + 2 );
proto_item_append_text( cia_tree, " (VendorID: 0x%04X", temp_data );
temp_data = tvb_get_letohs( tvb, offset + pathpos + 4 );
proto_item_append_text( cia_tree, ", DevTyp: 0x%04X", temp_data );
temp_data = tvb_get_guint8( tvb, offset + pathpos + 8 );
temp_data2 = tvb_get_guint8( tvb, offset + pathpos + 9 );
proto_item_append_text(cia_tree, ", %d.%d)", ( temp_data & 0x7F ), temp_data2 );
proto_item_append_text(epath_item, "[Key]" );
pathpos += 10;
}
else
{
expert_add_info(pinfo, epath_item, &ei_proto_electronic_key_format);
return;
}
}
else
{
expert_add_info(pinfo, epath_item, &ei_proto_special_segment_format);
return;
}
break;
default:
expert_add_info(pinfo, epath_item, &ei_proto_log_seg_type);
return;
}
break;
case CI_DATA_SEGMENT:
if ( generate )
{
it = proto_tree_add_uint(path_seg_tree, hf_cip_data_seg_type, NULL, 0, 0, segment_type & CI_DATA_SEG_TYPE_MASK);
PROTO_ITEM_SET_GENERATED(it);
ds_item = proto_tree_add_text(path_seg_tree, NULL, 0, 0, "%s", val_to_str_const( (segment_type & CI_DATA_SEG_TYPE_MASK), cip_data_segment_type_vals, "Reserved"));
PROTO_ITEM_SET_GENERATED(ds_item);
}
else
{
proto_tree_add_item(path_seg_tree, hf_cip_data_seg_type, tvb, offset+pathpos, 1, ENC_LITTLE_ENDIAN );
ds_item = proto_tree_add_text(path_seg_tree, tvb, offset + pathpos, 1, "%s", val_to_str_const( (segment_type & CI_DATA_SEG_TYPE_MASK), cip_data_segment_type_vals, "Reserved"));
}
proto_item_append_text( path_seg_item, " (%s)", val_to_str_const( (segment_type & CI_DATA_SEG_TYPE_MASK), cip_data_segment_type_vals, "Reserved"));
ds_tree = proto_item_add_subtree( ds_item, ett_data_seg );
switch( segment_type & CI_DATA_SEG_TYPE_MASK)
{
case CI_DATA_SEG_SIMPLE:
seg_size = tvb_get_guint8( tvb, offset + pathpos+1 )*2;
proto_tree_add_uint_format_value(ds_tree, hf_cip_data_seg_size,
tvb, offset + pathpos+1, 1, seg_size, "%d (words)", seg_size/2);
if( seg_size != 0 )
{
ds_data_item = proto_tree_add_text( ds_tree, tvb, offset + pathpos+2, 0, "Data" );
ds_data_tree = proto_item_add_subtree( ds_data_item, ett_data_seg_data );
for( i=0; i < seg_size/2; i ++ )
proto_tree_add_item(ds_data_tree, hf_cip_data_seg_item, tvb, offset + pathpos+2+(i*2), 2, ENC_LITTLE_ENDIAN );
proto_item_set_len(ds_data_item, seg_size);
}
proto_item_set_len( ds_item, 2 + seg_size );
proto_item_set_len( path_seg_item, 2 + seg_size );
pathpos += (2 + seg_size);
proto_item_append_text(epath_item, "[Data]" );
break;
case CI_DATA_SEG_SYMBOL:
seg_size = tvb_get_guint8( tvb, offset + pathpos+1 );
if ( generate )
{
it = proto_tree_add_uint(ds_tree, hf_cip_data_seg_type, NULL, 0, 0, seg_size);
PROTO_ITEM_SET_GENERATED(it);
}
else
proto_tree_add_item(ds_tree, hf_cip_data_seg_size, tvb, offset + pathpos+1, 1, ENC_LITTLE_ENDIAN );
if( seg_size != 0 )
{
if ( generate )
{
it = proto_tree_add_string(ds_tree, hf_cip_symbol, NULL, 0, 0, tvb_format_text(tvb, offset + pathpos + 2, seg_size));
PROTO_ITEM_SET_GENERATED(it);
}
else
proto_tree_add_item( ds_tree, hf_cip_symbol, tvb, offset + pathpos + 2, seg_size, ENC_ASCII|ENC_NA );
proto_item_append_text(epath_item, "%s", tvb_format_text(tvb, offset + pathpos + 2, seg_size));
}
if( seg_size %2 )
seg_size++;
if ( !generate )
{
proto_item_set_len( ds_item, 2 + seg_size );
proto_item_set_len( path_seg_item, 2 + seg_size );
}
pathpos += (2 + seg_size);
break;
default:
expert_add_info(pinfo, epath_item, &ei_proto_log_sub_seg_type);
return;
}
break;
case CI_NETWORK_SEGMENT:
if ( generate )
{
it = proto_tree_add_uint(path_seg_tree, hf_cip_network_seg_type, NULL, 0, 0, segment_type & CI_NETWORK_SEG_TYPE_MASK);
PROTO_ITEM_SET_GENERATED(it);
net_item = proto_tree_add_text(path_seg_tree, NULL, 0, 0, "%s", val_to_str_const( (segment_type & CI_NETWORK_SEG_TYPE_MASK), cip_network_segment_type_vals, "Reserved"));
PROTO_ITEM_SET_GENERATED(net_item);
}
else
{
proto_tree_add_item(path_seg_tree, hf_cip_network_seg_type, tvb, offset+pathpos, 1, ENC_LITTLE_ENDIAN );
net_item = proto_tree_add_text(path_seg_tree, tvb, offset + pathpos, 1, "%s", val_to_str_const( (segment_type & CI_NETWORK_SEG_TYPE_MASK), cip_network_segment_type_vals, "Reserved"));
}
proto_item_append_text( path_seg_item, " (%s)", val_to_str_const( (segment_type & CI_NETWORK_SEG_TYPE_MASK), cip_network_segment_type_vals, "Reserved"));
net_tree = proto_item_add_subtree( net_item, ett_network_seg );
switch( segment_type & CI_NETWORK_SEG_TYPE_MASK )
{
case CI_NETWORK_SEG_SCHEDULE:
proto_tree_add_item(net_tree, hf_cip_seg_schedule, tvb, offset+pathpos+1, 1, ENC_LITTLE_ENDIAN );
proto_item_set_len( net_item, 2);
proto_item_set_len( path_seg_item, 2);
pathpos += 2;
break;
case CI_NETWORK_SEG_FIXED_TAG:
proto_tree_add_item(net_tree, hf_cip_seg_fixed_tag, tvb, offset+pathpos+1, 1, ENC_LITTLE_ENDIAN );
proto_item_set_len( net_item, 2);
proto_item_set_len( path_seg_item, 2);
pathpos += 2;
break;
case CI_NETWORK_SEG_PROD_INHI:
temp_data = tvb_get_guint8( tvb, offset + pathpos + 1 );
proto_tree_add_uint_format_value(net_tree, hf_cip_seg_prod_inhibit_time,
tvb, offset + pathpos+1, 1, temp_data, "%dms", temp_data);
proto_item_set_len( net_item, 2);
proto_item_set_len( path_seg_item, 2);
pathpos += 2;
break;
case CI_NETWORK_SEG_SAFETY:
proto_item_append_text(epath_item, "[Safety]" );
seg_size = tvb_get_guint8( tvb, offset + pathpos+1 )*2;
proto_tree_add_uint_format_value(net_tree, hf_cip_seg_network_size,
tvb, offset + pathpos+1, 1, seg_size/2, "%d (words)", seg_size/2);
proto_tree_add_item(net_tree, hf_cip_seg_safety_format, tvb, offset+pathpos+2, 1, ENC_LITTLE_ENDIAN );
temp_data = tvb_get_guint8( tvb, offset + pathpos + 2 );
if (temp_data < 3)
{
safety_item = proto_tree_add_text(net_tree, tvb, offset + pathpos+3, seg_size-1, "%s", val_to_str_const(temp_data, cip_safety_segment_format_type_vals, "Reserved"));
safety_tree = proto_item_add_subtree( safety_item, ett_network_seg_safety );
switch (temp_data)
{
case 0:
if (safety != NULL)
safety->format = CIP_SAFETY_BASE_FORMAT;
proto_tree_add_item(safety_tree, hf_cip_seg_safety_reserved, tvb, offset+pathpos+3, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_configuration_crc, tvb, offset+pathpos+4, 4, ENC_LITTLE_ENDIAN );
dissect_cipsafety_ssn(safety_tree, tvb, pinfo, offset+pathpos+8, hf_cip_seg_safety_configuration_timestamp, hf_cip_seg_safety_configuration_date, hf_cip_seg_safety_configuration_time);
proto_tree_add_item(safety_tree, hf_cip_seg_safety_time_correction_epi, tvb, offset+pathpos+14, 4, ENC_LITTLE_ENDIAN );
dissect_net_param16(tvb, offset+pathpos+18, safety_tree,
hf_cip_seg_safety_time_correction_net_params, hf_cip_seg_safety_time_correction_own,
hf_cip_seg_safety_time_correction_typ, hf_cip_seg_safety_time_correction_prio,
hf_cip_seg_safety_time_correction_fixed_var, hf_cip_seg_safety_time_correction_con_size,
ett_network_seg_safety_time_correction_net_params);
it = proto_tree_add_item(safety_tree, hf_cip_seg_safety_tunid, tvb, offset+pathpos+20, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+pathpos+20, it, "Target UNID SNN", hf_cip_seg_safety_tunid_ssn_timestamp,
hf_cip_seg_safety_tunid_ssn_date, hf_cip_seg_safety_tunid_ssn_time, hf_cip_seg_safety_tunid_macid,
ett_cip_seg_safety_tunid, ett_cip_seg_safety_tunid_ssn);
it = proto_tree_add_item(safety_tree, hf_cip_seg_safety_ounid, tvb, offset+pathpos+30, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+pathpos+30, it, "Originator UNID SSN", hf_cip_seg_safety_ounid_ssn_timestamp,
hf_cip_seg_safety_ounid_ssn_date, hf_cip_seg_safety_ounid_ssn_time, hf_cip_seg_safety_ounid_macid,
ett_cip_seg_safety_ounid, ett_cip_seg_safety_ounid_ssn);
proto_tree_add_item(safety_tree, hf_cip_seg_safety_ping_eri_multiplier, tvb, offset+pathpos+40, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_time_coord_msg_min_multiplier, tvb, offset+pathpos+42, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_network_time_expected_multiplier, tvb, offset+pathpos+44, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_timeout_multiplier, tvb, offset+pathpos+46, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_max_consumer_number, tvb, offset+pathpos+47, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_conn_param_crc, tvb, offset+pathpos+48, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_time_correction_conn_id, tvb, offset+pathpos+52, 4, ENC_LITTLE_ENDIAN );
break;
case 1:
if (safety != NULL)
safety->format = CIP_SAFETY_BASE_FORMAT;
proto_tree_add_item(safety_tree, hf_cip_seg_safety_reserved, tvb, offset+pathpos+3, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_time_correction_conn_id, tvb, offset+pathpos+4, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_ping_eri_multiplier, tvb, offset+pathpos+8, 2, ENC_LITTLE_ENDIAN );
dissect_net_param16(tvb, offset+pathpos+10, safety_tree,
hf_cip_seg_safety_time_correction_net_params, hf_cip_seg_safety_time_correction_own,
hf_cip_seg_safety_time_correction_typ, hf_cip_seg_safety_time_correction_prio,
hf_cip_seg_safety_time_correction_fixed_var, hf_cip_seg_safety_time_correction_con_size,
ett_network_seg_safety_time_correction_net_params);
break;
case 2:
if (safety != NULL)
safety->format = CIP_SAFETY_EXTENDED_FORMAT;
proto_tree_add_item(safety_tree, hf_cip_seg_safety_reserved, tvb, offset+pathpos+3, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_configuration_crc, tvb, offset+pathpos+4, 4, ENC_LITTLE_ENDIAN );
dissect_cipsafety_ssn(safety_tree, tvb, pinfo, offset+pathpos+8, hf_cip_seg_safety_configuration_timestamp, hf_cip_seg_safety_configuration_date, hf_cip_seg_safety_configuration_time);
proto_tree_add_item(safety_tree, hf_cip_seg_safety_time_correction_epi, tvb, offset+pathpos+14, 4, ENC_LITTLE_ENDIAN );
dissect_net_param16(tvb, offset+pathpos+18, safety_tree,
hf_cip_seg_safety_time_correction_net_params, hf_cip_seg_safety_time_correction_own,
hf_cip_seg_safety_time_correction_typ, hf_cip_seg_safety_time_correction_prio,
hf_cip_seg_safety_time_correction_fixed_var, hf_cip_seg_safety_time_correction_con_size,
ett_network_seg_safety_time_correction_net_params);
it = proto_tree_add_item(safety_tree, hf_cip_seg_safety_tunid, tvb, offset+pathpos+20, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+pathpos+20, it, "Target UNID SNN", hf_cip_seg_safety_tunid_ssn_timestamp,
hf_cip_seg_safety_tunid_ssn_date, hf_cip_seg_safety_tunid_ssn_time, hf_cip_seg_safety_tunid_macid,
ett_cip_seg_safety_tunid, ett_cip_seg_safety_tunid_ssn);
it = proto_tree_add_item(safety_tree, hf_cip_seg_safety_ounid, tvb, offset+pathpos+30, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+pathpos+30, it, "Originator UNID SSN", hf_cip_seg_safety_ounid_ssn_timestamp,
hf_cip_seg_safety_ounid_ssn_date, hf_cip_seg_safety_ounid_ssn_time, hf_cip_seg_safety_ounid_macid,
ett_cip_seg_safety_ounid, ett_cip_seg_safety_ounid_ssn);
proto_tree_add_item(safety_tree, hf_cip_seg_safety_ping_eri_multiplier, tvb, offset+pathpos+40, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_time_coord_msg_min_multiplier, tvb, offset+pathpos+42, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_network_time_expected_multiplier, tvb, offset+pathpos+44, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_timeout_multiplier, tvb, offset+pathpos+46, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_max_consumer_number, tvb, offset+pathpos+47, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_max_fault_number, tvb, offset+pathpos+48, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_conn_param_crc, tvb, offset+pathpos+50, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_time_correction_conn_id, tvb, offset+pathpos+54, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_init_timestamp, tvb, offset+pathpos+58, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(safety_tree, hf_cip_seg_safety_init_rollover, tvb, offset+pathpos+60, 2, ENC_LITTLE_ENDIAN );
break;
}
}
else
{
proto_tree_add_item(net_tree, hf_cip_seg_safety_data, tvb, offset+pathpos+3, seg_size-1, ENC_NA );
}
if (safety != NULL)
safety->safety_seg = TRUE;
proto_item_set_len( net_item, seg_size+2);
proto_item_set_len( path_seg_item, seg_size+2);
pathpos += (seg_size+2);
break;
default:
expert_add_info(pinfo, epath_item, &ei_proto_log_sub_seg_type);
return;
}
break;
default:
expert_add_info(pinfo, epath_item, &ei_proto_seg_type);
return;
}
if( pathpos < path_length )
proto_item_append_text( epath_item, ", " );
}
}
void dissect_cip_date_and_time(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_datetime)
{
nstime_t computed_time;
guint16 num_days_since_1972;
guint32 num_ms_today;
num_days_since_1972 = tvb_get_letohs( tvb, offset);
num_ms_today = tvb_get_letohl( tvb, offset+2 );
if ((num_days_since_1972 != 0) || (num_ms_today != 0))
{
computed_time.secs = CIP_TIMEBASE+(num_days_since_1972*60*60*24);
computed_time.secs += num_ms_today/1000;
computed_time.nsecs = (num_ms_today%1000)*1000000;
}
else
{
computed_time.secs = 0;
computed_time.nsecs = 0;
}
proto_tree_add_time(tree, hf_datetime, tvb, offset, 6, &computed_time);
}
static int
dissect_cip_attribute(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
attribute_info_t* attr, int offset, int total_len)
{
int i, temp_data, temp_time, hour, min, sec, ms,
consumed = 0;
time_t computed_time;
struct tm* date;
char date_str[20];
if (((attr->datatype == cip_dissector_func) && (attr->pdissect == NULL)) ||
((attr->datatype != cip_dissector_func) && (attr->phf == NULL)))
{
DISSECTOR_ASSERT(0);
return total_len;
}
switch (attr->datatype)
{
case cip_bool:
case cip_usint:
case cip_sint:
case cip_byte:
proto_tree_add_item(tree, *(attr->phf), tvb, offset, 1, ENC_LITTLE_ENDIAN);
consumed = 1;
break;
case cip_uint:
case cip_int:
case cip_word:
case cip_itime:
proto_tree_add_item(tree, *(attr->phf), tvb, offset, 2, ENC_LITTLE_ENDIAN);
consumed = 2;
break;
case cip_byte_array:
proto_tree_add_item(tree, *(attr->phf), tvb, offset, total_len, ENC_NA);
consumed = total_len;
break;
case cip_usint_array:
for (i = 0; i < total_len; i++)
proto_tree_add_item(tree, *(attr->phf), tvb, offset, total_len, ENC_NA);
consumed = total_len;
break;
case cip_uint_array:
for (i = 0; i < total_len; i+=2)
proto_tree_add_item(tree, *(attr->phf), tvb, offset+i, 2, ENC_LITTLE_ENDIAN);
consumed = i;
break;
case cip_udint:
case cip_dint:
case cip_dword:
case cip_real:
case cip_time:
case cip_ftime:
proto_tree_add_item(tree, *(attr->phf), tvb, offset, 4, ENC_LITTLE_ENDIAN);
consumed = 4;
break;
case cip_ulint:
case cip_lint:
case cip_lword:
case cip_lreal:
case cip_ltime:
proto_tree_add_item(tree, *(attr->phf), tvb, offset, 8, ENC_LITTLE_ENDIAN);
consumed = 8;
break;
case cip_short_string:
temp_data = tvb_get_guint8( tvb, offset );
proto_tree_add_item(tree, *(attr->phf), tvb, offset+1, temp_data, ENC_ASCII|ENC_NA);
consumed = 1+temp_data;
break;
case cip_string:
temp_data = tvb_get_letohs( tvb, offset );
proto_tree_add_item(tree, *(attr->phf), tvb, offset+2, temp_data, ENC_ASCII|ENC_NA);
consumed = 2+temp_data;
break;
case cip_dissector_func:
consumed = attr->pdissect(pinfo, tree, item, tvb, offset, total_len);
break;
case cip_date_and_time:
dissect_cip_date_and_time(tree, tvb, offset, *(attr->phf));
consumed = 6;
break;
case cip_date:
temp_data = tvb_get_letohs( tvb, offset);
computed_time = CIP_TIMEBASE+(temp_data*60*60*24);
date = gmtime(&computed_time);
strftime(date_str, 20, "%b %d, %Y", date);
proto_tree_add_uint_format_value(tree, *(attr->phf), tvb, offset, 2, temp_data, "%s", date_str);
consumed = 2;
break;
case cip_time_of_day:
temp_time = temp_data = tvb_get_letohl( tvb, offset);
hour = temp_time/(60*60*1000);
temp_time %= (60*60*1000);
min = temp_time/(60*1000);
temp_time %= (60*1000);
sec = temp_time/1000;
ms = temp_time%1000;
proto_tree_add_uint_format_value(tree, *(attr->phf), tvb, offset, 4, temp_data, "%02d:%02d:%02d.%03d", hour, min, sec, ms);
consumed = 4;
break;
case cip_string2:
case cip_stringN:
case cip_stringi:
expert_add_info(pinfo, item, &ei_proto_unsupported_datatype);
consumed = total_len;
break;
}
return consumed;
}
static void
dissect_cip_generic_data( proto_tree *item_tree, tvbuff_t *tvb, int offset, int item_length, packet_info *pinfo, proto_item *ti )
{
proto_item *pi;
proto_tree *cmd_data_tree;
int req_path_size;
unsigned char add_stat_size;
guint8 service = tvb_get_guint8( tvb, offset );
if (service & 0x80)
{
add_stat_size = tvb_get_guint8( tvb, offset+3 ) * 2;
if( ( item_length-4-add_stat_size ) != 0 )
{
pi = proto_tree_add_text( item_tree, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, "Command Specific Data" );
cmd_data_tree = proto_item_add_subtree( pi, ett_cmd_data );
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
}
else
{
PROTO_ITEM_SET_HIDDEN( ti );
}
}
else
{
add_cip_service_to_info_column(pinfo, service, cip_sc_vals);
req_path_size = tvb_get_guint8( tvb, offset+1 )*2;
if( (item_length-req_path_size-2) != 0 )
{
pi = proto_tree_add_text( item_tree, tvb, offset+2+req_path_size, item_length-req_path_size-2, "Command Specific Data" );
cmd_data_tree = proto_item_add_subtree( pi, ett_cmd_data );
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+2+req_path_size, item_length-req_path_size-2, ENC_NA);
}
else
{
PROTO_ITEM_SET_HIDDEN( ti );
}
}
}
static int
dissect_cip_class_generic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *class_tree;
ti = proto_tree_add_item(tree, proto_cip_class_generic, tvb, 0, -1, ENC_NA);
class_tree = proto_item_add_subtree( ti, ett_cip_class_generic );
dissect_cip_generic_data( class_tree, tvb, 0, tvb_length(tvb), pinfo, ti );
return tvb_length(tvb);
}
static void
dissect_cip_set_attribute_single_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item * item,
int offset, cip_simple_request_info_t* req_data)
{
attribute_info_t* attr;
attr = cip_get_attribute(req_data->iClass, req_data->iInstance, req_data->iAttribute);
if (attr != NULL)
{
dissect_cip_attribute(pinfo, tree, item, tvb, attr, offset, tvb_reported_length_remaining(tvb, offset));
}
else
{
proto_tree_add_item(tree, hf_cip_sc_set_attr_single_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
}
}
static void
dissect_cip_get_attribute_list_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item * item,
int offset, cip_simple_request_info_t* req_data)
{
int i, att_count, att_value;
attribute_info_t* pattribute;
proto_item *att_list, *att_item;
proto_tree* att_tree;
if (tvb_reported_length_remaining(tvb, offset) < 2)
{
expert_add_info(pinfo, item, &ei_mal_serv_gal);
return;
}
att_count = tvb_get_letohs( tvb, offset);
proto_tree_add_item(tree, hf_cip_sc_get_attr_list_attr_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
att_list = proto_tree_add_text(tree, tvb, offset+2, att_count*2, "Attribute List" );
att_tree = proto_item_add_subtree( att_list, ett_cip_get_attribute_list);
for( i=0; i < att_count; i++ )
{
att_value = tvb_get_letohs( tvb, offset+2);
att_item = proto_tree_add_item(att_tree, hf_cip_sc_get_attr_list_attr_item, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
pattribute = cip_get_attribute(req_data->iClass, req_data->iInstance, att_value);
if (pattribute != NULL)
proto_item_append_text(att_item, " (%s)", pattribute->text);
offset += 2;
if ((tvb_reported_length_remaining(tvb, offset+2) < 2) && (i < att_count-1))
{
expert_add_info(pinfo, att_list, &ei_mal_serv_gal_count);
break;
}
}
}
static void
dissect_cip_set_attribute_list_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item * item,
int offset, cip_simple_request_info_t* req_data)
{
int i, start_offset, att_count,
att_value, att_size;
attribute_info_t* attr;
proto_item *att_list, *att_item;
proto_tree *att_tree, *att_list_tree;
if (tvb_reported_length_remaining(tvb, offset) < 2)
{
expert_add_info(pinfo, item, &ei_mal_serv_sal);
return;
}
att_count = tvb_get_letohs( tvb, offset);
proto_tree_add_item(tree, hf_cip_sc_set_attr_list_attr_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
att_list = proto_tree_add_text(tree, tvb, offset+2, att_count*4, "Attribute List" );
att_list_tree = proto_item_add_subtree( att_list, ett_cip_set_attribute_list);
offset += 2;
start_offset = offset;
for( i=0; i < att_count; i++ )
{
att_value = tvb_get_letohs( tvb, offset);
att_item = proto_tree_add_item(att_list_tree, hf_cip_sc_set_attr_list_attr_item, tvb, offset, 2, ENC_LITTLE_ENDIAN);
att_tree = proto_item_add_subtree( att_item, ett_cip_set_attribute_list_item);
offset += 2;
attr = cip_get_attribute(req_data->iClass, req_data->iInstance, att_value);
if (attr != NULL)
{
proto_item_append_text(att_item, " (%s)", attr->text);
att_size = dissect_cip_attribute(pinfo, att_tree, att_item, tvb, attr, offset, tvb_reported_length_remaining(tvb, offset));
offset += att_size;
proto_item_set_len(att_item, att_size+4);
}
else
{
proto_tree_add_item(att_tree, hf_cip_sc_set_attr_list_attr_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
}
if ((tvb_reported_length_remaining(tvb, offset) < 2) && (i < att_count-1))
{
expert_add_info(pinfo, att_list, &ei_mal_serv_sal_count);
break;
}
}
proto_item_set_len(att_list, offset-start_offset );
}
static void
dissect_cip_multiple_service_packet_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item * item, int offset)
{
proto_item *mult_serv_item, *ti;
proto_tree *mult_serv_tree;
int i, num_services, serv_offset, prev_offset = 0;
cip_req_info_t *cip_req_info, *mr_single_req_info;
mr_mult_req_info_t *mr_mult_req_info = NULL;
num_services = tvb_get_letohs( tvb, offset);
ti = proto_tree_add_item(tree, hf_cip_sc_mult_serv_pack_num_services, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (num_services*2 > tvb_reported_length_remaining(tvb, offset+2))
{
expert_add_info(pinfo, ti, &ei_mal_msp_services);
}
else
{
cip_req_info = (cip_req_info_t*)p_get_proto_data( pinfo->fd, proto_cip, 0 );
if ( cip_req_info )
{
if ( cip_req_info->pData == NULL )
{
mr_mult_req_info = wmem_new(wmem_file_scope(), mr_mult_req_info_t);
mr_mult_req_info->service = SC_MULT_SERV_PACK;
mr_mult_req_info->num_services = num_services;
mr_mult_req_info->requests = (cip_req_info_t *)wmem_alloc0(wmem_file_scope(), sizeof(cip_req_info_t)*num_services);
cip_req_info->pData = mr_mult_req_info;
}
else
{
mr_mult_req_info = (mr_mult_req_info_t*)cip_req_info->pData;
if ( mr_mult_req_info && mr_mult_req_info->num_services != num_services )
mr_mult_req_info = NULL;
}
}
}
for( i=0; i < num_services; i++ )
{
int serv_length;
tvbuff_t *next_tvb;
serv_offset = tvb_get_letohs( tvb, offset+2+(i*2) );
if (tvb_reported_length_remaining(tvb, serv_offset) <= 0)
{
expert_add_info(pinfo, item, &ei_mal_msp_inv_offset);
continue;
}
if( i == (num_services-1) )
{
serv_length = tvb_reported_length_remaining(tvb, offset)-serv_offset;
}
else
{
serv_length = tvb_get_letohs( tvb, offset+2+((i+1)*2) ) - serv_offset;
}
mult_serv_item = proto_tree_add_text(tree, tvb, offset+serv_offset, serv_length, "Service Packet #%d", i+1 );
mult_serv_tree = proto_item_add_subtree(mult_serv_item, ett_cip_mult_service_packet );
proto_tree_add_item(mult_serv_tree, hf_cip_sc_mult_serv_pack_offset, tvb, offset+2+(i*2) , 2, ENC_LITTLE_ENDIAN);
if ((tvb_reported_length_remaining(tvb, serv_offset) <= 0) ||
(tvb_reported_length_remaining(tvb, serv_offset+serv_length) <= 0) ||
(serv_length <= 0) ||
(prev_offset >= serv_offset))
{
expert_add_info(pinfo, mult_serv_item, &ei_mal_msp_inv_offset);
prev_offset = serv_offset;
continue;
}
prev_offset = serv_offset;
col_append_str( pinfo->cinfo, COL_INFO, ", ");
next_tvb = tvb_new_subset(tvb, offset+serv_offset, serv_length, serv_length);
if ( mr_mult_req_info )
{
mr_single_req_info = mr_mult_req_info->requests + i;
dissect_cip_data(mult_serv_tree, next_tvb, 0, pinfo, mr_single_req_info );
}
else
{
dissect_cip_data(mult_serv_tree, next_tvb, 0, pinfo, NULL );
}
}
}
static int
dissect_cip_generic_service_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, cip_simple_request_info_t* req_data)
{
proto_item *cmd_data_item;
int req_path_size,
offset = 0;
proto_tree *cmd_data_tree;
guint8 service = tvb_get_guint8( tvb, offset ) & 0x7F;
add_cip_service_to_info_column(pinfo, service, cip_sc_vals);
cmd_data_item = proto_tree_add_text(tree, tvb, 0, tvb_length(tvb), "%s",
val_to_str(service, cip_sc_vals , "Unknown Service (0x%02x)"));
proto_item_append_text(cmd_data_item, " (Request)");
cmd_data_tree = proto_item_add_subtree( cmd_data_item, ett_cmd_data );
req_path_size = tvb_get_guint8( tvb, offset+1);
offset += ((req_path_size*2)+2);
if (tvb_reported_length_remaining(tvb, offset) <= 0)
return tvb_reported_length(tvb);
switch(service)
{
case SC_GET_ATT_ALL:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_get_attribute_all_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_SET_ATT_ALL:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_set_attribute_all_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_GET_ATT_LIST:
dissect_cip_get_attribute_list_req(tvb, pinfo, cmd_data_tree, cmd_data_item, offset, req_data);
break;
case SC_SET_ATT_LIST:
dissect_cip_set_attribute_list_req(tvb, pinfo, cmd_data_tree, cmd_data_item, offset, req_data);
break;
case SC_RESET:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_reset_param, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_sc_reset_data, tvb, offset+1, tvb_reported_length_remaining(tvb, offset+1), ENC_NA);
break;
case SC_START:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_start_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_STOP:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_stop_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_CREATE:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_create_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_DELETE:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_delete_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_MULT_SERV_PACK:
dissect_cip_multiple_service_packet_req(tvb, pinfo, cmd_data_tree, cmd_data_item, offset);
break;
case SC_APPLY_ATTRIBUTES:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_apply_attributes_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_GET_ATT_SINGLE:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_get_attr_single_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_SET_ATT_SINGLE:
dissect_cip_set_attribute_single_req(tvb, pinfo, cmd_data_tree, cmd_data_item, offset, req_data);
break;
case SC_FIND_NEXT_OBJ_INST:
proto_tree_add_item(cmd_data_tree, hf_cip_find_next_object_max_instance, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case SC_RESTOR:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_restore_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_SAVE:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_save_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_NO_OP:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_noop_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_GET_MEMBER:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_get_member_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_SET_MEMBER:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_set_member_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_INSERT_MEMBER:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_insert_member_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_REMOVE_MEMBER:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_remove_member_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_GROUP_SYNC:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_group_sync_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
}
return tvb_length(tvb);
}
static void
dissect_cip_get_attribute_list_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item * item,
int offset, cip_simple_request_info_t* req_data)
{
int i, start_offset, att_count,
att_value, att_status;
guint att_size;
attribute_info_t* attr;
proto_item *att_list, *att_item;
proto_tree *att_tree, *att_list_tree;
if (tvb_reported_length_remaining(tvb, offset) < 2)
{
expert_add_info(pinfo, item, &ei_mal_serv_gal);
return;
}
att_count = tvb_get_letohs( tvb, offset);
proto_tree_add_item(tree, hf_cip_sc_get_attr_list_attr_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
att_list = proto_tree_add_text(tree, tvb, offset+2, att_count*4, "Attribute List" );
att_list_tree = proto_item_add_subtree( att_list, ett_cip_get_attribute_list);
offset += 2;
start_offset = offset;
for( i=0; i < att_count; i++ )
{
att_value = tvb_get_letohs( tvb, offset);
att_item = proto_tree_add_item(att_list_tree, hf_cip_sc_get_attr_list_attr_item, tvb, offset, 2, ENC_LITTLE_ENDIAN);
att_tree = proto_item_add_subtree( att_item, ett_cip_get_attribute_list_item);
att_status = tvb_get_letohs( tvb, offset+2);
proto_tree_add_item(att_tree, hf_cip_sc_get_attr_list_attr_status, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
attr = cip_get_attribute(req_data->iClass, req_data->iInstance, att_value);
if (attr != NULL)
proto_item_append_text(att_item, " (%s)", attr->text);
offset += 4;
if (att_status == 0)
{
if (attr != NULL)
{
att_size = dissect_cip_attribute(pinfo, att_tree, att_item, tvb, attr, offset, tvb_reported_length_remaining(tvb, offset));
offset += att_size;
proto_item_set_len(att_item, att_size+4);
}
else
{
proto_tree_add_item(att_tree, hf_cip_sc_get_attr_list_attr_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
}
}
if ((tvb_reported_length_remaining(tvb, offset) < 4) && (i < att_count-1))
{
expert_add_info(pinfo, att_list, &ei_mal_serv_gal_count);
break;
}
}
proto_item_set_len(att_list, offset-start_offset );
}
static void
dissect_cip_set_attribute_list_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item * item,
int offset, cip_simple_request_info_t* req_data)
{
int i, start_offset, att_count, att_value;
attribute_info_t* attr;
proto_item *att_list, *att_item;
proto_tree *att_tree, *att_list_tree;
if (tvb_reported_length_remaining(tvb, offset) < 2)
{
expert_add_info(pinfo, item, &ei_mal_serv_sal);
return;
}
att_count = tvb_get_letohs( tvb, offset);
proto_tree_add_item(tree, hf_cip_sc_set_attr_list_attr_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
att_list = proto_tree_add_text(tree, tvb, offset+2, att_count*4, "Attribute List" );
att_list_tree = proto_item_add_subtree( att_list, ett_cip_get_attribute_list);
offset += 2;
start_offset = offset;
for( i=0; i < att_count; i++ )
{
att_value = tvb_get_letohs( tvb, offset);
att_item = proto_tree_add_item(att_list_tree, hf_cip_sc_set_attr_list_attr_item, tvb, offset, 2, ENC_LITTLE_ENDIAN);
att_tree = proto_item_add_subtree( att_item, ett_cip_set_attribute_list_item);
proto_tree_add_item(att_tree, hf_cip_sc_set_attr_list_attr_status, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
attr = cip_get_attribute(req_data->iClass, req_data->iInstance, att_value);
if (attr != NULL)
proto_item_append_text(att_item, " (%s)", attr->text);
offset += 4;
if ((tvb_reported_length_remaining(tvb, offset) < 4) && (i < att_count-1))
{
expert_add_info(pinfo, att_list, &ei_mal_serv_sal_count);
break;
}
}
proto_item_set_len(att_list, offset-start_offset );
}
static void
dissect_cip_get_attribute_single_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item * item,
int offset, cip_simple_request_info_t* req_data)
{
attribute_info_t* attr;
attr = cip_get_attribute(req_data->iClass, req_data->iInstance, req_data->iAttribute);
if (attr != NULL)
{
proto_item_append_text(item, " (%s)", attr->text);
dissect_cip_attribute(pinfo, tree, item, tvb, attr, offset, tvb_reported_length_remaining(tvb, offset));
}
else
{
proto_tree_add_item(tree, hf_cip_sc_get_attr_single_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
}
}
static void
dissect_cip_multiple_service_packet_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item * item, int offset)
{
proto_item *mult_serv_item;
proto_tree *mult_serv_tree;
int i, num_services, serv_offset;
cip_req_info_t *cip_req_info, *mr_single_req_info;
mr_mult_req_info_t *mr_mult_req_info = NULL;
if (tvb_reported_length_remaining(tvb, offset) < 2)
{
expert_add_info(pinfo, item, &ei_mal_msp_missing_services);
return;
}
num_services = tvb_get_letohs( tvb, offset);
proto_tree_add_item(tree, hf_cip_sc_mult_serv_pack_num_replies, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (tvb_reported_length_remaining(tvb, offset+((num_services+1)*2)) <= 0)
{
expert_add_info(pinfo, item, &ei_mal_msp_resp_offset);
return;
}
cip_req_info = (cip_req_info_t*)p_get_proto_data( pinfo->fd, proto_cip, 0 );
if ( cip_req_info )
{
mr_mult_req_info = (mr_mult_req_info_t*)cip_req_info->pData;
if ( mr_mult_req_info
&& ( mr_mult_req_info->service != SC_MULT_SERV_PACK
|| mr_mult_req_info->num_services != num_services
)
)
mr_mult_req_info = NULL;
}
for( i=0; i < num_services; i++ )
{
int serv_length;
tvbuff_t *next_tvb;
serv_offset = tvb_get_letohs( tvb, offset+2+(i*2) );
if (tvb_reported_length_remaining(tvb, serv_offset) <= 0)
{
expert_add_info(pinfo, item, &ei_mal_msp_inv_offset);
continue;
}
if( i == (num_services-1) )
{
serv_length = tvb_reported_length_remaining(tvb, offset)-serv_offset;
}
else
{
serv_length = tvb_get_letohs( tvb, offset+2+((i+1)*2) ) - serv_offset;
}
mult_serv_item = proto_tree_add_text( tree, tvb, offset+serv_offset, serv_length, "Service Reply #%d", i+1 );
mult_serv_tree = proto_item_add_subtree( mult_serv_item, ett_cip_mult_service_packet );
proto_tree_add_item(mult_serv_tree, hf_cip_sc_mult_serv_pack_offset, tvb, offset+2+(i*2) , 2, ENC_LITTLE_ENDIAN);
col_append_str( pinfo->cinfo, COL_INFO, ", ");
next_tvb = tvb_new_subset(tvb, offset+serv_offset, serv_length, serv_length);
if ( mr_mult_req_info )
{
mr_single_req_info = mr_mult_req_info->requests + i;
dissect_cip_data( mult_serv_tree, next_tvb, 0, pinfo, mr_single_req_info );
}
else
{
dissect_cip_data( mult_serv_tree, next_tvb, 0, pinfo, NULL );
}
}
}
static void
dissect_cip_find_next_object_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item * item, int offset)
{
guint8 i, num_instances;
if (tvb_reported_length_remaining(tvb, offset) < 1)
{
expert_add_info(pinfo, item, &ei_mal_serv_find_next_object);
return;
}
num_instances = tvb_get_guint8( tvb, offset);
proto_tree_add_item(tree, hf_cip_find_next_object_num_instances, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
for (i = 0; i < num_instances; i++)
{
proto_tree_add_item(tree, hf_cip_find_next_object_instance_item, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if ((tvb_reported_length_remaining(tvb, offset) < 2) && (i < num_instances-1))
{
expert_add_info(pinfo, item, &ei_mal_serv_find_next_object_count);
break;
}
}
}
static int
dissect_cip_generic_service_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *cmd_data_item;
proto_tree *cmd_data_tree;
cip_req_info_t* preq_info;
cip_simple_request_info_t req_data;
int offset = 0,
item_length = tvb_length(tvb);
guint8 service = tvb_get_guint8( tvb, offset ) & 0x7F,
add_stat_size = tvb_get_guint8( tvb, offset+3 ) * 2;
if( (item_length-4-add_stat_size ) != 0 )
{
cmd_data_item = proto_tree_add_text(tree, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, "%s",
val_to_str(service, cip_sc_vals , "Unknown Service (0x%02x)"));
proto_item_append_text(cmd_data_item, " (Response)");
cmd_data_tree = proto_item_add_subtree( cmd_data_item, ett_cmd_data );
}
else
{
return tvb_length(tvb);
}
preq_info = (cip_req_info_t*)p_get_proto_data(pinfo->fd, proto_cip, 0);
if ((preq_info != NULL) &&
(preq_info->ciaData != NULL))
{
memcpy(&req_data, preq_info->ciaData, sizeof(cip_simple_request_info_t));
}
else
{
req_data.iClass = (guint32)-1;
req_data.iInstance = (guint32)-1;
req_data.iAttribute = (guint32)-1;
req_data.iMember = (guint32)-1;
}
switch(service)
{
case SC_GET_ATT_ALL:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_get_attribute_all_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_SET_ATT_ALL:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_set_attribute_all_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_GET_ATT_LIST:
dissect_cip_get_attribute_list_rsp(tvb, pinfo, cmd_data_tree, cmd_data_item, offset+4+add_stat_size, &req_data);
break;
case SC_SET_ATT_LIST:
dissect_cip_set_attribute_list_rsp(tvb, pinfo, cmd_data_tree, cmd_data_item, offset+4+add_stat_size, &req_data);
break;
case SC_RESET:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_reset_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_START:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_start_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_STOP:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_stop_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_CREATE:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_create_instance, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
proto_tree_add_item(cmd_data_tree, hf_cip_sc_create_data, tvb, offset+4+add_stat_size+2, tvb_reported_length_remaining(tvb, offset+4+add_stat_size+2), ENC_NA);
break;
case SC_DELETE:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_delete_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_MULT_SERV_PACK:
dissect_cip_multiple_service_packet_rsp(tvb, pinfo, cmd_data_tree, cmd_data_item, offset+4+add_stat_size);
break;
case SC_APPLY_ATTRIBUTES:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_apply_attributes_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_GET_ATT_SINGLE:
dissect_cip_get_attribute_single_rsp(tvb, pinfo, cmd_data_tree, cmd_data_item, offset+4+add_stat_size, &req_data);
break;
case SC_SET_ATT_SINGLE:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_set_attr_single_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_FIND_NEXT_OBJ_INST:
dissect_cip_find_next_object_rsp(tvb, pinfo, cmd_data_tree, cmd_data_item, offset+4+add_stat_size);
break;
case SC_RESTOR:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_restore_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_SAVE:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_save_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_NO_OP:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_noop_data, tvb, offset+4+add_stat_size, tvb_reported_length_remaining(tvb, offset+4+add_stat_size), ENC_NA);
break;
case SC_GET_MEMBER:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_get_member_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_SET_MEMBER:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_set_member_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_INSERT_MEMBER:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_insert_member_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_REMOVE_MEMBER:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_remove_member_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case SC_GROUP_SYNC:
proto_tree_add_item(cmd_data_tree, hf_cip_sc_group_sync_is_sync, tvb, offset+4+add_stat_size, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_sc_group_sync_data, tvb, offset+4+add_stat_size+1, tvb_reported_length_remaining(tvb, offset+4+add_stat_size+1), ENC_NA);
break;
}
return tvb_length(tvb);
}
static void
dissect_cip_cm_timeout(proto_tree *cmd_tree, tvbuff_t *tvb, int offset)
{
guint8 tick, timeout_tick;
int timeout;
tick = tvb_get_guint8( tvb, offset) & 0x0F;
proto_tree_add_item( cmd_tree, hf_cip_cm_priority, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_tree, hf_cip_cm_tick_time, tvb, offset, 1, ENC_LITTLE_ENDIAN);
timeout_tick = tvb_get_guint8( tvb, offset+1 );
proto_tree_add_item( cmd_tree, hf_cip_cm_timeout_tick, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
timeout = ( 1 << tick ) * timeout_tick;
proto_tree_add_uint_format_value(cmd_tree, hf_cip_cm_timeout, tvb, offset, 2, timeout, "%dms", timeout);
}
static void
dissect_cip_cm_fwd_open_req(cip_req_info_t *preq_info, proto_tree *cmd_tree, tvbuff_t *tvb, int offset, gboolean large_fwd_open, packet_info *pinfo)
{
proto_item *pi;
int conn_path_size, rpi, net_param_offset = 0;
guint32 O2TConnID, T2OConnID, DeviceSerialNumber;
guint16 ConnSerialNumber, VendorID;
guint8 TransportClass_trigger, O2TType, T2OType;
cip_simple_request_info_t connection_path;
cip_safety_epath_info_t safety_fwdopen;
dissect_cip_cm_timeout(cmd_tree, tvb, offset);
O2TConnID = tvb_get_letohl( tvb, offset+2 );
proto_tree_add_item( cmd_tree, hf_cip_cm_ot_connid, tvb, offset+2, 4, ENC_LITTLE_ENDIAN);
T2OConnID = tvb_get_letohl( tvb, offset+6 );
proto_tree_add_item( cmd_tree, hf_cip_cm_to_connid, tvb, offset+6, 4, ENC_LITTLE_ENDIAN);
ConnSerialNumber = tvb_get_letohs( tvb, offset+10 );
proto_tree_add_item( cmd_tree, hf_cip_cm_conn_serial_num, tvb, offset+10, 2, ENC_LITTLE_ENDIAN);
VendorID = tvb_get_letohs( tvb, offset+12 );
proto_tree_add_item( cmd_tree, hf_cip_cm_vendor, tvb, offset+12, 2, ENC_LITTLE_ENDIAN);
DeviceSerialNumber = tvb_get_letohl( tvb, offset+14 );
proto_tree_add_item( cmd_tree, hf_cip_cm_orig_serial_num, tvb, offset+14, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_tree, hf_cip_cm_timeout_multiplier, tvb, offset+18, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_tree, hf_cip_reserved24, tvb, offset+19, 3, ENC_LITTLE_ENDIAN);
rpi = tvb_get_letohl( tvb, offset+22 );
proto_tree_add_uint_format_value(cmd_tree, hf_cip_cm_ot_rpi, tvb, offset+22, 4, rpi, "%dms (0x%08X)", rpi / 1000, rpi);
if (large_fwd_open)
{
dissect_net_param32(tvb, offset+26, cmd_tree,
hf_cip_cm_ot_net_params32, hf_cip_cm_lfwo_own, hf_cip_cm_lfwo_typ,
hf_cip_cm_lfwo_prio, hf_cip_cm_lfwo_fixed_var, hf_cip_cm_lfwo_con_size, ett_cm_ncp);
O2TType = (guint8)(((tvb_get_letohl( tvb, offset+26 ) & 0x60000000) >> 29) & 3);
net_param_offset = 4;
}
else
{
dissect_net_param16(tvb, offset+26, cmd_tree,
hf_cip_cm_ot_net_params16, hf_cip_cm_fwo_own, hf_cip_cm_fwo_typ,
hf_cip_cm_fwo_prio, hf_cip_cm_fwo_fixed_var, hf_cip_cm_fwo_con_size, ett_cm_ncp);
O2TType = (guint8)(((tvb_get_letohs( tvb, offset+26 ) & 0x6000) >> 13) & 3);
net_param_offset = 2;
}
rpi = tvb_get_letohl( tvb, offset+26+net_param_offset );
proto_tree_add_uint_format_value(cmd_tree, hf_cip_cm_to_rpi, tvb, offset+26+net_param_offset, 4, rpi, "%dms (0x%08X)", rpi / 1000, rpi);
if (large_fwd_open)
{
dissect_net_param32(tvb, offset+26+net_param_offset+4, cmd_tree,
hf_cip_cm_to_net_params32, hf_cip_cm_lfwo_own, hf_cip_cm_lfwo_typ,
hf_cip_cm_lfwo_prio, hf_cip_cm_lfwo_fixed_var, hf_cip_cm_lfwo_con_size, ett_cm_ncp);
T2OType = (guint8)(((tvb_get_letohl( tvb, offset+26+net_param_offset+4 ) & 0x60000000) >> 29) & 3);
net_param_offset += 4;
}
else
{
dissect_net_param16(tvb, offset+26+net_param_offset+4, cmd_tree,
hf_cip_cm_to_net_params16, hf_cip_cm_fwo_own, hf_cip_cm_fwo_typ,
hf_cip_cm_fwo_prio, hf_cip_cm_fwo_fixed_var, hf_cip_cm_fwo_con_size, ett_cm_ncp);
T2OType = (guint8)(((tvb_get_letohs( tvb, offset+26+net_param_offset+4 ) & 0x6000) >> 13) & 3);
net_param_offset += 2;
}
TransportClass_trigger = tvb_get_guint8( tvb, offset+26+net_param_offset+4);
dissect_transport_type_trigger(tvb, offset+26+net_param_offset+4, cmd_tree, hf_cip_cm_transport_type_trigger,
hf_cip_cm_fwo_dir, hf_cip_cm_fwo_trigg, hf_cip_cm_fwo_class, ett_cm_ttt);
conn_path_size = tvb_get_guint8( tvb, offset+26+net_param_offset+5 )*2;
proto_tree_add_uint_format_value(cmd_tree, hf_cip_cm_conn_path_size, tvb, offset+26+net_param_offset+5, 1, conn_path_size/2, "%d (words)", conn_path_size/2);
pi = proto_tree_add_text(cmd_tree, tvb, offset+26+net_param_offset+6, conn_path_size, "Connection Path: ");
dissect_epath( tvb, pinfo, pi, offset+26+net_param_offset+6, conn_path_size, FALSE, FALSE, &connection_path, &safety_fwdopen);
if (pinfo->fd->flags.visited)
return;
if (preq_info != NULL)
{
DISSECTOR_ASSERT(preq_info->connInfo == NULL);
preq_info->connInfo = wmem_new0(wmem_file_scope(), cip_conn_info_t);
preq_info->connInfo->ConnSerialNumber = ConnSerialNumber;
preq_info->connInfo->VendorID = VendorID;
preq_info->connInfo->DeviceSerialNumber = DeviceSerialNumber;
preq_info->connInfo->O2T.connID = O2TConnID;
preq_info->connInfo->T2O.connID = T2OConnID;
preq_info->connInfo->TransportClass_trigger = TransportClass_trigger;
preq_info->connInfo->T2O.type = T2OType;
preq_info->connInfo->O2T.type = O2TType;
preq_info->connInfo->motion = (connection_path.iClass == 0x42) ? TRUE : FALSE;
preq_info->connInfo->safety = safety_fwdopen;
}
}
static void
dissect_cip_cm_fwd_open_rsp_success(cip_req_info_t *preq_info, proto_tree *tree, tvbuff_t *tvb, int offset, packet_info *pinfo)
{
int temp_data;
unsigned char app_rep_size;
guint32 O2TConnID, T2OConnID, DeviceSerialNumber;
guint16 ConnSerialNumber, VendorID;
proto_item *ti;
proto_tree *pid_tree, *safety_tree;
O2TConnID = tvb_get_letohl( tvb, offset );
proto_tree_add_item( tree, hf_cip_cm_ot_connid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
T2OConnID = tvb_get_letohl( tvb, offset+4 );
proto_tree_add_item( tree, hf_cip_cm_to_connid, tvb, offset+4, 4, ENC_LITTLE_ENDIAN);
ConnSerialNumber = tvb_get_letohs( tvb, offset+8 );
proto_tree_add_item( tree, hf_cip_cm_conn_serial_num, tvb, offset+8, 2, ENC_LITTLE_ENDIAN);
VendorID = tvb_get_letohs( tvb, offset+10 );
proto_tree_add_item( tree, hf_cip_cm_vendor, tvb, offset+10, 2, ENC_LITTLE_ENDIAN);
DeviceSerialNumber = tvb_get_letohl( tvb, offset+12 );
proto_tree_add_item( tree, hf_cip_cm_orig_serial_num, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
temp_data = tvb_get_letohl( tvb, offset+16 );
proto_tree_add_uint_format_value(tree, hf_cip_cm_ot_api, tvb, offset+16, 4, temp_data, "%dms (0x%08X)", temp_data / 1000, temp_data);
temp_data = tvb_get_letohl( tvb, offset+20 );
proto_tree_add_uint_format_value(tree, hf_cip_cm_to_api, tvb, offset+20, 4, temp_data, "%dms (0x%08X)", temp_data / 1000, temp_data);
app_rep_size = tvb_get_guint8( tvb, offset+24 ) * 2;
proto_tree_add_uint_format_value(tree, hf_cip_cm_app_reply_size, tvb, offset+24, 1, app_rep_size / 2, "%d (words)", app_rep_size / 2);
proto_tree_add_item(tree, hf_cip_reserved8, tvb, offset+25, 1, ENC_LITTLE_ENDIAN );
if (app_rep_size > 0)
{
if ((preq_info == NULL) || (preq_info->connInfo == NULL) ||
(preq_info->connInfo->safety.safety_seg == FALSE))
{
proto_tree_add_item(tree, hf_cip_cm_app_reply_data, tvb, offset+26, app_rep_size, ENC_NA );
}
else if (preq_info->connInfo->safety.format == CIP_SAFETY_BASE_FORMAT)
{
ti = proto_tree_add_text( tree, tvb, offset+28, 10, "Safety Application Reply Data");
safety_tree = proto_item_add_subtree( ti, ett_cip_cm_safety );
proto_tree_add_item( safety_tree, hf_cip_cm_consumer_number, tvb, offset+26, 2, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_text( safety_tree, tvb, offset+28, 8, "PID/CID");
pid_tree = proto_item_add_subtree( ti, ett_cip_cm_pid );
proto_tree_add_item( pid_tree, hf_cip_cm_targ_vendor_id, tvb, offset+28, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( pid_tree, hf_cip_cm_targ_dev_serial_num, tvb, offset+30, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item( pid_tree, hf_cip_cm_targ_conn_serial_num, tvb, offset+34, 2, ENC_LITTLE_ENDIAN);
if (app_rep_size > 10)
proto_tree_add_item(tree, hf_cip_cm_app_reply_data, tvb, offset+36, app_rep_size-10, ENC_NA );
}
else if (preq_info->connInfo->safety.format == CIP_SAFETY_EXTENDED_FORMAT)
{
ti = proto_tree_add_text( tree, tvb, offset+28, 14, "Safety Application Reply Data");
safety_tree = proto_item_add_subtree( ti, ett_cip_cm_safety );
proto_tree_add_item( safety_tree, hf_cip_cm_consumer_number, tvb, offset+26, 2, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_text( safety_tree, tvb, offset+28, 12, "PID/CID");
pid_tree = proto_item_add_subtree( ti, ett_cip_cm_pid );
proto_tree_add_item( pid_tree, hf_cip_cm_targ_vendor_id, tvb, offset+28, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( pid_tree, hf_cip_cm_targ_dev_serial_num, tvb, offset+30, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item( pid_tree, hf_cip_cm_targ_conn_serial_num, tvb, offset+34, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( pid_tree, hf_cip_cm_initial_timestamp, tvb, offset+36, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( pid_tree, hf_cip_cm_initial_rollover, tvb, offset+38, 2, ENC_LITTLE_ENDIAN);
if (app_rep_size > 14)
proto_tree_add_item(tree, hf_cip_cm_app_reply_data, tvb, offset+40, app_rep_size-14, ENC_NA );
}
}
if (pinfo->fd->flags.visited)
return;
if ((preq_info != NULL) && (preq_info->connInfo != NULL))
{
if ((preq_info->connInfo->ConnSerialNumber == ConnSerialNumber) &&
(preq_info->connInfo->VendorID == VendorID) &&
(preq_info->connInfo->DeviceSerialNumber == DeviceSerialNumber))
{
preq_info->connInfo->O2T.connID = O2TConnID;
preq_info->connInfo->T2O.connID = T2OConnID;
}
}
}
static void
dissect_cip_cm_data( proto_tree *item_tree, tvbuff_t *tvb, int offset, int item_length, packet_info *pinfo )
{
proto_item *pi, *rrsc_item, *status_item, *add_status_item, *temp_item;
proto_tree *rrsc_tree, *cmd_data_tree, *status_tree, *add_status_tree, *temp_tree;
int req_path_size, conn_path_size, temp_data;
unsigned char service, gen_status, add_stat_size;
unsigned short add_status;
unsigned char app_rep_size, route_path_size;
int i, msg_req_siz;
cip_req_info_t *preq_info;
cip_req_info_t *pembedded_req_info;
guint16 ConnSerialNumber, VendorID;
guint32 DeviceSerialNumber;
service = tvb_get_guint8( tvb, offset );
preq_info = (cip_req_info_t*)p_get_proto_data( pinfo->fd, proto_cip, 0 );
if ( preq_info != NULL && ( service & 0x80 )
&& preq_info->bService == SC_CM_UNCON_SEND
)
{
gen_status = tvb_get_guint8( tvb, offset+2 );
add_stat_size = tvb_get_guint8( tvb, offset+3 ) * 2;
if ( add_stat_size == 2 )
add_status = tvb_get_letohs( tvb, offset + 4 );
else
add_status = 0;
if( gen_status == 0
|| ( ( service & 0x7F ) != SC_CM_UNCON_SEND )
|| !( ( gen_status == CI_GRC_FAILURE && (add_status == CM_ES_UNCONNECTED_REQUEST_TIMED_OUT ||
add_status == CM_ES_PORT_NOT_AVAILABLE ||
add_status == CM_ES_LINK_ADDRESS_NOT_VALID ||
add_status == CM_ES_INVALID_SEGMENT_IN_CONN_PATH) )
|| gen_status == CI_GRC_NO_RESOURCE
|| gen_status == CI_GRC_BAD_PATH
)
)
{
pembedded_req_info = (cip_req_info_t*)preq_info->pData;
if ( pembedded_req_info )
{
tvbuff_t *next_tvb;
void *p_save_proto_data;
p_save_proto_data = p_get_proto_data( pinfo->fd, proto_cip, 0 );
p_remove_proto_data(pinfo->fd, proto_cip, 0);
p_add_proto_data(pinfo->fd, proto_cip, 0, pembedded_req_info );
proto_tree_add_text( item_tree, NULL, 0, 0, "(Service: Unconnected Send (Response))" );
next_tvb = tvb_new_subset(tvb, offset, item_length, item_length);
if ( pembedded_req_info && pembedded_req_info->dissector )
call_dissector(pembedded_req_info->dissector, next_tvb, pinfo, item_tree );
else
call_dissector( cip_class_generic_handle, next_tvb, pinfo, item_tree );
p_remove_proto_data(pinfo->fd, proto_cip, 0);
p_add_proto_data(pinfo->fd, proto_cip, 0, p_save_proto_data);
return;
}
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CIP CM");
rrsc_item = proto_tree_add_text( item_tree, tvb, offset, 1, "Service: " );
rrsc_tree = proto_item_add_subtree( rrsc_item, ett_cm_rrsc );
proto_tree_add_item( rrsc_tree, hf_cip_reqrsp, tvb, offset, 1, ENC_LITTLE_ENDIAN );
proto_item_append_text( rrsc_item, "%s (%s)",
val_to_str( ( service & 0x7F ),
cip_sc_vals_cm , "Unknown Service (0x%02x)"),
val_to_str_const( ( service & 0x80 )>>7,
cip_sc_rr, "") );
proto_tree_add_item(rrsc_tree, hf_cip_cm_sc, tvb, offset, 1, ENC_LITTLE_ENDIAN );
if( service & 0x80 )
{
gen_status = tvb_get_guint8( tvb, offset+2 );
add_stat_size = tvb_get_guint8( tvb, offset+3 ) * 2;
if (gen_status == CI_GRC_FAILURE)
{
status_item = proto_tree_add_text(item_tree, tvb, offset+2, 1, "Status: " );
status_tree = proto_item_add_subtree( status_item, ett_status_item );
proto_tree_add_item(status_tree, hf_cip_cm_genstat, tvb, offset+2, 1, ENC_LITTLE_ENDIAN );
proto_item_append_text( status_item, "%s", val_to_str_ext( gen_status,
&cip_gs_vals_ext , "Unknown Response (%x)") );
proto_tree_add_uint_format_value(status_tree, hf_cip_cm_addstat_size,
tvb, offset+3, 1, add_stat_size/2, "%d (words)", add_stat_size/2);
if( add_stat_size )
{
add_status = tvb_get_letohs( tvb, offset + 4 );
proto_tree_add_item(status_tree, hf_cip_cm_ext_status, tvb, offset+4, 2, ENC_LITTLE_ENDIAN );
proto_item_append_text(status_item, ", Extended: %s", val_to_str_ext(add_status, &cip_cm_ext_st_vals_ext, "Reserved (0x%04x)"));
switch(add_status)
{
case CM_ES_RPI_NOT_ACCEPTABLE:
if (add_stat_size < 3)
{
expert_add_info(pinfo, status_item, &ei_mal_rpi_no_data);
}
else
{
proto_tree_add_item(status_tree, hf_cip_cm_ext112_ot_rpi_type, tvb, offset+6, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(status_tree, hf_cip_cm_ext112_to_rpi_type, tvb, offset+7, 1, ENC_LITTLE_ENDIAN );
temp_data = tvb_get_letohl( tvb, offset+8);
proto_tree_add_uint_format_value(status_tree, hf_cip_cm_ext112_ot_rpi, tvb, offset+8, 4, temp_data, "%dms (0x%08X)", temp_data / 1000, temp_data);
temp_data = tvb_get_letohl( tvb, offset+12);
proto_tree_add_uint_format_value(status_tree, hf_cip_cm_ext112_to_rpi, tvb, offset+12, 4, temp_data, "%dms (0x%08X)", temp_data / 1000, temp_data);
}
break;
case CM_ES_INVALID_CONFIGURATION_SIZE:
if (add_stat_size < 1)
{
expert_add_info(pinfo, status_item, &ei_mal_inv_config_size);
}
else
{
proto_tree_add_item(status_tree, hf_cip_cm_ext126_size, tvb, offset+6, 2, ENC_LITTLE_ENDIAN );
}
break;
case CM_ES_INVALID_OT_SIZE:
if (add_stat_size < 1)
{
expert_add_info(pinfo, status_item, &ei_mal_ot_size);
}
else
{
proto_tree_add_item(status_tree, hf_cip_cm_ext127_size, tvb, offset+6, 2, ENC_LITTLE_ENDIAN );
}
break;
case CM_ES_INVALID_TO_SIZE:
if (add_stat_size < 1)
{
expert_add_info(pinfo, status_item, &ei_mal_to_size);
}
else
{
proto_tree_add_item(status_tree, hf_cip_cm_ext128_size, tvb, offset+6, 2, ENC_LITTLE_ENDIAN );
}
break;
default:
if (add_stat_size > 1)
{
add_status_item = proto_tree_add_text( status_tree, tvb, offset+4, add_stat_size, "Additional Status" );
add_status_tree = proto_item_add_subtree( add_status_item, ett_cm_add_status_item );
for( i=0; i < add_stat_size-2; i += 2 )
proto_tree_add_item(add_status_tree, hf_cip_cm_add_status, tvb, offset+4+i, 2, ENC_LITTLE_ENDIAN );
}
}
}
}
if( ( item_length-4-add_stat_size ) != 0 )
{
pi = proto_tree_add_text( item_tree, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, "Command Specific Data" );
cmd_data_tree = proto_item_add_subtree( pi, ett_cm_cmd_data );
if( gen_status == CI_GRC_SUCCESS || gen_status == CI_GRC_SERVICE_ERROR )
{
switch (service & 0x7F)
{
case SC_CM_FWD_OPEN:
case SC_CM_LARGE_FWD_OPEN:
dissect_cip_cm_fwd_open_rsp_success(preq_info, cmd_data_tree, tvb, offset+4+add_stat_size, pinfo);
break;
case SC_CM_FWD_CLOSE:
{
ConnSerialNumber = tvb_get_letohs( tvb, offset+4+add_stat_size );
proto_tree_add_item( cmd_data_tree, hf_cip_cm_conn_serial_num, tvb, offset+4+add_stat_size, 2, ENC_LITTLE_ENDIAN);
VendorID = tvb_get_letohs( tvb, offset+4+add_stat_size+2 );
proto_tree_add_item( cmd_data_tree, hf_cip_cm_vendor, tvb, offset+4+add_stat_size+2, 2, ENC_LITTLE_ENDIAN);
DeviceSerialNumber = tvb_get_letohl( tvb, offset+4+add_stat_size+4 );
proto_tree_add_item( cmd_data_tree, hf_cip_cm_orig_serial_num, tvb, offset+4+add_stat_size+4, 4, ENC_LITTLE_ENDIAN);
app_rep_size = tvb_get_guint8( tvb, offset+4+add_stat_size+8 ) * 2;
proto_tree_add_uint_format_value(cmd_data_tree, hf_cip_cm_app_reply_size, tvb, offset+4+add_stat_size+8, 1, app_rep_size / 2, "%d (words)", app_rep_size / 2);
proto_tree_add_item(cmd_data_tree, hf_cip_reserved8, tvb, offset+4+add_stat_size+9, 1, ENC_LITTLE_ENDIAN);
if (app_rep_size > 0)
proto_tree_add_item(cmd_data_tree, hf_cip_cm_app_reply_data, tvb, offset+4+add_stat_size+10, app_rep_size, ENC_NA);
enip_close_cip_connection( pinfo, ConnSerialNumber, VendorID, DeviceSerialNumber );
}
break;
case SC_CM_UNCON_SEND:
{
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
}
break;
case SC_CM_GET_CONN_OWNER:
{
proto_tree_add_item( cmd_data_tree, hf_cip_cm_gco_conn, tvb, offset+4+add_stat_size, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_data_tree, hf_cip_cm_gco_coo_conn, tvb, offset+4+add_stat_size+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_data_tree, hf_cip_cm_gco_roo_conn, tvb, offset+4+add_stat_size+2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_data_tree, hf_cip_cm_gco_last_action, tvb, offset+4+add_stat_size+3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_data_tree, hf_cip_cm_conn_serial_num, tvb, offset+4+add_stat_size+4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_data_tree, hf_cip_cm_vendor, tvb, offset+4+add_stat_size+6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_data_tree, hf_cip_cm_orig_serial_num, tvb, offset+4+add_stat_size+8, 4, ENC_LITTLE_ENDIAN);
}
break;
default:
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
break;
}
}
else
{
switch (service & 0x7F)
{
case SC_CM_FWD_OPEN:
case SC_CM_LARGE_FWD_OPEN:
case SC_CM_FWD_CLOSE:
ConnSerialNumber = tvb_get_letohs( tvb, offset+4+add_stat_size );
proto_tree_add_item( cmd_data_tree, hf_cip_cm_conn_serial_num, tvb, offset+4+add_stat_size, 2, ENC_LITTLE_ENDIAN);
VendorID = tvb_get_letohs( tvb, offset+4+add_stat_size+2 );
proto_tree_add_item( cmd_data_tree, hf_cip_cm_vendor, tvb, offset+4+add_stat_size+2, 2, ENC_LITTLE_ENDIAN);
DeviceSerialNumber = tvb_get_letohl( tvb, offset+4+add_stat_size+4 );
proto_tree_add_item( cmd_data_tree, hf_cip_cm_orig_serial_num, tvb, offset+4+add_stat_size+4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_cm_remain_path_size, tvb, offset+4+add_stat_size+8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_reserved8, tvb, offset+4+add_stat_size+9, 1, ENC_LITTLE_ENDIAN);
enip_close_cip_connection(pinfo, ConnSerialNumber, VendorID, DeviceSerialNumber);
if (preq_info != NULL)
{
preq_info->connInfo = NULL;
}
break;
case SC_CM_UNCON_SEND:
proto_tree_add_item(cmd_data_tree, hf_cip_cm_remain_path_size, tvb, offset+4+add_stat_size, 1, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
break;
}
}
}
}
else
{
add_cip_service_to_info_column(pinfo, service, cip_sc_vals_cm);
req_path_size = tvb_get_guint8( tvb, offset+1 )*2;
if( (item_length-req_path_size-2) != 0 )
{
pi = proto_tree_add_text( item_tree, tvb, offset+2+req_path_size, item_length-req_path_size-2, "Command Specific Data" );
cmd_data_tree = proto_item_add_subtree( pi, ett_cm_cmd_data );
switch (service)
{
case SC_CM_FWD_OPEN:
dissect_cip_cm_fwd_open_req(preq_info, cmd_data_tree, tvb, offset+2+req_path_size, FALSE, pinfo);
break;
case SC_CM_LARGE_FWD_OPEN:
dissect_cip_cm_fwd_open_req(preq_info, cmd_data_tree, tvb, offset+2+req_path_size, TRUE, pinfo);
break;
case SC_CM_FWD_CLOSE:
dissect_cip_cm_timeout( cmd_data_tree, tvb, offset+2+req_path_size);
proto_tree_add_item( cmd_data_tree, hf_cip_cm_conn_serial_num, tvb, offset+2+req_path_size+2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_data_tree, hf_cip_cm_vendor, tvb, offset+2+req_path_size+4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item( cmd_data_tree, hf_cip_cm_orig_serial_num, tvb, offset+2+req_path_size+6, 4, ENC_LITTLE_ENDIAN);
conn_path_size = tvb_get_guint8( tvb, offset+2+req_path_size+10 )*2;
proto_tree_add_uint_format_value(cmd_data_tree, hf_cip_cm_conn_path_size, tvb, offset+2+req_path_size+10, 1, conn_path_size/2, "%d (words)", conn_path_size/2);
proto_tree_add_item(cmd_data_tree, hf_cip_reserved8, tvb, offset+2+req_path_size+11, 1, ENC_LITTLE_ENDIAN);
pi = proto_tree_add_text(cmd_data_tree, tvb, offset+2+req_path_size+12, conn_path_size, "Connection Path: ");
dissect_epath( tvb, pinfo, pi, offset+2+req_path_size+12, conn_path_size, FALSE, FALSE, NULL, NULL );
break;
case SC_CM_UNCON_SEND:
{
tvbuff_t *next_tvb;
dissect_cip_cm_timeout( cmd_data_tree, tvb, offset+2+req_path_size);
msg_req_siz = tvb_get_letohs( tvb, offset+2+req_path_size+2 );
proto_tree_add_item(cmd_data_tree, hf_cip_cm_msg_req_size, tvb, offset+2+req_path_size+2, 2, ENC_LITTLE_ENDIAN);
temp_item = proto_tree_add_text( cmd_data_tree, tvb, offset+2+req_path_size+4, msg_req_siz, "Message Request" );
temp_tree = proto_item_add_subtree(temp_item, ett_cm_mes_req );
col_append_str( pinfo->cinfo, COL_INFO, ": ");
next_tvb = tvb_new_subset(tvb, offset+2+req_path_size+4, msg_req_siz, msg_req_siz);
preq_info = (cip_req_info_t *)p_get_proto_data( pinfo->fd, proto_cip, 0 );
pembedded_req_info = NULL;
if ( preq_info )
{
if ( preq_info->pData == NULL )
{
pembedded_req_info = wmem_new0(wmem_file_scope(), cip_req_info_t);
preq_info->pData = pembedded_req_info;
}
else
{
pembedded_req_info = (cip_req_info_t*)preq_info->pData;
}
pembedded_req_info->isUnconnectedSend = TRUE;
}
dissect_cip_data( temp_tree, next_tvb, 0, pinfo, pembedded_req_info );
if( msg_req_siz % 2 )
{
proto_tree_add_item(cmd_data_tree, hf_cip_pad8, tvb, offset+2+req_path_size+4+msg_req_siz, 1, ENC_LITTLE_ENDIAN);
msg_req_siz++;
}
route_path_size = tvb_get_guint8( tvb, offset+2+req_path_size+4+msg_req_siz )*2;
proto_tree_add_uint_format_value(cmd_data_tree, hf_cip_cm_route_path_size, tvb, offset+2+req_path_size+4+msg_req_siz, 1, route_path_size / 2, "%d (words)", route_path_size / 2);
proto_tree_add_item(cmd_data_tree, hf_cip_reserved8, tvb, offset+2+req_path_size+5+msg_req_siz, 1, ENC_LITTLE_ENDIAN);
temp_item = proto_tree_add_text(cmd_data_tree, tvb, offset+2+req_path_size+6+msg_req_siz, route_path_size, "Route Path: ");
dissect_epath( tvb, pinfo, temp_item, offset+2+req_path_size+6+msg_req_siz, route_path_size, FALSE, FALSE, NULL, NULL );
}
break;
case SC_CM_GET_CONN_OWNER:
proto_tree_add_item(cmd_data_tree, hf_cip_reserved8, tvb, offset+2+req_path_size, 1, ENC_LITTLE_ENDIAN);
conn_path_size = tvb_get_guint8( tvb, offset+2+req_path_size+1 )*2;
proto_tree_add_uint_format_value(cmd_data_tree, hf_cip_cm_conn_path_size, tvb, offset+2+req_path_size+1, 1, conn_path_size/2, "%d (words)", conn_path_size/2);
pi = proto_tree_add_text(cmd_data_tree, tvb, offset+2+req_path_size+2, conn_path_size, "Connection Path: ");
dissect_epath( tvb, pinfo, pi, offset+2+req_path_size+2, conn_path_size, FALSE, FALSE, NULL, NULL );
break;
default:
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+2+req_path_size, item_length-req_path_size-2, ENC_NA);
}
}
}
}
static int
dissect_cip_class_cm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *class_tree;
ti = proto_tree_add_item(tree, proto_cip_class_cm, tvb, 0, -1, ENC_NA);
class_tree = proto_item_add_subtree( ti, ett_cip_class_cm );
dissect_cip_cm_data( class_tree, tvb, 0, tvb_length(tvb), pinfo );
return tvb_length(tvb);
}
static void
dissect_cip_mb_data( proto_tree *item_tree, tvbuff_t *tvb, int offset, int item_length, packet_info *pinfo )
{
proto_item *pi, *rrsc_item;
proto_tree *rrsc_tree, *cmd_data_tree;
tvbuff_t *next_tvb;
int req_path_size;
guint8 gen_status, add_stat_size, service;
modbus_request_info_t* request_info;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CIP MB");
service = tvb_get_guint8( tvb, offset );
rrsc_item = proto_tree_add_text( item_tree, tvb, offset, 1, "Service: " );
rrsc_tree = proto_item_add_subtree( rrsc_item, ett_mb_rrsc );
proto_tree_add_item( rrsc_tree, hf_cip_reqrsp, tvb, offset, 1, ENC_LITTLE_ENDIAN );
proto_item_append_text( rrsc_item, "%s (%s)",
val_to_str( ( service & 0x7F ),
cip_sc_vals_mb , "Unknown Service (0x%02x)"),
val_to_str_const( ( service & 0x80 )>>7,
cip_sc_rr, "") );
proto_tree_add_item(rrsc_tree, hf_cip_mb_sc, tvb, offset, 1, ENC_LITTLE_ENDIAN );
if( service & 0x80 )
{
gen_status = tvb_get_guint8( tvb, offset+2 );
add_stat_size = tvb_get_guint8( tvb, offset+3 ) * 2;
if( ( item_length-4-add_stat_size ) != 0 )
{
pi = proto_tree_add_text( item_tree, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, "Command Specific Data" );
cmd_data_tree = proto_item_add_subtree( pi, ett_mb_cmd_data );
if( gen_status == CI_GRC_SUCCESS || gen_status == CI_GRC_SERVICE_ERROR )
{
switch (service & 0x7F)
{
case SC_MB_READ_DISCRETE_INPUTS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_discrete_inputs_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
break;
case SC_MB_READ_COILS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_coils_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
break;
case SC_MB_READ_INPUT_REGISTERS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_input_register_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
break;
case SC_MB_READ_HOLDING_REGISTERS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_holding_register_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
break;
case SC_MB_WRITE_COILS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_coils_start_addr, tvb, offset+4+add_stat_size, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_coils_outputs_forced, tvb, offset+4+add_stat_size+2, 2, ENC_LITTLE_ENDIAN);
break;
case SC_MB_WRITE_HOLDING_REGISTERS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_registers_start_addr, tvb, offset+4+add_stat_size, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_registers_outputs_forced, tvb, offset+4+add_stat_size+2, 2, ENC_LITTLE_ENDIAN);
break;
case SC_MB_PASSTHROUGH:
if( tvb_length_remaining(tvb, offset) > 0 )
{
next_tvb = tvb_new_subset( tvb, offset+4+add_stat_size, item_length-4-add_stat_size, item_length-4-add_stat_size);
request_info = wmem_new(wmem_packet_scope(), modbus_request_info_t);
request_info->packet_type = RESPONSE_PACKET;
request_info->register_addr_type = MBTCP_PREF_REGISTER_ADDR_RAW;
request_info->register_format = MBTCP_PREF_REGISTER_FORMAT_UINT16;
p_add_proto_data(pinfo->fd, proto_modbus, 0, request_info);
call_dissector(modbus_handle, next_tvb, pinfo, cmd_data_tree);
p_remove_proto_data(pinfo->fd, proto_modbus, 0);
}
break;
default:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
}
}
else
{
proto_tree_add_item(cmd_data_tree, hf_cip_mb_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
}
}
}
else
{
add_cip_service_to_info_column(pinfo, service, cip_sc_vals_mb);
req_path_size = tvb_get_guint8( tvb, offset+1 )*2;
if( (item_length-req_path_size-2) != 0 )
{
pi = proto_tree_add_text( item_tree, tvb, offset+2+req_path_size, item_length-req_path_size-2, "Command Specific Data" );
cmd_data_tree = proto_item_add_subtree( pi, ett_mb_cmd_data );
switch (service)
{
case SC_MB_READ_DISCRETE_INPUTS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_discrete_inputs_start_addr, tvb, offset+2+req_path_size, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_discrete_inputs_num_inputs, tvb, offset+2+req_path_size+2, 2, ENC_LITTLE_ENDIAN);
break;
case SC_MB_READ_COILS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_coils_start_addr, tvb, offset+2+req_path_size, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_coils_num_coils, tvb, offset+2+req_path_size+2, 2, ENC_LITTLE_ENDIAN);
break;
case SC_MB_READ_INPUT_REGISTERS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_input_register_start_addr, tvb, offset+2+req_path_size, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_input_register_num_registers, tvb, offset+2+req_path_size+2, 2, ENC_LITTLE_ENDIAN);
break;
case SC_MB_READ_HOLDING_REGISTERS:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_holding_register_start_addr, tvb, offset+2+req_path_size, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_mb_read_holding_register_num_registers, tvb, offset+2+req_path_size+2, 2, ENC_LITTLE_ENDIAN);
break;
case SC_MB_WRITE_COILS:
{
guint16 NumCoils;
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_coils_start_addr, tvb, offset+2+req_path_size, 2, ENC_LITTLE_ENDIAN);
NumCoils = tvb_get_letohs( tvb, offset+2+req_path_size+2 );
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_coils_num_coils, tvb, offset+2+req_path_size+2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_coils_data, tvb, offset+2+req_path_size+4, (NumCoils+7)/8, ENC_NA);
}
break;
case SC_MB_WRITE_HOLDING_REGISTERS:
{
guint16 NumRegisters;
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_registers_start_addr, tvb, offset+2+req_path_size, 2, ENC_LITTLE_ENDIAN);
NumRegisters = tvb_get_letohs( tvb, offset+2+req_path_size+2 );
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_registers_num_registers, tvb, offset+2+req_path_size+2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_mb_write_registers_data, tvb, offset+2+req_path_size+4, NumRegisters*2, ENC_NA);
}
break;
case SC_MB_PASSTHROUGH:
if( tvb_length_remaining(tvb, offset) > 0 )
{
next_tvb = tvb_new_subset( tvb, offset+2+req_path_size, item_length-req_path_size-2, item_length-req_path_size-2);
request_info = wmem_new(wmem_packet_scope(), modbus_request_info_t);
request_info->packet_type = QUERY_PACKET;
request_info->register_addr_type = MBTCP_PREF_REGISTER_ADDR_RAW;
request_info->register_format = MBTCP_PREF_REGISTER_FORMAT_UINT16;
p_add_proto_data(pinfo->fd, proto_modbus, 0, request_info);
call_dissector(modbus_handle, next_tvb, pinfo, cmd_data_tree);
p_remove_proto_data(pinfo->fd, proto_modbus, 0);
}
break;
default:
proto_tree_add_item(cmd_data_tree, hf_cip_mb_data, tvb, offset+2+req_path_size, item_length-req_path_size-2, ENC_NA);
}
}
}
}
static int
dissect_cip_class_mb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *class_tree;
ti = proto_tree_add_item(tree, proto_cip_class_mb, tvb, 0, -1, ENC_NA);
class_tree = proto_item_add_subtree( ti, ett_cip_class_mb );
dissect_cip_mb_data( class_tree, tvb, 0, tvb_length(tvb), pinfo );
return tvb_length(tvb);
}
static int
dissect_cip_cco_all_attribute_common( proto_tree *cmd_tree, tvbuff_t *tvb, int offset, int item_length, packet_info *pinfo)
{
proto_item *pi, *tdii, *ncpi, *iomapi, *confgi;
proto_tree *tdi_tree, *iomap_tree;
proto_tree *ncp_tree, *confg_tree;
int conn_path_size, variable_data_size = 0, config_data_size;
int connection_name_size, iomap_size, ot_rtf, to_rtf;
int temp_data;
char* str_connection_name;
temp_data = tvb_get_letohs( tvb, offset);
ot_rtf = (temp_data >> 1) & 7;
to_rtf = (temp_data >> 4) & 7;
confgi = proto_tree_add_item(cmd_tree, hf_cip_cco_con_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN );
confg_tree = proto_item_add_subtree(confgi, ett_cco_con_flag);
proto_tree_add_item(confg_tree, hf_cip_cco_con_type, tvb, offset, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(confg_tree, hf_cip_cco_ot_rtf, tvb, offset, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(confg_tree, hf_cip_cco_to_rtf, tvb, offset, 2, ENC_LITTLE_ENDIAN );
tdii = proto_tree_add_text( cmd_tree, tvb, offset+2, 10, "Target Device ID");
tdi_tree = proto_item_add_subtree(tdii, ett_cco_tdi);
dissect_deviceid(tvb, offset+2, tdi_tree,
hf_cip_cco_tdi_vendor, hf_cip_cco_tdi_devtype, hf_cip_cco_tdi_prodcode,
hf_cip_cco_tdi_compatibility, hf_cip_cco_tdi_comp_bit, hf_cip_cco_tdi_majorrev, hf_cip_cco_tdi_minorrev);
proto_tree_add_item(cmd_tree, hf_cip_cco_cs_data_index, tvb, offset+10, 4, ENC_LITTLE_ENDIAN );
ncpi = proto_tree_add_text( cmd_tree, tvb, offset+14, 14, "Net Connection Parameters");
ncp_tree = proto_item_add_subtree(ncpi, ett_cco_ncp);
proto_tree_add_item(ncp_tree, hf_cip_cco_timeout_multiplier, tvb, offset+14, 1, ENC_LITTLE_ENDIAN );
dissect_transport_type_trigger(tvb, offset+15, ncp_tree, hf_cip_cco_transport_type_trigger,
hf_cip_cco_fwo_dir, hf_cip_cco_fwo_trigger, hf_cip_cco_fwo_class, ett_cco_ttt);
temp_data = tvb_get_letohl( tvb, offset+16);
proto_tree_add_uint_format_value(ncp_tree, hf_cip_cco_ot_rpi, tvb, offset+16, 4, temp_data, "%dms (0x%08X)", temp_data / 1000, temp_data);
dissect_net_param16(tvb, offset+20, ncp_tree,
hf_cip_cco_ot_net_param16, hf_cip_cco_fwo_own, hf_cip_cco_fwo_typ,
hf_cip_cco_fwo_prio, hf_cip_cco_fwo_fixed_var, hf_cip_cco_fwo_con_size, ett_cco_ncp);
temp_data = tvb_get_letohl( tvb, offset+22);
proto_tree_add_uint_format_value(ncp_tree, hf_cip_cco_to_rpi, tvb, offset+16, 4, temp_data, "%dms (0x%08X)", temp_data / 1000, temp_data);
dissect_net_param16(tvb, offset+26, ncp_tree,
hf_cip_cco_to_net_param16, hf_cip_cco_fwo_own, hf_cip_cco_fwo_typ,
hf_cip_cco_fwo_prio, hf_cip_cco_fwo_fixed_var, hf_cip_cco_fwo_con_size, ett_cco_ncp);
conn_path_size = tvb_get_guint8( tvb, offset+28 )*2;
proto_tree_add_uint_format_value(cmd_tree, hf_cip_cco_conn_path_size, tvb, offset+28, 1, conn_path_size/2, "%d (words)", conn_path_size/2);
proto_tree_add_item(cmd_tree, hf_cip_reserved8, tvb, offset+29, 1, ENC_LITTLE_ENDIAN );
pi = proto_tree_add_text(cmd_tree, tvb, offset+30, conn_path_size, "Connection Path: ");
dissect_epath( tvb, pinfo, pi, offset+30, conn_path_size, FALSE, FALSE, NULL, NULL );
variable_data_size += (conn_path_size+30);
config_data_size = tvb_get_letohs( tvb, offset+variable_data_size);
proto_tree_add_item(cmd_tree, hf_cip_cco_proxy_config_size, tvb, offset+variable_data_size, 2, ENC_LITTLE_ENDIAN );
if (config_data_size > 0)
proto_tree_add_item(cmd_tree, hf_cip_cco_proxy_config_data, tvb, offset+variable_data_size+2, config_data_size, ENC_NA);
variable_data_size += (config_data_size+2);
config_data_size = tvb_get_letohs( tvb, offset+variable_data_size);
proto_tree_add_item(cmd_tree, hf_cip_cco_target_config_size, tvb, offset+variable_data_size, 2, ENC_LITTLE_ENDIAN );
if (config_data_size > 0)
proto_tree_add_item(cmd_tree, hf_cip_cco_target_config_data, tvb, offset+variable_data_size+2, config_data_size, ENC_NA);
variable_data_size += (config_data_size+2);
connection_name_size = tvb_get_guint8( tvb, offset+variable_data_size);
str_connection_name = tvb_get_string(wmem_packet_scope(), tvb, offset+variable_data_size+2, connection_name_size);
proto_tree_add_text(cmd_tree, tvb, offset+variable_data_size, connection_name_size+2, "Connection Name: %s", str_connection_name);
variable_data_size += ((connection_name_size*2)+2);
iomap_size = tvb_get_letohs( tvb, offset+variable_data_size+2);
iomapi = proto_tree_add_text( cmd_tree, tvb, offset+variable_data_size, iomap_size+2, "I/O Mapping");
iomap_tree = proto_item_add_subtree(iomapi, ett_cco_iomap);
proto_tree_add_item(iomap_tree, hf_cip_cco_iomap_format_number, tvb, offset+variable_data_size, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_uint_format_value(iomap_tree, hf_cip_cco_iomap_size, tvb, offset+variable_data_size+2, 2, iomap_size, "%d (bytes)", iomap_size);
if (iomap_size > 0)
proto_tree_add_item(iomap_tree, hf_cip_cco_iomap_attribute, tvb, offset+variable_data_size+4, iomap_size, ENC_NA);
variable_data_size += (iomap_size+4);
tdii = proto_tree_add_text( cmd_tree, tvb, offset+variable_data_size, 10, "Proxy Device ID");
tdi_tree = proto_item_add_subtree(tdii, ett_cco_pdi);
dissect_deviceid(tvb, offset+variable_data_size, tdi_tree,
hf_cip_cco_pdi_vendor, hf_cip_cco_pdi_devtype, hf_cip_cco_pdi_prodcode,
hf_cip_cco_pdi_compatibility, hf_cip_cco_pdi_comp_bit, hf_cip_cco_pdi_majorrev, hf_cip_cco_pdi_minorrev);
variable_data_size += 8;
if ((offset+variable_data_size < item_length) &&
((ot_rtf == 5) || (to_rtf == 5)))
{
proto_tree_add_item(cmd_tree, hf_cip_cco_safety, tvb, offset+variable_data_size, 55, ENC_NA);
variable_data_size += 55;
}
if (offset+variable_data_size < item_length)
{
proto_tree_add_item(cmd_tree, hf_cip_cco_connection_disable, tvb, offset+variable_data_size, 1, ENC_LITTLE_ENDIAN );
variable_data_size++;
}
if (offset+variable_data_size < item_length)
{
proto_tree_add_item(cmd_tree, hf_cip_cco_net_conn_param_attr, tvb, offset+variable_data_size, 1, ENC_LITTLE_ENDIAN );
variable_data_size++;
}
if (offset+variable_data_size < item_length)
{
ncpi = proto_tree_add_text( cmd_tree, tvb, offset+variable_data_size, 18, "Large Net Connection Parameters");
ncp_tree = proto_item_add_subtree(ncpi, ett_cco_ncp);
proto_tree_add_item(ncp_tree, hf_cip_cco_timeout_multiplier, tvb, offset+variable_data_size, 1, ENC_LITTLE_ENDIAN );
dissect_transport_type_trigger(tvb, offset+variable_data_size+1, ncp_tree, hf_cip_cco_transport_type_trigger,
hf_cip_cco_fwo_dir, hf_cip_cco_fwo_trigger, hf_cip_cco_fwo_class, ett_cco_ttt);
temp_data = tvb_get_letohl( tvb, offset+variable_data_size+2);
proto_tree_add_uint_format_value(ncp_tree, hf_cip_cco_ot_rpi, tvb, offset+variable_data_size+2, 4, temp_data, "%dms (0x%08X)", temp_data / 1000, temp_data);
dissect_net_param32(tvb, offset+variable_data_size+6, ncp_tree,
hf_cip_cco_ot_net_param32, hf_cip_cco_lfwo_own, hf_cip_cco_lfwo_typ,
hf_cip_cco_lfwo_prio, hf_cip_cco_lfwo_fixed_var, hf_cip_cco_lfwo_con_size, ett_cco_ncp);
temp_data = tvb_get_letohl( tvb, offset+variable_data_size+10);
proto_tree_add_uint_format_value(ncp_tree, hf_cip_cco_to_rpi, tvb, offset+variable_data_size+2, 4, temp_data, "%dms (0x%08X)", temp_data / 1000, temp_data);
dissect_net_param32(tvb, offset+variable_data_size+14, ncp_tree,
hf_cip_cco_to_net_param32, hf_cip_cco_lfwo_own, hf_cip_cco_lfwo_typ,
hf_cip_cco_lfwo_prio, hf_cip_cco_lfwo_fixed_var, hf_cip_cco_lfwo_con_size, ett_cco_ncp);
variable_data_size += 18;
}
return variable_data_size;
}
static void
dissect_cip_cco_data( proto_tree *item_tree, tvbuff_t *tvb, int offset, int item_length, packet_info *pinfo )
{
proto_item *pi, *rrsc_item, *con_sti;
proto_tree *rrsc_tree, *cmd_data_tree, *con_st_tree;
int req_path_size;
int temp_data;
guint8 service, gen_status, add_stat_size;
cip_req_info_t* preq_info;
cip_simple_request_info_t req_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CIP CCO");
service = tvb_get_guint8( tvb, offset );
rrsc_item = proto_tree_add_text( item_tree, tvb, offset, 1, "Service: " );
rrsc_tree = proto_item_add_subtree( rrsc_item, ett_cco_rrsc );
proto_tree_add_item( rrsc_tree, hf_cip_reqrsp, tvb, offset, 1, ENC_LITTLE_ENDIAN );
proto_item_append_text( rrsc_item, "%s (%s)",
val_to_str( ( service & 0x7F ),
cip_sc_vals_cco , "Unknown Service (0x%02x)"),
val_to_str_const( ( service & 0x80 )>>7,
cip_sc_rr, "") );
proto_tree_add_item(rrsc_tree, hf_cip_cco_sc, tvb, offset, 1, ENC_LITTLE_ENDIAN );
preq_info = (cip_req_info_t*)p_get_proto_data(pinfo->fd, proto_cip, 0);
if ((preq_info != NULL) &&
(preq_info->ciaData != NULL))
{
memcpy(&req_data, preq_info->ciaData, sizeof(cip_simple_request_info_t));
}
else
{
req_data.iClass = (guint32)-1;
req_data.iInstance = (guint32)-1;
req_data.iAttribute = (guint32)-1;
req_data.iMember = (guint32)-1;
}
if(service & 0x80 )
{
gen_status = tvb_get_guint8( tvb, offset+2 );
add_stat_size = tvb_get_guint8( tvb, offset+3 ) * 2;
if( ( item_length-4-add_stat_size ) != 0 )
{
pi = proto_tree_add_text( item_tree, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, "Command Specific Data" );
cmd_data_tree = proto_item_add_subtree( pi, ett_cco_cmd_data );
if( gen_status == CI_GRC_SUCCESS || gen_status == CI_GRC_SERVICE_ERROR )
{
if (((service & 0x7F) == SC_GET_ATT_ALL) &&
(req_data.iInstance != (guint32)-1))
{
if (req_data.iInstance == 0)
{
proto_tree_add_item(cmd_data_tree, hf_cip_class_rev, tvb, offset+4+add_stat_size, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(cmd_data_tree, hf_cip_class_max_inst32, tvb, offset+4+add_stat_size+2, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(cmd_data_tree, hf_cip_class_num_inst32, tvb, offset+4+add_stat_size+6, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(cmd_data_tree, hf_cip_cco_format_number, tvb, offset+4+add_stat_size+10, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(cmd_data_tree, hf_cip_cco_edit_signature, tvb, offset+4+add_stat_size+12, 4, ENC_LITTLE_ENDIAN );
}
else
{
con_sti = proto_tree_add_text( cmd_data_tree, tvb, offset+4+add_stat_size, 4, "Connection Status");
con_st_tree = proto_item_add_subtree(con_sti, ett_cco_con_status);
proto_tree_add_item(con_st_tree, hf_cip_genstat, tvb, offset+4+add_stat_size, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(con_st_tree, hf_cip_pad8, tvb, offset+4+add_stat_size+1, 1, ENC_LITTLE_ENDIAN);
temp_data = tvb_get_letohs( tvb, offset+4+add_stat_size+2);
proto_tree_add_text(con_st_tree, tvb, offset+4+add_stat_size+2, 2, "Extended Status: 0x%04X", temp_data );
dissect_cip_cco_all_attribute_common( cmd_data_tree, tvb, offset+4+add_stat_size+4, item_length, pinfo);
}
}
else
{
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
}
}
else
{
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
}
}
}
else
{
add_cip_service_to_info_column(pinfo, service, cip_sc_vals_cco);
req_path_size = tvb_get_guint8( tvb, offset+1 )*2;
if( (item_length-req_path_size-2) != 0 )
{
pi = proto_tree_add_text( item_tree, tvb, offset+2+req_path_size, item_length-req_path_size-2, "Command Specific Data" );
cmd_data_tree = proto_item_add_subtree( pi, ett_cco_cmd_data );
switch (service)
{
case SC_CCO_AUDIT_CHANGE:
proto_tree_add_item(cmd_data_tree, hf_cip_cco_change_type, tvb, offset+2+req_path_size, 2, ENC_LITTLE_ENDIAN );
break;
case SC_CCO_CHANGE_COMPLETE:
proto_tree_add_item(cmd_data_tree, hf_cip_cco_change_type, tvb, offset+2+req_path_size, 2, ENC_LITTLE_ENDIAN );
break;
case SC_SET_ATT_ALL:
if ((req_data.iInstance == 0) ||
(req_data.iInstance == (guint32)-1))
{
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+2+req_path_size, item_length-req_path_size-2, ENC_NA);
break;
}
dissect_cip_cco_all_attribute_common(cmd_data_tree, tvb, offset+2+req_path_size, item_length, pinfo);
break;
default:
proto_tree_add_item(cmd_data_tree, hf_cip_data, tvb, offset+2+req_path_size, item_length-req_path_size-2, ENC_NA);
}
}
}
}
static int
dissect_cip_class_cco(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *class_tree;
ti = proto_tree_add_item(tree, proto_cip_class_cco, tvb, 0, -1, ENC_NA);
class_tree = proto_item_add_subtree( ti, ett_cip_class_cco );
dissect_cip_cco_data( class_tree, tvb, 0, tvb_length(tvb), pinfo );
return tvb_length(tvb);
}
static gboolean
dissect_class_cco_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
unsigned char service, service_code, ioilen, segment;
cip_req_info_t* preq_info;
guint32 classid = 0;
int offset = 0;
service = tvb_get_guint8( tvb, offset );
service_code = service & 0x7F;
if ((service_code == SC_GET_ATT_ALL) ||
(service_code == SC_SET_ATT_ALL))
{
if (service & 0x80)
{
preq_info = (cip_req_info_t*)p_get_proto_data(pinfo->fd, proto_cip, 0);
if ((preq_info != NULL) &&
(preq_info->dissector == dissector_get_uint_handle( subdissector_class_table, CI_CLS_CCO)))
{
call_dissector(preq_info->dissector, tvb, pinfo, tree);
return TRUE;
}
}
else
{
ioilen = tvb_get_guint8( tvb, offset + 1 );
if (ioilen > 1)
{
segment = tvb_get_guint8( tvb, offset + 2 );
if (((segment & CI_SEGMENT_TYPE_MASK) == CI_LOGICAL_SEGMENT) &&
((segment & CI_LOGICAL_SEG_TYPE_MASK) == CI_LOGICAL_SEG_CLASS_ID))
{
switch ( segment & CI_LOGICAL_SEG_FORMAT_MASK )
{
case CI_LOGICAL_SEG_8_BIT:
classid = tvb_get_guint8( tvb, offset + 3 );
break;
case CI_LOGICAL_SEG_16_BIT:
if ( ioilen >= 2 )
classid = tvb_get_letohs( tvb, offset + 4 );
break;
case CI_LOGICAL_SEG_32_BIT:
if ( ioilen >= 3 )
classid = tvb_get_letohl( tvb, offset + 4 );
break;
}
}
}
if (classid == CI_CLS_CCO)
{
call_dissector(cip_class_cco_handle, tvb, pinfo, tree );
return TRUE;
}
}
}
return FALSE;
}
static void
dissect_cip_data( proto_tree *item_tree, tvbuff_t *tvb, int offset, packet_info *pinfo, cip_req_info_t* preq_info )
{
proto_item *ti;
proto_tree *cip_tree;
proto_item *pi, *rrsc_item, *status_item, *add_status_item;
proto_tree *rrsc_tree, *status_tree, *add_status_tree;
int req_path_size;
unsigned char i, gen_status, add_stat_size;
unsigned char service,ioilen,segment;
void *p_save_proto_data;
cip_simple_request_info_t path_info;
dissector_handle_t dissector;
gint service_index;
p_save_proto_data = p_get_proto_data(pinfo->fd, proto_cip, 0);
p_remove_proto_data(pinfo->fd, proto_cip, 0);
p_add_proto_data(pinfo->fd, proto_cip, 0, preq_info);
ti = proto_tree_add_item(item_tree, proto_cip, tvb, 0, -1, ENC_NA);
cip_tree = proto_item_add_subtree( ti, ett_cip );
service = tvb_get_guint8( tvb, offset );
rrsc_item = proto_tree_add_uint_format_value(cip_tree, hf_cip_service,
tvb, offset, 1, service, "%s (%s)",
val_to_str( ( service & 0x7F ), cip_sc_vals , "Unknown Service (0x%02x)"),
val_to_str_const( ( service & 0x80 )>>7, cip_sc_rr, ""));
rrsc_tree = proto_item_add_subtree( rrsc_item, ett_rrsc );
proto_tree_add_item( rrsc_tree, hf_cip_reqrsp, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rrsc_tree, hf_cip_service_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if( service & 0x80 )
{
status_item = proto_tree_add_text( cip_tree, tvb, offset+2, 1, "Status: " );
status_tree = proto_item_add_subtree( status_item, ett_status_item );
gen_status = tvb_get_guint8( tvb, offset+2 );
proto_tree_add_item(status_tree, hf_cip_genstat, tvb, offset+2, 1, ENC_LITTLE_ENDIAN );
proto_item_append_text( status_item, "%s", val_to_str_ext( gen_status,
&cip_gs_vals_ext , "Unknown Response (%x)") );
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " | ", "%s",
val_to_str_ext( gen_status, &cip_gs_vals_ext, "Unknown Response (%x)") );
col_set_fence(pinfo->cinfo, COL_INFO);
add_stat_size = tvb_get_guint8( tvb, offset+3 );
proto_tree_add_uint_format_value(status_tree, hf_cip_addstat_size,
tvb, offset+3, 1, add_stat_size, "%d (words)", add_stat_size);
if( add_stat_size )
{
add_status_item = proto_tree_add_text( status_tree, tvb, offset+4, add_stat_size*2, "Additional Status" );
add_status_tree = proto_item_add_subtree( add_status_item, ett_add_status_item );
for( i=0; i < add_stat_size; i ++ )
proto_tree_add_item(add_status_tree, hf_cip_add_stat, tvb, offset+4+(i*2), 2, ENC_LITTLE_ENDIAN );
}
proto_item_set_len( status_item, 2 + add_stat_size*2);
if( preq_info
&& !( preq_info->bService == ( service & 0x7F )
|| ( preq_info->bService == SC_CM_UNCON_SEND && preq_info->dissector == cip_class_cm_handle )
)
)
preq_info = NULL;
if ( preq_info )
{
if ( preq_info->IOILen && preq_info->pIOI )
{
tvbuff_t* tvbIOI;
tvbIOI = tvb_new_real_data((const guint8 *)preq_info->pIOI, preq_info->IOILen * 2, preq_info->IOILen * 2);
if ( tvbIOI )
{
pi = proto_tree_add_text( cip_tree, NULL, 0, 0, "Request Path Size: %d (words)", preq_info->IOILen );
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_text(cip_tree, NULL, 0, 0, "Request Path: ");
PROTO_ITEM_SET_GENERATED(pi);
preq_info->ciaData = wmem_new(wmem_file_scope(), cip_simple_request_info_t);
dissect_epath( tvbIOI, pinfo, pi, 0, preq_info->IOILen*2, TRUE, FALSE, preq_info->ciaData, NULL);
tvb_free(tvbIOI);
}
}
}
try_val_to_str_idx((service & 0x7F), cip_sc_vals, &service_index);
if (service_index >= 0)
{
if(!dissector_try_heuristic(heur_subdissector_service, tvb, pinfo, item_tree, NULL))
{
dissect_cip_generic_service_rsp(tvb, pinfo, cip_tree);
}
}
else if ( preq_info && preq_info->dissector )
{
call_dissector( preq_info->dissector, tvb, pinfo, item_tree );
}
else
{
call_dissector( cip_class_generic_handle, tvb, pinfo, item_tree );
}
}
else
{
req_path_size = tvb_get_guint8( tvb, offset+1);
proto_tree_add_uint_format_value(cip_tree, hf_cip_request_path_size,
tvb, offset+1, 1, req_path_size, "%d (words)", req_path_size);
pi = proto_tree_add_text(cip_tree, tvb, offset+2, req_path_size*2, "Request Path: ");
if (preq_info)
{
preq_info->ciaData = wmem_new(wmem_file_scope(), cip_simple_request_info_t);
dissect_epath( tvb, pinfo, pi, offset+2, req_path_size*2, FALSE, FALSE, preq_info->ciaData, NULL);
memcpy(&path_info, preq_info->ciaData, sizeof(cip_simple_request_info_t));
}
else
{
dissect_epath( tvb, pinfo, pi, offset+2, req_path_size*2, FALSE, FALSE, &path_info, NULL);
}
ioilen = tvb_get_guint8( tvb, offset + 1 );
if ( preq_info )
preq_info->dissector = NULL;
dissector = NULL;
if (path_info.iClass != 0xFFFFFFFF)
{
dissector = dissector_get_uint_handle( subdissector_class_table, path_info.iClass);
}
else
{
if ( ioilen >= 1 )
{
segment = tvb_get_guint8( tvb, offset + 2 );
if ((segment & CI_SEGMENT_TYPE_MASK) == CI_DATA_SEGMENT)
{
dissector = dissector_get_uint_handle( subdissector_symbol_table, segment );
}
}
}
if ( preq_info )
{
preq_info->dissector = dissector;
preq_info->pIOI = wmem_alloc(wmem_file_scope(), ioilen*2);
preq_info->IOILen = ioilen;
tvb_memcpy(tvb, preq_info->pIOI, offset+2, ioilen*2);
preq_info->bService = service;
}
try_val_to_str_idx(service, cip_sc_vals, &service_index);
if (service_index >= 0)
{
if(!dissector_try_heuristic(heur_subdissector_service, tvb, pinfo, item_tree, NULL))
{
dissect_cip_generic_service_req(tvb, pinfo, cip_tree, &path_info);
}
}
else if ( dissector )
{
call_dissector( dissector, tvb, pinfo, item_tree );
}
else
{
call_dissector( cip_class_generic_handle, tvb, pinfo, item_tree );
}
}
p_remove_proto_data(pinfo->fd, proto_cip, 0);
p_add_proto_data(pinfo->fd, proto_cip, 0, p_save_proto_data);
}
static int
dissect_cip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
enip_request_info_t *enip_info;
cip_req_info_t *preq_info;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CIP");
col_clear(pinfo->cinfo, COL_INFO);
enip_info = (enip_request_info_t*)p_get_proto_data(pinfo->fd, proto_enip, 0);
if ( enip_info )
{
preq_info = enip_info->cip_info;
if ( preq_info == NULL )
{
preq_info = wmem_new0(wmem_file_scope(), cip_req_info_t);
enip_info->cip_info = preq_info;
}
dissect_cip_data( tree, tvb, 0, pinfo, enip_info->cip_info );
}
else
{
dissect_cip_data( tree, tvb, 0, pinfo, NULL );
}
return tvb_length(tvb);
}
void
proto_register_cip(void)
{
static hf_register_info hf[] = {
{ &hf_cip_service, { "Service", "cip.service", FT_UINT8, BASE_HEX, NULL, 0, "Service Code + Request/Response", HFILL }},
{ &hf_cip_reqrsp, { "Request/Response", "cip.rr", FT_UINT8, BASE_HEX, VALS(cip_sc_rr), 0x80, "Request or Response message", HFILL }},
{ &hf_cip_service_code, { "Service", "cip.sc", FT_UINT8, BASE_HEX, VALS(cip_sc_vals), 0x7F, "Service Code", HFILL }},
{ &hf_cip_epath, { "EPath", "cip.epath", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_genstat, { "General Status", "cip.genstat", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &cip_gs_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_addstat_size, { "Additional Status Size", "cip.addstat_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_add_stat, { "Additional Status", "cip.addstat", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_request_path_size, { "Request Path Size", "cip.request_path_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_path_segment, { "Path Segment", "cip.path_segment", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_path_segment_type, { "Path Segment Type", "cip.path_segment.type", FT_UINT8, BASE_DEC, VALS(cip_path_seg_vals), CI_SEGMENT_TYPE_MASK, NULL, HFILL }},
{ &hf_cip_port_ex_link_addr, { "Extended Link Address", "cip.ex_linkaddress", FT_BOOLEAN, 8, TFS(&tfs_true_false), CI_PORT_SEG_EX_LINK_ADDRESS, NULL, HFILL }},
{ &hf_cip_port, { "Port", "cip.port", FT_UINT8, BASE_DEC, NULL, CI_PORT_SEG_PORT_ID_MASK, "Port Identifier", HFILL }},
{ &hf_cip_link_address_byte, { "Link Address", "cip.linkaddress", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_link_address_size, { "Link Address Size", "cip.linkaddress_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_link_address_string, { "Link Address", "cip.linkaddress", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_logical_seg_type, { "Logical Segment Type", "cip.logical_segment.type", FT_UINT8, BASE_DEC, VALS(cip_logical_segment_type_vals), CI_LOGICAL_SEG_TYPE_MASK, NULL, HFILL }},
{ &hf_cip_logical_seg_format, { "Logical Segment Format", "cip.logical_segment.format", FT_UINT8, BASE_DEC, VALS(cip_logical_segment_format_vals), CI_LOGICAL_SEG_FORMAT_MASK, NULL, HFILL }},
{ &hf_cip_class8, { "Class", "cip.class", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &cip_class_names_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_class16, { "Class", "cip.class", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_class_names_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_class32, { "Class", "cip.class", FT_UINT32, BASE_HEX|BASE_EXT_STRING, &cip_class_names_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_instance8, { "Instance", "cip.instance", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_instance16, { "Instance", "cip.instance", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_instance32, { "Instance", "cip.instance", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_member8, { "Member", "cip.member", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_member16, { "Member", "cip.member", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_member32, { "Member", "cip.member", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_attribute8, { "Attribute", "cip.attribute", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_attribute16, { "Attribute", "cip.attribute", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_attribute32, { "Attribute", "cip.attribute", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_conpoint8, { "Connection Point", "cip.connpoint", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_conpoint16, { "Connection Point", "cip.connpoint", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_conpoint32, { "Connection Point", "cip.connpoint", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_ekey_format, { "Key Format", "cip.ekey.format", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_ekey_vendor, { "Vendor ID", "cip.ekey.vendor", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_vendor_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_ekey_devtype, { "Device Type", "cip.ekey.devtype", FT_UINT16, BASE_DEC|BASE_EXT_STRING, &cip_devtype_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_ekey_prodcode, { "Product Code", "cip.ekey.product_code", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_ekey_compatibility, { "Compatibility", "cip.ekey.compatibility", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_ekey_comp_bit, { "Compatibility", "cip.ekey.comp_bit", FT_UINT8, BASE_HEX, VALS(cip_com_bit_vals), 0x80, "EKey: Compatibility bit", HFILL }},
{ &hf_cip_ekey_majorrev, { "Major Revision", "cip.ekey.major_rev", FT_UINT8, BASE_DEC, NULL, 0x7F, "EKey: Major Revision", HFILL }},
{ &hf_cip_ekey_minorrev, { "Minor Revision", "cip.ekey.minor_rev", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_data_seg_type, { "Data Segment Type", "cip.data_segment.type", FT_UINT8, BASE_DEC, VALS(cip_data_segment_type_vals), CI_DATA_SEG_TYPE_MASK, NULL, HFILL }},
{ &hf_cip_data_seg_size, { "Data Size", "cip.data_segment.size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_data_seg_item, { "Data", "cip.data_segment.data", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_symbol, { "Symbol", "cip.symbol", FT_STRING, BASE_NONE, NULL, 0, "ANSI Extended Symbol Segment", HFILL }},
{ &hf_cip_network_seg_type, { "Network Segment Type", "cip.network_segment.type", FT_UINT8, BASE_DEC, VALS(cip_network_segment_type_vals), CI_NETWORK_SEG_TYPE_MASK, NULL, HFILL }},
{ &hf_cip_seg_schedule, { "Multiplier/Phase", "cip.network_segment.schedule", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_fixed_tag, { "Fixed Tag", "cip.network_segment.fixed_tag", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_prod_inhibit_time, { "Production Inhibit Time", "cip.network_segment.prod_inhibit", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_network_size, { "Network Segment Length", "cip.network_segment.length", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_format, { "Safety Format", "cip.safety_segment.format", FT_UINT8, BASE_DEC, VALS(cip_safety_segment_format_type_vals), 0, NULL, HFILL }},
{ &hf_cip_seg_safety_reserved, { "Reserved", "cip.safety_segment.reserved", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_configuration_crc, { "Configuration CRC", "cip.safety_segment.configuration_crc", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_configuration_timestamp, { "Configuration Timestamp", "cip.safety_segment.configuration_timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_configuration_date, { "Configuration (Manual) Date", "cip.safety_segment.configuration_date", FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }},
{ &hf_cip_seg_safety_configuration_time, { "Configuration (Manual) Time", "cip.safety_segment.configuration_time", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_time_correction_epi, { "Time Correction EPI", "cip.safety_segment.time_correction_eri", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_time_correction_net_params, { "Time Correction Network Connection Parameters", "cip.safety_segment.time_correction.net_params", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_time_correction_own, { "Owner", "cip.safety_segment.time_correction.owner", FT_UINT16, BASE_DEC, VALS(cip_con_owner_vals), 0x8000, "Time Correction: Redundant owner bit", HFILL }},
{ &hf_cip_seg_safety_time_correction_typ, { "Connection Type", "cip.safety_segment.time_correction.type", FT_UINT16, BASE_DEC, VALS(cip_con_type_vals), 0x6000, "Time Correction: Connection type", HFILL }},
{ &hf_cip_seg_safety_time_correction_prio, { "Priority", "cip.safety_segment.time_correction.prio", FT_UINT16, BASE_DEC, VALS(cip_con_prio_vals), 0x0C00, "Time Correction: Connection priority", HFILL }},
{ &hf_cip_seg_safety_time_correction_fixed_var, { "Connection Size Type", "cip.safety_segment.time_correction.f_v", FT_UINT16, BASE_DEC, VALS(cip_con_fw_vals), 0x0200, "Time Correction: Fixed or variable connection size", HFILL }},
{ &hf_cip_seg_safety_time_correction_con_size, { "Connection Size", "cip.safety_segment.time_correction.consize", FT_UINT16, BASE_DEC, NULL, 0x01FF, "Time Correction: Connection size", HFILL }},
{ &hf_cip_seg_safety_tunid, { "Target UNID", "cip.safety_segment.tunid", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_tunid_ssn_timestamp, { "SSN Timestamp", "cip.safety_segment.tunid.ssn.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_tunid_ssn_date, { "SSN (Manual) Date", "cip.safety_segment.tunid.ssn.date", FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }},
{ &hf_cip_seg_safety_tunid_ssn_time, { "SSN (Manual) Time", "cip.safety_segment.tunid.ssn.time", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_tunid_macid, { "MAC ID", "cip.safety_segment.tunid.macid", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_ounid, { "Originator UNID", "cip.safety_segment.ounid", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_ounid_ssn_timestamp, { "SSN Timestamp", "cip.safety_segment.tunid.ssn.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_ounid_ssn_date, { "SSN (Manual) Date", "cip.safety_segment.tunid.ssn.date", FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }},
{ &hf_cip_seg_safety_ounid_ssn_time, { "SSN (Manual) Time", "cip.safety_segment.tunid.ssn.time", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_ounid_macid, { "MAC ID", "cip.safety_segment.ounid.macid", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_ping_eri_multiplier, { "Ping Interval EPI Multiplier", "cip.safety_segment.ping_eri_multiplier", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_time_coord_msg_min_multiplier, { "Time Coord Msg Min Multiplier", "cip.safety_segment.time_coord_msg_min_multiplier", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_network_time_expected_multiplier, { "Network Time Expectation Multiplier", "cip.safety_segment.network_time_expected_multiplier", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_timeout_multiplier, { "Timeout Multiplier", "cip.safety_segment.timeout_multiplier", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_max_consumer_number, { "Max Consumer Number", "cip.safety_segment.max_consumer_number", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_conn_param_crc, { "Connection Param CRC", "cip.safety_segment.conn_param_crc", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_time_correction_conn_id, { "Time Correction Connection ID", "cip.safety_segment.time_correction_conn_id", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_max_fault_number, { "Max Fault Number", "cip.safety_segment.max_fault_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_init_timestamp, { "Initial Timestamp", "cip.safety_segment.init_timestamp", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_init_rollover, { "Initial Rollover Value", "cip.safety_segment.init_rollover", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_seg_safety_data, { "Safety Data", "cip.safety_segment.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_class_rev, { "Class Revision", "cip.class.rev", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_class_max_inst32, { "Max Instance", "cip.class.max_inst", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_class_num_inst32, { "Number of Instances", "cip.class.num_inst", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_reserved8, { "Reserved", "cip.reserved", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
#if 0
{ &hf_cip_reserved16, { "Reserved", "cip.reserved", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
#endif
{ &hf_cip_reserved24, { "Reserved", "cip.reserved", FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_pad8, { "Pad Byte", "cip.pad", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_get_attr_list_attr_count, { "Attribute Count", "cip.getlist.attr_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_get_attr_list_attr_item, { "Attribute", "cip.getlist.attr_item", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_get_attr_list_attr_status, { "General Status", "cip.getlist.attr_status", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_gs_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_sc_get_attr_list_attr_data, { "Data", "cip.getlist.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_set_attr_list_attr_count, { "Attribute Count", "cip.setlist.attr_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_set_attr_list_attr_item, { "Attribute", "cip.setlist.attr_item", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_set_attr_list_attr_status, { "General Status", "cip.setlist.attr_status", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_gs_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_sc_set_attr_list_attr_data, { "Data", "cip.setlist.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_get_attribute_all_data, { "Data", "cip.getall.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_set_attribute_all_data, { "Data", "cip.setall.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_reset_param, { "Reset type", "cip.reset.type", FT_UINT8, BASE_DEC, VALS(cip_reset_type_vals), 0, NULL, HFILL }},
{ &hf_cip_sc_reset_data, { "Data", "cip.reset.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_start_data, { "Data", "cip.start.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_stop_data, { "Data", "cip.stop.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_create_instance, { "Instance", "cip.create.instance", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_create_data, { "Data", "cip.create.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_mult_serv_pack_num_services, { "Number of Services", "cip.msp.num_services", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_mult_serv_pack_offset, { "Offset", "cip.msp.offset", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_mult_serv_pack_num_replies, { "Number of Replies", "cip.msp.num_replies", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_delete_data, { "Data", "cip.delete.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_apply_attributes_data, { "Data", "cip.apply_attributes.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_get_attr_single_data, { "Data", "cip.getsingle.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_set_attr_single_data, { "Data", "cip.setsingle.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_find_next_object_max_instance, { "Maximum ID", "cip.find_next_object.max_instance", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_find_next_object_num_instances, { "Number of Instances:", "cip.find_next_object.num_instances", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_find_next_object_instance_item, { "Instance", "cip.find_next_object.instance", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_restore_data, { "Data", "cip.restore.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_save_data, { "Data", "cip.save.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_noop_data, { "Data", "cip.noop.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_get_member_data, { "Data", "cip.getmember.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_set_member_data, { "Data", "cip.setmember.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_insert_member_data, { "Data", "cip.insertmember.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_remove_member_data, { "Data", "cip.removemember.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_group_sync_is_sync, { "IsSynchronized", "cip.group_sync.data", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_sc_group_sync_data, { "Data", "cip.group_sync.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_data, { "Data", "cip.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_id_vendor_id, { "Vendor ID", "cip.id.vendor_id", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_id_device_type, { "Device Type", "cip.id.device_type", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_id_produce_code, { "Product Code", "cip.id.produce_code", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_id_major_rev, { "Major Revision", "cip.id.major_rev", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_id_minor_rev, { "Minor Revision", "cip.id.minor_rev", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_id_status, { "Status", "cip.id.status", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_id_serial_number, { "Serial Number", "cip.id.serial_number", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_id_product_name, { "Product Name", "cip.id.product_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_msg_rout_num_classes, { "Number of Classes", "cip.mr.num_classes", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_msg_rout_classes, { "Class", "cip.mr.class", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_class_names_vals_ext, 0, NULL, HFILL }},
{ &hf_msg_rout_num_available, { "Number Available", "cip.mr.num_available", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_msg_rout_num_active, { "Number Active", "cip.mr.num_active", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_msg_rout_active_connections, { "Active Connection", "cip.mr.active_connections", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_conn_mgr_open_requests, { "Open Requests", "cip.cm.open_requests", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_conn_mgr_open_format_rejects, { "Open Format Rejects", "cip.cm.open_format_rejects", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_conn_mgr_open_resource_rejects, { "Open Resource Rejects", "cip.cm.open_resource_rejects", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_conn_mgr_other_open_rejects, { "Other Open Rejects", "cip.cm.other_open_rejects", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_conn_mgr_close_requests, { "Close Requests", "cip.cm.close_requests", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_conn_close_format_requests, { "Close Format Requests", "cip.cm.close_format_requests", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_conn_mgr_close_other_requests, { "Close Other Requests", "cip.cm.close_other_requests", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_conn_mgr_conn_timouts, { "Connection Timeouts", "cip.cm.conn_timouts", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_ptp_enable, { "PTP Enable", "cip.time_sync.ptp_enable", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0, NULL, HFILL }},
{ &hf_time_sync_is_synchronized, { "Is Synchronized", "cip.time_sync.is_synchronized", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0, NULL, HFILL }},
{ &hf_time_sync_sys_time_micro, { "System Time (Microseconds)", "cip.time_sync.sys_time_micro", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_sys_time_nano, { "System Time (Nanoseconds)", "cip.time_sync.sys_time_nano", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_offset_from_master, { "Offset from Master", "cip.time_sync.offset_from_master", FT_INT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_max_offset_from_master, { "Max Offset from Master", "cip.time_sync.max_offset_from_master", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_mean_path_delay_to_master, { "Mean Path Delay To Master", "cip.time_sync.mean_path_delay_to_master", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_gm_clock_clock_id, { "Clock Identity", "cip.time_sync.gm_clock.clock_id", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_gm_clock_clock_class, { "Clock Class", "cip.time_sync.gm_clock.clock_class", FT_UINT16, BASE_DEC, VALS(cip_time_sync_clock_class_vals), 0, NULL, HFILL }},
{ &hf_time_sync_gm_clock_time_accuracy, { "Time Accuracy", "cip.time_sync.gm_clock.time_accuracy", FT_UINT16, BASE_DEC, VALS(cip_time_sync_time_accuracy_vals), 0, NULL, HFILL }},
{ &hf_time_sync_gm_clock_offset_scaled_log_variance, { "Offset Scaled Log Variance", "cip.time_sync.gm_clock.offset_scaled_log_variance", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_gm_clock_current_utc_offset, { "Current UTC Offset", "cip.time_sync.gm_clock.current_utc_offset", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_gm_clock_time_property_flags, { "Time Property Flags", "cip.time_sync.gm_clock.time_property_flags", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_gm_clock_time_property_flags_leap61, { "Leap indicator 61", "cip.time_sync.gm_clock.time_property_flags.leap61", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x01, NULL, HFILL }},
{ &hf_time_sync_gm_clock_time_property_flags_leap59, { "Leap indicator 59", "cip.time_sync.gm_clock.time_property_flags.leap59", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_time_sync_gm_clock_time_property_flags_current_utc_valid, { "Current UTC Offset Valid", "cip.time_sync.gm_clock.time_property_flags.current_utc_valid", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_time_sync_gm_clock_time_property_flags_ptp_timescale, { "PTP Timescale", "cip.time_sync.gm_clock.time_property_flags.ptp_timescale", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_time_sync_gm_clock_time_property_flags_time_traceable, { "Time traceable", "cip.time_sync.gm_clock.time_property_flags.time_traceable", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_time_sync_gm_clock_time_property_flags_freq_traceable, { "Frequency traceable", "cip.time_sync.gm_clock.time_property_flags.freq_traceable", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_time_sync_gm_clock_time_source, { "Time Source", "cip.time_sync.gm_clock.time_source", FT_UINT16, BASE_DEC, VALS(cip_time_sync_time_source_vals), 0, NULL, HFILL }},
{ &hf_time_sync_gm_clock_priority1, { "Priority1", "cip.time_sync.gm_clock.priority1", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_gm_clock_priority2, { "Priority2", "cip.time_sync.gm_clock.priority2", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_parent_clock_clock_id, { "Clock Identity", "cip.time_sync.parent_clock.clock_id", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_parent_clock_port_number, { "Port Number", "cip.time_sync.parent_clock.port_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_parent_clock_observed_offset_scaled_log_variance, { "Observed Offset Scaled Log Variance", "cip.time_sync.parent_clock.observed_offset_scaled_log_variance", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_parent_clock_observed_phase_change_rate, { "Observed Phase Change Rate", "cip.time_sync.parent_clock.observed_phase_change_rate", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_local_clock_clock_id, { "Clock Identity", "cip.time_sync.local_clock.clock_id", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_local_clock_clock_class, { "Clock Class", "cip.time_sync.local_clock.clock_class", FT_UINT16, BASE_DEC, VALS(cip_time_sync_clock_class_vals), 0, NULL, HFILL }},
{ &hf_time_sync_local_clock_time_accuracy, { "Time Accuracy", "cip.time_sync.local_clock.time_accuracy", FT_UINT16, BASE_DEC, VALS(cip_time_sync_time_accuracy_vals), 0, NULL, HFILL }},
{ &hf_time_sync_local_clock_offset_scaled_log_variance, { "Offset Scaled Log Variance", "cip.time_sync.local_clock.offset_scaled_log_variance", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_local_clock_current_utc_offset, { "Current UTC Offset", "cip.time_sync.local_clock.current_utc_offset", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_local_clock_time_property_flags, { "Time Property Flags", "cip.time_sync.local_clock.time_property_flags", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_local_clock_time_property_flags_leap61, { "Leap indicator 61", "cip.time_sync.local_clock.time_property_flags.leap61", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x01, NULL, HFILL }},
{ &hf_time_sync_local_clock_time_property_flags_leap59, { "Leap indicator 59", "cip.time_sync.local_clock.time_property_flags.leap59", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_time_sync_local_clock_time_property_flags_current_utc_valid, { "Current UTC Offset Valid", "cip.time_sync.local_clock.time_property_flags.current_utc_valid", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_time_sync_local_clock_time_property_flags_ptp_timescale, { "PTP Timescale", "cip.time_sync.local_clock.time_property_flags.ptp_timescale", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_time_sync_local_clock_time_property_flags_time_traceable, { "Time traceable", "cip.time_sync.local_clock.time_property_flags.time_traceable", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_time_sync_local_clock_time_property_flags_freq_traceable, { "Frequency traceable", "cip.time_sync.local_clock.time_property_flags.freq_traceable", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_time_sync_local_clock_time_source, { "Time Source", "cip.time_sync.local_clock.time_source", FT_UINT16, BASE_DEC, VALS(cip_time_sync_time_source_vals), 0, NULL, HFILL }},
{ &hf_time_sync_num_ports, { "Port Number", "cip.time_sync.port_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_state_info_num_ports, { "Number of Ports", "cip.time_sync.port_state_info.num_ports", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_state_info_port_num, { "Port Number", "cip.time_sync.port_state_info.port_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_state_info_port_state, { "Port State", "cip.time_sync.port_state_info.port_state", FT_UINT16, BASE_DEC, VALS(cip_time_sync_port_state_vals), 0, NULL, HFILL }},
{ &hf_time_sync_port_enable_cfg_num_ports, { "Number of Ports", "cip.time_sync.port_enable_cfg.num_ports", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_enable_cfg_port_num, { "Port Number", "cip.time_sync.port_enable_cfg.port_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_enable_cfg_port_enable, { "Port Enable", "cip.time_sync.port_enable_cfg.port_enable", FT_BOOLEAN, 16, TFS(&tfs_enabled_disabled), 0, NULL, HFILL }},
{ &hf_time_sync_port_log_announce_num_ports, { "Number of Ports", "cip.time_sync.port_log_announce.num_ports", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_log_announce_port_num, { "Port Number", "cip.time_sync.port_log_announce.port_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_log_announce_interval, { "Port Log Announce Interval", "cip.time_sync.port_log_announce.interval", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_log_sync_num_ports, { "Number of Ports", "cip.time_sync.port_log_sync.num_ports", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_log_sync_port_num, { "Port Number", "cip.time_sync.port_log_sync.port_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_log_sync_port_log_sync_interval, { "Port Log Sync Interval", "cip.time_sync.port_log_sync.port_log_sync_interval", FT_INT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_priority1, { "Priority1", "cip.time_sync.priority1", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_priority2, { "Priority2", "cip.time_sync.priority2", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_domain_number, { "Domain number", "cip.time_sync.domain_number", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_clock_type, { "Clock Type", "cip.time_sync.clock_type", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_clock_type_ordinary, { "Ordinary Clock", "cip.time_sync.clock_type.ordinary", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0080, NULL, HFILL }},
{ &hf_time_sync_clock_type_boundary, { "Boundary Clock", "cip.time_sync.clock_type.boundary", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0040, NULL, HFILL }},
{ &hf_time_sync_clock_type_end_to_end, { "End-to-End Transparent Clock", "cip.time_sync.clock_type.end_to_end", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0010, NULL, HFILL }},
{ &hf_time_sync_clock_type_management, { "Management Node", "cip.time_sync.clock_type.management", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0008, NULL, HFILL }},
{ &hf_time_sync_clock_type_slave_only, { "Slave Only", "cip.time_sync.clock_type.slave_only", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0100, NULL, HFILL }},
{ &hf_time_sync_manufacture_id_oui, { "Manufacture Identity OUI", "cip.time_sync.manufacture_id.oui", FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_manufacture_id_reserved, { "Reserved", "cip.time_sync.manufacture_id.reserved", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_prod_desc_size, { "Product Description Size", "cip.time_sync.prod_desc_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_prod_desc_str, { "Product Description", "cip.time_sync.prod_desc", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_revision_data_size, { "Revision Data Size", "cip.time_sync.revision_data_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_revision_data_str, { "Revision Data", "cip.time_sync.revision_data", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_user_desc_size, { "User Description Size", "cip.time_sync.user_desc_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_user_desc_str, { "User Description", "cip.time_sync.user_desc", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_profile_id_info_num_ports, { "Number of Ports", "cip.time_sync.port_profile_id_info.num_ports", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_profile_id_info_port_num, { "Port Number", "cip.time_sync.port_profile_id_info.port_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_profile_id_info_profile_id, { "Port Profile Identity", "cip.time_sync.port_profile_id_info.profile_id", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_phys_addr_info_num_ports, { "Number of Ports", "cip.time_sync.port_phys_addr_info.num_ports", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_phys_addr_info_port_num, { "Port Number", "cip.time_sync.port_phys_addr_info.port_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_phys_addr_info_phys_proto, { "Physical Protocol", "cip.time_sync.port_profile_id_info.phys_proto", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_phys_addr_info_addr_size, { "Size of Address", "cip.time_sync.port_phys_addr_info.addr_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
#if 0
{ &hf_time_sync_port_phys_addr_info_phys_addr, { "Port Physical Address", "cip.time_sync.port_profile_id_info.phys_addr", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
#endif
{ &hf_time_sync_port_proto_addr_info_num_ports, { "Number of Ports", "cip.time_sync.port_proto_addr_info.num_ports", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_proto_addr_info_port_num, { "Port Number", "cip.time_sync.port_proto_addr_info.port_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_proto_addr_info_network_proto, { "Network Protocol", "cip.time_sync.port_proto_addr_info.network_proto", FT_UINT16, BASE_DEC, VALS(cip_time_sync_network_protocol_vals), 0, NULL, HFILL }},
{ &hf_time_sync_port_proto_addr_info_addr_size, { "Size of Address", "cip.time_sync.port_proto_addr_info.addr_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_port_proto_addr_info_port_proto_addr, { "Port Protocol Address", "cip.time_sync.port_profile_id_info.port_proto_addr", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_steps_removed, { "Steps Removed", "cip.time_sync.steps_removed", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_sys_time_and_offset_time, { "System Time (Microseconds)", "cip.time_sync.sys_time_and_offset.time", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_time_sync_sys_time_and_offset_offset, { "System Offset (Microseconds)", "cip.time_sync.sys_time_and_offset.offset", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
};
static hf_register_info hf_cm[] = {
{ &hf_cip_cm_sc, { "Service", "cip.cm.sc", FT_UINT8, BASE_HEX, VALS(cip_sc_vals_cm), 0x7F, NULL, HFILL }},
{ &hf_cip_cm_genstat, { "General Status", "cip.cm.genstat", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &cip_gs_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_cm_addstat_size, { "Additional Status Size", "cip.cm.addstat_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_ext_status, { "Extended Status", "cip.cm.ext_status", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_cm_ext_st_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_cm_add_status, { "Additional Status", "cip.cm.addstat", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_priority, { "Priority", "cip.cm.priority", FT_UINT8, BASE_DEC, NULL, 0x10, NULL, HFILL }},
{ &hf_cip_cm_tick_time, { "Tick time", "cip.cm.tick_time", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_cip_cm_timeout_tick, { "Time-out ticks", "cip.cm.timeout_tick", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_timeout, { "Actual Time Out", "cip.cm.timeout", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_ot_connid, { "O->T Network Connection ID", "cip.cm.ot_connid", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_to_connid, { "T->O Network Connection ID", "cip.cm.to_connid", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_conn_serial_num, { "Connection Serial Number", "cip.cm.conn_serial_num", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_vendor, { "Vendor ID", "cip.cm.vendor", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_vendor_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_cm_timeout_multiplier, { "Connection Timeout Multiplier", "cip.cm.timeout_multiplier", FT_UINT8, BASE_DEC, VALS(cip_con_time_mult_vals), 0, NULL, HFILL }},
{ &hf_cip_cm_ot_rpi, { "O->T RPI", "cip.cm.otrpi", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_ot_net_params32, { "O->T Network Connection Parameters", "cip.cm.ot_net_params", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_ot_net_params16, { "O->T Network Connection Parameters", "cip.cm.ot_net_params", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_to_rpi, { "T->O RPI", "cip.cm.torpi", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_to_net_params32, { "T->O Network Connection Parameters", "cip.cm.to_net_params", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_to_net_params16, { "T->O Network Connection Parameters", "cip.cm.to_net_params", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_transport_type_trigger, { "Transport Type/Trigger", "cip.cm.transport_type_trigger", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_conn_path_size, { "Connection Path Size", "cip.cm.connpath_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_ot_api, { "O->T API", "cip.cm.otapi", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_to_api, { "T->O API", "cip.cm.toapi", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_app_reply_size, { "Application Reply Size", "cip.cm.app_reply_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_app_reply_data , { "Application Reply", "cip.cm.app_reply_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_consumer_number, { "Consumer Number", "cip.cm.consumer_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_targ_vendor_id, { "Target Vendor ID", "cip.cm.targ_vendor", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_vendor_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_cm_targ_dev_serial_num, { "Target Device Serial Number", "cip.cm.targ_dev_serial_num", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_targ_conn_serial_num, { "Target Connection Serial Number", "cip.cm.targ_conn_serial_num", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_initial_timestamp, { "Initial Timestamp", "cip.cm.initial_timestamp", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_initial_rollover, { "Initial Rollover Value", "cip.cm.initial_rollover", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_remain_path_size, { "Remaining Path Size", "cip.cm.remain_path_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_msg_req_size, { "Message Request Size", "cip.cm.msg_req_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_route_path_size, { "Route Path Size", "cip.cm.route_path_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_orig_serial_num, { "Originator Serial Number", "cip.cm.orig_serial_num", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_fwo_con_size, { "Connection Size", "cip.cm.fwo.consize", FT_UINT16, BASE_DEC, NULL, 0x01FF, "Fwd Open: Connection size", HFILL }},
{ &hf_cip_cm_lfwo_con_size, { "Connection Size", "cip.cm.fwo.consize", FT_UINT32, BASE_DEC, NULL, 0xFFFF, "Large Fwd Open: Connection size", HFILL }},
{ &hf_cip_cm_fwo_fixed_var, { "Connection Size Type", "cip.cm.fwo.f_v", FT_UINT16, BASE_DEC, VALS(cip_con_fw_vals), 0x0200, "Fwd Open: Fixed or variable connection size", HFILL }},
{ &hf_cip_cm_lfwo_fixed_var, { "Connection Size Type", "cip.cm.fwo.f_v", FT_UINT32, BASE_DEC, VALS(cip_con_fw_vals), 0x02000000, "Large Fwd Open: Fixed or variable connection size", HFILL }},
{ &hf_cip_cm_fwo_prio, { "Priority", "cip.cm.fwo.prio", FT_UINT16, BASE_DEC, VALS(cip_con_prio_vals), 0x0C00, "Fwd Open: Connection priority", HFILL }},
{ &hf_cip_cm_lfwo_prio, { "Priority", "cip.cm.fwo.prio", FT_UINT32, BASE_DEC, VALS(cip_con_prio_vals), 0x0C000000, "Large Fwd Open: Connection priority", HFILL }},
{ &hf_cip_cm_fwo_typ, { "Connection Type", "cip.cm.fwo.type", FT_UINT16, BASE_DEC, VALS(cip_con_type_vals), 0x6000, "Fwd Open: Connection type", HFILL }},
{ &hf_cip_cm_lfwo_typ, { "Connection Type", "cip.cm.fwo.type", FT_UINT32, BASE_DEC, VALS(cip_con_type_vals), 0x60000000, "Large Fwd Open: Connection type", HFILL }},
{ &hf_cip_cm_fwo_own, { "Owner", "cip.cm.fwo.owner", FT_UINT16, BASE_DEC, VALS(cip_con_owner_vals), 0x8000, "Fwd Open: Redundant owner bit", HFILL }},
{ &hf_cip_cm_lfwo_own, { "Owner", "cip.cm.fwo.owner", FT_UINT32, BASE_DEC, VALS(cip_con_owner_vals), 0x80000000, "Large Fwd Open: Redundant owner bit", HFILL }},
{ &hf_cip_cm_fwo_dir, { "Direction", "cip.cm.fwo.dir", FT_UINT8, BASE_DEC, VALS(cip_con_dir_vals), CI_PRODUCTION_DIR_MASK, "Fwd Open: Direction", HFILL }},
{ &hf_cip_cm_fwo_trigg, { "Trigger", "cip.cm.fwo.trigger", FT_UINT8, BASE_DEC, VALS(cip_con_trigg_vals), CI_PRODUCTION_TRIGGER_MASK, "Fwd Open: Production trigger", HFILL }},
{ &hf_cip_cm_fwo_class, { "Class", "cip.cm.fwo.transport", FT_UINT8, BASE_DEC, VALS(cip_con_class_vals), CI_TRANSPORT_CLASS_MASK, "Fwd Open: Transport Class", HFILL }},
{ &hf_cip_cm_gco_conn, { "Number of Connections", "cip.cm.gco.conn", FT_UINT8, BASE_DEC, NULL, 0, "GetConnOwner: Number of Connections", HFILL }},
{ &hf_cip_cm_gco_coo_conn, { "COO Connections", "cip.cm.gco.coo_conn", FT_UINT8, BASE_DEC, NULL, 0, "GetConnOwner: COO Connections", HFILL }},
{ &hf_cip_cm_gco_roo_conn, { "ROO Connections", "cip.cm.gco.roo_conn", FT_UINT8, BASE_DEC, NULL, 0, "GetConnOwner: ROO Connections", HFILL }},
{ &hf_cip_cm_gco_last_action, { "Last Action", "cip.cm.gco.la", FT_UINT8, BASE_DEC, VALS(cip_con_last_action_vals), 0, "GetConnOwner: Last Action", HFILL }},
{ &hf_cip_cm_ext112_ot_rpi_type, { "Trigger", "cip.cm.ext112otrpi_type", FT_UINT8, BASE_DEC, VALS(cip_cm_rpi_type_vals), 0, NULL, HFILL }},
{ &hf_cip_cm_ext112_to_rpi_type, { "Trigger", "cip.cm.ext112torpi_type", FT_UINT8, BASE_DEC, VALS(cip_cm_rpi_type_vals), 0, NULL, HFILL }},
{ &hf_cip_cm_ext112_ot_rpi, { "Acceptable O->T RPI", "cip.cm.ext112otrpi", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_ext112_to_rpi, { "Acceptable T->O RPI", "cip.cm.ext112torpi", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_ext126_size, { "Maximum Size", "cip.cm.ext126_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_ext127_size, { "Maximum Size", "cip.cm.ext127_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cm_ext128_size, { "Maximum Size", "cip.cm.ext128_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }}
};
static hf_register_info hf_mb[] = {
{ &hf_cip_mb_sc, { "Service", "cip.mb.sc", FT_UINT8, BASE_HEX, VALS(cip_sc_vals_mb), 0x7F, NULL, HFILL }},
{ &hf_cip_mb_read_coils_start_addr, { "Starting Address", "cip.mb.read_coils.start_addr", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_coils_num_coils, { "Quantity of Coils", "cip.mb.read_coils.num_coils", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_coils_data, { "Data", "cip.mb.read_coils.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_discrete_inputs_start_addr, { "Starting Address", "cip.mb.read_discrete_inputs.start_addr", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_discrete_inputs_num_inputs, { "Quantity of Inputs", "cip.mb.read_discrete_inputs.num_inputs", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_discrete_inputs_data, { "Data", "cip.mb.read_discrete_inputs.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_holding_register_start_addr, { "Starting Address", "cip.mb.read_holding_register.start_addr", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_holding_register_num_registers, { "Quantity of Holding Registers", "cip.mb.read_holding_register.num_registers", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_holding_register_data, { "Data", "cip.mb.read_holding_register.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_input_register_start_addr, { "Starting Address", "cip.mb.read_input_register.start_addr", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_input_register_num_registers, { "Quantity of Input Registers", "cip.mb.read_input_register.num_registers", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_read_input_register_data, { "Data", "cip.mb.read_input_register.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_write_coils_start_addr, { "Starting Address", "cip.mb.write_coils.start_addr", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_write_coils_outputs_forced, { "Outputs Forced", "cip.mb.write_coils.outputs_forced", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_write_coils_num_coils, { "Quantity of Coils", "cip.mb.write_coils.num_coils", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_write_coils_data, { "Data", "cip.mb.write_coils.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_write_registers_start_addr, { "Starting Address", "cip.mb.write_registers.start_addr", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_write_registers_outputs_forced, { "Outputs Forced", "cip.mb.write_registers.outputs_forced", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_write_registers_num_registers, { "Quantity of Holding Registers", "cip.mb.write_registers.num_registers", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_write_registers_data, { "Data", "cip.mb.write_registers.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_mb_data, { "Data", "cip.mb.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }}
};
static hf_register_info hf_cco[] = {
{ &hf_cip_cco_sc, { "Service", "cip.cco.sc", FT_UINT8, BASE_HEX, VALS(cip_sc_vals_cco), 0x7F, NULL, HFILL }},
{ &hf_cip_cco_format_number, { "Format Number", "cip.cco.format_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_edit_signature, { "Edit Signature", "cip.cco.edit_signature", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_con_flags, { "Connection Flags", "cip.cco.connflags", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_con_type, { "Connection O_T", "cip.cco.con", FT_UINT16, BASE_DEC, VALS(cip_con_vals), 0x001, NULL, HFILL }},
{ &hf_cip_cco_ot_rtf, { "O->T real time transfer format", "cip.cco.otrtf", FT_UINT16, BASE_DEC, VALS(cip_con_rtf_vals), 0x000E, NULL, HFILL }},
{ &hf_cip_cco_to_rtf, { "T->O real time transfer format", "cip.cco.tortf", FT_UINT16, BASE_DEC, VALS(cip_con_rtf_vals), 0x0070, NULL, HFILL }},
{ &hf_cip_cco_tdi_vendor, { "Vendor ID", "cip.cco.tdi.vendor", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_vendor_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_cco_tdi_devtype, { "Device Type", "cip.cco.tdi.devtype", FT_UINT16, BASE_DEC|BASE_EXT_STRING, &cip_devtype_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_cco_tdi_prodcode, { "Product Code", "cip.cco.tdi.product_code", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_tdi_compatibility, { "Compatibility", "cip.cco.tdi.compatibility", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_tdi_comp_bit, { "Compatibility", "cip.cco.tdi.comp_bit", FT_UINT8, BASE_HEX, VALS(cip_com_bit_vals), 0x80, NULL, HFILL }},
{ &hf_cip_cco_tdi_majorrev, { "Major Revision", "cip.cco.tdi.major_rev", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }},
{ &hf_cip_cco_tdi_minorrev, { "Minor Revision", "cip.cco.tdi.minor_rev", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_pdi_vendor, { "Vendor ID", "cip.cco.pdi.vendor", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_vendor_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_cco_pdi_devtype, { "Device Type", "cip.cco.pdi.devtype", FT_UINT16, BASE_DEC|BASE_EXT_STRING, &cip_devtype_vals_ext, 0, NULL, HFILL }},
{ &hf_cip_cco_pdi_prodcode, { "Product Code", "cip.cco.pdi.product_code", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_pdi_compatibility, { "Compatibility", "cip.cco.pdi.compatibility", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_pdi_comp_bit, { "Compatibility", "cip.cco.pdi.comp_bit", FT_UINT8, BASE_HEX, VALS(cip_com_bit_vals), 0x80, NULL, HFILL }},
{ &hf_cip_cco_pdi_majorrev, { "Major Revision", "cip.cco.pdi.major_rev", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }},
{ &hf_cip_cco_pdi_minorrev, { "Minor Revision", "cip.cco.pdi.minor_rev", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_cs_data_index, { "CS Data Index Number", "cip.cco.cs_data_index", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_timeout_multiplier, { "Connection Timeout Multiplier", "cip.cco.timeout_multiplier", FT_UINT8, BASE_DEC, VALS(cip_con_time_mult_vals), 0, NULL, HFILL }},
{ &hf_cip_cco_ot_rpi, { "O->T RPI", "cip.cco.otrpi", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_ot_net_param32, { "O->T Network Connection Parameters", "cip.cco.ot_net_params", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_ot_net_param16, { "O->T Network Connection Parameters", "cip.cco.ot_net_params", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_to_rpi, { "T->O RPI", "cip.cco.torpi", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_to_net_param16, { "T->O Network Connection Parameters", "cip.cco.to_net_params", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_to_net_param32, { "T->O Network Connection Parameters", "cip.cco.to_net_params", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_transport_type_trigger, { "Transport Type/Trigger", "cip.cco.transport_type_trigger", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_fwo_con_size, { "Connection Size", "cip.cco.consize", FT_UINT16, BASE_DEC, NULL, 0x01FF, NULL, HFILL }},
{ &hf_cip_cco_lfwo_con_size, { "Connection Size", "cip.cco.consize", FT_UINT32, BASE_DEC, NULL, 0xFFFF, NULL, HFILL }},
{ &hf_cip_cco_fwo_fixed_var, { "Connection Size Type", "cip.cco.f_v", FT_UINT16, BASE_DEC, VALS(cip_con_fw_vals), 0x0200, NULL, HFILL }},
{ &hf_cip_cco_lfwo_fixed_var, { "Connection Size Type", "cip.cco.f_v", FT_UINT32, BASE_DEC, VALS(cip_con_fw_vals), 0x02000000, NULL, HFILL }},
{ &hf_cip_cco_fwo_prio, { "Priority", "cip.cco.prio", FT_UINT16, BASE_DEC, VALS(cip_con_prio_vals), 0x0C00, NULL, HFILL }},
{ &hf_cip_cco_lfwo_prio, { "Priority", "cip.cco.prio", FT_UINT32, BASE_DEC, VALS(cip_con_prio_vals), 0x0C000000, NULL, HFILL }},
{ &hf_cip_cco_fwo_typ, { "Connection Type", "cip.cco.type", FT_UINT16, BASE_DEC, VALS(cip_con_type_vals), 0x6000, NULL, HFILL }},
{ &hf_cip_cco_lfwo_typ, { "Connection Type", "cip.cco.type", FT_UINT32, BASE_DEC, VALS(cip_con_type_vals), 0x60000000, NULL, HFILL }},
{ &hf_cip_cco_fwo_own, { "Owner", "cip.cco.owner", FT_UINT16, BASE_DEC, VALS(cip_con_owner_vals), 0x8000, NULL, HFILL }},
{ &hf_cip_cco_lfwo_own, { "Owner", "cip.cco.owner", FT_UINT32, BASE_DEC, VALS(cip_con_owner_vals), 0x80000000, NULL, HFILL }},
{ &hf_cip_cco_fwo_dir, { "Direction", "cip.cco.dir", FT_UINT8, BASE_DEC, VALS(cip_con_dir_vals), CI_PRODUCTION_DIR_MASK, NULL, HFILL }},
{ &hf_cip_cco_fwo_trigger, { "Trigger", "cip.cco.trigger", FT_UINT8, BASE_DEC, VALS(cip_con_trigg_vals), CI_PRODUCTION_TRIGGER_MASK, NULL, HFILL }},
{ &hf_cip_cco_fwo_class, { "Class", "cip.cco.transport", FT_UINT8, BASE_DEC, VALS(cip_con_class_vals), CI_TRANSPORT_CLASS_MASK, NULL, HFILL }},
{ &hf_cip_cco_conn_path_size, { "Connection Path Size", "cip.cco.connpath_size", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_proxy_config_size, { "Proxy Config Data Size", "cip.cco.proxy_config_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_target_config_size, { "Target Config Data Size", "cip.cco.proxy_config_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_iomap_format_number, { "Format number", "cip.cco.iomap_format_number", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_iomap_size, { "Attribute size", "cip.cco.iomap_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_connection_disable, { "Connection Disable", "cip.cco.connection_disable", FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }},
{ &hf_cip_cco_net_conn_param_attr, { "Net Connection Parameter Attribute Selection", "cip.cco.net_conn_param_attr", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_proxy_config_data, { "Proxy Config Data", "cip.cco.proxy_config_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_target_config_data, { "Target Config Data", "cip.cco.target_config_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_iomap_attribute, { "Attribute Data", "cip.cco.iomap", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_safety, { "Safety Parameters", "cip.cco.safety", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_cip_cco_change_type, { "Change Type", "cip.cco.change_type", FT_UINT16, BASE_DEC, cip_cco_change_type_vals, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_cip_class_generic,
&ett_cip,
&ett_path,
&ett_path_seg,
&ett_ekey_path,
&ett_rrsc,
&ett_mcsc,
&ett_cia_path,
&ett_data_seg,
&ett_data_seg_data,
&ett_cmd_data,
&ett_port_path,
&ett_network_seg,
&ett_network_seg_safety,
&ett_network_seg_safety_time_correction_net_params,
&ett_cip_seg_safety_tunid,
&ett_cip_seg_safety_tunid_ssn,
&ett_cip_seg_safety_ounid,
&ett_cip_seg_safety_ounid_ssn,
&ett_status_item,
&ett_add_status_item,
&ett_cip_get_attribute_list,
&ett_cip_get_attribute_list_item,
&ett_cip_set_attribute_list,
&ett_cip_set_attribute_list_item,
&ett_cip_mult_service_packet,
&ett_time_sync_gm_clock_flags,
&ett_time_sync_local_clock_flags,
&ett_time_sync_port_state_info,
&ett_time_sync_port_enable_cfg,
&ett_time_sync_port_log_announce,
&ett_time_sync_port_log_sync,
&ett_time_sync_clock_type,
&ett_time_sync_port_profile_id_info,
&ett_time_sync_port_phys_addr_info,
&ett_time_sync_port_proto_addr_info,
};
static gint *ett_cm[] = {
&ett_cip_class_cm,
&ett_cm_rrsc,
&ett_cm_mes_req,
&ett_cm_ncp,
&ett_cm_cmd_data,
&ett_cm_ttt,
&ett_cm_add_status_item,
&ett_cip_cm_pid,
&ett_cip_cm_safety
};
static gint *ett_mb[] = {
&ett_cip_class_mb,
&ett_mb_rrsc,
&ett_mb_cmd_data
};
static gint *ett_cco[] = {
&ett_cip_class_cco,
&ett_cco_iomap,
&ett_cco_con_status,
&ett_cco_con_flag,
&ett_cco_tdi,
&ett_cco_pdi,
&ett_cco_ncp,
&ett_cco_rrsc,
&ett_cco_cmd_data,
&ett_cco_ttt,
};
static ei_register_info ei[] = {
{ &ei_mal_identity_revision, { "cip.malformed.id.revision", PI_MALFORMED, PI_ERROR, "Malformed Identity revision", EXPFILL }},
{ &ei_mal_msg_rout_num_classes, { "cip.malformed.msg_rout.num_classes", PI_MALFORMED, PI_ERROR, "Malformed Message Router Attribute 1", EXPFILL }},
{ &ei_mal_time_sync_gm_clock, { "cip.malformed.time_sync.gm_clock", PI_MALFORMED, PI_ERROR, "Malformed Grandmaster clock info", EXPFILL }},
{ &ei_mal_time_sync_parent_clock, { "cip.malformed.time_sync.parent_clock", PI_MALFORMED, PI_ERROR, "Malformed Parent clock info", EXPFILL }},
{ &ei_mal_time_sync_local_clock, { "cip.malformed.time_sync.local_clock", PI_MALFORMED, PI_ERROR, "Malformed Local clock info", EXPFILL }},
{ &ei_mal_time_sync_port_state_info, { "cip.malformed.time_sync.port_state_info", PI_MALFORMED, PI_ERROR, "Malformed Port State Info", EXPFILL }},
{ &ei_mal_time_sync_port_state_info_ports, { "cip.malformed.time_sync.port_state_info.ports", PI_MALFORMED, PI_ERROR, "Malformed Port State Info - too many ports", EXPFILL }},
{ &ei_mal_time_sync_port_enable_cfg, { "cip.malformed.time_sync.port_enable_cfg", PI_MALFORMED, PI_ERROR, "Malformed Port Enable Cfg", EXPFILL }},
{ &ei_mal_time_sync_port_enable_cfg_ports, { "cip.malformed.time_sync.port_enable_cfg.ports", PI_MALFORMED, PI_ERROR, "Malformed Port Enable Cfg - too many ports", EXPFILL }},
{ &ei_mal_time_sync_port_log_announce, { "cip.malformed.time_sync.port_log_announce", PI_MALFORMED, PI_ERROR, "Malformed Port Log Announcement Interval Cfg", EXPFILL }},
{ &ei_mal_time_sync_port_log_announce_ports, { "cip.malformed.time_sync.port_log_announce.ports", PI_MALFORMED, PI_ERROR, "Malformed Port Log Announcement Interval Cfg - too many ports", EXPFILL }},
{ &ei_mal_time_sync_port_log_sync, { "cip.malformed.time_sync.port_log_sync", PI_MALFORMED, PI_ERROR, "Malformed Port Log Sync Interval Cfg", EXPFILL }},
{ &ei_mal_time_sync_port_log_sync_ports, { "cip.malformed.time_sync.port_log_sync.ports", PI_MALFORMED, PI_ERROR, "Malformed Port Log Sync Interval Cfg - too many ports", EXPFILL }},
{ &ei_mal_time_sync_clock_type, { "cip.malformed.time_sync.clock_type", PI_MALFORMED, PI_ERROR, "Malformed Clock Type", EXPFILL }},
{ &ei_mal_time_sync_manufacture_id, { "cip.malformed.time_sync.manufacture_id", PI_MALFORMED, PI_ERROR, "Malformed Manufacture Identity", EXPFILL }},
{ &ei_mal_time_sync_prod_desc, { "cip.malformed.time_sync.prod_desc", PI_MALFORMED, PI_ERROR, "Malformed Product Description", EXPFILL }},
{ &ei_mal_time_sync_prod_desc_64, { "cip.malformed.time_sync.prod_desc.limit_64", PI_PROTOCOL, PI_WARN, "Product Description limited to 64 characters", EXPFILL }},
{ &ei_mal_time_sync_prod_desc_size, { "cip.malformed.time_sync.prod_desc.size", PI_MALFORMED, PI_ERROR, "Malformed Product Description - invalid size", EXPFILL }},
{ &ei_mal_time_sync_revision_data, { "cip.malformed.time_sync.revision_data", PI_MALFORMED, PI_ERROR, "Malformed Revision Data", EXPFILL }},
{ &ei_mal_time_sync_revision_data_32, { "cip.malformed.time_sync.revision_data.limit_32", PI_PROTOCOL, PI_WARN, "Revision Data limited to 32 characters", EXPFILL }},
{ &ei_mal_time_sync_revision_data_size, { "cip.malformed.time_sync.revision_data.size", PI_MALFORMED, PI_ERROR, "Malformed Revision Data - invalid size", EXPFILL }},
{ &ei_mal_time_sync_user_desc, { "cip.malformed.time_sync.user_desc", PI_MALFORMED, PI_ERROR, "Malformed User Description", EXPFILL }},
{ &ei_mal_time_sync_user_desc_128, { "cip.malformed.time_sync.user_desc.limit_128", PI_PROTOCOL, PI_WARN, "User Description limited to 128 characters", EXPFILL }},
{ &ei_mal_time_sync_user_desc_size, { "cip.malformed.time_sync.user_desc.size", PI_MALFORMED, PI_ERROR, "Malformed User Description - invalid size", EXPFILL }},
{ &ei_mal_time_sync_port_profile_id_info, { "cip.malformed.time_sync.port_profile_id_info", PI_MALFORMED, PI_ERROR, "Malformed Port Profile Identity Info", EXPFILL }},
{ &ei_mal_time_sync_port_profile_id_info_ports, { "cip.malformed.time_sync.port_profile_id_info.ports", PI_MALFORMED, PI_ERROR, "Malformed Port Profile Identity Info - too many ports", EXPFILL }},
{ &ei_mal_time_sync_port_phys_addr_info, { "cip.malformed.time_sync.port_phys_addr_info", PI_MALFORMED, PI_ERROR, "Malformed Port Physical Address Info", EXPFILL }},
{ &ei_mal_time_sync_port_phys_addr_info_ports, { "cip.malformed.time_sync.port_phys_addr_info.ports", PI_MALFORMED, PI_ERROR, "Malformed Port Physical Address Info - too many ports", EXPFILL }},
{ &ei_mal_time_sync_port_proto_addr_info, { "cip.malformed.time_sync.port_proto_addr_info", PI_MALFORMED, PI_ERROR, "Malformed Port Protocol Address Info", EXPFILL }},
{ &ei_mal_time_sync_port_proto_addr_info_ports, { "cip.malformed.time_sync.port_proto_addr_info.ports", PI_MALFORMED, PI_ERROR, "Malformed Port Protocol Address Info - too many ports", EXPFILL }},
{ &ei_mal_time_sync_sys_time_and_offset, { "cip.malformed.time_sync.sys_time_and_offset", PI_MALFORMED, PI_ERROR, "Malformed System Time and Offset", EXPFILL }},
{ &ei_proto_log_seg_format, { "cip.unsupported.log_seg_format", PI_PROTOCOL, PI_WARN, "Unsupported Logical Segment Format", EXPFILL }},
{ &ei_mal_incomplete_epath, { "cip.malformed.incomplete_epath", PI_MALFORMED, PI_ERROR, "Incomplete EPATH", EXPFILL }},
{ &ei_proto_electronic_key_format, { "cip.unsupported.electronic_key_format", PI_PROTOCOL, PI_WARN, "Unsupported Electronic Key Format", EXPFILL }},
{ &ei_proto_special_segment_format, { "cip.unsupported.special_segment_format", PI_PROTOCOL, PI_WARN, "Unsupported Special Segment Format", EXPFILL }},
{ &ei_proto_log_seg_type, { "cip.unsupported.log_seg_type", PI_PROTOCOL, PI_WARN, "Unsupported Logical Segment Type", EXPFILL }},
{ &ei_proto_log_sub_seg_type, { "cip.unsupported.log_sub_seg_type", PI_PROTOCOL, PI_WARN, "Unsupported Sub-Segment Type", EXPFILL }},
{ &ei_proto_seg_type, { "cip.unsupported.seg_type", PI_PROTOCOL, PI_WARN, "Unsupported Segment Type", EXPFILL }},
{ &ei_proto_unsupported_datatype, { "cip.unsupported.datatype", PI_PROTOCOL, PI_WARN, "Unsupported Datatype", EXPFILL }},
{ &ei_mal_serv_gal, { "cip.malformed.get_attribute_list", PI_MALFORMED, PI_ERROR, "Malformed Get Attribute List service", EXPFILL }},
{ &ei_mal_serv_gal_count, { "cip.malformed.get_attribute_list.count", PI_MALFORMED, PI_ERROR, "Malformed Get Attribute List attribute list count greater than packet size", EXPFILL }},
{ &ei_mal_serv_sal, { "cip.malformed.set_attribute_list", PI_MALFORMED, PI_ERROR, "Malformed Set Attribute List service", EXPFILL }},
{ &ei_mal_serv_sal_count, { "cip.malformed.set_attribute_list.count", PI_MALFORMED, PI_ERROR, "Malformed Set Attribute List attribute list count greater than packet size", EXPFILL }},
{ &ei_mal_msp_services, { "cip.malformed.msp.services", PI_MALFORMED, PI_WARN, "Multiple Service Packet too many services for packet", EXPFILL }},
{ &ei_mal_msp_inv_offset, { "cip.malformed.msp.inv_offset", PI_MALFORMED, PI_WARN, "Multiple Service Packet service invalid offset", EXPFILL }},
{ &ei_mal_msp_missing_services, { "cip.malformed.msp.missing_services", PI_MALFORMED, PI_ERROR, "Multiple Service Packet service missing Number of Services field", EXPFILL }},
{ &ei_mal_msp_resp_offset, { "cip.malformed.msp.resp_offset", PI_MALFORMED, PI_ERROR, "Multiple Service Packet service too many response offsets for packet size", EXPFILL }},
{ &ei_mal_serv_find_next_object, { "cip.malformed.find_next_object", PI_MALFORMED, PI_ERROR, "Find Next Object service missing Number of List Members field", EXPFILL }},
{ &ei_mal_serv_find_next_object_count, { "cip.malformed.find_next_object.count", PI_MALFORMED, PI_ERROR, "Find Next Object instance list count greater than packet size", EXPFILL }},
{ &ei_mal_rpi_no_data, { "cip.malformed.rpi_no_data", PI_MALFORMED, PI_WARN, "RPI not acceptable - missing extended data", EXPFILL }},
{ &ei_mal_inv_config_size, { "cip.malformed.inv_config_size", PI_MALFORMED, PI_WARN, "Invalid configuration size - missing size field", EXPFILL }},
{ &ei_mal_ot_size, { "cip.malformed.ot_size", PI_MALFORMED, PI_WARN, "Invalid O->T size - missing size field", EXPFILL }},
{ &ei_mal_to_size, { "cip.malformed.to_size", PI_MALFORMED, PI_WARN, "Invalid T->O size - missing size field", EXPFILL }},
};
expert_module_t* expert_cip;
proto_cip = proto_register_protocol("Common Industrial Protocol",
"CIP", "cip");
proto_register_field_array(proto_cip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cip = expert_register_protocol(proto_cip);
expert_register_field_array(expert_cip, ei, array_length(ei));
subdissector_class_table = register_dissector_table("cip.class.iface",
"CIP Class Interface Handle", FT_UINT32, BASE_HEX);
subdissector_symbol_table = register_dissector_table("cip.data_segment.iface",
"CIP Data Segment Interface Handle", FT_UINT32, BASE_HEX);
proto_cip_class_generic = proto_register_protocol("CIP Class Generic",
"CIPCLS", "cipcls");
proto_cip_class_cm = proto_register_protocol("CIP Connection Manager",
"CIPCM", "cipcm");
proto_register_field_array(proto_cip_class_cm, hf_cm, array_length(hf_cm));
proto_register_subtree_array(ett_cm, array_length(ett_cm));
proto_cip_class_mb = proto_register_protocol("CIP Modbus Object",
"CIPMB", "cipmb");
proto_register_field_array(proto_cip_class_mb, hf_mb, array_length(hf_mb));
proto_register_subtree_array(ett_mb, array_length(ett_mb));
proto_cip_class_cco = proto_register_protocol("CIP Connection Configuration Object",
"CIPCCO", "cipcco");
proto_register_field_array(proto_cip_class_cco, hf_cco, array_length(hf_cco));
proto_register_subtree_array(ett_cco, array_length(ett_cco));
register_heur_dissector_list("cip.sc", &heur_subdissector_service);
}
void
proto_reg_handoff_cip(void)
{
dissector_handle_t cip_handle;
dissector_handle_t cip_class_mb_handle;
cip_handle = new_create_dissector_handle( dissect_cip, proto_cip );
dissector_add_uint( "enip.srrd.iface", ENIP_CIP_INTERFACE, cip_handle );
dissector_add_uint( "enip.sud.iface", ENIP_CIP_INTERFACE, cip_handle );
cip_class_generic_handle = new_create_dissector_handle( dissect_cip_class_generic, proto_cip_class_generic );
dissector_add_uint( "cip.class.iface", 0, cip_class_generic_handle );
cip_class_cm_handle = new_create_dissector_handle( dissect_cip_class_cm, proto_cip_class_cm );
dissector_add_uint( "cip.class.iface", CI_CLS_CM, cip_class_cm_handle );
cip_class_mb_handle = new_create_dissector_handle( dissect_cip_class_mb, proto_cip_class_mb );
dissector_add_uint( "cip.class.iface", CI_CLS_MB, cip_class_mb_handle );
modbus_handle = find_dissector("modbus");
cip_class_cco_handle = new_create_dissector_handle( dissect_cip_class_cco, proto_cip_class_cco );
dissector_add_uint( "cip.class.iface", CI_CLS_CCO, cip_class_cco_handle );
heur_dissector_add("cip.sc", dissect_class_cco_heur, proto_cip_class_cco);
proto_enip = proto_get_id_by_filter_name( "enip" );
proto_modbus = proto_get_id_by_filter_name( "modbus" );
}
