int
gm200_secboot_run_blob(struct nvkm_secboot *sb, struct nvkm_gpuobj *blob,
struct nvkm_falcon *falcon)
{
struct gm200_secboot *gsb = gm200_secboot(sb);
struct nvkm_subdev *subdev = &gsb->base.subdev;
struct nvkm_vma vma;
u32 start_address;
int ret;
ret = nvkm_falcon_get(falcon, subdev);
if (ret)
return ret;
ret = nvkm_gpuobj_map(blob, gsb->vm, NV_MEM_ACCESS_RW, &vma);
if (ret) {
nvkm_falcon_put(falcon, subdev);
return ret;
}
ret = nvkm_falcon_reset(falcon);
if (ret)
goto end;
nvkm_falcon_bind_context(falcon, gsb->inst);
ret = sb->acr->func->load(sb->acr, falcon, blob, vma.offset);
if (ret < 0)
goto end;
start_address = ret;
nvkm_mc_intr_mask(sb->subdev.device, falcon->owner->index, false);
nvkm_falcon_wr32(falcon, 0x040, 0xdeada5a5);
nvkm_falcon_set_start_addr(falcon, start_address);
nvkm_falcon_start(falcon);
ret = nvkm_falcon_wait_for_halt(falcon, 100);
if (ret)
goto end;
ret = nvkm_falcon_rd32(falcon, 0x040);
end:
nvkm_mc_intr_mask(sb->subdev.device, falcon->owner->index, true);
nvkm_gpuobj_unmap(&vma);
nvkm_falcon_put(falcon, subdev);
return ret;
}
int
gm200_secboot_oneinit(struct nvkm_secboot *sb)
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
if (sb->acr->func->oneinit) {
ret = sb->acr->func->oneinit(sb->acr, sb);
if (ret)
return ret;
}
return 0;
}
int
gm200_secboot_fini(struct nvkm_secboot *sb, bool suspend)
{
int ret = 0;
if (sb->acr->func->fini)
ret = sb->acr->func->fini(sb->acr, sb, suspend);
return ret;
}
void *
gm200_secboot_dtor(struct nvkm_secboot *sb)
{
struct gm200_secboot *gsb = gm200_secboot(sb);
sb->acr->func->dtor(sb->acr);
nvkm_vm_ref(NULL, &gsb->vm, gsb->pgd);
nvkm_gpuobj_del(&gsb->pgd);
nvkm_gpuobj_del(&gsb->inst);
return gsb;
}
int
gm200_secboot_new(struct nvkm_device *device, int index,
struct nvkm_secboot **psb)
{
int ret;
struct gm200_secboot *gsb;
struct nvkm_acr *acr;
acr = acr_r361_new(BIT(NVKM_SECBOOT_FALCON_FECS) |
BIT(NVKM_SECBOOT_FALCON_GPCCS));
if (IS_ERR(acr))
return PTR_ERR(acr);
gsb = kzalloc(sizeof(*gsb), GFP_KERNEL);
if (!gsb) {
psb = NULL;
return -ENOMEM;
}
*psb = &gsb->base;
ret = nvkm_secboot_ctor(&gm200_secboot, acr, device, index, &gsb->base);
if (ret)
return ret;
return 0;
}
