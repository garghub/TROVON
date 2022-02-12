static int
dissect_mip_priv_ext_3gpp2(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
guint16 type;
int length = tvb_reported_length(tvb);
type = tvb_get_ntohs(tvb,offset);
proto_tree_add_item(tree, hf_mip_nvse_3gpp2_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
switch(type){
case 16:
proto_tree_add_item(tree, hf_mip_nvse_3gpp2_type16_value, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 17:
proto_tree_add_item(tree, hf_mip_nvse_3gpp2_type17_entity, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_mip_nvse_3gpp2_type17_subtype1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_mip_nvse_3gpp2_type17_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_mip_nvse_3gpp2_type17_prim_dns, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_mip_nvse_3gpp2_type17_subtype2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_mip_nvse_3gpp2_type17_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_mip_nvse_3gpp2_type17_sec_dns, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_mip_data_not_dissected, tvb, offset, -1);
break;
}
return length;
}
static void
dissect_mip_extensions( tvbuff_t *tvb, int offset, proto_tree *tree, packet_info *pinfo)
{
proto_tree *exts_tree=NULL;
proto_tree *ext_tree;
proto_tree *tf;
proto_tree *ext_flags_tree;
proto_tree *pmipv4_tree;
gint ext_len;
guint8 ext_type;
guint8 ext_subtype=0;
guint8 pmipv4skipext_subscriberid_type;
guint16 flags;
gint hdrLen;
guint32 cvse_vendor_id;
guint16 cvse_3gpp2_type;
int cvse_local_offset= 0;
int nvse_local_offset= 0;
if (!tree) return;
exts_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_mip_exts, NULL, "Extensions");
while (tvb_reported_length_remaining(tvb, offset) > 0) {
ext_type = tvb_get_guint8(tvb, offset);
if (ext_type == GEN_AUTH_EXT || ext_type == PMIPv4_NON_SKIP_EXT) {
ext_subtype = tvb_get_guint8(tvb, offset + 1);
ext_len = tvb_get_ntohs(tvb, offset + 2);
hdrLen = 4;
}
else if(ext_type==CVSE_EXT){
ext_len = tvb_get_ntohs(tvb, offset + 2);
hdrLen = 4;
}
else {
ext_len = tvb_get_guint8(tvb, offset + 1);
hdrLen = 2;
}
ext_tree = proto_tree_add_subtree_format(exts_tree, tvb, offset, ext_len + hdrLen,
ett_mip_ext, NULL, "Extension: %s",
val_to_str(ext_type, mip_ext_types,
"Unknown Extension %u"));
proto_tree_add_uint(ext_tree, hf_mip_ext_type, tvb, offset, 1, ext_type);
offset++;
if (ext_type != GEN_AUTH_EXT &&
ext_type != PMIPv4_NON_SKIP_EXT &&
ext_type != CVSE_EXT) {
proto_tree_add_uint(ext_tree, hf_mip_ext_len, tvb, offset, 1, ext_len);
offset++;
}
switch (ext_type) {
case MH_AUTH_EXT:
case MF_AUTH_EXT:
case FH_AUTH_EXT:
proto_tree_add_item(ext_tree, hf_mip_aext_spi, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_mip_aext_auth, tvb, offset+4, ext_len-4, ENC_NA);
break;
case MN_NAI_EXT:
proto_tree_add_item(ext_tree, hf_mip_next_nai, tvb, offset,
ext_len, ENC_ASCII|ENC_NA);
break;
case GEN_AUTH_EXT:
proto_tree_add_uint(ext_tree, hf_mip_gaext_stype, tvb, offset, 1, ext_subtype);
offset++;
proto_tree_add_uint(ext_tree, hf_mip_ext_len, tvb, offset, 2, ext_len);
offset+=2;
proto_tree_add_item(ext_tree, hf_mip_aext_spi, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_mip_aext_auth, tvb, offset + 4,
ext_len - 4, ENC_NA);
break;
case REV_SUPP_EXT:
flags = tvb_get_ntohs(tvb, offset);
tf = proto_tree_add_uint(ext_tree, hf_mip_rext_flags, tvb, offset, 2, flags);
ext_flags_tree = proto_item_add_subtree(tf, ett_mip_flags);
proto_tree_add_boolean(ext_flags_tree, hf_mip_rext_i, tvb, offset, 2, flags);
proto_tree_add_uint(ext_flags_tree, hf_mip_rext_reserved, tvb, offset, 2, flags);
proto_tree_add_item(ext_tree, hf_mip_rext_tstamp, tvb, offset + 2, 4, ENC_BIG_ENDIAN);
break;
case DYN_HA_EXT:
proto_tree_add_item(ext_tree, hf_mip_dhaext_stype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_mip_dhaext_addr, tvb, offset + 1, 4, ENC_BIG_ENDIAN);
break;
case MSG_STR_EXT:
proto_tree_add_item(ext_tree, hf_mip_mstrext_stype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_mip_mstrext_text, tvb, offset + 1, ext_len-1, ENC_ASCII|ENC_NA);
break;
case UDP_TUN_REQ_EXT:
proto_tree_add_item(ext_tree, hf_mip_utrqext_stype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_mip_utrqext_reserved1, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, offset + 2);
tf = proto_tree_add_uint(ext_tree, hf_mip_utrqext_flags, tvb, offset + 2, 1, flags);
ext_flags_tree = proto_item_add_subtree(tf, ett_mip_flags);
proto_tree_add_boolean(ext_flags_tree, hf_mip_utrqext_f, tvb, offset + 2, 1, flags);
proto_tree_add_boolean(ext_flags_tree, hf_mip_utrqext_r, tvb, offset + 2, 1, flags);
proto_tree_add_uint(ext_flags_tree, hf_mip_utrqext_reserved2, tvb, offset + 2, 1, flags);
proto_tree_add_item(ext_tree, hf_mip_utrqext_encap_type, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_mip_utrqext_reserved3, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
break;
case UDP_TUN_REP_EXT:
proto_tree_add_item(ext_tree, hf_mip_utrpext_stype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_mip_utrpext_code, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
flags = tvb_get_ntohs(tvb, offset+2);
tf = proto_tree_add_uint(ext_tree, hf_mip_utrpext_flags, tvb, offset + 2, 2, flags);
ext_flags_tree = proto_item_add_subtree(tf, ett_mip_flags);
proto_tree_add_boolean(ext_flags_tree, hf_mip_utrpext_f, tvb, offset + 2, 2, flags);
proto_tree_add_uint(ext_flags_tree, hf_mip_utrpext_reserved, tvb, offset + 2, 2, flags);
proto_tree_add_item(ext_tree, hf_mip_utrpext_keepalive, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
break;
case PMIPv4_NON_SKIP_EXT:
proto_tree_add_uint(ext_tree, hf_mip_pmipv4nonskipext_stype, tvb, offset, 1, ext_subtype);
offset++;
proto_tree_add_uint(ext_tree, hf_mip_ext_len, tvb, offset, 2, ext_len);
offset+=2;
if(ext_subtype == 1){
proto_tree_add_item(ext_tree, hf_mip_pmipv4nonskipext_pernodeauthmethod, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case PMIPv4_SKIP_EXT:
ext_subtype = tvb_get_guint8(tvb, offset);
pmipv4_tree = proto_tree_add_subtree_format(ext_tree, tvb, offset, ext_len,
ett_mip_pmipv4_ext, NULL, "PMIPv4 Sub-Type: %s",
val_to_str(ext_subtype, mip_pmipv4skipext_stypes, "Unknown Sub-Type %u"));
proto_tree_add_uint(pmipv4_tree, hf_mip_pmipv4skipext_stype, tvb, offset, 1, ext_subtype);
if (ext_subtype == PMIPv4_SKIPEXT_STYPE_INTERFACE_ID) {
proto_tree_add_item(pmipv4_tree, hf_mip_pmipv4skipext_interfaceid, tvb, offset + 1, ext_len-1, ENC_NA);
} else if (ext_subtype == PMIPv4_SKIPEXT_STYPE_DEVICE_ID) {
proto_tree_add_item(pmipv4_tree, hf_mip_pmipv4skipext_deviceid_type, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pmipv4_tree, hf_mip_pmipv4skipext_deviceid_id, tvb, offset + 2, ext_len - 2, ENC_NA);
} else if (ext_subtype == PMIPv4_SKIPEXT_STYPE_SUBSCRIBER_ID) {
pmipv4skipext_subscriberid_type = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_uint(pmipv4_tree, hf_mip_pmipv4skipext_subscriberid_type, tvb, offset + 1, 1, pmipv4skipext_subscriberid_type);
if (pmipv4skipext_subscriberid_type == 1) {
proto_tree_add_item(pmipv4_tree, hf_mip_pmipv4skipext_subscriberid_id, tvb, offset + 2, ext_len - 2, ENC_NA);
}
} else if (ext_subtype == PMIPv4_SKIPEXT_STYPE_ACCESS_TECHNOLOGY) {
proto_tree_add_item(pmipv4_tree, hf_mip_pmipv4skipext_accesstechnology_type, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
break;
case OLD_CVSE_EXT:
case CVSE_EXT:
proto_tree_add_item(ext_tree, hf_mip_cvse_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_uint(ext_tree, hf_mip_ext_len, tvb, offset, 2, ext_len);
offset+=2;
cvse_local_offset = offset;
proto_tree_add_item(ext_tree, hf_mip_cvse_vendor_org_id, tvb, cvse_local_offset, 4, ENC_BIG_ENDIAN);
cvse_vendor_id = tvb_get_ntohl(tvb, cvse_local_offset);
cvse_local_offset+=4;
if( cvse_vendor_id == VENDOR_VERIZON ){
proto_tree_add_item(ext_tree, hf_mip_cvse_verizon_cvse_type, tvb, cvse_local_offset, 2, ENC_BIG_ENDIAN);
}else if( cvse_vendor_id == VENDOR_THE3GPP2 ){
cvse_3gpp2_type = tvb_get_ntohs(tvb, cvse_local_offset);
if(cvse_3gpp2_type == GRE_KEY_EXT){
proto_tree_add_item(ext_tree, hf_mip_cvse_3gpp2_grekey, tvb, cvse_local_offset, ext_len - 6, ENC_NA);
}
}else{
proto_tree_add_item(ext_tree, hf_mip_cvse_vendor_cvse_type, tvb, cvse_local_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_mip_cvse_vendor_cvse_value, tvb, cvse_local_offset, ext_len - 6, ENC_NA);
}
break;
case OLD_NVSE_EXT:
case NVSE_EXT:
{
guint32 nvse_vendor_org_id;
tvbuff_t *next_tvb;
proto_tree_add_item(ext_tree, hf_mip_nvse_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
nvse_local_offset = offset + hdrLen;
nvse_vendor_org_id = tvb_get_ntohl(tvb, nvse_local_offset);
proto_tree_add_item(ext_tree, hf_mip_nvse_vendor_org_id, tvb, nvse_local_offset, 4, ENC_BIG_ENDIAN);
nvse_local_offset+=4;
next_tvb = tvb_new_subset_length(tvb, nvse_local_offset, ext_len-6);
if (!dissector_try_uint(mip_nvse_ext_dissector_table, nvse_vendor_org_id, next_tvb, pinfo, ext_tree)){
proto_tree_add_item(ext_tree, hf_mip_nvse_vendor_nvse_type, tvb, nvse_local_offset, 2, ENC_BIG_ENDIAN);
nvse_local_offset+=2;
proto_tree_add_item(ext_tree, hf_mip_nvse_vendor_nvse_value, tvb, nvse_local_offset, ext_len - 8, ENC_NA);
}
}
break;
case MF_CHALLENGE_EXT:
default:
proto_tree_add_item(ext_tree, hf_mip_ext, tvb, offset, ext_len, ENC_NA);
break;
}
offset += ext_len;
}
}
static void
dissect_mip( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *mip_tree=NULL;
proto_item *tf;
proto_tree *flags_tree;
guint8 type;
guint16 flags;
gint offset=0;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MobileIP");
col_clear(pinfo->cinfo, COL_INFO);
type = tvb_get_guint8(tvb, offset);
switch (type) {
case MIP_REGISTRATION_REQUEST:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Reg Request: HoA=%s HA=%s CoA=%s",
tvb_ip_to_str(tvb, 4),
tvb_ip_to_str(tvb, 8),
tvb_ip_to_str(tvb, 12));
if (tree) {
ti = proto_tree_add_item(tree, proto_mip, tvb, offset, -1, ENC_NA);
mip_tree = proto_item_add_subtree(ti, ett_mip);
proto_tree_add_uint(mip_tree, hf_mip_type, tvb, offset, 1, type);
offset++;
flags = tvb_get_guint8(tvb, offset);
tf = proto_tree_add_uint(mip_tree, hf_mip_flags, tvb, offset, 1, flags);
flags_tree = proto_item_add_subtree(tf, ett_mip_flags);
proto_tree_add_boolean(flags_tree, hf_mip_s, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_mip_b, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_mip_d, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_mip_m, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_mip_g, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_mip_v, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_mip_t, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_mip_x, tvb, offset, 1, flags);
offset++;
proto_tree_add_item(mip_tree, hf_mip_life, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mip_tree, hf_mip_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mip_tree, hf_mip_haaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mip_tree, hf_mip_coa, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mip_tree, hf_mip_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
case MIP_REGISTRATION_REPLY:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Reg Reply: HoA=%s HA=%s, Code=%u",
tvb_ip_to_str(tvb, 4),
tvb_ip_to_str(tvb, 8),
tvb_get_guint8(tvb,1));
if (tree) {
ti = proto_tree_add_item(tree, proto_mip, tvb, offset, -1, ENC_NA);
mip_tree = proto_item_add_subtree(ti, ett_mip);
proto_tree_add_uint(mip_tree, hf_mip_type, tvb, offset, 1, type);
offset++;
proto_tree_add_item(mip_tree, hf_mip_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mip_tree, hf_mip_life, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mip_tree, hf_mip_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mip_tree, hf_mip_haaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mip_tree, hf_mip_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
case MIP_NATT_TUNNEL_DATA:
col_add_fstr(pinfo->cinfo, COL_INFO, "Tunnel Data: Next Header=%u",
tvb_get_guint8(tvb,1));
if (tree) {
ti = proto_tree_add_item(tree, proto_mip, tvb, offset, -1, ENC_NA);
mip_tree = proto_item_add_subtree(ti, ett_mip);
proto_tree_add_uint(mip_tree, hf_mip_type, tvb, offset, 1, type);
offset++;
proto_tree_add_item(mip_tree, hf_mip_nattt_nexthdr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mip_tree, hf_mip_nattt_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else {
offset += 4;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ip_handle, next_tvb, pinfo, mip_tree);
offset = tvb_reported_length(tvb);
break;
case MIP_REGISTRATION_REVOCATION:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Reg Revocation: HoA=%s HDA=%s FDA=%s",
tvb_ip_to_str(tvb, 4),
tvb_ip_to_str(tvb, 8),
tvb_ip_to_str(tvb, 12));
if (tree) {
ti = proto_tree_add_item(tree, proto_mip, tvb, offset, -1, ENC_NA);
mip_tree = proto_item_add_subtree(ti, ett_mip);
proto_tree_add_uint(mip_tree, hf_mip_type, tvb, offset, 1, type);
offset++;
proto_tree_add_item(mip_tree, hf_mip_rev_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
flags = tvb_get_ntohs(tvb, offset);
tf = proto_tree_add_uint(mip_tree, hf_mip_flags, tvb, offset, 2, flags);
flags_tree = proto_item_add_subtree(tf, ett_mip_flags);
proto_tree_add_boolean(flags_tree, hf_mip_rev_a, tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree, hf_mip_rev_i, tvb, offset, 2, flags);
proto_tree_add_uint(flags_tree, hf_mip_rev_reserved, tvb, offset, 2, flags);
offset += 2;
proto_tree_add_item(mip_tree, hf_mip_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mip_tree, hf_mip_hda, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mip_tree, hf_mip_fda, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mip_tree, hf_mip_revid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case MIP_REGISTRATION_REVOCATION_ACK:
col_add_fstr(pinfo->cinfo, COL_INFO, "Reg Revocation Ack: HoA=%s",
tvb_ip_to_str(tvb, 4));
if (tree) {
ti = proto_tree_add_item(tree, proto_mip, tvb, offset, -1, ENC_NA);
mip_tree = proto_item_add_subtree(ti, ett_mip);
proto_tree_add_uint(mip_tree, hf_mip_type, tvb, offset, 1, type);
offset++;
proto_tree_add_item(mip_tree, hf_mip_ack_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
flags = tvb_get_ntohs(tvb, offset);
tf = proto_tree_add_uint(mip_tree, hf_mip_flags, tvb, offset, 2, flags);
flags_tree = proto_item_add_subtree(tf, ett_mip_flags);
proto_tree_add_boolean(flags_tree, hf_mip_ack_i, tvb, offset, 2, flags);
proto_tree_add_uint(flags_tree, hf_mip_ack_reserved, tvb, offset, 2, flags);
offset += 2;
proto_tree_add_item(mip_tree, hf_mip_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mip_tree, hf_mip_revid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
}
if (tree) {
if (tvb_reported_length_remaining(tvb, offset) > 0)
dissect_mip_extensions(tvb, offset, mip_tree, pinfo);
}
}
void proto_register_mip(void)
{
static hf_register_info hf[] = {
{ &hf_mip_type,
{ "Message Type", "mip.type",
FT_UINT8, BASE_DEC, VALS(mip_types), 0,
"Mobile IP Message type.", HFILL }
},
{ &hf_mip_flags,
{"Flags", "mip.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_mip_s,
{"Simultaneous Bindings", "mip.s",
FT_BOOLEAN, 8, NULL, 128,
"Simultaneous Bindings Allowed", HFILL }
},
{ &hf_mip_b,
{"Broadcast Datagrams", "mip.b",
FT_BOOLEAN, 8, NULL, 64,
"Broadcast Datagrams requested", HFILL }
},
{ &hf_mip_d,
{ "Co-located Care-of Address", "mip.d",
FT_BOOLEAN, 8, NULL, 32,
"MN using Co-located Care-of address", HFILL }
},
{ &hf_mip_m,
{"Minimal Encapsulation", "mip.m",
FT_BOOLEAN, 8, NULL, 16,
"MN wants Minimal encapsulation", HFILL }
},
{ &hf_mip_g,
{"GRE", "mip.g",
FT_BOOLEAN, 8, NULL, 8,
"MN wants GRE encapsulation", HFILL }
},
{ &hf_mip_v,
{ "Van Jacobson", "mip.v",
FT_BOOLEAN, 8, NULL, 4,
NULL, HFILL }
},
{ &hf_mip_t,
{ "Reverse Tunneling", "mip.t",
FT_BOOLEAN, 8, NULL, 2,
"Reverse tunneling requested", HFILL }
},
{ &hf_mip_x,
{ "Reserved", "mip.x",
FT_BOOLEAN, 8, NULL, 1,
NULL, HFILL }
},
{ &hf_mip_code,
{ "Reply Code", "mip.code",
FT_UINT8, BASE_DEC, VALS(mip_reply_codes), 0,
"Mobile IP Reply code.", HFILL }
},
{ &hf_mip_life,
{ "Lifetime", "mip.life",
FT_UINT16, BASE_DEC, NULL, 0,
"Mobile IP Lifetime.", HFILL }
},
{ &hf_mip_homeaddr,
{ "Home Address", "mip.homeaddr",
FT_IPv4, BASE_NONE, NULL, 0,
"Mobile Node's home address.", HFILL }
},
{ &hf_mip_haaddr,
{ "Home Agent", "mip.haaddr",
FT_IPv4, BASE_NONE, NULL, 0,
"Home agent IP Address.", HFILL }
},
{ &hf_mip_coa,
{ "Care of Address", "mip.coa",
FT_IPv4, BASE_NONE, NULL, 0,
"Care of Address.", HFILL }
},
{ &hf_mip_ident,
{ "Identification", "mip.ident",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"MN Identification.", HFILL }
},
{ &hf_mip_ext_type,
{ "Extension Type", "mip.ext.type",
FT_UINT8, BASE_DEC, VALS(mip_ext_types), 0,
"Mobile IP Extension Type.", HFILL }
},
{ &hf_mip_gaext_stype,
{ "Gen Auth Ext SubType", "mip.ext.auth.subtype",
FT_UINT8, BASE_DEC, VALS(mip_gaext_stypes), 0,
"Mobile IP Auth Extension Sub Type.", HFILL }
},
{ &hf_mip_ext_len,
{ "Extension Length", "mip.ext.len",
FT_UINT16, BASE_DEC, NULL, 0,
"Mobile IP Extension Length.", HFILL }
},
{ &hf_mip_ext,
{ "Extension", "mip.extension",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_aext_spi,
{ "SPI", "mip.auth.spi",
FT_UINT32, BASE_HEX, NULL, 0,
"Authentication Header Security Parameter Index.", HFILL }
},
{ &hf_mip_aext_auth,
{ "Authenticator", "mip.auth.auth",
FT_BYTES, BASE_NONE, NULL, 0,
"Authenticator.", HFILL }
},
{ &hf_mip_next_nai,
{ "NAI", "mip.nai",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_rext_flags,
{"Rev Ext Flags", "mip.ext.rev.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Revocation Support Extension Flags", HFILL}
},
{ &hf_mip_rext_i,
{ "'I' bit Support", "mip.ext.rev.i",
FT_BOOLEAN, 16, NULL, 32768,
"Agent supports Inform bit in Revocation", HFILL }
},
{ &hf_mip_rext_reserved,
{ "Reserved", "mip.ext.rev.reserved",
FT_UINT16, BASE_HEX, NULL, 0x7fff,
NULL, HFILL }
},
{ &hf_mip_rext_tstamp,
{ "Timestamp", "mip.ext.rev.tstamp",
FT_UINT32, BASE_DEC, NULL, 0,
"Revocation Timestamp of Sending Agent", HFILL }
},
{ &hf_mip_rev_reserved,
{ "Reserved", "mip.rev.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_mip_rev_a,
{ "Home Agent", "mip.rev.a",
FT_BOOLEAN, 16, NULL, 32768,
"Revocation sent by Home Agent", HFILL }
},
{ &hf_mip_rev_i,
{ "Inform", "mip.rev.i",
FT_BOOLEAN, 16, NULL, 16384,
"Inform Mobile Node", HFILL }
},
#if 0
{ &hf_mip_rev_reserved2,
{ "Reserved", "mip.rev.reserved2",
FT_UINT16, BASE_HEX, NULL, 0x3fff,
NULL, HFILL}},
#endif
{ &hf_mip_hda,
{ "Home Domain Address", "mip.rev.hda",
FT_IPv4, BASE_NONE, NULL, 0,
"Revocation Home Domain IP Address", HFILL }
},
{ &hf_mip_fda,
{ "Foreign Domain Address", "mip.rev.fda",
FT_IPv4, BASE_NONE, NULL, 0,
"Revocation Foreign Domain IP Address", HFILL }
},
{ &hf_mip_revid,
{ "Revocation Identifier", "mip.revid",
FT_UINT32, BASE_DEC, NULL, 0,
"Revocation Identifier of Initiating Agent", HFILL }
},
{ &hf_mip_ack_reserved,
{ "Reserved", "mip.ack.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_mip_ack_i,
{ "Inform", "mip.ack.i",
FT_BOOLEAN, 16, NULL, 32768,
"Inform Mobile Node", HFILL }
},
#if 0
{ &hf_mip_ack_reserved2,
{ "Reserved", "mip.ack.reserved2",
FT_UINT16, BASE_HEX, NULL, 0x7fff,
NULL, HFILL}},
#endif
{ &hf_mip_dhaext_stype,
{ "DynHA Ext SubType", "mip.ext.dynha.subtype",
FT_UINT8, BASE_DEC, VALS(mip_dhaext_stypes), 0,
"Dynamic HA Extension Sub-type", HFILL }
},
{ &hf_mip_dhaext_addr,
{ "DynHA Home Agent", "mip.ext.dynha.ha",
FT_IPv4, BASE_NONE, NULL, 0,
"Dynamic Home Agent IP Address", HFILL }
},
{ &hf_mip_mstrext_stype,
{ "MsgStr Ext SubType", "mip.ext.msgstr.subtype",
FT_UINT8, BASE_DEC, VALS(mip_mstrext_stypes), 0,
"Message String Extension Sub-type", HFILL }
},
{ &hf_mip_mstrext_text,
{ "MsgStr Text", "mip.ext.msgstr.text",
FT_STRING, BASE_NONE, NULL, 0,
"Message String Extension Text", HFILL }
},
{ &hf_mip_nattt_nexthdr,
{ "NATTT NextHeader", "mip.nattt.nexthdr",
FT_UINT8, BASE_DEC, VALS(mip_nattt_nexthdr), 0,
"NAT Traversal Tunnel Next Header.", HFILL }
},
{ &hf_mip_nattt_reserved,
{ "Reserved", "mip.nattt.reserved",
FT_UINT16, BASE_HEX, NULL , 0x0,
NULL, HFILL }
},
{ &hf_mip_utrqext_stype,
{ "UDP TunReq Ext SubType", "mip.ext.utrq.subtype",
FT_UINT8, BASE_DEC, VALS(mip_utrqext_stypes), 0,
"UDP Tunnel Request Extension Sub-type", HFILL }
},
{ &hf_mip_utrqext_reserved1,
{ "Reserved 1", "mip.ext.utrq.reserved1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip_utrqext_flags,
{ "UDP TunReq Ext Flags", "mip.ext.utrq.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"UDP Tunnel Request Extension Flags", HFILL }
},
{ &hf_mip_utrqext_f,
{ "Req Forced", "mip.ext.utrq.f",
FT_BOOLEAN, 8, NULL, 128,
"MN wants to Force UDP Tunneling", HFILL }
},
{ &hf_mip_utrqext_r,
{ "FA Registration Required", "mip.ext.utrq.r",
FT_BOOLEAN, 8, NULL, 64,
"Registration through FA Required", HFILL }
},
{ &hf_mip_utrqext_reserved2,
{ "Reserved 2", "mip.ext.utrq.reserved2",
FT_UINT8, BASE_HEX, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_mip_utrqext_encap_type,
{ "UDP Encap Type", "mip.ext.utrq.encaptype",
FT_UINT8, BASE_DEC, VALS(mip_utrqext_encap_types), 0,
"UDP Encapsulation Type", HFILL }
},
{ &hf_mip_utrqext_reserved3,
{ "Reserved 3", "mip.ext.utrq.reserved3",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip_utrpext_stype,
{ "UDP TunRep Ext SubType", "mip.ext.utrp.subtype",
FT_UINT8, BASE_DEC, VALS(mip_utrpext_stypes), 0,
"UDP Tunnel Reply Extension Sub-type", HFILL }
},
{ &hf_mip_utrpext_code,
{ "UDP TunRep Code", "mip.ext.utrp.code",
FT_UINT8, BASE_DEC, VALS(mip_utrpext_codes), 0,
"UDP Tunnel Reply Code", HFILL }
},
{ &hf_mip_utrpext_flags,
{ "UDP TunRep Ext Flags", "mip.ext.utrp.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
"UDP Tunnel Request Extension Flags", HFILL }
},
{ &hf_mip_utrpext_f,
{ "Rep Forced", "mip.ext.utrp.f",
FT_BOOLEAN, 16, NULL, 32768,
"HA wants to Force UDP Tunneling", HFILL }
},
{ &hf_mip_utrpext_reserved,
{ "Reserved", "mip.ext.utrp.reserved",
FT_UINT16, BASE_HEX, NULL, 0x7fff,
NULL, HFILL }
},
{ &hf_mip_utrpext_keepalive,
{ "Keepalive Interval", "mip.ext.utrp.keepalive",
FT_UINT16, BASE_DEC, NULL, 0,
"NAT Keepalive Interval", HFILL }
},
{ &hf_mip_pmipv4nonskipext_stype,
{ "Sub-type", "mip.ext.pmipv4nonskipext.subtype",
FT_UINT8, BASE_DEC, VALS(mip_pmipv4nonskipext_stypes), 0,
"PMIPv4 Skippable Extension Sub-type", HFILL }
},
{ &hf_mip_pmipv4nonskipext_pernodeauthmethod,
{ "Per-Node Authentication Method", "mip.ext.pmipv4nonskipext.pernodeauthmethod",
FT_UINT8, BASE_DEC, VALS(mip_pmipv4nonskipext_pernodeauthmethod_types), 0,
NULL, HFILL }
},
{ &hf_mip_pmipv4skipext_stype,
{ "Sub-type", "mip.ext.pmipv4skipext.subtype",
FT_UINT8, BASE_DEC, VALS(mip_pmipv4skipext_stypes), 0,
"PMIPv4 Non-skippable Extension Sub-type", HFILL }
},
{ &hf_mip_pmipv4skipext_interfaceid,
{ "Interface ID", "mip.ext.pmipv4skipext.interfaceid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_pmipv4skipext_deviceid_type,
{ "ID-Type", "mip.ext.pmipv4skipext.deviceid_type",
FT_UINT8, BASE_DEC, VALS(mip_pmipv4skipext_deviceid_types), 0,
"Device ID-Type", HFILL }
},
{ &hf_mip_pmipv4skipext_deviceid_id,
{ "Identifier", "mip.ext.pmipv4skipext.deviceid_id",
FT_BYTES, BASE_NONE, NULL, 0,
"Device ID Identifier", HFILL }
},
{ &hf_mip_pmipv4skipext_subscriberid_type,
{ "ID-Type", "mip.ext.pmipv4skipext.subscriberid_type",
FT_UINT8, BASE_DEC, VALS(mip_pmipv4skipext_subscriberid_types), 0,
"Subscriber ID-Type", HFILL }
},
{ &hf_mip_pmipv4skipext_subscriberid_id,
{ "Identifier", "mip.ext.pmipv4skipext.subscriberid_id",
FT_BYTES, BASE_NONE, NULL, 0,
"Subscriber ID Identifier", HFILL }
},
{ &hf_mip_pmipv4skipext_accesstechnology_type,
{ "Access Technology Type", "mip.ext.pmipv4skipext.accesstechnology_type",
FT_UINT8, BASE_DEC, VALS(mip_pmipv4skipext_accesstechnology_types), 0,
NULL, HFILL }
},
{ &hf_mip_cvse_reserved,
{ "CVSE Reserved", "mip.ext.cvse.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip_cvse_vendor_org_id,
{ "CVSE Vendor/org ID", "mip.ext.cvse.vendor_id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0,
NULL, HFILL }
},
{ &hf_mip_cvse_verizon_cvse_type ,
{ "Verizon CVSE Type", "mip.ext.cvse.verizon_type",
FT_UINT16, BASE_DEC, VALS(mip_cvse_verizon_cvse_types), 0,
NULL, HFILL }
},
#if 0
{ &hf_mip_cvse_3gpp2_cvse_type ,
{ "3GPP2 CVSE Type","mip.ext.cvse.3gpp2_type",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
#endif
{ &hf_mip_cvse_3gpp2_grekey,
{ "GRE Key","mip.ext.cvse.3gpp2_grekey",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_cvse_vendor_cvse_type,
{ "Vendor CVSE Type", "mip.ext.cvse.vendor_type",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip_cvse_vendor_cvse_value,
{ "Vendor CVSE Value", "mip.ext.cvse.vendor_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_nvse_reserved,
{ "Reserved", "mip.ext.nvse.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip_nvse_vendor_org_id,
{ "Vendor ID", "mip.ext.nvse.vendor_id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0,
NULL, HFILL }
},
{ &hf_mip_nvse_vendor_nvse_type ,
{ "Vendor Type", "mip.ext.nvse.vendor_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mip_nvse_vendor_nvse_value ,
{ "Vendor Value", "mip.ext.nvse.vendor_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_nvse_3gpp2_type ,
{ "Type", "mip.ext.nvse.3gpp2.type",
FT_UINT16, BASE_DEC, VALS(mip_nvse_3gpp2_type_vals), 0,
NULL, HFILL }
},
{ &hf_mip_nvse_3gpp2_type16_value ,
{ "value", "mip.ext.nvse.3gpp2.type16.value",
FT_UINT16, BASE_DEC, VALS(mip_nvse_3gpp2_type17_vals), 0,
NULL, HFILL }
},
{ &hf_mip_nvse_3gpp2_type17_entity,
{ "Entity-Type", "mip.ext.nvse.3gpp2.type17.entity",
FT_UINT8, BASE_DEC, VALS(mip_nvse_3gpp2_type17_entity_vals), 0,
NULL, HFILL }
},
{ &hf_mip_nvse_3gpp2_type17_subtype1,
{ "Sub-Type1", "mip.ext.nvse.3gpp2.type17.subtype1",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_nvse_3gpp2_type17_length,
{ "Length", "mip.ext.nvse.3gpp2.type17.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_nvse_3gpp2_type17_subtype2,
{ "Sub-Type2", "mip.ext.nvse.3gpp2.type17.subtype2",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_nvse_3gpp2_type17_prim_dns,
{ "Primary DNS", "mip.ext.nvse.3gpp2.type17.prim_dns",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mip_nvse_3gpp2_type17_sec_dns,
{ "Secondary DNS", "mip.ext.nvse.3gpp2.type17.sec_dns",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_mip,
&ett_mip_flags,
&ett_mip_ext,
&ett_mip_exts,
&ett_mip_pmipv4_ext,
};
static ei_register_info ei[] = {
{ &ei_mip_data_not_dissected, { "mip.data_not_dissected", PI_UNDECODED, PI_WARN, "Data not dissected yet", EXPFILL }},
};
expert_module_t* expert_mip;
proto_mip = proto_register_protocol("Mobile IP", "Mobile IP", "mip");
register_dissector("mip", dissect_mip, proto_mip);
proto_register_field_array(proto_mip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mip = expert_register_protocol(proto_mip);
expert_register_field_array(expert_mip, ei, array_length(ei));
mip_nvse_ext_dissector_table = register_dissector_table("mip.nvse_ext",
"MIP Normal Vendor/Organization Specific Extension", FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_mip(void)
{
dissector_handle_t mip_handle;
mip_handle = find_dissector("mip");
ip_handle = find_dissector("ip");
dissector_add_uint("udp.port", UDP_PORT_MIP, mip_handle);
dissector_add_uint("mip.nvse_ext", VENDOR_THE3GPP2,
new_create_dissector_handle(dissect_mip_priv_ext_3gpp2, proto_mip));
}
