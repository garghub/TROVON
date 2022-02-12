static int
nvkm_control_mthd_pstate_info(struct nvkm_control *ctrl, void *data, u32 size)
{
union {
struct nvif_control_pstate_info_v0 v0;
} *args = data;
struct nvkm_clk *clk = ctrl->device->clk;
int ret;
nvif_ioctl(&ctrl->object, "control pstate info size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, false)) {
nvif_ioctl(&ctrl->object, "control pstate info vers %d\n",
args->v0.version);
} else
return ret;
if (clk) {
args->v0.count = clk->state_nr;
args->v0.ustate_ac = clk->ustate_ac;
args->v0.ustate_dc = clk->ustate_dc;
args->v0.pwrsrc = clk->pwrsrc;
args->v0.pstate = clk->pstate;
} else {
args->v0.count = 0;
args->v0.ustate_ac = NVIF_CONTROL_PSTATE_INFO_V0_USTATE_DISABLE;
args->v0.ustate_dc = NVIF_CONTROL_PSTATE_INFO_V0_USTATE_DISABLE;
args->v0.pwrsrc = -ENOSYS;
args->v0.pstate = NVIF_CONTROL_PSTATE_INFO_V0_PSTATE_UNKNOWN;
}
return 0;
}
static int
nvkm_control_mthd_pstate_attr(struct nvkm_control *ctrl, void *data, u32 size)
{
union {
struct nvif_control_pstate_attr_v0 v0;
} *args = data;
struct nvkm_clk *clk = ctrl->device->clk;
const struct nvkm_domain *domain;
struct nvkm_pstate *pstate;
struct nvkm_cstate *cstate;
int i = 0, j = -1;
u32 lo, hi;
int ret;
nvif_ioctl(&ctrl->object, "control pstate attr size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, false)) {
nvif_ioctl(&ctrl->object,
"control pstate attr vers %d state %d index %d\n",
args->v0.version, args->v0.state, args->v0.index);
if (!clk)
return -ENODEV;
if (args->v0.state < NVIF_CONTROL_PSTATE_ATTR_V0_STATE_CURRENT)
return -EINVAL;
if (args->v0.state >= clk->state_nr)
return -EINVAL;
} else
return ret;
domain = clk->domains;
while (domain->name != nv_clk_src_max) {
if (domain->mname && ++j == args->v0.index)
break;
domain++;
}
if (domain->name == nv_clk_src_max)
return -EINVAL;
if (args->v0.state != NVIF_CONTROL_PSTATE_ATTR_V0_STATE_CURRENT) {
list_for_each_entry(pstate, &clk->states, head) {
if (i++ == args->v0.state)
break;
}
lo = pstate->base.domain[domain->name];
hi = lo;
list_for_each_entry(cstate, &pstate->list, head) {
lo = min(lo, cstate->domain[domain->name]);
hi = max(hi, cstate->domain[domain->name]);
}
args->v0.state = pstate->pstate;
} else {
lo = max(nvkm_clk_read(clk, domain->name), 0);
hi = lo;
}
snprintf(args->v0.name, sizeof(args->v0.name), "%s", domain->mname);
snprintf(args->v0.unit, sizeof(args->v0.unit), "MHz");
args->v0.min = lo / domain->mdiv;
args->v0.max = hi / domain->mdiv;
args->v0.index = 0;
while ((++domain)->name != nv_clk_src_max) {
if (domain->mname) {
args->v0.index = ++j;
break;
}
}
return 0;
}
static int
nvkm_control_mthd_pstate_user(struct nvkm_control *ctrl, void *data, u32 size)
{
union {
struct nvif_control_pstate_user_v0 v0;
} *args = data;
struct nvkm_clk *clk = ctrl->device->clk;
int ret;
nvif_ioctl(&ctrl->object, "control pstate user size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, false)) {
nvif_ioctl(&ctrl->object,
"control pstate user vers %d ustate %d pwrsrc %d\n",
args->v0.version, args->v0.ustate, args->v0.pwrsrc);
if (!clk)
return -ENODEV;
} else
return ret;
if (args->v0.pwrsrc >= 0) {
ret |= nvkm_clk_ustate(clk, args->v0.ustate, args->v0.pwrsrc);
} else {
ret |= nvkm_clk_ustate(clk, args->v0.ustate, 0);
ret |= nvkm_clk_ustate(clk, args->v0.ustate, 1);
}
return ret;
}
static int
nvkm_control_mthd(struct nvkm_object *object, u32 mthd, void *data, u32 size)
{
struct nvkm_control *ctrl = nvkm_control(object);
switch (mthd) {
case NVIF_CONTROL_PSTATE_INFO:
return nvkm_control_mthd_pstate_info(ctrl, data, size);
case NVIF_CONTROL_PSTATE_ATTR:
return nvkm_control_mthd_pstate_attr(ctrl, data, size);
case NVIF_CONTROL_PSTATE_USER:
return nvkm_control_mthd_pstate_user(ctrl, data, size);
default:
break;
}
return -EINVAL;
}
static int
nvkm_control_new(struct nvkm_device *device, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
struct nvkm_control *ctrl;
if (!(ctrl = kzalloc(sizeof(*ctrl), GFP_KERNEL)))
return -ENOMEM;
*pobject = &ctrl->object;
ctrl->device = device;
nvkm_object_ctor(&nvkm_control, oclass, &ctrl->object);
return 0;
}
