static void OUT_RXArray8(ptvcursor_t *cursor, int field, int field_size, int encoding)
{
unsigned int i,
size = tvb_get_guint8(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_advance(cursor, 1);
for (i=0; i<size; i++) {
ptvcursor_add(cursor, field, field_size, encoding);
}
}
static void OUT_TIMESTAMP(ptvcursor_t *cursor, int field)
{
nstime_t ts;
ts.secs = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ts.nsecs = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor)+4)*1000;
proto_tree_add_time(ptvcursor_tree(cursor), field, ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), 8, &ts);
ptvcursor_advance(cursor, 8);
}
static void OUT_TIMESECS(ptvcursor_t *cursor, int field)
{
nstime_t ts;
ts.secs = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ts.nsecs = 0;
proto_tree_add_time(ptvcursor_tree(cursor), field, ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), 4, &ts);
ptvcursor_advance(cursor, 4);
}
static void OUT_RXString(ptvcursor_t *cursor, int field)
{
int offset = ptvcursor_current_offset(cursor),
new_offset;
ptvcursor_add(cursor, field, 4, ENC_BIG_ENDIAN);
new_offset = ptvcursor_current_offset(cursor);
ptvcursor_advance(cursor, 4-((new_offset-offset)&3));
}
static void OUT_RXStringV(ptvcursor_t *cursor, int field, guint32 length)
{
tvbuff_t* tvb = ptvcursor_tvbuff(cursor);
char* str = (char*)wmem_alloc(wmem_packet_scope(), length+1);
int offset = ptvcursor_current_offset(cursor),
start_offset = offset;
guint32 idx;
for (idx = 0; idx<length; idx++)
{
str[idx] = (char)tvb_get_ntohl(tvb, offset);
offset += 4;
}
str[length] = '\0';
proto_tree_add_string(ptvcursor_tree(cursor), field, tvb, start_offset, length*4, str);
ptvcursor_advance(cursor, length*4);
}
static void OUT_FS_AFSCallBack(ptvcursor_t *cursor)
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_afs_callback, "Callback");
ptvcursor_add(cursor, hf_afs_fs_callback_version, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_fs_callback_expires);
ptvcursor_add(cursor, hf_afs_fs_callback_type, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
static void OUT_CM_INTERFACES(ptvcursor_t *cursor)
{
unsigned int i;
unsigned int maxint = 32,
numint = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_afs_cm_interfaces, "Interfaces");
ptvcursor_add(cursor, hf_afs_cm_numint, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_cm_uuid, 4*11, ENC_NA);
for ( i=0; i<numint; i++ ) {
ptvcursor_add(cursor, hf_afs_cm_ipaddr, 4, ENC_BIG_ENDIAN);
}
ptvcursor_advance(cursor, 4*(maxint-numint));
for ( i=0; i<numint; i++ ) {
ptvcursor_add(cursor, hf_afs_cm_netmask, 4, ENC_BIG_ENDIAN);
}
ptvcursor_advance(cursor, 4*(maxint-numint));
for ( i=0; i<numint; i++ ) {
ptvcursor_add(cursor, hf_afs_cm_mtu, 4, ENC_BIG_ENDIAN);
}
ptvcursor_advance(cursor, 4*(maxint-numint));
ptvcursor_pop_subtree(cursor);
}
static void OUT_CM_CAPABILITIES(ptvcursor_t *cursor)
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_afs_cm_capabilities, "Capabilities");
ptvcursor_add(cursor, hf_afs_cm_numcap, 4, ENC_BIG_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_afs_cm_capabilities, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_cm_cap_errortrans, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
static void OUT_CB_AFSCallBack(ptvcursor_t *cursor)
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH,
ett_afs_callback, "Callback");
ptvcursor_add(cursor, hf_afs_cb_callback_version, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_cb_callback_expires);
ptvcursor_add(cursor, hf_afs_cb_callback_type, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
static void OUT_FS_AFSFid(ptvcursor_t *cursor, const char* label)
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH,
ett_afs_fid, "FileID (%s)", label);
ptvcursor_add(cursor, hf_afs_fs_fid_volume, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_fid_vnode, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_fid_uniqifier, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
static void OUT_CB_AFSFid(ptvcursor_t *cursor, const char* label)
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH,
ett_afs_fid, "FileID (%s)", label);
ptvcursor_add(cursor, hf_afs_cb_fid_volume, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_cb_fid_vnode, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_cb_fid_uniqifier, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
static void OUT_FS_AFSStoreStatus(ptvcursor_t *cursor, const char* label)
{
static const int * status_mask_flags[] = {
&hf_afs_fs_status_mask_setmodtime,
&hf_afs_fs_status_mask_setowner,
&hf_afs_fs_status_mask_setgroup,
&hf_afs_fs_status_mask_setmode,
&hf_afs_fs_status_mask_setsegsize,
&hf_afs_fs_status_mask_fsync,
NULL
};
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH,
ett_afs_status, "%s", label);
proto_tree_add_bitmask(ptvcursor_tree(cursor), ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor),
hf_afs_fs_status_mask, ett_afs_status_mask, status_mask_flags, ENC_BIG_ENDIAN);
ptvcursor_advance(cursor, 4);
OUT_TIMESECS(cursor, hf_afs_fs_status_clientmodtime);
ptvcursor_add(cursor, hf_afs_fs_status_owner, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_group, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_mode, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_segsize, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
static void OUT_FS_AFSFetchStatus(ptvcursor_t *cursor, const char* label)
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH,
ett_afs_status, "%s", label);
ptvcursor_add(cursor, hf_afs_fs_status_interfaceversion, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_filetype, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_linkcount, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_length, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_dataversion, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_author, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_owner, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_calleraccess, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_anonymousaccess, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_mode, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_parentvnode, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_parentunique, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_segsize, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_fs_status_clientmodtime);
OUT_TIMESECS(cursor, hf_afs_fs_status_servermodtime);
ptvcursor_add(cursor, hf_afs_fs_status_group, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_synccounter, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_dataversionhigh, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_spare2, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_spare3, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_status_spare4, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
static void OUT_FS_AFSVolSync(ptvcursor_t *cursor)
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH,
ett_afs_status, "VolSync");
OUT_TIMESECS(cursor, hf_afs_fs_volsync_spare1);
ptvcursor_add(cursor, hf_afs_fs_volsync_spare2, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_volsync_spare3, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_volsync_spare4, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_volsync_spare5, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_volsync_spare6, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
static void OUT_BOS_KEYINFO(ptvcursor_t *cursor)
{
OUT_TIMESTAMP(cursor, hf_afs_bos_keymodtime);
ptvcursor_add(cursor, hf_afs_bos_keychecksum, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_bos_keyspare2, 4, ENC_BIG_ENDIAN);
}
static void OUT_UBIK_InterfaceAddrs(ptvcursor_t *cursor)
{
unsigned int i,j,seen_null=0;
for (i=0; i<255; i++) {
j = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
if ( j != 0 ) {
ptvcursor_add(cursor, hf_afs_ubik_interface, 4, ENC_BIG_ENDIAN);
seen_null = 0;
} else {
if ( ! seen_null ) {
ptvcursor_add_no_advance(cursor, hf_afs_ubik_null_addresses, -1, ENC_NA);
seen_null = 1;
}
ptvcursor_advance(cursor, 4);
}
}
}
static void OUT_UBIKVERSION(ptvcursor_t *cursor, const char* label)
{
unsigned int epoch,counter;
nstime_t ts;
epoch = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
counter = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor)+4);
ts.secs = epoch;
ts.nsecs = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH,
ett_afs_ubikver, "UBIK Version (%s): %u.%u", label, epoch, counter);
if ( epoch != 0 )
proto_tree_add_time(ptvcursor_tree(cursor), hf_afs_ubik_version_epoch, ptvcursor_tvbuff(cursor),
ptvcursor_current_offset(cursor), 4, &ts);
else
proto_tree_add_time_format_value(ptvcursor_tree(cursor), hf_afs_ubik_version_epoch, ptvcursor_tvbuff(cursor),
ptvcursor_current_offset(cursor), 4, &ts, "0");
ptvcursor_advance(cursor, 4);
ptvcursor_add(cursor, hf_afs_ubik_version_counter, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
static void OUT_UBIK_DebugOld(ptvcursor_t *cursor)
{
OUT_TIMESECS(cursor, hf_afs_ubik_now);
OUT_TIMESECS(cursor, hf_afs_ubik_lastyestime);
ptvcursor_add(cursor, hf_afs_ubik_lastyeshost, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_lastyesstate, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_ubik_lastyesclaim);
ptvcursor_add(cursor, hf_afs_ubik_lowesthost, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_ubik_lowesttime);
ptvcursor_add(cursor, hf_afs_ubik_synchost, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_ubik_synctime);
OUT_UBIKVERSION(cursor, "Sync Version");
OUT_UBIKVERSION(cursor, "Sync TID");
ptvcursor_add(cursor, hf_afs_ubik_amsyncsite, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_ubik_syncsiteuntil);
ptvcursor_add(cursor, hf_afs_ubik_nservers, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_lockedpages, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_writelockedpages, 4, ENC_BIG_ENDIAN);
OUT_UBIKVERSION(cursor, "Local Version");
ptvcursor_add(cursor, hf_afs_ubik_activewrite, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_tidcounter, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_anyreadlocks, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_anywritelocks, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_recoverystate, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_currenttrans, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_writetrans, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_ubik_epochtime);
}
static void OUT_UBIK_SDebugOld(ptvcursor_t *cursor)
{
ptvcursor_add(cursor, hf_afs_ubik_addr, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_ubik_lastvotetime);
OUT_TIMESECS(cursor, hf_afs_ubik_lastbeaconsent);
ptvcursor_add(cursor, hf_afs_ubik_lastvote, 4, ENC_BIG_ENDIAN);
OUT_UBIKVERSION(cursor, "Remote Version");
ptvcursor_add(cursor, hf_afs_ubik_currentdb, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_beaconsincedown, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_up, 4, ENC_BIG_ENDIAN);
}
static void OUT_KAUTH_GetTicket(ptvcursor_t *cursor)
{
int len;
ptvcursor_add(cursor, hf_afs_kauth_kvno, 4, ENC_BIG_ENDIAN);
OUT_RXString(cursor, hf_afs_kauth_domain);
len = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_advance(cursor, 4);
ptvcursor_add(cursor, hf_afs_kauth_data, len, ENC_NA);
OUT_RXString(cursor, hf_afs_kauth_princ);
OUT_RXString(cursor, hf_afs_kauth_realm);
}
static gint
afs_equal(gconstpointer v, gconstpointer w)
{
const struct afs_request_key *v1 = (const struct afs_request_key *)v;
const struct afs_request_key *v2 = (const struct afs_request_key *)w;
if (v1 -> conversation == v2 -> conversation &&
v1 -> epoch == v2 -> epoch &&
v1 -> cid == v2 -> cid &&
v1 -> callnumber == v2 -> callnumber ) {
return 1;
}
return 0;
}
static guint
afs_hash (gconstpointer v)
{
const struct afs_request_key *key = (const struct afs_request_key *)v;
guint val;
val = key -> conversation + key -> epoch + key -> cid + key -> callnumber;
return val;
}
static void
afs_init_protocol(void)
{
afs_request_hash = g_hash_table_new(afs_hash, afs_equal);
reassembly_table_init(&afs_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
afs_cleanup_protocol(void)
{
reassembly_table_destroy(&afs_reassembly_table);
g_hash_table_destroy(afs_request_hash);
}
static void
dissect_acl(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_)
{
int old_offset = ptvcursor_current_offset(cursor), offset;
gint32 bytes;
int i, n, pos, neg, acl;
proto_tree* tree = ptvcursor_tree(cursor);
tvbuff_t* tvb = ptvcursor_tvbuff(cursor);
char user[128] = "[Unknown]";
bytes = tvb_get_ntohl(tvb, ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_afs_fs_acl_datasize, 4, ENC_BIG_ENDIAN);
if (sscanf(GETSTR, "%d %n", &pos, &n) != 1) {
return;
}
proto_tree_add_uint(tree, hf_afs_fs_acl_count_positive, tvb,
ptvcursor_current_offset(cursor), n, pos);
ptvcursor_advance(cursor, n);
if (sscanf(GETSTR, "%d %n", &neg, &n) != 1) {
return;
}
proto_tree_add_uint(tree, hf_afs_fs_acl_count_negative, tvb,
ptvcursor_current_offset(cursor), n, neg);
ptvcursor_advance(cursor, n);
offset = ptvcursor_current_offset(cursor);
for (i = 0; i < pos; i++) {
if (sscanf(GETSTR, "%127s %d %n", user, &acl, &n) != 2) {
return;
}
ACLOUT(user,1,acl,n);
offset += n;
}
for (i = 0; i < neg; i++) {
if (sscanf(GETSTR, "%127s %d %n", user, &acl, &n) != 2) {
return;
}
ACLOUT(user,0,acl,n);
offset += n;
if (offset >= old_offset+bytes ) {
return;
}
}
}
static void
dissect_fs_reply(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode)
{
if ( rxinfo->type == RX_PACKET_TYPE_DATA )
{
switch ( opcode )
{
case 130:
OUT_FS_AFSFetchStatus(cursor, "Status");
OUT_FS_AFSCallBack(cursor);
OUT_FS_AFSVolSync(cursor);
ptvcursor_add(cursor, hf_afs_fs_data, -1, ENC_NA);
break;
case 131:
dissect_acl(cursor, rxinfo);
OUT_FS_AFSFetchStatus(cursor, "Status");
OUT_FS_AFSVolSync(cursor);
break;
case 132:
OUT_FS_AFSFetchStatus(cursor, "Status");
OUT_FS_AFSCallBack(cursor);
OUT_FS_AFSVolSync(cursor);
break;
case 133:
case 134:
case 135:
case 136:
OUT_FS_AFSFetchStatus(cursor, "Status");
OUT_FS_AFSVolSync(cursor);
break;
case 137:
case 141:
case 161:
case 163:
OUT_FS_AFSFid(cursor, (opcode == 137)? "New File" : ((opcode == 141)? "New Directory" : "File"));
OUT_FS_AFSFetchStatus(cursor, "File Status");
OUT_FS_AFSFetchStatus(cursor, "Directory Status");
OUT_FS_AFSCallBack(cursor);
OUT_FS_AFSVolSync(cursor);
break;
case 138:
OUT_FS_AFSFetchStatus(cursor, "Old Directory Status");
OUT_FS_AFSFetchStatus(cursor, "New Directory Status");
OUT_FS_AFSVolSync(cursor);
break;
case 139:
OUT_FS_AFSFid(cursor, "Symlink");
break;
case 140:
OUT_FS_AFSFetchStatus(cursor, "Symlink Status");
break;
case 142:
OUT_FS_AFSFetchStatus(cursor, "Directory Status");
OUT_FS_AFSVolSync(cursor);
break;
case 143:
case 144:
case 145:
case 147:
case 150:
case 152:
break;
case 146:
break;
case 148:
case 154:
break;
case 149:
OUT_RXString(cursor, hf_afs_fs_volname);
OUT_RXString(cursor, hf_afs_fs_offlinemsg);
OUT_RXString(cursor, hf_afs_fs_motd);
break;
case 151:
OUT_RXString(cursor, hf_afs_fs_volname);
break;
case 153:
OUT_TIMESTAMP(cursor, hf_afs_fs_timestamp);
break;
case 155:
OUT_RXArray32(OUT_FS_AFSFetchStatus(cursor, "Status"));
ptvcursor_advance(cursor, 4);
OUT_RXArray32(OUT_FS_AFSCallBack(cursor));
OUT_FS_AFSVolSync(cursor);
break;
case 156:
case 157:
case 158:
OUT_FS_AFSVolSync(cursor);
break;
case 159:
ptvcursor_add(cursor, hf_afs_fs_xstats_version, 4, ENC_BIG_ENDIAN);
break;
case 160:
ptvcursor_add(cursor, hf_afs_fs_xstats_version, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_fs_xstats_timestamp);
break;
case 162:
ptvcursor_add(cursor, hf_afs_fs_cps_spare2, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_cps_spare3, 4, ENC_BIG_ENDIAN);
break;
case 65536:
OUT_RXArray32(OUT_FS_AFSFetchStatus(cursor, "Status"));
OUT_RXArray32(OUT_FS_AFSCallBack(cursor));
OUT_FS_AFSVolSync(cursor);
break;
}
}
else if ( rxinfo->type == RX_PACKET_TYPE_ABORT )
{
ptvcursor_add(cursor, hf_afs_fs_errcode, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_fs_request(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode)
{
ptvcursor_advance(cursor, 4);
switch ( opcode )
{
case 130:
OUT_FS_AFSFid(cursor, "Source");
ptvcursor_add(cursor, hf_afs_fs_offset, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_length, 4, ENC_BIG_ENDIAN);
break;
case 131:
OUT_FS_AFSFid(cursor, "Target");
break;
case 132:
OUT_FS_AFSFid(cursor, "Target");
break;
case 133:
OUT_FS_AFSFid(cursor, "Destination");
OUT_FS_AFSStoreStatus(cursor, "Status");
ptvcursor_add(cursor, hf_afs_fs_offset, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_length, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_flength, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_data, -1, ENC_NA);
break;
case 134:
OUT_FS_AFSFid(cursor, "Target");
dissect_acl(cursor, rxinfo);
break;
case 135:
OUT_FS_AFSFid(cursor, "Target");
OUT_FS_AFSStoreStatus(cursor, "Status");
break;
case 136:
OUT_FS_AFSFid(cursor, "Remove File");
OUT_RXString(cursor, hf_afs_fs_name);
break;
case 137:
OUT_FS_AFSFid(cursor, "Target");
OUT_RXString(cursor, hf_afs_fs_name);
OUT_FS_AFSStoreStatus(cursor, "Status");
break;
case 138:
OUT_FS_AFSFid(cursor, "Old");
OUT_RXString(cursor, hf_afs_fs_oldname);
OUT_FS_AFSFid(cursor, "New");
OUT_RXString(cursor, hf_afs_fs_newname);
break;
case 139:
OUT_FS_AFSFid(cursor, "File");
OUT_RXString(cursor, hf_afs_fs_symlink_name);
OUT_RXString(cursor, hf_afs_fs_symlink_content);
OUT_FS_AFSStoreStatus(cursor, "Status");
break;
case 140:
OUT_FS_AFSFid(cursor, "Link To (New File)");
OUT_RXString(cursor, hf_afs_fs_name);
OUT_FS_AFSFid(cursor, "Link From (Old File)");
break;
case 141:
OUT_FS_AFSFid(cursor, "Target");
OUT_RXString(cursor, hf_afs_fs_name);
OUT_FS_AFSStoreStatus(cursor, "Status");
break;
case 142:
OUT_FS_AFSFid(cursor, "Target");
OUT_RXString(cursor, hf_afs_fs_name);
break;
case 143:
OUT_FS_AFSFid(cursor, "Target");
ptvcursor_add(cursor, hf_afs_fs_vicelocktype, 4, ENC_BIG_ENDIAN);
OUT_FS_AFSVolSync(cursor);
break;
case 144:
OUT_FS_AFSFid(cursor, "Target");
OUT_FS_AFSVolSync(cursor);
break;
case 145:
OUT_FS_AFSFid(cursor, "Target");
OUT_FS_AFSVolSync(cursor);
break;
case 146:
break;
case 147:
OUT_RXArray32(OUT_FS_AFSFid(cursor, "Target"));
OUT_RXArray32(OUT_FS_AFSCallBack(cursor));
break;
case 148:
OUT_RXString(cursor, hf_afs_fs_volname);
break;
case 149:
ptvcursor_add(cursor, hf_afs_fs_volid, 4, ENC_BIG_ENDIAN);
break;
case 150:
ptvcursor_add(cursor, hf_afs_fs_volid, 4, ENC_BIG_ENDIAN);
OUT_RXString(cursor, hf_afs_fs_volname);
OUT_RXString(cursor, hf_afs_fs_offlinemsg);
OUT_RXString(cursor, hf_afs_fs_motd);
break;
case 151:
break;
case 152:
ptvcursor_add(cursor, hf_afs_fs_viceid, 4, ENC_BIG_ENDIAN);
OUT_RXStringV(cursor, hf_afs_fs_token, 1024);
break;
case 153:
break;
case 154:
OUT_RXString(cursor, hf_afs_fs_volname);
break;
case 155:
OUT_RXArray32(OUT_FS_AFSFid(cursor, "Target"));
break;
case 156:
OUT_FS_AFSFid(cursor, "Target");
ptvcursor_add(cursor, hf_afs_fs_vicelocktype, 4, ENC_BIG_ENDIAN);
break;
case 157:
OUT_FS_AFSFid(cursor, "Target");
break;
case 158:
OUT_FS_AFSFid(cursor, "Target");
break;
case 159:
break;
case 160:
ptvcursor_add(cursor, hf_afs_fs_xstats_clientversion, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_xstats_collnumber, 4, ENC_BIG_ENDIAN);
break;
case 161:
OUT_FS_AFSFid(cursor, "Target");
OUT_RXString(cursor, hf_afs_fs_name);
break;
case 162:
OUT_RXArray8(cursor, hf_afs_fs_viceid, 4, ENC_BIG_ENDIAN);
OUT_RXArray8(cursor, hf_afs_fs_ipaddr, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_cps_spare1, 4, ENC_BIG_ENDIAN);
break;
case 163:
OUT_FS_AFSFid(cursor, "Target");
OUT_RXString(cursor, hf_afs_fs_symlink_name);
OUT_RXString(cursor, hf_afs_fs_symlink_content);
OUT_FS_AFSStoreStatus(cursor, "Symlink Status");
break;
case 220:
OUT_FS_AFSFid(cursor, "Target");
break;
case 65536:
OUT_RXArray32(OUT_FS_AFSFid(cursor, "Target"));
break;
case 65537:
OUT_FS_AFSFid(cursor, "Target");
ptvcursor_add(cursor, hf_afs_fs_offset64, 8, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_length64, 8, ENC_BIG_ENDIAN);
break;
case 65538:
OUT_FS_AFSFid(cursor, "Target");
OUT_FS_AFSStoreStatus(cursor, "Status");
ptvcursor_add(cursor, hf_afs_fs_offset64, 8, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_length64, 8, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_fs_flength64, 8, ENC_BIG_ENDIAN);
break;
case 65539:
break;
case 65540:
break;
}
}
static void
dissect_bos_reply(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode)
{
if ( rxinfo->type == RX_PACKET_TYPE_DATA )
{
switch ( opcode )
{
case 80:
break;
case 81:
break;
case 82:
break;
case 83:
ptvcursor_add(cursor, hf_afs_bos_status, 4, ENC_BIG_ENDIAN);
OUT_RXString(cursor, hf_afs_bos_statusdesc);
break;
case 84:
OUT_RXString(cursor, hf_afs_bos_instance);
break;
case 85:
OUT_RXString(cursor, hf_afs_bos_type);
ptvcursor_advance(cursor, 4*10);
break;
case 86:
OUT_RXString(cursor, hf_afs_bos_parm);
break;
case 87:
break;
case 88:
break;
case 89:
OUT_RXString(cursor, hf_afs_bos_user);
break;
case 90:
ptvcursor_add(cursor, hf_afs_bos_kvno, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_bos_key, 8, ENC_NA);
OUT_BOS_KEYINFO(cursor);
break;
case 91:
break;
case 92:
break;
case 93:
break;
case 94:
OUT_RXString(cursor, hf_afs_bos_cell);
break;
case 95:
OUT_RXString(cursor, hf_afs_bos_host);
break;
case 96:
break;
case 97:
break;
case 98:
break;
case 99:
break;
case 100:
break;
case 101:
break;
case 102:
break;
case 103:
break;
case 104:
break;
case 105:
break;
case 106:
break;
case 107:
OUT_TIMESECS(cursor, hf_afs_bos_newtime);
OUT_TIMESECS(cursor, hf_afs_bos_baktime);
OUT_TIMESECS(cursor, hf_afs_bos_oldtime);
break;
case 108:
break;
case 109:
break;
case 110:
break;
case 111:
ptvcursor_advance(cursor, 12);
break;
case 112:
ptvcursor_add(cursor, hf_afs_bos_data, -1, ENC_NA);
break;
case 113:
break;
case 114:
OUT_RXString(cursor, hf_afs_bos_error);
OUT_RXString(cursor, hf_afs_bos_spare1);
OUT_RXString(cursor, hf_afs_bos_spare2);
OUT_RXString(cursor, hf_afs_bos_spare3);
break;
}
}
else if ( rxinfo->type == RX_PACKET_TYPE_ABORT )
{
ptvcursor_add(cursor, hf_afs_bos_errcode, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_bos_request(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_, int opcode)
{
ptvcursor_advance(cursor, 4);
switch ( opcode )
{
case 80:
OUT_RXString(cursor, hf_afs_bos_type);
OUT_RXString(cursor, hf_afs_bos_instance);
OUT_RXString(cursor, hf_afs_bos_parm);
OUT_RXString(cursor, hf_afs_bos_parm);
OUT_RXString(cursor, hf_afs_bos_parm);
OUT_RXString(cursor, hf_afs_bos_parm);
OUT_RXString(cursor, hf_afs_bos_parm);
OUT_RXString(cursor, hf_afs_bos_parm);
break;
case 81:
OUT_RXString(cursor, hf_afs_bos_instance);
break;
case 82:
OUT_RXString(cursor, hf_afs_bos_instance);
ptvcursor_add(cursor, hf_afs_bos_status, 4, ENC_BIG_ENDIAN);
break;
case 83:
OUT_RXString(cursor, hf_afs_bos_instance);
break;
case 84:
ptvcursor_add(cursor, hf_afs_bos_num, 4, ENC_BIG_ENDIAN);
break;
case 85:
OUT_RXString(cursor, hf_afs_bos_instance);
break;
case 86:
OUT_RXString(cursor, hf_afs_bos_instance);
ptvcursor_add(cursor, hf_afs_bos_num, 4, ENC_BIG_ENDIAN);
break;
case 87:
OUT_RXString(cursor, hf_afs_bos_user);
break;
case 88:
OUT_RXString(cursor, hf_afs_bos_user);
break;
case 89:
ptvcursor_add(cursor, hf_afs_bos_num, 4, ENC_BIG_ENDIAN);
break;
case 90:
ptvcursor_add(cursor, hf_afs_bos_num, 4, ENC_BIG_ENDIAN);
break;
case 91:
ptvcursor_add(cursor, hf_afs_bos_num, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_bos_key, 8, ENC_NA);
break;
case 92:
ptvcursor_add(cursor, hf_afs_bos_num, 4, ENC_BIG_ENDIAN);
break;
case 93:
OUT_RXString(cursor, hf_afs_bos_content);
break;
case 95:
ptvcursor_add(cursor, hf_afs_bos_num, 4, ENC_BIG_ENDIAN);
break;
case 96:
OUT_RXString(cursor, hf_afs_bos_content);
break;
case 97:
OUT_RXString(cursor, hf_afs_bos_content);
break;
case 98:
OUT_RXString(cursor, hf_afs_bos_content);
ptvcursor_add(cursor, hf_afs_bos_status, 4, ENC_BIG_ENDIAN);
break;
case 99:
break;
case 100:
break;
case 101:
break;
case 102:
ptvcursor_add(cursor, hf_afs_bos_flags, 4, ENC_BIG_ENDIAN);
break;
case 103:
break;
case 104:
OUT_RXString(cursor, hf_afs_bos_instance);
break;
case 105:
OUT_RXString(cursor, hf_afs_bos_path);
ptvcursor_add(cursor, hf_afs_bos_size, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_bos_flags, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_bos_date, 4, ENC_BIG_ENDIAN);
break;
case 106:
OUT_RXString(cursor, hf_afs_bos_path);
break;
case 107:
OUT_RXString(cursor, hf_afs_bos_path);
break;
case 108:
OUT_RXString(cursor, hf_afs_bos_cmd);
break;
case 109:
ptvcursor_add(cursor, hf_afs_bos_flags, 4, ENC_BIG_ENDIAN);
break;
case 110:
ptvcursor_add(cursor, hf_afs_bos_num, 4, ENC_BIG_ENDIAN);
ptvcursor_advance(cursor, 12);
break;
case 111:
ptvcursor_add(cursor, hf_afs_bos_num, 4, ENC_BIG_ENDIAN);
break;
case 112:
OUT_RXString(cursor, hf_afs_bos_file);
break;
case 113:
break;
case 114:
OUT_RXString(cursor, hf_afs_bos_content);
break;
}
}
static void
dissect_vol_reply(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode)
{
if ( rxinfo->type == RX_PACKET_TYPE_DATA )
{
switch ( opcode )
{
case 121:
ptvcursor_add(cursor, hf_afs_vol_count, 4, ENC_BIG_ENDIAN);
OUT_RXStringV(cursor, hf_afs_vol_name, 32);
break;
}
}
else if ( rxinfo->type == RX_PACKET_TYPE_ABORT )
{
ptvcursor_add(cursor, hf_afs_vol_errcode, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_vol_request(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_, int opcode)
{
ptvcursor_advance(cursor, 4);
switch ( opcode )
{
case 121:
ptvcursor_add(cursor, hf_afs_vol_count, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vol_id, 4, ENC_BIG_ENDIAN);
break;
}
}
static void
dissect_kauth_reply(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode)
{
if ( rxinfo->type == RX_PACKET_TYPE_DATA )
{
switch ( opcode )
{
}
}
else if ( rxinfo->type == RX_PACKET_TYPE_ABORT )
{
ptvcursor_add(cursor, hf_afs_kauth_errcode, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_kauth_request(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_, int opcode)
{
ptvcursor_advance(cursor, 4);
switch ( opcode )
{
case 1:
case 21:
case 22:
case 2:
case 5:
case 6:
case 7:
case 8:
case 14:
case 15:
OUT_RXString(cursor, hf_afs_kauth_princ);
OUT_RXString(cursor, hf_afs_kauth_realm);
ptvcursor_add(cursor, hf_afs_kauth_data, -1, ENC_NA);
break;
case 3:
case 23:
OUT_KAUTH_GetTicket(cursor);
break;
case 4:
OUT_RXString(cursor, hf_afs_kauth_princ);
OUT_RXString(cursor, hf_afs_kauth_realm);
ptvcursor_add(cursor, hf_afs_kauth_kvno, 4, ENC_BIG_ENDIAN);
break;
case 12:
OUT_RXString(cursor, hf_afs_kauth_name);
break;
}
}
static void
dissect_cb_reply(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode)
{
if ( rxinfo->type == RX_PACKET_TYPE_DATA )
{
switch ( opcode ) {
case 65538:
OUT_CM_INTERFACES(cursor);
OUT_CM_CAPABILITIES(cursor);
break;
}
}
else if ( rxinfo->type == RX_PACKET_TYPE_ABORT )
{
ptvcursor_add(cursor, hf_afs_cb_errcode, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_cb_request(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_, int opcode)
{
ptvcursor_advance(cursor, 4);
switch ( opcode )
{
case 204:
OUT_RXArray32(OUT_CB_AFSFid(cursor, "Target"));
OUT_RXArray32(OUT_CB_AFSCallBack(cursor));
break;
}
}
static void
dissect_prot_reply(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode)
{
if ( rxinfo->type == RX_PACKET_TYPE_DATA )
{
switch ( opcode )
{
case 504:
{
unsigned int i, size;
size = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_afs_prot_count, 4, ENC_BIG_ENDIAN);
for (i=0; i<size; i++)
{
ptvcursor_add(cursor, hf_afs_prot_id, 4, ENC_BIG_ENDIAN);
}
}
break;
case 505:
{
unsigned int i, size;
size = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_afs_prot_count, 4, ENC_BIG_ENDIAN);
for (i=0; i<size; i++)
{
OUT_RXStringV(cursor, hf_afs_prot_name, PRNAMEMAX);
}
}
break;
case 508:
case 514:
case 517:
case 518:
case 519:
{
unsigned int i, size;
size = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_afs_prot_count, 4, ENC_BIG_ENDIAN);
for (i=0; i<size; i++)
{
ptvcursor_add(cursor, hf_afs_prot_id, 4, ENC_BIG_ENDIAN);
}
}
break;
case 510:
ptvcursor_add(cursor, hf_afs_prot_maxuid, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_prot_maxgid, 4, ENC_BIG_ENDIAN);
break;
}
}
else if ( rxinfo->type == RX_PACKET_TYPE_ABORT )
{
ptvcursor_add(cursor, hf_afs_prot_errcode, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_prot_request(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_, int opcode)
{
ptvcursor_advance(cursor, 4);
switch ( opcode )
{
case 500:
OUT_RXString(cursor, hf_afs_prot_name_uint_string);
ptvcursor_add(cursor, hf_afs_prot_id, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_prot_oldid, 4, ENC_BIG_ENDIAN);
break;
case 501:
case 506:
case 508:
case 512:
case 514:
case 517:
case 519:
ptvcursor_add(cursor, hf_afs_prot_id, 4, ENC_BIG_ENDIAN);
break;
case 502:
ptvcursor_add(cursor, hf_afs_prot_pos, 4, ENC_BIG_ENDIAN);
break;
case 503:
case 507:
case 515:
ptvcursor_add(cursor, hf_afs_prot_uid, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_prot_gid, 4, ENC_BIG_ENDIAN);
break;
case 504:
{
unsigned int i, size;
size = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_afs_prot_count, 4, ENC_BIG_ENDIAN);
for (i=0; i<size; i++)
{
OUT_RXStringV(cursor, hf_afs_prot_name,PRNAMEMAX);
}
}
break;
case 505:
{
unsigned int i, size;
size = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_afs_prot_count, 4, ENC_BIG_ENDIAN);
for (i=0; i<size; i++)
{
ptvcursor_add(cursor, hf_afs_prot_id, 4, ENC_BIG_ENDIAN);
}
}
break;
case 509:
OUT_RXString(cursor, hf_afs_prot_name_uint_string);
ptvcursor_add(cursor, hf_afs_prot_flag, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_prot_oldid, 4, ENC_BIG_ENDIAN);
break;
case 511:
ptvcursor_add(cursor, hf_afs_prot_id, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_prot_flag, 4, ENC_BIG_ENDIAN);
break;
case 513:
ptvcursor_add(cursor, hf_afs_prot_id, 4, ENC_BIG_ENDIAN);
OUT_RXString(cursor, hf_afs_prot_name_uint_string);
ptvcursor_add(cursor, hf_afs_prot_oldid, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_prot_newid, 4, ENC_BIG_ENDIAN);
break;
case 520:
ptvcursor_add(cursor, hf_afs_prot_id, 4, ENC_BIG_ENDIAN);
OUT_RXString(cursor, hf_afs_prot_name_uint_string);
break;
}
}
static void
dissect_vldb_reply(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode)
{
static const int * vldb_flags[] = {
&hf_afs_vldb_flags_rwexists,
&hf_afs_vldb_flags_roexists,
&hf_afs_vldb_flags_bkexists,
&hf_afs_vldb_flags_dfsfileset,
NULL
};
if ( rxinfo->type == RX_PACKET_TYPE_DATA )
{
switch ( opcode )
{
case 510:
ptvcursor_add(cursor, hf_afs_vldb_count, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_nextindex, 4, ENC_BIG_ENDIAN);
break;
case 503:
case 504:
{
int nservers,i,j;
OUT_RXStringV(cursor, hf_afs_vldb_name, VLNAMEMAX);
ptvcursor_advance(cursor, 4);
nservers = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_afs_vldb_numservers, 4, ENC_BIG_ENDIAN);
for (i=0; i<8; i++)
{
if ( i<nservers )
{
ptvcursor_add(cursor, hf_afs_vldb_server, 4, ENC_BIG_ENDIAN);
}
else
{
ptvcursor_advance(cursor, 4);
}
}
for (i=0; i<8; i++)
{
char *part = wmem_strdup(wmem_packet_scope(), "/vicepa");
j = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
if ( i<nservers && j<=25 )
{
part[6] = 'a' + (char) j;
proto_tree_add_string(ptvcursor_tree(cursor), hf_afs_vldb_partition, ptvcursor_tvbuff(cursor),
ptvcursor_current_offset(cursor), 4, part);
}
ptvcursor_advance(cursor, 4);
}
ptvcursor_advance(cursor, 8*4);
ptvcursor_add(cursor, hf_afs_vldb_rwvol, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_rovol, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_bkvol, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_clonevol, 4, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(ptvcursor_tree(cursor), ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), hf_afs_vldb_flags,
ett_afs_vldb_flags, vldb_flags, ENC_BIG_ENDIAN);
ptvcursor_advance(cursor, 4);
}
break;
case 505:
ptvcursor_add(cursor, hf_afs_vldb_id, 4, ENC_BIG_ENDIAN);
break;
case 521:
case 529:
ptvcursor_add(cursor, hf_afs_vldb_count, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_nextindex, 4, ENC_BIG_ENDIAN);
break;
case 518:
case 519:
{
int nservers,i,j;
OUT_RXStringV(cursor, hf_afs_vldb_name, VLNAMEMAX);
nservers = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_afs_vldb_numservers, 4, ENC_BIG_ENDIAN);
for (i=0; i<13; i++)
{
if ( i<nservers )
{
ptvcursor_add(cursor, hf_afs_vldb_server, 4, ENC_BIG_ENDIAN);
}
else
{
ptvcursor_advance(cursor, 4);
}
}
for (i=0; i<13; i++)
{
char *part = wmem_strdup(wmem_packet_scope(), "/vicepa");
j = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
if ( i<nservers && j<=25 )
{
part[6] = 'a' + (char) j;
proto_tree_add_string(ptvcursor_tree(cursor), hf_afs_vldb_partition, ptvcursor_tvbuff(cursor),
ptvcursor_current_offset(cursor), 4, part);
}
ptvcursor_advance(cursor, 4);
}
ptvcursor_advance(cursor, 13*4);
ptvcursor_add(cursor, hf_afs_vldb_rwvol, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_rovol, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_bkvol, 4, ENC_BIG_ENDIAN);
}
break;
case 526:
case 527:
{
int nservers,i,j;
OUT_RXStringV(cursor, hf_afs_vldb_name, VLNAMEMAX);
nservers = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_afs_vldb_numservers, 4, ENC_BIG_ENDIAN);
for (i=0; i<13; i++)
{
if ( i<nservers )
{
ptvcursor_add(cursor, hf_afs_vldb_serveruuid, 4*11, ENC_NA);
}
else
{
ptvcursor_advance(cursor, 4*11);
}
}
for (i=0; i<13; i++)
{
if ( i<nservers )
{
ptvcursor_add(cursor, hf_afs_vldb_serveruniq, 4, ENC_BIG_ENDIAN);
}
else
{
ptvcursor_advance(cursor, 4);
}
}
for (i=0; i<13; i++)
{
char *part = wmem_strdup(wmem_packet_scope(), "/vicepa");
j = tvb_get_ntohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
if ( i<nservers && j<=25 )
{
part[6] = 'a' + (char) j;
proto_tree_add_string(ptvcursor_tree(cursor), hf_afs_vldb_partition, ptvcursor_tvbuff(cursor),
ptvcursor_current_offset(cursor), 4, part);
}
ptvcursor_advance(cursor, 4);
}
for (i=0; i<13; i++)
{
if ( i<nservers )
{
ptvcursor_add(cursor, hf_afs_vldb_serverflags, 4, ENC_BIG_ENDIAN);
}
else
{
ptvcursor_advance(cursor, 4);
}
}
ptvcursor_add(cursor, hf_afs_vldb_rwvol, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_rovol, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_bkvol, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_clonevol, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_flags, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_spare1, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_spare2, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_spare3, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_spare4, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_spare5, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_spare6, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_spare7, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_spare8, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_spare9, 4, ENC_BIG_ENDIAN);
}
break;
}
}
else if ( rxinfo->type == RX_PACKET_TYPE_ABORT )
{
ptvcursor_add(cursor, hf_afs_vldb_errcode, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_vldb_request(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_, int opcode)
{
ptvcursor_advance(cursor, 4);
switch ( opcode )
{
case 501:
case 517:
OUT_RXStringV(cursor, hf_afs_vldb_name, VLNAMEMAX);
break;
case 502:
case 503:
case 507:
case 508:
case 509:
case 518:
ptvcursor_add(cursor, hf_afs_vldb_id, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_type, 4, ENC_BIG_ENDIAN);
break;
case 504:
case 519:
case 524:
case 527:
OUT_RXString(cursor, hf_afs_vldb_name_uint_string);
break;
case 505:
ptvcursor_add(cursor, hf_afs_vldb_bump, 4, ENC_BIG_ENDIAN);
break;
case 506:
case 520:
ptvcursor_add(cursor, hf_afs_vldb_id, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_vldb_type, 4, ENC_BIG_ENDIAN);
OUT_RXStringV(cursor, hf_afs_vldb_name, VLNAMEMAX);
break;
case 510:
case 521:
ptvcursor_add(cursor, hf_afs_vldb_index, 4, ENC_BIG_ENDIAN);
break;
case 532:
ptvcursor_add(cursor, hf_afs_vldb_serveruuid, 4*11, ENC_NA);
ptvcursor_add(cursor, hf_afs_vldb_spare1, 4, ENC_BIG_ENDIAN);
OUT_RXArray32(ptvcursor_add(cursor, hf_afs_vldb_serverip, 4, ENC_BIG_ENDIAN));
break;
}
}
static void
dissect_ubik_reply(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_, int opcode)
{
switch ( opcode )
{
case 10000:
break;
case 10001:
OUT_UBIK_DebugOld(cursor);
break;
case 10002:
OUT_UBIK_SDebugOld(cursor);
break;
case 10003:
break;
case 10004:
OUT_UBIK_DebugOld(cursor);
OUT_UBIK_InterfaceAddrs(cursor);
break;
case 10005:
OUT_UBIK_SDebugOld(cursor);
OUT_UBIK_InterfaceAddrs(cursor);
break;
case 10006:
OUT_UBIK_DebugOld(cursor);
OUT_UBIK_InterfaceAddrs(cursor);
ptvcursor_add(cursor, hf_afs_ubik_isclone, 4, ENC_BIG_ENDIAN);
break;
case 10007:
OUT_UBIK_SDebugOld(cursor);
OUT_UBIK_InterfaceAddrs(cursor);
ptvcursor_add(cursor, hf_afs_ubik_isclone, 4, ENC_BIG_ENDIAN);
break;
case 20000:
break;
case 20004:
OUT_UBIKVERSION(cursor, "DB Version");
break;
case 20010:
break;
case 20012:
OUT_UBIK_InterfaceAddrs(cursor);
break;
}
}
static void
dissect_ubik_request(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_, int opcode)
{
ptvcursor_advance(cursor, 4);
switch ( opcode )
{
case 10000:
ptvcursor_add(cursor, hf_afs_ubik_state, 4, ENC_BIG_ENDIAN);
OUT_TIMESECS(cursor, hf_afs_ubik_votestart);
OUT_UBIKVERSION(cursor, "DB Version");
OUT_UBIKVERSION(cursor, "TID");
break;
case 10001:
break;
case 10002:
ptvcursor_add(cursor, hf_afs_ubik_site, 4, ENC_BIG_ENDIAN);
break;
case 10003:
ptvcursor_add(cursor, hf_afs_ubik_site, 4, ENC_BIG_ENDIAN);
break;
case 10004:
case 10005:
ptvcursor_add(cursor, hf_afs_ubik_site, 4, ENC_BIG_ENDIAN);
break;
case 20000:
OUT_UBIKVERSION(cursor, "TID");
break;
case 20001:
OUT_UBIKVERSION(cursor, "TID");
break;
case 20002:
OUT_UBIKVERSION(cursor, "TID");
ptvcursor_add(cursor, hf_afs_ubik_file, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_pos, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_length, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_locktype, 4, ENC_BIG_ENDIAN);
break;
case 20003:
OUT_UBIKVERSION(cursor, "TID");
ptvcursor_add(cursor, hf_afs_ubik_file, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_pos, 4, ENC_BIG_ENDIAN);
break;
case 20004:
break;
case 20005:
ptvcursor_add(cursor, hf_afs_ubik_file, 4, ENC_BIG_ENDIAN);
break;
case 20006:
ptvcursor_add(cursor, hf_afs_ubik_file, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_length, 4, ENC_BIG_ENDIAN);
OUT_UBIKVERSION(cursor, "DB Version");
break;
case 20007:
case 20008:
case 20010:
break;
case 20009:
OUT_UBIKVERSION(cursor, "TID");
ptvcursor_add(cursor, hf_afs_ubik_file, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_afs_ubik_length, 4, ENC_BIG_ENDIAN);
break;
case 20011:
OUT_UBIKVERSION(cursor, "TID");
break;
case 20012:
OUT_UBIK_InterfaceAddrs(cursor);
break;
case 20013:
OUT_UBIKVERSION(cursor, "TID");
OUT_UBIKVERSION(cursor, "Old DB Version");
OUT_UBIKVERSION(cursor, "New DB Version");
break;
}
}
static void
dissect_backup_reply(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode)
{
if ( rxinfo->type == RX_PACKET_TYPE_DATA )
{
switch ( opcode )
{
}
}
else if ( rxinfo->type == RX_PACKET_TYPE_ABORT )
{
ptvcursor_add(cursor, hf_afs_backup_errcode, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_backup_request(ptvcursor_t *cursor, struct rxinfo *rxinfo _U_, int opcode)
{
ptvcursor_advance(cursor, 4);
switch ( opcode )
{
}
}
static int
dissect_afs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
struct rxinfo *rxinfo = (struct rxinfo *)data;
int reply = 0;
conversation_t *conversation;
struct afs_request_key request_key, *new_request_key;
struct afs_request_val *request_val=NULL;
proto_tree *afs_tree, *afs_op_tree, *ti;
proto_item *hidden_item;
int port, node, typenode, opcode;
value_string_ext *vals_ext;
int offset = 0;
nstime_t delta_ts;
guint8 save_fragmented;
int reassembled = 0;
ptvcursor_t *cursor;
void (*dissector)(ptvcursor_t *cursor, struct rxinfo *rxinfo, int opcode);
if (data == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AFS (RX)");
col_clear(pinfo->cinfo, COL_INFO);
reply = (rxinfo->flags & RX_CLIENT_INITIATED) == 0;
port = ((reply == 0) ? pinfo->destport : pinfo->srcport );
conversation = find_or_create_conversation(pinfo);
request_key.conversation = conversation->conv_index;
request_key.service = rxinfo->serviceid;
request_key.epoch = rxinfo->epoch;
request_key.cid = rxinfo->cid;
request_key.callnumber = rxinfo->callnumber;
request_val = (struct afs_request_val *) g_hash_table_lookup(
afs_request_hash, &request_key);
opcode = 0;
if(!pinfo->fd->flags.visited){
if ( !request_val && !reply) {
new_request_key = wmem_new(wmem_file_scope(), struct afs_request_key);
*new_request_key = request_key;
request_val = wmem_new(wmem_file_scope(), struct afs_request_val);
request_val -> opcode = tvb_get_ntohl(tvb, offset);
request_val -> req_num = pinfo->num;
request_val -> rep_num = 0;
request_val -> req_time = pinfo->abs_ts;
g_hash_table_insert(afs_request_hash, new_request_key,
request_val);
}
if( request_val && reply ) {
request_val -> rep_num = pinfo->num;
}
}
if ( request_val ) {
opcode = request_val->opcode;
}
node = 0;
typenode = 0;
vals_ext = NULL;
dissector = NULL;
switch (port) {
case AFS_PORT_FS:
typenode = hf_afs_fs;
node = hf_afs_fs_opcode;
vals_ext = &fs_req_ext;
dissector = reply ? dissect_fs_reply : dissect_fs_request;
break;
case AFS_PORT_CB:
typenode = hf_afs_cb;
node = hf_afs_cb_opcode;
vals_ext = &cb_req_ext;
dissector = reply ? dissect_cb_reply : dissect_cb_request;
break;
case AFS_PORT_PROT:
typenode = hf_afs_prot;
node = hf_afs_prot_opcode;
vals_ext = &prot_req_ext;
dissector = reply ? dissect_prot_reply : dissect_prot_request;
break;
case AFS_PORT_VLDB:
typenode = hf_afs_vldb;
node = hf_afs_vldb_opcode;
vals_ext = &vldb_req_ext;
dissector = reply ? dissect_vldb_reply : dissect_vldb_request;
break;
case AFS_PORT_KAUTH:
typenode = hf_afs_kauth;
node = hf_afs_kauth_opcode;
vals_ext = &kauth_req_ext;
dissector = reply ? dissect_kauth_reply : dissect_kauth_request;
break;
case AFS_PORT_VOL:
typenode = hf_afs_vol;
node = hf_afs_vol_opcode;
vals_ext = &vol_req_ext;
dissector = reply ? dissect_vol_reply : dissect_vol_request;
break;
case AFS_PORT_ERROR:
typenode = hf_afs_error;
node = hf_afs_error_opcode;
break;
case AFS_PORT_BOS:
typenode = hf_afs_bos;
node = hf_afs_bos_opcode;
vals_ext = &bos_req_ext;
dissector = reply ? dissect_bos_reply : dissect_bos_request;
break;
case AFS_PORT_UPDATE:
typenode = hf_afs_update;
node = hf_afs_update_opcode;
vals_ext = &update_req_ext;
break;
case AFS_PORT_RMTSYS:
typenode = hf_afs_rmtsys;
node = hf_afs_rmtsys_opcode;
vals_ext = &rmtsys_req_ext;
break;
case AFS_PORT_BACKUP:
typenode = hf_afs_backup;
node = hf_afs_backup_opcode;
vals_ext = &backup_req_ext;
dissector = reply ? dissect_backup_reply : dissect_backup_request;
break;
}
if ( (opcode >= VOTE_LOW && opcode <= VOTE_HIGH) ||
(opcode >= DISK_LOW && opcode <= DISK_HIGH) ) {
typenode = hf_afs_ubik;
node = hf_afs_ubik_opcode;
vals_ext = &ubik_req_ext;
dissector = reply ? dissect_ubik_reply : dissect_ubik_request;
}
if ( VALID_OPCODE(opcode) ) {
if ( vals_ext ) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s%s %s: %s (%d)",
typenode == hf_afs_ubik ? "UBIK-" : "",
val_to_str_ext(port, &port_types_short_ext, "Unknown(%d)"),
reply ? "Reply" : "Request",
val_to_str_ext(opcode, vals_ext, "Unknown(%d)"), opcode);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s%s %s: Unknown(%d)",
typenode == hf_afs_ubik ? "UBIK-" : "",
val_to_str_ext(port, &port_types_short_ext, "Unknown(%d)"),
reply ? "Reply" : "Request",
opcode);
}
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "Encrypted %s %s",
val_to_str_ext(port, &port_types_short_ext, "Unknown(%d)"),
reply ? "Reply" : "Request"
);
}
ti = proto_tree_add_item(tree, proto_afs, tvb, offset,
tvb_reported_length_remaining(tvb, offset),
ENC_NA);
afs_tree = proto_item_add_subtree(ti, ett_afs);
save_fragmented = pinfo->fragmented;
if( (! (rxinfo->flags & RX_LAST_PACKET) || rxinfo->seq > 1 )) {
tvbuff_t * new_tvb = NULL;
fragment_head * frag_msg = NULL;
guint32 afs_seqid = rxinfo->callnumber ^ rxinfo->cid;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&afs_reassembly_table,
tvb, offset, pinfo, afs_seqid, NULL,
rxinfo->seq-1, tvb_captured_length_remaining(tvb, offset),
! ( rxinfo->flags & RX_LAST_PACKET ) );
new_tvb = process_reassembled_data( tvb, offset, pinfo, "Reassembled RX", frag_msg,
&afs_frag_items, NULL, afs_tree );
if (new_tvb) {
tvb = new_tvb;
reassembled = 1;
col_append_str(pinfo->cinfo, COL_INFO, " [AFS reassembled]");
} else {
col_set_str(pinfo->cinfo, COL_INFO, "[AFS segment of a reassembled PDU]");
return tvb_captured_length(tvb);
}
}
pinfo->fragmented = save_fragmented;
if (tree) {
proto_tree_add_uint_format_value(afs_tree, hf_afs_service, tvb, 0, 0,
opcode, "%s%s%s %s",
VALID_OPCODE(opcode) ? "" : "Encrypted ",
typenode == hf_afs_ubik ? "UBIK - " : "",
val_to_str_ext(port, &port_types_ext, "Unknown(%d)"),
reply ? "Reply" : "Request");
if( request_val && !reply && request_val->rep_num) {
proto_tree_add_uint_format(afs_tree, hf_afs_repframe,
tvb, 0, 0, request_val->rep_num,
"The reply to this request is in frame %u",
request_val->rep_num);
}
if( request_val && reply && request_val->rep_num) {
proto_tree_add_uint_format(afs_tree, hf_afs_reqframe,
tvb, 0, 0, request_val->req_num,
"This is a reply to a request in frame %u",
request_val->req_num);
nstime_delta(&delta_ts, &pinfo->abs_ts, &request_val->req_time);
proto_tree_add_time(afs_tree, hf_afs_time, tvb, offset, 0,
&delta_ts);
}
if ( VALID_OPCODE(opcode) ) {
ti = NULL;
if ( !reply && node != 0 ) {
if ( rxinfo->seq == 1 || reassembled )
{
ti = proto_tree_add_uint(afs_tree,
node, tvb, offset, 4, opcode);
} else {
ti = proto_tree_add_uint(afs_tree,
node, tvb, 0, 0, opcode);
}
afs_op_tree = proto_item_add_subtree(ti, ett_afs_op);
} else if ( reply && node != 0 ) {
ti = proto_tree_add_uint(afs_tree,
node, tvb, 0, 0, opcode);
afs_op_tree = proto_item_add_subtree(ti, ett_afs_op);
} else {
afs_op_tree = proto_tree_add_subtree(afs_tree, tvb, 0, 0, ett_afs_op, &ti, "Operation: Unknown");
}
if ( typenode != 0 ) {
hidden_item = proto_tree_add_boolean(afs_tree, typenode, tvb, offset, 0, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if ( dissector && ( rxinfo->seq == 1 || reassembled ) ) {
cursor = ptvcursor_new(afs_op_tree, tvb, offset);
(*dissector)(cursor, rxinfo, opcode);
}
}
}
if ( rxinfo->flags & RX_LAST_PACKET && reply ){
}
return tvb_captured_length(tvb);
}
void
proto_register_afs(void)
{
static hf_register_info hf[] = {
{ &hf_afs_fs, { "File Server", "afs.fs",
FT_BOOLEAN, BASE_NONE, 0, 0x0, NULL, HFILL }},
{ &hf_afs_cb, { "Callback", "afs.cb",
FT_BOOLEAN, BASE_NONE, 0, 0x0, NULL, HFILL }},
{ &hf_afs_prot, { "Protection", "afs.prot",
FT_BOOLEAN, BASE_NONE, 0, 0x0, "Protection Server", HFILL }},
{ &hf_afs_vldb, { "VLDB", "afs.vldb",
FT_BOOLEAN, BASE_NONE, 0, 0x0, "Volume Location Database Server", HFILL }},
{ &hf_afs_kauth, { "KAuth", "afs.kauth",
FT_BOOLEAN, BASE_NONE, 0, 0x0, "Kerberos Auth Server", HFILL }},
{ &hf_afs_vol, { "Volume Server", "afs.vol",
FT_BOOLEAN, BASE_NONE, 0, 0x0, NULL, HFILL }},
{ &hf_afs_error, { "Error", "afs.error",
FT_BOOLEAN, BASE_NONE, 0, 0x0, NULL, HFILL }},
{ &hf_afs_bos, { "BOS", "afs.bos",
FT_BOOLEAN, BASE_NONE, 0, 0x0, "Basic Oversee Server", HFILL }},
{ &hf_afs_update, { "Update", "afs.update",
FT_BOOLEAN, BASE_NONE, 0, 0x0, "Update Server", HFILL }},
{ &hf_afs_rmtsys, { "Rmtsys", "afs.rmtsys",
FT_BOOLEAN, BASE_NONE, 0, 0x0, NULL, HFILL }},
{ &hf_afs_ubik, { "Ubik", "afs.ubik",
FT_BOOLEAN, BASE_NONE, 0, 0x0, NULL, HFILL }},
{ &hf_afs_backup, { "Backup", "afs.backup",
FT_BOOLEAN, BASE_NONE, 0, 0x0, "Backup Server", HFILL }},
{ &hf_afs_service, { "Service", "afs.service",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_afs_fs_opcode, { "Operation", "afs.fs.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&fs_req_ext, 0, NULL, HFILL }},
{ &hf_afs_cb_opcode, { "Operation", "afs.cb.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&cb_req_ext, 0, NULL, HFILL }},
{ &hf_afs_prot_opcode, { "Operation", "afs.prot.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&prot_req_ext, 0, NULL, HFILL }},
{ &hf_afs_vldb_opcode, { "Operation", "afs.vldb.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&vldb_req_ext, 0, NULL, HFILL }},
{ &hf_afs_kauth_opcode, { "Operation", "afs.kauth.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&kauth_req_ext, 0, NULL, HFILL }},
{ &hf_afs_vol_opcode, { "Operation", "afs.vol.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&vol_req_ext, 0, NULL, HFILL }},
{ &hf_afs_bos_opcode, { "Operation", "afs.bos.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&bos_req_ext, 0, NULL, HFILL }},
{ &hf_afs_update_opcode, { "Operation", "afs.update.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&update_req_ext, 0, NULL, HFILL }},
{ &hf_afs_rmtsys_opcode, { "Operation", "afs.rmtsys.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&rmtsys_req_ext, 0, NULL, HFILL }},
{ &hf_afs_error_opcode, { "Operation", "afs.error.opcode",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_backup_opcode, { "Operation", "afs.backup.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&backup_req_ext, 0, NULL, HFILL }},
{ &hf_afs_ubik_opcode, { "Operation", "afs.ubik.opcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&ubik_req_ext, 0, NULL, HFILL }},
{ &hf_afs_fs_fid_volume, { "FileID (Volume)", "afs.fs.fid.volume",
FT_UINT32, BASE_DEC, 0, 0, "File ID (Volume)", HFILL }},
{ &hf_afs_fs_fid_vnode, { "FileID (VNode)", "afs.fs.fid.vnode",
FT_UINT32, BASE_DEC, 0, 0, "File ID (VNode)", HFILL }},
{ &hf_afs_fs_fid_uniqifier, { "FileID (Uniqifier)", "afs.fs.fid.uniq",
FT_UINT32, BASE_DEC, 0, 0, "File ID (Uniqifier)", HFILL }},
{ &hf_afs_fs_offset, { "Offset", "afs.fs.offset",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_length, { "Length", "afs.fs.length",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_flength, { "FLength", "afs.fs.flength",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_offset64, { "Offset64", "afs.fs.offset64",
FT_UINT64, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_length64, { "Length64", "afs.fs.length64",
FT_UINT64, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_flength64, { "FLength64", "afs.fs.flength64",
FT_UINT64, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_errcode, { "Error Code", "afs.fs.errcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &afs_errors_ext, 0, NULL, HFILL }},
{ &hf_afs_fs_data, { "Data", "afs.fs.data",
FT_BYTES, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_token, { "Token", "afs.fs.token",
FT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_oldname, { "Old Name", "afs.fs.oldname",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_newname, { "New Name", "afs.fs.newname",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_name, { "Name", "afs.fs.name",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_symlink_name, { "Symlink Name", "afs.fs.symlink.name",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_symlink_content, { "Symlink Content", "afs.fs.symlink.content",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_volid, { "Volume ID", "afs.fs.volid",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_volname, { "Volume Name", "afs.fs.volname",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_timestamp, { "Timestamp", "afs.fs.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_offlinemsg, { "Offline Message", "afs.fs.offlinemsg",
FT_UINT_STRING, BASE_NONE, 0, 0, "Volume Name", HFILL }},
{ &hf_afs_fs_motd, { "Message of the Day", "afs.fs.motd",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_xstats_version, { "XStats Version", "afs.fs.xstats.version",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_xstats_clientversion, { "Client Version", "afs.fs.xstats.clientversion",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_xstats_collnumber, { "Collection Number", "afs.fs.xstats.collnumber",
FT_UINT32, BASE_DEC, VALS(xstat_collections), 0, NULL, HFILL }},
{ &hf_afs_fs_xstats_timestamp, { "XStats Timestamp", "afs.fs.xstats.timestamp",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_cps_spare1, { "CPS Spare1", "afs.fs.cps.spare1",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_cps_spare2, { "CPS Spare2", "afs.fs.cps.spare2",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_cps_spare3, { "CPS Spare3", "afs.fs.cps.spare3",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_vicelocktype, { "Vice Lock Type", "afs.fs.vicelocktype",
FT_UINT32, BASE_DEC, VALS(vice_lock_types), 0, NULL, HFILL }},
{ &hf_afs_fs_viceid, { "Vice ID", "afs.fs.viceid",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_ipaddr, { "IP Addr", "afs.fs.ipaddr",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_mask, { "Mask", "afs.fs.status.mask",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_mask_setmodtime, { "Set Modification Time", "afs.fs.status.mask.setmodtime",
FT_BOOLEAN, 32, 0, 0x00000001, NULL, HFILL }},
{ &hf_afs_fs_status_mask_setowner, { "Set Owner", "afs.fs.status.mask.setowner",
FT_BOOLEAN, 32, 0, 0x00000002, NULL, HFILL }},
{ &hf_afs_fs_status_mask_setgroup, { "Set Group", "afs.fs.status.mask.setgroup",
FT_BOOLEAN, 32, 0, 0x00000004, NULL, HFILL }},
{ &hf_afs_fs_status_mask_setmode, { "Set Mode", "afs.fs.status.mask.setmode",
FT_BOOLEAN, 32, 0, 0x00000008, NULL, HFILL }},
{ &hf_afs_fs_status_mask_setsegsize, { "Set Segment Size", "afs.fs.status.mask.setsegsize",
FT_BOOLEAN, 32, 0, 0x00000010, NULL, HFILL }},
{ &hf_afs_fs_status_mask_fsync, { "FSync", "afs.fs.status.mask.fsync",
FT_BOOLEAN, 32, 0, 0x00000400, NULL, HFILL }},
{ &hf_afs_fs_status_clientmodtime, { "Client Modification Time", "afs.fs.status.clientmodtime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_servermodtime, { "Server Modification Time", "afs.fs.status.servermodtime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_owner, { "Owner", "afs.fs.status.owner",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_group, { "Group", "afs.fs.status.group",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_mode, { "Unix Mode", "afs.fs.status.mode",
FT_UINT32, BASE_OCT, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_segsize, { "Segment Size", "afs.fs.status.segsize",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_interfaceversion, { "Interface Version", "afs.fs.status.interfaceversion",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_filetype, { "File Type", "afs.fs.status.filetype",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_author, { "Author", "afs.fs.status.author",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_calleraccess, { "Caller Access", "afs.fs.status.calleraccess",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_anonymousaccess, { "Anonymous Access", "afs.fs.status.anonymousaccess",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_parentvnode, { "Parent VNode", "afs.fs.status.parentvnode",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_parentunique, { "Parent Unique", "afs.fs.status.parentunique",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_dataversion, { "Data Version", "afs.fs.status.dataversion",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_dataversionhigh, { "Data Version (High)", "afs.fs.status.dataversionhigh",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_linkcount, { "Link Count", "afs.fs.status.linkcount",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_spare2, { "Spare 2", "afs.fs.status.spare2",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_spare3, { "Spare 3", "afs.fs.status.spare3",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_spare4, { "Spare 4", "afs.fs.status.spare4",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_synccounter, { "Sync Counter", "afs.fs.status.synccounter",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_status_length, { "Length", "afs.fs.status.length",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_volsync_spare1, { "Volume Creation Timestamp", "afs.fs.volsync.spare1",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_volsync_spare2, { "Spare 2", "afs.fs.volsync.spare2",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_volsync_spare3, { "Spare 3", "afs.fs.volsync.spare3",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_volsync_spare4, { "Spare 4", "afs.fs.volsync.spare4",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_volsync_spare5, { "Spare 5", "afs.fs.volsync.spare5",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_volsync_spare6, { "Spare 6", "afs.fs.volsync.spare6",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_acl_count_positive, {
"ACL Count (Positive)", "afs.fs.acl.count.positive",
FT_UINT32, BASE_DEC, 0, 0, "Number of Positive ACLs", HFILL }},
{ &hf_afs_fs_acl_count_negative, {
"ACL Count (Negative)", "afs.fs.acl.count.negative",
FT_UINT32, BASE_DEC, 0, 0, "Number of Negative ACLs", HFILL }},
{ &hf_afs_fs_acl_datasize, {
"ACL Size", "afs.fs.acl.datasize",
FT_UINT32, BASE_DEC, 0, 0, "ACL Data Size", HFILL }},
{ &hf_afs_fs_acl_entity, {
"Entity (User/Group)", "afs.fs.acl.entity",
FT_STRING, BASE_NONE, 0, 0, "ACL Entity (User/Group)", HFILL }},
{ &hf_afs_fs_acl_r, {
"_R_ead", "afs.fs.acl.r",
FT_BOOLEAN, 8, 0, PRSFS_READ, "Read", HFILL }},
{ &hf_afs_fs_acl_l, {
"_L_ookup", "afs.fs.acl.l",
FT_BOOLEAN, 8, 0, PRSFS_LOOKUP, "Lookup", HFILL }},
{ &hf_afs_fs_acl_i, {
"_I_nsert", "afs.fs.acl.i",
FT_BOOLEAN, 8, 0, PRSFS_INSERT, "Insert", HFILL }},
{ &hf_afs_fs_acl_d, { "_D_elete", "afs.fs.acl.d",
FT_BOOLEAN, 8, 0, PRSFS_DELETE, "Delete", HFILL }},
{ &hf_afs_fs_acl_w, { "_W_rite", "afs.fs.acl.w",
FT_BOOLEAN, 8, 0, PRSFS_WRITE, "Write", HFILL }},
{ &hf_afs_fs_acl_k, { "_L_ock", "afs.fs.acl.k",
FT_BOOLEAN, 8, 0, PRSFS_LOCK, "Lock", HFILL }},
{ &hf_afs_fs_acl_a, { "_A_dminister", "afs.fs.acl.a",
FT_BOOLEAN, 8, 0, PRSFS_ADMINISTER, "Administer", HFILL }},
{ &hf_afs_fs_callback_version, { "Version", "afs.fs.callback.version",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_callback_expires, { "Expires", "afs.fs.callback.expires",
FT_RELATIVE_TIME, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_fs_callback_type, { "Type", "afs.fs.callback.type",
FT_UINT32, BASE_DEC, VALS(cb_types), 0, NULL, HFILL }},
{ &hf_afs_bos_errcode, { "Error Code", "afs.bos.errcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &afs_errors_ext, 0, NULL, HFILL }},
{ &hf_afs_bos_type, { "Type", "afs.bos.type",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_content, { "Content", "afs.bos.content",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_data, { "Data", "afs.bos.data",
FT_BYTES, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_path, { "Path", "afs.bos.path",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_parm, { "Parm", "afs.bos.parm",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_error, { "Error", "afs.bos.error",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_spare1, { "Spare1", "afs.bos.spare1",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_spare2, { "Spare2", "afs.bos.spare2",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_spare3, { "Spare3", "afs.bos.spare3",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_file, { "File", "afs.bos.file",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_cmd, { "Command", "afs.bos.cmd",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_key, { "Key", "afs.bos.key",
FT_BYTES, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_user, { "User", "afs.bos.user",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_instance, { "Instance", "afs.bos.instance",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_status, { "Status", "afs.bos.status",
FT_INT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_statusdesc, { "Status Description", "afs.bos.statusdesc",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_num, { "Number", "afs.bos.number",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_size, { "Size", "afs.bos.size",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_flags, { "Flags", "afs.bos.flags",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_date, { "Date", "afs.bos.date",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_kvno, { "Key Version Number", "afs.bos.kvno",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_cell, { "Cell", "afs.bos.cell",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_host, { "Host", "afs.bos.host",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_newtime, { "New Time", "afs.bos.newtime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_baktime, { "Backup Time", "afs.bos.baktime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_oldtime, { "Old Time", "afs.bos.oldtime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_keymodtime, { "Key Modification Time", "afs.bos.keymodtime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_keychecksum, { "Key Checksum", "afs.bos.keychecksum",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_bos_keyspare2, { "Key Spare 2", "afs.bos.keyspare2",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_kauth_errcode, { "Error Code", "afs.kauth.errcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &afs_errors_ext, 0, NULL, HFILL }},
{ &hf_afs_kauth_princ, { "Principal", "afs.kauth.princ",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_kauth_realm, { "Realm", "afs.kauth.realm",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_kauth_domain, { "Domain", "afs.kauth.domain",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_kauth_name, { "Name", "afs.kauth.name",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_kauth_data, { "Data", "afs.kauth.data",
FT_BYTES, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_kauth_kvno, { "Key Version Number", "afs.kauth.kvno",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vol_errcode, { "Error Code", "afs.vol.errcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &afs_errors_ext, 0, NULL, HFILL }},
{ &hf_afs_vol_id, { "Volume ID", "afs.vol.id",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vol_count, { "Volume Count", "afs.vol.count",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vol_name, { "Volume Name", "afs.vol.name",
FT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_errcode, { "Error Code", "afs.vldb.errcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &afs_errors_ext, 0, NULL, HFILL }},
{ &hf_afs_vldb_type, { "Volume Type", "afs.vldb.type",
FT_UINT32, BASE_HEX, VALS(volume_types), 0, NULL, HFILL }},
{ &hf_afs_vldb_id, { "Volume ID", "afs.vldb.id",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_bump, { "Bumped Volume ID", "afs.vldb.bump",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_index, { "Volume Index", "afs.vldb.index",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_count, { "Volume Count", "afs.vldb.count",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_numservers, { "Number of Servers", "afs.vldb.numservers",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_nextindex, { "Next Volume Index", "afs.vldb.nextindex",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_rovol, { "Read-Only Volume ID", "afs.vldb.rovol",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_rwvol, { "Read-Write Volume ID", "afs.vldb.rwvol",
FT_UINT32, BASE_DEC, 0, 0, "Read-Only Volume ID", HFILL }},
{ &hf_afs_vldb_bkvol, { "Backup Volume ID", "afs.vldb.bkvol",
FT_UINT32, BASE_DEC, 0, 0, "Read-Only Volume ID", HFILL }},
{ &hf_afs_vldb_clonevol, { "Clone Volume ID", "afs.vldb.clonevol",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_name, { "Volume Name", "afs.vldb.name",
FT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_name_uint_string, { "Volume Name", "afs.vldb.name",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_partition, { "Partition", "afs.vldb.partition",
FT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_server, { "Server", "afs.vldb.server",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_serveruuid, { "Server UUID", "afs.vldb.serveruuid",
FT_BYTES, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_serveruniq, { "Server Unique Address", "afs.vldb.serveruniq",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_serverflags, { "Server Flags", "afs.vldb.serverflags",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_serverip, { "Server IP", "afs.vldb.serverip",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_flags, { "Flags", "afs.vldb.flags",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_flags_rwexists, { "Read/Write Exists", "afs.vldb.flags.rwexists",
FT_BOOLEAN, 32, 0, 0x1000, NULL, HFILL }},
{ &hf_afs_vldb_flags_roexists, { "Read-Only Exists", "afs.vldb.flags.roexists",
FT_BOOLEAN, 32, 0, 0x2000, NULL, HFILL }},
{ &hf_afs_vldb_flags_bkexists, { "Backup Exists", "afs.vldb.flags.bkexists",
FT_BOOLEAN, 32, 0, 0x4000, NULL, HFILL }},
{ &hf_afs_vldb_flags_dfsfileset, { "DFS Fileset", "afs.vldb.flags.dfsfileset",
FT_BOOLEAN, 32, 0, 0x8000, NULL, HFILL }},
{ &hf_afs_vldb_spare1, { "Spare 1", "afs.vldb.spare1",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_spare2, { "Spare 2", "afs.vldb.spare2",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_spare3, { "Spare 3", "afs.vldb.spare3",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_spare4, { "Spare 4", "afs.vldb.spare4",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_spare5, { "Spare 5", "afs.vldb.spare5",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_spare6, { "Spare 6", "afs.vldb.spare6",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_spare7, { "Spare 7", "afs.vldb.spare7",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_spare8, { "Spare 8", "afs.vldb.spare8",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_vldb_spare9, { "Spare 9", "afs.vldb.spare9",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_backup_errcode, { "Error Code", "afs.backup.errcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &afs_errors_ext, 0, NULL, HFILL }},
{ &hf_afs_cb_errcode, { "Error Code", "afs.cb.errcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &afs_errors_ext, 0, NULL, HFILL }},
{ &hf_afs_cb_callback_version, { "Version", "afs.cb.callback.version",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_cb_callback_expires, { "Expires", "afs.cb.callback.expires",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_cb_callback_type, { "Type", "afs.cb.callback.type",
FT_UINT32, BASE_DEC, VALS(cb_types), 0, NULL, HFILL }},
{ &hf_afs_cb_fid_volume, { "FileID (Volume)", "afs.cb.fid.volume",
FT_UINT32, BASE_DEC, 0, 0, "File ID (Volume)", HFILL }},
{ &hf_afs_cb_fid_vnode, { "FileID (VNode)", "afs.cb.fid.vnode",
FT_UINT32, BASE_DEC, 0, 0, "File ID (VNode)", HFILL }},
{ &hf_afs_cb_fid_uniqifier, { "FileID (Uniqifier)", "afs.cb.fid.uniq",
FT_UINT32, BASE_DEC, 0, 0, "File ID (Uniqifier)", HFILL }},
{ &hf_afs_cm_uuid, { "UUID", "afs.cm.uuid",
FT_BYTES, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_cm_numint, { "Number of Interfaces", "afs.cm.numint",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_cm_ipaddr, { "IP Address", "afs.cm.ipaddr",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_cm_netmask, { "Netmask", "afs.cm.netmask",
FT_IPv4, BASE_NETMASK, 0, 0, NULL, HFILL }},
{ &hf_afs_cm_mtu, { "MTU", "afs.cm.mtu",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_cm_numcap, { "Number of Capability Words", "afs.cm.numcap",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_cm_capabilities, { "Capabilities", "afs.cm.capabilities",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_cm_cap_errortrans, { "ERRORTRANS", "afs.cm.capabilities.errortrans",
FT_BOOLEAN, 32, 0, 0x0001, NULL, HFILL }},
{ &hf_afs_prot_errcode, { "Error Code", "afs.prot.errcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &afs_errors_ext, 0, NULL, HFILL }},
{ &hf_afs_prot_name, { "Name", "afs.prot.name",
FT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_name_uint_string, { "Name", "afs.prot.name",
FT_UINT_STRING, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_id, { "ID", "afs.prot.id",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_oldid, { "Old ID", "afs.prot.oldid",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_newid, { "New ID", "afs.prot.newid",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_gid, { "Group ID", "afs.prot.gid",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_uid, { "User ID", "afs.prot.uid",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_count, { "Count", "afs.prot.count",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_maxgid, { "Maximum Group ID", "afs.prot.maxgid",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_maxuid, { "Maximum User ID", "afs.prot.maxuid",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_pos, { "Position", "afs.prot.pos",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_prot_flag, { "Flag", "afs.prot.flag",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
#if 0
{ &hf_afs_ubik_errcode, { "Error Code", "afs.ubik.errcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &afs_errors_ext, 0, NULL, HFILL }},
#endif
{ &hf_afs_ubik_state, { "State", "afs.ubik.state",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_version_epoch, { "Epoch", "afs.ubik.version.epoch",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_version_counter, { "Counter", "afs.ubik.version.counter",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_votestart, { "Vote Started", "afs.ubik.votestart",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
#if 0
{ &hf_afs_ubik_voteend, { "Vote Ends", "afs.ubik.voteend",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
#endif
{ &hf_afs_ubik_file, { "File", "afs.ubik.file",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_pos, { "Position", "afs.ubik.position",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_length, { "Length", "afs.ubik.length",
FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_locktype, { "Lock Type", "afs.ubik.locktype",
FT_UINT32, BASE_DEC, VALS(ubik_lock_types), 0, NULL, HFILL }},
#if 0
{ &hf_afs_ubik_votetype, { "Vote Type", "afs.ubik.votetype",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
#endif
{ &hf_afs_ubik_site, { "Site", "afs.ubik.site",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_interface, { "Interface Address", "afs.ubik.interface",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_null_addresses, { "Null Interface Addresses", "afs.ubik.null_addresses",
FT_NONE, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_now, { "Now", "afs.ubik.now",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lastyestime, { "Last Yes Time", "afs.ubik.lastyesttime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lastyeshost, { "Last Yes Host", "afs.ubik.lastyeshost",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lastyesstate, { "Last Yes State", "afs.ubik.lastyesstate",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lastyesclaim, { "Last Yes Claim", "afs.ubik.lastyesclaim",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lowesthost, { "Lowest Host", "afs.ubik.lowesthost",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lowesttime, { "Lowest Time", "afs.ubik.lowesttime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_synchost, { "Sync Host", "afs.ubik.synchost",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_addr, { "Address", "afs.ubik.addr",
FT_IPv4, BASE_NONE, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_synctime, { "Sync Time", "afs.ubik.synctime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lastvotetime, { "Last Vote Time", "afs.ubik.lastvotetime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lastbeaconsent, { "Last Beacon Sent", "afs.ubik.lastbeaconsent",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lastvote, { "Last Vote", "afs.ubik.lastvote",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_currentdb, { "Current DB", "afs.ubik.currentdb",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_up, { "Up", "afs.ubik.up",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_beaconsincedown, { "Beacon Since Down", "afs.ubik.beaconsincedown",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_amsyncsite, { "Am Sync Site", "afs.ubik.amsyncsite",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_syncsiteuntil, { "Sync Site Until", "afs.ubik.syncsiteuntil",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_nservers, { "Number of Servers", "afs.ubik.nservers",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_lockedpages, { "Locked Pages", "afs.ubik.lockedpages",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_writelockedpages, { "Write Locked Pages", "afs.ubik.writelockedpages",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_activewrite, { "Active Write", "afs.ubik.activewrite",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_tidcounter, { "TID Counter", "afs.ubik.tidcounter",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_anyreadlocks, { "Any Read Locks", "afs.ubik.anyreadlocks",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_anywritelocks, { "Any Write Locks", "afs.ubik.anywritelocks",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_recoverystate, { "Recovery State", "afs.ubik.recoverystate",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_currenttrans, { "Current Transaction", "afs.ubik.currenttran",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_writetrans, { "Write Transaction", "afs.ubik.writetran",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_epochtime, { "Epoch Time", "afs.ubik.epochtime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, 0, 0, NULL, HFILL }},
{ &hf_afs_ubik_isclone, { "Is Clone", "afs.ubik.isclone",
FT_UINT32, BASE_HEX, 0, 0, NULL, HFILL }},
{ &hf_afs_reqframe, { "Request Frame", "afs.reqframe",
FT_FRAMENUM, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_afs_repframe, { "Reply Frame", "afs.repframe",
FT_FRAMENUM, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_afs_time, { "Time from request", "afs.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0, "Time between Request and Reply for AFS calls", HFILL }},
{&hf_afs_fragments, {"Message fragments", "afs.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_afs_fragment, {"Message fragment", "afs.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_afs_fragment_overlap, {"Message fragment overlap", "afs.fragment.overlap",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_afs_fragment_overlap_conflicts, {"Message fragment overlapping with conflicting data", "afs.fragment.overlap.conflicts",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_afs_fragment_multiple_tails, {"Message has multiple tail fragments", "afs.fragment.multiple_tails",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_afs_fragment_too_long_fragment, {"Message fragment too long", "afs.fragment.too_long_fragment",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_afs_fragment_error, {"Message defragmentation error", "afs.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_afs_fragment_count, {"Message fragment count", "afs.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_afs_reassembled_in, {"Reassembled in", "afs.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_afs_reassembled_length, {"Reassembled length", "afs.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
};
static gint *ett[] = {
&ett_afs,
&ett_afs_op,
&ett_afs_acl,
&ett_afs_fid,
&ett_afs_callback,
&ett_afs_ubikver,
&ett_afs_status,
&ett_afs_status_mask,
&ett_afs_volsync,
&ett_afs_volumeinfo,
&ett_afs_vicestat,
&ett_afs_vldb_flags,
&ett_afs_fragment,
&ett_afs_fragments,
&ett_afs_cm_interfaces,
&ett_afs_cm_capabilities,
};
proto_afs = proto_register_protocol("Andrew File System (AFS)",
"AFS (RX)", "afs");
proto_register_field_array(proto_afs, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(&afs_init_protocol);
register_cleanup_routine(&afs_cleanup_protocol);
register_dissector("afs", dissect_afs, proto_afs);
}
