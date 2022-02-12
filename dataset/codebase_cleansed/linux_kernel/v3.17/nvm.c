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
if (pkt->hdr.flags & IWL_CMD_FAILED_MSK) {
IWL_ERR(mvm, "Bad return from NVM_ACCES_COMMAND (0x%08X)\n",
pkt->hdr.flags);
ret = -EIO;
goto exit;
}
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
const __le16 *hw, *sw, *calib, *regulatory, *mac_override;
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
}
if (WARN_ON(!mvm->cfg))
return NULL;
hw = (const __le16 *)sections[mvm->cfg->nvm_hw_section_num].data;
sw = (const __le16 *)sections[NVM_SECTION_TYPE_SW].data;
calib = (const __le16 *)sections[NVM_SECTION_TYPE_CALIBRATION].data;
regulatory = (const __le16 *)sections[NVM_SECTION_TYPE_REGULATORY].data;
mac_override =
(const __le16 *)sections[NVM_SECTION_TYPE_MAC_OVERRIDE].data;
return iwl_parse_nvm_data(mvm->trans->dev, mvm->cfg, hw, sw, calib,
regulatory, mac_override,
mvm->fw->valid_tx_ant,
mvm->fw->valid_rx_ant);
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
#define NVM_WORD1_LEN(x) (8 * (x & 0x03FF))
#define NVM_WORD2_ID(x) (x >> 12)
#define NVM_WORD2_LEN_FAMILY_8000(x) (2 * ((x & 0xFF) << 8 | x >> 8))
#define NVM_WORD1_ID_FAMILY_8000(x) (x >> 4)
IWL_DEBUG_EEPROM(mvm->trans->dev, "Read from external NVM\n");
if (mvm->trans->cfg->device_family != IWL_DEVICE_FAMILY_8000)
max_section_size = IWL_MAX_NVM_SECTION_SIZE;
else if ((mvm->trans->hw_rev & 0xc) == 0)
max_section_size = IWL_MAX_NVM_8000A_SECTION_SIZE;
else
max_section_size = IWL_MAX_NVM_8000B_SECTION_SIZE;
ret = request_firmware(&fw_entry, mvm->nvm_file_name,
mvm->trans->dev);
if (ret) {
IWL_ERR(mvm, "ERROR: %s isn't available %d\n",
mvm->nvm_file_name, ret);
return ret;
}
IWL_INFO(mvm, "Loaded NVM file %s (%zu bytes)\n",
mvm->nvm_file_name, fw_entry->size);
if (fw_entry->size < sizeof(*file_sec)) {
IWL_ERR(mvm, "NVM file too small\n");
ret = -EINVAL;
goto out;
}
if (fw_entry->size > MAX_NVM_FILE_LEN) {
IWL_ERR(mvm, "NVM file too large\n");
ret = -EINVAL;
goto out;
}
eof = fw_entry->data + fw_entry->size;
file_sec = (void *)fw_entry->data;
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
if (ret)
return ret;
}
mvm->nvm_data = iwl_parse_nvm_sections(mvm);
if (!mvm->nvm_data)
return -ENODATA;
return 0;
}
