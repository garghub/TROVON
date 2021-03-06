static int
mgcpstat_packet(void *pms, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pmi)
{
rtd_data_t* rtd_data = (rtd_data_t*)pms;
rtd_stat_table* ms = &rtd_data->stat_table;
const mgcp_info_t *mi = (const mgcp_info_t *)pmi;
nstime_t delta;
int ret = 0;
switch (mi->mgcp_type) {
case MGCP_REQUEST:
if (mi->is_duplicate) {
ms->time_stats[0].req_dup_num++;
}
else {
ms->time_stats[0].open_req_num++;
}
break;
case MGCP_RESPONSE:
if (mi->is_duplicate) {
ms->time_stats[0].rsp_dup_num++;
}
else if (!mi->request_available) {
ms->time_stats[0].disc_rsp_num++;
}
else {
ms->time_stats[0].open_req_num--;
nstime_delta(&delta, &pinfo->abs_ts, &mi->req_time);
time_stat_update(&(ms->time_stats[0].rtd[0]), &delta, pinfo);
if (g_ascii_strncasecmp(mi->code, "EPCF", 4) == 0 ) {
time_stat_update(&(ms->time_stats[0].rtd[1]), &delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "CRCX", 4) == 0 ) {
time_stat_update(&(ms->time_stats[0].rtd[2]), &delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "MDCX", 4) == 0 ) {
time_stat_update(&(ms->time_stats[0].rtd[3]), &delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "DLCX", 4) == 0 ) {
time_stat_update(&(ms->time_stats[0].rtd[4]), &delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "RQNT", 4) == 0 ) {
time_stat_update(&(ms->time_stats[0].rtd[5]), &delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "NTFY", 4) == 0 ) {
time_stat_update(&(ms->time_stats[0].rtd[6]), &delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "AUEP", 4) == 0 ) {
time_stat_update(&(ms->time_stats[0].rtd[7]), &delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "AUCX", 4) == 0 ) {
time_stat_update(&(ms->time_stats[0].rtd[8]), &delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "RSIP", 4) == 0 ) {
time_stat_update(&(ms->time_stats[0].rtd[9]), &delta, pinfo);
}
else {
time_stat_update(&(ms->time_stats[0].rtd[10]), &delta, pinfo);
}
ret = 1;
}
break;
default:
break;
}
return ret;
}
static gint mgcp_call_equal(gconstpointer k1, gconstpointer k2)
{
const mgcp_call_info_key* key1 = (const mgcp_call_info_key*) k1;
const mgcp_call_info_key* key2 = (const mgcp_call_info_key*) k2;
return (key1->transid == key2->transid &&
key1->conversation == key2->conversation);
}
static guint mgcp_call_hash(gconstpointer k)
{
const mgcp_call_info_key* key = (const mgcp_call_info_key*) k;
return key->transid + key->conversation->conv_index;
}
static int dissect_mgcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint sectionlen;
guint32 num_messages;
gint tvb_sectionend, tvb_sectionbegin, tvb_len;
proto_tree *mgcp_tree = NULL;
proto_item *ti = NULL, *tii;
const gchar *verb_name = "";
tvb_sectionend = 0;
tvb_sectionbegin = tvb_sectionend;
tvb_len = tvb_reported_length(tvb);
num_messages = 0;
if (!is_mgcp_verb(tvb, 0, tvb_len, &verb_name) && !is_mgcp_rspcode(tvb, 0, tvb_len))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MGCP");
col_clear(pinfo->cinfo, COL_INFO);
do
{
num_messages++;
ti = proto_tree_add_item(tree, proto_mgcp, tvb, 0, 0, ENC_NA);
mgcp_tree = proto_item_add_subtree(ti, ett_mgcp);
sectionlen = tvb_find_dot_line(tvb, tvb_sectionbegin, -1, &tvb_sectionend);
if (sectionlen != -1)
{
dissect_mgcp_message(tvb_new_subset_length_caplen(tvb, tvb_sectionbegin,
sectionlen, sectionlen),
pinfo, tree, mgcp_tree, ti);
tvb_sectionbegin = tvb_sectionend;
}
else
{
break;
}
} while (tvb_sectionend < tvb_len);
tii = proto_tree_add_uint(mgcp_tree, hf_mgcp_messagecount, tvb,
0 , 0 , num_messages);
PROTO_ITEM_SET_HIDDEN(tii);
tvb_sectionbegin = 0;
if (global_mgcp_message_count == TRUE )
{
if (num_messages > 1)
{
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "MGCP (%i messages)", num_messages);
}
else
{
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "MGCP (%i message)", num_messages);
}
}
sectionlen = tvb_find_line_end(tvb, tvb_sectionbegin, -1,
&tvb_sectionend, FALSE);
col_prepend_fstr(pinfo->cinfo, COL_INFO, "%s",
tvb_format_text(tvb, tvb_sectionbegin, sectionlen));
return tvb_len;
}
static int dissect_tpkt_mgcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint16 ascii_tpkt;
int offset = 0;
ascii_tpkt = is_asciitpkt(tvb);
if (ascii_tpkt != 1 )
{
offset = dissect_mgcp(tvb, pinfo, tree, NULL);
}
else
{
dissect_asciitpkt(tvb, pinfo, tree, mgcp_handle);
offset = tvb_reported_length(tvb);
}
return offset;
}
static void dissect_mgcp_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *mgcp_tree, proto_tree *ti)
{
gint sectionlen;
gint tvb_sectionend, tvb_sectionbegin, tvb_len;
tvbuff_t *next_tvb;
const gchar *verb_name = "";
mgcp_info_t* mi = wmem_new0(pinfo->pool, mgcp_info_t);
mi->mgcp_type = MGCP_OTHERS;
tvb_len = tvb_reported_length(tvb);
if (is_mgcp_verb(tvb, 0, tvb_len, &verb_name) || is_mgcp_rspcode(tvb, 0, tvb_len))
{
tvb_sectionbegin = 0;
tvb_sectionend = tvb_sectionbegin;
sectionlen = tvb_find_line_end(tvb, 0, -1, &tvb_sectionend, FALSE);
if (sectionlen > 0)
{
dissect_mgcp_firstline(tvb_new_subset_length_caplen(tvb, tvb_sectionbegin,
sectionlen, sectionlen), pinfo,
mgcp_tree, mi);
}
tvb_sectionbegin = tvb_sectionend;
if (tvb_sectionbegin < tvb_len)
{
sectionlen = tvb_find_null_line(tvb, tvb_sectionbegin, -1,
&tvb_sectionend);
if (sectionlen > 0)
{
dissect_mgcp_params(tvb_new_subset_length_caplen(tvb, tvb_sectionbegin, sectionlen, sectionlen),
mgcp_tree, mi);
}
}
sectionlen = tvb_sectionend;
proto_item_set_len(ti, sectionlen);
if (global_mgcp_raw_text)
{
mgcp_raw_text_add(tvb, mgcp_tree);
}
if (tvb_sectionend < tvb_len)
{
next_tvb = tvb_new_subset_remaining(tvb, tvb_sectionend);
call_dissector(sdp_handle, next_tvb, pinfo, tree);
}
}
}
static void mgcp_raw_text_add(tvbuff_t *tvb, proto_tree *tree)
{
gint tvb_linebegin, tvb_lineend, linelen;
tvb_linebegin = 0;
do
{
tvb_find_line_end(tvb, tvb_linebegin, -1, &tvb_lineend, FALSE);
linelen = tvb_lineend - tvb_linebegin;
proto_tree_add_format_text(tree, tvb, tvb_linebegin, linelen);
tvb_linebegin = tvb_lineend;
} while (tvb_offset_exists(tvb, tvb_lineend));
}
static gboolean is_mgcp_verb(tvbuff_t *tvb, gint offset, gint maxlength, const gchar **verb_name)
{
gboolean returnvalue = FALSE;
gchar word[5];
if (tvb_captured_length_remaining(tvb, offset) < (gint)sizeof(word))
return FALSE;
if ((maxlength >= 4) && tvb_get_nstringz0(tvb, offset, sizeof(word), word))
{
if (((g_ascii_strncasecmp(word, "EPCF", 4) == 0) && (*verb_name = "EndpointConfiguration")) ||
((g_ascii_strncasecmp(word, "CRCX", 4) == 0) && (*verb_name = "CreateConnection")) ||
((g_ascii_strncasecmp(word, "MDCX", 4) == 0) && (*verb_name = "ModifyConnection")) ||
((g_ascii_strncasecmp(word, "DLCX", 4) == 0) && (*verb_name = "DeleteConnection")) ||
((g_ascii_strncasecmp(word, "RQNT", 4) == 0) && (*verb_name = "NotificationRequest")) ||
((g_ascii_strncasecmp(word, "NTFY", 4) == 0) && (*verb_name = "Notify")) ||
((g_ascii_strncasecmp(word, "AUEP", 4) == 0) && (*verb_name = "AuditEndpoint")) ||
((g_ascii_strncasecmp(word, "AUCX", 4) == 0) && (*verb_name = "AuditConnection")) ||
((g_ascii_strncasecmp(word, "RSIP", 4) == 0) && (*verb_name = "RestartInProgress")) ||
((g_ascii_strncasecmp(word, "MESG", 4) == 0) && (*verb_name = "Message")) ||
(word[0] == 'X' && is_rfc2234_alpha(word[1]) && is_rfc2234_alpha(word[2]) &&
is_rfc2234_alpha(word[3]) && (*verb_name = "*Experimental*")))
{
returnvalue = TRUE;
}
}
if (returnvalue && maxlength >= 5)
{
char next = tvb_get_guint8(tvb, 4);
if ((next != ' ') && (next != '\t'))
{
returnvalue = FALSE;
}
}
return returnvalue;
}
static gboolean is_mgcp_rspcode(tvbuff_t *tvb, gint offset, gint maxlength)
{
gboolean returnvalue = FALSE;
guint8 word[4];
if (tvb_captured_length_remaining(tvb, offset) < (gint)sizeof(word))
return FALSE;
if (maxlength >= 3)
{
tvb_get_nstringz0(tvb, offset, sizeof(word), word);
if (g_ascii_isdigit(word[0]) && g_ascii_isdigit(word[1]) && g_ascii_isdigit(word[2]))
{
returnvalue = TRUE;
}
}
if (returnvalue && maxlength >= 4)
{
char next = tvb_get_guint8(tvb, 3);
if ((next != ' ') && (next != '\t'))
{
returnvalue = FALSE;
}
}
return returnvalue;
}
static gboolean is_rfc2234_alpha(guint8 c)
{
return ((c <= 'Z' && c >= 'A' ) || (c <= 'z' && c >= 'a'));
}
static gint tvb_parse_param(tvbuff_t* tvb, gint offset, gint len, int** hf, mgcp_info_t* mi)
{
gint returnvalue = -1, tvb_current_offset, counter;
guint8 tempchar, plus_minus;
gchar **buf;
tvb_current_offset = offset;
*hf = NULL;
buf = NULL;
if (len > 0)
{
tempchar = tvb_get_guint8(tvb, tvb_current_offset);
switch (tempchar)
{
case 'K':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_rspack;
break;
case 'B':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_bearerinfo;
break;
case 'C':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_callid;
break;
case 'I':
tvb_current_offset++;
if (len > (tvb_current_offset - offset) &&
(tempchar = tvb_get_guint8(tvb, tvb_current_offset)) == ':')
{
*hf = &hf_mgcp_param_connectionid;
tvb_current_offset--;
}
else
if (tempchar == '2')
{
*hf = &hf_mgcp_param_secondconnectionid;
}
break;
case 'N':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_notifiedentity;
break;
case 'X':
tvb_current_offset++;
if (len > (tvb_current_offset - offset) &&
(tempchar = tvb_get_guint8(tvb, tvb_current_offset)) == ':')
{
*hf = &hf_mgcp_param_requestid;
tvb_current_offset--;
}
else
if (len > (tvb_current_offset - offset) &&
((plus_minus = tvb_get_guint8(tvb, tvb_current_offset)) == '-' ||
(plus_minus == '+')))
{
tvb_current_offset++;
for (counter = 1;
((len > (counter + tvb_current_offset-offset)) &&
(is_rfc2234_alpha(tempchar = tvb_get_guint8(tvb, tvb_current_offset+counter)) ||
g_ascii_isdigit(tempchar))) ;
counter++);
if (tempchar == ':')
{
tvb_current_offset += counter;
switch (plus_minus)
{
case '+':
*hf = &hf_mgcp_param_extension_critical;
break;
case '-':
*hf = &hf_mgcp_param_extension;
break;
}
}
}
break;
case 'L':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_localconnoptions;
break;
case 'M':
tvb_current_offset++;
if (len > (tvb_current_offset - offset) &&
(tempchar = tvb_get_guint8(tvb, tvb_current_offset)) == ':')
{
*hf = &hf_mgcp_param_connectionmode;
tvb_current_offset--;
}
else
if (tempchar == 'D')
{
*hf = &hf_mgcp_param_maxmgcpdatagram;
}
break;
case 'R':
tvb_current_offset++;
if (len > (tvb_current_offset - offset) &&
(tempchar = tvb_get_guint8(tvb, tvb_current_offset)) == ':')
{
*hf = &hf_mgcp_param_reqevents;
tvb_current_offset--;
}
else
if ( tempchar == 'M')
{
*hf = &hf_mgcp_param_restartmethod;
}
else
if (tempchar == 'D')
{
*hf = &hf_mgcp_param_restartdelay;
}
break;
case 'S':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_signalreq;
buf = &(mi->signalReq);
break;
case 'D':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_digitmap;
mi->hasDigitMap = TRUE;
break;
case 'O':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_observedevent;
buf = &(mi->observedEvents);
break;
case 'P':
tvb_current_offset++;
if (len > (tvb_current_offset - offset) &&
(tempchar = tvb_get_guint8(tvb, tvb_current_offset)) == ':')
{
*hf = &hf_mgcp_param_connectionparam;
tvb_current_offset--;
}
else
if ( tempchar == 'L')
{
*hf = &hf_mgcp_param_packagelist;
}
break;
case 'E':
tvb_current_offset++;
if (len > (tvb_current_offset - offset) &&
(tempchar = tvb_get_guint8(tvb, tvb_current_offset)) == ':')
{
*hf = &hf_mgcp_param_reasoncode;
tvb_current_offset--;
}
else
if ( tempchar == 'S')
{
*hf = &hf_mgcp_param_eventstates;
}
break;
case 'Z':
tvb_current_offset++;
if (len > (tvb_current_offset - offset) &&
(tempchar = tvb_get_guint8(tvb, tvb_current_offset)) == ':')
{
*hf = &hf_mgcp_param_specificendpoint;
tvb_current_offset--;
}
else
if (tempchar == '2')
{
*hf = &hf_mgcp_param_secondendpointid;
}
break;
case 'F':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_reqinfo;
break;
case 'Q':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_quarantinehandling;
break;
case 'T':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_detectedevents;
break;
case 'A':
if (tvb_get_guint8(tvb, tvb_current_offset+1) != ':')
{
*hf = &hf_mgcp_param_invalid;
break;
}
*hf = &hf_mgcp_param_capabilities;
break;
default:
*hf = &hf_mgcp_param_invalid;
break;
}
tvb_current_offset++;
if (*hf != NULL && len > (tvb_current_offset - offset) &&
tvb_get_guint8(tvb, tvb_current_offset) == ':')
{
tvb_current_offset++;
tvb_current_offset = tvb_skip_wsp(tvb, tvb_current_offset, (len - tvb_current_offset + offset));
returnvalue = tvb_current_offset;
if (buf != NULL) {
*buf = tvb_get_string_enc(wmem_packet_scope(), tvb, tvb_current_offset, (len - tvb_current_offset + offset), ENC_ASCII);
}
}
}
else
{
*hf = &hf_mgcp_param_invalid;
}
if ((*hf == &hf_mgcp_param_invalid) ||
(*hf == &hf_mgcp_param_extension) || (*hf == &hf_mgcp_param_extension_critical))
{
returnvalue = offset;
}
return returnvalue;
}
static void dissect_mgcp_firstline(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, mgcp_info_t* mi)
{
gint tvb_current_offset, tvb_previous_offset, tvb_len, tvb_current_len;
gint tokennum, tokenlen;
proto_item* hidden_item;
char *transid = NULL;
char *code = NULL;
char *endpointId = NULL;
mgcp_type_t mgcp_type = MGCP_OTHERS;
conversation_t* conversation;
mgcp_call_info_key mgcp_call_key;
mgcp_call_info_key *new_mgcp_call_key = NULL;
mgcp_call_t *mgcp_call = NULL;
nstime_t delta;
const gchar *verb_description = "";
char code_with_verb[64] = "";
proto_item* pi;
static address null_address = ADDRESS_INIT_NONE;
tvb_previous_offset = 0;
tvb_len = tvb_reported_length(tvb);
tvb_current_offset = tvb_previous_offset;
mi->is_duplicate = FALSE;
mi->request_available = FALSE;
{
tokennum = 0;
do
{
tvb_current_len = tvb_reported_length_remaining(tvb, tvb_previous_offset);
tvb_current_offset = tvb_find_guint8(tvb, tvb_previous_offset, tvb_current_len, ' ');
if (tvb_current_offset == -1)
{
tvb_current_offset = tvb_len;
tokenlen = tvb_current_len;
}
else
{
tokenlen = tvb_current_offset - tvb_previous_offset;
}
if (tokennum == 0)
{
if (tokenlen > 4)
{
return;
}
code = tvb_format_text(tvb, tvb_previous_offset, tokenlen);
g_strlcpy(mi->code, code, 5);
if (is_mgcp_verb(tvb, tvb_previous_offset, tvb_current_len, &verb_description))
{
mgcp_type = MGCP_REQUEST;
if (verb_description != NULL)
{
g_snprintf(code_with_verb, 64, "%s (%s)", code, verb_description);
}
proto_tree_add_string_format(tree, hf_mgcp_req_verb, tvb,
tvb_previous_offset, tokenlen,
code, "%s",
strlen(code_with_verb) ? code_with_verb : code);
}
else
if (is_mgcp_rspcode(tvb, tvb_previous_offset, tvb_current_len))
{
gboolean rspcode_valid;
mgcp_type = MGCP_RESPONSE;
rspcode_valid = ws_strtou32(code, NULL, &mi->rspcode);
pi = proto_tree_add_uint(tree, hf_mgcp_rsp_rspcode, tvb,
tvb_previous_offset, tokenlen, mi->rspcode);
if (!rspcode_valid)
expert_add_info(pinfo, pi, &ei_mgcp_rsp_rspcode_invalid);
}
else
{
break;
}
}
if (tokennum == 1)
{
transid = tvb_format_text(tvb, tvb_previous_offset, tokenlen);
mi->transid = (guint32)strtoul(transid, NULL, 10);
proto_tree_add_string(tree, hf_mgcp_transid, tvb,
tvb_previous_offset, tokenlen, transid);
}
if (tokennum == 2)
{
if (mgcp_type == MGCP_REQUEST)
{
endpointId = tvb_format_text(tvb, tvb_previous_offset, tokenlen);
mi->endpointId = wmem_strdup(wmem_packet_scope(), endpointId);
proto_tree_add_string(tree, hf_mgcp_req_endpoint, tvb,
tvb_previous_offset, tokenlen, endpointId);
}
else
if (mgcp_type == MGCP_RESPONSE)
{
if (tvb_current_offset < tvb_len)
{
tokenlen = tvb_find_line_end(tvb, tvb_previous_offset,
-1, &tvb_current_offset, FALSE);
}
else
{
tokenlen = tvb_current_len;
}
proto_tree_add_string(tree, hf_mgcp_rsp_rspstring, tvb,
tvb_previous_offset, tokenlen,
tvb_format_text(tvb, tvb_previous_offset,
tokenlen));
break;
}
}
if ((tokennum == 3 && mgcp_type == MGCP_REQUEST))
{
if (tvb_current_offset < tvb_len )
{
tokenlen = tvb_find_line_end(tvb, tvb_previous_offset,
-1, &tvb_current_offset, FALSE);
}
else
{
tokenlen = tvb_current_len;
}
proto_tree_add_string(tree, hf_mgcp_version, tvb,
tvb_previous_offset, tokenlen,
tvb_format_text(tvb, tvb_previous_offset,
tokenlen));
break;
}
if (tvb_current_offset < tvb_len)
{
tvb_previous_offset = tvb_skip_wsp(tvb, tvb_current_offset,
tvb_current_len);
}
tokennum++;
} while (tvb_current_offset < tvb_len && tvb_offset_exists(tvb, tvb_current_offset) && tvb_previous_offset < tvb_len && tokennum <= 3);
switch (mgcp_type)
{
case MGCP_RESPONSE:
hidden_item = proto_tree_add_boolean(tree, hf_mgcp_rsp, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (pinfo->ptype == PT_TCP)
{
conversation = find_conversation(pinfo->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
}
else
{
conversation = find_conversation(pinfo->num, &null_address,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
}
if (conversation != NULL)
{
mgcp_call_key.transid = mi->transid;
mgcp_call_key.conversation = conversation;
mgcp_call = (mgcp_call_t *)wmem_map_lookup(mgcp_calls, &mgcp_call_key);
if (mgcp_call)
{
if (mgcp_call->req_num)
{
proto_item* item;
mi->request_available = TRUE;
mgcp_call->responded = TRUE;
mi->req_num = mgcp_call->req_num;
g_strlcpy(mi->code, mgcp_call->code, 5);
item = proto_tree_add_uint_format(tree, hf_mgcp_req_frame,
tvb, 0, 0, mgcp_call->req_num,
"This is a response to a request in frame %u",
mgcp_call->req_num);
PROTO_ITEM_SET_GENERATED(item);
nstime_delta(&delta, &pinfo->abs_ts, &mgcp_call->req_time);
item = proto_tree_add_time(tree, hf_mgcp_time, tvb, 0, 0, &delta);
PROTO_ITEM_SET_GENERATED(item);
}
if (mgcp_call->rsp_num == 0)
{
mgcp_call->rsp_num = pinfo->num;
}
else
{
if ((mgcp_call->rsp_num != pinfo->num) &&
(mi->rspcode >= 200) &&
(mi->rspcode == mgcp_call->rspcode))
{
proto_item* item;
mi->is_duplicate = TRUE;
col_append_fstr(pinfo->cinfo, COL_INFO,
", Duplicate Response %u",
mi->transid);
item = proto_tree_add_uint(tree, hf_mgcp_dup, tvb, 0, 0, mi->transid);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_uint(tree, hf_mgcp_rsp_dup,
tvb, 0, 0, mi->transid);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(tree, hf_mgcp_rsp_dup_frame,
tvb, 0, 0, mgcp_call->rsp_num);
PROTO_ITEM_SET_GENERATED(item);
}
}
mgcp_call->rspcode = mi->rspcode;
}
}
break;
case MGCP_REQUEST:
hidden_item = proto_tree_add_boolean(tree, hf_mgcp_req, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (pinfo->ptype == PT_TCP)
{
conversation = find_conversation(pinfo->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
}
else
{
conversation = find_conversation(pinfo->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
}
if (conversation == NULL)
{
if (pinfo->ptype == PT_TCP)
{
conversation = conversation_new(pinfo->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
}
else
{
conversation = conversation_new(pinfo->num, &pinfo->src,
&null_address, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
}
}
mgcp_call_key.transid = mi->transid;
mgcp_call_key.conversation = conversation;
mgcp_call = (mgcp_call_t *)wmem_map_lookup(mgcp_calls, &mgcp_call_key);
if (mgcp_call != NULL)
{
if (pinfo->num != mgcp_call->req_num)
{
mi->is_duplicate = TRUE;
mi->req_num = mgcp_call->req_num;
col_append_fstr(pinfo->cinfo, COL_INFO,
", Duplicate Request %u",
mi->transid);
if (tree)
{
proto_item* item;
item = proto_tree_add_uint(tree, hf_mgcp_dup, tvb, 0, 0, mi->transid);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_uint(tree, hf_mgcp_req_dup, tvb, 0, 0, mi->transid);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(tree, hf_mgcp_req_dup_frame, tvb, 0, 0, mi->req_num);
PROTO_ITEM_SET_GENERATED(item);
}
}
}
else
{
new_mgcp_call_key = (mgcp_call_info_key *)wmem_alloc(wmem_file_scope(), sizeof(*new_mgcp_call_key));
*new_mgcp_call_key = mgcp_call_key;
mgcp_call = (mgcp_call_t *)wmem_alloc(wmem_file_scope(), sizeof(*mgcp_call));
mgcp_call->req_num = pinfo->num;
mgcp_call->rsp_num = 0;
mgcp_call->transid = mi->transid;
mgcp_call->responded = FALSE;
mgcp_call->req_time=pinfo->abs_ts;
g_strlcpy(mgcp_call->code, mi->code, 5);
wmem_map_insert(mgcp_calls, new_mgcp_call_key, mgcp_call);
}
if (mgcp_call->rsp_num)
{
proto_item* item = proto_tree_add_uint_format(tree, hf_mgcp_rsp_frame,
tvb, 0, 0, mgcp_call->rsp_num,
"The response to this request is in frame %u",
mgcp_call->rsp_num);
PROTO_ITEM_SET_GENERATED(item);
}
break;
default:
break;
}
mi->mgcp_type = mgcp_type;
if (mgcp_call)
{
mi->req_time.secs=mgcp_call->req_time.secs;
mi->req_time.nsecs=mgcp_call->req_time.nsecs;
}
}
tap_queue_packet(mgcp_tap, pinfo, mi);
}
static void dissect_mgcp_params(tvbuff_t *tvb, proto_tree *tree, mgcp_info_t* mi)
{
int linelen, tokenlen, *my_param;
gint tvb_lineend, tvb_linebegin, tvb_len, old_lineend;
gint tvb_tokenbegin;
proto_tree *mgcp_param_ti, *mgcp_param_tree;
tvb_len = tvb_reported_length(tvb);
tvb_linebegin = 0;
tvb_lineend = tvb_linebegin;
mgcp_param_ti = proto_tree_add_item(tree, hf_mgcp_params, tvb,
tvb_linebegin, tvb_len, ENC_NA);
proto_item_set_text(mgcp_param_ti, "Parameters");
mgcp_param_tree = proto_item_add_subtree(mgcp_param_ti, ett_mgcp_param);
while (tvb_offset_exists(tvb, tvb_lineend))
{
old_lineend = tvb_lineend;
linelen = tvb_find_line_end(tvb, tvb_linebegin, -1, &tvb_lineend, FALSE);
tvb_tokenbegin = tvb_parse_param(tvb, tvb_linebegin, linelen, &my_param, mi);
if (my_param)
{
if (*my_param == hf_mgcp_param_connectionparam)
{
tokenlen = tvb_find_line_end(tvb, tvb_tokenbegin, -1, &tvb_lineend, FALSE);
dissect_mgcp_connectionparams(mgcp_param_tree, tvb, tvb_linebegin,
tvb_tokenbegin - tvb_linebegin, tokenlen);
}
else
if (*my_param == hf_mgcp_param_localconnoptions)
{
tokenlen = tvb_find_line_end(tvb, tvb_tokenbegin, -1, &tvb_lineend, FALSE);
dissect_mgcp_localconnectionoptions(mgcp_param_tree, tvb, tvb_linebegin,
tvb_tokenbegin - tvb_linebegin, tokenlen);
}
else
{
tokenlen = tvb_find_line_end(tvb, tvb_tokenbegin, -1, &tvb_lineend, FALSE);
proto_tree_add_string(mgcp_param_tree, *my_param, tvb,
tvb_linebegin, linelen,
tvb_format_text(tvb, tvb_tokenbegin, tokenlen));
}
}
tvb_linebegin = tvb_lineend;
if (old_lineend >= tvb_lineend)
{
break;
}
}
}
static void
dissect_mgcp_connectionparams(proto_tree *parent_tree, tvbuff_t *tvb, gint offset, gint param_type_len, gint param_val_len)
{
proto_tree *tree;
proto_item *item;
gchar *tokenline;
gchar **tokens;
guint i;
item = proto_tree_add_item(parent_tree, hf_mgcp_param_connectionparam, tvb, offset, param_type_len+param_val_len, ENC_ASCII|ENC_NA);
tree = proto_item_add_subtree(item, ett_mgcp_param_connectionparam);
offset += param_type_len;
tokenline = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, param_val_len, ENC_ASCII);
tokens = wmem_strsplit(wmem_packet_scope(), tokenline, ",", -1);
for (i = 0; tokens[i] != NULL; i++)
{
gchar **typval;
guint tokenlen;
int hf_uint = -1;
int hf_string = -1;
tokenlen = (int)strlen(tokens[i]);
typval = wmem_strsplit(wmem_packet_scope(), tokens[i], "=", 2);
if ((typval[0] != NULL) && (typval[1] != NULL))
{
if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "PS"))
{
hf_uint = hf_mgcp_param_connectionparam_ps;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "OS"))
{
hf_uint = hf_mgcp_param_connectionparam_os;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "PR"))
{
hf_uint = hf_mgcp_param_connectionparam_pr;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "OR"))
{
hf_uint = hf_mgcp_param_connectionparam_or;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "PL"))
{
hf_uint = hf_mgcp_param_connectionparam_pl;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "JI"))
{
hf_uint = hf_mgcp_param_connectionparam_ji;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "LA"))
{
hf_uint = hf_mgcp_param_connectionparam_la;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "PC/RPS"))
{
hf_uint = hf_mgcp_param_connectionparam_pcrps;
} else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "PC/ROS"))
{
hf_uint = hf_mgcp_param_connectionparam_pcros;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "PC/RPL"))
{
hf_uint = hf_mgcp_param_connectionparam_pcrpl;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "PC/RJI"))
{
hf_uint = hf_mgcp_param_connectionparam_pcrji;
}
else if (!g_ascii_strncasecmp(g_strstrip(typval[0]), "X-", 2))
{
hf_string = hf_mgcp_param_connectionparam_x;
}
else
{
hf_uint = -1;
hf_string = -1;
}
if (hf_uint != -1)
{
proto_tree_add_uint(tree, hf_uint, tvb, offset, tokenlen, (guint32)strtoul(typval[1], NULL, 10));
}
else if (hf_string != -1)
{
proto_tree_add_string(tree, hf_string, tvb, offset, tokenlen, g_strstrip(typval[1]));
}
else
{
proto_tree_add_string(tree, hf_mgcp_unknown_parameter, tvb, offset, tokenlen, tokens[i]);
}
}
else
{
proto_tree_add_string(tree, hf_mgcp_malformed_parameter, tvb, offset, tokenlen, tokens[i]);
}
offset += tokenlen + 1;
}
}
static void
dissect_mgcp_localconnectionoptions(proto_tree *parent_tree, tvbuff_t *tvb, gint offset, gint param_type_len, gint param_val_len)
{
proto_tree *tree;
proto_item *item;
gchar *tokenline;
gchar **tokens;
guint i;
item = proto_tree_add_item(parent_tree, hf_mgcp_param_localconnoptions, tvb, offset, param_type_len+param_val_len, ENC_ASCII|ENC_NA);
tree = proto_item_add_subtree(item, ett_mgcp_param_localconnectionoptions);
offset += param_type_len;
tokenline = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, param_val_len, ENC_ASCII);
tokens = wmem_strsplit(wmem_packet_scope(), tokenline, ",", -1);
for (i = 0; tokens[i] != NULL; i++)
{
gchar **typval;
guint tokenlen;
int hf_uint;
int hf_string;
hf_uint = -1;
hf_string = -1;
tokenlen = (int)strlen(tokens[i]);
typval = wmem_strsplit(wmem_packet_scope(), tokens[i], ":", 2);
if ((typval[0] != NULL) && (typval[1] != NULL))
{
if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "p"))
{
hf_uint = hf_mgcp_param_localconnoptions_p;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "a"))
{
hf_string = hf_mgcp_param_localconnoptions_a;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "s"))
{
hf_string = hf_mgcp_param_localconnoptions_s;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "e"))
{
hf_string = hf_mgcp_param_localconnoptions_e;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "sc-rtp"))
{
hf_string = hf_mgcp_param_localconnoptions_scrtp;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "sc-rtcp"))
{
hf_string = hf_mgcp_param_localconnoptions_scrtcp;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "b"))
{
hf_string = hf_mgcp_param_localconnoptions_b;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "es-ccd"))
{
hf_string = hf_mgcp_param_localconnoptions_esccd;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "es-cci"))
{
hf_string = hf_mgcp_param_localconnoptions_escci;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "dq-gi"))
{
hf_string = hf_mgcp_param_localconnoptions_dqgi;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "dq-rd"))
{
hf_string = hf_mgcp_param_localconnoptions_dqrd;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "dq-ri"))
{
hf_string = hf_mgcp_param_localconnoptions_dqri;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "dq-rr"))
{
hf_string = hf_mgcp_param_localconnoptions_dqrr;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "k"))
{
hf_string = hf_mgcp_param_localconnoptions_k;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "gc"))
{
hf_uint = hf_mgcp_param_localconnoptions_gc;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "fmtp"))
{
hf_string = hf_mgcp_param_localconnoptions_fmtp;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "nt"))
{
hf_string = hf_mgcp_param_localconnoptions_nt;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "o-fmtp"))
{
hf_string = hf_mgcp_param_localconnoptions_ofmtp;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "r"))
{
hf_string = hf_mgcp_param_localconnoptions_r;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "t"))
{
hf_string = hf_mgcp_param_localconnoptions_t;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "r-cnf"))
{
hf_string = hf_mgcp_param_localconnoptions_rcnf;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "r-dir"))
{
hf_string = hf_mgcp_param_localconnoptions_rdir;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "r-sh"))
{
hf_string = hf_mgcp_param_localconnoptions_rsh;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "mp"))
{
hf_string = hf_mgcp_param_localconnoptions_mp;
}
else if (!g_ascii_strcasecmp(g_strstrip(typval[0]), "fxr/fx"))
{
hf_string = hf_mgcp_param_localconnoptions_fxr;
}
else
{
hf_uint = -1;
hf_string = -1;
}
if (hf_uint != -1)
{
proto_tree_add_uint(tree, hf_uint, tvb, offset, tokenlen, (guint32)strtoul(typval[1], NULL, 10));
}
else if (hf_string != -1)
{
proto_tree_add_string(tree, hf_string, tvb, offset, tokenlen, g_strstrip(typval[1]));
}
else
{
proto_tree_add_string(tree, hf_mgcp_unknown_parameter, tvb, offset, tokenlen, tokens[i]);
}
}
else
{
proto_tree_add_string(tree, hf_mgcp_malformed_parameter, tvb, offset, tokenlen, tokens[i]);
}
offset += tokenlen + 1;
}
}
static gint tvb_find_null_line(tvbuff_t* tvb, gint offset, gint len, gint* next_offset)
{
gint tvb_lineend, tvb_current_len, tvb_linebegin, maxoffset;
guint tempchar;
tvb_linebegin = offset;
tvb_lineend = tvb_linebegin;
if (len != -1)
{
tvb_current_len = len;
}
else
{
tvb_current_len = tvb_reported_length_remaining(tvb, offset);
}
maxoffset = (tvb_current_len - 1) + offset;
do
{
tvb_linebegin = tvb_lineend;
tvb_current_len = tvb_reported_length_remaining(tvb, tvb_linebegin);
tvb_find_line_end(tvb, tvb_linebegin, tvb_current_len, &tvb_lineend, FALSE);
tempchar = tvb_get_guint8(tvb, tvb_linebegin);
} while (tempchar != '\r' && tempchar != '\n' && tvb_lineend <= maxoffset && tvb_offset_exists(tvb, tvb_lineend));
*next_offset = tvb_lineend;
if (tvb_lineend <= maxoffset)
{
tvb_current_len = tvb_linebegin - offset;
}
else
{
tvb_current_len = tvb_reported_length_remaining(tvb, offset);
}
return tvb_current_len;
}
static gint tvb_find_dot_line(tvbuff_t* tvb, gint offset, gint len, gint* next_offset)
{
gint tvb_current_offset, tvb_current_len, maxoffset, tvb_len;
guint8 tempchar;
tvb_current_len = len;
tvb_len = tvb_reported_length(tvb);
if (len == -1)
{
maxoffset = tvb_len - 1;
}
else
{
maxoffset = (len - 1) + offset;
}
tvb_current_offset = offset -1;
do
{
tvb_current_offset = tvb_find_guint8(tvb, tvb_current_offset+1,
tvb_current_len, '.');
tvb_current_len = maxoffset - tvb_current_offset + 1;
if (tvb_current_offset == -1)
{
break;
}
if (tvb_current_offset < maxoffset)
{
tempchar = tvb_get_guint8(tvb, tvb_current_offset+1);
if (tempchar == '\r' || tempchar == '\n')
{
if (tvb_current_offset == 0)
{
break;
}
else
{
tempchar = tvb_get_guint8(tvb, tvb_current_offset-1);
if (tempchar == '\r' || tempchar == '\n')
{
break;
}
}
}
}
else
if (tvb_current_offset == maxoffset)
{
if (tvb_current_offset == 0)
{
break;
}
else
{
tempchar = tvb_get_guint8(tvb, tvb_current_offset-1);
if (tempchar == '\r' || tempchar == '\n')
{
break;
}
}
}
} while (tvb_current_offset < maxoffset);
if (tvb_current_offset == -1)
{
tvb_current_offset = maxoffset +1;
*next_offset = maxoffset + 1;
}
else
{
tvb_find_line_end(tvb, tvb_current_offset, tvb_current_len, next_offset, FALSE);
}
if (tvb_current_offset == offset)
{
tvb_current_len = -1;
}
else
{
tvb_current_len = tvb_current_offset - offset;
}
return tvb_current_len;
}
void proto_register_mgcp(void)
{
expert_module_t* expert_mgcp;
static hf_register_info hf[] =
{
{ &hf_mgcp_req,
{ "Request", "mgcp.req", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True if MGCP request", HFILL }},
{ &hf_mgcp_rsp,
{ "Response", "mgcp.rsp", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if MGCP response", HFILL }},
{ &hf_mgcp_req_frame,
{ "Request Frame", "mgcp.reqframe", FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mgcp_rsp_frame,
{ "Response Frame", "mgcp.rspframe", FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mgcp_time,
{ "Time from request", "mgcp.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0,
"Timedelta between Request and Response", HFILL }},
{ &hf_mgcp_req_verb,
{ "Verb", "mgcp.req.verb", FT_STRING, BASE_NONE, NULL, 0x0,
"Name of the verb", HFILL }},
{ &hf_mgcp_req_endpoint,
{ "Endpoint", "mgcp.req.endpoint", FT_STRING, BASE_NONE, NULL, 0x0,
"Endpoint referenced by the message", HFILL }},
{ &hf_mgcp_transid,
{ "Transaction ID", "mgcp.transid", FT_STRING, BASE_NONE, NULL, 0x0,
"Transaction ID of this message", HFILL }},
{ &hf_mgcp_version,
{ "Version", "mgcp.version", FT_STRING, BASE_NONE, NULL, 0x0,
"MGCP Version", HFILL }},
{ &hf_mgcp_rsp_rspcode,
{ "Response Code", "mgcp.rsp.rspcode", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &mgcp_return_code_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_mgcp_rsp_rspstring,
{ "Response String", "mgcp.rsp.rspstring", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mgcp_params,
{ "Parameters", "mgcp.params", FT_NONE, BASE_NONE, NULL, 0x0,
"MGCP parameters", HFILL }},
{ &hf_mgcp_param_rspack,
{ "ResponseAck (K)", "mgcp.param.rspack", FT_STRING, BASE_NONE, NULL, 0x0,
"Response Ack", HFILL }},
{ &hf_mgcp_param_bearerinfo,
{ "BearerInformation (B)", "mgcp.param.bearerinfo", FT_STRING, BASE_NONE, NULL, 0x0,
"Bearer Information", HFILL }},
{ &hf_mgcp_param_callid,
{ "CallId (C)", "mgcp.param.callid", FT_STRING, BASE_NONE, NULL, 0x0,
"Call Id", HFILL }},
{ &hf_mgcp_param_connectionid,
{"ConnectionIdentifier (I)", "mgcp.param.connectionid", FT_STRING, BASE_NONE, NULL, 0x0,
"Connection Identifier", HFILL }},
{ &hf_mgcp_param_secondconnectionid,
{ "SecondConnectionID (I2)", "mgcp.param.secondconnectionid", FT_STRING, BASE_NONE, NULL, 0x0,
"Second Connection Identifier", HFILL }},
{ &hf_mgcp_param_notifiedentity,
{ "NotifiedEntity (N)", "mgcp.param.notifiedentity", FT_STRING, BASE_NONE, NULL, 0x0,
"Notified Entity", HFILL }},
{ &hf_mgcp_param_requestid,
{ "RequestIdentifier (X)", "mgcp.param.requestid", FT_STRING, BASE_NONE, NULL, 0x0,
"Request Identifier", HFILL }},
{ &hf_mgcp_param_localconnoptions,
{ "LocalConnectionOptions (L)", "mgcp.param.localconnectionoptions", FT_STRING, BASE_NONE, NULL, 0x0,
"Local Connection Options", HFILL }},
{ &hf_mgcp_param_localconnoptions_p,
{ "Packetization period (p)", "mgcp.param.localconnectionoptions.p", FT_UINT32, BASE_DEC, NULL, 0x0,
"Packetization period", HFILL }},
{ &hf_mgcp_param_localconnoptions_a,
{ "Codecs (a)", "mgcp.param.localconnectionoptions.a", FT_STRING, BASE_NONE, NULL, 0x0,
"Codecs", HFILL }},
{ &hf_mgcp_param_localconnoptions_s,
{ "Silence Suppression (s)", "mgcp.param.localconnectionoptions.s", FT_STRING, BASE_NONE, NULL, 0x0,
"Silence Suppression", HFILL }},
{ &hf_mgcp_param_localconnoptions_e,
{ "Echo Cancellation (e)", "mgcp.param.localconnectionoptions.e", FT_STRING, BASE_NONE, NULL, 0x0,
"Echo Cancellation", HFILL }},
{ &hf_mgcp_param_localconnoptions_scrtp,
{ "RTP ciphersuite (sc-rtp)", "mgcp.param.localconnectionoptions.scrtp", FT_STRING, BASE_NONE, NULL, 0x0,
"RTP ciphersuite", HFILL }},
{ &hf_mgcp_param_localconnoptions_scrtcp,
{ "RTCP ciphersuite (sc-rtcp)", "mgcp.param.localconnectionoptions.scrtcp", FT_STRING, BASE_NONE, NULL, 0x0,
"RTCP ciphersuite", HFILL }},
{ &hf_mgcp_param_localconnoptions_b,
{ "Bandwidth (b)", "mgcp.param.localconnectionoptions.b", FT_STRING, BASE_NONE, NULL, 0x0,
"Bandwidth", HFILL }},
{ &hf_mgcp_param_localconnoptions_esccd,
{ "Content Destination (es-ccd)", "mgcp.param.localconnectionoptions.esccd", FT_STRING, BASE_NONE, NULL, 0x0,
"Content Destination", HFILL }},
{ &hf_mgcp_param_localconnoptions_escci,
{ "Content Identifier (es-cci)", "mgcp.param.localconnectionoptions.escci", FT_STRING, BASE_NONE, NULL, 0x0,
"Content Identifier", HFILL }},
{ &hf_mgcp_param_localconnoptions_dqgi,
{ "D-QoS GateID (dq-gi)", "mgcp.param.localconnectionoptions.dqgi", FT_STRING, BASE_NONE, NULL, 0x0,
"D-QoS GateID", HFILL }},
{ &hf_mgcp_param_localconnoptions_dqrd,
{ "D-QoS Reserve Destination (dq-rd)", "mgcp.param.localconnectionoptions.dqrd", FT_STRING, BASE_NONE, NULL, 0x0,
"D-QoS Reserve Destination", HFILL }},
{ &hf_mgcp_param_localconnoptions_dqri,
{ "D-QoS Resource ID (dq-ri)", "mgcp.param.localconnectionoptions.dqri", FT_STRING, BASE_NONE, NULL, 0x0,
"D-QoS Resource ID", HFILL }},
{ &hf_mgcp_param_localconnoptions_dqrr,
{ "D-QoS Resource Reservation (dq-rr)", "mgcp.param.localconnectionoptions.dqrr", FT_STRING, BASE_NONE, NULL, 0x0,
"D-QoS Resource Reservation", HFILL }},
{ &hf_mgcp_param_localconnoptions_k,
{ "Encryption Key (k)", "mgcp.param.localconnectionoptions.k", FT_STRING, BASE_NONE, NULL, 0x0,
"Encryption Key", HFILL }},
{ &hf_mgcp_param_localconnoptions_gc,
{ "Gain Control (gc)", "mgcp.param.localconnectionoptions.gc", FT_UINT32, BASE_DEC, NULL, 0x0,
"Gain Control", HFILL }},
{ &hf_mgcp_param_localconnoptions_fmtp,
{ "Media Format (fmtp)", "mgcp.param.localconnectionoptions.fmtp", FT_STRING, BASE_NONE, NULL, 0x0,
"Media Format", HFILL }},
{ &hf_mgcp_param_localconnoptions_nt,
{ "Network Type (nt)", "mgcp.param.localconnectionoptions.nt", FT_STRING, BASE_NONE, NULL, 0x0,
"Network Type", HFILL }},
{ &hf_mgcp_param_localconnoptions_ofmtp,
{ "Optional Media Format (o-fmtp)", "mgcp.param.localconnectionoptions.ofmtp", FT_STRING, BASE_NONE, NULL, 0x0,
"Optional Media Format", HFILL }},
{ &hf_mgcp_param_localconnoptions_r,
{ "Resource Reservation (r)", "mgcp.param.localconnectionoptions.r", FT_STRING, BASE_NONE, NULL, 0x0,
"Resource Reservation", HFILL }},
{ &hf_mgcp_param_localconnoptions_t,
{ "Type of Service (r)", "mgcp.param.localconnectionoptions.t", FT_STRING, BASE_NONE, NULL, 0x0,
"Type of Service", HFILL }},
{ &hf_mgcp_param_localconnoptions_rcnf,
{ "Reservation Confirmation (r-cnf)", "mgcp.param.localconnectionoptions.rcnf", FT_STRING, BASE_NONE, NULL, 0x0,
"Reservation Confirmation", HFILL }},
{ &hf_mgcp_param_localconnoptions_rdir,
{ "Reservation Direction (r-dir)", "mgcp.param.localconnectionoptions.rdir", FT_STRING, BASE_NONE, NULL, 0x0,
"Reservation Direction", HFILL }},
{ &hf_mgcp_param_localconnoptions_rsh,
{ "Resource Sharing (r-sh)", "mgcp.param.localconnectionoptions.rsh", FT_STRING, BASE_NONE, NULL, 0x0,
"Resource Sharing", HFILL }},
{ &hf_mgcp_param_localconnoptions_mp,
{ "Multiple Packetization period (mp)", "mgcp.param.localconnectionoptions.mp", FT_STRING, BASE_NONE, NULL, 0x0,
"Multiple Packetization period", HFILL }},
{ &hf_mgcp_param_localconnoptions_fxr,
{ "FXR (fxr/fx)", "mgcp.param.localconnectionoptions.fxr", FT_STRING, BASE_NONE, NULL, 0x0,
"FXR", HFILL }},
{ &hf_mgcp_param_connectionmode,
{ "ConnectionMode (M)", "mgcp.param.connectionmode", FT_STRING, BASE_NONE, NULL, 0x0,
"Connection Mode", HFILL }},
{ &hf_mgcp_param_reqevents,
{ "RequestedEvents (R)", "mgcp.param.reqevents", FT_STRING, BASE_NONE, NULL, 0x0,
"Requested Events", HFILL }},
{ &hf_mgcp_param_signalreq,
{ "SignalRequests (S)", "mgcp.param.signalreq", FT_STRING, BASE_NONE, NULL, 0x0,
"Signal Request", HFILL }},
{ &hf_mgcp_param_restartmethod,
{ "RestartMethod (RM)", "mgcp.param.restartmethod", FT_STRING, BASE_NONE, NULL, 0x0,
"Restart Method", HFILL }},
{ &hf_mgcp_param_restartdelay,
{ "RestartDelay (RD)", "mgcp.param.restartdelay", FT_STRING, BASE_NONE, NULL, 0x0,
"Restart Delay", HFILL }},
{ &hf_mgcp_param_digitmap,
{ "DigitMap (D)", "mgcp.param.digitmap", FT_STRING, BASE_NONE, NULL, 0x0,
"Digit Map", HFILL }},
{ &hf_mgcp_param_observedevent,
{ "ObservedEvents (O)", "mgcp.param.observedevents", FT_STRING, BASE_NONE, NULL, 0x0,
"Observed Events", HFILL }},
{ &hf_mgcp_param_connectionparam,
{ "ConnectionParameters (P)", "mgcp.param.connectionparam", FT_STRING, BASE_NONE, NULL, 0x0,
"Connection Parameters", HFILL }},
{ &hf_mgcp_param_connectionparam_ps,
{ "Packets sent (PS)", "mgcp.param.connectionparam.ps", FT_UINT32, BASE_DEC, NULL, 0x0,
"Packets sent (P:PS)", HFILL }},
{ &hf_mgcp_param_connectionparam_os,
{ "Octets sent (OS)", "mgcp.param.connectionparam.os", FT_UINT32, BASE_DEC, NULL, 0x0,
"Octets sent (P:OS)", HFILL }},
{ &hf_mgcp_param_connectionparam_pr,
{ "Packets received (PR)", "mgcp.param.connectionparam.pr", FT_UINT32, BASE_DEC, NULL, 0x0,
"Packets received (P:PR)", HFILL }},
{ &hf_mgcp_param_connectionparam_or,
{ "Octets received (OR)", "mgcp.param.connectionparam.or", FT_UINT32, BASE_DEC, NULL, 0x0,
"Octets received (P:OR)", HFILL }},
{ &hf_mgcp_param_connectionparam_pl,
{ "Packets lost (PL)", "mgcp.param.connectionparam.pl", FT_UINT32, BASE_DEC, NULL, 0x0,
"Packets lost (P:PL)", HFILL }},
{ &hf_mgcp_param_connectionparam_ji,
{ "Jitter (JI)", "mgcp.param.connectionparam.ji", FT_UINT32, BASE_DEC, NULL, 0x0,
"Average inter-packet arrival jitter in milliseconds (P:JI)", HFILL }},
{ &hf_mgcp_param_connectionparam_la,
{ "Latency (LA)", "mgcp.param.connectionparam.la", FT_UINT32, BASE_DEC, NULL, 0x0,
"Average latency in milliseconds (P:LA)", HFILL }},
{ &hf_mgcp_param_connectionparam_pcrps,
{ "Remote Packets sent (PC/RPS)", "mgcp.param.connectionparam.pcrps", FT_UINT32, BASE_DEC, NULL, 0x0,
"Remote Packets sent (P:PC/RPS)", HFILL }},
{ &hf_mgcp_param_connectionparam_pcros,
{ "Remote Octets sent (PC/ROS)", "mgcp.param.connectionparam.pcros", FT_UINT32, BASE_DEC, NULL, 0x0,
"Remote Octets sent (P:PC/ROS)", HFILL }},
{ &hf_mgcp_param_connectionparam_pcrpl,
{ "Remote Packets lost (PC/RPL)", "mgcp.param.connectionparam.pcrpl", FT_UINT32, BASE_DEC, NULL, 0x0,
"Remote Packets lost (P:PC/RPL)", HFILL }},
{ &hf_mgcp_param_connectionparam_pcrji,
{ "Remote Jitter (PC/RJI)", "mgcp.param.connectionparam.pcrji", FT_UINT32, BASE_DEC, NULL, 0x0,
"Remote Jitter (P:PC/RJI)", HFILL }},
{ &hf_mgcp_param_connectionparam_x,
{ "Vendor Extension", "mgcp.param.connectionparam.x", FT_STRING, BASE_NONE, NULL, 0x0,
"Vendor Extension (P:X-*)", HFILL }},
{ &hf_mgcp_param_reasoncode,
{ "ReasonCode (E)", "mgcp.param.reasoncode", FT_STRING, BASE_NONE, NULL, 0x0,
"Reason Code", HFILL }},
{ &hf_mgcp_param_eventstates,
{ "EventStates (ES)", "mgcp.param.eventstates", FT_STRING, BASE_NONE, NULL, 0x0,
"Event States", HFILL }},
{ &hf_mgcp_param_specificendpoint,
{ "SpecificEndpointID (Z)", "mgcp.param.specificendpointid", FT_STRING, BASE_NONE, NULL, 0x0,
"Specific Endpoint ID", HFILL }},
{ &hf_mgcp_param_secondendpointid,
{ "SecondEndpointID (Z2)", "mgcp.param.secondendpointid", FT_STRING, BASE_NONE, NULL, 0x0,
"Second Endpoint ID", HFILL }},
{ &hf_mgcp_param_reqinfo,
{ "RequestedInfo (F)", "mgcp.param.reqinfo", FT_STRING, BASE_NONE, NULL, 0x0,
"Requested Info", HFILL }},
{ &hf_mgcp_param_quarantinehandling,
{ "QuarantineHandling (Q)", "mgcp.param.quarantinehandling", FT_STRING, BASE_NONE, NULL, 0x0,
"Quarantine Handling", HFILL }},
{ &hf_mgcp_param_detectedevents,
{ "DetectedEvents (T)", "mgcp.param.detectedevents", FT_STRING, BASE_NONE, NULL, 0x0,
"Detected Events", HFILL }},
{ &hf_mgcp_param_capabilities,
{ "Capabilities (A)", "mgcp.param.capabilities", FT_STRING, BASE_NONE, NULL, 0x0,
"Capabilities", HFILL }},
{ &hf_mgcp_param_maxmgcpdatagram,
{"MaxMGCPDatagram (MD)", "mgcp.param.maxmgcpdatagram", FT_STRING, BASE_NONE, NULL, 0x0,
"Maximum MGCP Datagram size", HFILL }},
{ &hf_mgcp_param_packagelist,
{"PackageList (PL)", "mgcp.param.packagelist", FT_STRING, BASE_NONE, NULL, 0x0,
"Package List", HFILL }},
{ &hf_mgcp_param_extension,
{ "Extension Parameter (non-critical)", "mgcp.param.extension", FT_STRING, BASE_NONE, NULL, 0x0,
"Extension Parameter", HFILL }},
{ &hf_mgcp_param_extension_critical,
{ "Extension Parameter (critical)", "mgcp.param.extensioncritical", FT_STRING, BASE_NONE, NULL, 0x0,
"Critical Extension Parameter", HFILL }},
{ &hf_mgcp_param_invalid,
{ "Invalid Parameter", "mgcp.param.invalid", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mgcp_messagecount,
{ "MGCP Message Count", "mgcp.messagecount", FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of MGCP message in a packet", HFILL }},
{ &hf_mgcp_dup,
{ "Duplicate Message", "mgcp.dup", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mgcp_req_dup,
{ "Duplicate Request", "mgcp.req.dup", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mgcp_req_dup_frame,
{ "Original Request Frame", "mgcp.req.dup.frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Frame containing original request", HFILL }},
{ &hf_mgcp_rsp_dup,
{ "Duplicate Response", "mgcp.rsp.dup", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mgcp_rsp_dup_frame,
{ "Original Response Frame", "mgcp.rsp.dup.frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Frame containing original response", HFILL }},
{ &hf_mgcp_unknown_parameter,
{ "Unknown parameter", "mgcp.unknown_parameter", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mgcp_malformed_parameter,
{ "Malformed parameter", "mgcp.rsp.malformed_parameter", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] =
{
&ett_mgcp,
&ett_mgcp_param,
&ett_mgcp_param_connectionparam,
&ett_mgcp_param_localconnectionoptions
};
static ei_register_info ei[] = {
{ &ei_mgcp_rsp_rspcode_invalid, { "mgcp.rsp.rspcode.invalid", PI_MALFORMED, PI_ERROR,
"RSP code must be a string containing an integer", EXPFILL }}
};
module_t *mgcp_module;
proto_mgcp = proto_register_protocol("Media Gateway Control Protocol", "MGCP", "mgcp");
proto_register_field_array(proto_mgcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
mgcp_calls = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), mgcp_call_hash, mgcp_call_equal);
mgcp_handle = register_dissector("mgcp", dissect_mgcp, proto_mgcp);
mgcp_module = prefs_register_protocol(proto_mgcp, proto_reg_handoff_mgcp);
prefs_register_uint_preference(mgcp_module, "tcp.gateway_port",
"MGCP Gateway TCP Port",
"Set the UDP port for gateway messages "
"(if other than the default of 2427)",
10, &global_mgcp_gateway_tcp_port);
prefs_register_uint_preference(mgcp_module, "udp.gateway_port",
"MGCP Gateway UDP Port",
"Set the TCP port for gateway messages "
"(if other than the default of 2427)",
10, &global_mgcp_gateway_udp_port);
prefs_register_uint_preference(mgcp_module, "tcp.callagent_port",
"MGCP Callagent TCP Port",
"Set the TCP port for callagent messages "
"(if other than the default of 2727)",
10, &global_mgcp_callagent_tcp_port);
prefs_register_uint_preference(mgcp_module, "udp.callagent_port",
"MGCP Callagent UDP Port",
"Set the UDP port for callagent messages "
"(if other than the default of 2727)",
10, &global_mgcp_callagent_udp_port);
prefs_register_bool_preference(mgcp_module, "display_raw_text",
"Display raw text for MGCP message",
"Specifies that the raw text of the "
"MGCP message should be displayed "
"instead of (or in addition to) the "
"dissection tree",
&global_mgcp_raw_text);
prefs_register_obsolete_preference(mgcp_module, "display_dissect_tree");
prefs_register_bool_preference(mgcp_module, "display_mgcp_message_count",
"Display the number of MGCP messages",
"Display the number of MGCP messages "
"found in a packet in the protocol column.",
&global_mgcp_message_count);
mgcp_tap = register_tap("mgcp");
register_rtd_table(proto_mgcp, NULL, 1, NUM_TIMESTATS, mgcp_mesage_type, mgcpstat_packet, NULL);
expert_mgcp = expert_register_protocol(proto_mgcp);
expert_register_field_array(expert_mgcp, ei, array_length(ei));
}
void proto_reg_handoff_mgcp(void)
{
static gboolean mgcp_prefs_initialized = FALSE;
static dissector_handle_t mgcp_tpkt_handle;
static guint gateway_tcp_port;
static guint gateway_udp_port;
static guint callagent_tcp_port;
static guint callagent_udp_port;
if (!mgcp_prefs_initialized)
{
sdp_handle = find_dissector_add_dependency("sdp", proto_mgcp);
mgcp_tpkt_handle = create_dissector_handle(dissect_tpkt_mgcp, proto_mgcp);
mgcp_prefs_initialized = TRUE;
}
else
{
dissector_delete_uint("tcp.port", gateway_tcp_port, mgcp_tpkt_handle);
dissector_delete_uint("udp.port", gateway_udp_port, mgcp_handle);
dissector_delete_uint("tcp.port", callagent_tcp_port, mgcp_tpkt_handle);
dissector_delete_uint("udp.port", callagent_udp_port, mgcp_handle);
}
gateway_tcp_port = global_mgcp_gateway_tcp_port;
gateway_udp_port = global_mgcp_gateway_udp_port;
callagent_tcp_port = global_mgcp_callagent_tcp_port;
callagent_udp_port = global_mgcp_callagent_udp_port;
dissector_add_uint("tcp.port", global_mgcp_gateway_tcp_port, mgcp_tpkt_handle);
dissector_add_uint("udp.port", global_mgcp_gateway_udp_port, mgcp_handle);
dissector_add_uint("tcp.port", global_mgcp_callagent_tcp_port, mgcp_tpkt_handle);
dissector_add_uint("udp.port", global_mgcp_callagent_udp_port, mgcp_handle);
}
