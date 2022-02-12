static u32
nvkm_ramht_hash(struct nvkm_ramht *ramht, int chid, u32 handle)
{
u32 hash = 0;
while (handle) {
hash ^= (handle & ((1 << ramht->bits) - 1));
handle >>= ramht->bits;
}
hash ^= chid << (ramht->bits - 4);
hash = hash << 3;
return hash;
}
int
nvkm_ramht_insert(struct nvkm_ramht *ramht, int chid, u32 handle, u32 context)
{
struct nvkm_bar *bar = nvkm_bar(ramht);
u32 co, ho;
co = ho = nvkm_ramht_hash(ramht, chid, handle);
do {
if (!nv_ro32(ramht, co + 4)) {
nv_wo32(ramht, co + 0, handle);
nv_wo32(ramht, co + 4, context);
if (bar)
bar->flush(bar);
return co;
}
co += 8;
if (co >= nv_gpuobj(ramht)->size)
co = 0;
} while (co != ho);
return -ENOMEM;
}
void
nvkm_ramht_remove(struct nvkm_ramht *ramht, int cookie)
{
struct nvkm_bar *bar = nvkm_bar(ramht);
nv_wo32(ramht, cookie + 0, 0x00000000);
nv_wo32(ramht, cookie + 4, 0x00000000);
if (bar)
bar->flush(bar);
}
int
nvkm_ramht_new(struct nvkm_object *parent, struct nvkm_object *pargpu,
u32 size, u32 align, struct nvkm_ramht **pramht)
{
struct nvkm_ramht *ramht;
int ret;
ret = nvkm_gpuobj_create(parent, parent->engine ?
&parent->engine->subdev.object : parent,
&nvkm_ramht_oclass, 0, pargpu, size,
align, NVOBJ_FLAG_ZERO_ALLOC, &ramht);
*pramht = ramht;
if (ret)
return ret;
ramht->bits = order_base_2(nv_gpuobj(ramht)->size >> 3);
return 0;
}
