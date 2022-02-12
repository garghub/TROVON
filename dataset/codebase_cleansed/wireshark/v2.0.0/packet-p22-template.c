static void
dissect_p22(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_p22, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_p22);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "P22");
col_set_str(pinfo->cinfo, COL_INFO, "InterPersonal");
dissect_p22_InformationObject(TRUE, tvb, offset, &asn1_ctx , tree, -1);
}
void proto_register_p22(void) {
static hf_register_info hf[] =
{
#include "packet-p22-hfarr.c"
};
static gint *ett[] = {
&ett_p22,
#include "packet-p22-ettarr.c"
};
proto_p22 = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("p22", dissect_p22, proto_p22);
proto_register_field_array(proto_p22, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_p22(void) {
#include "packet-p22-dis-tab.c"
register_ber_oid_dissector("2.6.1.10.0", dissect_p22, proto_p22, "InterPersonal Message (1984)");
register_ber_oid_dissector("2.6.1.10.1", dissect_p22, proto_p22, "InterPersonal Message (1988)");
}
