static void get_CP56Time( td_CP56Time *cp56t, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
guint16 ms;
ms = tvb_get_letohs( tvb , *offset );
(*offset) += 2;
cp56t->cp56t_s = ms / 1000;
cp56t->cp56t_ms = ms % 1000;
cp56t->cp56t_min = tvb_get_guint8(tvb, *offset);
cp56t->IV = cp56t->cp56t_min & 0x80;
cp56t->cp56t_min = cp56t->cp56t_min & 0x3F;
(*offset)++;
cp56t->cp56t_h = 0x1F & tvb_get_guint8(tvb, *offset);
(*offset)++;
cp56t->cp56t_dom = tvb_get_guint8(tvb, *offset);
cp56t->cp56t_dow = 0xE0 & cp56t->cp56t_dom;
cp56t->cp56t_dow >>= 5;
cp56t->cp56t_dom = cp56t->cp56t_dom & 0x1F;
(*offset)++;
cp56t->cp56t_month = 0x0F & tvb_get_guint8(tvb, *offset);
(*offset)++;
cp56t->cp56t_year = 0x7F & tvb_get_guint8(tvb, *offset);
(*offset)++;
if( iec104_header_tree != NULL )
{
proto_tree_add_text(iec104_header_tree, tvb, (*offset)-7, 7,
"%.2d-%.2d-%.2d (%d) %.2d:%.2d:%.2d.%.3d (%s)",
cp56t->cp56t_year,cp56t->cp56t_month,cp56t->cp56t_dom,
cp56t->cp56t_dow,cp56t->cp56t_h,cp56t->cp56t_min,
cp56t->cp56t_s,cp56t->cp56t_ms,cp56t->IV?"Invalid":"Valid");
}
}
static void get_InfoObjectAddress( guint32 *asdu_info_obj_addr, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
*asdu_info_obj_addr = tvb_get_letoh24(tvb, *offset);
if( iec104_header_tree != NULL )
{
proto_tree_add_uint(iec104_header_tree, hf_ioa,
tvb, *offset, 3, *asdu_info_obj_addr);
}
(*offset) += 3;
}
static void get_SIQ( td_ValueInfo *value, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
guint8 siq;
siq = tvb_get_guint8(tvb, *offset);
value->ON = siq & 0x01;
value->OFF = !(value->ON);
value->BL = siq & 0x10;
value->SB = siq & 0x20;
value->NT = siq & 0x40;
value->IV = siq & 0x80;
if( iec104_header_tree != NULL )
{
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Value: %s - Status: %s, %s, %s, %s",
value->ON?"ON":"OFF", value->BL?"Blocked":"Not blocked",
value->SB?"Substituted":"Not Substituted", value->NT?"Not Topical":"Topical",
value->IV?"Invalid":"Valid" );
}
(*offset)++;
}
static void get_DIQ( td_ValueInfo *value, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
guint8 diq;
diq = tvb_get_guint8(tvb, *offset);
value->IPOS0 = FALSE;
value->OFF = FALSE;
value->ON = FALSE;
value->IPOS3 = FALSE;
switch ( diq & 0x03 )
{
case 0:
value->IPOS0 = TRUE;
break;
case 1:
value->OFF = TRUE;
break;
case 2:
value->ON = TRUE;
break;
case 3:
value->IPOS3 = TRUE;
break;
default:
break;
}
value->BL = diq & 0x10;
value->SB = diq & 0x20;
value->NT = diq & 0x40;
value->IV = diq & 0x80;
if( iec104_header_tree != NULL )
{
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Value: %s%s%s%s - Status: %s, %s, %s, %s",
value->ON?"ON":"", value->OFF?"OFF":"", value->IPOS0?"IPOS0":"", value->IPOS3?"IPOS3":"",
value->BL?"Blocked":"Not blocked", value->SB?"Substituted":"Not Substituted",
value->NT?"Not Topical":"Topical", value->IV?"Invalid":"Valid" );
}
(*offset)++;
}
static void get_QDS( td_ValueInfo *value, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
guint8 qds;
qds = tvb_get_guint8(tvb, *offset);
value->OV = qds & 0x01;
value->BL = qds & 0x10;
value->SB = qds & 0x20;
value->NT = qds & 0x40;
value->IV = qds & 0x80;
if( iec104_header_tree != NULL )
{
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Status: %s, %s, %s, %s, %s",
value->OV?"Overflow!":"No Overflow", value->BL?"Blocked!":"Not Blocked",
value->SB?"Substituted!":"Not Substituted", value->NT?"Not Topical!":"Topical",
value->IV?"Invalid!":"Valid" );
}
(*offset)++;
}
static void get_VTI( td_ValueInfo *value _U_, tvbuff_t *tvb _U_, guint8 *offset _U_, proto_tree *iec104_header_tree _U_ )
{
guint8 vti;
vti = tvb_get_guint8(tvb, *offset);
value->MV.VTI= vti & 0x7F;
value->TRANSIENT = (vti & 0x80) != 0;
if( iec104_header_tree != NULL )
{
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Value: %d - Status: %s",
value->MV.VTI, value->TRANSIENT?"Transient":"Not transient" );
}
(*offset)++;
}
static void get_NVA( td_ValueInfo *value, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
value->MV.NVA = tvb_get_letohs(tvb, *offset);
if ( iec104_header_tree != NULL )
{
proto_tree_add_int(iec104_header_tree, hf_asdu_normval,
tvb, *offset, 2, value->MV.NVA);
}
(*offset) += 2;
}
static void get_NVAspt( td_SpInfo *spt, tvbuff_t *tvb, guint8 *offset,
proto_tree *iec104_header_tree )
{
spt->SP.NVA = tvb_get_letohs(tvb, *offset);
if ( iec104_header_tree != NULL )
{
proto_tree_add_int(iec104_header_tree, hf_asdu_normval,
tvb, *offset, 2, spt->SP.NVA);
}
(*offset) += 2;
}
static void get_SVA( td_ValueInfo *value, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
value->MV.SVA = tvb_get_letohs(tvb, *offset);
if ( iec104_header_tree != NULL )
{
proto_tree_add_int(iec104_header_tree, hf_asdu_normval,
tvb, *offset, 2, value->MV.SVA);
}
(*offset) += 2;
}
static void get_SVAspt( td_SpInfo *spt, tvbuff_t *tvb, guint8 *offset,
proto_tree *iec104_header_tree )
{
spt->SP.SVA = tvb_get_letohs(tvb, *offset);
if ( iec104_header_tree != NULL )
{
proto_tree_add_int(iec104_header_tree, hf_asdu_normval,
tvb, *offset, 2, spt->SP.SVA);
}
(*offset) += 2;
}
static void get_FLT( td_ValueInfo *value, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
value->MV.FLT = tvb_get_letohieee_float(tvb, *offset);
if ( iec104_header_tree != NULL )
{
proto_tree_add_float(iec104_header_tree, hf_asdu_float,
tvb, *offset, 4, value->MV.FLT);
}
(*offset) += 4;
}
static void get_FLTspt( td_SpInfo *spt, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
spt->SP.FLT = tvb_get_letohieee_float(tvb, *offset);
if ( iec104_header_tree != NULL )
{
proto_tree_add_float(iec104_header_tree, hf_asdu_float,
tvb, *offset, 4, spt->SP.FLT);
}
(*offset) += 4;
}
static void get_BSI( td_ValueInfo *value _U_, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
if ( iec104_header_tree != NULL )
{
proto_tree_add_bits_item(iec104_header_tree, hf_asdu_bitstring,
tvb, *offset*8, 32, ENC_BIG_ENDIAN);
}
(*offset) += 4;
}
static void get_BSIspt( td_ValueInfo *value _U_, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
if ( iec104_header_tree != NULL )
{
proto_tree_add_bits_item(iec104_header_tree, hf_asdu_bitstring,
tvb, *offset*8, 32, ENC_BIG_ENDIAN);
}
(*offset) += 4;
}
static void get_QOC( td_CmdInfo *value, guint8 data )
{
value->ZeroP = FALSE;
value->ShortP = FALSE;
value->LongP = FALSE;
value->Persist = FALSE;
value->QU = data & 0x7c;
value->QU >>= 2;
switch( value->QU )
{
case 0x00:
value->ZeroP = TRUE;
break;
case 0x01:
value->ShortP = TRUE;
break;
case 0x02:
value->LongP = TRUE;
break;
case 0x03:
value->Persist = TRUE;
break;
default:
;
break;
}
value->SE = data & 0x80;
}
static void get_QOS( td_SpInfo *spt, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
guint8 qos;
qos = tvb_get_guint8(tvb, *offset);
spt->QL = qos & 0x7F;
spt->SE = qos & 0x80;
if( iec104_header_tree != NULL )
{
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Qualifier - QL: %d, S/E: %s",
spt->QL, spt->SE?"Select":"Execute" );
}
(*offset)++;
}
static void get_SCO( td_CmdInfo *value, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
guint8 data;
data = tvb_get_guint8(tvb, *offset);
value->ON = data & 0x01;
value->OFF = !(value->ON);
get_QOC( value, data );
if( iec104_header_tree != NULL )
{
if ( value->QU < 4 )
{
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Command: %s%s, Qualifier: %s%s%s%s, %s",
value->ON?"ON":"", value->OFF?"OFF":"",
value->ZeroP?"No pulse defined":"", value->ShortP?"Short Pulse":"",
value->LongP?"Long Pulse":"", value->Persist?"Persistent Output":"",
value->SE?"Select":"Execute");
} else {
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Command: %s%s, Qualifier: QU=%d, %s",
value->ON?"ON":"", value->OFF?"OFF":"",
value->QU,
value->SE?"Select":"Execute");
}
}
(*offset)++;
}
static void get_DCO( td_CmdInfo *value, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
guint8 data;
data = tvb_get_guint8(tvb, *offset);
value->OFF = FALSE;
value->ON = FALSE;
switch ( data & 0x03 )
{
case 1:
value->OFF = TRUE;
break;
case 2:
value->ON = TRUE;
break;
default:
;
break;
}
get_QOC( value, data );
if( iec104_header_tree != NULL )
{
if ( value->QU < 4 )
{
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Command: %s%s%s, Qualifier: %s%s%s%s, %s",
value->ON?"ON":"", value->OFF?"OFF":"", (value->ON | value->OFF)?"":"Error: On/Off not defined",
value->ZeroP?"No pulse defined":"", value->ShortP?"Short Pulse":"",
value->LongP?"Long Pulse":"", value->Persist?"Persistent Output":"",
value->SE?"Select":"Execute");
} else {
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Command: %s%s%s, Qualifier: QU=%d, %s",
value->ON?"ON":"", value->OFF?"OFF":"", (value->ON | value->OFF)?"":"Error: On/Off not defined",
value->QU,
value->SE?"Select":"Execute");
}
}
(*offset)++;
}
static void get_RCO( td_CmdInfo *value, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
guint8 data;
data = tvb_get_guint8(tvb, *offset);
value->UP = FALSE;
value->DOWN = FALSE;
switch ( data & 0x03 )
{
case 1:
value->DOWN = TRUE;
break;
case 2:
value->UP = TRUE;
break;
default:
;
break;
}
get_QOC( value, data );
if( iec104_header_tree != NULL )
{
if ( value->QU < 4 )
{
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Command: %s%s%s, Qualifier: %s%s%s%s, %s",
value->UP?"UP":"", value->DOWN?"DOWN":"", (value->UP | value->DOWN)?"":"Error: On/Off not defined",
value->ZeroP?"No pulse defined":"", value->ShortP?"Short Pulse":"",
value->LongP?"Long Pulse":"", value->Persist?"Persistent Output":"",
value->SE?"Select":"Execute");
} else {
proto_tree_add_text( iec104_header_tree, tvb, *offset, 1, "Command: %s%s%s, Qualifier: QU=%d, %s",
value->UP?"UP":"", value->DOWN?"DOWN":"", (value->UP | value->DOWN)?"":"Error: On/Off not defined",
value->QU,
value->SE?"Select":"Execute");
}
}
(*offset)++;
}
static guint get_iec104apdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint8 Val;
guint32 Off;
for (Off= 0; Off <= tvb_length(tvb)- 2; Off++) {
Val = tvb_get_guint8(tvb, offset+ Off);
if (Val == APCI_START) {
return (guint)(Off+ tvb_get_guint8(tvb, offset+ Off+ 1)+ 2);
}
}
return (guint)(tvb_length(tvb));
}
static void dissect_iec104asdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint Len = tvb_reported_length(tvb);
guint8 Bytex = 0;
const char *cause_str;
size_t Ind = 0;
struct asduheader * asduh;
emem_strbuf_t * res;
proto_item * it104 = NULL;
proto_tree * trHead;
guint8 offset = 0;
guint8 offset_start_ioa = 0;
guint8 i;
guint32 asdu_info_obj_addr = 0;
proto_item * itSignal = NULL;
proto_tree * trSignal;
td_ValueInfo value;
td_CmdInfo cmd;
td_SpInfo spt;
td_CP56Time cp56t;
if (!(check_col(pinfo->cinfo, COL_INFO) || tree)) return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "104asdu");
col_clear(pinfo->cinfo, COL_INFO);
asduh = ep_alloc(sizeof(struct asduheader));
res = ep_strbuf_new_label(NULL);
if (Len >= ASDU_HEAD_LEN) {
asduh->AddrLow = tvb_get_guint8(tvb, 4);
asduh->AddrHigh = tvb_get_guint8(tvb, 5);
asduh->OA = tvb_get_guint8(tvb, 3);
asduh->TypeId = tvb_get_guint8(tvb, 0);
asduh->TNCause = tvb_get_guint8(tvb, 2);
asduh->IOA = tvb_get_letoh24(tvb, 6);
Bytex = tvb_get_guint8(tvb, 1);
asduh->NumIx = Bytex & 0x7F;
asduh->SQ = Bytex & F_SQ;
ep_strbuf_printf(res, "%u,%u%s%u ", asduh->AddrLow, asduh->AddrHigh, pinfo->srcport == iec104port ? "->" : "<-", asduh->OA);
ep_strbuf_append(res, val_to_str(asduh->TypeId, asdu_types, "<TypeId=%u>"));
ep_strbuf_append_c(res, ' ');
cause_str = val_to_str(asduh->TNCause & F_CAUSE, causetx_types, " <CauseTx=%u>");
ep_strbuf_append(res, cause_str);
if (asduh->TNCause & F_NEGA) ep_strbuf_append(res, "_NEGA");
if (asduh->TNCause & F_TEST) ep_strbuf_append(res, "_TEST");
if (asduh->TNCause & (F_TEST | F_NEGA)) {
for (Ind=strlen(cause_str); Ind< 7; Ind++) ep_strbuf_append_c(res, ' ');
}
ep_strbuf_append_printf(res, " IOA=%d", asduh->IOA);
if (asduh->NumIx > 1) {
if (asduh->SQ == F_SQ) ep_strbuf_append_printf(res, "-%d", asduh->IOA + asduh->NumIx - 1);
else ep_strbuf_append(res, ",...");
ep_strbuf_append_printf(res, " (%u)", asduh->NumIx);
}
}
else {
ep_strbuf_printf(res, "<ERR Short Asdu, Len=%u>", Len);
}
ep_strbuf_append_c(res, ' ');
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO, res->str);
col_set_fence(pinfo->cinfo, COL_INFO);
}
if(!tree) return;
it104 = proto_tree_add_item(tree, proto_iec104asdu, tvb, 0, -1, ENC_NA);
proto_item_append_text(it104, ": %s'%s'", res->str, Len >= ASDU_HEAD_LEN ? val_to_str(asduh->TypeId, asdu_lngtypes, "<Unknown TypeId>") : "");
if (Len < ASDU_HEAD_LEN) return;
trHead = proto_item_add_subtree(it104, ett_asdu);
proto_tree_add_uint(trHead, hf_typeid, tvb, 0, 1, asduh->TypeId);
proto_tree_add_uint(trHead, hf_numix, tvb, 1, 1, asduh->NumIx);
proto_tree_add_uint(trHead, hf_causetx, tvb, 2, 1, asduh->TNCause & F_CAUSE);
proto_tree_add_boolean(trHead, hf_nega, tvb, 2, 1, asduh->TNCause);
proto_tree_add_boolean(trHead, hf_test, tvb, 2, 1, asduh->TNCause);
proto_tree_add_uint(trHead, hf_oa, tvb, 3, 1, asduh->OA);
proto_tree_add_uint(trHead, hf_addr, tvb, 4, 2, asduh->AddrLow+ 256* asduh->AddrHigh);
proto_tree_add_uint(trHead, hf_ioa, tvb, 6, 3, asduh->IOA);
if (asduh->NumIx > 1) proto_tree_add_boolean(trHead, hf_sq, tvb, 1, 1, asduh->SQ);
offset = 6;
switch (asduh->TypeId) {
case M_SP_NA_1:
case M_DP_NA_1:
case M_ST_NA_1:
case M_BO_NA_1:
case M_SP_TB_1:
case M_DP_TB_1:
case M_ST_TB_1:
case M_BO_TB_1:
case M_ME_NA_1:
case M_ME_NB_1:
case M_ME_NC_1:
case M_ME_ND_1:
case M_ME_TD_1:
case M_ME_TE_1:
case M_ME_TF_1:
case C_SC_NA_1:
case C_DC_NA_1:
case C_RC_NA_1:
case C_SE_NA_1:
case C_SE_NB_1:
case C_SE_NC_1:
case C_BO_NA_1:
case C_SC_TA_1:
case C_DC_TA_1:
case C_RC_TA_1:
case C_SE_TA_1:
case C_SE_TB_1:
case C_SE_TC_1:
case C_BO_TA_1:
case C_CS_NA_1:
itSignal = proto_tree_add_item( trHead, proto_iec104asdu, tvb, offset, -1, ENC_NA );
proto_item_append_text(itSignal, ": Value");
trSignal = proto_item_add_subtree( itSignal, ett_asdu );
for(i = 0; i < asduh->NumIx; i++)
{
if (!i)
{
offset_start_ioa = offset;
asdu_info_obj_addr = asduh->IOA;
proto_tree_add_uint(trSignal, hf_ioa,
tvb, offset_start_ioa, 3, asdu_info_obj_addr);
if( Len < (guint)(offset+3) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
offset += 3;
} else {
if (asduh->SQ)
{
asdu_info_obj_addr++;
proto_tree_add_uint(trSignal, hf_ioa,
tvb, offset_start_ioa, 3, asdu_info_obj_addr);
} else {
if( Len < (guint)(offset+3) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_InfoObjectAddress( &asdu_info_obj_addr, tvb, &offset,
trSignal);
}
}
switch (asduh->TypeId) {
case M_SP_NA_1:
if( Len < (guint)(offset+1) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_SIQ( &value, tvb, &offset, trSignal );
break;
case M_DP_NA_1:
if( Len < (guint)(offset+1) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_DIQ( &value, tvb, &offset, trSignal );
break;
case M_ST_NA_1:
if( Len < (guint)(offset+2) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_VTI( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
break;
case M_BO_NA_1:
if( Len < (guint)(offset+5) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_BSI( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
break;
case M_ME_NA_1:
if( Len < (guint)(offset+3) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_NVA( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
break;
case M_ME_NB_1:
if( Len < (guint)(offset+3) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_SVA( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
break;
case M_ME_NC_1:
if( Len < (guint)(offset+5) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_FLT( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
break;
case M_ME_ND_1:
if( Len < (guint)(offset+2) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_NVA( &value, tvb, &offset, trSignal );
break;
case M_SP_TB_1:
if( Len < (guint)(offset+8) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_SIQ( &value, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case M_DP_TB_1:
if( Len < (guint)(offset+8) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_DIQ( &value, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case M_ST_TB_1:
if( Len < (guint)(offset+9) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_VTI( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case M_BO_TB_1:
if( Len < (guint)(offset+12) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_BSI( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case M_ME_TD_1:
if( Len < (guint)(offset+10) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_NVA( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case M_ME_TE_1:
if( Len < (guint)(offset+10) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_SVA( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case M_ME_TF_1:
if( Len < (guint)(offset+12) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_FLT( &value, tvb, &offset, trSignal );
get_QDS( &value, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case C_SC_NA_1:
if( Len < (guint)(offset+1) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_SCO( &cmd, tvb, &offset, trSignal );
break;
case C_DC_NA_1:
if( Len < (guint)(offset+1) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_DCO( &cmd, tvb, &offset, trSignal );
break;
case C_RC_NA_1:
if( Len < (guint)(offset+1) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_RCO( &cmd, tvb, &offset, trSignal );
break;
case C_SE_NA_1:
if( Len < (guint)(offset+3) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_NVAspt( &spt, tvb, &offset, trSignal );
get_QOS( &spt, tvb, &offset, trSignal );
break;
case C_SE_NB_1:
if( Len < (guint)(offset+3) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_SVAspt( &spt, tvb, &offset, trSignal );
get_QOS( &spt, tvb, &offset, trSignal );
break;
case C_SE_NC_1:
if( Len < (guint)(offset+5) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_FLTspt( &spt, tvb, &offset, trSignal );
get_QOS( &spt, tvb, &offset, trSignal );
break;
case C_BO_NA_1:
if( Len < (guint)(offset+4) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_BSIspt( &value, tvb, &offset, trSignal );
break;
case C_SC_TA_1:
if( Len < (guint)(offset+8) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_SCO( &cmd, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case C_DC_TA_1:
if( Len < (guint)(offset+8) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_DCO( &cmd, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case C_RC_TA_1:
if( Len < (guint)(offset+8) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_RCO( &cmd, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case C_SE_TA_1:
if( Len < (guint)(offset+10) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_NVAspt( &spt, tvb, &offset, trSignal );
get_QOS( &spt, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case C_SE_TB_1:
if( Len < (guint)(offset+10) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_SVAspt( &spt, tvb, &offset, trSignal );
get_QOS( &spt, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case C_SE_TC_1:
if( Len < (guint)(offset+12) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_FLTspt( &spt, tvb, &offset, trSignal );
get_QOS( &spt, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case C_BO_TA_1:
if( Len < (guint)(offset+11) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_BSIspt( &value, tvb, &offset, trSignal );
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
case C_CS_NA_1:
if( Len < (guint)(offset+7) ) {
proto_tree_add_text( trSignal, tvb, offset, 1, "<ERR Short Asdu>" );
return;
}
get_CP56Time( &cp56t, tvb, &offset, trSignal );
break;
default:
break;
}
}
break;
default:
break;
}
}
static void dissect_iec104apci(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint TcpLen = tvb_length(tvb);
guint Brossa = 0;
guint8 Start;
guint Off;
guint8 Byte1 = 0;
struct apciheader * apcih;
emem_strbuf_t * res;
proto_item * it104 = NULL;
proto_tree * trHead;
if (!(check_col(pinfo->cinfo, COL_INFO) || tree)) return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "104apci");
col_clear(pinfo->cinfo, COL_INFO);
apcih = ep_alloc(sizeof(struct apciheader));
Start = 0;
for (Off= 0; Off <= TcpLen- 2; Off++) {
Start = tvb_get_guint8(tvb, Off);
if (Start == APCI_START) {
Brossa = Off;
apcih->ApduLen = tvb_get_guint8(tvb, Off+ 1);
if (apcih->ApduLen >= APDU_MIN_LEN) {
Byte1 = tvb_get_guint8(tvb, Off+ 2);
apcih->Type = Byte1 & 0x03;
if (apcih->Type == 2) apcih->Type = 0;
switch(apcih->Type) {
case I_TYPE:
apcih->Tx = tvb_get_letohs(tvb, Off+ 2) >> 1;
case S_TYPE:
apcih->Rx = tvb_get_letohs(tvb, Off+ 4) >> 1;
break;
case U_TYPE:
apcih->UType = (Byte1 & 0xFC);
break;
}
}
else {
Brossa = TcpLen;
}
break;
}
}
if (Start != APCI_START) {
Brossa = TcpLen;
}
res = ep_strbuf_new_label(NULL);
if (Brossa > 0)
ep_strbuf_append_printf(res, "<ERR %u bytes> ", Brossa);
if (Brossa != TcpLen) {
if (apcih->ApduLen <= APDU_MAX_LEN) {
ep_strbuf_append_printf(res, "%s%s(", pinfo->srcport == iec104port ? "->" : "<-", val_to_str(apcih->Type, apci_types, "<ERR>"));
switch(apcih->Type) {
case I_TYPE:
ep_strbuf_append_printf(res, "%d,", apcih->Tx);
case S_TYPE:
ep_strbuf_append_printf(res, "%d)", apcih->Rx);
if (apcih->Tx < 10)
ep_strbuf_append_c(res, ' ');
if (apcih->Rx < 10)
ep_strbuf_append_c(res, ' ');
break;
case U_TYPE:
ep_strbuf_append_printf(res, "%s)", val_to_str(apcih->UType >> 2, u_types, "<ERR>"));
break;
}
if (apcih->Type != I_TYPE && apcih->ApduLen > APDU_MIN_LEN) ep_strbuf_append_printf(res, "<ERR %u bytes> ", apcih->ApduLen- APDU_MIN_LEN);
}
else {
ep_strbuf_append_printf(res, "<ERR ApduLen=%u bytes> ", apcih->ApduLen);
}
}
ep_strbuf_append_c(res, ' ');
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO, res->str);
if(apcih->Type == I_TYPE && Brossa != TcpLen) {
call_dissector(iec104asdu_handle, tvb_new_subset(tvb, Off+ APCI_LEN, -1, apcih->ApduLen- APCI_DATA_LEN), pinfo, tree);
} else {
col_set_fence(pinfo->cinfo, COL_INFO);
}
}
if(!tree) return;
it104 = proto_tree_add_item(tree, proto_iec104apci, tvb, 0, Off+ APCI_LEN, ENC_NA);
proto_item_append_text(it104, ": %s", res->str);
if(Brossa == TcpLen) return;
if(apcih->Type == I_TYPE && (!check_col(pinfo->cinfo, COL_INFO))){
call_dissector(iec104asdu_handle, tvb_new_subset(tvb, Off+ APCI_LEN, -1, apcih->ApduLen- APCI_DATA_LEN), pinfo, tree);
}
trHead = proto_item_add_subtree(it104, ett_apci);
proto_tree_add_uint(trHead, hf_apdulen, tvb, Off+ 1, 1, apcih->ApduLen);
proto_tree_add_uint(trHead, hf_apcitype, tvb, Off+ 2, 1, apcih->Type);
switch(apcih->Type){
case U_TYPE:
proto_tree_add_uint(trHead, hf_apciutype, tvb, Off+ 2, 1, apcih->UType);
break;
}
}
static void dissect_iec104reas(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, APCI_LEN,
get_iec104apdu_len, dissect_iec104apci);
}
void
proto_register_iec104apci(void)
{
static hf_register_info hf_ap[] = {
{ &hf_apdulen,
{ "ApduLen", "104apci.apdulen", FT_UINT8, BASE_DEC, NULL, 0x0,
"APDU Len", HFILL }},
{ &hf_apcitype,
{ "ApciType", "104apci.type", FT_UINT8, BASE_HEX, VALS(apci_types), 0x03,
"APCI type", HFILL }},
{ &hf_apciutype,
{ "ApciUType", "104apci.utype", FT_UINT8, BASE_HEX, VALS(u_types), 0xFC,
"Apci U type", HFILL }},
};
static gint *ett_ap[] = {
&ett_apci,
};
proto_iec104apci = proto_register_protocol(
"IEC 60870-5-104-Apci",
"104apci",
"104apci"
);
proto_register_field_array(proto_iec104apci, hf_ap, array_length(hf_ap));
proto_register_subtree_array(ett_ap, array_length(ett_ap));
}
void
proto_register_iec104asdu(void)
{
static hf_register_info hf_as[] = {
{ &hf_addr,
{ "Addr", "104asdu.addr", FT_UINT16, BASE_DEC, NULL, 0x0,
"Common Address of Asdu", HFILL }},
{ &hf_oa,
{ "OA", "104asdu.oa", FT_UINT8, BASE_DEC, NULL, 0x0,
"Originator Address", HFILL }},
{ &hf_typeid,
{ "TypeId", "104asdu.typeid", FT_UINT8, BASE_DEC, VALS(asdu_types), 0x0,
"Asdu Type Id", HFILL }},
{ &hf_causetx,
{ "CauseTx", "104asdu.causetx", FT_UINT8, BASE_DEC, VALS(causetx_types), 0x3F,
"Cause of Transmision", HFILL }},
{ &hf_nega,
{ "Negative", "104asdu.nega", FT_BOOLEAN, 8, NULL, F_NEGA,
NULL, HFILL }},
{ &hf_test,
{ "Test", "104asdu.test", FT_BOOLEAN, 8, NULL, F_TEST,
NULL, HFILL }},
{ &hf_ioa,
{ "IOA", "104asdu.ioa", FT_UINT24, BASE_DEC, NULL, 0x0,
"Information Object Address", HFILL }},
{ &hf_numix,
{ "NumIx", "104asdu.numix", FT_UINT8, BASE_DEC, NULL, 0x7F,
"Number of Information Objects/Elements", HFILL }},
{ &hf_sq,
{ "SQ", "104asdu.sq", FT_BOOLEAN, 8, NULL, F_SQ,
"Sequence", HFILL }},
{ &hf_asdu_bitstring,
{ "Object value", "104asdu.bitstring", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_asdu_float,
{ "Object value", "104asdu.float", FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_asdu_normval,
{ "Object value", "104asdu.normval", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett_as[] = {
&ett_asdu,
};
proto_iec104asdu = proto_register_protocol(
"IEC 60870-5-104-Asdu",
"104asdu",
"104asdu"
);
proto_register_field_array(proto_iec104asdu, hf_as, array_length(hf_as));
proto_register_subtree_array(ett_as, array_length(ett_as));
}
void
proto_reg_handoff_iec104(void)
{
dissector_handle_t iec104apci_handle;
iec104apci_handle = create_dissector_handle(dissect_iec104reas, proto_iec104apci);
iec104asdu_handle = create_dissector_handle(dissect_iec104asdu, proto_iec104asdu);
dissector_add_uint("tcp.port", iec104port, iec104apci_handle);
}
