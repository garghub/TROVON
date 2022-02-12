static int
parse_teredo_auth(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, e_teredohdr *teredoh)
{
guint idlen, aulen;
col_append_sep_str (pinfo->cinfo, COL_INFO, ", ",
"Authentication header");
teredoh->th_indtyp = 1;
offset += 2;
idlen = tvb_get_guint8(tvb, offset);
teredoh->th_cidlen = idlen;
offset++;
aulen = tvb_get_guint8(tvb, offset);
teredoh->th_authdlen = aulen;
offset++;
if (tree) {
proto_item *ti;
ti = proto_tree_add_item(tree, hf_teredo_auth, tvb, offset-4,
13 + idlen + aulen, ENC_NA);
tree = proto_item_add_subtree(ti, ett_teredo_auth);
proto_tree_add_item(tree, hf_teredo_auth_idlen, tvb,
offset - 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_teredo_auth_aulen, tvb,
offset - 1, 1, ENC_BIG_ENDIAN);
if (idlen) {
proto_tree_add_item(tree, hf_teredo_auth_id, tvb,
offset, idlen, ENC_NA);
offset += idlen;
}
if (aulen) {
proto_tree_add_item(tree, hf_teredo_auth_value, tvb,
offset, aulen, ENC_NA);
offset += aulen;
}
proto_tree_add_item(tree, hf_teredo_auth_nonce, tvb,
offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_teredo_auth_conf, tvb,
offset, 1, ENC_NA);
offset++;
}
else
offset += idlen + aulen + 9;
tvb_memcpy(tvb, teredoh->th_nonce, offset - 9, 8);
teredoh->th_conf = tvb_get_guint8(tvb, offset - 1);
return offset;
}
static int
parse_teredo_orig(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, e_teredohdr *teredoh)
{
proto_item *ti = NULL;
col_append_sep_str (pinfo->cinfo, COL_INFO, ", ",
"Origin indication");
if (tree) {
ti = proto_tree_add_item(tree, hf_teredo_orig, tvb, offset,
8, ENC_NA);
tree = proto_item_add_subtree(ti, ett_teredo_orig);
}
offset += 2;
teredoh->th_orgport = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_teredo_orig_port, tvb,
offset, 2,
(guint16)~teredoh->th_orgport);
}
offset += 2;
teredoh->th_iporgaddr = tvb_get_ipv4(tvb, offset);
if (tree) {
proto_tree_add_ipv4(tree, hf_teredo_orig_addr, tvb,
offset, 4, ~teredoh->th_iporgaddr);
}
offset += 4;
return offset;
}
static void
decode_teredo_ports(tvbuff_t *tvb, int offset, packet_info *pinfo,proto_tree *tree, int th_header)
{
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (dissector_try_uint(teredo_dissector_table, th_header, next_tvb, pinfo, tree))
return;
call_dissector(data_handle,next_tvb, pinfo, tree);
}
static void
dissect_teredo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *teredo_tree;
proto_item *ti;
int offset = 0;
static e_teredohdr teredohstruct[4], *teredoh;
static int teredoh_count = 0;
teredoh_count++;
if(teredoh_count>=4){
teredoh_count=0;
}
teredoh = &teredohstruct[teredoh_count];
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Teredo");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_teredo, tvb, 0, -1, ENC_NA);
teredo_tree = proto_item_add_subtree(ti, ett_teredo);
}
else
teredo_tree = NULL;
teredoh->th_header = tvb_get_ntohs(tvb, offset);
if (teredoh->th_header == 1) {
offset = parse_teredo_auth(tvb, pinfo, teredo_tree,
offset, teredoh);
teredoh->th_header = tvb_get_ntohs(tvb, offset);
}
else
teredoh->th_indtyp = 0;
if ( teredoh->th_header == 0 ) {
offset = parse_teredo_orig(tvb, pinfo, teredo_tree,
offset, teredoh);
}
teredoh->th_ip_v_hl = tvb_get_guint8(tvb, offset);
decode_teredo_ports(tvb, offset, pinfo, tree, teredoh->th_header );
tap_queue_packet(teredo_tap, pinfo, teredoh);
}
static gboolean
dissect_teredo_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint16 val;
int offset = 0;
if (tvb_captured_length_remaining(tvb, offset) < 40)
return FALSE;
val = tvb_get_ntohs(tvb, offset);
if (val == 1)
{
guint8 idlen, aulen;
offset += 2;
idlen = tvb_get_guint8(tvb, offset);
offset++;
aulen = tvb_get_guint8(tvb, offset);
offset += 10;
if (tvb_captured_length_remaining(tvb, offset) < idlen + aulen + 40)
return FALSE;
offset += idlen + aulen;
val = tvb_get_ntohs(tvb, offset);
}
if (val == 0)
{
offset += 8;
if (tvb_captured_length_remaining(tvb, offset) < 40)
return FALSE;
val = tvb_get_ntohs(tvb, offset);
}
if ((val >> 12) == 6)
{
val = tvb_get_ntohs(tvb, offset + 4);
offset += 40;
if (val > 65467)
return FALSE;
if (tvb_reported_length_remaining(tvb, offset) != val)
return FALSE;
dissect_teredo (tvb, pinfo, tree);
return TRUE;
}
return FALSE;
}
void
proto_register_teredo(void)
{
static hf_register_info hf[] = {
{ &hf_teredo_auth,
{ "Teredo Authentication header", "teredo.auth",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_teredo_auth_idlen,
{ "Client identifier length", "teredo.auth.idlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Client identifier length (ID-len)", HFILL }},
{ &hf_teredo_auth_aulen,
{ "Authentication value length", "teredo.auth.aulen",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Authentication value length (AU-len)", HFILL }},
{ &hf_teredo_auth_id,
{ "Client identifier", "teredo.auth.id",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Client identifier (ID)", HFILL }},
{ &hf_teredo_auth_value,
{ "Authentication value", "teredo.auth.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Authentication value (hash)", HFILL }},
{ &hf_teredo_auth_nonce,
{ "Nonce value", "teredo.auth.nonce",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Nonce value prevents spoofing Teredo server.",
HFILL }},
{ &hf_teredo_auth_conf,
{ "Confirmation byte", "teredo.auth.conf",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Confirmation byte is zero upon successful authentication.",
HFILL }},
{ &hf_teredo_orig,
{ "Teredo Origin Indication header", "teredo.orig",
FT_NONE, BASE_NONE, NULL, 0x0,
"Teredo Origin Indication", HFILL }},
{ &hf_teredo_orig_port,
{ "Origin UDP port", "teredo.orig.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_teredo_orig_addr,
{ "Origin IPv4 address", "teredo.orig.addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_teredo, &ett_teredo_auth, &ett_teredo_orig
};
module_t *teredo_module;
proto_teredo = proto_register_protocol(
"Teredo IPv6 over UDP tunneling", "Teredo", "teredo");
proto_register_field_array(proto_teredo, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
teredo_dissector_table = register_dissector_table("teredo","Teredo ", FT_UINT16, BASE_DEC);
teredo_module = prefs_register_protocol(proto_teredo, NULL);
prefs_register_obsolete_preference(teredo_module, "heuristic_teredo");
}
void
proto_reg_handoff_teredo(void)
{
dissector_handle_t teredo_handle;
teredo_handle = create_dissector_handle(dissect_teredo, proto_teredo);
data_handle = find_dissector("ipv6");
teredo_tap = register_tap("teredo");
dissector_add_uint("udp.port", UDP_PORT_TEREDO, teredo_handle);
heur_dissector_add("udp", dissect_teredo_heur, "Teredo over UDP", "teredo_udp", proto_teredo, HEURISTIC_DISABLE);
}
