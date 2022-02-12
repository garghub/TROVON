struct ls_ucode_img *
acr_r367_ls_ucode_img_load(const struct acr_r352 *acr,
const struct nvkm_secboot *sb,
enum nvkm_secboot_falcon falcon_id)
{
const struct nvkm_subdev *subdev = acr->base.subdev;
struct ls_ucode_img_r367 *img;
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
acr_r367_ls_img_fill_headers(struct acr_r352 *acr,
struct ls_ucode_img_r367 *img, u32 offset)
{
struct ls_ucode_img *_img = &img->base;
struct acr_r367_lsf_wpr_header *whdr = &img->wpr_header;
struct acr_r367_lsf_lsb_header *lhdr = &img->lsb_header;
struct ls_ucode_img_desc *desc = &_img->ucode_desc;
const struct acr_r352_ls_func *func =
acr->func->ls_func[_img->falcon_id];
whdr->falcon_id = _img->falcon_id;
whdr->bootstrap_owner = acr->base.boot_falcon;
whdr->bin_version = lhdr->signature.version;
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
acr_r367_ls_fill_headers(struct acr_r352 *acr, struct list_head *imgs)
{
struct ls_ucode_img_r367 *img;
struct list_head *l;
u32 count = 0;
u32 offset;
list_for_each(l, imgs)
count++;
offset = sizeof(img->wpr_header) * (count + 1);
list_for_each_entry(img, imgs, base.node) {
offset = acr_r367_ls_img_fill_headers(acr, img, offset);
}
return offset;
}
int
acr_r367_ls_write_wpr(struct acr_r352 *acr, struct list_head *imgs,
struct nvkm_gpuobj *wpr_blob, u64 wpr_addr)
{
struct ls_ucode_img *_img;
u32 pos = 0;
nvkm_kmap(wpr_blob);
list_for_each_entry(_img, imgs, node) {
struct ls_ucode_img_r367 *img = ls_ucode_img_r367(_img);
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
void
acr_r367_fixup_hs_desc(struct acr_r352 *acr, struct nvkm_secboot *sb,
void *_desc)
{
struct acr_r367_hsflcn_desc *desc = _desc;
struct nvkm_gpuobj *ls_blob = acr->ls_blob;
if (sb->wpr_size == 0) {
u64 wpr_start = ls_blob->addr;
u64 wpr_end = ls_blob->addr + ls_blob->size;
if (acr->func->shadow_blob)
wpr_start += ls_blob->size / 2;
desc->wpr_region_id = 1;
desc->regions.no_regions = 2;
desc->regions.region_props[0].start_addr = wpr_start >> 8;
desc->regions.region_props[0].end_addr = wpr_end >> 8;
desc->regions.region_props[0].region_id = 1;
desc->regions.region_props[0].read_mask = 0xf;
desc->regions.region_props[0].write_mask = 0xc;
desc->regions.region_props[0].client_mask = 0x2;
if (acr->func->shadow_blob)
desc->regions.region_props[0].shadow_mem_start_addr =
ls_blob->addr >> 8;
else
desc->regions.region_props[0].shadow_mem_start_addr = 0;
} else {
desc->ucode_blob_base = ls_blob->addr;
desc->ucode_blob_size = ls_blob->size;
}
}
struct nvkm_acr *
acr_r367_new(enum nvkm_secboot_falcon boot_falcon,
unsigned long managed_falcons)
{
return acr_r352_new_(&acr_r367_func, boot_falcon, managed_falcons);
}
