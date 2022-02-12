int
channel_of_freq(int f)
{
int c = 0;
if ((f >= 2412) && (f <= 2484)) {
while ((c < 14) && (f != frequency_list_bg[c]))
c++;
return (c >= 14) ? 0 : ++c;
} else if ((f >= (int) 5000) && (f <= (int) 6000)) {
return ( (f - 5000) / 5 );
} else
return 0;
}
int
mgt_init(islpci_private *priv)
{
int i;
priv->mib = kcalloc(OID_NUM_LAST, sizeof (void *), GFP_KERNEL);
if (!priv->mib)
return -ENOMEM;
for (i = 0; i < OID_NUM_LAST; i++) {
if (isl_oid[i].flags & OID_FLAG_CACHED) {
priv->mib[i] = kzalloc(isl_oid[i].size *
(isl_oid[i].range + 1),
GFP_KERNEL);
if (!priv->mib[i])
return -ENOMEM;
} else
priv->mib[i] = NULL;
}
init_rwsem(&priv->mib_sem);
prism54_mib_init(priv);
return 0;
}
void
mgt_clean(islpci_private *priv)
{
int i;
if (!priv->mib)
return;
for (i = 0; i < OID_NUM_LAST; i++) {
kfree(priv->mib[i]);
priv->mib[i] = NULL;
}
kfree(priv->mib);
priv->mib = NULL;
}
void
mgt_le_to_cpu(int type, void *data)
{
switch (type) {
case OID_TYPE_U32:
*(u32 *) data = le32_to_cpu(*(u32 *) data);
break;
case OID_TYPE_BUFFER:{
struct obj_buffer *buff = data;
buff->size = le32_to_cpu(buff->size);
buff->addr = le32_to_cpu(buff->addr);
break;
}
case OID_TYPE_BSS:{
struct obj_bss *bss = data;
bss->age = le16_to_cpu(bss->age);
bss->channel = le16_to_cpu(bss->channel);
bss->capinfo = le16_to_cpu(bss->capinfo);
bss->rates = le16_to_cpu(bss->rates);
bss->basic_rates = le16_to_cpu(bss->basic_rates);
break;
}
case OID_TYPE_BSSLIST:{
struct obj_bsslist *list = data;
int i;
list->nr = le32_to_cpu(list->nr);
for (i = 0; i < list->nr; i++)
mgt_le_to_cpu(OID_TYPE_BSS, &list->bsslist[i]);
break;
}
case OID_TYPE_FREQUENCIES:{
struct obj_frequencies *freq = data;
int i;
freq->nr = le16_to_cpu(freq->nr);
for (i = 0; i < freq->nr; i++)
freq->mhz[i] = le16_to_cpu(freq->mhz[i]);
break;
}
case OID_TYPE_MLME:{
struct obj_mlme *mlme = data;
mlme->id = le16_to_cpu(mlme->id);
mlme->state = le16_to_cpu(mlme->state);
mlme->code = le16_to_cpu(mlme->code);
break;
}
case OID_TYPE_MLMEEX:{
struct obj_mlmeex *mlme = data;
mlme->id = le16_to_cpu(mlme->id);
mlme->state = le16_to_cpu(mlme->state);
mlme->code = le16_to_cpu(mlme->code);
mlme->size = le16_to_cpu(mlme->size);
break;
}
case OID_TYPE_ATTACH:{
struct obj_attachment *attach = data;
attach->id = le16_to_cpu(attach->id);
attach->size = le16_to_cpu(attach->size);
break;
}
case OID_TYPE_SSID:
case OID_TYPE_KEY:
case OID_TYPE_ADDR:
case OID_TYPE_RAW:
break;
default:
BUG();
}
}
static void
mgt_cpu_to_le(int type, void *data)
{
switch (type) {
case OID_TYPE_U32:
*(u32 *) data = cpu_to_le32(*(u32 *) data);
break;
case OID_TYPE_BUFFER:{
struct obj_buffer *buff = data;
buff->size = cpu_to_le32(buff->size);
buff->addr = cpu_to_le32(buff->addr);
break;
}
case OID_TYPE_BSS:{
struct obj_bss *bss = data;
bss->age = cpu_to_le16(bss->age);
bss->channel = cpu_to_le16(bss->channel);
bss->capinfo = cpu_to_le16(bss->capinfo);
bss->rates = cpu_to_le16(bss->rates);
bss->basic_rates = cpu_to_le16(bss->basic_rates);
break;
}
case OID_TYPE_BSSLIST:{
struct obj_bsslist *list = data;
int i;
list->nr = cpu_to_le32(list->nr);
for (i = 0; i < list->nr; i++)
mgt_cpu_to_le(OID_TYPE_BSS, &list->bsslist[i]);
break;
}
case OID_TYPE_FREQUENCIES:{
struct obj_frequencies *freq = data;
int i;
freq->nr = cpu_to_le16(freq->nr);
for (i = 0; i < freq->nr; i++)
freq->mhz[i] = cpu_to_le16(freq->mhz[i]);
break;
}
case OID_TYPE_MLME:{
struct obj_mlme *mlme = data;
mlme->id = cpu_to_le16(mlme->id);
mlme->state = cpu_to_le16(mlme->state);
mlme->code = cpu_to_le16(mlme->code);
break;
}
case OID_TYPE_MLMEEX:{
struct obj_mlmeex *mlme = data;
mlme->id = cpu_to_le16(mlme->id);
mlme->state = cpu_to_le16(mlme->state);
mlme->code = cpu_to_le16(mlme->code);
mlme->size = cpu_to_le16(mlme->size);
break;
}
case OID_TYPE_ATTACH:{
struct obj_attachment *attach = data;
attach->id = cpu_to_le16(attach->id);
attach->size = cpu_to_le16(attach->size);
break;
}
case OID_TYPE_SSID:
case OID_TYPE_KEY:
case OID_TYPE_ADDR:
case OID_TYPE_RAW:
break;
default:
BUG();
}
}
int
mgt_set_request(islpci_private *priv, enum oid_num_t n, int extra, void *data)
{
int ret = 0;
struct islpci_mgmtframe *response = NULL;
int response_op = PIMFOR_OP_ERROR;
int dlen;
void *cache, *_data = data;
u32 oid;
BUG_ON(n >= OID_NUM_LAST);
BUG_ON(extra > isl_oid[n].range);
if (!priv->mib)
return -1;
dlen = isl_oid[n].size;
cache = priv->mib[n];
cache += (cache ? extra * dlen : 0);
oid = isl_oid[n].oid + extra;
if (_data == NULL)
_data = cache;
else
mgt_cpu_to_le(isl_oid[n].flags & OID_FLAG_TYPE, _data);
if (cache)
down_write(&priv->mib_sem);
if (islpci_get_state(priv) >= PRV_STATE_READY) {
ret = islpci_mgt_transaction(priv->ndev, PIMFOR_OP_SET, oid,
_data, dlen, &response);
if (!ret) {
response_op = response->header->operation;
islpci_mgt_release(response);
}
if (ret || response_op == PIMFOR_OP_ERROR)
ret = -EIO;
} else if (!cache)
ret = -EIO;
if (cache) {
if (!ret && data)
memcpy(cache, _data, dlen);
up_write(&priv->mib_sem);
}
if (data)
mgt_le_to_cpu(isl_oid[n].flags & OID_FLAG_TYPE, data);
return ret;
}
int
mgt_set_varlen(islpci_private *priv, enum oid_num_t n, void *data, int extra_len)
{
int ret = 0;
struct islpci_mgmtframe *response;
int response_op = PIMFOR_OP_ERROR;
int dlen;
u32 oid;
BUG_ON(n >= OID_NUM_LAST);
dlen = isl_oid[n].size;
oid = isl_oid[n].oid;
mgt_cpu_to_le(isl_oid[n].flags & OID_FLAG_TYPE, data);
if (islpci_get_state(priv) >= PRV_STATE_READY) {
ret = islpci_mgt_transaction(priv->ndev, PIMFOR_OP_SET, oid,
data, dlen + extra_len, &response);
if (!ret) {
response_op = response->header->operation;
islpci_mgt_release(response);
}
if (ret || response_op == PIMFOR_OP_ERROR)
ret = -EIO;
} else
ret = -EIO;
if (data)
mgt_le_to_cpu(isl_oid[n].flags & OID_FLAG_TYPE, data);
return ret;
}
int
mgt_get_request(islpci_private *priv, enum oid_num_t n, int extra, void *data,
union oid_res_t *res)
{
int ret = -EIO;
int reslen = 0;
struct islpci_mgmtframe *response = NULL;
int dlen;
void *cache, *_res = NULL;
u32 oid;
BUG_ON(n >= OID_NUM_LAST);
BUG_ON(extra > isl_oid[n].range);
res->ptr = NULL;
if (!priv->mib)
return -1;
dlen = isl_oid[n].size;
cache = priv->mib[n];
cache += cache ? extra * dlen : 0;
oid = isl_oid[n].oid + extra;
reslen = dlen;
if (cache)
down_read(&priv->mib_sem);
if (islpci_get_state(priv) >= PRV_STATE_READY) {
ret = islpci_mgt_transaction(priv->ndev, PIMFOR_OP_GET,
oid, data, dlen, &response);
if (ret || !response ||
response->header->operation == PIMFOR_OP_ERROR) {
if (response)
islpci_mgt_release(response);
ret = -EIO;
}
if (!ret) {
_res = response->data;
reslen = response->header->length;
}
} else if (cache) {
_res = cache;
ret = 0;
}
if ((isl_oid[n].flags & OID_FLAG_TYPE) == OID_TYPE_U32)
res->u = ret ? 0 : le32_to_cpu(*(u32 *) _res);
else {
res->ptr = kmalloc(reslen, GFP_KERNEL);
BUG_ON(res->ptr == NULL);
if (ret)
memset(res->ptr, 0, reslen);
else {
memcpy(res->ptr, _res, reslen);
mgt_le_to_cpu(isl_oid[n].flags & OID_FLAG_TYPE,
res->ptr);
}
}
if (cache)
up_read(&priv->mib_sem);
if (response && !ret)
islpci_mgt_release(response);
if (reslen > isl_oid[n].size)
printk(KERN_DEBUG
"mgt_get_request(0x%x): received data length was bigger "
"than expected (%d > %d). Memory is probably corrupted...",
oid, reslen, isl_oid[n].size);
return ret;
}
int
mgt_commit_list(islpci_private *priv, enum oid_num_t *l, int n)
{
int i, ret = 0;
struct islpci_mgmtframe *response;
for (i = 0; i < n; i++) {
struct oid_t *t = &(isl_oid[l[i]]);
void *data = priv->mib[l[i]];
int j = 0;
u32 oid = t->oid;
BUG_ON(data == NULL);
while (j <= t->range) {
int r = islpci_mgt_transaction(priv->ndev, PIMFOR_OP_SET,
oid, data, t->size,
&response);
if (response) {
r |= (response->header->operation == PIMFOR_OP_ERROR);
islpci_mgt_release(response);
}
if (r)
printk(KERN_ERR "%s: mgt_commit_list: failure. "
"oid=%08x err=%d\n",
priv->ndev->name, oid, r);
ret |= r;
j++;
oid++;
data += t->size;
}
}
return ret;
}
void
mgt_set(islpci_private *priv, enum oid_num_t n, void *data)
{
BUG_ON(n >= OID_NUM_LAST);
BUG_ON(priv->mib[n] == NULL);
memcpy(priv->mib[n], data, isl_oid[n].size);
mgt_cpu_to_le(isl_oid[n].flags & OID_FLAG_TYPE, priv->mib[n]);
}
void
mgt_get(islpci_private *priv, enum oid_num_t n, void *res)
{
BUG_ON(n >= OID_NUM_LAST);
BUG_ON(priv->mib[n] == NULL);
BUG_ON(res == NULL);
memcpy(res, priv->mib[n], isl_oid[n].size);
mgt_le_to_cpu(isl_oid[n].flags & OID_FLAG_TYPE, res);
}
static int
mgt_update_addr(islpci_private *priv)
{
struct islpci_mgmtframe *res;
int ret;
ret = islpci_mgt_transaction(priv->ndev, PIMFOR_OP_GET,
isl_oid[GEN_OID_MACADDRESS].oid, NULL,
isl_oid[GEN_OID_MACADDRESS].size, &res);
if ((ret == 0) && res && (res->header->operation != PIMFOR_OP_ERROR))
memcpy(priv->ndev->dev_addr, res->data, ETH_ALEN);
else
ret = -EIO;
if (res)
islpci_mgt_release(res);
if (ret)
printk(KERN_ERR "%s: mgt_update_addr: failure\n", priv->ndev->name);
return ret;
}
int
mgt_commit(islpci_private *priv)
{
int rvalue;
enum oid_num_t u;
if (islpci_get_state(priv) < PRV_STATE_INIT)
return 0;
rvalue = mgt_commit_list(priv, commit_part1, ARRAY_SIZE(commit_part1));
if (priv->iw_mode != IW_MODE_MONITOR)
rvalue |= mgt_commit_list(priv, commit_part2, ARRAY_SIZE(commit_part2));
u = OID_INL_MODE;
rvalue |= mgt_commit_list(priv, &u, 1);
rvalue |= mgt_update_addr(priv);
if (rvalue) {
printk(KERN_DEBUG "%s: mgt_commit: failure\n", priv->ndev->name);
}
return rvalue;
}
int
mgt_mlme_answer(islpci_private *priv)
{
u32 mlmeautolevel;
down_read(&priv->mib_sem);
mlmeautolevel =
le32_to_cpu(*(u32 *) priv->mib[DOT11_OID_MLMEAUTOLEVEL]);
up_read(&priv->mib_sem);
return ((priv->iw_mode == IW_MODE_MASTER) &&
(mlmeautolevel >= DOT11_MLME_INTERMEDIATE));
}
enum oid_num_t
mgt_oidtonum(u32 oid)
{
int i;
for (i = 0; i < OID_NUM_LAST; i++)
if (isl_oid[i].oid == oid)
return i;
printk(KERN_DEBUG "looking for an unknown oid 0x%x", oid);
return OID_NUM_LAST;
}
int
mgt_response_to_str(enum oid_num_t n, union oid_res_t *r, char *str)
{
switch (isl_oid[n].flags & OID_FLAG_TYPE) {
case OID_TYPE_U32:
return snprintf(str, PRIV_STR_SIZE, "%u\n", r->u);
case OID_TYPE_BUFFER:{
struct obj_buffer *buff = r->ptr;
return snprintf(str, PRIV_STR_SIZE,
"size=%u\naddr=0x%X\n", buff->size,
buff->addr);
}
break;
case OID_TYPE_BSS:{
struct obj_bss *bss = r->ptr;
return snprintf(str, PRIV_STR_SIZE,
"age=%u\nchannel=%u\n"
"capinfo=0x%X\nrates=0x%X\n"
"basic_rates=0x%X\n", bss->age,
bss->channel, bss->capinfo,
bss->rates, bss->basic_rates);
}
break;
case OID_TYPE_BSSLIST:{
struct obj_bsslist *list = r->ptr;
int i, k;
k = snprintf(str, PRIV_STR_SIZE, "nr=%u\n", list->nr);
for (i = 0; i < list->nr; i++)
k += snprintf(str + k, PRIV_STR_SIZE - k,
"bss[%u] :\nage=%u\nchannel=%u\n"
"capinfo=0x%X\nrates=0x%X\n"
"basic_rates=0x%X\n",
i, list->bsslist[i].age,
list->bsslist[i].channel,
list->bsslist[i].capinfo,
list->bsslist[i].rates,
list->bsslist[i].basic_rates);
return k;
}
break;
case OID_TYPE_FREQUENCIES:{
struct obj_frequencies *freq = r->ptr;
int i, t;
printk("nr : %u\n", freq->nr);
t = snprintf(str, PRIV_STR_SIZE, "nr=%u\n", freq->nr);
for (i = 0; i < freq->nr; i++)
t += snprintf(str + t, PRIV_STR_SIZE - t,
"mhz[%u]=%u\n", i, freq->mhz[i]);
return t;
}
break;
case OID_TYPE_MLME:{
struct obj_mlme *mlme = r->ptr;
return snprintf(str, PRIV_STR_SIZE,
"id=0x%X\nstate=0x%X\ncode=0x%X\n",
mlme->id, mlme->state, mlme->code);
}
break;
case OID_TYPE_MLMEEX:{
struct obj_mlmeex *mlme = r->ptr;
return snprintf(str, PRIV_STR_SIZE,
"id=0x%X\nstate=0x%X\n"
"code=0x%X\nsize=0x%X\n", mlme->id,
mlme->state, mlme->code, mlme->size);
}
break;
case OID_TYPE_ATTACH:{
struct obj_attachment *attach = r->ptr;
return snprintf(str, PRIV_STR_SIZE,
"id=%d\nsize=%d\n",
attach->id,
attach->size);
}
break;
case OID_TYPE_SSID:{
struct obj_ssid *ssid = r->ptr;
return snprintf(str, PRIV_STR_SIZE,
"length=%u\noctets=%.*s\n",
ssid->length, ssid->length,
ssid->octets);
}
break;
case OID_TYPE_KEY:{
struct obj_key *key = r->ptr;
int t, i;
t = snprintf(str, PRIV_STR_SIZE,
"type=0x%X\nlength=0x%X\nkey=0x",
key->type, key->length);
for (i = 0; i < key->length; i++)
t += snprintf(str + t, PRIV_STR_SIZE - t,
"%02X:", key->key[i]);
t += snprintf(str + t, PRIV_STR_SIZE - t, "\n");
return t;
}
break;
case OID_TYPE_RAW:
case OID_TYPE_ADDR:{
unsigned char *buff = r->ptr;
int t, i;
t = snprintf(str, PRIV_STR_SIZE, "hex data=");
for (i = 0; i < isl_oid[n].size; i++)
t += snprintf(str + t, PRIV_STR_SIZE - t,
"%02X:", buff[i]);
t += snprintf(str + t, PRIV_STR_SIZE - t, "\n");
return t;
}
break;
default:
BUG();
}
return 0;
}
