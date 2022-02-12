static inline void iwl_nvm_fill_read(struct iwl_nvm_access_cmd *cmd,
u16 offset, u16 length, u16 section)
{
cmd->offset = cpu_to_le16(offset);
cmd->length = cpu_to_le16(length);
cmd->type = cpu_to_le16(section);
}
static int iwl_nvm_read_chunk(struct iwl_mvm *mvm, u16 section,
u16 offset, u16 length, u8 *data)
{
struct iwl_nvm_access_cmd nvm_access_cmd = {};
struct iwl_nvm_access_resp *nvm_resp;
struct iwl_rx_packet *pkt;
struct iwl_host_cmd cmd = {
.id = NVM_ACCESS_CMD,
.flags = CMD_SYNC | CMD_WANT_SKB,
.data = { &nvm_access_cmd, },
};
int ret, bytes_read, offset_read;
u8 *resp_data;
iwl_nvm_fill_read(&nvm_access_cmd, offset, length, section);
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
IWL_ERR(mvm,
"NVM access command failed with status %d (device: %s)\n",
ret, mvm->cfg->name);
ret = -EINVAL;
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
static int iwl_nvm_read_section(struct iwl_mvm *mvm, u16 section,
u8 *data)
{
u16 length, offset = 0;
int ret;
length = IWL_NVM_DEFAULT_CHUNK_SIZE;
ret = length;
while (ret == length) {
ret = iwl_nvm_read_chunk(mvm, section, offset, length, data);
if (ret < 0) {
IWL_ERR(mvm,
"Cannot read NVM from section %d offset %d, length %d\n",
section, offset, length);
return ret;
}
offset += ret;
}
IWL_INFO(mvm, "NVM section %d read completed\n", section);
return offset;
}
static struct iwl_nvm_data *
iwl_parse_nvm_sections(struct iwl_mvm *mvm)
{
struct iwl_nvm_section *sections = mvm->nvm_sections;
const __le16 *hw, *sw, *calib;
if (!mvm->nvm_sections[NVM_SECTION_TYPE_SW].data ||
!mvm->nvm_sections[NVM_SECTION_TYPE_HW].data) {
IWL_ERR(mvm, "Can't parse empty NVM sections\n");
return NULL;
}
if (WARN_ON(!mvm->cfg))
return NULL;
hw = (const __le16 *)sections[NVM_SECTION_TYPE_HW].data;
sw = (const __le16 *)sections[NVM_SECTION_TYPE_SW].data;
calib = (const __le16 *)sections[NVM_SECTION_TYPE_CALIBRATION].data;
return iwl_parse_nvm_data(mvm->trans->dev, mvm->cfg, hw, sw, calib);
}
int iwl_nvm_init(struct iwl_mvm *mvm)
{
int ret, i, section;
u8 *nvm_buffer, *temp;
nvm_buffer = kmalloc(mvm->cfg->base_params->eeprom_size,
GFP_KERNEL);
if (!nvm_buffer)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(nvm_to_read); i++) {
section = nvm_to_read[i];
ret = iwl_nvm_read_section(mvm, section, nvm_buffer);
if (ret < 0)
break;
temp = kmemdup(nvm_buffer, ret, GFP_KERNEL);
if (!temp) {
ret = -ENOMEM;
break;
}
mvm->nvm_sections[section].data = temp;
mvm->nvm_sections[section].length = ret;
}
kfree(nvm_buffer);
if (ret < 0)
return ret;
ret = 0;
mvm->nvm_data = iwl_parse_nvm_sections(mvm);
return ret;
}
