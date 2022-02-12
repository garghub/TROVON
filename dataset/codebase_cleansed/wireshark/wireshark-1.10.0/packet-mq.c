static guint32 tvb_get_guint32_endian(tvbuff_t *a_tvb, gint a_iOffset, gint a_rep)
{
guint32 iResult;
if (a_rep & ENC_LITTLE_ENDIAN)
iResult = tvb_get_letohl(a_tvb, a_iOffset);
else
iResult = tvb_get_ntohl(a_tvb, a_iOffset);
return iResult;
}
static gint strip_trailing_blanks(guint8* a_string, gint a_size)
{
gint i = 0;
if (a_string != NULL)
{
for (i = 0; i < a_size; i++)
{
if (a_string[i] == ' ' || a_string[i] == '\0')
{
a_string[i] = '\0';
break;
}
}
}
return i;
}
static gint
dissect_mq_md(tvbuff_t *tvb, proto_tree *tree, gint int_rep, gint string_rep, gint offset, struct mq_msg_properties* tMsgProps)
{
proto_tree *mq_tree = NULL;
guint32 structId;
gint iSizeMD = 0;
if (tvb_length_remaining(tvb, offset) >= 4)
{
structId = tvb_get_ntohl(tvb, offset);
if ((structId == MQ_STRUCTID_MD || structId == MQ_STRUCTID_MD_EBCDIC) && tvb_length_remaining(tvb, offset) >= 8)
{
guint32 iVersionMD = 0;
iVersionMD = tvb_get_guint32_endian(tvb, offset + 4, int_rep);
switch (iVersionMD)
{
case 1: iSizeMD = 324; break;
case 2: iSizeMD = 364; break;
}
if (iSizeMD != 0 && tvb_length_remaining(tvb, offset) >= iSizeMD)
{
tMsgProps->iOffsetEncoding = offset + 24;
tMsgProps->iOffsetCcsid = offset + 28;
tMsgProps->iOffsetFormat = offset + 32;
if (tree)
{
proto_item *ti = NULL;
ti = proto_tree_add_text(tree, tvb, offset, iSizeMD, MQ_TEXT_MD);
mq_tree = proto_item_add_subtree(ti, ett_mq_md);
proto_tree_add_item(mq_tree, hf_mq_md_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_md_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_report, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_msgtype, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_expiry, tvb, offset + 16, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_feedback, tvb, offset + 20, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_encoding, tvb, offset + 24, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_ccsid, tvb, offset + 28, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_format, tvb, offset + 32, 8, string_rep);
proto_tree_add_item(mq_tree, hf_mq_md_priority, tvb, offset + 40, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_persistence, tvb, offset + 44, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_msgid, tvb, offset + 48, 24, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_correlid, tvb, offset + 72, 24, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_backountcount, tvb, offset + 96, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_replytoq, tvb, offset + 100, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_md_replytoqmgr, tvb, offset + 148, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_md_userid, tvb, offset + 196, 12, string_rep);
proto_tree_add_item(mq_tree, hf_mq_md_acttoken, tvb, offset + 208, 32, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_appliddata, tvb, offset + 240, 32, string_rep);
proto_tree_add_item(mq_tree, hf_mq_md_putappltype, tvb, offset + 272, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_putapplname, tvb, offset + 276, 28, string_rep);
proto_tree_add_item(mq_tree, hf_mq_md_putdate, tvb, offset + 304, 8, string_rep);
proto_tree_add_item(mq_tree, hf_mq_md_puttime, tvb, offset + 312, 8, string_rep);
proto_tree_add_item(mq_tree, hf_mq_md_applorigindata, tvb, offset + 320, 4, string_rep);
if (iVersionMD >= 2)
{
proto_tree_add_item(mq_tree, hf_mq_md_groupid, tvb, offset + 324, 24, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_msgseqnumber, tvb, offset + 348, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_offset, tvb, offset + 352, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_msgflags, tvb, offset + 356, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_originallength, tvb, offset + 360, 4, int_rep);
}
}
}
}
}
return iSizeMD;
}
static gint
dissect_mq_or(tvbuff_t *tvb, proto_tree *tree, int string_rep, gint offset, gint iNbrRecords, gint offsetOR)
{
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
gint iSizeOR = 0;
if (offsetOR != 0)
{
iSizeOR = iNbrRecords * 96;
if (tvb_length_remaining(tvb, offset) >= iSizeOR)
{
if (tree)
{
gint iOffsetOR = 0;
gint iRecord = 0;
for (iRecord = 0; iRecord < iNbrRecords ; iRecord++)
{
ti = proto_tree_add_text(tree, tvb, offset + iOffsetOR, 96, MQ_TEXT_OR);
mq_tree = proto_item_add_subtree(ti, ett_mq_or);
proto_tree_add_item(mq_tree, hf_mq_or_objname, tvb, offset + iOffsetOR, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_or_objqmgrname, tvb, offset + iOffsetOR + 48, 48, string_rep);
iOffsetOR += 96;
}
}
}
else iSizeOR = 0;
}
return iSizeOR;
}
static gint
dissect_mq_rr(tvbuff_t *tvb, proto_tree *tree, gint int_rep, gint offset, gint iNbrRecords, gint offsetRR)
{
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
gint iSizeRR = 0;
if (offsetRR != 0)
{
iSizeRR = iNbrRecords * 8;
if (tvb_length_remaining(tvb, offset) >= iSizeRR)
{
if (tree)
{
gint iOffsetRR = 0;
gint iRecord = 0;
for (iRecord = 0; iRecord < iNbrRecords; iRecord++)
{
ti = proto_tree_add_text(tree, tvb, offset + iOffsetRR, 8, MQ_TEXT_RR);
mq_tree = proto_item_add_subtree(ti, ett_mq_rr);
proto_tree_add_item(mq_tree, hf_mq_rr_completioncode, tvb, offset + iOffsetRR, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_rr_reasoncode, tvb, offset + iOffsetRR + 4, 4, int_rep);
iOffsetRR += 8;
}
}
}
else iSizeRR = 0;
}
return iSizeRR;
}
static gint
dissect_mq_pmr(tvbuff_t *tvb, proto_tree *tree, gint int_rep, gint offset, gint iNbrRecords, gint offsetPMR, guint32 recFlags)
{
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
gint iSizePMR1 = 0;
gint iSizePMR = 0;
iSizePMR1 = ((((recFlags & MQ_PMRF_MSG_ID) != 0) * 24)
+(((recFlags & MQ_PMRF_CORREL_ID) != 0) * 24)
+(((recFlags & MQ_PMRF_GROUP_ID) != 0) * 24)
+(((recFlags & MQ_PMRF_FEEDBACK) != 0) * 4)
+(((recFlags & MQ_PMRF_ACCOUNTING_TOKEN) != 0) * 32));
if (offsetPMR != 0)
{
iSizePMR = iNbrRecords * iSizePMR1;
if (tvb_length_remaining(tvb, offset) >= iSizePMR)
{
if (tree)
{
gint iOffsetPMR = 0;
gint iRecord = 0;
for (iRecord = 0; iRecord < iNbrRecords; iRecord++)
{
ti = proto_tree_add_text(tree, tvb, offset + iOffsetPMR, iSizePMR1, MQ_TEXT_PMR);
mq_tree = proto_item_add_subtree(ti, ett_mq_pmr);
if ((recFlags & MQ_PMRF_MSG_ID) != 0)
{
proto_tree_add_item(mq_tree, hf_mq_pmr_msgid, tvb, offset + iOffsetPMR, 24, ENC_NA);
iOffsetPMR += 24;
}
if ((recFlags & MQ_PMRF_CORREL_ID) != 0)
{
proto_tree_add_item(mq_tree, hf_mq_pmr_correlid, tvb, offset + iOffsetPMR, 24, ENC_NA);
iOffsetPMR += 24;
}
if ((recFlags & MQ_PMRF_GROUP_ID) != 0)
{
proto_tree_add_item(mq_tree, hf_mq_pmr_groupid, tvb, offset + iOffsetPMR, 24, ENC_NA);
iOffsetPMR += 24;
}
if ((recFlags & MQ_PMRF_FEEDBACK) != 0)
{
proto_tree_add_item(mq_tree, hf_mq_pmr_feedback, tvb, offset + iOffsetPMR, 4, int_rep);
iOffsetPMR += 4;
}
if ((recFlags & MQ_PMRF_ACCOUNTING_TOKEN) != 0)
{
proto_tree_add_item(mq_tree, hf_mq_pmr_acttoken, tvb, offset + iOffsetPMR, 32, ENC_NA);
iOffsetPMR += 32;
}
}
}
}
else iSizePMR = 0;
}
return iSizePMR;
}
static gint
dissect_mq_gmo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint int_rep, gint string_rep, gint offset)
{
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
guint32 structId;
gint iSizeGMO = 0;
if (tvb_length_remaining(tvb, offset) >= 4)
{
structId = tvb_get_ntohl(tvb, offset);
if ((structId == MQ_STRUCTID_GMO || structId == MQ_STRUCTID_GMO_EBCDIC) && tvb_length_remaining(tvb, offset) >= 8)
{
guint32 iVersionGMO = 0;
iVersionGMO = tvb_get_guint32_endian(tvb, offset + 4, int_rep);
switch (iVersionGMO)
{
case 1: iSizeGMO = 72; break;
case 2: iSizeGMO = 80; break;
case 3: iSizeGMO = 100; break;
}
if (iSizeGMO != 0 && tvb_length_remaining(tvb, offset) >= iSizeGMO)
{
if (check_col(pinfo->cinfo, COL_INFO))
{
guint8* sQueue;
sQueue = tvb_get_ephemeral_string_enc(tvb, offset + 24, 48, string_rep);
if (strip_trailing_blanks(sQueue, 48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Q=%s", sQueue);
}
}
if (tree)
{
ti = proto_tree_add_text(tree, tvb, offset, iSizeGMO, MQ_TEXT_GMO);
mq_tree = proto_item_add_subtree(ti, ett_mq_gmo);
proto_tree_add_item(mq_tree, hf_mq_gmo_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_gmo_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_gmo_options, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_gmo_waitinterval, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_gmo_signal1, tvb, offset + 16, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_gmo_signal2, tvb, offset + 20, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_gmo_resolvedqname, tvb, offset + 24, 48, string_rep);
if (iVersionGMO >= 2)
{
proto_tree_add_item(mq_tree, hf_mq_gmo_matchoptions, tvb, offset + 72, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_gmo_groupstatus, tvb, offset + 76, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_gmo_segmentstatus, tvb, offset + 77, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_gmo_segmentation, tvb, offset + 78, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_gmo_reserved, tvb, offset + 79, 1, ENC_BIG_ENDIAN);
}
if (iVersionGMO >= 3)
{
proto_tree_add_item(mq_tree, hf_mq_gmo_msgtoken, tvb, offset + 80, 16, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_gmo_returnedlength, tvb, offset + 96, 4, int_rep);
}
}
}
}
}
return iSizeGMO;
}
static gint
dissect_mq_pmo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint int_rep, gint string_rep, gint offset, gint* iDistributionListSize)
{
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
guint32 structId;
gint iSizePMO = 0;
if (tvb_length_remaining(tvb, offset) >= 4)
{
structId = tvb_get_ntohl(tvb, offset);
if ((structId == MQ_STRUCTID_PMO || structId == MQ_STRUCTID_PMO_EBCDIC) && tvb_length_remaining(tvb, offset) >= 8)
{
guint32 iVersionPMO = 0;
iVersionPMO = tvb_get_guint32_endian(tvb, offset + 4, int_rep);
switch (iVersionPMO)
{
case 1: iSizePMO = 128; break;
case 2: iSizePMO = 152;break;
}
if (iSizePMO != 0 && tvb_length_remaining(tvb, offset) >= iSizePMO)
{
gint iNbrRecords = 0;
guint32 iRecFlags = 0;
if (iVersionPMO >= 2)
{
iNbrRecords = tvb_get_guint32_endian(tvb, offset + 128, int_rep);
iRecFlags = tvb_get_guint32_endian(tvb, offset + 132, int_rep);
}
if (check_col(pinfo->cinfo, COL_INFO))
{
guint8* sQueue;
sQueue = tvb_get_ephemeral_string_enc(tvb, offset + 32, 48, string_rep);
if (strip_trailing_blanks(sQueue, 48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Q=%s", sQueue);
}
}
if (tree)
{
ti = proto_tree_add_text(tree, tvb, offset, iSizePMO, MQ_TEXT_PMO);
mq_tree = proto_item_add_subtree(ti, ett_mq_pmo);
proto_tree_add_item(mq_tree, hf_mq_pmo_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_options, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_timeout, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_context, tvb, offset + 16, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_knowndestcount, tvb, offset + 20, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_unknowndestcount, tvb, offset + 24, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_invaliddestcount, tvb, offset + 28, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_resolvedqname, tvb, offset + 32, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_resolvedqmgrname, tvb, offset + 80, 48, string_rep);
if (iVersionPMO >= 2)
{
proto_tree_add_item(mq_tree, hf_mq_pmo_recspresent, tvb, offset + 128, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_putmsgrecfields, tvb, offset + 132, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_putmsgrecoffset, tvb, offset + 136, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_responserecoffset, tvb, offset + 140, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_putmsgrecptr, tvb, offset + 144, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_pmo_responserecptr, tvb, offset + 148, 4, int_rep);
}
}
if (iNbrRecords > 0)
{
gint iOffsetPMR = 0;
gint iOffsetRR = 0;
gint iSizePMRRR = 0;
*iDistributionListSize = iNbrRecords;
iOffsetPMR = tvb_get_guint32_endian(tvb, offset + 136, int_rep);
iOffsetRR = tvb_get_guint32_endian(tvb, offset + 140, int_rep);
if ((iSizePMRRR = dissect_mq_pmr(tvb, tree, int_rep, offset + iSizePMO, iNbrRecords, iOffsetPMR, iRecFlags)) != 0)
iSizePMO += iSizePMRRR;
if ((iSizePMRRR = dissect_mq_rr(tvb, tree, int_rep, offset + iSizePMO, iNbrRecords, iOffsetRR)) != 0)
iSizePMO += iSizePMRRR;
}
}
}
}
return iSizePMO;
}
static gint
dissect_mq_xid(tvbuff_t *tvb, proto_tree *tree, gint int_rep, gint offset)
{
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
gint iSizeXid = 0;
if (tvb_length_remaining(tvb, offset) >= 6)
{
guint8 iXidLength = 0;
guint8 iBqLength = 0;
iXidLength = tvb_get_guint8(tvb, offset + 4);
iBqLength = tvb_get_guint8(tvb, offset + 5);
iSizeXid = 6 + iXidLength + iBqLength;
if (tvb_length_remaining(tvb, offset) >= iSizeXid)
{
if (tree)
{
ti = proto_tree_add_text(tree, tvb, offset, iSizeXid, MQ_TEXT_XID);
mq_tree = proto_item_add_subtree(ti, ett_mq_xa_xid);
proto_tree_add_item(mq_tree, hf_mq_xa_xid_formatid, tvb, offset, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_xa_xid_globalxid_length, tvb, offset + 4, 1, int_rep);
proto_tree_add_item(mq_tree, hf_mq_xa_xid_brq_length, tvb, offset + 5, 1, int_rep);
proto_tree_add_item(mq_tree, hf_mq_xa_xid_globalxid, tvb, offset + 6, iXidLength, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_xa_xid_brq, tvb, offset + 6 + iXidLength, iBqLength, ENC_NA);
}
iSizeXid += (4 - (iSizeXid % 4)) % 4;
if (tvb_length_remaining(tvb, offset) < iSizeXid) iSizeXid = 0;
}
else iSizeXid = 0;
}
return iSizeXid;
}
static void
dissect_mq_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *mq_tree = NULL;
proto_tree *mqroot_tree = NULL;
proto_item *ti = NULL;
gint offset = 0;
guint32 structId = MQ_STRUCTID_NULL;
guint8 opcode;
guint32 iSegmentLength = 0;
guint32 iSizePayload = 0;
gint iSizeMD_gbl = 0;
gint int_rep = ENC_BIG_ENDIAN;
gint string_rep = ENC_UTF_8|ENC_NA;
gboolean bPayload = FALSE;
gboolean bEBCDIC = FALSE;
gint iDistributionListSize = 0;
struct mq_msg_properties tMsgProps;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MQ");
tMsgProps.iOffsetFormat = 0;
if (tvb_length(tvb) >= 4)
{
structId = tvb_get_ntohl(tvb, offset);
if ((structId == MQ_STRUCTID_TSH || structId == MQ_STRUCTID_TSH_EBCDIC
|| structId == MQ_STRUCTID_TSHC || structId == MQ_STRUCTID_TSHC_EBCDIC
|| structId == MQ_STRUCTID_TSHM || structId == MQ_STRUCTID_TSHM_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 28)
{
gint iSizeTSH = 28;
gint iSizeMultiplexFields = 0;
guint8 iControlFlags = 0;
if (structId == MQ_STRUCTID_TSH_EBCDIC || structId == MQ_STRUCTID_TSHC_EBCDIC || structId == MQ_STRUCTID_TSHM_EBCDIC) {
bEBCDIC = TRUE;
string_rep = ENC_EBCDIC|ENC_NA;
}
iSegmentLength = tvb_get_ntohl(tvb, offset + 4);
if (structId == MQ_STRUCTID_TSHM || structId == MQ_STRUCTID_TSHM_EBCDIC)
{
if (tvb_length_remaining(tvb, offset) < 36) return;
iSizeMultiplexFields += 8;
iSizeTSH = 36;
}
opcode = tvb_get_guint8(tvb, offset + iSizeMultiplexFields + 9);
int_rep = (tvb_get_guint8(tvb, offset + iSizeMultiplexFields + 8) == MQ_LITTLE_ENDIAN ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
iControlFlags = tvb_get_guint8(tvb, offset + iSizeMultiplexFields + 10);
if (check_col(pinfo->cinfo, COL_INFO))
{
col_clear(pinfo->cinfo, COL_INFO);
col_append_sep_str(pinfo->cinfo, COL_INFO, " | ", val_to_str_ext(opcode, &mq_opcode_vals_ext, "Unknown (0x%02x)"));
col_set_fence(pinfo->cinfo, COL_INFO);
}
if (tree)
{
ti = proto_tree_add_item(tree, proto_mq, tvb, offset, -1, ENC_NA);
proto_item_append_text(ti, " (%s)", val_to_str(opcode, mq_opcode_vals, "Unknown (0x%02x)"));
if (bEBCDIC == TRUE) proto_item_append_text(ti, " (EBCDIC)");
mqroot_tree = proto_item_add_subtree(ti, ett_mq);
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeTSH, MQ_TEXT_TSH);
mq_tree = proto_item_add_subtree(ti, ett_mq_tsh);
proto_tree_add_item(mq_tree, hf_mq_tsh_structid, tvb, offset + 0, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_tsh_packetlength, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
if (iSizeTSH == 36)
{
proto_tree_add_item(mq_tree, hf_mq_tsh_convid, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_tsh_requestid, tvb, offset + 12, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(mq_tree, hf_mq_tsh_byteorder, tvb, offset + iSizeMultiplexFields + 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_tsh_opcode, tvb, offset + iSizeMultiplexFields + 9, 1, ENC_BIG_ENDIAN);
{
proto_tree *mq_tree_sub = NULL;
ti = proto_tree_add_item(mq_tree, hf_mq_tsh_controlflags, tvb, offset + iSizeMultiplexFields + 10, 1, ENC_BIG_ENDIAN);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_tsh_tcf);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_dlq, tvb, offset + iSizeMultiplexFields + 10, 1, iControlFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_reqacc, tvb, offset + iSizeMultiplexFields + 10, 1, iControlFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_last, tvb, offset + iSizeMultiplexFields + 10, 1, iControlFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_first, tvb, offset + iSizeMultiplexFields + 10, 1, iControlFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_closechann, tvb, offset + iSizeMultiplexFields + 10, 1, iControlFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_reqclose, tvb, offset + iSizeMultiplexFields + 10, 1, iControlFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_error, tvb, offset + iSizeMultiplexFields + 10, 1, iControlFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_confirmreq, tvb, offset + iSizeMultiplexFields + 10, 1, iControlFlags);
}
proto_tree_add_item(mq_tree, hf_mq_tsh_reserved, tvb, offset + iSizeMultiplexFields + 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_tsh_luwid, tvb, offset + iSizeMultiplexFields + 12, 8, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_tsh_encoding, tvb, offset + iSizeMultiplexFields + 20, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_tsh_ccsid, tvb, offset + iSizeMultiplexFields + 24, 2, int_rep);
proto_tree_add_item(mq_tree, hf_mq_tsh_padding, tvb, offset + iSizeMultiplexFields + 26, 2, ENC_BIG_ENDIAN);
}
offset += iSizeTSH;
if (tvb_length_remaining(tvb, offset) >= 4)
{
structId = tvb_get_ntohl(tvb, offset);
if (((iControlFlags & MQ_TCF_FIRST) != 0) || opcode < 0x80)
{
gint iSizeAPI = 16;
if (opcode >= 0x80 && opcode <= 0x9F && tvb_length_remaining(tvb, offset) >= 16)
{
guint32 iReturnCode = 0;
iReturnCode = tvb_get_guint32_endian(tvb, offset + 8, int_rep);
if (check_col(pinfo->cinfo, COL_INFO))
{
if (iReturnCode != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, " [RC=%d]", iReturnCode);
}
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeAPI, MQ_TEXT_API);
mq_tree = proto_item_add_subtree(ti, ett_mq_api);
proto_tree_add_item(mq_tree, hf_mq_api_replylength, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_api_completioncode, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_api_reasoncode, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_api_objecthandle, tvb, offset + 12, 4, int_rep);
}
offset += iSizeAPI;
structId = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((structId == MQ_STRUCTID_MSH || structId == MQ_STRUCTID_MSH_EBCDIC) && tvb_length_remaining(tvb, offset) >= 20)
{
gint iSizeMSH = 20;
iSizePayload = tvb_get_guint32_endian(tvb, offset + 16, int_rep);
bPayload = TRUE;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeMSH, MQ_TEXT_MSH);
mq_tree = proto_item_add_subtree(ti, ett_mq_msh);
proto_tree_add_item(mq_tree, hf_mq_msh_structid, tvb, offset + 0, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_msh_seqnum, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_msh_datalength, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_msh_unknown1, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_msh_msglength, tvb, offset + 16, 4, int_rep);
}
offset += iSizeMSH;
}
else if (opcode == MQ_TST_STATUS && tvb_length_remaining(tvb, offset) >= 8)
{
guint32 iStatus = 0;
gint iStatusLength = 0;
iStatus = tvb_get_guint32_endian(tvb, offset + 4, int_rep);
iStatusLength = tvb_get_guint32_endian(tvb, offset, int_rep);
if (tvb_length_remaining(tvb, offset) >= iStatusLength)
{
if (check_col(pinfo->cinfo, COL_INFO))
{
if (iStatus != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ": Code=%s", val_to_str(iStatus, mq_status_vals, "Unknown (0x%08x)"));
}
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 8, MQ_TEXT_STAT);
mq_tree = proto_item_add_subtree(ti, ett_mq_status);
proto_tree_add_item(mq_tree, hf_mq_status_length, tvb, offset, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_status_code, tvb, offset + 4, 4, int_rep);
if (iStatusLength >= 12)
proto_tree_add_item(mq_tree, hf_mq_status_value, tvb, offset + 8, 4, int_rep);
}
offset += iStatusLength;
}
}
else if (opcode == MQ_TST_PING && tvb_length_remaining(tvb, offset) > 4)
{
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, MQ_TEXT_PING);
mq_tree = proto_item_add_subtree(ti, ett_mq_ping);
proto_tree_add_item(mq_tree, hf_mq_ping_length, tvb, offset, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_ping_buffer, tvb, offset + 4, -1, ENC_NA);
}
offset = tvb_length(tvb);
}
else if (opcode == MQ_TST_RESET && tvb_length_remaining(tvb, offset) >= 8)
{
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, MQ_TEXT_RESET);
mq_tree = proto_item_add_subtree(ti, ett_mq_reset);
proto_tree_add_item(mq_tree, hf_mq_reset_length, tvb, offset, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_reset_seqnum, tvb, offset + 4, 4, int_rep);
}
offset = tvb_length(tvb);
}
else if (opcode == MQ_TST_MQCONN && tvb_length_remaining(tvb, offset) > 0)
{
gint iSizeCONN = 0;
iSizeCONN = iSegmentLength - iSizeTSH - iSizeAPI;
if (iSizeCONN != 112 && iSizeCONN != 120) iSizeCONN = 0;
if (iSizeCONN != 0 && tvb_length_remaining(tvb, offset) >= iSizeCONN)
{
if (check_col(pinfo->cinfo, COL_INFO))
{
guint8* sApplicationName;
guint8* sQueueManager;
sApplicationName = tvb_get_ephemeral_string_enc(tvb, offset + 48, 28, string_rep);
if (strip_trailing_blanks(sApplicationName, 28) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ": App=%s", sApplicationName);
}
sQueueManager = tvb_get_ephemeral_string_enc(tvb, offset, 48, string_rep);
if (strip_trailing_blanks(sQueueManager, 48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " QM=%s", sQueueManager);
}
}
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeCONN, MQ_TEXT_CONN);
mq_tree = proto_item_add_subtree(ti, ett_mq_conn);
proto_tree_add_item(mq_tree, hf_mq_conn_queuemanager, tvb, offset, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_conn_appname, tvb, offset + 48, 28, string_rep);
proto_tree_add_item(mq_tree, hf_mq_conn_apptype, tvb, offset + 76, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_conn_acttoken, tvb, offset + 80, 32, ENC_NA);
if (iSizeCONN >= 120)
{
proto_tree_add_item(mq_tree, hf_mq_conn_version, tvb, offset + 112, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_conn_options, tvb, offset + 116, 4, int_rep);
}
}
offset += iSizeCONN;
}
}
else if ((opcode == MQ_TST_MQINQ || opcode == MQ_TST_MQINQ_REPLY || opcode == MQ_TST_MQSET) && tvb_length_remaining(tvb, offset) >= 12)
{
gint iNbSelectors = 0;
gint iNbIntegers = 0;
gint iCharLen = 0;
gint iOffsetINQ = 0;
gint iSelector = 0;
iNbSelectors = tvb_get_guint32_endian(tvb, offset, int_rep);
iNbIntegers = tvb_get_guint32_endian(tvb, offset + 4, int_rep);
iCharLen = tvb_get_guint32_endian(tvb, offset + 8, int_rep);
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, MQ_TEXT_INQ);
mq_tree = proto_item_add_subtree(ti, ett_mq_inq);
proto_tree_add_item(mq_tree, hf_mq_inq_nbsel, tvb, offset, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_inq_nbint, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_inq_charlen, tvb, offset + 8, 4, int_rep);
}
iOffsetINQ = 12;
if (tvb_length_remaining(tvb, offset + iOffsetINQ) >= iNbSelectors * 4)
{
if (tree)
{
for (iSelector = 0; iSelector < iNbSelectors; iSelector++)
{
proto_tree_add_item(mq_tree, hf_mq_inq_sel, tvb, offset + iOffsetINQ + iSelector * 4, 4, int_rep);
}
}
iOffsetINQ += iNbSelectors * 4;
if (opcode == MQ_TST_MQINQ_REPLY || opcode == MQ_TST_MQSET)
{
gint iSizeINQValues = 0;
iSizeINQValues = iNbIntegers * 4 + iCharLen;
if (tvb_length_remaining(tvb, offset + iOffsetINQ) >= iSizeINQValues)
{
gint iInteger = 0;
if (tree)
{
for (iInteger = 0; iInteger < iNbIntegers; iInteger++)
{
proto_tree_add_item(mq_tree, hf_mq_inq_intvalue, tvb, offset + iOffsetINQ + iInteger * 4, 4, int_rep);
}
}
iOffsetINQ += iNbIntegers * 4;
if (iCharLen != 0)
{
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_inq_charvalues, tvb, offset + iOffsetINQ, iCharLen, string_rep);
}
}
}
}
}
offset += tvb_length(tvb);
}
else if ((opcode == MQ_TST_SPI || opcode == MQ_TST_SPI_REPLY) && tvb_length_remaining(tvb, offset) >= 12)
{
gint iOffsetSPI = 0;
guint32 iSpiVerb = 0;
iSpiVerb = tvb_get_guint32_endian(tvb, offset, int_rep);
if (check_col(pinfo->cinfo, COL_INFO))
{
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", val_to_str(iSpiVerb, mq_spi_verbs_vals, "Unknown (0x%08x)"));
}
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 12, MQ_TEXT_SPI);
mq_tree = proto_item_add_subtree(ti, ett_mq_spi);
proto_tree_add_item(mq_tree, hf_mq_spi_verb, tvb, offset, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_length, tvb, offset + 8, 4, int_rep);
}
offset += 12;
structId = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
if ((structId == MQ_STRUCTID_SPQU || structId == MQ_STRUCTID_SPAU_EBCDIC
|| structId == MQ_STRUCTID_SPPU || structId == MQ_STRUCTID_SPPU_EBCDIC
|| structId == MQ_STRUCTID_SPGU || structId == MQ_STRUCTID_SPGU_EBCDIC
|| structId == MQ_STRUCTID_SPAU || structId == MQ_STRUCTID_SPAU_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 12)
{
gint iSizeSPIMD = 0;
if (tree)
{
guint8* sStructId;
sStructId = tvb_get_ephemeral_string(tvb, offset, 4);
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 12, "%s", sStructId);
mq_tree = proto_item_add_subtree(ti, ett_mq_spi_base);
proto_tree_add_item(mq_tree, hf_mq_spi_base_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_base_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_base_length, tvb, offset + 8, 4, int_rep);
}
offset += 12;
structId = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
if ((iSizeSPIMD = dissect_mq_md(tvb, mqroot_tree, int_rep, string_rep, offset, &tMsgProps)) != 0)
{
gint iSizeGMO = 0;
gint iSizePMO = 0;
offset += iSizeSPIMD;
if ((iSizeGMO = dissect_mq_gmo(tvb, pinfo, mqroot_tree, int_rep, string_rep, offset)) != 0)
{
offset += iSizeGMO;
}
else if ((iSizePMO = dissect_mq_pmo(tvb, pinfo, mqroot_tree, int_rep, string_rep, offset, &iDistributionListSize)) != 0)
{
offset += iSizePMO;
}
structId = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((structId == MQ_STRUCTID_SPQO || structId == MQ_STRUCTID_SPQO_EBCDIC
|| structId == MQ_STRUCTID_SPQI || structId == MQ_STRUCTID_SPQI_EBCDIC
|| structId == MQ_STRUCTID_SPPO || structId == MQ_STRUCTID_SPPO_EBCDIC
|| structId == MQ_STRUCTID_SPPI || structId == MQ_STRUCTID_SPPI_EBCDIC
|| structId == MQ_STRUCTID_SPGO || structId == MQ_STRUCTID_SPGO_EBCDIC
|| structId == MQ_STRUCTID_SPGI || structId == MQ_STRUCTID_SPGI_EBCDIC
|| structId == MQ_STRUCTID_SPAO || structId == MQ_STRUCTID_SPAO_EBCDIC
|| structId == MQ_STRUCTID_SPAI || structId == MQ_STRUCTID_SPAI_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 12)
{
if (tree)
{
guint8* sStructId;
sStructId = tvb_get_ephemeral_string(tvb, offset, 4);
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, "%s", sStructId);
mq_tree = proto_item_add_subtree(ti, ett_mq_spi_base);
proto_tree_add_item(mq_tree, hf_mq_spi_base_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_base_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_base_length, tvb, offset + 8, 4, int_rep);
}
if (structId == MQ_STRUCTID_SPQO && tvb_length_remaining(tvb, offset) >= 16)
{
if (tree)
{
gint iVerbNumber = 0;
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_nbverb, tvb, offset + 12, 4, int_rep);
iVerbNumber = tvb_get_guint32_endian(tvb, offset + 12, int_rep);
if (tvb_length_remaining(tvb, offset) >= iVerbNumber * 20 + 16)
{
gint iVerb = 0;
iOffsetSPI = offset + 16;
for (iVerb = 0; iVerb < iVerbNumber; iVerb++)
{
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_verbid, tvb, iOffsetSPI, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_maxinoutversion, tvb, iOffsetSPI + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_maxinversion, tvb, iOffsetSPI + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_maxoutversion, tvb, iOffsetSPI + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_flags, tvb, iOffsetSPI + 16, 4, int_rep);
iOffsetSPI += 20;
}
offset += iVerbNumber * 20 + 16;
}
}
}
else if (structId == MQ_STRUCTID_SPAI && tvb_length_remaining(tvb, offset) >= 136)
{
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_spi_spai_mode, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_spai_unknown1, tvb, offset + 16, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_spai_unknown2, tvb, offset + 64, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_spai_msgid, tvb, offset + 112, 24, string_rep);
}
offset += 136;
}
else if (structId == MQ_STRUCTID_SPGI && tvb_length_remaining(tvb, offset) >= 24)
{
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_spi_spgi_batchsize, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_spgi_batchint, tvb, offset + 16, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_spi_spgi_maxmsgsize, tvb, offset + 20, 4, int_rep);
}
offset += 24;
}
else if ((structId == MQ_STRUCTID_SPGO || structId == MQ_STRUCTID_SPPI) && tvb_length_remaining(tvb, offset) >= 20)
{
if (tree)
{
{
proto_tree *mq_tree_sub = NULL;
gint iOptionsFlags;
ti = proto_tree_add_item(mq_tree, hf_mq_spi_spgo_options, tvb, offset + 12, 4, int_rep);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_spi_options);
iOptionsFlags = tvb_get_guint32_endian(tvb, offset + 12, int_rep);
proto_tree_add_boolean(mq_tree_sub, hf_mq_spi_options_deferred, tvb, offset + 12, 4, iOptionsFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_spi_options_syncpoint, tvb, offset + 12, 4, iOptionsFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_spi_options_blank, tvb, offset + 12, 4, iOptionsFlags);
}
proto_tree_add_item(mq_tree, hf_mq_spi_spgo_size, tvb, offset + 16, 4, int_rep);
}
iSizePayload = tvb_get_guint32_endian(tvb, offset + 16, int_rep);
offset += 20;
bPayload = TRUE;
}
else
{
offset += 12;
}
structId = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
}
}
else if ((opcode >= 0xA0 && opcode <= 0xB9) && tvb_length_remaining(tvb, offset) >= 16)
{
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 16, "%s (%s)", MQ_TEXT_XA,
val_to_str(opcode, mq_opcode_vals, "Unknown (0x%02x)"));
mq_tree = proto_item_add_subtree(ti, ett_mq_xa);
proto_tree_add_item(mq_tree, hf_mq_xa_length, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_xa_returnvalue, tvb, offset + 4, 4, int_rep);
{
proto_tree *mq_tree_sub = NULL;
guint32 iTMFlags;
ti = proto_tree_add_item(mq_tree, hf_mq_xa_tmflags, tvb, offset + 8, 4, int_rep);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_xa_tmflags);
iTMFlags = tvb_get_guint32_endian(tvb, offset + 8, int_rep);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_onephase, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_fail, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_resume, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_success, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_suspend, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_startrscan, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_endrscan, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_join, tvb, offset + 8, 4, iTMFlags);
}
proto_tree_add_item(mq_tree, hf_mq_xa_rmid, tvb, offset + 12, 4, int_rep);
}
offset += 16;
if (opcode == MQ_TST_XA_START || opcode == MQ_TST_XA_END || opcode == MQ_TST_XA_PREPARE
|| opcode == MQ_TST_XA_COMMIT || opcode == MQ_TST_XA_ROLLBACK || opcode == MQ_TST_XA_FORGET
|| opcode == MQ_TST_XA_COMPLETE)
{
gint iSizeXid = 0;
if ((iSizeXid = dissect_mq_xid(tvb, mqroot_tree, int_rep, offset)) != 0)
offset += iSizeXid;
}
else if ((opcode == MQ_TST_XA_OPEN || opcode == MQ_TST_XA_CLOSE)
&& tvb_length_remaining(tvb, offset) >= 1)
{
guint8 iXAInfoLength = 0;
iXAInfoLength = tvb_get_guint8(tvb, offset);
if (tvb_length_remaining(tvb, offset) >= iXAInfoLength + 1)
{
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iXAInfoLength + 1, MQ_TEXT_XINF);
mq_tree = proto_item_add_subtree(ti, ett_mq_xa_info);
proto_tree_add_item(mq_tree, hf_mq_xa_xainfo_length, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_xa_xainfo_value, tvb, offset + 1, iXAInfoLength, string_rep);
}
}
offset += 1 + iXAInfoLength;
}
else if ((opcode == MQ_TST_XA_RECOVER || opcode == MQ_TST_XA_RECOVER_REPLY)
&& tvb_length_remaining(tvb, offset) >= 4)
{
gint iNbXid = 0;
iNbXid = tvb_get_guint32_endian(tvb, offset, int_rep);
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_xa_count, tvb, offset, 4, int_rep);
}
offset += 4;
if (opcode == MQ_TST_XA_RECOVER_REPLY)
{
gint iXid = 0;
for (iXid = 0; iXid < iNbXid; iXid++)
{
gint iSizeXid = 0;
if ((iSizeXid = dissect_mq_xid(tvb, mqroot_tree, int_rep, offset)) != 0)
offset += iSizeXid;
else
break;
}
}
}
}
else if ((structId == MQ_STRUCTID_ID || structId == MQ_STRUCTID_ID_EBCDIC) && tvb_length_remaining(tvb, offset) >= 5)
{
guint8 iVersionID = 0;
gint iSizeID = 0;
iVersionID = tvb_get_guint8(tvb, offset + 4);
iSizeID = (iVersionID < 4 ? 44 : 104);
if (iSizeID != 0 && tvb_length_remaining(tvb, offset) >= iSizeID)
{
if (check_col(pinfo->cinfo, COL_INFO))
{
guint8* sChannel;
sChannel = tvb_get_ephemeral_string_enc(tvb, offset + 24, 20, string_rep);
if (strip_trailing_blanks(sChannel, 20) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ": CHL=%s", sChannel);
}
}
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeID, MQ_TEXT_ID);
mq_tree = proto_item_add_subtree(ti, ett_mq_id);
proto_tree_add_item(mq_tree, hf_mq_id_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_id_level, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
{
proto_tree *mq_tree_sub = NULL;
guint8 iIDFlags;
ti = proto_tree_add_item(mq_tree, hf_mq_id_flags, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_id_icf);
iIDFlags = tvb_get_guint8(tvb, offset + 5);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_icf_runtime, tvb, offset + 5, 1, iIDFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_icf_svrsec, tvb, offset + 5, 1, iIDFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_icf_mqreq, tvb, offset + 5, 1, iIDFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_icf_splitmsg, tvb, offset + 5, 1, iIDFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_icf_convcap, tvb, offset + 5, 1, iIDFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_icf_msgseq, tvb, offset + 5, 1, iIDFlags);
}
proto_tree_add_item(mq_tree, hf_mq_id_unknown2, tvb, offset + 6, 1, ENC_BIG_ENDIAN);
{
proto_tree *mq_tree_sub = NULL;
guint8 iErrorFlags;
ti = proto_tree_add_item(mq_tree, hf_mq_id_ieflags, tvb, offset + 7, 1, ENC_BIG_ENDIAN);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_id_ief);
iErrorFlags = tvb_get_guint8(tvb, offset + 7);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_ief_hbint, tvb, offset + 7, 1, iErrorFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_ief_seqwrap, tvb, offset + 7, 1, iErrorFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_ief_mxmsgpb, tvb, offset + 7, 1, iErrorFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_ief_mxmsgsz, tvb, offset + 7, 1, iErrorFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_ief_fap, tvb, offset + 7, 1, iErrorFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_ief_mxtrsz, tvb, offset + 7, 1, iErrorFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_ief_enc, tvb, offset + 7, 1, iErrorFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_id_ief_ccsid, tvb, offset + 7, 1, iErrorFlags);
}
proto_tree_add_item(mq_tree, hf_mq_id_unknown4, tvb, offset + 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_id_maxmsgperbatch, tvb, offset + 10, 2, int_rep);
proto_tree_add_item(mq_tree, hf_mq_id_maxtransmissionsize, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_id_maxmsgsize, tvb, offset + 16, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_id_sequencewrapvalue, tvb, offset + 20, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_id_channel, tvb, offset + 24, 20, string_rep);
}
if (iVersionID >= 4)
{
if (check_col(pinfo->cinfo, COL_INFO))
{
guint8* sQueueManager;
sQueueManager = tvb_get_ephemeral_string_enc(tvb, offset + 48, 48, string_rep);
if (strip_trailing_blanks(sQueueManager,48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " QM=%s", sQueueManager);
}
}
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_id_capflags, tvb, offset + 44, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_id_unknown5, tvb, offset + 45, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_id_ccsid, tvb, offset + 46, 2, int_rep);
proto_tree_add_item(mq_tree, hf_mq_id_queuemanager, tvb, offset + 48, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_id_heartbeatinterval, tvb, offset + 96, 4, int_rep);
}
}
offset += iSizeID;
}
}
else if ((structId == MQ_STRUCTID_UID || structId == MQ_STRUCTID_UID_EBCDIC) && tvb_length_remaining(tvb, offset) > 0)
{
gint iSizeUID = 0;
iSizeUID = iSegmentLength - iSizeTSH;
if (iSizeUID != 28 && iSizeUID != 132) iSizeUID = 0;
if (iSizeUID != 0 && tvb_length_remaining(tvb, offset) >= iSizeUID)
{
if (check_col(pinfo->cinfo, COL_INFO))
{
guint8* sUserId;
sUserId = tvb_get_ephemeral_string_enc(tvb, offset + 4, 12, string_rep);
if (strip_trailing_blanks(sUserId, 12) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ": User=%s", sUserId);
}
}
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeUID, MQ_TEXT_UID);
mq_tree = proto_item_add_subtree(ti, ett_mq_uid);
proto_tree_add_item(mq_tree, hf_mq_uid_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_uid_userid, tvb, offset + 4, 12, string_rep);
proto_tree_add_item(mq_tree, hf_mq_uid_password, tvb, offset + 16, 12, string_rep);
}
if (iSizeUID == 132)
{
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_uid_longuserid, tvb, offset + 28, 64, string_rep);
proto_tree_add_item(mq_tree, hf_mq_uid_securityid, tvb, offset + 92, 40, ENC_NA);
}
}
offset += iSizeUID;
}
}
if ((structId == MQ_STRUCTID_OD || structId == MQ_STRUCTID_OD_EBCDIC) && tvb_length_remaining(tvb, offset) >= 8)
{
gint iSizeOD = 0;
guint32 iVersionOD = 0;
iVersionOD = tvb_get_guint32_endian(tvb, offset + 4, int_rep);
switch (iVersionOD)
{
case 1: iSizeOD = 168; break;
case 2: iSizeOD = 200; break;
case 3: iSizeOD = 336; break;
}
if (iSizeOD != 0 && tvb_length_remaining(tvb, offset) >= iSizeOD)
{
gint iNbrRecords = 0;
if (iVersionOD >= 2)
iNbrRecords = tvb_get_guint32_endian(tvb, offset + 168, int_rep);
if (check_col(pinfo->cinfo, COL_INFO))
{
guint8* sQueue;
sQueue = tvb_get_ephemeral_string_enc(tvb, offset + 12, 48, string_rep);
if (strip_trailing_blanks(sQueue,48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Obj=%s", sQueue);
}
}
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeOD, MQ_TEXT_OD);
mq_tree = proto_item_add_subtree(ti, ett_mq_od);
proto_tree_add_item(mq_tree, hf_mq_od_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_od_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_od_objecttype, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_od_objectname, tvb, offset + 12, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_od_objectqmgrname, tvb, offset + 60, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_od_dynamicqname, tvb, offset + 108, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_od_alternateuserid, tvb, offset + 156, 12, string_rep);
if (iVersionOD >= 2)
{
proto_tree_add_item(mq_tree, hf_mq_od_recspresent, tvb, offset + 168, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_od_knowndestcount, tvb, offset + 172, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_od_unknowndestcount, tvb, offset + 176, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_od_invaliddestcount, tvb, offset + 180, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_od_objectrecoffset, tvb, offset + 184, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_od_responserecoffset, tvb, offset + 188, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_od_objectrecptr, tvb, offset + 192, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_od_responserecptr, tvb, offset + 196, 4, int_rep);
}
if (iVersionOD >= 3)
{
proto_tree_add_item(mq_tree, hf_mq_od_alternatesecurityid, tvb, offset + 200, 40, string_rep);
proto_tree_add_item(mq_tree, hf_mq_od_resolvedqname, tvb, offset + 240, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_od_resolvedqmgrname, tvb, offset + 288, 48, string_rep);
}
}
offset += iSizeOD;
if (iNbrRecords > 0)
{
gint iOffsetOR = 0;
gint iOffsetRR = 0;
gint iSizeORRR = 0;
iDistributionListSize = iNbrRecords;
iOffsetOR = tvb_get_guint32_endian(tvb, offset - iSizeOD + 184, int_rep);
iOffsetRR = tvb_get_guint32_endian(tvb, offset - iSizeOD + 188, int_rep);
if ((iSizeORRR = dissect_mq_or(tvb, mqroot_tree, string_rep, offset, iNbrRecords, iOffsetOR)) != 0)
offset += iSizeORRR;
if ((iSizeORRR = dissect_mq_rr(tvb, mqroot_tree, int_rep, offset, iNbrRecords, iOffsetRR)) != 0)
offset += iSizeORRR;
}
}
}
if ((opcode == MQ_TST_MQOPEN || opcode == MQ_TST_MQCLOSE
|| opcode == MQ_TST_MQOPEN_REPLY || opcode == MQ_TST_MQCLOSE_REPLY)
&& tvb_length_remaining(tvb, offset) >= 4)
{
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 4, MQ_TEXT_OPEN);
mq_tree = proto_item_add_subtree(ti, ett_mq_open);
proto_tree_add_item(mq_tree, hf_mq_open_options, tvb, offset, 4, int_rep);
}
offset += 4;
}
if ((iSizeMD_gbl = dissect_mq_md(tvb, mqroot_tree, int_rep, string_rep, offset, &tMsgProps)) != 0)
{
gint iSizeGMO = 0;
gint iSizePMO = 0;
offset += iSizeMD_gbl;
if ((iSizeGMO = dissect_mq_gmo(tvb, pinfo, mqroot_tree, int_rep, string_rep, offset)) != 0)
{
offset += iSizeGMO;
bPayload = TRUE;
}
else if ((iSizePMO = dissect_mq_pmo(tvb, pinfo, mqroot_tree, int_rep, string_rep, offset, &iDistributionListSize)) != 0)
{
offset += iSizePMO;
bPayload = TRUE;
}
if (tvb_length_remaining(tvb, offset) >= 4)
{
if (bPayload == TRUE)
{
iSizePayload = tvb_get_guint32_endian(tvb, offset, int_rep);
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 4, MQ_TEXT_PUT);
mq_tree = proto_item_add_subtree(ti, ett_mq_put);
proto_tree_add_item(mq_tree, hf_mq_put_length, tvb, offset, 4, int_rep);
}
offset += 4;
}
}
}
if (iDistributionListSize > 0)
{
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " (Distribution List, Size=%d)", iDistributionListSize);
}
if (bPayload == TRUE)
{
if (iSizePayload != 0 && tvb_length_remaining(tvb, offset) > 0)
{
guint32 iHeadersLength = 0;
if (tvb_length_remaining(tvb, offset) >= 4)
{
gint iSizeMD = 0;
structId = tvb_get_ntohl(tvb, offset);
if ((structId == MQ_STRUCTID_XQH || structId == MQ_STRUCTID_XQH_EBCDIC) && tvb_length_remaining(tvb, offset) >= 104)
{
gint iSizeXQH = 104;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeXQH, MQ_TEXT_XQH);
mq_tree = proto_item_add_subtree(ti, ett_mq_xqh);
proto_tree_add_item(mq_tree, hf_mq_xqh_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_xqh_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_xqh_remoteq, tvb, offset + 8, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_xqh_remoteqmgr, tvb, offset + 56, 48, string_rep);
}
offset += iSizeXQH;
iHeadersLength += iSizeXQH;
if ((iSizeMD = dissect_mq_md(tvb, mqroot_tree, int_rep, string_rep, offset, &tMsgProps)) != 0)
{
offset += iSizeMD;
iHeadersLength += iSizeMD;
}
structId = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((structId == MQ_STRUCTID_DH || structId == MQ_STRUCTID_DH_EBCDIC) && tvb_length_remaining(tvb, offset) >= 48)
{
gint iSizeDH = 48;
gint iNbrRecords = 0;
guint32 iRecFlags = 0;
iNbrRecords = tvb_get_guint32_endian(tvb, offset + 36, int_rep);
iRecFlags = tvb_get_guint32_endian(tvb, offset + 32, int_rep);
tMsgProps.iOffsetEncoding = offset + 12;
tMsgProps.iOffsetCcsid = offset + 16;
tMsgProps.iOffsetFormat = offset + 20;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeDH, MQ_TEXT_DH);
mq_tree = proto_item_add_subtree(ti, ett_mq_dh);
proto_tree_add_item(mq_tree, hf_mq_head_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_head_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_length, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_encoding, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_ccsid, tvb, offset + 16, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_format, tvb, offset + 20, 8, string_rep);
proto_tree_add_item(mq_tree, hf_mq_head_flags, tvb, offset + 28, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_dh_putmsgrecfields, tvb, offset + 32, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_dh_recspresent, tvb, offset + 36, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_dh_objectrecoffset , tvb, offset + 40, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_dh_putmsgrecoffset, tvb, offset + 44, 4, int_rep);
}
offset += iSizeDH;
iHeadersLength += iSizeDH;
if (iNbrRecords > 0)
{
gint iOffsetOR = 0;
gint iOffsetPMR = 0;
gint iSizeORPMR = 0;
iOffsetOR = tvb_get_guint32_endian(tvb, offset - iSizeDH + 40, int_rep);
iOffsetPMR = tvb_get_guint32_endian(tvb, offset - iSizeDH + 44, int_rep);
if ((iSizeORPMR = dissect_mq_or(tvb, mqroot_tree, string_rep, offset, iNbrRecords, iOffsetOR)) != 0)
{
offset += iSizeORPMR;
iHeadersLength += iSizeORPMR;
}
if ((iSizeORPMR = dissect_mq_pmr(tvb, mqroot_tree, int_rep, offset, iNbrRecords, iOffsetPMR, iRecFlags)) != 0)
{
offset += iSizeORPMR;
iHeadersLength += iSizeORPMR;
}
}
structId = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((structId == MQ_STRUCTID_DLH || structId == MQ_STRUCTID_DLH_EBCDIC) && tvb_length_remaining(tvb, offset) >= 172)
{
gint iSizeDLH = 172;
tMsgProps.iOffsetEncoding = offset + 108;
tMsgProps.iOffsetCcsid = offset + 112;
tMsgProps.iOffsetFormat = offset + 116;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeDLH, MQ_TEXT_DLH);
mq_tree = proto_item_add_subtree(ti, ett_mq_dlh);
proto_tree_add_item(mq_tree, hf_mq_dlh_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_reason, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_destq, tvb, offset + 12, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_destqmgr, tvb, offset + 60, 48, string_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_encoding, tvb, offset + 108, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_ccsid, tvb, offset + 112, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_format, tvb, offset + 116, 8, string_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_putappltype, tvb, offset + 124, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_putapplname, tvb, offset + 128, 28, string_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_putdate, tvb, offset + 156, 8, string_rep);
proto_tree_add_item(mq_tree, hf_mq_dlh_puttime, tvb, offset + 164, 8, string_rep);
}
offset += iSizeDLH;
iHeadersLength += iSizeDLH;
structId = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((structId == MQ_STRUCTID_MDE || structId == MQ_STRUCTID_MDE_EBCDIC) && tvb_length_remaining(tvb, offset) >= 72)
{
gint iSizeMDE = 72;
tMsgProps.iOffsetEncoding = offset + 12;
tMsgProps.iOffsetCcsid = offset + 16;
tMsgProps.iOffsetFormat = offset + 20;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeMDE, MQ_TEXT_MDE);
mq_tree = proto_item_add_subtree(ti, ett_mq_mde);
proto_tree_add_item(mq_tree, hf_mq_head_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_head_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_length, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_encoding, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_ccsid, tvb, offset + 16, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_format, tvb, offset + 20, 8, string_rep);
proto_tree_add_item(mq_tree, hf_mq_head_flags, tvb, offset + 28, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_groupid, tvb, offset + 32, 24, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_msgseqnumber, tvb, offset + 56, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_offset, tvb, offset + 60, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_msgflags, tvb, offset + 64, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_md_originallength, tvb, offset + 68, 4, int_rep);
}
offset += iSizeMDE;
iHeadersLength += iSizeMDE;
structId = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((structId == MQ_STRUCTID_CIH || structId == MQ_STRUCTID_CIH_EBCDIC
|| structId == MQ_STRUCTID_IIH || structId == MQ_STRUCTID_IIH_EBCDIC
|| structId == MQ_STRUCTID_RFH || structId == MQ_STRUCTID_RFH_EBCDIC
|| structId == MQ_STRUCTID_RMH || structId == MQ_STRUCTID_RMH_EBCDIC
|| structId == MQ_STRUCTID_WIH || structId == MQ_STRUCTID_WIH_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 12)
{
gint iSizeHeader = 0;
iSizeHeader = (gint) tvb_get_guint32_endian(tvb, offset + 8, int_rep);
if (iSizeHeader <= 32)
THROW(ReportedBoundsError);
if (tvb_length_remaining(tvb, offset) >= iSizeHeader)
{
tMsgProps.iOffsetEncoding = offset + 12;
tMsgProps.iOffsetCcsid = offset + 16;
tMsgProps.iOffsetFormat = offset + 20;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeHeader, "%s", val_to_str(structId, mq_structid_vals, "Unknown (0x%08x)"));
mq_tree = proto_item_add_subtree(ti, ett_mq_head);
proto_tree_add_item(mq_tree, hf_mq_head_structid, tvb, offset, 4, string_rep);
proto_tree_add_item(mq_tree, hf_mq_head_version, tvb, offset + 4, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_length, tvb, offset + 8, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_encoding, tvb, offset + 12, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_ccsid, tvb, offset + 16, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_format, tvb, offset + 20, 8, string_rep);
proto_tree_add_item(mq_tree, hf_mq_head_flags, tvb, offset + 28, 4, int_rep);
proto_tree_add_item(mq_tree, hf_mq_head_struct, tvb, offset + 32, iSizeHeader - 32, ENC_NA);
}
offset += iSizeHeader;
iHeadersLength += iSizeHeader;
}
}
}
if (tMsgProps.iOffsetFormat != 0)
{
guint8* sFormat = NULL;
sFormat = tvb_get_ephemeral_string_enc(tvb, tMsgProps.iOffsetFormat, 8, string_rep);
if (strip_trailing_blanks(sFormat, 8) == 0)
sFormat = (guint8*)ep_strdup("MQNONE");
col_append_fstr(pinfo->cinfo, COL_INFO, " Fmt=%s", sFormat);
if (tree)
{
proto_item *hidden_item;
hidden_item = proto_tree_add_string(tree, hf_mq_md_hidden_lastformat, tvb, tMsgProps.iOffsetFormat, 8, (const char*)sFormat);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
if (check_col(pinfo->cinfo, COL_INFO))
{
col_append_fstr(pinfo->cinfo, COL_INFO, " (%d bytes)", iSizePayload - iHeadersLength);
}
{
tvbuff_t* next_tvb = NULL;
void* pd_save;
struct mqinfo mqinfo;
mqinfo.encoding = tvb_get_guint32_endian(tvb, tMsgProps.iOffsetEncoding, int_rep);
mqinfo.ccsid = tvb_get_guint32_endian(tvb, tMsgProps.iOffsetCcsid, int_rep);
tvb_memcpy(tvb, mqinfo.format, tMsgProps.iOffsetFormat, 8);
pd_save = pinfo->private_data;
pinfo->private_data = &mqinfo;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_heuristic(mq_heur_subdissector_list, next_tvb, pinfo, tree, NULL))
call_dissector(data_handle, next_tvb, pinfo, tree);
pinfo->private_data = pd_save;
}
}
offset = tvb_length(tvb);
}
if (tvb_length_remaining(tvb, offset) >= 4)
{
structId = tvb_get_ntohl(tvb, offset);
if (tree)
{
proto_tree_add_text(mqroot_tree, tvb, offset, -1, "%s", val_to_str(structId, mq_structid_vals, "Unknown (0x%08x)"));
}
}
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, " [Unreassembled MQ]");
call_dissector(data_handle, tvb_new_subset_remaining(tvb, offset), pinfo, tree);
}
}
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, " [Undesegmented]");
if (tree)
{
proto_tree_add_item(tree, proto_mq, tvb, offset, -1, ENC_NA);
}
call_dissector(data_handle, tvb_new_subset_remaining(tvb, offset), pinfo, tree);
}
}
}
static void
reassemble_mq(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tvb_length(tvb) >= 28)
{
guint32 structId;
structId = tvb_get_ntohl(tvb, 0);
if (structId == MQ_STRUCTID_TSH || structId == MQ_STRUCTID_TSH_EBCDIC
|| structId == MQ_STRUCTID_TSHC || structId == MQ_STRUCTID_TSHC_EBCDIC
|| structId == MQ_STRUCTID_TSHM || structId == MQ_STRUCTID_TSHM_EBCDIC)
{
guint8 iControlFlags = 0;
guint32 iSegmentLength = 0;
guint32 iBeginLength = 0;
guint8 opcode;
gboolean bFirstSegment;
gboolean bLastSegment;
opcode = tvb_get_guint8(tvb, 9);
iControlFlags = tvb_get_guint8(tvb, 10);
iSegmentLength = tvb_get_ntohl(tvb, 4);
bFirstSegment = ((iControlFlags & MQ_TCF_FIRST) != 0);
bLastSegment = ((iControlFlags & MQ_TCF_LAST) != 0);
if (opcode > 0x80 && !(bFirstSegment && bLastSegment))
{
if (mq_reassembly)
{
tvbuff_t* next_tvb;
fragment_data* fd_head;
guint32 iConnectionId = (pinfo->srcport + pinfo->destport);
if (opcode > 0x80 && !bFirstSegment) iBeginLength = 28;
fd_head = fragment_add_seq_next(&mq_reassembly_table,
tvb, iBeginLength,
pinfo, iConnectionId, NULL,
iSegmentLength - iBeginLength, !bLastSegment);
if (fd_head != NULL && pinfo->fd->num == fd_head->reassembled_in)
{
if (fd_head->next != NULL)
{
next_tvb = tvb_new_child_real_data(tvb, fd_head->data, fd_head->len, fd_head->len);
add_new_data_source(pinfo, next_tvb, "Reassembled MQ");
}
else
{
next_tvb = tvb;
}
dissect_mq_pdu(next_tvb, pinfo, tree);
return;
}
else
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MQ");
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "%s [Reassembled MQ]", val_to_str(opcode, mq_opcode_vals, "Unknown (0x%02x)"));
if (tree)
{
proto_item* ti = NULL;
ti = proto_tree_add_item(tree, proto_mq, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, " (%s) [Reassembled MQ]", val_to_str(opcode, mq_opcode_vals, "Unknown (0x%02x)"));
}
return;
}
}
else
{
dissect_mq_pdu(tvb, pinfo, tree);
if (bFirstSegment)
{
col_append_str(pinfo->cinfo, COL_INFO, " [Unreassembled MQ]");
}
return;
}
}
dissect_mq_pdu(tvb, pinfo, tree);
return;
}
}
}
static guint
get_mq_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
if (tvb_length_remaining(tvb, offset) >= 8)
{
if (tvb_get_ntohl(tvb, 0) == MQ_STRUCTID_TSH || tvb_get_ntohl(tvb, 0) == MQ_STRUCTID_TSH_EBCDIC
|| tvb_get_ntohl(tvb, 0) == MQ_STRUCTID_TSHC || tvb_get_ntohl(tvb, 0) == MQ_STRUCTID_TSHC_EBCDIC
|| tvb_get_ntohl(tvb, 0) == MQ_STRUCTID_TSHM || tvb_get_ntohl(tvb, 0) == MQ_STRUCTID_TSHM_EBCDIC)
return tvb_get_ntohl(tvb, offset + 4);
}
return 0;
}
static void
dissect_mq_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, mq_desegment, 28, get_mq_pdu_len, reassemble_mq);
}
static void
dissect_mq_spx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_mq_pdu(tvb, pinfo, tree);
}
static gboolean
dissect_mq_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint iProto, void *data _U_)
{
if (tvb_length(tvb) >= 28)
{
guint32 structId;
guint8 cEndian;
guint8 cEndian2;
structId = tvb_get_ntohl(tvb, 0);
cEndian = tvb_get_guint8(tvb, 8);
cEndian2 = tvb_get_guint8(tvb, 16);
if (((structId == MQ_STRUCTID_TSH || structId == MQ_STRUCTID_TSH_EBCDIC
|| structId == MQ_STRUCTID_TSHC || structId == MQ_STRUCTID_TSHC_EBCDIC)
&& (cEndian == MQ_LITTLE_ENDIAN || cEndian == MQ_BIG_ENDIAN))
|| ((structId == MQ_STRUCTID_TSHM || structId == MQ_STRUCTID_TSHM_EBCDIC)
&& (cEndian2 == MQ_LITTLE_ENDIAN || cEndian2 == MQ_BIG_ENDIAN)))
{
conversation_t *conversation;
conversation = find_or_create_conversation(pinfo);
if (iProto == MQ_XPT_TCP) conversation_set_dissector(conversation, mq_tcp_handle);
reassemble_mq(tvb, pinfo, tree);
return TRUE;
}
}
return FALSE;
}
static gboolean
dissect_mq_heur_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_mq_heur(tvb, pinfo, tree, MQ_XPT_TCP, NULL);
}
static gboolean
dissect_mq_heur_netbios(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_mq_heur(tvb, pinfo, tree, MQ_XPT_NETBIOS, NULL);
}
static gboolean
dissect_mq_heur_http(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_mq_heur(tvb, pinfo, tree, MQ_XPT_HTTP, NULL);
}
static void
mq_init(void)
{
reassembly_table_init(&mq_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_mq(void)
{
static hf_register_info hf[] = {
{ &hf_mq_tsh_structid,
{ "TSH structid", "mq.tsh.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_tsh_packetlength,
{ "MQ Segment length", "mq.tsh.seglength", FT_UINT32, BASE_DEC, NULL, 0x0, "TSH MQ Segment length", HFILL }},
{ &hf_mq_tsh_convid,
{ "Conversation ID", "mq.tsh.convid", FT_UINT32, BASE_DEC, NULL, 0x0, "TSH Conversation ID", HFILL }},
{ &hf_mq_tsh_requestid,
{ "Request ID", "mq.tsh.requestid", FT_UINT32, BASE_DEC, NULL, 0x0, "TSH Request ID", HFILL }},
{ &hf_mq_tsh_byteorder,
{ "Byte order", "mq.tsh.byteorder", FT_UINT8, BASE_HEX, VALS(mq_byteorder_vals), 0x0, "TSH Byte order", HFILL }},
{ &hf_mq_tsh_opcode,
{ "Segment type", "mq.tsh.type", FT_UINT8, BASE_HEX, VALS(mq_opcode_vals), 0x0, "TSH MQ segment type", HFILL }},
{ &hf_mq_tsh_controlflags,
{ "Control flags", "mq.tsh.cflags", FT_UINT8, BASE_HEX, NULL, 0x0, "TSH Control flags", HFILL }},
{ &hf_mq_tsh_reserved,
{ "Reserved", "mq.tsh.reserved", FT_UINT8, BASE_HEX, NULL, 0x0, "TSH Reserved", HFILL }},
{ &hf_mq_tsh_luwid,
{ "Logical unit of work identifier", "mq.tsh.luwid", FT_BYTES, BASE_NONE, NULL, 0x0, "TSH logical unit of work identifier", HFILL }},
{ &hf_mq_tsh_encoding,
{ "Encoding", "mq.tsh.encoding", FT_UINT32, BASE_DEC, NULL, 0x0, "TSH Encoding", HFILL }},
{ &hf_mq_tsh_ccsid,
{ "Character set", "mq.tsh.ccsid", FT_UINT16, BASE_DEC, NULL, 0x0, "TSH CCSID", HFILL }},
{ &hf_mq_tsh_padding,
{ "Padding", "mq.tsh.padding", FT_UINT16, BASE_HEX, NULL, 0x0, "TSH Padding", HFILL }},
{ &hf_mq_tsh_tcf_confirmreq,
{ "Confirm request", "mq.tsh.tcf.confirmreq", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_CONFIRM_REQUEST, "TSH TCF Confirm request", HFILL }},
{ &hf_mq_tsh_tcf_error,
{ "Error", "mq.tsh.tcf.error", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_ERROR, "TSH TCF Error", HFILL }},
{ &hf_mq_tsh_tcf_reqclose,
{ "Request close", "mq.tsh.tcf.reqclose", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_REQUEST_CLOSE, "TSH TCF Request close", HFILL }},
{ &hf_mq_tsh_tcf_closechann,
{ "Close channel", "mq.tsh.tcf.closechann", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_CLOSE_CHANNEL, "TSH TCF Close channel", HFILL }},
{ &hf_mq_tsh_tcf_first,
{ "First", "mq.tsh.tcf.first", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_FIRST, "TSH TCF First", HFILL }},
{ &hf_mq_tsh_tcf_last,
{ "Last", "mq.tsh.tcf.last", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_LAST, "TSH TCF Last", HFILL }},
{ &hf_mq_tsh_tcf_reqacc,
{ "Request accepted", "mq.tsh.tcf.reqacc", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_REQUEST_ACCEPTED, "TSH TCF Request accepted", HFILL }},
{ &hf_mq_tsh_tcf_dlq,
{ "DLQ used", "mq.tsh.tcf.dlq", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_DLQ_USED, "TSH TCF DLQ used", HFILL }},
{ &hf_mq_api_replylength,
{ "Reply length", "mq.api.replylength", FT_UINT32, BASE_DEC, NULL, 0x0, "API Reply length", HFILL }},
{ &hf_mq_api_completioncode,
{ "Completion code", "mq.api.completioncode", FT_UINT32, BASE_DEC, NULL, 0x0, "API Completion code", HFILL }},
{ &hf_mq_api_reasoncode,
{ "Reason code", "mq.api.reasoncode", FT_UINT32, BASE_DEC, NULL, 0x0, "API Reason code", HFILL }},
{ &hf_mq_api_objecthandle,
{ "Object handle", "mq.api.hobj", FT_UINT32, BASE_HEX, NULL, 0x0, "API Object handle", HFILL }},
{ &hf_mq_id_icf_msgseq,
{ "Message sequence", "mq.id.icf.msgseq", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_MSG_SEQ, "ID ICF Message sequence", HFILL }},
{ &hf_mq_id_icf_convcap,
{ "Conversion capable", "mq.id.icf.convcap", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_CONVERSION_CAPABLE, "ID ICF Conversion capable", HFILL }},
{ &hf_mq_id_icf_splitmsg,
{ "Split messages", "mq.id.icf.splitmsg", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_SPLIT_MESSAGE, "ID ICF Split message", HFILL }},
{ &hf_mq_id_icf_mqreq,
{ "MQ request", "mq.id.icf.mqreq", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_MQREQUEST, "ID ICF MQ request", HFILL }},
{ &hf_mq_id_icf_svrsec,
{ "Server connection security", "mq.id.icf.svrsec", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_SVRCONN_SECURITY, "ID ICF Server connection security", HFILL }},
{ &hf_mq_id_icf_runtime,
{ "Runtime application", "mq.id.icf.runtime", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_RUNTIME, "ID ICF Runtime application", HFILL }},
{ &hf_mq_msh_structid,
{ "MSH structid", "mq.msh.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_msh_seqnum,
{ "Sequence number", "mq.msh.seqnum", FT_UINT32, BASE_DEC, NULL, 0x0, "MSH sequence number", HFILL }},
{ &hf_mq_msh_datalength,
{ "Buffer length", "mq.msh.buflength", FT_UINT32, BASE_DEC, NULL, 0x0, "MSH buffer length", HFILL }},
{ &hf_mq_msh_unknown1,
{ "Unknown1", "mq.msh.unknown1", FT_UINT32, BASE_HEX, NULL, 0x0, "MSH unknown1", HFILL }},
{ &hf_mq_msh_msglength,
{ "Message length", "mq.msh.msglength", FT_UINT32, BASE_DEC, NULL, 0x0, "MSH message length", HFILL }},
{ &hf_mq_xqh_structid,
{ "XQH structid", "mq.xqh.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_xqh_version,
{ "Version", "mq.xqh.version", FT_UINT32, BASE_DEC, NULL, 0x0, "XQH version", HFILL }},
{ &hf_mq_xqh_remoteq,
{ "Remote queue", "mq.xqh.remoteq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "XQH remote queue", HFILL }},
{ &hf_mq_xqh_remoteqmgr,
{ "Remote queue manager", "mq.xqh.remoteqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "XQH remote queue manager", HFILL }},
{ &hf_mq_id_structid,
{ "ID structid", "mq.id.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_id_level,
{ "FAP level", "mq.id.level", FT_UINT8, BASE_DEC, NULL, 0x0, "ID Formats And Protocols level", HFILL }},
{ &hf_mq_id_flags,
{ "Flags", "mq.id.flags", FT_UINT8, BASE_HEX, NULL, 0x0, "ID flags", HFILL }},
{ &hf_mq_id_unknown2,
{ "Unknown2", "mq.id.unknown2", FT_UINT8, BASE_HEX, NULL, 0x0, "ID unknown2", HFILL }},
{ &hf_mq_id_ieflags,
{ "Initial error flags", "mq.id.ief", FT_UINT8, BASE_HEX, NULL, 0x0, "ID initial error flags", HFILL }},
{ &hf_mq_id_unknown4,
{ "Unknown4", "mq.id.unknown4", FT_UINT16, BASE_HEX, NULL, 0x0, "ID unknown4", HFILL }},
{ &hf_mq_id_maxmsgperbatch,
{ "Maximum messages per batch", "mq.id.maxmsgperbatch", FT_UINT16, BASE_DEC, NULL, 0x0, "ID max msg per batch", HFILL }},
{ &hf_mq_id_maxtransmissionsize,
{ "Maximum transmission size", "mq.id.maxtranssize", FT_UINT32, BASE_DEC, NULL, 0x0, "ID max trans size", HFILL }},
{ &hf_mq_id_maxmsgsize,
{ "Maximum message size", "mq.id.maxmsgsize", FT_UINT32, BASE_DEC, NULL, 0x0, "ID max msg size", HFILL }},
{ &hf_mq_id_sequencewrapvalue,
{ "Sequence wrap value", "mq.id.seqwrap", FT_UINT32, BASE_DEC, NULL, 0x0, "ID seq wrap value", HFILL }},
{ &hf_mq_id_channel,
{ "Channel name", "mq.id.channelname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "ID channel name", HFILL }},
{ &hf_mq_id_capflags,
{ "Capability flags", "mq.id.capflags", FT_UINT8, BASE_HEX, NULL, 0x0, "ID Capability flags", HFILL }},
{ &hf_mq_id_unknown5,
{ "Unknown5", "mq.id.unknown5", FT_UINT8, BASE_HEX, NULL, 0x0, "ID unknown5", HFILL }},
{ &hf_mq_id_ccsid,
{ "Character set", "mq.id.ccsid", FT_UINT16, BASE_DEC, NULL, 0x0, "ID character set", HFILL }},
{ &hf_mq_id_queuemanager,
{ "Queue manager", "mq.id.qm", FT_STRINGZ, BASE_NONE, NULL, 0x0, "ID Queue manager", HFILL }},
{ &hf_mq_id_heartbeatinterval,
{ "Heartbeat interval", "mq.id.hbint", FT_UINT32, BASE_DEC, NULL, 0x0, "ID Heartbeat interval", HFILL }},
#if 0
{ &hf_mq_id_unknown6,
{ "Unknown6", "mq.id.unknown6", FT_UINT16, BASE_HEX, NULL, 0x0, "ID unknown6", HFILL }},
#endif
{ &hf_mq_id_ief_ccsid,
{ "Invalid CCSID", "mq.id.ief.ccsid", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_CCSID, "ID invalid CCSID", HFILL }},
{ &hf_mq_id_ief_enc,
{ "Invalid encoding", "mq.id.ief.enc", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_ENCODING, "ID invalid encoding", HFILL }},
{ &hf_mq_id_ief_mxtrsz,
{ "Invalid maximum transmission size", "mq.id.ief.mxtrsz", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_MAX_TRANSMISSION_SIZE, "ID invalid maximum transmission size", HFILL }},
{ &hf_mq_id_ief_fap,
{ "Invalid FAP level", "mq.id.ief.fap", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_FAP_LEVEL, "ID invalid FAP level", HFILL }},
{ &hf_mq_id_ief_mxmsgsz,
{ "Invalid message size", "mq.id.ief.mxmsgsz", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_MAX_MSG_SIZE, "ID invalid message size", HFILL }},
{ &hf_mq_id_ief_mxmsgpb,
{ "Invalid maximum message per batch", "mq.id.ief.mxmsgpb", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_MAX_MSG_PER_BATCH, "ID maximum message per batch", HFILL }},
{ &hf_mq_id_ief_seqwrap,
{ "Invalid sequence wrap value", "mq.id.ief.seqwrap", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_SEQ_WRAP_VALUE, "ID invalid sequence wrap value", HFILL }},
{ &hf_mq_id_ief_hbint,
{ "Invalid heartbeat interval", "mq.id.ief.hbint", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_HEARTBEAT_INTERVAL, "ID invalid heartbeat interval", HFILL }},
{ &hf_mq_uid_structid,
{ "UID structid", "mq.uid.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_uid_userid,
{ "User ID", "mq.uid.userid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "UID structid", HFILL }},
{ &hf_mq_uid_password,
{ "Password", "mq.uid.password", FT_STRINGZ, BASE_NONE, NULL, 0x0, "UID password", HFILL }},
{ &hf_mq_uid_longuserid,
{ "Long User ID", "mq.uid.longuserid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "UID long user id", HFILL }},
{ &hf_mq_uid_securityid,
{ "Security ID", "mq.uid.securityid", FT_BYTES, BASE_NONE, NULL, 0x0, "UID security id", HFILL }},
{ &hf_mq_conn_queuemanager,
{ "Queue manager", "mq.conn.qm", FT_STRINGZ, BASE_NONE, NULL, 0x0, "CONN queue manager", HFILL }},
{ &hf_mq_conn_appname,
{ "Application name", "mq.conn.appname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "CONN application name", HFILL }},
{ &hf_mq_conn_apptype,
{ "Application type", "mq.conn.apptype", FT_INT32, BASE_DEC, NULL, 0x0, "CONN application type", HFILL }},
{ &hf_mq_conn_acttoken,
{ "Accounting token", "mq.conn.acttoken", FT_BYTES, BASE_NONE, NULL, 0x0, "CONN accounting token", HFILL }},
{ &hf_mq_conn_version,
{ "Version", "mq.conn.version", FT_UINT32, BASE_DEC, VALS(mq_conn_version_vals), 0x0, "CONN version", HFILL }},
{ &hf_mq_conn_options,
{ "Options", "mq.conn.options", FT_UINT32, BASE_HEX, NULL, 0x0, "CONN options", HFILL }},
{ &hf_mq_inq_nbsel,
{ "Selector count", "mq.inq.nbsel", FT_UINT32, BASE_DEC, NULL, 0x0, "INQ Selector count", HFILL }},
{ &hf_mq_inq_nbint,
{ "Integer count", "mq.inq.nbint", FT_UINT32, BASE_DEC, NULL, 0x0, "INQ Integer count", HFILL }},
{ &hf_mq_inq_charlen,
{ "Character length", "mq.inq.charlen", FT_UINT32, BASE_DEC, NULL, 0x0, "INQ Character length", HFILL }},
{ &hf_mq_inq_sel,
{ "Selector", "mq.inq.sel", FT_UINT32, BASE_DEC, NULL, 0x0, "INQ Selector", HFILL }},
{ &hf_mq_inq_intvalue,
{ "Integer value", "mq.inq.intvalue", FT_UINT32, BASE_DEC, NULL, 0x0, "INQ Integer value", HFILL }},
{ &hf_mq_inq_charvalues,
{ "Char values", "mq.inq.charvalues", FT_STRINGZ, BASE_NONE, NULL, 0x0, "INQ Character values", HFILL }},
{ &hf_mq_spi_verb,
{ "SPI Verb", "mq.spi.verb", FT_UINT32, BASE_DEC, VALS(mq_spi_verbs_vals), 0x0, NULL, HFILL }},
{ &hf_mq_spi_version,
{ "Version", "mq.spi.version", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Version", HFILL }},
{ &hf_mq_spi_length,
{ "Max reply size", "mq.spi.replength", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Max reply size", HFILL }},
{ &hf_mq_spi_base_structid,
{ "SPI Structid", "mq.spib.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "SPI Base structid", HFILL }},
{ &hf_mq_spi_base_version,
{ "Version", "mq.spib.version", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Base Version", HFILL }},
{ &hf_mq_spi_base_length,
{ "Length", "mq.spib.length", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Base Length", HFILL }},
{ &hf_mq_spi_spqo_nbverb,
{ "Number of verbs", "mq.spqo.nbverb", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output Number of verbs", HFILL }},
{ &hf_mq_spi_spqo_verbid,
{ "Verb", "mq.spqo.verb", FT_UINT32, BASE_DEC, VALS(mq_spi_verbs_vals), 0x0, "SPI Query Output VerbId", HFILL }},
{ &hf_mq_spi_spqo_maxinoutversion,
{ "Max InOut Version", "mq.spqo.maxiov", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output Max InOut Version", HFILL }},
{ &hf_mq_spi_spqo_maxinversion,
{ "Max In Version", "mq.spqo.maxiv", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output Max In Version", HFILL }},
{ &hf_mq_spi_spqo_maxoutversion,
{ "Max Out Version", "mq.spqo.maxov", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output Max Out Version", HFILL }},
{ &hf_mq_spi_spqo_flags,
{ "Flags", "mq.spqo.flags", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output flags", HFILL }},
{ &hf_mq_spi_spai_mode,
{ "Mode", "mq.spai.mode", FT_UINT32, BASE_DEC, VALS(mq_spi_activate_vals), 0x0, "SPI Activate Input mode", HFILL }},
{ &hf_mq_spi_spai_unknown1,
{ "Unknown1", "mq.spai.unknown1", FT_STRINGZ, BASE_NONE, NULL, 0x0, "SPI Activate Input unknown1", HFILL }},
{ &hf_mq_spi_spai_unknown2,
{ "Unknown2", "mq.spai.unknown2", FT_STRINGZ, BASE_NONE, NULL, 0x0, "SPI Activate Input unknown2", HFILL }},
{ &hf_mq_spi_spai_msgid,
{ "Message Id", "mq.spai.msgid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "SPI Activate Input message id", HFILL }},
{ &hf_mq_spi_spgi_batchsize,
{ "Batch size", "mq.spgi.batchsize", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Input batch size", HFILL }},
{ &hf_mq_spi_spgi_batchint,
{ "Batch interval", "mq.spgi.batchint", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Input batch interval", HFILL }},
{ &hf_mq_spi_spgi_maxmsgsize,
{ "Max message size", "mq.spgi.maxmsgsize", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Input max message size", HFILL }},
{ &hf_mq_spi_spgo_options,
{ "Options", "mq.spgo.options", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Output options", HFILL }},
{ &hf_mq_spi_spgo_size,
{ "Size", "mq.spgo.size", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Output size", HFILL }},
{ &hf_mq_spi_options_blank,
{ "Blank padded", "mq.spi.options.blank", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_SPI_OPTIONS_BLANK_PADDED, "SPI Options blank padded", HFILL }},
{ &hf_mq_spi_options_syncpoint,
{ "Syncpoint", "mq.spi.options.sync", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_SPI_OPTIONS_SYNCPOINT, "SPI Options syncpoint", HFILL }},
{ &hf_mq_spi_options_deferred,
{ "Deferred", "mq.spi.options.deferred", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_SPI_OPTIONS_DEFERRED, "SPI Options deferred", HFILL }},
{ &hf_mq_put_length,
{ "Data length", "mq.put.length", FT_UINT32, BASE_DEC, NULL, 0x0, "PUT Data length", HFILL }},
{ &hf_mq_open_options,
{ "Options", "mq.open.options", FT_UINT32, BASE_DEC, NULL, 0x0, "OPEN options", HFILL }},
{ &hf_mq_ping_length,
{ "Length", "mq.ping.length", FT_UINT32, BASE_DEC, NULL, 0x0, "PING length", HFILL }},
{ &hf_mq_ping_buffer,
{ "Buffer", "mq.ping.buffer", FT_BYTES, BASE_NONE, NULL, 0x0, "PING buffer", HFILL }},
{ &hf_mq_reset_length,
{ "Length", "mq.reset.length", FT_UINT32, BASE_DEC, NULL, 0x0, "RESET length", HFILL }},
{ &hf_mq_reset_seqnum,
{ "Sequence number", "mq.reset.seqnum", FT_UINT32, BASE_DEC, NULL, 0x0, "RESET sequence number", HFILL }},
{ &hf_mq_status_length,
{ "Length", "mq.status.length", FT_UINT32, BASE_DEC, NULL, 0x0, "STATUS length", HFILL }},
{ &hf_mq_status_code,
{ "Code", "mq.status.code", FT_UINT32, BASE_DEC, VALS(mq_status_vals), 0x0, "STATUS code", HFILL }},
{ &hf_mq_status_value,
{ "Value", "mq.status.value", FT_UINT32, BASE_DEC, NULL, 0x0, "STATUS value", HFILL }},
{ &hf_mq_od_structid,
{ "OD structid", "mq.od.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_od_version,
{ "Version", "mq.od.version", FT_UINT32, BASE_DEC, NULL, 0x0, "OD version", HFILL }},
{ &hf_mq_od_objecttype,
{ "Object type", "mq.od.objtype", FT_UINT32, BASE_DEC, NULL, 0x0, "OD object type", HFILL }},
{ &hf_mq_od_objectname,
{ "Object name", "mq.od.objname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD object name", HFILL }},
{ &hf_mq_od_objectqmgrname,
{ "Object queue manager name", "mq.od.objqmgrname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD object queue manager name", HFILL }},
{ &hf_mq_od_dynamicqname,
{ "Dynamic queue name", "mq.od.dynqname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD dynamic queue name", HFILL }},
{ &hf_mq_od_alternateuserid,
{ "Alternate user id", "mq.od.altuserid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD alternate userid", HFILL }},
{ &hf_mq_od_recspresent,
{ "Number of records", "mq.od.nbrrec", FT_UINT32, BASE_DEC, NULL, 0x0, "OD number of records", HFILL }},
{ &hf_mq_od_knowndestcount,
{ "Known destination count", "mq.od.kdestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "OD known destination count", HFILL }},
{ &hf_mq_od_unknowndestcount,
{ "Unknown destination count", "mq.od.udestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "OD unknown destination count", HFILL }},
{ &hf_mq_od_invaliddestcount,
{ "Invalid destination count", "mq.od.idestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "OD invalid destination count", HFILL }},
{ &hf_mq_od_objectrecoffset,
{ "Offset of first OR", "mq.od.offsetor", FT_UINT32, BASE_DEC, NULL, 0x0, "OD offset of first OR", HFILL }},
{ &hf_mq_od_responserecoffset,
{ "Offset of first RR", "mq.od.offsetrr", FT_UINT32, BASE_DEC, NULL, 0x0, "OD offset of first RR", HFILL }},
{ &hf_mq_od_objectrecptr,
{ "Address of first OR", "mq.od.addror", FT_UINT32, BASE_HEX, NULL, 0x0, "OD address of first OR", HFILL }},
{ &hf_mq_od_responserecptr,
{ "Address of first RR", "mq.od.addrrr", FT_UINT32, BASE_HEX, NULL, 0x0, "OD address of first RR", HFILL }},
{ &hf_mq_od_alternatesecurityid,
{ "Alternate security id", "mq.od.altsecid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD alternate security id", HFILL }},
{ &hf_mq_od_resolvedqname,
{ "Resolved queue name", "mq.od.resolvq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD resolved queue name", HFILL }},
{ &hf_mq_od_resolvedqmgrname,
{ "Resolved queue manager name", "mq.od.resolvqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD resolved queue manager name", HFILL }},
{ &hf_mq_or_objname,
{ "Object name", "mq.or.objname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OR object name", HFILL }},
{ &hf_mq_or_objqmgrname,
{ "Object queue manager name", "mq.or.objqmgrname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OR object queue manager name", HFILL }},
{ &hf_mq_rr_completioncode,
{ "Completion code", "mq.rr.completioncode", FT_UINT32, BASE_DEC, NULL, 0x0, "OR completion code", HFILL }},
{ &hf_mq_rr_reasoncode,
{ "Reason code", "mq.rr.reasoncode", FT_UINT32, BASE_DEC, NULL, 0x0, "OR reason code", HFILL }},
{ &hf_mq_pmr_msgid,
{ "Message Id", "mq.pmr.msgid", FT_BYTES, BASE_NONE, NULL, 0x0, "PMR Message Id", HFILL }},
{ &hf_mq_pmr_correlid,
{ "Correlation Id", "mq.pmr.correlid", FT_BYTES, BASE_NONE, NULL, 0x0, "PMR Correlation Id", HFILL }},
{ &hf_mq_pmr_groupid,
{ "GroupId", "mq.pmr.groupid", FT_BYTES, BASE_NONE, NULL, 0x0, "PMR GroupId", HFILL }},
{ &hf_mq_pmr_feedback,
{ "Feedback", "mq.pmr.feedback", FT_UINT32, BASE_DEC, NULL, 0x0, "PMR Feedback", HFILL }},
{ &hf_mq_pmr_acttoken,
{ "Accounting token", "mq.pmr.acttoken", FT_BYTES, BASE_NONE, NULL, 0x0, "PMR accounting token", HFILL }},
{ &hf_mq_md_structid,
{ "MD structid", "mq.md.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_md_version,
{ "Version", "mq.md.version", FT_UINT32, BASE_DEC, NULL, 0x0, "MD version", HFILL }},
{ &hf_mq_md_report,
{ "Report", "mq.md.report", FT_UINT32, BASE_DEC, NULL, 0x0, "MD report", HFILL }},
{ &hf_mq_md_msgtype,
{ "Message type", "mq.md.msgtype", FT_UINT32, BASE_DEC, NULL, 0x0, "MD message type", HFILL }},
{ &hf_mq_md_expiry,
{ "Expiry", "mq.md.expiry", FT_INT32, BASE_DEC, NULL, 0x0, "MD expiry", HFILL }},
{ &hf_mq_md_feedback,
{ "Feedback", "mq.md.feedback", FT_UINT32, BASE_DEC, NULL, 0x0, "MD feedback", HFILL }},
{ &hf_mq_md_encoding,
{ "Encoding", "mq.md.encoding", FT_UINT32, BASE_DEC, NULL, 0x0, "MD encoding", HFILL }},
{ &hf_mq_md_ccsid,
{ "Character set", "mq.md.ccsid", FT_INT32, BASE_DEC, NULL, 0x0, "MD character set", HFILL }},
{ &hf_mq_md_format,
{ "Format", "mq.md.format", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD format", HFILL }},
{ &hf_mq_md_priority,
{ "Priority", "mq.md.priority", FT_INT32, BASE_DEC, NULL, 0x0, "MD priority", HFILL }},
{ &hf_mq_md_persistence,
{ "Persistence", "mq.md.persistence", FT_UINT32, BASE_DEC, NULL, 0x0, "MD persistence", HFILL }},
{ &hf_mq_md_msgid,
{ "MessageId", "mq.md.msgid", FT_BYTES, BASE_NONE, NULL, 0x0, "MD Message Id", HFILL }},
{ &hf_mq_md_correlid,
{ "CorrelationId", "mq.md.correlid", FT_BYTES, BASE_NONE, NULL, 0x0, "MD Correlation Id", HFILL }},
{ &hf_mq_md_backountcount,
{ "Backount count", "mq.md.backount", FT_UINT32, BASE_DEC, NULL, 0x0, "MD Backount count", HFILL }},
{ &hf_mq_md_replytoq,
{ "ReplyToQ", "mq.md.replytoq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD ReplyTo queue", HFILL }},
{ &hf_mq_md_replytoqmgr,
{ "ReplyToQMgr", "mq.md.replytoqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD ReplyTo queue manager", HFILL }},
{ &hf_mq_md_userid,
{ "UserId", "mq.md.userid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD UserId", HFILL }},
{ &hf_mq_md_acttoken,
{ "Accounting token", "mq.md.acttoken", FT_BYTES, BASE_NONE, NULL, 0x0, "MD accounting token", HFILL }},
{ &hf_mq_md_appliddata,
{ "ApplicationId data", "mq.md.appldata", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Put applicationId data", HFILL }},
{ &hf_mq_md_putappltype,
{ "Put Application Type", "mq.md.appltype", FT_INT32, BASE_DEC, NULL, 0x0, "MD Put application type", HFILL }},
{ &hf_mq_md_putapplname,
{ "Put Application Name", "mq.md.applname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Put application name", HFILL }},
{ &hf_mq_md_putdate,
{ "Put date", "mq.md.date", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Put date", HFILL }},
{ &hf_mq_md_puttime,
{ "Put time", "mq.md.time", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Put time", HFILL }},
{ &hf_mq_md_applorigindata,
{ "Application original data", "mq.md.origdata", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Application original data", HFILL }},
{ &hf_mq_md_groupid,
{ "GroupId", "mq.md.groupid", FT_BYTES, BASE_NONE, NULL, 0x0, "MD GroupId", HFILL }},
{ &hf_mq_md_msgseqnumber,
{ "Message sequence number", "mq.md.msgseqnumber", FT_UINT32, BASE_DEC, NULL, 0x0, "MD Message sequence number", HFILL }},
{ &hf_mq_md_offset,
{ "Offset", "mq.md.offset", FT_UINT32, BASE_DEC, NULL, 0x0, "MD Offset", HFILL }},
{ &hf_mq_md_msgflags,
{ "Message flags", "mq.md.msgflags", FT_UINT32, BASE_HEX, NULL, 0x0, "MD Message flags", HFILL }},
{ &hf_mq_md_originallength,
{ "Original length", "mq.md.origlength", FT_INT32, BASE_DEC, NULL, 0x0, "MD Original length", HFILL }},
{ &hf_mq_md_hidden_lastformat,
{ "Last format", "mq.md.lastformat", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Last format", HFILL }},
{ &hf_mq_dlh_structid,
{ "DLH structid", "mq.dlh.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_dlh_version,
{ "Version", "mq.dlh.version", FT_UINT32, BASE_DEC, NULL, 0x0, "DLH version", HFILL }},
{ &hf_mq_dlh_reason,
{ "Reason", "mq.dlh.reason", FT_UINT32, BASE_DEC, NULL, 0x0, "DLH reason", HFILL }},
{ &hf_mq_dlh_destq,
{ "Destination queue", "mq.dlh.destq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH destination queue", HFILL }},
{ &hf_mq_dlh_destqmgr,
{ "Destination queue manager", "mq.dlh.destqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH destination queue manager", HFILL }},
{ &hf_mq_dlh_encoding,
{ "Encoding", "mq.dlh.encoding", FT_UINT32, BASE_DEC, NULL, 0x0, "DLH encoding", HFILL }},
{ &hf_mq_dlh_ccsid,
{ "Character set", "mq.dlh.ccsid", FT_INT32, BASE_DEC, NULL, 0x0, "DLH character set", HFILL }},
{ &hf_mq_dlh_format,
{ "Format", "mq.dlh.format", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH format", HFILL }},
{ &hf_mq_dlh_putappltype,
{ "Put application type", "mq.dlh.putappltype", FT_INT32, BASE_DEC, NULL, 0x0, "DLH put application type", HFILL }},
{ &hf_mq_dlh_putapplname,
{ "Put application name", "mq.dlh.putapplname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH put application name", HFILL }},
{ &hf_mq_dlh_putdate,
{ "Put date", "mq.dlh.putdate", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH put date", HFILL }},
{ &hf_mq_dlh_puttime,
{ "Put time", "mq.dlh.puttime", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH put time", HFILL }},
{ &hf_mq_dh_putmsgrecfields,
{ "Flags PMR", "mq.dh.flagspmr", FT_UINT32, BASE_DEC, NULL, 0x0, "DH flags PMR", HFILL }},
{ &hf_mq_dh_recspresent,
{ "Number of records", "mq.dh.nbrrec", FT_UINT32, BASE_DEC, NULL, 0x0, "DH number of records", HFILL }},
{ &hf_mq_dh_objectrecoffset,
{ "Offset of first OR", "mq.dh.offsetor", FT_UINT32, BASE_DEC, NULL, 0x0, "DH offset of first OR", HFILL }},
{ &hf_mq_dh_putmsgrecoffset,
{ "Offset of first PMR", "mq.dh.offsetpmr", FT_UINT32, BASE_DEC, NULL, 0x0, "DH offset of first PMR", HFILL }},
{ &hf_mq_gmo_structid,
{ "GMO structid", "mq.gmo.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_gmo_version,
{ "Version", "mq.gmo.version", FT_UINT32, BASE_DEC, NULL, 0x0, "GMO version", HFILL }},
{ &hf_mq_gmo_options,
{ "Options", "mq.gmo.options", FT_UINT32, BASE_HEX, NULL, 0x0, "GMO options", HFILL }},
{ &hf_mq_gmo_waitinterval,
{ "Wait Interval", "mq.gmo.waitint", FT_INT32, BASE_DEC, NULL, 0x0, "GMO wait interval", HFILL }},
{ &hf_mq_gmo_signal1,
{ "Signal 1", "mq.gmo.signal1", FT_UINT32, BASE_HEX, NULL, 0x0, "GMO signal 1", HFILL }},
{ &hf_mq_gmo_signal2,
{ "Signal 2", "mq.gmo.signal2", FT_UINT32, BASE_HEX, NULL, 0x0, "GMO signal 2", HFILL }},
{ &hf_mq_gmo_resolvedqname,
{ "Resolved queue name", "mq.gmo.resolvq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "GMO resolved queue name", HFILL }},
{ &hf_mq_gmo_matchoptions,
{ "Match options", "mq.gmo.matchopt", FT_UINT32, BASE_HEX, NULL, 0x0, "GMO match options", HFILL }},
{ &hf_mq_gmo_groupstatus,
{ "Group status", "mq.gmo.grpstat", FT_UINT8, BASE_HEX, NULL, 0x0, "GMO group status", HFILL }},
{ &hf_mq_gmo_segmentstatus,
{ "Segment status", "mq.gmo.sgmtstat", FT_UINT8, BASE_HEX, NULL, 0x0, "GMO segment status", HFILL }},
{ &hf_mq_gmo_segmentation,
{ "Segmentation", "mq.gmo.segmentation", FT_UINT8, BASE_HEX, NULL, 0x0, "GMO segmentation", HFILL }},
{ &hf_mq_gmo_reserved,
{ "Reserved", "mq.gmo.reserved", FT_UINT8, BASE_HEX, NULL, 0x0, "GMO reserved", HFILL }},
{ &hf_mq_gmo_msgtoken,
{ "Message token", "mq.gmo.msgtoken", FT_BYTES, BASE_NONE, NULL, 0x0, "GMO message token", HFILL }},
{ &hf_mq_gmo_returnedlength,
{ "Returned length", "mq.gmo.retlen", FT_INT32, BASE_DEC, NULL, 0x0, "GMO returned length", HFILL }},
{ &hf_mq_pmo_structid,
{ "PMO structid", "mq.pmo.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_pmo_version,
{ "Version", "mq.pmo.version", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO version", HFILL }},
{ &hf_mq_pmo_options,
{ "Options", "mq.pmo.options", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO options", HFILL }},
{ &hf_mq_pmo_timeout,
{ "Timeout", "mq.pmo.timeout", FT_INT32, BASE_DEC, NULL, 0x0, "PMO time out", HFILL }},
{ &hf_mq_pmo_context,
{ "Context", "mq.pmo.context", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO context", HFILL }},
{ &hf_mq_pmo_knowndestcount,
{ "Known destination count", "mq.pmo.kdstcount", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO known destination count", HFILL }},
{ &hf_mq_pmo_unknowndestcount,
{ "Unknown destination count", "mq.pmo.udestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO unknown destination count", HFILL }},
{ &hf_mq_pmo_invaliddestcount,
{ "Invalid destination count", "mq.pmo.idestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO invalid destination count", HFILL }},
{ &hf_mq_pmo_resolvedqname,
{ "Resolved queue name", "mq.pmo.resolvq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "PMO resolved queue name", HFILL }},
{ &hf_mq_pmo_resolvedqmgrname,
{ "Resolved queue name manager", "mq.pmo.resolvqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "PMO resolved queue manager name", HFILL }},
{ &hf_mq_pmo_recspresent,
{ "Number of records", "mq.pmo.nbrrec", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO number of records", HFILL }},
{ &hf_mq_pmo_putmsgrecfields,
{ "Flags PMR fields", "mq.pmo.flagspmr", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO flags PMR fields", HFILL }},
{ &hf_mq_pmo_putmsgrecoffset,
{ "Offset of first PMR", "mq.pmo.offsetpmr", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO offset of first PMR", HFILL }},
{ &hf_mq_pmo_responserecoffset,
{ "Offset of first RR", "mq.pmo.offsetrr", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO offset of first RR", HFILL }},
{ &hf_mq_pmo_putmsgrecptr,
{ "Address of first record", "mq.pmo.addrrec", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO address of first record", HFILL }},
{ &hf_mq_pmo_responserecptr,
{ "Address of first response record", "mq.pmo.addrres", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO address of first response record", HFILL }},
{ &hf_mq_head_structid,
{ "Structid", "mq.head.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Header structid", HFILL }},
{ &hf_mq_head_version,
{ "Structid", "mq.head.version", FT_UINT32, BASE_DEC, NULL, 0x0, "Header version", HFILL }},
{ &hf_mq_head_length,
{ "Length", "mq.head.length", FT_UINT32, BASE_DEC, NULL, 0x0, "Header length", HFILL }},
{ &hf_mq_head_encoding,
{ "Encoding", "mq.head.encoding", FT_UINT32, BASE_DEC, NULL, 0x0, "Header encoding", HFILL }},
{ &hf_mq_head_ccsid,
{ "Character set", "mq.head.ccsid", FT_INT32, BASE_DEC, NULL, 0x0, "Header character set", HFILL }},
{ &hf_mq_head_format,
{ "Format", "mq.head.format", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Header format", HFILL }},
{ &hf_mq_head_flags,
{ "Flags", "mq.head.flags", FT_UINT32, BASE_DEC, NULL, 0x0, "Header flags", HFILL }},
{ &hf_mq_head_struct,
{ "Struct", "mq.head.struct", FT_BYTES, BASE_NONE, NULL, 0x0, "Header struct", HFILL }},
{ &hf_mq_xa_length,
{ "Length", "mq.xa.length", FT_UINT32, BASE_DEC, NULL, 0x0, "XA Length", HFILL }},
{ &hf_mq_xa_returnvalue,
{ "Return value", "mq.xa.returnvalue", FT_INT32, BASE_DEC, VALS(mq_xaer_vals), 0x0, "XA Return Value", HFILL }},
{ &hf_mq_xa_tmflags,
{ "Transaction Manager Flags", "mq.xa.tmflags", FT_UINT32, BASE_HEX, NULL, 0x0, "XA Transaction Manager Flags", HFILL }},
{ &hf_mq_xa_rmid,
{ "Resource manager ID", "mq.xa.rmid", FT_UINT32, BASE_DEC, NULL, 0x0, "XA Resource Manager ID", HFILL }},
{ &hf_mq_xa_count,
{ "Number of Xid", "mq.xa.nbxid", FT_UINT32, BASE_DEC, NULL, 0x0, "XA Number of Xid", HFILL }},
{ &hf_mq_xa_tmflags_join,
{ "JOIN", "mq.xa.tmflags.join", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMJOIN, "XA TM Flags JOIN", HFILL }},
{ &hf_mq_xa_tmflags_endrscan,
{ "ENDRSCAN", "mq.xa.tmflags.endrscan", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMENDRSCAN, "XA TM Flags ENDRSCAN", HFILL }},
{ &hf_mq_xa_tmflags_startrscan,
{ "STARTRSCAN", "mq.xa.tmflags.startrscan", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMSTARTRSCAN, "XA TM Flags STARTRSCAN", HFILL }},
{ &hf_mq_xa_tmflags_suspend,
{ "SUSPEND", "mq.xa.tmflags.suspend", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMSUSPEND, "XA TM Flags SUSPEND", HFILL }},
{ &hf_mq_xa_tmflags_success,
{ "SUCCESS", "mq.xa.tmflags.success", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMSUCCESS, "XA TM Flags SUCCESS", HFILL }},
{ &hf_mq_xa_tmflags_resume,
{ "RESUME", "mq.xa.tmflags.resume", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMRESUME, "XA TM Flags RESUME", HFILL }},
{ &hf_mq_xa_tmflags_fail,
{ "FAIL", "mq.xa.tmflags.fail", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMFAIL, "XA TM Flags FAIL", HFILL }},
{ &hf_mq_xa_tmflags_onephase,
{ "ONEPHASE", "mq.xa.tmflags.onephase", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMONEPHASE, "XA TM Flags ONEPHASE", HFILL }},
{ &hf_mq_xa_xid_formatid,
{ "Format ID", "mq.xa.xid.formatid", FT_INT32, BASE_DEC, NULL, 0x0, "XA Xid Format ID", HFILL }},
{ &hf_mq_xa_xid_globalxid_length,
{ "Global TransactionId Length", "mq.xa.xid.gxidl", FT_UINT8, BASE_DEC, NULL, 0x0, "XA Xid Global TransactionId Length", HFILL }},
{ &hf_mq_xa_xid_brq_length,
{ "Branch Qualifier Length", "mq.xa.xid.bql", FT_UINT8, BASE_DEC, NULL, 0x0, "XA Xid Branch Qualifier Length", HFILL }},
{ &hf_mq_xa_xid_globalxid,
{ "Global TransactionId", "mq.xa.xid.gxid", FT_BYTES, BASE_NONE, NULL, 0x0, "XA Xid Global TransactionId", HFILL }},
{ &hf_mq_xa_xid_brq,
{ "Branch Qualifier", "mq.xa.xid.bq", FT_BYTES, BASE_NONE, NULL, 0x0, "XA Xid Branch Qualifier", HFILL }},
{ &hf_mq_xa_xainfo_length,
{ "Length", "mq.xa.xainfo.length", FT_UINT8, BASE_DEC, NULL, 0x0, "XA XA_info Length", HFILL }},
{ &hf_mq_xa_xainfo_value,
{ "Value", "mq.xa.xainfo.value", FT_STRINGZ, BASE_NONE, NULL, 0x0, "XA XA_info Value", HFILL }}
};
static gint *ett[] = {
&ett_mq,
&ett_mq_tsh,
&ett_mq_tsh_tcf,
&ett_mq_api,
&ett_mq_msh,
&ett_mq_xqh,
&ett_mq_id,
&ett_mq_id_icf,
&ett_mq_id_ief,
&ett_mq_uid,
&ett_mq_conn,
&ett_mq_inq,
&ett_mq_spi,
&ett_mq_spi_base,
&ett_mq_spi_options,
&ett_mq_put,
&ett_mq_open,
&ett_mq_ping,
&ett_mq_reset,
&ett_mq_status,
&ett_mq_od,
&ett_mq_or,
&ett_mq_rr,
&ett_mq_pmr,
&ett_mq_md,
&ett_mq_mde,
&ett_mq_dlh,
&ett_mq_dh,
&ett_mq_gmo,
&ett_mq_pmo,
&ett_mq_head,
&ett_mq_xa,
&ett_mq_xa_tmflags,
&ett_mq_xa_xid,
&ett_mq_xa_info,
};
module_t *mq_module;
proto_mq = proto_register_protocol("WebSphere MQ", "MQ", "mq");
proto_register_field_array(proto_mq, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_heur_dissector_list("mq", &mq_heur_subdissector_list);
register_init_routine(mq_init);
mq_module = prefs_register_protocol(proto_mq, NULL);
prefs_register_bool_preference(mq_module, "desegment",
"Reassemble MQ messages spanning multiple TCP segments",
"Whether the MQ dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&mq_desegment);
prefs_register_bool_preference(mq_module, "reassembly",
"Reassemble segmented MQ messages",
"Whether the MQ dissector should reassemble MQ messages spanning multiple TSH segments",
&mq_reassembly);
}
void
proto_reg_handoff_mq(void)
{
mq_tcp_handle = create_dissector_handle(dissect_mq_tcp, proto_mq);
mq_spx_handle = create_dissector_handle(dissect_mq_spx, proto_mq);
dissector_add_handle("tcp.port", mq_tcp_handle);
heur_dissector_add("tcp", dissect_mq_heur_tcp, proto_mq);
heur_dissector_add("netbios", dissect_mq_heur_netbios, proto_mq);
heur_dissector_add("http", dissect_mq_heur_http, proto_mq);
dissector_add_uint("spx.socket", MQ_SOCKET_SPX, mq_spx_handle);
data_handle = find_dissector("data");
}
