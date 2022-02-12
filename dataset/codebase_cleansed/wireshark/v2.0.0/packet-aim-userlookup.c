static int dissect_aim_userlookup_search(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *lookup_tree)
{
proto_tree_add_item(lookup_tree, hf_aim_userlookup_email, tvb, 0, tvb_reported_length(tvb), ENC_UTF_8|ENC_NA);
return tvb_reported_length(tvb);
}
static int dissect_aim_userlookup_result(tvbuff_t *tvb, packet_info *pinfo, proto_tree *lookup_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, lookup_tree, aim_client_tlvs);
}
void
proto_register_aim_userlookup(void)
{
static hf_register_info hf[] = {
{ &hf_aim_userlookup_email,
{ "Email address looked for", "aim_lookup.email", FT_STRING, BASE_NONE, NULL, 0, "Email address", HFILL }
},
};
static gint *ett[] = {
&ett_aim_userlookup,
};
proto_aim_userlookup = proto_register_protocol("AIM User Lookup", "AIM User Lookup", "aim_lookup");
proto_register_field_array(proto_aim_userlookup, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_userlookup(void)
{
aim_init_family(proto_aim_userlookup, ett_aim_userlookup, FAMILY_USERLOOKUP, aim_fnac_family_userlookup);
}
