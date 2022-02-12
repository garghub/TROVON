static void
dissect_gdb_token(void *tvbparse_data, const void *wanted_data, tvbparse_elem_t *tok)
{
proto_tree *tree;
guint token;
guint8 ack;
if (!tok)
return;
tree = (proto_tree *)tvbparse_data;
token = GPOINTER_TO_UINT(wanted_data);
switch (token) {
case GDB_TOK_ACK:
ack = tvb_get_guint8(tok->tvb, tok->offset);
proto_tree_add_uint_format(tree, hf_gdb_ack,
tok->tvb, tok->offset, tok->len, ack,
"Acknowledgement: %s (%c)",
val_to_str_const(ack, gdb_ack, "unknown"), ack);
break;
case GDB_TOK_START:
proto_tree_add_item(tree, hf_gdb_start,
tok->tvb, tok->offset, tok->len, ENC_ASCII|ENC_NA);
break;
case GDB_TOK_PAYLOAD:
proto_tree_add_item(tree, hf_gdb_payload,
tok->tvb, tok->offset, tok->len, ENC_NA);
break;
case GDB_TOK_END:
proto_tree_add_item(tree, hf_gdb_end,
tok->tvb, tok->offset, tok->len, ENC_ASCII|ENC_NA);
break;
case GDB_TOK_CHKSUM:
proto_tree_add_checksum(tree, tok->tvb, tok->offset, hf_gdb_chksum, -1, NULL, NULL, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
break;
default:
break;
}
}
static void init_gdb_parser(void) {
tvbparse_wanted_t *want_ack;
tvbparse_wanted_t *want_start;
tvbparse_wanted_t *want_payload;
tvbparse_wanted_t *want_end;
tvbparse_wanted_t *want_chksum;
want_ack = tvbparse_chars(-1, 1, 1, "+-",
GUINT_TO_POINTER(GDB_TOK_ACK), NULL, dissect_gdb_token);
want_start = tvbparse_chars(-1, 1, 1, "$",
GUINT_TO_POINTER(GDB_TOK_START), NULL, dissect_gdb_token);
want_payload = tvbparse_not_chars(-1, 1, 0, "$#",
GUINT_TO_POINTER(GDB_TOK_PAYLOAD), NULL, dissect_gdb_token);
want_end = tvbparse_chars(-1, 1, 1, "#",
GUINT_TO_POINTER(GDB_TOK_END), NULL, dissect_gdb_token);
want_chksum = tvbparse_chars(-1, 2, 2, "0123456789abcdefABCDEF",
GUINT_TO_POINTER(GDB_TOK_CHKSUM), NULL, dissect_gdb_token);
want = tvbparse_set_seq(-1, NULL, NULL, NULL,
tvbparse_some(-1, 0, 1, NULL, NULL, NULL, want_ack),
want_start, want_payload, want_end, want_chksum, NULL);
}
static void
dissect_gdb_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *gdb_tree;
tvbparse_t *tt;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GDB");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_protocol_format(tree, proto_gdb,
tvb, 0, tvb_reported_length(tvb), "GDB Remote Serial Protocol");
gdb_tree = proto_item_add_subtree(ti, ett_gdb);
tt = tvbparse_init(tvb, 0, -1, (void *)gdb_tree, NULL);
while(tvbparse_get(tt, want)) {
;
}
}
static int
dissect_gdb_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset=0, offset_start;
gint pos;
guint packet_len;
tvbuff_t *packet_tvb;
while (tvb_captured_length_remaining(tvb, offset) > 0) {
packet_tvb = NULL;
offset_start = offset;
pos = tvb_find_guint8(tvb, offset, -1, '#');
if (pos != -1) {
offset += pos;
offset++;
if (tvb_bytes_exist(tvb, offset, 2)) {
offset += 2;
packet_len = offset-offset_start;
packet_tvb = tvb_new_subset_length(tvb, offset_start,
packet_len);
}
}
if (packet_tvb)
dissect_gdb_packet(tvb, pinfo, tree);
else {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return tvb_captured_length(tvb);
}
}
return tvb_captured_length(tvb);
}
void
proto_register_gdb(void)
{
static hf_register_info hf[] = {
{ &hf_gdb_ack,
{ "Acknowledge", "gdb.ack", FT_UINT8, BASE_HEX,
VALS(gdb_ack), 0, NULL, HFILL } },
{ &hf_gdb_start,
{ "Start character", "gdb.start", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_gdb_payload,
{ "Payload", "gdb.payload", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_gdb_end,
{ "Terminating character", "gdb.end", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_gdb_chksum,
{ "Checksum", "gdb.chksum", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL } }
};
static gint *ett[] = {
&ett_gdb
};
proto_gdb = proto_register_protocol(
"GDB Remote Serial Protocol", "GDB remote", "gdb");
proto_register_field_array(proto_gdb, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
init_gdb_parser();
}
void
proto_reg_handoff_gdb(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t gdb_handle;
if (!initialized) {
gdb_handle = create_dissector_handle(dissect_gdb_tcp, proto_gdb);
initialized = TRUE;
}
dissector_add_for_decode_as("tcp.port", gdb_handle);
}
