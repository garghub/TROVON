static gint
tn3270_add_hf_items(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
const hf_items *fields)
{
gint start = offset;
gint i;
for (i = 0; fields[i].hf_idx_p; i++) {
if (fields[i].bitmask == 0) {
proto_tree_add_item(tn3270_tree,
*fields[i].hf_idx_p,
tvb, offset,
fields[i].length,
fields[i].encoding);
}
else {
proto_tree_add_bitmask(tn3270_tree, tvb, offset, *fields[i].hf_idx_p,
*fields[i].bitmask_ett_idx_p, fields[i].bitmask, ENC_BIG_ENDIAN);
}
offset += fields[i].length;
}
return (offset - start);
}
static gint
dissect_unknown_data(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset, gint start,
gint data_length)
{
gint len_left;
len_left = (data_length) - (offset - start);
if (len_left > 0) {
proto_tree_add_item(tn3270_tree, hf_tn3270_unknown_data,
tvb, offset, len_left,
ENC_NA);
return len_left;
}
return 0;
}
static gint
add_data_until_next_order_code(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint datalen = 0;
gint length_remaining = tvb_reported_length_remaining(tvb, offset);
while (datalen < length_remaining) {
guint order_code;
order_code = tvb_get_guint8(tvb, offset + datalen);
if ((order_code > 0) && (order_code <= OC_MAX))
break;
datalen += 1;
}
if (datalen > 0) {
proto_tree_add_item(tn3270_tree, hf_tn3270_field_data, tvb, offset,
datalen, ENC_EBCDIC|ENC_NA);
}
return datalen;
}
static gint
dissect_query_reply_resbytes(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_res_twobytes, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_wcc(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
static const gint *wcc_fields[] = {
&hf_tn3270_wcc_nop,
&hf_tn3270_wcc_reset,
&hf_tn3270_wcc_printer1,
&hf_tn3270_wcc_printer2,
&hf_tn3270_wcc_start_printer,
&hf_tn3270_wcc_sound_alarm,
&hf_tn3270_wcc_keyboard_restore,
&hf_tn3270_wcc_reset_mdt,
NULL
};
proto_tree_add_bitmask_text(tn3270_tree, tvb, offset, 1, "Write Control Character: ", "None",
ett_tn3270_wcc, wcc_fields, ENC_BIG_ENDIAN, 0);
return 1;
}
static gint
dissect_3270_field_validation(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
static const gint *byte[] = {
&hf_tn3270_field_validation_mandatory_fill,
&hf_tn3270_field_validation_mandatory_entry,
&hf_tn3270_field_validation_trigger,
NULL
};
proto_tree_add_bitmask_text(tn3270_tree, tvb, 1, 1, "Field Validation: ",
"None", ett_tn3270_field_validation, byte, ENC_BIG_ENDIAN, 0);
offset += 1;
return (offset - start);
}
static gint
dissect_3270_field_attribute(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
static const gint *byte[] = {
&hf_tn3270_fa_graphic_convert,
&hf_tn3270_fa_protected,
&hf_tn3270_fa_numeric,
&hf_tn3270_fa_display,
&hf_tn3270_fa_reserved,
&hf_tn3270_fa_modified,
NULL
};
proto_tree_add_bitmask(tn3270_tree, tvb, offset, hf_tn3270_field_attribute,
ett_tn3270_field_attribute, byte, ENC_BIG_ENDIAN);
offset += 1;
return (offset - start);
}
static gint
dissect_ccc(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
static const gint *byte[] = {
&hf_tn3270_ccc_coding,
&hf_tn3270_ccc_printout,
&hf_tn3270_ccc_start_print,
&hf_tn3270_ccc_sound_alarm,
&hf_tn3270_ccc_copytype,
NULL
};
proto_tree_add_bitmask(tn3270_tree, tvb, offset, hf_tn3270_ccc,
ett_tn3270_ccc, byte, ENC_BIG_ENDIAN);
offset += 1;
return (offset - start);
}
static gint
dissect_create_partition(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset, gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_uom, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_height, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_width, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_rv, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_cv, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_hv, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_wv, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_rw, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_cw, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_rs, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_res, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_pw, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_ph, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_load_format_storage(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset, gint sf_body_length)
{
gint start = offset;
gint operand;
static const hf_items fields[] = {
{ &hf_tn3270_load_format_storage_flags1, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_load_format_storage_flags2, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_load_format_storage_operand, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_load_format_storage_localname, NULL, 8, NULL, ENC_EBCDIC|ENC_NA },
{ &hf_tn3270_format_group, NULL, 6, NULL, ENC_EBCDIC|ENC_NA },
{ &hf_tn3270_format_name, NULL, 16, NULL, ENC_EBCDIC|ENC_NA },
{ NULL, NULL, 0, NULL, 0 }
};
operand = tvb_get_guint8(tvb, offset+2);
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
if (operand == LOAD_FORMAT_STORAGE_OPERAND_ADD) {
gint fmtln = sf_body_length - (offset - start);
proto_tree_add_item(tn3270_tree, hf_tn3270_load_format_storage_format_data,
tvb, offset, fmtln, ENC_EBCDIC|ENC_NA);
offset += fmtln;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_load_programmed_symbols(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset, gint sf_body_length)
{
gint start = offset, i;
gint8 flags;
gint8 extended_ps_length;
static const hf_items ps_fields[] = {
{ &hf_tn3270_ps_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ps_lcid, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ps_char, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ps_rws, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items extended_ps_fields[] = {
{ &hf_tn3270_extended_ps_lw, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_extended_ps_lh, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_extended_ps_subsn, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_extended_ps_color, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_extended_ps_stsubs, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_extended_ps_echar, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_extended_ps_nw, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_extended_ps_nh, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_extended_ps_res, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
flags = tvb_get_guint8(tvb, offset);
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
ps_fields);
if (!(flags & 0x80)) {
return (offset - start);
}
extended_ps_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn3270_tree, hf_tn3270_extended_ps_length,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tn3270_tree, hf_tn3270_extended_ps_flags,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i = 0; i < extended_ps_length; ++i) {
if (extended_ps_fields[i].hf_idx_p == NULL) {
break;
}
proto_tree_add_item(tn3270_tree, *extended_ps_fields[i].hf_idx_p,
tvb, offset, extended_ps_fields[i].length,
extended_ps_fields[i].encoding);
offset += extended_ps_fields[i].length;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_modify_partition(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset, gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbytes, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_rv, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_cv, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_hv, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_wv, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_rw, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_cw, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_rs, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_res, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_pw, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_partition_ph, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_outbound_text_header(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint16 hdr_length;
static const hf_items outbound_text_header_fields1[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_outbound_text_header_operation_type, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items outbound_text_header_fields2[] = {
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_lvl, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_cro, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_cc, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
outbound_text_header_fields1);
offset += dissect_wcc(tn3270_tree, tvb, offset);
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
outbound_text_header_fields2);
hdr_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tn3270_tree, hf_tn3270_outbound_text_header_lhdr,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tn3270_tree, hf_tn3270_outbound_text_header_hdr,
tvb, offset, hdr_length, ENC_BIG_ENDIAN);
offset += hdr_length;
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_outbound_3270ds(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
tn3270_conv_info_t *tn3270_info, gint sf_body_length )
{
gint start = offset;
gint cmd;
proto_tree_add_item(tn3270_tree,
hf_tn3270_partition_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
cmd = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn3270_tree,
hf_tn3270_partition_command,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
switch (cmd) {
case CC_SNA_BSC:
offset += dissect_ccc(tn3270_tree, tvb, offset);
proto_tree_add_item(tn3270_tree,
hf_tn3270_bsc,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
break;
case CC_LCL_W:
case CC_LCL_EW:
case CC_LCL_EWA:
case CC_LCL_EAU:
case CC_RMT_W:
case CC_RMT_EW:
case CC_RMT_EWA:
case CC_RMT_EAU:
if ((offset - start) < sf_body_length)
offset += dissect_wcc(tn3270_tree, tvb, offset);
if ((offset - start) < sf_body_length)
offset += dissect_orders_and_data(tn3270_tree, tvb, offset, tn3270_info);
break;
default:
break;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_present_absolute_format(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
proto_tree_add_item(tn3270_tree,
hf_tn3270_partition_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tn3270_tree,
hf_tn3270_fpc,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
offset += dissect_wcc(tn3270_tree, tvb, offset);
proto_tree_add_item(tn3270_tree,
hf_tn3270_format_name,
tvb, offset,
sf_body_length - (offset - start),
ENC_EBCDIC|ENC_NA);
offset += (sf_body_length - (offset - start));
return (offset - start);
}
static gint
dissect_present_relative_format(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
proto_tree_add_item(tn3270_tree,
hf_tn3270_partition_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tn3270_tree,
hf_tn3270_fov,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tn3270_tree,
hf_tn3270_fpc,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
offset += dissect_wcc(tn3270_tree, tvb, offset);
proto_tree_add_item(tn3270_tree,
hf_tn3270_format_name,
tvb, offset,
sf_body_length - (offset - start),
ENC_EBCDIC|ENC_NA);
offset += (sf_body_length - (offset - start));
return (offset - start);
}
static gint
dissect_read_partition(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint type;
proto_item *pi;
proto_tree *query_list_tree;
gint qcode_list_len, i;
proto_tree_add_item(tn3270_tree,
hf_tn3270_partition_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
type = tvb_get_guint8(tvb, offset);
if (type == 0xFF) {
offset += 1;
type = tvb_get_guint8(tvb, offset);
}
proto_tree_add_item(tn3270_tree,
hf_tn3270_read_partition_operation_type,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
if (type == READ_PARTITION_OPTYPE_QUERY_LIST) {
proto_tree_add_item(tn3270_tree,
hf_tn3270_read_partition_reqtyp,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
if (sf_body_length > (offset - start)) {
qcode_list_len = sf_body_length - (offset - start);
pi = proto_tree_add_text(tn3270_tree, tvb, offset, qcode_list_len,
"Query List");
query_list_tree = proto_item_add_subtree(pi, ett_tn3270_query_list);
for (i = 0; i < qcode_list_len; i++) {
proto_tree_add_item(query_list_tree,
hf_tn3270_sf_query_reply,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
}
return (offset - start);
}
static gint
dissect_restart(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
proto_tree_add_item(tn3270_tree,
hf_tn3270_resbyte,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tn3270_tree,
hf_tn3270_start_page,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tn3270_tree,
hf_tn3270_start_line,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tn3270_tree,
hf_tn3270_scs_data,
tvb, offset,
sf_body_length - (offset - start),
ENC_NA);
offset += (sf_body_length - (offset - start));
return (offset - start);
}
static gint
dissect_set_msr_control(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const gint *byte[] = {
&hf_tn3270_msr_user,
&hf_tn3270_msr_locked,
&hf_tn3270_msr_auto,
&hf_tn3270_msr_ind1,
&hf_tn3270_msr_ind2,
NULL
};
static const hf_items outbound_text_header_fields[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_msr_type, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_msr_state_mask, &ett_tn3270_msr_state_mask, 1, byte, 0 },
{ &hf_tn3270_msr_state_value, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_msr_ind_mask, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_msr_ind_value, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
outbound_text_header_fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_set_partition_characteristics_sd_parms(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
guint16 sdp;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_spc_sdp_ot, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_spc_sdp_ob, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_spc_sdp_ol, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_spc_sdp_or, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp2[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_spc_sdp_eucflags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp3[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_spc_sdp_eucflags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_spc_sdp_eucflags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
sdp = tvb_get_ntohs(tvb, offset);
switch (sdp) {
case 0x0601:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
break;
case 0x0304:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp2);
break;
case 0x0405:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp3);
break;
default:
return 0;
}
return (offset - start);
}
static gint
dissect_set_partition_characteristics(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint i;
static const hf_items fields[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbytes, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i = 0; i < 3; i++) {
offset += dissect_set_partition_characteristics_sd_parms(tn3270_tree, tvb, offset);
if (tvb_reported_length_remaining(tvb, offset) <= 0)
break;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_set_printer_characteristics_sd_parms(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
guint16 sdp;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_spc_sdp_srepc, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
sdp = tvb_get_ntohs(tvb, offset);
switch (sdp) {
case 0x0301:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
break;
default:
return 0;
}
return (offset - start);
}
static gint
dissect_set_printer_characteristics(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint i;
static const hf_items fields[] = {
{ &hf_tn3270_printer_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i = 0; i < 3; i++) {
offset += dissect_set_printer_characteristics_sd_parms(tn3270_tree, tvb, offset);
if (tvb_reported_length_remaining(tvb, offset) <= 0)
break;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_set_reply_mode(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint type;
gint i;
static const hf_items fields[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_mode, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
type = tvb_get_guint8(tvb, offset+1);
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
if (type == 0x02) {
for (i = 0; i < (sf_body_length-(offset-start)); i++) {
proto_tree_add_item(tn3270_tree,
hf_tn3270_reply_mode_attr_list,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
return (offset - start);
}
static gint
dissect_type_1_text(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbytes, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
proto_tree_add_item(tn3270_tree,
hf_tn3270_field_data,
tvb, offset,
sf_body_length - (offset - start),
ENC_EBCDIC|ENC_NA);
offset += (sf_body_length - (offset - start));
return (offset - start);
}
static guint
dissect_data_chain(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const gint *byte[] = {
&hf_tn3270_data_chain_group,
&hf_tn3270_data_chain_inbound_control,
NULL
};
static const hf_items data_chain_fields[] = {
{ &hf_tn3270_data_chain_fields, &ett_tn3270_data_chain_fields, 1, byte, 0 },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
data_chain_fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_object_control(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_object_control_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_object_type, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
proto_tree_add_item(tn3270_tree,
hf_tn3270_type_1_text_outbound_data,
tvb, offset,
sf_body_length - (offset - start),
ENC_NA);
offset += (sf_body_length - (offset - start));
return (offset - start);
}
static gint
dissect_save_or_restore_format(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
hf_items fields[] = {
{ &hf_tn3270_save_or_restore_format_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_srf_fpcb, NULL, sf_body_length-1, NULL, ENC_NA },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_exception_or_status_sd_parms(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
guint16 sdp;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_excode, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp2[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_statcode, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp3[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_format_group, NULL, 16, NULL, ENC_EBCDIC|ENC_NA },
{ &hf_tn3270_format_name, NULL, 16, NULL, ENC_EBCDIC|ENC_NA },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp4[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_ngl, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_nml, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_nlml, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_stor, NULL, 4, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp5[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_format_group, NULL, 16, NULL, ENC_EBCDIC|ENC_NA },
{ &hf_tn3270_sdp_nml, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
sdp = tvb_get_ntohs(tvb, offset);
switch (sdp) {
case 0x0601:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
break;
case 0x0402:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp2);
break;
case 0x2203:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp3);
break;
case 0x0C04:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp4);
break;
case 0x1405:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp5);
break;
default:
return 0;
}
return (offset - start);
}
static gint
dissect_exception_or_status(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, i;
static const hf_items fields[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_exception_or_status_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i = 0; i < 5; i++) {
offset += dissect_exception_or_status_sd_parms(tn3270_tree, tvb, offset);
if (tvb_reported_length_remaining(tvb, offset) <= 0)
break;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_inbound_text_header(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items outbound_text_header_fields[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_aid, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_lvl, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_cro, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_cc, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_rw, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_cw, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_hw, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ww, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
outbound_text_header_fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_inbound_3270ds(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
tn3270_conv_info_t *tn3270_info, gint sf_body_length)
{
gint start = offset;
static const hf_items fields1[] = {
{ &hf_tn3270_partition_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_aid, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
hf_items fields2[] = {
{ &hf_tn3270_field_data, NULL, sf_body_length - 4, NULL, ENC_EBCDIC|ENC_NA },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset, fields1);
offset += dissect_buffer_address(tn3270_tree, tvb, offset, hf_tn3270_cursor_address, tn3270_info);
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset, fields2);
return (offset - start);
}
static gint
dissect_recovery_data(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_recovery_data_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sld, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_charset, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_vertical, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_v_offset, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_v_sequence, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_v_length, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_spd, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_horizon, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_h_offset, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_h_sequence, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_h_length, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_color, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_hilite, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_pages, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_lines, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_checkpoint, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_c_offset, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_c_sequence, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_c_seqoff, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_c_scsoff, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_prime, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_alphanumeric_sd_parms(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
guint16 sdp;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ap_cm, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ap_ro, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ap_co, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ap_fo, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
sdp = tvb_get_ntohs(tvb, offset);
switch (sdp) {
case 0x0702:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
break;
default:
return 0;
}
return (offset - start);
}
static gint
dissect_query_reply_alphanumeric(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const gint *byte[] = {
&hf_tn3270_ap_vertical_scrolling,
&hf_tn3270_ap_horizontal_scrolling,
&hf_tn3270_ap_apres1,
&hf_tn3270_ap_apa,
&hf_tn3270_ap_pp,
&hf_tn3270_ap_lc,
&hf_tn3270_ap_mp,
&hf_tn3270_ap_apres2,
NULL
};
static const hf_items fields[] = {
{ &hf_tn3270_ap_na, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ap_m, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_query_reply_alphanumeric_flags, &ett_tn3270_query_reply_alphanumeric_flags, 1, byte, 0 },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_query_reply_alphanumeric_sd_parms(tn3270_tree, tvb, offset);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_character_sets(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint flagbyte1, flagbyte2;
static const gint *byte1[] = {
&hf_tn3270_cs_ge,
&hf_tn3270_cs_mi,
&hf_tn3270_cs_lps,
&hf_tn3270_cs_lpse,
&hf_tn3270_cs_ms,
&hf_tn3270_cs_ch2,
&hf_tn3270_cs_gf,
&hf_tn3270_cs_res,
NULL
};
static const gint *byte2[] = {
&hf_tn3270_cs_res2,
&hf_tn3270_cs_pscs,
&hf_tn3270_cs_res3,
&hf_tn3270_cs_cf,
NULL
};
static const gint *byte3[] = {
&hf_tn3270_cs_form_type1,
&hf_tn3270_cs_form_type2,
&hf_tn3270_cs_form_type3,
&hf_tn3270_cs_form_type4,
&hf_tn3270_cs_form_type5,
&hf_tn3270_cs_form_type6,
&hf_tn3270_cs_form_type8,
NULL
};
static const gint *byte4[] = {
&hf_tn3270_cs_ds_load,
&hf_tn3270_cs_ds_triple,
&hf_tn3270_cs_ds_char,
&hf_tn3270_cs_ds_cb,
NULL
};
static const hf_items fields[] = {
{ &hf_tn3270_character_sets_flags1, &ett_tn3270_character_sets_flags1, 1, byte1, 0 },
{ &hf_tn3270_character_sets_flags2, &ett_tn3270_character_sets_flags2, 1, byte2, 0 },
{ &hf_tn3270_sdw, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdh, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_form, &ett_tn3270_character_sets_form, 1, byte3, 0 },
{ &hf_tn3270_formres, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_formres, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_formres, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_cs_dl, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items descriptors[] = {
{ &hf_tn3270_cs_descriptor_set, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_cs_descriptor_flags, &ett_tn3270_cs_descriptor_flags, 1, byte4, 0 },
{ &hf_tn3270_lcid, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sw_sh[] = {
{ &hf_tn3270_sw, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sh, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items subsn[] = {
{ &hf_tn3270_ssubsn, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_esubsn, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items gf[] = {
{ &hf_tn3270_ccsgid, NULL, 4, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items cf[] = {
{ &hf_tn3270_ccsid, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
flagbyte1 = tvb_get_guint8(tvb, offset);
flagbyte2 = tvb_get_guint8(tvb, offset+1);
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
while ((offset - start) < sf_body_length) {
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
descriptors);
if (flagbyte1 & QR_CS_MS) {
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sw_sh);
}
if (flagbyte1 & QR_CS_CH2) {
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
subsn);
}
if (flagbyte1 & QR_CS_GF) {
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
gf);
}
if (flagbyte2 & QR_CS_CF) {
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
cf);
}
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_color_sd_parms(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
guint16 sdp;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_db_cavdef, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_db_cidef, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
sdp = tvb_get_ntohs(tvb, offset);
switch (sdp) {
case 0x0402:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
break;
default:
return 0;
}
return (offset - start);
}
static gint
dissect_query_reply_color(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint i;
gint np;
static const gint *byte[] = {
&hf_tn3270_c_prtblk,
NULL
};
static const hf_items fields[] = {
{ &hf_tn3270_color_flags, &ett_tn3270_color_flags, 1, byte, 0 },
{ &hf_tn3270_c_np, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
np = tvb_get_guint8(tvb, offset +1);
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i=0; i < np; i++) {
if (tvb_get_guint8(tvb, offset) == 0xFF) {
offset += 1;
}
proto_tree_add_item(tn3270_tree,
hf_tn3270_c_cav,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
if (tvb_get_guint8(tvb, offset) == 0xFF) {
offset += 1;
}
proto_tree_add_item(tn3270_tree,
hf_tn3270_c_ci,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
}
offset += dissect_query_reply_color_sd_parms(tn3270_tree, tvb, offset);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_daid_sd_parm(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_daid, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
return (offset - start);
}
static gint
dissect_pclk_sd_parm(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_oem_sdp_pclk_vers, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
return (offset - start);
}
static gint
dissect_query_reply_oem_auxiliary_device_sd_parms(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
gint sdp_len;
gint sdp;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_daid, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp2[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_oem_sdp_ll_limin, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_oem_sdp_ll_limout, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp3[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_oem_sdp_pclk_vers, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
sdp_len = tvb_get_guint8(tvb, offset);
if ((sdp_len != 0x04) && (sdp_len != 0x06)) {
return 0;
}
sdp = tvb_get_guint8(tvb, offset+1);
switch (sdp) {
case 0x01:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
break;
case 0x02:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp2);
break;
case 0x03:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp3);
break;
default:
return 0;
}
return (offset - start);
}
static gint
dissect_query_reply_cooperative(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_res_twobytes, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_limin, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_limout, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_featl, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_feats, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
#if 0
proto_tree_add_item(tn3270_tree,
hf_tn3270_field_data,
tvb, offset,
sf_body_length - (offset-start),
ENC_EBCDIC|ENC_NA);
offset += (sf_body_length - (offset - start));
offset += dissect_query_reply_oem_auxiliary_device_sd_parms(tn3270_tree, tvb, offset);
#endif
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_data_chaining(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_dc_dir, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_data_streams(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint i;
proto_tree_add_item(tn3270_tree, hf_tn3270_ds_default_sfid, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
for (i=0; i < (sf_body_length-(offset-start)); i++) {
proto_tree_add_item(tn3270_tree,
hf_tn3270_ds_sfid,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_dbcs_asia_sd_parms(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
gint sdp_len;
gint sdp;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_asia_sdp_sosi_soset, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp2[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_asia_sdp_ic_func, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
sdp_len = tvb_get_guint8(tvb, offset);
if (sdp_len != 0x03) {
return 0;
}
sdp = tvb_get_guint8(tvb, offset+1);
switch (sdp) {
case 0x01:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
break;
case 0x02:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp2);
break;
default:
return 0;
}
return (offset - start);
}
static gint
dissect_query_reply_dbcs_asia(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint i;
static const hf_items fields[] = {
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i = 0; i < 3; i++) {
offset += dissect_query_reply_dbcs_asia_sd_parms(tn3270_tree, tvb, offset);
if (tvb_reported_length_remaining(tvb, offset) <= 0)
break;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_device_characteristics(proto_tree *tn3270_tree, tvbuff_t *tvb,
gint offset, gint sf_body_length)
{
gint start = offset;
#if 0
proto_tree_add_item(tn3270_tree,
hf_tn3270_sf_outbound_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
#endif
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_distributed_data_management(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, i;
gint sdp;
gboolean done = FALSE;
static const hf_items fields[] = {
{ &hf_tn3270_ddm_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ddm_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ddm_limin, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ddm_limout, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ddm_nss, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ddm_ddmss, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i = 0; i < 3; i++) {
sdp = tvb_get_guint8(tvb, offset+1);
switch (sdp) {
case 0x02:
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, tvb_get_guint8(tvb,offset));
break;
case 0x01:
offset += dissect_daid_sd_parm(tn3270_tree, tvb, offset);
break;
case 0x03:
offset += dissect_pclk_sd_parm(tn3270_tree, tvb, offset);
break;
default:
done = TRUE;
break;
}
if ((tvb_reported_length_remaining(tvb, offset) <= 0) || done)
break;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_document_interchange_architecture(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, sdp, ln, i;
static const hf_items fields[] = {
{ &hf_tn3270_dia_flags, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_dia_limin, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_dia_limout, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
ln = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn3270_tree, hf_tn3270_dia_nfs, tvb, offset, 1, ENC_BIG_ENDIAN);
for (i=0; i < ln; i++) {
proto_tree_add_item(tn3270_tree, hf_tn3270_dia_diafs, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tn3270_tree, hf_tn3270_dia_diafn, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 1;
}
sdp = tvb_get_guint8(tvb, offset+1);
if (sdp == 0x01) {
offset += dissect_daid_sd_parm(tn3270_tree, tvb, offset);
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_extended_drawing_routine(proto_tree *tn3270_tree, tvbuff_t *tvb,
gint offset, gint sf_body_length)
{
gint start = offset;
proto_tree_add_item(tn3270_tree, hf_tn3270_field_data ,tvb, offset,
sf_body_length, ENC_EBCDIC|ENC_NA);
offset += sf_body_length;
return (offset - start);
}
static gint
dissect_query_reply_field_outlining(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_fo_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_fo_vpos, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_fo_hpos, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_fo_hpos0, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_fo_hpos1, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_format_storage_aux_device(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, sdp;
static const hf_items fields[] = {
{ &hf_tn3270_fsad_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_fsad_limin, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_fsad_limout, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
sdp = tvb_get_guint8(tvb, offset+1);
if (sdp == 0x01) {
offset += dissect_daid_sd_parm(tn3270_tree, tvb, offset);
proto_tree_add_item(tn3270_tree, hf_tn3270_fsad_size ,tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_highlighting(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint i;
gint np;
static const hf_items fields[] = {
{ &hf_tn3270_h_np, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
np = tvb_get_guint8(tvb, offset);
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i=0; i < np; i++) {
if (tvb_get_guint8(tvb, offset) == 0xFF) {
offset += 1;
}
proto_tree_add_item(tn3270_tree,
hf_tn3270_h_vi,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
if (tvb_get_guint8(tvb, offset) == 0xFF) {
offset += 1;
}
proto_tree_add_item(tn3270_tree,
hf_tn3270_h_ai,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_ibm_aux_device(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, i, sdp;
gboolean done = FALSE;
static const hf_items fields[] = {
{ &hf_tn3270_ibm_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ibm_limin, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ibm_limout, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ibm_type, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i = 0; i < 3; i++) {
sdp = tvb_get_guint8(tvb, offset+1);
switch (sdp) {
case 0x02:
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, tvb_get_guint8(tvb,offset));
break;
case 0x01:
offset += dissect_daid_sd_parm(tn3270_tree, tvb, offset);
break;
case 0x03:
offset += dissect_pclk_sd_parm(tn3270_tree, tvb, offset);
break;
default:
done = TRUE;
break;
}
if ((tvb_reported_length_remaining(tvb, offset) <= 0) || done)
break;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_implicit_partitions_sd_parms(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
gint sdp_len;
gint sdp;
static const hf_items sdp1[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ip_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ipdd_wd, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ipdd_hd, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ipdd_wa, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ipdd_ha, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp2[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ip_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ippd_dpbs, NULL, 4, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ippd_apbs, NULL, 4, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items sdp3[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ip_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ipccd_wcd, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ipccd_hcd, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ipccd_wca, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ipccd_hca, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
sdp_len = tvb_get_guint8(tvb, offset);
if (sdp_len != 0x0B) {
return 0;
}
sdp = tvb_get_guint8(tvb, offset+1);
switch (sdp) {
case QR_IP_SDP_DISPLAY:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp1);
break;
case QR_IP_SDP_PRINTER:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp2);
break;
case QR_IP_SDP_CHARACTER:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
sdp3);
break;
default:
return 0;
}
return (offset - start);
}
static gint
dissect_query_reply_implicit_partitions(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint i;
static const hf_items fields[] = {
{ &hf_tn3270_ip_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ip_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i = 0; i < 3; i++) {
gint len;
len = dissect_query_reply_implicit_partitions_sd_parms(tn3270_tree, tvb, offset);
if ((len == 0) || (tvb_reported_length_remaining(tvb, offset) <= 0))
break;
offset += len;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_ioca_aux_device(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ioca_limin, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ioca_limout, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ioca_type, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_msr_control(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_msr_nd, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_msr_type, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_oem_auxiliary_device(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint i;
static const hf_items fields[] = {
{ &hf_tn3270_resbyte, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_oem_dsref, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_oem_dtype, NULL, 8, NULL, ENC_EBCDIC|ENC_NA },
{ &hf_tn3270_oem_uname, NULL, 8, NULL, ENC_EBCDIC|ENC_NA },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
for (i = 0; i < 3; i++) {
offset += dissect_query_reply_oem_auxiliary_device_sd_parms(tn3270_tree, tvb, offset);
if (tvb_reported_length_remaining(tvb, offset) <= 0)
break;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_paper_feed_techniques(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_pft_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_pft_tmo, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_pft_bmo, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_partition_characteristics(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, i, sdp;
gboolean done = FALSE;
static const hf_items fields[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
for (i = 0; i < 2; i++) {
sdp = tvb_get_guint8(tvb, offset+1);
switch (sdp) {
case 0x01:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
proto_tree_add_item(tn3270_tree, hf_tn3270_pc_vo_thickness,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case 0x03:
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
break;
default:
done = TRUE;
break;
}
if ((tvb_reported_length_remaining(tvb, offset) <= 0) || done)
break;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_product_defined_data_stream(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, sdp;
static const hf_items fields[] = {
{ &hf_tn3270_resbytes, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_pdds_refid, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_pdds_ssid, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
sdp = tvb_get_guint8(tvb, offset+1);
if (sdp == 0x01) {
offset += dissect_daid_sd_parm(tn3270_tree, tvb, offset);
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_modes(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint i;
for (i=0; i < sf_body_length; i++) {
proto_tree_add_item(tn3270_tree,
hf_tn3270_mode,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
}
return (offset - start);
}
static gint
dissect_query_reply_rpq_names(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint rpql;
static const hf_items fields[] = {
{ &hf_tn3270_rpq_device, NULL, 4, NULL, ENC_EBCDIC|ENC_NA },
{ &hf_tn3270_rpq_mid, NULL, 4, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
rpql = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn3270_tree,
hf_tn3270_rpq_rpql,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tn3270_tree,
hf_tn3270_rpq_name,
tvb, offset,
(rpql - 1),
ENC_EBCDIC|ENC_NA);
offset += (rpql-1);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_save_or_restore_format(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_srf_fpcbl, NULL, 1, NULL, ENC_NA },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_settable_printer_characteristics(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, sdp;
static const hf_items fields[] = {
{ &hf_tn3270_resbytes, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items fields2[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
sdp = tvb_get_guint8(tvb, offset+1);
if (sdp == 0x01) {
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields2);
proto_tree_add_item(tn3270_tree, hf_tn3270_spc_epc_flags, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_storage_pools(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, sdp, i;
static const hf_items fields2[] = {
{ &hf_tn3270_sdp_ln, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sdp_id, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sp_spid, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sp_size, NULL, 4, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_sp_space, NULL, 4, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
sdp = tvb_get_guint8(tvb, offset+1);
if (sdp == 0x01) {
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields2);
for (i=0; i < (sf_body_length-(offset-start)); i+=2) {
proto_tree_add_item(tn3270_tree, hf_tn3270_sp_objlist,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_summary(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint i;
gint datalen = 0;
gint length_remaining = tvb_reported_length_remaining(tvb, offset);
for (i=0; i < sf_body_length; i++) {
if (datalen >= length_remaining) {
return (datalen);
}
proto_tree_add_item(tn3270_tree,
hf_tn3270_sf_query_reply,
tvb, offset + datalen,
1,
ENC_BIG_ENDIAN);
datalen += 1;
}
datalen += dissect_unknown_data(tn3270_tree, tvb, offset+datalen, offset, sf_body_length);
return (datalen);
}
static gint
dissect_query_reply_text_partitions(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, len, i;
static const hf_items fields[] = {
{ &hf_tn3270_tp_nt, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_tp_m, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_tp_flags, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn3270_tree, hf_tn3270_tp_ntt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i=0; i < len; i++) {
proto_tree_add_item(tn3270_tree, hf_tn3270_tp_tlist,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_transparency(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset, i, len;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn3270_tree, hf_tn3270_t_np, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i=0; i < len; i+=2) {
proto_tree_add_item(tn3270_tree, hf_tn3270_t_vi,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tn3270_tree, hf_tn3270_t_ai,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_usable_area(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
gint vcp;
static const gint *byte1[] = {
&hf_tn3270_ua_reserved1,
&hf_tn3270_ua_page_printer,
&hf_tn3270_ua_reserved2,
&hf_tn3270_ua_hard_copy,
&hf_tn3270_ua_addressing,
NULL
};
static const gint *byte2[] = {
&hf_tn3270_ua_variable_cells,
&hf_tn3270_ua_characters,
&hf_tn3270_ua_cell_units,
NULL
};
static const hf_items fields[] = {
{ &hf_tn3270_usable_area_flags1, &ett_tn3270_usable_area_flags1, 1, byte1, 0 },
{ &hf_tn3270_usable_area_flags2, &ett_tn3270_usable_area_flags1, 1, byte2, 0 },
{ &hf_tn3270_ua_width_cells_pels, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_height_cells_pels, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_uom_cells_pels, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_xr, NULL, 4, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_yr, NULL, 4, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_aw, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_ah, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_buffsz, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
static const hf_items fields2[] = {
{ &hf_tn3270_ua_xmin, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_ymin, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_xmax, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_ua_ymax, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
vcp = tvb_get_guint8(tvb, offset+1);
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
if ((vcp & QR_UA_VARIABLE_CELLS) != 0) {
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields2);
}
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
dissect_query_reply_3270_ipds(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_body_length)
{
gint start = offset;
static const hf_items fields[] = {
{ &hf_tn3270_resbytes, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_3270_tranlim, NULL, 2, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
offset += tn3270_add_hf_items(tn3270_tree, tvb, offset,
fields);
offset += dissect_unknown_data(tn3270_tree, tvb, offset, start, sf_body_length);
return (offset - start);
}
static gint
process_inbound_structured_field(proto_tree *sf_tree, tvbuff_t *tvb, gint offset,
tn3270_conv_info_t *tn3270_info, guint sf_id, gint sf_body_length)
{
gint start = offset;
switch (sf_id) {
case SF_IB_EXCEPTION_OR_STATUS:
offset += dissect_exception_or_status(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_INBOUND_TEXT_HEADER:
offset += dissect_inbound_text_header(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_INBOUND_3270DS:
offset += dissect_inbound_3270ds(sf_tree, tvb, offset, tn3270_info, sf_body_length);
break;
case SF_IB_RECOVERY_DATA:
offset += dissect_recovery_data(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_TYPE_1_TEXT_INBOUND:
offset += dissect_type_1_text(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_ALPHANUMERIC_PARTITIONS:
offset += dissect_query_reply_alphanumeric(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_AUXILIARY_DEVICE:
case SF_IB_QUERY_REPLY_BEGIN_OR_END_OF_FILE:
offset += dissect_query_reply_resbytes(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_CHARACTER_SETS:
offset += dissect_query_reply_character_sets(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_COLOR:
offset += dissect_query_reply_color(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_COOPERATIVE_PROCESSING_REQUESTOR:
offset += dissect_query_reply_cooperative(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_DATA_CHAINING:
offset += dissect_query_reply_data_chaining(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_DATA_STREAMS:
offset += dissect_query_reply_data_streams(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_DBCS_ASIA:
offset += dissect_query_reply_dbcs_asia(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_DEVICE_CHARACTERISTICS:
offset += dissect_query_reply_device_characteristics(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_SUMMARY:
offset += dissect_query_reply_summary(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_USABLE_AREA:
offset += dissect_query_reply_usable_area(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_HIGHLIGHTING:
offset += dissect_query_reply_highlighting(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_REPLY_MODES:
offset += dissect_query_reply_modes(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_DISTRIBUTED_DATA_MANAGEMENT:
offset += dissect_query_reply_distributed_data_management(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_RPQ_NAMES:
offset += dissect_query_reply_rpq_names(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_IMPLICIT_PARTITION:
offset += dissect_query_reply_implicit_partitions(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_OEM_AUXILIARY_DEVICE:
offset += dissect_query_reply_oem_auxiliary_device(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_DOCUMENT_INTERCHANGE_ARCHITECTURE:
offset += dissect_query_reply_document_interchange_architecture(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_EXTENDED_DRAWING_ROUTINE:
offset += dissect_query_reply_extended_drawing_routine(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_FIELD_OUTLINING:
offset += dissect_query_reply_field_outlining(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_FIELD_VALIDATION:
offset += dissect_3270_field_validation(sf_tree, tvb, offset);
break;
case SF_IB_QUERY_REPLY_FORMAT_STORAGE_AUXILIARY_DEVICE:
offset += dissect_query_reply_format_storage_aux_device(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_GRAPHIC_COLOR:
case SF_IB_QUERY_REPLY_GRAPHIC_SYMBOL_SETS:
case SF_IB_QUERY_REPLY_IMAGE:
case SF_IB_QUERY_REPLY_LINE_TYPE:
case SF_IB_QUERY_REPLY_PROCEDURE:
case SF_IB_QUERY_REPLY_SEGMENT:
offset += dissect_query_reply_extended_drawing_routine(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_IBM_AUXILIARY_DEVICE:
offset += dissect_query_reply_ibm_aux_device(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_IOCA_AUXILIARY_DEVICE:
offset += dissect_query_reply_ioca_aux_device(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_MSR_CONTROL:
offset += dissect_query_reply_msr_control(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_FORMAT_PRESENTATION:
case SF_IB_QUERY_REPLY_NULL:
case SF_IB_QUERY_REPLY_PORT:
break;
case SF_IB_QUERY_REPLY_PAPER_FEED_TECHNIQUES:
offset += dissect_query_reply_paper_feed_techniques(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_PARTITION_CHARACTERISTICS:
offset += dissect_query_reply_partition_characteristics(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_PRODUCT_DEFINED_DATA_STREAM:
offset += dissect_query_reply_product_defined_data_stream(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_SAVE_OR_RESTORE_FORMAT:
offset += dissect_query_reply_save_or_restore_format(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_SETTABLE_PRINTER_CHARACTERISTICS:
offset += dissect_query_reply_settable_printer_characteristics(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_STORAGE_POOLS:
offset += dissect_query_reply_storage_pools(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_TEXT_PARTITIONS:
offset += dissect_query_reply_text_partitions(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_TRANSPARENCY:
offset += dissect_query_reply_transparency(sf_tree, tvb, offset, sf_body_length);
break;
case SF_IB_QUERY_REPLY_3270_IPDS:
offset += dissect_query_reply_3270_ipds(sf_tree, tvb, offset, sf_body_length);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
return (offset - start);
}
static gint
process_outbound_structured_field(proto_tree *sf_tree, tvbuff_t *tvb, gint offset,
tn3270_conv_info_t *tn3270_info, guint sf_id, gint sf_body_length)
{
gint start = offset;
switch (sf_id) {
case SF_OB_READ_PARTITION:
offset += dissect_read_partition(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_ACTIVATE_PARTITION:
case SF_OB_DESTROY_PARTITION:
case SF_OB_RESET_PARTITION:
proto_tree_add_item(sf_tree,
hf_tn3270_partition_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case SF_OB_CREATE_PARTITION:
offset += dissect_create_partition(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_ERASE_OR_RESET:
if ((tvb_get_guint8(tvb, offset) & 0x80) != 0) {
tn3270_info->rows = tn3270_info->altrows;
tn3270_info->cols = tn3270_info->altcols;
}
else {
tn3270_info->rows = 24;
tn3270_info->cols = 80;
}
proto_tree_add_bits_item(sf_tree,
hf_tn3270_erase_flags,
tvb, offset<<3,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case SF_OB_LOAD_PROGRAMMED_SYMBOLS:
offset += dissect_load_programmed_symbols(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_OUTBOUND_3270DS:
offset += dissect_outbound_3270ds(sf_tree, tvb, offset, tn3270_info, sf_body_length);
break;
case SF_OB_PRESENT_ABSOLUTE_FORMAT:
offset += dissect_present_absolute_format(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_PRESENT_RELATIVE_FORMAT:
offset += dissect_present_relative_format(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_SCS_DATA:
proto_tree_add_item(sf_tree,
hf_tn3270_partition_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sf_tree,
hf_tn3270_scs_data,
tvb, offset,
(sf_body_length - (offset - start)),
ENC_NA);
offset += (sf_body_length - (offset - start));
break;
case SF_OB_SET_REPLY_MODE:
offset += dissect_set_reply_mode(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_SELECT_FORMAT_GROUP:
proto_tree_add_item(sf_tree,
hf_tn3270_partition_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sf_tree,
hf_tn3270_format_group,
tvb, offset,
(sf_body_length - (offset - start)),
ENC_EBCDIC|ENC_NA);
offset += (sf_body_length - (offset - start));
break;
case SF_OB_SET_WINDOW_ORIGIN:
proto_tree_add_item(sf_tree,
hf_tn3270_partition_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sf_tree,
hf_tn3270_partition_rw,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sf_tree,
hf_tn3270_partition_cw,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
break;
case SF_OB_BEGIN_OR_END_OF_FILE:
proto_tree_add_item(sf_tree,
hf_tn3270_partition_id,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bits_item(sf_tree,
hf_tn3270_begin_end_flags1,
tvb, offset<<3,
2,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sf_tree,
hf_tn3270_begin_end_flags2,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case SF_OB_LOAD_COLOR_TABLE:
proto_tree_add_item(sf_tree,
hf_tn3270_load_color_command,
tvb, offset,
sf_body_length,
ENC_NA);
offset += sf_body_length;
break;
case SF_OB_LOAD_FORMAT_STORAGE:
offset += dissect_load_format_storage(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_LOAD_LINE_TYPE:
proto_tree_add_item(sf_tree,
hf_tn3270_load_line_type_command,
tvb, offset,
sf_body_length,
ENC_NA);
offset += sf_body_length;
break;
case SF_OB_MODIFY_PARTITION:
offset += dissect_modify_partition(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_OUTBOUND_TEXT_HEADER:
offset += dissect_outbound_text_header(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_REQUEST_RECOVERY_DATA:
proto_tree_add_item(sf_tree,
hf_tn3270_resbyte,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case SF_OB_RESTART:
offset += dissect_restart(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_SELECT_COLOR_TABLE:
proto_tree_add_item(sf_tree,
hf_tn3270_color_command,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
break;
case SF_OB_SET_CHECKPOINT_INTERVAL:
proto_tree_add_item(sf_tree,
hf_tn3270_resbyte,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sf_tree,
hf_tn3270_interval,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
break;
case SF_OB_SET_MSR_CONTROL:
offset += dissect_set_msr_control(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_SET_PARTITION_CHARACTERISTICS:
offset += dissect_set_partition_characteristics(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_SET_PRINTER_CHARACTERISTICS:
offset += dissect_set_printer_characteristics(sf_tree, tvb, offset, sf_body_length);
break;
case SF_OB_TYPE_1_TEXT_OUTBOUND:
offset += dissect_type_1_text(sf_tree, tvb, offset, sf_body_length);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
return (offset - start);
}
static gint
process_outbound_inbound_structured_field(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
tn3270_conv_info_t *tn3270_info _U_, guint sf_id, gint sf_body_length)
{
gint start = offset;
switch (sf_id) {
case SF_OB_IB_DATA_CHAIN:
offset += dissect_data_chain(tn3270_tree, tvb, offset, sf_body_length);
break;
case SF_OB_IB_DESTINATION_OR_ORIGIN:
proto_tree_add_item(tn3270_tree,
hf_tn3270_destination_or_origin_flags_input_control,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tn3270_tree,
hf_tn3270_resbyte,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tn3270_tree,
hf_tn3270_destination_or_origin_doid,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
break;
case SF_OB_IB_OBJECT_DATA:
case SF_OB_IB_OBJECT_CONTROL:
case SF_OB_IB_OBJECT_PICTURE:
case SF_OB_IB_OEM_DATA:
offset += dissect_object_control(tn3270_tree, tvb, offset, sf_body_length);
break;
case SF_OB_IB_SAVE_OR_RESTORE_FORMAT:
offset += dissect_save_or_restore_format(tn3270_tree, tvb, offset, sf_body_length);
break;
case SF_OB_IB_SELECT_IPDS_MODE:
proto_tree_add_item(tn3270_tree,
hf_tn3270_resbytes,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 2;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
return (offset - start);
}
static proto_tree *
display_sf_hdr(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
gint sf_length, guint sf_id, guint sf_id_len, const gchar *sf_id_str)
{
proto_item *pi;
proto_tree *sf_tree;
pi = proto_tree_add_text(tn3270_tree, tvb, offset, sf_length,
"Structured Field: %s", sf_id_str);
sf_tree = proto_item_add_subtree(pi, ett_sf);
proto_tree_add_item(sf_tree,
hf_tn3270_sf_length,
tvb, offset,
2,
ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(sf_tree,
(sf_id_len == 1) ? hf_tn3270_sf_single_byte_id : hf_tn3270_sf_double_byte_id,
tvb, offset+2, sf_id_len,
sf_id, "%s (0x%0*x)", sf_id_str, sf_id_len*2, sf_id);
return sf_tree;
}
static gint
dissect_structured_fields(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset,
tn3270_conv_info_t *tn3270_info, gboolean direction_inbound)
{
proto_tree *sf_tree;
gint start;
gint sf_length;
guint sf_id;
guint sf_id_len;
const gchar *sf_id_str;
start = offset;
while (tvb_reported_length_remaining(tvb, offset) >= 2) {
if ((sf_length = tvb_get_ntohs(tvb, offset)) == 0) {
proto_tree_add_item(tn3270_tree,
hf_tn3270_null,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
continue;
}
sf_id = tvb_get_guint8(tvb, offset+2);
sf_id_len = 1;
if ((sf_id == 0x0F) ||
(sf_id == 0x10) ||
(sf_id == 0x81)) {
sf_id = (sf_id << 8) + tvb_get_guint8(tvb, offset+3);
sf_id_len = 2;
}
sf_id_str = match_strval(sf_id, direction_inbound ?
vals_inbound_structured_fields : vals_outbound_structured_fields);
if (sf_id_str != NULL) {
sf_tree = display_sf_hdr(tn3270_tree, tvb, offset,
sf_length, sf_id, sf_id_len, sf_id_str);
offset += (sf_id_len + 2);
if (direction_inbound) {
offset += process_inbound_structured_field(sf_tree, tvb, offset, tn3270_info, sf_id, sf_length-2-sf_id_len);
}
else {
offset += process_outbound_structured_field(sf_tree, tvb, offset, tn3270_info, sf_id, sf_length-2-sf_id_len);
}
continue;
}
sf_id_str = match_strval(sf_id, vals_outbound_inbound_structured_fields);
if (sf_id_str != NULL) {
sf_tree = display_sf_hdr(tn3270_tree, tvb, offset,
sf_length, sf_id, sf_id_len, sf_id_str);
offset += (sf_id_len + 2);
offset += process_outbound_inbound_structured_field(sf_tree, tvb, offset, tn3270_info, sf_id, sf_length-2-sf_id_len);
continue;
}
sf_id_str = ep_strdup_printf("Unknown [%0*x]", sf_id_len*2, sf_id);
display_sf_hdr(tn3270_tree, tvb, offset, sf_length,
sf_length, sf_id_len, sf_id_str);
offset += sf_length;
continue;
}
return (offset - start);
}
static gint
dissect_stop_address(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
gint is_oc_ge;
proto_tree_add_item(tn3270_tree,
hf_tn3270_stop_address,
tvb, offset,
2,
ENC_BIG_ENDIAN);
offset += 1;
is_oc_ge = tvb_get_guint8(tvb, offset);
if (is_oc_ge != OC_GE) {
proto_tree_add_item(tn3270_tree,
hf_tn3270_character_code,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
}
return (offset - start);
}
static gint
dissect_buffer_address(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset, gint hf, tn3270_conv_info_t *tn3270_info)
{
gint start = offset;
guint16 buffer_addr;
guint16 address_format, address_value;
guint8 b1, b2;
guint8 rowsx = tn3270_info->rows;
guint8 colsx = tn3270_info->cols;
buffer_addr = tvb_get_ntohs(tvb, offset);
address_format = SBA_ADDRESS_FORMAT(buffer_addr);
address_value = SBA_ADDRESS_VALUE(buffer_addr);
switch (address_format) {
case SBA_14_BIT_BINARY:
proto_tree_add_uint_format_value(tn3270_tree,
hf,
tvb, offset, 2,
buffer_addr,
"14-bit address, %u = row %u, column %u [assuming a %ux%u display] (0x%04x)",
address_value,
(address_value / colsx) + 1,
(address_value % colsx) + 1,
rowsx, colsx,
buffer_addr);
break;
case SBA_12_BIT_CODED_1:
case SBA_12_BIT_CODED_2:
b1 = (address_value >> 8) & 0x3F;
b2 = (address_value >> 0) & 0x3F;
address_value = (b1 << 6) | b2;
proto_tree_add_uint_format_value(tn3270_tree,
hf,
tvb, offset, 2,
buffer_addr,
"12-bit address, %u = row %u, column %u [assuming a %ux%u display] (0x%04x)",
address_value,
(address_value / colsx) + 1,
(address_value % colsx) + 1,
rowsx, colsx,
buffer_addr);
break;
case SBA_RESERVED:
proto_tree_add_uint_format_value(tn3270_tree,
hf,
tvb, offset, 2,
buffer_addr,
"Reserved (0x%04x)",
buffer_addr);
break;
}
offset += 2;
return (offset - start);
}
static gint
dissect_field_attribute_pair(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
gint attribute_type;
attribute_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn3270_tree,
hf_tn3270_attribute_type,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
switch (attribute_type) {
case AT_ALL_CHARACTER_ATTRIBUTES:
proto_tree_add_item(tn3270_tree,
hf_tn3270_all_character_attributes,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case AT_T3270_FIELD_ATTRIBUTE:
offset += dissect_3270_field_attribute(tn3270_tree, tvb, offset);
break;
case AT_EXTENDED_HIGHLIGHTING:
proto_tree_add_item(tn3270_tree,
hf_tn3270_extended_highlighting,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case AT_FOREGROUND_COLOR:
case AT_BACKGROUND_COLOR:
proto_tree_add_item(tn3270_tree,
hf_tn3270_color,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case AT_CHARACTER_SET:
proto_tree_add_item(tn3270_tree,
hf_tn3270_character_set,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case AT_FIELD_OUTLINING:
proto_tree_add_item(tn3270_tree,
hf_tn3270_field_outlining,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case AT_TRANSPARENCY:
proto_tree_add_item(tn3270_tree,
hf_tn3270_transparency,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case AT_FIELD_VALIDATION:
offset += dissect_3270_field_validation(tn3270_tree, tvb, offset);
break;
}
return (offset - start);
}
static gint
dissect_field_attribute_pairs(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset;
gint no_of_pairs;
gint i;
no_of_pairs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn3270_tree,
hf_tn3270_number_of_attributes,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
for (i=0; i < no_of_pairs; i++) {
offset += dissect_field_attribute_pair(tn3270_tree, tvb, offset);
}
return (offset - start);
}
static gint
dissect_orders_and_data(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset, tn3270_conv_info_t *tn3270_info)
{
gint start = offset;
gint order_code;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
order_code = tvb_get_guint8(tvb, offset);
if ((order_code > 0) && (order_code <= OC_MAX)) {
proto_tree_add_item(tn3270_tree,
hf_tn3270_order_code,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
switch (order_code) {
case OC_SF:
offset += dissect_3270_field_attribute(tn3270_tree, tvb, offset);
break;
case OC_MF:
case OC_SFE:
offset += dissect_field_attribute_pairs(tn3270_tree, tvb, offset);
break;
case OC_SA:
offset += dissect_field_attribute_pair(tn3270_tree, tvb, offset);
break;
case OC_EUA:
case OC_RA:
offset += dissect_stop_address(tn3270_tree, tvb, offset);
break;
case OC_GE:
proto_tree_add_item(tn3270_tree,
hf_tn3270_character_code,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case OC_SBA:
offset += dissect_buffer_address(tn3270_tree, tvb, offset, hf_tn3270_buffer_address, tn3270_info);
break;
case OC_PT:
case OC_IC:
break;
default:
proto_tree_add_text(tn3270_tree, tvb, offset, 1, "Bogus value: %u", order_code);
break;
}
}
else {
offset += add_data_until_next_order_code(tn3270_tree, tvb, offset);
}
}
return (offset - start);
}
static gint
dissect_tn3270e_header(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset)
{
proto_item *pi;
proto_tree *tn3270e_hdr_tree;
gint start = offset;
gint data_type;
static const hf_items fields[] = {
{ &hf_tn3270_tn3270e_data_type, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ &hf_tn3270_tn3270e_request_flag, NULL, 1, NULL, ENC_BIG_ENDIAN },
{ NULL, NULL, 0, NULL, 0 }
};
data_type = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_text(tn3270_tree, tvb, offset, -1,
"TN3270E Header (Data Type: %s)",
val_to_str_const(data_type, vals_tn3270_header_data_types, "Unknown"));
tn3270e_hdr_tree = proto_item_add_subtree(pi, ett_tn3270e_hdr);
offset += tn3270_add_hf_items(tn3270e_hdr_tree, tvb, offset,
fields);
switch(data_type) {
case TN3270E_3270_DATA:
case TN3270E_SCS_DATA:
proto_tree_add_item(tn3270e_hdr_tree, hf_tn3270_tn3270e_response_flag_3270_SCS, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case TN3270E_RESPONSE:
proto_tree_add_item(tn3270e_hdr_tree, hf_tn3270_tn3270e_response_flag_response, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case TN3270E_BIND_IMAGE:
case TN3270E_NVT_DATA:
case TN3270E_REQUEST:
case TN3270E_SSCP_LU_DATA:
case TN3270E_UNBIND:
default:
proto_tree_add_item(tn3270e_hdr_tree, hf_tn3270_tn3270e_response_flag_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
offset += 1;
proto_tree_add_item(tn3270e_hdr_tree, hf_tn3270_tn3270e_seq_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (data_type) {
case TN3270E_BIND_IMAGE:
case TN3270E_NVT_DATA:
case TN3270E_REQUEST:
case TN3270E_RESPONSE:
case TN3270E_SCS_DATA:
case TN3270E_SSCP_LU_DATA:
case TN3270E_UNBIND:
proto_tree_add_item(tn3270e_hdr_tree, hf_tn3270_tn3270e_header_data, tvb, offset, -1, ENC_EBCDIC|ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
break;
default:
break;
}
proto_item_set_len(pi, offset - start);
return (offset - start);
}
static gint
dissect_outbound_stream(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset, tn3270_conv_info_t *tn3270_info)
{
gint command_code;
gint start = offset;
command_code = tvb_get_guint8(tvb, offset);
switch (command_code) {
case CC_LCL_EW:
case CC_RMT_EW:
tn3270_info->rows = 24;
tn3270_info->cols = 80;
break;
case CC_LCL_EWA:
case CC_RMT_EWA:
tn3270_info->rows = tn3270_info->altrows;
tn3270_info->cols = tn3270_info->altcols;
break;
default:
break;
}
switch (command_code) {
case CC_LCL_W:
case CC_LCL_EW:
case CC_LCL_EWA:
case CC_LCL_EAU:
case CC_RMT_W:
case CC_RMT_EW:
case CC_RMT_EWA:
case CC_RMT_EAU:
proto_tree_add_item(tn3270_tree,
hf_tn3270_command_code,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
offset += dissect_wcc(tn3270_tree, tvb, offset);
offset += dissect_orders_and_data(tn3270_tree, tvb, offset, tn3270_info);
break;
case CC_LCL_WSF:
case CC_RMT_WSF:
proto_tree_add_item(tn3270_tree,
hf_tn3270_command_code,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
offset += dissect_structured_fields(tn3270_tree, tvb, offset, tn3270_info, FALSE);
break;
case CC_LCL_RB:
case CC_LCL_RM:
case CC_LCL_RMA:
case CC_RMT_RB:
case CC_RMT_RM:
case CC_RMT_RMA:
proto_tree_add_item(tn3270_tree,
hf_tn3270_command_code,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
break;
default:
proto_tree_add_text(tn3270_tree, tvb, offset, 1, "Bogus value: %u", command_code);
offset += 1;
break;
}
return (offset - start);
}
static gint
dissect_inbound_stream(proto_tree *tn3270_tree, tvbuff_t *tvb, gint offset, tn3270_conv_info_t *tn3270_info)
{
gint start = offset;
gint aid;
aid = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn3270_tree,
hf_tn3270_aid,
tvb, offset,
1,
ENC_BIG_ENDIAN);
offset += 1;
switch (aid) {
case AID_STRUCTURED_FIELD:
offset += dissect_structured_fields(tn3270_tree, tvb, offset, tn3270_info, TRUE);
break;
case AID_PA1_KEY:
case AID_PA2_KEY_CNCL:
case AID_PA3_KEY:
case AID_CLEAR_KEY:
if (tvb_reported_length_remaining(tvb, offset) <= 0)
break;
case AID_READ_PARTITION_AID:
case AID_NO_AID_GENERATED:
case AID_NO_AID_GENERATED_PRINTER_ONLY:
case AID_TRIGGER_ACTION:
case AID_TEST_REQ_AND_SYS_REQ:
case AID_PF1_KEY:
case AID_PF2_KEY:
case AID_PF3_KEY:
case AID_PF4_KEY:
case AID_PF5_KEY:
case AID_PF6_KEY:
case AID_PF7_KEY:
case AID_PF8_KEY:
case AID_PF9_KEY:
case AID_PF10_KEY:
case AID_PF11_KEY:
case AID_PF12_KEY:
case AID_PF13_KEY:
case AID_PF14_KEY:
case AID_PF15_KEY:
case AID_PF16_KEY:
case AID_PF17_KEY:
case AID_PF18_KEY:
case AID_PF19_KEY:
case AID_PF20_KEY:
case AID_PF21_KEY:
case AID_PF22_KEY:
case AID_PF23_KEY:
case AID_PF24_KEY:
case AID_CLEAR_PARTITION_KEY:
case AID_ENTER_KEY:
case AID_SELECTOR_PEN_ATTENTION:
case AID_OPERATOR_ID_READER:
case AID_MAG_READER_NUMBER:
offset += dissect_buffer_address(tn3270_tree, tvb, offset, hf_tn3270_cursor_address, tn3270_info);
offset += dissect_orders_and_data(tn3270_tree, tvb, offset, tn3270_info);
break;
default:
proto_tree_add_text(tn3270_tree, tvb, offset, 1, "Bogus value: %u", aid);
offset += 1;
break;
}
return (offset - start);
}
static void
dissect_tn3270(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *tn3270_tree;
proto_item *pi;
gint offset = 0;
conversation_t *conversation;
tn3270_conv_info_t *tn3270_info = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TN3270");
pinfo->fd->flags.encoding = PACKET_CHAR_ENC_CHAR_EBCDIC;
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation != NULL) {
tn3270_info = conversation_get_proto_data(conversation, proto_tn3270);
}
if (tn3270_info == NULL)
return;
pi = proto_tree_add_item(tree, proto_tn3270, tvb, offset, -1, ENC_NA);
tn3270_tree = proto_item_add_subtree(pi, ett_tn3270);
col_clear(pinfo->cinfo, COL_INFO);
if (tn3270_info->extended) {
offset += dissect_tn3270e_header(tn3270_tree, tvb, offset);
}
if (tvb_reported_length_remaining(tvb, offset) <= 0)
return;
if (pinfo->srcport == tn3270_info->outbound_port) {
col_set_str(pinfo->cinfo, COL_INFO, "TN3270 Data from Mainframe");
}
else {
col_set_str(pinfo->cinfo, COL_INFO, "TN3270 Data to Mainframe");
}
if(tree) {
while (tvb_reported_length_remaining(tvb, offset) > 0) {
if (pinfo->srcport == tn3270_info->outbound_port) {
offset += dissect_outbound_stream(tn3270_tree, tvb, offset, tn3270_info);
}
else {
offset += dissect_inbound_stream(tn3270_tree, tvb, offset, tn3270_info);
}
}
}
}
void
add_tn3270_conversation(packet_info *pinfo, int tn3270e, gint model)
{
conversation_t *conversation;
tn3270_conv_info_t *tn3270_info;
conversation = find_or_create_conversation(pinfo);
tn3270_info = conversation_get_proto_data(conversation, proto_tn3270);
if (tn3270_info == NULL) {
tn3270_info = se_alloc(sizeof(tn3270_conv_info_t));
COPY_ADDRESS(&(tn3270_info->outbound_addr), &(pinfo->dst));
tn3270_info->outbound_port = pinfo->destport;
COPY_ADDRESS(&(tn3270_info->inbound_addr), &(pinfo->src));
tn3270_info->inbound_port = pinfo->srcport;
conversation_add_proto_data(conversation, proto_tn3270, tn3270_info);
}
switch (model) {
default:
case 2:
tn3270_info->altrows = 24;
tn3270_info->altcols = 80;
break;
case 3:
tn3270_info->altrows = 32;
tn3270_info->altcols = 80;
break;
case 4:
tn3270_info->altrows = 43;
tn3270_info->altcols = 80;
break;
case 5:
tn3270_info->altrows = 27;
tn3270_info->altcols = 132;
break;
}
tn3270_info->rows = 24;
tn3270_info->cols = 80;
tn3270_info->extended = tn3270e;
}
int
find_tn3270_conversation(packet_info *pinfo)
{
conversation_t *conversation = NULL;
tn3270_conv_info_t *tn3270_info = NULL;
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation != NULL) {
tn3270_info = conversation_get_proto_data(conversation, proto_tn3270);
if (tn3270_info != NULL) {
return 1;
}
}
return 0;
}
void
proto_register_tn3270(void)
{
static hf_register_info hf[] = {
{ &hf_tn3270_command_code,
{ "Command Code",
"tn3270.command_code",
FT_UINT8, BASE_HEX, VALS(vals_command_codes), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sf_length,
{ "Structured Field Length",
"tn3270.sf_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_wcc_nop,
{ "WCC NOP",
"tn3270.wcc.nop",
FT_BOOLEAN, 8, NULL, WCC_NOP,
NULL, HFILL }
},
{ &hf_tn3270_wcc_reset,
{ "WCC Reset",
"tn3270.wcc.reset",
FT_BOOLEAN, 8, NULL, WCC_RESET,
NULL, HFILL }
},
{ &hf_tn3270_wcc_printer1,
{ "WCC Printer1",
"tn3270.wcc.printer1",
FT_BOOLEAN, 8, NULL, WCC_PRINTER1,
NULL, HFILL }
},
{ &hf_tn3270_wcc_printer2,
{ "WCC Printer2",
"tn3270.wcc.printer2",
FT_BOOLEAN, 8, NULL, WCC_PRINTER2,
NULL, HFILL }
},
{ &hf_tn3270_wcc_start_printer,
{ "WCC Start Printer",
"tn3270.wcc.start_printer",
FT_BOOLEAN, 8, NULL, WCC_START_PRINTER,
NULL, HFILL }
},
{ &hf_tn3270_wcc_sound_alarm,
{ "WCC Sound Alarm",
"tn3270.wcc.sound_alarm",
FT_BOOLEAN, 8, NULL, WCC_SOUND_ALARM,
NULL, HFILL }
},
{ &hf_tn3270_wcc_keyboard_restore,
{ "WCC Keyboard Restore",
"tn3270.wcc.keyboard_restore",
FT_BOOLEAN, 8, NULL, WCC_KEYBOARD_RESTORE,
NULL, HFILL }
},
{ &hf_tn3270_wcc_reset_mdt,
{ "WCC Reset MDT",
"tn3270.wcc.reset_mdt",
FT_BOOLEAN, 8, NULL, WCC_RESET_MDT,
NULL, HFILL }
},
{ &hf_tn3270_ccc,
{ "Copy Control Code",
"tn3270.ccc",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_tn3270_ccc_coding,
{ "Coding",
"tn3270.ccc_coding",
FT_UINT8, BASE_HEX, NULL, CCC_GRAPHIC_CONVERT_MASK,
NULL, HFILL }
},
{ &hf_tn3270_ccc_printout,
{ "Printout Format",
"tn3270.ccc_printout",
FT_UINT8, BASE_HEX, VALS(ccc_vals_printout_format), CCC_PRINT_BITS_MASK,
NULL, HFILL }
},
{ &hf_tn3270_ccc_start_print,
{ "The start-print bit",
"tn3270.ccc_start_print",
FT_BOOLEAN, 8, NULL, CCC_START_PRINT,
NULL, HFILL }
},
{ &hf_tn3270_ccc_sound_alarm,
{ "The sound-alarm bit",
"tn3270.ccc_sound_alarm",
FT_BOOLEAN, 8, NULL, CCC_SOUND_ALARM,
NULL, HFILL }
},
{ &hf_tn3270_ccc_copytype,
{ "Type of Data to be Copied",
"tn3270.ccc_copytype",
FT_UINT8, BASE_HEX, VALS(ccc_vals_copytype), CCC_ATTRIBUTE_BITS_MASK,
NULL, HFILL }
},
{ &hf_tn3270_field_attribute,
{ "3270 Field Attribute",
"tn3270.field_attribute",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_tn3270_fa_graphic_convert,
{ "Graphic Convert",
"tn3270.fa.graphic_convert",
FT_UINT8, BASE_HEX, NULL, FA_GRAPHIC_CONVERT_MASK,
NULL, HFILL }
},
{ &hf_tn3270_fa_protected,
{ "Protected",
"tn3270.fa.protected",
FT_BOOLEAN, 8, NULL, FA_PROTECTED,
NULL, HFILL }
},
{ &hf_tn3270_fa_numeric,
{ "Numeric",
"tn3270.fa.numeric",
FT_BOOLEAN, 8, NULL, FA_NUMERIC,
NULL, HFILL }
},
{ &hf_tn3270_fa_display,
{ "Display",
"tn3270.fa.display",
FT_UINT8, BASE_HEX, VALS(vals_fa_display), FA_DISPLAY_BITS_MASK,
NULL, HFILL }
},
{ &hf_tn3270_fa_reserved,
{ "Reserved",
"tn3270.fa.reserved",
FT_BOOLEAN, 8, NULL, FA_RESERVED,
NULL, HFILL }
},
{ &hf_tn3270_fa_modified,
{ "Modified",
"tn3270.fa.modified",
FT_BOOLEAN, 8, NULL, FA_MODIFIED,
NULL, HFILL }
},
{ &hf_tn3270_order_code,
{ "Order Code",
"tn3270.order_code",
FT_UINT8, BASE_HEX, VALS(vals_order_codes), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_character_code,
{ "Character Code",
"tn3270.character_code",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_stop_address,
{ "Stop Address",
"tn3270.stop_address",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_attribute_type,
{ "Attribute Type",
"tn3270.attribute_type",
FT_UINT8, BASE_HEX, VALS(vals_attribute_types), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_highlighting,
{ "Extended Highlighting",
"tn3270.extended_highlighting",
FT_UINT8, BASE_HEX, VALS(vals_at_extended_highlighting), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_color,
{ "Color",
"tn3270.color",
FT_UINT8, BASE_HEX, VALS(vals_at_color_identifications), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_character_set,
{ "Character Set",
"tn3270.character_set",
FT_UINT8, BASE_RANGE_STRING|BASE_HEX, RVALS(rvals_at_character_set), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_field_outlining,
{ "Field Outlining",
"tn3270.field_outlining",
FT_UINT8, BASE_HEX, VALS(vals_at_field_outlining), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_transparency,
{ "Transparency",
"tn3270.transparency",
FT_UINT8, BASE_HEX, VALS(vals_at_transparency), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_field_validation_mandatory_fill,
{ "3270 Field validation_mandatory_fill",
"tn3270.field_validation_mandatory_fill",
FT_BOOLEAN, 8, TFS(&tn3270_field_validation_mandatory_fill), AT_FV_MANDATORY_FILL,
NULL, HFILL }
},
{ &hf_tn3270_field_validation_mandatory_entry,
{ "3270 Field validation_mandatory_entry",
"tn3270.field_validation_mandatory_entry",
FT_BOOLEAN, 8, TFS(&tn3270_field_validation_mandatory_entry), AT_FV_MANDATORY_ENTRY,
NULL, HFILL }
},
{ &hf_tn3270_field_validation_trigger,
{ "3270 Field validation_trigger",
"tn3270.field_validation_trigger",
FT_BOOLEAN, 8, TFS(&tn3270_field_validation_trigger), AT_FV_TRIGGER,
NULL, HFILL }
},
{ &hf_tn3270_all_character_attributes,
{ "all_character_attributes",
"tn3270.all_character_attributes",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_aid,
{ "Attention Identification",
"tn3270.aid",
FT_UINT8, BASE_HEX, VALS(vals_attention_identification_bytes), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_buffer_address,
{ "Buffer Address",
"tn3270.buffer_address",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdp_ln,
{ "Length of this Self-Defining Parameter",
"tn3270.sdp_ln",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdp_id,
{ "Self-Defining Parameter ID",
"tn3270.sdp_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_begin_end_flags1,
{ "Begin End Flags1",
"tn3270.begin_end_flags1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_begin_end_flags2,
{ "Begin End Flags2",
"tn3270.begin_end_flags2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_id,
{ "Partition ID",
"tn3270.partition_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_uom,
{ "The unit of measure and address mode",
"tn3270.partition_uom",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_flags,
{ "Flags",
"tn3270.partition_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_height,
{ "The height of the presentation space",
"tn3270.partition_height",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_width,
{ "The width of the presentation space",
"tn3270.partition_width",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_rv,
{ "The y, or row, origin of the viewport relative to the top edge of the usable area",
"tn3270.partition_rv",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_cv,
{ "The x, or column, origin of the viewport relative to the left side of the usable area",
"tn3270.partition_cv",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_hv,
{ "The height of the viewport",
"tn3270.partition_hv",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_wv,
{ "The width of the viewport",
"tn3270.partition_wv",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_rw,
{ "The y, or row, origin of the window relative to the top edge of the presentation space",
"tn3270.partition_rw",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_cw,
{ "The x, or column, origin of the window relative to the left edge of the presentation space",
"tn3270.partition_cw",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_rs,
{ "The number of units to be scrolled in a vertical multiple scroll",
"tn3270.partition_rs",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_res,
{ "Reserved",
"tn3270.partition_res",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_pw,
{ "The number of points in the horizontal direction in a character cell in this presentation space",
"tn3270.partition_pw",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_ph,
{ "The number of points in the vertical direction in a character cell in this presentation space",
"tn3270.partition_ph",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_partition_command,
{ "Partition Command",
"tn3270.partition_command",
FT_UINT8, BASE_HEX, VALS(vals_command_codes), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_erase_flags,
{ "Erase Flags",
"tn3270.erase_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_load_color_command,
{ "Command",
"tn3270.load_color_command",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_load_format_storage_flags1,
{ "Flags",
"tn3270.load_format_storage_flags1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_load_format_storage_flags2,
{ "Flags (Reserved)",
"tn3270.load_format_storage_flags2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_load_format_storage_operand,
{ "Operand:",
"tn3270.load_format_storage_operand",
FT_UINT8, BASE_HEX, VALS(vals_load_storage_format_operand), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_load_format_storage_localname,
{ "Local name for user selectable formats",
"tn3270.load_format_storage_localname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_format_group,
{ "Format Group name",
"tn3270.format_group_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_format_name,
{ "Format name",
"tn3270.format_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_load_format_storage_format_data,
{ "Format data",
"tn3270.load_format_storage_format_data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn3270_load_line_type_command,
{ "Line Type Command",
"tn3270.load_line_type_command",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ps_flags,
{ "Flags",
"tn3270.ps_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ps_lcid,
{ "Local character set ID",
"tn3270.ps_lcid",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ps_char,
{ "Beginning code point X'41' through X'FE'",
"tn3270.ps_char",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ps_rws,
{ "Loadable Character Set RWS Number",
"tn3270.ps_rws",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_length,
{ "Length of parameters for extended form, including the length parameter",
"tn3270.extended_ps_length",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_flags,
{ "Flags",
"tn3270.extended_ps_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_lw,
{ "Number of X-units in character cell (width of character matrixes)",
"tn3270.extended_ps_lw",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_lh,
{ "Number of Y-units in character cell (depth ofcharacter matrixes)",
"tn3270.extended_ps_lh",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_subsn,
{ "Subsection ID",
"tn3270.extended_ps_subsn",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_color,
{ "Color planes",
"tn3270.extended_ps_color",
FT_UINT8, BASE_HEX, VALS(vals_at_color_identifications), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_stsubs,
{ "Starting Subsection Identifier",
"tn3270.extended_ps_stsubs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_echar,
{ "Ending code point",
"tn3270.extended_ps_echar",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_nw,
{ "Number of width pairs",
"tn3270.extended_ps_nw",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_nh,
{ "Number of height pairs",
"tn3270.extended_ps_nh",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_extended_ps_res,
{ "Reserved",
"tn3270.extended_ps_res",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_outbound_text_header_operation_type,
{ "Outbound Text Operation Type",
"tn3270.outbound_text_operation_type",
FT_UINT8, BASE_HEX, VALS(vals_command_codes), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_lvl,
{ "Cursor level",
"tn3270.lvl",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cro,
{ "Cursor row offset",
"tn3270.cro",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cc,
{ "Cursor column offset",
"tn3270.cc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_outbound_text_header_lhdr,
{ "Header length includes itself",
"tn3270.outbound_text_header_lhdr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_outbound_text_header_hdr,
{ "Initial format controls",
"tn3270.outbound_text_header_hdr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_bsc,
{ "SNA BSC",
"tn3270.bsc",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fpc,
{ "Format Presentation Command",
"tn3270.fpc",
FT_UINT8, BASE_HEX, VALS(vals_command_codes), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fov,
{ "Format Offset Value",
"tn3270.fov",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_read_partition_operation_type,
{ "Read Partition Operation Type",
"tn3270.read_partition_reqtyp",
FT_UINT8, BASE_HEX, VALS(vals_read_partition_operation_type), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_read_partition_reqtyp,
{ "Read Partition Request Type",
"tn3270.read_partition_reqtyp",
FT_UINT8, BASE_HEX, VALS(vals_read_partition_reqtype), READ_PARTITION_REQTYPE_MASK,
NULL, HFILL }
},
{ &hf_tn3270_start_page,
{ "Number of pages to skip on restart",
"tn3270.start_page",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_start_line,
{ "Number of lines to skip on page for restart",
"tn3270.start_line",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_scs_data,
{ "SCS data (noncompressed and noncompacted) to set up for restart",
"tn3270.scs_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_color_command,
{ "Color Command",
"tn3270.color_command",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_interval,
{ "Checkpoint interval",
"tn3270.interval",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Specifies the number of pages in the interval between terminal checkpoints", HFILL }
},
{ &hf_tn3270_msr_type,
{ "MSR type",
"tn3270.msr_type",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_msr_state_mask,
{ "State Mask",
"tn3270.msr_state_mask",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_msr_user,
{ "User Mode",
"tn3270.msr.user",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_tn3270_msr_locked,
{ "Locked",
"tn3270.msr.locked",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_tn3270_msr_auto,
{ "Auto Enter",
"tn3270.msr.auto",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_tn3270_msr_ind1,
{ "Audible Ind 1 Suppress",
"tn3270.msr.ind1",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_tn3270_msr_ind2,
{ "Audible Ind 2 Suppress",
"tn3270.msr.ind2",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_tn3270_msr_state_value,
{ "State Value", "tn3270.msr_state_value",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_msr_ind_mask,
{ "Indicator Mask",
"tn3270.msr_ind_mask",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_msr_ind_value,
{ "Indicator Value",
"tn3270.msr_ind_value",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_spc_sdp_ot,
{ "Top edge outline thickness",
"tn3270.spc_sdp_ot",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_spc_sdp_ob,
{ "Bottom edge outline thickness",
"tn3270.spc_sdp_ob",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_spc_sdp_ol,
{ "Left edge outline thickness",
"tn3270.spc_sdp_ol",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_spc_sdp_or,
{ "Right edge outline thickness",
"tn3270.spc_sdp_or",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_spc_sdp_eucflags,
{ "Flags",
"tn3270.spc_sdp_eucflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_printer_flags,
{ "Flags",
"tn3270.printer_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_spc_sdp_srepc,
{ "Set/Reset Early Print Complete",
"tn3270.spc_sdp_srepc",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_mode,
{ "Mode",
"tn3270.mode",
FT_UINT8, BASE_HEX, VALS(vals_reply_modes), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_reply_mode_attr_list,
{ "Type codes for the attribute types",
"tn3270.reply_mode_attr_list",
FT_UINT8, BASE_HEX, VALS(vals_attribute_types), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_data_chain_fields,
{ "Data Chain Fields",
"tn3270.data_chain_fields",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_data_chain_group,
{ "Data Chain Group",
"tn3270.data_chain_group",
FT_UINT8, BASE_HEX, VALS(vals_data_chain_group), DATA_CHAIN_GROUP_MASK,
NULL, HFILL }
},
{ &hf_tn3270_data_chain_inbound_control,
{ "Data Chain Inbound Control",
"tn3270.data_chain_inbound_control",
FT_UINT8, BASE_HEX, VALS(vals_data_chain_inbound_control), DATA_CHAIN_INBOUND_CONTROL_MASK,
NULL, HFILL }
},
{ &hf_tn3270_destination_or_origin_flags_input_control,
{ "Input Control",
"tn3270.destination_or_origin_flags_input_control",
FT_UINT8, BASE_HEX, VALS(vals_destination_or_origin_flags_input_control), DESTINATION_OR_ORIGIN_FLAGS_INPUT_CONTROL_MASK,
NULL, HFILL }
},
{ &hf_tn3270_destination_or_origin_doid,
{ "DOID",
"tn3270.destination_or_origin_doid",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_object_control_flags,
{ "Flags",
"tn3270.object_control_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_object_type,
{ "Object Type",
"tn3270.object_type",
FT_UINT8, BASE_HEX, VALS(vals_oc_type), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_save_or_restore_format_flags,
{ "Flags",
"tn3270.save_or_restore_format_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_srf_fpcb,
{ "Contents of the FPCB that is to be saved or restored",
"tn3270.srf_fpcb",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_type_1_text_outbound_data,
{ "Type 1 text outbound data",
"tn3270.type_1_text_outbound_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_exception_or_status_flags,
{ "Flags",
"tn3270.exception_or_status_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdp_excode,
{ "Exception Code",
"tn3270.sdp_excode",
FT_UINT16, BASE_DEC, VALS(vals_sdp_excode), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdp_statcode,
{ "Status Code",
"tn3270.sdp_statcode",
FT_UINT16, BASE_DEC, VALS(vals_sdp_statcode), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdp_ngl,
{ "Number of groups currently assigned",
"tn3270.sdp_ngl",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdp_nml,
{ "Number of formats currently loaded",
"tn3270.sdp_nml",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdp_nlml,
{ "Number of local names used",
"tn3270.sdp_nlml",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdp_stor,
{ "Amount of format storage space available (KB)",
"tn3270.sdp_stor",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_hw,
{ "Window height",
"tn3270.hw",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_rw,
{ "Row offset of window origin",
"tn3270.rw",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ww,
{ "Window width",
"tn3270.ww",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cw,
{ "Column Offset of Window Origin",
"tn3270.cw",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cursor_address,
{ "Cursor Address",
"tn3270.cursor_address",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_recovery_data_flags,
{ "Flags",
"tn3270.recovery_data_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sld,
{ "SLD -- Set line density parameter in effect at the checkpoint",
"tn3270.sld",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_charset,
{ "Character set parameter of Set Attribute control in effect at the checkpoint",
"tn3270.charset",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_vertical,
{ "Byte offset from Checkpoint Interval structured field to the Set Vertical Format control in effect for the checkpoint",
"tn3270.vertical",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_v_offset,
{ "Byte offset within the string control byte string or the SVF character",
"tn3270.v_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_v_sequence,
{ "RU sequence number",
"tn3270.v_sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_v_length,
{ "Length of the SVF character string required for restart",
"tn3270.v_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_spd,
{ "Set Primary Density parameter in effect at the checkpoint",
"tn3270.spd",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_horizon,
{ "Byte offset from Checkpoint Interval structured field to the Set Horizontal Format control in effect for the checkpoint",
"tn3270.horizon",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_h_offset,
{ "Byte offset from Checkpoint Interval structured field to the Set Horizontal Format control in effect for the checkpoint",
"tn3270.h_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_h_sequence,
{ "RU sequence number",
"tn3270.h_sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_h_length,
{ "Length of the SHF character string required for restart",
"tn3270.h_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_hilite,
{ "Highlighting",
"tn3270.hilite",
FT_UINT8, BASE_HEX, VALS(vals_at_extended_highlighting), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_pages,
{ "Number of pages printed since the checkpoint",
"tn3270.pages",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_lines,
{ "Number of lines printed since the checkpoint",
"tn3270.lines",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_checkpoint,
{ "Byte offset from Set Checkpoint Interval structured field to the first"
" character afterhe code point or character that caused an eject to the"
" checkpointed page",
"tn3270.checkpoint",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_c_offset,
{ "Byte offset within the String Control Byte string or structured field of"
" the checkpointed character",
"tn3270.c_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_c_sequence,
{ "RU sequence number of the RU containing the checkpoint character",
"tn3270.c_sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_c_seqoff,
{ "Byte offset within the RU of the checkpointed character",
"tn3270.c_seqoff",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_c_scsoff,
{ "Byte offset within the parameterized SCS control code (for example, TRN) of the checkpointed character.",
"tn3270.c_scsoff",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_prime,
{ "Prime compression character",
"tn3270.prime",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ap_na,
{ "Max number of alphanumeric partitions",
"tn3270.ap_na",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ap_m,
{ "Total available partition storage",
"tn3270.ap_m",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_query_reply_alphanumeric_flags,
{ "Flags",
"tn3270.ap_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ap_vertical_scrolling,
{ "Vertical Scrolling Supported",
"tn3270.ap_vertical_scrolling",
FT_BOOLEAN, 8, NULL, QR_AP_VERTWIN,
NULL, HFILL }
},
{ &hf_tn3270_ap_horizontal_scrolling,
{ "Horizontal Scrolling Supported",
"tn3270.ap_horizontal_scrolling",
FT_BOOLEAN, 8, NULL, QR_AP_HORWIN,
NULL, HFILL }
},
{ &hf_tn3270_ap_apres1,
{ "Reserved",
"tn3270.ap_apres1",
FT_BOOLEAN, 8, NULL, QR_AP_APRES1,
NULL, HFILL }
},
{ &hf_tn3270_ap_apa,
{ "All Points addressability supported",
"tn3270.ap_apa",
FT_BOOLEAN, 8, NULL, QR_AP_APA_FLG,
NULL, HFILL }
},
{ &hf_tn3270_ap_pp,
{ "Partition protection supported",
"tn3270.ap_pp",
FT_BOOLEAN, 8, NULL, QR_AP_PROT,
NULL, HFILL }
},
{ &hf_tn3270_ap_lc,
{ "Presentation space local copy supported",
"tn3270.ap_lc",
FT_BOOLEAN, 8, NULL, QR_AP_LCOPY,
NULL, HFILL }
},
{ &hf_tn3270_ap_mp,
{ "Modify Partition supported",
"tn3270.ap_mp",
FT_BOOLEAN, 8, NULL, QR_AP_MODPART,
NULL, HFILL }
},
{ &hf_tn3270_ap_apres2,
{ "Reserved",
"tn3270.ap_apres2",
FT_BOOLEAN, 8, NULL, QR_AP_APRES2,
NULL, HFILL }
},
{ &hf_tn3270_ap_cm,
{ "Character multiplier",
"tn3270.ap_cm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ap_ro,
{ "Row overhead",
"tn3270.ap_ro",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ap_co,
{ "Column overhead",
"tn3270.ap_co",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ap_fo,
{ "Fixed overhead",
"tn3270.ap_fo",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_character_sets_flags1,
{ "Flags (1)",
"tn3270.character_sets_flags1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cs_ge,
{ "Graphic Escape supported",
"tn3270.cs_ge",
FT_BOOLEAN, 8, NULL, QR_CS_ALT,
NULL, HFILL }
},
{ &hf_tn3270_cs_mi,
{ "Multiple LCIDs are supported",
"tn3270.cs_mi",
FT_BOOLEAN, 8, NULL, QR_CS_MULTID,
NULL, HFILL }
},
{ &hf_tn3270_cs_lps,
{ "Load PSSF is supported",
"tn3270.cs_lps",
FT_BOOLEAN, 8, NULL, QR_CS_LOADABLE,
NULL, HFILL }
},
{ &hf_tn3270_cs_lpse,
{ "Load PS EXTENDED is supported",
"tn3270.cs_lpse",
FT_BOOLEAN, 8, NULL, QR_CS_EXT,
NULL, HFILL }
},
{ &hf_tn3270_cs_ms,
{ "More than one size of character slot is supported",
"tn3270.cs_ms",
FT_BOOLEAN, 8, NULL, QR_CS_MS,
NULL, HFILL }
},
{ &hf_tn3270_cs_ch2,
{ "Two-byte coded character sets are supported",
"tn3270.cs_ch2",
FT_BOOLEAN, 8, NULL, QR_CS_CH2,
NULL, HFILL }
},
{ &hf_tn3270_cs_gf,
{ "CGCSGID is present",
"tn3270.cs_gf",
FT_BOOLEAN, 8, NULL, QR_CS_GF,
NULL, HFILL }
},
{ &hf_tn3270_cs_res,
{ "Reserved",
"tn3270.cs_res",
FT_BOOLEAN, 8, NULL, QR_CS_CSRES,
NULL, HFILL }
},
{ &hf_tn3270_character_sets_flags2,
{ "Flags (2)",
"tn3270.character_sets_flags2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cs_res2,
{ "Reserved",
"tn3270.cs_res2",
FT_BOOLEAN, 8, NULL, QR_CS_CSRES2,
NULL, HFILL }
},
{ &hf_tn3270_cs_pscs,
{ "Load PS slot size match not required",
"tn3270.cs_pscs",
FT_BOOLEAN, 8, NULL, QR_CS_PSCS,
NULL, HFILL }
},
{ &hf_tn3270_cs_res3,
{ "Reserved",
"tn3270.cs_res3",
FT_BOOLEAN, 8, NULL, QR_CS_CSRES3,
NULL, HFILL }
},
{ &hf_tn3270_cs_cf,
{ "CCSID present",
"tn3270.cs_cf",
FT_BOOLEAN, 8, NULL, QR_CS_CF,
NULL, HFILL }
},
{ &hf_tn3270_sdw,
{ "Default character slot width",
"tn3270.cs_sdw",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdh,
{ "Default character slot height",
"tn3270.cs_sdh",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_form,
{ "Form Types",
"tn3270.form",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_formres,
{ "Form Types (Reserved)",
"tn3270.formres",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cs_form_type1,
{ "18-byte form; the first 2 bytes contain a 16-bit vertical slice,"
" the following 16 bytes contain 8-bit horizontal slices. For a 9"
" x 12 character matrix the last 4 bytes contain binary zero.",
"tn3270.cs_form_type1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_tn3270_cs_form_type2,
{ "18-byte form; the first 2 bytes contain a 16-bit vertical slice,"
" the following 16 bytes contain 8-bit horizontal slices. For a 9"
" x 12 character matrix the last 4 bytes contain binary zero. (COMPRESSED)",
"tn3270.cs_form_type2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_tn3270_cs_form_type3,
{ "Row loading (from top to bottom)",
"tn3270.cs_form_type3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_tn3270_cs_form_type4,
{ "Row loading (from top to bottom) (Compressed)",
"tn3270.cs_form_type4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_tn3270_cs_form_type5,
{ "Column loading (from left to right)",
"tn3270.cs_form_type5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_tn3270_cs_form_type6,
{ "Column loading (from left to right) (Compressed)",
"tn3270.cs_form_type6",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_tn3270_cs_form_type8,
{ "Vector",
"tn3270.cs_form_type8",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_tn3270_cs_dl,
{ "Length of each descriptor",
"tn3270.cs_dl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cs_descriptor_set,
{ "Device Specific Character Set ID (PS store No.)",
"tn3270.cs_descriptor_set",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cs_descriptor_flags,
{ "Flags",
"tn3270.cs_descriptor_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_cs_ds_load,
{ "Loadable character set",
"tn3270.cs_ds_load",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_tn3270_cs_ds_triple,
{ "Triple-plane character set",
"tn3270.cs_ds_triple",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_tn3270_cs_ds_char,
{ "Double-Byte coded character set",
"tn3270.cs_ds_char",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_tn3270_cs_ds_cb,
{ "No LCID compare",
"tn3270.cs_ds_cb",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_tn3270_lcid,
{ "Local character set ID (alias)",
"tn3270.lcid",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sw,
{ "Width of the character slots in this characterset.",
"tn3270.sw",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sh,
{ "Height of the character slots in this character set.",
"tn3270.sh",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ssubsn,
{ "Starting subsection.",
"tn3270.ssubsn",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_esubsn,
{ "Ending subsection.",
"tn3270.esubsn",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ccsgid,
{ "Coded Graphic Character Set Identifier.",
"tn3270.ccsgid",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ccsid,
{ "Coded Character Set Identifier.",
"tn3270.ccsid",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_color_flags,
{ "Flags",
"tn3270.color_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_c_prtblk,
{ "Printer only - black ribbon is loaded",
"tn3270.cc_prtblk",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_tn3270_c_np,
{ "Length of color attribute list",
"tn3270.np",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_c_cav,
{ "Color attribute value accepted by the device",
"tn3270.c_cav",
FT_UINT8, BASE_HEX, VALS(vals_at_color_identifications), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_c_ci,
{ "Color identifier",
"tn3270.c_ci",
FT_UINT8, BASE_HEX, VALS(vals_at_color_identifications), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_db_cavdef,
{ "Default color attribute value",
"tn3270.db_cavdef",
FT_UINT8, BASE_HEX, VALS(vals_at_color_identifications), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_db_cidef,
{ "Default background color identifier",
"tn3270.db_cidef",
FT_UINT8, BASE_HEX, VALS(vals_at_color_identifications), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_limin,
{ "Maximum CPR bytes/transmission allowed inbound",
"tn3270.limin",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_limout,
{ "Maximum CPR bytes/transmission allowed outbound",
"tn3270.limout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_featl,
{ "Length (in bytes) of feature information that follows",
"tn3270.featl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_feats,
{ "CPR length and feature flags",
"tn3270.feats",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_dc_dir,
{ "Indicates which direction can use the Data Chain structured field.",
"tn3270.dc_dir",
FT_UINT8, BASE_HEX, VALS(vals_data_chaining_dir), 0xC0,
NULL, HFILL }
},
{ &hf_tn3270_ds_default_sfid,
{ "Default Data Stream",
"tn3270.ds_default_sfid",
FT_UINT8, BASE_HEX, VALS(vals_data_streams), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ds_sfid,
{ "Supported Data Stream",
"tn3270.ds_sfid",
FT_UINT8, BASE_HEX, VALS(vals_data_streams), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_asia_sdp_sosi_soset,
{ "Set ID of the Shift Out (SO) character set",
"tn3270.asia_sdp_sosi_soset",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_asia_sdp_ic_func,
{ "SO/SI Creation supported",
"tn3270.asia_sdp_ic_func",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_tn3270_ddm_flags,
{ "Flags (Reserved)",
"tn3270.ddm_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ddm_limin,
{ "Maximum DDM bytes/transmission allowed inbound",
"tn3270.ddm_limin",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ddm_limout,
{ "Maximum DDM bytes/transmission allowed outbound",
"tn3270.ddm_limout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ddm_nss,
{ "Number of subsets supported",
"tn3270.ddm_nss",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ddm_ddmss,
{ "DDM subset identifier",
"tn3270.ddm_ddmss",
FT_UINT8, BASE_HEX, VALS(vals_qr_ddm), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_dia_flags,
{ "Flags (Reserved)",
"tn3270.dia_flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_dia_limin,
{ "Maximum DIA bytes/transmission allowed inbound",
"tn3270.dia_limin",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_dia_limout,
{ "Maximum DIA bytes/transmission allowed outbound",
"tn3270.dia_limout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_dia_nfs,
{ "Number of subsets supported",
"tn3270.dia_nfs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_dia_diafs,
{ "DIA function set identifier",
"tn3270.dia_diafs",
FT_UINT8, BASE_HEX, VALS(vals_qr_dia), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_dia_diafn,
{ "DIA function set number",
"tn3270.dia_diafn",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fo_flags,
{ "Flags",
"tn3270.fo_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fo_vpos,
{ "Location of vertical line",
"tn3270.fo_vpos",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fo_hpos,
{ "Location of overline/underline",
"tn3270.fo_hpos",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fo_hpos0,
{ "Location of overline in case of separation",
"tn3270.fo_hpos0",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fo_hpos1,
{ "Location of underline in case of separation",
"tn3270.fo_hpos1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fsad_flags,
{ "Flags",
"tn3270.fsad_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fsad_limin,
{ "Reserved for LIMIN parameter. Must be set to zeros.",
"tn3270.fsad_limin",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fsad_limout,
{ "Maximum bytes of format storage data per transmission allowed outbound.",
"tn3270.fsad_limout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_fsad_size,
{ "Size of the format storage space",
"tn3270.fsad_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_h_np,
{ "Number of attribute-value/action pairs",
"tn3270.h_np",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_h_vi,
{ "Data stream attribute value accepted",
"tn3270.h_vi",
FT_UINT8, BASE_HEX, VALS(vals_at_extended_highlighting), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_h_ai,
{ "Data stream action",
"tn3270.h_ai",
FT_UINT8, BASE_HEX, VALS(vals_at_extended_highlighting), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ibm_flags,
{ "Flags",
"tn3270.ibm_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ibm_limin,
{ "Inbound message size limit",
"tn3270.ibm_limin",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ibm_limout,
{ "Outbound message size limit",
"tn3270.ibm_limout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ibm_type,
{ "Type of IBM Auxiliary Device",
"tn3270.ibm_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ip_flags,
{ "Flags (Reserved)",
"tn3270.ip_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ipdd_wd,
{ "Width of the Implicit Partition default screen size (in character cells)",
"tn3270.ipdd_wd",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ipdd_hd,
{ "Height of the Implicit Partition default screen size",
"tn3270.ipdd_hd",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ipdd_wa,
{ "Width of the Implicit Partition alternate screen size",
"tn3270.ipdd_wa",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ipdd_ha,
{ "Height of the Implicit Partition alternate screen size",
"tn3270.ipdd_ha",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ippd_dpbs,
{ "Default printer buffer size (in character cells)",
"tn3270.ippd_dpbs",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ippd_apbs,
{ "Default printer buffer size (in character cells)",
"tn3270.ippd_apbs",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ipccd_wcd,
{ "Width of the character cell for the Implicit Partition default screen size",
"tn3270.ipccd_wcd",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ipccd_hcd,
{ "Height of the character cell for the Implicit Partition default screen size",
"tn3270.ipccd_hcd",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ipccd_wca,
{ "Width of the character cell for the Implicit Partition alternate screen size",
"tn3270.ipccd_wca",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ipccd_hca,
{ "Height of the character cell for the Implicit Partition alternate screen size",
"tn3270.ipccd_hca",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ioca_limin,
{ "Max IOCA bytes/inbound transmission",
"tn3270.ioca_limin",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ioca_limout,
{ "Max IOCA bytes/outbound transmission",
"tn3270.ioca_limout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ioca_type,
{ "Type of IOCA Auxiliary Device",
"tn3270.ioca_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_msr_nd,
{ "Number of MSR device types",
"tn3270.msr_nd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_oem_dsref,
{ "Data stream reference identifier",
"tn3270.oem_dsref",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_oem_dtype,
{ "Device type",
"tn3270.oem_dtype",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_oem_uname,
{ "User assigned name",
"tn3270.oem_uname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sdp_daid,
{ "Destination/Origin ID",
"tn3270.oem_sdp_daid_doid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_oem_sdp_ll_limin,
{ "Maximum OEM dsf bytes/transmission allowed inbound",
"tn3270.oem_sdp_ll_limin",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_oem_sdp_ll_limout,
{ "Maximum OEM dsf bytes/transmission allowed outbound",
"tn3270.oem_sdp_ll_limout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_oem_sdp_pclk_vers,
{ "Protocol version",
"tn3270.oem_sdp_pclk_vers",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_pft_flags,
{ "Flags",
"tn3270.pft_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_pft_tmo,
{ "Top margin offset in 1/1440ths of an inch",
"tn3270.pft_tmo",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_pft_bmo,
{ "Bottom margin offset in 1/1440ths of an inch",
"tn3270.pft_bmo",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_pc_vo_thickness,
{ "Thickness",
"tn3270.pc_vo_thickness",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_pdds_refid,
{ "Reference identifier",
"tn3270.pdds_refid",
FT_UINT8, BASE_HEX, VALS(vals_qr_pdds_refid), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_pdds_ssid,
{ "Subset identifier",
"tn3270.pdds_ssid",
FT_UINT8, BASE_HEX, VALS(vals_qr_pdds_ssid), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_rpq_device,
{ "Device type identifier",
"tn3270.rpq_device",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_rpq_mid,
{ "Model type identifier",
"tn3270.rpq_mid",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_rpq_rpql,
{ "Length of RPQ name (including this byte)",
"tn3270.rpq_rpql",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_rpq_name,
{ "RPQ name",
"tn3270.rpq_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_srf_fpcbl,
{ "Format parameter control block length",
"tn3270.srf_fpcbl",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_spc_epc_flags,
{ "Flags",
"tn3270.spc_epc_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sp_spid,
{ "Storage pool identity",
"tn3270.sp_spid",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sp_size,
{ "Size of this storage pool when empty",
"tn3270.sp_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sp_space,
{ "Space available in this storage pool",
"tn3270.sp_space",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sp_objlist,
{ "Identifiers of objects housed in this storage pool",
"tn3270.sp_objlist",
FT_UINT16, BASE_HEX, VALS(vals_sp_objlist), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tp_nt,
{ "Maximum number of text partitions",
"tn3270.tp_nt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tp_m,
{ "Maximum partition size",
"tn3270.tp_m",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tp_flags,
{ "Flags",
"tn3270.tp_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tp_ntt,
{ "Number of text types supported",
"tn3270.tp_ntt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tp_tlist,
{ "List of types supported",
"tn3270.tp_tlist",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_t_np,
{ "Number of pairs",
"tn3270.t_np",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_t_vi,
{ "Data stream attribute value accepted",
"tn3270.t_vi",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_t_ai,
{ "Associated action value",
"tn3270.t_ai",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_usable_area_flags1,
{"Usable Area Flags",
"tn3270.query_reply_usable_area_flags1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{ &hf_tn3270_ua_reserved1,
{ "Reserved",
"tn3270.reserved",
FT_BOOLEAN, 8, NULL, QR_UA_RESERVED1,
NULL, HFILL }
},
{ &hf_tn3270_ua_page_printer,
{ "Page Printer",
"tn3270.ua_page_printer",
FT_BOOLEAN, 8, NULL, QR_UA_PAGE_PRINTER,
NULL, HFILL }
},
{ &hf_tn3270_ua_reserved2,
{ "Reserved",
"tn3270.reserved",
FT_BOOLEAN, 8, NULL, QR_UA_RESERVED2,
NULL, HFILL }
},
{ &hf_tn3270_ua_hard_copy,
{ "Hard Copy",
"tn3270.ua_hard_copy",
FT_BOOLEAN, 8, NULL, QR_UA_HARD_COPY,
NULL, HFILL }
},
{ &hf_tn3270_ua_addressing,
{ "Usable Area Addressing",
"tn3270.ua_addressing",
FT_UINT8, BASE_HEX, VALS(vals_usable_area_addr_mode), QR_UA_ADDR_MODE_MASK,
NULL, HFILL}
},
{ &hf_tn3270_usable_area_flags2,
{ "Usable Area Flags",
"tn3270.query_reply_usable_area_flags2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_tn3270_ua_variable_cells,
{ "Variable Cells",
"tn3270.ua_variable_cells",
FT_BOOLEAN, 8, TFS(&tn3270_tfs_ua_variable_cells), QR_UA_VARIABLE_CELLS,
NULL, HFILL }
},
{ &hf_tn3270_ua_characters,
{ "Characters",
"tn3270.ua_characters",
FT_BOOLEAN, 8, TFS(&tn3270_tfs_ua_characters), QR_UA_CHARACTERS,
NULL, HFILL }
},
{ &hf_tn3270_ua_cell_units,
{ "Cell Units",
"tn3270.ua_cell_units",
FT_BOOLEAN, 8, TFS(&tn3270_tfs_ua_cell_units), QR_UA_CELL_UNITS,
NULL, HFILL }
},
{ &hf_tn3270_ua_width_cells_pels,
{ "Width of usable area in cells/pels",
"tn3270.ua_width_cells_pels",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_height_cells_pels,
{ "Height of usable area in cells/pels",
"tn3270.ua_height_cells_pels",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_uom_cells_pels,
{ "Units of measure for cells/pels",
"tn3270.ua_uom_cells_pels",
FT_UINT8, BASE_HEX, VALS(vals_usable_area_uom), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_xr,
{ "Distance between points in X direction as a fraction, measured in UNITS, with 2-byte"
" numerator and 2-byte denominator",
"tn3270.ua_xr",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_yr,
{ "Distance between points in Y direction as a fraction, measured in UNITS, with 2-byte"
" numerator and 2-byte denominator",
"tn3270.ua_xr",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_aw,
{ "Number of X units in default cell",
"tn3270.ua_aw",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_ah,
{ "Number of Y units in default cell",
"tn3270.ua_ah",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_buffsz,
{ "Character buffer size (bytes)",
"tn3270.ua_buffsz",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_xmin,
{ "Minimum number of X units in variable cell",
"tn3270.ua_xmin",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_ymin,
{ "Minimum number of Y units in variable cell",
"tn3270.ua_ymin",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_xmax,
{ "Maximum number of X units in variable cell",
"tn3270.ua_xmax",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_ua_ymax,
{ "Maximum number of Y units in variable cell",
"tn3270.ua_ymax",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_3270_tranlim,
{ "Maximum transmission size allowed outbound",
"tn3270.3270_tranlim",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_field_data,
{ "Field Data",
"tn3270.field_data",
FT_STRING, BASE_NONE, NULL, 0x0,
"tn3270.field_data", HFILL }
},
{ &hf_tn3270_number_of_attributes,
{ "Number of Attributes",
"tn3270.number_of_attributes",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_resbyte,
{ "Flags (Reserved)",
"tn3270.resbyte",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_resbytes,
{ "Flags (Reserved)",
"tn3270.resbytes",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_res_twobytes,
{ "Flags (Reserved)",
"tn3270.res_twobytes",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sf_single_byte_id,
{ "Structured Field",
"tn3270.sf_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sf_double_byte_id,
{ "Structured Field",
"tn3270.sf_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_sf_query_reply,
{ "Query Reply",
"tn3270.sf_query_reply",
FT_UINT8, BASE_HEX, VALS(vals_sf_query_replies), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_null,
{ "Trailing Null (Possible Mainframe/Emulator Bug)",
"tn3270.null",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_unknown_data,
{ "Unknown Data (Possible Mainframe/Emulator Bug)",
"tn3270.unknown_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tn3270e_data_type,
{ "TN3270E Data Type",
"tn3270.tn3270e_data_type",
FT_UINT8, BASE_HEX, VALS(vals_tn3270_header_data_types), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tn3270e_request_flag,
{ "TN3270E Request Flag",
"tn3270.tn3270e_request_flag",
FT_UINT8, BASE_HEX, VALS(vals_tn3270_header_request_flags), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tn3270e_response_flag_3270_SCS,
{ "TN3270E Response Flag",
"tn3270.tn3270e_response_flag",
FT_UINT8, BASE_HEX, VALS(vals_tn3270_header_response_flags_3270_SCS), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tn3270e_response_flag_response,
{ "TN3270E Response Flag",
"tn3270.tn3270e_response_flag",
FT_UINT8, BASE_HEX, VALS(vals_tn3270_header_response_flags_response), 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tn3270e_response_flag_unused,
{ "TN3270E Response Flag",
"tn3270.tn3270e_response_flag",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tn3270e_seq_number,
{ "TN3270E Seq Number",
"tn3270.tn3270e_seq_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tn3270_tn3270e_header_data,
{ "TN3270E Header Data",
"tn3270.tn3270e_header_data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_tn3270,
&ett_tn3270e_hdr,
&ett_sf,
&ett_tn3270_field_attribute,
&ett_tn3270_field_validation,
&ett_tn3270_usable_area_flags1,
&ett_tn3270_usable_area_flags2,
&ett_tn3270_query_reply_alphanumeric_flags,
&ett_tn3270_character_sets_flags1,
&ett_tn3270_character_sets_flags2,
&ett_tn3270_character_sets_form,
&ett_tn3270_cs_descriptor_flags,
&ett_tn3270_color_flags,
&ett_tn3270_wcc,
&ett_tn3270_ccc,
&ett_tn3270_msr_state_mask,
&ett_tn3270_data_chain_fields,
&ett_tn3270_query_list
};
proto_tn3270 = proto_register_protocol("TN3270 Protocol", "TN3270", "tn3270");
register_dissector("tn3270", dissect_tn3270, proto_tn3270);
proto_register_field_array(proto_tn3270, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
