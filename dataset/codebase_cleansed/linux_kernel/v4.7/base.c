int
nvkm_ltc_tags_alloc(struct nvkm_ltc *ltc, u32 n, struct nvkm_mm_node **pnode)
{
int ret = nvkm_mm_head(&ltc->tags, 0, 1, n, n, 1, pnode);
if (ret)
*pnode = NULL;
return ret;
}
void
nvkm_ltc_tags_free(struct nvkm_ltc *ltc, struct nvkm_mm_node **pnode)
{
nvkm_mm_free(&ltc->tags, pnode);
}
void
nvkm_ltc_tags_clear(struct nvkm_ltc *ltc, u32 first, u32 count)
{
const u32 limit = first + count - 1;
BUG_ON((first > limit) || (limit >= ltc->num_tags));
ltc->func->cbc_clear(ltc, first, limit);
ltc->func->cbc_wait(ltc);
}
int
nvkm_ltc_zbc_color_get(struct nvkm_ltc *ltc, int index, const u32 color[4])
{
memcpy(ltc->zbc_color[index], color, sizeof(ltc->zbc_color[index]));
ltc->func->zbc_clear_color(ltc, index, color);
return index;
}
int
nvkm_ltc_zbc_depth_get(struct nvkm_ltc *ltc, int index, const u32 depth)
{
ltc->zbc_depth[index] = depth;
ltc->func->zbc_clear_depth(ltc, index, depth);
return index;
}
void
nvkm_ltc_invalidate(struct nvkm_ltc *ltc)
{
if (ltc->func->invalidate)
ltc->func->invalidate(ltc);
}
void
nvkm_ltc_flush(struct nvkm_ltc *ltc)
{
if (ltc->func->flush)
ltc->func->flush(ltc);
}
static void
nvkm_ltc_intr(struct nvkm_subdev *subdev)
{
struct nvkm_ltc *ltc = nvkm_ltc(subdev);
ltc->func->intr(ltc);
}
static int
nvkm_ltc_oneinit(struct nvkm_subdev *subdev)
{
struct nvkm_ltc *ltc = nvkm_ltc(subdev);
return ltc->func->oneinit(ltc);
}
static int
nvkm_ltc_init(struct nvkm_subdev *subdev)
{
struct nvkm_ltc *ltc = nvkm_ltc(subdev);
int i;
for (i = ltc->zbc_min; i <= ltc->zbc_max; i++) {
ltc->func->zbc_clear_color(ltc, i, ltc->zbc_color[i]);
ltc->func->zbc_clear_depth(ltc, i, ltc->zbc_depth[i]);
}
ltc->func->init(ltc);
return 0;
}
static void *
nvkm_ltc_dtor(struct nvkm_subdev *subdev)
{
struct nvkm_ltc *ltc = nvkm_ltc(subdev);
struct nvkm_ram *ram = ltc->subdev.device->fb->ram;
nvkm_mm_fini(&ltc->tags);
if (ram)
nvkm_mm_free(&ram->vram, &ltc->tag_ram);
return ltc;
}
int
nvkm_ltc_new_(const struct nvkm_ltc_func *func, struct nvkm_device *device,
int index, struct nvkm_ltc **pltc)
{
struct nvkm_ltc *ltc;
if (!(ltc = *pltc = kzalloc(sizeof(*ltc), GFP_KERNEL)))
return -ENOMEM;
nvkm_subdev_ctor(&nvkm_ltc, device, index, &ltc->subdev);
ltc->func = func;
ltc->zbc_min = 1;
ltc->zbc_max = min(func->zbc, NVKM_LTC_MAX_ZBC_CNT) - 1;
return 0;
}
