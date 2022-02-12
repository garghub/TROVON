lbttcp_transport_t * lbttcp_transport_find(const address * source_address, guint16 source_port, guint32 session_id, guint32 frame)
{
lbttcp_transport_t * entry = NULL;
conversation_t * conv = NULL;
lbttcp_transport_conv_data_t * conv_data = NULL;
conv = find_conversation(frame, source_address, &lbttcp_null_address, PT_TCP, source_port, 0, 0);
if (conv != NULL)
{
conv_data = (lbttcp_transport_conv_data_t *) conversation_get_proto_data(conv, proto_lbttcp);
if (conv_data != NULL)
{
entry = (lbttcp_transport_t *) wmem_tree_lookup32(conv_data->session_tree, session_id);
}
}
return (entry);
}
static lbttcp_transport_t * lbttcp_transport_create(const address * source_address, guint16 source_port, guint32 session_id)
{
lbttcp_transport_t * transport = NULL;
transport = wmem_new(wmem_file_scope(), lbttcp_transport_t);
copy_address_wmem(wmem_file_scope(), &(transport->source_address), source_address);
transport->source_port = source_port;
transport->session_id = session_id;
transport->channel = lbm_channel_assign(LBM_CHANNEL_TRANSPORT_LBTTCP);
transport->next_client_id = 1;
transport->client_list = wmem_list_new(wmem_file_scope());
return (transport);
}
lbttcp_transport_t * lbttcp_transport_add(const address * source_address, guint16 source_port, guint32 session_id, guint32 frame)
{
lbttcp_transport_t * entry = NULL;
conversation_t * conv = NULL;
lbttcp_transport_conv_data_t * conv_data = NULL;
conv = find_conversation(frame, source_address, &lbttcp_null_address, PT_TCP, source_port, 0, 0);
if (conv == NULL)
{
conv = conversation_new(frame, source_address, &lbttcp_null_address, PT_TCP, source_port, 0, 0);
}
conv_data = (lbttcp_transport_conv_data_t *) conversation_get_proto_data(conv, proto_lbttcp);
if (conv_data == NULL)
{
conv_data = wmem_new(wmem_file_scope(), lbttcp_transport_conv_data_t);
conv_data->frame_tree = wmem_tree_new(wmem_file_scope());
conv_data->session_tree = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conv, proto_lbttcp, (void *) conv_data);
}
entry = (lbttcp_transport_t *) wmem_tree_lookup32(conv_data->session_tree, session_id);
if (entry != NULL)
{
return (entry);
}
entry = lbttcp_transport_create(source_address, source_port, session_id);
wmem_tree_insert32(conv_data->session_tree, session_id, (void *) entry);
wmem_tree_insert32(conv_data->frame_tree, frame, (void *) entry);
return (entry);
}
static lbttcp_client_transport_t * lbttcp_client_transport_find(lbttcp_transport_t * transport, const address * receiver_address, guint16 receiver_port, guint32 frame)
{
lbttcp_client_transport_t * entry = NULL;
conversation_t * client_conv = NULL;
if (transport == NULL)
{
return (NULL);
}
client_conv = find_conversation(frame, &(transport->source_address), receiver_address, PT_TCP, transport->source_port, receiver_port, 0);
if (client_conv != NULL)
{
wmem_tree_t * session_tree = NULL;
session_tree = (wmem_tree_t *) conversation_get_proto_data(client_conv, proto_lbttcp);
if (session_tree != NULL)
{
entry = (lbttcp_client_transport_t *) wmem_tree_lookup32(session_tree, transport->session_id);
}
}
return (entry);
}
static lbttcp_client_transport_t * lbttcp_client_transport_add(lbttcp_transport_t * transport, const address * receiver_address, guint16 receiver_port, guint32 frame)
{
lbttcp_client_transport_t * entry;
conversation_t * client_conv = NULL;
wmem_tree_t * session_tree = NULL;
if (transport == NULL)
{
return (NULL);
}
entry = lbttcp_client_transport_find(transport, receiver_address, receiver_port, frame);
if (entry != NULL)
{
return (entry);
}
entry = wmem_new(wmem_file_scope(), lbttcp_client_transport_t);
copy_address_wmem(wmem_file_scope(), &(entry->receiver_address), receiver_address);
entry->receiver_port = receiver_port;
entry->id = transport->next_client_id++;
client_conv = find_conversation(frame, &(transport->source_address), receiver_address, PT_TCP, transport->source_port, receiver_port, 0);
if (client_conv == NULL)
{
client_conv = conversation_new(frame, &(transport->source_address), receiver_address, PT_TCP, transport->source_port, receiver_port, 0);
session_tree = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(client_conv, proto_lbttcp, (void *) session_tree);
}
session_tree = (wmem_tree_t *) conversation_get_proto_data(client_conv, proto_lbttcp);
if (session_tree == NULL)
{
session_tree = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(client_conv, proto_lbttcp, (void *) session_tree);
}
wmem_tree_insert32(session_tree, transport->session_id, (void *) entry);
wmem_list_append(transport->client_list, (void *) entry);
return (entry);
}
char * lbttcp_transport_source_string(const address * source_address, guint16 source_port, guint32 session_id)
{
char * bufptr = NULL;
if (session_id == 0)
{
bufptr = wmem_strdup_printf(wmem_file_scope(), "TCP:%s:%" G_GUINT16_FORMAT, address_to_str(wmem_packet_scope(), source_address), source_port);
}
else
{
bufptr = wmem_strdup_printf(wmem_file_scope(), "TCP:%s:%" G_GUINT16_FORMAT ":%08x", address_to_str(wmem_packet_scope(), source_address), source_port, session_id);
}
return (bufptr);
}
gboolean lbttcp_transport_sid_find(const address * source_address, guint16 source_port, guint32 frame, guint32 * session_id)
{
conversation_t * conv = NULL;
lbttcp_transport_conv_data_t * conv_data = NULL;
lbttcp_transport_t * transport = NULL;
conv = find_conversation(frame, source_address, &lbttcp_null_address, PT_TCP, source_port, 0, 0);
if (conv == NULL)
{
return (FALSE);
}
conv_data = (lbttcp_transport_conv_data_t *) conversation_get_proto_data(conv, proto_lbttcp);
if (conv_data == NULL)
{
return (FALSE);
}
if (conv_data->frame_tree == NULL)
{
return (FALSE);
}
transport = (lbttcp_transport_t *)wmem_tree_lookup32_le(conv_data->frame_tree, frame);
if (transport == NULL)
{
return (FALSE);
}
*session_id = transport->session_id;
return (TRUE);
}
void lbttcp_transport_sid_add(const address * source_address, guint16 source_port, guint32 frame, guint32 session_id)
{
conversation_t * conv = NULL;
lbttcp_transport_conv_data_t * conv_data = NULL;
lbttcp_transport_t * transport = NULL;
conv = find_conversation(frame, source_address, &lbttcp_null_address, PT_TCP, source_port, 0, 0);
if (conv == NULL)
{
conv = conversation_new(frame, source_address, &lbttcp_null_address, PT_TCP, source_port, 0, 0);
}
conv_data = (lbttcp_transport_conv_data_t *) conversation_get_proto_data(conv, proto_lbttcp);
if (conv_data == NULL)
{
conv_data = wmem_new(wmem_file_scope(), lbttcp_transport_conv_data_t);
conv_data->frame_tree = wmem_tree_new(wmem_file_scope());
conv_data->session_tree = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conv, proto_lbttcp, (void *) conv_data);
}
transport = (lbttcp_transport_t *) wmem_tree_lookup32_le(conv_data->frame_tree, frame);
if (transport != NULL)
{
if (transport->session_id != session_id)
{
transport = NULL;
}
}
if (transport == NULL)
{
transport = lbttcp_transport_create(source_address, source_port, session_id);
wmem_tree_insert32(conv_data->session_tree, session_id, (void *) transport);
wmem_tree_insert32(conv_data->frame_tree, frame, (void *) transport);
}
}
static gboolean lbttcp_tag_update_cb(void * record, char * * error_string)
{
lbttcp_tag_entry_t * tag = (lbttcp_tag_entry_t *)record;
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
static void * lbttcp_tag_copy_cb(void * destination, const void * source, size_t length _U_)
{
const lbttcp_tag_entry_t * src = (const lbttcp_tag_entry_t *)source;
lbttcp_tag_entry_t * dest = (lbttcp_tag_entry_t *)destination;
dest->name = g_strdup(src->name);
dest->source_port_low = src->source_port_low;
dest->source_port_high = src->source_port_high;
dest->request_port_low = src->request_port_low;
dest->request_port_high = src->request_port_high;
dest->store_port_low = src->store_port_low;
dest->store_port_high = src->store_port_high;
return (dest);
}
static void lbttcp_tag_free_cb(void * record)
{
lbttcp_tag_entry_t * tag = (lbttcp_tag_entry_t *)record;
if (tag->name != NULL)
{
g_free(tag->name);
tag->name = NULL;
}
}
static const lbttcp_tag_entry_t * lbttcp_tag_locate(packet_info * pinfo)
{
guint idx;
const lbttcp_tag_entry_t * tag = NULL;
if (!lbttcp_use_tag)
{
return (NULL);
}
for (idx = 0; idx < lbttcp_tag_count; ++idx)
{
tag = &(lbttcp_tag_entry[idx]);
if (((pinfo->srcport >= tag->source_port_low) && (pinfo->srcport <= tag->source_port_high))
|| ((pinfo->destport >= tag->source_port_low) && (pinfo->destport <= tag->source_port_high))
|| ((pinfo->srcport >= tag->request_port_low) && (pinfo->srcport <= tag->request_port_high))
|| ((pinfo->destport >= tag->request_port_low) && (pinfo->destport <= tag->request_port_high))
|| ((pinfo->srcport >= tag->store_port_low) && (pinfo->srcport <= tag->store_port_high))
|| ((pinfo->destport >= tag->store_port_low) && (pinfo->destport <= tag->store_port_high)))
{
return (tag);
}
}
return (NULL);
}
static char * lbttcp_tag_find(packet_info * pinfo)
{
const lbttcp_tag_entry_t * tag = NULL;
if (!lbttcp_use_tag)
{
return (NULL);
}
tag = lbttcp_tag_locate(pinfo);
if (tag != NULL)
{
return tag->name;
}
return (NULL);
}
static gboolean lbttcp_packet_is_transport_source(packet_info * pinfo, const lbttcp_tag_entry_t * tag)
{
gboolean is_transport_source_packet = FALSE;
if (tag == NULL)
{
if ((pinfo->srcport >= lbttcp_source_port_low) && (pinfo->srcport <= lbttcp_source_port_high))
{
is_transport_source_packet = TRUE;
}
}
else
{
if ((pinfo->srcport >= tag->source_port_low) && (pinfo->srcport <= tag->source_port_high))
{
is_transport_source_packet = TRUE;
}
}
return (is_transport_source_packet);
}
static gboolean lbttcp_packet_is_transport_client(packet_info * pinfo, const lbttcp_tag_entry_t * tag)
{
gboolean is_transport_client_packet = FALSE;
if (tag == NULL)
{
if ((pinfo->destport >= lbttcp_source_port_low) && (pinfo->destport <= lbttcp_source_port_high))
{
is_transport_client_packet = TRUE;
}
}
else
{
if ((pinfo->destport >= tag->source_port_low) && (pinfo->destport <= tag->source_port_high))
{
is_transport_client_packet = TRUE;
}
}
return (is_transport_client_packet);
}
static guint get_lbttcp_pdu_length(packet_info * pinfo _U_, tvbuff_t * tvb,
int offset, void *data _U_)
{
return lbmc_get_message_length(tvb, offset);
}
static int dissect_lbttcp_pdu(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * dissector_data _U_)
{
proto_tree * lbttcp_tree = NULL;
proto_item * ti = NULL;
char * tag_name = NULL;
int len_dissected;
const lbttcp_tag_entry_t * tag = NULL;
guint64 channel = LBM_CHANNEL_NO_CHANNEL;
guint32 client_id = 0;
gboolean from_source = FALSE;
gboolean transport_packet = FALSE;
if (lbttcp_use_tag)
{
tag = lbttcp_tag_locate(pinfo);
tag_name = lbttcp_tag_find(pinfo);
}
if (tag_name != NULL)
{
ti = proto_tree_add_protocol_format(tree, proto_lbttcp, tvb, 0, -1, "LBT-TCP Protocol (Tag: %s)", tag_name);
}
else
{
ti = proto_tree_add_protocol_format(tree, proto_lbttcp, tvb, 0, -1, "LBT-TCP Protocol");
}
lbttcp_tree = proto_item_add_subtree(ti, ett_lbttcp);
if (tag_name != NULL)
{
proto_item * item = NULL;
item = proto_tree_add_string(lbttcp_tree, hf_lbttcp_tag, tvb, 0, 0, tag_name);
PROTO_ITEM_SET_GENERATED(item);
}
if (lbttcp_packet_is_transport_source(pinfo, tag))
{
from_source = TRUE;
transport_packet = TRUE;
}
else if (lbttcp_packet_is_transport_client(pinfo, tag))
{
from_source = FALSE;
transport_packet = TRUE;
}
if (transport_packet)
{
address source_address;
address client_address;
guint16 srcport;
guint16 clntport;
guint32 sid = 0;
lbttcp_transport_t * transport = NULL;
lbttcp_client_transport_t * client = NULL;
if (from_source)
{
copy_address_shallow(&source_address, &(pinfo->src));
srcport = pinfo->srcport;
copy_address_shallow(&client_address, &(pinfo->dst));
clntport = pinfo->destport;
}
else
{
copy_address_shallow(&source_address, &(pinfo->dst));
srcport = pinfo->destport;
copy_address_shallow(&client_address, &(pinfo->src));
clntport = pinfo->srcport;
}
transport = lbttcp_transport_find(&source_address, srcport, sid, pinfo->num);
if (transport == NULL)
{
if (lbttcp_transport_sid_find(&source_address, srcport, pinfo->num, &sid))
{
transport = lbttcp_transport_find(&source_address, srcport, sid, pinfo->num);
}
}
if (transport != NULL)
{
channel = transport->channel;
client = lbttcp_client_transport_find(transport, &client_address, clntport, pinfo->num);
if (client == NULL)
{
client = lbttcp_client_transport_add(transport, &client_address, clntport, pinfo->num);
}
if (client != NULL)
{
client_id = client->id;
}
}
else
{
if (PINFO_FD_VISITED(pinfo))
{
transport = lbttcp_transport_add(&source_address, srcport, 0, pinfo->num);
if (transport != NULL)
{
channel = transport->channel;
client = lbttcp_client_transport_add(transport, &client_address, clntport, pinfo->num);
if (client != NULL)
{
client_id = client->id;
}
}
}
else
{
if (from_source)
{
channel = lbm_channel_assign_unknown_transport_source_lbttcp();
}
else
{
channel = lbm_channel_assign_unknown_transport_client_lbttcp();
}
}
}
}
else
{
channel = lbm_channel_assign_unknown_stream_tcp();
}
if (lbm_channel_is_known(channel))
{
proto_item * channel_item = NULL;
proto_tree * channel_tree = NULL;
channel_item = proto_tree_add_item(lbttcp_tree, hf_lbttcp_channel, tvb, 0, 0, ENC_NA);
PROTO_ITEM_SET_GENERATED(channel_item);
channel_tree = proto_item_add_subtree(channel_item, ett_lbttcp_channel);
channel_item = proto_tree_add_uint64(channel_tree, hf_lbttcp_channel_id, tvb, 0, 0, channel);
PROTO_ITEM_SET_GENERATED(channel_item);
channel_item = proto_tree_add_uint(channel_tree, hf_lbttcp_channel_client, tvb, 0, 0, client_id);
PROTO_ITEM_SET_GENERATED(channel_item);
}
len_dissected = lbmc_dissect_lbmc_packet(tvb, 0, pinfo, tree, tag_name, channel);
return (len_dissected);
}
static int dissect_lbttcp_real(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * data _U_)
{
char * tag_name = NULL;
col_add_str(pinfo->cinfo, COL_PROTOCOL, "LBT-TCP");
col_clear(pinfo->cinfo, COL_INFO);
if (lbttcp_use_tag)
{
tag_name = lbttcp_tag_find(pinfo);
}
if (tag_name != NULL)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "[Tag: %s]", tag_name);
}
col_set_fence(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, lbmc_get_minimum_length(),
get_lbttcp_pdu_length, dissect_lbttcp_pdu, NULL);
return tvb_captured_length(tvb);
}
static int dissect_lbttcp(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * data)
{
if (!lbmc_test_lbmc_header(tvb, 0))
return 0;
return dissect_lbttcp_real(tvb, pinfo, tree, data);
}
static gboolean test_lbttcp_packet(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * data)
{
if ((pinfo->dst.type != AT_IPv4) || (pinfo->dst.len != 4))
{
return (FALSE);
}
if (lbttcp_use_tag)
{
if (lbttcp_tag_find(pinfo) != NULL)
{
dissect_lbttcp_real(tvb, pinfo, tree, data);
return (TRUE);
}
else
{
return (FALSE);
}
}
if (!(((pinfo->srcport >= lbttcp_source_port_low) && (pinfo->srcport <= lbttcp_source_port_high))
|| ((pinfo->destport >= lbttcp_source_port_low) && (pinfo->destport <= lbttcp_source_port_high))
|| ((pinfo->srcport >= lbttcp_request_port_low) && (pinfo->srcport <= lbttcp_request_port_high))
|| ((pinfo->destport >= lbttcp_request_port_low) && (pinfo->destport <= lbttcp_request_port_high))
|| ((pinfo->srcport >= lbttcp_store_port_low) && (pinfo->srcport <= lbttcp_store_port_high))
|| ((pinfo->destport >= lbttcp_store_port_low) && (pinfo->destport <= lbttcp_store_port_high))))
{
return (FALSE);
}
if (!lbmc_test_lbmc_header(tvb, 0))
return FALSE;
dissect_lbttcp_real(tvb, pinfo, tree, data);
return (TRUE);
}
void proto_register_lbttcp(void)
{
static hf_register_info hf[] =
{
{ &hf_lbttcp_tag,
{ "Tag", "lbttcp.tag", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbttcp_channel,
{ "Channel", "lbttcp.channel", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbttcp_channel_id,
{ "Channel ID", "lbttcp.channel.channel", FT_UINT64, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_lbttcp_channel_client,
{ "Channel Client", "lbttcp.channel.client", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
};
static gint * ett[] =
{
&ett_lbttcp,
&ett_lbttcp_channel
};
module_t * lbttcp_module;
uat_t * tag_uat;
proto_lbttcp = proto_register_protocol("LBT TCP Protocol", "LBT-TCP", "lbttcp");
proto_register_field_array(proto_lbttcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
lbttcp_module = prefs_register_protocol_subtree("29West", proto_lbttcp, proto_reg_handoff_lbttcp);
prefs_register_uint_preference(lbttcp_module,
"source_port_low",
"Source port range low (default " MAKESTRING(LBTTCP_DEFAULT_SOURCE_PORT_LOW)")",
"Set the low end of the LBT-TCP source TCP port range (context transport_tcp_port_low)",
10,
&global_lbttcp_source_port_low);
prefs_register_uint_preference(lbttcp_module,
"source_port_high",
"Source port range high (default " MAKESTRING(LBTTCP_DEFAULT_SOURCE_PORT_HIGH)")",
"Set the high end of the LBT-TCP source TCP port range (context transport_tcp_port_high)",
10,
&global_lbttcp_source_port_high);
prefs_register_uint_preference(lbttcp_module,
"request_port_low",
"Request port range low (default " MAKESTRING(LBTTCP_DEFAULT_REQUEST_PORT_LOW)")",
"Set the low end of the LBT-TCP request TCP port range (context request_tcp_port_low)",
10,
&global_lbttcp_request_port_low);
prefs_register_uint_preference(lbttcp_module,
"request_port_high",
"Request port range high (default " MAKESTRING(LBTTCP_DEFAULT_REQUEST_PORT_HIGH)")",
"Set the high end of the LBT-TCP request TCP port range (context request_tcp_port_high)",
10,
&global_lbttcp_request_port_high);
prefs_register_uint_preference(lbttcp_module,
"store_port_low",
"UME Store port range low (default " MAKESTRING(LBTTCP_DEFAULT_STORE_PORT_LOW)")",
"Set the low end of the LBT-TCP UME Store TCP port range",
10,
&global_lbttcp_store_port_low);
prefs_register_uint_preference(lbttcp_module,
"store_port_high",
"UME Store port range high (default " MAKESTRING(LBTTCP_DEFAULT_STORE_PORT_HIGH)")",
"Set the high end of the LBT-TCP UME Store TCP port range",
10,
&global_lbttcp_store_port_high);
prefs_register_bool_preference(lbttcp_module,
"use_lbttcp_domain",
"Use LBT-TCP tag table",
"Use table of LBT-TCP tags to decode the packet instead of above values",
&global_lbttcp_use_tag);
tag_uat = uat_new("LBT-TCP tag definitions",
sizeof(lbttcp_tag_entry_t),
"lbttcp_domains",
TRUE,
(void * *)&lbttcp_tag_entry,
&lbttcp_tag_count,
UAT_AFFECTS_DISSECTION,
NULL,
lbttcp_tag_copy_cb,
lbttcp_tag_update_cb,
lbttcp_tag_free_cb,
NULL,
lbttcp_tag_array);
prefs_register_uat_preference(lbttcp_module,
"tnw_lbttcp_tags",
"LBT-TCP Tags",
"A table to define LBT-TCP tags",
tag_uat);
}
void proto_reg_handoff_lbttcp(void)
{
static gboolean already_registered = FALSE;
if (!already_registered)
{
lbttcp_dissector_handle = create_dissector_handle(dissect_lbttcp, proto_lbttcp);
dissector_add_for_decode_as("tcp.port", lbttcp_dissector_handle);
heur_dissector_add("tcp", test_lbttcp_packet, "LBT over TCP", "lbttcp_tcp", proto_lbttcp, HEURISTIC_ENABLE);
}
if (global_lbttcp_source_port_low <= global_lbttcp_source_port_high)
{
lbttcp_source_port_low = global_lbttcp_source_port_low;
lbttcp_source_port_high = global_lbttcp_source_port_high;
}
if (global_lbttcp_request_port_low <= global_lbttcp_request_port_high)
{
lbttcp_request_port_low = global_lbttcp_request_port_low;
lbttcp_request_port_high = global_lbttcp_request_port_high;
}
if (global_lbttcp_store_port_low <= global_lbttcp_store_port_high)
{
lbttcp_store_port_low = global_lbttcp_store_port_low;
lbttcp_store_port_high = global_lbttcp_store_port_high;
}
lbttcp_use_tag = global_lbttcp_use_tag;
already_registered = TRUE;
}
