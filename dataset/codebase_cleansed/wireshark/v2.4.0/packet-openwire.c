static void
validate_boolean(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, int offset, proto_item *boolean_item)
{
guint8 booleanByte;
booleanByte = tvb_get_guint8(tvb, offset);
if (booleanByte != FALSE && booleanByte != TRUE)
{
expert_add_info(pinfo, boolean_item, &ei_openwire_encoding_not_supported);
}
}
static int
particularize(int specificField, int genericField)
{
return (specificField == hf_openwire_none ? genericField : specificField);
}
static void
detect_protocol_options(tvbuff_t *tvb, packet_info *pinfo, int offset, int iCommand)
{
if (tvb_captured_length_remaining(tvb, offset) >= 12)
{
if (iCommand == OPENWIRE_SESSION_INFO
|| iCommand == OPENWIRE_DESTINATION_INFO
|| iCommand == OPENWIRE_CONNECTION_INFO
|| iCommand == OPENWIRE_CONSUMER_INFO
|| iCommand == OPENWIRE_PRODUCER_INFO
|| iCommand == OPENWIRE_BROKER_INFO
|| iCommand == OPENWIRE_TRANSACTION_INFO
|| iCommand == OPENWIRE_REMOVE_SUBSCRIPTION_INFO
|| iCommand == OPENWIRE_MESSAGE_DISPATCH
|| iCommand == OPENWIRE_MESSAGE_ACK
|| iCommand == OPENWIRE_MESSAGE_PULL)
{
conversation_t *conv = NULL;
openwire_conv_data *cd = NULL;
conv = find_or_create_conversation(pinfo);
cd = (openwire_conv_data*)conversation_get_proto_data(conv, proto_openwire);
if (!cd)
{
guint8 present, type;
gint command_id = 0;
present = tvb_get_guint8(tvb, offset + 10);
type = tvb_get_guint8(tvb, offset + 11);
command_id = tvb_get_ntohl(tvb, offset + 5);
cd = wmem_new(wmem_file_scope(), openwire_conv_data);
cd->caching = FALSE;
cd->tight = FALSE;
if (command_id > (1 << 24))
{
cd->tight = TRUE;
}
else
{
if (present == TRUE && type == OPENWIRE_TYPE_NULL)
{
cd->caching = TRUE;
}
}
conversation_add_proto_data(conv, proto_openwire, cd);
}
}
}
else if ((tvb_get_guint8(tvb, 4) == OPENWIRE_KEEP_ALIVE_INFO)
&& (tvb_captured_length(tvb) == 11))
{
conversation_t *conv = NULL;
openwire_conv_data *cd = NULL;
conv = find_or_create_conversation(pinfo);
cd = (openwire_conv_data*)conversation_get_proto_data(conv, proto_openwire);
if (!cd)
{
cd = wmem_new(wmem_file_scope(), openwire_conv_data);
cd->tight = TRUE;
cd->caching = FALSE;
conversation_add_proto_data(conv, proto_openwire, cd);
}
}
}
static gboolean
retrieve_caching(packet_info *pinfo)
{
conversation_t *conv;
openwire_conv_data *cd;
conv = find_or_create_conversation(pinfo);
cd = (openwire_conv_data*)conversation_get_proto_data(conv, proto_openwire);
if (cd) return cd->caching;
return FALSE;
}
static gboolean
retrieve_tight(packet_info *pinfo)
{
conversation_t *conv;
openwire_conv_data *cd;
conv = find_or_create_conversation(pinfo);
cd = (openwire_conv_data*)conversation_get_proto_data(conv, proto_openwire);
if (cd && cd->tight) return TRUE;
return FALSE;
}
static int
dissect_openwire_type(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int field, int type, int parentType, gboolean nullable)
{
gint startOffset = offset;
proto_item *boolean_item = NULL;
const char *cache_str = "";
if (type == OPENWIRE_TYPE_CACHED && retrieve_caching(pinfo) == TRUE && tvb_reported_length_remaining(tvb, offset) >= 3)
{
guint8 inlined = 0;
gint cachedID = 0;
proto_item * cached_item = NULL;
inlined = tvb_get_guint8(tvb, offset + 0) == TRUE ? TRUE : FALSE;
cachedID = tvb_get_ntohs(tvb, offset + 1);
cache_str = wmem_strdup_printf(wmem_packet_scope(), " (CachedID: %d)", cachedID);
if (openwire_verbose_type)
{
proto_tree_add_item(tree, hf_openwire_cached_inlined, tvb, offset, 1, ENC_BIG_ENDIAN);
}
cached_item = proto_tree_add_item(tree, hf_openwire_cached_id, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
if (!openwire_verbose_type)
{
PROTO_ITEM_SET_HIDDEN(cached_item);
}
if (inlined == FALSE)
{
proto_item *ti;
ti = proto_tree_add_item(tree, particularize(field, hf_openwire_type_object), tvb, startOffset, 3, ENC_NA);
proto_item_append_text(ti, "%s", cache_str);
return 3;
}
else
{
offset += 3;
}
}
if (nullable == TRUE && (type == OPENWIRE_TYPE_NESTED || type == OPENWIRE_TYPE_CACHED || type == OPENWIRE_COMMAND_INNER) && tvb_reported_length_remaining(tvb, offset) >= 1)
{
nullable = tvb_get_guint8(tvb, offset + 0) == FALSE ? TRUE : FALSE;
if (openwire_verbose_type)
{
boolean_item = proto_tree_add_item(tree, hf_openwire_type_notnull, tvb, offset, 1, ENC_BIG_ENDIAN);
}
validate_boolean(tvb, pinfo, tree, offset, boolean_item);
if (nullable == TRUE)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_none), tvb, offset, 1, ENC_NA);
return offset - startOffset + 1;
}
offset += 1;
}
if (type == OPENWIRE_COMMAND_INNER && tvb_reported_length_remaining(tvb, offset) >= 1)
{
proto_item * inner_item = NULL;
proto_tree * object_tree = NULL;
guint8 iCommand = parentType;
iCommand = tvb_get_guint8(tvb, offset + 0);
inner_item = proto_tree_add_item(tree, particularize(field, hf_openwire_none), tvb, startOffset, -1, ENC_NA);
proto_item_append_text(inner_item, ": %s", val_to_str_ext(iCommand, &openwire_opcode_vals_ext, "Unknown (0x%02x)"));
object_tree = proto_item_add_subtree(inner_item, ett_openwire_type);
return (1 + dissect_openwire_command(tvb, pinfo, object_tree, offset, parentType));
}
if ((type == OPENWIRE_TYPE_NESTED || type == OPENWIRE_TYPE_CACHED) && tvb_reported_length_remaining(tvb, offset) >= 1)
{
type = tvb_get_guint8(tvb, offset + 0);
if (openwire_verbose_type)
{
proto_tree_add_item(tree, hf_openwire_type, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
}
if (nullable == TRUE && tvb_reported_length_remaining(tvb, offset) >= 1)
{
nullable = tvb_get_guint8(tvb, offset + 0) == FALSE ? TRUE : FALSE;
if (openwire_verbose_type)
{
boolean_item = proto_tree_add_item(tree, hf_openwire_type_notnull, tvb, offset, 1, ENC_BIG_ENDIAN);
}
validate_boolean(tvb, pinfo, tree, offset, boolean_item);
if (nullable == TRUE)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_none), tvb, offset, 1, ENC_NA);
return offset - startOffset + 1;
}
offset += 1;
}
if (type == OPENWIRE_TYPE_NULL)
{
offset += 0;
}
else if (type == OPENWIRE_TYPE_INTEGER && tvb_reported_length_remaining(tvb, offset) >= 4)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_type_integer), tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if (type == OPENWIRE_TYPE_SHORT && tvb_reported_length_remaining(tvb, offset) >= 2)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_type_short), tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else if (type == OPENWIRE_TYPE_LONG && tvb_reported_length_remaining(tvb, offset) >= 8)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_type_long), tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
else if (type == OPENWIRE_TYPE_BOOLEAN && tvb_reported_length_remaining(tvb, offset) >= 1)
{
boolean_item = proto_tree_add_item(tree, particularize(field, hf_openwire_type_boolean), tvb, offset, 1, ENC_BIG_ENDIAN);
validate_boolean(tvb, pinfo, tree, offset, boolean_item);
offset += 1;
}
else if (type == OPENWIRE_TYPE_BYTE && tvb_reported_length_remaining(tvb, offset) >= 1)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_type_byte), tvb, offset, 1, ENC_NA);
offset += 1;
}
else if (type == OPENWIRE_TYPE_CHAR && tvb_reported_length_remaining(tvb, offset) >= 2)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_type_char), tvb, offset, 2, ENC_NA);
offset += 2;
}
else if (type == OPENWIRE_TYPE_FLOAT && tvb_reported_length_remaining(tvb, offset) >= 4)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_type_float), tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if (type == OPENWIRE_TYPE_DOUBLE && tvb_reported_length_remaining(tvb, offset) >= 8)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_type_double), tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
else if (type == OPENWIRE_TYPE_STRING && tvb_reported_length_remaining(tvb, offset) >= 2)
{
gint iStringLength = 0;
iStringLength = tvb_get_ntohs(tvb, offset);
if (openwire_verbose_type)
{
proto_tree_add_item(tree, hf_openwire_type_short, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
if (tvb_reported_length_remaining(tvb, offset) >= iStringLength)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_type_string), tvb, offset, iStringLength, ENC_NA);
offset += iStringLength;
}
}
else if (type == OPENWIRE_TYPE_BIG_STRING && tvb_reported_length_remaining(tvb, offset) >= 4)
{
gint iStringLength = 0;
iStringLength = tvb_get_ntohl(tvb, offset);
if (openwire_verbose_type)
{
proto_tree_add_item(tree, hf_openwire_type_integer, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
if (tvb_reported_length_remaining(tvb, offset) >= iStringLength)
{
proto_tree_add_item(tree, particularize(field, hf_openwire_type_string), tvb, offset, iStringLength, ENC_NA);
offset += iStringLength;
}
}
else if (type == OPENWIRE_TYPE_BYTE_ARRAY && tvb_reported_length_remaining(tvb, offset) >= 4)
{
gint iArrayLength = 0;
iArrayLength = tvb_get_ntohl(tvb, offset);
if (openwire_verbose_type)
{
proto_tree_add_item(tree, hf_openwire_type_integer, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
if (tvb_reported_length_remaining(tvb, offset) >= iArrayLength)
{
proto_item * array_item = NULL;
proto_tree * object_tree = NULL;
array_item = proto_tree_add_item(tree, particularize(field, hf_openwire_type_bytes), tvb, offset, iArrayLength, ENC_NA);
object_tree = proto_item_add_subtree(array_item, ett_openwire_type);
if (field == hf_openwire_message_body)
{
tvbuff_t* next_tvb = NULL;
if (parentType == OPENWIRE_ACTIVEMQ_TEXT_MESSAGE)
{
dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_none, OPENWIRE_TYPE_BIG_STRING, type, FALSE);
next_tvb = tvb_new_subset_length(tvb, offset, iArrayLength);
add_new_data_source(pinfo, next_tvb, "Body");
}
else if (parentType == OPENWIRE_ACTIVEMQ_MAP_MESSAGE)
{
dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_none, OPENWIRE_TYPE_MAP, type, FALSE);
}
else if (parentType == OPENWIRE_ACTIVEMQ_STREAM_MESSAGE)
{
gint streamOffset = offset;
while (streamOffset < offset + iArrayLength)
{
streamOffset += dissect_openwire_type(tvb, pinfo, object_tree, streamOffset, hf_openwire_none, OPENWIRE_TYPE_NESTED, type, FALSE);
}
}
else if (parentType == OPENWIRE_ACTIVEMQ_BYTES_MESSAGE
|| parentType == OPENWIRE_ACTIVEMQ_OBJECT_MESSAGE
|| parentType == OPENWIRE_ACTIVEMQ_BLOB_MESSAGE)
{
next_tvb = tvb_new_subset_length(tvb, offset, iArrayLength);
add_new_data_source(pinfo, next_tvb, "Body");
expert_add_info(pinfo, array_item, &ei_openwire_body_type_not_supported);
}
}
else if (field == hf_openwire_message_properties)
{
dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_none, OPENWIRE_TYPE_MAP, type, FALSE);
}
offset += iArrayLength;
}
}
else if (tvb_reported_length_remaining(tvb, offset) >= 1)
{
proto_tree *object_tree;
proto_item *ti;
ti = proto_tree_add_item(tree, particularize(field, hf_openwire_type_object), tvb, startOffset, -1, ENC_NA);
proto_item_append_text(ti, ": %s", val_to_str_ext(type, &openwire_type_vals_ext, "Unknown (0x%02x)"));
proto_item_append_text(ti, "%s", cache_str);
object_tree = proto_item_add_subtree(ti, ett_openwire_type);
if (type == OPENWIRE_TYPE_OBJECT_ARRAY && tvb_reported_length_remaining(tvb, offset) >= 2)
{
gint iArrayLength;
int iArrayItem = 0;
iArrayLength = tvb_get_ntohs(tvb, offset);
if (openwire_verbose_type)
{
proto_tree_add_item(object_tree, hf_openwire_type_short, tvb, offset + 0, 2, ENC_BIG_ENDIAN);
}
proto_item_append_text(ti, " (Size : %d)", iArrayLength);
offset += 2;
for (iArrayItem = 0; iArrayItem < iArrayLength; iArrayItem++)
{
if (tvb_reported_length_remaining(tvb, offset) >= 0)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_none, OPENWIRE_TYPE_NESTED, type, TRUE);
}
}
}
else if (type == OPENWIRE_TYPE_MAP && tvb_reported_length_remaining(tvb, offset) >= 4)
{
int iMapItem = 0;
int iMapLength = 0;
iMapLength = tvb_get_ntohl(tvb, offset);
if (openwire_verbose_type)
{
proto_tree_add_item(object_tree, hf_openwire_map_length, tvb, offset, 4, ENC_BIG_ENDIAN);
}
proto_item_append_text(ti, " (Size : %d)", iMapLength);
offset += 4;
for (iMapItem = 0; (iMapItem < iMapLength) && (tvb_reported_length_remaining(tvb, offset) > 0); iMapItem++)
{
proto_item * map_entry;
proto_tree * entry_tree;
gint entryStartOffset = offset;
map_entry = proto_tree_add_item(object_tree, hf_openwire_map_entry, tvb, offset, 0, ENC_NA);
entry_tree = proto_item_add_subtree(map_entry, ett_openwire_type);
offset += dissect_openwire_type(tvb, pinfo, entry_tree, offset, hf_openwire_map_key, OPENWIRE_TYPE_STRING, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, entry_tree, offset, hf_openwire_none, OPENWIRE_TYPE_NESTED, type, FALSE);
proto_item_set_len(map_entry, offset - entryStartOffset);
}
}
else if (type == OPENWIRE_TYPE_THROWABLE && tvb_reported_length_remaining(tvb, offset) >= 2)
{
gint iStackTraceDepth, iStackTraceItem;
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_throwable_class, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_throwable_message, OPENWIRE_TYPE_STRING, type, TRUE);
iStackTraceDepth = tvb_get_ntohs(tvb, offset);
if (openwire_verbose_type)
{
proto_tree_add_item(tree, hf_openwire_type_short, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
if (iStackTraceDepth > 0)
{
for (iStackTraceItem = 0; iStackTraceItem < iStackTraceDepth; iStackTraceItem++)
{
proto_item *element;
proto_tree *element_tree;
gint startElementOffset = offset;
element = proto_tree_add_item(object_tree, hf_openwire_throwable_element, tvb, startElementOffset, -1, ENC_NA);
element_tree = proto_item_add_subtree(element, ett_openwire_type);
if (tvb_reported_length_remaining(tvb, offset) >= 0)
{
offset += dissect_openwire_type(tvb, pinfo, element_tree, offset, hf_openwire_throwable_classname, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, element_tree, offset, hf_openwire_throwable_methodname, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, element_tree, offset, hf_openwire_throwable_filename, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, element_tree, offset, hf_openwire_throwable_linenumber, OPENWIRE_TYPE_INTEGER, type, FALSE);
proto_item_set_len(element, offset - startElementOffset);
}
}
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_exceptionresponse_exception, OPENWIRE_TYPE_THROWABLE, type, TRUE);
}
}
else if (type == OPENWIRE_TYPE_LIST && tvb_reported_length_remaining(tvb, offset) >= 4)
{
}
else if (type == OPENWIRE_CONNECTION_ID && tvb_reported_length_remaining(tvb, offset) >= 1)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_connectionid_value, OPENWIRE_TYPE_STRING, type, TRUE);
}
else if (type == OPENWIRE_SESSION_ID && tvb_reported_length_remaining(tvb, offset) >= 2)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_sessionid_connectionid, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_sessionid_value, OPENWIRE_TYPE_LONG, type, FALSE);
}
else if (type == OPENWIRE_CONSUMER_ID && tvb_reported_length_remaining(tvb, offset) >= 3)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_consumerid_connectionid, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_consumerid_value, OPENWIRE_TYPE_LONG, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_consumerid_sessionid, OPENWIRE_TYPE_LONG, type, FALSE);
}
else if (type == OPENWIRE_PRODUCER_ID && tvb_reported_length_remaining(tvb, offset) >= 3)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_producerid_connectionid, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_producerid_value, OPENWIRE_TYPE_LONG, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_producerid_sessionid, OPENWIRE_TYPE_LONG, type, FALSE);
}
else if (type == OPENWIRE_BROKER_ID && tvb_reported_length_remaining(tvb, offset) >= 1)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_brokerid_value, OPENWIRE_TYPE_STRING, type, TRUE);
}
else if (type == OPENWIRE_MESSAGE_ID && tvb_reported_length_remaining(tvb, offset) >= 3)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_messageid_producerid, OPENWIRE_TYPE_CACHED, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_messageid_producersequenceid, OPENWIRE_TYPE_LONG, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_messageid_brokersequenceid, OPENWIRE_TYPE_LONG, type, FALSE);
}
else if (type == OPENWIRE_ACTIVEMQ_LOCAL_TRANSACTION_ID && tvb_reported_length_remaining(tvb, offset) >= 2)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_localtransactionid_value, OPENWIRE_TYPE_LONG, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_localtransactionid_connectionid, OPENWIRE_TYPE_CACHED, type, TRUE);
}
else if (type == OPENWIRE_ACTIVEMQ_XA_TRANSACTION_ID && tvb_reported_length_remaining(tvb, offset) >= 3)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_xatransactionid_formatid, OPENWIRE_TYPE_INTEGER, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_xatransactionid_globaltransactionid, OPENWIRE_TYPE_BYTE_ARRAY, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_xatransactionid_branchqualifier, OPENWIRE_TYPE_BYTE_ARRAY, type, TRUE);
}
else if ((type == OPENWIRE_ACTIVEMQ_QUEUE
|| type == OPENWIRE_ACTIVEMQ_TOPIC
|| type == OPENWIRE_ACTIVEMQ_TEMP_QUEUE
|| type == OPENWIRE_ACTIVEMQ_TEMP_TOPIC)
&& tvb_reported_length_remaining(tvb, offset) >= 1)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_destination_name, OPENWIRE_TYPE_STRING, type, TRUE);
}
else if (type == OPENWIRE_ACTIVEMQ_MESSAGE
|| type == OPENWIRE_ACTIVEMQ_BYTES_MESSAGE
|| type == OPENWIRE_ACTIVEMQ_MAP_MESSAGE
|| type == OPENWIRE_ACTIVEMQ_OBJECT_MESSAGE
|| type == OPENWIRE_ACTIVEMQ_STREAM_MESSAGE
|| type == OPENWIRE_ACTIVEMQ_TEXT_MESSAGE
|| type == OPENWIRE_ACTIVEMQ_BLOB_MESSAGE)
{
if (parentType != type)
{
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_command_id, OPENWIRE_TYPE_INTEGER, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_command_response_required, OPENWIRE_TYPE_BOOLEAN, type, FALSE);
}
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_producerid, OPENWIRE_TYPE_CACHED, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_destination, OPENWIRE_TYPE_CACHED, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_transactionid, OPENWIRE_TYPE_CACHED, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_originaldestination, OPENWIRE_TYPE_CACHED, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_messageid, OPENWIRE_TYPE_NESTED, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_originaldestinationid, OPENWIRE_TYPE_CACHED, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_groupid, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_groupsequence, OPENWIRE_TYPE_INTEGER, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_correlationid, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_persistent, OPENWIRE_TYPE_BOOLEAN, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_expiration, OPENWIRE_TYPE_LONG, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_priority, OPENWIRE_TYPE_BYTE, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_replyto, OPENWIRE_TYPE_NESTED, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_timestamp, OPENWIRE_TYPE_LONG, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_type, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_body, OPENWIRE_TYPE_BYTE_ARRAY, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_properties, OPENWIRE_TYPE_BYTE_ARRAY, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_datastructure, OPENWIRE_COMMAND_INNER, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_targetconsumerid, OPENWIRE_TYPE_CACHED, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_compressed, OPENWIRE_TYPE_BOOLEAN, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_redeliverycount, OPENWIRE_TYPE_INTEGER, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_brokerpath, OPENWIRE_TYPE_OBJECT_ARRAY, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_arrival, OPENWIRE_TYPE_LONG, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_userid, OPENWIRE_TYPE_STRING, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_receivedbydfbridge, OPENWIRE_TYPE_BOOLEAN, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_droppable, OPENWIRE_TYPE_BOOLEAN, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_cluster, OPENWIRE_TYPE_OBJECT_ARRAY, type, TRUE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_brokerintime, OPENWIRE_TYPE_LONG, type, FALSE);
offset += dissect_openwire_type(tvb, pinfo, object_tree, offset, hf_openwire_message_brokerouttime, OPENWIRE_TYPE_LONG, type, FALSE);
}
else if (tvb_reported_length_remaining(tvb, offset) > 0)
{
expert_add_info_format(pinfo, object_tree, &ei_openwire_type_not_supported, "OpenWire type not supported by Wireshark : %d", type);
offset += tvb_captured_length_remaining(tvb, offset);
}
proto_item_set_len(ti, offset - startOffset);
}
return (offset - startOffset);
}
static int
dissect_openwire_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int parentType)
{
gint startOffset = offset;
guint8 iCommand;
iCommand = tvb_get_guint8(tvb, offset + 0);
proto_tree_add_item(tree, hf_openwire_command, tvb, offset + 0, 1, ENC_BIG_ENDIAN);
offset += 1;
if (iCommand == OPENWIRE_WIREFORMAT_INFO)
{
if (tvb_reported_length_remaining(tvb, offset) >= 17)
{
proto_tree_add_item(tree, hf_openwire_wireformatinfo_magic, tvb, offset + 0, 8, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_openwire_wireformatinfo_version, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_openwire_wireformatinfo_data, tvb, offset + 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_openwire_wireformatinfo_length, tvb, offset + 13, 4, ENC_BIG_ENDIAN);
offset += 17;
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_none, OPENWIRE_TYPE_MAP, iCommand, FALSE);
}
}
else
{
if (tvb_reported_length_remaining(tvb, offset) >= 5)
{
proto_tree_add_item(tree, hf_openwire_command_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_openwire_command_response_required, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
offset += 5;
if (iCommand == OPENWIRE_SHUTDOWN_INFO || iCommand == OPENWIRE_KEEP_ALIVE_INFO || iCommand == OPENWIRE_FLUSH_COMMAND)
{
}
else if (iCommand == OPENWIRE_SESSION_INFO)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_sessioninfo_sessionid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_DESTINATION_INFO)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_destinationinfo_connectionid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_destinationinfo_destination, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_destinationinfo_operationtype, OPENWIRE_TYPE_BYTE, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_destinationinfo_timeout, OPENWIRE_TYPE_LONG, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_destinationinfo_brokerpath, OPENWIRE_TYPE_OBJECT_ARRAY, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_CONNECTION_INFO)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_connectionid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_clientid, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_password, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_username, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_brokerpath, OPENWIRE_TYPE_OBJECT_ARRAY, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_brokermasterconnector, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_manageable, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_clientmaster, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_faulttolerant, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioninfo_failoverreconnect, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
}
else if (iCommand == OPENWIRE_CONNECTION_CONTROL)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioncontrol_close, OPENWIRE_TYPE_BOOLEAN, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioncontrol_exit, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioncontrol_faulttolerant, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioncontrol_resume, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioncontrol_suspend, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioncontrol_connectedbrokers, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioncontrol_reconnectto, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectioncontrol_rebalanceconnection, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
}
else if (iCommand == OPENWIRE_CONSUMER_INFO)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_consumerid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_browser, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_destination, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_prefetchsize, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_maximumpendingmessagelimit, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_dispatchasync, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_selector, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_subscriptionname, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_nolocal, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_exclusive, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_retroactive, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_priority, OPENWIRE_TYPE_BYTE, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_brokerpath, OPENWIRE_TYPE_OBJECT_ARRAY, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_additionalpredicate, OPENWIRE_TYPE_NESTED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_networksubscription, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_optimizedacknowledge, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_norangeacks, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumerinfo_networkconsumerpath, OPENWIRE_TYPE_OBJECT_ARRAY, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_PRODUCER_INFO)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_producerinfo_producerid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_producerinfo_destination, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_producerinfo_brokerpath, OPENWIRE_TYPE_OBJECT_ARRAY, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_producerinfo_dispatchasync, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_producerinfo_windowsize, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
}
else if (iCommand == OPENWIRE_CONSUMER_CONTROL)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumercontrol_destination, OPENWIRE_TYPE_NESTED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumercontrol_close, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumercontrol_consumerid, OPENWIRE_TYPE_NESTED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumercontrol_prefetch, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumercontrol_flush, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumercontrol_start, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_consumercontrol_stop, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
}
else if (iCommand == OPENWIRE_BROKER_INFO)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_brokerid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_brokerurl, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_peerbrokerinfos, OPENWIRE_TYPE_OBJECT_ARRAY, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_brokername, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_slavebroker, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_masterbroker, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_faulttolerantconfiguration, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_duplexconnection, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_networkconnection, OPENWIRE_TYPE_BOOLEAN, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_connectionid, OPENWIRE_TYPE_LONG, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_brokeruploadurl, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_brokerinfo_networkproperties, OPENWIRE_TYPE_STRING, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_TRANSACTION_INFO)
{
guint8 iTransactionType;
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_transactioninfo_connectionid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_transactioninfo_transactionid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
if (tvb_reported_length_remaining(tvb, offset) >= 1)
{
iTransactionType = tvb_get_guint8(tvb, offset);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_transactioninfo_type, OPENWIRE_TYPE_BYTE, iCommand, FALSE);
proto_item_append_text(tree, " (%s)", val_to_str_ext(iTransactionType, &openwire_transaction_type_vals_ext, "Unknown (0x%02x)"));
}
}
else if (iCommand == OPENWIRE_PRODUCER_ACK)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_producerack_producerid, OPENWIRE_TYPE_NESTED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_producerack_size, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
}
else if (iCommand == OPENWIRE_REMOVE_INFO)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_removeinfo_objectid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_removeinfo_lastdeliveredsequenceid, OPENWIRE_TYPE_LONG, iCommand, FALSE);
}
else if (iCommand == OPENWIRE_REMOVE_SUBSCRIPTION_INFO)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_removesubscriptioninfo_connectionid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_removesubscriptioninfo_subscriptionname, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_removesubscriptioninfo_clientid, OPENWIRE_TYPE_STRING, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_MESSAGE_DISPATCH)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messagedispatch_consumerid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messagedispatch_destination, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messagedispatch_message, OPENWIRE_TYPE_NESTED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messagedispatch_redeliverycounter, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
}
else if (iCommand == OPENWIRE_MESSAGE_ACK)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messageack_destination, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messageack_transactionid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messageack_consumerid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messageack_acktype, OPENWIRE_TYPE_BYTE, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messageack_firstmessageid, OPENWIRE_TYPE_NESTED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messageack_lastmessageid, OPENWIRE_TYPE_NESTED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messageack_messagecount, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
}
else if (iCommand == OPENWIRE_MESSAGE_PULL)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messagepull_consumerid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messagepull_destinationid, OPENWIRE_TYPE_CACHED, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messagepull_timeout, OPENWIRE_TYPE_LONG, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messagepull_correlationid, OPENWIRE_TYPE_STRING, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_messagepull_messageid, OPENWIRE_TYPE_NESTED, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_RESPONSE)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_response_correlationid, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
}
else if (iCommand == OPENWIRE_DATA_RESPONSE)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_response_correlationid, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_dataresponse_data, OPENWIRE_COMMAND_INNER, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_CONNECTION_ERROR)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectionerror_exception, OPENWIRE_TYPE_THROWABLE, iCommand, TRUE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_connectionerror_connectionid, OPENWIRE_TYPE_NESTED, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_EXCEPTION_RESPONSE)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_response_correlationid, OPENWIRE_TYPE_INTEGER, iCommand, FALSE);
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_exceptionresponse_exception, OPENWIRE_TYPE_THROWABLE, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_CONTROL_COMMAND)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_controlcommand_command, OPENWIRE_TYPE_STRING, iCommand, TRUE);
}
else if (iCommand == OPENWIRE_ACTIVEMQ_MESSAGE
|| iCommand == OPENWIRE_ACTIVEMQ_BYTES_MESSAGE
|| iCommand == OPENWIRE_ACTIVEMQ_MAP_MESSAGE
|| iCommand == OPENWIRE_ACTIVEMQ_OBJECT_MESSAGE
|| iCommand == OPENWIRE_ACTIVEMQ_STREAM_MESSAGE
|| iCommand == OPENWIRE_ACTIVEMQ_TEXT_MESSAGE
|| iCommand == OPENWIRE_ACTIVEMQ_BLOB_MESSAGE)
{
offset += dissect_openwire_type(tvb, pinfo, tree, offset, hf_openwire_none, iCommand, parentType, FALSE);
}
else if (tvb_reported_length_remaining(tvb, offset) > 0)
{
expert_add_info_format(pinfo, tree, &ei_openwire_command_not_supported, "OpenWire command not supported by Wireshark: %d", iCommand);
}
}
}
return (offset - startOffset);
}
static int
dissect_openwire(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OpenWire");
col_clear(pinfo->cinfo, COL_INFO);
if (tvb_reported_length_remaining(tvb, offset) >= 5)
{
guint8 iCommand;
proto_tree *openwireroot_tree;
proto_item *ti;
gboolean caching;
iCommand = tvb_get_guint8(tvb, offset + 4);
col_append_sep_str(pinfo->cinfo, COL_INFO, " | ",
val_to_str_ext(iCommand, &openwire_opcode_vals_ext, "Unknown (0x%02x)"));
col_set_fence(pinfo->cinfo, COL_INFO);
detect_protocol_options(tvb, pinfo, offset, iCommand);
ti = proto_tree_add_item(tree, proto_openwire, tvb, offset, -1, ENC_NA);
proto_item_append_text(ti, " (%s)", val_to_str_ext(iCommand, &openwire_opcode_vals_ext, "Unknown (0x%02x)"));
openwireroot_tree = proto_item_add_subtree(ti, ett_openwire);
proto_tree_add_item(openwireroot_tree, hf_openwire_length, tvb, offset + 0, 4, ENC_BIG_ENDIAN);
if (iCommand != OPENWIRE_WIREFORMAT_INFO && retrieve_tight(pinfo) == TRUE)
{
proto_tree_add_item(openwireroot_tree, hf_openwire_command, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
expert_add_info(pinfo, openwireroot_tree, &ei_openwire_tight_encoding_not_supported);
return tvb_captured_length(tvb);
}
caching = retrieve_caching(pinfo);
if (caching)
{
proto_tree_add_boolean(openwireroot_tree, hf_openwire_cached_enabled, tvb, offset, 0, caching);
}
offset += 4;
offset += dissect_openwire_command(tvb, pinfo, openwireroot_tree, offset, iCommand);
if (tvb_reported_length_remaining(tvb, offset) > 0)
{
expert_add_info_format(pinfo, tree, &ei_openwire_command_not_supported, "OpenWire command fields unknown to Wireshark: %d", iCommand);
}
}
return tvb_captured_length(tvb);
}
static guint
get_openwire_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return (tvb_get_ntohl(tvb, offset) + 4);
}
static int
dissect_openwire_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, openwire_desegment, 5, get_openwire_pdu_len, dissect_openwire, data);
return tvb_captured_length(tvb);
}
static gboolean
dissect_openwire_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
conversation_t *conversation;
gboolean detected = FALSE;
if (tvb_reported_length(tvb) == 10 || tvb_reported_length(tvb) == 11)
{
if ((tvb_get_guint8(tvb, 4) == OPENWIRE_KEEP_ALIVE_INFO)
&& (tvb_get_ntohl(tvb, 0) + 4 == tvb_reported_length(tvb)))
{
detected = TRUE;
}
}
else if (tvb_reported_length(tvb) == 14 || tvb_reported_length(tvb) == 15)
{
if ((tvb_get_guint8(tvb, 4) == OPENWIRE_RESPONSE)
&& (tvb_get_ntohl(tvb, 0) + 4 == tvb_reported_length(tvb)))
{
detected = TRUE;
}
}
else if (tvb_reported_length(tvb) >= 13)
{
if (tvb_captured_length(tvb) >= 10
&& (tvb_get_guint8(tvb, 4) == OPENWIRE_WIREFORMAT_INFO)
&& (tvb_get_ntohl(tvb, 5) == OPENWIRE_MAGIC_PART_1)
&& (tvb_get_ntohl(tvb, 9) == OPENWIRE_MAGIC_PART_2))
{
detected = TRUE;
}
}
if (detected)
{
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, openwire_tcp_handle);
dissect_openwire(tvb, pinfo, tree, data);
return TRUE;
}
return FALSE;
}
void
proto_register_openwire(void)
{
static hf_register_info hf[] = {
{ &hf_openwire_length,
{ "Length", "openwire.length", FT_UINT32, BASE_DEC, NULL, 0x0, "OpenWire length", HFILL }},
{ &hf_openwire_command,
{ "Command", "openwire.command", FT_UINT8, BASE_DEC, VALS(openwire_opcode_vals), 0x0, "Openwire command", HFILL }},
{ &hf_openwire_command_id,
{ "Command Id", "openwire.command.id", FT_UINT32, BASE_DEC, NULL, 0x0, "Openwire command id", HFILL }},
{ &hf_openwire_command_response_required,
{ "Command response required", "openwire.command.response_required", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire command response required", HFILL }},
{ &hf_openwire_response_correlationid,
{ "CorrelationId", "openwire.response.correlationid", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire Response CorrelationId", HFILL }},
{ &hf_openwire_dataresponse_data,
{ "Data", "openwire.responsedata.data", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ResponseData Data", HFILL }},
{ &hf_openwire_exceptionresponse_exception,
{ "Exception", "openwire.exceptionresponse.exception", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ExceptionResponse Exception", HFILL }},
{ &hf_openwire_connectionerror_exception,
{ "Exception", "openwire.connectionerror.exception", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConnectionError Exception", HFILL }},
{ &hf_openwire_connectionerror_connectionid,
{ "ConnectionId", "openwire.connectionerror.connectionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConnectionError ConnectionId", HFILL }},
{ &hf_openwire_controlcommand_command,
{ "Command", "openwire.controlcommand.command", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ControlCommand Command", HFILL }},
{ &hf_openwire_wireformatinfo_magic,
{ "Magic", "openwire.wireformatinfo.magic", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire WireFormatInfo Magic", HFILL }},
{ &hf_openwire_wireformatinfo_version,
{ "Version", "openwire.wireformatinfo.version", FT_UINT32, BASE_DEC, NULL, 0x0, "Openwire WireFormatInfo Version", HFILL }},
{ &hf_openwire_wireformatinfo_data,
{ "Data", "openwire.wireformatinfo.data", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire WireFormatInfo Data", HFILL }},
{ &hf_openwire_wireformatinfo_length,
{ "Length", "openwire.wireformatinfo.length", FT_UINT32, BASE_DEC, NULL, 0x0, "Openwire WireFormatInfo Length", HFILL }},
{ &hf_openwire_sessioninfo_sessionid,
{ "SessionId", "openwire.sessioninfo.sessionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire SessionInfo SessionId", HFILL }},
{ &hf_openwire_destinationinfo_connectionid,
{ "ConnectionId", "openwire.destinationinfo.connectionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire DestinationInfo ConnectionId", HFILL }},
{ &hf_openwire_destinationinfo_destination,
{ "Destination", "openwire.destinationinfo.destination", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire DestinationInfo Destination", HFILL }},
{ &hf_openwire_destinationinfo_operationtype,
{ "OperationType", "openwire.destinationinfo.operationtype", FT_UINT8, BASE_DEC, VALS(openwire_operation_type_vals), 0x0, "Openwire DestinationInfo OperationType", HFILL }},
{ &hf_openwire_destinationinfo_timeout,
{ "Timeout", "openwire.destinationinfo.timeout", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire DestinationInfo Timeout", HFILL }},
{ &hf_openwire_destinationinfo_brokerpath,
{ "BrokerPath", "openwire.destinationinfo.brokerpath", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire DestinationInfo BrokerPath", HFILL }},
{ &hf_openwire_brokerinfo_brokerid,
{ "BrokerId", "openwire.brokerinfo.brokerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire BrokerInfo BrokerId", HFILL }},
{ &hf_openwire_brokerinfo_brokerurl,
{ "BrokerURL", "openwire.brokerinfo.brokerurl", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire BrokerInfo BrokerURL", HFILL }},
{ &hf_openwire_brokerinfo_peerbrokerinfos,
{ "PeerBrokerInfos", "openwire.brokerinfo.peerbrokerinfos", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire BrokerInfo PeerBrokerInfos", HFILL }},
{ &hf_openwire_brokerinfo_brokername,
{ "BrokerName", "openwire.brokerinfo.brokername", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire BrokerInfo BrokerName", HFILL }},
{ &hf_openwire_brokerinfo_slavebroker,
{ "SlaveBroker", "openwire.brokerinfo.slavebroker", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire BrokerInfo SlaveBroker", HFILL }},
{ &hf_openwire_brokerinfo_masterbroker,
{ "MasterBroker", "openwire.brokerinfo.masterbroker", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire BrokerInfo MasterBroker", HFILL }},
{ &hf_openwire_brokerinfo_faulttolerantconfiguration,
{ "FaultTolerantConfiguration", "openwire.brokerinfo.faulttolerantconfiguration", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire BrokerInfo FaultTolerantConfiguration", HFILL }},
{ &hf_openwire_brokerinfo_duplexconnection,
{ "DuplexConnection", "openwire.brokerinfo.duplexconnection", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire BrokerInfo DuplexConnection", HFILL }},
{ &hf_openwire_brokerinfo_networkconnection,
{ "NetworkConnection", "openwire.brokerinfo.networkconnection", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire BrokerInfo NetworkConnection", HFILL }},
{ &hf_openwire_brokerinfo_connectionid,
{ "ConnectionId", "openwire.brokerinfo.connectionid", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire BrokerInfo ConnectionId", HFILL }},
{ &hf_openwire_brokerinfo_brokeruploadurl,
{ "BrokerUploadUrl", "openwire.brokerinfo.brokeruploadurl", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire BrokerInfo BrokerUploadUrl", HFILL }},
{ &hf_openwire_brokerinfo_networkproperties,
{ "NetworkProperties", "openwire.brokerinfo.networkproperties", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire BrokerInfo NetworkProperties", HFILL }},
{ &hf_openwire_connectioninfo_connectionid,
{ "ConnectionId", "openwire.connectioninfo.connectionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConnectionInfo ConnectionId", HFILL }},
{ &hf_openwire_connectioninfo_clientid,
{ "ClientId", "openwire.connectioninfo.clientid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ConnectionInfo ClientId", HFILL }},
{ &hf_openwire_connectioninfo_password,
{ "Password", "openwire.connectioninfo.password", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ConnectionInfo Password", HFILL }},
{ &hf_openwire_connectioninfo_username,
{ "UserName", "openwire.connectioninfo.username", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ConnectionInfo UserName", HFILL }},
{ &hf_openwire_connectioninfo_brokerpath,
{ "BrokerPath", "openwire.connectioninfo.brokerpath", FT_BYTES, BASE_NONE, NULL, 0x0, "Openwire ConnectionInfo BrokerPath", HFILL }},
{ &hf_openwire_connectioninfo_brokermasterconnector,
{ "BrokerMasterConnector", "openwire.connectioninfo.brokermasterconnector", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionInfo BrokerMasterConnector", HFILL }},
{ &hf_openwire_connectioninfo_manageable,
{ "Manageable", "openwire.connectioninfo.manageable", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionInfo Manageable", HFILL }},
{ &hf_openwire_connectioninfo_clientmaster,
{ "ClientMaster", "openwire.connectioninfo.clientmaster", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionInfo ClientMaster", HFILL }},
{ &hf_openwire_connectioninfo_faulttolerant,
{ "FaultTolerant", "openwire.connectioninfo.faulttolerant", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionInfo FaultTolerant", HFILL }},
{ &hf_openwire_connectioninfo_failoverreconnect,
{ "FailoverReconnect", "openwire.connectioninfo.failoverreconnect", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionInfo FailoverReconnect", HFILL } },
{ &hf_openwire_consumerinfo_consumerid,
{ "ConsumerId", "openwire.consumerinfo.consumerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConsumerInfo ConsumerId", HFILL }},
{ &hf_openwire_consumerinfo_browser,
{ "Browser", "openwire.consumerinfo.browser", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo Browser", HFILL }},
{ &hf_openwire_consumerinfo_destination,
{ "Destination", "openwire.consumerinfo.destination", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConsumerInfo Destination", HFILL }},
{ &hf_openwire_consumerinfo_prefetchsize,
{ "PrefetchSize", "openwire.consumerinfo.prefetchsize", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo PrefetchSize", HFILL }},
{ &hf_openwire_consumerinfo_maximumpendingmessagelimit,
{ "MaximumPendingMessageLimit", "openwire.consumerinfo.maximumpendingmessagelimit", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo MaximumPendingMessageLimit", HFILL }},
{ &hf_openwire_consumerinfo_dispatchasync,
{ "DispatchAsync", "openwire.consumerinfo.dispatchasync", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo DispatchAsync", HFILL }},
{ &hf_openwire_consumerinfo_selector,
{ "Selector", "openwire.consumerinfo.selector", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ConsumerInfo Selector", HFILL }},
{ &hf_openwire_consumerinfo_subscriptionname,
{ "SubscriptionName", "openwire.consumerinfo.subscriptionname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ConsumerInfo SubscriptionName", HFILL }},
{ &hf_openwire_consumerinfo_nolocal,
{ "NoLocal", "openwire.consumerinfo.nolocal", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo NoLocal", HFILL }},
{ &hf_openwire_consumerinfo_exclusive,
{ "Exclusive", "openwire.consumerinfo.exclusive", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo Exclusive", HFILL }},
{ &hf_openwire_consumerinfo_retroactive,
{ "RetroActive", "openwire.consumerinfo.retroactive", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo RetroActive", HFILL }},
{ &hf_openwire_consumerinfo_priority,
{ "Priority", "openwire.consumerinfo.priority", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo Priority", HFILL }},
{ &hf_openwire_consumerinfo_brokerpath,
{ "BrokerPath", "openwire.consumerinfo.brokerpath", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConsumerInfo BrokerPath", HFILL }},
{ &hf_openwire_consumerinfo_additionalpredicate,
{ "AdditionalPredicate", "openwire.consumerinfo.additionalpredicate", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConsumerInfo AdditionalPredicate", HFILL }},
{ &hf_openwire_consumerinfo_networksubscription,
{ "NetworkSubscription", "openwire.consumerinfo.networksubscription", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo NetworkSubscription", HFILL }},
{ &hf_openwire_consumerinfo_optimizedacknowledge,
{ "OptimizedAcknowledge", "openwire.consumerinfo.optimizedacknowledge", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo OptimizedAcknowledge", HFILL }},
{ &hf_openwire_consumerinfo_norangeacks,
{ "NoRangeAcks", "openwire.consumerinfo.norangeacks", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerInfo NoRangeAcks", HFILL }},
{ &hf_openwire_consumerinfo_networkconsumerpath,
{ "NetworkConsumerPath", "openwire.consumerinfo.networkconsumerpath", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConsumerInfo NetworkConsumerPath", HFILL }},
{ &hf_openwire_consumercontrol_destination,
{ "Destination", "openwire.consumercontrol.destination", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConsumerControl Destination", HFILL }},
{ &hf_openwire_consumercontrol_close,
{ "Close", "openwire.consumercontrol.close", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerControl Close", HFILL }},
{ &hf_openwire_consumercontrol_consumerid,
{ "ConsumerId", "openwire.consumercontrol.consumerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ConsumerControl ConsumerId", HFILL }},
{ &hf_openwire_consumercontrol_prefetch,
{ "Prefetch", "openwire.consumercontrol.prefetch", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire ConsumerControl Prefetch", HFILL }},
{ &hf_openwire_consumercontrol_flush,
{ "Flush", "openwire.consumercontrol.flush", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerControl Flush", HFILL }},
{ &hf_openwire_consumercontrol_start,
{ "Start", "openwire.consumercontrol.start", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerControl Start", HFILL }},
{ &hf_openwire_consumercontrol_stop,
{ "Stop", "openwire.consumercontrol.stop", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConsumerControl Stop", HFILL }},
{ &hf_openwire_connectioncontrol_close,
{ "Close", "openwire.connectioncontrol.close", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionControl Close", HFILL }},
{ &hf_openwire_connectioncontrol_exit,
{ "Exit", "openwire.connectioncontrol.exit", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionControl Exit", HFILL }},
{ &hf_openwire_connectioncontrol_faulttolerant,
{ "FaultTolerant", "openwire.connectioncontrol.faulttolerant", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionControl FaultTolerant", HFILL }},
{ &hf_openwire_connectioncontrol_resume,
{ "Resume", "openwire.connectioncontrol.resume", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionControl Resume", HFILL }},
{ &hf_openwire_connectioncontrol_suspend,
{ "Suspend", "openwire.connectioncontrol.suspend", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionControl Suspend", HFILL }},
{ &hf_openwire_connectioncontrol_connectedbrokers,
{ "ConnectedBrokers", "openwire.connectioncontrol.connectedbrokers", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ConnectionControl ConnectedBrokers", HFILL }},
{ &hf_openwire_connectioncontrol_reconnectto,
{ "ReconnectTo", "openwire.connectioncontrol.reconnectto", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ConnectionControl ReconnectTo", HFILL }},
{ &hf_openwire_connectioncontrol_rebalanceconnection,
{ "RebalanceConnection", "openwire.connectioncontrol.rebalanceconnection", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ConnectionControl RebalanceConnection", HFILL }},
{ &hf_openwire_removeinfo_objectid,
{ "ObjectId", "openwire.removeinfo.objectid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire RemoveInfo ObjectId", HFILL }},
{ &hf_openwire_removeinfo_lastdeliveredsequenceid,
{ "LastDeliveredSequenceId", "openwire.removeinfo.lastdeliveredsequenceid", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire RemoveInfo LastDeliveredSequenceId" , HFILL }},
{ &hf_openwire_removesubscriptioninfo_connectionid,
{ "ConnectionId", "openwire.removesubscriptioninfo.connectionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire RemoveSubscriptionInfo ConnectionId", HFILL } },
{ &hf_openwire_removesubscriptioninfo_subscriptionname,
{ "SubscriptionName", "openwire.removesubscriptioninfo.subscriptionname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire RemoveSubscriptionInfo SubscriptionName", HFILL }},
{ &hf_openwire_removesubscriptioninfo_clientid,
{ "ClientId", "openwire.removesubscriptioninfo.clientid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire RemoveSubscriptionInfo ClientId", HFILL }},
{ &hf_openwire_producerinfo_producerid,
{ "ProducerId", "openwire.producerinfo.producerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ProducerInfo ProducerId", HFILL }},
{ &hf_openwire_producerinfo_destination,
{ "Destination", "openwire.producerinfo.destination", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ProducerInfo Destination", HFILL }},
{ &hf_openwire_producerinfo_brokerpath,
{ "BrokerPath", "openwire.producerinfo.brokerpath", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ProducerInfo BrokerPath", HFILL }},
{ &hf_openwire_producerinfo_dispatchasync,
{ "DispatchAsync", "openwire.producerinfo.dispatchasync", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire ProducerInfo DispatchAsync", HFILL }},
{ &hf_openwire_producerinfo_windowsize,
{ "WindowSize", "openwire.producerinfo.windowsize", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire ProducerInfo WindowSize", HFILL }},
{ &hf_openwire_transactioninfo_connectionid,
{ "ConnectionId", "openwire.transactioninfo.connectionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire TransactionInfo ConnectionId", HFILL }},
{ &hf_openwire_transactioninfo_transactionid,
{ "TransactionId", "openwire.transactioninfo.transactionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire TransactionInfo TransactionId", HFILL }},
{ &hf_openwire_transactioninfo_type,
{ "Type", "openwire.transactioninfo.type", FT_UINT8, BASE_DEC, VALS(openwire_transaction_type_vals), 0x0, "Openwire TransactionInfo Type", HFILL }},
{ &hf_openwire_producerack_producerid,
{ "ProducerId", "openwire.producerack.producerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire ProducerAck ProducerId", HFILL }},
{ &hf_openwire_producerack_size,
{ "Size", "openwire.producerack.size", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire ProducerAck Size", HFILL }},
{ &hf_openwire_messagedispatch_consumerid,
{ "ConsumerId", "openwire.messagedispatch.consumerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessageDispatch ConsumerId", HFILL }},
{ &hf_openwire_messagedispatch_destination,
{ "Destination", "openwire.messagedispatch.destination", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessageDispatch Destination", HFILL }},
{ &hf_openwire_messagedispatch_message,
{ "Message", "openwire.messagedispatch.message", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessageDispatch Message", HFILL }},
{ &hf_openwire_messagedispatch_redeliverycounter,
{ "RedeliveryCounter", "openwire.messagedispatch.redeliverycounter", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire MessageDispatch RedeliveryCounter", HFILL }},
{ &hf_openwire_messageack_destination,
{ "Destination", "openwire.messageack.destination", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessageAck Destination", HFILL }},
{ &hf_openwire_messageack_transactionid,
{ "TransactionId", "openwire.messageack.transactionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessageAck TransactionId", HFILL }},
{ &hf_openwire_messageack_consumerid,
{ "ConsumerId", "openwire.messageack.consumerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessageAck ConsumerId", HFILL }},
{ &hf_openwire_messageack_acktype,
{ "AckType", "openwire.messageack.acktype", FT_UINT8, BASE_DEC, VALS(openwire_message_ack_type_vals), 0x0, "Openwire MessageAck AckType", HFILL }},
{ &hf_openwire_messageack_firstmessageid,
{ "FirstMessageId", "openwire.messageack.firstmessageid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessageAck FirstMessageId", HFILL }},
{ &hf_openwire_messageack_lastmessageid,
{ "LastMessageId", "openwire.messageack.lastmessageid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessageAck LastMessageId", HFILL }},
{ &hf_openwire_messageack_messagecount,
{ "MessageCount", "openwire.messageack.messagecount", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire MessageAck MessageCount", HFILL }},
{ &hf_openwire_messagepull_consumerid,
{ "ConsumerId", "openwire.messagepull.consumerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessagePull ConsumerId", HFILL }},
{ &hf_openwire_messagepull_destinationid,
{ "DestinationId", "openwire.messagepull.destinationid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessagePull DestinationId", HFILL }},
{ &hf_openwire_messagepull_timeout,
{ "Timeout", "openwire.messagepull.timeout", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire MessagePull Timeout", HFILL }},
{ &hf_openwire_messagepull_correlationid,
{ "CorrelationId", "openwire.messagepull.correlationid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire MessagePull CorrelationId", HFILL }},
{ &hf_openwire_messagepull_messageid,
{ "MessageId", "openwire.messagepull.messageid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessagePull MessageId", HFILL }},
{ &hf_openwire_message_producerid,
{ "ProducerId", "openwire.message.producerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message ProducerID", HFILL }},
{ &hf_openwire_message_destination,
{ "Destination", "openwire.message.destination", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message Destination", HFILL }},
{ &hf_openwire_message_transactionid,
{ "TransactionId", "openwire.message.transactionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message TransactionId", HFILL }},
{ &hf_openwire_message_originaldestination,
{ "OriginalDestination", "openwire.message.originaldestination", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message OriginalDestination", HFILL }},
{ &hf_openwire_message_messageid,
{ "MessageId", "openwire.message.messageid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message MessageId", HFILL }},
{ &hf_openwire_message_originaldestinationid,
{ "OriginalDestinationId", "openwire.message.originaldestinationid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message OriginalDestinationId", HFILL }},
{ &hf_openwire_message_groupid,
{ "GroupID", "openwire.message.groupid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire message GroupID", HFILL }},
{ &hf_openwire_message_groupsequence,
{ "GroupSequence", "openwire.message.groupsequence", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire message GroupSequence", HFILL }},
{ &hf_openwire_message_correlationid,
{ "CorrelationId", "openwire.message.correlationid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire message CorrelationID", HFILL }},
{ &hf_openwire_message_persistent,
{ "Persistent", "openwire.message.persistent", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire message Persistent", HFILL }},
{ &hf_openwire_message_expiration,
{ "Expiration", "openwire.message.expiration", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire message Expiration", HFILL }},
{ &hf_openwire_message_priority,
{ "Priority", "openwire.message.priority", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire message Priority", HFILL }},
{ &hf_openwire_message_replyto,
{ "ReplyTo", "openwire.message.replyto", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message ReplyTo", HFILL }},
{ &hf_openwire_message_timestamp,
{ "Timestamp", "openwire.message.timestamp", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire message Timestamp", HFILL }},
{ &hf_openwire_message_type,
{ "Type", "openwire.message.type", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire message Type", HFILL }},
{ &hf_openwire_message_body,
{ "Body", "openwire.message.body", FT_BYTES, BASE_NONE, NULL, 0x0, "Openwire message Body", HFILL }},
{ &hf_openwire_message_properties,
{ "Properties", "openwire.message.properties", FT_BYTES, BASE_NONE, NULL, 0x0, "Openwire message Properties", HFILL }},
{ &hf_openwire_message_datastructure,
{ "DataStructure", "openwire.message.datastructure", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message DataStructure", HFILL }},
{ &hf_openwire_message_targetconsumerid,
{ "TargetConsumerId", "openwire.message.targetconsumerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message TargetConsumerId", HFILL }},
{ &hf_openwire_message_compressed,
{ "Compressed", "openwire.message.compressed", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire message Compressed", HFILL }},
{ &hf_openwire_message_redeliverycount,
{ "RedeliveryCount", "openwire.message.redeliverycount", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire message RedeliveryCount", HFILL }},
{ &hf_openwire_message_brokerpath,
{ "BrokerPath", "openwire.message.brokerpath", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message BrokerPath", HFILL }},
{ &hf_openwire_message_arrival,
{ "Arrival", "openwire.message.arrival", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire message Arrival", HFILL }},
{ &hf_openwire_message_userid,
{ "UserID", "openwire.message.userid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire message UserID", HFILL }},
{ &hf_openwire_message_receivedbydfbridge,
{ "ReceivedByDFBridge", "openwire.message.receivedbydfbridge", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire message ReceivedByDFBridge", HFILL }},
{ &hf_openwire_message_droppable,
{ "Droppable", "openwire.message.droppable", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire message Droppable", HFILL }},
{ &hf_openwire_message_cluster,
{ "Cluster", "openwire.message.cluster", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire message Cluster", HFILL }},
{ &hf_openwire_message_brokerintime,
{ "BrokerInTime", "openwire.message.brokerintime", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire message BrokerInTime", HFILL }},
{ &hf_openwire_message_brokerouttime,
{ "BrokerOutTime", "openwire.message.brokerouttime", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire message BrokerOutTime", HFILL }},
{ &hf_openwire_producerid_connectionid,
{ "ConnectionId", "openwire.producerid.connectionid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ProducerId ConnectionId", HFILL }},
{ &hf_openwire_producerid_value,
{ "Value", "openwire.producerid.value", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire ProducerId Value", HFILL }},
{ &hf_openwire_producerid_sessionid,
{ "SessionId", "openwire.producerid.sessionid", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire ProducerId SessionId", HFILL }},
{ &hf_openwire_consumerid_connectionid,
{ "ConnectionId", "openwire.consumerid.connectionid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ConsumerId ConnectionId", HFILL }},
{ &hf_openwire_consumerid_value,
{ "Value", "openwire.consumerid.value", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire ConsumerId Value", HFILL }},
{ &hf_openwire_consumerid_sessionid,
{ "SessionId", "openwire.consumerid.sessionid", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire ConsumerId SessionId", HFILL }},
{ &hf_openwire_destination_name,
{ "Name", "openwire.destination.name", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire Destination Name", HFILL }},
{ &hf_openwire_messageid_producerid,
{ "ProducerId", "openwire.messageid.producerid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire MessageId ProducerId", HFILL }},
{ &hf_openwire_messageid_producersequenceid,
{ "ProducerSequenceId", "openwire.messageid.producersequenceid", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire MessageId ProducerSequenceId", HFILL }},
{ &hf_openwire_messageid_brokersequenceid,
{ "BrokerSequenceId", "openwire.messageid.brokersequenceid", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire MessageId BrokerSequenceId", HFILL }},
{ &hf_openwire_connectionid_value,
{ "Value", "openwire.connectionid.value", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire ConnectionId Value", HFILL }},
{ &hf_openwire_sessionid_connectionid,
{ "Connection", "openwire.sessionid.connectionid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire SessionId ConnectionId", HFILL }},
{ &hf_openwire_sessionid_value,
{ "Value", "openwire.sessionid.value", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire SessionId Value", HFILL }},
{ &hf_openwire_brokerid_value,
{ "Value", "openwire.brokerid.value", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire BrokerId Value", HFILL }},
{ &hf_openwire_localtransactionid_value,
{ "Value", "openwire.localtransactionid.value", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire LocalTransactionId Value", HFILL }},
{ &hf_openwire_localtransactionid_connectionid,
{ "ConnectionId", "openwire.localtransactionid.connectionid", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire LocalTransactionId ConnecctionId", HFILL }},
{ &hf_openwire_xatransactionid_formatid,
{ "FormatId", "openwire.xatransactionid.formatid", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire XATransactionId FormatId", HFILL }},
{ &hf_openwire_xatransactionid_globaltransactionid,
{ "GlobalTransactionId", "openwire.xatransactionid.globaltransactionid", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire XATransactionId GlobalTransactionId", HFILL }},
{ &hf_openwire_xatransactionid_branchqualifier,
{ "BranchQualifier", "openwire.xatransactionid.branchqualifier", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire XATransactionId BranchQualifier", HFILL }},
{ &hf_openwire_none,
{ "Generic field", "openwire.generic", FT_BYTES, BASE_NONE, NULL, 0x0, "Openwire integer type", HFILL }},
{ &hf_openwire_map_length,
{ "Length", "openwire.map.length", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire map length", HFILL }},
{ &hf_openwire_map_key,
{ "Key", "openwire.map.key", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire map Key", HFILL }},
{ &hf_openwire_map_entry,
{ "Entry", "openwire.map.entry", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire map Entry", HFILL }},
{ &hf_openwire_throwable_class,
{ "Class", "openwire.throwable.class", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire Throwable Class", HFILL }},
{ &hf_openwire_throwable_message,
{ "Message", "openwire.throwable.message", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire Throwable Message", HFILL }},
{ &hf_openwire_throwable_element,
{ "Element", "openwire.throwable.element", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire Throwable Element", HFILL }},
{ &hf_openwire_throwable_classname,
{ "ClassName", "openwire.throwable.classname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire Throwable ClassName", HFILL }},
{ &hf_openwire_throwable_methodname,
{ "MethodName", "openwire.throwable.methodname", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire Throwable MethodName", HFILL }},
{ &hf_openwire_throwable_filename,
{ "FileName", "openwire.throwable.filename", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire Throwable FileName", HFILL }},
{ &hf_openwire_throwable_linenumber,
{ "LineNumber", "openwire.throwable.linenumber", FT_UINT32, BASE_DEC, NULL, 0x0, "Openwire Throwable LineNumber", HFILL }},
{ &hf_openwire_type_integer,
{ "Integer", "openwire.type.integer", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire Integer type", HFILL }},
{ &hf_openwire_type_short,
{ "Short", "openwire.type.short", FT_INT32, BASE_DEC, NULL, 0x0, "Openwire Short type", HFILL }},
{ &hf_openwire_type_string,
{ "String", "openwire.type.string", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Openwire String type", HFILL }},
{ &hf_openwire_type_bytes,
{ "Bytes", "openwire.type.bytes", FT_BYTES, BASE_NONE, NULL, 0x0, "Openwire Bytes type", HFILL }},
{ &hf_openwire_type_boolean,
{ "Boolean", "openwire.type.boolean", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire Boolean type", HFILL }},
{ &hf_openwire_type_byte,
{ "Byte", "openwire.type.byte", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire Byte type", HFILL }},
{ &hf_openwire_type_char,
{ "Char", "openwire.type.char", FT_UINT16, BASE_DEC, NULL, 0x0, "Openwire Char type", HFILL }},
{ &hf_openwire_type_long,
{ "Long", "openwire.type.long", FT_INT64, BASE_DEC, NULL, 0x0, "Openwire Cong type", HFILL }},
{ &hf_openwire_type_float,
{ "Float", "openwire.type.float", FT_FLOAT, BASE_NONE, NULL, 0x0, "Openwire Float type", HFILL }},
{ &hf_openwire_type_double,
{ "Double", "openwire.type.double", FT_DOUBLE, BASE_NONE, NULL, 0x0, "Openwire Double type", HFILL }},
{ &hf_openwire_type_notnull,
{ "NotNull", "openwire.type.notnull", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire NotNull type", HFILL }},
{ &hf_openwire_cached_inlined,
{ "Inlined", "openwire.cached.inlined", FT_UINT8, BASE_DEC, NULL, 0x0, "Openwire Cached Inlined", HFILL }},
{ &hf_openwire_cached_id,
{ "CachedID", "openwire.cached.id", FT_UINT16, BASE_DEC, NULL, 0x0, "Openwire Cached ID", HFILL }},
{ &hf_openwire_cached_enabled,
{ "CachedEnabled", "openwire.cached.enabled", FT_BOOLEAN, BASE_NONE, NULL, 0x0, "Openwire Cached Enabled", HFILL }},
{ &hf_openwire_type_object,
{ "Object", "openwire.type.object", FT_NONE, BASE_NONE, NULL, 0x0, "Openwire object", HFILL }},
{ &hf_openwire_type,
{ "Type", "openwire.type", FT_UINT8, BASE_DEC, VALS(openwire_type_vals), 0x0, "Openwire type", HFILL }}
};
static gint *ett[] = {
&ett_openwire,
&ett_openwire_type
};
static ei_register_info ei[] = {
{ &ei_openwire_encoding_not_supported, { "openwire.encoding_not_supported", PI_PROTOCOL, PI_WARN, "OpenWire encoding not supported by Wireshark or dissector bug", EXPFILL }},
{ &ei_openwire_body_type_not_supported, { "openwire.body_type_not_supported", PI_UNDECODED, PI_NOTE, "OpenWire body type not supported by Wireshark", EXPFILL }},
{ &ei_openwire_type_not_supported, { "openwire.type.not_supported", PI_UNDECODED, PI_NOTE, "OpenWire type not supported by Wireshark", EXPFILL }},
{ &ei_openwire_command_not_supported, { "openwire.command.not_supported", PI_UNDECODED, PI_NOTE, "OpenWire command not supported by Wireshark", EXPFILL }},
{ &ei_openwire_tight_encoding_not_supported, { "openwire.tight_encoding_not_supported", PI_UNDECODED, PI_NOTE, "OpenWire tight encoding not supported by Wireshark", EXPFILL }},
};
module_t *openwire_module;
expert_module_t* expert_openwire;
proto_openwire = proto_register_protocol("OpenWire", "OpenWire", "openwire");
proto_register_field_array(proto_openwire, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_openwire = expert_register_protocol(proto_openwire);
expert_register_field_array(expert_openwire, ei, array_length(ei));
openwire_module = prefs_register_protocol(proto_openwire, NULL);
prefs_register_bool_preference(openwire_module, "desegment",
"Reassemble Openwire messages spanning multiple TCP segments",
"Whether the Openwire dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&openwire_desegment);
prefs_register_bool_preference(openwire_module, "verbose_type",
"Show verbose type information",
"Whether verbose type and length information are displayed in the protocol tree",
&openwire_verbose_type);
}
void
proto_reg_handoff_openwire(void)
{
heur_dissector_add("tcp", dissect_openwire_heur, "OpenWire over TCP", "openwire_tcp", proto_openwire, HEURISTIC_ENABLE);
openwire_tcp_handle = create_dissector_handle(dissect_openwire_tcp, proto_openwire);
dissector_add_for_decode_as_with_preference("tcp.port", openwire_tcp_handle);
}
