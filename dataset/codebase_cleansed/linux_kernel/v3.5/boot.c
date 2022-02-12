static void wl1271_boot_set_ecpu_ctrl(struct wl1271 *wl, u32 flag)
{
u32 cpu_ctrl;
cpu_ctrl = wlcore_read_reg(wl, REG_ECPU_CONTROL);
cpu_ctrl |= flag;
wlcore_write_reg(wl, REG_ECPU_CONTROL, cpu_ctrl);
}
static int wlcore_parse_fw_ver(struct wl1271 *wl)
{
int ret;
ret = sscanf(wl->chip.fw_ver_str + 4, "%u.%u.%u.%u.%u",
&wl->chip.fw_ver[0], &wl->chip.fw_ver[1],
&wl->chip.fw_ver[2], &wl->chip.fw_ver[3],
&wl->chip.fw_ver[4]);
if (ret != 5) {
wl1271_warning("fw version incorrect value");
memset(wl->chip.fw_ver, 0, sizeof(wl->chip.fw_ver));
return -EINVAL;
}
ret = wlcore_identify_fw(wl);
if (ret < 0)
return ret;
return 0;
}
static int wlcore_boot_fw_version(struct wl1271 *wl)
{
struct wl1271_static_data *static_data;
int ret;
static_data = kmalloc(sizeof(*static_data), GFP_KERNEL | GFP_DMA);
if (!static_data) {
wl1271_error("Couldn't allocate memory for static data!");
return -ENOMEM;
}
wl1271_read(wl, wl->cmd_box_addr, static_data, sizeof(*static_data),
false);
strncpy(wl->chip.fw_ver_str, static_data->fw_version,
sizeof(wl->chip.fw_ver_str));
kfree(static_data);
wl->chip.fw_ver_str[sizeof(wl->chip.fw_ver_str) - 1] = '\0';
ret = wlcore_parse_fw_ver(wl);
if (ret < 0)
return ret;
return 0;
}
static int wl1271_boot_upload_firmware_chunk(struct wl1271 *wl, void *buf,
size_t fw_data_len, u32 dest)
{
struct wlcore_partition_set partition;
int addr, chunk_num, partition_limit;
u8 *p, *chunk;
wl1271_debug(DEBUG_BOOT, "starting firmware upload");
wl1271_debug(DEBUG_BOOT, "fw_data_len %zd chunk_size %d",
fw_data_len, CHUNK_SIZE);
if ((fw_data_len % 4) != 0) {
wl1271_error("firmware length not multiple of four");
return -EIO;
}
chunk = kmalloc(CHUNK_SIZE, GFP_KERNEL);
if (!chunk) {
wl1271_error("allocation for firmware upload chunk failed");
return -ENOMEM;
}
memcpy(&partition, &wl->ptable[PART_DOWN], sizeof(partition));
partition.mem.start = dest;
wlcore_set_partition(wl, &partition);
chunk_num = 0;
partition_limit = wl->ptable[PART_DOWN].mem.size;
while (chunk_num < fw_data_len / CHUNK_SIZE) {
addr = dest + (chunk_num + 2) * CHUNK_SIZE;
if (addr > partition_limit) {
addr = dest + chunk_num * CHUNK_SIZE;
partition_limit = chunk_num * CHUNK_SIZE +
wl->ptable[PART_DOWN].mem.size;
partition.mem.start = addr;
wlcore_set_partition(wl, &partition);
}
addr = dest + chunk_num * CHUNK_SIZE;
p = buf + chunk_num * CHUNK_SIZE;
memcpy(chunk, p, CHUNK_SIZE);
wl1271_debug(DEBUG_BOOT, "uploading fw chunk 0x%p to 0x%x",
p, addr);
wl1271_write(wl, addr, chunk, CHUNK_SIZE, false);
chunk_num++;
}
addr = dest + chunk_num * CHUNK_SIZE;
p = buf + chunk_num * CHUNK_SIZE;
memcpy(chunk, p, fw_data_len % CHUNK_SIZE);
wl1271_debug(DEBUG_BOOT, "uploading fw last chunk (%zd B) 0x%p to 0x%x",
fw_data_len % CHUNK_SIZE, p, addr);
wl1271_write(wl, addr, chunk, fw_data_len % CHUNK_SIZE, false);
kfree(chunk);
return 0;
}
int wlcore_boot_upload_firmware(struct wl1271 *wl)
{
u32 chunks, addr, len;
int ret = 0;
u8 *fw;
fw = wl->fw;
chunks = be32_to_cpup((__be32 *) fw);
fw += sizeof(u32);
wl1271_debug(DEBUG_BOOT, "firmware chunks to be uploaded: %u", chunks);
while (chunks--) {
addr = be32_to_cpup((__be32 *) fw);
fw += sizeof(u32);
len = be32_to_cpup((__be32 *) fw);
fw += sizeof(u32);
if (len > 300000) {
wl1271_info("firmware chunk too long: %u", len);
return -EINVAL;
}
wl1271_debug(DEBUG_BOOT, "chunk %d addr 0x%x len %u",
chunks, addr, len);
ret = wl1271_boot_upload_firmware_chunk(wl, fw, len, addr);
if (ret != 0)
break;
fw += len;
}
return ret;
}
int wlcore_boot_upload_nvs(struct wl1271 *wl)
{
size_t nvs_len, burst_len;
int i;
u32 dest_addr, val;
u8 *nvs_ptr, *nvs_aligned;
if (wl->nvs == NULL)
return -ENODEV;
if (wl->quirks & WLCORE_QUIRK_LEGACY_NVS) {
struct wl1271_nvs_file *nvs =
(struct wl1271_nvs_file *)wl->nvs;
if (wl->nvs_len == sizeof(struct wl1271_nvs_file) ||
wl->nvs_len == WL1271_INI_LEGACY_NVS_FILE_SIZE) {
if (nvs->general_params.dual_mode_select)
wl->enable_11a = true;
}
if (wl->nvs_len != sizeof(struct wl1271_nvs_file) &&
(wl->nvs_len != WL1271_INI_LEGACY_NVS_FILE_SIZE ||
wl->enable_11a)) {
wl1271_error("nvs size is not as expected: %zu != %zu",
wl->nvs_len, sizeof(struct wl1271_nvs_file));
kfree(wl->nvs);
wl->nvs = NULL;
wl->nvs_len = 0;
return -EILSEQ;
}
nvs_len = sizeof(nvs->nvs);
nvs_ptr = (u8 *) nvs->nvs;
} else {
struct wl128x_nvs_file *nvs = (struct wl128x_nvs_file *)wl->nvs;
if (wl->nvs_len == sizeof(struct wl128x_nvs_file)) {
if (nvs->general_params.dual_mode_select)
wl->enable_11a = true;
} else {
wl1271_error("nvs size is not as expected: %zu != %zu",
wl->nvs_len,
sizeof(struct wl128x_nvs_file));
kfree(wl->nvs);
wl->nvs = NULL;
wl->nvs_len = 0;
return -EILSEQ;
}
nvs_len = sizeof(nvs->nvs);
nvs_ptr = (u8 *)nvs->nvs;
}
nvs_ptr[11] = wl->addresses[0].addr[0];
nvs_ptr[10] = wl->addresses[0].addr[1];
nvs_ptr[6] = wl->addresses[0].addr[2];
nvs_ptr[5] = wl->addresses[0].addr[3];
nvs_ptr[4] = wl->addresses[0].addr[4];
nvs_ptr[3] = wl->addresses[0].addr[5];
while (nvs_ptr[0]) {
burst_len = nvs_ptr[0];
dest_addr = (nvs_ptr[1] & 0xfe) | ((u32)(nvs_ptr[2] << 8));
dest_addr += wl->curr_part.reg.start;
nvs_ptr += 3;
for (i = 0; i < burst_len; i++) {
if (nvs_ptr + 3 >= (u8 *) wl->nvs + nvs_len)
goto out_badnvs;
val = (nvs_ptr[0] | (nvs_ptr[1] << 8)
| (nvs_ptr[2] << 16) | (nvs_ptr[3] << 24));
wl1271_debug(DEBUG_BOOT,
"nvs burst write 0x%x: 0x%x",
dest_addr, val);
wl1271_write32(wl, dest_addr, val);
nvs_ptr += 4;
dest_addr += 4;
}
if (nvs_ptr >= (u8 *) wl->nvs + nvs_len)
goto out_badnvs;
}
nvs_ptr = (u8 *)wl->nvs +
ALIGN(nvs_ptr - (u8 *)wl->nvs + 7, 4);
if (nvs_ptr >= (u8 *) wl->nvs + nvs_len)
goto out_badnvs;
nvs_len -= nvs_ptr - (u8 *)wl->nvs;
wlcore_set_partition(wl, &wl->ptable[PART_WORK]);
nvs_aligned = kmemdup(nvs_ptr, nvs_len, GFP_KERNEL);
if (!nvs_aligned)
return -ENOMEM;
wlcore_write_data(wl, REG_CMD_MBOX_ADDRESS,
nvs_aligned, nvs_len, false);
kfree(nvs_aligned);
return 0;
out_badnvs:
wl1271_error("nvs data is malformed");
return -EILSEQ;
}
int wlcore_boot_run_firmware(struct wl1271 *wl)
{
int loop, ret;
u32 chip_id, intr;
wlcore_set_partition(wl, &wl->ptable[PART_BOOT]);
wl1271_boot_set_ecpu_ctrl(wl, ECPU_CONTROL_HALT);
chip_id = wlcore_read_reg(wl, REG_CHIP_ID_B);
wl1271_debug(DEBUG_BOOT, "chip id after firmware boot: 0x%x", chip_id);
if (chip_id != wl->chip.id) {
wl1271_error("chip id doesn't match after firmware boot");
return -EIO;
}
loop = 0;
while (loop++ < INIT_LOOP) {
udelay(INIT_LOOP_DELAY);
intr = wlcore_read_reg(wl, REG_INTERRUPT_NO_CLEAR);
if (intr == 0xffffffff) {
wl1271_error("error reading hardware complete "
"init indication");
return -EIO;
}
else if (intr & WL1271_ACX_INTR_INIT_COMPLETE) {
wlcore_write_reg(wl, REG_INTERRUPT_ACK,
WL1271_ACX_INTR_INIT_COMPLETE);
break;
}
}
if (loop > INIT_LOOP) {
wl1271_error("timeout waiting for the hardware to "
"complete initialization");
return -EIO;
}
wl->cmd_box_addr = wlcore_read_reg(wl, REG_COMMAND_MAILBOX_PTR);
wl1271_debug(DEBUG_MAILBOX, "cmd_box_addr 0x%x", wl->cmd_box_addr);
wl->mbox_ptr[0] = wlcore_read_reg(wl, REG_EVENT_MAILBOX_PTR);
wl->mbox_ptr[1] = wl->mbox_ptr[0] + sizeof(struct event_mailbox);
wl1271_debug(DEBUG_MAILBOX, "MBOX ptrs: 0x%x 0x%x",
wl->mbox_ptr[0], wl->mbox_ptr[1]);
ret = wlcore_boot_fw_version(wl);
if (ret < 0) {
wl1271_error("couldn't boot firmware");
return ret;
}
wl->event_mask = BSS_LOSE_EVENT_ID |
REGAINED_BSS_EVENT_ID |
SCAN_COMPLETE_EVENT_ID |
ROLE_STOP_COMPLETE_EVENT_ID |
RSSI_SNR_TRIGGER_0_EVENT_ID |
PSPOLL_DELIVERY_FAILURE_EVENT_ID |
SOFT_GEMINI_SENSE_EVENT_ID |
PERIODIC_SCAN_REPORT_EVENT_ID |
PERIODIC_SCAN_COMPLETE_EVENT_ID |
DUMMY_PACKET_EVENT_ID |
PEER_REMOVE_COMPLETE_EVENT_ID |
BA_SESSION_RX_CONSTRAINT_EVENT_ID |
REMAIN_ON_CHANNEL_COMPLETE_EVENT_ID |
INACTIVE_STA_EVENT_ID |
MAX_TX_RETRY_EVENT_ID |
CHANNEL_SWITCH_COMPLETE_EVENT_ID;
ret = wl1271_event_unmask(wl);
if (ret < 0) {
wl1271_error("EVENT mask setting failed");
return ret;
}
wlcore_set_partition(wl, &wl->ptable[PART_WORK]);
return 0;
}
