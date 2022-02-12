static int dissect_aim_snac_signon_logon(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
int offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_tlv(tvb, pinfo, offset, tree, aim_client_tlvs);
}
return offset;
}
static int dissect_aim_snac_signon_logon_reply(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree)
{
int offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_tlv(tvb, pinfo, offset, tree, aim_client_tlvs);
}
return offset;
}
static int dissect_aim_snac_signon_signon(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
guint8 buddyname_length = 0;
int offset = 0;
guint8 *buddyname;
proto_tree_add_item(tree, hf_aim_infotype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 1;
buddyname_length = aim_get_buddyname( &buddyname, tvb, offset );
col_append_fstr(pinfo->cinfo, COL_INFO, " Username: %s",
format_text(buddyname, buddyname_length));
if(tree) {
offset+=dissect_aim_buddyname(tvb, pinfo, offset, tree);
}
return offset;
}
static int dissect_aim_snac_signon_signon_reply(tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree)
{
int offset = 0;
guint16 challenge_length = 0;
challenge_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_aim_signon_challenge_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_aim_signon_challenge, tvb, offset, challenge_length, ENC_UTF_8|ENC_NA);
offset += challenge_length;
return offset;
}
static int dissect_aim_tlv_value_registration(proto_item *ti _U_, guint16 value_id _U_, tvbuff_t *tvb _U_, packet_info *pinfo _U_)
{
return 0;
}
static int dissect_aim_snac_register (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return dissect_aim_tlv(tvb, pinfo, 0, tree, aim_registration_tlvs);
}
void
proto_register_aim_signon(void)
{
static hf_register_info hf[] = {
{ &hf_aim_infotype,
{ "Infotype", "aim_signon.infotype", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_signon_challenge_len,
{ "Signon challenge length", "aim_signon.challengelen", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_signon_challenge,
{ "Signon challenge", "aim_signon.challenge", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_aim_signon,
};
proto_aim_signon = proto_register_protocol("AIM Signon", "AIM Signon", "aim_signon");
proto_register_field_array(proto_aim_signon, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_signon(void)
{
aim_init_family(proto_aim_signon, ett_aim_signon, FAMILY_SIGNON, aim_fnac_family_signon);
}
