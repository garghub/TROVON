static void lbm_init(void)
{
lbm_channel_reset();
}
void proto_register_lbm(void)
{
register_init_routine(lbm_init);
}
void lbm_channel_reset(void)
{
lbm_next_channel_value = 1;
}
guint64 lbm_channel_assign(guint8 channel_type)
{
guint64 ch;
guint64 ch_counter = lbm_next_channel_value++;
if (lbm_next_channel_value == LBM_CHANNEL_MAX_VALUE)
{
lbm_next_channel_value = 1;
}
ch = ((guint64)((ch_counter & LBM_CHANNEL_VALUE_LIMIT_MASK) << LBM_CHANNEL_VALUE_SHIFT_COUNT)) | channel_type;
return (ch);
}
gboolean lbm_channel_is_transport(guint64 channel)
{
guint8 ch_type;
ch_type = LBM_CHANNEL_TYPE(channel);
switch (ch_type)
{
case LBM_CHANNEL_TRANSPORT_LBTTCP:
case LBM_CHANNEL_TRANSPORT_LBTRU:
case LBM_CHANNEL_TRANSPORT_LBTRM:
case LBM_CHANNEL_TRANSPORT_LBTIPC:
case LBM_CHANNEL_TRANSPORT_LBTRDMA:
case LBM_CHANNEL_TRANSPORT_LBTSMX:
return (TRUE);
break;
default:
break;
}
return (FALSE);
}
guint8 lbm_channel_type(guint64 channel)
{
guint8 ch_type;
ch_type = LBM_CHANNEL_TYPE(channel);
return (ch_type);
}
guint64 lbm_channel_assign_unknown_transport_source_lbttcp(void)
{
return (LBM_CHANNEL_UNKNOWN_TRANSPORT_SOURCE_LBTTCP);
}
guint64 lbm_channel_assign_unknown_transport_client_lbttcp(void)
{
return (LBM_CHANNEL_UNKNOWN_TRANSPORT_CLIENT_LBTTCP);
}
guint64 lbm_channel_assign_unknown_stream_tcp(void)
{
return (LBM_CHANNEL_UNKNOWN_STREAM_TCP);
}
gboolean lbm_channel_is_unknown_transport_lbttcp(guint64 channel)
{
return (lbm_channel_is_unknown_transport_source_lbttcp(channel) || lbm_channel_is_unknown_transport_client_lbttcp(channel));
}
gboolean lbm_channel_is_unknown_transport_source_lbttcp(guint64 channel)
{
if (channel == LBM_CHANNEL_UNKNOWN_TRANSPORT_SOURCE_LBTTCP)
{
return (TRUE);
}
return (FALSE);
}
gboolean lbm_channel_is_unknown_transport_client_lbttcp(guint64 channel)
{
if (channel == LBM_CHANNEL_UNKNOWN_TRANSPORT_CLIENT_LBTTCP)
{
return (TRUE);
}
return (FALSE);
}
gboolean lbm_channel_is_unknown_stream_tcp(guint64 channel)
{
if (channel == LBM_CHANNEL_UNKNOWN_STREAM_TCP)
{
return (TRUE);
}
return (FALSE);
}
gboolean lbm_channel_is_known(guint64 channel)
{
return (!lbm_channel_is_unknown_transport_lbttcp(channel) && !lbm_channel_is_unknown_stream_tcp(channel));
}
lbm_transport_frame_t * lbm_transport_frame_add(wmem_tree_t * list, guint8 type, guint32 frame, guint32 sqn, gboolean retransmission)
{
lbm_transport_frame_t * frame_entry = NULL;
frame_entry = (lbm_transport_frame_t *) wmem_tree_lookup32(list, frame);
if (frame_entry != NULL)
{
return (frame_entry);
}
frame_entry = wmem_new(wmem_file_scope(), lbm_transport_frame_t);
frame_entry->frame = frame;
frame_entry->type = type;
frame_entry->sqn = sqn;
frame_entry->previous_frame = 0;
frame_entry->previous_type_frame = 0;
frame_entry->next_frame = 0;
frame_entry->next_type_frame = 0;
frame_entry->retransmission = retransmission;
frame_entry->sqn_gap = 0;
frame_entry->ooo_gap = 0;
frame_entry->duplicate = FALSE;
wmem_tree_insert32(list, frame, (void *) frame_entry);
return (frame_entry);
}
lbm_transport_sqn_t * lbm_transport_sqn_add(wmem_tree_t * list, lbm_transport_frame_t * frame)
{
lbm_transport_sqn_t * sqn_entry = NULL;
lbm_transport_sqn_frame_t * frame_entry = NULL;
sqn_entry = (lbm_transport_sqn_t *) wmem_tree_lookup32(list, frame->sqn);
if (sqn_entry == NULL)
{
sqn_entry = wmem_new(wmem_file_scope(), lbm_transport_sqn_t);
sqn_entry->sqn = frame->sqn;
sqn_entry->frame_count = 0;
sqn_entry->frame = wmem_tree_new(wmem_file_scope());
wmem_tree_insert32(list, frame->sqn, (void *) sqn_entry);
}
frame_entry = wmem_new(wmem_file_scope(), lbm_transport_sqn_frame_t);
frame_entry->frame = frame->frame;
frame_entry->retransmission = frame->retransmission;
wmem_tree_insert32(sqn_entry->frame, frame->frame, (void *) frame_entry);
sqn_entry->frame_count++;
return (sqn_entry);
}
void lbm_topic_init(void)
{
lbm_topic_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
static void lbm_topic_build_key(guint32 * key_value, wmem_tree_key_t * key, guint64 channel, guint32 topic_index)
{
key_value[LBM_TOPIC_KEY_ELEMENT_CHANNEL_HIGH] = (guint32) ((channel >> 32) & 0xffffffff);
key_value[LBM_TOPIC_KEY_ELEMENT_CHANNEL_LOW] = (guint32) ((channel & 0xffffffff) >> 32);
key_value[LBM_TOPIC_KEY_ELEMENT_TOPIC_INDEX] = topic_index;
key[0].length = LBM_TOPIC_KEY_ELEMENT_COUNT;
key[0].key = key_value;
key[1].length = 0;
key[1].key = NULL;
}
static lbm_topic_t * lbm_topic_locate(guint64 channel, guint32 topic_index)
{
lbm_topic_t * entry = NULL;
guint32 keyval[LBM_TOPIC_KEY_ELEMENT_COUNT];
wmem_tree_key_t tkey[2];
lbm_topic_build_key(keyval, tkey, channel, topic_index);
entry = (lbm_topic_t *) wmem_tree_lookup32_array(lbm_topic_table, tkey);
return (entry);
}
const char * lbm_topic_find(guint64 channel, guint32 topic_index)
{
lbm_topic_t * entry = NULL;
const char * topic = NULL;
entry = lbm_topic_locate(channel, topic_index);
if (entry != NULL)
{
topic = entry->topic;
}
return (topic);
}
void lbm_topic_add(guint64 channel, guint32 topic_index, const char * name)
{
lbm_topic_t * entry;
guint32 keyval[LBM_TOPIC_KEY_ELEMENT_COUNT];
wmem_tree_key_t tkey[2];
entry = lbm_topic_locate(channel, topic_index);
if (entry != NULL)
{
return;
}
entry = wmem_new(wmem_file_scope(), lbm_topic_t);
entry->key.channel = channel;
entry->key.topic_idx = topic_index;
entry->key.topic = entry;
entry->topic = wmem_strdup(wmem_file_scope(), name);
lbm_topic_build_key(keyval, tkey, channel, topic_index);
wmem_tree_insert32_array(lbm_topic_table, tkey, (void *) entry);
}
