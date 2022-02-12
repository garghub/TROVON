static gboolean
capture_pktap(const guchar *pd, int offset _U_, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
guint32 hdrlen, rectype, dlt;
hdrlen = pletoh32(pd);
if (hdrlen < MIN_PKTAP_HDR_LEN || !BYTES_ARE_IN_FRAME(0, len, hdrlen))
return FALSE;
rectype = pletoh32(pd+4);
if (rectype != PKT_REC_PACKET)
return FALSE;
dlt = pletoh32(pd+4);
switch (dlt) {
case 1:
return call_capture_dissector(eth_cap_handle, pd, hdrlen, len, cpinfo, pseudo_header);
}
return FALSE;
}
static int
dissect_pktap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *pktap_tree = NULL;
proto_item *ti = NULL;
tvbuff_t *next_tvb;
int offset = 0;
guint32 pkt_len, rectype, dlt;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PKTAP");
col_clear(pinfo->cinfo, COL_INFO);
pkt_len = tvb_get_letohl(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "PKTAP, %u byte header", pkt_len);
ti = proto_tree_add_item(tree, proto_pktap, tvb, offset, pkt_len, ENC_NA);
pktap_tree = proto_item_add_subtree(ti, ett_pktap);
proto_tree_add_item(pktap_tree, hf_pktap_hdrlen, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
if (pkt_len < MIN_PKTAP_HDR_LEN) {
proto_tree_add_expert(tree, pinfo, &ei_pktap_hdrlen_too_short,
tvb, offset, 4);
return tvb_captured_length(tvb);
}
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_rectype, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
rectype = tvb_get_letohl(tvb, offset);
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_dlt, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
dlt = tvb_get_letohl(tvb, offset);
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_ifname, tvb, offset, 24,
ENC_ASCII|ENC_NA);
offset += 24;
proto_tree_add_item(pktap_tree, hf_pktap_flags, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_pfamily, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_llhdrlen, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_lltrlrlen, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_pid, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_cmdname, tvb, offset, 20,
ENC_UTF_8|ENC_NA);
offset += 20;
proto_tree_add_item(pktap_tree, hf_pktap_svc_class, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_iftype, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(pktap_tree, hf_pktap_ifunit, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(pktap_tree, hf_pktap_epid, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(pktap_tree, hf_pktap_ecmdname, tvb, offset, 20,
ENC_UTF_8|ENC_NA);
if (rectype == PKT_REC_PACKET) {
next_tvb = tvb_new_subset_remaining(tvb, pkt_len);
call_dissector_with_data(pcap_pktdata_handle, next_tvb,
pinfo, tree, &dlt);
}
return tvb_captured_length(tvb);
}
void
proto_register_pktap(void)
{
static hf_register_info hf[] = {
{ &hf_pktap_hdrlen,
{ "Header length", "pktap.hdrlen",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_rectype,
{ "Record type", "pktap.rectype",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_dlt,
{ "DLT", "pktap.dlt",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_ifname,
{ "Interface name", "pktap.ifname",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_flags,
{ "Flags", "pktap.flags",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_pfamily,
{ "Protocol family", "pktap.pfamily",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_llhdrlen,
{ "Link-layer header length", "pktap.llhdrlen",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_lltrlrlen,
{ "Link-layer trailer length", "pktap.lltrlrlen",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_pid,
{ "Process ID", "pktap.pid",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_cmdname,
{ "Command name", "pktap.cmdname",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_svc_class,
{ "Service class", "pktap.svc_class",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_iftype,
{ "Interface type", "pktap.iftype",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_ifunit,
{ "Interface unit", "pktap.ifunit",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_epid,
{ "Effective process ID", "pktap.epid",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pktap_ecmdname,
{ "Effective command name", "pktap.ecmdname",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_pktap,
};
static ei_register_info ei[] = {
{ &ei_pktap_hdrlen_too_short,
{ "pktap.hdrlen_too_short", PI_MALFORMED, PI_ERROR,
"Header length is too short", EXPFILL }},
};
expert_module_t* expert_pktap;
proto_pktap = proto_register_protocol("PKTAP packet header", "PKTAP",
"pktap");
proto_register_field_array(proto_pktap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pktap = expert_register_protocol(proto_pktap);
expert_register_field_array(expert_pktap, ei, array_length(ei));
pktap_handle = register_dissector("pktap", dissect_pktap, proto_pktap);
}
void
proto_reg_handoff_pktap(void)
{
capture_dissector_handle_t pktap_cap_handle;
dissector_add_uint("wtap_encap", WTAP_ENCAP_PKTAP, pktap_handle);
pcap_pktdata_handle = find_dissector_add_dependency("pcap_pktdata", proto_pktap);
pktap_cap_handle = create_capture_dissector_handle(capture_pktap, proto_pktap);
capture_dissector_add_uint("wtap_encap", WTAP_ENCAP_PKTAP, pktap_cap_handle);
capture_dissector_add_uint("wtap_encap", WTAP_ENCAP_USER2, pktap_cap_handle);
eth_cap_handle = find_capture_dissector("eth");
}
