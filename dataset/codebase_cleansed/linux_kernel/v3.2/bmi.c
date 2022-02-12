static int ath6kl_get_bmi_cmd_credits(struct ath6kl *ar)
{
u32 addr;
unsigned long timeout;
int ret;
ar->bmi.cmd_credits = 0;
addr = COUNT_DEC_ADDRESS + (HTC_MAILBOX_NUM_MAX + ENDPOINT1) * 4;
timeout = jiffies + msecs_to_jiffies(BMI_COMMUNICATION_TIMEOUT);
while (time_before(jiffies, timeout) && !ar->bmi.cmd_credits) {
ret = hif_read_write_sync(ar, addr,
(u8 *)&ar->bmi.cmd_credits, 4,
HIF_RD_SYNC_BYTE_INC);
if (ret) {
ath6kl_err("Unable to decrement the command credit count register: %d\n",
ret);
return ret;
}
ar->bmi.cmd_credits &= 0xFF;
}
if (!ar->bmi.cmd_credits) {
ath6kl_err("bmi communication timeout\n");
return -ETIMEDOUT;
}
return 0;
}
static int ath6kl_bmi_get_rx_lkahd(struct ath6kl *ar)
{
unsigned long timeout;
u32 rx_word = 0;
int ret = 0;
timeout = jiffies + msecs_to_jiffies(BMI_COMMUNICATION_TIMEOUT);
while (time_before(jiffies, timeout) && !rx_word) {
ret = hif_read_write_sync(ar, RX_LOOKAHEAD_VALID_ADDRESS,
(u8 *)&rx_word, sizeof(rx_word),
HIF_RD_SYNC_BYTE_INC);
if (ret) {
ath6kl_err("unable to read RX_LOOKAHEAD_VALID\n");
return ret;
}
rx_word &= (1 << ENDPOINT1);
}
if (!rx_word) {
ath6kl_err("bmi_recv_buf FIFO empty\n");
return -EINVAL;
}
return ret;
}
static int ath6kl_bmi_send_buf(struct ath6kl *ar, u8 *buf, u32 len)
{
int ret;
u32 addr;
ret = ath6kl_get_bmi_cmd_credits(ar);
if (ret)
return ret;
addr = ar->mbox_info.htc_addr;
ret = hif_read_write_sync(ar, addr, buf, len,
HIF_WR_SYNC_BYTE_INC);
if (ret)
ath6kl_err("unable to send the bmi data to the device\n");
return ret;
}
static int ath6kl_bmi_recv_buf(struct ath6kl *ar, u8 *buf, u32 len)
{
int ret;
u32 addr;
if (len >= 4) {
ret = ath6kl_bmi_get_rx_lkahd(ar);
if (ret)
return ret;
}
addr = ar->mbox_info.htc_addr;
ret = hif_read_write_sync(ar, addr, buf, len,
HIF_RD_SYNC_BYTE_INC);
if (ret) {
ath6kl_err("Unable to read the bmi data from the device: %d\n",
ret);
return ret;
}
return 0;
}
int ath6kl_bmi_done(struct ath6kl *ar)
{
int ret;
u32 cid = BMI_DONE;
if (ar->bmi.done_sent) {
ath6kl_dbg(ATH6KL_DBG_BMI, "bmi done skipped\n");
return 0;
}
ar->bmi.done_sent = true;
ret = ath6kl_bmi_send_buf(ar, (u8 *)&cid, sizeof(cid));
if (ret) {
ath6kl_err("Unable to send bmi done: %d\n", ret);
return ret;
}
ath6kl_bmi_cleanup(ar);
return 0;
}
int ath6kl_bmi_get_target_info(struct ath6kl *ar,
struct ath6kl_bmi_target_info *targ_info)
{
int ret;
u32 cid = BMI_GET_TARGET_INFO;
if (ar->bmi.done_sent) {
ath6kl_err("bmi done sent already, cmd %d disallowed\n", cid);
return -EACCES;
}
ret = ath6kl_bmi_send_buf(ar, (u8 *)&cid, sizeof(cid));
if (ret) {
ath6kl_err("Unable to send get target info: %d\n", ret);
return ret;
}
ret = ath6kl_bmi_recv_buf(ar, (u8 *)&targ_info->version,
sizeof(targ_info->version));
if (ret) {
ath6kl_err("Unable to recv target info: %d\n", ret);
return ret;
}
if (le32_to_cpu(targ_info->version) == TARGET_VERSION_SENTINAL) {
ret = ath6kl_bmi_recv_buf(ar,
(u8 *)&targ_info->byte_count,
sizeof(targ_info->byte_count));
if (ret) {
ath6kl_err("unable to read target info byte count: %d\n",
ret);
return ret;
}
if (le32_to_cpu(targ_info->byte_count) != sizeof(*targ_info)) {
WARN_ON(1);
return -EINVAL;
}
ret = ath6kl_bmi_recv_buf(ar,
((u8 *)targ_info) +
sizeof(targ_info->byte_count),
sizeof(*targ_info) -
sizeof(targ_info->byte_count));
if (ret) {
ath6kl_err("Unable to read target info (%d bytes): %d\n",
targ_info->byte_count, ret);
return ret;
}
}
ath6kl_dbg(ATH6KL_DBG_BMI, "target info (ver: 0x%x type: 0x%x)\n",
targ_info->version, targ_info->type);
return 0;
}
int ath6kl_bmi_read(struct ath6kl *ar, u32 addr, u8 *buf, u32 len)
{
u32 cid = BMI_READ_MEMORY;
int ret;
u32 offset;
u32 len_remain, rx_len;
u16 size;
if (ar->bmi.done_sent) {
ath6kl_err("bmi done sent already, cmd %d disallowed\n", cid);
return -EACCES;
}
size = BMI_DATASZ_MAX + sizeof(cid) + sizeof(addr) + sizeof(len);
if (size > MAX_BMI_CMDBUF_SZ) {
WARN_ON(1);
return -EINVAL;
}
memset(ar->bmi.cmd_buf, 0, size);
ath6kl_dbg(ATH6KL_DBG_BMI,
"bmi read memory: device: addr: 0x%x, len: %d\n",
addr, len);
len_remain = len;
while (len_remain) {
rx_len = (len_remain < BMI_DATASZ_MAX) ?
len_remain : BMI_DATASZ_MAX;
offset = 0;
memcpy(&(ar->bmi.cmd_buf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(ar->bmi.cmd_buf[offset]), &addr, sizeof(addr));
offset += sizeof(addr);
memcpy(&(ar->bmi.cmd_buf[offset]), &rx_len, sizeof(rx_len));
offset += sizeof(len);
ret = ath6kl_bmi_send_buf(ar, ar->bmi.cmd_buf, offset);
if (ret) {
ath6kl_err("Unable to write to the device: %d\n",
ret);
return ret;
}
ret = ath6kl_bmi_recv_buf(ar, ar->bmi.cmd_buf, rx_len);
if (ret) {
ath6kl_err("Unable to read from the device: %d\n",
ret);
return ret;
}
memcpy(&buf[len - len_remain], ar->bmi.cmd_buf, rx_len);
len_remain -= rx_len; addr += rx_len;
}
return 0;
}
int ath6kl_bmi_write(struct ath6kl *ar, u32 addr, u8 *buf, u32 len)
{
u32 cid = BMI_WRITE_MEMORY;
int ret;
u32 offset;
u32 len_remain, tx_len;
const u32 header = sizeof(cid) + sizeof(addr) + sizeof(len);
u8 aligned_buf[BMI_DATASZ_MAX];
u8 *src;
if (ar->bmi.done_sent) {
ath6kl_err("bmi done sent already, cmd %d disallowed\n", cid);
return -EACCES;
}
if ((BMI_DATASZ_MAX + header) > MAX_BMI_CMDBUF_SZ) {
WARN_ON(1);
return -EINVAL;
}
memset(ar->bmi.cmd_buf, 0, BMI_DATASZ_MAX + header);
ath6kl_dbg(ATH6KL_DBG_BMI,
"bmi write memory: addr: 0x%x, len: %d\n", addr, len);
len_remain = len;
while (len_remain) {
src = &buf[len - len_remain];
if (len_remain < (BMI_DATASZ_MAX - header)) {
if (len_remain & 3) {
len_remain = len_remain +
(4 - (len_remain & 3));
memcpy(aligned_buf, src, len_remain);
src = aligned_buf;
}
tx_len = len_remain;
} else {
tx_len = (BMI_DATASZ_MAX - header);
}
offset = 0;
memcpy(&(ar->bmi.cmd_buf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(ar->bmi.cmd_buf[offset]), &addr, sizeof(addr));
offset += sizeof(addr);
memcpy(&(ar->bmi.cmd_buf[offset]), &tx_len, sizeof(tx_len));
offset += sizeof(tx_len);
memcpy(&(ar->bmi.cmd_buf[offset]), src, tx_len);
offset += tx_len;
ret = ath6kl_bmi_send_buf(ar, ar->bmi.cmd_buf, offset);
if (ret) {
ath6kl_err("Unable to write to the device: %d\n",
ret);
return ret;
}
len_remain -= tx_len; addr += tx_len;
}
return 0;
}
int ath6kl_bmi_execute(struct ath6kl *ar, u32 addr, u32 *param)
{
u32 cid = BMI_EXECUTE;
int ret;
u32 offset;
u16 size;
if (ar->bmi.done_sent) {
ath6kl_err("bmi done sent already, cmd %d disallowed\n", cid);
return -EACCES;
}
size = sizeof(cid) + sizeof(addr) + sizeof(param);
if (size > MAX_BMI_CMDBUF_SZ) {
WARN_ON(1);
return -EINVAL;
}
memset(ar->bmi.cmd_buf, 0, size);
ath6kl_dbg(ATH6KL_DBG_BMI, "bmi execute: addr: 0x%x, param: %d)\n",
addr, *param);
offset = 0;
memcpy(&(ar->bmi.cmd_buf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(ar->bmi.cmd_buf[offset]), &addr, sizeof(addr));
offset += sizeof(addr);
memcpy(&(ar->bmi.cmd_buf[offset]), param, sizeof(*param));
offset += sizeof(*param);
ret = ath6kl_bmi_send_buf(ar, ar->bmi.cmd_buf, offset);
if (ret) {
ath6kl_err("Unable to write to the device: %d\n", ret);
return ret;
}
ret = ath6kl_bmi_recv_buf(ar, ar->bmi.cmd_buf, sizeof(*param));
if (ret) {
ath6kl_err("Unable to read from the device: %d\n", ret);
return ret;
}
memcpy(param, ar->bmi.cmd_buf, sizeof(*param));
return 0;
}
int ath6kl_bmi_set_app_start(struct ath6kl *ar, u32 addr)
{
u32 cid = BMI_SET_APP_START;
int ret;
u32 offset;
u16 size;
if (ar->bmi.done_sent) {
ath6kl_err("bmi done sent already, cmd %d disallowed\n", cid);
return -EACCES;
}
size = sizeof(cid) + sizeof(addr);
if (size > MAX_BMI_CMDBUF_SZ) {
WARN_ON(1);
return -EINVAL;
}
memset(ar->bmi.cmd_buf, 0, size);
ath6kl_dbg(ATH6KL_DBG_BMI, "bmi set app start: addr: 0x%x\n", addr);
offset = 0;
memcpy(&(ar->bmi.cmd_buf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(ar->bmi.cmd_buf[offset]), &addr, sizeof(addr));
offset += sizeof(addr);
ret = ath6kl_bmi_send_buf(ar, ar->bmi.cmd_buf, offset);
if (ret) {
ath6kl_err("Unable to write to the device: %d\n", ret);
return ret;
}
return 0;
}
int ath6kl_bmi_reg_read(struct ath6kl *ar, u32 addr, u32 *param)
{
u32 cid = BMI_READ_SOC_REGISTER;
int ret;
u32 offset;
u16 size;
if (ar->bmi.done_sent) {
ath6kl_err("bmi done sent already, cmd %d disallowed\n", cid);
return -EACCES;
}
size = sizeof(cid) + sizeof(addr);
if (size > MAX_BMI_CMDBUF_SZ) {
WARN_ON(1);
return -EINVAL;
}
memset(ar->bmi.cmd_buf, 0, size);
ath6kl_dbg(ATH6KL_DBG_BMI, "bmi read SOC reg: addr: 0x%x\n", addr);
offset = 0;
memcpy(&(ar->bmi.cmd_buf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(ar->bmi.cmd_buf[offset]), &addr, sizeof(addr));
offset += sizeof(addr);
ret = ath6kl_bmi_send_buf(ar, ar->bmi.cmd_buf, offset);
if (ret) {
ath6kl_err("Unable to write to the device: %d\n", ret);
return ret;
}
ret = ath6kl_bmi_recv_buf(ar, ar->bmi.cmd_buf, sizeof(*param));
if (ret) {
ath6kl_err("Unable to read from the device: %d\n", ret);
return ret;
}
memcpy(param, ar->bmi.cmd_buf, sizeof(*param));
return 0;
}
int ath6kl_bmi_reg_write(struct ath6kl *ar, u32 addr, u32 param)
{
u32 cid = BMI_WRITE_SOC_REGISTER;
int ret;
u32 offset;
u16 size;
if (ar->bmi.done_sent) {
ath6kl_err("bmi done sent already, cmd %d disallowed\n", cid);
return -EACCES;
}
size = sizeof(cid) + sizeof(addr) + sizeof(param);
if (size > MAX_BMI_CMDBUF_SZ) {
WARN_ON(1);
return -EINVAL;
}
memset(ar->bmi.cmd_buf, 0, size);
ath6kl_dbg(ATH6KL_DBG_BMI,
"bmi write SOC reg: addr: 0x%x, param: %d\n",
addr, param);
offset = 0;
memcpy(&(ar->bmi.cmd_buf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(ar->bmi.cmd_buf[offset]), &addr, sizeof(addr));
offset += sizeof(addr);
memcpy(&(ar->bmi.cmd_buf[offset]), &param, sizeof(param));
offset += sizeof(param);
ret = ath6kl_bmi_send_buf(ar, ar->bmi.cmd_buf, offset);
if (ret) {
ath6kl_err("Unable to write to the device: %d\n", ret);
return ret;
}
return 0;
}
int ath6kl_bmi_lz_data(struct ath6kl *ar, u8 *buf, u32 len)
{
u32 cid = BMI_LZ_DATA;
int ret;
u32 offset;
u32 len_remain, tx_len;
const u32 header = sizeof(cid) + sizeof(len);
u16 size;
if (ar->bmi.done_sent) {
ath6kl_err("bmi done sent already, cmd %d disallowed\n", cid);
return -EACCES;
}
size = BMI_DATASZ_MAX + header;
if (size > MAX_BMI_CMDBUF_SZ) {
WARN_ON(1);
return -EINVAL;
}
memset(ar->bmi.cmd_buf, 0, size);
ath6kl_dbg(ATH6KL_DBG_BMI, "bmi send LZ data: len: %d)\n",
len);
len_remain = len;
while (len_remain) {
tx_len = (len_remain < (BMI_DATASZ_MAX - header)) ?
len_remain : (BMI_DATASZ_MAX - header);
offset = 0;
memcpy(&(ar->bmi.cmd_buf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(ar->bmi.cmd_buf[offset]), &tx_len, sizeof(tx_len));
offset += sizeof(tx_len);
memcpy(&(ar->bmi.cmd_buf[offset]), &buf[len - len_remain],
tx_len);
offset += tx_len;
ret = ath6kl_bmi_send_buf(ar, ar->bmi.cmd_buf, offset);
if (ret) {
ath6kl_err("Unable to write to the device: %d\n",
ret);
return ret;
}
len_remain -= tx_len;
}
return 0;
}
int ath6kl_bmi_lz_stream_start(struct ath6kl *ar, u32 addr)
{
u32 cid = BMI_LZ_STREAM_START;
int ret;
u32 offset;
u16 size;
if (ar->bmi.done_sent) {
ath6kl_err("bmi done sent already, cmd %d disallowed\n", cid);
return -EACCES;
}
size = sizeof(cid) + sizeof(addr);
if (size > MAX_BMI_CMDBUF_SZ) {
WARN_ON(1);
return -EINVAL;
}
memset(ar->bmi.cmd_buf, 0, size);
ath6kl_dbg(ATH6KL_DBG_BMI,
"bmi LZ stream start: addr: 0x%x)\n",
addr);
offset = 0;
memcpy(&(ar->bmi.cmd_buf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(ar->bmi.cmd_buf[offset]), &addr, sizeof(addr));
offset += sizeof(addr);
ret = ath6kl_bmi_send_buf(ar, ar->bmi.cmd_buf, offset);
if (ret) {
ath6kl_err("Unable to start LZ stream to the device: %d\n",
ret);
return ret;
}
return 0;
}
int ath6kl_bmi_fast_download(struct ath6kl *ar, u32 addr, u8 *buf, u32 len)
{
int ret;
u32 last_word = 0;
u32 last_word_offset = len & ~0x3;
u32 unaligned_bytes = len & 0x3;
ret = ath6kl_bmi_lz_stream_start(ar, addr);
if (ret)
return ret;
if (unaligned_bytes) {
memcpy(&last_word, &buf[last_word_offset], unaligned_bytes);
}
ret = ath6kl_bmi_lz_data(ar, buf, last_word_offset);
if (ret)
return ret;
if (unaligned_bytes)
ret = ath6kl_bmi_lz_data(ar, (u8 *)&last_word, 4);
if (!ret) {
ret = ath6kl_bmi_lz_stream_start(ar, 0x00);
}
return ret;
}
int ath6kl_bmi_init(struct ath6kl *ar)
{
ar->bmi.cmd_buf = kzalloc(MAX_BMI_CMDBUF_SZ, GFP_ATOMIC);
if (!ar->bmi.cmd_buf)
return -ENOMEM;
return 0;
}
void ath6kl_bmi_cleanup(struct ath6kl *ar)
{
kfree(ar->bmi.cmd_buf);
ar->bmi.cmd_buf = NULL;
}
