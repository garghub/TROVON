static void dissect_caps(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree *captree;
captree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_iapp_cap, NULL, "Capabilities");
proto_tree_add_item(captree, hf_iapp_cap_forwarding, tvb, offset, 1, ENC_NA);
proto_tree_add_item(captree, hf_iapp_cap_wep, tvb, offset, 1, ENC_NA);
}
static void
add_authval_str(proto_tree *tree, int type, int len, tvbuff_t *tvb, int offset)
{
int val;
switch (type)
{
case IAPP_AUTH_STATUS:
val = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_iapp_auth_status, tvb, offset, 1, val, "%s", val ? "Authenticated" : "Not authenticated");
break;
case IAPP_AUTH_USERNAME:
case IAPP_AUTH_PROVNAME:
proto_tree_add_item(tree, hf_iapp_auth_string, tvb, offset, 1, ENC_ASCII|ENC_NA);
break;
case IAPP_AUTH_RXPKTS:
case IAPP_AUTH_TXPKTS:
case IAPP_AUTH_RXBYTES:
case IAPP_AUTH_TXBYTES:
case IAPP_AUTH_RXGWORDS:
case IAPP_AUTH_TXGWORDS:
case IAPP_AUTH_VOLLIMIT:
proto_tree_add_item(tree, hf_iapp_auth_uint, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case IAPP_AUTH_LOGINTIME:
case IAPP_AUTH_TIMELIMIT:
case IAPP_AUTH_ACCCYCLE:
val = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_iapp_auth_uint, tvb, offset, 4, val, "%d seconds", val);
break;
case IAPP_AUTH_IPADDR:
proto_tree_add_item(tree, hf_iapp_auth_ipaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case IAPP_AUTH_TRAILER:
proto_tree_add_item(tree, hf_iapp_auth_trailer, tvb, offset, len, ENC_NA);
break;
}
}
static void dissect_authinfo(proto_item *pitem, tvbuff_t *tvb, int offset, int sumlen)
{
proto_tree *authtree, *value_tree;
guint8 pdu_type;
guint16 len;
authtree = proto_item_add_subtree(pitem, ett_iapp_auth);
while (sumlen > 0)
{
pdu_type = tvb_get_guint8(tvb, offset);
len = tvb_get_ntohs(tvb, offset+1);
value_tree = proto_tree_add_subtree_format(authtree, tvb, offset, len + 3,
ett_iapp_authinfo, NULL, "%s (%d)",
val_to_str_const(pdu_type, iapp_auth_type_vals, "Unknown PDU Type"),
pdu_type);
add_authval_str(value_tree, pdu_type, len, tvb, offset+3);
sumlen -= (len + 3);
offset += (len + 3);
}
}
static gboolean
append_pduval_str(proto_tree *tree, int type, int len, tvbuff_t *tvb, int offset,
gboolean is_fhss)
{
int val;
switch (type)
{
case IAPP_PDU_SSID:
proto_tree_add_item(tree, hf_iapp_pdu_ssid, tvb, offset, len, ENC_ASCII|ENC_NA);
break;
case IAPP_PDU_BSSID:
case IAPP_PDU_OLDBSSID:
case IAPP_PDU_MSADDR:
proto_tree_add_item(tree, hf_iapp_pdu_bytes, tvb, offset, len, ENC_NA);
break;
case IAPP_PDU_CAPABILITY:
dissect_caps(tree, tvb, offset);
break;
case IAPP_PDU_ANNOUNCEINT:
val = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_iapp_pdu_uint, tvb, offset, 2, val, "%d seconds", val);
break;
case IAPP_PDU_HOTIMEOUT:
case IAPP_PDU_BEACONINT:
val = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_iapp_pdu_uint, tvb, offset, 2, val, "%d Kus", val);
break;
case IAPP_PDU_MESSAGEID:
proto_tree_add_item(tree, hf_iapp_pdu_uint, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case IAPP_PDU_PHYTYPE:
proto_tree_add_item(tree, hf_iapp_pdu_phytype, tvb, offset, 1, ENC_BIG_ENDIAN);
is_fhss = (tvb_get_guint8(tvb, offset) == IAPP_PHY_FHSS);
break;
case IAPP_PDU_REGDOMAIN:
proto_tree_add_item(tree, hf_iapp_pdu_regdomain, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case IAPP_PDU_CHANNEL:
if (is_fhss)
{
val = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_iapp_pdu_uint, tvb, offset, 1, val,
"Pattern set %d, sequence %d", ((val >> 6) & 3) + 1, (val & 31) + 1);
}
else
proto_tree_add_item(tree, hf_iapp_pdu_uint, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case IAPP_PDU_OUIIDENT:
proto_tree_add_item(tree, hf_iapp_pdu_oui_ident, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
}
return is_fhss;
}
static void
dissect_pdus(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *pdutree, proto_item *pduitem, int pdulen)
{
guint8 pdu_type;
guint16 len;
proto_item *ti;
gboolean is_fhss;
proto_tree *subtree;
if (!pdulen)
{
expert_add_info(pinfo, pduitem, &ei_iapp_no_pdus);
return;
}
is_fhss = FALSE;
while (pdulen > 0)
{
pdu_type = tvb_get_guint8(tvb, offset);
len = tvb_get_ntohs(tvb, offset+1);
subtree = proto_tree_add_subtree_format(pdutree, tvb, offset, len + 3,
ett_iapp_subpdu, &ti, "%s (%d)",
val_to_str_const(pdu_type, iapp_pdu_type_vals, "Unknown PDU Type"),
pdu_type);
is_fhss = append_pduval_str(subtree, pdu_type, len, tvb,
offset+3, is_fhss);
if (pdu_type == IAPP_PDU_AUTHINFO)
dissect_authinfo(ti, tvb, offset + 3, len);
pdulen -= (len + 3);
offset += (len + 3);
}
}
static int
dissect_iapp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *pduitem;
proto_tree *iapp_tree, *pdutree;
guint8 ia_version;
guint8 ia_type;
const gchar *codestrval;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IAPP");
col_clear(pinfo->cinfo, COL_INFO);
ia_version = tvb_get_guint8(tvb, 0);
ia_type = tvb_get_guint8(tvb, 1);
codestrval = val_to_str_const(ia_type, iapp_vals, "Unknown Packet");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s(%d) (version=%d)", codestrval, ia_type, ia_version);
ti = proto_tree_add_item(tree, proto_iapp, tvb, 0, -1, ENC_NA);
iapp_tree = proto_item_add_subtree(ti, ett_iapp);
proto_tree_add_item(iapp_tree, hf_iapp_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(iapp_tree, hf_iapp_type, tvb, 1, 1, ENC_BIG_ENDIAN);
pdutree = proto_tree_add_subtree(iapp_tree, tvb, 2, -1,
ett_iapp_pdu, &pduitem, "Protocol data units");
dissect_pdus(tvb, pinfo, 2, pdutree, pduitem,
tvb_captured_length_remaining(tvb, 2));
return tvb_captured_length(tvb);
}
void
proto_register_iapp(void)
{
static hf_register_info hf[] = {
{ &hf_iapp_version,
{ "Version", "iapp.version", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_type,
{ "Type", "iapp.type", FT_UINT8, BASE_DEC, VALS(iapp_vals), 0x00, NULL, HFILL }
},
{ &hf_iapp_cap_forwarding,
{ "Forwarding", "iapp.cap.forwarding", FT_BOOLEAN, 8, TFS(&tfs_yes_no), IAPP_CAP_FORWARDING, NULL, HFILL }
},
{ &hf_iapp_cap_wep,
{ "WEP", "iapp.cap.wep", FT_BOOLEAN, 8, TFS(&tfs_yes_no), IAPP_CAP_WEP, NULL, HFILL }
},
{ &hf_iapp_auth_status,
{ "Status", "iapp.auth.status", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_auth_uint,
{ "Value", "iapp.auth.uint", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_auth_string,
{ "Value", "iapp.auth.string", FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_auth_ipaddr,
{ "IP Address", "iapp.auth.ipaddr", FT_IPv4, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_auth_trailer,
{ "Trailer", "iapp.auth.trailer", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_pdu_ssid,
{ "SSID", "iapp.pdu.ssid", FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_pdu_bytes,
{ "Value", "iapp.pdu.bytes", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_pdu_uint,
{ "Value", "iapp.pdu.uint", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_pdu_phytype,
{ "PHY Type", "iapp.pdu.phytype", FT_UINT8, BASE_DEC, VALS(iapp_phy_vals), 0x00, NULL, HFILL }
},
{ &hf_iapp_pdu_regdomain,
{ "Reg domain", "iapp.pdu.regdomain", FT_UINT8, BASE_DEC, VALS(iapp_dom_vals), 0x00, NULL, HFILL }
},
{ &hf_iapp_pdu_oui_ident,
{ "OUI", "iapp.pdu.oui_ident", FT_UINT24, BASE_DEC, VALS(oui_vals), 0x00, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_iapp,
&ett_iapp_pdu,
&ett_iapp_subpdu,
&ett_iapp_cap,
&ett_iapp_auth,
&ett_iapp_authinfo
};
static ei_register_info ei[] = {
{ &ei_iapp_no_pdus, { "iapp.no_pdus", PI_PROTOCOL, PI_NOTE, "No PDUs found", EXPFILL }},
};
expert_module_t* expert_iapp;
proto_iapp = proto_register_protocol("Inter-Access-Point Protocol", "IAPP", "iapp");
proto_register_field_array(proto_iapp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_iapp = expert_register_protocol(proto_iapp);
expert_register_field_array(expert_iapp, ei, array_length(ei));
}
void
proto_reg_handoff_iapp(void)
{
dissector_handle_t iapp_handle;
iapp_handle = create_dissector_handle(dissect_iapp, proto_iapp);
dissector_add_uint("udp.port", UDP_PORT_IAPP, iapp_handle);
}
