static void p9_mux_poll_stop(struct p9_conn *m)
{
unsigned long flags;
int i;
for (i = 0; i < ARRAY_SIZE(m->poll_wait); i++) {
struct p9_poll_wait *pwait = &m->poll_wait[i];
if (pwait->wait_addr) {
remove_wait_queue(pwait->wait_addr, &pwait->wait);
pwait->wait_addr = NULL;
}
}
spin_lock_irqsave(&p9_poll_lock, flags);
list_del_init(&m->poll_pending_link);
spin_unlock_irqrestore(&p9_poll_lock, flags);
}
static void p9_conn_cancel(struct p9_conn *m, int err)
{
struct p9_req_t *req, *rtmp;
unsigned long flags;
LIST_HEAD(cancel_list);
p9_debug(P9_DEBUG_ERROR, "mux %p err %d\n", m, err);
spin_lock_irqsave(&m->client->lock, flags);
if (m->err) {
spin_unlock_irqrestore(&m->client->lock, flags);
return;
}
m->err = err;
list_for_each_entry_safe(req, rtmp, &m->req_list, req_list) {
req->status = REQ_STATUS_ERROR;
if (!req->t_err)
req->t_err = err;
list_move(&req->req_list, &cancel_list);
}
list_for_each_entry_safe(req, rtmp, &m->unsent_req_list, req_list) {
req->status = REQ_STATUS_ERROR;
if (!req->t_err)
req->t_err = err;
list_move(&req->req_list, &cancel_list);
}
spin_unlock_irqrestore(&m->client->lock, flags);
list_for_each_entry_safe(req, rtmp, &cancel_list, req_list) {
p9_debug(P9_DEBUG_ERROR, "call back req %p\n", req);
list_del(&req->req_list);
p9_client_cb(m->client, req);
}
}
static int
p9_fd_poll(struct p9_client *client, struct poll_table_struct *pt)
{
int ret, n;
struct p9_trans_fd *ts = NULL;
if (client && client->status == Connected)
ts = client->trans;
if (!ts)
return -EREMOTEIO;
if (!ts->rd->f_op || !ts->rd->f_op->poll)
return -EIO;
if (!ts->wr->f_op || !ts->wr->f_op->poll)
return -EIO;
ret = ts->rd->f_op->poll(ts->rd, pt);
if (ret < 0)
return ret;
if (ts->rd != ts->wr) {
n = ts->wr->f_op->poll(ts->wr, pt);
if (n < 0)
return n;
ret = (ret & ~POLLOUT) | (n & ~POLLIN);
}
return ret;
}
static int p9_fd_read(struct p9_client *client, void *v, int len)
{
int ret;
struct p9_trans_fd *ts = NULL;
if (client && client->status != Disconnected)
ts = client->trans;
if (!ts)
return -EREMOTEIO;
if (!(ts->rd->f_flags & O_NONBLOCK))
p9_debug(P9_DEBUG_ERROR, "blocking read ...\n");
ret = kernel_read(ts->rd, ts->rd->f_pos, v, len);
if (ret <= 0 && ret != -ERESTARTSYS && ret != -EAGAIN)
client->status = Disconnected;
return ret;
}
static void p9_read_work(struct work_struct *work)
{
int n, err;
struct p9_conn *m;
m = container_of(work, struct p9_conn, rq);
if (m->err < 0)
return;
p9_debug(P9_DEBUG_TRANS, "start mux %p pos %d\n", m, m->rpos);
if (!m->rbuf) {
m->rbuf = m->tmp_buf;
m->rpos = 0;
m->rsize = 7;
}
clear_bit(Rpending, &m->wsched);
p9_debug(P9_DEBUG_TRANS, "read mux %p pos %d size: %d = %d\n",
m, m->rpos, m->rsize, m->rsize-m->rpos);
err = p9_fd_read(m->client, m->rbuf + m->rpos,
m->rsize - m->rpos);
p9_debug(P9_DEBUG_TRANS, "mux %p got %d bytes\n", m, err);
if (err == -EAGAIN) {
clear_bit(Rworksched, &m->wsched);
return;
}
if (err <= 0)
goto error;
m->rpos += err;
if ((!m->req) && (m->rpos == m->rsize)) {
u16 tag;
p9_debug(P9_DEBUG_TRANS, "got new header\n");
n = le32_to_cpu(*(__le32 *) m->rbuf);
if (n >= m->client->msize) {
p9_debug(P9_DEBUG_ERROR,
"requested packet size too big: %d\n", n);
err = -EIO;
goto error;
}
tag = le16_to_cpu(*(__le16 *) (m->rbuf+5));
p9_debug(P9_DEBUG_TRANS,
"mux %p pkt: size: %d bytes tag: %d\n", m, n, tag);
m->req = p9_tag_lookup(m->client, tag);
if (!m->req || (m->req->status != REQ_STATUS_SENT &&
m->req->status != REQ_STATUS_FLSH)) {
p9_debug(P9_DEBUG_ERROR, "Unexpected packet tag %d\n",
tag);
err = -EIO;
goto error;
}
if (m->req->rc == NULL) {
m->req->rc = kmalloc(sizeof(struct p9_fcall) +
m->client->msize, GFP_NOFS);
if (!m->req->rc) {
m->req = NULL;
err = -ENOMEM;
goto error;
}
}
m->rbuf = (char *)m->req->rc + sizeof(struct p9_fcall);
memcpy(m->rbuf, m->tmp_buf, m->rsize);
m->rsize = n;
}
if ((m->req) && (m->rpos == m->rsize)) {
p9_debug(P9_DEBUG_TRANS, "got new packet\n");
spin_lock(&m->client->lock);
if (m->req->status != REQ_STATUS_ERROR)
m->req->status = REQ_STATUS_RCVD;
list_del(&m->req->req_list);
spin_unlock(&m->client->lock);
p9_client_cb(m->client, m->req);
m->rbuf = NULL;
m->rpos = 0;
m->rsize = 0;
m->req = NULL;
}
if (!list_empty(&m->req_list)) {
if (test_and_clear_bit(Rpending, &m->wsched))
n = POLLIN;
else
n = p9_fd_poll(m->client, NULL);
if (n & POLLIN) {
p9_debug(P9_DEBUG_TRANS, "sched read work %p\n", m);
schedule_work(&m->rq);
} else
clear_bit(Rworksched, &m->wsched);
} else
clear_bit(Rworksched, &m->wsched);
return;
error:
p9_conn_cancel(m, err);
clear_bit(Rworksched, &m->wsched);
}
static int p9_fd_write(struct p9_client *client, void *v, int len)
{
int ret;
mm_segment_t oldfs;
struct p9_trans_fd *ts = NULL;
if (client && client->status != Disconnected)
ts = client->trans;
if (!ts)
return -EREMOTEIO;
if (!(ts->wr->f_flags & O_NONBLOCK))
p9_debug(P9_DEBUG_ERROR, "blocking write ...\n");
oldfs = get_fs();
set_fs(get_ds());
ret = vfs_write(ts->wr, (__force void __user *)v, len, &ts->wr->f_pos);
set_fs(oldfs);
if (ret <= 0 && ret != -ERESTARTSYS && ret != -EAGAIN)
client->status = Disconnected;
return ret;
}
static void p9_write_work(struct work_struct *work)
{
int n, err;
struct p9_conn *m;
struct p9_req_t *req;
m = container_of(work, struct p9_conn, wq);
if (m->err < 0) {
clear_bit(Wworksched, &m->wsched);
return;
}
if (!m->wsize) {
if (list_empty(&m->unsent_req_list)) {
clear_bit(Wworksched, &m->wsched);
return;
}
spin_lock(&m->client->lock);
req = list_entry(m->unsent_req_list.next, struct p9_req_t,
req_list);
req->status = REQ_STATUS_SENT;
p9_debug(P9_DEBUG_TRANS, "move req %p\n", req);
list_move_tail(&req->req_list, &m->req_list);
m->wbuf = req->tc->sdata;
m->wsize = req->tc->size;
m->wpos = 0;
spin_unlock(&m->client->lock);
}
p9_debug(P9_DEBUG_TRANS, "mux %p pos %d size %d\n",
m, m->wpos, m->wsize);
clear_bit(Wpending, &m->wsched);
err = p9_fd_write(m->client, m->wbuf + m->wpos, m->wsize - m->wpos);
p9_debug(P9_DEBUG_TRANS, "mux %p sent %d bytes\n", m, err);
if (err == -EAGAIN) {
clear_bit(Wworksched, &m->wsched);
return;
}
if (err < 0)
goto error;
else if (err == 0) {
err = -EREMOTEIO;
goto error;
}
m->wpos += err;
if (m->wpos == m->wsize)
m->wpos = m->wsize = 0;
if (m->wsize == 0 && !list_empty(&m->unsent_req_list)) {
if (test_and_clear_bit(Wpending, &m->wsched))
n = POLLOUT;
else
n = p9_fd_poll(m->client, NULL);
if (n & POLLOUT) {
p9_debug(P9_DEBUG_TRANS, "sched write work %p\n", m);
schedule_work(&m->wq);
} else
clear_bit(Wworksched, &m->wsched);
} else
clear_bit(Wworksched, &m->wsched);
return;
error:
p9_conn_cancel(m, err);
clear_bit(Wworksched, &m->wsched);
}
static int p9_pollwake(wait_queue_t *wait, unsigned mode, int sync, void *key)
{
struct p9_poll_wait *pwait =
container_of(wait, struct p9_poll_wait, wait);
struct p9_conn *m = pwait->conn;
unsigned long flags;
spin_lock_irqsave(&p9_poll_lock, flags);
if (list_empty(&m->poll_pending_link))
list_add_tail(&m->poll_pending_link, &p9_poll_pending_list);
spin_unlock_irqrestore(&p9_poll_lock, flags);
schedule_work(&p9_poll_work);
return 1;
}
static void
p9_pollwait(struct file *filp, wait_queue_head_t *wait_address, poll_table *p)
{
struct p9_conn *m = container_of(p, struct p9_conn, pt);
struct p9_poll_wait *pwait = NULL;
int i;
for (i = 0; i < ARRAY_SIZE(m->poll_wait); i++) {
if (m->poll_wait[i].wait_addr == NULL) {
pwait = &m->poll_wait[i];
break;
}
}
if (!pwait) {
p9_debug(P9_DEBUG_ERROR, "not enough wait_address slots\n");
return;
}
pwait->conn = m;
pwait->wait_addr = wait_address;
init_waitqueue_func_entry(&pwait->wait, p9_pollwake);
add_wait_queue(wait_address, &pwait->wait);
}
static struct p9_conn *p9_conn_create(struct p9_client *client)
{
int n;
struct p9_conn *m;
p9_debug(P9_DEBUG_TRANS, "client %p msize %d\n", client, client->msize);
m = kzalloc(sizeof(struct p9_conn), GFP_KERNEL);
if (!m)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&m->mux_list);
m->client = client;
INIT_LIST_HEAD(&m->req_list);
INIT_LIST_HEAD(&m->unsent_req_list);
INIT_WORK(&m->rq, p9_read_work);
INIT_WORK(&m->wq, p9_write_work);
INIT_LIST_HEAD(&m->poll_pending_link);
init_poll_funcptr(&m->pt, p9_pollwait);
n = p9_fd_poll(client, &m->pt);
if (n & POLLIN) {
p9_debug(P9_DEBUG_TRANS, "mux %p can read\n", m);
set_bit(Rpending, &m->wsched);
}
if (n & POLLOUT) {
p9_debug(P9_DEBUG_TRANS, "mux %p can write\n", m);
set_bit(Wpending, &m->wsched);
}
return m;
}
static void p9_poll_mux(struct p9_conn *m)
{
int n;
if (m->err < 0)
return;
n = p9_fd_poll(m->client, NULL);
if (n < 0 || n & (POLLERR | POLLHUP | POLLNVAL)) {
p9_debug(P9_DEBUG_TRANS, "error mux %p err %d\n", m, n);
if (n >= 0)
n = -ECONNRESET;
p9_conn_cancel(m, n);
}
if (n & POLLIN) {
set_bit(Rpending, &m->wsched);
p9_debug(P9_DEBUG_TRANS, "mux %p can read\n", m);
if (!test_and_set_bit(Rworksched, &m->wsched)) {
p9_debug(P9_DEBUG_TRANS, "sched read work %p\n", m);
schedule_work(&m->rq);
}
}
if (n & POLLOUT) {
set_bit(Wpending, &m->wsched);
p9_debug(P9_DEBUG_TRANS, "mux %p can write\n", m);
if ((m->wsize || !list_empty(&m->unsent_req_list)) &&
!test_and_set_bit(Wworksched, &m->wsched)) {
p9_debug(P9_DEBUG_TRANS, "sched write work %p\n", m);
schedule_work(&m->wq);
}
}
}
static int p9_fd_request(struct p9_client *client, struct p9_req_t *req)
{
int n;
struct p9_trans_fd *ts = client->trans;
struct p9_conn *m = ts->conn;
p9_debug(P9_DEBUG_TRANS, "mux %p task %p tcall %p id %d\n",
m, current, req->tc, req->tc->id);
if (m->err < 0)
return m->err;
spin_lock(&client->lock);
req->status = REQ_STATUS_UNSENT;
list_add_tail(&req->req_list, &m->unsent_req_list);
spin_unlock(&client->lock);
if (test_and_clear_bit(Wpending, &m->wsched))
n = POLLOUT;
else
n = p9_fd_poll(m->client, NULL);
if (n & POLLOUT && !test_and_set_bit(Wworksched, &m->wsched))
schedule_work(&m->wq);
return 0;
}
static int p9_fd_cancel(struct p9_client *client, struct p9_req_t *req)
{
int ret = 1;
p9_debug(P9_DEBUG_TRANS, "client %p req %p\n", client, req);
spin_lock(&client->lock);
if (req->status == REQ_STATUS_UNSENT) {
list_del(&req->req_list);
req->status = REQ_STATUS_FLSHD;
ret = 0;
} else if (req->status == REQ_STATUS_SENT)
req->status = REQ_STATUS_FLSH;
spin_unlock(&client->lock);
return ret;
}
static int parse_opts(char *params, struct p9_fd_opts *opts)
{
char *p;
substring_t args[MAX_OPT_ARGS];
int option;
char *options, *tmp_options;
opts->port = P9_PORT;
opts->rfd = ~0;
opts->wfd = ~0;
if (!params)
return 0;
tmp_options = kstrdup(params, GFP_KERNEL);
if (!tmp_options) {
p9_debug(P9_DEBUG_ERROR,
"failed to allocate copy of option string\n");
return -ENOMEM;
}
options = tmp_options;
while ((p = strsep(&options, ",")) != NULL) {
int token;
int r;
if (!*p)
continue;
token = match_token(p, tokens, args);
if (token != Opt_err) {
r = match_int(&args[0], &option);
if (r < 0) {
p9_debug(P9_DEBUG_ERROR,
"integer field, but no integer?\n");
continue;
}
}
switch (token) {
case Opt_port:
opts->port = option;
break;
case Opt_rfdno:
opts->rfd = option;
break;
case Opt_wfdno:
opts->wfd = option;
break;
default:
continue;
}
}
kfree(tmp_options);
return 0;
}
static int p9_fd_open(struct p9_client *client, int rfd, int wfd)
{
struct p9_trans_fd *ts = kmalloc(sizeof(struct p9_trans_fd),
GFP_KERNEL);
if (!ts)
return -ENOMEM;
ts->rd = fget(rfd);
ts->wr = fget(wfd);
if (!ts->rd || !ts->wr) {
if (ts->rd)
fput(ts->rd);
if (ts->wr)
fput(ts->wr);
kfree(ts);
return -EIO;
}
client->trans = ts;
client->status = Connected;
return 0;
}
static int p9_socket_open(struct p9_client *client, struct socket *csocket)
{
struct p9_trans_fd *p;
int ret, fd;
p = kmalloc(sizeof(struct p9_trans_fd), GFP_KERNEL);
if (!p)
return -ENOMEM;
csocket->sk->sk_allocation = GFP_NOIO;
fd = sock_map_fd(csocket, 0);
if (fd < 0) {
pr_err("%s (%d): failed to map fd\n",
__func__, task_pid_nr(current));
sock_release(csocket);
kfree(p);
return fd;
}
get_file(csocket->file);
get_file(csocket->file);
p->wr = p->rd = csocket->file;
client->trans = p;
client->status = Connected;
sys_close(fd);
p->rd->f_flags |= O_NONBLOCK;
p->conn = p9_conn_create(client);
if (IS_ERR(p->conn)) {
ret = PTR_ERR(p->conn);
p->conn = NULL;
kfree(p);
sockfd_put(csocket);
sockfd_put(csocket);
return ret;
}
return 0;
}
static void p9_conn_destroy(struct p9_conn *m)
{
p9_debug(P9_DEBUG_TRANS, "mux %p prev %p next %p\n",
m, m->mux_list.prev, m->mux_list.next);
p9_mux_poll_stop(m);
cancel_work_sync(&m->rq);
cancel_work_sync(&m->wq);
p9_conn_cancel(m, -ECONNRESET);
m->client = NULL;
kfree(m);
}
static void p9_fd_close(struct p9_client *client)
{
struct p9_trans_fd *ts;
if (!client)
return;
ts = client->trans;
if (!ts)
return;
client->status = Disconnected;
p9_conn_destroy(ts->conn);
if (ts->rd)
fput(ts->rd);
if (ts->wr)
fput(ts->wr);
kfree(ts);
}
static inline int valid_ipaddr4(const char *buf)
{
int rc, count, in[4];
rc = sscanf(buf, "%d.%d.%d.%d", &in[0], &in[1], &in[2], &in[3]);
if (rc != 4)
return -EINVAL;
for (count = 0; count < 4; count++) {
if (in[count] > 255)
return -EINVAL;
}
return 0;
}
static int
p9_fd_create_tcp(struct p9_client *client, const char *addr, char *args)
{
int err;
struct socket *csocket;
struct sockaddr_in sin_server;
struct p9_fd_opts opts;
err = parse_opts(args, &opts);
if (err < 0)
return err;
if (valid_ipaddr4(addr) < 0)
return -EINVAL;
csocket = NULL;
sin_server.sin_family = AF_INET;
sin_server.sin_addr.s_addr = in_aton(addr);
sin_server.sin_port = htons(opts.port);
err = __sock_create(read_pnet(&current->nsproxy->net_ns), PF_INET,
SOCK_STREAM, IPPROTO_TCP, &csocket, 1);
if (err) {
pr_err("%s (%d): problem creating socket\n",
__func__, task_pid_nr(current));
return err;
}
err = csocket->ops->connect(csocket,
(struct sockaddr *)&sin_server,
sizeof(struct sockaddr_in), 0);
if (err < 0) {
pr_err("%s (%d): problem connecting socket to %s\n",
__func__, task_pid_nr(current), addr);
sock_release(csocket);
return err;
}
return p9_socket_open(client, csocket);
}
static int
p9_fd_create_unix(struct p9_client *client, const char *addr, char *args)
{
int err;
struct socket *csocket;
struct sockaddr_un sun_server;
csocket = NULL;
if (strlen(addr) >= UNIX_PATH_MAX) {
pr_err("%s (%d): address too long: %s\n",
__func__, task_pid_nr(current), addr);
return -ENAMETOOLONG;
}
sun_server.sun_family = PF_UNIX;
strcpy(sun_server.sun_path, addr);
err = __sock_create(read_pnet(&current->nsproxy->net_ns), PF_UNIX,
SOCK_STREAM, 0, &csocket, 1);
if (err < 0) {
pr_err("%s (%d): problem creating socket\n",
__func__, task_pid_nr(current));
return err;
}
err = csocket->ops->connect(csocket, (struct sockaddr *)&sun_server,
sizeof(struct sockaddr_un) - 1, 0);
if (err < 0) {
pr_err("%s (%d): problem connecting socket: %s: %d\n",
__func__, task_pid_nr(current), addr, err);
sock_release(csocket);
return err;
}
return p9_socket_open(client, csocket);
}
static int
p9_fd_create(struct p9_client *client, const char *addr, char *args)
{
int err;
struct p9_fd_opts opts;
struct p9_trans_fd *p;
parse_opts(args, &opts);
if (opts.rfd == ~0 || opts.wfd == ~0) {
pr_err("Insufficient options for proto=fd\n");
return -ENOPROTOOPT;
}
err = p9_fd_open(client, opts.rfd, opts.wfd);
if (err < 0)
return err;
p = (struct p9_trans_fd *) client->trans;
p->conn = p9_conn_create(client);
if (IS_ERR(p->conn)) {
err = PTR_ERR(p->conn);
p->conn = NULL;
fput(p->rd);
fput(p->wr);
return err;
}
return 0;
}
static void p9_poll_workfn(struct work_struct *work)
{
unsigned long flags;
p9_debug(P9_DEBUG_TRANS, "start %p\n", current);
spin_lock_irqsave(&p9_poll_lock, flags);
while (!list_empty(&p9_poll_pending_list)) {
struct p9_conn *conn = list_first_entry(&p9_poll_pending_list,
struct p9_conn,
poll_pending_link);
list_del_init(&conn->poll_pending_link);
spin_unlock_irqrestore(&p9_poll_lock, flags);
p9_poll_mux(conn);
spin_lock_irqsave(&p9_poll_lock, flags);
}
spin_unlock_irqrestore(&p9_poll_lock, flags);
p9_debug(P9_DEBUG_TRANS, "finish\n");
}
int p9_trans_fd_init(void)
{
v9fs_register_trans(&p9_tcp_trans);
v9fs_register_trans(&p9_unix_trans);
v9fs_register_trans(&p9_fd_trans);
return 0;
}
void p9_trans_fd_exit(void)
{
flush_work_sync(&p9_poll_work);
v9fs_unregister_trans(&p9_tcp_trans);
v9fs_unregister_trans(&p9_unix_trans);
v9fs_unregister_trans(&p9_fd_trans);
}
