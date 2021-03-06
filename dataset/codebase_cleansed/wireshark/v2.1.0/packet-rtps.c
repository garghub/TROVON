static void append_status_info(packet_info *pinfo,
guint32 writer_id,
guint32 status_info) {
gchar * writerId = NULL;
gchar * disposeFlag = NULL;
gchar * unregisterFlag = NULL;
wmem_strbuf_t *buffer = wmem_strbuf_new_label(wmem_packet_scope());
switch(writer_id) {
case ENTITYID_PARTICIPANT:
writerId = "P";
break;
case ENTITYID_BUILTIN_TOPIC_WRITER:
writerId = "t";
break;
case ENTITYID_BUILTIN_PUBLICATIONS_WRITER:
writerId = "w";
break;
case ENTITYID_BUILTIN_SUBSCRIPTIONS_WRITER:
writerId = "r";
break;
case ENTITYID_BUILTIN_SDP_PARTICIPANT_WRITER:
writerId = "p";
break;
case ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_WRITER:
writerId = "m";
break;
case ENTITYID_P2P_BUILTIN_PARTICIPANT_STATELESS_WRITER:
writerId = "s";
break;
case ENTITYID_P2P_BUILTIN_PARTICIPANT_VOLATILE_SECURE_WRITER:
writerId = "V";
break;
case ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_SECURE_WRITER:
writerId = "M";
break;
default:
break;
}
switch(status_info) {
case 0: unregisterFlag = "_"; disposeFlag = "_"; break;
case 1: unregisterFlag = "_"; disposeFlag = "D"; break;
case 2: unregisterFlag = "U"; disposeFlag = "_"; break;
case 3: unregisterFlag = "U"; disposeFlag = "D"; break;
default:
break;
}
if (writerId != NULL || unregisterFlag != NULL ||
disposeFlag != NULL ) {
wmem_strbuf_append(buffer, "(");
if (writerId != NULL) {
wmem_strbuf_append(buffer, writerId);
}
if (unregisterFlag != NULL || disposeFlag != NULL) {
wmem_strbuf_append(buffer, "[");
wmem_strbuf_append(buffer, unregisterFlag);
wmem_strbuf_append(buffer, disposeFlag);
wmem_strbuf_append(buffer, "]");
}
wmem_strbuf_append(buffer, ")");
col_append_str(pinfo->cinfo, COL_INFO, wmem_strbuf_get_str(buffer));
}
}
guint16 rtps_util_add_protocol_version(proto_tree *tree,
tvbuff_t *tvb,
gint offset) {
proto_item *ti;
proto_tree *version_tree;
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
tvbuff_t *tvb,
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
void rtps_util_add_locator_t(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, gint offset,
gboolean little_endian, const guint8 *label) {
proto_tree *ti;
proto_tree *locator_tree;
gint32 kind;
guint32 port;
locator_tree = proto_tree_add_subtree(tree, tvb, offset, 24, ett_rtps_locator,
NULL, label);
kind = NEXT_guint32(tvb, offset, little_endian);
port = NEXT_guint32(tvb, offset+4, little_endian);
proto_tree_add_uint(locator_tree, hf_rtps_locator_kind, tvb, offset, 4, kind);
switch (kind) {
case LOCATOR_KIND_UDPV4: {
ti = proto_tree_add_int(locator_tree, hf_rtps_locator_port, tvb, offset+4, 4, port);
proto_tree_add_item(locator_tree, hf_rtps_locator_ipv4, tvb, offset+20, 4,
ENC_BIG_ENDIAN);
if (port == 0)
expert_add_info(pinfo, ti, &ei_rtps_locator_port);
break;
}
case LOCATOR_KIND_TCPV4_LAN:
case LOCATOR_KIND_TCPV4_WAN:
case LOCATOR_KIND_TLSV4_LAN:
case LOCATOR_KIND_TLSV4_WAN: {
ti = proto_tree_add_int(locator_tree, hf_rtps_logical_port, tvb, offset+4, 4, port);
if (port == 0)
expert_add_info(pinfo, ti, &ei_rtps_locator_port);
kind = NEXT_guint16(tvb, offset+16, little_endian);
if (kind == 0xFFFF) {
proto_tree_add_item(locator_tree, hf_rtps_locator_public_address_port,
tvb, offset+18, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(locator_tree, hf_rtps_locator_ipv4, tvb, offset+20,
4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(locator_tree, hf_rtps_locator_ipv6, tvb, offset+8,
16, ENC_NA);
}
break;
}
case LOCATOR_KIND_SHMEM: {
ti = proto_tree_add_int(locator_tree, hf_rtps_locator_port, tvb, offset+4,
4, port);
if (port == 0)
expert_add_info(pinfo, ti, &ei_rtps_locator_port);
break;
}
case LOCATOR_KIND_UDPV6: {
proto_tree_add_item(locator_tree, hf_rtps_locator_ipv6, tvb, offset+8, 16, ENC_NA);
break;
}
default:
break;
}
}
int rtps_util_add_locator_list(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
gint offset, const guint8 *label, gboolean little_endian) {
proto_tree *locator_tree;
guint32 num_locators;
num_locators = NEXT_guint32(tvb, offset, little_endian);
locator_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4,
ett_rtps_locator_udp_v4, NULL, "%s: %d Locators", label, num_locators);
offset += 4;
if (num_locators > 0) {
guint32 i;
char temp_buff[20];
for (i = 0; i < num_locators; ++i) {
g_snprintf(temp_buff, 20, "Locator[%d]", i);
rtps_util_add_locator_t(locator_tree, pinfo, tvb, offset,
little_endian, temp_buff);
offset += 24;
}
}
return offset;
}
void rtps_util_add_ipv4_address_t(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, gint offset,
gboolean little_endian, int hf_item) {
guint32 addr;
proto_item *ti;
addr = NEXT_guint32(tvb, offset, little_endian);
ti = proto_tree_add_ipv4(tree, hf_item, tvb, offset, 4, addr);
if (addr == IPADDRESS_INVALID)
expert_add_info(pinfo, ti, &ei_rtps_ip_invalid);
}
void rtps_util_add_locator_udp_v4(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
gint offset, const guint8 *label, gboolean little_endian) {
proto_item *ti;
proto_tree *locator_tree;
guint32 port;
locator_tree = proto_tree_add_subtree(tree, tvb, offset, 8, ett_rtps_locator_udp_v4, NULL, label);
rtps_util_add_ipv4_address_t(locator_tree, pinfo, tvb, offset,
little_endian, hf_rtps_locator_udp_v4);
port = NEXT_guint32(tvb, offset+4, little_endian);
ti = proto_tree_add_uint(locator_tree, hf_rtps_locator_udp_v4_port, tvb, offset, 4, port);
if (port == PORT_INVALID)
expert_add_info(pinfo, ti, &ei_rtps_port_invalid);
}
static void rtps_util_add_guid_prefix_v1(proto_tree *tree, tvbuff_t *tvb, gint offset,
int hf_prefix, int hf_host_id, int hf_app_id, int hf_app_id_instance_id,
int hf_app_id_app_kind, const guint8 *label) {
guint64 prefix;
guint32 host_id, app_id, instance_id;
guint8 app_kind;
proto_item *ti;
proto_tree *guid_tree, *appid_tree;
const guint8 *safe_label = (label == NULL) ? (const guint8 *)"guidPrefix" : label;
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
int hf_instance_id, int hf_prefix_extra) {
if (tree) {
proto_item *ti;
proto_tree *guid_tree;
ti = proto_tree_add_item(tree, hf_prefix, tvb, offset, 12, ENC_NA);
guid_tree = proto_item_add_subtree(ti, ett_rtps_guid_prefix);
if (hf_prefix_extra != 0) {
ti = proto_tree_add_item(tree, hf_prefix_extra, tvb, offset, 12, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
}
proto_tree_add_item(guid_tree, hf_host_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(guid_tree, hf_app_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(guid_tree, hf_instance_id, tvb, offset+8, 4, ENC_BIG_ENDIAN);
}
}
gboolean rtps_util_add_entity_id(proto_tree *tree, tvbuff_t *tvb, gint offset,
int hf_item, int hf_item_entity_key, int hf_item_entity_kind,
int subtree_entity_id, const char *label, guint32 *entity_id_out) {
guint32 entity_id = tvb_get_ntohl(tvb, offset);
guint32 entity_key = (entity_id >> 8);
guint8 entity_kind = (entity_id & 0xff);
const char *str_predef = try_val_to_str(entity_id, entity_id_vals);
if (entity_id_out != NULL) {
*entity_id_out = entity_id;
}
if (tree != NULL) {
proto_tree *entity_tree;
proto_item *ti;
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
entity_id == ENTITYID_BUILTIN_SDP_PARTICIPANT_READER ||
entity_id == ENTITYID_SEDP_BUILTIN_PUBLICATIONS_SECURE_WRITER ||
entity_id == ENTITYID_SEDP_BUILTIN_PUBLICATIONS_SECURE_READER ||
entity_id == ENTITYID_SEDP_BUILTIN_SUBSCRIPTIONS_SECURE_WRITER ||
entity_id == ENTITYID_SEDP_BUILTIN_SUBSCRIPTIONS_SECURE_READER ||
entity_id == ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_SECURE_WRITER ||
entity_id == ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_SECURE_READER ||
entity_id == ENTITYID_P2P_BUILTIN_PARTICIPANT_STATELESS_WRITER ||
entity_id == ENTITYID_P2P_BUILTIN_PARTICIPANT_STATELESS_READER ||
entity_id == ENTITYID_P2P_BUILTIN_PARTICIPANT_VOLATILE_SECURE_WRITER ||
entity_id == ENTITYID_P2P_BUILTIN_PARTICIPANT_VOLATILE_SECURE_READER ||
entity_id == ENTITYID_RTI_BUILTIN_SERVICE_REQUEST_WRITER ||
entity_id == ENTITYID_RTI_BUILTIN_SERVICE_REQUEST_READER ||
entity_id == ENTITYID_RTI_BUILTIN_LOCATOR_PING_WRITER ||
entity_id == ENTITYID_RTI_BUILTIN_LOCATOR_PING_READER);
}
void rtps_util_add_generic_entity_id(proto_tree *tree, tvbuff_t *tvb, gint offset, const char *label,
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
static void rtps_util_add_generic_guid_v1(proto_tree *tree, tvbuff_t *tvb, gint offset,
int hf_guid, int hf_host_id, int hf_app_id, int hf_app_id_instance_id,
int hf_app_id_app_kind, int hf_entity, int hf_entity_key,
int hf_entity_kind) {
guint64 prefix;
guint32 host_id, app_id, entity_id;
proto_item *ti;
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
static void rtps_util_add_generic_guid_v2(proto_tree *tree, tvbuff_t *tvb, gint offset,
int hf_guid, int hf_host_id, int hf_app_id, int hf_instance_id,
int hf_entity, int hf_entity_key, int hf_entity_kind) {
guint32 host_id, app_id, entity_id, instance_id;
proto_item *ti;
proto_tree *guid_tree, *entity_tree;
host_id = tvb_get_ntohl(tvb, offset);
app_id = tvb_get_ntohl(tvb, offset + 4);
instance_id = tvb_get_ntohl(tvb, offset + 8);
entity_id = tvb_get_ntohl(tvb, offset + 12);
ti = proto_tree_add_bytes_format_value(tree, hf_guid, tvb, offset, 16, NULL, "%08x %08x %08x %08x",
host_id, app_id, instance_id, entity_id);
guid_tree = proto_item_add_subtree(ti, ett_rtps_generic_guid);
proto_tree_add_item(guid_tree, hf_host_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(guid_tree, hf_app_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(guid_tree, hf_instance_id, tvb, offset+8, 4, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(guid_tree, hf_entity, tvb, offset+12, 4, ENC_BIG_ENDIAN);
entity_tree = proto_item_add_subtree(ti, ett_rtps_entity);
proto_tree_add_item(entity_tree, hf_entity_key, tvb, offset+12, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(entity_tree, hf_entity_kind, tvb, offset+15, 1, ENC_BIG_ENDIAN);
}
guint64 rtps_util_add_seq_number(proto_tree *tree,
tvbuff_t *tvb,
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
static void rtps_util_add_transport_info(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
int little_endian,
int transport_index)
{
gint32 classId = NEXT_guint32(tvb, offset, little_endian);
if (tree) {
proto_tree *xport_info_tree;
xport_info_tree = proto_tree_add_subtree_format(tree, tvb, offset, 8, ett_rtps_transport_info, NULL,
"transportInfo %d: %s", transport_index,val_to_str(classId, ndds_transport_class_id_vals, "unknown"));
proto_tree_add_item(xport_info_tree, hf_rtps_transportInfo_classId, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(xport_info_tree, hf_rtps_transportInfo_messageSizeMax, tvb,
offset+4, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
}
void rtps_util_add_ntp_time(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
gboolean little_endian,
int hf_time) {
proto_tree_add_item(tree, hf_time, tvb, offset, 8,
ENC_TIME_NTP_BASE_ZERO|(little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN));
}
static void rtps_util_add_ntp_time_sec_and_fraction(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
gboolean little_endian,
int hf_time _U_) {
guint8 tempBuffer[MAX_NTP_TIME_SIZE];
gdouble absolute;
gint32 sec;
guint32 frac;
if (tree) {
proto_tree *time_tree;
sec = NEXT_guint32(tvb, offset, little_endian);
frac = NEXT_guint32(tvb, offset+4, little_endian);
if ((sec == 0x7fffffff) && (frac == 0xffffffff)) {
g_strlcpy(tempBuffer, "INFINITE", MAX_NTP_TIME_SIZE);
} else if ((sec == 0) && (frac == 0)) {
g_strlcpy(tempBuffer, "0 sec", MAX_NTP_TIME_SIZE);
} else {
absolute = (gdouble)sec + (gdouble)frac / ((gdouble)(0x80000000) * 2.0);
g_snprintf(tempBuffer, MAX_NTP_TIME_SIZE,
"%f sec (%ds + 0x%08x)", absolute, sec, frac);
}
time_tree = proto_tree_add_subtree_format(tree, tvb, offset, 8,
ett_rtps_ntp_time, NULL, "%s: %s", "lease_duration", tempBuffer);
proto_tree_add_item(time_tree, hf_rtps_param_ntpt_sec, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(time_tree, hf_rtps_param_ntpt_fraction, tvb, offset+4, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
}
gint rtps_util_add_string(proto_tree *tree, tvbuff_t *tvb, gint offset,
int hf_item, gboolean little_endian) {
guint8 *retVal = NULL;
guint32 size = NEXT_guint32(tvb, offset, little_endian);
if (size > 0) {
retVal = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+4, size, ENC_ASCII);
}
proto_tree_add_string(tree, hf_item, tvb, offset, size+4,
(size == 0) ? (const guint8 *)"" : retVal);
return offset + 4 + ((size + 3) & 0xfffffffc);
}
void rtps_util_add_port(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
gint offset, gboolean little_endian, int hf_item) {
proto_item *ti;
guint32 port = NEXT_guint32(tvb, offset+4, little_endian);
ti = proto_tree_add_uint(tree, hf_item, tvb, offset, 4, port);
if (port == PORT_INVALID)
expert_add_info(pinfo, ti, &ei_rtps_port_invalid);
}
void rtps_util_add_durability_service_qos(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
gboolean little_endian) {
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb, offset, 28, ett_rtps_durability_service, NULL, "PID_DURABILITY_SERVICE");
rtps_util_add_ntp_time_sec_and_fraction(subtree, tvb, offset, little_endian, hf_rtps_durability_service_cleanup_delay);
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
void rtps_util_add_liveliness_qos(proto_tree *tree, tvbuff_t *tvb, gint offset, gboolean little_endian) {
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_rtps_liveliness, NULL, "PID_LIVELINESS");
proto_tree_add_item(subtree, hf_rtps_liveliness_kind, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
rtps_util_add_ntp_time_sec_and_fraction(subtree, tvb, offset+4, little_endian, hf_rtps_liveliness_lease_duration);
}
static void rtps_util_add_product_version(proto_tree *tree, tvbuff_t *tvb, gint offset) {
proto_tree *subtree;
guint8 major, minor, release, revision;
major = tvb_get_guint8(tvb, offset);
minor = tvb_get_guint8(tvb, offset+1);
release = tvb_get_guint8(tvb, offset+2);
revision = tvb_get_guint8(tvb, offset+3);
if (major < 5 && revision == 0) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 4, ett_rtps_product_version, NULL,
"Product version: %d.%d%c", major, minor, release);
} else if (major < 5 && revision > 0) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 4, ett_rtps_product_version, NULL,
"Product version: %d.%d%c rev%d", major, minor, release, revision);
} else {
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 4, ett_rtps_product_version, NULL,
"Product version: %d.%d.%d.%d", major, minor, release, revision);
}
proto_tree_add_item(subtree, hf_rtps_param_product_version_major,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_rtps_param_product_version_minor,
tvb, offset+1, 1, ENC_NA);
if (major < 5) {
proto_tree_add_item(subtree, hf_rtps_param_product_version_release_as_char,
tvb, offset+2, 1, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_item(subtree, hf_rtps_param_product_version_release,
tvb, offset+2, 1, ENC_NA);
}
proto_tree_add_item(subtree, hf_rtps_param_product_version_revision,
tvb, offset+3, 1, ENC_NA);
}
gint rtps_util_add_seq_string(proto_tree *tree, tvbuff_t *tvb, gint offset,
gboolean little_endian, int param_length, int hf_numstring,
int hf_string, const char *label) {
guint32 i, num_strings, size;
const guint8 *retVal;
proto_tree *string_tree;
num_strings = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_int(tree, hf_numstring, tvb, offset, 4, num_strings);
offset += 4;
string_tree = proto_tree_add_subtree(tree, tvb, offset, param_length-8, ett_rtps_seq_string, NULL, label);
for (i = 0; i < num_strings; ++i) {
size = NEXT_guint32(tvb, offset, little_endian);
if (size > 0) {
retVal = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+4, size, ENC_ASCII);
} else {
retVal = (const guint8 *)"";
}
proto_tree_add_string_format(string_tree, hf_string, tvb, offset, size+4, retVal,
"%s[%d]: %s", label, i, retVal);
offset += (4 + ((size + 3) & 0xfffffffc));
}
return offset;
}
gint rtps_util_add_seq_ulong(proto_tree *tree, tvbuff_t *tvb, gint offset, int hf_item,
gboolean little_endian, int param_length _U_, const char *label) {
guint32 num_elem;
guint32 i;
proto_tree *string_tree;
num_elem = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
string_tree = proto_tree_add_subtree_format(tree, tvb, offset, num_elem*4,
ett_rtps_seq_ulong, NULL, "%s (%d elements)", label, num_elem);
for (i = 0; i < num_elem; ++i) {
proto_tree_add_item(string_tree, hf_item, tvb, offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static const char *rtps_util_typecode_id_to_string(guint32 typecode_id) {
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
case RTI_CDR_TK_BOOLEAN: return "boolean";
case RTI_CDR_TK_CHAR: return "char";
case RTI_CDR_TK_OCTET: return "octet";
case RTI_CDR_TK_LONGLONG: return "longlong";
case RTI_CDR_TK_ULONGLONG: return "unsigned long long";
case RTI_CDR_TK_LONGDOUBLE: return "long double";
case RTI_CDR_TK_WCHAR: return "wchar";
case RTI_CDR_TK_WSTRING: return "wstring";
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
static gint rtps_util_add_typecode(proto_tree *tree, tvbuff_t *tvb, gint offset, gboolean little_endian,
int indent_level, int is_pointer, guint16 bitfield, int is_key, const gint offset_begin,
char *name,
int seq_max_len,
guint32 *arr_dimension,
int ndds_40_hack) {
const gint original_offset = offset;
guint32 tk_id;
guint16 tk_size;
unsigned int i;
char *indent_string;
gint retVal;
char type_name[40];
indent_string = (char *)wmem_alloc(wmem_epan_scope(), (indent_level*2)+1);
memset(indent_string, ' ', (indent_level*2)+1);
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
gint8 *struct_name;
const char *discriminator_name = "<unknown>";
char *discriminator_enum_name = NULL;
guint32 disc_id;
guint16 disc_size;
guint32 disc_offset_begin, num_members, member_name_len;
guint16 member_length;
guint8 *member_name = NULL;
guint32 next_offset, field_offset_begin, member_label_count, discriminator_enum_name_length;
gint32 member_label;
guint j;
LONG_ALIGN(offset);
struct_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
struct_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, struct_name_len, ENC_ASCII);
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
discriminator_enum_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+4, discriminator_enum_name_length, ENC_ASCII);
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
proto_tree_add_string_format(tree, hf_rtps_union, tvb, original_offset, retVal, struct_name, "%sunion %s (%s%s%s) {",
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
guint8 member_is_pointer;
field_offset_begin = offset = next_offset;
SHORT_ALIGN(offset);
member_length = NEXT_guint16(tvb, offset, little_endian);
offset += 2;
next_offset = offset + member_length;
LONG_ALIGN(offset);
member_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
member_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, member_name_len, ENC_ASCII);
offset += member_name_len;
member_is_pointer = tvb_get_guint8(tvb, offset);
offset++;
LONG_ALIGN(offset);
member_label_count = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (j = 0; j < member_label_count; ++j) {
proto_item* case_item;
LONG_ALIGN(offset);
member_label = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
case_item = proto_tree_add_uint_format(tree, hf_rtps_union_case, tvb, field_offset_begin, 1, member_label,
"%s case %d:", indent_string, member_label);
proto_item_set_len(case_item, retVal);
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
gint8 *struct_name;
guint32 struct_name_len, num_members;
guint32 next_offset;
const char *typecode_name;
LONG_ALIGN(offset);
struct_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
struct_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, struct_name_len, ENC_ASCII);
offset += struct_name_len;
if (tk_id == RTI_CDR_TK_ENUM) {
typecode_name = "enum";
} else if (tk_id == RTI_CDR_TK_VALUE_PARAM) {
guint32 baseTypeCodeLength;
typecode_name = "<sparse type>";
SHORT_ALIGN(offset);
NEXT_guint16(tvb, offset, little_endian);
offset += 2;
LONG_ALIGN(offset);
NEXT_guint32(tvb, offset, little_endian);
offset += 4;
baseTypeCodeLength = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
offset += baseTypeCodeLength;
} else {
typecode_name = "struct";
}
if (seq_max_len != -1) {
g_snprintf(type_name, 40, "%s", struct_name);
break;
}
proto_tree_add_string_format(tree, hf_rtps_struct, tvb, original_offset, retVal, struct_name,
"%s%s %s {", indent_string, typecode_name, struct_name);
LONG_ALIGN(offset);
num_members = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
next_offset = offset;
for (i = 0; i < num_members; ++i) {
guint8 *member_name;
guint32 member_name_len;
guint16 member_length;
guint32 field_offset_begin;
field_offset_begin = offset = next_offset;
SHORT_ALIGN(offset);
member_length = NEXT_guint16(tvb, offset, little_endian);
offset += 2;
next_offset = offset + member_length;
LONG_ALIGN(offset);
member_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
member_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, member_name_len, ENC_ASCII);
offset += member_name_len;
if (tk_id == RTI_CDR_TK_ENUM) {
guint32 ordinal_number;
LONG_ALIGN(offset);
ordinal_number = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
proto_tree_add_string_format(tree, hf_rtps_member_name, tvb, field_offset_begin, (offset-field_offset_begin), member_name,
"%s %s = %d;", indent_string, member_name, ordinal_number);
} else {
guint16 member_bitfield;
guint8 member_is_pointer;
guint8 member_is_key;
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
alias_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, alias_name_length, ENC_ASCII);
offset += alias_name_length;
g_strlcpy(type_name, alias_name, 40);
break;
}
case RTI_CDR_TK_VALUE_PARAM:
case RTI_CDR_TK_VALUE: {
guint32 value_name_len;
gint8 *value_name;
const char *type_id_name = "valuetype";
LONG_ALIGN(offset);
value_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
value_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, value_name_len, ENC_ASCII);
offset += value_name_len;
if (tk_id == RTI_CDR_TK_VALUE_PARAM) {
type_id_name = "valueparam";
}
g_snprintf(type_name, 40, "%s '%s'", type_id_name, value_name);
break;
}
}
if (seq_max_len != -1) {
proto_tree_add_string_format(tree, hf_rtps_sequence, tvb, offset_begin, (offset-offset_begin), type_name,
"%ssequence<%s, %d> %s%s;%s", indent_string, type_name, seq_max_len,
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
proto_tree_add_string_format(tree, hf_rtps_array, tvb, offset_begin, (offset-offset_begin), type_name,
"%s%s %s%s;%s", indent_string, type_name, name ? name : "",
wmem_strbuf_get_str(dim_str), is_key ? KEY_COMMENT : "");
return retVal;
}
if (bitfield != 0xffff && name != NULL && is_pointer == 0) {
proto_tree_add_string_format(tree, hf_rtps_bitfield, tvb, offset_begin, (offset-offset_begin), type_name,
"%s%s %s:%d;%s", indent_string, type_name, name ? name : "",
bitfield, is_key ? KEY_COMMENT : "");
return retVal;
}
proto_tree_add_string_format(tree, hf_rtps_datatype, tvb, offset_begin, (offset-offset_begin), type_name,
"%s%s%s%s%s;%s", indent_string, type_name,
name ? " " : "",
is_pointer ? "*" : "",
name ? name : "",
is_key ? KEY_COMMENT : "");
return retVal;
}
static void rtps_util_dissect_parameter_header(tvbuff_t * tvb, gint * offset,
gboolean little_endian, guint32 * member_id, guint32 * member_length) {
*member_id = NEXT_guint16(tvb, *offset, little_endian);
*offset += 2;
*member_length = NEXT_guint16(tvb, *offset, little_endian);
*offset += 2;
if ((*member_id & PID_EXTENDED) == PID_EXTENDED) {
*member_id = tvb_get_guint32(tvb, *offset, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
*offset += 4;
*member_length = tvb_get_guint32(tvb, *offset, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
*offset += 4;
}
}
static gint rtps_util_add_type_id(proto_tree *tree,
tvbuff_t * tvb, gint offset, gboolean little_endian,
gint zero, int hf_base, proto_item * append_info_item) {
proto_item * ti;
guint16 short_number;
guint64 longlong_number;
int hf_type;
short_number = NEXT_guint16(tvb, offset, little_endian);
ti = proto_tree_add_item(tree, hf_rtps_type_object_type_id_disc, tvb, offset,
2, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(ti);
if (hf_base != -1) {
if (short_number <= 13)
hf_type = hf_rtps_type_object_base_primitive_type_id;
else
hf_type = hf_rtps_type_object_base_type;
} else {
if (short_number <= 13)
hf_type = hf_rtps_type_object_primitive_type_id;
else
hf_type = hf_rtps_type_object_type_id;
}
offset += 2;
if (short_number <= 13) {
proto_tree_add_item(tree, hf_type, tvb, offset,
2, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
if (append_info_item) {
proto_item_append_text(append_info_item, "(%s)",
val_to_str(short_number, type_object_kind, "(0x%016x)"));
}
offset += 2;
} else {
ALIGN_ZERO(offset, 8, zero);
longlong_number = tvb_get_guint64(tvb, offset,
little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_type, tvb, offset,
8, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
if (append_info_item) {
proto_item_append_text(append_info_item, "(0x%016" G_GINT64_MODIFIER "x)", longlong_number);
}
offset += 8;
}
return offset;
}
static gint rtps_util_add_type_annotation_usage(proto_tree *tree,
tvbuff_t * tvb, gint offset, gboolean little_endian, gint zero) {
guint32 long_number, i;
guint16 short_number;
offset = rtps_util_add_type_id(tree, tvb, offset, little_endian, zero, -1, NULL);
long_number = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (i = 0; i < long_number; i++) {
proto_tree_add_item(tree, hf_rtps_type_object_member_id, tvb, offset,
4, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset += 4;
short_number = NEXT_guint16(tvb, offset, little_endian);
proto_tree_add_item(tree, hf_rtps_type_object_annotation_value_d, tvb, offset,
2, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset += 2;
switch (short_number) {
case 4:
proto_tree_add_item(tree, hf_rtps_type_object_annotation_value_16, tvb, offset,
2, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset += 2;
break;
default:
break;
}
}
return offset;
}
static gint rtps_util_add_type_library_type(proto_tree *tree,
tvbuff_t * tvb, gint offset, gboolean little_endian) {
proto_tree * annotation_tree;
guint32 member_id = 0, member_length = 0, long_number, i;
gint offset_tmp;
guint16 short_number;
gchar * name = NULL;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset_tmp = offset;
short_number = NEXT_guint16(tvb, offset_tmp, little_endian);
proto_tree_add_bitmask_value(tree, tvb, offset_tmp, hf_rtps_type_object_flags,
ett_rtps_flags, TYPE_FLAG_FLAGS, short_number);
offset_tmp += 2;
offset_tmp = rtps_util_add_type_id(tree, tvb, offset_tmp, little_endian, offset, -1, tree);
rtps_util_add_string(tree, tvb, offset_tmp, hf_rtps_type_object_type_property_name,
little_endian);
long_number = NEXT_guint32(tvb, offset_tmp, little_endian);
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset_tmp+4, long_number, ENC_ASCII);
proto_item_append_text(tree, " %s", name);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset_tmp = offset;
long_number = NEXT_guint32(tvb, offset_tmp, little_endian);
annotation_tree = proto_tree_add_subtree_format(tree, tvb, offset_tmp, member_length,
ett_rtps_type_annotation_usage_list, NULL, "Annotation Usage Member List (%d elements)",
long_number);
offset_tmp += 4;
for (i = 0; i < long_number ; i++) {
offset_tmp = rtps_util_add_type_annotation_usage(annotation_tree, tvb, offset_tmp,
little_endian, offset);
}
offset += member_length;
return offset;
}
static void rtps_util_add_type_element_enumeration(proto_tree *tree,
tvbuff_t * tvb, gint offset , gboolean little_endian) {
proto_tree * enumerated_constant;
guint32 member_id = 0, member_length = 0;
guint32 long_number, i;
gint enum_size, offset_tmp = offset;
offset = rtps_util_add_type_library_type(tree, tvb, offset, little_endian);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
proto_tree_add_item(tree, hf_rtps_type_object_bound, tvb, offset,
4, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset_tmp = offset;
long_number = NEXT_guint32(tvb, offset_tmp, little_endian);
offset_tmp += 4;
for (i = 0; i < long_number; i++) {
gchar * name = NULL;
guint32 size, value;
enum_size = offset_tmp;
size = NEXT_guint32(tvb, offset_tmp + 4, little_endian);
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset_tmp + 8, size, ENC_ASCII);
value = NEXT_guint32(tvb, offset_tmp, little_endian);
enumerated_constant = proto_tree_add_subtree_format(tree, tvb, offset_tmp, 0,
ett_rtps_type_enum_constant, NULL, "%s (%u)", name, value);
proto_tree_add_item(enumerated_constant, hf_rtps_type_object_enum_constant_value, tvb, offset_tmp,
4, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset_tmp += 4;
offset_tmp = rtps_util_add_string(enumerated_constant, tvb, offset_tmp, hf_rtps_type_object_enum_constant_name,
little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
proto_item_set_len(enumerated_constant, offset_tmp - enum_size);
}
offset += member_length;
}
static void rtps_util_add_type_element_sequence(proto_tree *tree,
tvbuff_t * tvb, gint offset , gboolean little_endian) {
guint32 member_id = 0, member_length = 0;
gint zero_alignment;
offset = rtps_util_add_type_library_type(tree, tvb, offset, little_endian);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
zero_alignment = offset;
rtps_util_add_type_id(tree, tvb, offset, little_endian, zero_alignment,
-1 , NULL);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
proto_tree_add_item(tree, hf_rtps_type_object_element_shared, tvb, offset,
1, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
proto_tree_add_item(tree, hf_rtps_type_object_bound, tvb, offset,
4, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset += member_length;
}
static void rtps_util_add_type_element_string(proto_tree *tree,
tvbuff_t * tvb, gint offset , gboolean little_endian) {
guint32 member_id = 0, member_length = 0;
gint zero_alignment;
offset = rtps_util_add_type_library_type(tree, tvb, offset, little_endian);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
zero_alignment = offset;
rtps_util_add_type_id(tree, tvb, offset, little_endian, zero_alignment,
-1 , NULL);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
proto_tree_add_item(tree, hf_rtps_type_object_element_shared, tvb, offset,
1, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
proto_tree_add_item(tree, hf_rtps_type_object_bound, tvb, offset,
4, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset += member_length;
}
static void rtps_util_add_type_element_array(proto_tree *tree,
tvbuff_t * tvb, gint offset , gboolean little_endian) {
proto_tree * bound_tree;
guint32 member_id = 0, member_length = 0;
guint32 long_number, i;
gint zero_alignment, offset_tmp;
offset = rtps_util_add_type_library_type(tree, tvb, offset, little_endian);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
zero_alignment = offset;
rtps_util_add_type_id(tree, tvb, offset, little_endian, zero_alignment,
-1 , NULL);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
proto_tree_add_item(tree, hf_rtps_type_object_element_shared, tvb, offset,
1, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset_tmp = offset;
long_number = NEXT_guint32(tvb, offset_tmp, little_endian);
bound_tree = proto_tree_add_subtree_format(tree, tvb, offset_tmp, member_length,
ett_rtps_type_bound_list, NULL, "Bounds (%d elements)",
long_number);
offset_tmp += 4;
for (i = 0; i < long_number ; i++) {
proto_tree_add_item(bound_tree, hf_rtps_type_object_bound, tvb, offset_tmp,
4, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
offset_tmp += 4;
}
}
static void rtps_util_add_type_element_alias(proto_tree *tree,
tvbuff_t * tvb, gint offset , gboolean little_endian) {
guint32 member_id = 0, member_length = 0;
offset = rtps_util_add_type_library_type(tree, tvb, offset, little_endian);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset = rtps_util_add_type_id(tree, tvb, offset, little_endian, offset, hf_rtps_type_object_base_type, NULL);
}
static gint rtps_util_add_type_member(proto_tree *tree,
tvbuff_t * tvb, gint offset, gboolean little_endian) {
proto_tree * member_property, *annotation_tree;
guint32 member_id = 0, member_length = 0;
guint32 long_number, i;
guint16 short_number;
gint offset_tmp;
gchar * name = NULL;
member_property = proto_tree_add_subtree(tree, tvb, offset, 0,
ett_rtps_type_element, NULL, "Member Property");
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset_tmp = offset;
short_number = NEXT_guint16(tvb, offset_tmp, little_endian);
proto_tree_add_bitmask_value(tree, tvb, offset_tmp, hf_rtps_type_object_flags,
ett_rtps_flags, MEMBER_FLAGS, short_number);
offset_tmp += 2;
ALIGN_ZERO(offset_tmp, 4, offset);
proto_tree_add_item(member_property, hf_rtps_type_object_member_id, tvb, offset_tmp,
4, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
member_id = NEXT_guint32(tvb, offset_tmp, little_endian);
offset_tmp += 4;
offset_tmp = rtps_util_add_type_id(member_property, tvb, offset_tmp, little_endian,
offset, -1, tree);
rtps_util_add_string(member_property, tvb, offset_tmp, hf_rtps_type_object_name,
little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
long_number = NEXT_guint32(tvb, offset_tmp, little_endian);
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset_tmp+4, long_number, ENC_ASCII);
proto_item_append_text(tree, " %s (ID: %d)", name, member_id);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset_tmp = offset;
long_number = NEXT_guint32(tvb, offset_tmp, little_endian);
annotation_tree = proto_tree_add_subtree_format(tree, tvb, offset_tmp, member_length,
ett_rtps_type_annotation_usage_list, NULL, "Annotation Usage Member List (%d elements)",
long_number);
offset_tmp += 4;
for (i = 0; i < long_number ; i++) {
offset_tmp = rtps_util_add_type_annotation_usage(annotation_tree, tvb, offset_tmp,
little_endian, offset);
}
offset += member_length;
offset += 4;
return offset;
}
static void rtps_util_add_type_element_struct(proto_tree *tree,
tvbuff_t * tvb, gint offset , gboolean little_endian) {
proto_tree * member;
guint32 member_id = 0, member_length = 0;
guint32 long_number, i;
gint offset_tmp, member_size;
offset = rtps_util_add_type_library_type(tree, tvb, offset, little_endian);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset = rtps_util_add_type_id(tree, tvb, offset, little_endian, offset, hf_rtps_type_object_base_type, NULL);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset_tmp = offset;
long_number = NEXT_guint32(tvb, offset_tmp, little_endian);
offset_tmp += 4;
for (i = 0; i < long_number; i++) {
member_size = offset_tmp;
member = proto_tree_add_subtree(tree, tvb, offset_tmp, 0,
ett_rtps_type_enum_constant, NULL, "");
offset_tmp = rtps_util_add_type_member(member, tvb, offset_tmp, little_endian);
proto_item_set_len(member, offset_tmp - member_size);
}
offset += member_length;
}
static void rtps_util_add_type_element_module(proto_tree *tree, packet_info * pinfo,
tvbuff_t * tvb, gint offset , gboolean little_endian) {
guint32 long_number;
gchar * name = NULL;
long_number = tvb_get_guint32(tvb, offset, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+4, long_number, ENC_ASCII);
proto_item_set_text(tree, "module %s", name);
offset = rtps_util_add_string(tree, tvb, offset, hf_rtps_type_object_element_module_name, little_endian);
rtps_util_add_type_library(tree, pinfo, tvb, offset, little_endian, -1);
}
static gint rtps_util_add_type_library_element(proto_tree *tree, packet_info * pinfo,
tvbuff_t * tvb, gint offset , gboolean little_endian) {
proto_tree * element_tree;
guint32 long_number;
guint32 member_id = 0, member_length = 0;
gint initial_offset = offset;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
long_number = NEXT_guint32(tvb, offset, little_endian);
element_tree = proto_tree_add_subtree(tree, tvb, offset, 0,
ett_rtps_type_element, NULL, "");
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
proto_item_set_len(element_tree, member_length + offset - initial_offset);
switch (long_number) {
case 14:
rtps_util_add_type_element_enumeration(element_tree, tvb, offset, little_endian);
break;
case 16:
rtps_util_add_type_element_alias(element_tree, tvb, offset, little_endian);
break;
case 17:
rtps_util_add_type_element_array(element_tree, tvb, offset, little_endian);
break;
case 18:
rtps_util_add_type_element_sequence(element_tree, tvb, offset, little_endian);
break;
case 19:
rtps_util_add_type_element_string(element_tree, tvb, offset, little_endian);
break;
case 22:
rtps_util_add_type_element_struct(element_tree, tvb, offset, little_endian);
break;
case 24:
rtps_util_add_type_element_module(element_tree, pinfo, tvb, offset, little_endian);
break;
default:
proto_tree_add_item(element_tree, hf_rtps_type_object_element_raw, tvb, offset,
member_length, little_endian ? ENC_LITTLE_ENDIAN: ENC_BIG_ENDIAN);
break;
}
offset += member_length;
LONG_ALIGN(offset);
long_number = NEXT_guint32(tvb, offset, little_endian);
if ((long_number & PID_LIST_END) != PID_LIST_END) {
expert_add_info_format(pinfo, element_tree, &ei_rtps_parameter_value_invalid,
"Now it should be PID_LIST_END and it is not"); \
}
offset += 4;
proto_item_set_len(element_tree, offset - initial_offset);
return offset;
}
static void rtps_util_add_type_library(proto_tree *tree, packet_info * pinfo,
tvbuff_t * tvb, gint offset, gboolean little_endian, guint32 size) {
proto_tree * library_tree;
guint32 long_number, i;
long_number = NEXT_guint32(tvb, offset, little_endian);
library_tree = proto_tree_add_subtree_format(tree, tvb, offset, size,
ett_rtps_type_library, NULL, "Type Library (%d elements)", long_number);
offset += 4;
for (i = 0; i < long_number; i++) {
offset = rtps_util_add_type_library_element(library_tree, pinfo, tvb,
offset, little_endian);
}
}
static void rtps_util_add_typeobject(proto_tree *tree, packet_info * pinfo,
tvbuff_t * tvb, gint offset, gboolean little_endian, guint32 size) {
proto_tree * typeobject_tree;
gint offset_tmp = 0;
guint32 member_id = 0, member_length = 0;
guint32 long_number;
typeobject_tree = proto_tree_add_subtree(tree, tvb, offset, size,
ett_rtps_type_object, NULL, "Type Object");
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset_tmp = offset;
rtps_util_add_type_library(typeobject_tree, pinfo, tvb, offset_tmp, little_endian, member_length);
offset += member_length;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &member_id, &member_length);
offset_tmp = offset;
rtps_util_add_type_id(typeobject_tree, tvb, offset_tmp, little_endian, offset, -1, NULL);
offset = offset + member_length;
long_number = NEXT_guint32(tvb, offset, little_endian);
if ((long_number & PID_LIST_END) != PID_LIST_END) {
expert_add_info_format(pinfo, typeobject_tree, &ei_rtps_parameter_value_invalid,
"This should be PID_LIST_END and it is not"); \
}
}
gint rtps_util_add_seq_octets(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
gint offset, gboolean little_endian, int param_length, int hf_id) {
guint32 seq_length;
proto_item *ti;
seq_length = NEXT_guint32(tvb, offset, little_endian);
ti = proto_tree_add_uint_format_value(tree, hf_rtps_sequence_size, tvb, offset, 4, seq_length, "%d octets", seq_length);
offset += 4;
if (param_length < 4 + (int)seq_length) {
expert_add_info_format(pinfo, ti, &ei_rtps_parameter_value_invalid, "ERROR: Parameter value too small");
return offset + seq_length;;
}
proto_tree_add_item(tree, hf_id, tvb, offset, seq_length, ENC_NA);
return offset + seq_length;
}
static gint rtps_util_add_data_holder(proto_tree *tree, tvbuff_t * tvb, packet_info * pinfo,
gint offset, gboolean little_endian, gint seq_index, gint alignment_zero) {
proto_tree * data_holder_tree, * properties_tree, * property_tree, * seq_values_tree;
proto_item * ti, * data_holder;
guint32 seq_size, param_id, param_length, i;
gint offset_tmp, data_holder_begin;
data_holder_tree = proto_tree_add_subtree_format(tree, tvb, offset,
-1, ett_rtps_data_holder, &data_holder, "Data Holder [%d]", seq_index);
data_holder_begin = offset;
offset = rtps_util_add_string(data_holder_tree, tvb, offset,
hf_rtps_pgm_data_holder_class_id, little_endian);
LONG_ALIGN_ZERO(offset, alignment_zero);
properties_tree = proto_tree_add_subtree_format(data_holder_tree, tvb, offset,
-1, ett_rtps_data_holder_properties, &ti, "String Properties");
offset_tmp = offset;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
proto_item_set_len(ti, offset - offset_tmp + param_length);
if (param_length > 0 ) {
gint32 local_offset;
local_offset = offset;
seq_size = NEXT_guint32(tvb, local_offset, little_endian);
local_offset += 4;
for(i = 0; i < seq_size; i++) {
property_tree = proto_tree_add_subtree_format(properties_tree, tvb, local_offset,
-1, ett_rtps_property_tree, &ti, "Property [%d]", i);
local_offset = rtps_util_add_string(property_tree, tvb, local_offset,
hf_rtps_property_name, little_endian);
local_offset = rtps_util_add_string(property_tree, tvb, local_offset,
hf_rtps_property_value, little_endian);
}
}
offset += param_length;
offset_tmp = offset;
properties_tree = proto_tree_add_subtree_format(data_holder_tree, tvb, offset,
-1, ett_rtps_data_holder_properties, &ti, "Binary Properties");
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
proto_item_set_len(ti, offset - offset_tmp + param_length);
if (param_length > 0 ) {
gint32 local_offset;
local_offset = offset;
seq_size = NEXT_guint32(tvb, local_offset, little_endian);
local_offset += 4;
for(i = 0; i < seq_size; i++) {
LONG_ALIGN(local_offset);
property_tree = proto_tree_add_subtree_format(properties_tree, tvb, local_offset,
-1, ett_rtps_property_tree, &ti, "Property [%d]", i);
local_offset = rtps_util_add_string(property_tree, tvb, local_offset,
hf_rtps_property_name, little_endian);
local_offset = rtps_util_add_seq_octets(property_tree, pinfo, tvb, local_offset,
little_endian, param_length, hf_rtps_param_user_data);
}
}
offset += param_length;
offset_tmp = offset;
seq_values_tree = proto_tree_add_subtree_format(data_holder_tree, tvb, offset,
-1, ett_rtps_seq_string, &ti, "String Values");
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
proto_item_set_len(ti, offset - offset_tmp + param_length);
if (param_length > 0 ) {
rtps_util_add_seq_string(seq_values_tree, tvb, offset, little_endian, param_length,
hf_rtps_pgm_data_holder_stringseq_size, hf_rtps_pgm_data_holder_stringseq_name,
"Sequence");
}
offset += param_length;
offset_tmp = offset;
seq_values_tree = proto_tree_add_subtree_format(data_holder_tree, tvb, offset,
-1, ett_rtps_seq_string, &ti, "Binary value 1");
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
proto_item_set_len(ti, offset - offset_tmp + param_length);
if (param_length > 0 ) {
rtps_util_add_seq_octets(seq_values_tree, pinfo, tvb, offset, little_endian, param_length,
hf_rtps_param_user_data);
}
offset += param_length;
offset_tmp = offset;
seq_values_tree = proto_tree_add_subtree_format(data_holder_tree, tvb, offset,
-1, ett_rtps_seq_string, &ti, "Binary value 2");
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
proto_item_set_len(ti, offset - offset_tmp + param_length);
if (param_length > 0 ) {
rtps_util_add_seq_octets(seq_values_tree, pinfo, tvb, offset, little_endian, param_length,
hf_rtps_param_user_data);
}
offset += param_length;
offset_tmp = offset;
properties_tree = proto_tree_add_subtree_format(data_holder_tree, tvb, offset,
-1, ett_rtps_seq_string, &ti, "Long Long Sequence");
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
proto_item_set_len(ti, offset - offset_tmp + param_length);
if (param_length > 0 ) {
seq_size = NEXT_guint32(tvb, offset, little_endian);
for (i = 0; i < seq_size; i++) {
proto_tree_add_item(properties_tree, hf_rtps_pgm_data_holder_long_long, tvb,
offset + 4 + 8 * i, 8, little_endian);
}
}
offset += param_length;
proto_item_set_len(data_holder, offset - data_holder_begin);
return offset;
}
static gint rtps_util_add_data_holder_seq(proto_tree *tree, tvbuff_t * tvb,
packet_info * pinfo, gint offset, gboolean little_endian, gint alignment_zero) {
proto_tree * data_holder_seq_tree;
proto_item * ti;
guint32 seq_length;
guint32 i;
data_holder_seq_tree = proto_tree_add_subtree(tree, tvb, offset,
-1, ett_rtps_data_holder_seq, &ti, "Data Holder Sequence");
seq_length = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for(i = 0; i < seq_length; i++) {
offset = rtps_util_add_data_holder(data_holder_seq_tree, tvb, pinfo, offset,
little_endian, i, alignment_zero);
}
return offset;
}
static int rtps_util_add_bitmap(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
gboolean little_endian,
const char *label) {
gint32 num_bits;
guint32 data;
wmem_strbuf_t *temp_buff = wmem_strbuf_new_label(wmem_packet_scope());
wmem_strbuf_t *analysis_buff = wmem_strbuf_new_label(wmem_packet_scope());
gint i, j, idx;
gchar *last_one;
proto_item *ti = NULL, *ti_tree = NULL;
proto_tree *bitmap_tree;
const gint original_offset = offset;
guint32 datamask;
guint64 first_seq_number;
gboolean first_nack = TRUE;
bitmap_tree = proto_tree_add_subtree(tree, tvb, original_offset, offset-original_offset,
ett_rtps_bitmap, &ti_tree, label);
first_seq_number = rtps_util_add_seq_number(bitmap_tree, tvb, offset, little_endian, "bitmapBase");
offset += 8;
num_bits = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_uint(bitmap_tree, hf_rtps_bitmap_num_bits, tvb, offset, 4, num_bits);
offset += 4;
if (first_seq_number == 0) {
ti = proto_tree_add_uint_format(bitmap_tree, hf_rtps_acknack_analysis, tvb, 0, 0,
1, "Acknack Analysis: Preemptive ACKNACK");
PROTO_ITEM_SET_GENERATED(ti);
}
if (first_seq_number > 0 && num_bits == 0) {
ti = proto_tree_add_uint_format(bitmap_tree, hf_rtps_acknack_analysis, tvb, 0, 0,
2, "Acknack Analysis: Expecting sample %" G_GINT64_MODIFIER "u", first_seq_number);
PROTO_ITEM_SET_GENERATED(ti);
}
if (num_bits > 0) {
ti = proto_tree_add_uint_format(bitmap_tree, hf_rtps_acknack_analysis, tvb, 0, 0,
3, "Acknack Analysis: Lost samples");
PROTO_ITEM_SET_GENERATED(ti);
}
idx = 0;
for (i = 0; i < num_bits; i += 32) {
data = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (j = 0; j < 32; ++j) {
datamask = (1U << (31-j));
wmem_strbuf_append_c(temp_buff, ((data & datamask) == datamask) ? '1':'0');
if ((data & datamask) == datamask) {
proto_item_append_text(ti,
first_nack ? " %" G_GINT64_MODIFIER "u" : ", %" G_GINT64_MODIFIER "u",
first_seq_number + idx);
first_nack = FALSE;
}
++idx;
if ((idx >= num_bits) || (wmem_strbuf_get_len(temp_buff) >= (ITEM_LABEL_LENGTH - 1))) {
break;
}
}
}
last_one = strrchr(wmem_strbuf_get_str(temp_buff), '1');
if (last_one) {
wmem_strbuf_truncate(temp_buff, (gsize) (last_one - wmem_strbuf_get_str(temp_buff)) + 1);
}
if (wmem_strbuf_get_len(temp_buff) > 0) {
proto_tree_add_bytes_format_value(bitmap_tree, hf_rtps_bitmap, tvb,
original_offset + 12, offset - original_offset - 12,
NULL, "%s", wmem_strbuf_get_str(temp_buff));
}
proto_item_set_len(ti_tree, offset-original_offset);
if (num_bits > 0) {
proto_item_append_text(ti, "%s in range [%" G_GINT64_MODIFIER "u,%" G_GINT64_MODIFIER "u]",
wmem_strbuf_get_str(analysis_buff), first_seq_number, first_seq_number + num_bits - 1);
}
return offset;
}
static int rtps_util_add_fragment_number_set(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
gint offset, gboolean little_endian, const char *label, gint section_size) {
guint64 base;
gint32 num_bits;
guint32 data;
wmem_strbuf_t *temp_buff = wmem_strbuf_new_label(wmem_packet_scope());
gchar *last_one;
int i, j, idx;
proto_item *ti;
proto_tree *bitmap_tree;
const gint original_offset = offset;
guint32 datamask;
gint expected_size;
gint base_size;
bitmap_tree = proto_tree_add_subtree(tree, tvb, original_offset, offset-original_offset, ett_rtps_bitmap, &ti, label);
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
datamask = (1U << (31-j));
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
if (base_size == 8) {
proto_tree_add_uint64(bitmap_tree, hf_rtps_fragment_number_base64, tvb, original_offset, 8,
base);
} else {
proto_tree_add_item(bitmap_tree, hf_rtps_fragment_number_base, tvb, original_offset, base_size,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
proto_tree_add_uint(bitmap_tree, hf_rtps_fragment_number_num_bits, tvb, original_offset + base_size, 4, num_bits);
if (wmem_strbuf_get_len(temp_buff) > 0) {
proto_tree_add_bytes_format_value(bitmap_tree, hf_rtps_bitmap, tvb, original_offset + base_size + 4, offset - original_offset - base_size - 4,
NULL, "%s", wmem_strbuf_get_str(temp_buff));
}
proto_item_set_len(ti, offset-original_offset);
return offset;
}
static void rtps_util_store_type_mapping(tvbuff_t *tvb, gint offset,
type_mapping * type_mapping_object, const gchar * value,
gint topic_info_add_id) {
if (enable_topic_info && type_mapping_object) {
switch (topic_info_add_id) {
case TOPIC_INFO_ADD_GUID: {
type_mapping_object->guid.host_id = tvb_get_ntohl(tvb, offset);
type_mapping_object->guid.app_id = tvb_get_ntohl(tvb, offset+4);
type_mapping_object->guid.instance_id = tvb_get_ntohl(tvb, offset+8);
type_mapping_object->guid.entity_id = tvb_get_ntohl(tvb, offset+12);
type_mapping_object->fields_visited =
type_mapping_object->fields_visited | TOPIC_INFO_ADD_GUID;
break;
}
case TOPIC_INFO_ADD_TOPIC_NAME: {
g_strlcpy(type_mapping_object->topic_name, value, MAX_TOPIC_AND_TYPE_LENGTH);
type_mapping_object->fields_visited =
type_mapping_object->fields_visited | TOPIC_INFO_ADD_TOPIC_NAME;
break;
}
case TOPIC_INFO_ADD_TYPE_NAME: {
g_strlcpy(type_mapping_object->type_name, value, MAX_TOPIC_AND_TYPE_LENGTH);
type_mapping_object->fields_visited =
type_mapping_object->fields_visited | TOPIC_INFO_ADD_TYPE_NAME;
break;
}
default:
break;
}
if ((type_mapping_object->fields_visited & TOPIC_INFO_ALL_SET) == TOPIC_INFO_ALL_SET &&
!wmem_map_lookup(registry, &(type_mapping_object->guid))) {
if (((type_mapping_object->guid.entity_id & 0x02) == 0x02)){
wmem_map_insert(registry, &(type_mapping_object->guid), type_mapping_object);
}
}
}
}
static guint hash_by_guid(gconstpointer key) {
const endpoint_guid * guid = (const endpoint_guid *) key;
return g_int_hash(&(guid->app_id));
}
static gboolean compare_by_guid(gconstpointer a, gconstpointer b) {
const endpoint_guid * guid_a = (const endpoint_guid *) a;
const endpoint_guid * guid_b = (const endpoint_guid *) b;
return memcmp(guid_a, guid_b, sizeof(endpoint_guid)) == 0;
}
static type_mapping * rtps_util_get_topic_info(endpoint_guid * guid) {
type_mapping * result = NULL;
if (guid)
result = (type_mapping *)wmem_map_lookup(registry, guid);
return result;
}
static void rtps_util_format_typename(gchar * type_name, gchar ** output) {
gchar ** tokens;
gchar * result_caps;
tokens = g_strsplit(type_name, "::", 255);
result_caps = g_strjoinv("_", tokens);
*output = g_ascii_strdown(result_caps, -1);
g_strfreev(tokens);
g_free(result_caps);
}
static gboolean rtps_util_show_topic_info(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, gint offset, endpoint_guid * guid,
rtps_dissector_data * data) {
if (enable_topic_info) {
type_mapping * type_mapping_object = rtps_util_get_topic_info(guid);
if (type_mapping_object != NULL) {
proto_tree * topic_info_tree;
proto_item * ti;
gchar * dissector_name = NULL;
tvbuff_t *next_tvb;
if (data && !(data->info_displayed)) {
topic_info_tree = proto_tree_add_subtree(tree, tvb, offset, 0,
ett_rtps_topic_info, NULL, "[Topic Information (from Discovery)]");
ti = proto_tree_add_string(topic_info_tree, hf_rtps_param_topic_name, tvb, offset, 0,
type_mapping_object->topic_name);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_string(topic_info_tree, hf_rtps_param_type_name, tvb, offset, 0,
type_mapping_object->type_name);
PROTO_ITEM_SET_GENERATED(ti);
col_append_sep_str(pinfo->cinfo, COL_INFO, " -> ", type_mapping_object->topic_name);
data->info_displayed = TRUE;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
rtps_util_format_typename(type_mapping_object->type_name, &dissector_name);
if (dissector_try_string(rtps_type_name_table, dissector_name,
next_tvb, pinfo, tree, data)) {
g_free(dissector_name);
return TRUE;
} else {
g_free(dissector_name);
return FALSE;
}
}
}
return FALSE;
}
static gint rtps_util_add_rti_topic_query_service_request(proto_tree * tree,
tvbuff_t * tvb, gint offset, gboolean little_endian) {
proto_tree * topic_query_tree, * topic_query_selection_tree, *topic_query_filter_params_tree;
proto_item * ti;
guint16 encapsulation_id, encapsulation_opt;
guint32 param_id, param_length, param_length_2, num_filter_params;
gint alignment_zero, tmp_offset;
guint32 i;
topic_query_tree = proto_tree_add_subtree(tree, tvb, offset,
0 , ett_rtps_topic_query_tree, &ti, "Topic Query Data");
encapsulation_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(topic_query_tree, hf_rtps_encapsulation_id,
tvb, offset, 2, encapsulation_id);
offset += 2;
little_endian = (encapsulation_id == ENCAPSULATION_CDR_LE || encapsulation_id == ENCAPSULATION_PL_CDR_LE);
encapsulation_opt = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(topic_query_tree, hf_rtps_encapsulation_options, tvb,
offset, 2, encapsulation_opt);
offset += 2;
alignment_zero = offset;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
tmp_offset = offset;
{
topic_query_selection_tree = proto_tree_add_subtree(topic_query_tree, tvb, tmp_offset,
0 , ett_rtps_topic_query_selection_tree, &ti, "Topic Query Selection");
SHORT_ALIGN_ZERO(tmp_offset,alignment_zero);
rtps_util_dissect_parameter_header(tvb, &tmp_offset, little_endian, &param_id, &param_length_2);
if (param_id == 0) {
LONG_ALIGN_ZERO(tmp_offset, alignment_zero);
rtps_util_add_string(topic_query_selection_tree, tvb, tmp_offset,
hf_rtps_topic_query_selection_filter_class_name, little_endian);
}
tmp_offset += param_length_2;
SHORT_ALIGN_ZERO(tmp_offset,alignment_zero);
rtps_util_dissect_parameter_header(tvb, &tmp_offset, little_endian, &param_id, &param_length_2);
LONG_ALIGN_ZERO(tmp_offset, alignment_zero);
tmp_offset = rtps_util_add_string(topic_query_selection_tree, tvb, tmp_offset,
hf_rtps_topic_query_selection_filter_expression, little_endian);
SHORT_ALIGN_ZERO(tmp_offset,alignment_zero);
rtps_util_dissect_parameter_header(tvb, &tmp_offset, little_endian, &param_id, &param_length_2);
num_filter_params = NEXT_guint32(tvb, tmp_offset, little_endian);
proto_tree_add_item(topic_query_selection_tree, hf_rtps_topic_query_selection_num_parameters,
tvb, tmp_offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
topic_query_filter_params_tree = proto_tree_add_subtree_format(topic_query_selection_tree, tvb,
tmp_offset + 4, 0 , ett_rtps_topic_query_filter_params_tree, &ti,
"Filter Parameters (size = %u)", num_filter_params);
tmp_offset += 4;
for (i = 0; i < num_filter_params; ++i) {
guint32 string_size;
gchar * retVal;
LONG_ALIGN_ZERO(tmp_offset, alignment_zero);
string_size = NEXT_guint32(tvb, tmp_offset, little_endian);
retVal = tvb_get_string_enc(wmem_packet_scope(), tvb, tmp_offset+4, string_size, ENC_ASCII);
proto_tree_add_string_format(topic_query_filter_params_tree,
hf_rtps_topic_query_selection_filter_parameter, tvb,
tmp_offset, string_size+4, retVal, "%s[%d]: %s", "Filter Parameter", i, retVal);
tmp_offset += (4 + string_size);
}
}
offset += param_length;
SHORT_ALIGN_ZERO(offset,alignment_zero);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
rtps_util_add_seq_number(topic_query_tree, tvb, offset, little_endian, "Sync Sequence Number");
offset += param_length;
SHORT_ALIGN_ZERO(offset,alignment_zero);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
LONG_ALIGN_ZERO(offset, alignment_zero);
rtps_util_add_string(topic_query_tree, tvb, offset,
hf_rtps_topic_query_topic_name, little_endian);
offset += param_length;
SHORT_ALIGN_ZERO(offset,alignment_zero);
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
rtps_util_add_generic_guid_v2(topic_query_tree, tvb, offset,
hf_rtps_topic_query_original_related_reader_guid,
hf_rtps_param_host_id, hf_rtps_param_app_id, hf_rtps_param_instance_id,
hf_rtps_param_entity, hf_rtps_param_entity_key, hf_rtps_param_hf_entity_kind);
offset += param_length;
return offset;
}
static gint rtps_util_add_rti_locator_reachability_service_request(proto_tree * tree,
packet_info *pinfo, tvbuff_t * tvb, gint offset, gboolean little_endian) {
proto_tree * locator_reachability_tree, * locator_seq_tree;
proto_item * ti;
guint16 encapsulation_id, encapsulation_opt;
guint32 param_id, param_length, seq_length, i;
locator_reachability_tree = proto_tree_add_subtree(tree, tvb, offset,
0 , ett_rtps_locator_reachability_tree, &ti, "Locator Reachability Data");
encapsulation_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(locator_reachability_tree, hf_rtps_encapsulation_id,
tvb, offset, 2, encapsulation_id);
offset += 2;
little_endian = (encapsulation_id == ENCAPSULATION_CDR_LE || encapsulation_id == ENCAPSULATION_PL_CDR_LE);
encapsulation_opt = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(locator_reachability_tree, hf_rtps_encapsulation_options, tvb,
offset, 2, encapsulation_opt);
offset += 2;
rtps_util_dissect_parameter_header(tvb, &offset, little_endian, &param_id, &param_length);
seq_length = NEXT_guint32(tvb, offset, little_endian);
locator_seq_tree = proto_tree_add_subtree_format(locator_reachability_tree, tvb, offset,
param_length, ett_rtps_locator_list_tree, &ti, "Locator List [Size = %u]", seq_length);
offset += 4;
for(i = 0; i < seq_length; i++) {
rtps_util_add_locator_t(locator_seq_tree, pinfo, tvb, offset, little_endian, "Locator");
offset += 24;
}
return offset;
}
static gint rtps_util_add_rti_service_request(proto_tree * tree, packet_info *pinfo, tvbuff_t * tvb,
gint offset, gboolean little_endian, guint32 service_id) {
switch (service_id) {
case RTI_SERVICE_REQUEST_ID_TOPIC_QUERY:
offset = rtps_util_add_rti_topic_query_service_request(tree, tvb, offset + 4,
little_endian);
break;
case RTI_SERVICE_REQUEST_ID_LOCATOR_REACHABILITY:
offset = rtps_util_add_rti_locator_reachability_service_request(tree, pinfo, tvb, offset + 4,
little_endian);
break;
case RTI_SERVICE_REQUEST_ID_UNKNOWN: {
guint32 seq_length;
seq_length = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_item(tree, hf_rtps_srm_request_body,
tvb, offset + 4, seq_length, ENC_NA);
offset = offset + seq_length + 4;
break;
}
}
return offset;
}
static gboolean dissect_parameter_sequence_rti(proto_tree *rtps_parameter_tree, packet_info *pinfo, tvbuff_t *tvb,
proto_item *parameter_item, proto_item * param_len_item, gint offset,
gboolean little_endian, int param_length, guint16 parameter, gboolean is_inline_qos) {
switch(parameter) {
case PID_ENABLE_AUTHENTICATION:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_enable_authentication, tvb,
offset, 4, ENC_NA);
break;
case PID_ENABLE_ENCRYPTION:
ENSURE_LENGTH(1);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_enable_encryption, tvb,
offset, 1, ENC_NA);
break;
case PID_VENDOR_BUILTIN_ENDPOINT_SET: {
guint32 flags;
ENSURE_LENGTH(4);
flags = tvb_get_guint32(tvb, offset, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_bitmask_value(rtps_parameter_tree, tvb, offset,
hf_rtps_param_vendor_builtin_endpoint_set_flags, ett_rtps_flags,
VENDOR_BUILTIN_ENDPOINT_FLAGS, flags);
break;
}
case PID_TOPIC_QUERY_PUBLICATION: {
ENSURE_LENGTH(8);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_topic_query_publication_enable,
tvb, offset, 1, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_topic_query_publication_sessions,
tvb, offset+4, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
}
case PID_ENDPOINT_PROPERTY_CHANGE_EPOCH: {
ENSURE_LENGTH(8);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_endpoint_property_change_epoch,
tvb, offset, 8, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
}
case PID_TOPIC_QUERY_GUID:
if (is_inline_qos) {
ENSURE_LENGTH(16);
rtps_util_add_generic_guid_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_endpoint_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
}
break;
case PID_REACHABILITY_LEASE_DURATION:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time_sec_and_fraction(rtps_parameter_tree, tvb, offset, little_endian,
hf_rtps_participant_lease_duration);
break;
case PID_DEFAULT_MULTICAST_LOCATOR: {
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree, pinfo, tvb, offset, little_endian, "locator");
break;
}
case PID_TRANSPORT_INFO_LIST: {
if (is_inline_qos) {
ENSURE_LENGTH(16);
rtps_util_add_generic_guid_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_endpoint_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
} else {
ENSURE_LENGTH(4);
{
int i;
guint32 temp_offset;
guint32 seq_size = NEXT_guint32(tvb, offset, little_endian);
if (seq_size > 0) {
temp_offset = offset+4;
i = 1;
while(seq_size-- > 0) {
rtps_util_add_transport_info(rtps_parameter_tree, tvb, temp_offset, little_endian, i);
temp_offset += 8;
++i;
}
}
}
}
break;
}
case PID_DIRECT_COMMUNICATION: {
if (is_inline_qos) {
ENSURE_LENGTH(16);
rtps_util_add_generic_guid_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_endpoint_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
} else {
proto_tree_add_item(rtps_parameter_tree, hf_rtps_direct_communication, tvb, offset, 1, ENC_NA );
}
break;
}
case PID_TYPE_CONSISTENCY: {
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_type_consistency_kind, tvb, offset, 2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
}
case PID_PRODUCT_VERSION: {
ENSURE_LENGTH(4);
rtps_util_add_product_version(rtps_parameter_tree, tvb, offset);
break;
}
case PID_PLUGIN_PROMISCUITY_KIND: {
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_plugin_promiscuity_kind, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
}
case PID_ENTITY_VIRTUAL_GUID: {
ENSURE_LENGTH(16);
rtps_util_add_guid_prefix_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_sm_guid_prefix, hf_rtps_sm_host_id, hf_rtps_sm_app_id,
hf_rtps_sm_instance_id, 0);
rtps_util_add_entity_id(rtps_parameter_tree, tvb, offset+12,
hf_rtps_sm_entity_id, hf_rtps_sm_entity_id_key, hf_rtps_sm_entity_id_kind,
ett_rtps_entity, "virtualGUIDSuffix", NULL);
break;
}
case PID_SERVICE_KIND: {
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_service_kind, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
}
case PID_ROLE_NAME: {
rtps_util_add_string(rtps_parameter_tree, tvb, offset, hf_rtps_param_role_name, little_endian);
break;
}
case PID_ACK_KIND: {
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_acknowledgment_kind, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
}
case PID_PEER_HOST_EPOCH: {
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_peer_host_epoch, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
}
case PID_DOMAIN_ID: {
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_domain_id, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
}
case PID_EXTENDED: {
ENSURE_LENGTH(8);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_extended_parameter, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_extended_pid_length, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
}
case PID_TYPE_OBJECT: {
rtps_util_add_typeobject(rtps_parameter_tree, pinfo, tvb,
offset, little_endian, param_length);
break;
}
case PID_TYPECODE:
case PID_TYPECODE_RTPS2: {
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
-1,
NULL,
0);
break;
}
case PID_DISABLE_POSITIVE_ACKS: {
ENSURE_LENGTH(1);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_disable_positive_ack, tvb, offset, 1, ENC_NA );
break;
}
case PID_EXPECTS_VIRTUAL_HB: {
ENSURE_LENGTH(1);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_expects_virtual_heartbeat, tvb, offset, 1, ENC_NA );
break;
}
case PID_LOCATOR_FILTER_LIST: {
guint32 number_of_channels, ch;
proto_tree *channel_tree;
proto_item *ti_channel;
char temp_buff[20];
gint old_offset;
guint32 off = offset;
ENSURE_LENGTH(4);
number_of_channels = NEXT_guint32(tvb, off, little_endian);
proto_item_append_text(parameter_item, " (%d channels)", number_of_channels );
proto_tree_add_int(rtps_parameter_tree, hf_rtps_locator_filter_list_num_channels, tvb, off, 4, number_of_channels );
off += 4;
if (number_of_channels == 0) {
break;
}
off = rtps_util_add_string(rtps_parameter_tree, tvb, off, hf_rtps_locator_filter_list_filter_name, little_endian);
for (ch = 0; ch < number_of_channels; ++ch) {
g_snprintf(temp_buff, 20, "Channel[%u]", ch);
old_offset = off;
channel_tree = proto_tree_add_subtree_format(rtps_parameter_tree, tvb, off, 0, ett_rtps_locator_filter_channel, &ti_channel, "Channel[%u]", ch);
off = rtps_util_add_locator_list(channel_tree, pinfo, tvb, off, temp_buff, little_endian);
off = rtps_util_add_string(rtps_parameter_tree, tvb, off, hf_rtps_locator_filter_list_filter_exp, little_endian);
proto_item_set_len(ti_channel, (off - old_offset));
}
break;
}
default: {
return FALSE;
}
}
return TRUE;
}
static gboolean dissect_parameter_sequence_toc(proto_tree *rtps_parameter_tree, packet_info *pinfo _U_,
tvbuff_t *tvb, proto_item *parameter_item _U_, proto_item *param_len_item _U_, gint offset,
gboolean little_endian, int param_length _U_,
guint16 parameter) {
switch(parameter) {
case PID_TYPECODE_RTPS2: {
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
}
default:
return FALSE;
}
return TRUE;
}
static gboolean dissect_parameter_sequence_pt(proto_tree *rtps_parameter_tree _U_, packet_info *pinfo _U_,
tvbuff_t *tvb _U_, proto_item *parameter_item _U_, proto_item *param_len_item _U_, gint offset _U_,
gboolean little_endian _U_, int param_length _U_,
guint16 parameter) {
switch(parameter) {
case PID_PRISMTECH_WRITER_INFO: {
break;
}
case PID_PRISMTECH_READER_DATA_LIFECYCLE: {
break;
}
case PID_PRISMTECH_WRITER_DATA_LIFECYCLE: {
break;
}
case PID_PRISMTECH_ENDPOINT_GUID: {
break;
}
case PID_PRISMTECH_SYNCHRONOUS_ENDPOINT: {
break;
}
case PID_PRISMTECH_RELAXED_QOS_MATCHING: {
break;
}
case PID_PRISMTECH_PARTICIPANT_VERSION_INFO: {
break;
}
case PID_PRISMTECH_NODE_NAME: {
break;
}
case PID_PRISMTECH_EXEC_NAME: {
break;
}
case PID_PRISMTECH_PROCESS_ID: {
break;
}
case PID_PRISMTECH_SERVICE_TYPE: {
break;
}
case PID_PRISMTECH_ENTITY_FACTORY: {
break;
}
case PID_PRISMTECH_WATCHDOG_SCHEDULING: {
break;
}
case PID_PRISMTECH_LISTENER_SCHEDULING: {
break;
}
case PID_PRISMTECH_SUBSCRIPTION_KEYS: {
break;
}
case PID_PRISMTECH_READER_LIFESPAN: {
break;
}
case PID_PRISMTECH_SHARE: {
break;
}
case PID_PRISMTECH_TYPE_DESCRIPTION: {
break;
}
case PID_PRISMTECH_LAN_ID: {
break;
}
case PID_PRISMTECH_ENDPOINT_GID: {
break;
}
case PID_PRISMTECH_GROUP_GID: {
break;
}
case PID_PRISMTECH_EOTINFO: {
break;
}
case PID_PRISMTECH_PART_CERT_NAME: {
break;
}
case PID_PRISMTECH_LAN_CERT_NAME: {
break;
}
default:
return FALSE;
}
return TRUE;
}
static gboolean dissect_parameter_sequence_v1(proto_tree *rtps_parameter_tree, packet_info *pinfo, tvbuff_t *tvb,
proto_item *parameter_item, proto_item * param_len_item, gint offset,
gboolean little_endian, int size, int param_length,
guint16 parameter, guint16 version, type_mapping * type_mapping_object) {
proto_tree *subtree;
switch(parameter) {
case PID_PARTICIPANT_LEASE_DURATION:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time_sec_and_fraction(rtps_parameter_tree, tvb, offset, little_endian,
hf_rtps_participant_lease_duration);
break;
case PID_TIME_BASED_FILTER:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time_sec_and_fraction(rtps_parameter_tree, tvb, offset, little_endian,
hf_rtps_time_based_filter_minimum_separation);
break;
case PID_TOPIC_NAME: {
const gchar * retVal = NULL;
guint32 str_size = NEXT_guint32(tvb, offset, little_endian);
retVal = (gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset+4, str_size, ENC_ASCII);
rtps_util_store_type_mapping(tvb, offset, type_mapping_object, retVal, TOPIC_INFO_ADD_TOPIC_NAME);
rtps_util_add_string(rtps_parameter_tree, tvb, offset, hf_rtps_param_topic_name, little_endian);
break;
}
case PID_OWNERSHIP_STRENGTH:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_strength, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_TYPE_NAME: {
const gchar * retVal = NULL;
guint32 str_size = NEXT_guint32(tvb, offset, little_endian);
retVal = (gchar*) tvb_get_string_enc(wmem_packet_scope(), tvb, offset+4, str_size, ENC_ASCII);
rtps_util_store_type_mapping(tvb, offset, type_mapping_object, retVal, TOPIC_INFO_ADD_TYPE_NAME);
rtps_util_add_string(rtps_parameter_tree, tvb, offset, hf_rtps_param_type_name, little_endian);
break;
}
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
rtps_util_add_vendor_id(rtps_parameter_tree, tvb, offset);
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
rtps_util_add_ntp_time_sec_and_fraction(rtps_parameter_tree, tvb, offset, little_endian, hf_rtps_deadline_period);
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
rtps_util_add_ntp_time_sec_and_fraction(rtps_parameter_tree, tvb, offset,
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
rtps_util_add_ntp_time_sec_and_fraction(rtps_parameter_tree, tvb, offset, little_endian,
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
subtree = proto_tree_add_subtree(rtps_parameter_tree, tvb, offset, 12, ett_rtps_resource_limit, NULL, "Resource Limit");
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
guint32 temp_offset, prop_size;
const guint8 *propName, *propValue;
proto_item *list_item, *item;
proto_tree *property_list_tree, *property_tree;
guint32 seq_size = NEXT_guint32(tvb, offset, little_endian);
int start_offset = offset, str_length;
proto_item_append_text( parameter_item, " (%d properties)", seq_size );
if (seq_size > 0) {
property_list_tree = proto_tree_add_subtree(rtps_parameter_tree, tvb, offset, -1, ett_rtps_property_list, &list_item, "Property List");
temp_offset = offset+4;
while(seq_size-- > 0) {
prop_size = NEXT_guint32(tvb, temp_offset, little_endian);
if (prop_size > 0) {
propName = tvb_get_string_enc(wmem_packet_scope(), tvb, temp_offset+4, prop_size, ENC_ASCII);
} else {
propName = (const guint8 *)"";
}
str_length = (4 + ((prop_size + 3) & 0xfffffffc));
item = proto_tree_add_string(property_list_tree, hf_rtps_property_name, tvb, temp_offset, str_length, propName);
property_tree = proto_item_add_subtree(item, ett_rtps_property);
temp_offset += str_length;
prop_size = NEXT_guint32(tvb, temp_offset, little_endian);
if (prop_size > 0) {
propValue = tvb_get_string_enc(wmem_packet_scope(), tvb, temp_offset+4, prop_size, ENC_ASCII);
} else {
propValue = (const guint8 *)"";
}
str_length = (4 + ((prop_size + 3) & 0xfffffffc));
proto_tree_add_string(property_tree, hf_rtps_property_value, tvb, temp_offset, str_length, propValue);
temp_offset += str_length;
}
proto_item_set_len(list_item, temp_offset-start_offset);
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
proto_tree_add_bytes_format_value(rtps_parameter_tree, hf_rtps_filter_signature, tvb, prev_offset, temp_offset - prev_offset, NULL, "%08x %08x %08x %08x",
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
hf_rtps_participant_guid_v1, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id_v1, hf_rtps_param_app_kind,
hf_rtps_param_entity, hf_rtps_param_entity_key, hf_rtps_param_hf_entity_kind);
} else {
ENSURE_LENGTH(16);
rtps_util_add_generic_guid_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_participant_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
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
hf_rtps_param_instance_id_v1, hf_rtps_param_app_kind,
hf_rtps_param_entity, hf_rtps_param_entity_key, hf_rtps_param_hf_entity_kind);
} else {
ENSURE_LENGTH(16);
rtps_util_add_generic_guid_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_group_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
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
rtps_util_add_ntp_time_sec_and_fraction(rtps_parameter_tree, tvb, offset, little_endian,
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
subtree = proto_tree_add_subtree(rtps_parameter_tree, tvb, offset, param_length, ett_rtps_manager_key, NULL, "Manager Keys");
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
proto_tree_add_item(rtps_parameter_tree, hf_rtps_parameter_data, tvb,
offset, param_length, ENC_NA);
}
break;
default:
return FALSE;
}
return TRUE;
}
static gboolean dissect_parameter_sequence_v2(proto_tree *rtps_parameter_tree, packet_info *pinfo, tvbuff_t *tvb,
proto_item *parameter_item _U_, proto_item *param_len_item,
gint offset, gboolean little_endian, int param_length,
guint16 parameter, guint32 *pStatusInfo, guint16 vendor_id _U_,
type_mapping * type_mapping_object) {
proto_item *ti;
switch(parameter) {
case PID_STATUS_INFO: {
ENSURE_LENGTH(4);
proto_tree_add_bitmask(rtps_parameter_tree, tvb, offset,
hf_rtps_param_status_info_flags, ett_rtps_flags,
STATUS_INFO_FLAGS, ENC_BIG_ENDIAN);
if (pStatusInfo != NULL) {
*pStatusInfo = NEXT_guint32(tvb, offset, ENC_BIG_ENDIAN);
}
break;
}
case PID_DIRECTED_WRITE: {
ENSURE_LENGTH(16);
rtps_util_add_guid_prefix_v2(rtps_parameter_tree, tvb, offset, hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id, hf_rtps_sm_app_id, hf_rtps_sm_instance_id, 0);
rtps_util_add_entity_id(rtps_parameter_tree, tvb, offset+12, hf_rtps_sm_entity_id,
hf_rtps_sm_entity_id_key, hf_rtps_sm_entity_id_kind, ett_rtps_entity,
"guidSuffix", NULL);
break;
}
case PID_KEY_HASH: {
guint8 guidPart;
int i;
ti = proto_tree_add_bytes_format(rtps_parameter_tree, hf_rtps_guid, tvb, offset, param_length, NULL, "guid: ");
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
proto_tree_add_bytes_format_value(rtps_parameter_tree, hf_rtps_filter_signature, tvb, prev_offset, temp_offset - prev_offset, NULL, "%08x %08x %08x %08x",
fs[0], fs[1], fs[2], fs[3]);
}
break;
}
case PID_BUILTIN_ENDPOINT_SET: {
guint32 flags;
ENSURE_LENGTH(4);
flags = tvb_get_guint32(tvb, offset, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_bitmask_value(rtps_parameter_tree, tvb, offset,
hf_rtps_param_builtin_endpoint_set_flags, ett_rtps_flags,
BUILTIN_ENDPOINT_FLAGS, flags);
break;
}
case PID_TYPE_MAX_SIZE_SERIALIZED:
ENSURE_LENGTH(4);
proto_tree_add_item(rtps_parameter_tree, hf_rtps_param_type_max_size_serialized, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case PID_ORIGINAL_WRITER_INFO:
ENSURE_LENGTH(16);
rtps_util_add_guid_prefix_v2(rtps_parameter_tree, tvb, offset, hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id, hf_rtps_sm_app_id, hf_rtps_sm_instance_id, 0);
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
rtps_util_store_type_mapping(tvb, offset, type_mapping_object, NULL, TOPIC_INFO_ADD_GUID);
rtps_util_add_generic_guid_v2(rtps_parameter_tree, tvb, offset,
hf_rtps_endpoint_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
break;
default:
return FALSE;
}
return TRUE;
}
static gint dissect_parameter_sequence(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
gint offset, gboolean little_endian, guint size, const char *label,
guint16 version, guint32 *pStatusInfo, guint16 vendor_id,
gboolean is_inline_qos) {
proto_item *ti, *param_item, *param_len_item = NULL;
proto_tree *rtps_parameter_sequence_tree, *rtps_parameter_tree;
guint32 parameter, param_length, param_length_length = 2;
gint original_offset = offset;
gboolean dissect_return_value = FALSE;
type_mapping * type_mapping_object = NULL;
const gchar * param_name = NULL;
if (!pinfo->fd->flags.visited)
type_mapping_object = wmem_new(wmem_file_scope(), type_mapping);
rtps_parameter_sequence_tree = proto_tree_add_subtree_format(tree, tvb, offset, size,
ett_rtps_parameter_sequence, &ti, "%s:", label);
for (;;) {
size -= offset - original_offset;
if (size < 4) {
expert_add_info_format(pinfo, (param_len_item == NULL) ? ti : param_len_item,
&ei_rtps_parameter_value_invalid, "ERROR: not enough bytes to read the next parameter");
return 0;
}
original_offset = offset;
parameter = NEXT_guint16(tvb, offset, little_endian);
param_length = NEXT_guint16(tvb, offset+2, little_endian);
if ((parameter & PID_EXTENDED) == PID_EXTENDED) {
offset += 4;
parameter = tvb_get_guint32(tvb, offset, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
param_length = tvb_get_guint32(tvb, offset+4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
param_length_length = 4;
}
if (version < 0x0200) {
rtps_parameter_tree = proto_tree_add_subtree(rtps_parameter_sequence_tree, tvb, offset, -1,
ett_rtps_parameter, &param_item, val_to_str(parameter, parameter_id_vals, "Unknown (0x%04x)"));
proto_tree_add_uint(rtps_parameter_tree, hf_rtps_parameter_id, tvb, offset, 2, parameter);
} else {
gboolean goto_default = TRUE;
switch(vendor_id) {
case RTPS_VENDOR_RTI_DDS: {
if (is_inline_qos) {
param_name = try_val_to_str(parameter, parameter_id_inline_qos_rti);
if (param_name != NULL) {
rtps_parameter_tree = proto_tree_add_subtree(rtps_parameter_sequence_tree, tvb, offset, -1,
ett_rtps_parameter, &param_item, val_to_str(parameter, parameter_id_inline_qos_rti, "Unknown (0x%04x)"));
proto_tree_add_uint(rtps_parameter_tree, hf_rtps_parameter_id_inline_rti, tvb, offset,
param_length_length, parameter);
goto_default = FALSE;
}
} else {
param_name = try_val_to_str(parameter, parameter_id_rti_vals);
if (param_name != NULL) {
rtps_parameter_tree = proto_tree_add_subtree(rtps_parameter_sequence_tree, tvb, offset, -1,
ett_rtps_parameter, &param_item, val_to_str(parameter, parameter_id_rti_vals, "Unknown (0x%04x)"));
proto_tree_add_uint(rtps_parameter_tree, hf_rtps_parameter_id_rti, tvb, offset,
param_length_length, parameter);
goto_default = FALSE;
}
}
break;
}
case RTPS_VENDOR_TOC: {
param_name = try_val_to_str(parameter, parameter_id_toc_vals);
if (param_name != NULL) {
rtps_parameter_tree = proto_tree_add_subtree(rtps_parameter_sequence_tree, tvb, offset, -1,
ett_rtps_parameter, &param_item, val_to_str(parameter, parameter_id_toc_vals, "Unknown (0x%04x)"));
proto_tree_add_uint(rtps_parameter_tree, hf_rtps_parameter_id_toc, tvb, offset,
param_length_length, parameter);
goto_default = FALSE;
}
break;
}
case RTPS_VENDOR_PT_DDS: {
param_name = try_val_to_str(parameter, parameter_id_pt_vals);
if (param_name != NULL) {
rtps_parameter_tree = proto_tree_add_subtree(rtps_parameter_sequence_tree, tvb, offset, -1,
ett_rtps_parameter, &param_item, val_to_str(parameter, parameter_id_pt_vals, "Unknown (0x%04x)"));
proto_tree_add_uint(rtps_parameter_tree, hf_rtps_parameter_id_pt, tvb, offset,
param_length_length, parameter);
goto_default = FALSE;
}
break;
}
}
if (goto_default) {
rtps_parameter_tree = proto_tree_add_subtree(rtps_parameter_sequence_tree, tvb, offset, -1,
ett_rtps_parameter, &param_item, val_to_str(parameter, parameter_id_v2_vals, "Unknown (0x%04x)"));
proto_tree_add_uint(rtps_parameter_tree, hf_rtps_parameter_id_v2, tvb, offset,
param_length_length, parameter);
}
}
offset += param_length_length;
if (parameter == PID_SENTINEL) {
proto_item_set_len(param_item, 4);
return offset +2;
}
param_len_item = proto_tree_add_item(rtps_parameter_tree, hf_rtps_parameter_length,
tvb, offset, param_length_length, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += param_length_length;
if ((size-4 < param_length) &&
(parameter != PID_SENTINEL)) {
expert_add_info_format(pinfo, param_len_item, &ei_rtps_parameter_value_invalid, "Not enough bytes to read the parameter value");
return 0;
}
proto_item_set_len(param_item, param_length+2*param_length_length);
switch (vendor_id) {
case RTPS_VENDOR_RTI_DDS: {
dissect_return_value = dissect_parameter_sequence_rti(rtps_parameter_tree, pinfo, tvb,
param_item, param_len_item, offset, little_endian, param_length, parameter, is_inline_qos);
break;
}
case RTPS_VENDOR_TOC: {
dissect_return_value = dissect_parameter_sequence_toc(rtps_parameter_tree, pinfo, tvb,
param_item, param_len_item, offset, little_endian, param_length, parameter);
break;
}
case RTPS_VENDOR_PT_DDS: {
dissect_return_value = dissect_parameter_sequence_pt(rtps_parameter_tree, pinfo, tvb,
param_item, param_len_item, offset, little_endian, param_length, parameter);
break;
}
default:
break;
}
if (!dissect_return_value) {
if (!dissect_parameter_sequence_v1(rtps_parameter_tree, pinfo, tvb, param_item, param_len_item,
offset, little_endian, size, param_length, parameter, version, type_mapping_object)) {
if ((version < 0x0200) ||
!dissect_parameter_sequence_v2(rtps_parameter_tree, pinfo, tvb, param_item, param_len_item,
offset, little_endian, param_length, parameter,
pStatusInfo, vendor_id, type_mapping_object)) {
if (param_length > 0) {
proto_tree_add_item(rtps_parameter_tree, hf_rtps_parameter_data, tvb,
offset, param_length, ENC_NA);
}
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
col_set_str(pinfo->cinfo, COL_INFO, "PING");
return is_ping;
}
static void dissect_APP_ACK_CONF(tvbuff_t *tvb,
packet_info *pinfo _U_,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
proto_item *item)
{
gint original_offset;
guint32 virtual_writer_count;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, APP_ACK_CONF_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
original_offset = offset;
if (octets_to_next_header < 20) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", 20);
return;
}
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
virtual_writer_count = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_item(tree, hf_rtps_param_app_ack_conf_virtual_writer_count, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
{
proto_tree *sil_tree_writer_list;
proto_tree *sil_tree_writer;
guint32 current_writer_index = 0;
sil_tree_writer_list = proto_tree_add_subtree_format(tree, tvb, offset, -1,
ett_rtps_app_ack_virtual_writer_list, NULL, "Virtual Writer List");
current_writer_index = 0;
while (current_writer_index < virtual_writer_count) {
sil_tree_writer = proto_tree_add_subtree_format(sil_tree_writer_list, tvb, offset, -1,
ett_rtps_app_ack_virtual_writer, NULL, "virtualWriter[%d]", current_writer_index);
rtps_util_add_guid_prefix_v2(sil_tree_writer, tvb, offset,
hf_rtps_sm_guid_prefix, hf_rtps_sm_host_id, hf_rtps_sm_app_id,
hf_rtps_sm_instance_id, 0);
rtps_util_add_entity_id(sil_tree_writer, tvb, offset+12,
hf_rtps_sm_entity_id, hf_rtps_sm_entity_id_key, hf_rtps_sm_entity_id_kind,
ett_rtps_entity, "virtualGUIDSuffix", NULL);
offset += 16;
proto_tree_add_item(tree, hf_rtps_param_app_ack_conf_count, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
current_writer_index++;
}
}
if (offset < original_offset + octets_to_next_header)
{
expert_add_info_format(pinfo, item, &ei_rtps_extra_bytes, "Don't know how to decode those extra bytes: %d", octets_to_next_header - offset);
}
else if (offset > original_offset + octets_to_next_header)
{
expert_add_info(pinfo, item, &ei_rtps_missing_bytes);
}
}
static void dissect_serialized_data(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, gint offset,
int size, const char *label, guint16 vendor_id, gboolean is_discovery_data,
endpoint_guid * guid) {
proto_item *ti;
proto_tree *rtps_parameter_sequence_tree;
guint16 encapsulation_id;
gboolean encapsulation_little_endian = FALSE;
rtps_dissector_data * data = NULL;
data = wmem_new(wmem_packet_scope(), rtps_dissector_data);
data->info_displayed = FALSE;
data->encapsulation_id = 0;
data->position_in_batch = -1;
rtps_parameter_sequence_tree = proto_tree_add_subtree(tree, tvb, offset, size,
ett_rtps_serialized_data, &ti, label);
encapsulation_id = NEXT_guint16(tvb, offset, ENC_BIG_ENDIAN);
proto_tree_add_uint(rtps_parameter_sequence_tree,
hf_rtps_param_serialize_encap_kind, tvb, offset, 2, encapsulation_id);
data->encapsulation_id = encapsulation_id;
offset += 2;
if (encapsulation_id == ENCAPSULATION_CDR_LE ||
encapsulation_id == ENCAPSULATION_PL_CDR_LE) {
encapsulation_little_endian = TRUE;
}
proto_tree_add_item(rtps_parameter_sequence_tree, hf_rtps_param_serialize_encap_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (rtps_util_show_topic_info(rtps_parameter_sequence_tree, pinfo, tvb,
offset, guid, data))
return;
size -= 4;
switch (encapsulation_id) {
case ENCAPSULATION_CDR_LE:
case ENCAPSULATION_CDR_BE:
proto_tree_add_item(rtps_parameter_sequence_tree, hf_rtps_issue_data, tvb,
offset, size, ENC_NA);
break;
case ENCAPSULATION_PL_CDR_LE:
case ENCAPSULATION_PL_CDR_BE:
if (is_discovery_data) {
dissect_parameter_sequence(rtps_parameter_sequence_tree, pinfo, tvb, offset,
encapsulation_little_endian, size, label, 0x0200, NULL, vendor_id, FALSE);
} else {
expert_add_info(pinfo, ti, &ei_rtps_unsupported_non_builtin_param_seq);
}
break;
default:
proto_tree_add_item(rtps_parameter_sequence_tree, hf_rtps_data_serialize_data, tvb,
offset, size, ENC_NA);
}
}
static void dissect_APP_ACK(tvbuff_t *tvb,
packet_info *pinfo,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
proto_item *item)
{
gint original_offset;
guint32 virtual_writer_count;
guint32 wid;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, APP_ACK_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header < 56) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", 56);
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
&wid);
offset += 4;
virtual_writer_count = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_item(tree, hf_rtps_param_app_ack_virtual_writer_count, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
{
proto_tree *sil_tree_writer_list;
guint32 current_writer_index;
guint32 current_interval_count;
sil_tree_writer_list = proto_tree_add_subtree_format(tree, tvb, offset, -1,
ett_rtps_app_ack_virtual_writer_list, NULL, "Virtual Writer List");
current_writer_index = 0;
while (current_writer_index < virtual_writer_count) {
proto_tree *sil_tree_writer;
proto_tree *sil_tree_interval_list;
guint16 interval_count;
sil_tree_writer = proto_tree_add_subtree_format(sil_tree_writer_list, tvb, offset, -1,
ett_rtps_app_ack_virtual_writer, NULL, "virtualWriter[%d]", current_writer_index);
#if 0
rtps_util_add_generic_guid(sil_tree_writer,
tvb,
offset,
"virtualGUID",
buffer,
MAX_GUID_SIZE);
#endif
offset += 16;
interval_count = NEXT_guint16(tvb, offset, little_endian);
proto_tree_add_item(sil_tree_writer, hf_rtps_param_app_ack_interval_count,
tvb, offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sil_tree_writer, hf_rtps_param_app_ack_octets_to_next_virtual_writer,
tvb, offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
sil_tree_interval_list = proto_tree_add_subtree_format(sil_tree_writer, tvb, offset, -1,
ett_rtps_app_ack_virtual_writer_interval_list, NULL, "Interval List");
current_interval_count = 0;
while (current_interval_count < interval_count) {
proto_tree *sil_tree_interval;
guint16 interval_payload_length;
sil_tree_interval = proto_tree_add_subtree_format(sil_tree_interval_list, tvb, offset, -1,
ett_rtps_app_ack_virtual_writer_interval, NULL, "Interval[%d]", current_interval_count);
rtps_util_add_seq_number(sil_tree_interval,
tvb,
offset,
little_endian,
"firstVirtualSN");
offset += 8;
rtps_util_add_seq_number(sil_tree_interval,
tvb,
offset,
little_endian,
"lastVirtualSN");
offset += 8;
proto_tree_add_item(sil_tree_interval, hf_rtps_param_app_ack_interval_flags,
tvb, offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
interval_payload_length = NEXT_guint16(tvb, offset, little_endian);
proto_tree_add_item(sil_tree_interval, hf_rtps_param_app_ack_interval_payload_length,
tvb, offset, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
if (interval_payload_length > 0) {
proto_tree_add_item(sil_tree_interval, hf_rtps_serialized_data, tvb, offset,
interval_payload_length, ENC_NA);
offset += ((interval_payload_length + 3) & 0xfffffffc);
}
++current_interval_count;
}
proto_tree_add_item(tree, hf_rtps_param_app_ack_count, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
current_writer_index++;
}
}
if (offset < original_offset + octets_to_next_header)
{
expert_add_info_format(pinfo, item, &ei_rtps_extra_bytes, "Don't know how to decode those extra bytes: %d", octets_to_next_header - offset);
}
else if (offset > original_offset + octets_to_next_header)
{
expert_add_info(pinfo, item, &ei_rtps_missing_bytes);
}
}
void dissect_PAD(tvbuff_t *tvb,
packet_info *pinfo,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree) {
proto_item *item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, PAD_FLAGS, flags);
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
gboolean is_builtin_entity = FALSE;
gint old_offset = offset;
guint32 wid;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, DATA_FLAGSv1, flags);
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
hf_rtps_sm_guid_prefix_v1, hf_rtps_sm_host_id, hf_rtps_sm_app_id,
hf_rtps_sm_instance_id_v1, hf_rtps_sm_app_kind,
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
gboolean is_inline_qos = TRUE;
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset,
little_endian, octets_to_next_header, "inlineQos",
0x0102, NULL, 0, is_inline_qos);
}
if ((flags & FLAG_DATA_D) != 0) {
if (is_builtin_entity) {
dissect_parameter_sequence(tree, pinfo, tvb, offset,
little_endian, octets_to_next_header, "serializedData",
0x0102, NULL, 0, FALSE);
} else {
proto_tree_add_item(tree, hf_rtps_issue_data, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
ENC_NA);
}
}
}
static void dissect_DATA_v2(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree,
guint16 vendor_id, endpoint_guid *guid) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
proto_item *octet_item;
gboolean from_builtin_writer;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, DATA_FLAGSv2, flags);
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
hf_rtps_sm_app_id, hf_rtps_sm_instance_id, 0);
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
gboolean is_inline_qos = TRUE;
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, NULL, vendor_id, is_inline_qos);
}
if ((flags & FLAG_DATA_D_v2) != 0) {
from_builtin_writer =
(((wid & 0xc2) == 0xc2) || ((wid & 0xc3) == 0xc3)) ? TRUE : FALSE;
guid->entity_id = wid;
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData", vendor_id, from_builtin_writer, guid);
}
append_status_info(pinfo, wid, status_info);
}
static void dissect_DATA_FRAG(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree, guint16 vendor_id) {
int min_len;
gint old_offset = offset;
proto_item *octet_item;
guint32 wid;
gboolean from_builtin_writer;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, DATA_FRAG_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 32;
if ((flags & FLAG_DATA_FRAG_Q) != 0) min_len += 4;
if ((flags & FLAG_DATA_FRAG_H) != 0) min_len += 12;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
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
rtps_util_add_guid_prefix_v2(tree, tvb, offset, hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id, hf_rtps_sm_app_id, hf_rtps_sm_instance_id, 0);
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
gboolean is_inline_qos = TRUE;
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, NULL, vendor_id, is_inline_qos);
}
if ((flags & FLAG_DATA_D_v2) != 0) {
from_builtin_writer =
(((wid & 0xc2) == 0xc2) || ((wid & 0xc3) == 0xc3)) ? TRUE : FALSE;
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData", vendor_id, from_builtin_writer, NULL);
}
}
static void dissect_NOKEY_DATA(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree,
guint16 version, guint16 vendor_id) {
int min_len;
guint32 wid;
gboolean from_builtin_writer;
gint old_offset = offset;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, NOKEY_DATA_FLAGS, flags);
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
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", &wid);
offset += 4;
rtps_util_add_seq_number(tree, tvb, offset, little_endian, "writerSeqNumber");
offset += 8;
if ((flags & FLAG_NOKEY_DATA_Q) != 0) {
gboolean is_inline_qos = TRUE;
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset,
little_endian, octets_to_next_header, "inlineQos",
version, NULL, vendor_id, is_inline_qos);
}
if ((version < 0x0200) && (flags & FLAG_NOKEY_DATA_D) == 0) {
proto_tree_add_item(tree, hf_rtps_issue_data, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
ENC_NA);
}
if ((version >= 0x0200) && (flags & FLAG_DATA_D_v2) != 0) {
from_builtin_writer =
(((wid & 0xc2) == 0xc2) || ((wid & 0xc3) == 0xc3)) ? TRUE : FALSE;
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData", vendor_id, from_builtin_writer, NULL);
}
}
static void dissect_NOKEY_DATA_FRAG(tvbuff_t *tvb, packet_info *pinfo, gint offset,
guint8 flags, gboolean little_endian, int octets_to_next_header, proto_tree *tree,
guint16 vendor_id) {
int min_len;
guint32 wid;
gboolean from_builtin_writer;
gint old_offset = offset;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, NOKEY_DATA_FRAG_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 28;
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
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", &wid);
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
gboolean is_inline_qos = TRUE;
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, NULL, vendor_id, is_inline_qos);
}
if ((flags & FLAG_DATA_D_v2) != 0) {
from_builtin_writer =
(((wid & 0xc2) == 0xc2) || ((wid & 0xc3) == 0xc3)) ? TRUE : FALSE;
dissect_serialized_data(tree, pinfo, tvb,offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData", vendor_id, from_builtin_writer, NULL);
}
}
static void dissect_ACKNACK(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree, proto_item *item) {
gint original_offset;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, ACKNACK_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb, offset + 2, 2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header < 20) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= 20)");
return;
}
offset += 4;
original_offset = offset;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", NULL);
offset += 4;
offset = rtps_util_add_bitmap(tree, tvb, offset, little_endian, "readerSNState");
if (offset + 4 == original_offset + octets_to_next_header) {
proto_tree_add_item(tree, hf_rtps_acknack_count, tvb, offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
} else if (offset < original_offset + octets_to_next_header) {
expert_add_info_format(pinfo, item, &ei_rtps_extra_bytes, "Don't know how to decode those extra bytes: %d", octets_to_next_header - offset);
} else if (offset > original_offset + octets_to_next_header) {
expert_add_info(pinfo, item, &ei_rtps_missing_bytes);
}
}
static void dissect_NACK_FRAG(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, NACK_FRAG_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header < 24) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= 24)");
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
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, HEARTBEAT_FLAGS, flags);
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
proto_tree_add_uint(tree, hf_rtps_heartbeat_count, tvb, offset, 4, counter);
}
}
static void dissect_HEARTBEAT_BATCH(tvbuff_t *tvb, packet_info *pinfo, gint offset,
guint8 flags, gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, HEARTBEAT_BATCH_FLAGS, flags);
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
static void dissect_HEARTBEAT_VIRTUAL(tvbuff_t *tvb, packet_info *pinfo _U_, gint offset,
guint8 flags, gboolean little_endian, int octets_to_next_header, proto_tree *tree,
guint16 vendor_id _U_) {
guint32 num_writers, num_virtual_guids;
gint writer_id_offset, virtual_guid_offset = 0, old_offset;
proto_item *octet_item, *ti;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, HEARTBEAT_VIRTUAL_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header < 12) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", 12);
return;
}
offset += 4;
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
writer_id_offset = offset;
offset += 4;
if (!(flags & FLAG_VIRTUAL_HEARTBEAT_V) && !(flags & FLAG_VIRTUAL_HEARTBEAT_N)) {
virtual_guid_offset = offset;
offset += 16;
}
ti = proto_tree_add_item(tree, hf_rtps_virtual_heartbeat_num_writers, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (flags & FLAG_VIRTUAL_HEARTBEAT_W) {
num_writers = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
} else {
proto_item_set_text(ti, "numWriters: 1");
num_writers = 1;
}
{
proto_tree *sil_tree_writer_list;
guint32 current_writer_index;
sil_tree_writer_list = proto_tree_add_subtree_format(tree, tvb, offset, -1,
ett_rtps_writer_heartbeat_virtual_list, NULL, "Writer List");
current_writer_index = 0;
while (current_writer_index < num_writers) {
proto_tree *sil_tree_writer;
sil_tree_writer = proto_tree_add_subtree_format(sil_tree_writer_list, tvb, offset, -1,
ett_rtps_writer_heartbeat_virtual, NULL, "writer[%d]", current_writer_index);
if (num_writers == 1) {
old_offset = offset;
offset = writer_id_offset;
}
rtps_util_add_entity_id(sil_tree_writer,
tvb,
offset,
hf_rtps_sm_wrentity_id,
hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind,
ett_rtps_wrentity,
"writerEntityId",
NULL);
if (num_writers == 1) {
offset = old_offset;
} else {
offset += 4;
}
if (!(flags & FLAG_VIRTUAL_HEARTBEAT_N)) {
proto_tree_add_item(sil_tree_writer, hf_rtps_virtual_heartbeat_num_virtual_guids, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
num_virtual_guids = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
} else {
num_virtual_guids = 0;
}
if (num_virtual_guids != 0) {
proto_tree *sil_tree_virtual_guid_list;
guint32 current_virtual_guid_index;
sil_tree_virtual_guid_list = proto_tree_add_subtree_format(sil_tree_writer, tvb, offset, -1,
ett_rtps_virtual_guid_heartbeat_virtual_list, NULL, "Virtual GUID List");
current_virtual_guid_index = 0;
while (current_virtual_guid_index < num_virtual_guids) {
proto_tree *sil_tree_virtual_guid;
sil_tree_virtual_guid = proto_tree_add_subtree_format(sil_tree_virtual_guid_list, tvb, offset, -1,
ett_rtps_virtual_guid_heartbeat_virtual, NULL, "virtualGUID[%d]", current_virtual_guid_index);
if (!(flags & FLAG_VIRTUAL_HEARTBEAT_V)) {
old_offset = offset;
offset = virtual_guid_offset;
}
if (!(flags & FLAG_VIRTUAL_HEARTBEAT_V)) {
offset = old_offset;
} else {
offset += 16;
}
rtps_util_add_seq_number(sil_tree_virtual_guid,
tvb,
offset,
little_endian,
"firstVirtualSN");
offset += 8;
rtps_util_add_seq_number(sil_tree_virtual_guid,
tvb,
offset,
little_endian,
"lastVirtualSN");
offset += 8;
rtps_util_add_seq_number(sil_tree_virtual_guid,
tvb,
offset,
little_endian,
"firstRTPSSN");
offset += 8;
rtps_util_add_seq_number(sil_tree_virtual_guid,
tvb,
offset,
little_endian,
"lastRTPSSN");
offset += 8;
current_virtual_guid_index++;
}
}
current_writer_index++;
}
}
proto_tree_add_item(tree, hf_rtps_virtual_heartbeat_count, tvb, offset,
4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
static void dissect_HEARTBEAT_FRAG(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, HEARTBEAT_FRAG_FLAGS, flags);
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
guint16 vendor_id, gboolean is_session, endpoint_guid * guid) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
gboolean from_builtin_writer;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, RTPS_DATA_FLAGS, flags);
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
offset += 4;
proto_tree_add_item(tree, hf_rtps_extra_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_uint(tree, hf_rtps_octets_to_inline_qos, tvb, offset, 2, NEXT_guint16(tvb, offset, little_endian));
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
gboolean is_inline_qos = TRUE;
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, &status_info, vendor_id, is_inline_qos);
}
if (((flags & FLAG_RTPS_DATA_D) != 0) || ((flags & FLAG_RTPS_DATA_K) != 0)) {
if (wid == ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_WRITER) {
proto_tree *rtps_pm_tree;
proto_tree *guid_tree;
guint32 kind;
guint16 encapsulation_id;
guint16 encapsulation_len;
proto_item *ti;
rtps_pm_tree = proto_tree_add_subtree(tree, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
ett_rtps_part_message_data, &ti, "ParticipantMessageData");
encapsulation_id = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_uint(rtps_pm_tree, hf_rtps_encapsulation_kind, tvb, offset, 2, encapsulation_id);
offset += 2;
#if 0
if (encapsulation_id == ENCAPSULATION_CDR_LE ||
encapsulation_id == ENCAPSULATION_PL_CDR_LE) {
encapsulation_little_endian = 1;
}
#endif
encapsulation_len = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_uint(rtps_pm_tree, hf_rtps_encapsulation_options, tvb, offset, 2, encapsulation_len);
offset += 2;
guid_tree = proto_item_add_subtree(ti, ett_rtps_part_message_data);
rtps_util_add_guid_prefix_v2(guid_tree, tvb, offset, hf_rtps_sm_guid_prefix, hf_rtps_sm_host_id,
hf_rtps_sm_app_id, hf_rtps_sm_instance_id, 0);
offset += 12;
kind = NEXT_guint32(tvb, offset, FALSE);
proto_tree_add_uint(guid_tree, hf_rtps_encapsulation_kind, tvb, offset, 4, kind);
offset += 4;
rtps_util_add_seq_octets(rtps_pm_tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset), hf_rtps_data_serialize_data);
} else if (wid == ENTITYID_P2P_BUILTIN_PARTICIPANT_STATELESS_WRITER) {
proto_tree * rtps_pgm_tree, * guid_tree, * message_identity_tree;
proto_item *ti;
guint16 encapsulation_id, encapsulation_opt;
gint32 alignment_zero;
ti = proto_tree_add_boolean_format(tree, hf_rtps_pgm, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4, TRUE, "Participant Generic Message");
rtps_pgm_tree = proto_item_add_subtree(ti, ett_rtps_pgm_data);
encapsulation_id = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_uint(rtps_pgm_tree, hf_rtps_param_serialize_encap_kind,
tvb, offset, 2, encapsulation_id);
little_endian = (encapsulation_id == ENCAPSULATION_CDR_LE ||
encapsulation_id == ENCAPSULATION_PL_CDR_LE);
offset += 2;
encapsulation_opt = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_uint(rtps_pgm_tree, hf_rtps_param_serialize_encap_len,
tvb, offset, 2, encapsulation_opt);
offset += 2;
alignment_zero = offset;
message_identity_tree = proto_tree_add_subtree(rtps_pgm_tree, tvb, offset,
24 , ett_rtps_message_identity, &ti, "Message Identity");
guid_tree = proto_item_add_subtree(ti, ett_rtps_message_identity);
rtps_util_add_generic_guid_v2(guid_tree, tvb, offset,
hf_rtps_message_identity_source_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
offset += 16;
proto_tree_add_item(message_identity_tree, hf_rtps_sm_seq_number, tvb,
offset, 8, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 8;
message_identity_tree = proto_tree_add_subtree(rtps_pgm_tree, tvb, offset,
24 , ett_rtps_related_message_identity, &ti, "Related Message Identity");
guid_tree = proto_item_add_subtree(ti, ett_rtps_related_message_identity);
rtps_util_add_generic_guid_v2(guid_tree, tvb, offset,
hf_rtps_message_identity_source_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
offset += 16;
proto_tree_add_item(message_identity_tree, hf_rtps_sm_seq_number, tvb,
offset, 8, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 8;
guid_tree = proto_item_add_subtree(rtps_pgm_tree, ett_rtps_pgm_data);
rtps_util_add_generic_guid_v2(guid_tree, tvb, offset,
hf_rtps_pgm_dst_participant_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
offset += 16;
guid_tree = proto_item_add_subtree(rtps_pgm_tree, ett_rtps_pgm_data);
rtps_util_add_generic_guid_v2(guid_tree, tvb, offset,
hf_rtps_pgm_dst_endpoint_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
offset += 16;
guid_tree = proto_item_add_subtree(rtps_pgm_tree, ett_rtps_pgm_data);
rtps_util_add_generic_guid_v2(guid_tree, tvb, offset,
hf_rtps_pgm_src_endpoint_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
offset += 16;
offset = rtps_util_add_string(rtps_pgm_tree, tvb, offset, hf_rtps_pgm_message_class_id, little_endian);
rtps_util_add_data_holder_seq(rtps_pgm_tree, tvb, pinfo, offset,
little_endian, alignment_zero);
} else if (wid == ENTITYID_RTI_BUILTIN_LOCATOR_PING_WRITER) {
proto_tree * locator_ping_tree, *guid_tree;
proto_item *ti;
guint16 encapsulation_id, encapsulation_opt;
locator_ping_tree = proto_tree_add_subtree(tree, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
ett_rtps_locator_ping_tree, &ti, "Locator Ping Message");
encapsulation_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(locator_ping_tree, hf_rtps_encapsulation_id,
tvb, offset, 2, encapsulation_id);
offset += 2;
little_endian = (encapsulation_id == ENCAPSULATION_CDR_LE || encapsulation_id == ENCAPSULATION_PL_CDR_LE);
encapsulation_opt = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(locator_ping_tree, hf_rtps_encapsulation_options,
tvb, offset, 2, encapsulation_opt);
offset += 2;
guid_tree = proto_item_add_subtree(ti, ett_rtps_generic_guid);
rtps_util_add_generic_guid_v2(guid_tree, tvb, offset,
hf_rtps_source_participant_guid, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
offset += 16;
rtps_util_add_locator_t(locator_ping_tree, pinfo, tvb, offset, little_endian,
"Destination Locator");
} else if (wid == ENTITYID_RTI_BUILTIN_SERVICE_REQUEST_WRITER) {
proto_tree * service_request_tree, * guid_tree;
proto_item *ti;
guint16 encapsulation_id, encapsulation_opt;
guint32 service_id;
ti = proto_tree_add_boolean_format(tree, hf_rtps_srm, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
TRUE, "Service Request Message");
service_request_tree = proto_item_add_subtree(ti, ett_rtps_service_request_tree);
encapsulation_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(service_request_tree, hf_rtps_encapsulation_id,
tvb, offset, 2, encapsulation_id);
offset += 2;
little_endian = (encapsulation_id == ENCAPSULATION_CDR_LE || encapsulation_id == ENCAPSULATION_PL_CDR_LE);
encapsulation_opt = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(service_request_tree, hf_rtps_encapsulation_options, tvb,
offset, 2, encapsulation_opt);
offset += 2;
service_id = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_item(service_request_tree, hf_rtps_srm_service_id, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
guid_tree = proto_item_add_subtree(ti, ett_rtps_generic_guid);
rtps_util_add_generic_guid_v2(guid_tree, tvb, offset,
hf_rtps_srm_instance_id, hf_rtps_param_host_id, hf_rtps_param_app_id,
hf_rtps_param_instance_id, hf_rtps_param_entity, hf_rtps_param_entity_key,
hf_rtps_param_hf_entity_kind);
offset += 16;
rtps_util_add_rti_service_request(service_request_tree, pinfo, tvb, offset,
little_endian, service_id);
} else {
const char *label;
if (((flags & FLAG_RTPS_DATA_D) != 0) || ((flags & FLAG_RTPS_DATA_K) == 0)) {
label = "serializedData";
} else if (((flags & FLAG_RTPS_DATA_D) == 0) || ((flags & FLAG_RTPS_DATA_K) != 0)) {
label = "serializedKey";
} else {
label = "<invalid or unknown data type>";
}
from_builtin_writer =
(((wid & 0xc2) == 0xc2) || ((wid & 0xc3) == 0xc3)) ? TRUE : FALSE;
guid->entity_id = wid;
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
label, vendor_id, from_builtin_writer, guid);
}
}
append_status_info(pinfo, wid, status_info);
}
static void dissect_RTPS_DATA_FRAG(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
guint32 wid;
gboolean from_builtin_writer;
guint32 status_info = 0xffffffff;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, RTPS_DATA_FRAG_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 36;
if ((flags & FLAG_RTPS_DATA_FRAG_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
offset += 4;
proto_tree_add_item(tree, hf_rtps_extra_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_uint(tree, hf_rtps_octets_to_inline_qos, tvb, offset, 2,
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
gboolean is_inline_qos = TRUE;
offset = dissect_parameter_sequence(tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos", 0x0200, &status_info, vendor_id, is_inline_qos);
}
{
const char *label = "serializedData";
if ((flags & FLAG_RTPS_DATA_FRAG_K) != 0) {
label = "serializedKey";
}
from_builtin_writer =
(((wid & 0xc2) == 0xc2) || ((wid & 0xc3) == 0xc3)) ? TRUE : FALSE;
dissect_serialized_data(tree, pinfo, tvb, offset,
octets_to_next_header - (offset - old_offset) + 4,
label, vendor_id, from_builtin_writer, NULL);
}
append_status_info(pinfo, wid, status_info);
}
static void dissect_RTPS_DATA_BATCH(tvbuff_t *tvb, packet_info *pinfo, gint offset,
guint8 flags, gboolean little_endian, int octets_to_next_header,
proto_tree *tree, guint16 vendor_id, endpoint_guid * guid) {
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
proto_item *octet_item;
rtps_dissector_data * data = NULL;
data = wmem_new(wmem_packet_scope(), rtps_dissector_data);
data->info_displayed = FALSE;
data->encapsulation_id = 0;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, RTPS_DATA_BATCH_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
min_len = 44;
if ((flags & FLAG_RTPS_DATA_BATCH_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be >= %u)", min_len);
return;
}
offset += 4;
proto_tree_add_item(tree, hf_rtps_extra_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_uint(tree, hf_rtps_octets_to_inline_qos, tvb, offset, 2,
NEXT_guint16(tvb, offset, little_endian));
offset += 2;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_rdentity_id, hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind, ett_rtps_rdentity, "readerEntityId", NULL);
offset += 4;
rtps_util_add_entity_id(tree, tvb, offset, hf_rtps_sm_wrentity_id, hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind, ett_rtps_wrentity, "writerEntityId", &wid);
guid->entity_id = wid;
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
"batchInlineQos", 0x0200, &status_info, vendor_id, FALSE);
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
sil_tree = proto_tree_add_subtree(tree, tvb, offset, octectsToSLEncapsulationId,
ett_rtps_sample_info_list, &list_item, "Sample Info List");
if (rtps_max_batch_samples_dissected == 0) {
sample_info_max = 1024;
}
sample_info_flags = (guint16 *)wmem_alloc(wmem_packet_scope(), sizeof(guint16) *sample_info_max);
sample_info_length = (guint32 *)wmem_alloc(wmem_packet_scope(), sizeof(guint32) *sample_info_max);
while (offset < sampleListOffset) {
guint16 flags2;
gint min_length;
proto_tree *si_tree;
gint offset_begin_sampleinfo = offset;
if (rtps_max_batch_samples_dissected > 0 && (guint)sample_info_count >= rtps_max_batch_samples_dissected) {
expert_add_info(pinfo, list_item, &ei_rtps_more_samples_available);
offset = sampleListOffset;
break;
}
si_tree = proto_tree_add_subtree_format(sil_tree, tvb, offset, -1, ett_rtps_sample_info, &ti, "sampleInfo[%d]", sample_info_count);
flags2 = NEXT_guint16(tvb, offset, FALSE);
sample_info_flags[sample_info_count] = flags2;
proto_tree_add_bitmask_value(si_tree, tvb, offset, hf_rtps_sm_flags2, ett_rtps_flags, RTPS_SAMPLE_INFO_FLAGS16, flags2);
offset += 2;
proto_tree_add_item(si_tree, hf_rtps_data_batch_octets_to_inline_qos, tvb,
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
proto_tree_add_item(si_tree, hf_rtps_data_batch_serialized_data_length, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
if ((flags2 & FLAG_SAMPLE_INFO_T) != 0) {
rtps_util_add_ntp_time(si_tree, tvb, offset, little_endian, hf_rtps_data_batch_timestamp);
offset += 8;
}
if ((flags2 & FLAG_SAMPLE_INFO_O) != 0) {
proto_tree_add_item(si_tree, hf_rtps_data_batch_offset_sn, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
}
if ((flags2 & FLAG_SAMPLE_INFO_Q) != 0) {
offset = dissect_parameter_sequence(si_tree, pinfo, tvb, offset, little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"sampleInlineQos", 0x0200, &status_info, vendor_id, FALSE);
}
proto_item_set_len(ti, offset - offset_begin_sampleinfo);
sample_info_count++;
}
}
encapsulation_id = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_uint(tree, hf_rtps_encapsulation_id, tvb, offset, 2, encapsulation_id);
data->encapsulation_id = encapsulation_id;
offset += 2;
offset += 2;
if (octets_to_next_header - (offset - old_offset) > 0) {
proto_item *ti;
proto_tree *sil_tree;
gint count = 0;
sil_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_rtps_sample_batch_list, &ti, "Serialized Sample List");
for (count = 0; count < sample_info_count; ++count) {
if (octets_to_next_header - (offset - old_offset) + 4 < (gint)sample_info_length[count]) {
expert_add_info_format(pinfo, ti, &ei_rtps_parameter_value_invalid, "Error: not enough bytes to dissect sample");
return;
}
data->position_in_batch = count;
if ((sample_info_flags[count] & FLAG_SAMPLE_INFO_K) != 0) {
proto_tree_add_bytes_format(sil_tree, hf_rtps_serialized_key,
tvb, offset, sample_info_length[count], NULL, "serializedKey[%d]", count);
} else {
if (!rtps_util_show_topic_info(sil_tree, pinfo, tvb, offset, guid, data)) {
proto_tree_add_bytes_format(sil_tree, hf_rtps_serialized_data,
tvb, offset, sample_info_length[count], NULL, "serializedData[%d]", count);
}
}
offset += sample_info_length[count];
}
}
append_status_info(pinfo, wid, status_info);
}
static void dissect_GAP(tvbuff_t *tvb, packet_info *pinfo, gint offset,
guint8 flags, gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, GAP_FLAGS, flags);
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
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, INFO_TS_FLAGS, flags);
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
proto_item *octet_item;
guint32 ip;
guint16 version;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, INFO_SRC_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (rtps_version < 0x0200) {
if (octets_to_next_header != 16) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be == 16)");
return;
}
} else {
if (octets_to_next_header != 20) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be == 20)");
return;
}
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
hf_rtps_sm_guid_prefix_v1, hf_rtps_sm_host_id, hf_rtps_sm_app_id,
hf_rtps_sm_instance_id_v1, hf_rtps_sm_app_kind,
NULL);
} else {
rtps_util_add_guid_prefix_v2(tree, tvb, offset, hf_rtps_guid_prefix_src,
hf_rtps_host_id, hf_rtps_app_id, hf_rtps_sm_instance_id, hf_rtps_guid_prefix);
}
}
static void dissect_INFO_REPLY_IP4(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
int min_len;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, INFO_REPLY_IP4_FLAGS, flags);
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
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, INFO_DST_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (version < 0x0200) {
if (octets_to_next_header != 8) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be == 8)");
return;
}
} else {
if (octets_to_next_header != 12) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be == 12)");
return;
}
}
offset += 4;
if (version < 0x0200) {
rtps_util_add_guid_prefix_v1(tree, tvb, offset,
hf_rtps_sm_guid_prefix_v1, hf_rtps_sm_host_id, hf_rtps_sm_app_id,
hf_rtps_sm_instance_id_v1, hf_rtps_sm_app_kind,
NULL);
} else {
rtps_util_add_guid_prefix_v2(tree, tvb, offset, hf_rtps_guid_prefix_dst,
hf_rtps_host_id, hf_rtps_app_id, hf_rtps_sm_instance_id, hf_rtps_guid_prefix);
}
}
static void dissect_INFO_REPLY(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, int octets_to_next_header, proto_tree *tree) {
int min_len;
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, INFO_REPLY_FLAGS, flags);
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
static void dissect_RTI_CRC(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, gint octets_to_next_header,proto_tree *tree) {
proto_item *octet_item;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, RTI_CRC_FLAGS, flags);
octet_item = proto_tree_add_item(tree, hf_rtps_sm_octets_to_next_header, tvb,
offset + 2, 2, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (octets_to_next_header != 8) {
expert_add_info_format(pinfo, octet_item, &ei_rtps_sm_octets_to_next_header_error, "(Error: should be == 8)");
return;
}
offset += 4;
proto_tree_add_item(tree, hf_rtps_sm_rti_crc_number, tvb, offset, 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_rtps_sm_rti_crc_result, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void dissect_SECURE(tvbuff_t *tvb, packet_info *pinfo _U_, gint offset,
guint8 flags, gboolean little_endian, int octets_to_next_header,
proto_tree *tree, guint16 vendor_id _U_) {
proto_tree * payload_tree;
proto_tree_add_bitmask_value(tree, tvb, offset + 1, hf_rtps_sm_flags, ett_rtps_flags, SECURE_FLAGS, flags);
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
payload_tree = proto_tree_add_subtree_format(tree, tvb, offset, octets_to_next_header,
ett_rtps_secure_payload_tree, NULL, "Secured payload");
proto_tree_add_item(payload_tree, hf_rtps_secure_transformation_id, tvb,
offset, 4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(payload_tree, hf_rtps_secure_ciphertext, tvb,
offset, octets_to_next_header-4, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
static gboolean dissect_rtps_submessage_v2(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags,
gboolean little_endian, guint8 submessageId, guint16 vendor_id, gint octets_to_next_header,
proto_tree *rtps_submessage_tree, proto_item *submessage_item,
endpoint_guid * guid)
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
case SUBMESSAGE_APP_ACK:
dissect_APP_ACK(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, submessage_item);
break;
case SUBMESSAGE_APP_ACK_CONF:
dissect_APP_ACK_CONF(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, submessage_item);
break;
case SUBMESSAGE_HEARTBEAT_SESSION:
case SUBMESSAGE_HEARTBEAT_BATCH:
dissect_HEARTBEAT_BATCH(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_HEARTBEAT_FRAG:
dissect_HEARTBEAT_FRAG(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_HEARTBEAT_VIRTUAL:
dissect_HEARTBEAT_VIRTUAL(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree, vendor_id);
break;
case SUBMESSAGE_RTPS_DATA_SESSION:
case SUBMESSAGE_RTPS_DATA:
dissect_RTPS_DATA(tvb, pinfo, offset, flags, little_endian, octets_to_next_header,
rtps_submessage_tree, vendor_id, (submessageId == SUBMESSAGE_RTPS_DATA_SESSION), guid);
break;
case SUBMESSAGE_RTPS_DATA_FRAG:
dissect_RTPS_DATA_FRAG(tvb, pinfo, offset, flags, little_endian, octets_to_next_header,
rtps_submessage_tree, vendor_id);
break;
case SUBMESSAGE_RTPS_DATA_BATCH:
dissect_RTPS_DATA_BATCH(tvb, pinfo, offset, flags, little_endian, octets_to_next_header,
rtps_submessage_tree, vendor_id, guid);
break;
case SUBMESSAGE_RTI_CRC:
if (vendor_id == RTPS_VENDOR_RTI_DDS) {
dissect_RTI_CRC(tvb, pinfo, offset, flags, little_endian, octets_to_next_header,
rtps_submessage_tree);
}
break;
case SUBMESSAGE_SECURE:
dissect_SECURE(tvb, pinfo, offset, flags, little_endian, octets_to_next_header,
rtps_submessage_tree, vendor_id);
break;
default:
return FALSE;
}
return TRUE;
}
static gboolean dissect_rtps_submessage_v1(tvbuff_t *tvb, packet_info *pinfo, gint offset, guint8 flags, gboolean little_endian,
guint8 submessageId, guint16 version, guint16 vendor_id, gint octets_to_next_header,
proto_tree *rtps_submessage_tree, proto_item *submessage_item,
endpoint_guid * guid)
{
switch (submessageId)
{
case SUBMESSAGE_PAD:
dissect_PAD(tvb, pinfo, offset, flags, little_endian, octets_to_next_header, rtps_submessage_tree);
break;
case SUBMESSAGE_DATA:
if (version < 0x0200) {
dissect_DATA_v1(tvb, pinfo, offset, flags, little_endian,
octets_to_next_header, rtps_submessage_tree);
} else {
dissect_DATA_v2(tvb, pinfo, offset, flags, little_endian,
octets_to_next_header, rtps_submessage_tree, vendor_id, guid);
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
static gboolean dissect_rtps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_item *ti;
proto_tree *rtps_tree, *rtps_submessage_tree;
guint8 submessageId, flags, majorRev;
guint16 version, vendor_id;
gboolean little_endian, is_ping;
gint next_submsg, octets_to_next_header;
int sub_hf;
const value_string *sub_vals;
endpoint_guid guid;
guint32 magic_number;
if (!tvb_bytes_exist(tvb, offset, 16))
return FALSE;
magic_number = tvb_get_ntohl(tvb, offset);
if (magic_number != RTPX_MAGIC_NUMBER &&
magic_number != RTPS_MAGIC_NUMBER) {
return FALSE;
}
majorRev = tvb_get_guint8(tvb,offset+4);
if ((majorRev != 1) && (majorRev != 2))
return FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTPS");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_rtps, tvb, 0, -1, ENC_NA);
rtps_tree = proto_item_add_subtree(ti, ett_rtps);
proto_tree_add_item(rtps_tree, hf_rtps_magic, tvb, 0, 4, ENC_NA | ENC_ASCII);
version = rtps_util_add_protocol_version(rtps_tree, tvb, offset+4);
vendor_id = rtps_util_add_vendor_id(rtps_tree, tvb, offset+6);
is_ping = rtps_is_ping(tvb, pinfo, offset+8);
if (!is_ping) {
if (version < 0x0200)
rtps_util_add_guid_prefix_v1(rtps_tree, tvb, offset+8,
hf_rtps_guid_prefix_v1, hf_rtps_host_id, hf_rtps_app_id,
hf_rtps_app_id_instance_id, hf_rtps_app_id_app_kind, NULL);
else
rtps_util_add_guid_prefix_v2(rtps_tree, tvb, offset+8, hf_rtps_guid_prefix_src,
hf_rtps_host_id, hf_rtps_app_id, hf_rtps_sm_instance_id, hf_rtps_guid_prefix);
guid.host_id = tvb_get_ntohl(tvb, offset+8);
guid.app_id = tvb_get_ntohl(tvb, offset+12);
guid.instance_id = tvb_get_ntohl(tvb, offset+16);
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
mapping_tree = proto_tree_add_subtree_format(rtps_tree, tvb, 0, 0,
ett_rtps_default_mapping, NULL, "Default port mapping: domainId=%d, "
"participantIdx=%d, nature=%s",
domain_id,
participant_idx,
val_to_str(nature, nature_type_vals, "%02x"));
} else {
mapping_tree = proto_tree_add_subtree_format(rtps_tree, tvb, 0, 0,
ett_rtps_default_mapping, NULL, "Default port mapping: %s, domainId=%d",
val_to_str(nature, nature_type_vals, "%02x"),
domain_id);
}
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
offset += ((version < 0x0200) ? 16 : 20);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
submessageId = tvb_get_guint8(tvb, offset);
if (version < 0x0200) {
sub_hf = hf_rtps_sm_id;
sub_vals = submessage_id_vals;
} else {
if ((submessageId & 0x80) && (vendor_id == RTPS_VENDOR_RTI_DDS)) {
sub_hf = hf_rtps_sm_idv2;
sub_vals = submessage_id_rti;
} else {
sub_hf = hf_rtps_sm_idv2;
sub_vals = submessage_id_valsv2;
}
}
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", val_to_str(submessageId, sub_vals, "Unknown[%02x]"));
if (submessageId & 0x80) {
if (vendor_id == RTPS_VENDOR_RTI_DDS) {
ti = proto_tree_add_uint_format_value(rtps_tree, sub_hf, tvb, offset, 1, submessageId, "%s",
val_to_str(submessageId, submessage_id_rti, "Vendor-specific (0x%02x)"));
} else {
ti = proto_tree_add_uint_format_value(rtps_tree, sub_hf, tvb, offset, 1,
submessageId, "Vendor-specific (0x%02x)", submessageId);
}
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
octets_to_next_header, rtps_submessage_tree, ti, &guid)) {
if ((version < 0x0200) ||
!dissect_rtps_submessage_v2(tvb, pinfo, offset, flags, little_endian, submessageId,
vendor_id, octets_to_next_header, rtps_submessage_tree, ti, &guid)) {
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
static gboolean dissect_rtps_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
return dissect_rtps(tvb, pinfo, tree, offset);
}
static gboolean dissect_rtps_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 4;
return dissect_rtps(tvb, pinfo, tree, offset);
}
static gboolean dissect_rtps_rtitcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
return dissect_rtps(tvb, pinfo, tree, offset);
}
static void
rtps_init(void)
{
if (enable_topic_info)
registry = wmem_map_new(wmem_file_scope(), hash_by_guid, compare_by_guid);
}
void proto_register_rtps(void) {
static hf_register_info hf[] = {
{ &hf_rtps_magic, {
"Magic",
"rtps.magic",
FT_STRING,
BASE_NONE,
NULL,
0,
"RTPS magic",
HFILL }
},
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
{ &hf_rtps_guid_prefix_v1,
{ "guidPrefix", "rtps.guidPrefix_v1",
FT_UINT64, BASE_HEX, NULL, 0,
"GuidPrefix of the RTPS packet", HFILL }
},
{ &hf_rtps_guid_prefix,
{ "guidPrefix", "rtps.guidPrefix",
FT_BYTES, BASE_NONE, NULL, 0,
"a generic guidPrefix that is transmitted inside the submessage (this is NOT the guidPrefix described in the packet header)", HFILL }
},
{ &hf_rtps_guid_prefix_src,
{ "guidPrefix", "rtps.guidPrefix.src",
FT_BYTES, BASE_NONE, NULL, 0,
"the guidPrefix of the entity sending the sample", HFILL }
},
{ &hf_rtps_guid_prefix_dst,
{ "guidPrefix", "rtps.guidPrefix.dst",
FT_BYTES, BASE_NONE, NULL, 0,
"the guidPrefix of the entity receiving the sample", HFILL }
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
{ &hf_rtps_sm_flags2, {
"Flags",
"rtps.sm.flags",
FT_UINT16,
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
{ &hf_rtps_sm_guid_prefix_v1, {
"guidPrefix",
"rtps.sm.guidPrefix_v1",
FT_UINT64,
BASE_HEX,
NULL,
0,
"a generic guidPrefix that is transmitted inside the submessage (this is NOT the guidPrefix described in the packet header)",
HFILL }
},
{ &hf_rtps_sm_guid_prefix, {
"guidPrefix",
"rtps.sm.guidPrefix",
FT_BYTES,
BASE_NONE,
NULL,
0,
"a generic guidPrefix that is transmitted inside the submessage (this is NOT the guidPrefix described in the packet header)",
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
{ &hf_rtps_sm_instance_id_v1, {
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
{ &hf_rtps_sm_instance_id, {
"instanceId",
"rtps.sm.guidPrefix.instanceId",
FT_UINT32,
BASE_HEX,
NULL,
0,
"instanceId component of the rtps.sm.guidPrefix",
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
{ &hf_rtps_parameter_id_inline_rti, {
"Parameter Id", "rtps.param.id", FT_UINT16,
BASE_HEX, VALS(parameter_id_inline_qos_rti), 0, NULL, HFILL }
},
{ &hf_rtps_parameter_id_toc, {
"parameterId",
"rtps.param.id",
FT_UINT16,
BASE_HEX,
VALS(parameter_id_toc_vals),
0,
"Parameter Id",
HFILL }
},
{ &hf_rtps_parameter_id_rti, {
"parameterId",
"rtps.param.id",
FT_UINT16,
BASE_HEX,
VALS(parameter_id_rti_vals),
0,
"Parameter Id",
HFILL }
},
{ &hf_rtps_parameter_id_pt, {
"parameterId",
"rtps.param.id",
FT_UINT16,
BASE_HEX,
VALS(parameter_id_pt_vals),
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
{ &hf_rtps_transportInfo_classId, {
"classID",
"rtps.transportInfo.classID",
FT_INT32,
BASE_DEC,
NULL,
0,
"Class ID of transport",
HFILL }
},
{ &hf_rtps_transportInfo_messageSizeMax, {
"messageSizeMax",
"rtps.transportInfo.messageSizeMax",
FT_INT32,
BASE_DEC,
NULL,
0,
"Maximum message size of transport",
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
{ &hf_rtps_logical_port,
{ "RTPS Logical Port", "rtps.locator.port",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_locator_public_address_port,
{ "Public Address Port", "rtps.locator.public_address_port",
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
{ &hf_rtps_acknack_count,
{ "Count", "rtps.acknack.count",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_ack_virtual_writer_count,
{ "virtualWriterCount", "rtps.app_ack.virtual_writer_count",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_ack_count,
{ "count", "rtps.app_ack.virtual_writer_count",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_ack_conf_virtual_writer_count,
{ "virtualWriterCount", "rtps.app_ack_conf.virtual_writer_count",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_ack_conf_count,
{ "count", "rtps.app_ack_conf.count",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_ack_interval_payload_length,
{ "intervalPayloadLength", "rtps.app_ack.interval_payload_length",
FT_INT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_ack_interval_flags,
{ "intervalFlags", "rtps.app_ack.interval_flags",
FT_INT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_ack_interval_count,
{ "intervalCount", "rtps.app_ack.interval_count",
FT_INT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_ack_octets_to_next_virtual_writer,
{ "octetsToNextVirtualWriter", "rtps.app_ack.octects_to_next_virtual_writer",
FT_INT16, BASE_DEC, NULL, 0,
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
{ &hf_rtps_direct_communication,
{ "Direct Communication", "rtps.direct_communication",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0,
NULL, HFILL }
},
{ &hf_rtps_expects_ack,
{ "expectsAck", "rtps.expects_ack",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0,
NULL, HFILL }
},
{ &hf_rtps_expects_virtual_heartbeat,
{ "expectsVirtualHB", "rtps.expects_virtual_heartbeat",
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
{ &hf_rtps_param_ntpt_sec, {
"seconds", "rtps.param.ntpTime.sec",
FT_INT32, BASE_DEC, NULL, 0,
"The 'second' component of a NTP time",
HFILL }
},
{ &hf_rtps_param_ntpt_fraction, {
"fraction", "rtps.param.ntpTime.fraction",
FT_UINT32, BASE_DEC, NULL, 0,
"The 'fraction' component of a NTP time",
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
{ &hf_rtps_param_peer_host_epoch,
{ "Peer Host Epoch", "rtps.param.peer_host_epoch",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_endpoint_property_change_epoch,
{ "Endpoint Property Change Epoch", "rtps.param.endpoint_property_change_epoch",
FT_INT64, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_param_entity_name,
{ "entityName", "rtps.param.entityName",
FT_STRINGZ, BASE_NONE, NULL, 0,
"String representing the name of the entity addressed by the submessage",
HFILL }
},
{ &hf_rtps_param_role_name,
{ "roleName", "rtps.param.roleName",
FT_STRINGZ, BASE_NONE, NULL, 0,
"String representing the role name of the entity addressed by the submessage",
HFILL }
},
{ &hf_rtps_disable_positive_ack,
{ "disablePositiveAcks", "rtps.disable_positive_ack",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0,
NULL, HFILL }
},
{ &hf_rtps_participant_guid_v1,
{ "Participant GUID", "rtps.param.participant_guid_v1",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_participant_guid,
{ "Participant GUID", "rtps.param.participant_guid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_group_guid,
{ "Group GUID", "rtps.param.group_guid",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_endpoint_guid,
{ "Endpoint GUID", "rtps.param.endpoint_guid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_host_id,
{ "hostId", "rtps.param.guid.hostId",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_app_id,
{ "appId", "rtps.param.guid.appId",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_instance_id_v1,
{ "instanceId", "rtps.param.guid.instanceId",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_instance_id,
{ "instanceId", "rtps.param.guid.instanceId",
FT_UINT32, BASE_HEX, NULL, 0,
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
{ &hf_rtps_param_extended_pid_length,
{ "Extended Length", "rtps.param.extended_pid_length",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_param_extended_parameter,
{ "Extended Parameter", "rtps.param.extended_parameter",
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
{ &hf_rtps_virtual_heartbeat_count,
{ "Count", "rtps.virtual_heartbeat.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_virtual_heartbeat_num_virtual_guids,
{ "numVirtualGUIDs", "rtps.virtual_heartbeat.num_virtual_guids",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_virtual_heartbeat_num_writers,
{ "numWriters", "rtps.virtual_heartbeat.num_virtual_guids",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_data_serialize_data, {
"serializedData", "rtps.data.serialize_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_parameter_data, {
"parameterData", "rtps.parameter_data",
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
{ "bitmapBase", "rtps.fragment_number.base64",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_fragment_number_base,
{ "bitmapBase", "rtps.fragment_number.base32",
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
{ &hf_rtps_acknack_analysis,
{ "Acknack Analysis", "rtps.sm.acknack_analysis",
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
{ &hf_rtps_param_builtin_endpoint_set_flags,
{ "Flags", "rtps.param.builtin_endpoint_set",
FT_UINT32, BASE_HEX, NULL, 0,
"bitmask representing the flags in PID_BUILTIN_ENDPOINT_SET",
HFILL }
},
{ &hf_rtps_param_vendor_builtin_endpoint_set_flags,
{ "Flags", "rtps.param.vendor_builtin_endpoint_set",
FT_UINT32, BASE_HEX, NULL, 0,
"bitmask representing the flags in PID_VENDOR_BUILTIN_ENDPOINT_SET",
HFILL }
},
{ &hf_rtps_param_plugin_promiscuity_kind, {
"promiscuityKind", "rtps.param.plugin_promiscuity_kind",
FT_UINT32, BASE_HEX, VALS(plugin_promiscuity_kind_vals), 0, NULL, HFILL }
},
{ &hf_rtps_param_service_kind, {
"serviceKind", "rtps.param.service_kind",
FT_UINT32, BASE_HEX, VALS(service_kind_vals), 0, NULL, HFILL }
},
{ &hf_rtps_param_type_consistency_kind, {
"Type Consistency Kind", "rtps.param.type_consistency_kind",
FT_UINT16, BASE_HEX, VALS(type_consistency_kind_vals), 0, NULL, HFILL }
},
{ &hf_rtps_param_acknowledgment_kind, {
"Acknowledgment Kind", "rtps.param.acknowledgment_kind",
FT_UINT32, BASE_HEX, VALS(acknowledgement_kind_vals), 0, NULL, HFILL }
},
{ &hf_rtps_issue_data, {
"serializedData", "rtps.issueData",
FT_BYTES, BASE_NONE, NULL, 0, "The user data transferred in a ISSUE submessage", HFILL }
},
{ &hf_rtps_param_product_version_major, {
"Major", "rtps.param.product_version.major",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_param_product_version_minor, {
"Minor", "rtps.param.product_version.minor",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_param_product_version_release, {
"Release", "rtps.param.product_version.release",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_param_product_version_release_as_char, {
"Release", "rtps.param.product_version.release_string",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_param_product_version_revision, {
"Revision", "rtps.param.product_version.revision",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_encapsulation_id, {
"encapsulation id", "rtps.encapsulation_id",
FT_UINT16, BASE_HEX, VALS(encapsulation_id_vals), 0, NULL, HFILL }
},
{ &hf_rtps_encapsulation_kind, {
"kind", "rtps.encapsulation_kind",
FT_UINT16, BASE_HEX, VALS(participant_message_data_kind), 0, NULL, HFILL }
},
{ &hf_rtps_octets_to_inline_qos, {
"Octets to inline QoS", "rtps.octets_to_inline_qos",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_filter_signature, {
"filterSignature", "rtps.filter_signature",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_bitmap, {
"bitmap", "rtps.bitmap",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_property_name, {
"Property Name", "rtps.property_name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_property_value, {
"Value", "rtps.property_value",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_union, {
"union", "rtps.union",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_union_case, {
"case", "rtps.union_case",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_struct, {
"struct", "rtps.struct",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_member_name, {
"member_name", "rtps.member_name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_sequence, {
"sequence", "rtps.sequence",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_array, {
"array", "rtps.array",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_bitfield, {
"bitfield", "rtps.bitfield",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_datatype, {
"datatype", "rtps.datatype",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_sequence_size, {
"sequenceSize", "rtps.sequence_size",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_guid, {
"guid", "rtps.guid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_heartbeat_count, {
"count", "rtps.heartbeat_count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_encapsulation_options, {
"Encapsulation options", "rtps.encapsulation_options",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_serialized_key, {
"serializedKey", "rtps.serialized_key",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_serialized_data, {
"serializedData", "rtps.serialized_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_sm_rti_crc_number, {
"RTPS Message Length", "rtps.sm.rti_crc.message_length",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_sm_rti_crc_result, {
"CRC", "rtps.sm.rti_crc",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_flag_reserved80, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80, NULL, HFILL }
},
{ &hf_rtps_flag_reserved40, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x40, NULL, HFILL }
},
{ &hf_rtps_flag_reserved20, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x20, NULL, HFILL }
},
{ &hf_rtps_flag_reserved10, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x10, NULL, HFILL }
},
{ &hf_rtps_flag_reserved08, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x08, NULL, HFILL }
},
{ &hf_rtps_flag_reserved04, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04, NULL, HFILL }
},
{ &hf_rtps_flag_reserved02, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }
},
{ &hf_rtps_flag_reserved8000, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x8000, NULL, HFILL }
},
{ &hf_rtps_flag_reserved4000, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x4000, NULL, HFILL }
},
{ &hf_rtps_flag_reserved2000, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x2000, NULL, HFILL }
},
{ &hf_rtps_flag_reserved1000, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x1000, NULL, HFILL }
},
{ &hf_rtps_flag_reserved0800, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0800, NULL, HFILL }
},
{ &hf_rtps_flag_reserved0400, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0400, NULL, HFILL }
},
{ &hf_rtps_flag_reserved0200, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0200, NULL, HFILL }
},
{ &hf_rtps_flag_reserved0100, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0100, NULL, HFILL }
},
{ &hf_rtps_flag_reserved0080, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0080, NULL, HFILL }
},
{ &hf_rtps_flag_reserved0040, {
"Reserved", "rtps.flag.reserved",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0040, NULL, HFILL }
},
{ &hf_rtps_flag_unregister, {
"Unregister flag", "rtps.flag.unregister",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x20, NULL, HFILL }
},
{ &hf_rtps_flag_inline_qos_v1, {
"Inline QoS", "rtps.flag.inline_qos",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x10, NULL, HFILL }
},
{ &hf_rtps_flag_hash_key, {
"Hash key flag", "rtps.flag.hash_key",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x08, NULL, HFILL }
},
{ &hf_rtps_flag_hash_key_rti, {
"Hash key flag", "rtps.flag.hash_key",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04, NULL, HFILL }
},
{ &hf_rtps_flag_alive, {
"Alive flag", "rtps.flag.alive",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04, NULL, HFILL }
},
{ &hf_rtps_flag_data_present_v1, {
"Data present", "rtps.flag.data_present",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }
},
{ &hf_rtps_flag_multisubmessage, {
"Multi-submessage", "rtps.flag.multisubmessage",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }
},
{ &hf_rtps_flag_endianness, {
"Endianness bit", "rtps.flag.endianness",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x01, NULL, HFILL }
},
{ &hf_rtps_flag_inline_qos_v2, {
"Inline QoS", "rtps.flag.inline_qos",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }
},
{ &hf_rtps_flag_data_present_v2, {
"Data present", "rtps.flag.data_present",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04, NULL, HFILL }
},
{ &hf_rtps_flag_status_info, {
"Status info flag", "rtps.flag.status_info",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x10, NULL, HFILL }
},
{ &hf_rtps_flag_final, {
"Final flag", "rtps.flag.final",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }
},
{ &hf_rtps_flag_liveliness, {
"Liveliness flag", "rtps.flag.liveliness",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04, NULL, HFILL }
},
{ &hf_rtps_flag_multicast, {
"Multicast flag", "rtps.flag.multicast",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }
},
{ &hf_rtps_flag_data_serialized_key, {
"Serialized Key", "rtps.flag.data.serialized_key",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x08, NULL, HFILL }
},
{ &hf_rtps_flag_data_frag_serialized_key, {
"Serialized Key", "rtps.flag.data_frag.serialized_key",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04, NULL, HFILL }
},
{ &hf_rtps_flag_timestamp, {
"Timestamp flag", "rtps.flag.timestamp",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }
},
{ &hf_rtps_flag_no_virtual_guids, {
"No virtual GUIDs flag", "rtps.flag.no_virtual_guids",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x08, NULL, HFILL }
},
{ &hf_rtps_flag_multiple_writers, {
"Multiple writers flag", "rtps.flag.multiple_writers",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04, NULL, HFILL }
},
{ &hf_rtps_flag_multiple_virtual_guids, {
"Multiple virtual GUIDs flag", "rtps.flag.multiple_virtual_guids",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02, NULL, HFILL }
},
{ &hf_rtps_flag_serialize_key16, {
"Serialized Key", "rtps.flag.serialize_key",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0020, NULL, HFILL }
},
{ &hf_rtps_flag_invalid_sample, {
"Invalid sample", "rtps.flag.invalid_sample",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0010, NULL, HFILL }
},
{ &hf_rtps_flag_data_present16, {
"Data present", "rtps.flag.data_present",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0008, NULL, HFILL }
},
{ &hf_rtps_flag_offsetsn_present, {
"OffsetSN present", "rtps.flag.offsetsn_present",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0004, NULL, HFILL }
},
{ &hf_rtps_flag_inline_qos16_v2, {
"Inline QoS", "rtps.flag.inline_qos",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0002, NULL, HFILL }
},
{ &hf_rtps_flag_timestamp_present, {
"Timestamp present", "rtps.flag.offsetsn_present",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0001, NULL, HFILL }
},
{ &hf_rtps_param_status_info_flags,
{ "Flags", "rtps.param.status_info",
FT_UINT32, BASE_HEX, NULL, 0, "bitmask representing the flags in PID_STATUS_INFO", HFILL }
},
{ &hf_rtps_flag_unregistered, {
"Unregistered", "rtps.flag.unregistered",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x0002, NULL, HFILL }
},
{ &hf_rtps_flag_disposed, {
"Disposed", "rtps.flag.undisposed",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x0001, NULL, HFILL }
},
{ &hf_rtps_flag_participant_announcer, {
"Participant Announcer", "rtps.flag.participant_announcer",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001, NULL, HFILL }
},
{ &hf_rtps_flag_participant_detector, {
"Participant Detector", "rtps.flag.participant_detector",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002, NULL, HFILL }
},
{ &hf_rtps_flag_publication_announcer, {
"Publication Announcer", "rtps.flag.publication_announcer",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004, NULL, HFILL }
},
{ &hf_rtps_flag_publication_detector, {
"Publication Detector", "rtps.flag.publication_detector",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008, NULL, HFILL }
},
{ &hf_rtps_flag_subscription_announcer, {
"Subscription Announcer", "rtps.flag.subscription_announcer",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000010, NULL, HFILL }
},
{ &hf_rtps_flag_subscription_detector, {
"Subscription Detector", "rtps.flag.subscription_detector",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000020, NULL, HFILL }
},
{ &hf_rtps_flag_participant_proxy_announcer, {
"Participant Proxy Announcer", "rtps.flag.participant_proxy_announcer",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000040, NULL, HFILL }
},
{ &hf_rtps_flag_participant_proxy_detector, {
"Participant Proxy Detector", "rtps.flag.participant_proxy_detector",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000080, NULL, HFILL }
},
{ &hf_rtps_flag_participant_state_announcer, {
"Participant State Announcer", "rtps.flag.participant_state_announcer",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000100, NULL, HFILL }
},
{ &hf_rtps_flag_participant_state_detector, {
"Participant State Detector", "rtps.flag.participant_state_detector",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000200, NULL, HFILL }
},
{ &hf_rtps_flag_participant_message_datawriter, {
"Participant Message DataWriter", "rtps.flag.participant_message_datawriter",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000400, NULL, HFILL }
},
{ &hf_rtps_flag_participant_message_datareader, {
"Participant Message DataReader", "rtps.flag.participant_message_datareader",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000800, NULL, HFILL }
},
{ &hf_rtps_type_object_type_id_disc,
{ "TypeId (_d)", "rtps.type_object.type_id.discr",
FT_INT16, BASE_DEC, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_primitive_type_id,
{ "Type Id", "rtps.type_object.primitive_type_id",
FT_UINT16, BASE_HEX, VALS(type_object_kind), 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_base_primitive_type_id,
{ "Base Id", "rtps.type_object.base_primitive_type_id",
FT_UINT16, BASE_HEX, VALS(type_object_kind), 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_type_id,
{ "Type Id", "rtps.type_object.type_id",
FT_UINT64, BASE_HEX, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_base_type,
{ "Base Type Id", "rtps.type_object.base_type_id",
FT_UINT64, BASE_HEX, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_element_raw, {
"Type Element Content", "rtps.type_object.element",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_type_property_name,
{ "Name", "rtps.type_object.property.name",
FT_STRING, BASE_NONE, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_member_id,
{ "Member Id", "rtps.type_object.annotation.member_id",
FT_UINT32, BASE_DEC, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_name,
{ "Name", "rtps.type_object.member.name",
FT_STRING, BASE_NONE, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_annotation_value_d,
{ "Annotation Member (_d)", "rtps.type_object.annotation.value_d",
FT_UINT16, BASE_DEC, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_annotation_value_16,
{ "16 bits type", "rtps.type_object.annotation.value",
FT_UINT16, BASE_DEC, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_bound,
{ "Bound", "rtps.type_object.bound",
FT_UINT32, BASE_DEC, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_enum_constant_name,
{ "Enum name", "rtps.type_object.enum.name",
FT_STRING, BASE_NONE, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_enum_constant_value,
{ "Enum value", "rtps.type_object.enum.value",
FT_INT32, BASE_DEC, 0x0, 0,
NULL, HFILL }
},
{ &hf_rtps_type_object_element_shared,
{ "Element shared", "rtps.type_object.shared",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0,
NULL, HFILL }
},
{ &hf_rtps_flag_typeflag_final, {
"FINAL", "rtps.flag.typeflags.final",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0001, NULL, HFILL }
},
{ &hf_rtps_flag_typeflag_mutable, {
"MUTABLE", "rtps.flag.typeflags.mutable",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0002, NULL, HFILL }
},
{ &hf_rtps_flag_typeflag_nested, {
"NESTED", "rtps.flag.typeflags.nested",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0004, NULL, HFILL }
},
{ &hf_rtps_type_object_flags, {
"Flags", "rtps.flag.typeflags",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_flag_memberflag_key, {
"Key", "rtps.flag.typeflags.key",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0001, NULL, HFILL }
},
{ &hf_rtps_flag_memberflag_optional, {
"Optional", "rtps.flag.typeflags.key",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0002, NULL, HFILL }
},
{ &hf_rtps_flag_memberflag_shareable, {
"Shareable", "rtps.flag.typeflags.key",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0004, NULL, HFILL }
},
{ &hf_rtps_flag_memberflag_union_default, {
"Union default", "rtps.flag.typeflags.key",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0008, NULL, HFILL }
},
{ &hf_rtps_type_object_element_module_name,
{ "Module name", "rtps.type_object.module_name",
FT_STRINGZ, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_flag_service_request_writer, {
"Service Request Writer", "rtps.flag.service_request_writer",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001, NULL, HFILL }
},
{ &hf_rtps_flag_service_request_reader, {
"Service Request Reader", "rtps.flag.service_request_reader",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002, NULL, HFILL }
},
{ &hf_rtps_flag_locator_ping_writer, {
"Locator Ping Writer", "rtps.flag.locator_ping_writer",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004, NULL, HFILL }
},
{ &hf_rtps_flag_locator_ping_reader, {
"Locator Ping Reader", "rtps.flag.locator_ping_reader",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008, NULL, HFILL }
},
{ &hf_rtps_param_enable_authentication,
{ "Authentication enabled", "rtps.secure.enable_authentication",
FT_BOOLEAN, 32, TFS(&tfs_true_false), 0, NULL, HFILL }
},
{ &hf_rtps_param_enable_encryption,
{ "Encryption enabled", "rtps.secure.enable_encryption",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0, NULL, HFILL }
},
{ &hf_rtps_srm_service_id,
{ "Service Id", "rtps.srm.service_id",
FT_INT32, BASE_DEC, VALS(service_request_kind), 0, NULL, HFILL }
},
{ &hf_rtps_srm_request_body, {
"Request Body", "rtps.srm.request_body",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_srm_instance_id, {
"Instance Id", "rtps.srm.instance_id",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_topic_query_selection_filter_class_name,
{ "Class Name", "rtps.srm.topic_query.class_name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_topic_query_selection_filter_expression,
{ "Filter Expression", "rtps.srm.topic_query.filter_expression",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_topic_query_selection_filter_parameter,
{ "Filter Parameter", "rtps.srm.topic_query.filter_parameter",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_topic_query_selection_num_parameters,
{ "Number of Filter Parameters", "rtps.srm.topic_query.num_filter_parameters",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_topic_query_topic_name,
{ "Topic Name", "rtps.srm.topic_query.topic_name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_topic_query_original_related_reader_guid,
{ "Original Related Reader GUID", "rtps.srm.topic_query.original_related_reader_guid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_secure_transformation_id,
{ "Transformation Id", "rtps.secure.transformation_id",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_secure_ciphertext,
{ "Ciphertext", "rtps.secure.ciphertext",
FT_BYTES, BASE_NONE, NULL, 0, "The user data transferred in a secure payload", HFILL }
},
{ &hf_rtps_pgm, {
"Participant Generic Message", "rtps.pgm",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x0, NULL, HFILL }
},
{ &hf_rtps_srm, {
"Service Request Message", "rtps.srm",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x0, NULL, HFILL }
},
{ &hf_rtps_pgm_dst_participant_guid,
{ "Destination Participant GUID", "rtps.pgm.dst_participant_guid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_source_participant_guid,
{ "Source Participant GUID", "rtps.pgm.source_participant_guid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_pgm_dst_endpoint_guid,
{ "Destination Endpoint GUID", "rtps.pgm.dst_endpoint_guid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_pgm_src_endpoint_guid,
{ "Source Endpoint GUID", "rtps.pgm.src_endpoint_guid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_message_identity_source_guid,
{ "Source GUID", "rtps.pgm.message_identity.source_guid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_pgm_message_class_id,
{ "Message class id", "rtps.pgm.data_holder.message_class_id",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_pgm_data_holder_class_id,
{ "Class Id", "rtps.pgm.data_holder.class_id",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_pgm_data_holder_stringseq_size,
{ "Size", "rtps.pgm.data_holder.string_seq_size",
FT_INT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_pgm_data_holder_stringseq_name,
{ "Name", "rtps.pgm.data_holder.string_seq_name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_pgm_data_holder_long_long,
{ "Long long", "rtps.pgm.data_holder.long_long",
FT_INT64, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_rtps_param_topic_query_publication_enable,
{ "Enable", "rtps.param.topic_query_publication_enable",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0, NULL, HFILL }
},
{ &hf_rtps_param_topic_query_publication_sessions,
{ "Number of sessions", "rtps.param.topic_query_publication_sessions",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_rtps,
&ett_rtps_default_mapping,
&ett_rtps_proto_version,
&ett_rtps_product_version,
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
&ett_rtps_sample_batch_list,
&ett_rtps_locator_filter_locator,
&ett_rtps_writer_heartbeat_virtual_list,
&ett_rtps_writer_heartbeat_virtual,
&ett_rtps_virtual_guid_heartbeat_virtual_list,
&ett_rtps_virtual_guid_heartbeat_virtual,
&ett_rtps_app_ack_virtual_writer_list,
&ett_rtps_app_ack_virtual_writer,
&ett_rtps_app_ack_virtual_writer_interval_list,
&ett_rtps_app_ack_virtual_writer_interval,
&ett_rtps_transport_info,
&ett_rtps_property_list,
&ett_rtps_property,
&ett_rtps_topic_info,
&ett_rtps_type_object,
&ett_rtps_type_library,
&ett_rtps_type_element,
&ett_rtps_type_annotation_usage_list,
&ett_rtps_type_enum_constant,
&ett_rtps_type_bound_list,
&ett_rtps_secure_payload_tree,
&ett_rtps_pgm_data,
&ett_rtps_message_identity,
&ett_rtps_related_message_identity,
&ett_rtps_data_holder_seq,
&ett_rtps_data_holder,
&ett_rtps_data_holder_properties,
&ett_rtps_property_tree,
&ett_rtps_param_header_tree,
&ett_rtps_custom_dissection_info,
&ett_rtps_service_request_tree,
&ett_rtps_locator_ping_tree,
&ett_rtps_locator_reachability_tree,
&ett_rtps_locator_list_tree,
&ett_rtps_topic_query_tree,
&ett_rtps_topic_query_selection_tree,
&ett_rtps_topic_query_filter_params_tree,
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
{ &ei_rtps_unsupported_non_builtin_param_seq, { "rtps.unsupported_non_builtin_param_seq", PI_PROTOCOL, PI_WARN, "Unsupported non-builtin parameter sequence", EXPFILL }},
};
module_t *rtps_module;
expert_module_t *expert_rtps;
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
prefs_register_bool_preference(rtps_module, "enable_topic_info",
"Enable Topic Information feature",
"Shows the Topic Name and Type Name of the samples.",
&enable_topic_info);
register_init_routine(rtps_init);
rtps_type_name_table = register_dissector_table("rtps.type_name", "RTPS Type Name",
proto_rtps, FT_STRING, BASE_NONE, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
void proto_reg_handoff_rtps(void) {
heur_dissector_add("rtitcp", dissect_rtps_rtitcp, "RTPS over RTITCP", "rtps_rtitcp", proto_rtps, HEURISTIC_ENABLE);
heur_dissector_add("udp", dissect_rtps_udp, "RTPS over UDP", "rtps_udp", proto_rtps, HEURISTIC_ENABLE);
heur_dissector_add("tcp", dissect_rtps_tcp, "RTPS over TCP", "rtps_tcp", proto_rtps, HEURISTIC_ENABLE);
}
