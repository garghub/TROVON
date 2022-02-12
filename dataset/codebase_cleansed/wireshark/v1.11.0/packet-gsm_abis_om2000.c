static gint
dissect_tss_mo_state(tvbuff_t *tvb, gint offset, proto_tree *tree)
{
guint8 tmp;
guint i = 0;
for (i = 0; i < 8; i+= 2) {
tmp = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_om2k_tsn_state, tvb, offset, 1, tmp & 0xf,
"Timslot %u MO State: %s", i,
val_to_str(tmp & 0xf, om2k_mo_state_vals, "unknown (%02d)"));
proto_tree_add_uint_format(tree, hf_om2k_tsn_state, tvb, offset, 1, tmp >> 4,
"Timslot %u MO State: %s", i+1,
val_to_str(tmp >> 4, om2k_mo_state_vals, "unknown (%02d)"));
offset++;
}
return 4;
}
static gint
dissect_om2k_time(tvbuff_t *tvb, gint offset, proto_tree *tree)
{
nstime_t tmptime;
time_t tval;
struct tm _time;
_time.tm_year = 100 + tvb_get_guint8(tvb, offset++);
_time.tm_mon = tvb_get_guint8(tvb, offset++) - 1;
_time.tm_mday = tvb_get_guint8(tvb, offset++);
_time.tm_hour = tvb_get_guint8(tvb, offset++);
_time.tm_min = tvb_get_guint8(tvb, offset++);
_time.tm_sec = tvb_get_guint8(tvb, offset++);
_time.tm_isdst = -1;
tval = mktime(&_time);
tmptime.secs = tval;
tmptime.nsecs = 0;
proto_tree_add_time(tree, hf_om2k_cal_time, tvb, offset, 6,
&tmptime);
return 6;
}
static gint
dissect_om2k_attr_unkn(tvbuff_t *tvb, gint offset, gint len, gint iei, proto_tree *tree)
{
proto_tree_add_bytes_format(tree, hf_om2k_unknown_val, tvb,
offset, len, NULL,
"%s: %s",
val_to_str_ext(iei, &om2k_attr_vals_ext, "0x%02x"),
tvb_bytes_to_str(tvb, offset, len));
return len;
}
static gint
dissect_om2k_is_list(tvbuff_t *tvb, gint base_offset, proto_tree *tree)
{
gint offset = base_offset;
proto_item *ti;
proto_tree *isl_tree;
guint8 len = tvb_get_guint8(tvb, offset++);
ti = proto_tree_add_item(tree, hf_om2k_isl, tvb, offset, len, ENC_NA);
isl_tree = proto_item_add_subtree(ti, ett_om2k_isl);
while (offset < base_offset + len) {
proto_tree_add_item(isl_tree, hf_om2k_isl_icp1, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(isl_tree, hf_om2k_isl_icp2, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(isl_tree, hf_om2k_isl_ci, tvb,
offset++, 1, ENC_BIG_ENDIAN);
}
return offset - base_offset;
}
static gint
dissect_om2k_con_list(tvbuff_t *tvb, gint base_offset, proto_tree *tree)
{
gint offset = base_offset;
proto_item *ti;
proto_tree *conl_tree;
guint8 len = tvb_get_guint8(tvb, offset++);
ti = proto_tree_add_item(tree, hf_om2k_conl, tvb, offset, len, ENC_NA);
conl_tree = proto_item_add_subtree(ti, ett_om2k_conl);
proto_tree_add_item(conl_tree, hf_om2k_conl_nr_cgs, tvb,
offset++, 1, ENC_BIG_ENDIAN);
while (offset < base_offset + len) {
guint8 nr_cps_cg = tvb_get_guint8(tvb, offset);
proto_tree_add_item(conl_tree, hf_om2k_conl_nr_cps_cg, tvb,
offset++, 1, ENC_BIG_ENDIAN);
while (nr_cps_cg--) {
proto_tree_add_item(conl_tree, hf_om2k_conl_ccp, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(conl_tree, hf_om2k_conl_ci, tvb,
offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(conl_tree, hf_om2k_conl_tag, tvb,
offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(conl_tree, hf_om2k_conl_tei, tvb,
offset++, 1, ENC_BIG_ENDIAN);
}
}
return offset - base_offset;
}
static gint
dissect_om2k_attrs(tvbuff_t *tvb, gint offset, proto_tree *tree)
{
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint8 iei = tvb_get_guint8(tvb, offset++);
guint8 len, tmp;
switch (iei) {
case 0x00:
proto_tree_add_item(tree, hf_om2k_aip, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x06:
proto_tree_add_item(tree, hf_om2k_bcc, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x07:
proto_tree_add_item(tree, hf_om2k_bs_ag_blks_res, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x09:
proto_tree_add_item(tree, hf_om2k_bsic, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x0a:
proto_tree_add_item(tree, hf_om2k_bs_pa_mfrms, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x0b:
proto_tree_add_item(tree, hf_om2k_cbi, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x0c:
proto_tree_add_item(tree, hf_om2k_cr, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_om2k_ipt3, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_om2k_aop, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 0x0d:
offset += dissect_om2k_time(tvb, offset, tree);
break;
case 0x0f:
proto_tree_add_item(tree, hf_om2k_comb, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x10:
offset += dissect_om2k_con_list(tvb, offset, tree);
break;
case 0x12:
proto_tree_add_item(tree, hf_om2k_drx_dev_max, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x13:
proto_tree_add_item(tree, hf_om2k_list_nr_end, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x14:
case 0x15:
offset += dissect_om2k_attr_unkn(tvb, offset, 2, iei, tree);
break;
case 0x16:
proto_tree_add_item(tree, hf_om2k_filerel_ilr, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_om2k_filerel_cur, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_om2k_filerel_other, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 0x17:
proto_tree_add_item(tree, hf_om2k_file_rev, tvb,
offset, 8, ENC_ASCII|ENC_NA);
offset += 8;
break;
case 0x1c:
proto_tree_add_item(tree, hf_om2k_fill_mark, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x1d:
proto_tree_add_item(tree, hf_om2k_fn_offs, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case 0x1e:
len = tvb_get_guint8(tvb, offset++);
offset += dissect_om2k_attr_unkn(tvb, offset, len, iei, tree);
break;
case 0x1f:
case 0x20:
offset += dissect_om2k_attr_unkn(tvb, offset, 2, iei, tree);
break;
case 0x21:
proto_tree_add_item(tree, hf_om2k_hsn, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x22:
proto_tree_add_item(tree, hf_om2k_icm, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x23:
case 0x24:
case 0x25:
case 0x26:
offset += dissect_om2k_attr_unkn(tvb, offset, 6, iei, tree);
break;
case 0x27:
offset += dissect_om2k_is_list(tvb, offset, tree);
break;
case 0x28:
proto_tree_add_item(tree, hf_om2k_list_nr, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x2a:
proto_tree_add_item(tree, hf_om2k_la_state, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x2b:
proto_tree_add_item(tree, hf_om2k_maio, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x2c:
proto_tree_add_item(tree, hf_om2k_mo_state, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x2d:
proto_tree_add_item(tree, hf_om2k_ny1, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x2e:
proto_tree_add_item(tree, hf_om2k_oip, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x2f:
proto_tree_add_item(tree, hf_om2k_nom_pwr, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x33:
proto_tree_add_item(tree, hf_om2k_diversity, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x34:
offset += dissect_om2k_attr_unkn(tvb, offset, 6, iei, tree);
break;
case 0x38:
proto_tree_add_item(tree, hf_om2k_t3105, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x3a:
proto_tree_add_item(tree, hf_om2k_tf_mode, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x3c:
proto_tree_add_item(tree, hf_om2k_ts, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x3d:
proto_tree_add_item(tree, hf_om2k_tsc, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x40:
proto_tree_add_item(tree, hf_om2k_bts_manuf, tvb,
offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_om2k_bts_gen, tvb,
offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_om2k_bts_rev, tvb,
offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_om2k_bts_var, tvb,
offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
break;
case 0x43:
case 0x44:
case 0x45:
case 0x46:
len = tvb_get_guint8(tvb, offset++);
offset += dissect_om2k_attr_unkn(tvb, offset, len, iei, tree);
break;
case 0x47:
proto_tree_add_item(tree, hf_om2k_ext_range, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x48:
proto_tree_add_item(tree, hf_om2k_brr, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_om2k_bfr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 0x50:
offset += dissect_om2k_attr_unkn(tvb, offset, 6, iei, tree);
break;
case 0x74:
offset += dissect_om2k_attr_unkn(tvb, offset, 5, iei, tree);
break;
case 0x79:
proto_tree_add_item(tree, hf_om2k_lsc_fm, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_om2k_lsc_lsi, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_om2k_lsc_lsa, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 0x7a:
proto_tree_add_item(tree, hf_om2k_ls_ft, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x7b:
proto_tree_add_item(tree, hf_om2k_cst, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x7e:
proto_tree_add_item(tree, hf_om2k_icm_cr, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x84:
proto_tree_add_item(tree, hf_om2k_hwinfo_sig, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case 0x87:
proto_tree_add_item(tree, hf_om2k_tta, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x8a:
proto_tree_add_item(tree, hf_om2k_capa_sig, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case 0x90:
case 0x91:
len = tvb_get_guint8(tvb, offset++);
offset += dissect_om2k_attr_unkn(tvb, offset, len, iei, tree);
break;
case 0x92:
proto_tree_add_item(tree, hf_om2k_ea, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x94:
proto_tree_add_item(tree, hf_om2k_irc, tvb,
offset++, 1, ENC_BIG_ENDIAN);
break;
case 0x95:
offset += dissect_om2k_attr_unkn(tvb, offset, 3, iei, tree);
break;
case 0x98:
proto_tree_add_item(tree, hf_om2k_tf_fs_offset, tvb,
offset, 5, ENC_BIG_ENDIAN);
offset += 5;
break;
case 0x9c:
offset += dissect_om2k_attr_unkn(tvb, offset, 4, iei, tree);
break;
case 0x9d:
offset += dissect_tss_mo_state(tvb, offset, tree);
break;
case 0x9e:
case 0x9f:
default:
tmp = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_om2k_unknown_tag, tvb,
offset-1, 1, tmp, "Tag %s: 0x%02x",
val_to_str_ext(iei, &om2k_attr_vals_ext, "0x%02x"), tmp);
offset++;
break;
}
}
return offset;
}
static guint
dissect_om2k_mo(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree)
{
guint8 mo_class = tvb_get_guint8(tvb, offset);
guint8 inst = tvb_get_guint8(tvb, offset+3);
col_append_fstr(pinfo->cinfo, COL_INFO, ", (%-4s %u)",
val_to_str(mo_class, om2k_mo_class_short_vals,
"0x%02x"), inst);
if (tree) {
proto_item *ti;
proto_tree *mo_tree;
guint8 sub1 = tvb_get_guint8(tvb, offset+1);
guint8 sub2 = tvb_get_guint8(tvb, offset+2);
ti = proto_tree_add_item(tree, hf_om2k_mo_if, tvb, offset,
4, ENC_NA);
mo_tree = proto_item_add_subtree(ti, ett_om2k_mo);
proto_tree_add_item(mo_tree, hf_om2k_mo_class, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(mo_tree, hf_om2k_mo_sub1, tvb, offset+1,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(mo_tree, hf_om2k_mo_sub2, tvb, offset+2,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(mo_tree, hf_om2k_mo_instance, tvb, offset+3,
1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Class: %s, Sub: %02x/%02x, Instance: %u",
val_to_str(mo_class, om2k_mo_class_vals, "0x%02x"),
sub1, sub2, inst);
}
return 4;
}
static void
dissect_abis_om2000(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *om2k_tree;
guint16 msg_code;
guint8 tmp;
int offset;
if ((tree == NULL) && (pinfo->cinfo == NULL))
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OM2000");
offset = 0;
ti = proto_tree_add_item(tree, proto_abis_om2000,
tvb, 0, -1, ENC_NA);
om2k_tree = proto_item_add_subtree(ti, ett_om2000);
msg_code = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(om2k_tree, hf_om2k_msg_code, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
offset += dissect_om2k_mo(tvb, offset, pinfo, om2k_tree);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s ",
val_to_str_ext(msg_code, &om2k_msgcode_vals_ext,
"unknown 0x%04x"));
if (tree == NULL)
return;
proto_item_append_text(ti, " %s ",
val_to_str_ext(msg_code, &om2k_msgcode_vals_ext,
"unknown 0x%04x"));
switch (msg_code) {
case 0x74:
tmp = tvb_get_guint8(tvb, offset+1);
proto_item_append_text(ti, ": %s",
val_to_str(tmp, om2k_oip_vals,
"unknown 0x%02x"));
break;
case 0x1A:
case 0x66:
case 0x82:
case 0xA6:
case 0xAE:
case 0xB6:
case 0xE2:
case 0xF6:
tmp = tvb_get_guint8(tvb, offset+1);
proto_item_append_text(ti, ": %s",
val_to_str(tmp, om2k_aip_vals,
"unknown 0x%02x"));
break;
default:
break;
}
dissect_om2k_attrs(tvb, offset, om2k_tree);
}
void
proto_register_abis_om2000(void)
{
static hf_register_info hf[] = {
{ &hf_om2k_msg_code,
{ "Message Code", "gsm_abis_om2000.msg_code",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &om2k_msgcode_vals_ext, 0,
NULL, HFILL }
},
{ &hf_om2k_mo_if,
{ "MO Interface", "gsm_abis_om2000.mo_if",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_mo_class,
{ "MO IF Class", "gsm_abis_om2000.mo_if.class",
FT_UINT8, BASE_HEX, VALS(om2k_mo_class_vals), 0,
NULL, HFILL }
},
{ &hf_om2k_mo_sub1,
{ "MO IF Sub 1", "gsm_abis_om2000.mo_if.sub1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_mo_sub2,
{ "MO IF Sub 2", "gsm_abis_om2000.mo_if.sub2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_mo_instance,
{ "MO IF Instance", "gsm_abis_om2000.mo_if.instance",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_oip,
{ "OIP (Operational Info)", "gsm_abis_om2000.oip",
FT_UINT8, BASE_HEX, VALS(om2k_oip_vals), 0,
"Operational Information Parameter", HFILL }
},
{ &hf_om2k_aip,
{ "AIP (Accordance Info)", "gsm_abis_om2000.aip",
FT_UINT8, BASE_HEX, VALS(om2k_aip_vals), 0,
"Accordance Information Parameter", HFILL }
},
{ &hf_om2k_comb,
{ "Channel Combination", "gsm_abis_om2000.chan_comb",
FT_UINT8, BASE_DEC, VALS(om2k_comb_vals), 0,
"Logical Channel Combination", HFILL }
},
{ &hf_om2k_ts,
{ "Timeslot Number", "gsm_abis_om2000.ts",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_hsn,
{ "HSN", "gsm_abis_om2000.hsn",
FT_UINT8, BASE_DEC, NULL, 0,
"Hopping Sequence Number", HFILL }
},
{ &hf_om2k_maio,
{ "MAIO", "gsm_abis_om2000.maio",
FT_UINT8, BASE_DEC, NULL, 0,
"Mobile Allication Index Offset", HFILL }
},
{ &hf_om2k_bsic,
{ "BSIC", "gsm_abis_om2000.bsic",
FT_UINT8, BASE_HEX, NULL, 0,
"Base Station Identity Code", HFILL }
},
{ &hf_om2k_diversity,
{ "Receiver Diversity", "gsm_abis_om2000.diversity",
FT_UINT8, BASE_HEX, VALS(om2k_diversity_vals), 0,
NULL, HFILL }
},
{ &hf_om2k_fn_offs,
{ "FN Offset", "gsm_abis_om2000.fn_offset",
FT_UINT16, BASE_DEC, NULL, 0,
"GSM Frame Number Offset", HFILL }
},
{ &hf_om2k_ext_range,
{ "Extended Range", "gsm_abis_om2000.ext_range",
FT_BOOLEAN, 1, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_irc,
{ "Interference Rejection Combining", "gsm_abis_om2000.irc",
FT_BOOLEAN, 1, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_bs_pa_mfrms,
{ "BS_PA_MFRMS", "gsm_abis_om2000.bs_pa_mfrms",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_bs_ag_blks_res,
{ "BS_AG_BLKS_RES", "gsm_abis_om2000.bs_ag_blks_res",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_drx_dev_max,
{ "DRX_DEV_MAX", "gsm_abis_om2000.drx_dev_max",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_cr,
{ "CCCH Repeat", "gsm_abis_om2000.ccch_repeat",
FT_BOOLEAN, 1, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_ipt3,
{ "Inhibit Paging Request Type 3", "gsm_abis_om2000.ipt3",
FT_BOOLEAN, 2, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_aop,
{ "Age Of Paging", "gsm_abis_om2000.aop",
FT_UINT8, BASE_DEC, NULL, 0x3C,
NULL, HFILL }
},
{ &hf_om2k_t3105,
{ "T3105 (in 10ms)", "gsm_abis_om2000.t3105",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_ny1,
{ "Ny1", "gsm_abis_om2000.ny1",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_cbi,
{ "CBCH Indicator", "gsm_abis_om2000.cbi",
FT_BOOLEAN, 1, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_tsc,
{ "Training Sequence Code", "gsm_abis_om2000.tsc",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_icm,
{ "Idle Channel Measurement", "gsm_abis_om2000.icm",
FT_BOOLEAN, 1, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_tta,
{ "Timer for Time Alignment", "gsm_abis_om2000.tta",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_icm_cr,
{ "ICM Channel Rate", "gsm_abis_om2000.icm_cr",
FT_UINT8, BASE_DEC, VALS(om2k_icmcr_vals), 0,
NULL, HFILL }
},
{ &hf_om2k_lsc_fm,
{ "LSC Dummy Frequency Measurement", "gsm_abis_om2000.lsc.fm",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_om2k_lsc_lsi,
{ "LSC Idle Channels", "gsm_abis_om2000.ls.lsi",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_om2k_lsc_lsa,
{ "LSC Active Channels", "gsm_abis_om2000.ls.lsa",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_om2k_ls_ft,
{ "Link Supervision Filtering Time (100ms)", "gsm_abis_om2000.ls_ft",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_cst,
{ "Call Supervision Time (480ms)", "gsm_abis_om2000.cst",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_ea,
{ "Encryption Algorithm", "gsm_abis_om2000.ea",
FT_UINT8, BASE_DEC, VALS(om2k_ea_vals), 0,
NULL, HFILL }
},
{ &hf_om2k_nom_pwr,
{ "Nominal Power (dBm)", "gsm_abis_om2000.pwr",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_fill_mark,
{ "Filling Marker", "gsm_abis_om2000.filling",
FT_UINT8, BASE_DEC, VALS(om2k_fill_vals), 0,
NULL, HFILL }
},
{ &hf_om2k_bcc,
{ "BCC", "gsm_abis_om2000.bcc",
FT_UINT8, BASE_DEC, NULL, 0,
"Base Station Color Code", HFILL }
},
{ &hf_om2k_mo_state,
{ "MO State", "gsm_abis_om2000.mo_state",
FT_UINT8, BASE_DEC, VALS(om2k_mo_state_vals), 0,
NULL, HFILL }
},
{ &hf_om2k_la_state,
{ "Local Access State", "gsm_abis_om2000.la_state",
FT_UINT8, BASE_DEC, VALS(om2k_la_state_vals), 0,
NULL, HFILL }
},
{ &hf_om2k_tsn_state,
{ "Time Slot N MO State", "gsm_abis_om2000.tsn_mo_state",
FT_UINT8, BASE_DEC, VALS(om2k_mo_state_vals), 0,
NULL, HFILL }
},
{ &hf_om2k_bts_manuf,
{ "BTS Manufacturer ID", "gsm_abis_om2000.bts_ver.manuf",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_bts_gen,
{ "BTS Generation", "gsm_abis_om2000.bts_ver.gen",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_bts_rev,
{ "BTS Revision", "gsm_abis_om2000.bts_ver.rev",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_bts_var,
{ "BTS Variant", "gsm_abis_om2000.bts_ver.variant",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_brr,
{ "BTS Requested Restart", "gsm_abis_om2000.brr",
FT_BOOLEAN, 0x01, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_bfr,
{ "BTS Requested File Relation", "gsm_abis_om2000.bfr",
FT_BOOLEAN, 0x01, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_hwinfo_sig,
{ "HW Info Signature", "gsm_abis_om2000.hwinfo_sig",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_capa_sig,
{ "Capabilities Signature", "gsm_abis_om2000.capa_sig",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_unknown_tag,
{ "Unknown Tag", "gsm_abis_om2000.unknown.tag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_unknown_val,
{ "Unknown Value", "gsm_abis_om2000.unknown.val",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_file_rev,
{ "File Revision", "gsm_abis_om2000.file_rev",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_filerel_ilr,
{ "Immediate Load Requested", "gsm_abis_om2000.filerel.ilr",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_om2k_filerel_cur,
{ "Current State", "gsm_abis_om2000.filerel.cur",
FT_UINT8, BASE_HEX, VALS(filerel_state_vals), 0x07,
NULL, HFILL }
},
{ &hf_om2k_filerel_other,
{ "Other State", "gsm_abis_om2000.filerel.other",
FT_UINT8, BASE_HEX, VALS(filerel_state_vals), 0x07,
NULL, HFILL }
},
{ &hf_om2k_cal_time,
{ "Calendar Time", "gsm_abis_om2000.cal_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_list_nr,
{ "List Number", "gsm_abis_om2000.list_nr",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_list_nr_end,
{ "End List Number", "gsm_abis_om2000.list_nr_end",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_isl,
{ "IS Connection List", "gsm_abis_om2000.is_list",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_isl_icp1,
{ "ICP1", "gsm_abis_om2000.is_list.icp1",
FT_UINT16, BASE_DEC, NULL, 0x7ff,
NULL, HFILL }
},
{ &hf_om2k_isl_icp2,
{ "ICP2", "gsm_abis_om2000.is_list.icp2",
FT_UINT16, BASE_DEC, NULL, 0x7ff,
NULL, HFILL }
},
{ &hf_om2k_isl_ci,
{ "Contiguity Index", "gsm_abis_om2000.is_list.ci",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_conl,
{ "Connection List", "gsm_abis_om2000.con_list",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_conl_nr_cgs,
{ "Number of CGs", "gsm_abis_om2000.con_list.nr_cgs",
FT_UINT8, BASE_DEC, NULL, 0x1f,
"Number of Concentration Groups in the DE", HFILL }
},
{ &hf_om2k_conl_nr_cps_cg,
{ "Number of CPS in CG", "gsm_abis_om2000.con_list.nr_cps_cg",
FT_UINT8, BASE_DEC, NULL, 0x1f,
"Number of CPS in Concentration Group", HFILL }
},
{ &hf_om2k_conl_ccp,
{ "CON Connection Point", "gsm_abis_om2000.con_list.cpp",
FT_UINT16, BASE_DEC, NULL, 0x3ff,
NULL, HFILL }
},
{ &hf_om2k_conl_ci,
{ "Contiguity Index", "gsm_abis_om2000.con_list.ci",
FT_UINT8, BASE_DEC, NULL, 0x7,
NULL, HFILL }
},
{ &hf_om2k_conl_tag,
{ "Tag", "gsm_abis_om2000.con_list.tag",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_om2k_conl_tei,
{ "TEI", "gsm_abis_om2000.con_list.tei",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_om2k_tf_mode,
{ "TF Mode", "gsm_abis_om2000.tf_mode",
FT_UINT8, BASE_HEX, VALS(om2k_tf_mode_vals), 0,
NULL, HFILL }
},
{ &hf_om2k_tf_fs_offset,
{ "TF FS Offset", "gsm_abis_om2000.tf_fs_offset",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_om2000,
&ett_om2k_mo,
&ett_om2k_isl,
&ett_om2k_conl,
};
proto_abis_om2000 = proto_register_protocol("Ericsson A-bis OML",
"Ericsson OML",
"gsm_abis_om2000");
proto_register_field_array(proto_abis_om2000, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gsm_abis_om2000", dissect_abis_om2000,
proto_abis_om2000);
}
