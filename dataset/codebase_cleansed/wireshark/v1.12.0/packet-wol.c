static int
dissect_wol_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint len;
gint offset;
guint8 *mac;
const guint8 *passwd;
guint64 qword;
proto_item *ti;
proto_item *mti;
proto_tree *wol_tree;
proto_tree *mac_tree;
len = tvb_length(tvb);
if ( len < 102 )
return (0);
qword = tvb_get_ntoh48(tvb,0);
if(qword != G_GUINT64_CONSTANT(0xffffffffffff))
return (0);
mac = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, 6, 6);
for ( offset = 12; offset < 102; offset += 6 )
if ( tvb_memeql(tvb, offset, mac, 6) != 0 )
return (0);
if ( len >= 106 && len < 108 )
{
len = 106;
passwd = tvb_ip_to_str(tvb, 102);
}
else if ( len >= 108 )
{
len = 108;
passwd = tvb_ether_to_str(tvb, 102);
}
else
{
len = 102;
passwd = NULL;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WOL");
col_add_fstr(pinfo->cinfo, COL_INFO, "MagicPacket for %s (%s)",
get_ether_name(mac), ether_to_str(mac));
if ( passwd )
col_append_fstr(pinfo->cinfo, COL_INFO, ", password %s", passwd);
if (tree) {
ti = proto_tree_add_item(tree, proto_wol, tvb, 0, len, ENC_NA);
proto_item_append_text(ti, ", MAC: %s (%s)", get_ether_name(mac),
ether_to_str(mac));
if ( passwd )
proto_item_append_text(ti, ", password: %s", passwd);
wol_tree = proto_item_add_subtree(ti, ett_wol);
proto_tree_add_item(wol_tree, hf_wol_sync, tvb, 0, 6, ENC_NA);
mti = proto_tree_add_text(wol_tree, tvb, 6, 96, "MAC: %s (%s)",
get_ether_name(mac), ether_to_str(mac));
mac_tree = proto_item_add_subtree(mti, ett_wol_macblock);
for ( offset = 6; offset < 102; offset += 6 )
proto_tree_add_ether(mac_tree, hf_wol_mac, tvb, offset, 6, mac);
if ( len == 106 )
proto_tree_add_bytes_format_value(wol_tree, hf_wol_passwd, tvb, offset,
4, passwd, "%s", passwd);
else if ( len == 108 )
proto_tree_add_bytes_format_value(wol_tree, hf_wol_passwd, tvb, offset,
6, passwd, "%s", passwd);
}
return (len);
}
static int
dissect_wol(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
return dissect_wol_pdu(tvb, pinfo, tree, data);
}
static gboolean
dissect_wolheur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (dissect_wol_pdu(tvb, pinfo, tree, data) > 0)
return TRUE;
return FALSE;
}
void
proto_register_wol(void)
{
static hf_register_info hf[] = {
{ &hf_wol_sync,
{ "Sync stream", "wol.sync",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_wol_mac,
{ "MAC", "wol.mac",
FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_wol_passwd,
{ "Password", "wol.passwd",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_wol,
&ett_wol_macblock
};
proto_wol = proto_register_protocol("Wake On LAN", "WOL", "wol");
proto_register_field_array(proto_wol, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_wol(void)
{
dissector_handle_t wol_handle;
wol_handle = new_create_dissector_handle(dissect_wol, proto_wol);
dissector_add_uint("ethertype", ETHERTYPE_WOL, wol_handle);
heur_dissector_add("udp", dissect_wolheur, proto_wol);
}
