static const h450_op_t *get_op(gint32 opcode) {
int i;
for (i = array_length(h450_op_tab) - 1; i >= 0; i--)
if (h450_op_tab[i].opcode == opcode)
return &h450_op_tab[i];
return NULL;
}
static const h450_err_t *get_err(gint32 errcode) {
int i;
for (i = array_length(h450_err_tab) - 1; i >= 0; i--)
if (h450_err_tab[i].errcode == errcode)
return &h450_err_tab[i];
return NULL;
}
static int
dissect_h450_arg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
proto_item *hidden_item;
int offset = 0;
rose_ctx_t *rctx;
gint32 opcode;
const h450_op_t *op_ptr;
const gchar *p;
if (data == NULL)
return 0;
rctx = get_rose_ctx(data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 1)
return offset;
if (rctx->d.code != 0)
return offset;
opcode = rctx->d.code_local;
op_ptr = get_op(opcode);
if (!op_ptr)
return offset;
hidden_item = proto_tree_add_uint(tree, hf_h450_operation, tvb, 0, 0, opcode);
PROTO_ITEM_SET_HIDDEN(hidden_item);
p = try_val_to_str(opcode, VALS(h450_str_operation));
if (p) {
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (op_ptr->arg_pdu && (tvb_reported_length_remaining(tvb, offset) > 0))
offset = op_ptr->arg_pdu(tvb, pinfo, tree, NULL);
else
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_expert(tree, pinfo, &ei_h450_unsupported_arg_type, tvb, offset, -1);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_h450_res(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
proto_item *hidden_item;
int offset = 0;
rose_ctx_t *rctx;
gint32 opcode;
const h450_op_t *op_ptr;
const gchar *p;
if (data == NULL)
return 0;
rctx = get_rose_ctx(data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 2)
return offset;
if (rctx->d.code != 0)
return offset;
opcode = rctx->d.code_local;
op_ptr = get_op(opcode);
if (!op_ptr)
return offset;
hidden_item = proto_tree_add_uint(tree, hf_h450_operation, tvb, 0, 0, opcode);
PROTO_ITEM_SET_HIDDEN(hidden_item);
p = try_val_to_str(opcode, VALS(h450_str_operation));
if (p) {
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (op_ptr->res_pdu && (tvb_reported_length_remaining(tvb, offset) > 0))
offset = op_ptr->res_pdu(tvb, pinfo, tree, NULL);
else
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_expert(tree, pinfo, &ei_h450_unsupported_result_type, tvb, offset, -1);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_h450_err(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
proto_item *hidden_item;
int offset = 0;
rose_ctx_t *rctx;
gint32 errcode;
const h450_err_t *err_ptr;
const gchar *p;
if (data == NULL)
return 0;
rctx = get_rose_ctx(data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 3)
return offset;
if (rctx->d.code != 0)
return offset;
errcode = rctx->d.code_local;
err_ptr = get_err(errcode);
if (!err_ptr)
return offset;
hidden_item = proto_tree_add_uint(tree, hf_h450_error, tvb, 0, 0, errcode);
PROTO_ITEM_SET_HIDDEN(hidden_item);
p = try_val_to_str(errcode, VALS(h450_str_error));
if (p) {
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (err_ptr->err_pdu && (tvb_reported_length_remaining(tvb, offset) > 0))
offset = err_ptr->err_pdu(tvb, pinfo, tree, NULL);
else
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_expert(tree, pinfo, &ei_h450_unsupported_error_type, tvb, offset, -1);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
void proto_register_h450(void) {
static hf_register_info hf[] = {
{ &hf_h450_operation, { "Operation", "h450.operation",
FT_UINT8, BASE_DEC, VALS(h450_str_operation), 0x0,
NULL, HFILL }},
{ &hf_h450_error, { "Error", "h450.error",
FT_UINT8, BASE_DEC, VALS(h450_str_error), 0x0,
NULL, HFILL }},
#include "packet-h450-hfarr.c"
};
static gint *ett[] = {
#include "packet-h450-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_h450_unsupported_arg_type, { "h450.unsupported.arg_type", PI_UNDECODED, PI_WARN, "UNSUPPORTED ARGUMENT TYPE (H.450)", EXPFILL }},
{ &ei_h450_unsupported_result_type, { "h450.unsupported.result_type", PI_UNDECODED, PI_WARN, "UNSUPPORTED RESULT TYPE (H.450)", EXPFILL }},
{ &ei_h450_unsupported_error_type, { "h450.unsupported.error_type", PI_UNDECODED, PI_WARN, "UNSUPPORTED ERROR TYPE (H.450)", EXPFILL }},
};
expert_module_t* expert_h450;
proto_h450 = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("h4501", dissect_h450_H4501SupplementaryService_PDU, proto_h450);
proto_register_field_array(proto_h450, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_h450 = expert_register_protocol(proto_h450);
expert_register_field_array(expert_h450, ei, array_length(ei));
rose_ctx_init(&h450_rose_ctx);
h450_rose_ctx.arg_global_dissector_table = register_dissector_table("h450.ros.global.arg", "H.450 Operation Argument (global opcode)", proto_h450, FT_STRING, BASE_NONE, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
h450_rose_ctx.res_global_dissector_table = register_dissector_table("h450.ros.global.res", "H.450 Operation Result (global opcode)", proto_h450, FT_STRING, BASE_NONE, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
h450_rose_ctx.arg_local_dissector_table = register_dissector_table("h450.ros.local.arg", "H.450 Operation Argument (local opcode)", proto_h450, FT_UINT32, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
h450_rose_ctx.res_local_dissector_table = register_dissector_table("h450.ros.local.res", "H.450 Operation Result (local opcode)", proto_h450, FT_UINT32, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
h450_rose_ctx.err_global_dissector_table = register_dissector_table("h450.ros.global.err", "H.450 Error (global opcode)", proto_h450, FT_STRING, BASE_NONE, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
h450_rose_ctx.err_local_dissector_table = register_dissector_table("h450.ros.local.err", "H.450 Error (local opcode)", proto_h450, FT_UINT32, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_h450(void)
{
int i;
dissector_handle_t h450_arg_handle;
dissector_handle_t h450_res_handle;
dissector_handle_t h450_err_handle;
h450_arg_handle = create_dissector_handle(dissect_h450_arg, proto_h450);
h450_res_handle = create_dissector_handle(dissect_h450_res, proto_h450);
for (i=0; i<(int)array_length(h450_op_tab); i++) {
dissector_add_uint("h450.ros.local.arg", h450_op_tab[i].opcode, h450_arg_handle);
dissector_add_uint("h450.ros.local.res", h450_op_tab[i].opcode, h450_res_handle);
}
h450_err_handle = create_dissector_handle(dissect_h450_err, proto_h450);
for (i=0; i<(int)array_length(h450_err_tab); i++) {
dissector_add_uint("h450.ros.local.err", h450_err_tab[i].errcode, h450_err_handle);
}
}
