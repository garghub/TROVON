static gint dissect_mq_MQMO(tvbuff_t *tvb, proto_tree *mq_tree, gint offset,gint ett_subtree, mq_parm_t *p_mq_parm)
{
proto_item *ti = NULL;
proto_tree *mq_tree_sub = NULL;
guint uMoOpt;
ti = proto_tree_add_item(mq_tree, hf_mq_gmo_matchoptions, tvb, offset, 4, p_mq_parm->mq_int_enc);
mq_tree_sub = proto_item_add_subtree(ti, ett_subtree);
uMoOpt= tvb_get_guint32_endian(tvb, offset,p_mq_parm->mq_int_enc);
if (uMoOpt==0)
{
proto_tree_add_text(mq_tree_sub, tvb, offset, 4, MQ_TEXT_MQMO_NONE);
}
else
{
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_matchoptions_MATCH_MSG_TOKEN , tvb, offset, 4, uMoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_matchoptions_MATCH_OFFSET , tvb, offset, 4, uMoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_matchoptions_MATCH_MSG_SEQ_NUMBER, tvb, offset, 4, uMoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_matchoptions_MATCH_GROUP_ID , tvb, offset, 4, uMoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_matchoptions_MATCH_CORREL_ID , tvb, offset, 4, uMoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_matchoptions_MATCH_MSG_ID , tvb, offset, 4, uMoOpt);
}
return 4;
}
static gint dissect_mq_MQGMO(tvbuff_t *tvb, proto_tree *mq_tree, gint offset,gint ett_subtree, mq_parm_t *p_mq_parm)
{
proto_item *ti = NULL;
proto_tree *mq_tree_sub = NULL;
guint uGmoOpt;
ti = proto_tree_add_item(mq_tree, hf_mq_gmo_options, tvb, offset, 4, p_mq_parm->mq_int_enc);
mq_tree_sub = proto_item_add_subtree(ti, ett_subtree);
uGmoOpt= tvb_get_guint32_endian(tvb, offset,p_mq_parm->mq_int_enc);
if (uGmoOpt==0)
{
proto_tree_add_text(mq_tree_sub, tvb, offset, 4, MQ_TEXT_MQGMO_NONE);
}
else
{
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_PROPERTIES_COMPATIBILITY, tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_PROPERTIES_IN_HANDLE , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_NO_PROPERTIES , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_PROPERTIES_FORCE_MQRFH2 , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_UNMARKED_BROWSE_MSG , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_UNMARK_BROWSE_HANDLE , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_UNMARK_BROWSE_CO_OP , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_MARK_BROWSE_CO_OP , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_MARK_BROWSE_HANDLE , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_ALL_SEGMENTS_AVAILABLE , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_ALL_MSGS_AVAILABLE , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_COMPLETE_MSG , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_LOGICAL_ORDER , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_CONVERT , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_FAIL_IF_QUIESCING , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_SYNCPOINT_IF_PERSISTENT , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_BROWSE_MSG_UNDER_CURSOR , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_UNLOCK , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_LOCK , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_MSG_UNDER_CURSOR , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_MARK_SKIP_BACKOUT , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_ACCEPT_TRUNCATED_MSG , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_BROWSE_NEXT , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_BROWSE_FIRST , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_SET_SIGNAL , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_NO_SYNCPOINT , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_SYNCPOINT , tvb, offset, 4, uGmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_gmo_options_WAIT , tvb, offset, 4, uGmoOpt);
}
return 4;
}
static gint dissect_mq_MQPMO(tvbuff_t *tvb, proto_tree *mq_tree, gint offset,gint ett_subtree, mq_parm_t *p_mq_parm)
{
proto_item *ti = NULL;
proto_tree *mq_tree_sub = NULL;
guint uPmoOpt;
ti = proto_tree_add_item(mq_tree, hf_mq_pmo_options, tvb, offset, 4, p_mq_parm->mq_int_enc);
mq_tree_sub = proto_item_add_subtree(ti, ett_subtree);
uPmoOpt= tvb_get_guint32_endian(tvb, offset,p_mq_parm->mq_int_enc);
if (uPmoOpt==0)
{
proto_tree_add_text(mq_tree_sub, tvb, offset, 4, MQ_TEXT_MQPMO_NONE);
}
else
{
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_NOT_OWN_SUBS , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_SUPPRESS_REPLYTO , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_SCOPE_QMGR , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_MD_FOR_OUTPUT_ONLY , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_RETAIN , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_WARN_IF_NO_SUBS_MATCHED , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_RESOLVE_LOCAL_Q , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_SYNC_RESPONSE , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_ASYNC_RESPONSE , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_LOGICAL_ORDER , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_NO_CONTEXT , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_FAIL_IF_QUIESCING , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_ALTERNATE_USER_AUTHORITY , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_SET_ALL_CONTEXT , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_SET_IDENTITY_CONTEXT , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_PASS_ALL_CONTEXT , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_PASS_IDENTITY_CONTEXT , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_NEW_CORREL_ID , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_NEW_MSG_ID , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_DEFAULT_CONTEXT , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_NO_SYNCPOINT , tvb, offset, 4, uPmoOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_pmo_options_SYNCPOINT , tvb, offset, 4, uPmoOpt);
}
return 4;
}
static gint dissect_mq_MQOO(tvbuff_t *tvb, proto_tree *mq_tree, gint offset,gint ett_subtree, mq_parm_t *p_mq_parm)
{
proto_item *ti = NULL;
proto_tree *mq_tree_sub = NULL;
guint uOpenOpt;
ti = proto_tree_add_item(mq_tree, hf_mq_open_options, tvb, offset, 4, p_mq_parm->mq_int_enc);
mq_tree_sub = proto_item_add_subtree(ti, ett_subtree);
uOpenOpt= tvb_get_guint32_endian(tvb, offset,p_mq_parm->mq_int_enc);
if (uOpenOpt==0)
{
proto_tree_add_text(mq_tree_sub, tvb, offset, 4, MQ_TEXT_BIND_READAHEAD_AS_Q_DEF);
}
else
{
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_BIND_ON_GROUP , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_NO_MULTICAST , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_READ_AHEAD , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_NO_READ_AHEAD , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_RESOLVE_LOCAL_Q , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_CO_OP , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_RESOLVE_NAMES , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_BIND_NOT_FIXED , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_BIND_ON_OPEN , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_FAIL_IF_QUIESC , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_ALT_USER_AUTH, tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_SET_ALL_CONTEXT , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_SET_IDENT_CTX , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_PASS_ALL_CTX , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_PASS_IDENT_CTX , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_SAVE_ALL_CTX , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_SET , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_INQUIRE , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_OUTPUT , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_BROWSE , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_INPUT_EXCLUSIVE , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_INPUT_SHARED , tvb, offset, 4, uOpenOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_open_options_INPUT_AS_Q_DEF , tvb, offset, 4, uOpenOpt);
}
return 4;
}
static gint dissect_mq_MQCO(tvbuff_t *tvb, proto_tree *mq_tree, gint offset, mq_parm_t *p_mq_parm)
{
proto_item *ti = NULL;
proto_tree *mq_tree_sub = NULL;
guint iCloseOpt;
ti = proto_tree_add_item(mq_tree, hf_mq_close_options, tvb, offset, 4, p_mq_parm->mq_int_enc);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_close_option);
iCloseOpt= tvb_get_guint32_endian(tvb, offset,p_mq_parm->mq_int_enc);
if (iCloseOpt==0)
{
proto_tree_add_text(mq_tree_sub, tvb, offset, 4, MQ_TEXT_IMMEDIATE_NONE);
}
else
{
proto_tree_add_boolean(mq_tree_sub, hf_mq_close_options_QUIESCE , tvb, offset, 4, iCloseOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_close_options_REMOVE_SUB , tvb, offset, 4, iCloseOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_close_options_KEEP_SUB , tvb, offset, 4, iCloseOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_close_options_DELETE_PURGE , tvb, offset, 4, iCloseOpt);
proto_tree_add_boolean(mq_tree_sub, hf_mq_close_options_DELETE , tvb, offset, 4, iCloseOpt);
}
return 4;
}
static gint dissect_mq_charv(tvbuff_t *tvb, proto_tree *tree, gint offset,gint iSize,gint idx,guint8 *pStr, mq_parm_t *p_mq_parm)
{
proto_item *ti = NULL;
proto_tree *mq_tree_sub = NULL;
guint32 lStr;
guint32 oStr;
gint32 eStr;
guint8 *sStr;
static guint8 sEmpty[]="[Empty]";
lStr = tvb_get_guint32_endian(tvb, offset + 12, p_mq_parm->mq_int_enc);
oStr = tvb_get_guint32_endian(tvb, offset + 4, p_mq_parm->mq_int_enc);
eStr = tvb_get_guint32_endian(tvb, offset + 16, p_mq_parm->mq_int_enc);
if (lStr && oStr)
{
sStr = tvb_get_string_enc(wmem_packet_scope(), tvb, oStr, lStr, p_mq_parm->mq_str_enc);
}
else
sStr=NULL;
ti = proto_tree_add_text(tree, tvb, offset, iSize, "%s - %s",pStr,(sStr)?sStr:sEmpty);
mq_tree_sub = proto_item_add_subtree(ti, idx);
proto_tree_add_item(mq_tree_sub, hf_mq_charv_vsptr, tvb, offset, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree_sub, hf_mq_charv_vsoffset, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree_sub, hf_mq_charv_vsbufsize, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree_sub, hf_mq_charv_vslength, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree_sub, hf_mq_charv_vsccsid, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree_sub, hf_mq_charv_vsvalue, tvb, oStr, lStr, (eStr==500)?ENC_EBCDIC:ENC_ASCII);
return 20;
}
static gint dissect_mq_pmr(tvbuff_t *tvb, proto_tree *tree, gint offset, gint iNbrRecords, gint offsetPMR, guint32 recFlags, mq_parm_t *p_mq_parm)
{
gint iSizePMR1 = 0;
gint iSizePMR = 0;
iSizePMR1 = ((((recFlags & MQ_PMRF_MSG_ID) != 0) * 24)
+(((recFlags & MQ_PMRF_CORREL_ID) != 0) * 24)
+(((recFlags & MQ_PMRF_GROUP_ID) != 0) * 24)
+(((recFlags & MQ_PMRF_FEEDBACK) != 0) * 4)
+(((recFlags & MQ_PMRF_ACCOUNTING_TOKEN) != 0) * 32));
if (offsetPMR!=0 && iSizePMR1!=0)
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
proto_item *ti = proto_tree_add_text(tree, tvb, offset + iOffsetPMR, iSizePMR1, MQ_TEXT_PMR);
proto_tree *mq_tree = proto_item_add_subtree(ti, ett_mq_pmr);
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
proto_tree_add_item(mq_tree, hf_mq_pmr_feedback, tvb, offset + iOffsetPMR, 4, p_mq_parm->mq_int_enc);
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
static gint dissect_mq_or(tvbuff_t *tvb, proto_tree *tree, gint offset, gint iNbrRecords, gint offsetOR, mq_parm_t *p_mq_parm)
{
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
proto_item *ti = proto_tree_add_text(tree, tvb, offset + iOffsetOR, 96, MQ_TEXT_OR);
proto_tree *mq_tree = proto_item_add_subtree(ti, ett_mq_or);
proto_tree_add_item(mq_tree, hf_mq_or_objname, tvb, offset + iOffsetOR, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_or_objqmgrname, tvb, offset + iOffsetOR + 48, 48, p_mq_parm->mq_str_enc);
iOffsetOR += 96;
}
}
}
else iSizeOR = 0;
}
return iSizeOR;
}
static gint dissect_mq_rr(tvbuff_t *tvb, proto_tree *tree, gint offset, gint iNbrRecords, gint offsetRR, mq_parm_t *p_mq_parm)
{
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
proto_item *ti = proto_tree_add_text(tree, tvb, offset + iOffsetRR, 8, MQ_TEXT_RR);
proto_tree *mq_tree = proto_item_add_subtree(ti, ett_mq_rr);
proto_tree_add_item(mq_tree, hf_mq_rr_compcode, tvb, offset + iOffsetRR, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_rr_reascode, tvb, offset + iOffsetRR + 4, 4, p_mq_parm->mq_int_enc);
iOffsetRR += 8;
}
}
}
else iSizeRR = 0;
}
return iSizeRR;
}
static gint dissect_mq_gmo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, mq_parm_t *p_mq_parm)
{
gint iSize = 0;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
if (p_mq_parm->mq_strucID == MQ_STRUCTID_GMO || p_mq_parm->mq_strucID == MQ_STRUCTID_GMO_EBCDIC)
{
guint32 iVersion = 0;
iVersion = tvb_get_guint32_endian(tvb, offset + 4, p_mq_parm->mq_int_enc);
switch (iVersion)
{
case 1: iSize = 72; break;
case 2: iSize = 80; break;
case 3: iSize = 100; break;
}
if (iSize != 0 && tvb_length_remaining(tvb, offset) >= iSize)
{
guint8 *sQueue;
sQueue = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 24, 48, p_mq_parm->mq_str_enc);
if (strip_trailing_blanks(sQueue, 48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Q=%s", sQueue);
}
if (tree)
{
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
ti = proto_tree_add_text(tree, tvb, offset, iSize, MQ_TEXT_GMO);
mq_tree = proto_item_add_subtree(ti, ett_mq_gmo);
proto_tree_add_item(mq_tree, hf_mq_gmo_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_gmo_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
dissect_mq_MQGMO(tvb, mq_tree, offset + 8, ett_mq_gmo_option, p_mq_parm);
proto_tree_add_item(mq_tree, hf_mq_gmo_waitinterval, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_gmo_signal1, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_gmo_signal2, tvb, offset + 20, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_gmo_resolvqname, tvb, offset + 24, 48, p_mq_parm->mq_str_enc);
if (iVersion >= 2)
{
dissect_mq_MQMO(tvb, mq_tree, offset + 8, ett_mq_gmo_matchoption, p_mq_parm);
proto_tree_add_item(mq_tree, hf_mq_gmo_groupstatus, tvb, offset + 76, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_gmo_segmstatus, tvb, offset + 77, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_gmo_segmentation, tvb, offset + 78, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_gmo_reserved, tvb, offset + 79, 1, ENC_BIG_ENDIAN);
}
if (iVersion >= 3)
{
proto_tree_add_item(mq_tree, hf_mq_gmo_msgtoken, tvb, offset + 80, 16, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_gmo_returnedlen, tvb, offset + 96, 4, p_mq_parm->mq_int_enc);
}
}
}
}
return iSize;
}
static gint dissect_mq_pmo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, mq_parm_t *p_mq_parm, gint* iDistributionListSize)
{
gint iSize = 0;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
if (p_mq_parm->mq_strucID == MQ_STRUCTID_PMO || p_mq_parm->mq_strucID == MQ_STRUCTID_PMO_EBCDIC)
{
guint32 iVersion = 0;
iVersion = tvb_get_guint32_endian(tvb, offset + 4, p_mq_parm->mq_int_enc);
switch (iVersion)
{
case 1: iSize = 128; break;
case 2: iSize = 152;break;
}
if (iSize != 0 && tvb_length_remaining(tvb, offset) >= iSize)
{
guint8 * sQueue;
sQueue = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 32, 48, p_mq_parm->mq_str_enc);
if (strip_trailing_blanks(sQueue, 48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Q=%s", sQueue);
}
if (tree)
{
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
ti = proto_tree_add_text(tree, tvb, offset, iSize, MQ_TEXT_PMO);
mq_tree = proto_item_add_subtree(ti, ett_mq_pmo);
proto_tree_add_item(mq_tree, hf_mq_pmo_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
dissect_mq_MQPMO(tvb, mq_tree, offset + 8, ett_mq_pmo_option, p_mq_parm);
proto_tree_add_item(mq_tree, hf_mq_pmo_timeout, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_context, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_knowndstcnt, tvb, offset + 20, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_unkndstcnt, tvb, offset + 24, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_invaldstcnt, tvb, offset + 28, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_resolvqname, tvb, offset + 32, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_resolvqmgr, tvb, offset + 80, 48, p_mq_parm->mq_str_enc);
if (iVersion >= 2)
{
proto_tree_add_item(mq_tree, hf_mq_pmo_recspresent, tvb, offset + 128, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_putmsgrecfld, tvb, offset + 132, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_putmsgrecofs, tvb, offset + 136, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_resprecofs, tvb, offset + 140, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_putmsgrecptr, tvb, offset + 144, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_pmo_resprecptr, tvb, offset + 148, 4, p_mq_parm->mq_int_enc);
}
}
if (iVersion >= 2)
{
gint iNbrRecords = 0;
guint32 iRecFlags = 0;
iNbrRecords = tvb_get_guint32_endian(tvb, offset + 128, p_mq_parm->mq_int_enc);
iRecFlags = tvb_get_guint32_endian(tvb, offset + 132, p_mq_parm->mq_int_enc);
if (iNbrRecords > 0)
{
gint iOffsetPMR = 0;
gint iOffsetRR = 0;
*iDistributionListSize = iNbrRecords;
iOffsetPMR = tvb_get_guint32_endian(tvb, offset + 136, p_mq_parm->mq_int_enc);
iOffsetRR = tvb_get_guint32_endian(tvb, offset + 140, p_mq_parm->mq_int_enc);
iSize += dissect_mq_pmr(tvb, tree, offset + iSize, iNbrRecords, iOffsetPMR, iRecFlags, p_mq_parm);
iSize += dissect_mq_rr(tvb, tree, offset + iSize, iNbrRecords, iOffsetRR, p_mq_parm);
}
}
}
}
return iSize;
}
static gint dissect_mq_od(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, mq_parm_t *p_mq_parm, gint* iDistributionListSize)
{
gint iSize = 0;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
if (p_mq_parm->mq_strucID == MQ_STRUCTID_OD || p_mq_parm->mq_strucID == MQ_STRUCTID_OD_EBCDIC)
{
guint32 iVersion = 0;
iVersion = tvb_get_guint32_endian(tvb, offset + 4, p_mq_parm->mq_int_enc);
switch (iVersion)
{
case 1: iSize = 168; break;
case 2: iSize = 200; break;
case 3: iSize = 336; break;
case 4: iSize = 336+3*20+4; break;
}
if (iSize != 0 && tvb_length_remaining(tvb, offset) >= iSize)
{
gint iNbrRecords = 0;
guint8 *sQueue;
if (iVersion >= 2)
iNbrRecords = tvb_get_guint32_endian(tvb, offset + 168, p_mq_parm->mq_int_enc);
sQueue = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 12, 48, p_mq_parm->mq_str_enc);
if (strip_trailing_blanks(sQueue,48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Obj=%s", sQueue);
}
if (tree)
{
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
ti = proto_tree_add_text(tree, tvb, offset, iSize, MQ_TEXT_OD);
mq_tree = proto_item_add_subtree(ti, ett_mq_od);
proto_tree_add_item(mq_tree, hf_mq_od_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_od_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_od_objecttype, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_od_objectname, tvb, offset + 12, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_od_objqmgrname, tvb, offset + 60, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_od_dynqname, tvb, offset + 108, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_od_altuserid, tvb, offset + 156, 12, p_mq_parm->mq_str_enc);
if (iVersion >= 2)
{
proto_tree_add_item(mq_tree, hf_mq_od_recspresent, tvb, offset + 168, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_od_knowndstcnt, tvb, offset + 172, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_od_unknowdstcnt, tvb, offset + 176, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_od_invaldstcnt, tvb, offset + 180, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_od_objrecofs, tvb, offset + 184, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_od_resprecofs, tvb, offset + 188, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_od_objrecptr, tvb, offset + 192, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_od_resprecptr, tvb, offset + 196, 4, p_mq_parm->mq_int_enc);
}
if (iVersion >= 3)
{
proto_tree_add_item(mq_tree, hf_mq_od_altsecurid, tvb, offset + 200, 40, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_od_resolvqname, tvb, offset + 240, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_od_resolvqmgrnm, tvb, offset + 288, 48, p_mq_parm->mq_str_enc);
}
if (iVersion >= 4)
{
dissect_mq_charv(tvb, mq_tree, offset+336, 20, ett_mq_od_objstr, (guint8 *)"Object string", p_mq_parm);
dissect_mq_charv(tvb, mq_tree, offset+356, 20, ett_mq_od_selstr, (guint8 *)"Selection string", p_mq_parm);
dissect_mq_charv(tvb, mq_tree, offset+376, 20, ett_mq_od_resobjstr, (guint8 *)"Resolved object string", p_mq_parm);
proto_tree_add_item(mq_tree, hf_mq_od_resolvobjtyp, tvb, offset + 396, 4, p_mq_parm->mq_int_enc);
}
}
if (iNbrRecords > 0)
{
gint iOffsetOR = 0;
gint iOffsetRR = 0;
*iDistributionListSize = iNbrRecords;
iOffsetOR = tvb_get_guint32_endian(tvb, offset + 184, p_mq_parm->mq_int_enc);
iOffsetRR = tvb_get_guint32_endian(tvb, offset + 188, p_mq_parm->mq_int_enc);
iSize += dissect_mq_or(tvb, tree, offset, iNbrRecords, iOffsetOR, p_mq_parm);
iSize += dissect_mq_rr(tvb, tree, offset, iNbrRecords, iOffsetRR, p_mq_parm);
}
}
}
return iSize;
}
static gint dissect_mq_xid(tvbuff_t *tvb, proto_tree *tree, mq_parm_t *p_mq_parm, gint offset)
{
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
proto_tree *mq_tree = NULL;
proto_item *ti = NULL;
ti = proto_tree_add_text(tree, tvb, offset, iSizeXid, MQ_TEXT_XID);
mq_tree = proto_item_add_subtree(ti, ett_mq_xa_xid);
proto_tree_add_item(mq_tree, hf_mq_xa_xid_formatid, tvb, offset, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_xa_xid_glbxid_len, tvb, offset + 4, 1, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_xa_xid_brq_length, tvb, offset + 5, 1, p_mq_parm->mq_int_enc);
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
static gint dissect_mq_sid(tvbuff_t *tvb, proto_tree *tree, mq_parm_t *p_mq_parm, gint offset)
{
guint8 iSIDL;
guint8 iSID;
guint8 *sid_str;
gint bOffset=offset;
iSIDL=tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mq_sidlen, tvb, offset, 1, p_mq_parm->mq_int_enc);
offset++;
if (iSIDL>0)
{
iSID=tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mq_sidtyp, tvb, offset, 1, p_mq_parm->mq_int_enc);
offset++;
if (iSID==MQ_MQSIDT_NT_SECURITY_ID)
{
offset=dissect_nt_sid(tvb, offset, tree,"SID", (char **)&sid_str,-1);
}
else
{
proto_tree_add_item(tree, hf_mq_securityid, tvb, offset, 40, ENC_NA);
offset+=40;
}
}
return offset-bOffset;
}
static gint dissect_mq_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *mqroot_tree, gint offset, mq_parm_t *p_mq_parm)
{
guint8 iFAPLvl;
gint iSize;
iFAPLvl = tvb_get_guint8(tvb, offset + 4);
if (iFAPLvl<4)
iSize=44;
else if (iFAPLvl<10)
iSize=102;
else
iSize=208;
if (iSize != 0 && tvb_length_remaining(tvb, offset) >= iSize)
{
guint8 *sChannel;
sChannel = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 24, 20, p_mq_parm->mq_str_enc);
col_append_fstr(pinfo->cinfo,COL_INFO, ": FAPLvl=%d",iFAPLvl);
if (strip_trailing_blanks(sChannel, 20) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", CHL=%s", sChannel);
}
if (iFAPLvl >= 4)
{
guint8 *sQMgr;
sQMgr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 48, 48, p_mq_parm->mq_str_enc);
if (strip_trailing_blanks(sQMgr,48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", QM=%s", sQMgr);
}
}
if (mqroot_tree)
{
proto_tree *mq_tree_sub = NULL;
proto_item *ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSize, MQ_TEXT_ID);
proto_tree *mq_tree = proto_item_add_subtree(ti, ett_mq_id);
proto_tree_add_item(mq_tree, hf_mq_id_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_id_level, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
{
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
proto_tree_add_item(mq_tree, hf_mq_id_unknown02, tvb, offset + 6, 1, p_mq_parm->mq_int_enc);
{
guint8 iErrorFlags;
ti = proto_tree_add_item(mq_tree, hf_mq_id_ieflags, tvb, offset + 7, 1, p_mq_parm->mq_int_enc);
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
proto_tree_add_item(mq_tree, hf_mq_id_unknown04, tvb, offset + 8, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_MaxMsgBatch, tvb, offset + 10, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_MaxTrSize, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_maxmsgsize, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_SeqWrapVal, tvb, offset + 20, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_channel, tvb, offset + 24, 20, p_mq_parm->mq_str_enc);
if (iFAPLvl >= 4)
{
proto_tree_add_item(mq_tree, hf_mq_id_capflags, tvb, offset + 44, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_id_ccsid, tvb, offset + 46, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_qmgrname, tvb, offset + 48, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_id_HBInterval, tvb, offset + 96, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown06, tvb, offset + 100, 2, p_mq_parm->mq_int_enc);
if (iFAPLvl>=10)
{
proto_tree_add_item(mq_tree, hf_mq_id_unknown07, tvb, offset + 102, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown08, tvb, offset + 104, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown09, tvb, offset + 106, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown10, tvb, offset + 108, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown11, tvb, offset + 112, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown12, tvb, offset + 116, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown13, tvb, offset + 120, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown14, tvb, offset + 124, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown15, tvb, offset + 128, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown16, tvb, offset + 132, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown17, tvb, offset + 136, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown18, tvb, offset + 140, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_unknown19, tvb, offset + 144, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_id_mqmvers, tvb, offset + 148, 12, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_id_mqmid, tvb, offset + 160, 48, p_mq_parm->mq_str_enc);
}
}
}
}
return iSize;
}
static gint dissect_mq_md(tvbuff_t *tvb, proto_tree *tree, gint offset, struct mq_msg_properties* tMsgProps, mq_parm_t *p_mq_parm, gboolean bDecode)
{
gint iSize = 0;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
if (p_mq_parm->mq_strucID == MQ_STRUCTID_MD || p_mq_parm->mq_strucID == MQ_STRUCTID_MD_EBCDIC)
{
guint32 iVersion = 0;
iVersion = tvb_get_guint32_endian(tvb, offset + 4, p_mq_parm->mq_int_enc);
switch (iVersion)
{
case 1: iSize = 324; break;
case 2: iSize = 364; break;
}
if (bDecode && iSize != 0 && tvb_length_remaining(tvb, offset) >= iSize)
{
tMsgProps->iOffsetEncoding = offset + 24;
tMsgProps->iOffsetCcsid = offset + 28;
tMsgProps->iOffsetFormat = offset + 32;
if (tree)
{
proto_item *ti = proto_tree_add_text(tree, tvb, offset, iSize, MQ_TEXT_MD);
proto_tree *mq_tree = proto_item_add_subtree(ti, ett_mq_md);
proto_tree_add_item(mq_tree, hf_mq_md_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_md_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_report, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_msgtype, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_expiry, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_feedback, tvb, offset + 20, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_encoding, tvb, offset + 24, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_ccsid, tvb, offset + 28, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_format, tvb, offset + 32, 8, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_md_priority, tvb, offset + 40, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_persistence, tvb, offset + 44, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_msgid, tvb, offset + 48, 24, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_correlid, tvb, offset + 72, 24, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_backoutcnt, tvb, offset + 96, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_replytoq, tvb, offset + 100, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_md_replytoqmgr, tvb, offset + 148, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_md_userid, tvb, offset + 196, 12, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_md_acttoken, tvb, offset + 208, 32, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_appliddata, tvb, offset + 240, 32, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_md_putappltype, tvb, offset + 272, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_putapplname, tvb, offset + 276, 28, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_md_putdate, tvb, offset + 304, 8, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_md_puttime, tvb, offset + 312, 8, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_md_apporigdata, tvb, offset + 320, 4, p_mq_parm->mq_str_enc);
if (iVersion >= 2)
{
proto_tree_add_item(mq_tree, hf_mq_md_groupid, tvb, offset + 324, 24, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_msgseqnumber, tvb, offset + 348, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_offset, tvb, offset + 352, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_msgflags, tvb, offset + 356, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_origlen, tvb, offset + 360, 4, p_mq_parm->mq_int_enc);
}
}
}
}
return iSize;
}
static gint dissect_mq_fopa(tvbuff_t *tvb, proto_tree *tree, gint offset, mq_parm_t *p_mq_parm)
{
gint iSize = 0;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
if (p_mq_parm->mq_strucID == MQ_STRUCTID_FOPA || p_mq_parm->mq_strucID == MQ_STRUCTID_FOPA_EBCDIC)
{
iSize=tvb_get_guint32_endian(tvb, offset+8,p_mq_parm->mq_int_enc);
if (iSize != 0 && tvb_length_remaining(tvb, offset) >= iSize)
{
if (tree)
{
proto_item *ti = proto_tree_add_text(tree, tvb, offset, iSize, MQ_TEXT_FOPA);
proto_tree *mq_tree = proto_item_add_subtree(ti, ett_mq_fopa);
proto_tree_add_item(mq_tree, hf_mq_fopa_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_fopa_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_fopa_length, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_fopa_unknown1, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_fopa_unknown2, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_fopa_unknown3, tvb, offset + 20, 8, p_mq_parm->mq_str_enc);
if (iSize>28)
{
proto_tree_add_item(mq_tree, hf_mq_fopa_qprotect, tvb, offset + 28, 48, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_fopa_unknown4, tvb, offset + 76, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_fopa_unknown5, tvb, offset + 80, 4, p_mq_parm->mq_int_enc);
}
}
}
}
return iSize;
}
static void dissect_mq_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
guint32 iSegmentLength = 0;
guint32 iSizePayload = 0;
gint iSizeMD = 0;
gboolean bPayload = FALSE;
gboolean bEBCDIC = FALSE;
gint iDistributionListSize = 0;
struct mq_msg_properties tMsgProps;
mq_parm_t *p_mq_parm;
p_mq_parm = wmem_new0(wmem_packet_scope(), mq_parm_t);
p_mq_parm->mq_strucID = MQ_STRUCTID_NULL;
p_mq_parm->mq_int_enc = ENC_BIG_ENDIAN;
p_mq_parm->mq_str_enc = ENC_UTF_8|ENC_NA;
p_mq_parm->mq_encode = 0;
p_mq_parm->mq_ccsid = 0;
p_mq_parm->mq_ctlf = 0;
p_mq_parm->mq_opcode = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MQ");
tMsgProps.iOffsetEncoding = 0;
tMsgProps.iOffsetFormat = 0;
tMsgProps.iOffsetCcsid = 0;
if (tvb_length(tvb) >= 4)
{
p_mq_parm->mq_strucID = tvb_get_ntohl(tvb, offset);
if (((p_mq_parm->mq_strucID & MQ_MASK_TSHx)==MQ_STRUCTID_TSHx ||
(p_mq_parm->mq_strucID & MQ_MASK_TSHx)==MQ_STRUCTID_TSHx_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 28)
{
proto_tree *mq_tree = NULL;
proto_tree *mqroot_tree = NULL;
proto_item *ti = NULL;
gint iSizeTSH = 28;
gint iSizeMultiplexFields = 0;
if ((p_mq_parm->mq_strucID & MQ_MASK_TSHx)==MQ_STRUCTID_TSHx_EBCDIC)
{
bEBCDIC = TRUE;
p_mq_parm->mq_str_enc = ENC_EBCDIC|ENC_NA;
}
iSegmentLength = tvb_get_ntohl(tvb, offset + 4);
if (p_mq_parm->mq_strucID == MQ_STRUCTID_TSHM || p_mq_parm->mq_strucID == MQ_STRUCTID_TSHM_EBCDIC)
{
if (tvb_length_remaining(tvb, offset) < 36) return;
iSizeMultiplexFields += 8;
iSizeTSH = 36;
}
p_mq_parm->mq_opcode = tvb_get_guint8(tvb, offset + iSizeMultiplexFields + 9);
if (p_mq_parm->mq_opcode == MQ_TST_REQUEST_MSGS || p_mq_parm->mq_opcode == MQ_TST_ASYNC_MESSAGE)
{
tMsgProps.iOffsetEncoding = offset + iSizeMultiplexFields + 20;
tMsgProps.iOffsetCcsid = offset + iSizeMultiplexFields + 24;
tMsgProps.iOffsetFormat = offset ;
}
p_mq_parm->mq_int_enc = (tvb_get_guint8(tvb, offset + iSizeMultiplexFields + 8) == MQ_LITTLE_ENDIAN ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
p_mq_parm->mq_ctlf = tvb_get_guint8(tvb, offset + iSizeMultiplexFields + 10);
p_mq_parm->mq_encode=tvb_get_guint32_endian(tvb, offset + iSizeMultiplexFields + 20, p_mq_parm->mq_int_enc);
p_mq_parm->mq_ccsid =tvb_get_guint16_endian(tvb, offset + iSizeMultiplexFields + 24, p_mq_parm->mq_int_enc);
if (p_mq_parm->mq_ccsid==500 && !bEBCDIC)
{
bEBCDIC = TRUE;
p_mq_parm->mq_str_enc = ENC_EBCDIC|ENC_NA;
}
if (!mq_in_reassembly)
{
col_clear(pinfo->cinfo, COL_INFO);
col_append_sep_str(pinfo->cinfo, COL_INFO, " | ", val_to_str_ext(p_mq_parm->mq_opcode, &mq_opcode_vals_ext, "Unknown (0x%02x)"));
col_set_fence(pinfo->cinfo, COL_INFO);
}
if (tree)
{
if (p_mq_parm->mq_opcode!=MQ_TST_ASYNC_MESSAGE)
{
ti = proto_tree_add_item(tree, proto_mq, tvb, offset, -1, ENC_NA);
proto_item_append_text(ti, " (%s)", val_to_str(p_mq_parm->mq_opcode, mq_opcode_vals, "Unknown (0x%02x)"));
if (bEBCDIC == TRUE) proto_item_append_text(ti, " (EBCDIC)");
mqroot_tree = proto_item_add_subtree(ti, ett_mq);
}
else
{
mqroot_tree = tree;
}
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeTSH, MQ_TEXT_TSH);
mq_tree = proto_item_add_subtree(ti, ett_mq_tsh);
proto_tree_add_item(mq_tree, hf_mq_tsh_structid, tvb, offset + 0, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_tsh_mqseglen, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
if (iSizeTSH == 36)
{
proto_tree_add_item(mq_tree, hf_mq_tsh_convid, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_tsh_requestid, tvb, offset + 12, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(mq_tree, hf_mq_tsh_byteorder, tvb, offset + iSizeMultiplexFields + 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_tsh_opcode, tvb, offset + iSizeMultiplexFields + 9, 1, ENC_BIG_ENDIAN);
{
proto_tree *mq_tree_sub = NULL;
ti = proto_tree_add_item(mq_tree, hf_mq_tsh_ctlflgs1, tvb, offset + iSizeMultiplexFields + 10, 1, ENC_BIG_ENDIAN);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_tsh_tcf);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_dlq, tvb, offset + iSizeMultiplexFields + 10, 1, p_mq_parm->mq_ctlf);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_reqacc, tvb, offset + iSizeMultiplexFields + 10, 1, p_mq_parm->mq_ctlf);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_last, tvb, offset + iSizeMultiplexFields + 10, 1, p_mq_parm->mq_ctlf);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_first, tvb, offset + iSizeMultiplexFields + 10, 1, p_mq_parm->mq_ctlf);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_closechann, tvb, offset + iSizeMultiplexFields + 10, 1, p_mq_parm->mq_ctlf);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_reqclose, tvb, offset + iSizeMultiplexFields + 10, 1, p_mq_parm->mq_ctlf);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_error, tvb, offset + iSizeMultiplexFields + 10, 1, p_mq_parm->mq_ctlf);
proto_tree_add_boolean(mq_tree_sub, hf_mq_tsh_tcf_confirmreq, tvb, offset + iSizeMultiplexFields + 10, 1, p_mq_parm->mq_ctlf);
}
proto_tree_add_item(mq_tree, hf_mq_tsh_ctlflgs2, tvb, offset + iSizeMultiplexFields + 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_tsh_luwid, tvb, offset + iSizeMultiplexFields + 12, 8, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_tsh_encoding, tvb, offset + iSizeMultiplexFields + 20, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_tsh_ccsid, tvb, offset + iSizeMultiplexFields + 24, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_tsh_padding, tvb, offset + iSizeMultiplexFields + 26, 2, ENC_BIG_ENDIAN);
}
offset += iSizeTSH;
if (tvb_length_remaining(tvb, offset) >= 4)
{
p_mq_parm->mq_strucID = tvb_get_ntohl(tvb, offset);
if (((p_mq_parm->mq_ctlf & MQ_TCF_FIRST) != 0) || p_mq_parm->mq_opcode < 0x80)
{
gint iSizeAPI = 16;
if (p_mq_parm->mq_opcode >= 0x80 && p_mq_parm->mq_opcode <= 0x9F && tvb_length_remaining(tvb, offset) >= 16)
{
guint32 iReturnCode = 0;
guint32 iHdl = 0;
iReturnCode = tvb_get_guint32_endian(tvb, offset + 8, p_mq_parm->mq_int_enc);
iHdl = tvb_get_guint32_endian(tvb, offset + 12, p_mq_parm->mq_int_enc);
if (iHdl != 0 && iHdl != 0xffffffff)
col_append_fstr(pinfo->cinfo, COL_INFO, " Hdl=0x%08x", iHdl);
if (iReturnCode != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, " [RC=%d]", iReturnCode);
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeAPI, MQ_TEXT_API);
mq_tree = proto_item_add_subtree(ti, ett_mq_api);
proto_tree_add_item(mq_tree, hf_mq_api_replylen, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_api_compcode, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_api_reascode, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_api_objecthdl, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
}
offset += iSizeAPI;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_MSH || p_mq_parm->mq_strucID == MQ_STRUCTID_MSH_EBCDIC) && tvb_length_remaining(tvb, offset) >= 20)
{
gint iSize = 20;
iSizePayload = tvb_get_guint32_endian(tvb, offset + 16, p_mq_parm->mq_int_enc);
bPayload = TRUE;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSize, MQ_TEXT_MSH);
mq_tree = proto_item_add_subtree(ti, ett_mq_msh);
proto_tree_add_item(mq_tree, hf_mq_msh_structid, tvb, offset + 0, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_msh_seqnum, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msh_datalength, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msh_unknown1, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msh_msglength, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
}
offset += iSize;
}
else if (p_mq_parm->mq_opcode == MQ_TST_CONAUTH_INFO && tvb_length_remaining(tvb, offset) >= 20)
{
gint iSize = 24;
gint iUsr = 0;
gint iPsw = 0;
iUsr=tvb_get_guint32_endian(tvb, offset + 8, p_mq_parm->mq_int_enc);
iPsw=tvb_get_guint32_endian(tvb, offset + 12, p_mq_parm->mq_int_enc);
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSize, MQ_TEXT_CAUT);
mq_tree = proto_item_add_subtree(ti, ett_mq_caut);
proto_tree_add_item(mq_tree, hf_mq_caut_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_caut_unknown1, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_caut_userlen1, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_caut_pswdlen1, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_caut_userlen2, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_caut_pswdlen2, tvb, offset + 20, 4, p_mq_parm->mq_int_enc);
if (iUsr)
proto_tree_add_item(mq_tree, hf_mq_caut_usr, tvb, offset + 24, iUsr, p_mq_parm->mq_str_enc);
if (iPsw)
proto_tree_add_item(mq_tree, hf_mq_caut_psw, tvb, offset + 24 + iUsr, iPsw, p_mq_parm->mq_str_enc);
}
offset += iSize + iUsr + iPsw;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
else if (p_mq_parm->mq_opcode == MQ_TST_SOCKET_ACTION && tvb_length_remaining(tvb, offset) >= 20)
{
gint iSize = 20;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeAPI, MQ_TEXT_SOCKET);
mq_tree = proto_item_add_subtree(ti, ett_mq_socket);
proto_tree_add_item(mq_tree, hf_mq_socket_unknown1, tvb, offset, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_socket_unknown2, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_socket_unknown3, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_socket_unknown4, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_socket_unknown5, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
}
offset += iSize;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
else if (p_mq_parm->mq_opcode == MQ_TST_STATUS && tvb_length_remaining(tvb, offset) >= 8)
{
gint iStatus = 0;
gint iStatusLength = 0;
iStatus = tvb_get_guint32_endian(tvb, offset + 4, p_mq_parm->mq_int_enc);
iStatusLength = tvb_get_guint32_endian(tvb, offset, p_mq_parm->mq_int_enc);
if (tvb_length_remaining(tvb, offset) >= iStatusLength)
{
if (iStatus != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ": Code=%s", val_to_str(iStatus, mq_status_vals, "Unknown (0x%08x)"));
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 8, MQ_TEXT_STAT);
mq_tree = proto_item_add_subtree(ti, ett_mq_status);
proto_tree_add_item(mq_tree, hf_mq_status_length, tvb, offset, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_status_code, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
if (iStatusLength >= 12)
proto_tree_add_item(mq_tree, hf_mq_status_value, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
}
offset += iStatusLength;
}
}
else if (p_mq_parm->mq_opcode == MQ_TST_PING && tvb_length_remaining(tvb, offset) > 4)
{
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, MQ_TEXT_PING);
mq_tree = proto_item_add_subtree(ti, ett_mq_ping);
proto_tree_add_item(mq_tree, hf_mq_ping_length, tvb, offset, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_ping_buffer, tvb, offset + 4, -1, ENC_NA);
}
offset = tvb_length(tvb);
}
else if (p_mq_parm->mq_opcode == MQ_TST_RESET && tvb_length_remaining(tvb, offset) >= 8)
{
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, MQ_TEXT_RESET);
mq_tree = proto_item_add_subtree(ti, ett_mq_reset);
proto_tree_add_item(mq_tree, hf_mq_reset_length, tvb, offset, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_reset_seqnum, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
}
offset = tvb_length(tvb);
}
else if ((p_mq_parm->mq_opcode == MQ_TST_MQOPEN || p_mq_parm->mq_opcode == MQ_TST_MQCLOSE ||
p_mq_parm->mq_opcode == MQ_TST_MQOPEN_REPLY || p_mq_parm->mq_opcode == MQ_TST_MQCLOSE_REPLY)
&& tvb_length_remaining(tvb, offset) >= 4)
{
offset += dissect_mq_od(tvb, pinfo, mqroot_tree, offset, p_mq_parm, &iDistributionListSize);
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 4, MQ_TEXT_OPEN);
mq_tree = proto_item_add_subtree(ti, ett_mq_open);
if (p_mq_parm->mq_opcode == MQ_TST_MQOPEN || p_mq_parm->mq_opcode == MQ_TST_MQOPEN_REPLY)
{
dissect_mq_MQOO(tvb, mq_tree, offset, ett_mq_open_option, p_mq_parm);
}
if (p_mq_parm->mq_opcode == MQ_TST_MQCLOSE || p_mq_parm->mq_opcode == MQ_TST_MQCLOSE_REPLY)
{
dissect_mq_MQCO(tvb, mq_tree, offset, p_mq_parm);
}
}
offset += 4;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
offset += dissect_mq_fopa(tvb, mqroot_tree, offset, p_mq_parm);
}
else if ((p_mq_parm->mq_opcode == MQ_TST_MQCONN || p_mq_parm->mq_opcode == MQ_TST_MQCONN_REPLY) &&
tvb_length_remaining(tvb, offset) > 0)
{
gint iSizeCONN = 0;
gint nofs;
iSizeCONN = iSegmentLength - iSizeTSH - iSizeAPI;
if (iSizeCONN != 112 && iSizeCONN != 120 && iSizeCONN != 260 && iSizeCONN != 332) iSizeCONN = 0;
if (iSizeCONN != 0 && tvb_length_remaining(tvb, offset) >= iSizeCONN)
{
guint8 *sApplicationName;
guint8 *sQMgr;
sApplicationName = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 48, 28, p_mq_parm->mq_str_enc);
if (strip_trailing_blanks(sApplicationName, 28) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ": App=%s", sApplicationName);
}
sQMgr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 48, p_mq_parm->mq_str_enc);
if (strip_trailing_blanks(sQMgr, 48) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " QM=%s", sQMgr);
}
#define do_proto_add_item(a,b) b;nofs+=a;
nofs=offset;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeCONN, MQ_TEXT_CONN);
mq_tree = proto_item_add_subtree(ti, ett_mq_conn);
do_proto_add_item(48,proto_tree_add_item(mq_tree, hf_mq_conn_QMgr, tvb, nofs, 48, p_mq_parm->mq_str_enc));
do_proto_add_item(28,proto_tree_add_item(mq_tree, hf_mq_conn_appname , tvb, nofs, 28, p_mq_parm->mq_str_enc));
do_proto_add_item( 4,proto_tree_add_item(mq_tree, hf_mq_conn_apptype , tvb, nofs, 4, p_mq_parm->mq_int_enc));
do_proto_add_item(32,proto_tree_add_item(mq_tree, hf_mq_conn_acttoken , tvb, nofs, 32, ENC_NA));
if (iSizeCONN >= 120)
{
do_proto_add_item(4,proto_tree_add_item(mq_tree, hf_mq_conn_version, tvb, nofs, 4, p_mq_parm->mq_int_enc));
do_proto_add_item(4,proto_tree_add_item(mq_tree, hf_mq_conn_options, tvb, nofs, 4, p_mq_parm->mq_int_enc));
}
if (iSizeCONN >= 260)
{
proto_tree *mq_tree_sub = NULL;
ti = proto_tree_add_text(mq_tree, tvb, nofs,iSizeCONN - nofs, MQ_TEXT_FCNO);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_fcno);
do_proto_add_item( 4,proto_tree_add_item(mq_tree_sub, hf_mq_fcno_structid , tvb, nofs, 4, p_mq_parm->mq_str_enc));
do_proto_add_item( 4,proto_tree_add_item(mq_tree_sub, hf_mq_fcno_unknown00, tvb, nofs, 4, p_mq_parm->mq_int_enc));
do_proto_add_item( 4,proto_tree_add_item(mq_tree_sub, hf_mq_fcno_unknown01, tvb, nofs, 4, p_mq_parm->mq_int_enc));
if (iSizeCONN == 260)
{
do_proto_add_item( 12,proto_tree_add_item(mq_tree_sub, hf_mq_fcno_msgid , tvb, nofs, 12, p_mq_parm->mq_str_enc));
do_proto_add_item( 48,proto_tree_add_item(mq_tree_sub, hf_mq_fcno_mqmid , tvb, nofs, 48, p_mq_parm->mq_str_enc));
do_proto_add_item( 68,proto_tree_add_item(mq_tree_sub, hf_mq_fcno_unknown02, tvb, nofs, 68, ENC_NA));
}
if (iSizeCONN >= 332)
{
do_proto_add_item(152,proto_tree_add_item(mq_tree_sub, hf_mq_fcno_msgid , tvb, nofs, 152, p_mq_parm->mq_str_enc));
proto_tree_add_item(mq_tree_sub, hf_mq_fcno_mqmid , tvb, nofs, 48, p_mq_parm->mq_int_enc);
}
}
}
offset += iSizeCONN;
}
}
else if ((p_mq_parm->mq_opcode == MQ_TST_MQINQ || p_mq_parm->mq_opcode == MQ_TST_MQINQ_REPLY || p_mq_parm->mq_opcode == MQ_TST_MQSET) && tvb_length_remaining(tvb, offset) >= 12)
{
gint iNbSelectors = 0;
gint iNbIntegers = 0;
gint iCharLen = 0;
gint iOffsetINQ = 0;
gint iSelector = 0;
iNbSelectors = tvb_get_guint32_endian(tvb, offset, p_mq_parm->mq_int_enc);
iNbIntegers = tvb_get_guint32_endian(tvb, offset + 4, p_mq_parm->mq_int_enc);
iCharLen = tvb_get_guint32_endian(tvb, offset + 8, p_mq_parm->mq_int_enc);
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, MQ_TEXT_INQ);
mq_tree = proto_item_add_subtree(ti, ett_mq_inq);
proto_tree_add_item(mq_tree, hf_mq_inq_nbsel, tvb, offset, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_inq_nbint, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_inq_charlen, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
}
iOffsetINQ = 12;
if (tvb_length_remaining(tvb, offset + iOffsetINQ) >= iNbSelectors * 4)
{
if (tree)
{
for (iSelector = 0; iSelector < iNbSelectors; iSelector++)
{
proto_tree_add_item(mq_tree, hf_mq_inq_sel, tvb, offset + iOffsetINQ + iSelector * 4, 4, p_mq_parm->mq_int_enc);
}
}
iOffsetINQ += iNbSelectors * 4;
if (p_mq_parm->mq_opcode == MQ_TST_MQINQ_REPLY || p_mq_parm->mq_opcode == MQ_TST_MQSET)
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
proto_tree_add_item(mq_tree, hf_mq_inq_intvalue, tvb, offset + iOffsetINQ + iInteger * 4, 4, p_mq_parm->mq_int_enc);
}
}
iOffsetINQ += iNbIntegers * 4;
if (iCharLen != 0)
{
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_inq_charvalues, tvb, offset + iOffsetINQ, iCharLen, p_mq_parm->mq_str_enc);
}
}
}
}
}
offset += tvb_length(tvb);
}
else if (p_mq_parm->mq_opcode == MQ_TST_NOTIFICATION)
{
gint iHdl = 0;
iHdl = tvb_get_guint32_endian(tvb, offset+4, p_mq_parm->mq_int_enc);
col_append_fstr(pinfo->cinfo, COL_INFO, ": Hdl=0x%08x", iHdl);
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, MQ_TEXT_NOTIFICATION);
mq_tree = proto_item_add_subtree(ti, ett_mq_notif);
proto_tree_add_item(mq_tree, hf_mq_notif_vers, tvb, offset, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_notif_handle, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_notif_code, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_notif_mqrc, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
}
offset+=16;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
else if (p_mq_parm->mq_opcode == MQ_TST_REQUEST_MSGS)
{
gint iHdl;
gint iFlags;
gint iLstSeq;
gint iMaxLen;
gint xOfs;
gint iExt;
xOfs=0;
iHdl = tvb_get_guint32_endian(tvb, offset+ 4, p_mq_parm->mq_int_enc);
iMaxLen = tvb_get_guint32_endian(tvb, offset+ 16, p_mq_parm->mq_int_enc);
iFlags = tvb_get_guint32_endian(tvb, offset+ 32, p_mq_parm->mq_int_enc);
iLstSeq = tvb_get_guint32_endian(tvb, offset+ 36, p_mq_parm->mq_int_enc);
col_append_fstr(pinfo->cinfo, COL_INFO, ": Hdl=0x%08x, LstSeq=%d, MaxLen=%d",
iHdl, iLstSeq,iMaxLen);
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, MQ_TEXT_REQMSG);
mq_tree = proto_item_add_subtree(ti, ett_mq_msg);
proto_tree_add_item(mq_tree, hf_mq_msgreq_version , tvb, offset , 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_handle , tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_unknown1, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_unknown2, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_maxlen , tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_unknown4, tvb, offset + 20, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_timeout , tvb, offset + 24, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_unknown5, tvb, offset + 28, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_flags , tvb, offset + 32, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_lstseqnr, tvb, offset + 36, 4, p_mq_parm->mq_int_enc);
if (iFlags & 0x00000010)
{
proto_tree_add_item(mq_tree, hf_mq_msgreq_msegver , tvb, offset + 40, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_msegseq , tvb, offset + 42, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_ccsid , tvb, offset + 44, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_encoding, tvb, offset + 48, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_unknown6, tvb, offset + 52, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_unknown7, tvb, offset + 56, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgreq_xfldflag, tvb, offset + 60, 4, p_mq_parm->mq_int_enc);
iExt=tvb_get_guint32_endian(tvb, offset + 60, p_mq_parm->mq_int_enc);
if (iExt & MQ_MSGREQ_MSGID_PRESENT)
{
proto_tree_add_item(mq_tree, hf_mq_msgreq_msgid , tvb, offset + 64 + xOfs, 24, p_mq_parm->mq_str_enc);
xOfs+=24;
}
if (iExt & MQ_MSGREQ_MQMID_PRESENT)
{
proto_tree_add_item(mq_tree, hf_mq_msgreq_mqmid , tvb, offset + 64 + xOfs, 24, p_mq_parm->mq_str_enc);
xOfs+=24;
}
}
}
offset+=(iFlags & 0x00000010)?(64+xOfs):40;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
else if (p_mq_parm->mq_opcode == MQ_TST_ASYNC_MESSAGE)
{
gint imsegseq;
gint iCurSeq;
gint iPadLen;
gint iPayLod;
gint8 iStrLen;
gint iHdl;
gint iHdrL;
iHdl = tvb_get_guint32_endian(tvb, offset+4, p_mq_parm->mq_int_enc);
iCurSeq = tvb_get_guint32_endian(tvb, offset + 12, p_mq_parm->mq_int_enc);
imsegseq = tvb_get_guint16_endian(tvb, offset + 20, p_mq_parm->mq_int_enc);
if (p_mq_parm->mq_ctlf & MQ_TCF_FIRST)
{
iStrLen = tvb_get_guint8(tvb,offset+54);
iPadLen = (2+1+iStrLen) % 4;
iPadLen = (iPadLen)?4-iPadLen:0;
}
else
{
iPadLen=0;
iStrLen=0;
}
iHdrL=(p_mq_parm->mq_ctlf & MQ_TCF_FIRST)?(54+1+iStrLen+iPadLen):24;
iPayLod=tvb_length_remaining(tvb, offset+iHdrL);
if (!mq_in_reassembly)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ": Hdl=0x%08x, CurSeq=%d, SSeq=%d, PayLoad=%d",
iHdl, iCurSeq, imsegseq, iPayLod);
}
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iHdrL, MQ_TEXT_ASYMSG);
mq_tree = proto_item_add_subtree(ti, ett_mq_msg);
proto_tree_add_item(mq_tree, hf_mq_msgasy_version , tvb, offset , 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_handle , tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_unknown1, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_curseqnr, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_payload , tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_msegseq , tvb, offset + 20, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_msegver , tvb, offset + 22, 2, p_mq_parm->mq_int_enc);
if (p_mq_parm->mq_ctlf & MQ_TCF_FIRST)
{
proto_tree_add_item(mq_tree, hf_mq_msgasy_flags , tvb, offset + 24, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_totlen1 , tvb, offset + 28, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_totlen2 , tvb, offset + 32, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_unknown2, tvb, offset + 36, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_unknown3, tvb, offset + 40, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_unknown4, tvb, offset + 44, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_unknown5, tvb, offset + 48, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_strFlg , tvb, offset + 52, 2, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_msgasy_strLen , tvb, offset + 54, 1, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_msgasy_strVal , tvb, offset + 55, iStrLen, p_mq_parm->mq_str_enc);
if (iPadLen)
proto_tree_add_item(mq_tree, hf_mq_msgasy_strPad , tvb, offset + 55 + iStrLen, iPadLen, p_mq_parm->mq_str_enc);
}
}
offset+=iHdrL;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
iSizePayload = tvb_length_remaining(tvb, offset);
bPayload = (iSizePayload>0);
}
else if ((p_mq_parm->mq_opcode == MQ_TST_SPI || p_mq_parm->mq_opcode == MQ_TST_SPI_REPLY) && tvb_length_remaining(tvb, offset) >= 12)
{
gint iOffsetSPI = 0;
guint32 iSpiVerb = 0;
tMsgProps.iOffsetEncoding = offset + 12;
tMsgProps.iOffsetCcsid = offset + 16;
tMsgProps.iOffsetFormat = offset + 20;
iSpiVerb = tvb_get_guint32_endian(tvb, offset, p_mq_parm->mq_int_enc);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", val_to_str(iSpiVerb, mq_spi_verbs_vals, "Unknown (0x%08x)"));
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 12, MQ_TEXT_SPI);
mq_tree = proto_item_add_subtree(ti, ett_mq_spi);
proto_tree_add_item(mq_tree, hf_mq_spi_verb, tvb, offset, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_length, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
}
offset += 12;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
if (((p_mq_parm->mq_strucID & MQ_MASK_SPxZ) == MQ_STRUCTID_SPxU ||
(p_mq_parm->mq_strucID & MQ_MASK_SPxZ) == MQ_STRUCTID_SPxU_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 12)
{
gint iSizeSPIMD = 0;
if (tree)
{
guint8 *sStructId;
sStructId = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4,((p_mq_parm->mq_strucID & MQ_MASK_SPxx)==MQ_STRUCTID_SPxx)?ENC_ASCII:ENC_EBCDIC);
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 12, "%s", sStructId);
mq_tree = proto_item_add_subtree(ti, ett_mq_spi_base);
proto_tree_add_item(mq_tree, hf_mq_spi_base_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_base_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_base_length, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
}
offset += 12;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
if ((iSizeSPIMD = dissect_mq_md(tvb, mqroot_tree, offset, &tMsgProps, p_mq_parm, TRUE)) != 0)
{
offset += iSizeSPIMD;
offset += dissect_mq_gmo(tvb, pinfo, mqroot_tree, offset, p_mq_parm);
offset += dissect_mq_pmo(tvb, pinfo, mqroot_tree, offset, p_mq_parm, &iDistributionListSize);
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
offset += dissect_mq_od(tvb, pinfo, mqroot_tree, offset, p_mq_parm, &iDistributionListSize);
if (((p_mq_parm->mq_strucID & MQ_MASK_SPxZ) == MQ_STRUCTID_SPxO ||
(p_mq_parm->mq_strucID & MQ_MASK_SPxZ) == MQ_STRUCTID_SPxO_EBCDIC ||
(p_mq_parm->mq_strucID & MQ_MASK_SPxZ) == MQ_STRUCTID_SPxI ||
(p_mq_parm->mq_strucID & MQ_MASK_SPxZ) == MQ_STRUCTID_SPxI_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 12)
{
if (tree)
{
guint8 *sStructId;
sStructId = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4,((p_mq_parm->mq_strucID & MQ_MASK_SPxx)==MQ_STRUCTID_SPxx)?ENC_ASCII:ENC_EBCDIC);
ti = proto_tree_add_text(mqroot_tree, tvb, offset, -1, "%s", sStructId);
mq_tree = proto_item_add_subtree(ti, ett_mq_spi_base);
proto_tree_add_item(mq_tree, hf_mq_spi_base_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_base_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_base_length, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
}
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_SPQO || p_mq_parm->mq_strucID == MQ_STRUCTID_SPQO_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 16)
{
if (tree)
{
gint iVerbNumber = 0;
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_nbverb, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
iVerbNumber = tvb_get_guint32_endian(tvb, offset + 12, p_mq_parm->mq_int_enc);
if (tvb_length_remaining(tvb, offset) >= iVerbNumber * 20 + 16)
{
gint iVerb = 0;
iOffsetSPI = offset + 16;
for (iVerb = 0; iVerb < iVerbNumber; iVerb++)
{
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_verbid, tvb, iOffsetSPI, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_maxiover, tvb, iOffsetSPI + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_maxinver, tvb, iOffsetSPI + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_maxouver, tvb, iOffsetSPI + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_spqo_flags, tvb, iOffsetSPI + 16, 4, p_mq_parm->mq_int_enc);
iOffsetSPI += 20;
}
offset += iVerbNumber * 20 + 16;
}
}
}
else if ((p_mq_parm->mq_strucID == MQ_STRUCTID_SPAI || p_mq_parm->mq_strucID == MQ_STRUCTID_SPAI_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 136)
{
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_spi_spai_mode, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_spai_unknown1, tvb, offset + 16, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_spai_unknown2, tvb, offset + 64, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_spai_msgid, tvb, offset + 112, 24, p_mq_parm->mq_str_enc);
}
offset += 136;
}
else if ((p_mq_parm->mq_strucID == MQ_STRUCTID_SPGI || p_mq_parm->mq_strucID == MQ_STRUCTID_SPGI_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 24)
{
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_spi_spgi_batchsz, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_spgi_batchint, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_spi_spgi_maxmsgsz, tvb, offset + 20, 4, p_mq_parm->mq_int_enc);
}
offset += 24;
}
else if ((p_mq_parm->mq_strucID == MQ_STRUCTID_SPGO || p_mq_parm->mq_strucID == MQ_STRUCTID_SPPI ||
p_mq_parm->mq_strucID == MQ_STRUCTID_SPGO_EBCDIC || p_mq_parm->mq_strucID == MQ_STRUCTID_SPPI_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 20)
{
if (tree)
{
{
proto_tree *mq_tree_sub = NULL;
gint iOptionsFlags;
ti = proto_tree_add_item(mq_tree, hf_mq_spi_spgo_options, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_spi_options);
iOptionsFlags = tvb_get_guint32_endian(tvb, offset + 12, p_mq_parm->mq_int_enc);
proto_tree_add_boolean(mq_tree_sub, hf_mq_spi_opt_deferred, tvb, offset + 12, 4, iOptionsFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_spi_opt_syncp, tvb, offset + 12, 4, iOptionsFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_spi_opt_blank, tvb, offset + 12, 4, iOptionsFlags);
}
proto_tree_add_item(mq_tree, hf_mq_spi_spgo_size, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
}
iSizePayload = tvb_get_guint32_endian(tvb, offset + 16, p_mq_parm->mq_int_enc);
offset += 20;
bPayload = TRUE;
}
else
{
offset += 12;
}
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
}
}
else if ((p_mq_parm->mq_opcode >= 0xA0 && p_mq_parm->mq_opcode <= 0xB9) && tvb_length_remaining(tvb, offset) >= 16)
{
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 16, "%s (%s)", MQ_TEXT_XA,
val_to_str(p_mq_parm->mq_opcode, mq_opcode_vals, "Unknown (0x%02x)"));
mq_tree = proto_item_add_subtree(ti, ett_mq_xa);
proto_tree_add_item(mq_tree, hf_mq_xa_length, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mq_tree, hf_mq_xa_returnvalue, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
{
proto_tree *mq_tree_sub = NULL;
guint32 iTMFlags;
ti = proto_tree_add_item(mq_tree, hf_mq_xa_tmflags, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
mq_tree_sub = proto_item_add_subtree(ti, ett_mq_xa_tmflags);
iTMFlags = tvb_get_guint32_endian(tvb, offset + 8, p_mq_parm->mq_int_enc);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_onephase, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_fail, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_resume, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_success, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_suspend, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_startrscan, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_endrscan, tvb, offset + 8, 4, iTMFlags);
proto_tree_add_boolean(mq_tree_sub, hf_mq_xa_tmflags_join, tvb, offset + 8, 4, iTMFlags);
}
proto_tree_add_item(mq_tree, hf_mq_xa_rmid, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
}
offset += 16;
if (p_mq_parm->mq_opcode == MQ_TST_XA_START || p_mq_parm->mq_opcode == MQ_TST_XA_END || p_mq_parm->mq_opcode == MQ_TST_XA_PREPARE
|| p_mq_parm->mq_opcode == MQ_TST_XA_COMMIT || p_mq_parm->mq_opcode == MQ_TST_XA_ROLLBACK || p_mq_parm->mq_opcode == MQ_TST_XA_FORGET
|| p_mq_parm->mq_opcode == MQ_TST_XA_COMPLETE)
{
gint iSizeXid = 0;
if ((iSizeXid = dissect_mq_xid(tvb, mqroot_tree, p_mq_parm, offset)) != 0)
offset += iSizeXid;
}
else if ((p_mq_parm->mq_opcode == MQ_TST_XA_OPEN || p_mq_parm->mq_opcode == MQ_TST_XA_CLOSE)
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
proto_tree_add_item(mq_tree, hf_mq_xa_xainfo_value, tvb, offset + 1, iXAInfoLength, p_mq_parm->mq_str_enc);
}
}
offset += 1 + iXAInfoLength;
}
else if ((p_mq_parm->mq_opcode == MQ_TST_XA_RECOVER || p_mq_parm->mq_opcode == MQ_TST_XA_RECOVER_REPLY)
&& tvb_length_remaining(tvb, offset) >= 4)
{
gint iNbXid = 0;
iNbXid = tvb_get_guint32_endian(tvb, offset, p_mq_parm->mq_int_enc);
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_xa_count, tvb, offset, 4, p_mq_parm->mq_int_enc);
}
offset += 4;
if (p_mq_parm->mq_opcode == MQ_TST_XA_RECOVER_REPLY)
{
gint iXid = 0;
for (iXid = 0; iXid < iNbXid; iXid++)
{
gint iSizeXid = 0;
if ((iSizeXid = dissect_mq_xid(tvb, mqroot_tree, p_mq_parm, offset)) != 0)
offset += iSizeXid;
else
break;
}
}
}
}
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_LPOO || p_mq_parm->mq_strucID == MQ_STRUCTID_LPOO_EBCDIC) && tvb_length_remaining(tvb, offset) >= 32)
{
guint iVersionID = 0;
gint iSizeID = 32;
iVersionID = tvb_get_guint32_endian(tvb, offset+4, p_mq_parm->mq_int_enc);
if (iSizeID != 0 && tvb_length_remaining(tvb, offset) >= iSizeID)
{
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeID, MQ_TEXT_LPOO);
mq_tree = proto_item_add_subtree(ti, ett_mq_lpoo);
proto_tree_add_item(mq_tree, hf_mq_lpoo_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_lpoo_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
dissect_mq_MQOO(tvb, mq_tree, offset+8, ett_mq_lpoo_option, p_mq_parm);
proto_tree_add_item(mq_tree, hf_mq_lpoo_unknown1, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_lpoo_unknown2, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_lpoo_unknown3, tvb, offset + 20, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_lpoo_unknown4, tvb, offset + 24, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_lpoo_unknown5, tvb, offset + 28, 4, p_mq_parm->mq_int_enc);
if (iVersionID>3)
{
proto_tree_add_item(mq_tree, hf_mq_lpoo_qprotect, tvb, offset + 32, 48, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_lpoo_unknown6, tvb, offset + 80, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_lpoo_unknown7, tvb, offset + 84, 4, p_mq_parm->mq_int_enc);
}
}
offset += iSizeID;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
}
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_ID || p_mq_parm->mq_strucID == MQ_STRUCTID_ID_EBCDIC) && tvb_length_remaining(tvb, offset) >= 5)
{
offset += dissect_mq_id(tvb, pinfo, mqroot_tree, offset, p_mq_parm);
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_UID || p_mq_parm->mq_strucID == MQ_STRUCTID_UID_EBCDIC) && tvb_length_remaining(tvb, offset) > 0)
{
gint iSizeUID = 0;
iSizeUID = iSegmentLength - iSizeTSH;
if (iSizeUID != 28 && iSizeUID != 132) iSizeUID = 0;
if (iSizeUID != 0 && tvb_length_remaining(tvb, offset) >= iSizeUID)
{
guint8 *sUserId;
sUserId = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 4, 12, p_mq_parm->mq_str_enc);
if (strip_trailing_blanks(sUserId, 12) != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ": User=%s", sUserId);
}
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeUID, MQ_TEXT_UID);
mq_tree = proto_item_add_subtree(ti, ett_mq_uid);
proto_tree_add_item(mq_tree, hf_mq_uid_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_uid_userid, tvb, offset + 4, 12, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_uid_password, tvb, offset + 16, 12, p_mq_parm->mq_str_enc);
}
if (iSizeUID == 132)
{
if (tree)
{
proto_tree_add_item(mq_tree, hf_mq_uid_longuserid, tvb, offset + 28, 64, p_mq_parm->mq_str_enc);
dissect_mq_sid(tvb, mq_tree, p_mq_parm, offset + 92);
}
}
}
offset += iSizeUID;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
offset += dissect_mq_od(tvb, pinfo, mqroot_tree, offset, p_mq_parm, &iDistributionListSize);
if ((iSizeMD = dissect_mq_md(tvb, mqroot_tree, offset, &tMsgProps, p_mq_parm, TRUE)) != 0)
{
gint iSizeGMO = 0;
gint iSizePMO = 0;
offset += iSizeMD;
if ((iSizeGMO = dissect_mq_gmo(tvb, pinfo, mqroot_tree, offset, p_mq_parm)) != 0)
{
offset += iSizeGMO;
bPayload = TRUE;
}
else if ((iSizePMO = dissect_mq_pmo(tvb, pinfo, mqroot_tree, offset, p_mq_parm, &iDistributionListSize)) != 0)
{
offset += iSizePMO;
bPayload = TRUE;
}
if (tvb_length_remaining(tvb, offset) >= 4)
{
if (bPayload == TRUE && (p_mq_parm->mq_opcode != MQ_TST_ASYNC_MESSAGE))
{
iSizePayload = tvb_get_guint32_endian(tvb, offset, p_mq_parm->mq_int_enc);
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, 4, MQ_TEXT_PUT);
mq_tree = proto_item_add_subtree(ti, ett_mq_put);
proto_tree_add_item(mq_tree, hf_mq_put_length, tvb, offset, 4, p_mq_parm->mq_int_enc);
}
offset += 4;
}
}
}
if (iDistributionListSize > 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " (Distribution List, Size=%d)", iDistributionListSize);
}
if (bPayload == TRUE)
{
if (iSizePayload != 0 && tvb_length_remaining(tvb, offset) > 0)
{
guint32 iHeadersLength = 0;
if (tvb_length_remaining(tvb, offset) >= 4)
{
gint iSizeMD2 = 0;
p_mq_parm->mq_strucID = tvb_get_ntohl(tvb, offset);
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_XQH || p_mq_parm->mq_strucID == MQ_STRUCTID_XQH_EBCDIC) && tvb_length_remaining(tvb, offset) >= 104)
{
gint iSizeXQH = 104;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeXQH, MQ_TEXT_XQH);
mq_tree = proto_item_add_subtree(ti, ett_mq_xqh);
proto_tree_add_item(mq_tree, hf_mq_xqh_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_xqh_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_xqh_remoteq, tvb, offset + 8, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_xqh_remoteqmgr, tvb, offset + 56, 48, p_mq_parm->mq_str_enc);
}
offset += iSizeXQH;
iHeadersLength += iSizeXQH;
if ((iSizeMD2 = dissect_mq_md(tvb, mqroot_tree, offset, &tMsgProps, p_mq_parm, TRUE)) != 0)
{
offset += iSizeMD2;
iHeadersLength += iSizeMD2;
}
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_DH || p_mq_parm->mq_strucID == MQ_STRUCTID_DH_EBCDIC) && tvb_length_remaining(tvb, offset) >= 48)
{
gint iSizeDH = 48;
gint iNbrRecords = 0;
guint32 iRecFlags = 0;
iNbrRecords = tvb_get_guint32_endian(tvb, offset + 36, p_mq_parm->mq_int_enc);
iRecFlags = tvb_get_guint32_endian(tvb, offset + 32, p_mq_parm->mq_int_enc);
tMsgProps.iOffsetEncoding = offset + 12;
tMsgProps.iOffsetCcsid = offset + 16;
tMsgProps.iOffsetFormat = offset + 20;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeDH, MQ_TEXT_DH);
mq_tree = proto_item_add_subtree(ti, ett_mq_dh);
proto_tree_add_item(mq_tree, hf_mq_head_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_head_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_length, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_encoding, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_ccsid, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_format, tvb, offset + 20, 8, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_head_flags, tvb, offset + 28, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_dh_putmsgrecfld, tvb, offset + 32, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_dh_recspresent, tvb, offset + 36, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_dh_objrecofs , tvb, offset + 40, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_dh_putmsgrecofs, tvb, offset + 44, 4, p_mq_parm->mq_int_enc);
}
offset += iSizeDH;
iHeadersLength += iSizeDH;
if (iNbrRecords > 0)
{
gint iOffsetOR = 0;
gint iOffsetPMR = 0;
gint iSizeORPMR = 0;
iOffsetOR = tvb_get_guint32_endian(tvb, offset - iSizeDH + 40, p_mq_parm->mq_int_enc);
iOffsetPMR = tvb_get_guint32_endian(tvb, offset - iSizeDH + 44, p_mq_parm->mq_int_enc);
if ((iSizeORPMR = dissect_mq_or(tvb, mqroot_tree, offset, iNbrRecords, iOffsetOR, p_mq_parm)) != 0)
{
offset += iSizeORPMR;
iHeadersLength += iSizeORPMR;
}
if ((iSizeORPMR = dissect_mq_pmr(tvb, mqroot_tree, offset, iNbrRecords, iOffsetPMR, iRecFlags, p_mq_parm)) != 0)
{
offset += iSizeORPMR;
iHeadersLength += iSizeORPMR;
}
}
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_DLH || p_mq_parm->mq_strucID == MQ_STRUCTID_DLH_EBCDIC) && tvb_length_remaining(tvb, offset) >= 172)
{
gint iSizeDLH = 172;
tMsgProps.iOffsetEncoding = offset + 108;
tMsgProps.iOffsetCcsid = offset + 112;
tMsgProps.iOffsetFormat = offset + 116;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeDLH, MQ_TEXT_DLH);
mq_tree = proto_item_add_subtree(ti, ett_mq_dlh);
proto_tree_add_item(mq_tree, hf_mq_dlh_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_reason, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_destq, tvb, offset + 12, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_destqmgr, tvb, offset + 60, 48, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_encoding, tvb, offset + 108, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_ccsid, tvb, offset + 112, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_format, tvb, offset + 116, 8, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_putappltype, tvb, offset + 124, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_putapplname, tvb, offset + 128, 28, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_putdate, tvb, offset + 156, 8, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_dlh_puttime, tvb, offset + 164, 8, p_mq_parm->mq_str_enc);
}
offset += iSizeDLH;
iHeadersLength += iSizeDLH;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_MDE || p_mq_parm->mq_strucID == MQ_STRUCTID_MDE_EBCDIC) && tvb_length_remaining(tvb, offset) >= 72)
{
gint iSizeMDE = 72;
tMsgProps.iOffsetEncoding = offset + 12;
tMsgProps.iOffsetCcsid = offset + 16;
tMsgProps.iOffsetFormat = offset + 20;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeMDE, MQ_TEXT_MDE);
mq_tree = proto_item_add_subtree(ti, ett_mq_mde);
proto_tree_add_item(mq_tree, hf_mq_head_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_head_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_length, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_encoding, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_ccsid, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_format, tvb, offset + 20, 8, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_head_flags, tvb, offset + 28, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_groupid, tvb, offset + 32, 24, ENC_NA);
proto_tree_add_item(mq_tree, hf_mq_md_msgseqnumber, tvb, offset + 56, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_offset, tvb, offset + 60, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_msgflags, tvb, offset + 64, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_md_origlen, tvb, offset + 68, 4, p_mq_parm->mq_int_enc);
}
offset += iSizeMDE;
iHeadersLength += iSizeMDE;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
if ((p_mq_parm->mq_strucID == MQ_STRUCTID_CIH || p_mq_parm->mq_strucID == MQ_STRUCTID_CIH_EBCDIC
|| p_mq_parm->mq_strucID == MQ_STRUCTID_IIH || p_mq_parm->mq_strucID == MQ_STRUCTID_IIH_EBCDIC
|| p_mq_parm->mq_strucID == MQ_STRUCTID_RFH || p_mq_parm->mq_strucID == MQ_STRUCTID_RFH_EBCDIC
|| p_mq_parm->mq_strucID == MQ_STRUCTID_RMH || p_mq_parm->mq_strucID == MQ_STRUCTID_RMH_EBCDIC
|| p_mq_parm->mq_strucID == MQ_STRUCTID_WIH || p_mq_parm->mq_strucID == MQ_STRUCTID_WIH_EBCDIC)
&& tvb_length_remaining(tvb, offset) >= 12)
{
gint iSizeHeader = 0;
iSizeHeader = (gint) tvb_get_guint32_endian(tvb, offset + 8, p_mq_parm->mq_int_enc);
if (iSizeHeader <= 32)
THROW(ReportedBoundsError);
if (tvb_length_remaining(tvb, offset) >= iSizeHeader)
{
tMsgProps.iOffsetEncoding = offset + 12;
tMsgProps.iOffsetCcsid = offset + 16;
tMsgProps.iOffsetFormat = offset + 20;
if (tree)
{
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeHeader, "%s", val_to_str(p_mq_parm->mq_strucID, mq_structid_vals, "Unknown (0x%08x)"));
mq_tree = proto_item_add_subtree(ti, ett_mq_head);
proto_tree_add_item(mq_tree, hf_mq_head_structid, tvb, offset, 4, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_head_version, tvb, offset + 4, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_length, tvb, offset + 8, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_encoding, tvb, offset + 12, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_ccsid, tvb, offset + 16, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_format, tvb, offset + 20, 8, p_mq_parm->mq_str_enc);
proto_tree_add_item(mq_tree, hf_mq_head_flags, tvb, offset + 28, 4, p_mq_parm->mq_int_enc);
proto_tree_add_item(mq_tree, hf_mq_head_struct, tvb, offset + 32, iSizeHeader - 32, ENC_NA);
}
offset += iSizeHeader;
iHeadersLength += iSizeHeader;
p_mq_parm->mq_strucID = (tvb_length_remaining(tvb, offset) >= 4) ? tvb_get_ntohl(tvb, offset) : MQ_STRUCTID_NULL;
}
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%d bytes)", iSizePayload - iHeadersLength);
if (!mq_in_reassembly)
{
tvbuff_t* next_tvb = NULL;
void* pd_save;
struct mqinfo *mqinfo;
mqinfo = wmem_new0(wmem_packet_scope(), struct mqinfo);
mqinfo->encoding = tvb_get_guint32_endian(tvb, tMsgProps.iOffsetEncoding, p_mq_parm->mq_int_enc);
mqinfo->ccsid = tvb_get_guint32_endian(tvb, tMsgProps.iOffsetCcsid, p_mq_parm->mq_int_enc);
memcpy(mqinfo->format,
tvb_get_string_enc(wmem_packet_scope(), tvb, tMsgProps.iOffsetFormat, sizeof(mqinfo->format), p_mq_parm->mq_str_enc),
sizeof(mqinfo->format));
pd_save = pinfo->private_data;
pinfo->private_data = mqinfo;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_heuristic(mq_heur_subdissector_list, next_tvb, pinfo, mqroot_tree, NULL))
call_dissector(data_handle, next_tvb, pinfo, mqroot_tree);
pinfo->private_data = pd_save;
}
else
{
tvbuff_t* next_tvb = NULL;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, mqroot_tree);
}
}
offset = tvb_length(tvb);
}
if (tvb_length_remaining(tvb, offset) >= 4)
{
p_mq_parm->mq_strucID = tvb_get_ntohl(tvb, offset);
if (tree)
{
proto_tree_add_text(mqroot_tree, tvb, offset, -1, "%s", val_to_str(p_mq_parm->mq_strucID, mq_structid_vals, "Unknown (0x%08x)"));
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
static void reassemble_mq(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tvb_length(tvb) >= 28)
{
mq_parm_t mq_parm;
mq_parm.mq_strucID = tvb_get_ntohl(tvb, 0);
mq_parm.mq_ccsid = 0;
mq_parm.mq_ctlf = 0;
mq_parm.mq_encode = 0;
mq_parm.mq_opcode = 0;
mq_parm.mq_int_enc = 0;
mq_parm.mq_str_enc = 0;
if (mq_parm.mq_strucID == MQ_STRUCTID_TSH || mq_parm.mq_strucID == MQ_STRUCTID_TSH_EBCDIC
|| mq_parm.mq_strucID == MQ_STRUCTID_TSHC || mq_parm.mq_strucID == MQ_STRUCTID_TSHC_EBCDIC
|| mq_parm.mq_strucID == MQ_STRUCTID_TSHM || mq_parm.mq_strucID == MQ_STRUCTID_TSHM_EBCDIC)
{
guint8 iCtlF = 0;
gint32 iSegL = 0;
gint32 iBegL = 0;
gint32 iEnco = 0;
gint32 iMulS = 0;
gint32 iHdrL = 0;
gint32 iNxtP = 0;
guint8 iOpcd = 0;
gboolean bSeg1st = FALSE;
gboolean bSegLst = FALSE;
gboolean bMore = FALSE;
guint32 uHdl = 0;
guint32 uCurS = 0;
guint32 uPayL = 0;
guint16 uMsgS = 0;
guint32 uStrL = 0;
guint32 uPadL = 0;
if (mq_parm.mq_strucID == MQ_STRUCTID_TSHM || mq_parm.mq_strucID == MQ_STRUCTID_TSHM_EBCDIC)
iMulS=8;
iEnco = (tvb_get_guint8(tvb, 8+iMulS) == MQ_LITTLE_ENDIAN ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
iOpcd = tvb_get_guint8(tvb, 9+iMulS);
iCtlF = tvb_get_guint8(tvb, 10+iMulS);
iSegL = tvb_get_ntohl (tvb, 4);
bSeg1st = ((iCtlF & MQ_TCF_FIRST) != 0);
bSegLst = ((iCtlF & MQ_TCF_LAST) != 0);
mq_in_reassembly=FALSE;
if ((iOpcd > 0x80 && !(bSeg1st && bSegLst)) || iOpcd==MQ_TST_ASYNC_MESSAGE)
{
proto_tree* mq_tree = NULL;
if (mq_reassembly)
{
fragment_head* fd_head;
guint32 iConnectionId = (pinfo->srcport + pinfo->destport);
iHdrL=28+iMulS;
uHdl = tvb_get_guint32_endian(tvb, iHdrL + 4, iEnco);
uCurS= tvb_get_guint32_endian(tvb, iHdrL +12, iEnco);
uMsgS= tvb_get_guint16_endian(tvb, iHdrL +20, iEnco);
if (bSeg1st)
{
uStrL = tvb_get_guint8(tvb,iHdrL+54);
uPadL = ((((2+1+uStrL)/4)+1)*4)-(2+1+uStrL);
}
bMore=!bSegLst;
iNxtP = iHdrL + ((bSeg1st)?(54 + 1 + uStrL + uPadL):(24));
iNxtP += dissect_mq_md(tvb, NULL, iNxtP, NULL, &mq_parm, FALSE);
uPayL = tvb_length_remaining(tvb, iNxtP);
iBegL = (bSeg1st)?0:iNxtP;
fd_head = fragment_add_seq_next(&mq_reassembly_table,
tvb, iBegL,
pinfo, iConnectionId, NULL,
iSegL - iBegL, bMore);
if (tree)
{
proto_item* ti = proto_tree_add_item(tree, proto_mq, tvb, 0, -1, ENC_NA);
if (bMore)
proto_item_append_text(ti, " [%s of a Reassembled MQ Segment] Hdl=0x%08x, CurS=%d, MsgS=%d, PayL=%d",
val_to_str(iOpcd, mq_opcode_vals, "Unknown (0x%02x)"),uHdl,uCurS,uMsgS,uPayL);
else
proto_item_append_text(ti, " %s Hdl=0x%08x, CurS=%d, MsgS=%d, PayL=%d",
val_to_str(iOpcd, mq_opcode_vals, "Unknown (0x%02x)"),uHdl,uCurS,uMsgS,uPayL);
mq_tree = proto_item_add_subtree(ti, ett_mq_reaasemb);
}
else
{
mq_tree=tree;
}
if (fd_head != NULL && pinfo->fd->num == fd_head->reassembled_in)
{
tvbuff_t* next_tvb;
if (fd_head->next != NULL)
{
next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, next_tvb, "Reassembled MQ");
}
else
{
next_tvb = tvb;
}
dissect_mq_pdu(next_tvb, pinfo, mq_tree);
return;
}
else
{
mq_in_reassembly=TRUE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MQ");
col_add_fstr(pinfo->cinfo, COL_INFO, "[%s of a Reassembled MQ Segment] Hdl=0x%08x, CurS=%d, MsgS=%d, PayL=%d",
val_to_str(iOpcd, mq_opcode_vals, "Unknown (0x%02x)"),uHdl,uCurS,uMsgS,uPayL);
dissect_mq_pdu(tvb, pinfo, mq_tree);
return;
}
}
else
{
dissect_mq_pdu(tvb, pinfo, mq_tree);
if (bSeg1st)
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
static guint get_mq_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
if (tvb_length_remaining(tvb, offset) >= 8)
{
guint32 mq_strucID = tvb_get_ntohl(tvb, 0);
if ( (mq_strucID & MQ_MASK_TSHx) == MQ_STRUCTID_TSHx || (mq_strucID & MQ_MASK_TSHx) == MQ_STRUCTID_TSHx_EBCDIC )
{
return tvb_get_ntohl(tvb, offset + 4);
}
}
return 0;
}
static void dissect_mq_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, mq_desegment, 28, get_mq_pdu_len, reassemble_mq);
}
static void dissect_mq_spx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_mq_pdu(tvb, pinfo, tree);
}
static gboolean dissect_mq_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint iProto, void *data _U_)
{
if (tvb_length(tvb) >= 28)
{
guint32 mq_strucID = tvb_get_ntohl(tvb, 0);
if ( (mq_strucID & MQ_MASK_TSHx) == MQ_STRUCTID_TSHx || (mq_strucID & MQ_MASK_TSHx) == MQ_STRUCTID_TSHx_EBCDIC )
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
static gboolean dissect_mq_heur_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_mq_heur(tvb, pinfo, tree, MQ_XPT_TCP, NULL);
}
static gboolean dissect_mq_heur_netbios(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_mq_heur(tvb, pinfo, tree, MQ_XPT_NETBIOS, NULL);
}
static gboolean dissect_mq_heur_http(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_mq_heur(tvb, pinfo, tree, MQ_XPT_HTTP, NULL);
}
static void mq_init(void)
{
reassembly_table_init(&mq_reassembly_table,
&addresses_reassembly_table_functions);
}
void proto_register_mq(void)
{
static hf_register_info hf[] = {
{ &hf_mq_tsh_structid ,{"structid..", "mq.tsh.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_tsh_mqseglen ,{"MQSegmLen.", "mq.tsh.seglength", FT_UINT32, BASE_DEC, NULL, 0x0, "TSH MQ Segment length", HFILL }},
{ &hf_mq_tsh_convid ,{"Convers ID", "mq.tsh.convid", FT_UINT32, BASE_DEC, NULL, 0x0, "TSH Conversation ID", HFILL }},
{ &hf_mq_tsh_requestid,{"Request ID", "mq.tsh.requestid", FT_UINT32, BASE_DEC, NULL, 0x0, "TSH Request ID", HFILL }},
{ &hf_mq_tsh_byteorder,{"Byte order", "mq.tsh.byteorder", FT_UINT8, BASE_HEX, VALS(GET_VALSV(byteorder)), 0x0, "TSH Byte order", HFILL }},
{ &hf_mq_tsh_opcode ,{"SegmType..", "mq.tsh.type", FT_UINT8, BASE_HEX, VALS(GET_VALSV(opcode)), 0x0, "TSH MQ segment type", HFILL }},
{ &hf_mq_tsh_ctlflgs1 ,{"Ctl Flag 1", "mq.tsh.cflags1", FT_UINT8, BASE_HEX, NULL, 0x0, "TSH Control flags 1", HFILL }},
{ &hf_mq_tsh_ctlflgs2 ,{"Ctl Flag 2", "mq.tsh.cflags2", FT_UINT8, BASE_HEX, NULL, 0x0, "TSH Control flags 2", HFILL }},
{ &hf_mq_tsh_luwid ,{"LUW Ident.", "mq.tsh.luwid", FT_BYTES, BASE_NONE, NULL, 0x0, "TSH logical unit of work identifier", HFILL }},
{ &hf_mq_tsh_encoding ,{"Encoding..", "mq.tsh.encoding", FT_UINT32, BASE_DEC, NULL, 0x0, "TSH Encoding", HFILL }},
{ &hf_mq_tsh_ccsid ,{"CCSID.....", "mq.tsh.ccsid", FT_UINT16, BASE_DEC, NULL, 0x0, "TSH CCSID", HFILL }},
{ &hf_mq_tsh_padding ,{"Padding...", "mq.tsh.padding", FT_UINT16, BASE_HEX, NULL, 0x0, "TSH Padding", HFILL }},
{ &hf_mq_tsh_tcf_confirmreq,{"Confirm Req", "mq.tsh.tcf.confirmreq", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_CONFIRM_REQUEST, "TSH TCF Confirm request", HFILL }},
{ &hf_mq_tsh_tcf_error ,{"Error......", "mq.tsh.tcf.error", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_ERROR, "TSH TCF Error", HFILL }},
{ &hf_mq_tsh_tcf_reqclose ,{"Req close..", "mq.tsh.tcf.reqclose", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_REQUEST_CLOSE, "TSH TCF Request close", HFILL }},
{ &hf_mq_tsh_tcf_closechann,{"Close Chnl.", "mq.tsh.tcf.closechann", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_CLOSE_CHANNEL, "TSH TCF Close channel", HFILL }},
{ &hf_mq_tsh_tcf_first ,{"First Seg..", "mq.tsh.tcf.first", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_FIRST, "TSH TCF First", HFILL }},
{ &hf_mq_tsh_tcf_last ,{"Last Seg...", "mq.tsh.tcf.last", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_LAST, "TSH TCF Last", HFILL }},
{ &hf_mq_tsh_tcf_reqacc ,{"Req accept.", "mq.tsh.tcf.reqacc", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_REQUEST_ACCEPTED, "TSH TCF Request accepted", HFILL }},
{ &hf_mq_tsh_tcf_dlq ,{"DLQ used...", "mq.tsh.tcf.dlq", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_TCF_DLQ_USED, "TSH TCF DLQ used", HFILL }},
{ &hf_mq_api_replylen ,{"Reply len..", "mq.api.replylength", FT_UINT32, BASE_DEC, NULL, 0x0, "API Reply length", HFILL }},
{ &hf_mq_api_compcode ,{"Compl Code.", "mq.api.completioncode", FT_UINT32, BASE_DEC, VALS(GET_VALSV(mqcc)), 0x0, "API Completion code", HFILL }},
{ &hf_mq_api_reascode ,{"Reason Code", "mq.api.reasoncode", FT_UINT32, BASE_DEC, VALS(GET_VALSV(mqrc)), 0x0, "API Reason code", HFILL }},
{ &hf_mq_api_objecthdl,{"Object Hdl.", "mq.api.hobj", FT_UINT32, BASE_HEX, NULL, 0x0, "API Object handle", HFILL }},
{ &hf_mq_socket_unknown1,{"unknown1", "mq.socket.unknown1", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "Socket unknown1", HFILL }},
{ &hf_mq_socket_unknown2,{"unknown2", "mq.socket.unknown2", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "Socket unknown2", HFILL }},
{ &hf_mq_socket_unknown3,{"unknown3", "mq.socket.unknown3", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "Socket unknown3", HFILL }},
{ &hf_mq_socket_unknown4,{"unknown4", "mq.socket.unknown4", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "Socket unknown4", HFILL }},
{ &hf_mq_socket_unknown5,{"unknown5", "mq.socket.unknown5", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "Socket unknown5", HFILL }},
{ &hf_mq_caut_structid ,{"structid", "mq.caut.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_caut_unknown1 ,{"unknown1", "mq.caut.unknown1", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "CAUT unknown1", HFILL }},
{ &hf_mq_caut_userlen1 ,{"userlen1", "mq.caut.userlen1", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "CAUT userid length 1", HFILL }},
{ &hf_mq_caut_pswdlen1 ,{"pswdlen1", "mq.caut.pswdlen1", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "CAUT password length 1", HFILL }},
{ &hf_mq_caut_userlen2 ,{"userlen2", "mq.caut.userlen2", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "CAUT userid length 2", HFILL }},
{ &hf_mq_caut_pswdlen2 ,{"pswdlen2", "mq.caut.pswdlen2", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "CAUT password length 5", HFILL }},
{ &hf_mq_caut_usr ,{"userid..", "mq.msh.userid" , FT_STRINGZ, BASE_NONE, NULL, 0x0, "CAUT UserId", HFILL }},
{ &hf_mq_caut_psw ,{"password", "mq.msh.password" , FT_STRINGZ, BASE_NONE, NULL, 0x0, "CAUT PAssword", HFILL }},
{ &hf_mq_id_icf_msgseq ,{"Message sequence..", "mq.id.icf.msgseq", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_MSG_SEQ, "ID ICF Message sequence", HFILL }},
{ &hf_mq_id_icf_convcap ,{"Conversion capable", "mq.id.icf.convcap", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_CONVERSION_CAPABLE, "ID ICF Conversion capable", HFILL }},
{ &hf_mq_id_icf_splitmsg,{"Split messages....", "mq.id.icf.splitmsg", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_SPLIT_MESSAGE, "ID ICF Split message", HFILL }},
{ &hf_mq_id_icf_mqreq ,{"MQ request........", "mq.id.icf.mqreq", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_MQREQUEST, "ID ICF MQ request", HFILL }},
{ &hf_mq_id_icf_svrsec ,{"Srvr Con security.", "mq.id.icf.svrsec", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_SVRCONN_SECURITY, "ID ICF Server connection security", HFILL }},
{ &hf_mq_id_icf_runtime ,{"Runtime applic....", "mq.id.icf.runtime", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_ICF_RUNTIME, "ID ICF Runtime application", HFILL }},
{ &hf_mq_msh_structid ,{"structid", "mq.msh.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_msh_seqnum ,{"Seq Numb", "mq.msh.seqnum", FT_UINT32, BASE_DEC, NULL, 0x0, "MSH sequence number", HFILL }},
{ &hf_mq_msh_datalength,{"Buf len.", "mq.msh.buflength", FT_UINT32, BASE_DEC, NULL, 0x0, "MSH buffer length", HFILL }},
{ &hf_mq_msh_unknown1 ,{"Unknown1", "mq.msh.unknown1", FT_UINT32, BASE_HEX, NULL, 0x0, "MSH unknown1", HFILL }},
{ &hf_mq_msh_msglength ,{"Msg len.", "mq.msh.msglength", FT_UINT32, BASE_DEC, NULL, 0x0, "MSH message length", HFILL }},
{ &hf_mq_xqh_structid ,{"structid", "mq.xqh.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_xqh_version ,{"Version.", "mq.xqh.version", FT_UINT32, BASE_DEC, NULL, 0x0, "XQH version", HFILL }},
{ &hf_mq_xqh_remoteq ,{"Remote Q", "mq.xqh.remoteq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "XQH remote queue", HFILL }},
{ &hf_mq_xqh_remoteqmgr,{"Rmt QMgr", "mq.xqh.remoteqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "XQH remote queue manager", HFILL }},
{ &hf_mq_id_structid ,{"Structid..", "mq.id.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_id_level ,{"FAP level.", "mq.id.level", FT_UINT8, BASE_DEC, NULL, 0x0, "ID Formats And Protocols level", HFILL }},
{ &hf_mq_id_flags ,{"Flags.....", "mq.id.flags", FT_UINT8, BASE_HEX, NULL, 0x0, "ID flags", HFILL }},
{ &hf_mq_id_unknown02 ,{"Unknown02.", "mq.id.unknown02", FT_UINT8, BASE_HEX, NULL, 0x0, "ID unknown02", HFILL }},
{ &hf_mq_id_ieflags ,{"InitErrFlg", "mq.id.ief", FT_UINT8, BASE_HEX, NULL, 0x0, "ID initial error flags", HFILL }},
{ &hf_mq_id_unknown04 ,{"Unknown04.", "mq.id.unknown04", FT_UINT16, BASE_HEX, NULL, 0x0, "ID unknown04", HFILL }},
{ &hf_mq_id_MaxMsgBatch,{"MaxMsgBtch", "mq.id.MaxMsgBatch", FT_UINT16, BASE_DEC, NULL, 0x0, "ID max msg per batch", HFILL }},
{ &hf_mq_id_MaxTrSize ,{"MaxTrSize.", "mq.id.MaxTrSize", FT_UINT32, BASE_DEC, NULL, 0x0, "ID max trans size", HFILL }},
{ &hf_mq_id_maxmsgsize ,{"MaxMsgSize", "mq.id.maxmsgsize", FT_UINT32, BASE_DEC, NULL, 0x0, "ID max msg size", HFILL }},
{ &hf_mq_id_SeqWrapVal ,{"SeqWrapVal", "mq.id.seqwrap", FT_UINT32, BASE_DEC, NULL, 0x0, "ID seq wrap value", HFILL }},
{ &hf_mq_id_channel ,{"ChannelNme", "mq.id.channelname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "ID channel name", HFILL }},
{ &hf_mq_id_capflags ,{"CapabilFlg", "mq.id.capflags", FT_UINT16, BASE_HEX, NULL, 0x0, "ID Capability flags", HFILL }},
{ &hf_mq_id_ccsid ,{"ccsid.....", "mq.id.ccsid", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, "ID character set", HFILL }},
{ &hf_mq_id_qmgrname ,{"QMgrName..", "mq.id.qm", FT_STRINGZ, BASE_NONE, NULL, 0x0, "ID Queue manager", HFILL }},
{ &hf_mq_id_HBInterval ,{"HBInterval", "mq.id.hbint", FT_UINT32, BASE_DEC, NULL, 0x0, "ID Heartbeat interval", HFILL }},
{ &hf_mq_id_unknown06 ,{"Unknown06.", "mq.id.unknown06", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, "ID Unknown06", HFILL }},
{ &hf_mq_id_unknown07 ,{"Unknown07.", "mq.id.unknown07", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, "ID Unknown07", HFILL }},
{ &hf_mq_id_unknown08 ,{"Unknown08.", "mq.id.unknown08", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, "ID Unknown08", HFILL }},
{ &hf_mq_id_unknown09 ,{"Unknown09.", "mq.id.unknown09", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, "ID Unknown09", HFILL }},
{ &hf_mq_id_unknown10 ,{"Unknown10.", "mq.id.unknown10", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown10", HFILL }},
{ &hf_mq_id_unknown11 ,{"Unknown11.", "mq.id.unknown11", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown11", HFILL }},
{ &hf_mq_id_unknown12 ,{"Unknown12.", "mq.id.unknown12", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown12", HFILL }},
{ &hf_mq_id_unknown13 ,{"Unknown13.", "mq.id.unknown13", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown13", HFILL }},
{ &hf_mq_id_unknown14 ,{"Unknown14.", "mq.id.unknown14", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown14", HFILL }},
{ &hf_mq_id_unknown15 ,{"Unknown15.", "mq.id.unknown15", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown15", HFILL }},
{ &hf_mq_id_unknown16 ,{"Unknown16.", "mq.id.unknown16", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown16", HFILL }},
{ &hf_mq_id_unknown17 ,{"Unknown17.", "mq.id.unknown17", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown17", HFILL }},
{ &hf_mq_id_unknown18 ,{"Unknown18.", "mq.id.unknown18", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown18", HFILL }},
{ &hf_mq_id_unknown19 ,{"Unknown19.", "mq.id.unknown19", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "ID Unknown19", HFILL }},
{ &hf_mq_id_mqmvers ,{"MQ Version", "mq.id.mqmvers", FT_STRINGZ, BASE_NONE, NULL, 0x0, "ID MQM Version", HFILL }},
{ &hf_mq_id_mqmid ,{"MQM ID....", "mq.id.mqmid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "ID MQM ID", HFILL }},
{ &hf_mq_id_ief_ccsid ,{"Invalid CCSID.........", "mq.id.ief.ccsid", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_CCSID, "ID invalid CCSID", HFILL }},
{ &hf_mq_id_ief_enc ,{"Invalid encoding......", "mq.id.ief.enc", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_ENCODING, "ID invalid encoding", HFILL }},
{ &hf_mq_id_ief_mxtrsz ,{"Invalid Max Trans Size", "mq.id.ief.mxtrsz", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_MAX_TRANSMISSION_SIZE, "ID invalid maximum transmission size", HFILL }},
{ &hf_mq_id_ief_fap ,{"Invalid FAP level.....", "mq.id.ief.fap", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_FAP_LEVEL, "ID invalid FAP level", HFILL }},
{ &hf_mq_id_ief_mxmsgsz,{"Invalid message size..", "mq.id.ief.mxmsgsz", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_MAX_MSG_SIZE, "ID invalid message size", HFILL }},
{ &hf_mq_id_ief_mxmsgpb,{"Invalid Max Msg batch.", "mq.id.ief.mxmsgpb", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_MAX_MSG_PER_BATCH, "ID maximum message per batch", HFILL }},
{ &hf_mq_id_ief_seqwrap,{"Invalid Seq Wrap Value", "mq.id.ief.seqwrap", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_SEQ_WRAP_VALUE, "ID invalid sequence wrap value", HFILL }},
{ &hf_mq_id_ief_hbint ,{"Invalid HB interval...", "mq.id.ief.hbint", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_IEF_HEARTBEAT_INTERVAL, "ID invalid heartbeat interval", HFILL }},
{ &hf_mq_uid_structid ,{"Structid", "mq.uid.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_uid_userid ,{"User ID.", "mq.uid.userid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "UID structid", HFILL }},
{ &hf_mq_uid_password ,{"Password", "mq.uid.password", FT_STRINGZ, BASE_NONE, NULL, 0x0, "UID password", HFILL }},
{ &hf_mq_uid_longuserid,{"Long UID", "mq.uid.longuserid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "UID long user id", HFILL }},
{ &hf_mq_sidlen ,{"SID Len.", "mq.uid.sidlen", FT_UINT8, BASE_DEC, NULL, 0x0, "Sid Len", HFILL }},
{ &hf_mq_sidtyp ,{"SIDType.", "mq.uid.sidtyp", FT_UINT8, BASE_DEC, VALS(GET_VALSV(sidtype)), 0x0, "Sid Typ", HFILL }},
{ &hf_mq_securityid ,{"SecurID.", "mq.uid.securityid", FT_BYTES, BASE_NONE, NULL, 0x0, "Security ID", HFILL }},
{ &hf_mq_conn_QMgr ,{"QMgr....", "mq.conn.qm", FT_STRINGZ, BASE_NONE, NULL, 0x0, "CONN queue manager", HFILL }},
{ &hf_mq_conn_appname ,{"ApplName", "mq.conn.appname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "CONN application name", HFILL }},
{ &hf_mq_conn_apptype ,{"ApplType", "mq.conn.apptype", FT_INT32, BASE_DEC, VALS(GET_VALSV(mqat)), 0x0, "CONN application type", HFILL }},
{ &hf_mq_conn_acttoken ,{"AccntTok", "mq.conn.acttoken", FT_BYTES, BASE_NONE, NULL, 0x0, "CONN accounting token", HFILL }},
{ &hf_mq_conn_version ,{"Version.", "mq.conn.version", FT_UINT32, BASE_DEC, VALS(mq_conn_version_vals), 0x0, "CONN version", HFILL }},
{ &hf_mq_conn_options ,{"Options.", "mq.conn.options", FT_UINT32, BASE_HEX, NULL, 0x0, "CONN options", HFILL }},
{ &hf_mq_fcno_structid ,{"StructId.", "mq.fcno.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_fcno_unknown00,{"unknown00", "mq.fcno.unknown00", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "FCNO unknown00", HFILL }},
{ &hf_mq_fcno_unknown01,{"unknown01", "mq.fcno.unknown01", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "FCNO unknown01", HFILL }},
{ &hf_mq_fcno_unknown02,{"unknown02", "mq.fcno.unknown02", FT_BYTES, BASE_NONE, NULL, 0x0, "FCNO unknown02", HFILL }},
{ &hf_mq_fcno_msgid ,{"msgid....", "mq.fcno.msgid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "FCNO Msg ID", HFILL }},
{ &hf_mq_fcno_mqmid ,{"MqmId....", "mq.fcno.mqmid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "FCNO Mqm ID", HFILL }},
{ &hf_mq_inq_nbsel ,{"Selector count..", "mq.inq.nbsel", FT_UINT32, BASE_DEC, NULL, 0x0, "INQ Selector count", HFILL }},
{ &hf_mq_inq_nbint ,{"Integer count...", "mq.inq.nbint", FT_UINT32, BASE_DEC, NULL, 0x0, "INQ Integer count", HFILL }},
{ &hf_mq_inq_charlen ,{"Character length", "mq.inq.charlen", FT_UINT32, BASE_DEC, NULL, 0x0, "INQ Character length", HFILL }},
{ &hf_mq_inq_sel ,{"Selector........", "mq.inq.sel", FT_UINT32, BASE_DEC, VALS(GET_VALSV(selector)), 0x0, "INQ Selector", HFILL }},
{ &hf_mq_inq_intvalue ,{"Integer value...", "mq.inq.intvalue", FT_UINT32, BASE_DEC, NULL, 0x0, "INQ Integer value", HFILL }},
{ &hf_mq_inq_charvalues,{"Char values.....", "mq.inq.charvalues", FT_STRINGZ, BASE_NONE, NULL, 0x0, "INQ Character values", HFILL }},
{ &hf_mq_spi_verb ,{"SPI Verb", "mq.spi.verb", FT_UINT32, BASE_DEC, VALS(GET_VALSV(spi_verbs)), 0x0, NULL, HFILL }},
{ &hf_mq_spi_version ,{"Version", "mq.spi.version", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Version", HFILL }},
{ &hf_mq_spi_length ,{"Max reply size", "mq.spi.replength", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Max reply size", HFILL }},
{ &hf_mq_spi_base_structid,{"SPI Structid", "mq.spib.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_spi_base_version ,{"Version", "mq.spib.version", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Base Version", HFILL }},
{ &hf_mq_spi_base_length ,{"Length", "mq.spib.length", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Base Length", HFILL }},
{ &hf_mq_spi_spqo_nbverb ,{"Number of verbs", "mq.spqo.nbverb", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output Number of verbs", HFILL }},
{ &hf_mq_spi_spqo_verbid ,{"Verb", "mq.spqo.verb", FT_UINT32, BASE_DEC, VALS(GET_VALSV(spi_verbs)), 0x0, "SPI Query Output VerbId", HFILL }},
{ &hf_mq_spi_spqo_maxiover,{"Max InOut Version", "mq.spqo.maxiov", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output Max InOut Version", HFILL }},
{ &hf_mq_spi_spqo_maxinver,{"Max In Version", "mq.spqo.maxiv", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output Max In Version", HFILL }},
{ &hf_mq_spi_spqo_maxouver,{"Max Out Version", "mq.spqo.maxov", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output Max Out Version", HFILL }},
{ &hf_mq_spi_spqo_flags ,{"Flags", "mq.spqo.flags", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Query Output flags", HFILL }},
{ &hf_mq_spi_spai_mode ,{"Mode", "mq.spai.mode", FT_UINT32, BASE_DEC, VALS(GET_VALSV(spi_activate)), 0x0, "SPI Activate Input mode", HFILL }},
{ &hf_mq_spi_spai_unknown1,{"Unknown1", "mq.spai.unknown1", FT_STRINGZ, BASE_NONE, NULL, 0x0, "SPI Activate Input unknown1", HFILL }},
{ &hf_mq_spi_spai_unknown2,{"Unknown2", "mq.spai.unknown2", FT_STRINGZ, BASE_NONE, NULL, 0x0, "SPI Activate Input unknown2", HFILL }},
{ &hf_mq_spi_spai_msgid ,{"Message Id", "mq.spai.msgid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "SPI Activate Input message id", HFILL }},
{ &hf_mq_spi_spgi_batchsz ,{"Batch size", "mq.spgi.batchsize", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Input batch size", HFILL }},
{ &hf_mq_spi_spgi_batchint,{"Batch interval", "mq.spgi.batchint", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Input batch interval", HFILL }},
{ &hf_mq_spi_spgi_maxmsgsz,{"Max message size", "mq.spgi.maxmsgsize", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Input max message size", HFILL }},
{ &hf_mq_spi_spgo_options ,{"Options", "mq.spgo.options", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Output options", HFILL }},
{ &hf_mq_spi_spgo_size ,{"Size", "mq.spgo.size", FT_UINT32, BASE_DEC, NULL, 0x0, "SPI Get Output size", HFILL }},
{ &hf_mq_spi_opt_blank ,{"Blank padded", "mq.spi.options.blank", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_SPI_OPTIONS_BLANK_PADDED, "SPI Options blank padded", HFILL }},
{ &hf_mq_spi_opt_syncp ,{"Syncpoint", "mq.spi.options.sync", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_SPI_OPTIONS_SYNCPOINT, "SPI Options syncpoint", HFILL }},
{ &hf_mq_spi_opt_deferred ,{"Deferred", "mq.spi.options.deferred", FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQ_SPI_OPTIONS_DEFERRED, "SPI Options deferred", HFILL }},
{ &hf_mq_put_length ,{"Data length", "mq.put.length", FT_UINT32, BASE_DEC, NULL, 0x0, "PUT Data length", HFILL }},
{ &hf_mq_close_options ,{"Options", "mq.close.options", FT_UINT32, BASE_HEX, NULL, 0x0, "CLOSE options", HFILL }},
{ &hf_mq_close_options_DELETE ,{"DELETE......", "mq.close.options.Delete", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQCO_DELETE, "CLOSE options DELETE", HFILL }},
{ &hf_mq_close_options_DELETE_PURGE,{"DELETE_PURGE", "mq.close.options.DeletePurge", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQCO_DELETE_PURGE, "CLOSE options DELETE_PURGE", HFILL }},
{ &hf_mq_close_options_KEEP_SUB ,{"KEEPSUB.....", "mq.close.options.KeepSub", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQCO_KEEP_SUB, "CLOSE options KEEP_SUB", HFILL }},
{ &hf_mq_close_options_REMOVE_SUB ,{"REMOVE_SUB..", "mq.close.options.RemoveSub", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQCO_REMOVE_SUB, "CLOSE options REMOVE_SUB", HFILL }},
{ &hf_mq_close_options_QUIESCE ,{"QUIESCE.....", "mq.close.options.Quiesce", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQCO_QUIESCE, "CLOSE options QUIESCE", HFILL }},
{ &hf_mq_open_options ,{"Options", "mq.open.options", FT_UINT32, BASE_HEX, NULL, 0x0, "OPEN options", HFILL }},
{ &hf_mq_open_options_INPUT_AS_Q_DEF ,{"INPUT_AS_Q_DEF..........", "mq.open.options.InputAsQDef", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_INPUT_AS_Q_DEF, "OPEN options INPUT_AS_Q_DEF", HFILL }},
{ &hf_mq_open_options_INPUT_SHARED ,{"INPUT_SHARED............", "mq.open.options.InputShared", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_INPUT_SHARED, "OPEN options INPUT_SHARED", HFILL }},
{ &hf_mq_open_options_INPUT_EXCLUSIVE,{"INPUT_EXCLUSIVE.........", "mq.open.options.InputExclusive", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_INPUT_EXCLUSIVE, "OPEN options INPUT_EXCLUSIVE", HFILL }},
{ &hf_mq_open_options_BROWSE ,{"BROWSE..................", "mq.open.options.Browse", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_BROWSE, "OPEN options BROWSE", HFILL }},
{ &hf_mq_open_options_OUTPUT ,{"OUTPUT..................", "mq.open.options.Output", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_OUTPUT, "OPEN options OUTPUT", HFILL }},
{ &hf_mq_open_options_INQUIRE ,{"INQUIRE.................", "mq.open.options.Inquire", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_INQUIRE, "OPEN options INQUIRE", HFILL }},
{ &hf_mq_open_options_SET ,{"SET.....................", "mq.open.options.Set", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_SET, "OPEN options SET", HFILL }},
{ &hf_mq_open_options_SAVE_ALL_CTX ,{"SAVE_ALL_CONTEXT........", "mq.open.options.SaveAllContext", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_SAVE_ALL_CONTEXT, "OPEN options SAVE_ALL_CONTEXT", HFILL }},
{ &hf_mq_open_options_PASS_IDENT_CTX ,{"PASS_IDENTITY_CONTEXT...", "mq.open.options.PassIdentityContext", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_PASS_IDENTITY_CONTEXT, "OPEN options PASS_IDENTITY_CONTEXT", HFILL }},
{ &hf_mq_open_options_PASS_ALL_CTX ,{"PASS_ALL_CONTEXT........", "mq.open.options.PassAllContext", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_PASS_ALL_CONTEXT, "OPEN options PASS_ALL_CONTEXT", HFILL }},
{ &hf_mq_open_options_SET_IDENT_CTX ,{"SET_IDENTITY_CONTEXT....", "mq.open.options.SetIdentityContext", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_SET_IDENTITY_CONTEXT, "OPEN options SET_IDENTITY_CONTEXT", HFILL }},
{ &hf_mq_open_options_SET_ALL_CONTEXT,{"SET_ALL_CONTEXT.........", "mq.open.options.SetAllContext", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_SET_ALL_CONTEXT, "OPEN options SET_ALL_CONTEXT", HFILL }},
{ &hf_mq_open_options_ALT_USER_AUTH ,{"ALTERNATE_USER_AUTHORITY", "mq.open.options.AlternateUserAuthority", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_ALTERNATE_USER_AUTHORITY, "OPEN options ALTERNATE_USER_AUTHORITY", HFILL }},
{ &hf_mq_open_options_FAIL_IF_QUIESC ,{"FAIL_IF_QUIESCING.......", "mq.open.options.FailIfQuiescing", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_FAIL_IF_QUIESCING, "OPEN options FAIL_IF_QUIESCING", HFILL }},
{ &hf_mq_open_options_BIND_ON_OPEN ,{"BIND_ON_OPEN............", "mq.open.options.BindOnOpen", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_BIND_ON_OPEN, "OPEN options BIND_ON_OPEN", HFILL }},
{ &hf_mq_open_options_BIND_NOT_FIXED ,{"BIND_NOT_FIXED..........", "mq.open.options.BindNotFixed", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_BIND_NOT_FIXED, "OPEN options BIND_NOT_FIXED", HFILL }},
{ &hf_mq_open_options_RESOLVE_NAMES ,{"RESOLVE_NAMES...........", "mq.open.options.ResolveNames", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_RESOLVE_NAMES, "OPEN options RESOLVE_NAMES", HFILL }},
{ &hf_mq_open_options_CO_OP ,{"CO_OP...................", "mq.open.options.CoOp", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_CO_OP, "OPEN options CO_OP", HFILL }},
{ &hf_mq_open_options_RESOLVE_LOCAL_Q,{"RESOLVE_LOCAL_Q.........", "mq.open.options.ResolveLocalQueueOrTopic", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_RESOLVE_LOCAL_Q, "OPEN options RESOLVE_LOCAL_Q", HFILL }},
{ &hf_mq_open_options_NO_READ_AHEAD ,{"NO_READ_AHEAD...........", "mq.open.options.NoReadAhead", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_NO_READ_AHEAD, "OPEN options NO_READ_AHEAD", HFILL }},
{ &hf_mq_open_options_READ_AHEAD ,{"READ_AHEAD..............", "mq.open.options.ReadAhead", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_READ_AHEAD, "OPEN options READ_AHEAD", HFILL }},
{ &hf_mq_open_options_NO_MULTICAST ,{"NO_MULTICAST............", "mq.open.options.NoMulticast", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_NO_MULTICAST, "OPEN options NO_MULTICAST", HFILL }},
{ &hf_mq_open_options_BIND_ON_GROUP ,{"BIND_ON_GROUP...........", "mq.open.options.BindOnGroup", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQOO_BIND_ON_GROUP, "OPEN options BIND_ON_GROUP", HFILL }},
{ &hf_mq_fopa_structid,{"StructId", "mq.fopa.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_fopa_version ,{"Version.", "mq.fopa.version", FT_UINT32, BASE_DEC, NULL, 0x0, "FOPA Version", HFILL }},
{ &hf_mq_fopa_length ,{"Length..", "mq.fopa.length", FT_UINT32, BASE_DEC, NULL, 0x0, "FOPA Length", HFILL }},
{ &hf_mq_fopa_unknown1,{"Unknown1", "mq.fopa.unknown1", FT_UINT32, BASE_HEX, NULL, 0x0, "FOPA unknown1", HFILL }},
{ &hf_mq_fopa_unknown2,{"Unknown2", "mq.fopa.unknown2", FT_UINT32, BASE_HEX, NULL, 0x0, "FOPA unknown2", HFILL }},
{ &hf_mq_fopa_unknown3,{"Unknown3", "mq.fopa.unknown3", FT_STRINGZ, BASE_NONE, NULL, 0x0, "FOPA unknown3", HFILL }},
{ &hf_mq_fopa_qprotect,{"qprotect", "mq.fopa.qprotect", FT_STRINGZ, BASE_NONE, NULL, 0x0, "FOPA queue protection", HFILL }},
{ &hf_mq_fopa_unknown4,{"Unknown4", "mq.fopa.unknown4", FT_UINT32, BASE_HEX, NULL, 0x0, "FOPA unknown4", HFILL }},
{ &hf_mq_fopa_unknown5,{"Unknown5", "mq.fopa.unknown5", FT_UINT32, BASE_HEX, NULL, 0x0, "FOPA unknown5", HFILL }},
{ &hf_mq_msgreq_version ,{"version.", "mq.msgreq.version", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ version", HFILL }},
{ &hf_mq_msgreq_handle ,{"handle..", "mq.msgreq.handle", FT_UINT32, BASE_HEX, NULL, 0x0, "MSGREQ handle", HFILL }},
{ &hf_mq_msgreq_unknown1,{"unknown1", "mq.msgreq.unknown1", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ unknown1", HFILL }},
{ &hf_mq_msgreq_unknown2,{"unknown2", "mq.msgreq.unknown2", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ unknown2", HFILL }},
{ &hf_mq_msgreq_maxlen ,{"maxlen..", "mq.msgreq.maxlen", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ End Position", HFILL }},
{ &hf_mq_msgreq_unknown4,{"unknown4", "mq.msgreq.unknown4", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ unknown4", HFILL }},
{ &hf_mq_msgreq_timeout ,{"timeout.", "mq.msgreq.timeout", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ timeout", HFILL }},
{ &hf_mq_msgreq_unknown5,{"unknown5", "mq.msgreq.unknown5", FT_UINT32, BASE_HEX, NULL, 0x0, "MSGREQ unknown5", HFILL }},
{ &hf_mq_msgreq_flags ,{"flags...", "mq.msgreq.flags", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ flags", HFILL }},
{ &hf_mq_msgreq_lstseqnr,{"lstseqnr", "mq.msgreq.lstseqnr", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ Last Sequence Number", HFILL }},
{ &hf_mq_msgreq_msegver ,{"msegver.", "mq.msgreq.msegver", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, "MSGREQ multi segment hdr version", HFILL }},
{ &hf_mq_msgreq_msegseq ,{"msegseq.", "mq.msgreq.msegseq", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, "MSGREQ multi segment sequence number", HFILL }},
{ &hf_mq_msgreq_ccsid ,{"ccsid...", "mq.msgreq.ccsid", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ ccsid", HFILL }},
{ &hf_mq_msgreq_encoding,{"encoding", "mq.msgreq.encoding", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ encoding", HFILL }},
{ &hf_mq_msgreq_unknown6,{"unknown6", "mq.msgreq.unknown6", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ unknown6", HFILL }},
{ &hf_mq_msgreq_unknown7,{"unknown7", "mq.msgreq.unknown7", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ unknown7", HFILL }},
{ &hf_mq_msgreq_xfldflag,{"xfldflag", "mq.msgreq.xfldflag", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGREQ Extended Field Flag", HFILL }},
{ &hf_mq_msgreq_msgid ,{"msgid...", "mq.msgreq.xfldmsgid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MSGREQ xfld msgid", HFILL }},
{ &hf_mq_msgreq_mqmid ,{"mqmid...", "mq.msgreq.xfldmqmid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MSGREQ xfld mqmid", HFILL }},
{ &hf_mq_msgasy_version ,{"version.", "mq.msgasy.version", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC version", HFILL }},
{ &hf_mq_msgasy_handle ,{"handle..", "mq.msgasy.handle", FT_UINT32, BASE_HEX, NULL, 0x0, "MSGASYNC handle", HFILL }},
{ &hf_mq_msgasy_unknown1,{"unknown1", "mq.msgasy.unknown1", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC unknown1", HFILL }},
{ &hf_mq_msgasy_curseqnr,{"curseqnr", "mq.msgasy.curseqnr", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC curseqnr", HFILL }},
{ &hf_mq_msgasy_payload ,{"payload.", "mq.msgasy.payload", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC payload", HFILL }},
{ &hf_mq_msgasy_msegver ,{"msegver.", "mq.msgasy.msegver", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC multi segment hdr version", HFILL }},
{ &hf_mq_msgasy_msegseq ,{"msegseq.", "mq.msgasy.msegseq", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC multi segment sequence number", HFILL }},
{ &hf_mq_msgasy_flags ,{"flags...", "mq.msgasy.flags", FT_UINT32, BASE_HEX, NULL, 0x0, "MSGASYNC flags", HFILL }},
{ &hf_mq_msgasy_totlen1 ,{"totlen1.", "mq.msgasy.totlen1", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC totlen1", HFILL }},
{ &hf_mq_msgasy_totlen2 ,{"totlen2.", "mq.msgasy.totlen2", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC totlen2", HFILL }},
{ &hf_mq_msgasy_unknown2,{"unknown2", "mq.msgasy.unknown2", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC unknown2", HFILL }},
{ &hf_mq_msgasy_unknown3,{"unknown3", "mq.msgasy.unknown3", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC unknown3", HFILL }},
{ &hf_mq_msgasy_unknown4,{"unknown4", "mq.msgasy.unknown4", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC unknown4", HFILL }},
{ &hf_mq_msgasy_unknown5,{"unknown5", "mq.msgasy.unknown5", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "MSGASYNC unknown5", HFILL }},
{ &hf_mq_msgasy_strFlg ,{"strflg..", "mq.msgasy.strflg", FT_UINT16, BASE_HEX, NULL, 0x0, "MSGASYNC Str Flag", HFILL }},
{ &hf_mq_msgasy_strLen ,{"strlen..", "mq.msgasy.strlen", FT_UINT8, BASE_DEC, NULL, 0x0, "MSGASYNC Str Len", HFILL }},
{ &hf_mq_msgasy_strVal ,{"strval..", "mq.msgasy.strval", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MSGASYNC Str Val", HFILL }},
{ &hf_mq_msgasy_strPad ,{"strpad..", "mq.msgasy.strpad", FT_BYTES, BASE_NONE, NULL, 0x0, "MSGASYNC Str Pad", HFILL }},
{ &hf_mq_notif_vers ,{"version.", "mq.notif.vers", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, "NOTIFICATION version", HFILL }},
{ &hf_mq_notif_handle ,{"handle..", "mq.notif.handle", FT_UINT32, BASE_HEX, NULL, 0x0, "NOTIFICATION handle", HFILL }},
{ &hf_mq_notif_code ,{"code....", "mq.notif.code", FT_UINT32, BASE_HEX_DEC, VALS(GET_VALSV(notifcode)), 0x0, "NOTIFICATION code", HFILL }},
{ &hf_mq_notif_mqrc ,{"mqrc....", "mq.notif.mqrc", FT_UINT32, BASE_HEX_DEC, VALS(GET_VALSV(mqrc)), 0x0, "NOTIFICATION MQRC", HFILL }},
{ &hf_mq_ping_length ,{"Length", "mq.ping.length", FT_UINT32, BASE_DEC, NULL, 0x0, "PING length", HFILL }},
{ &hf_mq_ping_buffer ,{"Buffer", "mq.ping.buffer", FT_BYTES, BASE_NONE, NULL, 0x0, "PING buffer", HFILL }},
{ &hf_mq_reset_length ,{"Length", "mq.reset.length", FT_UINT32, BASE_DEC, NULL, 0x0, "RESET length", HFILL }},
{ &hf_mq_reset_seqnum ,{"SeqNum", "mq.reset.seqnum", FT_UINT32, BASE_DEC, NULL, 0x0, "RESET sequence number", HFILL }},
{ &hf_mq_status_length ,{"Length", "mq.status.length", FT_UINT32, BASE_DEC, NULL, 0x0, "STATUS length", HFILL }},
{ &hf_mq_status_code ,{"Code..", "mq.status.code", FT_UINT32, BASE_DEC, VALS(mq_status_vals), 0x0, "STATUS code", HFILL }},
{ &hf_mq_status_value ,{"Value.", "mq.status.value", FT_UINT32, BASE_DEC, NULL, 0x0, "STATUS value", HFILL }},
{ &hf_mq_od_structid ,{"structid.........", "mq.od.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_od_version ,{"version..........", "mq.od.version", FT_UINT32, BASE_DEC, NULL, 0x0, "OD version", HFILL }},
{ &hf_mq_od_objecttype ,{"ObjType..........", "mq.od.objtype", FT_UINT32, BASE_DEC, VALS(GET_VALSV(objtype)), 0x0, "OD object type", HFILL }},
{ &hf_mq_od_objectname ,{"ObjName..........", "mq.od.objname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD object name", HFILL }},
{ &hf_mq_od_objqmgrname ,{"ObjQMgr..........", "mq.od.objqmgrname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD object queue manager name", HFILL }},
{ &hf_mq_od_dynqname ,{"DynQName.........", "mq.od.dynqname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD dynamic queue name", HFILL }},
{ &hf_mq_od_altuserid ,{"AltUserID........", "mq.od.altuserid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD alternate userid", HFILL }},
{ &hf_mq_od_recspresent ,{"NbrRecord........", "mq.od.nbrrec", FT_UINT32, BASE_DEC, NULL, 0x0, "OD number of records", HFILL }},
{ &hf_mq_od_knowndstcnt ,{"Known Dest Count.", "mq.od.kdestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "OD known destination count", HFILL }},
{ &hf_mq_od_unknowdstcnt,{"Unknown Dest Cnt.", "mq.od.udestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "OD unknown destination count", HFILL }},
{ &hf_mq_od_invaldstcnt ,{"Invalid Dest Cnt.", "mq.od.idestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "OD invalid destination count", HFILL }},
{ &hf_mq_od_objrecofs ,{"Offset of 1st OR.", "mq.od.offsetor", FT_UINT32, BASE_DEC, NULL, 0x0, "OD offset of first OR", HFILL }},
{ &hf_mq_od_resprecofs ,{"Offset of 1st RR.", "mq.od.offsetrr", FT_UINT32, BASE_DEC, NULL, 0x0, "OD offset of first RR", HFILL }},
{ &hf_mq_od_objrecptr ,{"Addr of 1st OR.", "mq.od.addror", FT_UINT32, BASE_HEX, NULL, 0x0, "OD address of first OR", HFILL }},
{ &hf_mq_od_resprecptr ,{"Addr of 1st RR.", "mq.od.addrrr", FT_UINT32, BASE_HEX, NULL, 0x0, "OD address of first RR", HFILL }},
{ &hf_mq_od_altsecurid ,{"Alt security id..", "mq.od.altsecid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD alternate security id", HFILL }},
{ &hf_mq_od_resolvqname ,{"Resolved Q Name..", "mq.od.resolvq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD resolved queue name", HFILL }},
{ &hf_mq_od_resolvqmgrnm,{"Resolved QMgrName", "mq.od.resolvqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OD resolved queue manager name", HFILL }},
{ &hf_mq_od_resolvobjtyp,{"Resolv Obj Type..", "mq.od.resolvedobjtype", FT_UINT32, BASE_DEC, NULL, 0x0, "OD resolved object type", HFILL }},
{ &hf_mq_or_objname ,{"Object name...", "mq.or.objname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OR object name", HFILL }},
{ &hf_mq_or_objqmgrname ,{"Object QMgr Nm", "mq.or.objqmgrname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "OR object queue manager name", HFILL }},
{ &hf_mq_rr_compcode ,{"Comp Code", "mq.rr.completioncode", FT_UINT32, BASE_DEC, NULL, 0x0, "OR completion code", HFILL }},
{ &hf_mq_rr_reascode ,{"Reas Code", "mq.rr.reasoncode", FT_UINT32, BASE_DEC, NULL, 0x0, "OR reason code", HFILL }},
{ &hf_mq_pmr_msgid ,{"Message Id", "mq.pmr.msgid", FT_BYTES, BASE_NONE, NULL, 0x0, "PMR Message Id", HFILL }},
{ &hf_mq_pmr_correlid ,{"Correlation Id", "mq.pmr.correlid", FT_BYTES, BASE_NONE, NULL, 0x0, "PMR Correlation Id", HFILL }},
{ &hf_mq_pmr_groupid ,{"GroupId", "mq.pmr.groupid", FT_BYTES, BASE_NONE, NULL, 0x0, "PMR GroupId", HFILL }},
{ &hf_mq_pmr_feedback ,{"Feedback", "mq.pmr.feedback", FT_UINT32, BASE_DEC, NULL, 0x0, "PMR Feedback", HFILL }},
{ &hf_mq_pmr_acttoken ,{"Accounting token", "mq.pmr.acttoken", FT_BYTES, BASE_NONE, NULL, 0x0, "PMR accounting token", HFILL }},
{ &hf_mq_md_structid ,{"structid.", "mq.md.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_md_version ,{"Version..", "mq.md.version", FT_UINT32, BASE_DEC, NULL, 0x0, "MD version", HFILL }},
{ &hf_mq_md_report ,{"Report...", "mq.md.report", FT_UINT32, BASE_DEC, NULL, 0x0, "MD report", HFILL }},
{ &hf_mq_md_msgtype ,{"Msg Type.", "mq.md.msgtype", FT_UINT32, BASE_DEC, NULL, 0x0, "MD message type", HFILL }},
{ &hf_mq_md_expiry ,{"Expiry .", "mq.md.expiry", FT_INT32, BASE_DEC, NULL, 0x0, "MD expiry", HFILL }},
{ &hf_mq_md_feedback ,{"Feedback.", "mq.md.feedback", FT_UINT32, BASE_DEC, NULL, 0x0, "MD feedback", HFILL }},
{ &hf_mq_md_encoding ,{"Encoding.", "mq.md.encoding", FT_UINT32, BASE_DEC, NULL, 0x0, "MD encoding", HFILL }},
{ &hf_mq_md_ccsid ,{"CCSID....", "mq.md.ccsid", FT_INT32, BASE_DEC, NULL, 0x0, "MD character set", HFILL }},
{ &hf_mq_md_format ,{"Format...", "mq.md.format", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD format", HFILL }},
{ &hf_mq_md_priority ,{"Priority.", "mq.md.priority", FT_INT32, BASE_DEC, NULL, 0x0, "MD priority", HFILL }},
{ &hf_mq_md_persistence ,{"Persist..", "mq.md.persistence", FT_UINT32, BASE_DEC, NULL, 0x0, "MD persistence", HFILL }},
{ &hf_mq_md_msgid ,{"Msg ID...", "mq.md.msgid", FT_BYTES, BASE_NONE, NULL, 0x0, "MD Message Id", HFILL }},
{ &hf_mq_md_correlid ,{"CorrelID.", "mq.md.correlid", FT_BYTES, BASE_NONE, NULL, 0x0, "MD Correlation Id", HFILL }},
{ &hf_mq_md_backoutcnt ,{"BackoCnt.", "mq.md.backount", FT_UINT32, BASE_DEC, NULL, 0x0, "MD Backout count", HFILL }},
{ &hf_mq_md_replytoq ,{"ReplyToQ.", "mq.md.replytoq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD ReplyTo queue", HFILL }},
{ &hf_mq_md_replytoqmgr ,{"RepToQMgr", "mq.md.replytoqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD ReplyTo queue manager", HFILL }},
{ &hf_mq_md_userid ,{"UserId...", "mq.md.userid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD UserId", HFILL }},
{ &hf_mq_md_acttoken ,{"AccntTok.", "mq.md.acttoken", FT_BYTES, BASE_NONE, NULL, 0x0, "MD accounting token", HFILL }},
{ &hf_mq_md_appliddata ,{"AppIdData", "mq.md.appldata", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Put applicationId data", HFILL }},
{ &hf_mq_md_putappltype ,{"PutAppTyp", "mq.md.appltype", FT_INT32, BASE_DEC, VALS(GET_VALSV(mqat)), 0x0, "MD Put application type", HFILL }},
{ &hf_mq_md_putapplname ,{"PutAppNme", "mq.md.applname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Put application name", HFILL }},
{ &hf_mq_md_putdate ,{"PutDatGMT", "mq.md.date", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Put date", HFILL }},
{ &hf_mq_md_puttime ,{"PutTimGMT", "mq.md.time", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Put time", HFILL }},
{ &hf_mq_md_apporigdata ,{"AppOriDat", "mq.md.origdata", FT_STRINGZ, BASE_NONE, NULL, 0x0, "MD Application original data", HFILL }},
{ &hf_mq_md_groupid ,{"GroupId..", "mq.md.groupid", FT_BYTES, BASE_NONE, NULL, 0x0, "MD GroupId", HFILL }},
{ &hf_mq_md_msgseqnumber,{"MsgSeqNum", "mq.md.msgseqnumber", FT_UINT32, BASE_DEC, NULL, 0x0, "MD Message sequence number", HFILL }},
{ &hf_mq_md_offset ,{"Offset...", "mq.md.offset", FT_UINT32, BASE_DEC, NULL, 0x0, "MD Offset", HFILL }},
{ &hf_mq_md_msgflags ,{"Msg flags", "mq.md.msgflags", FT_UINT32, BASE_HEX, NULL, 0x0, "MD Message flags", HFILL }},
{ &hf_mq_md_origlen ,{"Orig len.", "mq.md.origlength", FT_INT32, BASE_DEC, NULL, 0x0, "MD Original length", HFILL }},
{ &hf_mq_dlh_structid ,{"structid.", "mq.dlh.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_dlh_version ,{"Version..", "mq.dlh.version", FT_UINT32, BASE_DEC, NULL, 0x0, "DLH version", HFILL }},
{ &hf_mq_dlh_reason ,{"Reason...", "mq.dlh.reason", FT_UINT32, BASE_DEC, NULL, 0x0, "DLH reason", HFILL }},
{ &hf_mq_dlh_destq ,{"Dest Q...", "mq.dlh.destq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH destination queue", HFILL }},
{ &hf_mq_dlh_destqmgr ,{"DestQMgr.", "mq.dlh.destqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH destination queue manager", HFILL }},
{ &hf_mq_dlh_encoding ,{"Encoding.", "mq.dlh.encoding", FT_UINT32, BASE_DEC, NULL, 0x0, "DLH encoding", HFILL }},
{ &hf_mq_dlh_ccsid ,{"CCSID....", "mq.dlh.ccsid", FT_INT32, BASE_DEC, NULL, 0x0, "DLH character set", HFILL }},
{ &hf_mq_dlh_format ,{"Format...", "mq.dlh.format", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH format", HFILL }},
{ &hf_mq_dlh_putappltype,{"PutAppTyp", "mq.dlh.putappltype", FT_INT32, BASE_DEC, VALS(GET_VALSV(mqat)), 0x0, "DLH put application type", HFILL }},
{ &hf_mq_dlh_putapplname,{"PutAppNme", "mq.dlh.putapplname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH put application name", HFILL }},
{ &hf_mq_dlh_putdate ,{"PutDatGMT", "mq.dlh.putdate", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH put date", HFILL }},
{ &hf_mq_dlh_puttime ,{"PutTimGMT", "mq.dlh.puttime", FT_STRINGZ, BASE_NONE, NULL, 0x0, "DLH put time", HFILL }},
{ &hf_mq_dh_putmsgrecfld,{"Flags PMR", "mq.dh.flagspmr", FT_UINT32, BASE_DEC, NULL, 0x0, "DH flags PMR", HFILL }},
{ &hf_mq_dh_recspresent ,{"NumOfRecs", "mq.dh.nbrrec", FT_UINT32, BASE_DEC, NULL, 0x0, "DH number of records", HFILL }},
{ &hf_mq_dh_objrecofs ,{"Ofs1stOR.", "mq.dh.offsetor", FT_UINT32, BASE_DEC, NULL, 0x0, "DH offset of first OR", HFILL }},
{ &hf_mq_dh_putmsgrecofs,{"Ofs1stPMR", "mq.dh.offsetpmr", FT_UINT32, BASE_DEC, NULL, 0x0, "DH offset of first PMR", HFILL }},
{ &hf_mq_gmo_structid ,{"structid.", "mq.gmo.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_gmo_version ,{"Version..", "mq.gmo.version", FT_UINT32, BASE_DEC, NULL, 0x0, "GMO version", HFILL }},
{ &hf_mq_gmo_options ,{"Options..", "mq.gmo.options", FT_UINT32, BASE_HEX, NULL, 0x0, "GMO options", HFILL }},
{ &hf_mq_gmo_options_PROPERTIES_COMPATIBILITY,{"PROPERTIES_COMPATIBILITY", "mq.gmo.options.PROPERTIES_COMPATIBILITY", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_PROPERTIES_COMPATIBILITY, "GMO options PROPERTIES_COMPATIBILITY", HFILL }},
{ &hf_mq_gmo_options_PROPERTIES_IN_HANDLE ,{"PROPERTIES_IN_HANDLE....", "mq.gmo.options.PROPERTIES_IN_HANDLE", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_PROPERTIES_IN_HANDLE , "GMO options PROPERTIES_IN_HANDLE", HFILL }},
{ &hf_mq_gmo_options_NO_PROPERTIES ,{"NO_PROPERTIES...........", "mq.gmo.options.NO_PROPERTIES", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_NO_PROPERTIES , "GMO options NO_PROPERTIES", HFILL }},
{ &hf_mq_gmo_options_PROPERTIES_FORCE_MQRFH2 ,{"PROPERTIES_FORCE_MQRFH2.", "mq.gmo.options.PROPERTIES_FORCE_MQRFH2", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_PROPERTIES_FORCE_MQRFH2 , "GMO options PROPERTIES_FORCE_MQRFH2", HFILL }},
{ &hf_mq_gmo_options_UNMARKED_BROWSE_MSG ,{"UNMARKED_BROWSE_MSG.....", "mq.gmo.options.UNMARKED_BROWSE_MSG", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_UNMARKED_BROWSE_MSG , "GMO options UNMARKED_BROWSE_MSG", HFILL }},
{ &hf_mq_gmo_options_UNMARK_BROWSE_HANDLE ,{"UNMARK_BROWSE_HANDLE....", "mq.gmo.options.UNMARK_BROWSE_HANDLE", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_UNMARK_BROWSE_HANDLE , "GMO options UNMARK_BROWSE_HANDLE", HFILL }},
{ &hf_mq_gmo_options_UNMARK_BROWSE_CO_OP ,{"UNMARK_BROWSE_CO_OP.....", "mq.gmo.options.UNMARK_BROWSE_CO_OP", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_UNMARK_BROWSE_CO_OP , "GMO options UNMARK_BROWSE_CO_OP", HFILL }},
{ &hf_mq_gmo_options_MARK_BROWSE_CO_OP ,{"MARK_BROWSE_CO_OP.......", "mq.gmo.options.MARK_BROWSE_CO_OP", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_MARK_BROWSE_CO_OP , "GMO options MARK_BROWSE_CO_OP", HFILL }},
{ &hf_mq_gmo_options_MARK_BROWSE_HANDLE ,{"MARK_BROWSE_HANDLE......", "mq.gmo.options.MARK_BROWSE_HANDLE", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_MARK_BROWSE_HANDLE , "GMO options MARK_BROWSE_HANDLE", HFILL }},
{ &hf_mq_gmo_options_ALL_SEGMENTS_AVAILABLE ,{"ALL_SEGMENTS_AVAILABLE..", "mq.gmo.options.ALL_SEGMENTS_AVAILABLE", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_ALL_SEGMENTS_AVAILABLE , "GMO options ALL_SEGMENTS_AVAILABLE", HFILL }},
{ &hf_mq_gmo_options_ALL_MSGS_AVAILABLE ,{"ALL_MSGS_AVAILABLE......", "mq.gmo.options.ALL_MSGS_AVAILABLE", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_ALL_MSGS_AVAILABLE , "GMO options ALL_MSGS_AVAILABLE", HFILL }},
{ &hf_mq_gmo_options_COMPLETE_MSG ,{"COMPLETE_MSG............", "mq.gmo.options.COMPLETE_MSG", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_COMPLETE_MSG , "GMO options COMPLETE_MSG", HFILL }},
{ &hf_mq_gmo_options_LOGICAL_ORDER ,{"LOGICAL_ORDER...........", "mq.gmo.options.LOGICAL_ORDER", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_LOGICAL_ORDER , "GMO options LOGICAL_ORDER", HFILL }},
{ &hf_mq_gmo_options_CONVERT ,{"CONVERT.................", "mq.gmo.options.CONVERT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_CONVERT , "GMO options CONVERT", HFILL }},
{ &hf_mq_gmo_options_FAIL_IF_QUIESCING ,{"FAIL_IF_QUIESCING.......", "mq.gmo.options.FAIL_IF_QUIESCING", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_FAIL_IF_QUIESCING , "GMO options FAIL_IF_QUIESCING", HFILL }},
{ &hf_mq_gmo_options_SYNCPOINT_IF_PERSISTENT ,{"SYNCPOINT_IF_PERSISTENT.", "mq.gmo.options.SYNCPOINT_IF_PERSISTENT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_SYNCPOINT_IF_PERSISTENT , "GMO options SYNCPOINT_IF_PERSISTENT", HFILL }},
{ &hf_mq_gmo_options_BROWSE_MSG_UNDER_CURSOR ,{"BROWSE_MSG_UNDER_CURSOR.", "mq.gmo.options.BROWSE_MSG_UNDER_CURSOR", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_BROWSE_MSG_UNDER_CURSOR , "GMO options BROWSE_MSG_UNDER_CURSOR", HFILL }},
{ &hf_mq_gmo_options_UNLOCK ,{"UNLOCK..................", "mq.gmo.options.UNLOCK", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_UNLOCK , "GMO options UNLOCK", HFILL }},
{ &hf_mq_gmo_options_LOCK ,{"LOCK....................", "mq.gmo.options.LOCK", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_LOCK , "GMO options LOCK", HFILL }},
{ &hf_mq_gmo_options_MSG_UNDER_CURSOR ,{"MSG_UNDER_CURSOR........", "mq.gmo.options.MSG_UNDER_CURSOR", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_MSG_UNDER_CURSOR , "GMO options MSG_UNDER_CURSOR", HFILL }},
{ &hf_mq_gmo_options_MARK_SKIP_BACKOUT ,{"MARK_SKIP_BACKOUT.......", "mq.gmo.options.MARK_SKIP_BACKOUT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_MARK_SKIP_BACKOUT , "GMO options MARK_SKIP_BACKOUT", HFILL }},
{ &hf_mq_gmo_options_ACCEPT_TRUNCATED_MSG ,{"ACCEPT_TRUNCATED_MSG....", "mq.gmo.options.ACCEPT_TRUNCATED_MSG", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_ACCEPT_TRUNCATED_MSG , "GMO options ACCEPT_TRUNCATED_MSG", HFILL }},
{ &hf_mq_gmo_options_BROWSE_NEXT ,{"BROWSE_NEXT.............", "mq.gmo.options.BROWSE_NEXT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_BROWSE_NEXT , "GMO options BROWSE_NEXT", HFILL }},
{ &hf_mq_gmo_options_BROWSE_FIRST ,{"BROWSE_FIRST............", "mq.gmo.options.BROWSE_FIRST", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_BROWSE_FIRST , "GMO options BROWSE_FIRST", HFILL }},
{ &hf_mq_gmo_options_SET_SIGNAL ,{"SET_SIGNAL..............", "mq.gmo.options.SET_SIGNAL", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_SET_SIGNAL , "GMO options SET_SIGNAL", HFILL }},
{ &hf_mq_gmo_options_NO_SYNCPOINT ,{"NO_SYNCPOINT............", "mq.gmo.options.NO_SYNCPOINT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_NO_SYNCPOINT , "GMO options NO_SYNCPOINT", HFILL }},
{ &hf_mq_gmo_options_SYNCPOINT ,{"SYNCPOINT...............", "mq.gmo.options.SYNCPOINT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_SYNCPOINT , "GMO options SYNCPOINT", HFILL }},
{ &hf_mq_gmo_options_WAIT ,{"WAIT....................", "mq.gmo.options.WAIT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQGMO_WAIT , "GMO options WAIT", HFILL }},
{ &hf_mq_gmo_waitinterval,{"WaitIntv.", "mq.gmo.waitint", FT_INT32, BASE_DEC, NULL, 0x0, "GMO wait interval", HFILL }},
{ &hf_mq_gmo_signal1 ,{"Signal 1.", "mq.gmo.signal1", FT_UINT32, BASE_HEX, NULL, 0x0, "GMO signal 1", HFILL }},
{ &hf_mq_gmo_signal2 ,{"Signal 2.", "mq.gmo.signal2", FT_UINT32, BASE_HEX, NULL, 0x0, "GMO signal 2", HFILL }},
{ &hf_mq_gmo_resolvqname ,{"ResQName.", "mq.gmo.resolvq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "GMO resolved queue name", HFILL }},
{ &hf_mq_gmo_matchoptions,{"MatchOpt.", "mq.gmo.matchopt", FT_UINT32, BASE_HEX, NULL, 0x0, "GMO match options", HFILL }},
{ &hf_mq_gmo_matchoptions_MATCH_MSG_TOKEN ,{"MATCH_MSG_TOKEN.....", "mq.gmo.matchoptions.MATCH_MSG_TOKEN", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQMO_MATCH_MSG_TOKEN , "GMO matchoptions MATCH_MSG_TOKEN", HFILL }},
{ &hf_mq_gmo_matchoptions_MATCH_OFFSET ,{"MATCH_OFFSET........", "mq.gmo.matchoptions.MATCH_OFFSET", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQMO_MATCH_OFFSET , "GMO matchoptions MATCH_OFFSET", HFILL }},
{ &hf_mq_gmo_matchoptions_MATCH_MSG_SEQ_NUMBER,{"MATCH_MSG_SEQ_NUMBER", "mq.gmo.matchoptions.MATCH_MSG_SEQ_NUMBER", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQMO_MATCH_MSG_SEQ_NUMBER, "GMO matchoptions MATCH_MSG_SEQ_NUMBER", HFILL }},
{ &hf_mq_gmo_matchoptions_MATCH_GROUP_ID ,{"MATCH_GROUP_ID......", "mq.gmo.matchoptions.MATCH_GROUP_ID", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQMO_MATCH_GROUP_ID , "GMO matchoptions MATCH_GROUP_ID", HFILL }},
{ &hf_mq_gmo_matchoptions_MATCH_CORREL_ID ,{"MATCH_CORREL_ID.....", "mq.gmo.matchoptions.MATCH_CORREL_ID", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQMO_MATCH_CORREL_ID , "GMO matchoptions MATCH_CORREL_ID", HFILL }},
{ &hf_mq_gmo_matchoptions_MATCH_MSG_ID ,{"MATCH_MSG_ID........", "mq.gmo.matchoptions.MATCH_MSG_ID", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQMO_MATCH_MSG_ID , "GMO matchoptions MATCH_MSG_ID", HFILL }},
{ &hf_mq_gmo_groupstatus ,{"GrpStatus", "mq.gmo.grpstat", FT_UINT8, BASE_HEX, NULL, 0x0, "GMO group status", HFILL }},
{ &hf_mq_gmo_segmstatus ,{"SegStatus", "mq.gmo.sgmtstat", FT_UINT8, BASE_HEX, NULL, 0x0, "GMO segment status", HFILL }},
{ &hf_mq_gmo_segmentation,{"Segmentat", "mq.gmo.segmentation", FT_UINT8, BASE_HEX, NULL, 0x0, "GMO segmentation", HFILL }},
{ &hf_mq_gmo_reserved ,{"Reserved.", "mq.gmo.reserved", FT_UINT8, BASE_HEX, NULL, 0x0, "GMO reserved", HFILL }},
{ &hf_mq_gmo_msgtoken ,{"MsgToken.", "mq.gmo.msgtoken", FT_BYTES, BASE_NONE, NULL, 0x0, "GMO message token", HFILL }},
{ &hf_mq_gmo_returnedlen ,{"RtnLength", "mq.gmo.retlen", FT_INT32, BASE_DEC, NULL, 0x0, "GMO returned length", HFILL }},
{ &hf_mq_lpoo_structid ,{"structid", "mq.lpoo.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_lpoo_version ,{"Version.", "mq.lpoo.version", FT_UINT32, BASE_DEC, NULL, 0x0, "LPOO version", HFILL }},
{ &hf_mq_lpoo_unknown1 ,{"Unknown1", "mq.lpoo.unknown1", FT_UINT32, BASE_HEX, NULL, 0x0, "LPOO unknown1", HFILL }},
{ &hf_mq_lpoo_unknown2 ,{"Unknown2", "mq.lpoo.unknown2", FT_UINT32, BASE_HEX, NULL, 0x0, "LPOO unknown2", HFILL }},
{ &hf_mq_lpoo_unknown3 ,{"Unknown3", "mq.lpoo.unknown3", FT_UINT32, BASE_HEX, NULL, 0x0, "LPOO unknown3", HFILL }},
{ &hf_mq_lpoo_unknown4 ,{"Unknown4", "mq.lpoo.unknown4", FT_UINT32, BASE_HEX, NULL, 0x0, "LPOO unknown4", HFILL }},
{ &hf_mq_lpoo_unknown5 ,{"Unknown5", "mq.lpoo.unknown5", FT_UINT32, BASE_HEX, NULL, 0x0, "LPOO unknown5", HFILL }},
{ &hf_mq_lpoo_qprotect ,{"qprotect", "mq.lpoo.qprotect", FT_STRINGZ, BASE_NONE, NULL, 0x0, "LPOO queue protection", HFILL }},
{ &hf_mq_lpoo_unknown6 ,{"Unknown6", "mq.lpoo.unknown6", FT_UINT32, BASE_HEX, NULL, 0x0, "LPOO unknown6", HFILL }},
{ &hf_mq_lpoo_unknown7 ,{"Unknown7", "mq.lpoo.unknown7", FT_UINT32, BASE_HEX, NULL, 0x0, "LPOO unknown7", HFILL }},
{ &hf_mq_pmo_structid ,{"structid.", "mq.pmo.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_mq_pmo_version ,{"Version..", "mq.pmo.version", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO version", HFILL }},
{ &hf_mq_pmo_options ,{"Options..", "mq.pmo.options", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO options", HFILL }},
{ &hf_mq_pmo_options_NOT_OWN_SUBS ,{"NOT_OWN_SUBS............", "mq.pmo.options.NOT_OWN_SUBS", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_NOT_OWN_SUBS , "PMO options NOT_OWN_SUBS", HFILL }},
{ &hf_mq_pmo_options_SUPPRESS_REPLYTO ,{"SUPPRESS_REPLYTO........", "mq.pmo.options.SUPPRESS_REPLYTO", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_SUPPRESS_REPLYTO , "PMO options SUPPRESS_REPLYTO", HFILL }},
{ &hf_mq_pmo_options_SCOPE_QMGR ,{"SCOPE_QMGR..............", "mq.pmo.options.SCOPE_QMGR", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_SCOPE_QMGR , "PMO options SCOPE_QMGR", HFILL }},
{ &hf_mq_pmo_options_MD_FOR_OUTPUT_ONLY ,{"MD_FOR_OUTPUT_ONLY......", "mq.pmo.options.MD_FOR_OUTPUT_ONLY", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_MD_FOR_OUTPUT_ONLY , "PMO options MD_FOR_OUTPUT_ONLY", HFILL }},
{ &hf_mq_pmo_options_RETAIN ,{"RETAIN..................", "mq.pmo.options.RETAIN", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_RETAIN , "PMO options RETAIN", HFILL }},
{ &hf_mq_pmo_options_WARN_IF_NO_SUBS_MATCHED ,{"WARN_IF_NO_SUBS_MATCHED.", "mq.pmo.options.WARN_IF_NO_SUBS_MATCHED", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_WARN_IF_NO_SUBS_MATCHED , "PMO options WARN_IF_NO_SUBS_MATCHED", HFILL }},
{ &hf_mq_pmo_options_RESOLVE_LOCAL_Q ,{"RESOLVE_LOCAL_Q.........", "mq.pmo.options.RESOLVE_LOCAL_Q", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_RESOLVE_LOCAL_Q , "PMO options RESOLVE_LOCAL_Q", HFILL }},
{ &hf_mq_pmo_options_SYNC_RESPONSE ,{"SYNC_RESPONSE...........", "mq.pmo.options.SYNC_RESPONSE", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_SYNC_RESPONSE , "PMO options SYNC_RESPONSE", HFILL }},
{ &hf_mq_pmo_options_ASYNC_RESPONSE ,{"ASYNC_RESPONSE..........", "mq.pmo.options.ASYNC_RESPONSE", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_ASYNC_RESPONSE , "PMO options ASYNC_RESPONSE", HFILL }},
{ &hf_mq_pmo_options_LOGICAL_ORDER ,{"LOGICAL_ORDER...........", "mq.pmo.options.LOGICAL_ORDER", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_LOGICAL_ORDER , "PMO options LOGICAL_ORDER", HFILL }},
{ &hf_mq_pmo_options_NO_CONTEXT ,{"NO_CONTEXT..............", "mq.pmo.options.NO_CONTEXT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_NO_CONTEXT , "PMO options NO_CONTEXT", HFILL }},
{ &hf_mq_pmo_options_FAIL_IF_QUIESCING ,{"FAIL_IF_QUIESCING.......", "mq.pmo.options.FAIL_IF_QUIESCING", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_FAIL_IF_QUIESCING , "PMO options FAIL_IF_QUIESCING", HFILL }},
{ &hf_mq_pmo_options_ALTERNATE_USER_AUTHORITY,{"ALTERNATE_USER_AUTHORITY", "mq.pmo.options.ALTERNATE_USER_AUTHORITY", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_ALTERNATE_USER_AUTHORITY , "PMO options ALTERNATE_USER_AUTHORITY", HFILL }},
{ &hf_mq_pmo_options_SET_ALL_CONTEXT ,{"SET_ALL_CONTEXT.........", "mq.pmo.options.SET_ALL_CONTEXT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_SET_ALL_CONTEXT , "PMO options SET_ALL_CONTEXT", HFILL }},
{ &hf_mq_pmo_options_SET_IDENTITY_CONTEXT ,{"SET_IDENTITY_CONTEXT....", "mq.pmo.options.SET_IDENTITY_CONTEXT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_SET_IDENTITY_CONTEXT , "PMO options SET_IDENTITY_CONTEXT", HFILL }},
{ &hf_mq_pmo_options_PASS_ALL_CONTEXT ,{"PASS_ALL_CONTEXT........", "mq.pmo.options.PASS_ALL_CONTEXT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_PASS_ALL_CONTEXT , "PMO options PASS_ALL_CONTEXT", HFILL }},
{ &hf_mq_pmo_options_PASS_IDENTITY_CONTEXT ,{"PASS_IDENTITY_CONTEXT...", "mq.pmo.options.PASS_IDENTITY_CONTEXT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_PASS_IDENTITY_CONTEXT , "PMO options PASS_IDENTITY_CONTEXT", HFILL }},
{ &hf_mq_pmo_options_NEW_CORREL_ID ,{"NEW_CORREL_ID...........", "mq.pmo.options.NEW_CORREL_ID", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_NEW_CORREL_ID , "PMO options NEW_CORREL_ID", HFILL }},
{ &hf_mq_pmo_options_NEW_MSG_ID ,{"NEW_MSG_ID..............", "mq.pmo.options.NEW_MSG_ID", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_NEW_MSG_ID , "PMO options NEW_MSG_ID", HFILL }},
{ &hf_mq_pmo_options_DEFAULT_CONTEXT ,{"DEFAULT_CONTEXT.........", "mq.pmo.options.DEFAULT_CONTEXT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_DEFAULT_CONTEXT , "PMO options DEFAULT_CONTEXT", HFILL }},
{ &hf_mq_pmo_options_NO_SYNCPOINT ,{"NO_SYNCPOINT............", "mq.pmo.options.NO_SYNCPOINT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_NO_SYNCPOINT , "PMO options NO_SYNCPOINT", HFILL }},
{ &hf_mq_pmo_options_SYNCPOINT ,{"SYNCPOINT...............", "mq.pmo.options.SYNCPOINT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_MQPMO_SYNCPOINT , "PMO options SYNCPOINT", HFILL }},
{ &hf_mq_pmo_timeout ,{"Timeout..", "mq.pmo.timeout", FT_INT32, BASE_DEC, NULL, 0x0, "PMO time out", HFILL }},
{ &hf_mq_pmo_context ,{"Context..", "mq.pmo.context", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO context", HFILL }},
{ &hf_mq_pmo_knowndstcnt ,{"KnDstCnt.", "mq.pmo.kdstcount", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO known destination count", HFILL }},
{ &hf_mq_pmo_unkndstcnt ,{"UkDstCnt.", "mq.pmo.udestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO unknown destination count", HFILL }},
{ &hf_mq_pmo_invaldstcnt ,{"InDstCnt.", "mq.pmo.idestcount", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO invalid destination count", HFILL }},
{ &hf_mq_pmo_resolvqname ,{"ResQName.", "mq.pmo.resolvq", FT_STRINGZ, BASE_NONE, NULL, 0x0, "PMO resolved queue name", HFILL }},
{ &hf_mq_pmo_resolvqmgr ,{"ResQMgr..", "mq.pmo.resolvqmgr", FT_STRINGZ, BASE_NONE, NULL, 0x0, "PMO resolved queue manager name", HFILL }},
{ &hf_mq_pmo_recspresent ,{"NumRecs..", "mq.pmo.nbrrec", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO number of records", HFILL }},
{ &hf_mq_pmo_putmsgrecfld,{"PMR Flag.", "mq.pmo.flagspmr", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO flags PMR fields", HFILL }},
{ &hf_mq_pmo_putmsgrecofs,{"Ofs1stPMR", "mq.pmo.offsetpmr", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO offset of first PMR", HFILL }},
{ &hf_mq_pmo_resprecofs ,{"Off1stRR.", "mq.pmo.offsetrr", FT_UINT32, BASE_DEC, NULL, 0x0, "PMO offset of first RR", HFILL }},
{ &hf_mq_pmo_putmsgrecptr,{"Adr1stPMR", "mq.pmo.addrrec", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO address of first record", HFILL }},
{ &hf_mq_pmo_resprecptr ,{"Adr1stRR.", "mq.pmo.addrres", FT_UINT32, BASE_HEX, NULL, 0x0, "PMO address of first response record", HFILL }},
{ &hf_mq_head_structid ,{"Structid", "mq.head.structid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Header structid", HFILL }},
{ &hf_mq_head_version ,{"version.", "mq.head.version", FT_UINT32, BASE_DEC, NULL, 0x0, "Header version", HFILL }},
{ &hf_mq_head_length ,{"Length..", "mq.head.length", FT_UINT32, BASE_DEC, NULL, 0x0, "Header length", HFILL }},
{ &hf_mq_head_encoding ,{"Encoding", "mq.head.encoding", FT_UINT32, BASE_DEC, NULL, 0x0, "Header encoding", HFILL }},
{ &hf_mq_head_ccsid ,{"CCSID...", "mq.head.ccsid", FT_INT32, BASE_DEC, NULL, 0x0, "Header character set", HFILL }},
{ &hf_mq_head_format ,{"Format..", "mq.head.format", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Header format", HFILL }},
{ &hf_mq_head_flags ,{"Flags...", "mq.head.flags", FT_UINT32, BASE_DEC, NULL, 0x0, "Header flags", HFILL }},
{ &hf_mq_head_struct ,{"Struct..", "mq.head.struct", FT_BYTES, BASE_NONE, NULL, 0x0, "Header struct", HFILL }},
{ &hf_mq_xa_length ,{"Length.......", "mq.xa.length", FT_UINT32, BASE_DEC, NULL, 0x0, "XA Length", HFILL }},
{ &hf_mq_xa_returnvalue ,{"Return value.", "mq.xa.returnvalue", FT_INT32, BASE_DEC, VALS(mq_xaer_vals), 0x0, "XA Return Value", HFILL }},
{ &hf_mq_xa_tmflags ,{"TransMgrFlags", "mq.xa.tmflags", FT_UINT32, BASE_HEX, NULL, 0x0, "XA Transaction Manager Flags", HFILL }},
{ &hf_mq_xa_rmid ,{"ResourceMgrID", "mq.xa.rmid", FT_UINT32, BASE_DEC, NULL, 0x0, "XA Resource Manager ID", HFILL }},
{ &hf_mq_xa_count ,{"Number of Xid", "mq.xa.nbxid", FT_UINT32, BASE_DEC, NULL, 0x0, "XA Number of Xid", HFILL }},
{ &hf_mq_xa_tmflags_join ,{"JOIN......", "mq.xa.tmflags.join", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMJOIN, "XA TM Flags JOIN", HFILL }},
{ &hf_mq_xa_tmflags_endrscan ,{"ENDRSCAN..", "mq.xa.tmflags.endrscan", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMENDRSCAN, "XA TM Flags ENDRSCAN", HFILL }},
{ &hf_mq_xa_tmflags_startrscan,{"STARTRSCAN", "mq.xa.tmflags.startrscan", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMSTARTRSCAN, "XA TM Flags STARTRSCAN", HFILL }},
{ &hf_mq_xa_tmflags_suspend ,{"SUSPEND...", "mq.xa.tmflags.suspend", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMSUSPEND, "XA TM Flags SUSPEND", HFILL }},
{ &hf_mq_xa_tmflags_success ,{"SUCCESS...", "mq.xa.tmflags.success", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMSUCCESS, "XA TM Flags SUCCESS", HFILL }},
{ &hf_mq_xa_tmflags_resume ,{"RESUME....", "mq.xa.tmflags.resume", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMRESUME, "XA TM Flags RESUME", HFILL }},
{ &hf_mq_xa_tmflags_fail ,{"FAIL......", "mq.xa.tmflags.fail", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMFAIL, "XA TM Flags FAIL", HFILL }},
{ &hf_mq_xa_tmflags_onephase ,{"ONEPHASE..", "mq.xa.tmflags.onephase", FT_BOOLEAN, 32, TFS(&tfs_set_notset), MQ_XA_TMONEPHASE, "XA TM Flags ONEPHASE", HFILL }},
{ &hf_mq_xa_xid_formatid ,{"Format ID....", "mq.xa.xid.formatid", FT_INT32, BASE_DEC, NULL, 0x0, "XA Xid Format ID", HFILL }},
{ &hf_mq_xa_xid_glbxid_len,{"GlbTransIDLen", "mq.xa.xid.gxidl", FT_UINT8, BASE_DEC, NULL, 0x0, "XA Xid Global TransactionId Length", HFILL }},
{ &hf_mq_xa_xid_brq_length,{"BranchQualLen", "mq.xa.xid.bql", FT_UINT8, BASE_DEC, NULL, 0x0, "XA Xid Branch Qualifier Length", HFILL }},
{ &hf_mq_xa_xid_globalxid ,{"GlbTransactID", "mq.xa.xid.gxid", FT_BYTES, BASE_NONE, NULL, 0x0, "XA Xid Global TransactionId", HFILL }},
{ &hf_mq_xa_xid_brq ,{"BranchQualif.", "mq.xa.xid.bq", FT_BYTES, BASE_NONE, NULL, 0x0, "XA Xid Branch Qualifier", HFILL }},
{ &hf_mq_xa_xainfo_length ,{"Length.......", "mq.xa.xainfo.length", FT_UINT8, BASE_DEC, NULL, 0x0, "XA XA_info Length", HFILL }},
{ &hf_mq_xa_xainfo_value ,{"Value........", "mq.xa.xainfo.value", FT_STRINGZ, BASE_NONE, NULL, 0x0, "XA XA_info Value", HFILL }},
{ &hf_mq_charv_vsptr ,{"VLStr Addr.", "mq.charv.vsptr", FT_UINT32, BASE_HEX, NULL, 0x0, "VS Address", HFILL }},
{ &hf_mq_charv_vsoffset ,{"VLStr Offs.", "mq.charv.vsoffset", FT_UINT32, BASE_DEC, NULL, 0x0, "VS Offset", HFILL }},
{ &hf_mq_charv_vsbufsize ,{"VLStr BufSz", "mq.charv.vsbufsize", FT_UINT32, BASE_DEC, NULL, 0x0, "VS BufSize", HFILL }},
{ &hf_mq_charv_vslength ,{"VLStr Len..", "mq.charv.vslength", FT_UINT32, BASE_DEC, NULL, 0x0, "VS Length", HFILL }},
{ &hf_mq_charv_vsccsid ,{"VLStr Ccsid", "mq.charv.vsccsid", FT_INT32, BASE_DEC, NULL, 0x0, "VS CCSID", HFILL }},
{ &hf_mq_charv_vsvalue ,{"VLStr Value", "mq.charv.vsvalue", FT_STRINGZ, BASE_NONE, NULL, 0x0, "VS value", HFILL }}
};
static gint *ett[] = {
&ett_mq,
&ett_mq_tsh,
&ett_mq_tsh_tcf,
&ett_mq_api,
&ett_mq_socket,
&ett_mq_msh,
&ett_mq_caut,
&ett_mq_xqh,
&ett_mq_id,
&ett_mq_id_icf,
&ett_mq_id_ief,
&ett_mq_uid,
&ett_mq_conn,
&ett_mq_msg,
&ett_mq_notif,
&ett_mq_inq,
&ett_mq_spi,
&ett_mq_spi_base,
&ett_mq_spi_options,
&ett_mq_put,
&ett_mq_open,
&ett_mq_open_option,
&ett_mq_close_option,
&ett_mq_ping,
&ett_mq_reset,
&ett_mq_status,
&ett_mq_od,
&ett_mq_od_objstr,
&ett_mq_od_selstr,
&ett_mq_od_resobjstr,
&ett_mq_or,
&ett_mq_rr,
&ett_mq_pmr,
&ett_mq_md,
&ett_mq_mde,
&ett_mq_dlh,
&ett_mq_dh,
&ett_mq_gmo,
&ett_mq_gmo_option,
&ett_mq_gmo_matchoption,
&ett_mq_pmo,
&ett_mq_pmo_option,
&ett_mq_fcno,
&ett_mq_fopa,
&ett_mq_lpoo,
&ett_mq_lpoo_option,
&ett_mq_head,
&ett_mq_xa,
&ett_mq_xa_tmflags,
&ett_mq_xa_xid,
&ett_mq_xa_info,
&ett_mq_charv,
&ett_mq_reaasemb
};
module_t *mq_module;
proto_mq = proto_register_protocol("WebSphere MQ","MQ","mq");
proto_register_field_array(proto_mq, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_heur_dissector_list("mq", &mq_heur_subdissector_list);
register_init_routine(mq_init);
mq_module = prefs_register_protocol(proto_mq, NULL);
prefs_register_bool_preference(mq_module,"desegment",
"Reassemble MQ messages spanning multiple TCP segments",
"Whether the MQ dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&mq_desegment);
prefs_register_bool_preference(mq_module,"reassembly",
"Reassemble segmented MQ messages",
"Whether the MQ dissector should reassemble MQ messages spanning multiple TSH segments",
&mq_reassembly);
}
void proto_reg_handoff_mq(void)
{
mq_tcp_handle = create_dissector_handle(dissect_mq_tcp, proto_mq);
mq_spx_handle = create_dissector_handle(dissect_mq_spx, proto_mq);
dissector_add_handle("tcp.port", mq_tcp_handle);
heur_dissector_add("tcp", dissect_mq_heur_tcp, proto_mq);
heur_dissector_add("netbios", dissect_mq_heur_netbios, proto_mq);
heur_dissector_add("http", dissect_mq_heur_http, proto_mq);
dissector_add_uint("spx.socket", MQ_SOCKET_SPX, mq_spx_handle);
data_handle = find_dissector("data");
mqpcf_handle = find_dissector("mqpcf");
}
