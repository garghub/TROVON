static int
dissect_atn_cpdlc(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
proto_tree *atn_cpdlc_tree = NULL;
atn_conversation_t *atn_cv = NULL;
if((pinfo->clnp_dstref) && (!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src );
}
if((!pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if((pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if(!atn_cv){
return 0; }
atn_cpdlc_tree = proto_tree_add_subtree(
tree, tvb, 0, -1, ett_atn_cpdlc, NULL,
ATN_CPDLC_PROTO );
switch(atn_cv->ae_qualifier){
case pmcpdlc:
if( check_heur_msg_type(pinfo) == um ) {
dissect_ProtectedGroundPDUs_PDU(
tvb,
pinfo,
atn_cpdlc_tree, NULL);
}else {
dissect_ProtectedAircraftPDUs_PDU(
tvb,
pinfo,
atn_cpdlc_tree, NULL);
}
break;
case cpdlc:
if( check_heur_msg_type(pinfo) == um ) {
dissect_GroundPDUs_PDU(
tvb,
pinfo,
atn_cpdlc_tree, NULL);
}else {
dissect_AircraftPDUs_PDU(
tvb,
pinfo,
atn_cpdlc_tree, NULL);
}
break;
default:
break;
}
return tvb_reported_length_remaining(tvb, 0);
}
static gboolean
dissect_atn_cpdlc_heur(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
atn_conversation_t *atn_cv = NULL;
volatile gboolean is_atn_cpdlc = FALSE;
volatile gboolean is_pm = FALSE;
int type;
type = check_heur_msg_type(pinfo);
switch(type){
case um:
TRY {
dissect_ProtectedGroundPDUs_PDU(tvb, pinfo, NULL, NULL);
is_atn_cpdlc = TRUE;
is_pm = TRUE;}
CATCH_ALL{
is_atn_cpdlc = FALSE;
is_pm = FALSE;}
ENDTRY;
if (is_atn_cpdlc) {
break;
}
TRY {
dissect_GroundPDUs_PDU(tvb, pinfo, NULL, NULL);
is_pm = FALSE;
is_atn_cpdlc = TRUE;}
CATCH_ALL{
is_atn_cpdlc = FALSE;
is_pm = FALSE;}
ENDTRY;
break;
case dm:
TRY {
dissect_ProtectedAircraftPDUs_PDU(tvb, pinfo, NULL, NULL);
is_atn_cpdlc = TRUE;
is_pm = TRUE;}
CATCH_ALL {
is_atn_cpdlc = FALSE;
is_pm = FALSE; }
ENDTRY;
if (is_atn_cpdlc) {
break;
}
TRY{
dissect_AircraftPDUs_PDU(tvb, pinfo, NULL, NULL);
is_atn_cpdlc = TRUE;
is_pm = FALSE;}
CATCH_ALL{
is_atn_cpdlc = FALSE;
is_pm = FALSE;}
ENDTRY;
break;
default:
break;
}
if(is_atn_cpdlc){
if((pinfo->clnp_dstref) && (!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src );
}
if((!pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if((pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if(atn_cv){
if(is_pm == TRUE) {
atn_cv->ae_qualifier = pmcpdlc; }
else {
atn_cv->ae_qualifier = cpdlc; }
dissect_atn_cpdlc(tvb, pinfo, tree, NULL);
}
}else {
is_atn_cpdlc = FALSE;
}
return is_atn_cpdlc;
}
void proto_register_atn_cpdlc (void)
{
static hf_register_info hf_atn_cpdlc[] = {
#include "packet-atn-cpdlc-hfarr.c"
};
static gint *ett[] = {
#include "packet-atn-cpdlc-ettarr.c"
&ett_atn_cpdlc
};
proto_atn_cpdlc = proto_register_protocol(
ATN_CPDLC_PROTO ,
"ATN-CPDLC",
"atn-cpdlc");
proto_register_field_array(
proto_atn_cpdlc,
hf_atn_cpdlc,
array_length(hf_atn_cpdlc));
proto_register_subtree_array(
ett,
array_length(ett));
new_register_dissector(
"atn-cpdlc",
dissect_atn_cpdlc,
proto_atn_cpdlc);
}
void proto_reg_handoff_atn_cpdlc(void)
{
heur_dissector_add(
"atn-ulcs",
dissect_atn_cpdlc_heur,
"ATN-CPDLC over ATN-ULCS",
"atn-cpdlc-ulcs",
proto_atn_cpdlc, HEURISTIC_ENABLE);
}
