static void
acr_r364_fixup_hs_desc(struct acr_r352 *acr, struct nvkm_secboot *sb,
void *_desc)
{
struct acr_r364_hsflcn_desc *desc = _desc;
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
acr_r364_new(unsigned long managed_falcons)
{
return acr_r352_new_(&acr_r364_func, NVKM_SECBOOT_FALCON_PMU,
managed_falcons);
}
