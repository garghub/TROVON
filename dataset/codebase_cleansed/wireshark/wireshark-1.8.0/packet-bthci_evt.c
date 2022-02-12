static int
dissect_bthci_evt_bd_addr(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 i, bd_addr[6];
proto_item *handle_item;
for(i=6; i; i--)
bd_addr[6-i] = tvb_get_guint8(tvb, offset+i-1);
handle_item = proto_tree_add_item(tree, hf_bthci_evt_bd_addr, tvb, offset, 6, ENC_NA);
proto_item_append_text(handle_item, "%02x%02x:%02x:%02x%02x%02x (%s)",
bd_addr[0], bd_addr[1], bd_addr[2], bd_addr[3], bd_addr[4], bd_addr[5],
get_ether_name(bd_addr));
offset+=6;
return offset;
}
static int
dissect_bthci_evt_cod(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cod1, cod2;
proto_item *item;
item = proto_tree_add_item(tree, hf_bthci_evt_class_of_device, tvb, offset, 3, ENC_LITTLE_ENDIAN);
cod1 = tvb_get_guint8(tvb, offset+1);
cod2 = tvb_get_guint8(tvb, offset+2);
if ((cod2 != 0) || (cod1 & 0x20))
{
char buf[128];
buf[0] = 0;
proto_item_append_text(item, " (%s - services:", val_to_str_ext_const(cod1 & 0x1f, &bthci_cmd_major_dev_class_vals_ext, "???"));
if (cod2 & 0x80) g_strlcat(buf, " Information,", sizeof(buf));
if (cod2 & 0x40) g_strlcat(buf, " Telephony,", sizeof(buf));
if (cod2 & 0x20) g_strlcat(buf, " Audio,", sizeof(buf));
if (cod2 & 0x10) g_strlcat(buf, " Object transfer,", sizeof(buf));
if (cod2 & 0x08) g_strlcat(buf, " Capturing,", sizeof(buf));
if (cod2 & 0x04) g_strlcat(buf, " Rendering,", sizeof(buf));
if (cod2 & 0x02) g_strlcat(buf, " Networking,", sizeof(buf));
if (cod2 & 0x01) g_strlcat(buf, " Positioning,", sizeof(buf));
if (cod1 & 0x20) g_strlcat(buf, " Limited discoverable mode,", sizeof(buf));
buf[strlen(buf)-1] = 0;
g_strlcat(buf, ")", sizeof(buf));
proto_item_append_text(item, "%s", buf);
}
else
{
proto_item_append_text(item, " (%s - no major services)", val_to_str_ext_const(cod1 & 0x1f, &bthci_cmd_major_dev_class_vals_ext, "???"));
}
return offset+3;
}
static int
dissect_bthci_evt_inq_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_conn_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_link_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_encryption_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_conn_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
offset = dissect_bthci_evt_cod(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_link_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_disconn_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_reason, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_auth_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_lmp_features(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 fc_lag;
proto_item *item;
proto_item *ti_lmp_features = NULL;
proto_item *ti_lmp_subtree = NULL;
if(tree){
ti_lmp_features=proto_tree_add_text(tree, tvb, offset, 8, "LMP_Features");
ti_lmp_subtree=proto_item_add_subtree(ti_lmp_features, ett_lmp_subtree);
}
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_00, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_01, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_02, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_03, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_04, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_05, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_06, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_07, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_10, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_11, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_12, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_13, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_14, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_15, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_16, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_17, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_20, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_21, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_22, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_23, tvb, offset, 1, ENC_LITTLE_ENDIAN);
item = proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_24, tvb, offset, 1, ENC_LITTLE_ENDIAN);
fc_lag = (tvb_get_guint8(tvb, offset) & 0x70)>>4;
proto_item_append_text(item, " (%i bytes)", 256*fc_lag);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_27, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_31, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_32, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_33, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_34, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_35, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_36, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_37, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_40, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_41, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_43, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_44, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_47, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_50, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_51, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_52, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_53, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_54, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_55, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_56, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_57, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_60, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_63, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_64, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_65, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_66, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_70, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_71, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_lmp_subtree,hf_bthci_evt_lmp_feature_77, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_pin_code_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_bthci_evt_link_key_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_bthci_evt_link_key_notification(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_link_key, tvb, offset, 16, ENC_NA);
offset+=16;
proto_tree_add_item(tree, hf_bthci_evt_key_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset+=1;
return offset;
}
static int
dissect_bthci_evt_return_link_keys(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 evt_num_keys;
evt_num_keys = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_keys, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
while(evt_num_keys--){
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_link_key, tvb, offset, 16, ENC_NA);
offset+=16;
}
return offset;
}
static int
dissect_bthci_evt_read_remote_support_features_complete(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
offset=dissect_bthci_evt_lmp_features(tvb, offset, pinfo,tree);
return offset;
}
static int
dissect_bthci_evt_remote_name_req_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_remote_name, tvb, offset, 248, ENC_ASCII|ENC_NA);
offset+=248;
return offset;
}
static int
dissect_bthci_evt_read_remote_version_information_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_vers_nr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_comp_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_sub_vers_nr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_flush_occured(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_number_of_completed_packets(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 evt_num_handles;
evt_num_handles = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_handles, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
while(evt_num_handles--){
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_num_compl_packets, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
}
return offset;
}
static int
dissect_bthci_evt_mode_change(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *handle_item;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_curr_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
handle_item = proto_tree_add_item(tree, hf_bthci_evt_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(handle_item, " Baseband slots (%f msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_role_change(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_role, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_hardware_error(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_hardware_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_loopback_command(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset(tvb, offset, tvb_length_remaining(tvb, offset), -1);
if(bthci_com_handle){
call_dissector(bthci_com_handle, next_tvb, pinfo, tree);
}
offset+=tvb_length_remaining(tvb, offset);
return offset;
}
static int
dissect_bthci_evt_data_buffer_overflow(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_link_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_read_clock_offset_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *handle_item;
gint16 clk;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
handle_item = proto_tree_add_item(tree, hf_bthci_evt_clock_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
clk=tvb_get_letohs(tvb, offset) & 32767;
proto_item_append_text(handle_item, " (%g ms)", 1.25*clk);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_max_slots_change(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_max_slots, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_qos_violation(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_conn_packet_type_changed(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint16 flags;
proto_tree *handle_tree=NULL;
proto_item *ti_ptype_subtree=NULL;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
flags=tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
handle_tree = proto_tree_add_text(tree, tvb, offset, 2, "Usable packet types: ");
ti_ptype_subtree = proto_item_add_subtree(handle_tree, ett_ptype_subtree);
if (flags & 0x0008)
proto_item_append_text(handle_tree, "DM1 ");
if (flags & 0x0010)
proto_item_append_text(handle_tree, "DH1 ");
if (flags & 0x0400)
proto_item_append_text(handle_tree, "DM3 ");
if (flags & 0x0800)
proto_item_append_text(handle_tree, "DH3 ");
if (flags & 0x4000)
proto_item_append_text(handle_tree, "DM5 ");
if (flags & 0x8000)
proto_item_append_text(handle_tree, "DH5 ");
if (flags & 0x0020)
proto_item_append_text(handle_tree, "HV1 ");
if (flags & 0x0040)
proto_item_append_text(handle_tree, "HV2 ");
if (flags & 0x0080)
proto_item_append_text(handle_tree, "HV3 ");
if (flags & 0x0002)
proto_item_append_text(handle_tree, "2-DH1 ");
if (flags & 0x0004)
proto_item_append_text(handle_tree, "3-DH1 ");
if (flags & 0x0100)
proto_item_append_text(handle_tree, "2-DH3 ");
if (flags & 0x0200)
proto_item_append_text(handle_tree, "3-DH3 ");
if (flags & 0x1000)
proto_item_append_text(handle_tree, "2-DH5 ");
if (flags & 0x2000)
proto_item_append_text(handle_tree, "3-DH5 ");
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_2dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_3dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dm1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_2dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_3dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dm3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_2dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_3dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dm5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_hv1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_hv2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_hv3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_command_status(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
guint8 status_code;
guint16 opcode;
status_code = tvb_get_guint8(tvb, offset);
if (status_code != 0) {
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
else {
proto_tree_add_item(tree, hf_bthci_evt_status_pending, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset++;
proto_tree_add_item(tree, hf_bthci_evt_num_command_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
opcode = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_com_opcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str_ext(opcode, &bthci_cmd_opcode_vals_ext, "Unknown 0x%08x"));
return offset;
}
static int
dissect_bthci_evt_page_scan_mode_change(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_page_scan_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_page_scan_repetition_mode_change(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_page_scan_repetition_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_inq_result_with_rssi(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 num, evt_num_responses;
evt_num_responses = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_responses, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
for(num=0;num<evt_num_responses;num++){
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_page_scan_repetition_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset++;
offset = dissect_bthci_evt_cod(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_clock_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_rssi, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
}
return offset;
}
static int
dissect_bthci_evt_ext_inquiry_response(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 length, type;
guint i, j;
proto_item *ti_eir = NULL;
proto_item *ti_eir_subtree = NULL;
if(tree){
ti_eir=proto_tree_add_text(tree, tvb, offset, 240, "Extended Inquiry Response Data");
ti_eir_subtree=proto_item_add_subtree(ti_eir, ett_eir_subtree);
}
i=0;
while(i<240){
length = tvb_get_guint8(tvb, offset+i);
if (length != 0) {
proto_item *ti_eir_struct=NULL;
proto_tree *ti_eir_struct_subtree=NULL;
ti_eir_struct = proto_tree_add_text(ti_eir_subtree, tvb, offset+i, length+1, "%s", "");
ti_eir_struct_subtree = proto_item_add_subtree(ti_eir_struct, ett_eir_struct_subtree);
type = tvb_get_guint8(tvb, offset+i+1);
proto_item_append_text(ti_eir_struct,"%s", val_to_str_ext_const(type, &bthci_cmd_eir_data_type_vals_ext, "Unknown"));
proto_tree_add_item(ti_eir_struct_subtree,hf_bthci_evt_eir_struct_length, tvb, offset+i, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_eir_struct_subtree,hf_bthci_evt_eir_struct_type, tvb, offset+i+1, 1, ENC_LITTLE_ENDIAN);
switch(type) {
case 0x02:
case 0x03:
j=0;
while(j<(guint)(length-1))
{
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_evt_sc_uuid16, tvb, offset+i+j+2, 2, ENC_LITTLE_ENDIAN);
j+=2;
}
break;
case 0x04:
case 0x05:
j=0;
while(j<(guint)(length-1))
{
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_evt_sc_uuid32, tvb, offset+i+j+2, 4, ENC_LITTLE_ENDIAN);
j+=4;
}
break;
case 0x06:
case 0x07:
j=0;
while(j<(guint)(length-1))
{
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_evt_sc_uuid128, tvb, offset+i+j+2, 16, ENC_NA);
j+=16;
}
break;
case 0x08:
case 0x09:
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_evt_device_name, tvb, offset+i+2, length-1, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_eir_struct,": %s", tvb_format_text(tvb,offset+i+2,length-1));
break;
case 0x0A:
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_evt_transmit_power_level, tvb, offset+i+2, 1, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_evt_eir_data, tvb, offset+i+2, length-1, ENC_NA);
break;
}
i += length+1;
}
else {
break;
}
}
return offset+240;
}
static int
dissect_bthci_evt_io_capability_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_bthci_evt_io_capability_response(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_io_capability, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_oob_data_present, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_auth_requirements, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_user_confirmation_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_numeric_value, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_bthci_evt_user_passkey_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_bthci_evt_remote_oob_data_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_bthci_evt_simple_pairing_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_bthci_evt_user_passkey_notification(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_passkey, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_bthci_evt_keypress_notification(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_notification_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_remote_host_sup_feat_notification(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_ext_lmp_features, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset+=8;
return offset;
}
static int
dissect_bthci_evt_command_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti_opcode=NULL;
proto_tree *opcode_tree=NULL;
proto_item *item;
gint16 timeout;
guint8 num8, i;
guint16 com_opcode;
guint32 accuracy;
proto_tree_add_item(tree, hf_bthci_evt_num_command_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
com_opcode = tvb_get_letohs(tvb, offset);
ti_opcode = proto_tree_add_item(tree, hf_bthci_evt_com_opcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
opcode_tree = proto_item_add_subtree(ti_opcode, ett_opcode);
proto_tree_add_item(opcode_tree, hf_bthci_evt_ogf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(opcode_tree, hf_bthci_evt_ocf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str_ext(com_opcode, &bthci_cmd_opcode_vals_ext, "Unknown 0x%08x"));
switch(com_opcode) {
case 0x0402:
case 0x0403:
case 0x0404:
case 0x080f:
case 0x0c01:
case 0x0c03:
case 0x0c05:
case 0x0c0a:
case 0x0c0b:
case 0x0c13:
case 0x0c16:
case 0x0c18:
case 0x0c1a:
case 0x0c1c:
case 0x0c1e:
case 0x0c20:
case 0x0c22:
case 0x0c24:
case 0x0c26:
case 0x0c2a:
case 0x0c2c:
case 0x0c2f:
case 0x0c31:
case 0x0c33:
case 0x0c3a:
case 0x0c3c:
case 0x0c3e:
case 0x0c3f:
case 0x0c43:
case 0x0c45:
case 0x0c47:
case 0x0c49:
case 0x0c52:
case 0x0c53:
case 0x0c56:
case 0x0c59:
case 0x0c5b:
case 0x0c60:
case 0x1802:
case 0x1803:
case 0x1804:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0408:
case 0x040b:
case 0x040c:
case 0x040d:
case 0x040e:
case 0x041a:
case 0x042b:
case 0x042c:
case 0x042d:
case 0x042e:
case 0x042f:
case 0x0430:
case 0x0433:
case 0x1009:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
break;
case 0x080d:
case 0x0811:
case 0x0c08:
case 0x0c28:
case 0x0c37:
case 0x0c5f:
case 0x1402:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0c15:
case 0x0c17:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
timeout = tvb_get_letohs(tvb, offset);
item = proto_tree_add_item(tree, hf_bthci_evt_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset+=2;
break;
case 0x0c27:
case 0x0c36:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
timeout = tvb_get_letohs(tvb, offset);
item = proto_tree_add_item(tree, hf_bthci_evt_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset+=2;
break;
case 0x0c1b:
case 0x0c1d:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_window, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0420:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_lmp_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset+=4;
break;
case 0x0809:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_curr_role, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x080c:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_switch, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_hold , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_sniff , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_park , tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x080e:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_switch, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_hold , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_sniff , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_park , tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0c09:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_pin_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c0d:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_max_num_keys, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_num_keys_read, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0c11:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_num_keys_written, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c12:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_num_keys_deleted, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0c14:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_device_name, tvb, offset, 248, ENC_ASCII|ENC_NA);
offset+=248;
break;
case 0x0c19:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_scan_enable, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c1f:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_authentication_enable, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c21:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_encryption_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c23:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset = dissect_bthci_evt_cod(tvb, offset, pinfo, tree);
break;
case 0x0c25:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_input_coding, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_input_data_format, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_input_sample_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0c29:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_num_broadcast_retransm, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c2b:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_hold_mode_act_page, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_hold_mode_act_inquiry, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_hold_mode_act_periodic, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c2d:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_transmit_power_level, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c2e:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_sco_flow_cont_enable, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c38:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_num_supp_iac, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c39:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
num8 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_curr_iac, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
for (i=0; i<num8; i++) {
proto_tree_add_item(tree, hf_bthci_evt_iac_lap, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset+=3;
}
break;
case 0x0c3b:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_page_scan_period_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c3d:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_page_scan_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c42:
case 0x0c46:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_scan_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c44:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_inq_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c48:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_afh_ch_assessment_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c51:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_fec_required, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset=dissect_bthci_evt_ext_inquiry_response(tvb, offset, pinfo, tree);
break;
case 0x0c55:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_simple_pairing_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c57:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_hash_c, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_randomizer_r, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0c58:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_power_level_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0c5a:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_err_data_reporting, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x1001:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_hci_vers_nr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_hci_revision, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_vers_nr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_comp_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_sub_vers_nr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x1002:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_local_supported_cmds, tvb, offset, 64, ENC_NA);
offset+=64;
break;
case 0x1003:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset=dissect_bthci_evt_lmp_features(tvb, offset, pinfo, tree);
break;
case 0x1004:
{
guint8 page_number;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
page_number = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_max_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (page_number == 0) {
offset=dissect_bthci_evt_lmp_features(tvb, offset, pinfo, tree);
}
else {
proto_tree_add_item(tree, hf_bthci_evt_ext_lmp_features, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset+=8;
}
}
break;
case 0x1005:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_host_data_packet_length_acl, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_host_data_packet_length_sco, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_host_total_num_acl_data_packets, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_host_total_num_sco_data_packets, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x1007:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_country_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x1401:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_failed_contact_counter, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x1403:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_link_quality, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x1405:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_rssi, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x1406:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_afh_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_afh_channel_map, tvb, offset, 10, ENC_NA);
offset+=10;
break;
case 0x1407:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_clock, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
accuracy = tvb_get_letohl(tvb, offset);
item = proto_tree_add_item(tree, hf_bthci_evt_clock_accuracy, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " %g msec", accuracy*0.3125);
offset+=2;
break;
case 0x1801:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_loopback_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
default:
proto_tree_add_item(tree, hf_bthci_evt_ret_params, tvb, offset, -1, ENC_NA);
offset+=tvb_length_remaining(tvb, offset);
break;
}
return offset;
}
static int
dissect_bthci_evt_qos_setup_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_service_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_token_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_evt_peak_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_evt_latency, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_evt_delay_variation, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_bthci_evt_change_conn_link_key_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_master_link_key_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_key_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_encryption_change(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_encryption_enable, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_read_remote_ext_features_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 page_number;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
page_number = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_max_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (page_number == 0) {
offset=dissect_bthci_evt_lmp_features(tvb, offset, pinfo, tree);
}
else {
proto_tree_add_item(tree, hf_bthci_evt_ext_lmp_features, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset+=8;
}
return offset;
}
static int
dissect_bthci_evt_sync_connection_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *item;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_sync_link_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
item = proto_tree_add_item(tree, hf_bthci_evt_sync_tx_interval, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_guint8(tvb, offset)*0.625);
offset++;
item = proto_tree_add_item(tree, hf_bthci_evt_sync_rtx_window, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_guint8(tvb, offset)*0.625);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_sync_rx_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_sync_tx_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_air_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static int
dissect_bthci_evt_sync_connection_changed(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *item;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_evt_sync_tx_interval, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_guint8(tvb, offset)*0.625);
offset++;
item = proto_tree_add_item(tree, hf_bthci_evt_sync_rtx_window, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_guint8(tvb, offset)*0.625);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_sync_rx_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_sync_tx_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_sniff_subrating(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *item;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_evt_max_tx_latency, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_evt_max_rx_latency, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_evt_min_remote_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_evt_min_local_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_flow_specification_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_evt_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_flow_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_service_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_token_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_evt_token_bucket_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_evt_peak_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_evt_latency, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_bthci_evt_enhanced_flush_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_encryption_key_refresh_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_link_supervision_timeout_changed(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *item;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_evt_link_supervision_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
return offset;
}
static int
dissect_bthci_evt_inq_result(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 num, evt_num_responses;
evt_num_responses = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_responses, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
for(num=0;num<evt_num_responses;num++){
offset = dissect_bthci_evt_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_page_scan_repetition_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_page_scan_period_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_evt_page_scan_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset = dissect_bthci_evt_cod(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_evt_clock_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
}
return offset;
}
static int
dissect_bthci_evt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *bthci_evt_tree = NULL;
guint8 param_length, evt_code;
int offset = 0;
if(tree){
ti=proto_tree_add_item(tree, proto_bthci_evt, tvb, offset, -1, ENC_NA);
bthci_evt_tree=proto_item_add_subtree(ti, ett_bthci_evt);
}
evt_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(bthci_evt_tree, hf_bthci_evt_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(bthci_evt_tree, " - %s", val_to_str(evt_code, evt_code_vals, "Unknown 0x%08x"));
offset++;
param_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(bthci_evt_tree, hf_bthci_evt_param_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI_EVT");
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str(evt_code, evt_code_vals, "Unknown 0x%08x"));
if (param_length > 0) {
switch(evt_code) {
case 0x01:
offset=dissect_bthci_evt_inq_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x02:
offset=dissect_bthci_evt_inq_result(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x03:
offset=dissect_bthci_evt_conn_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x04:
offset=dissect_bthci_evt_conn_request(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x05:
offset=dissect_bthci_evt_disconn_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x06:
offset=dissect_bthci_evt_auth_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x07:
offset=dissect_bthci_evt_remote_name_req_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x08:
offset=dissect_bthci_evt_encryption_change(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x09:
offset=dissect_bthci_evt_change_conn_link_key_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x0a:
offset=dissect_bthci_evt_master_link_key_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x0b:
offset=dissect_bthci_evt_read_remote_support_features_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x0c:
offset=dissect_bthci_evt_read_remote_version_information_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x0d:
offset=dissect_bthci_evt_qos_setup_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x0e:
offset=dissect_bthci_evt_command_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x0f:
offset=dissect_bthci_evt_command_status(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x10:
offset=dissect_bthci_evt_hardware_error(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x11:
offset=dissect_bthci_evt_flush_occured(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x12:
offset=dissect_bthci_evt_role_change(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x13:
offset=dissect_bthci_evt_number_of_completed_packets(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x14:
offset=dissect_bthci_evt_mode_change(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x15:
offset=dissect_bthci_evt_return_link_keys(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x16:
offset=dissect_bthci_evt_pin_code_request(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x17:
offset=dissect_bthci_evt_link_key_request(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x18:
offset=dissect_bthci_evt_link_key_notification(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x19:
offset=dissect_bthci_evt_loopback_command(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x1a:
offset=dissect_bthci_evt_data_buffer_overflow(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x1b:
offset=dissect_bthci_evt_max_slots_change(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x1c:
offset=dissect_bthci_evt_read_clock_offset_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x1d:
offset=dissect_bthci_evt_conn_packet_type_changed(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x1e:
offset=dissect_bthci_evt_qos_violation(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x1f:
offset=dissect_bthci_evt_page_scan_mode_change(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x20:
offset=dissect_bthci_evt_page_scan_repetition_mode_change(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x21:
offset=dissect_bthci_evt_flow_specification_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x22:
offset=dissect_bthci_evt_inq_result_with_rssi(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x23:
offset=dissect_bthci_evt_read_remote_ext_features_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x2c:
offset=dissect_bthci_evt_sync_connection_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x2d:
offset=dissect_bthci_evt_sync_connection_changed(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x2e:
offset=dissect_bthci_evt_sniff_subrating(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x2f:
offset=dissect_bthci_evt_inq_result_with_rssi(tvb, offset, pinfo, bthci_evt_tree);
offset=dissect_bthci_evt_ext_inquiry_response(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x30:
offset=dissect_bthci_evt_encryption_key_refresh_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x31:
offset=dissect_bthci_evt_io_capability_request(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x32:
offset=dissect_bthci_evt_io_capability_response(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x33:
offset=dissect_bthci_evt_user_confirmation_request(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x34:
offset=dissect_bthci_evt_user_passkey_request(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x35:
offset=dissect_bthci_evt_remote_oob_data_request(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x36:
offset=dissect_bthci_evt_simple_pairing_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x38:
offset=dissect_bthci_evt_link_supervision_timeout_changed(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x39:
offset=dissect_bthci_evt_enhanced_flush_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x3b:
offset=dissect_bthci_evt_user_passkey_notification(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x3c:
offset=dissect_bthci_evt_keypress_notification(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x3d:
offset=dissect_bthci_evt_remote_host_sup_feat_notification(tvb, offset, pinfo, bthci_evt_tree);
break;
default:
proto_tree_add_item(bthci_evt_tree, hf_bthci_evt_params, tvb, 2, -1, ENC_NA);
offset+=tvb_length_remaining(tvb, offset);
break;
}
}
return offset;
}
void
proto_register_bthci_evt(void)
{
static hf_register_info hf[] = {
{ &hf_bthci_evt_code,
{ "Event Code", "bthci_evt.code",
FT_UINT8, BASE_HEX, VALS(evt_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_param_length,
{ "Parameter Total Length", "bthci_evt.param_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_params,
{ "Event Parameter", "bthci_evt.params",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_command_packets,
{ "Number of Allowed Command Packets", "bthci_evt.num_command_packets",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_handles,
{ "Number of Connection Handles", "bthci_evt.num_handles",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Connection Handles and Num_HCI_Data_Packets parameter pairs", HFILL }
},
{ &hf_bthci_evt_connection_handle,
{ "Connection Handle", "bthci_evt.connection_handle",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_compl_packets,
{ "Number of Completed Packets", "bthci_evt.num_compl_packets",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The number of HCI Data Packets that have been completed", HFILL }
},
{ &hf_bthci_evt_com_opcode,
{ "Command Opcode", "bthci_evt.com_opcode",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_opcode_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_ogf,
{ "ogf", "bthci_evt.ogf",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &bthci_ogf_vals_ext, 0xfc00,
"Opcode Group Field", HFILL }
},
{ &hf_bthci_evt_ocf,
{ "ocf", "bthci_evt.ocf",
FT_UINT16, BASE_HEX, NULL, 0x03ff,
"Opcode Command Field", HFILL }
},
{ &hf_bthci_evt_ret_params,
{ "Return Parameter", "bthci_evt.ret_params",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_status,
{ "Status", "bthci_evt.status",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_status_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_status_pending,
{ "Status", "bthci_evt.status",
FT_UINT8, BASE_HEX, VALS(bthci_cmd_status_pending_vals), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_bd_addr,
{ "BD_ADDR:", "bthci_evt.bd_addr",
FT_NONE, BASE_NONE, NULL, 0x0,
"Bluetooth Device Address", HFILL}
},
{ &hf_bthci_evt_class_of_device,
{ "Class of Device", "bthci_evt.class_of_device",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type,
{ "Link Type", "bthci_evt.link_type",
FT_UINT8, BASE_HEX, VALS(evt_link_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_encryption_mode,
{ "Encryption Mode", "bthci_evt.encryption_mode",
FT_UINT8, BASE_HEX, VALS(evt_encryption_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_reason,
{ "Reason", "bthci_evt.reason",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_status_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_remote_name,
{ "Remote Name", "bthci_evt.remote_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Userfriendly descriptive name for the remote device", HFILL }
},
{ &hf_bthci_evt_encryption_enable,
{ "Encryption Enable", "bthci_evt.encryption_enable",
FT_UINT8, BASE_HEX, VALS(evt_encryption_enable), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_key_flag,
{ "Key Flag", "bthci_evt.key_flag",
FT_UINT8, BASE_HEX, VALS(evt_key_flag), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_vers_nr,
{ "LMP Version", "bthci_evt.lmp_vers_nr",
FT_UINT8, BASE_HEX, VALS(evt_lmp_vers_nr), 0x0,
"Version of the Current LMP", HFILL }
},
{ &hf_bthci_evt_hci_vers_nr,
{ "HCI Version", "bthci_evt.hci_vers_nr",
FT_UINT8, BASE_HEX, VALS(evt_hci_vers_nr), 0x0,
"Version of the Current HCI", HFILL }
},
{ &hf_bthci_evt_hci_revision,
{ "HCI Revision", "bthci_evt.hci_vers_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Revision of the Current HCI", HFILL }
},
{ &hf_bthci_evt_comp_id,
{ "Manufacturer Name", "bthci_evt.comp_id",
FT_UINT16, BASE_HEX, VALS(evt_comp_id), 0x0,
"Manufacturer Name of Bluetooth Hardware", HFILL }
},
{ &hf_bthci_evt_sub_vers_nr,
{ "LMP Subversion", "bthci_evt.lmp_sub_vers_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Subversion of the Current LMP", HFILL }
},
{ &hf_bthci_evt_flags,
{ "Flags", "bthci_evt.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_service_type,
{ "Service Type", "bthci_evt.service_type",
FT_UINT8, BASE_HEX, VALS(evt_service_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_token_rate,
{ "Available Token Rate", "bthci_evt.token_rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Available Token Rate, in bytes per second", HFILL }
},
{ &hf_bthci_evt_peak_bandwidth,
{ "Available Peak Bandwidth", "bthci_evt.peak_bandwidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Available Peak Bandwidth, in bytes per second", HFILL }
},
{ &hf_bthci_evt_latency,
{ "Available Latency", "bthci_evt.latency",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Available Latency, in microseconds", HFILL }
},
{ &hf_bthci_evt_delay_variation,
{ "Available Delay Variation", "bthci_evt.delay_variation",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Available Delay Variation, in microseconds", HFILL }
},
{ &hf_bthci_evt_hardware_code,
{ "Hardware Code", "bthci_evt.hardware_code",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Hardware Code (implementation specific)", HFILL }
},
{ &hf_bthci_evt_role,
{ "Role", "bthci_evt.role",
FT_UINT8, BASE_HEX, VALS(evt_role_vals), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_curr_mode,
{ "Current Mode", "bthci_evt.current_mode",
FT_UINT8, BASE_HEX, VALS(evt_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_interval,
{ "Interval", "bthci_evt.interval",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Interval - Number of Baseband slots", HFILL }
},
{ &hf_bthci_evt_link_key,
{ "Link Key", "bthci_evt.link_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Link Key for the associated BD_ADDR", HFILL }
},
{ &hf_bthci_evt_key_type,
{ "Key Type", "bthci_evt.key_type",
FT_UINT8, BASE_HEX, VALS(evt_key_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_max_slots,
{ "Maximum Number of Slots", "bthci_evt.max_slots",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Maximum Number of slots allowed for baseband packets", HFILL }
},
{ &hf_bthci_evt_clock_offset,
{ "Clock Offset", "bthci_evt.clock_offset",
FT_UINT16, BASE_HEX, NULL, 0x7FFF,
"Bit 2-16 of the Clock Offset between CLKmaster-CLKslave", HFILL }
},
{ &hf_bthci_evt_page_scan_mode,
{ "Page Scan Mode", "bthci_evt.page_scan_mode",
FT_UINT8, BASE_HEX, VALS(evt_page_scan_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_page_scan_repetition_mode,
{ "Page Scan Repetition Mode", "bthci_evt.page_scan_repetition_mode",
FT_UINT8, BASE_HEX, VALS(evt_page_scan_repetition_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_page_scan_period_mode,
{ "Page Scan Period Mode", "bthci_evt.page_scan_period_mode",
FT_UINT8, BASE_HEX, VALS(evt_page_scan_period_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_2dh1,
{ "ACL Link Type 2-DH1", "bthci_evt.link_type_2dh1",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0002,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_3dh1,
{ "ACL Link Type 3-DH1", "bthci_evt.link_type_3dh1",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0004,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dm1,
{ "ACL Link Type DM1", "bthci_evt.link_type_dm1",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0008,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dh1,
{ "ACL Link Type DH1", "bthci_evt.link_type_dh1",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0010,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_2dh3,
{ "ACL Link Type 2-DH3", "bthci_evt.link_type_2dh3",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0100,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_3dh3,
{ "ACL Link Type 3-DH3", "bthci_evt.link_type_3dh3",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0200,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dm3,
{ "ACL Link Type DM3", "bthci_evt.link_type_dm3",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0400,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dh3,
{ "ACL Link Type DH3", "bthci_evt.link_type_dh3",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0800,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_2dh5,
{ "ACL Link Type 2-DH5", "bthci_evt.link_type_2dh5",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x1000,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_3dh5,
{ "ACL Link Type 3-DH5", "bthci_evt.link_type_3dh5",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x2000,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dm5,
{ "ACL Link Type DM5", "bthci_evt.link_type_dm5",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x4000,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dh5,
{ "ACL Link Type DH5", "bthci_evt.link_type_dh5",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x8000,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_hv1,
{ "SCO Link Type HV1", "bthci_evt.link_type_hv1",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0020,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_hv2,
{ "SCO Link Type HV2", "bthci_evt.link_type_hv2",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0040,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_hv3,
{ "SCO Link Type HV3", "bthci_evt.link_type_hv3",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0080,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_00,
{ "3-slot packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_01,
{ "5-slot packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_02,
{ "encryption", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x04,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_03,
{ "slot offset", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_04,
{ "timing accuracy", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x10,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_05,
{ "master/slave switch", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x20,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_06,
{ "hold mode", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x40,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_07,
{ "sniff mode", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_10,
{ "park mode", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_11,
{ "RSSI", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_12,
{ "channel quality driven data rate", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x04,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_13,
{ "SCO link", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_14,
{ "HV2 packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x10,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_15,
{ "HV3 packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x20,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_16,
{ "u-law log", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x40,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_17,
{ "A-law log", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_20,
{ "CVSD", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_21,
{ "paging scheme", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_22,
{ "power control", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x04,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_23,
{ "transparent SCO data", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_24,
{ "Flow control lag", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_27,
{ "broadband encryption", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_31,
{ "EDR ACL 2 Mbps mode", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_32,
{ "EDR ACL 3 Mbps mode", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x04,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_33,
{ "enhanced inquiry scan", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_34,
{ "interlaced inquiry scan", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x10,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_35,
{ "interlaced page scan", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x20,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_36,
{ "RSSI with inquiry results", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x40,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_37,
{ "eSCO EV3 packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_40,
{ "eSCO EV4 packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_41,
{ "eSCO EV5 packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_43,
{ "AFH capable slave", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_44,
{ "AFH classification slave", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x10,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_47,
{ "3-slot EDR ACL packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_50,
{ "5-slot EDR ACL packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_51,
{ "sniff subrating", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_52,
{ "pause encryption", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x04,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_53,
{ "AFH capable master", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_54,
{ "AFH classification master", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x10,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_55,
{ "EDR eSCO 2 Mbps mode", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x20,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_56,
{ "EDR eSCO 3 Mbps mode", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x40,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_57,
{ "3-slot EDR eSCO packets", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_60,
{ "extended inquiry response", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_63,
{ "secure simple pairing", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_64,
{ "encapsulated PDU", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x10,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_65,
{ "erroneous data reporting", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x20,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_66,
{ "non-flushable packet boundary flag", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x40,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_70,
{ "link supervision timeout changed event", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_71,
{ "inquiry response TX power level", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_lmp_feature_77,
{ "extended features", "bthci_evt.lmp_feature",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_num_keys,
{ "Number of Link Keys", "bthci_evt.num_keys",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Link Keys contained", HFILL }
},
{ &hf_bthci_evt_num_keys_read,
{ "Number of Link Keys Read", "bthci_evt.num_keys_read",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_keys_deleted,
{ "Number of Link Keys Deleted", "bthci_evt.num_keys_deleted",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_keys_written,
{ "Number of Link Keys Written", "bthci_evt.num_keys_written",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_max_num_keys,
{ "Max Num Keys", "bthci_evt.max_num_keys",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total Number of Link Keys that the Host Controller can store", HFILL }
},
{ &hf_bthci_evt_num_responses,
{ "Number of responses", "bthci_evt.num_responses",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Responses from Inquiry", HFILL }
},
{ &hf_bthci_evt_link_policy_setting_switch,
{ "Enable Master Slave Switch", "bthci_evt.link_policy_switch",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0001,
NULL, HFILL }
},
{ &hf_bthci_evt_link_policy_setting_hold,
{ "Enable Hold Mode", "bthci_evt.link_policy_hold",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0002,
NULL, HFILL }
},
{ &hf_bthci_evt_link_policy_setting_sniff,
{ "Enable Sniff Mode", "bthci_evt.link_policy_sniff",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0004,
NULL, HFILL }
},
{ &hf_bthci_evt_link_policy_setting_park,
{ "Enable Park Mode", "bthci_evt.link_policy_park",
FT_UINT16, BASE_DEC, VALS(evt_boolean), 0x0008,
NULL, HFILL }
},
{ &hf_bthci_evt_curr_role,
{ "Current Role", "bthci_evt.curr_role",
FT_UINT8, BASE_HEX, VALS(evt_role_vals_handle), 0x0,
"Current role for this connection handle", HFILL }
},
{ &hf_bthci_evt_pin_type,
{ "PIN Type", "bthci_evt.pin_type",
FT_UINT8, BASE_HEX, VALS(evt_pin_types), 0x0,
"PIN Types", HFILL }
},
{ &hf_bthci_evt_device_name,
{ "Device Name", "bthci_evt.device_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Userfriendly descriptive name for the device", HFILL }
},
{ &hf_bthci_evt_timeout,
{ "Timeout", "bthci_evt.timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of Baseband slots for timeout.", HFILL }
},
{ &hf_bthci_evt_scan_enable,
{ "Scan", "bthci_evt.scan_enable",
FT_UINT8, BASE_HEX, VALS(evt_scan_enable_values), 0x0,
"Scan Enable", HFILL }
},
{ &hf_bthci_evt_authentication_enable,
{ "Authentication", "bthci_evt.auth_enable",
FT_UINT8, BASE_HEX, VALS(evt_auth_enable_values), 0x0,
"Authentication Enable", HFILL }
},
{ &hf_bthci_evt_sco_flow_cont_enable,
{ "SCO Flow Control", "bthci_evt.sco_flow_cont_enable",
FT_UINT8, BASE_HEX, VALS(evt_enable_values), 0x0,
"SCO Flow Control Enable", HFILL }
},
{ &hf_bthci_evt_window,
{ "Interval", "bthci_evt.window",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Window", HFILL }
},
{ &hf_bthci_evt_input_coding,
{ "Input Coding", "bthci_evt.input_coding",
FT_UINT16, BASE_DEC, VALS(evt_input_coding_values), 0x0300,
"Authentication Enable", HFILL }
},
{ &hf_bthci_evt_input_data_format,
{ "Input Data Format", "bthci_evt.input_data_format",
FT_UINT16, BASE_DEC, VALS(evt_input_data_format_values), 0x00c0,
NULL, HFILL }
},
{ &hf_bthci_evt_input_sample_size,
{ "Input Sample Size", "bthci_evt.input_sample_size",
FT_UINT16, BASE_DEC, VALS(evt_input_sample_size_values), 0x0020,
NULL, HFILL }
},
{ &hf_bthci_evt_num_broadcast_retransm,
{ "Num Broadcast Retran", "bthci_evt.num_broad_retran",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Broadcast Retransmissions", HFILL }
},
{ &hf_bthci_evt_hold_mode_act_page,
{ "Suspend Page Scan", "bthci_evt.hold_mode_page",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x1,
"Device can enter low power state", HFILL }
},
{ &hf_bthci_evt_hold_mode_act_inquiry,
{ "Suspend Inquiry Scan", "bthci_evt.hold_mode_inquiry",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x2,
"Device can enter low power state", HFILL }
},
{ &hf_bthci_evt_hold_mode_act_periodic,
{ "Suspend Periodic Inquiries", "bthci_evt.hold_mode_periodic",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x4,
"Device can enter low power state", HFILL }
},
{ &hf_bthci_evt_transmit_power_level,
{ "Transmit Power Level (dBm)", "bthci_evt.transmit_power_level",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_supp_iac,
{"Num Support IAC", "bthci_evt.num_supp_iac",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Num of supported IAC the device can simultaneously listen", HFILL }
},
{ &hf_bthci_evt_num_curr_iac,
{"Num Current IAC", "bthci_evt.num_curr_iac",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Num of IACs currently in use to simultaneously listen", HFILL }
},
{ &hf_bthci_evt_iac_lap,
{ "IAC LAP", "bthci_evt.num_curr_iac",
FT_UINT24, BASE_HEX, NULL, 0x0,
"LAP(s)used to create IAC", HFILL }
},
{ &hf_bthci_evt_loopback_mode,
{"Loopback Mode", "bthci_evt.loopback_mode",
FT_UINT8, BASE_HEX, VALS(evt_loopback_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_country_code,
{"Country Code", "bthci_evt.country_code",
FT_UINT8, BASE_HEX, VALS(evt_country_code_values), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_failed_contact_counter,
{"Failed Contact Counter", "bthci_evt.failed_contact_counter",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_link_quality,
{"Link Quality", "bthci_evt.link_quality",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Link Quality (0x00 - 0xFF Higher Value = Better Link)", HFILL }
},
{ &hf_bthci_evt_rssi,
{ "RSSI (dB)", "bthci_evt.rssi",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_host_data_packet_length_acl,
{"Host ACL Data Packet Length (bytes)", "bthci_evt.max_data_length_acl",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Max Host ACL Data Packet length of data portion host is able to accept", HFILL }
},
{ &hf_bthci_evt_host_data_packet_length_sco,
{"Host SCO Data Packet Length (bytes)", "bthci_evt.max_data_length_sco",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Max Host SCO Data Packet length of data portion host is able to accept", HFILL }
},
{ &hf_bthci_evt_host_total_num_acl_data_packets,
{"Host Total Num ACL Data Packets", "bthci_evt.max_data_num_acl",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total Number of HCI ACL Data Packets that can be stored in the data buffers of the Host", HFILL }
},
{ &hf_bthci_evt_host_total_num_sco_data_packets,
{"Host Total Num SCO Data Packets", "bthci_evt.max_data_num_sco",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total Number of HCI SCO Data Packets that can be stored in the data buffers of the Host", HFILL }
},
{ &hf_bthci_evt_page_number,
{"Page Number", "bthci_evt.page_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_max_page_number,
{"Max. Page Number", "bthci_evt.max_page_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_local_supported_cmds,
{ "Local Supported Commands", "bthci_evt.local_supported_cmds",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_fec_required,
{"FEC Required", "bthci_evt.fec_required",
FT_UINT8, BASE_DEC, VALS(evt_boolean), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_err_data_reporting,
{"Erroneous Data Reporting", "bthci_evt.err_data_reporting",
FT_UINT8, BASE_DEC, VALS(evt_enable_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_scan_type,
{"Scan Type", "bthci_evt.inq_scan_type",
FT_UINT8, BASE_DEC, VALS(evt_scan_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_inq_mode,
{"Inquiry Mode", "bthci_evt.inq_scan_type",
FT_UINT8, BASE_DEC, VALS(evt_inq_modes), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_power_level_type,
{"Type", "bthci_evt.power_level_type",
FT_UINT8, BASE_HEX, VALS(evt_power_level_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_ext_lmp_features,
{"Ext. LMP Features", "bthci_evt.page_number",
FT_UINT64, BASE_HEX, NULL, 0x0,
"Extended LMP Features", HFILL}
},
{ &hf_bthci_evt_sync_link_type,
{"Link Type", "bthci_evt.sync_link_type",
FT_UINT8, BASE_HEX, VALS(evt_sync_link_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_sync_tx_interval,
{"Transmit Interval", "bthci_evt.sync_tx_interval",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_sync_rtx_window,
{"Retransmit Window", "bthci_evt.sync_rtx_window",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_sync_rx_packet_length,
{"Rx Packet Length", "bthci_evt.sync_rx_pkt_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_sync_tx_packet_length,
{"Tx Packet Length", "bthci_evt.sync_tx_pkt_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_air_mode,
{"Air Mode", "bthci_evt.air_mode",
FT_UINT8, BASE_DEC, VALS(evt_air_mode_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_max_tx_latency,
{"Max. Tx Latency", "bthci_evt.max_tx_latency",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_max_rx_latency,
{"Max. Rx Latency", "bthci_evt.max_rx_latency",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_min_remote_timeout,
{"Min. Remote Timeout", "bthci_evt.min_remote_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_min_local_timeout,
{"Min. Local Timeout", "bthci_evt.min_local_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_link_supervision_timeout,
{"Link Supervision Timeout", "bthci_evt.link_supervision_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_token_bucket_size,
{ "Token Bucket Size", "bthci_evt.token_bucket_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Token Bucket Size (bytes)", HFILL }
},
{ &hf_bthci_evt_flow_direction,
{"Flow Direction", "bthci_evt.flow_direction",
FT_UINT8, BASE_DEC, VALS(evt_flow_direction_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_afh_ch_assessment_mode,
{"AFH Channel Assessment Mode", "bthci_evt.afh_ch_assessment_mode",
FT_UINT8, BASE_DEC, VALS(evt_enable_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_lmp_handle,
{ "LMP Handle", "bthci_evt.lmp_handle",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_clock,
{ "Clock", "bthci_evt.clock",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_clock_accuracy,
{ "Clock", "bthci_evt.clock_accuracy",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_afh_mode,
{"AFH Mode", "bthci_evt.afh_mode",
FT_UINT8, BASE_DEC, VALS(evt_enable_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_afh_channel_map,
{"AFH Channel Map", "bthci_evt.afh_channel_map",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_simple_pairing_mode,
{"Simple Pairing Mode", "bthci_evt.simple_pairing_mode",
FT_UINT8, BASE_DEC, VALS(evt_enable_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_hash_c,
{"Hash C", "bthci_evt.hash_c",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_randomizer_r,
{"Randomizer R", "bthci_evt.randomizer_r",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_io_capability,
{"IO Capability", "bthci_evt.io_capability",
FT_UINT8, BASE_HEX, VALS(bthci_cmd_io_capability_vals), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_oob_data_present,
{"OOB Data Present", "bthci_evt.oob_data_present",
FT_UINT8, BASE_DEC, VALS(bthci_cmd_oob_data_present_vals), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_auth_requirements,
{"Authentication Requirements", "bthci_evt.auth_requirements",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &bthci_cmd_auth_req_vals_ext, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_numeric_value,
{"Numeric Value", "bthci_evt.numeric_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_passkey,
{"Passkey", "bthci_evt.passkey",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_notification_type,
{"Notification Type", "bthci_evt.notification_type",
FT_UINT8, BASE_DEC, VALS(evt_notification_type_vals), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_eir_data,
{"Data", "bthci_evt.eir_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"EIR Data", HFILL}
},
{ &hf_bthci_evt_eir_struct_length,
{ "Length", "bthci_evt.eir_struct_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Structure Length", HFILL }
},
{ &hf_bthci_evt_eir_struct_type,
{ "Type", "bthci_evt.eir_data_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_eir_data_type_vals_ext, 0x0,
"Data Type", HFILL }
},
{ &hf_bthci_evt_sc_uuid16,
{ "UUID", "bthci_evt.service_class_uuid16",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_service_class_type_vals_ext, 0x0,
"16-bit Service Class UUID", HFILL }
},
{ &hf_bthci_evt_sc_uuid32,
{ "UUID", "bthci_evt.service_class_uuid32",
FT_UINT32, BASE_HEX, NULL, 0x0,
"32-bit Service Class UUID", HFILL }
},
{ &hf_bthci_evt_sc_uuid128,
{ "UUID", "bthci_evt.service_class_uuid128",
FT_BYTES, BASE_NONE, NULL, 0x0,
"128-bit Service Class UUID", HFILL }
}
};
static gint *ett[] = {
&ett_bthci_evt,
&ett_opcode,
&ett_lmp_subtree,
&ett_ptype_subtree,
&ett_eir_subtree,
&ett_eir_struct_subtree
};
proto_bthci_evt = proto_register_protocol("Bluetooth HCI Event",
"HCI_EVT", "bthci_evt");
new_register_dissector("bthci_evt", dissect_bthci_evt, proto_bthci_evt);
proto_register_field_array(proto_bthci_evt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bthci_evt(void)
{
dissector_handle_t bthci_evt_handle;
bthci_evt_handle = find_dissector("bthci_evt");
dissector_add_uint("hci_h4.type", HCI_H4_TYPE_EVT, bthci_evt_handle);
dissector_add_uint("hci_h1.type", BTHCI_CHANNEL_EVENT, bthci_evt_handle);
bthci_com_handle = find_dissector("bthci_cmd");
}
