static int
dissect_ns_rpc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint16 rpc_errcode;
guint32 datalen, rpc_cmd, remote_ioctl;
int offset = 0;
proto_item *ti;
proto_tree *ns_rpc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NS-RPC");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_ns_rpc, tvb, 0, -1, ENC_NA);
ns_rpc_tree = proto_item_add_subtree(ti, ett_nsrpc);
proto_tree_add_item_ret_uint(ns_rpc_tree, hf_nsrpc_dlen, tvb, offset, 4, ENC_LITTLE_ENDIAN, &datalen);
offset += 8;
proto_tree_add_item_ret_uint(ns_rpc_tree, hf_nsrpc_cmd, tvb, offset, 1, ENC_LITTLE_ENDIAN, &rpc_cmd);
offset += 2;
if (rpc_cmd & 0x80)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Resp: %s", val_to_str((rpc_cmd&(~0x80)), ns_rpc_cmd_vals, "0x%02X"));
proto_tree_add_item(ns_rpc_tree, hf_nsrpc_errcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Req: %s", val_to_str(rpc_cmd, ns_rpc_cmd_vals, "0x%02X"));
}
rpc_errcode = tvb_get_letohs(tvb, offset);
offset += 2;
offset += 4;
if ((rpc_cmd&(~0x80)) == 0x02)
{
proto_tree_add_item_ret_uint(ns_rpc_tree, hf_ns_remoteIOCTL, tvb, offset, 4, ENC_LITTLE_ENDIAN, &remote_ioctl);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_ext(remote_ioctl, &ns_rpc_rioctl_vals_ext, "0x%04X"));
}
if (rpc_cmd & 0x80)
{
if ((rpc_cmd&(~0x80)) == 0x02)
col_append_fstr(pinfo->cinfo, COL_INFO, "; ErrCode: %s", val_to_str(tvb_get_letohl(tvb, (offset+12)), ns_rpc_errcode_vals, "0x%04X"));
else
col_append_fstr(pinfo->cinfo, COL_INFO, "; Status: %s", val_to_str(rpc_errcode, ns_rpc_errcode_vals, "0x%04X"));
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_ns_rpc_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
guint16 ns_rpc_sig;
if (tvb_reported_length(tvb) < 6)
return FALSE;
ns_rpc_sig = tvb_get_letohs(tvb, 4);
if (ns_rpc_sig != 0xA5A5)
return FALSE;
dissect_ns_rpc_heur(tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_ns_rpc(void)
{
static hf_register_info hf_nsrpc[] = {
{ &hf_nsrpc_dlen,
{ "Data Len", "nstrace.rpc.dlen", FT_UINT32, BASE_DEC,NULL, 0x0,
NULL, HFILL }},
{ &hf_nsrpc_cmd,
{ "Command", "nstrace.rpc.cmd", FT_UINT8, BASE_HEX, VALS(ns_rpc_cmd_vals), 0x0,
NULL, HFILL }},
{ &hf_nsrpc_errcode,
{ "Status Code", "nstrace.rpc.errcode", FT_UINT16, BASE_HEX, VALS(ns_rpc_errcode_vals), 0x0,
NULL, HFILL }},
{ &hf_ns_remoteIOCTL,
{ "Remote IOCTL", "nstrace.mep.mfu.remoteIOCTL", FT_UINT32, BASE_HEX|BASE_EXT_STRING, &ns_rpc_rioctl_vals_ext, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_nsrpc,
};
proto_ns_rpc = proto_register_protocol("NetScaler RPC Protocol", "NetScaler RPC", "nstrace.rpc");
proto_register_field_array(proto_ns_rpc, hf_nsrpc, array_length(hf_nsrpc));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("nsrpc", dissect_ns_rpc, proto_ns_rpc);
}
void proto_reg_handoff_ns_rpc(void)
{
heur_dissector_add("tcp", dissect_ns_rpc_heur, "netscaler-nsrpc", "nsrpc", proto_ns_rpc, HEURISTIC_DISABLE);
}
