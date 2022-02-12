static void
dissect_mtp3mg_unknown_message(tvbuff_t *tvb, proto_tree *tree)
{
guint8 message_length;
message_length = tvb_length(tvb);
proto_tree_add_text(tree, tvb, 0, message_length,
"Unknown message (%u byte%s)", message_length,
plurality(message_length, "", "s"));
}
static void
dissect_mtp3mg_chm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, chm_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case CHM_H1_COO:
case CHM_H1_COA:
if (mtp3_standard == ANSI_STANDARD)
{
proto_tree_add_item(tree, hf_mtp3mg_coo_ansi_slc, tvb, 0,
ANSI_COO_LENGTH, ENC_NA);
proto_tree_add_item(tree, hf_mtp3mg_coo_ansi_fsn, tvb, 0,
ANSI_COO_LENGTH, ENC_NA);
} else {
proto_tree_add_item(tree, hf_mtp3mg_coo_itu_fsn, tvb, 0,
ITU_COO_LENGTH, ENC_NA);
}
break;
case CHM_H1_XCO:
case CHM_H1_XCA:
if (mtp3_standard == ANSI_STANDARD)
{
proto_tree_add_item(tree, hf_mtp3mg_xco_ansi_slc, tvb, 0,
ANSI_XCO_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mtp3mg_xco_ansi_fsn, tvb, 0,
ANSI_XCO_LENGTH, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mtp3mg_xco_itu_fsn, tvb, 0,
ITU_XCO_LENGTH, ENC_LITTLE_ENDIAN);
}
break;
case CHM_H1_CBD:
case CHM_H1_CBA:
if (mtp3_standard == ANSI_STANDARD)
{
proto_tree_add_item(tree, hf_mtp3mg_cbd_ansi_slc, tvb, 0,
ANSI_CBD_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mtp3mg_cbd_ansi_cbc, tvb, 0,
ANSI_CBD_LENGTH, ENC_LITTLE_ENDIAN);
} else if (mtp3_standard == JAPAN_STANDARD) {
proto_tree_add_item(tree, hf_mtp3mg_cbd_japan_cbc, tvb, 0,
ITU_CBD_LENGTH, ENC_NA);
} else {
proto_tree_add_item(tree, hf_mtp3mg_cbd_itu_cbc, tvb, 0,
ITU_CBD_LENGTH, ENC_NA);
}
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg_ecm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, ecm_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case ECM_H1_ECO:
case ECM_H1_ECA:
if (mtp3_standard == ANSI_STANDARD)
{
proto_tree_add_item(tree, hf_mtp3mg_eco_ansi_slc, tvb, 0,
ANSI_ECO_LENGTH, ENC_NA);
}
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg_fcm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
proto_item *apc_item;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, fcm_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case FCM_H1_RCT:
break;
case FCM_H1_TFC:
if (mtp3_standard == ITU_STANDARD)
{
apc_item = proto_tree_add_item(tree, hf_mtp3mg_tfc_itu_apc, tvb, 0,
ITU_PC_LENGTH, ENC_LITTLE_ENDIAN);
if (mtp3_pc_structured())
{
guint32 apc;
apc = tvb_get_letohs(tvb, 0) & ITU_PC_MASK;
proto_item_append_text(apc_item, " (%s)", mtp3_pc_to_str(apc));
}
proto_tree_add_item(tree, hf_mtp3mg_tfc_itu_status, tvb, 0,
ITU_TFC_STATUS_LENGTH, ENC_NA);
} else if (mtp3_standard == JAPAN_STANDARD) {
proto_tree_add_item(tree, hf_mtp3mg_tfc_japan_spare, tvb,
JAPAN_TFC_SPARE_OFFSET,
JAPAN_TFC_SPARE_LENGTH, ENC_NA);
apc_item = proto_tree_add_item(tree, hf_mtp3mg_tfc_japan_apc, tvb,
JAPAN_TFC_APC_OFFSET,
JAPAN_PC_LENGTH, ENC_LITTLE_ENDIAN);
if (mtp3_pc_structured())
{
guint32 apc;
apc = tvb_get_letohs(tvb, JAPAN_TFC_APC_OFFSET);
proto_item_append_text(apc_item, " (%s)", mtp3_pc_to_str(apc));
}
proto_tree_add_item(tree, hf_mtp3mg_tfc_japan_status, tvb,
JAPAN_TFC_STATUS_OFFSET,
JAPAN_TFC_STATUS_LENGTH, ENC_NA);
proto_tree_add_item(tree, hf_mtp3mg_tfc_japan_status_spare, tvb,
JAPAN_TFC_STATUS_OFFSET,
JAPAN_TFC_STATUS_LENGTH, ENC_NA);
} else {
int hf_apc_string;
if (mtp3_standard == ANSI_STANDARD) {
hf_apc_string = hf_mtp3mg_tfc_ansi_apc;
} else {
hf_apc_string = hf_mtp3mg_tfc_chinese_apc;
}
dissect_mtp3_3byte_pc(tvb, 0, tree, ett_mtp3mg_fcm_apc,
hf_apc_string, hf_mtp3mg_tfc_apc_network,
hf_mtp3mg_tfc_apc_cluster,
hf_mtp3mg_tfc_apc_member, 0, 0);
proto_tree_add_item(tree, hf_mtp3mg_tfc_ansi_status, tvb,
ANSI_TFC_STATUS_OFFSET, ANSI_TFC_STATUS_LENGTH,
ENC_NA);
}
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg_tfm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
proto_item *apc_item;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, tfm_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case TFM_H1_TFP:
case TFM_H1_TCP:
case TFM_H1_TFR:
case TFM_H1_TCR:
case TFM_H1_TFA:
case TFM_H1_TCA:
if (mtp3_standard == ANSI_STANDARD)
{
dissect_mtp3_3byte_pc(tvb, 0, tree, ett_mtp3mg_tfm_apc,
hf_mtp3mg_tfm_ansi_apc,
hf_mtp3mg_tfm_apc_network,
hf_mtp3mg_tfm_apc_cluster,
hf_mtp3mg_tfm_apc_member, 0, 0);
} else if (mtp3_standard == JAPAN_STANDARD) {
guint8 count, i;
guint32 offset;
if (h1 == TFM_H1_TCP || h1 == TFM_H1_TCR || h1 == TFM_H1_TCA
|| h1 == TFM_H1_TFR)
dissect_mtp3mg_unknown_message(tvb, tree);
proto_tree_add_item(tree, hf_mtp3mg_tfm_japan_count, tvb,
JAPAN_TFM_COUNT_OFFSET,
JAPAN_TFM_COUNT_LENGTH, ENC_NA);
count = tvb_get_guint8(tvb, JAPAN_TFM_COUNT_OFFSET);
offset = JAPAN_TFM_COUNT_LENGTH;
for (i = 0; i < count; i++)
{
apc_item = proto_tree_add_item(tree, hf_mtp3mg_tfm_japan_apc, tvb,
offset, JAPAN_PC_LENGTH, ENC_LITTLE_ENDIAN);
if (mtp3_pc_structured())
{
guint32 apc;
apc = tvb_get_letohs(tvb, offset);
proto_item_append_text(apc_item, " (%s)", mtp3_pc_to_str(apc));
}
offset += JAPAN_PC_LENGTH;
proto_tree_add_item(tree, hf_mtp3mg_tfm_japan_spare, tvb,
offset, JAPAN_PC_LENGTH, ENC_LITTLE_ENDIAN);
offset += JAPAN_PC_LENGTH;
}
} else {
if (h1 == TFM_H1_TCP || h1 == TFM_H1_TCR || h1 == TFM_H1_TCA)
dissect_mtp3mg_unknown_message(tvb, tree);
else if (mtp3_standard == ITU_STANDARD)
{
apc_item = proto_tree_add_item(tree, hf_mtp3mg_tfm_itu_apc,
tvb, 0, ITU_PC_LENGTH, ENC_LITTLE_ENDIAN);
if (mtp3_pc_structured())
{
guint32 apc;
apc = tvb_get_letohs(tvb, 0) & ITU_PC_MASK;
proto_item_append_text(apc_item, " (%s)", mtp3_pc_to_str(apc));
}
}
else if (mtp3_standard == CHINESE_ITU_STANDARD)
dissect_mtp3_3byte_pc(tvb, 0, tree, ett_mtp3mg_tfm_apc,
hf_mtp3mg_tfm_chinese_apc,
hf_mtp3mg_tfm_apc_network,
hf_mtp3mg_tfm_apc_cluster,
hf_mtp3mg_tfm_apc_member, 0, 0);
}
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg_rsm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
proto_item *apc_item;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, rsm_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case RSM_H1_RST:
case RSM_H1_RSR:
case RSM_H1_RCP:
case RSM_H1_RCR:
if (mtp3_standard == ANSI_STANDARD)
{
dissect_mtp3_3byte_pc(tvb, 0, tree, ett_mtp3mg_rsm_apc,
hf_mtp3mg_rsm_ansi_apc,
hf_mtp3mg_rsm_apc_network,
hf_mtp3mg_rsm_apc_cluster,
hf_mtp3mg_rsm_apc_member, 0, 0);
} else if (mtp3_standard == JAPAN_STANDARD) {
if (h1 == RSM_H1_RST)
{
guint32 offset;
guint8 count, i;
proto_tree_add_item(tree, hf_mtp3mg_rsm_japan_count, tvb,
JAPAN_TFM_COUNT_OFFSET,
JAPAN_TFM_COUNT_LENGTH, ENC_NA);
count = tvb_get_guint8(tvb, JAPAN_TFM_COUNT_OFFSET);
offset = JAPAN_TFM_COUNT_LENGTH;
for (i = 0; i < count; i++)
{
apc_item = proto_tree_add_item(tree,
hf_mtp3mg_rsm_japan_apc,
tvb, offset,
JAPAN_PC_LENGTH,
ENC_LITTLE_ENDIAN);
if (mtp3_pc_structured())
{
guint32 apc;
apc = tvb_get_letohs(tvb, 0);
proto_item_append_text(apc_item, " (%s)",
mtp3_pc_to_str(apc));
}
offset += JAPAN_PC_LENGTH;
proto_tree_add_item(tree, hf_mtp3mg_rsm_japan_spare, tvb,
offset, JAPAN_PC_LENGTH,
ENC_LITTLE_ENDIAN);
offset += JAPAN_PC_LENGTH;
}
} else
dissect_mtp3mg_unknown_message(tvb, tree);
} else {
if (h1 == RSM_H1_RST || h1 == RSM_H1_RSR)
{
if (mtp3_standard == ITU_STANDARD)
{
apc_item = proto_tree_add_item(tree, hf_mtp3mg_rsm_itu_apc,
tvb, 0, ITU_PC_LENGTH,
ENC_LITTLE_ENDIAN);
if (mtp3_pc_structured())
{
guint32 apc;
apc = tvb_get_letohs(tvb, 0) & ITU_PC_MASK;
proto_item_append_text(apc_item, " (%s)", mtp3_pc_to_str(apc));
}
}
else
dissect_mtp3_3byte_pc(tvb, 0, tree, ett_mtp3mg_rsm_apc,
hf_mtp3mg_rsm_chinese_apc,
hf_mtp3mg_rsm_apc_network,
hf_mtp3mg_rsm_apc_cluster,
hf_mtp3mg_rsm_apc_member, 0, 0);
} else
dissect_mtp3mg_unknown_message(tvb, tree);
}
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg_mim(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, mim_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case MIM_H1_LIN:
case MIM_H1_LUN:
case MIM_H1_LIA:
case MIM_H1_LUA:
case MIM_H1_LID:
case MIM_H1_LFU:
case MIM_H1_LLT:
case MIM_H1_LRT:
if (mtp3_standard == ANSI_STANDARD)
{
proto_tree_add_item(tree, hf_mtp3mg_mim_ansi_slc, tvb, 0,
ANSI_MIM_LENGTH, ENC_NA);
}
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg_trm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, trm_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case TRM_H1_TRA:
break;
case TRM_H1_TRW:
if (mtp3_standard != ANSI_STANDARD)
dissect_mtp3mg_unknown_message(tvb, tree);
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg_dlm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, dlm_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case DLM_H1_DLC:
if (mtp3_standard == ANSI_STANDARD)
{
proto_tree_add_item(tree, hf_mtp3mg_dlc_ansi_slc, tvb, 0,
ANSI_DLC_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mtp3mg_dlc_ansi_link, tvb, 0,
ANSI_DLC_LENGTH, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mtp3mg_dlc_itu_link, tvb, 0,
ITU_DLC_LENGTH, ENC_LITTLE_ENDIAN);
}
break;
case DLM_H1_CSS:
case DLM_H1_CNS:
case DLM_H1_CNP:
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg_ufc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
proto_item *apc_item;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, ufc_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case UFC_H1_UPU:
if (mtp3_standard == ANSI_STANDARD
|| mtp3_standard == CHINESE_ITU_STANDARD)
{
int hf_apc;
if (mtp3_standard == ANSI_STANDARD)
hf_apc = hf_mtp3mg_upu_ansi_apc;
else
hf_apc = hf_mtp3mg_upu_chinese_apc;
dissect_mtp3_3byte_pc(tvb, 0, tree, ett_mtp3mg_upu_apc, hf_apc,
hf_mtp3mg_rsm_apc_network,
hf_mtp3mg_rsm_apc_cluster,
hf_mtp3mg_rsm_apc_member, 0, 0);
proto_tree_add_item(tree, hf_mtp3mg_upu_user, tvb,
ANSI_UPU_USER_OFFSET, UPU_USER_LENGTH, ENC_NA);
proto_tree_add_item(tree, hf_mtp3mg_upu_cause, tvb,
ANSI_UPU_USER_OFFSET, UPU_USER_LENGTH, ENC_NA);
} else if (mtp3_standard == ITU_STANDARD) {
apc_item = proto_tree_add_item(tree, hf_mtp3mg_upu_itu_apc, tvb, 0,
ITU_PC_LENGTH, ENC_LITTLE_ENDIAN);
if (mtp3_pc_structured())
{
guint32 apc;
apc = tvb_get_letohs(tvb, 0) & ITU_PC_MASK;
proto_item_append_text(apc_item, " (%s)", mtp3_pc_to_str(apc));
}
proto_tree_add_item(tree, hf_mtp3mg_upu_user, tvb,
ITU_UPU_USER_OFFSET, UPU_USER_LENGTH, ENC_NA);
proto_tree_add_item(tree, hf_mtp3mg_upu_cause, tvb,
ITU_UPU_USER_OFFSET, UPU_USER_LENGTH, ENC_NA);
} else {
apc_item = proto_tree_add_item(tree, hf_mtp3mg_upu_japan_apc, tvb,
0, JAPAN_PC_LENGTH,
ENC_LITTLE_ENDIAN);
if (mtp3_pc_structured())
{
guint32 apc;
apc = tvb_get_letohs(tvb, 0);
proto_item_append_text(apc_item, " (%s)", mtp3_pc_to_str(apc));
}
proto_tree_add_item(tree, hf_mtp3mg_upu_user, tvb,
ITU_UPU_USER_OFFSET, UPU_USER_LENGTH, ENC_NA);
proto_tree_add_item(tree, hf_mtp3mg_upu_cause, tvb,
ITU_UPU_USER_OFFSET, UPU_USER_LENGTH, ENC_NA);
}
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg_test(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 h1)
{
guint8 length;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h1, test_h1_message_type_acro_values, "Unknown"));
switch (h1)
{
case TEST_H1_SLTM:
case TEST_H1_SLTA:
if (mtp3_standard == ANSI_STANDARD)
{
proto_tree_add_item(tree, hf_mtp3mg_test_ansi_slc, tvb, 0,
TEST_LENGTH, ENC_NA);
}
proto_tree_add_item(tree, hf_mtp3mg_test_length, tvb, 0, TEST_LENGTH,
ENC_NA);
length = tvb_get_guint8(tvb, 0) >> TEST_LENGTH_SHIFT;
proto_tree_add_text(tree, tvb, TEST_PATTERN_OFFSET, length,
"Test pattern (%u byte%s)", length,
plurality(length, "", "s"));
break;
default:
dissect_mtp3mg_unknown_message(tvb, tree);
}
}
static void
dissect_mtp3mg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 h0, h1;
tvbuff_t *payload_tvb;
proto_item *mtp3mg_item = NULL;
proto_tree *mtp3mg_tree = NULL;
switch(mtp3_standard) {
case ITU_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MTP3MG (Int. ITU)");
break;
case ANSI_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MTP3MG (ANSI)");
break;
case CHINESE_ITU_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MTP3MG (Chin. ITU)");
break;
case JAPAN_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MTP3MG (Japan)");
break;
};
if (tree) {
mtp3mg_item = proto_tree_add_item(tree, proto_mtp3mg, tvb, 0, -1, ENC_NA);
mtp3mg_tree = proto_item_add_subtree(mtp3mg_item, ett_mtp3mg);
}
if(pinfo->private_data == (void *)MTP_SI_MTN ||
pinfo->private_data == (void *)MTP_SI_MTNS)
{
if (mtp3_standard == JAPAN_STANDARD)
{
guint8 h0h1;
guint16 test_pattern;
proto_item *pattern_item;
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_japan_spare, tvb, 0,
JAPAN_SPARE_LENGTH, ENC_NA);
h0h1 = tvb_get_guint8(tvb, JAPAN_H0H1_OFFSET);
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_japan_test, tvb,
JAPAN_SPARE_LENGTH, H0H1_LENGTH, ENC_NA);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(h0h1, japan_test_message_type_acro_values, "Unknown"));
switch (h0h1)
{
case JAPAN_TEST_SRT:
case JAPAN_TEST_SRA:
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_japan_test_spare,
tvb, JAPAN_TEST_SPARE_OFFSET,
JAPAN_TEST_SPARE_LENGTH, ENC_NA);
test_pattern = tvb_get_letohs(tvb, JAPAN_TEST_PATTERN_OFFSET);
pattern_item = proto_tree_add_item(mtp3mg_tree,
hf_mtp3mg_japan_test_pattern,
tvb,
JAPAN_TEST_PATTERN_OFFSET,
JAPAN_TEST_PATTERN_LENGTH,
ENC_LITTLE_ENDIAN);
proto_item_append_text(pattern_item, " (%s)",
test_pattern == JAPAN_TEST_PATTERN
? "correct" : "incorrect");
break;
default:
dissect_mtp3mg_unknown_message(tvb, mtp3mg_tree);
}
} else {
proto_tree_add_item(mtp3mg_tree, hf_mtp3test_h0, tvb, 0, H0H1_LENGTH, ENC_NA);
h0 = tvb_get_guint8(tvb, 0) & H0_MASK;
h1 = (tvb_get_guint8(tvb, 0) & H1_MASK) >> H1_SHIFT;
payload_tvb = tvb_new_subset_remaining(tvb, H0H1_LENGTH);
switch (h0)
{
case TEST_H0_SLT:
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_test_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_test(payload_tvb, pinfo, mtp3mg_tree, h1);
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown ");
dissect_mtp3mg_unknown_message(tvb, mtp3mg_tree);
}
}
} else {
if (mtp3_standard == JAPAN_STANDARD)
{
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_japan_spare, tvb, 0,
JAPAN_SPARE_LENGTH, ENC_NA);
tvb = tvb_new_subset_remaining(tvb, JAPAN_SPARE_LENGTH);
}
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_h0, tvb, 0, H0H1_LENGTH,
ENC_NA);
h0 = tvb_get_guint8(tvb, 0) & H0_MASK;
h1 = (tvb_get_guint8(tvb, 0) & H1_MASK) >> H1_SHIFT;
payload_tvb = tvb_new_subset_remaining(tvb, H0H1_LENGTH);
switch (h0)
{
case H0_CHM:
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_chm_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_chm(payload_tvb, pinfo, mtp3mg_tree, h1);
break;
case H0_ECM:
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_ecm_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_ecm(payload_tvb, pinfo, mtp3mg_tree, h1);
break;
case H0_FCM:
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_fcm_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_fcm(payload_tvb, pinfo, mtp3mg_tree, h1);
break;
case H0_TFM:
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_tfm_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_tfm(payload_tvb, pinfo, mtp3mg_tree, h1);
break;
case H0_RSM:
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_rsm_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_rsm(payload_tvb, pinfo, mtp3mg_tree, h1);
break;
case H0_MIM:
if (mtp3_standard != JAPAN_STANDARD)
{
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_mim_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_mim(payload_tvb, pinfo, mtp3mg_tree, h1);
} else
dissect_mtp3mg_unknown_message(tvb, mtp3mg_tree);
break;
case H0_TRM:
if (mtp3_standard != JAPAN_STANDARD)
{
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_trm_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_trm(payload_tvb, pinfo, mtp3mg_tree, h1);
} else
dissect_mtp3mg_unknown_message(tvb, mtp3mg_tree);
break;
case H0_DLM:
if (mtp3_standard != JAPAN_STANDARD)
{
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_dlm_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_dlm(payload_tvb, pinfo, mtp3mg_tree, h1);
} else
dissect_mtp3mg_unknown_message(tvb, mtp3mg_tree);
break;
case H0_UFC:
if (mtp3_standard != JAPAN_STANDARD)
{
proto_tree_add_item(mtp3mg_tree, hf_mtp3mg_ufc_h1, tvb, 0,
H0H1_LENGTH, ENC_NA);
dissect_mtp3mg_ufc(payload_tvb, pinfo, mtp3mg_tree, h1);
} else
dissect_mtp3mg_unknown_message(tvb, mtp3mg_tree);
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown ");
dissect_mtp3mg_unknown_message(tvb, mtp3mg_tree);
}
}
}
void
proto_register_mtp3mg(void)
{
static hf_register_info hf[] = {
{ &hf_mtp3mg_h0,
{ "H0 (Message Group)", "mtp3mg.h0",
FT_UINT8, BASE_HEX, VALS(h0_message_type_values), H0_MASK,
"Message group identifier", HFILL }},
{ &hf_mtp3mg_chm_h1,
{ "H1 (Message)", "mtp3mg.h1",
FT_UINT8, BASE_HEX, VALS(chm_h1_message_type_values), H1_MASK,
"Message type", HFILL }},
{ &hf_mtp3mg_ecm_h1,
{ "H1 (Message)", "mtp3mg.h1",
FT_UINT8, BASE_HEX, VALS(ecm_h1_message_type_values), H1_MASK,
"Message type", HFILL }},
{ &hf_mtp3mg_fcm_h1,
{ "H1 (Message)", "mtp3mg.h1",
FT_UINT8, BASE_HEX, VALS(fcm_h1_message_type_values), H1_MASK,
"Message type", HFILL }},
{ &hf_mtp3mg_tfm_h1,
{ "H1 (Message)", "mtp3mg.h1",
FT_UINT8, BASE_HEX, VALS(tfm_h1_message_type_values), H1_MASK,
"Message type", HFILL }},
{ &hf_mtp3mg_rsm_h1,
{ "H1 (Message)", "mtp3mg.h1",
FT_UINT8, BASE_HEX, VALS(rsm_h1_message_type_values), H1_MASK,
"Message type", HFILL }},
{ &hf_mtp3mg_mim_h1,
{ "H1 (Message)", "mtp3mg.h1",
FT_UINT8, BASE_HEX, VALS(mim_h1_message_type_values), H1_MASK,
"Message type", HFILL }},
{ &hf_mtp3mg_trm_h1,
{ "H1 (Message)", "mtp3mg.h1",
FT_UINT8, BASE_HEX, VALS(trm_h1_message_type_values), H1_MASK,
"Message type", HFILL }},
{ &hf_mtp3mg_dlm_h1,
{ "H1 (Message)", "mtp3mg.h1",
FT_UINT8, BASE_HEX, VALS(dlm_h1_message_type_values), H1_MASK,
"Message type", HFILL }},
{ &hf_mtp3mg_ufc_h1,
{ "H1 (Message)", "mtp3mg.h1",
FT_UINT8, BASE_HEX, VALS(ufc_h1_message_type_values), H1_MASK,
"Message type", HFILL }},
{ &hf_mtp3mg_coo_ansi_slc,
{ "Signalling Link Code", "mtp3mg.slc",
FT_UINT8, BASE_DEC, NULL, ANSI_COO_SLC_MASK,
"SLC of affected link", HFILL }},
{ &hf_mtp3mg_coo_ansi_fsn,
{ "Forward Sequence Number", "mtp3mg.fsn",
FT_UINT8, BASE_DEC, NULL, ANSI_COO_FSN_MASK,
"Forward Sequence Number of last accepted message", HFILL }},
{ &hf_mtp3mg_coo_itu_fsn,
{ "Forward Sequence Number", "mtp3mg.fsn",
FT_UINT8, BASE_DEC, NULL, ITU_COO_FSN_MASK,
"Forward Sequence Number of last accepted message", HFILL }},
{ &hf_mtp3mg_xco_ansi_slc,
{ "Signalling Link Code", "mtp3mg.slc",
FT_UINT32, BASE_DEC, NULL, ANSI_XCO_SLC_MASK,
"SLC of affected link", HFILL }},
{ &hf_mtp3mg_xco_ansi_fsn,
{ "Forward Sequence Number", "mtp3mg.fsn",
FT_UINT32, BASE_DEC, NULL, ANSI_XCO_FSN_MASK,
"Forward Sequence Number of last accepted message", HFILL }},
{ &hf_mtp3mg_xco_itu_fsn,
{ "Forward Sequence Number", "mtp3mg.fsn",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Forward Sequence Number of last accepted message", HFILL }},
{ &hf_mtp3mg_cbd_ansi_slc,
{ "Signalling Link Code", "mtp3mg.slc",
FT_UINT16, BASE_DEC, NULL, ANSI_CBD_SLC_MASK,
"SLC of affected link", HFILL }},
{ &hf_mtp3mg_cbd_ansi_cbc,
{ "Change Back Code", "mtp3mg.cbc",
FT_UINT16, BASE_DEC, NULL, ANSI_CBD_CBC_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_cbd_itu_cbc,
{ "Change Back Code", "mtp3mg.cbc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_cbd_japan_cbc,
{ "Change Back Code", "mtp3mg.cbc",
FT_UINT8, BASE_DEC, NULL, JAPAN_CBD_CBC_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_eco_ansi_slc,
{ "Signalling Link Code", "mtp3mg.slc",
FT_UINT8, BASE_DEC, NULL, ANSI_ECO_SLC_MASK,
"SLC of affected link", HFILL }},
{ &hf_mtp3mg_tfc_ansi_apc,
{ "Affected Point Code", "mtp3mg.ansi_apc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_tfc_apc_member,
{ "Affected Point Code member", "mtp3mg.apc.member",
FT_UINT24, BASE_DEC, NULL, ANSI_MEMBER_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfc_apc_cluster,
{ "Affected Point Code cluster", "mtp3mg.apc.cluster",
FT_UINT24, BASE_DEC, NULL, ANSI_CLUSTER_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfc_apc_network,
{ "Affected Point Code network", "mtp3mg.apc.network",
FT_UINT24, BASE_DEC, NULL, ANSI_NETWORK_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfc_ansi_status,
{ "Status", "mtp3mg.status",
FT_UINT8, BASE_DEC, NULL, ANSI_TFC_STATUS_MASK,
"Congestion status", HFILL }},
{ &hf_mtp3mg_tfc_itu_apc,
{ "Affected Point Code (ITU)", "mtp3mg.apc",
FT_UINT16, BASE_DEC, NULL, ITU_PC_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfc_itu_status,
{ "Status", "mtp3mg.status",
FT_UINT8, BASE_DEC, NULL, ITU_TFC_STATUS_MASK,
"Congestion status", HFILL }},
{ &hf_mtp3mg_tfc_chinese_apc,
{ "Affected Point Code", "mtp3mg.chinese_apc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_tfc_japan_spare,
{ "TFC spare (Japan)", "mtp3mg.japan_spare",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_tfc_japan_apc,
{ "Affected Point Code", "mtp3mg.japan_apc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_tfc_japan_status,
{ "Status", "mtp3mg.japan_status",
FT_UINT8, BASE_DEC, NULL, JAPAN_TFC_STATUS_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfc_japan_status_spare,
{ "Spare (Japan)", "mtp3mg.japan_spare",
FT_UINT8, BASE_HEX, NULL, JAPAN_TFC_STATUS_SPARE_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfm_ansi_apc,
{ "Affected Point Code", "mtp3mg.ansi_apc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_tfm_apc_member,
{ "Affected Point Code member", "mtp3mg.apc.member",
FT_UINT24, BASE_DEC, NULL, ANSI_MEMBER_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfm_apc_cluster,
{ "Affected Point Code cluster", "mtp3mg.apc.cluster",
FT_UINT24, BASE_DEC, NULL, ANSI_CLUSTER_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfm_apc_network,
{ "Affected Point Code network", "mtp3mg.apc.network",
FT_UINT24, BASE_DEC, NULL, ANSI_NETWORK_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfm_itu_apc,
{ "Affected Point Code (ITU)", "mtp3mg.apc",
FT_UINT16, BASE_DEC, NULL, ITU_PC_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_tfm_chinese_apc,
{ "Affected Point Code", "mtp3mg.chinese_apc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_tfm_japan_count,
{ "Count of Affected Point Codes (Japan)", "mtp3mg.japan_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_tfm_japan_apc,
{ "Affected Point Code", "mtp3mg.japan_apc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_tfm_japan_spare,
{ "Spare (Japan)", "mtp3mg.japan_spare",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_rsm_ansi_apc,
{ "Affected Point Code", "mtp3mg.ansi_apc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_rsm_apc_member,
{ "Affected Point Code member", "mtp3mg.apc.member",
FT_UINT24, BASE_DEC, NULL, ANSI_MEMBER_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_rsm_apc_cluster,
{ "Affected Point Code cluster", "mtp3mg.apc.cluster",
FT_UINT24, BASE_DEC, NULL, ANSI_CLUSTER_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_rsm_apc_network,
{ "Affected Point Code network", "mtp3mg.apc.network",
FT_UINT24, BASE_DEC, NULL, ANSI_NETWORK_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_rsm_itu_apc,
{ "Affected Point Code (ITU)", "mtp3mg.apc",
FT_UINT16, BASE_DEC, NULL, ITU_PC_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_rsm_chinese_apc,
{ "Affected Point Code", "mtp3mg.chinese_apc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_rsm_japan_count,
{ "Count of Affected Point Codes (Japan)", "mtp3mg.japan_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_rsm_japan_apc,
{ "Affected Point Code", "mtp3mg.japan_apc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_rsm_japan_spare,
{ "Spare (Japan)", "mtp3mg.japan_spare",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_mim_ansi_slc,
{ "Signalling Link Code", "mtp3mg.slc",
FT_UINT8, BASE_DEC, NULL, ANSI_MIM_SLC_MASK,
"SLC of affected link", HFILL }},
{ &hf_mtp3mg_dlc_ansi_slc,
{ "Signalling Link Code", "mtp3mg.slc",
FT_UINT8, BASE_DEC, NULL, ANSI_DLC_SLC_MASK,
"SLC of affected link", HFILL }},
{ &hf_mtp3mg_dlc_ansi_link,
{ "Link", "mtp3mg.link",
FT_UINT8, BASE_DEC, NULL, ANSI_DLC_LINK_MASK,
"CIC of BIC used to carry data", HFILL }},
{ &hf_mtp3mg_dlc_itu_link,
{ "Link", "mtp3mg.link",
FT_UINT8, BASE_DEC, NULL, ITU_DLC_LINK_MASK,
"CIC of BIC used to carry data", HFILL }},
{ &hf_mtp3mg_upu_ansi_apc,
{ "Affected Point Code", "mtp3mg.ansi_apc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_upu_apc_member,
{ "Affected Point Code member", "mtp3mg.apc.member",
FT_UINT24, BASE_DEC, NULL, ANSI_MEMBER_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_upu_apc_cluster,
{ "Affected Point Code cluster", "mtp3mg.apc.cluster",
FT_UINT24, BASE_DEC, NULL, ANSI_CLUSTER_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_upu_apc_network,
{ "Affected Point Code network", "mtp3mg.apc.network",
FT_UINT24, BASE_DEC, NULL, ANSI_NETWORK_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_upu_itu_apc,
{ "Affected Point Code", "mtp3mg.apc",
FT_UINT16, BASE_DEC, NULL, ITU_PC_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_upu_chinese_apc,
{ "Affected Point Code", "mtp3mg.chinese_apc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_upu_japan_apc,
{ "Affected Point Code", "mtp3mg.apc",
FT_UINT16, BASE_DEC, NULL, JAPAN_PC_MASK,
NULL, HFILL }},
{ &hf_mtp3mg_upu_user,
{ "User", "mtp3mg.user",
FT_UINT8, BASE_HEX, VALS(service_indicator_code_vals), UPU_USER_MASK,
"Unavailable user part", HFILL }},
{ &hf_mtp3mg_upu_cause,
{ "Cause", "mtp3mg.cause",
FT_UINT8, BASE_HEX, VALS(upu_cause_values), UPU_CAUSE_MASK,
"Cause of user unavailability", HFILL }},
{ &hf_mtp3test_h0,
{ "H0 (Message Group)", "mtp3mg.test.h0",
FT_UINT8, BASE_HEX, VALS(test_h0_message_type_values), H0_MASK,
"Message group identifier", HFILL }},
{ &hf_mtp3mg_test_h1,
{ "H1 (Message)", "mtp3mg.test.h1",
FT_UINT8, BASE_HEX, VALS(test_h1_message_type_values), H1_MASK,
"SLT message type", HFILL }},
{ &hf_mtp3mg_test_length,
{ "Test length", "mtp3mg.test.length",
FT_UINT8, BASE_DEC, NULL, H1_MASK,
"Signalling link test pattern length", HFILL }},
{ &hf_mtp3mg_japan_test,
{ "Japan test message", "mtp3mg.test",
FT_UINT8, BASE_HEX, VALS(japan_test_message_type_values), 0x0,
"Japan test message type", HFILL }},
{ &hf_mtp3mg_japan_test_spare,
{ "Japan test message spare", "mtp3mg.test.spare",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_japan_test_pattern,
{ "Japan test message pattern", "mtp3mg.test.pattern",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_japan_spare,
{ "Japan management spare", "mtp3mg.spare",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_mtp3mg_test_ansi_slc,
{ "Signalling Link Code", "mtp3mg.slc",
FT_UINT8, BASE_DEC, NULL, ANSI_TEST_SLC_MASK,
"SLC of affected link", HFILL }}
};
static gint *ett[] = {
&ett_mtp3mg,
&ett_mtp3mg_fcm_apc,
&ett_mtp3mg_tfm_apc,
&ett_mtp3mg_rsm_apc,
&ett_mtp3mg_upu_apc
};
proto_mtp3mg = proto_register_protocol("Message Transfer Part Level 3 Management",
"MTP3MG", "mtp3mg");
register_dissector("mtp3mg", dissect_mtp3mg, proto_mtp3mg);
proto_register_field_array(proto_mtp3mg, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mtp3mg(void)
{
dissector_handle_t mtp3mg_handle;
mtp3mg_handle = find_dissector("mtp3mg");
dissector_add_uint("mtp3.service_indicator", MTP_SI_SNM, mtp3mg_handle);
dissector_add_uint("mtp3.service_indicator", MTP_SI_MTN, mtp3mg_handle);
dissector_add_uint("mtp3.service_indicator", MTP_SI_MTNS, mtp3mg_handle);
}
