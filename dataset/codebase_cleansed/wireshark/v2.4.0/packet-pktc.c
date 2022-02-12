static int
dissect_pktc_app_specific_data(packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint8 doi, guint8 kmmid)
{
int old_offset=offset;
proto_tree *tree;
proto_tree *engineid_tree = NULL;
proto_item *item;
proto_item *engineid_item = NULL;
guint8 len;
item = proto_tree_add_item(parent_tree, hf_pktc_app_spec_data, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_pktc_app_spec_data);
switch(doi){
case DOI_SNMPv3:
switch(kmmid){
case KMMID_AP_REQUEST:
case KMMID_AP_REPLY:
len=tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_pktc_snmpEngineID_len, tvb, offset, 1, len);
offset+=1;
engineid_item = proto_tree_add_item(tree, hf_pktc_snmpEngineID, tvb, offset, len, ENC_NA);
engineid_tree = proto_item_add_subtree(engineid_item, ett_pktc_engineid);
dissect_snmp_engineid(engineid_tree, pinfo, tvb, offset, len);
offset+=len;
proto_tree_add_item(tree, hf_pktc_snmpEngineBoots, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_pktc_snmpEngineTime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
len=tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_pktc_usmUserName_len, tvb, offset, 1, len);
offset+=1;
proto_tree_add_item(tree, hf_pktc_usmUserName, tvb, offset, len, ENC_ASCII|ENC_NA);
offset+=len;
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_pktc_unknown_kmmid, tvb, offset, 1);
};
break;
case DOI_IPSEC:
switch(kmmid){
case KMMID_AP_REQUEST:
case KMMID_AP_REPLY:
case KMMID_REKEY:
proto_tree_add_item(tree, hf_pktc_ipsec_spi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_pktc_unknown_kmmid, tvb, offset, 1);
};
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_pktc_unknown_doi, tvb, offset, 1);
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_pktc_list_of_ciphersuites(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint8 doi)
{
int old_offset=offset;
proto_tree *tree;
proto_item *item, *hidden_item;
guint8 len, i;
item = proto_tree_add_item(parent_tree, hf_pktc_list_of_ciphersuites, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_pktc_list_of_ciphersuites);
len=tvb_get_guint8(tvb, offset);
if (len>0) {
proto_item_append_text(tree, " (%d):", len);
}
hidden_item = proto_tree_add_uint(tree, hf_pktc_list_of_ciphersuites_len, tvb, offset, 1, len);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset+=1;
switch(doi){
case DOI_SNMPv3:
for(i=0;i<len;i++){
proto_tree_add_item(tree, hf_pktc_snmpAuthenticationAlgorithm, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tree, " %s", val_to_str(tvb_get_guint8(tvb, offset), snmp_authentication_algorithm_vals, "%0x"));
offset+=1;
proto_tree_add_item(tree, hf_pktc_snmpEncryptionTransformID, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tree, "/%s", val_to_str(tvb_get_guint8(tvb, offset), snmp_transform_id_vals, "%0x"));
offset+=1;
}
break;
case DOI_IPSEC:
for(i=0;i<len;i++){
proto_tree_add_item(tree, hf_pktc_ipsecAuthenticationAlgorithm, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tree, " %s", val_to_str(tvb_get_guint8(tvb, offset), ipsec_authentication_algorithm_vals, "%0x"));
offset+=1;
proto_tree_add_item(tree, hf_pktc_ipsecEncryptionTransformID, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tree, "/%s", val_to_str(tvb_get_guint8(tvb, offset), ipsec_transform_id_vals, "%0x"));
offset+=1;
}
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_pktc_unknown_doi, tvb, offset, 1);
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_pktc_wakeup(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint32 snonce;
guint string_len;
snonce=tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_pktc_server_nonce, tvb, offset, 4, snonce);
offset+=4;
string_len=tvb_strsize(tvb, offset);
proto_tree_add_item(tree, hf_pktc_server_principal, tvb, offset, string_len, ENC_ASCII|ENC_NA);
offset+=string_len;
return offset;
}
static int
dissect_pktc_ap_request(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint8 doi)
{
tvbuff_t *pktc_tvb;
guint32 snonce;
pktc_tvb = tvb_new_subset_remaining(tvb, offset);
offset += dissect_kerberos_main(pktc_tvb, pinfo, tree, FALSE, NULL);
snonce=tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_pktc_server_nonce, tvb, offset, 4, snonce);
offset+=4;
offset=dissect_pktc_app_specific_data(pinfo, tree, tvb, offset, doi, KMMID_AP_REQUEST);
offset=dissect_pktc_list_of_ciphersuites(pinfo, tree, tvb, offset, doi);
proto_tree_add_item(tree, hf_pktc_reestablish_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_pktc_sha1_hmac, tvb, offset, 20, ENC_NA);
offset+=20;
return offset;
}
static int
dissect_pktc_ap_reply(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint8 doi)
{
tvbuff_t *pktc_tvb;
pktc_tvb = tvb_new_subset_remaining(tvb, offset);
offset += dissect_kerberos_main(pktc_tvb, pinfo, tree, FALSE, NULL);
offset=dissect_pktc_app_specific_data(pinfo, tree, tvb, offset, doi, KMMID_AP_REPLY);
offset=dissect_pktc_list_of_ciphersuites(pinfo, tree, tvb, offset, doi);
proto_tree_add_uint_format(tree, hf_pktc_sec_param_lifetime, tvb, offset, 4,
tvb_get_ntohl(tvb, offset), "%s: %s",
proto_registrar_get_name(hf_pktc_sec_param_lifetime),
signed_time_secs_to_str(wmem_packet_scope(), tvb_get_ntohl(tvb, offset)));
offset+=4;
proto_tree_add_item(tree, hf_pktc_grace_period, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_pktc_reestablish_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_pktc_ack_required_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_pktc_sha1_hmac, tvb, offset, 20, ENC_NA);
offset+=20;
return offset;
}
static int
dissect_pktc_sec_param_rec(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_pktc_sha1_hmac, tvb, offset, 20, ENC_NA);
offset+=20;
return offset;
}
static int
dissect_pktc_rekey(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint8 doi)
{
guint32 snonce;
guint string_len;
const guint8 *timestr;
snonce=tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_pktc_server_nonce, tvb, offset, 4, snonce);
offset+=4;
string_len=tvb_strsize(tvb, offset);
proto_tree_add_item(tree, hf_pktc_server_principal, tvb, offset, string_len, ENC_ASCII|ENC_NA);
offset+=string_len;
timestr=tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 13, ENC_ASCII);
proto_tree_add_string_format_value(tree, hf_pktc_timestamp, tvb, offset, 13, timestr,
"%.2s-%.2s-%.2s %.2s:%.2s:%.2s",
timestr, timestr+2, timestr+4, timestr+6, timestr+8, timestr+10);
offset+=13;
offset=dissect_pktc_app_specific_data(pinfo, tree, tvb, offset, doi, KMMID_REKEY);
offset=dissect_pktc_list_of_ciphersuites(pinfo, tree, tvb, offset, doi);
proto_tree_add_item(tree, hf_pktc_sec_param_lifetime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_pktc_grace_period, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_pktc_reestablish_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_pktc_sha1_hmac, tvb, offset, 20, ENC_NA);
offset+=20;
return offset;
}
static int
dissect_pktc_error_reply(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset)
{
tvbuff_t *pktc_tvb;
pktc_tvb = tvb_new_subset_remaining(tvb, offset);
offset += dissect_kerberos_main(pktc_tvb, pinfo, tree, FALSE, NULL);
return offset;
}
static int
dissect_pktc_mtafqdn_krbsafeuserdata(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tree)
{
int offset=0, string_len=0;
guint8 msgtype;
guint32 bignum;
nstime_t ts;
msgtype = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_pktc_mtafqdn_msgtype, tvb, offset, 1, msgtype);
offset+=1;
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(msgtype, pktc_mtafqdn_msgtype_vals, "MsgType %u"));
proto_tree_add_item(tree, hf_pktc_mtafqdn_enterprise, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_pktc_mtafqdn_version, tvb, offset, 1, ENC_NA);
offset+=1;
switch(msgtype) {
case PKTC_MTAFQDN_REQ:
proto_tree_add_item(tree, hf_pktc_mtafqdn_mac, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(tree, hf_pktc_mtafqdn_pub_key_hash, tvb, offset, 20, ENC_NA);
offset+=20;
bignum = tvb_get_ntohl(tvb, offset);
ts.secs = bignum;
if (bignum==0) {
proto_tree_add_time_format_value(tree, hf_pktc_mtafqdn_manu_cert_revoked, tvb, offset, 4,
&ts, "not revoked");
} else {
proto_tree_add_time(tree, hf_pktc_mtafqdn_manu_cert_revoked, tvb, offset, 4, &ts);
}
break;
case PKTC_MTAFQDN_REP:
string_len = tvb_reported_length_remaining(tvb, offset) - 4;
proto_tree_add_item(tree, hf_pktc_mtafqdn_fqdn, tvb, offset, string_len, ENC_ASCII|ENC_NA);
offset+=string_len;
tvb_memcpy(tvb, (guint8 *)&bignum, offset, sizeof(bignum));
proto_tree_add_ipv4(tree, hf_pktc_mtafqdn_ip, tvb, offset, 4, bignum);
break;
}
return offset;
}
static int
dissect_pktc_mtafqdn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset=0;
proto_tree *pktc_mtafqdn_tree;
proto_item *item;
tvbuff_t *pktc_mtafqdn_tvb;
gint8 ber_class;
gboolean pc;
gint32 tag;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PKTC");
item = proto_tree_add_item(tree, proto_pktc, tvb, 0, 0, ENC_NA);
pktc_mtafqdn_tree = proto_item_add_subtree(item, ett_pktc_mtafqdn);
col_add_fstr(pinfo->cinfo, COL_INFO, "MTA FQDN %s",
pinfo->srcport == pinfo->match_uint ? "Reply":"Request");
pktc_mtafqdn_tvb = tvb_new_subset_remaining(tvb, offset);
get_ber_identifier(pktc_mtafqdn_tvb, 0, &ber_class, &pc, &tag);
if ((tag == KERBEROS_APPLICATIONS_AP_REQ) || (tag == KERBEROS_APPLICATIONS_AP_REP)) {
offset += dissect_kerberos_main(pktc_mtafqdn_tvb, pinfo, pktc_mtafqdn_tree, FALSE, NULL);
} else {
expert_add_info_format(pinfo, item, &ei_pktc_unknown_kerberos_application, "Unknown Kerberos application (%d), expected 10 or 11", tag);
return tvb_captured_length(tvb);
}
pktc_mtafqdn_tvb = tvb_new_subset_remaining(tvb, offset);
get_ber_identifier(pktc_mtafqdn_tvb, 0, &ber_class, &pc, &tag);
if (tag == KERBEROS_APPLICATIONS_KRB_SAFE) {
offset += dissect_kerberos_main(pktc_mtafqdn_tvb, pinfo, pktc_mtafqdn_tree, FALSE, cb);
} else {
expert_add_info_format(pinfo, item, &ei_pktc_unknown_kerberos_application, "Unknown Kerberos application (%d), expected 20", tag);
}
proto_item_set_len(item, offset);
return tvb_captured_length(tvb);
}
static int
dissect_pktc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 kmmid, doi, version;
int offset=0;
proto_tree *pktc_tree, *version_tree;
proto_item *item;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PKTC");
item = proto_tree_add_item(tree, proto_pktc, tvb, 0, 3, ENC_NA);
pktc_tree = proto_item_add_subtree(item, ett_pktc);
kmmid=tvb_get_guint8(tvb, offset);
proto_tree_add_uint(pktc_tree, hf_pktc_kmmid, tvb, offset, 1, kmmid);
offset+=1;
doi=tvb_get_guint8(tvb, offset);
proto_tree_add_uint(pktc_tree, hf_pktc_doi, tvb, offset, 1, doi);
offset+=1;
version=tvb_get_guint8(tvb, offset);
version_tree = proto_tree_add_subtree_format(pktc_tree, tvb, offset, 1, ett_pktc_version, NULL,
"Version: %d.%d", (version>>4)&0x0f, (version)&0x0f);
proto_tree_add_item(version_tree, hf_pktc_version_major, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(version_tree, hf_pktc_version_minor, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(kmmid, kmmid_types, "Unknown KMMID %#x"));
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str(doi, doi_types, "Unknown DOI %#x"));
switch(kmmid){
case KMMID_WAKEUP:
offset=dissect_pktc_wakeup(pktc_tree, tvb, offset);
break;
case KMMID_AP_REQUEST:
offset=dissect_pktc_ap_request(pinfo, pktc_tree, tvb, offset, doi);
break;
case KMMID_AP_REPLY:
offset=dissect_pktc_ap_reply(pinfo, pktc_tree, tvb, offset, doi);
break;
case KMMID_SEC_PARAM_REC:
offset=dissect_pktc_sec_param_rec(pktc_tree, tvb, offset);
break;
case KMMID_REKEY:
offset=dissect_pktc_rekey(pinfo, pktc_tree, tvb, offset, doi);
break;
case KMMID_ERROR_REPLY:
offset=dissect_pktc_error_reply(pinfo, pktc_tree, tvb, offset);
break;
};
proto_item_set_len(item, offset);
return tvb_captured_length(tvb);
}
void
proto_register_pktc(void)
{
static hf_register_info hf[] = {
{ &hf_pktc_kmmid, {
"Key Management Message ID", "pktc.kmmid", FT_UINT8, BASE_HEX,
VALS(kmmid_types), 0, NULL, HFILL }},
{ &hf_pktc_doi, {
"Domain of Interpretation", "pktc.doi", FT_UINT8, BASE_DEC,
VALS(doi_types), 0, NULL, HFILL }},
{ &hf_pktc_version_major, {
"Major version", "pktc.version.major", FT_UINT8, BASE_DEC,
NULL, 0xF0, "Major version of PKTC", HFILL }},
{ &hf_pktc_version_minor, {
"Minor version", "pktc.version.minor", FT_UINT8, BASE_DEC,
NULL, 0x0F, "Minor version of PKTC", HFILL }},
{ &hf_pktc_server_nonce, {
"Server Nonce", "pktc.server_nonce", FT_UINT32, BASE_HEX,
NULL, 0, "Server Nonce random number", HFILL }},
{ &hf_pktc_server_principal, {
"Server Kerberos Principal Identifier", "pktc.server_principal", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_timestamp, {
"Timestamp", "pktc.timestamp", FT_STRING, STR_UNICODE,
NULL, 0, "Timestamp (UTC)", HFILL }},
{ &hf_pktc_app_spec_data, {
"Application Specific Data", "pktc.asd", FT_NONE, BASE_NONE,
NULL, 0, "KMMID/DOI application specific data", HFILL }},
{ &hf_pktc_list_of_ciphersuites, {
"List of Ciphersuites", "pktc.ciphers", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_list_of_ciphersuites_len, {
"Number of Ciphersuites", "pktc.ciphers.len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_snmpAuthenticationAlgorithm, {
"SNMPv3 Authentication Algorithm", "pktc.asd.snmp_auth_alg", FT_UINT8, BASE_HEX,
VALS(snmp_authentication_algorithm_vals), 0, NULL, HFILL }},
{ &hf_pktc_snmpEncryptionTransformID, {
"SNMPv3 Encryption Transform ID", "pktc.asd.snmp_enc_alg", FT_UINT8, BASE_HEX,
VALS(snmp_transform_id_vals), 0, NULL, HFILL }},
{ &hf_pktc_ipsecAuthenticationAlgorithm, {
"IPsec Authentication Algorithm", "pktc.asd.ipsec_auth_alg", FT_UINT8, BASE_HEX,
VALS(ipsec_authentication_algorithm_vals), 0, NULL, HFILL }},
{ &hf_pktc_ipsecEncryptionTransformID, {
"IPsec Encryption Transform ID", "pktc.asd.ipsec_enc_alg", FT_UINT8, BASE_HEX,
VALS(ipsec_transform_id_vals), 0, NULL, HFILL }},
{ &hf_pktc_snmpEngineID_len, {
"SNMPv3 Engine ID Length", "pktc.asd.snmp_engine_id.len", FT_UINT8, BASE_DEC,
NULL, 0, "Length of SNMPv3 Engine ID", HFILL }},
{ &hf_pktc_snmpEngineID, {
"SNMPv3 Engine ID", "pktc.asd.snmp_engine_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_snmpEngineBoots, {
"SNMPv3 Engine Boots", "pktc.asd.snmp_engine_boots", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_snmpEngineTime, {
"SNMPv3 Engine Time", "pktc.asd.snmp_engine_time", FT_UINT32, BASE_DEC,
NULL, 0, "SNMPv3 Engine ID Time", HFILL }},
{ &hf_pktc_usmUserName_len, {
"SNMPv3 USM User Name Length", "pktc.asd.snmp_usm_username.len", FT_UINT8, BASE_DEC,
NULL, 0, "Length of SNMPv3 USM User Name", HFILL }},
{ &hf_pktc_usmUserName, {
"SNMPv3 USM User Name", "pktc.asd.snmp_usm_username", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_ipsec_spi, {
"IPsec Security Parameter Index", "pktc.asd.ipsec_spi", FT_UINT32, BASE_HEX,
NULL, 0, "Security Parameter Index for inbound Security Association (IPsec)", HFILL }},
{ &hf_pktc_reestablish_flag, {
"Re-establish Flag", "pktc.reestablish", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_pktc_ack_required_flag, {
"ACK Required Flag", "pktc.ack_required", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_pktc_sec_param_lifetime, {
"Security Parameter Lifetime", "pktc.spl", FT_UINT32, BASE_DEC,
NULL, 0, "Lifetime in seconds of security parameter", HFILL }},
{ &hf_pktc_sha1_hmac, {
"SHA-1 HMAC", "pktc.sha1_hmac", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_grace_period, {
"Grace Period", "pktc.grace_period", FT_UINT32, BASE_DEC,
NULL, 0, "Grace Period in seconds", HFILL }},
};
static gint *ett[] = {
&ett_pktc,
&ett_pktc_app_spec_data,
&ett_pktc_list_of_ciphersuites,
&ett_pktc_engineid,
&ett_pktc_version,
};
proto_pktc = proto_register_protocol("PacketCable", "PKTC", "pktc");
proto_register_field_array(proto_pktc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pktc(void)
{
dissector_handle_t pktc_handle;
pktc_handle = create_dissector_handle(dissect_pktc, proto_pktc);
dissector_add_uint_with_preference("udp.port", PKTC_PORT, pktc_handle);
}
void
proto_register_pktc_mtafqdn(void)
{
static hf_register_info hf[] = {
{ &hf_pktc_mtafqdn_msgtype, {
"Message Type", "pktc.mtafqdn.msgtype", FT_UINT8, BASE_DEC,
VALS(pktc_mtafqdn_msgtype_vals), 0, "MTA FQDN Message Type", HFILL }},
{ &hf_pktc_mtafqdn_enterprise, {
"Enterprise Number", "pktc.mtafqdn.enterprise", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_mtafqdn_version, {
"Protocol Version", "pktc.mtafqdn.version", FT_UINT8, BASE_DEC,
NULL, 0, "MTA FQDN Protocol Version", HFILL }},
{ &hf_pktc_mtafqdn_mac, {
"MTA MAC address", "pktc.mtafqdn.mac", FT_ETHER, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_mtafqdn_pub_key_hash, {
"MTA Public Key Hash", "pktc.mtafqdn.pub_key_hash", FT_BYTES, BASE_NONE,
NULL, 0, "MTA Public Key Hash (SHA-1)", HFILL }},
{ &hf_pktc_mtafqdn_manu_cert_revoked, {
"Manufacturer Cert Revocation Time", "pktc.mtafqdn.manu_cert_revoked", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Manufacturer Cert Revocation Time (UTC) or 0 if not revoked", HFILL }},
{ &hf_pktc_mtafqdn_fqdn, {
"MTA FQDN", "pktc.mtafqdn.fqdn", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pktc_mtafqdn_ip, {
"MTA IP Address", "pktc.mtafqdn.ip", FT_IPv4, BASE_NONE,
NULL, 0, "MTA IP Address (all zeros if not supplied)", HFILL }},
};
static gint *ett[] = {
&ett_pktc_mtafqdn,
};
static ei_register_info ei[] = {
{ &ei_pktc_unknown_kmmid, { "pktc.mtafqdn.unknown_kmmid", PI_PROTOCOL, PI_WARN, "Unknown KMMID", EXPFILL }},
{ &ei_pktc_unknown_doi, { "pktc.mtafqdn.unknown_doi", PI_PROTOCOL, PI_WARN, "Unknown DOI", EXPFILL }},
{ &ei_pktc_unknown_kerberos_application, { "pktc.mtafqdn.unknown_kerberos_application", PI_PROTOCOL, PI_WARN, "Unknown Kerberos application", EXPFILL }},
};
expert_module_t* expert_pktc;
proto_pktc_mtafqdn = proto_register_protocol("PacketCable MTA FQDN", "PKTC MTA FQDN", "pktc.mtafqdn");
proto_register_field_array(proto_pktc_mtafqdn, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pktc = expert_register_protocol(proto_pktc_mtafqdn);
expert_register_field_array(expert_pktc, ei, array_length(ei));
}
void
proto_reg_handoff_pktc_mtafqdn(void)
{
dissector_handle_t pktc_mtafqdn_handle;
pktc_mtafqdn_handle = create_dissector_handle(dissect_pktc_mtafqdn, proto_pktc_mtafqdn);
dissector_add_uint_with_preference("udp.port", PKTC_MTAFQDN_PORT, pktc_mtafqdn_handle);
}
