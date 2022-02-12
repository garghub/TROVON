static int
dissect_bthci_cmd_bd_addr(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 i, bd_addr[6];
proto_item *item;
for(i=6; i; i--)
bd_addr[6-i] = tvb_get_guint8(tvb, offset+i-1);
item = proto_tree_add_item(tree, hf_bthci_cmd_bd_addr, tvb, offset, 6, ENC_NA);
proto_item_append_text(item, "%02x%02x:%02x:%02x%02x%02x (%s)",
bd_addr[0], bd_addr[1], bd_addr[2], bd_addr[3], bd_addr[4], bd_addr[5],
get_ether_name(bd_addr));
offset+=6;
return offset;
}
static int
dissect_bthci_cmd_cod(int type, tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cod1, cod2;
proto_item *item;
item = proto_tree_add_item(tree, type, tvb, offset, 3, ENC_LITTLE_ENDIAN);
cod1 = tvb_get_guint8(tvb, offset+1);
cod2 = tvb_get_guint8(tvb, offset+2);
if ((cod2 != 0) || (cod1 & 0x20))
{
char buf[128];
buf[0] = '\0';
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
buf[strlen(buf)-1] = '\0';
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
dissect_bthci_ext_inquiry_response(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 i, j, length, type;
proto_item *ti_eir = NULL;
proto_tree *ti_eir_subtree = NULL;
if (tree) {
ti_eir=proto_tree_add_text(tree, tvb, offset, 240, "Extended Inquiry Response Data");
ti_eir_subtree=proto_item_add_subtree(ti_eir, ett_eir_subtree);
}
i=0;
while(i<240) {
length = tvb_get_guint8(tvb, offset+i);
if (length != 0) {
proto_item *ti_eir_struct=NULL;
proto_tree *ti_eir_struct_subtree=NULL;
ti_eir_struct = proto_tree_add_text(ti_eir_subtree, tvb, offset+i, length+1, "%s", "");
ti_eir_struct_subtree = proto_item_add_subtree(ti_eir_struct, ett_eir_struct_subtree);
type = tvb_get_guint8(tvb, offset+i+1);
proto_item_append_text(ti_eir_struct,"%s", val_to_str_ext_const(type, &bthci_cmd_eir_data_type_vals_ext, "Unknown"));
proto_tree_add_item(ti_eir_struct_subtree,hf_bthci_cmd_eir_struct_length, tvb, offset+i, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_eir_struct_subtree,hf_bthci_cmd_eir_struct_type, tvb, offset+i+1, 1, ENC_LITTLE_ENDIAN);
switch (type) {
case 0x02:
case 0x03:
j=0;
while(j<(length-1))
{
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_cmd_sc_uuid16, tvb, offset+i+j+2, 2, ENC_LITTLE_ENDIAN);
j+=2;
}
break;
case 0x04:
case 0x05:
j=0;
while(j<(length-1))
{
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_cmd_sc_uuid32, tvb, offset+i+j+2, 4, ENC_LITTLE_ENDIAN);
j+=4;
}
break;
case 0x06:
case 0x07:
j=0;
while(j<(length-1))
{
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_cmd_sc_uuid128, tvb, offset+i+j+2, 16, ENC_NA);
j+=16;
}
break;
case 0x08:
case 0x09:
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_cmd_device_name, tvb, offset+i+2, length-1, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_eir_struct,": %s", tvb_format_text(tvb,offset+i+2,length-1));
break;
case 0x0A:
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_cmd_tx_power, tvb, offset+i+2, 1, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(ti_eir_struct_subtree, hf_bthci_cmd_eir_data, tvb, offset+i+2, length-1, ENC_NA);
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
dissect_link_control_cmd(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, guint16 cmd_ocf)
{
proto_item *item;
guint32 clock_value;
switch (cmd_ocf) {
case 0x0001:
proto_tree_add_item(tree, hf_bthci_cmd_lap, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset+=3;
proto_tree_add_item(tree, hf_bthci_cmd_inq_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_num_responses, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0002:
break;
case 0x0003:
proto_tree_add_item(tree, hf_bthci_cmd_max_period_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_min_period_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_lap, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset+=3;
proto_tree_add_item(tree, hf_bthci_cmd_inq_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_num_responses, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0004:
break;
case 0x0005:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_2dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_3dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dm1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_2dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_3dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dm3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_2dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_3dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dm5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_page_scan_repetition_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_page_scan_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
item = proto_tree_add_item(tree, hf_bthci_cmd_clock_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
clock_value = tvb_get_letohs(tvb, 13) & 32767;
proto_item_append_text(item, " (%g ms)", 1.25*clock_value);
proto_tree_add_item(tree, hf_bthci_cmd_clock_offset_valid , tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_allow_role_switch, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0006:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_reason, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0007:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_hv1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_hv2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_hv3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0008:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
break;
case 0x0009:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_role, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x000a:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_reason, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x000b:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_link_key, tvb, offset, 16, ENC_NA);
offset+=16;
break;
case 0x000c:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
break;
case 0x000d:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_pin_code_length ,tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_pin_code ,tvb, offset, 16, ENC_ASCII|ENC_NA);
offset+=16;
break;
case 0x000e:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
break;
case 0x000f:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_2dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_3dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dm1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_2dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_3dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dm3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_2dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_3dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dm5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_packet_type_dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0011:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0013:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_encryption_enable, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0017:
proto_tree_add_item(tree, hf_bthci_cmd_key_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0019:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_page_scan_repetition_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_page_scan_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
item = proto_tree_add_item(tree, hf_bthci_cmd_clock_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
clock_value = tvb_get_letohs(tvb, offset) & 32767;
proto_item_append_text(item, " (%g ms)", 1.25*clock_value);
proto_tree_add_item(tree, hf_bthci_cmd_clock_offset_valid , tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x001a:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
break;
case 0x001c:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0028:
case 0x0029:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_transmit_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_cmd_receive_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_cmd_max_latency_ms, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_input_coding, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_input_data_format, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_input_sample_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_linear_pcm_bit_pos, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_air_coding_format, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_retransmission_effort, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_hv1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_hv2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_hv3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_ev3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_ev4, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_ev5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_2ev3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_3ev3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_2ev5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_sco_packet_type_3ev5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x002a:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_reason, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0015:
case 0x001b:
case 0x001d:
case 0x001f:
case 0x0020:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x002b:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_io_capability, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_oob_data_present, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_auth_requirements, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x002c:
case 0x002d:
case 0x002f:
case 0x0033:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
break;
case 0x002e:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_passkey, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
break;
case 0x0030:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_hash_c, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_randomizer_r, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
default:
proto_tree_add_item(tree, hf_bthci_cmd_params, tvb, offset, -1, ENC_NA);
offset+=tvb_length_remaining(tvb, offset);
break;
}
return offset;
}
static int
dissect_link_policy_cmd(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, guint16 cmd_ocf)
{
proto_item *item;
guint16 timeout;
switch (cmd_ocf) {
case 0x0001:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_max_interval_hold, tvb, offset, 2, ENC_LITTLE_ENDIAN);
timeout = tvb_get_letohs(tvb, offset);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_min_interval_hold, tvb, offset, 2, ENC_LITTLE_ENDIAN);
timeout = tvb_get_letohs(tvb, offset);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset+=2;
break;
case 0x0003:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_max_interval_sniff, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_min_interval_sniff, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_sniff_attempt, tvb, offset, 2, ENC_LITTLE_ENDIAN);
timeout = tvb_get_letohs(tvb, offset);
if (timeout>0) {
proto_item_append_text(item, " (%g msec)", (2*timeout-1)*0.625);
} else {
proto_item_append_text(item, " (0 msec)");
}
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*1.25);
offset+=2;
break;
case 0x0005:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_max_interval_beacon, tvb, offset, 2, ENC_LITTLE_ENDIAN);
timeout = tvb_get_letohs(tvb, offset);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_min_interval_beacon, tvb, offset, 2, ENC_LITTLE_ENDIAN);
timeout = tvb_get_letohs(tvb, offset);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset+=2;
break;
case 0x0007:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_service_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_token_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_cmd_peak_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_cmd_latency, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_cmd_delay_variation, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
break;
case 0x000b:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_role, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0004:
case 0x0006:
case 0x0009:
case 0x000c:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x000d:
case 0x000f:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_link_policy_setting_switch, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_link_policy_setting_hold , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_link_policy_setting_sniff , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_link_policy_setting_park , tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0010:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_service_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_token_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_cmd_token_bucket_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_cmd_peak_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_bthci_cmd_latency, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
break;
case 0x0011:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_max_latency, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_min_remote_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_min_local_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
break;
default:
proto_tree_add_item(tree, hf_bthci_cmd_params, tvb, offset, -1, ENC_NA);
offset+=tvb_length_remaining(tvb, offset);
break;
}
return offset;
}
static int
dissect_host_controller_baseband_cmd(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint16 cmd_ocf)
{
proto_item *item;
guint16 timeout;
guint8 filter_type, filter_condition_type, num8;
int i;
switch (cmd_ocf) {
case 0x0001:
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_00, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_01, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_02, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_03, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_04, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_05, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_06, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_07, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_10, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_11, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_12, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_13, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_14, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_17, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_20, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_21, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_23, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_24, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_25, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_26, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_27, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_30, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_31, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_32, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_33, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_34, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_35, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_36, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_37, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_40, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_41, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_42, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_53, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_54, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_55, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_56, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_57, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_60, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_61, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_62, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_63, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_64, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_65, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_67, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_70, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_72, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_evt_mask_73, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0005:
proto_tree_add_item(tree, hf_bthci_cmd_filter_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
filter_type = tvb_get_guint8(tvb, 3);
offset++;
switch (filter_type) {
case 0x01:
proto_tree_add_item(tree, hf_bthci_cmd_inquiry_result_filter_condition_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
filter_condition_type = tvb_get_guint8(tvb, offset);
offset++;
switch (filter_condition_type) {
case 0x01:
offset=dissect_bthci_cmd_cod(hf_bthci_cmd_class_of_device, tvb, offset, pinfo, tree);
offset=dissect_bthci_cmd_cod(hf_bthci_cmd_class_of_device_mask, tvb, offset, pinfo, tree);
break;
case 0x02:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
break;
default:
break;
}
break;
case 0x02:
proto_tree_add_item(tree, hf_bthci_cmd_connection_setup_filter_condition_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
filter_condition_type = tvb_get_guint8(tvb, offset);
offset++;
switch (filter_condition_type) {
case 0x00:
proto_tree_add_item(tree, hf_bthci_cmd_auto_acc_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x01:
offset=dissect_bthci_cmd_cod(hf_bthci_cmd_class_of_device, tvb, offset, pinfo, tree);
offset=dissect_bthci_cmd_cod(hf_bthci_cmd_class_of_device_mask, tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_auto_acc_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x02:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_auto_acc_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
default:
break;
}
break;
default:
break;
}
break;
case 0x000a:
proto_tree_add_item(tree, hf_bthci_cmd_pin_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x000d:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_read_all_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0011:
proto_tree_add_item(tree, hf_bthci_cmd_num_link_keys, tvb, offset, 1, ENC_LITTLE_ENDIAN);
num8 = tvb_get_guint8(tvb, offset);
offset++;
for (i=0; i<num8; i++) {
dissect_bthci_cmd_bd_addr(tvb, offset+(i*22), pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_link_key, tvb, offset+6+(i*22), 16, ENC_NA);
}
break;
case 0x0012:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_delete_all_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0013:
proto_tree_add_item(tree, hf_bthci_cmd_device_name,
tvb, offset, 248, ENC_ASCII|ENC_NA);
offset+=248;
break;
case 0x0016:
item = proto_tree_add_item(tree, hf_bthci_cmd_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
timeout = tvb_get_letohs(tvb, offset);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset+=2;
break;
case 0x0018:
item = proto_tree_add_item(tree, hf_bthci_cmd_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
timeout = tvb_get_letohs(tvb, offset);
if (timeout > 0) {
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
} else {
proto_item_append_text(item, " Illegal Page Timeout");
}
offset+=2;
break;
case 0x001a:
proto_tree_add_item(tree, hf_bthci_cmd_scan_enable,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0020:
proto_tree_add_item(tree, hf_bthci_cmd_authentication_enable,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0022:
proto_tree_add_item(tree, hf_bthci_cmd_encrypt_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0024:
offset=dissect_bthci_cmd_cod(hf_bthci_cmd_class_of_device, tvb, offset, pinfo, tree);
break;
case 0x0026:
proto_tree_add_item(tree, hf_bthci_cmd_input_coding,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_input_data_format,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_input_sample_size,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_linear_pcm_bit_pos,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_air_coding_format,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0028:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
timeout = tvb_get_letohs(tvb, offset);
if (timeout>0) {
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
} else {
proto_item_append_text(item, " (= No Automatic Flush )");
}
offset+=2;
break;
case 0x002a:
proto_tree_add_item(tree, hf_bthci_cmd_num_broadcast_retransmissions,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x002c:
proto_tree_add_item(tree, hf_bthci_cmd_hold_mode_act_page,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_hold_mode_act_inquiry,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_hold_mode_act_periodic,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x002d:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_power_level_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x002f:
proto_tree_add_item(tree, hf_bthci_cmd_sco_flow_control,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0031:
proto_tree_add_item(tree, hf_bthci_cmd_flow_contr_enable,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0033:
proto_tree_add_item(tree, hf_bthci_cmd_host_data_packet_length_acl,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_host_data_packet_length_sco,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_bthci_cmd_host_total_num_acl_data_packets,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_host_total_num_sco_data_packets,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0035:
proto_tree_add_item(tree, hf_bthci_cmd_num_handles,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
num8 = tvb_get_guint8(tvb, offset);
offset++;
for (i=0; i<num8; i++) {
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle,
tvb, offset+(i*4), 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_cmd_num_compl_packets,
tvb, offset+2+(i*4), 2, ENC_LITTLE_ENDIAN);
}
break;
case 0x0037:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_timeout,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
timeout = tvb_get_letohs(tvb, offset);
if (timeout>0) {
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
} else {
proto_item_append_text(item, " (= No Link Supervision Timeout)");
}
offset+=2;
break;
case 0x003a:
proto_tree_add_item(tree, hf_bthci_cmd_num_curr_iac, tvb, offset, 1, ENC_LITTLE_ENDIAN);
num8 = tvb_get_guint8(tvb, offset);
offset++;
for (i=0; i<num8; i++) {
proto_tree_add_item(tree, hf_bthci_cmd_iac_lap, tvb, offset+(i*3), 3, ENC_LITTLE_ENDIAN);
}
break;
case 0x003c:
proto_tree_add_item(tree, hf_bthci_cmd_page_scan_period_mode,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x003e:
proto_tree_add_item(tree, hf_bthci_cmd_page_scan_mode,
tvb, 3, 1, ENC_LITTLE_ENDIAN);
break;
case 0x003f:
proto_tree_add_item(tree, hf_bthci_cmd_afh_ch_classification, tvb, offset, 10, ENC_NA);
offset+=10;
break;
case 0x0008:
case 0x0027:
case 0x0036:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x001c:
case 0x001e:
item = proto_tree_add_item(tree, hf_bthci_cmd_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
item = proto_tree_add_item(tree, hf_bthci_cmd_window, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset+=2;
break;
case 0x0043:
proto_tree_add_item(tree, hf_bthci_cmd_scan_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0045:
proto_tree_add_item(tree, hf_bthci_cmd_inq_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0047:
proto_tree_add_item(tree, hf_bthci_cmd_scan_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0049:
proto_tree_add_item(tree, hf_bthci_cmd_afh_ch_assessment_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0052:
proto_tree_add_item(tree, hf_bthci_cmd_fec_required, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset=dissect_bthci_ext_inquiry_response(tvb, offset, pinfo, tree);
break;
case 0x0053:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0056:
proto_tree_add_item(tree, hf_bthci_cmd_simple_pairing_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0059:
proto_tree_add_item(tree, hf_bthci_cmd_tx_power, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x005b:
proto_tree_add_item(tree, hf_bthci_cmd_err_data_reporting, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x005f:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_flush_packet_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0060:
offset = dissect_bthci_cmd_bd_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_bthci_cmd_notification_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
default:
proto_tree_add_item(tree, hf_bthci_cmd_params, tvb, offset, -1, ENC_NA);
offset+=tvb_length_remaining(tvb, offset);
break;
}
return offset;
}
static int
dissect_informational_parameters_cmd(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint16 cmd_ocf)
{
switch (cmd_ocf) {
case 0x0004:
proto_tree_add_item(tree, hf_bthci_cmd_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
default:
proto_tree_add_item(tree, hf_bthci_cmd_params, tvb, offset, -1, ENC_NA);
offset+=tvb_length_remaining(tvb, offset);
break;
}
return offset;
}
static int
dissect_status_parameters_cmd(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint16 cmd_ocf)
{
switch (cmd_ocf) {
case 0x0001:
case 0x0002:
case 0x0003:
case 0x0005:
case 0x0006:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
break;
case 0x0007:
proto_tree_add_item(tree, hf_bthci_cmd_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_bthci_cmd_which_clock, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
default:
proto_tree_add_item(tree, hf_bthci_cmd_params, tvb, offset, -1, ENC_NA);
offset+=tvb_length_remaining(tvb, offset);
break;
}
return offset;
}
static int
dissect_testing_cmd(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, guint16 cmd_ocf)
{
switch (cmd_ocf) {
case 0x0002:
proto_tree_add_item(tree, hf_bthci_cmd_loopback_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case 0x0004:
proto_tree_add_item(tree, hf_bthci_cmd_simple_pairing_debug_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
default:
proto_tree_add_item(tree, hf_bthci_cmd_params, tvb, offset, -1, ENC_NA);
offset+=tvb_length_remaining(tvb, offset);
break;
}
return offset;
}
static void
dissect_bthci_cmd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti_cmd = NULL;
proto_tree *bthci_cmd_tree = NULL;
guint16 opcode, ocf;
guint8 param_length, ogf;
int offset = 0;
proto_item *ti_opcode;
proto_tree *opcode_tree;
if (tree) {
ti_cmd = proto_tree_add_item(tree, proto_bthci_cmd, tvb, offset, -1, ENC_NA);
bthci_cmd_tree = proto_item_add_subtree(ti_cmd, ett_bthci_cmd);
}
opcode = tvb_get_letohs(tvb, offset);
ocf = opcode & 0x03ff;
ogf = (guint8) (opcode >> 10);
proto_item_append_text(ti_cmd," - %s", val_to_str_ext(opcode, &bthci_cmd_opcode_vals_ext, "Unknown 0x%04x"));
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI_CMD");
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_ext(opcode, &bthci_cmd_opcode_vals_ext, "Unknown 0x%04x"));
ti_opcode = proto_tree_add_item(bthci_cmd_tree, hf_bthci_cmd_opcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
opcode_tree = proto_item_add_subtree(ti_opcode, ett_opcode);
proto_tree_add_item(opcode_tree, hf_bthci_cmd_ogf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(opcode_tree, hf_bthci_cmd_ocf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(bthci_cmd_tree, hf_bthci_cmd_param_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
param_length = tvb_get_guint8(tvb, offset);
offset++;
if (param_length > 0) {
switch (ogf) {
case 0x01:
dissect_link_control_cmd(tvb, offset, pinfo, bthci_cmd_tree, ocf);
break;
case 0x02:
dissect_link_policy_cmd(tvb, offset, pinfo, bthci_cmd_tree, ocf);
break;
case 0x03:
dissect_host_controller_baseband_cmd(tvb, offset, pinfo, bthci_cmd_tree, ocf);
break;
case 0x04:
dissect_informational_parameters_cmd(tvb, offset, pinfo, bthci_cmd_tree, ocf);
break;
case 0x05:
dissect_status_parameters_cmd(tvb, offset, pinfo, bthci_cmd_tree, ocf);
break;
case 0x06:
dissect_testing_cmd(tvb, offset, pinfo, bthci_cmd_tree, ocf);
break;
default:
proto_tree_add_item(bthci_cmd_tree, hf_bthci_cmd_params, tvb, 3, -1, ENC_NA);
break;
}
}
}
void
proto_register_bthci_cmd(void)
{
static hf_register_info hf[] = {
{ &hf_bthci_cmd_opcode,
{ "Command Opcode","bthci_cmd.opcode", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&bthci_cmd_opcode_vals_ext, 0x0, "HCI Command Opcode", HFILL }
},
{ &hf_bthci_cmd_ogf,
{ "ogf", "bthci_cmd.ogf",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &bthci_ogf_vals_ext, 0xfc00,
"Opcode Group Field", HFILL }
},
{ &hf_bthci_cmd_ocf,
{ "ocf", "bthci_cmd.ocf",
FT_UINT16, BASE_HEX, NULL, 0x03ff,
"Opcode Command Field", HFILL }
},
{ &hf_bthci_cmd_param_length,
{ "Parameter Total Length", "bthci_cmd.param_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_params,
{ "Command Parameters", "bthci_cmd.params",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_lap,
{ "LAP", "bthci_cmd.lap",
FT_UINT24, BASE_HEX, NULL, 0x0,
"LAP for the inquiry access code", HFILL }
},
{ &hf_bthci_cmd_inq_length,
{ "Inquiry Length", "bthci_cmd.inq_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Inquiry Length (*1.28s)", HFILL }
},
{ &hf_bthci_cmd_num_responses,
{ "Num Responses", "bthci_cmd.num_responses",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Responses", HFILL }
},
{ &hf_bthci_cmd_encrypt_mode,
{ "Encryption Mode", "bthci_cmd.encrypt_mode",
FT_UINT8, BASE_HEX, VALS(encrypt_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_bd_addr,
{ "BD_ADDR:", "bthci_cmd.bd_addr",
FT_NONE, BASE_NONE, NULL, 0x0,
"Bluetooth Device Address", HFILL}
},
{ &hf_bthci_cmd_packet_type_2dh1,
{ "Packet Type 2-DH1", "bthci_cmd.packet_type_2dh1",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0002,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_3dh1,
{ "Packet Type 3-DH1", "bthci_cmd.packet_type_3dh1",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0004,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_dm1,
{ "Packet Type DM1", "bthci_cmd.packet_type_dm1",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0008,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_dh1,
{ "Packet Type DH1", "bthci_cmd.packet_type_dh1",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0010,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_2dh3,
{ "Packet Type 2-DH3", "bthci_cmd.packet_type_2dh3",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0100,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_3dh3,
{ "Packet Type 3-DH3", "bthci_cmd.packet_type_3dh3",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0200,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_dm3,
{ "Packet Type DM3", "bthci_cmd.packet_type_dm3",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0400,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_dh3,
{ "Packet Type DH3", "bthci_cmd.packet_type_dh3",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0800,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_2dh5,
{ "Packet Type 2-DH5", "bthci_cmd.packet_type_2dh5",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x1000,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_3dh5,
{ "Packet Type 3-DH5", "bthci_cmd.packet_type_3dh5",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x2000,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_dm5,
{ "Packet Type DM5", "bthci_cmd.packet_type_dm5",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x4000,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_dh5,
{ "Packet Type DH5", "bthci_cmd.packet_type_dh5",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x8000,
NULL, HFILL }
},
{ &hf_bthci_cmd_page_scan_mode,
{ "Page Scan Mode", "bthci_cmd.page_scan_mode",
FT_UINT8, BASE_HEX, VALS(cmd_page_scan_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_page_scan_repetition_mode,
{ "Page Scan Repetition Mode", "bthci_cmd.page_scan_repetition_mode",
FT_UINT8, BASE_HEX, VALS(cmd_page_scan_repetition_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_page_scan_period_mode,
{ "Page Scan Period Mode", "bthci_cmd.page_scan_period_mode",
FT_UINT8, BASE_HEX, VALS(cmd_page_scan_period_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_clock_offset,
{ "Clock Offset", "bthci_cmd.clock_offset",
FT_UINT16, BASE_HEX, NULL, 0x7FFF,
"Bit 2-16 of the Clock Offset between CLKmaster-CLKslave", HFILL }
},
{ &hf_bthci_cmd_clock_offset_valid,
{ "Clock_Offset_Valid_Flag", "bthci_cmd.clock_offset_valid",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x8000,
"Indicates if clock offset is valid", HFILL }
},
{ &hf_bthci_cmd_allow_role_switch,
{ "Allow Role Switch", "bthci_cmd.allow_role_switch",
FT_UINT8, BASE_HEX, VALS(cmd_role_switch_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_status,
{ "Status", "bthci_cmd.status",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_status_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_max_period_length,
{ "Max Period Length", "bthci_cmd.max_period_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum amount of time specified between consecutive inquiries.", HFILL }
},
{ &hf_bthci_cmd_min_period_length,
{ "Min Period Length", "bthci_cmd.min_period_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Minimum amount of time specified between consecutive inquiries.", HFILL }
},
{ &hf_bthci_cmd_connection_handle,
{ "Connection Handle", "bthci_cmd.connection_handle",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_reason,
{ "Reason", "bthci_cmd.reason",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_status_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_num_link_keys,
{ "Number of Link Keys", "bthci_cmd.num_link_keys",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_link_key,
{ "Link Key", "bthci_cmd.link_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Link Key for the associated BD_ADDR", HFILL }
},
{ &hf_bthci_cmd_packet_type_hv1,
{ "Packet Type HV1", "bthci_cmd.packet_type_hv1",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0020,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_hv2,
{ "Packet Type HV2", "bthci_cmd.packet_type_hv2",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0040,
NULL, HFILL }
},
{ &hf_bthci_cmd_packet_type_hv3,
{ "Packet Type HV3", "bthci_cmd.packet_type_hv3",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0080,
NULL, HFILL }
},
{ &hf_bthci_cmd_role,
{ "Role", "bthci_cmd.role",
FT_UINT8, BASE_HEX, VALS(cmd_role_vals), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_pin_code_length,
{ "PIN Code Length", "bthci_cmd.pin_code_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_pin_code,
{ "PIN Code", "bthci_cmd.pin_code",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_pin_type,
{ "PIN Type", "bthci_cmd.pin_type",
FT_UINT8, BASE_HEX, VALS(cmd_pin_types), 0x0,
"PIN Types", HFILL }
},
{ &hf_bthci_cmd_encryption_enable,
{ "Encryption Enable", "bthci_cmd.encryption_enable",
FT_UINT8, BASE_HEX, VALS(cmd_encryption_enable), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_key_flag,
{ "Key Flag", "bthci_cmd.key_flag",
FT_UINT8, BASE_HEX, VALS(cmd_key_flag), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_max_interval_hold,
{ "Hold Mode Max Interval", "bthci_cmd.hold_mode_max_int",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximal acceptable number of Baseband slots to wait in Hold Mode.", HFILL }
},
{ &hf_bthci_cmd_min_interval_hold,
{ "Hold Mode Min Interval", "bthci_cmd.hold_mode_min_int",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Minimum acceptable number of Baseband slots to wait in Hold Mode.", HFILL }
},
{ &hf_bthci_cmd_max_interval_sniff,
{ "Sniff Max Interval", "bthci_cmd.sniff_max_int",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximal acceptable number of Baseband slots between each sniff period.", HFILL }
},
{ &hf_bthci_cmd_min_interval_sniff,
{ "Sniff Min Interval", "bthci_cmd.sniff_min_int",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Minimum acceptable number of Baseband slots between each sniff period.", HFILL }
},
{ &hf_bthci_cmd_sniff_attempt,
{ "Sniff Attempt", "bthci_cmd.sniff_attempt",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of Baseband receive slots for sniff attempt.", HFILL }
},
{ &hf_bthci_cmd_timeout,
{ "Timeout", "bthci_cmd.timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of Baseband slots for timeout.", HFILL }
},
{ &hf_bthci_cmd_max_interval_beacon,
{ "Beacon Max Interval", "bthci_cmd.beacon_max_int",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximal acceptable number of Baseband slots between consecutive beacons.", HFILL }
},
{ &hf_bthci_cmd_min_interval_beacon,
{ "Beacon Min Interval", "bthci_cmd.beacon_min_int",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Minimum acceptable number of Baseband slots between consecutive beacons.", HFILL }
},
{ &hf_bthci_cmd_flags,
{ "Flags", "bthci_cmd.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_service_type,
{ "Service Type", "bthci_cmd.service_type",
FT_UINT8, BASE_HEX, VALS(cmd_service_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_token_rate,
{ "Available Token Rate", "bthci_cmd.token_rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Token Rate, in bytes per second", HFILL }
},
{ &hf_bthci_cmd_token_bucket_size,
{ "Available Token Bucket Size", "bthci_cmd.token_bucket_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Token Bucket Size in bytes", HFILL }
},
{ &hf_bthci_cmd_peak_bandwidth,
{ "Peak Bandwidth", "bthci_cmd.peak_bandwidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Peak Bandwidth, in bytes per second", HFILL }
},
{ &hf_bthci_cmd_latency,
{ "Latency", "bthci_cmd.latency",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Latency, in microseconds", HFILL }
},
{ &hf_bthci_cmd_delay_variation,
{ "Delay Variation", "bthci_cmd.delay_variation",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Delay Variation, in microseconds", HFILL }
},
{ &hf_bthci_cmd_link_policy_setting_switch,
{ "Enable Master Slave Switch", "bthci_cmd.link_policy_switch",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0001,
NULL, HFILL }
},
{ &hf_bthci_cmd_link_policy_setting_hold,
{ "Enable Hold Mode", "bthci_cmd.link_policy_hold",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0002,
NULL, HFILL }
},
{ &hf_bthci_cmd_link_policy_setting_sniff,
{ "Enable Sniff Mode", "bthci_cmd.link_policy_sniff",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0004,
NULL, HFILL }
},
{ &hf_bthci_cmd_link_policy_setting_park,
{ "Enable Park Mode", "bthci_cmd.link_policy_park",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0008,
NULL, HFILL }
},
{ &hf_bthci_cmd_filter_type,
{ "Filter Type", "bthci_cmd.filter_type",
FT_UINT8, BASE_HEX, VALS(cmd_filter_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_inquiry_result_filter_condition_type,
{ "Filter Condition Type", "bthci_cmd.filter_condition_type",
FT_UINT8, BASE_HEX, VALS(cmd_inquiry_result_filter_condition_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_connection_setup_filter_condition_type,
{ "Filter Condition Type", "bthci_cmd.filter_condition_type",
FT_UINT8, BASE_HEX, VALS(cmd_connection_setup_filter_condition_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_class_of_device,
{ "Class of Device", "bthci_cmd.class_of_device",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_class_of_device_mask,
{ "Class of Device Mask", "bthci_cmd.class_of_device_mask",
FT_UINT24, BASE_HEX, NULL, 0x0,
"Bit Mask used to determine which bits of the Class of Device parameter are of interest.", HFILL }
},
{ &hf_bthci_cmd_auto_acc_flag,
{ "Auto Accept Flag", "bthci_cmd.auto_accept_flag",
FT_UINT8, BASE_HEX, VALS(cmd_auto_acc_flag_values), 0x0,
"Class of Device of Interest", HFILL }
},
{ &hf_bthci_cmd_read_all_flag,
{ "Read All Flag", "bthci_cmd.read_all_flag",
FT_UINT8, BASE_HEX, VALS(cmd_read_all_flag_values), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_delete_all_flag,
{ "Delete All Flag", "bthci_cmd.delete_all_flag",
FT_UINT8, BASE_HEX, VALS(cmd_delete_all_flag_values), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_authentication_enable,
{ "Authentication Enable", "bthci_cmd.auth_enable",
FT_UINT8, BASE_HEX, VALS(cmd_authentication_enable_values), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_input_coding,
{ "Input Coding", "bthci_cmd.input_coding",
FT_UINT16, BASE_DEC, VALS(cmd_input_coding_values), 0x0300,
"Authentication Enable", HFILL }
},
{ &hf_bthci_cmd_input_data_format,
{ "Input Data Format", "bthci_cmd.input_data_format",
FT_UINT16, BASE_DEC, VALS(cmd_input_data_format_values), 0x00c0,
NULL, HFILL }
},
{ &hf_bthci_cmd_input_sample_size,
{ "Input Sample Size", "bthci_cmd.input_sample_size",
FT_UINT16, BASE_DEC, VALS(cmd_input_sample_size_values), 0x0020,
NULL, HFILL }
},
{ &hf_bthci_cmd_linear_pcm_bit_pos,
{ "Linear PCM Bit Pos", "bthci_cmd.lin_pcm_bit_pos",
FT_UINT16, BASE_DEC, NULL, 0x001c,
"# bit pos. that MSB of sample is away from starting at MSB", HFILL }
},
{ &hf_bthci_cmd_air_coding_format,
{ "Air Coding Format", "bthci_cmd.air_coding_format",
FT_UINT16, BASE_DEC, VALS(cmd_air_coding_format_values), 0x0003,
NULL, HFILL }
},
{ &hf_bthci_cmd_num_broadcast_retransmissions,
{ "Num Broadcast Retran", "bthci_cmd.num_broad_retran",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Broadcast Retransmissions", HFILL }
},
{ &hf_bthci_cmd_hold_mode_act_page,
{ "Suspend Page Scan", "bthci_cmd.hold_mode_page",
FT_UINT8, BASE_DEC, VALS(cmd_boolean), 0x1,
"Device can enter low power state", HFILL }
},
{ &hf_bthci_cmd_hold_mode_act_inquiry,
{ "Suspend Inquiry Scan", "bthci_cmd.hold_mode_inquiry",
FT_UINT8, BASE_DEC, VALS(cmd_boolean), 0x2,
"Device can enter low power state", HFILL }
},
{ &hf_bthci_cmd_hold_mode_act_periodic,
{ "Suspend Periodic Inquiries", "bthci_cmd.hold_mode_periodic",
FT_UINT8, BASE_DEC, VALS(cmd_boolean), 0x4,
"Device can enter low power state", HFILL }
},
{ &hf_bthci_cmd_scan_enable,
{ "Scan Enable", "bthci_cmd.scan_enable",
FT_UINT8, BASE_HEX, VALS(cmd_scan_enable_values), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_interval,
{ "Interval", "bthci_cmd.interval",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_window,
{ "Interval", "bthci_cmd.window",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Window", HFILL }
},
{ &hf_bthci_cmd_device_name,
{ "Device Name", "bthci_cmd.device_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Userfriendly descriptive name for the device", HFILL }
},
{ &hf_bthci_cmd_num_curr_iac,
{ "Number of Current IAC", "bthci_cmd.num_curr_iac",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of IACs which are currently in use", HFILL }
},
{ &hf_bthci_cmd_iac_lap,
{ "IAC LAP", "bthci_cmd.num_curr_iac",
FT_UINT24, BASE_HEX, NULL, 0x0,
"LAP(s)used to create IAC", HFILL }
},
{ &hf_bthci_cmd_evt_mask_00,
{ "Inquiry Complete", "bthci_cmd.evt_mask_00",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x01,
"Inquiry Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_01,
{ "Inquiry Result", "bthci_cmd.evt_mask_01",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x02,
"Inquiry Result Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_02,
{ "Connect Complete", "bthci_cmd.evt_mask_02",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x04,
"Connection Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_03,
{ "Connect Request", "bthci_cmd.evt_mask_03",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x08,
"Connect Request Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_04,
{ "Disconnect Complete", "bthci_cmd.evt_mask_04",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x10,
"Disconnect Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_05,
{ "Auth Complete", "bthci_cmd.evt_mask_05",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x20,
"Auth Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_06,
{ "Remote Name Req Complete", "bthci_cmd.evt_mask_06",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x40,
"Remote Name Req Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_07,
{ "Encrypt Change", "bthci_cmd.evt_mask_07",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x80,
"Encrypt Change Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_10,
{ "Change Connection Link Key Complete", "bthci_cmd.evt_mask_10",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x01,
"Change Connection Link Key Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_11,
{ "Master Link Key Complete", "bthci_cmd.evt_mask_11",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x02,
"Master Link Key Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_12,
{ "Read Remote Supported Features", "bthci_cmd.evt_mask_12",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x04,
"Read Remote Supported Features Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_13,
{ "Read Remote Ver Info Complete", "bthci_cmd.evt_mask_13",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x08,
"Read Remote Ver Info Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_14,
{ "QoS Setup Complete", "bthci_cmd.evt_mask_14",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x10,
"QoS Setup Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_17,
{ "Hardware Error", "bthci_cmd.evt_mask_17",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x80,
"Hardware Error Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_20,
{ "Flush Occurred", "bthci_cmd.evt_mask_20",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x01,
"Flush Occurred Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_21,
{ "Role Change", "bthci_cmd.evt_mask_21",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x02,
"Role Change Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_23,
{ "Mode Change", "bthci_cmd.evt_mask_23",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x08,
"Mode Change Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_24,
{ "Return Link Keys", "bthci_cmd.evt_mask_24",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x10,
"Return Link Keys Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_25,
{ "PIN Code Request", "bthci_cmd.evt_mask_25",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x20,
"PIN Code Request Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_26,
{ "Link Key Request", "bthci_cmd.evt_mask_26",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x40,
"Link Key Request Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_27,
{ "Link Key Notification", "bthci_cmd.evt_mask_27",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x80,
"Link Key Notification Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_30,
{ "Loopback Command", "bthci_cmd.evt_mask_30",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x01,
"Loopback Command Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_31,
{ "Data Buffer Overflow" , "bthci_cmd.evt_mask_31",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x02,
"Data Buffer Overflow Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_32,
{ "Max Slots Change", "bthci_cmd.evt_mask_32",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x04,
"Max Slots Change Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_33,
{ "Read Clock Offset Complete", "bthci_cmd.evt_mask_33",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x08,
"Read Clock Offset Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_34,
{ "Connection Packet Type Changed", "bthci_cmd.evt_mask_34",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x10,
"Connection Packet Type Changed Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_35,
{ "QoS Violation", "bthci_cmd.evt_mask_35",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x20,
"QoS Violation Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_36,
{ "Page Scan Mode Change", "bthci_cmd.evt_mask_36",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x40,
"Page Scan Mode Change Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_37,
{ "Page Scan Repetition Mode Change", "bthci_cmd.evt_mask_37",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x80,
"Page Scan Repetition Mode Change Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_40,
{ "Flow Specification Complete", "bthci_cmd.evt_mask_40",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x01,
"Flow Specification Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_41,
{ "Inquiry Result With RSSI", "bthci_cmd.evt_mask_41",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x02,
"Inquiry Result With RSSI Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_42,
{ "Read Remote Ext. Features Complete", "bthci_cmd.evt_mask_42",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x04,
"Read Remote Ext. Features Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_53,
{ "Synchronous Connection Complete", "bthci_cmd.evt_mask_53",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x08,
"Synchronous Connection Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_54,
{ "Synchronous Connection Changed", "bthci_cmd.evt_mask_54",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x10,
"Synchronous Connection Changed Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_55,
{ "Sniff Subrate", "bthci_cmd.evt_mask_55",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x20,
"Sniff Subrate Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_56,
{ "Extended Inquiry Result", "bthci_cmd.evt_mask_56",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x40,
"Extended Inquiry Result Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_57,
{ "Encryption Key Refresh Complete", "bthci_cmd.evt_mask_57",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x80,
"Encryption Key Refresh Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_60,
{ "IO Capability Request", "bthci_cmd.evt_mask_60",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x01,
"IO Capability Request Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_61,
{ "IO Capability Response", "bthci_cmd.evt_mask_61",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x02,
"IO Capability Response Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_62,
{ "User Confirmation Request", "bthci_cmd.evt_mask_62",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x04,
"User Confirmation Request Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_63,
{ "User Passkey Request", "bthci_cmd.evt_mask_63",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x08,
"User Passkey Request Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_64,
{ "Remote OOB Data Request", "bthci_cmd.evt_mask_64",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x10,
"Remote OOB Data Request Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_65,
{ "Simple Pairing Complete", "bthci_cmd.evt_mask_65",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x20,
"Simple Pairing Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_67,
{ "Link Supervision Timeout Changed", "bthci_cmd.evt_mask_67",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x80,
"Link Supervision Timeout Changed Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_70,
{ "Enhanced Flush Complete", "bthci_cmd.evt_mask_70",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x01,
"Enhanced Flush Complete Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_72,
{ "User Passkey Notification", "bthci_cmd.evt_mask_72",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x04,
"User Passkey Notification Bit", HFILL }
},
{ &hf_bthci_cmd_evt_mask_73,
{ "Keypress Notification", "bthci_cmd.evt_mask_73",
FT_UINT8, BASE_HEX, VALS(cmd_boolean), 0x08,
"Keypress Notification Bit", HFILL }
},
{ &hf_bthci_cmd_sco_flow_control,
{ "SCO Flow Control","bthci_cmd.flow_control",
FT_UINT8, BASE_HEX, VALS(cmd_en_disabled), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_num_handles,
{ "Number of Handles", "bthci_cmd.num_handles",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_num_compl_packets,
{ "Number of Completed Packets", "bthci_cmd.num_compl_packets",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of Completed HCI Data Packets", HFILL }
},
{ &hf_bthci_cmd_flow_contr_enable,
{ "Flow Control Enable", "bthci_cmd.flow_contr_enable",
FT_UINT8, BASE_HEX, VALS(cmd_flow_contr_enable), 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_host_data_packet_length_acl,
{"Host ACL Data Packet Length (bytes)", "bthci_cmd.max_data_length_acl",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Max Host ACL Data Packet length of data portion host is able to accept", HFILL }
},
{ &hf_bthci_cmd_host_data_packet_length_sco,
{"Host SCO Data Packet Length (bytes)", "bthci_cmd.max_data_length_sco",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Max Host SCO Data Packet length of data portion host is able to accept", HFILL }
},
{ &hf_bthci_cmd_host_total_num_acl_data_packets,
{"Host Total Num ACL Data Packets", "bthci_cmd.max_data_num_acl",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total Number of HCI ACL Data Packets that can be stored in the data buffers of the Host", HFILL }
},
{ &hf_bthci_cmd_host_total_num_sco_data_packets,
{"Host Total Num SCO Data Packets", "bthci_cmd.max_data_num_sco",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total Number of HCI SCO Data Packets that can be stored in the data buffers of the Host", HFILL }
},
{ &hf_bthci_cmd_power_level_type,
{"Type", "bthci_cmd.power_level_type",
FT_UINT8, BASE_HEX, VALS(cmd_power_level_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_loopback_mode,
{"Loopback Mode", "bthci_cmd.loopback_mode",
FT_UINT8, BASE_HEX, VALS(cmd_loopback_modes), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_page_number,
{"Page Number", "bthci_cmd.page_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_transmit_bandwidth,
{"Tx Bandwidth (bytes/s)", "bthci_cmd.tx_bandwidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Tx Bandwidth", HFILL}
},
{ &hf_bthci_cmd_receive_bandwidth,
{"Rx Bandwidth (bytes/s)", "bthci_cmd.rx_bandwidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Rx Bandwidth", HFILL}
},
{ &hf_bthci_cmd_max_latency_ms,
{"Max. Latency (ms)", "bthci_cmd.max_latency_ms",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_max_latency,
{"Max. Latency", "bthci_cmd.max_latency",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Max. Latency in baseband slots", HFILL}
},
{ &hf_bthci_cmd_retransmission_effort,
{"Retransmission Effort", "bthci_cmd.retransmission_effort",
FT_UINT8, BASE_DEC, VALS(cmd_rtx_effort), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_scan_type,
{"Scan Type", "bthci_cmd.inq_scan_type",
FT_UINT8, BASE_DEC, VALS(cmd_scan_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_inq_mode,
{"Inquiry Mode", "bthci_cmd.inq_scan_type",
FT_UINT8, BASE_DEC, VALS(cmd_inq_modes), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_fec_required,
{"FEC Required", "bthci_cmd.fec_required",
FT_UINT8, BASE_DEC, VALS(cmd_boolean), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_err_data_reporting,
{"Erroneous Data Reporting", "bthci_cmd.err_data_reporting",
FT_UINT8, BASE_DEC, VALS(cmd_en_disabled), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_tx_power,
{"Power Level (dBm)", "bthci_cmd.power_level",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_sco_packet_type_hv1,
{ "Packet Type HV1", "bthci_cmd.sco_packet_type_hv1",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0001,
NULL, HFILL }
},
{ &hf_bthci_cmd_sco_packet_type_hv2,
{ "Packet Type HV2", "bthci_cmd.sco_packet_type_hv2",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0002,
NULL, HFILL }
},
{ &hf_bthci_cmd_sco_packet_type_hv3,
{ "Packet Type HV3", "bthci_cmd.sco_packet_type_hv3",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0004,
NULL, HFILL }
},
{ &hf_bthci_cmd_sco_packet_type_ev3,
{ "Packet Type EV3", "bthci_cmd.sco_packet_type_ev3",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0008,
NULL, HFILL }
},
{ &hf_bthci_cmd_sco_packet_type_ev4,
{ "Packet Type EV4", "bthci_cmd.sco_packet_type_ev4",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0010,
NULL, HFILL }
},
{ &hf_bthci_cmd_sco_packet_type_ev5,
{ "Packet Type EV5", "bthci_cmd.sco_packet_type_ev5",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0020,
NULL, HFILL }
},
{ &hf_bthci_cmd_sco_packet_type_2ev3,
{ "Packet Type 2-EV3", "bthci_cmd.sco_packet_type_2ev3",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0040,
NULL, HFILL }
},
{ &hf_bthci_cmd_sco_packet_type_3ev3,
{ "Packet Type 3-EV3", "bthci_cmd.sco_packet_type_3ev3",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0080,
NULL, HFILL }
},
{ &hf_bthci_cmd_sco_packet_type_2ev5,
{ "Packet Type 2-EV5", "bthci_cmd.sco_packet_type_2ev5",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0100,
NULL, HFILL }
},
{ &hf_bthci_cmd_sco_packet_type_3ev5,
{ "Packet Type 3-EV5", "bthci_cmd.sco_packet_type_3ev5",
FT_UINT16, BASE_DEC, VALS(cmd_boolean), 0x0200,
NULL, HFILL }
},
{ &hf_bthci_cmd_min_remote_timeout,
{"Min. Remote Timeout", "bthci_cmd.min_remote_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Min. Remote Timeout in baseband slots", HFILL}
},
{ &hf_bthci_cmd_min_local_timeout,
{"Min. Local Timeout", "bthci_cmd.min_local_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Min. Local Timeout in baseband slots", HFILL}
},
{ &hf_bthci_cmd_flush_packet_type,
{"Packet Type", "bthci_cmd.flush_packet_type",
FT_UINT8, BASE_DEC, VALS(cmd_flush_pkt_type), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_afh_ch_assessment_mode,
{"AFH Channel Assessment Mode", "bthci_cmd.afh_ch_assessment_mode",
FT_UINT8, BASE_DEC, VALS(cmd_en_disabled), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_afh_ch_classification,
{ "Channel Classification", "bthci_cmd.afh_ch_classification",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_cmd_which_clock,
{"Which Clock", "bthci_cmd.which_clock",
FT_UINT8, BASE_DEC, VALS(cmd_which_clock), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_io_capability,
{"IO Capability", "bthci_cmd.io_capability",
FT_UINT8, BASE_DEC, VALS(bthci_cmd_io_capability_vals), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_oob_data_present,
{"OOB Data Present", "bthci_cmd.oob_data_present",
FT_UINT8, BASE_DEC, VALS(bthci_cmd_oob_data_present_vals), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_auth_requirements,
{"Authentication Requirements", "bthci_cmd.auth_requirements",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &bthci_cmd_auth_req_vals_ext, 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_passkey,
{"Passkey", "bthci_cmd.passkey",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_hash_c,
{"Hash C", "bthci_cmd.hash_c",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_randomizer_r,
{"Randomizer R", "bthci_cmd.randomizer_r",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_simple_pairing_mode,
{"Simple Pairing Mode", "bthci_cmd.simple_pairing_mode",
FT_UINT8, BASE_DEC, VALS(cmd_en_disabled), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_simple_pairing_debug_mode,
{"Simple Pairing Debug Mode", "bthci_cmd.simple_pairing_debug_mode",
FT_UINT8, BASE_DEC, VALS(cmd_en_disabled), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_notification_type,
{"Notification Type", "bthci_cmd.notification_type",
FT_UINT8, BASE_DEC, VALS(cmd_notification_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_cmd_eir_data,
{"Data", "bthci_cmd.eir_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"EIR Data", HFILL}
},
{ &hf_bthci_cmd_eir_struct_length,
{ "Length", "bthci_cmd.eir_struct_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Structure Length", HFILL }
},
{ &hf_bthci_cmd_eir_struct_type,
{ "Type", "bthci_cmd.eir_data_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_eir_data_type_vals_ext, 0x0,
"Data Type", HFILL }
},
{ &hf_bthci_cmd_sc_uuid16,
{ "UUID", "bthci_cmd.service_class_uuid16",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_service_class_type_vals_ext, 0x0,
"16-bit Service Class UUID", HFILL }
},
{ &hf_bthci_cmd_sc_uuid32,
{ "UUID", "bthci_cmd.service_class_uuid32",
FT_UINT32, BASE_HEX, NULL, 0x0,
"32-bit Service Class UUID", HFILL }
},
{ &hf_bthci_cmd_sc_uuid128,
{ "UUID", "bthci_cmd.service_class_uuid128",
FT_BYTES, BASE_NONE, NULL, 0x0,
"128-bit Service Class UUID", HFILL }
}
};
static gint *ett[] = {
&ett_bthci_cmd,
&ett_opcode,
&ett_eir_subtree,
&ett_eir_struct_subtree
};
proto_bthci_cmd = proto_register_protocol("Bluetooth HCI Command", "HCI_CMD", "bthci_cmd");
register_dissector("bthci_cmd", dissect_bthci_cmd, proto_bthci_cmd);
proto_register_field_array(proto_bthci_cmd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bthci_cmd(void)
{
dissector_handle_t bthci_cmd_handle;
bthci_cmd_handle = find_dissector("bthci_cmd");
dissector_add_uint("hci_h4.type", HCI_H4_TYPE_CMD, bthci_cmd_handle);
dissector_add_uint("hci_h1.type", BTHCI_CHANNEL_COMMAND, bthci_cmd_handle);
}
