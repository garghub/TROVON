static int
gm20b_secboot_prepare_blobs(struct gm200_secboot *gsb)
{
struct nvkm_subdev *subdev = &gsb->base.subdev;
int acr_size;
int ret;
ret = gm20x_secboot_prepare_blobs(gsb);
if (ret)
return ret;
acr_size = gsb->acr_load_blob->size;
if (acr_size > gsb->wpr_size) {
nvkm_error(subdev, "WPR region too small for FW blob!\n");
nvkm_error(subdev, "required: %dB\n", acr_size);
nvkm_error(subdev, "WPR size: %dB\n", gsb->wpr_size);
return -ENOSPC;
}
return 0;
}
static void
gm20b_secboot_fixup_bl_desc(const struct gm200_flcn_bl_desc *desc, void *ret)
{
struct gm20b_flcn_bl_desc *gdesc = ret;
u64 addr;
memcpy(gdesc->reserved, desc->reserved, sizeof(gdesc->reserved));
memcpy(gdesc->signature, desc->signature, sizeof(gdesc->signature));
gdesc->ctx_dma = desc->ctx_dma;
addr = desc->code_dma_base.hi;
addr <<= 32;
addr |= desc->code_dma_base.lo;
gdesc->code_dma_base = lower_32_bits(addr >> 8);
gdesc->non_sec_code_off = desc->non_sec_code_off;
gdesc->non_sec_code_size = desc->non_sec_code_size;
gdesc->sec_code_off = desc->sec_code_off;
gdesc->sec_code_size = desc->sec_code_size;
gdesc->code_entry_point = desc->code_entry_point;
addr = desc->data_dma_base.hi;
addr <<= 32;
addr |= desc->data_dma_base.lo;
gdesc->data_dma_base = lower_32_bits(addr >> 8);
gdesc->data_size = desc->data_size;
}
static void
gm20b_secboot_fixup_hs_desc(struct gm200_secboot *gsb,
struct hsflcn_acr_desc *desc)
{
desc->ucode_blob_base = gsb->ls_blob->addr;
desc->ucode_blob_size = gsb->ls_blob->size;
desc->wpr_offset = 0;
}
static int
gm20b_tegra_read_wpr(struct gm200_secboot *gsb)
{
struct nvkm_secboot *sb = &gsb->base;
void __iomem *mc;
u32 cfg;
mc = ioremap(TEGRA_MC_BASE, 0xd00);
if (!mc) {
nvkm_error(&sb->subdev, "Cannot map Tegra MC registers\n");
return PTR_ERR(mc);
}
gsb->wpr_addr = ioread32_native(mc + MC_SECURITY_CARVEOUT2_BOM_0) |
((u64)ioread32_native(mc + MC_SECURITY_CARVEOUT2_BOM_HI_0) << 32);
gsb->wpr_size = ioread32_native(mc + MC_SECURITY_CARVEOUT2_SIZE_128K)
<< 17;
cfg = ioread32_native(mc + MC_SECURITY_CARVEOUT2_CFG0);
iounmap(mc);
if (gsb->wpr_size == 0) {
nvkm_error(&sb->subdev, "WPR region is empty\n");
return -EINVAL;
}
if (!(cfg & TEGRA_MC_SECURITY_CARVEOUT_CFG_LOCKED)) {
nvkm_error(&sb->subdev, "WPR region not locked\n");
return -EINVAL;
}
return 0;
}
static int
gm20b_tegra_read_wpr(struct gm200_secboot *gsb)
{
nvkm_error(&gsb->base.subdev, "Tegra support not compiled in\n");
return -EINVAL;
}
static int
gm20b_secboot_init(struct nvkm_secboot *sb)
{
struct gm200_secboot *gsb = gm200_secboot(sb);
int ret;
ret = gm20b_tegra_read_wpr(gsb);
if (ret)
return ret;
return gm200_secboot_init(sb);
}
int
gm20b_secboot_new(struct nvkm_device *device, int index,
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
ret = nvkm_secboot_ctor(&gm20b_secboot, device, index, &gsb->base);
if (ret)
return ret;
gsb->func = &gm20b_secboot_func;
return 0;
}
