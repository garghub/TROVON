static void wl1271_boot_set_ecpu_ctrl(struct wl1271 *wl, u32 flag)
{
u32 cpu_ctrl;
cpu_ctrl = wl1271_read32(wl, ACX_REG_ECPU_CONTROL);
cpu_ctrl |= flag;
wl1271_write32(wl, ACX_REG_ECPU_CONTROL, cpu_ctrl);
}
static unsigned int wl12xx_get_fw_ver_quirks(struct wl1271 *wl)
{
unsigned int quirks = 0;
unsigned int *fw_ver = wl->chip.fw_ver;
if ((fw_ver[FW_VER_CHIP] == FW_VER_CHIP_WL127X) &&
(((fw_ver[FW_VER_IF_TYPE] == FW_VER_IF_TYPE_STA) &&
(fw_ver[FW_VER_MINOR] < FW_VER_MINOR_1_SPARE_STA_MIN)) ||
((fw_ver[FW_VER_IF_TYPE] == FW_VER_IF_TYPE_AP) &&
(fw_ver[FW_VER_MINOR] < FW_VER_MINOR_1_SPARE_AP_MIN))))
quirks |= WL12XX_QUIRK_USE_2_SPARE_BLOCKS;
if ((fw_ver[FW_VER_IF_TYPE] == FW_VER_IF_TYPE_STA) &&
(fw_ver[FW_VER_MINOR] < FW_VER_MINOR_FWLOG_STA_MIN))
quirks |= WL12XX_QUIRK_FWLOG_NOT_IMPLEMENTED;
if (fw_ver[FW_VER_IF_TYPE] == FW_VER_IF_TYPE_AP)
quirks |= WL12XX_QUIRK_FWLOG_NOT_IMPLEMENTED;
return quirks;
}
static void wl1271_parse_fw_ver(struct wl1271 *wl)
{
int ret;
ret = sscanf(wl->chip.fw_ver_str + 4, "%u.%u.%u.%u.%u",
&wl->chip.fw_ver[0], &wl->chip.fw_ver[1],
&wl->chip.fw_ver[2], &wl->chip.fw_ver[3],
&wl->chip.fw_ver[4]);
if (ret != 5) {
wl1271_warning("fw version incorrect value");
memset(wl->chip.fw_ver, 0, sizeof(wl->chip.fw_ver));
return;
}
wl->quirks |= wl12xx_get_fw_ver_quirks(wl);
}
static void wl1271_boot_fw_version(struct wl1271 *wl)
{
struct wl1271_static_data static_data;
wl1271_read(wl, wl->cmd_box_addr, &static_data, sizeof(static_data),
false);
strncpy(wl->chip.fw_ver_str, static_data.fw_version,
sizeof(wl->chip.fw_ver_str));
wl->chip.fw_ver_str[sizeof(wl->chip.fw_ver_str) - 1] = '\0';
wl1271_parse_fw_ver(wl);
}
static int wl1271_boot_upload_firmware_chunk(struct wl1271 *wl, void *buf,
size_t fw_data_len, u32 dest)
{
struct wl1271_partition_set partition;
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
memcpy(&partition, &part_table[PART_DOWN], sizeof(partition));
partition.mem.start = dest;
wl1271_set_partition(wl, &partition);
chunk_num = 0;
partition_limit = part_table[PART_DOWN].mem.size;
while (chunk_num < fw_data_len / CHUNK_SIZE) {
addr = dest + (chunk_num + 2) * CHUNK_SIZE;
if (addr > partition_limit) {
addr = dest + chunk_num * CHUNK_SIZE;
partition_limit = chunk_num * CHUNK_SIZE +
part_table[PART_DOWN].mem.size;
partition.mem.start = addr;
wl1271_set_partition(wl, &partition);
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
static int wl1271_boot_upload_firmware(struct wl1271 *wl)
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
static int wl1271_boot_upload_nvs(struct wl1271 *wl)
{
size_t nvs_len, burst_len;
int i;
u32 dest_addr, val;
u8 *nvs_ptr, *nvs_aligned;
if (wl->nvs == NULL)
return -ENODEV;
if (wl->chip.id == CHIP_ID_1283_PG20) {
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
} else {
struct wl1271_nvs_file *nvs =
(struct wl1271_nvs_file *)wl->nvs;
if (wl->nvs_len == sizeof(struct wl1271_nvs_file) ||
wl->nvs_len == WL1271_INI_LEGACY_NVS_FILE_SIZE) {
if (wl->bss_type != BSS_TYPE_AP_BSS &&
nvs->general_params.dual_mode_select)
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
}
nvs_ptr[11] = wl->mac_addr[0];
nvs_ptr[10] = wl->mac_addr[1];
nvs_ptr[6] = wl->mac_addr[2];
nvs_ptr[5] = wl->mac_addr[3];
nvs_ptr[4] = wl->mac_addr[4];
nvs_ptr[3] = wl->mac_addr[5];
while (nvs_ptr[0]) {
burst_len = nvs_ptr[0];
dest_addr = (nvs_ptr[1] & 0xfe) | ((u32)(nvs_ptr[2] << 8));
dest_addr += REGISTERS_BASE;
nvs_ptr += 3;
for (i = 0; i < burst_len; i++) {
val = (nvs_ptr[0] | (nvs_ptr[1] << 8)
| (nvs_ptr[2] << 16) | (nvs_ptr[3] << 24));
wl1271_debug(DEBUG_BOOT,
"nvs burst write 0x%x: 0x%x",
dest_addr, val);
wl1271_write32(wl, dest_addr, val);
nvs_ptr += 4;
dest_addr += 4;
}
}
nvs_ptr = (u8 *)wl->nvs +
ALIGN(nvs_ptr - (u8 *)wl->nvs + 7, 4);
nvs_len -= nvs_ptr - (u8 *)wl->nvs;
wl1271_set_partition(wl, &part_table[PART_WORK]);
nvs_aligned = kmemdup(nvs_ptr, nvs_len, GFP_KERNEL);
if (!nvs_aligned)
return -ENOMEM;
wl1271_write(wl, CMD_MBOX_ADDRESS, nvs_aligned, nvs_len, false);
kfree(nvs_aligned);
return 0;
}
static void wl1271_boot_enable_interrupts(struct wl1271 *wl)
{
wl1271_enable_interrupts(wl);
wl1271_write32(wl, ACX_REG_INTERRUPT_MASK,
WL1271_ACX_INTR_ALL & ~(WL1271_INTR_MASK));
wl1271_write32(wl, HI_CFG, HI_CFG_DEF_VAL);
}
static int wl1271_boot_soft_reset(struct wl1271 *wl)
{
unsigned long timeout;
u32 boot_data;
wl1271_write32(wl, ACX_REG_SLV_SOFT_RESET, ACX_SLV_SOFT_RESET_BIT);
timeout = jiffies + usecs_to_jiffies(SOFT_RESET_MAX_TIME);
while (1) {
boot_data = wl1271_read32(wl, ACX_REG_SLV_SOFT_RESET);
wl1271_debug(DEBUG_BOOT, "soft reset bootdata 0x%x", boot_data);
if ((boot_data & ACX_SLV_SOFT_RESET_BIT) == 0)
break;
if (time_after(jiffies, timeout)) {
wl1271_error("soft reset timeout");
return -1;
}
udelay(SOFT_RESET_STALL_TIME);
}
wl1271_write32(wl, ENABLE, 0x0);
wl1271_write32(wl, SPARE_A2, 0xffff);
return 0;
}
static int wl1271_boot_run_firmware(struct wl1271 *wl)
{
int loop, ret;
u32 chip_id, intr;
wl1271_boot_set_ecpu_ctrl(wl, ECPU_CONTROL_HALT);
chip_id = wl1271_read32(wl, CHIP_ID_B);
wl1271_debug(DEBUG_BOOT, "chip id after firmware boot: 0x%x", chip_id);
if (chip_id != wl->chip.id) {
wl1271_error("chip id doesn't match after firmware boot");
return -EIO;
}
loop = 0;
while (loop++ < INIT_LOOP) {
udelay(INIT_LOOP_DELAY);
intr = wl1271_read32(wl, ACX_REG_INTERRUPT_NO_CLEAR);
if (intr == 0xffffffff) {
wl1271_error("error reading hardware complete "
"init indication");
return -EIO;
}
else if (intr & WL1271_ACX_INTR_INIT_COMPLETE) {
wl1271_write32(wl, ACX_REG_INTERRUPT_ACK,
WL1271_ACX_INTR_INIT_COMPLETE);
break;
}
}
if (loop > INIT_LOOP) {
wl1271_error("timeout waiting for the hardware to "
"complete initialization");
return -EIO;
}
wl->cmd_box_addr = wl1271_read32(wl, REG_COMMAND_MAILBOX_PTR);
wl->event_box_addr = wl1271_read32(wl, REG_EVENT_MAILBOX_PTR);
wl1271_set_partition(wl, &part_table[PART_WORK]);
wl1271_debug(DEBUG_MAILBOX, "cmd_box_addr 0x%x event_box_addr 0x%x",
wl->cmd_box_addr, wl->event_box_addr);
wl1271_boot_fw_version(wl);
wl->event_mask = BSS_LOSE_EVENT_ID |
SCAN_COMPLETE_EVENT_ID |
PS_REPORT_EVENT_ID |
JOIN_EVENT_COMPLETE_ID |
DISCONNECT_EVENT_COMPLETE_ID |
RSSI_SNR_TRIGGER_0_EVENT_ID |
PSPOLL_DELIVERY_FAILURE_EVENT_ID |
SOFT_GEMINI_SENSE_EVENT_ID |
PERIODIC_SCAN_REPORT_EVENT_ID |
PERIODIC_SCAN_COMPLETE_EVENT_ID;
if (wl->bss_type == BSS_TYPE_AP_BSS)
wl->event_mask |= STA_REMOVE_COMPLETE_EVENT_ID |
INACTIVE_STA_EVENT_ID |
MAX_TX_RETRY_EVENT_ID;
else
wl->event_mask |= DUMMY_PACKET_EVENT_ID |
BA_SESSION_RX_CONSTRAINT_EVENT_ID;
ret = wl1271_event_unmask(wl);
if (ret < 0) {
wl1271_error("EVENT mask setting failed");
return ret;
}
wl1271_event_mbox_config(wl);
return 0;
}
static int wl1271_boot_write_irq_polarity(struct wl1271 *wl)
{
u32 polarity;
polarity = wl1271_top_reg_read(wl, OCP_REG_POLARITY);
polarity &= ~POLARITY_LOW;
wl1271_top_reg_write(wl, OCP_REG_POLARITY, polarity);
return 0;
}
static void wl1271_boot_hw_version(struct wl1271 *wl)
{
u32 fuse;
fuse = wl1271_top_reg_read(wl, REG_FUSE_DATA_2_1);
fuse = (fuse & PG_VER_MASK) >> PG_VER_OFFSET;
wl->hw_pg_ver = (s8)fuse;
if (((wl->hw_pg_ver & PG_MAJOR_VER_MASK) >> PG_MAJOR_VER_OFFSET) < 3)
wl->quirks |= WL12XX_QUIRK_END_OF_TRANSACTION;
}
static int wl128x_switch_tcxo_to_fref(struct wl1271 *wl)
{
u16 spare_reg;
spare_reg = wl1271_top_reg_read(wl, WL_SPARE_REG);
if (spare_reg == 0xFFFF)
return -EFAULT;
spare_reg |= (BIT(3) | BIT(5) | BIT(6));
wl1271_top_reg_write(wl, WL_SPARE_REG, spare_reg);
wl1271_top_reg_write(wl, SYS_CLK_CFG_REG,
WL_CLK_REQ_TYPE_PG2 | MCS_PLL_CLK_SEL_FREF);
mdelay(15);
return 0;
}
static bool wl128x_is_tcxo_valid(struct wl1271 *wl)
{
u16 tcxo_detection;
tcxo_detection = wl1271_top_reg_read(wl, TCXO_CLK_DETECT_REG);
if (tcxo_detection & TCXO_DET_FAILED)
return false;
return true;
}
static bool wl128x_is_fref_valid(struct wl1271 *wl)
{
u16 fref_detection;
fref_detection = wl1271_top_reg_read(wl, FREF_CLK_DETECT_REG);
if (fref_detection & FREF_CLK_DETECT_FAIL)
return false;
return true;
}
static int wl128x_manually_configure_mcs_pll(struct wl1271 *wl)
{
wl1271_top_reg_write(wl, MCS_PLL_M_REG, MCS_PLL_M_REG_VAL);
wl1271_top_reg_write(wl, MCS_PLL_N_REG, MCS_PLL_N_REG_VAL);
wl1271_top_reg_write(wl, MCS_PLL_CONFIG_REG, MCS_PLL_CONFIG_REG_VAL);
return 0;
}
static int wl128x_configure_mcs_pll(struct wl1271 *wl, int clk)
{
u16 spare_reg;
u16 pll_config;
u8 input_freq;
spare_reg = wl1271_top_reg_read(wl, WL_SPARE_REG);
if (spare_reg == 0xFFFF)
return -EFAULT;
spare_reg |= BIT(2);
wl1271_top_reg_write(wl, WL_SPARE_REG, spare_reg);
if (wl->tcxo_clock == WL12XX_TCXOCLOCK_16_8 ||
wl->tcxo_clock == WL12XX_TCXOCLOCK_33_6)
return wl128x_manually_configure_mcs_pll(wl);
input_freq = (clk & 1) + 1;
pll_config = wl1271_top_reg_read(wl, MCS_PLL_CONFIG_REG);
if (pll_config == 0xFFFF)
return -EFAULT;
pll_config |= (input_freq << MCS_SEL_IN_FREQ_SHIFT);
pll_config |= MCS_PLL_ENABLE_HP;
wl1271_top_reg_write(wl, MCS_PLL_CONFIG_REG, pll_config);
return 0;
}
static int wl128x_boot_clk(struct wl1271 *wl, int *selected_clock)
{
u16 sys_clk_cfg;
if (wl->ref_clock == WL12XX_REFCLOCK_26_XTAL ||
wl->ref_clock == WL12XX_REFCLOCK_38_XTAL) {
if (!wl128x_switch_tcxo_to_fref(wl))
return -EINVAL;
goto fref_clk;
}
sys_clk_cfg = wl1271_top_reg_read(wl, SYS_CLK_CFG_REG);
if (sys_clk_cfg == 0xFFFF)
return -EINVAL;
if (sys_clk_cfg & PRCM_CM_EN_MUX_WLAN_FREF)
goto fref_clk;
if (wl->tcxo_clock == WL12XX_TCXOCLOCK_16_368 ||
wl->tcxo_clock == WL12XX_TCXOCLOCK_32_736) {
if (!wl128x_switch_tcxo_to_fref(wl))
return -EINVAL;
goto fref_clk;
}
if (!wl128x_is_tcxo_valid(wl))
return -EINVAL;
*selected_clock = wl->tcxo_clock;
goto config_mcs_pll;
fref_clk:
if (!wl128x_is_fref_valid(wl))
return -EINVAL;
*selected_clock = wl->ref_clock;
config_mcs_pll:
return wl128x_configure_mcs_pll(wl, *selected_clock);
}
static int wl127x_boot_clk(struct wl1271 *wl)
{
u32 pause;
u32 clk;
wl1271_boot_hw_version(wl);
if (wl->ref_clock == CONF_REF_CLK_19_2_E ||
wl->ref_clock == CONF_REF_CLK_38_4_E ||
wl->ref_clock == CONF_REF_CLK_38_4_M_XTAL)
clk = 0x3;
else if (wl->ref_clock == CONF_REF_CLK_26_E ||
wl->ref_clock == CONF_REF_CLK_52_E)
clk = 0x5;
else
return -EINVAL;
if (wl->ref_clock != CONF_REF_CLK_19_2_E) {
u16 val;
val = wl1271_top_reg_read(wl, OCP_REG_CLK_TYPE);
val &= FREF_CLK_TYPE_BITS;
wl1271_top_reg_write(wl, OCP_REG_CLK_TYPE, val);
val = wl1271_top_reg_read(wl, OCP_REG_CLK_PULL);
val |= NO_PULL;
wl1271_top_reg_write(wl, OCP_REG_CLK_PULL, val);
} else {
u16 val;
val = wl1271_top_reg_read(wl, OCP_REG_CLK_POLARITY);
val &= FREF_CLK_POLARITY_BITS;
val |= CLK_REQ_OUTN_SEL;
wl1271_top_reg_write(wl, OCP_REG_CLK_POLARITY, val);
}
wl1271_write32(wl, PLL_PARAMETERS, clk);
pause = wl1271_read32(wl, PLL_PARAMETERS);
wl1271_debug(DEBUG_BOOT, "pause1 0x%x", pause);
pause &= ~(WU_COUNTER_PAUSE_VAL);
pause |= WU_COUNTER_PAUSE_VAL;
wl1271_write32(wl, WU_COUNTER_PAUSE, pause);
return 0;
}
int wl1271_load_firmware(struct wl1271 *wl)
{
int ret = 0;
u32 tmp, clk;
int selected_clock = -1;
if (wl->chip.id == CHIP_ID_1283_PG20) {
ret = wl128x_boot_clk(wl, &selected_clock);
if (ret < 0)
goto out;
} else {
ret = wl127x_boot_clk(wl);
if (ret < 0)
goto out;
}
wl1271_write32(wl, WELP_ARM_COMMAND, WELP_ARM_COMMAND_VAL);
udelay(500);
wl1271_set_partition(wl, &part_table[PART_DRPW]);
wl1271_debug(DEBUG_BOOT, "DRPW_SCRATCH_START %08x", DRPW_SCRATCH_START);
clk = wl1271_read32(wl, DRPW_SCRATCH_START);
wl1271_debug(DEBUG_BOOT, "clk2 0x%x", clk);
if (wl->chip.id == CHIP_ID_1283_PG20) {
clk |= ((selected_clock & 0x3) << 1) << 4;
} else {
clk |= (wl->ref_clock << 1) << 4;
}
if (wl->quirks & WL12XX_QUIRK_LPD_MODE)
clk |= SCRATCH_ENABLE_LPD;
wl1271_write32(wl, DRPW_SCRATCH_START, clk);
wl1271_set_partition(wl, &part_table[PART_WORK]);
wl1271_write32(wl, ACX_REG_INTERRUPT_MASK, WL1271_ACX_INTR_ALL);
ret = wl1271_boot_soft_reset(wl);
if (ret < 0)
goto out;
ret = wl1271_boot_upload_nvs(wl);
if (ret < 0)
goto out;
wl1271_debug(DEBUG_BOOT, "ACX_EEPROMLESS_IND_REG");
wl1271_write32(wl, ACX_EEPROMLESS_IND_REG, ACX_EEPROMLESS_IND_REG);
tmp = wl1271_read32(wl, CHIP_ID_B);
wl1271_debug(DEBUG_BOOT, "chip id 0x%x", tmp);
tmp = wl1271_read32(wl, SCR_PAD2);
if (wl->chip.id == CHIP_ID_1283_PG20)
wl1271_top_reg_write(wl, SDIO_IO_DS, wl->conf.hci_io_ds);
ret = wl1271_boot_upload_firmware(wl);
if (ret < 0)
goto out;
out:
return ret;
}
int wl1271_boot(struct wl1271 *wl)
{
int ret;
ret = wl1271_load_firmware(wl);
if (ret)
return ret;
ret = wl1271_boot_run_firmware(wl);
if (ret < 0)
goto out;
ret = wl1271_boot_write_irq_polarity(wl);
if (ret < 0)
goto out;
wl1271_write32(wl, ACX_REG_INTERRUPT_MASK,
WL1271_ACX_ALL_EVENTS_VECTOR);
wl1271_boot_enable_interrupts(wl);
wl1271_set_default_filters(wl);
wl1271_event_mbox_config(wl);
out:
return ret;
}
