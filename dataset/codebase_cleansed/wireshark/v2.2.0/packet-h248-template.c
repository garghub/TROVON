gcp_msg_t* gcp_msg(packet_info* pinfo, int o, gboolean keep_persistent_data) {
gcp_msg_t* m;
guint32 framenum = (guint32)pinfo->num;
guint32 offset = (guint32)o;
address* src = &(pinfo->src);
address* dst = &(pinfo->dst);
address* lo_addr;
address* hi_addr;
if (keep_persistent_data) {
wmem_tree_key_t key[3];
key[0].length = 1;
key[0].key = &(framenum);
key[1].length = 1;
key[1].key = &offset;
key[2].length = 0;
key[2].key =NULL;
if (( m = (gcp_msg_t *)wmem_tree_lookup32_array(gcp_msgs,key) )) {
m->committed = TRUE;
return m;
} else {
m = wmem_new(wmem_file_scope(), gcp_msg_t);
m->framenum = framenum;
m->frametime = pinfo->abs_ts;
m->trxs = NULL;
m->committed = FALSE;
wmem_tree_insert32_array(gcp_msgs,key,m);
}
} else {
m = wmem_new0(wmem_packet_scope(), gcp_msg_t);
m->framenum = framenum;
m->trxs = NULL;
m->committed = FALSE;
}
if (cmp_address(src, dst) < 0) {
lo_addr = src;
hi_addr = dst;
} else {
lo_addr = dst;
hi_addr = src;
}
switch(lo_addr->type) {
case AT_NONE:
m->lo_addr = 0;
m->hi_addr = 0;
break;
case AT_IPv4:
memcpy((guint8*)&(m->hi_addr),hi_addr->data,4);
memcpy((guint8*)&(m->lo_addr),lo_addr->data,4);
break;
default:
if (lo_addr->type == ss7pc_address_type) {
m->hi_addr = mtp3_pc_hash((const mtp3_addr_pc_t *)hi_addr->data);
m->lo_addr = mtp3_pc_hash((const mtp3_addr_pc_t *)lo_addr->data);
}
else {
m->hi_addr = g_str_hash(address_to_str(wmem_packet_scope(), hi_addr));
m->lo_addr = g_str_hash(address_to_str(wmem_packet_scope(), lo_addr));
}
break;
}
return m;
}
gcp_trx_t* gcp_trx(gcp_msg_t* m ,guint32 t_id , gcp_trx_type_t type, gboolean keep_persistent_data) {
gcp_trx_t* t = NULL;
gcp_trx_msg_t* trxmsg;
if ( !m ) return NULL;
if (keep_persistent_data) {
if (m->committed) {
for ( trxmsg = m->trxs; trxmsg; trxmsg = trxmsg->next) {
if (trxmsg->trx && trxmsg->trx->id == t_id) {
return trxmsg->trx;
}
}
DISSECTOR_ASSERT_NOT_REACHED();
} else {
wmem_tree_key_t key[4];
key[0].length = 1;
key[0].key = &(m->hi_addr);
key[1].length = 1;
key[1].key = &(m->lo_addr);
key[2].length = 1;
key[2].key = &(t_id);
key[3].length = 0;
key[3].key = NULL;
trxmsg = wmem_new(wmem_file_scope(), gcp_trx_msg_t);
t = (gcp_trx_t *)wmem_tree_lookup32_array(gcp_trxs,key);
if (!t) {
t = wmem_new(wmem_file_scope(), gcp_trx_t);
t->initial = m;
t->id = t_id;
t->type = type;
t->pendings = 0;
t->error = 0;
t->cmds = NULL;
wmem_tree_insert32_array(gcp_trxs,key,t);
}
switch ( type ) {
case GCP_TRX_PENDING:
t->pendings++;
break;
default:
break;
}
}
} else {
t = wmem_new(wmem_packet_scope(), gcp_trx_t);
trxmsg = wmem_new(wmem_packet_scope(), gcp_trx_msg_t);
t->initial = NULL;
t->id = t_id;
t->type = type;
t->pendings = 0;
t->error = 0;
t->cmds = NULL;
}
DISSECTOR_ASSERT(trxmsg);
trxmsg->trx = t;
trxmsg->next = NULL;
trxmsg->last = trxmsg;
if (m->trxs) {
m->trxs->last = m->trxs->last->next = trxmsg;
} else {
m->trxs = trxmsg;
}
return t;
}
gcp_ctx_t* gcp_ctx(gcp_msg_t* m, gcp_trx_t* t, guint32 c_id, gboolean persistent) {
gcp_ctx_t* context = NULL;
gcp_ctx_t** context_p = NULL;
if ( !m || !t ) return NULL;
if (persistent) {
wmem_tree_key_t ctx_key[4];
wmem_tree_key_t trx_key[4];
ctx_key[0].length = 1;
ctx_key[0].key = &(m->hi_addr);
ctx_key[1].length = 1;
ctx_key[1].key = &(m->lo_addr);
ctx_key[2].length = 1;
ctx_key[2].key = &(c_id);
ctx_key[3].length = 0;
ctx_key[3].key = NULL;
trx_key[0].length = 1;
trx_key[0].key = &(m->hi_addr);
trx_key[1].length = 1;
trx_key[1].key = &(m->lo_addr);
trx_key[2].length = 1;
trx_key[2].key = &(t->id);
trx_key[3].length = 0;
trx_key[3].key = NULL;
if (m->committed) {
if (( context = (gcp_ctx_t *)wmem_tree_lookup32_array(gcp_ctxs_by_trx,trx_key) )) {
return context;
} if ((context_p = (gcp_ctx_t **)wmem_tree_lookup32_array(gcp_ctxs,ctx_key))) {
context = *context_p;
do {
if (context->initial->framenum <= m->framenum) {
return context;
}
} while(( context = context->prev ));
DISSECTOR_ASSERT(! "a context should exist");
}
} else {
if (c_id == CHOOSE_CONTEXT) {
if (! ( context = (gcp_ctx_t *)wmem_tree_lookup32_array(gcp_ctxs_by_trx,trx_key))) {
context = wmem_new(wmem_file_scope(), gcp_ctx_t);
context->initial = m;
context->cmds = NULL;
context->id = c_id;
context->terms.last = &(context->terms);
context->terms.next = NULL;
context->terms.term = NULL;
wmem_tree_insert32_array(gcp_ctxs_by_trx,trx_key,context);
}
} else {
if (( context = (gcp_ctx_t *)wmem_tree_lookup32_array(gcp_ctxs_by_trx,trx_key) )) {
if (( context_p = (gcp_ctx_t **)wmem_tree_lookup32_array(gcp_ctxs,ctx_key) )) {
if (context != *context_p) {
if(context->id != CHOOSE_CONTEXT) {
context = wmem_new(wmem_file_scope(), gcp_ctx_t);
}
context->initial = m;
context->id = c_id;
context->cmds = NULL;
context->terms.last = &(context->terms);
context->terms.next = NULL;
context->terms.term = NULL;
context->prev = *context_p;
*context_p = context;
}
} else {
context_p = wmem_new(wmem_file_scope(), gcp_ctx_t*);
*context_p = context;
context->initial = m;
context->id = c_id;
wmem_tree_insert32_array(gcp_ctxs,ctx_key,context_p);
}
} else if (! ( context_p = (gcp_ctx_t**)wmem_tree_lookup32_array(gcp_ctxs,ctx_key) )) {
context = wmem_new(wmem_file_scope(), gcp_ctx_t);
context->initial = m;
context->id = c_id;
context->cmds = NULL;
context->terms.last = &(context->terms);
context->terms.next = NULL;
context->terms.term = NULL;
context_p = wmem_new(wmem_file_scope(), gcp_ctx_t*);
*context_p = context;
wmem_tree_insert32_array(gcp_ctxs,ctx_key,context_p);
} else {
context = *context_p;
}
}
}
} else {
context = wmem_new(wmem_packet_scope(), gcp_ctx_t);
context->initial = m;
context->cmds = NULL;
context->id = c_id;
context->terms.last = &(context->terms);
context->terms.next = NULL;
context->terms.term = NULL;
}
return context;
}
gcp_cmd_t* gcp_cmd(gcp_msg_t* m, gcp_trx_t* t, gcp_ctx_t* c, gcp_cmd_type_t type, guint offset, gboolean persistent) {
gcp_cmd_t* cmd;
gcp_cmd_msg_t* cmdtrx;
gcp_cmd_msg_t* cmdctx;
if ( !m || !t || !c ) return NULL;
if (persistent) {
if (m->committed) {
DISSECTOR_ASSERT(t->cmds != NULL);
for (cmdctx = t->cmds; cmdctx; cmdctx = cmdctx->next) {
cmd = cmdctx->cmd;
if (cmd->msg == m && cmd->offset == offset) {
return cmd;
}
}
DISSECTOR_ASSERT(!"called for a command that does not exist!");
return NULL;
} else {
cmd = wmem_new(wmem_file_scope(), gcp_cmd_t);
cmdtrx = wmem_new(wmem_file_scope(), gcp_cmd_msg_t);
cmdctx = wmem_new(wmem_file_scope(), gcp_cmd_msg_t);
}
} else {
cmd = wmem_new(wmem_packet_scope(), gcp_cmd_t);
cmdtrx = wmem_new(wmem_packet_scope(), gcp_cmd_msg_t);
cmdctx = wmem_new(wmem_packet_scope(), gcp_cmd_msg_t);
}
cmd->type = type;
cmd->offset = offset;
cmd->terms.term = NULL;
cmd->terms.next = NULL;
cmd->terms.last = &(cmd->terms);
cmd->str = NULL;
cmd->msg = m;
if ((type != GCP_CMD_NONE) && (!persistent)){
cmd->str = val_to_str_const(type, gcp_cmd_type, "Unknown");
}
cmd->trx = t;
cmd->ctx = c;
cmd->error = 0;
cmdctx->cmd = cmdtrx->cmd = cmd;
cmdctx->next = cmdtrx->next = NULL;
cmdctx->last = cmdtrx->last = NULL;
if (t->cmds) {
t->cmds->last->next = cmdtrx;
t->cmds->last = cmdtrx;
} else {
t->cmds = cmdtrx;
t->cmds->last = cmdtrx;
}
if (c->cmds) {
c->cmds->last->next = cmdctx;
c->cmds->last = cmdctx;
} else {
c->cmds = cmdctx;
c->cmds->last = cmdctx;
}
return cmd;
}
gcp_term_t* gcp_cmd_add_term(gcp_msg_t* m, gcp_trx_t* tr, gcp_cmd_t* c, gcp_term_t* t, gcp_wildcard_t wildcard, gboolean persistent) {
gcp_terms_t* ct;
gcp_terms_t* ct2;
static gcp_term_t all_terms = {"$",(const guint8*)"",1,GCP_TERM_TYPE_UNKNOWN,NULL,NULL,NULL};
if ( !c ) return NULL;
if ( wildcard == GCP_WILDCARD_CHOOSE) {
return &all_terms;
}
if (persistent) {
if ( c->msg->committed ) {
if (wildcard == GCP_WILDCARD_ALL) {
for (ct = c->ctx->terms.next; ct; ct = ct->next) {
if ( ct->term->start == m ) {
return ct->term;
}
}
return NULL;
} else {
for (ct = c->ctx->terms.next; ct; ct = ct->next) {
if ( g_str_equal(ct->term->str,t->str) ) {
return ct->term;
}
}
return NULL;
}
} else {
for (ct = c->ctx->terms.next; ct; ct = ct->next) {
if ( g_str_equal(ct->term->str,t->str) || ct->term->start == m) {
break;
}
}
if ( ! ct ) {
if (wildcard == GCP_WILDCARD_ALL) {
ct = wmem_new(wmem_file_scope(), gcp_terms_t);
ct->next = NULL;
ct->term = wmem_new0(wmem_file_scope(), gcp_term_t);
ct->term->start = m;
ct->term->str = "*";
ct->term->buffer = NULL;
ct->term->len = 0;
c->terms.last = c->terms.last->next = ct;
ct2 = wmem_new0(wmem_file_scope(), gcp_terms_t);
ct2->term = ct->term;
c->ctx->terms.last->next = ct2;
c->ctx->terms.last = ct2;
return ct->term;
} else {
for (ct = c->ctx->terms.next; ct; ct = ct->next) {
if ( ct->term->buffer == NULL && tr->cmds->cmd->msg == ct->term->start ) {
ct->term->str = wmem_strdup(wmem_file_scope(), t->str);
ct->term->buffer = (const guint8 *)wmem_memdup(wmem_file_scope(), t->buffer,t->len);
ct->term->len = t->len;
ct2 = wmem_new0(wmem_file_scope(), gcp_terms_t);
ct2->term = ct->term;
c->terms.last = c->terms.last->next = ct2;
return ct->term;
}
if ( g_str_equal(ct->term->str,t->str) ) {
ct2 = wmem_new0(wmem_file_scope(), gcp_terms_t);
ct2->term = ct->term;
c->terms.last = c->terms.last->next = ct2;
return ct->term;
}
}
ct = wmem_new(wmem_file_scope(), gcp_terms_t);
ct->next = NULL;
ct->term = wmem_new0(wmem_file_scope(), gcp_term_t);
ct->term->start = m;
ct->term->str = wmem_strdup(wmem_file_scope(), t->str);
ct->term->buffer = (const guint8 *)wmem_memdup(wmem_file_scope(), t->buffer,t->len);
ct->term->len = t->len;
ct2 = wmem_new0(wmem_file_scope(), gcp_terms_t);
ct2->term = ct->term;
c->terms.last = c->terms.last->next = ct2;
ct2 = wmem_new0(wmem_file_scope(), gcp_terms_t);
ct2->term = ct->term;
c->ctx->terms.last = c->ctx->terms.last->next = ct2;
return ct->term;
}
} else {
ct2 = wmem_new0(wmem_file_scope(), gcp_terms_t);
ct2->term = ct->term;
c->terms.last = c->terms.last->next = ct2;
return ct->term;
}
DISSECTOR_ASSERT_NOT_REACHED();
}
} else {
ct = wmem_new(wmem_packet_scope(), gcp_terms_t);
ct->term = t;
ct->next = NULL;
c->terms.last = c->terms.last->next = ct;
return t;
}
}
static const gchar* gcp_cmd_to_str(gcp_cmd_t* c, gboolean persistent) {
const gchar* s;
gcp_terms_t* term;
if ( !c ) return "-";
switch (c->type) {
case GCP_CMD_NONE:
return "-";
break;
case GCP_CMD_ADD_REQ:
s = "AddReq {";
break;
case GCP_CMD_MOVE_REQ:
s = "MoveReq {";
break;
case GCP_CMD_MOD_REQ:
s = "ModReq {";
break;
case GCP_CMD_SUB_REQ:
s = "SubReq {";
break;
case GCP_CMD_AUDITCAP_REQ:
s = "AuditCapReq {";
break;
case GCP_CMD_AUDITVAL_REQ:
s = "AuditValReq {";
break;
case GCP_CMD_NOTIFY_REQ:
s = "NotifyReq {";
break;
case GCP_CMD_SVCCHG_REQ:
s = "SvcChgReq {";
break;
case GCP_CMD_TOPOLOGY_REQ:
s = "TopologyReq {";
break;
case GCP_CMD_CTX_ATTR_AUDIT_REQ:
s = "CtxAttribAuditReq {";
break;
case GCP_CMD_ADD_REPLY:
s = "AddReply {";
break;
case GCP_CMD_MOVE_REPLY:
s = "MoveReply {";
break;
case GCP_CMD_MOD_REPLY:
s = "ModReply {";
break;
case GCP_CMD_SUB_REPLY:
s = "SubReply {";
break;
case GCP_CMD_AUDITCAP_REPLY:
s = "AuditCapReply {";
break;
case GCP_CMD_AUDITVAL_REPLY:
s = "AuditValReply {";
break;
case GCP_CMD_NOTIFY_REPLY:
s = "NotifyReply {";
break;
case GCP_CMD_SVCCHG_REPLY:
s = "SvcChgReply {";
break;
case GCP_CMD_TOPOLOGY_REPLY:
s = "TopologyReply {";
break;
case GCP_CMD_REPLY:
s = "ActionReply {";
break;
case GCP_CMD_OTHER_REQ:
s = "Request {";
break;
default:
s = "-";
break;
}
for (term = c->terms.next; term; term = term->next) {
s = wmem_strdup_printf(wmem_packet_scope(), "%s %s",s,term->term->str);
}
if (c->error) {
s = wmem_strdup_printf(wmem_packet_scope(), "%s Error=%i",s,c->error);
}
s = wmem_strdup_printf(wmem_packet_scope(), "%s }", s);
if (persistent) {
if (! c->str) c->str = wmem_strdup(wmem_file_scope(), s);
} else {
c->str = s;
}
return s;
}
static const gchar* gcp_trx_to_str(gcp_msg_t* m, gcp_trx_t* t, gboolean persistent) {
gchar* s;
gcp_cmd_msg_t* c;
if ( !m || !t ) return "-";
s = wmem_strdup_printf(wmem_packet_scope(), "T %x { ",t->id);
if (t->cmds) {
if (t->cmds->cmd->ctx) {
s = wmem_strdup_printf(wmem_packet_scope(), "%s C %x {",s,t->cmds->cmd->ctx->id);
for (c = t->cmds; c; c = c->next) {
if (c->cmd->msg == m) {
s = wmem_strdup_printf(wmem_packet_scope(), "%s %s",s,gcp_cmd_to_str(c->cmd,persistent));
}
}
s = wmem_strdup_printf(wmem_packet_scope(), "%s %s",s,"}");
}
}
if (t->error) {
s = wmem_strdup_printf(wmem_packet_scope(), "%s Error=%i",s,t->error);
}
return wmem_strdup_printf(wmem_packet_scope(), "%s %s",s,"}");
}
const gchar* gcp_msg_to_str(gcp_msg_t* m, gboolean persistent) {
gcp_trx_msg_t* t;
const gchar* s = "";
if ( !m ) return "-";
for (t = m->trxs; t; t = t->next) {
s = wmem_strdup_printf(wmem_packet_scope(), "%s %s",s,gcp_trx_to_str(m,t->trx, persistent));
}
return s;
}
void gcp_analyze_msg(proto_tree* gcp_tree, packet_info* pinfo, tvbuff_t* gcp_tvb, gcp_msg_t* m, gcp_hf_ett_t* ids, expert_field* command_err) {
gcp_trx_msg_t* t;
gcp_ctxs_t contexts = {NULL,NULL};
gcp_ctxs_t* ctx_node;
gcp_cmd_msg_t* c;
for (t = m->trxs; t; t = t->next) {
for (c = t->trx->cmds; c; c = c->next) {
gcp_ctx_t* ctx = c->cmd->ctx;
for (ctx_node = contexts.next; ctx_node; ctx_node = ctx_node->next) {
if (ctx_node->ctx->id == ctx->id) {
break;
}
}
if (! ctx_node) {
ctx_node = wmem_new(wmem_packet_scope(), gcp_ctxs_t);
ctx_node->ctx = ctx;
ctx_node->next = contexts.next;
contexts.next = ctx_node;
}
}
}
for (ctx_node = contexts.next; ctx_node; ctx_node = ctx_node->next) {
gcp_ctx_t* ctx = ctx_node->ctx;
proto_item* ctx_item = proto_tree_add_uint(gcp_tree,ids->hf.ctx,gcp_tvb,0,0,ctx->id);
proto_tree* ctx_tree = proto_item_add_subtree(ctx_item,ids->ett.ctx);
gcp_terms_t *ctx_term;
PROTO_ITEM_SET_GENERATED(ctx_item);
if (ctx->cmds) {
proto_tree* history_tree = proto_tree_add_subtree(ctx_tree,gcp_tvb,0,0,ids->ett.ctx_cmds,NULL,"[ Command History ]");
for (c = ctx->cmds; c; c = c->next) {
proto_item* cmd_item = proto_tree_add_uint(history_tree,ids->hf.ctx_cmd,gcp_tvb,0,0,c->cmd->msg->framenum);
if (c->cmd->str) proto_item_append_text(cmd_item," %s ",c->cmd->str);
PROTO_ITEM_SET_GENERATED(cmd_item);
if (c->cmd->error) {
expert_add_info(pinfo, cmd_item, command_err);
}
}
}
if (( ctx_term = ctx->terms.next )) {
proto_tree* terms_tree = proto_tree_add_subtree(ctx_tree,gcp_tvb,0,0,ids->ett.ctx_terms,NULL,"[ Terminations Used ]");
for (; ctx_term; ctx_term = ctx_term->next ) {
if ( ctx_term->term && ctx_term->term->str) {
proto_item* pi = proto_tree_add_string(terms_tree,ids->hf.ctx_term,gcp_tvb,0,0,ctx_term->term->str);
proto_tree* term_tree = proto_item_add_subtree(pi,ids->ett.ctx_term);
PROTO_ITEM_SET_GENERATED(pi);
if (ctx_term->term->type) {
pi = proto_tree_add_uint(term_tree,ids->hf.ctx_term_type,gcp_tvb,0,0,ctx_term->term->type);
PROTO_ITEM_SET_GENERATED(pi);
}
if (ctx_term->term->bir) {
pi = proto_tree_add_string(term_tree,ids->hf.ctx_term_bir,gcp_tvb,0,0,ctx_term->term->bir);
PROTO_ITEM_SET_GENERATED(pi);
}
if (ctx_term->term->nsap) {
pi = proto_tree_add_string(term_tree,ids->hf.ctx_term_nsap,gcp_tvb,0,0,ctx_term->term->nsap);
PROTO_ITEM_SET_GENERATED(pi);
}
if (ctx_term->term->bir && ctx_term->term->nsap) {
gchar* tmp_key = wmem_strdup_printf(wmem_packet_scope(), "%s:%s",ctx_term->term->nsap,ctx_term->term->bir);
gchar* key = g_ascii_strdown(tmp_key, -1);
alcap_tree_from_bearer_key(term_tree, gcp_tvb, pinfo, key);
g_free(key);
}
}
}
}
}
}
static void
export_h248_pdu(packet_info *pinfo, tvbuff_t *tvb)
{
exp_pdu_data_t *exp_pdu_data = export_pdu_create_common_tags(pinfo, "h248", EXP_PDU_TAG_PROTO_NAME);
exp_pdu_data->tvb_captured_length = tvb_captured_length(tvb);
exp_pdu_data->tvb_reported_length = tvb_reported_length(tvb);
exp_pdu_data->pdu_tvb = tvb;
tap_queue_packet(exported_pdu_tap, pinfo, exp_pdu_data);
}
extern void h248_param_ber_integer(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo, int hfid, h248_curr_info_t* u _U_, void* implicit) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ber_integer(implicit ? *((gboolean*)implicit) : FALSE, &asn1_ctx, tree, tvb, 0, hfid, NULL);
}
extern void h248_param_ber_octetstring(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo, int hfid, h248_curr_info_t* u _U_, void* implicit) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ber_octet_string(implicit ? *((gboolean*)implicit) : FALSE, &asn1_ctx, tree, tvb, 0, hfid, NULL);
}
extern void h248_param_ber_boolean(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo, int hfid, h248_curr_info_t* u _U_, void* implicit) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ber_boolean(implicit ? *((gboolean*)implicit) : FALSE, &asn1_ctx, tree, tvb, 0, hfid, NULL);
}
extern void h248_param_bytes_item(proto_tree* tree,
tvbuff_t* tvb,
packet_info* pinfo _U_,
int hfid,
h248_curr_info_t* h248_info _U_,
void* lenp ) {
int len = lenp ? *((int*)lenp) : -1;
proto_tree_add_item(tree,hfid,tvb,0,len,ENC_NA);
}
extern void h248_param_uint_item(proto_tree* tree,
tvbuff_t* tvb,
packet_info* pinfo _U_,
int hfid,
h248_curr_info_t* h248_info _U_,
void* lenp ) {
int len = lenp ? *((int*)lenp) : -1;
proto_tree_add_item(tree,hfid,tvb,0,len,ENC_BIG_ENDIAN);
}
extern void h248_param_external_dissector(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo , int hfid _U_, h248_curr_info_t* u _U_, void* dissector_hdl) {
call_dissector((dissector_handle_t) dissector_hdl,tvb,pinfo,tree);
}
extern void h248_param_PkgdName(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo , int hfid _U_, h248_curr_info_t* u1 _U_, void* u2 _U_) {
tvbuff_t *new_tvb = NULL;
proto_tree *package_tree=NULL;
guint16 name_major, name_minor;
const h248_package_t* pkg = NULL;
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, offset, hfid , &new_tvb);
if (new_tvb) {
name_major=tvb_get_ntohs(new_tvb, 0);
name_minor=tvb_get_ntohs(new_tvb, 2);
pkg = find_package_id(name_major);
proto_item_append_text(asn1_ctx.created_item, " %s (%04x)",
val_to_str(0, pkg->param_names, "Unknown Package"),
name_major);
if(tree){
proto_item* pi;
const gchar* strval;
package_tree = proto_item_add_subtree(asn1_ctx.created_item, ett_packagename);
proto_tree_add_uint_format(package_tree, hf_h248_pkg_name, tvb, offset-4, 2, name_major,
"%s (0x%04x)", val_to_str(0, pkg->param_names, "Unknown Package"), name_major);
pi = proto_tree_add_uint(package_tree, hf_248_pkg_param, tvb, offset-2, 2, name_minor);
if (pkg->signal_names && ( strval = try_val_to_str(name_minor, pkg->signal_names) )) {
strval = wmem_strdup_printf(wmem_packet_scope(), "%s (%d)",strval,name_minor);
} else {
strval = wmem_strdup_printf(wmem_packet_scope(), "Unknown (%d)",name_minor);
}
proto_item_set_text(pi,"Signal ID: %s", strval);
}
}
}
static int dissect_h248_trx_id(gboolean implicit_tag, packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32* trx_id_p) {
guint64 trx_id = 0;
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
guint32 i;
if(!implicit_tag){
offset=dissect_ber_identifier(pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(pinfo, tree, tvb, offset, &len, NULL);
} else {
len=tvb_reported_length_remaining(tvb, offset);
}
if (len > 8 || len < 1) {
THROW(BoundsError);
} else {
for(i=1;i<=len;i++){
trx_id=(trx_id<<8)|tvb_get_guint8(tvb, offset);
offset++;
}
if (trx_id > 0xffffffff) {
proto_item* pi = proto_tree_add_uint64(tree, hf_h248_transactionId64, tvb, offset-len, len, trx_id);
expert_add_info(pinfo, pi, &ei_h248_transactionId64);
*trx_id_p = 0;
} else {
proto_tree_add_uint(tree, hf_h248_transactionId, tvb, offset-len, len, (guint32)trx_id);
*trx_id_p = (guint32)trx_id;
}
}
return offset;
}
static int dissect_h248_ctx_id(gboolean implicit_tag, packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32* ctx_id_p) {
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
guint64 ctx_id = 0;
guint32 i;
if(!implicit_tag){
offset=dissect_ber_identifier(pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(pinfo, tree, tvb, offset, &len, NULL);
} else {
len=tvb_reported_length_remaining(tvb, offset);
}
if (len > 8 || len < 1) {
THROW(BoundsError);
} else {
for(i=1;i<=len;i++){
ctx_id=(ctx_id<<8)|tvb_get_guint8(tvb, offset);
offset++;
}
if (ctx_id > 0xffffffff) {
proto_item* pi = proto_tree_add_uint64(tree, hf_h248_context_id64, tvb, offset-len, len, ctx_id);
expert_add_info(pinfo, pi, &ei_h248_context_id64);
*ctx_id_p = 0xfffffffd;
} else {
proto_item* pi = proto_tree_add_uint(tree, hf_h248_context_id, tvb, offset-len, len, (guint32)ctx_id);
if ( ctx_id == NULL_CONTEXT ) {
proto_item_set_text(pi,"contextId: Null Context(0)");
} else if ( ctx_id == CHOOSE_CONTEXT ) {
proto_item_set_text(pi,"contextId: $ (Choose Context = 0xfffffffe)");
} else if ( ctx_id == ALL_CONTEXTS ) {
proto_item_set_text(pi,"contextId: * (All Contexts = 0xffffffff)");
}
*ctx_id_p = (guint32) ctx_id;
}
}
return offset;
}
static s_h248_package_t *s_find_package_id(guint16 pkgid) {
s_h248_package_t *s_pkg = NULL;
s_pkg = (s_h248_package_t *)g_tree_lookup(packages, GUINT_TO_POINTER((guint32)(pkgid)));
return s_pkg;
}
const h248_package_t *find_package_id(guint16 pkgid) {
s_h248_package_t *s_pkg = NULL;
s_pkg = s_find_package_id(pkgid);
if (! s_pkg ) return &no_package;
return s_pkg->pkg;
}
static gint32 comparePkgID(gconstpointer a, gconstpointer b) {
return GPOINTER_TO_UINT(b) - GPOINTER_TO_UINT(a);
}
static gboolean is_pkg_default(guint16 pkgid) {
s_h248_package_t *s_pkg = NULL;
s_pkg = (s_h248_package_t *)g_tree_lookup(packages, GUINT_TO_POINTER((guint32)(pkgid)));
if(! s_pkg ) return TRUE;
return s_pkg->is_default;
}
void h248_register_package(h248_package_t* pkg, pkg_reg_action reg_action) {
h248_package_t *pkg_found = NULL, *pkg_high = NULL, *pkg_low = NULL;
s_h248_package_t *s_pkg = NULL;
value_string *vst;
gboolean pkg_default = FALSE;
gint j = 0, idx = 0, i = 0, k = 0;
if (! packages) {
packages = g_tree_new(comparePkgID);
while (base_package_name_vals[i].strptr != NULL) {
pkg_found = wmem_new0(wmem_epan_scope(), h248_package_t);
pkg_found->id = base_package_name_vals[i].value;
vst = (value_string *)wmem_alloc0(wmem_epan_scope(), sizeof(value_string)*2);
vst[0].strptr = base_package_name_vals[i].strptr;
pkg_found->param_names = vst;
pkg_found->hfid = &hf_h248_pkg_name;
pkg_found->ett = &ett_packagename;
try_val_to_str_idx((pkg_found->id)<<16,base_event_name_vals, &j);
if (j != -1) {
j++; idx=j;
while((base_event_name_vals[j].strptr!=NULL) && (((base_event_name_vals[j].value)>>16) == (pkg_found->id))) {
j++;
};
if (idx < j) {
vst = (value_string *)wmem_alloc0(wmem_epan_scope(), sizeof(value_string)*(j-idx+1));
for (k=0;idx<j;k++) {
vst[k].strptr = base_event_name_vals[idx].strptr;
vst[k].value = (base_event_name_vals[idx].value & 0xffff);
idx++;
};
pkg_found->event_names = vst;
}
}
if (!try_val_to_str_idx((pkg_found->id)<<16, base_signal_name_vals, &j)) {
j++; idx=j;
while((base_signal_name_vals[j].strptr != NULL) && ((base_signal_name_vals[j].value>>16) == (pkg_found->id))) {
j++;
};
if (idx < j) {
vst = (value_string *)wmem_alloc0(wmem_epan_scope(), sizeof(value_string)*(j-idx+1));
for (k=0;idx<j;k++) {
vst[k].strptr = base_signal_name_vals[idx].strptr;
vst[k].value = (base_signal_name_vals[idx].value &0xffff);
idx++;
};
pkg_found->signal_names = vst;
}
};
s_pkg = wmem_new0(wmem_epan_scope(), s_h248_package_t);
s_pkg->is_default = TRUE;
s_pkg->pkg = pkg_found;
g_tree_insert(packages, GINT_TO_POINTER(pkg_found->id), (gpointer)s_pkg);
i++;
};
pkg_found = NULL;
};
pkg_default = is_pkg_default(pkg->id);
if (((reg_action==REPLACE_PKG) || (reg_action==ADD_PKG)) && pkg_default) {
s_pkg = wmem_new0(wmem_epan_scope(), s_h248_package_t);
s_pkg->is_default = FALSE;
s_pkg->pkg = (h248_package_t *)pkg;
g_tree_replace(packages, GINT_TO_POINTER(pkg->id), (gpointer)s_pkg);
return;
};
if(pkg_default) reg_action = MERGE_PKG_HIGH;
s_pkg = s_find_package_id(pkg->id);
if (s_pkg == NULL) {
s_pkg = wmem_new0(wmem_epan_scope(), s_h248_package_t);
s_pkg->is_default = FALSE;
s_pkg->pkg = (h248_package_t *)pkg;
g_tree_insert(packages, GINT_TO_POINTER(pkg->id), (gpointer)s_pkg);
return;
}
pkg_found = s_pkg->pkg;
if (reg_action==MERGE_PKG_HIGH) {
pkg_high = (h248_package_t *)pkg;
pkg_low = pkg_found;
};
if (reg_action==MERGE_PKG_LOW) {
pkg_high = pkg_found;
pkg_low = (h248_package_t *)pkg;
};
if(pkg_high) {
(pkg_high->hfid ? (pkg_found->hfid=pkg_high->hfid) : (pkg_found->hfid=pkg_low->hfid));
(pkg_high->ett ? (pkg_found->ett=pkg_high->ett ):( pkg_found->ett=pkg_low->ett));
(pkg_high->param_names ? (pkg_found->param_names=pkg_high->param_names ):( pkg_found->param_names=pkg_low->param_names));
(pkg_high->signal_names ? (pkg_found->signal_names=pkg_high->signal_names ):( pkg_found->signal_names=pkg_low->signal_names));
(pkg_high->event_names ? (pkg_found->event_names=pkg_high->event_names ):( pkg_found->event_names=pkg_low->event_names));
(pkg_high->stats_names ? (pkg_found->stats_names=pkg_high->stats_names ):( pkg_found->stats_names=pkg_low->stats_names));
(pkg_high->properties ? (pkg_found->properties=pkg_high->properties ):( pkg_found->properties=pkg_low->properties));
(pkg_high->signals ? (pkg_found->signals=pkg_high->signals ):( pkg_found->signals=pkg_low->signals));
(pkg_high->events ? (pkg_found->events=pkg_high->events ):( pkg_found->events=pkg_low->events));
(pkg_high->statistics ? (pkg_found->statistics=pkg_high->statistics ):( pkg_found->statistics=pkg_low->statistics));
s_pkg->pkg = pkg_found;
s_pkg->is_default = FALSE;
}
}
static int dissect_h248_PkgdName(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
tvbuff_t *new_tvb = NULL;
proto_tree *package_tree=NULL;
guint16 name_major, name_minor;
const h248_package_t* pkg = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
name_major=tvb_get_ntohs(new_tvb, 0);
name_minor=tvb_get_ntohs(new_tvb, 2);
packageandid=(name_major<<16)|name_minor;
pkg = find_package_id(name_major);
proto_item_append_text(actx->created_item, " %s (%04x)",
val_to_str(0, pkg->param_names, "Unknown Package"),
name_major);
if(tree){
package_tree = proto_item_add_subtree(actx->created_item, ett_packagename);
proto_tree_add_uint_format(package_tree, hf_h248_pkg_name, tvb, offset-4, 2, name_major,
"PkgName: %s (0x%04x)", val_to_str(0, pkg->param_names, "Unknown Package"), name_major);
}
{
proto_item* pi = proto_tree_add_uint(package_tree, hf_248_pkg_param, tvb, offset-2, 2, name_minor);
const gchar* strval;
if (pkg->param_names && ( strval = try_val_to_str(name_minor, pkg->param_names) )) {
strval = wmem_strdup_printf(wmem_packet_scope(), "%s (%d)",strval,name_minor);
} else {
strval = wmem_strdup_printf(wmem_packet_scope(), "Unknown (%d)",name_minor);
}
proto_item_set_text(pi,"Parameter: %s", strval);
}
} else {
pkg = &no_package;
}
curr_info.pkg = pkg;
return offset;
}
static int dissect_h248_EventName(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
tvbuff_t *new_tvb;
proto_tree *package_tree=NULL;
guint16 name_major, name_minor;
const h248_package_t* pkg = NULL;
const h248_pkg_evt_t* evt = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
name_major=tvb_get_ntohs(new_tvb, 0);
name_minor=tvb_get_ntohs(new_tvb, 2);
packageandid=(name_major<<16)|name_minor;
pkg = find_package_id(name_major);
proto_item_append_text(actx->created_item, " %s (%04x)",
val_to_str(0, pkg->param_names, "Unknown Package"),
name_major);
if(tree){
package_tree = proto_item_add_subtree(actx->created_item, ett_packagename);
}
proto_tree_add_uint_format(package_tree, hf_h248_pkg_name, tvb, offset-4, 2, name_major,
"%s (0x%04x)", val_to_str(0, pkg->param_names, "Unknown Package"), name_major);
curr_info.pkg = pkg;
if (pkg->events) {
for (evt = pkg->events; evt->hfid; evt++) {
if (name_minor == evt->id) {
break;
}
}
if (! evt->hfid) evt = &no_event;
} else {
evt = &no_event;
}
curr_info.evt = evt;
{
proto_item* pi = proto_tree_add_uint(package_tree, hf_h248_event_code, tvb, offset-2, 2, name_minor);
const gchar* strval;
if (pkg->event_names && ( strval = try_val_to_str(name_minor, pkg->event_names) )) {
strval = wmem_strdup_printf(wmem_packet_scope(), "%s (%d)",strval,name_minor);
} else {
strval = wmem_strdup_printf(wmem_packet_scope(), "Unknown (%d)",name_minor);
}
proto_item_set_text(pi,"Event ID: %s", strval);
}
} else {
curr_info.pkg = &no_package;
curr_info.evt = &no_event;
}
return offset;
}
static int dissect_h248_SignalName(gboolean implicit_tag , tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
tvbuff_t *new_tvb;
proto_tree *package_tree=NULL;
guint16 name_major, name_minor;
const h248_package_t* pkg = NULL;
const h248_pkg_sig_t* sig;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
name_major=tvb_get_ntohs(new_tvb, 0);
name_minor=tvb_get_ntohs(new_tvb, 2);
packageandid=(name_major<<16)|name_minor;
pkg = find_package_id(name_major);
proto_item_append_text(actx->created_item, " %s (%04x)",
val_to_str(0, pkg->param_names, "Unknown Package"),
name_major);
if(tree){
package_tree = proto_item_add_subtree(actx->created_item, ett_packagename);
}
proto_tree_add_uint_format(package_tree, hf_h248_pkg_name, tvb, offset-4, 2, name_major,
"%s (0x%04x)", val_to_str(0, pkg->param_names, "Unknown Package"), name_major);
if (pkg->signals) {
for (sig = pkg->signals; sig->hfid; sig++) {
if (name_minor == sig->id) {
break;
}
}
if (! sig->hfid) sig = &no_signal;
curr_info.pkg = pkg;
curr_info.sig = sig;
} else {
curr_info.pkg = &no_package;
curr_info.sig = &no_signal;
}
{
proto_item* pi = proto_tree_add_uint(package_tree, hf_h248_signal_code, tvb, offset-2, 2, name_minor);
const gchar* strval;
if (pkg->signal_names && ( strval = try_val_to_str(name_minor, pkg->signal_names) )) {
strval = wmem_strdup_printf(wmem_packet_scope(), "%s (%d)",strval,name_minor);
} else {
strval = wmem_strdup_printf(wmem_packet_scope(), "Unknown (%d)",name_minor);
}
proto_item_set_text(pi,"Signal ID: %s", strval);
}
} else {
curr_info.pkg = &no_package;
curr_info.sig = &no_signal;
}
return offset;
}
static int dissect_h248_PropertyID(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
guint16 name_minor;
int end_offset;
const h248_package_t* pkg;
const h248_pkg_param_t* prop;
tvbuff_t *next_tvb = NULL;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
end_offset=offset+len;
if( (ber_class!=BER_CLASS_UNI)
||(tag!=BER_UNI_TAG_OCTETSTRING) ){
proto_tree_add_expert_format(tree, actx->pinfo, &ei_h248_octet_string_expected, tvb, offset-2, 2,
"H.248 BER Error: OctetString expected but Class:%d PC:%d Tag:%d was unexpected", ber_class, pc, tag);
return end_offset;
}
next_tvb = tvb_new_subset_length(tvb,offset,len);
name_minor = packageandid & 0xffff;
pkg = (curr_info.pkg) ? curr_info.pkg : &no_package;
if (pkg->properties) {
for (prop = pkg->properties; prop && prop->hfid; prop++) {
if (name_minor == prop->id) {
break;
}
}
} else {
prop = &no_param;
}
if (prop && prop->hfid && prop->dissector) {
prop->dissector(tree, next_tvb, actx->pinfo, *(prop->hfid), &curr_info, prop->data);
}
return end_offset;
}
static int dissect_h248_SigParameterName(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
tvbuff_t *next_tvb;
guint32 param_id = 0xffffffff;
const h248_pkg_param_t* sigpar;
const gchar* strval;
proto_item* pi;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &next_tvb);
pi = actx->created_item;
switch(tvb_reported_length(next_tvb)) {
case 4: param_id = tvb_get_ntohl(next_tvb,0); break;
case 3: param_id = tvb_get_ntoh24(next_tvb,0); break;
case 2: param_id = tvb_get_ntohs(next_tvb,0); break;
case 1: param_id = tvb_get_guint8(next_tvb,0); break;
default: break;
}
curr_info.par = &no_param;
if (curr_info.sig && curr_info.sig->parameters) {
for(sigpar = curr_info.sig->parameters; sigpar->hfid; sigpar++) {
if (sigpar->id == param_id) {
curr_info.par = sigpar;
break;
}
}
}
if (curr_info.sig && curr_info.sig->param_names && ( strval = try_val_to_str(param_id, curr_info.sig->param_names) )) {
strval = wmem_strdup_printf(wmem_packet_scope(), "%s (%d)",strval,param_id);
} else {
strval = wmem_strdup_printf(wmem_packet_scope(), "Unknown (%d)",param_id);
}
proto_item_set_text(pi,"Parameter: %s", strval);
return offset;
}
static int dissect_h248_SigParamValue(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
int end_offset;
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
tvbuff_t *next_tvb = NULL;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
end_offset=offset+len;
if( (ber_class!=BER_CLASS_UNI)
||(tag!=BER_UNI_TAG_OCTETSTRING) ){
proto_tree_add_expert_format(tree, actx->pinfo, &ei_h248_octet_string_expected, tvb, offset-2, 2,
"H.248 BER Error: OctetString expected but Class:%d PC:%d Tag:%d was unexpected", ber_class, pc, tag);
return end_offset;
}
next_tvb = tvb_new_subset_length(tvb,offset,len);
if ( curr_info.par && curr_info.par->dissector) {
curr_info.par->dissector(tree, next_tvb, actx->pinfo, *(curr_info.par->hfid), &curr_info, curr_info.par->data);
}
return end_offset;
}
static int dissect_h248_SigParamValueV1(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
return dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
}
static int dissect_h248_EventParameterName(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
tvbuff_t *next_tvb;
guint32 param_id = 0xffffffff;
const h248_pkg_param_t* evtpar;
const gchar* strval;
proto_item* pi;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &next_tvb);
pi = actx->created_item;
if (next_tvb) {
switch(tvb_reported_length(next_tvb)) {
case 4: param_id = tvb_get_ntohl(next_tvb,0); break;
case 3: param_id = tvb_get_ntoh24(next_tvb,0); break;
case 2: param_id = tvb_get_ntohs(next_tvb,0); break;
case 1: param_id = tvb_get_guint8(next_tvb,0); break;
default: break;
}
}
curr_info.par = &no_param;
if (curr_info.evt && curr_info.evt->parameters) {
for(evtpar = curr_info.evt->parameters; evtpar->hfid; evtpar++) {
if (evtpar->id == param_id) {
curr_info.par = evtpar;
break;
}
}
} else {
curr_info.par = &no_param;
}
if (curr_info.evt && curr_info.evt->param_names && ( strval = try_val_to_str(param_id, curr_info.evt->param_names) )) {
strval = wmem_strdup_printf(wmem_packet_scope(), "%s (%d)",strval,param_id);
} else {
strval = wmem_strdup_printf(wmem_packet_scope(), "Unknown (%d)",param_id);
}
proto_item_set_text(pi,"Parameter: %s", strval);
return offset;
}
static int dissect_h248_EventParamValue(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
tvbuff_t *next_tvb;
int end_offset;
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
end_offset=offset+len;
if( (ber_class!=BER_CLASS_UNI)
||(tag!=BER_UNI_TAG_OCTETSTRING) ){
proto_tree_add_expert_format(tree, actx->pinfo, &ei_h248_octet_string_expected, tvb, offset-2, 2,
"H.248 BER Error: OctetString expected but Class:%d PC:%d Tag:%d was unexpected", ber_class, pc, tag);
return end_offset;
}
next_tvb = tvb_new_subset_length(tvb,offset,len);
if ( curr_info.par && curr_info.par->dissector) {
curr_info.par->dissector(tree, next_tvb, actx->pinfo, *(curr_info.par->hfid), &curr_info, curr_info.par->data);
}
return end_offset;
}
static int dissect_h248_EventParamValueV1(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
return dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &tvb);
}
static int dissect_h248_MtpAddress(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
tvbuff_t *new_tvb;
proto_tree *mtp_tree=NULL;
guint32 val;
int i, len, old_offset;
old_offset=offset;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
val=0;
len=tvb_reported_length(new_tvb);
for(i=0;i<len;i++){
val= (val<<8)|tvb_get_guint8(new_tvb, i);
}
proto_item_append_text(actx->created_item, " NI = %d, PC = %d ( %d-%d )", val&0x03,val>>2,val&0x03,val>>2);
if(tree){
mtp_tree = proto_item_add_subtree(actx->created_item, ett_mtpaddress);
}
proto_tree_add_uint(mtp_tree, hf_h248_mtpaddress_ni, tvb, old_offset, offset-old_offset, val&0x03);
proto_tree_add_uint(mtp_tree, hf_h248_mtpaddress_pc, tvb, old_offset, offset-old_offset, val>>2);
}
return offset;
}
static int dissect_h248_tpkt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
dissect_tpkt_encap(tvb, pinfo, tree, h248_desegment, h248_handle);
return tvb_captured_length(tvb);
}
static int
dissect_h248(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *h248_item;
asn1_ctx_t asn1_ctx;
h248_tree = NULL;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
curr_info.msg = NULL;
curr_info.trx = NULL;
curr_info.ctx = NULL;
curr_info.cmd = NULL;
curr_info.term = NULL;
curr_info.pkg = NULL;
curr_info.evt = NULL;
curr_info.sig = NULL;
curr_info.stat = NULL;
curr_info.par = NULL;
if(tvb_captured_length(tvb)>=6){
if(!tvb_strneql(tvb, 0, "MEGACO", 6)){
static dissector_handle_t megaco_handle=NULL;
if(!megaco_handle){
megaco_handle = find_dissector("megaco");
}
if(megaco_handle){
call_dissector(megaco_handle, tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
}
{
proto_item *hidden_item = NULL;
guint32 magic_num = 0, offset = 0;
magic_num = tvb_get_ntohl(tvb, offset);
hidden_item = proto_tree_add_uint(tree, hf_248_magic_num, tvb, offset, 4, magic_num);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if( dissector_try_uint(subdissector_table, magic_num, tvb, pinfo, tree) ) {
return tvb_captured_length(tvb);
}
}
}
export_h248_pdu(pinfo, tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "H.248");
if (tree) {
h248_item = proto_tree_add_item(tree, proto_h248, tvb, 0, -1, ENC_NA);
h248_tree = proto_item_add_subtree(h248_item, ett_h248);
}
dissect_h248_MegacoMessage(FALSE, tvb, 0, &asn1_ctx, h248_tree, -1);
return tvb_captured_length(tvb);
}
void proto_register_h248(void) {
static hf_register_info hf[] = {
{ &hf_248_magic_num,
{ "Magic Number for Avaya H.248", "h248.magic_num",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_h248_mtpaddress_ni,
{ "NI", "h248.mtpaddress.ni",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_mtpaddress_pc,
{ "PC", "h248.mtpaddress.pc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_pkg_name,
{ "Package", "h248.package_name",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_248_pkg_param,
{ "Parameter ID", "h248.package_paramid",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_signal_code,
{ "Signal ID", "h248.package_signalid",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_event_code,
{ "Event ID", "h248.package_eventid",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_event_name,
{ "Package and Event name", "h248.event_name",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_signal_name,
{ "Package and Signal name", "h248.signal_name",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_pkg_bcp_BNCChar_PDU,
{ "BNCChar", "h248.package_bcp.BNCChar",
FT_UINT32, BASE_DEC, VALS(gcp_term_types), 0,
NULL, HFILL }},
{ &hf_h248_context_id,
{ "contextId", "h248.contextId",
FT_UINT32, BASE_HEX, NULL, 0,
"Context ID", HFILL }},
{ &hf_h248_term_wild_type,
{ "Wildcard Mode", "h248.term.wildcard.mode",
FT_UINT8, BASE_DEC, VALS(wildcard_modes), 0x80,
NULL, HFILL }},
{ &hf_h248_term_wild_level,
{ "Wildcarding Level", "h248.term.wildcard.level",
FT_UINT8, BASE_DEC, VALS(wildcard_levels), 0x40,
NULL, HFILL }},
{ &hf_h248_term_wild_position,
{ "Wildcarding Position", "h248.term.wildcard.pos",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }},
{ &hf_h248_no_pkg,
{ "Unknown Package", "h248.pkg.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_no_sig,
{ "Unknown Signal", "h248.pkg.unknown.sig",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_no_evt,
{ "Unknown Event", "h248.pkg.unknown.evt",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_param,
{ "Parameter", "h248.pkg.unknown.param",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_serviceChangeReasonStr,
{ "ServiceChangeReasonStr", "h248.serviceChangeReasonstr",
FT_STRING, BASE_NONE, NULL, 0,
"h248.IA5String", HFILL }},
{ &hf_h248_context_id64,
{ "contextId", "h248.contextId64",
FT_UINT64, BASE_HEX, NULL, 0,
"Context ID", HFILL }},
{ &hf_h248_transactionId64,
{ "transactionId", "h248.transactionId",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_auditValueReplyV1,
{ "auditValueReplyV1", "h248.auditValueReplyV1",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-h248-hfarr.c"
GCP_HF_ARR_ELEMS("h248",h248_arrel)
};
static gint *ett[] = {
&ett_h248,
&ett_mtpaddress,
&ett_packagename,
&ett_codec,
&ett_wildcard,
&ett_h248_no_pkg,
&ett_h248_no_sig,
&ett_h248_no_evt,
GCP_ETT_ARR_ELEMS(h248_arrel),
#include "packet-h248-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_h248_errored_command, { "h248.errored_command", PI_RESPONSE_CODE, PI_WARN, "Errored Command", EXPFILL }},
{ &ei_h248_transactionId64, { "h248.transactionId.error", PI_MALFORMED, PI_WARN, "Transaction ID invalid", EXPFILL }},
{ &ei_h248_context_id64, { "h248.contextId.error", PI_MALFORMED, PI_WARN, "Context ID invalid", EXPFILL }},
{ &ei_h248_octet_string_expected, { "h248.octet_string_expected", PI_PROTOCOL, PI_WARN, "H.248 BER Error: OctetString expected", EXPFILL }},
};
expert_module_t* expert_h248;
module_t *h248_module;
proto_h248 = proto_register_protocol(PNAME, PSNAME, PFNAME);
h248_handle = register_dissector("h248", dissect_h248, proto_h248);
h248_tpkt_handle = register_dissector("h248.tpkt", dissect_h248_tpkt, proto_h248);
proto_register_field_array(proto_h248, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_h248 = expert_register_protocol(proto_h248);
expert_register_field_array(expert_h248, ei, array_length(ei));
subdissector_table = register_dissector_table("h248.magic_num", "H248 Magic Num", proto_h248, FT_UINT32, BASE_HEX);
h248_module = prefs_register_protocol(proto_h248, proto_reg_handoff_h248);
prefs_register_bool_preference(h248_module, "ctx_info",
"Track Context",
"Maintain relationships between transactions and contexts and display an extra tree showing context data",
&keep_persistent_data);
prefs_register_uint_preference(h248_module, "udp_port",
"UDP port",
"Port to be decoded as h248",
10,
&global_udp_port);
prefs_register_uint_preference(h248_module, "tcp_port",
"TCP port",
"Port to be decoded as h248",
10,
&global_tcp_port);
prefs_register_bool_preference(h248_module, "desegment",
"Desegment H.248 over TCP",
"Desegment H.248 messages that span more TCP segments",
&h248_desegment);
gcp_msgs = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
gcp_trxs = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
gcp_ctxs_by_trx = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
gcp_ctxs = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
h248_tap = register_tap("h248");
}
void proto_reg_handoff_h248(void) {
static gboolean initialized = FALSE;
static guint32 udp_port;
static guint32 tcp_port;
if (!initialized) {
dissector_add_uint("mtp3.service_indicator", MTP_SI_GCP, h248_handle);
h248_term_handle = find_dissector_add_dependency("h248term", proto_h248);
initialized = TRUE;
} else {
if (udp_port != 0)
dissector_delete_uint("udp.port", udp_port, h248_handle);
if (tcp_port != 0)
dissector_delete_uint("tcp.port", tcp_port, h248_tpkt_handle);
}
udp_port = global_udp_port;
tcp_port = global_tcp_port;
if (udp_port != 0) {
dissector_add_uint("udp.port", udp_port, h248_handle);
}
if (tcp_port != 0) {
dissector_add_uint("tcp.port", tcp_port, h248_tpkt_handle);
}
ss7pc_address_type = address_type_get_by_name("AT_SS7PC");
exported_pdu_tap = find_tap_id(EXPORT_PDU_TAP_NAME_LAYER_7);
}
