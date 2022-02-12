static void
acr_r361_generate_flcn_bl_desc(const struct nvkm_acr *acr,
const struct ls_ucode_img *img, u64 wpr_addr,
void *_desc)
{
struct acr_r361_flcn_bl_desc *desc = _desc;
const struct ls_ucode_img_desc *pdesc = &img->ucode_desc;
u64 base, addr_code, addr_data;
base = wpr_addr + img->ucode_off + pdesc->app_start_offset;
addr_code = base + pdesc->app_resident_code_offset;
addr_data = base + pdesc->app_resident_data_offset;
desc->ctx_dma = FALCON_DMAIDX_UCODE;
desc->code_dma_base = u64_to_flcn64(addr_code);
desc->non_sec_code_off = pdesc->app_resident_code_offset;
desc->non_sec_code_size = pdesc->app_resident_code_size;
desc->code_entry_point = pdesc->app_imem_entry;
desc->data_dma_base = u64_to_flcn64(addr_data);
desc->data_size = pdesc->app_resident_data_size;
}
void
acr_r361_generate_hs_bl_desc(const struct hsf_load_header *hdr, void *_bl_desc,
u64 offset)
{
struct acr_r361_flcn_bl_desc *bl_desc = _bl_desc;
bl_desc->ctx_dma = FALCON_DMAIDX_VIRT;
bl_desc->code_dma_base = u64_to_flcn64(offset);
bl_desc->non_sec_code_off = hdr->non_sec_code_off;
bl_desc->non_sec_code_size = hdr->non_sec_code_size;
bl_desc->sec_code_off = hsf_load_header_app_off(hdr, 0);
bl_desc->sec_code_size = hsf_load_header_app_size(hdr, 0);
bl_desc->code_entry_point = 0;
bl_desc->data_dma_base = u64_to_flcn64(offset + hdr->data_dma_base);
bl_desc->data_size = hdr->data_size;
}
static void
acr_r361_generate_pmu_bl_desc(const struct nvkm_acr *acr,
const struct ls_ucode_img *img, u64 wpr_addr,
void *_desc)
{
const struct ls_ucode_img_desc *pdesc = &img->ucode_desc;
const struct nvkm_pmu *pmu = acr->subdev->device->pmu;
struct acr_r361_pmu_bl_desc *desc = _desc;
u64 base, addr_code, addr_data;
u32 addr_args;
base = wpr_addr + img->ucode_off + pdesc->app_start_offset;
addr_code = base + pdesc->app_resident_code_offset;
addr_data = base + pdesc->app_resident_data_offset;
addr_args = pmu->falcon->data.limit;
addr_args -= NVKM_MSGQUEUE_CMDLINE_SIZE;
desc->dma_idx = FALCON_DMAIDX_UCODE;
desc->code_dma_base = u64_to_flcn64(addr_code);
desc->total_code_size = pdesc->app_size;
desc->code_size_to_load = pdesc->app_resident_code_size;
desc->code_entry_point = pdesc->app_imem_entry;
desc->data_dma_base = u64_to_flcn64(addr_data);
desc->data_size = pdesc->app_resident_data_size;
desc->overlay_dma_base = u64_to_flcn64(addr_code);
desc->argc = 1;
desc->argv = addr_args;
}
static void
acr_r361_generate_sec2_bl_desc(const struct nvkm_acr *acr,
const struct ls_ucode_img *img, u64 wpr_addr,
void *_desc)
{
const struct ls_ucode_img_desc *pdesc = &img->ucode_desc;
const struct nvkm_sec2 *sec = acr->subdev->device->sec2;
struct acr_r361_pmu_bl_desc *desc = _desc;
u64 base, addr_code, addr_data;
u32 addr_args;
base = wpr_addr + img->ucode_off + pdesc->app_start_offset;
addr_code = base;
addr_data = base + pdesc->app_resident_data_offset;
addr_args = sec->falcon->data.limit;
addr_args -= NVKM_MSGQUEUE_CMDLINE_SIZE;
desc->dma_idx = FALCON_SEC2_DMAIDX_UCODE;
desc->code_dma_base = u64_to_flcn64(addr_code);
desc->total_code_size = pdesc->app_size;
desc->code_size_to_load = pdesc->app_resident_code_size;
desc->code_entry_point = pdesc->app_imem_entry;
desc->data_dma_base = u64_to_flcn64(addr_data);
desc->data_size = pdesc->app_resident_data_size;
desc->overlay_dma_base = u64_to_flcn64(addr_code);
desc->argc = 1;
desc->argv = 0x01000000;
}
struct nvkm_acr *
acr_r361_new(unsigned long managed_falcons)
{
return acr_r352_new_(&acr_r361_func, NVKM_SECBOOT_FALCON_PMU,
managed_falcons);
}
