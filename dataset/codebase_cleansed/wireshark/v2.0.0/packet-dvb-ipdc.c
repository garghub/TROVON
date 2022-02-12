static void
dissect_ipdc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_tree *esg_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPDC");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
proto_item *ti;
ti = proto_tree_add_protocol_format(tree, proto_ipdc, tvb, 0, -1,
"ESG Bootstrap");
esg_tree = proto_item_add_subtree(ti, ett_ipdc);
}
next_tvb = tvb_new_subset_remaining(tvb, 0);
call_dissector(sub_handles[DVB_IPDC_SUB_FLUTE], next_tvb, pinfo, esg_tree);
}
void
proto_register_dvb_ipdc(void)
{
#if 0
static hf_register_info hf[] = {
{&hf_ipdc_esg_bootstrap_xml,
{"ESG Provider Discovery", "dvb_ipdc.bootstrap",
FT_STRING, BASE_NONE, NULL, 0x0, "List of ESG Providers", HFILL}}
};
#endif
static gint *ett[] = {
&ett_ipdc,
};
proto_ipdc = proto_register_protocol("ETSI IPDC Bootstrap",
"ESG Bootstrap", "dvb_ipdc");
#if 0
proto_register_field_array(proto_ipdc, hf, array_length(hf));
#endif
proto_register_subtree_array(ett, array_length(ett));
register_dissector("dvb_ipdc", dissect_ipdc, proto_ipdc);
}
void
proto_reg_handoff_dvb_ipdc(void)
{
dissector_handle_t ipdc_handle;
sub_handles[DVB_IPDC_SUB_FLUTE] = find_dissector("alc");
ipdc_handle = create_dissector_handle(dissect_ipdc, proto_ipdc);
dissector_add_uint("udp.port", UDP_PORT_IPDC_ESG_BOOTSTRAP, ipdc_handle);
}
