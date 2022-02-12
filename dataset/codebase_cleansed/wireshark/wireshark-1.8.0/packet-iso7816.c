static int
dissect_iso7816_atr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset=0;
guint i=0;
proto_item *td_it;
proto_tree *td_tree=NULL;
guint8 ta, tb, tc, td, k=0;
gint tck_len;
proto_item *err_it;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "ATR sequence");
proto_tree_add_item(tree, hf_iso7816_atr_init_char,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
do {
td = tvb_get_guint8(tvb, offset);
if (i==0) {
td_it = proto_tree_add_item(tree, hf_iso7816_atr_t0,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
else {
td_it = proto_tree_add_uint_format(tree, hf_iso7816_atr_td,
tvb, offset, 1, td,
"Interface character TD(%d): 0x%02x", i, td);
}
td_tree = proto_item_add_subtree(td_it, ett_iso7816_atr_td);
proto_tree_add_boolean_format(td_tree, hf_iso7816_atr_next_ta_present,
tvb, offset, 1, td&0x10,
"TA(%d) present: %s", i+1, td&0x10 ? "True" : "False");
proto_tree_add_boolean_format(td_tree, hf_iso7816_atr_next_tb_present,
tvb, offset, 1, td&0x20,
"TB(%d) present: %s", i+1, td&0x20 ? "True" : "False");
proto_tree_add_boolean_format(td_tree, hf_iso7816_atr_next_tc_present,
tvb, offset, 1, td&0x40,
"TC(%d) present: %s", i+1, td&0x40 ? "True" : "False");
proto_tree_add_boolean_format(td_tree, hf_iso7816_atr_next_td_present,
tvb, offset, 1, td&0x80,
"TD(%d) present: %s", i+1, td&0x80 ? "True" : "False");
if (i==0) {
k = td&0x0F;
proto_tree_add_item(td_tree, hf_iso7816_atr_k,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(td_tree, hf_iso7816_atr_t,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset++;
if (td&0x10) {
ta = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_iso7816_atr_ta, tvb, offset, 1,
ta, "Interface character TA(%d): 0x%02x", i+1, ta);
offset++;
}
if (td&0x20) {
tb = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_iso7816_atr_tb, tvb, offset, 1,
tb, "Interface character TB(%d): 0x%02x", i+1, tb);
offset++;
}
if (td&0x40) {
tc = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_iso7816_atr_tc, tvb, offset, 1,
tc, "Interface character TC(%d): 0x%02x", i+1, tc);
offset++;
}
i++;
} while (td&0x80);
if (k>0) {
proto_tree_add_item(tree, hf_iso7816_atr_hist_bytes,
tvb, offset, k, ENC_NA);
offset += k;
}
tck_len = tvb_reported_length_remaining(tvb, offset);
if (tck_len==1) {
proto_tree_add_item(tree, hf_iso7816_atr_tck,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
else if (tck_len>1) {
err_it = proto_tree_add_text(tree, tvb, offset, tck_len,
"Invalid TCK byte");
expert_add_info_format(pinfo, err_it, PI_PROTOCOL, PI_WARN,
"TCK byte must either be absent or exactly one byte");
}
return offset;
}
static int
dissect_iso7816_le(
tvbuff_t *tvb, gint offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 le;
proto_item *le_item;
le = tvb_get_guint8(tvb, offset);
le_item = proto_tree_add_item(
tree, hf_iso7816_le, tvb, offset, 1, ENC_BIG_ENDIAN);
if (le==0)
proto_item_append_text(le_item, " (maximum number of available bytes)");
return 1;
}
static int
dissect_iso7816_cmd_apdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
guint8 ins;
gint body_len;
guint8 lc;
proto_tree_add_item(tree, hf_iso7816_cla, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ins = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_iso7816_ins, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s",
val_to_str_const(ins, iso7816_ins, "Unknown instruction"));
offset++;
proto_tree_add_item(tree, hf_iso7816_p1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_iso7816_p2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
body_len = tvb_reported_length_remaining(tvb, offset);
if (body_len==1) {
offset += dissect_iso7816_le(tvb, offset, pinfo, tree);
}
else if (body_len>1) {
lc = tvb_get_guint8(tvb, offset);
proto_tree_add_item(
tree, hf_iso7816_lc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (lc>0) {
proto_tree_add_item(tree, hf_iso7816_body, tvb, offset, lc, ENC_NA);
offset += lc;
}
if (tvb_reported_length_remaining(tvb, offset)>0) {
offset += dissect_iso7816_le(tvb, offset, pinfo, tree);
}
}
return offset;
}
static int
dissect_iso7816_resp_apdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
gint body_len;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Response APDU");
body_len = tvb_reported_length_remaining(tvb, offset) - 2;
if (body_len>0) {
proto_tree_add_item(tree, hf_iso7816_body,
tvb, offset, body_len, ENC_NA);
offset += body_len;
}
if (tvb_reported_length_remaining(tvb, offset) >= 2) {
proto_tree_add_item(tree, hf_iso7816_sw1,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_iso7816_sw2,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
return offset;
}
static int
dissect_iso7816(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
proto_item *tree_ti = NULL;
proto_tree *iso7816_tree = NULL;
guint8 tmp;
if (pinfo->p2p_dir!=P2P_DIR_SENT && pinfo->p2p_dir!=P2P_DIR_RECV)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISO 7816");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
tree_ti = proto_tree_add_protocol_format(tree, proto_iso7816,
tvb, 0, tvb_reported_length(tvb), "ISO 7816");
iso7816_tree = proto_item_add_subtree(tree_ti, ett_iso7816);
}
if (pinfo->p2p_dir==P2P_DIR_SENT) {
SET_ADDRESS(&pinfo->src, AT_STRINGZ,
(int)strlen(ADDR_INTF)+1, ADDR_INTF);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ,
(int)strlen(ADDR_CARD)+1, ADDR_CARD);
if (tree_ti)
proto_item_append_text(tree_ti, " Command APDU");
offset = dissect_iso7816_cmd_apdu(tvb, pinfo, iso7816_tree);
}
else if (pinfo->p2p_dir==P2P_DIR_RECV) {
SET_ADDRESS(&pinfo->src, AT_STRINGZ,
(int)strlen(ADDR_CARD)+1, ADDR_CARD);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ,
(int)strlen(ADDR_INTF)+1, ADDR_INTF);
tmp = tvb_get_guint8(tvb, offset);
if (tmp==0x3B || tmp==0x3F) {
if (tree_ti)
proto_item_append_text(tree_ti, " ATR");
offset = dissect_iso7816_atr(tvb, pinfo, iso7816_tree);
}
else {
if (tree_ti)
proto_item_append_text(tree_ti, " Response APDU");
offset = dissect_iso7816_resp_apdu(tvb, pinfo, iso7816_tree);
}
}
return offset;
}
void
proto_register_iso7816(void)
{
static hf_register_info hf[] = {
{ &hf_iso7816_atr_init_char,
{ "Initial character", "iso7816.atr.init_char",
FT_UINT8, BASE_HEX, VALS(iso7816_atr_init_char), 0, NULL, HFILL }
},
{ &hf_iso7816_atr_t0,
{ "Format character T0", "iso7816.atr.t0",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_atr_ta,
{ "Interface character TA(i)", "iso7816.atr.ta",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_atr_tb,
{ "Interface character TB(i)", "iso7816.atr.tb",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_atr_tc,
{ "Interface character TC(i)", "iso7816.atr.tc",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_atr_td,
{ "Interface character TD(i)", "iso7816.atr.td",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_atr_next_ta_present,
{ "TA(i+1) present", "iso7816.atr.next_ta_present",
FT_BOOLEAN, BASE_HEX, NULL, 0x10, NULL, HFILL }
},
{ &hf_iso7816_atr_next_tb_present,
{ "TB(i+1) present", "iso7816.atr.next_tb_present",
FT_BOOLEAN, BASE_HEX, NULL, 0x20, NULL, HFILL }
},
{ &hf_iso7816_atr_next_tc_present,
{ "TC(i+1) present", "iso7816.atr.next_tc_present",
FT_BOOLEAN, BASE_HEX, NULL, 0x40, NULL, HFILL }
},
{ &hf_iso7816_atr_next_td_present,
{ "TD(i+1) present", "iso7816.atr.next_td_present",
FT_BOOLEAN, BASE_HEX, NULL, 0x80, NULL, HFILL }
},
{ &hf_iso7816_atr_k,
{ "Number K of historical bytes", "iso7816.atr.k",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_iso7816_atr_t,
{ "Protocol reference T", "iso7816.atr.t",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL }
},
{ &hf_iso7816_atr_hist_bytes,
{ "Historical bytes", "iso7816.atr.historical_bytes",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_atr_tck,
{ "Check character TCK", "iso7816.atr.tck",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_cla,
{ "Class", "iso7816.apdu.cla",
FT_UINT8, BASE_HEX, NULL, 0, NULL , HFILL }
},
{ &hf_iso7816_ins,
{ "Instruction", "iso7816.apdu.ins",
FT_UINT8, BASE_HEX, VALS(iso7816_ins), 0, NULL, HFILL }
},
{ &hf_iso7816_p1,
{ "Parameter 1", "iso7816.apdu.p1",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_p2,
{ "Parameter 2", "iso7816.apdu.p2",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_lc,
{ "Length field Lc", "iso7816.apdu.lc",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_le,
{ "Expected response length Le", "iso7816.apdu.le",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_body,
{ "APDU Body", "iso7816.apdu.body",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_sw1,
{ "Status Word SW1", "iso7816.apdu.sw1", FT_UINT8,
BASE_RANGE_STRING|BASE_HEX, RVALS(iso7816_sw1), 0, NULL, HFILL }
},
{ &hf_iso7816_sw2,
{ "Status Word SW2", "iso7816.apdu.sw2",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_iso7816,
&ett_iso7816_atr_td
};
proto_iso7816 = proto_register_protocol(
"ISO/IEC 7816", "ISO 7816", "iso7816");
proto_register_field_array(proto_iso7816, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("iso7816", dissect_iso7816, proto_iso7816);
}
