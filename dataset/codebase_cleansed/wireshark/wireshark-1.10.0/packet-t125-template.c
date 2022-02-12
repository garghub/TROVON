static int
dissect_t125(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gint8 ber_class;
gboolean pc;
gint32 tag;
top_tree = parent_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "T.125");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_t125, tvb, 0, tvb_length(tvb), ENC_NA);
tree = proto_item_add_subtree(item, ett_t125);
get_ber_identifier(tvb, 0, &ber_class, &pc, &tag);
if ( (ber_class==BER_CLASS_APP) && (tag>=101) && (tag<=104) ){
dissect_ConnectMCSPDU_PDU(tvb, pinfo, tree, NULL);
} else {
t124_set_top_tree(top_tree);
dissect_DomainMCSPDU_PDU(tvb, pinfo, tree);
}
return tvb_length(tvb);
}
static gboolean
dissect_t125_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 choice_index = 100;
asn1_ctx_t asn1_ctx;
gboolean failed;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
failed = FALSE;
TRY {
get_ber_identifier(tvb, 0, &ber_class, &pc, &tag);
} CATCH_BOUNDS_ERRORS {
failed = TRUE;
} ENDTRY;
if (!failed && ((ber_class==BER_CLASS_APP) && ((tag>=101) && (tag<=104)))) {
dissect_t125(tvb, pinfo, parent_tree, NULL);
return TRUE;
}
failed = FALSE;
TRY {
dissect_per_constrained_integer(tvb, 0, &asn1_ctx,
NULL, hf_t125_heur, 0, 42,
&choice_index, FALSE);
} CATCH_BOUNDS_ERRORS {
failed = TRUE;
} ENDTRY;
if (!failed && (choice_index <=42)) {
dissect_t125(tvb, pinfo, parent_tree, NULL);
return TRUE;
}
return FALSE;
}
void proto_register_t125(void) {
static hf_register_info hf[] = {
{ &hf_t125_connectData,
{ "connectData", "t125.connectData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t125_heur,
{ "heuristic", "t125.heuristic",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
#include "packet-t125-hfarr.c"
};
static gint *ett[] = {
&ett_t125,
#include "packet-t125-ettarr.c"
};
proto_t125 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_t125, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_heur_dissector_list("t125", &t125_heur_subdissector_list);
new_register_dissector("t125", dissect_t125, proto_t125);
}
void proto_reg_handoff_t125(void) {
heur_dissector_add("cotp", dissect_t125_heur, proto_t125);
heur_dissector_add("cotp_is", dissect_t125_heur, proto_t125);
}
