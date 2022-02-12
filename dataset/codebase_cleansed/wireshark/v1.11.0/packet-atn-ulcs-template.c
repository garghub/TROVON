static int atn_ulcs_Externalt_encoding(
tvbuff_t *tvb _U_,
int offset _U_,
asn1_ctx_t *actx _U_,
proto_tree *tree _U_,
int hf_index _U_)
{
offset = dissect_per_choice(
tvb,
offset,
actx,
tree,
hf_index,
ett_atn_ulcs_EXTERNALt,
External_encoding_choice,
&actx->external.encoding);
return offset;
}
guint32 atn_per_external_type(
tvbuff_t *tvb _U_,
guint32 offset,
asn1_ctx_t *actx,
proto_tree *tree _U_,
int hf_index _U_,
per_type_fn type_cb)
{
memset(&actx->external, '\0', sizeof(actx->external));
actx->external.hf_index = -1;
actx->external.encoding = -1;
actx->external.u.per.type_cb = type_cb;
offset = atn_ulcs_Externalt_encoding(
tvb,
offset,
actx,
tree,
hf_index);
memset(
&actx->external,
'\0',
sizeof(actx->external));
actx->external.hf_index = -1;
actx->external.encoding = -1;
return offset;
}
guint32 get_aircraft_24_bit_address_from_nsap(
packet_info *pinfo)
{
guint8* addr = NULL;
guint32 ars =0;
guint32 adr_prefix =0;
if( (pinfo->src.type != AT_OSI) ||
(pinfo->dst.type != AT_OSI)) {
return ars; }
if( (pinfo->src.len != 20) ||
(pinfo->dst.len != 20)) {
return ars; }
addr = (guint8*) pinfo->src.data;
adr_prefix =
((addr[0]<<24) |
(addr[1]<<16) |
(addr[2]<<8) |
addr[3] );
if((adr_prefix == 0x470027c1) ||
(adr_prefix == 0x47002741)) {
ars = ((addr[8])<<16) |
((addr[9])<<8) |
(addr[10]);
}
addr = (guint8*) pinfo->dst.data;
adr_prefix = ((addr[0]<<24) |
(addr[1]<<16) |
(addr[2]<<8) |
addr[3] );
if((adr_prefix == 0x470027c1) ||
(adr_prefix == 0x47002741)) {
ars = ((addr[8])<<16) |
((addr[9])<<8) |
(addr[10]);
}
return ars;
}
int check_heur_msg_type(packet_info *pinfo _U_)
{
int t = no_msg;
guint8* addr = NULL;
guint32 adr_prefix =0;
if( (pinfo->src.type != AT_OSI) || (pinfo->dst.type != AT_OSI)) {
return t; }
if( (pinfo->src.len != 20) || (pinfo->dst.len != 20)) {
return t; }
addr = (guint8*) pinfo->src.data;
adr_prefix = ((addr[0]<<24) | (addr[1]<<16) | (addr[2]<<8) | addr[3] );
if((adr_prefix == 0x470027c1) || (adr_prefix == 0x47002741)) {
t = dm;
}
addr = (guint8*) pinfo->dst.data;
adr_prefix = ((addr[0]<<24) | (addr[1]<<16) | (addr[2]<<8) | addr[3] );
if((adr_prefix == 0x470027c1) || (adr_prefix == 0x47002741)) {
t = um;
}
return t;
}
wmem_tree_t *get_atn_conversation_tree(void){
return atn_conversation_tree;
}
atn_conversation_t * find_atn_conversation(
address *address1,
guint16 clnp_ref1,
address *address2 )
{
atn_conversation_t *cv = NULL;
guint32 key = 0;
guint32 tmp = 0;
ADD_ADDRESS_TO_HASH( tmp, address1);
key = (tmp << 16) | clnp_ref1 ;
ADD_ADDRESS_TO_HASH( tmp, address2);
key = (tmp << 24) | key ;
cv = (atn_conversation_t *)
wmem_tree_lookup32(get_atn_conversation_tree(),key);
return cv;
}
atn_conversation_t * create_atn_conversation(
address *address1,
guint16 clnp_ref1,
address *address2,
atn_conversation_t *conversation)
{
atn_conversation_t *cv = NULL;
guint32 key = 0;
guint32 tmp = 0;
ADD_ADDRESS_TO_HASH( tmp, address1);
key = (tmp << 16) | clnp_ref1 ;
ADD_ADDRESS_TO_HASH( tmp, address2);
key = (tmp << 24) | key ;
cv = (atn_conversation_t *)
wmem_tree_lookup32(
get_atn_conversation_tree(),
key);
if(cv) {
return NULL; }
wmem_tree_insert32(
get_atn_conversation_tree(),
key,
(void*)conversation);
return conversation;
}
static int
dissect_atn_ulcs(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
int offset = 0;
proto_item *ti = NULL;
proto_tree *atn_ulcs_tree = NULL;
guint8 value_pres = 0;
guint8 value_ses = 0;
guint16 value_ses_pres = 0;
root_tree = tree;
if ( (int)(intptr_t) data == FALSE )
{
ti = proto_tree_add_item(
tree,
proto_atn_ulcs,
tvb,
0,
0 ,
FALSE);
atn_ulcs_tree = proto_item_add_subtree(
ti,
ett_atn_ulcs);
dissect_Fully_encoded_data_PDU(
tvb,
pinfo,
atn_ulcs_tree);
return offset +
tvb_reported_length_remaining(tvb, offset ) ;
}
if ( (int)(intptr_t) data == TRUE )
{
value_ses_pres = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_text(
tree,
tvb,
offset,
0,
ATN_SES_PROTO );
atn_ulcs_tree = proto_item_add_subtree(
ti,
ett_atn_ses);
value_ses = tvb_get_guint8(tvb, offset);
proto_tree_add_item(atn_ulcs_tree,
hf_atn_ses_type,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
switch(value_ses & SES_PDU_TYPE_MASK){
case SES_ATN_SRF:
case SES_ATN_SRFC:
proto_tree_add_item(atn_ulcs_tree,
hf_atn_ses_param_ind,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
proto_tree_add_item(atn_ulcs_tree,
hf_atn_ses_param_b2,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
proto_tree_add_item(atn_ulcs_tree,
hf_atn_ses_param_b1,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
break;
default:
break;
}
offset++;
ti = proto_tree_add_text(
tree,
tvb,
offset,
0,
ATN_PRES_PROTO );
atn_ulcs_tree = proto_item_add_subtree(ti, ett_atn_pres);
value_pres = tvb_get_guint8(tvb, offset);
proto_tree_add_text(atn_ulcs_tree,
tvb,
offset,
1,
"%s (0x%02x)",
val_to_str( value_ses_pres & ATN_SES_PRES_MASK , atn_pres_vals, "?"),
value_pres);
switch(value_ses & SES_PDU_TYPE_MASK){
case SES_ATN_SRF:
case SES_ATN_SRFC:
proto_tree_add_item(
atn_ulcs_tree,
hf_atn_pres_err,
tvb,
offset,
1,
ENC_BIG_ENDIAN );
break;
default:
break;
}
offset++;
ti = proto_tree_add_text(
tree,
tvb,
offset,
0,
ATN_ACSE_PROTO );
atn_ulcs_tree = proto_item_add_subtree(
ti,
ett_atn_acse);
dissect_ACSE_apdu_PDU(
tvb_new_subset_remaining(tvb, offset),
pinfo,
atn_ulcs_tree);
return offset +
tvb_reported_length_remaining(tvb, offset );
}
return offset;
}
static gboolean dissect_atn_ulcs_heur(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
if (tvb_reported_length_remaining(tvb, 0) < 2){
return FALSE; }
switch( tvb_get_ntohs(tvb, 0) & 0xf8ff ){
case 0xe802:
case 0xf802:
case 0xf002:
case 0xd802:
case 0xe002:
case 0xe012:
case 0xe022:
case 0xe032:
case 0xe042:
case 0xe052:
case 0xe062:
case 0xe072:
case 0xa002:
case 0xa012:
case 0xa022:
case 0xa032:
case 0xa042:
case 0xa052:
case 0xa062:
case 0xa072:
dissect_atn_ulcs(
tvb,
pinfo,
tree,
(void*) TRUE);
return TRUE;
default:
break;
}
switch( tvb_get_ntohs(tvb, 0) & 0xfff0 ){
case 0x0020:
case 0x00a0:
dissect_atn_ulcs(tvb, pinfo, tree, (void*) FALSE);
return TRUE;
break;
default:
break;
}
return FALSE;
}
void proto_register_atn_ulcs (void)
{
static hf_register_info hf_atn_ulcs[] = {
#include "packet-atn-ulcs-hfarr.c"
{&hf_atn_ses_type,
{ "SPDU Type",
"atn-ulcs.ses.type",
FT_UINT8,
BASE_HEX,
VALS(atn_ses_type),
0xf8,
"Indicates presence of session parameters",
HFILL}},
{&hf_atn_ses_param_ind,
{ "SPDU Parameter Indication",
"atn-ulcs.ses.parameter-indication",
FT_UINT8,
BASE_HEX,
VALS(atn_ses_param_ind),
SES_PARAM_IND_MASK,
"Indicates presence of session parameters",
HFILL}},
{&hf_atn_ses_param_b1,
{ "SRF Parameter B1",
"atn-ulcs.ses.srf-b1",
FT_UINT8,
BASE_HEX,
VALS(srf_b1),
0x01,
"Determines if transport connection reject is \
transient or persistent",
HFILL}},
{&hf_atn_ses_param_b2,
{ "SRF Parameter B2",
"atn-ulcs.ses.srf-b2",
FT_UINT8,
BASE_HEX,
VALS(srf_b2),
0x02,
"Determines if transport connection is \
retained or released",
HFILL}},
{ &hf_atn_pres_err,
{ "Error Code", "atn-ulcs.pres.cpr-error",
FT_UINT8,
BASE_HEX,
VALS(atn_pres_err),
PRES_CPR_ER_MASK,
NULL,
HFILL}},
};
static gint *ett[] = {
#include "packet-atn-ulcs-ettarr.c"
&ett_atn_ses,
&ett_atn_pres,
&ett_atn_acse,
&ett_atn_ulcs
};
proto_atn_ulcs = proto_register_protocol (
ATN_ULCS_PROTO ,
"ATN-ULCS",
"atn-ulcs");
proto_register_field_array (
proto_atn_ulcs,
hf_atn_ulcs,
array_length(hf_atn_ulcs));
proto_register_subtree_array (
ett,
array_length (ett));
new_register_dissector(
"atn-ulcs",
dissect_atn_ulcs,
proto_atn_ulcs);
atn_cm_handle = find_dissector("atn-cm");
atn_cpdlc_handle = find_dissector("atn-cpdlc");
register_heur_dissector_list(
"atn-ulcs",
&atn_ulcs_heur_subdissector_list);
aarq_data_tree = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
atn_conversation_tree = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
void proto_reg_handoff_atn_ulcs(void)
{
heur_dissector_add(
"cotp",
dissect_atn_ulcs_heur,
proto_atn_ulcs);
}
