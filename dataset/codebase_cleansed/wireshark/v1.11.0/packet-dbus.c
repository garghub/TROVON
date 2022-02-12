static gboolean
dbus_validate_object_path(const char *path)
{
if (*path != '/')
return FALSE;
do {
path++;
if (*path == '/')
return FALSE;
while ((*path >= 'A' && *path <= 'Z') || (*path >= 'a' && *path <= 'z') || (*path >= '0' && *path <= '9') || *path == '_')
path++;
if (*path == '\0')
return TRUE;
} while (*path == '/');
return FALSE;
}
static gboolean
dbus_validate_signature(const char *sig _U_)
{
return TRUE;
}
static int
dissect_dbus_sig(tvbuff_t *tvb, dbus_info_t *dinfo, proto_tree *tree, int offset, char sig, dbus_val_t *ret)
{
const int org_offset = offset;
proto_item *ti;
switch (sig) {
case 'y':
{
guint8 val;
val = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_uint_format(tree, hfi_dbus_value_uint.id, tvb, org_offset, offset - org_offset, val, "BYTE: %u", val);
ret->uint = val;
return offset;
}
case 'b':
{
guint32 val;
val = dinfo->get32(tvb, offset);
offset += 4;
ti = proto_tree_add_boolean_format(tree, hfi_dbus_value_bool.id, tvb, org_offset, offset - org_offset, val, "BOOLEAN: %s", val ? "True" : "False");
if (val != 0 && val != 1) {
expert_add_info_format(dinfo->pinfo, ti, &ei_dbus_value_bool_invalid, "Invalid boolean value (must be 0 or 1 is: %u)", val);
return -1;
}
ret->uint = val;
return offset;
}
case 'n':
{
gint16 val;
val = (gint16 )dinfo->get16(tvb, offset);
offset += 2;
proto_tree_add_uint_format(tree, hfi_dbus_value_int.id, tvb, org_offset, offset - org_offset, val, "INT16: %d", val);
return offset;
}
case 'q':
{
guint16 val;
val = dinfo->get16(tvb, offset);
offset += 2;
proto_tree_add_uint_format(tree, hfi_dbus_value_uint.id, tvb, org_offset, offset - org_offset, val, "UINT16: %u", val);
ret->uint = val;
return offset;
}
case 'i':
{
gint32 val;
val = (gint32) dinfo->get32(tvb, offset);
offset += 4;
proto_tree_add_int_format(tree, hfi_dbus_value_int.id, tvb, org_offset, offset - org_offset, val, "INT32: %d", val);
return offset;
}
case 'u':
{
guint32 val;
val = dinfo->get32(tvb, offset);
offset += 4;
proto_tree_add_uint_format(tree, hfi_dbus_value_uint.id, tvb, org_offset, offset - org_offset, val, "UINT32: %u", val);
ret->uint = val;
return offset;
}
case 'x':
case 't':
return -1;
case 'd':
{
gdouble val;
val = dinfo->getdouble(tvb, offset);
offset += 8;
proto_tree_add_double_format(tree, hfi_dbus_value_double.id, tvb, org_offset, offset - org_offset, val, "DOUBLE: %." STRINGIFY(DBL_DIG) "g", val);
return offset;
}
case 's':
case 'o':
{
guint32 len;
char *val;
len = dinfo->get32(tvb, offset);
offset += 4;
val = tvb_get_string(wmem_packet_scope(), tvb, offset, len);
offset += (len + 1 + 3) & ~3;
if (sig == 's') {
ti = proto_tree_add_string_format(tree, hfi_dbus_value_str.id, tvb, org_offset, offset - org_offset, val, "STRING: %s", val);
if (!g_utf8_validate(val, -1, NULL)) {
expert_add_info(dinfo->pinfo, ti, &ei_dbus_value_str_invalid);
return -1;
}
} else {
ti = proto_tree_add_string_format(tree, hfi_dbus_value_str.id, tvb, org_offset, offset - org_offset, val, "OBJECT_PATH: %s", val);
if (!dbus_validate_object_path(val)) {
expert_add_info(dinfo->pinfo, ti, &ei_dbus_invalid_object_path);
return -1;
}
}
ret->str = val;
return offset;
}
case 'g':
{
guint8 len;
char *val;
len = tvb_get_guint8(tvb, offset);
offset += 1;
val = tvb_get_string(wmem_packet_scope(), tvb, offset, len);
offset += (len + 1);
ti = proto_tree_add_string_format(tree, hfi_dbus_value_str.id, tvb, org_offset, offset - org_offset, val, "SIGNATURE: %s", val);
if (!dbus_validate_signature(val)) {
expert_add_info(dinfo->pinfo, ti, &ei_dbus_invalid_signature);
return -1;
}
ret->str = val;
return offset;
}
}
return -1;
}
static int
dissect_dbus_field_signature(tvbuff_t *tvb, dbus_info_t *dinfo, proto_tree *tree, int offset, int field_code)
{
const int org_offset = offset;
proto_item *ti;
guint sig_len;
char *sig;
sig_len = tvb_get_guint8(tvb, offset);
offset += 1;
sig = tvb_get_string(wmem_packet_scope(), tvb, offset, sig_len);
offset += (sig_len + 1);
ti = proto_tree_add_string(tree, &hfi_dbus_type_signature, tvb, org_offset, offset - org_offset, sig);
if (!dbus_validate_signature(sig)) {
expert_add_info(dinfo->pinfo, ti, &ei_dbus_invalid_signature);
return -1;
}
switch (field_code) {
case DBUS_HEADER_FIELD_REPLY_SERIAL:
if (!strcmp(sig, "u")) {
dbus_val_t serial_val;
offset = dissect_dbus_sig(tvb, dinfo, tree, offset, 'u', &serial_val);
if (offset != -1)
{ }
return offset;
}
break;
case DBUS_HEADER_FIELD_DESTINATION:
case DBUS_HEADER_FIELD_SENDER:
if (!strcmp(sig, "s")) {
dbus_val_t addr_val;
offset = dissect_dbus_sig(tvb, dinfo, tree, offset, 's', &addr_val);
if (offset != -1)
SET_ADDRESS((field_code == DBUS_HEADER_FIELD_DESTINATION) ? &dinfo->pinfo->dst : &dinfo->pinfo->src,
AT_STRINGZ, (int)strlen(addr_val.str)+1, addr_val.str);
return offset;
}
break;
case DBUS_HEADER_FIELD_SIGNATURE:
if (!strcmp(sig, "g")) {
dbus_val_t sig_val;
offset = dissect_dbus_sig(tvb, dinfo, tree, offset, 'g', &sig_val);
if (offset != -1)
dinfo->body_sig = sig_val.str;
return offset;
}
break;
}
while (*sig) {
dbus_val_t val;
offset = dissect_dbus_sig(tvb, dinfo, tree, offset, *sig, &val);
if (offset == -1)
return -1;
sig++;
}
return offset;
}
static int
dissect_dbus_hdr_fields(tvbuff_t *tvb, dbus_info_t *dinfo, proto_tree *tree, int offset)
{
int end_offset;
end_offset = offset + dinfo->fields_len;
while (offset < end_offset) {
proto_tree *field_tree;
proto_item *ti;
guint8 field_code;
ti = proto_tree_add_item(tree, &hfi_dbus_hdr_field, tvb, offset, 0, ENC_NA);
field_tree = proto_item_add_subtree(ti, ett_dbus_field);
field_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(field_tree, &hfi_dbus_hdr_field_code, tvb, offset, 1, dinfo->enc);
proto_item_append_text(ti, ": %s", val_to_str(field_code, field_code_vals, "Unknown: %d"));
offset += 1;
offset = dissect_dbus_field_signature(tvb, dinfo, field_tree, offset, field_code);
if (offset == -1)
break;
offset = (offset + 7) & ~7;
proto_item_set_end(ti, tvb, offset);
}
if (offset >= end_offset) {
}
return end_offset;
}
static int
dissect_dbus_hdr(tvbuff_t *tvb, dbus_info_t *dinfo, proto_tree *tree, int offset)
{
proto_tree *hdr_tree;
proto_item *ti;
guint8 type;
ti = proto_tree_add_item(tree, &hfi_dbus_hdr, tvb, offset, 0, ENC_NA);
hdr_tree = proto_item_add_subtree(ti, ett_dbus_hdr);
proto_tree_add_item(hdr_tree, &hfi_dbus_hdr_endianness, tvb, offset, 1, ENC_ASCII | ENC_NA);
offset += 1;
type = tvb_get_guint8(tvb, offset);
col_add_str(dinfo->pinfo->cinfo, COL_INFO, val_to_str_const(type, message_type_vals, ""));
proto_tree_add_item(hdr_tree, &hfi_dbus_hdr_type, tvb, offset, 1, dinfo->enc);
offset += 1;
proto_tree_add_item(hdr_tree, &hfi_dbus_hdr_flags, tvb, offset, 1, dinfo->enc);
offset += 1;
proto_tree_add_item(hdr_tree, &hfi_dbus_hdr_version, tvb, offset, 1, dinfo->enc);
offset += 1;
dinfo->body_len = dinfo->get32(tvb, offset);
proto_tree_add_item(hdr_tree, &hfi_dbus_hdr_body_length, tvb, offset, 4, dinfo->enc);
offset += 4;
proto_tree_add_item(hdr_tree, &hfi_dbus_hdr_serial, tvb, offset, 4, dinfo->enc);
offset += 4;
dinfo->fields_len = dinfo->get32(tvb, offset);
proto_tree_add_item(hdr_tree, &hfi_dbus_hdr_fields_length, tvb, offset, 4, dinfo->enc);
offset += 4;
return offset;
}
static int
dissect_dbus_body(tvbuff_t *tvb, dbus_info_t *dinfo, proto_tree *tree, int offset)
{
proto_tree *body_tree;
proto_item *ti;
if (dinfo->body_len && dinfo->body_sig[0]) {
const char *sig = dinfo->body_sig;
ti = proto_tree_add_item(tree, &hfi_dbus_body, tvb, offset, 0, ENC_NA);
body_tree = proto_item_add_subtree(ti, ett_dbus_body);
while (*sig) {
dbus_val_t val;
offset = dissect_dbus_sig(tvb, dinfo, body_tree, offset, *sig, &val);
if (offset == -1)
return -1;
sig++;
}
proto_item_set_end(ti, tvb, offset);
} else if (dinfo->body_len || dinfo->body_sig[0]) {
}
return offset;
}
static int
dissect_dbus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *dbus_tree = NULL;
dbus_info_t dinfo;
int offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "D-BUS");
col_clear(pinfo->cinfo, COL_INFO);
memset(&dinfo, 0, sizeof(dinfo));
dinfo.pinfo = pinfo;
switch (tvb_get_guint8(tvb, 0)) {
case 'l':
dinfo.enc = ENC_LITTLE_ENDIAN;
dinfo.get16 = tvb_get_letohs;
dinfo.get32 = tvb_get_letohl;
dinfo.getdouble = tvb_get_letohieee_double;
break;
case 'B':
dinfo.enc = ENC_BIG_ENDIAN;
dinfo.get16 = tvb_get_ntohs;
dinfo.get32 = tvb_get_ntohl;
dinfo.getdouble = tvb_get_ntohieee_double;
break;
default:
dinfo.enc = ENC_NA;
dinfo.get16 = tvb_get_ntohs;
dinfo.get32 = tvb_get_ntohl;
dinfo.getdouble = tvb_get_ntohieee_double;
}
if (tree) {
proto_item *ti = proto_tree_add_item(tree, hfi_dbus, tvb, 0, -1, ENC_NA);
dbus_tree = proto_item_add_subtree(ti, ett_dbus);
}
offset = 0;
offset = dissect_dbus_hdr(tvb, &dinfo, dbus_tree, offset);
offset = dissect_dbus_hdr_fields(tvb, &dinfo, dbus_tree, offset);
offset = (offset + 7) & ~7;
if (!dinfo.body_sig)
dinfo.body_sig = "";
offset = dissect_dbus_body(tvb, &dinfo, dbus_tree, offset);
return offset;
}
static guint
get_dbus_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 (*get_guint32)(tvbuff_t *, const gint);
guint32 len_body, len_hdr;
switch (tvb_get_guint8(tvb, offset)) {
case 'l':
get_guint32 = tvb_get_letohl;
break;
case 'B':
default:
get_guint32 = tvb_get_ntohl;
break;
}
len_hdr = DBUS_HEADER_LEN + get_guint32(tvb, offset + 12);
len_hdr = (len_hdr + 7) & ~7;
len_body = get_guint32(tvb, offset + 4);
return len_hdr + len_body;
}
static void
dissect_dbus_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_dbus(tvb, pinfo, tree, NULL);
}
static int
dissect_dbus_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
tcp_dissect_pdus(tvb, pinfo, tree, dbus_desegment, DBUS_HEADER_LEN, get_dbus_message_len, dissect_dbus_pdu);
return tvb_length(tvb);
}
void
proto_register_dbus(void)
{
static header_field_info *hfi[] = {
&hfi_dbus_hdr,
&hfi_dbus_hdr_endianness,
&hfi_dbus_hdr_type,
&hfi_dbus_hdr_flags,
&hfi_dbus_hdr_version,
&hfi_dbus_hdr_body_length,
&hfi_dbus_hdr_serial,
&hfi_dbus_hdr_fields_length,
&hfi_dbus_hdr_field,
&hfi_dbus_hdr_field_code,
&hfi_dbus_type_signature,
&hfi_dbus_body,
&hfi_dbus_value_bool,
&hfi_dbus_value_int,
&hfi_dbus_value_uint,
&hfi_dbus_value_str,
&hfi_dbus_value_double,
};
static gint *ett[] = {
&ett_dbus,
&ett_dbus_hdr,
&ett_dbus_body,
&ett_dbus_field
};
static ei_register_info ei[] = {
{ &ei_dbus_value_bool_invalid, { "dbus.value.bool.invalid", PI_PROTOCOL, PI_WARN, "Invalid boolean value", EXPFILL }},
{ &ei_dbus_value_str_invalid, { "dbus.value.str.invalid", PI_PROTOCOL, PI_WARN, "Invalid string (not UTF-8)", EXPFILL }},
{ &ei_dbus_invalid_object_path, { "dbus.invalid_object_path", PI_PROTOCOL, PI_WARN, "Invalid object_path", EXPFILL }},
{ &ei_dbus_invalid_signature, { "dbus.invalid_signature", PI_PROTOCOL, PI_WARN, "Invalid signature", EXPFILL }},
};
expert_module_t *expert_dbus;
int proto_dbus;
proto_dbus = proto_register_protocol("D-Bus", "D-BUS", "dbus");
hfi_dbus = proto_registrar_get_nth(proto_dbus);
proto_register_fields(proto_dbus, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
expert_dbus = expert_register_protocol(proto_dbus);
expert_register_field_array(expert_dbus, ei, array_length(ei));
dbus_handle = new_create_dissector_handle(dissect_dbus, proto_dbus);
dbus_handle_tcp = new_create_dissector_handle(dissect_dbus_tcp, proto_dbus);
}
void
proto_reg_handoff_dbus(void)
{
dissector_add_uint("wtap_encap", WTAP_ENCAP_DBUS, dbus_handle);
dissector_add_handle("tcp.port", dbus_handle_tcp);
}
