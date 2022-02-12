static int dissect_aim_location_rightsinfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *loc_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, loc_tree, aim_location_rights_tlvs);
}
static int dissect_aim_location_setuserinfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *loc_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, loc_tree, aim_locate_tags_tlvs);
}
static int dissect_aim_location_watcher_notification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *loc_tree)
{
int offset = 0;
while (tvb_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_buddyname(tvb, pinfo, offset, loc_tree);
}
return offset;
}
static int dissect_aim_location_user_info_query(tvbuff_t *tvb, packet_info *pinfo, proto_tree *loc_tree)
{
return dissect_aim_buddyname(tvb, pinfo, 4, loc_tree);
}
static int dissect_aim_snac_location_request_user_information(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint8 buddyname_length = 0;
proto_tree_add_item(tree, hf_aim_snac_location_request_user_info_infotype,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
buddyname_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_aim_buddyname_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_aim_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
return offset;
}
static int dissect_aim_snac_location_user_information(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint8 buddyname_length = 0;
buddyname_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_aim_buddyname_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_aim_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
proto_tree_add_item(tree, hf_aim_userinfo_warninglevel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_aim_tlv_list(tvb, pinfo, offset, tree, aim_onlinebuddy_tlvs);
return dissect_aim_tlv_sequence(tvb, pinfo, offset, tree, aim_locate_tags_tlvs);
}
void
proto_register_aim_location(void)
{
static hf_register_info hf[] = {
{ &hf_aim_buddyname_len,
{ "Buddyname len", "aim_location.buddynamelen", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_buddyname,
{ "Buddy Name", "aim_location.buddyname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_userinfo_warninglevel,
{ "Warning Level", "aim_location.userinfo.warninglevel", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_snac_location_request_user_info_infotype,
{ "Infotype", "aim_location.snac.request_user_info.infotype", FT_UINT16, BASE_HEX, VALS(aim_snac_location_request_user_info_infotypes), 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_aim_location,
};
proto_aim_location = proto_register_protocol("AIM Location", "AIM Location", "aim_location");
proto_register_field_array(proto_aim_location, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_location(void)
{
aim_init_family(proto_aim_location, ett_aim_location, FAMILY_LOCATION, aim_fnac_family_location);
}
