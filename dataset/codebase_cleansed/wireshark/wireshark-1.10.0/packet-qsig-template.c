static const qsig_op_t *get_op(gint32 opcode) {
int i;
for (i = array_length(qsig_op_tab) - 1; i >= 0; i--)
if (qsig_op_tab[i].opcode == opcode)
return &qsig_op_tab[i];
return NULL;
}
static gint32 get_service(gint32 opcode) {
if ((opcode < 0) || (opcode >= (int)array_length(op2srv_tab)))
return NO_SRV;
return op2srv_tab[opcode];
}
static const qsig_err_t *get_err(gint32 errcode) {
int i;
for (i = array_length(qsig_err_tab) - 1; i >= 0; i--)
if (qsig_err_tab[i].errcode == errcode)
return &qsig_err_tab[i];
return NULL;
}
static int
dissect_qsig_arg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset;
rose_ctx_t *rctx;
gint32 opcode = 0, service;
const qsig_op_t *op_ptr;
const gchar *p;
proto_item *ti, *ti_tmp;
proto_tree *qsig_tree;
offset = 0;
rctx = get_rose_ctx(pinfo->private_data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 1)
return offset;
if (rctx->d.code == 0) {
opcode = rctx->d.code_local;
op_ptr = get_op(opcode);
} else if (rctx->d.code == 1) {
op_ptr = (qsig_op_t *)g_hash_table_lookup(qsig_oid2op_hashtable, rctx->d.code_global);
if (op_ptr) opcode = op_ptr->opcode;
} else {
return offset;
}
if (!op_ptr)
return offset;
service = get_service(opcode);
ti = proto_tree_add_item(tree, proto_qsig, tvb, offset, tvb_length(tvb), ENC_NA);
qsig_tree = proto_item_add_subtree(ti, ett_qsig);
proto_tree_add_uint(qsig_tree, hf_qsig_operation, tvb, 0, 0, opcode);
p = try_val_to_str(opcode, VALS(qsig_str_operation));
if (p) {
proto_item_append_text(ti, ": %s", p);
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
ti_tmp = proto_tree_add_uint(qsig_tree, hf_qsig_service, tvb, 0, 0, service);
p = try_val_to_str(service, VALS(qsig_str_service_name));
if (p) proto_item_append_text(ti_tmp, " - %s", p);
if (op_ptr->arg_pdu)
offset = op_ptr->arg_pdu(tvb, pinfo, qsig_tree, NULL);
else
if (tvb_length_remaining(tvb, offset) > 0) {
proto_tree_add_text(qsig_tree, tvb, offset, -1, "UNSUPPORTED ARGUMENT TYPE (QSIG)");
offset += tvb_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_qsig_res(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
gint offset;
rose_ctx_t *rctx;
gint32 opcode, service;
const qsig_op_t *op_ptr;
const gchar *p;
proto_item *ti, *ti_tmp;
proto_tree *qsig_tree;
offset = 0;
rctx = get_rose_ctx(pinfo->private_data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 2)
return offset;
if (rctx->d.code != 0)
return offset;
opcode = rctx->d.code_local;
op_ptr = get_op(opcode);
if (!op_ptr)
return offset;
service = get_service(opcode);
ti = proto_tree_add_item(tree, proto_qsig, tvb, offset, tvb_length(tvb), ENC_NA);
qsig_tree = proto_item_add_subtree(ti, ett_qsig);
proto_tree_add_uint(qsig_tree, hf_qsig_operation, tvb, 0, 0, opcode);
p = try_val_to_str(opcode, VALS(qsig_str_operation));
if (p) {
proto_item_append_text(ti, ": %s", p);
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
ti_tmp = proto_tree_add_uint(qsig_tree, hf_qsig_service, tvb, 0, 0, service);
p = try_val_to_str(service, VALS(qsig_str_service_name));
if (p) proto_item_append_text(ti_tmp, " - %s", p);
if (op_ptr->res_pdu)
offset = op_ptr->res_pdu(tvb, pinfo, qsig_tree, NULL);
else
if (tvb_length_remaining(tvb, offset) > 0) {
proto_tree_add_text(qsig_tree, tvb, offset, -1, "UNSUPPORTED RESULT TYPE (QSIG)");
offset += tvb_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_qsig_err(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset;
rose_ctx_t *rctx;
gint32 errcode;
const qsig_err_t *err_ptr;
const gchar *p;
proto_item *ti;
proto_tree *qsig_tree;
offset = 0;
rctx = get_rose_ctx(pinfo->private_data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 3)
return offset;
if (rctx->d.code != 0)
return offset;
errcode = rctx->d.code_local;
err_ptr = get_err(errcode);
if (!err_ptr)
return offset;
ti = proto_tree_add_item(tree, proto_qsig, tvb, offset, tvb_length(tvb), ENC_NA);
qsig_tree = proto_item_add_subtree(ti, ett_qsig);
proto_tree_add_uint(qsig_tree, hf_qsig_error, tvb, 0, 0, errcode);
p = try_val_to_str(errcode, VALS(qsig_str_error));
if (p) {
proto_item_append_text(ti, ": %s", p);
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (err_ptr->err_pdu)
offset = err_ptr->err_pdu(tvb, pinfo, qsig_tree, NULL);
else
if (tvb_length_remaining(tvb, offset) > 0) {
proto_tree_add_text(qsig_tree, tvb, offset, -1, "UNSUPPORTED ERROR TYPE (QSIG)");
offset += tvb_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_qsig_transit_counter_ie(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, int length _U_) {
proto_tree_add_item(tree, hf_qsig_tc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_qsig_party_category_ie(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, int length _U_) {
proto_tree_add_item(tree, hf_qsig_pc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static void
dissect_qsig_ie(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int codeset) {
gint offset;
proto_item *ti, *ti_ie, *hidden_item;
proto_tree *ie_tree;
guint8 ie_type, ie_len;
offset = 0;
ti = proto_tree_add_item(tree, proto_qsig, tvb, offset, -1, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
ie_type = tvb_get_guint8(tvb, offset);
ie_len = tvb_get_guint8(tvb, offset + 1);
ti_ie = proto_tree_add_text(tree, tvb, offset, -1, "%s",
val_to_str(ie_type, VALS(qsig_str_ie_type[codeset]), "unknown (0x%02X)"));
ie_tree = proto_item_add_subtree(ti_ie, ett_qsig_ie);
proto_tree_add_item(ie_tree, *hf_qsig_ie_type_arr[codeset], tvb, offset, 1, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_item(ie_tree, hf_qsig_ie_type, tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(ie_tree, hf_qsig_ie_len, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
offset += 2;
if (tvb_length_remaining(tvb, offset) <= 0)
return;
switch ((codeset << 8) | ie_type) {
case CS4 | QSIG_IE_TRANSIT_COUNTER :
dissect_qsig_transit_counter_ie(tvb, offset, pinfo, ie_tree, ie_len);
break;
case CS5 | QSIG_IE_PARTY_CATEGORY :
dissect_qsig_party_category_ie(tvb, offset, pinfo, ie_tree, ie_len);
break;
default:
if (ie_len > 0) {
if (tree) proto_tree_add_item(ie_tree, hf_qsig_ie_data, tvb, offset, ie_len, ENC_NA);
}
}
}
static void
dissect_qsig_ie_cs4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
dissect_qsig_ie(tvb, pinfo, tree, 4);
}
static void
dissect_qsig_ie_cs5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
dissect_qsig_ie(tvb, pinfo, tree, 5);
}
static void qsig_init_tables(void) {
guint i;
gint opcode, *key;
gchar *oid;
if (qsig_opcode2oid_hashtable)
g_hash_table_destroy(qsig_opcode2oid_hashtable);
qsig_opcode2oid_hashtable = g_hash_table_new_full(g_int_hash, g_int_equal, g_free, g_free);
if (qsig_oid2op_hashtable)
g_hash_table_destroy(qsig_oid2op_hashtable);
qsig_oid2op_hashtable = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
for (i=0; i<array_length(qsig_op_tab); i++) {
opcode = qsig_op_tab[i].opcode;
oid = g_strdup_printf("1.3.12.9.%d", opcode);
key = (gint *)g_malloc(sizeof(gint));
*key = opcode;
g_hash_table_insert(qsig_opcode2oid_hashtable, key, oid);
g_hash_table_insert(qsig_oid2op_hashtable, g_strdup(oid), (gpointer)&qsig_op_tab[i]);
}
}
void proto_register_qsig(void) {
static hf_register_info hf[] = {
{ &hf_qsig_operation, { "Operation", "qsig.operation",
FT_UINT8, BASE_DEC, VALS(qsig_str_operation), 0x0,
NULL, HFILL }},
{ &hf_qsig_service, { "Service", "qsig.service",
FT_UINT8, BASE_DEC, VALS(qsig_str_service), 0x0,
"Supplementary Service", HFILL }},
{ &hf_qsig_error, { "Error", "qsig.error",
FT_UINT8, BASE_DEC, VALS(qsig_str_error), 0x0,
NULL, HFILL }},
{ &hf_qsig_ie_type, { "Type", "qsig.ie.type",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Information Element Type", HFILL }},
{ &hf_qsig_ie_type_cs4, { "Type", "qsig.ie.type.cs4",
FT_UINT8, BASE_HEX, VALS(qsig_str_ie_type_cs4), 0x0,
"Information Element Type (Codeset 4)", HFILL }},
{ &hf_qsig_ie_type_cs5, { "Type", "qsig.ie.type.cs5",
FT_UINT8, BASE_HEX, VALS(qsig_str_ie_type_cs5), 0x0,
"Information Element Type (Codeset 5)", HFILL }},
{ &hf_qsig_ie_len, { "Length", "qsig.ie.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Information Element Length", HFILL }},
{ &hf_qsig_ie_data, { "Data", "qsig.ie.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_qsig_tc, { "Transit count", "qsig.tc",
FT_UINT8, BASE_DEC, NULL, 0x1F,
NULL, HFILL }},
{ &hf_qsig_pc, { "Party category", "qsig.pc",
FT_UINT8, BASE_HEX, VALS(qsig_str_pc), 0x07,
NULL, HFILL }},
#include "packet-qsig-hfarr.c"
};
static gint *ett[] = {
&ett_qsig,
&ett_qsig_ie,
&ett_qsig_unknown_extension,
#include "packet-qsig-ettarr.c"
&ett_cnq_PSS1InformationElement,
};
proto_qsig = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_qsig, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
extension_dissector_table = register_dissector_table("qsig.ext", "QSIG Extension", FT_STRING, BASE_NONE);
qsig_init_tables();
}
void proto_reg_handoff_qsig(void) {
int i;
gint key;
const gchar *oid;
dissector_handle_t q931_handle;
dissector_handle_t qsig_arg_handle;
dissector_handle_t qsig_res_handle;
dissector_handle_t qsig_err_handle;
dissector_handle_t qsig_ie_handle;
q931_handle = find_dissector("q931");
q931_ie_handle = find_dissector("q931.ie");
qsig_arg_handle = new_create_dissector_handle(dissect_qsig_arg, proto_qsig);
qsig_res_handle = new_create_dissector_handle(dissect_qsig_res, proto_qsig);
for (i=0; i<(int)array_length(qsig_op_tab); i++) {
dissector_add_uint("q932.ros.local.arg", qsig_op_tab[i].opcode, qsig_arg_handle);
dissector_add_uint("q932.ros.local.res", qsig_op_tab[i].opcode, qsig_res_handle);
key = qsig_op_tab[i].opcode;
oid = (const gchar *)g_hash_table_lookup(qsig_opcode2oid_hashtable, &key);
if (oid) {
dissector_add_string("q932.ros.global.arg", oid, qsig_arg_handle);
dissector_add_string("q932.ros.global.res", oid, qsig_res_handle);
}
}
qsig_err_handle = new_create_dissector_handle(dissect_qsig_err, proto_qsig);
for (i=0; i<(int)array_length(qsig_err_tab); i++) {
dissector_add_uint("q932.ros.local.err", qsig_err_tab[i].errcode, qsig_err_handle);
}
qsig_ie_handle = create_dissector_handle(dissect_qsig_ie_cs4, proto_qsig);
dissector_add_uint("q931.ie", CS4 | QSIG_IE_TRANSIT_COUNTER, qsig_ie_handle);
qsig_ie_handle = create_dissector_handle(dissect_qsig_ie_cs5, proto_qsig);
dissector_add_uint("q931.ie", CS5 | QSIG_IE_PARTY_CATEGORY, qsig_ie_handle);
dissector_add_string("media_type", "application/qsig", q931_handle);
}
