static void info_summary_append(char *summaryText, int submessageId, const char * extra_text) {
gint len = (gint) strlen(summaryText);
if (extra_text == NULL) {
extra_text="";
}
if (summaryText[0] != '\0') {
g_strlcat(summaryText, ", ", MAX_SUMMARY_SIZE-len-1);
len += 2;
}
g_snprintf(summaryText + len,
MAX_SUMMARY_SIZE - len,
"%s%s",
val_to_str(submessageId, submessage_id_vals, "Unknown[%02x]"),
extra_text);
}
static void info_summary_append_ex(char *info_summary_text,
int submessageId,
guint32 writer_id,
guint32 status_info) {
char buffer[10] = "(?[??])";
if (writer_id == ENTITYID_PARTICIPANT)
buffer[1] = 'P';
else if (writer_id == ENTITYID_SEDP_BUILTIN_TOPIC_WRITER)
buffer[1] = 't';
else if (writer_id == ENTITYID_SEDP_BUILTIN_PUBLICATIONS_WRITER)
buffer[1] = 'w';
else if (writer_id == ENTITYID_SEDP_BUILTIN_SUBSCRIPTIONS_WRITER)
buffer[1] = 'r';
else if (writer_id == ENTITYID_SPDP_BUILTIN_PARTICIPANT_WRITER)
buffer[1] = 'p';
else if (writer_id == ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_WRITER)
buffer[1] = 'm';
else {
info_summary_append(info_summary_text, submessageId, NULL);
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
info_summary_append(info_summary_text, submessageId, buffer);
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
static void rtps_util_add_extra_flags(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
const char *label) {
if (tree) {
guint16 flags = NEXT_guint16(tvb, offset, FALSE);
guint8 temp_buffer[20];
int i;
for (i = 0; i < 16; ++i) {
temp_buffer[i] = ((flags & (1 << (15-i))) != 0) ? '1' : '0';
}
temp_buffer[16] = '\0';
proto_tree_add_text(tree,
tvb,
offset,
2,
"%s: %s",
label,
temp_buffer);
}
}
static void rtps_util_add_protocol_version(proto_tree *tree,
tvbuff_t * tvb,
gint offset) {
if (tree) {
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
case RTPS_VENDOR_TOC:
g_strlcpy(vendor_name, RTPS_VENDOR_TOC_STRING, MAX_VENDOR_ID_SIZE);
break;
default:
g_snprintf(vendor_name, MAX_VENDOR_ID_SIZE, "%d.%d", major, minor);
}
if (tree) {
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
if (tree) {
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
}
if (buffer) {
g_strlcpy(buffer, temp_buff, buffer_size);
}
}
static int rtps_util_add_locator_list(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
const guint8 * label,
gboolean little_endian) {
proto_item *ti;
proto_tree *locator_tree;
guint32 num_locators;
num_locators = NEXT_guint32(tvb, offset, little_endian);
if (tree) {
ti = proto_tree_add_text(tree,
tvb,
offset,
4,
"%s: %d Locators",
label,
num_locators);
} else {
return offset + 4 + ((num_locators > 0) ? (24 * num_locators) : 0);
}
offset += 4;
if (num_locators > 0) {
guint32 i;
char temp_buff[20];
locator_tree = proto_item_add_subtree(ti,
ett_rtps_locator_udp_v4);
for (i = 0; i < num_locators; ++i) {
g_snprintf(temp_buff, 20, "Locator[%d]", i);
rtps_util_add_locator_t(locator_tree,
tvb,
offset,
little_endian,
temp_buff,
NULL,
0);
offset += 24;
}
}
return offset;
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
if (tree) {
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
}
static void rtps_util_add_guid_prefix(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
int hf_prefix,
int hf_host_id,
int hf_app_id,
int hf_counter,
const guint8 * label,
guint8 * buffer,
gint buffer_size) {
guint32 host_id;
guint32 app_id;
guint32 counter;
guint8 * temp_buff;
guint8 guid_prefix[12];
const guint8 * safe_label;
int i;
safe_label = (label == NULL) ? (const guint8 *)"guidPrefix" : label;
host_id = tvb_get_ntohl(tvb, offset);
app_id = tvb_get_ntohl(tvb, offset + 4);
counter = tvb_get_ntohl(tvb, offset + 8);
for (i = 0; i < 12; ++i) {
guid_prefix[i] = tvb_get_guint8(tvb, offset+i);
}
temp_buff = (guint8 *) ep_alloc(MAX_GUID_PREFIX_SIZE);
g_snprintf(temp_buff, MAX_GUID_PREFIX_SIZE,
"%s=%02x%02x%02x%02x:%02x%02x%02x%02x:%02x%02x%02x%02x"
" { hostId=%08x, appId=%08x, counter=%08x }",
safe_label,
guid_prefix[0],
guid_prefix[1],
guid_prefix[2],
guid_prefix[3],
guid_prefix[4],
guid_prefix[5],
guid_prefix[6],
guid_prefix[7],
guid_prefix[8],
guid_prefix[9],
guid_prefix[10],
guid_prefix[11],
host_id,
app_id,
counter);
if (tree) {
proto_item * ti, *hidden_item;
proto_tree * guid_tree;
hidden_item = proto_tree_add_item(tree,
hf_prefix,
tvb,
offset,
12,
ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
ti = proto_tree_add_text(tree,
tvb,
offset,
12,
"%s",
temp_buff);
guid_tree = proto_item_add_subtree(ti,
ett_rtps_guid_prefix);
proto_tree_add_item(guid_tree,
hf_host_id,
tvb,
offset,
4,
ENC_BIG_ENDIAN);
proto_tree_add_item(guid_tree,
hf_app_id,
tvb,
offset+4,
4,
ENC_BIG_ENDIAN);
proto_tree_add_item(guid_tree,
hf_counter,
tvb,
offset+8,
4,
ENC_BIG_ENDIAN);
}
if (buffer != NULL) {
g_strlcpy(buffer, temp_buff, buffer_size);
}
}
static void rtps_util_add_entity_id(proto_tree *tree,
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
if (tree) {
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
"unknown kind (%02x)"),
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
if (tree) {
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
guint32 entity_id;
guint32 entity_key;
guint32 counter;
guint8 entity_kind;
guint8 guid_raw[16];
const char * str_entity_kind;
guint8 temp_buff[MAX_GUID_SIZE];
int i;
host_id = tvb_get_ntohl(tvb, offset);
app_id = tvb_get_ntohl(tvb, offset + 4);
counter = tvb_get_ntohl(tvb, offset + 8);
entity_id = tvb_get_ntohl(tvb, offset + 12);
for (i = 0; i < 16; ++i) {
guid_raw[i] = tvb_get_guint8(tvb, offset+i);
}
entity_key = (entity_id >> 8);
entity_kind = (entity_id & 0xff);
str_entity_kind = val_to_str(entity_kind, entity_kind_vals, "%02x");
g_snprintf(temp_buff, MAX_GUID_SIZE,
"%s=%02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x: "
"{ hostId=%08x, appId=%08x, counter=%08x, entityId=%08x (%s: %06x) }",
label,
guid_raw[0], guid_raw[1], guid_raw[2], guid_raw[3],
guid_raw[4], guid_raw[5], guid_raw[6], guid_raw[7],
guid_raw[8], guid_raw[9], guid_raw[10], guid_raw[11],
guid_raw[12], guid_raw[13], guid_raw[14], guid_raw[15],
host_id,
app_id,
counter,
entity_id, str_entity_kind, entity_key);
if (tree) {
proto_tree_add_text(tree, tvb, offset, 16, "%s", temp_buff);
}
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
if (tree) {
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
if (tree) {
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
if (tree) {
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
static guint32 rtps_util_add_long(proto_tree *tree,
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
guint32 retVal = NEXT_guint32(tvb, offset, little_endian);
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
return retVal;
}
static guint16 rtps_util_add_short(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
int hf_item,
gboolean little_endian,
gboolean is_hex,
gboolean is_signed,
const char *label,
guint8 * buffer,
gint buffer_size) {
char temp_buff[16];
guint16 retVal = NEXT_guint16(tvb, offset, little_endian);
g_snprintf(temp_buff, 16,
(is_hex ? "0x%04x" : (is_signed ? "%d" : "%u")),
retVal);
if (tree != NULL) {
if (hf_item != -1) {
proto_tree_add_item(tree,
hf_item,
tvb,
offset,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
} else if (label != NULL) {
proto_tree_add_text(tree,
tvb,
offset,
2,
"%s: %s",
label,
temp_buff);
}
}
if (buffer != NULL) {
g_strlcpy(buffer, temp_buff, buffer_size);
}
return retVal;
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
if (tree) {
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
if (tree) {
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
proto_tree *string_tree = NULL;
proto_item *ti = NULL;
char temp_buff[MAX_LABEL_SIZE];
guint8 overview_buffer[MAX_LABEL_SIZE];
num_strings = NEXT_guint32(tvb, offset, little_endian);
proto_tree_add_text(tree,
tvb,
offset,
4,
"size: %d", num_strings);
offset += 4;
if (tree) {
ti = proto_tree_add_text(tree,
tvb,
offset,
param_length-8,
"Strings");
string_tree = proto_item_add_subtree(ti, ett_rtps_seq_string);
}
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
if (tree) {
proto_item_set_text(ti,
"%s: %s",
label,
overview_buffer);
}
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
if (tree) {
ti = proto_tree_add_text(tree,
tvb,
offset,
param_length-8,
"Seq");
string_tree = proto_item_add_subtree(ti, ett_rtps_seq_ulong);
} else {
return offset + 4*num_elem;
}
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
if (seq_max_len != 0) {
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
0,
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
} else if (tk_id == RTI_CDR_TK_VALUE_PARARM) {
guint32 baseTypeCodeLength;
typecode_name = "<sparse type>";
SHORT_ALIGN(offset);
offset += 2;
LONG_ALIGN(offset);
offset += 4;
baseTypeCodeLength = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
offset += baseTypeCodeLength;
} else {
typecode_name = "struct";
}
if (seq_max_len != 0) {
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
0,
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
0,
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
case RTI_CDR_TK_VALUE_PARARM:
case RTI_CDR_TK_VALUE: {
guint32 value_name_len;
gint8 * value_name;
const char * type_id_name = "valuetype";
LONG_ALIGN(offset);
value_name_len = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
value_name = tvb_get_ephemeral_string(tvb, offset, value_name_len);
offset += value_name_len;
if (tk_id == RTI_CDR_TK_VALUE_PARARM) {
type_id_name = "valueparam";
}
g_snprintf(type_name, 40, "%s '%s'", type_id_name, value_name);
break;
}
}
if (seq_max_len != 0) {
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
emem_strbuf_t *dim_str = ep_strbuf_new_label("");
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
g_strlcpy(buffer, "RTPS PROTOCOL ERROR: parameter value too small", buffer_size);
if (tree) {
proto_tree_add_text(tree,
tvb,
offset,
param_length,
"%s",
buffer);
}
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
if (tree) {
proto_tree_add_text(tree,
tvb,
original_offset,
4,
"sequenceSize: %d octets",
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
temp_buff[0] = '\0';
for (i = 0; i < num_bits; i += 32) {
data = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (j = 0; j < 32; ++j) {
datamask = (1 << (31-j));
temp_buff[idx] = ((data & datamask) == datamask) ? '1':'0';
++idx;
if (idx >= num_bits) {
break;
}
if (idx >= MAX_BITMAP_SIZE-1) {
break;
}
}
}
temp_buff[idx] = '\0';
for (i = (int)strlen(temp_buff) - 1; (i>0 && temp_buff[i] == '0'); --i) {
temp_buff[i] = '\0';
}
if (tree) {
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
}
return offset;
}
static int rtps_util_add_fragment_number_set(proto_tree *tree,
tvbuff_t * tvb,
gint offset,
gboolean little_endian,
const char *label _U_,
gint section_size) {
guint64 base;
gint32 num_bits;
guint32 data;
char temp_buff[MAX_BITMAP_SIZE];
int i, j, idx;
proto_item * ti;
proto_tree * bitmap_tree;
const gint original_offset = offset;
guint32 datamask;
gint expected_size;
gint base_size;
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
if (tree) {
proto_tree_add_text(tree,
tvb,
original_offset,
section_size,
"Packet malformed: illegal size for fragment number set");
}
return -1;
}
}
idx = 0;
temp_buff[0] = '\0';
for (i = 0; i < num_bits; i += 32) {
data = NEXT_guint32(tvb, offset, little_endian);
offset += 4;
for (j = 0; j < 32; ++j) {
datamask = (1 << (31-j));
temp_buff[idx] = ((data & datamask) != 0) ? '1':'0';
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
for (i = (int)strlen(temp_buff) - 1; (i>0 && temp_buff[i] == '0'); --i) {
temp_buff[i] = '\0';
}
if (tree) {
ti = proto_tree_add_text(tree,
tvb,
original_offset,
offset-original_offset,
"%s: %" G_GINT64_MODIFIER "u/%d:%s",
label,
base,
num_bits,
temp_buff);
bitmap_tree = proto_item_add_subtree(ti, ett_rtps_bitmap);
proto_tree_add_text(bitmap_tree,
tvb,
original_offset,
base_size,
"bitmapBase: %" G_GINT64_MODIFIER "u",
base);
proto_tree_add_text(bitmap_tree,
tvb,
original_offset + base_size,
4,
"numBits: %u",
num_bits);
if (temp_buff[0] != '\0') {
proto_tree_add_text(bitmap_tree,
tvb,
original_offset + base_size + 4,
offset - original_offset - base_size - 4,
"bitmap: %s",
temp_buff);
}
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
if (tree == NULL) {
return;
}
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
static void rtps_util_decode_flags_16bit(proto_tree * tree,
tvbuff_t *tvb,
gint offset,
guint16 flags,
const struct Flag_definition * flag_def) {
proto_item * ti;
proto_tree * flags_tree;
int i, j;
char flags_str[MAX_FLAG_SIZE];
if (tree == NULL) {
return;
}
flags_str[0] = '\0';
for (i = 0; i < 16; ++i) {
g_snprintf(flags_str + (2 * i), MAX_FLAG_SIZE - (2 * i), "%c ",
((flags & (1<<(15-i))) ? flag_def[i].letter : RESERVEDFLAG_CHAR));
}
ti = proto_tree_add_uint_format(tree,
hf_rtps_sm_flags,
tvb,
offset,
2,
flags,
"Flags: 0x%04x (%s)",
flags,
flags_str);
flags_tree = proto_item_add_subtree(ti,
ett_rtps_flags);
for (i = 0; i < 16; ++i) {
int is_set = (flags & (1 << (15-i)));
for (j = 0; j < 16; ++j) {
flags_str[j] = (i == j) ? (is_set ? '1' : '0') : '.';
}
flags_str[16] = '\0';
proto_tree_add_text(flags_tree,
tvb,
offset,
2,
"%s = %s: %s",
flags_str,
flag_def[i].description,
is_set ? "Set" : "Not set");
}
}
static void dissect_serialized_data(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
int size,
const char * label,
guint16 vendor_id) {
proto_item * ti;
proto_tree * rtps_parameter_sequence_tree;
guint16 encapsulation_id;
guint16 encapsulation_len;
gboolean encapsulation_little_endian = FALSE;
if (tree == NULL) {
return;
}
ti = proto_tree_add_text(tree,
tvb,
offset,
-1,
"%s:", label);
rtps_parameter_sequence_tree = proto_item_add_subtree(ti,
ett_rtps_serialized_data);
encapsulation_id = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_text(rtps_parameter_sequence_tree,
tvb,
offset,
2,
"encapsulation kind: %s",
val_to_str(encapsulation_id, encapsulation_id_vals, "unknown (%02x)"));
offset += 2;
if (encapsulation_id == ENCAPSULATION_CDR_LE ||
encapsulation_id == ENCAPSULATION_PL_CDR_LE) {
encapsulation_little_endian = TRUE;
}
encapsulation_len = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_text(rtps_parameter_sequence_tree,
tvb,
offset,
2,
"encapsulation options: %04x",
encapsulation_len);
offset += 2;
size -= 4;
switch (encapsulation_id) {
case ENCAPSULATION_CDR_LE:
case ENCAPSULATION_CDR_BE:
proto_tree_add_item(rtps_parameter_sequence_tree,
hf_rtps_issue_data,
tvb,
offset,
size,
encapsulation_little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
break;
case ENCAPSULATION_PL_CDR_LE:
case ENCAPSULATION_PL_CDR_BE:
dissect_parameter_sequence(rtps_parameter_sequence_tree,
tvb,
offset,
encapsulation_little_endian,
size,
label, NULL, vendor_id);
break;
default:
proto_tree_add_text(rtps_parameter_sequence_tree,
tvb,
offset,
size,
"%s",
label);
}
}
static void dissect_octet_seq(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
const char * label) {
proto_item * ti;
proto_tree * rtps_parameter_sequence_tree;
guint32 length;
if (tree == NULL) {
return;
}
ti = proto_tree_add_text(tree,
tvb,
offset,
-1,
"%s:", label);
rtps_parameter_sequence_tree = proto_item_add_subtree(ti,
ett_rtps_serialized_data);
length = NEXT_guint32(tvb, offset, FALSE);
proto_tree_add_text(rtps_parameter_sequence_tree,
tvb,
offset,
4,
"Sequence length: %d", length);
offset += 4;
proto_tree_add_item(rtps_parameter_sequence_tree,
hf_rtps_issue_data,
tvb,
offset,
length,
ENC_NA);
}
static gint dissect_parameter_sequence(proto_tree *tree,
tvbuff_t *tvb,
gint offset,
gboolean little_endian,
int size,
const char * label,
guint32 *pStatusInfo,
guint16 vendor_id) {
proto_item * ti = NULL;
proto_tree * rtps_parameter_sequence_tree = NULL;
proto_tree * rtps_parameter_tree = NULL;
guint16 parameter, param_length;
guint8 buffer[MAX_PARAM_SIZE];
gint original_offset = offset;
buffer[0] = '\0';
if (tree) {
ti = proto_tree_add_text(tree,
tvb,
offset,
-1,
"%s:", label);
rtps_parameter_sequence_tree = proto_item_add_subtree(ti,
ett_rtps_parameter_sequence);
}
for (;;) {
size -= offset - original_offset;
if (size < 4) {
proto_tree_add_text(tree,
tvb,
offset,
1,
"RTPS PROTOCOL ERROR: not enough bytes to read "
" the next parameter");
return 0;
}
original_offset = offset;
parameter = NEXT_guint16(tvb, offset, little_endian);
if (tree) {
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
}
offset += 2;
if (parameter == PID_SENTINEL) {
return offset +2;
}
param_length = NEXT_guint16(tvb, offset, little_endian);
if (tree) {
proto_tree_add_item(rtps_parameter_tree,
hf_rtps_parameter_length,
tvb,
offset,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
offset += 2;
if (size-4 < param_length) {
if (tree) {
proto_tree_add_text(tree,
tvb,
offset,
1,
"RTPS PROTOCOL ERROR: not enough bytes to read"
" the parameter value");
}
return 0;
}
if (tree) {
proto_item_set_len(ti, param_length+4);
}
if (tree == NULL) {
if (parameter == PID_STATUS_INFO) {
if (pStatusInfo != NULL) {
*pStatusInfo = NEXT_guint32(tvb, offset, little_endian);
}
}
offset += param_length;
continue;
}
switch(parameter) {
case PID_STATUS_INFO: {
guint32 si = 0xffffffff;
ENSURE_LENGTH(4);
si = rtps_util_add_long(rtps_parameter_tree,
tvb,
offset,
hf_rtps_param_status_info,
FALSE,
TRUE,
FALSE,
NULL,
buffer,
MAX_PARAM_SIZE);
if (pStatusInfo != NULL) {
*pStatusInfo = si;
}
break;
}
case PID_DIRECTED_WRITE: {
guint8 guidPart;
int i;
ENSURE_LENGTH(16);
rtps_util_add_guid_prefix(rtps_parameter_tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_counter,
"guidPrefix",
NULL,
0);
rtps_util_add_entity_id(rtps_parameter_tree,
tvb,
offset+12,
hf_rtps_sm_entity_id,
hf_rtps_sm_entity_id_key,
hf_rtps_sm_entity_id_kind,
ett_rtps_entity,
"guidSuffix",
NULL);
memset(buffer, 0, MAX_PARAM_SIZE);
for (i = 0; i < 16; ++i) {
guidPart = tvb_get_guint8(tvb, offset+i);
g_snprintf(buffer+strlen(buffer), MAX_PARAM_SIZE-(gulong)strlen(buffer),
"%02x", guidPart);
if (i == 3 || i == 7 || i == 11) g_strlcat(buffer, ":", MAX_PARAM_SIZE);
}
break;
}
case PID_KEY_HASH: {
guint8 guidPart;
int i;
g_strlcat(buffer, "guid: ", MAX_PARAM_SIZE);
for (i = 0; i < param_length; ++i) {
guidPart = tvb_get_guint8(tvb, offset+i);
g_snprintf(buffer+strlen(buffer), MAX_PARAM_SIZE-(gulong)strlen(buffer),
"%02x", guidPart);
if (( ((i+1) % 4) == 0 ) && (i != param_length-1) )
g_strlcat(buffer, ":", MAX_PARAM_SIZE);
}
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
param_length,
"%s",
buffer);
break;
}
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
case PID_EXPECTS_INLINE_QOS:
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
case PID_TRANSPORT_PRIORITY:
ENSURE_LENGTH(4);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset,
-1,
little_endian,
FALSE,
FALSE,
"value",
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
case PID_DEFAULT_MULTICAST_LOCATOR:
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
case PID_PROPERTY_LIST_OLD:
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
case PID_CONTENT_FILTER_INFO: {
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
case PID_BUILTIN_ENDPOINT_SET: {
guint32 data;
guint32 datamask;
char bitbuf[33];
int i;
ENSURE_LENGTH(4);
data = NEXT_guint32(tvb, offset, little_endian);
for (i = 0; i < 32; ++i) {
datamask = (1 << (31-i));
bitbuf[i] = ((data & datamask) == datamask) ? '1':'0';
}
bitbuf[i] = '\0';
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
4,
"value: %08x (%s)",
data, bitbuf);
break;
}
case PID_TYPE_MAX_SIZE_SERIALIZED:
ENSURE_LENGTH(4);
rtps_util_add_long(rtps_parameter_tree,
tvb,
offset,
-1,
little_endian,
FALSE,
FALSE,
"value",
buffer,
MAX_PARAM_SIZE);
break;
case PID_ORIGINAL_WRITER_INFO:
ENSURE_LENGTH(16);
rtps_util_add_guid_prefix(rtps_parameter_tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_counter,
"virtualGUIDPrefix",
NULL,
0);
rtps_util_add_entity_id(rtps_parameter_tree,
tvb,
offset+12,
hf_rtps_sm_entity_id,
hf_rtps_sm_entity_id_key,
hf_rtps_sm_entity_id_kind,
ett_rtps_entity,
"virtualGUIDSuffix",
NULL);
rtps_util_add_seq_number(rtps_parameter_tree,
tvb,
offset+16,
little_endian,
"virtualSeqNumber");
break;
case PID_ENTITY_NAME:
rtps_util_add_string(rtps_parameter_tree,
tvb,
offset,
hf_rtps_param_entity_name,
little_endian,
NULL,
buffer,
MAX_PARAM_SIZE);
break;
case PID_PARTICIPANT_GUID:
case PID_ENDPOINT_GUID:
ENSURE_LENGTH(16);
rtps_util_add_generic_guid(rtps_parameter_tree,
tvb,
offset,
"GUID",
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
ENSURE_LENGTH(16);
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
MAX_PARAM_SIZE-(gulong)strlen(buffer),
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
case PID_IS_RELIABLE:
case PID_TYPE2_NAME:
case PID_TYPE2_CHECKSUM:
case PID_RELIABILITY_ENABLED:
g_strlcpy(buffer, "[DEPRECATED] - Parameter not decoded", MAX_PARAM_SIZE);
case PID_PAD:
break;
default:
if (vendor_id == RTPS_VENDOR_RTI) {
switch(parameter) {
case PID_PRODUCT_VERSION: {
guint8 major = 0;
guint8 minor = 0;
guint8 release;
guint8 revision;
ENSURE_LENGTH(4);
major = tvb_get_guint8(tvb, offset);
minor = tvb_get_guint8(tvb, offset+1);
release = tvb_get_guint8(tvb, offset+2);
revision = tvb_get_guint8(tvb, offset+3);
g_snprintf(buffer, MAX_PARAM_SIZE, "%d.%d%c rev%d",
major, minor, release, revision);
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
param_length,
"productVersion: %s",
buffer);
break;
}
case PID_PLUGIN_PROMISCUITY_KIND: {
guint32 val;
ENSURE_LENGTH(4);
val = NEXT_guint32(tvb, offset, little_endian);
g_snprintf(buffer, MAX_PARAM_SIZE, "%s",
val_to_str(val, plugin_promiscuity_kind_vals,
"unknown (%04x)"));
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
param_length,
"promiscuityKind: %s",
buffer);
break;
}
case PID_ENTITY_VIRTUAL_GUID:
ENSURE_LENGTH(16);
rtps_util_add_guid_prefix(rtps_parameter_tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_counter,
"virtualGUIDPrefix",
NULL,
0);
rtps_util_add_entity_id(rtps_parameter_tree,
tvb,
offset+12,
hf_rtps_sm_entity_id,
hf_rtps_sm_entity_id_key,
hf_rtps_sm_entity_id_kind,
ett_rtps_entity,
"virtualGUIDSuffix",
NULL);
break;
case PID_SERVICE_KIND: {
guint32 val;
ENSURE_LENGTH(4);
val = NEXT_guint32(tvb, offset, little_endian);
g_snprintf(buffer, MAX_PARAM_SIZE, "%s",
val_to_str(val, service_kind_vals, "unknown (%04x)"));
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
param_length,
"serviceKind: %s",
buffer);
break;
}
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
0,
NULL,
0);
break;
case PID_DISABLE_POSITIVE_ACKS:
ENSURE_LENGTH(1);
rtps_util_add_boolean(rtps_parameter_tree,
tvb,
offset,
"disablePositiveAcks",
buffer,
MAX_PARAM_SIZE);
break;
case PID_LOCATOR_FILTER_LIST: {
guint32 number_of_channels = 0;
proto_tree *channel_tree = NULL;
proto_item *ti_channel = NULL;
char temp_buff[MAX_LABEL_SIZE];
guint32 ch;
gint old_offset;
guint32 off = offset;
ENSURE_LENGTH(4);
number_of_channels = NEXT_guint32(tvb, off, little_endian);
g_snprintf(buffer, MAX_PARAM_SIZE, "%d channels", number_of_channels);
off += 4;
if (number_of_channels == 0) {
proto_tree_add_text(rtps_parameter_tree,
tvb,
off-4,
4,
"numberOfChannels: %d", number_of_channels);
break;
}
off = rtps_util_add_string(rtps_parameter_tree,
tvb,
off,
-1,
little_endian,
"filterName",
NULL,
0);
for (ch = 0; ch < number_of_channels; ++ch) {
g_snprintf(temp_buff, MAX_LABEL_SIZE, "Channel[%u]", ch);
old_offset = off;
if (tree) {
ti_channel = proto_tree_add_text(rtps_parameter_tree,
tvb,
off,
0,
"%s",
temp_buff);
channel_tree = proto_item_add_subtree(ti_channel, ett_rtps_locator_filter_channel);
}
off = rtps_util_add_locator_list(channel_tree,
tvb,
off,
temp_buff,
little_endian);
off = rtps_util_add_string(channel_tree,
tvb,
off,
-1,
little_endian,
"filterExpression",
NULL,
0);
if (ti_channel) {
proto_item_set_len(ti_channel, (off - old_offset));
}
}
break;
}
}
}
else if (vendor_id == RTPS_VENDOR_TOC) {
switch(parameter) {
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
0,
NULL,
0);
break;
default:
break;
}
}
else {
if (param_length > 0) {
proto_tree_add_text(rtps_parameter_tree,
tvb,
offset,
param_length,
"parameterData");
}
}
}
if (buffer[0]) {
proto_item_append_text(ti, ": %s", buffer);
buffer[0] = '\0';
}
offset += param_length;
}
g_assert_not_reached();
}
static void dissect_PAD(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
if (tree) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, PAD_FLAGS);
if (NEXT_guint16(tvb, offset + 2, little_endian) != 0) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be ZERO)",
octets_to_next_header);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
info_summary_append(info_summary_text, SUBMESSAGE_PAD, NULL);
}
static void dissect_DATA(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, DATA_FLAGS);
min_len = 20;
if ((flags & FLAG_DATA_Q) != 0) min_len += 4;
if ((flags & FLAG_DATA_D) != 0) min_len += 4;
if ((flags & FLAG_DATA_H) != 0) min_len += 12;
if (octets_to_next_header < min_len) {
if (tree) proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= %u)",
octets_to_next_header,
min_len);
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
info_summary_append_ex(info_summary_text, SUBMESSAGE_DATA, wid, status_info);
return;
}
if (tree) proto_tree_add_item(tree,
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
&wid);
offset += 4;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"writerSeqNumber");
offset += 8;
if ((flags & FLAG_DATA_H) != 0) {
rtps_util_add_guid_prefix(tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_counter,
"keyHashPrefix",
NULL,
0);
offset += 12;
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
if ((flags & FLAG_DATA_I) != 0) {
status_info = rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
1,
0,
"statusInfo",
NULL,
0);
offset += 4;
}
if ((flags & FLAG_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos",
NULL,
vendor_id);
}
if ((flags & FLAG_DATA_D) != 0) {
dissect_serialized_data(tree,
tvb,
offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData",
vendor_id);
}
info_summary_append_ex(info_summary_text, SUBMESSAGE_DATA, wid, status_info);
}
static void dissect_DATA_FRAG(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char *info_summary_text,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, NOKEY_DATA_FRAG_FLAGS);
min_len = 32;
if ((flags & FLAG_DATA_FRAG_Q) != 0) min_len += 4;
if ((flags & FLAG_DATA_FRAG_H) != 0) min_len += 12;
if (octets_to_next_header < min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= %u)",
octets_to_next_header,
min_len);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_DATA_FRAG, NULL);
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
if ((flags & FLAG_DATA_H) != 0) {
rtps_util_add_guid_prefix(tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_counter,
"keyHashPrefix",
NULL,
0);
offset += 12;
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
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"fragmentStartingNum",
NULL,
0);
offset += 4;
rtps_util_add_short(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"fragmentsInSubmessage",
NULL,
0);
offset += 2;
rtps_util_add_short(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"fragmentSize",
NULL,
0);
offset += 2;
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"sampleSize",
NULL,
0);
offset += 4;
if ((flags & FLAG_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos",
NULL,
vendor_id);
}
if ((flags & FLAG_DATA_D) != 0) {
dissect_serialized_data(tree,
tvb,
offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData",
vendor_id);
}
info_summary_append(info_summary_text, SUBMESSAGE_DATA_FRAG, NULL);
}
static void dissect_NOKEY_DATA(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, NOKEY_DATA_FLAGS);
min_len = 16;
if ((flags & FLAG_NOKEY_DATA_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= %u)",
octets_to_next_header,
min_len);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_NOKEY_DATA, NULL);
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
if ((flags & FLAG_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos",
NULL,
vendor_id);
}
if ((flags & FLAG_DATA_D) != 0) {
dissect_serialized_data(tree,
tvb,
offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData",
vendor_id);
}
info_summary_append(info_summary_text, SUBMESSAGE_NOKEY_DATA, NULL);
}
static void dissect_NOKEY_DATA_FRAG(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, NOKEY_DATA_FRAG_FLAGS);
min_len = 28;
if ((flags & FLAG_NOKEY_DATA_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= %u)",
octets_to_next_header,
min_len);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_NOKEY_DATA_FRAG, NULL);
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
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"fragmentStartingNum",
NULL,
0);
offset += 4;
rtps_util_add_short(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"fragmentsInSubmessage",
NULL,
0);
offset += 2;
rtps_util_add_short(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"fragmentSize",
NULL,
0);
offset += 2;
if ((flags & FLAG_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos",
NULL,
vendor_id);
}
if ((flags & FLAG_DATA_D) != 0) {
dissect_serialized_data(tree,
tvb,
offset,
octets_to_next_header - (offset - old_offset) + 4,
"serializedData",
vendor_id);
}
info_summary_append(info_summary_text, SUBMESSAGE_NOKEY_DATA_FRAG, NULL);
}
static void dissect_ACKNACK(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
gint original_offset;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, ACKNACK_FLAGS);
if (octets_to_next_header < 20) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= 20)",
octets_to_next_header);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_ACKNACK, NULL);
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
if (offset + 4 == original_offset + octets_to_next_header) {
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
} else if (offset < original_offset + octets_to_next_header) {
proto_tree_add_text(tree,
tvb,
offset,
octets_to_next_header - offset,
"Packet malformed: don't know how to decode those "
"extra bytes: %d",
octets_to_next_header - offset);
} else if (offset > original_offset + octets_to_next_header) {
proto_tree_add_text(tree,
tvb,
original_offset,
octets_to_next_header + original_offset,
"Packet malformed: not enough bytes to decode");
}
info_summary_append(info_summary_text, SUBMESSAGE_ACKNACK, NULL);
}
static void dissect_NACK_FRAG(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, NACK_FRAG_FLAGS);
if (octets_to_next_header < 24) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= 24)",
octets_to_next_header);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_NACK_FRAG, NULL);
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
"writerSN");
offset += 8;
offset = rtps_util_add_fragment_number_set(tree,
tvb,
offset,
little_endian,
"fragmentNumberState",
octets_to_next_header - 20);
info_summary_append(info_summary_text, SUBMESSAGE_NACK_FRAG, NULL);
if (offset == -1) {
return;
}
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
FALSE,
TRUE,
"count",
NULL,
0);
}
static void dissect_HEARTBEAT(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, HEARTBEAT_FLAGS);
if (octets_to_next_header < 28) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= 28)",
octets_to_next_header);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_HEARTBEAT, NULL);
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
"firstSeqNumber");
offset += 8;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"lastSeqNumber");
offset += 8;
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"count",
NULL,
0);
info_summary_append(info_summary_text, SUBMESSAGE_HEARTBEAT, NULL);
}
static void dissect_HEARTBEAT_BATCH(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, HEARTBEAT_BATCH_FLAGS);
if (octets_to_next_header < 36) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= 36)",
octets_to_next_header);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_HEARTBEAT, NULL);
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
"firstBatchSN");
offset += 8;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"lastBatchSN");
offset += 8;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"firstSeqNumber");
offset += 8;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"lastSeqNumber");
offset += 8;
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"count",
NULL,
0);
info_summary_append(info_summary_text, SUBMESSAGE_HEARTBEAT_BATCH, NULL);
}
static void dissect_HEARTBEAT_FRAG(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, HEARTBEAT_FRAG_FLAGS);
if (octets_to_next_header < 24) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= 24)",
octets_to_next_header);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_HEARTBEAT_FRAG, NULL);
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
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"lastFragmentNum",
NULL,
0);
offset += 4;
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"count",
NULL,
0);
info_summary_append(info_summary_text, SUBMESSAGE_HEARTBEAT_FRAG, NULL);
}
static void dissect_GAP(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, GAP_FLAGS);
if (octets_to_next_header < 24) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= 24)",
octets_to_next_header);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_GAP, NULL);
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
info_summary_append(info_summary_text, SUBMESSAGE_GAP, NULL);
}
static void dissect_INFO_TS(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
int min_len;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_TS_FLAGS);
min_len = 0;
if ((flags & FLAG_INFO_TS_T) == 0) min_len += 8;
if (octets_to_next_header != min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be == %u)",
octets_to_next_header,
min_len);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_INFO_TS, NULL);
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
info_summary_append(info_summary_text, SUBMESSAGE_INFO_TS, NULL);
}
static void dissect_INFO_SRC(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_SRC_FLAGS);
if (octets_to_next_header != 16) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be == 16)",
octets_to_next_header);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_INFO_SRC, NULL);
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
hf_rtps_sm_counter,
NULL,
NULL,
0);
}
info_summary_append(info_summary_text, SUBMESSAGE_INFO_SRC, NULL);
}
static void dissect_INFO_REPLY_IP4(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
int min_len;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_REPLY_IP4_FLAGS);
min_len = 8;
if ((flags & FLAG_INFO_REPLY_IP4_M) != 0) min_len += 8;
if (octets_to_next_header != min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be == %u)",
octets_to_next_header,
min_len);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_INFO_REPLY_IP4, NULL);
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
info_summary_append(info_summary_text, SUBMESSAGE_INFO_REPLY_IP4, NULL);
}
static void dissect_INFO_DST(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_DST_FLAGS);
if (octets_to_next_header != 12) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be == 12)",
octets_to_next_header);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_INFO_DST, NULL);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
rtps_util_add_guid_prefix(tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_counter,
NULL,
NULL,
0);
info_summary_append(info_summary_text, SUBMESSAGE_INFO_DST, NULL);
}
static void dissect_INFO_REPLY(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id _U_) {
int min_len;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, INFO_REPLY_FLAGS);
min_len = 4;
if ((flags & FLAG_INFO_REPLY_M) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= %u)",
octets_to_next_header,
min_len);
return;
}
if (tree == NULL) {
info_summary_append(info_summary_text, SUBMESSAGE_INFO_REPLY, NULL);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
offset = rtps_util_add_locator_list(tree,
tvb,
offset,
"unicastReplyLocatorList",
little_endian);
if ((flags & FLAG_INFO_REPLY_M) != 0) {
offset = rtps_util_add_locator_list(tree,
tvb,
offset,
"multicastReplyLocatorList",
little_endian);
}
info_summary_append(info_summary_text, SUBMESSAGE_INFO_REPLY, NULL);
}
static void dissect_RTPS_DATA(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id,
int is_session) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, RTPS_DATA_FLAGS);
min_len = 24;
if (is_session) {
min_len += 8;
}
if ((flags & FLAG_RTPS_DATA_Q) != 0) min_len += 4;
if ((flags & FLAG_RTPS_DATA_D) != 0) min_len += 4;
if ((flags & FLAG_RTPS_DATA_K) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= %u)",
octets_to_next_header,
min_len);
return;
}
if (tree == NULL) {
offset += 12;
wid = NEXT_guint32(tvb, offset, little_endian);
offset += 12;
if ((flags & FLAG_RTPS_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos",
&status_info,
vendor_id);
}
info_summary_append_ex(info_summary_text, SUBMESSAGE_RTPS_DATA, wid, status_info);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
rtps_util_add_extra_flags(tree,
tvb,
offset,
"Extra flags:");
offset += 2;
proto_tree_add_text(tree,
tvb,
offset,
2,
"Octets to inline QoS: %d",
NEXT_guint16(tvb, offset, little_endian));
offset += 2;
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
if (is_session) {
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"writerSessionSeqNumber");
offset += 8;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"writerVirtualSeqNumber");
offset += 8;
} else {
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"writerSeqNumber");
offset += 8;
}
if ((flags & FLAG_RTPS_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos",
&status_info,
vendor_id);
}
if (((flags & FLAG_RTPS_DATA_D) != 0) || ((flags & FLAG_RTPS_DATA_K) != 0)) {
if (wid == ENTITYID_P2P_BUILTIN_PARTICIPANT_MESSAGE_WRITER) {
proto_tree * rtps_pm_tree;
proto_tree * guid_tree;
guint32 kind;
guint16 encapsulation_id;
guint16 encapsulation_len;
proto_item * ti = proto_tree_add_text(tree,
tvb,
offset,
octets_to_next_header - (offset - old_offset) + 4,
"ParticipantMessageData");
rtps_pm_tree = proto_item_add_subtree(ti, ett_rtps_part_message_data);
encapsulation_id = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_text(rtps_pm_tree,
tvb,
offset,
2,
"encapsulation kind: %s",
val_to_str(encapsulation_id,
encapsulation_id_vals, "unknown (%02x)"));
offset += 2;
#if 0
if (encapsulation_id == ENCAPSULATION_CDR_LE ||
encapsulation_id == ENCAPSULATION_PL_CDR_LE) {
encapsulation_little_endian = 1;
}
#endif
encapsulation_len = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_text(rtps_pm_tree,
tvb,
offset,
2,
"encapsulation options: %04x",
encapsulation_len);
offset += 2;
guid_tree = proto_item_add_subtree(ti,
ett_rtps_part_message_data);
rtps_util_add_guid_prefix(guid_tree,
tvb,
offset,
hf_rtps_sm_guid_prefix,
hf_rtps_sm_host_id,
hf_rtps_sm_app_id,
hf_rtps_sm_counter,
"participantGuidPrefix",
NULL,
0);
offset += 12;
kind = NEXT_guint32(tvb, offset, FALSE);
proto_tree_add_text(guid_tree,
tvb,
offset,
4,
"kind: %s",
val_to_str(kind, participant_message_data_kind, "unknown (%04x)"));
offset += 4;
dissect_octet_seq(rtps_pm_tree,
tvb,
offset,
"serializedData");
} else {
const char *label;
if (((flags & FLAG_RTPS_DATA_D) != 0) || ((flags & FLAG_RTPS_DATA_K) == 0)) {
label = "serializedData";
} else if (((flags & FLAG_RTPS_DATA_D) == 0) || ((flags & FLAG_RTPS_DATA_K) != 0)) {
label = "serializedKey";
} else {
label = "<invalid or unknown data type>";
}
dissect_serialized_data(tree,
tvb,
offset,
octets_to_next_header - (offset - old_offset) + 4,
label,
vendor_id);
}
}
info_summary_append_ex(info_summary_text, SUBMESSAGE_RTPS_DATA, wid, status_info);
}
static void dissect_RTPS_DATA_FRAG(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, RTPS_DATA_FRAG_FLAGS);
min_len = 36;
if ((flags & FLAG_RTPS_DATA_FRAG_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= %u)",
octets_to_next_header,
min_len);
return;
}
if (tree == NULL) {
offset += 12;
wid = NEXT_guint32(tvb, offset, little_endian);
offset += 24;
if ((flags & FLAG_RTPS_DATA_FRAG_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos",
&status_info,
vendor_id);
}
info_summary_append_ex(info_summary_text, SUBMESSAGE_RTPS_DATA_FRAG, wid, status_info);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
rtps_util_add_extra_flags(tree,
tvb,
offset,
"Extra flags:");
offset += 2;
proto_tree_add_text(tree,
tvb,
offset,
2,
"Octets to inline QoS: %d",
NEXT_guint16(tvb, offset, little_endian));
offset += 2;
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
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"writerSeqNumber");
offset += 8;
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"fragmentStartingNum",
NULL,
0);
offset += 4;
rtps_util_add_short(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"fragmentsInSubmessage",
NULL,
0);
offset += 2;
rtps_util_add_short(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"fragmentSize",
NULL,
0);
offset += 2;
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"sampleSize",
NULL,
0);
offset += 4;
if ((flags & FLAG_RTPS_DATA_FRAG_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos",
&status_info,
vendor_id);
}
{
const char *label = "serializedData";
if ((flags & FLAG_RTPS_DATA_FRAG_K) != 0) {
label = "serializedKey";
}
dissect_serialized_data(tree,
tvb,
offset,
octets_to_next_header - (offset - old_offset) + 4,
label,
vendor_id);
}
info_summary_append_ex(info_summary_text, SUBMESSAGE_RTPS_DATA_FRAG, wid, status_info);
}
static void dissect_RTPS_DATA_BATCH(tvbuff_t *tvb,
gint offset,
guint8 flags,
gboolean little_endian,
int octets_to_next_header,
proto_tree *tree,
char * info_summary_text,
guint16 vendor_id) {
int min_len;
gint old_offset = offset;
guint32 wid;
guint32 status_info = 0xffffffff;
gint32 octectsToSLEncapsulationId;
gint32 sampleListOffset;
guint16 encapsulation_id;
guint16 *sample_info_flags = NULL;
guint32 *sample_info_length = NULL;
gint32 sample_info_count = 0;
gint32 sample_info_max = rtps_max_batch_samples_dissected;
rtps_util_decode_flags(tree, tvb, offset + 1, flags, RTPS_DATA_BATCH_FLAGS);
min_len = 44;
if ((flags & FLAG_RTPS_DATA_BATCH_Q) != 0) min_len += 4;
if (octets_to_next_header < min_len) {
proto_tree_add_uint_format(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset+2,
2,
octets_to_next_header,
"octetsToNextHeader: %u (Error: should be >= %u)",
octets_to_next_header,
min_len);
return;
}
if (tree == NULL) {
offset += 12;
wid = NEXT_guint32(tvb, offset, little_endian);
offset += 24;
if ((flags & FLAG_DATA_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"inlineQos",
&status_info,
vendor_id);
}
info_summary_append_ex(info_summary_text, SUBMESSAGE_RTPS_DATA_BATCH, wid, status_info);
return;
}
proto_tree_add_item(tree,
hf_rtps_sm_octets_to_next_header,
tvb,
offset + 2,
2,
little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
offset += 4;
rtps_util_add_extra_flags(tree,
tvb,
offset,
"Extra flags:");
offset += 2;
proto_tree_add_text(tree,
tvb,
offset,
2,
"Octets to inline QoS: %d",
NEXT_guint16(tvb, offset, little_endian));
offset += 2;
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
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"batchSeqNumber");
offset += 8;
rtps_util_add_seq_number(tree,
tvb,
offset,
little_endian,
"firstSampleSeqNumber");
offset += 8;
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"offsetToLastSampleSN",
NULL,
0);
offset += 4;
rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"batchSampleCount",
NULL,
0);
offset += 4;
if ((flags & FLAG_RTPS_DATA_BATCH_Q) != 0) {
offset = dissect_parameter_sequence(tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"batchInlineQos",
&status_info,
vendor_id);
}
octectsToSLEncapsulationId = (gint32)rtps_util_add_long(tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"octetsToSLEncapsulationId",
NULL,
0);
offset += 4;
sampleListOffset = offset + octectsToSLEncapsulationId;
{
proto_item * ti;
proto_tree * sil_tree;
sample_info_count = 0;
ti = proto_tree_add_text(tree,
tvb,
offset,
-1,
"Sample Info List");
sil_tree = proto_item_add_subtree(ti, ett_rtps_sample_info_list);
if (rtps_max_batch_samples_dissected == 0) {
sample_info_max = 1024;
}
sample_info_flags = (guint16 *)ep_alloc(sizeof(guint16) * sample_info_max);
sample_info_length = (guint32 *)ep_alloc(sizeof(guint32) * sample_info_max);
while (offset < sampleListOffset) {
guint16 flags2;
gint min_length;
proto_tree * si_tree;
gint offset_begin_sampleinfo = offset;
if (rtps_max_batch_samples_dissected > 0 && (guint)sample_info_count >= rtps_max_batch_samples_dissected) {
proto_tree_add_text(sil_tree,
tvb,
offset,
-1,
"... (more samples available. Configure this limit from preferences dialog)");
offset = sampleListOffset;
break;
}
ti = proto_tree_add_text(sil_tree,
tvb,
offset,
-1,
"sampleInfo[%d]", sample_info_count);
si_tree = proto_item_add_subtree(ti, ett_rtps_sample_info);
flags2 = NEXT_guint16(tvb, offset, FALSE);
sample_info_flags[sample_info_count] = flags2;
rtps_util_decode_flags_16bit(si_tree, tvb, offset, flags2, RTPS_SAMPLE_INFO_FLAGS16);
offset += 2;
rtps_util_add_short(si_tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"octetsToInlineQos",
NULL,
0);
offset += 2;
min_length = 4;
if ((flags2 & FLAG_SAMPLE_INFO_T) != 0) min_len += 8;
if ((flags2 & FLAG_SAMPLE_INFO_Q) != 0) min_len += 4;
if ((flags2 & FLAG_SAMPLE_INFO_O) != 0) min_len += 4;
if (sampleListOffset - offset < min_length) {
proto_tree_add_text(si_tree,
tvb,
offset-4,
4,
"Error: not enough bytes to dissect sample info");
return;
}
sample_info_length[sample_info_count] = rtps_util_add_long(si_tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"serializedDataLength",
NULL,
0);
offset += 4;
if ((flags2 & FLAG_SAMPLE_INFO_T) != 0) {
rtps_util_add_ntp_time(si_tree,
tvb,
offset,
little_endian,
"timestamp",
NULL,
0);
offset += 8;
}
if ((flags2 & FLAG_SAMPLE_INFO_O) != 0) {
rtps_util_add_long(si_tree,
tvb,
offset,
-1,
little_endian,
0,
0,
"offsetSN",
NULL,
0);
offset += 4;
}
if ((flags2 & FLAG_SAMPLE_INFO_Q) != 0) {
offset = dissect_parameter_sequence(si_tree,
tvb,
offset,
little_endian,
octets_to_next_header - (offset - old_offset) + 4,
"sampleInlineQos",
&status_info,
vendor_id);
}
proto_item_set_len(ti, offset - offset_begin_sampleinfo);
sample_info_count++;
}
}
encapsulation_id = NEXT_guint16(tvb, offset, FALSE);
proto_tree_add_text(tree,
tvb,
offset,
2,
"encapsulation kind: %s",
val_to_str(encapsulation_id, encapsulation_id_vals, "unknown (%02x)"));
offset += 2;
offset += 2;
if (octets_to_next_header - (offset - old_offset) > 0) {
proto_item * ti;
proto_tree * sil_tree;
gint count = 0;
const char * label;
ti = proto_tree_add_text(tree,
tvb,
offset,
-1,
"Serialized Sample List");
sil_tree = proto_item_add_subtree(ti, ett_rtps_sample_batch_list);
for (count = 0; count < sample_info_count; ++count) {
if (octets_to_next_header - (offset - old_offset) + 4 < (gint)sample_info_length[count]) {
proto_tree_add_text(sil_tree,
tvb,
offset,
4,
"Error: not enough bytes to dissect sample");
return;
}
if ((sample_info_flags[count] & FLAG_SAMPLE_INFO_K) != 0) {
label = "serializedKey[%d]";
} else {
label = "serializedData[%d]";
}
proto_tree_add_text(sil_tree,
tvb,
offset,
sample_info_length[count],
label,
count);
offset += sample_info_length[count];
}
}
info_summary_append_ex(info_summary_text, SUBMESSAGE_RTPS_DATA_BATCH, wid, status_info);
}
static gboolean dissect_rtps(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree) {
proto_item *ti = NULL;
proto_tree *rtps_tree = NULL;
gint offset = 0;
proto_tree *rtps_submessage_tree = NULL;
guint8 submessageId;
guint8 flags;
gboolean little_endian;
gboolean is_ping = FALSE;
gint next_submsg, octets_to_next_header;
guint16 vendor_id = RTPS_VENDOR_UNKNOWN;
char info_summary_text[MAX_SUMMARY_SIZE];
info_summary_text[0] = '\0';
if (!tvb_bytes_exist(tvb, offset, 16)) return FALSE;
if ( (tvb_get_guint8(tvb,offset) != 'R') ||
(tvb_get_guint8(tvb,offset+1) != 'T') ||
(tvb_get_guint8(tvb,offset+2) != 'P') ||
(tvb_get_guint8(tvb,offset+3) != 'S') ||
(tvb_get_guint8(tvb,offset+4) != 2) ) {
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTPS2");
col_clear(pinfo->cinfo, COL_INFO);
{
guint8 nddsPing[8];
tvb_memcpy(tvb, nddsPing, offset+8, 8);
is_ping = (nddsPing[0] == 'N' &&
nddsPing[1] == 'D' &&
nddsPing[2] == 'D' &&
nddsPing[3] == 'S' &&
nddsPing[4] == 'P' &&
nddsPing[5] == 'I' &&
nddsPing[6] == 'N' &&
nddsPing[7] == 'G');
}
if (tree) {
ti = proto_tree_add_item(tree, proto_rtps, tvb, 0, -1, ENC_NA);
rtps_tree = proto_item_add_subtree(ti, ett_rtps);
rtps_util_add_protocol_version(rtps_tree, tvb, offset+4);
vendor_id = NEXT_guint16(tvb, offset+6, FALSE);
rtps_util_add_vendor_id(rtps_tree, tvb, offset+6, NULL, 0);
if (!is_ping) {
rtps_util_add_guid_prefix(rtps_tree,
tvb,
offset+8,
hf_rtps_guid_prefix,
hf_rtps_host_id,
hf_rtps_app_id,
hf_rtps_sm_counter,
NULL,
NULL,
0);
}
}
if (is_ping) {
g_strlcpy(info_summary_text, "PING", MAX_SUMMARY_SIZE);
}
#ifdef RTI_BUILD
else {
pinfo->guid_prefix_host = tvb_get_ntohl(tvb, offset + 8);
pinfo->guid_prefix_app = tvb_get_ntohl(tvb, offset + 12);
pinfo->guid_prefix_count = tvb_get_ntohl(tvb, offset + 16);
pinfo->guid_rtps2 = 1;
}
#endif
if (tree) {
int domain_id;
int participant_idx = -1;
int nature;
int Doffset;
proto_item *ti2;
proto_tree *mapping_tree;
domain_id = (pinfo->destport - PORT_BASE) / 250;
Doffset = (pinfo->destport - PORT_BASE - domain_id * 250);
if (Doffset == 0) {
nature = PORT_METATRAFFIC_MULTICAST;
} else if (Doffset == 1) {
nature = PORT_USERTRAFFIC_MULTICAST;
} else {
participant_idx = (Doffset - 10) / 2;
if ( (Doffset - 10) % 2 == 0) {
nature = PORT_METATRAFFIC_UNICAST;
} else {
nature = PORT_USERTRAFFIC_UNICAST;
}
}
if (nature == PORT_METATRAFFIC_UNICAST || nature == PORT_USERTRAFFIC_UNICAST) {
ti2 = proto_tree_add_text(rtps_tree,
tvb,
0,
4,
"Default port mapping: %s, domainId=%d, "
"participantIdx=%d",
val_to_str(nature, nature_type_vals, "%02x"),
domain_id,
participant_idx);
} else {
ti2 = proto_tree_add_text(rtps_tree,
tvb,
0,
4,
"Default port mapping: %s, domainId=%d",
val_to_str(nature, nature_type_vals, "%02x"),
domain_id);
}
mapping_tree = proto_item_add_subtree(ti2, ett_rtps_default_mapping);
proto_tree_add_uint(mapping_tree,
hf_rtps_domain_id,
tvb,
0,
4,
domain_id);
if (nature == PORT_METATRAFFIC_UNICAST || nature == PORT_USERTRAFFIC_UNICAST) {
proto_tree_add_uint(mapping_tree,
hf_rtps_participant_idx,
tvb,
0,
4,
participant_idx);
}
proto_tree_add_uint(mapping_tree,
hf_rtps_nature_type,
tvb,
0,
4,
nature);
}
offset=20;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
submessageId = tvb_get_guint8(tvb, offset);
if (rtps_tree) {
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
}
flags = tvb_get_guint8(tvb, offset + 1);
little_endian = ((flags & FLAG_E) != 0);
octets_to_next_header = NEXT_guint16(tvb, offset + 2, little_endian);
if (octets_to_next_header == 0)
octets_to_next_header = tvb_reported_length_remaining(tvb, offset + 4);
next_submsg = offset + octets_to_next_header + 4;
if (ti != NULL) {
proto_item_set_len(ti, octets_to_next_header + 4);
}
switch (submessageId) {
case SUBMESSAGE_PAD:
dissect_PAD(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_DATA:
dissect_DATA(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_DATA_FRAG:
dissect_DATA_FRAG(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_NOKEY_DATA:
dissect_NOKEY_DATA(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_NOKEY_DATA_FRAG:
dissect_NOKEY_DATA_FRAG(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_NACK_FRAG:
dissect_NACK_FRAG(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_ACKNACK_SESSION:
case SUBMESSAGE_ACKNACK_BATCH:
case SUBMESSAGE_ACKNACK:
dissect_ACKNACK(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_HEARTBEAT:
dissect_HEARTBEAT(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_HEARTBEAT_SESSION:
case SUBMESSAGE_HEARTBEAT_BATCH:
dissect_HEARTBEAT_BATCH(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_HEARTBEAT_FRAG:
dissect_HEARTBEAT_FRAG(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_GAP:
dissect_GAP(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_INFO_TS:
dissect_INFO_TS(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_INFO_SRC:
dissect_INFO_SRC(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_INFO_REPLY_IP4:
dissect_INFO_REPLY_IP4(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_INFO_DST:
dissect_INFO_DST(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_INFO_REPLY:
dissect_INFO_REPLY(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_RTPS_DATA_SESSION:
case SUBMESSAGE_RTPS_DATA:
dissect_RTPS_DATA(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id,
(submessageId == SUBMESSAGE_RTPS_DATA_SESSION));
break;
case SUBMESSAGE_RTPS_DATA_FRAG:
dissect_RTPS_DATA_FRAG(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
case SUBMESSAGE_RTPS_DATA_BATCH:
dissect_RTPS_DATA_BATCH(tvb,
offset,
flags,
little_endian,
octets_to_next_header,
rtps_submessage_tree,
info_summary_text,
vendor_id);
break;
default:
if (rtps_submessage_tree != NULL) {
proto_tree_add_uint(rtps_submessage_tree, hf_rtps_sm_flags,
tvb, offset + 1, 1, flags);
proto_tree_add_uint(rtps_submessage_tree,
hf_rtps_sm_octets_to_next_header,
tvb, offset + 2, 2, next_submsg);
}
}
offset = next_submsg;
}
col_add_str(pinfo->cinfo, COL_INFO, info_summary_text);
return TRUE;
}
void proto_register_rtps2(void) {
static hf_register_info hf[] = {
{ &hf_rtps_protocol_version, {
"version",
"rtps2.version",
FT_NONE,
BASE_NONE,
NULL,
0,
"RTPS protocol version number",
HFILL }
},
{ &hf_rtps_protocol_version_major, {
"major",
"rtps2.version.major",
FT_INT8,
BASE_DEC,
NULL,
0,
"RTPS major protocol version number",
HFILL }
},
{ &hf_rtps_protocol_version_minor, {
"minor",
"rtps2.version.minor",
FT_INT8,
BASE_DEC,
NULL,
0,
"RTPS minor protocol version number",
HFILL }
},
{ &hf_rtps_domain_id, {
"domain_id",
"rtps2.domain_id",
FT_UINT32,
BASE_DEC,
NULL,
0,
"Domain ID",
HFILL }
},
{ &hf_rtps_participant_idx, {
"participant_idx",
"rtps2.participant_idx",
FT_UINT32,
BASE_DEC,
NULL,
0,
"Participant index",
HFILL }
},
{ &hf_rtps_nature_type, {
"traffic_nature",
"rtps2.traffic_nature",
FT_UINT32,
BASE_DEC,
VALS(nature_type_vals),
0,
"Nature of the traffic (meta/user-traffic uni/multi-cast)",
HFILL }
},
{ &hf_rtps_vendor_id, {
"vendorId",
"rtps2.vendorId",
FT_UINT16,
BASE_HEX,
NULL,
0,
"Unique identifier of the DDS vendor that generated this packet",
HFILL }
},
{ &hf_rtps_guid_prefix, {
"guidPrefix",
"rtps2.guidPrefix",
FT_BYTES,
BASE_NONE,
NULL,
0,
"GuidPrefix of the RTPS packet",
HFILL }
},
{ &hf_rtps_host_id, {
"hostId",
"rtps2.hostId",
FT_UINT32,
BASE_HEX,
NULL,
0,
"Sub-component 'hostId' of the GuidPrefix of the RTPS packet",
HFILL }
},
{ &hf_rtps_app_id, {
"appId",
"rtps2.appId",
FT_UINT32,
BASE_HEX,
NULL,
0,
"Sub-component 'appId' of the GuidPrefix of the RTPS packet",
HFILL }
},
{ &hf_rtps_counter, {
"counter",
"rtps2.counter",
FT_UINT32,
BASE_HEX,
NULL,
0,
"Sub-component 'counter' of the GuidPrefix of the RTPS packet",
HFILL }
},
{ &hf_rtps_sm_id, {
"submessageId",
"rtps2.sm.id",
FT_UINT8,
BASE_HEX,
VALS(submessage_id_vals),
0,
"defines the type of submessage",
HFILL }
},
{ &hf_rtps_sm_flags, {
"flags",
"rtps2.sm.flags",
FT_UINT8,
BASE_HEX,
NULL,
0,
"bitmask representing the flags associated with a submessage",
HFILL }
},
{ &hf_rtps_sm_octets_to_next_header, {
"octetsToNextHeader",
"rtps2.sm.octetsToNextHeader",
FT_UINT16,
BASE_DEC,
NULL,
0,
"Size of the submessage payload",
HFILL }
},
{ &hf_rtps_sm_guid_prefix, {
"guidPrefix",
"rtps2.sm.guidPrefix",
FT_BYTES,
BASE_NONE,
NULL,
0,
"a generic guidPrefix that is transmitted inside the submessage (this is NOT the guidPrefix described in the packet header",
HFILL }
},
{ &hf_rtps_sm_host_id, {
"host_id",
"rtps2.sm.guidPrefix.hostId",
FT_UINT32,
BASE_HEX,
NULL,
0,
"The hostId component of the rtps2.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_app_id, {
"appId",
"rtps2.sm.guidPrefix.appId",
FT_UINT32,
BASE_HEX,
NULL,
0,
"AppId component of the rtps2.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_instance_id, {
"instanceId",
"rtps2.sm.guidPrefix.appId.instanceId",
FT_UINT24,
BASE_HEX,
NULL,
0,
"instanceId component of the AppId of the rtps2.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_app_kind, {
"appKind",
"rtps2.sm.guidPrefix.appId.appKind",
FT_UINT8,
BASE_HEX,
NULL,
0,
"appKind component of the AppId of the rtps2.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_counter, {
"counter",
"rtps2.sm.guidPrefix.counter",
FT_UINT32,
BASE_HEX,
NULL,
0,
"The counter component of the rtps2.sm.guidPrefix",
HFILL }
},
{ &hf_rtps_sm_entity_id, {
"entityId",
"rtps2.sm.entityId",
FT_UINT32,
BASE_HEX,
VALS(entity_id_vals),
0,
"Object entity ID as it appears in a DATA submessage (keyHashSuffix)",
HFILL }
},
{ &hf_rtps_sm_entity_id_key, {
"entityKey",
"rtps2.sm.entityId.entityKey",
FT_UINT24,
BASE_HEX,
NULL,
0,
"'entityKey' field of the object entity ID",
HFILL }
},
{ &hf_rtps_sm_entity_id_kind, {
"entityKind",
"rtps2.sm.entityId.entityKind",
FT_UINT8,
BASE_HEX,
VALS(entity_kind_vals),
0,
"'entityKind' field of the object entity ID",
HFILL }
},
{ &hf_rtps_sm_rdentity_id, {
"readerEntityId",
"rtps2.sm.rdEntityId",
FT_UINT32,
BASE_HEX,
VALS(entity_id_vals),
0,
"Reader entity ID as it appears in a submessage",
HFILL }
},
{ &hf_rtps_sm_rdentity_id_key, {
"readerEntityKey",
"rtps2.sm.rdEntityId.entityKey",
FT_UINT24,
BASE_HEX,
NULL,
0,
"'entityKey' field of the reader entity ID",
HFILL }
},
{ &hf_rtps_sm_rdentity_id_kind, {
"readerEntityKind",
"rtps2.sm.rdEntityId.entityKind",
FT_UINT8,
BASE_HEX,
VALS(entity_kind_vals),
0,
"'entityKind' field of the reader entity ID",
HFILL }
},
{ &hf_rtps_sm_wrentity_id, {
"writerEntityId",
"rtps2.sm.wrEntityId",
FT_UINT32,
BASE_HEX,
VALS(entity_id_vals),
0,
"Writer entity ID as it appears in a submessage",
HFILL }
},
{ &hf_rtps_sm_wrentity_id_key, {
"writerEntityKey",
"rtps2.sm.wrEntityId.entityKey",
FT_UINT24,
BASE_HEX,
NULL,
0,
"'entityKey' field of the writer entity ID",
HFILL }
},
{ &hf_rtps_sm_wrentity_id_kind, {
"writerEntityKind",
"rtps2.sm.wrEntityId.entityKind",
FT_UINT8,
BASE_HEX,
VALS(entity_kind_vals),
0,
"'entityKind' field of the writer entity ID",
HFILL }
},
{ &hf_rtps_sm_seq_number, {
"writerSeqNumber",
"rtps2.sm.seqNumber",
FT_INT64,
BASE_DEC,
NULL,
0,
"Writer sequence number",
HFILL }
},
{ &hf_rtps_parameter_id, {
"parameterId",
"rtps2.param.id",
FT_UINT16,
BASE_HEX,
VALS(parameter_id_vals),
0,
"Parameter Id",
HFILL }
},
{ &hf_rtps_parameter_length, {
"parameterLength",
"rtps2.param.length",
FT_UINT16,
BASE_DEC,
NULL,
0,
"Parameter Length",
HFILL }
},
{ &hf_rtps_param_status_info, {
"statusInfo",
"rtps2.param.statusInfo",
FT_UINT32,
BASE_HEX,
NULL,
0,
"State information of the data object to which the message apply (i.e. lifecycle)",
HFILL }
},
{ &hf_rtps_param_ntpt, {
"ntpTime",
"rtps2.param.ntpTime",
FT_NONE,
BASE_NONE,
NULL,
0,
"Time using the NTP standard format",
HFILL }
},
{ &hf_rtps_param_ntpt_sec, {
"seconds",
"rtps2.param.ntpTime.sec",
FT_INT32,
BASE_DEC,
NULL,
0,
"The 'second' component of a NTP time",
HFILL }
},
{ &hf_rtps_param_ntpt_fraction, {
"fraction",
"rtps2.param.ntpTime.fraction",
FT_UINT32,
BASE_DEC,
NULL,
0,
"The 'fraction' component of a NTP time",
HFILL }
},
{ &hf_rtps_param_topic_name, {
"topic",
"rtps2.param.topicName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"String representing the value value of a PID_TOPIC parameter",
HFILL }
},
{ &hf_rtps_param_entity_name, {
"entity",
"rtps2.param.entityName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"String representing the name of the entity addressed by the submessage",
HFILL }
},
{ &hf_rtps_param_strength, {
"strength",
"rtps2.param.strength",
FT_INT32,
BASE_DEC,
NULL,
0,
"Decimal value representing the value of a PID_OWNERSHIP_STRENGTH parameter",
HFILL }
},
{ &hf_rtps_param_type_name, {
"typeName",
"rtps2.param.typeName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"String representing the value of a PID_TYPE_NAME parameter",
HFILL }
},
{ &hf_rtps_param_user_data, {
"userData",
"rtps2.param.userData",
FT_BYTES,
BASE_NONE,
NULL,
0,
"The user data sent in a PID_USER_DATA parameter",
HFILL }
},
{ &hf_rtps_param_group_data, {
"groupData",
"rtps2.param.groupData",
FT_BYTES,
BASE_NONE,
NULL,
0,
"The user data sent in a PID_GROUP_DATA parameter",
HFILL }
},
{ &hf_rtps_param_topic_data, {
"topicData",
"rtps2.param.topicData",
FT_BYTES,
BASE_NONE,
NULL,
0,
"The user data sent in a PID_TOPIC_DATA parameter",
HFILL }
},
{ &hf_rtps_param_content_filter_name, {
"contentFilterName",
"rtps2.param.contentFilterName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"Value of the content filter name as sent in a PID_CONTENT_FILTER_PROPERTY parameter",
HFILL }
},
{ &hf_rtps_param_related_topic_name, {
"relatedTopicName",
"rtps2.param.relatedTopicName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"Value of the related topic name as sent in a PID_CONTENT_FILTER_PROPERTY parameter",
HFILL }
},
{ &hf_rtps_param_filter_name, {
"filterName",
"rtps2.param.filterName",
FT_STRINGZ,
BASE_NONE,
NULL,
0,
"Value of the filter name as sent in a PID_CONTENT_FILTER_PROPERTY parameter",
HFILL }
},
{ &hf_rtps_issue_data, {
"serializedData",
"rtps2.serializedData",
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
&ett_rtps_part_message_data,
&ett_rtps_part_message_guid,
&ett_rtps_locator_udp_v4,
&ett_rtps_locator,
&ett_rtps_locator_list,
&ett_rtps_ntp_time,
&ett_rtps_bitmap,
&ett_rtps_seq_string,
&ett_rtps_seq_ulong,
&ett_rtps_serialized_data,
&ett_rtps_sample_info_list,
&ett_rtps_sample_info,
&ett_rtps_sample_batch_list,
&ett_rtps_locator_filter_channel,
&ett_rtps_locator_filter_locator
};
module_t *rtps_module;
proto_rtps = proto_register_protocol(
"Real-Time Publish-Subscribe Wire Protocol 2.x",
"RTPS2",
"rtps2");
proto_register_field_array(proto_rtps, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
rtps_module = prefs_register_protocol(proto_rtps, NULL);
prefs_register_uint_preference(rtps_module, "max_batch_samples_dissected",
"Max samples dissected for DATA_BATCH",
"Specifies the maximum number of samples dissected in "
"a DATA_BATCH submessage. Increasing this value may affect "
"performances if the trace has a lot of big batched samples.",
10, &rtps_max_batch_samples_dissected);
}
void proto_reg_handoff_rtps2(void) {
heur_dissector_add("udp", dissect_rtps, proto_rtps);
}
