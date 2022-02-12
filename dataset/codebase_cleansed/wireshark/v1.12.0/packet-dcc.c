static gboolean
dissect_dcc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *dcc_tree, *dcc_optree, *dcc_opnumtree, *ti;
proto_tree *dcc_tracetree;
int offset = 0;
int client_is_le = 0;
int op = 0;
int i, is_response;
if (pinfo->srcport != DCC_PORT && pinfo->destport != DCC_PORT) {
return FALSE;
}
if ( tvb_length(tvb) < sizeof(DCC_HDR) ) {
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DCC");
offset = 0;
is_response = pinfo->srcport == DCC_PORT;
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s: %s",
is_response ? "Response" : "Request",
val_to_str(tvb_get_guint8(tvb, offset+3),
dcc_op_vals, "Unknown Op: %u")
);
if (tree) {
ti = proto_tree_add_item(tree, proto_dcc, tvb, offset, -1,
ENC_NA);
dcc_tree = proto_item_add_subtree(ti, ett_dcc);
proto_tree_add_item(dcc_tree, hf_dcc_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
if ( tvb_length(tvb) < tvb_get_ntohs(tvb, offset)) {
proto_tree_add_text(dcc_tree, tvb, offset, 2, "Error - packet is shorter than header claims!");
}
offset += 2;
proto_tree_add_item(dcc_tree, hf_dcc_pkt_vers, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
op = tvb_get_guint8(tvb, offset);
proto_tree_add_item(dcc_tree, hf_dcc_op, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dcc_tree, hf_dcc_clientid, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ti = proto_tree_add_text(dcc_tree, tvb, offset, -1, "Operation Numbers (Opaque to Server)");
dcc_opnumtree = proto_item_add_subtree(ti, ett_dcc_opnums);
client_is_le = ( (tvb_get_guint8(tvb, offset+4) | tvb_get_guint8(tvb, offset+4)) &&
(tvb_get_guint8(tvb, offset+8) | tvb_get_guint8(tvb, offset+9)) &&
(tvb_get_guint8(tvb, offset+12) | tvb_get_guint8(tvb, offset+13)) );
proto_tree_add_item(dcc_opnumtree, hf_dcc_opnums_host, tvb,
offset, 4, client_is_le);
offset += 4;
proto_tree_add_item(dcc_opnumtree, hf_dcc_opnums_pid, tvb,
offset, 4, client_is_le);
offset += 4;
proto_tree_add_item(dcc_opnumtree, hf_dcc_opnums_report, tvb,
offset, 4, client_is_le);
offset += 4;
proto_tree_add_item(dcc_opnumtree, hf_dcc_opnums_retrans, tvb,
offset, 4, client_is_le);
offset += 4;
ti = proto_tree_add_text(dcc_tree, tvb, offset, -1, "Operation: %s",
val_to_str(op, dcc_op_vals, "Unknown Op: %u"));
dcc_optree = proto_item_add_subtree(ti, ett_dcc_op);
switch(op) {
case DCC_OP_NOP:
D_SIGNATURE();
break;
case DCC_OP_REPORT:
D_TARGET();
for (i=0; i<=DCC_QUERY_MAX &&
tvb_bytes_exist(tvb, offset+(int)sizeof(DCC_SIGNATURE),1); i++)
{
D_CHECKSUM();
}
D_SIGNATURE();
break;
case DCC_OP_QUERY_RESP:
for (i=0; i<=DCC_QUERY_MAX &&
tvb_bytes_exist(tvb, offset+(int)sizeof(DCC_SIGNATURE),1); i++)
{
D_TARGET();
}
D_SIGNATURE();
break;
case DCC_OP_ADMN:
if ( is_response )
{
int left_local = tvb_length_remaining(tvb, offset) -
(int)sizeof(DCC_SIGNATURE);
if ( left_local == sizeof(DCC_ADMN_RESP_CLIENTS) )
{
D_LABEL("Addr", 16);
D_LABEL("Id", (int)sizeof(DCC_CLNT_ID));
D_LABEL("Last Used", 4);
D_LABEL("Requests", 4);
}
else
{
D_TEXT("Response Text", (int)sizeof(DCC_SIGNATURE));
}
D_SIGNATURE();
}
else
{
int aop;
D_DATE();
aop = tvb_get_guint8(tvb, offset+4);
proto_tree_add_item(dcc_optree, hf_dcc_adminop, tvb, offset+4,
1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(tvb_get_guint8(tvb,offset+4),
dcc_adminop_vals, "Unknown (%u)"));
if (aop == DCC_AOP_TRACE_ON || aop == DCC_AOP_TRACE_OFF )
{
ti = proto_tree_add_item(dcc_optree, hf_dcc_trace, tvb, offset,
4, ENC_BIG_ENDIAN);
dcc_tracetree = proto_item_add_subtree(ti, ett_dcc_trace);
proto_tree_add_item(dcc_tracetree, hf_dcc_trace_admin, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dcc_tracetree, hf_dcc_trace_anon, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dcc_tracetree, hf_dcc_trace_client, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dcc_tracetree, hf_dcc_trace_rlim, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dcc_tracetree, hf_dcc_trace_query, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dcc_tracetree, hf_dcc_trace_ridc, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(dcc_tracetree, hf_dcc_trace_flood, tvb, offset, 4, ENC_BIG_ENDIAN);
}
else if ( aop == DCC_AOP_FLOD )
{
proto_tree_add_item(dcc_optree, hf_dcc_floodop,
tvb, offset, 4, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(tvb_get_ntohl(tvb,offset),
dcc_floodop_vals, "Unknown (%u)"));
}
else
{
proto_tree_add_item(dcc_optree, hf_dcc_adminval,
tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
offset += 1;
D_LABEL("Pad", 3);
D_SIGNATURE();
}
break;
case DCC_OP_OK:
proto_tree_add_item(dcc_optree, hf_dcc_max_pkt_vers, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
D_LABEL("Unused", 1);
proto_tree_add_item(dcc_optree, hf_dcc_qdelay_ms, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dcc_optree, hf_dcc_brand, tvb,
offset, (int)sizeof(DCC_BRAND), ENC_ASCII|ENC_NA);
offset += (int)sizeof(DCC_BRAND);
D_SIGNATURE();
break;
default:
break;
}
}
return TRUE;
}
void
proto_register_dcc(void)
{
static hf_register_info hf[] = {
{ &hf_dcc_len, {
"Packet Length", "dcc.len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_pkt_vers, {
"Packet Version", "dcc.pkt_vers", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_op, {
"Operation Type", "dcc.op", FT_UINT8, BASE_DEC,
VALS(dcc_op_vals), 0, NULL, HFILL }},
{ &hf_dcc_clientid, {
"Client ID", "dcc.clientid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_opnums_host, {
"Host", "dcc.opnums.host", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_opnums_pid, {
"Process ID", "dcc.opnums.pid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_opnums_report, {
"Report", "dcc.opnums.report", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_opnums_retrans, {
"Retransmission", "dcc.opnums.retrans", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_signature, {
"Signature", "dcc.signature", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_max_pkt_vers, {
"Maximum Packet Version", "dcc.max_pkt_vers", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_qdelay_ms, {
"Client Delay", "dcc.qdelay_ms", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_brand, {
"Server Brand", "dcc.brand", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_ck_type, {
"Type", "dcc.checksum.type", FT_UINT8, BASE_DEC,
VALS(dcc_cktype_vals), 0, "Checksum Type", HFILL }},
{ &hf_dcc_ck_len, {
"Length", "dcc.checksum.length", FT_UINT8, BASE_DEC,
NULL, 0, "Checksum Length", HFILL }},
{ &hf_dcc_ck_sum, {
"Sum", "dcc.checksum.sum", FT_BYTES, BASE_NONE,
NULL, 0, "Checksum", HFILL }},
{ &hf_dcc_target, {
"Target", "dcc.target", FT_UINT32, BASE_HEX,
VALS(dcc_target_vals), 0, NULL, HFILL }},
{ &hf_dcc_date, {
"Date", "dcc.date", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_adminop, {
"Admin Op", "dcc.adminop", FT_UINT8, BASE_DEC,
VALS(dcc_adminop_vals), 0, NULL, HFILL }},
{ &hf_dcc_adminval, {
"Admin Value", "dcc.adminval", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_trace, {
"Trace Bits", "dcc.trace", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_dcc_trace_admin, {
"Admin Requests", "dcc.trace.admin", FT_BOOLEAN, 32,
NULL, 0x00000001, NULL, HFILL }},
{ &hf_dcc_trace_anon, {
"Anonymous Requests", "dcc.trace.anon", FT_BOOLEAN, 32,
NULL, 0x00000002, NULL, HFILL }},
{ &hf_dcc_trace_client, {
"Authenticated Client Requests", "dcc.trace.client", FT_BOOLEAN, 32,
NULL, 0x00000004, NULL, HFILL }},
{ &hf_dcc_trace_rlim, {
"Rate-Limited Requests", "dcc.trace.rlim", FT_BOOLEAN, 32,
NULL, 0x00000008, NULL, HFILL }},
{ &hf_dcc_trace_query, {
"Queries and Reports", "dcc.trace.query", FT_BOOLEAN, 32,
NULL, 0x00000010, NULL, HFILL }},
{ &hf_dcc_trace_ridc, {
"RID Cache Messages", "dcc.trace.ridc", FT_BOOLEAN, 32,
NULL, 0x00000020, NULL, HFILL }},
{ &hf_dcc_trace_flood, {
"Input/Output Flooding", "dcc.trace.flood", FT_BOOLEAN, 32,
NULL, 0x00000040, NULL, HFILL }},
{ &hf_dcc_floodop, {
"Flood Control Operation", "dcc.floodop", FT_UINT32, BASE_DEC,
VALS(dcc_floodop_vals), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcc,
&ett_dcc_op,
&ett_dcc_ck,
&ett_dcc_opnums,
&ett_dcc_trace,
};
proto_dcc = proto_register_protocol("Distributed Checksum Clearinghouse protocol",
"DCC", "dcc");
proto_register_field_array(proto_dcc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcc(void)
{
heur_dissector_add("udp", dissect_dcc, proto_dcc);
}
