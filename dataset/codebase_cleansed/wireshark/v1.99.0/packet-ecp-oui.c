static gint32
dissect_ecp_unknown_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint16 tempLen;
guint16 tempShort;
proto_tree *ecp_unknown_tlv_tree;
tempShort = tvb_get_ntohs(tvb, offset);
tempLen = TLV_INFO_LEN(tempShort);
ecp_unknown_tlv_tree = proto_tree_add_subtree(tree, tvb, offset, (tempLen + 2), ett_ecp, NULL, "Unknown TLV");
proto_tree_add_item(ecp_unknown_tlv_tree, hf_ecp_subtype, tvb, offset, 2, ENC_BIG_ENDIAN);
return -1;
}
static gint32
dissect_vdp_fi_macvid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
gint i;
guint16 entries;
guint32 tempOffset = offset;
const guint8 *mac_addr = NULL;
proto_tree *ecp_vdp_tlv_fi_subtree;
entries = tvb_get_ntohs(tvb, offset);
ecp_vdp_tlv_fi_subtree = proto_tree_add_subtree_format(tree, tvb, tempOffset, 2, ett_ecp, NULL,
"%i MAC/VID pair%s", entries, plurality((entries > 1), "s", ""));
tempOffset += 2;
for (i=0; i < entries; i++) {
mac_addr = tvb_get_ptr(tvb, tempOffset, 6);
if (tree) {
proto_tree_add_ether(ecp_vdp_tlv_fi_subtree, hf_ecp_vdp_mac, tvb, tempOffset, 6, mac_addr);
}
tempOffset += 6;
proto_tree_add_item(ecp_vdp_tlv_fi_subtree, hf_ecp_vdp_vlan, tvb, tempOffset, 2, ENC_BIG_ENDIAN);
tempOffset += 2;
}
return tempOffset-offset;
}
static gint32
dissect_vdp_org_specific_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint16 tempLen;
guint16 len;
guint16 tempShort;
guint32 tempOffset = offset;
guint32 oui;
const char *ouiStr;
guint8 subType, format;
const char *subTypeStr;
proto_tree *ecp_vdp_tlv_subtree;
tempLen = 0;
tempShort = tvb_get_ntohs(tvb, offset);
len = TLV_INFO_LEN(tempShort);
tempOffset += 2;
oui = tvb_get_ntoh24(tvb, (tempOffset));
ouiStr = val_to_str_const(oui, oui_vals, "Unknown");
if (strcmp(ouiStr, "Unknown")==0) {
ouiStr = uint_get_manuf_name_if_known(oui);
if(ouiStr==NULL) ouiStr="Unknown";
}
tempOffset += 3;
subType = tvb_get_guint8(tvb, tempOffset);
tempOffset++;
switch(oui) {
case OUI_IEEE_802_1QBG:
subTypeStr = val_to_str(subType, ieee_802_1qbg_subtypes, "Unknown subtype 0x%x");
break;
default:
subTypeStr = "Unknown";
break;
}
ecp_vdp_tlv_subtree = proto_tree_add_subtree_format(tree, tvb, offset, (len + 2), ett_ecp, NULL,
"%s - %s", ouiStr, subTypeStr);
proto_tree_add_item(ecp_vdp_tlv_subtree, hf_ecp_vdp_mode, tvb, tempOffset, 1, ENC_BIG_ENDIAN);
tempOffset++;
proto_tree_add_item(ecp_vdp_tlv_subtree, hf_ecp_vdp_response, tvb, tempOffset, 1, ENC_BIG_ENDIAN);
tempOffset++;
proto_tree_add_item(ecp_vdp_tlv_subtree, hf_ecp_vdp_mgrid, tvb, tempOffset, 1, ENC_BIG_ENDIAN);
tempOffset++;
proto_tree_add_item(ecp_vdp_tlv_subtree, hf_ecp_vdp_vsitypeid, tvb, tempOffset, 3, ENC_BIG_ENDIAN);
tempOffset += 3;
proto_tree_add_item(ecp_vdp_tlv_subtree, hf_ecp_vdp_vsitypeidversion, tvb, tempOffset, 1, ENC_BIG_ENDIAN);
tempOffset += 1;
proto_tree_add_item(ecp_vdp_tlv_subtree, hf_ecp_vdp_instanceid, tvb, tempOffset, 16, ENC_NA);
tempOffset += 16;
format = tvb_get_guint8(tvb, tempOffset);
proto_tree_add_item(ecp_vdp_tlv_subtree, hf_ecp_vdp_format, tvb, tempOffset, 1, ENC_BIG_ENDIAN);
tempOffset++;
switch (format) {
case VDP_FIF_VID:
case VDP_FIF_MACVID:
tempLen = dissect_vdp_fi_macvid(tvb, pinfo, ecp_vdp_tlv_subtree, tempOffset);
break;
case VDP_FIF_GROUPVID:
break;
case VDP_FIF_GROUPVMACVID:
break;
default:
break;
}
tempOffset += tempLen;
return tempOffset-offset;
}
static gint32
dissect_vdp_end_of_vdpdu_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint16 tempLen;
guint16 tempShort;
proto_tree *end_of_vdpdu_tree;
tempShort = tvb_get_ntohs(tvb, offset);
tempLen = TLV_INFO_LEN(tempShort);
if (tree)
{
end_of_vdpdu_tree = proto_tree_add_subtree(tree, tvb, offset, (tempLen + 2),
ett_end_of_vdpdu, NULL, "End of VDPDU");
proto_tree_add_item(end_of_vdpdu_tree, hf_ecp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(end_of_vdpdu_tree, hf_ecp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
}
return -1;
}
static void
dissect_ecp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ecp_tree;
proto_item *ti;
gint32 tempLen = 0;
guint32 offset = 0;
guint16 tempShort;
guint8 tempType;
gboolean end = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ECP");
ti = proto_tree_add_item(tree, proto_ecp, tvb, 0, -1, ENC_NA);
ecp_tree = proto_item_add_subtree(ti, ett_ecp);
proto_tree_add_item(ecp_tree, hf_ecp_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecp_tree, hf_ecp_mode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecp_tree, hf_ecp_sequence, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
while (!end) {
if (!tvb_bytes_exist(tvb, offset, 1))
break;
tempShort = tvb_get_ntohs(tvb, offset);
tempType = TLV_TYPE(tempShort);
switch (tempType) {
case ORG_SPECIFIC_TLV_TYPE:
tempLen = dissect_vdp_org_specific_tlv(tvb, pinfo, ecp_tree, offset);
break;
case END_OF_VDPDU_TLV_TYPE:
tempLen = dissect_vdp_end_of_vdpdu_tlv(tvb, pinfo, ecp_tree, offset);
break;
default:
tempLen = dissect_ecp_unknown_tlv(tvb, pinfo, ecp_tree, offset);
break;
}
offset += tempLen;
if (tempLen < 0)
end = TRUE;
}
}
void proto_register_ecp_oui(void)
{
static hf_register_info hf_reg = {
&hf_ecp_pid,
{ "PID", "ieee802a.ecp_pid", FT_UINT16, BASE_HEX,
VALS(ecp_pid_vals), 0x0, NULL, HFILL },
};
static hf_register_info hf[] = {
{ &hf_ecp_tlv_type,
{ "TLV Type", "ecp.tlv.type", FT_UINT16, BASE_DEC,
NULL, TLV_TYPE_MASK, NULL, HFILL }
},
{ &hf_ecp_tlv_len,
{ "TLV Length", "ecp.tlv.len", FT_UINT16, BASE_DEC,
NULL, TLV_INFO_LEN_MASK, NULL, HFILL }
},
{ &hf_ecp_subtype,
{ "subtype", "ecp.subtype", FT_UINT8, BASE_HEX,
VALS(ecp_subtypes), 0x0, NULL, HFILL },
},
{ &hf_ecp_mode,
{ "mode", "ecp.mode", FT_UINT8, BASE_HEX,
VALS(ecp_modes), 0x0, NULL, HFILL },
},
{ &hf_ecp_sequence,
{ "sequence number", "ecp.seq", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL },
},
#if 0
{ &hf_ecp_vdp_oui,
{ "Organization Unique Code", "ecp.vdp.oui", FT_UINT24, BASE_HEX,
VALS(oui_vals), 0x0, NULL, HFILL }
},
#endif
{ &hf_ecp_vdp_mode,
{ "mode", "ecp.vdp.mode", FT_UINT8, BASE_HEX,
VALS(ecp_vdp_modes), 0x0, NULL, HFILL },
},
{ &hf_ecp_vdp_response,
{ "response", "ecp.vdp.response", FT_UINT8, BASE_HEX,
VALS(ecp_vdp_responses), 0x0, NULL, HFILL },
},
{ &hf_ecp_vdp_mgrid,
{ "Manager ID", "ecp.vdp.mgrid", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL },
},
{ &hf_ecp_vdp_vsitypeid,
{ "VSI type ID", "ecp.vdp.vsitypeid", FT_UINT24, BASE_HEX,
NULL, 0x0, NULL, HFILL },
},
{ &hf_ecp_vdp_vsitypeidversion,
{ "VSI type ID version", "ecp.vdp.vsitypeidversion", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL },
},
{ &hf_ecp_vdp_instanceid,
{ "VSI Instance ID version", "ecp.vdp.instanceid", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL },
},
{ &hf_ecp_vdp_format,
{ "VSI filter info format", "ecp.vdp.format", FT_UINT8, BASE_HEX,
VALS(ecp_vdp_formats), 0x0, NULL, HFILL },
},
{ &hf_ecp_vdp_mac,
{ "VSI Mac Address", "ecp.vdp.mac", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ecp_vdp_vlan,
{ "VSI VLAN ID", "ecp.vdp.vlan", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_ecp,
&ett_end_of_vdpdu,
&ett_802_1qbg_capabilities_flags,
};
ieee802a_add_oui(OUI_IEEE_802_1QBG, "ieee802a.ecp_pid",
"IEEE802a ECP PID", &hf_reg);
proto_ecp = proto_register_protocol("ECP Protocol", "ECP", "ecp");
proto_register_field_array(proto_ecp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("ecp", dissect_ecp, proto_ecp);
}
void proto_reg_handoff_ecp(void)
{
static dissector_handle_t ecp_handle;
ecp_handle = find_dissector("ecp");
dissector_add_uint("ieee802a.ecp_pid", 0x0000, ecp_handle);
}
