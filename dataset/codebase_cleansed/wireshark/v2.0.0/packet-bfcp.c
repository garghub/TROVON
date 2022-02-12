static int
dissect_bfcp_attributes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int bfcp_payload_length)
{
proto_item *ti, *item;
proto_tree *bfcp_attr_tree = NULL;
gint attr_start_offset;
gint length;
guint8 attribute_type;
gint read_attr = 0;
guint8 first_byte, pad_len;
while ((tvb_reported_length_remaining(tvb, offset) >= 2) &&
((bfcp_payload_length - read_attr) >= 2))
{
attr_start_offset = offset;
first_byte = tvb_get_guint8(tvb, offset);
if (first_byte == 0){
read_attr++;
continue;
}
ti = proto_tree_add_item(tree, hf_bfcp_attribute_types, tvb, offset, 1, ENC_BIG_ENDIAN);
bfcp_attr_tree = proto_item_add_subtree(ti, ett_bfcp_attr);
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_attribute_types_m_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
attribute_type = (first_byte & 0xFE) >> 1;
offset++;
item = proto_tree_add_item(bfcp_attr_tree, hf_bfcp_attribute_length, tvb, offset, 1, ENC_BIG_ENDIAN);
length = tvb_get_guint8(tvb, offset);
offset++;
pad_len = 0;
switch(attribute_type){
case 1:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_beneficiary_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
case 2:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_floor_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
case 3:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_floor_request_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
case 4:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_priority, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
case 5:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_request_status, tvb, offset,1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_queue_pos, tvb, offset,1, ENC_BIG_ENDIAN);
offset++;
break;
case 6:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_error_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(length>3){
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_error_specific_details, tvb, offset, length-3, ENC_NA);
}
offset = offset + length-3;
pad_len = length & 0x03;
if(pad_len != 0){
pad_len = 4 - pad_len;
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_padding, tvb, offset, pad_len, ENC_NA);
}
offset = offset + pad_len;
break;
case 7:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_error_info_text, tvb, offset, length-3, ENC_ASCII|ENC_NA);
offset = offset + length-3;
pad_len = length & 0x03;
if(pad_len != 0){
pad_len = 4 - pad_len;
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_padding, tvb, offset, pad_len, ENC_NA);
}
offset = offset + pad_len;
break;
case 8:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_part_prov_info_text, tvb, offset, length-3, ENC_ASCII|ENC_NA);
offset = offset + length-3;
pad_len = length & 0x03;
if(pad_len != 0){
pad_len = 4 - pad_len;
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_padding, tvb, offset, pad_len, ENC_NA);
}
offset = offset + pad_len;
break;
case 9:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_status_info_text, tvb, offset, length-3, ENC_ASCII|ENC_NA);
offset = offset + length-3;
pad_len = length & 0x03;
if(pad_len != 0){
pad_len = 4 - pad_len;
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_padding, tvb, offset, pad_len, ENC_NA);
}
offset = offset + pad_len;
break;
case 10:
while(offset < (attr_start_offset+length)){
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_supp_attr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
}
pad_len = length & 0x03;
if(pad_len != 0){
pad_len = 4 - pad_len;
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_padding, tvb, offset, pad_len, ENC_NA);
}
offset = offset + pad_len;
break;
case 11:
while(offset < (attr_start_offset+length)){
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_supp_prim, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
}
pad_len = length & 0x03;
if(pad_len != 0){
pad_len = 4 - pad_len;
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_padding, tvb, offset, pad_len, ENC_NA);
}
offset = offset + pad_len;
break;
case 12:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_user_disp_name, tvb, offset, length-3, ENC_ASCII|ENC_NA);
offset = offset + length-3;
pad_len = length & 0x03;
if(pad_len != 0){
pad_len = 4 - pad_len;
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_padding, tvb, offset, pad_len, ENC_NA);
}
offset = offset + pad_len;
break;
case 13:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_user_uri, tvb, offset, length-3, ENC_ASCII|ENC_NA);
offset = offset + length-3;
pad_len = length & 0x03;
if(pad_len != 0){
pad_len = 4 - pad_len;
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_padding, tvb, offset, pad_len, ENC_NA);
}
offset = offset + pad_len;
break;
case 14:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_beneficiary_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset = dissect_bfcp_attributes(tvb, pinfo, bfcp_attr_tree, offset, length -4);
break;
case 15:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_floor_request_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset = dissect_bfcp_attributes(tvb, pinfo, bfcp_attr_tree, offset, length -4);
break;
case 16:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_req_by_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset = dissect_bfcp_attributes(tvb, pinfo, bfcp_attr_tree, offset, length -4);
break;
case 17:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_floor_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset = dissect_bfcp_attributes(tvb, pinfo, bfcp_attr_tree, offset, length -4);
break;
case 18:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_floor_request_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset = dissect_bfcp_attributes(tvb, pinfo, bfcp_attr_tree, offset, length -4);
break;
default:
proto_tree_add_item(bfcp_attr_tree, hf_bfcp_payload, tvb, offset, length-2, ENC_NA);
offset = offset + length - 2;
break;
}
if ((length+pad_len) < (offset - attr_start_offset)){
expert_add_info_format(pinfo, item, &ei_bfcp_attribute_length_too_small,
"Attribute length is too small (%d bytes)", length);
break;
}
read_attr = read_attr + length;
}
return offset;
}
static void
dissect_bfcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 primitive;
const gchar *str;
gint bfcp_payload_length;
proto_tree *bfcp_tree = NULL;
primitive = tvb_get_guint8(tvb, 1);
str = try_val_to_str(primitive, map_bfcp_primitive);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BFCP");
col_add_str(pinfo->cinfo, COL_INFO, str);
if (tree) {
proto_item *ti;
ti = proto_tree_add_item(tree, proto_bfcp, tvb, 0, -1, ENC_NA);
bfcp_tree = proto_item_add_subtree(ti, ett_bfcp);
proto_tree_add_item(bfcp_tree, hf_bfcp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bfcp_tree, hf_bfcp_hdr_r_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bfcp_tree, hf_bfcp_hdr_f_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(bfcp_tree, hf_bfcp_primitive, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(bfcp_tree, hf_bfcp_payload_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(bfcp_tree, hf_bfcp_conference_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(bfcp_tree, hf_bfcp_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(bfcp_tree, hf_bfcp_user_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
bfcp_payload_length = tvb_get_ntohs(tvb,
BFCP_OFFSET_PAYLOAD_LENGTH) * 4;
dissect_bfcp_attributes(tvb, pinfo, bfcp_tree, offset, bfcp_payload_length);
}
}
static gboolean
dissect_bfcp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 primitive;
guint8 first_byte;
const gchar *str;
if (tvb_captured_length(tvb) < 12)
return FALSE;
first_byte = tvb_get_guint8(tvb, 0);
if ((first_byte != 0x20) && (first_byte != 0x30))
return FALSE;
primitive = tvb_get_guint8(tvb, 1);
if ((primitive < 1) || (primitive > 18))
return FALSE;
str = try_val_to_str(primitive, map_bfcp_primitive);
if (NULL == str)
return FALSE;
dissect_bfcp(tvb, pinfo, tree);
return TRUE;
}
void proto_register_bfcp(void)
{
module_t *bfcp_module;
expert_module_t* expert_bfcp;
static hf_register_info hf[] = {
{
&hf_bfcp_version,
{ "Version(ver)", "bfcp.ver",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{
&hf_bfcp_hdr_r_bit,
{ "Transaction Responder (R)", "bfcp.hdr_r_bit",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{
&hf_bfcp_hdr_f_bit,
{ "Fragmentation (F)", "bfcp.hdr_f_bit",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{
&hf_bfcp_primitive,
{ "Primitive", "bfcp.primitive",
FT_UINT8, BASE_DEC, VALS(map_bfcp_primitive), 0x0,
NULL, HFILL }
},
{
&hf_bfcp_payload_length,
{ "Payload Length", "bfcp.payload_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_conference_id,
{ "Conference ID", "bfcp.conference_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_transaction_id,
{ "Transaction ID", "bfcp.transaction_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_user_id,
{ "User ID", "bfcp.user_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_payload,
{ "Payload", "bfcp.payload",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL,
HFILL }
},
{
&hf_bfcp_attribute_types,
{ "Attribute Type", "bfcp.attribute_type",
FT_UINT8, BASE_DEC, VALS(map_bfcp_attribute_types), 0xFE,
NULL, HFILL }
},
{
&hf_bfcp_attribute_types_m_bit,
{ "Mandatory bit(M)", "bfcp.attribute_types_m_bit",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{
&hf_bfcp_attribute_length,
{ "Attribute Length", "bfcp.attribute_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_beneficiary_id,
{ "BENEFICIARY-ID", "bfcp.beneficiary_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_floor_id,
{ "FLOOR-ID", "bfcp.floor_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_floor_request_id,
{ "FLOOR-REQUEST-ID", "bfcp.floorrequest_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_priority,
{ "FLOOR-REQUEST-ID", "bfcp.priority",
FT_UINT16, BASE_DEC, NULL, 0xe000,
NULL, HFILL }
},
{
&hf_bfcp_request_status,
{ "Request Status", "bfcp.request_status",
FT_UINT8, BASE_DEC, VALS(map_bfcp_request_status), 0x0,
NULL, HFILL }
},
{
&hf_bfcp_queue_pos,
{ "Queue Position", "bfcp.queue_pos",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_error_code,
{ "Error Code", "bfcp.error_code",
FT_UINT8, BASE_DEC, VALS(bfcp_error_code_valuse), 0x0,
NULL, HFILL }
},
{
&hf_bfcp_error_info_text,
{ "Text", "bfcp.error_info_text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_part_prov_info_text,
{ "Text", "bfcp.part_prov_info_text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_status_info_text,
{ "Text", "bfcp.status_info_text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_supp_attr,
{ "Supported Attribute", "bfcp.supp_attr",
FT_UINT8, BASE_DEC, VALS(map_bfcp_attribute_types), 0xFE,
NULL, HFILL }
},
{
&hf_bfcp_supp_prim,
{ "Supported Primitive", "bfcp.supp_primitive",
FT_UINT8, BASE_DEC, VALS(map_bfcp_primitive), 0x0,
NULL, HFILL }
},
{
&hf_bfcp_user_disp_name,
{ "Name", "bfcp.user_disp_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_user_uri,
{ "URI", "bfcp.user_uri",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_req_by_id,
{ "Requested-by ID", "bfcp.req_by_i",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_padding,
{ "Padding", "bfcp.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{
&hf_bfcp_error_specific_details,
{ "Error Specific Details", "bfcp.error_specific_details",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_bfcp,
&ett_bfcp_attr,
};
static ei_register_info ei[] = {
{ &ei_bfcp_attribute_length_too_small, { "bfcp.attribute_length.too_small", PI_MALFORMED, PI_ERROR, "Attribute length is too small", EXPFILL }},
};
proto_bfcp = proto_register_protocol("Binary Floor Control Protocol",
"BFCP", "bfcp");
bfcp_handle = register_dissector("bfcp", dissect_bfcp, proto_bfcp);
bfcp_module = prefs_register_protocol(proto_bfcp,
proto_reg_handoff_bfcp);
prefs_register_obsolete_preference(bfcp_module, "enable");
proto_register_field_array(proto_bfcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_bfcp = expert_register_protocol(proto_bfcp);
expert_register_field_array(expert_bfcp, ei, array_length(ei));
}
void proto_reg_handoff_bfcp(void)
{
static gboolean prefs_initialized = FALSE;
if (!prefs_initialized)
{
heur_dissector_add("tcp", dissect_bfcp_heur, "BFCP over TCP", "bfcp_tcp", proto_bfcp, HEURISTIC_DISABLE);
heur_dissector_add("udp", dissect_bfcp_heur, "BFCP over UDP", "bfcp_udp", proto_bfcp, HEURISTIC_DISABLE);
dissector_add_for_decode_as("tcp.port", bfcp_handle);
dissector_add_for_decode_as("udp.port", bfcp_handle);
prefs_initialized = TRUE;
}
}
