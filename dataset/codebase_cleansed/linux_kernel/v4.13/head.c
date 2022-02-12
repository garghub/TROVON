struct nvkm_head *
nvkm_head_find(struct nvkm_disp *disp, int id)
{
struct nvkm_head *head;
list_for_each_entry(head, &disp->head, head) {
if (head->id == id)
return head;
}
return NULL;
}
int
nvkm_head_mthd_scanoutpos(struct nvkm_object *object,
struct nvkm_head *head, void *data, u32 size)
{
union {
struct nv04_disp_scanoutpos_v0 v0;
} *args = data;
int ret = -ENOSYS;
nvif_ioctl(object, "head scanoutpos size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(object, "head scanoutpos vers %d\n",
args->v0.version);
head->func->state(head, &head->arm);
args->v0.vtotal = head->arm.vtotal;
args->v0.vblanks = head->arm.vblanks;
args->v0.vblanke = head->arm.vblanke;
args->v0.htotal = head->arm.htotal;
args->v0.hblanks = head->arm.hblanks;
args->v0.hblanke = head->arm.hblanke;
if (!args->v0.vtotal || !args->v0.htotal)
return -ENOTSUPP;
args->v0.time[0] = ktime_to_ns(ktime_get());
head->func->rgpos(head, &args->v0.hline, &args->v0.vline);
args->v0.time[1] = ktime_to_ns(ktime_get());
} else
return ret;
return 0;
}
void
nvkm_head_del(struct nvkm_head **phead)
{
struct nvkm_head *head = *phead;
if (head) {
HEAD_DBG(head, "dtor");
list_del(&head->head);
kfree(*phead);
*phead = NULL;
}
}
int
nvkm_head_new_(const struct nvkm_head_func *func,
struct nvkm_disp *disp, int id)
{
struct nvkm_head *head;
if (!(head = kzalloc(sizeof(*head), GFP_KERNEL)))
return -ENOMEM;
head->func = func;
head->disp = disp;
head->id = id;
list_add_tail(&head->head, &disp->head);
HEAD_DBG(head, "ctor");
return 0;
}
