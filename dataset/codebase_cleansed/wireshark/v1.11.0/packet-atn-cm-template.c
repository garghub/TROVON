static int
dissect_atn_cm(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
int type = no_msg;
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
ti = proto_tree_add_text(
tree,
tvb,
0,
tvb_reported_length_remaining(tvb, 0) ,
ATN_CM_PROTO);
sub_tree = proto_item_add_subtree(
ti,
ett_atn_cm);
type = check_heur_msg_type(pinfo);
switch(type){
case um:
dissect_CMGroundMessage_PDU(
tvb,
pinfo,
sub_tree);
break;
case dm:
dissect_CMAircraftMessage_PDU(
tvb,
pinfo,
sub_tree);
break;
default:
break;
}
return tvb_reported_length_remaining(tvb, 0);
}
static gboolean
dissect_atn_cm_heur(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
atn_conversation_t *atn_cv = NULL;
gboolean is_atn_cm = FALSE;
int type;
type = check_heur_msg_type(pinfo);
switch(type){
case um:
TRY {
dissect_CMGroundMessage_PDU(
tvb,
pinfo,
NULL);
is_atn_cm = TRUE; }
CATCH_ALL {
is_atn_cm = FALSE; }
ENDTRY;
break;
case dm:
TRY {
dissect_CMAircraftMessage_PDU(
tvb,
pinfo,
NULL);
is_atn_cm = TRUE;}
CATCH_ALL {
is_atn_cm = FALSE; }
ENDTRY;
break;
default:
break;
}
if (is_atn_cm == TRUE) {
if((pinfo->clnp_dstref) &&
(!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src );
}
if((!pinfo->clnp_dstref) &&
(pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if((pinfo->clnp_dstref) &&
(pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if(atn_cv){
atn_cv->ae_qualifier = cma;
}
dissect_atn_cm(
tvb,
pinfo,
tree,
NULL);
}
return is_atn_cm;
}
void proto_register_atn_cm (void)
{
static hf_register_info hf_atn_cm[] = {
#include "packet-atn-cm-hfarr.c"
};
static gint *ett[] = {
#include "packet-atn-cm-ettarr.c"
&ett_atn_cm
};
proto_atn_cm = proto_register_protocol(
ATN_CM_PROTO ,
"ATN-CM",
"atn-cm");
proto_register_field_array(
proto_atn_cm,
hf_atn_cm,
array_length(hf_atn_cm));
proto_register_subtree_array(
ett,
array_length(ett));
new_register_dissector(
"atn-cm",
dissect_atn_cm,
proto_atn_cm);
}
void proto_reg_handoff_atn_cm(void)
{
heur_dissector_add(
"atn-ulcs",
dissect_atn_cm_heur,
proto_atn_cm);
}
