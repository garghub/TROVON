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
ls_ucode_img_load_gr(const struct nvkm_subdev *subdev, struct ls_ucode_img *img,
const char *falcon_name)
{
const struct firmware *bl, *code, *data, *sig;
char f[64];
int ret;
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
snprintf(f, sizeof(f), "gr/%s_sig", falcon_name);
ret = nvkm_firmware_get(subdev->device, f, &sig);
if (ret)
goto free_data;
img->sig = kmemdup(sig->data, sig->size, GFP_KERNEL);
if (!img->sig) {
ret = -ENOMEM;
goto free_sig;
}
img->sig_size = sig->size;
img->ucode_data = ls_ucode_img_build(bl, code, data,
&img->ucode_desc);
if (IS_ERR(img->ucode_data)) {
kfree(img->sig);
ret = PTR_ERR(img->ucode_data);
goto free_sig;
}
img->ucode_size = img->ucode_desc.image_size;
free_sig:
nvkm_firmware_put(sig);
free_data:
nvkm_firmware_put(data);
free_inst:
nvkm_firmware_put(code);
free_bl:
nvkm_firmware_put(bl);
error:
return ret;
}
int
acr_ls_ucode_load_fecs(const struct nvkm_secboot *sb, struct ls_ucode_img *img)
{
return ls_ucode_img_load_gr(&sb->subdev, img, "fecs");
}
int
acr_ls_ucode_load_gpccs(const struct nvkm_secboot *sb, struct ls_ucode_img *img)
{
return ls_ucode_img_load_gr(&sb->subdev, img, "gpccs");
}
