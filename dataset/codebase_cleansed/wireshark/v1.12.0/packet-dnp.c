static gboolean
dl_conversation_equal(gconstpointer v, gconstpointer w)
{
const dl_conversation_key_t* v1 = (const dl_conversation_key_t*)v;
const dl_conversation_key_t* v2 = (const dl_conversation_key_t*)w;
if ((v1->conversation == v2->conversation) &&
(v1->src == v2->src) &&
(v1->dst == v2->dst))
{
return TRUE;
}
return FALSE;
}
static guint
dl_conversation_hash(gconstpointer v)
{
const dl_conversation_key_t *key = (const dl_conversation_key_t*)v;
guint val;
val = key->conversation + (key->src << 16) + key->dst;
return val;
}
static guint16
calculateCRC(const void *buf, guint len) {
guint16 crc = 0;
const guint8 *p = (const guint8 *)buf;
while (len-- > 0)
crc = crctable[(crc ^ *p++) & 0xff] ^ (crc >> 8);
return ~crc;
}
static gboolean
add_item_text(proto_item *item, const gchar *text, gboolean comma_needed)
{
if (comma_needed) {
proto_item_append_text(item, ", ");
}
proto_item_append_text(item, "%s", text);
return TRUE;
}
static void
dnp3_al_process_iin(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *al_tree)
{
guint16 al_iin;
proto_item *tiin;
proto_tree *iin_tree;
gboolean comma_needed = FALSE;
al_iin = tvb_get_ntohs(tvb, offset);
tiin = proto_tree_add_uint_format(al_tree, hf_dnp3_al_iin, tvb, offset, 2, al_iin,
"Internal Indications: ");
if (al_iin & AL_IIN_RST) comma_needed = add_item_text(tiin, "Device Restart", comma_needed);
if (al_iin & AL_IIN_DOL) comma_needed = add_item_text(tiin, "Outputs in Local", comma_needed);
if (al_iin & AL_IIN_DT) comma_needed = add_item_text(tiin, "Device Trouble", comma_needed);
if (al_iin & AL_IIN_TSR) comma_needed = add_item_text(tiin, "Time Sync Required", comma_needed);
if (al_iin & AL_IIN_CLS3D) comma_needed = add_item_text(tiin, "Class 3 Data Available", comma_needed);
if (al_iin & AL_IIN_CLS2D) comma_needed = add_item_text(tiin, "Class 2 Data Available", comma_needed);
if (al_iin & AL_IIN_CLS1D) comma_needed = add_item_text(tiin, "Class 1 Data Available", comma_needed);
if (al_iin & AL_IIN_BMSG) comma_needed = add_item_text(tiin, "Broadcast Message Rx'd", comma_needed);
if (al_iin & AL_IIN_CC) comma_needed = add_item_text(tiin, "Device Configuration Corrupt", comma_needed);
if (al_iin & AL_IIN_OAE) comma_needed = add_item_text(tiin, "Operation Already Executing", comma_needed);
if (al_iin & AL_IIN_EBO) comma_needed = add_item_text(tiin, "Event Buffer Overflow", comma_needed);
if (al_iin & AL_IIN_PIOOR) comma_needed = add_item_text(tiin, "Parameters Invalid or Out of Range", comma_needed);
if (al_iin & AL_IIN_OBJU) comma_needed = add_item_text(tiin, "Requested Objects Unknown", comma_needed);
if (al_iin & AL_IIN_FCNI) add_item_text(tiin, "Function code not implemented", comma_needed);
proto_item_append_text(tiin, " (0x%04x)", al_iin);
if ((al_iin & AL_IIN_DT) || (al_iin & AL_IIN_CC) || (al_iin & AL_IIN_OAE) || (al_iin & AL_IIN_EBO) ||
(al_iin & AL_IIN_PIOOR) || (al_iin & AL_IIN_OBJU) || (al_iin & AL_IIN_FCNI)) {
expert_add_info(pinfo, tiin, &ei_dnp_iin_abnormal);
}
iin_tree = proto_item_add_subtree(tiin, ett_dnp3_al_iin);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_rst, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_dt, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_dol, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_tsr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_cls3d, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_cls2d, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_cls1d, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_bmsg, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_cc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_oae, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_ebo, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_pioor, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_obju, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iin_tree, hf_dnp3_al_iin_fcni, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static int
dnp3_al_obj_procindex(tvbuff_t *tvb, int offset, guint8 al_objq_index, guint32 *al_ptaddr, proto_tree *item_tree)
{
int indexbytes = 0;
proto_item *index_item;
switch (al_objq_index)
{
case AL_OBJQL_IDX_NI:
indexbytes = 0;
index_item = proto_tree_add_text(item_tree, tvb, offset, 0, "Point Index: %u", *al_ptaddr);
PROTO_ITEM_SET_GENERATED(index_item);
break;
case AL_OBJQL_IDX_1O:
*al_ptaddr = tvb_get_guint8(tvb, offset);
proto_tree_add_item(item_tree, hf_dnp3_al_index8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
indexbytes = 1;
break;
case AL_OBJQL_IDX_2O:
*al_ptaddr = tvb_get_letohs(tvb, offset);
proto_tree_add_item(item_tree, hf_dnp3_al_index16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
indexbytes = 2;
break;
case AL_OBJQL_IDX_4O:
*al_ptaddr = tvb_get_letohl(tvb, offset);
proto_tree_add_item(item_tree, hf_dnp3_al_index32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
indexbytes = 4;
break;
case AL_OBJQL_IDX_1OS:
*al_ptaddr = tvb_get_guint8(tvb, offset);
proto_tree_add_item(item_tree, hf_dnp3_al_size8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
indexbytes = 1;
break;
case AL_OBJQL_IDX_2OS:
*al_ptaddr = tvb_get_letohs(tvb, offset);
proto_tree_add_item(item_tree, hf_dnp3_al_size16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
indexbytes = 2;
break;
case AL_OBJQL_IDX_4OS:
*al_ptaddr = tvb_get_letohl(tvb, offset);
proto_tree_add_item(item_tree, hf_dnp3_al_size32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
indexbytes = 4;
break;
}
return indexbytes;
}
static void
dnp3_append_2item_text(proto_item *item1, proto_item *item2, const gchar *text)
{
proto_item_append_text(item1, "%s", text);
proto_item_append_text(item2, "%s", text);
}
static void
dnp3_al_obj_quality(tvbuff_t *tvb, int offset, guint8 al_ptflags, proto_tree *point_tree, proto_item *point_item, enum QUALITY_TYPE type)
{
proto_tree *quality_tree;
proto_item *quality_item;
int hf0 = 0, hf1 = 0, hf2 = 0, hf3 = 0, hf4 = 0, hf5 = 0, hf6 = 0, hf7 = 0;
proto_item_append_text(point_item, " (Quality: ");
quality_item = proto_tree_add_text(point_tree, tvb, offset, 1, "Quality: ");
quality_tree = proto_item_add_subtree(quality_item, ett_dnp3_al_obj_quality);
if (al_ptflags & AL_OBJ_BI_FLAG0) {
dnp3_append_2item_text(point_item, quality_item, "Online");
}
else {
dnp3_append_2item_text(point_item, quality_item, "Offline");
}
if (al_ptflags & AL_OBJ_BI_FLAG1) dnp3_append_2item_text(point_item, quality_item, ", Restart");
if (al_ptflags & AL_OBJ_BI_FLAG2) dnp3_append_2item_text(point_item, quality_item, ", Comm Fail");
if (al_ptflags & AL_OBJ_BI_FLAG3) dnp3_append_2item_text(point_item, quality_item, ", Remote Force");
if (al_ptflags & AL_OBJ_BI_FLAG4) dnp3_append_2item_text(point_item, quality_item, ", Local Force");
switch (type) {
case BIN_IN:
if (al_ptflags & AL_OBJ_BI_FLAG5) dnp3_append_2item_text(point_item, quality_item, ", Chatter Filter");
hf0 = hf_dnp3_al_biq_b0;
hf1 = hf_dnp3_al_biq_b1;
hf2 = hf_dnp3_al_biq_b2;
hf3 = hf_dnp3_al_biq_b3;
hf4 = hf_dnp3_al_biq_b4;
hf5 = hf_dnp3_al_biq_b5;
hf6 = hf_dnp3_al_biq_b6;
hf7 = hf_dnp3_al_biq_b7;
break;
case BIN_OUT:
hf0 = hf_dnp3_al_boq_b0;
hf1 = hf_dnp3_al_boq_b1;
hf2 = hf_dnp3_al_boq_b2;
hf3 = hf_dnp3_al_boq_b3;
hf4 = hf_dnp3_al_boq_b4;
hf5 = hf_dnp3_al_boq_b5;
hf6 = hf_dnp3_al_boq_b6;
hf7 = hf_dnp3_al_boq_b7;
break;
case ANA_IN:
if (al_ptflags & AL_OBJ_AI_FLAG5) dnp3_append_2item_text(point_item, quality_item, ", Over-Range");
if (al_ptflags & AL_OBJ_AI_FLAG6) dnp3_append_2item_text(point_item, quality_item, ", Reference Check");
hf0 = hf_dnp3_al_aiq_b0;
hf1 = hf_dnp3_al_aiq_b1;
hf2 = hf_dnp3_al_aiq_b2;
hf3 = hf_dnp3_al_aiq_b3;
hf4 = hf_dnp3_al_aiq_b4;
hf5 = hf_dnp3_al_aiq_b5;
hf6 = hf_dnp3_al_aiq_b6;
hf7 = hf_dnp3_al_aiq_b7;
break;
case ANA_OUT:
hf0 = hf_dnp3_al_aoq_b0;
hf1 = hf_dnp3_al_aoq_b1;
hf2 = hf_dnp3_al_aoq_b2;
hf3 = hf_dnp3_al_aoq_b3;
hf4 = hf_dnp3_al_aoq_b4;
hf5 = hf_dnp3_al_aoq_b5;
hf6 = hf_dnp3_al_aoq_b6;
hf7 = hf_dnp3_al_aoq_b7;
break;
case COUNTER:
if (al_ptflags & AL_OBJ_CTR_FLAG5) dnp3_append_2item_text(point_item, quality_item, ", Roll-over");
if (al_ptflags & AL_OBJ_CTR_FLAG6) dnp3_append_2item_text(point_item, quality_item, ", Discontinuity");
hf0 = hf_dnp3_al_ctrq_b0;
hf1 = hf_dnp3_al_ctrq_b1;
hf2 = hf_dnp3_al_ctrq_b2;
hf3 = hf_dnp3_al_ctrq_b3;
hf4 = hf_dnp3_al_ctrq_b4;
hf5 = hf_dnp3_al_ctrq_b5;
hf6 = hf_dnp3_al_ctrq_b6;
hf7 = hf_dnp3_al_ctrq_b7;
break;
}
if (quality_tree != NULL) {
proto_tree_add_item(quality_tree, hf7, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(quality_tree, hf6, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(quality_tree, hf5, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(quality_tree, hf4, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(quality_tree, hf3, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(quality_tree, hf2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(quality_tree, hf1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(quality_tree, hf0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
proto_item_append_text(point_item, ")");
}
static void
dnp3_al_get_timestamp(nstime_t *timestamp, tvbuff_t *tvb, int data_pos)
{
guint32 hi, lo;
guint64 time_ms;
lo = tvb_get_letohs(tvb, data_pos);
hi = tvb_get_letohl(tvb, data_pos + 2);
time_ms = (guint64)hi * 0x10000 + lo;
timestamp->secs = (long)(time_ms / 1000);
timestamp->nsecs = (int)(time_ms % 1000) * 1000000;
}
static int
dnp3_al_process_object(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *robj_tree, gboolean header_only,
guint16 *al_objtype, nstime_t *al_cto)
{
guint8 al_objq, al_objq_index, al_objq_code, al_oct_len = 0, bitindex;
guint16 al_obj, temp;
guint32 al_ptaddr = 0;
int num_items = 0;
int orig_offset, rangebytes = 0;
proto_item *object_item, *qualifier_item, *range_item;
proto_tree *object_tree, *qualifier_tree, *range_tree;
orig_offset = offset;
*al_objtype =
al_obj = tvb_get_ntohs(tvb, offset);
temp = al_obj & 0xFF00;
if ((temp == AL_OBJ_OCT) || (temp == AL_OBJ_OCT_EVT )) {
al_oct_len = al_obj & 0xFF;
al_obj = temp;
}
object_item = proto_tree_add_uint_format(robj_tree, hf_dnp3_al_obj, tvb, offset, 2, al_obj,
"Object(s): %s (0x%04x)",
val_to_str_ext_const(al_obj, &dnp3_al_obj_vals_ext, "Unknown Object - Abort Decoding..."),
al_obj);
object_tree = proto_item_add_subtree(object_item, ett_dnp3_al_obj);
offset += 2;
al_objq = tvb_get_guint8(tvb, offset);
al_objq_index = al_objq & AL_OBJQ_INDEX;
al_objq_index = al_objq_index >> 4;
al_objq_code = al_objq & AL_OBJQ_CODE;
qualifier_item = proto_tree_add_text(object_tree, tvb, offset, 1, "Qualifier Field, Prefix: %s, Code: %s",
val_to_str_ext_const(al_objq_index, &dnp3_al_objq_index_vals_ext, "Unknown Index Type"),
val_to_str_ext_const(al_objq_code, &dnp3_al_objq_code_vals_ext, "Unknown Code Type"));
qualifier_tree = proto_item_add_subtree(qualifier_item, ett_dnp3_al_obj_qualifier);
proto_tree_add_item(qualifier_tree, hf_dnp3_al_objq_index, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(qualifier_tree, hf_dnp3_al_objq_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
range_item = proto_tree_add_text(object_tree, tvb, offset, 0, "Number of Items: ");
range_tree = proto_item_add_subtree(range_item, ett_dnp3_al_obj_range);
switch (al_objq_code)
{
case AL_OBJQL_CODE_SSI8:
num_items = ( tvb_get_guint8(tvb, offset+1) - tvb_get_guint8(tvb, offset) + 1);
PROTO_ITEM_SET_GENERATED(range_item);
al_ptaddr = tvb_get_guint8(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_start8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(range_tree, hf_dnp3_al_range_stop8, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
rangebytes = 2;
break;
case AL_OBJQL_CODE_SSI16:
num_items = ( tvb_get_letohs(tvb, offset+2) - tvb_get_letohs(tvb, (offset)) + 1);
PROTO_ITEM_SET_GENERATED(range_item);
al_ptaddr = tvb_get_letohs(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_start16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(range_tree, hf_dnp3_al_range_stop16, tvb, offset + 2, 2, ENC_LITTLE_ENDIAN);
rangebytes = 4;
break;
case AL_OBJQL_CODE_SSI32:
num_items = ( tvb_get_letohl(tvb, offset+4) - tvb_get_letohl(tvb, offset) + 1);
PROTO_ITEM_SET_GENERATED(range_item);
al_ptaddr = tvb_get_letohl(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_start32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(range_tree, hf_dnp3_al_range_stop32, tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
rangebytes = 8;
break;
case AL_OBJQL_CODE_AA8:
num_items = 1;
PROTO_ITEM_SET_GENERATED(range_item);
al_ptaddr = tvb_get_guint8(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_abs8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
rangebytes = 1;
break;
case AL_OBJQL_CODE_AA16:
num_items = 1;
PROTO_ITEM_SET_GENERATED(range_item);
al_ptaddr = tvb_get_letohs(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_abs16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
rangebytes = 2;
break;
case AL_OBJQL_CODE_AA32:
num_items = 1;
PROTO_ITEM_SET_GENERATED(range_item);
al_ptaddr = tvb_get_letohl(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_abs32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
rangebytes = 4;
break;
case AL_OBJQL_CODE_SF8:
num_items = tvb_get_guint8(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_quant8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
rangebytes = 1;
proto_item_set_len(range_item, rangebytes);
break;
case AL_OBJQL_CODE_SF16:
num_items = tvb_get_letohs(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_quant16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
rangebytes = 2;
proto_item_set_len(range_item, rangebytes);
break;
case AL_OBJQL_CODE_SF32:
num_items = tvb_get_letohl(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_quant32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
rangebytes = 4;
proto_item_set_len(range_item, rangebytes);
break;
case AL_OBJQL_CODE_FF:
num_items = tvb_get_guint8(tvb, offset);
proto_tree_add_item(range_tree, hf_dnp3_al_range_quant8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
rangebytes = 1;
proto_item_set_len(range_item, rangebytes);
}
if (num_items > 0) {
proto_item_append_text(object_item, ", %d point%s", num_items, plurality(num_items, "", "s"));
}
proto_item_append_text(range_item, "%d", num_items);
if (num_items < 0) {
proto_item_append_text(range_item, " (bogus)");
expert_add_info(pinfo, range_item, &ei_dnp_num_items_neg);
return tvb_length(tvb);
}
offset += rangebytes;
bitindex = 0;
if (!header_only || al_objq_index > 0) {
int item_num;
int start_offset;
start_offset = offset;
for (item_num = 0; item_num < num_items; item_num++)
{
proto_item *point_item;
proto_tree *point_tree;
guint data_pos;
int indexbytes;
if (al_objq_index <= AL_OBJQL_IDX_4O)
point_item = proto_tree_add_text(object_tree, tvb, offset, -1, "Point Number");
else
point_item = proto_tree_add_text(object_tree, tvb, offset, -1, "Object: Size");
point_tree = proto_item_add_subtree(point_item, ett_dnp3_al_obj_point);
data_pos = offset;
indexbytes = dnp3_al_obj_procindex(tvb, offset, al_objq_index, &al_ptaddr, point_tree);
proto_item_append_text(point_item, " %u", al_ptaddr);
proto_item_set_len(point_item, indexbytes);
data_pos += indexbytes;
if (!header_only || (AL_OBJQL_IDX_1OS <= al_objq_index && al_objq_index <= AL_OBJQL_IDX_4OS)) {
guint8 al_2bit, al_ptflags, al_ctlobj_count, al_bi_val, al_tcc_code, da_len;
gint16 al_val_int16;
guint16 al_val_uint16, al_ctlobj_stat;
guint16 al_relms, al_filename_offs, al_filename_len, al_file_ctrl_mode;
gint32 al_val_int32;
guint32 al_val_uint32, al_ctlobj_on, al_ctlobj_off, file_data_size;
nstime_t al_reltime, al_abstime;
gboolean al_bit;
gfloat al_valflt;
gdouble al_valdbl;
const gchar *ctl_status_str;
switch (al_obj)
{
case AL_OBJ_BI_ALL:
case AL_OBJ_BIC_ALL:
case AL_OBJ_BOC_ALL:
case AL_OBJ_2BI_ALL:
case AL_OBJ_2BIC_ALL:
case AL_OBJ_CTR_ALL:
case AL_OBJ_CTRC_ALL:
case AL_OBJ_AI_ALL:
case AL_OBJ_AIC_ALL:
case AL_OBJ_AIDB_ALL:
case AL_OBJ_AOC_ALL:
offset = data_pos;
break;
case AL_OBJ_DA_MSTR_DSP:
case AL_OBJ_DA_OS_DSP:
case AL_OBJ_DA_MSTR_DS:
case AL_OBJ_DA_OS_DS:
case AL_OBJ_DA_BO_REQ:
case AL_OBJ_DA_LOC_TA:
case AL_OBJ_DA_DUR_TA:
case AL_OBJ_DA_AO_EVT:
case AL_OBJ_DA_MAX_AO:
case AL_OBJ_DA_NUM_AO:
case AL_OBJ_DA_BO_EVT:
case AL_OBJ_DA_MAX_BO:
case AL_OBJ_DA_NUM_BO:
case AL_OBJ_DA_FCTR_EVT:
case AL_OBJ_DA_FCTR:
case AL_OBJ_DA_CTR_EVT:
case AL_OBJ_DA_MAX_CTR:
case AL_OBJ_DA_NUM_CTR:
case AL_OBJ_DA_AIF:
case AL_OBJ_DA_AI_EVT:
case AL_OBJ_DA_MAX_AI:
case AL_OBJ_DA_NUM_AI:
case AL_OBJ_DA_2BI_EVT:
case AL_OBJ_DA_MAX_2BI:
case AL_OBJ_DA_NUM_2BI:
case AL_OBJ_DA_BI_EVT:
case AL_OBJ_DA_MAX_BI:
case AL_OBJ_DA_NUM_BI:
case AL_OBJ_DA_MXTX_FR:
case AL_OBJ_DA_MXRX_FR:
proto_tree_add_item(point_tree, hf_dnp3_al_datatype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
da_len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(point_tree, hf_dnp3_al_da_length, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
if (da_len == 1) {
proto_tree_add_item(point_tree, hf_dnp3_al_da_int8, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(object_item, ", Value: %u", tvb_get_guint8(tvb, offset+2));
}
else if (da_len == 4) {
proto_tree_add_item(point_tree, hf_dnp3_al_da_int32, tvb, offset+2, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(object_item, ", Value: %u", tvb_get_letohl(tvb, offset+2));
}
offset += 2 + da_len;
break;
case AL_OBJ_DA_USR_ATTR:
case AL_OBJ_DA_SWVER:
case AL_OBJ_DA_HWVER:
case AL_OBJ_DA_LOC:
case AL_OBJ_DA_ID:
case AL_OBJ_DA_DEVNAME:
case AL_OBJ_DA_SERNUM:
case AL_OBJ_DA_CONF:
case AL_OBJ_DA_PROD:
case AL_OBJ_DA_MFG:
proto_tree_add_item(point_tree, hf_dnp3_al_datatype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
da_len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(point_tree, hf_dnp3_al_da_length, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_text(point_tree, tvb, offset+2, da_len, "Value: %s", tvb_get_string(wmem_packet_scope(), tvb, offset+2, da_len));
proto_item_append_text(object_item, ", Value: %s", tvb_get_string(wmem_packet_scope(), tvb, offset+2, da_len));
offset += 2 + da_len;
break;
case AL_OBJ_BI_1BIT:
case AL_OBJ_BO:
case AL_OBJ_IIN:
if (bitindex > 7)
{
bitindex = 0;
offset += (indexbytes + 1);
}
al_bi_val = tvb_get_guint8(tvb, offset);
al_bit = (al_bi_val & (1 << bitindex)) > 0;
if (al_obj == AL_OBJ_IIN) {
guint16 iin_bit = 0;
if (al_ptaddr < 8) {
iin_bit = 0x100 << al_ptaddr;
}
else {
iin_bit = 1 << (al_ptaddr - 8);
}
proto_item_append_text(point_item, " (%s), Value: %u",
val_to_str_const(iin_bit, dnp3_al_iin_vals, "Invalid IIN bit"), al_bit);
}
else {
proto_item_append_text(point_item, ", Value: %u", al_bit);
}
proto_tree_add_boolean(point_tree, hf_dnp3_al_bit, tvb, offset, 1, al_bit);
proto_item_set_len(point_item, indexbytes + 1);
if (item_num == (num_items-1))
{
offset += (indexbytes + 1);
}
break;
case AL_OBJ_2BI_NF:
if (bitindex > 3)
{
bitindex = 0;
offset += (indexbytes + 1);
}
al_bi_val = tvb_get_guint8(tvb, offset);
al_2bit = ((al_bi_val >> (bitindex << 1)) & 3);
proto_item_append_text(point_item, ", Value: %u", al_2bit);
proto_tree_add_uint(point_tree, hf_dnp3_al_2bit, tvb, offset, 1, al_2bit);
proto_item_set_len(point_item, indexbytes + 1);
if (item_num == (num_items-1))
{
offset += (indexbytes + 1);
}
break;
case AL_OBJ_BI_STAT:
case AL_OBJ_BIC_NOTIME:
case AL_OBJ_BO_STAT:
case AL_OBJ_BOC_NOTIME:
al_ptflags = tvb_get_guint8(tvb, data_pos);
switch (al_obj) {
case AL_OBJ_BI_STAT:
case AL_OBJ_BIC_NOTIME:
dnp3_al_obj_quality(tvb, data_pos, al_ptflags, point_tree, point_item, BIN_IN);
break;
case AL_OBJ_BO_STAT:
case AL_OBJ_BOC_NOTIME:
dnp3_al_obj_quality(tvb, data_pos, al_ptflags, point_tree, point_item, BIN_OUT);
break;
}
data_pos += 1;
al_bit = (al_ptflags & AL_OBJ_BI_FLAG7) > 0;
proto_item_append_text(point_item, ", Value: %u", al_bit);
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_2BI_STAT:
case AL_OBJ_2BIC_NOTIME:
al_ptflags = tvb_get_guint8(tvb, data_pos);
dnp3_al_obj_quality(tvb, data_pos, al_ptflags, point_tree, point_item, BIN_IN);
data_pos += 1;
al_2bit = (al_ptflags >> 6) & 3;
proto_item_append_text(point_item, ", Value: %u", al_2bit);
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_BIC_TIME:
case AL_OBJ_BOC_TIME:
al_ptflags = tvb_get_guint8(tvb, data_pos);
switch (al_obj) {
case AL_OBJ_BIC_TIME:
dnp3_al_obj_quality(tvb, data_pos, al_ptflags, point_tree, point_item, BIN_IN);
break;
case AL_OBJ_BOC_TIME:
dnp3_al_obj_quality(tvb, data_pos, al_ptflags, point_tree, point_item, BIN_OUT);
break;
}
data_pos += 1;
dnp3_al_get_timestamp(&al_abstime, tvb, data_pos);
proto_tree_add_time(point_tree, hf_dnp3_al_timestamp, tvb, data_pos, 6, &al_abstime);
data_pos += 6;
al_bit = (al_ptflags & AL_OBJ_BI_FLAG7) >> 7;
proto_item_append_text(point_item, ", Value: %u, Timestamp: %s",
al_bit, abs_time_to_ep_str(&al_abstime, ABSOLUTE_TIME_UTC, FALSE));
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_2BIC_TIME:
al_ptflags = tvb_get_guint8(tvb, data_pos);
dnp3_al_obj_quality(tvb, (offset+indexbytes), al_ptflags, point_tree, point_item, BIN_IN);
data_pos += 1;
dnp3_al_get_timestamp(&al_abstime, tvb, data_pos);
proto_tree_add_time(point_tree, hf_dnp3_al_timestamp, tvb, data_pos, 6, &al_abstime);
data_pos += 6;
al_2bit = (al_ptflags >> 6) & 3;
proto_item_append_text(point_item, ", Value: %u, Timestamp: %s",
al_2bit, abs_time_to_ep_str(&al_abstime, ABSOLUTE_TIME_UTC, FALSE));
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_BIC_RTIME:
al_ptflags = tvb_get_guint8(tvb, data_pos);
dnp3_al_obj_quality(tvb, data_pos, al_ptflags, point_tree, point_item, BIN_IN);
data_pos += 1;
al_relms = tvb_get_letohs(tvb, data_pos);
al_reltime.secs = al_relms / 1000;
al_reltime.nsecs = (al_relms % 1000) * 1000;
nstime_sum(&al_abstime, al_cto, &al_reltime);
proto_tree_add_time(point_tree, hf_dnp3_al_rel_timestamp, tvb, data_pos, 2, &al_reltime);
data_pos += 2;
al_bit = (al_ptflags & AL_OBJ_BI_FLAG7) >> 7;
proto_item_append_text(point_item, ", Value: %u, Timestamp: %s",
al_bit, abs_time_to_ep_str(&al_abstime, ABSOLUTE_TIME_UTC, FALSE));
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_CTLOP_BLK:
{
proto_item *tcc_item;
proto_tree *tcc_tree;
al_tcc_code = tvb_get_guint8(tvb, data_pos);
tcc_item = proto_tree_add_text(point_tree, tvb, data_pos, 1, "Control Code [0x%02x]",al_tcc_code);
tcc_tree = proto_item_add_subtree(tcc_item, ett_dnp3_al_obj_point_tcc);
proto_item_append_text(point_item, " [%s]", val_to_str_const((al_tcc_code & AL_OBJCTLC_CODE),
dnp3_al_ctlc_code_vals,
"Invalid Operation"));
proto_item_append_text(point_item, " [%s]", val_to_str_const((al_tcc_code & AL_OBJCTLC_TC) >> 6,
dnp3_al_ctlc_tc_vals,
"Invalid Qualifier"));
proto_tree_add_item(tcc_tree, hf_dnp3_ctlobj_code_c, tvb, data_pos, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tcc_tree, hf_dnp3_ctlobj_code_m, tvb, data_pos, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tcc_tree, hf_dnp3_ctlobj_code_tc, tvb, data_pos, 1, ENC_LITTLE_ENDIAN);
data_pos += 1;
al_ctlobj_count = tvb_get_guint8(tvb, data_pos);
data_pos += 1;
al_ctlobj_on = tvb_get_letohl(tvb, data_pos);
data_pos += 4;
al_ctlobj_off = tvb_get_letohl(tvb, data_pos);
data_pos += 4;
proto_tree_add_text(point_tree, tvb, data_pos - 9, 9,
"[Count: %u] [On-Time: %u] [Off-Time: %u]",
al_ctlobj_count, al_ctlobj_on, al_ctlobj_off);
proto_tree_add_item(point_tree, hf_dnp3_al_ctrlstatus, tvb, data_pos, 1, ENC_LITTLE_ENDIAN);
data_pos += 1;
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
}
case AL_OBJ_AO_32OPB:
case AL_OBJ_AO_16OPB:
case AL_OBJ_AO_FLTOPB:
case AL_OBJ_AO_DBLOPB:
switch (al_obj)
{
case AL_OBJ_AO_32OPB:
al_val_int32 = tvb_get_letohl(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %d", al_val_int32);
proto_tree_add_item(point_tree, hf_dnp3_al_anaout32, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
break;
case AL_OBJ_AO_16OPB:
al_val_int16 = tvb_get_letohs(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %d", al_val_int16);
proto_tree_add_item(point_tree, hf_dnp3_al_anaout16, tvb, data_pos, 2, ENC_LITTLE_ENDIAN);
data_pos += 2;
break;
case AL_OBJ_AO_FLTOPB:
al_valflt = tvb_get_letohieee_float(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %g", al_valflt);
proto_tree_add_item(point_tree, hf_dnp3_al_anaoutflt, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
break;
case AL_OBJ_AO_DBLOPB:
al_valdbl = tvb_get_letohieee_double(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %g", al_valdbl);
proto_tree_add_item(point_tree, hf_dnp3_al_anaoutdbl, tvb, data_pos, 8, ENC_LITTLE_ENDIAN);
data_pos += 8;
break;
}
al_ctlobj_stat = tvb_get_guint8(tvb, data_pos);
ctl_status_str = val_to_str_ext(al_ctlobj_stat, &dnp3_al_ctl_status_vals_ext, "Invalid Status (0x%02x)");
proto_item_append_text(point_item, " [Status: %s (0x%02x)]", ctl_status_str, al_ctlobj_stat);
proto_tree_add_item(point_tree, hf_dnp3_al_ctrlstatus, tvb, data_pos, 1, ENC_LITTLE_ENDIAN);
data_pos += 1;
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_CTR_32:
case AL_OBJ_CTR_16:
case AL_OBJ_DCTR_32:
case AL_OBJ_DCTR_16:
case AL_OBJ_CTR_32NF:
case AL_OBJ_CTR_16NF:
case AL_OBJ_DCTR_32NF:
case AL_OBJ_DCTR_16NF:
case AL_OBJ_FCTR_32:
case AL_OBJ_FCTR_16:
case AL_OBJ_FDCTR_32:
case AL_OBJ_FDCTR_16:
case AL_OBJ_FCTR_32T:
case AL_OBJ_FCTR_16T:
case AL_OBJ_FDCTR_32T:
case AL_OBJ_FDCTR_16T:
case AL_OBJ_FCTR_32NF:
case AL_OBJ_FCTR_16NF:
case AL_OBJ_FDCTR_32NF:
case AL_OBJ_FDCTR_16NF:
case AL_OBJ_CTRC_32:
case AL_OBJ_CTRC_16:
case AL_OBJ_DCTRC_32:
case AL_OBJ_DCTRC_16:
case AL_OBJ_CTRC_32T:
case AL_OBJ_CTRC_16T:
case AL_OBJ_DCTRC_32T:
case AL_OBJ_DCTRC_16T:
case AL_OBJ_FCTRC_32:
case AL_OBJ_FCTRC_16:
case AL_OBJ_FDCTRC_32:
case AL_OBJ_FDCTRC_16:
case AL_OBJ_FCTRC_32T:
case AL_OBJ_FCTRC_16T:
case AL_OBJ_FDCTRC_32T:
case AL_OBJ_FDCTRC_16T:
switch (al_obj)
{
case AL_OBJ_CTR_32NF:
case AL_OBJ_CTR_16NF:
case AL_OBJ_DCTR_32NF:
case AL_OBJ_DCTR_16NF:
case AL_OBJ_FCTR_32NF:
case AL_OBJ_FCTR_16NF:
case AL_OBJ_FDCTR_32NF:
case AL_OBJ_FDCTR_16NF:
break;
default:
al_ptflags = tvb_get_guint8(tvb, data_pos);
dnp3_al_obj_quality(tvb, data_pos, al_ptflags, point_tree, point_item, COUNTER);
data_pos += 1;
break;
}
switch (al_obj)
{
case AL_OBJ_CTR_32:
case AL_OBJ_DCTR_32:
case AL_OBJ_CTR_32NF:
case AL_OBJ_DCTR_32NF:
case AL_OBJ_FCTR_32:
case AL_OBJ_FDCTR_32:
case AL_OBJ_FCTR_32T:
case AL_OBJ_FDCTR_32T:
case AL_OBJ_FCTR_32NF:
case AL_OBJ_FDCTR_32NF:
case AL_OBJ_CTRC_32:
case AL_OBJ_DCTRC_32:
case AL_OBJ_CTRC_32T:
case AL_OBJ_DCTRC_32T:
case AL_OBJ_FCTRC_32:
case AL_OBJ_FDCTRC_32:
case AL_OBJ_FCTRC_32T:
case AL_OBJ_FDCTRC_32T:
al_val_uint32 = tvb_get_letohl(tvb, data_pos);
proto_item_append_text(point_item, ", Count: %u", al_val_uint32);
proto_tree_add_item(point_tree, hf_dnp3_al_cnt32, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
break;
case AL_OBJ_CTR_16:
case AL_OBJ_DCTR_16:
case AL_OBJ_CTR_16NF:
case AL_OBJ_DCTR_16NF:
case AL_OBJ_FCTR_16:
case AL_OBJ_FDCTR_16:
case AL_OBJ_FCTR_16T:
case AL_OBJ_FDCTR_16T:
case AL_OBJ_FCTR_16NF:
case AL_OBJ_FDCTR_16NF:
case AL_OBJ_CTRC_16:
case AL_OBJ_DCTRC_16:
case AL_OBJ_CTRC_16T:
case AL_OBJ_DCTRC_16T:
case AL_OBJ_FCTRC_16:
case AL_OBJ_FDCTRC_16:
case AL_OBJ_FCTRC_16T:
case AL_OBJ_FDCTRC_16T:
al_val_uint16 = tvb_get_letohs(tvb, data_pos);
proto_item_append_text(point_item, ", Count: %u", al_val_uint16);
proto_tree_add_item(point_tree, hf_dnp3_al_cnt16, tvb, data_pos, 2, ENC_LITTLE_ENDIAN);
data_pos += 2;
break;
}
switch (al_obj)
{
case AL_OBJ_FCTR_32T:
case AL_OBJ_FCTR_16T:
case AL_OBJ_FDCTR_32T:
case AL_OBJ_FDCTR_16T:
case AL_OBJ_CTRC_32T:
case AL_OBJ_CTRC_16T:
case AL_OBJ_DCTRC_32T:
case AL_OBJ_DCTRC_16T:
case AL_OBJ_FCTRC_32T:
case AL_OBJ_FCTRC_16T:
case AL_OBJ_FDCTRC_32T:
case AL_OBJ_FDCTRC_16T:
dnp3_al_get_timestamp(&al_abstime, tvb, data_pos);
proto_item_append_text(point_item, ", Timestamp: %s", abs_time_to_ep_str(&al_abstime, ABSOLUTE_TIME_UTC, FALSE));
proto_tree_add_time(point_tree, hf_dnp3_al_timestamp, tvb, data_pos, 6, &al_abstime);
data_pos += 6;
break;
}
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_AI_32:
case AL_OBJ_AI_16:
case AL_OBJ_AI_32NF:
case AL_OBJ_AI_16NF:
case AL_OBJ_AI_FLT:
case AL_OBJ_AI_DBL:
case AL_OBJ_AIF_FLT:
case AL_OBJ_AIF_DBL:
case AL_OBJ_AIC_32NT:
case AL_OBJ_AIC_16NT:
case AL_OBJ_AIC_32T:
case AL_OBJ_AIC_16T:
case AL_OBJ_AIC_FLTNT:
case AL_OBJ_AIC_DBLNT:
case AL_OBJ_AIC_FLTT:
case AL_OBJ_AIC_DBLT:
case AL_OBJ_AIFC_FLTNT:
case AL_OBJ_AIFC_DBLNT:
case AL_OBJ_AIFC_FLTT:
case AL_OBJ_AIFC_DBLT:
case AL_OBJ_AIDB_16:
case AL_OBJ_AIDB_32:
case AL_OBJ_AIDB_FLT:
switch (al_obj)
{
case AL_OBJ_AI_32NF:
case AL_OBJ_AI_16NF:
case AL_OBJ_AIDB_16:
case AL_OBJ_AIDB_32:
case AL_OBJ_AIDB_FLT:
break;
default:
al_ptflags = tvb_get_guint8(tvb, data_pos);
dnp3_al_obj_quality(tvb, data_pos, al_ptflags, point_tree, point_item, ANA_IN);
data_pos += 1;
break;
}
switch (al_obj)
{
case AL_OBJ_AI_32:
case AL_OBJ_AI_32NF:
case AL_OBJ_AIC_32NT:
case AL_OBJ_AIC_32T:
case AL_OBJ_AIDB_32:
al_val_int32 = tvb_get_letohl(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %d", al_val_int32);
proto_tree_add_item(point_tree, hf_dnp3_al_ana32, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
break;
case AL_OBJ_AI_16:
case AL_OBJ_AI_16NF:
case AL_OBJ_AIC_16NT:
case AL_OBJ_AIC_16T:
case AL_OBJ_AIDB_16:
al_val_int16 = tvb_get_letohs(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %d", al_val_int16);
proto_tree_add_item(point_tree, hf_dnp3_al_ana16, tvb, data_pos, 2, ENC_LITTLE_ENDIAN);
data_pos += 2;
break;
case AL_OBJ_AI_FLT:
case AL_OBJ_AIF_FLT:
case AL_OBJ_AIC_FLTNT:
case AL_OBJ_AIC_FLTT:
case AL_OBJ_AIFC_FLTNT:
case AL_OBJ_AIFC_FLTT:
case AL_OBJ_AIDB_FLT:
al_valflt = tvb_get_letohieee_float(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %g", al_valflt);
proto_tree_add_item(point_tree, hf_dnp3_al_anaflt, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
break;
case AL_OBJ_AI_DBL:
case AL_OBJ_AIF_DBL:
case AL_OBJ_AIC_DBLNT:
case AL_OBJ_AIC_DBLT:
case AL_OBJ_AIFC_DBLNT:
case AL_OBJ_AIFC_DBLT:
al_valdbl = tvb_get_letohieee_double(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %g", al_valdbl);
proto_tree_add_item(point_tree, hf_dnp3_al_anadbl, tvb, data_pos, 8, ENC_LITTLE_ENDIAN);
data_pos += 8;
break;
}
switch (al_obj)
{
case AL_OBJ_AIC_32T:
case AL_OBJ_AIC_16T:
case AL_OBJ_AIC_FLTT:
case AL_OBJ_AIC_DBLT:
case AL_OBJ_AIFC_FLTT:
case AL_OBJ_AIFC_DBLT:
dnp3_al_get_timestamp(&al_abstime, tvb, data_pos);
proto_item_append_text(point_item, ", Timestamp: %s", abs_time_to_ep_str(&al_abstime, ABSOLUTE_TIME_UTC, FALSE));
proto_tree_add_time(point_tree, hf_dnp3_al_timestamp, tvb, data_pos, 6, &al_abstime);
data_pos += 6;
break;
}
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_AO_32:
case AL_OBJ_AO_16:
case AL_OBJ_AO_FLT:
case AL_OBJ_AO_DBL:
case AL_OBJ_AOC_32NT:
case AL_OBJ_AOC_16NT:
case AL_OBJ_AOC_32T:
case AL_OBJ_AOC_16T:
case AL_OBJ_AOC_FLTNT:
case AL_OBJ_AOC_DBLNT:
case AL_OBJ_AOC_FLTT:
case AL_OBJ_AOC_DBLT:
al_ptflags = tvb_get_guint8(tvb, data_pos);
dnp3_al_obj_quality(tvb, data_pos, al_ptflags, point_tree, point_item, ANA_OUT);
data_pos += 1;
switch (al_obj)
{
case AL_OBJ_AO_32:
case AL_OBJ_AOC_32NT:
case AL_OBJ_AOC_32T:
al_val_int32 = tvb_get_letohl(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %d", al_val_int32);
proto_tree_add_item(point_tree, hf_dnp3_al_anaout32, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
break;
case AL_OBJ_AO_16:
case AL_OBJ_AOC_16NT:
case AL_OBJ_AOC_16T:
al_val_int16 = tvb_get_letohs(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %d", al_val_int16);
proto_tree_add_item(point_tree, hf_dnp3_al_anaout16, tvb, data_pos, 2, ENC_LITTLE_ENDIAN);
data_pos += 2;
break;
case AL_OBJ_AO_FLT:
case AL_OBJ_AOC_FLTNT:
case AL_OBJ_AOC_FLTT:
al_valflt = tvb_get_letohieee_float(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %g", al_valflt);
proto_tree_add_item(point_tree, hf_dnp3_al_anaoutflt, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
break;
case AL_OBJ_AO_DBL:
case AL_OBJ_AOC_DBLNT:
case AL_OBJ_AOC_DBLT:
al_valdbl = tvb_get_letohieee_double(tvb, data_pos);
proto_item_append_text(point_item, ", Value: %g", al_valdbl);
proto_tree_add_item(point_tree, hf_dnp3_al_anaoutdbl, tvb, data_pos, 8, ENC_LITTLE_ENDIAN);
data_pos += 8;
break;
}
switch (al_obj)
{
case AL_OBJ_AOC_32T:
case AL_OBJ_AOC_16T:
case AL_OBJ_AOC_FLTT:
case AL_OBJ_AOC_DBLT:
dnp3_al_get_timestamp(&al_abstime, tvb, data_pos);
proto_item_append_text(point_item, ", Timestamp: %s", abs_time_to_ep_str(&al_abstime, ABSOLUTE_TIME_UTC, FALSE));
proto_tree_add_time(point_tree, hf_dnp3_al_timestamp, tvb, data_pos, 6, &al_abstime);
data_pos += 6;
break;
}
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_TD:
case AL_OBJ_TDR:
case AL_OBJ_TDCTO:
dnp3_al_get_timestamp(&al_abstime, tvb, data_pos);
proto_tree_add_time(object_tree, hf_dnp3_al_timestamp, tvb, data_pos, 6, &al_abstime);
data_pos += 6;
proto_item_set_len(point_item, data_pos - offset);
if (al_obj == AL_OBJ_TDCTO) {
nstime_copy(al_cto, &al_abstime);
}
offset = data_pos;
break;
case AL_OBJ_TDELAYF:
al_val_uint16 = tvb_get_letohs(tvb, data_pos);
proto_tree_add_text(object_tree, tvb, data_pos, 2, "Time Delay: %u ms", al_val_uint16);
data_pos += 2;
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_CLASS0:
case AL_OBJ_CLASS1:
case AL_OBJ_CLASS2:
case AL_OBJ_CLASS3:
offset = data_pos;
break;
case AL_OBJ_FILE_CMD:
al_filename_offs = tvb_get_letohs(tvb, data_pos);
proto_tree_add_text(point_tree, tvb, data_pos, 2, "File String Offset: %u", al_filename_offs);
data_pos += 2;
al_filename_len = tvb_get_letohs(tvb, data_pos);
proto_tree_add_text(point_tree, tvb, data_pos, 2, "File String Length: %u", al_filename_len);
data_pos += 2;
al_file_ctrl_mode = tvb_get_letohs(tvb, data_pos + 16);
if (al_file_ctrl_mode == AL_OBJ_FILE_MODE_WRITE) {
dnp3_al_get_timestamp(&al_abstime, tvb, data_pos);
proto_tree_add_time(point_tree, hf_dnp3_al_timestamp, tvb, data_pos, 6, &al_abstime);
}
data_pos += 6;
if (al_file_ctrl_mode == AL_OBJ_FILE_MODE_WRITE) {
proto_item *perms_item;
proto_tree *perms_tree;
perms_item = proto_tree_add_item(point_tree, hf_dnp3_al_file_perms, tvb, offset, 2, ENC_LITTLE_ENDIAN);
perms_tree = proto_item_add_subtree(perms_item, ett_dnp3_al_obj_point_perms);
proto_tree_add_item(perms_tree, hf_dnp3_al_file_perms_read_owner, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(perms_tree, hf_dnp3_al_file_perms_write_owner, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(perms_tree, hf_dnp3_al_file_perms_exec_owner, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(perms_tree, hf_dnp3_al_file_perms_read_group, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(perms_tree, hf_dnp3_al_file_perms_write_group, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(perms_tree, hf_dnp3_al_file_perms_exec_group, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(perms_tree, hf_dnp3_al_file_perms_read_world, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(perms_tree, hf_dnp3_al_file_perms_write_world, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(perms_tree, hf_dnp3_al_file_perms_exec_world, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
data_pos += 2;
proto_tree_add_item(point_tree, hf_dnp3_al_file_auth, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
if (al_file_ctrl_mode == AL_OBJ_FILE_MODE_WRITE || al_file_ctrl_mode == AL_OBJ_FILE_MODE_APPEND) {
proto_tree_add_item(point_tree, hf_dnp3_al_file_size, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
}
data_pos += 4;
proto_tree_add_item(point_tree, hf_dnp3_al_file_mode, tvb, data_pos, 2, ENC_LITTLE_ENDIAN);
data_pos += 2;
proto_tree_add_item(point_tree, hf_dnp3_al_file_maxblk, tvb, data_pos, 2, ENC_LITTLE_ENDIAN);
data_pos += 2;
proto_tree_add_item(point_tree, hf_dnp3_al_file_reqID, tvb, data_pos, 2, ENC_LITTLE_ENDIAN);
data_pos += 2;
if (al_filename_len > 0) {
const gchar *al_filename;
al_filename = tvb_get_string(wmem_packet_scope(), tvb, data_pos, al_filename_len);
proto_tree_add_text(point_tree, tvb, data_pos, al_filename_len, "File Name: %s", al_filename);
}
data_pos += al_filename_len;
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_FILE_STAT:
proto_tree_add_item(point_tree, hf_dnp3_al_file_handle, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
proto_tree_add_item(point_tree, hf_dnp3_al_file_size, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
proto_tree_add_item(point_tree, hf_dnp3_al_file_maxblk, tvb, data_pos, 2, ENC_LITTLE_ENDIAN);
data_pos += 2;
proto_tree_add_item(point_tree, hf_dnp3_al_file_reqID, tvb, data_pos, 2, ENC_LITTLE_ENDIAN);
data_pos += 2;
proto_tree_add_item(point_tree, hf_dnp3_al_file_status, tvb, data_pos, 1, ENC_LITTLE_ENDIAN);
data_pos += 1;
file_data_size = al_ptaddr - (data_pos - offset - indexbytes);
if ((file_data_size) > 0) {
proto_tree_add_item(point_tree, hf_dnp3_al_file_data, tvb, data_pos, file_data_size, ENC_NA);
data_pos += file_data_size;
}
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_FILE_TRANS:
proto_tree_add_item(point_tree, hf_dnp3_al_file_handle, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
proto_tree_add_item(point_tree, hf_dnp3_al_file_blocknum, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(point_tree, hf_dnp3_al_file_lastblock, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
file_data_size = al_ptaddr - (data_pos - offset - indexbytes);
if ((file_data_size) > 0) {
proto_tree_add_item(point_tree, hf_dnp3_al_file_data, tvb, data_pos, file_data_size, ENC_NA);
data_pos += file_data_size;
}
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_FILE_TRAN_ST:
proto_tree_add_item(point_tree, hf_dnp3_al_file_handle, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
proto_tree_add_item(point_tree, hf_dnp3_al_file_blocknum, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(point_tree, hf_dnp3_al_file_lastblock, tvb, data_pos, 4, ENC_LITTLE_ENDIAN);
data_pos += 4;
proto_tree_add_item(point_tree, hf_dnp3_al_file_status, tvb, data_pos, 1, ENC_LITTLE_ENDIAN);
data_pos += 1;
file_data_size = al_ptaddr - (data_pos - offset - indexbytes);
if ((file_data_size) > 0) {
proto_tree_add_item(point_tree, hf_dnp3_al_file_data, tvb, data_pos, file_data_size, ENC_NA);
data_pos += file_data_size;
}
proto_item_set_len(point_item, data_pos - offset);
offset = data_pos;
break;
case AL_OBJ_OCT:
case AL_OBJ_OCT_EVT:
if (al_oct_len > 0) {
proto_tree_add_text(object_tree, tvb, data_pos, al_oct_len, "Octet String (%u bytes)", al_oct_len);
data_pos += al_oct_len;
proto_item_set_len(point_item, data_pos - offset);
}
offset = data_pos;
break;
default:
proto_tree_add_text(object_tree, tvb, offset, -1,
"Unknown Data Chunk, %u Bytes", tvb_reported_length_remaining(tvb, offset));
offset = tvb_length(tvb);
break;
}
bitindex++;
al_ptaddr++;
}
if (start_offset > offset) {
expert_add_info(pinfo, point_item, &ei_dnp_invalid_length);
offset = tvb_length(tvb);
}
}
}
proto_item_set_len(object_item, offset - orig_offset);
return offset;
}
static int
dissect_dnp3_al(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 al_ctl, al_seq, al_func, al_class = 0, i;
guint16 bytes, obj_type = 0;
guint data_len = 0, offset = 0;
proto_item *ti, *tc, *t_robj;
proto_tree *al_tree, *field_tree, *robj_tree;
const gchar *func_code_str, *obj_type_str;
nstime_t al_cto;
nstime_set_zero (&al_cto);
data_len = tvb_length(tvb);
al_ctl = tvb_get_guint8(tvb, offset);
al_seq = al_ctl & DNP3_AL_SEQ;
al_func = tvb_get_guint8(tvb, (offset+1));
func_code_str = val_to_str_ext(al_func, &dnp3_al_func_vals_ext, "Unknown function (0x%02x)");
col_clear(pinfo->cinfo, COL_INFO);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", func_code_str);
col_set_fence(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_text(tree, tvb, offset, data_len, "Application Layer: (");
if (al_ctl & DNP3_AL_FIR) proto_item_append_text(ti, "FIR, ");
if (al_ctl & DNP3_AL_FIN) proto_item_append_text(ti, "FIN, ");
if (al_ctl & DNP3_AL_CON) proto_item_append_text(ti, "CON, ");
if (al_ctl & DNP3_AL_UNS) proto_item_append_text(ti, "UNS, ");
proto_item_append_text(ti, "Sequence %u, %s)", al_seq, func_code_str);
al_tree = proto_item_add_subtree(ti, ett_dnp3_al);
tc = proto_tree_add_uint_format(al_tree, hf_dnp3_al_ctl, tvb, offset, 1, al_ctl,
"Control: 0x%02x (", al_ctl);
if (al_ctl & DNP3_AL_FIR) proto_item_append_text(tc, "FIR, ");
if (al_ctl & DNP3_AL_FIN) proto_item_append_text(tc, "FIN, ");
if (al_ctl & DNP3_AL_CON) proto_item_append_text(tc, "CON, ");
if (al_ctl & DNP3_AL_UNS) proto_item_append_text(tc, "UNS, ");
proto_item_append_text(tc, "Sequence %u)", al_seq);
field_tree = proto_item_add_subtree(tc, ett_dnp3_al_ctl);
proto_tree_add_boolean(field_tree, hf_dnp3_al_fir, tvb, offset, 1, al_ctl);
proto_tree_add_boolean(field_tree, hf_dnp3_al_fin, tvb, offset, 1, al_ctl);
proto_tree_add_boolean(field_tree, hf_dnp3_al_con, tvb, offset, 1, al_ctl);
proto_tree_add_boolean(field_tree, hf_dnp3_al_uns, tvb, offset, 1, al_ctl);
proto_tree_add_item(field_tree, hf_dnp3_al_seq, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
#if 0
if (!(al_ctl & DNP3_AL_FIN)) {
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "Buffering User Data Until Final Frame is Received..");
return 1;
}
#endif
proto_tree_add_uint_format(al_tree, hf_dnp3_al_func, tvb, offset, 1, al_func,
"Function Code: %s (0x%02x)", func_code_str, al_func);
offset += 1;
switch (al_func)
{
case AL_FUNC_READ:
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "READ Request Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, TRUE, &obj_type, &al_cto);
switch(obj_type) {
case AL_OBJ_CLASS0:
case AL_OBJ_CLASS1:
case AL_OBJ_CLASS2:
case AL_OBJ_CLASS3:
al_class |= (1 << ((obj_type & 0x0f) - 1));
break;
default:
obj_type_str = val_to_str_ext((obj_type & 0xFF00), &dnp3_al_read_obj_vals_ext, "Unknown Object Type");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", obj_type_str);
break;
}
}
if (al_class != 0) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Class ");
for (i = 0; i < 4; i++) {
if (al_class & (1 << i)) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%u", i);
}
}
}
break;
case AL_FUNC_WRITE:
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "WRITE Request Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, FALSE, &obj_type, &al_cto);
obj_type_str = val_to_str_ext((obj_type & 0xFF00), &dnp3_al_write_obj_vals_ext, "Unknown Object Type");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s", obj_type_str);
}
break;
case AL_FUNC_SELECT:
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "SELECT Request Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, FALSE, &obj_type, &al_cto);
}
break;
case AL_FUNC_OPERATE:
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "OPERATE Request Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, FALSE, &obj_type, &al_cto);
}
break;
case AL_FUNC_DIROP:
case AL_FUNC_DIROPNACK:
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "DIRECT OPERATE Request Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, FALSE, &obj_type, &al_cto);
}
break;
case AL_FUNC_FRZ:
case AL_FUNC_FRZNACK:
case AL_FUNC_FRZCLR:
case AL_FUNC_FRZCLRNACK:
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "Freeze Request Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, TRUE, &obj_type, &al_cto);
}
break;
case AL_FUNC_ENSPMSG:
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "Enable Spontaneous Msg's Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, FALSE, &obj_type, &al_cto);
}
break;
case AL_FUNC_DISSPMSG:
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "Disable Spontaneous Msg's Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, FALSE, &obj_type, &al_cto);
}
break;
case AL_FUNC_DELAYMST:
break;
case AL_FUNC_OPENFILE:
case AL_FUNC_CLOSEFILE:
case AL_FUNC_DELETEFILE:
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1, "File Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, FALSE, &obj_type, &al_cto);
}
break;
case AL_FUNC_RESPON:
case AL_FUNC_UNSOLI:
dnp3_al_process_iin(tvb, pinfo, offset, al_tree);
offset += 2;
bytes = tvb_reported_length_remaining(tvb, offset);
if (bytes > 0)
{
t_robj = proto_tree_add_text(al_tree, tvb, offset, -1,"RESPONSE Data Objects");
robj_tree = proto_item_add_subtree(t_robj, ett_dnp3_al_objdet);
while (offset <= (data_len-2)) {
offset = dnp3_al_process_object(tvb, pinfo, offset, robj_tree, FALSE, &obj_type, &al_cto);
}
break;
}
default:
break;
}
return 0;
}
static int
dissect_dnp3_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *tdl, *tc, *hidden_item;
proto_tree *dnp3_tree, *dl_tree, *field_tree;
int offset = 0, temp_offset = 0;
gboolean dl_prm;
guint8 dl_len, dl_ctl, dl_func;
const gchar *func_code_str;
guint16 dl_dst, dl_src, dl_crc, calc_dl_crc;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DNP 3.0");
col_clear(pinfo->cinfo, COL_INFO);
temp_offset += 2;
dl_len = tvb_get_guint8(tvb, temp_offset);
temp_offset += 1;
dl_ctl = tvb_get_guint8(tvb, temp_offset);
temp_offset += 1;
dl_dst = tvb_get_letohs(tvb, temp_offset);
temp_offset += 2;
dl_src = tvb_get_letohs(tvb, temp_offset);
dl_func = dl_ctl & DNP3_CTL_FUNC;
dl_prm = dl_ctl & DNP3_CTL_PRM;
func_code_str = val_to_str(dl_func, dl_prm ? dnp3_ctl_func_pri_vals : dnp3_ctl_func_sec_vals,
"Unknown function (0x%02x)");
col_append_fstr(pinfo->cinfo, COL_INFO, "from %u to %u", dl_src, dl_dst);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "len=%u, %s", dl_len, func_code_str);
ti = proto_tree_add_item(tree, proto_dnp3, tvb, offset, -1, ENC_NA);
dnp3_tree = proto_item_add_subtree(ti, ett_dnp3);
tdl = proto_tree_add_text(dnp3_tree, tvb, offset, DNP_HDR_LEN,
"Data Link Layer, Len: %u, From: %u, To: %u, ", dl_len, dl_src, dl_dst);
if (dl_prm) {
if (dl_ctl & DNP3_CTL_DIR) proto_item_append_text(tdl, "DIR, ");
if (dl_ctl & DNP3_CTL_PRM) proto_item_append_text(tdl, "PRM, ");
if (dl_ctl & DNP3_CTL_FCB) proto_item_append_text(tdl, "FCB, ");
if (dl_ctl & DNP3_CTL_FCV) proto_item_append_text(tdl, "FCV, ");
}
else {
if (dl_ctl & DNP3_CTL_DIR) proto_item_append_text(tdl, "DIR, ");
if (dl_ctl & DNP3_CTL_PRM) proto_item_append_text(tdl, "PRM, ");
if (dl_ctl & DNP3_CTL_RES) proto_item_append_text(tdl, "RES, ");
if (dl_ctl & DNP3_CTL_DFC) proto_item_append_text(tdl, "DFC, ");
}
proto_item_append_text(tdl, "%s", func_code_str);
dl_tree = proto_item_add_subtree(tdl, ett_dnp3_dl);
proto_tree_add_item(dl_tree, hf_dnp3_start, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dl_tree, hf_dnp3_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tc = proto_tree_add_uint_format_value(dl_tree, hf_dnp3_ctl, tvb, offset, 1, dl_ctl,
"0x%02x (", dl_ctl);
if (dl_prm) {
if (dl_ctl & DNP3_CTL_DIR) proto_item_append_text(tc, "DIR, ");
if (dl_ctl & DNP3_CTL_PRM) proto_item_append_text(tc, "PRM, ");
if (dl_ctl & DNP3_CTL_FCB) proto_item_append_text(tc, "FCB, ");
if (dl_ctl & DNP3_CTL_FCV) proto_item_append_text(tc, "FCV, ");
}
else {
if (dl_ctl & DNP3_CTL_DIR) proto_item_append_text(tc, "DIR, ");
if (dl_ctl & DNP3_CTL_PRM) proto_item_append_text(tc, "PRM, ");
if (dl_ctl & DNP3_CTL_RES) proto_item_append_text(tc, "RES, ");
if (dl_ctl & DNP3_CTL_DFC) proto_item_append_text(tc, "DFC, ");
}
proto_item_append_text(tc, "%s)", func_code_str );
field_tree = proto_item_add_subtree(tc, ett_dnp3_dl_ctl);
if (dl_prm) {
proto_tree_add_item(field_tree, hf_dnp3_ctl_dir, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(field_tree, hf_dnp3_ctl_prm, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(field_tree, hf_dnp3_ctl_fcb, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(field_tree, hf_dnp3_ctl_fcv, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(field_tree, hf_dnp3_ctl_prifunc, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(field_tree, hf_dnp3_ctl_dir, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(field_tree, hf_dnp3_ctl_prm, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(field_tree, hf_dnp3_ctl_dfc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(field_tree, hf_dnp3_ctl_secfunc, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
proto_tree_add_item(dl_tree, hf_dnp3_dst, tvb, offset, 2, ENC_LITTLE_ENDIAN);
hidden_item = proto_tree_add_item(dl_tree, hf_dnp3_addr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 2;
proto_tree_add_item(dl_tree, hf_dnp3_src, tvb, offset, 2, ENC_LITTLE_ENDIAN);
hidden_item = proto_tree_add_item(dl_tree, hf_dnp3_addr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 2;
dl_crc = tvb_get_letohs(tvb, offset);
calc_dl_crc = calculateCRC(tvb_get_ptr(tvb, 0, DNP_HDR_LEN - 2), DNP_HDR_LEN - 2);
if (dl_crc == calc_dl_crc)
proto_tree_add_uint_format_value(dl_tree, hf_dnp_hdr_CRC, tvb, offset, 2,
dl_crc, "0x%04x [correct]", dl_crc);
else
{
hidden_item = proto_tree_add_boolean(dl_tree, hf_dnp_hdr_CRC_bad, tvb,
offset, 2, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint_format_value(dl_tree, hf_dnp_hdr_CRC, tvb, offset, 2,
dl_crc, "0x%04x [incorrect, should be 0x%04x]",
dl_crc, calc_dl_crc);
}
offset += 2;
if ((dl_func != DL_FUNC_LINK_STAT) && (dl_func != DL_FUNC_STAT_LINK) &&
(dl_func != DL_FUNC_RESET_LINK) && (dl_func != DL_FUNC_ACK))
{
proto_tree *tr_tree, *al_tree;
proto_item *al_chunks;
guint8 tr_ctl, tr_seq;
gboolean tr_fir, tr_fin;
guint8 *tmp, *tmp_ptr;
guint8 data_len;
int data_offset;
gboolean crc_OK = FALSE;
tvbuff_t *next_tvb;
guint i;
tr_ctl = tvb_get_guint8(tvb, offset);
tr_seq = tr_ctl & DNP3_TR_SEQ;
tr_fir = tr_ctl & DNP3_TR_FIR;
tr_fin = tr_ctl & DNP3_TR_FIN;
tc = proto_tree_add_uint_format(dnp3_tree, hf_dnp3_tr_ctl, tvb, offset, 1, tr_ctl,
"Transport Layer: 0x%02x (", tr_ctl);
if (tr_fir) proto_item_append_text(tc, "FIR, ");
if (tr_fin) proto_item_append_text(tc, "FIN, ");
proto_item_append_text(tc, "Sequence %u)", tr_seq);
tr_tree = proto_item_add_subtree(tc, ett_dnp3_tr_ctl);
proto_tree_add_boolean(tr_tree, hf_dnp3_tr_fin, tvb, offset, 1, tr_ctl);
proto_tree_add_boolean(tr_tree, hf_dnp3_tr_fir, tvb, offset, 1, tr_ctl);
proto_tree_add_item(tr_tree, hf_dnp3_tr_seq, tvb, offset, 1, ENC_BIG_ENDIAN);
al_chunks = proto_tree_add_text(tr_tree, tvb, offset + 1, -1, "Application data chunks");
al_tree = proto_item_add_subtree(al_chunks, ett_dnp3_al_data);
data_len = dl_len - 5;
tmp = (guint8 *)wmem_alloc(pinfo->pool, data_len);
tmp_ptr = tmp;
i = 0;
data_offset = 1;
while (data_len > 0)
{
guint8 chk_size;
const guint8 *chk_ptr;
guint16 calc_crc, act_crc;
chk_size = MIN(data_len, AL_MAX_CHUNK_SIZE);
chk_ptr = tvb_get_ptr(tvb, offset, chk_size);
memcpy(tmp_ptr, chk_ptr + data_offset, chk_size - data_offset);
calc_crc = calculateCRC(chk_ptr, chk_size);
offset += chk_size;
tmp_ptr += chk_size - data_offset;
act_crc = tvb_get_letohs(tvb, offset);
offset += 2;
crc_OK = calc_crc == act_crc;
if (crc_OK)
{
proto_tree_add_text(al_tree, tvb, offset - (chk_size + 2), chk_size + 2,
"Application Chunk %u Len: %u CRC 0x%04x",
i, chk_size, act_crc);
data_len -= chk_size;
}
else
{
proto_tree_add_text(al_tree, tvb, offset - (chk_size + 2), chk_size + 2,
"Application Chunk %u Len: %u Bad CRC got 0x%04x expected 0x%04x",
i, chk_size, act_crc, calc_crc);
break;
}
i++;
data_offset = 0;
}
if (crc_OK)
{
tvbuff_t *al_tvb;
gboolean save_fragmented;
al_tvb = tvb_new_child_real_data(tvb, tmp, (guint) (tmp_ptr-tmp), (gint) (tmp_ptr-tmp));
save_fragmented = pinfo->fragmented;
if (! (tr_fir && tr_fin))
{
guint conv_seq_number;
fragment_head *frag_msg;
conversation_t *conversation;
dnp3_conv_t *conv_data_ptr;
dl_conversation_key_t dl_conversation_key;
pinfo->fragmented = TRUE;
conversation = find_or_create_conversation(pinfo);
dl_conversation_key.conversation = conversation->index;
dl_conversation_key.src = dl_src;
dl_conversation_key.dst = dl_dst;
conv_data_ptr = (dnp3_conv_t*)g_hash_table_lookup(dl_conversation_table, &dl_conversation_key);
if (!pinfo->fd->flags.visited && conv_data_ptr == NULL)
{
dl_conversation_key_t* new_dl_conversation_key = NULL;
new_dl_conversation_key = wmem_new(wmem_file_scope(), dl_conversation_key_t);
*new_dl_conversation_key = dl_conversation_key;
conv_data_ptr = wmem_new(wmem_file_scope(), dnp3_conv_t);
conv_data_ptr->conv_seq_number = seq_number++;
g_hash_table_insert(dl_conversation_table, new_dl_conversation_key, conv_data_ptr);
}
conv_seq_number = conv_data_ptr->conv_seq_number;
frag_msg = fragment_add_seq_next(&al_reassembly_table,
al_tvb, 0, pinfo, conv_seq_number, NULL,
tvb_reported_length(al_tvb),
!tr_fin);
next_tvb = process_reassembled_data(al_tvb, 0, pinfo,
"Reassembled DNP 3.0 Application Layer message", frag_msg, &dnp3_frag_items,
NULL, tr_tree);
if (next_tvb)
{
col_clear(pinfo->cinfo, COL_INFO);
}
else
{
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "TL fragment %u ", tr_seq);
}
}
else
{
next_tvb = al_tvb;
add_new_data_source(pinfo, next_tvb, "DNP 3.0 Application Layer message");
col_clear(pinfo->cinfo, COL_INFO);
}
pinfo->fragmented = save_fragmented;
}
else
{
next_tvb = NULL;
proto_tree_add_text(dnp3_tree, tvb, 11, -1, "CRC failed, %u chunks", i);
}
if (next_tvb && tr_fin)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "from %u to %u", dl_src, dl_dst);
col_set_fence(pinfo->cinfo, COL_INFO);
dissect_dnp3_al(next_tvb, pinfo, dnp3_tree);
}
else
{
col_set_fence(pinfo->cinfo, COL_INFO);
}
}
return tvb_length(tvb);
}
static guint
get_dnp3_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint16 message_len;
guint16 data_crc;
message_len = tvb_get_guint8(tvb, offset + 2);
data_crc = (guint16)(ceil((message_len - 5) / 16.0)) * 2;
message_len += 2 + 1 + 2 + data_crc;
return message_len;
}
static gboolean
dissect_dnp3_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint length = tvb_length(tvb);
if ((length < 2) || (tvb_get_ntohs(tvb, 0) != 0x0564)) {
return FALSE;
}
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, DNP_HDR_LEN,
get_dnp3_message_len, dissect_dnp3_message, data);
return TRUE;
}
static gboolean
dissect_dnp3_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint length = tvb_length(tvb);
if ((length < 2) || (tvb_get_ntohs(tvb, 0) != 0x0564)) {
return FALSE;
}
dissect_dnp3_message(tvb, pinfo, tree, data);
return TRUE;
}
static void
dnp3_init(void)
{
if (dl_conversation_table)
{
g_hash_table_destroy(dl_conversation_table);
}
dl_conversation_table = g_hash_table_new(dl_conversation_hash, dl_conversation_equal);
reassembly_table_init(&al_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_dnp3(void)
{
static hf_register_info hf[] = {
{ &hf_dnp3_start,
{ "Start Bytes", "dnp3.start",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_len,
{ "Length", "dnp3.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Frame Data Length", HFILL }
},
{ &hf_dnp3_ctl,
{ "Control", "dnp3.ctl",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Frame Control Byte", HFILL }
},
{ &hf_dnp3_ctl_prifunc,
{ "Control Function Code", "dnp3.ctl.prifunc",
FT_UINT8, BASE_DEC, VALS(dnp3_ctl_func_pri_vals), DNP3_CTL_FUNC,
"Frame Control Function Code", HFILL }
},
{ &hf_dnp3_ctl_secfunc,
{ "Control Function Code", "dnp3.ctl.secfunc",
FT_UINT8, BASE_DEC, VALS(dnp3_ctl_func_sec_vals), DNP3_CTL_FUNC,
"Frame Control Function Code", HFILL }
},
{ &hf_dnp3_ctlobj_code_c,
{ "Operation Type", "dnp3.ctl.op",
FT_UINT8, BASE_DEC, VALS(dnp3_al_ctlc_code_vals), AL_OBJCTLC_CODE,
"Control Code, Operation Type", HFILL }
},
{ &hf_dnp3_ctlobj_code_m,
{ "Queue / Clear Field", "dnp3.ctl.clr",
FT_UINT8, BASE_DEC, VALS(dnp3_al_ctlc_misc_vals), AL_OBJCTLC_MISC,
"Control Code, Clear Field", HFILL }
},
{ &hf_dnp3_ctlobj_code_tc,
{ "Trip Control Code", "dnp3.ctl.trip",
FT_UINT8, BASE_DEC, VALS(dnp3_al_ctlc_tc_vals), AL_OBJCTLC_TC,
"Control Code, Trip Close Control", HFILL }
},
{ &hf_dnp3_ctl_dir,
{ "Direction", "dnp3.ctl.dir",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_CTL_DIR,
NULL, HFILL }
},
{ &hf_dnp3_ctl_prm,
{ "Primary", "dnp3.ctl.prm",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_CTL_PRM,
NULL, HFILL }
},
{ &hf_dnp3_ctl_fcb,
{ "Frame Count Bit", "dnp3.ctl.fcb",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_CTL_FCB,
NULL, HFILL }
},
{ &hf_dnp3_ctl_fcv,
{ "Frame Count Valid", "dnp3.ctl.fcv",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_CTL_FCV,
NULL, HFILL }
},
{ &hf_dnp3_ctl_dfc,
{ "Data Flow Control", "dnp3.ctl.dfc",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_CTL_DFC,
NULL, HFILL }
},
{ &hf_dnp3_dst,
{ "Destination", "dnp3.dst",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Destination Address", HFILL }
},
{ &hf_dnp3_src,
{ "Source", "dnp3.src",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Source Address", HFILL }
},
{ &hf_dnp3_addr,
{ "Address", "dnp3.addr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Source or Destination Address", HFILL }
},
{ &hf_dnp_hdr_CRC,
{ "CRC", "dnp3.hdr.CRC",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp_hdr_CRC_bad,
{ "Bad CRC", "dnp3.hdr.CRC_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_tr_ctl,
{ "Transport Control", "dnp3.tr.ctl",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Transport Layer Control Byte", HFILL }
},
{ &hf_dnp3_tr_fin,
{ "Final", "dnp3.tr.fin",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_TR_FIN,
NULL, HFILL }
},
{ &hf_dnp3_tr_fir,
{ "First", "dnp3.tr.fir",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_TR_FIR,
NULL, HFILL }
},
{ &hf_dnp3_tr_seq,
{ "Sequence", "dnp3.tr.seq",
FT_UINT8, BASE_DEC, NULL, DNP3_TR_SEQ,
"Frame Sequence Number", HFILL }
},
{ &hf_dnp3_al_ctl,
{ "Application Control", "dnp3.al.ctl",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Application Layer Control Byte", HFILL }
},
{ &hf_dnp3_al_fir,
{ "First", "dnp3.al.fir",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_AL_FIR,
NULL, HFILL }
},
{ &hf_dnp3_al_fin,
{ "Final", "dnp3.al.fin",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_AL_FIN,
NULL, HFILL }
},
{ &hf_dnp3_al_con,
{ "Confirm", "dnp3.al.con",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_AL_CON,
NULL, HFILL }
},
{ &hf_dnp3_al_uns,
{ "Unsolicited", "dnp3.al.uns",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), DNP3_AL_UNS,
NULL, HFILL }
},
{ &hf_dnp3_al_seq,
{ "Sequence", "dnp3.al.seq",
FT_UINT8, BASE_DEC, NULL, DNP3_AL_SEQ,
"Frame Sequence Number", HFILL }
},
{ &hf_dnp3_al_func,
{ "Application Layer Function Code", "dnp3.al.func",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &dnp3_al_func_vals_ext, DNP3_AL_FUNC,
"Application Function Code", HFILL }
},
{ &hf_dnp3_al_iin,
{ "Application Layer IIN bits", "dnp3.al.iin",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Application Layer IIN", HFILL }
},
{ &hf_dnp3_al_iin_bmsg,
{ "Broadcast Msg Rx", "dnp3.al.iin.bmsg",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_BMSG,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_cls1d,
{ "Class 1 Data Available", "dnp3.al.iin.cls1d",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_CLS1D,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_cls2d,
{ "Class 2 Data Available", "dnp3.al.iin.cls2d",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_CLS2D,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_cls3d,
{ "Class 3 Data Available", "dnp3.al.iin.cls3d",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_CLS3D,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_tsr,
{ "Time Sync Required", "dnp3.al.iin.tsr",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_TSR,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_dol,
{ "Digital Outputs in Local", "dnp3.al.iin.dol",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_DOL,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_dt,
{ "Device Trouble", "dnp3.al.iin.dt",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_DT,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_rst,
{ "Device Restart", "dnp3.al.iin.rst",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_RST,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_fcni,
{ "Function Code not implemented", "dnp3.al.iin.fcni",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_FCNI,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_obju,
{ "Requested Objects Unknown", "dnp3.al.iin.obju",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_OBJU,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_pioor,
{ "Parameters Invalid or Out of Range", "dnp3.al.iin.pioor",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_PIOOR,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_ebo,
{ "Event Buffer Overflow", "dnp3.al.iin.ebo",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_EBO,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_oae,
{ "Operation Already Executing", "dnp3.al.iin.oae",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_OAE,
NULL, HFILL }
},
{ &hf_dnp3_al_iin_cc,
{ "Configuration Corrupt", "dnp3.al.iin.cc",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), AL_IIN_CC,
NULL, HFILL }
},
{ &hf_dnp3_al_obj,
{ "Object", "dnp3.al.obj",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &dnp3_al_obj_vals_ext, 0x0,
"Application Layer Object", HFILL }
},
{ &hf_dnp3_al_objq_index,
{ "Index Prefix", "dnp3.al.objq.index",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &dnp3_al_objq_index_vals_ext, AL_OBJQ_INDEX,
"Object Index Prefixing", HFILL }
},
{ &hf_dnp3_al_objq_code,
{ "Qualifier Code", "dnp3.al.objq.code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &dnp3_al_objq_code_vals_ext, AL_OBJQ_CODE,
"Object Qualifier Code", HFILL }
},
{ &hf_dnp3_al_range_start8,
{ "Start (8 bit)", "dnp3.al.range.start",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Object Start Index", HFILL }
},
{ &hf_dnp3_al_range_stop8,
{ "Stop (8 bit)", "dnp3.al.range.stop",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Object Stop Index", HFILL }
},
{ &hf_dnp3_al_range_start16,
{ "Start (16 bit)", "dnp3.al.range.start",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Object Start Index", HFILL }
},
{ &hf_dnp3_al_range_stop16,
{ "Stop (16 bit)", "dnp3.al.range.stop",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Object Stop Index", HFILL }
},
{ &hf_dnp3_al_range_start32,
{ "Start (32 bit)", "dnp3.al.range.start",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Object Start Index", HFILL }
},
{ &hf_dnp3_al_range_stop32,
{ "Stop (32 bit)", "dnp3.al.range.stop",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Object Stop Index", HFILL }
},
{ &hf_dnp3_al_range_abs8,
{ "Address (8 bit)", "dnp3.al.range.abs",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Object Absolute Address", HFILL }
},
{ &hf_dnp3_al_range_abs16,
{ "Address (16 bit)", "dnp3.al.range.abs",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Object Absolute Address", HFILL }
},
{ &hf_dnp3_al_range_abs32,
{ "Address (32 bit)", "dnp3.al.range.abs",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Object Absolute Address", HFILL }
},
{ &hf_dnp3_al_range_quant8,
{ "Quantity (8 bit)", "dnp3.al.range.quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Object Quantity", HFILL }
},
{ &hf_dnp3_al_range_quant16,
{ "Quantity (16 bit)", "dnp3.al.range.quantity",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Object Quantity", HFILL }
},
{ &hf_dnp3_al_range_quant32,
{ "Quantity (32 bit)", "dnp3.al.range.quantity",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Object Quantity", HFILL }
},
{ &hf_dnp3_al_index8,
{ "Index (8 bit)", "dnp3.al.index",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Object Index", HFILL }
},
{ &hf_dnp3_al_index16,
{ "Index (16 bit)", "dnp3.al.index",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Object Index", HFILL }
},
{ &hf_dnp3_al_index32,
{ "Index (32 bit)", "dnp3.al.index",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Object Index", HFILL }
},
#if 0
{ &hf_dnp3_al_ptnum,
{ "Object Point Number", "dnp3.al.ptnum",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_dnp3_al_size8,
{ "Size (8 bit)", "dnp3.al.size",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Object Size", HFILL }
},
{ &hf_dnp3_al_size16,
{ "Size (16 bit)", "dnp3.al.size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Object Size", HFILL }
},
{ &hf_dnp3_al_size32,
{ "Size (32 bit)", "dnp3.al.size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Object Size", HFILL }
},
{ &hf_dnp3_al_bit,
{ "Value (bit)", "dnp3.al.bit",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x1,
"Digital Value (1 bit)", HFILL }
},
{ &hf_dnp3_al_2bit,
{ "Value (two bit)", "dnp3.al.2bit",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Digital Value (2 bit)", HFILL }
},
{ &hf_dnp3_al_ana16,
{ "Value (16 bit)", "dnp3.al.ana",
FT_INT16, BASE_DEC, NULL, 0x0,
"Analog Value (16 bit)", HFILL }
},
{ &hf_dnp3_al_ana32,
{ "Value (32 bit)", "dnp3.al.ana",
FT_INT32, BASE_DEC, NULL, 0x0,
"Analog Value (32 bit)", HFILL }
},
{ &hf_dnp3_al_anaflt,
{ "Value (float)", "dnp3.al.ana",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Analog Value (float)", HFILL }
},
{ &hf_dnp3_al_anadbl,
{ "Value (double)", "dnp3.al.ana",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Analog Value (double)", HFILL }
},
{ &hf_dnp3_al_anaout16,
{ "Output Value (16 bit)", "dnp3.al.anaout",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_anaout32,
{ "Output Value (32 bit)", "dnp3.al.anaout",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_anaoutflt,
{ "Output Value (float)", "dnp3.al.anaout",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_anaoutdbl,
{ "Output (double)", "dnp3.al.anaout",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Output Value (double)", HFILL }
},
{ &hf_dnp3_al_cnt16,
{ "Counter (16 bit)", "dnp3.al.cnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Counter Value (16 bit)", HFILL }
},
{ &hf_dnp3_al_cnt32,
{ "Counter (32 bit)", "dnp3.al.cnt",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Counter Value (32 bit)", HFILL }
},
{ &hf_dnp3_al_ctrlstatus,
{ "Control Status", "dnp3.al.ctrlstatus",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &dnp3_al_ctl_status_vals_ext, 0xff,
NULL, HFILL }
},
{ &hf_dnp3_al_file_mode,
{ "File Control Mode", "dnp3.al.file.mode",
FT_UINT16, BASE_DEC, VALS(dnp3_al_file_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_file_auth,
{ "File Authentication Key", "dnp3.al.file.auth",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_file_size,
{ "File Size", "dnp3.al.file.size",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_file_maxblk,
{ "File Max Block Size", "dnp3.al.file.maxblock",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_file_reqID,
{ "File Request Identifier", "dnp3.al.file.reqID",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_file_status,
{ "File Control Status", "dnp3.al.file.status",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &dnp3_al_file_status_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_file_handle,
{ "File Handle", "dnp3.al.file.handle",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_file_blocknum,
{ "File Block Number", "dnp3.al.file.blocknum",
FT_UINT32, BASE_HEX, NULL, 0x7fffffff,
NULL, HFILL }
},
{ &hf_dnp3_al_file_lastblock,
{ "File Last Block", "dnp3.al.file.lastblock",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x80000000,
NULL, HFILL }
},
{ &hf_dnp3_al_file_data,
{ "File Data", "dnp3.al.file.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_biq_b0,
{ "Online", "dnp3.al.biq.b0",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BI_FLAG0,
NULL, HFILL }
},
{ &hf_dnp3_al_biq_b1,
{ "Restart", "dnp3.al.biq.b1",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BI_FLAG1,
NULL, HFILL }
},
{ &hf_dnp3_al_biq_b2,
{ "Comm Fail", "dnp3.al.biq.b2",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BI_FLAG2,
NULL, HFILL }
},
{ &hf_dnp3_al_biq_b3,
{ "Remote Force", "dnp3.al.biq.b3",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BI_FLAG3,
NULL, HFILL }
},
{ &hf_dnp3_al_biq_b4,
{ "Local Force", "dnp3.al.biq.b4",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BI_FLAG4,
NULL, HFILL }
},
{ &hf_dnp3_al_biq_b5,
{ "Chatter Filter", "dnp3.al.biq.b5",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BI_FLAG5,
NULL, HFILL }
},
{ &hf_dnp3_al_biq_b6,
{ "Reserved", "dnp3.al.biq.b6",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BI_FLAG6,
NULL, HFILL }
},
{ &hf_dnp3_al_biq_b7,
{ "Point Value", "dnp3.al.biq.b7",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BI_FLAG7,
NULL, HFILL }
},
{ &hf_dnp3_al_boq_b0,
{ "Online", "dnp3.al.boq.b0",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BO_FLAG0,
NULL, HFILL }
},
{ &hf_dnp3_al_boq_b1,
{ "Restart", "dnp3.al.boq.b1",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BO_FLAG1,
NULL, HFILL }
},
{ &hf_dnp3_al_boq_b2,
{ "Comm Fail", "dnp3.al.boq.b2",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BO_FLAG2,
NULL, HFILL }
},
{ &hf_dnp3_al_boq_b3,
{ "Remote Force", "dnp3.al.boq.b3",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BO_FLAG3,
NULL, HFILL }
},
{ &hf_dnp3_al_boq_b4,
{ "Local Force", "dnp3.al.boq.b4",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BO_FLAG4,
NULL, HFILL }
},
{ &hf_dnp3_al_boq_b5,
{ "Reserved", "dnp3.al.boq.b5",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BO_FLAG5,
NULL, HFILL }
},
{ &hf_dnp3_al_boq_b6,
{ "Reserved", "dnp3.al.boq.b6",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BO_FLAG6,
NULL, HFILL }
},
{ &hf_dnp3_al_boq_b7,
{ "Point Value", "dnp3.al.boq.b7",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_BO_FLAG7,
NULL, HFILL }
},
{ &hf_dnp3_al_ctrq_b0,
{ "Online", "dnp3.al.ctrq.b0",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_CTR_FLAG0,
NULL, HFILL }
},
{ &hf_dnp3_al_ctrq_b1,
{ "Restart", "dnp3.al.ctrq.b1",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_CTR_FLAG1,
NULL, HFILL }
},
{ &hf_dnp3_al_ctrq_b2,
{ "Comm Fail", "dnp3.al.ctrq.b2",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_CTR_FLAG2,
NULL, HFILL }
},
{ &hf_dnp3_al_ctrq_b3,
{ "Remote Force", "dnp3.al.ctrq.b3",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_CTR_FLAG3,
NULL, HFILL }
},
{ &hf_dnp3_al_ctrq_b4,
{ "Local Force", "dnp3.al.ctrq.b4",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_CTR_FLAG4,
NULL, HFILL }
},
{ &hf_dnp3_al_ctrq_b5,
{ "Roll-Over", "dnp3.al.ctrq.b5",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_CTR_FLAG5,
NULL, HFILL }
},
{ &hf_dnp3_al_ctrq_b6,
{ "Discontinuity", "dnp3.al.ctrq.b6",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_CTR_FLAG6,
NULL, HFILL }
},
{ &hf_dnp3_al_ctrq_b7,
{ "Reserved", "dnp3.al.ctrq.b7",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_CTR_FLAG7,
NULL, HFILL }
},
{ &hf_dnp3_al_aiq_b0,
{ "Online", "dnp3.al.aiq.b0",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AI_FLAG0,
NULL, HFILL }
},
{ &hf_dnp3_al_aiq_b1,
{ "Restart", "dnp3.al.aiq.b1",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AI_FLAG1,
NULL, HFILL }
},
{ &hf_dnp3_al_aiq_b2,
{ "Comm Fail", "dnp3.al.aiq.b2",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AI_FLAG2,
NULL, HFILL }
},
{ &hf_dnp3_al_aiq_b3,
{ "Remote Force", "dnp3.al.aiq.b3",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AI_FLAG3,
NULL, HFILL }
},
{ &hf_dnp3_al_aiq_b4,
{ "Local Force", "dnp3.al.aiq.b4",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AI_FLAG4,
NULL, HFILL }
},
{ &hf_dnp3_al_aiq_b5,
{ "Over-Range", "dnp3.al.aiq.b5",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AI_FLAG5,
NULL, HFILL }
},
{ &hf_dnp3_al_aiq_b6,
{ "Reference Check", "dnp3.al.aiq.b6",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AI_FLAG6,
NULL, HFILL }
},
{ &hf_dnp3_al_aiq_b7,
{ "Reserved", "dnp3.al.aiq.b7",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AI_FLAG7,
NULL, HFILL }
},
{ &hf_dnp3_al_aoq_b0,
{ "Online", "dnp3.al.aoq.b0",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AO_FLAG0,
NULL, HFILL }
},
{ &hf_dnp3_al_aoq_b1,
{ "Restart", "dnp3.al.aoq.b1",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AO_FLAG1,
NULL, HFILL }
},
{ &hf_dnp3_al_aoq_b2,
{ "Comm Fail", "dnp3.al.aoq.b2",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AO_FLAG2,
NULL, HFILL }
},
{ &hf_dnp3_al_aoq_b3,
{ "Remote Force", "dnp3.al.aoq.b3",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AO_FLAG3,
NULL, HFILL }
},
{ &hf_dnp3_al_aoq_b4,
{ "Local Force", "dnp3.al.aoq.b4",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AO_FLAG4,
NULL, HFILL }
},
{ &hf_dnp3_al_aoq_b5,
{ "Reserved", "dnp3.al.aoq.b5",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AO_FLAG5,
NULL, HFILL }
},
{ &hf_dnp3_al_aoq_b6,
{ "Reserved", "dnp3.al.aoq.b6",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AO_FLAG6,
NULL, HFILL }
},
{ &hf_dnp3_al_aoq_b7,
{ "Reserved", "dnp3.al.aoq.b7",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), AL_OBJ_AO_FLAG7,
NULL, HFILL }
},
{ &hf_dnp3_al_timestamp,
{ "Timestamp", "dnp3.al.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Object Timestamp", HFILL }
},
{ &hf_dnp3_al_file_perms,
{ "Permissions", "dnp3.al.file.perms",
FT_UINT16, BASE_OCT, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_al_file_perms_read_owner,
{ "Read permission for owner", "dnp3.al.file.perms.read_owner",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0400,
NULL, HFILL }
},
{ &hf_dnp3_al_file_perms_write_owner,
{ "Write permission for owner", "dnp3.al.file.perms.write_owner",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0200,
NULL, HFILL }
},
{ &hf_dnp3_al_file_perms_exec_owner,
{ "Execute permission for owner", "dnp3.al.file.perms.exec_owner",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0100,
NULL, HFILL }
},
{ &hf_dnp3_al_file_perms_read_group,
{ "Read permission for group", "dnp3.al.file.perms.read_group",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 040,
NULL, HFILL }
},
{ &hf_dnp3_al_file_perms_write_group,
{ "Write permission for group", "dnp3.al.file.perms.write_group",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 020,
NULL, HFILL }
},
{ &hf_dnp3_al_file_perms_exec_group,
{ "Execute permission for group", "dnp3.al.file.perms.exec_group",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 010,
NULL, HFILL }
},
{ &hf_dnp3_al_file_perms_read_world,
{ "Read permission for world", "dnp3.al.file.perms.read_world",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 04,
NULL, HFILL }
},
{ &hf_dnp3_al_file_perms_write_world,
{ "Write permission for world", "dnp3.al.file.perms.write_world",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 02,
NULL, HFILL }
},
{ &hf_dnp3_al_file_perms_exec_world,
{ "Execute permission for world", "dnp3.al.file.perms.exec_world",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 01,
NULL, HFILL }
},
{ &hf_dnp3_al_rel_timestamp,
{ "Relative Timestamp", "dnp3.al.reltimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0,
"Object Relative Timestamp", HFILL }
},
{ &hf_dnp3_al_datatype,
{ "Data Type", "dnp3.al.datatype",
FT_UINT8, BASE_HEX, VALS(dnp3_al_data_type_vals), 0,
NULL, HFILL }
},
{ &hf_dnp3_al_da_length,
{ "Device Attribute Length", "dnp3.al.da.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_dnp3_al_da_int8,
{ "8-Bit Integer Value", "dnp3.al.da.int8",
FT_INT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_dnp3_al_da_int32,
{ "32-Bit Integer Value", "dnp3.al.da.int32",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_dnp3_fragment,
{ "DNP 3.0 AL Fragment", "dnp3.al.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"DNP 3.0 Application Layer Fragment", HFILL }
},
{ &hf_dnp3_fragments,
{ "DNP 3.0 AL Fragments", "dnp3.al.fragments",
FT_NONE, BASE_NONE, NULL, 0x0,
"DNP 3.0 Application Layer Fragments", HFILL }
},
{ &hf_dnp3_fragment_overlap,
{ "Fragment overlap", "dnp3.al.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }
},
{ &hf_dnp3_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "dnp3.al.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }
},
{ &hf_dnp3_fragment_multiple_tails,
{ "Multiple tail fragments found", "dnp3.al.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }
},
{ &hf_dnp3_fragment_too_long_fragment,
{ "Fragment too long", "dnp3.al.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }
},
{ &hf_dnp3_fragment_error,
{ "Defragmentation error", "dnp3.al.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }
},
{ &hf_dnp3_fragment_count,
{ "Fragment count", "dnp3.al.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dnp3_fragment_reassembled_in,
{ "Reassembled PDU In Frame", "dnp3.al.fragment.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This PDU is reassembled in this frame", HFILL }
},
{ &hf_dnp3_fragment_reassembled_length,
{ "Reassembled DNP length", "dnp3.al.fragment.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }
}
};
static gint *ett[] = {
&ett_dnp3,
&ett_dnp3_dl,
&ett_dnp3_dl_ctl,
&ett_dnp3_tr_ctl,
&ett_dnp3_al_data,
&ett_dnp3_al,
&ett_dnp3_al_ctl,
&ett_dnp3_al_obj_point_tcc,
&ett_dnp3_al_iin,
&ett_dnp3_al_obj,
&ett_dnp3_al_obj_qualifier,
&ett_dnp3_al_obj_range,
&ett_dnp3_al_objdet,
&ett_dnp3_al_obj_quality,
&ett_dnp3_al_obj_point,
&ett_dnp3_al_obj_point_perms,
&ett_dnp3_fragment,
&ett_dnp3_fragments
};
static ei_register_info ei[] = {
{ &ei_dnp_num_items_neg, { "dnp3.num_items_neg", PI_MALFORMED, PI_ERROR, "Negative number of items", EXPFILL }},
{ &ei_dnp_invalid_length, { "dnp3.invalid_length", PI_MALFORMED, PI_ERROR, "Invalid length", EXPFILL }},
{ &ei_dnp_iin_abnormal, { "dnp3.iin_abnormal", PI_PROTOCOL, PI_WARN, "IIN Abnormality", EXPFILL }},
};
module_t *dnp3_module;
expert_module_t* expert_dnp3;
register_init_routine(&dnp3_init);
proto_dnp3 = proto_register_protocol("Distributed Network Protocol 3.0",
"DNP 3.0", "dnp3");
new_register_dissector("dnp3.udp", dissect_dnp3_udp, proto_dnp3);
proto_register_field_array(proto_dnp3, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dnp3 = expert_register_protocol(proto_dnp3);
expert_register_field_array(expert_dnp3, ei, array_length(ei));
dnp3_module = prefs_register_protocol(proto_dnp3, NULL);
prefs_register_bool_preference(dnp3_module, "heuristics",
"Try to detect DNP 3 heuristically",
"Whether the DNP3 dissector should try to find DNP 3 packets heuristically.",
&dnp3_heuristics);
prefs_register_bool_preference(dnp3_module, "desegment",
"Reassemble DNP3 messages spanning multiple TCP segments",
"Whether the DNP3 dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&dnp3_desegment);
}
void
proto_reg_handoff_dnp3(void)
{
dissector_handle_t dnp3_tcp_handle;
dissector_handle_t dnp3_udp_handle;
if (dnp3_heuristics) {
heur_dissector_add("tcp", dissect_dnp3_tcp, proto_dnp3);
heur_dissector_add("udp", dissect_dnp3_udp, proto_dnp3);
} else {
heur_dissector_delete("tcp", dissect_dnp3_tcp, proto_dnp3);
heur_dissector_delete("udp", dissect_dnp3_udp, proto_dnp3);
}
dnp3_tcp_handle = new_create_dissector_handle(dissect_dnp3_tcp, proto_dnp3);
dnp3_udp_handle = new_create_dissector_handle(dissect_dnp3_udp, proto_dnp3);
dissector_add_uint("tcp.port", TCP_PORT_DNP, dnp3_tcp_handle);
dissector_add_uint("udp.port", UDP_PORT_DNP, dnp3_udp_handle);
}
