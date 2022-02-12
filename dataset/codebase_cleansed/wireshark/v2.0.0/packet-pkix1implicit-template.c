int
dissect_pkix1implicit_ReasonFlags(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) {
offset = dissect_x509ce_ReasonFlags(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_pkix1implicit_GeneralName(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) {
offset = dissect_x509ce_GeneralName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
void proto_register_pkix1implicit(void) {
static hf_register_info hf[] = {
#include "packet-pkix1implicit-hfarr.c"
};
static gint *ett[] = {
#include "packet-pkix1implicit-ettarr.c"
};
proto_pkix1implicit = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkix1implicit, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkix1implicit(void) {
#include "packet-pkix1implicit-dis-tab.c"
}
