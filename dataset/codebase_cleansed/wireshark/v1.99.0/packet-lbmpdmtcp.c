static void lbmtcp_order_key(lbmtcp_transport_t * transport)
{
gboolean swap = FALSE;
int compare;
compare = CMP_ADDRESS(&(transport->addr1), &(transport->addr2));
if (compare > 0)
{
swap = TRUE;
}
else if (compare == 0)
{
if (transport->port1 > transport->port2)
{
swap = TRUE;
}
}
if (swap)
{
address addr;
guint16 port;
COPY_ADDRESS_SHALLOW(&addr, &(transport->addr1));
COPY_ADDRESS_SHALLOW(&(transport->addr2), &(transport->addr1));
COPY_ADDRESS_SHALLOW(&(transport->addr1), &addr);
port = transport->port2;
transport->port2 = transport->port1;
transport->port1 = port;
}
}
static lbmtcp_transport_t * lbmtcp_transport_add(const address * address1, guint16 port1, const address * address2, guint16 port2, guint32 frame)
{
lbmtcp_transport_t * entry;
conversation_t * conv = NULL;
conv = find_conversation(frame, address1, address2, PT_TCP, port1, port2, 0);
if (conv == NULL)
{
conv = conversation_new(frame, address1, address2, PT_TCP, port1, port2, 0);
}
entry = (lbmtcp_transport_t *) conversation_get_proto_data(conv, lbmpdm_tcp_protocol_handle);
if (entry != NULL)
{
return (entry);
}
entry = wmem_new(wmem_file_scope(), lbmtcp_transport_t);
SE_COPY_ADDRESS(&(entry->addr1), address1);
entry->port1 = port1;
SE_COPY_ADDRESS(&(entry->addr2), address2);
entry->port2 = port2;
lbmtcp_order_key(entry);
entry->channel = lbm_channel_assign(LBM_CHANNEL_TCP);
conversation_add_proto_data(conv, lbmpdm_tcp_protocol_handle, (void *) entry);
return (entry);
}
static void lbmpdm_tcp_tag_update_cb(void * record, const char * * error_string)
{
lbmpdm_tcp_tag_entry_t * tag = (lbmpdm_tcp_tag_entry_t *)record;
if (tag->name == NULL)
{
*error_string = g_strdup_printf("Tag name can't be empty");
}
else
{
g_strstrip(tag->name);
if (tag->name[0] == 0)
{
*error_string = g_strdup_printf("Tag name can't be empty");
}
}
}
static void * lbmpdm_tcp_tag_copy_cb(void * destination, const void * source, size_t length _U_)
{
const lbmpdm_tcp_tag_entry_t * src = (const lbmpdm_tcp_tag_entry_t *)source;
lbmpdm_tcp_tag_entry_t * dest = (lbmpdm_tcp_tag_entry_t *)destination;
dest->name = g_strdup(src->name);
dest->port_low = src->port_low;
dest->port_high = src->port_high;
return (dest);
}
static void lbmpdm_tcp_tag_free_cb(void * record)
{
lbmpdm_tcp_tag_entry_t * tag = (lbmpdm_tcp_tag_entry_t *)record;
if (tag->name != NULL)
{
g_free(tag->name);
tag->name = NULL;
}
}
static const lbmpdm_tcp_tag_entry_t * lbmpdm_tcp_tag_locate(packet_info * pinfo)
{
guint idx;
const lbmpdm_tcp_tag_entry_t * tag = NULL;
if (!lbmpdm_tcp_use_tag)
{
return (NULL);
}
for (idx = 0; idx < lbmpdm_tcp_tag_count; ++idx)
{
tag = &(lbmpdm_tcp_tag_entry[idx]);
if (((pinfo->srcport >= tag->port_low) && (pinfo->srcport <= tag->port_high))
|| ((pinfo->destport >= tag->port_low) && (pinfo->destport <= tag->port_high)))
{
return (tag);
}
}
return (NULL);
}
static char * lbmpdm_tcp_tag_find(packet_info * pinfo)
{
const lbmpdm_tcp_tag_entry_t * tag = NULL;
if (!lbmpdm_tcp_use_tag)
{
return (NULL);
}
tag = lbmpdm_tcp_tag_locate(pinfo);
if (tag != NULL)
{
return tag->name;
}
return (NULL);
}
static guint get_lbmpdm_tcp_pdu_length(packet_info * pinfo _U_, tvbuff_t * tvb, int offset)
{
int encoding;
int packet_len = 0;
packet_len = 0;
if (!lbmpdm_verify_payload(tvb, offset, &encoding, &packet_len))
{
packet_len = 0;
}
return (packet_len);
}
static int dissect_lbmpdm_tcp_pdu(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * dissector_data _U_)
{
proto_tree * lbmpdm_tcp_tree = NULL;
proto_item * ti = NULL;
lbmtcp_transport_t * transport = NULL;
char * tag_name = NULL;
guint64 channel = LBM_CHANNEL_NO_CHANNEL;
if (lbmpdm_tcp_use_tag)
{
tag_name = lbmpdm_tcp_tag_find(pinfo);
}
if (tag_name != NULL)
{
ti = proto_tree_add_protocol_format(tree, lbmpdm_tcp_protocol_handle, tvb, 0, -1, "LBMPDM-TCP Protocol (Tag: %s)", tag_name);
}
else
{
ti = proto_tree_add_protocol_format(tree, lbmpdm_tcp_protocol_handle, tvb, 0, -1, "LBMPDM-TCP Protocol");
}
lbmpdm_tcp_tree = proto_item_add_subtree(ti, ett_lbmpdm_tcp);
transport = lbmtcp_transport_add(&(pinfo->src), pinfo->srcport, &(pinfo->dst), pinfo->destport, pinfo->fd->num);
if (transport != NULL)
{
channel = transport->channel;
}
if (tag_name != NULL)
{
proto_item * item = NULL;
item = proto_tree_add_string(lbmpdm_tcp_tree, hf_lbmpdm_tcp_tag, tvb, 0, 0, tag_name);
PROTO_ITEM_SET_GENERATED(item);
}
if (channel != LBM_CHANNEL_NO_CHANNEL)
{
proto_item * item = NULL;
item = proto_tree_add_uint64(lbmpdm_tcp_tree, hf_lbmpdm_tcp_channel, tvb, 0, 0, channel);
PROTO_ITEM_SET_GENERATED(item);
}
return (lbmpdm_dissect_lbmpdm_payload(tvb, 0, pinfo, tree, channel));
}
static void dissect_lbmpdm_tcp(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
char * tag_name = NULL;
col_add_str(pinfo->cinfo, COL_PROTOCOL, "LBMPDM-TCP");
col_clear(pinfo->cinfo, COL_INFO);
if (lbmpdm_tcp_use_tag)
{
tag_name = lbmpdm_tcp_tag_find(pinfo);
}
if (tag_name != NULL)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "[Tag: %s]", tag_name);
}
col_set_fence(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, lbmpdm_get_minimum_length(),
get_lbmpdm_tcp_pdu_length, dissect_lbmpdm_tcp_pdu, NULL);
}
static gboolean test_lbmpdm_tcp_packet(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * user_data _U_)
{
int encoding = 0;
int packet_len = 0;
if (pinfo->ptype != PT_TCP)
{
return (FALSE);
}
if ((pinfo->dst.type != AT_IPv4) || (pinfo->dst.len != 4))
{
return (FALSE);
}
if (!lbmpdm_verify_payload(tvb, 0, &encoding, &packet_len))
{
return (FALSE);
}
if (lbmpdm_tcp_use_tag)
{
if (lbmpdm_tcp_tag_find(pinfo) != NULL)
{
dissect_lbmpdm_tcp(tvb, pinfo, tree);
return (TRUE);
}
else
{
return (FALSE);
}
}
if (!(((pinfo->srcport >= lbmpdm_tcp_port_low) && (pinfo->srcport <= lbmpdm_tcp_port_high))
|| ((pinfo->destport >= lbmpdm_tcp_port_low) && (pinfo->destport <= lbmpdm_tcp_port_high))))
{
return (FALSE);
}
dissect_lbmpdm_tcp(tvb, pinfo, tree);
return (TRUE);
}
void proto_register_lbmpdm_tcp(void)
{
static hf_register_info hf[] =
{
{ &hf_lbmpdm_tcp_tag,
{ "Tag", "lbmpdm_tcp.tag", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_lbmpdm_tcp_channel,
{ "Channel ID", "lbmpdm_tcp.channel", FT_UINT64, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL } },
};
static gint * ett[] =
{
&ett_lbmpdm_tcp,
};
module_t * lbmpdm_tcp_module;
uat_t * tag_uat;
lbmpdm_tcp_protocol_handle = proto_register_protocol("LBMPDM over TCP Protocol", "LBMPDM-TCP", "lbmpdm_tcp");
proto_register_field_array(lbmpdm_tcp_protocol_handle, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
lbmpdm_tcp_module = prefs_register_protocol_subtree("29West", lbmpdm_tcp_protocol_handle, proto_reg_handoff_lbmpdm_tcp);
prefs_register_uint_preference(lbmpdm_tcp_module,
"port_low",
"Port range low (default " MAKESTRING(LBMPDM_TCP_DEFAULT_PORT_LOW)")",
"Set the low end of the TCP port range",
10,
&global_lbmpdm_tcp_port_low);
prefs_register_uint_preference(lbmpdm_tcp_module,
"port_high",
"Port range high (default " MAKESTRING(LBMPDM_TCP_DEFAULT_PORT_HIGH)")",
"Set the high end of the port range",
10,
&global_lbmpdm_tcp_port_high);
prefs_register_bool_preference(lbmpdm_tcp_module,
"use_lbmpdm_tcp_domain",
"Use LBMPDM-TCP tag table",
"Use table of LBMPDM-TCP tags to decode the packet instead of above values",
&global_lbmpdm_tcp_use_tag);
tag_uat = uat_new("LBMPDM-TCP tag definitions",
sizeof(lbmpdm_tcp_tag_entry_t),
"lbmpdm_tcp_domains",
TRUE,
(void * *)&lbmpdm_tcp_tag_entry,
&lbmpdm_tcp_tag_count,
UAT_AFFECTS_DISSECTION,
NULL,
lbmpdm_tcp_tag_copy_cb,
lbmpdm_tcp_tag_update_cb,
lbmpdm_tcp_tag_free_cb,
NULL,
lbmpdm_tcp_tag_array);
prefs_register_uat_preference(lbmpdm_tcp_module,
"tnw_lbmpdm_tcp_tags",
"LBMPDM-TCP Tags",
"A table to define LBMPDM-TCP tags",
tag_uat);
}
void proto_reg_handoff_lbmpdm_tcp(void)
{
static gboolean already_registered = FALSE;
if (!already_registered)
{
lbmpdm_tcp_dissector_handle = create_dissector_handle(dissect_lbmpdm_tcp, lbmpdm_tcp_protocol_handle);
dissector_add_for_decode_as("tcp.port", lbmpdm_tcp_dissector_handle);
heur_dissector_add("tcp", test_lbmpdm_tcp_packet, lbmpdm_tcp_protocol_handle);
}
if (global_lbmpdm_tcp_port_low <= global_lbmpdm_tcp_port_high)
{
lbmpdm_tcp_port_low = global_lbmpdm_tcp_port_low;
lbmpdm_tcp_port_high = global_lbmpdm_tcp_port_high;
}
lbmpdm_tcp_use_tag = global_lbmpdm_tcp_use_tag;
already_registered = TRUE;
}
