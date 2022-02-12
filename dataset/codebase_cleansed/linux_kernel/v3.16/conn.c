static void
nvkm_connector_hpd_work(struct work_struct *w)
{
struct nvkm_connector *conn = container_of(w, typeof(*conn), hpd.work);
struct nouveau_disp *disp = nouveau_disp(conn);
struct nouveau_gpio *gpio = nouveau_gpio(conn);
u32 send = NVKM_HPD_UNPLUG;
if (gpio->get(gpio, 0, DCB_GPIO_UNUSED, conn->hpd.event->index))
send = NVKM_HPD_PLUG;
nouveau_event_trigger(disp->hpd, send, conn->index);
nouveau_event_get(conn->hpd.event);
}
static int
nvkm_connector_hpd(void *data, u32 type, int index)
{
struct nvkm_connector *conn = data;
DBG("HPD: %d\n", type);
schedule_work(&conn->hpd.work);
return NVKM_EVENT_DROP;
}
int
_nvkm_connector_fini(struct nouveau_object *object, bool suspend)
{
struct nvkm_connector *conn = (void *)object;
if (conn->hpd.event)
nouveau_event_put(conn->hpd.event);
return nouveau_object_fini(&conn->base, suspend);
}
int
_nvkm_connector_init(struct nouveau_object *object)
{
struct nvkm_connector *conn = (void *)object;
int ret = nouveau_object_init(&conn->base);
if (ret == 0) {
if (conn->hpd.event)
nouveau_event_get(conn->hpd.event);
}
return ret;
}
void
_nvkm_connector_dtor(struct nouveau_object *object)
{
struct nvkm_connector *conn = (void *)object;
nouveau_event_ref(NULL, &conn->hpd.event);
nouveau_object_destroy(&conn->base);
}
int
nvkm_connector_create_(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass,
struct nvbios_connE *info, int index,
int length, void **pobject)
{
static const u8 hpd[] = { 0x07, 0x08, 0x51, 0x52, 0x5e, 0x5f, 0x60 };
struct nouveau_gpio *gpio = nouveau_gpio(parent);
struct nouveau_disp *disp = (void *)engine;
struct nvkm_connector *conn;
struct nvkm_output *outp;
struct dcb_gpio_func func;
int ret;
list_for_each_entry(outp, &disp->outp, head) {
if (outp->conn && outp->conn->index == index) {
atomic_inc(&nv_object(outp->conn)->refcount);
*pobject = outp->conn;
return 1;
}
}
ret = nouveau_object_create_(parent, engine, oclass, 0, length, pobject);
conn = *pobject;
if (ret)
return ret;
conn->info = *info;
conn->index = index;
DBG("type %02x loc %d hpd %02x dp %x di %x sr %x lcdid %x\n",
info->type, info->location, info->hpd, info->dp,
info->di, info->sr, info->lcdid);
if ((info->hpd = ffs(info->hpd))) {
if (--info->hpd >= ARRAY_SIZE(hpd)) {
ERR("hpd %02x unknown\n", info->hpd);
goto done;
}
info->hpd = hpd[info->hpd];
ret = gpio->find(gpio, 0, info->hpd, DCB_GPIO_UNUSED, &func);
if (ret) {
ERR("func %02x lookup failed, %d\n", info->hpd, ret);
goto done;
}
ret = nouveau_event_new(gpio->events, NVKM_GPIO_TOGGLED,
func.line, nvkm_connector_hpd,
conn, &conn->hpd.event);
if (ret) {
ERR("func %02x failed, %d\n", info->hpd, ret);
} else {
DBG("func %02x (HPD)\n", info->hpd);
}
}
done:
INIT_WORK(&conn->hpd.work, nvkm_connector_hpd_work);
return 0;
}
int
_nvkm_connector_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *info, u32 index,
struct nouveau_object **pobject)
{
struct nvkm_connector *conn;
int ret;
ret = nvkm_connector_create(parent, engine, oclass, info, index, &conn);
*pobject = nv_object(conn);
if (ret)
return ret;
return 0;
}
