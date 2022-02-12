static void get_CP56Time(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
guint16 ms;
guint8 value;
guint8 su;
struct tm tm;
nstime_t datetime;
proto_item* ti;
proto_tree* cp56time_tree;
ms = tvb_get_letohs(tvb, *offset);
tm.tm_sec = ms / 1000;
datetime.nsecs = (ms % 1000) * 1000000;
(*offset) += 2;
value = tvb_get_guint8(tvb, *offset);
tm.tm_min = value & 0x3F;
(*offset)++;
value = tvb_get_guint8(tvb, *offset);
tm.tm_hour = value & 0x1F;
su = value & 0x80;
(*offset)++;
value = tvb_get_guint8(tvb, *offset);
tm.tm_mday = value & 0x1F;
(*offset)++;
value = tvb_get_guint8(tvb, *offset);
tm.tm_mon = (value & 0x0F) - 1;
(*offset)++;
value = tvb_get_guint8(tvb, *offset);
tm.tm_year = value & 0x7F;
if (tm.tm_year < 70)
tm.tm_year += 100;
(*offset)++;
if (su)
tm.tm_isdst = 1;
else
tm.tm_isdst = -1;
datetime.secs = mktime(&tm);
(*offset) -= 7;
ti = proto_tree_add_time(iec104_header_tree, hf_cp56time, tvb, *offset, 7, &datetime);
cp56time_tree = proto_item_add_subtree(ti, ett_cp56time);
proto_tree_add_item(cp56time_tree, hf_cp56time_ms, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
proto_tree_add_item(cp56time_tree, hf_cp56time_min, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cp56time_tree, hf_cp56time_iv, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset) ++;
proto_tree_add_item(cp56time_tree, hf_cp56time_hour, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cp56time_tree, hf_cp56time_su, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset) ++;
proto_tree_add_item(cp56time_tree, hf_cp56time_day, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cp56time_tree, hf_cp56time_dow, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset) ++;
proto_tree_add_item(cp56time_tree, hf_cp56time_month, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset) ++;
proto_tree_add_item(cp56time_tree, hf_cp56time_year, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset) ++;
}
static proto_item* get_InfoObjectAddress(guint32 *asdu_info_obj_addr, tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
*asdu_info_obj_addr = tvb_get_letoh24(tvb, *offset);
ti = proto_tree_add_item(iec104_header_tree, hf_ioa, tvb, *offset, 3, ENC_LITTLE_ENDIAN);
(*offset) += 3;
return ti;
}
static guint8 get_TypeIdLength(guint8 TypeId)
{
guint8 ret = 0;
const td_asdu_length *item;
item = asdu_length;
while (item->value)
{
if (item->value == TypeId)
{
ret = item->length;
break;
}
item++;
}
return ret;
}
static void get_SIQ(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
proto_tree* siq_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_siq, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
siq_tree = proto_item_add_subtree(ti, ett_siq);
proto_tree_add_item(siq_tree, hf_siq_spi, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(siq_tree, hf_siq_bl, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(siq_tree, hf_siq_sb, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(siq_tree, hf_siq_nt, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(siq_tree, hf_siq_iv, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_DIQ(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
proto_tree* diq_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_diq, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
diq_tree = proto_item_add_subtree(ti, ett_diq);
proto_tree_add_item(diq_tree, hf_diq_dpi, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(diq_tree, hf_diq_bl, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(diq_tree, hf_diq_sb, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(diq_tree, hf_diq_nt, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(diq_tree, hf_diq_iv, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_QDS(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
proto_tree* qds_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_qds, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
qds_tree = proto_item_add_subtree(ti, ett_qds);
proto_tree_add_item(qds_tree, hf_qds_ov, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qds_tree, hf_qds_bl, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qds_tree, hf_qds_sb, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qds_tree, hf_qds_nt, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qds_tree, hf_qds_iv, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_VTI(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
proto_tree* vti_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_vti, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
vti_tree = proto_item_add_subtree(ti, ett_vti);
proto_tree_add_item(vti_tree, hf_vti_v, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(vti_tree, hf_vti_t, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_NVA(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
gint16 value;
float fvalue;
value = (gint16)tvb_get_letohs(tvb, *offset);
fvalue = (float)value / 32768;
proto_tree_add_float_format_value(iec104_header_tree, hf_asdu_normval, tvb, *offset, 2, fvalue, "%." G_STRINGIFY(FLT_DIG) "g (%d)", fvalue, value);
(*offset) += 2;
}
static void get_NVAspt(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
gint16 value;
float fvalue;
value = (gint16)tvb_get_letohs(tvb, *offset);
fvalue = (float)value / 32768;
proto_tree_add_float_format_value(iec104_header_tree, hf_asdu_normval, tvb, *offset, 2, fvalue, "%." G_STRINGIFY(FLT_DIG) "g (%d)", fvalue, value);
(*offset) += 2;
}
static void get_SVA(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_tree_add_item(iec104_header_tree, hf_asdu_scalval, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
}
static void get_SVAspt(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_tree_add_item(iec104_header_tree, hf_asdu_scalval, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
(*offset) += 2;
}
static void get_FLT(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_tree_add_item(iec104_header_tree, hf_asdu_float, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
(*offset) += 4;
}
static void get_FLTspt(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_tree_add_item(iec104_header_tree, hf_asdu_float, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
(*offset) += 4;
}
static void get_BSI(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_tree_add_bits_item(iec104_header_tree, hf_asdu_bitstring, tvb, *offset*8, 32, ENC_BIG_ENDIAN);
(*offset) += 4;
}
static void get_BSIspt(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_tree_add_bits_item(iec104_header_tree, hf_asdu_bitstring, tvb, *offset*8, 32, ENC_BIG_ENDIAN);
(*offset) += 4;
}
static void get_BCR(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_tree_add_item(iec104_header_tree, hf_bcr_count, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_item(iec104_header_tree, hf_bcr_sq, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(iec104_header_tree, hf_bcr_cy, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(iec104_header_tree, hf_bcr_ca, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(iec104_header_tree, hf_bcr_iv, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
}
static void get_QOS(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
proto_tree* qos_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_qos, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
qos_tree = proto_item_add_subtree(ti, ett_qos);
proto_tree_add_item(qos_tree, hf_qos_ql, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qos_tree, hf_qos_se, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_SCO(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
proto_tree* sco_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_sco, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
sco_tree = proto_item_add_subtree(ti, ett_sco);
proto_tree_add_item(sco_tree, hf_sco_on, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sco_tree, hf_sco_qu, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sco_tree, hf_sco_se, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_DCO(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
proto_tree* dco_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_dco, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
dco_tree = proto_item_add_subtree(ti, ett_dco);
proto_tree_add_item(dco_tree, hf_dco_on, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dco_tree, hf_dco_qu, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dco_tree, hf_dco_se, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_RCO(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
proto_tree* rco_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_rco, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
rco_tree = proto_item_add_subtree(ti, ett_rco);
proto_tree_add_item(rco_tree, hf_rco_up, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rco_tree, hf_rco_qu, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rco_tree, hf_rco_se, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_COI(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_item* ti;
proto_tree* coi_tree;
ti = proto_tree_add_item(iec104_header_tree, hf_coi, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
coi_tree = proto_item_add_subtree(ti, ett_rco);
proto_tree_add_item(coi_tree, hf_coi_r, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(coi_tree, hf_coi_i, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static void get_QOI(tvbuff_t *tvb, guint8 *offset, proto_tree *iec104_header_tree)
{
proto_tree_add_item(iec104_header_tree, hf_qoi, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
(*offset)++;
}
static guint get_iec104apdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint8 Val;
guint32 Off;
for (Off = 0; Off <= tvb_reported_length(tvb) - 2; Off++) {
Val = tvb_get_guint8(tvb, offset + Off);
if (Val == APCI_START) {
return (guint)(Off + tvb_get_guint8(tvb, offset + Off + 1) + 2);
}
}
return (guint)(tvb_reported_length(tvb));
}
static int dissect_iec104asdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint Len = tvb_reported_length(tvb);
guint8 Bytex;
const char *cause_str;
size_t Ind;
struct asduheader asduh;
proto_item *it104;
proto_tree *it104tree;
wmem_strbuf_t * res;
guint8 offset = 0;
guint8 i;
guint32 asdu_info_obj_addr = 0;
proto_item * itSignal = NULL;
proto_tree * trSignal;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "104asdu");
it104 = proto_tree_add_item(tree, proto_iec104asdu, tvb, 0, -1, ENC_NA);
it104tree = proto_item_add_subtree(it104, ett_asdu);
res = wmem_strbuf_new_label(wmem_packet_scope());
asduh.TypeId = tvb_get_guint8(tvb, 0);
proto_tree_add_item(it104tree, hf_typeid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
asduh.DataLength = get_TypeIdLength(asduh.TypeId);
Bytex = tvb_get_guint8(tvb, 1);
asduh.SQ = Bytex & F_SQ;
asduh.NumIx = Bytex & 0x7F;
proto_tree_add_item(it104tree, hf_sq, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(it104tree, hf_numix, tvb, 1, 1, ENC_LITTLE_ENDIAN);
asduh.TNCause = tvb_get_guint8(tvb, 2);
proto_tree_add_item(it104tree, hf_causetx, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(it104tree, hf_nega, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(it104tree, hf_test, tvb, 2, 1, ENC_LITTLE_ENDIAN);
asduh.OA = tvb_get_guint8(tvb, 3);
proto_tree_add_item(it104tree, hf_oa, tvb, 3, 1, ENC_LITTLE_ENDIAN);
asduh.Addr = tvb_get_letohs(tvb, 4);
proto_tree_add_item(it104tree, hf_addr, tvb, 4, 2, ENC_LITTLE_ENDIAN);
asduh.IOA = tvb_get_letoh24(tvb, 6);
cause_str = val_to_str(asduh.TNCause & F_CAUSE, causetx_types, " <CauseTx=%u>");
wmem_strbuf_append_printf(res, "ASDU=%u %s %s", asduh.Addr, val_to_str(asduh.TypeId, asdu_types, "<TypeId=%u>"), cause_str);
if (asduh.TNCause & F_NEGA)
wmem_strbuf_append(res, "_NEGA");
if (asduh.TNCause & F_TEST)
wmem_strbuf_append(res, "_TEST");
if ((asduh.TNCause & (F_TEST | F_NEGA)) == 0) {
for (Ind=strlen(cause_str); Ind< 7; Ind++)
wmem_strbuf_append(res, " ");
}
if (asduh.NumIx > 1) {
wmem_strbuf_append_printf(res, " IOA[%d]=%d", asduh.NumIx, asduh.IOA);
if (asduh.SQ == F_SQ)
wmem_strbuf_append_printf(res, "-%d", asduh.IOA + asduh.NumIx - 1);
else
wmem_strbuf_append(res, ",...");
} else {
wmem_strbuf_append_printf(res, " IOA=%d", asduh.IOA);
}
col_append_str(pinfo->cinfo, COL_INFO, wmem_strbuf_get_str(res));
col_set_fence(pinfo->cinfo, COL_INFO);
proto_item_append_text(it104, ": %s '%s'", wmem_strbuf_get_str(res),
Len >= ASDU_HEAD_LEN ? val_to_str_const(asduh.TypeId, asdu_lngtypes, "<Unknown TypeId>") : "");
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
case M_IT_NA_1:
case M_IT_TB_1:
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
case M_EI_NA_1:
case C_IC_NA_1:
case C_CS_NA_1:
for(i = 0; i < asduh.NumIx; i++)
{
if (i == 0 || !asduh.SQ)
trSignal = proto_tree_add_subtree(it104tree, tvb, offset, asduh.DataLength + 3,
ett_asdu_objects, &itSignal, "IOA:s");
else
trSignal = proto_tree_add_subtree(it104tree, tvb, offset, asduh.DataLength,
ett_asdu_objects, &itSignal, "IOA:s");
if (i == 0)
{
if(Len < (guint)(offset + 3)) {
expert_add_info(pinfo, itSignal, &ei_iec104_short_asdu);
return offset;
}
get_InfoObjectAddress(&asdu_info_obj_addr, tvb, &offset, trSignal);
} else {
if (asduh.SQ)
{
proto_item *ti;
asdu_info_obj_addr++;
ti = proto_tree_add_uint(trSignal, hf_ioa, tvb, 0, 0, asdu_info_obj_addr);
PROTO_ITEM_SET_GENERATED(ti);
} else {
if(Len < (guint)(offset + 3)) {
expert_add_info(pinfo, itSignal, &ei_iec104_short_asdu);
return offset;
}
get_InfoObjectAddress(&asdu_info_obj_addr, tvb, &offset, trSignal);
}
}
proto_item_set_text(itSignal, "IOA: %d", asdu_info_obj_addr);
if(Len < (guint)(offset + asduh.DataLength)) {
expert_add_info(pinfo, itSignal, &ei_iec104_short_asdu);
return offset;
}
switch (asduh.TypeId) {
case M_SP_NA_1:
get_SIQ(tvb, &offset, trSignal);
break;
case M_DP_NA_1:
get_DIQ(tvb, &offset, trSignal);
break;
case M_ST_NA_1:
get_VTI(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
break;
case M_BO_NA_1:
get_BSI(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
break;
case M_ME_NA_1:
get_NVA(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
break;
case M_ME_NB_1:
get_SVA(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
break;
case M_ME_NC_1:
get_FLT(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
break;
case M_IT_NA_1:
get_BCR(tvb, &offset, trSignal);
break;
case M_ME_ND_1:
get_NVA(tvb, &offset, trSignal);
break;
case M_SP_TB_1:
get_SIQ(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case M_DP_TB_1:
get_DIQ(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case M_ST_TB_1:
get_VTI(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case M_BO_TB_1:
get_BSI(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case M_ME_TD_1:
get_NVA(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case M_ME_TE_1:
get_SVA(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case M_ME_TF_1:
get_FLT(tvb, &offset, trSignal);
get_QDS(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case M_IT_TB_1:
get_BCR(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case C_SC_NA_1:
get_SCO(tvb, &offset, trSignal);
break;
case C_DC_NA_1:
get_DCO(tvb, &offset, trSignal);
break;
case C_RC_NA_1:
get_RCO(tvb, &offset, trSignal);
break;
case C_SE_NA_1:
get_NVAspt(tvb, &offset, trSignal);
get_QOS(tvb, &offset, trSignal);
break;
case C_SE_NB_1:
get_SVAspt(tvb, &offset, trSignal);
get_QOS(tvb, &offset, trSignal);
break;
case C_SE_NC_1:
get_FLTspt(tvb, &offset, trSignal);
get_QOS(tvb, &offset, trSignal);
break;
case C_BO_NA_1:
get_BSIspt(tvb, &offset, trSignal);
break;
case C_SC_TA_1:
get_SCO(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case C_DC_TA_1:
get_DCO(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case C_RC_TA_1:
get_RCO(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case C_SE_TA_1:
get_NVAspt(tvb, &offset, trSignal);
get_QOS(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case C_SE_TB_1:
get_SVAspt(tvb, &offset, trSignal);
get_QOS(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case C_SE_TC_1:
get_FLTspt(tvb, &offset, trSignal);
get_QOS(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case C_BO_TA_1:
get_BSIspt(tvb, &offset, trSignal);
get_CP56Time(tvb, &offset, trSignal);
break;
case M_EI_NA_1:
get_COI(tvb, &offset, trSignal);
break;
case C_IC_NA_1:
get_QOI(tvb, &offset, trSignal);
break;
case C_CS_NA_1:
get_CP56Time(tvb, &offset, trSignal);
break;
default:
break;
}
}
break;
default:
proto_tree_add_item(it104tree, hf_ioa, tvb, offset, 3, ENC_LITTLE_ENDIAN);
break;
}
return tvb_captured_length(tvb);
}
static int dissect_iec104apci(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint TcpLen = tvb_reported_length(tvb);
guint8 Start, len, type, temp8;
guint16 apci_txid, apci_rxid;
guint Off;
proto_item *it104, *ti;
proto_tree *it104tree;
wmem_strbuf_t * res;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "104apci");
it104 = proto_tree_add_item(tree, proto_iec104apci, tvb, 0, -1, ENC_NA);
it104tree = proto_item_add_subtree(it104, ett_apci);
res = wmem_strbuf_new_label(wmem_packet_scope());
Start = 0;
for (Off = 0; Off <= TcpLen - 2; Off++) {
Start = tvb_get_guint8(tvb, Off);
if (Start == APCI_START) {
if (Off > 0)
{
proto_tree_add_item(it104tree, hf_apcidata, tvb, 0, Off, ENC_NA);
wmem_strbuf_append_printf(res, "<ERR prefix %u bytes> ", Off);
}
proto_item_set_len(it104, Off + APCI_LEN);
proto_tree_add_uint_format(it104tree, hf_start, tvb, Off, 1, Start, "START");
ti = proto_tree_add_item(it104tree, hf_apdulen, tvb, Off + 1, 1, ENC_LITTLE_ENDIAN);
len = tvb_get_guint8(tvb, Off + 1);
if (len < APDU_MIN_LEN) {
expert_add_info_format(pinfo, ti, &ei_iec104_apdu_min_len, "APDU less than %d bytes", APDU_MIN_LEN);
wmem_strbuf_append_printf(res, "<ERR ApduLen=%u bytes> ", len);
return tvb_captured_length(tvb);
}
temp8 = tvb_get_guint8(tvb, Off + 2);
if ((temp8 & 0x01) == 0)
type = 0;
else
type = temp8 & 0x03;
if (type == I_TYPE)
proto_tree_add_bits_item(it104tree, hf_apcitype, tvb, (Off + 2) * 8 + 7, 1, ENC_LITTLE_ENDIAN);
else
proto_tree_add_bits_item(it104tree, hf_apcitype, tvb, (Off + 2) * 8 + 6, 2, ENC_LITTLE_ENDIAN);
if (len <= APDU_MAX_LEN) {
wmem_strbuf_append_printf(res, "%s %s ",
(pinfo->srcport == iec104_port ? "->" : "<-"),
val_to_str_const(type, apci_types, "<ERR>"));
}
else {
wmem_strbuf_append_printf(res, "<ERR ApduLen=%u bytes> ", len);
}
switch(type) {
case I_TYPE:
apci_txid = tvb_get_letohs(tvb, Off + 2) >> 1;
apci_rxid = tvb_get_letohs(tvb, Off + 4) >> 1;
wmem_strbuf_append_printf(res, "(%d,%d) ", apci_txid, apci_rxid);
proto_tree_add_uint(it104tree, hf_apcitx, tvb, Off+2, 2, apci_txid);
proto_tree_add_uint(it104tree, hf_apcirx, tvb, Off+4, 2, apci_rxid);
break;
case S_TYPE:
apci_rxid = tvb_get_letohs(tvb, Off + 4) >> 1;
wmem_strbuf_append_printf(res, "(%d) ", apci_rxid);
proto_tree_add_uint(it104tree, hf_apcirx, tvb, Off+4, 2, apci_rxid);
break;
case U_TYPE:
wmem_strbuf_append_printf(res, "(%s) ", val_to_str_const((temp8 >> 2) & 0x3F, u_types, "<ERR>"));
proto_tree_add_item(it104tree, hf_apciutype, tvb, Off + 2, 1, ENC_LITTLE_ENDIAN);
break;
}
col_clear(pinfo->cinfo, COL_INFO);
col_append_sep_str(pinfo->cinfo, COL_INFO, " | ", wmem_strbuf_get_str(res));
col_set_fence(pinfo->cinfo, COL_INFO);
proto_item_append_text(it104, ": %s", wmem_strbuf_get_str(res));
if (type == I_TYPE)
call_dissector(iec104asdu_handle, tvb_new_subset(tvb, Off + APCI_LEN, -1, len - APCI_DATA_LEN), pinfo, tree);
break;
}
}
if (Start != APCI_START) {
proto_tree_add_item(it104tree, hf_apcidata, tvb, 0, Off, ENC_NA);
}
return tvb_captured_length(tvb);
}
static int dissect_iec104reas(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, APCI_LEN,
get_iec104apdu_len, dissect_iec104apci, data);
return tvb_captured_length(tvb);
}
void
proto_register_iec104apci(void)
{
static hf_register_info hf_ap[] = {
{ &hf_apdulen,
{ "ApduLen", "104apci.apdulen", FT_UINT8, BASE_DEC, NULL, 0x0,
"APDU Len", HFILL }},
{ &hf_apcitype,
{ "Type", "104apci.type", FT_UINT8, BASE_HEX, VALS(apci_types), 0x00,
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
module_t *iec104_module;
proto_iec104apci = proto_register_protocol(
"IEC 60870-5-104-Apci",
"104apci",
"104apci"
);
proto_register_field_array(proto_iec104apci, hf_ap, array_length(hf_ap));
proto_register_subtree_array(ett_ap, array_length(ett_ap));
iec104_module = prefs_register_protocol(proto_iec104apci, proto_reg_handoff_iec104);
prefs_register_uint_preference(iec104_module, "tcp.port",
"IEC104 TCP port used by source",
"TCP port used by source of IEC104, usually 2404",
10, &iec104_port);
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
{ &hf_cp56time_ms,
{ "MS", "104asdu.cp56time.ms", FT_UINT16, BASE_DEC, NULL, 0xFFFF,
"CP56Time milliseconds", HFILL }},
{ &hf_cp56time_min,
{ "Min", "104asdu.cp56time.min", FT_UINT8, BASE_DEC, NULL, 0x3F,
"CP56Time minutes", HFILL }},
{ &hf_cp56time_iv,
{ "IV", "104asdu.cp56time.iv", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid), 0x80,
"CP56Time invalid", HFILL }},
{ &hf_cp56time_hour,
{ "Hour", "104asdu.cp56time.hour", FT_UINT8, BASE_DEC, NULL, 0x1F,
"CP56Time hours", HFILL }},
{ &hf_cp56time_su,
{ "SU", "104asdu.cp56time.su", FT_BOOLEAN, 8, TFS(&tfs_local_dst), 0x80,
"CP56Time summer time", HFILL }},
{ &hf_cp56time_day,
{ "Day", "104asdu.cp56time.day", FT_UINT8, BASE_DEC, NULL, 0x1F,
"CP56Time day", HFILL }},
{ &hf_cp56time_dow,
{ "DOW", "104asdu.cp56time.dow", FT_UINT8, BASE_DEC, NULL, 0xE0,
"CP56Time day of week", HFILL }},
{ &hf_cp56time_month,
{ "Month", "104asdu.cp56time.month", FT_UINT8, BASE_DEC, NULL, 0x0F,
"CP56Time month", HFILL }},
{ &hf_cp56time_year,
{ "Year", "104asdu.cp56time.year", FT_UINT8, BASE_DEC, NULL, 0x7F,
"CP56Time year", HFILL }},
{ &hf_siq,
{ "SIQ", "104asdu.siq", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_siq_spi,
{ "SPI", "104asdu.siq.spi", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x01,
"SIQ SPI", HFILL }},
{ &hf_siq_bl,
{ "BL", "104asdu.siq.bl", FT_BOOLEAN, 8, TFS(&tfs_blocked_not_blocked), 0x10,
"SIQ BL", HFILL }},
{ &hf_siq_sb,
{ "SB", "104asdu.siq.sb", FT_BOOLEAN, 8, TFS(&tfs_substituted_not_substituted), 0x20,
"SIQ SB", HFILL }},
{ &hf_siq_nt,
{ "NT", "104asdu.siq.nt", FT_BOOLEAN, 8, TFS(&tfs_not_topical_topical), 0x40,
"SIQ NT", HFILL }},
{ &hf_siq_iv,
{ "IV", "104asdu.siq.iv", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid), 0x80,
"SIQ IV", HFILL }},
{ &hf_diq,
{ "DIQ", "104asdu.diq", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_diq_dpi,
{ "DPI", "104asdu.diq.dpi", FT_UINT8, BASE_DEC, VALS(diq_types), 0x03,
"DIQ DPI", HFILL }},
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
{ "BL", "104asdu.qds.bl", FT_BOOLEAN, 8, TFS(&tfs_blocked_not_blocked), 0x10,
"QDS BL", HFILL }},
{ &hf_qds_sb,
{ "SB", "104asdu.qds.sb", FT_BOOLEAN, 8, TFS(&tfs_substituted_not_substituted), 0x20,
"QDS SB", HFILL }},
{ &hf_qds_nt,
{ "NT", "104asdu.qds.nt", FT_BOOLEAN, 8, TFS(&tfs_not_topical_topical), 0x40,
"QDS NT", HFILL }},
{ &hf_qds_iv,
{ "IV", "104asdu.qds.iv", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid), 0x80,
"QDS IV", HFILL }},
{ &hf_vti,
{ "VTI", "104asdu.vti", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_vti_v,
{ "Value", "104asdu.vti.v", FT_INT8, BASE_DEC, NULL, 0x7F,
"VTI Value", HFILL }},
{ &hf_vti_t,
{ "T", "104asdu.vti.t", FT_BOOLEAN, 8, TFS(&tfs_transient_not_transient), 0x80,
"VTI T", HFILL }},
{ &hf_qos,
{ "QOS", "104asdu.qos", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_qos_ql,
{ "QL", "104asdu.qos.ql", FT_UINT8, BASE_DEC, NULL, 0x7F,
"QOS QL", HFILL }},
{ &hf_qos_se,
{ "S/E", "104asdu.qos.se", FT_BOOLEAN, 8, TFS(&tfs_select_execute), 0x80,
"QOS S/E", HFILL }},
{ &hf_sco,
{ "SCO", "104asdu.sco", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_sco_on,
{ "ON/OFF", "104asdu.sco.on", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x01,
"SCO SCS", HFILL }},
{ &hf_sco_qu,
{ "QU", "104asdu.sco.qu", FT_UINT8, BASE_DEC, VALS(qos_qu_types), 0x7C,
"SCO QU", HFILL }},
{ &hf_sco_se,
{ "S/E", "104asdu.sco.se", FT_BOOLEAN, 8, TFS(&tfs_select_execute), 0x80,
"SCO S/E", HFILL }},
{ &hf_dco,
{ "DCO", "104asdu.dco", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_dco_on,
{ "ON/OFF", "104asdu.dco.on", FT_UINT8, BASE_DEC, VALS(dco_on_types), 0x03,
"DCO DCS", HFILL }},
{ &hf_dco_qu,
{ "QU", "104asdu.dco.qu", FT_UINT8, BASE_DEC, VALS(qos_qu_types), 0x7C,
"DCO QU", HFILL }},
{ &hf_dco_se,
{ "S/E", "104asdu.dco.se", FT_BOOLEAN, 8, TFS(&tfs_select_execute), 0x80,
"DCO S/E", HFILL }},
{ &hf_rco,
{ "RCO", "104asdu.rco", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_rco_up,
{ "UP/DOWN", "104asdu.rco.up", FT_UINT8, BASE_DEC, VALS(rco_up_types), 0x03,
"RCO RCS", HFILL }},
{ &hf_rco_qu,
{ "QU", "104asdu.rco.qu", FT_UINT8, BASE_DEC, VALS(qos_qu_types), 0x7C,
"RCO QU", HFILL }},
{ &hf_rco_se,
{ "S/E", "104asdu.rco.se", FT_BOOLEAN, 8, TFS(&tfs_select_execute), 0x80,
"RCO S/E", HFILL }},
{ &hf_coi,
{ "COI", "104asdu.coi", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_coi_r,
{ "R", "104asdu.coi_r", FT_UINT8, BASE_DEC, VALS(coi_r_types), 0x7F,
"COI R", HFILL }},
{ &hf_coi_i,
{ "I", "104asdu.coi_i", FT_BOOLEAN, 8, TFS(&tfs_coi_i), 0x80,
"COI I", HFILL }},
{ &hf_qoi,
{ "QOI", "104asdu.qoi", FT_UINT8, BASE_DEC, VALS(qoi_r_types), 0,
NULL, HFILL }},
{ &hf_bcr_count,
{ "Binary Counter", "104asdu.bcr.count", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bcr_sq,
{ "SQ", "104asdu.bcr.sq", FT_UINT8, BASE_DEC, NULL, 0x1F,
"Sequence Number", HFILL }},
{ &hf_bcr_cy,
{ "CY", "104asdu.bcr.cy", FT_BOOLEAN, 8, TFS(&tfs_overflow_no_overflow), 0x20,
"Counter Overflow", HFILL }},
{ &hf_bcr_ca,
{ "CA", "104asdu.bcr.ca", FT_BOOLEAN, 8, TFS(&tfs_adjusted_not_adjusted), 0x40,
"Counter Adjusted", HFILL }},
{ &hf_bcr_iv,
{ "IV", "104asdu.bcr.iv", FT_BOOLEAN, 8, TFS(&tfs_invalid_valid), 0x80,
"Counter Validity", HFILL }},
{ &hf_start,
{ "START", "104asdu.start", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_asdu_bitstring,
{ "Value", "104asdu.bitstring", FT_UINT32, BASE_HEX, NULL, 0x0,
"BSI value", HFILL }},
{ &hf_asdu_float,
{ "Value", "104asdu.float", FT_FLOAT, BASE_NONE, NULL, 0x0,
"Float value", HFILL }},
{ &hf_asdu_normval,
{ "Value", "104asdu.normval", FT_FLOAT, BASE_NONE, NULL, 0x0,
"Normalised value", HFILL }},
{ &hf_asdu_scalval,
{ "Value", "104asdu.scalval", FT_INT16, BASE_DEC, NULL, 0x0,
"Scaled value", HFILL }},
};
static gint *ett_as[] = {
&ett_asdu,
&ett_asdu_objects,
&ett_siq,
&ett_diq,
&ett_qds,
&ett_qos,
&ett_vti,
&ett_sco,
&ett_dco,
&ett_rco,
&ett_cp56time
};
static ei_register_info ei[] = {
{ &ei_iec104_short_asdu, { "iec104.short_asdu", PI_MALFORMED, PI_ERROR, "<ERR Short Asdu>", EXPFILL }},
{ &ei_iec104_apdu_min_len, { "iec104.apdu_min_len", PI_MALFORMED, PI_ERROR, "APDU less than bytes", EXPFILL }},
};
expert_module_t* expert_iec104;
proto_iec104asdu = proto_register_protocol(
"IEC 60870-5-104-Asdu",
"104asdu",
"104asdu"
);
proto_register_field_array(proto_iec104asdu, hf_as, array_length(hf_as));
proto_register_subtree_array(ett_as, array_length(ett_as));
expert_iec104 = expert_register_protocol(proto_iec104asdu);
expert_register_field_array(expert_iec104, ei, array_length(ei));
}
void
proto_reg_handoff_iec104(void)
{
static dissector_handle_t iec104apci_handle;
static gboolean iec104_prefs_initialized = FALSE;
static guint saved_iec104_port;
if (!iec104_prefs_initialized) {
iec104apci_handle = create_dissector_handle(dissect_iec104reas, proto_iec104apci);
iec104asdu_handle = create_dissector_handle(dissect_iec104asdu, proto_iec104asdu);
dissector_add_uint("tcp.port", iec104_port, iec104apci_handle);
} else {
dissector_delete_uint("tcp.port", saved_iec104_port, iec104apci_handle);
}
saved_iec104_port = iec104_port;
if (iec104_port != 0) {
dissector_add_uint("tcp.port", iec104_port, iec104apci_handle);
}
}
