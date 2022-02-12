static void
unit_tracking_create(struct list_head *dev_list_link)
{
unsigned long flags;
spin_lock_irqsave(&Request_list_lock, flags);
list_add(dev_list_link, &Request_list);
spin_unlock_irqrestore(&Request_list_lock, flags);
}
static void
unit_tracking_destroy(struct list_head *dev_list_link)
{
unsigned long flags;
spin_lock_irqsave(&Request_list_lock, flags);
list_del(dev_list_link);
spin_unlock_irqrestore(&Request_list_lock, flags);
}
static struct any_request *
alloc_request(char *fn, int ln)
{
struct any_request *req = (struct any_request *)
(visorchipset_cache_alloc(Request_memory_pool,
FALSE,
fn, ln));
if (!req)
return NULL;
memset(req, 0, sizeof(struct any_request) + Caller_req_context_bytes);
unit_tracking_create(&req->req_list);
return req;
}
static void
free_request(struct any_request *req, char *fn, int ln)
{
unit_tracking_destroy(&req->req_list);
visorchipset_cache_free(Request_memory_pool, req, fn, ln);
}
int
filexfer_constructor(size_t req_context_bytes)
{
int rc = -1;
Caller_req_context_bytes = req_context_bytes;
Request_memory_pool =
kmem_cache_create(Request_memory_pool_name,
sizeof(struct any_request) +
Caller_req_context_bytes,
0, SLAB_HWCACHE_ALIGN, NULL);
if (!Request_memory_pool) {
LOGERR("failed to alloc Request_memory_pool");
rc = -ENOMEM;
goto Away;
}
rc = 0;
Away:
if (rc < 0) {
if (Request_memory_pool) {
kmem_cache_destroy(Request_memory_pool);
Request_memory_pool = NULL;
}
}
return rc;
}
void
filexfer_destructor(void)
{
if (Request_memory_pool) {
kmem_cache_destroy(Request_memory_pool);
Request_memory_pool = NULL;
}
}
static void *
get_empty_bucket_for_getfile_data(void *context,
ulong min_size, ulong max_size,
ulong *actual_size)
{
void *bucket;
struct any_request *req = (struct any_request *) context;
if (!req->is_get) {
LOGERR("%s - unexpected call", __func__);
return NULL;
}
bucket = (*req->get.get_contiguous_controlvm_payload)
(min_size, max_size, actual_size);
if (bucket != NULL) {
atomic_inc(&req->get.buffers_in_use);
DBGINF("%s - sent %lu-byte buffer", __func__, *actual_size);
}
return bucket;
}
static int
send_full_getfile_data_bucket(void *context, void *bucket,
ulong bucket_actual_size, ulong bucket_used_size)
{
struct any_request *req = (struct any_request *) context;
if (!req->is_get) {
LOGERR("%s - unexpected call", __func__);
return 0;
}
DBGINF("sending buffer for %lu/%lu",
bucket_used_size, bucket_actual_size);
if (!(*req->get.controlvm_respond_with_payload)
(&req->get.controlvm_header,
req->file_request_number,
req->data_sequence_number++,
0, bucket, bucket_actual_size, bucket_used_size, TRUE))
atomic_dec(&req->get.buffers_in_use);
return 0;
}
static void
send_end_of_getfile_data(void *context, int status)
{
struct any_request *req = (struct any_request *) context;
if (!req->is_get) {
LOGERR("%s - unexpected call", __func__);
return;
}
LOGINF("status=%d", status);
(*req->get.controlvm_respond_with_payload)
(&req->get.controlvm_header,
req->file_request_number,
req->data_sequence_number++, status, NULL, 0, 0, FALSE);
free_request(req, __FILE__, __LINE__);
module_put(THIS_MODULE);
}
static int
get_putfile_data(void *context, void *pbuf, size_t bufsize,
BOOL buf_is_userspace, size_t *bytes_transferred)
{
struct any_request *req = (struct any_request *) context;
if (req->is_get) {
LOGERR("%s - unexpected call", __func__);
return -1;
}
return (*req->put.get_controlvm_filedata) (&req->caller_context_data[0],
pbuf, bufsize,
buf_is_userspace,
bytes_transferred);
}
static void
end_putfile(void *context, int status)
{
struct any_request *req = (struct any_request *) context;
if (req->is_get) {
LOGERR("%s - unexpected call", __func__);
return;
}
(*req->put.controlvm_end_putFile) (&req->caller_context_data[0],
status);
free_request(req, __FILE__, __LINE__);
module_put(THIS_MODULE);
}
BOOL
filexfer_getFile(CONTROLVM_MESSAGE_HEADER *msgHdr,
ulong2 file_request_number,
uint uplink_index,
uint disk_index,
char *file_name,
GET_CONTIGUOUS_CONTROLVM_PAYLOAD_FUNC
get_contiguous_controlvm_payload,
CONTROLVM_RESPOND_WITH_PAYLOAD_FUNC
controlvm_respond_with_payload,
TRANSMITFILE_DUMP_FUNC dump_func)
{
BOOL use_count_up = FALSE;
BOOL failed = TRUE;
struct any_request *req = alloc_request(__FILE__, __LINE__);
if (!req) {
LOGERR("allocation of any_request failed");
goto Away;
}
__module_get(THIS_MODULE);
use_count_up = TRUE;
req->is_get = TRUE;
req->file_request_number = file_request_number;
req->data_sequence_number = 0;
req->dump_func = dump_func;
req->get.controlvm_header = *msgHdr;
atomic_set(&req->get.buffers_in_use, 0);
req->get.get_contiguous_controlvm_payload =
get_contiguous_controlvm_payload;
req->get.controlvm_respond_with_payload =
controlvm_respond_with_payload;
if (sparfilexfer_local2remote(req,
file_name,
file_request_number,
uplink_index,
disk_index,
get_empty_bucket_for_getfile_data,
send_full_getfile_data_bucket,
send_end_of_getfile_data) < 0) {
LOGERR("sparfilexfer_local2remote failed");
goto Away;
}
failed = FALSE;
Away:
if (failed) {
if (use_count_up) {
module_put(THIS_MODULE);
use_count_up = FALSE;
}
if (req) {
free_request(req, __FILE__, __LINE__);
req = NULL;
}
return FALSE;
} else {
return TRUE;
}
}
void *
filexfer_putFile(CONTROLVM_MESSAGE_HEADER *msgHdr,
ulong2 file_request_number,
uint uplink_index,
uint disk_index,
char *file_name,
TRANSMITFILE_INIT_CONTEXT_FUNC init_context,
GET_CONTROLVM_FILEDATA_FUNC get_controlvm_filedata,
CONTROLVM_RESPOND_FUNC controlvm_end_putFile,
TRANSMITFILE_DUMP_FUNC dump_func)
{
BOOL use_count_up = FALSE;
BOOL failed = TRUE;
struct any_request *req = alloc_request(__FILE__, __LINE__);
void *caller_ctx = NULL;
if (!req) {
LOGERR("allocation of any_request failed");
goto Away;
}
caller_ctx = (void *) (&(req->caller_context_data[0]));
__module_get(THIS_MODULE);
use_count_up = TRUE;
req->is_get = FALSE;
req->file_request_number = file_request_number;
req->data_sequence_number = 0;
req->dump_func = dump_func;
req->put.get_controlvm_filedata = get_controlvm_filedata;
req->put.controlvm_end_putFile = controlvm_end_putFile;
(*init_context) (caller_ctx, msgHdr, file_request_number);
if (sparfilexfer_remote2local(req,
file_name,
file_request_number,
uplink_index,
disk_index,
get_putfile_data, end_putfile) < 0) {
LOGERR("sparfilexfer_remote2local failed");
goto Away;
}
failed = FALSE;
Away:
if (failed) {
if (use_count_up) {
module_put(THIS_MODULE);
use_count_up = FALSE;
}
if (req) {
free_request(req, __FILE__, __LINE__);
req = NULL;
}
return NULL;
} else {
return caller_ctx;
}
}
static void
dump_get_request(struct seq_file *f, struct getfile_request *getreq)
{
seq_printf(f, " buffers_in_use=%d\n",
atomic_read(&getreq->buffers_in_use));
}
static void
dump_put_request(struct seq_file *f, struct putfile_request *putreq)
{
}
static void
dump_request(struct seq_file *f, struct any_request *req)
{
seq_printf(f, "* %s id=%llu seq=%llu\n",
((req->is_get) ? "Get" : "Put"),
req->file_request_number, req->data_sequence_number);
if (req->is_get)
dump_get_request(f, &req->get);
else
dump_put_request(f, &req->put);
if (req->dump_func)
(*req->dump_func) (f, &(req->caller_context_data[0]), " ");
}
void
filexfer_dump(struct seq_file *f)
{
ulong flags;
struct list_head *entry;
seq_puts(f, "Outstanding TRANSMIT_FILE requests:\n");
spin_lock_irqsave(&Request_list_lock, flags);
list_for_each(entry, &Request_list) {
struct any_request *req;
req = list_entry(entry, struct any_request, req_list);
dump_request(f, req);
}
spin_unlock_irqrestore(&Request_list_lock, flags);
}
int
filexfer_constructor(size_t req_context_bytes)
{
return 0;
}
void
filexfer_destructor(void)
{
}
BOOL
filexfer_getFile(CONTROLVM_MESSAGE_HEADER *msgHdr,
u64 file_request_number,
uint uplink_index,
uint disk_index,
char *file_name,
GET_CONTIGUOUS_CONTROLVM_PAYLOAD_FUNC
get_contiguous_controlvm_payload,
CONTROLVM_RESPOND_WITH_PAYLOAD_FUNC
controlvm_respond_with_payload,
TRANSMITFILE_DUMP_FUNC dump_func)
{
return FALSE;
}
void *
filexfer_putFile(CONTROLVM_MESSAGE_HEADER *msgHdr,
u64 file_request_number,
uint uplink_index,
uint disk_index,
char *file_name,
TRANSMITFILE_INIT_CONTEXT_FUNC init_context,
GET_CONTROLVM_FILEDATA_FUNC get_controlvm_filedata,
CONTROLVM_RESPOND_FUNC controlvm_end_putFile,
TRANSMITFILE_DUMP_FUNC dump_func)
{
return NULL;
}
void
filexfer_dump(struct seq_file *f)
{
}
