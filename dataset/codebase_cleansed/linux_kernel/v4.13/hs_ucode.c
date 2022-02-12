static void
hs_ucode_patch_signature(const struct nvkm_falcon *falcon, void *acr_image,
bool new_format)
{
struct fw_bin_header *hsbin_hdr = acr_image;
struct hsf_fw_header *fw_hdr = acr_image + hsbin_hdr->header_offset;
void *hs_data = acr_image + hsbin_hdr->data_offset;
void *sig;
u32 sig_size;
u32 patch_loc, patch_sig;
if (new_format) {
patch_loc = fw_hdr->patch_loc;
patch_sig = fw_hdr->patch_sig;
} else {
patch_loc = *(u32 *)(acr_image + fw_hdr->patch_loc);
patch_sig = *(u32 *)(acr_image + fw_hdr->patch_sig);
}
if (falcon->debug) {
sig = acr_image + fw_hdr->sig_dbg_offset;
sig_size = fw_hdr->sig_dbg_size;
} else {
sig = acr_image + fw_hdr->sig_prod_offset;
sig_size = fw_hdr->sig_prod_size;
}
memcpy(hs_data + patch_loc, sig + patch_sig, sig_size);
}
void *
hs_ucode_load_blob(struct nvkm_subdev *subdev, const struct nvkm_falcon *falcon,
const char *fw)
{
void *acr_image;
bool new_format;
acr_image = nvkm_acr_load_firmware(subdev, fw, 0);
if (IS_ERR(acr_image))
return acr_image;
switch (((u32 *)acr_image)[0]) {
case 0x3b1d14f0:
new_format = true;
break;
case 0x000010de:
new_format = false;
break;
default:
nvkm_error(subdev, "unknown header for HS blob %s\n", fw);
return ERR_PTR(-EINVAL);
}
hs_ucode_patch_signature(falcon, acr_image, new_format);
return acr_image;
}
