struct nvkm_ior *
nvkm_ior_find(struct nvkm_disp *disp, enum nvkm_ior_type type, int id)
{
struct nvkm_ior *ior;
list_for_each_entry(ior, &disp->ior, head) {
if (ior->type == type && (id < 0 || ior->id == id))
return ior;
}
return NULL;
}
void
nvkm_ior_del(struct nvkm_ior **pior)
{
struct nvkm_ior *ior = *pior;
if (ior) {
IOR_DBG(ior, "dtor");
list_del(&ior->head);
kfree(*pior);
*pior = NULL;
}
}
int
nvkm_ior_new_(const struct nvkm_ior_func *func, struct nvkm_disp *disp,
enum nvkm_ior_type type, int id)
{
struct nvkm_ior *ior;
if (!(ior = kzalloc(sizeof(*ior), GFP_KERNEL)))
return -ENOMEM;
ior->func = func;
ior->disp = disp;
ior->type = type;
ior->id = id;
snprintf(ior->name, sizeof(ior->name), "%s-%d",
nvkm_ior_name[ior->type], ior->id);
list_add_tail(&ior->head, &disp->ior);
IOR_DBG(ior, "ctor");
return 0;
}
