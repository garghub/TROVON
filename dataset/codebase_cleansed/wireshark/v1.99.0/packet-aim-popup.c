static int dissect_aim_popup(tvbuff_t *tvb, packet_info *pinfo, proto_tree *popup_tree)
{
return dissect_aim_tlv(tvb, pinfo, 0, popup_tree, aim_popup_tlvs);
}
void
proto_register_aim_popup(void)
{
static gint *ett[] = {
&ett_aim_popup,
};
proto_aim_popup = proto_register_protocol("AIM Popup", "AIM Popup", "aim_popup");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_popup(void)
{
aim_init_family(proto_aim_popup, ett_aim_popup, FAMILY_POPUP, aim_fnac_family_popup);
}
