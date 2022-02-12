static int
dissect_finger(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti, *expert_ti;
proto_tree *finger_tree;
conversation_t *conversation;
finger_transaction_t *finger_trans;
gboolean is_query;
guint len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FINGER");
if (pinfo->destport == FINGER_PORT) {
is_query = TRUE;
col_set_str(pinfo->cinfo, COL_INFO, "Query");
} else {
is_query = FALSE;
col_set_str(pinfo->cinfo, COL_INFO, "Response");
}
conversation = find_or_create_conversation(pinfo);
finger_trans = (finger_transaction_t *)conversation_get_proto_data(conversation, proto_finger);
if (finger_trans == NULL) {
finger_trans = wmem_new0(wmem_file_scope(), finger_transaction_t);
conversation_add_proto_data(conversation, proto_finger, finger_trans);
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
finger_trans->req_frame = pinfo->num;
finger_trans->req_time = pinfo->abs_ts;
}
} else {
pinfo->desegment_len = DESEGMENT_UNTIL_FIN;
pinfo->desegment_offset = 0;
return -1;
}
}
} else if (is_query && (finger_trans->req_frame == 0)) {
finger_trans->req_frame = pinfo->num;
finger_trans->req_time = pinfo->abs_ts;
}
if (!is_query && (finger_trans->rep_frame == 0)) {
finger_trans->rep_frame = pinfo->num;
}
ti = proto_tree_add_protocol_format(tree, proto_finger, tvb, 0, -1,
"FINGER: %s", is_query ? "Query" : "Response");
finger_tree = proto_item_add_subtree(ti, ett_finger);
if (is_query) {
expert_ti = proto_tree_add_item(finger_tree, hf_finger_query, tvb, 0, -1, ENC_ASCII|ENC_NA);
if ((len < 2) || (tvb_memeql(tvb, len - 2, "\r\n", 2))) {
expert_add_info(pinfo, expert_ti, &ei_finger_nocrlf);
}
if (tree && finger_trans->rep_frame) {
ti = proto_tree_add_uint(finger_tree, hf_finger_response_in,
tvb, 0, 0, finger_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(ti);
}
} else if (tree && finger_trans->rep_frame) {
proto_tree_add_item(finger_tree, hf_finger_response, tvb, 0, -1, ENC_ASCII|ENC_NA);
if (finger_trans->req_frame) {
nstime_t ns;
ti = proto_tree_add_uint(finger_tree, hf_finger_response_to,
tvb, 0, 0, finger_trans->req_frame);
PROTO_ITEM_SET_GENERATED(ti);
if (pinfo->num == finger_trans->rep_frame) {
nstime_delta(&ns, &pinfo->abs_ts, &finger_trans->req_time);
ti = proto_tree_add_time(finger_tree, hf_finger_response_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_finger(void)
{
expert_module_t *expert_finger;
static hf_register_info hf[] = {
{ &hf_finger_query,
{ "Query", "finger.query", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_finger_response,
{ "Response", "finger.response", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_finger_response_in,
{ "Response In", "finger.response_in", FT_FRAMENUM, BASE_NONE, NULL,
0x0, "The response to this FINGER query is in this frame",
HFILL }
},
{ &hf_finger_response_to,
{ "Request In", "finger.response_to", FT_FRAMENUM, BASE_NONE, NULL,
0x0, "This is a response to the FINGER query in this frame",
HFILL }
},
{ &hf_finger_response_time,
{ "Response Time", "finger.response_time", FT_RELATIVE_TIME,
BASE_NONE, NULL, 0x0,
"The time between the Query and the Response", HFILL }
}
};
static gint *ett[] = {
&ett_finger
};
static ei_register_info ei[] = {
{ &ei_finger_nocrlf,
{ "finger.nocrlf", PI_MALFORMED, PI_WARN, "Missing <CR><LF>", EXPFILL}
}
};
proto_finger = proto_register_protocol("finger", "FINGER", "finger");
proto_register_field_array(proto_finger, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_finger = expert_register_protocol(proto_finger);
expert_register_field_array(expert_finger, ei, array_length(ei));
}
void
proto_reg_handoff_finger(void)
{
static dissector_handle_t finger_handle;
finger_handle = create_dissector_handle(dissect_finger, proto_finger);
dissector_add_uint("tcp.port", FINGER_PORT, finger_handle);
}
