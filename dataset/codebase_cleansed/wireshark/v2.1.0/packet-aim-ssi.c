static int calc_ssi_entry_size(tvbuff_t *tvb, int offset)
{
gint ssi_entry_size = 2 + tvb_get_ntohs(tvb, offset) + 2 * 3;
ssi_entry_size += tvb_get_ntohs(tvb, offset + ssi_entry_size) + 2;
return ssi_entry_size;
}
static int dissect_ssi_item(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *ssi_entry)
{
guint16 buddyname_length = 0;
int endoffset;
guint16 tlv_len = 0;
buddyname_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_buddyname_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (buddyname_length > 0) {
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
}
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_gid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_bid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tlv_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_tlvlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
endoffset = offset;
while(endoffset < offset+tlv_len) {
endoffset = dissect_aim_tlv(tvb, pinfo, endoffset, ssi_entry, aim_client_tlvs);
}
return endoffset;
}
static int dissect_ssi_ssi_item(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ssi_entry)
{
return dissect_ssi_item(tvb, pinfo, 0, ssi_entry);
}
static int dissect_ssi_ssi_items(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
gint ssi_entry_size;
proto_tree *ssi_entry = NULL;
int size = tvb_reported_length(tvb);
while (size > offset)
{
ssi_entry_size = calc_ssi_entry_size(tvb, offset);
ssi_entry = proto_tree_add_subtree(tree, tvb, offset, ssi_entry_size, ett_aim_ssi, NULL, "SSI Entry");
offset = dissect_ssi_item(tvb, pinfo, offset, ssi_entry);
}
return offset;
}
static int dissect_aim_ssi_rightsinfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ssi_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, ssi_tree, aim_ssi_rightsinfo_tlvs);
}
static int dissect_aim_ssi_was_added(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ssi_tree)
{
return dissect_aim_buddyname(tvb, pinfo, 0, ssi_tree);
}
static int dissect_aim_snac_ssi_time_and_items_num(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
nstime_t tmptime;
tmptime.secs = tvb_get_ntohl(tvb, offset);
tmptime.nsecs = 0;
proto_tree_add_time(tree, hf_aim_fnac_subtype_ssi_last_change_time, tvb, offset, 4, &tmptime);
offset += 4;
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_numitems, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_aim_snac_ssi_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
proto_tree *ssi_entry = NULL;
guint16 num_items, i;
nstime_t tmptime;
gint ssi_entry_size;
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_numitems, tvb, offset, 2, ENC_BIG_ENDIAN);
num_items = tvb_get_ntohs(tvb, offset);
offset += 2;
for(i = 0; i < num_items; i++) {
ssi_entry_size = calc_ssi_entry_size(tvb, offset);
ssi_entry = proto_tree_add_subtree_format(tree, tvb, offset, ssi_entry_size,
ett_aim_ssi, NULL, "SSI Entry %u", i);
offset = dissect_ssi_item(tvb, pinfo, offset, ssi_entry);
}
tmptime.secs = tvb_get_ntohl(tvb, offset);
tmptime.nsecs = 0;
proto_tree_add_time(tree, hf_aim_fnac_subtype_ssi_last_change_time, tvb, offset, 4, &tmptime);
return offset;
}
static int dissect_aim_snac_ssi_auth_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 reason_length;
guint8 buddyname_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_buddyname_len8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (buddyname_length > 0) {
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
}
reason_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_reason_str_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (reason_length > 0) {
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_reason_str, tvb, offset, reason_length, ENC_UTF_8|ENC_NA);
offset += reason_length;
}
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_grant_auth_unkn, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_aim_snac_ssi_auth_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 reason_length;
guint8 buddyname_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_buddyname_len8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (buddyname_length > 0) {
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
}
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_allow_auth, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
reason_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_reason_str_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (reason_length > 0) {
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_reason_str, tvb, offset, reason_length, ENC_UTF_8|ENC_NA);
offset += reason_length;
}
return offset;
}
void
proto_register_aim_ssi(void)
{
static hf_register_info hf[] = {
{ &hf_aim_fnac_subtype_ssi_version,
{ "SSI Version", "aim_ssi.fnac.version", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_numitems,
{ "SSI Object count", "aim_ssi.fnac.numitems", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_last_change_time,
{ "SSI Last Change Time", "aim_ssi.fnac.last_change_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_buddyname_len,
{ "SSI Buddy Name length", "aim_ssi.fnac.buddyname_len", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_buddyname,
{ "Buddy Name", "aim_ssi.fnac.buddyname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_gid,
{ "SSI Buddy Group ID", "aim_ssi.fnac.gid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_bid,
{ "SSI Buddy ID", "aim_ssi.fnac.bid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_type,
{ "SSI Buddy type", "aim_ssi.fnac.type", FT_UINT16, BASE_HEX, VALS(aim_fnac_family_ssi_types), 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_tlvlen,
{ "SSI TLV Len", "aim_ssi.fnac.tlvlen", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
#if 0
{ &hf_aim_fnac_subtype_ssi_data,
{ "SSI Buddy Data", "aim_ssi.fnac.data", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_aim_fnac_subtype_ssi_buddyname_len8,
{ "SSI Buddy Name length", "aim_ssi.fnac.buddyname_len8", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_reason_str_len,
{ "Reason Message length", "aim_ssi.fnac.reason_len", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_reason_str,
{ "Reason Message", "aim_ssi.fnac.reason", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_grant_auth_unkn,
{ "Unknown", "aim_ssi.fnac.auth_unkn", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_allow_auth,
{ "Allow flag", "aim_ssi.fnac.allow_auth_flag", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_aim_ssi,
&ett_ssi,
};
proto_aim_ssi = proto_register_protocol("AIM Server Side Info", "AIM SSI", "aim_ssi");
proto_register_field_array(proto_aim_ssi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_aim_ssi(void)
{
aim_init_family(proto_aim_ssi, ett_aim_ssi, FAMILY_SSI, aim_fnac_family_ssi);
}
