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
struct nvkm_client *client = object->client;
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
nvif_ioctl(object, "notify new size %d\n", size);
if (nvif_unpack(req->v0, 0, 0, true)) {
nvif_ioctl(object, "notify new vers %d reply %d route %02x "
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
nvif_ioctl(object, "client devlist size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, true)) {
nvif_ioctl(object, "client devlist vers %d count %d\n",
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
static int
nvkm_client_child_new(const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
return oclass->base.ctor(oclass, data, size, pobject);
}
static int
nvkm_client_child_get(struct nvkm_object *object, int index,
struct nvkm_oclass *oclass)
{
const struct nvkm_sclass *sclass;
switch (index) {
case 0: sclass = &nvkm_udevice_sclass; break;
default:
return -EINVAL;
}
oclass->ctor = nvkm_client_child_new;
oclass->base = *sclass;
return 0;
}
void
nvkm_client_remove(struct nvkm_client *client, struct nvkm_object *object)
{
if (!RB_EMPTY_NODE(&object->node))
rb_erase(&object->node, &client->objroot);
}
bool
nvkm_client_insert(struct nvkm_client *client, struct nvkm_object *object)
{
struct rb_node **ptr = &client->objroot.rb_node;
struct rb_node *parent = NULL;
while (*ptr) {
struct nvkm_object *this =
container_of(*ptr, typeof(*this), node);
parent = *ptr;
if (object->object < this->object)
ptr = &parent->rb_left;
else
if (object->object > this->object)
ptr = &parent->rb_right;
else
return false;
}
rb_link_node(&object->node, parent, ptr);
rb_insert_color(&object->node, &client->objroot);
return true;
}
struct nvkm_object *
nvkm_client_search(struct nvkm_client *client, u64 handle)
{
struct rb_node *node = client->objroot.rb_node;
while (node) {
struct nvkm_object *object =
container_of(node, typeof(*object), node);
if (handle < object->object)
node = node->rb_left;
else
if (handle > object->object)
node = node->rb_right;
else
return object;
}
return NULL;
}
int
nvkm_client_fini(struct nvkm_client *client, bool suspend)
{
struct nvkm_object *object = &client->object;
const char *name[2] = { "fini", "suspend" };
int i;
nvif_debug(object, "%s notify\n", name[suspend]);
for (i = 0; i < ARRAY_SIZE(client->notify); i++)
nvkm_client_notify_put(client, i);
return nvkm_object_fini(&client->object, suspend);
}
int
nvkm_client_init(struct nvkm_client *client)
{
return nvkm_object_init(&client->object);
}
void
nvkm_client_del(struct nvkm_client **pclient)
{
struct nvkm_client *client = *pclient;
int i;
if (client) {
nvkm_client_fini(client, false);
for (i = 0; i < ARRAY_SIZE(client->notify); i++)
nvkm_client_notify_del(client, i);
nvkm_object_dtor(&client->object);
kfree(*pclient);
*pclient = NULL;
}
}
int
nvkm_client_new(const char *name, u64 device, const char *cfg,
const char *dbg, struct nvkm_client **pclient)
{
struct nvkm_oclass oclass = {};
struct nvkm_client *client;
if (!(client = *pclient = kzalloc(sizeof(*client), GFP_KERNEL)))
return -ENOMEM;
oclass.client = client;
nvkm_object_ctor(&nvkm_client_object_func, &oclass, &client->object);
snprintf(client->name, sizeof(client->name), "%s", name);
client->device = device;
client->debug = nvkm_dbgopt(dbg, "CLIENT");
client->objroot = RB_ROOT;
client->dmaroot = RB_ROOT;
return 0;
}
