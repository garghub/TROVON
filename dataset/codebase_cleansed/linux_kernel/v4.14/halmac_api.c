static enum halmac_ret_status
halmac_check_platform_api(void *driver_adapter,
enum halmac_interface halmac_interface,
struct halmac_platform_api *halmac_platform_api)
{
void *adapter_local = NULL;
adapter_local = driver_adapter;
if (!halmac_platform_api)
return HALMAC_RET_PLATFORM_API_NULL;
if (halmac_interface == HALMAC_INTERFACE_SDIO) {
if (!halmac_platform_api->SDIO_CMD52_READ) {
pr_err("(!halmac_platform_api->SDIO_CMD52_READ)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->SDIO_CMD53_READ_8) {
pr_err("(!halmac_platform_api->SDIO_CMD53_READ_8)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->SDIO_CMD53_READ_16) {
pr_err("(!halmac_platform_api->SDIO_CMD53_READ_16)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->SDIO_CMD53_READ_32) {
pr_err("(!halmac_platform_api->SDIO_CMD53_READ_32)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->SDIO_CMD53_READ_N) {
pr_err("(!halmac_platform_api->SDIO_CMD53_READ_N)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->SDIO_CMD52_WRITE) {
pr_err("(!halmac_platform_api->SDIO_CMD52_WRITE)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->SDIO_CMD53_WRITE_8) {
pr_err("(!halmac_platform_api->SDIO_CMD53_WRITE_8)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->SDIO_CMD53_WRITE_16) {
pr_err("(!halmac_platform_api->SDIO_CMD53_WRITE_16)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->SDIO_CMD53_WRITE_32) {
pr_err("(!halmac_platform_api->SDIO_CMD53_WRITE_32)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
}
if (halmac_interface == HALMAC_INTERFACE_USB ||
halmac_interface == HALMAC_INTERFACE_PCIE) {
if (!halmac_platform_api->REG_READ_8) {
pr_err("(!halmac_platform_api->REG_READ_8)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->REG_READ_16) {
pr_err("(!halmac_platform_api->REG_READ_16)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->REG_READ_32) {
pr_err("(!halmac_platform_api->REG_READ_32)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->REG_WRITE_8) {
pr_err("(!halmac_platform_api->REG_WRITE_8)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->REG_WRITE_16) {
pr_err("(!halmac_platform_api->REG_WRITE_16)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
if (!halmac_platform_api->REG_WRITE_32) {
pr_err("(!halmac_platform_api->REG_WRITE_32)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
}
if (!halmac_platform_api->EVENT_INDICATION) {
pr_err("(!halmac_platform_api->EVENT_INDICATION)\n");
return HALMAC_RET_PLATFORM_API_NULL;
}
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"%s ==========>\n", __func__);
return HALMAC_RET_SUCCESS;
}
static enum halmac_ret_status
halmac_convert_to_sdio_bus_offset(u32 *halmac_offset)
{
switch ((*halmac_offset) & 0xFFFF0000) {
case WLAN_IOREG_OFFSET:
*halmac_offset = (HALMAC_SDIO_CMD_ADDR_MAC_REG << 13) |
(*halmac_offset & HALMAC_WLAN_MAC_REG_MSK);
break;
case SDIO_LOCAL_OFFSET:
*halmac_offset = (HALMAC_SDIO_CMD_ADDR_SDIO_REG << 13) |
(*halmac_offset & HALMAC_SDIO_LOCAL_MSK);
break;
default:
*halmac_offset = 0xFFFFFFFF;
return HALMAC_RET_CONVERT_SDIO_OFFSET_FAIL;
}
return HALMAC_RET_SUCCESS;
}
static u8
platform_reg_read_8_sdio(void *driver_adapter,
struct halmac_platform_api *halmac_platform_api,
u32 offset)
{
u8 value8;
u32 halmac_offset = offset;
enum halmac_ret_status status = HALMAC_RET_SUCCESS;
if ((halmac_offset & 0xFFFF0000) == 0)
halmac_offset |= WLAN_IOREG_OFFSET;
status = halmac_convert_to_sdio_bus_offset(&halmac_offset);
if (status != HALMAC_RET_SUCCESS) {
pr_err("%s error = %x\n", __func__, status);
return status;
}
value8 = halmac_platform_api->SDIO_CMD52_READ(driver_adapter,
halmac_offset);
return value8;
}
static enum halmac_ret_status
platform_reg_write_8_sdio(void *driver_adapter,
struct halmac_platform_api *halmac_platform_api,
u32 offset, u8 data)
{
enum halmac_ret_status status = HALMAC_RET_SUCCESS;
u32 halmac_offset = offset;
if ((halmac_offset & 0xFFFF0000) == 0)
halmac_offset |= WLAN_IOREG_OFFSET;
status = halmac_convert_to_sdio_bus_offset(&halmac_offset);
if (status != HALMAC_RET_SUCCESS) {
pr_err("halmac_reg_write_8_sdio_88xx error = %x\n", status);
return status;
}
halmac_platform_api->SDIO_CMD52_WRITE(driver_adapter, halmac_offset,
data);
return HALMAC_RET_SUCCESS;
}
static enum halmac_ret_status
halmac_get_chip_info(void *driver_adapter,
struct halmac_platform_api *halmac_platform_api,
enum halmac_interface halmac_interface,
struct halmac_adapter *halmac_adapter)
{
struct halmac_api *halmac_api = (struct halmac_api *)NULL;
u8 chip_id, chip_version;
u32 polling_count;
halmac_api = (struct halmac_api *)halmac_adapter->halmac_api;
if (halmac_adapter->halmac_interface == HALMAC_INTERFACE_SDIO) {
platform_reg_write_8_sdio(
driver_adapter, halmac_platform_api, REG_SDIO_HSUS_CTRL,
platform_reg_read_8_sdio(driver_adapter,
halmac_platform_api,
REG_SDIO_HSUS_CTRL) &
~(BIT(0)));
polling_count = 10000;
while (!(platform_reg_read_8_sdio(driver_adapter,
halmac_platform_api,
REG_SDIO_HSUS_CTRL) &
0x02)) {
polling_count--;
if (polling_count == 0)
return HALMAC_RET_SDIO_LEAVE_SUSPEND_FAIL;
}
chip_id = platform_reg_read_8_sdio(
driver_adapter, halmac_platform_api, REG_SYS_CFG2);
chip_version = platform_reg_read_8_sdio(driver_adapter,
halmac_platform_api,
REG_SYS_CFG1 + 1) >>
4;
} else {
chip_id = halmac_platform_api->REG_READ_8(driver_adapter,
REG_SYS_CFG2);
chip_version = halmac_platform_api->REG_READ_8(
driver_adapter, REG_SYS_CFG1 + 1) >>
4;
}
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"[TRACE]Chip id : 0x%X\n", chip_id);
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"[TRACE]Chip version : 0x%X\n", chip_version);
halmac_adapter->chip_version = (enum halmac_chip_ver)chip_version;
if (chip_id == HALMAC_CHIP_ID_HW_DEF_8822B)
halmac_adapter->chip_id = HALMAC_CHIP_ID_8822B;
else if (chip_id == HALMAC_CHIP_ID_HW_DEF_8821C)
halmac_adapter->chip_id = HALMAC_CHIP_ID_8821C;
else if (chip_id == HALMAC_CHIP_ID_HW_DEF_8814B)
halmac_adapter->chip_id = HALMAC_CHIP_ID_8814B;
else if (chip_id == HALMAC_CHIP_ID_HW_DEF_8197F)
halmac_adapter->chip_id = HALMAC_CHIP_ID_8197F;
else
halmac_adapter->chip_id = HALMAC_CHIP_ID_UNDEFINE;
if (halmac_adapter->chip_id == HALMAC_CHIP_ID_UNDEFINE)
return HALMAC_RET_CHIP_NOT_SUPPORT;
return HALMAC_RET_SUCCESS;
}
enum halmac_ret_status
halmac_init_adapter(void *driver_adapter,
struct halmac_platform_api *halmac_platform_api,
enum halmac_interface halmac_interface,
struct halmac_adapter **pp_halmac_adapter,
struct halmac_api **pp_halmac_api)
{
struct halmac_adapter *halmac_adapter = (struct halmac_adapter *)NULL;
enum halmac_ret_status status = HALMAC_RET_SUCCESS;
union {
u32 i;
u8 x[4];
} ENDIAN_CHECK = {0x01000000};
status = halmac_check_platform_api(driver_adapter, halmac_interface,
halmac_platform_api);
if (status != HALMAC_RET_SUCCESS)
return status;
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
HALMAC_SVN_VER "\n");
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"HALMAC_MAJOR_VER = %x\n", HALMAC_MAJOR_VER);
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"HALMAC_PROTOTYPE_VER = %x\n", HALMAC_PROTOTYPE_VER);
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"HALMAC_MINOR_VER = %x\n", HALMAC_MINOR_VER);
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"HALMAC_PATCH_VER = %x\n", HALMAC_PATCH_VER);
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"halmac_init_adapter_88xx ==========>\n");
if (ENDIAN_CHECK.x[0] == HALMAC_SYSTEM_ENDIAN) {
pr_err("Endian setting Err!!\n");
return HALMAC_RET_ENDIAN_ERR;
}
halmac_adapter = kzalloc(sizeof(*halmac_adapter), GFP_KERNEL);
if (!halmac_adapter) {
return HALMAC_RET_MALLOC_FAIL;
}
*pp_halmac_adapter = halmac_adapter;
halmac_adapter->halmac_platform_api = halmac_platform_api;
halmac_adapter->driver_adapter = driver_adapter;
halmac_interface = halmac_interface == HALMAC_INTERFACE_AXI ?
HALMAC_INTERFACE_PCIE :
halmac_interface;
halmac_adapter->halmac_interface = halmac_interface;
spin_lock_init(&halmac_adapter->efuse_lock);
spin_lock_init(&halmac_adapter->h2c_seq_lock);
if (halmac_get_chip_info(driver_adapter, halmac_platform_api,
halmac_interface,
halmac_adapter) != HALMAC_RET_SUCCESS) {
pr_err("HALMAC_RET_CHIP_NOT_SUPPORT\n");
return HALMAC_RET_CHIP_NOT_SUPPORT;
}
halmac_init_adapter_para_88xx(halmac_adapter);
status = halmac_mount_api_88xx(halmac_adapter);
*pp_halmac_api = (struct halmac_api *)halmac_adapter->halmac_api;
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"halmac_init_adapter_88xx <==========\n");
return status;
}
enum halmac_ret_status halmac_halt_api(struct halmac_adapter *halmac_adapter)
{
void *driver_adapter = NULL;
struct halmac_platform_api *halmac_platform_api =
(struct halmac_platform_api *)NULL;
if (halmac_adapter_validate(halmac_adapter) != HALMAC_RET_SUCCESS)
return HALMAC_RET_ADAPTER_INVALID;
driver_adapter = halmac_adapter->driver_adapter;
halmac_platform_api = halmac_adapter->halmac_platform_api;
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"%s ==========>\n", __func__);
halmac_adapter->halmac_state.api_state = HALMAC_API_STATE_HALT;
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"%s ==========>\n", __func__);
return HALMAC_RET_SUCCESS;
}
enum halmac_ret_status
halmac_deinit_adapter(struct halmac_adapter *halmac_adapter)
{
void *driver_adapter = NULL;
if (halmac_adapter_validate(halmac_adapter) != HALMAC_RET_SUCCESS)
return HALMAC_RET_ADAPTER_INVALID;
driver_adapter = halmac_adapter->driver_adapter;
HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_INIT, DBG_DMESG,
"[TRACE]halmac_deinit_adapter_88xx ==========>\n");
kfree(halmac_adapter->hal_efuse_map);
halmac_adapter->hal_efuse_map = (u8 *)NULL;
kfree(halmac_adapter->halmac_state.psd_set.data);
halmac_adapter->halmac_state.psd_set.data = (u8 *)NULL;
kfree(halmac_adapter->halmac_api);
halmac_adapter->halmac_api = NULL;
halmac_adapter->hal_adapter_backup = NULL;
kfree(halmac_adapter);
return HALMAC_RET_SUCCESS;
}
enum halmac_ret_status halmac_get_version(struct halmac_ver *version)
{
version->major_ver = (u8)HALMAC_MAJOR_VER;
version->prototype_ver = (u8)HALMAC_PROTOTYPE_VER;
version->minor_ver = (u8)HALMAC_MINOR_VER;
return HALMAC_RET_SUCCESS;
}
