static void sclp_rw_pm_event(struct sclp_register *reg,
enum sclp_pm_event sclp_pm_event)
{
sclp_console_pm_event(sclp_pm_event);
}
struct sclp_buffer *
sclp_make_buffer(void *page, unsigned short columns, unsigned short htab)
{
struct sclp_buffer *buffer;
struct sccb_header *sccb;
sccb = (struct sccb_header *) page;
buffer = ((struct sclp_buffer *) ((addr_t) sccb + PAGE_SIZE)) - 1;
buffer->sccb = sccb;
buffer->retry_count = 0;
buffer->messages = 0;
buffer->char_sum = 0;
buffer->current_line = NULL;
buffer->current_length = 0;
buffer->columns = columns;
buffer->htab = htab;
memset(sccb, 0, sizeof(struct sccb_header));
sccb->length = sizeof(struct sccb_header);
return buffer;
}
void *
sclp_unmake_buffer(struct sclp_buffer *buffer)
{
return buffer->sccb;
}
static int
sclp_initialize_mto(struct sclp_buffer *buffer, int max_len)
{
struct sccb_header *sccb;
struct msg_buf *msg;
struct mdb *mdb;
struct go *go;
struct mto *mto;
int msg_size;
msg_size = sizeof(struct msg_buf) + max_len;
sccb = buffer->sccb;
if ((MAX_SCCB_ROOM - sccb->length) < msg_size)
return -ENOMEM;
msg = (struct msg_buf *)((addr_t) sccb + sccb->length);
memset(msg, 0, sizeof(struct msg_buf));
msg->header.length = sizeof(struct msg_buf);
msg->header.type = EVTYP_MSG;
mdb = &msg->mdb;
mdb->header.length = sizeof(struct mdb);
mdb->header.type = 1;
mdb->header.tag = 0xD4C4C240;
mdb->header.revision_code = 1;
go = &mdb->go;
go->length = sizeof(struct go);
go->type = 1;
mto = &mdb->mto;
mto->length = sizeof(struct mto);
mto->type = 4;
mto->line_type_flags = LNTPFLGS_ENDTEXT;
buffer->current_msg = msg;
buffer->current_line = (char *) (mto + 1);
buffer->current_length = 0;
return 0;
}
static void
sclp_finalize_mto(struct sclp_buffer *buffer)
{
struct sccb_header *sccb;
struct msg_buf *msg;
sccb = buffer->sccb;
msg = buffer->current_msg;
msg->header.length += buffer->current_length;
msg->mdb.header.length += buffer->current_length;
msg->mdb.mto.length += buffer->current_length;
sccb->length += msg->header.length;
buffer->messages++;
buffer->char_sum += buffer->current_length;
buffer->current_line = NULL;
buffer->current_length = 0;
buffer->current_msg = NULL;
}
int
sclp_write(struct sclp_buffer *buffer, const unsigned char *msg, int count)
{
int spaces, i_msg;
int rc;
for (i_msg = 0; i_msg < count; i_msg++) {
switch (msg[i_msg]) {
case '\n':
if (buffer->current_line == NULL) {
rc = sclp_initialize_mto(buffer, 0);
if (rc)
return i_msg;
}
sclp_finalize_mto(buffer);
break;
case '\a':
if (buffer->current_line == NULL) {
rc = sclp_initialize_mto(buffer,
buffer->columns);
if (rc)
return i_msg;
}
buffer->current_msg->mdb.go.general_msg_flags |=
GNRLMSGFLGS_SNDALRM;
break;
case '\t':
if (buffer->current_line == NULL) {
rc = sclp_initialize_mto(buffer,
buffer->columns);
if (rc)
return i_msg;
}
do {
if (buffer->current_length >= buffer->columns)
break;
*buffer->current_line++ = 0x40;
buffer->current_length++;
} while (buffer->current_length % buffer->htab);
break;
case '\f':
case '\v':
if (buffer->current_line != NULL) {
spaces = buffer->current_length;
sclp_finalize_mto(buffer);
rc = sclp_initialize_mto(buffer,
buffer->columns);
if (rc)
return i_msg;
memset(buffer->current_line, 0x40, spaces);
buffer->current_line += spaces;
buffer->current_length = spaces;
} else {
rc = sclp_initialize_mto(buffer,
buffer->columns);
if (rc)
return i_msg;
sclp_finalize_mto(buffer);
}
break;
case '\b':
if (buffer->current_line != NULL &&
buffer->current_length > 0) {
buffer->current_length--;
buffer->current_line--;
}
break;
case 0x00:
if (buffer->current_line != NULL)
sclp_finalize_mto(buffer);
i_msg = count - 1;
break;
default:
if (!isprint(msg[i_msg]))
break;
if (buffer->current_line == NULL) {
rc = sclp_initialize_mto(buffer,
buffer->columns);
if (rc)
return i_msg;
}
*buffer->current_line++ = sclp_ascebc(msg[i_msg]);
buffer->current_length++;
break;
}
if (buffer->current_line != NULL &&
buffer->current_length >= buffer->columns)
sclp_finalize_mto(buffer);
}
return i_msg;
}
int
sclp_buffer_space(struct sclp_buffer *buffer)
{
struct sccb_header *sccb;
int count;
sccb = buffer->sccb;
count = MAX_SCCB_ROOM - sccb->length;
if (buffer->current_line != NULL)
count -= sizeof(struct msg_buf) + buffer->current_length;
return count;
}
int
sclp_chars_in_buffer(struct sclp_buffer *buffer)
{
int count;
count = buffer->char_sum;
if (buffer->current_line != NULL)
count += buffer->current_length;
return count;
}
void
sclp_set_columns(struct sclp_buffer *buffer, unsigned short columns)
{
buffer->columns = columns;
if (buffer->current_line != NULL &&
buffer->current_length > buffer->columns)
sclp_finalize_mto(buffer);
}
void
sclp_set_htab(struct sclp_buffer *buffer, unsigned short htab)
{
buffer->htab = htab;
}
int
sclp_rw_init(void)
{
static int init_done = 0;
int rc;
if (init_done)
return 0;
rc = sclp_register(&sclp_rw_event);
if (rc == 0)
init_done = 1;
return rc;
}
static void
sclp_writedata_callback(struct sclp_req *request, void *data)
{
int rc;
struct sclp_buffer *buffer;
struct sccb_header *sccb;
buffer = (struct sclp_buffer *) data;
sccb = buffer->sccb;
if (request->status == SCLP_REQ_FAILED) {
if (buffer->callback != NULL)
buffer->callback(buffer, -EIO);
return;
}
switch (sccb->response_code) {
case 0x0020 :
rc = 0;
break;
case 0x0340:
if (++buffer->retry_count > SCLP_BUFFER_MAX_RETRY) {
rc = -EIO;
break;
}
if (sclp_remove_processed((struct sccb_header *) sccb) > 0) {
sccb->response_code = 0x0000;
buffer->request.status = SCLP_REQ_FILLED;
rc = sclp_add_request(request);
if (rc == 0)
return;
} else
rc = 0;
break;
case 0x0040:
case 0x05f0:
if (++buffer->retry_count > SCLP_BUFFER_MAX_RETRY) {
rc = -EIO;
break;
}
sccb->response_code = 0x0000;
buffer->request.status = SCLP_REQ_FILLED;
rc = sclp_add_request(request);
if (rc == 0)
return;
break;
default:
if (sccb->response_code == 0x71f0)
rc = -ENOMEM;
else
rc = -EINVAL;
break;
}
if (buffer->callback != NULL)
buffer->callback(buffer, rc);
}
int
sclp_emit_buffer(struct sclp_buffer *buffer,
void (*callback)(struct sclp_buffer *, int))
{
if (buffer->current_line != NULL)
sclp_finalize_mto(buffer);
if (buffer->messages == 0)
return -EIO;
buffer->request.command = SCLP_CMDW_WRITE_EVENT_DATA;
buffer->request.status = SCLP_REQ_FILLED;
buffer->request.callback = sclp_writedata_callback;
buffer->request.callback_data = buffer;
buffer->request.sccb = buffer->sccb;
buffer->callback = callback;
return sclp_add_request(&buffer->request);
}
