void firmware_init_param(struct r8192_priv *priv)
{
rt_firmware *pfirmware = priv->pFirmware;
pfirmware->cmdpacket_frag_thresold =
GET_COMMAND_PACKET_FRAG_THRESHOLD(MAX_TRANSMIT_BUFFER_SIZE);
}
static bool fw_download_code(struct r8192_priv *priv, u8 *code_virtual_address,
u32 buffer_len)
{
bool rt_status = true;
u16 frag_threshold;
u16 frag_length, frag_offset = 0;
int i;
rt_firmware *pfirmware = priv->pFirmware;
struct sk_buff *skb;
unsigned char *seg_ptr;
cb_desc *tcb_desc;
u8 bLastIniPkt;
firmware_init_param(priv);
frag_threshold = pfirmware->cmdpacket_frag_thresold;
do {
if ((buffer_len - frag_offset) > frag_threshold) {
frag_length = frag_threshold ;
bLastIniPkt = 0;
} else {
frag_length = buffer_len - frag_offset;
bLastIniPkt = 1;
}
skb = dev_alloc_skb(frag_length + 4);
tcb_desc = (cb_desc *)(skb->cb + MAX_DEV_ADDR_SIZE);
tcb_desc->queue_index = TXCMD_QUEUE;
tcb_desc->bCmdOrInit = DESC_PACKET_TYPE_INIT;
tcb_desc->bLastIniPkt = bLastIniPkt;
seg_ptr = skb->data;
for (i = 0; i < frag_length; i += 4) {
*seg_ptr++ = ((i+0) < frag_length) ?
code_virtual_address[i+3] : 0;
*seg_ptr++ = ((i+1) < frag_length) ?
code_virtual_address[i+2] : 0;
*seg_ptr++ = ((i+2) < frag_length) ?
code_virtual_address[i+1] : 0;
*seg_ptr++ = ((i+3) < frag_length) ?
code_virtual_address[i+0] : 0;
}
tcb_desc->txbuf_size = (u16)i;
skb_put(skb, i);
priv->ieee80211->softmac_hard_start_xmit(skb, priv->ieee80211);
code_virtual_address += frag_length;
frag_offset += frag_length;
} while (frag_offset < buffer_len);
return rt_status;
}
static bool CPUcheck_maincodeok_turnonCPU(struct r8192_priv *priv)
{
unsigned long timeout;
bool rt_status = true;
u32 CPU_status = 0;
timeout = jiffies + msecs_to_jiffies(20);
while (time_before(jiffies, timeout)) {
CPU_status = read_nic_dword(priv, CPU_GEN);
if (CPU_status & CPU_GEN_PUT_CODE_OK)
break;
msleep(2);
}
if (!(CPU_status & CPU_GEN_PUT_CODE_OK)) {
RT_TRACE(COMP_ERR, "Download Firmware: Put code fail!\n");
goto CPUCheckMainCodeOKAndTurnOnCPU_Fail;
} else {
RT_TRACE(COMP_FIRMWARE, "Download Firmware: Put code ok!\n");
}
CPU_status = read_nic_dword(priv, CPU_GEN);
write_nic_byte(priv, CPU_GEN,
(u8)((CPU_status | CPU_GEN_PWR_STB_CPU) & 0xff));
mdelay(1);
timeout = jiffies + msecs_to_jiffies(20);
while (time_before(jiffies, timeout)) {
CPU_status = read_nic_dword(priv, CPU_GEN);
if (CPU_status & CPU_GEN_BOOT_RDY)
break;
msleep(2);
}
if (!(CPU_status & CPU_GEN_BOOT_RDY))
goto CPUCheckMainCodeOKAndTurnOnCPU_Fail;
else
RT_TRACE(COMP_FIRMWARE, "Download Firmware: Boot ready!\n");
return rt_status;
CPUCheckMainCodeOKAndTurnOnCPU_Fail:
RT_TRACE(COMP_ERR, "ERR in %s()\n", __func__);
rt_status = FALSE;
return rt_status;
}
static bool CPUcheck_firmware_ready(struct r8192_priv *priv)
{
unsigned long timeout;
bool rt_status = true;
u32 CPU_status = 0;
timeout = jiffies + msecs_to_jiffies(20);
while (time_before(jiffies, timeout)) {
CPU_status = read_nic_dword(priv, CPU_GEN);
if (CPU_status & CPU_GEN_FIRM_RDY)
break;
msleep(2);
}
if (!(CPU_status & CPU_GEN_FIRM_RDY))
goto CPUCheckFirmwareReady_Fail;
else
RT_TRACE(COMP_FIRMWARE, "Download Firmware: Firmware ready!\n");
return rt_status;
CPUCheckFirmwareReady_Fail:
RT_TRACE(COMP_ERR, "ERR in %s()\n", __func__);
rt_status = false;
return rt_status;
}
bool init_firmware(struct r8192_priv *priv)
{
bool rt_status = true;
u32 file_length = 0;
u8 *mapped_file = NULL;
u32 init_step = 0;
enum opt_rst_type rst_opt = OPT_SYSTEM_RESET;
enum firmware_init_step starting_state = FW_INIT_STEP0_BOOT;
rt_firmware *pfirmware = priv->pFirmware;
const struct firmware *fw_entry;
const char *fw_name[3] = { "RTL8192E/boot.img",
"RTL8192E/main.img",
"RTL8192E/data.img"};
int rc;
RT_TRACE(COMP_FIRMWARE, " PlatformInitFirmware()==>\n");
if (pfirmware->firmware_status == FW_STATUS_0_INIT) {
rst_opt = OPT_SYSTEM_RESET;
starting_state = FW_INIT_STEP0_BOOT;
} else if (pfirmware->firmware_status == FW_STATUS_5_READY) {
rst_opt = OPT_FIRMWARE_RESET;
starting_state = FW_INIT_STEP2_DATA;
} else {
RT_TRACE(COMP_FIRMWARE,
"PlatformInitFirmware: undefined firmware state\n");
}
for (init_step = starting_state; init_step <= FW_INIT_STEP2_DATA;
init_step++) {
if (rst_opt == OPT_SYSTEM_RESET) {
if (pfirmware->firmware_buf_size[init_step] == 0) {
rc = request_firmware(&fw_entry,
fw_name[init_step], &priv->pdev->dev);
if (rc < 0) {
RT_TRACE(COMP_FIRMWARE, "request firmware fail!\n");
goto download_firmware_fail;
}
if (fw_entry->size > sizeof(pfirmware->firmware_buf[init_step])) {
RT_TRACE(COMP_FIRMWARE,
"img file size exceed the container buffer fail!\n");
goto download_firmware_fail;
}
if (init_step != FW_INIT_STEP1_MAIN) {
memcpy(pfirmware->firmware_buf[init_step],
fw_entry->data, fw_entry->size);
pfirmware->firmware_buf_size[init_step] = fw_entry->size;
} else {
memset(pfirmware->firmware_buf[init_step], 0, 128);
memcpy(&pfirmware->firmware_buf[init_step][128], fw_entry->data,
fw_entry->size);
pfirmware->firmware_buf_size[init_step] = fw_entry->size+128;
}
if (rst_opt == OPT_SYSTEM_RESET)
release_firmware(fw_entry);
}
mapped_file = pfirmware->firmware_buf[init_step];
file_length = pfirmware->firmware_buf_size[init_step];
} else if (rst_opt == OPT_FIRMWARE_RESET) {
mapped_file = pfirmware->firmware_buf[init_step];
file_length = pfirmware->firmware_buf_size[init_step];
}
rt_status = fw_download_code(priv, mapped_file, file_length);
if (rt_status != TRUE)
goto download_firmware_fail;
switch (init_step) {
case FW_INIT_STEP0_BOOT:
pfirmware->firmware_status = FW_STATUS_1_MOVE_BOOT_CODE;
break;
case FW_INIT_STEP1_MAIN:
pfirmware->firmware_status = FW_STATUS_2_MOVE_MAIN_CODE;
rt_status = CPUcheck_maincodeok_turnonCPU(priv);
if (rt_status != TRUE) {
RT_TRACE(COMP_FIRMWARE,
"CPUcheck_maincodeok_turnonCPU fail!\n");
goto download_firmware_fail;
}
pfirmware->firmware_status = FW_STATUS_3_TURNON_CPU;
break;
case FW_INIT_STEP2_DATA:
pfirmware->firmware_status = FW_STATUS_4_MOVE_DATA_CODE;
mdelay(1);
rt_status = CPUcheck_firmware_ready(priv);
if (rt_status != TRUE) {
RT_TRACE(COMP_FIRMWARE,
"CPUcheck_firmware_ready fail(%d)!\n",
rt_status);
goto download_firmware_fail;
}
pfirmware->firmware_status = FW_STATUS_5_READY;
break;
}
}
RT_TRACE(COMP_FIRMWARE, "Firmware Download Success\n");
return rt_status;
download_firmware_fail:
RT_TRACE(COMP_ERR, "ERR in %s() step %d\n", __func__, init_step);
rt_status = false;
return rt_status;
}
