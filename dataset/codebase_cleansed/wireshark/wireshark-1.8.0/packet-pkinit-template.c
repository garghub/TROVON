int
dissect_pkinit_PA_PK_AS_REQ(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_) {
offset = dissect_pkinit_PaPkAsReq(FALSE, tvb, offset, actx, tree, -1);
return offset;
}
int
dissect_pkinit_PA_PK_AS_REP(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_) {
offset = dissect_pkinit_PaPkAsRep(FALSE, tvb, offset, actx, tree, -1);
return offset;
}
static int
dissect_KerberosV5Spec2_KerberosTime(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) {
offset = dissect_krb5_ctime(tree, tvb, offset, actx);
return offset;
}
static int
dissect_KerberosV5Spec2_Checksum(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) {
offset = dissect_krb5_Checksum(tree, tvb, offset, actx);
return offset;
}
void proto_register_pkinit(void) {
static hf_register_info hf[] = {
#include "packet-pkinit-hfarr.c"
};
static gint *ett[] = {
#include "packet-pkinit-ettarr.c"
};
proto_pkinit = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkinit, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkinit(void) {
#include "packet-pkinit-dis-tab.c"
}
