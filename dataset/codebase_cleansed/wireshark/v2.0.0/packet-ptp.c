static void
dissect_ptp_oE(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_ptp_v2(tvb, pinfo, tree, TRUE);
}
static void
dissect_ptp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if(is_ptp_v1(tvb))
dissect_ptp_v1(tvb, pinfo, tree);
else if(is_ptp_v2(tvb))
dissect_ptp_v2(tvb, pinfo, tree, FALSE);
}
static gboolean
is_ptp_v1(tvbuff_t *tvb)
{
guint16 version_ptp;
version_ptp = tvb_get_ntohs(tvb, PTP_VERSIONPTP_OFFSET);
if( version_ptp == 1) return TRUE;
else return FALSE;
}
static gboolean
is_ptp_v2(tvbuff_t *tvb)
{
guint8 version_ptp;
version_ptp = 0x0F & tvb_get_guint8(tvb, PTP_V2_VERSIONPTP_OFFSET);
if( version_ptp == 2) return TRUE;
else return FALSE;
}
static void
dissect_ptp_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 ptp_control, ptp_mm_messagekey = 0;
nstime_t ts;
proto_item *ti, *flags_ti, *time_ti, *time2_ti;
proto_tree *ptp_tree = NULL, *ptp_flags_tree, *ptp_time_tree, *ptp_time2_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PTPv1");
ptp_control = tvb_get_guint8 (tvb, PTP_CONTROL_OFFSET);
if ( ptp_control == PTP_MANAGEMENT_MESSAGE ){
ptp_mm_messagekey = tvb_get_guint8(tvb, PTP_MM_MANAGEMENTMESSAGEKEY_OFFSET);
}
switch(ptp_control){
case PTP_SYNC_MESSAGE:{
col_set_str(pinfo->cinfo, COL_INFO, "Sync Message");
break;
}
case PTP_DELAY_REQ_MESSAGE:{
col_set_str(pinfo->cinfo, COL_INFO, "Delay_Request Message");
break;
}
case PTP_FOLLOWUP_MESSAGE:{
col_set_str(pinfo->cinfo, COL_INFO, "Follow_Up Message");
break;
}
case PTP_DELAY_RESP_MESSAGE:{
col_set_str(pinfo->cinfo, COL_INFO, "Delay_Response Message");
break;
}
case PTP_MANAGEMENT_MESSAGE:{
col_add_fstr(pinfo->cinfo, COL_INFO, "Management Message (%s)",
val_to_str_ext(ptp_mm_messagekey,
&ptp_managementMessageKey_infocolumn_vals_ext,
"Unknown message key %u"));
break;
}
default:{
col_set_str(pinfo->cinfo, COL_INFO, "Unknown Message");
break;
}
}
if (tree) {
ti = proto_tree_add_item(tree, proto_ptp, tvb, 0, -1, ENC_NA);
ptp_tree = proto_item_add_subtree(ti, ett_ptp);
proto_tree_add_item(ptp_tree,
hf_ptp_versionptp, tvb, PTP_VERSIONPTP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_versionnetwork, tvb, PTP_VERSIONNETWORK_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_subdomain, tvb, PTP_SUBDOMAIN_OFFSET, 16, ENC_ASCII|ENC_NA);
proto_tree_add_item(ptp_tree,
hf_ptp_messagetype, tvb, PTP_MESSAGETYPE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sourcecommunicationtechnology, tvb, PTP_SOURCECOMMUNICATIONTECHNOLOGY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sourceuuid, tvb, PTP_SOURCEUUID_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree,
hf_ptp_sourceportid, tvb, PTP_SOURCEPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sequenceid, tvb, PTP_SEQUENCEID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_control, tvb, PTP_CONTROL_OFFSET, 1, ENC_BIG_ENDIAN);
if(tree){
flags_ti = proto_tree_add_item(ptp_tree,
hf_ptp_flags, tvb, PTP_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
ptp_flags_tree = proto_item_add_subtree(flags_ti, ett_ptp_flags);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_flags_li61, tvb, PTP_FLAGS_LI61_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_flags_li59, tvb, PTP_FLAGS_LI59_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_flags_boundary_clock, tvb, PTP_FLAGS_BOUNDARY_CLOCK_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_flags_assist, tvb, PTP_FLAGS_ASSIST_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_flags_ext_sync, tvb, PTP_FLAGS_EXT_SYNC_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_flags_parent, tvb, PTP_FLAGS_PARENT_STATS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_flags_sync_burst, tvb, PTP_FLAGS_SYNC_BURST_OFFSET, 2, ENC_BIG_ENDIAN);
}
switch(ptp_control){
case PTP_SYNC_MESSAGE:
case PTP_DELAY_REQ_MESSAGE:{
ts.secs = tvb_get_ntohl(tvb, PTP_SDR_ORIGINTIMESTAMP_SECONDS_OFFSET);
ts.nsecs = tvb_get_ntohl(tvb, PTP_SDR_ORIGINTIMESTAMP_NANOSECONDS_OFFSET);
if(tree){
time_ti = proto_tree_add_time(ptp_tree,
hf_ptp_sdr_origintimestamp, tvb, PTP_SDR_ORIGINTIMESTAMP_OFFSET, 8, &ts);
ptp_time_tree = proto_item_add_subtree(time_ti, ett_ptp_time);
proto_tree_add_item(ptp_time_tree,
hf_ptp_sdr_origintimestamp_seconds, tvb,
PTP_SDR_ORIGINTIMESTAMP_SECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_time_tree, hf_ptp_sdr_origintimestamp_nanoseconds, tvb,
PTP_SDR_ORIGINTIMESTAMP_NANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_epochnumber, tvb, PTP_SDR_EPOCHNUMBER_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_currentutcoffset, tvb, PTP_SDR_CURRENTUTCOFFSET_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_sdr_grandmastercommunicationtechnology, tvb,
PTP_SDR_GRANDMASTERCOMMUNICATIONTECHNOLOGY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_grandmasterclockuuid, tvb, PTP_SDR_GRANDMASTERCLOCKUUID_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_grandmasterportid, tvb, PTP_SDR_GRANDMASTERPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_grandmastersequenceid, tvb, PTP_SDR_GRANDMASTERSEQUENCEID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_grandmasterclockstratum, tvb,
PTP_SDR_GRANDMASTERCLOCKSTRATUM_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_sdr_grandmasterclockidentifier, tvb,
PTP_SDR_GRANDMASTERCLOCKIDENTIFIER_OFFSET, 4, ENC_ASCII|ENC_NA);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_grandmasterclockvariance, tvb,
PTP_SDR_GRANDMASTERCLOCKVARIANCE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_grandmasterpreferred, tvb, PTP_SDR_GRANDMASTERPREFERRED_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_sdr_grandmasterisboundaryclock, tvb,
PTP_SDR_GRANDMASTERISBOUNDARYCLOCK_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_syncinterval, tvb, PTP_SDR_SYNCINTERVAL_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_localclockvariance, tvb, PTP_SDR_LOCALCLOCKVARIANCE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_localstepsremoved, tvb, PTP_SDR_LOCALSTEPSREMOVED_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_localclockstratum, tvb, PTP_SDR_LOCALCLOCKSTRATUM_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_localclockidentifier, tvb, PTP_SDR_LOCALCLOCKIDENTIFIER_OFFSET, 4, ENC_ASCII|ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_sdr_parentcommunicationtechnology, tvb,
PTP_SDR_PARENTCOMMUNICATIONTECHNOLOGY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_parentuuid, tvb, PTP_SDR_PARENTUUID_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_parentportfield, tvb, PTP_SDR_PARENTPORTFIELD_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_estimatedmastervariance, tvb,
PTP_SDR_ESTIMATEDMASTERVARIANCE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_estimatedmasterdrift, tvb, PTP_SDR_ESTIMATEDMASTERDRIFT_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_sdr_utcreasonable, tvb, PTP_SDR_UTCREASONABLE_OFFSET, 1, ENC_BIG_ENDIAN);
break;
}
case PTP_FOLLOWUP_MESSAGE:{
proto_tree_add_item(ptp_tree,
hf_ptp_fu_associatedsequenceid, tvb, PTP_FU_ASSOCIATEDSEQUENCEID_OFFSET, 2, ENC_BIG_ENDIAN);
ts.secs = tvb_get_ntohl(tvb, PTP_FU_PRECISEORIGINTIMESTAMP_SECONDS_OFFSET);
ts.nsecs = tvb_get_ntohl(tvb, PTP_FU_PRECISEORIGINTIMESTAMP_NANOSECONDS_OFFSET);
if(tree){
time_ti = proto_tree_add_time(ptp_tree,
hf_ptp_fu_preciseorigintimestamp, tvb,
PTP_FU_PRECISEORIGINTIMESTAMP_OFFSET, 8, &ts);
ptp_time_tree = proto_item_add_subtree(time_ti, ett_ptp_time);
proto_tree_add_item(ptp_time_tree, hf_ptp_fu_preciseorigintimestamp_seconds, tvb,
PTP_FU_PRECISEORIGINTIMESTAMP_SECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_time_tree, hf_ptp_fu_preciseorigintimestamp_nanoseconds, tvb,
PTP_FU_PRECISEORIGINTIMESTAMP_NANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
}
break;
}
case PTP_DELAY_RESP_MESSAGE:{
ts.secs = tvb_get_ntohl(tvb, PTP_DR_DELAYRECEIPTTIMESTAMP_SECONDS_OFFSET);
ts.nsecs = tvb_get_ntohl(tvb, PTP_DR_DELAYRECEIPTTIMESTAMP_NANOSECONDS_OFFSET);
if(tree){
time_ti = proto_tree_add_time(ptp_tree,
hf_ptp_dr_delayreceipttimestamp, tvb,
PTP_DR_DELAYRECEIPTTIMESTAMP_OFFSET, 8, &ts);
ptp_time_tree = proto_item_add_subtree(time_ti, ett_ptp_time);
proto_tree_add_item(ptp_time_tree, hf_ptp_dr_delayreceipttimestamp_seconds, tvb,
PTP_DR_DELAYRECEIPTTIMESTAMP_SECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_time_tree, hf_ptp_dr_delayreceipttimestamp_nanoseconds, tvb,
PTP_DR_DELAYRECEIPTTIMESTAMP_NANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ptp_tree, hf_ptp_dr_requestingsourcecommunicationtechnology, tvb,
PTP_DR_REQUESTINGSOURCECOMMUNICATIONTECHNOLOGY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_dr_requestingsourceuuid, tvb, PTP_DR_REQUESTINGSOURCEUUID_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree,
hf_ptp_dr_requestingsourceportid, tvb, PTP_DR_REQUESTINGSOURCEPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_dr_requestingsourcesequenceid, tvb,
PTP_DR_REQUESTINGSOURCESEQUENCEID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_MANAGEMENT_MESSAGE:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_targetcommunicationtechnology, tvb,
PTP_MM_TARGETCOMMUNICATIONTECHNOLOGY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_mm_targetuuid, tvb, PTP_MM_TARGETUUID_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree,
hf_ptp_mm_targetportid, tvb, PTP_MM_TARGETPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_mm_startingboundaryhops, tvb, PTP_MM_STARTINGBOUNDARYHOPS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_mm_boundaryhops, tvb, PTP_MM_BOUNDARYHOPS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_mm_managementmessagekey, tvb, PTP_MM_MANAGEMENTMESSAGEKEY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_mm_parameterlength, tvb, PTP_MM_PARAMETERLENGTH_OFFSET, 2, ENC_BIG_ENDIAN);
switch(ptp_mm_messagekey){
case PTP_MM_CLOCK_IDENTITY:{
proto_tree_add_item(ptp_tree,
hf_ptp_mm_clock_identity_clockcommunicationtechnology, tvb,
PTP_MM_CLOCK_IDENTITY_CLOCKCOMMUNICATIONTECHNOLOGY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_clock_identity_clockuuidfield, tvb,
PTP_MM_CLOCK_IDENTITY_CLOCKUUIDFIELD_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_clock_identity_clockportfield, tvb,
PTP_MM_CLOCK_IDENTITY_CLOCKPORTFIELD_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_clock_identity_manufactureridentity, tvb,
PTP_MM_CLOCK_IDENTITY_MANUFACTURERIDENTITY_OFFSET, 48, ENC_NA);
break;
}
case PTP_MM_INITIALIZE_CLOCK:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_initialize_clock_initialisationkey, tvb,
PTP_MM_INITIALIZE_CLOCK_INITIALISATIONKEY_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_MM_SET_SUBDOMAIN:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_set_subdomain_subdomainname, tvb,
PTP_MM_SET_SUBDOMAIN_SUBDOMAINNAME_OFFSET, 16, ENC_ASCII|ENC_NA);
break;
}
case PTP_MM_DEFAULT_DATA_SET:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_clockcommunicationtechnology,
tvb, PTP_MM_DEFAULT_DATA_SET_CLOCKCOMMUNICATIONTECHNOLOGY_OFFSET,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_clockuuidfield, tvb,
PTP_MM_DEFAULT_DATA_SET_CLOCKUUIDFIELD_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_clockportfield, tvb,
PTP_MM_DEFAULT_DATA_SET_CLOCKPORTFIELD_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_clockstratum, tvb,
PTP_MM_DEFAULT_DATA_SET_CLOCKSTRATUM_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_clockidentifier, tvb,
PTP_MM_DEFAULT_DATA_SET_CLOCKIDENTIFIER_OFFSET, 4, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_clockvariance, tvb,
PTP_MM_DEFAULT_DATA_SET_CLOCKVARIANCE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_clockfollowupcapable, tvb,
PTP_MM_DEFAULT_DATA_SET_CLOCKFOLLOWUPCAPABLE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_preferred, tvb,
PTP_MM_DEFAULT_DATA_SET_PREFERRED_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_initializable, tvb,
PTP_MM_DEFAULT_DATA_SET_INITIALIZABLE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_externaltiming, tvb,
PTP_MM_DEFAULT_DATA_SET_EXTERNALTIMING_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_isboundaryclock, tvb,
PTP_MM_DEFAULT_DATA_SET_ISBOUNDARYCLOCK_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_syncinterval, tvb,
PTP_MM_DEFAULT_DATA_SET_SYNCINTERVAL_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_subdomainname, tvb,
PTP_MM_DEFAULT_DATA_SET_SUBDOMAINNAME_OFFSET, 16, ENC_ASCII|ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_numberports, tvb,
PTP_MM_DEFAULT_DATA_SET_NUMBERPORTS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_default_data_set_numberforeignrecords, tvb,
PTP_MM_DEFAULT_DATA_SET_NUMBERFOREIGNRECORDS_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_MM_UPDATE_DEFAULT_DATA_SET:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_update_default_data_set_clockstratum, tvb,
PTP_MM_UPDATE_DEFAULT_DATA_SET_CLOCKSTRATUM_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_update_default_data_set_clockidentifier, tvb,
PTP_MM_UPDATE_DEFAULT_DATA_SET_CLOCKIDENTIFIER_OFFSET, 4, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_update_default_data_set_clockvariance, tvb,
PTP_MM_UPDATE_DEFAULT_DATA_SET_CLOCKVARIANCE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_update_default_data_set_preferred, tvb,
PTP_MM_UPDATE_DEFAULT_DATA_SET_PREFERRED_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_update_default_data_set_syncinterval, tvb,
PTP_MM_UPDATE_DEFAULT_DATA_SET_SYNCINTERVAL_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_update_default_data_set_subdomainname, tvb,
PTP_MM_UPDATE_DEFAULT_DATA_SET_SUBDOMAINNAME_OFFSET, 16, ENC_ASCII|ENC_NA);
break;
}
case PTP_MM_CURRENT_DATA_SET:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_current_data_set_stepsremoved, tvb,
PTP_MM_CURRENT_DATA_SET_STEPSREMOVED_OFFSET, 2, ENC_BIG_ENDIAN);
ts.secs = tvb_get_ntohl(tvb, PTP_MM_CURRENT_DATA_SET_OFFSETFROMMASTERSECONDS_OFFSET);
ts.nsecs = tvb_get_ntohl(tvb,
PTP_MM_CURRENT_DATA_SET_OFFSETFROMMASTERNANOSECONDS_OFFSET);
if (ts.nsecs & 0x80000000) ts.nsecs = ts.nsecs & 0x7FFFFFFF;
if(tree){
time_ti = proto_tree_add_time(ptp_tree,
hf_ptp_mm_current_data_set_offsetfrommaster, tvb,
PTP_MM_CURRENT_DATA_SET_OFFSETFROMMASTER_OFFSET, 8, &ts);
ptp_time_tree = proto_item_add_subtree(time_ti, ett_ptp_time);
proto_tree_add_item(ptp_time_tree,
hf_ptp_mm_current_data_set_offsetfrommasterseconds, tvb,
PTP_MM_CURRENT_DATA_SET_OFFSETFROMMASTERSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_time_tree,
hf_ptp_mm_current_data_set_offsetfrommasternanoseconds, tvb,
PTP_MM_CURRENT_DATA_SET_OFFSETFROMMASTERNANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
}
ts.secs = tvb_get_ntohl(tvb, PTP_MM_CURRENT_DATA_SET_ONEWAYDELAYSECONDS_OFFSET);
ts.nsecs = tvb_get_ntohl(tvb, PTP_MM_CURRENT_DATA_SET_ONEWAYDELAYNANOSECONDS_OFFSET);
if(tree){
time2_ti = proto_tree_add_time(ptp_tree,
hf_ptp_mm_current_data_set_onewaydelay, tvb,
PTP_MM_CURRENT_DATA_SET_ONEWAYDELAY_OFFSET, 8, &ts);
ptp_time2_tree = proto_item_add_subtree(time2_ti, ett_ptp_time2);
proto_tree_add_item(ptp_time2_tree, hf_ptp_mm_current_data_set_onewaydelayseconds,
tvb, PTP_MM_CURRENT_DATA_SET_ONEWAYDELAYSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_time2_tree,
hf_ptp_mm_current_data_set_onewaydelaynanoseconds,
tvb, PTP_MM_CURRENT_DATA_SET_ONEWAYDELAYNANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
}
break;
}
case PTP_MM_PARENT_DATA_SET:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_parentcommunicationtechnology,
tvb, PTP_MM_PARENT_DATA_SET_PARENTCOMMUNICATIONTECHNOLOGY_OFFSET,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_parentuuid, tvb,
PTP_MM_PARENT_DATA_SET_PARENTUUID_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_parentportid, tvb,
PTP_MM_PARENT_DATA_SET_PARENTPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_parentlastsyncsequencenumber,
tvb, PTP_MM_PARENT_DATA_SET_PARENTLASTSYNCSEQUENCENUMBER_OFFSET,
2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_parentfollowupcapable, tvb,
PTP_MM_PARENT_DATA_SET_PARENTFOLLOWUPCAPABLE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_parentexternaltiming, tvb,
PTP_MM_PARENT_DATA_SET_PARENTEXTERNALTIMING_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_parentvariance, tvb,
PTP_MM_PARENT_DATA_SET_PARENTVARIANCE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_parentstats, tvb,
PTP_MM_PARENT_DATA_SET_PARENTSTATS_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_observedvariance, tvb,
PTP_MM_PARENT_DATA_SET_OBSERVEDVARIANCE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_observeddrift, tvb,
PTP_MM_PARENT_DATA_SET_OBSERVEDDRIFT_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_utcreasonable, tvb,
PTP_MM_PARENT_DATA_SET_UTCREASONABLE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_mm_parent_data_set_grandmastercommunicationtechnology,
tvb, PTP_MM_PARENT_DATA_SET_GRANDMASTERCOMMUNICATIONTECHNOLOGY_OFFSET, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_grandmasteruuidfield, tvb,
PTP_MM_PARENT_DATA_SET_GRANDMASTERUUIDFIELD_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_grandmasterportidfield, tvb,
PTP_MM_PARENT_DATA_SET_GRANDMASTERPORTIDFIELD_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_grandmasterstratum, tvb,
PTP_MM_PARENT_DATA_SET_GRANDMASTERSTRATUM_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_grandmasteridentifier, tvb,
PTP_MM_PARENT_DATA_SET_GRANDMASTERIDENTIFIER_OFFSET, 4, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_grandmastervariance, tvb,
PTP_MM_PARENT_DATA_SET_GRANDMASTERVARIANCE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_grandmasterpreferred, tvb,
PTP_MM_PARENT_DATA_SET_GRANDMASTERPREFERRED_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_grandmasterisboundaryclock, tvb,
PTP_MM_PARENT_DATA_SET_GRANDMASTERISBOUNDARYCLOCK_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_parent_data_set_grandmastersequencenumber, tvb,
PTP_MM_PARENT_DATA_SET_GRANDMASTERSEQUENCENUMBER_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_MM_PORT_DATA_SET:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_returnedportnumber, tvb,
PTP_MM_PORT_DATA_SET_RETURNEDPORTNUMBER_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_portstate, tvb,
PTP_MM_PORT_DATA_SET_PORTSTATE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_lastsynceventsequencenumber, tvb,
PTP_MM_PORT_DATA_SET_LASTSYNCEVENTSEQUENCENUMBER_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_lastgeneraleventsequencenumber,
tvb, PTP_MM_PORT_DATA_SET_LASTGENERALEVENTSEQUENCENUMBER_OFFSET,
2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_portcommunicationtechnology, tvb,
PTP_MM_PORT_DATA_SET_PORTCOMMUNICATIONTECHNOLOGY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_portuuidfield, tvb,
PTP_MM_PORT_DATA_SET_PORTUUIDFIELD_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_portidfield, tvb,
PTP_MM_PORT_DATA_SET_PORTIDFIELD_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_burstenabled, tvb,
PTP_MM_PORT_DATA_SET_BURSTENABLED_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_subdomainaddressoctets, tvb,
PTP_MM_PORT_DATA_SET_SUBDOMAINADDRESSOCTETS_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_eventportaddressoctets, tvb,
PTP_MM_PORT_DATA_SET_EVENTPORTADDRESSOCTETS_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_generalportaddressoctets, tvb,
PTP_MM_PORT_DATA_SET_GENERALPORTADDRESSOCTETS_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_subdomainaddress, tvb,
PTP_MM_PORT_DATA_SET_SUBDOMAINADDRESS_OFFSET, 4, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_eventportaddress, tvb,
PTP_MM_PORT_DATA_SET_EVENTPORTADDRESS_OFFSET, 2, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_port_data_set_generalportaddress, tvb,
PTP_MM_PORT_DATA_SET_GENERALPORTADDRESS_OFFSET, 2, ENC_NA);
break;
}
case PTP_MM_GLOBAL_TIME_DATA_SET:{
ts.secs = tvb_get_ntohl(tvb, PTP_MM_GLOBAL_TIME_DATA_SET_LOCALTIMESECONDS_OFFSET);
ts.nsecs = tvb_get_ntohl(tvb,
PTP_MM_GLOBAL_TIME_DATA_SET_LOCALTIMENANOSECONDS_OFFSET);
if(tree){
time_ti = proto_tree_add_time(ptp_tree,
hf_ptp_mm_global_time_data_set_localtime, tvb,
PTP_MM_GLOBAL_TIME_DATA_SET_LOCALTIME_OFFSET, 8, &ts);
ptp_time_tree = proto_item_add_subtree(time_ti, ett_ptp_time);
proto_tree_add_item(ptp_time_tree,
hf_ptp_mm_global_time_data_set_localtimeseconds, tvb,
PTP_MM_GLOBAL_TIME_DATA_SET_LOCALTIMESECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_time_tree,
hf_ptp_mm_global_time_data_set_localtimenanoseconds,
tvb, PTP_MM_GLOBAL_TIME_DATA_SET_LOCALTIMENANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ptp_tree, hf_ptp_mm_global_time_data_set_currentutcoffset, tvb,
PTP_MM_GLOBAL_TIME_DATA_SET_CURRENTUTCOFFSET_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_global_time_data_set_leap59, tvb,
PTP_MM_GLOBAL_TIME_DATA_SET_LEAP59_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_global_time_data_set_leap61, tvb,
PTP_MM_GLOBAL_TIME_DATA_SET_LEAP61_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_global_time_data_set_epochnumber, tvb,
PTP_MM_GLOBAL_TIME_DATA_SET_EPOCHNUMBER_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_MM_UPDATE_GLOBAL_TIME_PROPERTIES:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_update_global_time_properties_currentutcoffset,
tvb, PTP_MM_UPDATE_GLOBAL_TIME_PROPERTIES_CURRENTUTCOFFSET_OFFSET,
2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_update_global_time_properties_leap59, tvb,
PTP_MM_UPDATE_GLOBAL_TIME_PROPERTIES_LEAP59_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_update_global_time_properties_leap61, tvb,
PTP_MM_UPDATE_GLOBAL_TIME_PROPERTIES_LEAP61_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_get_foreign_data_set_recordkey, tvb,
PTP_MM_UPDATE_GLOBAL_TIME_PROPERTIES_EPOCHNUMBER_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_MM_GET_FOREIGN_DATA_SET:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_get_foreign_data_set_recordkey, tvb,
PTP_MM_GET_FOREIGN_DATA_SET_RECORDKEY_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_MM_FOREIGN_DATA_SET:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_foreign_data_set_returnedportnumber, tvb,
PTP_MM_FOREIGN_DATA_SET_RETURNEDPORTNUMBER_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_foreign_data_set_returnedrecordnumber, tvb,
PTP_MM_FOREIGN_DATA_SET_RETURNEDRECORDNUMBER_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_mm_foreign_data_set_foreignmastercommunicationtechnology,
tvb, PTP_MM_FOREIGN_DATA_SET_FOREIGNMASTERCOMMUNICATIONTECHNOLOGY_OFFSET, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_foreign_data_set_foreignmasteruuidfield, tvb,
PTP_MM_FOREIGN_DATA_SET_FOREIGNMASTERUUIDFIELD_OFFSET, 6, ENC_NA);
proto_tree_add_item(ptp_tree, hf_ptp_mm_foreign_data_set_foreignmasterportidfield, tvb,
PTP_MM_FOREIGN_DATA_SET_FOREIGNMASTERPORTIDFIELD_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_mm_foreign_data_set_foreignmastersyncs, tvb,
PTP_MM_FOREIGN_DATA_SET_FOREIGNMASTERSYNCS_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_MM_SET_SYNC_INTERVAL:{
proto_tree_add_item(ptp_tree, hf_ptp_mm_set_sync_interval_syncinterval, tvb,
PTP_MM_SET_SYNC_INTERVAL_SYNCINTERVAL_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_MM_SET_TIME:{
ts.secs = tvb_get_ntohl(tvb, PTP_MM_SET_TIME_LOCALTIMESECONDS_OFFSET);
ts.nsecs = tvb_get_ntohl(tvb, PTP_MM_SET_TIME_LOCALTIMENANOSECONDS_OFFSET);
if(tree){
time_ti = proto_tree_add_time(ptp_tree, hf_ptp_mm_set_time_localtime, tvb,
PTP_MM_SET_TIME_LOCALTIME_OFFSET, 8, &ts);
ptp_time_tree = proto_item_add_subtree(time_ti, ett_ptp_time);
proto_tree_add_item(ptp_time_tree, hf_ptp_mm_set_time_localtimeseconds, tvb,
PTP_MM_SET_TIME_LOCALTIMESECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_time_tree, hf_ptp_mm_set_time_localtimenanoseconds,
tvb, PTP_MM_SET_TIME_LOCALTIMENANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
}
break;
}
default :{
break;
}
}
break;
}
default :{
break;
}
}
}
}
static void
dissect_ptp_v2_text(tvbuff_t *tvb, guint16 *cur_offset, proto_tree *tree, int hf_ptp_v2_mm_ptptext, int hf_ptp_v2_mm_ptptext_length)
{
guint8 length = 0;
proto_item *ptptext_ti;
proto_tree *ptptext_subtree;
length = tvb_get_guint8 (tvb, *cur_offset);
if (tree)
{
ptptext_ti = proto_tree_add_item(tree, hf_ptp_v2_mm_ptptext, tvb,
*cur_offset+1, length, ENC_BIG_ENDIAN);
ptptext_subtree = proto_item_add_subtree(ptptext_ti, ett_ptp_v2_ptptext);
proto_tree_add_item(ptptext_subtree, hf_ptp_v2_mm_ptptext_length, tvb,
*cur_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptptext_subtree, hf_ptp_v2_mm_ptptext, tvb,
*cur_offset+1, length, ENC_ASCII|ENC_NA);
*cur_offset = *cur_offset + length + 1;
}
}
static void
dissect_ptp_v2_timeInterval(tvbuff_t *tvb, guint16 *cur_offset, proto_tree *tree, const char* name, int hf_ptp_v2_timeInterval_ns, int hf_ptp_v2_timeInterval_subns)
{
double time_double;
gint64 time_ns;
guint16 time_subns;
proto_tree *ptptimeInterval_subtree;
time_ns = tvb_get_ntoh64(tvb, *cur_offset);
time_double = (1.0*time_ns) / 65536.0;
time_ns = time_ns >> 16;
time_subns = tvb_get_ntohs(tvb, *cur_offset+6);
ptptimeInterval_subtree = proto_tree_add_subtree_format(tree, tvb, *cur_offset, 8,
ett_ptp_v2_timeInterval, NULL, "%s: %f nanoseconds", name, time_double);
proto_tree_add_uint64_format_value(ptptimeInterval_subtree,
hf_ptp_v2_timeInterval_ns, tvb, *cur_offset, 6, time_ns, "Ns: %" G_GINT64_MODIFIER "d nanoseconds", time_ns);
proto_tree_add_double_format_value(ptptimeInterval_subtree,
hf_ptp_v2_timeInterval_subns, tvb, *cur_offset+6, 2, (time_subns/65536.0),
"%f nanoseconds", (time_subns/65536.0));
*cur_offset = *cur_offset + 8;
}
static void
dissect_ptp_v2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean ptpv2_oE)
{
guint8 ptp_v2_transport_specific;
guint8 ptp_v2_messageid;
guint64 timeStamp;
guint16 msg_len;
guint16 temp;
proto_item *ti = NULL, *msg_len_item = NULL, *transportspecific_ti, *flags_ti, *managementData_ti, *clockType_ti, *protocolAddress_ti;
proto_tree *ptp_tree = NULL, *ptp_transportspecific_tree, *ptp_flags_tree, *ptp_managementData_tree,
*ptp_clockType_tree, *ptp_protocolAddress_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PTPv2");
ptp_v2_transport_specific = 0xF0 & tvb_get_guint8 (tvb, PTP_V2_TRANSPORT_SPECIFIC_MESSAGE_ID_OFFSET);
ptp_v2_messageid = 0x0F & tvb_get_guint8 (tvb, PTP_V2_TRANSPORT_SPECIFIC_MESSAGE_ID_OFFSET);
msg_len = tvb_get_ntohs(tvb, PTP_V2_MESSAGE_LENGTH_OFFSET);
if ( ptp_v2_messageid == PTP_V2_MANAGEMENT_MESSAGE )
{
guint16 tlv_type;
tlv_type = tvb_get_ntohs (tvb, PTP_V2_MM_TLV_TYPE_OFFSET);
switch(tlv_type)
{
case PTP_V2_TLV_TYPE_MANAGEMENT:
{
guint16 ptp_v2_mm_managementId;
guint8 ptp_v2_management_action;
ptp_v2_mm_managementId = tvb_get_ntohs(tvb, PTP_V2_MM_TLV_MANAGEMENTID_OFFSET);
ptp_v2_management_action = 0x0F & tvb_get_guint8(tvb, PTP_V2_MM_ACTION_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "Management (%s) %s",
val_to_str_ext(ptp_v2_mm_managementId, &ptp_v2_managementID_infocolumn_vals_ext, "Unknown management Id %u"),
val_to_str(ptp_v2_management_action, ptp_v2_mm_action_vals, "Unknown Action %u"));
break;
}
case PTP_V2_TLV_TYPE_MANAGEMENT_ERROR_STATUS:
{
guint16 ptp_v2_mm_managementId;
ptp_v2_mm_managementId = tvb_get_ntohs(tvb, PTP_V2_MM_TLV_MANAGEMENTERRORID_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "Management Error Message (%s)",
val_to_str_ext(ptp_v2_mm_managementId, &ptp2_managementErrorId_vals_ext, "Unknown Error Id %u"));
break;
}
default:
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str_ext(ptp_v2_messageid, &ptp_v2_messageid_vals_ext, "Unknown PTP Message (%u)"));
break;
}
}
else
{
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext(ptp_v2_messageid, &ptp_v2_messageid_vals_ext, "Unknown PTP Message (%u)"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_ptp, tvb, 0, -1, ENC_NA);
ptp_tree = proto_item_add_subtree(ti, ett_ptp_v2);
transportspecific_ti = proto_tree_add_item(ptp_tree,
hf_ptp_v2_transportspecific, tvb, PTP_V2_TRANSPORT_SPECIFIC_MESSAGE_ID_OFFSET, 1, ENC_BIG_ENDIAN);
ptp_transportspecific_tree = proto_item_add_subtree(transportspecific_ti, ett_ptp_v2_transportspecific);
if (ptpv2_oE == TRUE)
{
proto_tree_add_item(ptp_transportspecific_tree,
hf_ptp_v2_transportspecific_802as_conform, tvb, PTP_V2_TRANSPORT_SPECIFIC_MESSAGE_ID_OFFSET, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ptp_transportspecific_tree,
hf_ptp_v2_transportspecific_v1_compatibility, tvb, PTP_V2_TRANSPORT_SPECIFIC_MESSAGE_ID_OFFSET, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ptp_tree,
hf_ptp_v2_messageid, tvb, PTP_V2_TRANSPORT_SPECIFIC_MESSAGE_ID_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_v2_versionptp, tvb, PTP_V2_VERSIONPTP_OFFSET, 1, ENC_BIG_ENDIAN);
msg_len_item = proto_tree_add_item(ptp_tree,
hf_ptp_v2_messagelength, tvb, PTP_V2_MESSAGE_LENGTH_OFFSET, 2, ENC_BIG_ENDIAN);
}
if (msg_len > tvb_reported_length(tvb)) {
expert_add_info(pinfo, msg_len_item, &ei_ptp_v2_msg_len_too_large);
msg_len = tvb_reported_length(tvb);
} else if (msg_len < PTP_V2_MESSAGE_LENGTH_OFFSET + 2) {
expert_add_info(pinfo, msg_len_item, &ei_ptp_v2_msg_len_too_small);
return;
} else {
set_actual_length(tvb, msg_len);
proto_item_set_len(ti, msg_len);
}
if (tree) {
proto_tree_add_item(ptp_tree,
hf_ptp_v2_domainnumber, tvb, PTP_V2_DOMAIN_NUMBER_OFFSET, 1, ENC_BIG_ENDIAN);
flags_ti = proto_tree_add_item(ptp_tree,
hf_ptp_v2_flags, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
ptp_flags_tree = proto_item_add_subtree(flags_ti, ett_ptp_v2_flags);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_security, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_specific2, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_specific1, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_unicast, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_twostep, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_alternatemaster, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_frequencytraceable, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_timetraceable, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_ptptimescale, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_utcoffsetvalid, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_li59, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_flags_tree,
hf_ptp_v2_flags_li61, tvb, PTP_V2_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
temp = PTP_V2_CORRECTIONNS_OFFSET;
dissect_ptp_v2_timeInterval(tvb, &temp, ptp_tree, "correction", hf_ptp_v2_correction, hf_ptp_v2_correctionsubns);
proto_tree_add_item(ptp_tree,
hf_ptp_v2_clockidentity, tvb, PTP_V2_CLOCKIDENTITY_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_v2_sourceportid, tvb, PTP_V2_SOURCEPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_v2_sequenceid, tvb, PTP_V2_SEQUENCEID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_v2_control, tvb, PTP_V2_CONTROL_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_v2_logmessageperiod, tvb, PTP_V2_LOGMESSAGEPERIOD_OFFSET, 1, ENC_BIG_ENDIAN);
switch(ptp_v2_messageid){
case PTP_V2_ANNOUNCE_MESSAGE:{
guint16 Offset;
guint16 tlv_type;
guint16 tlv_length;
guint16 tlv_total_length;
proto_tree *ptp_tlv_tree;
if(!(ptp_v2_transport_specific & PTP_V2_TRANSPORTSPECIFIC_ASPACKET_BITMASK)){
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_origintimestamp_seconds, tvb,
PTP_V2_AN_ORIGINTIMESTAMPSECONDS_OFFSET, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_origintimestamp_nanoseconds, tvb,
PTP_V2_AN_ORIGINTIMESTAMPNANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_origincurrentutcoffset, tvb,
PTP_V2_AN_ORIGINCURRENTUTCOFFSET_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_priority1, tvb,
PTP_V2_AN_PRIORITY_1_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_grandmasterclockclass, tvb,
PTP_V2_AN_GRANDMASTERCLOCKCLASS_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_grandmasterclockaccuracy, tvb,
PTP_V2_AN_GRANDMASTERCLOCKACCURACY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_grandmasterclockvariance, tvb,
PTP_V2_AN_GRANDMASTERCLOCKVARIANCE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_priority2, tvb,
PTP_V2_AN_PRIORITY_2_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_grandmasterclockidentity, tvb,
PTP_V2_AN_GRANDMASTERCLOCKIDENTITY_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_an_localstepsremoved, tvb,
PTP_V2_AN_LOCALSTEPSREMOVED_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree,
hf_ptp_v2_an_timesource, tvb, PTP_V2_AN_TIMESOURCE_OFFSET, 1, ENC_BIG_ENDIAN);
if (msg_len > 64)
{
tlv_total_length = 0;
while (tvb_reported_length_remaining(tvb, PTP_V2_AN_TLV_OFFSET + tlv_total_length) >= 4)
{
tlv_type = tvb_get_ntohs (tvb, PTP_V2_AN_TLV_OFFSET+tlv_total_length+PTP_V2_AN_TLV_TYPE_OFFSET);
tlv_length = tvb_get_ntohs (tvb, PTP_V2_AN_TLV_OFFSET+tlv_total_length+PTP_V2_AN_TLV_LENGTHFIELD_OFFSET);
ptp_tlv_tree = proto_tree_add_subtree_format(
ptp_tree,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length,
tlv_length + PTP_V2_AN_TLV_DATA_OFFSET,
ett_ptp_v2_tlv, NULL, "%s TLV",
val_to_str_ext(tlv_type,
&ptp_v2_TLV_type_vals_ext,
"Unknown (%u)"));
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_an_tlv_tlvtype,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_TYPE_OFFSET,
2,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_an_tlv_lengthfield,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_LENGTHFIELD_OFFSET,
2,
ENC_BIG_ENDIAN);
switch (tlv_type)
{
case PTP_V2_TLV_TYPE_ORGANIZATION_EXTENSION:
{
guint32 org_id;
guint32 subtype;
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_oe_tlv_organizationid,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_ORGANIZATIONID_OFFSET,
3,
ENC_BIG_ENDIAN);
org_id = tvb_get_ntoh24(tvb, PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_ORGANIZATIONID_OFFSET);
subtype = tvb_get_ntoh24(tvb, PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_ORGANIZATIONSUBTYPE_OFFSET);
switch (org_id)
{
case PTP_V2_OE_ORG_ID_IEEE_C37_238:
{
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_oe_tlv_organizationsubtype,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_ORGANIZATIONSUBTYPE_OFFSET,
3,
ENC_BIG_ENDIAN);
switch (subtype)
{
case PTP_V2_OE_ORG_IEEE_C37_238_SUBTYPE_C37238TLV:
{
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_oe_tlv_subtype_c37238tlv_grandmasterid,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_IEEEC37238TLV_GMID_OFFSET,
2,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_oe_tlv_subtype_c37238tlv_grandmastertimeinaccuracy,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_IEEEC37238TLV_GMINACCURACY_OFFSET,
4,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_oe_tlv_subtype_c37238tlv_networktimeinaccuracy,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_IEEEC37238TLV_NWINACCURACY_OFFSET,
4,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_oe_tlv_subtype_c37238tlv_reserved,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_IEEEC37238TLV_RESERVED_OFFSET,
2,
ENC_BIG_ENDIAN);
break;
}
default:
{
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_oe_tlv_datafield,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_DATAFIELD_OFFSET,
tlv_length - 6,
ENC_NA);
break;
}
}
break;
}
default:
{
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_oe_tlv_organizationsubtype,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_ORGANIZATIONSUBTYPE_OFFSET,
3,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_oe_tlv_datafield,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_OE_DATAFIELD_OFFSET,
tlv_length - 6,
ENC_NA);
break;
}
}
break;
}
case PTP_V2_TLV_TYPE_ALTERNATE_TIME_OFFSET_INDICATOR:
{
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_atoi_tlv_keyfield,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_ATOI_KEYFIELD_OFFSET,
1,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_atoi_tlv_currentoffset,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_ATOI_CURRENTOFFSET_OFFSET,
4,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_atoi_tlv_jumpseconds,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_ATOI_JUMPSECONDS_OFFSET,
4,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_atoi_tlv_timeofnextjump,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_ATOI_TIMEOFNEXTJUMP_OFFSET,
6,
ENC_NA);
Offset = PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_ATOI_DISPLAYNAME_OFFSET;
dissect_ptp_v2_text(tvb,
&Offset,
ptp_tlv_tree,
hf_ptp_v2_atoi_tlv_displayname,
hf_ptp_v2_atoi_tlv_displayname_length);
break;
}
case PTP_V2_TLV_TYPE_PATH_TRACE:
{
guint16 path_seq_total_length;
for(path_seq_total_length = 0; path_seq_total_length < tlv_length; path_seq_total_length+=8)
{
proto_tree_add_item(ptp_tlv_tree, hf_ptp_v2_an_tlv_pathsequence, tvb,
PTP_V2_AN_TLV_OFFSET + PTP_AS_AN_TLV_PATH_TRACE_OFFSET + path_seq_total_length,
8, ENC_BIG_ENDIAN);
}
break;
}
default:
{
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_v2_an_tlv_data,
tvb,
PTP_V2_AN_TLV_OFFSET + tlv_total_length + PTP_V2_AN_TLV_DATA_OFFSET,
tlv_length,
ENC_NA);
break;
}
}
tlv_total_length += (tlv_length + PTP_V2_AN_TLV_DATA_OFFSET);
}
}
break;
}
case PTP_V2_SYNC_MESSAGE:
case PTP_V2_DELAY_REQ_MESSAGE:{
proto_tree_add_item(ptp_tree, hf_ptp_v2_sdr_origintimestamp_seconds, tvb,
PTP_V2_SDR_ORIGINTIMESTAMPSECONDS_OFFSET, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_sdr_origintimestamp_nanoseconds, tvb,
PTP_V2_SDR_ORIGINTIMESTAMPNANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_FOLLOWUP_MESSAGE:{
guint16 tlv_length;
proto_tree *ptp_tlv_tree;
proto_tree_add_item(ptp_tree, hf_ptp_v2_fu_preciseorigintimestamp_seconds, tvb,
PTP_V2_FU_PRECISEORIGINTIMESTAMPSECONDS_OFFSET, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_fu_preciseorigintimestamp_nanoseconds, tvb,
PTP_V2_FU_PRECISEORIGINTIMESTAMPNANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
if(ptp_v2_transport_specific & PTP_V2_TRANSPORTSPECIFIC_ASPACKET_BITMASK){
tlv_length = tvb_get_ntohs (tvb, PTP_AS_FU_TLV_INFORMATION_OFFSET + PTP_AS_FU_TLV_LENGTHFIELD_OFFSET);
ptp_tlv_tree = proto_tree_add_subtree(
ptp_tree,
tvb,
PTP_AS_FU_TLV_INFORMATION_OFFSET,
tlv_length + PTP_AS_FU_TLV_ORGANIZATIONID_OFFSET,
ett_ptp_v2_tlv, NULL, "Follow Up information TLV");
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_fu_tlv_tlvtype,
tvb,
PTP_AS_FU_TLV_INFORMATION_OFFSET + PTP_AS_FU_TLV_TYPE_OFFSET,
2,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_fu_tlv_lengthfield,
tvb,
PTP_AS_FU_TLV_INFORMATION_OFFSET + PTP_AS_FU_TLV_LENGTHFIELD_OFFSET,
2,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_fu_tlv_organization_id,
tvb,
PTP_AS_FU_TLV_INFORMATION_OFFSET + PTP_AS_FU_TLV_ORGANIZATIONID_OFFSET,
3,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_fu_tlv_organization_subtype,
tvb,
PTP_AS_FU_TLV_INFORMATION_OFFSET + PTP_AS_FU_TLV_ORGANIZATIONSUBTYPE_OFFSET,
3,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_fu_tlv_cumulative_offset,
tvb,
PTP_AS_FU_TLV_INFORMATION_OFFSET + PTP_AS_FU_TLV_CUMULATIVESCALEDRATEOFFSET_OFFSET,
4,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_fu_tlv_gm_base_indicator,
tvb,
PTP_AS_FU_TLV_INFORMATION_OFFSET + PTP_AS_FU_TLV_GMTIMEBASEINDICATOR_OFFSET,
2,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_fu_tlv_last_gm_phase_change,
tvb,
PTP_AS_FU_TLV_INFORMATION_OFFSET + PTP_AS_FU_TLV_LASTGMPHASECHANGE_OFFSET,
12,
ENC_NA);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_fu_tlv_scaled_last_gm_phase_change,
tvb,
PTP_AS_FU_TLV_INFORMATION_OFFSET + PTP_AS_FU_TLV_SCALEDLASTGMFREQCHANGE_OFFSET,
4,
ENC_BIG_ENDIAN);
}
break;
}
case PTP_V2_DELAY_RESP_MESSAGE:{
proto_tree_add_item(ptp_tree, hf_ptp_v2_dr_receivetimestamp_seconds, tvb,
PTP_V2_DR_RECEIVETIMESTAMPSECONDS_OFFSET, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_dr_receivetimestamp_nanoseconds, tvb,
PTP_V2_DR_RECEIVETIMESTAMPNANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_dr_requestingportidentity, tvb,
PTP_V2_DR_REQUESTINGPORTIDENTITY_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_dr_requestingsourceportid, tvb,
PTP_V2_DR_REQUESTINGSOURCEPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_PATH_DELAY_REQ_MESSAGE:{
if(!(ptp_v2_transport_specific & PTP_V2_TRANSPORTSPECIFIC_ASPACKET_BITMASK)){
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdrq_origintimestamp_seconds, tvb,
PTP_V2_PDRQ_ORIGINTIMESTAMPSECONDS_OFFSET, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdrq_origintimestamp_nanoseconds, tvb,
PTP_V2_PDRQ_ORIGINTIMESTAMPNANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
}
break;
}
case PTP_V2_PATH_DELAY_RESP_MESSAGE:{
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdrs_requestreceipttimestamp_seconds, tvb,
PTP_V2_PDRS_REQUESTRECEIPTTIMESTAMPSECONDS_OFFSET, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdrs_requestreceipttimestamp_nanoseconds, tvb,
PTP_V2_PDRS_REQUESTRECEIPTTIMESTAMPNANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdrs_requestingportidentity, tvb,
PTP_V2_PDRS_REQUESTINGPORTIDENTITY_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdrs_requestingsourceportid, tvb,
PTP_V2_PDRS_REQUESTINGSOURCEPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_PATH_DELAY_FOLLOWUP_MESSAGE:{
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdfu_responseorigintimestamp_seconds, tvb,
PTP_V2_PDFU_RESPONSEORIGINTIMESTAMPSECONDS_OFFSET, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdfu_responseorigintimestamp_nanoseconds, tvb,
PTP_V2_PDFU_RESPONSEORIGINTIMESTAMPNANOSECONDS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdfu_requestingportidentity, tvb,
PTP_V2_PDFU_REQUESTINGPORTIDENTITY_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_pdfu_requestingsourceportid, tvb,
PTP_V2_PDFU_REQUESTINGSOURCEPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_SIGNALLING_MESSAGE:{
guint16 tlv_length;
proto_item *tlv_ti, *sig_tlv_flags_ti;
proto_tree *ptp_tlv_tree, *sig_tlv_flags_tree;
proto_tree_add_item(ptp_tree, hf_ptp_v2_sig_targetportidentity, tvb,
PTP_V2_SIG_TARGETPORTIDENTITY_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_sig_targetportid, tvb,
PTP_V2_SIG_TARGETPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
if(ptp_v2_transport_specific & PTP_V2_TRANSPORTSPECIFIC_ASPACKET_BITMASK){
tlv_length = tvb_get_ntohs (tvb, PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_LENGTHFIELD_OFFSET);
ptp_tlv_tree = proto_tree_add_subtree(
ptp_tree,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET,
tlv_length + PTP_AS_SIG_TLV_ORGANIZATIONID_OFFSET,
ett_ptp_v2_tlv, NULL, "Message Interval Request TLV");
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_sig_tlv_tlvtype,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_TYPE_OFFSET,
2,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_sig_tlv_lengthfield,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_LENGTHFIELD_OFFSET,
2,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_sig_tlv_organization_id,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_ORGANIZATIONID_OFFSET,
3,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_sig_tlv_organization_subtype,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_ORGANIZATIONSUBTYPE_OFFSET,
3,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_sig_tlv_link_delay_interval,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_LINKDELAYINTERVAL_OFFSET,
1,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_sig_tlv_time_sync_interval,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_TIMESYNCINTERVAL_OFFSET,
1,
ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_sig_tlv_announce_interval,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_ANNOUNCEINTERVAL_OFFSET,
1,
ENC_BIG_ENDIAN);
sig_tlv_flags_ti = proto_tree_add_item(ptp_tlv_tree,
hf_ptp_as_sig_tlv_flags,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_FLAGS_OFFSET,
1,
ENC_BIG_ENDIAN);
sig_tlv_flags_tree = proto_item_add_subtree(sig_tlv_flags_ti, ett_ptp_as_sig_tlv_flags);
proto_tree_add_item(sig_tlv_flags_tree,
hf_ptp_as_sig_tlv_flags_comp_rate_ratio,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_FLAGS_OFFSET,
1,
ENC_BIG_ENDIAN);
proto_tree_add_item(sig_tlv_flags_tree,
hf_ptp_as_sig_tlv_flags_comp_prop_delay,
tvb,
PTP_AS_SIG_TLV_MESSAGEINTERVALREQUEST_OFFSET + PTP_AS_SIG_TLV_FLAGS_OFFSET,
1,
ENC_BIG_ENDIAN);
} else {
guint proto_len;
guint32 tlv_offset;
guint16 tlv_type;
gint8 log_inter_message_period;
gdouble period = 0.0f;
gdouble rate = 0.0f;
guint32 duration_field;
proto_item *ptp_tlv_period;
proto_tree *ptp_tlv_period_tree;
proto_len = tvb_reported_length(tvb);
tlv_offset = PTP_V2_SIG_TLV_START;
while (tlv_offset < proto_len) {
tlv_type = tvb_get_ntohs(tvb, tlv_offset + PTP_V2_SIG_TLV_TYPE_OFFSET);
tlv_ti = proto_tree_add_item(ptp_tree, hf_ptp_v2_sig_tlv_tlvType, tvb,
tlv_offset + PTP_V2_SIG_TLV_TYPE_OFFSET, PTP_V2_SIG_TLV_TYPE_LEN, ENC_BIG_ENDIAN);
ptp_tlv_tree = proto_item_add_subtree(tlv_ti, ett_ptp_v2_tlv);
tlv_length = tvb_get_ntohs(tvb, tlv_offset + PTP_V2_SIG_TLV_LENGTH_OFFSET);
proto_tree_add_uint(ptp_tlv_tree, hf_ptp_v2_sig_tlv_lengthField, tvb,
tlv_offset + PTP_V2_SIG_TLV_LENGTH_OFFSET, PTP_V2_SIG_TLV_LENGTH_LEN, tlv_length);
switch (tlv_type) {
case PTP_V2_TLV_TYPE_REQUEST_UNICAST_TRANSMISSION:
proto_tree_add_item(ptp_tlv_tree, hf_ptp_v2_sig_tlv_messageType, tvb,
tlv_offset + PTP_V2_SIG_TLV_MESSAGE_TYPE_OFFSET, PTP_V2_SIG_TLV_MESSAGE_TYPE_LEN, ENC_BIG_ENDIAN);
log_inter_message_period = tvb_get_guint8(tvb, tlv_offset + PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_OFFSET);
period = pow(2, log_inter_message_period);
rate = 1/period;
ptp_tlv_period = proto_tree_add_item(ptp_tlv_tree, hf_ptp_v2_sig_tlv_logInterMessagePeriod, tvb,
tlv_offset + PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_OFFSET, PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_LEN, ENC_BIG_ENDIAN);
ptp_tlv_period_tree = proto_item_add_subtree(ptp_tlv_period, ett_ptp_v2_tlv_log_period);
proto_tree_add_int_format_value(ptp_tlv_period_tree, hf_ptp_v2_sig_tlv_logInterMessagePeriod_period, tvb,
tlv_offset + PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_OFFSET, PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_LEN, log_inter_message_period, "every %lg seconds", period);
proto_tree_add_int_format_value(ptp_tlv_period_tree, hf_ptp_v2_sig_tlv_logInterMessagePeriod_rate, tvb,
tlv_offset + PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_OFFSET, PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_LEN, log_inter_message_period, "%lg packets/sec", rate);
duration_field = tvb_get_ntohl(tvb, tlv_offset + PTP_V2_SIG_TLV_DURATION_FIELD_OFFSET);
proto_tree_add_uint_format_value(ptp_tlv_tree, hf_ptp_v2_sig_tlv_durationField, tvb,
tlv_offset + PTP_V2_SIG_TLV_DURATION_FIELD_OFFSET, PTP_V2_SIG_TLV_DURATION_FIELD_LEN, duration_field, "%u seconds", duration_field);
break;
case PTP_V2_TLV_TYPE_GRANT_UNICAST_TRANSMISSION:
proto_tree_add_item(ptp_tlv_tree, hf_ptp_v2_sig_tlv_messageType, tvb,
tlv_offset + PTP_V2_SIG_TLV_MESSAGE_TYPE_OFFSET, PTP_V2_SIG_TLV_MESSAGE_TYPE_LEN, ENC_BIG_ENDIAN);
log_inter_message_period = tvb_get_guint8(tvb, tlv_offset + PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_OFFSET);
period = pow(2, log_inter_message_period);
rate = 1/period;
ptp_tlv_period = proto_tree_add_item(ptp_tlv_tree, hf_ptp_v2_sig_tlv_logInterMessagePeriod, tvb,
tlv_offset + PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_OFFSET, PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_LEN, ENC_BIG_ENDIAN);
ptp_tlv_period_tree = proto_item_add_subtree(ptp_tlv_period, ett_ptp_v2_tlv_log_period);
proto_tree_add_int_format_value(ptp_tlv_period_tree, hf_ptp_v2_sig_tlv_logInterMessagePeriod_period, tvb,
tlv_offset + PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_OFFSET, PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_LEN, log_inter_message_period, "every %lg seconds", period);
proto_tree_add_int_format_value(ptp_tlv_period_tree, hf_ptp_v2_sig_tlv_logInterMessagePeriod_rate, tvb,
tlv_offset + PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_OFFSET, PTP_V2_SIG_TLV_LOG_INTER_MESSAGE_PERIOD_LEN, log_inter_message_period, "%lg packets/sec", rate);
duration_field = tvb_get_ntohl(tvb, tlv_offset + PTP_V2_SIG_TLV_DURATION_FIELD_OFFSET);
proto_tree_add_uint_format_value(ptp_tlv_tree, hf_ptp_v2_sig_tlv_durationField, tvb,
tlv_offset + PTP_V2_SIG_TLV_DURATION_FIELD_OFFSET, PTP_V2_SIG_TLV_DURATION_FIELD_LEN, duration_field, "%u seconds", duration_field);
proto_tree_add_item(ptp_tlv_tree, hf_ptp_v2_sig_tlv_renewalInvited, tvb,
tlv_offset + PTP_V2_SIG_TLV_RENEWAL_INVITED_OFFSET, PTP_V2_SIG_TLV_RENEWAL_INVITED_LEN, ENC_BIG_ENDIAN);
break;
case PTP_V2_TLV_TYPE_CANCEL_UNICAST_TRANSMISSION:
proto_tree_add_item(ptp_tlv_tree, hf_ptp_v2_sig_tlv_messageType, tvb,
tlv_offset + PTP_V2_SIG_TLV_MESSAGE_TYPE_OFFSET, PTP_V2_SIG_TLV_MESSAGE_TYPE_LEN, ENC_BIG_ENDIAN);
break;
case PTP_V2_TLV_TYPE_ACKNOWLEDGE_CANCEL_UNICAST_TRANSMISSION:
proto_tree_add_item(ptp_tlv_tree, hf_ptp_v2_sig_tlv_messageType, tvb,
tlv_offset + PTP_V2_SIG_TLV_MESSAGE_TYPE_OFFSET, PTP_V2_SIG_TLV_MESSAGE_TYPE_LEN, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(ptp_tlv_tree, hf_ptp_v2_sig_tlv_data, tvb,
tlv_offset + PTP_V2_SIG_TLV_VALUE_OFFSET, tlv_length, ENC_NA);
}
tlv_offset += PTP_V2_SIG_TLV_TYPE_LEN +
PTP_V2_SIG_TLV_LENGTH_LEN +
tlv_length;
}
}
break;
}
case PTP_V2_MANAGEMENT_MESSAGE:
{
guint16 tlv_type, tlv_length;
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_targetportidentity, tvb,
PTP_V2_MM_TARGETPORTIDENTITY_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_targetportid, tvb,
PTP_V2_MM_TARGETPORTID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_startingboundaryhops, tvb,
PTP_V2_MM_STARTINGBOUNDARYHOPS_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_boundaryhops, tvb,
PTP_V2_MM_BOUNDARYHOPS_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_action, tvb,
PTP_V2_MM_ACTION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_tlvType, tvb,
PTP_V2_MM_TLV_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_lengthField, tvb,
PTP_V2_MM_TLV_LENGTHFIELD_OFFSET, 2, ENC_BIG_ENDIAN);
tlv_type = tvb_get_ntohs (tvb, PTP_V2_MM_TLV_TYPE_OFFSET);
tlv_length = tvb_get_ntohs (tvb, PTP_V2_MM_TLV_LENGTHFIELD_OFFSET);
switch(tlv_type) {
case PTP_V2_TLV_TYPE_MANAGEMENT:
{
guint16 ptp_v2_managementId;
guint16 Offset = PTP_V2_MM_TLV_DATAFIELD_OFFSET;
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_managementId, tvb,
PTP_V2_MM_TLV_MANAGEMENTID_OFFSET, 2, ENC_BIG_ENDIAN);
ptp_v2_managementId = tvb_get_ntohs (tvb, PTP_V2_MM_TLV_MANAGEMENTID_OFFSET);
if (tlv_length <= 2)
{
break;
}
managementData_ti = proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_data, tvb, Offset, tlv_length - 2, ENC_NA);
ptp_managementData_tree = proto_item_add_subtree(managementData_ti, ett_ptp_v2_managementData);
switch(ptp_v2_managementId) {
case PTP_V2_MM_ID_NULL_MANAGEMENT:
{
break;
}
case PTP_V2_MM_ID_CLOCK_DESCRIPTION:
{
guint16 N = 0, S = 0;
clockType_ti = proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockType, tvb,
Offset, 2, ENC_BIG_ENDIAN);
ptp_clockType_tree = proto_item_add_subtree(clockType_ti, ett_ptp_v2_clockType);
proto_tree_add_item(ptp_clockType_tree, hf_ptp_v2_mm_clockType_ordinaryClock, tvb,
Offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_clockType_tree, hf_ptp_v2_mm_clockType_boundaryClock, tvb,
Offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_clockType_tree, hf_ptp_v2_mm_clockType_p2p_transparentClock, tvb,
Offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_clockType_tree, hf_ptp_v2_mm_clockType_e2e_transparentClock, tvb,
Offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_clockType_tree, hf_ptp_v2_mm_clockType_managementNode, tvb,
Offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_clockType_tree, hf_ptp_v2_mm_clockType_reserved, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
dissect_ptp_v2_text (tvb, &Offset, ptp_managementData_tree,
hf_ptp_v2_mm_physicalLayerProtocol, hf_ptp_v2_mm_physicalLayerProtocol_length);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_physicalAddressLength, tvb,
Offset, 2, ENC_BIG_ENDIAN);
S = tvb_get_ntohs (tvb, Offset);
Offset +=2;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_physicalAddress, tvb,
Offset, S, ENC_NA);
Offset += S;
N = tvb_get_ntohs (tvb, Offset+2);
protocolAddress_ti = proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_protocolAddress, tvb,
Offset+4, N, ENC_NA);
ptp_protocolAddress_tree = proto_item_add_subtree(protocolAddress_ti, ett_ptp_v2_protocolAddress);
proto_tree_add_item(ptp_protocolAddress_tree, hf_ptp_v2_mm_protocolAddress_networkProtocol, tvb,
Offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_protocolAddress_tree, hf_ptp_v2_mm_protocolAddress_length, tvb,
Offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_protocolAddress_tree, hf_ptp_v2_mm_protocolAddress, tvb,
Offset+4, N, ENC_NA);
N = N + 4;
Offset += N;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_manufacturerIdentity, tvb,
Offset, 3, ENC_NA);
Offset += 3;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 1, ENC_NA);
Offset += 1;
dissect_ptp_v2_text (tvb, &Offset, ptp_managementData_tree,
hf_ptp_v2_mm_productDescription, hf_ptp_v2_mm_productDescription_length);
dissect_ptp_v2_text (tvb, &Offset, ptp_managementData_tree,
hf_ptp_v2_mm_revisionData, hf_ptp_v2_mm_revisionData_length);
dissect_ptp_v2_text (tvb, &Offset, ptp_managementData_tree,
hf_ptp_v2_mm_userDescription, hf_ptp_v2_mm_userDescription_length);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_profileIdentity, tvb,
Offset, 6, ENC_NA);
Offset += 6;
if ( (Offset - PTP_V2_MM_TLV_DATAFIELD_OFFSET) % 2 )
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_pad, tvb,
Offset, 1, ENC_NA);
}
break;
}
case PTP_V2_MM_ID_USER_DESCRIPTION:
{
dissect_ptp_v2_text (tvb, &Offset, ptp_managementData_tree,
hf_ptp_v2_mm_userDescription, hf_ptp_v2_mm_userDescription_length);
if ( (Offset - PTP_V2_MM_TLV_DATAFIELD_OFFSET) % 2 )
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_pad, tvb,
Offset, 1, ENC_NA);
}
break;
}
case PTP_V2_MM_ID_SAVE_IN_NON_VOLATILE_STORAGE:
{
break;
}
case PTP_V2_MM_ID_RESET_NON_VOLATILE_STORAGE:
{
break;
}
case PTP_V2_MM_ID_INITIALIZE:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_initializationKey, tvb,
Offset, 2, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_MM_ID_FAULT_LOG:
{
guint16 ii, num = 0;
proto_tree *ptpError_subtree;
num = tvb_get_ntohs (tvb, Offset);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_numberOfFaultRecords, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
for (ii = 0; ii < num; ii++)
{
ptpError_subtree = proto_tree_add_subtree(ptp_managementData_tree, tvb, Offset, tvb_get_ntohs (tvb, Offset),
ett_ptp_v2_faultRecord, NULL, "Fault record");
proto_tree_add_item(ptpError_subtree, hf_ptp_v2_mm_faultRecordLength, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
proto_tree_add_item(ptpError_subtree, hf_ptp_v2_mm_faultTime_s, tvb,
Offset, 6, ENC_BIG_ENDIAN);
Offset +=6;
proto_tree_add_item(ptpError_subtree, hf_ptp_v2_mm_faultTime_ns, tvb,
Offset, 4, ENC_BIG_ENDIAN);
Offset +=4;
proto_tree_add_item(ptpError_subtree, hf_ptp_v2_mm_severityCode, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
dissect_ptp_v2_text (tvb, &Offset, ptpError_subtree,
hf_ptp_v2_mm_faultName, hf_ptp_v2_mm_faultName_length);
dissect_ptp_v2_text (tvb, &Offset, ptpError_subtree,
hf_ptp_v2_mm_faultValue, hf_ptp_v2_mm_faultValue_length);
dissect_ptp_v2_text (tvb, &Offset, ptpError_subtree,
hf_ptp_v2_mm_faultDescription, hf_ptp_v2_mm_faultDescription_length);
}
if ( (Offset - PTP_V2_MM_TLV_DATAFIELD_OFFSET) % 2 )
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_pad, tvb,
Offset, 1, ENC_NA);
}
break;
}
case PTP_V2_MM_ID_FAULT_LOG_RESET:
{
break;
}
case PTP_V2_MM_ID_DEFAULT_DATA_SET:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_TSC, tvb,
PTP_V2_MM_TLV_DATAFIELD_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_dds_SO, tvb,
PTP_V2_MM_TLV_DATAFIELD_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
PTP_V2_MM_RESERVED1, 1, ENC_NA);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_numberPorts, tvb,
PTP_V2_MM_NUMBERPORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_priority1, tvb,
PTP_V2_MM_PRIORITY1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockclass, tvb,
PTP_V2_MM_CLOCKQUALITY, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockaccuracy, tvb,
PTP_V2_MM_CLOCKQUALITY+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockvariance, tvb,
PTP_V2_MM_CLOCKQUALITY+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_priority2, tvb,
PTP_V2_MM_PRIORITY2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockidentity, tvb,
PTP_V2_MM_CLOCKIDENTITY, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_domainNumber, tvb,
PTP_V2_MM_DOMAINNUMBER, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
PTP_V2_MM_RESERVED2, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_CURRENT_DATA_SET:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_stepsRemoved, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
dissect_ptp_v2_timeInterval(tvb, &Offset, ptp_managementData_tree,
"Offset from Master", hf_ptp_v2_mm_offset_ns, hf_ptp_v2_mm_offset_subns);
dissect_ptp_v2_timeInterval(tvb, &Offset, ptp_managementData_tree,
"Mean path delay", hf_ptp_v2_mm_pathDelay_ns, hf_ptp_v2_mm_pathDelay_subns);
break;
}
case PTP_V2_MM_ID_PARENT_DATA_SET:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_parentIdentity, tvb,
Offset, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_parentPort, tvb,
Offset+8, 2, ENC_BIG_ENDIAN);
Offset +=10;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_parentStats, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 1, ENC_NA);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_observedParentOffsetScaledLogVariance, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_observedParentClockPhaseChangeRate, tvb,
Offset, 4, ENC_BIG_ENDIAN);
Offset +=4;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_grandmasterPriority1, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_grandmasterclockclass, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_grandmasterclockaccuracy, tvb,
Offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_grandmasterclockvariance, tvb,
Offset+2, 2, ENC_BIG_ENDIAN);
Offset += 4;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_grandmasterPriority2, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_grandmasterIdentity, tvb,
Offset, 8, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_MM_ID_TIME_PROPERTIES_DATA_SET:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_currentUtcOffset, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_LI_61, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_LI_59, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_UTCV, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_PTP, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_TTRA, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_FTRA, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_timesource, tvb,
Offset, 1, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_MM_ID_PORT_DATA_SET:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockidentity, tvb,
Offset, 8, ENC_BIG_ENDIAN);
Offset +=8;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_PortNumber, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_portState, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_logMinDelayReqInterval, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
dissect_ptp_v2_timeInterval(tvb, &Offset, ptp_managementData_tree,
"Peer mean path delay", hf_ptp_v2_mm_peerMeanPathDelay_ns, hf_ptp_v2_mm_peerMeanPathDelay_subns);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_logAnnounceInterval, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_announceReceiptTimeout, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_logSyncInterval, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_delayMechanism, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_logMinPdelayReqInterval, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_versionNumber, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
break;
}
case PTP_V2_MM_ID_PRIORITY1:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_priority1, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_PRIORITY2:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_priority2, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_DOMAIN:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_domainNumber, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_SLAVE_ONLY:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_SO, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_LOG_ANNOUNCE_INTERVAL:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_logAnnounceInterval, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_ANNOUNCE_RECEIPT_TIMEOUT:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_announceReceiptTimeout, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_LOG_SYNC_INTERVAL:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_logSyncInterval, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_VERSION_NUMBER:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_versionNumber, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_ENABLE_PORT:
{
break;
}
case PTP_V2_MM_ID_DISABLE_PORT:
{
break;
}
case PTP_V2_MM_ID_TIME:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_currentTime_s, tvb,
Offset, 6, ENC_BIG_ENDIAN);
Offset +=6;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_currentTime_ns, tvb,
Offset, 4, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_MM_ID_CLOCK_ACCURACY:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockAccuracy, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_UTC_PROPERTIES:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_currentUtcOffset, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_LI_61, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_LI_59, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_UTCV, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_TRACEABILITY_PROPERTIES:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_TTRA, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_FTRA, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_TIMESCALE_PROPERTIES:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_PTP, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_timesource, tvb,
Offset, 1, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_MM_ID_UNICAST_NEGOTIATION_ENABLE:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_ucEN, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_PATH_TRACE_LIST:
{
guint16 i = 0;
for (i = 0; i < (tlv_length / 8); i++)
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockidentity, tvb,
Offset, 8, ENC_BIG_ENDIAN);
}
break;
}
case PTP_V2_MM_ID_PATH_TRACE_ENABLE:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_ptEN, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_GRANDMASTER_CLUSTER_TABLE:
{
break;
}
case PTP_V2_MM_ID_UNICAST_MASTER_TABLE:
{
break;
}
case PTP_V2_MM_ID_UNICAST_MASTER_MAX_TABLE_SIZE:
{
break;
}
case PTP_V2_MM_ID_ACCEPTABLE_MASTER_TABLE:
{
break;
}
case PTP_V2_MM_ID_ACCEPTABLE_MASTER_TABLE_ENABLED:
{
break;
}
case PTP_V2_MM_ID_ACCEPTABLE_MASTER_MAX_TABLE_SIZE:
{
break;
}
case PTP_V2_MM_ID_ALTERNATE_TIME_OFFSET_ENABLE:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_keyField, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_atEN, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
break;
}
case PTP_V2_MM_ID_ALTERNATE_TIME_OFFSET_NAME:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_keyField, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
dissect_ptp_v2_text (tvb, &Offset, ptp_managementData_tree,
hf_ptp_v2_mm_displayName, hf_ptp_v2_mm_displayName_length);
if ( (Offset - PTP_V2_MM_TLV_DATAFIELD_OFFSET) % 2 )
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_pad, tvb,
Offset, 1, ENC_NA);
}
break;
}
case PTP_V2_MM_ID_ALTERNATE_TIME_OFFSET_MAX_KEY:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_maxKey, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_ALTERNATE_MASTER:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_transmitAlternateMulticastSync, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_numberOfAlternateMasters, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_logAlternateMulticastSyncInterval, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_ALTERNATE_TIME_OFFSET_PROPERTIES:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_keyField, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_currentOffset, tvb,
Offset, 4, ENC_BIG_ENDIAN);
Offset +=4;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_jumpSeconds, tvb,
Offset, 4, ENC_BIG_ENDIAN);
Offset +=4;
timeStamp = tvb_get_ntohl(tvb, Offset);
timeStamp = timeStamp << 16;
timeStamp = timeStamp | tvb_get_ntohs(tvb, Offset+4);
proto_tree_add_uint64(ptp_managementData_tree, hf_ptp_v2_mm_nextjumpSeconds, tvb,
Offset, 6, timeStamp);
Offset +=6;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_TC_DEFAULT_DATA_SET:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockidentity, tvb,
Offset, 8, ENC_BIG_ENDIAN);
Offset +=8;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_numberPorts, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_delayMechanism, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_primaryDomain, tvb,
Offset, 1, ENC_BIG_ENDIAN);
break;
}
case PTP_V2_MM_ID_TC_PORT_DATA_SET:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_clockidentity, tvb,
Offset, 8, ENC_BIG_ENDIAN);
Offset +=8;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_PortNumber, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_faultyFlag, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_logMinPdelayReqInterval, tvb,
Offset, 1, ENC_BIG_ENDIAN);
Offset +=1;
dissect_ptp_v2_timeInterval(tvb, &Offset, ptp_managementData_tree,
"Peer mean path delay", hf_ptp_v2_mm_peerMeanPathDelay_ns, hf_ptp_v2_mm_peerMeanPathDelay_subns);
break;
}
case PTP_V2_MM_ID_PRIMARY_DOMAIN:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_primaryDomain, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_DELAY_MECHANISM:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_delayMechanism, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
case PTP_V2_MM_ID_LOG_MIN_PDELAY_REQ_INTERVAL:
{
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_logMinPdelayReqInterval, tvb,
Offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ptp_managementData_tree, hf_ptp_v2_mm_reserved, tvb,
Offset+1, 1, ENC_NA);
break;
}
default:
{
break;
}
}
break;
}
case PTP_V2_TLV_TYPE_MANAGEMENT_ERROR_STATUS:
{
guint16 Offset = PTP_V2_MM_TLV_MANAGEMENTERRORID_OFFSET;
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_managementErrorId, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_managementId, tvb,
Offset, 2, ENC_BIG_ENDIAN);
Offset +=2;
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_reserved, tvb,
Offset, 4, ENC_NA);
Offset +=4;
if (Offset - PTP_V2_MM_TLV_MANAGEMENTERRORID_OFFSET + 2 < tlv_length)
{
dissect_ptp_v2_text (tvb, &Offset, ptp_tree,
hf_ptp_v2_mm_displayData, hf_ptp_v2_mm_displayData_length);
}
if ( (Offset - PTP_V2_MM_TLV_MANAGEMENTERRORID_OFFSET) % 2 )
{
proto_tree_add_item(ptp_tree, hf_ptp_v2_mm_pad, tvb,
Offset, 1, ENC_NA);
}
break;
}
default:
{
break;
}
}
}
}
}
}
void
proto_register_ptp(void)
{
static hf_register_info hf[] = {
{ &hf_ptp_versionptp,
{ "versionPTP", "ptp.versionptp",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_versionnetwork,
{ "versionNetwork", "ptp.versionnetwork",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_subdomain,
{ "subdomain", "ptp.subdomain",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_messagetype,
{ "messageType", "ptp.messagetype",
FT_UINT8, BASE_DEC, VALS(ptp_messagetype_vals), 0x00,
NULL, HFILL }
},
{ &hf_ptp_sourcecommunicationtechnology,
{ "sourceCommunicationTechnology", "ptp.sourcecommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sourceuuid,
{ "sourceUuid", "ptp.sourceuuid",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sourceportid,
{ "sourcePortId", "ptp.sourceportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sequenceid,
{ "sequenceId", "ptp.sequenceid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_control,
{ "control", "ptp.control",
FT_UINT8, BASE_DEC, VALS(ptp_control_vals), 0x00,
NULL, HFILL }
},
{ &hf_ptp_flags,
{ "flags", "ptp.flags",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_flags_li61,
{ "PTP_LI61", "ptp.flags.li61",
FT_BOOLEAN, 16, NULL, PTP_FLAGS_LI61_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_flags_li59,
{ "PTP_LI59", "ptp.flags.li59",
FT_BOOLEAN, 16, NULL, PTP_FLAGS_LI59_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_flags_boundary_clock,
{ "PTP_BOUNDARY_CLOCK", "ptp.flags.boundary_clock",
FT_BOOLEAN, 16, NULL, PTP_FLAGS_BOUNDARY_CLOCK_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_flags_assist,
{ "PTP_ASSIST", "ptp.flags.assist",
FT_BOOLEAN, 16, NULL, PTP_FLAGS_ASSIST_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_flags_ext_sync,
{ "PTP_EXT_SYNC", "ptp.flags.ext_sync",
FT_BOOLEAN, 16, NULL, PTP_FLAGS_EXT_SYNC_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_flags_parent,
{ "PTP_PARENT_STATS", "ptp.flags.parent_stats",
FT_BOOLEAN, 16, NULL, PTP_FLAGS_PARENT_STATS_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_flags_sync_burst,
{ "PTP_SYNC_BURST", "ptp.flags.sync_burst",
FT_BOOLEAN, 16, NULL, PTP_FLAGS_SYNC_BURST_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_sdr_origintimestamp,
{ "originTimestamp", "ptp.sdr.origintimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_origintimestamp_seconds,
{ "originTimestamp (seconds)", "ptp.sdr.origintimestamp_seconds",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_origintimestamp_nanoseconds,
{ "originTimestamp (nanoseconds)", "ptp.sdr.origintimestamp_nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_epochnumber,
{ "epochNumber", "ptp.sdr.epochnumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_currentutcoffset,
{ "currentUTCOffset", "ptp.sdr.currentutcoffset",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_grandmastercommunicationtechnology,
{ "grandmasterCommunicationTechnology", "ptp.sdr.grandmastercommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_grandmasterclockuuid,
{ "grandMasterClockUuid", "ptp.sdr.grandmasterclockuuid",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_grandmasterportid,
{ "grandmasterPortId", "ptp.sdr.grandmasterportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_grandmastersequenceid,
{ "grandmasterSequenceId", "ptp.sdr.grandmastersequenceid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_grandmasterclockstratum,
{ "grandmasterClockStratum", "ptp.sdr.grandmasterclockstratum",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_grandmasterclockidentifier,
{ "grandmasterClockIdentifier", "ptp.sdr.grandmasterclockidentifier",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_grandmasterclockvariance,
{ "grandmasterClockVariance", "ptp.sdr.grandmasterclockvariance",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_grandmasterpreferred,
{ "grandmasterPreferred", "ptp.sdr.grandmasterpreferred",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_grandmasterisboundaryclock,
{ "grandmasterIsBoundaryClock", "ptp.sdr.grandmasterisboundaryclock",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_syncinterval,
{ "syncInterval", "ptp.sdr.syncinterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_localclockvariance,
{ "localClockVariance", "ptp.sdr.localclockvariance",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_localstepsremoved,
{ "localStepsRemoved", "ptp.sdr.localstepsremoved",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_localclockstratum,
{ "localClockStratum", "ptp.sdr.localclockstratum",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_localclockidentifier,
{ "localClockIdentifier", "ptp.sdr.localclockidentifier",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_parentcommunicationtechnology,
{ "parentCommunicationTechnology", "ptp.sdr.parentcommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_parentuuid,
{ "parentUuid", "ptp.sdr.parentuuid",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_parentportfield,
{ "parentPortField", "ptp.sdr.parentportfield",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_estimatedmastervariance,
{ "estimatedMasterVariance", "ptp.sdr.estimatedmastervariance",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_estimatedmasterdrift,
{ "estimatedMasterDrift", "ptp.sdr.estimatedmasterdrift",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_sdr_utcreasonable,
{ "utcReasonable", "ptp.sdr.utcreasonable",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_fu_associatedsequenceid,
{ "associatedSequenceId", "ptp.fu.associatedsequenceid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_fu_preciseorigintimestamp,
{ "preciseOriginTimestamp", "ptp.fu.preciseorigintimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_fu_preciseorigintimestamp_seconds,
{ "preciseOriginTimestamp (seconds)", "ptp.fu.preciseorigintimestamp_seconds",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_fu_preciseorigintimestamp_nanoseconds,
{ "preciseOriginTimestamp (nanoseconds)", "ptp.fu.preciseorigintimestamp_nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_dr_delayreceipttimestamp,
{ "delayReceiptTimestamp", "ptp.dr.delayreceipttimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_dr_delayreceipttimestamp_seconds,
{ "delayReceiptTimestamp (Seconds)", "ptp.dr.delayreceipttimestamp_seconds",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_dr_delayreceipttimestamp_nanoseconds,
{ "delayReceiptTimestamp (nanoseconds)", "ptp.dr.delayreceipttimestamp_nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_dr_requestingsourcecommunicationtechnology,
{ "requestingSourceCommunicationTechnology", "ptp.dr.requestingsourcecommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_dr_requestingsourceuuid,
{ "requestingSourceUuid", "ptp.dr.requestingsourceuuid",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_dr_requestingsourceportid,
{ "requestingSourcePortId", "ptp.dr.requestingsourceportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_dr_requestingsourcesequenceid,
{ "requestingSourceSequenceId", "ptp.dr.requestingsourcesequenceid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_targetcommunicationtechnology,
{ "targetCommunicationTechnology", "ptp.mm.targetcommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_targetuuid,
{ "targetUuid", "ptp.mm.targetuuid",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_targetportid,
{ "targetPortId", "ptp.mm.targetportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_startingboundaryhops,
{ "startingBoundaryHops", "ptp.mm.startingboundaryhops",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_boundaryhops,
{ "boundaryHops", "ptp.mm.boundaryhops",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_managementmessagekey,
{ "managementMessageKey", "ptp.mm.managementmessagekey",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_managementMessageKey_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parameterlength,
{ "parameterLength", "ptp.mm.parameterlength",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_mm_messageparameters,
{ "messageParameters", "ptp.mm.messageparameters",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_mm_clock_identity_clockcommunicationtechnology,
{ "clockCommunicationTechnology", "ptp.mm.clock.identity.clockcommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_clock_identity_clockuuidfield,
{ "clockUuidField", "ptp.mm.clock.identity.clockuuidfield",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_clock_identity_clockportfield,
{ "clockPortField", "ptp.mm.clock.identity.clockportfield",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_clock_identity_manufactureridentity,
{ "manufacturerIdentity", "ptp.mm.clock.identity.manufactureridentity",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_initialize_clock_initialisationkey,
{ "initialisationKey", "ptp.mm.initialize.clock.initialisationkey",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_set_subdomain_subdomainname,
{ "subdomainName", "ptp.mm.set.subdomain.subdomainname",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_clockcommunicationtechnology,
{ "clockCommunicationTechnology", "ptp.mm.default.data.set.clockcommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_clockuuidfield,
{ "clockUuidField", "ptp.mm.default.data.set.clockuuidfield",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_clockportfield,
{ "clockPortField", "ptp.mm.default.data.set.clockportfield",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_clockstratum,
{ "clockStratum", "ptp.mm.default.data.set.clockstratum",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_clockidentifier,
{ "clockIdentifier", "ptp.mm.default.data.set.clockidentifier",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_clockvariance,
{ "clockVariance", "ptp.mm.default.data.set.clockvariance",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_clockfollowupcapable,
{ "clockFollowupCapable", "ptp.mm.default.data.set.clockfollowupcapable",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_preferred,
{ "preferred", "ptp.mm.default.data.set.preferred",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_initializable,
{ "initializable", "ptp.mm.default.data.set.initializable",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_externaltiming,
{ "externalTiming", "ptp.mm.default.data.set.externaltiming",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_isboundaryclock,
{ "isBoundaryClock", "ptp.mm.default.data.set.isboundaryclock",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_syncinterval,
{ "syncInterval", "ptp.mm.default.data.set.syncinterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_subdomainname,
{ "subDomainName", "ptp.mm.default.data.set.subdomainname",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_numberports,
{ "numberPorts", "ptp.mm.default.data.set.numberports",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_default_data_set_numberforeignrecords,
{ "numberForeignRecords", "ptp.mm.default.data.set.numberforeignrecords",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_update_default_data_set_clockstratum,
{ "clockStratum", "ptp.mm.update.default.data.set.clockstratum",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_update_default_data_set_clockidentifier,
{ "clockIdentifier", "ptp.mm.update.default.data.set.clockidentifier",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_update_default_data_set_clockvariance,
{ "clockVariance", "ptp.mm.update.default.data.set.clockvariance",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_update_default_data_set_preferred,
{ "preferred", "ptp.mm.update.default.data.set.preferred",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_update_default_data_set_syncinterval,
{ "syncInterval", "ptp.mm.update.default.data.set.syncinterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_update_default_data_set_subdomainname,
{ "subdomainName", "ptp.mm.update.default.data.set.subdomainname",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_current_data_set_stepsremoved,
{ "stepsRemoved", "ptp.mm.current.data.set.stepsremoved",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_current_data_set_offsetfrommaster,
{ "offsetFromMaster", "ptp.mm.current.data.set.offsetfrommaster",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_current_data_set_offsetfrommasterseconds,
{ "offsetFromMasterSeconds", "ptp.mm.current.data.set.offsetfrommasterseconds",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_current_data_set_offsetfrommasternanoseconds,
{ "offsetFromMasterNanoseconds", "ptp.mm.current.data.set.offsetfrommasternanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_current_data_set_onewaydelay,
{ "oneWayDelay", "ptp.mm.current.data.set.onewaydelay",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_current_data_set_onewaydelayseconds,
{ "oneWayDelaySeconds", "ptp.mm.current.data.set.onewaydelayseconds",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_current_data_set_onewaydelaynanoseconds,
{ "oneWayDelayNanoseconds", "ptp.mm.current.data.set.onewaydelaynanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_parentcommunicationtechnology,
{ "parentCommunicationTechnology", "ptp.mm.parent.data.set.parentcommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_parentuuid,
{ "parentUuid", "ptp.mm.parent.data.set.parentuuid",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_parentportid,
{ "parentPortId", "ptp.mm.parent.data.set.parentportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_parentlastsyncsequencenumber,
{ "parentLastSyncSequenceNumber", "ptp.mm.parent.data.set.parentlastsyncsequencenumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_parentfollowupcapable,
{ "parentFollowupCapable", "ptp.mm.parent.data.set.parentfollowupcapable",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_parentexternaltiming,
{ "parentExternalTiming", "ptp.mm.parent.data.set.parentexternaltiming",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_parentvariance,
{ "parentVariance", "ptp.mm.parent.data.set.parentvariance",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_parentstats,
{ "parentStats", "ptp.mm.parent.data.set.parentstats",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_observedvariance,
{ "observedVariance", "ptp.mm.parent.data.set.observedvariance",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_observeddrift,
{ "observedDrift", "ptp.mm.parent.data.set.observeddrift",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_utcreasonable,
{ "utcReasonable", "ptp.mm.parent.data.set.utcreasonable",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_grandmastercommunicationtechnology,
{ "grandmasterCommunicationTechnology", "ptp.mm.parent.data.set.grandmastercommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_grandmasteruuidfield,
{ "grandmasterUuidField", "ptp.mm.parent.data.set.grandmasteruuidfield",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_grandmasterportidfield,
{ "grandmasterPortIdField", "ptp.mm.parent.data.set.grandmasterportidfield",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_grandmasterstratum,
{ "grandmasterStratum", "ptp.mm.parent.data.set.grandmasterstratum",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_grandmasteridentifier,
{ "grandmasterIdentifier", "ptp.mm.parent.data.set.grandmasteridentifier",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_grandmastervariance,
{ "grandmasterVariance", "ptp.mm.parent.data.set.grandmastervariance",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_grandmasterpreferred,
{ "grandmasterPreferred", "ptp.mm.parent.data.set.grandmasterpreferred",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_grandmasterisboundaryclock,
{ "grandmasterIsBoundaryClock", "ptp.mm.parent.data.set.grandmasterisboundaryclock",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_parent_data_set_grandmastersequencenumber,
{ "grandmasterSequenceNumber", "ptp.mm.parent.data.set.grandmastersequencenumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_returnedportnumber,
{ "returnedPortNumber", "ptp.mm.port.data.set.returnedportnumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_portstate,
{ "portState", "ptp.mm.port.data.set.portstate",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_lastsynceventsequencenumber,
{ "lastSyncEventSequenceNumber", "ptp.mm.port.data.set.lastsynceventsequencenumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_lastgeneraleventsequencenumber,
{ "lastGeneralEventSequenceNumber", "ptp.mm.port.data.set.lastgeneraleventsequencenumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_portcommunicationtechnology,
{ "portCommunicationTechnology", "ptp.mm.port.data.set.portcommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_portuuidfield,
{ "portUuidField", "ptp.mm.port.data.set.portuuidfield",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_portidfield,
{ "portIdField", "ptp.mm.port.data.set.portidfield",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_burstenabled,
{ "burstEnabled", "ptp.mm.port.data.set.burstenabled",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_subdomainaddressoctets,
{ "subdomainAddressOctets", "ptp.mm.port.data.set.subdomainaddressoctets",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_eventportaddressoctets,
{ "eventPortAddressOctets", "ptp.mm.port.data.set.eventportaddressoctets",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_generalportaddressoctets,
{ "generalPortAddressOctets", "ptp.mm.port.data.set.generalportaddressoctets",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_subdomainaddress,
{ "subdomainAddress", "ptp.mm.port.data.set.subdomainaddress",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_eventportaddress,
{ "eventPortAddress", "ptp.mm.port.data.set.eventportaddress",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_port_data_set_generalportaddress,
{ "generalPortAddress", "ptp.mm.port.data.set.generalportaddress",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_global_time_data_set_localtime,
{ "localTime", "ptp.mm.global.time.data.set.localtime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_global_time_data_set_localtimeseconds,
{ "localTimeSeconds", "ptp.mm.global.time.data.set.localtimeseconds",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_global_time_data_set_localtimenanoseconds,
{ "localTimeNanoseconds", "ptp.mm.global.time.data.set.localtimenanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_global_time_data_set_currentutcoffset,
{ "currentUtcOffset", "ptp.mm.global.time.data.set.currentutcoffset",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_global_time_data_set_leap59,
{ "leap59", "ptp.mm.global.time.data.set.leap59",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_global_time_data_set_leap61,
{ "leap61", "ptp.mm.global.time.data.set.leap61",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_global_time_data_set_epochnumber,
{ "epochNumber", "ptp.mm.global.time.data.set.epochnumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_update_global_time_properties_currentutcoffset,
{ "currentUtcOffset", "ptp.mm.update.global.time.properties.currentutcoffset",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_update_global_time_properties_leap59,
{ "leap59", "ptp.mm.update.global.time.properties.leap59",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_mm_update_global_time_properties_leap61,
{ "leap61", "ptp.mm.update.global.time.properties.leap61",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_ptp_mm_update_global_time_properties_epochnumber,
{ "epochNumber", "ptp.mm.update.global.time.properties.epochnumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_mm_get_foreign_data_set_recordkey,
{ "recordKey", "ptp.mm.get.foreign.data.set.recordkey",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_foreign_data_set_returnedportnumber,
{ "returnedPortNumber", "ptp.mm.foreign.data.set.returnedportnumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_foreign_data_set_returnedrecordnumber,
{ "returnedRecordNumber", "ptp.mm.foreign.data.set.returnedrecordnumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_foreign_data_set_foreignmastercommunicationtechnology,
{ "foreignMasterCommunicationTechnology",
"ptp.mm.foreign.data.set.foreignmastercommunicationtechnology",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp_communicationid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_foreign_data_set_foreignmasteruuidfield,
{ "foreignMasterUuidField", "ptp.mm.foreign.data.set.foreignmasteruuidfield",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_foreign_data_set_foreignmasterportidfield,
{ "foreignMasterPortIdField", "ptp.mm.foreign.data.set.foreignmasterportidfield",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_foreign_data_set_foreignmastersyncs,
{ "foreignMasterSyncs", "ptp.mm.foreign.data.set.foreignmastersyncs",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_set_sync_interval_syncinterval,
{ "syncInterval", "ptp.mm.set.sync.interval.syncinterval",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_set_time_localtime,
{ "localtime", "ptp.mm.set.time.localtime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_set_time_localtimeseconds,
{ "localtimeSeconds", "ptp.mm.set.time.localtimeseconds",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_mm_set_time_localtimenanoseconds,
{ "localTimeNanoseconds", "ptp.mm.set.time.localtimenanoseconds",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_v2_transportspecific,
{ "transportSpecific", "ptp.v2.transportspecific",
FT_UINT8, BASE_HEX, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_ptp_v2_transportspecific_v1_compatibility,
{ "V1 Compatibility", "ptp.v2.transportspecific.v1compatibility",
FT_BOOLEAN, 8, NULL, PTP_V2_TRANSPORTSPECIFIC_V1COMPATIBILITY_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_transportspecific_802as_conform,
{ "802.1as conform", "ptp.v2.transportspecific.802.1asconform",
FT_BOOLEAN, 8, NULL, PTP_V2_TRANSPORTSPECIFIC_V1COMPATIBILITY_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_messageid,
{ "messageId", "ptp.v2.messageid",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ptp_v2_messageid_vals_ext, 0x0F,
NULL, HFILL }
},
{ &hf_ptp_v2_versionptp,
{ "versionPTP", "ptp.v2.versionptp",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_ptp_v2_messagelength,
{ "messageLength", "ptp.v2.messagelength",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_domainnumber,
{ "subdomainNumber", "ptp.v2.subdomainnumber",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_flags,
{ "flags", "ptp.v2.flags",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_alternatemaster,
{ "PTP_ALTERNATE_MASTER", "ptp.v2.flags.alternatemaster",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_ALTERNATE_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_twostep,
{ "PTP_TWO_STEP", "ptp.v2.flags.twostep",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_TWO_STEP_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_unicast,
{ "PTP_UNICAST", "ptp.v2.flags.unicast",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_UNICAST_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_specific1,
{ "PTP profile Specific 1", "ptp.v2.flags.specific1",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_SPECIFIC1_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_specific2,
{ "PTP profile Specific 2", "ptp.v2.flags.specific2",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_SPECIFIC2_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_security,
{ "PTP_SECURITY", "ptp.v2.flags.security",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_SECURITY_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_li61,
{ "PTP_LI_61", "ptp.v2.flags.li61",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_LI61_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_li59,
{ "PTP_LI_59", "ptp.v2.flags.li59",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_LI59_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_utcoffsetvalid,
{ "PTP_UTC_REASONABLE", "ptp.v2.flags.utcreasonable",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_UTC_OFFSET_VALID_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_ptptimescale,
{ "PTP_TIMESCALE", "ptp.v2.flags.timescale",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_PTP_TIMESCALE_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_timetraceable,
{ "TIME_TRACEABLE", "ptp.v2.flags.timetraceable",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_TIME_TRACEABLE_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_flags_frequencytraceable,
{ "FREQUENCY_TRACEABLE", "ptp.v2.flags.frequencytraceable",
FT_BOOLEAN, 16, NULL, PTP_V2_FLAGS_FREQUENCY_TRACEABLE_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_correction,
{ "correction", "ptp.v2.correction.ns",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_correctionsubns,
{ "correctionSubNs", "ptp.v2.correction.subns",
FT_DOUBLE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_clockidentity,
{ "ClockIdentity", "ptp.v2.clockidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sourceportid,
{ "SourcePortID", "ptp.v2.sourceportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sequenceid,
{ "sequenceId", "ptp.v2.sequenceid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_control,
{ "control", "ptp.v2.control",
FT_UINT8, BASE_DEC, VALS(ptp_control_vals), 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_logmessageperiod,
{ "logMessagePeriod", "ptp.v2.logmessageperiod",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_v2_an_origintimestamp,
{ "originTimestamp", "ptp.v2.an.origintimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_v2_an_origintimestamp_seconds,
{ "originTimestamp (seconds)", "ptp.v2.an.origintimestamp.seconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_origintimestamp_nanoseconds,
{ "originTimestamp (nanoseconds)", "ptp.v2.an.origintimestamp.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_origincurrentutcoffset,
{ "originCurrentUTCOffset", "ptp.v2.an.origincurrentutcoffset",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_timesource,
{ "TimeSource", "ptp.v2.timesource",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ptp_v2_timesource_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_localstepsremoved,
{ "localStepsRemoved", "ptp.v2.an.localstepsremoved",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_grandmasterclockidentity,
{ "grandmasterClockIdentity", "ptp.v2.an.grandmasterclockidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_grandmasterclockclass,
{ "grandmasterClockClass", "ptp.v2.an.grandmasterclockclass",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_grandmasterclockaccuracy,
{ "grandmasterClockAccuracy", "ptp.v2.an.grandmasterclockaccuracy",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ptp_v2_clockaccuracy_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_grandmasterclockvariance,
{ "grandmasterClockVariance", "ptp.v2.an.grandmasterclockvariance",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_priority1,
{ "priority1", "ptp.v2.an.priority1",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_priority2,
{ "priority2", "ptp.v2.an.priority2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_tlv_tlvtype,
{ "tlvType", "ptp.v2.an.tlvType",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ptp_v2_TLV_type_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_tlv_lengthfield,
{ "lengthField", "ptp.v2.an.lengthField",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_oe_tlv_organizationid,
{ "organizationId", "ptp.v2.an.oe.organizationId",
FT_UINT24, BASE_HEX, VALS(ptp2_organizationExtensionOrgId_vals), 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_oe_tlv_organizationsubtype,
{ "organizationSubType", "ptp.v2.an.oe.organizationSubType",
FT_UINT24, BASE_HEX, VALS(ptp2_org_iee_c37_238_subtype_vals), 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_oe_tlv_datafield,
{ "dataField", "ptp.v2.an.oe.dataField",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_oe_tlv_subtype_c37238tlv_grandmasterid,
{ "grandmasterID", "ptp.v2.an.oe.grandmasterID",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_oe_tlv_subtype_c37238tlv_grandmastertimeinaccuracy,
{ "grandmasterTimeInaccuracy (nanoseconds)", "ptp.v2.an.oe.grandmasterTimeInaccuracy",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_oe_tlv_subtype_c37238tlv_networktimeinaccuracy,
{ "networkTimeInaccuracy (nanoseconds)", "ptp.v2.an.oe.networkTimeInaccuracy",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_oe_tlv_subtype_c37238tlv_reserved,
{ "reserved", "ptp.v2.an.oe.reserved",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_atoi_tlv_keyfield,
{ "keyField", "ptp.v2.an.atoi.keyField",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_atoi_tlv_currentoffset,
{ "currentOffset", "ptp.v2.an.atoi.currentOffset",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_atoi_tlv_jumpseconds,
{ "jumpSeconds", "ptp.v2.an.atoi.jumpSeconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_atoi_tlv_timeofnextjump,
{ "timeOfNextJump", "ptp.v2.an.atoi.timeOfNextJump",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_atoi_tlv_displayname,
{ "displayName", "ptp.v2.an.atoi.dislpayName",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_atoi_tlv_displayname_length,
{ "length", "ptp.v2.an.atoi.dislpayName.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_tlv_pathsequence,
{ "PathSequence", "ptp.v2.an.pathsequence",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_an_tlv_data,
{ "data", "ptp.v2.an.tlv.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_v2_sdr_origintimestamp,
{ "originTimestamp", "ptp.v2.sdr.origintimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_v2_sdr_origintimestamp_seconds,
{ "originTimestamp (seconds)", "ptp.v2.sdr.origintimestamp.seconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sdr_origintimestamp_nanoseconds,
{ "originTimestamp (nanoseconds)", "ptp.v2.sdr.origintimestamp.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_v2_fu_preciseorigintimestamp,
{ "preciseOriginTimestamp", "ptp.v2.fu.preciseorigintimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_v2_fu_preciseorigintimestamp_seconds,
{ "preciseOriginTimestamp (seconds)", "ptp.v2.fu.preciseorigintimestamp.seconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_fu_preciseorigintimestamp_nanoseconds,
{ "preciseOriginTimestamp (nanoseconds)", "ptp.v2.fu.preciseorigintimestamp.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_fu_tlv_tlvtype,
{ "tlvType", "ptp.as.fu.tlvType",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ptp_v2_TLV_type_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_fu_tlv_lengthfield,
{ "lengthField", "ptp.as.fu.lengthField",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_fu_tlv_organization_id,
{ "organizationId", "ptp.as.fu.organizationId",
FT_UINT24, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_fu_tlv_organization_subtype,
{ "OrganizationSubType", "ptp.as.fu.organizationSubType",
FT_INT24, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_fu_tlv_cumulative_offset,
{ "cumulativeScaledRateOffset", "ptp.as.fu.cumulativeScaledRateOffset",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_fu_tlv_gm_base_indicator,
{ "gmTimeBaseIndicator", "ptp.as.fu.gmTimeBaseIndicator",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_fu_tlv_last_gm_phase_change,
{ "lastGMPhaseChange", "ptp.as.fu.lastGmPhaseChange",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_fu_tlv_scaled_last_gm_phase_change,
{ "scaledLastGMPhaseChange", "ptp.as.fu.scaledLastGmPhaseChange",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_v2_dr_receivetimestamp,
{ "receiveTimestamp", "ptp.v2.dr.receivetimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_v2_dr_receivetimestamp_seconds,
{ "receiveTimestamp (seconds)", "ptp.v2.dr.receivetimestamp.seconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_dr_receivetimestamp_nanoseconds,
{ "receiveTimestamp (nanoseconds)", "ptp.v2.dr.receivetimestamp.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_dr_requestingportidentity,
{ "requestingSourcePortIdentity", "ptp.v2.dr.requestingsourceportidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_dr_requestingsourceportid,
{ "requestingSourcePortId", "ptp.v2.dr.requestingsourceportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_v2_pdrq_origintimestamp,
{ "originTimestamp", "ptp.v2.pdrq.origintimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_v2_pdrq_origintimestamp_seconds,
{ "originTimestamp (seconds)", "ptp.v2.pdrq.origintimestamp.seconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_pdrq_origintimestamp_nanoseconds,
{ "originTimestamp (nanoseconds)", "ptp.v2.pdrq.origintimestamp.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_v2_pdrs_requestreceipttimestamp,
{ "requestreceiptTimestamp", "ptp.v2.pdrs.requestreceipttimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_v2_pdrs_requestreceipttimestamp_seconds,
{ "requestreceiptTimestamp (seconds)", "ptp.v2.pdrs.requestreceipttimestamp.seconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_pdrs_requestreceipttimestamp_nanoseconds,
{ "requestreceiptTimestamp (nanoseconds)", "ptp.v2.pdrs.requestreceipttimestamp.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_pdrs_requestingportidentity,
{ "requestingSourcePortIdentity", "ptp.v2.pdrs.requestingportidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_pdrs_requestingsourceportid,
{ "requestingSourcePortId", "ptp.v2.pdrs.requestingsourceportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_v2_pdfu_responseorigintimestamp,
{ "responseOriginTimestamp", "ptp.v2.pdfu.responseorigintimestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_v2_pdfu_responseorigintimestamp_seconds,
{ "responseOriginTimestamp (seconds)", "ptp.v2.pdfu.responseorigintimestamp.seconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_pdfu_responseorigintimestamp_nanoseconds,
{ "responseOriginTimestamp (nanoseconds)", "ptp.v2.pdfu.responseorigintimestamp.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_pdfu_requestingportidentity,
{ "requestingSourcePortIdentity", "ptp.v2.pdfu.requestingportidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_pdfu_requestingsourceportid,
{ "requestingSourcePortId", "ptp.v2.pdfu.requestingsourceportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_targetportidentity,
{ "targetPortIdentity", "ptp.v2.sig.targetportidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_targetportid,
{ "targetPortId", "ptp.v2.sig.targetportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_tlv_tlvType,
{ "tlvType", "ptp.v2.sig.tlv.tlvType",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ptp_v2_TLV_type_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_tlv_lengthField,
{ "lengthField", "ptp.v2.sig.tlv.lengthField",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_tlv_data,
{ "data", "ptp.v2.sig.tlv.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_tlv_messageType,
{ "messageType", "ptp.v2.sig.tlv.messageType",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ptp_v2_messageid_vals_ext, 0xF0,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_tlv_logInterMessagePeriod,
{ "logInterMessagePeriod", "ptp.v2.sig.tlv.logInterMessagePeriod",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_tlv_logInterMessagePeriod_period,
{ "period", "ptp.v2.sig.tlv.logInterMessagePeriod.period",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_tlv_logInterMessagePeriod_rate,
{ "rate", "ptp.v2.sig.tlv.logInterMessagePeriod.rate",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_tlv_durationField,
{ "durationField", "ptp.v2.sig.tlv.durationField",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_sig_tlv_renewalInvited,
{ "renewalInvited", "ptp.v2.sig.tlv.renewalInvited",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_tlvtype,
{ "tlvType", "ptp.as.sig.tlvType",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ptp_v2_TLV_type_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_lengthfield,
{ "lengthField", "ptp.as.sig.lengthField",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_organization_id,
{ "organizationId", "ptp.as.sig.tlv.organizationId",
FT_UINT24, BASE_HEX, VALS(ptp_as_TLV_oid_vals), 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_organization_subtype,
{ "OrganizationSubType", "ptp.as.sig.tlv.organizationSubType",
FT_INT24, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_link_delay_interval,
{ "linkDelayInterval", "ptp.as.sig.tlv.linkdelayinterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_time_sync_interval,
{ "timeSyncInterval", "ptp.as.sig.tlv.timesyncinterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_announce_interval,
{ "announceInterval", "ptp.as.sig.tlv.announceinterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_flags,
{ "flags", "ptp.as.sig.tvl.flags",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_flags_comp_rate_ratio,
{ "computeNeighborRateRatio", "ptp.as.sig.tlv.flags.rateratio",
FT_BOOLEAN, 8, NULL, PTP_AS_FLAGS_COMP_NEIGHBOR_RATE_RATIO_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_as_sig_tlv_flags_comp_prop_delay,
{ "computeNeighborPropDelay", "ptp.as.sig.tlv.flags.propdelay",
FT_BOOLEAN, 8, NULL, PTP_AS_FLAGS_COMP_NEIGHBOR_PROP_DELAY_BITMASK,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_targetportidentity,
{ "targetPortIdentity", "ptp.v2.mm.targetportidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_targetportid,
{ "targetPortId", "ptp.v2.mm.targetportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_startingboundaryhops,
{ "startingBoundaryHops", "ptp.v2.mm.startingboundaryhops",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_boundaryhops,
{ "boundaryHops", "ptp.v2.mm.boundaryhops",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_action,
{ "action", "ptp.v2.mm.action",
FT_UINT8, BASE_DEC, VALS(ptp_v2_mm_action_vals), 0x0F,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_tlvType,
{ "tlvType", "ptp.v2.mm.tlvType",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ptp_v2_TLV_type_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_lengthField,
{ "lengthField", "ptp.v2.mm.lengthField",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_managementId,
{ "managementId", "ptp.v2.mm.managementId",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ptp_v2_managementID_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_data,
{ "data", "ptp.v2.mm.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockType,
{ "clockType", "ptp.v2.mm.clockType",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockType_ordinaryClock,
{ "The node implements an ordinary clock", "ptp.v2.mm.clockType.OC",
FT_BOOLEAN, 16, NULL, CLOCKTYPE_ORDINARY_CLOCK,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockType_boundaryClock,
{ "The node implements a boundary clock", "ptp.v2.mm.clockType.BC",
FT_BOOLEAN, 16, NULL, CLOCKTYPE_BOUNDARY_CLOCK,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockType_p2p_transparentClock,
{ "The node implements a peer-to-peer transparent clock", "ptp.v2.mm.clockType.p2p_TC",
FT_BOOLEAN, 16, NULL, CLOCKTYPE_P2P_TC,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockType_e2e_transparentClock,
{ "The node implements an end-to-end transparent clock", "ptp.v2.mm.clockType.e2e_TC",
FT_BOOLEAN, 16, NULL, CLOCKTYPE_E2E_TC,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockType_managementNode,
{ "The node implements a management node", "ptp.v2.mm.clockType.MM",
FT_BOOLEAN, 16, NULL, CLOCKTYPE_MANAGEMENT_NODE,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockType_reserved,
{ "Reserved", "ptp.v2.mm.clockType.reserved",
FT_BOOLEAN, 16, NULL, CLOCKTYPE_RESERVED,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_physicalLayerProtocol,
{ "physicalLayerProtocol", "ptp.v2.mm.physicalLayerProtocol",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_physicalLayerProtocol_length,
{ "length", "ptp.v2.mm.physicalLayerProtocol.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_physicalAddressLength,
{ "physical address length", "ptp.v2.mm.physicalAddressLength",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_physicalAddress,
{ "physical address", "ptp.v2.mm.physicalAddress",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_protocolAddress,
{ "protocol address", "ptp.v2.mm.protocolAddress",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_protocolAddress_networkProtocol,
{ "network protocol", "ptp.v2.mm.networkProtocol",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ptp2_networkProtocol_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_protocolAddress_length,
{ "length", "ptp.v2.mm.protocolAddress.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_manufacturerIdentity,
{ "manufacturer identity", "ptp.v2.mm.manufacturerIdentity",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_reserved,
{ "reserved", "ptp.v2.mm.reserved",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_productDescription,
{ "product description", "ptp.v2.mm.productDescription",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_productDescription_length,
{ "length", "ptp.v2.mm.productDescription.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_revisionData,
{ "revision data", "ptp.v2.mm.revisionData",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_revisionData_length,
{ "length", "ptp.v2.mm.revisionData.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_userDescription,
{ "user description", "ptp.v2.mm.userDescription",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_userDescription_length,
{ "length", "ptp.v2.mm.userDescription.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_profileIdentity,
{ "profileIdentity", "ptp.v2.mm.profileIdentity",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_pad,
{ "Pad", "ptp.v2.mm.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_initializationKey,
{ "initialization key", "ptp.v2.mm.initializationKey",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_numberOfFaultRecords,
{ "number of fault records", "ptp.v2.mm.numberOfFaultRecords",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_v2_mm_faultRecord,
{ "fault record", "ptp.v2.mm.faultRecord",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_v2_mm_faultRecordLength,
{ "fault record length", "ptp.v2.mm.faultRecordLength",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_severityCode,
{ "severity code", "ptp.v2.mm.severityCode",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp2_severityCode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_faultName,
{ "faultName", "ptp.v2.mm.faultName",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_faultName_length,
{ "length", "ptp.v2.mm.faultName.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_faultValue,
{ "faultValue", "ptp.v2.mm.faultValue",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_faultValue_length,
{ "length", "ptp.v2.mm.faultValue.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_faultDescription,
{ "faultDescription", "ptp.v2.mm.faultDescription",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_faultDescription_length,
{ "length", "ptp.v2.mm.faultDescription.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#if 0
{ &hf_ptp_v2_mm_faultTime,
{ "Fault time", "ptp.v2.mm.faultTime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_ptp_v2_mm_faultTime_s,
{ "Fault time (seconds)", "ptp.v2.mm.faultTime.seconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_faultTime_ns,
{ "Fault time (nanoseconds)", "ptp.v2.mm.faultTime.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_currentTime_s,
{ "current time (seconds)", "ptp.v2.mm.currentTime.seconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_currentTime_ns,
{ "current time (nanoseconds)", "ptp.v2.mm.currentTime.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockAccuracy,
{ "Clock accuracy", "ptp.v2.mm.clockaccuracy",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ptp_v2_clockaccuracy_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_priority1,
{ "priority1", "ptp.v2.mm.priority1",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_priority2,
{ "priority2", "ptp.v2.mm.priority2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_dds_SO,
{ "Slave only", "ptp.v2.mm.SlavOnly",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_TSC,
{ "Two step", "ptp.v2.mm.twoStep",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_numberPorts,
{ "number of ports", "ptp.v2.mm.numberPorts",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockclass,
{ "Clock class", "ptp.v2.mm.clockclass",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockaccuracy,
{ "Clock accuracy", "ptp.v2.mm.clockaccuracy",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ptp_v2_clockaccuracy_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockvariance,
{ "Clock variance", "ptp.v2.mm.clockvariance",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_clockidentity,
{ "Clock identity", "ptp.v2.mm.clockidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_domainNumber,
{ "domain number", "ptp.v2.mm.domainNumber",
FT_UINT8, BASE_DEC, NULL , 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_SO,
{ "Slave only", "ptp.v2.mm.SlavOnly",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_stepsRemoved,
{ "steps removed", "ptp.v2.mm.stepsRemoved",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_parentIdentity,
{ "parent ClockIdentity", "ptp.v2.mm.parentclockidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_parentPort,
{ "parent SourcePortID", "ptp.v2.mm.parentsourceportid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_parentStats,
{ "parent stats", "ptp.v2.mm.parentstats",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_observedParentOffsetScaledLogVariance,
{ "observedParentOffsetScaledLogVariance", "ptp.v2.mm.observedParentOffsetScaledLogVariance",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_observedParentClockPhaseChangeRate,
{ "observedParentClockPhaseChangeRate", "ptp.v2.mm.observedParentClockPhaseChangeRate",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_grandmasterPriority1,
{ "Grandmaster priority1", "ptp.v2.mm.grandmasterPriority1",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_grandmasterPriority2,
{ "Grandmaster priority2", "ptp.v2.mm.grandmasterPriority2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_grandmasterclockclass,
{ "Grandmaster clock class", "ptp.v2.mm.grandmasterclockclass",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_grandmasterclockaccuracy,
{ "Grandmaster clock accuracy", "ptp.v2.mm.grandmasterclockaccuracy",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ptp_v2_clockaccuracy_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_grandmasterclockvariance,
{ "Grandmaster clock variance", "ptp.v2.mm.grandmasterclockvariance",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_grandmasterIdentity,
{ "Grandmaster clock identity", "ptp.v2.mm.grandmasterclockidentity",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_currentUtcOffset,
{ "CurrentUTCOffset", "ptp.v2.mm.currentutcoffset",
FT_INT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_LI_61,
{ "leap 61", "ptp.v2.mm.li61",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_LI_59,
{ "leap 59", "ptp.v2.mm.li59",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_UTCV,
{ "CurrentUTCOffset valid", "ptp.v2.mm.CurrentUTCOffsetValid",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_PTP,
{ "PTP timescale", "ptp.v2.mm.ptptimescale",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_TTRA,
{ "Time traceable", "ptp.v2.mm.timeTraceable",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_FTRA,
{ "Frequency traceable", "ptp.v2.mm.frequencyTraceable",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_timesource,
{ "TimeSource", "ptp.v2.mm.timesource",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ptp_v2_timesource_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_offset_ns,
{ "correction", "ptp.v2.mm.offset.ns",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_offset_subns,
{ "SubNs", "ptp.v2.mm.offset.subns",
FT_DOUBLE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_pathDelay_ns,
{ "ns", "ptp.v2.mm.pathDelay.ns",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_pathDelay_subns,
{ "SubNs", "ptp.v2.mm.pathDelay.subns",
FT_DOUBLE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_PortNumber,
{ "PortNumber", "ptp.v2.mm.PortNumber",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_portState,
{ "Port state", "ptp.v2.mm.portState",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ptp2_portState_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_logMinDelayReqInterval,
{ "logMinDelayReqInterval", "ptp.v2.mm.logMinDelayReqInterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_peerMeanPathDelay_ns,
{ "ns", "ptp.v2.mm.peerMeanPathDelay.ns",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_peerMeanPathDelay_subns,
{ "SubNs", "ptp.v2.mm.peerMeanPathDelay.subns",
FT_DOUBLE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_logAnnounceInterval,
{ "logAnnounceInterval", "ptp.v2.mm.logAnnounceInterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_announceReceiptTimeout,
{ "announceReceiptTimeout", "ptp.v2.mm.announceReceiptTimeout",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_logSyncInterval,
{ "logSyncInterval", "ptp.v2.mm.logSyncInterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_delayMechanism,
{ "Delay mechanism", "ptp.v2.mm.delayMechanism",
FT_UINT8, BASE_DEC, VALS(ptp2_delayMechanism_vals), 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_logMinPdelayReqInterval,
{ "logMinPdelayReqInterval", "ptp.v2.mm.logMinPdelayReqInterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_versionNumber,
{ "versionNumber", "ptp.v2.mm.versionNumber",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_primaryDomain,
{ "Primary domain number", "ptp.v2.mm.primaryDomain",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_faultyFlag,
{ "Faulty flag", "ptp.v2.mm.faultyFlag",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_managementErrorId,
{ "managementErrorId", "ptp.v2.mm.managementErrorId",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ptp2_managementErrorId_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_displayData,
{ "Display data", "ptp.v2.mm.displayData",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_displayData_length,
{ "length", "ptp.v2.mm.displayData.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_ucEN,
{ "Enable unicast", "ptp.v2.mm.unicastEnable",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_ptEN,
{ "Path trace unicast", "ptp.v2.mm.pathTraceEnable",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_atEN,
{ "Path trace unicast", "ptp.v2.mm.pathTraceEnable",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_keyField,
{ "Key field", "ptp.v2.mm.keyField",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_displayName,
{ "Display name", "ptp.v2.mm.displayName",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_displayName_length,
{ "length", "ptp.v2.mm.displayName.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_maxKey,
{ "Max key", "ptp.v2.mm.maxKey",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_currentOffset,
{ "Current offset", "ptp.v2.mm.currentOffset",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_jumpSeconds,
{ "Jump seconds", "ptp.v2.mm.jumpSeconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_nextjumpSeconds,
{ "Time of next jump (seconds)", "ptp.v2.mm.nextjumpSeconds",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_numberOfAlternateMasters,
{ "Number of alternate masters", "ptp.v2.mm.numberOfAlternateMasters",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_logAlternateMulticastSyncInterval,
{ "Alternate multicast sync interval", "ptp.v2.mm.AlternateMulticastSyncInterval",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ptp_v2_mm_transmitAlternateMulticastSync,
{ "Transmit alternate multicast sync", "ptp.v2.mm.transmitAlternateMulticastSync",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_ptp,
&ett_ptp_flags,
&ett_ptp_time,
&ett_ptp_time2,
&ett_ptp_v2,
&ett_ptp_v2_transportspecific,
&ett_ptp_v2_flags,
&ett_ptp_v2_correction,
&ett_ptp_v2_time,
&ett_ptp_v2_time2,
&ett_ptp_v2_managementData,
&ett_ptp_v2_clockType,
&ett_ptp_v2_physicalLayerProtocol,
&ett_ptp_v2_protocolAddress,
&ett_ptp_v2_ptptext,
&ett_ptp_v2_faultRecord,
&ett_ptp_v2_timeInterval,
&ett_ptp_v2_tlv,
&ett_ptp_v2_tlv_log_period,
&ett_ptp_as_sig_tlv_flags,
};
static ei_register_info ei[] = {
{ &ei_ptp_v2_msg_len_too_large, { "ptp.v2.msg_len_too_large", PI_MALFORMED, PI_ERROR, "Message length goes past the end of the packet", EXPFILL }},
{ &ei_ptp_v2_msg_len_too_small, { "ptp.v2.msg_len_too_small", PI_MALFORMED, PI_ERROR, "Message length too short to include the message length field", EXPFILL }},
};
expert_module_t* expert_ptp;
proto_ptp = proto_register_protocol("Precision Time Protocol (IEEE1588)",
"PTP", "ptp");
proto_register_field_array(proto_ptp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ptp = expert_register_protocol(proto_ptp);
expert_register_field_array(expert_ptp, ei, array_length(ei));
}
void
proto_reg_handoff_ptp(void)
{
dissector_handle_t ptp_handle;
dissector_handle_t ethertype_ptp_handle;
ptp_handle = create_dissector_handle(dissect_ptp, proto_ptp);
ethertype_ptp_handle = create_dissector_handle(dissect_ptp_oE, proto_ptp);
dissector_add_uint("udp.port", EVENT_PORT_PTP, ptp_handle);
dissector_add_uint("udp.port", GENERAL_PORT_PTP, ptp_handle);
dissector_add_uint("ethertype", ETHERTYPE_PTP, ethertype_ptp_handle);
}
