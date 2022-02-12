char *sh_css_get_fw_version(void)
{
return FW_rel_ver_name;
}
static enum ia_css_err
setup_binary(struct ia_css_fw_info *fw, const char *fw_data, struct ia_css_fw_info *sh_css_fw, unsigned binary_id)
{
const char *blob_data;
if ((fw == NULL) || (fw_data == NULL))
return IA_CSS_ERR_INVALID_ARGUMENTS;
blob_data = fw_data + fw->blob.offset;
*sh_css_fw = *fw;
sh_css_fw->blob.code = vmalloc(fw->blob.size);
if (sh_css_fw->blob.code == NULL)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
memcpy((void *)sh_css_fw->blob.code, blob_data, fw->blob.size);
sh_css_fw->blob.data = (char *)sh_css_fw->blob.code + fw->blob.data_source;
fw_minibuffer[binary_id].buffer = sh_css_fw->blob.code;
return IA_CSS_SUCCESS;
}
enum ia_css_err
sh_css_load_blob_info(const char *fw, const struct ia_css_fw_info *bi, struct ia_css_blob_descr *bd, unsigned index)
{
const char *name;
const unsigned char *blob;
if ((fw == NULL) || (bd == NULL))
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (bi == NULL) bi = (const struct ia_css_fw_info *)fw;
name = fw + bi->blob.prog_name_offset;
blob = (const unsigned char *)fw + bi->blob.offset;
if (bi->blob.size != bi->blob.text_size + bi->blob.icache_size + bi->blob.data_size + bi->blob.padding_size) {
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if ((bi->blob.offset % (1UL<<(ISP_PMEM_WIDTH_LOG2-3))) != 0)
return IA_CSS_ERR_INVALID_ARGUMENTS;
bd->blob = blob;
bd->header = *bi;
if (bi->type == ia_css_isp_firmware || bi->type == ia_css_sp_firmware) {
char *namebuffer;
int namelength = (int)strlen(name);
namebuffer = (char *) kmalloc(namelength + 1, GFP_KERNEL);
if (namebuffer == NULL)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
memcpy(namebuffer, name, namelength + 1);
bd->name = fw_minibuffer[index].name = namebuffer;
} else {
bd->name = name;
}
if (bi->type == ia_css_isp_firmware) {
size_t paramstruct_size = sizeof(struct ia_css_memory_offsets);
size_t configstruct_size = sizeof(struct ia_css_config_memory_offsets);
size_t statestruct_size = sizeof(struct ia_css_state_memory_offsets);
char *parambuf = (char *)kmalloc(paramstruct_size + configstruct_size + statestruct_size,
GFP_KERNEL);
if (parambuf == NULL)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
bd->mem_offsets.array[IA_CSS_PARAM_CLASS_PARAM].ptr = NULL;
bd->mem_offsets.array[IA_CSS_PARAM_CLASS_CONFIG].ptr = NULL;
bd->mem_offsets.array[IA_CSS_PARAM_CLASS_STATE].ptr = NULL;
fw_minibuffer[index].buffer = parambuf;
memcpy(parambuf, (void *)(fw + bi->blob.memory_offsets.offsets[IA_CSS_PARAM_CLASS_PARAM]),
paramstruct_size);
bd->mem_offsets.array[IA_CSS_PARAM_CLASS_PARAM].ptr = parambuf;
memcpy(parambuf + paramstruct_size,
(void *)(fw + bi->blob.memory_offsets.offsets[IA_CSS_PARAM_CLASS_CONFIG]),
configstruct_size);
bd->mem_offsets.array[IA_CSS_PARAM_CLASS_CONFIG].ptr = parambuf + paramstruct_size;
memcpy(parambuf + paramstruct_size + configstruct_size,
(void *)(fw + bi->blob.memory_offsets.offsets[IA_CSS_PARAM_CLASS_STATE]),
statestruct_size);
bd->mem_offsets.array[IA_CSS_PARAM_CLASS_STATE].ptr = parambuf + paramstruct_size + configstruct_size;
}
return IA_CSS_SUCCESS;
}
bool
sh_css_check_firmware_version(const char *fw_data)
{
struct sh_css_fw_bi_file_h *file_header;
firmware_header = (struct firmware_header *)fw_data;
file_header = &firmware_header->file_header;
if (strcmp(file_header->version, release_version) != 0) {
return false;
} else {
return true;
}
}
enum ia_css_err
sh_css_load_firmware(const char *fw_data,
unsigned int fw_size)
{
unsigned i;
struct ia_css_fw_info *binaries;
struct sh_css_fw_bi_file_h *file_header;
bool valid_firmware = false;
firmware_header = (struct firmware_header *)fw_data;
file_header = &firmware_header->file_header;
binaries = &firmware_header->binary_header;
strncpy(FW_rel_ver_name, file_header->version, min(sizeof(FW_rel_ver_name), sizeof(file_header->version)) - 1);
valid_firmware = sh_css_check_firmware_version(fw_data);
if (!valid_firmware) {
#if !defined(HRT_RTL)
IA_CSS_ERROR("CSS code version (%s) and firmware version (%s) mismatch!",
file_header->version, release_version);
return IA_CSS_ERR_VERSION_MISMATCH;
#endif
} else {
IA_CSS_LOG("successfully load firmware version %s", release_version);
}
if (!fw_data || fw_size < sizeof(struct sh_css_fw_bi_file_h))
return IA_CSS_ERR_INTERNAL_ERROR;
if (file_header->h_size != sizeof(struct sh_css_fw_bi_file_h))
return IA_CSS_ERR_INTERNAL_ERROR;
sh_css_num_binaries = file_header->binary_nr;
if (sh_css_num_binaries > NUM_OF_SPS) {
sh_css_blob_info = kmalloc(
(sh_css_num_binaries - NUM_OF_SPS) *
sizeof(*sh_css_blob_info), GFP_KERNEL);
if (sh_css_blob_info == NULL)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
} else {
sh_css_blob_info = NULL;
}
fw_minibuffer = kzalloc(sh_css_num_binaries * sizeof(struct fw_param), GFP_KERNEL);
if (fw_minibuffer == NULL)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
for (i = 0; i < sh_css_num_binaries; i++) {
struct ia_css_fw_info *bi = &binaries[i];
static struct ia_css_blob_descr bd;
enum ia_css_err err;
err = sh_css_load_blob_info(fw_data, bi, &bd, i);
if (err != IA_CSS_SUCCESS)
return IA_CSS_ERR_INTERNAL_ERROR;
if (bi->blob.offset + bi->blob.size > fw_size)
return IA_CSS_ERR_INTERNAL_ERROR;
if (bi->type == ia_css_sp_firmware) {
if (i != SP_FIRMWARE)
return IA_CSS_ERR_INTERNAL_ERROR;
err = setup_binary(bi, fw_data, &sh_css_sp_fw, i);
if (err != IA_CSS_SUCCESS)
return err;
} else {
if (i < NUM_OF_SPS)
return IA_CSS_ERR_INTERNAL_ERROR;
if (bi->type != ia_css_isp_firmware)
return IA_CSS_ERR_INTERNAL_ERROR;
if (sh_css_blob_info == NULL)
return IA_CSS_ERR_INTERNAL_ERROR;
sh_css_blob_info[i - NUM_OF_SPS] = bd;
}
}
return IA_CSS_SUCCESS;
}
void sh_css_unload_firmware(void)
{
if (fw_minibuffer) {
unsigned int i = 0;
for (i = 0; i < sh_css_num_binaries; i++) {
if (fw_minibuffer[i].name)
kfree((void *)fw_minibuffer[i].name);
if (fw_minibuffer[i].buffer)
vfree((void *)fw_minibuffer[i].buffer);
}
kfree(fw_minibuffer);
fw_minibuffer = NULL;
}
memset(&sh_css_sp_fw, 0, sizeof(sh_css_sp_fw));
if (sh_css_blob_info) {
kfree(sh_css_blob_info);
sh_css_blob_info = NULL;
}
sh_css_num_binaries = 0;
}
hrt_vaddress
sh_css_load_blob(const unsigned char *blob, unsigned size)
{
hrt_vaddress target_addr = mmgr_malloc(size);
assert(blob != NULL);
if (target_addr)
mmgr_store(target_addr, blob, size);
return target_addr;
}
