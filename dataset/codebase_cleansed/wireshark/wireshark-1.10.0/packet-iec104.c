static void get_CP56Time(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
guint16 ms;
guint8 valid;
struct tm tm;
nstime_t datetime;
proto_item* ti;
ms = tvb_get_letohs( tvb , *offset );
(*offset) += 2;
tm.tm_sec = ms / 1000;
datetime.nsecs = ms * 1000000;
tm.tm_min = tvb_get_guint8(tvb, *offset);
valid = tm.tm_min & 0x80;
tm.tm_min &= 0x3F;
(*offset)++;
tm.tm_hour = 0x1F & tvb_get_guint8(tvb, *offset);
(*offset)++;
tm.tm_mday = tvb_get_guint8(tvb, *offset) & 0x1F;
(*offset)++;
tm.tm_mon = 0x0F & tvb_get_guint8(tvb, *offset);
(*offset)++;
tm.tm_year = 0x7F & tvb_get_guint8(tvb, *offset);
(*offset)++;
tm.tm_isdst = -1;
datetime.secs = mktime(&tm);
ti = proto_tree_add_time(iec104_header_tree, hf_cp56time, tvb, (*offset)-7, 7, &datetime);
proto_item_append_text(ti, "%s", valid ? "Invalid":"Valid");
}
static proto_item* get_InfoObjectAddress( guint32 *asdu_info_obj_addr, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_item* ti;
*asdu_info_obj_addr = tvb_get_letoh24(tvb, *offset);
ti = proto_tree_add_item(iec104_header_tree, hf_ioa, tvb, *offset, 3, ENC_LITTLE_ENDIAN);
(*offset) += 3;
return ti;
}
static void get_SIQ( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_item* ti;
proto_tree* siq_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_siq, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
siq_tree = proto_item_add_subtree( ti, ett_siq );
proto_tree_add_item(siq_tree, hf_siq_on, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(siq_tree, hf_siq_bl, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(siq_tree, hf_siq_sb, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(siq_tree, hf_siq_nt, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(siq_tree, hf_siq_iv, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_DIQ( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_item* ti;
proto_tree* diq_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_diq, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
diq_tree = proto_item_add_subtree( ti, ett_diq );
proto_tree_add_item(diq_tree, hf_diq_value, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(diq_tree, hf_diq_bl, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(diq_tree, hf_diq_sb, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(diq_tree, hf_diq_nt, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(diq_tree, hf_diq_iv, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_QDS( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_item* ti;
proto_tree* qds_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_qds, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
qds_tree = proto_item_add_subtree( ti, ett_qds );
proto_tree_add_item(qds_tree, hf_qds_ov, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qds_tree, hf_qds_bl, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qds_tree, hf_qds_sb, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qds_tree, hf_qds_nt, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qds_tree, hf_qds_iv, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_VTI( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_tree_add_item(iec104_header_tree, hf_vti, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(iec104_header_tree, hf_vti_tr, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_NVA( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_tree_add_item(iec104_header_tree, hf_asdu_normval, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
}
static void get_NVAspt( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_tree_add_item(iec104_header_tree, hf_asdu_normval, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
}
static void get_SVA( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_tree_add_item(iec104_header_tree, hf_asdu_normval, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
}
static void get_SVAspt( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_tree_add_item(iec104_header_tree, hf_asdu_normval, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
}
static void get_FLT( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_tree_add_item(iec104_header_tree, hf_asdu_float, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
(*offset) += 4;
}
static void get_FLTspt( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_tree_add_item(iec104_header_tree, hf_asdu_float, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
(*offset) += 4;
}
static void get_BSI( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_tree_add_bits_item(iec104_header_tree, hf_asdu_bitstring, tvb, *offset*8, 32, ENC_BIG_ENDIAN);
(*offset) += 4;
}
static void get_BSIspt( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_tree_add_bits_item(iec104_header_tree, hf_asdu_bitstring, tvb, *offset*8, 32, ENC_BIG_ENDIAN);
(*offset) += 4;
}
static void get_QOS( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_tree_add_item(iec104_header_tree, hf_qos_ql, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(iec104_header_tree, hf_qos_se, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_SCO( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_item* ti;
proto_tree* sco_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_sco, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
sco_tree = proto_item_add_subtree( ti, ett_sco );
proto_tree_add_item(sco_tree, hf_sco_on, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sco_tree, hf_sco_qu, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sco_tree, hf_sco_se, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_DCO( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_item* ti;
proto_tree* dco_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_dco, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
dco_tree = proto_item_add_subtree( ti, ett_dco );
proto_tree_add_item(dco_tree, hf_dco_on, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dco_tree, hf_dco_qu, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dco_tree, hf_dco_se, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_RCO( tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree )
{
proto_item* ti;
proto_tree* rco_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_rco, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
rco_tree = proto_item_add_subtree( ti, ett_rco );
proto_tree_add_item(rco_tree, hf_rco_up, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rco_tree, hf_rco_qu, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rco_tree, hf_rco_se, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static guint get_iec104apdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint8 Val;
guint32 Off;
for (Off= 0; Off <= tvb_reported_length(tvb)- 2; Off++) {
Val = tvb_get_guint8(tvb, offset+ Off);
if (Val == APCI_START) {
return (guint)(Off+ tvb_get_guint8(tvb, offset+ Off+ 1)+ 2);
}
}
return (guint)(tvb_reported_length(tvb));
}
static void dissect_iec104asdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint Len = tvb_reported_length(tvb);
guint8 Bytex;
const char *cause_str;
size_t Ind;
struct asduheader asduh;
proto_item *it104, *ioa_item;
proto_tree *it104tree;
guint8 offset = 0;
guint8 offset_start_ioa = 0;
guint8 i;
guint32 asdu_info_obj_addr = 0;
proto_item * itSignal = NULL;
proto_tree * trSignal;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "104asdu");
col_clear(pinfo->cinfo, COL_INFO);
it104 = proto_tree_add_item(tree, proto_iec104asdu, tvb, 0, -1, ENC_NA);
it104tree = proto_item_add_subtree(it104, ett_asdu);
asduh.TypeId = tvb_get_guint8(tvb, 0);
proto_tree_add_item(it104tree, hf_typeid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
Bytex = tvb_get_guint8(tvb, 1);
asduh.NumIx = Bytex & 0x7F;
asduh.SQ = Bytex & F_SQ;
proto_tree_add_item(it104tree, hf_numix, tvb, 1, 1, ENC_LITTLE_ENDIAN);
if (asduh.NumIx > 1)
proto_tree_add_item(it104tree, hf_sq, tvb, 1, 1, ENC_LITTLE_ENDIAN);
asduh.TNCause = tvb_get_guint8(tvb, 2);
proto_tree_add_item(it104tree, hf_causetx, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(it104tree, hf_nega, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(it104tree, hf_test, tvb, 2, 1, ENC_LITTLE_ENDIAN);
asduh.OA = tvb_get_guint8(tvb, 3);
proto_tree_add_item(it104tree, hf_oa, tvb, 3, 1, ENC_LITTLE_ENDIAN);
asduh.Addr = tvb_get_letohs(tvb, 4);
proto_tree_add_item(it104tree, hf_addr, tvb, 4, 2, ENC_LITTLE_ENDIAN);
asduh.IOA = tvb_get_letoh24(tvb, 6);
proto_tree_add_item(it104tree, hf_ioa, tvb, 6, 3, ENC_LITTLE_ENDIAN);
cause_str = val_to_str(asduh.TNCause & F_CAUSE, causetx_types, " <CauseTx=%u>");
col_append_fstr( pinfo->cinfo, COL_INFO, "%u %s %u %s %s", asduh.Addr, pinfo->srcport == IEC104_PORT ? "->" : "<-",
asduh.OA, val_to_str(asduh.TypeId, asdu_types, "<TypeId=%u>"), cause_str);
if (asduh.TNCause & F_NEGA)
col_append_str( pinfo->cinfo, COL_INFO, "_NEGA");
if (asduh.TNCause & F_TEST)
col_append_str( pinfo->cinfo, COL_INFO, "_TEST");
if (asduh.TNCause & (F_TEST | F_NEGA)) {
for (Ind=strlen(cause_str); Ind< 7; Ind++)
col_append_str( pinfo->cinfo, COL_INFO, " ");
}
col_append_fstr( pinfo->cinfo, COL_INFO, " IOA=%d", asduh.IOA);
if (asduh.NumIx > 1) {
if (asduh.SQ == F_SQ)
col_append_fstr( pinfo->cinfo, COL_INFO, "-%d", asduh.IOA + asduh.NumIx - 1);
else
col_append_str( pinfo->cinfo, COL_INFO, ",...");
col_append_fstr( pinfo->cinfo, COL_INFO, " (%u) ", asduh.NumIx);
} else {
col_append_str( pinfo->cinfo, COL_INFO, " ");
}
col_set_fence(pinfo->cinfo, COL_INFO);
offset = 6;
switch (asduh.TypeId) {
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
itSignal = proto_tree_add_text(it104tree, tvb, offset, -1, "Object values");
trSignal = proto_item_add_subtree( itSignal, ett_asdu_objects );
for(i = 0; i < asduh.NumIx; i++)
{
if (!i)
{
offset_start_ioa = offset;
asdu_info_obj_addr = asduh.IOA;
ioa_item = proto_tree_add_uint(trSignal, hf_ioa, tvb, offset_start_ioa, 3, asdu_info_obj_addr);
if( Len < (guint)(offset+3) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
offset += 3;
} else {
if (asduh.SQ)
{
asdu_info_obj_addr++;
ioa_item = proto_tree_add_uint(trSignal, hf_ioa, tvb, offset_start_ioa, 3, asdu_info_obj_addr);
} else {
if( Len < (guint)(offset+3) ) {
expert_add_info_format(pinfo, itSignal, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
ioa_item = get_InfoObjectAddress( &asdu_info_obj_addr, tvb, &offset, trSignal);
}
}
switch (asduh.TypeId) {
case M_SP_NA_1:
if( Len < (guint)(offset+1) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_SIQ( tvb, &offset, trSignal );
break;
case M_DP_NA_1:
if( Len < (guint)(offset+1) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_DIQ( tvb, &offset, trSignal );
break;
case M_ST_NA_1:
if( Len < (guint)(offset+2) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_VTI( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
break;
case M_BO_NA_1:
if( Len < (guint)(offset+5) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_BSI( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
break;
case M_ME_NA_1:
if( Len < (guint)(offset+3) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_NVA( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
break;
case M_ME_NB_1:
if( Len < (guint)(offset+3) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_SVA( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
break;
case M_ME_NC_1:
if( Len < (guint)(offset+5) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_FLT( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
break;
case M_ME_ND_1:
if( Len < (guint)(offset+2) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_NVA( tvb, &offset, trSignal );
break;
case M_SP_TB_1:
if( Len < (guint)(offset+8) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_SIQ( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case M_DP_TB_1:
if( Len < (guint)(offset+8) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_DIQ( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case M_ST_TB_1:
if( Len < (guint)(offset+9) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_VTI( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case M_BO_TB_1:
if( Len < (guint)(offset+12) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_BSI( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case M_ME_TD_1:
if( Len < (guint)(offset+10) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_NVA( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case M_ME_TE_1:
if( Len < (guint)(offset+10) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_SVA( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case M_ME_TF_1:
if( Len < (guint)(offset+12) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_FLT( tvb, &offset, trSignal );
get_QDS( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case C_SC_NA_1:
if( Len < (guint)(offset+1) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_SCO( tvb, &offset, trSignal );
break;
case C_DC_NA_1:
if( Len < (guint)(offset+1) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_DCO( tvb, &offset, trSignal );
break;
case C_RC_NA_1:
if( Len < (guint)(offset+1) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_RCO( tvb, &offset, trSignal );
break;
case C_SE_NA_1:
if( Len < (guint)(offset+3) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_NVAspt( tvb, &offset, trSignal );
get_QOS( tvb, &offset, trSignal );
break;
case C_SE_NB_1:
if( Len < (guint)(offset+3) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_SVAspt( tvb, &offset, trSignal );
get_QOS( tvb, &offset, trSignal );
break;
case C_SE_NC_1:
if( Len < (guint)(offset+5) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_FLTspt( tvb, &offset, trSignal );
get_QOS( tvb, &offset, trSignal );
break;
case C_BO_NA_1:
if( Len < (guint)(offset+4) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_BSIspt( tvb, &offset, trSignal );
break;
case C_SC_TA_1:
if( Len < (guint)(offset+8) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_SCO( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case C_DC_TA_1:
if( Len < (guint)(offset+8) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_DCO( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case C_RC_TA_1:
if( Len < (guint)(offset+8) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_RCO( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case C_SE_TA_1:
if( Len < (guint)(offset+10) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_NVAspt( tvb, &offset, trSignal );
get_QOS( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case C_SE_TB_1:
if( Len < (guint)(offset+10) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_SVAspt( tvb, &offset, trSignal );
get_QOS( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case C_SE_TC_1:
if( Len < (guint)(offset+12) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_FLTspt( tvb, &offset, trSignal );
get_QOS( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case C_BO_TA_1:
if( Len < (guint)(offset+11) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_BSIspt( tvb, &offset, trSignal );
get_CP56Time( tvb, &offset, trSignal );
break;
case C_CS_NA_1:
if( Len < (guint)(offset+7) ) {
expert_add_info_format(pinfo, ioa_item, PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>");
return;
}
get_CP56Time( tvb, &offset, trSignal );
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
guint TcpLen = tvb_reported_length(tvb);
guint8 Start = 0, len, type = 0, temp8;
guint8 temp16;
guint Off;
proto_item *it104, *ti;
proto_tree *it104tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "104apci");
col_clear(pinfo->cinfo, COL_INFO);
it104 = proto_tree_add_item(tree, proto_iec104apci, tvb, 0, -1, ENC_NA);
it104tree = proto_item_add_subtree(it104, ett_apci);
for (Off= 0; Off <= TcpLen- 2; Off++) {
Start = tvb_get_guint8(tvb, Off);
if (Start == APCI_START) {
if (Off > 0)
{
proto_tree_add_item(it104tree, hf_apcidata, tvb, 0, Off, ENC_NA);
col_append_fstr( pinfo->cinfo, COL_INFO, "<ERR prefix %u bytes> ", Off);
}
proto_item_set_len(it104, Off+ APCI_LEN);
proto_tree_add_text(it104tree, tvb, Off, 1, "START");
ti = proto_tree_add_item(it104tree, hf_apdulen, tvb, Off+ 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(it104tree, hf_apcitype, tvb, Off+ 2, 1, ENC_LITTLE_ENDIAN);
len = tvb_get_guint8(tvb, Off+ 1);
if (len < APDU_MIN_LEN) {
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR, "APDU less than %d bytes", APDU_MIN_LEN);
col_append_fstr( pinfo->cinfo, COL_INFO, "<ERR ApduLen=%u bytes> ", len);
return;
}
temp8 = tvb_get_guint8(tvb, Off+ 2);
type = temp8 & 0x03;
if (len <= APDU_MAX_LEN) {
col_append_fstr( pinfo->cinfo, COL_INFO, "%s %s (",
(pinfo->srcport == IEC104_PORT ? "->" : "<-"),
val_to_str_const(type, apci_types, "<ERR>"));
}
else {
col_append_fstr( pinfo->cinfo, COL_INFO, "<ERR ApduLen=%u bytes> ", len);
}
switch(type) {
case I_TYPE:
case I_TYPE2:
temp16 = tvb_get_letohs(tvb, Off+ 2) >> 1;
col_append_fstr( pinfo->cinfo, COL_INFO, "%2.2d,", temp16);
proto_tree_add_uint(it104tree, hf_apcitx, tvb, Off+2, 2, temp16);
case S_TYPE:
temp16 = tvb_get_letohs(tvb, Off+ 4) >> 1;
col_append_fstr( pinfo->cinfo, COL_INFO, "%2.2d) ", temp16);
proto_tree_add_uint(it104tree, hf_apcirx, tvb, Off+4, 2, temp16);
break;
case U_TYPE:
col_append_fstr( pinfo->cinfo, COL_INFO, "%s) ", val_to_str_const((temp8 >> 2) & 0x3F, u_types, "<ERR>"));
proto_tree_add_item(it104tree, hf_apciutype, tvb, Off+ 2, 1, ENC_LITTLE_ENDIAN);
break;
}
break;
}
}
if (Start != APCI_START) {
proto_tree_add_item(it104tree, hf_apcidata, tvb, 0, Off, ENC_NA);
return;
}
if ((type == I_TYPE) || (type == I_TYPE2)) {
call_dissector(iec104asdu_handle, tvb_new_subset(tvb, Off+ APCI_LEN, -1, len - APCI_DATA_LEN), pinfo, tree);
} else {
col_set_fence(pinfo->cinfo, COL_INFO);
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
{ "Type", "104apci.type", FT_UINT8, BASE_HEX, VALS(apci_types), 0x03,
"APCI type", HFILL }},
{ &hf_apciutype,
{ "UType", "104apci.utype", FT_UINT8, BASE_HEX, VALS(u_types), 0xFC,
"Apci U type", HFILL }},
{ &hf_apcitx,
{ "Tx", "104apci.tx", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_apcirx,
{ "Rx", "104apci.rx", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_apcidata,
{ "Data", "104apci.data", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
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
{ "CauseTx", "104asdu.causetx", FT_UINT8, BASE_DEC, VALS(causetx_types), F_CAUSE,
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
{ &hf_cp56time,
{ "CP56Time", "104asdu.cp56time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
NULL, HFILL }},
{ &hf_siq,
{ "SIQ", "104asdu.siq", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_siq_on,
{ "SQ", "104asdu.siq.on", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x01,
"SIQ SQ", HFILL }},
{ &hf_siq_bl,
{ "BL", "104asdu.siq.bl", FT_BOOLEAN, 8, TFS(&tfs_blocked_not_blocked), 0x02,
"SIQ BL", HFILL }},
{ &hf_siq_sb,
{ "SB", "104asdu.siq.sb", FT_BOOLEAN, 8, TFS(&tfs_substituted_not_substituted), 0x04,
"SIQ SB", HFILL }},
{ &hf_siq_nt,
{ "NT", "104asdu.siq.nt", FT_BOOLEAN, 8, TFS(&tfs_not_topical_topical), 0x08,
"SIQ NT", HFILL }},
{ &hf_siq_iv,
{ "IV", "104asdu.siq.iv", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid), 0x10,
"SIQ IV", HFILL }},
{ &hf_diq,
{ "DIQ", "104asdu.diq", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_diq_value,
{ "Value", "104asdu.diq.value", FT_UINT8, BASE_DEC, VALS(diq_types), 0x03,
"DIQ Value", HFILL }},
{ &hf_diq_bl,
{ "BL", "104asdu.diq.bl", FT_BOOLEAN, 8, TFS(&tfs_blocked_not_blocked), 0x10,
"DIQ BL", HFILL }},
{ &hf_diq_sb,
{ "SB", "104asdu.diq.sb", FT_BOOLEAN, 8, TFS(&tfs_substituted_not_substituted), 0x20,
"DIQ SB", HFILL }},
{ &hf_diq_nt,
{ "NT", "104asdu.diq.nt", FT_BOOLEAN, 8, TFS(&tfs_not_topical_topical), 0x40,
"DIQ NT", HFILL }},
{ &hf_diq_iv,
{ "IV", "104asdu.diq.iv", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid), 0x80,
"DIQ IV", HFILL }},
{ &hf_qds,
{ "QDS", "104asdu.qds", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_qds_ov,
{ "OV", "104asdu.qds.ov", FT_BOOLEAN, 8, TFS(&tfs_overflow_no_overflow), 0x01,
"QDS OV", HFILL }},
{ &hf_qds_bl,
{ "BL", "104asdu.qds.bl", FT_BOOLEAN, 8, TFS(&tfs_blocked_not_blocked), 0x02,
"QDS BL", HFILL }},
{ &hf_qds_sb,
{ "SB", "104asdu.qds.sb", FT_BOOLEAN, 8, TFS(&tfs_substituted_not_substituted), 0x04,
"QDS SB", HFILL }},
{ &hf_qds_nt,
{ "NT", "104asdu.qds.nt", FT_BOOLEAN, 8, TFS(&tfs_not_topical_topical), 0x08,
"QDS NT", HFILL }},
{ &hf_qds_iv,
{ "IV", "104asdu.qds.iv", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid), 0x10,
"QDS IV", HFILL }},
{ &hf_vti,
{ "VTI", "104asdu.vti", FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_vti_tr,
{ "VTI Transient", "104asdu.qds.ov", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_qos_ql,
{ "QOS Qualifier", "104asdu.qos_ql", FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_qos_se,
{ "QOS S/E", "104asdu.qos_se", FT_BOOLEAN, 8, TFS(&tfs_select_execute), 0x80,
NULL, HFILL }},
{ &hf_sco,
{ "SCO", "104asdu.sco", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sco_on,
{ "SCO ON/OFF", "104asdu.sco.on", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x01,
NULL, HFILL }},
{ &hf_sco_qu,
{ "SCO QU", "104asdu.sco.qu", FT_UINT8, BASE_DEC, VALS(qos_qu_types), 0x70,
NULL, HFILL }},
{ &hf_sco_se,
{ "SCO S/E", "104asdu.sco.se", FT_BOOLEAN, 8, TFS(&tfs_select_execute), 0x80,
NULL, HFILL }},
{ &hf_dco,
{ "DCO", "104asdu.dco", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dco_on,
{ "DCO ON/OFF", "104asdu.dco.on", FT_UINT8, BASE_DEC, VALS(dco_on_types), 0x03,
NULL, HFILL }},
{ &hf_dco_qu,
{ "DCO QU", "104asdu.dco.qu", FT_UINT8, BASE_DEC, VALS(qos_qu_types), 0x70,
NULL, HFILL }},
{ &hf_dco_se,
{ "DCO S/E", "104asdu.dco.se", FT_BOOLEAN, 8, TFS(&tfs_select_execute), 0x80,
NULL, HFILL }},
{ &hf_rco,
{ "RCO", "104asdu.rco", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rco_up,
{ "RCO UP/DOWN", "104asdu.rco.up", FT_UINT8, BASE_DEC, VALS(rco_up_types), 0x03,
NULL, HFILL }},
{ &hf_rco_qu,
{ "RCO QU", "104asdu.rco.qu", FT_UINT8, BASE_DEC, VALS(qos_qu_types), 0x70,
NULL, HFILL }},
{ &hf_rco_se,
{ "RCO S/E", "104asdu.rco.se", FT_BOOLEAN, 8, TFS(&tfs_select_execute), 0x80,
NULL, HFILL }},
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
&ett_asdu_objects,
&ett_siq,
&ett_diq,
&ett_qds,
&ett_sco,
&ett_dco,
&ett_rco
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
dissector_add_uint("tcp.port", IEC104_PORT, iec104apci_handle);
}
