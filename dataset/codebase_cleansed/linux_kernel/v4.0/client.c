static int
nvkm_client_notify(struct nvkm_notify *n)
{
struct nvkm_client_notify *notify = container_of(n, typeof(*notify), n);
struct nvkm_client *client = notify->client;
return client->ntfy(&notify->rep, notify->size, n->data, n->size);
}
int
nvkm_client_notify_put(struct nvkm_client *client, int index)
{
if (index < ARRAY_SIZE(client->notify)) {
if (client->notify[index]) {
nvkm_notify_put(&client->notify[index]->n);
return 0;
}
}
return -ENOENT;
}
int
nvkm_client_notify_get(struct nvkm_client *client, int index)
{
if (index < ARRAY_SIZE(client->notify)) {
if (client->notify[index]) {
nvkm_notify_get(&client->notify[index]->n);
return 0;
}
}
return -ENOENT;
}
int
nvkm_client_notify_del(struct nvkm_client *client, int index)
{
if (index < ARRAY_SIZE(client->notify)) {
if (client->notify[index]) {
nvkm_notify_fini(&client->notify[index]->n);
kfree(client->notify[index]);
client->notify[index] = NULL;
return 0;
}
}
return -ENOENT;
}
int
nvkm_client_notify_new(struct nvkm_object *object,
struct nvkm_event *event, void *data, u32 size)
{
struct nvkm_client *client = nvkm_client(object);
struct nvkm_client_notify *notify;
union {
struct nvif_notify_req_v0 v0;
} *req = data;
u8 index, reply;
int ret;
for (index = 0; index < ARRAY_SIZE(client->notify); index++) {
if (!client->notify[index])
break;
}
if (index == ARRAY_SIZE(client->notify))
return -ENOSPC;
notify = kzalloc(sizeof(*notify), GFP_KERNEL);
if (!notify)
return -ENOMEM;
nv_ioctl(client, "notify new size %d\n", size);
if (nvif_unpack(req->v0, 0, 0, true)) {
nv_ioctl(client, "notify new vers %d reply %d route %02x "
"token %llx\n", req->v0.version,
req->v0.reply, req->v0.route, req->v0.token);
notify->version = req->v0.version;
notify->size = sizeof(notify->rep.v0);
notify->rep.v0.version = req->v0.version;
notify->rep.v0.route = req->v0.route;
notify->rep.v0.token = req->v0.token;
reply = req->v0.reply;
}
if (ret == 0) {
ret = nvkm_notify_init(object, event, nvkm_client_notify,
false, data, size, reply, &notify->n);
if (ret == 0) {
client->notify[index] = notify;
notify->client = client;
return index;
}
}
kfree(notify);
return ret;
}
static int
nvkm_client_mthd_devlist(struct nvkm_object *object, void *data, u32 size)
{
union {
struct nv_client_devlist_v0 v0;
} *args = data;
int ret;
nv_ioctl(object, "client devlist size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, true)) {
nv_ioctl(object, "client devlist vers %d count %d\n",
args->v0.version, args->v0.count);
if (size == sizeof(args->v0.device[0]) * args->v0.count) {
ret = nvkm_device_list(args->v0.device, args->v0.count);
if (ret >= 0) {
args->v0.count = ret;
ret = 0;
}
} else {
ret = -EINVAL;
}
}
return ret;
}
static int
nvkm_client_mthd(struct nvkm_object *object, u32 mthd, void *data, u32 size)
{
switch (mthd) {
case NV_CLIENT_DEVLIST:
return nvkm_client_mthd_devlist(object, data, size);
default:
break;
}
return -EINVAL;
}
static void
nvkm_client_dtor(struct nvkm_object *object)
{
struct nvkm_client *client = (void *)object;
int i;
for (i = 0; i < ARRAY_SIZE(client->notify); i++)
nvkm_client_notify_del(client, i);
nvkm_object_ref(NULL, &client->device);
nvkm_handle_destroy(client->root);
nvkm_namedb_destroy(&client->namedb);
}
int
nvkm_client_create_(const char *name, u64 devname, const char *cfg,
const char *dbg, int length, void **pobject)
{
struct nvkm_object *device;
struct nvkm_client *client;
int ret;
device = (void *)nvkm_device_find(devname);
if (!device)
return -ENODEV;
ret = nvkm_namedb_create_(NULL, NULL, &nvkm_client_oclass,
NV_CLIENT_CLASS, NULL,
(1ULL << NVDEV_ENGINE_DEVICE),
length, pobject);
client = *pobject;
if (ret)
return ret;
ret = nvkm_handle_create(nv_object(client), ~0, ~0, nv_object(client),
&client->root);
if (ret)
return ret;
atomic_set(&nv_object(client)->usecount, 2);
nvkm_object_ref(device, &client->device);
snprintf(client->name, sizeof(client->name), "%s", name);
client->debug = nvkm_dbgopt(dbg, "CLIENT");
return 0;
}
int
nvkm_client_init(struct nvkm_client *client)
{
int ret;
nv_debug(client, "init running\n");
ret = nvkm_handle_init(client->root);
nv_debug(client, "init completed with %d\n", ret);
return ret;
}
int
nvkm_client_fini(struct nvkm_client *client, bool suspend)
{
const char *name[2] = { "fini", "suspend" };
int ret, i;
nv_debug(client, "%s running\n", name[suspend]);
nv_debug(client, "%s notify\n", name[suspend]);
for (i = 0; i < ARRAY_SIZE(client->notify); i++)
nvkm_client_notify_put(client, i);
nv_debug(client, "%s object\n", name[suspend]);
ret = nvkm_handle_fini(client->root, suspend);
nv_debug(client, "%s completed with %d\n", name[suspend], ret);
return ret;
}
const char *
nvkm_client_name(void *obj)
{
const char *client_name = "unknown";
struct nvkm_client *client = nvkm_client(obj);
if (client)
client_name = client->name;
return client_name;
}
