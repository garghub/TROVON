static int
dissect_whois(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti, *expert_ti;
proto_tree *whois_tree;
conversation_t *conversation;
whois_transaction_t *whois_trans;
gboolean is_query;
guint len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WHOIS");
if (pinfo->destport == WHOIS_PORT) {
is_query = TRUE;
col_set_str(pinfo->cinfo, COL_INFO, "Query");
} else {
is_query = FALSE;
col_set_str(pinfo->cinfo, COL_INFO, "Answer");
}
conversation = find_or_create_conversation(pinfo);
whois_trans = (whois_transaction_t *)conversation_get_proto_data(conversation, proto_whois);
if (whois_trans == NULL) {
whois_trans = wmem_new0(wmem_file_scope(), whois_transaction_t);
conversation_add_proto_data(conversation, proto_whois, whois_trans);
}
len = tvb_reported_length(tvb);
if (!PINFO_FD_VISITED(pinfo)) {
if (pinfo->can_desegment) {
if (is_query) {
if ((len < 2) || (tvb_memeql(tvb, len - 2, "\r\n", 2))) {
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
pinfo->desegment_offset = 0;
return -1;
} else {
whois_trans->req_frame = pinfo->num;
whois_trans->req_time = pinfo->abs_ts;
}
} else {
pinfo->desegment_len = DESEGMENT_UNTIL_FIN;
pinfo->desegment_offset = 0;
return -1;
}
}
} else if (is_query && (whois_trans->req_frame == 0)) {
whois_trans->req_frame = pinfo->num;
whois_trans->req_time = pinfo->abs_ts;
}
if (!is_query && (whois_trans->rep_frame == 0)) {
whois_trans->rep_frame = pinfo->num;
}
ti = proto_tree_add_protocol_format(tree, proto_whois, tvb, 0, -1,
"WHOIS: %s", is_query ? "Query" : "Answer");
whois_tree = proto_item_add_subtree(ti, ett_whois);
if (is_query) {
expert_ti = proto_tree_add_item(whois_tree, hf_whois_query, tvb, 0, -1, ENC_ASCII|ENC_NA);
if ((len < 2) || (tvb_memeql(tvb, len - 2, "\r\n", 2))) {
expert_add_info(pinfo, expert_ti, &ei_whois_nocrlf);
}
if (tree && whois_trans->rep_frame) {
ti = proto_tree_add_uint(whois_tree, hf_whois_answer_in,
tvb, 0, 0, whois_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(ti);
}
} else if (tree && whois_trans->rep_frame) {
proto_tree_add_item(whois_tree, hf_whois_answer, tvb, 0, -1, ENC_ASCII|ENC_NA);
if (whois_trans->req_frame) {
nstime_t ns;
ti = proto_tree_add_uint(whois_tree, hf_whois_answer_to,
tvb, 0, 0, whois_trans->req_frame);
PROTO_ITEM_SET_GENERATED(ti);
if (pinfo->num == whois_trans->rep_frame) {
nstime_delta(&ns, &pinfo->abs_ts, &whois_trans->req_time);
ti = proto_tree_add_time(whois_tree, hf_whois_response_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_whois(void)
{
expert_module_t *expert_whois;
static hf_register_info hf[] = {
{ &hf_whois_query,
{ "Query", "whois.query", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_whois_answer,
{ "Answer", "whois.answer", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_whois_answer_in,
{ "Answer In", "whois.answer_in", FT_FRAMENUM, BASE_NONE, NULL,
0x0, "The answer to this WHOIS query is in this frame",
HFILL }
},
{ &hf_whois_answer_to,
{ "Query In", "whois.answer_to", FT_FRAMENUM, BASE_NONE, NULL,
0x0, "This is the answer to the WHOIS query in this frame",
HFILL }
},
{ &hf_whois_response_time,
{ "Response Time", "whois.response_time", FT_RELATIVE_TIME,
BASE_NONE, NULL, 0x0,
"The time between the Query and the Answer", HFILL }
}
};
static gint *ett[] = {
&ett_whois
};
static ei_register_info ei[] = {
{ &ei_whois_nocrlf,
{ "whois.nocrlf", PI_MALFORMED, PI_WARN, "Missing <CR><LF>", EXPFILL}
}
};
proto_whois = proto_register_protocol("whois", "WHOIS", "whois");
proto_register_field_array(proto_whois, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_whois = expert_register_protocol(proto_whois);
expert_register_field_array(expert_whois, ei, array_length(ei));
}
void
proto_reg_handoff_whois(void)
{
static dissector_handle_t whois_handle;
whois_handle = create_dissector_handle(dissect_whois, proto_whois);
dissector_add_uint_with_preference("tcp.port", WHOIS_PORT, whois_handle);
}
