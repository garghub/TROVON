static u8 e1000_calculate_checksum(u8 *buffer, u32 length)
{
u32 i;
u8 sum = 0;
if (!buffer)
return 0;
for (i = 0; i < length; i++)
sum += buffer[i];
return (u8)(0 - sum);
}
static s32 e1000_mng_enable_host_if(struct e1000_hw *hw)
{
u32 hicr;
u8 i;
if (!hw->mac.arc_subsystem_valid) {
e_dbg("ARC subsystem not valid.\n");
return -E1000_ERR_HOST_INTERFACE_COMMAND;
}
hicr = er32(HICR);
if (!(hicr & E1000_HICR_EN)) {
e_dbg("E1000_HOST_EN bit disabled.\n");
return -E1000_ERR_HOST_INTERFACE_COMMAND;
}
for (i = 0; i < E1000_MNG_DHCP_COMMAND_TIMEOUT; i++) {
hicr = er32(HICR);
if (!(hicr & E1000_HICR_C))
break;
mdelay(1);
}
if (i == E1000_MNG_DHCP_COMMAND_TIMEOUT) {
e_dbg("Previous command timeout failed.\n");
return -E1000_ERR_HOST_INTERFACE_COMMAND;
}
return 0;
}
bool e1000e_check_mng_mode_generic(struct e1000_hw *hw)
{
u32 fwsm = er32(FWSM);
return (fwsm & E1000_FWSM_MODE_MASK) ==
(E1000_MNG_IAMT_MODE << E1000_FWSM_MODE_SHIFT);
}
bool e1000e_enable_tx_pkt_filtering(struct e1000_hw *hw)
{
struct e1000_host_mng_dhcp_cookie *hdr = &hw->mng_cookie;
u32 *buffer = (u32 *)&hw->mng_cookie;
u32 offset;
s32 ret_val, hdr_csum, csum;
u8 i, len;
hw->mac.tx_pkt_filtering = true;
if (!hw->mac.ops.check_mng_mode(hw)) {
hw->mac.tx_pkt_filtering = false;
return hw->mac.tx_pkt_filtering;
}
ret_val = e1000_mng_enable_host_if(hw);
if (ret_val) {
hw->mac.tx_pkt_filtering = false;
return hw->mac.tx_pkt_filtering;
}
len = E1000_MNG_DHCP_COOKIE_LENGTH >> 2;
offset = E1000_MNG_DHCP_COOKIE_OFFSET >> 2;
for (i = 0; i < len; i++)
*(buffer + i) = E1000_READ_REG_ARRAY(hw, E1000_HOST_IF,
offset + i);
hdr_csum = hdr->checksum;
hdr->checksum = 0;
csum = e1000_calculate_checksum((u8 *)hdr,
E1000_MNG_DHCP_COOKIE_LENGTH);
if ((hdr_csum != csum) || (hdr->signature != E1000_IAMT_SIGNATURE)) {
hw->mac.tx_pkt_filtering = true;
return hw->mac.tx_pkt_filtering;
}
if (!(hdr->status & E1000_MNG_DHCP_COOKIE_STATUS_PARSING))
hw->mac.tx_pkt_filtering = false;
return hw->mac.tx_pkt_filtering;
}
static s32 e1000_mng_write_cmd_header(struct e1000_hw *hw,
struct e1000_host_mng_command_header *hdr)
{
u16 i, length = sizeof(struct e1000_host_mng_command_header);
hdr->checksum = e1000_calculate_checksum((u8 *)hdr, length);
length >>= 2;
for (i = 0; i < length; i++) {
E1000_WRITE_REG_ARRAY(hw, E1000_HOST_IF, i, *((u32 *)hdr + i));
e1e_flush();
}
return 0;
}
static s32 e1000_mng_host_if_write(struct e1000_hw *hw, u8 *buffer,
u16 length, u16 offset, u8 *sum)
{
u8 *tmp;
u8 *bufptr = buffer;
u32 data = 0;
u16 remaining, i, j, prev_bytes;
if (length == 0 || offset + length > E1000_HI_MAX_MNG_DATA_LENGTH)
return -E1000_ERR_PARAM;
tmp = (u8 *)&data;
prev_bytes = offset & 0x3;
offset >>= 2;
if (prev_bytes) {
data = E1000_READ_REG_ARRAY(hw, E1000_HOST_IF, offset);
for (j = prev_bytes; j < sizeof(u32); j++) {
*(tmp + j) = *bufptr++;
*sum += *(tmp + j);
}
E1000_WRITE_REG_ARRAY(hw, E1000_HOST_IF, offset, data);
length -= j - prev_bytes;
offset++;
}
remaining = length & 0x3;
length -= remaining;
length >>= 2;
for (i = 0; i < length; i++) {
for (j = 0; j < sizeof(u32); j++) {
*(tmp + j) = *bufptr++;
*sum += *(tmp + j);
}
E1000_WRITE_REG_ARRAY(hw, E1000_HOST_IF, offset + i, data);
}
if (remaining) {
for (j = 0; j < sizeof(u32); j++) {
if (j < remaining)
*(tmp + j) = *bufptr++;
else
*(tmp + j) = 0;
*sum += *(tmp + j);
}
E1000_WRITE_REG_ARRAY(hw, E1000_HOST_IF, offset + i, data);
}
return 0;
}
s32 e1000e_mng_write_dhcp_info(struct e1000_hw *hw, u8 *buffer, u16 length)
{
struct e1000_host_mng_command_header hdr;
s32 ret_val;
u32 hicr;
hdr.command_id = E1000_MNG_DHCP_TX_PAYLOAD_CMD;
hdr.command_length = length;
hdr.reserved1 = 0;
hdr.reserved2 = 0;
hdr.checksum = 0;
ret_val = e1000_mng_enable_host_if(hw);
if (ret_val)
return ret_val;
ret_val = e1000_mng_host_if_write(hw, buffer, length,
sizeof(hdr), &(hdr.checksum));
if (ret_val)
return ret_val;
ret_val = e1000_mng_write_cmd_header(hw, &hdr);
if (ret_val)
return ret_val;
hicr = er32(HICR);
ew32(HICR, hicr | E1000_HICR_C);
return 0;
}
bool e1000e_enable_mng_pass_thru(struct e1000_hw *hw)
{
u32 manc;
u32 fwsm, factps;
manc = er32(MANC);
if (!(manc & E1000_MANC_RCV_TCO_EN))
return false;
if (hw->mac.has_fwsm) {
fwsm = er32(FWSM);
factps = er32(FACTPS);
if (!(factps & E1000_FACTPS_MNGCG) &&
((fwsm & E1000_FWSM_MODE_MASK) ==
(e1000_mng_mode_pt << E1000_FWSM_MODE_SHIFT)))
return true;
} else if ((hw->mac.type == e1000_82574) ||
(hw->mac.type == e1000_82583)) {
u16 data;
s32 ret_val;
factps = er32(FACTPS);
ret_val = e1000_read_nvm(hw, NVM_INIT_CONTROL2_REG, 1, &data);
if (ret_val)
return false;
if (!(factps & E1000_FACTPS_MNGCG) &&
((data & E1000_NVM_INIT_CTRL2_MNGM) ==
(e1000_mng_mode_pt << 13)))
return true;
} else if ((manc & E1000_MANC_SMBUS_EN) &&
!(manc & E1000_MANC_ASF_EN)) {
return true;
}
return false;
}
