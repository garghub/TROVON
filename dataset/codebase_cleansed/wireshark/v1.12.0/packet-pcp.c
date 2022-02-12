static guint get_pcp_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return (guint)tvb_get_ntohl(tvb, offset);
}
static int dissect_pcp_message_creds(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint32 creds_length;
guint32 i;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]",
val_to_str(CREDS, packettypenames, "Unknown Type:0x%02x"));
proto_tree_add_item(tree, hf_pcp_creds_number_of, tvb, offset, 4, ENC_BIG_ENDIAN);
creds_length = tvb_get_ntohl(tvb, offset);
offset += 4;
for (i = 0; i < creds_length; i++) {
proto_tree_add_item(tree, hf_pcp_creds_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_pcp_creds_vala, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_pcp_creds_valb, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_pcp_creds_valc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
return offset;
}
static int dissect_pcp_message_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
gint32 error_num;
col_append_str(pinfo->cinfo, COL_INFO, "[ERROR] ");
proto_tree_add_item(tree, hf_pcp_pdu_error, tvb, offset, 4, ENC_BIG_ENDIAN);
error_num = tvb_get_ntohl(tvb, 4);
col_append_fstr(pinfo->cinfo, COL_INFO, "error=%s ",
val_to_str(error_num, packettypenames_errors, "Unknown Error:%i"));
offset += 4;
return offset;
}
static int dissect_pcp_message_start(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_start_item;
proto_tree *pcp_start_tree;
guint32 bits_offset;
pcp_start_item = proto_tree_add_item(tree, hf_pcp_start, tvb, 0, -1, ENC_NA);
pcp_start_tree = proto_item_add_subtree(pcp_start_item, ett_pcp);
bits_offset = offset*8;
col_append_str(pinfo->cinfo, COL_INFO, "[START]");
proto_tree_add_item(pcp_start_tree, hf_pcp_start_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
bits_offset += 32;
proto_tree_add_bits_item(pcp_start_tree, hf_pcp_start_zero, tvb, bits_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(pcp_start_tree, hf_pcp_start_version, tvb, bits_offset+1, 7, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pcp_start_tree, hf_pcp_start_licensed, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pcp_start_tree, hf_pcp_start_authorize, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_pcp_message_pmns_traverse(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_pmns_traverse_item;
proto_tree *pcp_pmns_traverse_tree;
guint32 name_len;
guint32 padding;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]",
val_to_str(PMNS_TRAVERSE, packettypenames, "Unknown Type:0x%02x"));
pcp_pmns_traverse_item = proto_tree_add_item(tree, hf_pcp_pmns_traverse, tvb, offset, -1, ENC_NA);
pcp_pmns_traverse_tree = proto_item_add_subtree(pcp_pmns_traverse_item, ett_pcp);
proto_tree_add_item(pcp_pmns_traverse_tree, hf_pcp_pmns_subtype, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_pmns_traverse_tree, hf_pcp_pmns_namelen, tvb, offset, 4, ENC_BIG_ENDIAN);
name_len = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(pcp_pmns_traverse_tree, hf_pcp_pmns_name, tvb, offset, name_len, ENC_ASCII|ENC_NA);
offset += name_len;
padding = name_len % 4;
if (padding != 0) {
padding = 4 - padding;
proto_tree_add_item(pcp_pmns_traverse_tree, hf_pcp_pdu_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
return offset;
}
static int dissect_pcp_message_pmns_names(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_pmns_names_item;
proto_tree *pcp_pmns_names_tree;
proto_item *pcp_pmns_names_name_item;
proto_tree *pcp_pmns_names_name_tree;
guint32 is_pmns_names_status;
guint32 num_names;
guint32 name_len;
guint32 full_name_len;
guint32 padding;
guint32 i;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(PMNS_NAMES, packettypenames, "Unknown Type:0x%02x"));
pcp_pmns_names_item = proto_tree_add_item(tree, hf_pcp_pmns_names, tvb, offset, -1, ENC_NA);
pcp_pmns_names_tree = proto_item_add_subtree(pcp_pmns_names_item, ett_pcp);
proto_tree_add_item(pcp_pmns_names_tree, hf_pcp_pmns_names_nstrbytes, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_pmns_names_tree, hf_pcp_pmns_names_numstatus, tvb, offset, 4, ENC_BIG_ENDIAN);
is_pmns_names_status = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(pcp_pmns_names_tree, hf_pcp_pmns_names_numnames, tvb, offset, 4, ENC_BIG_ENDIAN);
num_names = tvb_get_ntohl(tvb, offset);
offset += 4;
for (i=0; i < num_names; i++) {
if (is_pmns_names_status) {
name_len = tvb_get_ntohl(tvb, offset+4);
full_name_len = name_len + 8;
} else {
name_len = tvb_get_ntohl(tvb, offset);
full_name_len = name_len + 4;
}
pcp_pmns_names_name_item = proto_tree_add_item(pcp_pmns_names_tree, hf_pcp_pmns_names_nametree,
tvb, offset, full_name_len, ENC_NA);
pcp_pmns_names_name_tree = proto_item_add_subtree(pcp_pmns_names_name_item, ett_pcp);
if (is_pmns_names_status) {
proto_tree_add_item(pcp_pmns_names_name_tree, hf_pcp_pmns_names_nametree_status,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(pcp_pmns_names_name_tree, hf_pcp_pmns_names_nametree_namelen,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_pmns_names_name_tree, hf_pcp_pmns_names_nametree_name,
tvb, offset, name_len, ENC_ASCII|ENC_NA);
offset += name_len;
padding = name_len % 4;
if (padding != 0) {
padding = 4 - padding;
proto_tree_add_item(pcp_pmns_names_name_tree, hf_pcp_pdu_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
}
return offset;
}
static int dissect_pcp_message_pmns_child(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_pmns_child_item;
proto_tree *pcp_pmns_child_tree;
guint32 name_len;
pcp_pmns_child_item = proto_tree_add_item(tree, hf_pcp_pmns_child, tvb, offset, -1, ENC_NA);
pcp_pmns_child_tree = proto_item_add_subtree(pcp_pmns_child_item, ett_pcp);
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(PMNS_CHILD, packettypenames, "Unknown Type:0x%02x"));
proto_tree_add_item(pcp_pmns_child_tree, hf_pcp_pmns_subtype, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_pmns_child_tree, hf_pcp_pmns_namelen, tvb, offset, 4, ENC_BIG_ENDIAN);
name_len = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(pcp_pmns_child_tree, hf_pcp_pmns_name, tvb, offset, name_len, ENC_ASCII|ENC_NA);
offset += 4;
return offset;
}
static int dissect_pcp_message_pmns_ids(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_pmns_ids_item;
proto_tree *pcp_pmns_ids_tree;
guint32 num_ids;
guint32 i;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]",
val_to_str(PMNS_IDS, packettypenames, "Unknown Type:0x%02x"));
pcp_pmns_ids_item = proto_tree_add_item(tree, hf_pcp_pmns_ids, tvb, offset, -1, ENC_NA);
pcp_pmns_ids_tree = proto_item_add_subtree(pcp_pmns_ids_item, ett_pcp);
proto_tree_add_item(pcp_pmns_ids_tree, hf_pcp_pmns_ids_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_pmns_ids_tree, hf_pcp_pmns_ids_numids, tvb, offset, 4, ENC_BIG_ENDIAN);
num_ids = tvb_get_ntohl(tvb, offset);
offset += 4;
for (i=0; i<num_ids; i++) {
offset = dissect_pcp_partial_pmid(tvb, pinfo, pcp_pmns_ids_tree, offset);
}
return offset;
}
static int dissect_pcp_message_profile(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_profile_item;
proto_tree *pcp_profile_tree;
proto_item *pcp_profile_profile_item;
proto_tree *pcp_profile_profile_tree;
guint32 num_prof;
guint32 i;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(PROFILE, packettypenames, "Unknown Type:0x%02x"));
pcp_profile_item = proto_tree_add_item(tree, hf_pcp_profile, tvb, offset, -1, ENC_NA);
pcp_profile_tree = proto_item_add_subtree(pcp_profile_item, ett_pcp);
proto_tree_add_item(pcp_profile_tree, hf_pcp_ctxnum, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_profile_tree, hf_pcp_profile_g_state, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_profile_tree, hf_pcp_profile_numprof, tvb, offset, 4, ENC_BIG_ENDIAN);
num_prof = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(pcp_profile_tree, hf_pcp_pdu_padding, tvb, offset, 4, ENC_NA);
offset += 4;
for (i=0; i<num_prof; i++) {
pcp_profile_profile_item = proto_tree_add_item(pcp_profile_tree, hf_pcp_profile_profile, tvb, offset, 32, ENC_NA);
pcp_profile_profile_tree = proto_item_add_subtree(pcp_profile_profile_item, ett_pcp);
proto_tree_add_item(pcp_profile_profile_tree, hf_pcp_instance_indom, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_profile_profile_tree, hf_pcp_profile_profile_state, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_profile_profile_tree, hf_pcp_profile_profile_numinst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_profile_tree, hf_pcp_pdu_padding, tvb, offset, 4, ENC_NA);
offset += 4;
}
return offset;
}
static int dissect_pcp_message_fetch(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_fetch_item;
proto_tree *pcp_fetch_tree;
guint32 num_pmid;
guint32 i;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]",
val_to_str(FETCH, packettypenames, "Unknown Type:0x%02x"));
pcp_fetch_item = proto_tree_add_item(tree, hf_pcp_fetch, tvb, offset, -1, ENC_NA);
pcp_fetch_tree = proto_item_add_subtree(pcp_fetch_item, ett_pcp);
proto_tree_add_item(pcp_fetch_tree, hf_pcp_ctxnum, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_pcp_partial_when(tvb, pinfo, pcp_fetch_tree, offset);
proto_tree_add_item(pcp_fetch_tree, hf_pcp_fetch_numpmid, tvb, offset, 4, ENC_BIG_ENDIAN);
num_pmid = tvb_get_ntohl(tvb, offset);
offset += 4;
for (i=0; i<num_pmid; i++) {
offset = dissect_pcp_partial_pmid(tvb, pinfo, pcp_fetch_tree, offset);
}
return offset;
}
static int dissect_pcp_message_result(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_results_item;
proto_tree *pcp_results_tree;
proto_item *pcp_result_item;
proto_tree *pcp_result_tree;
proto_item *pcp_result_instance_item;
proto_tree *pcp_result_instance_tree;
guint32 num_pmid;
guint32 num_val;
guint32 offset_start;
guint32 valfmt_type;
guint32 value_type;
guint32 pmvalueblock_offset;
guint32 pmvalueblock_value_length;
guint32 i;
guint32 j;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(RESULT, packettypenames, "Unknown Type:0x%02x"));
pcp_results_item = proto_tree_add_item(tree, hf_pcp_results, tvb, offset, -1, ENC_NA);
pcp_results_tree = proto_item_add_subtree(pcp_results_item, ett_pcp);
offset = dissect_pcp_partial_when(tvb, pinfo, pcp_results_tree, offset);
proto_tree_add_item(pcp_results_tree, hf_pcp_results_numpmid, tvb, offset, 4, ENC_BIG_ENDIAN);
num_pmid = tvb_get_ntohl(tvb, offset);
offset += 4;
for (i=0; i<num_pmid; i++) {
offset_start = offset;
pcp_result_item = proto_tree_add_item(pcp_results_tree, hf_pcp_result, tvb, offset, -1, ENC_NA);
pcp_result_tree = proto_item_add_subtree(pcp_result_item, ett_pcp);
offset = dissect_pcp_partial_pmid(tvb, pinfo, pcp_result_tree, offset);
proto_tree_add_item(pcp_result_tree, hf_pcp_result_numval, tvb, offset, 4, ENC_BIG_ENDIAN);
num_val = tvb_get_ntohl(tvb, offset);
offset += 4;
if (num_val > 0) {
proto_tree_add_item(pcp_result_tree, hf_pcp_result_valfmt, tvb, offset, 4, ENC_BIG_ENDIAN);
valfmt_type = tvb_get_ntohl(tvb, offset);
offset += 4;
for (j=0; j<num_val; j++) {
pcp_result_instance_item = proto_tree_add_item(pcp_result_tree, hf_pcp_instance,
tvb, offset, 8, ENC_NA);
pcp_result_instance_tree = proto_item_add_subtree(pcp_result_instance_item, ett_pcp);
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_pmid_inst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (valfmt_type == PM_VAL_INSITU) {
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_value_insitu,
tvb, offset, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_valoffset,
tvb, offset, 4, ENC_BIG_ENDIAN);
pmvalueblock_offset = tvb_get_ntohl(tvb, offset);
pmvalueblock_offset = pmvalueblock_offset * 4;
value_type = tvb_get_guint8(tvb, pmvalueblock_offset);
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_pmid_type,
tvb, pmvalueblock_offset, 1, ENC_BIG_ENDIAN);
pmvalueblock_offset += 1;
pmvalueblock_value_length = tvb_get_ntoh24(tvb, pmvalueblock_offset);
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_vallength,
tvb, pmvalueblock_offset, 3, ENC_BIG_ENDIAN);
pmvalueblock_offset += 3;
switch (value_type) {
case PM_TYPE_32:
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_value_int, tvb,
pmvalueblock_offset, pmvalueblock_value_length-4, ENC_BIG_ENDIAN);
break;
case PM_TYPE_U32:
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_value_uint, tvb,
pmvalueblock_offset, pmvalueblock_value_length-4, ENC_BIG_ENDIAN);
break;
case PM_TYPE_64:
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_value_int64, tvb,
pmvalueblock_offset, pmvalueblock_value_length-4, ENC_BIG_ENDIAN);
break;
case PM_TYPE_U64:
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_value_uint64, tvb,
pmvalueblock_offset, pmvalueblock_value_length-4, ENC_BIG_ENDIAN);
break;
case PM_TYPE_FLOAT:
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_value_float, tvb,
pmvalueblock_offset, pmvalueblock_value_length-4, ENC_BIG_ENDIAN);
break;
case PM_TYPE_DOUBLE:
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_value_double, tvb,
pmvalueblock_offset, pmvalueblock_value_length-4, ENC_BIG_ENDIAN);
break;
case PM_TYPE_STRING:
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_value_ptr, tvb,
pmvalueblock_offset, pmvalueblock_value_length-4, ENC_ASCII|ENC_NA);
break;
case PM_TYPE_AGGREGATE:
case PM_TYPE_AGGREGATE_STATIC:
proto_tree_add_item(pcp_result_instance_tree, hf_pcp_instance_value_aggr, tvb,
pmvalueblock_offset, pmvalueblock_value_length-4, ENC_NA);
break;
case PM_TYPE_EVENT:
expert_add_info(pinfo, pcp_result_instance_tree, &ei_pcp_type_event_unimplemented);
break;
case PM_TYPE_NOSUPPORT:
expert_add_info(pinfo, pcp_result_instance_tree, &ei_pcp_type_nosupport_unsupported);
break;
case PM_TYPE_UNKNOWN:
expert_add_info(pinfo, pcp_result_instance_tree, &ei_pcp_type_unknown_unknown_value);
break;
default:
expert_add_info(pinfo, pcp_result_instance_tree, &ei_pcp_unimplemented_value);
break;
}
}
offset += 4;
}
}
proto_item_set_len(pcp_result_tree, offset-offset_start);
}
return offset;
}
static int dissect_pcp_message_desc_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_desc_req_item;
proto_tree *pcp_desc_req_tree;
proto_item *pcp_desc_req_pmid_item;
proto_tree *pcp_desc_req_pmid_tree;
guint32 bits_offset;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(DESC_REQ, packettypenames, "Unknown Type:0x%02x"));
bits_offset = offset*8;
pcp_desc_req_item = proto_tree_add_item(tree, hf_pcp_desc_req, tvb, offset, -1, ENC_NA);
pcp_desc_req_tree = proto_item_add_subtree(pcp_desc_req_item, ett_pcp);
pcp_desc_req_pmid_item = proto_tree_add_item(pcp_desc_req_tree, hf_pcp_pmid, tvb, offset, 4, ENC_BIG_ENDIAN);
pcp_desc_req_pmid_tree = proto_item_add_subtree(pcp_desc_req_pmid_item, ett_pcp);
proto_tree_add_bits_item(pcp_desc_req_pmid_tree, hf_pcp_pmid_flag, tvb, bits_offset, 1, ENC_BIG_ENDIAN);
bits_offset += 1;
proto_tree_add_bits_item(pcp_desc_req_pmid_tree, hf_pcp_pmid_domain, tvb, bits_offset, 9, ENC_BIG_ENDIAN);
bits_offset += 9;
proto_tree_add_bits_item(pcp_desc_req_pmid_tree, hf_pcp_pmid_cluster, tvb, bits_offset, 12, ENC_BIG_ENDIAN);
bits_offset += 12;
proto_tree_add_bits_item(pcp_desc_req_pmid_tree, hf_pcp_pmid_item, tvb, bits_offset, 10, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_pcp_message_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_desc_item;
proto_tree *pcp_desc_tree;
proto_item *pcp_desc_units_item;
proto_tree *pcp_desc_units_tree;
guint32 bits_offset;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(DESC, packettypenames, "Unknown Type:0x%02x"));
pcp_desc_item = proto_tree_add_item(tree, hf_pcp_desc, tvb, offset, 4, ENC_NA);
pcp_desc_tree = proto_item_add_subtree(pcp_desc_item, ett_pcp);
offset = dissect_pcp_partial_pmid(tvb, pinfo, pcp_desc_tree, offset);
proto_tree_add_item(pcp_desc_tree, hf_pcp_pmid_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_desc_tree, hf_pcp_instance_indom, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_desc_tree, hf_pcp_pmid_sem, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
bits_offset = offset*8;
pcp_desc_units_item = proto_tree_add_item(pcp_desc_tree, hf_pcp_units, tvb, offset, -1, ENC_NA);
pcp_desc_units_tree = proto_item_add_subtree(pcp_desc_units_item, ett_pcp);
proto_tree_add_bits_item(pcp_desc_units_tree, hf_pcp_units_dimspace, tvb, bits_offset, 4, ENC_BIG_ENDIAN);
bits_offset += 4;
proto_tree_add_bits_item(pcp_desc_units_tree, hf_pcp_units_dimtime, tvb, bits_offset, 4, ENC_BIG_ENDIAN);
bits_offset += 4;
proto_tree_add_bits_item(pcp_desc_units_tree, hf_pcp_units_dimcount, tvb, bits_offset, 4, ENC_BIG_ENDIAN);
bits_offset += 4;
proto_tree_add_bits_item(pcp_desc_units_tree, hf_pcp_units_scalespace, tvb, bits_offset, 4, ENC_BIG_ENDIAN);
bits_offset += 4;
proto_tree_add_bits_item(pcp_desc_units_tree, hf_pcp_units_scaletime, tvb, bits_offset, 4, ENC_BIG_ENDIAN);
bits_offset += 4;
proto_tree_add_bits_item(pcp_desc_units_tree, hf_pcp_units_scalecount, tvb, bits_offset, 4, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(pcp_desc_units_tree, hf_pcp_pdu_padding, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static int dissect_pcp_message_instance_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_instance_req_item;
proto_tree *pcp_instance_req_tree;
guint32 name_len;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(INSTANCE_REQ, packettypenames, "Unknown Type:0x%02x"));
pcp_instance_req_item = proto_tree_add_item(tree, hf_pcp_instance_req, tvb, offset, -1, ENC_NA);
pcp_instance_req_tree = proto_item_add_subtree(pcp_instance_req_item, ett_pcp);
proto_tree_add_item(pcp_instance_req_tree, hf_pcp_instance_indom, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_pcp_partial_when(tvb, pinfo, pcp_instance_req_tree, offset);
proto_tree_add_item(pcp_instance_req_tree, hf_pcp_pmid_inst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_instance_req_tree, hf_pcp_instance_namelen, tvb, offset, 4, ENC_BIG_ENDIAN);
name_len = tvb_get_ntohl(tvb, offset);
offset += 4;
if (name_len > 0) {
proto_tree_add_item(pcp_instance_req_tree, hf_pcp_instance_name, tvb, offset, name_len, ENC_ASCII|ENC_NA);
offset += name_len;
}
return offset;
}
static int dissect_pcp_message_text_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_text_req_item;
proto_tree *pcp_text_req_tree;
proto_item *pcp_text_req_type_item;
proto_tree *pcp_text_req_type_tree;
guint32 bits_offset;
guint32 type;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(TEXT_REQ, packettypenames, "Unknown Type:0x%02x"));
pcp_text_req_item = proto_tree_add_item(tree, hf_pcp_text_req, tvb, offset, -1, ENC_NA);
pcp_text_req_tree = proto_item_add_subtree(pcp_text_req_item, ett_pcp);
type = tvb_get_ntohl(tvb, offset + 4);
if (type & PM_TEXT_PMID) {
offset = dissect_pcp_partial_pmid(tvb, pinfo, pcp_text_req_tree, offset);
} else if (type & PM_TEXT_INDOM) {
proto_tree_add_item(pcp_text_req_tree, hf_pcp_instance_indom, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
pcp_text_req_type_item = proto_tree_add_item(pcp_text_req_tree, hf_pcp_text_type, tvb, offset, 4, ENC_NA);
pcp_text_req_type_tree = proto_item_add_subtree(pcp_text_req_type_item, ett_pcp);
bits_offset = offset * 8 + 28;
proto_tree_add_bits_item(pcp_text_req_type_tree, hf_pcp_text_type_ident, tvb, bits_offset, 2, ENC_BIG_ENDIAN);
bits_offset += 2;
proto_tree_add_bits_item(pcp_text_req_type_tree, hf_pcp_text_type_format, tvb, bits_offset, 2, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_pcp_message_text(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_text_item;
proto_tree *pcp_text_tree;
guint32 buflen;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(TEXT, packettypenames, "Unknown Type:0x%02x"));
pcp_text_item = proto_tree_add_item(tree, hf_pcp_text, tvb, offset, -1, ENC_NA);
pcp_text_tree = proto_item_add_subtree(pcp_text_item, ett_pcp);
proto_tree_add_item(pcp_text_tree, hf_pcp_text_ident, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
buflen = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(pcp_text_tree, hf_pcp_text_buflen, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_text_tree, hf_pcp_text_buffer, tvb, offset, buflen, ENC_ASCII|ENC_NA);
offset += buflen;
return offset;
}
static int dissect_pcp_message_instance(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pcp_instances_item;
proto_tree *pcp_instances_tree;
proto_item *pcp_instance_item;
proto_tree *pcp_instance_tree;
guint32 num_inst;
guint32 i;
guint32 name_len;
guint32 padding;
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s]", val_to_str(INSTANCE, packettypenames, "Unknown Type:0x%02x"));
pcp_instances_item = proto_tree_add_item(tree, hf_pcp_instances, tvb, offset, -1, ENC_NA);
pcp_instances_tree = proto_item_add_subtree(pcp_instances_item, ett_pcp);
proto_tree_add_item(pcp_instances_tree, hf_pcp_instance_indom, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_instances_tree, hf_pcp_instances_numinst, tvb, offset, 4, ENC_BIG_ENDIAN);
num_inst = tvb_get_ntohl(tvb, offset);
offset += 4;
for (i=0; i<num_inst; i++) {
name_len = tvb_get_ntohl(tvb, offset+4);
pcp_instance_item = proto_tree_add_item(pcp_instances_tree, hf_pcp_instance, tvb, offset, name_len+8, ENC_NA);
pcp_instance_tree = proto_item_add_subtree(pcp_instance_item, ett_pcp);
proto_tree_add_item(pcp_instance_tree, hf_pcp_pmid_inst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_instance_tree, hf_pcp_instance_namelen, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (name_len > 0) {
proto_tree_add_item(pcp_instance_tree, hf_pcp_instance_name, tvb, offset, name_len, ENC_ASCII|ENC_NA);
offset += name_len;
}
padding = name_len % 4;
if (padding != 0) {
padding = 4 - padding;
proto_tree_add_item(pcp_instance_tree, hf_pcp_pdu_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
}
return offset;
}
static int dissect_pcp_partial_pmid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *pcp_pmid_item;
proto_tree *pcp_pmid_tree;
guint32 bits_offset;
bits_offset = offset * 8;
pcp_pmid_item = proto_tree_add_item(tree, hf_pcp_pmid, tvb, offset, 4, ENC_BIG_ENDIAN);
pcp_pmid_tree = proto_item_add_subtree(pcp_pmid_item, ett_pcp);
proto_tree_add_bits_item(pcp_pmid_tree, hf_pcp_pmid_flag, tvb, bits_offset, 1, ENC_BIG_ENDIAN);
bits_offset += 1;
proto_tree_add_bits_item(pcp_pmid_tree, hf_pcp_pmid_domain, tvb, bits_offset, 9, ENC_BIG_ENDIAN);
bits_offset += 9;
proto_tree_add_bits_item(pcp_pmid_tree, hf_pcp_pmid_cluster, tvb, bits_offset, 12, ENC_BIG_ENDIAN);
bits_offset += 12;
proto_tree_add_bits_item(pcp_pmid_tree, hf_pcp_pmid_item, tvb, bits_offset, 10, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_pcp_partial_when(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *pcp_when_item;
proto_tree *pcp_when_tree;
pcp_when_item = proto_tree_add_item(tree, hf_pcp_when, tvb, offset, 8, ENC_NA);
pcp_when_tree = proto_item_add_subtree(pcp_when_item, ett_pcp);
proto_tree_add_item(pcp_when_tree, hf_pcp_when_sec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_when_tree, hf_pcp_when_usec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_pcp_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *root_pcp_item;
proto_tree *pcp_tree;
guint32 packet_type;
gint32 err_bytes;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PCP");
col_clear(pinfo->cinfo, COL_INFO);
root_pcp_item = proto_tree_add_item(tree, proto_pcp, tvb, 0, -1, ENC_NA);
pcp_tree = proto_item_add_subtree(root_pcp_item, ett_pcp);
packet_type = tvb_get_ntohl(tvb, 4);
if (pinfo->srcport == PCP_PORT) {
col_set_str(pinfo->cinfo, COL_INFO, "Server > Client ");
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Client > Server ");
}
proto_tree_add_item(pcp_tree, hf_pcp_pdu_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_tree, hf_pcp_pdu_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pcp_tree, hf_pcp_pdu_pid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (packet_type) {
case CREDS:
dissect_pcp_message_creds(tvb, pinfo, pcp_tree, offset);
break;
case START_OR_ERROR:
err_bytes = tvb_get_ntohl(tvb, offset);
if (err_bytes < 0) {
dissect_pcp_message_error(tvb, pinfo, pcp_tree, offset);
} else {
dissect_pcp_message_start(tvb, pinfo, pcp_tree, offset);
}
break;
case PMNS_TRAVERSE:
dissect_pcp_message_pmns_traverse(tvb, pinfo, pcp_tree, offset);
break;
case PMNS_NAMES:
dissect_pcp_message_pmns_names(tvb, pinfo, pcp_tree, offset);
break;
case PMNS_CHILD:
dissect_pcp_message_pmns_child(tvb, pinfo, pcp_tree, offset);
break;
case PMNS_IDS:
dissect_pcp_message_pmns_ids(tvb, pinfo, pcp_tree, offset);
break;
case PROFILE:
dissect_pcp_message_profile(tvb, pinfo, pcp_tree, offset);
break;
case FETCH:
dissect_pcp_message_fetch(tvb, pinfo, pcp_tree, offset);
break;
case RESULT:
dissect_pcp_message_result(tvb, pinfo, pcp_tree, offset);
break;
case DESC_REQ:
dissect_pcp_message_desc_req(tvb, pinfo, pcp_tree, offset);
break;
case DESC:
dissect_pcp_message_desc(tvb, pinfo, pcp_tree, offset);
break;
case INSTANCE_REQ:
dissect_pcp_message_instance_req(tvb, pinfo, pcp_tree, offset);
break;
case INSTANCE:
dissect_pcp_message_instance(tvb, pinfo, pcp_tree, offset);
break;
case TEXT_REQ:
dissect_pcp_message_text_req(tvb, pinfo, pcp_tree, offset);
break;
case TEXT:
dissect_pcp_message_text(tvb, pinfo, pcp_tree, offset);
break;
default:
col_append_str(pinfo->cinfo, COL_INFO, "[UNIMPLEMENTED TYPE]");
expert_add_info(pinfo, pcp_tree, &ei_pcp_unimplemented_packet_type);
break;
}
return tvb_length(tvb);
}
static int dissect_pcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, PCP_HEADER_LEN, get_pcp_message_len, dissect_pcp_message, data);
return tvb_length(tvb);
}
void proto_register_pcp(void)
{
static hf_register_info hf[] = {
{ &hf_pcp_pdu_length,
{ "PDU Length", "pcp.length",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pdu_type,
{ "Type", "pcp.type",
FT_UINT32, BASE_HEX,
VALS(packettypenames), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pdu_pid,
{ "From", "pcp.from",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pdu_error,
{ "Error", "pcp.error",
FT_INT32, BASE_DEC,
VALS(packettypenames_errors), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pdu_padding,
{ "Padding", "pcp.padding",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_creds_number_of,
{ "Number of Credentials", "pcp.creds.number",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_creds_type,
{ "Credentials Type", "pcp.creds.type",
FT_UINT8, BASE_DEC,
VALS(packettypenames_creds), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_creds_vala,
{ "Credentials Value A", "pcp.creds.vala",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_creds_valb,
{ "Credentials Value B", "pcp.creds.valb",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_creds_valc,
{ "Credentials Value C", "pcp.creds.valc",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_start,
{ "Start", "pcp.start",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_start_zero,
{ "Start Compatibility Bit", "pcp.start.zero",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_start_version,
{ "Version", "pcp.start.version",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_start_status,
{ "Start Status", "pcp.start.status",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_start_licensed,
{ "Licensed", "pcp.start.licensed",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_start_authorize,
{ "Authorize", "pcp.start.authorize",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_traverse,
{ "PMNS Traverse", "pcp.pmns_traverse",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_subtype,
{ "Subtype", "pcp.pmns.subtype",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_namelen,
{ "Name Length", "pcp.pmns.namelen",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_name,
{ "Name", "pcp.pmns.name",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_names,
{ "PMNS Names", "pcp.pmns_names",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_names_nstrbytes,
{ "String Bytes", "pcp.pmns_names.nstrbytes",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_names_numstatus,
{ "Status", "pcp.pmns_names.numstatus",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_names_numnames,
{ "Number of Names", "pcp.pmns_names.numnames",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_names_nametree,
{ "Names", "pcp.pmns_names.nametree",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_names_nametree_status,
{ "Status", "pcp.pmns_names.nametree.status",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_names_nametree_namelen,
{ "Length", "pcp.pmns_names.nametree.namelen",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_names_nametree_name,
{ "Name", "pcp.pmns_names.nametree.name",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_ids,
{ "PMNS IDs", "pcp.pmns_ids",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_ids_status,
{ "Status", "pcp.pmns_ids.status",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_ids_numids,
{ "Number of IDs", "pcp.pmns_ids.numids",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmns_child,
{ "PMID Child", "pcp.pmns.child",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmid,
{ "PMID", "pcp.pmid",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmid_flag,
{ "Flag", "pcp.pmid.flag",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmid_domain,
{ "Domain", "pcp.pmid.domain",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmid_cluster,
{ "Cluster", "pcp.pmid.cluster",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmid_item,
{ "Item", "pcp.pmid.item",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmid_type,
{ "Type", "pcp.pmid.type",
FT_INT8, BASE_DEC,
VALS(packettypenames_pm_types), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmid_sem,
{ "Type Semantics", "pcp.pmid.sem",
FT_UINT32, BASE_DEC,
VALS(packettypenames_pm_types_sem), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_pmid_inst,
{ "Instance", "pcp.pmid.inst",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_profile,
{ "Profile", "pcp.profile",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_ctxnum,
{ "Context Number", "pcp.ctxnum",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_profile_g_state,
{ "Global Include/Exclude State", "pcp.profile.g_state",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_profile_numprof,
{ "Number of Profiles", "pcp.profile.numprof",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_profile_profile,
{ "Each Profile", "pcp.profile.profile",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_profile_profile_state,
{ "Include/Exclude State", "pcp.profile.profile.state",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_profile_profile_numinst,
{ "Number Instances to Follow", "pcp.profile.profile.numinst",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_fetch,
{ "Fetch", "pcp.fetch",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_fetch_numpmid,
{ "Number PMIDs", "pcp.fetch.numpmid",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_when,
{ "Time Value", "pcp.when",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_when_sec,
{ "Seconds", "pcp.when.sec",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_when_usec,
{ "Microseconds", "pcp.when.usec",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_desc_req,
{ "Description Request", "pcp.desc_req",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_desc,
{ "Description Response", "pcp.desc",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_units,
{ "PMID Units", "pcp.units",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_units_dimspace,
{ "Dimension Space", "pcp.units.dimspace",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_units_dimtime,
{ "Dimension Time", "pcp.units.dimtime",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_units_dimcount,
{ "Dimension Count", "pcp.units.dimcount",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_units_scalespace,
{ "Scale Space", "pcp.units.scalespace",
FT_UINT8, BASE_DEC,
VALS(packettypenames_pm_units_space), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_units_scaletime,
{ "Scale Time", "pcp.units.scalespace",
FT_UINT8, BASE_DEC,
VALS(packettypenames_pm_units_time), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_units_scalecount,
{ "Scale Count", "pcp.units.scalecount",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_req,
{ "Instance Request", "pcp.instance_req",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instances,
{ "Instance Response", "pcp.instances",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instances_numinst,
{ "Number of Instances", "pcp.instance_resp.numinst",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance,
{ "Instance", "pcp.instance",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_namelen,
{ "Name Length", "pcp.instance.namelen",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_name,
{ "Name", "pcp.instance.name",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_indom,
{ "Instance Domain", "pcp.instance.indom",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_valoffset,
{ "Instance Offset", "pcp.instance.valoffset",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_vallength,
{ "Instance Value Length", "pcp.instance.vallength",
FT_INT24, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_value_insitu,
{ "Instance Value", "pcp.instance.value.uint",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_value_ptr,
{ "Instance Value", "pcp.instance.value.string",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_value_int,
{ "Instance Value", "pcp.instance.value.int",
FT_INT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_value_uint,
{ "Instance Value", "pcp.instance.value.uint",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_value_int64,
{ "Instance Value", "pcp.instance.value.int64",
FT_INT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_value_uint64,
{ "Instance Value", "pcp.instance.value.uint64",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_value_float,
{ "Instance Value", "pcp.instance.value.float",
FT_FLOAT, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_value_double,
{ "Instance Value", "pcp.instance.value.float",
FT_DOUBLE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_instance_value_aggr,
{ "Instance Value", "pcp.instance.value.bytes",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_results,
{ "Fetch Results", "pcp.results",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_results_numpmid,
{ "Number of PMIDs", "pcp.results.numpmid",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_result,
{ "Result", "pcp.result",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_result_numval,
{ "Number of Values", "pcp.result.numval",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_result_valfmt,
{ "Value Encoding Format", "pcp.result.valfmt",
FT_UINT32, BASE_DEC,
VALS(packettypenames_valfmt), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_text_req,
{ "Text Request", "pcp.text_req",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_text_type,
{ "Help Text Type", "pcp.text.type",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_text_type_format,
{ "Text Type Format", "pcp.text.type.format",
FT_UINT8, BASE_DEC,
VALS(packettypenames_text_type_format), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_text_type_ident,
{ "Text Type Ident", "pcp.text.type.ident",
FT_UINT8, BASE_DEC,
VALS(packettypenames_text_type_ident), 0x0,
NULL, HFILL
}
},
{ &hf_pcp_text,
{ "Text Response", "pcp.text",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_text_ident,
{ "Text Ident (raw)", "pcp.text.ident",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_text_buflen,
{ "Text Buffer Length", "pcp.text.buflen",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcp_text_buffer,
{ "Text Buffer", "pcp.text.buffer",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_pcp,
&ett_pcp_pdu_length,
&ett_pcp_pdu_type,
&ett_pcp_pdu_pid,
&ett_pcp_pdu_error,
&ett_pcp_pdu_padding,
&ett_pcp_creds_number_of,
&ett_pcp_creds_type,
&ett_pcp_creds_vala,
&ett_pcp_creds_valb,
&ett_pcp_creds_valc,
&ett_pcp_start,
&ett_pcp_start_status,
&ett_pcp_start_zero,
&ett_pcp_start_version,
&ett_pcp_start_licensed,
&ett_pcp_start_authorize,
&ett_pcp_pmns_traverse,
&ett_pcp_pmns_subtype,
&ett_pcp_pmns_namelen,
&ett_pcp_pmns_name,
&ett_pcp_pmns_names,
&ett_pcp_pmns_names_nstrbytes,
&ett_pcp_pmns_names_numstatus,
&ett_pcp_pmns_names_numnames,
&ett_pcp_pmns_names_nametree,
&ett_pcp_pmns_names_nametree_status,
&ett_pcp_pmns_names_nametree_namelen,
&ett_pcp_pmns_names_nametree_name,
&ett_pcp_pmns_ids,
&ett_pcp_pmns_ids_status,
&ett_pcp_pmns_ids_numids,
&ett_pcp_pmns_child,
&ett_pcp_pmid,
&ett_pcp_pmid_flag,
&ett_pcp_pmid_domain,
&ett_pcp_pmid_cluster,
&ett_pcp_pmid_item,
&ett_pcp_pmid_type,
&ett_pcp_pmid_sem,
&ett_pcp_profile,
&ett_pcp_ctxnum,
&ett_pcp_profile_g_state,
&ett_pcp_profile_numprof,
&ett_pcp_profile_profile,
&ett_pcp_profile_profile_state,
&ett_pcp_profile_profile_numinst,
&ett_pcp_fetch,
&ett_pcp_fetch_numpmid,
&ett_pcp_when,
&ett_pcp_when_sec,
&ett_pcp_when_usec,
&ett_pcp_desc_req,
&ett_pcp_units,
&ett_pcp_units_dimspace,
&ett_pcp_units_dimtime,
&ett_pcp_units_dimcount,
&ett_pcp_units_scalespace,
&ett_pcp_units_scaletime,
&ett_pcp_units_scalecount,
&ett_pcp_instance,
&ett_pcp_instance_req,
&ett_pcp_instance_namelen,
&ett_pcp_instance_name,
&ett_pcp_instance_indom,
&ett_pcp_instance_inst,
&ett_pcp_instance_valoffset,
&ett_pcp_instance_vallength,
&ett_pcp_instance_value_insitu,
&ett_pcp_instance_value_ptr,
&ett_pcp_instance_value_int,
&ett_pcp_instance_value_uint,
&ett_pcp_instance_value_int64,
&ett_pcp_instance_value_uint64,
&ett_pcp_instance_value_float,
&ett_pcp_instance_value_double,
&ett_pcp_instance_value_aggr,
&ett_pcp_instances,
&ett_pcp_instances_numinst,
&ett_pcp_results,
&ett_pcp_results_numpmid,
&ett_pcp_result,
&ett_pcp_result_numval,
&ett_pcp_result_valfmt,
&ett_pcp_text_req,
&ett_pcp_text_type,
&ett_pcp_text_type_format,
&ett_pcp_text_type_ident,
&ett_pcp_text,
&ett_pcp_text_ident,
&ett_pcp_text_buflen,
&ett_pcp_text_buffer,
};
static ei_register_info ei[] = {
{ &ei_pcp_type_event_unimplemented, { "pcp.pmid.type.event.unimplemented", PI_UNDECODED, PI_WARN, "PM_TYPE_EVENT: Unimplemented Value Type", EXPFILL }},
{ &ei_pcp_type_nosupport_unsupported, { "pcp.pmid.type.nosupport.unsupported", PI_UNDECODED, PI_WARN, "PM_TYPE_NOSUPPORT: Unsupported Value Type", EXPFILL }},
{ &ei_pcp_type_unknown_unknown_value, { "pcp.pmid.type.unknown.unknown_value", PI_UNDECODED, PI_WARN, "PM_TYPE_UNKNOWN: Unknown Value Type", EXPFILL }},
{ &ei_pcp_unimplemented_value, { "pcp.pmid.type.unimplemented", PI_UNDECODED, PI_WARN, "Unimplemented Value Type", EXPFILL }},
{ &ei_pcp_unimplemented_packet_type, { "pcp.type.unimplemented", PI_UNDECODED, PI_WARN, "Unimplemented Packet Type", EXPFILL }},
};
expert_module_t* expert_pcp;
expert_pcp = expert_register_protocol(proto_pcp);
expert_register_field_array(expert_pcp, ei, array_length(ei));
proto_pcp = proto_register_protocol("Performance Co-Pilot", "PCP", "pcp");
proto_register_field_array(proto_pcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pcp(void)
{
dissector_handle_t pcp_handle;
pcp_handle = new_create_dissector_handle(dissect_pcp, proto_pcp);
dissector_add_uint("tcp.port", PCP_PORT, pcp_handle);
}
