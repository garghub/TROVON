static int dissect_aim_buddylist_buddylist(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
int offset = 0;
while (tvb_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_buddyname( tvb, pinfo, offset, buddy_tree);
}
return offset;
}
static int dissect_aim_buddylist_rights_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, buddy_tree, aim_buddylist_tlvs);
}
static int dissect_aim_buddylist_reject(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
return dissect_aim_buddyname(tvb, pinfo, 0, buddy_tree);
}
static int dissect_aim_buddylist_oncoming(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
guint8 *buddyname;
int offset = 0;
int buddyname_length = aim_get_buddyname( &buddyname, tvb, offset );
col_set_str(pinfo->cinfo, COL_INFO, "Oncoming Buddy");
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
format_text(buddyname, buddyname_length));
offset += dissect_aim_buddyname(tvb, pinfo, offset, buddy_tree);
proto_tree_add_item(buddy_tree, hf_aim_userinfo_warninglevel, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_aim_tlv_list(tvb, pinfo, offset, buddy_tree, aim_onlinebuddy_tlvs);
return offset;
}
static int dissect_aim_buddylist_offgoing(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
guint8 *buddyname;
int offset = 0;
int buddyname_length = aim_get_buddyname( &buddyname, tvb, offset );
col_set_str(pinfo->cinfo, COL_INFO, "Offgoing Buddy");
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
format_text(buddyname, buddyname_length));
offset += dissect_aim_buddyname(tvb, pinfo, offset, buddy_tree);
proto_tree_add_item(buddy_tree, hf_aim_userinfo_warninglevel, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
return dissect_aim_tlv_list(tvb, pinfo, offset, buddy_tree, aim_onlinebuddy_tlvs);
}
void
proto_register_aim_buddylist(void)
{
static hf_register_info hf[] = {
{ &hf_aim_userinfo_warninglevel,
{ "Warning Level", "aim_buddylist.userinfo.warninglevel", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
};
static gint *ett[] = {
&ett_aim_buddylist,
};
proto_aim_buddylist = proto_register_protocol("AIM Buddylist Service", "AIM Buddylist", "aim_buddylist");
proto_register_field_array(proto_aim_buddylist, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_buddylist(void)
{
aim_init_family(proto_aim_buddylist, ett_aim_buddylist, FAMILY_BUDDYLIST, aim_fnac_family_buddylist);
}
