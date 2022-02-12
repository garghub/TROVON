s32 fm10k_tlv_msg_init(u32 *msg, u16 msg_id)
{
if (!msg)
return FM10K_ERR_PARAM;
*msg = (FM10K_TLV_FLAGS_MSG << FM10K_TLV_FLAGS_SHIFT) | msg_id;
return 0;
}
static s32 fm10k_tlv_attr_put_null_string(u32 *msg, u16 attr_id,
const unsigned char *string)
{
u32 attr_data = 0, len = 0;
u32 *attr;
if (!string || !msg)
return FM10K_ERR_PARAM;
attr = &msg[FM10K_TLV_DWORD_LEN(*msg)];
do {
if (len && !(len % 4)) {
attr[len / 4] = attr_data;
attr_data = 0;
}
attr_data |= (u32)(*string) << (8 * (len % 4));
len++;
} while (*(string++));
attr[(len + 3) / 4] = attr_data;
len <<= FM10K_TLV_LEN_SHIFT;
attr[0] = len | attr_id;
len += FM10K_TLV_HDR_LEN << FM10K_TLV_LEN_SHIFT;
*msg += FM10K_TLV_LEN_ALIGN(len);
return 0;
}
static s32 fm10k_tlv_attr_get_null_string(u32 *attr, unsigned char *string)
{
u32 len;
if (!string || !attr)
return FM10K_ERR_PARAM;
len = *attr >> FM10K_TLV_LEN_SHIFT;
attr++;
while (len--)
string[len] = (u8)(attr[len / 4] >> (8 * (len % 4)));
return 0;
}
s32 fm10k_tlv_attr_put_mac_vlan(u32 *msg, u16 attr_id,
const u8 *mac_addr, u16 vlan)
{
u32 len = ETH_ALEN << FM10K_TLV_LEN_SHIFT;
u32 *attr;
if (!msg || !mac_addr)
return FM10K_ERR_PARAM;
attr = &msg[FM10K_TLV_DWORD_LEN(*msg)];
attr[0] = len | attr_id;
attr[1] = le32_to_cpu(*(const __le32 *)&mac_addr[0]);
attr[2] = le16_to_cpu(*(const __le16 *)&mac_addr[4]);
attr[2] |= (u32)vlan << 16;
len += FM10K_TLV_HDR_LEN << FM10K_TLV_LEN_SHIFT;
*msg += FM10K_TLV_LEN_ALIGN(len);
return 0;
}
s32 fm10k_tlv_attr_get_mac_vlan(u32 *attr, u8 *mac_addr, u16 *vlan)
{
if (!mac_addr || !attr)
return FM10K_ERR_PARAM;
*(__le32 *)&mac_addr[0] = cpu_to_le32(attr[1]);
*(__le16 *)&mac_addr[4] = cpu_to_le16((u16)(attr[2]));
*vlan = (u16)(attr[2] >> 16);
return 0;
}
s32 fm10k_tlv_attr_put_bool(u32 *msg, u16 attr_id)
{
if (!msg)
return FM10K_ERR_PARAM;
msg[FM10K_TLV_DWORD_LEN(*msg)] = attr_id;
*msg += FM10K_TLV_HDR_LEN << FM10K_TLV_LEN_SHIFT;
return 0;
}
s32 fm10k_tlv_attr_put_value(u32 *msg, u16 attr_id, s64 value, u32 len)
{
u32 *attr;
if (!msg || !len || len > 8 || (len & (len - 1)))
return FM10K_ERR_PARAM;
attr = &msg[FM10K_TLV_DWORD_LEN(*msg)];
if (len < 4) {
attr[1] = (u32)value & ((0x1ul << (8 * len)) - 1);
} else {
attr[1] = (u32)value;
if (len > 4)
attr[2] = (u32)(value >> 32);
}
len <<= FM10K_TLV_LEN_SHIFT;
attr[0] = len | attr_id;
len += FM10K_TLV_HDR_LEN << FM10K_TLV_LEN_SHIFT;
*msg += FM10K_TLV_LEN_ALIGN(len);
return 0;
}
s32 fm10k_tlv_attr_get_value(u32 *attr, void *value, u32 len)
{
if (!attr || !value)
return FM10K_ERR_PARAM;
if ((*attr >> FM10K_TLV_LEN_SHIFT) != len)
return FM10K_ERR_PARAM;
if (len == 8)
*(u64 *)value = ((u64)attr[2] << 32) | attr[1];
else if (len == 4)
*(u32 *)value = attr[1];
else if (len == 2)
*(u16 *)value = (u16)attr[1];
else
*(u8 *)value = (u8)attr[1];
return 0;
}
s32 fm10k_tlv_attr_put_le_struct(u32 *msg, u16 attr_id,
const void *le_struct, u32 len)
{
const __le32 *le32_ptr = (const __le32 *)le_struct;
u32 *attr;
u32 i;
if (!msg || !len || (len % 4))
return FM10K_ERR_PARAM;
attr = &msg[FM10K_TLV_DWORD_LEN(*msg)];
for (i = 0; i < (len / 4); i++)
attr[i + 1] = le32_to_cpu(le32_ptr[i]);
len <<= FM10K_TLV_LEN_SHIFT;
attr[0] = len | attr_id;
len += FM10K_TLV_HDR_LEN << FM10K_TLV_LEN_SHIFT;
*msg += FM10K_TLV_LEN_ALIGN(len);
return 0;
}
s32 fm10k_tlv_attr_get_le_struct(u32 *attr, void *le_struct, u32 len)
{
__le32 *le32_ptr = (__le32 *)le_struct;
u32 i;
if (!le_struct || !attr)
return FM10K_ERR_PARAM;
if ((*attr >> FM10K_TLV_LEN_SHIFT) != len)
return FM10K_ERR_PARAM;
attr++;
for (i = 0; len; i++, len -= 4)
le32_ptr[i] = cpu_to_le32(attr[i]);
return 0;
}
static u32 *fm10k_tlv_attr_nest_start(u32 *msg, u16 attr_id)
{
u32 *attr;
if (!msg)
return NULL;
attr = &msg[FM10K_TLV_DWORD_LEN(*msg)];
attr[0] = attr_id;
return attr;
}
static s32 fm10k_tlv_attr_nest_stop(u32 *msg)
{
u32 *attr;
u32 len;
if (!msg)
return FM10K_ERR_PARAM;
attr = &msg[FM10K_TLV_DWORD_LEN(*msg)];
len = (attr[0] >> FM10K_TLV_LEN_SHIFT) << FM10K_TLV_LEN_SHIFT;
if (len) {
len += FM10K_TLV_HDR_LEN << FM10K_TLV_LEN_SHIFT;
*msg += len;
}
return 0;
}
static s32 fm10k_tlv_attr_validate(u32 *attr,
const struct fm10k_tlv_attr *tlv_attr)
{
u32 attr_id = *attr & FM10K_TLV_ID_MASK;
u16 len = *attr >> FM10K_TLV_LEN_SHIFT;
if (*attr & (FM10K_TLV_FLAGS_MSG << FM10K_TLV_FLAGS_SHIFT))
return FM10K_ERR_PARAM;
while (tlv_attr->id < attr_id)
tlv_attr++;
if (tlv_attr->id != attr_id)
return FM10K_NOT_IMPLEMENTED;
attr++;
switch (tlv_attr->type) {
case FM10K_TLV_NULL_STRING:
if (!len ||
(attr[(len - 1) / 4] & (0xFF << (8 * ((len - 1) % 4)))))
return FM10K_ERR_PARAM;
if (len > tlv_attr->len)
return FM10K_ERR_PARAM;
break;
case FM10K_TLV_MAC_ADDR:
if (len != ETH_ALEN)
return FM10K_ERR_PARAM;
break;
case FM10K_TLV_BOOL:
if (len)
return FM10K_ERR_PARAM;
break;
case FM10K_TLV_UNSIGNED:
case FM10K_TLV_SIGNED:
if (len != tlv_attr->len)
return FM10K_ERR_PARAM;
break;
case FM10K_TLV_LE_STRUCT:
if ((len % 4) || len != tlv_attr->len)
return FM10K_ERR_PARAM;
break;
case FM10K_TLV_NESTED:
if (len % 4)
return FM10K_ERR_PARAM;
break;
default:
return FM10K_ERR_PARAM;
}
return 0;
}
static s32 fm10k_tlv_attr_parse(u32 *attr, u32 **results,
const struct fm10k_tlv_attr *tlv_attr)
{
u32 i, attr_id, offset = 0;
s32 err = 0;
u16 len;
if (!attr || !results)
return FM10K_ERR_PARAM;
for (i = 0; i < FM10K_TLV_RESULTS_MAX; i++)
results[i] = NULL;
len = *attr >> FM10K_TLV_LEN_SHIFT;
if (!len)
return 0;
if (!tlv_attr) {
results[0] = attr;
return 0;
}
attr++;
while (offset < len) {
attr_id = *attr & FM10K_TLV_ID_MASK;
if (attr_id < FM10K_TLV_RESULTS_MAX)
err = fm10k_tlv_attr_validate(attr, tlv_attr);
else
err = FM10K_NOT_IMPLEMENTED;
if (err < 0)
return err;
if (!err)
results[attr_id] = attr;
offset += FM10K_TLV_DWORD_LEN(*attr) * 4;
attr = &attr[FM10K_TLV_DWORD_LEN(*attr)];
}
if (offset != len)
return FM10K_ERR_PARAM;
return 0;
}
s32 fm10k_tlv_msg_parse(struct fm10k_hw *hw, u32 *msg,
struct fm10k_mbx_info *mbx,
const struct fm10k_msg_data *data)
{
u32 *results[FM10K_TLV_RESULTS_MAX];
u32 msg_id;
s32 err;
if (!msg || !data)
return FM10K_ERR_PARAM;
if (!(*msg & (FM10K_TLV_FLAGS_MSG << FM10K_TLV_FLAGS_SHIFT)))
return FM10K_ERR_PARAM;
msg_id = *msg & FM10K_TLV_ID_MASK;
while (data->id < msg_id)
data++;
if (data->id != msg_id) {
while (data->id != FM10K_TLV_ERROR)
data++;
}
err = fm10k_tlv_attr_parse(msg, results, data->attr);
if (err < 0)
return err;
return data->func(hw, results, mbx);
}
s32 fm10k_tlv_msg_error(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
return FM10K_NOT_IMPLEMENTED;
}
static void fm10k_tlv_msg_test_generate_data(u32 *msg, u32 attr_flags)
{
if (attr_flags & (1 << FM10K_TEST_MSG_STRING))
fm10k_tlv_attr_put_null_string(msg, FM10K_TEST_MSG_STRING,
test_str);
if (attr_flags & (1 << FM10K_TEST_MSG_MAC_ADDR))
fm10k_tlv_attr_put_mac_vlan(msg, FM10K_TEST_MSG_MAC_ADDR,
test_mac, test_vlan);
if (attr_flags & (1 << FM10K_TEST_MSG_U8))
fm10k_tlv_attr_put_u8(msg, FM10K_TEST_MSG_U8, test_u8);
if (attr_flags & (1 << FM10K_TEST_MSG_U16))
fm10k_tlv_attr_put_u16(msg, FM10K_TEST_MSG_U16, test_u16);
if (attr_flags & (1 << FM10K_TEST_MSG_U32))
fm10k_tlv_attr_put_u32(msg, FM10K_TEST_MSG_U32, test_u32);
if (attr_flags & (1 << FM10K_TEST_MSG_U64))
fm10k_tlv_attr_put_u64(msg, FM10K_TEST_MSG_U64, test_u64);
if (attr_flags & (1 << FM10K_TEST_MSG_S8))
fm10k_tlv_attr_put_s8(msg, FM10K_TEST_MSG_S8, test_s8);
if (attr_flags & (1 << FM10K_TEST_MSG_S16))
fm10k_tlv_attr_put_s16(msg, FM10K_TEST_MSG_S16, test_s16);
if (attr_flags & (1 << FM10K_TEST_MSG_S32))
fm10k_tlv_attr_put_s32(msg, FM10K_TEST_MSG_S32, test_s32);
if (attr_flags & (1 << FM10K_TEST_MSG_S64))
fm10k_tlv_attr_put_s64(msg, FM10K_TEST_MSG_S64, test_s64);
if (attr_flags & (1 << FM10K_TEST_MSG_LE_STRUCT))
fm10k_tlv_attr_put_le_struct(msg, FM10K_TEST_MSG_LE_STRUCT,
test_le, 8);
}
void fm10k_tlv_msg_test_create(u32 *msg, u32 attr_flags)
{
u32 *nest = NULL;
fm10k_tlv_msg_init(msg, FM10K_TLV_MSG_ID_TEST);
fm10k_tlv_msg_test_generate_data(msg, attr_flags);
attr_flags >>= FM10K_TEST_MSG_NESTED;
if (attr_flags) {
nest = fm10k_tlv_attr_nest_start(msg, FM10K_TEST_MSG_NESTED);
fm10k_tlv_msg_test_generate_data(nest, attr_flags);
fm10k_tlv_attr_nest_stop(msg);
}
}
s32 fm10k_tlv_msg_test(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
u32 *nest_results[FM10K_TLV_RESULTS_MAX];
unsigned char result_str[80];
unsigned char result_mac[ETH_ALEN];
s32 err = 0;
__le32 result_le[2];
u16 result_vlan;
u64 result_u64;
u32 result_u32;
u16 result_u16;
u8 result_u8;
s64 result_s64;
s32 result_s32;
s16 result_s16;
s8 result_s8;
u32 reply[3];
if (!!results[FM10K_TEST_MSG_RESULT])
return fm10k_tlv_attr_get_s32(results[FM10K_TEST_MSG_RESULT],
&mbx->test_result);
parse_nested:
if (!!results[FM10K_TEST_MSG_STRING]) {
err = fm10k_tlv_attr_get_null_string(
results[FM10K_TEST_MSG_STRING],
result_str);
if (!err && memcmp(test_str, result_str, sizeof(test_str)))
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_MAC_ADDR]) {
err = fm10k_tlv_attr_get_mac_vlan(
results[FM10K_TEST_MSG_MAC_ADDR],
result_mac, &result_vlan);
if (!err && !ether_addr_equal(test_mac, result_mac))
err = FM10K_ERR_INVALID_VALUE;
if (!err && test_vlan != result_vlan)
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_U8]) {
err = fm10k_tlv_attr_get_u8(results[FM10K_TEST_MSG_U8],
&result_u8);
if (!err && test_u8 != result_u8)
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_U16]) {
err = fm10k_tlv_attr_get_u16(results[FM10K_TEST_MSG_U16],
&result_u16);
if (!err && test_u16 != result_u16)
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_U32]) {
err = fm10k_tlv_attr_get_u32(results[FM10K_TEST_MSG_U32],
&result_u32);
if (!err && test_u32 != result_u32)
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_U64]) {
err = fm10k_tlv_attr_get_u64(results[FM10K_TEST_MSG_U64],
&result_u64);
if (!err && test_u64 != result_u64)
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_S8]) {
err = fm10k_tlv_attr_get_s8(results[FM10K_TEST_MSG_S8],
&result_s8);
if (!err && test_s8 != result_s8)
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_S16]) {
err = fm10k_tlv_attr_get_s16(results[FM10K_TEST_MSG_S16],
&result_s16);
if (!err && test_s16 != result_s16)
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_S32]) {
err = fm10k_tlv_attr_get_s32(results[FM10K_TEST_MSG_S32],
&result_s32);
if (!err && test_s32 != result_s32)
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_S64]) {
err = fm10k_tlv_attr_get_s64(results[FM10K_TEST_MSG_S64],
&result_s64);
if (!err && test_s64 != result_s64)
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_LE_STRUCT]) {
err = fm10k_tlv_attr_get_le_struct(
results[FM10K_TEST_MSG_LE_STRUCT],
result_le,
sizeof(result_le));
if (!err && memcmp(test_le, result_le, sizeof(test_le)))
err = FM10K_ERR_INVALID_VALUE;
if (err)
goto report_result;
}
if (!!results[FM10K_TEST_MSG_NESTED]) {
memset(nest_results, 0, sizeof(nest_results));
err = fm10k_tlv_attr_parse(results[FM10K_TEST_MSG_NESTED],
nest_results,
fm10k_tlv_msg_test_attr);
if (err)
goto report_result;
results = nest_results;
goto parse_nested;
}
report_result:
fm10k_tlv_msg_init(reply, FM10K_TLV_MSG_ID_TEST);
fm10k_tlv_attr_put_s32(reply, FM10K_TEST_MSG_RESULT, err);
return mbx->ops.enqueue_tx(hw, mbx, reply);
}
