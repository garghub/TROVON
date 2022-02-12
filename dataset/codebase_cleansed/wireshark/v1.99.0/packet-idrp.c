static int dissect_BISPDU_OPEN(tvbuff_t * tvb, int offset, proto_tree * tree)
{
guint8 rdi_len;
guint8 number_of_non_empty_rib_attributes;
guint8 number_of_distinguishing_attributes;
guint8 rib_attribute_type;
guint8 number_of_rdcs;
guint8 length_indicator_guint8;
gint i;
gint j;
proto_tree_add_item(tree, hf_idrp_open_version, tvb, offset,1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_idrp_open_hold_time, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_idrp_open_max_pdu_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
rdi_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_idrp_open_src_rdi, tvb, offset, rdi_len, ENC_NA);
offset += rdi_len;
number_of_non_empty_rib_attributes = tvb_get_guint8(tvb, offset);
offset += 1;
for (i = number_of_non_empty_rib_attributes; i > 0; i--) {
number_of_distinguishing_attributes = tvb_get_guint8(tvb, offset);
offset += 1;
for (j = number_of_distinguishing_attributes; j > 0; j--) {
rib_attribute_type = tvb_get_guint8(tvb, offset);
offset += 1;
switch (rib_attribute_type) {
case IDRP_PATH_ATTR_TYPE_ROUTE_SEPARATOR:
case IDRP_PATH_ATTR_TYPE_EXT_INFO:
case IDRP_PATH_ATTR_TYPE_RD_PATH:
case IDRP_PATH_ATTR_TYPE_NEXT_HOP:
case IDRP_PATH_ATTR_TYPE_DIST_LIST_EXCL:
case IDRP_PATH_ATTR_TYPE_DIST_LIST_INCL:
case IDRP_PATH_ATTR_TYPE_MULTI_EXIT_DISC:
case IDRP_PATH_ATTR_TYPE_RESIDUAL_ERROR:
case IDRP_PATH_ATTR_TYPE_EXPENSE:
case IDRP_PATH_ATTR_TYPE_HIERARCHICALRECORDING:
case IDRP_PATH_ATTR_TYPE_RD_HOP_COUNT:
case IDRP_PATH_ATTR_TYPE_CAPACITY:
case IDRP_PATH_ATTR_TYPE_PRIORITY:
break;
case IDRP_PATH_ATTR_TYPE_LOCALLY_DEFINED_QOS:
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
tree,
hf_idrp_open_rib_attr_locally_defined_qos_nsap,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
tree,
hf_idrp_open_rib_attr_locally_defined_qos_value,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
tree,
hf_idrp_open_rib_attr_locally_defined_qos_metric,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
break;
case IDRP_PATH_ATTR_TYPE_SECURITY:
offset += 2;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
tree,
hf_idrp_open_rib_attr_security_reg_id,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
tree,
hf_idrp_open_rib_attr_security_info,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
break;
default:
break;
}
}
}
number_of_rdcs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_idrp_open_number_of_confederations, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i = number_of_rdcs; i > 0; i--) {
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_idrp_open_confederation, tvb,
offset, length_indicator_guint8, ENC_NA);
offset += length_indicator_guint8;
}
proto_tree_add_item(tree, hf_idrp_open_authentication_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_idrp_open_authentication_data, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int dissect_BISPDU_UPDATE(tvbuff_t * tvb, int offset, proto_tree * tree)
{
guint16 nb_unfeasible_routes;
guint16 path_attrs_len;
int path_attrs_start_offset;
guint8 path_attr_type;
guint16 path_attr_len;
int start_offset;
guint16 rdi_len;
guint8 proto_len;
guint16 net_len;
int path_segment_rdi_offset;
guint16 length_indicator_guint16;
guint8 length_indicator_guint8;
guint8 nb_of_snpa;
guint8 dist_list_count;
int i;
nb_unfeasible_routes = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_idrp_update_number_of_unfeasible_routes,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for (i = nb_unfeasible_routes; i > 0; i--) {
proto_tree_add_item(tree, hf_idrp_update_withdrawn_route, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
path_attrs_len = tvb_get_ntohs(tvb, offset);
offset += 2;
path_attrs_start_offset = offset;
while (offset < (path_attrs_start_offset + path_attrs_len)) {
proto_tree_add_item(tree, hf_idrp_update_path_attr_flag, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
path_attr_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_idrp_update_path_attr_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
path_attr_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_idrp_update_path_attr_length, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (path_attr_type) {
case IDRP_PATH_ATTR_TYPE_ROUTE_SEPARATOR:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_route_separator_id,
tvb,
offset,
4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_route_separator_localpref,
tvb,
offset,
1,
ENC_BIG_ENDIAN);
offset ++ ;
break;
case IDRP_PATH_ATTR_TYPE_EXT_INFO:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_ext_info,
tvb,
offset,
0,
ENC_BIG_ENDIAN);
break;
case IDRP_PATH_ATTR_TYPE_RD_PATH:
start_offset = offset;
while (offset < (start_offset + path_attr_len)) {
proto_tree_add_item(tree,
hf_idrp_update_path_attr_rd_path_type,
tvb,
offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
length_indicator_guint16 = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree,
hf_idrp_update_path_attr_rd_path_segment_length,
tvb,
offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
path_segment_rdi_offset = offset;
while (offset < (path_segment_rdi_offset + length_indicator_guint16)) {
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_rd_path_rdi,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
}
}
break;
case IDRP_PATH_ATTR_TYPE_NEXT_HOP:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_next_hop_idrp_server,
tvb,
offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
start_offset = offset;
while (offset < (start_offset + path_attr_len)) {
proto_tree_add_item(tree,
hf_idrp_update_path_attr_next_hop_proto_type,
tvb,
offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_next_hop_proto,
tvb,
offset,
length_indicator_guint8,
ENC_ASCII | ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_next_hop_rdi,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
nb_of_snpa = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree,
hf_idrp_update_path_attr_next_hop_nb_snpa,
tvb,
offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
for (i = nb_of_snpa; i > 0; i--) {
length_indicator_guint8 =
(guint8) ceil((float)tvb_get_guint8(tvb, offset) / (float)2.0);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_next_hop_snpa,
tvb,
offset,
length_indicator_guint8 ,
ENC_NA);
offset += length_indicator_guint8;
}
}
break;
case IDRP_PATH_ATTR_TYPE_DIST_LIST_EXCL:
dist_list_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree,
hf_idrp_update_path_attr_dist_list_excl_nb_rdi,
tvb,
offset,
1 ,
ENC_BIG_ENDIAN);
offset += 1;
for (i = dist_list_count; i > 0; i--) {
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_dist_list_excl_rdi ,
tvb,
offset,
length_indicator_guint8 ,
ENC_NA);
offset += length_indicator_guint8;
}
break;
case IDRP_PATH_ATTR_TYPE_DIST_LIST_INCL:
dist_list_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree,
hf_idrp_update_path_attr_dist_list_incl_nb_rdi,
tvb,
offset,
1 ,
ENC_BIG_ENDIAN);
offset += 1;
for (i = dist_list_count; i > 0; i--) {
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_dist_list_incl_rdi ,
tvb,
offset,
length_indicator_guint8 ,
ENC_NA);
offset += length_indicator_guint8;
}
break;
case IDRP_PATH_ATTR_TYPE_MULTI_EXIT_DISC:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_multi_exit_disc ,
tvb,
offset,
1 ,
ENC_BIG_ENDIAN);
offset += 1;
break;
case IDRP_PATH_ATTR_TYPE_TRANSIT_DELAY:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_transit_delay ,
tvb,
offset,
2 ,
ENC_BIG_ENDIAN);
offset += 2;
break;
case IDRP_PATH_ATTR_TYPE_RESIDUAL_ERROR:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_residual_error ,
tvb,
offset,
4 ,
ENC_BIG_ENDIAN);
offset += 4;
break;
case IDRP_PATH_ATTR_TYPE_EXPENSE:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_expense ,
tvb,
offset,
2 ,
ENC_BIG_ENDIAN);
offset += 2;
break;
case IDRP_PATH_ATTR_TYPE_LOCALLY_DEFINED_QOS:
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_locally_defined_qos_nsap ,
tvb,
offset,
length_indicator_guint8 ,
ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_locally_defined_qos_value,
tvb,
offset,
length_indicator_guint8 ,
ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_locally_defined_qos_metric,
tvb,
offset,
length_indicator_guint8 ,
ENC_NA);
offset += length_indicator_guint8;
break;
case IDRP_PATH_ATTR_TYPE_HIERARCHICALRECORDING:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_hierarchicaldecoding,
tvb,
offset,
1 ,
ENC_BIG_ENDIAN);
offset += 1;
break;
case IDRP_PATH_ATTR_TYPE_RD_HOP_COUNT:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_rd_hop_count,
tvb,
offset,
1 ,
ENC_BIG_ENDIAN);
offset += 1;
break;
case IDRP_PATH_ATTR_TYPE_SECURITY:
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_security_reg_id,
tvb,
offset,
length_indicator_guint8 ,
ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree,
hf_idrp_update_path_attr_security_info,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
break;
case IDRP_PATH_ATTR_TYPE_CAPACITY:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_capacity,
tvb,
offset,
1 ,
ENC_BIG_ENDIAN);
offset += 1;
break;
case IDRP_PATH_ATTR_TYPE_PRIORITY:
proto_tree_add_item(tree,
hf_idrp_update_path_attr_priority,
tvb,
offset,
1 ,
ENC_BIG_ENDIAN);
offset += 1;
break;
default:
break;
}
}
proto_tree_add_item(tree, hf_idrp_update_nlri_proto_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_idrp_update_nlri_proto_id, tvb, offset,
proto_len, ENC_NA);
offset += proto_len;
net_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_idrp_update_nlri_addr_length, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
start_offset = offset;
while (offset < (start_offset + net_len)) {
rdi_len = tvb_get_guint8(tvb, offset) / 8;
proto_tree_add_item(tree, hf_idrp_update_nlri_addr_info_nb_bits, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_idrp_update_nlri_addr_info, tvb,
offset, rdi_len, ENC_NA);
offset += rdi_len;
}
return offset;
}
static int dissect_BISPDU_ERROR(tvbuff_t * tvb, int offset, proto_tree * tree)
{
guint8 error_code = 0;
gint data_length;
error_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_idrp_error_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (error_code) {
case IDRP_ERROR_OPEN:
proto_tree_add_item(tree, hf_idrp_error_open_subcode, tvb, offset, 1,
ENC_BIG_ENDIAN);
break;
case IDRP_ERROR_UPDATE:
proto_tree_add_item(tree, hf_idrp_error_update_subcode, tvb, offset, 1,
ENC_BIG_ENDIAN);
break;
case IDRP_ERROR_HOLD_TIMER:
proto_tree_add_item(tree, hf_idrp_error_hold_timer_subcode, tvb,
offset, 1, ENC_BIG_ENDIAN);
break;
case IDRP_ERROR_FSM:
proto_tree_add_item(tree, hf_idrp_error_fsm_subcode, tvb, offset, 1,
ENC_BIG_ENDIAN);
break;
case IDRP_ERROR_RIB_REFRESH:
proto_tree_add_item(tree, hf_idrp_error_rib_refresh_subcode, tvb,
offset, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset += 1;
data_length = tvb_reported_length_remaining(tvb, offset);
if (data_length>0) {
proto_tree_add_item(tree, hf_idrp_error_data, tvb, offset, data_length,
ENC_NA);
offset += data_length;
}
return offset;
}
static int dissect_BISPDU_RIB_REFRESH(tvbuff_t * tvb, packet_info *pinfo, int offset, proto_tree * tree)
{
proto_tree *sub_tree;
proto_item *sub_item;
guint8 number_of_non_empty_rib_attributes;
guint8 number_of_distinguishing_attributes;
guint8 rib_attribute_type;
guint8 length_indicator_guint8;
int i;
int j;
proto_tree_add_item(tree, hf_idrp_rib_refresh_opcode, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_idrp_sub, &sub_item, "Path Attributes");
number_of_non_empty_rib_attributes = tvb_get_guint8(tvb, offset);
offset += 1;
if (!number_of_non_empty_rib_attributes)
expert_add_info(pinfo, sub_item, &ei_idrp_no_path_attributes);
for (i = number_of_non_empty_rib_attributes; i > 0; i--) {
number_of_distinguishing_attributes = tvb_get_guint8(tvb, offset);
offset += 1;
for (j = number_of_distinguishing_attributes; j > 0; j--) {
rib_attribute_type = tvb_get_guint8(tvb, offset);
offset += 1;
switch (rib_attribute_type) {
case IDRP_PATH_ATTR_TYPE_ROUTE_SEPARATOR:
case IDRP_PATH_ATTR_TYPE_EXT_INFO:
case IDRP_PATH_ATTR_TYPE_RD_PATH:
case IDRP_PATH_ATTR_TYPE_NEXT_HOP:
case IDRP_PATH_ATTR_TYPE_DIST_LIST_EXCL:
case IDRP_PATH_ATTR_TYPE_DIST_LIST_INCL:
case IDRP_PATH_ATTR_TYPE_MULTI_EXIT_DISC:
case IDRP_PATH_ATTR_TYPE_RESIDUAL_ERROR:
case IDRP_PATH_ATTR_TYPE_EXPENSE:
case IDRP_PATH_ATTR_TYPE_HIERARCHICALRECORDING:
case IDRP_PATH_ATTR_TYPE_RD_HOP_COUNT:
case IDRP_PATH_ATTR_TYPE_CAPACITY:
case IDRP_PATH_ATTR_TYPE_PRIORITY:
break;
case IDRP_PATH_ATTR_TYPE_LOCALLY_DEFINED_QOS:
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
sub_tree,
hf_idrp_rib_refresh_rib_attr_locally_defined_qos_nsap,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
sub_tree,
hf_idrp_rib_refresh_rib_attr_locally_defined_qos_value,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
sub_tree,
hf_idrp_rib_refresh_rib_attr_locally_defined_qos_metric,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
break;
case IDRP_PATH_ATTR_TYPE_SECURITY:
offset += 2;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
sub_tree,
hf_idrp_rib_refresh_rib_attr_security_reg_id,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
length_indicator_guint8 = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(
sub_tree,
hf_idrp_rib_refresh_rib_attr_security_info,
tvb,
offset,
length_indicator_guint8,
ENC_NA);
offset += length_indicator_guint8;
break;
default:
break;
}
}
}
return offset;
}
static int
dissect_idrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *idrp_tree;
guint8 pdu_type;
gint offset = 0;
if (tvb_get_guint8(tvb, offset) != NLPID_ISO10747_IDRP)
return 0;
offset += 1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IDRP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_idrp, tvb, 0, -1, ENC_NA);
idrp_tree = proto_item_add_subtree(ti, ett_idrp);
proto_tree_add_item(idrp_tree, hf_idrp_li,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
pdu_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(idrp_tree, hf_idrp_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(idrp_tree, hf_idrp_sequence,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(idrp_tree, hf_idrp_ack,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(idrp_tree, hf_idrp_credit_offered,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(idrp_tree, hf_idrp_credit_avail,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(idrp_tree, hf_idrp_validation_pattern,
tvb, offset, 16, ENC_NA);
offset += 16;
switch (pdu_type) {
case IDRP_TYPE_OPEN:
offset = dissect_BISPDU_OPEN(tvb, offset, idrp_tree);
break;
case IDRP_TYPE_UPDATE:
offset = dissect_BISPDU_UPDATE(tvb, offset, idrp_tree);
break;
case IDRP_TYPE_ERROR:
offset = dissect_BISPDU_ERROR(tvb, offset, idrp_tree);
break;
case IDRP_TYPE_KEEPALIVE:
offset += 30;
break;
case IDRP_TYPE_CEASE:
offset += 30;
break;
case IDRP_TYPE_RIB_REFRESH:
offset = dissect_BISPDU_RIB_REFRESH(tvb, pinfo, offset, idrp_tree);
break;
default:
break;
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(pdu_type, idrp_pdu_types, "Unknown (%u)"));
return offset;
}
void proto_register_idrp(void)
{
static hf_register_info hf_idrp[] = {
{&hf_idrp_li,
{"BISPDU Length", "idrp.li", FT_UINT16, BASE_DEC, NULL, 0x0,
"BISPDU Length Indicator, length of this PDU", HFILL}},
{&hf_idrp_type,
{"BISPDU Type", "idrp.type", FT_UINT8, BASE_DEC,
VALS(idrp_pdu_types), 0xff, NULL, HFILL}},
{&hf_idrp_sequence,
{"Sequence Number", "idrp.seq", FT_UINT32, BASE_DEC, NULL, 0x0,
"Sequence number, Sequence number of curent BISPDU ", HFILL}},
{&hf_idrp_ack,
{"Acknowledgment number", "idrp.ack", FT_UINT32, BASE_DEC, NULL, 0x0,
"Acknowledgment number, Sequence number of the PDU that the sender last received correctly and in sequence number order",
HFILL}},
{&hf_idrp_credit_offered,
{"Credits Offered", "idrp.credits-offered", FT_UINT8, BASE_DEC,
NULL, 0,
"Number of additional BISPDUs that the sender is willing to accept from the remote BIS",
HFILL}},
{&hf_idrp_credit_avail,
{"Credits Available", "idrp.credits-avail", FT_UINT8, BASE_DEC,
NULL, 0,
"Number of additional BISPDUs that the sender is able to send to the remote BIS",
HFILL}},
{&hf_idrp_validation_pattern,
{"Validation", "idrp.validation", FT_BYTES, BASE_NONE,
NULL, 0,
"16-octet field which provides a validation function for the BISPDU",
HFILL}},
{&hf_idrp_open_version,
{"Version", "idrp.open.version", FT_UINT8, BASE_DEC,
NULL, 0, "Version number of the protocol.", HFILL}},
{&hf_idrp_open_hold_time,
{"Hold Time", "idrp.open.hold-time", FT_UINT16, BASE_DEC,
NULL, 0, "Max number of seconds to remain in the ESTABLISHED state",
HFILL}},
{&hf_idrp_open_max_pdu_size,
{"Max PDU Size", "idrp.open.max-pdu-size", FT_UINT16, BASE_DEC,
NULL, 0,
"Maximum number of octets that this BIS will accept in an incoming UPDATE PDU, IDRP ERROR PDU, or RIB REFRESH PDU",
HFILL}},
{&hf_idrp_open_src_rdi,
{"Source RDI", "idrp.open.src-rdi", FT_BYTES, BASE_NONE,
NULL, 0,
"RDI of the routing domain in which the BIS that is sending this BISPDU is located",
HFILL}},
{&hf_idrp_open_rib_attr_locally_defined_qos_nsap,
{"Rib Attribute Value Locally Defined Qos NSAP",
"idrp.open.rib-attr.locally-defined-qos.nsap", FT_BYTES, BASE_NONE,
NULL, 0, "Locally Defined Qos NSAP" ,
HFILL}},
{&hf_idrp_open_rib_attr_locally_defined_qos_value,
{"Rib Attribute Value Locally Defined Qos",
"idrp.open.rib-attr.locally-defined-qos.qos", FT_BYTES, BASE_NONE,
NULL, 0, "Locally Defined Qos Value" ,
HFILL}},
{&hf_idrp_open_rib_attr_locally_defined_qos_metric,
{"Rib Attribute Value Locally Defined Qos Metric",
"idrp.open.rib-attr.locally-defined-qos.metric", FT_BYTES, BASE_NONE,
NULL, 0, "Locally Defined Metric" ,
HFILL}},
{&hf_idrp_open_rib_attr_security_reg_id,
{"Rib Attribute Value Security Registration ID",
"idrp.open.rib-attr.security.reg-id", FT_BYTES, BASE_NONE,
NULL, 0, "Identifys the Security Authority" ,
HFILL}},
{&hf_idrp_open_rib_attr_security_info,
{"Rib Attribute Value Security Registration ID",
"idrp.open.rib-attr.security.info", FT_BYTES, BASE_NONE,
NULL, 0, "Additional security related information" ,
HFILL}},
{&hf_idrp_open_number_of_confederations,
{"Number of Routing Confederations",
"idrp.open.number-of-confederations", FT_UINT8, BASE_DEC,
NULL, 0,
"Number of Routing Domain Identifiers (Routing Domain Confederation) that this BIS is a member of",
HFILL}},
{&hf_idrp_open_confederation,
{"Routing Confederation", "idrp.open.confederation", FT_BYTES,
BASE_NONE,
NULL, 0,
"Routing Domain Identifier of Routing Domain Confederation that this BIS is a member of",
HFILL}},
{&hf_idrp_open_authentication_code,
{"Authentication Code", "idrp.open.authentication-code", FT_UINT8,
BASE_DEC,
VALS(idrp_pdu_open_authentication_codes), 0,
"Indicates the authentication mechanism being used",
HFILL}},
{&hf_idrp_open_authentication_data,
{"Authentication Data", "idrp.open.authentication-data", FT_BYTES,
BASE_NONE,
NULL, 0, "Datat used for optional authentication of a peer BIS", HFILL}},
{&hf_idrp_update_number_of_unfeasible_routes,
{"Number of Unfeasible Routes",
"idrp.update.number-of-unfeasible-routes", FT_UINT16, BASE_DEC,
NULL, 0,
"Number of RDIs that are included in the subsequent withdrawn routes field",
HFILL}},
{&hf_idrp_update_withdrawn_route,
{"Unfeasible Route", "idrp.update.unfeasible-route", FT_UINT32,
BASE_DEC,
NULL, 0,
"Route-ID for the route that id being withdrawn from service",
HFILL}},
{&hf_idrp_update_path_attr_flag,
{"Path Attribute Flag", "idrp.update.path-attribute-flag", FT_UINT8,
BASE_HEX,
VALS(idrp_path_attr_flags), 0, NULL, HFILL}},
{&hf_idrp_update_path_attr_type,
{"Path Attribute Type", "idrp.update.path-attribute-type", FT_UINT8,
BASE_DEC,
VALS(path_attr_types), 0, NULL, HFILL}},
{&hf_idrp_update_path_attr_length,
{"Path Attribute Length", "idrp.update.path-attribute-length", FT_UINT16,
BASE_DEC,
NULL, 0, NULL, HFILL}},
{&hf_idrp_update_path_attr_route_separator_id,
{"Path Attribute Value Route Separator Id",
"idrp.update.path-attr.route-separator.id", FT_UINT32, BASE_DEC,
NULL, 0,",Route identifier for the advertised route",
HFILL}},
{&hf_idrp_update_path_attr_route_separator_localpref,
{"Path Attribute Value Route Separator Local Pref",
"idrp.update.path-attr.route-separator.local-pref", FT_UINT8, BASE_DEC,
NULL, 0,"Contains the local preference value for route",
HFILL}},
{&hf_idrp_update_path_attr_ext_info,
{"Path Attribute Value External Info",
"idrp.update.path-attr.ext-info", FT_BOOLEAN, 8,
NULL, 0,"Flag indicates if routes have been discovered by means of IDRP",
HFILL}},
{&hf_idrp_update_path_attr_rd_path_type,
{"Path Attribute Value RD Path Segment Type",
"idrp.update.path-attr.rd-path.segment-type", FT_UINT8, BASE_HEX,
VALS(path_rd_segment_types), 0, NULL,
HFILL}},
{&hf_idrp_update_path_attr_rd_path_segment_length,
{"Path Attribute Value RD Path Segment Length",
"idrp.update.path-attr.rd-path.segment-length", FT_UINT16, BASE_DEC,
NULL, 0, NULL,
HFILL}},
{&hf_idrp_update_path_attr_rd_path_rdi,
{"Path Attribute Value RD Path Segment RDI",
"idrp.update.path-attr.rd-path.segment-rdi", FT_BYTES, BASE_NONE,
NULL, 0,"RD Path Segment Routing Identifier or Confederation" ,
HFILL}},
{&hf_idrp_update_path_attr_next_hop_idrp_server,
{"Path Attribute Value Next Hop Idrp Server",
"idrp.update.path-attr.next-hop.idrp-server", FT_UINT8, BASE_DEC,
NULL, 0, "Permit a BIS to advertise a different or local BISs NET" ,
HFILL}},
{&hf_idrp_update_path_attr_next_hop_proto_type,
{"Path Attribute Value Next Hop Segment Protocol Type",
"idrp.update.path-attr.next-hop.segment-protp-type", FT_UINT8, BASE_DEC,
VALS(idrp_proto_type), 0, NULL ,
HFILL}},
{&hf_idrp_update_path_attr_next_hop_proto,
{"Path Attribute Value Next Hop Segment Protocol",
"idrp.update.path-attr.next-hop.segment-proto", FT_UINT8, BASE_DEC,
NULL, 0, NULL ,
HFILL}},
{&hf_idrp_update_path_attr_next_hop_rdi,
{"Path Attribute Value Next Hop RDI",
"idrp.update.path-attr.next-hop.rdi", FT_BYTES, BASE_NONE,
NULL, 0, "NET to advertise as next hop segment" ,
HFILL}},
{&hf_idrp_update_path_attr_next_hop_nb_snpa,
{"Path Attribute Value Next Hop Number of SNPA",
"idrp.update.path-attr.next-hop.number-snpa", FT_UINT8, BASE_DEC,
NULL, 0, "Number of SNPA's on next hop segment" ,
HFILL}},
{&hf_idrp_update_path_attr_next_hop_snpa,
{"Path Attribute Value Next Hop SNPA",
"idrp.update.path-attr.next-hop.snpa", FT_BYTES, BASE_NONE,
NULL, 0, "SNPA on next hop segment" ,
HFILL}},
{&hf_idrp_update_path_attr_dist_list_incl_nb_rdi,
{"Path Attribute Value Dist List Incl Number of RDIs",
"idrp.update.path-attr.dist-list-incl.number-rdi", FT_UINT8, BASE_DEC,
NULL, 0, "Number of RDIs which NLRI infomation may be distributed" ,
HFILL}},
{&hf_idrp_update_path_attr_dist_list_incl_rdi,
{"Path Attribute Value Dist List Incl RDI",
"idrp.update.path-attr.dist-list-incl.rdi", FT_BYTES, BASE_NONE,
NULL, 0, "RDI which NLRI infomation may be distributed" ,
HFILL}},
{&hf_idrp_update_path_attr_dist_list_excl_nb_rdi,
{"Path Attribute Value Dist List Excl Number of RDIs",
"idrp.update.path-attr.dist-list-excl.number-rdi", FT_UINT8, BASE_DEC,
NULL, 0, "Number of RDIs which NLRI infomation may not be distributed" ,
HFILL}},
{&hf_idrp_update_path_attr_dist_list_excl_rdi,
{"Path Attribute Value Dist List Excl RDI",
"idrp.update.path-attr.dist-list-excl.rdi", FT_BYTES, BASE_NONE,
NULL, 0, "RDI which NLRI infomation may be distributed" ,
HFILL}},
{&hf_idrp_update_path_attr_multi_exit_disc,
{"Path Attribute Value Multi Exit Disc",
"idrp.update.path-attr.dist-list-excl.rdi", FT_UINT8, BASE_DEC,
NULL, 0, "Number of exit points to an adjacent domain" ,
HFILL}},
{&hf_idrp_update_path_attr_transit_delay,
{"Path Attribute Value Transit Delay",
"idrp.update.path-attr.transit-delay", FT_UINT16, BASE_DEC,
NULL, 0, "Transit Delay" ,
HFILL}},
{&hf_idrp_update_path_attr_residual_error,
{"Path Attribute Value Residual Error",
"idrp.update.path-attr.residual-error", FT_UINT32, BASE_DEC,
NULL, 0, "Residual error probability to destination" ,
HFILL}},
{&hf_idrp_update_path_attr_expense,
{"Path Attribute Value Expense",
"idrp.update.path-attr.expense", FT_UINT16, BASE_DEC,
NULL, 0, "Expense to destination" ,
HFILL}},
{&hf_idrp_update_path_attr_locally_defined_qos_nsap,
{"Path Attribute Value Locally Defined Qos NSAP",
"idrp.update.path-attr.locally-defined-qos.nsap", FT_BYTES, BASE_NONE,
NULL, 0, "Locally Defined Qos NSAP" ,
HFILL}},
{&hf_idrp_update_path_attr_locally_defined_qos_value,
{"Path Attribute Value Locally Defined Qos",
"idrp.update.path-attr.locally-defined-qos.qos", FT_BYTES, BASE_NONE,
NULL, 0, "Locally Defined Qos Value" ,
HFILL}},
{&hf_idrp_update_path_attr_locally_defined_qos_metric,
{"Path Attribute Value Locally Defined Qos Metric",
"idrp.update.path-attr.locally-defined-qos.metric", FT_BYTES, BASE_NONE,
NULL, 0, "Locally Defined Metric" ,
HFILL}},
{&hf_idrp_update_path_attr_hierarchicaldecoding,
{"Path Attribute Value Hierarchical Decoding",
"idrp.update.path-attr.hierarchical-decoding", FT_UINT8, BASE_HEX,
NULL, 0, "Controls the transitivity of NPDUs through the confederation" ,
HFILL}},
{&hf_idrp_update_path_attr_rd_hop_count,
{"Path Attribute Value RD Hop Count",
"idrp.update.path-attr.rd-hop-count", FT_UINT8, BASE_DEC,
NULL, 0, "Maximum Hop Count for this Routing Information to travel" ,
HFILL}},
{&hf_idrp_update_path_attr_security_reg_id,
{"Path Attribute Value Security Registration ID",
"idrp.update.path-attr.security.reg-id", FT_BYTES, BASE_NONE,
NULL, 0, "Identifys the Security Authority" ,
HFILL}},
{&hf_idrp_update_path_attr_security_info,
{"Path Attribute Value Security Registration ID",
"idrp.update.path-attr.security.info", FT_BYTES, BASE_NONE,
NULL, 0, "Additional security related information" ,
HFILL}},
{&hf_idrp_update_path_attr_capacity,
{"Path Attribute Value Capacity",
"idrp.update.path-attr.capacity", FT_UINT8, BASE_DEC,
NULL, 0, "Capacity of the RD_PATH for handling traffic" ,
HFILL}},
{&hf_idrp_update_path_attr_priority,
{"Path Attribute Value Capacity",
"idrp.update.path-attr.capacity", FT_UINT8, BASE_DEC,
NULL, 0, "Capacity of the RD_PATH for handling traffic" ,
HFILL}},
{&hf_idrp_update_nlri_proto_type,
{"NLRI Protocol Type", "idrp.update.nlri.proto-type", FT_UINT8,
BASE_DEC,
VALS(idrp_proto_type), 0, NULL, HFILL}},
{&hf_idrp_update_nlri_proto_id,
{"NLRI Protocol Identity", "idrp.update.nlri.proto-id", FT_BYTES,
BASE_NONE,
NULL, 0,
"Identity of the protocol associated with the NLRI address information",
HFILL}},
{&hf_idrp_update_nlri_addr_length,
{"NLRI Address Length",
"idrp.update.nlri.addr-length.", FT_UINT16, BASE_DEC,
NULL, 0, NULL ,
HFILL}},
{&hf_idrp_update_nlri_addr_info_nb_bits,
{"NLRI Address Info Bits",
"idrp.update.nlri.addr-info-bits.", FT_UINT8, BASE_DEC,
NULL, 0, NULL ,
HFILL}},
{&hf_idrp_update_nlri_addr_info,
{"NLRI Address Info", "idrp.update.nlri.addr-info", FT_BYTES,
BASE_NONE,
NULL, 0, "Network Layer Reachability Information Protocol", HFILL}},
{&hf_idrp_error_code,
{"Error Code", "idrp.error.code", FT_UINT8, BASE_DEC,
VALS(idrp_error_codes), 0,
NULL, HFILL}},
{&hf_idrp_error_open_subcode,
{"Error Subcode (Open Message)", "idrp.error.subcode", FT_UINT8,
BASE_DEC, VALS(idrp_error_open_subcodes),
0, NULL, HFILL}},
{&hf_idrp_error_update_subcode,
{"Error Subcode (Update Message)", "idrp.error.subcode", FT_UINT8,
BASE_DEC, VALS(idrp_error_update_subcodes),
0, NULL, HFILL}},
{&hf_idrp_error_hold_timer_subcode,
{"Error Subcode (Hold Timer)", "idrp.error.subcode", FT_UINT8,
BASE_DEC, VALS(idrp_error_hold_timer_subcodes),
0, NULL, HFILL}},
{&hf_idrp_error_fsm_subcode,
{"Error Subcode (Fsm State)", "idrp.error.subcode", FT_UINT8,
BASE_DEC, VALS(idrp_error_fsm_subcodes),
0, NULL, HFILL}},
{&hf_idrp_error_rib_refresh_subcode,
{"Error Subcode (Rib-Refresh Message)", "idrp.error.subcode",
FT_UINT8, BASE_DEC, VALS(idrp_error_rib_refresh_subcodes),
0xff, NULL, HFILL}},
{&hf_idrp_error_data,
{"Error Data", "idrp.error.data", FT_BYTES, BASE_NONE, NULL, 0,
"Diagnosis data that depends upon the error code and error subcode",
HFILL}},
{&hf_idrp_rib_refresh_opcode,
{"Rib Refresh upcode", "idrp.rib-refresh.opcode", FT_UINT8, BASE_DEC,
VALS(idrp_error_rib_refresh_subcodes),
0xff, NULL, HFILL}},
{&hf_idrp_rib_refresh_rib_attr_locally_defined_qos_nsap,
{"Rib Attribute Value Locally Defined Qos NSAP",
"idrp.rib-refresh.rib-attr.locally-defined-qos.nsap",
FT_BYTES, BASE_NONE,
NULL, 0, "Locally Defined Qos NSAP" ,
HFILL}},
{&hf_idrp_rib_refresh_rib_attr_locally_defined_qos_value,
{"Rib Attribute Value Locally Defined Qos",
"idrp.rib-refresh.rib-attr.locally-defined-qos.qos",
FT_BYTES, BASE_NONE,
NULL, 0, "Locally Defined Qos Value" ,
HFILL}},
{&hf_idrp_rib_refresh_rib_attr_locally_defined_qos_metric,
{"Rib Attribute Value Locally Defined Qos Metric",
"idrp.rib-refresh.rib-attr.locally-defined-qos.metric",
FT_BYTES, BASE_NONE,
NULL, 0, "Locally Defined Metric" ,
HFILL}},
{&hf_idrp_rib_refresh_rib_attr_security_reg_id,
{"Rib Attribute Value Security Registration ID",
"idrp.rib-refresh.rib-attr.security.reg-id", FT_BYTES, BASE_NONE,
NULL, 0, "Identifys the Security Authority" ,
HFILL}},
{&hf_idrp_rib_refresh_rib_attr_security_info,
{"Rib Attribute Value Security Registration ID",
"idrp.rib-refresh.rib-attr.security.info", FT_BYTES, BASE_NONE,
NULL, 0, "Additional security related information" ,
HFILL}},
};
static gint *ett[] = {
&ett_idrp,
&ett_idrp_sub
};
static ei_register_info ei[] = {
{ &ei_idrp_no_path_attributes, { "idrp.no_path_attributes", PI_PROTOCOL, PI_NOTE, "No path attributes", EXPFILL }},
};
expert_module_t* expert_idrp;
proto_idrp = proto_register_protocol(IDRP_PROTO, "IDRP", "idrp");
proto_register_field_array(proto_idrp, hf_idrp, array_length(hf_idrp));
proto_register_subtree_array(ett, array_length(ett));
expert_idrp = expert_register_protocol(proto_idrp);
expert_register_field_array(expert_idrp, ei, array_length(ei));
new_register_dissector("idrp", dissect_idrp, proto_idrp);
}
