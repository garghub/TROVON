static gint dissect_etf_dist_header(packet_info *pinfo _U_, tvbuff_t *tvb, gint offset, proto_tree *tree) {
guint8 num, flen, i, flg, isi;
gint flg_offset, acrs_offset, acr_offset;
guint32 atom_txt_len;
gboolean new_entry, long_atom;
proto_item *ti_acrs, *ti_acr, *ti_tmp;
proto_tree *flags_tree, *acrs_tree, *acr_tree;
const gchar *str;
num = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_erldp_num_atom_cache_refs, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
if (num == 0)
return offset;
flg_offset = offset;
flen = num / 2 + 1;
ti_tmp = proto_tree_add_item(tree, hf_erldp_etf_flags, tvb, offset, flen, ENC_NA );
flags_tree = proto_item_add_subtree(ti_tmp, ett_etf_flags);
for (i=0; i<num; i++) {
flg = tvb_get_guint8(tvb, offset + i / 2);
proto_tree_add_boolean_format_value(flags_tree, hf_etf_dist_header_new_cache, tvb, offset + i / 2, 1,
(flg & (0x08 << 4*(i%2))), "NewCacheEntryFlag[%2d]: %s",
i, (flg & (0x08 << 4*(i%2))) ? "SET" : "---");
proto_tree_add_uint_format(flags_tree, hf_etf_dist_header_segment_index, tvb, offset + i / 2, 1,
(flg & (0x07 << 4*(i%2))), "SegmentIndex [%2d]: %u",
i, (flg & (0x07 << 4*(i%2))));
}
flg = tvb_get_guint8(tvb, offset + num / 2);
proto_tree_add_boolean(flags_tree, hf_etf_dist_header_long_atoms, tvb, offset + num / 2, 1, (flg & (0x01 << 4*(num%2))));
long_atom = flg & (0x01 << 4*(num%2));
offset += flen;
acrs_offset = offset;
acrs_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_etf_acrs, &ti_acrs, "AtomCacheRefs");
for (i=0; i<num; i++) {
flg = tvb_get_guint8(tvb, flg_offset + i / 2);
new_entry = flg & (0x08 << 4*(i%2));
acr_offset = offset;
acr_tree = proto_tree_add_subtree_format(acrs_tree, tvb, offset, 0, ett_etf_acr, &ti_acr, "AtomCacheRef[%2d]:", i);
isi = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(acr_tree, hf_erldp_internal_segment_index, tvb, offset, 1, isi);
proto_item_append_text(ti_acr, " %3d", isi);
offset++;
if (!new_entry)
continue;
if (long_atom) {
atom_txt_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(acr_tree, hf_erldp_atom_length2, tvb, offset, 2, atom_txt_len);
offset += 2;
}
else {
atom_txt_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(acr_tree, hf_erldp_atom_length, tvb, offset, 1, atom_txt_len);
offset++;
}
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, atom_txt_len, ENC_ASCII);
proto_tree_add_item(acr_tree, hf_erldp_atom_text, tvb, offset, atom_txt_len, ENC_NA|ENC_ASCII);
proto_item_append_text(ti_acr, " - '%s'", str);
offset += atom_txt_len;
proto_item_set_len(ti_acr, offset - acr_offset);
}
proto_item_set_len(ti_acrs, offset - acrs_offset);
return offset;
}
static gint dissect_etf_tuple_content(gboolean large, packet_info *pinfo, tvbuff_t *tvb, gint offset, proto_tree *tree, gchar **value_str _U_) {
guint32 arity, i;
if (large) {
arity = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_etf_arity4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
arity = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_etf_arity, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
for (i=0; i<arity; i++) {
offset = dissect_etf_type(NULL, pinfo, tvb, offset, tree);
}
return offset;
}
static gint dissect_etf_type_content(guint8 tag, packet_info *pinfo, tvbuff_t *tvb, gint offset, proto_tree *tree, gchar **value_str) {
gint32 len, int_val, i;
guint32 id;
switch (tag) {
case DIST_HEADER:
offset = dissect_etf_dist_header(pinfo, tvb, offset, tree);
break;
case ATOM_CACHE_REF:
int_val = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_erldp_atom_cache_ref, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (value_str)
*value_str = wmem_strdup_printf(wmem_packet_scope(), "%d", int_val);
break;
case SMALL_INTEGER_EXT:
int_val = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_erldp_small_int_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (value_str)
*value_str = wmem_strdup_printf(wmem_packet_scope(), "%d", int_val);
break;
case INTEGER_EXT:
int_val = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_erldp_int_ext, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (value_str)
*value_str = wmem_strdup_printf(wmem_packet_scope(), "%d", int_val);
break;
case PID_EXT:
offset = dissect_etf_type("Node", pinfo, tvb, offset, tree);
proto_tree_add_item(tree, hf_erldp_pid_ext_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_erldp_pid_ext_serial, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_erldp_pid_ext_creation, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case SMALL_TUPLE_EXT:
offset = dissect_etf_tuple_content(FALSE, pinfo, tvb, offset, tree, value_str);
break;
case LARGE_TUPLE_EXT:
offset = dissect_etf_tuple_content(TRUE, pinfo, tvb, offset, tree, value_str);
break;
case NIL_EXT:
break;
case LIST_EXT:
len = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_erldp_list_ext_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i=0; i<len; i++) {
offset = dissect_etf_type(NULL, pinfo, tvb, offset, tree);
}
offset = dissect_etf_type("Tail", pinfo, tvb, offset, tree);
break;
case NEW_REFERENCE_EXT:
len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_erldp_new_ref_ext_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_etf_type("Node", pinfo, tvb, offset, tree);
proto_tree_add_item(tree, hf_erldp_new_ref_ext_creation, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i=0; i<len; i++) {
id = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_erldp_new_ref_ext_id, tvb, offset, 4,
id, "ID[%d]: 0x%08X", i, id);
offset += 4;
}
break;
}
return offset;
}
static gint dissect_etf_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, const gchar *label) {
gint offset = 0;
guint8 mag, tag;
proto_item *ti;
proto_tree *etf_tree;
mag = tvb_get_guint8(tvb, offset);
if (mag != VERSION_MAGIC) {
return 0;
}
etf_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_etf, &ti, (label) ? label : "External Term Format");
proto_tree_add_item(etf_tree, hf_etf_version_magic, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tag = tvb_get_guint8(tvb, offset);
proto_tree_add_item(etf_tree, hf_etf_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (!label)
proto_item_set_text(ti, "%s", val_to_str(tag, VALS(etf_tag_vals), "unknown tag (%d)"));
offset = dissect_etf_type_content(tag, pinfo, tvb, offset, etf_tree, NULL);
proto_item_set_len(ti, offset);
return offset;
}
static gint dissect_etf_type(const gchar *label, packet_info *pinfo, tvbuff_t *tvb, gint offset, proto_tree *tree) {
gint begin = offset;
guint8 tag;
proto_item *ti;
proto_tree *etf_tree;
gchar *value_str = NULL;
etf_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_etf, &ti, (label) ? label : "External Term Format");
tag = tvb_get_guint8(tvb, offset);
proto_tree_add_item(etf_tree, hf_etf_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (!label)
proto_item_set_text(ti, "%s", val_to_str(tag, VALS(etf_tag_vals), "unknown tag (%d)"));
offset = dissect_etf_type_content(tag, pinfo, tvb, offset, etf_tree, &value_str);
if (value_str)
proto_item_append_text(ti, ": %s", value_str);
proto_item_set_len(ti, offset - begin);
return offset;
}
static gboolean is_handshake(tvbuff_t *tvb, int offset) {
guint32 len = tvb_get_ntohs(tvb, offset);
guint8 tag = tvb_get_guint8(tvb, offset + 2);
return ((len > 0) && strchr("nras", tag) && (len == (guint32)tvb_captured_length_remaining(tvb, offset + 2)));
}
static void dissect_erldp_handshake(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
gint offset = 0;
guint8 tag;
gint i;
gboolean is_challenge = FALSE;
guint32 str_len;
const gchar *str;
proto_tree_add_item(tree, hf_erldp_length_2, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tag = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_erldp_tag, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset++;
switch (tag) {
case 'n' :
proto_tree_add_item(tree, hf_erldp_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_erldp_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (tvb_bytes_exist(tvb, offset, 4)) {
for (i=0; i<4; i++)
if(!g_ascii_isprint(tvb_get_guint8(tvb, offset + i))) {
is_challenge = TRUE;
break;
}
}
if (is_challenge) {
proto_tree_add_item(tree, hf_erldp_challenge, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
str_len = tvb_captured_length_remaining(tvb, offset);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, str_len, ENC_ASCII);
proto_tree_add_item(tree, hf_erldp_name, tvb, offset, str_len, ENC_ASCII|ENC_NA);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s", (is_challenge) ? "SEND_CHALLENGE" : "SEND_NAME", str);
break;
case 'r' :
proto_tree_add_item(tree, hf_erldp_challenge, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_erldp_digest, tvb, offset, 16, ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "SEND_CHALLENGE_REPLY");
break;
case 'a' :
proto_tree_add_item(tree, hf_erldp_digest, tvb, offset, 16, ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "SEND_CHALLENGE_ACK");
break;
case 's' :
str_len = tvb_captured_length_remaining(tvb, offset);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, str_len, ENC_ASCII);
proto_tree_add_item(tree, hf_erldp_status, tvb, offset, str_len, ENC_ASCII|ENC_NA);
col_add_fstr(pinfo->cinfo, COL_INFO, "SEND_STATUS %s", str);
break;
}
}
static int dissect_erldp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
gint offset;
guint32 msg_len;
guint8 type, ctl_op;
proto_tree *erldp_tree;
proto_item *ti;
tvbuff_t *next_tvb = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
ti = proto_tree_add_item(tree, proto_erldp, tvb, 0, -1, ENC_NA);
erldp_tree = proto_item_add_subtree(ti, ett_erldp);
if (is_handshake(tvb, 0)) {
dissect_erldp_handshake(tvb, pinfo, erldp_tree);
return tvb_captured_length(tvb);
}
offset = 0;
msg_len = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(erldp_tree, hf_erldp_length_4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (msg_len == 0) {
col_set_str(pinfo->cinfo, COL_INFO, "KEEP_ALIVE");
return offset;
}
type = tvb_get_guint8(tvb, offset);
switch (type) {
case ERL_PASS_THROUGH:
proto_tree_add_item(erldp_tree, hf_erldp_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case VERSION_MAGIC:
next_tvb = tvb_new_subset(tvb, offset, -1, 4 + msg_len - offset);
offset += dissect_etf_pdu(next_tvb, pinfo, erldp_tree, "DistributionHeader");
if ((tvb_get_guint8(tvb, offset) == SMALL_TUPLE_EXT) && (tvb_get_guint8(tvb, offset + 2) == SMALL_INTEGER_EXT)) {
ctl_op = tvb_get_guint8(tvb, offset + 3);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(ctl_op, VALS(erldp_ctlmsg_vals), "unknown ControlMessage operation (%d)"));
}
offset = dissect_etf_type("ControlMessage", pinfo, tvb, offset, erldp_tree);
if (tvb_reported_length_remaining(tvb, offset) > 0)
dissect_etf_type("Message", pinfo, tvb, offset, erldp_tree);
break;
default:
proto_tree_add_item(erldp_tree, hf_erldp_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
col_set_str(pinfo->cinfo, COL_INFO, "unknown header format");
}
return tvb_captured_length(tvb);
}
static guint get_erldp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
if (is_handshake(tvb, offset))
return(2 + tvb_get_ntohs(tvb, offset));
return(4 + tvb_get_ntohl(tvb, offset));
}
static int
dissect_erldp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data) {
tcp_dissect_pdus(tvb, pinfo, tree,
erldp_desegment,
4,
get_erldp_pdu_len,
dissect_erldp_pdu, data);
return tvb_captured_length(tvb);
}
void proto_register_erldp(void) {
static hf_register_info hf[] = {
{ &hf_erldp_length_2, { "Length", "erldp.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Message Length", HFILL}},
{ &hf_etf_version_magic, { "VERSION_MAGIC", "erldp.version_magic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_tag, { "Tag", "erldp.tag",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_type, { "Type", "erldp.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_version, { "Version", "erldp.version",
FT_UINT16, BASE_DEC, VALS(epmd_version_vals), 0x0,
NULL, HFILL}},
{ &hf_erldp_flags, { "Flags", "erldp.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_challenge, { "Challenge", "erldp.challenge",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_digest, { "Digest", "erldp.digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_name, { "Name", "erldp.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_status, { "Status", "erldp.status",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_num_atom_cache_refs, { "NumberOfAtomCacheRefs", "erldp.num_atom_cache_refs",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_etf_flags, { "Flags", "erldp.etf_flags",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_internal_segment_index, { "InternalSegmentIndex", "erldp.internal_segment_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_atom_length, { "Length", "erldp.atom_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_atom_length2, { "Length", "erldp.atom_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_atom_text, { "AtomText", "erldp.atom_text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_atom_cache_ref, { "AtomCacheReferenceIndex", "erldp.atom_cache_ref",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_small_int_ext, { "Int", "erldp.small_int_ext",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_int_ext, { "Int", "erldp.int_ext",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_pid_ext_id, { "ID", "erldp.pid_ext.id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_pid_ext_serial, { "Serial", "erldp.pid_ext.serial",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_pid_ext_creation, { "Creation", "erldp.pid_ext.creation",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_list_ext_len, { "Len", "erldp.list_ext.len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_new_ref_ext_len, { "Len", "erldp.new_ref_ext.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_new_ref_ext_creation, { "Creation", "erldp.new_ref_ext.creation",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_new_ref_ext_id, { "ID", "erldp.new_ref_ext.id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_erldp_length_4, { "Length", "erldp.len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Message Length", HFILL}},
{ &hf_etf_tag, { "Tag", "erldp.etf_tag",
FT_UINT8, BASE_DEC, VALS(etf_tag_vals), 0x0,
NULL, HFILL}},
{ &hf_etf_dist_header_new_cache, { "NewCacheEntryFlag", "erldp.dist_header.new_cache",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x08,
NULL, HFILL}},
{ &hf_etf_dist_header_segment_index, { "SegmentIndex", "erldp.dist_header.segment_index",
FT_UINT8, BASE_DEC, NULL, 0x7,
NULL, HFILL}},
{ &hf_etf_dist_header_long_atoms, { "LongAtoms", "erldp.dist_header.new_cache",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x12,
NULL, HFILL}},
{ &hf_etf_arity4, { "Arity", "erldp.arity",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_etf_arity, { "Arity", "erldp.arity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_erldp,
&ett_etf,
&ett_etf_flags,
&ett_etf_acrs,
&ett_etf_acr,
&ett_etf_tmp,
};
proto_erldp = proto_register_protocol(PNAME, PSNAME, PFNAME);
erldp_handle = new_register_dissector(PFNAME, dissect_erldp, proto_erldp);
proto_register_field_array(proto_erldp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_erldp(void) {
dissector_add_for_decode_as("tcp.port", erldp_handle);
}
