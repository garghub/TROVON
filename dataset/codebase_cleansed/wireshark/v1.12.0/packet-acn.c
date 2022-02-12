static gboolean
is_acn(tvbuff_t *tvb)
{
static const char acn_packet_id[] = "ASC-E1.17\0\0\0";
if (tvb_length(tvb) < (4+sizeof(acn_packet_id)))
return FALSE;
if (tvb_memeql(tvb, 4, acn_packet_id, sizeof(acn_packet_id)-1) != 0)
return FALSE;
return TRUE;
}
static gboolean
dissect_acn_heur( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_ )
{
if (!global_acn_heur) return FALSE;
if (!is_acn(tvb)) return FALSE;
dissect_acn(tvb, pinfo, tree);
return TRUE;
}
static guint32
acn_add_channel_owner_info_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pi;
proto_tree *this_tree;
guint32 session_count;
guint32 x;
pi = proto_tree_add_text(tree, tvb, offset, 8, "Channel Owner Info Block");
this_tree = proto_item_add_subtree(pi, ett_acn_channel_owner_info_block);
proto_tree_add_item(this_tree, hf_acn_member_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(this_tree, hf_acn_channel_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += acn_add_address(tvb, pinfo, this_tree, offset, "Destination Address:");
offset += acn_add_address(tvb, pinfo, this_tree, offset, "Source Address:");
session_count = tvb_get_ntohs(tvb, offset);
for (x=0; x<session_count; x++) {
pi = proto_tree_add_item(this_tree, hf_acn_protocol_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(pi, " #%d", x+1);
offset += 4;
}
return offset;
}
static guint32
acn_add_channel_member_info_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *pi;
proto_tree *this_tree;
guint32 session_count;
guint32 x;
pi = proto_tree_add_text(tree, tvb, offset, 8, "Channel Member Info Block");
this_tree = proto_item_add_subtree(pi, ett_acn_channel_member_info_block);
proto_tree_add_item(this_tree, hf_acn_member_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(this_tree, hf_acn_cid, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(this_tree, hf_acn_channel_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += acn_add_address(tvb, pinfo, this_tree, offset, "Destination Address:");
offset += acn_add_address(tvb, pinfo, this_tree, offset, "Source Address:");
proto_tree_add_item(this_tree, hf_acn_reciprocal_channel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
session_count = tvb_get_ntohs(tvb, offset);
for (x=0; x<session_count; x++) {
pi = proto_tree_add_item(this_tree, hf_acn_protocol_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(pi, " #%d", x+1);
offset += 4;
}
return offset;
}
static guint32
acn_add_expiry(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, const char *label)
{
proto_tree_add_text(tree, tvb, offset, 2, "%s %d", label, tvb_get_guint8(tvb, offset));
offset += 1;
return offset;
}
static guint32
acn_add_channel_parameter(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *pi;
proto_tree *param_tree;
pi = proto_tree_add_text(tree, tvb, offset, 8, "Channel Parameter Block");
param_tree = proto_item_add_subtree(pi, ett_acn_channel_parameter);
proto_tree_add_item(param_tree, hf_acn_expiry, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(param_tree, hf_acn_nak_outbound_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(param_tree, hf_acn_nak_holdoff, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(param_tree, hf_acn_nak_modulus, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(param_tree, hf_acn_nak_max_wait, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static guint32
acn_add_address(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, const char *label)
{
proto_item *pi;
proto_tree *addr_tree = NULL;
guint8 ip_address_type;
address addr;
guint32 IPv4;
guint32 port;
struct e_in6_addr IPv6;
ip_address_type = tvb_get_guint8(tvb, offset);
switch (ip_address_type) {
case ACN_ADDR_NULL:
proto_tree_add_item(tree, hf_acn_ip_address_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case ACN_ADDR_IPV4:
pi = proto_tree_add_text(tree, tvb, offset, 7, "%s", label);
addr_tree = proto_item_add_subtree(pi, ett_acn_address);
proto_tree_add_item(addr_tree, hf_acn_ip_address_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
port = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(addr_tree, hf_acn_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(addr_tree, hf_acn_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
IPv4 = tvb_get_ipv4(tvb, offset);
SET_ADDRESS(&addr, AT_IPv4, sizeof(IPv4), &IPv4);
proto_item_append_text(pi, " %s, Port %d", address_to_str(wmem_packet_scope(), &addr), port);
offset += 4;
break;
case ACN_ADDR_IPV6:
pi = proto_tree_add_text(tree, tvb, offset, 19, "%s", label);
addr_tree = proto_item_add_subtree(pi, ett_acn_address);
proto_tree_add_item(addr_tree, hf_acn_ip_address_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
port = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(addr_tree, hf_acn_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(addr_tree, hf_acn_ipv6, tvb, offset, 16, ENC_NA);
tvb_get_ipv6(tvb, offset, &IPv6);
SET_ADDRESS(&addr, AT_IPv6, sizeof(struct e_in6_addr), &IPv6);
proto_item_append_text(pi, " %s, Port %d", address_to_str(wmem_packet_scope(), &addr), port);
offset += 16;
break;
case ACN_ADDR_IPPORT:
pi = proto_tree_add_text(tree, tvb, offset, 3, "%s", label);
addr_tree = proto_item_add_subtree(pi, ett_acn_address);
proto_tree_add_item(addr_tree, hf_acn_ip_address_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
port = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(addr_tree, hf_acn_port, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pi, " %s Port %d", address_to_str(wmem_packet_scope(), &addr), port);
offset += 2;
break;
}
return offset;
}
static guint32
acn_add_dmp_address_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, acn_dmp_adt_type *adt)
{
proto_item *pi;
proto_tree *this_tree = NULL;
guint8 D;
const gchar *name;
adt->flags = tvb_get_guint8(tvb, offset);
D = ACN_DMP_ADT_EXTRACT_D(adt->flags);
name = val_to_str(D, acn_dmp_adt_d_vals, "not valid (%d)");
pi = proto_tree_add_text(tree, tvb, offset, 1, "Address and Data Type: %s", name);
this_tree = proto_item_add_subtree(pi, ett_acn_address_type);
proto_tree_add_uint(this_tree, hf_acn_dmp_adt_v, tvb, offset, 1, adt->flags);
proto_tree_add_uint(this_tree, hf_acn_dmp_adt_r, tvb, offset, 1, adt->flags);
proto_tree_add_uint(this_tree, hf_acn_dmp_adt_d, tvb, offset, 1, adt->flags);
proto_tree_add_uint(this_tree, hf_acn_dmp_adt_x, tvb, offset, 1, adt->flags);
proto_tree_add_uint(this_tree, hf_acn_dmp_adt_a, tvb, offset, 1, adt->flags);
offset += 1;
return offset;
}
static guint32
acn_add_dmp_address(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, acn_dmp_adt_type *adt)
{
guint32 start_offset;
guint32 bytes_used;
guint8 D, A;
start_offset = offset;
D = ACN_DMP_ADT_EXTRACT_D(adt->flags);
A = ACN_DMP_ADT_EXTRACT_A(adt->flags);
switch (D) {
case ACN_DMP_ADT_D_NS:
adt->increment = 1;
adt->count = 1;
switch (A) {
case ACN_DMP_ADT_A_1:
adt->address = tvb_get_guint8(tvb, offset);
offset += 1;
bytes_used = 1;
break;
case ACN_DMP_ADT_A_2:
adt->address = tvb_get_ntohs(tvb, offset);
offset += 2;
bytes_used = 2;
break;
case ACN_DMP_ADT_A_4:
adt->address = tvb_get_ntohl(tvb, offset);
offset += 4;
bytes_used = 4;
break;
default:
return offset;
}
if (adt->flags & ACN_DMP_ADT_FLAG_V) {
proto_tree_add_text(tree, tvb, start_offset, bytes_used, "Virtual Address: 0x%X", adt->address);
} else {
proto_tree_add_text(tree, tvb, start_offset, bytes_used, "Actual Address: 0x%X", adt->address);
}
break;
case ACN_DMP_ADT_D_RS:
switch (A) {
case ACN_DMP_ADT_A_1:
adt->address = tvb_get_guint8(tvb, offset);
offset += 1;
adt->increment = tvb_get_guint8(tvb, offset);
offset += 1;
adt->count = tvb_get_guint8(tvb, offset);
offset += 1;
bytes_used = 3;
break;
case ACN_DMP_ADT_A_2:
adt->address = tvb_get_ntohs(tvb, offset);
offset += 2;
adt->increment = tvb_get_ntohs(tvb, offset);
offset += 2;
adt->count = tvb_get_ntohs(tvb, offset);
offset += 2;
bytes_used = 6;
break;
case ACN_DMP_ADT_A_4:
adt->address = tvb_get_ntohl(tvb, offset);
offset += 4;
adt->increment = tvb_get_ntohl(tvb, offset);
offset += 4;
adt->count = tvb_get_ntohl(tvb, offset);
offset += 4;
bytes_used = 12;
break;
default:
return offset;
}
if (adt->flags & ACN_DMP_ADT_FLAG_V) {
proto_tree_add_text(tree, tvb, start_offset, bytes_used,
"Virtual Address first: 0x%X, inc: %d, count: %d",
adt->address, adt->increment, adt->count);
} else {
proto_tree_add_text(tree, tvb, start_offset, bytes_used,
"Actual Address first: 0x%X, inc: %d, count: %d",
adt->address, adt->increment, adt->count);
}
break;
case ACN_DMP_ADT_D_RE:
switch (A) {
case ACN_DMP_ADT_A_1:
adt->address = tvb_get_guint8(tvb, offset);
offset += 1;
adt->increment = tvb_get_guint8(tvb, offset);
offset += 1;
adt->count = tvb_get_guint8(tvb, offset);
offset += 1;
bytes_used = 3;
break;
case ACN_DMP_ADT_A_2:
adt->address = tvb_get_ntohs(tvb, offset);
offset += 2;
adt->increment = tvb_get_ntohs(tvb, offset);
offset += 2;
adt->count = tvb_get_ntohs(tvb, offset);
offset += 2;
bytes_used = 6;
break;
case ACN_DMP_ADT_A_4:
adt->address = tvb_get_ntohl(tvb, offset);
offset += 4;
adt->increment = tvb_get_ntohl(tvb, offset);
offset += 4;
adt->count = tvb_get_ntohl(tvb, offset);
offset += 4;
bytes_used = 12;
break;
default:
return offset;
}
if (adt->flags & ACN_DMP_ADT_FLAG_V) {
proto_tree_add_text(tree, tvb, start_offset, bytes_used,
"Virtual Address first: 0x%X, inc: %d, count: %d",
adt->address, adt->increment, adt->count);
} else {
proto_tree_add_text(tree, tvb, start_offset, bytes_used,
"Actual Address first: 0x%X, inc: %d, count: %d",
adt->address, adt->increment, adt->count);
}
break;
case ACN_DMP_ADT_D_RM:
switch (A) {
case ACN_DMP_ADT_A_1:
adt->address = tvb_get_guint8(tvb, offset);
offset += 1;
adt->increment = tvb_get_guint8(tvb, offset);
offset += 1;
adt->count = tvb_get_guint8(tvb, offset);
offset += 1;
bytes_used = 3;
break;
case ACN_DMP_ADT_A_2:
adt->address = tvb_get_ntohs(tvb, offset);
offset += 2;
adt->increment = tvb_get_ntohs(tvb, offset);
offset += 2;
adt->count = tvb_get_ntohs(tvb, offset);
offset += 2;
bytes_used = 6;
break;
case ACN_DMP_ADT_A_4:
adt->address = tvb_get_ntohl(tvb, offset);
offset += 4;
adt->increment = tvb_get_ntohl(tvb, offset);
offset += 4;
adt->count = tvb_get_ntohl(tvb, offset);
offset += 4;
bytes_used = 12;
break;
default:
return offset;
}
if (adt->flags & ACN_DMP_ADT_FLAG_V) {
proto_tree_add_text(tree, tvb, start_offset, bytes_used,
"Virtual Address first: 0x%X, inc: %d, count: %d",
adt->address, adt->increment, adt->count);
} else {
proto_tree_add_text(tree, tvb, start_offset, bytes_used,
"Actual Address first: 0x%X, inc: %d, count: %d",
adt->address, adt->increment, adt->count);
}
break;
}
return offset;
}
static guint32
acn_add_dmp_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, acn_dmp_adt_type *adt)
{
guint8 D, A;
guint32 data_size;
guint32 data_value;
guint32 data_address;
guint32 x,y;
gchar buffer[BUFFER_SIZE];
proto_item *ti;
guint32 ok_to_process = FALSE;
buffer[0] = 0;
D = ACN_DMP_ADT_EXTRACT_D(adt->flags);
switch (D) {
case ACN_DMP_ADT_D_NS:
case ACN_DMP_ADT_D_RS:
if (adt->data_length <= adt->count + 4) {
ok_to_process = TRUE;
}
break;
case ACN_DMP_ADT_D_RE:
if (adt->count == 0) {
break;
}
if (adt->data_length <= adt->count + 4) {
ok_to_process = TRUE;
}
break;
}
if (!ok_to_process) {
data_size = adt->data_length;
ti = proto_tree_add_item(tree, hf_acn_data, tvb, offset, data_size, ENC_NA);
offset += data_size;
proto_item_set_text(ti, "Data and more Address-Data Pairs (further dissection not possible)");
return offset;
}
A = ACN_DMP_ADT_EXTRACT_A(adt->flags);
switch (D) {
case ACN_DMP_ADT_D_NS:
data_size = adt->data_length;
data_address = adt->address;
switch (A) {
case ACN_DMP_ADT_A_1:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%2.2X ->", data_address);
break;
case ACN_DMP_ADT_A_2:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%4.4X ->", data_address);
break;
case ACN_DMP_ADT_A_4:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%8.8X ->", data_address);
break;
default:
offset += data_size;
return offset;
}
switch (data_size) {
case 1:
data_value = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 1, data_value, "%s %2.2X", buffer, data_value);
break;
case 2:
data_value = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data16, tvb, offset, 2, data_value, "%s %4.4X", buffer, data_value);
break;
case 3:
data_value = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data24, tvb, offset, 3, data_value, "%s %6.6X", buffer, data_value);
break;
case 4:
data_value = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data32, tvb, offset, 4, data_value, "%s %8.8X", buffer, data_value);
break;
default:
for (y=0; y<20 && y<data_size; y++) {
data_value = tvb_get_guint8(tvb, offset+y);
g_snprintf(buffer, BUFFER_SIZE, "%s %2.2X", buffer, data_value);
}
ti = proto_tree_add_item(tree, hf_acn_data, tvb, offset, data_size, ENC_NA);
offset += data_size;
proto_item_set_text(ti, "%s", buffer);
break;
}
offset += data_size;
break;
case ACN_DMP_ADT_D_RS:
data_size = adt->data_length;
data_address = adt->address;
for (x=0; x<adt->count; x++) {
switch (A) {
case ACN_DMP_ADT_A_1:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%2.2X ->", data_address);
break;
case ACN_DMP_ADT_A_2:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%4.4X ->", data_address);
break;
case ACN_DMP_ADT_A_4:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%8.8X ->", data_address);
break;
default:
return offset;
}
switch (data_size) {
case 1:
data_value = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 1, data_value, "%s %2.2X", buffer, data_value);
break;
case 2:
data_value = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 2, data_value, "%s %4.4X", buffer, data_value);
break;
case 3:
data_value = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 3, data_value, "%s %6.6X", buffer, data_value);
break;
case 4:
data_value = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 4, data_value, "%s %8.8X", buffer, data_value);
break;
default:
for (y=0; y<20 && y<data_size; y++) {
data_value = tvb_get_guint8(tvb, offset+y);
g_snprintf(buffer, BUFFER_SIZE, "%s %2.2X", buffer, data_value);
}
ti = proto_tree_add_item(tree, hf_acn_data, tvb, offset, data_size, ENC_NA);
proto_item_set_text(ti, "%s", buffer);
break;
}
data_address += adt->increment;
}
offset += data_size;
break;
case ACN_DMP_ADT_D_RE:
data_size = adt->data_length / adt->count;
data_address = adt->address;
for (x=0; x<adt->count; x++) {
switch (A) {
case ACN_DMP_ADT_A_1:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%2.2X ->", data_address);
break;
case ACN_DMP_ADT_A_2:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%4.4X ->", data_address);
break;
case ACN_DMP_ADT_A_4:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%8.8X ->", data_address);
break;
default:
return offset;
}
switch (data_size) {
case 1:
data_value = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 1, data_value, "%s %2.2X", buffer, data_value);
break;
case 2:
data_value = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 2, data_value, "%s %4.4X", buffer, data_value);
break;
case 3:
data_value = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 3, data_value, "%s %6.6X", buffer, data_value);
break;
case 4:
data_value = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 4, data_value, "%s %8.8X", buffer, data_value);
break;
default:
for (y=0; y<20 && y<data_size; y++) {
data_value = tvb_get_guint8(tvb, offset+y);
g_snprintf(buffer, BUFFER_SIZE, "%s %2.2X", buffer, data_value);
}
ti = proto_tree_add_item(tree, hf_acn_data, tvb, offset, data_size, ENC_NA);
proto_item_set_text(ti, "%s", buffer);
break;
}
offset += data_size;
data_address += adt->increment;
}
break;
case ACN_DMP_ADT_D_RM:
data_size = adt->data_length;
ti = proto_tree_add_item(tree, hf_acn_data, tvb, offset, data_size, ENC_NA);
offset += data_size;
proto_item_set_text(ti, "Mixed size data items");
break;
}
return offset;
}
static guint32
acn_add_dmp_reason_codes(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, acn_dmp_adt_type *adt)
{
guint8 D, A;
guint32 data_value;
guint32 data_address;
guint32 x;
gchar buffer[BUFFER_SIZE];
const gchar *name;
buffer[0] = 0;
D = ACN_DMP_ADT_EXTRACT_D(adt->flags);
A = ACN_DMP_ADT_EXTRACT_A(adt->flags);
switch (D) {
case ACN_DMP_ADT_D_NS:
data_address = adt->address;
switch (A) {
case ACN_DMP_ADT_A_1:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%2.2X ->", data_address);
break;
case ACN_DMP_ADT_A_2:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%4.4X ->", data_address);
break;
case ACN_DMP_ADT_A_4:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%8.8X ->", data_address);
break;
default:
return offset;
}
data_value = tvb_get_guint8(tvb, offset);
name = val_to_str(data_value, acn_dmp_reason_code_vals, "reason not valid (%d)");
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 1, data_value, "%s %s", buffer, name);
offset += 1;
break;
case ACN_DMP_ADT_D_RS:
data_address = adt->address;
for (x=0; x<adt->count; x++) {
switch (A) {
case ACN_DMP_ADT_A_1:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%2.2X ->", data_address);
break;
case ACN_DMP_ADT_A_2:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%4.4X ->", data_address);
break;
case ACN_DMP_ADT_A_4:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%8.8X ->", data_address);
break;
default:
return offset;
}
data_value = tvb_get_guint8(tvb, offset);
name = val_to_str(data_value, acn_dmp_reason_code_vals, "reason not valid (%d)");
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 1, data_value, "%s %s", buffer, name);
data_address += adt->increment;
}
offset += 1;
break;
case ACN_DMP_ADT_D_RE:
case ACN_DMP_ADT_D_RM:
data_address = adt->address;
for (x=0; x<adt->count; x++) {
switch (A) {
case ACN_DMP_ADT_A_1:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%2.2X ->", data_address);
break;
case ACN_DMP_ADT_A_2:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%4.4X ->", data_address);
break;
case ACN_DMP_ADT_A_4:
g_snprintf(buffer, BUFFER_SIZE, "Addr 0x%8.8X ->", data_address);
break;
default:
return offset;
}
data_value = tvb_get_guint8(tvb, offset);
name = val_to_str(data_value, acn_dmp_reason_code_vals, "reason not valid (%d)");
proto_tree_add_uint_format(tree, hf_acn_data8, tvb, offset, 1, data_value, "%s %s", buffer, name);
data_address += adt->increment;
offset += 1;
}
break;
}
return offset;
}
static guint32
dissect_acn_dmp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, acn_pdu_offsets *last_pdu_offsets)
{
guint8 pdu_flags;
guint32 pdu_start;
guint32 pdu_length;
guint32 pdu_flvh_length;
guint8 D;
guint8 octet;
guint32 length1;
guint32 length2;
guint32 length3;
guint32 vector_offset;
guint32 header_offset;
guint32 data_offset;
guint32 old_offset;
guint32 end_offset;
guint32 data_length;
guint32 address_count;
proto_item *ti, *pi;
proto_tree *pdu_tree = NULL;
proto_tree *flag_tree = NULL;
const gchar *name;
acn_dmp_adt_type adt = {0,0,0,0,0,0};
acn_dmp_adt_type adt2 = {0,0,0,0,0,0};
guint32 vector;
pdu_start = offset;
octet = tvb_get_guint8(tvb, offset++);
pdu_flags = octet & 0xf0;
length1 = octet & 0x0f;
length2 = tvb_get_guint8(tvb, offset++);
if (pdu_flags & ACN_PDU_FLAG_L) {
length3 = tvb_get_guint8(tvb, offset);
offset += 1;
pdu_length = length3 | (length2 << 8) | (length1 << 16);
pdu_flvh_length = 3;
} else {
pdu_length = length2 | (length1 << 8);
pdu_flvh_length = 2;
}
ti = proto_tree_add_item(tree, hf_acn_pdu, tvb, pdu_start, pdu_length, ENC_NA);
pdu_tree = proto_item_add_subtree(ti, ett_acn_dmp_pdu);
pi = proto_tree_add_uint(pdu_tree, hf_acn_pdu_flags, tvb, pdu_start, 1, pdu_flags);
flag_tree = proto_item_add_subtree(pi, ett_acn_pdu_flags);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_l, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_v, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_h, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_d, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(pdu_tree, hf_acn_pdu_length, tvb, pdu_start, pdu_flvh_length, pdu_length);
if (pdu_flags & ACN_PDU_FLAG_V) {
vector_offset = offset;
last_pdu_offsets->vector = offset;
offset += 1;
pdu_flvh_length++;
} else {
vector_offset = last_pdu_offsets->vector;
}
vector = tvb_get_guint8(tvb, vector_offset);
proto_tree_add_uint(pdu_tree, hf_acn_dmp_vector, tvb, vector_offset, 1, vector);
name = val_to_str(vector, acn_dmp_vector_vals, "not valid (%d)");
proto_item_append_text(ti, ": ");
proto_item_append_text(ti, "%s", name);
if (pdu_flags & ACN_PDU_FLAG_H) {
header_offset = offset;
last_pdu_offsets->header = offset;
offset += 1;
pdu_flvh_length++;
} else {
header_offset = last_pdu_offsets->header;
}
acn_add_dmp_address_type(tvb, pinfo, pdu_tree, header_offset, &adt);
if (pdu_flags & ACN_PDU_FLAG_D) {
data_offset = offset;
data_length = pdu_length - pdu_flvh_length;
last_pdu_offsets->data = offset;
last_pdu_offsets->data_length = data_length;
} else {
data_offset = last_pdu_offsets->data;
data_length = last_pdu_offsets->data_length;
}
end_offset = data_offset + data_length;
switch (vector) {
case ACN_DMP_VECTOR_UNKNOWN:
break;
case ACN_DMP_VECTOR_GET_PROPERTY:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_SET_PROPERTY:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
adt.data_length = data_length - (data_offset - old_offset);
old_offset = data_offset;
data_offset = acn_add_dmp_data(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_GET_PROPERTY_REPLY:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
adt.data_length = data_length - (data_offset - old_offset);
old_offset = data_offset;
data_offset = acn_add_dmp_data(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_EVENT:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
adt.data_length = data_length - (data_offset - old_offset);
old_offset = data_offset;
data_offset = acn_add_dmp_data(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_MAP_PROPERTY:
data_offset = acn_add_dmp_address_type(tvb, pinfo, pdu_tree, data_offset, &adt2);
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
D = ACN_DMP_ADT_EXTRACT_D(adt.flags);
switch (D) {
case ACN_DMP_ADT_D_NS:
address_count = 1;
break;
case ACN_DMP_ADT_D_RS:
address_count = 1;
break;
case ACN_DMP_ADT_D_RE:
address_count = adt.count;
break;
default:
return pdu_start + pdu_length;
break;
}
while (address_count > 0) {
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt2);
address_count--;
}
}
break;
case ACN_DMP_VECTOR_UNMAP_PROPERTY:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_SUBSCRIBE:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_UNSUBSCRIBE:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_GET_PROPERTY_FAIL:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
adt.data_length = data_length - (data_offset - old_offset);
old_offset = data_offset;
data_offset = acn_add_dmp_reason_codes(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_SET_PROPERTY_FAIL:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
adt.data_length = data_length - (data_offset - old_offset);
old_offset = data_offset;
data_offset = acn_add_dmp_reason_codes(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_MAP_PROPERTY_FAIL:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
adt.data_length = data_length - (data_offset - old_offset);
old_offset = data_offset;
data_offset = acn_add_dmp_reason_codes(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_SUBSCRIBE_ACCEPT:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_SUBSCRIBE_REJECT:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = acn_add_dmp_address(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
adt.data_length = data_length - (data_offset - old_offset);
old_offset = data_offset;
data_offset = acn_add_dmp_reason_codes(tvb, pinfo, pdu_tree, data_offset, &adt);
if (old_offset == data_offset) break;
}
break;
case ACN_DMP_VECTOR_ALLOCATE_MAP:
break;
case ACN_DMP_VECTOR_ALLOCATE_MAP_REPLY:
proto_tree_add_item(pdu_tree, hf_acn_dmp_reason_code, tvb, data_offset, 1, ENC_BIG_ENDIAN);
case ACN_DMP_VECTOR_DEALLOCATE_MAP:
break;
}
return pdu_start + pdu_length;
}
static guint32
dissect_acn_sdt_wrapped_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, int offset, acn_pdu_offsets *last_pdu_offsets)
{
guint8 pdu_flags;
guint32 pdu_start;
guint32 pdu_length;
guint32 pdu_flvh_length;
guint8 octet;
guint32 length1;
guint32 length2;
guint32 length3;
guint32 vector_offset;
guint32 data_offset;
guint32 data_length;
proto_item *ti, *pi;
proto_tree *pdu_tree = NULL;
proto_tree *flag_tree = NULL;
const gchar *name;
guint32 vector;
pdu_start = offset;
octet = tvb_get_guint8(tvb, offset++);
pdu_flags = octet & 0xf0;
length1 = octet & 0x0f;
length2 = tvb_get_guint8(tvb, offset++);
if (pdu_flags & ACN_PDU_FLAG_L) {
length3 = tvb_get_guint8(tvb, offset);
offset += 1;
pdu_length = length3 | (length2 << 8) | (length1 << 16);
pdu_flvh_length = 3;
} else {
pdu_length = length2 | (length1 << 8);
pdu_flvh_length = 2;
}
ti = proto_tree_add_item(tree, hf_acn_pdu, tvb, pdu_start, pdu_length, ENC_NA);
pdu_tree = proto_item_add_subtree(ti, ett_acn_sdt_pdu);
pi = proto_tree_add_uint(pdu_tree, hf_acn_pdu_flags, tvb, pdu_start, 1, pdu_flags);
flag_tree = proto_item_add_subtree(pi, ett_acn_pdu_flags);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_l, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_v, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_h, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_d, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(pdu_tree, hf_acn_pdu_length, tvb, pdu_start, pdu_flvh_length, pdu_length);
if (pdu_flags & ACN_PDU_FLAG_V) {
vector_offset = offset;
last_pdu_offsets->vector = offset;
offset += 1;
pdu_flvh_length++;
} else {
vector_offset = last_pdu_offsets->vector;
}
vector = tvb_get_guint8(tvb, vector_offset);
proto_tree_add_uint(pdu_tree, hf_acn_sdt_vector, tvb, vector_offset, 1, vector);
name = val_to_str(vector, acn_sdt_vector_vals, "not valid (%d)");
proto_item_append_text(ti, ": ");
proto_item_append_text(ti, "%s", name);
if (pdu_flags & ACN_PDU_FLAG_D) {
data_offset = offset;
data_length = pdu_length - pdu_flvh_length;
last_pdu_offsets->data = offset;
last_pdu_offsets->data_length = data_length;
} else {
data_offset = last_pdu_offsets->data;
}
switch (vector) {
case ACN_SDT_VECTOR_ACK:
proto_tree_add_item(pdu_tree, hf_acn_reliable_sequence_number, tvb, data_offset, 4, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_CHANNEL_PARAMS:
data_offset = acn_add_channel_parameter(tvb, pinfo, pdu_tree, data_offset);
data_offset = acn_add_address(tvb, pinfo, pdu_tree, data_offset, "Ad-hoc Address:");
acn_add_expiry(tvb, pinfo, pdu_tree, data_offset, "Ad-hoc Expiry:");
break;
case ACN_SDT_VECTOR_LEAVE:
break;
case ACN_SDT_VECTOR_CONNECT:
proto_tree_add_item(pdu_tree, hf_acn_protocol_id, tvb, data_offset, 4, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_CONNECT_ACCEPT:
proto_tree_add_item(pdu_tree, hf_acn_protocol_id, tvb, data_offset, 4, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_CONNECT_REFUSE:
proto_tree_add_item(pdu_tree, hf_acn_protocol_id, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_refuse_code, tvb, data_offset, 1, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_DISCONNECT:
proto_tree_add_item(pdu_tree, hf_acn_protocol_id, tvb, data_offset, 4, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_DISCONNECTING:
proto_tree_add_item(pdu_tree, hf_acn_protocol_id, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_reason_code, tvb, data_offset, 1, ENC_BIG_ENDIAN);
break;
}
return pdu_start + pdu_length;
}
static guint32
dissect_acn_sdt_client_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, acn_pdu_offsets *last_pdu_offsets)
{
guint8 pdu_flags;
guint32 pdu_start;
guint32 pdu_length;
guint32 pdu_flvh_length;
acn_pdu_offsets pdu_offsets = {0,0,0,0,0};
guint8 octet;
guint32 length1;
guint32 length2;
guint32 length3;
guint32 vector_offset;
guint32 header_offset;
guint32 data_offset;
guint32 data_length;
guint32 old_offset;
guint32 end_offset;
proto_item *ti, *pi;
proto_tree *pdu_tree = NULL;
proto_tree *flag_tree = NULL;
const gchar *name;
guint32 member_id;
guint32 protocol_id;
guint16 association;
pdu_start = offset;
pdu_offsets.start = pdu_start;
octet = tvb_get_guint8(tvb, offset++);
pdu_flags = octet & 0xf0;
length1 = octet & 0x0f;
length2 = tvb_get_guint8(tvb, offset++);
if (pdu_flags & ACN_PDU_FLAG_L) {
length3 = tvb_get_guint8(tvb, offset);
offset += 1;
pdu_length = length3 | (length2 << 8) | (length1 << 16);
pdu_flvh_length = 3;
} else {
pdu_length = length2 | (length1 << 8);
pdu_flvh_length = 2;
}
ti = proto_tree_add_item(tree, hf_acn_pdu, tvb, pdu_start, pdu_length, ENC_NA);
pdu_tree = proto_item_add_subtree(ti, ett_acn_sdt_client_pdu);
pi = proto_tree_add_uint(pdu_tree, hf_acn_pdu_flags, tvb, pdu_start, 1, pdu_flags);
flag_tree = proto_item_add_subtree(pi, ett_acn_pdu_flags);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_l, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_v, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_h, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_d, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(pdu_tree, hf_acn_pdu_length, tvb, pdu_start, pdu_flvh_length, pdu_length);
if (pdu_flags & ACN_PDU_FLAG_V) {
vector_offset = offset;
last_pdu_offsets->vector = offset;
offset += 2;
pdu_flvh_length += 2;
} else {
vector_offset = last_pdu_offsets->vector;
}
member_id = tvb_get_ntohs(tvb, vector_offset);
proto_tree_add_uint(pdu_tree, hf_acn_member_id, tvb, vector_offset, 2, member_id);
if (pdu_flags & ACN_PDU_FLAG_H) {
header_offset = offset;
last_pdu_offsets->header = offset;
offset += 6;
pdu_flvh_length += 6;
} else {
header_offset = last_pdu_offsets->header;
}
protocol_id = tvb_get_ntohl(tvb, header_offset);
proto_tree_add_uint(pdu_tree, hf_acn_protocol_id, tvb, header_offset, 4, protocol_id);
header_offset += 4;
name = val_to_str(protocol_id, acn_protocol_id_vals, "id not valid (%d)");
proto_item_append_text(ti, ": ");
proto_item_append_text(ti, "%s", name);
association = tvb_get_ntohs(tvb, header_offset);
proto_tree_add_uint(pdu_tree, hf_acn_association, tvb, header_offset, 2, association);
if (pdu_flags & ACN_PDU_FLAG_D) {
data_offset = offset;
data_length = pdu_length - pdu_flvh_length;
last_pdu_offsets->data = offset;
last_pdu_offsets->data_length = data_length;
} else {
data_offset = last_pdu_offsets->data;
data_length = last_pdu_offsets->data_length;
}
end_offset = data_offset + data_length;
switch (protocol_id) {
case ACN_PROTOCOL_ID_SDT:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = dissect_acn_sdt_wrapped_pdu(tvb, pinfo, pdu_tree, data_offset, &pdu_offsets);
if (old_offset == data_offset) break;
}
break;
case ACN_PROTOCOL_ID_DMP:
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = dissect_acn_dmp_pdu(tvb, pinfo, pdu_tree, data_offset, &pdu_offsets);
if (data_offset == old_offset) break;
}
break;
}
return pdu_start + pdu_length;
}
static char *
ltos(guint8 level, gchar *string, guint8 base, gchar leading_char, guint8 min_chars, gboolean show_zero)
{
guint8 i;
if (base < 2 || base > 16) {
*string = '\0';
return(string);
}
if ((level == 0) && (!show_zero)) {
for (i=0; i<min_chars; i++) {
string[i] = '.';
}
string[i++] = ' ';
string[i] = '\0';
return(string + i);
}
i = 0;
do {
string[i++] = "0123456789ABCDEF"[level % base];
} while ((level /= base) > 0);
for (; i<min_chars; i++) {
string[i] = leading_char;
}
string[i] = '\0';
g_strreverse(string);
string[i++] = ' ';
string[i] = '\0';
return(string + i);
}
static guint32
dissect_acn_dmx_data_pdu(guint32 protocol_id, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, acn_pdu_offsets *last_pdu_offsets)
{
guint8 pdu_flags;
guint32 pdu_start;
guint32 pdu_length;
guint32 pdu_flvh_length;
guint8 octet;
guint32 length1;
guint32 length2;
guint32 length3;
guint32 vector_offset;
guint32 data_offset;
guint32 end_offset;
guint32 data_length;
guint32 header_offset;
guint32 total_cnt;
guint32 item_cnt;
proto_item *ti, *pi;
proto_tree *pdu_tree = NULL;
proto_tree *flag_tree = NULL;
acn_dmp_adt_type adt = {0,0,0,0,0,0};
const gchar *name;
guint32 vector;
gchar buffer[BUFFER_SIZE];
char *buf_ptr;
guint x;
guint8 level;
guint8 min_char;
guint8 base;
gchar leading_char;
guint perline;
guint halfline;
guint16 dmx_count;
guint16 dmx_start_code;
buffer[0] = 0;
pdu_start = offset;
octet = tvb_get_guint8(tvb, offset++);
pdu_flags = octet & 0xf0;
length1 = octet & 0x0f;
length2 = tvb_get_guint8(tvb, offset++);
if (pdu_flags & ACN_PDU_FLAG_L) {
length3 = tvb_get_guint8(tvb, offset);
offset += 1;
pdu_length = length3 | (length2 << 8) | (length1 << 16);
pdu_flvh_length = 3;
} else {
pdu_length = length2 | (length1 << 8);
pdu_flvh_length = 2;
}
ti = proto_tree_add_item(tree, hf_acn_pdu, tvb, pdu_start, pdu_length, ENC_NA);
pdu_tree = proto_item_add_subtree(ti, ett_acn_dmx_data_pdu);
pi = proto_tree_add_uint(pdu_tree, hf_acn_pdu_flags, tvb, pdu_start, 1, pdu_flags);
flag_tree = proto_item_add_subtree(pi, ett_acn_pdu_flags);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_l, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_v, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_h, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_d, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(pdu_tree, hf_acn_pdu_length, tvb, pdu_start, pdu_flvh_length, pdu_length);
if (pdu_flags & ACN_PDU_FLAG_V) {
vector_offset = offset;
last_pdu_offsets->vector = offset;
offset += 1;
pdu_flvh_length += 1;
} else {
vector_offset = last_pdu_offsets->vector;
}
vector = tvb_get_guint8(tvb, vector_offset);
proto_tree_add_uint(pdu_tree, hf_acn_dmp_vector, tvb, vector_offset, 1, vector);
name = val_to_str(vector, acn_dmp_vector_vals, "not valid (%d)");
proto_item_append_text(ti, ": ");
proto_item_append_text(ti, "%s", name);
if (pdu_flags & ACN_PDU_FLAG_H) {
header_offset = offset;
last_pdu_offsets->header = offset;
offset += 1;
pdu_flvh_length++;
} else {
header_offset = last_pdu_offsets->header;
}
acn_add_dmp_address_type(tvb, pinfo, pdu_tree, header_offset, &adt);
if (pdu_flags & ACN_PDU_FLAG_D) {
data_offset = offset;
data_length = pdu_length - pdu_flvh_length;
last_pdu_offsets->data = offset;
last_pdu_offsets->data_length = data_length;
} else {
data_offset = last_pdu_offsets->data;
data_length = last_pdu_offsets->data_length;
}
end_offset = data_offset + data_length;
switch (vector) {
case ACN_DMP_VECTOR_SET_PROPERTY:
dmx_start_code = tvb_get_ntohs(tvb, data_offset);
if (protocol_id==ACN_PROTOCOL_ID_DMX_2) {
proto_tree_add_item(pdu_tree, hf_acn_dmx_2_first_property_address, tvb, data_offset, 2, ENC_BIG_ENDIAN);
} else{
proto_tree_add_item(pdu_tree, hf_acn_dmx_start_code, tvb, data_offset, 2, ENC_BIG_ENDIAN);
}
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_dmx_increment, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
dmx_count = tvb_get_ntohs(tvb, data_offset);
proto_tree_add_item(pdu_tree, hf_acn_dmx_count, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
if (protocol_id==ACN_PROTOCOL_ID_DMX_2) {
proto_tree_add_item(pdu_tree, hf_acn_dmx_2_start_code, tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset += 1;
dmx_count -= 1;
}
buf_ptr = buffer;
switch (global_acn_dmx_display_line_format) {
case ACN_PREF_DMX_DISPLAY_16PL:
perline = 16;
halfline = 8;
break;
default:
perline = 20;
halfline = 10;
}
switch ((guint)global_acn_dmx_display_view) {
case ACN_PREF_DMX_DISPLAY_HEX:
min_char = 2;
base = 16;
break;
default:
min_char = 3;
base = 10;
}
if (global_acn_dmx_display_leading_zeros) {
leading_char = '0';
} else {
leading_char = ' ';
}
col_append_fstr(pinfo->cinfo,COL_INFO, ", Sc %02x, [%02x %02x %02x %02x %02x %02x...]",
dmx_start_code,
tvb_get_guint8(tvb, data_offset),
tvb_get_guint8(tvb, data_offset+1),
tvb_get_guint8(tvb, data_offset+2),
tvb_get_guint8(tvb, data_offset+3),
tvb_get_guint8(tvb, data_offset+4),
tvb_get_guint8(tvb, data_offset+5));
g_snprintf(buffer, BUFFER_SIZE, "%-10s: ", "Data...");
buf_ptr += 9;
for (x=0; x<perline; x++) {
buf_ptr = ltos((guint8)(x+1), buf_ptr, 10, ' ', min_char, FALSE);
if ((x+1)==halfline) {
*buf_ptr++ = '|';
*buf_ptr++ = ' ';
}
}
*buf_ptr = '\0';
proto_tree_add_text(pdu_tree, tvb, data_offset, dmx_count, "%s", buffer);
g_snprintf(buffer, BUFFER_SIZE, "001-%03d: ", perline);
buf_ptr = buffer + 9;
total_cnt = 0;
item_cnt = 0;
for (x=data_offset; x<end_offset; x++) {
level = tvb_get_guint8(tvb, x);
if (global_acn_dmx_display_view==ACN_PREF_DMX_DISPLAY_PER) {
if ((level > 0) && (level < 3)) {
level = 1;
} else {
level = level * 100 / 255;
}
}
buf_ptr = ltos(level, buf_ptr, base, leading_char, min_char, global_acn_dmx_display_zeros);
total_cnt++;
item_cnt++;
if (item_cnt == perline || x == (end_offset-1)) {
proto_tree_add_text(pdu_tree, tvb, data_offset, item_cnt, "%s", buffer);
data_offset += perline;
g_snprintf(buffer, BUFFER_SIZE, "%03d-%03d: ",total_cnt, total_cnt+perline);
buf_ptr = buffer + 9;
item_cnt = 0;
} else {
if (item_cnt == halfline) {
*buf_ptr++ = '|';
*buf_ptr++ = ' ';
*buf_ptr = '\0';
}
}
}
break;
}
return pdu_start + pdu_length;
}
static guint32
dissect_acn_dmx_pdu(guint32 protocol_id, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, acn_pdu_offsets *last_pdu_offsets)
{
guint8 pdu_flags;
guint32 pdu_start;
guint32 pdu_length;
guint32 pdu_flvh_length;
acn_pdu_offsets pdu_offsets = {0,0,0,0,0};
guint8 octet;
guint8 option_flags;
guint32 length1;
guint32 length2;
guint32 length3;
guint32 vector_offset;
guint32 data_offset;
guint32 data_length;
proto_item *ti, *pi;
proto_tree *pdu_tree = NULL;
proto_tree *flag_tree = NULL;
const char *name;
guint32 vector;
guint32 universe;
guint32 priority;
guint32 sequence;
pdu_start = offset;
pdu_offsets.start = pdu_start;
octet = tvb_get_guint8(tvb, offset++);
pdu_flags = octet & 0xf0;
length1 = octet & 0x0f;
length2 = tvb_get_guint8(tvb, offset++);
if (pdu_flags & ACN_PDU_FLAG_L) {
length3 = tvb_get_guint8(tvb, offset);
offset += 1;
pdu_length = length3 | (length2 << 8) | (length1 << 16);
pdu_flvh_length = 3;
} else {
pdu_length = length2 | (length1 << 8);
pdu_flvh_length = 2;
}
ti = proto_tree_add_item(tree, hf_acn_pdu, tvb, pdu_start, pdu_length, ENC_NA);
pdu_tree = proto_item_add_subtree(ti, ett_acn_dmx_pdu);
pi = proto_tree_add_uint(pdu_tree, hf_acn_pdu_flags, tvb, pdu_start, 1, pdu_flags);
flag_tree = proto_item_add_subtree(pi, ett_acn_pdu_flags);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_l, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_v, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_h, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_d, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(pdu_tree, hf_acn_pdu_length, tvb, pdu_start, pdu_flvh_length, pdu_length);
if (pdu_flags & ACN_PDU_FLAG_V) {
vector_offset = offset;
last_pdu_offsets->vector = offset;
offset += 4;
pdu_flvh_length += 4;
} else {
vector_offset = last_pdu_offsets->vector;
}
vector = tvb_get_ntohl(tvb, vector_offset);
proto_tree_add_item(pdu_tree, hf_acn_dmx_vector, tvb, vector_offset, 4, ENC_BIG_ENDIAN);
name = val_to_str(vector, acn_dmx_vector_vals, "not valid (%d)");
proto_item_append_text(ti, ": %s", name);
if (pdu_flags & ACN_PDU_FLAG_D) {
data_offset = offset;
data_length = pdu_length - pdu_flvh_length;
last_pdu_offsets->data = offset;
last_pdu_offsets->data_length = data_length;
} else {
data_offset = last_pdu_offsets->data;
}
switch (vector) {
case 0x02:
if (protocol_id==ACN_PROTOCOL_ID_DMX_2) {
proto_tree_add_item(pdu_tree, hf_acn_dmx_source_name, tvb, data_offset, 64, ENC_UTF_8|ENC_NA);
data_offset += 64;
} else{
proto_tree_add_item(pdu_tree, hf_acn_dmx_source_name, tvb, data_offset, 32, ENC_UTF_8|ENC_NA);
data_offset += 32;
}
priority = tvb_get_guint8(tvb, data_offset);
proto_tree_add_item(pdu_tree, hf_acn_dmx_priority, tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset += 1;
if (protocol_id==ACN_PROTOCOL_ID_DMX_2) {
proto_tree_add_item(pdu_tree, hf_acn_dmx_2_reserved, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
}
sequence = tvb_get_guint8(tvb, data_offset);
proto_tree_add_item(pdu_tree, hf_acn_dmx_sequence_number, tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset += 1;
if (protocol_id == ACN_PROTOCOL_ID_DMX_2) {
option_flags = tvb_get_guint8(tvb, data_offset);
pi = proto_tree_add_uint(pdu_tree, hf_acn_dmx_2_options, tvb, data_offset, 1, option_flags);
flag_tree = proto_item_add_subtree(pi, ett_acn_dmx_2_options);
proto_tree_add_item(flag_tree, hf_acn_dmx_2_option_p, tvb, data_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_dmx_2_option_s, tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset += 1;
}
universe = tvb_get_ntohs(tvb, data_offset);
proto_tree_add_item(pdu_tree, hf_acn_dmx_universe , tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
col_append_fstr(pinfo->cinfo,COL_INFO, ", Universe %d, Seq %3d", universe, sequence );
proto_item_append_text(ti, ", Universe: %d, Priority: %d", universe, priority);
dissect_acn_dmx_data_pdu(protocol_id, tvb, pinfo, pdu_tree, data_offset, &pdu_offsets);
break;
}
return pdu_start + pdu_length;
}
static guint32
dissect_acn_sdt_base_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, acn_pdu_offsets *last_pdu_offsets)
{
guint8 pdu_flags;
guint32 pdu_start;
guint32 pdu_length;
guint32 pdu_flvh_length;
acn_pdu_offsets pdu_offsets = {0,0,0,0,0};
guint8 octet;
guint32 length1;
guint32 length2;
guint32 length3;
guint32 vector_offset;
guint32 data_offset;
guint32 end_offset;
guint32 old_offset;
guint32 data_length;
proto_item *ti, *pi;
proto_tree *pdu_tree = NULL;
proto_tree *flag_tree = NULL;
const gchar *name;
guint32 vector;
guint32 member_id;
pdu_start = offset;
pdu_offsets.start = pdu_start;
octet = tvb_get_guint8(tvb, offset++);
pdu_flags = octet & 0xf0;
length1 = octet & 0x0f;
length2 = tvb_get_guint8(tvb, offset++);
if (pdu_flags & ACN_PDU_FLAG_L) {
length3 = tvb_get_guint8(tvb, offset);
offset += 1;
pdu_length = length3 | (length2 << 8) | (length1 << 16);
pdu_flvh_length = 3;
} else {
pdu_length = length2 | (length1 << 8);
pdu_flvh_length = 2;
}
ti = proto_tree_add_item(tree, hf_acn_pdu, tvb, pdu_start, pdu_length, ENC_NA);
pdu_tree = proto_item_add_subtree(ti, ett_acn_sdt_base_pdu);
pi = proto_tree_add_uint(pdu_tree, hf_acn_pdu_flags, tvb, pdu_start, 1, pdu_flags);
flag_tree = proto_item_add_subtree(pi, ett_acn_pdu_flags);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_l, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_v, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_h, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_d, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(pdu_tree, hf_acn_pdu_length, tvb, pdu_start, pdu_flvh_length, pdu_length);
if (pdu_flags & ACN_PDU_FLAG_V) {
vector_offset = offset;
last_pdu_offsets->vector = offset;
offset += 1;
pdu_flvh_length++;
} else {
vector_offset = last_pdu_offsets->vector;
}
vector = tvb_get_guint8(tvb, vector_offset);
proto_tree_add_uint(pdu_tree, hf_acn_sdt_vector, tvb, vector_offset, 1, vector);
name = val_to_str(vector, acn_sdt_vector_vals, "not valid (%d)");
proto_item_append_text(ti, ": ");
proto_item_append_text(ti, "%s", name);
if (pdu_flags & ACN_PDU_FLAG_D) {
data_offset = offset;
data_length = pdu_length - pdu_flvh_length;
last_pdu_offsets->data = offset;
last_pdu_offsets->data_length = data_length;
} else {
data_offset = last_pdu_offsets->data;
data_length = last_pdu_offsets->data_length;
}
end_offset = data_offset + data_length;
switch (vector) {
case ACN_SDT_VECTOR_UNKNOWN:
break;
case ACN_SDT_VECTOR_REL_WRAP:
case ACN_SDT_VECTOR_UNREL_WRAP:
proto_tree_add_item(pdu_tree, hf_acn_channel_number, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_total_sequence_number, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_reliable_sequence_number, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_oldest_available_wrapper, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_first_memeber_to_ack, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_last_memeber_to_ack, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_mak_threshold, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = dissect_acn_sdt_client_pdu(tvb, pinfo, pdu_tree, data_offset, &pdu_offsets);
if (data_offset == old_offset) break;
}
break;
case ACN_SDT_VECTOR_CHANNEL_PARAMS:
break;
case ACN_SDT_VECTOR_JOIN:
proto_tree_add_item(pdu_tree, hf_acn_cid, tvb, data_offset, 16, ENC_BIG_ENDIAN);
data_offset += 16;
proto_tree_add_item(pdu_tree, hf_acn_member_id, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_channel_number, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_reciprocal_channel, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_total_sequence_number, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_reliable_sequence_number, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
data_offset = acn_add_address(tvb, pinfo, pdu_tree, data_offset, "Destination Address:");
data_offset = acn_add_channel_parameter(tvb, pinfo, pdu_tree, data_offset);
acn_add_expiry(tvb, pinfo, pdu_tree, data_offset, "Ad-hoc Expiry:");
break;
case ACN_SDT_VECTOR_JOIN_REFUSE:
pi = proto_tree_add_item(pdu_tree, hf_acn_cid, tvb, data_offset, 16, ENC_BIG_ENDIAN);
data_offset += 16;
proto_item_append_text(pi, "(Leader)");
proto_tree_add_item(pdu_tree, hf_acn_channel_number, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_member_id, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_reliable_sequence_number, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_refuse_code, tvb, data_offset, 1, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_JOIN_ACCEPT:
pi = proto_tree_add_item(pdu_tree, hf_acn_cid, tvb, data_offset, 16, ENC_BIG_ENDIAN);
data_offset += 16;
proto_item_append_text(pi, "(Leader)");
proto_tree_add_item(pdu_tree, hf_acn_channel_number, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_member_id, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_reliable_sequence_number, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_reciprocal_channel, tvb, data_offset, 2, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_LEAVE:
break;
case ACN_SDT_VECTOR_LEAVING:
pi = proto_tree_add_item(pdu_tree, hf_acn_cid, tvb, data_offset, 16, ENC_BIG_ENDIAN);
data_offset += 16;
proto_item_append_text(pi, "(Leader)");
proto_tree_add_item(pdu_tree, hf_acn_channel_number, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_member_id, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_reliable_sequence_number, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_reason_code, tvb, data_offset, 1, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_CONNECT:
break;
case ACN_SDT_VECTOR_CONNECT_ACCEPT:
break;
case ACN_SDT_VECTOR_CONNECT_REFUSE:
break;
case ACN_SDT_VECTOR_DISCONNECT:
break;
case ACN_SDT_VECTOR_DISCONNECTING:
break;
case ACN_SDT_VECTOR_ACK:
break;
case ACN_SDT_VECTOR_NAK:
pi = proto_tree_add_item(pdu_tree, hf_acn_cid, tvb, data_offset, 16, ENC_BIG_ENDIAN);
data_offset += 16;
proto_item_append_text(pi, "(Leader)");
proto_tree_add_item(pdu_tree, hf_acn_channel_number, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_member_id, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(pdu_tree, hf_acn_reliable_sequence_number, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_first_missed_sequence, tvb, data_offset, 4, ENC_BIG_ENDIAN);
data_offset += 4;
proto_tree_add_item(pdu_tree, hf_acn_last_missed_sequence, tvb, data_offset, 4, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_GET_SESSION:
proto_tree_add_item(pdu_tree, hf_acn_cid, tvb, data_offset, 16, ENC_BIG_ENDIAN);
break;
case ACN_SDT_VECTOR_SESSIONS:
member_id = tvb_get_ntohs(tvb, data_offset);
switch (member_id) {
case 0:
acn_add_channel_owner_info_block(tvb, pinfo, pdu_tree, data_offset);
break;
case 1:
acn_add_channel_member_info_block(tvb, pinfo, pdu_tree, data_offset);
break;
}
break;
}
return pdu_start + pdu_length;
}
static guint32
dissect_acn_root_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, acn_pdu_offsets *last_pdu_offsets)
{
guint8 pdu_flags;
guint32 pdu_start;
guint32 pdu_length;
guint32 pdu_flvh_length;
acn_pdu_offsets pdu_offsets = {0,0,0,0,0};
guint8 octet;
guint32 length1;
guint32 length2;
guint32 length3;
guint32 vector_offset;
guint32 header_offset;
guint32 data_offset;
guint32 end_offset;
guint32 old_offset;
guint32 data_length;
proto_item *ti, *pi;
proto_tree *pdu_tree = NULL;
proto_tree *flag_tree = NULL;
guint32 protocol_id;
e_guid_t guid;
pdu_start = offset;
pdu_offsets.start = pdu_start;
octet = tvb_get_guint8(tvb, offset++);
pdu_flags = octet & 0xf0;
length1 = octet & 0x0f;
length2 = tvb_get_guint8(tvb, offset++);
if (pdu_flags & ACN_PDU_FLAG_L) {
length3 = tvb_get_guint8(tvb, offset);
offset += 1;
pdu_length = length3 | (length2 << 8) | (length1 << 16);
pdu_flvh_length = 3;
} else {
pdu_length = length2 | (length1 << 8);
pdu_flvh_length = 2;
}
ti = proto_tree_add_item(tree, hf_acn_pdu, tvb, pdu_start, pdu_length, ENC_NA);
pdu_tree = proto_item_add_subtree(ti, ett_acn_root_pdu);
pi = proto_tree_add_uint(pdu_tree, hf_acn_pdu_flags, tvb, pdu_start, 1, pdu_flags);
flag_tree = proto_item_add_subtree(pi, ett_acn_pdu_flags);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_l, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_v, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_h, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_acn_pdu_flag_d, tvb, pdu_start, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(pdu_tree, hf_acn_pdu_length, tvb, pdu_start, pdu_flvh_length, pdu_length);
if (pdu_flags & ACN_PDU_FLAG_V) {
vector_offset = offset;
last_pdu_offsets->vector = offset;
offset += 4;
pdu_flvh_length += 4;
} else {
vector_offset = last_pdu_offsets->vector;
}
protocol_id = tvb_get_ntohl(tvb, vector_offset);
proto_tree_add_uint(pdu_tree, hf_acn_protocol_id, tvb, vector_offset, 4, protocol_id);
switch (protocol_id) {
case ACN_PROTOCOL_ID_DMX:
case ACN_PROTOCOL_ID_DMX_2:
if (global_acn_dmx_enable) {
proto_item_append_text(ti,": Root DMX");
if (pdu_flags & ACN_PDU_FLAG_H) {
header_offset = offset;
last_pdu_offsets->header = offset;
offset += 16;
pdu_flvh_length += 16;
} else {
header_offset = last_pdu_offsets->header;
}
tvb_get_guid(tvb, header_offset, &guid, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Src: %s", guid_to_ep_str(&guid));
col_add_fstr(pinfo->cinfo,COL_INFO, "CID %s", guid_to_ep_str(&guid));
proto_tree_add_item(pdu_tree, hf_acn_cid, tvb, header_offset, 16, ENC_BIG_ENDIAN);
if (pdu_flags & ACN_PDU_FLAG_D) {
data_offset = offset;
data_length = pdu_length - pdu_flvh_length;
last_pdu_offsets->data = offset;
last_pdu_offsets->data_length = data_length;
} else {
data_offset = last_pdu_offsets->data;
data_length = last_pdu_offsets->data_length;
}
end_offset = data_offset + data_length;
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = dissect_acn_dmx_pdu(protocol_id, tvb, pinfo, pdu_tree, data_offset, &pdu_offsets);
if (data_offset == old_offset) break;
}
}
break;
case ACN_PROTOCOL_ID_SDT:
proto_item_append_text(ti,": Root SDT");
if (pdu_flags & ACN_PDU_FLAG_H) {
header_offset = offset;
last_pdu_offsets->header = offset;
offset += 16;
pdu_flvh_length += 16;
} else {
header_offset = last_pdu_offsets->header;
}
tvb_get_guid(tvb, header_offset, &guid, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Src: %s", guid_to_ep_str(&guid));
proto_tree_add_item(pdu_tree, hf_acn_cid, tvb, header_offset, 16, ENC_BIG_ENDIAN);
if (pdu_flags & ACN_PDU_FLAG_D) {
data_offset = offset;
data_length = pdu_length - pdu_flvh_length;
last_pdu_offsets->data = offset;
last_pdu_offsets->data_length = data_length;
} else {
data_offset = last_pdu_offsets->data;
data_length = last_pdu_offsets->data_length;
}
end_offset = data_offset + data_length;
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = dissect_acn_sdt_base_pdu(tvb, pinfo, pdu_tree, data_offset, &pdu_offsets);
if (data_offset == old_offset) break;
}
break;
}
return pdu_start + pdu_length;
}
static int
dissect_acn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *acn_tree = NULL;
guint32 data_offset = 0;
guint32 old_offset;
guint32 end_offset;
acn_pdu_offsets pdu_offsets = {0,0,0,0,0};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ACN");
col_add_fstr(pinfo->cinfo,COL_INFO, "ACN [Src Port: %d, Dst Port: %d]", pinfo->srcport, pinfo->destport );
if (tree) {
ti = proto_tree_add_item(tree, proto_acn, tvb, 0, -1, ENC_NA);
acn_tree = proto_item_add_subtree(ti, ett_acn);
proto_tree_add_item(acn_tree, hf_acn_preamble_size, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(acn_tree, hf_acn_postamble_size, tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
proto_tree_add_item(acn_tree, hf_acn_packet_identifier, tvb, data_offset, 12, ENC_UTF_8|ENC_NA);
data_offset += 12;
end_offset = data_offset + tvb_reported_length_remaining(tvb, data_offset);
while (data_offset < end_offset) {
old_offset = data_offset;
data_offset = dissect_acn_root_pdu(tvb, pinfo, acn_tree, data_offset, &pdu_offsets);
if (data_offset == old_offset) break;
}
}
return tvb_length(tvb);
}
void
proto_register_acn(void)
{
static hf_register_info hf[] = {
{ &hf_acn_ip_address_type,
{ "Addr Type", "acn.ip_address_type",
FT_UINT8, BASE_DEC, VALS(acn_ip_address_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_acn_association,
{ "Association", "acn.association",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_channel_number,
{ "Channel Number", "acn.channel_number",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_cid,
{ "CID", "acn.cid",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_acn_client_protocol_id,
{ "Client Protocol ID", "acn.client_protocol_id",
FT_UINT32, BASE_DEC, VALS(acn_protocol_id_vals), 0x0,
NULL, HFILL }
},
#endif
{ &hf_acn_data,
{ "Data", "acn.dmp_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_data8,
{ "Addr", "acn.dmp_data8",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
"Data8", HFILL }
},
{ &hf_acn_data16,
{ "Addr", "acn.dmp_data16",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
"Data16", HFILL }
},
{ &hf_acn_data24,
{ "Addr", "acn.dmp_data24",
FT_UINT24, BASE_DEC_HEX, NULL, 0x0,
"Data24", HFILL }
},
{ &hf_acn_data32,
{ "Addr", "acn.dmp_data32",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
"Data32", HFILL }
},
#if 0
{ &hf_acn_dmp_adt,
{ "Address and Data Type", "acn.dmp_adt",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_acn_dmp_adt_a,
{ "Size", "acn.dmp_adt_a",
FT_UINT8, BASE_DEC, VALS(acn_dmp_adt_a_vals), 0x03,
NULL, HFILL }
},
{ &hf_acn_dmp_adt_d,
{ "Data Type", "acn.dmp_adt_d",
FT_UINT8, BASE_DEC, VALS(acn_dmp_adt_d_vals), 0x30,
NULL, HFILL }
},
{ &hf_acn_dmp_adt_r,
{ "Relative", "acn.dmp_adt_r",
FT_UINT8, BASE_DEC, VALS(acn_dmp_adt_r_vals), 0x40,
NULL, HFILL }
},
{ &hf_acn_dmp_adt_v,
{ "Virtual", "acn.dmp_adt_v",
FT_UINT8, BASE_DEC, VALS(acn_dmp_adt_v_vals), 0x80,
NULL, HFILL }
},
{ &hf_acn_dmp_adt_x,
{ "Reserved", "acn.dmp_adt_x",
FT_UINT8, BASE_DEC, NULL, 0x0c,
NULL, HFILL }
},
{ &hf_acn_dmp_reason_code,
{ "Reason Code", "acn.dmp_reason_code",
FT_UINT8, BASE_DEC, VALS(acn_dmp_reason_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_acn_dmp_vector,
{ "DMP Vector", "acn.dmp_vector",
FT_UINT8, BASE_DEC, VALS(acn_dmp_vector_vals), 0x0,
NULL, HFILL }
},
{ &hf_acn_expiry,
{ "Expiry", "acn.expiry",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_first_memeber_to_ack,
{ "First Member to ACK", "acn.first_member_to_ack",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_first_missed_sequence,
{ "First Missed Sequence", "acn.first_missed_sequence",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_ipv4,
{ "IPV4", "acn.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_ipv6,
{ "IPV6", "acn.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_last_memeber_to_ack,
{ "Last Member to ACK", "acn.last_member_to_ack",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_last_missed_sequence,
{ "Last Missed Sequence", "acn.last_missed_sequence",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_mak_threshold,
{ "MAK Threshold", "acn.mak_threshold",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_member_id,
{ "Member ID", "acn.member_id",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_nak_holdoff,
{ "NAK holdoff (ms)", "acn.nak_holdoff",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_nak_max_wait,
{ "NAK Max Wait (ms)", "acn.nak_max_wait",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_nak_modulus,
{ "NAK Modulus", "acn.nak_modulus",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_nak_outbound_flag,
{ "NAK Outbound Flag", "acn.nak_outbound_flag",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_acn_oldest_available_wrapper,
{ "Oldest Available Wrapper", "acn.oldest_available_wrapper",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_preamble_size,
{ "Size of preamble", "acn.preamble_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Preamble size in bytes", HFILL }
},
{ &hf_acn_packet_identifier,
{ "Packet Identifier", "acn.packet_identifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_pdu,
{ "PDU", "acn.pdu",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_pdu_flags,
{ "Flags", "acn.pdu.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"PDU Flags", HFILL }
},
{ &hf_acn_pdu_flag_d,
{ "Data", "acn.pdu.flag_d",
FT_BOOLEAN, 8, NULL, ACN_PDU_FLAG_D,
"Data flag", HFILL }
},
{ &hf_acn_pdu_flag_h,
{ "Header", "acn.pdu.flag_h",
FT_BOOLEAN, 8, NULL, ACN_PDU_FLAG_H,
"Header flag", HFILL }
},
{ &hf_acn_pdu_flag_l,
{ "Length", "acn.pdu.flag_l",
FT_BOOLEAN, 8, NULL, ACN_PDU_FLAG_L,
"Length flag", HFILL }
},
{ &hf_acn_pdu_flag_v,
{ "Vector", "acn.pdu.flag_v",
FT_BOOLEAN, 8, NULL, ACN_PDU_FLAG_V,
"Vector flag", HFILL }
},
{ &hf_acn_pdu_length,
{ "Length", "acn.pdu.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PDU Length", HFILL }
},
{ &hf_acn_port,
{ "Port", "acn.port",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_postamble_size,
{ "Size of postamble", "acn.postamble_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Postamble size in bytes", HFILL }
},
{ &hf_acn_protocol_id,
{ "Protocol ID", "acn.protocol_id",
FT_UINT32, BASE_DEC, VALS(acn_protocol_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_acn_reason_code,
{ "Reason Code", "acn.reason_code",
FT_UINT8, BASE_DEC, VALS(acn_reason_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_acn_reciprocal_channel,
{ "Reciprocal Channel Number", "acn.reciprocal_channel",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
"Reciprocal Channel", HFILL }
},
{ &hf_acn_refuse_code,
{ "Refuse Code", "acn.refuse_code",
FT_UINT8, BASE_DEC, VALS(acn_refuse_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_acn_reliable_sequence_number,
{ "Reliable Sequence Number", "acn.reliable_sequence_number",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_acn_sdt_vector,
{ "STD Vector", "acn.sdt_vector",
FT_UINT8, BASE_DEC, VALS(acn_sdt_vector_vals), 0x0,
NULL, HFILL }
},
{ &hf_acn_dmx_vector,
{ "Vector", "acn.dmx_vector",
FT_UINT32, BASE_DEC, VALS(acn_dmx_vector_vals), 0x0,
"DMX Vector", HFILL }
},
{ &hf_acn_dmx_source_name,
{ "Source", "acn.dmx.source_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"DMX Source Name", HFILL }
},
{ &hf_acn_dmx_priority,
{ "Priority", "acn.dmx.priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
"DMX Priority", HFILL }
},
{ &hf_acn_dmx_2_reserved,
{ "Reserved", "acn.dmx.reserved",
FT_UINT16, BASE_DEC, NULL, 0x0,
"DMX Reserved", HFILL }
},
{ &hf_acn_dmx_sequence_number,
{ "Seq No", "acn.dmx.seq_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
"DMX Sequence Number", HFILL }
},
{ &hf_acn_dmx_2_options,
{ "Options", "acn.dmx.options",
FT_UINT8, BASE_DEC, NULL, 0x0,
"DMX Options", HFILL }
},
{ &hf_acn_dmx_2_option_p,
{ "Preview Data", "acn.dmx.option_p",
FT_BOOLEAN, 8, NULL, ACN_DMX_OPTION_P,
"Preview Data flag", HFILL }
},
{ &hf_acn_dmx_2_option_s,
{ "Stream Terminated", "acn.dmx.option_s",
FT_BOOLEAN, 8, NULL, ACN_DMX_OPTION_S,
"Stream Terminated flag", HFILL }
},
{ &hf_acn_dmx_universe,
{ "Universe", "acn.dmx.universe",
FT_UINT16, BASE_DEC, NULL, 0x0,
"DMX Universe", HFILL }
},
{ &hf_acn_dmx_start_code,
{ "Start Code", "acn.dmx.start_code",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
"DMX Start Code", HFILL }
},
{ &hf_acn_dmx_2_first_property_address,
{ "First Property Address", "acn.dmx.start_code",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
"DMX First Property Address", HFILL }
},
{ &hf_acn_dmx_increment,
{ "Increment", "acn.dmx.increment",
FT_UINT16, BASE_DEC, NULL, 0x0,
"DMX Increment", HFILL }
},
{ &hf_acn_dmx_count,
{ "Count", "acn.dmx.count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"DMX Count", HFILL }
},
{ &hf_acn_dmx_2_start_code,
{ "Start Code", "acn.dmx.start_code2",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
"DMX Start Code", HFILL }
},
#if 0
{ &hf_acn_session_count,
{ "Session Count", "acn.session_count",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_acn_total_sequence_number,
{ "Total Sequence Number", "acn.total_sequence_number",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_acn,
&ett_acn_channel_owner_info_block,
&ett_acn_channel_member_info_block,
&ett_acn_channel_parameter,
&ett_acn_address,
&ett_acn_address_type,
&ett_acn_pdu_flags,
&ett_acn_dmp_pdu,
&ett_acn_sdt_pdu,
&ett_acn_sdt_client_pdu,
&ett_acn_sdt_base_pdu,
&ett_acn_root_pdu,
&ett_acn_dmx_address,
&ett_acn_dmx_2_options,
&ett_acn_dmx_data_pdu,
&ett_acn_dmx_pdu
};
module_t *acn_module;
proto_acn = proto_register_protocol (
"Architecture for Control Networks",
"ACN",
"acn"
);
proto_register_field_array(proto_acn, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
acn_module = prefs_register_protocol(proto_acn, NULL);
prefs_register_bool_preference(acn_module, "heuristic_acn",
"Decode ACN",
"Enable Architecture for Control Networks dissector (ANSI BSR E1.17)",
&global_acn_heur);
prefs_register_bool_preference(acn_module, "dmx_enable",
"Streaming DMX",
"Enable Streaming DMX extension dissector (ANSI BSR E1.31)",
&global_acn_dmx_enable);
prefs_register_enum_preference(acn_module, "dmx_display_view",
"DMX, display format",
"Display format",
&global_acn_dmx_display_view,
dmx_display_view,
TRUE);
prefs_register_bool_preference(acn_module, "dmx_display_zeros",
"DMX, display zeros",
"Display zeros instead of dots",
&global_acn_dmx_display_zeros);
prefs_register_bool_preference(acn_module, "dmx_display_leading_zeros",
"DMX, display leading zeros",
"Display leading zeros on levels",
&global_acn_dmx_display_leading_zeros);
prefs_register_enum_preference(acn_module, "dmx_display_line_format",
"DMX, display line format",
"Display line format",
&global_acn_dmx_display_line_format,
dmx_display_line_format,
TRUE);
}
void
proto_reg_handoff_acn(void)
{
heur_dissector_add("udp", dissect_acn_heur, proto_acn);
}
