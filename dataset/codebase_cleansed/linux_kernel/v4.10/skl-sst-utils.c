int snd_skl_get_module_info(struct skl_sst *ctx,
struct skl_module_cfg *mconfig)
{
struct uuid_module *module;
uuid_le *uuid_mod;
uuid_mod = (uuid_le *)mconfig->guid;
if (list_empty(&ctx->uuid_list)) {
dev_err(ctx->dev, "Module list is empty\n");
return -EINVAL;
}
list_for_each_entry(module, &ctx->uuid_list, list) {
if (uuid_le_cmp(*uuid_mod, module->uuid) == 0) {
mconfig->id.module_id = module->id;
mconfig->is_loadable = module->is_loadable;
return 0;
}
}
return -EINVAL;
}
static int skl_get_pvtid_map(struct uuid_module *module, int instance_id)
{
int pvt_id;
for (pvt_id = 0; pvt_id < module->max_instance; pvt_id++) {
if (module->instance_id[pvt_id] == instance_id)
return pvt_id;
}
return -EINVAL;
}
int skl_get_pvt_instance_id_map(struct skl_sst *ctx,
int module_id, int instance_id)
{
struct uuid_module *module;
list_for_each_entry(module, &ctx->uuid_list, list) {
if (module->id == module_id)
return skl_get_pvtid_map(module, instance_id);
}
return -EINVAL;
}
static inline int skl_getid_32(struct uuid_module *module, u64 *val,
int word1_mask, int word2_mask)
{
int index, max_inst, pvt_id;
u32 mask_val;
max_inst = module->max_instance;
mask_val = (u32)(*val >> word1_mask);
if (mask_val != 0xffffffff) {
index = ffz(mask_val);
pvt_id = index + word1_mask + word2_mask;
if (pvt_id <= (max_inst - 1)) {
*val |= 1ULL << (index + word1_mask);
return pvt_id;
}
}
return -EINVAL;
}
static inline int skl_pvtid_128(struct uuid_module *module)
{
int j, i, word1_mask, word2_mask = 0, pvt_id;
for (j = 0; j < MAX_INSTANCE_BUFF; j++) {
word1_mask = 0;
for (i = 0; i < 2; i++) {
pvt_id = skl_getid_32(module, &module->pvt_id[j],
word1_mask, word2_mask);
if (pvt_id >= 0)
return pvt_id;
word1_mask += 32;
if ((word1_mask + word2_mask) >= module->max_instance)
return -EINVAL;
}
word2_mask += 64;
if (word2_mask >= module->max_instance)
return -EINVAL;
}
return -EINVAL;
}
int skl_get_pvt_id(struct skl_sst *ctx, struct skl_module_cfg *mconfig)
{
struct uuid_module *module;
uuid_le *uuid_mod;
int pvt_id;
uuid_mod = (uuid_le *)mconfig->guid;
list_for_each_entry(module, &ctx->uuid_list, list) {
if (uuid_le_cmp(*uuid_mod, module->uuid) == 0) {
pvt_id = skl_pvtid_128(module);
if (pvt_id >= 0) {
module->instance_id[pvt_id] =
mconfig->id.instance_id;
return pvt_id;
}
}
}
return -EINVAL;
}
int skl_put_pvt_id(struct skl_sst *ctx, struct skl_module_cfg *mconfig)
{
int i;
uuid_le *uuid_mod;
struct uuid_module *module;
uuid_mod = (uuid_le *)mconfig->guid;
list_for_each_entry(module, &ctx->uuid_list, list) {
if (uuid_le_cmp(*uuid_mod, module->uuid) == 0) {
if (mconfig->id.pvt_id != 0)
i = (mconfig->id.pvt_id) / 64;
else
i = 0;
module->pvt_id[i] &= ~(1 << (mconfig->id.pvt_id));
mconfig->id.pvt_id = -1;
return 0;
}
}
return -EINVAL;
}
int snd_skl_parse_uuids(struct sst_dsp *ctx, const struct firmware *fw,
unsigned int offset, int index)
{
struct adsp_fw_hdr *adsp_hdr;
struct adsp_module_entry *mod_entry;
int i, num_entry, size;
uuid_le *uuid_bin;
const char *buf;
struct skl_sst *skl = ctx->thread_context;
struct uuid_module *module;
struct firmware stripped_fw;
unsigned int safe_file;
stripped_fw.data = fw->data;
stripped_fw.size = fw->size;
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
module->id = (i | (index << 12));
module->is_loadable = mod_entry->type.load_type;
module->max_instance = mod_entry->instance_max_count;
size = sizeof(int) * mod_entry->instance_max_count;
module->instance_id = devm_kzalloc(ctx->dev, size, GFP_KERNEL);
if (!module->instance_id) {
kfree(module);
return -ENOMEM;
}
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
