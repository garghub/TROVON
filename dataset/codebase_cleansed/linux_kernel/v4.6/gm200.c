static void *
gm200_secboot_load_firmware(struct nvkm_subdev *subdev, const char *name,
size_t min_size)
{
const struct firmware *fw;
void *blob;
int ret;
ret = nvkm_firmware_get(subdev->device, name, &fw);
if (ret)
return ERR_PTR(ret);
if (fw->size < min_size) {
nvkm_error(subdev, "%s is smaller than expected size %zu\n",
name, min_size);
nvkm_firmware_put(fw);
return ERR_PTR(-EINVAL);
}
blob = kmemdup(fw->data, fw->size, GFP_KERNEL);
nvkm_firmware_put(fw);
if (!blob)
return ERR_PTR(-ENOMEM);
return blob;
}
static void *
ls_ucode_img_build(const struct firmware *bl, const struct firmware *code,
const struct firmware *data, struct ls_ucode_img_desc *desc)
{
struct fw_bin_header *bin_hdr = (void *)bl->data;
struct fw_bl_desc *bl_desc = (void *)bl->data + bin_hdr->header_offset;
void *bl_data = (void *)bl->data + bin_hdr->data_offset;
u32 pos = 0;
void *image;
desc->bootloader_start_offset = pos;
desc->bootloader_size = ALIGN(bl_desc->code_size, sizeof(u32));
desc->bootloader_imem_offset = bl_desc->start_tag * 256;
desc->bootloader_entry_point = bl_desc->start_tag * 256;
pos = ALIGN(pos + desc->bootloader_size, BL_DESC_BLK_SIZE);
desc->app_start_offset = pos;
desc->app_size = ALIGN(code->size, BL_DESC_BLK_SIZE) +
ALIGN(data->size, BL_DESC_BLK_SIZE);
desc->app_imem_offset = 0;
desc->app_imem_entry = 0;
desc->app_dmem_offset = 0;
desc->app_resident_code_offset = 0;
desc->app_resident_code_size = ALIGN(code->size, BL_DESC_BLK_SIZE);
pos = ALIGN(pos + desc->app_resident_code_size, BL_DESC_BLK_SIZE);
desc->app_resident_data_offset = pos - desc->app_start_offset;
desc->app_resident_data_size = ALIGN(data->size, BL_DESC_BLK_SIZE);
desc->image_size = ALIGN(bl_desc->code_size, BL_DESC_BLK_SIZE) +
desc->app_size;
image = kzalloc(desc->image_size, GFP_KERNEL);
if (!image)
return ERR_PTR(-ENOMEM);
memcpy(image + desc->bootloader_start_offset, bl_data,
bl_desc->code_size);
memcpy(image + desc->app_start_offset, code->data, code->size);
memcpy(image + desc->app_start_offset + desc->app_resident_data_offset,
data->data, data->size);
return image;
}
static int
ls_ucode_img_load_generic(struct nvkm_subdev *subdev,
struct ls_ucode_img *img, const char *falcon_name,
const u32 falcon_id)
{
const struct firmware *bl, *code, *data;
struct lsf_ucode_desc *lsf_desc;
char f[64];
int ret;
img->ucode_header = NULL;
snprintf(f, sizeof(f), "gr/%s_bl", falcon_name);
ret = nvkm_firmware_get(subdev->device, f, &bl);
if (ret)
goto error;
snprintf(f, sizeof(f), "gr/%s_inst", falcon_name);
ret = nvkm_firmware_get(subdev->device, f, &code);
if (ret)
goto free_bl;
snprintf(f, sizeof(f), "gr/%s_data", falcon_name);
ret = nvkm_firmware_get(subdev->device, f, &data);
if (ret)
goto free_inst;
img->ucode_data = ls_ucode_img_build(bl, code, data,
&img->ucode_desc);
if (IS_ERR(img->ucode_data)) {
ret = PTR_ERR(img->ucode_data);
goto free_data;
}
img->ucode_size = img->ucode_desc.image_size;
snprintf(f, sizeof(f), "gr/%s_sig", falcon_name);
lsf_desc = gm200_secboot_load_firmware(subdev, f, sizeof(*lsf_desc));
if (IS_ERR(lsf_desc)) {
ret = PTR_ERR(lsf_desc);
goto free_image;
}
lsf_desc->falcon_id = falcon_id;
memcpy(&img->lsb_header.signature, lsf_desc, sizeof(*lsf_desc));
img->falcon_id = lsf_desc->falcon_id;
kfree(lsf_desc);
goto free_data;
free_image:
kfree(img->ucode_data);
free_data:
nvkm_firmware_put(data);
free_inst:
nvkm_firmware_put(code);
free_bl:
nvkm_firmware_put(bl);
error:
return ret;
}
static int
ls_ucode_img_load_fecs(struct nvkm_subdev *subdev, struct ls_ucode_img *img)
{
return ls_ucode_img_load_generic(subdev, img, "fecs",
NVKM_SECBOOT_FALCON_FECS);
}
static int
ls_ucode_img_load_gpccs(struct nvkm_subdev *subdev, struct ls_ucode_img *img)
{
return ls_ucode_img_load_generic(subdev, img, "gpccs",
NVKM_SECBOOT_FALCON_GPCCS);
}
static struct ls_ucode_img *
ls_ucode_img_load(struct nvkm_subdev *subdev, lsf_load_func load_func)
{
struct ls_ucode_img *img;
int ret;
img = kzalloc(sizeof(*img), GFP_KERNEL);
if (!img)
return ERR_PTR(-ENOMEM);
ret = load_func(subdev, img);
if (ret) {
kfree(img);
return ERR_PTR(ret);
}
return img;
}
static void
ls_ucode_img_populate_bl_desc(struct ls_ucode_img *img, u64 wpr_addr,
struct gm200_flcn_bl_desc *desc)
{
struct ls_ucode_img_desc *pdesc = &img->ucode_desc;
u64 addr_base;
addr_base = wpr_addr + img->lsb_header.ucode_off +
pdesc->app_start_offset;
memset(desc, 0, sizeof(*desc));
desc->ctx_dma = FALCON_DMAIDX_UCODE;
desc->code_dma_base.lo = lower_32_bits(
(addr_base + pdesc->app_resident_code_offset));
desc->code_dma_base.hi = upper_32_bits(
(addr_base + pdesc->app_resident_code_offset));
desc->non_sec_code_size = pdesc->app_resident_code_size;
desc->data_dma_base.lo = lower_32_bits(
(addr_base + pdesc->app_resident_data_offset));
desc->data_dma_base.hi = upper_32_bits(
(addr_base + pdesc->app_resident_data_offset));
desc->data_size = pdesc->app_resident_data_size;
desc->code_entry_point = pdesc->app_imem_entry;
}
static u32
ls_ucode_img_fill_headers(struct gm200_secboot *gsb, struct ls_ucode_img *img,
u32 offset)
{
struct lsf_wpr_header *whdr = &img->wpr_header;
struct lsf_lsb_header *lhdr = &img->lsb_header;
struct ls_ucode_img_desc *desc = &img->ucode_desc;
if (img->ucode_header) {
nvkm_fatal(&gsb->base.subdev,
"images withough loader are not supported yet!\n");
return offset;
}
whdr->falcon_id = img->falcon_id;
whdr->bootstrap_owner = gsb->base.func->boot_falcon;
whdr->status = LSF_IMAGE_STATUS_COPY;
offset = ALIGN(offset, LSF_LSB_HEADER_ALIGN);
whdr->lsb_offset = offset;
offset += sizeof(struct lsf_lsb_header);
offset = ALIGN(offset, LSF_UCODE_DATA_ALIGN);
lhdr->ucode_off = offset;
offset += img->ucode_size;
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
lhdr->flags = 0;
if (img->falcon_id == gsb->base.func->boot_falcon)
lhdr->flags = LSF_FLAG_DMACTL_REQ_CTX;
if (img->falcon_id == NVKM_SECBOOT_FALCON_GPCCS)
lhdr->flags |= LSF_FLAG_FORCE_PRIV_LOAD;
lhdr->bl_data_size = ALIGN(sizeof(struct gm200_flcn_bl_desc),
LSF_BL_DATA_SIZE_ALIGN);
offset = ALIGN(offset, LSF_BL_DATA_ALIGN);
lhdr->bl_data_off = offset;
offset += lhdr->bl_data_size;
return offset;
}
static void
ls_ucode_mgr_init(struct ls_ucode_mgr *mgr)
{
memset(mgr, 0, sizeof(*mgr));
INIT_LIST_HEAD(&mgr->img_list);
}
static void
ls_ucode_mgr_cleanup(struct ls_ucode_mgr *mgr)
{
struct ls_ucode_img *img, *t;
list_for_each_entry_safe(img, t, &mgr->img_list, node) {
kfree(img->ucode_data);
kfree(img->ucode_header);
kfree(img);
}
}
static void
ls_ucode_mgr_add_img(struct ls_ucode_mgr *mgr, struct ls_ucode_img *img)
{
mgr->count++;
list_add_tail(&img->node, &mgr->img_list);
}
static void
ls_ucode_mgr_fill_headers(struct gm200_secboot *gsb, struct ls_ucode_mgr *mgr)
{
struct ls_ucode_img *img;
u32 offset;
offset = sizeof(struct lsf_wpr_header) * (mgr->count + 1);
list_for_each_entry(img, &mgr->img_list, node) {
offset = ls_ucode_img_fill_headers(gsb, img, offset);
}
mgr->wpr_size = offset;
}
static int
ls_ucode_mgr_write_wpr(struct gm200_secboot *gsb, struct ls_ucode_mgr *mgr,
struct nvkm_gpuobj *wpr_blob)
{
struct ls_ucode_img *img;
u32 pos = 0;
nvkm_kmap(wpr_blob);
list_for_each_entry(img, &mgr->img_list, node) {
nvkm_gpuobj_memcpy_to(wpr_blob, pos, &img->wpr_header,
sizeof(img->wpr_header));
nvkm_gpuobj_memcpy_to(wpr_blob, img->wpr_header.lsb_offset,
&img->lsb_header, sizeof(img->lsb_header));
if (!img->ucode_header) {
u8 desc[gsb->func->bl_desc_size];
struct gm200_flcn_bl_desc gdesc;
ls_ucode_img_populate_bl_desc(img, gsb->wpr_addr,
&gdesc);
gsb->func->fixup_bl_desc(&gdesc, &desc);
nvkm_gpuobj_memcpy_to(wpr_blob,
img->lsb_header.bl_data_off,
&desc, gsb->func->bl_desc_size);
}
nvkm_gpuobj_memcpy_to(wpr_blob, img->lsb_header.ucode_off,
img->ucode_data, img->ucode_size);
pos += sizeof(img->wpr_header);
}
nvkm_wo32(wpr_blob, pos, NVKM_SECBOOT_FALCON_INVALID);
nvkm_done(wpr_blob);
return 0;
}
static int
gm200_secboot_prepare_ls_blob(struct gm200_secboot *gsb)
{
struct nvkm_secboot *sb = &gsb->base;
struct nvkm_device *device = sb->subdev.device;
struct ls_ucode_mgr mgr;
int falcon_id;
int ret;
ls_ucode_mgr_init(&mgr);
for_each_set_bit(falcon_id, &gsb->base.func->managed_falcons,
NVKM_SECBOOT_FALCON_END) {
struct ls_ucode_img *img;
img = ls_ucode_img_load(&sb->subdev, lsf_load_funcs[falcon_id]);
if (IS_ERR(img)) {
ret = PTR_ERR(img);
goto cleanup;
}
ls_ucode_mgr_add_img(&mgr, img);
}
ls_ucode_mgr_fill_headers(gsb, &mgr);
mgr.wpr_size = ALIGN(mgr.wpr_size, WPR_ALIGNMENT);
ret = nvkm_gpuobj_new(device, mgr.wpr_size, WPR_ALIGNMENT, false, NULL,
&gsb->ls_blob);
if (ret)
goto cleanup;
nvkm_debug(&sb->subdev, "%d managed LS falcons, WPR size is %d bytes\n",
mgr.count, mgr.wpr_size);
if (!gsb->wpr_size) {
gsb->wpr_addr = gsb->ls_blob->addr;
gsb->wpr_size = gsb->ls_blob->size;
}
ret = ls_ucode_mgr_write_wpr(gsb, &mgr, gsb->ls_blob);
cleanup:
ls_ucode_mgr_cleanup(&mgr);
return ret;
}
static void
gm200_secboot_hsf_patch_signature(struct gm200_secboot *gsb, void *acr_image)
{
struct nvkm_secboot *sb = &gsb->base;
struct fw_bin_header *hsbin_hdr = acr_image;
struct hsf_fw_header *fw_hdr = acr_image + hsbin_hdr->header_offset;
void *hs_data = acr_image + hsbin_hdr->data_offset;
void *sig;
u32 sig_size;
if ((nvkm_rd32(sb->subdev.device, sb->base + 0xc08) >> 20) & 0x1) {
sig = acr_image + fw_hdr->sig_dbg_offset;
sig_size = fw_hdr->sig_dbg_size;
} else {
sig = acr_image + fw_hdr->sig_prod_offset;
sig_size = fw_hdr->sig_prod_size;
}
memcpy(hs_data + fw_hdr->patch_loc, sig + fw_hdr->patch_sig, sig_size);
}
static void
gm200_secboot_populate_hsf_bl_desc(void *acr_image,
struct gm200_flcn_bl_desc *bl_desc)
{
struct fw_bin_header *hsbin_hdr = acr_image;
struct hsf_fw_header *fw_hdr = acr_image + hsbin_hdr->header_offset;
struct hsf_load_header *load_hdr = acr_image + fw_hdr->hdr_offset;
fw_hdr = acr_image + hsbin_hdr->header_offset;
load_hdr = acr_image + fw_hdr->hdr_offset;
memset(bl_desc, 0, sizeof(*bl_desc));
bl_desc->ctx_dma = FALCON_DMAIDX_VIRT;
bl_desc->non_sec_code_off = load_hdr->non_sec_code_off;
bl_desc->non_sec_code_size = load_hdr->non_sec_code_size;
bl_desc->sec_code_off = load_hdr->app[0].sec_code_off;
bl_desc->sec_code_size = load_hdr->app[0].sec_code_size;
bl_desc->code_entry_point = 0;
bl_desc->code_dma_base.lo = 0;
bl_desc->data_dma_base.lo = load_hdr->data_dma_base;
bl_desc->data_size = load_hdr->data_size;
}
static int
gm200_secboot_prepare_hs_blob(struct gm200_secboot *gsb, const char *fw,
struct nvkm_gpuobj **blob,
struct gm200_flcn_bl_desc *bl_desc, bool patch)
{
struct nvkm_subdev *subdev = &gsb->base.subdev;
void *acr_image;
struct fw_bin_header *hsbin_hdr;
struct hsf_fw_header *fw_hdr;
void *acr_data;
struct hsf_load_header *load_hdr;
struct hsflcn_acr_desc *desc;
int ret;
acr_image = gm200_secboot_load_firmware(subdev, fw, 0);
if (IS_ERR(acr_image))
return PTR_ERR(acr_image);
hsbin_hdr = acr_image;
gm200_secboot_hsf_patch_signature(gsb, acr_image);
acr_data = acr_image + hsbin_hdr->data_offset;
if (patch) {
fw_hdr = acr_image + hsbin_hdr->header_offset;
load_hdr = acr_image + fw_hdr->hdr_offset;
desc = acr_data + load_hdr->data_dma_base;
gsb->func->fixup_hs_desc(gsb, desc);
}
gm200_secboot_populate_hsf_bl_desc(acr_image, bl_desc);
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
gm200_secboot_prepare_hsbl_blob(struct gm200_secboot *gsb)
{
struct nvkm_subdev *subdev = &gsb->base.subdev;
gsb->hsbl_blob = gm200_secboot_load_firmware(subdev, "acr/bl", 0);
if (IS_ERR(gsb->hsbl_blob)) {
int ret = PTR_ERR(gsb->hsbl_blob);
gsb->hsbl_blob = NULL;
return ret;
}
return 0;
}
int
gm20x_secboot_prepare_blobs(struct gm200_secboot *gsb)
{
int ret;
ret = gm200_secboot_prepare_ls_blob(gsb);
if (ret)
return ret;
ret = gm200_secboot_prepare_hs_blob(gsb, "acr/ucode_load",
&gsb->acr_load_blob,
&gsb->acr_load_bl_desc, true);
if (ret)
return ret;
ret = gm200_secboot_prepare_hsbl_blob(gsb);
if (ret)
return ret;
return 0;
}
static int
gm200_secboot_prepare_blobs(struct nvkm_secboot *sb)
{
struct gm200_secboot *gsb = gm200_secboot(sb);
int ret;
ret = gm20x_secboot_prepare_blobs(gsb);
if (ret)
return ret;
ret = gm200_secboot_prepare_hs_blob(gsb, "acr/ucode_unload",
&gsb->acr_unload_blob,
&gsb->acr_unload_bl_desc, false);
if (ret)
return ret;
return 0;
}
static void
gm200_secboot_load_hs_bl(struct gm200_secboot *gsb, void *data, u32 data_size)
{
struct nvkm_device *device = gsb->base.subdev.device;
struct fw_bin_header *hdr = gsb->hsbl_blob;
struct fw_bl_desc *hsbl_desc = gsb->hsbl_blob + hdr->header_offset;
void *blob_data = gsb->hsbl_blob + hdr->data_offset;
void *hsbl_code = blob_data + hsbl_desc->code_off;
void *hsbl_data = blob_data + hsbl_desc->data_off;
u32 code_size = ALIGN(hsbl_desc->code_size, 256);
const u32 base = gsb->base.base;
u32 blk;
u32 tag;
int i;
nvkm_wr32(device, base + 0x1c0, (0x00000000 | (0x1 << 24)));
for (i = 0; i < hsbl_desc->data_size / 4; i++)
nvkm_wr32(device, base + 0x1c4, ((u32 *)hsbl_data)[i]);
nvkm_wr32(device, base + 0x1c0,
(hsbl_desc->dmem_load_off | (0x1 << 24)));
for (i = 0; i < data_size / 4; i++)
nvkm_wr32(device, base + 0x1c4, ((u32 *)data)[i]);
blk = (nvkm_rd32(device, base + 0x108) & 0x1ff) - (code_size >> 8);
tag = hsbl_desc->start_tag;
nvkm_wr32(device, base + 0x180, ((blk & 0xff) << 8) | (0x1 << 24));
for (i = 0; i < code_size / 4; i++) {
if ((i & 0x3f) == 0) {
nvkm_wr32(device, base + 0x188, tag & 0xffff);
tag++;
}
nvkm_wr32(device, base + 0x184, ((u32 *)hsbl_code)[i]);
}
nvkm_wr32(device, base + 0x188, 0);
}
static int
gm200_secboot_setup_falcon(struct gm200_secboot *gsb)
{
struct nvkm_device *device = gsb->base.subdev.device;
struct fw_bin_header *hdr = gsb->hsbl_blob;
struct fw_bl_desc *hsbl_desc = gsb->hsbl_blob + hdr->header_offset;
u32 virt_addr = hsbl_desc->start_tag << 8;
const u32 base = gsb->base.base;
const u32 reg_base = base + 0xe00;
u32 inst_loc;
int ret;
ret = nvkm_secboot_falcon_reset(&gsb->base);
if (ret)
return ret;
nvkm_wr32(device, reg_base + 4 * (FALCON_DMAIDX_UCODE), 0x4);
nvkm_wr32(device, reg_base + 4 * (FALCON_DMAIDX_VIRT), 0x0);
nvkm_wr32(device, reg_base + 4 * (FALCON_DMAIDX_PHYS_VID), 0x4);
nvkm_wr32(device, reg_base + 4 * (FALCON_DMAIDX_PHYS_SYS_COH),
0x4 | 0x1);
nvkm_wr32(device, reg_base + 4 * (FALCON_DMAIDX_PHYS_SYS_NCOH),
0x4 | 0x2);
if (nvkm_memory_target(gsb->inst->memory) == NVKM_MEM_TARGET_VRAM)
inst_loc = 0x0;
else
inst_loc = 0x3;
nvkm_mask(device, base + 0x048, 0x1, 0x1);
nvkm_wr32(device, base + 0x480,
((gsb->inst->addr >> 12) & 0xfffffff) |
(inst_loc << 28) | (1 << 30));
nvkm_wr32(device, base + 0x104, virt_addr);
return 0;
}
static int
gm200_secboot_run_hs_blob(struct gm200_secboot *gsb, struct nvkm_gpuobj *blob,
struct gm200_flcn_bl_desc *desc)
{
struct nvkm_vma vma;
u64 vma_addr;
const u32 bl_desc_size = gsb->func->bl_desc_size;
u8 bl_desc[bl_desc_size];
int ret;
ret = nvkm_gpuobj_map(blob, gsb->vm, NV_MEM_ACCESS_RW, &vma);
if (ret)
return ret;
vma_addr = flcn64_to_u64(desc->code_dma_base) + vma.offset;
desc->code_dma_base.lo = lower_32_bits(vma_addr);
desc->code_dma_base.hi = upper_32_bits(vma_addr);
vma_addr = flcn64_to_u64(desc->data_dma_base) + vma.offset;
desc->data_dma_base.lo = lower_32_bits(vma_addr);
desc->data_dma_base.hi = upper_32_bits(vma_addr);
gsb->func->fixup_bl_desc(desc, &bl_desc);
ret = gm200_secboot_setup_falcon(gsb);
if (ret)
goto done;
gm200_secboot_load_hs_bl(gsb, &bl_desc, bl_desc_size);
ret = nvkm_secboot_falcon_run(&gsb->base);
if (ret)
goto done;
done:
vma_addr = flcn64_to_u64(desc->code_dma_base) - vma.offset;
desc->code_dma_base.lo = lower_32_bits(vma_addr);
desc->code_dma_base.hi = upper_32_bits(vma_addr);
vma_addr = flcn64_to_u64(desc->data_dma_base) - vma.offset;
desc->data_dma_base.lo = lower_32_bits(vma_addr);
desc->data_dma_base.hi = upper_32_bits(vma_addr);
nvkm_gpuobj_unmap(&vma);
return ret;
}
int
gm200_secboot_reset(struct nvkm_secboot *sb, enum nvkm_secboot_falcon falcon)
{
struct gm200_secboot *gsb = gm200_secboot(sb);
int ret;
if (falcon != NVKM_SECBOOT_FALCON_FECS)
goto end;
if (gsb->acr_unload_blob &&
gsb->falcon_state[NVKM_SECBOOT_FALCON_FECS] != NON_SECURE) {
ret = gm200_secboot_run_hs_blob(gsb, gsb->acr_unload_blob,
&gsb->acr_unload_bl_desc);
if (ret)
return ret;
}
ret = gm200_secboot_run_hs_blob(gsb, gsb->acr_load_blob,
&gsb->acr_load_bl_desc);
if (ret)
return ret;
end:
gsb->falcon_state[falcon] = RESET;
return 0;
}
int
gm200_secboot_start(struct nvkm_secboot *sb, enum nvkm_secboot_falcon falcon)
{
struct gm200_secboot *gsb = gm200_secboot(sb);
int base;
switch (falcon) {
case NVKM_SECBOOT_FALCON_FECS:
base = 0x409000;
break;
case NVKM_SECBOOT_FALCON_GPCCS:
base = 0x41a000;
break;
default:
nvkm_error(&sb->subdev, "cannot start unhandled falcon!\n");
return -EINVAL;
}
nvkm_wr32(sb->subdev.device, base + 0x130, 0x00000002);
gsb->falcon_state[falcon] = RUNNING;
return 0;
}
int
gm200_secboot_init(struct nvkm_secboot *sb)
{
struct gm200_secboot *gsb = gm200_secboot(sb);
struct nvkm_device *device = sb->subdev.device;
struct nvkm_vm *vm;
const u64 vm_area_len = 600 * 1024;
int ret;
ret = nvkm_gpuobj_new(device, 0x1000, 0, true, NULL, &gsb->inst);
if (ret)
return ret;
ret = nvkm_gpuobj_new(device, 0x8000, 0, true, NULL, &gsb->pgd);
if (ret)
return ret;
ret = nvkm_vm_new(device, 0, vm_area_len, 0, NULL, &vm);
if (ret)
return ret;
atomic_inc(&vm->engref[NVKM_SUBDEV_PMU]);
ret = nvkm_vm_ref(vm, &gsb->vm, gsb->pgd);
nvkm_vm_ref(NULL, &vm, NULL);
if (ret)
return ret;
nvkm_kmap(gsb->inst);
nvkm_wo32(gsb->inst, 0x200, lower_32_bits(gsb->pgd->addr));
nvkm_wo32(gsb->inst, 0x204, upper_32_bits(gsb->pgd->addr));
nvkm_wo32(gsb->inst, 0x208, lower_32_bits(vm_area_len - 1));
nvkm_wo32(gsb->inst, 0x20c, upper_32_bits(vm_area_len - 1));
nvkm_done(gsb->inst);
return 0;
}
int
gm200_secboot_fini(struct nvkm_secboot *sb, bool suspend)
{
struct gm200_secboot *gsb = gm200_secboot(sb);
int ret = 0;
int i;
if (gsb->acr_unload_blob &&
gsb->falcon_state[NVKM_SECBOOT_FALCON_FECS] != NON_SECURE)
ret = gm200_secboot_run_hs_blob(gsb, gsb->acr_unload_blob,
&gsb->acr_unload_bl_desc);
for (i = 0; i < NVKM_SECBOOT_FALCON_END; i++)
gsb->falcon_state[i] = NON_SECURE;
return ret;
}
void *
gm200_secboot_dtor(struct nvkm_secboot *sb)
{
struct gm200_secboot *gsb = gm200_secboot(sb);
nvkm_gpuobj_del(&gsb->acr_unload_blob);
kfree(gsb->hsbl_blob);
nvkm_gpuobj_del(&gsb->acr_load_blob);
nvkm_gpuobj_del(&gsb->ls_blob);
nvkm_vm_ref(NULL, &gsb->vm, gsb->pgd);
nvkm_gpuobj_del(&gsb->pgd);
nvkm_gpuobj_del(&gsb->inst);
return gsb;
}
static void
gm200_secboot_fixup_bl_desc(const struct gm200_flcn_bl_desc *desc, void *ret)
{
memcpy(ret, desc, sizeof(*desc));
}
static void
gm200_secboot_fixup_hs_desc(struct gm200_secboot *gsb,
struct hsflcn_acr_desc *desc)
{
desc->ucode_blob_base = gsb->ls_blob->addr;
desc->ucode_blob_size = gsb->ls_blob->size;
desc->wpr_offset = 0;
desc->wpr_region_id = 1;
desc->regions.no_regions = 1;
desc->regions.region_props[0].region_id = 1;
desc->regions.region_props[0].start_addr = gsb->wpr_addr >> 8;
desc->regions.region_props[0].end_addr =
(gsb->wpr_addr + gsb->wpr_size) >> 8;
}
int
gm200_secboot_new(struct nvkm_device *device, int index,
struct nvkm_secboot **psb)
{
int ret;
struct gm200_secboot *gsb;
gsb = kzalloc(sizeof(*gsb), GFP_KERNEL);
if (!gsb) {
psb = NULL;
return -ENOMEM;
}
*psb = &gsb->base;
ret = nvkm_secboot_ctor(&gm200_secboot, device, index, &gsb->base);
if (ret)
return ret;
gsb->func = &gm200_secboot_func;
return 0;
}
