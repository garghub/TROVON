gef_ctx_t* gef_ctx_alloc(gef_ctx_t *parent, const gchar *type) {
gef_ctx_t *gefx;
gefx = wmem_new0(wmem_packet_scope(), gef_ctx_t);
gefx->signature = GEF_CTX_SIGNATURE;
gefx->parent = parent;
gefx->type = type;
return gefx;
}
gboolean gef_ctx_check_signature(gef_ctx_t *gefx) {
return gefx && (gefx->signature == GEF_CTX_SIGNATURE);
}
gef_ctx_t* gef_ctx_get(void *ptr) {
gef_ctx_t *gefx = (gef_ctx_t*)ptr;
asn1_ctx_t *actx = (asn1_ctx_t*)ptr;
if (!asn1_ctx_check_signature(actx))
actx = NULL;
if (actx)
gefx = (gef_ctx_t *)actx->private_data;
if (!gef_ctx_check_signature(gefx))
gefx = NULL;
return gefx;
}
void gef_ctx_update_key(gef_ctx_t *gefx) {
const gchar *parent_key;
if (!gefx) return;
parent_key = (gefx->parent) ? gefx->parent->key : NULL;
gefx->key = wmem_strdup_printf(wmem_packet_scope(),
"%s%s"
"%s%s%s"
"%s%s" ,
(parent_key) ? parent_key : "", (parent_key) ? "/" : "",
(gefx->type) ? gefx->type : "", (gefx->type && (gefx->id || gefx->subid)) ? "/" : "", (gefx->id) ? gefx->id : "",
(gefx->subid) ? "-" : "", (gefx->subid) ? gefx->subid : ""
);
}
void proto_register_h323(void) {
static hf_register_info hf[] = {
#include "packet-h323-hfarr.c"
};
static gint *ett[] = {
#include "packet-h323-ettarr.c"
};
proto_h323 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h323, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_h323(void)
{
dissector_handle_t q931_handle;
q931_handle = find_dissector("q931");
dissector_add_string("h225.tp", "1.3.12.9", q931_handle);
dissector_add_string("h225.gef.content", "GenericData/1000/1",
create_dissector_handle(dissect_RasTunnelledSignallingMessage_PDU, proto_h323));
dissector_add_string("h225.gef.content", "GenericData/1/1",
create_dissector_handle(dissect_RobustnessData_PDU, proto_h323));
}
