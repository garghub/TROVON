static int dissect_zbee_zcl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tvbuff_t *payload_tvb;
dissector_handle_t cluster_handle;
proto_tree *zcl_tree;
proto_tree *sub_tree = NULL;
proto_item *proto_root;
zbee_nwk_packet *nwk;
zbee_zcl_packet packet;
zbee_zcl_cluster_desc *desc;
guint16 cluster_id;
guint8 fcf;
guint offset = 0;
if (data == NULL)
return 0;
nwk = (zbee_nwk_packet *)data;
memset(&packet, 0, sizeof(zbee_zcl_packet));
cluster_id = zcl_cluster_id = nwk->cluster_id;
cluster_handle = dissector_get_uint_handle(zbee_zcl_dissector_table, cluster_id);
proto_root = proto_tree_add_protocol_format(tree, proto_zbee_zcl, tvb, offset,
-1, "ZigBee Cluster Library Frame");
zcl_tree = proto_item_add_subtree(proto_root, ett_zbee_zcl);
col_clear(pinfo->cinfo, COL_INFO);
fcf = tvb_get_guint8(tvb, offset);
packet.frame_type = zbee_get_bit_field(fcf, ZBEE_ZCL_FCF_FRAME_TYPE);
packet.mfr_spec = zbee_get_bit_field(fcf, ZBEE_ZCL_FCF_MFR_SPEC);
packet.direction = zbee_get_bit_field(fcf, ZBEE_ZCL_FCF_DIRECTION);
packet.disable_default_resp = zbee_get_bit_field(fcf, ZBEE_ZCL_FCF_DISABLE_DEFAULT_RESP);
if ( tree ) {
sub_tree = proto_tree_add_subtree_format(zcl_tree, tvb, offset, 1,
ett_zbee_zcl_fcf, NULL, "Frame Control Field: %s (0x%02x)",
val_to_str_const(packet.frame_type, zbee_zcl_frame_types, "Unknown"), fcf);
proto_tree_add_item(sub_tree, hf_zbee_zcl_fcf_frame_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_fcf_mfr_spec, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_fcf_dir, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_fcf_disable_default_resp, tvb, offset, 1, ENC_NA);
}
offset += 1;
if (packet.mfr_spec) {
packet.mfr_code = tvb_get_letohs(tvb, offset);
if ( tree ) {
proto_tree_add_uint(zcl_tree, hf_zbee_zcl_mfr_code, tvb, offset, 2,
packet.mfr_code);
proto_item_append_text(proto_root, ", Mfr: %s (0x%04x)",
val_to_str_ext_const(packet.mfr_code, &zbee_mfr_code_names_ext, "Unknown"),
packet.mfr_code);
}
offset += 2;
}
packet.tran_seqno = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(zcl_tree, hf_zbee_zcl_tran_seqno, tvb, offset, 1, packet.tran_seqno);
offset += 1;
packet.cmd_id = tvb_get_guint8(tvb, offset);
desc = zbee_zcl_get_cluster_desc(cluster_id);
if (desc != NULL) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s: ", desc->name);
}
if ( packet.frame_type == ZBEE_ZCL_FCF_PROFILE_WIDE ) {
if ( tree ) {
proto_item_append_text(proto_root, ", Command: %s, Seq: %u",
val_to_str_ext_const(packet.cmd_id, &zbee_zcl_cmd_names_ext, "Unknown Command"),
packet.tran_seqno);
}
col_set_str(pinfo->cinfo, COL_INFO, "ZCL: ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_ext_const(packet.cmd_id, &zbee_zcl_cmd_names_ext, "Unknown Command"),
packet.tran_seqno);
proto_tree_add_uint(zcl_tree, hf_zbee_zcl_cmd_id, tvb, offset, 1, packet.cmd_id);
offset += 1;
} else {
payload_tvb = tvb_new_subset_remaining(tvb, offset);
if (cluster_handle != NULL) {
call_dissector_with_data(cluster_handle, payload_tvb, pinfo, zcl_tree, &packet);
return tvb_captured_length(tvb);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "Unknown Command: 0x%02x, Seq: %u", packet.cmd_id,
packet.tran_seqno);
proto_tree_add_uint(zcl_tree, hf_zbee_zcl_cs_cmd_id, tvb, offset, 1, packet.cmd_id);
offset += 1;
}
zcl_dump_data(tvb, offset, pinfo, zcl_tree);
return tvb_captured_length(tvb);
}
if ( zcl_tree ) {
switch ( packet.cmd_id ) {
case ZBEE_ZCL_CMD_READ_ATTR:
dissect_zcl_read_attr(tvb, pinfo, zcl_tree, &offset, cluster_id);
break;
case ZBEE_ZCL_CMD_READ_ATTR_RESP:
dissect_zcl_read_attr_resp(tvb, pinfo, zcl_tree, &offset, cluster_id);
break;
case ZBEE_ZCL_CMD_WRITE_ATTR:
case ZBEE_ZCL_CMD_WRITE_ATTR_UNDIVIDED:
case ZBEE_ZCL_CMD_WRITE_ATTR_NO_RESP:
case ZBEE_ZCL_CMD_REPORT_ATTR:
dissect_zcl_write_attr(tvb, pinfo, zcl_tree, &offset, cluster_id);
break;
case ZBEE_ZCL_CMD_WRITE_ATTR_RESP:
dissect_zcl_write_attr_resp(tvb, pinfo, zcl_tree, &offset, cluster_id);
break;
case ZBEE_ZCL_CMD_CONFIG_REPORT:
dissect_zcl_config_report(tvb, pinfo, zcl_tree, &offset, cluster_id);
break;
case ZBEE_ZCL_CMD_CONFIG_REPORT_RESP:
dissect_zcl_config_report_resp(tvb, pinfo, zcl_tree, &offset, cluster_id);
break;
case ZBEE_ZCL_CMD_READ_REPORT_CONFIG:
dissect_zcl_read_report_config(tvb, pinfo, zcl_tree, &offset, cluster_id);
break;
case ZBEE_ZCL_CMD_READ_REPORT_CONFIG_RESP:
dissect_zcl_read_report_config_resp(tvb, pinfo, zcl_tree, &offset, cluster_id);
break;
case ZBEE_ZCL_CMD_DEFAULT_RESP:
dissect_zcl_default_resp(tvb, pinfo, zcl_tree, &offset, cluster_id, packet.direction);
break;
case ZBEE_ZCL_CMD_DISCOVER_ATTR:
dissect_zcl_discover_attr(tvb, pinfo, zcl_tree, &offset);
break;
case ZBEE_ZCL_CMD_DISCOVER_ATTR_RESP:
dissect_zcl_discover_attr_resp(tvb, pinfo, zcl_tree, &offset, cluster_id);
break;
case ZBEE_ZCL_CMD_READ_ATTR_STRUCT:
case ZBEE_ZCL_CMD_WRITE_ATTR_STRUCT:
case ZBEE_ZCL_CMD_WRITE_ATTR_STRUCT_RESP:
break;
}
}
zcl_dump_data(tvb, offset, pinfo, zcl_tree);
return tvb_captured_length(tvb);
}
void dissect_zcl_read_attr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset, guint16 cluster_id)
{
guint tvb_len;
tvb_len = tvb_captured_length(tvb);
while ( *offset < tvb_len ) {
dissect_zcl_attr_id(tvb, tree, offset, cluster_id);
}
return;
}
void dissect_zcl_read_attr_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset, guint16 cluster_id)
{
proto_tree *sub_tree;
guint tvb_len;
guint i = 0;
guint16 attr_id;
tvb_len = tvb_captured_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 0, ett_zbee_zcl_attr[i], NULL, "Status Record");
i++;
attr_id = tvb_get_letohs(tvb, *offset);
dissect_zcl_attr_id(tvb, sub_tree, offset, cluster_id);
if ( dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_status)
== ZBEE_ZCL_STAT_SUCCESS ) {
dissect_zcl_attr_data_type_val(tvb, sub_tree, offset, attr_id, cluster_id);
}
}
}
void dissect_zcl_write_attr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset, guint16 cluster_id)
{
proto_tree *sub_tree;
guint tvb_len;
guint i = 0;
guint16 attr_id;
tvb_len = tvb_captured_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 0, ett_zbee_zcl_attr[i], NULL, "Attribute Field");
i++;
attr_id = tvb_get_letohs(tvb, *offset);
dissect_zcl_attr_id(tvb, sub_tree, offset, cluster_id);
dissect_zcl_attr_data_type_val(tvb, sub_tree, offset, attr_id, cluster_id);
}
}
static void dissect_zcl_write_attr_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset, guint16 cluster_id)
{
proto_tree *sub_tree;
guint tvb_len;
guint i = 0;
tvb_len = tvb_captured_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 0, ett_zbee_zcl_attr[i], NULL, "Status Record");
i++;
if ( dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_status) !=
ZBEE_ZCL_STAT_SUCCESS ) {
dissect_zcl_attr_id(tvb, sub_tree, offset, cluster_id);
}
}
}
static void dissect_zcl_read_report_config_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint *offset, guint16 cluster_id)
{
proto_tree *sub_tree;
guint tvb_len;
guint i = 0;
guint data_type;
guint attr_status;
guint attr_dir;
guint16 attr_id;
tvb_len = tvb_captured_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 3, ett_zbee_zcl_attr[i], NULL, "Reporting Configuration Record");
i++;
attr_status = dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_status);
attr_dir = dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dir);
attr_id = tvb_get_letohs(tvb, *offset);
dissect_zcl_attr_id(tvb, sub_tree, offset, cluster_id);
if ( attr_status == ZBEE_ZCL_STAT_SUCCESS ) {
if ( attr_dir == ZBEE_ZCL_DIR_REPORTED ) {
data_type = dissect_zcl_attr_uint8(tvb, sub_tree, offset,
&hf_zbee_zcl_attr_data_type);
proto_tree_add_item(tree, hf_zbee_zcl_attr_minint, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
proto_tree_add_item(tree, hf_zbee_zcl_attr_maxint, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
if ( IS_ANALOG_SUBTYPE(data_type) ) {
dissect_zcl_attr_data_general(tvb, sub_tree, offset, attr_id, data_type, cluster_id);
}
} else {
proto_tree_add_item(tree, hf_zbee_zcl_attr_timeout, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
}
}
}
}
static void dissect_zcl_config_report(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset, guint16 cluster_id)
{
proto_tree *sub_tree;
guint tvb_len;
guint i = 0;
guint data_type;
guint16 attr_id;
tvb_len = tvb_captured_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 3, ett_zbee_zcl_attr[i], NULL, "Reporting Configuration Record");
i++;
if ( dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dir)
== ZBEE_ZCL_DIR_REPORTED ) {
attr_id = tvb_get_letohs(tvb, *offset);
dissect_zcl_attr_id(tvb, sub_tree, offset, cluster_id);
data_type = dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_data_type);
proto_tree_add_item(tree, hf_zbee_zcl_attr_minint, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
proto_tree_add_item(tree, hf_zbee_zcl_attr_maxint, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
if ( IS_ANALOG_SUBTYPE(data_type) ) {
dissect_zcl_attr_data_general(tvb, sub_tree, offset, attr_id, data_type, cluster_id);
}
} else {
dissect_zcl_attr_id(tvb, sub_tree, offset, cluster_id);
proto_tree_add_item(tree, hf_zbee_zcl_attr_timeout, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
}
}
}
static void dissect_zcl_config_report_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint *offset, guint16 cluster_id)
{
proto_tree *sub_tree;
guint tvb_len;
guint i = 0;
tvb_len = tvb_captured_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 3, ett_zbee_zcl_attr[i], NULL, "Attribute Status Record");
i++;
if ( dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_status) !=
ZBEE_ZCL_STAT_SUCCESS ) {
dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dir);
dissect_zcl_attr_id(tvb, sub_tree, offset, cluster_id);
}
}
}
static void dissect_zcl_read_report_config(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint *offset, guint16 cluster_id)
{
proto_tree *sub_tree;
guint tvb_len;
guint i = 0;
tvb_len = tvb_captured_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 3, ett_zbee_zcl_attr[i], NULL, "Attribute Status Record");
i++;
dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dir);
dissect_zcl_attr_id(tvb, sub_tree, offset, cluster_id);
}
}
static void dissect_zcl_default_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint *offset, guint16 cluster_id, guint8 dir)
{
zbee_zcl_cluster_desc *desc;
int hf_cmd_id = hf_zbee_zcl_cs_cmd_id;
desc = zbee_zcl_get_cluster_desc(cluster_id);
if (dir == ZBEE_ZCL_FCF_TO_SERVER) {
if (desc && (desc->hf_cmd_tx_id >= 0)) hf_cmd_id = desc->hf_cmd_tx_id;
} else {
if (desc && (desc->hf_cmd_rx_id >= 0)) hf_cmd_id = desc->hf_cmd_rx_id;
}
proto_tree_add_item(tree, hf_cmd_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_status);
}
static void dissect_zcl_discover_attr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_attr_start, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_maxnum);
return;
}
static void dissect_zcl_discover_attr_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint *offset, guint16 cluster_id)
{
proto_tree *sub_tree = NULL;
guint tvb_len;
guint i = 0;
dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_dis);
tvb_len = tvb_captured_length(tvb);
while ( *offset < tvb_len && i < ZBEE_ZCL_NUM_ATTR_ETT ) {
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 3, ett_zbee_zcl_attr[i], NULL, "Attribute Status Record");
i++;
dissect_zcl_attr_id(tvb, sub_tree, offset, cluster_id);
dissect_zcl_attr_uint8(tvb, sub_tree, offset, &hf_zbee_zcl_attr_data_type);
}
}
static void dissect_zcl_attr_id(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint16 cluster_id)
{
zbee_zcl_cluster_desc *desc;
int hf_attr_id = hf_zbee_zcl_attr_id;
desc = zbee_zcl_get_cluster_desc(cluster_id);
if (desc && (desc->hf_attr_id >= 0)) hf_attr_id = desc->hf_attr_id;
proto_tree_add_item(tree, hf_attr_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void dissect_zcl_attr_data_type_val(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint16 attr_id, guint16 cluster_id)
{
zbee_zcl_cluster_desc *desc;
desc = zbee_zcl_get_cluster_desc(cluster_id);
if ((desc != NULL) && (desc->fn_attr_data != NULL)) {
desc->fn_attr_data(tree, tvb, offset, attr_id,
dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_data_type));
}
else {
dissect_zcl_attr_data(tvb, tree, offset,
dissect_zcl_attr_uint8(tvb, tree, offset, &hf_zbee_zcl_attr_data_type) );
}
}
static void dissect_zcl_attr_data_general(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint16 attr_id, guint data_type, guint16 cluster_id)
{
zbee_zcl_cluster_desc *desc;
desc = zbee_zcl_get_cluster_desc(cluster_id);
if ((desc != NULL) && (desc->fn_attr_data != NULL)) {
desc->fn_attr_data(tree, tvb, offset, attr_id, data_type);
}
else {
dissect_zcl_attr_data(tvb, tree, offset, data_type);
}
}
void dissect_zcl_attr_data(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint data_type)
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
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 1, ENC_NA);
(*offset) += 1;
break;
case ZBEE_ZCL_8_BIT_BITMAP:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bitmap8, tvb, *offset, 1, ENC_NA);
proto_item_append_text(tree, ", Bitmap: %02x", tvb_get_guint8(tvb, *offset));
(*offset) += 1;
break;
case ZBEE_ZCL_8_BIT_UINT:
case ZBEE_ZCL_8_BIT_ENUM:
attr_uint = tvb_get_guint8(tvb, *offset);
proto_item_append_text(tree, ", %s: %u",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_item(tree, hf_zbee_zcl_attr_uint8, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_8_BIT_INT:
attr_int = (gint8)tvb_get_guint8(tvb, *offset);
proto_item_append_text(tree, ", %s: %-d",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_int);
proto_tree_add_item(tree, hf_zbee_zcl_attr_int8, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_BOOLEAN:
attr_uint = tvb_get_guint8(tvb, *offset);
proto_item_append_text(tree, ", %s: 0x%02x",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_item(tree, hf_zbee_zcl_attr_boolean, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_16_BIT_DATA:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 2, ENC_NA);
(*offset) += 2;
break;
case ZBEE_ZCL_16_BIT_BITMAP:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bitmap16, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Bitmap: %04" G_GINT16_MODIFIER "x", tvb_get_letohs(tvb, *offset));
(*offset) += 2;
break;
case ZBEE_ZCL_16_BIT_UINT:
case ZBEE_ZCL_16_BIT_ENUM:
attr_uint = tvb_get_letohs(tvb, *offset);
proto_item_append_text(tree, ", %s: %u",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_item(tree, hf_zbee_zcl_attr_uint16, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_16_BIT_INT:
attr_int = (gint16)tvb_get_letohs(tvb, *offset);
proto_item_append_text(tree, ", %s: %-d",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_int);
proto_tree_add_item(tree, hf_zbee_zcl_attr_int16, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_24_BIT_DATA:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 3, ENC_NA);
(*offset) += 3;
break;
case ZBEE_ZCL_24_BIT_BITMAP:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bitmap24, tvb, *offset, 3, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Bitmap: %06" G_GINT32_MODIFIER "x", tvb_get_letoh24(tvb, *offset));
(*offset) += 3;
break;
case ZBEE_ZCL_24_BIT_UINT:
attr_uint = tvb_get_letoh24(tvb, *offset);
proto_item_append_text(tree, ", %s: %u",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_item(tree, hf_zbee_zcl_attr_uint24, tvb, *offset, 3, ENC_LITTLE_ENDIAN);
*offset += 3;
break;
case ZBEE_ZCL_24_BIT_INT:
attr_int = (gint)tvb_get_letoh24(tvb, *offset);
if (attr_int & INT24_SIGN_BITS) attr_int |= INT24_SIGN_BITS;
proto_item_append_text(tree, ", %s: %-d",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_int);
proto_tree_add_item(tree, hf_zbee_zcl_attr_int24, tvb, *offset, 3, ENC_LITTLE_ENDIAN);
*offset += 3;
break;
case ZBEE_ZCL_32_BIT_DATA:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 4, ENC_NA);
(*offset) += 4;
break;
case ZBEE_ZCL_32_BIT_BITMAP:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bitmap32, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Bitmap: %08" G_GINT32_MODIFIER "x", tvb_get_letohl(tvb, *offset));
(*offset) += 4;
break;
case ZBEE_ZCL_32_BIT_UINT:
attr_uint = tvb_get_letohl(tvb, *offset);
proto_item_append_text(tree, ", %s: %u",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_uint);
proto_tree_add_item(tree, hf_zbee_zcl_attr_uint32, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
break;
case ZBEE_ZCL_32_BIT_INT:
attr_int = (gint)tvb_get_letohl(tvb, *offset);
proto_item_append_text(tree, ", %s: %-d",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved"), attr_int);
proto_tree_add_item(tree, hf_zbee_zcl_attr_int32, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
break;
case ZBEE_ZCL_40_BIT_DATA:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 5, ENC_NA);
(*offset) += 5;
break;
case ZBEE_ZCL_40_BIT_BITMAP:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bitmap40, tvb, *offset, 5, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Bitmap: %010" G_GINT64_MODIFIER "x", tvb_get_letoh40(tvb, *offset));
(*offset) += 5;
break;
case ZBEE_ZCL_40_BIT_UINT:
proto_tree_add_item(tree, hf_zbee_zcl_attr_uint40, tvb, *offset, 5, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Uint: %" G_GINT64_MODIFIER "u", tvb_get_letoh40(tvb, *offset));
(*offset) += 5;
break;
case ZBEE_ZCL_40_BIT_INT:
proto_tree_add_item(tree, hf_zbee_zcl_attr_int64, tvb, *offset, 5, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Int: %" G_GINT64_MODIFIER "d", tvb_get_letohi40(tvb, *offset));
(*offset) += 5;
break;
case ZBEE_ZCL_48_BIT_DATA:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 6, ENC_NA);
(*offset) += 6;
break;
case ZBEE_ZCL_48_BIT_BITMAP:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bitmap48, tvb, *offset, 6, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Bitmap: %012" G_GINT64_MODIFIER "x", tvb_get_letoh48(tvb, *offset));
(*offset) += 6;
break;
case ZBEE_ZCL_48_BIT_UINT:
proto_tree_add_item(tree, hf_zbee_zcl_attr_uint48, tvb, *offset, 6, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Uint: %" G_GINT64_MODIFIER "u", tvb_get_letoh48(tvb, *offset));
(*offset) += 6;
break;
case ZBEE_ZCL_48_BIT_INT:
proto_tree_add_item(tree, hf_zbee_zcl_attr_int64, tvb, *offset, 6, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Int: %" G_GINT64_MODIFIER "d", tvb_get_letohi48(tvb, *offset));
(*offset) += 6;
break;
case ZBEE_ZCL_56_BIT_DATA:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 7, ENC_NA);
(*offset) += 7;
break;
case ZBEE_ZCL_56_BIT_BITMAP:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bitmap56, tvb, *offset, 7, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Bitmap: %014" G_GINT64_MODIFIER "x", tvb_get_letoh56(tvb, *offset));
(*offset) += 7;
break;
case ZBEE_ZCL_56_BIT_UINT:
proto_tree_add_item(tree, hf_zbee_zcl_attr_uint56, tvb, *offset, 7, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Uint: %" G_GINT64_MODIFIER "u", tvb_get_letoh56(tvb, *offset));
(*offset) += 7;
break;
case ZBEE_ZCL_56_BIT_INT:
proto_tree_add_item(tree, hf_zbee_zcl_attr_int64, tvb, *offset, 7, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Int: %" G_GINT64_MODIFIER "d", tvb_get_letohi56(tvb, *offset));
(*offset) += 7;
break;
case ZBEE_ZCL_64_BIT_DATA:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 8, ENC_NA);
(*offset) += 8;
break;
case ZBEE_ZCL_64_BIT_BITMAP:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bitmap64, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Bitmap: %016" G_GINT64_MODIFIER "x", tvb_get_letoh64(tvb, *offset));
(*offset) += 8;
break;
case ZBEE_ZCL_64_BIT_UINT:
proto_tree_add_item(tree, hf_zbee_zcl_attr_uint64, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Uint: %" G_GINT64_MODIFIER "u", tvb_get_letoh64(tvb, *offset));
(*offset) += 8;
break;
case ZBEE_ZCL_64_BIT_INT:
proto_tree_add_item(tree, hf_zbee_zcl_attr_int64, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", Int: %" G_GINT64_MODIFIER "u", tvb_get_letoh64(tvb, *offset));
(*offset) += 8;
break;
case ZBEE_ZCL_SEMI_FLOAT:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 2, ENC_NA);
(*offset) += 2;
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
proto_item_append_text(tree, ", Double: %g", attr_double);
proto_tree_add_item(tree, hf_zbee_zcl_attr_double, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
break;
case ZBEE_ZCL_OCTET_STRING:
attr_uint = tvb_get_guint8(tvb, *offset);
if (attr_uint == ZBEE_ZCL_INVALID_STR_LENGTH) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_attr_str_len, tvb, *offset, 1,
attr_uint);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_attr_ostr, tvb, *offset, attr_uint, ENC_NA);
proto_item_append_text(tree, ", Octets: %s", tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, *offset, attr_uint, ':'));
*offset += attr_uint;
break;
case ZBEE_ZCL_CHAR_STRING:
attr_uint = tvb_get_guint8(tvb, *offset);
if (attr_uint == ZBEE_ZCL_INVALID_STR_LENGTH) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_attr_str_len, tvb, *offset, 1, attr_uint);
*offset += 1;
attr_string = tvb_get_string_enc(wmem_packet_scope(), tvb, *offset, attr_uint, ENC_ASCII);
proto_item_append_text(tree, ", String: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_attr_str, tvb, *offset, attr_uint, attr_string);
*offset += attr_uint;
break;
case ZBEE_ZCL_LONG_OCTET_STRING:
attr_uint = tvb_get_letohs(tvb, *offset);
if (attr_uint == ZBEE_ZCL_INVALID_LONG_STR_LENGTH) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_attr_str_len, tvb, *offset, 2, attr_uint);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_attr_ostr, tvb, *offset, attr_uint, ENC_NA);
proto_item_append_text(tree, ", Octets: %s", tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, *offset, attr_uint, ':'));
*offset += attr_uint;
break;
case ZBEE_ZCL_LONG_CHAR_STRING:
attr_uint = tvb_get_letohs(tvb, *offset);
if (attr_uint == ZBEE_ZCL_INVALID_LONG_STR_LENGTH) attr_uint = 0;
proto_tree_add_uint(tree, hf_zbee_zcl_attr_str_len, tvb, *offset, 2, attr_uint);
*offset += 2;
attr_string = tvb_get_string_enc(wmem_packet_scope(), tvb, *offset, attr_uint, ENC_ASCII);
proto_item_append_text(tree, ", String: %s", attr_string);
proto_tree_add_string(tree, hf_zbee_zcl_attr_str, tvb, *offset, attr_uint, attr_string);
*offset += attr_uint;
break;
case ZBEE_ZCL_ARRAY:
elements_type = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_array_elements_type, tvb, *offset, 1, elements_type);
*offset += 1;
elements_num = tvb_get_letohs(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_array_elements_num, tvb, *offset, 2, elements_num);
*offset += 2;
dissect_zcl_array_type(tvb, tree, offset, elements_type, elements_num);
break;
case ZBEE_ZCL_SET:
elements_type = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_set_elements_type, tvb, *offset, 1, elements_type);
*offset += 1;
elements_num = tvb_get_letohs(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_set_elements_num, tvb, *offset, 2, elements_num);
*offset += 2;
dissect_zcl_set_type(tvb, tree, offset, elements_type, elements_num);
break;
case ZBEE_ZCL_BAG:
elements_type = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_bag_elements_type, tvb, *offset, 1, elements_type);
*offset += 1;
elements_num = tvb_get_letohs(tvb, *offset);
proto_tree_add_uint(tree, hf_zbee_zcl_attr_bag_elements_num, tvb, *offset, 2, elements_num);
*offset += 2;
dissect_zcl_set_type(tvb, tree, offset, elements_type, elements_num);
break;
case ZBEE_ZCL_STRUCT:
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
attr_time.secs = tvb_get_letohl(tvb, *offset);
attr_time.secs += ZBEE_ZCL_NSTIME_UTC_OFFSET;
attr_time.nsecs = 0;
proto_item_append_text(tree, ", %s",
val_to_str_ext_const(data_type, &zbee_zcl_short_data_type_names_ext, "Reserved") );
proto_tree_add_time(tree, hf_zbee_zcl_attr_utc, tvb, *offset, 4, &attr_time);
*offset += 4;
break;
case ZBEE_ZCL_CLUSTER_ID:
proto_tree_add_item(tree, hf_zbee_zcl_attr_cid, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
break;
case ZBEE_ZCL_ATTR_ID:
dissect_zcl_attr_id(tvb, tree, offset, zcl_cluster_id);
break;
case ZBEE_ZCL_BACNET_OID:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 4, ENC_NA);
(*offset) += 4;
break;
case ZBEE_ZCL_IEEE_ADDR:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 8, ENC_NA);
(*offset) += 8;
break;
case ZBEE_ZCL_SECURITY_KEY:
proto_tree_add_item(tree, hf_zbee_zcl_attr_bytes, tvb, *offset, 16, ENC_NA);
(*offset) += 16;
break;
default:
break;
}
}
static guint dissect_zcl_attr_uint8(tvbuff_t *tvb, proto_tree *tree, guint *offset, int *hf_zbee_zcl)
{
guint attr_uint;
attr_uint = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, *hf_zbee_zcl, tvb, *offset, 1, attr_uint);
(*offset)++;
return attr_uint;
}
static void
dissect_zcl_array_type(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint8 elements_type, guint16 elements_num)
{
proto_tree *sub_tree;
guint tvb_len;
guint i = 1;
tvb_len = tvb_captured_length(tvb);
while ( (*offset < tvb_len) && (elements_num != 0) ) {
if (i < ZBEE_ZCL_NUM_ARRAY_ELEM_ETT-1)
sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 0,
ett_zbee_zcl_array_elements[i], NULL, "Element #%d", i);
else
sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 0,
ett_zbee_zcl_array_elements[ZBEE_ZCL_NUM_ARRAY_ELEM_ETT-1], NULL, "Element #%d", i);
dissect_zcl_attr_data(tvb, sub_tree, offset, elements_type);
elements_num--;
i++;
}
}
static void
dissect_zcl_set_type(tvbuff_t *tvb, proto_tree *tree, guint *offset, guint8 elements_type, guint16 elements_num)
{
proto_tree *sub_tree;
guint tvb_len;
guint i = 1;
tvb_len = tvb_captured_length(tvb);
while ( (*offset < tvb_len) && (elements_num != 0) ) {
if (i < ZBEE_ZCL_NUM_ARRAY_ELEM_ETT-1)
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 0,
ett_zbee_zcl_array_elements[i], NULL, "Element");
else
sub_tree = proto_tree_add_subtree(tree, tvb, *offset, 0,
ett_zbee_zcl_array_elements[ZBEE_ZCL_NUM_ARRAY_ELEM_ETT-1], NULL, "Element");
dissect_zcl_attr_data(tvb, sub_tree, offset, elements_type);
elements_num--;
i++;
}
}
static void zcl_dump_data(tvbuff_t *tvb, guint offset, packet_info *pinfo, proto_tree *tree)
{
proto_tree *root = proto_tree_get_root(tree);
guint length = tvb_captured_length_remaining(tvb, offset);
tvbuff_t *remainder;
if (length > 0) {
remainder = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(remainder, pinfo, root);
}
return;
}
void decode_zcl_time_in_seconds(gchar *s, guint16 value)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d seconds", value);
return;
}
void decode_zcl_time_in_minutes(gchar *s, guint16 value)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d minutes", value);
return;
}
static void
cluster_desc_free(gpointer p, gpointer user_data _U_)
{
g_free(p);
}
static void
zbee_shutdown(void)
{
g_list_foreach(acluster_desc, cluster_desc_free, NULL);
g_list_free(acluster_desc);
}
void proto_register_zbee_zcl(void)
{
guint i, j;
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
{ &hf_zbee_zcl_attr_bitmap8,
{ "Bitmap8", "zbee_zcl.attr.bitmap8", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bitmap16,
{ "Bitmap16", "zbee_zcl.attr.bitmap16", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bitmap24,
{ "Bitmap24", "zbee_zcl.attr.bitmap24", FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bitmap32,
{ "Bitmap32", "zbee_zcl.attr.bitmap32", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bitmap40,
{ "Bitmap40", "zbee_zcl.attr.bitmap40", FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bitmap48,
{ "Bitmap48", "zbee_zcl.attr.bitmap48", FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bitmap56,
{ "Bitmap56", "zbee_zcl.attr.bitmap56", FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bitmap64,
{ "Bitmap64", "zbee_zcl.attr.bitmap64", FT_UINT64, BASE_HEX, NULL, 0x0,
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
{ &hf_zbee_zcl_attr_uint40,
{ "Uint40", "zbee_zcl.attr.uint40", FT_UINT64, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_uint48,
{ "Uint48", "zbee_zcl.attr.uint48", FT_UINT64, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_uint56,
{ "Uint56", "zbee_zcl.attr.uint56", FT_UINT64, BASE_DEC_HEX, NULL, 0x0,
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
{ "Maximum Number", "zbee_zcl.attr.maxnum", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_str_len,
{ "Length", "zbee_zcl.attr.str.len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_str,
{ "String", "zbee_zcl.attr.str", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_ostr,
{ "Octet String", "zbee_zcl.attr.ostr", FT_BYTES, SEP_COLON, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_array_elements_type,
{ "Elements Type", "zbee_zcl.attr.array.elements_type", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&zbee_zcl_data_type_names_ext, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_array_elements_num,
{ "Elements Number", "zbee_zcl.attr.array.elements_num", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_set_elements_type,
{ "Elements Type", "zbee_zcl.attr.set.elements_type", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&zbee_zcl_data_type_names_ext, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_set_elements_num,
{ "Elements Number", "zbee_zcl.attr.set.elements_num", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bag_elements_type,
{ "Elements Type", "zbee_zcl.attr.bag.elements_type", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&zbee_zcl_data_type_names_ext, 0x0,
NULL, HFILL }},
{ &hf_zbee_zcl_attr_bag_elements_num,
{ "Elements Number", "zbee_zcl.attr.bag.elements_num", FT_UINT16, BASE_DEC, NULL, 0x0,
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
zbee_zcl_dissector_table = register_dissector_table("zbee.zcl.cluster", "ZigBee ZCL Cluster ID", proto_zbee_zcl, FT_UINT16, BASE_HEX);
register_dissector(ZBEE_PROTOABBREV_ZCL, dissect_zbee_zcl, proto_zbee_zcl);
register_shutdown_routine(zbee_shutdown);
}
void proto_reg_handoff_zbee_zcl(void)
{
dissector_handle_t zbee_zcl_handle;
zbee_zcl_handle = find_dissector(ZBEE_PROTOABBREV_ZCL);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_IPM, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_T1, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_HA, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_CBA, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_WSN, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_TA, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_HC, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_SE, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_RS, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_GP, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_ZLL, zbee_zcl_handle);
dissector_add_uint("zbee.profile", ZBEE_PROFILE_C4_CL, zbee_zcl_handle);
}
void
zbee_zcl_init_cluster(int proto, gint ett, guint16 cluster_id, int hf_attr_id, int hf_cmd_rx_id, int hf_cmd_tx_id, zbee_zcl_fn_attr_data fn_attr_data)
{
zbee_zcl_cluster_desc *cluster_desc;
cluster_desc = g_new(zbee_zcl_cluster_desc, 1);
cluster_desc->proto = find_protocol_by_id(proto);
cluster_desc->name = proto_get_protocol_short_name(cluster_desc->proto);
cluster_desc->cluster_id = cluster_id;
cluster_desc->hf_attr_id = hf_attr_id;
cluster_desc->hf_cmd_rx_id = hf_cmd_rx_id;
cluster_desc->hf_cmd_tx_id = hf_cmd_tx_id;
cluster_desc->fn_attr_data = fn_attr_data;
acluster_desc = g_list_append(acluster_desc, cluster_desc);
cluster_desc->proto_id = proto;
cluster_desc->ett = ett;
return;
}
zbee_zcl_cluster_desc
*zbee_zcl_get_cluster_desc(guint16 cluster_id)
{
GList *gl;
gl = acluster_desc;
while (gl) {
zbee_zcl_cluster_desc *cluster_desc = (zbee_zcl_cluster_desc *)gl->data;
if(cluster_desc->cluster_id == cluster_id) {
return cluster_desc;
}
gl = gl->next;
}
return NULL;
}
