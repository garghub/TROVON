static void info_summary_append_ex(packet_info *pinfo,
guint32 writer_id,
guint32 status_info) {
char buffer[10] = "(?[??])";
switch(writer_id)
{
case ENTITYID_PARTICIPANT:
buffer[1] = 'P';
break;
case ENTITYID_BUILTIN_TOPIC_WRITER:
buffer[1] = 't';
break;
case ENTITYID_BUILTIN_PUBLICATIONS_WRITER:
buffer[1] = 'w';
break;
case ENTITYID_BUILTIN_SUBSCRIPTIONS_WRITER:
buffer[1] = 'r';
break;
case ENTITYID_BUILTIN_SDP_PARTICIPANT_WRITER:
buffer[1] = 'p';
break;
case ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_WRITER:
buffer[1] = 'm';
break;
default:
return;
}
switch(status_info) {
case 0: buffer[3] = '_'; buffer[4] = '_'; break;
case 1: buffer[3] = '_'; buffer[4] = 'D'; break;
case 2: buffer[3] = 'U'; buffer[4] = '_'; break;
case 3: buffer[3] = 'U'; buffer[4] = 'D'; break;
default:
buffer[2] = ')';
buffer[3] = '\0';
}
col_append_str(pinfo->cinfo, COL_INFO, buffer);
}
guint16 rtps_util_add_protocol_version(proto_tree *tree,
tvbuff_t * tvb,
gint offset) {
proto_item * ti;
proto_tree * version_tree;
guint16 version;
version = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_uint_format(tree, hf_rtps_protocol_version, tvb, offset, 2,
version, "Protocol version: %d.%d",
tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset+1));
version_tree = proto_item_add_subtree(ti, ett_rtps_proto_version);
proto_tree_add_item(version_tree, hf_rtps_protocol_version_major, tvb, offset, 1, ENC_NA);
proto_tree_add_item(version_tree, hf_rtps_protocol_version_minor, tvb, offset+1, 1, ENC_NA);
return version;
}
guint16 rtps_util_add_vendor_id(proto_tree *tree,
tvbuff_t * tvb,
gint offset) {
guint8 major, minor;
guint16 vendor_id;
major = tvb_get_guint8(tvb, offset);
minor = tvb_get_guint8(tvb, offset+1);
vendor_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_rtps_vendor_id, tvb, offset, 2, vendor_id,
"%02d.%02d (%s)", major, minor,
val_to_str_const(vendor_id, vendor_vals, "Unknown"));
return vendor_id;
}
void rtps_util_add_locator_t(proto_tree *tree, packet_info *pinfo, tvbuff_t * tvb, gint offset,
gboolean little_endian, const guint8 * label) {
proto_item * ti;
proto_tree * locator_tree;
gint32 kind;
guint32 port;
ti = proto_tree_add_text(tree, tvb, offset, 24, "%s", label);
locator_tree = proto_item_add_subtree(ti, ett_rtps_locator);
kind = NEXT_guint32(tvb, offset, little_endian);
port = NEXT_guint32(tvb, offset+4, little_endian);
proto_tree_add_uint(locator_tree, hf_rtps_locator_kind, tvb, offset, 4, kind);
ti = proto_tree_add_int(locator_tree, hf_rtps_locator_port, tvb, offset+4, 4, port);
if (port == 0)
expert_add_info(pinfo, ti, &ei_rtps_locator_port);
if (kind == LOCATOR_KIND_UDPV4) {
proto_tree_add_item(locator_tree, hf_rtps_locator_ipv4, tvb, offset+20, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(locator_tree, hf_rtps_locator_ipv6, tvb, offset+8, 16, ENC_NA);
}
}
int rtps_util_add_locator_list(proto_tree *tree, packet_info *pinfo, tvbuff_t * tvb,
gint offset, const guint8* label, gboolean little_endian) {
proto_item *ti;
proto_tree *locator_tree;
guint32 num_locators;
num_locators = NEXT_guint32(tvb, offset, little_endian);
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 4,
"%s: %d Locators", label, num_locators);
} else {
return offset + 4 + ((num_locators > 0) ? (24 * num_locators) : 0);
}
offset += 4;
if (num_locators > 0) {
guint32 i;
char temp_buff[20];
locator_tree = proto_item_add_subtree(ti, ett_rtps_locator_udp_v4);
for (i = 0; i < num_locators; ++i) {
g_snprintf(temp_buff, 20, "Locator[%d]", i);
rtps_util_add_locator_t(locator_tree, pinfo, tvb, offset,
little_endian, temp_buff);
offset += 24;
}
}
return offset;
}
void rtps_util_add_ipv4_address_t(proto_tree *tree, packet_info *pinfo, tvbuff_t * tvb, gint offset,
gboolean little_endian, int hf_item) {
guint32 addr;
proto_item* ti;
addr = NEXT_guint32(tvb, offset, little_endian);
ti = proto_tree_add_ipv4(tree, hf_item, tvb, offset, 4, addr);
if (addr == IPADDRESS_INVALID)
expert_add_info(pinfo, ti, &ei_rtps_ip_invalid);
}
void rtps_util_add_locator_udp_v4(proto_tree *tree, packet_info *pinfo, tvbuff_t * tvb,
gint offset, const guint8 * label, gboolean little_endian) {
proto_item * ti;
proto_tree * locator_tree;
guint32 port;
ti = proto_tree_add_text(tree, tvb, offset, 8, "%s", label);
locator_tree = proto_item_add_subtree(ti, ett_rtps_locator_udp_v4);
rtps_util_add_ipv4_address_t(locator_tree, pinfo, tvb, offset,
little_endian, hf_rtps_locator_udp_v4);
port = NEXT_guint32(tvb, offset+4, little_endian);
ti = proto_tree_add_uint(locator_tree, hf_rtps_locator_udp_v4_port, tvb, offset, 4, port);
if (port == PORT_INVALID)
expert_add_info(pinfo, ti, &ei_rtps_port_invalid);
}
static void rtps_util_add_guid_prefix_v1(proto_tree *tree, tvbuff_t *tvb, gint offset,
int hf_prefix, int hf_host_id, int hf_app_id, int hf_app_id_instance_id,
int hf_app_id_app_kind, const guint8 * label) {
guint64 prefix;
guint32 host_id, app_id, instance_id;
guint8 app_kind;
proto_item *ti;
proto_tree *guid_tree, *appid_tree;
const guint8 * safe_label = (label == NULL) ? (const guint8 *)"guidPrefix" : label;
prefix = tvb_get_ntoh64(tvb, offset);
host_id = tvb_get_ntohl(tvb, offset);
app_id = tvb_get_ntohl(tvb, offset + 4);
instance_id = (app_id >> 8);
app_kind = (app_id & 0xff);
if (tree != NULL) {
ti = proto_tree_add_uint64_format(tree, hf_prefix, tvb, offset, 8, prefix,
"%s=%08x %08x { hostId=%08x, appId=%08x (%s: %06x) }",
safe_label, host_id, app_id, host_id, app_id,
val_to_str(app_kind, app_kind_vals, "%02x"),
instance_id);
guid_tree = proto_item_add_subtree(ti, ett_rtps_guid_prefix);
proto_tree_add_item(guid_tree, hf_host_id, tvb, offset, 4, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(guid_tree, hf_app_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
appid_tree = proto_item_add_subtree(ti, ett_rtps_app_id);
proto_tree_add_item(appid_tree, hf_app_id_instance_id, tvb, offset+4, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(appid_tree, hf_app_id_app_kind, tvb, offset+7, 1, ENC_BIG_ENDIAN);
}
}
static void rtps_util_add_guid_prefix_v2(proto_tree *tree, tvbuff_t *tvb, gint offset,
int hf_prefix, int hf_host_id, int hf_app_id,
int hf_counter, const guint8 * label) {
const guint8 * safe_label;
safe_label = (label == NULL) ? (const guint8 *)"guidPrefix" : label;
if (tree) {
proto_item * ti, *hidden_item;
proto_tree * guid_tree;
ti = proto_tree_add_text(tree, tvb, offset, 12, "%s", safe_label);
guid_tree = proto_item_add_subtree(ti, ett_rtps_guid_prefix);
hidden_item = proto_tree_add_item(guid_tree, hf_prefix, tvb, offset, 8, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(guid_tree, hf_host_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(guid_tree, hf_app_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(guid_tree, hf_counter, tvb, offset+8, 4, ENC_BIG_ENDIAN);
}
}
int rtps_util_add_entity_id(proto_tree *tree, tvbuff_t * tvb, gint offset,
int hf_item, int hf_item_entity_key, int hf_item_entity_kind,
int subtree_entity_id, const char *label, guint32* entity_id_out) {
guint32 entity_id = tvb_get_ntohl(tvb, offset);
guint32 entity_key = (entity_id >> 8);
guint8 entity_kind = (entity_id & 0xff);
const char *str_predef = try_val_to_str(entity_id, entity_id_vals);
if (entity_id_out != NULL) {
*entity_id_out = entity_id;
}
if (tree != NULL) {
proto_tree * entity_tree;
proto_item * ti;
if (str_predef == NULL) {
ti = proto_tree_add_uint_format(tree, hf_item, tvb, offset, 4, entity_id,
"%s: 0x%08x (%s: 0x%06x)",
label, entity_id,
val_to_str(entity_kind, entity_kind_vals, "unknown kind (%02x)"),
entity_key);
} else {
ti = proto_tree_add_uint_format(tree, hf_item, tvb, offset, 4, entity_id,
"%s: %s (0x%08x)", label, str_predef, entity_id);
}
entity_tree = proto_item_add_subtree(ti, subtree_entity_id);
proto_tree_add_item(entity_tree, hf_item_entity_key, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(entity_tree, hf_item_entity_kind, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
return ( entity_id == ENTITYID_BUILTIN_TOPIC_WRITER ||
entity_id == ENTITYID_BUILTIN_TOPIC_READER ||
entity_id == ENTITYID_BUILTIN_PUBLICATIONS_WRITER ||
entity_id == ENTITYID_BUILTIN_PUBLICATIONS_READER ||
entity_id == ENTITYID_BUILTIN_SUBSCRIPTIONS_WRITER ||
entity_id == ENTITYID_BUILTIN_SUBSCRIPTIONS_READER ||
entity_id == ENTITYID_BUILTIN_SDP_PARTICIPANT_WRITER ||
entity_id == ENTITYID_BUILTIN_SDP_PARTICIPANT_READER );
}
void rtps_util_add_generic_entity_id(proto_tree *tree, tvbuff_t * tvb, gint offset, const char* label,
int hf_item, int hf_item_entity_key, int hf_item_entity_kind,
int subtree_entity_id) {
guint32 entity_id = tvb_get_ntohl(tvb, offset);
guint32 entity_key = (entity_id >> 8);
guint8 entity_kind = (entity_id & 0xff);
const char *str_predef = try_val_to_str(entity_id, entity_id_vals);
proto_item *ti;
proto_tree *entity_tree;
if (str_predef == NULL) {
ti = proto_tree_add_uint_format(tree, hf_item, tvb, offset, 4, entity_id,
"%s: 0x%08x (%s: 0x%06x)", label, entity_id,
val_to_str(entity_kind, entity_kind_vals, "unknown kind (%02x)"),
entity_key);
} else {
ti = proto_tree_add_uint_format_value(tree, hf_item, tvb, offset, 4, entity_id,
"%s: %s (0x%08x)", label, str_predef, entity_id);
}
entity_tree = proto_item_add_subtree(ti, subtree_entity_id);
proto_tree_add_item(entity_tree, hf_item_entity_key, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(entity_tree, hf_item_entity_kind, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
static void rtps_util_add_generic_guid_v1(proto_tree *tree, tvbuff_t * tvb, gint offset,
int hf_guid, int hf_host_id, int hf_app_id, int hf_app_id_instance_id,
int hf_app_id_app_kind, int hf_entity, int hf_entity_key,
int hf_entity_kind) {
guint64 prefix;
guint32 host_id, app_id, entity_id;
proto_item* ti;
proto_tree *guid_tree, *appid_tree, *entity_tree;
prefix = tvb_get_ntoh64(tvb, offset);
host_id = tvb_get_ntohl(tvb, offset);
app_id = tvb_get_ntohl(tvb, offset + 4);
entity_id = tvb_get_ntohl(tvb, offset + 8);
ti = proto_tree_add_uint64_format_value(tree, hf_guid, tvb, offset, 8, prefix, "%08x %08x %08x",
host_id, app_id, entity_id);
guid_tree = proto_item_add_subtree(ti, ett_rtps_generic_guid);
proto_tree_add_item(guid_tree, hf_host_id, tvb, offset, 4, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(guid_tree, hf_app_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
appid_tree = proto_item_add_subtree(ti, ett_rtps_app_id);
proto_tree_add_item(appid_tree, hf_app_id_instance_id, tvb, offset+4, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(appid_tree, hf_app_id_app_kind, tvb, offset+7, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(guid_tree, hf_entity, tvb, offset+8, 4, ENC_BIG_ENDIAN);
entity_tree = proto_item_add_subtree(ti, ett_rtps_entity);
proto_tree_add_item(entity_tree, hf_entity_key, tvb, offset+8, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(entity_tree, hf_entity_kind, tvb, offset+11, 1, ENC_BIG_ENDIAN);
}
static void rtps_util_add_generic_guid_v2(proto_tree *tree, tvbuff_t * tvb, gint offset,
int hf_guid, int hf_host_id, int hf_app_id, int hf_app_id_instance_id,
int hf_app_id_app_kind, int hf_counter,
int hf_entity, int hf_entity_key, int hf_entity_kind) {
guint64 prefix;
guint32 host_id, app_id, entity_id, counter;
proto_item *ti;
proto_tree *guid_tree, *appid_tree, *entity_tree;
prefix = tvb_get_ntoh64(tvb, offset);
host_id = tvb_get_ntohl(tvb, offset);
app_id = tvb_get_ntohl(tvb, offset + 4);
counter = tvb_get_ntohl(tvb, offset + 8);
entity_id = tvb_get_ntohl(tvb, offset + 12);
ti = proto_tree_add_uint64_format_value(tree, hf_guid, tvb, offset, 8, prefix, "%08x %08x %08x %08x",
host_id, app_id, counter, entity_id);
guid_tree = proto_item_add_subtree(ti, ett_rtps_generic_guid);
proto_tree_add_item(guid_tree, hf_host_id, tvb, offset, 4, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(guid_tree, hf_app_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
appid_tree = proto_item_add_subtree(ti, ett_rtps_app_id);
proto_tree_add_item(appid_tree, hf_app_id_instance_id, tvb, offset+4, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(appid_tree, hf_app_id_app_kind, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(guid_tree, hf_counter, tvb, offset+8, 4, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(guid_tree, hf_entity, tvb, offset+12, 4, ENC_BIG_ENDIAN);
entity_tree = proto_item_add_subtree(ti, ett_rtps_entity);
proto_tree_add_item(entity_tree, hf_entity_key, tvb, offset+12, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(entity_tree, hf_entity_kind, tvb, offset+15, 1, ENC_BIG_ENDIAN);
}
guint64 rtps_util_add_seq_number(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
const char *label) {
guint64 hi = (guint64)NEXT_guint32(tvb, offset, little_endian);
guint64 lo = (guint64)NEXT_guint32(tvb, offset+4, little_endian);
guint64 all = (hi << 32) | lo;
proto_tree_add_int64_format(tree, hf_rtps_sm_seq_number, tvb, offset, 8,
all, "%s: %" G_GINT64_MODIFIER "u", label, all);
return all;
}
void rtps_util_add_ntp_time(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
int hf_time) {
proto_tree_add_item(tree, hf_time, tvb, offset, 8,
ENC_TIME_NTP|(little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN));
}
gint rtps_util_add_string(proto_tree *tree, tvbuff_t* tvb, gint offset,
int hf_item, gboolean little_endian) {
guint8 * retVal = NULL;
guint32 size = NEXT_guint32(tvb, offset, little_endian);
if (size > 0) {
retVal = tvb_get_string(wmem_packet_scope(), tvb, offset+4, size);
}
proto_tree_add_string(tree, hf_item, tvb, offset, size+4,
(size == 0) ? (guint8 *)"" : retVal);
return offset + 4 + ((size + 3) & 0xfffffffc);
}
void rtps_util_add_port(proto_tree *tree, packet_info *pinfo, tvbuff_t * tvb,
gint offset, gboolean little_endian, int hf_item) {
proto_item* ti;
guint32 port = NEXT_guint32(tvb, offset+4, little_endian);
ti = proto_tree_add_uint(tree, hf_item, tvb, offset, 4, port);
if (port == PORT_INVALID)
expert_add_info(pinfo, ti, &ei_rtps_port_invalid);
}
void rtps_util_add_durability_service_qos(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian) {
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_text(tree, tvb, offset, 28, "PID_DURABILITY_SERVICE");
subtree = proto_item_add_subtree(ti, ett_rtps_durability_service);
rtps_util_add_ntp_time(subtree, tvb, offset, little_endian, hf_rtps_durability_service_cleanup_delay);
proto_tree_add_item(subtree, hf_rtps_durability_service_history_kind, tvb, offset+8, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_rtps_durability_service_history_depth, tvb, offset+12, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_rtps_durability_service_max_samples, tvb, offset+16, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_rtps_durability_service_max_instances, tvb, offset+20, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_rtps_durability_service_max_samples_per_instances, tvb, offset+24, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
void rtps_util_add_liveliness_qos(proto_tree *tree, tvbuff_t * tvb, gint offset, gboolean little_endian) {
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_text(tree, tvb, offset, 12, "PID_LIVELINESS");
subtree = proto_item_add_subtree(ti, ett_rtps_liveliness);
proto_tree_add_item(subtree, hf_rtps_liveliness_kind, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
rtps_util_add_ntp_time(subtree, tvb, offset+4, little_endian, hf_rtps_liveliness_lease_duration);
}
gint rtps_util_add_seq_string(proto_tree *tree, tvbuff_t* tvb, gint offset,
gboolean little_endian, int param_length, int hf_numstring,
int hf_string, const char *label) {
guint32 i, num_strings, size;
guint8 * retVal;
proto_tree *string_tree;
proto_item *ti;
num_strings = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_int(tree, hf_numstring, tvb, offset, 4, num_strings);
offset += 4;
ti = proto_tree_add_text(tree, tvb, offset, param_length-8, "%s", label);
string_tree = proto_item_add_subtree(ti, ett_rtps_seq_string);
for (i = 0; i < num_strings; ++i) {
size = NEXT_guint32(tvb, offset, little_endian);
if (size > 0) {
retVal = tvb_get_string(wmem_packet_scope(), tvb, offset+4, size);
} else {
retVal = (guint8 *)"";
}
proto_tree_add_string_format(string_tree, hf_string, tvb, offset, size+4, retVal,
"%s[%d]: %s", label, i, retVal);
offset += (4 + ((size + 3) & 0xfffffffc));
}
return offset;
}
gint rtps_util_add_seq_ulong(proto_tree *tree, tvbuff_t * tvb, gint offset, int hf_item,
gboolean little_endian, int param_length _U_, const char *label) {
guint32 num_elem;
guint32 i;
proto_tree *string_tree;
proto_item *ti;
num_elem = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
ti = proto_tree_add_text(tree, tvb, offset, num_elem*4, "%s (%d elements)", label, num_elem);
string_tree = proto_item_add_subtree(ti, ett_rtps_seq_ulong);
for (i = 0; i < num_elem; ++i) {
proto_tree_add_item(string_tree, hf_item, tvb, offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static const char * rtps_util_typecode_id_to_string(guint32 typecode_id) {
switch(typecode_id) {
case RTI_CDR_TK_ENUM: return "enum";
case RTI_CDR_TK_UNION: return "union";
case RTI_CDR_TK_STRUCT: return "struct";
case RTI_CDR_TK_LONG: return "long";
case RTI_CDR_TK_SHORT: return "short";
case RTI_CDR_TK_USHORT: return "unsigned short";
case RTI_CDR_TK_ULONG: return "unsigned long";
case RTI_CDR_TK_FLOAT: return "float";
case RTI_CDR_TK_DOUBLE: return "double";
case RTI_CDR_TK_BOOLEAN:return "boolean";
case RTI_CDR_TK_CHAR: return "char";
case RTI_CDR_TK_OCTET: return "octet";
case RTI_CDR_TK_LONGLONG:return "longlong";
case RTI_CDR_TK_ULONGLONG: return "unsigned long long";
case RTI_CDR_TK_LONGDOUBLE: return "long double";
case RTI_CDR_TK_WCHAR: return "wchar";
case RTI_CDR_TK_WSTRING:return "wstring";
case RTI_CDR_TK_STRING: return "string";
case RTI_CDR_TK_SEQUENCE: return "sequence";
case RTI_CDR_TK_ARRAY: return "array";
case RTI_CDR_TK_ALIAS: return "alias";
case RTI_CDR_TK_VALUE: return "valuetype";
case RTI_CDR_TK_NULL:
default:
return "<unknown type>";
}
}
static gint rtps_util_add_typecode(proto_tree *tree, tvbuff_t * tvb, gint offset, gboolean little_endian,
int indent_level, int is_pointer, guint16 bitfield, int is_key, const gint offset_begin,
char* name,
int seq_max_len,
guint32* arr_dimension,
int ndds_40_hack) {
const gint original_offset = offset;
guint32 tk_id;
guint16 tk_size;
unsigned int i;
char* indent_string;
gint retVal;
char type_name[40];
indent_string = (char *)wmem_alloc(wmem_epan_scope(), (indent_level*2)+1);
memset(indent_string, ' ', indent_level*2);
indent_string[indent_level*2] = '\0';
LONG_ALIGN(offset);
tk_id = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
tk_size = NEXT_guint16(tvb, offset, little_endian);
offset += 2;
retVal = tk_size + 6;
tk_id &= 0x7fffffff;
if (indent_level == 0) {
if (tk_id == RTI_CDR_TK_OCTET) {
ndds_40_hack = 1;
}
}
if (ndds_40_hack) {
++tk_id;
}
g_strlcpy(type_name, rtps_util_typecode_id_to_string(tk_id), 40);
switch(tk_id) {
case RTI_CDR_TK_UNION: {
guint32 struct_name_len;
gint8 * struct_name;
const char * discriminator_name = "<unknown>";
char * discriminator_enum_name = NULL;
guint32 disc_id;
guint16 disc_size;
guint32 disc_offset_begin, num_members, member_name_len;
guint16 member_length;
guint8 *member_name = NULL;
guint8 member_is_pointer;
guint32 next_offset, field_offset_begin, member_label_count, discriminator_enum_name_length;
gint32 member_label;
guint j;
LONG_ALIGN(offset);
struct_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
struct_name = tvb_get_string(wmem_packet_scope(), tvb, offset, struct_name_len);
offset += struct_name_len;
LONG_ALIGN(offset);
offset += 4;
disc_id = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
disc_size = NEXT_guint16(tvb, offset, little_endian);
offset += 2;
disc_offset_begin = offset;
disc_id &= 0x7fffffff;
discriminator_name = rtps_util_typecode_id_to_string(disc_id);
if (disc_id == RTI_CDR_TK_ENUM) {
LONG_ALIGN(offset);
discriminator_enum_name_length = NEXT_guint32(tvb, offset, little_endian);
discriminator_enum_name = tvb_get_string(wmem_packet_scope(), tvb, offset+4, discriminator_enum_name_length);
}
offset = disc_offset_begin + disc_size;
#if 0
field_offset_begin = offset;
offset += rtps_util_add_typecode(
tree,
tvb,
offset,
little_endian,
indent_level+1,
0,
0,
0,
field_offset_begin,
member_name,
-1,
NULL,
ndds_40_hack);
#endif
proto_tree_add_text(tree, tvb, original_offset, retVal,
"%sunion %s (%s%s%s) {",
indent_string, struct_name, discriminator_name,
(discriminator_enum_name ? " " : ""),
(discriminator_enum_name ? discriminator_enum_name : ""));
if (seq_max_len != -1) {
g_snprintf(type_name, 40, "%s", struct_name);
break;
}
LONG_ALIGN(offset);
num_members = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
next_offset = offset;
for (i = 0; i < num_members; ++i) {
field_offset_begin = offset = next_offset;
SHORT_ALIGN(offset);
member_length = NEXT_guint16(tvb, offset, little_endian);
offset += 2;
next_offset = offset + member_length;
LONG_ALIGN(offset);
member_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
member_name = tvb_get_string(wmem_packet_scope(), tvb, offset, member_name_len);
offset += member_name_len;
member_is_pointer = tvb_get_guint8(tvb, offset);
offset++;
LONG_ALIGN(offset);
member_label_count = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (j = 0; j < member_label_count; ++j) {
LONG_ALIGN(offset);
member_label = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
proto_tree_add_text(tree, tvb, field_offset_begin, retVal,
"%s case %d:", indent_string, member_label);
}
offset += rtps_util_add_typecode(tree, tvb, offset, little_endian,
indent_level+2, member_is_pointer, 0, 0, field_offset_begin,
member_name, -1, NULL, ndds_40_hack);
}
g_strlcpy(type_name, "}", 40);
break;
}
case RTI_CDR_TK_ENUM:
case RTI_CDR_TK_STRUCT: {
gint8 * struct_name;
guint16 member_length, member_bitfield;
guint8 member_is_pointer, member_is_key;
guint32 struct_name_len, num_members, member_name_len,
next_offset, field_offset_begin, ordinal_number;
guint8 *member_name = NULL;
const char * typecode_name;
LONG_ALIGN(offset);
struct_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
struct_name = tvb_get_string(wmem_packet_scope(), tvb, offset, struct_name_len);
offset += struct_name_len;
if (tk_id == RTI_CDR_TK_ENUM) {
typecode_name = "enum";
} else {
typecode_name = "struct";
}
if (seq_max_len != -1) {
g_snprintf(type_name, 40, "%s", struct_name);
break;
}
proto_tree_add_text(tree, tvb, original_offset, retVal, "%s%s %s {",
indent_string, typecode_name, struct_name);
LONG_ALIGN(offset);
num_members = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
next_offset = offset;
for (i = 0; i < num_members; ++i) {
field_offset_begin = offset = next_offset;
SHORT_ALIGN(offset);
member_length = NEXT_guint16(tvb, offset, little_endian);
offset += 2;
next_offset = offset + member_length;
LONG_ALIGN(offset);
member_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
member_name = tvb_get_string(wmem_packet_scope(), tvb, offset, member_name_len);
offset += member_name_len;
if (tk_id == RTI_CDR_TK_ENUM) {
LONG_ALIGN(offset);
ordinal_number = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
proto_tree_add_text(tree, tvb, field_offset_begin, (offset-field_offset_begin),
"%s %s = %d;", indent_string, member_name, ordinal_number);
} else {
member_is_pointer = tvb_get_guint8(tvb, offset);
offset++;
SHORT_ALIGN(offset);
member_bitfield = NEXT_guint16(tvb, offset, little_endian);
offset += 2;
member_is_key = tvb_get_guint8(tvb, offset);
offset++;
offset += rtps_util_add_typecode(tree, tvb, offset, little_endian,
indent_level+1, member_is_pointer, member_bitfield, member_is_key,
field_offset_begin, member_name, -1, NULL, ndds_40_hack);
}
}
g_strlcpy(type_name, "}", 40);
break;
}
case RTI_CDR_TK_WSTRING:
case RTI_CDR_TK_STRING: {
guint32 string_length;
LONG_ALIGN(offset);
string_length = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
g_snprintf(type_name, 40, "%s<%d>",
(tk_id == RTI_CDR_TK_STRING) ? "string" : "wstring",
string_length);
break;
}
case RTI_CDR_TK_SEQUENCE: {
guint32 seq_max_len2;
LONG_ALIGN(offset);
seq_max_len2 = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
rtps_util_add_typecode(tree, tvb, offset, little_endian, indent_level,
is_pointer, bitfield, is_key, offset_begin, name,
seq_max_len2, NULL, ndds_40_hack);
return retVal;
}
case RTI_CDR_TK_ARRAY: {
guint32 size[MAX_ARRAY_DIMENSION];
guint32 dim_max;
LONG_ALIGN(offset);
dim_max = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
if (dim_max > MAX_ARRAY_DIMENSION) {
dim_max = MAX_ARRAY_DIMENSION;
}
for (i = 0; i < MAX_ARRAY_DIMENSION; ++i) size[i] = 0;
for (i = 0; i < dim_max; ++i) {
size[i] = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
}
rtps_util_add_typecode(tree, tvb, offset, little_endian,
indent_level, is_pointer, bitfield, is_key, offset_begin,
name, -1, size, ndds_40_hack);
return retVal;
}
case RTI_CDR_TK_ALIAS: {
guint32 alias_name_length;
guint8 *alias_name;
LONG_ALIGN(offset);
alias_name_length = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
alias_name = tvb_get_string(wmem_packet_scope(), tvb, offset, alias_name_length);
offset += alias_name_length;
g_strlcpy(type_name, alias_name, 40);
break;
}
case RTI_CDR_TK_VALUE: {
guint32 value_name_len;
gint8 * value_name;
LONG_ALIGN(offset);
value_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
value_name = tvb_get_string(wmem_packet_scope(), tvb, offset, value_name_len);
offset += value_name_len;
g_snprintf(type_name, 40, "valuetype %s", value_name);
break;
}
}
if (seq_max_len != -1) {
proto_tree_add_text(tree, tvb, offset_begin, (offset-offset_begin),
"%ssequence<%s, %d> %s%s;%s",
indent_string, type_name, seq_max_len,
is_pointer ? "*" : "",
name ? name : "",
is_key ? KEY_COMMENT : "");
return retVal;
}
if (arr_dimension != NULL) {
wmem_strbuf_t *dim_str = wmem_strbuf_new_label(wmem_packet_scope());
for (i = 0; i < MAX_ARRAY_DIMENSION; ++i) {
if (arr_dimension[i] != 0) {
wmem_strbuf_append_printf(dim_str, "[%d]", arr_dimension[i]);
} else {
break;
}
}
proto_tree_add_text(tree, tvb, offset_begin, (offset-offset_begin),
"%s%s %s%s;%s",
indent_string, type_name, name ? name : "",
wmem_strbuf_get_str(dim_str), is_key ? KEY_COMMENT : "");
return retVal;
}
if (bitfield != 0xffff && name != NULL && is_pointer == 0) {
proto_tree_add_text(tree, tvb, offset_begin, (offset-offset_begin),
"%s%s %s:%d;%s",
indent_string, type_name, name ? name : "",
bitfield, is_key ? KEY_COMMENT : "");
return retVal;
}
proto_tree_add_text(tree, tvb, offset_begin, (offset-offset_begin),
"%s%s%s%s%s;%s", indent_string, type_name,
name ? " " : "",
is_pointer ? "*" : "",
name ? name : "",
is_key ? KEY_COMMENT : "");
return retVal;
}
void rtps_util_add_seq_octets(proto_tree *tree, packet_info *pinfo, tvbuff_t* tvb,
gint offset, gboolean little_endian, int param_length, int hf_id) {
guint32 seq_length;
proto_item *ti;
seq_length = NEXT_guint32(tvb, offset, little_endian);
ti = proto_tree_add_text(tree, tvb, offset, 4, "sequenceSize: %d octects", seq_length);
offset += 4;
if (param_length < 4 + (int)seq_length) {
expert_add_info_format(pinfo, ti, &ei_rtps_parameter_value_invalid, "ERROR: Parameter value too small");
return;
}
proto_tree_add_item(tree, hf_id, tvb, offset+4, seq_length,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
static int rtps_util_add_bitmap(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
const char *label _U_) {
gint32 num_bits;
guint32 data;
wmem_strbuf_t *temp_buff = wmem_strbuf_new_label(wmem_packet_scope());
int i, j, idx;
gchar *last_one;
proto_item * ti;
proto_tree * bitmap_tree;
const gint original_offset = offset;
guint32 datamask;
ti = proto_tree_add_text(tree, tvb, original_offset, offset-original_offset, "%s", label);
bitmap_tree = proto_item_add_subtree(ti, ett_rtps_bitmap);
rtps_util_add_seq_number(bitmap_tree, tvb, offset, little_endian, "bitmapBase");
offset += 8;
num_bits = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_uint(bitmap_tree, hf_rtps_bitmap_num_bits, tvb, offset, 4, num_bits);
offset += 4;
idx = 0;
for (i = 0; i < num_bits; i += 32) {
data = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (j = 0; j < 32; ++j) {
datamask = (1 << (31-j));
wmem_strbuf_append_c(temp_buff, ((data & datamask) == datamask) ? '1':'0');
++idx;
if ((idx >= num_bits) || (wmem_strbuf_get_len(temp_buff) >= (ITEM_LABEL_LENGTH - 1))) {
break;
}
}
}
last_one = strrchr(wmem_strbuf_get_str(temp_buff), '1');
if (last_one) {
wmem_strbuf_truncate(temp_buff, (gsize) (last_one - wmem_strbuf_get_str(temp_buff)));
}
if (wmem_strbuf_get_len(temp_buff) > 0) {
proto_tree_add_text(bitmap_tree,
tvb,
original_offset + 12,
offset - original_offset - 12,
"bitmap: %s",
wmem_strbuf_get_str(temp_buff));
}
proto_item_set_len(ti, offset-original_offset);
return offset;
}
static int rtps_util_add_fragment_number_set(proto_tree *tree, packet_info *pinfo, tvbuff_t * tvb,
gint offset, gboolean little_endian, const char *label, gint section_size) {
guint64 base;
gint32 num_bits;
guint32 data;
wmem_strbuf_t *temp_buff = wmem_strbuf_new_label(wmem_packet_scope());
gchar *last_one;
int i, j, idx;
proto_item * ti;
proto_tree * bitmap_tree;
const gint original_offset = offset;
guint32 datamask;
gint expected_size;
gint base_size;
ti = proto_tree_add_text(tree, tvb, original_offset, offset-original_offset, "%s", label);
num_bits = NEXT_guint32(tvb, offset+4, little_endian);
expected_size = (((num_bits / 8) + 3) / 4) * 4 + 8;
if (expected_size == section_size) {
base = (guint64)NEXT_guint32(tvb, offset, little_endian);
base_size = 4;
offset += 8;
} else {
num_bits = NEXT_guint32(tvb, offset+8, little_endian);
expected_size = (((num_bits / 8) + 3) / 4) * 4 + 12;
if (expected_size == section_size) {
guint64 hi = (guint64)NEXT_guint32(tvb, offset, little_endian);
guint64 lo = (guint64)NEXT_guint32(tvb, offset+4, little_endian);
base = (hi << 32) | lo;
base_size = 8;
offset += 12;
} else {
expert_add_info_format(pinfo, ti, &ei_rtps_parameter_value_invalid, "Illegal size for fragment number set");
return -1;
}
}
idx = 0;
for (i = 0; i < num_bits; i += 32) {
data = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (j = 0; j < 32; ++j) {
datamask = (1 << (31-j));
wmem_strbuf_append_c(temp_buff, ((data & datamask) == datamask) ? '1':'0');
++idx;
if ((idx >= num_bits) || (wmem_strbuf_get_len(temp_buff) >= (ITEM_LABEL_LENGTH - 1))) {
break;
}
}
}
last_one = strrchr(wmem_strbuf_get_str(temp_buff), '1');
if (last_one) {
wmem_strbuf_truncate(temp_buff, (gsize) (last_one - wmem_strbuf_get_str(temp_buff)));
}
bitmap_tree = proto_item_add_subtree(ti, ett_rtps_bitmap);
if (base_size == 8) {
proto_tree_add_uint64(bitmap_tree, hf_rtps_fragment_number_base64, tvb, original_offset, 8,
base);
} else {
proto_tree_add_item(bitmap_tree, hf_rtps_fragment_number_base, tvb, original_offset, base_size,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
proto_tree_add_uint(bitmap_tree, hf_rtps_fragment_number_num_bits, tvb, original_offset + base_size, 4, num_bits);
if (wmem_strbuf_get_len(temp_buff) > 0) {
proto_tree_add_text(bitmap_tree, tvb,
original_offset + base_size + 4,
offset - original_offset - base_size - 4,
"bitmap: %s", wmem_strbuf_get_str(temp_buff));
}
proto_item_set_len(ti, offset-original_offset);
return offset;
}
static void rtps_util_decode_flags(proto_tree * tree, tvbuff_t *tvb, gint offset,
guint8 flags, const struct Flag_definition * flag_def) {
proto_item * ti;
proto_tree * flags_tree;
int i, j;
char flags_str[20];
ti = proto_tree_add_uint(tree, hf_rtps_sm_flags, tvb, offset, 1, flags);
proto_item_append_text(ti, " ( ");
for (i = 0; i < 8; ++i) {
proto_item_append_text(ti, "%c ", ((flags & (1<<(7-i))) ? flag_def[i].letter : RESERVEDFLAG_CHAR));
}
proto_item_append_text(ti, ")");
flags_tree = proto_item_add_subtree(ti, ett_rtps_flags);
for (i = 0; i < 8; ++i) {
int is_set = (flags & (1 << (7-i)));
for (j = 0; j < 8; ++j) {
flags_str[j] = (i == j) ? (is_set ? '1' : '0') : '.';
}
flags_str[8] = '\0';
proto_tree_add_text(flags_tree, tvb, offset, 1, "%s = %s: %s",
flags_str, flag_def[i].description,
is_set ? "Set" : "Not set");
}
}
static void rtps_util_decode_flags_16bit(proto_tree * tree, tvbuff_t *tvb, gint offset,
guint16 flags, const struct Flag_definition * flag_def) {
proto_item * ti;
proto_tree * flags_tree;
int i, j;
char flags_str[20];
ti = proto_tree_add_uint(tree, hf_rtps_sm_flags, tvb, offset, 2, flags);
proto_item_append_text(ti, " ( ");
for (i = 0; i < 16; ++i) {
proto_item_append_text(ti, "%c ", ((flags & (1<<(15-i))) ? flag_def[i].letter : RESERVEDFLAG_CHAR));
}
proto_item_append_text(ti, ")");
flags_tree = proto_item_add_subtree(ti, ett_rtps_flags);
for (i = 0; i < 16; ++i) {
int is_set = (flags & (1 << (15-i)));
for (j = 0; j < 16; ++j) {
flags_str[j] = (i == j) ? (is_set ? '1' : '0') : '.';
}
flags_str[16] = '\0';
proto_tree_add_text(flags_tree, tvb, offset, 2, "%s = %s: %s",
flags_str,
flag_def[i].description,
is_set ? "Set" : "Not set");
}
}
static gboolean dissect_parameter_sequence_v1(proto_tree *rtps_parameter_tree, packet_info *pinfo, tvbuff_t *tvb,
proto_item* parameter_item, proto_item* param_len_item, gint offset,
gboolean little_endian, int size, int param_length,
guint16 parameter, guint16 version) {
proto_item *ti;
proto_tree *subtree;
switch(parameter) {
case PID_PARTICIPANT_LEASE_DURATION:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree, tvb, offset, little_endian,
hf_rtps_participant_lease_duration);
break;
case PID_TIME_BASED_FILTER:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree, tvb, offset, little_endian,
hf_rtps_time_based_filter_minimum_separation);
break;
case PID_TOPIC_NAME:
rtps_util_add_string(rtps_parameter_tree, tvb, offset, hf_rtps_param_topic_name, little_endian);
break;
case PID_OWNERSHIP_STRENGTH:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_strength, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_TYPE_NAME:
rtps_util_add_string(rtps_parameter_tree, tvb, offset, hf_rtps_param_type_name, little_endian);
break;
case PID_METATRAFFIC_MULTICAST_PORT:
case PID_METATRAFFIC_UNICAST_PORT:
case PID_DEFAULT_UNICAST_PORT:
ENSURE_LENGTH(4);
rtps_util_add_port(rtps_parameter_tree, pinfo, tvb, offset, little_endian, hf_rtps_param_port);
break;
case PID_EXPECTS_INLINE_QOS:
ENSURE_LENGTH(1);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_expects_inline_qos, tvb, offset, 1, ENC_NA );
break;
case PID_METATRAFFIC_MULTICAST_IPADDRESS:
case PID_DEFAULT_UNICAST_IPADDRESS:
case PID_MULTICAST_IPADDRESS:
case PID_METATRAFFIC_UNICAST_IPADDRESS:
rtps_util_add_ipv4_address_t(rtps_parameter_tree, pinfo, tvb, offset,
little_endian, hf_param_ip_address);
break;
case PID_PROTOCOL_VERSION:
ENSURE_LENGTH(2);
rtps_util_add_protocol_version(rtps_parameter_tree, tvb, offset);
break;
case PID_VENDOR_ID:
ENSURE_LENGTH(2);
rtps_util_add_vendor_id(NULL, tvb, offset);
break;
case PID_RELIABILITY_OFFERED:
case PID_RELIABILITY:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_reliability_kind, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (size == 12) {
rtps_util_add_ntp_time(rtps_parameter_tree, tvb, offset + 4,
little_endian, hf_rtps_reliability_max_blocking_time);
}
break;
case PID_LIVELINESS_OFFERED:
case PID_LIVELINESS:
ENSURE_LENGTH(12);
rtps_util_add_liveliness_qos(rtps_parameter_tree, tvb, offset, little_endian);
break;
case PID_DURABILITY:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_durability, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_DURABILITY_SERVICE:
ENSURE_LENGTH(28);
rtps_util_add_durability_service_qos(rtps_parameter_tree, tvb, offset, little_endian);
break;
case PID_OWNERSHIP_OFFERED:
case PID_OWNERSHIP:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_ownership, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_PRESENTATION_OFFERED:
case PID_PRESENTATION:
ENSURE_LENGTH(6);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_presentation_access_scope, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_presentation_coherent_access, tvb, offset+4, 1, ENC_NA );
proto_tree_add_item(rtps_parameter_tree, hf_rtps_presentation_ordered_access, tvb, offset+5, 1, ENC_NA );
break;
case PID_DEADLINE_OFFERED:
case PID_DEADLINE:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree, tvb, offset, little_endian, hf_rtps_deadline_period);
break;
case PID_DESTINATION_ORDER_OFFERED:
case PID_DESTINATION_ORDER:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_destination_order, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_LATENCY_BUDGET_OFFERED:
case PID_LATENCY_BUDGET:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree, tvb, offset,
little_endian, hf_rtps_latency_budget_duration);
break;
case PID_PARTITION_OFFERED:
case PID_PARTITION:
ENSURE_LENGTH(4);
rtps_util_add_seq_string(rtps_parameter_tree, tvb, offset, little_endian,
param_length, hf_rtps_param_partition_num, hf_rtps_param_partition, "name");
break;
case PID_LIFESPAN:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree, tvb, offset, little_endian,
hf_rtps_lifespan_duration);
break;
case PID_USER_DATA:
ENSURE_LENGTH(4);
rtps_util_add_seq_octets(rtps_parameter_tree, pinfo, tvb, offset,
little_endian, param_length, hf_rtps_param_user_data);
break;
case PID_GROUP_DATA:
ENSURE_LENGTH(4);
rtps_util_add_seq_octets(rtps_parameter_tree, pinfo, tvb, offset,
little_endian, param_length, hf_rtps_param_group_data);
break;
case PID_TOPIC_DATA:
ENSURE_LENGTH(4);
rtps_util_add_seq_octets(rtps_parameter_tree, pinfo, tvb, offset,
little_endian, param_length, hf_rtps_param_topic_data);
break;
case PID_UNICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree, pinfo, tvb,
offset, little_endian, "locator");
break;
case PID_MULTICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree, pinfo, tvb,
offset, little_endian, "locator");
break;
case PID_DEFAULT_UNICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree, pinfo, tvb, offset,
little_endian, "locator");
break;
case PID_METATRAFFIC_UNICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree, pinfo, tvb, offset,
little_endian, "locator");
break;
case PID_METATRAFFIC_MULTICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree, pinfo, tvb,
offset, little_endian, "locator");
break;
case PID_PARTICIPANT_BUILTIN_ENDPOINTS:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_participant_builtin_endpoints, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_PARTICIPANT_MANUAL_LIVELINESS_COUNT:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_participant_manual_liveliness_count, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_HISTORY:
ENSURE_LENGTH(8);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_history_kind, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_history_depth, tvb, offset+4, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_RESOURCE_LIMIT:
ENSURE_LENGTH(12);
ti = proto_tree_add_text(rtps_parameter_tree, tvb, offset, 12, "Resource Limit");
subtree = proto_item_add_subtree(ti, ett_rtps_resource_limit);
proto_tree_add_item(subtree, hf_rtps_resource_limit_max_samples, tvb, offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_rtps_resource_limit_max_instances, tvb, offset+4, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_rtps_resource_limit_max_samples_per_instances, tvb, offset+8, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_CONTENT_FILTER_PROPERTY: {
guint32 temp_offset = offset;
ENSURE_LENGTH(20);
temp_offset = rtps_util_add_string(rtps_parameter_tree, tvb, temp_offset,
hf_rtps_param_content_filter_name, little_endian);
temp_offset = rtps_util_add_string(rtps_parameter_tree, tvb, temp_offset,
hf_rtps_param_related_topic_name, little_endian);
temp_offset = rtps_util_add_string(rtps_parameter_tree, tvb, temp_offset,
hf_rtps_param_filter_name, little_endian);
temp_offset = rtps_util_add_string(rtps_parameter_tree, tvb, temp_offset,
hf_rtps_param_filter_expression, little_endian);
rtps_util_add_seq_string(rtps_parameter_tree, tvb, temp_offset,
little_endian, param_length, hf_rtps_param_filter_parameters_num,
hf_rtps_param_filter_parameters, "filterParameters");
break;
}
case PID_PROPERTY_LIST:
case PID_PROPERTY_LIST_OLD:
ENSURE_LENGTH(4);
{
guint32 prev_offset, temp_offset, prop_size;
guint8 *propName, *propValue;
guint32 seq_size = NEXT_guint32(tvb, offset, little_endian);
proto_item_append_text( parameter_item, " (%d properties)", seq_size );
if (seq_size > 0) {
proto_tree_add_text(rtps_parameter_tree, tvb, offset, 0,
" Property Name | Property Value");
proto_tree_add_text(rtps_parameter_tree, tvb, offset, 0,
"------------------------------|------------------------------");
temp_offset = offset+4;
while(seq_size-- > 0) {
prev_offset = temp_offset;
prop_size = NEXT_guint32(tvb, temp_offset, little_endian);
if (prop_size > 0) {
propName = tvb_get_string(wmem_packet_scope(), tvb, temp_offset+4, prop_size);
} else {
propName = (guint8 *)"";
}
temp_offset += (4 + ((prop_size + 3) & 0xfffffffc));
prop_size = NEXT_guint32(tvb, temp_offset, little_endian);
if (prop_size > 0) {
propValue = tvb_get_string(wmem_packet_scope(), tvb, temp_offset+4, prop_size);
} else {
propValue = (guint8 *)"";
}
temp_offset += (4 + ((prop_size + 3) & 0xfffffffc));
proto_tree_add_text(rtps_parameter_tree, tvb, prev_offset,
temp_offset - prev_offset, "%-29s | %-29s",
propName,
propValue);
}
}
}
break;
case PID_FILTER_SIGNATURE: {
guint32 temp_offset = offset;
guint32 prev_offset;
guint32 fs_elem;
guint32 fs[4];
ENSURE_LENGTH(8);
temp_offset = rtps_util_add_seq_ulong(rtps_parameter_tree, tvb, offset,
hf_rtps_filter_bitmap, little_endian, param_length, "filterBitmap");
fs_elem = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
while (fs_elem-- > 0) {
prev_offset = temp_offset;
fs[0] = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
fs[1] = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
fs[2] = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
fs[3] = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
proto_tree_add_text(rtps_parameter_tree, tvb, prev_offset,
temp_offset - prev_offset,
"filterSignature: %08x %08x %08x %08x",
fs[0], fs[1], fs[2], fs[3]);
}
break;
}
case PID_COHERENT_SET:
ENSURE_LENGTH(8);
rtps_util_add_seq_number(rtps_parameter_tree, tvb, offset,
little_endian, "sequenceNumber");
break;
case PID_TYPECODE:
rtps_util_add_typecode(rtps_parameter_tree, tvb, offset, little_endian,
0,
0,
-1,
0,
offset,
NULL,
-1,
NULL,
0);
break;
case PID_PARTICIPANT_GUID:
if (version < 0x0200) {
ENSURE_LENGTH(12);
rtps_util_add_generic_guid_v1(rtps_parameter_tree, tvb, offset,
hf_rtps_participant_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_app_kind,
hf_rtps_param_entity, hf_rtps_param_entity_key, hf_rtps_param_hf_entity_kind);
} else {
ENSURE_LENGTH(16);
rtps_util_add_generic_guid_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_participant_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_app_kind, hf_rtps_param_counter,
hf_rtps_param_entity, hf_rtps_param_entity_key, hf_rtps_param_hf_entity_kind);
}
break;
case PID_PARTICIPANT_ENTITY_ID:
ENSURE_LENGTH(4);
rtps_util_add_generic_entity_id(rtps_parameter_tree, tvb, offset, "Participant entity ID",
hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind, ett_rtps_entity);
break;
case PID_GROUP_GUID:
if (version < 0x0200) {
ENSURE_LENGTH(12);
rtps_util_add_generic_guid_v1(rtps_parameter_tree, tvb, offset,
hf_rtps_group_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_app_kind,
hf_rtps_param_entity, hf_rtps_param_entity_key, hf_rtps_param_hf_entity_kind);
} else {
ENSURE_LENGTH(16);
rtps_util_add_generic_guid_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_group_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_app_kind, hf_rtps_param_counter,
hf_rtps_param_entity, hf_rtps_param_entity_key, hf_rtps_param_hf_entity_kind);
}
break;
case PID_GROUP_ENTITY_ID:
ENSURE_LENGTH(4);
rtps_util_add_generic_entity_id(rtps_parameter_tree, tvb, offset, "Group entity ID",
hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind, ett_rtps_entity);
break;
case PID_PERSISTENCE:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree, tvb, offset, little_endian,
hf_rtps_persistence);
break;
case PID_TYPE_CHECKSUM:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_type_checksum, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_EXPECTS_ACK:
ENSURE_LENGTH(1);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_expects_ack, tvb, offset, 1, ENC_NA );
break;
case PID_MANAGER_KEY: {
int i = 0;
guint32 manager_key;
ti = proto_tree_add_text(rtps_parameter_tree, tvb, offset, param_length, "Manager Keys");
subtree = proto_item_add_subtree(ti, ett_rtps_manager_key);
while (param_length >= 4) {
manager_key = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_uint_format(subtree, hf_rtps_manager_key, tvb, offset, 4,
manager_key, "Key[%d]: 0x%X", i, manager_key);
++i;
offset +=4;
param_length -= 4;
}
break;
}
case PID_RECV_QUEUE_SIZE:
case PID_SEND_QUEUE_SIZE:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_queue_size, tvb, offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_VARGAPPS_SEQUENCE_NUMBER_LAST:
ENSURE_LENGTH(4);
rtps_util_add_seq_number(rtps_parameter_tree, tvb, offset, little_endian, "sequenceNumberLast");
break;
case PID_SENTINEL:
break;
case PID_IS_RELIABLE:
case PID_TYPE2_NAME:
case PID_TYPE2_CHECKSUM:
case PID_RELIABILITY_ENABLED:
expert_add_info(pinfo, parameter_item, &ei_rtps_parameter_not_decoded);
case PID_PAD:
if (param_length > 0) {
proto_tree_add_text(rtps_parameter_tree, tvb, offset, param_length, "parameterData");
}
break;
default:
return FALSE;
}
return TRUE;
}
static gboolean dissect_parameter_sequence_v2(proto_tree *rtps_parameter_tree, packet_info *pinfo, tvbuff_t *tvb,
proto_item* parameter_item, proto_item* param_len_item, gint offset,
gboolean little_endian, int param_length,
guint16 parameter, guint32 *pStatusInfo, guint16 vendor_id) {
proto_item *ti;
switch(parameter) {
case PID_STATUS_INFO:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_status_info, tvb, offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (pStatusInfo != NULL) {
*pStatusInfo = NEXT_guint32(tvb, offset, little_endian);
}
break;
case PID_DIRECTED_WRITE: {
ENSURE_LENGTH(16);
rtps_util_add_guid_prefix_v2(rtps_parameter_tree, tvb, offset, hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id, hf_rtps_sm_app_id, hf_rtps_sm_counter, "guidPrefix");
rtps_util_add_entity_id(rtps_parameter_tree, tvb, offset+12, hf_rtps_sm_entity_id,
hf_rtps_sm_entity_id_key, hf_rtps_sm_entity_id_kind, ett_rtps_entity,
"guidSuffix", NULL);
break;
}
case PID_KEY_HASH: {
guint8 guidPart;
int i;
ti = proto_tree_add_text(rtps_parameter_tree, tvb, offset, param_length, "guid: ");
for (i = 0; i < param_length; ++i) {
guidPart = tvb_get_guint8(tvb, offset+i);
proto_item_append_text(ti, "%02x", guidPart);
if (( ((i+1) % 4) == 0 ) && (i != param_length-1) )
proto_item_append_text(ti, ":");
}
break;
}
case PID_TRANSPORT_PRIORITY:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_transport_priority, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_CONTENT_FILTER_INFO: {
guint32 temp_offset = offset;
guint32 prev_offset;
guint32 fs_elem;
guint32 fs[4];
ENSURE_LENGTH(8);
temp_offset = rtps_util_add_seq_ulong(rtps_parameter_tree, tvb, offset,
hf_rtps_filter_bitmap, little_endian, param_length, "filterBitmap");
fs_elem = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
while (fs_elem-- > 0) {
prev_offset = temp_offset;
fs[0] = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
fs[1] = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
fs[2] = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
fs[3] = NEXT_guint32(tvb, temp_offset, little_endian);
temp_offset += 4;
proto_tree_add_text(rtps_parameter_tree,
tvb,
prev_offset,
temp_offset - prev_offset,
"filterSignature: %08x %08x %08x %08x",
fs[0], fs[1], fs[2], fs[3]);
}
break;
}
case PID_BUILTIN_ENDPOINT_SET:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_builtin_endpoint_set, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_TYPE_MAX_SIZE_SERIALIZED:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_type_max_size_serialized, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_ORIGINAL_WRITER_INFO:
ENSURE_LENGTH(16);
rtps_util_add_guid_prefix_v2(rtps_parameter_tree, tvb, offset, hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id, hf_rtps_sm_app_id, hf_rtps_sm_counter, "virtualGUIDPrefix");
rtps_util_add_entity_id(rtps_parameter_tree, tvb, offset+12, hf_rtps_sm_entity_id,
hf_rtps_sm_entity_id_key, hf_rtps_sm_entity_id_kind, ett_rtps_entity,
"virtualGUIDSuffix", NULL);
rtps_util_add_seq_number(rtps_parameter_tree, tvb, offset+16,
little_endian, "virtualSeqNumber");
break;
case PID_ENTITY_NAME:
rtps_util_add_string(rtps_parameter_tree, tvb, offset, hf_rtps_param_entity_name, little_endian);
break;
case PID_ENDPOINT_GUID:
ENSURE_LENGTH(16);
rtps_util_add_generic_guid_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_endpoint_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_app_kind, hf_rtps_param_counter,
hf_rtps_param_entity, hf_rtps_param_entity_key, hf_rtps_param_hf_entity_kind);
break;
default:
if (vendor_id == RTPS_VENDOR_RTI_DDS) {
switch(parameter) {
case PID_PRODUCT_VERSION: {
guint8 major, minor, release, revision;
ENSURE_LENGTH(4);
major = tvb_get_guint8(tvb, offset);
minor = tvb_get_guint8(tvb, offset+1);
release = tvb_get_guint8(tvb, offset+2);
revision = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(rtps_parameter_tree, tvb, offset, param_length,
"productVersion: %d.%d%c rev%d",
major, minor, release, revision);
break;
}
case PID_PLUGIN_PROMISCUITY_KIND:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_plugin_promiscuity_kind, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_ENTITY_VIRTUAL_GUID:
ENSURE_LENGTH(16);
rtps_util_add_guid_prefix_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_sm_guid_prefix, hf_rtps_sm_host_id, hf_rtps_sm_app_id,
hf_rtps_sm_counter, "virtualGUIDPrefix");
rtps_util_add_entity_id(rtps_parameter_tree, tvb, offset+12,
hf_rtps_sm_entity_id, hf_rtps_sm_entity_id_key, hf_rtps_sm_entity_id_kind,
ett_rtps_entity, "virtualGUIDSuffix", NULL);
break;
case PID_SERVICE_KIND:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_service_kind, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_TYPECODE_RTPS2:
rtps_util_add_typecode(rtps_parameter_tree,
tvb,
offset,
little_endian,
0,
0,
-1,
0,
offset,
NULL,
0,
NULL,
0);
break;
case PID_DISABLE_POSITIVE_ACKS:
ENSURE_LENGTH(1);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_disable_positive_ack, tvb, offset, 1, ENC_NA );
break;
case PID_LOCATOR_FILTER_LIST: {
guint32 number_of_channels, ch;
proto_tree *channel_tree;
proto_item *ti_channel;
char temp_buff[20];
gint old_offset;
guint32 off = offset;
ENSURE_LENGTH(4);
number_of_channels = NEXT_guint32(tvb, off, little_endian);
proto_item_append_text( parameter_item, " (%d channels)", number_of_channels );
proto_tree_add_int(rtps_parameter_tree, hf_rtps_locator_filter_list_num_channels, tvb, off, 4, number_of_channels );
off += 4;
if (number_of_channels == 0) {
break;
}
off = rtps_util_add_string(rtps_parameter_tree, tvb, off, hf_rtps_locator_filter_list_filter_name, little_endian);
for (ch = 0; ch < number_of_channels; ++ch) {
g_snprintf(temp_buff, 20, "Channel[%u]", ch);
old_offset = off;
ti_channel = proto_tree_add_text(rtps_parameter_tree, tvb, off, 0, "Channel[%u]", ch);
channel_tree = proto_item_add_subtree(ti_channel, ett_rtps_locator_filter_channel);
off = rtps_util_add_locator_list(channel_tree, pinfo, tvb, off, temp_buff, little_endian);
off = rtps_util_add_string(rtps_parameter_tree, tvb, off, hf_rtps_locator_filter_list_filter_exp, little_endian);
proto_item_set_len(ti_channel, (off - old_offset));
}
break;
}
}
}
else if (vendor_id == RTPS_VENDOR_TOC) {
switch(parameter) {
case PID_TYPECODE_RTPS2:
rtps_util_add_typecode(rtps_parameter_tree,
tvb,
offset,
little_endian,
0,
0,
-1,
0,
offset,
NULL,
0,
NULL,
0);
break;
default:
break;
}
} else {
return FALSE;
}
break;
}
return TRUE;
}
static gint dissect_parameter_sequence(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
gint offset, gboolean little_endian, int size, const char * label,
guint16 version, guint32 *pStatusInfo, guint16 vendor_id) {
proto_item *ti, *param_item, *param_len_item = NULL;
proto_tree *rtps_parameter_sequence_tree, *rtps_parameter_tree;
guint16 parameter, param_length;
gint original_offset = offset;
ti = proto_tree_add_text(tree, tvb, offset, -1, "%s:", label);
rtps_parameter_sequence_tree = proto_item_add_subtree(ti, ett_rtps_parameter_sequence);
for (;;) {
size -= offset - original_offset;
if (size < 4) {
expert_add_info_format(pinfo, (param_len_item == NULL) ? ti : param_len_item, &ei_rtps_parameter_value_invalid, "ERROR: not enough bytes to read the next parameter");
return 0;
}
original_offset = offset;
parameter = NEXT_guint16(tvb, offset, little_endian);
if (version < 0x0200) {
param_item = proto_tree_add_text(rtps_parameter_sequence_tree, tvb, offset, -1,
"%s", val_to_str(parameter, parameter_id_vals, "Unknown (0x%04x)"));
rtps_parameter_tree = proto_item_add_subtree(param_item, ett_rtps_parameter);
proto_tree_add_uint(rtps_parameter_tree, hf_rtps_parameter_id, tvb, offset, 2, parameter);
} else {
param_item = proto_tree_add_text(rtps_parameter_sequence_tree, tvb, offset, -1,
"%s", val_to_str(parameter, parameter_id_v2_vals, "Unknown (0x%04x)"));
rtps_parameter_tree = proto_item_add_subtree(param_item, ett_rtps_parameter);
proto_tree_add_uint(rtps_parameter_tree, hf_rtps_parameter_id_v2, tvb, offset, 2, parameter);
}
offset += 2;
if (parameter == PID_SENTINEL) {
return offset +2;
}
param_length = NEXT_guint16(tvb, offset, little_endian);
param_len_item = proto_tree_add_item(rtps_parameter_tree, hf_rtps_parameter_length,
tvb, offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
if ((size-4 < param_length) &&
(parameter != PID_SENTINEL)) {
expert_add_info_format(pinfo, param_len_item, &ei_rtps_parameter_value_invalid, "Not enough bytes to read the parameter value");
return 0;
}
proto_item_set_len(param_item, param_length+4);
if (!dissect_parameter_sequence_v1(rtps_parameter_tree, pinfo, tvb, param_item, param_len_item,
offset, little_endian, size, param_length, parameter, version)) {
if ((version < 0x0200) ||
!dissect_parameter_sequence_v2(rtps_parameter_tree, pinfo, tvb, param_item, param_len_item,
offset, little_endian, param_length, parameter,
pStatusInfo, vendor_id)) {
if (param_length > 0) {
proto_tree_add_text(rtps_parameter_tree, tvb, offset, param_length,
"parameterData");
}
}
}
offset += param_length;
}
return offset;
}
gboolean rtps_is_ping(tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
gboolean is_ping = FALSE;
if (!tvb_strneql(tvb, offset, "NDDSPING", 8))
is_ping = TRUE;
if (is_ping)
col_add_str(pinfo->cinfo, COL_INFO, "PING");
return is_ping;
}
static void dissect_serialized_data(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, gint offset,
int size, const char * label, guint16 vendor_id) {
proto_item * ti;
proto_tree * rtps_parameter_sequence_tree;
guint16 encapsulation_id;
gboolean encapsulation_little_endian = FALSE;
ti = proto_tree_add_text(tree, tvb, offset, -1, "%s", label);
rtps_parameter_sequence_tree = proto_item_add_subtree(ti, ett_rtps_serialized_data);
encapsulation_id = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_uint(rtps_parameter_sequence_tree, hf_rtps_param_serialize_encap_kind, tvb, offset, 2, encapsulation_id);
offset += 2;
if (encapsulation_id == ENCAPSULATION_CDR_LE ||
encapsulation_id == ENCAPSULATION_PL_CDR_LE) {
encapsulation_little_endian = TRUE;
}
proto_tree_add_item(rtps_parameter_sequence_tree, hf_rtps_param_serialize_encap_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
size -= 4;
switch (encapsulation_id) {
case ENCAPSULATION_CDR_LE:
case ENCAPSULATION_CDR_BE:
proto_tree_add_item(rtps_parameter_sequence_tree, hf_rtps_issue_data, tvb,
offset, size, encapsulation_little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case ENCAPSULATION_PL_CDR_LE:
case ENCAPSULATION_PL_CDR_BE:
dissect_parameter_sequence(rtps_parameter_sequence_tree, pinfo, tvb, offset,
encapsulation_little_endian, size, label, 0x0200, NULL, vendor_id);
break;
default:
proto_tree_add_text(rtps_parameter_sequence_tree, tvb, offset,
size, "%s", label);
}
}
void dissect_PAD(tvbuff_t *tvb,
packet_info *pinfo,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree) {
proto_item* item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, PAD_FLAGS);
item = proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header != 0) {
expert_add_info(pinfo, item, &ei_rtps_sm_octets_to_next_header_not_zero);
}
}
static void dissect_DATA_v1(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
int min_len;
int is_builtin_entity = 0;
gint old_offset = offset;
guint32 wid;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, DATA_FLAGSv1);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 20;
if ((flags & FLAG_DATA_H) != 0) min_len += 8;
if ((flags & FLAG_DATA_Q) != 0) min_len += 4;
if ((flags & FLAG_DATA_D) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
offset += 4;
is_builtin_entity |= rtps_util_add_entity_id(tree, tvb, offset,
hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key, hf_rtps_sm_rdentity_id_kind,
ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
is_builtin_entity |= rtps_util_add_entity_id(tree, tvb, offset,
hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key, hf_rtps_sm_wrentity_id_kind,
ett_rtps_wrentity, "writerEntityId", &wid);
offset += 4;
if (wid == ENTITYID_BUILTIN_PUBLICATIONS_WRITER && (flags & FLAG_DATA_A) != 0) {
col_append_str(pinfo->cinfo, COL_INFO, SM_EXTRA_WPLUS);
} else if (wid == ENTITYID_BUILTIN_PUBLICATIONS_WRITER && (flags & FLAG_DATA_A) == 0) {
col_append_str(pinfo->cinfo, COL_INFO, SM_EXTRA_WMINUS);
} else if (wid == ENTITYID_BUILTIN_SUBSCRIPTIONS_WRITER && (flags & FLAG_DATA_A) != 0) {
col_append_str(pinfo->cinfo, COL_INFO, SM_EXTRA_RPLUS);
} else if (wid == ENTITYID_BUILTIN_SUBSCRIPTIONS_WRITER && (flags & FLAG_DATA_A) == 0) {
col_append_str(pinfo->cinfo, COL_INFO, SM_EXTRA_RMINUS);
} else if (wid == ENTITYID_BUILTIN_SDP_PARTICIPANT_WRITER && (flags & FLAG_DATA_A) != 0) {
col_append_str(pinfo->cinfo, COL_INFO, SM_EXTRA_PPLUS);
} else if (wid == ENTITYID_BUILTIN_SDP_PARTICIPANT_WRITER && (flags & FLAG_DATA_A) == 0) {
col_append_str(pinfo->cinfo, COL_INFO, SM_EXTRA_PMINUS);
} else if (wid == ENTITYID_BUILTIN_TOPIC_WRITER && (flags & FLAG_DATA_A) != 0) {
col_append_str(pinfo->cinfo, COL_INFO, SM_EXTRA_TPLUS);
} else if (wid == ENTITYID_BUILTIN_TOPIC_WRITER && (flags & FLAG_DATA_A) == 0) {
col_append_str(pinfo->cinfo, COL_INFO, SM_EXTRA_TMINUS);
}
if ((flags & FLAG_DATA_H) != 0) {
rtps_util_add_guid_prefix_v1(tree, tvb, offset,
hf_rtps_sm_guid_prefix, hf_rtps_sm_host_id, hf_rtps_sm_app_id,
hf_rtps_sm_instance_id, hf_rtps_sm_app_kind,
"keyHashPrefix");
offset += 8;
} else {
}
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_entity_id, hf_rtps_sm_entity_id_key,
hf_rtps_sm_entity_id_kind, ett_rtps_entity, "keyHashSuffix", NULL);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSeqNumber");
offset += 8;
if ((flags & FLAG_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset,
little_endian, octets_to_next_header, "inlineQos",
0x0102, NULL, 0);
}
if ((flags & FLAG_DATA_D) != 0) {
if (is_builtin_entity) {
dissect_parameter_sequence(tree, pinfo, tvb, offset,
little_endian, octets_to_next_header, "serializedData",
0x0102, NULL, 0);
} else {
proto_tree_add_item(tree, hf_rtps_issue_data, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
}
}
static void dissect_DATA_v2(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, DATA_FLAGSv2);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 20;
if ((flags & FLAG_DATA_Q_v2) != 0) min_len += 4;
if ((flags & FLAG_DATA_D_v2) != 0) min_len += 4;
if ((flags & FLAG_DATA_H) != 0) min_len += 12;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
if (tree == NULL) {
offset += 8;
wid = NEXT_guint32(tvb, offset, little_endian);
offset += 12;
if ((flags & FLAG_DATA_H) != 0) {
offset += 12;
}
offset += 4;
if ((flags & FLAG_DATA_I) != 0) {
status_info = NEXT_guint32(tvb, offset, little_endian);
}
info_summary_append_ex(pinfo, wid, status_info);
return;
}
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", &wid);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSeqNumber");
offset += 8;
if ((flags & FLAG_DATA_H) != 0) {
rtps_util_add_guid_prefix_v2(tree, tvb, offset, hf_rtps_sm_guid_prefix, hf_rtps_sm_host_id,
hf_rtps_sm_app_id, hf_rtps_sm_counter, "keyHashPrefix");
offset += 12;
} else {
}
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_entity_id, hf_rtps_sm_entity_id_key,
hf_rtps_sm_entity_id_kind, ett_rtps_entity, "keyHashSuffix", NULL);
offset += 4;
if ((flags & FLAG_DATA_I) != 0) {
proto_tree_add_item(tree, hf_rtps_data_status_info, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
}
if ((flags & FLAG_DATA_Q_v2) != 0) {
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, NULL, vendor_id);
}
if ((flags & FLAG_DATA_D_v2) != 0) {
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData", vendor_id);
}
info_summary_append_ex(pinfo, wid, status_info);
}
static void dissect_DATA_FRAG(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree, guint16 vendor_id) {
int min_len;
gint old_offset = offset;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, NOKEY_DATA_FRAG_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 32;
if ((flags & FLAG_DATA_FRAG_Q) != 0) min_len += 4;
if ((flags & FLAG_DATA_FRAG_H) != 0) min_len += 12;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
if (tree == NULL) {
return;
}
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", NULL);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSeqNumber");
offset += 8;
if ((flags & FLAG_DATA_H) != 0) {
rtps_util_add_guid_prefix_v2(tree, tvb, offset, hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id, hf_rtps_sm_app_id, hf_rtps_sm_counter, "keyHashPrefix");
offset += 12;
} else {
}
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_entity_id, hf_rtps_sm_entity_id_key,
hf_rtps_sm_entity_id_kind, ett_rtps_entity, "keyHashSuffix", NULL);
offset += 4;
proto_tree_add_item(tree, hf_rtps_data_frag_number, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rtps_data_frag_num_fragments, tvb,
offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rtps_data_frag_size, tvb,
offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rtps_data_frag_sample_size, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
if ((flags & FLAG_DATA_Q_v2) != 0) {
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, NULL, vendor_id);
}
if ((flags & FLAG_DATA_D_v2) != 0) {
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData", vendor_id);
}
}
static void dissect_NOKEY_DATA(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree,
guint16 version, guint16 vendor_id) {
int min_len;
gint old_offset = offset;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, NOKEY_DATA_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 16;
if ((flags & FLAG_NOKEY_DATA_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", NULL);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSeqNumber");
offset += 8;
if ((flags & FLAG_NOKEY_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset,
little_endian, octets_to_next_header, "inlineQos",
version, NULL, vendor_id);
}
if ((version < 0x0200) && (flags & FLAG_NOKEY_DATA_D) == 0) {
proto_tree_add_item(tree, hf_rtps_issue_data, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
if ((version >= 0x0200) && (flags & FLAG_DATA_D_v2) != 0) {
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData", vendor_id);
}
}
static void dissect_NOKEY_DATA_FRAG(tvbuff_t *tvb, packet_info *pinfo, gint offset,
guint8 flags, gboolean little_endian, int octets_to_next_header, proto_tree *tree,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, NOKEY_DATA_FRAG_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 28;
if ((flags & FLAG_NOKEY_DATA_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
if (tree == NULL) {
return;
}
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", NULL);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSeqNumber");
offset += 8;
proto_tree_add_item(tree, hf_rtps_nokey_data_frag_number, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rtps_nokey_data_frag_num_fragments, tvb,
offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rtps_nokey_data_frag_size, tvb,
offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
if ((flags & FLAG_DATA_Q_v2) != 0) {
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, NULL, vendor_id);
}
if ((flags & FLAG_DATA_D_v2) != 0) {
dissect_serialized_data(tree, pinfo, tvb,offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData", vendor_id);
}
}
static void dissect_ACKNACK(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree, proto_item *item) {
gint original_offset;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, ACKNACK_FLAGS);
octet_item = proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header < 20) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= 20)");
return;
}
offset += 4;
original_offset = offset;
rtps_util_add_entity_id(tree,
tvb,
offset,
hf_rtps_sm_rdentity_id,
hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind,
ett_rtps_rdentity,
"readerEntityId",
NULL);
offset += 4;
rtps_util_add_entity_id(tree,
tvb,
offset,
hf_rtps_sm_wrentity_id,
hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind,
ett_rtps_wrentity,
"writerEntityId",
NULL);
offset += 4;
offset = rtps_util_add_bitmap(tree,
tvb,
offset,
little_endian,
"readerSNState");
if (offset + 4 == original_offset + octets_to_next_header) {
proto_tree_add_item(tree, hf_rtps_acknack_counter, tvb, offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
} else if (offset < original_offset + octets_to_next_header) {
expert_add_info_format(pinfo, item, &ei_rtps_extra_bytes, "Don't know how to decode those extra bytes: %d", octets_to_next_header - offset);
} else if (offset > original_offset + octets_to_next_header) {
expert_add_info(pinfo, item, &ei_rtps_missing_bytes);
}
}
static void dissect_NACK_FRAG(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, NACK_FRAG_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header < 24) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= 24)");
return;
}
if (tree == NULL) {
return;
}
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", NULL);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSN");
offset += 8;
offset = rtps_util_add_fragment_number_set(tree, pinfo, tvb, offset, little_endian,
"fragmentNumberState", octets_to_next_header - 20);
if (offset == -1) {
return;
}
proto_tree_add_item(tree, hf_rtps_nack_frag_count, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
static void dissect_HEARTBEAT(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree, guint16 version) {
guint32 counter;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, HEARTBEAT_FLAGS);
octet_item = proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if ((octets_to_next_header < 24) && (version <= 0x0101)) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= 24)");
return;
}
else if (octets_to_next_header < 28) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= 28)");
return;
}
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", NULL);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "firstAvailableSeqNumber");
offset += 8;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "lastSeqNumber");
offset += 8;
if (version >= 0x0101) {
counter = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_text(tree, tvb, offset, 4, "count: %u", counter);
}
}
static void dissect_HEARTBEAT_BATCH(tvbuff_t *tvb, packet_info *pinfo, gint offset,
guint8 flags, gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, HEARTBEAT_BATCH_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header < 36) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= 36)");
return;
}
if (tree == NULL) {
return;
}
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", NULL);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "firstBatchSN");
offset += 8;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "lastBatchSN");
offset += 8;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "firstSeqNumber");
offset += 8;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "lastSeqNumber");
offset += 8;
proto_tree_add_item(tree, hf_rtps_heartbeat_batch_count, tvb, offset,
4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
static void dissect_HEARTBEAT_FRAG(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, HEARTBEAT_FRAG_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header < 24) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= 24)");
return;
}
if (tree == NULL) {
return;
}
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", NULL);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSeqNumber");
offset += 8;
proto_tree_add_item(tree, hf_rtps_heartbeat_frag_number, tvb, offset,
4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rtps_heartbeat_frag_count, tvb, offset,
4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
static void dissect_RTPS_DATA(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree,
guint16 vendor_id, gboolean is_session) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, RTPS_DATA_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 24;
if (is_session) {
min_len += 8;
}
if ((flags & FLAG_RTPS_DATA_Q) != 0) min_len += 4;
if ((flags & FLAG_RTPS_DATA_D) != 0) min_len += 4;
if ((flags & FLAG_RTPS_DATA_K) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
if (tree == NULL) {
offset += 12;
wid = NEXT_guint32(tvb, offset, little_endian);
offset += 12;
if ((flags & FLAG_RTPS_DATA_Q) != 0) {
dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, &status_info, vendor_id);
}
info_summary_append_ex(pinfo, wid, status_info);
return;
}
offset += 4;
proto_tree_add_item(tree, hf_rtps_extra_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_text(tree, tvb, offset, 2, "Octets to inline QoS: %d",
NEXT_guint16(tvb, offset, little_endian));
offset += 2;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", &wid);
offset += 4;
if (is_session) {
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSessionSeqNumber");
offset += 8;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerVirtualSeqNumber");
offset += 8;
} else {
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSeqNumber");
offset += 8;
}
if ((flags & FLAG_RTPS_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, &status_info, vendor_id);
}
if (((flags & FLAG_RTPS_DATA_D) != 0) || ((flags & FLAG_RTPS_DATA_K) != 0)) {
if (wid == ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_WRITER) {
proto_tree * rtps_pm_tree;
proto_tree * guid_tree;
guint32 kind;
guint16 encapsulation_id;
guint16 encapsulation_len;
proto_item * ti = proto_tree_add_text(tree, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
"ParticipantMessageData");
rtps_pm_tree = proto_item_add_subtree(ti, ett_rtps_part_message_data);
encapsulation_id = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_text(rtps_pm_tree, tvb, offset, 2, "encapsulation kind: %s",
val_to_str(encapsulation_id, encapsulation_id_vals, "unknown (%02x)"));
offset += 2;
#if 0
if (encapsulation_id == ENCAPSULATION_CDR_LE ||
encapsulation_id == ENCAPSULATION_PL_CDR_LE) {
encapsulation_little_endian = 1;
}
#endif
encapsulation_len = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_text(rtps_pm_tree, tvb, offset, 2,
"encapsulation options: %04x", encapsulation_len);
offset += 2;
guid_tree = proto_item_add_subtree(ti, ett_rtps_part_message_data);
rtps_util_add_guid_prefix_v2(guid_tree, tvb, offset, hf_rtps_sm_guid_prefix, hf_rtps_sm_host_id,
hf_rtps_sm_app_id, hf_rtps_sm_counter, "participantGuidPrefix");
offset += 12;
kind = NEXT_guint32(tvb, offset, FALSE);
proto_tree_add_text(guid_tree, tvb, offset, 4, "kind: %s",
val_to_str(kind, participant_message_data_kind, "unknown (%04x)"));
offset += 4;
rtps_util_add_seq_octets(rtps_pm_tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset), hf_rtps_data_serialize_data);
} else {
const char *label;
if (((flags & FLAG_RTPS_DATA_D) != 0) || ((flags & FLAG_RTPS_DATA_K) == 0)) {
label = "serializedData";
} else if (((flags & FLAG_RTPS_DATA_D) == 0) || ((flags & FLAG_RTPS_DATA_K) != 0)) {
label = "serializedKey";
} else {
label = "<invalid or unknown data type>";
}
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
label, vendor_id);
}
}
info_summary_append_ex(pinfo, wid, status_info);
}
static void dissect_RTPS_DATA_FRAG(tvbuff_t *tvb,
packet_info *pinfo,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, RTPS_DATA_FRAG_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 36;
if ((flags & FLAG_RTPS_DATA_FRAG_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
if (tree == NULL) {
offset += 12;
wid = NEXT_guint32(tvb, offset, little_endian);
offset += 24;
if ((flags & FLAG_RTPS_DATA_FRAG_Q) != 0) {
dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, &status_info, vendor_id);
}
info_summary_append_ex(pinfo, wid, status_info);
return;
}
offset += 4;
proto_tree_add_item(tree, hf_rtps_extra_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_text(tree, tvb, offset, 2, "Octets to inline QoS: %d",
NEXT_guint16(tvb, offset, little_endian));
offset += 2;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", &wid);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSeqNumber");
offset += 8;
proto_tree_add_item(tree, hf_rtps_data_frag_number, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rtps_data_frag_num_fragments, tvb,
offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rtps_data_frag_size, tvb,
offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_rtps_data_frag_sample_size, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
if ((flags & FLAG_RTPS_DATA_FRAG_Q) != 0) {
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, &status_info, vendor_id);
}
{
const char *label = "serializedData";
if ((flags & FLAG_RTPS_DATA_FRAG_K) != 0) {
label = "serializedKey";
}
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
label, vendor_id);
}
info_summary_append_ex(pinfo, wid, status_info);
}
static void dissect_RTPS_DATA_BATCH(tvbuff_t *tvb, packet_info *pinfo, gint offset,
guint8 flags, gboolean little_endian, int octets_to_next_header,
proto_tree *tree, guint16 vendor_id) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
gint32 octectsToSLEncapsulationId;
gint32 sampleListOffset;
guint16 encapsulation_id;
guint16 *sample_info_flags = NULL;
guint32 *sample_info_length = NULL;
gint32 sample_info_count = 0,
sample_info_max = rtps_max_batch_samples_dissected;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, RTPS_DATA_BATCH_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 44;
if ((flags & FLAG_RTPS_DATA_BATCH_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
if (tree == NULL) {
offset += 12;
wid = NEXT_guint32(tvb, offset, little_endian);
offset += 24;
if ((flags & FLAG_DATA_Q_v2) != 0) {
dissect_parameter_sequence(tree, pinfo, tvb, offset,
little_endian, octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, &status_info, vendor_id);
}
info_summary_append_ex(pinfo, wid, status_info);
return;
}
offset += 4;
proto_tree_add_item(tree, hf_rtps_extra_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_text(tree, tvb, offset, 2, "Octets to inline QoS: %d",
NEXT_guint16(tvb, offset, little_endian));
offset += 2;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", &wid);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "batchSeqNumber");
offset += 8;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "firstSampleSeqNumber");
offset += 8;
proto_tree_add_item(tree, hf_rtps_data_batch_offset_to_last_sample_sn, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rtps_data_batch_sample_count, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
if ((flags & FLAG_RTPS_DATA_BATCH_Q) != 0) {
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"batchInlineQos", 0x0200, &status_info, vendor_id);
}
octectsToSLEncapsulationId = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_item(tree, hf_rtps_data_batch_octets_to_sl_encap_id, tvb,
offset, 4, octectsToSLEncapsulationId);
offset += 4;
sampleListOffset = offset + octectsToSLEncapsulationId;
{
proto_item *ti, *list_item;
proto_tree *sil_tree;
sample_info_count = 0;
list_item = proto_tree_add_text(tree, tvb, offset, -1, "Sample Info List");
sil_tree = proto_item_add_subtree(list_item, ett_rtps_sample_info_list);
if (rtps_max_batch_samples_dissected == 0) {
sample_info_max = 1024;
}
sample_info_flags = (guint16 *)wmem_alloc(wmem_packet_scope(), sizeof(guint16) * sample_info_max);
sample_info_length = (guint32 *)wmem_alloc(wmem_packet_scope(), sizeof(guint32) * sample_info_max);
while (offset < sampleListOffset) {
guint16 flags2;
gint min_length;
proto_tree * si_tree;
gint offset_begin_sampleinfo = offset;
if (rtps_max_batch_samples_dissected > 0 && (guint)sample_info_count >= rtps_max_batch_samples_dissected) {
expert_add_info(pinfo, list_item, &ei_rtps_more_samples_available);
offset = sampleListOffset;
break;
}
ti = proto_tree_add_text(sil_tree, tvb, offset, -1, "sampleInfo[%d]", sample_info_count);
si_tree = proto_item_add_subtree(ti, ett_rtps_sample_info);
flags2 = NEXT_guint16(tvb, offset, FALSE);
sample_info_flags[sample_info_count] = flags2;
rtps_util_decode_flags_16bit(si_tree, tvb, offset, flags2, RTPS_SAMPLE_INFO_FLAGS16);
offset += 2;
proto_tree_add_item(tree, hf_rtps_data_batch_octets_to_inline_qos, tvb,
offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
min_length = 4;
if ((flags2 & FLAG_SAMPLE_INFO_T) != 0) min_len += 8;
if ((flags2 & FLAG_SAMPLE_INFO_Q) != 0) min_len += 4;
if ((flags2 & FLAG_SAMPLE_INFO_O) != 0) min_len += 4;
if (sampleListOffset - offset < min_length) {
expert_add_info_format(pinfo, ti, &ei_rtps_parameter_value_invalid, "Error: not enough bytes to dissect sample info");
return;
}
sample_info_length[sample_info_count] = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_item(tree, hf_rtps_data_batch_serialized_data_length, tvb,
offset, 4, sample_info_length[sample_info_count]);
offset += 4;
if ((flags2 & FLAG_SAMPLE_INFO_T) != 0) {
rtps_util_add_ntp_time(si_tree, tvb, offset, little_endian, hf_rtps_data_batch_timestamp);
offset += 8;
}
if ((flags2 & FLAG_SAMPLE_INFO_O) != 0) {
proto_tree_add_item(tree, hf_rtps_data_batch_offset_sn, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
}
if ((flags2 & FLAG_SAMPLE_INFO_Q) != 0) {
offset = dissect_parameter_sequence(si_tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"sampleInlineQos", 0x0200, &status_info, vendor_id);
}
proto_item_set_len(ti, offset - offset_begin_sampleinfo);
sample_info_count++;
}
}
encapsulation_id = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_text(tree, tvb, offset, 2,
"encapsulation kind: %s",
val_to_str(encapsulation_id, encapsulation_id_vals, "unknown (%02x)"));
offset += 2;
offset += 2;
if (octets_to_next_header - (offset - old_offset) > 0) {
proto_item * ti;
proto_tree * sil_tree;
gint count = 0;
const char * label;
ti = proto_tree_add_text(tree, tvb, offset, -1, "Serialized Sample List");
sil_tree = proto_item_add_subtree(ti, ett_rtps_sample_batch_list);
for (count = 0; count < sample_info_count; ++count) {
if (octets_to_next_header - (offset - old_offset) + 4 < (gint)sample_info_length[count]) {
expert_add_info_format(pinfo, ti, &ei_rtps_parameter_value_invalid, "Error: not enough bytes to dissect sample");
return;
}
if ((sample_info_flags[count] & FLAG_SAMPLE_INFO_K) != 0) {
label = "serializedKey[%d]";
} else {
label = "serializedData[%d]";
}
proto_tree_add_text(sil_tree, tvb, offset, sample_info_length[count], label, count);
offset += sample_info_length[count];
}
}
info_summary_append_ex(pinfo, wid, status_info);
}
static void dissect_GAP(tvbuff_t *tvb,
packet_info *pinfo,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree) {
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, GAP_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header < 24) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= 24)");
return;
}
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset,
hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key, hf_rtps_sm_rdentity_id_kind,
ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset,
hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key, hf_rtps_sm_wrentity_id_kind,
ett_rtps_wrentity, "writerEntityId", NULL);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "gapStart");
offset += 8;
rtps_util_add_bitmap(tree, tvb, offset, little_endian, "gapList");
}
void dissect_INFO_TS(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
int min_len;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_TS_FLAGS);
octet_item = proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 0;
if ((flags & FLAG_INFO_TS_T) == 0) min_len += 8;
if (octets_to_next_header != min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be == %u)", min_len);
return;
}
offset += 4;
if ((flags & FLAG_INFO_TS_T) == 0) {
rtps_util_add_ntp_time(tree,
tvb,
offset,
little_endian,
hf_rtps_info_ts_timestamp);
}
}
void dissect_INFO_SRC(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree, guint16 rtps_version) {
proto_item* octet_item;
guint32 ip;
guint16 version;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_SRC_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header != 16) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be == 16)");
return;
}
offset += 4;
ip = NEXT_guint32(tvb, offset, little_endian);
version = tvb_get_ntohs(tvb, offset+4);
if (version < 0x102) {
proto_tree_add_ipv4(tree, hf_rtps_info_src_ip, tvb, offset, 4, ip);
} else {
proto_tree_add_uint(tree, hf_rtps_info_src_unused, tvb, offset, 4, ip);
}
offset += 4;
rtps_util_add_protocol_version(tree, tvb, offset);
offset += 2;
rtps_util_add_vendor_id(NULL, tvb, offset);
offset += 2;
if (rtps_version < 0x0200) {
rtps_util_add_guid_prefix_v1(tree, tvb, offset,
hf_rtps_sm_guid_prefix, hf_rtps_sm_host_id, hf_rtps_sm_app_id,
hf_rtps_sm_instance_id, hf_rtps_sm_app_kind,
NULL);
} else {
rtps_util_add_guid_prefix_v2(tree, tvb, offset, hf_rtps_guid_prefix,
hf_rtps_host_id, hf_rtps_app_id, hf_rtps_sm_counter, NULL);
}
}
static void dissect_INFO_REPLY_IP4(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
int min_len;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_REPLY_IP4_FLAGS);
octet_item = proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 8;
if ((flags & FLAG_INFO_REPLY_IP4_M) != 0) min_len += 8;
if (octets_to_next_header != min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be == %u)", min_len);
return;
}
offset += 4;
rtps_util_add_locator_udp_v4(tree, pinfo, tvb, offset,
"unicastReplyLocator", little_endian);
offset += 8;
if ((flags & FLAG_INFO_REPLY_IP4_M) != 0) {
rtps_util_add_locator_udp_v4(tree, pinfo, tvb, offset,
"multicastReplyLocator", little_endian);
}
}
static void dissect_INFO_DST(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree, guint16 version) {
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_DST_FLAGS);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header != 8) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be == 8)");
return;
}
offset += 4;
if (version < 0x0200) {
rtps_util_add_guid_prefix_v1(tree, tvb, offset,
hf_rtps_sm_guid_prefix, hf_rtps_sm_host_id, hf_rtps_sm_app_id,
hf_rtps_sm_instance_id, hf_rtps_sm_app_kind,
NULL);
} else {
rtps_util_add_guid_prefix_v2(tree, tvb, offset, hf_rtps_guid_prefix,
hf_rtps_host_id, hf_rtps_app_id, hf_rtps_sm_counter, NULL);
}
}
static void dissect_INFO_REPLY(tvbuff_t *tvb,
packet_info *pinfo,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree) {
int min_len;
proto_item* octet_item;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_REPLY_FLAGS);
octet_item = proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 4;
if ((flags & FLAG_INFO_REPLY_M) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
offset += 4;
offset = rtps_util_add_locator_list(tree, pinfo, tvb, offset, "unicastReplyLocatorList", little_endian);
if ((flags & FLAG_INFO_REPLY_M) != 0) {
rtps_util_add_locator_list(tree, pinfo, tvb, offset, "multicastReplyLocatorList", little_endian);
}
}
static gboolean dissect_rtps_submessage_v2(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, guint8 submessageId, guint16 vendor_id, gint octets_to_next_header,
proto_tree* rtps_submessage_tree, proto_item* submessage_item)
{
switch (submessageId)
{
case SUBMESSAGE_DATA_FRAG:
dissect_DATA_FRAG(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, vendor_id);
break;
case SUBMESSAGE_NOKEY_DATA_FRAG:
dissect_NOKEY_DATA_FRAG(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, vendor_id);
break;
case SUBMESSAGE_NACK_FRAG:
dissect_NACK_FRAG(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_ACKNACK_SESSION:
case SUBMESSAGE_ACKNACK_BATCH:
dissect_ACKNACK(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, submessage_item);
break;
case SUBMESSAGE_HEARTBEAT_SESSION:
case SUBMESSAGE_HEARTBEAT_BATCH:
dissect_HEARTBEAT_BATCH(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_HEARTBEAT_FRAG:
dissect_HEARTBEAT_FRAG(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_RTPS_DATA_SESSION:
case SUBMESSAGE_RTPS_DATA:
dissect_RTPS_DATA(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree,
vendor_id, (submessageId == SUBMESSAGE_RTPS_DATA_SESSION));
break;
case SUBMESSAGE_RTPS_DATA_FRAG:
dissect_RTPS_DATA_FRAG(tvb, pinfo, offset, flags, little_endian, octets_to_next_header,
rtps_submessage_tree, vendor_id);
break;
case SUBMESSAGE_RTPS_DATA_BATCH:
dissect_RTPS_DATA_BATCH(tvb, pinfo, offset, flags, little_endian, octets_to_next_header,
rtps_submessage_tree, vendor_id);
break;
default:
return FALSE;
}
return TRUE;
}
static gboolean dissect_rtps_submessage_v1(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags, gboolean little_endian,
guint8 submessageId, guint16 version, guint16 vendor_id, gint octets_to_next_header,
proto_tree* rtps_submessage_tree, proto_item* submessage_item)
{
switch (submessageId)
{
case SUBMESSAGE_PAD:
dissect_PAD(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_DATA:
if (version < 0x0200) {
dissect_DATA_v1(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
} else {
dissect_DATA_v2(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, vendor_id);
}
break;
case SUBMESSAGE_NOKEY_DATA:
dissect_NOKEY_DATA(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree,
version, vendor_id);
break;
case SUBMESSAGE_ACKNACK:
dissect_ACKNACK(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, submessage_item);
break;
case SUBMESSAGE_HEARTBEAT:
dissect_HEARTBEAT(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, version);
break;
case SUBMESSAGE_GAP:
dissect_GAP(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_INFO_TS:
dissect_INFO_TS(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_INFO_SRC:
dissect_INFO_SRC(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, version);
break;
case SUBMESSAGE_INFO_REPLY_IP4:
dissect_INFO_REPLY_IP4(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_INFO_DST:
dissect_INFO_DST(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, version);
break;
case SUBMESSAGE_INFO_REPLY:
dissect_INFO_REPLY(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
default:
return FALSE;
}
return TRUE;
}
static gboolean dissect_rtps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *rtps_tree, *rtps_submessage_tree;
gint offset = 0;
guint8 submessageId, flags, majorRev;
guint16 version, vendor_id;
gboolean little_endian, is_ping;
gint next_submsg, octets_to_next_header;
int sub_hf;
const value_string* sub_vals;
const gboolean is_tcp = (pinfo->ptype == PT_TCP);
if (is_tcp) {
offset = 4;
}
if (!tvb_bytes_exist(tvb, offset, 16))
return FALSE;
if (tvb_get_ntohl(tvb, offset) != RTPS_MAGIC_NUMBER)
return FALSE;
majorRev = tvb_get_guint8(tvb,offset+4);
if ((majorRev != 1) && (majorRev != 2))
return FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTPS");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_rtps, tvb, 0, -1, ENC_NA);
rtps_tree = proto_item_add_subtree(ti, ett_rtps);
version = rtps_util_add_protocol_version(rtps_tree, tvb, offset+4);
vendor_id = rtps_util_add_vendor_id(rtps_tree, tvb, offset+6);
is_ping = rtps_is_ping(tvb, pinfo, offset+8);
if (!is_ping) {
if (version < 0x0200)
rtps_util_add_guid_prefix_v1(rtps_tree, tvb, offset+8,
hf_rtps_guid_prefix, hf_rtps_host_id, hf_rtps_app_id,
hf_rtps_app_id_instance_id, hf_rtps_app_id_app_kind, NULL);
else
rtps_util_add_guid_prefix_v2(rtps_tree, tvb, offset+8, hf_rtps_guid_prefix,
hf_rtps_host_id, hf_rtps_app_id, hf_rtps_sm_counter, NULL);
#ifdef RTI_BUILD
pinfo->guid_prefix_host = tvb_get_ntohl(tvb, offset + 8);
pinfo->guid_prefix_app = tvb_get_ntohl(tvb, offset + 12);
pinfo->guid_prefix_count = tvb_get_ntohl(tvb, offset + 16);
pinfo->guid_rtps2 = 1;
#endif
}
{
int domain_id, doffset, participant_idx = 0, nature;
proto_tree *mapping_tree;
if (version < 0x0200) {
domain_id = ((pinfo->destport - PORT_BASE)/10) % 100;
participant_idx = (pinfo->destport - PORT_BASE) / 1000;
nature = (pinfo->destport % 10);
} else {
domain_id = (pinfo->destport - PORT_BASE) / 250;
doffset = (pinfo->destport - PORT_BASE - domain_id * 250);
if (doffset == 0) {
nature = PORT_METATRAFFIC_MULTICAST;
} else if (doffset == 1) {
nature = PORT_USERTRAFFIC_MULTICAST;
} else {
participant_idx = (doffset - 10) / 2;
if ( (doffset - 10) % 2 == 0) {
nature = PORT_METATRAFFIC_UNICAST;
} else {
nature = PORT_USERTRAFFIC_UNICAST;
}
}
}
if ((nature == PORT_METATRAFFIC_UNICAST) || (nature == PORT_USERTRAFFIC_UNICAST) ||
(version < 0x0200)) {
ti = proto_tree_add_text(rtps_tree, tvb, 0, 0,
"Default port mapping: domainId=%d, "
"participantIdx=%d, nature=%s",
domain_id,
participant_idx,
val_to_str(nature, nature_type_vals, "%02x"));
} else {
ti = proto_tree_add_text(rtps_tree, tvb, 0, 0,
"Default port mapping: %s, domainId=%d",
val_to_str(nature, nature_type_vals, "%02x"),
domain_id);
}
mapping_tree = proto_item_add_subtree(ti, ett_rtps_default_mapping);
ti = proto_tree_add_uint(mapping_tree, hf_rtps_domain_id, tvb, 0, 0, domain_id);
PROTO_ITEM_SET_GENERATED(ti);
if ((nature == PORT_METATRAFFIC_UNICAST) || (nature == PORT_USERTRAFFIC_UNICAST) ||
(version < 0x0200)) {
ti = proto_tree_add_uint(mapping_tree, hf_rtps_participant_idx, tvb, 0, 0, participant_idx);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_uint(mapping_tree, hf_rtps_nature_type, tvb, 0, 0, nature);
PROTO_ITEM_SET_GENERATED(ti);
}
offset = (version < 0x0200) ? 16 : 20;
if (is_tcp)
offset += 4;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
submessageId = tvb_get_guint8(tvb, offset);
if (version < 0x0200) {
sub_hf = hf_rtps_sm_id;
sub_vals = submessage_id_vals;
} else {
sub_hf = hf_rtps_sm_idv2;
sub_vals = submessage_id_valsv2;
}
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", val_to_str(submessageId, sub_vals, "Unknown[%02x]"));
if (submessageId & 0x80) {
ti = proto_tree_add_uint_format_value(rtps_tree, sub_hf, tvb, offset, 1,
submessageId, "Vendor-specific (0x%02x)", submessageId);
} else {
ti = proto_tree_add_uint(rtps_tree, sub_hf, tvb, offset, 1, submessageId);
}
rtps_submessage_tree = proto_item_add_subtree(ti, ett_rtps_submessage);
flags = tvb_get_guint8(tvb, offset + 1);
little_endian = ((flags & FLAG_E) != 0);
octets_to_next_header = NEXT_guint16(tvb, offset + 2, little_endian);
if ((octets_to_next_header == 0) && (version >= 0x0200))
octets_to_next_header = tvb_reported_length_remaining(tvb, offset + 4);
next_submsg = offset + octets_to_next_header + 4;
proto_item_set_len(ti, octets_to_next_header + 4);
if (!dissect_rtps_submessage_v1(tvb, pinfo, offset, flags, little_endian,
submessageId, version, vendor_id,
octets_to_next_header, rtps_submessage_tree, ti)) {
if ((version < 0x0200) ||
!dissect_rtps_submessage_v2(tvb, pinfo, offset, flags, little_endian, submessageId,
vendor_id, octets_to_next_header, rtps_submessage_tree, ti)) {
proto_tree_add_uint(rtps_submessage_tree, hf_rtps_sm_flags,
tvb, offset + 1, 1, flags);
proto_tree_add_uint(rtps_submessage_tree,
hf_rtps_sm_octets_to_next_header,
tvb, offset + 2, 2, next_submsg);
}
}
offset = next_submsg;
}
return TRUE;
}
void proto_register_rtps(void) {
static hf_register_info hf[] = {
{ &hf_rtps_protocol_version, {
"version",
"rtps.version",
FT_UINT16,
BASE_HEX,
NULL,
0,
"RTPS protocol version number",
HFILL }
},
{ &hf_rtps_protocol_version_major, {
"major",
"rtps.version.major",
FT_INT8,
BASE_DEC,
NULL,
0,
"RTPS major protocol version number",
HFILL }
},
{ &hf_rtps_protocol_version_minor, {
"minor",
"rtps.version.minor",
FT_INT8,
BASE_DEC,
NULL,
0,
"RTPS minor protocol version number",
HFILL }
},
{ &hf_rtps_domain_id, {
"domain_id",
"rtps.domain_id",
FT_UINT32,
BASE_DEC,
NULL,
0,
"Domain ID",
HFILL }
},
{ &hf_rtps_participant_idx, {
"participant_idx",
"rtps.participant_idx",
FT_UINT32,
BASE_DEC,
NULL,
0,
"Participant index",
HFILL }
},
{ &hf_rtps_nature_type, {
"traffic_nature",
"rtps.traffic_nature",
FT_UINT32,
BASE_DEC,
VALS(nature_type_vals),
0,
"Nature of the traffic (meta/user-traffic uni/multi-cast)",
HFILL }
},
{ &hf_rtps_vendor_id, {
"vendorId",
"rtps.vendorId",
FT_UINT16,
BASE_HEX,
NULL,
0,
"Unique identifier of the DDS vendor that generated this packet",
HFILL }
},
{ &hf_rtps_guid_prefix, {
"guidPrefix",
"rtps.guidPrefix",
FT_UINT64,
BASE_HEX,
NULL,
0,
"GuidPrefix of the RTPS packet",
HFILL }
},
{ &hf_rtps_host_id, {
"hostId",
"rtps.hostId",
FT_UINT32,
BASE_HEX,
NULL,
0,
"Sub-component 'hostId' of the GuidPrefix of the RTPS packet",
HFILL }
},
{ &hf_rtps_app_id, {
"appId",
"rtps.appId",
FT_UINT32,
BASE_HEX,
NULL,
0,
"Sub-component 'appId' of the GuidPrefix of the RTPS packet",
HFILL }
},
{ &hf_rtps_app_id_instance_id, {
"appId.instanceId",
"rtps.appId.instanceId",
FT_UINT24,
BASE_HEX,
NULL,
0,
"'instanceId' field of the 'AppId' structure",
HFILL }
},
{ &hf_rtps_app_id_app_kind, {
"appid.appKind",
"rtps.appId.appKind",
FT_UINT8,
BASE_HEX,
VALS(app_kind_vals),
0,
"'appKind' field of the 'AppId' structure",
HFILL }
},
{ &hf_rtps_sm_id, {
"submessageId",
"rtps.sm.id",
FT_UINT8,
BASE_HEX,
VALS(submessage_id_vals),
0,
"defines the type of submessage",
HFILL }
},
{ &hf_rtps_sm_idv2, {
"submessageId",
"rtps.sm.id",
FT_UINT8,
BASE_HEX,
VALS(submessage_id_valsv2),
0,
"defines the type of submessage",
HFILL }
},
{ &hf_rtps_sm_flags, {
"Flags",
"rtps.sm.flags",
FT_UINT8,
BASE_HEX,
NULL,
0,
"bitmask representing the flags associated with a submessage",
HFILL }
},
{ &hf_rtps_sm_octets_to_next_header, {
"octetsToNextHeader",
"rtps.sm.octetsToNextHeader",
FT_UINT16,
BASE_DEC,
NULL,
0,
"Size of the submessage payload",
HFILL }
},
{ &hf_rtps_sm_guid_prefix, {
"guidPrefix",
"rtps.sm.guidPrefix",
FT_UINT64,
BASE_HEX,
NULL,
0,
"a generic guidPrefix that is transmitted inside the submessage (this is NOT the guidPrefix described in the packet header",
HFILL }
},
{ &hf_rtps_sm_host_id, {
"host_id",
"rtps.sm.guidPrefix.hostId",
FT_UINT32,
BASE_HEX,
NULL,
0,
"The hostId component of the rtps.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_app_id, {
"appId",
"rtps.sm.guidPrefix.appId",
FT_UINT32,
BASE_HEX,
NULL,
0,
"AppId component of the rtps.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_instance_id, {
"instanceId",
"rtps.sm.guidPrefix.appId.instanceId",
FT_UINT24,
BASE_HEX,
NULL,
0,
"instanceId component of the AppId of the rtps.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_app_kind, {
"appKind",
"rtps.sm.guidPrefix.appId.appKind",
FT_UINT8,
BASE_HEX,
NULL,
0,
"appKind component of the AppId of the rtps.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_counter, {
"counter",
"rtps.sm.guidPrefix.counter",
FT_UINT32,
BASE_HEX,
NULL,
0,
"The counter component of the rtps.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_entity_id, {
"entityId",
"rtps.sm.entityId",
FT_UINT32,
BASE_HEX,
VALS(entity_id_vals),
0,
"Object entity ID as it appears in a DATA submessage (keyHashSuffix)",
HFILL }
},
{ &hf_rtps_sm_entity_id_key, {
"entityKey",
"rtps.sm.entityId.entityKey",
FT_UINT24,
BASE_HEX,
NULL,
0,
"'entityKey' field of the object entity ID",
HFILL }
},
{ &hf_rtps_sm_entity_id_kind, {
"entityKind",
"rtps.sm.entityId.entityKind",
FT_UINT8,
BASE_HEX,
VALS(entity_kind_vals),
0,
"'entityKind' field of the object entity ID",
HFILL }
},
{ &hf_rtps_sm_rdentity_id, {
"readerEntityId",
"rtps.sm.rdEntityId",
FT_UINT32,
BASE_HEX,
VALS(entity_id_vals),
0,
"Reader entity ID as it appears in a submessage",
HFILL }
},
{ &hf_rtps_sm_rdentity_id_key, {
"readerEntityKey",
"rtps.sm.rdEntityId.entityKey",
FT_UINT24,
BASE_HEX,
NULL,
0,
"'entityKey' field of the reader entity ID",
HFILL }
},
{ &hf_rtps_sm_rdentity_id_kind, {
"readerEntityKind",
"rtps.sm.rdEntityId.entityKind",
FT_UINT8,
BASE_HEX,
VALS(entity_kind_vals),
0,
"'entityKind' field of the reader entity ID",
HFILL }
},
{ &hf_rtps_sm_wrentity_id, {
"writerEntityId",
"rtps.sm.wrEntityId",
FT_UINT32,
BASE_HEX,
VALS(entity_id_vals),
0,
"Writer entity ID as it appears in a submessage",
HFILL }
},
{ &hf_rtps_sm_wrentity_id_key, {
"writerEntityKey",
"rtps.sm.wrEntityId.entityKey",
FT_UINT24,
BASE_HEX,
NULL,
0,
"'entityKey' field of the writer entity ID",
HFILL }
},
{ &hf_rtps_sm_wrentity_id_kind, {
"writerEntityKind",
"rtps.sm.wrEntityId.entityKind",
FT_UINT8,
BASE_HEX,
VALS(entity_kind_vals),
0,
"'entityKind' field of the writer entity ID",
HFILL }
},
{ &hf_rtps_sm_seq_number, {
"writerSeqNumber",
"rtps.sm.seqNumber",
FT_INT64,
BASE_DEC,
NULL,
0,
"Writer sequence number",
HFILL }
},
{ &hf_rtps_info_src_ip, {
"appIpAddress",
"rtps.info_src.ip",
FT_IPv4,
BASE_NONE,
NULL,
0,
NULL,
HFILL }
},
{ &hf_rtps_info_src_unused, {
"Unused",
"rtps.info_src.unused",
FT_UINT32,
BASE_HEX,
NULL,
0,
NULL,
HFILL }
},
{ &hf_rtps_parameter_id, {
"parameterId",
"rtps.param.id",
FT_UINT16,
BASE_HEX,
VALS(parameter_id_vals),
0,
"Parameter Id",
HFILL }
},
{ &hf_rtps_parameter_id_v2, {
"parameterId",
"rtps.param.id",
FT_UINT16,
BASE_HEX,
VALS(parameter_id_v2_vals),
0,
"Parameter Id",
HFILL }
},
{ &hf_rtps_parameter_length, {
"parameterLength",
"rtps.param.length",
FT_UINT16,
BASE_DEC,
NULL,
0,
"Parameter Length",
HFILL }
},
{ &hf_rtps_param_topic_name, {
"topic",
"rtps.param.topicName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"String representing the value value of a PID_TOPIC parameter",
HFILL }
},
{ &hf_rtps_param_strength, {
"strength",
"rtps.param.strength",
FT_INT32,
BASE_DEC,
NULL,
0,
"Decimal value representing the value of a PID_OWNERSHIP_STRENGTH parameter",
HFILL }
},
{ &hf_rtps_param_type_name, {
"typeName",
"rtps.param.typeName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"String representing the value of a PID_TYPE_NAME parameter",
HFILL }
},
{ &hf_rtps_param_user_data, {
"userData",
"rtps.param.userData",
FT_BYTES,
BASE_NONE,
NULL,
0,
"The user data sent in a PID_USER_DATA parameter",
HFILL }
},
{ &hf_rtps_param_group_data, {
"groupData",
"rtps.param.groupData",
FT_BYTES,
BASE_NONE,
NULL,
0,
"The user data sent in a PID_GROUP_DATA parameter",
HFILL }
},
{ &hf_rtps_param_topic_data, {
"topicData",
"rtps.param.topicData",
FT_BYTES,
BASE_NONE,
NULL,
0,
"The user data sent in a PID_TOPIC_DATA parameter",
HFILL }
},
{ &hf_rtps_param_content_filter_name, {
"contentFilterName",
"rtps.param.contentFilterName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"Value of the content filter name as sent in a PID_CONTENT_FILTER_PROPERTY parameter",
HFILL }
},
{ &hf_rtps_param_related_topic_name, {
"relatedTopicName",
"rtps.param.relatedTopicName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"Value of the related topic name as sent in a PID_CONTENT_FILTER_PROPERTY parameter",
HFILL }
},
{ &hf_rtps_param_filter_name, {
"filterName",
"rtps.param.filterName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"Value of the filter name as sent in a PID_CONTENT_FILTER_PROPERTY parameter",
HFILL }
},
{ &hf_rtps_durability_service_cleanup_delay,
{ "Service Cleanup Delay", "rtps.durability.service_cleanup_delay",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_liveliness_lease_duration,
{ "Lease Duration", "rtps.liveliness.lease_duration",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_participant_lease_duration,
{ "Duration", "rtps.participant_lease_duration",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_time_based_filter_minimum_separation,
{ "Minimum Separation", "rtps.time_based_filter.minimum_separation",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_reliability_max_blocking_time,
{ "Max Blocking Time", "rtps.reliability.max_blocking_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_deadline_period,
{ "Period", "rtps.deadline_period",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_latency_budget_duration,
{ "Duration", "rtps.latency_budget.duration",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_lifespan_duration,
{ "Duration", "rtps.lifespan",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_persistence,
{ "Persistence", "rtps.persistence",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_info_ts_timestamp,
{ "Timestamp", "rtps.info_ts.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_locator_kind,
{ "Kind", "rtps.locator.kind",
FT_UINT32, BASE_HEX, VALS(rtps_locator_kind_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_locator_port,
{ "Port", "rtps.locator.port",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_locator_ipv4,
{ "Address", "rtps.locator.ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_locator_ipv6,
{ "Address", "rtps.locator.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_participant_builtin_endpoints,
{ "BuiltIn Endpoint", "rtps.participant_builtin_endpoints",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_participant_manual_liveliness_count,
{ "Manual Liveliness Count", "rtps.participant_manual_liveliness_count",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_history_depth,
{ "Depth", "rtps.history_depth",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_resource_limit_max_samples,
{ "Max Samples", "rtps.resource_limit.max_samples",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_resource_limit_max_instances,
{ "Max Instances", "rtps.resource_limit.max_instances",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_resource_limit_max_samples_per_instances,
{ "Max Samples Per Instance", "rtps.resource_limit.max_samples_per_instance",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_filter_bitmap,
{ "Filter Bitmap", "rtps.filter_bitmap",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_type_checksum,
{ "Checksum", "rtps.type_checksum",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_queue_size,
{ "queueSize", "rtps.queue_size",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_acknack_counter,
{ "Counter", "rtps.acknack.counter",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_durability_service_history_kind,
{ "History Kind", "rtps.durability_service.history_kind",
FT_UINT32, BASE_HEX, VALS(history_qos_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_durability_service_history_depth,
{ "History Depth", "rtps.durability_service.history_depth",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_durability_service_max_samples,
{ "Max Samples", "rtps.durability_service.max_samples",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_durability_service_max_instances,
{ "Max Instances", "rtps.durability_service.max_instances",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_durability_service_max_samples_per_instances,
{ "Max Samples Per Instance", "rtps.durability_service.max_samples_per_instance",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_liveliness_kind,
{ "Kind", "rtps.liveliness.kind",
FT_UINT32, BASE_HEX, VALS(liveliness_qos_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_manager_key,
{ "Key", "rtps.manager_key",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_locator_udp_v4,
{ "Address", "rtps.locator_udp_v4.ip",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_locator_udp_v4_port,
{ "Port", "rtps.locator_udp_v4.port",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_param_ip_address,
{ "Address", "rtps.param.ip_address",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_port,
{ "Port", "rtps.param.port",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_expects_inline_qos,
{ "Inline QoS", "rtps.expects_inline_qos",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0,
NULL, HFILL }
},
{ &hf_rtps_presentation_coherent_access,
{ "Coherent Access", "rtps.presentation.coherent_access",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0,
NULL, HFILL }
},
{ &hf_rtps_presentation_ordered_access,
{ "Ordered Access", "rtps.presentation.ordered_access",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0,
NULL, HFILL }
},
{ &hf_rtps_expects_ack,
{ "expectsAck", "rtps.expects_ack",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0,
NULL, HFILL }
},
{ &hf_rtps_reliability_kind,
{ "Kind", "rtps.reliability_kind",
FT_UINT32, BASE_HEX, VALS(reliability_qos_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_durability,
{ "Durability", "rtps.durability",
FT_UINT32, BASE_HEX, VALS(durability_qos_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_ownership,
{ "Kind", "rtps.ownership",
FT_UINT32, BASE_HEX, VALS(ownership_qos_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_presentation_access_scope,
{ "Access Scope", "rtps.presentation.access_scope",
FT_UINT32, BASE_HEX, VALS(presentation_qos_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_destination_order,
{ "Kind", "rtps.destination_order",
FT_UINT32, BASE_HEX, VALS(destination_order_qos_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_history_kind,
{ "Kind", "rtps.history.kind",
FT_UINT32, BASE_HEX, VALS(history_qos_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_data_status_info,
{ "statusInfo", "rtps.data.status_info",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_serialize_encap_kind,
{ "encapsulation kind", "rtps.param.serialize.encap_kind",
FT_UINT16, BASE_HEX, VALS(encapsulation_id_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_param_serialize_encap_len,
{ "encapsulation options", "rtps.param.serialize.encap_len",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_status_info,
{ "statusInfo", "rtps.param.statusInfo",
FT_UINT32, BASE_HEX, NULL, 0,
"State information of the data object to which the message apply (i.e. lifecycle)",
HFILL }
},
{ &hf_rtps_param_transport_priority,
{ "Value", "rtps.param.transport_priority",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_type_max_size_serialized,
{ "Value", "rtps.param.type_max_size_serialized",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_entity_name,
{ "entity", "rtps.param.entityName",
FT_STRINGZ, BASE_NONE, NULL, 0,
"String representing the name of the entity addressed by the submessage",
HFILL }
},
{ &hf_rtps_disable_positive_ack,
{ "disablePositiveAcks", "rtps.disable_positive_ack",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0,
NULL, HFILL }
},
{ &hf_rtps_participant_guid,
{ "Participant GUID", "rtps.param.participant_guid",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_group_guid,
{ "Group GUID", "rtps.param.group_guid",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_endpoint_guid,
{ "Endpoint GUID", "rtps.param.endpoint_guid",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_host_id,
{ "host_id", "rtps.param.guid.hostId",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_id,
{ "appId", "rtps.param.guid.appId",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_instance_id,
{ "instanceId", "rtps.param.guid.instanceId",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_kind,
{ "instanceId", "rtps.param.guid.appKind",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_entity,
{ "entityId", "rtps.param.guid.entityId",
FT_UINT32, BASE_HEX, VALS(entity_id_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_param_entity_key,
{ "entityKey", "rtps.param.guid.entityKey",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_hf_entity_kind,
{ "entityKind", "rtps.param.guid.entityKind",
FT_UINT8, BASE_HEX, VALS(entity_kind_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_param_counter,
{ "Counter", "rtps.param.guid.counter",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_frag_number,
{ "fragmentStartingNum", "rtps.data_frag.number",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_frag_sample_size,
{ "sampleSize", "rtps.data_frag.sample_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_frag_num_fragments,
{ "fragmentsInSubmessage", "rtps.data_frag.num_fragments",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_frag_size,
{ "fragmentSize", "rtps.data_frag.size",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_nokey_data_frag_number,
{ "fragmentStartingNum", "rtps.nokey_data_frag.number",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_nokey_data_frag_num_fragments,
{ "fragmentsInSubmessage", "rtps.nokey_data_frag.num_fragments",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_nokey_data_frag_size,
{ "fragmentSize", "rtps.nokey_data_frag.size",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_nack_frag_count,
{ "Count", "rtps.nack_frag.count",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_heartbeat_frag_number,
{ "lastFragmentNum", "rtps.heartbeat_frag.number",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_heartbeat_frag_count,
{ "Count", "rtps.heartbeat_frag.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_heartbeat_batch_count,
{ "Count", "rtps.heartbeat_batch.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_serialize_data, {
"serializedData", "rtps.data.serialize_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_batch_timestamp,
{ "Timestamp", "rtps.data_batch.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"Time using the NTP standard format", HFILL }
},
{ &hf_rtps_data_batch_offset_to_last_sample_sn,
{ "offsetToLastSampleSN", "rtps.data_batch.offset_to_last_sample_sn",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_batch_sample_count,
{ "batchSampleCount", "rtps.data_batch.sample_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_batch_offset_sn,
{ "offsetSN", "rtps.data_batch.offset_sn",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_batch_octets_to_sl_encap_id,
{ "octetsToSLEncapsulationId", "rtps.data_batch.octets_to_sl_encap_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_batch_serialized_data_length,
{ "serializedDataLength", "rtps.data_batch.serialized_data_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_batch_octets_to_inline_qos,
{ "octetsToInlineQos", "rtps.data_batch.octets_to_inline_qos",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_fragment_number_base64,
{ "bitmapBase", "rtps.fragment_number.base",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_fragment_number_base,
{ "bitmapBase", "rtps.fragment_number.base",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_fragment_number_num_bits,
{ "numBits", "rtps.fragment_number.num_bits",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_bitmap_num_bits,
{ "numBits", "rtps.bitmap.num_bits",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_partition_num,
{ "Size", "rtps.param.partition_num",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_filter_parameters_num,
{ "Size", "rtps.param.filter_parameters_num",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_partition,
{ "name", "rtps.param.partition",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_filter_expression,
{ "filterExpression", "rtps.param.filter_expression",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_filter_parameters,
{ "filterParameters", "rtps.param.filter_parameters",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_locator_filter_list_num_channels,
{ "numberOfChannels", "rtps.param.locator_filter_list.num_channels",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_locator_filter_list_filter_name,
{ "filterName", "rtps.param.locator_filter_list.filter_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_locator_filter_list_filter_exp,
{ "filterExpression", "rtps.param.locator_filter_list.filter_exp",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_extra_flags,
{ "Extra flags", "rtps.extra_flags",
FT_UINT16, BASE_HEX, NULL, 0xFFFF,
NULL, HFILL }
},
{ &hf_rtps_param_builtin_endpoint_set,
{ "Builtin endpoint set", "rtps.param.builtin_endpoint_set",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFF,
NULL, HFILL }
},
{ &hf_rtps_param_plugin_promiscuity_kind,
{ "promiscuityKind", "rtps.param.plugin_promiscuity_kind",
FT_UINT32, BASE_HEX, VALS(plugin_promiscuity_kind_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_param_service_kind,
{ "serviceKind", "rtps.param.service_kind",
FT_UINT32, BASE_HEX, VALS(service_kind_vals), 0,
NULL, HFILL }
},
{ &hf_rtps_issue_data, {
"serializedData",
"rtps.issueData",
FT_BYTES,
BASE_NONE,
NULL,
0,
"The user data transferred in a ISSUE submessage",
HFILL }
},
};
static gint *ett[] = {
&ett_rtps,
&ett_rtps_default_mapping,
&ett_rtps_proto_version,
&ett_rtps_submessage,
&ett_rtps_parameter_sequence,
&ett_rtps_parameter,
&ett_rtps_flags,
&ett_rtps_entity,
&ett_rtps_generic_guid,
&ett_rtps_rdentity,
&ett_rtps_wrentity,
&ett_rtps_guid_prefix,
&ett_rtps_app_id,
&ett_rtps_locator_udp_v4,
&ett_rtps_locator,
&ett_rtps_locator_list,
&ett_rtps_ntp_time,
&ett_rtps_bitmap,
&ett_rtps_seq_string,
&ett_rtps_seq_ulong,
&ett_rtps_resource_limit,
&ett_rtps_durability_service,
&ett_rtps_liveliness,
&ett_rtps_manager_key,
&ett_rtps_serialized_data,
&ett_rtps_locator_filter_channel,
&ett_rtps_part_message_data,
&ett_rtps_sample_info_list,
&ett_rtps_sample_info,
&ett_rtps_sample_batch_list
};
static ei_register_info ei[] = {
{ &ei_rtps_sm_octets_to_next_header_error, { "rtps.sm.octetsToNextHeader.error", PI_PROTOCOL, PI_WARN, "(Error: bad length)", EXPFILL }},
{ &ei_rtps_locator_port, { "rtps.locator.port.invalid", PI_PROTOCOL, PI_WARN, "Invalid Port", EXPFILL }},
{ &ei_rtps_ip_invalid, { "rtps.ip_invalid", PI_PROTOCOL, PI_WARN, "IPADDRESS_INVALID_STRING", EXPFILL }},
{ &ei_rtps_port_invalid, { "rtps.port_invalid", PI_PROTOCOL, PI_WARN, "PORT_INVALID_STRING", EXPFILL }},
{ &ei_rtps_parameter_value_invalid, { "rtps.parameter_value_too_small", PI_PROTOCOL, PI_WARN, "ERROR: Parameter value too small", EXPFILL }},
{ &ei_rtps_parameter_not_decoded, { "rtps.parameter_not_decoded", PI_PROTOCOL, PI_WARN, "[DEPRECATED] - Parameter not decoded", EXPFILL }},
{ &ei_rtps_sm_octets_to_next_header_not_zero, { "rtps.sm.octetsToNextHeader.not_zero", PI_PROTOCOL, PI_WARN, "Should be ZERO", EXPFILL }},
{ &ei_rtps_extra_bytes, { "rtps.extra_bytes", PI_MALFORMED, PI_ERROR, "Don't know how to decode those extra bytes: %d", EXPFILL }},
{ &ei_rtps_missing_bytes, { "rtps.missing_bytes", PI_MALFORMED, PI_ERROR, "Not enough bytes to decode", EXPFILL }},
{ &ei_rtps_more_samples_available, { "rtps.more_samples_available", PI_PROTOCOL, PI_NOTE, "More samples available. Configure this limit from preferences dialog", EXPFILL }},
};
module_t *rtps_module;
expert_module_t* expert_rtps;
proto_rtps = proto_register_protocol(
"Real-Time Publish-Subscribe Wire Protocol",
"RTPS",
"rtps");
proto_register_field_array(proto_rtps, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_rtps = expert_register_protocol(proto_rtps);
expert_register_field_array(expert_rtps, ei, array_length(ei));
rtps_module = prefs_register_protocol(proto_rtps, NULL);
prefs_register_uint_preference(rtps_module, "max_batch_samples_dissected",
"Max samples dissected for DATA_BATCH",
"Specifies the maximum number of samples dissected in "
"a DATA_BATCH submessage. Increasing this value may affect "
"performances if the trace has a lot of big batched samples.",
10, &rtps_max_batch_samples_dissected);
}
void proto_reg_handoff_rtps(void) {
heur_dissector_add("udp", dissect_rtps, proto_rtps);
heur_dissector_add("tcp", dissect_rtps, proto_rtps);
}
