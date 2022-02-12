static struct SMCounterRecord * sm_counter_add(
struct SMCounterRecord *last,
guint8 submessage,
const char * const extra) {
#if 0
if ((last == NULL) || (last->id != submessage)) {
struct SMCounterRecord *ptr;
ptr = (struct SMCounterRecord *)g_malloc(sizeof(struct SMCounterRecord));
if (ptr == NULL) {
return NULL;
}
ptr->id = submessage;
ptr->counter = 1;
ptr->next = NULL;
if (last) {
last->next = ptr;
}
return ptr;
}
last->counter++;
#endif
struct SMCounterRecord *ptr;
ptr = (struct SMCounterRecord *)g_malloc(sizeof(struct SMCounterRecord));
if (ptr == NULL) {
return NULL;
}
ptr->id = submessage;
ptr->extra = extra;
ptr->next = NULL;
if (last) {
last->next = ptr;
}
return ptr;
}
static void sm_counter_free(struct SMCounterRecord *head) {
struct SMCounterRecord *ptr;
while (head != NULL) {
ptr = head->next;
g_free(head);
head = ptr;
}
}
static void rtps_util_format_ipv6(guint8 *addr,
guint8 *buffer,
gint buffer_size) {
guint32 i;
guint8 temp[5];
buffer[0] = '\0';
for (i = 0; i < 16; i+=2) {
g_snprintf(temp, 5, "%02x%02x", addr[i], addr[i+1]);
if (temp[0] == '0') {
if (temp[1] == '0') {
if (temp[2] == '0') {
g_strlcat(buffer, &temp[3], buffer_size);
} else {
g_strlcat(buffer, &temp[2], buffer_size);
}
} else {
g_strlcat(buffer, &temp[1], buffer_size);
}
} else {
g_strlcat(buffer, temp, buffer_size);
}
if (i < 14) {
g_strlcat(buffer, ":", buffer_size);
}
}
}
static void rtps_util_add_protocol_version(proto_tree *tree,
tvbuff_t * tvb,
gint offset) {
proto_item * ti;
proto_tree * version_tree;
ti = proto_tree_add_none_format(tree,
hf_rtps_protocol_version,
tvb,
offset,
2,
"Protocol version: %d.%d",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset+1));
version_tree = proto_item_add_subtree(ti,
ett_rtps_proto_version);
proto_tree_add_item(version_tree,
hf_rtps_protocol_version_major,
tvb,
offset,
1,
ENC_BIG_ENDIAN);
proto_tree_add_item(version_tree,
hf_rtps_protocol_version_minor,
tvb,
offset+1,
1,
ENC_BIG_ENDIAN);
}
static void rtps_util_add_vendor_id(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
guint8 * buffer,
gint buffer_size) {
guint8 major, minor;
guint32 vendor_id = 0;
guint8 vendor_name[MAX_VENDOR_ID_SIZE];
major = tvb_get_guint8(tvb, offset);
minor = tvb_get_guint8(tvb, offset+1);
vendor_id = (major<<8) | minor;
switch(vendor_id) {
case RTPS_VENDOR_UNKNOWN:
g_strlcpy(vendor_name, RTPS_VENDOR_UNKNOWN_STRING, MAX_VENDOR_ID_SIZE);
break;
case RTPS_VENDOR_RTI:
g_strlcpy(vendor_name, RTPS_VENDOR_RTI_STRING, MAX_VENDOR_ID_SIZE);
break;
default:
g_snprintf(vendor_name, MAX_VENDOR_ID_SIZE, "%d.%d", major, minor);
}
if (tree != NULL) {
proto_tree_add_uint_format(tree,
hf_rtps_vendor_id,
tvb,
offset,
2,
vendor_id,
"vendor: %s",
vendor_name);
}
if (buffer != NULL) {
g_strlcpy(buffer, vendor_name, buffer_size);
}
}
static void rtps_util_add_locator_t(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
const guint8 * label,
guint8 * buffer,
gint buffer_size) {
proto_item * ti;
proto_tree * locator_tree;
gint32 kind;
guint8 addr[16];
guint32 port;
char temp_buff[MAX_LOCATOR_SIZE];
char addr_buff[MAX_IPV6_SIZE];
const char *kind_string = NULL;
int i;
kind = NEXT_guint32(tvb, offset, little_endian);
port = NEXT_guint32(tvb, offset+4, little_endian);
for (i = 0; i < 16; ++i) {
addr[i] = tvb_get_guint8(tvb, offset + 8 + i);
}
switch(kind) {
case LOCATOR_KIND_UDPV4:
kind_string = "LOCATOR_KIND_UDPV4";
g_snprintf(addr_buff, MAX_IPV6_SIZE,
"%d.%d.%d.%d",
addr[12],
addr[13],
addr[14],
addr[15]);
g_snprintf(temp_buff, MAX_LOCATOR_SIZE, "%s:%d",
addr_buff,
port);
break;
case LOCATOR_KIND_UDPV6:
kind_string = "LOCATOR_KIND_UDPV6";
rtps_util_format_ipv6(addr, &addr_buff[0], MAX_IPV6_SIZE);
g_snprintf(temp_buff, MAX_LOCATOR_SIZE,
"IPv6: { addr=%s, port=%d }",
addr_buff,
port);
break;
case LOCATOR_KIND_INVALID:
kind_string = "LOCATOR_KIND_INVALID";
case LOCATOR_KIND_RESERVED:
if (!kind_string)
kind_string = "LOCATOR_KIND_RESERVED";
default:
if (!kind_string)
kind_string = "(unknown)";
g_snprintf(temp_buff, MAX_LOCATOR_SIZE,
"{ kind=%02x, port=%d, addr=%02x %02x %02x ... %02x %02x }",
kind,
port,
addr[0],
addr[1],
addr[2],
addr[14],
addr[15]);
}
ti = proto_tree_add_text(tree,
tvb,
offset,
24,
"%s: %s",
label,
temp_buff);
locator_tree = proto_item_add_subtree(ti,
ett_rtps_locator);
proto_tree_add_text(locator_tree,
tvb,
offset,
4,
"kind: %02x (%s)",
kind,
kind_string);
proto_tree_add_text(locator_tree,
tvb,
offset+4,
4,
"port: %d%s",
port,
(port == 0) ? " (PORT_INVALID)" : "");
proto_tree_add_text(locator_tree,
tvb,
offset + 8,
16,
"address: %s",
addr_buff);
if (buffer) {
g_strlcpy(buffer, temp_buff, buffer_size);
}
}
static void rtps_util_add_locator_list(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
const guint8 * label,
gboolean little_endian) {
proto_item *ti;
proto_tree *locator_tree;
guint32 num_locators;
num_locators = NEXT_guint32(tvb, offset, little_endian);
ti = proto_tree_add_text(tree,
tvb,
offset,
4,
"%s: %d Locators",
label,
num_locators);
if (num_locators > 0) {
guint32 i;
char temp_buff[20];
locator_tree = proto_item_add_subtree(ti,
ett_rtps_locator_udp_v4);
for (i = 0; i < num_locators; ++i) {
g_snprintf(temp_buff, 20, "Locator[%d]", i);
rtps_util_add_locator_t(locator_tree,
tvb,
offset + 4 + (i * 24),
little_endian,
temp_buff,
NULL,
0);
}
}
}
static void rtps_util_add_ipv4_address_t(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
const guint8 * label,
guint8 * buffer,
gint buffer_size) {
guint32 addr;
addr = NEXT_guint32(tvb, offset, little_endian);
if (addr == IPADDRESS_INVALID) {
if (buffer) {
g_strlcpy(buffer, IPADDRESS_INVALID_STRING, buffer_size);
}
if (tree) {
proto_tree_add_text(tree,
tvb,
offset,
4,
"%s: %s",
label,
IPADDRESS_INVALID_STRING);
}
} else {
if (buffer) {
g_snprintf(buffer, buffer_size,
"%d.%d.%d.%d",
(addr >> 24) & 0xff,
(addr >> 16) & 0xff,
(addr >> 8) & 0xff,
addr & 0xff);
}
if (tree) {
proto_tree_add_text(tree,
tvb,
offset,
4,
"%s: %d.%d.%d.%d",
label,
(addr >> 24) & 0xff,
(addr >> 16) & 0xff,
(addr >> 8) & 0xff,
addr & 0xff);
}
}
}
static void rtps_util_add_locator_udp_v4(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
const guint8 * label,
gboolean little_endian) {
proto_item * ti;
proto_tree * locator_tree;
guint32 port;
char portLabel[MAX_PORT_SIZE];
char addr[MAX_IPV4_ADDRESS_SIZE];
port = NEXT_guint32(tvb, offset+4, little_endian);
if (port == PORT_INVALID) {
g_snprintf(portLabel, MAX_PORT_SIZE, "%s (0x00000000)", PORT_INVALID_STRING);
} else {
g_snprintf(portLabel, MAX_PORT_SIZE, "%u", port);
}
ti = proto_tree_add_text(tree,
tvb,
offset,
8,
"addr");
locator_tree = proto_item_add_subtree(ti, ett_rtps_locator_udp_v4);
rtps_util_add_ipv4_address_t(locator_tree,
tvb,
offset,
little_endian,
"address",
addr,
MAX_IPV4_ADDRESS_SIZE);
proto_tree_add_text(locator_tree,
tvb,
offset + 4,
4,
"port: %s",
portLabel);
proto_item_set_text(ti, "%s: { address=%s, port=%s }",
label,
addr,
portLabel);
}
static void rtps_util_add_guid_prefix(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
int hf_prefix,
int hf_host_id,
int hf_app_id,
int hf_app_id_instance_id,
int hf_app_id_app_kind,
const guint8 * label,
guint8 * buffer,
gint buffer_size) {
guint32 host_id;
guint32 app_id;
guint32 instance_id;
guint8 app_kind;
guint8 * temp_buff;
guint8 guid_prefix[8];
const guint8 * safe_label;
int i;
safe_label = (label == NULL) ? (const guint8 *)"guidPrefix" : label;
host_id = tvb_get_ntohl(tvb, offset);
app_id = tvb_get_ntohl(tvb, offset + 4);
for (i = 0; i < 8; ++i) {
guid_prefix[i] = tvb_get_guint8(tvb, offset+i);
}
instance_id = (app_id >> 8);
app_kind = (app_id & 0xff);
temp_buff = (guint8 *)ep_alloc(MAX_GUID_PREFIX_SIZE);
g_snprintf(temp_buff, MAX_GUID_PREFIX_SIZE,
"%s=%02x%02x%02x%02x %02x%02x%02x%02x"
" { hostId=%08x, appId=%08x"
" (%s: %06x) }",
safe_label,
guid_prefix[0],
guid_prefix[1],
guid_prefix[2],
guid_prefix[3],
guid_prefix[4],
guid_prefix[5],
guid_prefix[6],
guid_prefix[7],
host_id,
app_id,
val_to_str(app_kind, app_kind_vals, "%02x"),
instance_id);
if (tree != NULL) {
proto_item * ti, *hidden_item;
proto_tree * guid_tree;
proto_tree * appid_tree;
hidden_item = proto_tree_add_item(tree,
hf_prefix,
tvb,
offset,
8,
ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
ti = proto_tree_add_text(tree,
tvb,
offset,
8, "%s",
temp_buff);
guid_tree = proto_item_add_subtree(ti,
ett_rtps_guid_prefix);
proto_tree_add_item(guid_tree,
hf_host_id,
tvb,
offset,
4,
ENC_BIG_ENDIAN);
ti = proto_tree_add_item(guid_tree,
hf_app_id,
tvb,
offset+4,
4,
ENC_BIG_ENDIAN);
appid_tree = proto_item_add_subtree(ti,
ett_rtps_app_id);
proto_tree_add_item(appid_tree,
hf_app_id_instance_id,
tvb,
offset+4,
3,
ENC_BIG_ENDIAN);
proto_tree_add_item(appid_tree,
hf_app_id_app_kind,
tvb,
offset+7,
1,
ENC_BIG_ENDIAN);
}
if (buffer != NULL) {
g_strlcpy(buffer, temp_buff, buffer_size);
}
}
static int rtps_util_add_entity_id(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
int hf_item,
int hf_item_entity_key,
int hf_item_entity_kind,
int subtree_entity_id,
const char *label,
guint32 * entity_id_out) {
guint32 entity_id = tvb_get_ntohl(tvb, offset);
guint32 entity_key = (entity_id >> 8);
guint8 entity_kind = (entity_id & 0xff);
const char *str_predef = match_strval(entity_id, entity_id_vals);
if (entity_id_out != NULL) {
*entity_id_out = entity_id;
}
if (tree != NULL) {
proto_tree * entity_tree;
proto_item * ti;
if (str_predef == NULL) {
ti = proto_tree_add_uint_format(tree,
hf_item,
tvb,
offset,
4,
entity_id,
"%s: 0x%08x (%s: 0x%06x)",
label,
entity_id,
val_to_str(entity_kind, entity_kind_vals,
"unknown (%02x)"),
entity_key);
} else {
ti = proto_tree_add_uint_format(tree,
hf_item,
tvb,
offset,
4,
entity_id,
"%s: %s (0x%08x)", label, str_predef, entity_id);
}
entity_tree = proto_item_add_subtree(ti,
subtree_entity_id);
proto_tree_add_item(entity_tree,
hf_item_entity_key,
tvb,
offset,
3,
ENC_BIG_ENDIAN);
proto_tree_add_item(entity_tree,
hf_item_entity_kind,
tvb,
offset+3,
1,
ENC_BIG_ENDIAN);
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
static void rtps_util_add_generic_entity_id(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
const char *label,
guint8 * buffer,
gint buffer_size) {
guint32 entity_id = tvb_get_ntohl(tvb, offset);
guint32 entity_key = (entity_id >> 8);
guint8 entity_kind = (entity_id & 0xff);
const char *str_predef = match_strval(entity_id, entity_id_vals);
guint8 temp_buffer[MAX_GUID_SIZE];
if (str_predef == NULL) {
g_snprintf(temp_buffer, MAX_GUID_SIZE,
"0x%08x (%s: 0x%06x)",
entity_id,
val_to_str(entity_kind, entity_kind_vals,
"unknown kind (%02x)"),
entity_key);
} else {
g_snprintf(temp_buffer, MAX_GUID_SIZE,
"%s (0x%08x)",
str_predef,
entity_id);
}
if (tree != NULL) {
proto_tree_add_text(tree,
tvb,
offset,
4,
"%s: %s",
label,
temp_buffer);
}
if (buffer != NULL) {
g_strlcpy(buffer, temp_buffer, buffer_size);
}
}
static void rtps_util_add_generic_guid(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
const char *label,
guint8 * buffer,
gint buffer_size) {
guint32 host_id;
guint32 app_id;
guint8 app_kind;
guint32 instance_id;
guint32 entity_id;
guint32 entity_key;
guint8 entity_kind;
guint8 guid_raw[12];
const char * str_entity_kind;
const char * str_app_kind;
guint8 temp_buff[MAX_GUID_SIZE];
int i;
host_id = tvb_get_ntohl(tvb, offset);
app_id = tvb_get_ntohl(tvb, offset + 4);
entity_id = tvb_get_ntohl(tvb, offset + 8);
for (i = 0; i < 12; ++i) {
guid_raw[i] = tvb_get_guint8(tvb, offset+i);
}
instance_id = (app_id >> 8);
app_kind = (app_id & 0xff);
entity_key = (entity_id >> 8);
entity_kind = (entity_id & 0xff);
str_entity_kind = val_to_str(entity_kind, entity_kind_vals, "%02x");
str_app_kind = val_to_str(app_kind, app_kind_vals, "%02x");
g_snprintf(temp_buff, MAX_GUID_SIZE,
"%s=%02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x: "
"{ hostId=%08x, appId=%08x (%s: %06x), entityId=%08x (%s: %06x) }",
label,
guid_raw[0], guid_raw[1], guid_raw[2], guid_raw[3],
guid_raw[4], guid_raw[5], guid_raw[6], guid_raw[7],
guid_raw[8], guid_raw[9], guid_raw[10], guid_raw[11],
host_id,
app_id, str_app_kind, instance_id,
entity_id, str_entity_kind, entity_key);
proto_tree_add_text(tree, tvb, offset, 12, "%s", temp_buff);
if (buffer != NULL) {
g_strlcpy(buffer, temp_buff, buffer_size);
}
}
static guint64 rtps_util_add_seq_number(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
const char *label _U_) {
guint64 hi = (guint64)NEXT_guint32(tvb, offset, little_endian);
guint64 lo = (guint64)NEXT_guint32(tvb, offset+4, little_endian);
guint64 all = (hi << 32) | lo;
if (tree != NULL) {
proto_tree_add_int64_format(tree,
hf_rtps_sm_seq_number,
tvb,
offset,
8,
all,
"%s: %" G_GINT64_MODIFIER "u", label, all);
}
return all;
}
static void rtps_util_add_ntp_time(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
const char * label,
guint8 * buffer,
gint buffer_size) {
guint8 tempBuffer[MAX_NTP_TIME_SIZE];
gint32 sec = NEXT_guint32(tvb, offset, little_endian);
guint32 frac = NEXT_guint32(tvb, offset+4, little_endian);
double absolute;
if ((sec == 0x7fffffff) && (frac == 0xffffffff)) {
g_strlcpy(tempBuffer, "INFINITE", MAX_NTP_TIME_SIZE);
} else if ((sec == 0) && (frac == 0)) {
g_strlcpy(tempBuffer, "0 sec", MAX_NTP_TIME_SIZE);
} else {
absolute = (double)sec + (double)frac / ((double)(0x80000000) * 2.0);
g_snprintf(tempBuffer, MAX_NTP_TIME_SIZE,
"%f sec (%ds + 0x%08x)", absolute, sec, frac);
}
if (tree != NULL) {
proto_item * ti;
proto_tree *time_tree;
ti = proto_tree_add_none_format(tree,
hf_rtps_param_ntpt,
tvb,
offset,
8,
"%s: %s",
label,
tempBuffer);
time_tree = proto_item_add_subtree(ti, ett_rtps_ntp_time);
proto_tree_add_item(time_tree,
hf_rtps_param_ntpt_sec,
tvb,
offset,
4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
proto_tree_add_item(time_tree,
hf_rtps_param_ntpt_fraction,
tvb,
offset+4,
4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
if (buffer != NULL) {
g_strlcpy(buffer, tempBuffer, buffer_size);
}
}
static gint rtps_util_add_string(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
int hf_item,
gboolean little_endian,
const guint8 * label,
guint8 * buffer,
size_t buffer_size) {
guint8 * retVal = NULL;
guint32 size = NEXT_guint32(tvb, offset, little_endian);
if (size > 0) {
retVal = tvb_get_ephemeral_string(tvb, offset+4, size);
}
if (tree != NULL) {
if (hf_item != -1) {
proto_item * hidden_item;
hidden_item = proto_tree_add_string(tree,
hf_item,
tvb,
offset,
size+4,
(size == 0) ? (guint8 *)"" : retVal);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
proto_tree_add_text(tree,
tvb,
offset,
size+4,
"%s: \"%s\"",
((label != NULL) ? label : (const guint8 *)"value") ,
(size == 0) ? (guint8 *)"" : retVal);
}
if (buffer != NULL) {
if (size == 0) {
buffer[0] = '\0';
} else {
g_snprintf(buffer, (gulong) buffer_size, "%s", retVal);
}
}
return offset + 4 + ((size + 3) & 0xfffffffc);
}
static void rtps_util_add_long(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
int hf_item,
gboolean little_endian,
gboolean is_hex,
gboolean is_signed,
const char *label,
guint8 * buffer,
size_t buffer_size) {
char temp_buff[16];
g_snprintf(temp_buff, 16,
(is_hex ? "0x%08x" : (is_signed ? "%d" : "%u")),
NEXT_guint32(tvb, offset, little_endian));
if (tree != NULL) {
if (hf_item != -1) {
proto_tree_add_item(tree,
hf_item,
tvb,
offset,
4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
} else if (label != NULL) {
proto_tree_add_text(tree,
tvb,
offset,
4,
"%s: %s",
label,
temp_buff);
}
}
if (buffer != NULL) {
g_strlcpy(buffer, temp_buff, (gulong) buffer_size);
}
}
static void rtps_util_add_port(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
char * label,
guint8 * buffer,
gint buffer_size) {
guint8 tempBuffer[MAX_PORT_SIZE];
guint32 value = NEXT_guint32(tvb, offset, little_endian);
if (value == PORT_INVALID) {
g_snprintf(buffer, buffer_size, "%s (0x00000000)", PORT_INVALID_STRING);
} else {
g_snprintf(tempBuffer, MAX_PORT_SIZE, "%u", value);
}
if (tree != NULL) {
proto_tree_add_text(tree,
tvb,
offset,
4,
"%s: %s",
label,
tempBuffer);
}
if (buffer != NULL) {
g_strlcpy(buffer, tempBuffer, buffer_size);
}
}
static void rtps_util_add_boolean(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
char * label,
guint8 * buffer,
size_t buffer_size) {
const char *str;
guint8 value = tvb_get_guint8(tvb, offset);
str = value ? "TRUE" : "FALSE";
if (buffer) {
g_strlcpy(buffer, str, (gulong) buffer_size);
}
if (tree) {
proto_tree_add_text(tree,
tvb,
offset,
1,
"%s: %s",
label,
str);
}
}
static void rtps_util_add_durability_service_qos(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
guint8 * buffer,
gint buffer_size) {
guint8 temp_buffer[MAX_NTP_TIME_SIZE];
gint32 kind = NEXT_guint32(tvb, offset+8, little_endian);
gint32 history_depth = NEXT_guint32(tvb, offset+12, little_endian);
gint32 max_samples = NEXT_guint32(tvb, offset+16, little_endian);
gint32 max_instances = NEXT_guint32(tvb, offset+20, little_endian);
gint32 max_spi = NEXT_guint32(tvb, offset+24, little_endian);
rtps_util_add_ntp_time(NULL,
tvb,
offset,
little_endian,
NULL,
temp_buffer,
MAX_NTP_TIME_SIZE);
g_snprintf(buffer, buffer_size,
"{ service_cleanup_delay=%s, history_kind='%s', "
"history_depth=%d, max_samples=%d, max_instances=%d, "
"max_samples_per_instances=%d }",
temp_buffer,
val_to_str(kind, history_qos_vals, "0x%08x"),
history_depth,
max_samples,
max_instances,
max_spi);
rtps_util_add_ntp_time(tree,
tvb,
offset,
little_endian,
"service_cleanup_delay",
NULL,
0);
proto_tree_add_text(tree,
tvb,
offset+8,
4,
"history_kind: %s",
val_to_str(kind, history_qos_vals, "0x%08x"));
proto_tree_add_text(tree,
tvb,
offset+12,
4,
"history_depth: %d",
history_depth);
proto_tree_add_text(tree,
tvb,
offset+16,
4,
"max_samples: %d",
max_samples);
proto_tree_add_text(tree,
tvb,
offset+20,
4,
"max_instances: %d",
max_instances);
proto_tree_add_text(tree,
tvb,
offset+24,
4,
"max_samples_per_instances: %d",
max_spi);
}
static void rtps_util_add_liveliness_qos(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
guint8 * buffer,
gint buffer_size) {
guint8 temp_buffer[MAX_NTP_TIME_SIZE];
guint32 kind = NEXT_guint32(tvb, offset, little_endian);
rtps_util_add_ntp_time(NULL,
tvb,
offset+4,
little_endian,
NULL,
temp_buffer,
MAX_NTP_TIME_SIZE);
g_snprintf(buffer, buffer_size,
"{ kind=%s, lease_duration=%s }",
val_to_str(kind, liveliness_qos_vals, "0x%08x"),
temp_buffer);
proto_tree_add_text(tree,
tvb,
offset,
4,
"kind: %s",
val_to_str(kind, liveliness_qos_vals, "0x%08x"));
rtps_util_add_ntp_time(tree,
tvb,
offset+4,
little_endian,
"lease_duration",
NULL,
0);
}
static void rtps_util_add_kind_qos(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
char * label,
const value_string *vals,
guint8 * buffer,
size_t buffer_size) {
guint32 kind = NEXT_guint32(tvb, offset, little_endian);
if (buffer) {
g_strlcpy(buffer, val_to_str(kind, vals, "0x%08x"),
(gulong) buffer_size);
}
if (tree) {
proto_tree_add_text(tree,
tvb,
offset,
4,
"%s: %s",
label,
buffer);
}
}
static gint rtps_util_add_seq_string(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
int param_length,
char * label,
guint8 * buffer,
gint buffer_size) {
guint32 num_strings;
guint32 i;
proto_tree *string_tree;
proto_item *ti;
char temp_buff[MAX_LABEL_SIZE];
guint8 overview_buffer[MAX_LABEL_SIZE];
num_strings = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_text(tree,
tvb,
offset,
4,
"size: %d", num_strings);
offset += 4;
ti = proto_tree_add_text(tree,
tvb,
offset,
param_length-8,
"Strings");
string_tree = proto_item_add_subtree(ti, ett_rtps_seq_string);
overview_buffer[0] = '\0';
for (i = 0; i < num_strings; ++i) {
g_snprintf(temp_buff, MAX_LABEL_SIZE,
"%s[%d]",
label,
i);
offset = rtps_util_add_string(string_tree,
tvb,
offset,
-1,
little_endian,
temp_buff,
overview_buffer+strlen(overview_buffer),
MAX_LABEL_SIZE-strlen(overview_buffer));
}
proto_item_set_text(ti,
"%s: %s",
label,
overview_buffer);
if (buffer != NULL) {
g_strlcpy(buffer, overview_buffer, buffer_size);
}
return offset;
}
static gint rtps_util_add_seq_ulong(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
int param_length,
int is_hex,
int is_signed,
char * label) {
guint32 num_elem;
guint32 i;
proto_tree *string_tree;
proto_item *ti;
char temp_buff[MAX_LABEL_SIZE];
char overview_buff[MAX_PARAM_SIZE];
num_elem = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
ti = proto_tree_add_text(tree,
tvb,
offset,
param_length-8,
"Seq");
string_tree = proto_item_add_subtree(ti, ett_rtps_seq_ulong);
overview_buff[0] = '\0';
for (i = 0; i < num_elem; ++i) {
g_snprintf(temp_buff, MAX_LABEL_SIZE,
"%s[%d]",
label,
i);
rtps_util_add_long( string_tree,
tvb,
offset,
-1,
little_endian,
is_hex,
is_signed,
temp_buff,
overview_buff+strlen(overview_buff),
MAX_PARAM_SIZE-strlen(overview_buff));
offset += 4;
}
proto_item_set_text(ti,
"%s: %s",
label,
overview_buff);
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
static gint rtps_util_add_typecode(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
int indent_level,
int is_pointer,
guint16 bitfield,
int is_key,
const gint offset_begin,
char * name,
int seq_max_len,
guint32 * arr_dimension,
int ndds_40_hack) {
const gint original_offset = offset;
guint32 tk_id;
guint16 tk_size;
unsigned int i;
char indent_string[40];
gint retVal;
char type_name[40];
memset(indent_string, ' ', 40);
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
guint32 disc_offset_begin;
guint32 num_members;
guint16 member_length;
guint32 member_name_len;
guint8 *member_name = NULL;
guint8 member_is_pointer;
guint32 next_offset;
guint32 field_offset_begin;
guint32 member_label_count;
gint32 member_label;
guint32 discriminator_enum_name_length;
guint j;
LONG_ALIGN(offset);
struct_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
struct_name = tvb_get_ephemeral_string(tvb, offset, struct_name_len);
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
discriminator_enum_name = tvb_get_ephemeral_string(tvb, offset+4, discriminator_enum_name_length);
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
proto_tree_add_text(tree,
tvb,
original_offset,
retVal,
"%sunion %s (%s%s%s) {",
indent_string,
struct_name,
discriminator_name,
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
member_name = tvb_get_ephemeral_string(tvb, offset, member_name_len);
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
proto_tree_add_text(tree,
tvb,
field_offset_begin,
retVal,
"%s case %d:",
indent_string,
member_label);
}
offset += rtps_util_add_typecode(
tree,
tvb,
offset,
little_endian,
indent_level+2,
member_is_pointer,
0,
0,
field_offset_begin,
member_name,
-1,
NULL,
ndds_40_hack);
}
g_strlcpy(type_name, "}", 40);
break;
}
case RTI_CDR_TK_ENUM:
case RTI_CDR_TK_STRUCT: {
guint32 struct_name_len;
gint8 * struct_name;
guint32 num_members;
guint16 member_length;
guint8 member_is_pointer;
guint16 member_bitfield;
guint8 member_is_key;
guint32 member_name_len;
guint8 *member_name = NULL;
guint32 next_offset;
guint32 field_offset_begin;
guint32 ordinal_number;
const char * typecode_name;
LONG_ALIGN(offset);
struct_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
struct_name = tvb_get_ephemeral_string(tvb, offset, struct_name_len);
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
proto_tree_add_text(tree,
tvb,
original_offset,
retVal,
"%s%s %s {",
indent_string,
typecode_name,
struct_name);
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
member_name = tvb_get_ephemeral_string(tvb, offset, member_name_len);
offset += member_name_len;
if (tk_id == RTI_CDR_TK_ENUM) {
LONG_ALIGN(offset);
ordinal_number = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
proto_tree_add_text(tree,
tvb,
field_offset_begin,
(offset-field_offset_begin),
"%s %s = %d;",
indent_string,
member_name,
ordinal_number);
} else {
member_is_pointer = tvb_get_guint8(tvb, offset);
offset++;
SHORT_ALIGN(offset);
member_bitfield = NEXT_guint16(tvb, offset, little_endian);
offset += 2;
member_is_key = tvb_get_guint8(tvb, offset);
offset++;
offset += rtps_util_add_typecode(
tree,
tvb,
offset,
little_endian,
indent_level+1,
member_is_pointer,
member_bitfield,
member_is_key,
field_offset_begin,
member_name,
-1,
NULL,
ndds_40_hack);
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
offset += rtps_util_add_typecode(
tree,
tvb,
offset,
little_endian,
indent_level,
is_pointer,
bitfield,
is_key,
offset_begin,
name,
seq_max_len2,
NULL,
ndds_40_hack);
return retVal;
}
case RTI_CDR_TK_ARRAY: {
guint32 size[MAX_ARRAY_DIMENSION];
guint32 dim_max;
LONG_ALIGN(offset);
dim_max = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (i = 0; i < MAX_ARRAY_DIMENSION; ++i) size[i] = 0;
for (i = 0; i < dim_max; ++i) {
size[i] = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
}
offset += rtps_util_add_typecode(
tree,
tvb,
offset,
little_endian,
indent_level,
is_pointer,
bitfield,
is_key,
offset_begin,
name,
-1,
size,
ndds_40_hack);
return retVal;
}
case RTI_CDR_TK_ALIAS: {
guint32 alias_name_length;
guint8 *alias_name;
LONG_ALIGN(offset);
alias_name_length = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
alias_name = tvb_get_ephemeral_string(tvb, offset, alias_name_length);
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
value_name = tvb_get_ephemeral_string(tvb, offset, value_name_len);
offset += value_name_len;
g_snprintf(type_name, 40, "valuetype %s", value_name);
break;
}
}
if (seq_max_len != -1) {
proto_tree_add_text(tree,
tvb,
offset_begin,
(offset-offset_begin),
"%ssequence<%s, %d> %s%s;%s",
indent_string,
type_name,
seq_max_len,
is_pointer ? "*" : "",
name ? name : "",
is_key ? KEY_COMMENT : "");
return retVal;
}
if (arr_dimension != NULL) {
emem_strbuf_t *dim_str = ep_strbuf_new_label(NULL);
for (i = 0; i < MAX_ARRAY_DIMENSION; ++i) {
if (arr_dimension[i] != 0) {
ep_strbuf_append_printf(dim_str, "[%d]", arr_dimension[i]);
} else {
break;
}
}
proto_tree_add_text(tree,
tvb,
offset_begin,
(offset-offset_begin),
"%s%s %s%s;%s",
indent_string,
type_name,
name ? name : "",
dim_str->str,
is_key ? KEY_COMMENT : "");
return retVal;
}
if (bitfield != 0xffff && name != NULL && is_pointer == 0) {
proto_tree_add_text(tree,
tvb,
offset_begin,
(offset-offset_begin),
"%s%s %s:%d;%s",
indent_string,
type_name,
name ? name : "",
bitfield,
is_key ? KEY_COMMENT : "");
return retVal;
}
proto_tree_add_text(tree,
tvb,
offset_begin,
(offset-offset_begin),
"%s%s%s%s%s;%s",
indent_string,
type_name,
name ? " " : "",
is_pointer ? "*" : "",
name ? name : "",
is_key ? KEY_COMMENT : "");
return retVal;
}
static void rtps_util_add_seq_octets(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
int param_length,
int hf_id,
guint8 * buffer,
gint buffer_size) {
gint idx = 0;
guint32 seq_length;
guint32 i;
gint original_offset = offset;
guint32 original_seq_length;
original_seq_length = seq_length = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
if (param_length < 4 + (int)seq_length) {
g_strlcpy(buffer,
"RTPS PROTOCOL ERROR: parameter value too small",
buffer_size);
proto_tree_add_text(tree,
tvb,
offset,
param_length, "%s",
buffer);
return ;
}
if (seq_length > MAX_SEQ_OCTETS_PRINTED) {
seq_length = MAX_SEQ_OCTETS_PRINTED;
}
for (i = 0; i < seq_length; ++i) {
idx += g_snprintf(&buffer[idx],
buffer_size - idx - 1,
"%02x",
tvb_get_guint8(tvb, offset++));
if (idx >= buffer_size) {
break;
}
}
if (seq_length != original_seq_length) {
g_strlcat(buffer, "...", buffer_size);
}
if (tree != NULL) {
proto_tree_add_text(tree,
tvb,
original_offset,
4,
"sequenceSize: %d octects",
original_seq_length);
proto_tree_add_item(tree,
hf_id,
tvb,
original_offset+4,
original_seq_length,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
}
static int rtps_util_add_bitmap(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
const char *label _U_) {
guint64 seq_base;
gint32 num_bits;
guint32 data;
char temp_buff[MAX_BITMAP_SIZE];
int i, j, idx;
proto_item * ti;
proto_tree * bitmap_tree;
const gint original_offset = offset;
guint32 datamask;
seq_base = rtps_util_add_seq_number(NULL,
tvb,
offset,
little_endian,
NULL);
offset += 8;
num_bits = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
idx = 0;
for (i = 0; i < num_bits; i += 32) {
data = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (j = 0; j < 32; ++j) {
datamask = (1 << (31-j));
temp_buff[idx] = ((data & datamask) == datamask) ? '1':'0';
++idx;
if (idx > num_bits) {
break;
}
if (idx >= MAX_BITMAP_SIZE-1) {
break;
}
}
}
temp_buff[idx] = '\0';
for (i = (int) strlen(temp_buff) - 1; (i>0 && temp_buff[i] == '0'); --i) {
temp_buff[i] = '\0';
}
ti = proto_tree_add_text(tree,
tvb,
original_offset,
offset-original_offset,
"%s: %" G_GINT64_MODIFIER "u/%d:%s",
label,
seq_base,
num_bits,
temp_buff);
bitmap_tree = proto_item_add_subtree(ti, ett_rtps_bitmap);
proto_tree_add_text(bitmap_tree,
tvb,
original_offset,
8,
"bitmapBase: %" G_GINT64_MODIFIER "u",
seq_base);
proto_tree_add_text(bitmap_tree,
tvb,
original_offset + 8,
4,
"numBits: %u",
num_bits);
if (temp_buff[0] != '\0') {
proto_tree_add_text(bitmap_tree,
tvb,
original_offset + 12,
offset - original_offset - 12,
"bitmap: %s",
temp_buff);
}
return offset;
}
static void rtps_util_decode_flags(proto_tree * tree,
tvbuff_t *tvb,
gint offset,
guint8 flags,
const struct Flag_definition * flag_def) {
proto_item * ti;
proto_tree * flags_tree;
int i, j;
char flags_str[MAX_FLAG_SIZE];
flags_str[0] = '\0';
for (i = 0; i < 8; ++i) {
g_snprintf(flags_str + (2 * i), MAX_FLAG_SIZE - (2 * i), "%c ",
((flags & (1<<(7-i))) ? flag_def[i].letter : RESERVEDFLAG_CHAR));
}
ti = proto_tree_add_uint_format(tree,
hf_rtps_sm_flags,
tvb,
offset,
1,
flags,
"Flags: 0x%02x (%s)",
flags,
flags_str);
flags_tree = proto_item_add_subtree(ti,
ett_rtps_flags);
for (i = 0; i < 8; ++i) {
int is_set = (flags & (1 << (7-i)));
for (j = 0; j < 8; ++j) {
flags_str[j] = (i == j) ? (is_set ? '1' : '0') : '.';
}
flags_str[8] = '\0';
proto_tree_add_text(flags_tree,
tvb,
offset,
1,
"%s = %s: %s",
flags_str,
flag_def[i].description,
is_set ? "Set" : "Not set");
}
}
static gint dissect_parameter_sequence(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
gboolean little_endian,
int octects_to_next_header,
const char * label) {
proto_item * ti;
proto_tree * rtps_parameter_sequence_tree;
proto_tree * rtps_parameter_tree;
guint16 parameter, param_length;
guint8 buffer[MAX_PARAM_SIZE];
gint max_param_section = offset + octects_to_next_header;
buffer[0] = '\0';
ti = proto_tree_add_text(tree,
tvb,
offset,
-1,
"%s:", label);
rtps_parameter_sequence_tree = proto_item_add_subtree(ti,
ett_rtps_parameter_sequence);
do {
if (max_param_section-offset < 4) {
proto_tree_add_text(tree,
tvb,
offset,
1,
"RTPS PROTOCOL ERROR: not enough bytes to read "
" the next parameter");
return 0;
}
parameter = NEXT_guint16(tvb, offset, little_endian);
ti = proto_tree_add_text(rtps_parameter_sequence_tree,
tvb,
offset,
-1,
"%s",
val_to_str(parameter, parameter_id_vals,
"Unknown (0x%04x)"));
rtps_parameter_tree = proto_item_add_subtree(ti, ett_rtps_parameter);
proto_tree_add_uint_format(rtps_parameter_tree,
hf_rtps_parameter_id,
tvb,
offset,
2,
parameter,
"parameterId: 0x%04x (%s)",
parameter,
val_to_str(parameter, parameter_id_vals,
"unknown %04x"));
offset += 2;
param_length = NEXT_guint16(tvb, offset, little_endian);
proto_tree_add_item(rtps_parameter_tree,
hf_rtps_parameter_length,
tvb,
offset,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 2;
if ((max_param_section-offset < param_length) &&
(parameter != PID_SENTINEL)) {
proto_tree_add_text(tree,
tvb,
offset,
1,
"RTPS PROTOCOL ERROR: not enough bytes to read "
" the parameter value");
return 0;
}
proto_item_set_len(ti, param_length+4);
switch(parameter) {
case PID_PARTICIPANT_LEASE_DURATION:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree,
tvb,
offset,
little_endian,
"duration",
buffer,
MAX_PARAM_SIZE);
break;
case PID_TIME_BASED_FILTER:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree,
tvb,
offset,
little_endian,
"minimum_separation",
buffer,
MAX_PARAM_SIZE);
break;
case PID_TOPIC_NAME:
rtps_util_add_string(rtps_parameter_tree,
tvb,
offset,
hf_rtps_param_topic_name,
little_endian,
NULL,
buffer,
MAX_PARAM_SIZE);
break;
case PID_OWNERSHIP_STRENGTH:
ENSURE_LENGTH(4);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset,
hf_rtps_param_strength,
little_endian,
FALSE,
TRUE,
NULL,
buffer,
MAX_PARAM_SIZE);
break;
case PID_TYPE_NAME:
rtps_util_add_string(rtps_parameter_tree,
tvb,
offset,
hf_rtps_param_type_name,
little_endian,
NULL,
buffer,
MAX_PARAM_SIZE);
break;
case PID_METATRAFFIC_MULTICAST_PORT:
case PID_METATRAFFIC_UNICAST_PORT:
case PID_DEFAULT_UNICAST_PORT:
ENSURE_LENGTH(4);
rtps_util_add_port(rtps_parameter_tree,
tvb,
offset,
little_endian,
"port",
buffer,
MAX_PARAM_SIZE);
break;
case PID_DEFAULT_EXPECTS_INLINE_QOS:
ENSURE_LENGTH(1);
rtps_util_add_boolean(rtps_parameter_tree,
tvb,
offset,
"inline_qos",
buffer,
MAX_PARAM_SIZE);
break;
case PID_METATRAFFIC_MULTICAST_IPADDRESS:
case PID_DEFAULT_UNICAST_IPADDRESS:
case PID_MULTICAST_IPADDRESS:
case PID_METATRAFFIC_UNICAST_IPADDRESS:
rtps_util_add_ipv4_address_t(rtps_parameter_tree,
tvb,
offset,
little_endian,
"address",
buffer,
MAX_PARAM_SIZE);
break;
case PID_PROTOCOL_VERSION: {
guint8 major = 0;
guint8 minor = 0;
ENSURE_LENGTH(2);
major = tvb_get_guint8(tvb, offset);
minor = tvb_get_guint8(tvb, offset+1);
g_snprintf(buffer, MAX_PARAM_SIZE, "%d.%d", major, minor);
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
param_length,
"protocolVersion: %s",
buffer);
break;
}
case PID_VENDOR_ID:
ENSURE_LENGTH(2);
rtps_util_add_vendor_id(NULL,
tvb,
offset,
buffer,
MAX_PARAM_SIZE);
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
2,
"vendorId: %s",
buffer);
break;
case PID_RELIABILITY_OFFERED:
case PID_RELIABILITY:
ENSURE_LENGTH(4);
rtps_util_add_kind_qos(rtps_parameter_tree,
tvb,
offset,
little_endian,
"kind",
reliability_qos_vals,
buffer,
MAX_PARAM_SIZE);
if (octects_to_next_header == 12) {
rtps_util_add_ntp_time(rtps_parameter_tree,
tvb,
offset + 4,
little_endian,
"maxBlockingTime",
NULL,
0);
}
break;
case PID_LIVELINESS_OFFERED:
case PID_LIVELINESS:
ENSURE_LENGTH(12);
rtps_util_add_liveliness_qos(rtps_parameter_tree,
tvb,
offset,
little_endian,
buffer,
MAX_PARAM_SIZE);
break;
case PID_DURABILITY:
ENSURE_LENGTH(4);
rtps_util_add_kind_qos(rtps_parameter_tree,
tvb,
offset,
little_endian,
"durability",
durability_qos_vals,
buffer,
MAX_PARAM_SIZE);
break;
case PID_DURABILITY_SERVICE:
ENSURE_LENGTH(28);
rtps_util_add_durability_service_qos(rtps_parameter_tree,
tvb,
offset,
little_endian,
buffer,
MAX_PARAM_SIZE);
break;
case PID_OWNERSHIP_OFFERED:
case PID_OWNERSHIP:
ENSURE_LENGTH(4);
rtps_util_add_kind_qos(rtps_parameter_tree,
tvb,
offset,
little_endian,
"kind",
ownership_qos_vals,
buffer,
MAX_PARAM_SIZE);
break;
case PID_PRESENTATION_OFFERED:
case PID_PRESENTATION:
ENSURE_LENGTH(6);
g_strlcpy(buffer, "{ ", MAX_PARAM_SIZE);
rtps_util_add_kind_qos(rtps_parameter_tree,
tvb,
offset,
little_endian,
"access_scope",
presentation_qos_vals,
buffer+strlen(buffer),
MAX_PARAM_SIZE-strlen(buffer));
g_strlcat(buffer, ", ", MAX_PARAM_SIZE);
rtps_util_add_boolean(rtps_parameter_tree,
tvb,
offset+4,
"coherent_access",
buffer+strlen(buffer),
MAX_PARAM_SIZE-strlen(buffer));
g_strlcat(buffer, ", ", MAX_PARAM_SIZE);
rtps_util_add_boolean(rtps_parameter_tree,
tvb,
offset+4,
"ordered_access",
buffer+strlen(buffer),
MAX_PARAM_SIZE-strlen(buffer));
g_strlcat(buffer, " }", MAX_PARAM_SIZE);
break;
case PID_DEADLINE_OFFERED:
case PID_DEADLINE:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree,
tvb,
offset,
little_endian,
"period",
buffer,
MAX_PARAM_SIZE);
break;
case PID_DESTINATION_ORDER_OFFERED:
case PID_DESTINATION_ORDER:
ENSURE_LENGTH(4);
rtps_util_add_kind_qos(rtps_parameter_tree,
tvb,
offset,
little_endian,
"kind",
destination_order_qos_vals,
buffer,
MAX_PARAM_SIZE);
break;
case PID_LATENCY_BUDGET_OFFERED:
case PID_LATENCY_BUDGET:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree,
tvb,
offset,
little_endian,
"duration",
buffer,
MAX_PARAM_SIZE);
break;
case PID_PARTITION_OFFERED:
case PID_PARTITION:
ENSURE_LENGTH(4);
rtps_util_add_seq_string(rtps_parameter_tree,
tvb,
offset,
little_endian,
param_length,
"name",
buffer,
MAX_PARAM_SIZE);
break;
case PID_LIFESPAN:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree,
tvb,
offset,
little_endian,
"duration",
buffer,
MAX_PARAM_SIZE);
break;
case PID_USER_DATA:
ENSURE_LENGTH(4);
rtps_util_add_seq_octets(rtps_parameter_tree,
tvb,
offset,
little_endian,
param_length,
hf_rtps_param_user_data,
buffer,
MAX_PARAM_SIZE);
break;
case PID_GROUP_DATA:
ENSURE_LENGTH(4);
rtps_util_add_seq_octets(rtps_parameter_tree,
tvb,
offset,
little_endian,
param_length,
hf_rtps_param_group_data,
buffer,
MAX_PARAM_SIZE);
break;
case PID_TOPIC_DATA:
ENSURE_LENGTH(4);
rtps_util_add_seq_octets(rtps_parameter_tree,
tvb,
offset,
little_endian,
param_length,
hf_rtps_param_topic_data,
buffer,
MAX_PARAM_SIZE);
break;
case PID_UNICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree,
tvb,
offset,
little_endian,
"locator",
buffer,
MAX_PARAM_SIZE);
break;
case PID_MULTICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree,
tvb,
offset,
little_endian,
"locator",
buffer,
MAX_PARAM_SIZE);
break;
case PID_DEFAULT_UNICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree,
tvb,
offset,
little_endian,
"locator",
buffer,
MAX_PARAM_SIZE);
break;
case PID_METATRAFFIC_UNICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree,
tvb,
offset,
little_endian,
"locator",
buffer,
MAX_PARAM_SIZE);
break;
case PID_METATRAFFIC_MULTICAST_LOCATOR:
ENSURE_LENGTH(24);
rtps_util_add_locator_t(rtps_parameter_tree,
tvb,
offset,
little_endian,
"locator",
buffer,
MAX_PARAM_SIZE);
break;
case PID_PARTICIPANT_BUILTIN_ENDPOINTS:
case PID_PARTICIPANT_MANUAL_LIVELINESS_COUNT:
ENSURE_LENGTH(4);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset,
-1,
little_endian,
TRUE,
FALSE,
"value",
buffer,
MAX_PARAM_SIZE);
break;
case PID_HISTORY:
ENSURE_LENGTH(8);
g_strlcpy(buffer, "{ ", MAX_PARAM_SIZE);
rtps_util_add_kind_qos(rtps_parameter_tree,
tvb,
offset,
little_endian,
"kind",
history_qos_vals,
buffer+strlen(buffer),
MAX_PARAM_SIZE-strlen(buffer));
g_strlcat(buffer, ", ", MAX_PARAM_SIZE);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset+4,
-1,
little_endian,
FALSE,
TRUE,
"depth",
buffer + strlen(buffer),
MAX_PARAM_SIZE-strlen(buffer));
g_strlcat(buffer, " }", MAX_PARAM_SIZE);
break;
case PID_RESOURCE_LIMIT:
ENSURE_LENGTH(12);
g_strlcpy(buffer, "{ ", MAX_PARAM_SIZE);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset,
-1,
little_endian,
FALSE,
TRUE,
"max_samples",
buffer + strlen(buffer),
MAX_PARAM_SIZE-strlen(buffer));
g_strlcat(buffer, ", ", MAX_PARAM_SIZE);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset+4,
-1,
little_endian,
FALSE,
TRUE,
"max_instances",
buffer + strlen(buffer),
MAX_PARAM_SIZE-strlen(buffer));
g_strlcat(buffer, ", ", MAX_PARAM_SIZE);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset+8,
-1,
little_endian,
FALSE,
TRUE,
"max_samples_per_instances",
buffer + strlen(buffer),
MAX_PARAM_SIZE-strlen(buffer));
g_strlcat(buffer, " }", MAX_PARAM_SIZE);
break;
case PID_CONTENT_FILTER_PROPERTY: {
guint32 temp_offset = offset;
ENSURE_LENGTH(20);
temp_offset = rtps_util_add_string(rtps_parameter_tree,
tvb,
temp_offset,
hf_rtps_param_content_filter_name,
little_endian,
NULL,
buffer,
MAX_PARAM_SIZE);
temp_offset = rtps_util_add_string(rtps_parameter_tree,
tvb,
temp_offset,
hf_rtps_param_related_topic_name,
little_endian,
NULL,
NULL,
0);
temp_offset = rtps_util_add_string(rtps_parameter_tree,
tvb,
temp_offset,
hf_rtps_param_filter_name,
little_endian,
NULL,
NULL,
0);
temp_offset = rtps_util_add_string(rtps_parameter_tree,
tvb,
temp_offset,
-1,
little_endian,
"filterExpression",
NULL,
0);
temp_offset = rtps_util_add_seq_string(rtps_parameter_tree,
tvb,
temp_offset,
little_endian,
param_length,
"filterParameters",
NULL,
0);
break;
}
case PID_PROPERTY_LIST:
ENSURE_LENGTH(4);
{
guint32 prev_offset;
guint32 temp_offset;
guint8 tempName[MAX_PARAM_SIZE];
guint8 tempValue[MAX_PARAM_SIZE];
guint32 seq_size = NEXT_guint32(tvb, offset, little_endian);
g_snprintf(buffer, MAX_PARAM_SIZE, "%d properties", seq_size);
if (seq_size > 0) {
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
0,
" Property Name | Property Value");
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
0,
"------------------------------|------------------------------");
temp_offset = offset+4;
while(seq_size-- > 0) {
prev_offset = temp_offset;
temp_offset = rtps_util_add_string(NULL,
tvb,
temp_offset,
-1,
little_endian,
NULL,
tempName,
MAX_PARAM_SIZE);
temp_offset = rtps_util_add_string(NULL,
tvb,
temp_offset,
-1,
little_endian,
NULL,
tempValue,
MAX_PARAM_SIZE);
proto_tree_add_text(rtps_parameter_tree,
tvb,
prev_offset,
temp_offset - prev_offset,
"%-29s | %-29s",
tempName,
tempValue);
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
temp_offset = rtps_util_add_seq_ulong(rtps_parameter_tree,
tvb,
offset,
little_endian,
param_length,
TRUE,
FALSE,
"filterBitmap");
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
case PID_COHERENT_SET:
ENSURE_LENGTH(8);
rtps_util_add_seq_number(rtps_parameter_tree,
tvb,
offset,
little_endian,
"sequenceNumber");
break;
case PID_TYPECODE:
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
case PID_PARTICIPANT_GUID:
ENSURE_LENGTH(12);
rtps_util_add_generic_guid(rtps_parameter_tree,
tvb,
offset,
"Participant GUID",
buffer,
MAX_PARAM_SIZE);
break;
case PID_PARTICIPANT_ENTITY_ID:
ENSURE_LENGTH(4);
rtps_util_add_generic_entity_id(rtps_parameter_tree,
tvb,
offset,
"Participant entity ID",
buffer,
MAX_PARAM_SIZE);
break;
case PID_GROUP_GUID:
ENSURE_LENGTH(12);
rtps_util_add_generic_guid(rtps_parameter_tree,
tvb,
offset,
"Group GUID",
buffer,
MAX_PARAM_SIZE);
break;
case PID_GROUP_ENTITY_ID:
ENSURE_LENGTH(4);
rtps_util_add_generic_entity_id(rtps_parameter_tree,
tvb,
offset,
"Group entity ID",
buffer,
MAX_PARAM_SIZE);
break;
case PID_PERSISTENCE:
ENSURE_LENGTH(8);
rtps_util_add_ntp_time(rtps_parameter_tree,
tvb,
offset,
little_endian,
"persistence",
buffer,
MAX_PARAM_SIZE);
break;
case PID_TYPE_CHECKSUM:
ENSURE_LENGTH(4);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset,
-1,
little_endian,
TRUE,
FALSE,
"checksum",
buffer,
MAX_PARAM_SIZE);
break;
case PID_EXPECTS_ACK:
ENSURE_LENGTH(1);
rtps_util_add_boolean(rtps_parameter_tree,
tvb,
offset,
"expectsAck",
buffer,
MAX_PARAM_SIZE);
break;
case PID_MANAGER_KEY: {
int i = 0;
char sep = ':';
guint32 manager_key;
buffer[0] = '\0';
while (param_length >= 4) {
manager_key = NEXT_guint32(tvb, offset, little_endian);
g_snprintf(buffer+strlen(buffer),
MAX_PARAM_SIZE-(gulong) strlen(buffer),
"%c 0x%08x",
sep,
manager_key);
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
param_length,
"Key[%d]: 0x%X", i, manager_key);
++i;
offset +=4;
sep = ',';
param_length -= 4;
}
offset += param_length;
break;
}
case PID_RECV_QUEUE_SIZE:
case PID_SEND_QUEUE_SIZE:
ENSURE_LENGTH(4);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset,
-1,
little_endian,
TRUE,
FALSE,
"queueSize",
buffer,
MAX_PARAM_SIZE);
break;
case PID_VARGAPPS_SEQUENCE_NUMBER_LAST:
ENSURE_LENGTH(4);
rtps_util_add_seq_number(rtps_parameter_tree,
tvb,
offset,
little_endian,
"sequenceNumberLast");
break;
case PID_SENTINEL:
break;
case PID_IS_RELIABLE:
case PID_TYPE2_NAME:
case PID_TYPE2_CHECKSUM:
g_strlcpy(buffer, "[DEPRECATED] - Parameter not decoded", MAX_PARAM_SIZE);
case PID_PAD:
case PID_RELIABILITY_ENABLED:
default:
if (param_length > 0) {
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
param_length,
"parameterData");
}
}
if (buffer[0]) {
proto_item_append_text(ti, ": %s", buffer);
buffer[0] = '\0';
}
offset += param_length;
} while(parameter != PID_SENTINEL);
return offset;
}
static void dissect_PAD(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, PAD_FLAGS);
if (octects_to_next_header != 0) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be ZERO)",
octects_to_next_header);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
static void dissect_DATA(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree,
const char ** sm_data) {
int min_len;
int is_builtin_entity = 0;
gint old_offset = offset;
guint32 wid;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, DATA_FLAGS);
min_len = 20;
if ((flags & FLAG_DATA_H) != 0) min_len += 8;
if ((flags & FLAG_DATA_Q) != 0) min_len += 4;
if ((flags & FLAG_DATA_D) != 0) min_len += 4;
if (octects_to_next_header < min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be >= %u)",
octects_to_next_header,
min_len);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
is_builtin_entity |= rtps_util_add_entity_id(tree,
tvb,
offset,
hf_rtps_sm_rdentity_id,
hf_rtps_sm_rdentity_id_key,
hf_rtps_sm_rdentity_id_kind,
ett_rtps_rdentity,
"readerEntityId",
NULL);
offset += 4;
is_builtin_entity |= rtps_util_add_entity_id(tree,
tvb,
offset,
hf_rtps_sm_wrentity_id,
hf_rtps_sm_wrentity_id_key,
hf_rtps_sm_wrentity_id_kind,
ett_rtps_wrentity,
"writerEntityId",
&wid);
offset += 4;
if (wid == ENTITYID_BUILTIN_PUBLICATIONS_WRITER && (flags & FLAG_DATA_A) != 0) {
*sm_data = SM_EXTRA_WPLUS;
} else if (wid == ENTITYID_BUILTIN_PUBLICATIONS_WRITER && (flags & FLAG_DATA_A) == 0) {
*sm_data = SM_EXTRA_WMINUS;
} else if (wid == ENTITYID_BUILTIN_SUBSCRIPTIONS_WRITER && (flags & FLAG_DATA_A) != 0) {
*sm_data = SM_EXTRA_RPLUS;
} else if (wid == ENTITYID_BUILTIN_SUBSCRIPTIONS_WRITER && (flags & FLAG_DATA_A) == 0) {
*sm_data = SM_EXTRA_RMINUS;
} else if (wid == ENTITYID_BUILTIN_SDP_PARTICIPANT_WRITER && (flags & FLAG_DATA_A) != 0) {
*sm_data = SM_EXTRA_PPLUS;
} else if (wid == ENTITYID_BUILTIN_SDP_PARTICIPANT_WRITER && (flags & FLAG_DATA_A) == 0) {
*sm_data = SM_EXTRA_PMINUS;
} else if (wid == ENTITYID_BUILTIN_TOPIC_WRITER && (flags & FLAG_DATA_A) != 0) {
*sm_data = SM_EXTRA_TPLUS;
} else if (wid == ENTITYID_BUILTIN_TOPIC_WRITER && (flags & FLAG_DATA_A) == 0) {
*sm_data = SM_EXTRA_TMINUS;
}
if ((flags & FLAG_DATA_H) != 0) {
rtps_util_add_guid_prefix(tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_instance_id,
hf_rtps_sm_app_kind,
"keyHashPrefix",
NULL,
0);
offset += 8;
} else {
}
rtps_util_add_entity_id(tree,
tvb,
offset,
hf_rtps_sm_entity_id,
hf_rtps_sm_entity_id_key,
hf_rtps_sm_entity_id_kind,
ett_rtps_entity,
"keyHashSuffix",
NULL);
offset += 4;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"writerSeqNumber");
offset += 8;
if ((flags & FLAG_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octects_to_next_header,
"inlineQos");
}
if ((flags & FLAG_DATA_D) != 0) {
if (is_builtin_entity) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octects_to_next_header,
"serializedData");
} else {
proto_tree_add_item(tree,
hf_rtps_issue_data,
tvb,
offset,
octects_to_next_header - (offset - old_offset) + 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
}
}
static void dissect_NOKEY_DATA(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
int min_len;
gint old_offset = offset;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, NOKEY_DATA_FLAGS);
min_len = 16;
if ((flags & FLAG_NOKEY_DATA_Q) != 0) min_len += 4;
if (octects_to_next_header < min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be >= %u)",
octects_to_next_header,
min_len);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
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
offset += 4;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"writerSeqNumber");
offset += 8;
if ((flags & FLAG_NOKEY_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octects_to_next_header,
"inlineQos");
}
if ((flags & FLAG_NOKEY_DATA_D) == 0) {
proto_tree_add_item(tree,
hf_rtps_issue_data,
tvb,
offset,
octects_to_next_header - (offset - old_offset) + 4,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
}
static void dissect_ACKNACK(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
gint original_offset;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, ACKNACK_FLAGS);
if (octects_to_next_header < 20) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be >= 20)",
octects_to_next_header);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
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
if (offset + 4 == original_offset + octects_to_next_header) {
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
FALSE,
TRUE,
"counter",
NULL,
0);
} else if (offset < original_offset + octects_to_next_header) {
proto_tree_add_text(tree,
tvb,
offset,
octects_to_next_header - offset,
"Packet malformed: don't know how to decode those "
"extra bytes: %d",
octects_to_next_header - offset);
} else if (offset > original_offset + octects_to_next_header) {
proto_tree_add_text(tree,
tvb,
original_offset,
octects_to_next_header + original_offset,
"Packet malformed: not enough bytes to decode");
}
}
static void dissect_HEARTBEAT(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
guint32 counter;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, HEARTBEAT_FLAGS);
if (octects_to_next_header < 24) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be >= 24)",
octects_to_next_header);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
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
offset += 4;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"firstAvailableSeqNumber");
offset += 8;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"lastSeqNumber");
offset += 8;
if (octects_to_next_header == 0x28) {
counter = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_text(tree,
tvb,
offset,
4,
"count: %u",
counter);
}
}
static void dissect_GAP(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, GAP_FLAGS);
if (octects_to_next_header < 24) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be >= 24)",
octects_to_next_header);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
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
offset += 4;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"gapStart");
offset += 8;
rtps_util_add_bitmap(tree,
tvb,
offset,
little_endian,
"gapList");
}
static void dissect_INFO_TS(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
int min_len;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_TS_FLAGS);
min_len = 0;
if ((flags & FLAG_INFO_TS_T) == 0) min_len += 8;
if (octects_to_next_header != min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be == %u)",
octects_to_next_header,
min_len);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
if ((flags & FLAG_INFO_TS_T) == 0) {
rtps_util_add_ntp_time(tree,
tvb,
offset,
little_endian,
"timestamp",
NULL,
0);
}
}
static void dissect_INFO_SRC(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_SRC_FLAGS);
if (octects_to_next_header != 16) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be == 16)",
octects_to_next_header);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
{
guint32 ip = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_text(tree,
tvb,
offset,
4,
"unused: 0x%08x (appIpAddress: %d.%d.%d.%d)",
ip,
(ip >> 24) & 0xff,
(ip >> 16) & 0xff,
(ip >> 8) & 0xff,
ip & 0xff);
offset += 4;
}
{
guint8 major = 0;
guint8 minor = 0;
major = tvb_get_guint8(tvb, offset);
minor = tvb_get_guint8(tvb, offset+1);
proto_tree_add_text(tree,
tvb,
offset,
2,
"version: %d.%d",
major,
minor);
offset += 2;
}
{
guint8 vendor[MAX_VENDOR_ID_SIZE];
rtps_util_add_vendor_id(NULL,
tvb,
offset,
vendor,
MAX_VENDOR_ID_SIZE);
proto_tree_add_text(tree,
tvb,
offset,
2,
"vendor: %s",
vendor);
offset += 2;
}
{
rtps_util_add_guid_prefix(tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_instance_id,
hf_rtps_sm_app_kind,
NULL,
NULL,
0);
#if 0
rtps_util_add_guid_prefix(tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_instance_id,
hf_rtps_sm_app_kind,
NULL,
&temp_buffer[0],
MAX_GUID_PREFIX_SIZE);
proto_tree_add_text(tree,
tvb,
offset,
8,
temp_buffer);
#endif
}
}
static void dissect_INFO_REPLY_IP4(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
int min_len;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_REPLY_IP4_FLAGS);
min_len = 8;
if ((flags & FLAG_INFO_REPLY_IP4_M) != 0) min_len += 8;
if (octects_to_next_header != min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be == %u)",
octects_to_next_header,
min_len);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
rtps_util_add_locator_udp_v4(tree,
tvb,
offset,
"unicastReplyLocator",
little_endian);
offset += 8;
if ((flags & FLAG_INFO_REPLY_IP4_M) != 0) {
rtps_util_add_locator_udp_v4(tree,
tvb,
offset,
"multicastReplyLocator",
little_endian);
offset += 8;
}
}
static void dissect_INFO_DST(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_DST_FLAGS);
if (octects_to_next_header != 8) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be == 8)",
octects_to_next_header);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
{
rtps_util_add_guid_prefix(tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_instance_id,
hf_rtps_sm_app_kind,
NULL,
NULL,
0);
}
}
static void dissect_INFO_REPLY(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octects_to_next_header,
proto_tree *tree) {
int min_len;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_REPLY_FLAGS);
min_len = 8;
if ((flags & FLAG_INFO_REPLY_M) != 0) min_len += 8;
if (octects_to_next_header != min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octects_to_next_header,
"octectsToNextHeader: %u (Error: should be == %u)",
octects_to_next_header,
min_len);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
rtps_util_add_locator_list(tree,
tvb,
offset,
"unicastReplyLocatorList",
little_endian);
offset += 8;
if ((flags & FLAG_INFO_REPLY_M) != 0) {
rtps_util_add_locator_list(tree,
tvb,
offset,
"multicastReplyLocatorList",
little_endian);
offset += 8;
}
}
static gboolean dissect_rtps(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree) {
proto_item *ti = NULL;
proto_tree *rtps_tree=NULL;
gint offset = 0;
proto_tree *rtps_submessage_tree;
guint8 submessageId;
guint8 flags;
gboolean little_endian;
gboolean is_ping = FALSE;
gint next_submsg, octects_to_next_header;
struct SMCounterRecord *smcr_head = NULL;
struct SMCounterRecord *smcr_last = NULL;
const gboolean is_tcp = (pinfo->ptype == PT_TCP);
const char * sm_extra = NULL;
if (is_tcp) {
offset = 4;
}
if (!tvb_bytes_exist(tvb, offset, 16)) return FALSE;
if (tvb_get_guint8(tvb,offset) != 'R') return FALSE;
if (tvb_get_guint8(tvb,offset+1) != 'T') return FALSE;
if (tvb_get_guint8(tvb,offset+2) != 'P') return FALSE;
if (tvb_get_guint8(tvb,offset+3) != 'S') return FALSE;
if (tvb_get_guint8(tvb,offset+4) != 1) return FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTPS");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
guint8 nddsPing[8];
ti = proto_tree_add_item(tree, proto_rtps, tvb, 0, -1, ENC_NA);
rtps_tree = proto_item_add_subtree(ti, ett_rtps);
rtps_util_add_protocol_version(rtps_tree, tvb, offset+4);
rtps_util_add_vendor_id(rtps_tree, tvb, offset+6, NULL, 0);
tvb_memcpy(tvb, nddsPing, offset+8, 8);
if (nddsPing[0] == 'N' &&
nddsPing[1] == 'D' &&
nddsPing[2] == 'D' &&
nddsPing[3] == 'S' &&
nddsPing[4] == 'P' &&
nddsPing[5] == 'I' &&
nddsPing[6] == 'N' &&
nddsPing[7] == 'G') {
is_ping = TRUE;
}
if (!is_ping) {
rtps_util_add_guid_prefix(rtps_tree,
tvb,
offset+8,
hf_rtps_guid_prefix,
hf_rtps_host_id,
hf_rtps_app_id,
hf_rtps_app_id_instance_id,
hf_rtps_app_id_app_kind,
NULL,
NULL,
0);
}
}
{
int domain_id;
int participant_idx;
int nature;
proto_item *ti2;
proto_tree *mapping_tree;
domain_id = ((pinfo->destport - PORT_BASE)/10) % 100;
participant_idx = (pinfo->destport - PORT_BASE) / 1000;
nature = (pinfo->destport % 10);
ti2 = proto_tree_add_text(rtps_tree,
tvb,
0,
4,
"Default port mapping: domainId=%d, "
"participantIdx=%d, nature=%s",
domain_id,
participant_idx,
val_to_str(nature, nature_type_vals, "%02x"));
mapping_tree = proto_item_add_subtree(ti2, ett_rtps_default_mapping);
proto_tree_add_uint(mapping_tree,
hf_rtps_domain_id,
tvb,
0,
4,
domain_id);
proto_tree_add_uint(mapping_tree,
hf_rtps_participant_idx,
tvb,
0,
4,
participant_idx);
proto_tree_add_uint(mapping_tree,
hf_rtps_nature_type,
tvb,
0,
4,
nature);
}
offset=16;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
sm_extra = NULL;
submessageId = tvb_get_guint8(tvb, offset);
if (submessageId & 0x80) {
ti = proto_tree_add_text(rtps_tree,
tvb,
offset,
-1,
"Submessage: %s",
val_to_str(submessageId, submessage_id_vals,
"Vendor-specific (0x%02x)"));
} else {
ti = proto_tree_add_text(rtps_tree,
tvb,
offset,
-1,
"Submessage: %s",
val_to_str(submessageId, submessage_id_vals,
"Unknown (0x%02x)"));
}
rtps_submessage_tree = proto_item_add_subtree(ti, ett_rtps_submessage);
if (submessageId & 0x80) {
proto_tree_add_uint_format(rtps_submessage_tree,
hf_rtps_sm_id,
tvb,
offset,
1,
submessageId,
"submessageId: Vendor-specific (0x%02x)",
submessageId);
} else {
proto_tree_add_uint(rtps_submessage_tree, hf_rtps_sm_id,
tvb, offset, 1, submessageId);
}
flags = tvb_get_guint8(tvb, offset + 1);
little_endian = ((flags & FLAG_E) != 0);
octects_to_next_header = NEXT_guint16(tvb, offset + 2, little_endian);
next_submsg = offset + octects_to_next_header + 4;
proto_item_set_len(ti, octects_to_next_header + 4);
switch (submessageId)
{
case PAD:
if (tree) {
dissect_PAD(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
case DATA:
if (tree) {
dissect_DATA(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree,
&sm_extra);
}
break;
case NOKEY_DATA:
if (tree) {
dissect_NOKEY_DATA(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
case ACKNACK:
if (tree) {
dissect_ACKNACK(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
case HEARTBEAT:
if (tree) {
dissect_HEARTBEAT(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
case GAP:
if (tree) {
dissect_GAP(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
case INFO_TS:
if (tree) {
dissect_INFO_TS(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
case INFO_SRC:
if (tree) {
dissect_INFO_SRC(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
case INFO_REPLY_IP4:
if (tree) {
dissect_INFO_REPLY_IP4(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
case INFO_DST:
if (tree) {
dissect_INFO_DST(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
case INFO_REPLY:
if (tree) {
dissect_INFO_REPLY(tvb,
offset,
flags,
little_endian,
octects_to_next_header,
rtps_submessage_tree);
}
break;
default:
if (tree) {
proto_tree_add_uint(rtps_submessage_tree, hf_rtps_sm_flags,
tvb, offset + 1, 1, flags);
proto_tree_add_uint(rtps_submessage_tree,
hf_rtps_sm_octets_to_next_header,
tvb, offset + 2, 2, next_submsg);
}
break;
}
smcr_last = sm_counter_add(smcr_last, submessageId, sm_extra);
if (smcr_head == NULL) {
smcr_head = smcr_last;
}
offset = next_submsg;
}
if (check_col(pinfo->cinfo, COL_INFO)) {
emem_strbuf_t *info_buf = ep_strbuf_new_label(NULL);
struct SMCounterRecord *smcr_ptr = smcr_head;
if (is_ping) {
ep_strbuf_append(info_buf, "PING");
} else {
while (smcr_ptr != NULL) {
if (info_buf->len > 0) {
ep_strbuf_append(info_buf, ", ");
}
ep_strbuf_append_printf(info_buf, "%s%s",
val_to_str(smcr_ptr->id,
submessage_id_vals,
"Unknown[%02x]"),
smcr_ptr->extra ? smcr_ptr->extra : "");
smcr_ptr = smcr_ptr->next;
}
}
col_add_str(pinfo->cinfo, COL_INFO, info_buf->str);
}
sm_counter_free(smcr_head);
return TRUE;
}
void proto_register_rtps(void) {
static hf_register_info hf[] = {
{ &hf_rtps_protocol_version, {
"version",
"rtps.version",
FT_NONE,
BASE_NONE,
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
FT_BYTES,
BASE_NONE,
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
{ &hf_rtps_sm_flags, {
"flags",
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
FT_BYTES,
BASE_NONE,
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
{ &hf_rtps_param_ntpt, {
"ntpTime",
"rtps.param.ntpTime",
FT_NONE,
BASE_NONE,
NULL,
0,
"Time using the NTP standard format",
HFILL }
},
{ &hf_rtps_param_ntpt_sec, {
"seconds",
"rtps.param.ntpTime.sec",
FT_INT32,
BASE_DEC,
NULL,
0,
"The 'second' component of a NTP time",
HFILL }
},
{ &hf_rtps_param_ntpt_fraction, {
"fraction",
"rtps.param.ntpTime.fraction",
FT_UINT32,
BASE_DEC,
NULL,
0,
"The 'fraction' component of a NTP time",
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
};
proto_rtps = proto_register_protocol(
"Real-Time Publish-Subscribe Wire Protocol",
"RTPS",
"rtps");
proto_register_field_array(proto_rtps, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_rtps(void) {
heur_dissector_add("udp", dissect_rtps, proto_rtps);
heur_dissector_add("tcp", dissect_rtps, proto_rtps);
}
