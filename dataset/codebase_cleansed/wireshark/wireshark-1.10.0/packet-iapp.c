static void dissect_caps(proto_item *pitem, tvbuff_t *tvb, int offset)
{
proto_tree *captree;
int bit, val, thisbit;
const gchar *strval;
gchar bitval[4+1+4+1];
captree = proto_item_add_subtree(pitem, ett_iapp_cap);
val = tvb_get_guint8(tvb, offset + 3);
for (bit = 7; bit >= 0; bit--)
{
thisbit = 1 << bit;
strval = try_val_to_str(thisbit, iapp_cap_vals);
if (strval)
{
other_decode_bitfield_value(bitval, val, thisbit, 8);
proto_tree_add_text(captree, tvb, offset + 3, 1, "%s %s: %s",
bitval, strval, val & thisbit ? "Yes" : "No");
}
}
}
static void
append_authval_str(proto_item *ti, int type, int len, tvbuff_t *tvb, int offset)
{
int z, val;
proto_item_append_text(ti, " Value: ");
switch (type)
{
case IAPP_AUTH_STATUS:
proto_item_append_text(ti, "%s", tvb_get_guint8(tvb, offset + 3) ? "Authenticated" : "Not authenticated");
break;
case IAPP_AUTH_USERNAME:
case IAPP_AUTH_PROVNAME:
proto_item_append_text(ti, "\"%s\"",
tvb_format_text(tvb, offset + 3, len));
break;
case IAPP_AUTH_RXPKTS:
case IAPP_AUTH_TXPKTS:
case IAPP_AUTH_RXBYTES:
case IAPP_AUTH_TXBYTES:
case IAPP_AUTH_RXGWORDS:
case IAPP_AUTH_TXGWORDS:
case IAPP_AUTH_VOLLIMIT:
val = tvb_get_ntohl(tvb, offset + 3);
proto_item_append_text(ti, "%d", val);
break;
case IAPP_AUTH_LOGINTIME:
case IAPP_AUTH_TIMELIMIT:
case IAPP_AUTH_ACCCYCLE:
val = tvb_get_ntohl(tvb, offset + 3);
proto_item_append_text(ti, "%d seconds", val);
break;
case IAPP_AUTH_IPADDR:
proto_item_append_text(ti, "%s", tvb_ip_to_str(tvb, offset + 3));
break;
case IAPP_AUTH_TRAILER:
for (z = 0; z < len; z++)
proto_item_append_text(ti, "%s%02x", z ? " " : "",
tvb_get_guint8(tvb, offset + 3 + z));
break;
}
}
static void dissect_authinfo(proto_item *pitem, tvbuff_t *tvb, int offset, int sumlen)
{
proto_tree *authtree;
proto_item *ti;
e_pduhdr pduhdr;
int len;
authtree = proto_item_add_subtree(pitem, ett_iapp_auth);
while (sumlen > 0)
{
tvb_memcpy(tvb, (guint8 *)&pduhdr, offset, sizeof(e_pduhdr));
len = (((int)pduhdr.pdu_len_h) << 8) + pduhdr.pdu_len_l;
ti = proto_tree_add_text(authtree, tvb, offset, len + 3,
"%s(%d)",
val_to_str_const(pduhdr.pdu_type, iapp_auth_type_vals,
"Unknown PDU Type"),
pduhdr.pdu_type);
append_authval_str(ti, pduhdr.pdu_type, len, tvb, offset);
sumlen -= (len + 3);
offset += (len + 3);
}
}
static gboolean
append_pduval_str(proto_item *ti, int type, int len, tvbuff_t *tvb, int offset,
gboolean is_fhss)
{
int z, val;
const gchar *strval;
proto_item_append_text(ti, " Value: ");
switch (type)
{
case IAPP_PDU_SSID:
proto_item_append_text(ti, "\"%s\"",
tvb_format_text(tvb, offset + 3, len));
break;
case IAPP_PDU_BSSID:
case IAPP_PDU_OLDBSSID:
case IAPP_PDU_MSADDR:
for (z = 0; z < len; z++)
proto_item_append_text(ti, "%s%02x", z ? ":" : "",
tvb_get_guint8(tvb, offset + 3 + z));
break;
case IAPP_PDU_CAPABILITY:
{
int mask, first = 1;
val = tvb_get_guint8(tvb, offset + 3);
proto_item_append_text(ti, "%02x (", val);
for (mask = 0x80; mask; mask >>= 1)
if (val & mask)
{
strval = try_val_to_str(mask, iapp_cap_vals);
if (strval)
{
if (!first)
proto_item_append_text(ti, " ");
proto_item_append_text(ti, "%s", strval);
first=0;
}
}
proto_item_append_text(ti, ")");
break;
}
case IAPP_PDU_ANNOUNCEINT:
val = tvb_get_ntohs(tvb, offset + 3);
proto_item_append_text(ti, "%d seconds", val);
break;
case IAPP_PDU_HOTIMEOUT:
case IAPP_PDU_BEACONINT:
val = tvb_get_ntohs(tvb, offset + 3);
proto_item_append_text(ti, "%d Kus", val);
break;
case IAPP_PDU_MESSAGEID:
val = tvb_get_ntohs(tvb, offset + 3);
proto_item_append_text(ti, "%d", val);
break;
case IAPP_PDU_PHYTYPE:
val = tvb_get_guint8(tvb, offset + 3);
strval = val_to_str_const(val, iapp_phy_vals, "Unknown");
proto_item_append_text(ti, "%s", strval);
is_fhss = (val == IAPP_PHY_FHSS);
break;
case IAPP_PDU_REGDOMAIN:
val = tvb_get_guint8(tvb, offset + 3);
strval = val_to_str_const(val, iapp_dom_vals, "Unknown");
proto_item_append_text(ti, "%s", strval);
break;
case IAPP_PDU_CHANNEL:
val = tvb_get_guint8(tvb, offset + 3);
if (is_fhss)
proto_item_append_text(ti, "Pattern set %d, sequence %d",
((val >> 6) & 3) + 1, (val & 31) + 1);
else
proto_item_append_text(ti, "%d", val);
break;
case IAPP_PDU_OUIIDENT:
for (val = z = 0; z < 3; z++)
val = (val << 8) | tvb_get_guint8(tvb, offset + 3 + z);
strval = val_to_str_const(val, oui_vals, "Unknown");
proto_item_append_text(ti, "%s", strval);
break;
}
return is_fhss;
}
static void
dissect_pdus(tvbuff_t *tvb, int offset, proto_tree *pdutree, int pdulen)
{
e_pduhdr pduhdr;
int len;
proto_item *ti;
gboolean is_fhss;
if (!pdulen)
{
proto_tree_add_text(pdutree, tvb, offset, 0, "No PDUs found");
return;
}
is_fhss = FALSE;
while (pdulen > 0)
{
tvb_memcpy(tvb, (guint8 *)&pduhdr, offset, sizeof(e_pduhdr));
len = (((int)pduhdr.pdu_len_h) << 8) + pduhdr.pdu_len_l;
ti = proto_tree_add_text(pdutree, tvb, offset, len + 3,
"%s(%d)",
val_to_str_const(pduhdr.pdu_type, iapp_pdu_type_vals,
"Unknown PDU Type"),
pduhdr.pdu_type);
is_fhss = append_pduval_str(ti, pduhdr.pdu_type, len, tvb,
offset, is_fhss);
if (pduhdr.pdu_type == IAPP_PDU_CAPABILITY)
dissect_caps(ti, tvb, offset);
if (pduhdr.pdu_type == IAPP_PDU_AUTHINFO)
dissect_authinfo(ti, tvb, offset + 3, len);
pdulen -= (len + 3);
offset += (len + 3);
}
}
static void
dissect_iapp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *pdutf;
proto_tree *iapp_tree, *pdutree;
e_iapphdr ih;
int ia_version;
int ia_type;
const gchar *codestrval;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IAPP");
col_clear(pinfo->cinfo, COL_INFO);
tvb_memcpy(tvb, (guint8 *)&ih, 0, sizeof(e_iapphdr));
ia_version = (int)ih.ia_version;
ia_type = (int)ih.ia_type;
codestrval = val_to_str_const(ia_type, iapp_vals, "Unknown Packet");
if (check_col(pinfo->cinfo, COL_INFO))
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s(%d) (version=%d)",
codestrval, ia_type, ia_version);
}
if (tree)
{
ti = proto_tree_add_item(tree, proto_iapp, tvb, 0, -1, ENC_NA);
iapp_tree = proto_item_add_subtree(ti, ett_iapp);
proto_tree_add_uint(iapp_tree, hf_iapp_version, tvb, 0, 1,
ih.ia_version);
proto_tree_add_uint_format(iapp_tree, hf_iapp_type, tvb, 1, 1,
ih.ia_type, "Type: %s(%d)", codestrval, ia_type);
pdutf = proto_tree_add_text(iapp_tree, tvb, 2, -1,
"Protocol data units");
pdutree = proto_item_add_subtree(pdutf, ett_iapp_pdu);
if (pdutree)
{
dissect_pdus(tvb, 2, pdutree,
tvb_length_remaining(tvb, 2));
}
}
}
void
proto_register_iapp(void)
{
static hf_register_info hf[] = {
{ &hf_iapp_version,
{ "Version", "iapp.version", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_iapp_type,
{ "type", "iapp.type", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_iapp,
&ett_iapp_pdu,
&ett_iapp_cap,
&ett_iapp_auth
};
proto_iapp = proto_register_protocol("Inter-Access-Point Protocol",
"IAPP", "iapp");
proto_register_field_array(proto_iapp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_iapp(void)
{
dissector_handle_t iapp_handle;
iapp_handle = create_dissector_handle(dissect_iapp, proto_iapp);
dissector_add_uint("udp.port", UDP_PORT_IAPP, iapp_handle);
}
