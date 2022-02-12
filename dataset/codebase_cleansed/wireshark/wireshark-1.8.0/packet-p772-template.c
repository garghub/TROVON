static void
dissect_p772(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_p772, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_p772);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "P772");
col_set_str(pinfo->cinfo, COL_INFO, "Military");
dissect_p772_InformationObject(TRUE, tvb, offset, &asn1_ctx , tree, -1);
}
void proto_register_p772(void) {
static hf_register_info hf[] =
{
#include "packet-p772-hfarr.c"
};
static gint *ett[] = {
&ett_p772,
#include "packet-p772-ettarr.c"
};
proto_p772 = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("p772", dissect_p772, proto_p772);
proto_register_field_array(proto_p772, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_ber_syntax_dissector("STANAG 4406", proto_p772, dissect_p772);
register_ber_oid_syntax(".p772", NULL, "STANAG 4406");
}
void proto_reg_handoff_p772(void) {
#include "packet-p772-dis-tab.c"
register_ber_oid_dissector("1.3.26.0.4406.0.4.1", dissect_p772, proto_p772, "STANAG 4406");
}
