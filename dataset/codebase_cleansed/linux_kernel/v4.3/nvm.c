static int iwl_nvm_write_chunk(struct iwl_mvm *mvm, u16 section,
u16 offset, u16 length, const u8 *data)
{
struct iwl_nvm_access_cmd nvm_access_cmd = {
.offset = cpu_to_le16(offset),
.length = cpu_to_le16(length),
.type = cpu_to_le16(section),
.op_code = NVM_WRITE_OPCODE,
};
struct iwl_host_cmd cmd = {
.id = NVM_ACCESS_CMD,
.len = { sizeof(struct iwl_nvm_access_cmd), length },
.flags = CMD_SEND_IN_RFKILL,
.data = { &nvm_access_cmd, data },
.dataflags = { 0, IWL_HCMD_DFL_DUP },
};
return iwl_mvm_send_cmd(mvm, &cmd);
}
static int iwl_nvm_read_chunk(struct iwl_mvm *mvm, u16 section,
u16 offset, u16 length, u8 *data)
{
struct iwl_nvm_access_cmd nvm_access_cmd = {
.offset = cpu_to_le16(offset),
.length = cpu_to_le16(length),
.type = cpu_to_le16(section),
.op_code = NVM_READ_OPCODE,
};
struct iwl_nvm_access_resp *nvm_resp;
struct iwl_rx_packet *pkt;
struct iwl_host_cmd cmd = {
.id = NVM_ACCESS_CMD,
.flags = CMD_WANT_SKB | CMD_SEND_IN_RFKILL,
.data = { &nvm_access_cmd, },
};
int ret, bytes_read, offset_read;
u8 *resp_data;
cmd.len[0] = sizeof(struct iwl_nvm_access_cmd);
ret = iwl_mvm_send_cmd(mvm, &cmd);
if (ret)
return ret;
pkt = cmd.resp_pkt;
nvm_resp = (void *)pkt->data;
ret = le16_to_cpu(nvm_resp->status);
bytes_read = le16_to_cpu(nvm_resp->length);
offset_read = le16_to_cpu(nvm_resp->offset);
resp_data = nvm_resp->data;
if (ret) {
if ((offset != 0) &&
(ret == READ_NVM_CHUNK_NOT_VALID_ADDRESS)) {
IWL_DEBUG_EEPROM(mvm->trans->dev,
"NVM access command failed on offset 0x%x since that section size is multiple 2K\n",
offset);
ret = 0;
} else {
IWL_DEBUG_EEPROM(mvm->trans->dev,
"NVM access command failed with status %d (device: %s)\n",
ret, mvm->cfg->name);
ret = -EIO;
}
goto exit;
}
if (offset_read != offset) {
IWL_ERR(mvm, "NVM ACCESS response with invalid offset %d\n",
offset_read);
ret = -EINVAL;
goto exit;
}
memcpy(data + offset, resp_data, bytes_read);
ret = bytes_read;
exit:
iwl_free_resp(&cmd);
return ret;
}
static int iwl_nvm_write_section(struct iwl_mvm *mvm, u16 section,
const u8 *data, u16 length)
{
int offset = 0;
while (offset < length) {
int chunk_size, ret;
chunk_size = min(IWL_NVM_DEFAULT_CHUNK_SIZE,
length - offset);
ret = iwl_nvm_write_chunk(mvm, section, offset,
chunk_size, data + offset);
if (ret < 0)
return ret;
offset += chunk_size;
}
return 0;
}
static int iwl_nvm_read_section(struct iwl_mvm *mvm, u16 section,
u8 *data, u32 size_read)
{
u16 length, offset = 0;
int ret;
length = IWL_NVM_DEFAULT_CHUNK_SIZE;
ret = length;
while (ret == length) {
if ((size_read + offset + length) >
mvm->cfg->base_params->eeprom_size) {
IWL_ERR(mvm, "EEPROM size is too small for NVM\n");
return -ENOBUFS;
}
ret = iwl_nvm_read_chunk(mvm, section, offset, length, data);
if (ret < 0) {
IWL_DEBUG_EEPROM(mvm->trans->dev,
"Cannot read NVM from section %d offset %d, length %d\n",
section, offset, length);
return ret;
}
offset += ret;
}
IWL_DEBUG_EEPROM(mvm->trans->dev,
"NVM section %d read completed\n", section);
return offset;
}
static struct iwl_nvm_data *
iwl_parse_nvm_sections(struct iwl_mvm *mvm)
{
struct iwl_nvm_section *sections = mvm->nvm_sections;
const __le16 *hw, *sw, *calib, *regulatory, *mac_override, *phy_sku;
bool lar_enabled;
u32 mac_addr0, mac_addr1;
if (mvm->trans->cfg->device_family != IWL_DEVICE_FAMILY_8000) {
if (!mvm->nvm_sections[NVM_SECTION_TYPE_SW].data ||
!mvm->nvm_sections[mvm->cfg->nvm_hw_section_num].data) {
IWL_ERR(mvm, "Can't parse empty OTP/NVM sections\n");
return NULL;
}
} else {
if (!mvm->nvm_sections[NVM_SECTION_TYPE_SW].data ||
!mvm->nvm_sections[NVM_SECTION_TYPE_REGULATORY].data) {
IWL_ERR(mvm,
"Can't parse empty family 8000 OTP/NVM sections\n");
return NULL;
}
if (!mvm->nvm_sections[mvm->cfg->nvm_hw_section_num].data &&
!mvm->nvm_sections[NVM_SECTION_TYPE_MAC_OVERRIDE].data) {
IWL_ERR(mvm,
"Can't parse mac_address, empty sections\n");
return NULL;
}
if (!mvm->nvm_sections[NVM_SECTION_TYPE_PHY_SKU].data) {
IWL_ERR(mvm,
"Can't parse phy_sku in B0, empty sections\n");
return NULL;
}
}
if (WARN_ON(!mvm->cfg))
return NULL;
mac_addr0 = iwl_trans_read_prph(mvm->trans, WFMP_MAC_ADDR_0);
mac_addr1 = iwl_trans_read_prph(mvm->trans, WFMP_MAC_ADDR_1);
hw = (const __le16 *)sections[mvm->cfg->nvm_hw_section_num].data;
sw = (const __le16 *)sections[NVM_SECTION_TYPE_SW].data;
calib = (const __le16 *)sections[NVM_SECTION_TYPE_CALIBRATION].data;
regulatory = (const __le16 *)sections[NVM_SECTION_TYPE_REGULATORY].data;
mac_override =
(const __le16 *)sections[NVM_SECTION_TYPE_MAC_OVERRIDE].data;
phy_sku = (const __le16 *)sections[NVM_SECTION_TYPE_PHY_SKU].data;
lar_enabled = !iwlwifi_mod_params.lar_disable &&
fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_LAR_SUPPORT);
return iwl_parse_nvm_data(mvm->trans->dev, mvm->cfg, hw, sw, calib,
regulatory, mac_override, phy_sku,
mvm->fw->valid_tx_ant, mvm->fw->valid_rx_ant,
lar_enabled, mac_addr0, mac_addr1);
}
static int iwl_mvm_read_external_nvm(struct iwl_mvm *mvm)
{
int ret, section_size;
u16 section_id;
const struct firmware *fw_entry;
const struct {
__le16 word1;
__le16 word2;
u8 data[];
} *file_sec;
const u8 *eof, *temp;
int max_section_size;
const __le32 *dword_buff;
#define NVM_WORD1_LEN(x) (8 * (x & 0x03FF))
#define NVM_WORD2_ID(x) (x >> 12)
#define NVM_WORD2_LEN_FAMILY_8000(x) (2 * ((x & 0xFF) << 8 | x >> 8))
#define NVM_WORD1_ID_FAMILY_8000(x) (x >> 4)
#define NVM_HEADER_0 (0x2A504C54)
#define NVM_HEADER_1 (0x4E564D2A)
#define NVM_HEADER_SIZE (4 * sizeof(u32))
IWL_DEBUG_EEPROM(mvm->trans->dev, "Read from external NVM\n");
if (mvm->trans->cfg->device_family != IWL_DEVICE_FAMILY_8000)
max_section_size = IWL_MAX_NVM_SECTION_SIZE;
else
max_section_size = IWL_MAX_NVM_8000_SECTION_SIZE;
ret = request_firmware(&fw_entry, mvm->nvm_file_name,
mvm->trans->dev);
if (ret) {
IWL_ERR(mvm, "ERROR: %s isn't available %d\n",
mvm->nvm_file_name, ret);
return ret;
}
IWL_INFO(mvm, "Loaded NVM file %s (%zu bytes)\n",
mvm->nvm_file_name, fw_entry->size);
if (fw_entry->size > MAX_NVM_FILE_LEN) {
IWL_ERR(mvm, "NVM file too large\n");
ret = -EINVAL;
goto out;
}
eof = fw_entry->data + fw_entry->size;
dword_buff = (__le32 *)fw_entry->data;
if (fw_entry->size > NVM_HEADER_SIZE &&
dword_buff[0] == cpu_to_le32(NVM_HEADER_0) &&
dword_buff[1] == cpu_to_le32(NVM_HEADER_1)) {
file_sec = (void *)(fw_entry->data + NVM_HEADER_SIZE);
IWL_INFO(mvm, "NVM Version %08X\n", le32_to_cpu(dword_buff[2]));
IWL_INFO(mvm, "NVM Manufacturing date %08X\n",
le32_to_cpu(dword_buff[3]));
if ((CSR_HW_REV_STEP(mvm->trans->hw_rev) == SILICON_C_STEP &&
le32_to_cpu(dword_buff[2]) < 0xE4A) ||
(CSR_HW_REV_STEP(mvm->trans->hw_rev) == SILICON_B_STEP &&
le32_to_cpu(dword_buff[2]) >= 0xE4A)) {
ret = -EFAULT;
goto out;
}
} else {
file_sec = (void *)fw_entry->data;
}
while (true) {
if (file_sec->data > eof) {
IWL_ERR(mvm,
"ERROR - NVM file too short for section header\n");
ret = -EINVAL;
break;
}
if (!file_sec->word1 && !file_sec->word2) {
ret = 0;
break;
}
if (mvm->trans->cfg->device_family != IWL_DEVICE_FAMILY_8000) {
section_size =
2 * NVM_WORD1_LEN(le16_to_cpu(file_sec->word1));
section_id = NVM_WORD2_ID(le16_to_cpu(file_sec->word2));
} else {
section_size = 2 * NVM_WORD2_LEN_FAMILY_8000(
le16_to_cpu(file_sec->word2));
section_id = NVM_WORD1_ID_FAMILY_8000(
le16_to_cpu(file_sec->word1));
}
if (section_size > max_section_size) {
IWL_ERR(mvm, "ERROR - section too large (%d)\n",
section_size);
ret = -EINVAL;
break;
}
if (!section_size) {
IWL_ERR(mvm, "ERROR - section empty\n");
ret = -EINVAL;
break;
}
if (file_sec->data + section_size > eof) {
IWL_ERR(mvm,
"ERROR - NVM file too short for section (%d bytes)\n",
section_size);
ret = -EINVAL;
break;
}
if (WARN(section_id >= NVM_MAX_NUM_SECTIONS,
"Invalid NVM section ID %d\n", section_id)) {
ret = -EINVAL;
break;
}
temp = kmemdup(file_sec->data, section_size, GFP_KERNEL);
if (!temp) {
ret = -ENOMEM;
break;
}
mvm->nvm_sections[section_id].data = temp;
mvm->nvm_sections[section_id].length = section_size;
file_sec = (void *)(file_sec->data + section_size);
}
out:
release_firmware(fw_entry);
return ret;
}
int iwl_mvm_load_nvm_to_nic(struct iwl_mvm *mvm)
{
int i, ret = 0;
struct iwl_nvm_section *sections = mvm->nvm_sections;
IWL_DEBUG_EEPROM(mvm->trans->dev, "'Write to NVM\n");
for (i = 0; i < ARRAY_SIZE(mvm->nvm_sections); i++) {
if (!mvm->nvm_sections[i].data || !mvm->nvm_sections[i].length)
continue;
ret = iwl_nvm_write_section(mvm, i, sections[i].data,
sections[i].length);
if (ret < 0) {
IWL_ERR(mvm, "iwl_mvm_send_cmd failed: %d\n", ret);
break;
}
}
return ret;
}
int iwl_nvm_init(struct iwl_mvm *mvm, bool read_nvm_from_nic)
{
int ret, section;
u32 size_read = 0;
u8 *nvm_buffer, *temp;
const char *nvm_file_B = mvm->cfg->default_nvm_file_B_step;
const char *nvm_file_C = mvm->cfg->default_nvm_file_C_step;
if (WARN_ON_ONCE(mvm->cfg->nvm_hw_section_num >= NVM_MAX_NUM_SECTIONS))
return -EINVAL;
if (read_nvm_from_nic) {
IWL_DEBUG_EEPROM(mvm->trans->dev, "Read from NVM\n");
nvm_buffer = kmalloc(mvm->cfg->base_params->eeprom_size,
GFP_KERNEL);
if (!nvm_buffer)
return -ENOMEM;
for (section = 0; section < NVM_MAX_NUM_SECTIONS; section++) {
ret = iwl_nvm_read_section(mvm, section, nvm_buffer,
size_read);
if (ret < 0)
continue;
size_read += ret;
temp = kmemdup(nvm_buffer, ret, GFP_KERNEL);
if (!temp) {
ret = -ENOMEM;
break;
}
mvm->nvm_sections[section].data = temp;
mvm->nvm_sections[section].length = ret;
#ifdef CONFIG_IWLWIFI_DEBUGFS
switch (section) {
case NVM_SECTION_TYPE_SW:
mvm->nvm_sw_blob.data = temp;
mvm->nvm_sw_blob.size = ret;
break;
case NVM_SECTION_TYPE_CALIBRATION:
mvm->nvm_calib_blob.data = temp;
mvm->nvm_calib_blob.size = ret;
break;
case NVM_SECTION_TYPE_PRODUCTION:
mvm->nvm_prod_blob.data = temp;
mvm->nvm_prod_blob.size = ret;
break;
default:
if (section == mvm->cfg->nvm_hw_section_num) {
mvm->nvm_hw_blob.data = temp;
mvm->nvm_hw_blob.size = ret;
break;
}
}
#endif
}
if (!size_read)
IWL_ERR(mvm, "OTP is blank\n");
kfree(nvm_buffer);
}
if (mvm->nvm_file_name) {
ret = iwl_mvm_read_external_nvm(mvm);
if (ret) {
if (CSR_HW_REV_STEP(mvm->trans->hw_rev) ==
SILICON_B_STEP)
mvm->nvm_file_name = nvm_file_B;
else
mvm->nvm_file_name = nvm_file_C;
if (ret == -EFAULT && mvm->nvm_file_name) {
ret = iwl_mvm_read_external_nvm(mvm);
if (ret)
return ret;
} else {
return ret;
}
}
}
mvm->nvm_data = iwl_parse_nvm_sections(mvm);
if (!mvm->nvm_data)
return -ENODATA;
IWL_DEBUG_EEPROM(mvm->trans->dev, "nvm version = %x\n",
mvm->nvm_data->nvm_version);
return 0;
}
struct iwl_mcc_update_resp *
iwl_mvm_update_mcc(struct iwl_mvm *mvm, const char *alpha2,
enum iwl_mcc_source src_id)
{
struct iwl_mcc_update_cmd mcc_update_cmd = {
.mcc = cpu_to_le16(alpha2[0] << 8 | alpha2[1]),
.source_id = (u8)src_id,
};
struct iwl_mcc_update_resp *mcc_resp, *resp_cp = NULL;
struct iwl_rx_packet *pkt;
struct iwl_host_cmd cmd = {
.id = MCC_UPDATE_CMD,
.flags = CMD_WANT_SKB,
.data = { &mcc_update_cmd },
};
int ret;
u32 status;
int resp_len, n_channels;
u16 mcc;
if (WARN_ON_ONCE(!iwl_mvm_is_lar_supported(mvm)))
return ERR_PTR(-EOPNOTSUPP);
cmd.len[0] = sizeof(struct iwl_mcc_update_cmd);
IWL_DEBUG_LAR(mvm, "send MCC update to FW with '%c%c' src = %d\n",
alpha2[0], alpha2[1], src_id);
ret = iwl_mvm_send_cmd(mvm, &cmd);
if (ret)
return ERR_PTR(ret);
pkt = cmd.resp_pkt;
mcc_resp = (void *)pkt->data;
status = le32_to_cpu(mcc_resp->status);
mcc = le16_to_cpu(mcc_resp->mcc);
if (mcc == 0) {
mcc = 0x3030;
mcc_resp->mcc = cpu_to_le16(mcc);
}
n_channels = __le32_to_cpu(mcc_resp->n_channels);
IWL_DEBUG_LAR(mvm,
"MCC response status: 0x%x. new MCC: 0x%x ('%c%c') change: %d n_chans: %d\n",
status, mcc, mcc >> 8, mcc & 0xff,
!!(status == MCC_RESP_NEW_CHAN_PROFILE), n_channels);
resp_len = sizeof(*mcc_resp) + n_channels * sizeof(__le32);
resp_cp = kmemdup(mcc_resp, resp_len, GFP_KERNEL);
if (!resp_cp) {
ret = -ENOMEM;
goto exit;
}
ret = 0;
exit:
iwl_free_resp(&cmd);
if (ret)
return ERR_PTR(ret);
return resp_cp;
}
static u32 iwl_mvm_wrdd_get_mcc(struct iwl_mvm *mvm, union acpi_object *wrdd)
{
union acpi_object *mcc_pkg, *domain_type, *mcc_value;
u32 i;
if (wrdd->type != ACPI_TYPE_PACKAGE ||
wrdd->package.count < 2 ||
wrdd->package.elements[0].type != ACPI_TYPE_INTEGER ||
wrdd->package.elements[0].integer.value != 0) {
IWL_DEBUG_LAR(mvm, "Unsupported wrdd structure\n");
return 0;
}
for (i = 1 ; i < wrdd->package.count ; ++i) {
mcc_pkg = &wrdd->package.elements[i];
if (mcc_pkg->type != ACPI_TYPE_PACKAGE ||
mcc_pkg->package.count < 2 ||
mcc_pkg->package.elements[0].type != ACPI_TYPE_INTEGER ||
mcc_pkg->package.elements[1].type != ACPI_TYPE_INTEGER) {
mcc_pkg = NULL;
continue;
}
domain_type = &mcc_pkg->package.elements[0];
if (domain_type->integer.value == WRDD_WIFI)
break;
mcc_pkg = NULL;
}
if (mcc_pkg) {
mcc_value = &mcc_pkg->package.elements[1];
return mcc_value->integer.value;
}
return 0;
}
static int iwl_mvm_get_bios_mcc(struct iwl_mvm *mvm, char *mcc)
{
acpi_handle root_handle;
acpi_handle handle;
struct acpi_buffer wrdd = {ACPI_ALLOCATE_BUFFER, NULL};
acpi_status status;
u32 mcc_val;
struct pci_dev *pdev = to_pci_dev(mvm->dev);
root_handle = ACPI_HANDLE(&pdev->dev);
if (!root_handle) {
IWL_DEBUG_LAR(mvm,
"Could not retrieve root port ACPI handle\n");
return -ENOENT;
}
status = acpi_get_handle(root_handle, (acpi_string)WRD_METHOD, &handle);
if (ACPI_FAILURE(status)) {
IWL_DEBUG_LAR(mvm, "WRD method not found\n");
return -ENOENT;
}
status = acpi_evaluate_object(handle, NULL, NULL, &wrdd);
if (ACPI_FAILURE(status)) {
IWL_DEBUG_LAR(mvm, "WRDC invocation failed (0x%x)\n", status);
return -ENOENT;
}
mcc_val = iwl_mvm_wrdd_get_mcc(mvm, wrdd.pointer);
kfree(wrdd.pointer);
if (!mcc_val)
return -ENOENT;
mcc[0] = (mcc_val >> 8) & 0xff;
mcc[1] = mcc_val & 0xff;
mcc[2] = '\0';
return 0;
}
static int iwl_mvm_get_bios_mcc(struct iwl_mvm *mvm, char *mcc)
{
return -ENOENT;
}
int iwl_mvm_init_mcc(struct iwl_mvm *mvm)
{
bool tlv_lar;
bool nvm_lar;
int retval;
struct ieee80211_regdomain *regd;
char mcc[3];
if (mvm->cfg->device_family == IWL_DEVICE_FAMILY_8000) {
tlv_lar = fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_LAR_SUPPORT);
nvm_lar = mvm->nvm_data->lar_enabled;
if (tlv_lar != nvm_lar)
IWL_INFO(mvm,
"Conflict between TLV & NVM regarding enabling LAR (TLV = %s NVM =%s)\n",
tlv_lar ? "enabled" : "disabled",
nvm_lar ? "enabled" : "disabled");
}
if (!iwl_mvm_is_lar_supported(mvm))
return 0;
retval = iwl_mvm_init_fw_regd(mvm);
if (retval != -ENOENT)
return retval;
mvm->lar_regdom_set = false;
regd = iwl_mvm_get_current_regdomain(mvm, NULL);
if (IS_ERR_OR_NULL(regd))
return -EIO;
if (iwl_mvm_is_wifi_mcc_supported(mvm) &&
!iwl_mvm_get_bios_mcc(mvm, mcc)) {
kfree(regd);
regd = iwl_mvm_get_regdomain(mvm->hw->wiphy, mcc,
MCC_SOURCE_BIOS, NULL);
if (IS_ERR_OR_NULL(regd))
return -EIO;
}
retval = regulatory_set_wiphy_regd_sync_rtnl(mvm->hw->wiphy, regd);
kfree(regd);
return retval;
}
void iwl_mvm_rx_chub_update_mcc(struct iwl_mvm *mvm,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_mcc_chub_notif *notif = (void *)pkt->data;
enum iwl_mcc_source src;
char mcc[3];
struct ieee80211_regdomain *regd;
lockdep_assert_held(&mvm->mutex);
if (WARN_ON_ONCE(!iwl_mvm_is_lar_supported(mvm)))
return;
mcc[0] = notif->mcc >> 8;
mcc[1] = notif->mcc & 0xff;
mcc[2] = '\0';
src = notif->source_id;
IWL_DEBUG_LAR(mvm,
"RX: received chub update mcc cmd (mcc '%s' src %d)\n",
mcc, src);
regd = iwl_mvm_get_regdomain(mvm->hw->wiphy, mcc, src, NULL);
if (IS_ERR_OR_NULL(regd))
return;
regulatory_set_wiphy_regd(mvm->hw->wiphy, regd);
kfree(regd);
}
