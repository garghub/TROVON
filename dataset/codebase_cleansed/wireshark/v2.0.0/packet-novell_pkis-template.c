void proto_reg_handoff_novell_pkis(void)
{
#include "packet-novell_pkis-dis-tab.c"
}
void proto_register_novell_pkis (void)
{
static hf_register_info hf[] = {
#include "packet-novell_pkis-hfarr.c"
};
static gint *ett[] = {
#include "packet-novell_pkis-ettarr.c"
};
if (proto_novell_pkis != -1) return;
proto_novell_pkis = proto_register_protocol("Novell PKIS ASN.1 type", "novell_pkis", "novell_pkis");
proto_register_field_array (proto_novell_pkis, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
