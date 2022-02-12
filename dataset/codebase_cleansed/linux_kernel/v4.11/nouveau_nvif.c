static void
nvkm_client_unmap(void *priv, void __iomem *ptr, u32 size)
{
iounmap(ptr);
}
static void __iomem *
nvkm_client_map(void *priv, u64 handle, u32 size)
{
return ioremap(handle, size);
}
static int
nvkm_client_ioctl(void *priv, bool super, void *data, u32 size, void **hack)
{
return nvkm_ioctl(priv, super, data, size, hack);
}
static int
nvkm_client_resume(void *priv)
{
struct nvkm_client *client = priv;
return nvkm_object_init(&client->object);
}
static int
nvkm_client_suspend(void *priv)
{
struct nvkm_client *client = priv;
return nvkm_object_fini(&client->object, true);
}
static int
nvkm_client_ntfy(const void *header, u32 length, const void *data, u32 size)
{
const union {
struct nvif_notify_req_v0 v0;
} *args = header;
u8 route;
if (length == sizeof(args->v0) && args->v0.version == 0) {
route = args->v0.route;
} else {
WARN_ON(1);
return NVKM_NOTIFY_DROP;
}
switch (route) {
case NVDRM_NOTIFY_NVIF:
return nvif_notify(header, length, data, size);
case NVDRM_NOTIFY_USIF:
return usif_notify(header, length, data, size);
default:
WARN_ON(1);
break;
}
return NVKM_NOTIFY_DROP;
}
static int
nvkm_client_driver_init(const char *name, u64 device, const char *cfg,
const char *dbg, void **ppriv)
{
return nvkm_client_new(name, device, cfg, dbg, nvkm_client_ntfy,
(struct nvkm_client **)ppriv);
}
