static void
dissect_rdmap_payload(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, struct rdmapinfo *info)
{
heur_dtbl_entry_t *hdtbl_entry;
if (!dissector_try_heuristic(rdmap_heur_subdissector_list,
tvb, pinfo, tree, &hdtbl_entry, info)) {
call_dissector(data_handle, tvb, pinfo, tree);
}
}
static void
ddp_rdma_packetlist(packet_info *pinfo, gboolean ddp_last_flag,
guint8 rdma_msg_opcode)
{
const gchar *ddp_fragment_state;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DDP/RDMA");
if (ddp_last_flag) {
ddp_fragment_state = "[last DDP segment]";
} else {
ddp_fragment_state = "[more DDP segments]";
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d %s %s", pinfo->srcport,
pinfo->destport, val_to_str(rdma_msg_opcode, rdmap_messages,
"Unknown %d"), ddp_fragment_state);
}
static void
dissect_iwarp_rdmap(tvbuff_t *tvb, proto_tree *rdma_tree, guint32 offset,
guint8 rdma_msg_opcode)
{
proto_tree *rdma_header_tree = NULL;
proto_tree *term_ctrl_field_tree = NULL;
proto_tree *header_ctrl_field_tree = NULL;
proto_item *rdma_header_subitem = NULL;
proto_item *term_ctrl_field_subitem = NULL;
proto_item *header_ctrl_field_subitem = NULL;
guint8 layer, etype, hdrct;
guint32 rdmardsz;
if (rdma_tree) {
if (rdma_msg_opcode == RDMA_READ_REQUEST) {
rdma_header_subitem = proto_tree_add_item(rdma_tree,
hf_iwarp_rdma_rr_header, tvb, offset, -1, ENC_NA);
rdma_header_tree = proto_item_add_subtree(rdma_header_subitem,
ett_iwarp_rdma);
proto_tree_add_item(rdma_header_tree, hf_iwarp_rdma_sinkstag, tvb,
offset, RDMA_SINKSTAG_LEN, ENC_BIG_ENDIAN);
offset += RDMA_SINKSTAG_LEN;
proto_tree_add_item(rdma_header_tree, hf_iwarp_rdma_sinkto, tvb,
offset, RDMA_SINKTO_LEN, ENC_BIG_ENDIAN);
offset += RDMA_SINKTO_LEN;
rdmardsz = (guint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(rdma_header_tree,
hf_iwarp_rdma_rdmardsz, tvb, offset,
RDMA_RDMARDSZ_LEN, rdmardsz, "%u bytes",
rdmardsz);
offset += RDMA_RDMARDSZ_LEN;
proto_tree_add_item(rdma_header_tree, hf_iwarp_rdma_srcstag, tvb,
offset, RDMA_SRCSTAG_LEN, ENC_BIG_ENDIAN);
offset += RDMA_SRCSTAG_LEN;
proto_tree_add_item(rdma_header_tree, hf_iwarp_rdma_srcto, tvb,
offset, RDMA_SRCTO_LEN, ENC_NA);
offset += RDMA_SRCTO_LEN;
}
if (rdma_msg_opcode == RDMA_TERMINATE) {
rdma_header_subitem = proto_tree_add_item(rdma_tree,
hf_iwarp_rdma_terminate_header, tvb, offset, -1, ENC_NA);
rdma_header_tree = proto_item_add_subtree(rdma_header_subitem,
ett_iwarp_rdma);
layer = tvb_get_guint8(tvb, offset) & IWARP_LAYER;
etype = tvb_get_guint8(tvb, offset) & IWARP_ETYPE;
term_ctrl_field_subitem = proto_tree_add_item(rdma_tree,
hf_iwarp_rdma_term_ctrl, tvb, offset, 3, ENC_NA);
term_ctrl_field_tree = proto_item_add_subtree(
term_ctrl_field_subitem, ett_iwarp_rdma);
proto_tree_add_item(term_ctrl_field_tree, hf_iwarp_rdma_term_layer,
tvb, offset, 1, ENC_BIG_ENDIAN);
switch (layer) {
case IWARP_LAYER_RDMA:
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_etype_rdma, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_errcode_rdma, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case IWARP_LAYER_DDP:
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_etype_ddp, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
switch (etype) {
case IWARP_ETYPE_DDP_TAGGED:
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_errcode_ddp_tagged, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case IWARP_ETYPE_DDP_UNTAGGED:
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_errcode_ddp_untagged, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
default:
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_errcode, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
break;
}
break;
case IWARP_LAYER_LLP:
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_etype_llp, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_errcode_llp, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
break;
default:
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_etype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(term_ctrl_field_tree,
hf_iwarp_rdma_term_errcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
header_ctrl_field_subitem = proto_tree_add_item(
term_ctrl_field_tree, hf_iwarp_rdma_term_hdrct, tvb,
offset, 1, ENC_NA);
header_ctrl_field_tree = proto_item_add_subtree(
header_ctrl_field_subitem, ett_iwarp_rdma);
hdrct = tvb_get_guint8(tvb, offset) & IWARP_HDRCT;
proto_tree_add_item(header_ctrl_field_tree,
hf_iwarp_rdma_term_hdrct_m, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(header_ctrl_field_tree,
hf_iwarp_rdma_term_hdrct_d, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(header_ctrl_field_tree,
hf_iwarp_rdma_term_hdrct_r, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rdma_header_tree, hf_iwarp_rdma_term_rsvd, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (hdrct & IWARP_HDRCT_D) {
proto_tree_add_item(rdma_header_tree,
hf_iwarp_rdma_term_ddp_seg_len, tvb,
offset, RDMA_DDP_SEGLEN_LEN, ENC_NA);
offset += RDMA_DDP_SEGLEN_LEN;
if (etype == IWARP_ETYPE_DDP_TAGGED) {
proto_tree_add_item(rdma_header_tree,
hf_iwarp_rdma_term_ddp_h, tvb,
offset, DDP_TAGGED_HEADER_LEN, ENC_NA);
offset += DDP_TAGGED_HEADER_LEN;
} else {
proto_tree_add_item(rdma_header_tree,
hf_iwarp_rdma_term_ddp_h, tvb,
offset, DDP_UNTAGGED_HEADER_LEN, ENC_NA);
offset += DDP_UNTAGGED_HEADER_LEN;
}
}
if (hdrct & IWARP_HDRCT_R) {
proto_tree_add_item(rdma_header_tree, hf_iwarp_rdma_term_rdma_h,
tvb, offset, RDMA_TERMINATED_RDMA_LEN, ENC_NA);
}
}
}
}
static void
dissect_iwarp_ddp_rdmap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ddp_rdma_tree = NULL;
proto_tree *ddp_tree = NULL;
proto_tree *ddp_ctrl_field_tree = NULL;
proto_tree *ddp_buffer_model_tree = NULL;
proto_tree *rdma_tree = NULL;
proto_tree *rdma_ctrl_field_tree = NULL;
proto_item *ddp_rdma_item = NULL;
proto_item *ddp_item = NULL;
proto_item *ddp_ctrl_field_item = NULL;
proto_item *ddp_buffer_model_item = NULL;
proto_item *rdma_item = NULL;
proto_item *rdma_ctrl_field_item = NULL;
tvbuff_t *next_tvb = NULL;
gboolean is_tagged_buffer_model;
guint8 ddp_ctrl_field, rdma_ctrl_field;
struct rdmapinfo info = { 0, };
guint32 header_end;
guint32 offset = 0;
ddp_ctrl_field = tvb_get_guint8(tvb, 0);
rdma_ctrl_field = tvb_get_guint8(tvb, 1);
info.opcode = rdma_ctrl_field & RDMA_OPCODE;
is_tagged_buffer_model = ddp_ctrl_field & DDP_TAGGED_FLAG;
ddp_rdma_packetlist(pinfo, ddp_ctrl_field & DDP_LAST_FLAG, info.opcode);
offset = 0;
if (is_tagged_buffer_model) {
header_end = DDP_TAGGED_HEADER_LEN;
} else {
header_end = DDP_UNTAGGED_HEADER_LEN;
}
if (info.opcode == RDMA_READ_REQUEST
|| info.opcode == RDMA_TERMINATE) {
header_end = -1;
}
ddp_rdma_item = proto_tree_add_item(tree, proto_iwarp_ddp_rdmap,
tvb, offset, header_end, ENC_NA);
ddp_rdma_tree = proto_item_add_subtree(ddp_rdma_item,
ett_iwarp_ddp_rdmap);
ddp_item = proto_tree_add_item(ddp_rdma_tree, hf_iwarp_ddp, tvb,
offset, header_end, ENC_NA);
ddp_tree = proto_item_add_subtree(ddp_item, ett_iwarp_ddp);
ddp_ctrl_field_item = proto_tree_add_item(ddp_tree,
hf_iwarp_ddp_control_field, tvb, offset,
DDP_CONTROL_FIELD_LEN, ENC_NA);
ddp_ctrl_field_tree = proto_item_add_subtree(ddp_ctrl_field_item,
ett_iwarp_ddp);
proto_tree_add_item(ddp_ctrl_field_tree, hf_iwarp_ddp_t_flag, tvb,
offset, DDP_CONTROL_FIELD_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(ddp_ctrl_field_tree, hf_iwarp_ddp_l_flag, tvb,
offset, DDP_CONTROL_FIELD_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(ddp_ctrl_field_tree, hf_iwarp_ddp_rsvd, tvb,
offset, DDP_CONTROL_FIELD_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(ddp_ctrl_field_tree, hf_iwarp_ddp_dv, tvb, offset,
DDP_CONTROL_FIELD_LEN, ENC_BIG_ENDIAN);
offset += DDP_CONTROL_FIELD_LEN;
if (!is_tagged_buffer_model) {
proto_tree_add_item(ddp_tree, hf_iwarp_ddp_rsvdulp, tvb,
offset, DDP_UNTAGGED_RSVDULP_LEN, ENC_NA);
}
if (is_tagged_buffer_model) {
header_end = RDMA_CONTROL_FIELD_LEN;
} else {
header_end = RDMA_CONTROL_FIELD_LEN + RDMA_RESERVED_FIELD_LEN;
}
rdma_item = proto_tree_add_item(ddp_rdma_tree, hf_iwarp_rdma, tvb,
offset, header_end, ENC_NA);
rdma_tree = proto_item_add_subtree(rdma_item, ett_iwarp_rdma);
rdma_ctrl_field_item = proto_tree_add_item(rdma_tree,
hf_iwarp_rdma_control_field, tvb, offset,
RDMA_CONTROL_FIELD_LEN, ENC_NA);
rdma_ctrl_field_tree = proto_item_add_subtree(rdma_ctrl_field_item,
ett_iwarp_rdma);
proto_tree_add_item(rdma_ctrl_field_tree, hf_iwarp_rdma_version, tvb,
offset, RDMA_CONTROL_FIELD_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(rdma_ctrl_field_tree, hf_iwarp_rdma_rsvd, tvb,
offset, RDMA_CONTROL_FIELD_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(rdma_ctrl_field_tree, hf_iwarp_rdma_opcode, tvb,
offset, RDMA_CONTROL_FIELD_LEN, ENC_BIG_ENDIAN);
offset += RDMA_CONTROL_FIELD_LEN;
if (info.opcode == RDMA_READ_REQUEST
|| info.opcode == RDMA_SEND
|| info.opcode == RDMA_SEND_SE
|| info.opcode == RDMA_TERMINATE) {
proto_tree_add_item(rdma_tree, hf_iwarp_rdma_reserved,
tvb, offset, RDMA_RESERVED_FIELD_LEN, ENC_NA);
}
if (info.opcode == RDMA_SEND_INVALIDATE
|| info.opcode == RDMA_SEND_SE_INVALIDATE) {
proto_tree_add_item(rdma_tree, hf_iwarp_rdma_inval_stag,
tvb, offset, RDMA_INVAL_STAG_LEN, ENC_BIG_ENDIAN);
}
if (!is_tagged_buffer_model) {
offset += RDMA_RESERVED_FIELD_LEN;
}
if (is_tagged_buffer_model) {
ddp_buffer_model_item = proto_tree_add_item(ddp_tree,
hf_iwarp_ddp_tagged_header, tvb, offset,
DDP_BUFFER_MODEL_LEN, ENC_NA);
ddp_buffer_model_tree = proto_item_add_subtree(ddp_buffer_model_item,
ett_iwarp_ddp);
proto_tree_add_item(ddp_buffer_model_tree, hf_iwarp_ddp_stag, tvb,
offset, DDP_STAG_LEN, ENC_NA);
offset += DDP_STAG_LEN;
proto_tree_add_item(ddp_buffer_model_tree, hf_iwarp_ddp_to, tvb,
offset, DDP_TO_LEN, ENC_NA);
offset += DDP_TO_LEN;
if( info.opcode == RDMA_READ_RESPONSE
|| info.opcode == RDMA_WRITE) {
next_tvb = tvb_new_subset_remaining(tvb, DDP_TAGGED_HEADER_LEN);
dissect_rdmap_payload(next_tvb, pinfo, tree, &info);
}
} else {
ddp_buffer_model_item = proto_tree_add_item(ddp_tree,
hf_iwarp_ddp_untagged_header, tvb, offset,
DDP_BUFFER_MODEL_LEN, ENC_NA);
ddp_buffer_model_tree = proto_item_add_subtree(ddp_buffer_model_item,
ett_iwarp_ddp);
proto_tree_add_item(ddp_buffer_model_tree, hf_iwarp_ddp_qn, tvb,
offset, DDP_QN_LEN, ENC_BIG_ENDIAN);
offset += DDP_QN_LEN;
proto_tree_add_item(ddp_buffer_model_tree, hf_iwarp_ddp_msn, tvb,
offset, DDP_MSN_LEN, ENC_BIG_ENDIAN);
offset += DDP_MSN_LEN;
proto_tree_add_item(ddp_buffer_model_tree, hf_iwarp_ddp_mo, tvb,
offset, DDP_MO_LEN, ENC_BIG_ENDIAN);
offset += DDP_MO_LEN;
if (info.opcode == RDMA_SEND
|| info.opcode == RDMA_SEND_INVALIDATE
|| info.opcode == RDMA_SEND_SE
|| info.opcode == RDMA_SEND_SE_INVALIDATE) {
next_tvb = tvb_new_subset_remaining(tvb, DDP_UNTAGGED_HEADER_LEN);
dissect_rdmap_payload(next_tvb, pinfo, tree, &info);
}
}
if (info.opcode == RDMA_READ_REQUEST
|| info.opcode == RDMA_TERMINATE) {
dissect_iwarp_rdmap(tvb, rdma_tree, offset, info.opcode);
}
}
void
proto_register_iwarp_ddp_rdmap(void)
{
static hf_register_info hf[] = {
{ &hf_iwarp_ddp, {
"DDP header", "iwarp_ddp",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_iwarp_ddp_control_field, {
"DDP control field", "iwarp_ddp.control_field",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_iwarp_ddp_tagged_header, {
"Tagged buffer model", "iwarp_ddp.tagged",
FT_NONE, BASE_NONE, NULL, 0x0,
"DDP Tagged Buffer Model Header", HFILL} },
{ &hf_iwarp_ddp_untagged_header, {
"Untagged buffer model", "iwarp_ddp.untagged",
FT_NONE, BASE_NONE, NULL, 0x0,
"DDP Untagged Buffer Model Header", HFILL} },
{ &hf_iwarp_ddp_t_flag, {
"Tagged flag", "iwarp_ddp.tagged_flag",
FT_BOOLEAN, 8, NULL, DDP_TAGGED_FLAG,
NULL, HFILL} },
{ &hf_iwarp_ddp_l_flag, {
"Last flag", "iwarp_ddp.last_flag",
FT_BOOLEAN, 8, NULL, DDP_LAST_FLAG,
NULL, HFILL} },
{ &hf_iwarp_ddp_rsvd, {
"Reserved", "iwarp_ddp.rsvd",
FT_UINT8, BASE_HEX, NULL, DDP_RSVD,
NULL, HFILL} },
{ &hf_iwarp_ddp_dv, {
"DDP protocol version", "iwarp_ddp.dv",
FT_UINT8, BASE_DEC, NULL, DDP_DV,
NULL, HFILL} },
{ &hf_iwarp_ddp_rsvdulp, {
"Reserved for use by the ULP", "iwarp_ddp.rsvdulp",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_ddp_stag, {
"(Data Sink) Steering Tag", "iwarp_ddp.stag",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_ddp_to, {
"(Data Sink) Tagged offset", "iwarp_ddp.tagged_offset",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_ddp_qn, {
"Queue number", "iwarp_ddp.qn",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_ddp_msn, {
"Message sequence number", "iwarp_ddp.msn",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_ddp_mo, {
"Message offset", "iwarp_ddp.mo",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_iwarp_rdma, {
"RDMAP header", "iwarp_rdma",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_rdma_control_field, {
"RDMAP control field", "iwarp_rdma.control_field",
FT_NONE, BASE_NONE, NULL, 0x0,
"RDMA Control Field", HFILL} },
{ &hf_iwarp_rdma_version, {
"Version", "iwarp_rdma.version",
FT_UINT8, BASE_DEC, NULL, RDMA_RV,
"RDMA Version Field", HFILL} },
{ &hf_iwarp_rdma_rsvd, {
"Reserved", "iwarp_rdma.rsv",
FT_UINT8, BASE_HEX, NULL, RDMA_RSV,
"RDMA Control Field Reserved", HFILL} },
{ &hf_iwarp_rdma_opcode, {
"OpCode", "iwarp_rdma.opcode",
FT_UINT8, BASE_HEX, VALS(rdmap_messages), RDMA_OPCODE,
"RDMA OpCode Field", HFILL} },
{ &hf_iwarp_rdma_reserved, {
"Reserved", "iwarp_rdma.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_rdma_inval_stag, {
"Invalidate STag", "iwarp_rdma.inval_stag",
FT_UINT32, BASE_DEC, NULL, 0x0,
"RDMA Invalidate STag", HFILL} },
{ &hf_iwarp_rdma_rr_header, {
"Read request", "iwarp_rdma.rr",
FT_NONE, BASE_NONE, NULL, 0x0,
"RDMA Read Request Header", HFILL} },
{ &hf_iwarp_rdma_terminate_header, {
"Terminate", "iwarp_rdma.terminate",
FT_NONE, BASE_NONE, NULL, 0x0,
"RDMA Terminate Header", HFILL} },
{ &hf_iwarp_rdma_sinkstag, {
"Data Sink STag", "iwarp_rdma.sinkstag",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_rdma_sinkto, {
"Data Sink Tagged Offset", "iwarp_rdma.sinkto",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_rdma_rdmardsz, {
"RDMA Read Message Size", "iwarp_rdma.rdmardsz",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_rdma_srcstag, {
"Data Source STag", "iwarp_rdma.srcstag",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_rdma_srcto, {
"Data Source Tagged Offset", "iwarp_rdma.srcto",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_rdma_term_ctrl, {
"Terminate Control", "iwarp_rdma.term_ctrl",
FT_NONE, BASE_NONE, NULL, 0x0,
"RDMA Terminate Control Field", HFILL} },
{ &hf_iwarp_rdma_term_layer, {
"Layer", "iwarp_rdma.term_layer",
FT_UINT8, BASE_HEX, VALS(layer_names), IWARP_LAYER,
"Terminate Control Field: Layer", HFILL} },
{ &hf_iwarp_rdma_term_etype_rdma, {
"Error Types for RDMA layer", "iwarp_rdma.term_etype_rdma",
FT_UINT8, BASE_HEX, VALS(rdma_etype_names), IWARP_ETYPE,
"Terminate Control Field: Error Type", HFILL} },
{ &hf_iwarp_rdma_term_etype_ddp, {
"Error Types for DDP layer", "iwarp_rdma.term_etype_ddp",
FT_UINT8, BASE_HEX, VALS(ddp_etype_names), IWARP_ETYPE,
"Terminate Control Field: Error Type", HFILL} },
{ &hf_iwarp_rdma_term_etype_llp, {
"Error Types for LLP layer", "iwarp_rdma.term_etype_llp",
FT_UINT8, BASE_HEX, NULL, IWARP_ETYPE,
"Terminate Control Field: Error Type", HFILL} },
{ &hf_iwarp_rdma_term_etype, {
"Error Types", "iwarp_rdma.term_etype",
FT_UINT8, BASE_HEX, NULL, IWARP_ETYPE,
"Terminate Control Field: Error Type", HFILL} },
{ &hf_iwarp_rdma_term_errcode_rdma, {
"Error Code for RDMA layer", "iwarp_rdma.term_errcode_rdma",
FT_UINT8, BASE_HEX, VALS(rdma_errcode_names), 0x0,
"Terminate Control Field: Error Code", HFILL} },
{ &hf_iwarp_rdma_term_errcode_ddp_tagged, {
"Error Code for DDP Tagged Buffer",
"iwarp_rdma.term_errcode_ddp_tagged",
FT_UINT8, BASE_HEX, VALS(ddp_errcode_tagged_names), 0x0,
"Terminate Control Field: Error Code", HFILL} },
{ &hf_iwarp_rdma_term_errcode_ddp_untagged, {
"Error Code for DDP Untagged Buffer",
"iwarp_rdma.term_errcode_ddp_untagged",
FT_UINT8, BASE_HEX, VALS(ddp_errcode_untagged_names), 0x0,
"Terminate Control Field: Error Code", HFILL} },
{ &hf_iwarp_rdma_term_errcode, {
"Error Code", "iwarp_rdma.term_errcode",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Terminate Control Field: Error Code", HFILL} },
{ &hf_iwarp_rdma_term_errcode_llp, {
"Error Code for LLP layer", "iwarp_rdma.term_errcode_llp",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Terminate Control Field: Lower Layer Protocol Error Code",
HFILL} },
{ &hf_iwarp_rdma_term_hdrct, {
"Header control bits", "iwarp_rdma.term_hdrct",
FT_NONE, BASE_NONE, NULL, 0x0,
"Terminate Control Field: Header control bits", HFILL} },
{ &hf_iwarp_rdma_term_hdrct_m, {
"M bit", "iwarp_rdma.term_hdrct_m",
FT_UINT8, BASE_HEX, NULL, IWARP_HDRCT_M,
"Header control bit m: DDP Segment Length valid", HFILL} },
{ &hf_iwarp_rdma_term_hdrct_d, {
"D bit", "iwarp_rdma.hdrct_d",
FT_UINT8, BASE_HEX, NULL, IWARP_HDRCT_D,
"Header control bit d: DDP Header Included", HFILL} },
{ &hf_iwarp_rdma_term_hdrct_r, {
"R bit", "iwarp_rdma.hdrct_r",
FT_UINT8, BASE_HEX, NULL, IWARP_HDRCT_R,
"Header control bit r: RDMAP Header Included", HFILL} },
{ &hf_iwarp_rdma_term_rsvd, {
"Reserved", "iwarp_rdma.term_rsvd",
FT_UINT16, BASE_HEX, NULL, IWARP_TERM_RES,
NULL, HFILL} },
{ &hf_iwarp_rdma_term_ddp_seg_len, {
"DDP Segment Length", "iwarp_rdma.term_ddp_seg_len",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_rdma_term_ddp_h, {
"Terminated DDP Header", "iwarp_rdma.term_ddp_h",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL} },
{ &hf_iwarp_rdma_term_rdma_h, {
"Terminated RDMA Header", "iwarp_rdma.term_rdma_h",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL} }
};
static gint *ett[] = {
&ett_iwarp_ddp_rdmap,
&ett_iwarp_ddp,
&ett_iwarp_ddp_control_field,
&ett_iwarp_ddp_tagged_header,
&ett_iwarp_ddp_untagged_header,
&ett_iwarp_rdma,
&ett_iwarp_rdma_control_field,
&ett_iwarp_rdma_rr_header,
&ett_iwarp_rdma_terminate_header,
&ett_iwarp_rdma_term_ctrl,
&ett_iwarp_rdma_term_hdrct
};
proto_iwarp_ddp_rdmap = proto_register_protocol(
"iWARP Direct Data Placement and Remote Direct Memory Access Protocol",
"IWARP_DDP_RDMAP",
"iwarp_ddp_rdmap");
proto_register_field_array(proto_iwarp_ddp_rdmap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_heur_dissector_list("iwarp_ddp_rdmap",
&rdmap_heur_subdissector_list);
register_dissector("iwarp_ddp_rdmap", dissect_iwarp_ddp_rdmap,
proto_iwarp_ddp_rdmap);
}
void
proto_reg_handoff_iwarp_ddp_rdmap(void)
{
data_handle = find_dissector("data");
}
