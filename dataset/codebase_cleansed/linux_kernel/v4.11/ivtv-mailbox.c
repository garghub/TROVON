static int try_mailbox(struct ivtv *itv, struct ivtv_mailbox_data *mbdata, int mb)
{
u32 flags = readl(&mbdata->mbox[mb].flags);
int is_free = flags == IVTV_MBOX_FREE || (flags & IVTV_MBOX_FIRMWARE_DONE);
if (is_free && !test_and_set_bit(mb, &mbdata->busy)) {
write_sync(IVTV_MBOX_DRIVER_BUSY, &mbdata->mbox[mb].flags);
return 1;
}
return 0;
}
static int get_mailbox(struct ivtv *itv, struct ivtv_mailbox_data *mbdata, int flags)
{
unsigned long then = jiffies;
int i, mb;
int max_mbox = mbdata->max_mbox;
int retries = 100;
if ((flags & API_FAST_RESULT) == API_RESULT)
max_mbox = 1;
for (i = 0; i < retries; i++) {
for (mb = 1; mb <= max_mbox; mb++)
if (try_mailbox(itv, mbdata, mb))
return mb;
if (!(flags & API_NO_WAIT_MB)) {
if (time_after(jiffies,
then + msecs_to_jiffies(10*retries)))
break;
ivtv_msleep_timeout(10, 0);
}
}
return -ENODEV;
}
static void write_mailbox(volatile struct ivtv_mailbox __iomem *mbox, int cmd, int args, u32 data[])
{
int i;
write_sync(cmd, &mbox->cmd);
write_sync(IVTV_API_STD_TIMEOUT, &mbox->timeout);
for (i = 0; i < CX2341X_MBOX_MAX_DATA; i++)
write_sync(data[i], &mbox->data[i]);
write_sync(IVTV_MBOX_DRIVER_DONE | IVTV_MBOX_DRIVER_BUSY, &mbox->flags);
}
static void clear_all_mailboxes(struct ivtv *itv, struct ivtv_mailbox_data *mbdata)
{
int i;
for (i = 0; i <= mbdata->max_mbox; i++) {
IVTV_DEBUG_WARN("Clearing mailbox %d: cmd 0x%08x flags 0x%08x\n",
i, readl(&mbdata->mbox[i].cmd), readl(&mbdata->mbox[i].flags));
write_sync(0, &mbdata->mbox[i].flags);
clear_bit(i, &mbdata->busy);
}
}
static int ivtv_api_call(struct ivtv *itv, int cmd, int args, u32 data[])
{
struct ivtv_mailbox_data *mbdata = (cmd >= 128) ? &itv->enc_mbox : &itv->dec_mbox;
volatile struct ivtv_mailbox __iomem *mbox;
int api_timeout = msecs_to_jiffies(1000);
int flags, mb, i;
unsigned long then;
if (NULL == mbdata) {
IVTV_ERR("No mailbox allocated\n");
return -ENODEV;
}
if (args < 0 || args > CX2341X_MBOX_MAX_DATA ||
cmd < 0 || cmd > 255 || api_info[cmd].name == NULL) {
IVTV_ERR("Invalid MB call: cmd = 0x%02x, args = %d\n", cmd, args);
return -EINVAL;
}
if (api_info[cmd].flags & API_HIGH_VOL) {
IVTV_DEBUG_HI_MB("MB Call: %s\n", api_info[cmd].name);
}
else {
IVTV_DEBUG_MB("MB Call: %s\n", api_info[cmd].name);
}
for (i = args; i < CX2341X_MBOX_MAX_DATA; i++)
data[i] = 0;
if (itv->api_cache[cmd].last_jiffies &&
time_before(jiffies,
itv->api_cache[cmd].last_jiffies +
msecs_to_jiffies(1800000)) &&
!memcmp(data, itv->api_cache[cmd].data, sizeof(itv->api_cache[cmd].data))) {
itv->api_cache[cmd].last_jiffies = jiffies;
return 0;
}
flags = api_info[cmd].flags;
if (flags & API_DMA) {
for (i = 0; i < 100; i++) {
mb = i % (mbdata->max_mbox + 1);
if (try_mailbox(itv, mbdata, mb)) {
write_mailbox(&mbdata->mbox[mb], cmd, args, data);
clear_bit(mb, &mbdata->busy);
return 0;
}
IVTV_DEBUG_WARN("%s: mailbox %d not free %08x\n",
api_info[cmd].name, mb, readl(&mbdata->mbox[mb].flags));
}
IVTV_WARN("Could not find free DMA mailbox for %s\n", api_info[cmd].name);
clear_all_mailboxes(itv, mbdata);
return -EBUSY;
}
if ((flags & API_FAST_RESULT) == API_FAST_RESULT)
api_timeout = msecs_to_jiffies(100);
mb = get_mailbox(itv, mbdata, flags);
if (mb < 0) {
IVTV_DEBUG_WARN("No free mailbox found (%s)\n", api_info[cmd].name);
clear_all_mailboxes(itv, mbdata);
return -EBUSY;
}
mbox = &mbdata->mbox[mb];
write_mailbox(mbox, cmd, args, data);
if (flags & API_CACHE) {
memcpy(itv->api_cache[cmd].data, data, sizeof(itv->api_cache[cmd].data));
itv->api_cache[cmd].last_jiffies = jiffies;
}
if ((flags & API_RESULT) == 0) {
clear_bit(mb, &mbdata->busy);
return 0;
}
then = jiffies;
if (!(flags & API_NO_POLL)) {
for (i = 0; i < 100; i++) {
if (readl(&mbox->flags) & IVTV_MBOX_FIRMWARE_DONE)
break;
}
}
while (!(readl(&mbox->flags) & IVTV_MBOX_FIRMWARE_DONE)) {
if (time_after(jiffies, then + api_timeout)) {
IVTV_DEBUG_WARN("Could not get result (%s)\n", api_info[cmd].name);
write_sync(0, &mbox->flags);
clear_bit(mb, &mbdata->busy);
return -EIO;
}
if (flags & API_NO_WAIT_RES)
mdelay(1);
else
ivtv_msleep_timeout(1, 0);
}
if (time_after(jiffies, then + msecs_to_jiffies(100)))
IVTV_DEBUG_WARN("%s took %u jiffies\n",
api_info[cmd].name,
jiffies_to_msecs(jiffies - then));
for (i = 0; i < CX2341X_MBOX_MAX_DATA; i++)
data[i] = readl(&mbox->data[i]);
write_sync(0, &mbox->flags);
clear_bit(mb, &mbdata->busy);
return 0;
}
int ivtv_api(struct ivtv *itv, int cmd, int args, u32 data[])
{
int res = ivtv_api_call(itv, cmd, args, data);
return (res == -EBUSY) ? ivtv_api_call(itv, cmd, args, data) : res;
}
int ivtv_api_func(void *priv, u32 cmd, int in, int out, u32 data[CX2341X_MBOX_MAX_DATA])
{
return ivtv_api(priv, cmd, in, data);
}
int ivtv_vapi_result(struct ivtv *itv, u32 data[CX2341X_MBOX_MAX_DATA], int cmd, int args, ...)
{
va_list ap;
int i;
va_start(ap, args);
for (i = 0; i < args; i++) {
data[i] = va_arg(ap, u32);
}
va_end(ap);
return ivtv_api(itv, cmd, args, data);
}
int ivtv_vapi(struct ivtv *itv, int cmd, int args, ...)
{
u32 data[CX2341X_MBOX_MAX_DATA];
va_list ap;
int i;
va_start(ap, args);
for (i = 0; i < args; i++) {
data[i] = va_arg(ap, u32);
}
va_end(ap);
return ivtv_api(itv, cmd, args, data);
}
void ivtv_api_get_data(struct ivtv_mailbox_data *mbdata, int mb,
int argc, u32 data[])
{
volatile u32 __iomem *p = mbdata->mbox[mb].data;
int i;
for (i = 0; i < argc; i++, p++)
data[i] = readl(p);
}
void ivtv_mailbox_cache_invalidate(struct ivtv *itv)
{
int i;
for (i = 0; i < 256; i++)
itv->api_cache[i].last_jiffies = 0;
}
