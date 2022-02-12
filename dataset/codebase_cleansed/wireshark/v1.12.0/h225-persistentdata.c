static gint h225ras_call_equal(gconstpointer k1, gconstpointer k2)
{
const h225ras_call_info_key* key1 = (const h225ras_call_info_key*) k1;
const h225ras_call_info_key* key2 = (const h225ras_call_info_key*) k2;
return (key1->reqSeqNum == key2->reqSeqNum &&
key1->conversation == key2->conversation);
}
static guint h225ras_call_hash(gconstpointer k)
{
const h225ras_call_info_key* key = (const h225ras_call_info_key*) k;
return key->reqSeqNum + GPOINTER_TO_UINT(key->conversation);
}
h225ras_call_t * find_h225ras_call(h225ras_call_info_key *h225ras_call_key ,int category)
{
h225ras_call_t *h225ras_call = NULL;
h225ras_call = (h225ras_call_t *)g_hash_table_lookup(ras_calls[category], h225ras_call_key);
return h225ras_call;
}
h225ras_call_t * new_h225ras_call(h225ras_call_info_key *h225ras_call_key, packet_info *pinfo, e_guid_t *guid, int category)
{
h225ras_call_info_key *new_h225ras_call_key;
h225ras_call_t *h225ras_call = NULL;
new_h225ras_call_key = se_new(h225ras_call_info_key);
new_h225ras_call_key->reqSeqNum = h225ras_call_key->reqSeqNum;
new_h225ras_call_key->conversation = h225ras_call_key->conversation;
h225ras_call = se_new(h225ras_call_t);
h225ras_call->req_num = pinfo->fd->num;
h225ras_call->rsp_num = 0;
h225ras_call->requestSeqNum = h225ras_call_key->reqSeqNum;
h225ras_call->responded = FALSE;
h225ras_call->next_call = NULL;
h225ras_call->req_time=pinfo->fd->abs_ts;
h225ras_call->guid=*guid;
g_hash_table_insert(ras_calls[category], new_h225ras_call_key, h225ras_call);
return h225ras_call;
}
h225ras_call_t * append_h225ras_call(h225ras_call_t *prev_call, packet_info *pinfo, e_guid_t *guid, int category _U_)
{
h225ras_call_t *h225ras_call = NULL;
h225ras_call = se_new(h225ras_call_t);
h225ras_call->req_num = pinfo->fd->num;
h225ras_call->rsp_num = 0;
h225ras_call->requestSeqNum = prev_call->requestSeqNum;
h225ras_call->responded = FALSE;
h225ras_call->next_call = NULL;
h225ras_call->req_time=pinfo->fd->abs_ts;
h225ras_call->guid=*guid;
prev_call->next_call = h225ras_call;
return h225ras_call;
}
void
h225_init_routine(void)
{
int i;
for(i=0;i<7;i++) {
if (ras_calls[i] != NULL) {
g_hash_table_destroy(ras_calls[i]);
ras_calls[i] = NULL;
}
}
for(i=0;i<7;i++) {
ras_calls[i] = g_hash_table_new(h225ras_call_hash, h225ras_call_equal);
}
}
