static void elasticsearch_format_version(gchar *buf, guint32 value) {
g_snprintf(buf, ELASTICSEARCH_VERSION_LABEL_LENGTH, "%d.%d.%d (%d)", (value / 1000000) % 100,
(value / 10000) % 100, (value/ 100) % 100, value);
}
static vint_t read_vint(tvbuff_t *tvb, int offset){
vint_t vint;
guint8 b = tvb_get_guint8(tvb, offset);
vint.value = b & 0x7F;
if ((b & 0x80) == 0) {
vint.length = 1;
return vint;
}
b = tvb_get_guint8(tvb, offset+1);
vint.value |= (b & 0x7F) << 7;
if ((b & 0x80) == 0) {
vint.length = 2;
return vint;
}
b = tvb_get_guint8(tvb, offset+2);
vint.value |= (b & 0x7F) << 14;
if ((b & 0x80) == 0) {
vint.length = 3;
return vint;
}
b = tvb_get_guint8(tvb, offset+3);
vint.value |= (b & 0x7F) << 21;
if ((b & 0x80) == 0) {
vint.length = 4;
return vint;
}
b = tvb_get_guint8(tvb, offset+4);
vint.length = 5;
vint.value |= ((b & 0x7F) << 28);
return vint;
}
static vstring_t read_vstring(tvbuff_t *tvb, int offset) {
vstring_t vstring;
int string_starting_offset;
int string_length;
vstring.vint_length = read_vint(tvb, offset);
string_starting_offset = offset + vstring.vint_length.length;
string_length = vstring.vint_length.value;
vstring.value = tvb_get_string_enc(wmem_packet_scope(), tvb, string_starting_offset, string_length, ENC_UTF_8);
vstring.length = string_length + vstring.vint_length.length;
return vstring;
}
static int elasticsearch_partial_dissect_address(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset) {
proto_tree *address_tree;
proto_item *address_item;
int start_offset;
guint8 es_address_format;
guint8 address_length;
vstring_t address_name;
guint16 address_type_id;
start_offset = offset;
address_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_elasticsearch_address, &address_item, "Address" );
proto_tree_add_item(address_tree, hf_elasticsearch_address_type, tvb, offset, 2, ENC_BIG_ENDIAN);
address_type_id = tvb_get_ntohs(tvb, offset);
offset += 2;
if(address_type_id != ADDRESS_TYPE_SOCKET) {
expert_add_info(pinfo, tree, &ei_elasticsearch_unsupported_address_type);
return offset;
}
es_address_format = tvb_get_guint8(tvb, offset);
proto_tree_add_item(address_tree, hf_elasticsearch_address_format, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch(es_address_format) {
case ADDRESS_FORMAT_NUEMRIC:
address_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(address_tree, hf_elasticsearch_address_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (address_length == IPv4_ADDRESS_LENGTH) {
proto_tree_add_item(address_tree, hf_elasticsearch_address_ipv4, tvb, offset, 4, ENC_NA);
offset += 4;
}
else {
proto_tree_add_item(address_tree, hf_elasticsearch_address_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(address_tree, hf_elasticsearch_address_ipv6_scope_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case ADDRESS_FORMAT_STRING:
address_name = read_vstring(tvb, offset);
proto_tree_add_string(address_tree, hf_elasticsearch_address_name, tvb, offset, address_name.length, address_name.value);
offset += address_name.length;
break;
default:
expert_add_info(pinfo, tree, &ei_elasticsearch_unsupported_address_format);
break;
}
proto_tree_add_item(address_item, hf_elasticsearch_address_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_len(address_item, offset - start_offset);
return offset;
}
static version_t elasticsearch_parse_version(tvbuff_t *tvb, int offset){
version_t version;
vint_t raw_version_value;
raw_version_value = read_vint(tvb, offset);
version.length = raw_version_value.length;
version.value = raw_version_value.value;
g_snprintf(version.string, sizeof(version.string), "%d.%d.%d", (version.value / 1000000) % 100,
(version.value / 10000) % 100, (version.value/ 100) % 100);
return version;
}
static int dissect_elasticsearch_zen_ping(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_){
int offset = 0;
version_t version;
vstring_t cluster_name;
vstring_t node_name;
vstring_t node_id;
vstring_t host_name;
vstring_t host_address;
vint_t attributes_length;
version_t node_version;
proto_item *root_elasticsearch_item;
proto_tree *elasticsearch_tree;
proto_tree *discovery_node_tree;
proto_item *discovery_node_item;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Elasticsearch");
col_clear(pinfo->cinfo, COL_INFO);
root_elasticsearch_item = proto_tree_add_item(tree, proto_elasticsearch, tvb, 0, -1, ENC_NA);
elasticsearch_tree = proto_item_add_subtree(root_elasticsearch_item,ett_elasticsearch);
col_set_str(pinfo->cinfo, COL_INFO, "Zen Ping: ");
proto_tree_add_item(elasticsearch_tree, hf_elasticsearch_internal_header, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
version = elasticsearch_parse_version(tvb, offset);
proto_tree_add_uint(elasticsearch_tree, hf_elasticsearch_version, tvb, offset, version.length, version.value);
offset += version.length;
proto_tree_add_item(elasticsearch_tree, hf_elasticsearch_ping_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
cluster_name = read_vstring(tvb, offset);
proto_tree_add_string(elasticsearch_tree, hf_elasticsearch_cluster_name, tvb, offset, cluster_name.length, cluster_name.value);
col_append_fstr(pinfo->cinfo, COL_INFO, "cluster=%s", cluster_name.value);
offset += cluster_name.length;
discovery_node_tree = proto_tree_add_subtree(elasticsearch_tree, tvb, offset, -1, ett_elasticsearch_discovery_node, &discovery_node_item, "Node" );
node_name = read_vstring(tvb, offset);
proto_tree_add_string(discovery_node_tree, hf_elasticsearch_node_name, tvb, offset, node_name.length, node_name.value);
col_append_fstr(pinfo->cinfo, COL_INFO, ", name=%s", node_name.value);
offset += node_name.length;
col_append_fstr(pinfo->cinfo, COL_INFO, ", version=%s", version.string);
node_id = read_vstring(tvb, offset);
proto_tree_add_string(discovery_node_tree, hf_elasticsearch_node_id, tvb, offset, node_id.length, node_id.value);
offset += node_id.length;
host_name = read_vstring(tvb, offset);
proto_tree_add_string(discovery_node_tree, hf_elasticsearch_host_name, tvb, offset, host_name.length, host_name.value);
offset += host_name.length;
host_address = read_vstring(tvb, offset);
proto_tree_add_string(discovery_node_tree, hf_elasticsearch_host_address, tvb, offset, host_address.length, host_address.value);
offset += host_address.length;
offset = elasticsearch_partial_dissect_address(tvb, pinfo, discovery_node_tree, offset);
attributes_length = read_vint(tvb, offset);
proto_tree_add_uint(discovery_node_tree, hf_elasticsearch_attributes_length, tvb, offset, attributes_length.length, attributes_length.value);
offset += attributes_length.length;
node_version = elasticsearch_parse_version(tvb, offset);
proto_tree_add_uint(elasticsearch_tree, hf_elasticsearch_version, tvb, offset, node_version.length, node_version.value);
offset += node_version.length;
return offset;
}
static int elasticsearch_binary_header_is_valid(tvbuff_t *tvb){
return tvb_captured_length(tvb) >= 2 && tvb_get_ntohs(tvb, 0) == ELASTICSEARCH_BINARY_HEADER_TOKEN;
}
static int elasticsearch_transport_status_flag_is_a_response(gint8 transport_status_flags) {
return transport_status_flags & ELASTICSEARCH_STATUS_FLAG_RESPONSE;
}
static int transport_status_flag_is_a_request(gint8 transport_status_flags){
return !elasticsearch_transport_status_flag_is_a_response(transport_status_flags);
}
static int elasticsearch_is_compressed(gint8 transport_status_flags){
return transport_status_flags & ELASTICSEARCH_STATUS_FLAG_COMPRESSED;
}
static void elasticsearch_decode_binary_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gint8 transport_status_flags) {
vstring_t action;
if(elasticsearch_is_compressed(transport_status_flags)){
proto_tree_add_item(tree, hf_elasticsearch_data_compressed, tvb, offset, -1, ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "[COMPRESSED], ");
} else {
action = read_vstring(tvb, offset);
proto_tree_add_string(tree, hf_elasticsearch_action, tvb, offset, action.length, action.value);
col_append_fstr(pinfo->cinfo, COL_INFO, "action=%s, ", action.value);
offset += action.length;
proto_tree_add_item(tree, hf_elasticsearch_data, tvb, offset, -1, ENC_NA);
}
}
static void append_status_info_to_column(packet_info *pinfo, gint8 transport_status_flags) {
if(transport_status_flags & ELASTICSEARCH_STATUS_FLAG_ERROR){
col_append_str(pinfo->cinfo, COL_INFO, "[ERROR], ");
}else{
col_append_str(pinfo->cinfo, COL_INFO, "[OK], ");
}
}
static void elasticsearch_decode_binary_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gint8 transport_status_flags) {
append_status_info_to_column(pinfo, transport_status_flags);
if(elasticsearch_is_compressed(transport_status_flags)){
col_append_str(pinfo->cinfo, COL_INFO, "[COMPRESSED], ");
proto_tree_add_item(tree, hf_elasticsearch_data_compressed, tvb, offset, -1, ENC_NA);
} else {
proto_tree_add_item(tree, hf_elasticsearch_data, tvb, offset, -1, ENC_NA);
}
}
static int elasticsearch_dissect_valid_binary_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_){
int offset = 0;
gint8 transport_status_flags;
guint64 request_id;
proto_item *transport_status_flags_item;
proto_tree *transport_status_flags_tree;
proto_tree_add_item(tree, hf_elasticsearch_header_token, tvb, offset, 2, ENC_ASCII|ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_elasticsearch_header_message_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_elasticsearch_header_request_id, tvb, offset, 8, ENC_BIG_ENDIAN);
request_id = tvb_get_ntoh64(tvb, offset);
offset += 8;
transport_status_flags = tvb_get_guint8(tvb, offset);
transport_status_flags_item = proto_tree_add_uint(tree, hf_elasticsearch_header_status_flags, tvb, offset, 1, transport_status_flags);
transport_status_flags_tree = proto_item_add_subtree(transport_status_flags_item, ett_elasticsearch_status_flags);
if(elasticsearch_transport_status_flag_is_a_response(transport_status_flags)){
col_append_str(pinfo->cinfo, COL_INFO, "Response: ");
} else {
col_append_str(pinfo->cinfo, COL_INFO, "Request: ");
}
proto_tree_add_bits_item(transport_status_flags_tree, hf_elasticsearch_header_status_flags_compression, tvb, offset * BITS_IN_A_BYTE + 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(transport_status_flags_tree, hf_elasticsearch_header_status_flags_error, tvb, offset * BITS_IN_A_BYTE + 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(transport_status_flags_tree, hf_elasticsearch_header_status_flags_message_type, tvb, offset * BITS_IN_A_BYTE + 7, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_elasticsearch_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (transport_status_flag_is_a_request(transport_status_flags)) {
elasticsearch_decode_binary_request(tvb, pinfo, tree, offset, transport_status_flags);
} else {
elasticsearch_decode_binary_response(tvb, pinfo, tree, offset, transport_status_flags);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "request_id=%"G_GUINT64_FORMAT" ", request_id);
return tvb_captured_length(tvb);
}
static guint elasticsearch_get_binary_message_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
return (guint)tvb_get_ntohl(tvb, offset+ELASTICSEARCH_MESSAGE_LENGTH_OFFSET) + ELASTICSEARCH_HEADER_LENGTH;
}
static int dissect_elasticsearch_binary(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data) {
int offset = 0;
proto_item *root_elasticsearch_item;
proto_tree *elasticsearch_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Elasticsearch");
col_clear(pinfo->cinfo, COL_INFO);
root_elasticsearch_item = proto_tree_add_item(tree, proto_elasticsearch, tvb, 0, -1, ENC_NA);
elasticsearch_tree = proto_item_add_subtree(root_elasticsearch_item,ett_elasticsearch);
if(elasticsearch_binary_header_is_valid(tvb)){
tcp_dissect_pdus(tvb, pinfo, elasticsearch_tree, TRUE, ELASTICSEARCH_HEADER_LENGTH,
elasticsearch_get_binary_message_len, elasticsearch_dissect_valid_binary_packet, data);
} else {
proto_tree_add_item(elasticsearch_tree, hf_elasticsearch_data, tvb, offset, -1, ENC_NA);
expert_add_info(pinfo, elasticsearch_tree, &ei_elasticsearch_unsupported_version);
}
return tvb_captured_length(tvb);
}
void proto_register_elasticsearch(void) {
static hf_register_info hf[] = {
{ &hf_elasticsearch_internal_header,
{ "Internal header", "elasticsearch.internal_header",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_version,
{ "Version", "elasticsearch.version",
FT_UINT32, BASE_CUSTOM,
CF_FUNC(elasticsearch_format_version), 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_ping_request_id,
{ "Ping ID", "elasticsearch.ping_request_id",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_cluster_name,
{ "Cluster name", "elasticsearch.cluster_name",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_node_name,
{ "Node name", "elasticsearch.node_name",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_node_id,
{ "Node ID", "elasticsearch.node_id",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_host_name,
{ "Hostname", "elasticsearch.host_name",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_host_address,
{ "Host address", "elasticsearch.host_address",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_address_type,
{ "Type", "elasticsearch.address.type",
FT_UINT16, BASE_DEC,
VALS(address_types), 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_address_format,
{ "Format", "elasticsearch.address.format",
FT_UINT8, BASE_DEC,
VALS(address_format), 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_address_name,
{ "Name", "elasticsearch.address.name",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_address_length,
{ "Length", "elasticsearch.address.length",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_address_ipv4,
{ "IP", "elasticsearch.address.ipv4",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_address_ipv6,
{ "IP", "elasticsearch.address.ipv6",
FT_IPv6, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_address_ipv6_scope_id,
{ "IP", "elasticsearch.address.ipv6.scope_id",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_address_port,
{ "Port", "elasticsearch.address.port",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_attributes_length,
{ "Attributes length", "elasticsearch.attributes.length",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_header_token,
{ "Token", "elasticsearch.header.token",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_header_message_length,
{ "Message length", "elasticsearch.header.message_length",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_header_request_id,
{ "Request ID", "elasticsearch.header.request_id",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_header_status_flags,
{ "Status flags", "elasticsearch.header.status_flags",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_header_status_flags_message_type,
{ "Message type", "elasticsearch.header.status_flags.message_type",
FT_UINT8, BASE_DEC,
VALS(status_flag_message_type), 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_header_status_flags_error,
{ "Error", "elasticsearch.header.status_flags.error",
FT_BOOLEAN, BASE_NONE,
TFS(&tfs_set_notset), 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_header_status_flags_compression,
{ "Compression", "elasticsearch.header.status_flags.compression",
FT_BOOLEAN, BASE_NONE,
TFS(&tfs_set_notset), 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_action,
{ "Action", "elasticsearch.action",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_data,
{ "Data", "elasticsearch.data",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{ &hf_elasticsearch_data_compressed,
{ "Compressed data", "elasticsearch.data_compressed",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_elasticsearch,
&ett_elasticsearch_address,
&ett_elasticsearch_discovery_node,
&ett_elasticsearch_status_flags,
};
static ei_register_info ei[] = {
{ &ei_elasticsearch_unsupported_version, { "elasticsearch.version.unsupported", PI_UNDECODED, PI_WARN, "Unsupported header type: Elasticsearch version < 0.20.0RC1", EXPFILL }},
{ &ei_elasticsearch_unsupported_address_format, { "elasticsearch.address.format.unsupported", PI_MALFORMED, PI_WARN, "Unsupported address format", EXPFILL }},
{ &ei_elasticsearch_unsupported_address_type, { "elasticsearch.address.type.unsupported", PI_MALFORMED, PI_WARN, "Unsupported address type", EXPFILL }},
};
expert_module_t*expert_elasticsearch;
proto_elasticsearch = proto_register_protocol("Elasticsearch", "Elasticsearch", "elasticsearch");
expert_elasticsearch = expert_register_protocol(proto_elasticsearch);
expert_register_field_array(expert_elasticsearch, ei, array_length(ei));
proto_register_field_array(proto_elasticsearch, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_elasticsearch(void) {
dissector_handle_t elasticsearch_handle_binary;
dissector_handle_t elasticsearch_zen_handle;
elasticsearch_handle_binary = create_dissector_handle(dissect_elasticsearch_binary, proto_elasticsearch);
elasticsearch_zen_handle = create_dissector_handle(dissect_elasticsearch_zen_ping, proto_elasticsearch);
dissector_add_uint_with_preference("udp.port", ELASTICSEARCH_DISCOVERY_PORT, elasticsearch_zen_handle);
dissector_add_uint_with_preference("tcp.port", ELASTICSEARCH_BINARY_PORT, elasticsearch_handle_binary);
}
