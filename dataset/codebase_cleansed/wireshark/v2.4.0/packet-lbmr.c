static void lbtipc_transport_init(void)
{
lbtipc_transport_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
static lbtipc_transport_t * lbtipc_transport_find(guint32 host_id, guint32 session_id, guint16 xport_id)
{
lbtipc_transport_t * entry = NULL;
guint32 keyval[LBTIPC_KEY_ELEMENT_COUNT];
wmem_tree_key_t tkey[2];
keyval[LBTIPC_KEY_ELEMENT_HOST_ID] = host_id;
keyval[LBTIPC_KEY_ELEMENT_SESSION_ID] = session_id;
keyval[LBTIPC_KEY_ELEMENT_XPORT_ID] = (guint32) xport_id;
tkey[0].length = LBTIPC_KEY_ELEMENT_COUNT;
tkey[0].key = keyval;
tkey[1].length = 0;
tkey[1].key = NULL;
entry = (lbtipc_transport_t *) wmem_tree_lookup32_array(lbtipc_transport_table, tkey);
return (entry);
}
static lbtipc_transport_t * lbtipc_transport_add(guint32 host_id, guint32 session_id, guint16 xport_id)
{
lbtipc_transport_t * entry;
guint32 keyval[LBTIPC_KEY_ELEMENT_COUNT];
wmem_tree_key_t tkey[2];
entry = lbtipc_transport_find(host_id, session_id, xport_id);
if (entry != NULL)
{
return (entry);
}
entry = wmem_new(wmem_file_scope(), lbtipc_transport_t);
entry->host_id = host_id;
entry->session_id = session_id;
entry->xport_id = xport_id;
entry->channel = lbm_channel_assign(LBM_CHANNEL_TRANSPORT_LBTIPC);
keyval[LBTIPC_KEY_ELEMENT_HOST_ID] = host_id;
keyval[LBTIPC_KEY_ELEMENT_SESSION_ID] = session_id;
keyval[LBTIPC_KEY_ELEMENT_XPORT_ID] = (guint32) xport_id;
tkey[0].length = LBTIPC_KEY_ELEMENT_COUNT;
tkey[0].key = keyval;
tkey[1].length = 0;
tkey[1].key = NULL;
wmem_tree_insert32_array(lbtipc_transport_table, tkey, (void *) entry);
return (entry);
}
static char * lbtipc_transport_source_string(guint32 host_id _U_, guint32 session_id, guint16 xport_id)
{
return (wmem_strdup_printf(wmem_file_scope(), "LBT-IPC:%x:%" G_GUINT16_FORMAT, session_id, xport_id));
}
static void lbtsmx_transport_init(void)
{
lbtsmx_transport_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
static lbtsmx_transport_t * lbtsmx_transport_find(guint32 host_id, guint32 session_id, guint16 xport_id)
{
lbtsmx_transport_t * entry = NULL;
guint32 keyval[LBTSMX_KEY_ELEMENT_COUNT];
wmem_tree_key_t tkey[2];
keyval[LBTSMX_KEY_ELEMENT_HOST_ID] = host_id;
keyval[LBTSMX_KEY_ELEMENT_SESSION_ID] = session_id;
keyval[LBTSMX_KEY_ELEMENT_XPORT_ID] = (guint32) xport_id;
tkey[0].length = LBTSMX_KEY_ELEMENT_COUNT;
tkey[0].key = keyval;
tkey[1].length = 0;
tkey[1].key = NULL;
entry = (lbtsmx_transport_t *) wmem_tree_lookup32_array(lbtsmx_transport_table, tkey);
return (entry);
}
static lbtsmx_transport_t * lbtsmx_transport_add(guint32 host_id, guint32 session_id, guint16 xport_id)
{
lbtsmx_transport_t * entry;
guint32 keyval[LBTSMX_KEY_ELEMENT_COUNT];
wmem_tree_key_t tkey[2];
entry = lbtsmx_transport_find(host_id, session_id, xport_id);
if (entry != NULL)
{
return (entry);
}
entry = wmem_new(wmem_file_scope(), lbtsmx_transport_t);
entry->host_id = host_id;
entry->session_id = session_id;
entry->xport_id = xport_id;
entry->channel = lbm_channel_assign(LBM_CHANNEL_TRANSPORT_LBTSMX);
keyval[LBTSMX_KEY_ELEMENT_HOST_ID] = host_id;
keyval[LBTSMX_KEY_ELEMENT_SESSION_ID] = session_id;
keyval[LBTSMX_KEY_ELEMENT_XPORT_ID] = (guint32) xport_id;
tkey[0].length = LBTSMX_KEY_ELEMENT_COUNT;
tkey[0].key = keyval;
tkey[1].length = 0;
tkey[1].key = NULL;
wmem_tree_insert32_array(lbtsmx_transport_table, tkey, (void *) entry);
return (entry);
}
static char * lbtsmx_transport_source_string(guint32 host_id _U_, guint32 session_id, guint16 xport_id)
{
return (wmem_strdup_printf(wmem_file_scope(), "LBT-SMX:%x:%" G_GUINT16_FORMAT, session_id, xport_id));
}
static void lbtrdma_transport_init(void)
{
lbtrdma_transport_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
static void lbtrdma_transport_build_key(guint32 * key_value, wmem_tree_key_t * key, const lbtrdma_transport_t * transport)
{
guint32 val;
memcpy(&val, transport->source_address.data, sizeof(guint32));
key_value[LBTRDMA_KEY_ELEMENT_SOURCE_ADDRESS] = val;
key_value[LBTRDMA_KEY_ELEMENT_SESSION_ID] = transport->session_id;
key_value[LBTRDMA_KEY_ELEMENT_PORT] = (guint32) transport->port;
key[0].length = LBTRDMA_KEY_ELEMENT_COUNT;
key[0].key = key_value;
key[1].length = 0;
key[1].key = NULL;
}
static lbtrdma_transport_t * lbtrdma_transport_find(const address * source_address, guint32 session_id, guint16 port)
{
lbtrdma_transport_t key;
lbtrdma_transport_t * entry = NULL;
guint32 keyval[LBTRDMA_KEY_ELEMENT_COUNT];
wmem_tree_key_t tkey[2];
memset((void *)&key, 0, sizeof(lbtrdma_transport_t));
copy_address_shallow(&(key.source_address), source_address);
key.session_id = session_id;
key.port = port;
lbtrdma_transport_build_key(keyval, tkey, &key);
entry = (lbtrdma_transport_t *) wmem_tree_lookup32_array(lbtrdma_transport_table, tkey);
return (entry);
}
static lbtrdma_transport_t * lbtrdma_transport_add(const address * source_address, guint32 session_id, guint16 port)
{
lbtrdma_transport_t * entry;
guint32 keyval[LBTRDMA_KEY_ELEMENT_COUNT];
wmem_tree_key_t tkey[2];
entry = lbtrdma_transport_find(source_address, session_id, port);
if (entry != NULL)
{
return (entry);
}
entry = wmem_new(wmem_file_scope(), lbtrdma_transport_t);
copy_address_wmem(wmem_file_scope(), &(entry->source_address), source_address);
entry->session_id = session_id;
entry->port = port;
entry->channel = lbm_channel_assign(LBM_CHANNEL_TRANSPORT_LBTRDMA);
lbtrdma_transport_build_key(keyval, tkey, entry);
wmem_tree_insert32_array(lbtrdma_transport_table, tkey, (void *) entry);
return (entry);
}
static char * lbtrdma_transport_source_string(const address * source_address _U_, guint32 session_id, guint16 port)
{
return (wmem_strdup_printf(wmem_file_scope(), "LBT-RDMA:%x:%" G_GUINT16_FORMAT, session_id, port));
}
static gboolean lbmr_tag_update_cb(void * record, char * * error_string)
{
lbmr_tag_entry_t * tag = (lbmr_tag_entry_t *)record;
if (tag->name == NULL)
{
*error_string = g_strdup("Tag name can't be empty");
return FALSE;
}
else
{
g_strstrip(tag->name);
if (tag->name[0] == 0)
{
*error_string = g_strdup("Tag name can't be empty");
return FALSE;
}
}
return TRUE;
}
static void * lbmr_tag_copy_cb(void * destination, const void * source, size_t length _U_)
{
const lbmr_tag_entry_t * src = (const lbmr_tag_entry_t *)source;
lbmr_tag_entry_t * dest = (lbmr_tag_entry_t *)destination;
dest->name = g_strdup(src->name);
dest->mc_outgoing_udp_port = src->mc_outgoing_udp_port;
dest->mc_incoming_udp_port = src->mc_incoming_udp_port;
dest->mc_incoming_address = g_strdup(src->mc_incoming_address);
dest->mc_incoming_address_val_h = src->mc_incoming_address_val_h;
dest->mc_outgoing_address = g_strdup(src->mc_outgoing_address);
dest->mc_outgoing_address_val_h = src->mc_outgoing_address_val_h;
dest->uc_port_high = src->uc_port_high;
dest->uc_port_low = src->uc_port_low;
dest->uc_dest_port = src->uc_dest_port;
dest->uc_address = g_strdup(src->uc_address);
dest->uc_address_val_h = src->uc_address_val_h;
return (dest);
}
static void lbmr_tag_free_cb(void * record)
{
lbmr_tag_entry_t * tag = (lbmr_tag_entry_t *)record;
if (tag->name != NULL)
{
g_free(tag->name);
tag->name = NULL;
}
if (tag->mc_incoming_address != NULL)
{
g_free(tag->mc_incoming_address);
tag->mc_incoming_address = NULL;
}
if (tag->mc_outgoing_address != NULL)
{
g_free(tag->mc_outgoing_address);
tag->mc_outgoing_address = NULL;
}
if (tag->uc_address != NULL)
{
g_free(tag->uc_address);
tag->uc_address = NULL;
}
}
static gboolean lbmr_match_packet(packet_info * pinfo, const lbmr_tag_entry_t * entry)
{
guint32 dest_addr_h;
guint32 src_addr_h;
if ((pinfo->dst.type != AT_IPv4) || (pinfo->dst.len != 4) ||
(pinfo->src.type != AT_IPv4) || (pinfo->src.len != 4))
return (FALSE);
dest_addr_h = pntoh32(pinfo->dst.data);
src_addr_h = pntoh32(pinfo->src.data);
if (IN_MULTICAST(dest_addr_h))
{
if ((dest_addr_h != entry->mc_incoming_address_val_h) && (dest_addr_h != entry->mc_outgoing_address_val_h))
{
return (FALSE);
}
if ((dest_addr_h == entry->mc_incoming_address_val_h) && (pinfo->destport != entry->mc_incoming_udp_port))
{
return (FALSE);
}
if ((dest_addr_h == entry->mc_outgoing_address_val_h) && (pinfo->destport != entry->mc_outgoing_udp_port))
{
return (FALSE);
}
return (TRUE);
}
else
{
if ((entry->uc_address_val_h == 0) || (entry->uc_address_val_h == dest_addr_h) || (entry->uc_address_val_h == src_addr_h))
{
if (((pinfo->destport == entry->uc_dest_port) || (pinfo->srcport == entry->uc_dest_port))
&& (((pinfo->destport <= entry->uc_port_high) && (pinfo->destport >= entry->uc_port_low))
|| ((pinfo->srcport <= entry->uc_port_high) && (pinfo->srcport >= entry->uc_port_low))))
{
return (TRUE);
}
}
}
return (FALSE);
}
static char * lbmr_tag_find(packet_info * pinfo)
{
guint idx;
lbmr_tag_entry_t * tag = NULL;
if (!lbmr_use_tag)
{
return (NULL);
}
for (idx = 0; idx < lbmr_tag_count; ++idx)
{
tag = &(lbmr_tag_entry[idx]);
if (lbmr_match_packet(pinfo, tag))
{
return tag->name;
}
}
return (NULL);
}
static void add_contents_tqr(lbmr_contents_t * contents, const char * topic)
{
tqr_node_t * node = NULL;
node = wmem_new(wmem_packet_scope(), tqr_node_t);
node->topic = wmem_strdup(wmem_packet_scope(), topic);
node->next = contents->contents.topic.tqr;
contents->contents.topic.tqr = node;
contents->contents.topic.tqr_count++;
}
static void add_contents_wctqr(lbmr_contents_t * contents, unsigned char type, const char * pattern)
{
wctqr_node_t * node = NULL;
node = wmem_new(wmem_packet_scope(), wctqr_node_t);
node->type = type;
node->pattern = wmem_strdup(wmem_packet_scope(), pattern);
node->next = contents->contents.topic.wctqr;
contents->contents.topic.wctqr = node;
contents->contents.topic.wctqr_count++;
}
static void add_contents_tir(lbmr_contents_t * contents, const char * topic, char * source, guint32 topic_index)
{
tir_node_t * node = NULL;
node = wmem_new(wmem_packet_scope(), tir_node_t);
node->topic = wmem_strdup(wmem_packet_scope(), topic);
node->source_string = source;
node->idx = topic_index;
node->next = contents->contents.topic.tir;
contents->contents.topic.tir = node;
contents->contents.topic.tir_count++;
}
static void add_contents_qqr(lbmr_contents_t * contents, const char * queue)
{
qqr_node_t * node = NULL;
node = wmem_new(wmem_packet_scope(), qqr_node_t);
node->queue = wmem_strdup(wmem_packet_scope(), queue);
node->next = contents->contents.queue.qqr;
contents->contents.queue.qqr = node;
contents->contents.queue.qqr_count++;
}
static void add_contents_qir(lbmr_contents_t * contents, const char * queue, const char * topic, guint16 port)
{
qir_node_t * node = NULL;
node = wmem_new(wmem_packet_scope(), qir_node_t);
node->queue = wmem_strdup(wmem_packet_scope(), queue);
node->topic = wmem_strdup(wmem_packet_scope(), topic);
node->port = port;
node->next = contents->contents.queue.qir;
contents->contents.queue.qir = node;
contents->contents.queue.qir_count++;
}
static void lbmr_topic_ads_topic_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_topic_ads_topic = stats_tree_create_node(tree, lbmr_stat_tree_name_topic_ads_topic, 0, TRUE);
}
static int lbmr_topic_ads_topic_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_topic_advertisement_tap_info_t * info = (const lbm_lbmr_topic_advertisement_tap_info_t *) data;
int topic_node;
int source_node;
gchar * full_source_string;
tick_stat_node(tree, lbmr_stat_tree_name_topic_ads_topic, 0, FALSE);
topic_node = tick_stat_node(tree, info->topic, lbmr_stats_tree_handle_topic_ads_topic, TRUE);
source_node = tick_stat_node(tree, address_to_str(wmem_packet_scope(), &pinfo->net_src), topic_node, TRUE);
full_source_string = wmem_strdup_printf(wmem_packet_scope(), "%s[%" G_GUINT32_FORMAT "]", info->source, info->topic_index);
tick_stat_node(tree, full_source_string, source_node, TRUE);
return (1);
}
static void lbmr_topic_ads_source_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_topic_ads_source = stats_tree_create_node(tree, lbmr_stat_tree_name_topic_ads_source, 0, TRUE);
}
static int lbmr_topic_ads_source_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_topic_advertisement_tap_info_t * info = (const lbm_lbmr_topic_advertisement_tap_info_t *) data;
int source_node;
int topic_node;
gchar * full_source_string;
tick_stat_node(tree, lbmr_stat_tree_name_topic_ads_source, 0, FALSE);
source_node = tick_stat_node(tree, address_to_str(wmem_packet_scope(), &pinfo->net_src), lbmr_stats_tree_handle_topic_ads_source, TRUE);
topic_node = tick_stat_node(tree, info->topic, source_node, TRUE);
full_source_string = wmem_strdup_printf(wmem_packet_scope(), "%s[%" G_GUINT32_FORMAT "]", info->source, info->topic_index);
tick_stat_node(tree, full_source_string, topic_node, TRUE);
return (1);
}
static void lbmr_topic_ads_transport_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_topic_ads_transport = stats_tree_create_node(tree, lbmr_stat_tree_name_topic_ads_transport, 0, TRUE);
}
static int lbmr_topic_ads_transport_stats_tree_packet(stats_tree * tree, packet_info * pinfo _U_, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_topic_advertisement_tap_info_t * info = (const lbm_lbmr_topic_advertisement_tap_info_t *) data;
int transport_node;
gchar * full_source_string;
tick_stat_node(tree, lbmr_stat_tree_name_topic_ads_transport, 0, FALSE);
transport_node = tick_stat_node(tree, info->source, lbmr_stats_tree_handle_topic_ads_transport, TRUE);
full_source_string = wmem_strdup_printf(wmem_packet_scope(), "%s [%" G_GUINT32_FORMAT "]", info->topic, info->topic_index);
tick_stat_node(tree, full_source_string, transport_node, TRUE);
return (1);
}
static void lbmr_topic_queries_topic_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_topic_queries_topic = stats_tree_create_node(tree, lbmr_stat_tree_name_topic_queries_topic, 0, TRUE);
}
static int lbmr_topic_queries_topic_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_topic_query_tap_info_t * info = (const lbm_lbmr_topic_query_tap_info_t *) data;
int topic_node;
tick_stat_node(tree, lbmr_stat_tree_name_topic_queries_topic, 0, FALSE);
topic_node = tick_stat_node(tree, info->topic, lbmr_stats_tree_handle_topic_queries_topic, TRUE);
tick_stat_node(tree, address_to_str(wmem_packet_scope(), &pinfo->net_src), topic_node, TRUE);
return (1);
}
static void lbmr_topic_queries_receiver_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_topic_queries_receiver = stats_tree_create_node(tree, lbmr_stat_tree_name_topic_queries_receiver, 0, TRUE);
}
static int lbmr_topic_queries_receiver_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_topic_query_tap_info_t * info = (const lbm_lbmr_topic_query_tap_info_t *) data;
int receiver_node;
tick_stat_node(tree, lbmr_stat_tree_name_topic_queries_receiver, 0, FALSE);
receiver_node = tick_stat_node(tree, address_to_str(wmem_packet_scope(), &pinfo->net_src), lbmr_stats_tree_handle_topic_queries_receiver, TRUE);
tick_stat_node(tree, info->topic, receiver_node, TRUE);
return (1);
}
static void lbmr_topic_queries_pattern_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_topic_queries_pattern = stats_tree_create_node(tree, lbmr_stat_tree_name_topic_queries_pattern, 0, TRUE);
}
static int lbmr_topic_queries_pattern_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_pattern_query_tap_info_t * info = (const lbm_lbmr_pattern_query_tap_info_t *) data;
int pattern_node;
char * pattern_str;
tick_stat_node(tree, lbmr_stat_tree_name_topic_queries_pattern, 0, FALSE);
pattern_str = wmem_strdup_printf(wmem_packet_scope(), "%s (%s)",
info->pattern,
val_to_str(info->type, lbm_wildcard_pattern_type_short, "UNKN[0x%02x]"));
pattern_node = tick_stat_node(tree, pattern_str, lbmr_stats_tree_handle_topic_queries_pattern, TRUE);
tick_stat_node(tree, address_to_str(wmem_packet_scope(), &pinfo->net_src), pattern_node, TRUE);
return (1);
}
static void lbmr_topic_queries_pattern_receiver_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_topic_queries_pattern_receiver = stats_tree_create_node(tree, lbmr_stat_tree_name_topic_queries_pattern_receiver, 0, TRUE);
}
static int lbmr_topic_queries_pattern_receiver_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_pattern_query_tap_info_t * info = (const lbm_lbmr_pattern_query_tap_info_t *) data;
int receiver_node;
char * pattern_str;
tick_stat_node(tree, lbmr_stat_tree_name_topic_queries_pattern_receiver, 0, FALSE);
receiver_node = tick_stat_node(tree, address_to_str(wmem_packet_scope(), &pinfo->net_src), lbmr_stats_tree_handle_topic_queries_pattern_receiver, TRUE);
pattern_str = wmem_strdup_printf(wmem_packet_scope(), "%s (%s)",
info->pattern,
val_to_str(info->type, lbm_wildcard_pattern_type_short, "UNKN[0x%02x]"));
tick_stat_node(tree, pattern_str, receiver_node, TRUE);
return (1);
}
static void lbmr_queue_ads_queue_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_queue_ads_queue = stats_tree_create_node(tree, lbmr_stat_tree_name_queue_ads_queue, 0, TRUE);
}
static int lbmr_queue_ads_queue_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_queue_advertisement_tap_info_t * info = (const lbm_lbmr_queue_advertisement_tap_info_t *) data;
int queue_node;
gchar * str;
tick_stat_node(tree, lbmr_stat_tree_name_queue_ads_queue, 0, FALSE);
queue_node = tick_stat_node(tree, info->queue, lbmr_stats_tree_handle_queue_ads_queue, TRUE);
str = wmem_strdup_printf(wmem_packet_scope(), "%s:%" G_GUINT16_FORMAT, address_to_str(wmem_packet_scope(), &pinfo->net_src), info->port);
tick_stat_node(tree, str, queue_node, TRUE);
return (1);
}
static void lbmr_queue_ads_source_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_queue_ads_source = stats_tree_create_node(tree, lbmr_stat_tree_name_queue_ads_source, 0, TRUE);
}
static int lbmr_queue_ads_source_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_queue_advertisement_tap_info_t * info = (const lbm_lbmr_queue_advertisement_tap_info_t *) data;
int source_node;
gchar * str;
tick_stat_node(tree, lbmr_stat_tree_name_queue_ads_source, 0, FALSE);
source_node = tick_stat_node(tree, address_to_str(wmem_packet_scope(), &pinfo->net_src), lbmr_stats_tree_handle_queue_ads_source, TRUE);
str = wmem_strdup_printf(wmem_packet_scope(), "%s:%" G_GUINT16_FORMAT, info->queue, info->port);
tick_stat_node(tree, str, source_node, TRUE);
return (1);
}
static void lbmr_queue_queries_queue_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_queue_queries_queue = stats_tree_create_node(tree, lbmr_stat_tree_name_queue_queries_queue, 0, TRUE);
}
static int lbmr_queue_queries_queue_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_queue_query_tap_info_t * info = (const lbm_lbmr_queue_query_tap_info_t *) data;
int queue_node = 0;
tick_stat_node(tree, lbmr_stat_tree_name_queue_queries_queue, 0, FALSE);
queue_node = tick_stat_node(tree, info->queue, lbmr_stats_tree_handle_queue_queries_queue, TRUE);
tick_stat_node(tree, address_to_str(wmem_packet_scope(), &pinfo->net_src), queue_node, TRUE);
return (1);
}
static void lbmr_queue_queries_receiver_stats_tree_init(stats_tree * tree)
{
lbmr_stats_tree_handle_queue_queries_receiver = stats_tree_create_node(tree, lbmr_stat_tree_name_queue_queries_receiver, 0, TRUE);
}
static int lbmr_queue_queries_receiver_stats_tree_packet(stats_tree * tree, packet_info * pinfo, epan_dissect_t * edt _U_, const void * data)
{
const lbm_lbmr_queue_query_tap_info_t * info = (const lbm_lbmr_queue_query_tap_info_t *) data;
int receiver_node;
tick_stat_node(tree, lbmr_stat_tree_name_queue_queries_receiver, 0, FALSE);
receiver_node = tick_stat_node(tree, address_to_str(wmem_packet_scope(), &pinfo->net_src), lbmr_stats_tree_handle_queue_queries_receiver, TRUE);
tick_stat_node(tree, info->queue, receiver_node, TRUE);
return (1);
}
static int dissect_lbmr_tnwg_ctxinst_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * opt_tree = NULL;
proto_item * opt_item = NULL;
guint8 opt_len = 0;
static const int * flags[] =
{
&hf_lbmr_tnwg_opt_ctxinst_flags_ignore,
NULL
};
opt_len = tvb_get_guint8(tvb, offset + O_LBMR_TNWG_OPT_CTXINST_T_LEN);
opt_item = proto_tree_add_item(tree, hf_lbmr_tnwg_opt_ctxinst, tvb, offset, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_tnwg_ctxinst_opt);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_ctxinst_type, tvb, offset + O_LBMR_TNWG_OPT_CTXINST_T_TYPE, L_LBMR_TNWG_OPT_CTXINST_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_ctxinst_len, tvb, offset + O_LBMR_TNWG_OPT_CTXINST_T_LEN, L_LBMR_TNWG_OPT_CTXINST_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, offset + O_LBMR_TNWG_OPT_CTXINST_T_FLAGS, hf_lbmr_tnwg_opt_ctxinst_flags, ett_lbmr_tnwg_ctxinst_opt_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_ctxinst_instance, tvb, offset + O_LBMR_TNWG_OPT_CTXINST_T_INSTANCE, L_LBMR_TNWG_OPT_CTXINST_T_INSTANCE, ENC_NA);
return ((int) opt_len);
}
static int dissect_lbmr_tnwg_address_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * opt_tree = NULL;
proto_item * opt_item = NULL;
guint8 opt_len = 0;
static const int * flags[] =
{
&hf_lbmr_tnwg_opt_address_flags_ignore,
NULL
};
opt_len = tvb_get_guint8(tvb, offset + O_LBMR_TNWG_OPT_ADDRESS_T_LEN);
opt_item = proto_tree_add_item(tree, hf_lbmr_tnwg_opt_address, tvb, offset, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_tnwg_address_opt);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_address_type, tvb, offset + O_LBMR_TNWG_OPT_ADDRESS_T_TYPE, L_LBMR_TNWG_OPT_ADDRESS_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_address_len, tvb, offset + O_LBMR_TNWG_OPT_ADDRESS_T_LEN, L_LBMR_TNWG_OPT_ADDRESS_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, offset + O_LBMR_TNWG_OPT_ADDRESS_T_FLAGS, hf_lbmr_tnwg_opt_address_flags, ett_lbmr_tnwg_address_opt_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_address_port, tvb, offset + O_LBMR_TNWG_OPT_ADDRESS_T_PORT, L_LBMR_TNWG_OPT_ADDRESS_T_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_address_res, tvb, offset + O_LBMR_TNWG_OPT_ADDRESS_T_RES, L_LBMR_TNWG_OPT_ADDRESS_T_RES, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_address_ip, tvb, offset + O_LBMR_TNWG_OPT_ADDRESS_T_IP, L_LBMR_TNWG_OPT_ADDRESS_T_IP, ENC_BIG_ENDIAN);
return ((int)opt_len);
}
static int dissect_lbmr_tnwg_domain_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * opt_tree = NULL;
proto_item * opt_item = NULL;
guint8 opt_len = 0;
static const int * flags[] =
{
&hf_lbmr_tnwg_opt_domain_flags_ignore,
NULL
};
opt_len = tvb_get_guint8(tvb, offset + O_LBMR_TNWG_OPT_DOMAIN_T_LEN);
opt_item = proto_tree_add_item(tree, hf_lbmr_tnwg_opt_domain, tvb, offset, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_tnwg_domain_opt);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_domain_type, tvb, offset + O_LBMR_TNWG_OPT_DOMAIN_T_TYPE, L_LBMR_TNWG_OPT_DOMAIN_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_domain_len, tvb, offset + O_LBMR_TNWG_OPT_DOMAIN_T_LEN, L_LBMR_TNWG_OPT_DOMAIN_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, offset + O_LBMR_TNWG_OPT_DOMAIN_T_FLAGS, hf_lbmr_tnwg_opt_domain_flags, ett_lbmr_tnwg_domain_opt_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_domain_domain_id, tvb, offset + O_LBMR_TNWG_OPT_DOMAIN_T_DOMAIN_ID, L_LBMR_TNWG_OPT_DOMAIN_T_DOMAIN_ID, ENC_BIG_ENDIAN);
return ((int)opt_len);
}
static int dissect_lbmr_tnwg_name_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * opt_tree = NULL;
proto_item * opt_item = NULL;
guint8 opt_len = 0;
static const int * flags[] =
{
&hf_lbmr_tnwg_opt_name_flags_ignore,
NULL
};
guint32 name_len = 0;
opt_len = tvb_get_guint8(tvb, offset + O_LBMR_TNWG_OPT_T_LEN);
name_len = opt_len - L_LBMR_TNWG_OPT_T;
opt_item = proto_tree_add_item(tree, hf_lbmr_tnwg_opt_name, tvb, offset, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_tnwg_name_opt);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_name_type, tvb, offset + O_LBMR_TNWG_OPT_T_TYPE, L_LBMR_TNWG_OPT_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_name_len, tvb, offset + O_LBMR_TNWG_OPT_T_LEN, L_LBMR_TNWG_OPT_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, offset + O_LBMR_TNWG_OPT_T_FLAGS, hf_lbmr_tnwg_opt_name_flags, ett_lbmr_tnwg_name_opt_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_name_name, tvb, offset + L_LBMR_TNWG_OPT_T, name_len, ENC_ASCII|ENC_NA);
return ((int)opt_len);
}
static int dissect_lbmr_tnwg_unknown_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * opt_tree = NULL;
proto_item * opt_item = NULL;
guint8 opt_len = 0;
static const int * flags[] =
{
&hf_lbmr_tnwg_opt_flags_ignore,
NULL
};
guint32 data_len = 0;
opt_len = tvb_get_guint8(tvb, offset + O_LBMR_TNWG_OPT_T_LEN);
data_len = opt_len - L_LBMR_TNWG_OPT_T;
opt_item = proto_tree_add_item(tree, hf_lbmr_tnwg_opt, tvb, offset, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_tnwg_unknown_opt);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_type, tvb, offset + O_LBMR_TNWG_OPT_T_TYPE, L_LBMR_TNWG_OPT_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_len, tvb, offset + O_LBMR_TNWG_OPT_T_LEN, L_LBMR_TNWG_OPT_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, offset + O_LBMR_TNWG_OPT_T_FLAGS, hf_lbmr_tnwg_opt_flags, ett_lbmr_tnwg_unknown_opt_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_tnwg_opt_data, tvb, offset + L_LBMR_TNWG_OPT_T, data_len, ENC_NA);
return ((int)opt_len);
}
static int dissect_lbmr_tnwg_opts(tvbuff_t * tvb, int offset, int length, packet_info * pinfo, proto_tree * tree)
{
int len_remaining = length;
int curr_offset = offset;
int dissected_len = 0;
guint8 type = 0;
int len_used = 0;
while (len_remaining >= L_LBMR_TNWG_OPT_T)
{
type = tvb_get_guint8(tvb, curr_offset);
switch (type)
{
case LBMR_TNWG_OPT_CTXINST_TYPE:
dissected_len += dissect_lbmr_tnwg_ctxinst_opt(tvb, curr_offset, pinfo, tree);
break;
case LBMR_TNWG_OPT_ADDRESS_TYPE:
dissected_len += dissect_lbmr_tnwg_address_opt(tvb, curr_offset, pinfo, tree);
break;
case LBMR_TNWG_OPT_DOMAIN_TYPE:
dissected_len += dissect_lbmr_tnwg_domain_opt(tvb, curr_offset, pinfo, tree);
break;
case LBMR_TNWG_OPT_NAME_TYPE:
dissected_len += dissect_lbmr_tnwg_name_opt(tvb, curr_offset, pinfo, tree);
break;
default:
dissected_len += dissect_lbmr_tnwg_unknown_opt(tvb, curr_offset, pinfo, tree);
break;
}
len_remaining -= dissected_len;
len_used += dissected_len;
curr_offset += dissected_len;
}
return (len_used);
}
static int dissect_lbmr_tnwg_interest_rec(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * rec_tree = NULL;
proto_item * rec_item = NULL;
guint16 rec_len = 0;
gint string_len = 0;
static const int * flags[] =
{
&hf_lbmr_tnwg_interest_rec_flags_pattern,
&hf_lbmr_tnwg_interest_rec_flags_cancel,
&hf_lbmr_tnwg_interest_rec_flags_refresh,
NULL
};
rec_len = tvb_get_ntohs(tvb, offset + O_LBMR_TNWG_INTEREST_REC_T_LEN);
rec_item = proto_tree_add_item(tree, hf_lbmr_tnwg_interest_rec, tvb, offset, rec_len, ENC_NA);
rec_tree = proto_item_add_subtree(rec_item, ett_lbmr_tnwg_interest_rec);
proto_tree_add_item(rec_tree, hf_lbmr_tnwg_interest_rec_len, tvb, offset + O_LBMR_TNWG_INTEREST_REC_T_LEN, L_LBMR_TNWG_INTEREST_REC_T_LEN, ENC_BIG_ENDIAN);
if (rec_len < L_LBMR_TNWG_INTEREST_REC_T)
{
return ((int)rec_len);
}
proto_tree_add_bitmask(rec_tree, tvb, offset + O_LBMR_TNWG_INTEREST_REC_T_FLAGS, hf_lbmr_tnwg_interest_rec_flags, ett_lbmr_tnwg_interest_rec_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(rec_tree, hf_lbmr_tnwg_interest_rec_pattype, tvb, offset + O_LBMR_TNWG_INTEREST_REC_T_PATTYPE, L_LBMR_TNWG_INTEREST_REC_T_PATTYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(rec_tree, hf_lbmr_tnwg_interest_rec_domain_id, tvb, offset + O_LBMR_TNWG_INTEREST_REC_T_DOMAIN_ID, L_LBMR_TNWG_INTEREST_REC_T_DOMAIN_ID, ENC_BIG_ENDIAN);
string_len = rec_len - L_LBMR_TNWG_INTEREST_REC_T;
proto_tree_add_item(rec_tree, hf_lbmr_tnwg_interest_rec_symbol, tvb, offset + L_LBMR_TNWG_INTEREST_REC_T, string_len, ENC_ASCII|ENC_NA);
return ((int)rec_len);
}
static int dissect_lbmr_tnwg_interest(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
proto_tree * int_tree = NULL;
proto_item * int_item = NULL;
guint16 rec_count = 0;
int curr_offset = 0;
int len = 0;
int len_remaining = 0;
int len_dissected = 0;
len_remaining = tvb_get_ntohs(tvb, offset + O_LBMR_TNWG_INTEREST_T_LEN);
rec_count = tvb_get_ntohs(tvb, offset + O_LBMR_TNWG_INTEREST_T_COUNT);
int_item = proto_tree_add_item(tree, hf_lbmr_tnwg_interest, tvb, offset, len_remaining, ENC_NA);
int_tree = proto_item_add_subtree(int_item, ett_lbmr_tnwg_interest);
proto_tree_add_item(int_tree, hf_lbmr_tnwg_interest_len, tvb, offset + O_LBMR_TNWG_INTEREST_T_LEN, L_LBMR_TNWG_INTEREST_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(int_tree, hf_lbmr_tnwg_interest_count, tvb, offset + O_LBMR_TNWG_INTEREST_T_COUNT, L_LBMR_TNWG_INTEREST_T_COUNT, ENC_BIG_ENDIAN);
curr_offset = offset + L_LBMR_TNWG_INTEREST_T;
len = L_LBMR_TNWG_INTEREST_T;
while (rec_count > 0)
{
len_dissected = dissect_lbmr_tnwg_interest_rec(tvb, curr_offset, pinfo, int_tree);
curr_offset += len_dissected;
len += len_dissected;
rec_count--;
}
return (len);
}
static int dissect_lbmr_tnwg_ctxinfo(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
proto_tree * ctxinfo_tree = NULL;
proto_item * ctxinfo_item = NULL;
static const int * flags1[] =
{
&hf_lbmr_tnwg_ctxinfo_flags1_query,
&hf_lbmr_tnwg_ctxinfo_flags1_tnwg_src,
&hf_lbmr_tnwg_ctxinfo_flags1_tnwg_rcv,
&hf_lbmr_tnwg_ctxinfo_flags1_proxy,
NULL
};
guint16 reclen = 0;
guint16 len_remaining = 0;
int len_used = 0;
reclen = tvb_get_ntohs(tvb, offset + O_LBMR_TNWG_CTXINFO_T_LEN);
len_remaining = reclen;
ctxinfo_item = proto_tree_add_item(tree, hf_lbmr_tnwg_ctxinfo, tvb, offset, (gint)reclen, ENC_NA);
ctxinfo_tree = proto_item_add_subtree(ctxinfo_item, ett_lbmr_tnwg_ctxinfo);
proto_tree_add_item(ctxinfo_tree, hf_lbmr_tnwg_ctxinfo_len, tvb, offset + O_LBMR_TNWG_CTXINFO_T_LEN, L_LBMR_TNWG_CTXINFO_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(ctxinfo_tree, hf_lbmr_tnwg_ctxinfo_hop_count, tvb, offset + O_LBMR_TNWG_CTXINFO_T_HOP_COUNT, L_LBMR_TNWG_CTXINFO_T_HOP_COUNT, ENC_BIG_ENDIAN);
proto_tree_add_item(ctxinfo_tree, hf_lbmr_tnwg_ctxinfo_reserved, tvb, offset + O_LBMR_TNWG_CTXINFO_T_RESERVED, L_LBMR_TNWG_CTXINFO_T_RESERVED, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(ctxinfo_tree, tvb, offset + O_LBMR_TNWG_CTXINFO_T_FLAGS1, hf_lbmr_tnwg_ctxinfo_flags1, ett_lbmr_tnwg_ctxinfo_flags1, flags1, ENC_BIG_ENDIAN);
proto_tree_add_item(ctxinfo_tree, hf_lbmr_tnwg_ctxinfo_flags2, tvb, offset + O_LBMR_TNWG_CTXINFO_T_FLAGS2, L_LBMR_TNWG_CTXINFO_T_FLAGS2, ENC_BIG_ENDIAN);
offset += L_LBMR_TNWG_CTXINFO_T;
len_remaining -= L_LBMR_TNWG_CTXINFO_T;
len_used = L_LBMR_TNWG_CTXINFO_T;
if (len_remaining >= L_LBMR_TNWG_OPT_T)
{
len_used += dissect_lbmr_tnwg_opts(tvb, offset, len_remaining, pinfo, ctxinfo_tree);
}
return (len_used);
}
static int dissect_lbmr_tnwg_trreq(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
proto_tree * trreq_tree = NULL;
proto_item * trreq_item = NULL;
guint16 reclen = 0;
guint16 len_remaining = 0;
int len_used = 0;
reclen = tvb_get_ntohs(tvb, offset + O_LBMR_TNWG_TRREQ_T_LEN);
len_remaining = reclen;
trreq_item = proto_tree_add_item(tree, hf_lbmr_tnwg_trreq, tvb, offset, (gint)reclen, ENC_NA);
trreq_tree = proto_item_add_subtree(trreq_item, ett_lbmr_tnwg_trreq);
proto_tree_add_item(trreq_tree, hf_lbmr_tnwg_trreq_len, tvb, offset + O_LBMR_TNWG_TRREQ_T_LEN, L_LBMR_TNWG_TRREQ_T_LEN, ENC_BIG_ENDIAN);
offset += L_LBMR_TNWG_TRREQ_T;
len_remaining -= L_LBMR_TNWG_TRREQ_T;
len_used = L_LBMR_TNWG_TRREQ_T;
if (len_remaining >= L_LBMR_TNWG_OPT_T)
{
len_used += dissect_lbmr_tnwg_opts(tvb, offset, len_remaining, pinfo, trreq_tree);
}
return (len_used);
}
static int dissect_lbmr_tnwg(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 type = 0;
int curr_offset = 0;
int len_dissected = 0;
proto_item * type_item = NULL;
type = tvb_get_ntohs(tvb, offset + O_LBMR_TNWG_T_TYPE);
proto_tree_add_item(tree, hf_lbmr_tnwg_len, tvb, offset + O_LBMR_TNWG_T_LEN, L_LBMR_TNWG_T_LEN, ENC_BIG_ENDIAN);
type_item = proto_tree_add_item(tree, hf_lbmr_tnwg_type, tvb, offset + O_LBMR_TNWG_T_TYPE, L_LBMR_TNWG_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_tnwg_reserved, tvb, offset + O_LBMR_TNWG_T_RESERVED, L_LBMR_TNWG_T_RESERVED, ENC_BIG_ENDIAN);
len_dissected = L_LBMR_TNWG_T;
curr_offset = offset + L_LBMR_TNWG_T;
switch (type)
{
case LBMR_TNWG_TYPE_INTEREST:
len_dissected += dissect_lbmr_tnwg_interest(tvb, curr_offset, pinfo, tree);
break;
case LBMR_TNWG_TYPE_CTXINFO:
len_dissected += dissect_lbmr_tnwg_ctxinfo(tvb, curr_offset, pinfo, tree);
break;
case LBMR_TNWG_TYPE_TRREQ:
len_dissected += dissect_lbmr_tnwg_trreq(tvb, curr_offset, pinfo, tree);
break;
default:
expert_add_info_format(pinfo, type_item, &ei_lbmr_analysis_invalid_value, "Unknown LBMR TNWG type 0x%04x", type);
break;
}
return ((int)len_dissected);
}
static int dissect_lbmr_tmr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
gint namelen = 0;
int name_offset = 0;
char * name = NULL;
proto_item * ti = NULL;
proto_tree * tinfo_tree = NULL;
static const int * flags[] =
{
&hf_lbmr_tmr_flags_response,
&hf_lbmr_tmr_flags_wildcard_pcre,
&hf_lbmr_tmr_flags_wildcard_regex,
NULL
};
guint16 tmr_len;
guint8 tmr_type;
guint8 tmr_flags;
const char * info_string = "";
tmr_len = tvb_get_ntohs(tvb, offset + O_LBMR_TMR_T_LEN);
tmr_type = tvb_get_guint8(tvb, offset + O_LBMR_TMR_T_TYPE);
tmr_flags = tvb_get_guint8(tvb, offset + O_LBMR_TMR_T_FLAGS);
name_offset = offset + L_LBMR_TMR_T;
name = tvb_get_stringz_enc(wmem_packet_scope(), tvb, name_offset, &namelen, ENC_ASCII);
switch (tmr_type)
{
case LBMR_TMR_LEAVE_TOPIC:
default:
break;
case LBMR_TMR_TOPIC_USE:
if (tmr_flags & LBMR_TMR_FLAG_RESPONSE)
{
info_string = " Response";
}
else
{
info_string = " Query";
}
break;
}
ti = proto_tree_add_none_format(tree, hf_lbmr_tmr, tvb, offset, tmr_len, "%s: %s%s, Length %" G_GUINT16_FORMAT,
name, val_to_str(tmr_type, lbmr_tmr_type, "Unknown (0x%02x)"), info_string, tmr_len);
tinfo_tree = proto_item_add_subtree(ti, ett_lbmr_tmr);
proto_tree_add_item(tinfo_tree, hf_lbmr_tmr_len, tvb, offset + O_LBMR_TMR_T_LEN, L_LBMR_TMR_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(tinfo_tree, hf_lbmr_tmr_type, tvb, offset + O_LBMR_TMR_T_TYPE, L_LBMR_TMR_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tinfo_tree, tvb, offset + O_LBMR_TMR_T_FLAGS, hf_lbmr_tmr_flags, ett_lbmr_tmr_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(tinfo_tree, hf_lbmr_tmr_name, tvb, name_offset, namelen, ENC_ASCII|ENC_NA);
return ((int) tmr_len);
}
static int dissect_lbmr_tmb(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
int tmr_len = 0;
proto_tree * tmb_tree = NULL;
proto_item * ti = NULL;
proto_tree * tmr_tree = NULL;
proto_item * tmr_ti = NULL;
int tmr_count = 0;
guint16 tmrs;
int len_dissected;
tmrs = tvb_get_ntohs(tvb, offset + O_LBMR_TMB_T_TMRS);
ti = proto_tree_add_item(tree, hf_lbmr_tmb, tvb, offset, -1, ENC_NA);
tmb_tree = proto_item_add_subtree(ti, ett_lbmr_tmb);
proto_tree_add_item(tmb_tree, hf_lbmr_tmb_len, tvb, offset + O_LBMR_TMB_T_LEN, L_LBMR_TMB_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(tmb_tree, hf_lbmr_tmb_tmrs, tvb, offset + O_LBMR_TMB_T_TMRS, L_LBMR_TMB_T_TMRS, ENC_BIG_ENDIAN);
tmr_ti = proto_tree_add_item(tmb_tree, hf_lbmr_tmb_tmr_list, tvb, offset + L_LBMR_TMB_T, -1, ENC_NA);
tmr_tree = proto_item_add_subtree(tmr_ti, ett_lbmr_tmrs);
offset += L_LBMR_TMB_T;
len_dissected = L_LBMR_TMB_T;
while (tmr_count < tmrs)
{
tmr_len = dissect_lbmr_tmr(tvb, offset, pinfo, tmr_tree);
len_dissected += tmr_len;
offset += tmr_len;
tmr_count++;
}
return (len_dissected);
}
static int dissect_lbmr_tqr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree, gboolean wildcard_tqr, lbmr_contents_t * contents)
{
gint namelen = 0;
guint reclen = 0;
char * name = NULL;
guint8 pattern_type;
proto_item * tqr_item = NULL;
proto_tree * tqr_tree = NULL;
gint name_offset = offset;
if (wildcard_tqr)
{
pattern_type = tvb_get_guint8(tvb, offset);
name_offset++;
reclen++;
}
name = tvb_get_stringz_enc(wmem_packet_scope(), tvb, name_offset, &namelen, ENC_ASCII);
reclen += namelen;
if (wildcard_tqr)
{
tqr_item = proto_tree_add_none_format(tree, hf_lbmr_tqr, tvb, offset, reclen, "Wildcard TQR: %s", name);
}
else
{
tqr_item = proto_tree_add_none_format(tree, hf_lbmr_tqr, tvb, offset, reclen, "TQR: %s", name);
}
tqr_tree = proto_item_add_subtree(tqr_item, ett_lbmr_tqr);
if (wildcard_tqr)
{
proto_tree_add_item(tqr_tree, hf_lbmr_tqr_pattern_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tqr_tree, hf_lbmr_tqr_pattern, tvb, offset, namelen, ENC_ASCII|ENC_NA);
add_contents_wctqr(contents, pattern_type, name);
}
else
{
proto_tree_add_item(tqr_tree, hf_lbmr_tqr_name, tvb, offset, namelen, ENC_ASCII|ENC_NA);
add_contents_tqr(contents, name);
}
return (reclen);
}
static int dissect_lbmr_tqrs(tvbuff_t * tvb, int offset, guint8 tqr_count, packet_info * pinfo, proto_tree * tree,
gboolean wildcard_tqr, lbmr_contents_t * contents)
{
int start_offset = 0;
int tqr_len = 0;
proto_tree * tqrs_tree = NULL;
proto_item * ti = NULL;
int len = 0;
start_offset = offset;
if (wildcard_tqr)
{
ti = proto_tree_add_none_format(tree, hf_lbmr_tqrs, tvb, start_offset, -1, "Wildcard TQRs");
}
else
{
ti = proto_tree_add_none_format(tree, hf_lbmr_tqrs, tvb, start_offset, -1, "TQRs");
}
tqrs_tree = proto_item_add_subtree(ti, ett_lbmr_tqrs);
while (tqr_count-- > 0)
{
tqr_len = dissect_lbmr_tqr(tvb, offset, pinfo, tqrs_tree, wildcard_tqr, contents);
len += tqr_len;
offset += tqr_len;
}
proto_item_set_len(ti, len);
return (len);
}
static int dissect_lbmr_tir_options(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint8 opt_type = 0;
guint8 opt_len = 0;
int opt_total_len = 0;
int opt_remaining_len = 0;
int curr_offset = offset;
proto_item * oi = NULL;
proto_tree * otree = NULL;
proto_item * optlen_item = NULL;
proto_tree * optlen_tree = NULL;
static const int * opt_ume_flags[] =
{
&hf_lbmr_topt_ume_flags_ignore,
&hf_lbmr_topt_ume_flags_latejoin,
&hf_lbmr_topt_ume_flags_store,
&hf_lbmr_topt_ume_flags_qccap,
&hf_lbmr_topt_ume_flags_acktosrc,
NULL
};
static const int * opt_ume_store_flags[] =
{
&hf_lbmr_topt_ume_store_flags_ignore,
NULL
};
static const int * opt_ume_store_group_flags[] =
{
&hf_lbmr_topt_ume_store_group_flags_ignore,
NULL
};
static const int * opt_latejoin_flags[] =
{
&hf_lbmr_topt_latejoin_flags_ignore,
&hf_lbmr_topt_latejoin_flags_acktosrc,
NULL
};
static const int * opt_umq_rcridx_flags[] =
{
&hf_lbmr_topt_umq_rcridx_flags_ignore,
NULL
};
static const int * opt_umq_qinfo_flags[] =
{
&hf_lbmr_topt_umq_qinfo_flags_ignore,
&hf_lbmr_topt_umq_qinfo_flags_queue,
&hf_lbmr_topt_umq_qinfo_flags_rcvlisten,
&hf_lbmr_topt_umq_qinfo_flags_control,
&hf_lbmr_topt_umq_qinfo_flags_srcrcvlisten,
&hf_lbmr_topt_umq_qinfo_flags_participants_only,
NULL
};
static const int * opt_cost_flags[] =
{
&hf_lbmr_topt_cost_flags_ignore,
NULL
};
static const int * opt_otid_flags[] =
{
&hf_lbmr_topt_otid_flags_ignore,
NULL
};
static const int * opt_ctxinst_flags[] =
{
&hf_lbmr_topt_ctxinst_flags_ignore,
NULL
};
static const int * opt_ctxinsts_flags[] =
{
&hf_lbmr_topt_ctxinsts_flags_ignore,
NULL
};
static const int * opt_ulb_flags[] =
{
&hf_lbmr_topt_ulb_flags_ignore,
NULL
};
static const int * opt_ctxinstq_flags[] =
{
&hf_lbmr_topt_ctxinstq_flags_ignore,
NULL
};
static const int * opt_domain_id_flags[] =
{
&hf_lbmr_topt_domain_id_flags_ignore,
NULL
};
static const int * opt_exfunc_flags[] =
{
&hf_lbmr_topt_exfunc_flags_ignore,
NULL
};
static const int * opt_exfunc_functionality_flags[] =
{
&hf_lbmr_topt_exfunc_functionality_flags_ulb,
&hf_lbmr_topt_exfunc_functionality_flags_umq,
&hf_lbmr_topt_exfunc_functionality_flags_ume,
&hf_lbmr_topt_exfunc_functionality_flags_lj,
NULL
};
int len = 0;
opt_total_len = (int)tvb_get_ntohs(tvb, curr_offset + O_LBMR_TOPIC_OPT_LEN_T_TOTAL_LEN);
opt_remaining_len = opt_total_len;
oi = proto_tree_add_none_format(tree, hf_lbmr_topts, tvb, curr_offset, opt_total_len, "Options: %d bytes", opt_total_len);
otree = proto_item_add_subtree(oi, ett_lbmr_topts);
optlen_item = proto_tree_add_item(otree, hf_lbmr_topt_len, tvb, curr_offset, L_LBMR_TOPIC_OPT_LEN_T, ENC_NA);
optlen_tree = proto_item_add_subtree(optlen_item, ett_lbmr_topt_len);
proto_tree_add_item(optlen_tree, hf_lbmr_topt_len_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_LEN_T_TYPE, L_LBMR_TOPIC_OPT_LEN_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(optlen_tree, hf_lbmr_topt_len_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_LEN_T_LEN, L_LBMR_TOPIC_OPT_LEN_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(optlen_tree, hf_lbmr_topt_len_total_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_LEN_T_TOTAL_LEN, L_LBMR_TOPIC_OPT_LEN_T_TOTAL_LEN, ENC_BIG_ENDIAN);
len = L_LBMR_TOPIC_OPT_LEN_T;
curr_offset += L_LBMR_TOPIC_OPT_LEN_T;
opt_remaining_len -= L_LBMR_TOPIC_OPT_LEN_T;
while (opt_remaining_len > 0)
{
proto_item * opt_item = NULL;
proto_tree * opt_tree = NULL;
proto_item * ei_item = NULL;
int qname_len;
opt_type = tvb_get_guint8(tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE);
opt_len = tvb_get_guint8(tvb, curr_offset + O_LBMR_TOPIC_OPT_T_LEN);
if (opt_len == 0)
{
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_unknown, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_unknown);
proto_tree_add_item(opt_tree, hf_lbmr_topt_unknown_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, L_LBMR_TOPIC_OPT_T_TYPE, ENC_BIG_ENDIAN);
ei_item = proto_tree_add_item(opt_tree, hf_lbmr_topt_unknown_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_LEN, L_LBMR_TOPIC_OPT_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_unknown_flags, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_FLAGS, L_LBMR_TOPIC_OPT_T_FLAGS, ENC_BIG_ENDIAN);
if (((int) opt_len) > L_LBMR_TOPIC_OPT_T)
{
proto_tree_add_item(opt_tree, hf_lbmr_topt_unknown_data, tvb, curr_offset + L_LBMR_TOPIC_OPT_T, ((int) opt_len) - L_LBMR_TOPIC_OPT_T, ENC_NA);
}
expert_add_info_format(pinfo, ei_item, &ei_lbmr_analysis_zero_len_option, "Zero-length LBMR option");
return (len);
}
switch (opt_type)
{
case LBMR_TOPIC_OPT_UME_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_ume, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_ume);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_TYPE, L_LBMR_TOPIC_OPT_UME_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_LEN, L_LBMR_TOPIC_OPT_UME_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_FLAGS, hf_lbmr_topt_ume_flags, ett_lbmr_topt_ume_flags, opt_ume_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_tcp_port, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_STORE_TCP_PORT, L_LBMR_TOPIC_OPT_UME_T_STORE_TCP_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_src_tcp_port, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_SRC_TCP_PORT, L_LBMR_TOPIC_OPT_UME_T_SRC_TCP_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_tcp_addr, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_STORE_TCP_ADDR, L_LBMR_TOPIC_OPT_UME_T_STORE_TCP_ADDR, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_src_tcp_addr, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_SRC_TCP_ADDR, L_LBMR_TOPIC_OPT_UME_T_SRC_TCP_ADDR, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_src_reg_id, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_SRC_REG_ID, L_LBMR_TOPIC_OPT_UME_T_SRC_REG_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_transport_idx, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_TRANSPORT_IDX, L_LBMR_TOPIC_OPT_UME_T_TRANSPORT_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_high_seqnum, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_HIGH_SEQNUM, L_LBMR_TOPIC_OPT_UME_T_HIGH_SEQNUM, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_low_seqnum, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_T_LOW_SEQNUM, L_LBMR_TOPIC_OPT_UME_T_LOW_SEQNUM, ENC_BIG_ENDIAN);
break;
case LBMR_TOPIC_OPT_UME_STORE_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_ume_store, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_ume_store);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_T_TYPE, L_LBMR_TOPIC_OPT_UME_STORE_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_T_LEN, L_LBMR_TOPIC_OPT_UME_STORE_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_T_FLAGS, hf_lbmr_topt_ume_store_flags, ett_lbmr_topt_ume_store_flags, opt_ume_store_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_grp_idx, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_T_GRP_IDX, L_LBMR_TOPIC_OPT_UME_STORE_T_GRP_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_store_tcp_port, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_T_STORE_TCP_PORT, L_LBMR_TOPIC_OPT_UME_STORE_T_STORE_TCP_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_store_idx, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_T_STORE_IDX, L_LBMR_TOPIC_OPT_UME_STORE_T_STORE_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_store_ip_addr, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_T_STORE_IP_ADDR, L_LBMR_TOPIC_OPT_UME_STORE_T_STORE_IP_ADDR, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_src_reg_id, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_T_SRC_REG_ID, L_LBMR_TOPIC_OPT_UME_STORE_T_SRC_REG_ID, ENC_BIG_ENDIAN);
break;
case LBMR_TOPIC_OPT_UME_STORE_GROUP_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_ume_store_group, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_ume_store_group);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_group_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_TYPE, L_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_group_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_LEN, L_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_FLAGS, hf_lbmr_topt_ume_store_group_flags, ett_lbmr_topt_ume_store_group_flags, opt_ume_store_group_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_group_grp_idx, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_GRP_IDX, L_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_GRP_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_group_grp_sz, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_GRP_SZ, L_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_GRP_SZ, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ume_store_group_reserved, tvb, curr_offset + O_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_RESERVED, L_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_RESERVED, ENC_BIG_ENDIAN);
break;
case LBMR_TOPIC_OPT_LATEJOIN_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_latejoin, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_latejoin);
proto_tree_add_item(opt_tree, hf_lbmr_topt_latejoin_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_LATEJOIN_T_TYPE, L_LBMR_TOPIC_OPT_LATEJOIN_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_latejoin_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_LATEJOIN_T_LEN, L_LBMR_TOPIC_OPT_LATEJOIN_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_LATEJOIN_T_FLAGS, hf_lbmr_topt_latejoin_flags, ett_lbmr_topt_latejoin_flags, opt_latejoin_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_latejoin_src_tcp_port, tvb, curr_offset + O_LBMR_TOPIC_OPT_LATEJOIN_T_SRC_TCP_PORT, L_LBMR_TOPIC_OPT_LATEJOIN_T_SRC_TCP_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_latejoin_reserved, tvb, curr_offset + O_LBMR_TOPIC_OPT_LATEJOIN_T_RESERVED, L_LBMR_TOPIC_OPT_LATEJOIN_T_RESERVED, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_latejoin_src_ip_addr, tvb, curr_offset + O_LBMR_TOPIC_OPT_LATEJOIN_T_SRC_IP_ADDR, L_LBMR_TOPIC_OPT_LATEJOIN_T_SRC_IP_ADDR, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_latejoin_transport_idx, tvb, curr_offset + O_LBMR_TOPIC_OPT_LATEJOIN_T_TRANSPORT_IDX, L_LBMR_TOPIC_OPT_LATEJOIN_T_TRANSPORT_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_latejoin_high_seqnum, tvb, curr_offset + O_LBMR_TOPIC_OPT_LATEJOIN_T_HIGH_SEQNUM, L_LBMR_TOPIC_OPT_LATEJOIN_T_HIGH_SEQNUM, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_latejoin_low_seqnum, tvb, curr_offset + O_LBMR_TOPIC_OPT_LATEJOIN_T_LOW_SEQNUM, L_LBMR_TOPIC_OPT_LATEJOIN_T_LOW_SEQNUM, ENC_BIG_ENDIAN);
break;
case LBMR_TOPIC_OPT_UMQ_RCRIDX_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_umq_rcridx, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_umq_rcridx);
proto_tree_add_item(opt_tree, hf_lbmr_topt_umq_rcridx_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_UMQ_RCRIDX_T_TYPE, L_LBMR_TOPIC_OPT_UMQ_RCRIDX_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_umq_rcridx_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_UMQ_RCRIDX_T_LEN, L_LBMR_TOPIC_OPT_UMQ_RCRIDX_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_UMQ_RCRIDX_T_FLAGS, hf_lbmr_topt_umq_rcridx_flags, ett_lbmr_topt_umq_rcridx_flags, opt_umq_rcridx_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_umq_rcridx_rcr_idx, tvb, curr_offset + O_LBMR_TOPIC_OPT_UMQ_RCRIDX_T_RCR_IDX, L_LBMR_TOPIC_OPT_UMQ_RCRIDX_T_RCR_IDX, ENC_BIG_ENDIAN);
break;
case LBMR_TOPIC_OPT_UMQ_QINFO_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_umq_qinfo, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_umq_qinfo);
proto_tree_add_item(opt_tree, hf_lbmr_topt_umq_qinfo_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, L_LBMR_TOPIC_OPT_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_umq_qinfo_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_LEN, L_LBMR_TOPIC_OPT_T_LEN, ENC_BIG_ENDIAN);
qname_len = opt_len - L_LBMR_TOPIC_OPT_T;
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_FLAGS, hf_lbmr_topt_umq_qinfo_flags, ett_lbmr_topt_umq_qinfo_flags, opt_umq_qinfo_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_umq_qinfo_queue, tvb, curr_offset + L_LBMR_TOPIC_OPT_T, qname_len, ENC_ASCII|ENC_NA);
break;
case LBMR_TOPIC_OPT_COST_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_cost, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_cost);
proto_tree_add_item(opt_tree, hf_lbmr_topt_cost_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_COST_T_TYPE, L_LBMR_TOPIC_OPT_COST_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_cost_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_COST_T_LEN, L_LBMR_TOPIC_OPT_COST_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_COST_T_FLAGS, hf_lbmr_topt_cost_flags, ett_lbmr_topt_cost_flags, opt_cost_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_cost_hop_count, tvb, curr_offset + O_LBMR_TOPIC_OPT_COST_T_HOP_COUNT, L_LBMR_TOPIC_OPT_COST_T_HOP_COUNT, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_cost_cost, tvb, curr_offset + O_LBMR_TOPIC_OPT_COST_T_COST, L_LBMR_TOPIC_OPT_COST_T_COST, ENC_BIG_ENDIAN);
break;
case LBMR_TOPIC_OPT_OTID_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_otid, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_otid);
proto_tree_add_item(opt_tree, hf_lbmr_topt_otid_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_OTID_T_TYPE, L_LBMR_TOPIC_OPT_OTID_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_otid_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_OTID_T_LEN, L_LBMR_TOPIC_OPT_OTID_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_OTID_T_FLAGS, hf_lbmr_topt_otid_flags, ett_lbmr_topt_otid_flags, opt_otid_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_otid_originating_transport, tvb, curr_offset + O_LBMR_TOPIC_OPT_OTID_T_ORIGINATING_TRANSPORT, L_LBMR_TOPIC_OPT_OTID_T_ORIGINATING_TRANSPORT, ENC_NA);
break;
case LBMR_TOPIC_OPT_CTXINST_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_ctxinst, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_ctxinst);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinst_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINST_T_TYPE, L_LBMR_TOPIC_OPT_CTXINST_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinst_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINST_T_LEN, L_LBMR_TOPIC_OPT_CTXINST_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINST_T_FLAGS, hf_lbmr_topt_ctxinst_flags, ett_lbmr_topt_ctxinst_flags, opt_ctxinst_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinst_res, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINST_T_RES, L_LBMR_TOPIC_OPT_CTXINST_T_RES, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinst_ctxinst, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINST_T_CTXINST, L_LBMR_TOPIC_OPT_CTXINST_T_CTXINST, ENC_NA);
break;
case LBMR_TOPIC_OPT_CTXINSTS_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_ctxinsts, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_ctxinsts);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinsts_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTS_T_TYPE, L_LBMR_TOPIC_OPT_CTXINSTS_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinsts_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTS_T_LEN, L_LBMR_TOPIC_OPT_CTXINSTS_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTS_T_FLAGS, hf_lbmr_topt_ctxinsts_flags, ett_lbmr_topt_ctxinsts_flags, opt_ctxinsts_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinsts_idx, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTS_T_IDX, L_LBMR_TOPIC_OPT_CTXINSTS_T_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinsts_ctxinst, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTS_T_CTXINST, L_LBMR_TOPIC_OPT_CTXINSTS_T_CTXINST, ENC_NA);
break;
case LBMR_TOPIC_OPT_ULB_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_ulb, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_ulb);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ulb_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_ULB_T_TYPE, L_LBMR_TOPIC_OPT_ULB_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ulb_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_ULB_T_LEN, L_LBMR_TOPIC_OPT_ULB_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_ULB_T_FLAGS, hf_lbmr_topt_ulb_flags, ett_lbmr_topt_ulb_flags, opt_ulb_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ulb_queue_id, tvb, curr_offset + O_LBMR_TOPIC_OPT_ULB_T_QUEUE_ID, L_LBMR_TOPIC_OPT_ULB_T_QUEUE_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ulb_regid, tvb, curr_offset + O_LBMR_TOPIC_OPT_ULB_T_REGID, L_LBMR_TOPIC_OPT_ULB_T_REGID, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ulb_ulb_src_id, tvb, curr_offset + O_LBMR_TOPIC_OPT_ULB_T_ULB_SRC_ID, L_LBMR_TOPIC_OPT_ULB_T_ULB_SRC_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ulb_src_ip_addr, tvb, curr_offset + O_LBMR_TOPIC_OPT_ULB_T_SRC_IP_ADDR, L_LBMR_TOPIC_OPT_ULB_T_SRC_IP_ADDR, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ulb_src_tcp_port, tvb, curr_offset + O_LBMR_TOPIC_OPT_ULB_T_SRC_TCP_PORT, L_LBMR_TOPIC_OPT_ULB_T_SRC_TCP_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ulb_reserved, tvb, curr_offset + O_LBMR_TOPIC_OPT_ULB_T_RESERVED, L_LBMR_TOPIC_OPT_ULB_T_RESERVED, ENC_BIG_ENDIAN);
break;
case LBMR_TOPIC_OPT_CTXINSTQ_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_ctxinstq, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_ctxinstq);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinstq_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTQ_T_TYPE, L_LBMR_TOPIC_OPT_CTXINSTQ_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinstq_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTQ_T_LEN, L_LBMR_TOPIC_OPT_CTXINSTQ_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTQ_T_FLAGS, hf_lbmr_topt_ctxinstq_flags, ett_lbmr_topt_ctxinstq_flags, opt_ctxinstq_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinstq_idx, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTQ_T_IDX, L_LBMR_TOPIC_OPT_CTXINSTQ_T_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_ctxinstq_ctxinst, tvb, curr_offset + O_LBMR_TOPIC_OPT_CTXINSTQ_T_CTXINST, L_LBMR_TOPIC_OPT_CTXINSTQ_T_CTXINST, ENC_NA);
break;
case LBMR_TOPIC_OPT_DOMAIN_ID_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_domain_id, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_domain_id);
proto_tree_add_item(opt_tree, hf_lbmr_topt_domain_id_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_DOMAIN_ID_T_TYPE, L_LBMR_TOPIC_OPT_DOMAIN_ID_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_domain_id_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_DOMAIN_ID_T_LEN, L_LBMR_TOPIC_OPT_DOMAIN_ID_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_DOMAIN_ID_T_FLAGS, hf_lbmr_topt_domain_id_flags, ett_lbmr_topt_domain_id_flags, opt_domain_id_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_domain_id_domain_id, tvb, curr_offset + O_LBMR_TOPIC_OPT_DOMAIN_ID_T_DOMAIN_ID, L_LBMR_TOPIC_OPT_DOMAIN_ID_T_DOMAIN_ID, ENC_BIG_ENDIAN);
break;
case LBMR_TOPIC_OPT_EXFUNC_TYPE:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_exfunc, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_exfunc);
proto_tree_add_item(opt_tree, hf_lbmr_topt_exfunc_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_EXFUNC_T_TYPE, L_LBMR_TOPIC_OPT_EXFUNC_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_exfunc_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_EXFUNC_T_LEN, L_LBMR_TOPIC_OPT_EXFUNC_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_EXFUNC_T_FLAGS, hf_lbmr_topt_exfunc_flags, ett_lbmr_topt_exfunc_flags, opt_exfunc_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_exfunc_src_tcp_port, tvb, curr_offset + O_LBMR_TOPIC_OPT_EXFUNC_T_SRC_TCP_PORT, L_LBMR_TOPIC_OPT_EXFUNC_T_SRC_TCP_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_exfunc_reserved, tvb, curr_offset + O_LBMR_TOPIC_OPT_EXFUNC_T_RESERVED, L_LBMR_TOPIC_OPT_EXFUNC_T_RESERVED, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_exfunc_src_ip_addr, tvb, curr_offset + O_LBMR_TOPIC_OPT_EXFUNC_T_SRC_IP_ADDR, L_LBMR_TOPIC_OPT_EXFUNC_T_SRC_IP_ADDR, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(opt_tree, tvb, curr_offset + O_LBMR_TOPIC_OPT_EXFUNC_T_FUNCTIONALITY_FLAGS, hf_lbmr_topt_exfunc_functionality_flags, ett_lbmr_topt_exfunc_functionality_flags, opt_exfunc_functionality_flags, ENC_BIG_ENDIAN);
break;
default:
opt_item = proto_tree_add_item(otree, hf_lbmr_topt_unknown, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, opt_len, ENC_NA);
opt_tree = proto_item_add_subtree(opt_item, ett_lbmr_topt_unknown);
ei_item = proto_tree_add_item(opt_tree, hf_lbmr_topt_unknown_type, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_TYPE, L_LBMR_TOPIC_OPT_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_unknown_len, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_LEN, L_LBMR_TOPIC_OPT_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_lbmr_topt_unknown_flags, tvb, curr_offset + O_LBMR_TOPIC_OPT_T_FLAGS, L_LBMR_TOPIC_OPT_T_FLAGS, ENC_BIG_ENDIAN);
if (((int) opt_len) > L_LBMR_TOPIC_OPT_T)
{
proto_tree_add_item(opt_tree, hf_lbmr_topt_unknown_data, tvb, curr_offset + L_LBMR_TOPIC_OPT_T, ((int) opt_len) - L_LBMR_TOPIC_OPT_T, ENC_NA);
}
expert_add_info_format(pinfo, ei_item, &ei_lbmr_analysis_invalid_value, "Unknown option 0x%02x", opt_type);
break;
}
len += opt_len;
curr_offset += opt_len;
opt_remaining_len -= opt_len;
}
return (opt_total_len);
}
static int dissect_lbmr_tir_transport(tvbuff_t * tvb, int offset, lbm_uint8_t transport, lbm_uint8_t transport_len, const char * topic_name,
guint32 topic_index, packet_info * pinfo, proto_tree * tree, lbmr_contents_t * contents, proto_item * transport_len_item)
{
int len = 0;
guint64 channel;
proto_item * channel_item = NULL;
proto_item * ei_item = NULL;
switch (transport)
{
case LBMR_TRANSPORT_TCP:
{
guint16 port = 0;
guint32 session_id = 0;
proto_item * tcp_item = NULL;
proto_tree * tcp_tree = NULL;
lbttcp_transport_t * lbttcp_transport = NULL;
tcp_item = proto_tree_add_item(tree, hf_lbmr_tir_tcp, tvb, offset, (gint) transport_len, ENC_NA);
tcp_tree = proto_item_add_subtree(tcp_item, ett_lbmr_tir_tcp);
if ((transport_len != L_LBMR_TIR_TCP_T) && (transport_len != L_LBMR_TIR_TCP_WITH_SID_T))
{
expert_add_info_format(pinfo, transport_len_item, &ei_lbmr_analysis_length_incorrect, "Wrong transport length for LBMR TIR TCP info");
return (0);
}
if (transport_len == L_LBMR_TIR_TCP_WITH_SID_T)
{
session_id = tvb_get_ntohl(tvb, offset + O_LBMR_TIR_TCP_WITH_SID_T_SESSION_ID);
port = tvb_get_ntohs(tvb, offset + O_LBMR_TIR_TCP_WITH_SID_T_PORT);
proto_tree_add_item(tcp_tree, hf_lbmr_tir_tcp_ip, tvb, offset + O_LBMR_TIR_TCP_WITH_SID_T_IP, L_LBMR_TIR_TCP_WITH_SID_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(tcp_tree, hf_lbmr_tir_tcp_session_id, tvb, offset + O_LBMR_TIR_TCP_WITH_SID_T_SESSION_ID, L_LBMR_TIR_TCP_WITH_SID_T_SESSION_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(tcp_tree, hf_lbmr_tir_tcp_port, tvb, offset + O_LBMR_TIR_TCP_WITH_SID_T_PORT, L_LBMR_TIR_TCP_WITH_SID_T_PORT, ENC_BIG_ENDIAN);
len += L_LBMR_TIR_TCP_WITH_SID_T;
}
else
{
port = tvb_get_ntohs(tvb, offset + O_LBMR_TIR_TCP_T_PORT);
proto_tree_add_item(tcp_tree, hf_lbmr_tir_tcp_ip, tvb, offset + O_LBMR_TIR_TCP_T_IP, L_LBMR_TIR_TCP_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(tcp_tree, hf_lbmr_tir_tcp_port, tvb, offset + O_LBMR_TIR_TCP_T_PORT, L_LBMR_TIR_TCP_T_PORT, ENC_BIG_ENDIAN);
session_id = 0;
len += L_LBMR_TIR_TCP_T;
}
lbttcp_transport = lbttcp_transport_add(&(pinfo->src), port, session_id, pinfo->num);
channel = lbttcp_transport->channel;
add_contents_tir(contents, topic_name, lbttcp_transport_source_string(&(pinfo->src), port, session_id), topic_index);
}
break;
case LBMR_TRANSPORT_LBTRM:
{
guint16 src_ucast_port = 0;
guint16 udp_dest_port = 0;
guint32 session_id = 0;
proto_item * lbtrm_item = NULL;
proto_tree * lbtrm_tree = NULL;
lbtrm_transport_t * lbtrm_transport = NULL;
address multicast_group;
lbtrm_item = proto_tree_add_item(tree, hf_lbmr_tir_lbtrm, tvb, offset, (gint)transport_len, ENC_NA);
lbtrm_tree = proto_item_add_subtree(lbtrm_item, ett_lbmr_tir_lbtrm);
set_address_tvb(&multicast_group, AT_IPv4, L_LBMR_TIR_LBTRM_T_MCAST_ADDR, tvb, offset + O_LBMR_TIR_LBTRM_T_MCAST_ADDR);
session_id = tvb_get_ntohl(tvb, offset + O_LBMR_TIR_LBTRM_T_SESSION_ID);
udp_dest_port = tvb_get_ntohs(tvb, offset + O_LBMR_TIR_LBTRM_T_UDP_DEST_PORT);
src_ucast_port = tvb_get_ntohs(tvb, offset + O_LBMR_TIR_LBTRM_T_SRC_UCAST_PORT);
proto_tree_add_item(lbtrm_tree, hf_lbmr_tir_lbtrm_src_addr, tvb, offset + O_LBMR_TIR_LBTRM_T_SRC_ADDR, L_LBMR_TIR_LBTRM_T_SRC_ADDR, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtrm_tree, hf_lbmr_tir_lbtrm_mcast_addr, tvb, offset + O_LBMR_TIR_LBTRM_T_MCAST_ADDR, L_LBMR_TIR_LBTRM_T_MCAST_ADDR, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtrm_tree, hf_lbmr_tir_lbtrm_session_id, tvb, offset + O_LBMR_TIR_LBTRM_T_SESSION_ID, L_LBMR_TIR_LBTRM_T_SESSION_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtrm_tree, hf_lbmr_tir_lbtrm_udp_dest_port, tvb, offset + O_LBMR_TIR_LBTRM_T_UDP_DEST_PORT, L_LBMR_TIR_LBTRM_T_UDP_DEST_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtrm_tree, hf_lbmr_tir_lbtrm_src_ucast_port, tvb, offset + O_LBMR_TIR_LBTRM_T_SRC_UCAST_PORT, L_LBMR_TIR_LBTRM_T_SRC_UCAST_PORT, ENC_BIG_ENDIAN);
lbtrm_transport = lbtrm_transport_add(&(pinfo->src), src_ucast_port, session_id, &multicast_group, udp_dest_port, pinfo->num);
channel = lbtrm_transport->channel;
add_contents_tir(contents, topic_name, lbtrm_transport_source_string(&(pinfo->src), src_ucast_port, session_id, &multicast_group, udp_dest_port), topic_index);
len += L_LBMR_TIR_LBTRM_T;
if (transport_len != L_LBMR_TIR_LBTRM_T)
{
expert_add_info_format(pinfo, transport_len_item, &ei_lbmr_analysis_length_incorrect, "Wrong transport length for LBMR TIR LBTRM info");
}
}
break;
case LBMR_TRANSPORT_LBTRU:
{
guint32 session_id;
guint16 port;
proto_item * lbtru_item = NULL;
proto_tree * lbtru_tree = NULL;
lbtru_transport_t * lbtru_transport = NULL;
lbtru_item = proto_tree_add_item(tree, hf_lbmr_tir_lbtru, tvb, offset, (gint)transport_len, ENC_NA);
lbtru_tree = proto_item_add_subtree(lbtru_item, ett_lbmr_tir_lbtru);
if ((transport_len != L_LBMR_TIR_LBTRU_T) && (transport_len != L_LBMR_TIR_LBTRU_WITH_SID_T))
{
expert_add_info_format(pinfo, transport_len_item, &ei_lbmr_analysis_length_incorrect, "Wrong transport length for LBMR TIR LBTRU info");
return (0);
}
if (transport_len == L_LBMR_TIR_LBTRU_WITH_SID_T)
{
session_id = tvb_get_ntohl(tvb, offset + O_LBMR_TIR_LBTRU_WITH_SID_T_SESSION_ID);
port = tvb_get_ntohs(tvb, offset + O_LBMR_TIR_LBTRU_WITH_SID_T_PORT);
proto_tree_add_item(lbtru_tree, hf_lbmr_tir_lbtru_ip, tvb, offset + O_LBMR_TIR_LBTRU_WITH_SID_T_IP, L_LBMR_TIR_LBTRU_WITH_SID_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtru_tree, hf_lbmr_tir_lbtru_session_id, tvb, offset + O_LBMR_TIR_LBTRU_WITH_SID_T_SESSION_ID, L_LBMR_TIR_LBTRU_WITH_SID_T_SESSION_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtru_tree, hf_lbmr_tir_lbtru_port, tvb, offset + O_LBMR_TIR_LBTRU_WITH_SID_T_PORT, L_LBMR_TIR_LBTRU_WITH_SID_T_PORT, ENC_BIG_ENDIAN);
len += L_LBMR_TIR_LBTRU_WITH_SID_T;
}
else
{
session_id = 0;
port = tvb_get_ntohs(tvb, offset + O_LBMR_TIR_LBTRU_T_PORT);
proto_tree_add_item(lbtru_tree, hf_lbmr_tir_lbtru_ip, tvb, offset + O_LBMR_TIR_LBTRU_T_IP, L_LBMR_TIR_LBTRU_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtru_tree, hf_lbmr_tir_lbtru_port, tvb, offset + O_LBMR_TIR_LBTRU_T_PORT, L_LBMR_TIR_LBTRU_T_PORT, ENC_BIG_ENDIAN);
len += L_LBMR_TIR_LBTRU_T;
}
lbtru_transport = lbtru_transport_add(&(pinfo->src), port, session_id, pinfo->num);
channel = lbtru_transport->channel;
add_contents_tir(contents, topic_name, lbtru_transport_source_string(&(pinfo->src), port, session_id), topic_index);
}
break;
case LBMR_TRANSPORT_LBTIPC:
{
guint32 host_id;
guint32 session_id;
guint16 xport_id;
proto_item * lbtipc_item = NULL;
proto_tree * lbtipc_tree = NULL;
lbtipc_transport_t * lbtipc_transport = NULL;
lbtipc_item = proto_tree_add_item(tree, hf_lbmr_tir_lbtipc, tvb, offset, (gint)transport_len, ENC_NA);
lbtipc_tree = proto_item_add_subtree(lbtipc_item, ett_lbmr_tir_lbtipc);
if (transport_len != L_LBMR_TIR_LBTIPC_T)
{
expert_add_info_format(pinfo, transport_len_item, &ei_lbmr_analysis_length_incorrect, "Wrong transport length for LBMR TIR LBTIPC info");
return (0);
}
host_id = tvb_get_ntohl(tvb, offset + O_LBMR_TIR_LBTIPC_T_HOST_ID);
session_id = tvb_get_ntohl(tvb, offset + O_LBMR_TIR_LBTIPC_T_SESSION_ID);
xport_id = tvb_get_ntohs(tvb, offset + O_LBMR_TIR_LBTIPC_T_XPORT_ID);
proto_tree_add_item(lbtipc_tree, hf_lbmr_tir_lbtipc_host_id, tvb, offset + O_LBMR_TIR_LBTIPC_T_HOST_ID, L_LBMR_TIR_LBTIPC_T_HOST_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtipc_tree, hf_lbmr_tir_lbtipc_session_id, tvb, offset + O_LBMR_TIR_LBTIPC_T_SESSION_ID, L_LBMR_TIR_LBTIPC_T_SESSION_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtipc_tree, hf_lbmr_tir_lbtipc_xport_id, tvb, offset + O_LBMR_TIR_LBTIPC_T_XPORT_ID, L_LBMR_TIR_LBTIPC_T_XPORT_ID, ENC_BIG_ENDIAN);
lbtipc_transport = lbtipc_transport_add(host_id, session_id, xport_id);
channel = lbtipc_transport->channel;
add_contents_tir(contents, topic_name, lbtipc_transport_source_string(host_id, session_id, xport_id), topic_index);
len += L_LBMR_TIR_LBTIPC_T;
}
break;
case LBMR_TRANSPORT_LBTRDMA:
{
guint32 session_id;
guint16 port;
proto_item * lbtrdma_item = NULL;
proto_tree * lbtrdma_tree = NULL;
lbtrdma_transport_t * lbtrdma_transport = NULL;
address source_addr;
lbtrdma_item = proto_tree_add_item(tree, hf_lbmr_tir_lbtrdma, tvb, offset, (gint)transport_len, ENC_NA);
lbtrdma_tree = proto_item_add_subtree(lbtrdma_item, ett_lbmr_tir_lbtrdma);
if (transport_len != L_LBMR_TIR_LBTRDMA_T)
{
expert_add_info_format(pinfo, transport_len_item, &ei_lbmr_analysis_length_incorrect, "Wrong transport length for LBMR TIR LBTRDMA info");
return (0);
}
set_address_tvb(&source_addr, AT_IPv4, L_LBMR_TIR_LBTRDMA_T_IP, tvb, offset + O_LBMR_TIR_LBTRDMA_T_IP);
session_id = tvb_get_ntohl(tvb, offset + O_LBMR_TIR_LBTRDMA_T_SESSION_ID);
port = tvb_get_ntohs(tvb, offset + O_LBMR_TIR_LBTRDMA_T_PORT);
proto_tree_add_item(lbtrdma_tree, hf_lbmr_tir_lbtrdma_ip, tvb, offset + O_LBMR_TIR_LBTRDMA_T_IP, L_LBMR_TIR_LBTRDMA_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtrdma_tree, hf_lbmr_tir_lbtrdma_session_id, tvb, offset + O_LBMR_TIR_LBTRDMA_T_SESSION_ID, L_LBMR_TIR_LBTRDMA_T_SESSION_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtrdma_tree, hf_lbmr_tir_lbtrdma_port, tvb, offset + O_LBMR_TIR_LBTRDMA_T_PORT, L_LBMR_TIR_LBTRDMA_T_PORT, ENC_BIG_ENDIAN);
lbtrdma_transport = lbtrdma_transport_add(&source_addr, port, session_id);
channel = lbtrdma_transport->channel;
add_contents_tir(contents, topic_name, lbtrdma_transport_source_string(&source_addr, port, session_id), topic_index);
len += L_LBMR_TIR_LBTRDMA_T;
}
break;
case LBMR_TRANSPORT_LBTSMX:
{
guint32 host_id;
guint32 session_id;
guint16 xport_id;
proto_item * lbtsmx_item = NULL;
proto_tree * lbtsmx_tree = NULL;
lbtsmx_transport_t * lbtsmx_transport = NULL;
lbtsmx_item = proto_tree_add_item(tree, hf_lbmr_tir_lbtsmx, tvb, offset, (gint)transport_len, ENC_NA);
lbtsmx_tree = proto_item_add_subtree(lbtsmx_item, ett_lbmr_tir_lbtsmx);
if (transport_len != L_LBMR_TIR_LBTSMX_T)
{
expert_add_info_format(pinfo, transport_len_item, &ei_lbmr_analysis_length_incorrect, "Wrong transport length for LBMR TIR LBTSMX info");
}
host_id = tvb_get_ntohl(tvb, offset + O_LBMR_TIR_LBTSMX_T_HOST_ID);
session_id = tvb_get_ntohl(tvb, offset + O_LBMR_TIR_LBTSMX_T_SESSION_ID);
xport_id = tvb_get_ntohs(tvb, offset + O_LBMR_TIR_LBTSMX_T_XPORT_ID);
proto_tree_add_item(lbtsmx_tree, hf_lbmr_tir_lbtsmx_host_id, tvb, offset + O_LBMR_TIR_LBTSMX_T_HOST_ID, L_LBMR_TIR_LBTSMX_T_HOST_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtsmx_tree, hf_lbmr_tir_lbtsmx_session_id, tvb, offset + O_LBMR_TIR_LBTSMX_T_SESSION_ID, L_LBMR_TIR_LBTSMX_T_SESSION_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(lbtsmx_tree, hf_lbmr_tir_lbtsmx_xport_id, tvb, offset + O_LBMR_TIR_LBTSMX_T_XPORT_ID, L_LBMR_TIR_LBTSMX_T_XPORT_ID, ENC_BIG_ENDIAN);
lbtsmx_transport = lbtsmx_transport_add(host_id, session_id, xport_id);
channel = lbtsmx_transport->channel;
add_contents_tir(contents, topic_name, lbtsmx_transport_source_string(host_id, session_id, xport_id), topic_index);
len += L_LBMR_TIR_LBTSMX_T;
}
break;
default:
ei_item = proto_tree_add_item(tree, hf_lbmr_tir_unknown_transport, tvb, offset, transport_len, ENC_NA);
expert_add_info_format(pinfo, ei_item, &ei_lbmr_analysis_invalid_value, "Unknown LBMR TIR transport 0x%02x", transport);
len = transport_len;
channel = LBM_CHANNEL_NO_CHANNEL;
break;
}
if (channel != LBM_CHANNEL_NO_CHANNEL)
{
lbm_topic_add(channel, topic_index, topic_name);
channel_item = proto_tree_add_uint64(tree, hf_lbmr_tir_channel, tvb, 0, 0, channel);
PROTO_ITEM_SET_GENERATED(channel_item);
}
return (len);
}
static int dissect_lbmr_tir_entry(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree, lbmr_contents_t * contents)
{
gint namelen = 0;
gint reclen = 0;
int dissect_len = 0;
int tinfo_offset = 0;
char * name = NULL;
proto_item * ti = NULL;
proto_tree * tinfo_tree = NULL;
guint8 transport;
guint8 tlen;
guint16 ttl;
guint32 idx;
int curr_offset;
proto_item * transport_len_item = NULL;
name = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &namelen, ENC_ASCII);
reclen += namelen;
curr_offset = offset + namelen;
tinfo_offset = curr_offset;
transport = tvb_get_guint8(tvb, curr_offset + O_LBMR_TIR_T_TRANSPORT);
tlen = tvb_get_guint8(tvb, curr_offset + O_LBMR_TIR_T_TLEN);
ttl = tvb_get_ntohs(tvb, curr_offset + O_LBMR_TIR_T_TTL);
idx = tvb_get_ntohl(tvb, curr_offset + O_LBMR_TIR_T_INDEX);
reclen += L_LBMR_TIR_T;
curr_offset += L_LBMR_TIR_T;
ti = proto_tree_add_none_format(tree, hf_lbmr_tir, tvb, offset, reclen, "%s: %s, Length %u, Index %" G_GUINT32_FORMAT ", TTL %" G_GUINT16_FORMAT,
name, val_to_str((transport & LBMR_TIR_TRANSPORT), lbmr_transport_type, "Unknown (0x%02x)"), tlen, idx, ttl);
tinfo_tree = proto_item_add_subtree(ti, ett_lbmr_tir);
proto_tree_add_item(tinfo_tree, hf_lbmr_tir_name, tvb, offset, namelen, ENC_ASCII|ENC_NA);
proto_tree_add_item(tinfo_tree, hf_lbmr_tir_transport_opts, tvb, tinfo_offset + O_LBMR_TIR_T_TRANSPORT, L_LBMR_TIR_T_TRANSPORT, ENC_BIG_ENDIAN);
proto_tree_add_item(tinfo_tree, hf_lbmr_tir_transport_type, tvb, tinfo_offset + O_LBMR_TIR_T_TRANSPORT, L_LBMR_TIR_T_TRANSPORT, ENC_BIG_ENDIAN);
transport_len_item = proto_tree_add_item(tinfo_tree, hf_lbmr_tir_tlen, tvb, tinfo_offset + O_LBMR_TIR_T_TLEN, L_LBMR_TIR_T_TLEN, ENC_BIG_ENDIAN);
proto_tree_add_item(tinfo_tree, hf_lbmr_tir_ttl, tvb, tinfo_offset + O_LBMR_TIR_T_TTL, L_LBMR_TIR_T_TTL, ENC_BIG_ENDIAN);
proto_tree_add_item(tinfo_tree, hf_lbmr_tir_index, tvb, tinfo_offset + O_LBMR_TIR_T_INDEX, L_LBMR_TIR_T_INDEX, ENC_BIG_ENDIAN);
if ((transport & LBMR_TIR_OPTIONS) != 0)
{
dissect_len = dissect_lbmr_tir_options(tvb, curr_offset, pinfo, tinfo_tree);
reclen += dissect_len;
curr_offset += dissect_len;
}
reclen += dissect_lbmr_tir_transport(tvb, curr_offset, (lbm_uint8_t)(transport & LBMR_TIR_TRANSPORT), tlen, name, idx, pinfo, tinfo_tree, contents, transport_len_item);
proto_item_set_len(ti, reclen);
return (reclen);
}
static int dissect_lbmr_tirs(tvbuff_t * tvb, int offset, guint16 tir_count, packet_info * pinfo, proto_tree * tree,
const char * name, lbmr_contents_t * contents)
{
int start_offset;
int tir_len;
proto_tree * tirs_tree = NULL;
proto_item * ti = NULL;
int len = 0;
start_offset = offset;
ti = proto_tree_add_none_format(tree, hf_lbmr_tirs, tvb, start_offset, -1, "%s", name);
tirs_tree = proto_item_add_subtree(ti, ett_lbmr_tirs);
while (tir_count-- > 0)
{
tir_len = dissect_lbmr_tir_entry(tvb, offset, pinfo, tirs_tree, contents);
offset += tir_len;
len += tir_len;
}
proto_item_set_len(ti, len);
return (len);
}
static int dissect_lbmr_qqr(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree, lbmr_contents_t * contents)
{
gint namelen = 0;
guint reclen = 0;
char * name = NULL;
name = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &namelen, ENC_ASCII);
reclen += namelen;
add_contents_qqr(contents, name);
proto_tree_add_item(tree, hf_lbmr_qqr_name, tvb, offset, namelen, ENC_ASCII|ENC_NA);
return (reclen);
}
static int dissect_lbmr_qqrs(tvbuff_t * tvb, int offset, guint8 qqr_count, packet_info * pinfo, proto_tree * tree, lbmr_contents_t * contents)
{
int start_offset;
int qqr_len;
proto_tree * qqrs_tree = NULL;
proto_item * qqrs_ti = NULL;
int total_len = 0;
start_offset = offset;
qqrs_ti = proto_tree_add_item(tree, hf_lbmr_qqr, tvb, start_offset, -1, ENC_NA);
qqrs_tree = proto_item_add_subtree(qqrs_ti, ett_lbmr_qqrs);
while (qqr_count-- > 0)
{
qqr_len = dissect_lbmr_qqr(tvb, offset, pinfo, qqrs_tree, contents);
total_len += qqr_len;
offset += qqr_len;
}
proto_item_set_len(qqrs_ti, total_len);
return (total_len);
}
static int dissect_lbmr_qir_queue_blk(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree, const char * queue_name,
const char * topic_name, lbmr_contents_t * contents)
{
guint16 port = 0;
proto_item * ti = NULL;
proto_tree * blk_tree = NULL;
port = tvb_get_ntohs(tvb, offset + O_LBMR_QIR_QUEUE_BLK_T_PORT);
ti = proto_tree_add_item(tree, hf_lbmr_qir_queue_blk, tvb, offset, L_LBMR_QIR_QUEUE_BLK_T, ENC_NA);
blk_tree = proto_item_add_subtree(ti, ett_lbmr_qir_queue_blk);
proto_tree_add_item(blk_tree, hf_lbmr_qir_queue_blk_ip, tvb, offset + O_LBMR_QIR_QUEUE_BLK_T_IP, L_LBMR_QIR_QUEUE_BLK_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(blk_tree, hf_lbmr_qir_queue_blk_port, tvb, offset + O_LBMR_QIR_QUEUE_BLK_T_PORT, L_LBMR_QIR_QUEUE_BLK_T_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(blk_tree, hf_lbmr_qir_queue_blk_idx, tvb, offset + O_LBMR_QIR_QUEUE_BLK_T_IDX, L_LBMR_QIR_QUEUE_BLK_T_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(blk_tree, hf_lbmr_qir_queue_blk_grp_idx, tvb, offset + O_LBMR_QIR_QUEUE_BLK_T_GRP_IDX, L_LBMR_QIR_QUEUE_BLK_T_GRP_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(blk_tree, hf_lbmr_qir_queue_blk_reserved, tvb, offset + O_LBMR_QIR_QUEUE_BLK_T_RESERVED, L_LBMR_QIR_QUEUE_BLK_T_RESERVED, ENC_BIG_ENDIAN);
add_contents_qir(contents, queue_name, topic_name, port);
return ((int)L_LBMR_QIR_QUEUE_BLK_T);
}
static int dissect_lbmr_qir_grp_blk(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree, lbmr_contents_t * contents _U_)
{
proto_item * ti = NULL;
proto_tree * blk_tree = NULL;
guint16 idx = 0;
guint16 sz = 0;
idx = tvb_get_ntohs(tvb, offset + O_LBMR_QIR_GRP_BLK_T_GRP_IDX);
sz = tvb_get_ntohs(tvb, offset + O_LBMR_QIR_GRP_BLK_T_GRP_SZ);
ti = proto_tree_add_none_format(tree, hf_lbmr_qir_grp_blk, tvb, offset, L_LBMR_QIR_GRP_BLK_T, "Group block, Index %" G_GUINT16_FORMAT ", Size %" G_GUINT16_FORMAT, idx, sz);
blk_tree = proto_item_add_subtree(ti, ett_lbmr_qir_grp_blk);
proto_tree_add_item(blk_tree, hf_lbmr_qir_grp_blk_grp_idx, tvb, offset + O_LBMR_QIR_GRP_BLK_T_GRP_IDX, L_LBMR_QIR_GRP_BLK_T_GRP_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(blk_tree, hf_lbmr_qir_grp_blk_grp_sz, tvb, offset + O_LBMR_QIR_GRP_BLK_T_GRP_SZ, L_LBMR_QIR_GRP_BLK_T_GRP_SZ, ENC_BIG_ENDIAN);
return ((int)L_LBMR_QIR_GRP_BLK_T);
}
static int dissect_lbmr_qir_entry(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree, lbmr_contents_t * contents)
{
gint qnamelen = 0;
gint qnameoffset = 0;
char * qname = NULL;
gint tnamelen = 0;
gint tnameoffset = 0;
char * tname = NULL;
gint reclen = 0;
int curr_offset = 0;
proto_item * qirti = NULL;
proto_tree * qirtree = NULL;
proto_item * grpti = NULL;
proto_tree * grptree = NULL;
int grplen = 0;
proto_item * queueti = NULL;
proto_item * queuetree = NULL;
int queuelen = 0;
guint32 queue_id = 0;
guint16 grp_blks = 0;
guint16 queue_blks = 0;
guint16 have_options = 0;
int optlen = 0;
curr_offset = offset;
qnameoffset = curr_offset;
qname = tvb_get_stringz_enc(wmem_packet_scope(), tvb, qnameoffset, &qnamelen, ENC_ASCII);
curr_offset += qnamelen;
reclen += qnamelen;
tnameoffset = curr_offset;
tname = tvb_get_stringz_enc(wmem_packet_scope(), tvb, tnameoffset, &tnamelen, ENC_ASCII);
curr_offset += tnamelen;
reclen += tnamelen;
queue_id = tvb_get_ntohl(tvb, curr_offset + O_LBMR_QIR_T_QUEUE_ID);
have_options = tvb_get_ntohs(tvb, curr_offset + O_LBMR_QIR_T_GRP_BLKS);
grp_blks = have_options & LBMR_QIR_GRP_BLOCKS_MASK;
have_options &= LBMR_QIR_OPTIONS;
queue_blks = tvb_get_ntohs(tvb, curr_offset + O_LBMR_QIR_T_QUEUE_BLKS);
qirti = proto_tree_add_none_format(tree, hf_lbmr_qir, tvb, offset, reclen, "%s: %s, ID %" G_GUINT32_FORMAT, qname, tname, queue_id);
qirtree = proto_item_add_subtree(qirti, ett_lbmr_qir);
proto_tree_add_item(qirtree, hf_lbmr_qir_queue_name, tvb, qnameoffset, qnamelen, ENC_ASCII|ENC_NA);
proto_tree_add_item(qirtree, hf_lbmr_qir_topic_name, tvb, tnameoffset, tnamelen, ENC_ASCII|ENC_NA);
proto_tree_add_item(qirtree, hf_lbmr_qir_queue_id, tvb, curr_offset + O_LBMR_QIR_T_QUEUE_ID, L_LBMR_QIR_T_QUEUE_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(qirtree, hf_lbmr_qir_queue_ver, tvb, curr_offset + O_LBMR_QIR_T_QUEUE_VER, L_LBMR_QIR_T_QUEUE_VER, ENC_BIG_ENDIAN);
proto_tree_add_item(qirtree, hf_lbmr_qir_queue_prev_ver, tvb, curr_offset + O_LBMR_QIR_T_QUEUE_PREV_VER, L_LBMR_QIR_T_QUEUE_PREV_VER, ENC_BIG_ENDIAN);
proto_tree_add_item(qirtree, hf_lbmr_qir_option_flag, tvb, curr_offset + O_LBMR_QIR_T_GRP_BLKS, L_LBMR_QIR_T_GRP_BLKS, ENC_BIG_ENDIAN);
proto_tree_add_item(qirtree, hf_lbmr_qir_grp_blks, tvb, curr_offset + O_LBMR_QIR_T_GRP_BLKS, L_LBMR_QIR_T_GRP_BLKS, ENC_BIG_ENDIAN);
proto_tree_add_item(qirtree, hf_lbmr_qir_queue_blks, tvb, curr_offset + O_LBMR_QIR_T_QUEUE_BLKS, L_LBMR_QIR_T_QUEUE_BLKS, ENC_BIG_ENDIAN);
curr_offset += L_LBMR_QIR_T;
reclen += L_LBMR_QIR_T;
if (have_options)
{
optlen = dissect_lbmr_tir_options(tvb, curr_offset, pinfo, tree);
curr_offset += optlen;
reclen += optlen;
}
if (grp_blks > 0)
{
grpti = proto_tree_add_item(qirtree, hf_lbmr_qir_grps, tvb, curr_offset, 1, ENC_NA);
grptree = proto_item_add_subtree(grpti, ett_lbmr_qir_grp);
grplen = 0;
while (grp_blks-- > 0)
{
optlen = dissect_lbmr_qir_grp_blk(tvb, curr_offset, pinfo, grptree, contents);
curr_offset += optlen;
reclen += optlen;
grplen += optlen;
}
proto_item_set_len(grpti, grplen);
}
if (queue_blks > 0)
{
queueti = proto_tree_add_item(qirtree, hf_lbmr_qir_queues, tvb, curr_offset, 1, ENC_NA);
queuetree = proto_item_add_subtree(queueti, ett_lbmr_qir_queue);
queuelen = 0;
while (queue_blks-- > 0)
{
optlen = dissect_lbmr_qir_queue_blk(tvb, curr_offset, pinfo, queuetree, qname, tname, contents);
curr_offset += optlen;
reclen += optlen;
queuelen += optlen;
}
proto_item_set_len(queueti, queuelen);
}
proto_item_set_len(qirti, reclen);
return (reclen);
}
static int dissect_lbmr_qirs(tvbuff_t * tvb, int offset, guint16 qirs, packet_info * pinfo, proto_tree * tree, lbmr_contents_t * contents)
{
int start_offset;
int qir_len;
proto_tree * qirs_tree = NULL;
proto_item * qirs_ti = NULL;
int len = 0;
start_offset = offset;
qirs_ti = proto_tree_add_item(tree, hf_lbmr_qirs, tvb, start_offset, -1, ENC_NA);
qirs_tree = proto_item_add_subtree(qirs_ti, ett_lbmr_qirs);
while (qirs-- > 0)
{
qir_len = dissect_lbmr_qir_entry(tvb, offset, pinfo, qirs_tree, contents);
len += qir_len;
offset += qir_len;
}
proto_item_set_len(qirs_ti, len);
return (len);
}
static int dissect_lbmr_pser(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
int hdr_len = 0;
int len = 0;
int topic_len = 0;
static const int * flags[] =
{
&hf_lbmr_pser_flags_option,
NULL
};
int curr_offset = offset;
guint16 flags_val = 0;
hdr_len = (int)tvb_get_ntohs(tvb, curr_offset + O_LBMR_PSER_T_LEN);
flags_val = tvb_get_ntohs(tvb, curr_offset + O_LBMR_PSER_T_FLAGS);
topic_len = hdr_len - L_LBMR_PSER_T;
proto_tree_add_item(tree, hf_lbmr_pser_dep_type, tvb, offset + O_LBMR_PSER_T_DEP_TYPE, L_LBMR_PSER_T_DEP_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_pser_len, tvb, offset + O_LBMR_PSER_T_LEN, L_LBMR_PSER_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset + O_LBMR_PSER_T_FLAGS, hf_lbmr_pser_flags, ett_lbmr_pser_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_pser_source_ip, tvb, offset + O_LBMR_PSER_T_SOURCE_IP, L_LBMR_PSER_T_SOURCE_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_pser_store_ip, tvb, offset + O_LBMR_PSER_T_STORE_IP, L_LBMR_PSER_T_STORE_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_pser_transport_idx, tvb, offset + O_LBMR_PSER_T_TRANSPORT_IDX, L_LBMR_PSER_T_TRANSPORT_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_pser_topic_idx, tvb, offset + O_LBMR_PSER_T_TOPIC_IDX, L_LBMR_PSER_T_TOPIC_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_pser_source_port, tvb, offset + O_LBMR_PSER_T_SOURCE_PORT, L_LBMR_PSER_T_SOURCE_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_pser_store_port, tvb, offset + O_LBMR_PSER_T_STORE_PORT, L_LBMR_PSER_T_STORE_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_pser_topic, tvb, offset + O_LBMR_PSER_T_TOPIC, topic_len, ENC_ASCII|ENC_NA);
curr_offset += hdr_len;
len = hdr_len;
if ((flags_val & LBMR_PSER_OPT_FLAG) != 0)
{
proto_tree * opts_tree = NULL;
proto_item * opts_item = NULL;
proto_tree * optlen_tree = NULL;
proto_tree * optlen_item = NULL;
guint16 opt_len = 0;
opt_len = tvb_get_ntohs(tvb, curr_offset + O_LBMR_PSER_OPTLEN_T_OPTLEN);
opts_item = proto_tree_add_item(tree, hf_lbmr_pser_opts, tvb, curr_offset, -1, ENC_NA);
opts_tree = proto_item_add_subtree(opts_item, ett_lbmr_pser_opts);
optlen_item = proto_tree_add_item(opts_tree, hf_lbmr_pser_optlen, tvb, curr_offset, L_LBMR_PSER_OPTLEN_T, ENC_NA);
optlen_tree = proto_item_add_subtree(optlen_item, ett_lbmr_pser_opt_len);
proto_tree_add_item(optlen_tree, hf_lbmr_pser_optlen_type, tvb, curr_offset + O_LBMR_PSER_OPTLEN_T_TYPE, L_LBMR_PSER_OPTLEN_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(optlen_tree, hf_lbmr_pser_optlen_optlen, tvb, curr_offset + O_LBMR_PSER_OPTLEN_T_OPTLEN, L_LBMR_PSER_OPTLEN_T_OPTLEN, ENC_BIG_ENDIAN);
proto_item_set_len(opts_item, opt_len);
len += L_LBMR_PSER_OPTLEN_T;
curr_offset += L_LBMR_PSER_OPTLEN_T;
opt_len -= L_LBMR_PSER_OPTLEN_T;
while (opt_len > 0)
{
proto_tree * ctxinst_tree = NULL;
proto_item * ctxinst_item = NULL;
guint8 opt_type = tvb_get_guint8(tvb, curr_offset + O_LBMR_PSER_OPT_HDR_T_TYPE);
guint8 option_len = tvb_get_guint8(tvb, curr_offset + O_LBMR_PSER_OPT_HDR_T_LEN);
switch (opt_type)
{
case LBMR_PSER_OPT_SRC_CTXINST_TYPE:
case LBMR_PSER_OPT_STORE_CTXINST_TYPE:
ctxinst_item = proto_tree_add_item(opts_tree, hf_lbmr_pser_opt_ctxinst, tvb, curr_offset, L_LBMR_PSER_OPT_CTXINST_T, ENC_NA);
ctxinst_tree = proto_item_add_subtree(ctxinst_item, ett_lbmr_pser_opt_ctxinst);
proto_tree_add_item(ctxinst_tree, hf_lbmr_pser_opt_ctxinst_len, tvb, curr_offset + O_LBMR_PSER_OPT_CTXINST_T_LEN, L_LBMR_PSER_OPT_CTXINST_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(ctxinst_tree, hf_lbmr_pser_opt_ctxinst_type, tvb, curr_offset + O_LBMR_PSER_OPT_CTXINST_T_TYPE, L_LBMR_PSER_OPT_CTXINST_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(ctxinst_tree, hf_lbmr_pser_opt_ctxinst_ctxinst, tvb, curr_offset + O_LBMR_PSER_OPT_CTXINST_T_CTXINST, L_LBMR_PSER_OPT_CTXINST_T_CTXINST, ENC_NA);
len += L_LBMR_PSER_OPT_CTXINST_T;
curr_offset += L_LBMR_PSER_OPT_CTXINST_T;
opt_len -= L_LBMR_PSER_OPT_CTXINST_T;
break;
default:
len += option_len;
curr_offset += option_len;
opt_len -= option_len;
expert_add_info_format(pinfo, NULL, &ei_lbmr_analysis_invalid_value, "Unknown LBMR PSER option 0x%02x", opt_type);
if (option_len == 0) {
return (len);
}
break;
}
}
}
return (len);
}
int lbmr_dissect_umq_qmgmt(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint8 pckt_type = 0;
int curr_offset = 0;
guint16 dep16;
guint16 idx;
guint8 flags_val = 0;
int len_dissected = 0;
static const int * flags[] =
{
&hf_qmgmt_flags_i_flag,
&hf_qmgmt_flags_n_flag,
NULL
};
static const int * il_flags[] =
{
&hf_qmgmt_flags_i_flag,
&hf_qmgmt_flags_n_flag,
&hf_qmgmt_flags_il_l_flag,
&hf_qmgmt_flags_il_k_flag,
NULL
};
flags_val = tvb_get_guint8(tvb, offset + O_UMQ_QMGMT_HDR_T_FLAGS);
pckt_type = tvb_get_guint8(tvb, offset + O_UMQ_QMGMT_HDR_T_PCKT_TYPE);
dep16 = tvb_get_ntohs(tvb, offset + O_UMQ_QMGMT_HDR_T_PCKT_TYPE_DEP16);
if (pckt_type == UMQ_QMGMT_HDR_PCKT_TYPE_IL)
{
proto_tree_add_bitmask(tree, tvb, offset + O_UMQ_QMGMT_HDR_T_FLAGS, hf_qmgmt_flags, ett_qmgmt_flags, il_flags, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_bitmask(tree, tvb, offset + O_UMQ_QMGMT_HDR_T_FLAGS, hf_qmgmt_flags, ett_qmgmt_flags, flags, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_qmgmt_pckt_type, tvb, offset + O_UMQ_QMGMT_HDR_T_PCKT_TYPE, L_UMQ_QMGMT_HDR_T_PCKT_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_qmgmt_cfgsig, tvb, offset + O_UMQ_QMGMT_HDR_T_CFGSIG, L_UMQ_QMGMT_HDR_T_CFGSIG, ENC_NA);
proto_tree_add_item(tree, hf_qmgmt_queue_id, tvb, offset + O_UMQ_QMGMT_HDR_T_QUEUE_ID, L_UMQ_QMGMT_HDR_T_QUEUE_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_qmgmt_queue_ver, tvb, offset + O_UMQ_QMGMT_HDR_T_QUEUE_VER, L_UMQ_QMGMT_HDR_T_QUEUE_VER, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_qmgmt_ip, tvb, offset + O_UMQ_QMGMT_HDR_T_IP, L_UMQ_QMGMT_HDR_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_qmgmt_port, tvb, offset + O_UMQ_QMGMT_HDR_T_PORT, L_UMQ_QMGMT_HDR_T_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_qmgmt_inst_idx, tvb, offset + O_UMQ_QMGMT_HDR_T_INST_IDX, L_UMQ_QMGMT_HDR_T_INST_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_qmgmt_grp_idx, tvb, offset + O_UMQ_QMGMT_HDR_T_GRP_IDX, L_UMQ_QMGMT_HDR_T_GRP_IDX, ENC_BIG_ENDIAN);
switch (pckt_type)
{
case UMQ_QMGMT_HDR_PCKT_TYPE_IL:
proto_tree_add_item(tree, hf_qmgmt_il_num_insts, tvb, offset + O_UMQ_QMGMT_HDR_T_PCKT_TYPE_DEP16, L_UMQ_QMGMT_HDR_T_PCKT_TYPE_DEP16, ENC_BIG_ENDIAN);
break;
case UMQ_QMGMT_HDR_PCKT_TYPE_JREJ:
proto_tree_add_item(tree, hf_qmgmt_jrej_code, tvb, offset + O_UMQ_QMGMT_HDR_T_PCKT_TYPE_DEP16, L_UMQ_QMGMT_HDR_T_PCKT_TYPE_DEP16, ENC_BIG_ENDIAN);
break;
case UMQ_QMGMT_HDR_PCKT_TYPE_EV:
proto_tree_add_item(tree, hf_qmgmt_ev_bias, tvb, offset + O_UMQ_QMGMT_HDR_T_PCKT_TYPE_DEP16, L_UMQ_QMGMT_HDR_T_PCKT_TYPE_DEP16, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_qmgmt_pckt_type_dep16, tvb, offset + O_UMQ_QMGMT_HDR_T_PCKT_TYPE_DEP16, L_UMQ_QMGMT_HDR_T_PCKT_TYPE_DEP16, ENC_BIG_ENDIAN);
break;
}
len_dissected = L_UMQ_QMGMT_HDR_T;
curr_offset = offset + L_UMQ_QMGMT_HDR_T;
switch (pckt_type)
{
case UMQ_QMGMT_HDR_PCKT_TYPE_IL:
{
proto_item * il_subtree_item = NULL;
proto_tree * il_subtree = NULL;
static const int * il_inst_flags[] =
{
&hf_qmgmt_il_inst_flags_m_flag,
&hf_qmgmt_il_inst_flags_q_flag,
&hf_qmgmt_il_inst_flags_p_flag,
NULL
};
il_subtree_item = proto_tree_add_item(tree, hf_qmgmt_il, tvb, curr_offset, L_UMQ_QMGMT_IL_HDR_T, ENC_NA);
il_subtree = proto_item_add_subtree(il_subtree_item, ett_qmgmt_il);
proto_tree_add_item(il_subtree, hf_qmgmt_il_highest_rcr_tsp, tvb, curr_offset + O_UMQ_QMGMT_IL_HDR_T_HIGHEST_RCR_TSP, L_UMQ_QMGMT_IL_HDR_T_HIGHEST_RCR_TSP, ENC_BIG_ENDIAN);
len_dissected += L_UMQ_QMGMT_IL_HDR_T;
curr_offset += L_UMQ_QMGMT_IL_HDR_T;
for (idx = 0; idx < dep16; ++idx)
{
proto_item * il_inst_subtree_item = NULL;
proto_tree * il_inst_subtree = NULL;
il_inst_subtree_item = proto_tree_add_item(tree, hf_qmgmt_il_inst, tvb, curr_offset, L_UMQ_QMGMT_IL_INST_HDR_T, ENC_NA);
il_inst_subtree = proto_item_add_subtree(il_inst_subtree_item, ett_qmgmt_il_inst);
proto_tree_add_item(il_inst_subtree, hf_qmgmt_il_inst_ip, tvb, curr_offset + O_UMQ_QMGMT_IL_INST_HDR_T_IP, L_UMQ_QMGMT_IL_INST_HDR_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(il_inst_subtree, hf_qmgmt_il_inst_port, tvb, curr_offset + O_UMQ_QMGMT_IL_INST_HDR_T_PORT, L_UMQ_QMGMT_IL_INST_HDR_T_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(il_inst_subtree, hf_qmgmt_il_inst_inst_idx, tvb, curr_offset + O_UMQ_QMGMT_IL_INST_HDR_T_INST_IDX, L_UMQ_QMGMT_IL_INST_HDR_T_INST_IDX, ENC_BIG_ENDIAN);
proto_tree_add_item(il_inst_subtree, hf_qmgmt_il_inst_grp_idx, tvb, curr_offset + O_UMQ_QMGMT_IL_INST_HDR_T_GRP_IDX, L_UMQ_QMGMT_IL_INST_HDR_T_GRP_IDX, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(il_inst_subtree, tvb, curr_offset + O_UMQ_QMGMT_IL_INST_HDR_T_FLAGS, hf_qmgmt_il_inst_flags, ett_qmgmt_il_inst_flags, il_inst_flags, ENC_BIG_ENDIAN);
len_dissected += L_UMQ_QMGMT_IL_INST_HDR_T;
curr_offset += L_UMQ_QMGMT_IL_INST_HDR_T;
}
}
break;
case UMQ_QMGMT_HDR_PCKT_TYPE_JR:
break;
case UMQ_QMGMT_HDR_PCKT_TYPE_JREJ:
break;
case UMQ_QMGMT_HDR_PCKT_TYPE_IKA:
break;
case UMQ_QMGMT_HDR_PCKT_TYPE_EC:
{
proto_item * ec_subtree_item = NULL;
proto_tree * ec_subtree = NULL;
ec_subtree_item = proto_tree_add_item(tree, hf_qmgmt_ec, tvb, curr_offset, L_UMQ_QMGMT_EC_HDR_T, ENC_NA);
ec_subtree = proto_item_add_subtree(ec_subtree_item, ett_qmgmt_ec);
proto_tree_add_item(ec_subtree, hf_qmgmt_ec_queue_new_ver, tvb, curr_offset + O_UMQ_QMGMT_EC_HDR_T_QUEUE_NEW_VER, L_UMQ_QMGMT_EC_HDR_T_QUEUE_NEW_VER, ENC_BIG_ENDIAN);
len_dissected += L_UMQ_QMGMT_EC_HDR_T;
curr_offset += L_UMQ_QMGMT_EC_HDR_T;
}
break;
case UMQ_QMGMT_HDR_PCKT_TYPE_EV:
{
proto_item * ev_subtree_item = NULL;
proto_tree * ev_subtree = NULL;
ev_subtree_item = proto_tree_add_item(tree, hf_qmgmt_ev, tvb, curr_offset, L_UMQ_QMGMT_EV_HDR_T, ENC_NA);
ev_subtree = proto_item_add_subtree(ev_subtree_item, ett_qmgmt_ev);
proto_tree_add_item(ev_subtree, hf_qmgmt_ev_highest_rcr_tsp, tvb, curr_offset + O_UMQ_QMGMT_EV_HDR_T_HIGHEST_RCR_TSP, L_UMQ_QMGMT_EV_HDR_T_HIGHEST_RCR_TSP, ENC_BIG_ENDIAN);
proto_tree_add_item(ev_subtree, hf_qmgmt_ev_age, tvb, curr_offset + O_UMQ_QMGMT_EV_HDR_T_AGE, L_UMQ_QMGMT_EV_HDR_T_AGE, ENC_BIG_ENDIAN);
len_dissected += L_UMQ_QMGMT_EV_HDR_T;
curr_offset += L_UMQ_QMGMT_EV_HDR_T;
}
break;
case UMQ_QMGMT_HDR_PCKT_TYPE_CNIL:
break;
case UMQ_QMGMT_HDR_PCKT_TYPE_QRO:
{
proto_item * qro_subtree_item = NULL;
proto_tree * qro_subtree = NULL;
qro_subtree_item = proto_tree_add_item(tree, hf_qmgmt_qro, tvb, curr_offset, L_UMQ_QMGMT_QRO_HDR_T, ENC_NA);
qro_subtree = proto_item_add_subtree(qro_subtree_item, ett_qmgmt_qro);
proto_tree_add_item(qro_subtree, hf_qmgmt_qro_highest_rcr_tsp, tvb, curr_offset + O_UMQ_QMGMT_QRO_HDR_T_HIGHEST_RCR_TSP, L_UMQ_QMGMT_QRO_HDR_T_HIGHEST_RCR_TSP, ENC_BIG_ENDIAN);
len_dissected += L_UMQ_QMGMT_QRO_HDR_T;
curr_offset += L_UMQ_QMGMT_QRO_HDR_T;
}
break;
default:
expert_add_info_format(pinfo, NULL, &ei_lbmr_analysis_invalid_value, "Unknown LBMR QMGMT packet type 0x%02x", pckt_type);
break;
}
if ((flags_val & UMQ_QMGMT_HDR_N_FLAG) != 0)
{
int qnamelen = tvb_reported_length_remaining(tvb, curr_offset);
if (qnamelen > 1)
{
proto_tree_add_item(tree, hf_qmgmt_qname, tvb, curr_offset, qnamelen, ENC_ASCII|ENC_NA);
}
len_dissected += qnamelen;
}
return (len_dissected);
}
static int dissect_lbmr_ctxinfo(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 flags16 = 0;
guint8 reclen = 0;
static const int * flags[] =
{
&hf_lbmr_ctxinfo_flags_query,
&hf_lbmr_ctxinfo_flags_ip,
&hf_lbmr_ctxinfo_flags_instance,
&hf_lbmr_ctxinfo_flags_tnwg_src,
&hf_lbmr_ctxinfo_flags_tnwg_rcv,
&hf_lbmr_ctxinfo_flags_proxy,
&hf_lbmr_ctxinfo_flags_name,
NULL
};
flags16 = tvb_get_ntohs(tvb, offset + O_LBMR_CTXINFO_T_FLAGS);
reclen = tvb_get_guint8(tvb, offset + O_LBMR_CTXINFO_T_LEN);
proto_tree_add_item(tree, hf_lbmr_ctxinfo_len, tvb, offset + O_LBMR_CTXINFO_T_LEN, L_LBMR_CTXINFO_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_ctxinfo_hop_count, tvb, offset + O_LBMR_CTXINFO_T_HOP_COUNT, L_LBMR_CTXINFO_T_HOP_COUNT, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset + O_LBMR_CTXINFO_T_FLAGS, hf_lbmr_ctxinfo_flags, ett_lbmr_ctxinfo_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_ctxinfo_port, tvb, offset + O_LBMR_CTXINFO_T_PORT, L_LBMR_CTXINFO_T_FLAGS, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_ctxinfo_ip, tvb, offset + O_LBMR_CTXINFO_T_IP, L_LBMR_CTXINFO_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_ctxinfo_instance, tvb, offset + O_LBMR_CTXINFO_T_INSTANCE, L_LBMR_CTXINFO_T_INSTANCE, ENC_NA);
if ((flags16 & LBMR_CTXINFO_NAME_FLAG) != 0)
{
proto_tree_add_item(tree, hf_lbmr_ctxinfo_name, tvb, offset + L_LBMR_CTXINFO_T, reclen - L_LBMR_CTXINFO_T, ENC_ASCII|ENC_NA);
}
return ((int)reclen);
}
static int dissect_lbmr_topic_res_request(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
static const int * flags[] =
{
&hf_lbmr_topic_res_request_flags_gw_remote_interest,
&hf_lbmr_topic_res_request_flags_context_query,
&hf_lbmr_topic_res_request_flags_context_advertisement,
&hf_lbmr_topic_res_request_flags_gateway_meta,
&hf_lbmr_topic_res_request_flags_advertisement,
&hf_lbmr_topic_res_request_flags_query,
&hf_lbmr_topic_res_request_flags_wildcard_query,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset + O_LBMR_TOPIC_RES_REQUEST_T_FLAGS, hf_lbmr_topic_res_request_flags, ett_lbmr_topic_res_request_flags, flags, ENC_BIG_ENDIAN);
return (L_LBMR_TOPIC_RES_REQUEST_T);
}
static int dissect_lbmr_remote_domain_route(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
guint16 num_domains;
int len_dissected = 0;
int ofs = 0;
guint16 idx;
num_domains = tvb_get_ntohs(tvb, offset + O_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_NUM_DOMAINS);
proto_tree_add_item(tree, hf_lbmr_remote_domain_route_hdr_num_domains, tvb, offset + O_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_NUM_DOMAINS, L_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_NUM_DOMAINS, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_remote_domain_route_hdr_ip, tvb, offset + O_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_IP, L_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_remote_domain_route_hdr_port, tvb, offset + O_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_PORT, L_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_remote_domain_route_hdr_reserved, tvb, offset + O_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_RESERVED, L_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_RESERVED, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_remote_domain_route_hdr_length, tvb, offset + O_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_LENGTH, L_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T_LENGTH, ENC_BIG_ENDIAN);
len_dissected = L_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T;
ofs = offset + L_LBMR_REMOTE_DOMAIN_ROUTE_HDR_T;
for (idx = 0; idx < num_domains; ++idx)
{
proto_tree_add_item(tree, hf_lbmr_remote_domain_route_hdr_domain, tvb, ofs, sizeof(lbm_uint32_t), ENC_BIG_ENDIAN);
len_dissected += (int)sizeof(lbm_uint32_t);
ofs += (int)sizeof(lbm_uint32_t);
}
return (len_dissected);
}
static int dissect_lbmr_rctxinfo_rec_address_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
subtree_item = proto_tree_add_item(tree, hf_lbmr_rctxinfo_rec_address, tvb, offset, L_LBMR_RCTXINFO_REC_ADDRESS_OPT_T, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_rctxinfo_rec_address);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_address_type, tvb, offset + O_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_TYPE, L_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_address_len, tvb, offset + O_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_LEN, L_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_address_flags, tvb, offset + O_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_FLAGS, L_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_FLAGS, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_address_domain_id, tvb, offset + O_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_DOMAIN_ID, L_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_DOMAIN_ID, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_address_ip, tvb, offset + O_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_IP, L_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_IP, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_address_port, tvb, offset + O_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_PORT, L_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_PORT, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_address_res, tvb, offset + O_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_RES, L_LBMR_RCTXINFO_REC_ADDRESS_OPT_T_RES, ENC_BIG_ENDIAN);
return ((int)L_LBMR_RCTXINFO_REC_ADDRESS_OPT_T);
}
static int dissect_lbmr_rctxinfo_rec_instance_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
guint8 len = 0;
len = tvb_get_guint8(tvb, offset + O_LBMR_RCTXINFO_REC_INSTANCE_OPT_T_LEN);
subtree_item = proto_tree_add_item(tree, hf_lbmr_rctxinfo_rec_instance, tvb, offset, (int)len, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_rctxinfo_rec_instance);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_instance_type, tvb, offset + O_LBMR_RCTXINFO_REC_INSTANCE_OPT_T_TYPE, L_LBMR_RCTXINFO_REC_INSTANCE_OPT_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_instance_len, tvb, offset + O_LBMR_RCTXINFO_REC_INSTANCE_OPT_T_LEN, L_LBMR_RCTXINFO_REC_INSTANCE_OPT_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_instance_flags, tvb, offset + O_LBMR_RCTXINFO_REC_INSTANCE_OPT_T_FLAGS, L_LBMR_RCTXINFO_REC_INSTANCE_OPT_T_FLAGS, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_instance_instance, tvb, offset + O_LBMR_RCTXINFO_REC_INSTANCE_OPT_T_INSTANCE, L_LBMR_RCTXINFO_REC_INSTANCE_OPT_T_INSTANCE, ENC_NA);
return ((int)L_LBMR_RCTXINFO_REC_INSTANCE_OPT_T);
}
static int dissect_lbmr_rctxinfo_rec_odomain_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
guint8 len = 0;
len = tvb_get_guint8(tvb, offset + O_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T_LEN);
subtree_item = proto_tree_add_item(tree, hf_lbmr_rctxinfo_rec_odomain, tvb, offset, (int)len, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_rctxinfo_rec_odomain);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_odomain_type, tvb, offset + O_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T_TYPE, L_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_odomain_len, tvb, offset + O_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T_LEN, L_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_odomain_flags, tvb, offset + O_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T_FLAGS, L_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T_FLAGS, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_odomain_domain_id, tvb, offset + O_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T_DOMAIN_ID, L_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T_DOMAIN_ID, ENC_BIG_ENDIAN);
return ((int)L_LBMR_RCTXINFO_REC_ODOMAIN_OPT_T);
}
static int dissect_lbmr_rctxinfo_rec_name_opt(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
guint8 len = 0;
int name_len = 0;
len = tvb_get_guint8(tvb, offset + O_LBMR_RCTXINFO_REC_NAME_OPT_T_LEN);
subtree_item = proto_tree_add_item(tree, hf_lbmr_rctxinfo_rec_name, tvb, offset, (int)len, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_rctxinfo_rec_name);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_name_type, tvb, offset + O_LBMR_RCTXINFO_REC_NAME_OPT_T_TYPE, L_LBMR_RCTXINFO_REC_NAME_OPT_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_name_len, tvb, offset + O_LBMR_RCTXINFO_REC_NAME_OPT_T_LEN, L_LBMR_RCTXINFO_REC_NAME_OPT_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_name_flags, tvb, offset + O_LBMR_RCTXINFO_REC_NAME_OPT_T_FLAGS, L_LBMR_RCTXINFO_REC_NAME_OPT_T_FLAGS, ENC_BIG_ENDIAN);
name_len = ((int)len) - L_LBMR_RCTXINFO_REC_NAME_OPT_T;
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_name_name, tvb, offset + L_LBMR_RCTXINFO_REC_NAME_OPT_T, name_len, ENC_ASCII|ENC_NA);
return ((int)len);
}
static int dissect_lbmr_rctxinfo_rec_unknown_opt(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
guint8 len = 0;
int data_len = 0;
guint8 opt_type;
opt_type = tvb_get_guint8(tvb, offset + O_LBMR_RCTXINFO_REC_OPT_T_TYPE);
len = tvb_get_guint8(tvb, offset + O_LBMR_RCTXINFO_REC_OPT_T_LEN);
subtree_item = proto_tree_add_item(tree, hf_lbmr_rctxinfo_rec_unknown, tvb, offset, (int)len, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_rctxinfo_rec_unknown);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_unknown_type, tvb, offset + O_LBMR_RCTXINFO_REC_OPT_T_TYPE, L_LBMR_RCTXINFO_REC_OPT_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_unknown_len, tvb, offset + O_LBMR_RCTXINFO_REC_OPT_T_LEN, L_LBMR_RCTXINFO_REC_OPT_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_unknown_flags, tvb, offset + O_LBMR_RCTXINFO_REC_OPT_T_FLAGS, L_LBMR_RCTXINFO_REC_OPT_T_FLAGS, ENC_BIG_ENDIAN);
data_len = ((int) len) - L_LBMR_RCTXINFO_REC_OPT_T;
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_unknown_data, tvb, offset + L_LBMR_RCTXINFO_REC_OPT_T, data_len, ENC_NA);
expert_add_info_format(pinfo, subtree_item, &ei_lbmr_analysis_invalid_value, "Unknown LBMR RCTXINFO option 0x%02x", opt_type);
return ((int) len);
}
static int dissect_lbmr_rctxinfo_rec(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
guint8 opt_type = 0;
static const int * flags[] =
{
&hf_lbmr_rctxinfo_rec_flags_query,
NULL
};
guint16 len = 0;
int rec_len_remaining = 0;
int ofs = 0;
int opt_len_dissected = 0;
int len_dissected = 0;
len = tvb_get_ntohs(tvb, offset + O_LBMR_RCTXINFO_REC_T_LEN);
subtree_item = proto_tree_add_item(tree, hf_lbmr_rctxinfo_rec, tvb, offset, -1, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_rctxinfo_rec);
proto_tree_add_item(subtree, hf_lbmr_rctxinfo_rec_len, tvb, offset + O_LBMR_RCTXINFO_REC_T_LEN, L_LBMR_RCTXINFO_REC_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(subtree, tvb, offset + O_LBMR_RCTXINFO_REC_T_FLAGS, hf_lbmr_rctxinfo_rec_flags, ett_lbmr_rctxinfo_rec_flags, flags, ENC_BIG_ENDIAN);
ofs = offset + L_LBMR_RCTXINFO_REC_T;
rec_len_remaining = len - L_LBMR_RCTXINFO_REC_T;
len_dissected = L_LBMR_RCTXINFO_REC_T;
while (rec_len_remaining > 0)
{
opt_type = tvb_get_guint8(tvb, ofs + O_LBMR_RCTXINFO_REC_OPT_T_TYPE);
switch (opt_type)
{
case LBMR_RCTXINFO_OPT_ADDRESS_TYPE:
opt_len_dissected = dissect_lbmr_rctxinfo_rec_address_opt(tvb, ofs, pinfo, subtree);
break;
case LBMR_RCTXINFO_OPT_INSTANCE_TYPE:
opt_len_dissected = dissect_lbmr_rctxinfo_rec_instance_opt(tvb, ofs, pinfo, subtree);
break;
case LBMR_RCTXINFO_OPT_ODOMAIN_TYPE:
opt_len_dissected = dissect_lbmr_rctxinfo_rec_odomain_opt(tvb, ofs, pinfo, subtree);
break;
case LBMR_RCTXINFO_OPT_NAME_TYPE:
opt_len_dissected = dissect_lbmr_rctxinfo_rec_name_opt(tvb, ofs, pinfo, subtree);
break;
default:
opt_len_dissected = dissect_lbmr_rctxinfo_rec_unknown_opt(tvb, ofs, pinfo, subtree);
break;
}
len_dissected += opt_len_dissected;
rec_len_remaining -= opt_len_dissected;
ofs += opt_len_dissected;
}
proto_item_set_len(subtree_item, len_dissected);
return (len_dissected);
}
static int dissect_lbmr_rctxinfo(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
guint16 num_recs = 0;
int ofs = 0;
int len_dissected = 0;
int rec_len_dissected = 0;
num_recs = tvb_get_ntohs(tvb, offset + O_LBMR_RCTXINFO_T_NUM_RECS);
proto_tree_add_item(tree, hf_lbmr_rctxinfo_len, tvb, offset + O_LBMR_RCTXINFO_T_LEN, L_LBMR_RCTXINFO_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_rctxinfo_num_recs, tvb, offset + O_LBMR_RCTXINFO_T_NUM_RECS, L_LBMR_RCTXINFO_T_NUM_RECS, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_rctxinfo_reserved, tvb, offset + O_LBMR_RCTXINFO_T_RESERVED, L_LBMR_RCTXINFO_T_RESERVED, ENC_BIG_ENDIAN);
len_dissected = L_LBMR_RCTXINFO_T;
ofs = offset + L_LBMR_RCTXINFO_T;
while (num_recs > 0)
{
rec_len_dissected = dissect_lbmr_rctxinfo_rec(tvb, ofs, pinfo, tree);
ofs += rec_len_dissected;
len_dissected += rec_len_dissected;
num_recs--;
}
return (len_dissected);
}
static proto_item * format_ver_type(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_item * type_item = NULL;
proto_tree_add_item(tree, hf_lbmr_hdr_ver, tvb, offset + O_LBMR_HDR_T_VER_TYPE, L_LBMR_HDR_T_VER_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lbmr_hdr_opt, tvb, offset + O_LBMR_HDR_T_VER_TYPE, L_LBMR_HDR_T_VER_TYPE, ENC_BIG_ENDIAN);
type_item = proto_tree_add_item(tree, hf_lbmr_hdr_type, tvb, offset + O_LBMR_HDR_T_VER_TYPE, L_LBMR_HDR_T_VER_TYPE, ENC_BIG_ENDIAN);
return (type_item);
}
static int dissect_lbmr_opt_len(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
int len = 0;
subtree_item = proto_tree_add_item(tree, hf_lbmr_opt_len, tvb, offset, L_LBMR_LBMR_OPT_SRC_ID_T, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_opt_len);
proto_tree_add_item(subtree, hf_lbmr_opt_len_type, tvb, offset + O_LBMR_LBMR_OPT_LEN_T_TYPE, L_LBMR_LBMR_OPT_LEN_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_len_len, tvb, offset + O_LBMR_LBMR_OPT_LEN_T_LEN, L_LBMR_LBMR_OPT_LEN_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_len_total_len, tvb, offset + O_LBMR_LBMR_OPT_LEN_T_TOTAL_LEN, L_LBMR_LBMR_OPT_LEN_T_TOTAL_LEN, ENC_BIG_ENDIAN);
len = L_LBMR_LBMR_OPT_LEN_T;
return (len);
}
static int dissect_lbmr_opt_src_id(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
static const int * flags[] =
{
&hf_lbmr_opt_src_id_flags_ignore,
NULL
};
subtree_item = proto_tree_add_item(tree, hf_lbmr_opt_src_id, tvb, offset, L_LBMR_LBMR_OPT_SRC_ID_T, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_opt_src_id);
proto_tree_add_item(subtree, hf_lbmr_opt_src_id_type, tvb, offset + O_LBMR_LBMR_OPT_SRC_ID_T_TYPE, L_LBMR_LBMR_OPT_SRC_ID_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_src_id_len, tvb, offset + O_LBMR_LBMR_OPT_SRC_ID_T_LEN, L_LBMR_LBMR_OPT_SRC_ID_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(subtree, tvb, offset + O_LBMR_LBMR_OPT_SRC_ID_T_FLAGS, hf_lbmr_opt_src_id_flags, ett_lbmr_opt_src_id_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_src_id_src_id, tvb, offset + O_LBMR_LBMR_OPT_SRC_ID_T_SRC_ID, L_LBMR_LBMR_OPT_SRC_ID_T_SRC_ID, ENC_NA);
return (L_LBMR_LBMR_OPT_SRC_ID_T);
}
static int dissect_lbmr_opt_src_type(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
static const int * flags[] =
{
&hf_lbmr_opt_src_type_flags_ignore,
NULL
};
subtree_item = proto_tree_add_item(tree, hf_lbmr_opt_src_type, tvb, offset, L_LBMR_LBMR_OPT_SRC_TYPE_T, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_opt_src_type);
proto_tree_add_item(subtree, hf_lbmr_opt_src_type_type, tvb, offset + O_LBMR_LBMR_OPT_SRC_TYPE_T_TYPE, L_LBMR_LBMR_OPT_SRC_TYPE_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_src_type_len, tvb, offset + O_LBMR_LBMR_OPT_SRC_TYPE_T_LEN, L_LBMR_LBMR_OPT_SRC_TYPE_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(subtree, tvb, offset + O_LBMR_LBMR_OPT_SRC_TYPE_T_FLAGS, hf_lbmr_opt_src_type_flags, ett_lbmr_opt_src_type_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_src_type_src_type, tvb, offset + O_LBMR_LBMR_OPT_SRC_TYPE_T_SRC_TYPE, L_LBMR_LBMR_OPT_SRC_TYPE_T_SRC_TYPE, ENC_BIG_ENDIAN);
return (L_LBMR_LBMR_OPT_SRC_TYPE_T);
}
static int dissect_lbmr_opt_version(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
static const int * flags[] =
{
&hf_lbmr_opt_version_flags_ignore,
&hf_lbmr_opt_version_flags_ume,
&hf_lbmr_opt_version_flags_umq,
NULL
};
subtree_item = proto_tree_add_item(tree, hf_lbmr_opt_version, tvb, offset, L_LBMR_LBMR_OPT_VERSION_T, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_opt_version);
proto_tree_add_item(subtree, hf_lbmr_opt_version_type, tvb, offset + O_LBMR_LBMR_OPT_VERSION_T_TYPE, L_LBMR_LBMR_OPT_VERSION_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_version_len, tvb, offset + O_LBMR_LBMR_OPT_VERSION_T_LEN, L_LBMR_LBMR_OPT_VERSION_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(subtree, tvb, offset + O_LBMR_LBMR_OPT_VERSION_T_FLAGS, hf_lbmr_opt_version_flags, ett_lbmr_opt_version_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_version_version, tvb, offset + O_LBMR_LBMR_OPT_VERSION_T_VERSION, L_LBMR_LBMR_OPT_VERSION_T_VERSION, ENC_BIG_ENDIAN);
return (L_LBMR_LBMR_OPT_VERSION_T);
}
static int dissect_lbmr_opt_local_domain(tvbuff_t * tvb, int offset, packet_info * pinfo _U_, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
static const int * flags[] =
{
&hf_lbmr_opt_local_domain_flags_ignore,
NULL
};
subtree_item = proto_tree_add_item(tree, hf_lbmr_opt_local_domain, tvb, offset, L_LBMR_LBMR_OPT_LOCAL_DOMAIN_T, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_opt_local_domain);
proto_tree_add_item(subtree, hf_lbmr_opt_local_domain_type, tvb, offset + O_LBMR_LBMR_OPT_LOCAL_DOMAIN_T_TYPE, L_LBMR_LBMR_OPT_LOCAL_DOMAIN_T_TYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_local_domain_len, tvb, offset + O_LBMR_LBMR_OPT_LOCAL_DOMAIN_T_LEN, L_LBMR_LBMR_OPT_LOCAL_DOMAIN_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(subtree, tvb, offset + O_LBMR_LBMR_OPT_LOCAL_DOMAIN_T_FLAGS, hf_lbmr_opt_local_domain_flags, ett_lbmr_opt_local_domain_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_local_domain_local_domain_id, tvb, offset + O_LBMR_LBMR_OPT_LOCAL_DOMAIN_T_LOCAL_DOMAIN_ID, L_LBMR_LBMR_OPT_LOCAL_DOMAIN_T_LOCAL_DOMAIN_ID, ENC_BIG_ENDIAN);
return (L_LBMR_LBMR_OPT_LOCAL_DOMAIN_T);
}
static int dissect_lbmr_opt_unknown(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
proto_tree * subtree = NULL;
proto_item * subtree_item = NULL;
guint8 len = 0;
proto_item * type_item = NULL;
guint8 opt_type = 0;
subtree_item = proto_tree_add_item(tree, hf_lbmr_opt_unknown, tvb, offset, -1, ENC_NA);
subtree = proto_item_add_subtree(subtree_item, ett_lbmr_opt_unknown);
opt_type = tvb_get_guint8(tvb, offset + O_LBMR_LBMR_OPT_HDR_T_TYPE);
type_item = proto_tree_add_item(subtree, hf_lbmr_opt_unknown_type, tvb, offset + O_LBMR_LBMR_OPT_HDR_T_TYPE, L_LBMR_LBMR_OPT_HDR_T_TYPE, ENC_BIG_ENDIAN);
len = tvb_get_guint8(tvb, offset + O_LBMR_LBMR_OPT_HDR_T_LEN);
proto_tree_add_item(subtree, hf_lbmr_opt_unknown_len, tvb, offset + O_LBMR_LBMR_OPT_HDR_T_LEN, L_LBMR_LBMR_OPT_HDR_T_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_lbmr_opt_unknown_flags, tvb, offset + O_LBMR_LBMR_OPT_HDR_T_FLAGS, L_LBMR_LBMR_OPT_HDR_T_FLAGS, ENC_NA);
proto_tree_add_item(subtree, hf_lbmr_opt_unknown_data, tvb, offset + L_LBMR_LBMR_OPT_HDR_T, (int) len - L_LBMR_LBMR_OPT_HDR_T, ENC_NA);
proto_item_set_len(subtree_item, (int) len);
expert_add_info_format(pinfo, type_item, &ei_lbmr_analysis_invalid_value, "Unknown LBMR option type 0x%02x", opt_type);
return ((int) len);
}
static int dissect_lbmr_options(tvbuff_t * tvb, int offset, packet_info * pinfo, proto_tree * tree)
{
proto_tree * opt_tree = NULL;
proto_item * ti = NULL;
int curr_offset = offset;
int len = 0;
ti = proto_tree_add_item(tree, hf_lbmr_opts, tvb, curr_offset, -1, ENC_NA);
opt_tree = proto_item_add_subtree(ti, ett_lbmr_opts);
while (tvb_reported_length_remaining(tvb, curr_offset) > 0)
{
int opt_len;
guint8 opt_type;
opt_type = tvb_get_guint8(tvb, curr_offset + O_LBMR_LBMR_OPT_HDR_T_TYPE);
switch (opt_type)
{
case LBMR_LBMR_OPT_LEN_TYPE:
opt_len = dissect_lbmr_opt_len(tvb, curr_offset, pinfo, opt_tree);
break;
case LBMR_LBMR_OPT_SRC_ID_TYPE:
opt_len = dissect_lbmr_opt_src_id(tvb, curr_offset, pinfo, opt_tree);
break;
case LBMR_LBMR_OPT_SRC_TYPE_TYPE:
opt_len = dissect_lbmr_opt_src_type(tvb, curr_offset, pinfo, opt_tree);
break;
case LBMR_LBMR_OPT_VERSION_TYPE:
opt_len = dissect_lbmr_opt_version(tvb, curr_offset, pinfo, opt_tree);
break;
case LBMR_LBMR_OPT_LOCAL_DOMAIN_TYPE:
opt_len = dissect_lbmr_opt_local_domain(tvb, curr_offset, pinfo, opt_tree);
break;
default:
opt_len = dissect_lbmr_opt_unknown(tvb, curr_offset, pinfo, opt_tree);
break;
}
len += opt_len;
curr_offset += opt_len;
}
return (len);
}
static void lbmr_tap_queue_packet(packet_info * pinfo, const lbmr_contents_t * contents)
{
const lbmr_topic_contents_t * topic;
const lbmr_queue_contents_t * queue;
switch (contents->type)
{
case LBMR_CONTENTS_TOPIC:
topic = &(contents->contents.topic);
if (topic->tqr_count > 0)
{
tqr_node_t * tqr = topic->tqr;
while (tqr != NULL)
{
lbm_lbmr_topic_query_tap_info_t * tqr_tap = wmem_new0(wmem_packet_scope(), lbm_lbmr_topic_query_tap_info_t);
tqr_tap->size = (guint16) sizeof(lbm_lbmr_topic_query_tap_info_t);
tqr_tap->topic_length = (guint8)strlen(tqr->topic);
memcpy(tqr_tap->topic, tqr->topic, tqr_tap->topic_length);
tap_queue_packet(lbmr_topic_query_tap_handle, pinfo, (void *) tqr_tap);
tqr = tqr->next;
}
}
if (topic->tir_count > 0)
{
tir_node_t * tir = topic->tir;
while (tir != NULL)
{
lbm_lbmr_topic_advertisement_tap_info_t * tir_tap = wmem_new0(wmem_packet_scope(), lbm_lbmr_topic_advertisement_tap_info_t);
tir_tap->size = (guint16) sizeof(lbm_lbmr_topic_advertisement_tap_info_t);
tir_tap->topic_length = (guint8)strlen(tir->topic);
tir_tap->source_length = (guint8)strlen(tir->source_string);
tir_tap->topic_index = tir->idx;
memcpy(tir_tap->topic, tir->topic, tir_tap->topic_length);
memcpy(tir_tap->source, tir->source_string, tir_tap->source_length);
tap_queue_packet(lbmr_topic_advertisement_tap_handle, pinfo, (void *) tir_tap);
tir = tir->next;
}
}
if (topic->wctqr_count > 0)
{
wctqr_node_t * wctqr = topic->wctqr;
while (wctqr != NULL)
{
lbm_lbmr_pattern_query_tap_info_t * wctqr_tap = wmem_new0(wmem_packet_scope(), lbm_lbmr_pattern_query_tap_info_t);
wctqr_tap->size = (guint16) sizeof(lbm_lbmr_pattern_query_tap_info_t);
wctqr_tap->type = wctqr->type;
wctqr_tap->pattern_length = (guint8)strlen(wctqr->pattern);
memcpy(wctqr_tap->pattern, wctqr->pattern, wctqr_tap->pattern_length);
tap_queue_packet(lbmr_pattern_query_tap_handle, pinfo, (void *) wctqr_tap);
wctqr = wctqr->next;
}
}
break;
case LBMR_CONTENTS_QUEUE:
queue = &(contents->contents.queue);
if (queue->qqr_count > 0)
{
qqr_node_t * qqr = queue->qqr;
while (qqr != NULL)
{
lbm_lbmr_queue_query_tap_info_t * qqr_tap = wmem_new0(wmem_packet_scope(), lbm_lbmr_queue_query_tap_info_t);
qqr_tap->size = (guint16) sizeof(lbm_lbmr_queue_query_tap_info_t);
qqr_tap->queue_length = (guint8)strlen(qqr->queue);
memcpy(qqr_tap->queue, qqr->queue, qqr_tap->queue_length);
tap_queue_packet(lbmr_queue_advertisement_tap_handle, pinfo, (void *) qqr_tap);
qqr = qqr->next;
}
}
if (queue->qir_count > 0)
{
qir_node_t * qir = queue->qir;
while (qir != NULL)
{
lbm_lbmr_queue_advertisement_tap_info_t * qir_tap = wmem_new0(wmem_packet_scope(), lbm_lbmr_queue_advertisement_tap_info_t);
qir_tap->size = (guint16) sizeof(lbm_lbmr_queue_advertisement_tap_info_t);
qir_tap->port = qir->port;
qir_tap->queue_length = (guint8)strlen(qir->queue);
qir_tap->topic_length = (guint8)strlen(qir->topic);
memcpy(qir_tap->queue, qir->queue, qir_tap->queue_length);
memcpy(qir_tap->topic, qir->topic, qir_tap->topic_length);
tap_queue_packet(lbmr_queue_query_tap_handle, pinfo, (void *) qir_tap);
qir = qir->next;
}
}
break;
default:
break;
}
}
static int dissect_lbmr(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * user_data _U_)
{
proto_tree * lbmr_tree = NULL;
proto_item * ti = NULL;
int offset = 0;
guint8 ver_type;
guint8 ver;
guint8 type;
lbmr_contents_t * contents = NULL;
char * tag_name = NULL;
int total_len_dissected = 0;
int len_dissected = 0;
tvbuff_t * packet_tvb = NULL;
proto_item * lbmr_hdr_item = NULL;
proto_tree * lbmr_hdr_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LBMR");
if (lbmr_use_tag)
{
tag_name = lbmr_tag_find(pinfo);
}
col_clear(pinfo->cinfo, COL_INFO);
if (tag_name != NULL)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "[Tag: %s]", tag_name);
}
col_set_fence(pinfo->cinfo, COL_INFO);
ver_type = tvb_get_guint8(tvb, O_LBMR_HDR_T_VER_TYPE);
ver = LBMR_HDR_VER(ver_type);
type = LBMR_HDR_TYPE(ver_type);
offset = 0;
total_len_dissected = 0;
packet_tvb = tvb;
if ((ver_type & LBMR_HDR_TYPE_OPTS_MASK) != 0)
{
guint8 opt_type;
guint8 opt_len;
opt_type = tvb_get_guint8(tvb, -L_LBMR_LBMR_OPT_LEN_T + O_LBMR_LBMR_OPT_LEN_T_TYPE);
opt_len = tvb_get_guint8(tvb, -L_LBMR_LBMR_OPT_LEN_T + O_LBMR_LBMR_OPT_LEN_T_LEN);
if ((opt_type == LBMR_LBMR_OPT_LEN_TYPE) && (((gint)opt_len) == L_LBMR_LBMR_OPT_LEN_T))
{
gint opt_total_len = 0;
gint packet_len;
packet_len = tvb_reported_length_remaining(tvb, 0);
opt_total_len = (gint)tvb_get_ntohs(tvb, -L_LBMR_LBMR_OPT_LEN_T + O_LBMR_LBMR_OPT_LEN_T_TOTAL_LEN);
if (packet_len > opt_total_len)
{
gint tvb_len = packet_len - opt_total_len;
packet_tvb = tvb_new_subset_length(tvb, 0, tvb_len);
}
}
}
if (type == LBMR_HDR_TYPE_EXT)
{
guint8 ext_type = 0;
const gchar * ext_string;
proto_item * ext_type_item = NULL;
ext_type = tvb_get_guint8(tvb, O_LBMR_HDR_EXT_TYPE_T_EXT_TYPE);
ext_string = val_to_str(ext_type, lbmr_ext_packet_type, "Unknown(0x%02x)");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "ExtType %s", ext_string);
if (tag_name != NULL)
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_EXT_TYPE_T_VER_TYPE, -1, "LBM Topic Resolution Protocol (Tag: %s): Version %u, Type 0x%x (%s), ExtType %s",
tag_name, ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"), ext_string);
}
else
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_EXT_TYPE_T_VER_TYPE, -1, "LBM Topic Resolution Protocol: Version %u, Type 0x%x (%s), ExtType %s",
ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"), ext_string);
}
lbmr_tree = proto_item_add_subtree(ti, ett_lbmr);
if (tag_name != NULL)
{
proto_item * item = NULL;
item = proto_tree_add_string(lbmr_tree, hf_lbmr_tag, tvb, 0, 0, tag_name);
PROTO_ITEM_SET_GENERATED(item);
}
lbmr_hdr_item = proto_tree_add_item(lbmr_tree, hf_lbmr_hdr, tvb, 0, -1, ENC_NA);
lbmr_hdr_tree = proto_item_add_subtree(lbmr_hdr_item, ett_lbmr_hdr);
(void) format_ver_type(tvb, 0, pinfo, lbmr_hdr_tree);
ext_type_item = proto_tree_add_item(lbmr_hdr_tree, hf_lbmr_hdr_ext_type, tvb, O_LBMR_HDR_EXT_TYPE_T_EXT_TYPE, L_LBMR_HDR_EXT_TYPE_T_EXT_TYPE, ENC_BIG_ENDIAN);
switch (ext_type)
{
case LBMR_HDR_EXT_TYPE_UME_PROXY_SRC_ELECT:
len_dissected = dissect_lbmr_pser(packet_tvb, offset, pinfo, lbmr_tree);
break;
case LBMR_HDR_EXT_TYPE_UMQ_QUEUE_MGMT:
offset += L_LBMR_UMQ_QMGMT_HDR_T_VER_TYPE + L_LBMR_UMQ_QMGMT_HDR_T_EXT_TYPE;
total_len_dissected += L_LBMR_UMQ_QMGMT_HDR_T_VER_TYPE + L_LBMR_UMQ_QMGMT_HDR_T_EXT_TYPE;
len_dissected = lbmr_dissect_umq_qmgmt(packet_tvb, offset - 2, pinfo, lbmr_tree);
break;
case LBMR_HDR_EXT_TYPE_CONTEXT_INFO:
len_dissected = dissect_lbmr_ctxinfo(packet_tvb, offset, pinfo, lbmr_tree);
break;
case LBMR_HDR_EXT_TYPE_TOPIC_RES_REQUEST:
len_dissected = dissect_lbmr_topic_res_request(packet_tvb, offset, pinfo, lbmr_tree);
break;
case LBMR_HDR_EXT_TYPE_TNWG_MSG:
len_dissected = dissect_lbmr_tnwg(packet_tvb, offset, pinfo, lbmr_tree);
break;
case LBMR_HDR_EXT_TYPE_REMOTE_DOMAIN_ROUTE:
len_dissected = dissect_lbmr_remote_domain_route(packet_tvb, offset, pinfo, lbmr_tree);
break;
case LBMR_HDR_EXT_TYPE_REMOTE_CONTEXT_INFO:
len_dissected = dissect_lbmr_rctxinfo(packet_tvb, offset, pinfo, lbmr_tree);
break;
default:
len_dissected = L_LBMR_HDR_EXT_TYPE_T_VER_TYPE + L_LBMR_HDR_EXT_TYPE_T_EXT_TYPE;
expert_add_info_format(pinfo, ext_type_item, &ei_lbmr_analysis_invalid_value, "Unknown LBMR extended type 0x%02x", ext_type);
break;
}
offset += len_dissected;
total_len_dissected += len_dissected;
}
else
{
guint8 tqrs = 0;
guint16 tirs = 0;
gboolean rd_keepalive = FALSE;
gboolean topic_mgmt = FALSE;
gboolean client_rd_keepalive = FALSE;
gboolean zero_tirs_tqrs = FALSE;
proto_item * type_item = NULL;
tqrs = tvb_get_guint8(tvb, O_LBMR_HDR_T_TQRS);
tirs = tvb_get_ntohs(tvb, O_LBMR_HDR_T_TIRS);
if ((tqrs == 0) && (tirs == 0))
{
zero_tirs_tqrs = TRUE;
}
if ((type == LBMR_HDR_TYPE_NORMAL) && zero_tirs_tqrs)
{
rd_keepalive = TRUE;
}
else if (zero_tirs_tqrs && ((type == LBMR_HDR_TYPE_UCAST_RCV_ALIVE) || (type == LBMR_HDR_TYPE_UCAST_SRC_ALIVE)))
{
client_rd_keepalive = TRUE;
}
else if (type == LBMR_HDR_TYPE_TOPIC_MGMT)
{
topic_mgmt = TRUE;
}
switch (type)
{
case LBMR_HDR_TYPE_QUEUE_RES:
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "QQRs %u QIRs %" G_GUINT16_FORMAT, tqrs, tirs);
break;
default:
if (rd_keepalive)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "Unicast Resolver Keepalive");
}
else if (client_rd_keepalive)
{
if (type == LBMR_HDR_TYPE_UCAST_RCV_ALIVE)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "Receiver Alive");
}
else
{
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "Source Alive");
}
}
else if (topic_mgmt)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "Topic Management");
}
else
{
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "TQRs %u TIRs %" G_GUINT16_FORMAT, tqrs, tirs);
}
break;
}
switch (type)
{
case LBMR_HDR_TYPE_QUEUE_RES:
if (tag_name != NULL)
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_T_VER_TYPE, -1, "LBM Topic Resolution Protocol (Tag: %s): Version %u, Type 0x%x (%s) QQRs %u, QIRs %" G_GUINT16_FORMAT,
tag_name, ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"), tqrs, tirs);
}
else
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_T_VER_TYPE, -1, "LBM Topic Resolution Protocol: Version %u, Type 0x%x (%s) QQRs %u, QIRs %" G_GUINT16_FORMAT,
ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"), tqrs, tirs);
}
break;
default:
if (tag_name != NULL)
{
if (rd_keepalive)
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_T_VER_TYPE, -1, "LBM Topic Resolution Protocol (Tag: %s): Version %u, Type 0x%x (%s) Unicast Resolver Keepalive",
tag_name, ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"));
}
else if (topic_mgmt)
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_T_VER_TYPE, -1, "LBM Topic Resolution Protocol (Tag: %s): Version %u, Type 0x%x (%s) Topic Management",
tag_name, ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"));
}
else
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_T_VER_TYPE, -1, "LBM Topic Resolution Protocol (Tag: %s): Version %u, Type 0x%x (%s) TQRs %u, TIRs %" G_GUINT16_FORMAT,
tag_name, ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"), tqrs, tirs);
}
}
else
{
if (rd_keepalive)
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_T_VER_TYPE, -1, "LBM Topic Resolution Protocol: Version %u, Type 0x%x (%s) Unicast Resolver Keepalive",
ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"));
}
else if (topic_mgmt)
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_T_VER_TYPE, -1, "LBM Topic Resolution Protocol: Version %u, Type 0x%x (%s) Topic Management",
ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"));
}
else
{
ti = proto_tree_add_protocol_format(tree, proto_lbmr, tvb, O_LBMR_HDR_T_VER_TYPE, -1, "LBM Topic Resolution Protocol: Version %u, Type 0x%x (%s) TQRs %u, TIRs %" G_GUINT16_FORMAT,
ver, type, val_to_str(type, lbmr_packet_type, "Unknown(0x%02x)"), tqrs, tirs);
}
}
break;
}
lbmr_tree = proto_item_add_subtree(ti, ett_lbmr);
if (tag_name != NULL)
{
proto_item * item;
item = proto_tree_add_string(lbmr_tree, hf_lbmr_tag, tvb, 0, 0, tag_name);
PROTO_ITEM_SET_GENERATED(item);
}
lbmr_hdr_item = proto_tree_add_item(lbmr_tree, hf_lbmr_hdr, tvb, 0, -1, ENC_NA);
lbmr_hdr_tree = proto_item_add_subtree(lbmr_hdr_item, ett_lbmr_hdr);
type_item = format_ver_type(tvb, 0, pinfo, lbmr_hdr_tree);
switch (type)
{
case LBMR_HDR_TYPE_QUEUE_RES:
proto_tree_add_item(lbmr_hdr_tree, hf_lbmr_hdr_qqrs, tvb, O_LBMR_HDR_T_TQRS, L_LBMR_HDR_T_TQRS, ENC_BIG_ENDIAN);
proto_tree_add_item(lbmr_hdr_tree, hf_lbmr_hdr_qirs, tvb, O_LBMR_HDR_T_TIRS, L_LBMR_HDR_T_TIRS, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(lbmr_hdr_tree, hf_lbmr_hdr_tqrs, tvb, O_LBMR_HDR_T_TQRS, L_LBMR_HDR_T_TQRS, ENC_BIG_ENDIAN);
proto_tree_add_item(lbmr_hdr_tree, hf_lbmr_hdr_tirs, tvb, O_LBMR_HDR_T_TIRS, L_LBMR_HDR_T_TIRS, ENC_BIG_ENDIAN);
break;
}
offset = L_LBMR_HDR_T;
total_len_dissected = L_LBMR_HDR_T;
contents = wmem_new0(wmem_packet_scope(), lbmr_contents_t);
switch (type)
{
case LBMR_HDR_TYPE_QUEUE_RES:
contents->type = LBMR_CONTENTS_QUEUE;
if (tqrs > 0)
{
len_dissected = dissect_lbmr_qqrs(packet_tvb, offset, tqrs, pinfo, lbmr_tree, contents);
total_len_dissected += len_dissected;
offset += len_dissected;
}
if (tirs > 0)
{
len_dissected = dissect_lbmr_qirs(packet_tvb, offset, tirs, pinfo, lbmr_tree, contents);
total_len_dissected += len_dissected;
offset += len_dissected;
}
lbmr_tap_queue_packet(pinfo, contents);
break;
case LBMR_HDR_TYPE_NORMAL:
case LBMR_HDR_TYPE_WC_TQRS:
if (!rd_keepalive)
{
contents->type = LBMR_CONTENTS_TOPIC;
if (tqrs > 0)
{
gboolean wc_tqrs = FALSE;
if (type == LBMR_HDR_TYPE_WC_TQRS)
{
wc_tqrs = TRUE;
}
len_dissected = dissect_lbmr_tqrs(packet_tvb, offset, tqrs, pinfo, lbmr_tree, wc_tqrs, contents);
total_len_dissected += len_dissected;
offset += len_dissected;
}
if (tirs > 0)
{
len_dissected = dissect_lbmr_tirs(packet_tvb, offset, tirs, pinfo, lbmr_tree, "TIRs", contents);
total_len_dissected += len_dissected;
offset += len_dissected;
}
lbmr_tap_queue_packet(pinfo, contents);
}
break;
case LBMR_HDR_TYPE_TOPIC_MGMT:
len_dissected = dissect_lbmr_tmb(packet_tvb, offset, pinfo, lbmr_tree);
total_len_dissected += len_dissected;
offset += len_dissected;
break;
case LBMR_HDR_TYPE_UCAST_RCV_ALIVE:
case LBMR_HDR_TYPE_UCAST_SRC_ALIVE:
break;
default:
expert_add_info_format(pinfo, type_item, &ei_lbmr_analysis_invalid_value, "Unknown LBMR type 0x%02x", type);
break;
}
}
if ((tvb_reported_length_remaining(tvb, offset) > 0) && ((ver_type & LBMR_HDR_TYPE_OPTS_MASK) != 0))
{
len_dissected = dissect_lbmr_options(tvb, offset, pinfo, lbmr_tree);
total_len_dissected += len_dissected;
}
return (total_len_dissected);
}
static gboolean test_lbmr_packet(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * user_data _U_)
{
lbmr_tag_entry_t entry;
gboolean valid_packet = FALSE;
if (pinfo->ptype != PT_UDP)
{
return (FALSE);
}
if ((pinfo->dst.type != AT_IPv4) || (pinfo->dst.len != 4))
{
return (FALSE);
}
if (lbmr_use_tag)
{
if (lbmr_tag_find(pinfo) != NULL)
{
valid_packet = TRUE;
}
}
else
{
entry.name = NULL;
entry.mc_outgoing_udp_port = lbmr_mc_outgoing_udp_port;
entry.mc_incoming_udp_port = lbmr_mc_incoming_udp_port;
entry.mc_incoming_address = NULL;
entry.mc_incoming_address_val_h = lbmr_mc_incoming_address_host;
entry.mc_outgoing_address = NULL;
entry.mc_outgoing_address_val_h = lbmr_mc_outgoing_address_host;
entry.uc_port_high = lbmr_uc_port_high;
entry.uc_port_low = lbmr_uc_port_low;
entry.uc_dest_port = lbmr_uc_dest_port;
entry.uc_address = NULL;
entry.uc_address_val_h = lbmr_uc_address_host;
valid_packet = lbmr_match_packet(pinfo, &entry);
}
if (valid_packet)
{
dissect_lbmr(tvb, pinfo, tree, NULL);
return (TRUE);
}
return (FALSE);
}
void proto_register_lbmr(void)
{
static hf_register_info hf[] =
{
{ &hf_lbmr_tag,
{ "Tag", "lbmr.tag", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_hdr,
{ "Header", "lbmr.hdr", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_hdr_ver,
{ "Version", "lbmr.hdr.ver", FT_UINT8, BASE_DEC, NULL, LBMR_HDR_VER_VER_MASK, NULL, HFILL } },
{ &hf_lbmr_hdr_opt,
{ "Options", "lbmr.hdr.opts", FT_BOOLEAN, 8, TFS(&tfs_present_not_present), LBMR_HDR_TYPE_OPTS_MASK, "Set if LBMR options are present", HFILL } },
{ &hf_lbmr_hdr_type,
{ "Type", "lbmr.hdr.type", FT_UINT8, BASE_HEX, VALS(lbmr_packet_type), LBMR_HDR_VER_TYPE_MASK, NULL, HFILL } },
{ &hf_lbmr_hdr_tqrs,
{ "Topic Query Records", "lbmr.hdr.tqrs", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_hdr_tirs,
{ "Topic Information Records", "lbmr.hdr.tirs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_hdr_qqrs,
{ "Queue Query Records", "lbmr.hdr.qqrs", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_hdr_qirs,
{ "Queue Information Records", "lbmr.hdr.qirs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_hdr_ext_type,
{ "Extended Type", "lbmr.hdr.ext_type", FT_UINT8, BASE_HEX, VALS(lbmr_ext_packet_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_tqrs,
{ "TQRs", "lbmr.tqrs", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tqr,
{ "TQR", "lbmr.tqr", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tqr_pattern_type,
{ "Pattern Type", "lbmr.tqr.pattern_type", FT_UINT8, BASE_DEC, VALS(lbm_wildcard_pattern_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_tqr_pattern,
{ "Pattern", "lbmr.tqr.pattern", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tqr_name,
{ "Topic Name", "lbmr.tqr.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tirs,
{ "TIRs", "lbmr.tirs", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir,
{ "TIR", "lbmr.tir", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_name,
{ "Topic Name", "lbmr.tir.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_transport_opts,
{ "Transport Options Present", "lbmr.tir.transport_opts", FT_BOOLEAN, L_LBMR_TIR_T_TRANSPORT * 8, TFS(&tfs_set_notset), LBMR_TIR_OPTIONS, "Set if transport options are present", HFILL } },
{ &hf_lbmr_tir_transport_type,
{ "Transport Type", "lbmr.tir.transport_type", FT_UINT8, BASE_HEX, VALS(lbmr_transport_type), LBMR_TIR_TRANSPORT, NULL, HFILL } },
{ &hf_lbmr_tir_tlen,
{ "Transport Info Length", "lbmr.tir.tlen", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_ttl,
{ "TTL", "lbmr.tir.ttl", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_index,
{ "Index", "lbmr.tir.index", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_tcp,
{ "TCP Transport", "lbmr.tir.tcp", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_tcp_ip,
{ "Source IP", "lbmr.tir.tcp.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_tcp_session_id,
{ "Session ID", "lbmr.tir.tcp.session_id", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_tcp_port,
{ "Source Port", "lbmr.tir.tcp.port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrm,
{ "LBTRM Transport", "lbmr.tir.lbtrm", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrm_src_addr,
{ "Source IP", "lbmr.tir.lbtrm.srcip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrm_mcast_addr,
{ "Multicast IP", "lbmr.tir.lbtrm.mcastip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrm_session_id,
{ "Session ID", "lbmr.tir.lbtrm.sessid", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrm_udp_dest_port,
{ "Destination Port", "lbmr.tir.lbtrm.dport", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrm_src_ucast_port,
{ "Source Port", "lbmr.tir.lbtrm.sport", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtru,
{ "LBTRU Transport", "lbmr.tir.lbtru", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtru_ip,
{ "Source IP", "lbmr.tir.lbtru.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtru_port,
{ "Source Port", "lbmr.tir.lbtru.port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtru_session_id,
{ "Session ID", "lbmr.tir.lbtru.session_id", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtipc,
{ "LBTIPC Transport", "lbmr.tir.lbtipc", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtipc_host_id,
{ "Host ID", "lbmr.tir.lbtipc.host_id", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtipc_session_id,
{ "Session ID", "lbmr.tir.lbtipc.session_id", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtipc_xport_id,
{ "Transport ID", "lbmr.tir.lbtipc.xport_id", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrdma,
{ "LBTRDMA Transport", "lbmr.tir.lbtrdma", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrdma_ip,
{ "Source IP", "lbmr.tir.lbtrdma.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrdma_session_id,
{ "Session ID", "lbmr.tir.lbtrdma.session_id", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtrdma_port,
{ "Port", "lbmr.tir.lbtrdma.port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtsmx,
{ "LBTSMX Transport", "lbmr.tir.lbtsmx", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtsmx_host_id,
{ "Host ID", "lbmr.tir.lbtsmx.host_id", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtsmx_session_id,
{ "Session ID", "lbmr.tir.lbtsmx.session_id", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_lbtsmx_xport_id,
{ "Transport ID", "lbmr.tir.lbtsmx.xport_id", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_channel,
{ "Channel", "lbmr.tir.channel", FT_UINT64, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tir_unknown_transport,
{ "Unknown Transport", "lbmr.tir.unknown_transport", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topts,
{ "Options", "lbmr.topts", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_len,
{ "Length Option", "lbmr.topt.len", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_len_type,
{ "Type", "lbmr.topt.len.type", FT_UINT8, BASE_DEC, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_len_len,
{ "Length", "lbmr.topt.len.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_len_total_len,
{ "Total Length", "lbmr.topt.len.total_len", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume,
{ "UME Option", "lbmr.topt.ume", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_type,
{ "Type", "lbmr.topt.ume.type", FT_UINT8, BASE_DEC, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_len,
{ "Length", "lbmr.topt.ume.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_flags,
{ "Flags", "lbmr.topt.ume.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_flags_ignore,
{ "Ignore", "lbmr.topt.ume.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_UME_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_UME_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_ume_flags_latejoin,
{ "Late Join", "lbmr.topt.ume.flags.latejoin", FT_BOOLEAN, L_LBMR_TOPIC_OPT_UME_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_UME_FLAG_LATEJOIN, "If set, the source provides late join", HFILL } },
{ &hf_lbmr_topt_ume_flags_store,
{ "Store", "lbmr.topt.ume.flags.store", FT_BOOLEAN, L_LBMR_TOPIC_OPT_UME_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_UME_FLAG_STORE, "If set, one or more stores are specified", HFILL } },
{ &hf_lbmr_topt_ume_flags_qccap,
{ "Q/C Capable", "lbmr.topt.ume.flags.qccap", FT_BOOLEAN, L_LBMR_TOPIC_OPT_UME_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_UME_FLAG_QCCAP, "If set, the source supports quorun/consensus", HFILL } },
{ &hf_lbmr_topt_ume_flags_acktosrc,
{ "Send ACKs to Source", "lbmr.topt.ume.flags.acktosrc", FT_BOOLEAN, L_LBMR_TOPIC_OPT_UME_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_UME_FLAG_ACKTOSRC, "If set, receivers send ACKs to the source", HFILL } },
{ &hf_lbmr_topt_ume_store_tcp_port,
{ "Store TCP Port", "lbmr.topt.ume.store_tcp_port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_src_tcp_port,
{ "Source TCP Port", "lbmr.topt.ume.src_tcp_port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_tcp_addr,
{ "Store TCP Address", "lbmr.topt.ume.store_tcp_addr", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_src_tcp_addr,
{ "Source TCP Address", "lbmr.topt.ume.src_tcp_addr", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_src_reg_id,
{ "Source Registration ID", "lbmr.topt.ume.src_reg_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_transport_idx,
{ "Transport Index", "lbmr.topt.ume.transport_idx", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_high_seqnum,
{ "High Sequence Number", "lbmr.topt.ume.high_seqnum", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_low_seqnum,
{ "Low Sequence Number", "lbmr.topt.ume.low_seqnum", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store,
{ "UME Store Option", "lbmr.topt.ume_store", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_type,
{ "Type", "lbmr.topt.ume_store.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_len,
{ "Length", "lbmr.topt.ume_store.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_flags,
{ "Flags", "lbmr.topt.ume_store.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_flags_ignore,
{ "Ignore", "lbmr.topt.ume_store.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_UME_STORE_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_UME_STORE_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_grp_idx,
{ "Group Index", "lbmr.topt.ume_store.grp_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_store_tcp_port,
{ "Store TCP Port", "lbmr.topt.ume_store.store_tcp_port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_store_idx,
{ "Store Index", "lbmr.topt.ume_store.store_idx", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_store_ip_addr,
{ "Store IP Address", "lbmr.topt.ume_store.store_ip_addr", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_src_reg_id,
{ "Source Registration ID", "lbmr.topt.ume_store.src_reg_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_group,
{ "UME Store Group Option", "lbmr.topt.ume_store_group", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_group_type,
{ "Type", "lbmr.topt.ume_store_group.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_group_len,
{ "Length", "lbmr.topt.ume_store_group.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_group_flags,
{ "Flags", "lbmr.topt.ume_store_group.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_group_flags_ignore,
{ "Ignore", "lbmr.topt.ume_store_group.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_UME_STORE_GROUP_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_UME_STORE_GROUP_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_group_grp_idx,
{ "Group Index", "lbmr.topt.ume_store_group.grp_idx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_group_grp_sz,
{ "Group Size", "lbmr.topt.ume_store_group.grp_sz", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ume_store_group_reserved,
{ "Reserved", "lbmr.topt.ume_store_group.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin,
{ "Late Join Option", "lbmr.topt.latejoin", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_type,
{ "Type", "lbmr.topt.latejoin.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_len,
{ "Length", "lbmr.topt.latejoin.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_flags,
{ "Flags", "lbmr.topt.latejoin.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_flags_ignore,
{ "Ignore", "lbmr.topt.latejoin.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_LATEJOIN_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_LATEJOIN_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_flags_acktosrc,
{ "Send ACKs to Source", "lbmr.topt.latejoin.flags.acktosrc", FT_BOOLEAN, L_LBMR_TOPIC_OPT_LATEJOIN_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_LATEJOIN_FLAG_ACKTOSRC, "If set, ACKs are sent to source", HFILL } },
{ &hf_lbmr_topt_latejoin_src_tcp_port,
{ "Source TCP Port", "lbmr.topt.latejoin.src_tcp_port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_reserved,
{ "Reserved", "lbmr.topt.latejoin.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_src_ip_addr,
{ "Source IP Address", "lbmr.topt.latejoin.src_ip_addr", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_transport_idx,
{ "Transport Index", "lbmr.topt.latejoin.transport_idx", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_high_seqnum,
{ "High Sequence Number", "lbmr.topt.latejoin.high_seqnum", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_latejoin_low_seqnum,
{ "Low Sequence Number", "lbmr.topt.latejoin.low_seqnum", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_rcridx,
{ "Receiver Control Record Index Option", "lbmr.topt.umq_rcridx", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_rcridx_type,
{ "Type", "lbmr.topt.umq_rcridx.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_rcridx_len,
{ "Length", "lbmr.topt.umq_rcridx.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_rcridx_flags,
{ "Flags", "lbmr.topt.umq_rcridx.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_rcridx_flags_ignore,
{ "Ignore", "lbmr.topt.umq_rcridx.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_UMQ_RCRIDX_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_UMQ_RCRIDX_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_umq_rcridx_rcr_idx,
{ "Receiver Control Record Index", "lbmr.topt.umq_rcridx.rcr_idx", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo,
{ "Queue Info Option", "lbmr.topt.umq_qinfo", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_type,
{ "Type", "lbmr.topt.umq_qinfo.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_len,
{ "Length", "lbmr.topt.umq_qinfo.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_flags,
{ "Flags", "lbmr.topt.umq_qinfo.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_flags_ignore,
{ "Ignore", "lbmr.topt.umq_qinfo.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_UMQ_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_flags_queue,
{ "Queue", "lbmr.topt.umq_qinfo.flags.queue", FT_BOOLEAN, L_LBMR_TOPIC_OPT_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_UMQ_FLAG_QUEUE, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_flags_rcvlisten,
{ "Receiver Listen", "lbmr.topt.umq_qinfo.flags.rcvlisten", FT_BOOLEAN, L_LBMR_TOPIC_OPT_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_UMQ_FLAG_RCVLISTEN, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_flags_control,
{ "Control", "lbmr.topt.umq_qinfo.flags.control", FT_BOOLEAN, L_LBMR_TOPIC_OPT_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_UMQ_FLAG_CONTROL, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_flags_srcrcvlisten,
{ "Source Receiver Listen", "lbmr.topt.umq_qinfo.flags.srcrcvlisten", FT_BOOLEAN, L_LBMR_TOPIC_OPT_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_UMQ_FLAG_SRCRCVLISTEN, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_flags_participants_only,
{ "Participants Only", "lbmr.topt.umq_qinfo.flags.participants_only", FT_BOOLEAN, L_LBMR_TOPIC_OPT_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TOPIC_OPT_UMQ_FLAG_PARTICIPANTS_ONLY, NULL, HFILL } },
{ &hf_lbmr_topt_umq_qinfo_queue,
{ "Queue", "lbmr.topt.ume_qinfo.queue", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_cost,
{ "Cost Option", "lbmr.topt.cost", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_cost_type,
{ "Type", "lbmr.topt.cost.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_cost_len,
{ "Length", "lbmr.topt.cost.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_cost_flags,
{ "Flags", "lbmr.topt.cost.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_cost_flags_ignore,
{ "Ignore", "lbmr.topt.cost.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_COST_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_COST_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_cost_hop_count,
{ "Hop count", "lbmr.topt.cost.hop_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_cost_cost,
{ "Cost", "lbmr.topt.cost.cost", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_otid,
{ "Originating Transport ID Option", "lbmr.topt.otid", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_otid_type,
{ "Type", "lbmr.topt.otid.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_otid_len,
{ "Length", "lbmr.topt.otid.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_otid_flags,
{ "Flags", "lbmr.topt.otid.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_otid_flags_ignore,
{ "Ignore", "lbmr.topt.otid.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_OTID_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_OTID_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_otid_originating_transport,
{ "Originating Transport ID", "lbmr.topt.otid.originating_transport", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinst,
{ "Context Instance Option", "lbmr.topt.ctxinst", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinst_type,
{ "Type", "lbmr.topt.ctxinst.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinst_len,
{ "Length", "lbmr.topt.ctxinst.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinst_flags,
{ "Flags", "lbmr.topt.ctxinst.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinst_flags_ignore,
{ "Ignore", "lbmr.topt.ctxinst.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_CTXINST_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_CTXINST_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinst_res,
{ "Reserved", "lbmr.topt.ctxinst.res", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinst_ctxinst,
{ "Context Instance", "lbmr.topt.ctxinst.ctxinst", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinsts,
{ "Store Context Instance Option", "lbmr.topt.ctxinsts", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinsts_type,
{ "Type", "lbmr.topt.ctxinsts.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinsts_len,
{ "Length", "lbmr.topt.ctxinsts.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinsts_flags,
{ "Flags", "lbmr.topt.ctxinsts.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinsts_flags_ignore,
{ "Ignore", "lbmr.topt.ctxinsts.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_CTXINSTS_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_CTXINSTS_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinsts_idx,
{ "Index", "lbmr.topt.ctxinsts.idx", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinsts_ctxinst,
{ "Store Context Instance", "lbmr.topt.ctxinsts.ctxinsts", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb,
{ "ULB Option", "lbmr.topt.ulb", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_type,
{ "Type", "lbmr.topt.ulb.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_len,
{ "Length", "lbmr.topt.ulb.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_flags,
{ "Flags", "lbmr.topt.ulb.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_flags_ignore,
{ "Ignore", "lbmr.topt.ulb.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_ULB_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_ULB_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_queue_id,
{ "Queue ID", "lbmr.topt.ulb.queue_id", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_regid,
{ "Registration ID", "lbmr.topt.ulb.regid", FT_UINT64, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_ulb_src_id,
{ "ULB Source ID", "lbmr.topt.ulb.ulb_src_id", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_src_ip_addr,
{ "Source IP Address", "lbmr.topt.ulb.src_ip_addr", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_src_tcp_port,
{ "Source TCP Port", "lbmr.topt.ulb.src_tcp_port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ulb_reserved,
{ "Reserved", "lbmr.topt.ulb.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinstq,
{ "Queue Context Instance Option", "lbmr.topt.ctxinstq", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinstq_type,
{ "Type", "lbmr.topt.ctxinstq.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinstq_len,
{ "Length", "lbmr.topt.ctxinstq.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinstq_flags,
{ "Flags", "lbmr.topt.ctxinstq.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinstq_flags_ignore,
{ "Ignore", "lbmr.topt.ctxinstq.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_CTXINSTQ_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_CTXINSTQ_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinstq_idx,
{ "Index", "lbmr.topt.ctxinstq.idx", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_ctxinstq_ctxinst,
{ "Store Context Instance", "lbmr.topt.ctxinstq.ctxinstq", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_domain_id,
{ "Domain ID Option", "lbmr.topt.domain_id", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_domain_id_type,
{ "Type", "lbmr.topt.domain_id.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_domain_id_len,
{ "Length", "lbmr.topt.domain_id.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_domain_id_flags,
{ "Flags", "lbmr.topt.domain_id.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_domain_id_flags_ignore,
{ "Ignore", "lbmr.topt.domain_id.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_DOMAIN_ID_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_DOMAIN_ID_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_domain_id_domain_id,
{ "Domain ID", "lbmr.topt.domain_id.domain_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc,
{ "Extended Functionality Option", "lbmr.topt.exfunc", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc_type,
{ "Type", "lbmr.topt.exfunc.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc_len,
{ "Length", "lbmr.topt.exfunc.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc_flags,
{ "Flags", "lbmr.topt.exfunc.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc_flags_ignore,
{ "Ignore", "lbmr.topt.exfunc.flags.ignore", FT_BOOLEAN, L_LBMR_TOPIC_OPT_EXFUNC_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TOPIC_OPT_EXFUNC_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc_src_tcp_port,
{ "Source TCP Port", "lbmr.topt.exfunc.src_tcp_port", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc_reserved,
{ "Reserved", "lbmr.topt.exfunc.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc_src_ip_addr,
{ "Source IP Address", "lbmr.topt.exfunc.src_ip_addr", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc_functionality_flags,
{ "Functionality Flags", "lbmr.topt.exfunc.functionality_flags", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_exfunc_functionality_flags_ulb,
{ "ULB", "lbmr.topt.exfunc.functionality_flags.ulb", FT_BOOLEAN, L_LBMR_TOPIC_OPT_EXFUNC_T_FUNCTIONALITY_FLAGS * 8, TFS(&tfs_capable_not_capable), LBM_TOPIC_OPT_EXFUNC_FFLAG_ULB, "Set if ULB supported", HFILL } },
{ &hf_lbmr_topt_exfunc_functionality_flags_umq,
{ "UMQ", "lbmr.topt.exfunc.functionality_flags.umq", FT_BOOLEAN, L_LBMR_TOPIC_OPT_EXFUNC_T_FUNCTIONALITY_FLAGS * 8, TFS(&tfs_capable_not_capable), LBM_TOPIC_OPT_EXFUNC_FFLAG_UMQ, "Set if UMQ supported", HFILL } },
{ &hf_lbmr_topt_exfunc_functionality_flags_ume,
{ "UME", "lbmr.topt.exfunc.functionality_flags.ume", FT_BOOLEAN, L_LBMR_TOPIC_OPT_EXFUNC_T_FUNCTIONALITY_FLAGS * 8, TFS(&tfs_capable_not_capable), LBM_TOPIC_OPT_EXFUNC_FFLAG_UME, "Set if UME supported", HFILL } },
{ &hf_lbmr_topt_exfunc_functionality_flags_lj,
{ "Late Join", "lbmr.topt.exfunc.functionality_flags.lj", FT_BOOLEAN, L_LBMR_TOPIC_OPT_EXFUNC_T_FUNCTIONALITY_FLAGS * 8, TFS(&tfs_capable_not_capable), LBM_TOPIC_OPT_EXFUNC_FFLAG_LJ, "Set if late join supported", HFILL } },
{ &hf_lbmr_topt_unknown,
{ "Unknown Option", "lbmr.topt.unknown", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_unknown_type,
{ "Type", "lbmr.topt.unknown.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_topic_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_unknown_len,
{ "Length", "lbmr.topt.unknown.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_unknown_flags,
{ "Flags", "lbmr.topt.unknown.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topt_unknown_data,
{ "Data", "lbmr.topt.unknown.data", FT_BYTES, FT_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tmb,
{ "Topic Management Block", "lbmr.tmb", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tmb_len,
{ "Length", "lbmr.tmb.len", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tmb_tmrs,
{ "Topic Management Record Count", "lbmr.tmb.tmrs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tmb_tmr_list,
{ "Topic Management Records", "lbmr.tmb.tmr_list", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tmr,
{ "Topic Management Record", "lbmr.tmb.tmr", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tmr_len,
{ "Length", "lbmr.tmb.tmr.len", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tmr_type,
{ "TMR Type", "lbmr.tmb.tmr.type", FT_UINT8, BASE_DEC, VALS(lbmr_tmr_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_tmr_flags,
{ "Flags", "lbmr.tmb.tmr.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tmr_flags_response,
{ "Response", "lbmr.tmb.tmr.flags.response", FT_BOOLEAN, L_LBMR_TMR_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TMR_FLAG_RESPONSE, "Set if this is a response", HFILL } },
{ &hf_lbmr_tmr_flags_wildcard_pcre,
{ "PCRE pattern", "lbmr.tmb.tmr.flags.wildcard_pcre", FT_BOOLEAN, L_LBMR_TMR_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TMR_FLAG_WILDCARD_PCRE, "Set if topic is a PCRE pattern", HFILL } },
{ &hf_lbmr_tmr_flags_wildcard_regex,
{ "Regex pattern", "lbmr.tmb.tmr.flags.wildcard_regex", FT_BOOLEAN, L_LBMR_TMR_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TMR_FLAG_WILDCARD_REGEX, "Set if topic is a Regex pattern", HFILL } },
{ &hf_lbmr_tmr_name,
{ "Topic Name", "lbmr.tmb.tmr.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_dep_type,
{ "Dependent Type", "lbmr.pser.dep_type", FT_UINT16, BASE_DEC_HEX, VALS(lbmr_pser_dependent_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_len,
{ "Length", "lbmr.pser.len", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_flags,
{ "Flags", "lbmr.pser.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_flags_option,
{ "Option", "lbmr.pser.flags.option", FT_BOOLEAN, L_LBMR_PSER_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_PSER_OPT_FLAG, NULL, HFILL } },
{ &hf_lbmr_pser_source_ip,
{ "Source IP", "lbmr.pser.source_ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_store_ip,
{ "Store IP", "lbmr.pser.store_ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_transport_idx,
{ "Transport Index", "lbmr.pser.transport_idx", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_topic_idx,
{ "Topic Index", "lbmr.pser.topic_idx", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_source_port,
{ "Source Port", "lbmr.pser.source_port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_store_port,
{ "Store Port", "lbmr.pser.store_port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_topic,
{ "Topic", "lbmr.pser.topic", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_opts,
{ "Options", "lbmr.pser.opts", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_optlen,
{ "Option Length", "lbmr.pser.opt.optlen", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_optlen_type,
{ "Type", "lbmr.pser.opt.optlen.type", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_optlen_optlen,
{ "Options Length", "lbmr.pser.opt.optlen.optlen", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_opt_ctxinst,
{ "Context Instance Option", "lbmr.pser.opt.ctxinst", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_opt_ctxinst_len,
{ "Length", "lbmr.pser.opt.ctxinst.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_opt_ctxinst_type,
{ "Type", "lbmr.pser.opt.ctxinst.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_pser_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_pser_opt_ctxinst_ctxinst,
{ "Context Instance", "lbmr.pser.opt.ctxinst.ctxinst", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qqr,
{ "QQRs", "lbmr.qqr", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qqr_name,
{ "Queue name", "lbmr.qqr.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qirs,
{ "QIRs", "lbmr.qirs", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir,
{ "QIR", "lbmr.qir", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_name,
{ "Queue name", "lbmr.qir.qname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_topic_name,
{ "Topic name", "lbmr.qir.tname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_id,
{ "Queue ID", "lbmr.qir.queue_id", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_ver,
{ "Queue Version", "lbmr.qir.queue_ver", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_prev_ver,
{ "Queue Previous Version", "lbmr.qir.queue_prev_ver", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_option_flag,
{ "QIR Options Present", "lbmr.qir.opts", FT_BOOLEAN, L_LBMR_QIR_T_GRP_BLKS * 8, TFS(&tfs_set_notset), LBMR_QIR_OPTIONS, NULL, HFILL } },
{ &hf_lbmr_qir_grp_blks,
{ "Group Block Count", "lbmr.qir.grp_blks", FT_UINT16, BASE_DEC_HEX, NULL, LBMR_QIR_GRP_BLOCKS_MASK, NULL, HFILL } },
{ &hf_lbmr_qir_queue_blks,
{ "Queue Blocks", "lbmr.qir.queue_blks", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_grps,
{ "Groups", "lbmr.qir.grps", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_grp_blk,
{ "Group Block", "lbmr.qir.grp", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_grp_blk_grp_idx,
{ "Group Index", "lbmr.qir.grp.grp_idx", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_grp_blk_grp_sz,
{ "Group Size", "lbmr.qir.grp.grp_sz", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queues,
{ "Queues", "lbmr.qir.queues", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_blk,
{ "Queue Block", "lbmr.qir.queue", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_blk_ip,
{ "IP Address", "lbmr.qir.queue.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_blk_port,
{ "Port", "lbmr.qir.queue.port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_blk_idx,
{ "Index", "lbmr.qir.queue.idx", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_blk_grp_idx,
{ "Group Index", "lbmr.qir.queue.grp_idx", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_qir_queue_blk_reserved,
{ "Reserved", "lbmr.qir.queue.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opts,
{ "Options", "lbmr.opt", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_len,
{ "Length Option", "lbmr.opt.len", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_len_type,
{ "Type", "lbmr.opt.len.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_len_len,
{ "Length", "lbmr.opt.len.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_len_total_len,
{ "Total Length", "lbmr.opt.len.total_len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_id,
{ "Source ID Option", "lbmr.opt.src_id", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_id_type,
{ "Type", "lbmr.opt.src_id.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_id_len,
{ "Length", "lbmr.opt.src_id.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_id_flags,
{ "Flags", "lbmr.opt.src_id.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_id_flags_ignore,
{ "Ignore", "lbmr.opt.src_id.flags.ignore", FT_BOOLEAN, L_LBMR_LBMR_OPT_SRC_ID_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_LBMR_OPT_SRC_ID_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_opt_src_id_src_id,
{ "Source ID", "lbmr.opt.src_id.src_id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_type,
{ "Source Type Option", "lbmr.opt.src_type", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_type_type,
{ "Type", "lbmr.opt.src_type.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_type_len,
{ "Length", "lbmr.opt.src_type.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_type_flags,
{ "Flags", "lbmr.opt.src_type.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_src_type_flags_ignore,
{ "Ignore", "lbmr.opt.src_type.flags.ignore", FT_BOOLEAN, L_LBMR_LBMR_OPT_SRC_TYPE_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_LBMR_OPT_SRC_TYPE_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_opt_src_type_src_type,
{ "Source Type", "lbmr.opt.src_type.src_type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_option_source_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_version,
{ "Version Option", "lbmr.opt.version", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_version_type,
{ "Type", "lbmr.opt.version.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_version_len,
{ "Length", "lbmr.opt.version.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_version_flags,
{ "Flags", "lbmr.opt.version.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_version_flags_ignore,
{ "Ignore", "lbmr.opt.version.flags.ignore", FT_BOOLEAN, L_LBMR_LBMR_OPT_VERSION_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_LBMR_OPT_VERSION_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_opt_version_flags_ume,
{ "UME Capable", "lbmr.opt.version.flags.ume", FT_BOOLEAN, L_LBMR_LBMR_OPT_VERSION_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_LBMR_OPT_VERSION_FLAG_UME, "Set if UME capable", HFILL } },
{ &hf_lbmr_opt_version_flags_umq,
{ "UMQ Capable", "lbmr.opt.version.flags.umq", FT_BOOLEAN, L_LBMR_LBMR_OPT_VERSION_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_LBMR_OPT_VERSION_FLAG_UMQ, "Set if UMQ capable", HFILL } },
{ &hf_lbmr_opt_version_version,
{ "Version", "lbmr.opt.version.version", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_local_domain,
{ "Local Domain Option", "lbmr.opt.local_domain", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_local_domain_type,
{ "Type", "lbmr.opt.local_domain.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_local_domain_len,
{ "Length", "lbmr.opt.local_domain.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_local_domain_flags,
{ "Flags", "lbmr.opt.local_domain.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_local_domain_flags_ignore,
{ "Ignore", "lbmr.opt.local_domain.flags.ignore", FT_BOOLEAN, L_LBMR_LBMR_OPT_LOCAL_DOMAIN_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_LBMR_OPT_VERSION_FLAG_IGNORE, NULL, HFILL } },
{ &hf_lbmr_opt_local_domain_local_domain_id,
{ "Local Domain ID", "lbmr.opt.local_domain.local_domain_id", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_unknown,
{ "Unknown ID Option", "lbmr.opt.unknown", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_unknown_type,
{ "Type", "lbmr.opt.unknown.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_unknown_len,
{ "Length", "lbmr.opt.unknown.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_unknown_flags,
{ "Flags", "lbmr.opt.unknown.flags", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_opt_unknown_data,
{ "Data", "lbmr.opt.unknown.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topic_res_request_flags,
{ "Flags", "lbmr.topic_res_request.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_topic_res_request_flags_gw_remote_interest,
{ "Gateway Remote Interest", "lbmr.topic_res_request.flags.gw_remote_interest", FT_BOOLEAN, 8 * L_LBMR_TOPIC_RES_REQUEST_T_FLAGS, TFS(&tfs_set_notset), LBM_TOPIC_RES_REQUEST_GW_REMOTE_INTEREST, "Set if gateway remote interest is requested", HFILL } },
{ &hf_lbmr_topic_res_request_flags_context_query,
{ "Context Queries", "lbmr.topic_res_request.flags.context_query", FT_BOOLEAN, 8 * L_LBMR_TOPIC_RES_REQUEST_T_FLAGS, TFS(&tfs_set_notset), LBM_TOPIC_RES_REQUEST_CONTEXT_QUERY, "Set if context queries are requested", HFILL } },
{ &hf_lbmr_topic_res_request_flags_context_advertisement,
{ "Context Advertisements", "lbmr.topic_res_request.flags.context_advertisement", FT_BOOLEAN, 8 * L_LBMR_TOPIC_RES_REQUEST_T_FLAGS, TFS(&tfs_set_notset), LBM_TOPIC_RES_REQUEST_CONTEXT_ADVERTISEMENT, "Set if context advertisements are requested", HFILL } },
{ &hf_lbmr_topic_res_request_flags_gateway_meta,
{ "Gateway Meta Flag", "lbmr.topic_res_request.flags.gateway_meta", FT_BOOLEAN, 8 * L_LBMR_TOPIC_RES_REQUEST_T_FLAGS, TFS(&tfs_set_notset), LBM_TOPIC_RES_REQUEST_RESERVED1, NULL, HFILL } },
{ &hf_lbmr_topic_res_request_flags_advertisement,
{ "Advertisements", "lbmr.topic_res_request.flags.advertisement", FT_BOOLEAN, 8 * L_LBMR_TOPIC_RES_REQUEST_T_FLAGS, TFS(&tfs_set_notset), LBM_TOPIC_RES_REQUEST_ADVERTISEMENT, "Set if advertisements are requested", HFILL } },
{ &hf_lbmr_topic_res_request_flags_query,
{ "Queries", "lbmr.topic_res_request.flags.query", FT_BOOLEAN, 8 * L_LBMR_TOPIC_RES_REQUEST_T_FLAGS, TFS(&tfs_set_notset), LBM_TOPIC_RES_REQUEST_QUERY, "Set if queries are requested", HFILL } },
{ &hf_lbmr_topic_res_request_flags_wildcard_query,
{ "Wildcard Queries", "lbmr.topic_res_request.flags.wildcard_query", FT_BOOLEAN, 8 * L_LBMR_TOPIC_RES_REQUEST_T_FLAGS, TFS(&tfs_set_notset), LBM_TOPIC_RES_REQUEST_WILDCARD_QUERY, "Set if wildcard queries are requested", HFILL } },
{ &hf_lbmr_ctxinfo_len,
{ "Length", "lbmr.ctxinfo.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_ctxinfo_hop_count,
{ "Hop Count", "lbmr.ctxinfo.hop_count", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_ctxinfo_flags,
{ "Flags", "lbmr.ctxinfo.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_ctxinfo_flags_query,
{ "Query", "lbmr.ctxinfo.flags.query", FT_BOOLEAN, 16, TFS(&tfs_set_notset), LBMR_CTXINFO_QUERY_FLAG, "Set if query, clear if response", HFILL } },
{ &hf_lbmr_ctxinfo_flags_ip,
{ "IP Address", "lbmr.ctxinfo.flags.ip", FT_BOOLEAN, 16, TFS(&tfs_present_not_present), LBMR_CTXINFO_IP_FLAG, "Set if IP address is included", HFILL } },
{ &hf_lbmr_ctxinfo_flags_instance,
{ "Instance", "lbmr.ctxinfo.flags.instance", FT_BOOLEAN, 16, TFS(&tfs_present_not_present), LBMR_CTXINFO_INSTANCE_FLAG, "Set if context instance is included", HFILL } },
{ &hf_lbmr_ctxinfo_flags_tnwg_src,
{ "Gateway Source", "lbmr.ctxinfo.flags.tnwg_src", FT_BOOLEAN, 16, TFS(&tfs_set_notset), LBMR_CTXINFO_TNWG_SRC_FLAG, "Set if a gateway source", HFILL } },
{ &hf_lbmr_ctxinfo_flags_tnwg_rcv,
{ "Gateway Receiver", "lbmr.ctxinfo.flags.tnwg_rcv", FT_BOOLEAN, 16, TFS(&tfs_set_notset), LBMR_CTXINFO_TNWG_RCV_FLAG, "Set if a gateway receiver", HFILL } },
{ &hf_lbmr_ctxinfo_flags_proxy,
{ "Proxy", "lbmr.ctxinfo.flags.proxy", FT_BOOLEAN, 16, TFS(&tfs_set_notset), LBMR_CTXINFO_PROXY_FLAG, "Set if a proxy for another context", HFILL } },
{ &hf_lbmr_ctxinfo_flags_name,
{ "Name", "lbmr.ctxinfo.flags.name", FT_BOOLEAN, 16, TFS(&tfs_present_not_present), LBMR_CTXINFO_NAME_FLAG, "Set if context name is included", HFILL } },
{ &hf_lbmr_ctxinfo_port,
{ "Port", "lbmr.ctxinfo.port", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_ctxinfo_ip,
{ "IP Address", "lbmr.ctxinfo.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_ctxinfo_instance,
{ "Instance", "lbmr.ctxinfo.instance", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_ctxinfo_name,
{ "Name", "lbmr.ctxinfo.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_len,
{ "Length", "lbmr.tnwg.len", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_type,
{ "Type", "lbmr.tnwg.type", FT_UINT16, BASE_DEC_HEX, VALS(lbmr_tnwg_function_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_reserved,
{ "Reserved", "lbmr.tnwg.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_interest,
{ "Interest", "lbmr.tnwg.interest", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_interest_len,
{ "Length", "lbmr.tnwg.interest.len", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_interest_count,
{ "Record Count", "lbmr.tnwg.interest.count", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_interest_rec,
{ "Interest Record", "lbmr.tnwg.interest_rec", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_interest_rec_len,
{ "Length", "lbmr.tnwg.interest_rec.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_interest_rec_flags,
{ "Flags", "lbmr.tnwg.interest_rec.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_interest_rec_flags_pattern,
{ "Pattern", "lbmr.tnwg.interest_rec.flags.pattern", FT_BOOLEAN, L_LBMR_TNWG_INTEREST_REC_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TNWG_INTEREST_REC_PATTERN_FLAG, "Set if interest is for a pattern", HFILL } },
{ &hf_lbmr_tnwg_interest_rec_flags_cancel,
{ "Cancel", "lbmr.tnwg.interest_rec.flags.cancel", FT_BOOLEAN, L_LBMR_TNWG_INTEREST_REC_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TNWG_INTEREST_REC_CANCEL_FLAG, "Set if interest is being cancelled", HFILL } },
{ &hf_lbmr_tnwg_interest_rec_flags_refresh,
{ "Refresh", "lbmr.tnwg.interest_rec.flags.refresh", FT_BOOLEAN, L_LBMR_TNWG_INTEREST_REC_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_TNWG_INTEREST_REC_REFRESH_FLAG, "Set if interest is being refreshed", HFILL } },
{ &hf_lbmr_tnwg_interest_rec_pattype,
{ "Pattern Type", "lbmr.tnwg.interest_rec.pattype", FT_UINT8, BASE_DEC_HEX, VALS(lbm_wildcard_pattern_type_short), 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_interest_rec_domain_id,
{ "Domain ID", "lbmr.tnwg.interest_rec.domain_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_interest_rec_symbol,
{ "Symbol", "lbmr.tnwg.interest_rec.symbol", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_ctxinfo,
{ "Context Information", "lbmr.tnwg.ctxinfo", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_ctxinfo_len,
{ "Length", "lbmr.tnwg.ctxinfo.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_ctxinfo_hop_count,
{ "Hop Count", "lbmr.tnwg.ctxinfo.hop_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_ctxinfo_reserved,
{ "Reserved", "lbmr.tnwg.ctxinfo.reserved", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_ctxinfo_flags1,
{ "Flags1", "lbmr.tnwg.ctxinfo.flags1", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_ctxinfo_flags1_query,
{ "Query", "lbmr.tnwg.ctxinfo.flags1.query", FT_BOOLEAN, L_LBMR_TNWG_CTXINFO_T_FLAGS1 * 8, TFS(&tfs_set_notset), LBMR_TNWG_CTXINFO_QUERY_FLAG, "Set if a query, clear if a response", HFILL } },
{ &hf_lbmr_tnwg_ctxinfo_flags1_tnwg_src,
{ "TNWG Source", "lbmr.tnwg.ctxinfo.flags1.tnwg_src", FT_BOOLEAN, L_LBMR_TNWG_CTXINFO_T_FLAGS1 * 8, TFS(&tfs_set_notset), LBMR_TNWG_CTXINFO_TNWG_SRC_FLAG, "Set if a gateway source", HFILL } },
{ &hf_lbmr_tnwg_ctxinfo_flags1_tnwg_rcv,
{ "TNWG Receiver", "lbmr.tnwg.ctxinfo.flags1.tnwg_rcv", FT_BOOLEAN, L_LBMR_TNWG_CTXINFO_T_FLAGS1 * 8, TFS(&tfs_set_notset), LBMR_TNWG_CTXINFO_TNWG_RCV_FLAG, "Set if a gateway receiver", HFILL } },
{ &hf_lbmr_tnwg_ctxinfo_flags1_proxy,
{ "Proxy", "lbmr.tnwg.ctxinfo.flags1.proxy", FT_BOOLEAN, L_LBMR_TNWG_CTXINFO_T_FLAGS1 * 8, TFS(&tfs_set_notset), LBMR_TNWG_CTXINFO_PROXY_FLAG, "Set if a proxy for another context", HFILL } },
{ &hf_lbmr_tnwg_ctxinfo_flags2,
{ "Flags2", "lbmr.tnwg.ctxinfo.flags2", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_trreq,
{ "Topic Res Request", "lbmr.tnwg.trreq", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_trreq_len,
{ "Length", "lbmr.tnwg.trreq.len", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt,
{ "Unknown Option", "lbmr.tnwg.opt", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_type,
{ "Type", "lbmr.tnwg.opt.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_tnwg_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_len,
{ "Length", "lbmr.tnwg.opt.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_flags,
{ "Flags", "lbmr.tnwg.opt.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_flags_ignore,
{ "Ignore", "lbmr.tnwg.opt.flags.ignore", FT_BOOLEAN, L_LBMR_TNWG_OPT_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TNWG_OPT_IGNORE_FLAG, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_data,
{ "Data", "lbmr.tnwg.opt.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_ctxinst,
{ "Context Instance Option", "lbmr.tnwg.opt_ctxinst", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_ctxinst_type,
{ "Type", "lbmr.tnwg.opt_ctxinst.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_tnwg_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_ctxinst_len,
{ "Length", "lbmr.tnwg.opt_ctxinst.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_ctxinst_flags,
{ "Flags", "lbmr.tnwg.opt_ctxinst.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_ctxinst_flags_ignore,
{ "Ignore", "lbmr.tnwg.opt_ctxinst.flags.ignore", FT_BOOLEAN, L_LBMR_TNWG_OPT_CTXINST_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TNWG_OPT_IGNORE_FLAG, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_ctxinst_instance,
{ "Context Instance", "lbmr.tnwg.opt_ctxinst.instance", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_address,
{ "Address Option", "lbmr.tnwg.opt_address", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_address_type,
{ "Type", "lbmr.tnwg.opt_address.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_tnwg_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_address_len,
{ "Length", "lbmr.tnwg.opt_address.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_address_flags,
{ "Flags", "lbmr.tnwg.opt_address.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_address_flags_ignore,
{ "Ignore", "lbmr.tnwg.opt_address.flags.ignore", FT_BOOLEAN, L_LBMR_TNWG_OPT_ADDRESS_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TNWG_OPT_IGNORE_FLAG, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_address_port,
{ "Port", "lbmr.tnwg.opt_address.port", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_address_res,
{ "Reserved", "lbmr.tnwg.opt_address.res", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_address_ip,
{ "IP Address", "lbmr.tnwg.opt_address.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_domain,
{ "Domain Option", "lbmr.tnwg.opt_domain", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_domain_type,
{ "Type", "lbmr.tnwg.opt_domain.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_tnwg_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_domain_len,
{ "Length", "lbmr.tnwg.opt_domain.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_domain_flags,
{ "Flags", "lbmr.tnwg.opt_domain.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_domain_flags_ignore,
{ "Ignore", "lbmr.tnwg.opt_domain.flags.ignore", FT_BOOLEAN, L_LBMR_TNWG_OPT_DOMAIN_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TNWG_OPT_IGNORE_FLAG, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_domain_domain_id,
{ "Domain ID", "lbmr.tnwg.opt_domain.domain_id", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_name,
{ "Name Option", "lbmr.tnwg.opt_name", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_name_type,
{ "Type", "lbmr.tnwg.opt_name.type", FT_UINT8, BASE_HEX_DEC, VALS(lbmr_tnwg_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_name_len,
{ "Length", "lbmr.tnwg.opt_name.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_name_flags,
{ "Flags", "lbmr.tnwg.opt_name.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_name_flags_ignore,
{ "Ignore", "lbmr.tnwg.opt_name.flags.ignore", FT_BOOLEAN, L_LBMR_TNWG_OPT_T_FLAGS * 8, TFS(&lbm_ignore_flag), LBMR_TNWG_OPT_IGNORE_FLAG, NULL, HFILL } },
{ &hf_lbmr_tnwg_opt_name_name,
{ "Name", "lbmr.tnwg.opt_name.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_remote_domain_route_hdr_num_domains,
{ "Number of Domains", "lbmr.remote_domain_route.num_domains", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_remote_domain_route_hdr_ip,
{ "IP Address", "lbmr.remote_domain_route.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_remote_domain_route_hdr_port,
{ "Port", "lbmr.remote_domain_route.port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_remote_domain_route_hdr_reserved,
{ "Reserved", "lbmr.remote_domain_route.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_remote_domain_route_hdr_length,
{ "Length", "lbmr.remote_domain_route.length", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_remote_domain_route_hdr_domain,
{ "Domain", "lbmr.remote_domain_route.domain", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_len,
{ "Length", "lbmr.rctxinfo.len", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_num_recs,
{ "Number of Records", "lbmr.rctxinfo.num_recs", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_reserved,
{ "Reserved", "lbmr.rctxinfo.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec,
{ "Remote Context Information Record", "lbmr.rctxinfo.rec", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_len,
{ "Length", "lbmr.rctxinfo.rec.len", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_flags,
{ "Flags", "lbmr.rctxinfo.rec.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_flags_query,
{ "Query", "lbmr.rctxinfo.rec.flags.query", FT_BOOLEAN, L_LBMR_RCTXINFO_REC_T_FLAGS * 8, TFS(&tfs_set_notset), LBMR_RCTXINFO_REC_FLAG_QUERY, "Set if a query, clear if a response", HFILL } },
{ &hf_lbmr_rctxinfo_rec_address,
{ "Address Option", "lbmr.rctxinfo.rec.address", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_address_type,
{ "Type", "lbmr.rctxinfo.rec.address.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_rctxinfo_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_address_len,
{ "Length", "lbmr.rctxinfo.rec.address.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_address_flags,
{ "Flags", "lbmr.rctxinfo.rec.address.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_address_domain_id,
{ "Domain ID", "lbmr.rctxinfo.rec.address.domain_id", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_address_ip,
{ "Address", "lbmr.rctxinfo.rec.address.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_address_port,
{ "Port", "lbmr.rctxinfo.rec.address.port", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_address_res,
{ "Reserved", "lbmr.rctxinfo.rec.address.res", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_instance,
{ "Instance Option", "lbmr.rctxinfo.rec.instance", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_instance_type,
{ "Type", "lbmr.rctxinfo.rec.instance.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_rctxinfo_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_instance_len,
{ "Length", "lbmr.rctxinfo.rec.instance.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_instance_flags,
{ "Flags", "lbmr.rctxinfo.rec.instance.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_instance_instance,
{ "Instance", "lbmr.rctxinfo.rec.instance.instance", FT_BYTES, FT_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_odomain,
{ "Originating Domain Option", "lbmr.rctxinfo.rec.odomain", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_odomain_type,
{ "Type", "lbmr.rctxinfo.rec.odomain.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_rctxinfo_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_odomain_len,
{ "Length", "lbmr.rctxinfo.rec.odomain.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_odomain_flags,
{ "Flags", "lbmr.rctxinfo.rec.odomain.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_odomain_domain_id,
{ "Domain ID", "lbmr.rctxinfo.rec.odomain.domain_id", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_name,
{ "Name Option", "lbmr.rctxinfo.rec.name", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_name_type,
{ "Type", "lbmr.rctxinfo.rec.name.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_rctxinfo_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_name_len,
{ "Length", "lbmr.rctxinfo.rec.name.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_name_flags,
{ "Flags", "lbmr.rctxinfo.rec.name.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_name_name,
{ "Name", "lbmr.rctxinfo.rec.name.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_unknown,
{ "Unknown Option", "lbmr.rctxinfo.rec.unknown", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_unknown_type,
{ "Type", "lbmr.rctxinfo.rec.unknown.type", FT_UINT8, BASE_DEC_HEX, VALS(lbmr_rctxinfo_option_type), 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_unknown_len,
{ "Length", "lbmr.rctxinfo.rec.unknown.len", FT_UINT8, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_unknown_flags,
{ "Flags", "lbmr.rctxinfo.rec.unknown.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmr_rctxinfo_rec_unknown_data,
{ "Data", "lbmr.rctxinfo.rec.unknown.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_flags,
{ "Flags", "lbmr.qmgmt.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_flags_i_flag,
{ "Ignore", "lbmr.qmgmt.flags.i_flag", FT_BOOLEAN, L_UMQ_QMGMT_HDR_T_FLAGS * 8, TFS(&lbm_ignore_flag), UMQ_QMGMT_HDR_I_FLAG, NULL, HFILL } },
{ &hf_qmgmt_flags_n_flag,
{ "Queue Name", "lbmr.qmgmt.flags.n_flag", FT_BOOLEAN, L_UMQ_QMGMT_HDR_T_FLAGS * 8, TFS(&tfs_present_not_present), UMQ_QMGMT_HDR_N_FLAG, "Set if queue name is present", HFILL } },
{ &hf_qmgmt_flags_il_l_flag,
{ "New Instance List", "lbmr.qmgmt.flags.il_l_flag", FT_BOOLEAN, L_UMQ_QMGMT_HDR_T_FLAGS * 8, TFS(&tfs_set_notset), UMQ_QMGMT_HDR_IL_L_FLAG, "Set if contains a new instance list", HFILL } },
{ &hf_qmgmt_flags_il_k_flag,
{ "Keepalive Requested", "lbmr.qmgmt.flags.il_k_flag", FT_BOOLEAN, L_UMQ_QMGMT_HDR_T_FLAGS * 8, TFS(&tfs_set_notset), UMQ_QMGMT_HDR_IL_K_FLAG, "Set if a keepalive requester", HFILL } },
{ &hf_qmgmt_pckt_type,
{ "Packet Type", "lbmr.qmgmt.pckt_type", FT_UINT8, BASE_HEX_DEC, VALS(umq_qmgmt_packet_type), 0x0, NULL, HFILL } },
{ &hf_qmgmt_cfgsig,
{ "Configuration Signature", "lbmr.qmgmt.cfg_sig", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_queue_id,
{ "Queue ID", "lbmr.qmgmt.queue_id", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_queue_ver,
{ "Queue Version", "lbmr.qmgmt.queue_ver", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_ip,
{ "IP Address", "lbmr.qmgmt.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_port,
{ "Port", "lbmr.qmgmt.port", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_inst_idx,
{ "Instance Index", "lbmr.qmgmt.inst_idx", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_grp_idx,
{ "Group Index", "lbmr.qmgmt.grp_idx", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_pckt_type_dep16,
{ "Packet-Type Dependent Data", "lbmr.qmgmt.pckt_type_dep16", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il_num_insts,
{ "Number of IL Instances", "lbmr.qmgmt.il_num_insts", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_jrej_code,
{ "Join Rejection Code", "lbmr.qmgmt.jrej_code", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_ev_bias,
{ "EV Bias", "lbmr.qmgmt.ev_bias", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il,
{ "Instance List Header", "lbmr.qmgmt.il", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il_highest_rcr_tsp,
{ "Highest RCR TSP", "lbmr.qmgmt.il.highest_rcr_tsp", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il_inst,
{ "Instance Header", "lbmr.qmgmt.il_inst", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il_inst_ip,
{ "IP", "lbmr.qmgmt.il_inst.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il_inst_port,
{ "Port", "lbmr.qmgmt.il_inst.port", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il_inst_inst_idx,
{ "Instance Index", "lbmr.qmgmt.il_inst.inst_idx", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il_inst_grp_idx,
{ "Group Index", "lbmr.qmgmt.il_inst.grp_idx", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il_inst_flags,
{ "Flags", "lbmr.qmgmt.il_inst.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_il_inst_flags_m_flag,
{ "Master", "lbmr.qmgmt.il_inst.flags.m_flag", FT_BOOLEAN, L_UMQ_QMGMT_IL_INST_HDR_T_FLAGS * 8, TFS(&tfs_set_notset), UMQ_QMGMT_HDR_IL_INST_M_FLAG, "Set if the master queue", HFILL } },
{ &hf_qmgmt_il_inst_flags_q_flag,
{ "Queue Election Master", "lbmr.qmgmt.il_inst.flags.q_flag", FT_BOOLEAN, L_UMQ_QMGMT_IL_INST_HDR_T_FLAGS * 8, TFS(&tfs_set_notset), UMQ_QMGMT_HDR_IL_INST_Q_FLAG, "Set if a queue election master", HFILL } },
{ &hf_qmgmt_il_inst_flags_p_flag,
{ "Post Election Master", "lbmr.qmgmt.il_inst.flags.p_flag", FT_BOOLEAN, L_UMQ_QMGMT_IL_INST_HDR_T_FLAGS * 8, TFS(&tfs_set_notset), UMQ_QMGMT_HDR_IL_INST_P_FLAG, "Set if a post election master", HFILL } },
{ &hf_qmgmt_ec,
{ "Election Call Header", "lbmr.qmgmt.ec", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_ec_queue_new_ver,
{ "Queue New Version", "lbmr.qmgmt.ec.queue_new_ver", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_ev,
{ "Election Vote Header", "lbmr.qmgmt.ev", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_ev_highest_rcr_tsp,
{ "Highest RCR TSP", "lbmr.qmgmt.ev.highest_rcr_tsp", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_ev_age,
{ "Age", "lbmr.qmgmt.ev.age", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_qro,
{ "Queue Resume Operation Header", "lbmr.qmgmt.qro", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_qro_highest_rcr_tsp,
{ "Highest RCR TSP", "lbmr.qmgmt.qro.highest_rcr_tsp", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_qmgmt_qname,
{ "Queue Name", "lbmr.qmgmt.qname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } }
};
static gint * ett[] =
{
&ett_lbmr,
&ett_lbmr_hdr,
&ett_lbmr_opts,
&ett_lbmr_opt_src_id,
&ett_lbmr_opt_src_id_flags,
&ett_lbmr_opt_len,
&ett_lbmr_opt_src_type,
&ett_lbmr_opt_src_type_flags,
&ett_lbmr_opt_version,
&ett_lbmr_opt_version_flags,
&ett_lbmr_opt_local_domain,
&ett_lbmr_opt_local_domain_flags,
&ett_lbmr_opt_unknown,
&ett_lbmr_tqrs,
&ett_lbmr_tqr,
&ett_lbmr_tirs,
&ett_lbmr_tir,
&ett_lbmr_tir_tcp,
&ett_lbmr_tir_lbtrm,
&ett_lbmr_tir_lbtru,
&ett_lbmr_tir_lbtipc,
&ett_lbmr_tir_lbtrdma,
&ett_lbmr_tir_lbtsmx,
&ett_lbmr_topts,
&ett_lbmr_topt_len,
&ett_lbmr_topt_ume,
&ett_lbmr_topt_ume_flags,
&ett_lbmr_topt_ume_store,
&ett_lbmr_topt_ume_store_flags,
&ett_lbmr_topt_ume_store_group,
&ett_lbmr_topt_ume_store_group_flags,
&ett_lbmr_topt_latejoin,
&ett_lbmr_topt_latejoin_flags,
&ett_lbmr_topt_umq_rcridx,
&ett_lbmr_topt_umq_rcridx_flags,
&ett_lbmr_topt_umq_qinfo,
&ett_lbmr_topt_umq_qinfo_flags,
&ett_lbmr_topt_cost,
&ett_lbmr_topt_cost_flags,
&ett_lbmr_topt_otid,
&ett_lbmr_topt_otid_flags,
&ett_lbmr_topt_ctxinst,
&ett_lbmr_topt_ctxinst_flags,
&ett_lbmr_topt_ctxinsts,
&ett_lbmr_topt_ctxinsts_flags,
&ett_lbmr_topt_ulb,
&ett_lbmr_topt_ulb_flags,
&ett_lbmr_topt_ctxinstq,
&ett_lbmr_topt_ctxinstq_flags,
&ett_lbmr_topt_domain_id,
&ett_lbmr_topt_domain_id_flags,
&ett_lbmr_topt_exfunc,
&ett_lbmr_topt_exfunc_flags,
&ett_lbmr_topt_exfunc_functionality_flags,
&ett_lbmr_topt_unknown,
&ett_lbmr_tmb,
&ett_lbmr_tmrs,
&ett_lbmr_tmr,
&ett_lbmr_tmr_flags,
&ett_lbmr_pser_flags,
&ett_lbmr_pser_opts,
&ett_lbmr_pser_opt_len,
&ett_lbmr_pser_opt_ctxinst,
&ett_lbmr_qqrs,
&ett_lbmr_qirs,
&ett_lbmr_qir,
&ett_lbmr_qir_options,
&ett_lbmr_qir_grp_blk,
&ett_lbmr_qir_queue_blk,
&ett_lbmr_qir_grp,
&ett_lbmr_qir_queue,
&ett_lbmr_topic_res_request_flags,
&ett_lbmr_ctxinfo_flags,
&ett_lbmr_tnwg,
&ett_lbmr_tnwg_interest,
&ett_lbmr_tnwg_interest_rec,
&ett_lbmr_tnwg_interest_rec_flags,
&ett_lbmr_tnwg_ctxinfo,
&ett_lbmr_tnwg_ctxinfo_flags1,
&ett_lbmr_tnwg_trreq,
&ett_lbmr_tnwg_ctxinst_opt,
&ett_lbmr_tnwg_ctxinst_opt_flags,
&ett_lbmr_tnwg_address_opt,
&ett_lbmr_tnwg_address_opt_flags,
&ett_lbmr_tnwg_domain_opt,
&ett_lbmr_tnwg_domain_opt_flags,
&ett_lbmr_tnwg_name_opt,
&ett_lbmr_tnwg_name_opt_flags,
&ett_lbmr_tnwg_unknown_opt,
&ett_lbmr_tnwg_unknown_opt_flags,
&ett_lbmr_remote_domain_route_hdr,
&ett_lbmr_rctxinfo,
&ett_lbmr_rctxinfo_rec,
&ett_lbmr_rctxinfo_rec_flags,
&ett_lbmr_rctxinfo_rec_address,
&ett_lbmr_rctxinfo_rec_instance,
&ett_lbmr_rctxinfo_rec_odomain,
&ett_lbmr_rctxinfo_rec_name,
&ett_lbmr_rctxinfo_rec_unknown,
&ett_qmgmt_flags,
&ett_qmgmt_il,
&ett_qmgmt_il_inst,
&ett_qmgmt_il_inst_flags,
&ett_qmgmt_ec,
&ett_qmgmt_ev,
&ett_qmgmt_qro
};
static ei_register_info ei[] =
{
{ &ei_lbmr_analysis_length_incorrect, { "lbmr.analysis.length_incorrect", PI_MALFORMED, PI_ERROR, "Header length incorrect", EXPFILL } },
{ &ei_lbmr_analysis_invalid_value, { "lbmr.analysis.invalid_value", PI_UNDECODED, PI_WARN, "Invalid value", EXPFILL } },
{ &ei_lbmr_analysis_zero_len_option, { "lbmr.analysis.zero_len_option", PI_MALFORMED, PI_ERROR, "Zero-length LBMR option", EXPFILL } },
};
module_t * lbmr_module;
struct in_addr addr;
uat_t * tag_uat;
expert_module_t * expert_lbmr;
proto_lbmr = proto_register_protocol("LBM Topic Resolution Protocol",
"LBMR", "lbmr");
proto_register_field_array(proto_lbmr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_lbmr = expert_register_protocol(proto_lbmr);
expert_register_field_array(expert_lbmr, ei, array_length(ei));
lbmr_module = prefs_register_protocol_subtree("29West", proto_lbmr, proto_reg_handoff_lbmr);
prefs_register_uint_preference(lbmr_module,
"mc_incoming_port",
"Incoming multicast UDP port (default " LBMR_DEFAULT_MC_INCOMING_UDP_PORT_STRING ")",
"Set the UDP port for incoming multicast topic resolution (context resolver_multicast_incoming_port)",
10,
&global_lbmr_mc_incoming_udp_port);
inet_aton(LBMR_DEFAULT_MC_INCOMING_ADDRESS, &addr);
lbmr_mc_incoming_address_host = g_ntohl(addr.s_addr);
prefs_register_string_preference(lbmr_module,
"mc_incoming_address",
"Incoming multicast address (default " LBMR_DEFAULT_MC_INCOMING_ADDRESS ")",
"Set the multicast address for incoming multicast topic resolution (context resolver_multicast_incoming_address)",
&global_lbmr_mc_incoming_address);
prefs_register_uint_preference(lbmr_module,
"mc_outgoing_port",
"Outgoing multicast UDP port (default " LBMR_DEFAULT_MC_OUTGOING_UDP_PORT_STRING ")",
"Set the UDP port for outgoing multicast topic resolution (context resolver_multicast_outgoing_port)",
10,
&global_lbmr_mc_outgoing_udp_port);
inet_aton(LBMR_DEFAULT_MC_OUTGOING_ADDRESS, &addr);
lbmr_mc_outgoing_address_host = g_ntohl(addr.s_addr);
prefs_register_string_preference(lbmr_module,
"mc_outgoing_address",
"Outgoing multicast address (default " LBMR_DEFAULT_MC_OUTGOING_ADDRESS ")",
"Set the multicast address for outgoing multicast topic resolution (context resolver_multicast_outgoing_address)",
&global_lbmr_mc_outgoing_address);
prefs_register_uint_preference(lbmr_module,
"uc_port_low",
"Unicast UDP port low (default " LBMR_DEFAULT_UC_PORT_LOW_STRING ")",
"Set the low UDP port for unicast topic resolution (context resolver_unicast_port_low)",
10,
&global_lbmr_uc_port_low);
prefs_register_uint_preference(lbmr_module,
"uc_port_high",
"Unicast UDP port high (default " LBMR_DEFAULT_UC_PORT_HIGH_STRING ")",
"Set the high UDP port for unicast topic resolution (context resolver_unicast_port_high)",
10,
&global_lbmr_uc_port_high);
prefs_register_uint_preference(lbmr_module,
"uc_dest_port",
"Unicast UDP destination port (default " LBMR_DEFAULT_UC_DEST_PORT_STRING ")",
"Set the destination port for unicast topic resolution (context resolver_unicast_destination_port)",
10,
&global_lbmr_uc_dest_port);
inet_aton(LBMR_DEFAULT_UC_ADDRESS, &addr);
lbmr_uc_address_host = g_ntohl(addr.s_addr);
prefs_register_string_preference(lbmr_module,
"uc_address",
"Unicast resolver address (default " LBMR_DEFAULT_UC_ADDRESS ")",
"Set the address of the unicast resolver daemon (context resolver_unicast_address)",
&global_lbmr_uc_address);
prefs_register_bool_preference(lbmr_module,
"use_lbmr_domain",
"Use LBMR tag table",
"Use table of LBMR tags to decode the packet instead of above values",
&global_lbmr_use_tag);
tag_uat = uat_new("LBMR tag definitions",
sizeof(lbmr_tag_entry_t),
"lbmr_domains",
TRUE,
(void * *)&lbmr_tag_entry,
&lbmr_tag_count,
UAT_AFFECTS_DISSECTION,
NULL,
lbmr_tag_copy_cb,
lbmr_tag_update_cb,
lbmr_tag_free_cb,
NULL,
NULL,
lbmr_tag_array);
prefs_register_uat_preference(lbmr_module,
"tnw_lbmr_tags",
"LBMR Tags",
"A table to define LBMR tags",
tag_uat);
lbmr_topic_advertisement_tap_handle = register_tap(LBMR_TOPIC_ADVERTISEMENT_TAP_STRING);
lbmr_topic_query_tap_handle = register_tap(LBMR_TOPIC_QUERY_TAP_STRING);
lbmr_pattern_query_tap_handle = register_tap(LBMR_PATTERN_QUERY_TAP_STRING);
lbmr_queue_advertisement_tap_handle = register_tap(LBMR_QUEUE_ADVERTISEMENT_TAP_STRING);
lbmr_queue_query_tap_handle = register_tap(LBMR_QUEUE_QUERY_TAP_STRING);
stats_tree_register(LBMR_TOPIC_ADVERTISEMENT_TAP_STRING,
"lbmr_topic_ads_topic",
lbmr_stat_tree_name_topic_ads_topic,
0,
lbmr_topic_ads_topic_stats_tree_packet,
lbmr_topic_ads_topic_stats_tree_init,
NULL);
stats_tree_register(LBMR_TOPIC_ADVERTISEMENT_TAP_STRING,
"lbmr_topic_ads_source",
lbmr_stat_tree_name_topic_ads_source,
0,
lbmr_topic_ads_source_stats_tree_packet,
lbmr_topic_ads_source_stats_tree_init,
NULL);
stats_tree_register(LBMR_TOPIC_ADVERTISEMENT_TAP_STRING,
"lbmr_topic_ads_transport",
lbmr_stat_tree_name_topic_ads_transport,
0,
lbmr_topic_ads_transport_stats_tree_packet,
lbmr_topic_ads_transport_stats_tree_init,
NULL);
stats_tree_register(LBMR_TOPIC_QUERY_TAP_STRING,
"lbmr_topic_queries_topic",
lbmr_stat_tree_name_topic_queries_topic,
0,
lbmr_topic_queries_topic_stats_tree_packet,
lbmr_topic_queries_topic_stats_tree_init,
NULL);
stats_tree_register(LBMR_TOPIC_QUERY_TAP_STRING,
"lbmr_topic_queries_receiver",
lbmr_stat_tree_name_topic_queries_receiver,
0,
lbmr_topic_queries_receiver_stats_tree_packet,
lbmr_topic_queries_receiver_stats_tree_init,
NULL);
stats_tree_register(LBMR_PATTERN_QUERY_TAP_STRING,
"lbmr_topic_queries_pattern",
lbmr_stat_tree_name_topic_queries_pattern,
0,
lbmr_topic_queries_pattern_stats_tree_packet,
lbmr_topic_queries_pattern_stats_tree_init,
NULL);
stats_tree_register(LBMR_PATTERN_QUERY_TAP_STRING,
"lbmr_topic_queries_pattern_receiver",
lbmr_stat_tree_name_topic_queries_pattern_receiver,
0,
lbmr_topic_queries_pattern_receiver_stats_tree_packet,
lbmr_topic_queries_pattern_receiver_stats_tree_init,
NULL);
stats_tree_register(LBMR_QUEUE_ADVERTISEMENT_TAP_STRING,
"lbmr_queue_ads_queue",
lbmr_stat_tree_name_queue_ads_queue,
0,
lbmr_queue_ads_queue_stats_tree_packet,
lbmr_queue_ads_queue_stats_tree_init,
NULL);
stats_tree_register(LBMR_QUEUE_ADVERTISEMENT_TAP_STRING,
"lbmr_queue_ads_source",
lbmr_stat_tree_name_queue_ads_source,
0,
lbmr_queue_ads_source_stats_tree_packet,
lbmr_queue_ads_source_stats_tree_init,
NULL);
stats_tree_register(LBMR_QUEUE_QUERY_TAP_STRING,
"lbmr_queue_queries_queue",
lbmr_stat_tree_name_queue_queries_queue,
0,
lbmr_queue_queries_queue_stats_tree_packet,
lbmr_queue_queries_queue_stats_tree_init,
NULL);
stats_tree_register(LBMR_QUEUE_QUERY_TAP_STRING,
"lbmr_queue_queries_receiver",
lbmr_stat_tree_name_queue_queries_receiver,
0,
lbmr_queue_queries_receiver_stats_tree_packet,
lbmr_queue_queries_receiver_stats_tree_init,
NULL);
lbm_topic_init();
lbtsmx_transport_init();
lbtipc_transport_init();
lbtrdma_transport_init();
}
void proto_reg_handoff_lbmr(void)
{
static gboolean already_registered = FALSE;
struct in_addr addr;
if (!already_registered)
{
lbmr_dissector_handle = create_dissector_handle(dissect_lbmr, proto_lbmr);
dissector_add_for_decode_as_with_preference("udp.port", lbmr_dissector_handle);
heur_dissector_add("udp", test_lbmr_packet, "LBM Topic Resolution over UDP", "lbmr_udp", proto_lbmr, HEURISTIC_ENABLE);
}
lbmr_mc_incoming_udp_port = global_lbmr_mc_incoming_udp_port;
lbmr_mc_outgoing_udp_port = global_lbmr_mc_outgoing_udp_port;
inet_aton(global_lbmr_mc_incoming_address, &addr);
lbmr_mc_incoming_address_host = g_ntohl(addr.s_addr);
inet_aton(global_lbmr_mc_outgoing_address, &addr);
lbmr_mc_outgoing_address_host = g_ntohl(addr.s_addr);
if (global_lbmr_uc_port_low <= global_lbmr_uc_port_high)
{
lbmr_uc_port_high = global_lbmr_uc_port_high;
lbmr_uc_port_low = global_lbmr_uc_port_low;
}
lbmr_uc_dest_port = global_lbmr_uc_dest_port;
inet_aton(global_lbmr_uc_address, &addr);
lbmr_uc_address_host = g_ntohl(addr.s_addr);
lbmr_use_tag = global_lbmr_use_tag;
already_registered = TRUE;
}
