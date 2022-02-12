static void
acr_r352_generate_flcn_bl_desc(const struct nvkm_acr *acr,
const struct ls_ucode_img *_img, u64 wpr_addr,
void *_desc)
{
struct ls_ucode_img_r352 *img = ls_ucode_img_r352(_img);
struct acr_r352_flcn_bl_desc *desc = _desc;
const struct ls_ucode_img_desc *pdesc = &_img->ucode_desc;
u64 base, addr_code, addr_data;
base = wpr_addr + img->lsb_header.ucode_off + pdesc->app_start_offset;
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
enum nvkm_secboot_falcon falcon_id)
{
const struct nvkm_subdev *subdev = acr->base.subdev;
struct ls_ucode_img_r352 *img;
int ret;
img = kzalloc(sizeof(*img), GFP_KERNEL);
if (!img)
return ERR_PTR(-ENOMEM);
img->base.falcon_id = falcon_id;
ret = acr->func->ls_func[falcon_id]->load(subdev, &img->base);
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
lhdr->ucode_off = offset;
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
struct nvkm_gpuobj *wpr_blob, u32 wpr_addr)
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
acr_r352_prepare_ls_blob(struct acr_r352 *acr, u64 wpr_addr, u32 wpr_size)
{
const struct nvkm_subdev *subdev = acr->base.subdev;
struct list_head imgs;
struct ls_ucode_img *img, *t;
unsigned long managed_falcons = acr->base.managed_falcons;
int managed_count = 0;
u32 image_wpr_size;
int falcon_id;
int ret;
INIT_LIST_HEAD(&imgs);
for_each_set_bit(falcon_id, &managed_falcons, NVKM_SECBOOT_FALCON_END) {
struct ls_ucode_img *img;
img = acr->func->ls_ucode_img_load(acr, falcon_id);
if (IS_ERR(img)) {
ret = PTR_ERR(img);
goto cleanup;
}
list_add_tail(&img->node, &imgs);
managed_count++;
}
image_wpr_size = acr->func->ls_fill_headers(acr, &imgs);
image_wpr_size = ALIGN(image_wpr_size, WPR_ALIGNMENT);
ret = nvkm_gpuobj_new(subdev->device, image_wpr_size, WPR_ALIGNMENT,
false, NULL, &acr->ls_blob);
if (ret)
goto cleanup;
nvkm_debug(subdev, "%d managed LS falcons, WPR size is %d bytes\n",
managed_count, image_wpr_size);
if (wpr_size == 0) {
wpr_addr = acr->ls_blob->addr;
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
static void
acr_r352_hsf_patch_signature(struct nvkm_secboot *sb, void *acr_image)
{
struct fw_bin_header *hsbin_hdr = acr_image;
struct hsf_fw_header *fw_hdr = acr_image + hsbin_hdr->header_offset;
void *hs_data = acr_image + hsbin_hdr->data_offset;
void *sig;
u32 sig_size;
if (sb->boot_falcon->debug) {
sig = acr_image + fw_hdr->sig_dbg_offset;
sig_size = fw_hdr->sig_dbg_size;
} else {
sig = acr_image + fw_hdr->sig_prod_offset;
sig_size = fw_hdr->sig_prod_size;
}
memcpy(hs_data + fw_hdr->patch_loc, sig + fw_hdr->patch_sig, sig_size);
}
static void
acr_r352_fixup_hs_desc(struct acr_r352 *acr, struct nvkm_secboot *sb,
struct hsflcn_acr_desc *desc)
{
struct nvkm_gpuobj *ls_blob = acr->ls_blob;
if (sb->wpr_size == 0) {
u32 wpr_start = ls_blob->addr;
u32 wpr_end = wpr_start + ls_blob->size;
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
bl_desc->sec_code_off = hdr->app[0].sec_code_off;
bl_desc->sec_code_size = hdr->app[0].sec_code_size;
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
acr_image = nvkm_acr_load_firmware(subdev, fw, 0);
if (IS_ERR(acr_image))
return PTR_ERR(acr_image);
hsbin_hdr = acr_image;
fw_hdr = acr_image + hsbin_hdr->header_offset;
load_hdr = acr_image + fw_hdr->hdr_offset;
acr_data = acr_image + hsbin_hdr->data_offset;
acr_r352_hsf_patch_signature(sb, acr_image);
if (patch) {
struct hsflcn_acr_desc *desc;
desc = acr_data + load_hdr->data_dma_base;
acr_r352_fixup_hs_desc(acr, sb, desc);
}
if (load_hdr->num_apps > ACR_R352_MAX_APPS) {
nvkm_error(subdev, "more apps (%d) than supported (%d)!",
load_hdr->num_apps, ACR_R352_MAX_APPS);
ret = -EINVAL;
goto cleanup;
}
memcpy(load_header, load_hdr, sizeof(*load_header) +
(sizeof(load_hdr->app[0]) * load_hdr->num_apps));
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
static int
acr_r352_prepare_hsbl_blob(struct acr_r352 *acr)
{
const struct nvkm_subdev *subdev = acr->base.subdev;
struct fw_bin_header *hdr;
struct fw_bl_desc *hsbl_desc;
acr->hsbl_blob = nvkm_acr_load_firmware(subdev, "acr/bl", 0);
if (IS_ERR(acr->hsbl_blob)) {
int ret = PTR_ERR(acr->hsbl_blob);
acr->hsbl_blob = NULL;
return ret;
}
hdr = acr->hsbl_blob;
hsbl_desc = acr->hsbl_blob + hdr->header_offset;
acr->base.start_address = hsbl_desc->start_tag << 8;
return 0;
}
int
acr_r352_load_blobs(struct acr_r352 *acr, struct nvkm_secboot *sb)
{
int ret;
if (acr->firmware_ok)
return 0;
ret = acr_r352_prepare_ls_blob(acr, sb->wpr_addr, sb->wpr_size);
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
ret = acr_r352_prepare_hsbl_blob(acr);
if (ret)
return ret;
}
acr->firmware_ok = true;
nvkm_debug(&sb->subdev, "LS blob successfully created\n");
return 0;
}
static int
acr_r352_load(struct nvkm_acr *_acr, struct nvkm_secboot *sb,
struct nvkm_gpuobj *blob, u64 offset)
{
struct acr_r352 *acr = acr_r352(_acr);
struct nvkm_falcon *falcon = sb->boot_falcon;
struct fw_bin_header *hdr = acr->hsbl_blob;
struct fw_bl_desc *hsbl_desc = acr->hsbl_blob + hdr->header_offset;
void *blob_data = acr->hsbl_blob + hdr->data_offset;
void *hsbl_code = blob_data + hsbl_desc->code_off;
void *hsbl_data = blob_data + hsbl_desc->data_off;
u32 code_size = ALIGN(hsbl_desc->code_size, 256);
const struct hsf_load_header *load_hdr;
const u32 bl_desc_size = acr->func->hs_bl_desc_size;
u8 bl_desc[bl_desc_size];
if (blob == acr->load_blob) {
load_hdr = &acr->load_bl_header;
} else if (blob == acr->unload_blob) {
load_hdr = &acr->unload_bl_header;
} else {
nvkm_error(_acr->subdev, "invalid secure boot blob!\n");
return -EINVAL;
}
nvkm_falcon_load_dmem(falcon, hsbl_data, 0x0, hsbl_desc->data_size, 0);
nvkm_falcon_load_imem(falcon, hsbl_code, falcon->code.limit - code_size,
code_size, hsbl_desc->start_tag, 0, false);
memset(bl_desc, 0, bl_desc_size);
acr->func->generate_hs_bl_desc(load_hdr, bl_desc, offset);
nvkm_falcon_load_dmem(falcon, bl_desc, hsbl_desc->dmem_load_off,
bl_desc_size, 0);
return 0;
}
static int
acr_r352_shutdown(struct acr_r352 *acr, struct nvkm_secboot *sb)
{
int i;
if (acr->unload_blob && sb->wpr_set) {
int ret;
nvkm_debug(&sb->subdev, "running HS unload blob\n");
ret = sb->func->run_blob(sb, acr->unload_blob);
if (ret)
return ret;
nvkm_debug(&sb->subdev, "HS unload blob completed\n");
}
for (i = 0; i < NVKM_SECBOOT_FALCON_END; i++)
acr->falcon_state[i] = NON_SECURE;
sb->wpr_set = false;
return 0;
}
static int
acr_r352_bootstrap(struct acr_r352 *acr, struct nvkm_secboot *sb)
{
int ret;
if (sb->wpr_set)
return 0;
ret = acr_r352_load_blobs(acr, sb);
if (ret)
return ret;
nvkm_debug(&sb->subdev, "running HS load blob\n");
ret = sb->func->run_blob(sb, acr->load_blob);
nvkm_falcon_clear_interrupt(sb->boot_falcon, 0x10);
if (ret)
return ret;
nvkm_debug(&sb->subdev, "HS load blob completed\n");
sb->wpr_set = true;
return 0;
}
static int
acr_r352_reset(struct nvkm_acr *_acr, struct nvkm_secboot *sb,
enum nvkm_secboot_falcon falcon)
{
struct acr_r352 *acr = acr_r352(_acr);
int ret;
if (falcon != NVKM_SECBOOT_FALCON_FECS)
goto end;
ret = acr_r352_shutdown(acr, sb);
if (ret)
return ret;
acr_r352_bootstrap(acr, sb);
if (ret)
return ret;
end:
acr->falcon_state[falcon] = RESET;
return 0;
}
static int
acr_r352_start(struct nvkm_acr *_acr, struct nvkm_secboot *sb,
enum nvkm_secboot_falcon falcon)
{
struct acr_r352 *acr = acr_r352(_acr);
const struct nvkm_subdev *subdev = &sb->subdev;
int base;
switch (falcon) {
case NVKM_SECBOOT_FALCON_FECS:
base = 0x409000;
break;
case NVKM_SECBOOT_FALCON_GPCCS:
base = 0x41a000;
break;
default:
nvkm_error(subdev, "cannot start unhandled falcon!\n");
return -EINVAL;
}
nvkm_wr32(subdev->device, base + 0x130, 0x00000002);
acr->falcon_state[falcon] = RUNNING;
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
kfree(acr->hsbl_blob);
nvkm_gpuobj_del(&acr->load_blob);
nvkm_gpuobj_del(&acr->ls_blob);
kfree(acr);
}
struct nvkm_acr *
acr_r352_new_(const struct acr_r352_func *func,
enum nvkm_secboot_falcon boot_falcon,
unsigned long managed_falcons)
{
struct acr_r352 *acr;
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
