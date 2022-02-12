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
return "Technical problem with no diagnostic";
}
return val_to_str(sw, sw_vals, "%04x");
}
static int
dissect_bertlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
unsigned int pos = 0;
while (pos < tvb_reported_length(tvb)) {
guint8 tag;
guint32 len;
tvbuff_t *subtvb;
proto_tree_add_item(tree, hf_cat_ber_tag, tvb, pos, 1, ENC_BIG_ENDIAN);
tag = tvb_get_guint8(tvb, pos++);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(tag, ber_tlv_cat_tag_vals, "%02x "));
len = tvb_get_guint8(tvb, pos++);
switch (len) {
case 0x81:
len = tvb_get_guint8(tvb, pos++);
break;
case 0x82:
len = tvb_get_ntohs(tvb, pos);
pos += 2;
break;
case 0x83:
len = tvb_get_ntoh24(tvb, pos);
pos += 3;
break;
default:
break;
}
subtvb = tvb_new_subset_length(tvb, pos, len);
switch (tag) {
case 0xD0:
case 0xD1:
case 0xD6:
case 0xD7:
call_dissector_with_data(sub_handle_cap, subtvb, pinfo, tree, GUINT_TO_POINTER((guint)tag));
break;
}
pos += len;
}
return tvb_captured_length(tvb);
}
static int
dissect_gsm_apdu(guint8 ins, guint8 p1, guint8 p2, guint8 p3, tvbuff_t *tvb,
int offset, packet_info *pinfo, proto_tree *tree, gboolean isSIMtrace)
{
guint8 g8;
guint16 g16;
tvbuff_t *subtvb;
int i, start_offset;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(ins, apdu_ins_vals, "%02x"));
switch (ins) {
case 0xA4:
if (p3 < 2)
break;
switch (p1) {
case 0x03:
col_append_str(pinfo->cinfo, COL_INFO, "Parent DF ");
break;
case 0x04:
col_append_fstr(pinfo->cinfo, COL_INFO, "Application %s ",
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset+DATA_OFFS, p3));
proto_tree_add_item(tree, hf_aid, tvb, offset+DATA_OFFS, p3, ENC_NA);
break;
case 0x09:
col_append_str(pinfo->cinfo, COL_INFO, ".");
case 0x08:
for (i = 0; i < p3; i += 2) {
g16 = tvb_get_ntohs(tvb, offset+DATA_OFFS+i);
col_append_fstr(pinfo->cinfo, COL_INFO, "/%s",
val_to_str(g16, mf_dfs, "%04x"));
proto_tree_add_item(tree, hf_file_id, tvb, offset+DATA_OFFS+i, 2, ENC_BIG_ENDIAN);
}
col_append_str(pinfo->cinfo, COL_INFO, " ");
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
col_append_fstr(pinfo->cinfo, COL_INFO, "Offset=%u ", p1 << 8 | p2);
proto_tree_add_item(tree, hf_bin_offset, tvb, offset+P1_OFFS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_le, tvb, offset+P3_OFFS, 1, ENC_BIG_ENDIAN);
if (isSIMtrace) {
proto_tree_add_item(tree, hf_apdu_data, tvb, offset+DATA_OFFS, p3, ENC_NA);
}
break;
case 0xD6:
col_append_fstr(pinfo->cinfo, COL_INFO, "Offset=%u ", p1 << 8 | p2);
proto_tree_add_item(tree, hf_bin_offset, tvb, offset+P1_OFFS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_apdu_data, tvb, offset+DATA_OFFS, p3, ENC_NA);
break;
case 0xB2:
col_append_fstr(pinfo->cinfo, COL_INFO, "RecordNr=%u ", p1);
proto_tree_add_item(tree, hf_record_nr, tvb, offset+P1_OFFS, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_le, tvb, offset+P3_OFFS, 1, ENC_BIG_ENDIAN);
if (isSIMtrace) {
proto_tree_add_item(tree, hf_apdu_data, tvb, offset+DATA_OFFS, p3, ENC_NA);
}
break;
case 0xDC:
col_append_fstr(pinfo->cinfo, COL_INFO, "RecordNr=%u ", p1);
proto_tree_add_item(tree, hf_record_nr, tvb, offset+P1_OFFS, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_apdu_data, tvb, offset+DATA_OFFS, p3, ENC_NA);
break;
case 0xA2:
proto_tree_add_item(tree, hf_seek_mode, tvb, offset+P2_OFFS, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_seek_type, tvb, offset+P2_OFFS, 1, ENC_BIG_ENDIAN);
offset += DATA_OFFS;
proto_tree_add_item(tree, hf_apdu_data, tvb, offset, p3, ENC_NA);
offset += p3;
if ((p2 & 0xF0) == 0x20)
proto_tree_add_item(tree, hf_seek_rec_nr, tvb, offset++, 1, ENC_BIG_ENDIAN);
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
proto_tree_add_item(tree, hf_auth_rand, tvb, offset, 16, ENC_NA);
offset += 16;
if (isSIMtrace) {
proto_tree_add_item(tree, hf_auth_sres, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_auth_kc, tvb, offset, 8, ENC_NA);
offset += 8;
}
break;
case 0x10:
offset += DATA_OFFS;
start_offset = offset;
ADD_TP_BYTE(1);
ADD_TP_BYTE(2);
ADD_TP_BYTE(3);
ADD_TP_BYTE(4);
ADD_TP_BYTE(5);
ADD_TP_BYTE(6);
ADD_TP_BYTE(7);
ADD_TP_BYTE(8);
ADD_TP_BYTE(9);
ADD_TP_BYTE(10);
ADD_TP_BYTE(11);
ADD_TP_BYTE(12);
ADD_TP_BYTE(13);
ADD_TP_BYTE(14);
ADD_TP_BYTE(15);
ADD_TP_BYTE(16);
ADD_TP_BYTE(17);
ADD_TP_BYTE(18);
ADD_TP_BYTE(19);
ADD_TP_BYTE(20);
ADD_TP_BYTE(21);
ADD_TP_BYTE(22);
ADD_TP_BYTE(23);
ADD_TP_BYTE(24);
ADD_TP_BYTE(25);
ADD_TP_BYTE(26);
ADD_TP_BYTE(27);
ADD_TP_BYTE(28);
ADD_TP_BYTE(29);
ADD_TP_BYTE(30);
ADD_TP_BYTE(31);
ADD_TP_BYTE(32);
ADD_TP_BYTE(33);
while ((offset - start_offset) < p3) {
proto_tree_add_item(tree, hf_tprof_unknown_byte, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
break;
case 0x12:
proto_tree_add_item(tree, hf_le, tvb, offset+P3_OFFS, 1, ENC_BIG_ENDIAN);
if (isSIMtrace) {
subtvb = tvb_new_subset_length(tvb, offset+DATA_OFFS, (p3 == 0) ? 256 : p3);
dissect_bertlv(subtvb, pinfo, tree, NULL);
}
break;
case 0x14:
subtvb = tvb_new_subset_length(tvb, offset+DATA_OFFS, p3);
call_dissector_with_data(sub_handle_cap, subtvb, pinfo, tree, GUINT_TO_POINTER(0x14));
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
case 0xC0:
proto_tree_add_item(tree, hf_le, tvb, offset+P3_OFFS, 1, ENC_BIG_ENDIAN);
if (isSIMtrace) {
proto_tree_add_item(tree, hf_apdu_data, tvb, offset+DATA_OFFS, p3, ENC_NA);
}
break;
case 0xC2:
proto_tree_add_item(tree, hf_le, tvb, offset+P3_OFFS, 1, ENC_BIG_ENDIAN);
subtvb = tvb_new_subset_length(tvb, offset+DATA_OFFS, p3);
dissect_bertlv(subtvb, pinfo, tree, NULL);
break;
case 0x04:
case 0x44:
default:
return -1;
}
return offset;
}
static gint
dissect_rsp_apdu_tvb(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree, proto_tree *sim_tree)
{
guint16 sw;
proto_item *ti;
guint tvb_len = tvb_reported_length(tvb);
if (tree && !sim_tree) {
ti = proto_tree_add_item(tree, proto_gsm_sim, tvb, 0, -1, ENC_NA);
sim_tree = proto_item_add_subtree(ti, ett_sim);
}
if ((tvb_len-offset) > 2) {
proto_tree_add_item(sim_tree, hf_apdu_data, tvb, offset, tvb_len - 2, ENC_NA);
}
offset = tvb_len - 2;
sw = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(sim_tree, hf_apdu_sw, tvb, offset, 2, sw,
"Status Word: %04x %s", sw, get_sw_string(sw));
offset += 2;
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
static gint
dissect_cmd_apdu_tvb(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree, gboolean isSIMtrace)
{
guint8 cla, ins, p1, p2, p3;
proto_item *ti;
proto_tree *sim_tree = NULL;
gint rc = -1;
guint tvb_len = tvb_reported_length(tvb);
cla = tvb_get_guint8(tvb, offset);
ins = tvb_get_guint8(tvb, offset+1);
p1 = tvb_get_guint8(tvb, offset+2);
p2 = tvb_get_guint8(tvb, offset+3);
p3 = tvb_get_guint8(tvb, offset+4);
if (tree) {
ti = proto_tree_add_item(tree, proto_gsm_sim, tvb, 0, -1, ENC_NA);
sim_tree = proto_item_add_subtree(ti, ett_sim);
if ((cla & 0x50) == 0x40) {
proto_tree_add_item(sim_tree, hf_apdu_cla_coding_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_cla_secure_messaging_ind_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_cla_log_chan_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(sim_tree, hf_apdu_cla_coding, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_cla_secure_messaging_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_cla_log_chan, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(sim_tree, hf_apdu_ins, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
offset += 2;
if ((cla & 0x50) == 0x40) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(cla>>6, apdu_cla_coding_ext_vals, "%01x"));
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(cla>>4, apdu_cla_coding_vals, "%01x"));
}
rc = dissect_gsm_apdu(ins, p1, p2, p3, tvb, offset, pinfo, sim_tree, isSIMtrace);
if (rc == -1 && sim_tree) {
proto_tree_add_item(sim_tree, hf_apdu_p1, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_p2, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sim_tree, hf_apdu_p3, tvb, offset+2, 1, ENC_BIG_ENDIAN);
if (p3 && (p3 <= tvb_reported_length_remaining(tvb, offset+3))) {
proto_tree_add_item(sim_tree, hf_apdu_data, tvb, offset+3, p3, ENC_NA);
}
}
offset += 3+p3;
if (isSIMtrace) {
return dissect_rsp_apdu_tvb(tvb, tvb_len-2, pinfo, tree, sim_tree);
}
return offset;
}
static int
dissect_gsm_sim(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM SIM");
dissect_cmd_apdu_tvb(tvb, 0, pinfo, tree, TRUE);
return tvb_captured_length(tvb);
}
static int
dissect_gsm_sim_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM SIM");
dissect_cmd_apdu_tvb(tvb, 0, pinfo, tree, FALSE);
return tvb_captured_length(tvb);
}
static int
dissect_gsm_sim_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM SIM");
dissect_rsp_apdu_tvb(tvb, 0, pinfo, tree, NULL);
return tvb_captured_length(tvb);
}
void
proto_register_gsm_sim(void)
{
static hf_register_info hf[] = {
{ &hf_apdu_cla_coding,
{ "Class Coding", "gsm_sim.apdu.cla.coding",
FT_UINT8, BASE_HEX, VALS(apdu_cla_coding_vals), 0xf0,
"ISO 7816-4 APDU CLA (Class) Byte", HFILL }
},
{ &hf_apdu_cla_coding_ext,
{ "Class Coding", "gsm_sim.apdu.cla.coding",
FT_UINT8, BASE_HEX, VALS(apdu_cla_coding_ext_vals), 0xc0,
"ISO 7816-4 APDU CLA (Class) Byte", HFILL }
},
{ &hf_apdu_cla_secure_messaging_ind,
{ "Secure Messaging Indication", "gsm_sim.apdu.cla.secure_messaging_ind",
FT_UINT8, BASE_HEX, VALS(apdu_cla_secure_messaging_ind_vals), 0x0c,
"ISO 7816-4 APDU CLA (Class) Byte", HFILL }
},
{ &hf_apdu_cla_secure_messaging_ind_ext,
{ "Secure Messaging Indication", "gsm_sim.apdu.cla.secure_messaging_ind",
FT_BOOLEAN, 8, TFS(&apdu_cla_secure_messaging_ind_ext_val), 0x20,
"ISO 7816-4 APDU CLA (Class) Byte", HFILL }
},
{ &hf_apdu_cla_log_chan,
{ "Logical Channel number", "gsm_sim.apdu.cla.log_chan",
FT_UINT8, BASE_DEC, NULL, 0x03,
"ISO 7816-4 APDU CLA (Class) Byte", HFILL }
},
{ &hf_apdu_cla_log_chan_ext,
{ "Logical Channel number", "gsm_sim.apdu.cla.log_chan",
FT_UINT8, BASE_DEC, NULL, 0x0f,
"ISO 7816-4 APDU CLA (Class) Byte", HFILL }
},
{ &hf_apdu_ins,
{ "Instruction", "gsm_sim.apdu.ins",
FT_UINT8, BASE_HEX, VALS(apdu_ins_vals), 0,
"ISO 7816-4 APDU INS (Instruction) Byte", HFILL }
},
{ &hf_apdu_p1,
{ "Parameter 1", "gsm_sim.apdu.p1",
FT_UINT8, BASE_HEX, NULL, 0,
"ISO 7816-4 APDU P1 (Parameter 1) Byte", HFILL }
},
{ &hf_apdu_p2,
{ "Parameter 2", "gsm_sim.apdu.p2",
FT_UINT8, BASE_HEX, NULL, 0,
"ISO 7816-4 APDU P2 (Parameter 2) Byte", HFILL }
},
{ &hf_apdu_p3,
{ "Length (Parameter 3)", "gsm_sim.apdu.p3",
FT_UINT8, BASE_HEX, NULL, 0,
"ISO 7816-4 APDU P3 (Parameter 3) Byte", HFILL }
},
{ &hf_apdu_data,
{ "APDU Payload", "gsm_sim.apdu.data",
FT_BYTES, BASE_NONE, NULL, 0,
"ISO 7816-4 APDU Data Payload", HFILL }
},
{ &hf_apdu_sw,
{ "Status Word (SW1:SW2)", "gsm_sim.apdu.sw",
FT_UINT16, BASE_HEX, VALS(sw_vals), 0,
"ISO 7816-4 APDU Status Word", HFILL }
},
{ &hf_file_id,
{ "File ID", "gsm_sim.file_id",
FT_UINT16, BASE_HEX, VALS(mf_dfs), 0,
"ISO 7816-4 File ID", HFILL }
},
{ &hf_aid,
{ "Application ID", "gsm_sim.aid",
FT_BYTES, BASE_NONE, NULL, 0,
"ISO 7816-4 Application ID", HFILL }
},
{ &hf_bin_offset,
{ "Offset", "gsm_sim.bin_offset",
FT_UINT16, BASE_DEC, NULL, 0,
"Offset into binary file", HFILL }
},
{ &hf_record_nr,
{ "Record number", "gsm_sim.record_nr",
FT_UINT8, BASE_DEC, NULL, 0,
"Offset into binary file", HFILL }
},
{ &hf_auth_rand,
{ "Random Challenge", "gsm_sim.auth_rand",
FT_BYTES, BASE_NONE, NULL, 0,
"GSM Authentication Random Challenge", HFILL }
},
{ &hf_auth_sres,
{ "SRES", "gsm_sim.auth_sres",
FT_BYTES, BASE_NONE, NULL, 0,
"GSM Authentication SRES Response", HFILL }
},
{ &hf_auth_kc,
{ "Kc", "gsm_sim.auth_kc",
FT_BYTES, BASE_NONE, NULL, 0,
"GSM Authentication Kc result", HFILL }
},
{ &hf_chan_nr,
{ "Channel Number", "gsm_sim.chan_nr",
FT_UINT8, BASE_DEC, NULL, 0,
"ISO 7816-4 Logical Channel Number", HFILL }
},
{ &hf_le,
{ "Length of Expected Response Data", "gsm_sim.le",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_chan_op,
{ "Channel Operation", "gsm_sim.chan_op",
FT_UINT8, BASE_HEX, VALS(chan_op_vals), 0,
"ISO 7816-4 Logical Channel Operation", HFILL }
},
{ &hf_tprof_b1,
{ "Terminal Profile Byte 1 (Download)", "gsm_sim.tp.b1",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_prof_dld,
{ "Profile Download", "gsm_sim.tp.prof_dld",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
"TP Profile Download", HFILL }
},
{ &hf_tp_sms_data_dld,
{ "SMS-PP Data Download", "gsm_sim.tp.sms_data_dld",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
"TP SMS-PP Data Download", HFILL }
},
{ &hf_tp_cb_data_dld,
{ "CB Data Download", "gsm_sim.tp.cb_data_dld",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
"TP Cell Broadcast Data Downolad", HFILL }
},
{ &hf_tp_menu_sel,
{ "Menu Selection", "gsm_sim.tp.menu_sel",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
"TP Menu Selection", HFILL }
},
{ &hf_tp_sms_data_dld_support,
{ "SMS-PP data download is supported", "gsm_sim.tp.sms_data_dld_support",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
"TP SMS-PP data download is supported", HFILL }
},
{ &hf_tp_timer_exp,
{ "Timer expiration", "gsm_sim.tp.timer_exp",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
"TP Timer expiration", HFILL }
},
{ &hf_tp_cc_sim_support,
{ "Call Control by USIM is supported", "gsm_sim.tp.cc_sim_support",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
"TP Call Control by USIM is supported", HFILL }
},
{ &hf_tp_cc_sim_support2,
{ "Call Control by USIM is supported", "gsm_sim.tp.cc_sim_support",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
"TP Call Control by USIM is supported", HFILL }
},
{ &hf_tprof_b2,
{ "Terminal Profile Byte 2 (Other)", "gsm_sim.tp.b2",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_cmd_res,
{ "Command result", "gsm_sim.tp.cmd_res",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
"TP Command result", HFILL }
},
{ &hf_tp_cc_sim,
{ "Call Control by USIM", "gsm_sim.tp.cc_sim",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
"TP Call Control by SIM", HFILL }
},
{ &hf_tp_cc_sim_support3,
{ "Call Control by USIM is supported", "gsm_sim.tp.cc_sim_support",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
"TP Call Control by USIM is supported", HFILL }
},
{ &hf_tp_mo_sms_sim,
{ "MO SMS control by SIM", "gsm_sim.tp.mo_sms_sim",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
"TP MO short message control by SIM", HFILL }
},
{ &hf_tp_cc_sim_support4,
{ "Call Control by USIM is supported", "gsm_sim.tp.cc_sim_support",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
"TP Call Control by USIM is supported", HFILL }
},
{ &hf_tp_ucs2_entry,
{ "UCS2 Entry", "gsm_sim.tp.ucs2_entry",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
"TP UCS2 Entry", HFILL }
},
{ &hf_tp_ucs2_display,
{ "UCS2 Display", "gsm_sim.tp.ucs2_display",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
"TP UCS2 Display", HFILL }
},
{ &hf_tp_display_ext,
{ "Display of Extension Text", "gsm_sim.tp.display_ext",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
"TP Display of the Extension Text", HFILL }
},
{ &hf_tprof_b3,
{ "Terminal Profile Byte 3 (Proactive SIM)", "gsm_sim.tp.b3",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_display_text,
{ "Proactive SIM: DISPLAY TEXT", "gsm_sim.tp.pa.display_text",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_get_inkey,
{ "Proactive SIM: GET INKEY", "gsm_sim.tp.pa.get_inkey",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_get_input,
{ "Proactive SIM: GET INPUT", "gsm_sim.tp.pa.get_input",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_more_time,
{ "Proactive SIM: MORE TIME", "gsm_sim.tp.pa.more_time",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_play_tone,
{ "Proactive SIM: PLAY TONE", "gsm_sim.tp.pa.play_tone",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_poll_intv,
{ "Proactive SIM: POLL INTERVAL", "gsm_sim.tp.pa.poll_intv",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_polling_off,
{ "Proactive SIM: POLLING OFF", "gsm_sim.tp.pa.polling_off",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_refresh,
{ "Proactive SIM: REFRESH", "gsm_sim.tp.pa.refresh",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b4,
{ "Terminal Profile Byte 4 (Proactive SIM)", "gsm_sim.tp.b4",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_select_item,
{ "Proactive SIM: SELECT ITEM", "gsm_sim.tp.pa.select_item",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_send_sms,
{ "Proactive SIM: SEND SHORT MESSAGE", "gsm_sim.tp.pa.send_sms",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_send_ss,
{ "Proactive SIM: SEND SS", "gsm_sim.tp.pa.send_ss",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_send_ussd,
{ "Proactive SIM: SEND USSD", "gsm_sim.tp.pa.send_ussd",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_set_up_call,
{ "Proactive SIM: SET UP CALL", "gsm_sim.tp.pa.set_up_call",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_set_up_menu,
{ "Proactive SIM: SET UP MENU", "gsm_sim.tp.pa.set_up_menu",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION", "gsm_sim.tp.pa.prov_loci",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_nmr,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (NMR)", "gsm_sim.tp.pa.prov_loci_nmr",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b5,
{ "Terminal Profile Byte 5 (Event driven information)", "gsm_sim.tp.b5",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_evt_list,
{ "Proactive SIM: SET UP EVENT LIST", "gsm_sim.tp.pa.set_up_evt_list",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_ev_mt_call,
{ "Event: MT call", "gsm_sim.tp.evt.mt_call",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_ev_call_connected,
{ "Event: Call connected", "gsm_sim.tp.evt.call_conn",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_ev_call_disconnected,
{ "Event: Call disconnected", "gsm_sim.tp.evt.call_disc",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_ev_location_status,
{ "Event: Location status", "gsm_sim.tp.evt.loc_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_ev_user_activity,
{ "Event: User activity", "gsm_sim.tp.evt.user_activity",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_ev_idle_screen,
{ "Event: Idle screen available", "gsm_sim.tp.evt.idle_screen",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_ev_cardreader_status,
{ "Event: Card reader status", "gsm_sim.tp.evt.card_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b6,
{ "Terminal Profile Byte 6 (Event driven information extension)", "gsm_sim.tp.b6",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_ev_lang_sel,
{ "Event: Language Selection", "gsm_sim.tp.evt.lang_sel",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_ev_brows_term,
{ "Event: Browser Termination", "gsm_sim.tp.evt.brows_term",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_ev_data_avail,
{ "Event: Data Available", "gsm_sim.tp.evt.data_avail",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_ev_chan_status,
{ "Event: Channel Status", "gsm_sim.tp.evt.chan_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_ev_access_techno_change,
{ "Event: Access Technology Change", "gsm_sim.tp.evt.access_techno_change",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_ev_disp_params_changed,
{ "Event: Display parameters changed", "gsm_sim.tp.evt.disp_params_changed",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_ev_local_conn,
{ "Event: Local Connection", "gsm_sim.tp.evt.local_conn",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_ev_nwk_search_mode_change,
{ "Event: Network Search Mode Change", "gsm_sim.tp.evt.nwk_search_mode_change",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b7,
{ "Terminal Profile Byte 7 (Multiple card proactive commands)", "gsm_sim.tp.b7",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_power_on,
{ "Proactive SIM: POWER ON CARD", "gsm_sim.tp.pa.power_on_card",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_power_off,
{ "Proactive SIM: POWER OFF CARD", "gsm_sim.tp.pa.power_off_card",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_perform_card_apdu,
{ "Proactive SIM: PERFORM CARD APDU", "gsm_sim.tp.pa.perf_card_apdu",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_get_reader_status,
{ "Proactive SIM: GET READER STATUS (status)", "gsm_sim.tp.pa.get_rdr_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_get_reader_status_id,
{ "Proactive SIM: GET READER STATUS (identifier)", "gsm_sim.tp.pa.get_rdr_status_id",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_rfu,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0xe0,
NULL, HFILL },
},
{ &hf_tprof_b8,
{ "Terminal Profile Byte 8 (Proactive SIM)", "gsm_sim.tp.b8",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_timer_start_stop,
{ "Proactive SIM: TIMER MANAGEMENT (start, stop)", "gsm_sim.tp.pa.timer_start_stop",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_timer_get_current,
{ "Proactive SIM: TIMER MANAGEMENT (get current value)", "gsm_sim.tp.pa.timer_get_current",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_date_tz,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (date, time, tz)", "gsm_sim.tp.pa.prov_loci_date",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_get_inkey_binary,
{ "Proactive SIM: GET INKEY", "gsm_sim.tp.pa.get_inkey_bin",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_set_up_idle_mode_text,
{ "Proactive SIM: SET UP IDLE MODE TEXT", "gsm_sim.tp.pa.set_up_idle_text",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_run_at_command,
{ "Proactive SIM: RUN AT COMMAND", "gsm_sim.tp.pa.run_at_command",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_2nd_alpha_setup_call,
{ "Proactive SIM: SETUP CALL", "gsm_sim.tp.pa.2nd_alpha_id",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_2nd_cc_sim_support,
{ "Proactive SIM: Call Control by USIM is supported", "gsm_sim.tp.pa.cc_sim_support",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b9,
{ "Terminal Profile Byte 9", "gsm_sim.tp.b9",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_display_text,
{ "DISPLAY TEXT", "gsm_sim.tp.display_text",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_send_dtmf_cmd,
{ "SEND DTMF command", "gsm_sim.tp.send_dtmf_cmd",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_nmr2,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (NMR)", "gsm_sim.tp.pa.prov_loci_nmr",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_lang,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (language)", "gsm_sim.tp.pa.prov_loci_lang",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_ta,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (Timing Advance)", "gsm_sim.tp.pa.prov_loci_ta",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_lang_notif,
{ "Proactive SIM: LANGUAGE NOTIFICATION", "gsm_sim.tp.pa.lang_notif",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_launch_browser,
{ "Proactive SIM: LAUNCH BROWSER", "gsm_sim.tp.pa.launch_browser",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_access_techno,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (Access Technology)", "gsm_sim.tp.pa.prov_loci_access_techno",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b10,
{ "Terminal Profile Byte 10 (Soft keys support)", "gsm_sim.tp.b10",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_soft_key_support_select_item,
{ "Soft keys support for SELECT ITEM", "gsm_sim.tp.soft_key_support.select_item",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_soft_key_support_set_up_menu,
{ "Soft Keys support for SET UP MENU", "gsm_sim.tp.soft_key_support.set_up_menu",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_rfu2,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0xfc,
NULL, HFILL },
},
{ &hf_tprof_b11,
{ "Terminal Profile Byte 11 (Soft keys information)", "gsm_sim.tp.b11",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_soft_key_info_max_nb,
{ "Maximum number of soft keys available", "gsm_sim.tp.soft_key_info.max_nb",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_tprof_b12,
{ "Terminal Profile Byte 12 (Bearer Independent protocol proactive commands, class \"e\")", "gsm_sim.tp.b12",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_open_chan,
{ "Proactive SIM: OPEN CHANNEL", "gsm_sim.tp.pa.open_chan",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_close_chan,
{ "Proactive SIM: CLOSE CHANNEL", "gsm_sim.tp.pa.close_chan",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_recv_data,
{ "Proactive SIM: RECEIVE DATA", "gsm_sim.tp.pa.recv_data",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_send_data,
{ "Proactive SIM: SEND DATA", "gsm_sim.tp.pa.send_data",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_get_chan_status,
{ "Proactive SIM: GET CHANNEL STATUS", "gsm_sim.tp.pa.get_chan_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_serv_search,
{ "Proactive SIM: SERVICE SEARCH", "gsm_sim.tp.pa.serv_search",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_get_serv_info,
{ "Proactive SIM: GET SERVICE INFORMATION", "gsm_sim.tp.pa.get_serv_info",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_decl_serv,
{ "Proactive SIM: DECLARE SERVICE", "gsm_sim.tp.pa.decl_serv",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b13,
{ "Terminal Profile Byte 13 (Bearer Independent protocol supported bearers, class \"e\")", "gsm_sim.tp.b13",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_bip_csd,
{ "CSD bearer", "gsm_sim.tp.bip.csd",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_bip_gprs,
{ "GPRS bearer", "gsm_sim.tp.bip.gprs",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_bip_bluetooth,
{ "Bluetooth bearer", "gsm_sim.tp.bip.bluetooth",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_bip_irda,
{ "IrDA bearer", "gsm_sim.tp.bip.irda",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_bip_rs232,
{ "RS232 bearer", "gsm_sim.tp.bip.rs232",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_num_chans,
{ "Number of Channels", "gsm_sim.tp.num_chans",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_tprof_b14,
{ "Terminal Profile Byte 14 (Screen height)", "gsm_sim.tp.b14",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_char_height,
{ "Display height (chars)", "gsm_sim.tp.display.height",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL },
},
{ &hf_tp_nd,
{ "No display capability", "gsm_sim.tp.nd",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL },
},
{ &hf_tp_nk,
{ "No keypad available", "gsm_sim.tp.nk",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL },
},
{ &hf_tp_sizing_supp,
{ "Screen sizing parameters", "gsm_sim.tp.disp_sizing",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL },
},
{ &hf_tprof_b15,
{ "Terminal Profile Byte 15 (Screen width)", "gsm_sim.tp.b15",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_char_width,
{ "Display width (chars)", "gsm_sim.tp.display.width",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL },
},
{ &hf_tp_var_fonts,
{ "Variable size fonts", "gsm_sim.tp.var_fonts",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL },
},
{ &hf_tprof_b16,
{ "Terminal Profile Byte 16 (Screen effects)", "gsm_sim.tp.b16",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_display_resize,
{ "Display resize", "gsm_sim.tp.display.resize",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL },
},
{ &hf_tp_text_wrapping,
{ "Text Wrapping", "gsm_sim.tp.display.wrapping",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL },
},
{ &hf_tp_text_scrolling,
{ "Text Scrolling", "gsm_sim.tp.display.scrolling",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL },
},
{ &hf_tp_text_attributes,
{ "Text Attributes", "gsm_sim.tp.display.attributes",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL },
},
{ &hf_tp_rfu3,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0x10,
NULL, HFILL },
},
{ &hf_tp_width_red_menu,
{ "Width reduction when in menu", "gsm_sim.tp.display.width_red_menu",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL },
},
{ &hf_tprof_b17,
{ "Terminal Profile Byte 17 (Bearer independent protocol supported transport interface/bearers, class \"e\")", "gsm_sim.tp.b17",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_bip_tcp_remote,
{ "TCP client mode remote connection", "gsm_sim.tp.bip.tcp_remote",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_bip_udp_remote,
{ "UDP client mode remote connection", "gsm_sim.tp.bip.udp_remote",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_bip_tcp_server,
{ "TCP server mode", "gsm_sim.tp.bip.tcp_server",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_bip_tcp_local,
{ "TCP client mode local connection", "gsm_sim.tp.bip.tcp_local",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_bip_udp_local,
{ "UDP client mode local connection", "gsm_sim.tp.bip.udp_local",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_bip_direct_com,
{ "Direct communication channel", "gsm_sim.tp.bip.direct_com",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_bip_eutran,
{ "E-UTRAN bearer", "gsm_sim.tp.bip.eutran",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_bip_hsdpa,
{ "HSDPA bearer", "gsm_sim.tp.bip.hsdpa",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b18,
{ "Terminal Profile Byte 18 (Bearer independent protocol)", "gsm_sim.tp.b18",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_display_text_var_time_out,
{ "Proactive SIM: DISPLAY TEXT (Variable Time out)", "gsm_sim.tp.pa.display_text_var_time_out",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_get_inkey_help,
{ "Proactive SIM: GET INKEY (help is supported)", "gsm_sim.tp.pa.get_inkey_help",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_bip_usb,
{ "USB bearer", "gsm_sim.tp.bip.usb",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_pa_get_inkey_var_time_out,
{ "Proactive SIM: GET INKEY (Variable Timeout)", "gsm_sim.tp.pa.get_inkey_var_time_out",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_esn,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (ESN)", "gsm_sim.tp.pa.prov_loci_esn",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_cc_gprs,
{ "CALL CONTROL on GPRS", "gsm_sim.tp.cc_gprs",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_imeisv,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (IMEISV)", "gsm_sim.tp.pa.prov_loci_imeisv",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_search_mode_change,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (Search Mode change)", "gsm_sim.tp.pa.prov_loci_search_mode_change",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b19,
{ "Terminal Profile Byte 19 (TIA/EIA-136-C facilities)", "gsm_sim.tp.b19",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_tia_eia_version,
{ "TIA/EIA Version", "gsm_sim.tp.tia_eia_version",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_tp_rfu4,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL },
},
{ &hf_tprof_b20,
{ "Terminal Profile Byte 20 (TIA/EIA/IS-820-A facilities)", "gsm_sim.tp.b20",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_tia_iea_is820a_reserved,
{ "Reserved", "gsm_sim.tp.tia_iea_is820a_reserved",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL }
},
{ &hf_tprof_b21,
{ "Terminal Profile Byte 21 (Extended Launch Browser Capability)", "gsm_sim.tp.b21",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_ext_launch_browser_wml,
{ "WML", "gsm_sim.tp.ext_launch_browser.wml",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_ext_launch_browser_xhtml,
{ "XHTML", "gsm_sim.tp.ext_launch_browser.xhtml",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_ext_launch_browser_html,
{ "HTML", "gsm_sim.tp.ext_launch_browser.html",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_ext_launch_browser_chtml,
{ "CHTML", "gsm_sim.tp.ext_launch_browser.chtml",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_rfu5,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL },
},
{ &hf_tprof_b22,
{ "Terminal Profile Byte 22", "gsm_sim.tp.b22",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_utran_ps_ext_params,
{ "UTRAN PS with extended parameters", "gsm_sim.tp.utran_ps_ext_params",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_batt_state,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (battery state)", "gsm_sim.tp.pa.prov_loci_batt_state",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_play_tone_melody,
{ "Proactive SIM: PLAY TONE (Melody tones and Themed tones supported)", "gsm_sim.tp.pa.play_tone_melody",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_mm_call_set_up_call,
{ "Multi-media Calls in SET UP CALL", "gsm_sim.tp.mm_call_set_up_call",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_toolkit_initiated_gba,
{ "Toolkit-initiated GBA", "gsm_sim.tp.toolkit_initiated_gba",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_retrieve_mm_msg,
{ "Proactive SIM: RETRIEVE MULTIMEDIA MESSAGE", "gsm_sim.tp.pa.retrieve_mm_msg",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_submit_mm_msg,
{ "Proactive SIM: SUBMIT MULTIMEDIA MESSAGE", "gsm_sim.tp.pa.submit_mm_msg",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_display_mm_msg,
{ "Proactive SIM: DISPLAY MULTIMEDIA MESSAGE", "gsm_sim.tp.pa.display_mm_msg",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b23,
{ "Terminal Profile Byte 23", "gsm_sim.tp.b23",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_set_frames,
{ "Proactive SIM: SET FRAMES", "gsm_sim.tp.pa.set_frames",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_get_frames_status,
{ "Proactive SIM: GET FRAMES STATUS", "gsm_sim.tp.pa.get_frames_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_mms_notif_download,
{ "MMS notification download", "gsm_sim.tp.mms_notif_download",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_alpha_id_refresh_cmd,
{ "Alpha Identifier in REFRESH command", "gsm_sim.tp.alpha_id_refresh_cmd",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_geo_loc_report,
{ "Geographical Location Reporting", "gsm_sim.tp.geo_loc_report",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_meid,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (MEID)", "gsm_sim.tp.pa.prov_loci_meid",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_nmr_utran_eutran,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (NMR(UTRAN/E-UTRAN))", "gsm_sim.tp.pa.prov_loci_nmr_utran_eutran",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_ussd_data_download,
{ "USSD Data download and application mode", "gsm_sim.tp.ussd_data_download",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b24,
{ "Terminal Profile Byte 24 (Class \"i\")", "gsm_sim.tp.b24",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_class_i_max_nb_frames,
{ "Maximum number of frames supported", "gsm_sim.tp.class_i_max_nb_frames",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_tp_rfu6,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL },
},
{ &hf_tprof_b25,
{ "Terminal Profile Byte 25 (Event driven information extensions)", "gsm_sim.tp.b25",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_evt_browsing_status,
{ "Event: Browsing status", "gsm_sim.tp.evt.browsing_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_evt_mms_transfer_status,
{ "Event: MMS Transfer status", "gsm_sim.tp.evt.mms_transfer_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_evt_frame_info_changed,
{ "Event: Frame Information changed", "gsm_sim.tp.evt.frame_info_changed",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_evt_iwlan_access_status,
{ "Event: I-WLAN Access status", "gsm_sim.tp.evt.iwlan_access_status",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_evt_nw_reject_geran_utran,
{ "Event: Network Rejection for GERAN/UTRAN", "gsm_sim.tp.evt.nw_reject_geran_utran",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_evt_hci_connectivity,
{ "Event: HCI connectivity", "gsm_sim.tp.evt.hci_connectivity",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_evt_nw_reject_eutran,
{ "Event: Network Rejection for E-UTRAN", "gsm_sim.tp.evt.reject_eutran",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_evt_mult_access_techno_change,
{ "Multiple access technologies supported in Event Access Technology Change and PROVIDE LOCAL INFORMATION",
"gsm_sim.tp.evt.mult_access_techno_change",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b26,
{ "Terminal Profile Byte 26 (Event driven information extensions)", "gsm_sim.tp.b26",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_evt_csg_cell_select,
{ "Event: CSG Cell Selection", "gsm_sim.tp.evt.csg_cell_select",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_evt_contactless_state_req,
{ "Event: Contactless state request", "gsm_sim.tp.evt.contactless_state_req",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_rfu7,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0xfc,
NULL, HFILL },
},
{ &hf_tprof_b27,
{ "Terminal Profile Byte 27 (Event driven information extensions)", "gsm_sim.tp.b27",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_rfu8,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL },
},
{ &hf_tprof_b28,
{ "Terminal Profile Byte 28 (Text attributes)", "gsm_sim.tp.b28",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_text_align_left,
{ "Alignment left", "gsm_sim.tp.text.align_left",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_text_align_centre,
{ "Alignment centre", "gsm_sim.tp.text.align_centre",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_text_align_right,
{ "Alignment right", "gsm_sim.tp.text.align_right",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_text_font_size_normal,
{ "Font size normal", "gsm_sim.tp.text.font_size_normal",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_text_font_size_large,
{ "Font size large", "gsm_sim.tp.text.font_size_large",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_text_font_size_small,
{ "Font size small", "gsm_sim.tp.text.font_size_small",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_rfu9,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0xc0,
NULL, HFILL },
},
{ &hf_tprof_b29,
{ "Terminal Profile Byte 29 (Text attributes)", "gsm_sim.tp.b29",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_text_style_normal,
{ "Style normal", "gsm_sim.tp.text.style_normal",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_text_style_bold,
{ "Style bold", "gsm_sim.tp.text.style_bold",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_text_style_italic,
{ "Style italic", "gsm_sim.tp.text.style_italic",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_text_style_underlined,
{ "Style underlined", "gsm_sim.tp.text.style_underlined",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_text_style_strikethrough,
{ "Style strikethrough", "gsm_sim.tp.text.style_strikethrough",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_text_style_text_fg_colour,
{ "Style text foreground colour", "gsm_sim.tp.text.style_text_fg_colour",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_text_style_text_bg_colour,
{ "Style text background colour", "gsm_sim.tp.text.style_text_bg_colour",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_rfu10,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL },
},
{ &hf_tprof_b30,
{ "Terminal Profile Byte 30", "gsm_sim.tp.b30",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_bip_iwlan,
{ "I-WLAN bearer", "gsm_sim.tp.bip.iwlan",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_wsid,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (WSID of the current I-WLAN connection)", "gsm_sim.tp.pa.prov_loci_wsid",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_term_app,
{ "TERMINAL APPLICATIONS", "gsm_sim.tp.term_app",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_steering_roaming_refresh,
{ "\"Steering of Roaming\" REFRESH", "gsm_sim.tp.steering_roaming_refresh",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_pa_activate,
{ "Proactive SIM: ACTIVATE", "gsm_sim.tp.pa.activate",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_geo_loc_req,
{ "Proactive SIM: Geographical Location Request", "gsm_sim.tp.pa.geo_loc_req",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_broadcast_nw_info,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (Broadcast Network Information)", "gsm_sim.tp.pa.prov_loci_broadcast_nw_info",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_steering_roaming_iwlan_refresh,
{ "\"Steering of Roaming for I-WLAN\" REFRESH", "gsm_sim.tp.steering_roaming_iwlan_refresh",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b31,
{ "Terminal Profile Byte 31", "gsm_sim.tp.b31",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_pa_contactless_state_changed,
{ "Proactive SIM: Contactless State Changed", "gsm_sim.tp.pa.contactless_state_changed",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_csg_cell_discovery,
{ "CSG cell discovery", "gsm_sim.tp.csg_cell_discovery",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_cnf_params_support_open_chan_server_mode,
{ "Confirmation parameters supported for OPEN CHANNEL in Terminal Server Mode", "gsm_sim.tp.cnf_params_support_open_chan_server_mode",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_com_ctrl_ims,
{ "Communication Control for IMS", "gsm_sim.tp.com_ctrl_ims",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_cat_over_modem_itf,
{ "CAT over the modem interface", "gsm_sim.tp.cat_over_modem_itf",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_evt_incoming_data_ims,
{ "Event: Incoming IMS Data", "gsm_sim.tp.evt.incoming_data_ims",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_evt_ims_registration,
{ "Event: IMS Registration", "gsm_sim.tp.evt.ims_registration",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_pa_prof_env_cont,
{ "Proactive SIM: Profile Container, Envelope Container, COMMAND CONTAINER and ENCAPSULATED SESSION CONTROL", "gsm_sim.tp.pa.prof_env_cont",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b32,
{ "Terminal Profile Byte 32", "gsm_sim.tp.b32",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_bip_ims,
{ "IMS bearer", "gsm_sim.tp.bip.ims",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_henb_ip_addr,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (H(e)NB IP address)", "gsm_sim.tp.pa.prov_loci_henb_ip_addr",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_pa_prov_loci_henb_surround_macro,
{ "Proactive SIM: PROVIDE LOCAL INFORMATION (H(e)NB surrounding macrocells)", "gsm_sim.tp.pa.prov_loci_henb_surround_macro",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_launch_params_support_open_chan_server_mode,
{ "Launch parameters supported for OPEN CHANNEL in Terminal Server Mode", "gsm_sim.tp.launch_params_support_open_chan_server_mode",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_tp_direct_com_support_open_chan_server_mode,
{ "Direct communication channel supported for OPEN CHANNEL in Terminal Server Mode", "gsm_sim.tp.direct_com_support_open_chan_server_mode",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10,
NULL, HFILL }
},
{ &hf_tp_pa_sec_prof_env_cont,
{ "Proactive SIM: Security for Profile Container, Envelope Container, COMMAND CONTAINER and ENCAPSULATED SESSION CONTROL", "gsm_sim.tp.sec_prof_env_cont",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_tp_cat_serv_list_ecat_client,
{ "CAT service list for eCAT client", "gsm_sim.tp.serv_list_ecat_client",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL }
},
{ &hf_tp_support_refresh_enforcement_policy,
{ "Support of refresh enforcement policy", "gsm_sim.tp.refresh_enforcement_policy",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_tprof_b33,
{ "Terminal Profile Byte 33", "gsm_sim.tp.b33",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_tp_support_dns_addr_req,
{ "Support of DNS server address request for OPEN CHANNEL related to packet data service bearer", "gsm_sim.tp.support_dns_addr_req",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }
},
{ &hf_tp_support_nw_access_name_reuse,
{ "Support of Network Access Name reuse indication for CLOSE CHANNEL related to packet data service bearer", "gsm_sim.tp.nw_access_name_reuse",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }
},
{ &hf_tp_ev_poll_intv_nego,
{ "Event: Poll Interval Negotiation", "gsm_sim.tp.evt.poll_intv_nego",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_tp_rfu11,
{ "RFU", "gsm_sim.tp.rfu",
FT_UINT8, BASE_HEX, NULL, 0xf8,
NULL, HFILL },
},
{ &hf_tprof_unknown_byte,
{ "Unknown Terminal Profile Byte", "gsm_sim.tp.unknown_byte",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_cat_ber_tag,
{ "BER-TLV Tag", "gsm_sim.cat.ber_tlv_tag",
FT_UINT8, BASE_HEX, VALS(ber_tlv_cat_tag_vals), 0,
"Card Application Toolkit BER-TLV tag", HFILL },
},
{ &hf_seek_mode,
{ "Seek Mode", "gsm_sim.seek_mode",
FT_UINT8, BASE_HEX, VALS(seek_mode_vals), 0x0F,
NULL, HFILL },
},
{ &hf_seek_type,
{ "Seek Type", "gsm_sim.seek_type",
FT_UINT8, BASE_DEC, VALS(seek_type_vals), 0x0F,
NULL, HFILL },
},
{ &hf_seek_rec_nr,
{ "Seek Record Number", "gsm_sim.seek_rec_nr",
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
&ett_tprof_b20,
&ett_tprof_b21,
&ett_tprof_b22,
&ett_tprof_b23,
&ett_tprof_b24,
&ett_tprof_b25,
&ett_tprof_b26,
&ett_tprof_b27,
&ett_tprof_b28,
&ett_tprof_b29,
&ett_tprof_b30,
&ett_tprof_b31,
&ett_tprof_b32,
&ett_tprof_b33
};
proto_gsm_sim = proto_register_protocol("GSM SIM 11.11", "GSM SIM",
"gsm_sim");
proto_register_field_array(proto_gsm_sim, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
sim_handle = register_dissector("gsm_sim", dissect_gsm_sim, proto_gsm_sim);
register_dissector("gsm_sim.command", dissect_gsm_sim_command, proto_gsm_sim);
register_dissector("gsm_sim.response", dissect_gsm_sim_response, proto_gsm_sim);
register_dissector("gsm_sim.bertlv", dissect_bertlv, proto_gsm_sim);
}
void
proto_reg_handoff_gsm_sim(void)
{
dissector_add_uint("gsmtap.type", GSMTAP_TYPE_SIM, sim_handle);
sub_handle_cap = find_dissector_add_dependency("etsi_cat", proto_gsm_sim);
}
