static void
nvkm_client_unmap(void *priv, void *ptr, u32 size)
{
iounmap(ptr);
}
static void *
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
return nouveau_client_init(priv);
}
static int
nvkm_client_suspend(void *priv)
{
return nouveau_client_fini(priv, true);
}
static void
nvkm_client_fini(void *priv)
{
struct nouveau_object *client = priv;
nouveau_client_fini(nv_client(client), false);
atomic_set(&client->refcount, 1);
nouveau_object_ref(NULL, &client);
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
nvkm_client_init(const char *name, u64 device, const char *cfg,
const char *dbg, void **ppriv)
{
struct nouveau_client *client;
int ret;
ret = nouveau_client_create(name, device, cfg, dbg, &client);
*ppriv = client;
if (ret)
return ret;
client->ntfy = nvkm_client_ntfy;
return 0;
}
