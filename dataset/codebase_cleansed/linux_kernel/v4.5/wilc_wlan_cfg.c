static int wilc_wlan_cfg_set_byte(u8 *frame, u32 offset, u16 id, u8 val8)
{
u8 *buf;
if ((offset + 4) >= MAX_CFG_FRAME_SIZE)
return 0;
buf = &frame[offset];
buf[0] = (u8)id;
buf[1] = (u8)(id >> 8);
buf[2] = 1;
buf[3] = val8;
return 4;
}
static int wilc_wlan_cfg_set_hword(u8 *frame, u32 offset, u16 id, u16 val16)
{
u8 *buf;
if ((offset + 5) >= MAX_CFG_FRAME_SIZE)
return 0;
buf = &frame[offset];
buf[0] = (u8)id;
buf[1] = (u8)(id >> 8);
buf[2] = 2;
buf[3] = (u8)val16;
buf[4] = (u8)(val16 >> 8);
return 5;
}
static int wilc_wlan_cfg_set_word(u8 *frame, u32 offset, u16 id, u32 val32)
{
u8 *buf;
if ((offset + 7) >= MAX_CFG_FRAME_SIZE)
return 0;
buf = &frame[offset];
buf[0] = (u8)id;
buf[1] = (u8)(id >> 8);
buf[2] = 4;
buf[3] = (u8)val32;
buf[4] = (u8)(val32 >> 8);
buf[5] = (u8)(val32 >> 16);
buf[6] = (u8)(val32 >> 24);
return 7;
}
static int wilc_wlan_cfg_set_str(u8 *frame, u32 offset, u16 id, u8 *str, u32 size)
{
u8 *buf;
if ((offset + size + 3) >= MAX_CFG_FRAME_SIZE)
return 0;
buf = &frame[offset];
buf[0] = (u8)id;
buf[1] = (u8)(id >> 8);
buf[2] = (u8)size;
if ((str != NULL) && (size != 0))
memcpy(&buf[3], str, size);
return (size + 3);
}
static int wilc_wlan_cfg_set_bin(u8 *frame, u32 offset, u16 id, u8 *b, u32 size)
{
u8 *buf;
u32 i;
u8 checksum = 0;
if ((offset + size + 5) >= MAX_CFG_FRAME_SIZE)
return 0;
buf = &frame[offset];
buf[0] = (u8)id;
buf[1] = (u8)(id >> 8);
buf[2] = (u8)size;
buf[3] = (u8)(size >> 8);
if ((b != NULL) && (size != 0)) {
memcpy(&buf[4], b, size);
for (i = 0; i < size; i++) {
checksum += buf[i + 4];
}
}
buf[size + 4] = checksum;
return (size + 5);
}
static void wilc_wlan_parse_response_frame(u8 *info, int size)
{
u32 wid, len = 0, i = 0;
static int seq;
while (size > 0) {
i = 0;
wid = info[0] | (info[1] << 8);
wid = cpu_to_le32(wid);
PRINT_INFO(GENERIC_DBG, "Processing response for %d seq %d\n", wid, seq++);
switch ((wid >> 12) & 0x7) {
case WID_CHAR:
do {
if (g_cfg_byte[i].id == WID_NIL)
break;
if (g_cfg_byte[i].id == wid) {
g_cfg_byte[i].val = info[3];
break;
}
i++;
} while (1);
len = 2;
break;
case WID_SHORT:
do {
if (g_cfg_hword[i].id == WID_NIL)
break;
if (g_cfg_hword[i].id == wid) {
g_cfg_hword[i].val = cpu_to_le16(info[3] | (info[4] << 8));
break;
}
i++;
} while (1);
len = 3;
break;
case WID_INT:
do {
if (g_cfg_word[i].id == WID_NIL)
break;
if (g_cfg_word[i].id == wid) {
g_cfg_word[i].val = cpu_to_le32(info[3] | (info[4] << 8) | (info[5] << 16) | (info[6] << 24));
break;
}
i++;
} while (1);
len = 5;
break;
case WID_STR:
do {
if (g_cfg_str[i].id == WID_NIL)
break;
if (g_cfg_str[i].id == wid) {
if (wid == WID_SITE_SURVEY_RESULTS) {
static int toggle;
PRINT_INFO(GENERIC_DBG, "Site survey results received[%d]\n",
size);
PRINT_INFO(GENERIC_DBG, "Site survey results value[%d]toggle[%d]\n", size, toggle);
i += toggle;
toggle ^= 1;
}
memcpy(g_cfg_str[i].str, &info[2], (info[2] + 1));
break;
}
i++;
} while (1);
len = 1 + info[2];
break;
default:
break;
}
size -= (2 + len);
info += (2 + len);
}
}
static int wilc_wlan_parse_info_frame(u8 *info, int size)
{
wilc_mac_cfg_t *pd = &g_mac;
u32 wid, len;
int type = WILC_CFG_RSP_STATUS;
wid = info[0] | (info[1] << 8);
len = info[2];
PRINT_INFO(GENERIC_DBG, "Status Len = %d Id= %d\n", len, wid);
if ((len == 1) && (wid == WID_STATUS)) {
pd->mac_status = info[3];
type = WILC_CFG_RSP_STATUS;
}
return type;
}
int wilc_wlan_cfg_set_wid(u8 *frame, u32 offset, u16 id, u8 *buf, int size)
{
u8 type = (id >> 12) & 0xf;
int ret = 0;
if (type == 0) {
if (size >= 1)
ret = wilc_wlan_cfg_set_byte(frame, offset, id, *buf);
} else if (type == 1) {
if (size >= 2)
ret = wilc_wlan_cfg_set_hword(frame, offset, id, *((u16 *)buf));
} else if (type == 2) {
if (size >= 4)
ret = wilc_wlan_cfg_set_word(frame, offset, id, *((u32 *)buf));
} else if (type == 3) {
ret = wilc_wlan_cfg_set_str(frame, offset, id, buf, size);
} else if (type == 4) {
ret = wilc_wlan_cfg_set_bin(frame, offset, id, buf, size);
} else {
g_mac.dPrint(N_ERR, "illegal id\n");
}
return ret;
}
int wilc_wlan_cfg_get_wid(u8 *frame, u32 offset, u16 id)
{
u8 *buf;
if ((offset + 2) >= MAX_CFG_FRAME_SIZE)
return 0;
buf = &frame[offset];
buf[0] = (u8)id;
buf[1] = (u8)(id >> 8);
return 2;
}
int wilc_wlan_cfg_get_wid_value(u16 wid, u8 *buffer, u32 buffer_size)
{
u32 type = (wid >> 12) & 0xf;
int i, ret = 0;
if (wid == WID_STATUS) {
*((u32 *)buffer) = g_mac.mac_status;
return 4;
}
i = 0;
if (type == 0) {
do {
if (g_cfg_byte[i].id == WID_NIL)
break;
if (g_cfg_byte[i].id == wid) {
memcpy(buffer, &g_cfg_byte[i].val, 1);
ret = 1;
break;
}
i++;
} while (1);
} else if (type == 1) {
do {
if (g_cfg_hword[i].id == WID_NIL)
break;
if (g_cfg_hword[i].id == wid) {
memcpy(buffer, &g_cfg_hword[i].val, 2);
ret = 2;
break;
}
i++;
} while (1);
} else if (type == 2) {
do {
if (g_cfg_word[i].id == WID_NIL)
break;
if (g_cfg_word[i].id == wid) {
memcpy(buffer, &g_cfg_word[i].val, 4);
ret = 4;
break;
}
i++;
} while (1);
} else if (type == 3) {
do {
if (g_cfg_str[i].id == WID_NIL)
break;
if (g_cfg_str[i].id == wid) {
u32 size = g_cfg_str[i].str[0];
if (buffer_size >= size) {
if (g_cfg_str[i].id == WID_SITE_SURVEY_RESULTS) {
static int toggle;
PRINT_INFO(GENERIC_DBG, "Site survey results value[%d]\n",
size);
i += toggle;
toggle ^= 1;
}
memcpy(buffer, &g_cfg_str[i].str[1], size);
ret = size;
}
break;
}
i++;
} while (1);
} else {
g_mac.dPrint(N_ERR, "[CFG]: illegal type (%08x)\n", wid);
}
return ret;
}
int wilc_wlan_cfg_indicate_rx(struct wilc *wilc, u8 *frame, int size,
struct wilc_cfg_rsp *rsp)
{
int ret = 1;
u8 msg_type;
u8 msg_id;
msg_type = frame[0];
msg_id = frame[1];
frame += 4;
size -= 4;
switch (msg_type) {
case 'R':
wilc_wlan_parse_response_frame(frame, size);
rsp->type = WILC_CFG_RSP;
rsp->seq_no = msg_id;
break;
case 'I':
rsp->type = wilc_wlan_parse_info_frame(frame, size);
rsp->seq_no = msg_id;
PRINT_INFO(RX_DBG, "Info message received\n");
wilc_gnrl_async_info_received(wilc, frame - 4, size + 4);
break;
case 'N':
wilc_network_info_received(wilc, frame - 4, size + 4);
rsp->type = 0;
break;
case 'S':
PRINT_INFO(RX_DBG, "Scan Notification Received\n");
wilc_scan_complete_received(wilc, frame - 4, size + 4);
break;
default:
PRINT_INFO(RX_DBG, "Receive unknown message type[%d-%d-%d-%d-%d-%d-%d-%d]\n",
frame[0], frame[1], frame[2], frame[3], frame[4],
frame[5], frame[6], frame[7]);
rsp->type = 0;
rsp->seq_no = msg_id;
ret = 0;
break;
}
return ret;
}
int wilc_wlan_cfg_init(wilc_debug_func func)
{
memset((void *)&g_mac, 0, sizeof(wilc_mac_cfg_t));
g_mac.dPrint = func;
return 1;
}
