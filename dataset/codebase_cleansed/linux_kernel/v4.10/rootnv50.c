int
nv50_disp_root_scanoutpos(NV50_DISP_MTHD_V0)
{
struct nvkm_device *device = disp->base.engine.subdev.device;
const u32 blanke = nvkm_rd32(device, 0x610aec + (head * 0x540));
const u32 blanks = nvkm_rd32(device, 0x610af4 + (head * 0x540));
const u32 total = nvkm_rd32(device, 0x610afc + (head * 0x540));
union {
struct nv50_disp_scanoutpos_v0 v0;
} *args = data;
int ret = -ENOSYS;
nvif_ioctl(object, "disp scanoutpos size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(object, "disp scanoutpos vers %d\n",
args->v0.version);
args->v0.vblanke = (blanke & 0xffff0000) >> 16;
args->v0.hblanke = (blanke & 0x0000ffff);
args->v0.vblanks = (blanks & 0xffff0000) >> 16;
args->v0.hblanks = (blanks & 0x0000ffff);
args->v0.vtotal = ( total & 0xffff0000) >> 16;
args->v0.htotal = ( total & 0x0000ffff);
args->v0.time[0] = ktime_to_ns(ktime_get());
args->v0.vline =
nvkm_rd32(device, 0x616340 + (head * 0x800)) & 0xffff;
args->v0.time[1] = ktime_to_ns(ktime_get());
args->v0.hline =
nvkm_rd32(device, 0x616344 + (head * 0x800)) & 0xffff;
} else
return ret;
return 0;
}
static int
nv50_disp_root_mthd_(struct nvkm_object *object, u32 mthd, void *data, u32 size)
{
union {
struct nv50_disp_mthd_v0 v0;
struct nv50_disp_mthd_v1 v1;
} *args = data;
struct nv50_disp_root *root = nv50_disp_root(object);
struct nv50_disp *disp = root->disp;
const struct nv50_disp_func *func = disp->func;
struct nvkm_output *outp = NULL;
struct nvkm_output *temp;
u16 type, mask = 0;
int head, ret = -ENOSYS;
if (mthd != NV50_DISP_MTHD)
return -EINVAL;
nvif_ioctl(object, "disp mthd size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, true))) {
nvif_ioctl(object, "disp mthd vers %d mthd %02x head %d\n",
args->v0.version, args->v0.method, args->v0.head);
mthd = args->v0.method;
head = args->v0.head;
} else
if (!(ret = nvif_unpack(ret, &data, &size, args->v1, 1, 1, true))) {
nvif_ioctl(object, "disp mthd vers %d mthd %02x "
"type %04x mask %04x\n",
args->v1.version, args->v1.method,
args->v1.hasht, args->v1.hashm);
mthd = args->v1.method;
type = args->v1.hasht;
mask = args->v1.hashm;
head = ffs((mask >> 8) & 0x0f) - 1;
} else
return ret;
if (head < 0 || head >= disp->base.head.nr)
return -ENXIO;
if (mask) {
list_for_each_entry(temp, &disp->base.outp, head) {
if ((temp->info.hasht == type) &&
(temp->info.hashm & mask) == mask) {
outp = temp;
break;
}
}
if (outp == NULL)
return -ENXIO;
}
switch (mthd) {
case NV50_DISP_SCANOUTPOS:
return func->head.scanoutpos(object, disp, data, size, head);
default:
break;
}
switch (mthd * !!outp) {
case NV50_DISP_MTHD_V1_DAC_PWR:
return func->dac.power(object, disp, data, size, head, outp);
case NV50_DISP_MTHD_V1_DAC_LOAD:
return func->dac.sense(object, disp, data, size, head, outp);
case NV50_DISP_MTHD_V1_SOR_PWR:
return func->sor.power(object, disp, data, size, head, outp);
case NV50_DISP_MTHD_V1_SOR_HDA_ELD:
if (!func->sor.hda_eld)
return -ENODEV;
return func->sor.hda_eld(object, disp, data, size, head, outp);
case NV50_DISP_MTHD_V1_SOR_HDMI_PWR:
if (!func->sor.hdmi)
return -ENODEV;
return func->sor.hdmi(object, disp, data, size, head, outp);
case NV50_DISP_MTHD_V1_SOR_LVDS_SCRIPT: {
union {
struct nv50_disp_sor_lvds_script_v0 v0;
} *args = data;
int ret = -ENOSYS;
nvif_ioctl(object, "disp sor lvds script size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(object, "disp sor lvds script "
"vers %d name %04x\n",
args->v0.version, args->v0.script);
disp->sor.lvdsconf = args->v0.script;
return 0;
} else
return ret;
}
break;
case NV50_DISP_MTHD_V1_SOR_DP_PWR: {
struct nvkm_output_dp *outpdp = nvkm_output_dp(outp);
union {
struct nv50_disp_sor_dp_pwr_v0 v0;
} *args = data;
int ret = -ENOSYS;
nvif_ioctl(object, "disp sor dp pwr size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(object, "disp sor dp pwr vers %d state %d\n",
args->v0.version, args->v0.state);
if (args->v0.state == 0) {
nvkm_notify_put(&outpdp->irq);
outpdp->func->lnk_pwr(outpdp, 0);
atomic_set(&outpdp->lt.done, 0);
return 0;
} else
if (args->v0.state != 0) {
nvkm_output_dp_train(&outpdp->base, 0);
return 0;
}
} else
return ret;
}
break;
case NV50_DISP_MTHD_V1_SOR_DP_MST_LINK: {
struct nvkm_output_dp *outpdp = nvkm_output_dp(outp);
union {
struct nv50_disp_sor_dp_mst_link_v0 v0;
} *args = data;
int ret = -ENOSYS;
nvif_ioctl(object, "disp sor dp mst link size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(object, "disp sor dp mst link vers %d state %d\n",
args->v0.version, args->v0.state);
if (outpdp->lt.mst != !!args->v0.state) {
outpdp->lt.mst = !!args->v0.state;
atomic_set(&outpdp->lt.done, 0);
nvkm_output_dp_train(&outpdp->base, 0);
}
return 0;
} else
return ret;
}
break;
case NV50_DISP_MTHD_V1_SOR_DP_MST_VCPI: {
struct nvkm_output_dp *outpdp = nvkm_output_dp(outp);
union {
struct nv50_disp_sor_dp_mst_vcpi_v0 v0;
} *args = data;
int ret = -ENOSYS;
nvif_ioctl(object, "disp sor dp mst vcpi size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(object, "disp sor dp mst vcpi vers %d "
"slot %02x/%02x pbn %04x/%04x\n",
args->v0.version, args->v0.start_slot,
args->v0.num_slots, args->v0.pbn,
args->v0.aligned_pbn);
if (!outpdp->func->vcpi)
return -ENODEV;
outpdp->func->vcpi(outpdp, head, args->v0.start_slot,
args->v0.num_slots, args->v0.pbn,
args->v0.aligned_pbn);
return 0;
} else
return ret;
}
break;
case NV50_DISP_MTHD_V1_PIOR_PWR:
if (!func->pior.power)
return -ENODEV;
return func->pior.power(object, disp, data, size, head, outp);
default:
break;
}
return -EINVAL;
}
static int
nv50_disp_root_dmac_new_(const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
const struct nv50_disp_dmac_oclass *sclass = oclass->priv;
struct nv50_disp_root *root = nv50_disp_root(oclass->parent);
return sclass->ctor(sclass->func, sclass->mthd, root, sclass->chid,
oclass, data, size, pobject);
}
static int
nv50_disp_root_pioc_new_(const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
const struct nv50_disp_pioc_oclass *sclass = oclass->priv;
struct nv50_disp_root *root = nv50_disp_root(oclass->parent);
return sclass->ctor(sclass->func, sclass->mthd, root, sclass->chid.ctrl,
sclass->chid.user, oclass, data, size, pobject);
}
static int
nv50_disp_root_child_get_(struct nvkm_object *object, int index,
struct nvkm_oclass *sclass)
{
struct nv50_disp_root *root = nv50_disp_root(object);
if (index < ARRAY_SIZE(root->func->dmac)) {
sclass->base = root->func->dmac[index]->base;
sclass->priv = root->func->dmac[index];
sclass->ctor = nv50_disp_root_dmac_new_;
return 0;
}
index -= ARRAY_SIZE(root->func->dmac);
if (index < ARRAY_SIZE(root->func->pioc)) {
sclass->base = root->func->pioc[index]->base;
sclass->priv = root->func->pioc[index];
sclass->ctor = nv50_disp_root_pioc_new_;
return 0;
}
return -EINVAL;
}
static int
nv50_disp_root_fini_(struct nvkm_object *object, bool suspend)
{
struct nv50_disp_root *root = nv50_disp_root(object);
root->func->fini(root);
return 0;
}
static int
nv50_disp_root_init_(struct nvkm_object *object)
{
struct nv50_disp_root *root = nv50_disp_root(object);
return root->func->init(root);
}
static void *
nv50_disp_root_dtor_(struct nvkm_object *object)
{
struct nv50_disp_root *root = nv50_disp_root(object);
nvkm_ramht_del(&root->ramht);
nvkm_gpuobj_del(&root->instmem);
return root;
}
int
nv50_disp_root_new_(const struct nv50_disp_root_func *func,
struct nvkm_disp *base, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
struct nv50_disp *disp = nv50_disp(base);
struct nv50_disp_root *root;
struct nvkm_device *device = disp->base.engine.subdev.device;
int ret;
if (!(root = kzalloc(sizeof(*root), GFP_KERNEL)))
return -ENOMEM;
*pobject = &root->object;
nvkm_object_ctor(&nv50_disp_root_, oclass, &root->object);
root->func = func;
root->disp = disp;
ret = nvkm_gpuobj_new(disp->base.engine.subdev.device, 0x10000, 0x10000,
false, NULL, &root->instmem);
if (ret)
return ret;
return nvkm_ramht_new(device, 0x1000, 0, root->instmem, &root->ramht);
}
void
nv50_disp_root_fini(struct nv50_disp_root *root)
{
struct nvkm_device *device = root->disp->base.engine.subdev.device;
nvkm_wr32(device, 0x610024, 0x00000000);
nvkm_wr32(device, 0x610020, 0x00000000);
}
int
nv50_disp_root_init(struct nv50_disp_root *root)
{
struct nv50_disp *disp = root->disp;
struct nvkm_device *device = disp->base.engine.subdev.device;
u32 tmp;
int i;
tmp = nvkm_rd32(device, 0x614004);
nvkm_wr32(device, 0x610184, tmp);
for (i = 0; i < disp->base.head.nr; i++) {
tmp = nvkm_rd32(device, 0x616100 + (i * 0x800));
nvkm_wr32(device, 0x610190 + (i * 0x10), tmp);
tmp = nvkm_rd32(device, 0x616104 + (i * 0x800));
nvkm_wr32(device, 0x610194 + (i * 0x10), tmp);
tmp = nvkm_rd32(device, 0x616108 + (i * 0x800));
nvkm_wr32(device, 0x610198 + (i * 0x10), tmp);
tmp = nvkm_rd32(device, 0x61610c + (i * 0x800));
nvkm_wr32(device, 0x61019c + (i * 0x10), tmp);
}
for (i = 0; i < disp->func->dac.nr; i++) {
tmp = nvkm_rd32(device, 0x61a000 + (i * 0x800));
nvkm_wr32(device, 0x6101d0 + (i * 0x04), tmp);
}
for (i = 0; i < disp->func->sor.nr; i++) {
tmp = nvkm_rd32(device, 0x61c000 + (i * 0x800));
nvkm_wr32(device, 0x6101e0 + (i * 0x04), tmp);
}
for (i = 0; i < disp->func->pior.nr; i++) {
tmp = nvkm_rd32(device, 0x61e000 + (i * 0x800));
nvkm_wr32(device, 0x6101f0 + (i * 0x04), tmp);
}
if (nvkm_rd32(device, 0x610024) & 0x00000100) {
nvkm_wr32(device, 0x610024, 0x00000100);
nvkm_mask(device, 0x6194e8, 0x00000001, 0x00000000);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x6194e8) & 0x00000002))
break;
) < 0)
return -EBUSY;
}
nvkm_wr32(device, 0x610010, (root->instmem->addr >> 8) | 9);
nvkm_wr32(device, 0x61002c, 0x00000370);
nvkm_wr32(device, 0x610028, 0x00000000);
return 0;
}
static int
nv50_disp_root_new(struct nvkm_disp *disp, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
return nv50_disp_root_new_(&nv50_disp_root, disp, oclass,
data, size, pobject);
}
