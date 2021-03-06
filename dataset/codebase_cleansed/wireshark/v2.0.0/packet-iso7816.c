static inline
guint16 FI_to_Fi(guint8 FI)
{
if (FI<=1)
return 372;
else if (FI<=6)
return (FI-1) * 372;
else if (FI==9)
return 512;
else if (FI==10)
return 768;
else if (FI==11)
return 1024;
else if (FI==12)
return 1536;
else if (FI==13)
return 2048;
return 0;
}
static inline
guint8 DI_to_Di(guint8 DI)
{
if (DI>=1 && DI<=6)
return 1 << (DI-1);
else if (DI==8)
return 12;
else if (DI==9)
return 20;
return 0;
}
static void
dissect_iso7816_atr_ta(tvbuff_t *tvb, gint offset, guint ta_index,
packet_info *pinfo _U_, proto_tree *tree)
{
guint8 ta, FI, DI;
guint16 Fi;
guint8 Di;
proto_item *ta_it;
proto_tree *ta_tree;
ta = tvb_get_guint8(tvb, offset);
ta_it = proto_tree_add_uint_format(tree, hf_iso7816_atr_ta,
tvb, offset, 1, ta,
"Interface character TA(%d): 0x%02x", ta_index, ta);
ta_tree = proto_item_add_subtree(ta_it, ett_iso7816_atr_ta);
if (ta_index==1) {
FI = (tvb_get_guint8(tvb, offset) & 0xF0) >> 4;
Fi = FI_to_Fi(FI);
if (Fi>0) {
proto_tree_add_uint_format(ta_tree, hf_iso7816_atr_ta1_fi,
tvb, offset, 1, Fi,
"Clock rate conversion factor Fi: %d (FI 0x%x)",
Fi, FI);
}
DI = tvb_get_guint8(tvb, offset) & 0x0F;
Di = DI_to_Di(DI);
if (Di>0) {
proto_tree_add_uint_format(ta_tree, hf_iso7816_atr_ta1_di,
tvb, offset, 1, Di,
"Baud rate adjustment factor Di: %d (DI 0x%x)",
Di, DI);
}
}
}
static int
dissect_iso7816_atr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset=0;
guint8 init_char;
guint i=0;
proto_item *proto_it;
proto_tree *proto_tr;
guint8 tb, tc, td, k=0;
gint tck_len;
init_char = tvb_get_guint8(tvb, offset);
if (init_char!=0x3B && init_char!=0x3F)
return 0;
proto_it = proto_tree_add_protocol_format(tree, proto_iso7816_atr,
tvb, 0, -1, "ISO 7816 ATR");
proto_tr = proto_item_add_subtree(proto_it, ett_iso7816_atr);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "ATR");
proto_tree_add_item(proto_tr, hf_iso7816_atr_init_char,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
do {
proto_item *td_it;
proto_tree *td_tree;
td = tvb_get_guint8(tvb, offset);
if (i==0) {
td_it = proto_tree_add_item(proto_tr, hf_iso7816_atr_t0,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
else {
td_it = proto_tree_add_uint_format(proto_tr, hf_iso7816_atr_td,
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
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"TA(%d)=%s TB(%d)=%s TC(%d)=%s TD(%d)=%s",
i+1, td&0x10 ? "True" : "False",
i+1, td&0x20 ? "True" : "False",
i+1, td&0x40 ? "True" : "False",
i+1, td&0x80 ? "True" : "False");
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
dissect_iso7816_atr_ta(tvb, offset, i+1, pinfo, proto_tr);
offset++;
}
if (td&0x20) {
tb = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(proto_tr, hf_iso7816_atr_tb,
tvb, offset, 1, tb,
"Interface character TB(%d): 0x%02x", i+1, tb);
offset++;
}
if (td&0x40) {
tc = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(proto_tr, hf_iso7816_atr_tc,
tvb, offset, 1, tc,
"Interface character TC(%d): 0x%02x", i+1, tc);
offset++;
}
i++;
} while (td&0x80);
if (k>0) {
proto_tree_add_item(proto_tr, hf_iso7816_atr_hist_bytes,
tvb, offset, k, ENC_NA);
offset += k;
}
tck_len = tvb_reported_length_remaining(tvb, offset);
if (tck_len==1) {
proto_tree_add_item(proto_tr, hf_iso7816_atr_tck,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
else if (tck_len>1) {
proto_tree_add_expert(proto_tr, pinfo, &ie_iso7816_atr_tck_not1,
tvb, offset, tck_len);
}
proto_item_set_len(proto_it, offset);
return offset;
}
static gint
dissect_iso7816_class(tvbuff_t *tvb, gint offset,
packet_info *pinfo _U_, proto_tree *tree)
{
gint ret_fct = 1;
proto_item *class_item;
proto_tree *class_tree;
guint8 dev_class;
guint8 channel;
proto_item *ch_item;
class_item = proto_tree_add_item(tree, hf_iso7816_cla,
tvb, offset, 1, ENC_BIG_ENDIAN);
class_tree = proto_item_add_subtree(class_item, ett_iso7816_class);
dev_class = tvb_get_guint8(tvb, offset);
if (dev_class>=0x10 && dev_class<=0x7F) {
}
else if (dev_class>=0xD0 && dev_class<=0xFE) {
ret_fct = -1;
}
else if (dev_class==0xFF) {
}
else {
if (dev_class<=0x0F || (dev_class>=0x80 && dev_class<=0xAF)) {
proto_tree_add_item(class_tree, hf_iso7816_cla_sm,
tvb, offset, 1, ENC_BIG_ENDIAN);
channel = dev_class & 0x03;
ch_item = proto_tree_add_item(class_tree, hf_iso7816_cla_channel,
tvb, offset, 1, ENC_BIG_ENDIAN);
if (channel==0)
proto_item_append_text(ch_item, " (or unused)");
}
}
return ret_fct;
}
static gint
dissect_iso7816_params(guint8 ins, tvbuff_t *tvb, gint offset,
packet_info *pinfo _U_, proto_tree *tree)
{
gint offset_start, p1_offset, p2_offset;
proto_tree *params_tree;
guint8 p1, p2;
proto_item *p1_it = NULL, *p2_it = NULL;
proto_tree *p1_tree = NULL, *p2_tree = NULL;
proto_item *p1_p2_it = NULL;
guint16 P1P2;
offset_start = offset;
params_tree = proto_tree_add_subtree(tree, tvb, offset_start, 2,
ett_iso7816_param, NULL, "Parameters");
p1 = tvb_get_guint8(tvb,offset);
p1_it = proto_tree_add_item(params_tree, hf_iso7816_p1, tvb,
offset, 1, ENC_BIG_ENDIAN);
p1_offset = offset;
offset++;
p2 = tvb_get_guint8(tvb,offset);
p2_it = proto_tree_add_item(params_tree, hf_iso7816_p2,
tvb, offset, 1, ENC_BIG_ENDIAN);
p2_offset = offset;
offset++;
P1P2 = (p1<<8|p2);
switch (ins) {
case INS_EXT_AUTH:
if (p1>0) {
proto_item_append_text(p1_it,
" (reference of the algorithm on the card)");
}
proto_item_append_text(p2_it, " (reference of the secret)");
break;
case INS_SELECT_FILE:
proto_item_append_text(p1_it, " (selection control)");
p1_tree = proto_item_add_subtree(p1_it, ett_iso7816_p1);
proto_tree_add_item(p1_tree, hf_iso7816_sel_file_ctrl,
tvb, p1_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(p2_it, " (selection options)");
p2_tree = proto_item_add_subtree(p2_it, ett_iso7816_p2);
proto_tree_add_item(p2_tree, hf_iso7816_sel_file_fci_req,
tvb, p2_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(p2_tree, hf_iso7816_sel_file_occ,
tvb, p2_offset, 1, ENC_BIG_ENDIAN);
break;
case INS_READ_BIN:
if (p1&0x80) {
}
else {
p1_p2_it = proto_tree_add_uint(params_tree, hf_iso7816_offset_first_byte,
tvb, offset_start, offset-offset_start, P1P2);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"offset %d", P1P2);
}
break;
case INS_GET_RESP:
p1_p2_it = proto_tree_add_uint_format(params_tree, hf_iso7816_get_resp,
tvb, offset_start, offset-offset_start, P1P2,
"Both should be 0x00, other values are RFU");
break;
case INS_GET_DATA:
if (P1P2<=0x003F || (0x0300<=P1P2 && P1P2<=0x3FFF)) {
p1_p2_it = proto_tree_add_uint(params_tree, hf_iso7816_rfu,
tvb, offset_start, offset-offset_start, P1P2);
}
else if (0x0100<=P1P2 && P1P2<=0x01FF) {
p1_p2_it = proto_tree_add_uint(params_tree, hf_iso7816_application_data,
tvb, offset_start, offset-offset_start, P1P2);
}
break;
default:
break;
}
PROTO_ITEM_SET_GENERATED(p1_p2_it);
return 2;
}
static gint
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
static gint
dissect_iso7816_cmd_apdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
iso7816_transaction_t *iso7816_trans = NULL;
proto_item *trans_ti = NULL;
gint ret;
gint offset = 0;
guint8 ins;
gint body_len;
guint8 lc;
if (PINFO_FD_VISITED(pinfo)) {
iso7816_trans = (iso7816_transaction_t *)wmem_tree_lookup32(
transactions, PINFO_FD_NUM(pinfo));
if (iso7816_trans && iso7816_trans->cmd_frame==PINFO_FD_NUM(pinfo) &&
iso7816_trans->resp_frame!=0) {
trans_ti = proto_tree_add_uint_format(tree, hf_iso7816_resp_in,
NULL, 0, 0, iso7816_trans->resp_frame,
"Response in frame %d", iso7816_trans->resp_frame);
PROTO_ITEM_SET_GENERATED(trans_ti);
}
}
else {
if (transactions) {
iso7816_trans = wmem_new(wmem_file_scope(), iso7816_transaction_t);
iso7816_trans->cmd_frame = PINFO_FD_NUM(pinfo);
iso7816_trans->resp_frame = 0;
iso7816_trans->cmd_ins = INS_INVALID;
wmem_tree_insert32(transactions,
iso7816_trans->cmd_frame, (void *)iso7816_trans);
}
}
ret = dissect_iso7816_class(tvb, offset, pinfo, tree);
if (ret==-1) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s",
"Command APDU using proprietary format");
return 1;
}
offset += ret;
ins = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_iso7816_ins, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s",
val_to_str_ext_const(ins, &iso7816_ins_ext, "Unknown instruction"));
offset++;
if (iso7816_trans && iso7816_trans->cmd_ins==INS_INVALID)
iso7816_trans->cmd_ins = ins;
ret = dissect_iso7816_params(ins, tvb, offset, pinfo, tree);
if (ret>0)
offset += ret;
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
static gint
dissect_iso7816_resp_apdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
iso7816_transaction_t *iso7816_trans;
proto_item *trans_ti = NULL;
const gchar *cmd_ins_str;
gint offset = 0;
gint body_len;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Response APDU");
if (transactions) {
iso7816_trans = (iso7816_transaction_t *)wmem_tree_lookup32_le(
transactions, PINFO_FD_NUM(pinfo));
if (iso7816_trans) {
if (iso7816_trans->resp_frame==0) {
iso7816_trans->resp_frame = PINFO_FD_NUM(pinfo);
}
if (iso7816_trans->resp_frame== PINFO_FD_NUM(pinfo)) {
cmd_ins_str = val_to_str_const(iso7816_trans->cmd_ins,
iso7816_ins, "Unknown instruction");
trans_ti = proto_tree_add_uint_format(tree, hf_iso7816_resp_to,
NULL, 0, 0, iso7816_trans->cmd_frame,
"Response to frame %d (%s)",
iso7816_trans->cmd_frame, cmd_ins_str);
PROTO_ITEM_SET_GENERATED(trans_ti);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ",
"(to %s)", cmd_ins_str);
}
}
}
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
dissect_iso7816(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
proto_item *tree_ti = NULL;
proto_tree *iso7816_tree = NULL;
gboolean is_atr = FALSE;
if (pinfo->p2p_dir!=P2P_DIR_SENT && pinfo->p2p_dir!=P2P_DIR_RECV)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISO 7816");
col_clear(pinfo->cinfo, COL_INFO);
tree_ti = proto_tree_add_protocol_format(tree, proto_iso7816,
tvb, 0, tvb_reported_length(tvb), "ISO 7816");
iso7816_tree = proto_item_add_subtree(tree_ti, ett_iso7816);
if (pinfo->p2p_dir==P2P_DIR_SENT) {
SET_ADDRESS(&pinfo->src, AT_STRINGZ,
(int)strlen(ADDR_INTF)+1, ADDR_INTF);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ,
(int)strlen(ADDR_CARD)+1, ADDR_CARD);
proto_item_append_text(tree_ti, " Command APDU");
offset = dissect_iso7816_cmd_apdu(tvb, pinfo, iso7816_tree);
}
else if (pinfo->p2p_dir==P2P_DIR_RECV) {
SET_ADDRESS(&pinfo->src, AT_STRINGZ,
(int)strlen(ADDR_CARD)+1, ADDR_CARD);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ,
(int)strlen(ADDR_INTF)+1, ADDR_INTF);
if (iso7816_atr_handle) {
offset = call_dissector_only(iso7816_atr_handle,
tvb, pinfo, iso7816_tree, NULL);
if (offset > 0)
is_atr = TRUE;
}
if (!is_atr) {
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
{ &hf_iso7816_atr_ta1_fi,
{ "Fi", "iso7816.atr.ta1.fi",
FT_UINT16, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_iso7816_atr_ta1_di,
{ "Di", "iso7816.atr.ta1.di",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL }
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
{ &hf_iso7816_resp_in,
{ "Response In", "iso7816.resp_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this command is in this frame", HFILL }
},
{ &hf_iso7816_resp_to,
{ "Response To", "iso7816.resp_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is the response to the command in this frame", HFILL }
},
{ &hf_iso7816_cla,
{ "Class", "iso7816.apdu.cla",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(iso7816_class_rvals), 0, NULL , HFILL }
},
{ &hf_iso7816_cla_sm,
{ "Secure Messaging", "iso7816.apdu.cla.sm",
FT_UINT8, BASE_HEX, VALS(iso7816_cla_sm), 0x0C, NULL , HFILL }
},
{ &hf_iso7816_cla_channel,
{ "Logical channel number", "iso7816.apdu.cla.channel",
FT_UINT8, BASE_HEX, NULL, 0x03, NULL , HFILL }
},
{ &hf_iso7816_ins,
{ "Instruction", "iso7816.apdu.ins",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &iso7816_ins_ext, 0, NULL, HFILL }
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
},
{ &hf_iso7816_sel_file_ctrl,
{ "Selection control", "iso7816.apdu.select_file.ctrl",
FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&ext_iso7816_sel_file_ctrl, 0, NULL, HFILL }
},
{ &hf_iso7816_sel_file_fci_req,
{ "File control information request", "iso7816.apdu.select_file.fci_req",
FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&ext_iso7816_sel_file_fci_req, 0x0C, NULL, HFILL }
},
{ &hf_iso7816_sel_file_occ,
{ "Occurrence", "iso7816.apdu.select_file.occurrence",
FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&ext_iso7816_sel_file_occ, 0x03, NULL, HFILL }
},
{ &hf_iso7816_offset_first_byte,
{ "Offset of the first byte to read", "iso7816.offset_first_byte",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_get_resp,
{ "GetResp", "iso7816.get_resp",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_rfu,
{ "RFU", "iso7816.rfu",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_iso7816_application_data,
{ "Application data (proprietary coding)", "iso7816.application_data",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_iso7816,
&ett_iso7816_class,
&ett_iso7816_param,
&ett_iso7816_p1,
&ett_iso7816_p2,
&ett_iso7816_atr,
&ett_iso7816_atr_ta,
&ett_iso7816_atr_td
};
static ei_register_info ei[] = {
{ &ie_iso7816_atr_tck_not1, { "iso7816.atr.tck.not1", PI_PROTOCOL, PI_WARN, "TCK byte must either be absent or exactly one byte", EXPFILL }}
};
expert_module_t* expert_iso7816;
proto_iso7816 = proto_register_protocol(
"ISO/IEC 7816", "ISO 7816", "iso7816");
proto_register_field_array(proto_iso7816, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_iso7816 = expert_register_protocol(proto_iso7816);
expert_register_field_array(expert_iso7816, ei, array_length(ei));
new_register_dissector("iso7816", dissect_iso7816, proto_iso7816);
transactions = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
proto_iso7816_atr = proto_register_protocol(
"ISO/IEC 7816-3", "ISO 7816-3", "iso7816.atr");
new_register_dissector("iso7816.atr", dissect_iso7816_atr, proto_iso7816_atr);
}
void
proto_reg_handoff_iso7816(void)
{
iso7816_atr_handle = find_dissector("iso7816.atr");
}
