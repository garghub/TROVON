static const gchar *get_sw_string(guint16 sw)
{
guint8 sw1 = sw >> 8;
switch (sw1) {
case 0x91:
return "Normal ending of command with info from proactive SIM";
case 0x9e:
return "Length of the response data given / SIM data download error";
case 0x9f:
return "Length of the response data";
case 0x92:
if ((sw & 0xf0) == 0x00)
return "Command successful but after internal retry routine";
break;
case 0x67:
return "Incorrect parameter P3";
case 0x6d:
return "Unknown instruction code";
case 0x6e:
return "Wrong instruction class";
case 0x6f:
return "Technical problem with no diacnostic";
}
return val_to_str(sw, sw_vals, "%04x");
}
static void
dissect_bertlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
unsigned int pos = 0;
while (pos < tvb_length(tvb)) {
guint8 tag, len;
tvbuff_t *subtvb;
proto_tree_add_item(tree, hf_cat_ber_tag, tvb, pos, 1, ENC_BIG_ENDIAN);
tag = tvb_get_guint8(tvb, pos++);
len = tvb_get_guint8(tvb, pos++);
subtvb = tvb_new_subset(tvb, pos, len, len);
switch (tag) {
case 0xD0:
call_dissector(sub_handle_cap, subtvb, pinfo, tree);
break;
}
pos += len;
}
}
static int
dissect_gsm_apdu(guint8 ins, guint8 p1, guint8 p2, guint8 p3,
tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
guint8 g8;
guint16 g16;
tvbuff_t *subtvb;
int i;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(ins, apdu_ins_vals, "%02x"));
switch (ins) {
case 0xA4:
if (p3 < 2)
break;
switch (p1) {
case 0x03:
col_append_fstr(pinfo->cinfo, COL_INFO, "Parent DF ");
break;
case 0x04:
col_append_fstr(pinfo->cinfo, COL_INFO, "Application %s ",
tvb_bytes_to_str(tvb, offset+DATA_OFFS, p3));
proto_tree_add_item(tree, hf_aid, tvb, offset+DATA_OFFS, p3, ENC_NA);
break;
case 0x09:
col_append_fstr(pinfo->cinfo, COL_INFO, ".");
case 0x08:
for (i = 0; i < p3; i += 2) {
g16 = tvb_get_ntohs(tvb, offset+DATA_OFFS+i);
col_append_fstr(pinfo->cinfo, COL_INFO, "/%s",
val_to_str(g16, mf_dfs, "%04x"));
proto_tree_add_item(tree, hf_file_id, tvb, offset+DATA_OFFS+i, 2, ENC_BIG_ENDIAN);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " ");
break;
default:
g16 = tvb_get_ntohs(tvb, offset+DATA_OFFS);
col_append_fstr(pinfo->cinfo, COL_INFO, "File %s ",
val_to_str(g16, mf_dfs, "%04x"));
proto_tree_add_item(tree, hf_file_id, tvb, offset+DATA_OFFS, p3, ENC_BIG_ENDIAN);
offset++;
break;
}
break;
case 0xF2:
break;
case 0xB0:
case 0xD6:
col_append_fstr(pinfo->cinfo, COL_INFO, "Offset=%u ", p1 << 8 | p2);
proto_tree_add_item(tree, hf_bin_offset, tvb, offset+P1_OFFS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_apdu_data, tvb, offset+DATA_OFFS, p3, ENC_NA);
break;
case 0xB2:
case 0xDC:
col_append_fstr(pinfo->cinfo, COL_INFO, "RecordNr=%u ", p1);
proto_tree_add_item(tree, hf_record_nr, tvb, offset+P1_OFFS, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_apdu_data, tvb, offset+DATA_OFFS, p3, ENC_NA);
break;
case 0xA2:
proto_tree_add_item(tree, hf_seek_mode, tvb, offset+P2_OFFS, 1, ENC_NA);
proto_tree_add_item(tree, hf_seek_type, tvb, offset+P2_OFFS, 1, ENC_NA);
offset += DATA_OFFS;
proto_tree_add_item(tree, hf_apdu_data, tvb, offset, p3, ENC_NA);
offset += p3;
if ((p2 & 0xF0) == 0x20)
proto_tree_add_item(tree, hf_seek_rec_nr, tvb, offset++, 1, ENC_NA);
break;
case 0x32:
break;
case 0x20:
case 0x24:
case 0x26:
case 0x28:
case 0x2C:
col_append_fstr(pinfo->cinfo, COL_INFO, "CHV=%u ", p2);
offset += DATA_OFFS;
break;
case 0x88:
offset += DATA_OFFS;
proto_tree_add_item(tree, hf_auth_rand, tvb, offset+DATA_OFFS, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_auth_sres, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_auth_kc, tvb, offset, 8, ENC_NA);
offset += 8;
break;
case 0x10:
offset += DATA_OFFS;
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b1, ett_tprof_b1, tprof_b1_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b2, ett_tprof_b2, tprof_b2_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b3, ett_tprof_b3, tprof_b3_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b4, ett_tprof_b4, tprof_b4_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b5, ett_tprof_b5, tprof_b5_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b6, ett_tprof_b6, tprof_b6_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b7, ett_tprof_b7, tprof_b7_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b8, ett_tprof_b8, tprof_b8_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b9, ett_tprof_b9, tprof_b9_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b10, ett_tprof_b10, tprof_b10_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b11, ett_tprof_b11, tprof_b11_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b12, ett_tprof_b12, tprof_b12_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b13, ett_tprof_b13, tprof_b13_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b14, ett_tprof_b14, tprof_b14_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b15, ett_tprof_b15, tprof_b15_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b16, ett_tprof_b16, tprof_b16_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b17, ett_tprof_b17, tprof_b17_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b18, ett_tprof_b18, tprof_b18_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset++, hf_tprof_b19, ett_tprof_b19, tprof_b19_fields, ENC_BIG_ENDIAN);
break;
case 0x12:
subtvb = tvb_new_subset(tvb, offset+DATA_OFFS, p3, p3);
dissect_bertlv(subtvb, pinfo, tree);
break;
case 0x14:
subtvb = tvb_new_subset(tvb, offset+DATA_OFFS, p3, p3);
call_dissector(sub_handle_cap, subtvb, pinfo, tree);
break;
case 0x70:
proto_tree_add_item(tree, hf_chan_op, tvb, offset-3, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "Operation=%s ",
val_to_str(p1, chan_op_vals, "%02x"));
switch (p1) {
case 0x00:
proto_tree_add_item(tree, hf_chan_nr, tvb, offset+DATA_OFFS, 1, ENC_BIG_ENDIAN);
g8 = tvb_get_guint8(tvb, offset+DATA_OFFS);
col_append_fstr(pinfo->cinfo, COL_INFO, "Channel=%d ", g8);
break;
case 0x80:
proto_tree_add_item(tree, hf_chan_nr, tvb, offset-2, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "Channel=%d ", p2);
break;
}
break;
case 0x04:
case 0x44:
default:
return -1;
}
return offset;
}
static int
dissect_apdu_tvb(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
guint8 cla, ins, p1, p2, p3;
guint16 sw;
proto_item *ti;
proto_tree *sim_tree = NULL;
int rc = -1;
guint tvb_len = tvb_length(tvb);
cla = tvb_get_guint8(tvb, offset);
ins = tvb_get_guint8(tvb, offset+1);
p1 = tvb_get_guint8(tvb, offset+2);
p2 = tvb_get_guint8(tvb, offset+3);
p3 = tvb_get_guint8(tvb, offset+4);
if (tree) {
ti = proto_tree_add_item(tree, proto_gsm_sim, tvb, 0, -1, ENC_NA);
sim_tree = proto_item_add_subtree(ti, ett_sim);
proto_tree_add_item(sim_tree, hf_apdu_cla, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_ins, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(cla, apdu_cla_vals, "%02x"));
rc = dissect_gsm_apdu(ins, p1, p2, p3, tvb, offset, pinfo, sim_tree);
if (rc == -1 && sim_tree) {
proto_tree_add_item(sim_tree, hf_apdu_p1, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_p2, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_p3, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_data, tvb, offset+3, p3, ENC_NA);
}
offset += 3;
sw = tvb_get_ntohs(tvb, tvb_len-2);
proto_tree_add_uint_format(sim_tree, hf_apdu_sw, tvb, tvb_len-2, 2, sw,
"Status Word: %04x %s", sw, get_sw_string(sw));
switch (sw >> 8) {
case 0x61:
case 0x90:
case 0x91:
case 0x92:
case 0x9e:
case 0x9f:
break;
default:
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s ", get_sw_string(sw));
break;
}
return offset;
}
static void
dissect_gsm_sim(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_apdu_tvb(tvb, 0, pinfo, tree);
}
void
proto_register_gsm_sim(void)
{
static hf_register_info hf[] = {
{ &hf_apdu_cla,
{ "Class", "iso7816.apdu.cla",
FT_UINT8, BASE_HEX, VALS(apdu_cla_vals), 0,
"ISO 7816-4 APDU CLA (Class) Byte", HFILL }
},
{ &hf_apdu_ins,
{ "Instruction", "iso7816.apdu.ins",
FT_UINT8, BASE_HEX, VALS(apdu_ins_vals), 0,
"ISO 7816-4 APDU INS (Instruction) Byte", HFILL }
},
{ &hf_apdu_p1,
{ "Parameter 1", "iso7816.apdu.p1",
FT_UINT8, BASE_HEX, NULL, 0,
"ISO 7816-4 APDU P1 (Parameter 1) Byte", HFILL }
},
{ &hf_apdu_p2,
{ "Parameter 2", "iso7816.apdu.p2",
FT_UINT8, BASE_HEX, NULL, 0,
"ISO 7816-4 APDU P2 (Parameter 2) Byte", HFILL }
},
{ &hf_apdu_p3,
{ "Length (Parameter 3)", "iso7816.apdu.p3",
FT_UINT8, BASE_HEX, NULL, 0,
"ISO 7816-4 APDU P3 (Parameter 3) Byte", HFILL }
},
{ &hf_apdu_data,
{ "APDU Payload", "iso7816.apdu.data",
FT_BYTES, BASE_NONE, NULL, 0,
"ISO 7816-4 APDU Data Payload", HFILL }
},
{ &hf_apdu_sw,
{ "Status Word (SW1:SW2)", "iso7816.apdu.sw",
FT_UINT16, BASE_HEX, VALS(sw_vals), 0,
"ISO 7816-4 APDU Status Word", HFILL }
},
{ &hf_file_id,
{ "File ID", "iso7816.file_id",
FT_UINT16, BASE_HEX, VALS(mf_dfs), 0,
"ISO 7816-4 File ID", HFILL }
},
{ &hf_aid,
{ "Application ID", "iso7816.aid",
FT_BYTES, BASE_NONE, NULL, 0,
"ISO 7816-4 Application ID", HFILL }
},
{ &hf_bin_offset,
{ "Offset", "iso7816.bin_offset",
FT_UINT16, BASE_DEC, NULL, 0,
"Offset into binary file", HFILL }
},
{ &hf_record_nr,
{ "Record number", "iso7816.record_nr",
FT_UINT8, BASE_DEC, NULL, 0,
"Offset into binary file", HFILL }
},
{ &hf_auth_rand,
{ "Random Challenge", "iso7816.auth_rand",
FT_BYTES, BASE_NONE, NULL, 0,
"GSM Authentication Random Challenge", HFILL }
},
{ &hf_auth_sres,
{ "SRES", "iso7816.auth_sres",
FT_BYTES, BASE_NONE, NULL, 0,
"GSM Authentication SRES Response", HFILL }
},
{ &hf_auth_kc,
{ "Kc", "iso7816.auth_kc",
FT_BYTES, BASE_NONE, NULL, 0,
"GSM Authentication Kc result", HFILL }
},
{ &hf_chan_nr,
{ "Channel Number", "iso7816.chan_nr",
FT_UINT8, BASE_DEC, NULL, 0,
"ISO 7816-4 Logical Channel Number", HFILL }
},
{ &hf_chan_op,
{ "Channel Operation", "iso7816.chan_op",
FT_UINT8, BASE_HEX, VALS(chan_op_vals), 0,
"ISO 7816-4 Logical Channel Operation", HFILL }
},
{ &hf_tprof_b1,
{ "Terminal Profile Byte 1 (Download)", "iso7816.tp.b1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_prof_dld,
{ "Profile Download", "iso7816.tp.prof_dld",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
"TP Profile Downolad", HFILL }
},
{ &hf_tp_sms_data_dld,
{ "SMS-PP Data Download", "iso7816.tp.sms_data_dld",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
"TP SMS-PP Data Downolad", HFILL }
},
{ &hf_tp_cb_data_dld,
{ "CB Data Download", "iso7816.tp.cb_data_dld",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
"TP Cell Broadcast Data Downolad", HFILL }
},
{ &hf_tp_menu_sel,
{ "Menu Selection", "iso7816.tp.menu_sel",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
"TP Menu Selection", HFILL }
},
{ &hf_tp_9e_err,
{ "Menu Selection", "iso7816.tp.9e_err",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
"TP 9EXX response code for SIM data download error", HFILL }
},
{ &hf_tp_timer_exp,
{ "Timer expiration", "iso7816.tp.timer_exp",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
"TP Timer expiration", HFILL }
},
{ &hf_tp_ussd_cc,
{ "USSD string data in Call Control", "iso7816.tp.ussd_cc",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
"TP USSD string data object in Call Control", HFILL }
},
{ &hf_tp_auto_redial,
{ "Envelope CC during automatic redial", "iso7816.tp.auto_redial",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
"TP Envelope CC always sent to SIM during automatic redial", HFILL }
},
{ &hf_tprof_b2,
{ "Terminal Profile Byte 2 (Other)", "iso7816.tp.b2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_cmd_res,
{ "Command result", "iso7816.tp.cmd_res",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
"TP Command result", HFILL }
},
{ &hf_tp_cc_sim,
{ "Call Control by SIM", "iso7816.tp.cc_sim",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
"TP Call Control by SIM", HFILL }
},
{ &hf_tp_cc_sim_cellid,
{ "Cell ID in Call Control by SIM", "iso7816.tp.cc_sim_cellid",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
"TP Cell ID included in Call Control by SIM", HFILL }
},
{ &hf_tp_mo_sms_sim,
{ "MO SMS control by SIM", "iso7816.tp.mo_sms_sim",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
"TP MO short message control by SIM", HFILL }
},
{ &hf_tp_alpha_id,
{ "Alpha identifier according 9.1.3", "iso7816.tp.alpha_id",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
"TP Handling of alpha identifier according to 9.1.3", HFILL }
},
{ &hf_tp_ucs2_entry,
{ "UCS2 Entry", "iso7816.tp.ucs2_entry",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
"TP UCS2 Entry", HFILL }
},
{ &hf_tp_ucs2_display,
{ "UCS2 Display", "iso7816.tp.ucs2_display",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
"TP UCS2 Display", HFILL }
},
{ &hf_tp_display_ext,
{ "Display of Extension Text", "iso7816.tp.display_ext",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
"TP Display of the Extension Text", HFILL }
},
{ &hf_tprof_b3,
{ "Terminal Profile Byte 3 (Proactive SIM)", "iso7816.tp.b3",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_display_text,
{ "Proactive SIM: DISPLAY TEXT", "iso7816.tp.pa.display_text",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_get_inkey,
{ "Proactive SIM: GET INKEY", "iso7816.tp.pa.get_inkey",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_get_input,
{ "Proactive SIM: GET INPUT", "iso7816.tp.pa.get_input",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_more_time,
{ "Proactive SIM: MORE TIME", "iso7816.tp.pa.more_time",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_play_tone,
{ "Proactive SIM: PLAY TONE", "iso7816.tp.pa.play_tone",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_poll_intv,
{ "Proactive SIM: POLL INTERVAL", "iso7816.tp.pa.poll_intv",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_polling_off,
{ "Proactive SIM: POLLING OFF", "iso7816.tp.pa.polling_off",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_refresh,
{ "Proactive SIM: REFRESH", "iso7816.tp.pa.refresh",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b4,
{ "Terminal Profile Byte 4 (Proactive SIM)", "iso7816.tp.b4",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_select_item,
{ "Proactive SIM: SELECT ITEM", "iso7816.tp.pa.select_item",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_send_sms,
{ "Proactive SIM: SEND SHORT MESSAGE", "iso7816.tp.pa.send_sms",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_send_ss,
{ "Proactive SIM: SEND SS", "iso7816.tp.pa.send_ss",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_send_ussd,
{ "Proactive SIM: SEND USSD", "iso7816.tp.pa.send_ussd",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_set_up_call,
{ "Proactive SIM: SET UP CALL", "iso7816.tp.pa.set_up_call",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_set_up_menu,
{ "Proactive SIM: SET UP MENU", "iso7816.tp.pa.set_up_menu",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION", "iso7816.tp.pa.prov_loci",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_nmr,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (NMR)", "iso7816.tp.pa.prov_loci_nmr",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b5,
{ "Terminal Profile Byte 5 (Event driven information)", "iso7816.tp.b5",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_evt_list,
{ "Proactive SIM: SET UP EVENT LIST", "iso7816.tp.pa.set_up_evt_list",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_ev_mt_call,
{ "Event: MT call", "iso7816.tp.evt.mt_call",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_ev_call_connected,
{ "Event: Call connected", "iso7816.tp.evt.call_conn",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_ev_call_disconnected,
{ "Event: Call disconnected", "iso7816.tp.evt.call_disc",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_ev_location_status,
{ "Event: Location status", "iso7816.tp.evt.loc_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_ev_user_activity,
{ "Event: User activity", "iso7816.tp.evt.user_activity",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_ev_idle_screen,
{ "Event: Idle screen available", "iso7816.tp.evt.idle_screen",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_ev_cardreader_status,
{ "Event: Cardreader status", "iso7816.tp.evt.card_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b6,
{ "Terminal Profile Byte 6 (Event driven information extension)", "iso7816.tp.b6",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_ev_lang_sel,
{ "Event: Language Selection", "iso7816.tp.evt.lang_sel",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_ev_brows_term,
{ "Event: Browser Termination", "iso7816.tp.evt.brows_term",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_ev_data_avail,
{ "Event: Data Available", "iso7816.tp.evt.data_avail",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_ev_chan_status,
{ "Event: Channel Status", "iso7816.tp.evt.chan_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tprof_b7,
{ "Terminal Profile Byte 7 (Multiple card proactive commands)", "iso7816.tp.b7",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_power_on,
{ "Proactive SIM: POWER ON CARD", "iso7816.tp.pa.power_on_card",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_power_off,
{ "Proactive SIM: POWER OFF CARD", "iso7816.tp.pa.power_off_card",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_perform_card_apdu,
{ "Proactive SIM: PERFORM CARD APDU", "iso7816.tp.pa.perf_card_apdu",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_get_reader_status,
{ "Proactive SIM: GET READER STATUS (status)", "iso7816.tp.pa.get_rdr_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_get_reader_status_id,
{ "Proactive SIM: GET READER STATUS (identifier)", "iso7816.tp.pa.get_rdr_status_id",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tprof_b8,
{ "Terminal Profile Byte 8 (Proactive SIM)", "iso7816.tp.b8",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_timer_start_stop,
{ "Proactive SIM: TIMER MANAGEMENT (start, stop)", "iso7816.tp.pa.timer_start_stop",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_timer_get_current,
{ "Proactive SIM: TIMER MANAGEMENT (get current value)", "iso7816.tp.pa.timer_get_current",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_date_tz,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (date, time, tz)", "iso7816.tp.pa.prov_loci_date",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_get_inkey_binary,
{ "Proactive SIM: Binary choice in GET INKEY", "iso7816.tp.pa.get_inkey_bin",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_set_up_idle_mode_text,
{ "Proactive SIM: SET UP IDLE MODE TEXT", "iso7816.tp.pa.set_up_idle_text",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_run_at_command,
{ "Proactive SIM: RUN AT COMMAND", "iso7816.tp.pa.run_at_command",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_2nd_alpha_setup_call,
{ "Proactive SIM: 2nd alpha identifier in SET UP CALL", "iso7816.tp.pa.2nd_alpha_id",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_2nd_capability_param,
{ "Proactive SIM: 2nd capability config param", "iso7816.tp.pa.2nd_capa_conf",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b9,
{ "Terminal Profile Byte 9", "iso7816.tp.b9",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tprof_b10,
{ "Terminal Profile Byte 10", "iso7816.tp.b10",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tprof_b11,
{ "Terminal Profile Byte 11", "iso7816.tp.b11",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tprof_b12,
{ "Terminal Profile Byte 12", "iso7816.tp.b12",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_open_chan,
{ "Proactive SIM: OPEN CHANNEL", "iso7816.tp.pa.open_chan",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_close_chan,
{ "Proactive SIM: CLOSE CHANNEL", "iso7816.tp.pa.close_chan",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_recv_data,
{ "Proactive SIM: RECEIVE DATA", "iso7816.tp.pa.recv_data",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_send_data,
{ "Proactive SIM: SEND DATA", "iso7816.tp.pa.send_data",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_get_chan_status,
{ "Proactive SIM: GET CHANNEL STATUS", "iso7816.tp.pa.get_chan_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tprof_b13,
{ "Terminal Profile Byte 13 (Bearer Independent protocol)", "iso7816.tp.b13",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_bip_csd,
{ "CSD bearer", "iso7816.tp.bip.csd",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_bip_gprs,
{ "GPRS bearer", "iso7816.tp.bip.gprs",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_num_chans,
{ "Number of Channels", "iso7816.tp.num_chans",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_tprof_b14,
{ "Terminal Profile Byte 14 (Screen height)", "iso7816.tp.b14",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_char_height,
{ "Display height (chars)", "iso7816.tp.display.height",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL },
},
{ &hf_tp_sizing_supp,
{ "Screen Sizing", "iso7816.tp.disp_sizing",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL },
},
{ &hf_tprof_b15,
{ "Terminal Profile Byte 15 (Screen width)", "iso7816.tp.b15",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_char_width,
{ "Display width (chars)", "iso7816.tp.display.width",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL },
},
{ &hf_tp_var_fonts,
{ "Variable-size fonts", "iso7816.tp.var_fonts",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL },
},
{ &hf_tprof_b16,
{ "Terminal Profile Byte 16 (Screen effects)", "iso7816.tp.b16",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_display_resize,
{ "Display resize", "iso7816.tp.display.resize",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL },
},
{ &hf_tp_text_wrapping,
{ "Text Wrapping", "iso7816.tp.display.wrapping",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL },
},
{ &hf_tp_text_scrolling,
{ "Text Scrolling", "iso7816.tp.display.scrolling",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL },
},
{ &hf_tp_width_red_menu,
{ "Width reduction when in menu", "iso7816.tp.display.width_red_menu",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL },
},
{ &hf_tprof_b17,
{ "Terminal Profile Byte 17 (Bearer independent protocol)", "iso7816.tp.b17",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_bip_tcp,
{ "TCP transport", "iso7816.tp.bip.tcp",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_bip_udp,
{ "UDP transport", "iso7816.tp.bip.udp",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tprof_b18,
{ "Terminal Profile Byte 18 (Bearer independent protocol)", "iso7816.tp.b18",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tprof_b19,
{ "Terminal Profile Byte 19", "iso7816.tp.b19",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_tia_eia_version,
{ "TIA/EIA Version", "iso7816.tp.tia_eia_version",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_cat_ber_tag,
{ "BER-TLV Tag", "cat.ber_tlv_tag",
FT_UINT8, BASE_HEX, VALS(ber_tlv_cat_tag_vals), 0,
"Card Application Toolkit BER-TLV tag", HFILL },
},
{ &hf_seek_mode,
{ "Seek Mode", "iso7816.seek_mode",
FT_UINT8, BASE_HEX, VALS(seek_mode_vals), 0x0F,
NULL, HFILL },
},
{ &hf_seek_type,
{ "Seek Type", "iso7816.seek_type",
FT_UINT8, BASE_DEC, VALS(seek_type_vals), 0x0F,
NULL, HFILL },
},
{ &hf_seek_rec_nr,
{ "Seek Record Number", "iso7816.seek_rec_nr",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL },
},
};
static gint *ett[] = {
&ett_sim,
&ett_tprof_b1,
&ett_tprof_b2,
&ett_tprof_b3,
&ett_tprof_b4,
&ett_tprof_b5,
&ett_tprof_b6,
&ett_tprof_b7,
&ett_tprof_b8,
&ett_tprof_b9,
&ett_tprof_b10,
&ett_tprof_b11,
&ett_tprof_b12,
&ett_tprof_b13,
&ett_tprof_b14,
&ett_tprof_b15,
&ett_tprof_b16,
&ett_tprof_b17,
&ett_tprof_b18,
&ett_tprof_b19,
};
proto_gsm_sim = proto_register_protocol("GSM SIM 11.11", "GSM SIM",
"gsm_sim");
proto_register_field_array(proto_gsm_sim, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gsm_sim", dissect_gsm_sim, proto_gsm_sim);
}
void
proto_reg_handoff_gsm_sim(void)
{
static gboolean initialized = FALSE;
if (!initialized) {
dissector_handle_t dtap_handle;
dtap_handle = find_dissector("gsm_sim");
dissector_add_uint("gsmtap.type", 4, dtap_handle);
sub_handle_cap = find_dissector("etsi_cat");
} else {
}
}
