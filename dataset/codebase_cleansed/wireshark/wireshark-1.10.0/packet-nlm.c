static gboolean
nlm_msg_res_unmatched_free_all(gpointer key_arg _U_, gpointer value, gpointer user_data _U_)
{
nlm_msg_res_unmatched_data *umd = (nlm_msg_res_unmatched_data *)value;
g_free((gpointer)umd->cookie);
g_free(umd);
return TRUE;
}
static gboolean
nlm_msg_res_matched_free_all(gpointer key_arg _U_, gpointer value, gpointer user_data _U_)
{
nlm_msg_res_matched_data *md = (nlm_msg_res_matched_data *)value;
g_free(md);
return TRUE;
}
static guint
nlm_msg_res_unmatched_hash(gconstpointer k)
{
const nlm_msg_res_unmatched_data *umd = (const nlm_msg_res_unmatched_data *)k;
guint8 hash=0;
int i;
for(i=0;i<umd->cookie_len;i++){
hash^=umd->cookie[i];
}
return hash;
}
static guint
nlm_msg_res_matched_hash(gconstpointer k)
{
guint hash = GPOINTER_TO_UINT(k);
return hash;
}
static gint
nlm_msg_res_unmatched_equal(gconstpointer k1, gconstpointer k2)
{
const nlm_msg_res_unmatched_data *umd1 = (const nlm_msg_res_unmatched_data *)k1;
const nlm_msg_res_unmatched_data *umd2 = (const nlm_msg_res_unmatched_data *)k2;
if(umd1->cookie_len!=umd2->cookie_len){
return 0;
}
return( memcmp(umd1->cookie, umd2->cookie, umd1->cookie_len) == 0);
}
static gint
nlm_msg_res_matched_equal(gconstpointer k1, gconstpointer k2)
{
guint mk1 = GPOINTER_TO_UINT(k1);
guint mk2 = GPOINTER_TO_UINT(k2);
return( mk1==mk2 );
}
static void
nlm_msg_res_match_init(void)
{
if(nlm_msg_res_unmatched != NULL){
g_hash_table_foreach_remove(nlm_msg_res_unmatched,
nlm_msg_res_unmatched_free_all, NULL);
} else {
nlm_msg_res_unmatched=g_hash_table_new(nlm_msg_res_unmatched_hash,
nlm_msg_res_unmatched_equal);
}
if(nlm_msg_res_matched != NULL){
g_hash_table_foreach_remove(nlm_msg_res_matched,
nlm_msg_res_matched_free_all, NULL);
} else {
nlm_msg_res_matched=g_hash_table_new(nlm_msg_res_matched_hash,
nlm_msg_res_matched_equal);
}
}
static void
nlm_print_msgres_reply(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb)
{
nlm_msg_res_matched_data *md;
md=(nlm_msg_res_matched_data *)g_hash_table_lookup(nlm_msg_res_matched, GINT_TO_POINTER(pinfo->fd->num));
if(md){
nstime_t ns;
proto_tree_add_uint(tree, hf_nlm_request_in, tvb, 0, 0, md->req_frame);
nstime_delta(&ns, &pinfo->fd->abs_ts, &md->ns);
proto_tree_add_time(tree, hf_nlm_time, tvb, 0, 0, &ns);
}
}
static void
nlm_print_msgres_request(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb)
{
nlm_msg_res_matched_data *md;
md=(nlm_msg_res_matched_data *)g_hash_table_lookup(nlm_msg_res_matched, GINT_TO_POINTER(pinfo->fd->num));
if(md){
proto_tree_add_uint(tree, hf_nlm_reply_in, tvb, 0, 0, md->rep_frame);
}
}
static void
nlm_match_fhandle_reply(packet_info *pinfo, proto_tree *tree)
{
nlm_msg_res_matched_data *md;
md=(nlm_msg_res_matched_data *)g_hash_table_lookup(nlm_msg_res_matched, GINT_TO_POINTER(pinfo->fd->num));
if(md && md->rep_frame){
dissect_fhandle_hidden(pinfo,
tree, md->req_frame);
}
}
static void
nlm_match_fhandle_request(packet_info *pinfo, proto_tree *tree)
{
nlm_msg_res_matched_data *md;
md=(nlm_msg_res_matched_data *)g_hash_table_lookup(nlm_msg_res_matched, GINT_TO_POINTER(pinfo->fd->num));
if(md && md->rep_frame){
dissect_fhandle_hidden(pinfo,
tree, md->rep_frame);
}
}
static void
nlm_register_unmatched_res(packet_info *pinfo, tvbuff_t *tvb, int offset)
{
nlm_msg_res_unmatched_data umd;
nlm_msg_res_unmatched_data *old_umd;
umd.cookie_len=tvb_get_ntohl(tvb, offset);
umd.cookie=tvb_get_ptr(tvb, offset+4, -1);
old_umd=(nlm_msg_res_unmatched_data *)g_hash_table_lookup(nlm_msg_res_unmatched, (gconstpointer)&umd);
if(old_umd){
nlm_msg_res_matched_data *md;
md=(nlm_msg_res_matched_data *)g_malloc(sizeof(nlm_msg_res_matched_data));
md->req_frame=old_umd->req_frame;
md->rep_frame=pinfo->fd->num;
md->ns=old_umd->ns;
g_hash_table_insert(nlm_msg_res_matched, GINT_TO_POINTER(md->req_frame), (gpointer)md);
g_hash_table_insert(nlm_msg_res_matched, GINT_TO_POINTER(md->rep_frame), (gpointer)md);
g_hash_table_remove(nlm_msg_res_unmatched, (gconstpointer)old_umd);
g_free((gpointer)old_umd->cookie);
g_free(old_umd);
}
}
static void
nlm_register_unmatched_msg(packet_info *pinfo, tvbuff_t *tvb, int offset)
{
nlm_msg_res_unmatched_data *umd;
nlm_msg_res_unmatched_data *old_umd;
umd=(nlm_msg_res_unmatched_data *)g_malloc(sizeof(nlm_msg_res_unmatched_data));
umd->req_frame=pinfo->fd->num;
umd->ns=pinfo->fd->abs_ts;
umd->cookie_len=tvb_get_ntohl(tvb, offset);
umd->cookie=(const guint8 *)tvb_memdup(tvb, offset+4, umd->cookie_len);
old_umd=(nlm_msg_res_unmatched_data *)g_hash_table_lookup(nlm_msg_res_unmatched, (gconstpointer)umd);
if(old_umd){
g_hash_table_remove(nlm_msg_res_unmatched, (gconstpointer)old_umd);
g_free((gpointer)old_umd->cookie);
g_free(old_umd);
}
g_hash_table_insert(nlm_msg_res_unmatched, (gpointer)umd, (gpointer)umd);
}
static int
dissect_lock(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int version, int offset)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
guint32 fh_hash, svid, start_offset=0, end_offset=0;
if (tree) {
lock_item = proto_tree_add_item(tree, hf_nlm_lock, tvb,
offset, -1, ENC_NA);
if (lock_item)
lock_tree = proto_item_add_subtree(lock_item, ett_nlm_lock);
}
offset = dissect_rpc_string(tvb,lock_tree,
hf_nlm_lock_caller_name, offset, NULL);
offset = dissect_nfs3_fh(tvb, offset, pinfo, lock_tree, "fh", &fh_hash);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " FH:0x%08x", fh_hash);
}
offset = dissect_rpc_data(tvb, lock_tree, hf_nlm_lock_owner, offset);
svid = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, lock_tree, hf_nlm_lock_svid, offset);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " svid:%d", svid);
}
if (version == 4) {
start_offset = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint64(tvb, lock_tree, hf_nlm_lock_l_offset64, offset);
end_offset = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint64(tvb, lock_tree, hf_nlm_lock_l_len64, offset);
}
else {
start_offset = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, lock_tree, hf_nlm_lock_l_offset, offset);
end_offset = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, lock_tree, hf_nlm_lock_l_len, offset);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " pos:%d-%d", start_offset, end_offset);
}
return offset;
}
static int
dissect_nlm_test(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, int version)
{
if(nlm_match_msgres){
rpc_call_info_value *rpc_call=(rpc_call_info_value *)pinfo->private_data;
if(rpc_call->proc==6){
if( (!pinfo->fd->flags.visited) ){
nlm_register_unmatched_msg(pinfo, tvb, offset);
} else {
nlm_print_msgres_request(pinfo, tree, tvb);
}
if(nfs_fhandle_reqrep_matching){
nlm_match_fhandle_request(pinfo, tree);
}
}
}
offset = dissect_rpc_data(tvb, tree, hf_nlm_cookie, offset);
dissect_rpc_bool(tvb, tree, hf_nlm_exclusive, offset);
offset += 4;
offset = dissect_lock(tvb, pinfo, tree, version, offset);
return offset;
}
static int
dissect_nlm_lock(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree,int version)
{
if(nlm_match_msgres){
rpc_call_info_value *rpc_call=(rpc_call_info_value *)pinfo->private_data;
if(rpc_call->proc==7){
if( (!pinfo->fd->flags.visited) ){
nlm_register_unmatched_msg(pinfo, tvb, offset);
} else {
nlm_print_msgres_request(pinfo, tree, tvb);
}
if(nfs_fhandle_reqrep_matching){
nlm_match_fhandle_request(pinfo, tree);
}
}
}
offset = dissect_rpc_data(tvb, tree, hf_nlm_cookie, offset);
offset = dissect_rpc_bool(tvb, tree, hf_nlm_block, offset);
offset = dissect_rpc_bool(tvb, tree, hf_nlm_exclusive, offset);
offset = dissect_lock(tvb, pinfo, tree, version, offset);
offset = dissect_rpc_bool(tvb, tree, hf_nlm_reclaim, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_nlm_state, offset);
return offset;
}
static int
dissect_nlm_cancel(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree,int version)
{
if(nlm_match_msgres){
rpc_call_info_value *rpc_call=(rpc_call_info_value *)pinfo->private_data;
if(rpc_call->proc==8){
if( (!pinfo->fd->flags.visited) ){
nlm_register_unmatched_msg(pinfo, tvb, offset);
} else {
nlm_print_msgres_request(pinfo, tree, tvb);
}
if(nfs_fhandle_reqrep_matching){
nlm_match_fhandle_request(pinfo, tree);
}
}
}
offset = dissect_rpc_data(tvb, tree, hf_nlm_cookie, offset);
offset = dissect_rpc_bool(tvb, tree, hf_nlm_block, offset);
offset = dissect_rpc_bool(tvb, tree, hf_nlm_exclusive, offset);
offset = dissect_lock(tvb, pinfo, tree, version, offset);
return offset;
}
static int
dissect_nlm_unlock(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree,int version)
{
if(nlm_match_msgres){
rpc_call_info_value *rpc_call=(rpc_call_info_value *)pinfo->private_data;
if(rpc_call->proc==9){
if( (!pinfo->fd->flags.visited) ){
nlm_register_unmatched_msg(pinfo, tvb, offset);
} else {
nlm_print_msgres_request(pinfo, tree, tvb);
}
if(nfs_fhandle_reqrep_matching){
nlm_match_fhandle_request(pinfo, tree);
}
}
}
offset = dissect_rpc_data(tvb, tree, hf_nlm_cookie, offset);
offset = dissect_lock(tvb, pinfo, tree, version, offset);
return offset;
}
static int
dissect_nlm_granted(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree,int version)
{
if(nlm_match_msgres){
rpc_call_info_value *rpc_call=(rpc_call_info_value *)pinfo->private_data;
if(rpc_call->proc==10){
if( (!pinfo->fd->flags.visited) ){
nlm_register_unmatched_msg(pinfo, tvb, offset);
} else {
nlm_print_msgres_request(pinfo, tree, tvb);
}
if(nfs_fhandle_reqrep_matching){
nlm_match_fhandle_request(pinfo, tree);
}
}
}
offset = dissect_rpc_data(tvb, tree, hf_nlm_cookie, offset);
offset = dissect_rpc_bool(tvb, tree, hf_nlm_exclusive, offset);
offset = dissect_lock(tvb, pinfo, tree, version, offset);
return offset;
}
static int
dissect_nlm_test_res(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree,int version)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
if(nlm_match_msgres){
rpc_call_info_value *rpc_call=(rpc_call_info_value *)pinfo->private_data;
if(rpc_call->proc==11){
if( (!pinfo->fd->flags.visited) ){
nlm_register_unmatched_res(pinfo, tvb, offset);
} else {
nlm_print_msgres_reply(pinfo, tree, tvb);
}
if(nfs_fhandle_reqrep_matching){
nlm_match_fhandle_reply(pinfo, tree);
}
}
}
offset = dissect_rpc_data(tvb, tree, hf_nlm_cookie, offset);
if (tree) {
lock_item = proto_tree_add_item(tree, hf_nlm_test_stat, tvb,
offset, -1, ENC_NA);
if (lock_item)
lock_tree = proto_item_add_subtree(lock_item,
ett_nlm_lock);
}
offset = dissect_rpc_uint32(tvb, lock_tree, hf_nlm_test_stat_stat,
offset);
if(tvb_reported_length_remaining(tvb, offset) == 0){
return offset;
}
if (tree) {
lock_item = proto_tree_add_item(lock_tree, hf_nlm_holder, tvb,
offset, -1, ENC_NA);
if (lock_item)
lock_tree = proto_item_add_subtree(lock_item,
ett_nlm_lock);
}
offset = dissect_rpc_bool(tvb, lock_tree, hf_nlm_exclusive,
offset);
offset = dissect_rpc_uint32(tvb, lock_tree, hf_nlm_lock_svid,
offset);
offset = dissect_rpc_data(tvb, lock_tree, hf_nlm_lock_owner,
offset);
if (version == 4) {
offset = dissect_rpc_uint64(tvb, lock_tree,
hf_nlm_lock_l_offset64, offset);
offset = dissect_rpc_uint64(tvb, lock_tree,
hf_nlm_lock_l_len64, offset);
}
else {
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nlm_lock_l_offset, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nlm_lock_l_len, offset);
}
return offset;
}
static int
dissect_nlm_share(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree,int version _U_)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
guint32 fh_hash;
offset = dissect_rpc_data(tvb, tree, hf_nlm_cookie, offset);
if (tree) {
lock_item = proto_tree_add_item(tree, hf_nlm_share, tvb,
offset, -1, ENC_NA);
if (lock_item)
lock_tree = proto_item_add_subtree(lock_item,
ett_nlm_lock);
}
offset = dissect_rpc_string(tvb,lock_tree,
hf_nlm_lock_caller_name, offset, NULL);
offset = dissect_nfs3_fh(tvb, offset, pinfo, lock_tree, "fh", &fh_hash);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " FH:0x%08x", fh_hash);
}
offset = dissect_rpc_data(tvb, lock_tree, hf_nlm_lock_owner, offset);
offset = dissect_rpc_uint32(tvb, lock_tree, hf_nlm_share_mode, offset);
offset = dissect_rpc_uint32(tvb, lock_tree, hf_nlm_share_access, offset);
offset = dissect_rpc_bool(tvb, tree, hf_nlm_reclaim, offset);
return offset;
}
static int
dissect_nlm_shareres(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, int version _U_)
{
guint32 nlm_stat;
offset = dissect_rpc_data(tvb, tree, hf_nlm_cookie, offset);
nlm_stat = tvb_get_ntohl(tvb, offset);
if (nlm_stat && check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(nlm_stat, names_nlm_stats, "Unknown Status (%u)"));
}
offset = dissect_rpc_uint32(tvb, tree, hf_nlm_stat, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_nlm_sequence, offset);
return offset;
}
static int
dissect_nlm_freeall(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree,int version _U_)
{
guint32 nlm_stat;
offset = dissect_rpc_string(tvb,tree,
hf_nlm_share_name, offset, NULL);
nlm_stat = tvb_get_ntohl(tvb, offset);
if (nlm_stat && check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(nlm_stat, names_nlm_stats, "Unknown Status (%u)"));
}
offset = dissect_rpc_uint32(tvb, tree, hf_nlm_stat, offset);
return offset;
}
static int
dissect_nlm_gen_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
guint32 nlm_stat;
if(nlm_match_msgres){
rpc_call_info_value *rpc_call=(rpc_call_info_value *)pinfo->private_data;
if((rpc_call->proc==12)
|| (rpc_call->proc==13)
|| (rpc_call->proc==14)
|| (rpc_call->proc==15) ){
if( (!pinfo->fd->flags.visited) ){
nlm_register_unmatched_res(pinfo, tvb, offset);
} else {
nlm_print_msgres_reply(pinfo, tree, tvb);
}
if(nfs_fhandle_reqrep_matching){
nlm_match_fhandle_reply(pinfo, tree);
}
}
}
offset = dissect_rpc_data(tvb, tree, hf_nlm_cookie, offset);
nlm_stat = tvb_get_ntohl(tvb, offset);
if (nlm_stat && check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(nlm_stat, names_nlm_stats, "Unknown Status (%u)"));
}
offset = dissect_rpc_uint32(tvb, tree, hf_nlm_stat, offset);
return offset;
}
static int
dissect_nlm1_test(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_test(tvb,offset,pinfo,tree,1);
}
static int
dissect_nlm4_test(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_test(tvb,offset,pinfo,tree,4);
}
static int
dissect_nlm1_lock(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_lock(tvb,offset,pinfo,tree,1);
}
static int
dissect_nlm4_lock(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_lock(tvb,offset,pinfo,tree,4);
}
static int
dissect_nlm1_cancel(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_cancel(tvb,offset,pinfo,tree,1);
}
static int
dissect_nlm4_cancel(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_cancel(tvb,offset,pinfo,tree,4);
}
static int
dissect_nlm1_unlock(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_unlock(tvb,offset,pinfo,tree,1);
}
static int
dissect_nlm4_unlock(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_unlock(tvb,offset,pinfo,tree,4);
}
static int
dissect_nlm1_granted(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_granted(tvb,offset,pinfo,tree,1);
}
static int
dissect_nlm4_granted(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_granted(tvb,offset,pinfo,tree,4);
}
static int
dissect_nlm1_test_res(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_test_res(tvb,offset,pinfo,tree,1);
}
static int
dissect_nlm4_test_res(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_test_res(tvb,offset,pinfo,tree,4);
}
static int
dissect_nlm3_share(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_share(tvb,offset,pinfo,tree,3);
}
static int
dissect_nlm4_share(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_share(tvb,offset,pinfo,tree,4);
}
static int
dissect_nlm3_shareres(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_shareres(tvb,offset,pinfo,tree,3);
}
static int
dissect_nlm4_shareres(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_shareres(tvb,offset,pinfo,tree,4);
}
static int
dissect_nlm3_freeall(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_freeall(tvb,offset,pinfo,tree,3);
}
static int
dissect_nlm4_freeall(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
return dissect_nlm_freeall(tvb,offset,pinfo,tree,4);
}
void
proto_register_nlm(void)
{
static hf_register_info hf[] = {
{ &hf_nlm_procedure_v1, {
"V1 Procedure", "nlm.procedure_v1", FT_UINT32, BASE_DEC,
VALS(nlm1_proc_vals), 0, NULL, HFILL }},
{ &hf_nlm_procedure_v2, {
"V2 Procedure", "nlm.procedure_v2", FT_UINT32, BASE_DEC,
VALS(nlm2_proc_vals), 0, NULL, HFILL }},
{ &hf_nlm_procedure_v3, {
"V3 Procedure", "nlm.procedure_v3", FT_UINT32, BASE_DEC,
VALS(nlm3_proc_vals), 0, NULL, HFILL }},
{ &hf_nlm_procedure_v4, {
"V4 Procedure", "nlm.procedure_v4", FT_UINT32, BASE_DEC,
VALS(nlm4_proc_vals), 0, NULL, HFILL }},
{ &hf_nlm_cookie, {
"cookie", "nlm.cookie", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_block, {
"block", "nlm.block", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0x0, NULL, HFILL }},
{ &hf_nlm_exclusive, {
"exclusive", "nlm.exclusive", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0x0, NULL, HFILL }},
{ &hf_nlm_lock, {
"lock", "nlm.lock", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_lock_caller_name, {
"caller_name", "nlm.lock.caller_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_lock_owner, {
"owner", "nlm.lock.owner", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_lock_svid, {
"svid", "nlm.lock.svid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_lock_l_offset64, {
"l_offset", "nlm.lock.l_offset", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_lock_l_offset, {
"l_offset", "nlm.lock.l_offset", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_lock_l_len64, {
"l_len", "nlm.lock.l_len", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_lock_l_len, {
"l_len", "nlm.lock.l_len", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_reclaim, {
"reclaim", "nlm.reclaim", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0x0, NULL, HFILL }},
{ &hf_nlm_state, {
"state", "nlm.state", FT_UINT32, BASE_DEC,
NULL, 0, "STATD state", HFILL }},
{ &hf_nlm_stat, {
"stat", "nlm.stat", FT_UINT32, BASE_DEC,
VALS(names_nlm_stats), 0, NULL, HFILL }},
{ &hf_nlm_test_stat, {
"test_stat", "nlm.test_stat", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_test_stat_stat, {
"stat", "nlm.test_stat.stat", FT_UINT32, BASE_DEC,
VALS(names_nlm_stats), 0, NULL, HFILL }},
{ &hf_nlm_holder, {
"holder", "nlm.holder", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_share, {
"share", "nlm.share", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_share_mode, {
"mode", "nlm.share.mode", FT_UINT32, BASE_DEC,
VALS(names_fsh_mode), 0, NULL, HFILL }},
{ &hf_nlm_share_access, {
"access", "nlm.share.access", FT_UINT32, BASE_DEC,
VALS(names_fsh_access), 0, NULL, HFILL }},
{ &hf_nlm_share_name, {
"name", "nlm.share.name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_sequence, {
"sequence", "nlm.sequence", FT_INT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nlm_request_in, {
"Request MSG in", "nlm.msg_in", FT_UINT32, BASE_DEC,
NULL, 0, "The RES packet is a response to the MSG in this packet", HFILL }},
{ &hf_nlm_reply_in, {
"Reply RES in", "nlm.res_in", FT_UINT32, BASE_DEC,
NULL, 0, "The response to this MSG packet is in this packet", HFILL }},
{ &hf_nlm_time, {
"Time from request", "nlm.time", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Time between Request and Reply for async NLM calls", HFILL }},
};
static gint *ett[] = {
&ett_nlm,
&ett_nlm_lock,
};
module_t *nlm_module;
proto_nlm = proto_register_protocol("Network Lock Manager Protocol",
"NLM", "nlm");
proto_register_field_array(proto_nlm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
nlm_module = prefs_register_protocol(proto_nlm, NULL);
prefs_register_bool_preference(nlm_module, "msg_res_matching",
"Match MSG/RES packets for async NLM",
"Whether the dissector will track and match MSG and RES calls for asynchronous NLM",
&nlm_match_msgres);
register_init_routine(nlm_msg_res_match_init);
}
void
proto_reg_handoff_nlm(void)
{
rpc_init_prog(proto_nlm, NLM_PROGRAM, ett_nlm);
rpc_init_proc_table(NLM_PROGRAM, 1, nlm1_proc, hf_nlm_procedure_v1);
rpc_init_proc_table(NLM_PROGRAM, 2, nlm2_proc, hf_nlm_procedure_v2);
rpc_init_proc_table(NLM_PROGRAM, 3, nlm3_proc, hf_nlm_procedure_v3);
rpc_init_proc_table(NLM_PROGRAM, 4, nlm4_proc, hf_nlm_procedure_v4);
}
