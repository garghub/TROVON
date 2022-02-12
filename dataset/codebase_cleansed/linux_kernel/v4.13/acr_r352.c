static void
acr_r352_generate_flcn_bl_desc(const struct nvkm_acr *acr,
const struct ls_ucode_img *img, u64 wpr_addr,
void *_desc)
{
struct acr_r352_flcn_bl_desc *desc = _desc;
const struct ls_ucode_img_desc *pdesc = &img->ucode_desc;
u64 base, addr_code, addr_data;
base = wpr_addr + img->ucode_off + pdesc->app_start_offset;
addr_code = (base + pdesc->app_resident_code_offset) >> 8;
addr_data = (base + pdesc->app_resident_data_offset) >> 8;
desc->ctx_dma = FALCON_DMAIDX_UCODE;
desc->code_dma_base = lower_32_bits(addr_code);
desc->code_dma_base1 = upper_32_bits(addr_code);
desc->non_sec_code_off = pdesc->app_resident_code_offset;
desc->non_sec_code_size = pdesc->app_resident_code_size;
desc->code_entry_point = pdesc->app_imem_entry;
desc->data_dma_base = lower_32_bits(addr_data);
desc->data_dma_base1 = upper_32_bits(addr_data);
desc->data_size = pdesc->app_resident_data_size;
}
struct ls_ucode_img *
acr_r352_ls_ucode_img_load(const struct acr_r352 *acr,
const struct nvkm_secboot *sb,
enum nvkm_secboot_falcon falcon_id)
{
const struct nvkm_subdev *subdev = acr->base.subdev;
struct ls_ucode_img_r352 *img;
int ret;
img = kzalloc(sizeof(*img), GFP_KERNEL);
if (!img)
return ERR_PTR(-ENOMEM);
img->base.falcon_id = falcon_id;
ret = acr->func->ls_func[falcon_id]->load(sb, &img->base);
if (ret) {
kfree(img->base.ucode_data);
kfree(img->base.sig);
kfree(img);
return ERR_PTR(ret);
}
if (img->base.sig_size != sizeof(img->lsb_header.signature)) {
nvkm_error(subdev, "invalid signature size for %s falcon!\n",
nvkm_secboot_falcon_name[falcon_id]);
return ERR_PTR(-EINVAL);
}
memcpy(&img->lsb_header.signature, img->base.sig, img->base.sig_size);
img->lsb_header.signature.falcon_id = falcon_id;
return &img->base;
}
static u32
acr_r352_ls_img_fill_headers(struct acr_r352 *acr,
struct ls_ucode_img_r352 *img, u32 offset)
{
struct ls_ucode_img *_img = &img->base;
struct acr_r352_lsf_wpr_header *whdr = &img->wpr_header;
struct acr_r352_lsf_lsb_header *lhdr = &img->lsb_header;
struct ls_ucode_img_desc *desc = &_img->ucode_desc;
const struct acr_r352_ls_func *func =
acr->func->ls_func[_img->falcon_id];
whdr->falcon_id = _img->falcon_id;
whdr->bootstrap_owner = acr->base.boot_falcon;
whdr->status = LSF_IMAGE_STATUS_COPY;
if (acr->lazy_bootstrap & BIT(_img->falcon_id))
whdr->lazy_bootstrap = 1;
offset = ALIGN(offset, LSF_LSB_HEADER_ALIGN);
whdr->lsb_offset = offset;
offset += sizeof(*lhdr);
offset = ALIGN(offset, LSF_UCODE_DATA_ALIGN);
_img->ucode_off = lhdr->ucode_off = offset;
offset += _img->ucode_size;
lhdr->bl_code_size = ALIGN(desc->bootloader_size,
LSF_BL_CODE_SIZE_ALIGN);
lhdr->ucode_size = ALIGN(desc->app_resident_data_offset,
LSF_BL_CODE_SIZE_ALIGN) + lhdr->bl_code_size;
lhdr->data_size = ALIGN(desc->app_size, LSF_BL_CODE_SIZE_ALIGN) +
lhdr->bl_code_size - lhdr->ucode_size;
lhdr->bl_imem_off = desc->bootloader_imem_offset;
lhdr->app_code_off = desc->app_start_offset +
desc->app_resident_code_offset;
lhdr->app_code_size = desc->app_resident_code_size;
lhdr->app_data_off = desc->app_start_offset +
desc->app_resident_data_offset;
lhdr->app_data_size = desc->app_resident_data_size;
lhdr->flags = func->lhdr_flags;
if (_img->falcon_id == acr->base.boot_falcon)
lhdr->flags |= LSF_FLAG_DMACTL_REQ_CTX;
lhdr->bl_data_size = ALIGN(func->bl_desc_size, LSF_BL_DATA_SIZE_ALIGN);
offset = ALIGN(offset, LSF_BL_DATA_ALIGN);
lhdr->bl_data_off = offset;
offset += lhdr->bl_data_size;
return offset;
}
int
acr_r352_ls_fill_headers(struct acr_r352 *acr, struct list_head *imgs)
{
struct ls_ucode_img_r352 *img;
struct list_head *l;
u32 count = 0;
u32 offset;
list_for_each(l, imgs)
count++;
offset = sizeof(img->wpr_header) * (count + 1);
list_for_each_entry(img, imgs, base.node) {
offset = acr_r352_ls_img_fill_headers(acr, img, offset);
}
return offset;
}
int
acr_r352_ls_write_wpr(struct acr_r352 *acr, struct list_head *imgs,
struct nvkm_gpuobj *wpr_blob, u64 wpr_addr)
{
struct ls_ucode_img *_img;
u32 pos = 0;
nvkm_kmap(wpr_blob);
list_for_each_entry(_img, imgs, node) {
struct ls_ucode_img_r352 *img = ls_ucode_img_r352(_img);
const struct acr_r352_ls_func *ls_func =
acr->func->ls_func[_img->falcon_id];
u8 gdesc[ls_func->bl_desc_size];
nvkm_gpuobj_memcpy_to(wpr_blob, pos, &img->wpr_header,
sizeof(img->wpr_header));
nvkm_gpuobj_memcpy_to(wpr_blob, img->wpr_header.lsb_offset,
&img->lsb_header, sizeof(img->lsb_header));
memset(gdesc, 0, ls_func->bl_desc_size);
ls_func->generate_bl_desc(&acr->base, _img, wpr_addr, gdesc);
nvkm_gpuobj_memcpy_to(wpr_blob, img->lsb_header.bl_data_off,
gdesc, ls_func->bl_desc_size);
nvkm_gpuobj_memcpy_to(wpr_blob, img->lsb_header.ucode_off,
_img->ucode_data, _img->ucode_size);
pos += sizeof(img->wpr_header);
}
nvkm_wo32(wpr_blob, pos, NVKM_SECBOOT_FALCON_INVALID);
nvkm_done(wpr_blob);
return 0;
}
static int
acr_r352_prepare_ls_blob(struct acr_r352 *acr, struct nvkm_secboot *sb)
{
const struct nvkm_subdev *subdev = acr->base.subdev;
struct list_head imgs;
struct ls_ucode_img *img, *t;
unsigned long managed_falcons = acr->base.managed_falcons;
u64 wpr_addr = sb->wpr_addr;
u32 wpr_size = sb->wpr_size;
int managed_count = 0;
u32 image_wpr_size, ls_blob_size;
int falcon_id;
int ret;
INIT_LIST_HEAD(&imgs);
for_each_set_bit(falcon_id, &managed_falcons, NVKM_SECBOOT_FALCON_END) {
struct ls_ucode_img *img;
img = acr->func->ls_ucode_img_load(acr, sb, falcon_id);
if (IS_ERR(img)) {
if (acr->base.optional_falcons & BIT(falcon_id)) {
managed_falcons &= ~BIT(falcon_id);
nvkm_info(subdev, "skipping %s falcon...\n",
nvkm_secboot_falcon_name[falcon_id]);
continue;
}
ret = PTR_ERR(img);
goto cleanup;
}
list_add_tail(&img->node, &imgs);
managed_count++;
}
acr->base.managed_falcons = managed_falcons;
if (acr->func->ls_func[acr->base.boot_falcon] &&
(managed_falcons & BIT(acr->base.boot_falcon))) {
for_each_set_bit(falcon_id, &managed_falcons,
NVKM_SECBOOT_FALCON_END) {
if (falcon_id == acr->base.boot_falcon)
continue;
acr->lazy_bootstrap |= BIT(falcon_id);
}
}
image_wpr_size = acr->func->ls_fill_headers(acr, &imgs);
image_wpr_size = ALIGN(image_wpr_size, WPR_ALIGNMENT);
ls_blob_size = image_wpr_size;
if (wpr_size == 0 && acr->func->shadow_blob)
ls_blob_size *= 2;
ret = nvkm_gpuobj_new(subdev->device, ls_blob_size, WPR_ALIGNMENT,
false, NULL, &acr->ls_blob);
if (ret)
goto cleanup;
nvkm_debug(subdev, "%d managed LS falcons, WPR size is %d bytes\n",
managed_count, image_wpr_size);
if (wpr_size == 0) {
wpr_addr = acr->ls_blob->addr;
if (acr->func->shadow_blob)
wpr_addr += acr->ls_blob->size / 2;
wpr_size = image_wpr_size;
} else if (image_wpr_size > wpr_size) {
nvkm_error(subdev, "WPR region too small for FW blob!\n");
nvkm_error(subdev, "required: %dB\n", image_wpr_size);
nvkm_error(subdev, "available: %dB\n", wpr_size);
ret = -ENOSPC;
goto cleanup;
}
ret = acr->func->ls_write_wpr(acr, &imgs, acr->ls_blob, wpr_addr);
if (ret)
nvkm_gpuobj_del(&acr->ls_blob);
cleanup:
list_for_each_entry_safe(img, t, &imgs, node) {
kfree(img->ucode_data);
kfree(img->sig);
kfree(img);
}
return ret;
}
void
acr_r352_fixup_hs_desc(struct acr_r352 *acr, struct nvkm_secboot *sb,
void *_desc)
{
struct hsflcn_acr_desc *desc = _desc;
struct nvkm_gpuobj *ls_blob = acr->ls_blob;
if (sb->wpr_size == 0) {
u64 wpr_start = ls_blob->addr;
u64 wpr_end = wpr_start + ls_blob->size;
desc->wpr_region_id = 1;
desc->regions.no_regions = 2;
desc->regions.region_props[0].start_addr = wpr_start >> 8;
desc->regions.region_props[0].end_addr = wpr_end >> 8;
desc->regions.region_props[0].region_id = 1;
desc->regions.region_props[0].read_mask = 0xf;
desc->regions.region_props[0].write_mask = 0xc;
desc->regions.region_props[0].client_mask = 0x2;
} else {
desc->ucode_blob_base = ls_blob->addr;
desc->ucode_blob_size = ls_blob->size;
}
}
static void
acr_r352_generate_hs_bl_desc(const struct hsf_load_header *hdr, void *_bl_desc,
u64 offset)
{
struct acr_r352_flcn_bl_desc *bl_desc = _bl_desc;
u64 addr_code, addr_data;
addr_code = offset >> 8;
addr_data = (offset + hdr->data_dma_base) >> 8;
bl_desc->ctx_dma = FALCON_DMAIDX_VIRT;
bl_desc->code_dma_base = lower_32_bits(addr_code);
bl_desc->non_sec_code_off = hdr->non_sec_code_off;
bl_desc->non_sec_code_size = hdr->non_sec_code_size;
bl_desc->sec_code_off = hsf_load_header_app_off(hdr, 0);
bl_desc->sec_code_size = hsf_load_header_app_size(hdr, 0);
bl_desc->code_entry_point = 0;
bl_desc->data_dma_base = lower_32_bits(addr_data);
bl_desc->data_size = hdr->data_size;
}
static int
acr_r352_prepare_hs_blob(struct acr_r352 *acr, struct nvkm_secboot *sb,
const char *fw, struct nvkm_gpuobj **blob,
struct hsf_load_header *load_header, bool patch)
{
struct nvkm_subdev *subdev = &sb->subdev;
void *acr_image;
struct fw_bin_header *hsbin_hdr;
struct hsf_fw_header *fw_hdr;
struct hsf_load_header *load_hdr;
void *acr_data;
int ret;
acr_image = hs_ucode_load_blob(subdev, sb->boot_falcon, fw);
if (IS_ERR(acr_image))
return PTR_ERR(acr_image);
hsbin_hdr = acr_image;
fw_hdr = acr_image + hsbin_hdr->header_offset;
load_hdr = acr_image + fw_hdr->hdr_offset;
acr_data = acr_image + hsbin_hdr->data_offset;
if (patch) {
struct hsflcn_acr_desc *desc;
desc = acr_data + load_hdr->data_dma_base;
acr->func->fixup_hs_desc(acr, sb, desc);
}
if (load_hdr->num_apps > ACR_R352_MAX_APPS) {
nvkm_error(subdev, "more apps (%d) than supported (%d)!",
load_hdr->num_apps, ACR_R352_MAX_APPS);
ret = -EINVAL;
goto cleanup;
}
memcpy(load_header, load_hdr, sizeof(*load_header) +
(sizeof(load_hdr->apps[0]) * 2 * load_hdr->num_apps));
ret = nvkm_gpuobj_new(subdev->device, ALIGN(hsbin_hdr->data_size, 256),
0x1000, false, NULL, blob);
if (ret)
goto cleanup;
nvkm_kmap(*blob);
nvkm_gpuobj_memcpy_to(*blob, 0, acr_data, hsbin_hdr->data_size);
nvkm_done(*blob);
cleanup:
kfree(acr_image);
return ret;
}
int
acr_r352_load_blobs(struct acr_r352 *acr, struct nvkm_secboot *sb)
{
struct nvkm_subdev *subdev = &sb->subdev;
int ret;
if (acr->firmware_ok)
return 0;
ret = acr_r352_prepare_ls_blob(acr, sb);
if (ret)
return ret;
if (!acr->load_blob) {
ret = acr_r352_prepare_hs_blob(acr, sb, "acr/ucode_load",
&acr->load_blob,
&acr->load_bl_header, true);
if (ret)
return ret;
}
if (sb->wpr_size == 0) {
ret = acr_r352_prepare_hs_blob(acr, sb, "acr/ucode_unload",
&acr->unload_blob,
&acr->unload_bl_header, false);
if (ret)
return ret;
}
if (!acr->hsbl_blob) {
acr->hsbl_blob = nvkm_acr_load_firmware(subdev, "acr/bl", 0);
if (IS_ERR(acr->hsbl_blob)) {
ret = PTR_ERR(acr->hsbl_blob);
acr->hsbl_blob = NULL;
return ret;
}
if (acr->base.boot_falcon != NVKM_SECBOOT_FALCON_PMU) {
acr->hsbl_unload_blob = nvkm_acr_load_firmware(subdev,
"acr/unload_bl", 0);
if (IS_ERR(acr->hsbl_unload_blob)) {
ret = PTR_ERR(acr->hsbl_unload_blob);
acr->hsbl_unload_blob = NULL;
return ret;
}
} else {
acr->hsbl_unload_blob = acr->hsbl_blob;
}
}
acr->firmware_ok = true;
nvkm_debug(&sb->subdev, "LS blob successfully created\n");
return 0;
}
static int
acr_r352_load(struct nvkm_acr *_acr, struct nvkm_falcon *falcon,
struct nvkm_gpuobj *blob, u64 offset)
{
struct acr_r352 *acr = acr_r352(_acr);
const u32 bl_desc_size = acr->func->hs_bl_desc_size;
const struct hsf_load_header *load_hdr;
struct fw_bin_header *bl_hdr;
struct fw_bl_desc *hsbl_desc;
void *bl, *blob_data, *hsbl_code, *hsbl_data;
u32 code_size;
u8 bl_desc[bl_desc_size];
if (blob == acr->load_blob) {
load_hdr = &acr->load_bl_header;
bl = acr->hsbl_blob;
} else if (blob == acr->unload_blob) {
load_hdr = &acr->unload_bl_header;
bl = acr->hsbl_unload_blob;
} else {
nvkm_error(_acr->subdev, "invalid secure boot blob!\n");
return -EINVAL;
}
bl_hdr = bl;
hsbl_desc = bl + bl_hdr->header_offset;
blob_data = bl + bl_hdr->data_offset;
hsbl_code = blob_data + hsbl_desc->code_off;
hsbl_data = blob_data + hsbl_desc->data_off;
code_size = ALIGN(hsbl_desc->code_size, 256);
nvkm_falcon_load_dmem(falcon, hsbl_data, 0x0, hsbl_desc->data_size, 0);
nvkm_falcon_load_imem(falcon, hsbl_code, falcon->code.limit - code_size,
code_size, hsbl_desc->start_tag, 0, false);
memset(bl_desc, 0, bl_desc_size);
acr->func->generate_hs_bl_desc(load_hdr, bl_desc, offset);
nvkm_falcon_load_dmem(falcon, bl_desc, hsbl_desc->dmem_load_off,
bl_desc_size, 0);
return hsbl_desc->start_tag << 8;
}
static int
acr_r352_shutdown(struct acr_r352 *acr, struct nvkm_secboot *sb)
{
struct nvkm_subdev *subdev = &sb->subdev;
int i;
if (acr->unload_blob && sb->wpr_set) {
int ret;
nvkm_debug(subdev, "running HS unload blob\n");
ret = sb->func->run_blob(sb, acr->unload_blob, sb->halt_falcon);
if (ret < 0)
return ret;
if (ret && ret != 0x1d) {
nvkm_error(subdev, "HS unload failed, ret 0x%08x", ret);
return -EINVAL;
}
nvkm_debug(subdev, "HS unload blob completed\n");
}
for (i = 0; i < NVKM_SECBOOT_FALCON_END; i++)
acr->falcon_state[i] = NON_SECURE;
sb->wpr_set = false;
return 0;
}
static bool
acr_r352_wpr_is_set(const struct acr_r352 *acr, const struct nvkm_secboot *sb)
{
const struct nvkm_subdev *subdev = &sb->subdev;
const struct nvkm_device *device = subdev->device;
u64 wpr_lo, wpr_hi;
u64 wpr_range_lo, wpr_range_hi;
nvkm_wr32(device, 0x100cd4, 0x2);
wpr_lo = (nvkm_rd32(device, 0x100cd4) & ~0xff);
wpr_lo <<= 8;
nvkm_wr32(device, 0x100cd4, 0x3);
wpr_hi = (nvkm_rd32(device, 0x100cd4) & ~0xff);
wpr_hi <<= 8;
if (sb->wpr_size != 0) {
wpr_range_lo = sb->wpr_addr;
wpr_range_hi = wpr_range_lo + sb->wpr_size;
} else {
wpr_range_lo = acr->ls_blob->addr;
wpr_range_hi = wpr_range_lo + acr->ls_blob->size;
}
return (wpr_lo >= wpr_range_lo && wpr_lo < wpr_range_hi &&
wpr_hi > wpr_range_lo && wpr_hi <= wpr_range_hi);
}
static int
acr_r352_bootstrap(struct acr_r352 *acr, struct nvkm_secboot *sb)
{
const struct nvkm_subdev *subdev = &sb->subdev;
unsigned long managed_falcons = acr->base.managed_falcons;
int falcon_id;
int ret;
if (sb->wpr_set)
return 0;
ret = acr_r352_load_blobs(acr, sb);
if (ret)
return ret;
nvkm_debug(subdev, "running HS load blob\n");
ret = sb->func->run_blob(sb, acr->load_blob, sb->boot_falcon);
nvkm_falcon_clear_interrupt(sb->boot_falcon, 0x10);
sb->wpr_set = acr_r352_wpr_is_set(acr, sb);
if (ret < 0) {
return ret;
} else if (ret > 0) {
nvkm_error(subdev, "HS load failed, ret 0x%08x", ret);
return -EINVAL;
}
nvkm_debug(subdev, "HS load blob completed\n");
if (!sb->wpr_set) {
nvkm_error(subdev, "ACR blob completed but WPR not set!\n");
return -EINVAL;
}
for_each_set_bit(falcon_id, &managed_falcons, NVKM_SECBOOT_FALCON_END) {
const struct acr_r352_ls_func *func =
acr->func->ls_func[falcon_id];
if (func->post_run) {
ret = func->post_run(&acr->base, sb);
if (ret)
return ret;
}
}
return 0;
}
static int
acr_r352_reset_nopmu(struct acr_r352 *acr, struct nvkm_secboot *sb,
unsigned long falcon_mask)
{
int falcon;
int ret;
if (!(falcon_mask & BIT(NVKM_SECBOOT_FALCON_FECS)))
goto end;
ret = acr_r352_shutdown(acr, sb);
if (ret)
return ret;
ret = acr_r352_bootstrap(acr, sb);
if (ret)
return ret;
end:
for_each_set_bit(falcon, &falcon_mask, NVKM_SECBOOT_FALCON_END) {
acr->falcon_state[falcon] = RESET;
}
return 0;
}
static int
acr_r352_reset(struct nvkm_acr *_acr, struct nvkm_secboot *sb,
unsigned long falcon_mask)
{
struct acr_r352 *acr = acr_r352(_acr);
struct nvkm_msgqueue *queue;
int falcon;
bool wpr_already_set = sb->wpr_set;
int ret;
ret = acr_r352_bootstrap(acr, sb);
if (ret)
return ret;
if (!nvkm_secboot_is_managed(sb, _acr->boot_falcon)) {
if (wpr_already_set)
return acr_r352_reset_nopmu(acr, sb, falcon_mask);
else
return ret;
}
switch (_acr->boot_falcon) {
case NVKM_SECBOOT_FALCON_PMU:
queue = sb->subdev.device->pmu->queue;
break;
case NVKM_SECBOOT_FALCON_SEC2:
queue = sb->subdev.device->sec2->queue;
break;
default:
return -EINVAL;
}
for_each_set_bit(falcon, &falcon_mask, NVKM_SECBOOT_FALCON_END)
nvkm_debug(&sb->subdev, "resetting %s falcon\n",
nvkm_secboot_falcon_name[falcon]);
ret = nvkm_msgqueue_acr_boot_falcons(queue, falcon_mask);
if (ret) {
nvkm_error(&sb->subdev, "error during falcon reset: %d\n", ret);
return ret;
}
nvkm_debug(&sb->subdev, "falcon reset done\n");
return 0;
}
static int
acr_r352_fini(struct nvkm_acr *_acr, struct nvkm_secboot *sb, bool suspend)
{
struct acr_r352 *acr = acr_r352(_acr);
return acr_r352_shutdown(acr, sb);
}
static void
acr_r352_dtor(struct nvkm_acr *_acr)
{
struct acr_r352 *acr = acr_r352(_acr);
nvkm_gpuobj_del(&acr->unload_blob);
if (_acr->boot_falcon != NVKM_SECBOOT_FALCON_PMU)
kfree(acr->hsbl_unload_blob);
kfree(acr->hsbl_blob);
nvkm_gpuobj_del(&acr->load_blob);
nvkm_gpuobj_del(&acr->ls_blob);
kfree(acr);
}
static void
acr_r352_generate_pmu_bl_desc(const struct nvkm_acr *acr,
const struct ls_ucode_img *img, u64 wpr_addr,
void *_desc)
{
const struct ls_ucode_img_desc *pdesc = &img->ucode_desc;
const struct nvkm_pmu *pmu = acr->subdev->device->pmu;
struct acr_r352_pmu_bl_desc *desc = _desc;
u64 base;
u64 addr_code;
u64 addr_data;
u32 addr_args;
base = wpr_addr + img->ucode_off + pdesc->app_start_offset;
addr_code = (base + pdesc->app_resident_code_offset) >> 8;
addr_data = (base + pdesc->app_resident_data_offset) >> 8;
addr_args = pmu->falcon->data.limit;
addr_args -= NVKM_MSGQUEUE_CMDLINE_SIZE;
desc->dma_idx = FALCON_DMAIDX_UCODE;
desc->code_dma_base = lower_32_bits(addr_code);
desc->code_dma_base1 = upper_32_bits(addr_code);
desc->code_size_total = pdesc->app_size;
desc->code_size_to_load = pdesc->app_resident_code_size;
desc->code_entry_point = pdesc->app_imem_entry;
desc->data_dma_base = lower_32_bits(addr_data);
desc->data_dma_base1 = upper_32_bits(addr_data);
desc->data_size = pdesc->app_resident_data_size;
desc->overlay_dma_base = lower_32_bits(addr_code);
desc->overlay_dma_base1 = upper_32_bits(addr_code);
desc->argc = 1;
desc->argv = addr_args;
}
struct nvkm_acr *
acr_r352_new_(const struct acr_r352_func *func,
enum nvkm_secboot_falcon boot_falcon,
unsigned long managed_falcons)
{
struct acr_r352 *acr;
int i;
for_each_set_bit(i, &managed_falcons, NVKM_SECBOOT_FALCON_END) {
if (!func->ls_func[i])
return ERR_PTR(-ENOTSUPP);
}
acr = kzalloc(sizeof(*acr), GFP_KERNEL);
if (!acr)
return ERR_PTR(-ENOMEM);
acr->base.boot_falcon = boot_falcon;
acr->base.managed_falcons = managed_falcons;
acr->base.func = &acr_r352_base_func;
acr->func = func;
return &acr->base;
}
struct nvkm_acr *
acr_r352_new(unsigned long managed_falcons)
{
return acr_r352_new_(&acr_r352_func, NVKM_SECBOOT_FALCON_PMU,
managed_falcons);
}
