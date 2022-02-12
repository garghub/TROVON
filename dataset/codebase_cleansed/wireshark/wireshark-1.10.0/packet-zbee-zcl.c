static void dissect_zbee_zcl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *zcl_tree = NULL;
proto_tree *sub_tree = NULL;
proto_item *proto_root = NULL;
proto_item *ti;
zbee_zcl_packet packet;
guint8 fcf;
guint offset = 0;
memset(&packet, 0, sizeof(zbee_zcl_packet));
if ( tree ) {
proto_root = proto_tree_add_protocol_format(tree, proto_zbee_zcl, tvb, offset,
tvb_length(tvb), "ZigBee Cluster Library Frame");
zcl_tree = proto_item_add_subtree(proto_root, ett_zbee_zcl);
}
col_clear(pinfo->cinfo, COL_INFO);
fcf = tvb_get_guint8(tvb, offset);
packet.frame_type = zbee_get_bit_field(fcf, ZBEE_ZCL_FCF_FRAME_TYPE);
packet.mfr_spec = zbee_get_bit_field(fcf, ZBEE_ZCL_FCF_MFR_SPEC);
packet.direction = zbee_get_bit_field(fcf, ZBEE_ZCL_FCF_DIRECTION);
packet.disable_default_resp = zbee_get_bit_field(fcf, ZBEE_ZCL_FCF_DISABLE_DEFAULT_RESP);
if ( tree ) {
ti = proto_tree_add_text(zcl_tree, tvb, offset, sizeof(guint8),
"Frame Control Field: %s (0x%02x)",
val_to_str_const(packet.frame_type, zbee_zcl_frame_types, "Unknown"), fcf);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_fcf);
proto_tree_add_uint(sub_tree, hf_zbee_zcl_fcf_frame_type, tvb, offset, sizeof(guint8),
fcf & ZBEE_ZCL_FCF_FRAME_TYPE);
proto_tree_add_boolean(sub_tree, hf_zbee_zcl_fcf_mfr_spec, tvb, offset,
sizeof(guint8), fcf & ZBEE_ZCL_FCF_MFR_SPEC);
proto_tree_add_boolean(sub_tree, hf_zbee_zcl_fcf_dir, tvb, offset, sizeof(guint8),
fcf & ZBEE_ZCL_FCF_DIRECTION);
proto_tree_add_boolean(sub_tree, hf_zbee_zcl_fcf_disable_default_resp, tvb, offset,
sizeof(guint8), fcf & ZBEE_ZCL_FCF_DISABLE_DEFAULT_RESP);
}
offset += (int)sizeof(guint8);
if (packet.mfr_spec) {
packet.mfr_code = tvb_get_letohs(tvb, offset);
if ( tree ) {
proto_tree_add_uint(zcl_tree, hf_zbee_zcl_mfr_code, tvb, offset, (int)sizeof(guint16),
packet.mfr_code);
proto_item_append_text(proto_root, ", Mfr: %s (0x%04x)",
val_to_str_ext_const(packet.mfr_code, &zbee_mfr_code_names_ext, "Unknown"),
packet.mfr_code);
}
offset += (int)sizeof(guint16);
}
packet.tran_seqno = tvb_get_guint8(tvb, offset);
if ( zcl_tree ) {
proto_tree_add_uint(zcl_tree, hf_zbee_zcl_tran_seqno, tvb, offset, (int)sizeof(guint8),
packet.tran_seqno);
}
offset += (int)sizeof(guint8);
packet.cmd_id = tvb_get_guint8(tvb, offset);
if ( packet.frame_type == ZBEE_ZCL_FCF_PROFILE_WIDE ) {
if ( tree ) {
proto_item_append_text(proto_root, ", Command: %s, Seq: %u",
val_to_str_ext_const(packet.cmd_id, &zbee_zcl_cmd_names_ext, "Unknown Command"),
packet.tran_seqno);
}
if ( check_col(pinfo->cinfo, COL_INFO) ) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_ext_const(packet.cmd_id, &zbee_zcl_cmd_names_ext, "Unknown Command"),
packet.tran_seqno);
}
if ( zcl_tree ) {
proto_tree_add_uint(zcl_tree, hf_zbee_zcl_cmd_id, tvb, offset, (int)sizeof(guint8),
packet.cmd_id);
}
offset += (int)sizeof(guint8);
} else {
if ( tree ) {
proto_item_append_text(proto_root, ", Cluster-specific Command: 0x%02x, Seq: %u",
packet.cmd_id, packet.tran_seqno);
}
if ( check_col(pinfo->cinfo, COL_INFO) ) {
col_append_fstr(pinfo->cinfo, COL_INFO, "Command: 0x%02x, Seq: %u",
packet.cmd_id, packet.tran_seqno);
}
if ( zcl_tree ) {
proto_tree_add_uint(zcl_tree, hf_zbee_zcl_cs_cmd_id, tvb, offset, (int)sizeof(guint8),
packet.cmd_id);
}
offset += (int)sizeof(guint8);
zcl_dump_data(tvb, offset, pinfo, zcl_tree);
return;
}
if ( zcl_tree ) {
switch ( packet.cmd_id ) {
case ZBEE_ZCL_CMD_READ_ATTR:
dissect_zcl_read_attr(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_READ_ATTR_RESP:
dissect_zcl_read_attr_resp(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_WRITE_ATTR:
case ZBEE_ZCL_CMD_WRITE_ATTR_UNDIVIDED:
case ZBEE_ZCL_CMD_WRITE_ATTR_NO_RESP:
case ZBEE_ZCL_CMD_REPORT_ATTR:
dissect_zcl_write_attr(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_WRITE_ATTR_RESP:
dissect_zcl_write_attr_resp(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_CONFIG_REPORT:
dissect_zcl_config_report(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_CONFIG_REPORT_RESP:
dissect_zcl_config_report_resp(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_READ_REPORT_CONFIG:
dissect_zcl_read_report_config(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_READ_REPORT_CONFIG_RESP:
dissect_zcl_read_report_config_resp(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_DEFAULT_RESP:
dissect_zcl_default_resp(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_DISCOVER_ATTR:
dissect_zcl_discover_attr(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_DISCOVER_ATTR_RESP:
dissect_zcl_discover_attr_resp(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_READ_ATTR_STRUCT:
case ZBEE_ZCL_CMD_WRITE_ATTR_STRUCT:
case ZBEE_ZCL_CMD_WRITE_ATTR_STRUCT_RESP:
default:
zcl_dump_data(tvb, offset, pinfo, zcl_tree);
break;
}
}
return;
}
static void dissect_zcl_read_attr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
guint tvb_len;
tvb_len = tvb_length(tvb);
while ( *offset < tvb_len ) {
dissect_zcl_attr_id(tvb, tree, offset);
}
return;
}
static void dissect_zcl_read_attr_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
tvb_len = tvb_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
ti = proto_tree_add_text(tree, tvb, *offset, 0, "Status Record");
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_attr[i]);
i++;
dissect_zcl_attr_id(tvb, sub_tree, offset);
if ( dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_status)
== ZBEE_ZCL_STAT_SUCCESS ) {
dissect_zcl_attr_data_type_val(tvb, sub_tree, offset);
}
}
return;
}
static void dissect_zcl_write_attr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
tvb_len = tvb_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
ti = proto_tree_add_text(tree, tvb, *offset, 0, "Attribute Field");
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_attr[i]);
i++;
dissect_zcl_attr_id(tvb, sub_tree, offset);
dissect_zcl_attr_data_type_val(tvb, sub_tree, offset);
}
return;
}
static void dissect_zcl_write_attr_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
tvb_len = tvb_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
ti = proto_tree_add_text(tree, tvb, *offset, 0, "Status Record");
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_attr[i]);
i++;
if ( dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_status) !=
ZBEE_ZCL_STAT_SUCCESS ) {
dissect_zcl_attr_id(tvb, sub_tree, offset);
}
}
return;
}
static void dissect_zcl_read_report_config_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint *offset)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
guint data_type;
guint attr_status;
guint attr_dir;
tvb_len = tvb_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
ti = proto_tree_add_text(tree, tvb, *offset, 3, "Reporting Configuration Record");
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_attr[i]);
i++;
attr_status = dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_status);
attr_dir = dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dir);
dissect_zcl_attr_id(tvb, sub_tree, offset);
if ( attr_status == ZBEE_ZCL_STAT_SUCCESS ) {
if ( attr_dir == ZBEE_ZCL_DIR_REPORTED ) {
data_type = dissect_zcl_attr_uint8(tvb, sub_tree, offset,
&hf_zbee_zcl_attr_data_type);
dissect_zcl_attr_uint16(tvb, sub_tree, offset, &hf_zbee_zcl_attr_minint);
dissect_zcl_attr_uint16(tvb, sub_tree, offset, &hf_zbee_zcl_attr_maxint);
if ( IS_ANALOG_SUBTYPE(data_type) ) {
dissect_zcl_attr_data(tvb, sub_tree, offset, data_type);
}
} else {
dissect_zcl_attr_uint16(tvb, sub_tree, offset, &hf_zbee_zcl_attr_timeout);
}
}
}
return;
}
static void dissect_zcl_config_report(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
guint data_type;
tvb_len = tvb_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
ti = proto_tree_add_text(tree, tvb, *offset, 3, "Reporting Configuration Record");
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_attr[i]);
i++;
if ( dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dir)
== ZBEE_ZCL_DIR_REPORTED ) {
dissect_zcl_attr_id(tvb, sub_tree, offset);
data_type = dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_data_type);
dissect_zcl_attr_uint16(tvb, sub_tree, offset, &hf_zbee_zcl_attr_minint);
dissect_zcl_attr_uint16(tvb, sub_tree, offset, &hf_zbee_zcl_attr_maxint);
if ( IS_ANALOG_SUBTYPE(data_type) ) {
dissect_zcl_attr_data(tvb, sub_tree, offset, data_type);
}
} else {
dissect_zcl_attr_id(tvb, sub_tree, offset);
dissect_zcl_attr_uint16(tvb, sub_tree, offset, &hf_zbee_zcl_attr_timeout);
}
}
return;
}
static void dissect_zcl_config_report_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint *offset)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
tvb_len = tvb_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
ti = proto_tree_add_text(tree, tvb, *offset, 3, "Attribute Status Record");
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_attr[i]);
i++;
if ( dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_status) !=
ZBEE_ZCL_STAT_SUCCESS ) {
dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dir);
dissect_zcl_attr_id(tvb, sub_tree, offset);
}
}
return;
}
static void dissect_zcl_read_report_config(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint *offset)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
tvb_len = tvb_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
ti = proto_tree_add_text(tree, tvb, *offset, 3, "Attribute Status Record");
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_attr[i]);
i++;
dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dir);
dissect_zcl_attr_id(tvb, sub_tree, offset);
}
return;
}
static void dissect_zcl_default_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
guint cmd_id;
cmd_id = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_cmd_id, tvb, *offset, (int)sizeof(guint8), cmd_id);
*offset += (int)sizeof(guint8);
dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_status);
return;
}
static void dissect_zcl_discover_attr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
dissect_zcl_attr_uint16(tvb, tree, offset, &hf_zbee_zcl_attr_start);
dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_maxnum);
return;
}
static void dissect_zcl_discover_attr_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint *offset)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dis);
tvb_len = tvb_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
ti = proto_tree_add_text(tree, tvb, *offset, 3, "Attribute Status Record");
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_attr[i]);
i++;
dissect_zcl_attr_id(tvb, sub_tree, offset);
dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_data_type);
}
return;
}
static void dissect_zcl_attr_id(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint16 attr_id;
attr_id = tvb_get_letohs(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_id, tvb, *offset, (int)sizeof(guint16),
attr_id);
*offset += (int)sizeof(guint16);
return;
}
static void dissect_zcl_attr_data_type_val(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
dissect_zcl_attr_data(tvb, tree, offset,
dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_data_type) );
return;
}
static void dissect_zcl_attr_data(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint data_type)
{
guint attr_uint;
gint attr_int;
guint8 *attr_string;
guint8 attr_uint8[4];
guint8 elements_type;
guint16 elements_num;
gfloat attr_float;
gdouble attr_double;
nstime_t attr_time;
switch ( data_type ) {
case ZBEE_ZCL_NO_DATA:
break;
case ZBEE_ZCL_8_BIT_DATA:
case ZBEE_ZCL_8_BIT_BITMAP:
dissect_zcl_attr_bytes(tvb, tree, offset, 1);
break;
case ZBEE_ZCL_8_BIT_UINT:
case ZBEE_ZCL_8_BIT_ENUM:
attr_uint = tvb_get_guint8(tvb, *offset);
proto_item_append_text(tree, ", %s: %u",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_uint8, tvb, *offset, (int)sizeof(guint8),
attr_uint);
*offset += (int)sizeof(guint8);
break;
case ZBEE_ZCL_8_BIT_INT:
attr_int = (gint8)tvb_get_guint8(tvb, *offset);
proto_item_append_text(tree, ", %s: %-d",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_int);
proto_tree_add_int(tree, hf_zbee_zcl_attr_int8, tvb, *offset, (int)sizeof(gint8),
(gint)attr_int);
*offset += (int)sizeof(gint8);
break;
case ZBEE_ZCL_BOOLEAN:
attr_uint = tvb_get_guint8(tvb, *offset);
proto_item_append_text(tree, ", %s: 0x%02x",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_item(tree, hf_zbee_zcl_attr_boolean, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += (int)sizeof(guint8);
break;
case ZBEE_ZCL_16_BIT_DATA:
case ZBEE_ZCL_16_BIT_BITMAP:
dissect_zcl_attr_bytes(tvb, tree, offset, 2);
break;
case ZBEE_ZCL_16_BIT_UINT:
case ZBEE_ZCL_16_BIT_ENUM:
attr_uint = tvb_get_letohs(tvb, *offset);
proto_item_append_text(tree, ", %s: %u",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_uint16, tvb, *offset, (int)sizeof(guint16),
attr_uint);
*offset += (int)sizeof(guint16);
break;
case ZBEE_ZCL_16_BIT_INT:
attr_int = (gint16)tvb_get_letohs(tvb, *offset);
proto_item_append_text(tree, ", %s: %-d",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_int);
proto_tree_add_int(tree, hf_zbee_zcl_attr_int16, tvb, *offset, (int)sizeof(gint16),
attr_int);
*offset += (int)sizeof(gint16);
break;
case ZBEE_ZCL_24_BIT_DATA:
case ZBEE_ZCL_24_BIT_BITMAP:
dissect_zcl_attr_bytes(tvb, tree, offset, 3);
break;
case ZBEE_ZCL_24_BIT_UINT:
attr_uint = tvb_get_letoh24(tvb, *offset);
proto_item_append_text(tree, ", %s: %u",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_uint24, tvb, *offset, 3,
attr_uint);
*offset += 3;
break;
case ZBEE_ZCL_24_BIT_INT:
attr_int = (gint)tvb_get_letoh24(tvb, *offset);
if (attr_int & INT24_SIGN_BITS) attr_int |= INT24_SIGN_BITS;
proto_item_append_text(tree, ", %s: %-d",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_int);
proto_tree_add_int(tree, hf_zbee_zcl_attr_int24, tvb, *offset, 3,
attr_int);
*offset += 3;
break;
case ZBEE_ZCL_32_BIT_DATA:
case ZBEE_ZCL_32_BIT_BITMAP:
dissect_zcl_attr_bytes(tvb, tree, offset, 4);
break;
case ZBEE_ZCL_32_BIT_UINT:
attr_uint = tvb_get_letohl(tvb, *offset);
proto_item_append_text(tree, ", %s: %u",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_uint32, tvb, *offset, (int)sizeof(guint),
attr_uint);
*offset += (int)sizeof(guint);
break;
case ZBEE_ZCL_32_BIT_INT:
attr_int = (gint)tvb_get_letohl(tvb, *offset);
proto_item_append_text(tree, ", %s: %-d",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_int);
proto_tree_add_int(tree, hf_zbee_zcl_attr_int32, tvb, *offset, (int)sizeof(gint),
attr_int);
*offset += (int)sizeof(gint);
break;
case ZBEE_ZCL_40_BIT_DATA:
case ZBEE_ZCL_40_BIT_BITMAP:
dissect_zcl_attr_bytes(tvb, tree, offset, 5);
break;
case ZBEE_ZCL_40_BIT_UINT:
dissect_zcl_big_int(tvb, tree, offset, 5, FALSE);
break;
case ZBEE_ZCL_40_BIT_INT:
dissect_zcl_big_int(tvb, tree, offset, 5, TRUE);
break;
case ZBEE_ZCL_48_BIT_DATA:
case ZBEE_ZCL_48_BIT_BITMAP:
dissect_zcl_attr_bytes(tvb, tree, offset, 6);
break;
case ZBEE_ZCL_48_BIT_UINT:
dissect_zcl_big_int(tvb, tree, offset, 6, FALSE);
break;
case ZBEE_ZCL_48_BIT_INT:
dissect_zcl_big_int(tvb, tree, offset, 6, TRUE);
break;
case ZBEE_ZCL_56_BIT_DATA:
case ZBEE_ZCL_56_BIT_BITMAP:
dissect_zcl_attr_bytes(tvb, tree, offset, 7);
break;
case ZBEE_ZCL_56_BIT_UINT:
dissect_zcl_big_int(tvb, tree, offset, 7, FALSE);
break;
case ZBEE_ZCL_56_BIT_INT:
dissect_zcl_big_int(tvb, tree, offset, 7, TRUE);
break;
case ZBEE_ZCL_64_BIT_DATA:
case ZBEE_ZCL_64_BIT_BITMAP:
dissect_zcl_attr_bytes(tvb, tree, offset, 8);
break;
case ZBEE_ZCL_64_BIT_UINT:
dissect_zcl_big_int(tvb, tree, offset, 8, FALSE);
break;
case ZBEE_ZCL_64_BIT_INT:
dissect_zcl_big_int(tvb, tree, offset, 8, TRUE);
break;
case ZBEE_ZCL_SEMI_FLOAT:
dissect_zcl_attr_bytes(tvb, tree, offset, 2);
break;
case ZBEE_ZCL_SINGLE_FLOAT:
attr_float = tvb_get_letohieee_float(tvb, *offset);
proto_item_append_text(tree, ", %s: %g",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_float);
proto_tree_add_item(tree, hf_zbee_zcl_attr_float, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
break;
case ZBEE_ZCL_DOUBLE_FLOAT:
attr_double = tvb_get_letohieee_double(tvb, *offset);
proto_item_append_text(tree, ", Double: %lg", attr_double);
proto_tree_add_item(tree, hf_zbee_zcl_attr_double, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
break;
case ZBEE_ZCL_OCTET_STRING:
attr_uint = tvb_get_guint8(tvb, *offset);
if (attr_uint == ZBEE_ZCL_INVALID_STR_LENGTH) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_attr_str_len, tvb, *offset, (int)sizeof(guint8),
attr_uint);
*offset += (int)sizeof(guint8);
attr_string = tvb_bytes_to_str_punct(tvb, *offset, attr_uint, ':');
proto_item_append_text(tree, ", Octets: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_attr_ostr, tvb, *offset, attr_uint,
attr_string);
*offset += attr_uint;
break;
case ZBEE_ZCL_CHAR_STRING:
attr_uint = tvb_get_guint8(tvb, *offset);
if (attr_uint == ZBEE_ZCL_INVALID_STR_LENGTH) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_attr_str_len, tvb, *offset, (int)sizeof(guint8),
attr_uint);
*offset += (int)sizeof(guint8);
attr_string = tvb_get_ephemeral_string(tvb, *offset, attr_uint);
proto_item_append_text(tree, ", String: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_attr_str, tvb, *offset, attr_uint, attr_string);
*offset += attr_uint;
break;
case ZBEE_ZCL_LONG_OCTET_STRING:
attr_uint = tvb_get_letohs(tvb, *offset);
if (attr_uint == ZBEE_ZCL_INVALID_LONG_STR_LENGTH) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_attr_str_len, tvb, *offset, (int)sizeof(guint16), attr_uint);
*offset += (int)sizeof(guint16);
attr_string = tvb_bytes_to_str_punct(tvb, *offset, attr_uint, ':');
proto_item_append_text(tree, ", Octets: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_attr_ostr, tvb, *offset, attr_uint, attr_string);
*offset += attr_uint;
break;
case ZBEE_ZCL_LONG_CHAR_STRING:
attr_uint = tvb_get_letohs(tvb, *offset);
if (attr_uint == ZBEE_ZCL_INVALID_LONG_STR_LENGTH) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_attr_str_len, tvb, *offset, (int)sizeof(guint16), attr_uint);
*offset += (int)sizeof(guint16);
attr_string = tvb_get_ephemeral_string(tvb, *offset, attr_uint);
proto_item_append_text(tree, ", String: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_attr_str, tvb, *offset, attr_uint, attr_string);
*offset += attr_uint;
break;
case ZBEE_ZCL_ARRAY:
elements_type = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_array_elements_type, tvb, *offset, (int)sizeof(guint8), elements_type);
*offset += (int)sizeof(guint8);
elements_num = tvb_get_letohs(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_array_elements_num, tvb, *offset, (int)sizeof(guint16), elements_num);
*offset += (int)sizeof(guint16);
dissect_zcl_array_type(tvb, tree, offset, elements_type, elements_num);
break;
case ZBEE_ZCL_SET:
break;
case ZBEE_ZCL_STRUCT:
break;
case ZBEE_ZCL_BAG:
break;
case ZBEE_ZCL_TIME:
attr_uint8[0] = dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_hours);
attr_uint8[1] = dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_mins);
attr_uint8[2] = dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_secs);
attr_uint8[3] = dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_csecs);
proto_item_append_text(tree, ", Time: %u:%u:%u.%u",
attr_uint8[0], attr_uint8[1], attr_uint8[2], attr_uint8[3]);
break;
case ZBEE_ZCL_DATE:
attr_uint8[0] = dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_yy);
attr_uint8[1] = dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_mm);
attr_uint8[2] = dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_md);
attr_uint8[3] = dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_wd);
proto_item_append_text(tree, ", Date: %u/%u/%u %s",
attr_uint8[0]+1900, attr_uint8[1], attr_uint8[2],
val_to_str_ext_const(attr_uint8[3], &zbee_zcl_wd_names_ext, "Invalid Weekday") );
break;
case ZBEE_ZCL_UTC:
attr_time.secs = (guint32)tvb_get_letohl(tvb, *offset);
attr_time.secs += ZBEE_ZCL_NSTIME_UTC_OFFSET;
attr_time.nsecs = 0;
proto_item_append_text(tree, ", %s",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved") );
proto_tree_add_time(tree, hf_zbee_zcl_attr_utc, tvb, *offset, (int)sizeof(guint),
&attr_time);
*offset += (int)sizeof(guint32);
break;
case ZBEE_ZCL_CLUSTER_ID:
dissect_zcl_attr_uint16(tvb, tree, offset, &hf_zbee_zcl_attr_cid);
break;
case ZBEE_ZCL_ATTR_ID:
dissect_zcl_attr_id(tvb, tree, offset);
break;
case ZBEE_ZCL_BACNET_OID:
dissect_zcl_attr_bytes(tvb, tree, offset, 4);
break;
case ZBEE_ZCL_IEEE_ADDR:
dissect_zcl_attr_bytes(tvb, tree, offset, 8);
break;
case ZBEE_ZCL_SECURITY_KEY:
dissect_zcl_attr_bytes(tvb, tree, offset, 16);
break;
default:
break;
}
return;
}
static void dissect_zcl_big_int(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint length,
gboolean signed_flag)
{
guint64 attr_uint64;
attr_uint64 = tvb_get_letohi(tvb, *offset, length, signed_flag);
if ( signed_flag ) {
proto_item_append_text(tree, ", Int: %" G_GINT64_MODIFIER "d", (gint64)attr_uint64);
proto_tree_add_int64(tree, hf_zbee_zcl_attr_int64, tvb, *offset, length,
(gint64)attr_uint64);
} else {
proto_item_append_text(tree, ", Uint: %" G_GINT64_MODIFIER "u", attr_uint64);
proto_tree_add_uint64(tree, hf_zbee_zcl_attr_uint64, tvb, *offset, length,
attr_uint64);
}
*offset += length;
return;
}
static guint dissect_zcl_attr_uint8(tvbuff_t *tvb, proto_tree *tree, guint *offset, int *hf_zbee_zcl)
{
guint attr_uint;
attr_uint = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, *hf_zbee_zcl, tvb, *offset, (int)sizeof(guint8), attr_uint);
(*offset)++;
return attr_uint;
}
static guint dissect_zcl_attr_uint16(tvbuff_t *tvb, proto_tree *tree, guint *offset, int *hf_zbee_zcl)
{
guint attr_uint;
attr_uint = tvb_get_letohs(tvb, *offset);
proto_tree_add_uint(tree, *hf_zbee_zcl, tvb, *offset, (int)sizeof(guint16), attr_uint);
*offset += (int)sizeof(guint16);
return attr_uint;
}
static void dissect_zcl_attr_bytes(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint length)
{
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, length, ENC_NA);
*offset += length;
return;
}
static void
dissect_zcl_array_type(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint8 elements_type, guint16 elements_num)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 1;
tvb_len = tvb_length(tvb);
while ( (*offset < tvb_len) && (i < ZBEE_ZCL_NUM_ARRAY_ELEM_ETT) && (elements_num != 0) ) {
ti = proto_tree_add_text(tree, tvb, *offset, 0, "Element #%d", i);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_array_elements[i]);
dissect_zcl_attr_data(tvb, sub_tree, offset, elements_type);
elements_num--;
i++;
}
return;
}
static void zcl_dump_data(tvbuff_t *tvb, guint offset, packet_info *pinfo, proto_tree *tree)
{
proto_tree *root = proto_tree_get_root(tree);
guint length = tvb_length_remaining(tvb, offset);
tvbuff_t *remainder;
if (length > 0) {
remainder = tvb_new_subset(tvb, offset, length, length);
call_dissector(data_handle, remainder, pinfo, root);
}
}
static guint64 tvb_get_letohi(tvbuff_t *tvb, guint offset, guint length, gboolean signed_flag)
{
guint64 result;
guint shift;
DISSECTOR_ASSERT((length>=1) && (length<=8));
result = 0;
shift = 0;
while ( length-- ) {
result += (guint64)tvb_get_guint8(tvb, offset) << shift;
offset += (int)sizeof(guint8);
shift += 8;
}
if ( signed_flag && (result >> (shift - 1)) ) {
while ( shift < ((int)sizeof(guint64) * 8) ) {
result += (guint64)0xff << shift;
shift += 8;
}
}
return result;
}
void proto_register_zbee_zcl(void)
{
guint i, j;
static const true_false_string tfs_client_server = {
"To Client",
"To Server"
};
static hf_register_info hf[] = {
{ &hf_zbee_zcl_fcf_frame_type,
{ "Frame Type", "zbee_zcl.type", FT_UINT8, BASE_HEX, VALS(zbee_zcl_frame_types),
ZBEE_ZCL_FCF_FRAME_TYPE, NULL, HFILL }},
{ &hf_zbee_zcl_fcf_mfr_spec,
{ "Manufacturer Specific", "zbee_zcl.ms", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_FCF_MFR_SPEC, NULL, HFILL }},
{ &hf_zbee_zcl_fcf_dir,
{ "Direction", "zbee_zcl.dir", FT_BOOLEAN, 8, TFS(&tfs_client_server),
ZBEE_ZCL_FCF_DIRECTION, NULL, HFILL }},
{ &hf_zbee_zcl_fcf_disable_default_resp,
{ "Disable Default Response", "zbee_zcl.ddr", FT_BOOLEAN, 8, NULL,
ZBEE_ZCL_FCF_DISABLE_DEFAULT_RESP, NULL, HFILL }},
{ &hf_zbee_zcl_mfr_code,
{ "Manufacturer Code", "zbee_zcl.cmd.mc", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&zbee_mfr_code_names_ext, 0x0, "Assigned manufacturer code.", HFILL }},
{ &hf_zbee_zcl_tran_seqno,
{ "Sequence Number", "zbee_zcl.cmd.tsn", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_cmd_id,
{ "Command", "zbee_zcl.cmd.id", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &zbee_zcl_cmd_names_ext,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_cs_cmd_id,
{ "Command", "zbee_zcl.cs.cmd.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_cs_cmd_names) ,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_id,
{ "Attribute", "zbee_zcl.attr.id", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_data_type,
{ "Data Type", "zbee_zcl.attr.data.type", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&zbee_zcl_data_type_names_ext, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_boolean,
{ "Boolean", "zbee_zcl.attr.boolean", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0xff,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_uint8,
{ "Uint8", "zbee_zcl.attr.uint8", FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_uint16,
{ "Uint16", "zbee_zcl.attr.uint16", FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_uint24,
{ "Uint24", "zbee_zcl.attr.uint24", FT_UINT24, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_uint32,
{ "Uint32", "zbee_zcl.attr.uint32", FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_uint64,
{ "Uint64", "zbee_zcl.attr.uint64", FT_UINT64, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_int8,
{ "Int8", "zbee_zcl.attr.int8", FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_int16,
{ "Int16", "zbee_zcl.attr.int16", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_int24,
{ "Int24", "zbee_zcl.attr.int24", FT_INT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_int32,
{ "Int32", "zbee_zcl.attr.int32", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_int64,
{ "Int64", "zbee_zcl.attr.int64", FT_INT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_zbee_zcl_attr_semi,
{ "Semi Float", "zbee_zcl.attr.float", FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_zbee_zcl_attr_float,
{ "Float", "zbee_zcl.attr.float", FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_double,
{ "Double Float", "zbee_zcl.attr.float", FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bytes,
{ "Bytes", "zbee_zcl.attr.bytes", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_minint,
{ "Minimum Interval", "zbee_zcl.attr.minint", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_maxint,
{ "Maximum Interval", "zbee_zcl.attr.maxint", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_timeout,
{ "Timeout", "zbee_zcl.attr.timeout", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_hours,
{ "Hours", "zbee_zcl.attr.hours", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_mins,
{ "Minutes", "zbee_zcl.attr.mins", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_secs,
{ "Seconds", "zbee_zcl.attr.secs", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_csecs,
{ "Centiseconds", "zbee_zcl.attr.csecs", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_yy,
{ "Year", "zbee_zcl.attr.yy", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_mm,
{ "Month", "zbee_zcl.attr.mm", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_md,
{ "Day of Month", "zbee_zcl.attr.md", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_wd,
{ "Day of Week", "zbee_zcl.attr.wd", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_utc,
{ "UTC", "zbee_zcl.attr.utc", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_status,
{ "Status", "zbee_zcl.attr.status", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &zbee_zcl_status_names_ext,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_dir,
{ "Direction", "zbee_zcl.attr.dir", FT_UINT8, BASE_HEX, VALS(zbee_zcl_dir_names),
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_dis,
{ "Discovery", "zbee_zcl.attr.dis", FT_UINT8, BASE_HEX, VALS(zbee_zcl_dis_names),
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_attr_cid,
{ "Cluster", "zbee_zcl.attr.cid", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_start,
{ "Start Attribute", "zbee_zcl.attr.start", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_maxnum,
{ "Maxiumum Number", "zbee_zcl.attr.maxnum", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_str_len,
{ "Length", "zbee_zcl.attr.str.len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_str,
{ "String", "zbee_zcl.attr.str", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_ostr,
{ "Octet String", "zbee_zcl.attr.ostr", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_array_elements_type,
{ "Elements Type", "zbee_zcl.attr.array.elements_type", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&zbee_zcl_data_type_names_ext, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_array_elements_num,
{ "Elements Number", "zbee_zcl.attr.array.elements_num", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
gint *ett[ZBEE_ZCL_NUM_TOTAL_ETT];
ett[0] = &ett_zbee_zcl;
ett[1] = &ett_zbee_zcl_fcf;
j = ZBEE_ZCL_NUM_INDIVIDUAL_ETT;
for ( i = 0; i < ZBEE_ZCL_NUM_ATTR_ETT; i++, j++) {
ett_zbee_zcl_attr[i] = -1;
ett[j] = &ett_zbee_zcl_attr[i];
}
for ( i = 0; i < ZBEE_ZCL_NUM_ARRAY_ELEM_ETT; i++, j++ ) {
ett_zbee_zcl_array_elements[i] = -1;
ett[j] = &ett_zbee_zcl_array_elements[i];
}
proto_zbee_zcl = proto_register_protocol("ZigBee Cluster Library", "ZigBee ZCL", "zbee_zcl");
proto_register_field_array(proto_zbee_zcl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("zbee_zcl", dissect_zbee_zcl, proto_zbee_zcl);
}
void proto_reg_handoff_zbee_zcl(void)
{
dissector_handle_t zbee_zcl_handle;
data_handle = find_dissector("data");
zbee_zcl_handle = find_dissector("zbee_zcl");
dissector_add_uint("zbee.profile", ZBEE_PROFILE_IPM, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_T1, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_HA, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_CBA, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_WSN, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_TA, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_HC, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_SE, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_C4_CL, zbee_zcl_handle);
}
