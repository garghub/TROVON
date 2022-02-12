static int dissect_aim_invitation_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *invite_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, invite_tree, aim_onlinebuddy_tlvs);
}
void
proto_register_aim_invitation(void)
{
static gint *ett[] = {
&ett_aim_invitation,
};
proto_aim_invitation = proto_register_protocol("AIM Invitation Service", "AIM Invitation", "aim_invitation");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_invitation(void)
{
aim_init_family(proto_aim_invitation, ett_aim_invitation, FAMILY_INVITATION, aim_fnac_family_invitation);
}
