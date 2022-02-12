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
.flags = CMD_WANT_SKB | CMD_SEND_IN_RFKILL,
.data = { &nvm_access_cmd, data },
.dataflags = { 0, IWL_HCMD_DFL_DUP },
};
struct iwl_rx_packet *pkt;
struct iwl_nvm_access_resp *nvm_resp;
int ret;
ret = iwl_mvm_send_cmd(mvm, &cmd);
if (ret)
return ret;
pkt = cmd.resp_pkt;
nvm_resp = (void *)pkt->data;
if (le16_to_cpu(nvm_resp->status) != READ_NVM_CHUNK_SUCCEED) {
IWL_ERR(mvm,
"NVM access write command failed for section %u (status = 0x%x)\n",
section, le16_to_cpu(nvm_resp->status));
ret = -EIO;
}
iwl_free_resp(&cmd);
return ret;
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
static void iwl_mvm_nvm_fixups(struct iwl_mvm *mvm, unsigned int section,
u8 *data, unsigned int len)
{
#define IWL_4165_DEVICE_ID 0x5501
#define NVM_SKU_CAP_MIMO_DISABLE BIT(5)
if (section == NVM_SECTION_TYPE_PHY_SKU &&
mvm->trans->hw_id == IWL_4165_DEVICE_ID && data && len >= 5 &&
(data[4] & NVM_SKU_CAP_MIMO_DISABLE))
data[3] = ANT_B | (ANT_B << 4);
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
iwl_mvm_nvm_fixups(mvm, section, data, offset);
IWL_DEBUG_EEPROM(mvm->trans->dev,
"NVM section %d read completed\n", section);
return offset;
}
static struct iwl_nvm_data *
iwl_parse_nvm_sections(struct iwl_mvm *mvm)
{
struct iwl_nvm_section *sections = mvm->nvm_sections;
const __be16 *hw;
const __le16 *sw, *calib, *regulatory, *mac_override, *phy_sku;
bool lar_enabled;
int regulatory_type;
if (mvm->trans->cfg->nvm_type != IWL_NVM_EXT) {
if (!mvm->nvm_sections[NVM_SECTION_TYPE_SW].data ||
!mvm->nvm_sections[mvm->cfg->nvm_hw_section_num].data) {
IWL_ERR(mvm, "Can't parse empty OTP/NVM sections\n");
return NULL;
}
} else {
if (mvm->trans->cfg->nvm_type == IWL_NVM_SDP)
regulatory_type = NVM_SECTION_TYPE_REGULATORY_SDP;
else
regulatory_type = NVM_SECTION_TYPE_REGULATORY;
if (!mvm->nvm_sections[NVM_SECTION_TYPE_SW].data ||
!mvm->nvm_sections[regulatory_type].data) {
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
hw = (const __be16 *)sections[mvm->cfg->nvm_hw_section_num].data;
sw = (const __le16 *)sections[NVM_SECTION_TYPE_SW].data;
calib = (const __le16 *)sections[NVM_SECTION_TYPE_CALIBRATION].data;
mac_override =
(const __le16 *)sections[NVM_SECTION_TYPE_MAC_OVERRIDE].data;
phy_sku = (const __le16 *)sections[NVM_SECTION_TYPE_PHY_SKU].data;
regulatory = mvm->trans->cfg->nvm_type == IWL_NVM_SDP ?
(const __le16 *)sections[NVM_SECTION_TYPE_REGULATORY_SDP].data :
(const __le16 *)sections[NVM_SECTION_TYPE_REGULATORY].data;
lar_enabled = !iwlwifi_mod_params.lar_disable &&
fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_LAR_SUPPORT);
return iwl_parse_nvm_data(mvm->trans, mvm->cfg, hw, sw, calib,
regulatory, mac_override, phy_sku,
mvm->fw->valid_tx_ant, mvm->fw->valid_rx_ant,
lar_enabled);
}
int iwl_mvm_read_external_nvm(struct iwl_mvm *mvm)
{
int ret, section_size;
u16 section_id;
const struct firmware *fw_entry;
const struct {
__le16 word1;
__le16 word2;
u8 data[];
} *file_sec;
const u8 *eof;
u8 *temp;
int max_section_size;
const __le32 *dword_buff;
#define NVM_WORD1_LEN(x) (8 * (x & 0x03FF))
#define NVM_WORD2_ID(x) (x >> 12)
#define EXT_NVM_WORD2_LEN(x) (2 * (((x) & 0xFF) << 8 | (x) >> 8))
#define EXT_NVM_WORD1_ID(x) ((x) >> 4)
#define NVM_HEADER_0 (0x2A504C54)
#define NVM_HEADER_1 (0x4E564D2A)
#define NVM_HEADER_SIZE (4 * sizeof(u32))
IWL_DEBUG_EEPROM(mvm->trans->dev, "Read from external NVM\n");
if (mvm->trans->cfg->nvm_type != IWL_NVM_EXT)
max_section_size = IWL_MAX_NVM_SECTION_SIZE;
else
max_section_size = IWL_MAX_EXT_NVM_SECTION_SIZE;
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
if (mvm->trans->cfg->device_family == IWL_DEVICE_FAMILY_8000 &&
CSR_HW_REV_STEP(mvm->trans->hw_rev) == SILICON_C_STEP &&
le32_to_cpu(dword_buff[2]) < 0xE4A) {
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
if (mvm->trans->cfg->nvm_type != IWL_NVM_EXT) {
section_size =
2 * NVM_WORD1_LEN(le16_to_cpu(file_sec->word1));
section_id = NVM_WORD2_ID(le16_to_cpu(file_sec->word2));
} else {
section_size = 2 * EXT_NVM_WORD2_LEN(
le16_to_cpu(file_sec->word2));
section_id = EXT_NVM_WORD1_ID(
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
iwl_mvm_nvm_fixups(mvm, section_id, temp, section_size);
kfree(mvm->nvm_sections[section_id].data);
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
int iwl_nvm_init(struct iwl_mvm *mvm)
{
int ret, section;
u32 size_read = 0;
u8 *nvm_buffer, *temp;
const char *nvm_file_C = mvm->cfg->default_nvm_file_C_step;
if (WARN_ON_ONCE(mvm->cfg->nvm_hw_section_num >= NVM_MAX_NUM_SECTIONS))
return -EINVAL;
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
iwl_mvm_nvm_fixups(mvm, section, temp, ret);
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
case NVM_SECTION_TYPE_PHY_SKU:
mvm->nvm_phy_sku_blob.data = temp;
mvm->nvm_phy_sku_blob.size = ret;
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
if (mvm->nvm_file_name) {
ret = iwl_mvm_read_external_nvm(mvm);
if (ret) {
mvm->nvm_file_name = nvm_file_C;
if ((ret == -EFAULT || ret == -ENOENT) &&
mvm->nvm_file_name) {
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
struct iwl_mcc_update_resp *resp_cp;
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
bool resp_v2 = fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_LAR_SUPPORT_V2);
if (WARN_ON_ONCE(!iwl_mvm_is_lar_supported(mvm)))
return ERR_PTR(-EOPNOTSUPP);
cmd.len[0] = sizeof(struct iwl_mcc_update_cmd);
if (!resp_v2)
cmd.len[0] = sizeof(struct iwl_mcc_update_cmd_v1);
IWL_DEBUG_LAR(mvm, "send MCC update to FW with '%c%c' src = %d\n",
alpha2[0], alpha2[1], src_id);
ret = iwl_mvm_send_cmd(mvm, &cmd);
if (ret)
return ERR_PTR(ret);
pkt = cmd.resp_pkt;
if (resp_v2) {
struct iwl_mcc_update_resp *mcc_resp = (void *)pkt->data;
n_channels = __le32_to_cpu(mcc_resp->n_channels);
resp_len = sizeof(struct iwl_mcc_update_resp) +
n_channels * sizeof(__le32);
resp_cp = kmemdup(mcc_resp, resp_len, GFP_KERNEL);
if (!resp_cp) {
resp_cp = ERR_PTR(-ENOMEM);
goto exit;
}
} else {
struct iwl_mcc_update_resp_v1 *mcc_resp_v1 = (void *)pkt->data;
n_channels = __le32_to_cpu(mcc_resp_v1->n_channels);
resp_len = sizeof(struct iwl_mcc_update_resp) +
n_channels * sizeof(__le32);
resp_cp = kzalloc(resp_len, GFP_KERNEL);
if (!resp_cp) {
resp_cp = ERR_PTR(-ENOMEM);
goto exit;
}
resp_cp->status = mcc_resp_v1->status;
resp_cp->mcc = mcc_resp_v1->mcc;
resp_cp->cap = mcc_resp_v1->cap;
resp_cp->source_id = mcc_resp_v1->source_id;
resp_cp->n_channels = mcc_resp_v1->n_channels;
memcpy(resp_cp->channels, mcc_resp_v1->channels,
n_channels * sizeof(__le32));
}
status = le32_to_cpu(resp_cp->status);
mcc = le16_to_cpu(resp_cp->mcc);
if (mcc == 0) {
mcc = 0x3030;
resp_cp->mcc = cpu_to_le16(mcc);
}
IWL_DEBUG_LAR(mvm,
"MCC response status: 0x%x. new MCC: 0x%x ('%c%c') change: %d n_chans: %d\n",
status, mcc, mcc >> 8, mcc & 0xff,
!!(status == MCC_RESP_NEW_CHAN_PROFILE), n_channels);
exit:
iwl_free_resp(&cmd);
return resp_cp;
}
int iwl_mvm_init_mcc(struct iwl_mvm *mvm)
{
bool tlv_lar;
bool nvm_lar;
int retval;
struct ieee80211_regdomain *regd;
char mcc[3];
if (mvm->cfg->nvm_type == IWL_NVM_EXT) {
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
!iwl_get_bios_mcc(mvm->dev, mcc)) {
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
if (iwl_mvm_is_vif_assoc(mvm) && notif->source_id == MCC_SOURCE_WIFI) {
IWL_DEBUG_LAR(mvm, "Ignore mcc update while associated\n");
return;
}
if (WARN_ON_ONCE(!iwl_mvm_is_lar_supported(mvm)))
return;
mcc[0] = le16_to_cpu(notif->mcc) >> 8;
mcc[1] = le16_to_cpu(notif->mcc) & 0xff;
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
