int snd_skl_get_module_info(struct skl_sst *ctx, u8 *uuid,
struct skl_dfw_module *dfw_config)
{
struct uuid_module *module;
uuid_le *uuid_mod;
uuid_mod = (uuid_le *)uuid;
if (list_empty(&ctx->uuid_list)) {
dev_err(ctx->dev, "Module list is empty\n");
return -EINVAL;
}
list_for_each_entry(module, &ctx->uuid_list, list) {
if (uuid_le_cmp(*uuid_mod, module->uuid) == 0) {
dfw_config->module_id = module->id;
dfw_config->is_loadable = module->is_loadable;
return 0;
}
}
return -EINVAL;
}
int snd_skl_parse_uuids(struct sst_dsp *ctx, unsigned int offset)
{
struct adsp_fw_hdr *adsp_hdr;
struct adsp_module_entry *mod_entry;
int i, num_entry;
uuid_le *uuid_bin;
const char *buf;
struct skl_sst *skl = ctx->thread_context;
struct uuid_module *module;
struct firmware stripped_fw;
unsigned int safe_file;
stripped_fw.data = ctx->fw->data;
stripped_fw.size = ctx->fw->size;
skl_dsp_strip_extended_manifest(&stripped_fw);
buf = stripped_fw.data;
safe_file = sizeof(*adsp_hdr) + offset;
if (stripped_fw.size <= safe_file) {
dev_err(ctx->dev, "Small fw file size, No space for hdr\n");
return -EINVAL;
}
adsp_hdr = (struct adsp_fw_hdr *)(buf + offset);
safe_file += adsp_hdr->len + sizeof(*mod_entry);
if (stripped_fw.size <= safe_file) {
dev_err(ctx->dev, "Small fw file size, No module entry\n");
return -EINVAL;
}
mod_entry = (struct adsp_module_entry *)
(buf + offset + adsp_hdr->len);
num_entry = adsp_hdr->num_modules;
safe_file += num_entry * sizeof(*mod_entry);
if (stripped_fw.size <= safe_file) {
dev_err(ctx->dev, "Small fw file size, No modules\n");
return -EINVAL;
}
for (i = 0; i < num_entry; i++, mod_entry++) {
module = kzalloc(sizeof(*module), GFP_KERNEL);
if (!module)
return -ENOMEM;
uuid_bin = (uuid_le *)mod_entry->uuid.id;
memcpy(&module->uuid, uuid_bin, sizeof(module->uuid));
module->id = i;
module->is_loadable = mod_entry->type.load_type;
list_add_tail(&module->list, &skl->uuid_list);
dev_dbg(ctx->dev,
"Adding uuid :%pUL mod id: %d Loadable: %d\n",
&module->uuid, module->id, module->is_loadable);
}
return 0;
}
void skl_freeup_uuid_list(struct skl_sst *ctx)
{
struct uuid_module *uuid, *_uuid;
list_for_each_entry_safe(uuid, _uuid, &ctx->uuid_list, list) {
list_del(&uuid->list);
kfree(uuid);
}
}
int skl_dsp_strip_extended_manifest(struct firmware *fw)
{
struct skl_ext_manifest_hdr *hdr;
if (fw->size < sizeof(hdr)) {
pr_err("%s: Firmware file small, no hdr\n", __func__);
return -EINVAL;
}
hdr = (struct skl_ext_manifest_hdr *)fw->data;
if (hdr->id == SKL_EXT_MANIFEST_HEADER_MAGIC) {
fw->size -= hdr->len;
fw->data += hdr->len;
}
return 0;
}
