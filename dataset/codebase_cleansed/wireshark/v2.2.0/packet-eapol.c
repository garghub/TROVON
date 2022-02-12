static int
dissect_eapol(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
guint8 eapol_type;
guint16 eapol_len;
guint8 keydesc_type;
guint len;
proto_tree *ti;
proto_tree *eapol_tree;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EAPOL");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_eapol, tvb, 0, -1, ENC_NA);
eapol_tree = proto_item_add_subtree(ti, ett_eapol);
proto_tree_add_item(eapol_tree, hf_eapol_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
eapol_type = tvb_get_guint8(tvb, offset);
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
keydesc_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eapol_tree, hf_eapol_keydes_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_uint_new(eapol_keydes_type_dissector_table,
keydesc_type, next_tvb, pinfo, eapol_tree,
FALSE, NULL))
proto_tree_add_item(eapol_tree, hf_eapol_keydes_body, tvb, offset, -1, ENC_NA);
break;
case EAPOL_MKA:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(mka_handle, next_tvb, pinfo, eapol_tree);
break;
case EAPOL_ENCAP_ASF_ALERT:
default:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, eapol_tree);
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_eapol_rc4_key(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
guint16 eapol_key_len;
gboolean generated_locally;
proto_tree *ti;
proto_tree *key_index_tree;
gint eapol_len;
eapol_key_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_eapol_keydes_key_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_eapol_keydes_replay_counter, tvb,
offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_eapol_keydes_key_iv, tvb,
offset, 16, ENC_NA);
offset += 16;
ti = proto_tree_add_item(tree, hf_eapol_keydes_key_index, tvb, offset, 1, ENC_BIG_ENDIAN);
key_index_tree = proto_item_add_subtree(ti, ett_eapol_key_index);
proto_tree_add_item(key_index_tree, hf_eapol_keydes_key_index_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(key_index_tree, hf_eapol_keydes_key_index_number,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_eapol_keydes_key_signature, tvb,
offset, 16, ENC_NA);
offset += 16;
if (eapol_key_len != 0) {
eapol_len = 1 + tvb_reported_length(tvb);
generated_locally = eapol_len <= 44;
if (!generated_locally) {
proto_tree_add_item(tree, hf_eapol_keydes_key, tvb, offset,
eapol_key_len, ENC_NA);
}
proto_tree_add_boolean(tree, hf_eapol_keydes_key_generated_locally, tvb, offset,
0, generated_locally);
}
return tvb_captured_length(tvb);
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
{ &hf_eapol_keydes_body, {
"Key Descriptor Body", "eapol.keydes.body",
FT_BYTES, BASE_NONE, NULL, 0x0,
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
};
static gint *ett[] = {
&ett_eapol,
&ett_keyinfo,
&ett_eapol_key_index
};
proto_eapol = proto_register_protocol("802.1X Authentication", "EAPOL", "eapol");
eapol_handle = register_dissector("eapol", dissect_eapol, proto_eapol);
proto_register_field_array(proto_eapol, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
eapol_keydes_type_dissector_table = register_dissector_table("eapol.keydes.type",
"EAPOL Key Descriptor Type",
proto_eapol, FT_UINT8,
BASE_DEC);
}
void
proto_reg_handoff_eapol(void)
{
dissector_handle_t eapol_rc4_key_handle;
eap_handle = find_dissector_add_dependency("eap", proto_eapol);
mka_handle = find_dissector_add_dependency("mka", proto_eapol);
dissector_add_uint("ethertype", ETHERTYPE_EAPOL, eapol_handle);
dissector_add_uint("ethertype", ETHERTYPE_RSN_PREAUTH, eapol_handle);
eapol_rc4_key_handle = create_dissector_handle(dissect_eapol_rc4_key,
proto_eapol);
dissector_add_uint("eapol.keydes.type", EAPOL_RC4_KEY, eapol_rc4_key_handle);
}
