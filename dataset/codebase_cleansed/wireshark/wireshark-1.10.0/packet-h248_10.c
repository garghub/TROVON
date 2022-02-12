void proto_register_h248_dot10(void) {
static hf_register_info hf[] = {
{ &hf_h248_CHP_mgcon, { "MGCon", "h248.chp.mgcon", FT_BYTES, BASE_NONE, NULL, 0, "This event occurs when the MG requires that the MGC start or finish load reduction.", HFILL }},
{ &hf_h248_CHP_mgcon_reduction, { "Reduction", "h248.chp.mgcon.reduction", FT_UINT32, BASE_DEC, NULL, 0, "Percentage of the load that the MGC is requested to block", HFILL }},
};
static gint *ett[] = {
&ett_h248_CHP,
&ett_h248_CHP_mgcon,
};
proto_h248_CHP = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h248_CHP, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
h248_register_package(&h248_pkg_CHP,REPLACE_PKG);
}
