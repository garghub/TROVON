static int dm_ulog_sendto_server(struct dm_ulog_request *tfr)
{
int r;
struct cn_msg *msg = prealloced_cn_msg;
memset(msg, 0, sizeof(struct cn_msg));
msg->id.idx = ulog_cn_id.idx;
msg->id.val = ulog_cn_id.val;
msg->ack = 0;
msg->seq = tfr->seq;
msg->len = sizeof(struct dm_ulog_request) + tfr->data_size;
r = cn_netlink_send(msg, 0, gfp_any());
return r;
}
static int fill_pkg(struct cn_msg *msg, struct dm_ulog_request *tfr)
{
uint32_t rtn_seq = (msg) ? msg->seq : (tfr) ? tfr->seq : 0;
struct receiving_pkg *pkg;
list_for_each_entry(pkg, &receiving_list, list) {
if (rtn_seq != pkg->seq)
continue;
if (msg) {
pkg->error = -msg->ack;
if (pkg->error != -EAGAIN)
*(pkg->data_size) = 0;
} else if (tfr->data_size > *(pkg->data_size)) {
DMERR("Insufficient space to receive package [%u] "
"(%u vs %zu)", tfr->request_type,
tfr->data_size, *(pkg->data_size));
*(pkg->data_size) = 0;
pkg->error = -ENOSPC;
} else {
pkg->error = tfr->error;
memcpy(pkg->data, tfr->data, tfr->data_size);
*(pkg->data_size) = tfr->data_size;
}
complete(&pkg->complete);
return 0;
}
return -ENOENT;
}
static void cn_ulog_callback(struct cn_msg *msg, struct netlink_skb_parms *nsp)
{
struct dm_ulog_request *tfr = (struct dm_ulog_request *)(msg + 1);
if (!cap_raised(current_cap(), CAP_SYS_ADMIN))
return;
spin_lock(&receiving_list_lock);
if (msg->len == 0)
fill_pkg(msg, NULL);
else if (msg->len < sizeof(*tfr))
DMERR("Incomplete message received (expected %u, got %u): [%u]",
(unsigned)sizeof(*tfr), msg->len, msg->seq);
else
fill_pkg(NULL, tfr);
spin_unlock(&receiving_list_lock);
}
int dm_consult_userspace(const char *uuid, uint64_t luid, int request_type,
char *data, size_t data_size,
char *rdata, size_t *rdata_size)
{
int r = 0;
size_t dummy = 0;
int overhead_size = sizeof(struct dm_ulog_request) + sizeof(struct cn_msg);
struct dm_ulog_request *tfr = prealloced_ulog_tfr;
struct receiving_pkg pkg;
if (data_size > (DM_ULOG_PREALLOCED_SIZE - overhead_size)) {
DMINFO("Size of tfr exceeds preallocated size");
return -EINVAL;
}
if (!rdata_size)
rdata_size = &dummy;
resend:
mutex_lock(&dm_ulog_lock);
memset(tfr, 0, DM_ULOG_PREALLOCED_SIZE - sizeof(struct cn_msg));
memcpy(tfr->uuid, uuid, DM_UUID_LEN);
tfr->version = DM_ULOG_REQUEST_VERSION;
tfr->luid = luid;
tfr->seq = dm_ulog_seq++;
tfr->request_type = request_type & DM_ULOG_REQUEST_MASK;
tfr->data_size = data_size;
if (data && data_size)
memcpy(tfr->data, data, data_size);
memset(&pkg, 0, sizeof(pkg));
init_completion(&pkg.complete);
pkg.seq = tfr->seq;
pkg.data_size = rdata_size;
pkg.data = rdata;
spin_lock(&receiving_list_lock);
list_add(&(pkg.list), &receiving_list);
spin_unlock(&receiving_list_lock);
r = dm_ulog_sendto_server(tfr);
mutex_unlock(&dm_ulog_lock);
if (r) {
DMERR("Unable to send log request [%u] to userspace: %d",
request_type, r);
spin_lock(&receiving_list_lock);
list_del_init(&(pkg.list));
spin_unlock(&receiving_list_lock);
goto out;
}
r = wait_for_completion_timeout(&(pkg.complete), DM_ULOG_RETRY_TIMEOUT);
spin_lock(&receiving_list_lock);
list_del_init(&(pkg.list));
spin_unlock(&receiving_list_lock);
if (!r) {
DMWARN("[%s] Request timed out: [%u/%u] - retrying",
(strlen(uuid) > 8) ?
(uuid + (strlen(uuid) - 8)) : (uuid),
request_type, pkg.seq);
goto resend;
}
r = pkg.error;
if (r == -EAGAIN)
goto resend;
out:
return r;
}
int dm_ulog_tfr_init(void)
{
int r;
void *prealloced;
INIT_LIST_HEAD(&receiving_list);
prealloced = kmalloc(DM_ULOG_PREALLOCED_SIZE, GFP_KERNEL);
if (!prealloced)
return -ENOMEM;
prealloced_cn_msg = prealloced;
prealloced_ulog_tfr = prealloced + sizeof(struct cn_msg);
r = cn_add_callback(&ulog_cn_id, "dmlogusr", cn_ulog_callback);
if (r) {
cn_del_callback(&ulog_cn_id);
return r;
}
return 0;
}
void dm_ulog_tfr_exit(void)
{
cn_del_callback(&ulog_cn_id);
kfree(prealloced_cn_msg);
}
