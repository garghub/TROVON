static void dbg(guint level, char *fmt, ...) {
va_list ap;
if (level > debug_level) return;
va_start(ap,fmt);
vfprintf(stderr, fmt, ap);
va_end(ap);
}
static char camel_number_to_char(int number)
{
if (number < 10)
return (char) (number + 48 );
else
return (char) (number + 55 );
}
static guint8
dissect_RP_cause_ie(tvbuff_t *tvb, guint32 offset, _U_ guint len,
proto_tree *tree, int hf_cause_value, guint8 *cause_value)
{
guint8 oct;
guint32 curr_offset;
static char a_bigbuf[1024];
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
*cause_value = oct & 0x7f;
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
proto_tree_add_uint_format(tree, hf_cause_value,
tvb, curr_offset, 1, *cause_value,
"%s : %s",
a_bigbuf,
val_to_str(*cause_value, camel_RP_Cause_values,
"Unknown Cause (%u), treated as (41) \"Temporary failure\" for MO-SMS or (111) \"Protocol error,unspecified\" for MT-SMS"));
curr_offset++;
if ((oct & 0x80)) {
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format(tree, hf_cause_value,
tvb, curr_offset, 1, oct,
"Diagnostic : %u", oct);
curr_offset++;
}
return(curr_offset - offset);
}
static gint
camelsrt_call_equal(gconstpointer k1, gconstpointer k2)
{
const struct camelsrt_call_info_key_t *key1 = (const struct camelsrt_call_info_key_t *) k1;
const struct camelsrt_call_info_key_t *key2 = (const struct camelsrt_call_info_key_t *) k2;
return (key1->SessionIdKey == key2->SessionIdKey) ;
}
static guint
camelsrt_call_hash(gconstpointer k)
{
const struct camelsrt_call_info_key_t *key = (const struct camelsrt_call_info_key_t *) k;
return key->SessionIdKey;
}
static struct camelsrt_call_t *
find_camelsrt_call(struct camelsrt_call_info_key_t *p_camelsrt_call_key)
{
struct camelsrt_call_t *p_camelsrt_call = NULL;
p_camelsrt_call = (struct camelsrt_call_t *)g_hash_table_lookup(srt_calls, p_camelsrt_call_key);
#ifdef DEBUG_CAMELSRT
if(p_camelsrt_call) {
dbg(10,"D%d ", p_camelsrt_call->session_id);
} else {
dbg(23,"Not in hash ");
}
#endif
return p_camelsrt_call;
}
static void
raz_camelsrt_call (struct camelsrt_call_t *p_camelsrt_call)
{
memset(p_camelsrt_call,0,sizeof(struct camelsrt_call_t));
}
static struct camelsrt_call_t *
new_camelsrt_call(struct camelsrt_call_info_key_t *p_camelsrt_call_key)
{
struct camelsrt_call_info_key_t *p_new_camelsrt_call_key;
struct camelsrt_call_t *p_new_camelsrt_call = NULL;
p_new_camelsrt_call_key = se_new(struct camelsrt_call_info_key_t);
p_new_camelsrt_call_key->SessionIdKey = p_camelsrt_call_key->SessionIdKey;
p_new_camelsrt_call = se_new(struct camelsrt_call_t);
raz_camelsrt_call(p_new_camelsrt_call);
p_new_camelsrt_call->session_id = camelsrt_global_SessionId++;
#ifdef DEBUG_CAMELSRT
dbg(10,"D%d ", p_new_camelsrt_call->session_id);
#endif
g_hash_table_insert(srt_calls, p_new_camelsrt_call_key, p_new_camelsrt_call);
return p_new_camelsrt_call;
}
void
camelsrt_init_routine(void)
{
if (srt_calls != NULL) {
#ifdef DEBUG_CAMELSRT
dbg(16,"Destroy hash ");
#endif
g_hash_table_destroy(srt_calls);
}
srt_calls = g_hash_table_new(camelsrt_call_hash, camelsrt_call_equal);
#ifdef DEBUG_CAMELSRT
dbg(16,"Create hash ");
#endif
camelsrt_global_SessionId=1;
gcamel_DisplaySRT=gcamel_PersistentSRT || gcamel_HandleSRT&gcamel_StatSRT;
}
static void
update_camelsrt_call(struct camelsrt_call_t *p_camelsrt_call, packet_info *pinfo,
guint msg_category)
{
p_camelsrt_call->category[msg_category].req_num = pinfo->fd->num;
p_camelsrt_call->category[msg_category].rsp_num = 0;
p_camelsrt_call->category[msg_category].responded = FALSE;
p_camelsrt_call->category[msg_category].req_time = pinfo->fd->abs_ts;
}
static void
camelsrt_close_call_matching(packet_info *pinfo,
struct camelsrt_info_t *p_camelsrt_info)
{
struct camelsrt_call_t *p_camelsrt_call;
struct camelsrt_call_info_key_t camelsrt_call_key;
nstime_t delta;
p_camelsrt_info->bool_msginfo[CAMELSRT_SESSION]=TRUE;
#ifdef DEBUG_CAMELSRT
dbg(10,"\n Session end #%u\n", pinfo->fd->num);
#endif
camelsrt_call_key.SessionIdKey = p_camelsrt_info->tcap_session_id;
#ifdef DEBUG_CAMELSRT
dbg(11,"Search key %lu ",camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = find_camelsrt_call(&camelsrt_call_key);
if(p_camelsrt_call) {
#ifdef DEBUG_CAMELSRT
dbg(12,"Found ");
#endif
nstime_delta(&delta, &pinfo->fd->abs_ts, &p_camelsrt_call->category[CAMELSRT_SESSION].req_time);
p_camelsrt_call->category[CAMELSRT_SESSION].responded = TRUE;
p_camelsrt_info->msginfo[CAMELSRT_SESSION].request_available = TRUE;
p_camelsrt_info->msginfo[CAMELSRT_SESSION].is_delta_time = TRUE;
p_camelsrt_info->msginfo[CAMELSRT_SESSION].delta_time = delta;
p_camelsrt_info->msginfo[CAMELSRT_SESSION].req_time = p_camelsrt_call->category[CAMELSRT_SESSION].req_time;
if ( !gcamel_PersistentSRT ) {
g_hash_table_remove(srt_calls, &camelsrt_call_key);
#ifdef DEBUG_CAMELSRT
dbg(20,"remove hash ");
#endif
} else {
#ifdef DEBUG_CAMELSRT
dbg(20,"keep hash ");
#endif
}
}
}
static void
camelsrt_tcap_matching(tvbuff_t *tvb _U_, packet_info *pinfo,
proto_tree *tree _U_,
struct tcaphash_context_t *p_tcap_context)
{
struct camelsrt_info_t *p_camelsrt_info;
#ifdef DEBUG_CAMELSRT
dbg(11,"Camel_CallBack ");
#endif
p_camelsrt_info=camelsrt_razinfo();
p_camelsrt_info->tcap_context=p_tcap_context;
if (p_tcap_context) {
#ifdef DEBUG_CAMELSRT
dbg(11,"Close TCAP ");
#endif
p_camelsrt_info->tcap_session_id = p_tcap_context->session_id;
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, p_camelsrt_info);
}
}
static void
camelsrt_begin_call_matching(packet_info *pinfo,
struct camelsrt_info_t *p_camelsrt_info)
{
struct camelsrt_call_t *p_camelsrt_call;
struct camelsrt_call_info_key_t camelsrt_call_key;
p_camelsrt_info->bool_msginfo[CAMELSRT_SESSION]=TRUE;
camelsrt_call_key.SessionIdKey = p_camelsrt_info->tcap_session_id;
#ifdef DEBUG_CAMELSRT
dbg(10,"\n Session begin #%u\n", pinfo->fd->num);
dbg(11,"Search key %lu ",camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = (struct camelsrt_call_t *)g_hash_table_lookup(srt_calls, &camelsrt_call_key);
if (p_camelsrt_call) {
#ifdef DEBUG_CAMELSRT
dbg(22,"Already seen ");
#endif
} else {
#ifdef DEBUG_CAMELSRT
dbg(10,"New key %lu ",camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = new_camelsrt_call(&camelsrt_call_key);
p_camelsrt_call->tcap_context=(struct tcaphash_context_t *)p_camelsrt_info->tcap_context;
update_camelsrt_call(p_camelsrt_call, pinfo,CAMELSRT_SESSION);
#ifdef DEBUG_CAMELSRT
dbg(11,"Update Callback ");
#endif
p_camelsrt_call->tcap_context->callback=camelsrt_tcap_matching;
}
}
static void
camelsrt_request_call_matching(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree,
struct camelsrt_info_t *p_camelsrt_info,
guint srt_type )
{
struct camelsrt_call_t *p_camelsrt_call;
struct camelsrt_call_info_key_t camelsrt_call_key;
proto_item *ti, *hidden_item;
#ifdef DEBUG_CAMELSRT
dbg(10,"\n %s #%u\n", val_to_str_const(srt_type, camelSRTtype_naming, "Unk"),pinfo->fd->num);
#endif
camelsrt_call_key.SessionIdKey = p_camelsrt_info->tcap_session_id;
#ifdef DEBUG_CAMELSRT
dbg(11,"Search key %lu ", camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = find_camelsrt_call(&camelsrt_call_key);
if(p_camelsrt_call) {
#ifdef DEBUG_CAMELSRT
dbg(12,"Found ");
#endif
if (gcamel_DisplaySRT)
proto_tree_add_uint(tree, hf_camelsrt_SessionId, tvb, 0,0, p_camelsrt_call->session_id);
if (srt_type==CAMELSRT_VOICE_ACR1) {
if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].req_num == 0) {
srt_type=CAMELSRT_VOICE_ACR1;
} else if ( (p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].req_num == 0)
&& (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num != 0)
&& (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num < pinfo->fd->num) ) {
srt_type=CAMELSRT_VOICE_ACR2;
} else if ( (p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].req_num == 0)
&& (p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num != 0)
&& (p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num < pinfo->fd->num) ) {
srt_type=CAMELSRT_VOICE_ACR3;
} else if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num > pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR1;
} else if ( p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num > pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR2;
} else if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].rsp_num > pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR3;
}
#ifdef DEBUG_CAMELSRT
dbg(70,"Request ACR %u ",srt_type);
dbg(70,"ACR1 %u %u",p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].req_num, p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].rsp_num);
dbg(70,"ACR2 %u %u",p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].req_num, p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].rsp_num);
dbg(70,"ACR3 %u %u",p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].req_num, p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].rsp_num);
#endif
}
p_camelsrt_info->bool_msginfo[srt_type]=TRUE;
if (p_camelsrt_call->category[srt_type].req_num == 0) {
#ifdef DEBUG_CAMELSRT
dbg(5,"Set reqlink #%u ", pinfo->fd->num);
#endif
update_camelsrt_call(p_camelsrt_call, pinfo, srt_type);
} else {
if (p_camelsrt_call->category[srt_type].req_num != pinfo->fd->num) {
if (srt_type!=CAMELSRT_VOICE_DISC) {
#ifdef DEBUG_CAMELSRT
dbg(21,"Display_duplicate with req %d ", p_camelsrt_call->category[srt_type].req_num);
#endif
p_camelsrt_info->msginfo[srt_type].is_duplicate = TRUE;
if (gcamel_DisplaySRT){
hidden_item = proto_tree_add_uint(tree, hf_camelsrt_Duplicate, tvb, 0,0, 77);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
} else {
if (pinfo->fd->num > p_camelsrt_call->category[srt_type].req_num) {
p_camelsrt_call->category[srt_type].req_num = pinfo->fd->num;
#ifdef DEBUG_CAMELSRT
dbg(5,"DISC Set reqlink #%u ", pinfo->fd->num);
#endif
update_camelsrt_call(p_camelsrt_call, pinfo, srt_type);
}
}
}
}
if ( gcamel_DisplaySRT &&
(p_camelsrt_call->category[srt_type].rsp_num != 0) &&
(p_camelsrt_call->category[srt_type].req_num != 0) &&
(p_camelsrt_call->category[srt_type].req_num == pinfo->fd->num) ) {
#ifdef DEBUG_CAMELSRT
dbg(20,"Display_framersplink %d ",p_camelsrt_call->category[srt_type].rsp_num);
#endif
ti = proto_tree_add_uint_format(tree, hf_camelsrt_RequestFrame, tvb, 0, 0,
p_camelsrt_call->category[srt_type].rsp_num,
"Linked response %s in frame %u",
val_to_str_const(srt_type, camelSRTtype_naming, "Unk"),
p_camelsrt_call->category[srt_type].rsp_num);
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
static void
camelsrt_display_DeltaTime(proto_tree *tree, tvbuff_t *tvb, nstime_t *value_ptr,
guint category)
{
proto_item *ti;
if ( gcamel_DisplaySRT ) {
switch(category) {
case CAMELSRT_VOICE_INITIALDP:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime31, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_VOICE_ACR1:
case CAMELSRT_VOICE_ACR2:
case CAMELSRT_VOICE_ACR3:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime22, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_VOICE_DISC:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime35, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_GPRS_INITIALDP:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime75, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_GPRS_REPORT:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime80, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
case CAMELSRT_SMS_INITIALDP:
ti = proto_tree_add_time(tree, hf_camelsrt_DeltaTime65, tvb, 0, 0, value_ptr);
PROTO_ITEM_SET_GENERATED(ti);
break;
default:
break;
}
}
}
static void
camelsrt_report_call_matching(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree,
struct camelsrt_info_t *p_camelsrt_info,
guint srt_type)
{
struct camelsrt_call_t *p_camelsrt_call;
struct camelsrt_call_info_key_t camelsrt_call_key;
nstime_t delta;
proto_item *ti, *hidden_item;
#ifdef DEBUG_CAMELSRT
dbg(10,"\n %s #%u\n", val_to_str_const(srt_type, camelSRTtype_naming, "Unk"),pinfo->fd->num);
#endif
camelsrt_call_key.SessionIdKey = p_camelsrt_info->tcap_session_id;
#ifdef DEBUG_CAMELSRT
dbg(11,"Search key %lu ",camelsrt_call_key.SessionIdKey);
#endif
p_camelsrt_call = find_camelsrt_call(&camelsrt_call_key);
if(p_camelsrt_call) {
#ifdef DEBUG_CAMELSRT
dbg(12,"Found, req=%d ",p_camelsrt_call->category[srt_type].req_num);
#endif
if ( gcamel_DisplaySRT )
proto_tree_add_uint(tree, hf_camelsrt_SessionId, tvb, 0,0, p_camelsrt_call->session_id);
if (srt_type==CAMELSRT_VOICE_ACR1) {
if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].req_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR3].req_num < pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR1;
} else if ( p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].req_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR2].req_num < pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR2;
} else if (p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].req_num != 0
&& p_camelsrt_call->category[CAMELSRT_VOICE_ACR1].req_num < pinfo->fd->num) {
srt_type=CAMELSRT_VOICE_ACR1;
}
#ifdef DEBUG_CAMELSRT
dbg(70,"Report ACR %u ",srt_type);
#endif
}
p_camelsrt_info->bool_msginfo[srt_type]=TRUE;
if (p_camelsrt_call->category[srt_type].rsp_num == 0) {
if ( (p_camelsrt_call->category[srt_type].req_num != 0)
&& (pinfo->fd->num > p_camelsrt_call->category[srt_type].req_num) ){
#ifdef DEBUG_CAMELSRT
dbg(14,"Set reslink #%d req %u ",pinfo->fd->num, p_camelsrt_call->category[srt_type].req_num);
#endif
p_camelsrt_call->category[srt_type].rsp_num = pinfo->fd->num;
} else {
#ifdef DEBUG_CAMELSRT
dbg(2,"badreslink #%u req %u ",pinfo->fd->num, p_camelsrt_call->category[srt_type].req_num);
#endif
}
} else {
if (p_camelsrt_call->category[srt_type].rsp_num != pinfo->fd->num) {
#ifdef DEBUG_CAMELSRT
dbg(21,"Display_duplicate rsp=%d ", p_camelsrt_call->category[srt_type].rsp_num);
#endif
p_camelsrt_info->msginfo[srt_type].is_duplicate = TRUE;
if ( gcamel_DisplaySRT ){
hidden_item = proto_tree_add_uint(tree, hf_camelsrt_Duplicate, tvb, 0,0, 77);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
if ( (p_camelsrt_call->category[srt_type].req_num != 0) &&
(p_camelsrt_call->category[srt_type].rsp_num != 0) &&
(p_camelsrt_call->category[srt_type].rsp_num == pinfo->fd->num) ) {
p_camelsrt_call->category[srt_type].responded = TRUE;
p_camelsrt_info->msginfo[srt_type].request_available = TRUE;
#ifdef DEBUG_CAMELSRT
dbg(20,"Display_frameReqlink %d ",p_camelsrt_call->category[srt_type].req_num);
#endif
if ( gcamel_DisplaySRT ) {
ti = proto_tree_add_uint_format(tree, hf_camelsrt_ResponseFrame, tvb, 0, 0,
p_camelsrt_call->category[srt_type].req_num,
"Linked request %s in frame %u",
val_to_str_const(srt_type, camelSRTtype_naming, "Unk"),
p_camelsrt_call->category[srt_type].req_num);
PROTO_ITEM_SET_GENERATED(ti);
}
nstime_delta(&delta, &pinfo->fd->abs_ts, &p_camelsrt_call->category[srt_type].req_time);
p_camelsrt_info->msginfo[srt_type].is_delta_time = TRUE;
p_camelsrt_info->msginfo[srt_type].delta_time = delta;
p_camelsrt_info->msginfo[srt_type].req_time = p_camelsrt_call->category[srt_type].req_time;
camelsrt_display_DeltaTime(tree, tvb, &delta, srt_type);
}
}
}
void
camelsrt_call_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
struct camelsrt_info_t *p_camelsrt_info)
{
#ifdef DEBUG_CAMELSRT
dbg(10,"tcap_session #%d ", p_camelsrt_info->tcap_session_id);
#endif
switch (p_camelsrt_info->opcode) {
case 0:
camelsrt_begin_call_matching(pinfo, p_camelsrt_info);
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_INITIALDP);
break;
case 60:
camelsrt_begin_call_matching(pinfo, p_camelsrt_info);
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_SMS_INITIALDP);
break;
case 78:
camelsrt_begin_call_matching(pinfo, p_camelsrt_info);
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_GPRS_INITIALDP);
break;
case 23:
break;
case 63:
break;
case 81:
break;
case 24:
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_DISC );
break;
case 64:
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
tcapsrt_close((struct tcaphash_context_t *)p_camelsrt_info->tcap_context, pinfo);
break;
case 80:
camelsrt_begin_call_matching(pinfo, p_camelsrt_info);
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_GPRS_REPORT);
break;
case 35:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_ACR1 );
break;
case 71:
break;
case 36:
camelsrt_request_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_ACR1 );
break;
case 72:
break;
case 31:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_INITIALDP);
break;
case 65:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_SMS_INITIALDP);
break;
case 75:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_GPRS_INITIALDP);
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_GPRS_REPORT);
break;
case 22:
camelsrt_report_call_matching(tvb, pinfo, tree, p_camelsrt_info,
CAMELSRT_VOICE_DISC);
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
break;
case 66:
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
tcapsrt_close((struct tcaphash_context_t *)p_camelsrt_info->tcap_context,pinfo);
break;
case 79:
camelsrt_close_call_matching(pinfo, p_camelsrt_info);
break;
}
}
struct camelsrt_info_t *
camelsrt_razinfo(void)
{
struct camelsrt_info_t *p_camelsrt_info ;
camelsrt_global_current++;
if(camelsrt_global_current==MAX_CAMEL_INSTANCE){
camelsrt_global_current=0;
}
p_camelsrt_info=&camelsrt_global_info[camelsrt_global_current];
memset(p_camelsrt_info,0,sizeof(struct camelsrt_info_t));
p_camelsrt_info->opcode=255;
return p_camelsrt_info;
}
static int
dissect_camel_camelPDU(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_,proto_tree *tree,
int hf_index, struct tcap_private_t * p_private_tcap) {
char *version_ptr;
opcode = 0;
application_context_version = 0;
if (p_private_tcap != NULL){
if (p_private_tcap->acv==TRUE ){
version_ptr = strrchr((const char *)p_private_tcap->oid,'.');
if (version_ptr)
application_context_version = atoi(version_ptr+1);
}
gp_camelsrt_info->tcap_context=p_private_tcap->context;
if (p_private_tcap->context)
gp_camelsrt_info->tcap_session_id = ( (struct tcaphash_context_t *) (p_private_tcap->context))->session_id;
}
camel_pdu_type = tvb_get_guint8(tvb, offset)&0x0f;
camel_pdu_size = tvb_get_guint8(tvb, offset+1)+2;
col_add_str(actx->pinfo->cinfo, COL_INFO, val_to_str(camel_pdu_type, camel_Component_vals, "Unknown Camel (%u)"));
col_append_str(actx->pinfo->cinfo, COL_INFO, " ");
is_ExtensionField =FALSE;
offset = dissect_camel_ROS(TRUE, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_camel_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
proto_item *item, *stat_item;
proto_tree *tree = NULL, *stat_tree = NULL;
struct tcap_private_t * p_private_tcap = (struct tcap_private_t*)data;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Camel-v1");
camel_ver = 1;
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_camel, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_camel);
}
gp_camelsrt_info=camelsrt_razinfo();
dissect_camel_camelPDU(FALSE, tvb, 0, &asn1_ctx , tree, -1, p_private_tcap);
if (gcamel_HandleSRT &&
gp_camelsrt_info->tcap_context ) {
if (gcamel_DisplaySRT && tree) {
stat_item = proto_tree_add_text(tree, tvb, 0, 0, "Stat");
stat_tree = proto_item_add_subtree(stat_item, ett_camel_stat);
}
camelsrt_call_matching(tvb, pinfo, stat_tree, gp_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, gp_camelsrt_info);
}
return tvb_length(tvb);
}
static int
dissect_camel_v2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
proto_item *item, *stat_item;
proto_tree *tree = NULL, *stat_tree = NULL;
struct tcap_private_t * p_private_tcap = (struct tcap_private_t*)data;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Camel-v2");
camel_ver = 2;
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_camel, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_camel);
}
gp_camelsrt_info=camelsrt_razinfo();
dissect_camel_camelPDU(FALSE, tvb, 0, &asn1_ctx , tree, -1, p_private_tcap);
if (gcamel_HandleSRT &&
gp_camelsrt_info->tcap_context ) {
if (gcamel_DisplaySRT && tree) {
stat_item = proto_tree_add_text(tree, tvb, 0, 0, "Stat");
stat_tree = proto_item_add_subtree(stat_item, ett_camel_stat);
}
camelsrt_call_matching(tvb, pinfo, stat_tree, gp_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, gp_camelsrt_info);
}
return tvb_length(tvb);
}
static int
dissect_camel(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
proto_item *item, *stat_item;
proto_tree *tree, *stat_tree = NULL;
struct tcap_private_t * p_private_tcap = (struct tcap_private_t*)data;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Camel");
camel_ver = 0;
item = proto_tree_add_item(parent_tree, proto_camel, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_camel);
gp_camelsrt_info=camelsrt_razinfo();
dissect_camel_camelPDU(FALSE, tvb, 0, &asn1_ctx , tree, -1, p_private_tcap);
if (gcamel_HandleSRT &&
gp_camelsrt_info->tcap_context ) {
if (gcamel_DisplaySRT && tree) {
stat_item = proto_tree_add_text(tree, tvb, 0, 0, "Stat");
stat_tree = proto_item_add_subtree(stat_item, ett_camel_stat);
}
camelsrt_call_matching(tvb, pinfo, stat_tree, gp_camelsrt_info);
tap_queue_packet(camel_tap, pinfo, gp_camelsrt_info);
}
return tvb_length(tvb);
}
static void range_delete_callback(guint32 ssn)
{
if (ssn) {
delete_itu_tcap_subdissector(ssn, camel_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn) {
add_itu_tcap_subdissector(ssn, camel_handle);
}
}
void proto_reg_handoff_camel(void) {
static gboolean camel_prefs_initialized = FALSE;
static range_t *ssn_range;
if (!camel_prefs_initialized) {
camel_prefs_initialized = TRUE;
camel_handle = find_dissector("camel");
camel_v1_handle = find_dissector("camel-v1");
camel_v2_handle = find_dissector("camel-v2");
register_ber_oid_dissector_handle("0.4.0.0.1.0.50.0",camel_v1_handle, proto_camel, "CAP-v1-gsmSSF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.50.1",camel_v2_handle, proto_camel, "CAP-v2-gsmSSF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.51.1",camel_v2_handle, proto_camel, "CAP-v2-assist-gsmSSF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.52.1",camel_v2_handle, proto_camel, "CAP-v2-gsmSRF-to-gsmSCF-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.21.3.50",camel_handle, proto_camel, "cap3-gprssf-scfAC" );
register_ber_oid_dissector_handle("0.4.0.0.1.21.3.51",camel_handle, proto_camel, "cap3-gsmscf-gprsssfAC" );
register_ber_oid_dissector_handle("0.4.0.0.1.21.3.61",camel_handle, proto_camel, "cap3-sms-AC" );
register_ber_oid_dissector_handle("0.4.0.0.1.23.3.4",camel_handle, proto_camel, "capssf-scfGenericAC" );
register_ber_oid_dissector_handle("0.4.0.0.1.23.3.61",camel_handle, proto_camel, "cap4-sms-AC" );
#include "packet-camel-dis-tab.c"
} else {
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
}
void proto_register_camel(void) {
module_t *camel_module;
static hf_register_info hf[] = {
{ &hf_camel_extension_code_local,
{ "local", "camel.extension_code_local",
FT_INT32, BASE_DEC, NULL, 0,
"Extension local code", HFILL }},
{ &hf_camel_error_code_local,
{ "local", "camel.error_code_local",
FT_INT32, BASE_DEC, VALS(camel_err_code_string_vals), 0,
"ERROR code", HFILL }},
{ &hf_camel_cause_indicator,
{ "Cause indicator", "camel.cause_indicator",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q850_cause_code_vals_ext, 0x7f,
NULL, HFILL }},
{ &hf_digit,
{ "Digit Value", "camel.digit_value",
FT_UINT8, BASE_DEC, VALS(digit_value), 0, NULL, HFILL }},
{ &hf_camel_PDPTypeNumber_etsi,
{ "ETSI defined PDP Type Value", "camel.PDPTypeNumber_etsi",
FT_UINT8, BASE_HEX, VALS(gsm_map_etsi_defined_pdp_vals), 0,
NULL, HFILL }},
{ &hf_camel_PDPTypeNumber_ietf,
{ "IETF defined PDP Type Value", "camel.PDPTypeNumber_ietf",
FT_UINT8, BASE_HEX, VALS(gsm_map_ietf_defined_pdp_vals), 0,
NULL, HFILL }},
{ &hf_camel_PDPAddress_IPv4,
{ "PDPAddress IPv4", "camel.PDPAddress_IPv4",
FT_IPv4, BASE_NONE, NULL, 0,
"IPAddress IPv4", HFILL }},
{ &hf_camel_PDPAddress_IPv6,
{ "PDPAddress IPv6", "camel.PDPAddress_IPv6",
FT_IPv6, BASE_NONE, NULL, 0,
"IPAddress IPv6", HFILL }},
{ &hf_camel_cellGlobalIdOrServiceAreaIdFixedLength,
{ "CellGlobalIdOrServiceAreaIdFixedLength", "camel.CellGlobalIdOrServiceAreaIdFixedLength",
FT_BYTES, BASE_NONE, NULL, 0,
"LocationInformationGPRS/CellGlobalIdOrServiceAreaIdOrLAI", HFILL }},
{ &hf_camel_RP_Cause,
{ "RP Cause", "camel.RP_Cause",
FT_UINT8, BASE_DEC, NULL, 0,
"RP Cause Value", HFILL }},
{ &hf_camel_CAMEL_AChBillingChargingCharacteristics,
{ "CAMEL-AChBillingChargingCharacteristics", "camel.CAMEL_AChBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_AChBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_FCIBillingChargingCharacteristics,
{ "CAMEL-FCIBillingChargingCharacteristics", "camel.CAMEL_FCIBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_FCIBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_FCIGPRSBillingChargingCharacteristics,
{ "CAMEL-FCIGPRSBillingChargingCharacteristics", "camel.CAMEL_FCIGPRSBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_FCISMSBillingChargingCharacteristics,
{ "CAMEL-FCISMSBillingChargingCharacteristics", "camel.CAMEL_FCISMSBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_FCISMSBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_SCIBillingChargingCharacteristics,
{ "CAMEL-SCIBillingChargingCharacteristics", "camel.CAMEL_SCIBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_SCIBillingChargingCharacteristics_vals), 0,
NULL, HFILL }},
{ &hf_camel_CAMEL_SCIGPRSBillingChargingCharacteristics,
{ "CAMEL-SCIGPRSBillingChargingCharacteristics", "camel.CAMEL_SCIGPRSBillingChargingCharacteristics",
FT_UINT32, BASE_DEC, NULL, 0,
"CAMEL-FSCIGPRSBillingChargingCharacteristics", HFILL }},
{ &hf_camel_CAMEL_CallResult,
{ "CAMEL-CAMEL_CallResult", "camel.CAMEL_CallResult",
FT_UINT32, BASE_DEC, VALS(camel_CAMEL_CallResult_vals), 0,
"CAMEL-CallResult", HFILL }},
{ &hf_camelsrt_SessionId,
{ "Session Id",
"camel.srt.session_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_camelsrt_RequestNumber,
{ "Request Number",
"camel.srt.request_number",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_camelsrt_Duplicate,
{ "Request Duplicate",
"camel.srt.duplicate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_camelsrt_RequestFrame,
{ "Requested Frame",
"camel.srt.reqframe",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Request Frame", HFILL }
},
{ &hf_camelsrt_ResponseFrame,
{ "Response Frame",
"camel.srt.rspframe",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Response Frame", HFILL }
},
{ &hf_camelsrt_DeltaTime,
{ "Service Response Time",
"camel.srt.deltatime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between Request and Response", HFILL }
},
{ &hf_camelsrt_SessionTime,
{ "Session duration",
"camel.srt.sessiontime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Duration of the TCAP session", HFILL }
},
{ &hf_camelsrt_DeltaTime31,
{ "Service Response Time",
"camel.srt.deltatime31",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between InitialDP and Continue", HFILL }
},
{ &hf_camelsrt_DeltaTime65,
{ "Service Response Time",
"camel.srt.deltatime65",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between InitialDPSMS and ContinueSMS", HFILL }
},
{ &hf_camelsrt_DeltaTime75,
{ "Service Response Time",
"camel.srt.deltatime75",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between InitialDPGPRS and ContinueGPRS", HFILL }
},
{ &hf_camelsrt_DeltaTime35,
{ "Service Response Time",
"camel.srt.deltatime35",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between ApplyCharginReport and ApplyCharging", HFILL }
},
{ &hf_camelsrt_DeltaTime22,
{ "Service Response Time",
"camel.srt.deltatime22",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between EventReport(Disconnect) and Release Call", HFILL }
},
{ &hf_camelsrt_DeltaTime80,
{ "Service Response Time",
"camel.srt.deltatime80",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"DeltaTime between EventReportGPRS and ContinueGPRS", HFILL }
},
#ifdef REMOVED
#endif
#include "packet-camel-hfarr.c"
};
static gint *ett[] = {
&ett_camel,
&ett_camelisup_parameter,
&ett_camel_AccessPointName,
&ett_camel_pdptypenumber,
&ett_camel_cause,
&ett_camel_RPcause,
&ett_camel_stat,
&ett_camel_calledpartybcdnumber,
&ett_camel_callingpartynumber,
&ett_camel_locationnumber,
#include "packet-camel-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_camel_unknown_invokeData, { "camel.unknown.invokeData", PI_MALFORMED, PI_WARN, "Unknown invokeData", EXPFILL }},
{ &ei_camel_unknown_returnResultData, { "camel.unknown.returnResultData", PI_MALFORMED, PI_WARN, "Unknown returnResultData", EXPFILL }},
{ &ei_camel_unknown_returnErrorData, { "camel.unknown.returnErrorData", PI_MALFORMED, PI_WARN, "Unknown returnResultData", EXPFILL }},
};
expert_module_t* expert_camel;
proto_camel = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("camel", dissect_camel, proto_camel);
new_register_dissector("camel-v1", dissect_camel_v1, proto_camel);
new_register_dissector("camel-v2", dissect_camel_v2, proto_camel);
proto_register_field_array(proto_camel, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_camel = expert_register_protocol(proto_camel);
expert_register_field_array(expert_camel, ei, array_length(ei));
rose_ctx_init(&camel_rose_ctx);
camel_rose_ctx.arg_local_dissector_table = register_dissector_table("camel.ros.local.arg",
"CAMEL Operation Argument (local opcode)",
FT_UINT32, BASE_HEX);
camel_rose_ctx.res_local_dissector_table = register_dissector_table("camel.ros.local.res",
"CAMEL Operation Result (local opcode)",
FT_UINT32, BASE_HEX);
camel_rose_ctx.err_local_dissector_table = register_dissector_table("camel.ros.local.err",
"CAMEL Error (local opcode)",
FT_UINT32, BASE_HEX);
range_convert_str(&global_ssn_range, "146", MAX_SSN);
camel_module = prefs_register_protocol(proto_camel, proto_reg_handoff_camel);
prefs_register_enum_preference(camel_module, "date.format", "Date Format",
"The date format: (DD/MM) or (MM/DD)",
&date_format, date_options, FALSE);
prefs_register_range_preference(camel_module, "tcap.ssn",
"TCAP SSNs",
"TCAP Subsystem numbers used for Camel",
&global_ssn_range, MAX_SSN);
prefs_register_bool_preference(camel_module, "srt",
"Service Response Time Analyse",
"Activate the analyse for Response Time",
&gcamel_HandleSRT);
prefs_register_bool_preference(camel_module, "persistentsrt",
"Persistent stats for SRT",
"Statistics for Response Time",
&gcamel_PersistentSRT);
register_init_routine(&camelsrt_init_routine);
camel_tap=register_tap(PSNAME);
}
