static gint
tn5250_is_valid_aid(gint aid)
{
switch (aid) {
case AID_CLEAR:
case AID_ENTER_OR_RECORD_ADV:
case AID_HELP:
case AID_ROLL_DOWN:
case AID_ROLL_UP:
case AID_ROLL_LEFT:
case AID_ROLL_RIGHT:
case AID_PRINT:
case AID_RECORD_BACKSPACE:
case AID_SLP_AUTO_ENTER:
case AID_FORWARD_EDGE_TRIGGER_AUTO__ENTER:
case AID_PA1:
case AID_PA2:
case AID_PA3:
case AID_CMD_01:
case AID_CMD_02:
case AID_CMD_03:
case AID_CMD_04:
case AID_CMD_05:
case AID_CMD_06:
case AID_CMD_07:
case AID_CMD_08:
case AID_CMD_09:
case AID_CMD_10:
case AID_CMD_11:
case AID_CMD_12:
case AID_CMD_13:
case AID_CMD_14:
case AID_CMD_15:
case AID_CMD_16:
case AID_CMD_17:
case AID_CMD_18:
case AID_CMD_19:
case AID_CMD_20:
case AID_CMD_21:
case AID_CMD_22:
case AID_CMD_23:
case AID_CMD_24:
case AID_INBOUND_WRITE_STRUCTURED_FIELD:
case AID_PASS_THROUGH_RESPONSE:
return 1;
default:
break;
}
return 0;
}
static guint32
tn5250_add_hf_items(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset,
const hf_items *fields)
{
int start=offset, byte;
int i;
for (i = 0; fields[i].phf; ++i) {
if (fields[i].bitmask == 0) {
byte = tvb_get_guint8(tvb,offset);
if (byte == 0xFF) {
offset++;
}
proto_tree_add_item(tn5250_tree, *fields[i].phf, tvb, offset,
fields[i].length, fields[i].encoding);
} else {
proto_tree_add_bitmask(tn5250_tree, tvb, offset, *fields[i].phf,
fields[i].bitmask_ett, fields[i].bitmask, ENC_BIG_ENDIAN);
}
DISSECTOR_ASSERT(fields[i].length > 0);
offset+=fields[i].length;
}
return (offset - start);
}
static guint32
dissect_unknown_data(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset,
gint start, gint sf_length)
{
int len_left;
len_left = sf_length - (offset - start);
if (len_left > 0) {
proto_tree_add_item(tn5250_tree, hf_tn5250_unknown_data, tvb, offset,
len_left, ENC_NA);
return len_left;
}
return 0;
}
static guint32
dissect_wcc(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
static const int *wcc_byte[] = {
&hf_tn5250_wtd_ccc2_res,
&hf_tn5250_wtd_ccc2_cursor,
&hf_tn5250_wtd_ccc2_reset,
&hf_tn5250_wtd_ccc2_set,
&hf_tn5250_wtd_ccc2_unlock,
&hf_tn5250_wtd_ccc2_alarm,
&hf_tn5250_wtd_ccc2_off,
&hf_tn5250_wtd_ccc2_on,
NULL
};
hf_items wcc_fields[] = {
{ &hf_tn5250_wtd_ccc1, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wtd_ccc2, ett_tn5250_wcc, 1, wcc_byte, 0 },
{ NULL, 0, 0, 0, 0 }
};
tn5250_add_hf_items(tn5250_tree, tvb, offset, wcc_fields);
return 2;
}
static guint32
dissect_row_column(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
proto_tree_add_item(tn5250_tree, hf_tn5250_buffer_x, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tn5250_tree, hf_tn5250_buffer_y, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return (offset - start);
}
static guint32
dissect_erase_to_address(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int i, length = 0;
dissect_row_column(tn5250_tree, tvb, offset);
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn5250_tree, hf_tn5250_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i=1; i < length; i++) {
proto_tree_add_item(tn5250_tree, hf_tn5250_attribute_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
}
return (offset - start);
}
static guint32
dissect_start_of_header(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
static const int *byte[] = {
&hf_tn5250_soh_cursor_direction,
&hf_tn5250_soh_screen_reverse,
&hf_tn5250_soh_input_capable_only,
NULL
};
static const int *byte1[] = {
&hf_tn5250_soh_pf24, &hf_tn5250_soh_pf23, &hf_tn5250_soh_pf22,
&hf_tn5250_soh_pf21, &hf_tn5250_soh_pf20, &hf_tn5250_soh_pf19,
&hf_tn5250_soh_pf18, &hf_tn5250_soh_pf17,
NULL
};
static const int *byte2[] = {
&hf_tn5250_soh_pf16, &hf_tn5250_soh_pf15, &hf_tn5250_soh_pf14,
&hf_tn5250_soh_pf13, &hf_tn5250_soh_pf12, &hf_tn5250_soh_pf11,
&hf_tn5250_soh_pf10, &hf_tn5250_soh_pf9,
NULL
};
static const int *byte3[] = {
&hf_tn5250_soh_pf8, &hf_tn5250_soh_pf7, &hf_tn5250_soh_pf6,
&hf_tn5250_soh_pf5, &hf_tn5250_soh_pf4, &hf_tn5250_soh_pf3,
&hf_tn5250_soh_pf2, &hf_tn5250_soh_pf1,
NULL
};
hf_items start_of_header_fields[] = {
{ &hf_tn5250_soh_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_soh_flags, ett_tn5250_soh_mask, 1, byte, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_soh_resq, 1, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_soh_err, 1, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_soh_pf24to17, ett_tn5250_soh_pf24to17_mask, 1, byte1, 0 },
{ &hf_tn5250_soh_pf16to9, ett_tn5250_soh_pf16to9_mask, 1, byte2, 0 },
{ &hf_tn5250_soh_pf8to1, ett_tn5250_soh_pf8to1_mask, 1, byte3, 0 },
{ NULL, 0, 0, 0, 0 }
};
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
start_of_header_fields);
return (offset - start);
}
static guint32
dissect_twobyte_length_and_data(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int length = 0;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tn5250_tree, hf_tn5250_length_twobyte, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset+=2;
if (tvb_reported_length_remaining(tvb, offset) >= length) {
proto_tree_add_item(tn5250_tree, hf_tn5250_field_data, tvb, offset,
length, ENC_EBCDIC|ENC_NA);
offset+=length;
} else {
offset += dissect_unknown_data(tn5250_tree, tvb, offset, start, length);
}
return (offset - start);
}
static guint32
dissect_field_attribute_pair(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int attribute_type;
static const int *byte[] = {
&hf_tn5250_wea_prim_attr_flag, &hf_tn5250_wea_prim_attr_col,
&hf_tn5250_wea_prim_attr_blink, &hf_tn5250_wea_prim_attr_und,
&hf_tn5250_wea_prim_attr_int, &hf_tn5250_wea_prim_attr_rev,
NULL
};
attribute_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tn5250_tree, hf_tn5250_attribute_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
switch (attribute_type) {
case EXTENDED_PRIMARY_ATTRIBUTES:
proto_tree_add_bitmask(tn5250_tree, tvb, offset, hf_tn5250_wea_prim_attr,
ett_tn5250_wea_prim_attr, byte, ENC_BIG_ENDIAN);
offset++;
break;
case EXTENDED_FOREGROUND_COLOR_ATTRIBUTES:
proto_tree_add_item(tn5250_tree, hf_tn5250_foreground_color_attr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case EXTENDED_IDEOGRAPHIC_ATTRIBUTES:
proto_tree_add_item(tn5250_tree, hf_tn5250_ideographic_attr, tvb, offset,
1, ENC_BIG_ENDIAN);
offset++;
break;
default:
break;
}
return (offset - start);
}
static guint32
dissect_start_of_field(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int done = 0;
int ffw = 0, fcw = 0, fa = 0;
static const int *byte[] = {
&hf_tn5250_ffw_id,
&hf_tn5250_ffw_bypass,
&hf_tn5250_ffw_dup,
&hf_tn5250_ffw_mdt,
&hf_tn5250_ffw_shift,
NULL
};
static const int *byte1[] = {
&hf_tn5250_ffw_auto,
&hf_tn5250_ffw_fer,
&hf_tn5250_ffw_monocase,
&hf_tn5250_ffw_res,
&hf_tn5250_ffw_me,
&hf_tn5250_ffw_adjust,
NULL
};
static const int *fabyte[] = {
&hf_tn5250_sf_attr_flag, &hf_tn5250_wea_prim_attr_col,
&hf_tn5250_wea_prim_attr_blink, &hf_tn5250_wea_prim_attr_und,
&hf_tn5250_wea_prim_attr_int, &hf_tn5250_wea_prim_attr_rev,
NULL
};
hf_items outbound_text_header_fields[] = {
{ &hf_tn5250_ffw, ett_tn5250_soh_mask, 1, byte, 0 },
{ &hf_tn5250_ffw, ett_tn5250_soh_mask, 1, byte1, 0 },
{ NULL, 0, 0, 0, 0 }
};
ffw = tvb_get_guint8(tvb, offset);
if (ffw & FFW_ID) {
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
outbound_text_header_fields);
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
fcw = tvb_get_guint8(tvb, offset);
switch (fcw) {
case SELECTOR:
case IDEOGRAPHIC:
case FORWARD_EDGE:
case CONTINUED_ENTRY:
case SELF_CHECK:
case ENTRY_FIELD_RESEQUENCING:
case CURSOR_PROGRESSION_ENTRY_FIELD:
case HIGHLIGHTED_ENTRY_FIELD:
case POINTER_DEVICE_SELECTION_ENTRY_FIELD:
case TRANSPARENCY_ENTRY_FIELD:
proto_tree_add_item(tn5250_tree, hf_tn5250_fcw, tvb, offset,
2, ENC_BIG_ENDIAN);
offset+=2;
break;
default:
done = 1;
break;
}
}
}
fa = tvb_get_guint8(tvb, offset);
if (fa & FA_ID) {
proto_tree_add_bitmask(tn5250_tree, tvb, offset, hf_tn5250_fa,
ett_tn5250_wea_prim_attr, fabyte, ENC_BIG_ENDIAN);
offset++;
} else {
proto_tree_add_item(tn5250_tree, hf_tn5250_fa_color, tvb, offset,
1, ENC_BIG_ENDIAN);
offset++;
}
proto_tree_add_item(tn5250_tree, hf_tn5250_length_twobyte, tvb, offset,
2, ENC_BIG_ENDIAN);
offset+=2;
return (offset - start);
}
static guint32
dissect_create_window(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int length = 0;
int done = 0, minor_structure = 0;
static const int *byte[] = {
&hf_tn5250_wdsf_cw_flag1_1,
&hf_tn5250_wdsf_cw_flag1_2,
&hf_tn5250_wdsf_cw_flag1_reserved,
NULL
};
hf_items cw_fields[] = {
{ &hf_tn5250_wdsf_cw_flag1, ett_tn5250_wdsf_cw_mask, 1, byte, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cw_wd, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cw_ww, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *cw_bp_flag1[] = {
&hf_tn5250_wdsf_cw_bp_flag1_1,
&hf_tn5250_wdsf_cw_bp_flag1_reserved,
NULL
};
hf_items cwbp_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cw_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cw_bp_flag1, ett_tn5250_wdsf_cw_bp_mask, 1, cw_bp_flag1, 0 },
{ &hf_tn5250_wdsf_cw_bp_mba, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cw_bp_cba, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cw_bp_ulbc, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_cw_bp_tbc, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_cw_bp_urbc, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_cw_bp_lbc, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_cw_bp_rbc, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_cw_bp_llbc, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_cw_bp_bbc, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_cw_bp_lrbc, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ NULL, 0, 0, 0, 0 }
};
static const int *cw_tf_flag1[] = {
&hf_tn5250_wdsf_cw_tf_flag_orientation,
&hf_tn5250_wdsf_cw_tf_flag_1,
&hf_tn5250_wdsf_cw_tf_flag_reserved,
NULL
};
hf_items cw_tf_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cw_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cw_tf_flag, ett_tn5250_wdsf_cw_tf_mask, 1, cw_tf_flag1, 0 },
{ &hf_tn5250_wdsf_cw_tf_mba, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cw_tf_cba, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, cw_fields);
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
minor_structure = tvb_get_guint8(tvb, offset+1);
switch (minor_structure) {
case CW_BORDER_PRESENTATION:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, cwbp_fields);
case CW_TITLE_FOOTER:
length = tvb_get_guint8(tvb,offset);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, cw_tf_fields);
proto_tree_add_item(tn5250_tree, hf_tn5250_wdsf_cw_tf_text, tvb, offset,
(length - 6), ENC_EBCDIC|ENC_NA);
offset += (guint32)((length - 6));
default:
done = 1;
break;
}
}
return (offset - start);
}
static guint32
dissect_define_selection(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int length = 0;
int done = 0, minor_structure = 0, digit_selection = 0;
static const int *ds_flag1[] = {
&hf_tn5250_wdsf_ds_flag1_mouse_characteristics, &hf_tn5250_wdsf_ds_flag1_reserved,
&hf_tn5250_wdsf_ds_flag1_auto_enter, &hf_tn5250_wdsf_ds_flag1_1,
&hf_tn5250_wdsf_ds_flag1_2, NULL
};
static const int *ds_flag2[] = {
&hf_tn5250_wdsf_ds_flag2_1, &hf_tn5250_wdsf_ds_flag2_2,
&hf_tn5250_wdsf_ds_flag2_3, &hf_tn5250_wdsf_ds_flag2_4,
&hf_tn5250_wdsf_ds_flag2_5, &hf_tn5250_wdsf_ds_flag2_6,
&hf_tn5250_wdsf_ds_flag2_reserved,
NULL
};
static const int *ds_flag3[] = {
&hf_tn5250_wdsf_ds_flag3_1, &hf_tn5250_wdsf_ds_flag3_reserved,
NULL
};
static const int *ds_gdc[] = {
&hf_tn5250_wdsf_ds_gdc_indicators, &hf_tn5250_wdsf_ds_gdc_reserved,
&hf_tn5250_wdsf_ds_gdc_selection_techniques,
NULL
};
static const int *ds_nws[] = {
&hf_tn5250_wdsf_ds_nws_indicators, &hf_tn5250_wdsf_ds_nws_reserved,
&hf_tn5250_wdsf_ds_nws_selection_techniques,
NULL
};
hf_items ds_fields[] = {
{ &hf_tn5250_wdsf_ds_flag1, ett_tn5250_wdsf_ds_mask, 1, ds_flag1, 0 },
{ &hf_tn5250_wdsf_ds_flag2, ett_tn5250_wdsf_ds_mask, 1, ds_flag2, 0 },
{ &hf_tn5250_wdsf_ds_flag3, ett_tn5250_wdsf_ds_mask, 1, ds_flag3, 0 },
{ &hf_tn5250_wdsf_ds_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_gdc, ett_tn5250_wdsf_ds_mask, 1, ds_gdc, 0 },
{ &hf_tn5250_wdsf_ds_nws, ett_tn5250_wdsf_ds_mask, 1, ds_nws, 0 },
{ &hf_tn5250_wdsf_ds_nws_wout, ett_tn5250_wdsf_ds_mask, 1, ds_nws, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_textsize, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_rows, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_columns, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_padding, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_numeric_sep, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_country_sel, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_cancel_aid, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_totalrows, 0, 4, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sliderpos, 0, 4, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *ds_ct_flag1[] = {
&hf_tn5250_wdsf_ds_ct_flag1_choice_state, &hf_tn5250_wdsf_ds_ct_flag1_2,
&hf_tn5250_wdsf_ds_ct_flag1_3, &hf_tn5250_wdsf_ds_ct_flag1_4,
&hf_tn5250_wdsf_ds_ct_flag1_5, &hf_tn5250_wdsf_ds_ct_flag1_numeric_selection,
NULL
};
static const int *ds_ct_flag2[] = {
&hf_tn5250_wdsf_ds_ct_flag2_0, &hf_tn5250_wdsf_ds_ct_flag2_1,
&hf_tn5250_wdsf_ds_ct_flag2_2, &hf_tn5250_wdsf_ds_ct_flag2_3,
&hf_tn5250_wdsf_ds_ct_flag2_4, &hf_tn5250_wdsf_ds_ct_flag2_5,
&hf_tn5250_wdsf_ds_ct_flag2_6, &hf_tn5250_wdsf_ds_ct_flag2_7,
NULL
};
static const int *ds_ct_flag3[] = {
&hf_tn5250_wdsf_ds_ct_flag3_0, &hf_tn5250_wdsf_ds_ct_flag3_1,
&hf_tn5250_wdsf_ds_ct_flag3_2, &hf_tn5250_wdsf_ds_ct_flag3_reserved,
NULL
};
hf_items ds_ct_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_ct_flag1, ett_tn5250_wdsf_ds_ct_mask, 1, ds_ct_flag1, 0 },
{ &hf_tn5250_wdsf_ds_ct_flag2, ett_tn5250_wdsf_ds_ct_mask, 1, ds_ct_flag2, 0 },
{ &hf_tn5250_wdsf_ds_ct_flag3, ett_tn5250_wdsf_ds_ct_mask, 1, ds_ct_flag3, 0 },
{ &hf_tn5250_wdsf_ds_ct_mnemonic_offset, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_ct_aid, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_ct_numeric_onebyte, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_ct_numeric_twobyte, 0, 2, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *ds_mbs_flag[] = {
&hf_tn5250_wdsf_ds_mbs_flag_0, &hf_tn5250_wdsf_ds_mbs_flag_1,
&hf_tn5250_wdsf_ds_mbs_flag_reserved,
NULL
};
hf_items ds_mbs_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_mbs_flag, ett_tn5250_wdsf_ds_mbs_mask, 1, ds_mbs_flag, 0 },
{ &hf_tn5250_wdsf_ds_mbs_start_column, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_mbs_end_column, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_mbs_start_column, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_mbs_monochrome_sep, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_mbs_color_sep, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_mbs_sep_char, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ NULL, 0, 0, 0, 0 }
};
static const int *ds_cpda_flag[] = {
&hf_tn5250_wdsf_ds_cpda_flag1_0, &hf_tn5250_wdsf_ds_cpda_flag1_1,
&hf_tn5250_wdsf_ds_cpda_flag1_2, &hf_tn5250_wdsf_ds_cpda_flag1_reserved,
NULL
};
hf_items ds_cpda_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_flag1, ett_tn5250_wdsf_ds_cpda_mask, 1, ds_cpda_flag, 0 },
{ &hf_tn5250_wdsf_ds_cpda_monochrome_sel_avail, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_color_sel_avail, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_monochrome_sel_selected, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_color_sel_selected, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_monochrome_sel_unavail, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_color_sel_unavail, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_monochrome_avail, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_color_avail, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_monochrome_selected, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_color_selected, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_monochrome_unavail, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_color_unavail, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_monochrome_indicator, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_color_indicator, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_monochrome_unavail_indicator, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_cpda_color_unavail_indicator, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *ds_ci_flag[] = {
&hf_tn5250_wdsf_ds_ci_flag1_0, &hf_tn5250_wdsf_ds_ci_flag1_reserved,
NULL
};
hf_items ds_ci_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_ci_flag1, ett_tn5250_wdsf_ds_ci_mask, 1, ds_ci_flag, 0 },
{ &hf_tn5250_wdsf_ds_ci_left_push, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_ci_right_push, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_ci_first_choice, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ NULL, 0, 0, 0, 0 }
};
static const int *ds_sbi_flag[] = {
&hf_tn5250_wdsf_ds_sbi_flag1_0, &hf_tn5250_wdsf_ds_sbi_flag1_reserved,
NULL
};
hf_items ds_sbi_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_flag1, ett_tn5250_wdsf_ds_sbi_mask, 1, ds_sbi_flag, 0 },
{ &hf_tn5250_wdsf_ds_sbi_monochrome_top_highlight, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_color_top_highlight, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_monochrome_top_highlight_shaft, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_color_top_highlight_shaft, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_top_character, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_sbi_bottom_character, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_sbi_empty_character, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_sbi_slider_character, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ NULL, 0, 0, 0, 0 }
};
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, ds_fields);
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
minor_structure = tvb_get_guint8(tvb, offset+1);
switch (minor_structure) {
case DS_CHOICE_TEXT:
length = tvb_get_guint8(tvb, offset);
digit_selection = tvb_get_guint8(tvb, offset+2);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, ds_ct_fields);
if (digit_selection & DS_NUMERIC_SELECTION_SINGLE_DIGIT) {
proto_tree_add_item(tn5250_tree, hf_tn5250_wdsf_ds_ct_numeric_onebyte,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
} else if (digit_selection & DS_NUMERIC_SELECTION_DOUBLE_DIGIT) {
proto_tree_add_item(tn5250_tree, hf_tn5250_wdsf_ds_ct_numeric_twobyte,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
proto_tree_add_item(tn5250_tree, hf_tn5250_wdsf_ds_ct_text, tvb, offset,
(length - (offset - start)), ENC_EBCDIC|ENC_NA);
offset += (guint32)((length - (offset - start)));
break;
case DS_MENU_BAR_SEPARATOR:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, ds_mbs_fields);
break;
case DS_CHOICE_PRESENTATION_DISPLAY:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, ds_cpda_fields);
break;
case DS_CHOICE_INDICATORS:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, ds_ci_fields);
break;
case DS_SCROLLBAR_INDICATORS:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, ds_sbi_fields);
break;
default:
done = 1;
break;
}
}
return (offset - start);
}
static guint32
dissect_define_scrollbar(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int done = 0, minor_structure = 0;
static const int *dsb_byte[] = {
&hf_tn5250_wdsf_dsb_flag1_0, &hf_tn5250_wdsf_dsb_flag1_1,
&hf_tn5250_wdsf_dsb_flag1_reserved, &hf_tn5250_wdsf_dsb_flag1_7,
NULL
};
hf_items dsb_fields[] = {
{ &hf_tn5250_wdsf_dsb_flag1, ett_tn5250_wdsf_dsb_mask, 1, dsb_byte, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_sbi_total_scroll, 0, 4, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_sbi_sliderpos, 0, 4, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_sbi_rowscols, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *ds_sbi_flag[] = {
&hf_tn5250_wdsf_ds_sbi_flag1_0, &hf_tn5250_wdsf_ds_sbi_flag1_reserved,
NULL
};
hf_items ds_sbi_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_flag1, ett_tn5250_wdsf_ds_sbi_mask, 1, ds_sbi_flag, 0 },
{ &hf_tn5250_wdsf_ds_sbi_monochrome_top_highlight, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_color_top_highlight, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_monochrome_top_highlight_shaft, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_color_top_highlight_shaft, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_ds_sbi_top_character, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_sbi_bottom_character, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_sbi_empty_character, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_wdsf_ds_sbi_slider_character, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ NULL, 0, 0, 0, 0 }
};
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, dsb_fields);
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
minor_structure = tvb_get_guint8(tvb, offset+1);
switch (minor_structure) {
case DS_SCROLLBAR_INDICATORS:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, ds_sbi_fields);
break;
default:
done = 1;
break;
}
}
return (offset - start);
}
static guint32
dissect_draw_erase_gridlines(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int done = 0, minor_structure=0;
static const int *deg_byte[] = {
&hf_tn5250_wdsf_deg_flag1_0, &hf_tn5250_wdsf_deg_flag1_reserved,
NULL
};
static const int *deg_byte2[] = {
&hf_tn5250_wdsf_deg_flag2_0, &hf_tn5250_wdsf_deg_flag2_reserved,
NULL
};
hf_items deg_fields[] = {
{ &hf_tn5250_wdsf_deg_partition, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_flag1, ett_tn5250_wdsf_deg_mask, 1, deg_byte, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_flag2, ett_tn5250_wdsf_deg_mask, 1, deg_byte2, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_default_color, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_default_line, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *deg_ms_byte[] = {
&hf_tn5250_wdsf_deg_ms_flag1_0, &hf_tn5250_wdsf_deg_ms_flag1_reserved,
NULL
};
hf_items deg_ms_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_ms_flag1, ett_tn5250_wdsf_deg_ms_mask, 1, deg_ms_byte, 0 },
{ &hf_tn5250_wdsf_deg_ms_start_row, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_ms_start_column, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_ms_horizontal_dimension, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_ms_vertical_dimension, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_ms_default_color, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_ms_line_repeat, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_deg_ms_line_interval, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, deg_fields);
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
minor_structure = tvb_get_guint8(tvb, offset+1);
switch (minor_structure) {
case UPPER_HORIZONTAL_LINE:
case LOWER_HORIZONTAL_LINE:
case LEFT_VERTICAL_LINE:
case RIGHT_VERTICAL_LINE:
case PLAIN_BOX:
case HORIZONTALLY_RULED_BOX:
case VERTICALLY_RULED_BOX:
case HORIZONTALLY_AND_VERTICALLY_RULED_BOX:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, deg_ms_fields);
break;
default:
done = 1;
break;
}
}
return (offset - start);
}
static guint32
dissect_wdsf_structured_field(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int length = 0, type;
int done = 0, ln_left = 0, i = 0;
hf_items standard_fields[] = {
{ &hf_tn5250_sf_length, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sf_class, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sf_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *rgw_byte[] = {
&hf_tn5250_wdsf_rgw_flag1_0,
&hf_tn5250_wdsf_rgw_flag1_1,
&hf_tn5250_wdsf_rgw_reserved,
NULL
};
hf_items rgw_fields[] = {
{ &hf_tn5250_wdsf_rgw_flag1, ett_tn5250_wdsf_rgw_mask, 1, rgw_byte, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *ragc_byte[] = {
&hf_tn5250_wdsf_ragc_flag1_0,
&hf_tn5250_wdsf_ragc_reserved,
NULL
};
hf_items ragc_fields[] = {
{ &hf_tn5250_wdsf_ragc_flag1, ett_tn5250_wdsf_ragc_mask, 1, ragc_byte, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *wdf_byte[] = {
&hf_tn5250_wdsf_wdf_flag1_0,
&hf_tn5250_wdsf_wdf_flag1_reserved,
NULL
};
hf_items wdf_fields[] = {
{ &hf_tn5250_wdsf_wdf_flag1, ett_tn5250_wdsf_wdf_mask, 1, wdf_byte, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *pmb_byte[] = {
&hf_tn5250_wdsf_pmb_flag1_0, &hf_tn5250_wdsf_pmb_flag1_1,
&hf_tn5250_wdsf_pmb_flag1_2, &hf_tn5250_wdsf_pmb_flag1_3,
&hf_tn5250_wdsf_pmb_flag1_reserved,
NULL
};
hf_items pmb_fields[] = {
{ &hf_tn5250_wdsf_pmb_flag1, ett_tn5250_wdsf_pmb_mask, 1, pmb_byte, 0 },
{ &hf_tn5250_wdsf_pmb_first_mouse_event, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_pmb_second_mouse_event, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_aid, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
hf_items cgl_fields[] = {
{ &hf_tn5250_wdsf_cgl_partition, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cgl_start_row, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cgl_start_column, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cgl_rectangle_width, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wdsf_cgl_rectangle_height, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
length = tvb_get_ntohs(tvb,offset);
type = tvb_get_guint8(tvb, offset+3);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, standard_fields);
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
switch (type) {
case CREATE_WINDOW:
offset += dissect_create_window(tn5250_tree, tvb, offset);
break;
case UNRESTRICTED_WINDOW_CURSOR_MOVEMENT:
case REMOVE_GUI_SELECTION_FIELD:
case REMOVE_GUI_SCROLL_BAR_FIELD:
proto_tree_add_item(tn5250_tree, hf_tn5250_reserved, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tn5250_tree, hf_tn5250_reserved, tvb, offset,
1, ENC_BIG_ENDIAN);
offset +=2;
break;
case REMOVE_GUI_WINDOW:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, rgw_fields);
break;
case REMOVE_ALL_GUI_CONSTRUCTS:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, ragc_fields);
break;
case DEFINE_SELECTION_FIELD:
offset += dissect_define_selection(tn5250_tree, tvb, offset);
break;
case DEFINE_SCROLL_BAR_FIELD:
offset += dissect_define_scrollbar(tn5250_tree, tvb, offset);
break;
case WRITE_DATA:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, wdf_fields);
proto_tree_add_item(tn5250_tree, hf_tn5250_field_data, tvb, offset,
(length - 6), ENC_EBCDIC|ENC_NA);
offset += (guint32)((length - 6));
break;
case PROGRAMMABLE_MOUSE_BUTTONS:
proto_tree_add_item(tn5250_tree, hf_tn5250_reserved, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tn5250_tree, hf_tn5250_reserved, tvb, offset,
1, ENC_BIG_ENDIAN);
offset +=2;
ln_left = length - (offset - start);
for (i = 0; i < ln_left; i+=4) {
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, pmb_fields);
}
break;
case DRAW_ERASE_GRID_LINES:
offset += dissect_draw_erase_gridlines(tn5250_tree, tvb, offset);
break;
case CLEAR_GRID_LINE_BUFFER:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, cgl_fields);
break;
default:
done = 1;
break;
}
}
offset += dissect_unknown_data(tn5250_tree, tvb, offset, start, length);
return (offset - start);
}
static guint32
dissect_tn5250_ra_data(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
gint order_code, done = 0;
gint start = offset;
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
order_code = tvb_get_guint8(tvb, offset);
switch (order_code) {
case TN5250_IC:
case TN5250_MC:
case TN5250_SBA:
case TN5250_RA:
case TN5250_EA:
case TN5250_SOH:
case TN5250_TD:
case TN5250_WEA:
case TN5250_SF:
case TN5250_WDSF:
case TN5250_ESCAPE:
done = 1;
break;
default:
offset++;
break;
}
}
if (offset > start) {
proto_tree_add_item(tn5250_tree, hf_tn5250_repeated_character,
tvb, start, (offset - start), ENC_EBCDIC|ENC_NA);
}
return (offset - start);
}
static guint32
dissect_tn5250_orders_and_data(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
gint start = offset, done = 0;
gint order_code;
proto_tree *cc_tree;
proto_item *ti;
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
order_code = tvb_get_guint8(tvb, offset);
switch (order_code) {
case TN5250_IC:
case TN5250_MC:
case TN5250_SBA:
ti = proto_tree_add_item(tn5250_tree, hf_tn5250_order_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
cc_tree = proto_item_add_subtree(ti, ett_cc);
offset += dissect_row_column(cc_tree, tvb, offset);
offset += dissect_tn5250_ra_data(cc_tree, tvb, offset);
break;
case TN5250_RA:
ti = proto_tree_add_item(tn5250_tree, hf_tn5250_order_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
cc_tree = proto_item_add_subtree(ti, ett_cc);
offset += dissect_row_column(cc_tree, tvb, offset);
offset += dissect_tn5250_ra_data(cc_tree, tvb, offset);
break;
case TN5250_EA:
ti = proto_tree_add_item(tn5250_tree, hf_tn5250_order_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
cc_tree = proto_item_add_subtree(ti, ett_cc);
offset += dissect_erase_to_address(cc_tree, tvb, offset);
break;
case TN5250_SOH:
ti = proto_tree_add_item(tn5250_tree, hf_tn5250_order_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
cc_tree = proto_item_add_subtree(ti, ett_cc);
offset += dissect_start_of_header(cc_tree, tvb, offset);
break;
case TN5250_TD:
ti = proto_tree_add_item(tn5250_tree, hf_tn5250_order_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
cc_tree = proto_item_add_subtree(ti, ett_cc);
offset += dissect_twobyte_length_and_data(cc_tree, tvb, offset);
break;
case TN5250_WEA:
ti = proto_tree_add_item(tn5250_tree, hf_tn5250_order_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
cc_tree = proto_item_add_subtree(ti, ett_cc);
offset += dissect_field_attribute_pair(cc_tree, tvb, offset);
break;
case TN5250_SF:
ti = proto_tree_add_item(tn5250_tree, hf_tn5250_order_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
cc_tree = proto_item_add_subtree(ti, ett_cc);
offset += dissect_start_of_field(cc_tree, tvb, offset);
offset += dissect_tn5250_ra_data(cc_tree, tvb, offset);
break;
case TN5250_WDSF:
ti = proto_tree_add_item(tn5250_tree, hf_tn5250_order_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
cc_tree = proto_item_add_subtree(ti, ett_cc);
offset += dissect_wdsf_structured_field(cc_tree, tvb, offset);
break;
default:
done = 1;
break;
}
}
return (offset - start);
}
static guint32
dissect_save_partial_screen(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
int length = 0;
static const int *byte[] = {
&hf_tn5250_sps_flag1_0,
&hf_tn5250_sps_flag1_reserved,
NULL
};
hf_items save_partial_screen_fields[] = {
{ &hf_tn5250_soh_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sps_flag1, ett_tn5250_sps_mask, 1, byte, 0 },
{ &hf_tn5250_sps_top_row, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sps_left_column, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sps_window_depth, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sps_window_width, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
length = tvb_get_guint8(tvb, offset);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
save_partial_screen_fields);
offset += dissect_unknown_data(tn5250_tree, tvb, offset, start, length);
return (offset - start);
}
static guint32
dissect_roll(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
static const int *byte[] = {
&hf_tn5250_roll_flag1_0,
&hf_tn5250_roll_flag1_reserved,
&hf_tn5250_roll_flag1_lines,
NULL
};
hf_items roll_fields[] = {
{ &hf_tn5250_roll_flag1, ett_tn5250_roll_mask, 1, byte, 0 },
{ &hf_tn5250_roll_top_line, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_roll_bottom_line, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, roll_fields);
return (offset - start);
}
static guint32
dissect_write_single_structured_field_minor_fields(proto_tree *tn5250_tree,
tvbuff_t *tvb, gint offset)
{
int start = offset;
int done = 0, type = 0;
static const int *byte_wssf_kbc_flag1[] = {
&hf_tn5250_wssf_kbc_flag1_reserved,
&hf_tn5250_wssf_kbc_flag1_5,
&hf_tn5250_wssf_kbc_flag1_6,
&hf_tn5250_wssf_kbc_flag1_7,
NULL
};
static const int *byte_wssf_cc_flag1[] = {
&hf_tn5250_wssf_cc_flag1_reserved,
&hf_tn5250_wssf_cc_flag1_7,
NULL
};
hf_items wsc_customization_kbc_fields[] = {
{ &hf_tn5250_sf_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_wsc_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_kbc_flag1, ett_tn5250_wssf_kbc_mask, 1, byte_wssf_kbc_flag1, 0 },
{ NULL, 0, 0, 0, 0 }
};
hf_items wsc_customization_cc_fields[] = {
{ &hf_tn5250_sf_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_wsc_minor_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_cc_flag1, ett_tn5250_wssf_cc_mask, 1, byte_wssf_cc_flag1, 0 },
{ NULL, 0, 0, 0, 0 }
};
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
type = tvb_get_guint8(tvb, offset+1);
switch (type) {
case KEYSTROKE_BUFFERING_CONTROL:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
wsc_customization_kbc_fields);
break;
case CURSOR_CONTROL:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
wsc_customization_cc_fields);
break;
default:
done = 1;
break;
}
}
return (offset - start);
}
static guint32
dissect_write_single_structured_field(proto_tree *tn5250_tree, tvbuff_t *tvb,
gint offset)
{
int start = offset;
int length, type, done = 0;
guint32 namelength;
static const int *byte[] = {
&hf_tn5250_wssf_flag2_0,
&hf_tn5250_wssf_flag2_1,
&hf_tn5250_wssf_flag2_2,
&hf_tn5250_wssf_flag2_3,
&hf_tn5250_wssf_flag2_4,
&hf_tn5250_wssf_flag2_5,
&hf_tn5250_wssf_flag2_6,
&hf_tn5250_wssf_flag2_7,
NULL
};
static const int *ifc_byte[] = {
&hf_tn5250_wssf_ifc_flag1_0,
&hf_tn5250_wssf_ifc_flag1_1to3,
&hf_tn5250_wssf_ifc_flag1_4,
&hf_tn5250_wssf_ifc_flag1_5,
&hf_tn5250_wssf_ifc_flag1_6,
&hf_tn5250_wssf_ifc_flag1_7,
NULL
};
static const int *ifc_byte2[] = {
&hf_tn5250_wssf_ifc_flag2_0,
&hf_tn5250_wssf_ifc_flag2_1,
&hf_tn5250_wssf_ifc_flag2_reserved,
&hf_tn5250_wssf_ifc_flag2_7,
NULL
};
static const int *ifd_byte[] = {
&hf_tn5250_wssf_ifd_flag1_0,
&hf_tn5250_wssf_ifd_flag1_reserved,
NULL
};
hf_items standard_fields[] = {
{ &hf_tn5250_sf_length, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sf_class, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sf_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
hf_items wsc_customization_fields[] = {
{ &hf_tn5250_wssf_flag1, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_flag2, ett_tn5250_wssf_mask, 1, byte, 0 },
{ NULL, 0, 0, 0, 0 }
};
hf_items wsc_image_control_fields[] = {
{ &hf_tn5250_wssf_ifc_flag1, ett_tn5250_wssf_ifc_mask, 1, ifc_byte, 0 },
{ &hf_tn5250_wssf_ifc_flag2, ett_tn5250_wssf_ifc_mask, 1, ifc_byte2, 0 },
{ &hf_tn5250_wssf_ifc_image_format, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_viewport_location_row, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_viewport_location_col, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_viewport_size_row, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_viewport_size_col, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_scaling, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_viewimage_location_row, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_viewimage_location_col, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_rotation, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_foreground_color, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wssf_ifc_background_color, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
hf_items wsc_image_download_fields[] = {
{ &hf_tn5250_wssf_ifd_flag1, ett_tn5250_wssf_ifd_mask, 1, ifd_byte, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_length, 0, 2, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
length = tvb_get_ntohs(tvb,offset);
type = tvb_get_guint8(tvb, offset+3);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, standard_fields);
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
switch (type) {
case WSC_CUSTOMIZATION:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
wsc_customization_fields);
offset += dissect_write_single_structured_field_minor_fields(tn5250_tree, tvb, offset);
break;
case IMAGE_FAX_CONTROL:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
wsc_image_control_fields);
proto_tree_add_item(tn5250_tree, hf_tn5250_wssf_ifc_imagefax_name, tvb, offset,
(length - (start + offset)), ENC_EBCDIC|ENC_NA);
if (length > (start + offset))
offset += (guint32)(length - (start + offset));
break;
case IMAGE_FAX_DOWNLOAD:
namelength = tvb_get_ntohs(tvb,offset+6);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
wsc_image_download_fields);
proto_tree_add_item(tn5250_tree, hf_tn5250_wssf_ifd_imagefax_name, tvb, offset,
namelength, ENC_EBCDIC|ENC_NA);
offset += namelength;
proto_tree_add_item(tn5250_tree, hf_tn5250_wssf_ifd_imagefax_data, tvb, offset,
(length - (start + offset)), ENC_NA);
if (length > (start + offset))
offset += (guint32)(length - (start + offset));
break;
case VIDEO_AUDIO_CONTROLS:
proto_tree_add_item(tn5250_tree, hf_tn5250_vac_prefix, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tn5250_tree, hf_tn5250_vac_data, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 2;
break;
case TRUE_TRANSPARENCY_WRITE:
proto_tree_add_item(tn5250_tree, hf_tn5250_wssf_ttw_flag, tvb, offset,
1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(tn5250_tree, hf_tn5250_wssf_ttw_data, tvb, offset,
(length - (start + offset)), ENC_NA);
if (length > (start + offset))
offset += (guint32)(length - (start + offset));
break;
default:
done = 1;
break;
}
}
offset += dissect_unknown_data(tn5250_tree, tvb, offset, start, length);
return (offset - start);
}
static guint32
dissect_write_structured_field(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
guint16 sf_length = 0;
int length, type, done = 0, used = 0;
hf_items standard_fields[] = {
{ &hf_tn5250_sf_length, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sf_class, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sf_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *qss_byte1[] = {
&hf_tn5250_wsf_qss_flag1_0,
&hf_tn5250_wsf_qss_flag1_reserved,
NULL
};
static const int *qss_byte2[] = {
&hf_tn5250_wsf_qss_flag2_reserved,
&hf_tn5250_wsf_qss_flag2_7,
NULL
};
hf_items qss_fields[] = {
{ &hf_tn5250_wsf_qss_flag1, ett_tn5250_wsf_qss_mask, 1, qss_byte1, 0 },
{ &hf_tn5250_wsf_qss_flag2, ett_tn5250_wsf_qss_mask, 1, qss_byte2, 0 },
{ NULL, 0, 0, 0, 0 }
};
hf_items dawt_fields[] = {
{ &hf_tn5250_dawt_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dawt_char, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ NULL, 0, 0, 0, 0 }
};
hf_items dckf_fields[] = {
{ &hf_tn5250_dckf_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dckf_key_code, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dckf_function_code, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *rts_byte1[] = {
&hf_tn5250_rts_flag1_0,
&hf_tn5250_rts_flag1_reserved,
NULL
};
hf_items rts_fields[] = {
{ &hf_tn5250_rts_partition, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_rts_flag1, ett_tn5250_wsf_rts_mask, 1, rts_byte1, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *dpo_byte1[] = {
&hf_tn5250_dpo_flag1_0,
&hf_tn5250_dpo_flag1_1,
&hf_tn5250_dpo_flag1_2,
&hf_tn5250_dpo_flag1_3,
&hf_tn5250_dpo_flag1_4,
&hf_tn5250_dpo_flag1_5,
&hf_tn5250_dpo_flag1_6,
&hf_tn5250_dpo_flag1_7,
NULL
};
static const int *dpo_byte2[] = {
&hf_tn5250_dpo_flag2_0,
&hf_tn5250_dpo_flag2_reserved,
NULL
};
hf_items dpo_fields[] = {
{ &hf_tn5250_dpo_partition, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dpo_flag1, ett_tn5250_wsf_dpo_mask, 1, dpo_byte1, 0 },
{ &hf_tn5250_dpo_flag2, ett_tn5250_wsf_dpo_mask, 1, dpo_byte2, 0 },
{ &hf_tn5250_dpo_displace_characters, 0, 3, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_dpo_start_location_row, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dpo_start_location_col, 0, 2, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *dtsf_byte1[] = {
&hf_tn5250_dtsf_flag1_0,
&hf_tn5250_dtsf_flag1_1,
&hf_tn5250_dtsf_flag1_2,
&hf_tn5250_dtsf_flag1_3,
&hf_tn5250_dtsf_flag1_4,
&hf_tn5250_dtsf_flag1_5,
&hf_tn5250_dtsf_flag1_6,
&hf_tn5250_dtsf_flag1_7,
NULL
};
static const int *dtsf_byte2[] = {
&hf_tn5250_dtsf_flag2_0,
&hf_tn5250_dtsf_flag2_1,
&hf_tn5250_dtsf_flag2_2,
&hf_tn5250_dtsf_flag2_3,
&hf_tn5250_dtsf_flag2_4to7,
NULL
};
hf_items dtsf_fields[] = {
{ &hf_tn5250_dtsf_partition, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dtsf_flag1, ett_tn5250_wsf_dtsf_mask, 1, dtsf_byte1, 0 },
{ &hf_tn5250_dtsf_flag2, ett_tn5250_wsf_dtsf_mask, 1, dtsf_byte2, 0 },
{ &hf_tn5250_dtsf_text_body_height, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dtsf_text_body_width, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dtsf_line_cmd_field_size, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dtsf_location_of_pitch, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dtsf_first_line, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *dsl_byte1[] = {
&hf_tn5250_dsl_flag1_0,
&hf_tn5250_dsl_flag1_1,
&hf_tn5250_dsl_flag1_2,
&hf_tn5250_dsl_flag1_reserved,
NULL
};
hf_items dsl_fields[] = {
{ &hf_tn5250_dsl_partition, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dsl_rtl_offset, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dsl_offset, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
hf_items dsl_fields2[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dsl_flag1, ett_tn5250_wsf_dsl_mask, 1, dsl_byte1, 0 },
{ &hf_tn5250_dsl_id, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dsl_location, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dsl_function, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *wts_byte1[] = {
&hf_tn5250_wts_flag1_0,
&hf_tn5250_wts_flag1_1,
&hf_tn5250_wts_flag1_2,
&hf_tn5250_wts_flag1_3,
&hf_tn5250_wts_flag1_reserved,
NULL
};
static const int *wts_byte2[] = {
&hf_tn5250_wts_flag2_reserved,
&hf_tn5250_wts_flag2_6,
&hf_tn5250_wts_flag2_reserved2,
NULL
};
static const int *wts_byte3[] = {
&hf_tn5250_wts_flag3_0,
&hf_tn5250_wts_flag3_1,
&hf_tn5250_wts_flag3_2,
&hf_tn5250_wts_flag3_3,
&hf_tn5250_wts_flag3_4,
&hf_tn5250_wts_flag3_5,
&hf_tn5250_wts_flag3_6,
&hf_tn5250_wts_flag3_7,
NULL
};
hf_items wts_fields[] = {
{ &hf_tn5250_wts_partition, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wts_flag1, ett_tn5250_wts_mask, 1, wts_byte1, 0 },
{ &hf_tn5250_wts_flag2, ett_tn5250_wts_mask, 1, wts_byte2, 0 },
{ &hf_tn5250_wts_flag3, ett_tn5250_wts_mask, 1, wts_byte3, 0 },
{ &hf_tn5250_wts_home_position_row, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wts_home_position_col, 0, 2, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *wts_cld_byte1[] = {
&hf_tn5250_wts_cld_flag1_0,
&hf_tn5250_wts_cld_flag1_1,
&hf_tn5250_wts_cld_flag1_2,
&hf_tn5250_wts_cld_flag1_3,
&hf_tn5250_wts_cld_flag1_4,
&hf_tn5250_wts_cld_flag1_5,
&hf_tn5250_wts_cld_flag1_6,
&hf_tn5250_wts_cld_flag1_7,
NULL
};
static const int *wts_cld_byte2[] = {
&hf_tn5250_wts_cld_flag2_0,
&hf_tn5250_wts_cld_flag2_1,
&hf_tn5250_wts_cld_flag2_2,
&hf_tn5250_wts_cld_flag2_3,
&hf_tn5250_wts_cld_flag2_4,
&hf_tn5250_wts_cld_flag2_line_spacing,
NULL
};
static const int *wts_cld_byte3[] = {
&hf_tn5250_wts_cld_flag3_0,
&hf_tn5250_wts_cld_flag3_1,
&hf_tn5250_wts_cld_flag3_2,
&hf_tn5250_wts_cld_flag3_3,
&hf_tn5250_wts_cld_flag3_4,
&hf_tn5250_wts_cld_flag3_5,
&hf_tn5250_wts_cld_flag3_6,
&hf_tn5250_wts_cld_flag3_7,
NULL
};
hf_items wts_line_data_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wts_cld_flag1, ett_tn5250_wts_mask, 1, wts_cld_byte1, 0 },
{ &hf_tn5250_wts_cld_flag2, ett_tn5250_wts_mask, 1, wts_cld_byte2, 0 },
{ &hf_tn5250_wts_cld_row, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wts_cld_flag3, ett_tn5250_wts_mask, 1, wts_cld_byte3, 0 },
{ &hf_tn5250_wts_cld_page_num, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wts_cld_lmo, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wts_cld_io, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_wts_cld_sli, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
hf_items dsc_fields[] = {
{ &hf_tn5250_dsc_partition, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dsc_sk, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dsc_ev, 0, 1, 0, ENC_EBCDIC|ENC_NA },
{ NULL, 0, 0, 0, 0 }
};
hf_items dorm_fields[] = {
{ &hf_tn5250_dorm_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dorm_ec, 0, 2, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
static const int *dfdpck_coreflag[] = {
&hf_tn5250_dfdpck_coreflag_0,
&hf_tn5250_dfdpck_coreflag_1,
&hf_tn5250_dfdpck_coreflag_2,
&hf_tn5250_dfdpck_coreflag_3,
&hf_tn5250_dfdpck_coreflag_4,
&hf_tn5250_dfdpck_coreflag_5,
&hf_tn5250_dfdpck_coreflag_6,
&hf_tn5250_dfdpck_coreflag_7,
NULL
};
static const int *dfdpck_toprowflag1[] = {
&hf_tn5250_dfdpck_toprowflag1_0,
&hf_tn5250_dfdpck_toprowflag1_1,
&hf_tn5250_dfdpck_toprowflag1_2,
&hf_tn5250_dfdpck_toprowflag1_3,
&hf_tn5250_dfdpck_toprowflag1_4,
&hf_tn5250_dfdpck_toprowflag1_5,
&hf_tn5250_dfdpck_toprowflag1_6,
&hf_tn5250_dfdpck_toprowflag1_7,
NULL
};
static const int *dfdpck_toprowflag2[] = {
&hf_tn5250_dfdpck_toprowflag2_0,
&hf_tn5250_dfdpck_toprowflag2_1,
&hf_tn5250_dfdpck_toprowflag2_2,
&hf_tn5250_dfdpck_toprowflag2_3,
&hf_tn5250_dfdpck_toprowflag2_4,
&hf_tn5250_dfdpck_toprowflag2_5,
&hf_tn5250_dfdpck_toprowflag2_6,
&hf_tn5250_dfdpck_toprowflag2_7,
NULL
};
static const int *dfdpck_toprowflag3[] = {
&hf_tn5250_dfdpck_toprowflag3_0,
&hf_tn5250_dfdpck_toprowflag3_1,
&hf_tn5250_dfdpck_toprowflag3_2,
&hf_tn5250_dfdpck_toprowflag3_3,
&hf_tn5250_dfdpck_toprowflag3_4,
&hf_tn5250_dfdpck_toprowflag3_5,
&hf_tn5250_dfdpck_toprowflag3_6,
&hf_tn5250_dfdpck_toprowflag3_7,
NULL
};
hf_items dfdpck_fields[] = {
{ &hf_tn5250_dfdpck_partition, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
hf_items dfdpck_core_area_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dfdpck_data_field, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dfdpck_coreflag, ett_tn5250_dfdpck_mask, 1, dfdpck_coreflag, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
hf_items dfdpck_top_row_fields[] = {
{ &hf_tn5250_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dfdpck_data_field, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_dfdpck_toprowflag1, ett_tn5250_dfdpck_mask, 1, dfdpck_toprowflag1, 0 },
{ &hf_tn5250_dfdpck_toprowflag2, ett_tn5250_dfdpck_mask, 1, dfdpck_toprowflag2, 0 },
{ &hf_tn5250_dfdpck_toprowflag3, ett_tn5250_dfdpck_mask, 1, dfdpck_toprowflag3, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
while (tvb_reported_length_remaining(tvb, offset) > 0 && !done) {
sf_length = tvb_get_ntohs(tvb,offset);
type = tvb_get_guint8(tvb, offset+3);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, standard_fields);
switch (type) {
case PASS_THROUGH:
proto_tree_add_item(tn5250_tree, hf_tn5250_field_data, tvb, offset,
(sf_length - (start + offset)), ENC_EBCDIC|ENC_NA);
offset += (guint32)(sf_length - (start + offset));
break;
case TN5250_QUERY:
proto_tree_add_item(tn5250_tree, hf_tn5250_reserved, tvb, offset,
1, ENC_BIG_ENDIAN);
offset ++;
break;
case TN5250_QUERY_STATION_STATE:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, qss_fields);
break;
case DEFINE_AUDIT_WINDOW__TABLE:
proto_tree_add_item(tn5250_tree, hf_tn5250_dawt_id, tvb, offset,
1, ENC_BIG_ENDIAN);
while ((offset - start) < sf_length) {
length = tvb_get_guint8(tvb,offset);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, dawt_fields);
proto_tree_add_item(tn5250_tree, hf_tn5250_dawt_message, tvb, offset,
(length - 2), ENC_EBCDIC|ENC_NA);
offset += length;
}
break;
case DEFINE_COMMAND_KEY_FUNCTION:
proto_tree_add_item(tn5250_tree, hf_tn5250_dckf_id, tvb, offset,
1, ENC_BIG_ENDIAN);
while ((offset - start) < sf_length) {
length = tvb_get_guint8(tvb,offset);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
dckf_fields);
proto_tree_add_item(tn5250_tree, hf_tn5250_dckf_prompt_text, tvb,
offset, (length - 2), ENC_EBCDIC|ENC_NA);
offset += length;
}
break;
case READ_TEXT_SCREEN:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, rts_fields);
break;
case DEFINE_PENDING_OPERATIONS:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, dpo_fields);
break;
case DEFINE_TEXT_SCREEN_FORMAT:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, dtsf_fields);
break;
case DEFINE_SCALE_LINE:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, dsl_fields);
while ((offset - start) < sf_length) {
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, dsl_fields2);
}
break;
case WRITE_TEXT_SCREEN:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
wts_fields);
length = tvb_get_guint8(tvb,offset);
used = tn5250_add_hf_items(tn5250_tree, tvb, offset,
wts_line_data_fields);
offset += used;
proto_tree_add_item(tn5250_tree, hf_tn5250_wts_cld_li, tvb, offset,
(length - used), ENC_EBCDIC|ENC_NA);
break;
case DEFINE_SPECIAL_CHARACTERS:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
dsc_fields);
break;
case DEFINE_OPERATOR_ERROR_MESSAGES:
proto_tree_add_item(tn5250_tree, hf_tn5250_dorm_id, tvb, offset,
1, ENC_BIG_ENDIAN);
while ((offset - start) < sf_length) {
length = tvb_get_guint8(tvb,offset);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
dorm_fields);
proto_tree_add_item(tn5250_tree, hf_tn5250_dorm_mt, tvb, offset,
(length - 2), ENC_EBCDIC|ENC_NA);
offset += length;
}
break;
case DEFINE_PITCH_TABLE:
proto_tree_add_item(tn5250_tree, hf_tn5250_dpt_id, tvb, offset,
1, ENC_BIG_ENDIAN);
while ((offset - start) < sf_length) {
length = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tn5250_tree, hf_tn5250_length, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tn5250_tree, hf_tn5250_dpt_ec, tvb, offset,
length, ENC_EBCDIC|ENC_NA);
offset += length;
}
break;
case DEFINE_FAKE_DP_COMMAND_KEY_FUNCTION:
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
dfdpck_fields);
while ((offset - start) < sf_length) {
length = tvb_get_guint8(tvb,offset);
type = tvb_get_guint8(tvb,offset+1);
if (type == CORE_AREA_COMMAND_KEYS) {
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
dfdpck_core_area_fields);
} else if (type == TOP_ROW_COMMAND_KEYS) {
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset,
dfdpck_top_row_fields);
} else {
offset += dissect_unknown_data(tn5250_tree, tvb, offset, start, length);
}
}
break;
default:
done = 1;
break;
}
}
offset += dissect_unknown_data(tn5250_tree, tvb, offset, start, sf_length);
return (offset - start);
}
static guint32
dissect_query_reply(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start = offset;
static const int *byte[] = {
&hf_tn5250_qr_flag_0,
&hf_tn5250_qr_flag_reserved,
NULL
};
static const int *byte1[] = {
&hf_tn5250_qr_flag1_0,
&hf_tn5250_qr_flag1_1,
&hf_tn5250_qr_flag1_2,
&hf_tn5250_qr_flag1_3,
&hf_tn5250_qr_flag1_4,
&hf_tn5250_qr_flag1_5,
&hf_tn5250_qr_flag1_6,
&hf_tn5250_qr_flag1_7,
NULL
};
static const int *byte2[] = {
&hf_tn5250_qr_flag2_0to3,
&hf_tn5250_qr_flag2_4,
&hf_tn5250_qr_flag2_5,
&hf_tn5250_qr_flag2_6to7,
NULL
};
hf_items qr_fields[] = {
{ &hf_tn5250_sf_length, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sf_class, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sf_type, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_qr_flag, ett_tn5250_qr_mask, 1, byte, 0 },
{ &hf_tn5250_qr_chc, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_qr_ccl, 0, 3, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_qr_dt, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_qr_dtc, 0, 4, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_qr_dm, 0, 3, 0, ENC_EBCDIC|ENC_NA },
{ &hf_tn5250_qr_ki, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_qr_eki, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_qr_dsn, 0, 4, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_qr_mni, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_qr_flag1, ett_tn5250_qr_mask, 1, byte1, 0 },
{ &hf_tn5250_qr_flag2, ett_tn5250_qr_mask, 1, byte2, 0 },
{ &hf_tn5250_qr_flag3, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_qr_flag4, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, qr_fields);
return (offset - start);
}
static guint32
dissect_tn5250_header(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
int start=offset;
int error_flag;
static const int *byte[] = {
&hf_tn5250_ds_output_error,
&hf_tn5250_attn_key,
&hf_tn5250_sys_request_key,
&hf_tn5250_test_request_key,
&hf_tn5250_error_state,
NULL
};
hf_items fields[] = {
{ &hf_tn5250_logical_record_length, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_sna_record_type, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_reserved, 0, 2, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_variable_record_length, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_header_flags, ett_tn5250_header_flags, 1, byte, 0 },
{ &hf_tn5250_reserved, 0, 1, 0, ENC_BIG_ENDIAN },
{ &hf_tn5250_operation_code, 0, 1, 0, ENC_BIG_ENDIAN },
{ NULL, 0, 0, 0, 0 }
};
error_flag = tvb_get_guint8(tvb, offset+8);
offset += tn5250_add_hf_items(tn5250_tree, tvb, offset, fields);
if (error_flag & 0x02) {
proto_tree_add_item(tn5250_tree, hf_tn5250_error_code, tvb, offset, 2, ENC_BIG_ENDIAN);
}
return (offset - start);
}
static guint32
dissect_outbound_stream(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset)
{
gint command_code;
gint start = offset, length = 0;
proto_tree *cc_tree;
proto_item *ti;
ti = proto_tree_add_item(tn5250_tree, hf_tn5250_escape_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
cc_tree = proto_item_add_subtree(ti, ett_cc);
command_code = tvb_get_guint8(tvb, offset);
switch (command_code) {
case CLEAR_UNIT:
case CLEAR_FORMAT_TABLE:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
break;
case CLEAR_UNIT_ALTERNATE:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(cc_tree, hf_tn5250_cua_parm, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case WRITE_TO_DISPLAY:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
offset += dissect_wcc(cc_tree, tvb, offset);
offset += dissect_tn5250_orders_and_data(cc_tree, tvb, offset);
break;
case WRITE_ERROR_CODE:
proto_tree_add_item(cc_tree, hf_tn5250_command_code,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset += dissect_tn5250_orders_and_data(cc_tree, tvb, offset);
proto_tree_add_item(cc_tree, hf_tn5250_fa, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(cc_tree, hf_tn5250_field_data, tvb, offset,
tvb_reported_length_remaining(tvb, offset) - 1,
ENC_EBCDIC|ENC_NA);
offset += (guint32)(tvb_reported_length_remaining(tvb, offset) - 1);
proto_tree_add_item(cc_tree, hf_tn5250_fa, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case RESTORE_SCREEN:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset += dissect_outbound_stream(cc_tree, tvb, offset);
}
break;
case WRITE_ERROR_CODE_TO_WINDOW:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(cc_tree, hf_tn5250_wectw_start_column, tvb, offset,
1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(cc_tree, hf_tn5250_wectw_end_column, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
break;
case READ_INPUT_FIELDS:
case READ_MDT_FIELDS:
case READ_MDT_ALTERNATE:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
offset += dissect_wcc(cc_tree, tvb, offset);
break;
case READ_SCREEN:
case READ_SCREEN_WITH_EXTENDED_ATTRIBUTES:
case READ_SCREEN_TO_PRINT:
case READ_SCREEN_TO_PRINT_WITH_EXTENDED_ATTRIBUTES:
case READ_SCREEN_TO_PRINT_WITH_GRIDLINES:
case READ_SCREEN_TO_PRINT_WITH_EXTENDED_ATTRIBUTES_AND_GRIDLINES:
case READ_IMMEDIATE:
case READ_MODIFIED_IMMEDIATE_ALTERNATE:
case SAVE_SCREEN:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
break;
case SAVE_PARTIAL_SCREEN:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
offset += dissect_save_partial_screen(cc_tree, tvb, offset);
break;
case RESTORE_PARTIAL_SCREEN:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(cc_tree, hf_tn5250_length_twobyte, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset++;
offset += dissect_tn5250_orders_and_data(cc_tree, tvb, offset);
proto_tree_add_item(cc_tree, hf_tn5250_field_data, tvb, offset,
(length - 2), ENC_EBCDIC|ENC_NA);
offset++;
break;
case ROLL:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
offset += dissect_roll(cc_tree, tvb, offset);
break;
case WRITE_SINGLE_STRUCTURED_FIELD:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
offset += dissect_write_single_structured_field(cc_tree, tvb, offset);
break;
case WRITE_STRUCTURED_FIELD:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
offset += dissect_write_structured_field(cc_tree, tvb, offset);
break;
case COPY_TO_PRINTER:
proto_tree_add_item(cc_tree, hf_tn5250_command_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(cc_tree, hf_tn5250_ctp_lsid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(cc_tree, hf_tn5250_ctp_mlpp, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
default:
proto_tree_add_text(cc_tree, tvb, offset, 1, "Bogus value: %u", command_code);
offset ++;
break;
}
return (offset - start);
}
static guint32
dissect_inbound_stream(proto_tree *tn5250_tree, tvbuff_t *tvb, gint offset, gint sna_flag)
{
gint start = offset, aid;
guint32 commands;
if (sna_flag & 0x01) {
proto_tree_add_item(tn5250_tree, hf_tn5250_error_code, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset+=2;
return (offset - start);
} else if (sna_flag & 0x80) {
proto_tree_add_item(tn5250_tree, hf_tn5250_negative_response,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
return (offset - start);
}
aid = tvb_get_guint8(tvb,offset+2);
if (tn5250_is_valid_aid(aid)) {
switch(aid) {
case AID_IMAGE_FAX_REQUEST:
case AID_UNKNOWN_IMAGE_FAX_FORMAT:
case AID_IMAGE_FAX_ERROR:
proto_tree_add_item(tn5250_tree, hf_tn5250_image_fax_error, tvb, offset,
2, ENC_BIG_ENDIAN);
offset+=2;
break;
default:
offset += dissect_row_column(tn5250_tree, tvb, offset);
break;
}
proto_tree_add_item(tn5250_tree, hf_tn5250_aid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (aid == AID_INBOUND_WRITE_STRUCTURED_FIELD) {
offset += dissect_query_reply(tn5250_tree, tvb, offset);
return (offset - start);
}
offset += dissect_tn5250_orders_and_data(tn5250_tree, tvb, offset);
} else {
if (tvb_get_guint8(tvb,offset) == TN5250_ESCAPE) {
commands = dissect_outbound_stream(tn5250_tree, tvb, offset);
if (commands) {
offset += commands;
if (tvb_reported_length_remaining(tvb, offset)) {
proto_tree_add_item(tn5250_tree, hf_tn5250_unknown_data, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
}
return (offset - start);
}
}
}
if (tvb_reported_length_remaining(tvb, offset)) {
proto_tree_add_item(tn5250_tree, hf_tn5250_field_data, tvb, offset,
tvb_reported_length_remaining(tvb, offset),
ENC_EBCDIC|ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
}
return (offset - start);
}
static void
dissect_tn5250(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *tn5250_tree;
proto_item *ti;
gint offset = 0;
conversation_t *conversation;
tn5250_conv_info_t *tn5250_info = NULL;
int sna_flag;
pinfo->fd->flags.encoding = PACKET_CHAR_ENC_CHAR_EBCDIC;
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation != NULL) {
tn5250_info = (tn5250_conv_info_t *)conversation_get_proto_data(conversation, proto_tn5250);
}
if (!tn5250_info)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TN5250");
ti = proto_tree_add_item(tree, proto_tn5250, tvb, offset, -1, ENC_NA);
tn5250_tree = proto_item_add_subtree(ti, ett_tn5250);
if (pinfo->srcport == tn5250_info->outbound_port) {
col_set_str(pinfo->cinfo, COL_INFO, "TN5250 Data from Mainframe");
} else {
col_set_str(pinfo->cinfo, COL_INFO, "TN5250 Data to Mainframe");
}
if (tree) {
sna_flag = tvb_get_ntohs(tvb, offset+6);
offset += dissect_tn5250_header(tn5250_tree, tvb, offset);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
if (pinfo->srcport == tn5250_info->outbound_port) {
offset += dissect_outbound_stream(tn5250_tree, tvb, offset);
} else {
offset += dissect_inbound_stream(tn5250_tree, tvb, offset, sna_flag);
}
}
}
}
void
add_tn5250_conversation(packet_info *pinfo, int tn5250e)
{
conversation_t *conversation;
tn5250_conv_info_t *tn5250_info = NULL;
conversation = find_or_create_conversation(pinfo);
tn5250_info = (tn5250_conv_info_t *)conversation_get_proto_data(conversation, proto_tn5250);
if (tn5250_info == NULL) {
tn5250_info = wmem_new(wmem_file_scope(), tn5250_conv_info_t);
SE_COPY_ADDRESS(&(tn5250_info->outbound_addr),&(pinfo->dst));
tn5250_info->outbound_port = pinfo->destport;
SE_COPY_ADDRESS(&(tn5250_info->inbound_addr),&(pinfo->src));
tn5250_info->inbound_port = pinfo->srcport;
conversation_add_proto_data(conversation, proto_tn5250, tn5250_info);
tn5250_info->next = tn5250_info_items;
tn5250_info_items = tn5250_info;
}
tn5250_info->extended = tn5250e;
}
int
find_tn5250_conversation(packet_info *pinfo)
{
conversation_t *conversation = NULL;
tn5250_conv_info_t *tn5250_info = NULL;
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation != NULL) {
tn5250_info = (tn5250_conv_info_t *)conversation_get_proto_data(conversation, proto_tn5250);
if (tn5250_info != NULL) {
return 1;
}
}
return 0;
}
void
proto_register_tn5250(void)
{
static hf_register_info hf[] = {
{ &hf_tn5250_escape_code,
{ "Escape Code", "tn5250.escape_code",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_escape_codes), 0x0,
NULL, HFILL }},
{ &hf_tn5250_command_code,
{ "Command Code", "tn5250.command_code",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_command_codes), 0x0,
NULL, HFILL }},
{ &hf_tn5250_sf_length,
{ "Structured Field Length", "tn5250.sf_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn5250_sf_class,
{ "Structured Field Class", "tn5250.class",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_sf_class), 0,
NULL, HFILL }},
{ &hf_tn5250_sf_type,
{ "Structured Field Type", "tn5250.type",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_sf_type), 0,
NULL, HFILL }},
{ &hf_tn5250_cua_parm,
{ "TN5250 CUA Parameter", "tn5250.cua_parm",
FT_UINT16, BASE_HEX, VALS(vals_tn5250_cua_parms), 0x0,
NULL, HFILL }},
{ &hf_tn5250_wtd_ccc1,
{"Write To Display Command Control Character Byte 1", "tn5250.wtd_ccc1",
FT_UINT8, BASE_HEX,
VALS (vals_tn5250_wtd_cc_byteone), CCBITS, NULL, HFILL}},
{ &hf_tn5250_wtd_ccc2,
{ "Write To Display Command Control Character Byte 2", "tn5250.wtd_ccc2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wtd_ccc2_res,
{ "Reserved",
"tn5250.wtd_ccc_reserved", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_tn5250_wtd_ccc2_cursor,
{ "Cursor does not move when keyboard unlocks",
"tn5250.wtd_ccc_cursor", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_tn5250_wtd_ccc2_reset,
{ "Reset blinking cursor",
"tn5250.wtd_ccc_reset", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_tn5250_wtd_ccc2_set,
{ "Set blinking cursor",
"tn5250.wtd_ccc_set", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_tn5250_wtd_ccc2_unlock,
{ "Unlock the keyboard and reset any pending AID bytes",
"tn5250.wtd_ccc_unlock", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_tn5250_wtd_ccc2_alarm,
{ "Sound Alarm",
"tn5250.wtd_ccc_alarm", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_tn5250_wtd_ccc2_off,
{ "Set Message Waiting indicator off",
"tn5250.wtd_ccc_off", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_tn5250_wtd_ccc2_on,
{ "Set Message Waiting indicator on",
"tn5250.wtd_ccc_on", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_tn5250_repeated_character,
{ "Repeated Character", "tn5250.repeated_character",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn5250_soh_length,
{ "Length", "tn5250.soh_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_soh_flags,
{ "Start of Header Flags", "tn5250.soh_flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_soh_cursor_direction,
{ "Right To Left Screen-Level Cursor Direction", "tn5250.soh_cursor_direction",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_tn5250_soh_screen_reverse,
{ "Automatic local screen reverse", "tn5250.soh_screen_reverse",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_tn5250_soh_input_capable_only,
{ "The cursor is allowed to move only to input-capable positions", "tn5250.soh_input_capable_only",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_tn5250_soh_pf24to17, { "Command Key Switch 1", "tn5250.soh_pf24to17",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_tn5250_soh_pf24, { "PF24", "tn5250.soh_pf24",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_tn5250_soh_pf23, { "PF22", "tn5250.soh_pf23",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_tn5250_soh_pf22, { "PF22", "tn5250.soh_pf22",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_tn5250_soh_pf21, { "PF21", "tn5250.soh_pf21",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_tn5250_soh_pf20, { "PF20", "tn5250.soh_pf20",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_tn5250_soh_pf19, { "PF19", "tn5250.soh_pf19",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_tn5250_soh_pf18, { "PF18", "tn5250.soh_pf18",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_tn5250_soh_pf17, { "PF17", "tn5250.soh_pf17",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_tn5250_soh_pf16to9, { "Command Key Switch 2", "tn5250.soh_pf16to9",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_tn5250_soh_pf16, { "PF16", "tn5250.soh_pf16",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_tn5250_soh_pf15, { "PF15", "tn5250.soh_pf15",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_tn5250_soh_pf14, { "PF14", "tn5250.soh_pf14",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_tn5250_soh_pf13, { "PF13", "tn5250.soh_pf13",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_tn5250_soh_pf12, { "PF12", "tn5250.soh_pf12",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_tn5250_soh_pf11, { "PF11", "tn5250.soh_pf11",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_tn5250_soh_pf10, { "PF10", "tn5250.soh_pf10",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_tn5250_soh_pf9, { "PF9", "tn5250.soh_pf9",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_tn5250_soh_pf8to1, { "Command Key Switch 3", "tn5250.soh_pf8to1",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_tn5250_soh_pf8, { "PF8", "tn5250.soh_pf8",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_tn5250_soh_pf7, { "PF7", "tn5250.soh_pf7",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_tn5250_soh_pf6, { "PF6", "tn5250.soh_pf6",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_tn5250_soh_pf5, { "PF5", "tn5250.soh_pf5",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_tn5250_soh_pf4, { "PF4", "tn5250.soh_pf4",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_tn5250_soh_pf3, { "PF3", "tn5250.soh_pf3",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_tn5250_soh_pf2, { "PF2", "tn5250.soh_pf2",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_tn5250_soh_pf1, { "PF1", "tn5250.soh_pf1",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_tn5250_soh_resq, { "Resequence to Field", "tn5250.soh_resq",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_soh_err, { "Error Row", "tn5250.soh_err",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_wea_prim_attr,
{ "Extended Primary Attributes", "tn5250.wea_prim_attr",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wea_prim_attr_flag,
{ "Attribute Change",
"tn5250.wea_prim_attr_flag", FT_BOOLEAN, 8, NULL,
0x80, NULL, HFILL }},
{ &hf_tn5250_wea_prim_attr_col,
{ "Column Separator",
"tn5250.wea_prim_attr_col", FT_BOOLEAN, 8,
TFS(&tn5250_field_attr_col), 0x10, NULL, HFILL }},
{ &hf_tn5250_wea_prim_attr_blink,
{ "Blink",
"tn5250.wea_prim_attr_blink", FT_BOOLEAN, 8,
TFS(&tn5250_field_attr_blink), 0x08, NULL, HFILL }},
{ &hf_tn5250_wea_prim_attr_und,
{ "Underscore",
"tn5250.wea_prim_attr_und", FT_BOOLEAN, 8,
TFS(&tn5250_field_attr_und), 0x04, NULL, HFILL }},
{ &hf_tn5250_wea_prim_attr_int,
{ "Intensity",
"tn5250.wea_prim_attr_int", FT_BOOLEAN, 8,
TFS(&tn5250_field_attr_int), 0x02, NULL, HFILL }},
{ &hf_tn5250_wea_prim_attr_rev,
{ "Reverse Image",
"tn5250.wea_prim_attr_rev", FT_BOOLEAN, 8,
TFS(&tn5250_field_attr_rev), 0x01, NULL, HFILL }},
{ &hf_tn5250_foreground_color_attr,
{ "Foreground Color Attribute", "tn5250.foreground_color_attr",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_foreground_color_attributes), 0x0,
NULL, HFILL }},
{ &hf_tn5250_ideographic_attr,
{ "Ideographic Attribute", "tn5250.ideographic_attr",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_ideographic_attributes), 0x0,
NULL, HFILL }},
{ &hf_tn5250_ffw,
{ "Field Format Word", "tn5250.ffw",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_ffw_id,
{ "Field Format Word ID", "tn5250.ffw_id", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_ffw_id), FFW_ID_BITS, NULL, HFILL }},
{ &hf_tn5250_ffw_bypass,
{ "Bypass", "tn5250.ffw_bypass",
FT_BOOLEAN, 8, TFS(&tn5250_field_ffw_bypass),
0x20, NULL, HFILL }},
{ &hf_tn5250_ffw_dup,
{ "Dupe or Field Mark Enable", "tn5250.ffw_dup",
FT_BOOLEAN, 8, TFS(&tn5250_field_ffw_dup),
0x10, NULL, HFILL }},
{ &hf_tn5250_ffw_mdt,
{ "Modified Data Tag", "tn5250.ffw_mdt",
FT_BOOLEAN, 8, TFS(&tn5250_field_ffw_mdt),
0x08, NULL, HFILL }},
{ &hf_tn5250_ffw_shift,
{ "Field Shift/Edit Specification", "tn5250.ffw_shift", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_ffw_shift), FFW_SHIFT_BITS, NULL, HFILL }},
{ &hf_tn5250_ffw_auto,
{ "Auto Enter", "tn5250.ffw_auto",
FT_BOOLEAN, 8, TFS(&tn5250_field_ffw_auto),
0x80, NULL, HFILL }},
{ &hf_tn5250_ffw_fer,
{ "Field Exit Required", "tn5250.ffw_fer",
FT_BOOLEAN, 8, TFS(&tn5250_field_ffw_fer),
0x40, NULL, HFILL }},
{ &hf_tn5250_ffw_monocase,
{ "Monocase", "tn5250.ffw_monocase",
FT_BOOLEAN, 8, TFS(&tn5250_field_ffw_monocase),
0x20, NULL, HFILL }},
{ &hf_tn5250_ffw_res,
{ "Reserved", "tn5250.ffw_res",
FT_BOOLEAN, 8, NULL,
0x10, NULL, HFILL }},
{ &hf_tn5250_ffw_me,
{ "Mandatory Enter", "tn5250.ffw_me",
FT_BOOLEAN, 8, TFS(&tn5250_field_ffw_me),
0x08, NULL, HFILL }},
{ &hf_tn5250_ffw_adjust,
{ "Right Adjust/Mandatory Fill", "tn5250.ffw_adjust", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_ffw_adjust), FFW_ADJUST_BITS, NULL, HFILL }},
{ &hf_tn5250_fcw,
{ "Field Control Word", "tn5250.fcw",
FT_UINT16, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_fcw), 0,
NULL, HFILL }},
{ &hf_tn5250_fa_color,
{ "Field Attribute (Color)", "tn5250.fa_color",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_fa,
{ "Field Attributes", "tn5250.sf_fa",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_sf_attr_flag,
{ "Attribute ID",
"tn5250.sf_attr_flag", FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_id), FA_ID_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_flag1,
{ "Flags", "tn5250.wdsf_cw_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_flag1_1,
{ "Flag 1", "tn5250.wdsf_cw_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_cw_flag1_1),
0x80, NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_flag1_2,
{ "Flag 2", "tn5250.wdsf_cw_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_cw_flag1_2),
0x40, NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_flag1_reserved,
{ "Reserved", "tn5250.wdsf_cw_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0x3F, NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_wd,
{ "Window Depth", "tn5250.wdsf_cw_wd",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_ww,
{ "Window Width", "tn5250.wdsf_cw_ww",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_minor_type,
{ "Minor Structured Field Type", "tn5250.wdsf_cw_minor_type",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_wdsf_cw_minor_type), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_flag1,
{ "Flags", "tn5250.wdsf_cw_bp_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_flag1_1,
{ "Flag 1", "tn5250.wdsf_cw_bp_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_cw_bp_flag1_1),
0x80, NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_flag1_reserved,
{ "Reserved", "tn5250.wdsf_cw_bp_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0x7F, NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_mba,
{ "Monochrome Border Attribute", "tn5250.wdsf_cw_bp_mba",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_cba,
{ "Color Border Attribute", "tn5250.wdsf_cw_bp_cba",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_ulbc,
{ "Upper Left Border Character", "tn5250.wdsf_cw_bp_ulbc",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_tbc,
{ "Top Border Character", "tn5250.wdsf_cw_bp_tbc",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_urbc,
{ "Upper Right Border Character", "tn5250.wdsf_cw_bp_urbc",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_lbc,
{ "Left Border Character", "tn5250.wdsf_cw_bp_lbc",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_rbc,
{ "Right Border Character", "tn5250.wdsf_cw_bp_rbc",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_llbc,
{ "Lower Left Border Character", "tn5250.wdsf_cw_bp_llbc",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_bbc,
{ "Bottom Border Character", "tn5250.wdsf_cw_bp_bbc",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_bp_lrbc,
{ "Lower Right Border Character", "tn5250.wdsf_cw_bp_lrbc",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_tf_flag,
{ "Flags", "tn5250.wdsf_cw_tf_flag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_tf_flag_orientation,
{ "Orientation", "tn5250.wdsf_cw_tf_flag_orientation", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_wdsf_cw_tf_flag_orientation), WTF_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_tf_flag_1,
{ "Title/Footer Defined", "tn5250.wdsf_cw_tf_flag_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_cw_tf_flag_1),
0x20, NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_tf_flag_reserved,
{ "Reserved", "tn5250.wdsf_cw_tf_flag_reserved", FT_UINT8, BASE_HEX,
NULL, 0xF8, NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_tf_mba,
{ "Monochrome Title/Footer Attribute", "tn5250.wdsf_cw_tf_mba",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_tf_cba,
{ "Color Title/Footer Attribute", "tn5250.wdsf_cw_tf_cba",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cw_tf_text,
{ "Title Text", "tn5250.wdsf_cw_tf_text",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_rgw_flag1,
{ "Flags", "tn5250.wdsf_rgw_flag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_rgw_flag1_0,
{ "Reserved", "tn5250.wdsf_rgw_flag1_0",
FT_BOOLEAN, 8, NULL,
0x80, NULL, HFILL }},
{ &hf_tn5250_wdsf_rgw_flag1_1,
{ "Window Pull-Down", "tn5250.wdsf_rgw_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_cw_flag1_2),
0x40, NULL, HFILL }},
{ &hf_tn5250_wdsf_rgw_reserved,
{ "Reserved", "tn5250.wdsf_rgw_flag_reserved", FT_UINT8, BASE_HEX,
NULL, 0x3F, NULL, HFILL }},
{ &hf_tn5250_wdsf_ragc_flag1,
{ "Flags", "tn5250.wdsf_ragc_flag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ragc_flag1_0,
{ "GUI-Like Characters", "tn5250.wdsf_ragc_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ragc_flag1_0),
0x80, NULL, HFILL }},
{ &hf_tn5250_wdsf_ragc_reserved,
{ "Reserved", "tn5250.wdsf_ragc_flag_reserved", FT_UINT8, BASE_HEX,
NULL, 0x7F, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag1,
{ "Flags", "tn5250.wdsf_ds_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag1_mouse_characteristics,
{ "Mouse Characteristics", "tn5250.wdsf_ds_flag1_mouse_characteristics", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_wdsf_ds_flag1_mouse_characteristics), MOUSE_CHARACTERISTICS_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag1_reserved,
{ "Reserved", "tn5250.wdsf_ds_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0x0C, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag1_auto_enter,
{ "Mouse Characteristics", "tn5250.wdsf_ds_flag1_auto_enter", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_wdsf_ds_flag1_auto_enter), DS_AUTO_ENTER_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag1_1,
{ "Auto Select", "tn5250.wdsf_ds_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_flag1_1),
0x40, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag1_2,
{ "Field MDT", "tn5250.wdsf_ds_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_flag1_2),
0x80, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag2,
{ "Flags", "tn5250.wdsf_ds_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag2_1,
{ "Bit 0", "tn5250.wdsf_ds_flag2_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_flag2_1),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag2_2,
{ "Bit 1", "tn5250.wdsf_ds_flag2_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_flag2_2),
0x02, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag2_3,
{ "Bit 2", "tn5250.wdsf_ds_flag2_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_flag2_3),
0x04, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag2_4,
{ "Bit 3", "tn5250.wdsf_ds_flag2_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_flag2_4),
0x08, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag2_5,
{ "Bit 4", "tn5250.wdsf_ds_flag2_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_flag2_5),
0x10, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag2_6,
{ "Bit 5", "tn5250.wdsf_ds_flag2_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_flag2_6),
0x20, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag2_reserved,
{ "Reserved", "tn5250.wdsf_ds_flag2_reserved", FT_UINT8, BASE_HEX,
NULL, 0xC0, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag3,
{ "Flags", "tn5250.wdsf_ds_flag3",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag3_1,
{ "Bit 0", "tn5250.wdsf_ds_flag3_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_flag3_1),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_flag3_reserved,
{ "Reserved", "tn5250.wdsf_ds_flag3_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_type,
{ "Type of Selection Field", "tn5250.wdsf_ds_type",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_wdsf_ds_type), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_gdc,
{ "GUI Device Characteristics", "tn5250.wdsf_ds_gdc",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_gdc_indicators,
{ "Indicators", "tn5250.wdsf_ds_gdc_indicators", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_wdsf_ds_gdc_indicators), DS_INDICATORS_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_gdc_reserved,
{ "Reserved", "tn5250.wdsf_ds_gdc_reserved", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_gdc_selection_techniques,
{ "Selection Techniques", "tn5250.wdsf_ds_gdc_selection_techniques", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_wdsf_ds_gdc_selection_techniques), DS_SELECTION_TECHNIQUES_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_nws,
{ "NWS With Mnemonic Underscore Characteristics", "tn5250.wdsf_ds_nws",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_nws_indicators,
{ "Indicators", "tn5250.wdsf_ds_nws_indicators", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_wdsf_ds_nws_indicators), DS_NWS_INDICATORS_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_nws_reserved,
{ "Reserved", "tn5250.wdsf_ds_nws_reserved", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_nws_selection_techniques,
{ "Selection Techniques", "tn5250.wdsf_ds_nws_selection_techniques", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_wdsf_ds_nws_selection_techniques), DS_NWS_SELECTION_TECHNIQUES_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_nws_wout,
{ "NWS Without Mnemonic Underscore Characteristics", "tn5250.wdsf_ds_nws_wout",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_textsize,
{ "Text Size", "tn5250.wdsf_ds_textsize",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_rows,
{ "Rows", "tn5250.wdsf_ds_rows",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_columns,
{ "Columns/Menu Bar Choices", "tn5250.wdsf_ds_columns",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_padding,
{ "Padding Between Choices", "tn5250.wdsf_ds_padding",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_numeric_sep,
{ "Numeric Separator Character", "tn5250.wdsf_ds_numeric_sep",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_country_sel,
{ "Country Specific Selection Character", "tn5250.wdsf_ds_country_sel",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cancel_aid,
{ "Mouse Pull-Down Cancel AID", "tn5250.wdsf_ds_cancel_aid",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_totalrows,
{ "Total Rows or Minor Structures That Can Be Scrolled", "tn5250.wdsf_ds_totalrows",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sliderpos,
{ "Slider Positions That Can Be Scrolled", "tn5250.wdsf_ds_sliderpos",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_minor_type,
{ "Minor Structured Field Type", "tn5250.wdsf_ds_minor_type",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_wdsf_ds_minor_type), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag1,
{ "Flag Byte 1", "tn5250.wdsf_ds_ct_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag1_choice_state,
{ "Choice State", "tn5250.wdsf_ds_ct_flag1_choice_state", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_wdsf_ds_ct_flag1_choice_state), DS_CHOICE_STATE_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag1_2,
{ "Bit 2", "tn5250.wdsf_ds_ct_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag1_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag1_3,
{ "Bit 3", "tn5250.wdsf_ds_ct_flag1_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag1_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag1_4,
{ "Bit 4", "tn5250.wdsf_ds_ct_flag1_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag1_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag1_5,
{ "Bit 5", "tn5250.wdsf_ds_ct_flag1_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag1_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag1_numeric_selection,
{ "Numeric Selection Characters", "tn5250.wdsf_ds_ct_flag1_numeric_selection", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_wdsf_ds_ct_flag1_numeric_selection), DS_NUMERIC_SELECTION_BITS, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag2,
{ "Flag Byte 2", "tn5250.wdsf_ds_ct_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag2_0,
{ "Bit 0", "tn5250.wdsf_ds_ct_flag2_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag2_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag2_1,
{ "Bit 1", "tn5250.wdsf_ds_ct_flag2_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag2_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag2_2,
{ "Bit 2", "tn5250.wdsf_ds_ct_flag2_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag2_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag2_3,
{ "Bit 3", "tn5250.wdsf_ds_ct_flag2_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag2_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag2_4,
{ "Bit 4", "tn5250.wdsf_ds_ct_flag2_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag2_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag2_5,
{ "Bit 5", "tn5250.wdsf_ds_ct_flag2_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag2_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag2_6,
{ "Bit 6", "tn5250.wdsf_ds_ct_flag2_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag2_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag2_7,
{ "Bit 7", "tn5250.wdsf_ds_ct_flag2_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag2_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag3,
{ "Flag Byte 3", "tn5250.wdsf_ds_ct_flag3",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag3_0,
{ "Bit 0", "tn5250.wdsf_ds_ct_flag3_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag3_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag3_1,
{ "Bit 1", "tn5250.wdsf_ds_ct_flag3_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag3_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag3_2,
{ "Bit 2", "tn5250.wdsf_ds_ct_flag3_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ct_flag3_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_flag3_reserved,
{ "Reserved", "tn5250.wdsf_ds_ct_flag3_reserved", FT_UINT8, BASE_HEX,
NULL, 0xF8, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_mnemonic_offset,
{ "Mnemonic Offset", "tn5250.wdsf_ds_ct_mnemonic_offset",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_aid,
{ "AID", "tn5250.wdsf_ds_ct_aid",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_numeric_onebyte,
{ "Numeric Characters", "tn5250.wdsf_ds_ct_numeric",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_numeric_twobyte,
{ "Numeric Characters", "tn5250.wdsf_ds_ct_numeric",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ct_text,
{ "Choice Text", "tn5250.wdsf_ds_ct_text",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_mbs_flag,
{ "Flags", "tn5250.wdsf_ds_mbs_flag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_mbs_flag_0,
{ "Bit 0", "tn5250.wdsf_ds_mbs_flag_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_mbs_flag_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_mbs_flag_1,
{ "Bit 1", "tn5250.wdsf_ds_mbs_flag_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_mbs_flag_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_mbs_flag_reserved,
{ "Reserved", "tn5250.wdsf_ds_mbs_flag_reserved", FT_UINT8, BASE_HEX,
NULL, 0xF8, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_mbs_start_column,
{ "Start Column", "tn5250.wdsf_ds_mbs_start_column",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_mbs_end_column,
{ "End Column", "tn5250.wdsf_ds_mbs_end_column",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_mbs_monochrome_sep,
{ "Monochrome Separator Emphasis", "tn5250.wdsf_ds_mbs_monochrome_sep",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_mbs_color_sep,
{ "Color Separator Emphasis", "tn5250.wdsf_ds_mbs_color_sep",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_mbs_sep_char,
{ "Separator Character", "tn5250.wdsf_ds_mbs_sep_char",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_flag1,
{ "Flags", "tn5250.wdsf_ds_cpda_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_flag1_0,
{ "Bit 0", "tn5250.wdsf_ds_cpda_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_cpda_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_flag1_1,
{ "Bit 1", "tn5250.wdsf_ds_cpda_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_cpda_flag1_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_flag1_2,
{ "Bit 2", "tn5250.wdsf_ds_cpda_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_cpda_flag1_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_flag1_reserved,
{ "Reserved", "tn5250.wdsf_ds_cpda_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xF8, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_monochrome_sel_avail,
{ "Monochrome Selection Cursor Available Emphasis", "tn5250.wdsf_ds_cpda_monochrome_sel_avail",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_color_sel_avail,
{ "Color Selection Cursor Available Emphasis", "tn5250.wdsf_ds_cpda_color_sel_avail",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_monochrome_sel_selected,
{ "Monochrome Selection Cursor Selected Emphasis", "tn5250.wdsf_ds_cpda_monochrome_sel_selected",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_color_sel_selected,
{ "Color Selection Cursor Selected Emphasis", "tn5250.wdsf_ds_cpda_color_sel_selected",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_monochrome_sel_unavail,
{ "Monochrome Selection Cursor Unavailable Emphasis", "tn5250.wdsf_ds_cpda_monochrome_sel_unavail",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_color_sel_unavail,
{ "Color Selection Cursor Unavailable Emphasis", "tn5250.wdsf_ds_cpda_color_sel_unavail",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_monochrome_avail,
{ "Monochrome Available Emphasis", "tn5250.wdsf_ds_cpda_monochrome_avail",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_color_avail,
{ "Color Available Emphasis", "tn5250.wdsf_ds_cpda_color_avail",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_monochrome_selected,
{ "Monochrome Selected Emphasis", "tn5250.wdsf_ds_cpda_monochrome_selected",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_color_selected,
{ "Color Selected Emphasis", "tn5250.wdsf_ds_cpda_color_selected",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_monochrome_unavail,
{ "Monochrome Unavailable Emphasis", "tn5250.wdsf_ds_cpda_monochrome_unavail",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_color_unavail,
{ "Color Unavailable Emphasis", "tn5250.wdsf_ds_cpda_color_unavail",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_monochrome_indicator,
{ "Monochrome Indicator Emphasis", "tn5250.wdsf_ds_cpda_monochrome_indicator",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_color_indicator,
{ "Color Indicator Emphasis", "tn5250.wdsf_ds_cpda_color_indicator",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_monochrome_unavail_indicator,
{ "Monochrome Unavailable Indicator Emphasis", "tn5250.wdsf_ds_cpda_monochrome_unavail_indicator",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_cpda_color_unavail_indicator,
{ "Color Unavailable Indicator Emphasis", "tn5250.wdsf_ds_cpda_color_unavail_indicator",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ci_flag1,
{ "Flags", "tn5250.wdsf_ds_ci_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ci_flag1_0,
{ "Bit 0", "tn5250.wdsf_ds_ci_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_ci_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ci_flag1_reserved,
{ "Reserved", "tn5250.wdsf_ds_ci_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ci_left_push,
{ "Empty Indicator or Left Push Button", "tn5250.wdsf_ds_ci_left_push",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ci_right_push,
{ "Selected Indicator or Right Push Button", "tn5250.wdsf_ds_ci_right_push",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_ci_first_choice,
{ "Character That Replaces the First Choice Text Character for Unavailable Choices On a Monochrome Display", "tn5250.wdsf_ds_ci_first_choice",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_flag1,
{ "Flags", "tn5250.wdsf_ds_sbi_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_flag1_0,
{ "Bit 0", "tn5250.wdsf_ds_sbi_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_ds_sbi_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_flag1_reserved,
{ "Reserved", "tn5250.wdsf_ds_sbi_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_monochrome_top_highlight,
{ "Monochrome Top of ScrollBar Highlighting", "tn5250.wdsf_ds_sbi_monochrome_top_highlight",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_color_top_highlight,
{ "Color Top of ScrollBar Highlighting", "tn5250.wdsf_ds_sbi_color_top_highlightl",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_monochrome_top_highlight_shaft,
{ "Monochrome Shaft ScrollBar Highlighting", "tn5250.wdsf_ds_sbi_monochrome_top_highlight_shaft",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_color_top_highlight_shaft,
{ "Color Shaft ScrollBar Highlighting", "tn5250.wdsf_ds_sbi_color_top_highlight_shaft",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_top_character,
{ "Top Scroll Bar Character", "tn5250.wdsf_ds_sbi_top_character",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_bottom_character,
{ "Bottom Scroll Bar Character", "tn5250.wdsf_ds_sbi_bottom_character",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_empty_character,
{ "Empty Scroll Bar Character", "tn5250.wdsf_ds_sbi_empty_character",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_ds_sbi_slider_character,
{ "Slider Scroll Bar Character", "tn5250.wdsf_ds_sbi_slider_character",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_dsb_flag1,
{ "Flags", "tn5250.wdsf_dsb_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_dsb_flag1_0,
{ "Bit 0", "tn5250.wdsf_dsb_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_dsb_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_dsb_flag1_1,
{ "Bit 1", "tn5250.wdsf_dsb_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_dsb_flag1_0),
0x02, NULL, HFILL }},
{ &hf_tn5250_wdsf_dsb_flag1_reserved,
{ "Reserved", "tn5250.wdsf_dsb_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0x7C, NULL, HFILL }},
{ &hf_tn5250_wdsf_dsb_flag1_7,
{ "Bit 7", "tn5250.wdsf_dsb_flag1_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_dsb_flag1_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wdsf_sbi_total_scroll,
{ "TotalRows or TotalCols That Can Be Scrolled", "tn5250.wdsf_sbi_total_scroll",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_sbi_sliderpos,
{ "SliderPos", "tn5250.wdsf_sbi_sliderpos",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_sbi_rowscols,
{ "Rows or Columns", "tn5250.wdsf_sbi_rowscols",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_wdf_flag1,
{ "Flags", "tn5250.wdsf_wdf_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_wdf_flag1_0,
{ "Bit 0", "tn5250.wdsf_wdf_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_wdf_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_wdf_flag1_reserved,
{ "Reserved", "tn5250.wdsf_wdf_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_wdsf_pmb_flag1,
{ "Flags", "tn5250.wdsf_pmb_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_pmb_flag1_0,
{ "Bit 0", "tn5250.wdsf_pmb_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_pmb_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_pmb_flag1_1,
{ "Bit 1", "tn5250.wdsf_pmb_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_pmb_flag1_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wdsf_pmb_flag1_2,
{ "Bit 2", "tn5250.wdsf_pmb_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_pmb_flag1_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wdsf_pmb_flag1_3,
{ "Bit 3", "tn5250.wdsf_pmb_flag1_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_pmb_flag1_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_wdsf_pmb_flag1_reserved,
{ "Reserved", "tn5250.wdsf_pmb_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xF0, NULL, HFILL }},
{ &hf_tn5250_wdsf_pmb_first_mouse_event,
{ "First Mouse Event (Leading Edge Event)", "tn5250.wdsf_pmb_first_mouse_event",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_mouse_events), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_pmb_second_mouse_event,
{ "Second Mouse Event (Trailing Edge Event)", "tn5250.wdsf_pmb_second_mouse_event",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_mouse_events), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_partition,
{ "Partition", "tn5250.wdsf_deg_partition",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_flag1,
{ "Flags", "tn5250.wdsf_deg_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_flag1_0,
{ "Bit 0", "tn5250.wdsf_deg_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_deg_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_flag1_reserved,
{ "Reserved", "tn5250.wdsf_deg_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_flag2,
{ "Flags", "tn5250.wdsf_deg_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_flag2_0,
{ "Bit 0", "tn5250.wdsf_deg_flag2_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_deg_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_flag2_reserved,
{ "Reserved", "tn5250.wdsf_deg_flag2_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_default_color,
{ "Default Color for Grid Lines", "tn5250.wdsf_deg_default_color",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_default_line,
{ "Default Line Style", "tn5250.wdsf_deg_default_line",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_deg_lines), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_minor_type,
{ "Construct", "tn5250.wdsf_deg_minor_type",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_wdsf_deg_minor_type), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_flag1,
{ "Flags", "tn5250.wdsf_deg_ms_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_flag1_0,
{ "Bit 0", "tn5250.wdsf_deg_ms_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wdsf_deg_ms_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_flag1_reserved,
{ "Reserved", "tn5250.wdsf_deg_ms_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_start_row,
{ "Start Row", "tn5250.wdsf_deg_ms_start_row",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_start_column,
{ "Start Column", "tn5250.wdsf_deg_ms_start_column",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_horizontal_dimension,
{ "Horizontal Dimenstion", "tn5250.wdsf_deg_ms_horizontal_dimension",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_vertical_dimension,
{ "Vertical Dimenstion", "tn5250.wdsf_deg_ms_vertical_dimension",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_default_color,
{ "Color", "tn5250.wdsf_deg_ms_default_color",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_fa_color), 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_line_repeat,
{ "Line Repeat", "tn5250.wdsf_deg_ms_line_repeat",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_deg_ms_line_interval,
{ "Line Interval", "tn5250.wdsf_deg_ms_line_interval",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cgl_partition,
{ "Partition", "tn5250.wdsf_cgl_partition",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cgl_start_row,
{ "Start Row", "tn5250.wdsf_cgl_start_row",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cgl_start_column,
{ "Start Column", "tn5250.wdsf_cgl_start_column",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cgl_rectangle_width,
{ "Width of Rectangle", "tn5250.wdsf_cgl_rectangle_width",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wdsf_cgl_rectangle_height,
{ "Height of Rectangle", "tn5250.wdsf_cgl_rectangle_height",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wectw_start_column,
{ "Start Column", "tn5250.wectw_start_column",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wectw_end_column,
{ "End Column", "tn5250.wectw_end_column",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_sps_flag1,
{ "Flags", "tn5250.sps_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_sps_flag1_0,
{ "Bit 0", "tn5250.sps_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_sps_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_sps_flag1_reserved,
{ "Reserved", "tn5250.sps_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_sps_top_row,
{ "Top Row", "tn5250.sps_top_row",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_sps_left_column,
{ "Left Column", "tn5250.sps_left_column",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_sps_window_depth,
{ "Window Depth", "tn5250.sps_window_depth",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_sps_window_width,
{ "Window Width", "tn5250.sps_window_width",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_roll_flag1,
{ "Byte 1", "tn5250.roll_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_roll_flag1_0,
{ "Bit 0", "tn5250.roll_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_roll_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_roll_flag1_reserved,
{ "Reserved", "tn5250.roll_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0x06, NULL, HFILL }},
{ &hf_tn5250_roll_flag1_lines,
{ "Number of lines that the designated area is to be rolled", "tn5250.roll_flag1_lines", FT_UINT8, BASE_DEC,
NULL, 0xF8, NULL, HFILL }},
{ &hf_tn5250_roll_top_line,
{ "Line number defining the top line of the area that will participate in the roll", "tn5250.roll_top_line",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_roll_bottom_line,
{ "Line number defining the bottom line of the area that will participate in the roll", "tn5250.roll_bottom_line",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_wsc_minor_type,
{ "Minor Structured Field Type", "tn5250.wssf_wsc_minor_type",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_wssf_minor_type), 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_flag1,
{ "Byte 1", "tn5250.wssf_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_flag2,
{ "Byte 2", "tn5250.wssf_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_flag2_0,
{ "Bit 0", "tn5250.wssf_flag2_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_flag2_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wssf_flag2_1,
{ "Bit 1", "tn5250.wssf_flag2_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_flag2_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wssf_flag2_2,
{ "Bit 2", "tn5250.wssf_flag2_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_flag2_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wssf_flag2_3,
{ "Bit 3", "tn5250.wssf_flag2_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_flag2_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_wssf_flag2_4,
{ "Bit 4", "tn5250.wssf_flag2_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_flag2_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_wssf_flag2_5,
{ "Bit 5", "tn5250.wssf_flag2_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_flag2_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_wssf_flag2_6,
{ "Bit 6", "tn5250.wssf_flag2_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_flag2_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_wssf_flag2_7,
{ "Bit 7", "tn5250.wssf_flag2_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_flag2_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wssf_kbc_flag1,
{ "Byte 1", "tn5250.wssf_kbc_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_kbc_flag1_reserved,
{ "Reserved", "tn5250.wssf_kbc_flag1_reserved", FT_UINT8, BASE_HEX|BASE_RANGE_STRING,
RVALS(vals_tn5250_reserved), 0x1F, NULL, HFILL }},
{ &hf_tn5250_wssf_kbc_flag1_5,
{ "Bit 5", "tn5250.wssf_kbc_flag1_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_kbc_flag1_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_wssf_kbc_flag1_6,
{ "Bit 6", "tn5250.wssf_kbc_flag1_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_kbc_flag1_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_wssf_kbc_flag1_7,
{ "Bit 7", "tn5250.wssf_kbc_flag1_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_kbc_flag1_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wssf_cc_flag1,
{ "Byte 1", "tn5250.wssf_cc_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_cc_flag1_reserved,
{ "Reserved", "tn5250.wssf_cc_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0x7F, NULL, HFILL }},
{ &hf_tn5250_wssf_cc_flag1_7,
{ "Bit 7", "tn5250.wssf_cc_flag1_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_cc_flag1_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag1,
{ "Byte 1", "tn5250.wssf_ifc_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag1_0,
{ "Bit 0 (Cache allowed flag)", "tn5250.wssf_ifc_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_ifc_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag1_1to3,
{ "Bits 1-3 (Type of image/fax display)", "tn5250.wssf_ifc_flag1_1to3", FT_UINT8, BASE_HEX,
VALS(tn5250_vals_tn5250_wssf_ifc_vals), 0x0E, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag1_4,
{ "Bit 4 (Color importance during scaling)", "tn5250.wssf_ifc_flag1_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_ifc_flag1_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag1_5,
{ "Bit 5 (Allow display to control scaling)", "tn5250.wssf_ifc_flag1_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_ifc_flag1_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag1_6,
{ "Bit 6 (Reverse image)", "tn5250.wssf_ifc_flag1_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_ifc_flag1_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag1_7,
{ "Bit 7 (Allow/Inhibit EasyScroll with a mouse)", "tn5250.wssf_ifc_flag1_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_ifc_flag1_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag2,
{ "Byte 2", "tn5250.wssf_ifc_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag2_0,
{ "Bit 0 (Duplicate Scan Lines)", "tn5250.wssf_ifc_flag2_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_ifc_flag2_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag2_1,
{ "Bit 1 (Allow/Inhibit Trim Magnify Scaling)", "tn5250.wssf_ifc_flag2_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_ifc_flag2_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag2_reserved,
{ "Reserved", "tn5250.wssf_ifc_flag2_reserved", FT_UINT8, BASE_HEX,
NULL, 0x7C, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_flag2_7,
{ "Bit 7", "tn5250.wssf_ifc_flag2_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_ifc_flag2_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_image_format,
{ "Image Format", "tn5250.wssf_ifc_image_format",
FT_UINT16, BASE_DEC, VALS(vals_tn5250_image_format), 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_viewport_location_row,
{ "Viewport Location (Row)", "tn5250.wssf_ifc_viewport_location_row",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_viewport_location_col,
{ "Viewport Location (Column)", "tn5250.wssf_ifc_viewport_location_col",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_viewport_size_row,
{ "Viewport Size (Row)", "tn5250.wssf_ifc_viewport_size_row",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_viewport_size_col,
{ "Viewport Size (Column)", "tn5250.wssf_ifc_viewport_size_col",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_scaling,
{ "Scaling", "tn5250.wssf_ifc_scaling",
FT_UINT16, BASE_HEX, VALS(vals_tn5250_wssf_ifc_scaling), 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_viewimage_location_row,
{ "View Image Location (Vertical Percentage)", "tn5250.wssf_ifc_viewimage_location_row",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_viewimage_location_col,
{ "View Image Location (Horizontal Position)", "tn5250.wssf_ifc_viewimage_location_col",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_rotation,
{ "Rotation (Degrees)", "tn5250.wssf_ifc_rotation",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_foreground_color,
{ "Foreground Color", "tn5250.wssf_ifc_foreground_color",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_foreground_color_attributes), 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_background_color,
{ "Background Color", "tn5250.wssf_ifc_background_color",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_foreground_color_attributes), 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifc_imagefax_name,
{ "Image/Fax Name", "tn5250.wssf_ifc_imagefax_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifd_flag1,
{ "Byte 1", "tn5250.wssf_ifd_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifd_flag1_0,
{ "Bit 0 (Last Data Stream flag)", "tn5250.wssf_ifd_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wssf_ifd_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wssf_ifd_flag1_reserved,
{ "Reserved", "tn5250.wssf_ifd_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_wssf_ifd_imagefax_name,
{ "Image/Fax Name", "tn5250.wssf_ifd_imagefax_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ifd_imagefax_data,
{ "Image/Fax Data", "tn5250.wssf_ifd_imagefax_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_image_fax_error,
{ "Image/Fax Error", "tn5250.image_fax_error",
FT_UINT16, BASE_HEX, VALS(vals_tn5250_image_fax_error), 0,
NULL, HFILL }},
{ &hf_tn5250_vac_prefix,
{ "Video/Audio Control Data Prefix", "tn5250.vac_data_prefix",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_vac_data,
{ "Video/Audio Control Data", "tn5250.vac_data",
FT_UINT32, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_vac_data), 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ttw_flag,
{ "Flag", "tn5250.wssf_ttw_flag",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_wssf_ttw_flag), 0,
NULL, HFILL }},
{ &hf_tn5250_wssf_ttw_data,
{ "Transparent Data", "tn5250.wssf_ttw_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wsf_qss_flag1,
{ "Byte 1", "tn5250.wsf_qss_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wsf_qss_flag1_0,
{ "Bit 0", "tn5250.wsf_qss_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wsf_qss_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wsf_qss_flag1_reserved,
{ "Reserved", "tn5250.wsf_qss_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_wsf_qss_flag2,
{ "Byte 2", "tn5250.wsf_qss_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wsf_qss_flag2_reserved,
{ "Reserved", "tn5250.wsf_qss_flag2_reserved", FT_UINT8, BASE_HEX,
NULL, 0x7F, NULL, HFILL }},
{ &hf_tn5250_wsf_qss_flag2_7,
{ "Bit 7", "tn5250.wsf_qss_flag2_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wsf_qss_flag2_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_dawt_id,
{ "ID", "tn5250.dawt_id",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dawt_id), 0,
NULL, HFILL }},
{ &hf_tn5250_dawt_length,
{ "Length", "tn5250.dawt_length",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dawt_length), 0,
NULL, HFILL }},
{ &hf_tn5250_dawt_char,
{ "Character", "tn5250.dawt_char",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dawt_message,
{ "Message", "tn5250.dawt_message",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dckf_id,
{ "ID", "tn5250.dckf_id",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dckf_id), 0,
NULL, HFILL }},
{ &hf_tn5250_dckf_length,
{ "Length", "tn5250.dckf_length",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dckf_length), 0,
NULL, HFILL }},
{ &hf_tn5250_dckf_key_code,
{ "Key Code", "tn5250.dckf_key_code",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dckf_key_code), 0,
NULL, HFILL }},
{ &hf_tn5250_dckf_function_code,
{ "Function Code", "tn5250.dckf_function_code",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_dckf_function_code), 0,
NULL, HFILL }},
{ &hf_tn5250_dckf_prompt_text,
{ "Prompt Text", "tn5250.dckf_prompt_text",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_rts_partition,
{ "Partition", "tn5250.rts_partition",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_rts_partition), 0,
NULL, HFILL }},
{ &hf_tn5250_rts_flag1,
{ "Byte 1", "tn5250.rts_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_rts_flag1_0,
{ "Bit 0 (Last Data Stream flag)", "tn5250.rts_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_rts_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_rts_flag1_reserved,
{ "Reserved", "tn5250.rts_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_dpo_partition,
{ "Partition", "tn5250.dpo_partition",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_rts_partition), 0,
NULL, HFILL }},
{ &hf_tn5250_dpo_flag1,
{ "Byte 1", "tn5250.dpo_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dpo_flag1_0,
{ "Bit 0", "tn5250.dpo_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_dpo_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_dpo_flag1_1,
{ "Bit 1", "tn5250.dpo_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_dpo_flag1_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_dpo_flag1_2,
{ "Bit 2", "tn5250.dpo_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_dpo_flag1_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_dpo_flag1_3,
{ "Bit 3", "tn5250.dpo_flag1_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_dpo_flag1_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_dpo_flag1_4,
{ "Bit 4", "tn5250.dpo_flag1_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_dpo_flag1_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_dpo_flag1_5,
{ "Bit 5", "tn5250.dpo_flag1_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_dpo_flag1_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_dpo_flag1_6,
{ "Bit 6", "tn5250.dpo_flag1_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_dpo_flag1_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_dpo_flag1_7,
{ "Bit 7", "tn5250.dpo_flag1_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_dpo_flag1_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_dpo_flag2,
{ "Byte 1", "tn5250.dpo_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dpo_flag2_0,
{ "Bit 0", "tn5250.dpo_flag2_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_dpo_flag2_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_dpo_flag2_reserved,
{ "Reserved", "tn5250.dpo_flag2_reserved", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_tn5250_dpo_displace_characters,
{ "Displaced Characters", "tn5250.dpo_displace_characters",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dpo_start_location_row,
{ "Start Location (Row)", "tn5250.dpo_start_location_row",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dpo_start_location_col,
{ "Start Location (Column)", "tn5250.dpo_start_location_col",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dtsf_partition,
{ "Partition", "tn5250.dtsf_partition",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_rts_partition), 0,
NULL, HFILL }},
{ &hf_tn5250_dtsf_flag1,
{ "Byte 1", "tn5250.dtsf_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dtsf_flag1_0,
{ "Bit 0", "tn5250.dtsf_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag1_1,
{ "Bit 1", "tn5250.dtsf_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag1_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag1_2,
{ "Bit 2", "tn5250.dtsf_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag1_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag1_3,
{ "Bit 3", "tn5250.dtsf_flag1_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag1_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag1_4,
{ "Bit 4", "tn5250.dtsf_flag1_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag1_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag1_5,
{ "Bit 5", "tn5250.dtsf_flag1_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag1_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag1_6,
{ "Bit 6", "tn5250.dtsf_flag1_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag1_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag1_7,
{ "Bit 7", "tn5250.dtsf_flag1_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag1_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag2,
{ "Byte 1", "tn5250.dtsf_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dtsf_flag2_0,
{ "Bit 0", "tn5250.dtsf_flag2_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag2_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag2_1,
{ "Bit 1", "tn5250.dtsf_flag2_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag2_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag2_2,
{ "Bit 2", "tn5250.dtsf_flag2_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag2_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag2_3,
{ "Bit 3", "tn5250.dtsf_flag2_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_dtsf_flag2_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_dtsf_flag2_4to7,
{ "Bits 4 to 7", "tn5250.dtsf_flag2_4to7",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dtsf_flag2_vals), 0xF0,
NULL, HFILL }},
{ &hf_tn5250_dtsf_text_body_height,
{ "Text Body Height", "tn5250.dtsf_text_body_height",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dtsf_text_body_width,
{ "Text Body Width", "tn5250.dtsf_text_body_width",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dtsf_line_cmd_field_size,
{ "Line Cmd Field Size", "tn5250.dtsf_line_cmd_field_size",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dtsf_location_of_pitch,
{ "Location of Pitch", "tn5250.dtsf_location_of_pitch",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dtsf_first_line,
{ "First Line in Text Body", "tn5250.dtsf_first_line",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dsl_partition,
{ "Partition", "tn5250.dsl_partition",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_rts_partition), 0,
NULL, HFILL }},
{ &hf_tn5250_dsl_rtl_offset,
{ "RTL Offset", "tn5250.dsl_rtl_offset",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dsl_offset,
{ "Offset", "tn5250.dsl_offset",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dsl_flag1,
{ "Byte 1", "tn5250.dsl_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dsl_flag1_0,
{ "Bit 0", "tn5250.dsl_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_dsl_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_dsl_flag1_1,
{ "Bit 1", "tn5250.dsl_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_dsl_flag1_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_dsl_flag1_2,
{ "Bit 2", "tn5250.dsl_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_dsl_flag1_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_dsl_flag1_reserved,
{ "Reserved", "tn5250.dsl_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xF8, NULL, HFILL }},
{ &hf_tn5250_dsl_id,
{ "ID", "tn5250.dsl_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dsl_location,
{ "Location", "tn5250.dsl_location",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dsl_function,
{ "Function", "tn5250.dsl_function",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dsl_function), 0x00,
NULL, HFILL }},
{ &hf_tn5250_wts_partition,
{ "Partition", "tn5250.wts_partition",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_rts_partition), 0,
NULL, HFILL }},
{ &hf_tn5250_wts_flag1,
{ "Byte 1", "tn5250.wts_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_flag1_0,
{ "Bit 0", "tn5250.wts_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wts_flag1_1,
{ "Bit 1", "tn5250.wts_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag1_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wts_flag1_2,
{ "Bit 2", "tn5250.wts_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag1_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wts_flag1_3,
{ "Bit 3", "tn5250.wts_flag1_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag1_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_wts_flag1_reserved,
{ "Reserved", "tn5250.wts_flag1_reserved", FT_UINT8, BASE_HEX,
NULL, 0xF0, NULL, HFILL }},
{ &hf_tn5250_wts_flag2,
{ "Byte 2", "tn5250.wts_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_flag2_reserved,
{ "Reserved", "tn5250.wts_flag2_reserved", FT_UINT8, BASE_HEX,
NULL, 0x1F, NULL, HFILL }},
{ &hf_tn5250_wts_flag2_6,
{ "Bit 6", "tn5250.wts_flag2_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag2_6),
0x20, NULL, HFILL }},
{ &hf_tn5250_wts_flag2_reserved2,
{ "Reserved", "tn5250.wts_flag2_reserved2", FT_UINT8, BASE_HEX,
NULL, 0xC0, NULL, HFILL }},
{ &hf_tn5250_wts_flag3,
{ "Byte 3", "tn5250.wts_flag3",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_flag3_0,
{ "Bit 0", "tn5250.wts_flag3_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag3_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wts_flag3_1,
{ "Bit 1", "tn5250.wts_flag3_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag3_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wts_flag3_2,
{ "Bit 2", "tn5250.wts_flag3_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag3_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wts_flag3_3,
{ "Bit 3", "tn5250.wts_flag3_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag3_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_wts_flag3_4,
{ "Bit 4", "tn5250.wts_flag3_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag3_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_wts_flag3_5,
{ "Bit 5", "tn5250.wts_flag3_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag3_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_wts_flag3_6,
{ "Bit 6", "tn5250.wts_flag3_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag3_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_wts_flag3_7,
{ "Bit 7", "tn5250.wts_flag3_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_flag3_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wts_home_position_row,
{ "Home Position (Row)", "tn5250.wts_home_position_row",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_home_position_col,
{ "Home Position (Column)", "tn5250.wts_home_position_col",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag1,
{ "Byte 1", "tn5250.wts_cld_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag1_0,
{ "Bit 0", "tn5250.wts_cld_flag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag1_1,
{ "Bit 1", "tn5250.wts_cld_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag1_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag1_2,
{ "Bit 2", "tn5250.wts_cld_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag1_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag1_3,
{ "Bit 3", "tn5250.wts_cld_flag1_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag1_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag1_4,
{ "Bit 4", "tn5250.wts_cld_flag1_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag1_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag1_5,
{ "Bit 5", "tn5250.wts_cld_flag1_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag1_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag1_6,
{ "Bit 6", "tn5250.wts_cld_flag1_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag1_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag1_7,
{ "Bit 7", "tn5250.wts_cld_flag1_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag1_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag2,
{ "Byte 2", "tn5250.wts_cld_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag2_0,
{ "Bit 0", "tn5250.wts_cld_flag2_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag2_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag2_1,
{ "Bit 1", "tn5250.wts_cld_flag2_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag2_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag2_2,
{ "Bit 2", "tn5250.wts_cld_flag2_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag2_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag2_3,
{ "Bit 3", "tn5250.wts_cld_flag2_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag2_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag2_4,
{ "Bit 4", "tn5250.wts_cld_flag2_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag2_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag2_line_spacing,
{ "Line Spacing in Half-Units", "tn5250.wts_cld_flag2_line_spacing", FT_UINT8, BASE_DEC,
NULL, 0xE0, NULL, HFILL }},
{ &hf_tn5250_wts_cld_row,
{ "Row", "tn5250.wts_cld_row",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag3,
{ "Byte 3", "tn5250.wts_cld_flag3",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag3_0,
{ "Bit 0", "tn5250.wts_cld_flag3_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag3_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag3_1,
{ "Bit 1", "tn5250.wts_cld_flag3_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag3_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag3_2,
{ "Bit 2", "tn5250.wts_cld_flag3_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag3_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag3_3,
{ "Bit 3", "tn5250.wts_cld_flag3_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag3_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag3_4,
{ "Bit 4", "tn5250.wts_cld_flag3_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag3_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag3_5,
{ "Bit 5", "tn5250.wts_cld_flag3_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag3_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag3_6,
{ "Bit 6", "tn5250.wts_cld_flag3_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag3_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_wts_cld_flag3_7,
{ "Bit 7", "tn5250.wts_cld_flag3_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_wts_cld_flag3_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_wts_cld_page_num,
{ "Page Number", "tn5250.wts_cld_page_num",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_cld_lmo,
{ "Left Margin Offset", "tn5250.wts_cld_lmo",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_cld_io,
{ "Indent Offset", "tn5250.wts_cld_io",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_cld_sli,
{ "Scale Line ID", "tn5250.wts_cld_sli",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_wts_cld_li,
{ "Line Image", "tn5250.wts_cld_li",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dsc_partition,
{ "Partition", "tn5250.dsc_partition",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_rts_partition), 0,
NULL, HFILL }},
{ &hf_tn5250_dsc_sk,
{ "Symbol Key", "tn5250.dsc_sk",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dsc_ev,
{ "EBCDIC Value", "tn5250.dsc_ev",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dorm_id,
{ "ID", "tn5250.dorm_id",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dorm_id), 0x00,
NULL, HFILL }},
{ &hf_tn5250_dorm_length,
{ "Length", "tn5250.dorm_length",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dorm_length), 0,
NULL, HFILL }},
{ &hf_tn5250_dorm_ec,
{ "Error Code", "tn5250.dorm_ec",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dorm_mt,
{ "Message Text", "tn5250.dorm_mt",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dpt_id,
{ "ID", "tn5250.dpt_id",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dpt_id), 0x00,
NULL, HFILL }},
{ &hf_tn5250_dpt_ec,
{ "EBCDIC Code", "tn5250.dpt_ec",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dfdpck_partition,
{ "Partition", "tn5250.dfdpck_partition",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_rts_partition), 0,
NULL, HFILL }},
{ &hf_tn5250_dfdpck_data_field,
{ "Data Field", "tn5250.dfdpck_data_field",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_dfdpck_data_field), 0,
NULL, HFILL }},
{ &hf_tn5250_dfdpck_coreflag,
{ "Core Area Flag", "tn5250.dfdpck_coreflag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dfdpck_coreflag_0,
{ "Bit 0", "tn5250.dfdpck_coreflag_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_coreflag_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_dfdpck_coreflag_1,
{ "Bit 1", "tn5250.dfdpck_coreflag_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_coreflag_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_dfdpck_coreflag_2,
{ "Bit 2", "tn5250.dfdpck_coreflag_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_coreflag_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_dfdpck_coreflag_3,
{ "Bit 3", "tn5250.dfdpck_coreflag_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_coreflag_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_dfdpck_coreflag_4,
{ "Bit 4", "tn5250.dfdpck_coreflag_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_coreflag_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_dfdpck_coreflag_5,
{ "Bit 5", "tn5250.dfdpck_coreflag_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_coreflag_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_dfdpck_coreflag_6,
{ "Bit 6", "tn5250.dfdpck_coreflag_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_coreflag_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_dfdpck_coreflag_7,
{ "Bit 7", "tn5250.dfdpck_coreflag_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_coreflag_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag1,
{ "Top Row Flags", "tn5250.dfdpck_toprowflag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag1_0,
{ "Bit 0", "tn5250.dfdpck_toprowflag1_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag1_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag1_1,
{ "Bit 1", "tn5250.dfdpck_toprowflag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag1_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag1_2,
{ "Bit 2", "tn5250.dfdpck_toprowflag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag1_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag1_3,
{ "Bit 3", "tn5250.dfdpck_toprowflag1_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag1_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag1_4,
{ "Bit 4", "tn5250.dfdpck_toprowflag1_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag1_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag1_5,
{ "Bit 5", "tn5250.dfdpck_toprowflag1_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag1_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag1_6,
{ "Bit 6", "tn5250.dfdpck_toprowflag1_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag1_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag1_7,
{ "Bit 7", "tn5250.dfdpck_toprowflag1_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag1_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag2,
{ "Top Row Flags", "tn5250.dfdpck_toprowflag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag2_0,
{ "Bit 0", "tn5250.dfdpck_toprowflag2_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag2_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag2_1,
{ "Bit 1", "tn5250.dfdpck_toprowflag2_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag2_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag2_2,
{ "Bit 2", "tn5250.dfdpck_toprowflag2_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag2_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag2_3,
{ "Bit 3", "tn5250.dfdpck_toprowflag2_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag2_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag2_4,
{ "Bit 4", "tn5250.dfdpck_toprowflag2_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag2_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag2_5,
{ "Bit 5", "tn5250.dfdpck_toprowflag2_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag2_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag2_6,
{ "Bit 6", "tn5250.dfdpck_toprowflag2_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag2_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag2_7,
{ "Bit 7", "tn5250.dfdpck_toprowflag2_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag2_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag3,
{ "Top Row Flags", "tn5250.dfdpck_toprowflag3",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag3_0,
{ "Bit 0", "tn5250.dfdpck_toprowflag3_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag3_0),
0x01, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag3_1,
{ "Bit 1", "tn5250.dfdpck_toprowflag3_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag3_1),
0x02, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag3_2,
{ "Bit 2", "tn5250.dfdpck_toprowflag3_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag3_2),
0x04, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag3_3,
{ "Bit 3", "tn5250.dfdpck_toprowflag3_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag3_3),
0x08, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag3_4,
{ "Bit 4", "tn5250.dfdpck_toprowflag3_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag3_4),
0x10, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag3_5,
{ "Bit 5", "tn5250.dfdpck_toprowflag3_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag3_5),
0x20, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag3_6,
{ "Bit 6", "tn5250.dfdpck_toprowflag3_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag3_6),
0x40, NULL, HFILL }},
{ &hf_tn5250_dfdpck_toprowflag3_7,
{ "Bit 7", "tn5250.dfdpck_toprowflag3_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_dfdpck_toprowflag3_7),
0x80, NULL, HFILL }},
{ &hf_tn5250_ctp_lsid,
{ "Printer LSID", "tn5250.ctp_lsid",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_ctp_mlpp,
{ "Max Lines Per Page", "tn5250.ctp_mlpp",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_qr_flag,
{ "Flag", "tn5250.qr_flag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_qr_flag_0,
{ "Bit 1", "tn5250.qr_flag_0",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag_0),
0x80, NULL, HFILL }},
{ &hf_tn5250_qr_flag_reserved,
{ "Reserved", "tn5250.qr_flag_reserved", FT_UINT8, BASE_HEX,
NULL, 0x7F, NULL, HFILL }},
{ &hf_tn5250_qr_chc,
{ "Controller Hardware Class", "tn5250.qr_chc",
FT_UINT16, BASE_HEX, VALS(vals_tn5250_chc), 0x0,
NULL, HFILL }},
{ &hf_tn5250_qr_ccl,
{ "Controller Code Level", "tn5250.qr_ccl",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn5250_qr_dt,
{ "Device Type", "tn5250.qr_dt",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_dt), 0x0,
NULL, HFILL }},
{ &hf_tn5250_qr_dtc,
{ "Device Type", "tn5250.qr_dtc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn5250_qr_dm,
{ "Device Model", "tn5250.qr_dm",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn5250_qr_ki,
{ "Keyboard ID", "tn5250.qr_ki",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_qr_ki), 0x0,
NULL, HFILL }},
{ &hf_tn5250_qr_eki,
{ "Extended Keyboard ID", "tn5250.qr_eki",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn5250_qr_dsn,
{ "Display Serial Number", "tn5250.qr_dsn",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn5250_qr_mni,
{ "Maximum number of input fields", "tn5250.qr_mni",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn5250_qr_flag1,
{ "Flags", "tn5250.qr_flag1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_qr_flag1_0,
{ "Bit 0 (Reserved)", "tn5250.qr_flag1_0",
FT_BOOLEAN, 8, NULL,
0x80, NULL, HFILL }},
{ &hf_tn5250_qr_flag1_1,
{ "Bit 1", "tn5250.qr_flag1_1",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag1_1),
0x40, NULL, HFILL }},
{ &hf_tn5250_qr_flag1_2,
{ "Bit 2", "tn5250.qr_flag1_2",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag1_2),
0x20, NULL, HFILL }},
{ &hf_tn5250_qr_flag1_3,
{ "Bit 3", "tn5250.qr_flag1_3",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag1_3),
0x10, NULL, HFILL }},
{ &hf_tn5250_qr_flag1_4,
{ "Bit 4", "tn5250.qr_flag1_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag1_4),
0x08, NULL, HFILL }},
{ &hf_tn5250_qr_flag1_5,
{ "Bit 5", "tn5250.qr_flag1_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag1_5),
0x04, NULL, HFILL }},
{ &hf_tn5250_qr_flag1_6,
{ "Bit 6", "tn5250.qr_flag1_6",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag1_6),
0x02, NULL, HFILL }},
{ &hf_tn5250_qr_flag1_7,
{ "Bit 7", "tn5250.qr_flag1_7",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag1_7),
0x01, NULL, HFILL }},
{ &hf_tn5250_qr_flag2,
{ "Flags", "tn5250.qr_flag2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_tn5250_qr_flag2_0to3,
{ "Bits 0 to 3", "tn5250.qr_flag2_0to3", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_qr_flag2_0to3), 0xF0, NULL, HFILL }},
{ &hf_tn5250_qr_flag2_4,
{ "Bit 4", "tn5250.qr_flag2_4",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag2_4),
0x08, NULL, HFILL }},
{ &hf_tn5250_qr_flag2_5,
{ "Bit 5", "tn5250.qr_flag2_5",
FT_BOOLEAN, 8, TFS(&tn5250_field_qr_flag2_5),
0x04, NULL, HFILL }},
{ &hf_tn5250_qr_flag2_6to7,
{ "Bits 6 to 7", "tn5250.qr_flag2_6to7", FT_UINT8, BASE_HEX,
VALS(vals_tn5250_qr_flag2_6to7), 0x03, NULL, HFILL }},
{ &hf_tn5250_qr_flag3,
{ "Flags", "tn5250.qr_flag3",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_qr_flag3), 0,
NULL, HFILL }},
{ &hf_tn5250_qr_flag4,
{ "Flags", "tn5250.qr_flag4",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_qr_flag4), 0,
NULL, HFILL }},
{ &hf_tn5250_order_code, { "Order Code", "tn5250.order_code",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_order_codes), 0x0, NULL, HFILL }},
{ &hf_tn5250_attribute_type, { "Attribute Type", "tn5250.attribute",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_attributes), 0x0, NULL, HFILL }},
{ &hf_tn5250_aid, { "Attention Identification", "tn5250.aid",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING,
RVALS(vals_tn5250_attention_identification_bytes), 0x0, NULL, HFILL }},
{ &hf_tn5250_buffer_x, { "Row Address", "tn5250.buffer_x",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_buffer_y, { "Column Address", "tn5250.buffer_y",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_length, { "Length", "tn5250.length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_length_twobyte, { "Length", "tn5250.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_field_data,
{ "Field Data", "tn5250.field_data", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tn5250_reserved, { "Flags (Reserved):", "tn5250.reserved",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(vals_tn5250_reserved), 0,
NULL, HFILL }},
{ &hf_tn5250_unknown_data,
{ "Unknown Data (Possible Mainframe/Emulator Bug)", "tn5250.unknown_data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_logical_record_length,
{ "TN5250 Logical Record Length", "tn5250.logical_record_length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_sna_record_type,
{ "TN5250 SNA Record Type", "tn5250.sna_record_type",
FT_UINT16, BASE_HEX, VALS(vals_tn5250_sna_record_type), 0x0,
NULL, HFILL }},
{ &hf_tn5250_variable_record_length,
{ "TN5250 Variable Record Length", "tn5250.variable_record_length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_header_flags, { "TN5250 SNA Flags", "tn5250.header_flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_tn5250_ds_output_error,
{ "Data Stream Output Error",
"tn5250.ds_output_error", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_tn5250_attn_key,
{ "5250 attention key was pressed.",
"tn5250.attn_key", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_tn5250_sys_request_key,
{ "5250 System Request key was pressed",
"tn5250.sys_request_key", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_tn5250_test_request_key,
{ "5250 Test Request key was pressed",
"tn5250.test_request_key", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_tn5250_error_state,
{ "In Error State",
"tn5250.error_state", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_tn5250_operation_code,
{ "TN5250 Operation Code", "tn5250.operation_code",
FT_UINT8, BASE_HEX, VALS(vals_tn5250_header_operation_code), 0x0,
NULL, HFILL }},
{ &hf_tn5250_error_code,
{ "TN5250 Error Code", "tn5250.error_code",
FT_UINT16, BASE_HEX, VALS(vals_tn5250_header_error_codes), 0x0,
NULL, HFILL }},
{ &hf_tn5250_negative_response,
{ "Negative Response", "tn5250.negative_response",
FT_UINT32, BASE_HEX, VALS(vals_tn5250_negative_responses), 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_tn5250,
&ett_sf,
&ett_tn5250_wcc,
&ett_tn5250_field_attribute,
&ett_tn5250_dfdpck_mask,
&ett_tn5250_field_validation,
&ett_tn5250_header_flags,
&ett_tn5250_roll_mask,
&ett_tn5250_soh_mask,
&ett_tn5250_soh_pf16to9_mask,
&ett_tn5250_soh_pf24to17_mask,
&ett_tn5250_soh_pf8to1_mask,
&ett_tn5250_sps_mask,
&ett_tn5250_wdsf_cw_bp_mask,
&ett_tn5250_wdsf_cw_mask,
&ett_tn5250_wdsf_cw_tf_mask,
&ett_tn5250_wdsf_deg_mask,
&ett_tn5250_wdsf_deg_ms_mask,
&ett_tn5250_wdsf_ds_ci_mask,
&ett_tn5250_wdsf_ds_cpda_mask,
&ett_tn5250_wdsf_ds_ct_mask,
&ett_tn5250_wdsf_ds_mask,
&ett_tn5250_wdsf_ds_mbs_mask,
&ett_tn5250_wdsf_ds_sbi_mask,
&ett_tn5250_wdsf_dsb_mask,
&ett_tn5250_wdsf_pmb_mask,
&ett_tn5250_wdsf_ragc_mask,
&ett_tn5250_wdsf_rgw_mask,
&ett_tn5250_wdsf_wdf_mask,
&ett_tn5250_wsf_dpo_mask,
&ett_tn5250_wsf_dsl_mask,
&ett_tn5250_wsf_dtsf_mask,
&ett_tn5250_wsf_qss_mask,
&ett_tn5250_wsf_rts_mask,
&ett_tn5250_wssf_cc_mask,
&ett_tn5250_wssf_ifc_mask,
&ett_tn5250_wssf_ifd_mask,
&ett_tn5250_wssf_kbc_mask,
&ett_tn5250_wssf_mask,
&ett_tn5250_wts_mask,
&ett_tn5250_wea_prim_attr,
&ett_tn5250_qr_mask,
&ett_cc,
};
proto_tn5250 = proto_register_protocol("TN5250 Protocol", "TN5250", "tn5250");
register_dissector("tn5250", dissect_tn5250, proto_tn5250);
proto_register_field_array(proto_tn5250, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
