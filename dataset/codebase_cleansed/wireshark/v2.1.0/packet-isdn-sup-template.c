static const isdn_sup_op_t *get_op(gint32 opcode) {
int i;
for (i = array_length(isdn_sup_op_tab) - 1; i >= 0; i--)
if (isdn_sup_op_tab[i].opcode == opcode)
return &isdn_sup_op_tab[i];
return NULL;
}
static const isdn_sup_err_t *get_err(gint32 errcode) {
int i;
for (i = array_length(isdn_sup_err_tab) - 1; i >= 0; i--)
if (isdn_sup_err_tab[i].errcode == errcode)
return &isdn_sup_err_tab[i];
return NULL;
}
static int
dissect_isdn_sup_arg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
int offset = 0;
rose_ctx_t *rctx;
gint32 opcode = 0;
const gchar *p;
const isdn_sup_op_t *op_ptr;
proto_item *ti;
proto_tree *isdn_sup_tree;
if (data == NULL)
return 0;
rctx = get_rose_ctx(data);
DISSECTOR_ASSERT(rctx);
if (rctx->d.pdu != 1)
return offset;
if (rctx->d.code == 0) {
opcode = rctx->d.code_local;
} else {
return offset;
}
op_ptr = get_op(opcode);
if (!op_ptr)
return offset;
ti = proto_tree_add_item(tree, proto_isdn_sup, tvb, offset, -1, ENC_NA);
isdn_sup_tree = proto_item_add_subtree(ti, ett_isdn_sup);
proto_tree_add_uint(isdn_sup_tree, hf_isdn_sup_operation, tvb, 0, 0, opcode);
p = try_val_to_str(opcode, VALS(isdn_sup_str_operation));
if (p) {
proto_item_append_text(ti, ": %s", p);
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (op_ptr->arg_pdu)
offset = op_ptr->arg_pdu(tvb, pinfo, isdn_sup_tree, NULL);
else
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_expert(tree, pinfo, &ei_isdn_sup_unsupported_error_type, tvb, offset, -1);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_isdn_sup_res(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
gint offset = 0;
rose_ctx_t *rctx;
gint32 opcode = 0;
const gchar *p;
const isdn_sup_op_t *op_ptr;
proto_item *ti;
proto_tree *isdn_sup_tree;
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
ti = proto_tree_add_item(tree, proto_isdn_sup, tvb, offset, -1, ENC_NA);
isdn_sup_tree = proto_item_add_subtree(ti, ett_isdn_sup);
proto_tree_add_uint(isdn_sup_tree, hf_isdn_sup_operation, tvb, 0, 0, opcode);
p = try_val_to_str(opcode, VALS(isdn_sup_str_operation));
if (p) {
proto_item_append_text(ti, ": %s", p);
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (op_ptr->res_pdu)
offset = op_ptr->res_pdu(tvb, pinfo, isdn_sup_tree, NULL);
else
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_expert(tree, pinfo, &ei_isdn_sup_unsupported_result_type, tvb, offset, -1);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_isdn_sup_err(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
int offset = 0;
rose_ctx_t *rctx;
gint32 errcode;
const isdn_sup_err_t *err_ptr;
const gchar *p;
proto_item *ti;
proto_tree *isdn_sup_tree;
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
ti = proto_tree_add_item(tree, proto_isdn_sup, tvb, offset, -1, ENC_NA);
isdn_sup_tree = proto_item_add_subtree(ti, ett_isdn_sup);
proto_tree_add_uint(isdn_sup_tree, hf_isdn_sup_error, tvb, 0, 0, errcode);
p = try_val_to_str(errcode, VALS(isdn_sup_str_error));
if (p) {
proto_item_append_text(ti, ": %s", p);
proto_item_append_text(rctx->d.code_item, " - %s", p);
if (rctx->apdu_depth >= 0)
proto_item_append_text(proto_item_get_parent_nth(proto_tree_get_parent(tree), rctx->apdu_depth), " %s", p);
}
if (err_ptr->err_pdu)
offset = err_ptr->err_pdu(tvb, pinfo, isdn_sup_tree, NULL);
else
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_expert(tree, pinfo, &ei_isdn_sup_unsupported_error_type, tvb, offset, -1);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
void proto_reg_handoff_isdn_sup(void) {
int i;
#if 0
dissector_handle_t q931_handle;
#endif
dissector_handle_t isdn_sup_arg_handle;
dissector_handle_t isdn_sup_res_handle;
dissector_handle_t isdn_sup_err_handle;
#if 0
q931_handle = find_dissector("q931");
#endif
isdn_sup_arg_handle = create_dissector_handle(dissect_isdn_sup_arg, proto_isdn_sup);
isdn_sup_res_handle = create_dissector_handle(dissect_isdn_sup_res, proto_isdn_sup);
for (i=0; i<(int)array_length(isdn_sup_op_tab); i++) {
dissector_add_uint("q932.ros.etsi.local.arg", isdn_sup_op_tab[i].opcode, isdn_sup_arg_handle);
dissector_add_uint("q932.ros.etsi.local.res", isdn_sup_op_tab[i].opcode, isdn_sup_res_handle);
}
for (i=0; i<(int)array_length(isdn_sup_global_op_tab); i++) {
if(isdn_sup_global_op_tab->arg_pdu)
dissector_add_string("q932.ros.global.arg", isdn_sup_global_op_tab[i].oid, create_dissector_handle(isdn_sup_global_op_tab[i].arg_pdu, proto_isdn_sup));
if(isdn_sup_global_op_tab->res_pdu)
dissector_add_string("q932.ros.global.res", isdn_sup_global_op_tab[i].oid, create_dissector_handle(isdn_sup_global_op_tab[i].res_pdu, proto_isdn_sup));
}
isdn_sup_err_handle = create_dissector_handle(dissect_isdn_sup_err, proto_isdn_sup);
for (i=0; i<(int)array_length(isdn_sup_err_tab); i++) {
dissector_add_uint("q932.ros.etsi.local.err", isdn_sup_err_tab[i].errcode, isdn_sup_err_handle);
}
}
void proto_register_isdn_sup(void) {
static hf_register_info hf[] = {
{ &hf_isdn_sup,
{ "isdn_sup", "isdn_sup.1",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_isdn_sup_operation,
{ "Operation", "isdn_sup.operation",
FT_UINT8, BASE_DEC, VALS(isdn_sup_str_operation), 0x0,
NULL, HFILL }
},
{ &hf_isdn_sup_error,
{ "Error", "isdn_sup.error",
FT_UINT8, BASE_DEC, VALS(isdn_sup_str_error), 0x0,
NULL, HFILL }
},
#include "packet-isdn-sup-hfarr.c"
};
static gint *ett[] = {
&ett_isdn_sup,
#include "packet-isdn-sup-ettarr.c"
};
static ei_register_info ei[] = {
#if 0
{ &ei_isdn_sup_unsupported_arg_type, { "isdn_sup.unsupported.arg_type", PI_UNDECODED, PI_WARN, "UNSUPPORTED ARGUMENT TYPE (ETSI sup)", EXPFILL }},
#endif
{ &ei_isdn_sup_unsupported_result_type, { "isdn_sup.unsupported.result_type", PI_UNDECODED, PI_WARN, "UNSUPPORTED RESULT TYPE (ETSI sup)", EXPFILL }},
{ &ei_isdn_sup_unsupported_error_type, { "isdn_sup.unsupported.error_type", PI_UNDECODED, PI_WARN, "UNSUPPORTED ERROR TYPE (ETSI sup)", EXPFILL }},
};
expert_module_t* expert_isdn_sup;
proto_isdn_sup = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_isdn_sup, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_isdn_sup = expert_register_protocol(proto_isdn_sup);
expert_register_field_array(expert_isdn_sup, ei, array_length(ei));
}
