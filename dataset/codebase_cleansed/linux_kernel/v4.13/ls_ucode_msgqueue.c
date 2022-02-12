static int
acr_ls_ucode_load_msgqueue(const struct nvkm_subdev *subdev, const char *name,
struct ls_ucode_img *img)
{
const struct firmware *image, *desc, *sig;
char f[64];
int ret;
snprintf(f, sizeof(f), "%s/image", name);
ret = nvkm_firmware_get(subdev->device, f, &image);
if (ret)
return ret;
img->ucode_data = kmemdup(image->data, image->size, GFP_KERNEL);
nvkm_firmware_put(image);
if (!img->ucode_data)
return -ENOMEM;
snprintf(f, sizeof(f), "%s/desc", name);
ret = nvkm_firmware_get(subdev->device, f, &desc);
if (ret)
return ret;
memcpy(&img->ucode_desc, desc->data, sizeof(img->ucode_desc));
img->ucode_size = ALIGN(img->ucode_desc.app_start_offset + img->ucode_desc.app_size, 256);
nvkm_firmware_put(desc);
snprintf(f, sizeof(f), "%s/sig", name);
ret = nvkm_firmware_get(subdev->device, f, &sig);
if (ret)
return ret;
img->sig_size = sig->size;
img->sig = kmemdup(sig->data, sig->size, GFP_KERNEL);
nvkm_firmware_put(sig);
if (!img->sig)
return -ENOMEM;
return 0;
}
static int
acr_ls_msgqueue_post_run(struct nvkm_msgqueue *queue,
struct nvkm_falcon *falcon, u32 addr_args)
{
struct nvkm_device *device = falcon->owner->device;
u32 cmdline_size = NVKM_MSGQUEUE_CMDLINE_SIZE;
u8 buf[cmdline_size];
memset(buf, 0, cmdline_size);
nvkm_msgqueue_write_cmdline(queue, buf);
nvkm_falcon_load_dmem(falcon, buf, addr_args, cmdline_size, 0);
nvkm_msgqueue_reinit(queue);
nvkm_falcon_wr32(falcon, 0x10, 0xff);
nvkm_mc_intr_mask(device, falcon->owner->index, true);
nvkm_falcon_start(falcon);
return 0;
}
int
acr_ls_ucode_load_pmu(const struct nvkm_secboot *sb, struct ls_ucode_img *img)
{
struct nvkm_pmu *pmu = sb->subdev.device->pmu;
int ret;
ret = acr_ls_ucode_load_msgqueue(&sb->subdev, "pmu", img);
if (ret)
return ret;
ret = nvkm_msgqueue_new(img->ucode_desc.app_version, pmu->falcon,
sb, &pmu->queue);
if (ret)
return ret;
return 0;
}
int
acr_ls_pmu_post_run(const struct nvkm_acr *acr, const struct nvkm_secboot *sb)
{
struct nvkm_device *device = sb->subdev.device;
struct nvkm_pmu *pmu = device->pmu;
u32 addr_args = pmu->falcon->data.limit - NVKM_MSGQUEUE_CMDLINE_SIZE;
int ret;
ret = acr_ls_msgqueue_post_run(pmu->queue, pmu->falcon, addr_args);
if (ret)
return ret;
nvkm_debug(&sb->subdev, "%s started\n",
nvkm_secboot_falcon_name[acr->boot_falcon]);
return 0;
}
int
acr_ls_ucode_load_sec2(const struct nvkm_secboot *sb, struct ls_ucode_img *img)
{
struct nvkm_sec2 *sec = sb->subdev.device->sec2;
int ret;
ret = acr_ls_ucode_load_msgqueue(&sb->subdev, "sec2", img);
if (ret)
return ret;
ret = nvkm_msgqueue_new(img->ucode_desc.app_version, sec->falcon,
sb, &sec->queue);
if (ret)
return ret;
return 0;
}
int
acr_ls_sec2_post_run(const struct nvkm_acr *acr, const struct nvkm_secboot *sb)
{
const struct nvkm_subdev *subdev = &sb->subdev;
struct nvkm_device *device = subdev->device;
struct nvkm_sec2 *sec = device->sec2;
const u32 addr_args = 0x01000000;
u32 reg;
int ret;
ret = acr_ls_msgqueue_post_run(sec->queue, sec->falcon, addr_args);
if (ret)
return ret;
nvkm_msec(device, 1,
if ((reg = nvkm_falcon_rd32(sb->boot_falcon, 0x100) & 0x30) != 0)
break;
);
if (reg & BIT(4)) {
nvkm_debug(subdev, "applying workaround for start bug...");
nvkm_falcon_start(sb->boot_falcon);
nvkm_msec(subdev->device, 1,
if ((reg = nvkm_rd32(subdev->device,
sb->boot_falcon->addr + 0x100)
& 0x30) != 0)
break;
);
if (reg & BIT(4)) {
nvkm_error(subdev, "%s failed to start\n",
nvkm_secboot_falcon_name[acr->boot_falcon]);
return -EINVAL;
}
}
nvkm_debug(&sb->subdev, "%s started\n",
nvkm_secboot_falcon_name[acr->boot_falcon]);
return 0;
}
