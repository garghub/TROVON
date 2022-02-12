static void
dissect_eapol(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 eapol_type;
guint8 keydesc_type;
guint16 eapol_len;
guint len;
guint16 eapol_key_len, eapol_data_len;
guint16 keyinfo;
gboolean generated_locally;
proto_tree *ti = NULL;
proto_tree *eapol_tree = NULL;
proto_tree *keyinfo_item = NULL;
proto_tree *keyinfo_tree = NULL;
proto_tree *key_index_tree, *keydes_tree;
tvbuff_t *next_tvb;
guint8 counter;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EAPOL");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_eapol, tvb, 0, -1, ENC_NA);
eapol_tree = proto_item_add_subtree(ti, ett_eapol);
proto_tree_add_item(eapol_tree, hf_eapol_version, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset++;
eapol_type = tvb_get_guint8(tvb, offset);
if (tree)
proto_tree_add_item(eapol_tree, hf_eapol_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(eapol_type, eapol_type_vals, "Unknown Type (0x%02X)"));
offset++;
eapol_len = tvb_get_ntohs(tvb, offset);
len = EAPOL_HDR_LEN + eapol_len;
set_actual_length(tvb, len);
if (tree) {
proto_item_set_len(ti, len);
proto_tree_add_item(eapol_tree, hf_eapol_len, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
switch (eapol_type) {
case EAP_PACKET:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(eap_handle, next_tvb, pinfo, eapol_tree);
break;
case EAPOL_KEY:
if (tree) {
keydesc_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eapol_tree, hf_eapol_keydes_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (keydesc_type == EAPOL_WPA_KEY || keydesc_type == EAPOL_RSN_KEY) {
keyinfo = tvb_get_ntohs(tvb, offset);
if (keyinfo & KEY_INFO_REQUEST_MASK) {
col_set_str(pinfo->cinfo, COL_INFO, "Key (Request)");
if (keyinfo & KEY_INFO_ERROR_MASK)
col_set_str(pinfo->cinfo, COL_INFO, "Key (Request, Error)");
} else if (keyinfo & KEY_INFO_KEY_TYPE_MASK) {
guint16 masked;
masked = keyinfo &
(KEY_INFO_INSTALL_MASK | KEY_INFO_KEY_ACK_MASK |
KEY_INFO_KEY_MIC_MASK | KEY_INFO_SECURE_MASK);
if (keydesc_type == EAPOL_WPA_KEY) {
switch (masked) {
case KEY_INFO_KEY_ACK_MASK:
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 1 of 4)");
break;
case KEY_INFO_KEY_MIC_MASK:
counter = tvb_get_guint8(tvb, offset+11);
if (!counter)
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 2 of 4)");
else
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 4 of 4)");
break;
case (KEY_INFO_INSTALL_MASK | KEY_INFO_KEY_ACK_MASK |
KEY_INFO_KEY_MIC_MASK):
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 3 of 4)");
break;
}
}
if (keydesc_type == EAPOL_RSN_KEY) {
switch (masked) {
case KEY_INFO_KEY_ACK_MASK:
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 1 of 4)");
break;
case KEY_INFO_KEY_MIC_MASK:
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 2 of 4)");
break;
case (KEY_INFO_INSTALL_MASK | KEY_INFO_KEY_ACK_MASK |
KEY_INFO_KEY_MIC_MASK | KEY_INFO_SECURE_MASK):
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 3 of 4)");
break;
case (KEY_INFO_KEY_MIC_MASK | KEY_INFO_SECURE_MASK):
col_set_str(pinfo->cinfo, COL_INFO, "Key (Message 4 of 4)");
break;
}
}
} else {
if (keyinfo & KEY_INFO_KEY_ACK_MASK)
col_set_str(pinfo->cinfo, COL_INFO, "Key (Group Message 1 of 2)");
else
col_set_str(pinfo->cinfo, COL_INFO, "Key (Group Message 2 of 2)");
}
keyinfo_item =
proto_tree_add_item(eapol_tree, hf_eapol_wpa_keydes_keyinfo, tvb,
offset, 2, ENC_BIG_ENDIAN);
keyinfo_tree = proto_item_add_subtree(keyinfo_item, ett_keyinfo);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_keydes_version, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_key_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_key_index, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_install, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_key_ack, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_key_mic, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_secure, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_error, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_request, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(keyinfo_tree, hf_eapol_wpa_keydes_keyinfo_encrypted_key_data, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(eapol_tree, hf_eapol_keydes_key_len, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(eapol_tree, hf_eapol_keydes_replay_counter, tvb,
offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(eapol_tree, hf_eapol_wpa_keydes_nonce, tvb, offset,
32, ENC_NA);
offset += 32;
proto_tree_add_item(eapol_tree, hf_eapol_keydes_key_iv, tvb,
offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(eapol_tree, hf_eapol_wpa_keydes_rsc, tvb, offset,
8, ENC_NA);
offset += 8;
proto_tree_add_item(eapol_tree, hf_eapol_wpa_keydes_id, tvb, offset, 8,
ENC_NA);
offset += 8;
proto_tree_add_item(eapol_tree, hf_eapol_wpa_keydes_mic, tvb, offset,
16, ENC_NA);
offset += 16;
eapol_data_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(eapol_tree, hf_eapol_wpa_keydes_data_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (eapol_data_len != 0) {
ti = proto_tree_add_item(eapol_tree, hf_eapol_wpa_keydes_data,
tvb, offset, eapol_data_len, ENC_NA);
if ((keyinfo & KEY_INFO_ENCRYPTED_KEY_DATA_MASK) ||
!(keyinfo & KEY_INFO_KEY_TYPE_MASK)) {
} else {
keydes_tree = proto_item_add_subtree(ti, ett_eapol_keydes_data);
ieee_80211_add_tagged_parameters(tvb, offset, pinfo, keydes_tree,
eapol_data_len, -1);
}
}
} else {
eapol_key_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(eapol_tree, hf_eapol_keydes_key_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(eapol_tree, hf_eapol_keydes_replay_counter, tvb,
offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(eapol_tree, hf_eapol_keydes_key_iv, tvb,
offset, 16, ENC_NA);
offset += 16;
ti = proto_tree_add_item(eapol_tree, hf_eapol_keydes_key_index, tvb, offset, 1, ENC_BIG_ENDIAN);
key_index_tree = proto_item_add_subtree(ti, ett_eapol_key_index);
proto_tree_add_item(key_index_tree, hf_eapol_keydes_key_index_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(key_index_tree, hf_eapol_keydes_key_index_number,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(eapol_tree, hf_eapol_keydes_key_signature, tvb,
offset, 16, ENC_NA);
offset += 16;
if (eapol_key_len != 0) {
generated_locally = eapol_len <= 44;
if (!generated_locally) {
proto_tree_add_item(eapol_tree, hf_eapol_keydes_key, tvb, offset,
eapol_key_len, ENC_NA);
}
proto_tree_add_boolean(eapol_tree, hf_eapol_keydes_key_generated_locally, tvb, offset,
0, generated_locally);
}
}
}
break;
case EAPOL_ENCAP_ASF_ALERT:
default:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, eapol_tree);
break;
}
}
void
proto_register_eapol(void)
{
static hf_register_info hf[] = {
{ &hf_eapol_version, {
"Version", "eapol.version",
FT_UINT8, BASE_DEC, VALS(eapol_version_vals), 0x0,
NULL, HFILL }},
{ &hf_eapol_type, {
"Type", "eapol.type",
FT_UINT8, BASE_DEC, VALS(eapol_type_vals), 0x0,
NULL, HFILL }},
{ &hf_eapol_len, {
"Length", "eapol.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_keydes_type, {
"Key Descriptor Type", "eapol.keydes.type",
FT_UINT8, BASE_DEC, VALS(eapol_keydes_type_vals), 0x0,
NULL, HFILL }},
{ &hf_eapol_keydes_key_len, {
"Key Length", "eapol.keydes.key_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_keydes_replay_counter, {
"Replay Counter", "eapol.keydes.replay_counter",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_keydes_key_iv, {
"Key IV", "eapol.keydes.key_iv",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_keydes_key_index, {
"Key Index", "eapol.keydes.key_index",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_keydes_key_index_type, {
"Type", "eapol.keydes.key_index.type",
FT_BOOLEAN, 8, TFS(&keytype_tfs), KEYDES_KEY_INDEX_TYPE_MASK ,
NULL, HFILL }},
{ &hf_eapol_keydes_key_index_number, {
"Number", "eapol.keydes.key_index.number",
FT_UINT8, BASE_DEC, NULL, KEYDES_KEY_INDEX_NUMBER_MASK,
NULL, HFILL }},
{ &hf_eapol_keydes_key_signature, {
"Key Signature", "eapol.keydes.key_signature",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_keydes_key, {
"Key", "eapol.keydes.key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_keydes_key_generated_locally, {
"Key Generated Locally", "eapol.keydes.key.generated_locally",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo, {
"Key Information", "eapol.keydes.key_info",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_keydes_version, {
"Key Descriptor Version", "eapol.keydes.key_info.keydes_version",
FT_UINT16, BASE_DEC, VALS(keydes_version_vals), KEY_INFO_KEYDES_VERSION_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_key_type, {
"Key Type", "eapol.keydes.key_info.key_type",
FT_BOOLEAN, 16, TFS(&keyinfo_key_type_tfs), KEY_INFO_KEY_TYPE_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_key_index, {
"Key Index", "eapol.keydes.key_info.key_index",
FT_UINT16, BASE_DEC, NULL, KEY_INFO_KEY_INDEX_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_install, {
"Install", "eapol.keydes.key_info.install",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_INSTALL_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_key_ack, {
"Key ACK", "eapol.keydes.key_info.key_ack",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_KEY_ACK_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_key_mic, {
"Key MIC", "eapol.keydes.key_info.key_mic",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_KEY_MIC_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_secure, {
"Secure", "eapol.keydes.key_info.secure",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_SECURE_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_error, {
"Error", "eapol.keydes.key_info.error",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_ERROR_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_request, {
"Request", "eapol.keydes.key_info.request",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_REQUEST_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_keyinfo_encrypted_key_data, {
"Encrypted Key Data", "eapol.keydes.key_info.encrypted_key_data",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), KEY_INFO_ENCRYPTED_KEY_DATA_MASK,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_nonce, {
"WPA Key Nonce", "eapol.keydes.nonce",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_rsc, {
"WPA Key RSC", "eapol.keydes.rsc",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_id, {
"WPA Key ID", "eapol.keydes.id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_mic, {
"WPA Key MIC", "eapol.keydes.mic",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_data_len, {
"WPA Key Data Length", "eapol.keydes.data_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eapol_wpa_keydes_data, {
"WPA Key Data", "eapol.keydes.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_eapol,
&ett_eapol_keydes_data,
&ett_keyinfo,
&ett_eapol_key_index
};
proto_eapol = proto_register_protocol("802.1X Authentication", "EAPOL", "eapol");
eapol_handle = register_dissector("eapol", dissect_eapol, proto_eapol);
proto_register_field_array(proto_eapol, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_eapol(void)
{
eap_handle = find_dissector("eap");
data_handle = find_dissector("data");
dissector_add_uint("ethertype", ETHERTYPE_EAPOL, eapol_handle);
dissector_add_uint("ethertype", ETHERTYPE_RSN_PREAUTH, eapol_handle);
}
