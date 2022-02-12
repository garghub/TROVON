static void
dissect_wsmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *wsmdata_item;
proto_tree *wsmp_tree, *wsmdata_tree;
tvbuff_t *wsmdata_tvb;
guint16 acmlength, wsmlength, offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WSMP");
col_set_str(pinfo->cinfo, COL_INFO, "WAVE Short Message Protocol IEEE P1609.3");
if (tree) {
ti = proto_tree_add_item(tree, proto_wsmp, tvb, 0, -1, ENC_NA);
wsmp_tree = proto_item_add_subtree(ti, ett_wsmp);
offset = 0;
proto_tree_add_item(wsmp_tree,
hf_wsmp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(wsmp_tree,
hf_wsmp_security, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(wsmp_tree,
hf_wsmp_channel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(wsmp_tree,
hf_wsmp_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(wsmp_tree,
hf_wsmp_txpower, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(wsmp_tree,
hf_wsmp_appclass, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
acmlength = tvb_get_guint8(tvb,offset);
proto_tree_add_item(wsmp_tree,
hf_wsmp_acmlength, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(wsmp_tree, hf_wsmp_acm, tvb, offset, acmlength, ENC_ASCII|ENC_NA);
offset +=acmlength;
wsmlength = tvb_get_letohs( tvb, offset);
proto_tree_add_item(wsmp_tree,
hf_wsmp_wsmlength, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
wsmdata_item = proto_tree_add_text (wsmp_tree, tvb, offset, wsmlength,
"Wave Short Message");
wsmdata_tree = proto_item_add_subtree(wsmdata_item, ett_wsmdata);
wsmdata_tvb = tvb_new_subset(tvb, offset,wsmlength, wsmlength);
call_dissector(data_handle, wsmdata_tvb, pinfo, wsmdata_tree);
}
}
void
proto_register_wsmp(void)
{
static hf_register_info hf[] = {
{ &hf_wsmp_version,
{ "Version", "wsmp.version", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_security,
{ "Security", "wsmp.security", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_channel,
{ "Channel", "wsmp.channel", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_rate,
{ "Rate", "wsmp.rate", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_txpower,
{ "Transmit power", "wsmp.txpower", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_appclass,
{ "App class", "wsmp.appclass", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_acmlength,
{ "Acm Length", "wsmp.acmlength", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_acm,
{ "Application Context Data", "wsmp.acm", FT_STRING,
BASE_NONE, NULL, 0x0, "Acm", HFILL }},
{ &hf_wsmp_wsmlength,
{ "WSM Length", "wsmp.wsmlength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_wsmp,
&ett_wsmdata,
};
proto_wsmp = proto_register_protocol("Wave Short Message Protocol(IEEE P1609.3)",
"WSMP", "wsmp");
proto_register_field_array(proto_wsmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_wsmp(void)
{
dissector_handle_t wsmp_handle;
wsmp_handle = create_dissector_handle(dissect_wsmp, proto_wsmp);
dissector_add_uint("ethertype", ETHERTYPE_WSMP, wsmp_handle);
data_handle = find_dissector("data");
return;
}
