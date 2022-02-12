static int
nvkm_conn_hpd(struct nvkm_notify *notify)
{
struct nvkm_conn *conn = container_of(notify, typeof(*conn), hpd);
struct nvkm_disp *disp = conn->disp;
struct nvkm_gpio *gpio = disp->engine.subdev.device->gpio;
const struct nvkm_gpio_ntfy_rep *line = notify->data;
struct nvif_notify_conn_rep_v0 rep;
int index = conn->index;
CONN_DBG(conn, "HPD: %d", line->mask);
if (!nvkm_gpio_get(gpio, 0, DCB_GPIO_UNUSED, conn->hpd.index))
rep.mask = NVIF_NOTIFY_CONN_V0_UNPLUG;
else
rep.mask = NVIF_NOTIFY_CONN_V0_PLUG;
rep.version = 0;
nvkm_event_send(&disp->hpd, rep.mask, index, &rep, sizeof(rep));
return NVKM_NOTIFY_KEEP;
}
void
nvkm_conn_fini(struct nvkm_conn *conn)
{
nvkm_notify_put(&conn->hpd);
}
void
nvkm_conn_init(struct nvkm_conn *conn)
{
nvkm_notify_get(&conn->hpd);
}
void
nvkm_conn_del(struct nvkm_conn **pconn)
{
struct nvkm_conn *conn = *pconn;
if (conn) {
nvkm_notify_fini(&conn->hpd);
kfree(*pconn);
*pconn = NULL;
}
}
static void
nvkm_conn_ctor(struct nvkm_disp *disp, int index, struct nvbios_connE *info,
struct nvkm_conn *conn)
{
static const u8 hpd[] = { 0x07, 0x08, 0x51, 0x52, 0x5e, 0x5f, 0x60 };
struct nvkm_gpio *gpio = disp->engine.subdev.device->gpio;
struct dcb_gpio_func func;
int ret;
conn->disp = disp;
conn->index = index;
conn->info = *info;
CONN_DBG(conn, "type %02x loc %d hpd %02x dp %x di %x sr %x lcdid %x",
info->type, info->location, info->hpd, info->dp,
info->di, info->sr, info->lcdid);
if ((info->hpd = ffs(info->hpd))) {
if (--info->hpd >= ARRAY_SIZE(hpd)) {
CONN_ERR(conn, "hpd %02x unknown", info->hpd);
return;
}
info->hpd = hpd[info->hpd];
ret = nvkm_gpio_find(gpio, 0, info->hpd, DCB_GPIO_UNUSED, &func);
if (ret) {
CONN_ERR(conn, "func %02x lookup failed, %d",
info->hpd, ret);
return;
}
ret = nvkm_notify_init(NULL, &gpio->event, nvkm_conn_hpd,
true, &(struct nvkm_gpio_ntfy_req) {
.mask = NVKM_GPIO_TOGGLED,
.line = func.line,
},
sizeof(struct nvkm_gpio_ntfy_req),
sizeof(struct nvkm_gpio_ntfy_rep),
&conn->hpd);
if (ret) {
CONN_ERR(conn, "func %02x failed, %d", info->hpd, ret);
} else {
CONN_DBG(conn, "func %02x (HPD)", info->hpd);
}
}
}
int
nvkm_conn_new(struct nvkm_disp *disp, int index, struct nvbios_connE *info,
struct nvkm_conn **pconn)
{
if (!(*pconn = kzalloc(sizeof(**pconn), GFP_KERNEL)))
return -ENOMEM;
nvkm_conn_ctor(disp, index, info, *pconn);
return 0;
}
