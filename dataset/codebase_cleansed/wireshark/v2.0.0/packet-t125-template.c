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
item = proto_tree_add_item(parent_tree, proto_t125, tvb, 0, tvb_captured_length(tvb), ENC_NA);
tree = proto_item_add_subtree(item, ett_t125);
get_ber_identifier(tvb, 0, &ber_class, &pc, &tag);
if ( (ber_class==BER_CLASS_APP) && (tag>=101) && (tag<=104) ){
dissect_ConnectMCSPDU_PDU(tvb, pinfo, tree, NULL);
} else {
t124_set_top_tree(top_tree);
dissect_DomainMCSPDU_PDU(tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_t125_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
gint8 ber_class;
gboolean pc;
gint32 tag;
volatile gboolean failed;
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
return FALSE;
}
void proto_register_t125(void) {
static hf_register_info hf[] = {
#include "packet-t125-hfarr.c"
};
static gint *ett[] = {
&ett_t125,
#include "packet-t125-ettarr.c"
};
proto_t125 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_t125, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
t125_heur_subdissector_list= register_heur_dissector_list("t125");
new_register_dissector("t125", dissect_t125, proto_t125);
}
void proto_reg_handoff_t125(void) {
heur_dissector_add("cotp", dissect_t125_heur, "T.125 over COTP", "t125_cotp", proto_t125, HEURISTIC_ENABLE);
heur_dissector_add("cotp_is", dissect_t125_heur, "T.125 over COTP (inactive subset)", "t125_cotp_is", proto_t125, HEURISTIC_ENABLE);
}
