int
lnet_acceptor_port(void)
{
return accept_port;
}
static inline int
lnet_accept_magic(__u32 magic, __u32 constant)
{
return (magic == constant ||
magic == __swab32(constant));
}
int
lnet_acceptor_get_tunables(void)
{
accept_type = accept;
return 0;
}
int
lnet_acceptor_timeout(void)
{
return accept_timeout;
}
void
lnet_connect_console_error (int rc, lnet_nid_t peer_nid,
__u32 peer_ip, int peer_port)
{
switch (rc) {
case -ECONNREFUSED:
CNETERR("Connection to %s at host %pI4h on port %d was "
"refused: check that Lustre is running on that node.\n",
libcfs_nid2str(peer_nid),
&peer_ip, peer_port);
break;
case -EHOSTUNREACH:
case -ENETUNREACH:
CNETERR("Connection to %s at host %pI4h "
"was unreachable: the network or that node may "
"be down, or Lustre may be misconfigured.\n",
libcfs_nid2str(peer_nid), &peer_ip);
break;
case -ETIMEDOUT:
CNETERR("Connection to %s at host %pI4h on "
"port %d took too long: that node may be hung "
"or experiencing high load.\n",
libcfs_nid2str(peer_nid),
&peer_ip, peer_port);
break;
case -ECONNRESET:
LCONSOLE_ERROR_MSG(0x11b, "Connection to %s at host %pI4h"
" on port %d was reset: "
"is it running a compatible version of "
"Lustre and is %s one of its NIDs?\n",
libcfs_nid2str(peer_nid),
&peer_ip, peer_port,
libcfs_nid2str(peer_nid));
break;
case -EPROTO:
LCONSOLE_ERROR_MSG(0x11c, "Protocol error connecting to %s at "
"host %pI4h on port %d: is it running "
"a compatible version of Lustre?\n",
libcfs_nid2str(peer_nid),
&peer_ip, peer_port);
break;
case -EADDRINUSE:
LCONSOLE_ERROR_MSG(0x11d, "No privileged ports available to "
"connect to %s at host %pI4h on port "
"%d\n", libcfs_nid2str(peer_nid),
&peer_ip, peer_port);
break;
default:
LCONSOLE_ERROR_MSG(0x11e, "Unexpected error %d connecting to %s"
" at host %pI4h on port %d\n", rc,
libcfs_nid2str(peer_nid),
&peer_ip, peer_port);
break;
}
}
int
lnet_connect(socket_t **sockp, lnet_nid_t peer_nid,
__u32 local_ip, __u32 peer_ip, int peer_port)
{
lnet_acceptor_connreq_t cr;
socket_t *sock;
int rc;
int port;
int fatal;
CLASSERT (sizeof(cr) <= 16);
for (port = LNET_ACCEPTOR_MAX_RESERVED_PORT;
port >= LNET_ACCEPTOR_MIN_RESERVED_PORT;
--port) {
rc = libcfs_sock_connect(&sock, &fatal,
local_ip, port,
peer_ip, peer_port);
if (rc != 0) {
if (fatal)
goto failed;
continue;
}
CLASSERT (LNET_PROTO_ACCEPTOR_VERSION == 1);
cr.acr_magic = LNET_PROTO_ACCEPTOR_MAGIC;
cr.acr_version = LNET_PROTO_ACCEPTOR_VERSION;
cr.acr_nid = peer_nid;
if (the_lnet.ln_testprotocompat != 0) {
lnet_net_lock(LNET_LOCK_EX);
if ((the_lnet.ln_testprotocompat & 4) != 0) {
cr.acr_version++;
the_lnet.ln_testprotocompat &= ~4;
}
if ((the_lnet.ln_testprotocompat & 8) != 0) {
cr.acr_magic = LNET_PROTO_MAGIC;
the_lnet.ln_testprotocompat &= ~8;
}
lnet_net_unlock(LNET_LOCK_EX);
}
rc = libcfs_sock_write(sock, &cr, sizeof(cr),
accept_timeout);
if (rc != 0)
goto failed_sock;
*sockp = sock;
return 0;
}
rc = -EADDRINUSE;
goto failed;
failed_sock:
libcfs_sock_release(sock);
failed:
lnet_connect_console_error(rc, peer_nid, peer_ip, peer_port);
return rc;
}
int
lnet_accept(socket_t *sock, __u32 magic)
{
lnet_acceptor_connreq_t cr;
__u32 peer_ip;
int peer_port;
int rc;
int flip;
lnet_ni_t *ni;
char *str;
LASSERT (sizeof(cr) <= 16);
rc = libcfs_sock_getaddr(sock, 1, &peer_ip, &peer_port);
LASSERT (rc == 0);
if (!lnet_accept_magic(magic, LNET_PROTO_ACCEPTOR_MAGIC)) {
if (lnet_accept_magic(magic, LNET_PROTO_MAGIC)) {
memset (&cr, 0, sizeof(cr));
cr.acr_magic = LNET_PROTO_ACCEPTOR_MAGIC;
cr.acr_version = LNET_PROTO_ACCEPTOR_VERSION;
rc = libcfs_sock_write(sock, &cr, sizeof(cr),
accept_timeout);
if (rc != 0)
CERROR("Error sending magic+version in response"
"to LNET magic from %pI4h: %d\n",
&peer_ip, rc);
return -EPROTO;
}
if (magic == le32_to_cpu(LNET_PROTO_TCP_MAGIC))
str = "'old' socknal/tcpnal";
else if (lnet_accept_magic(magic, LNET_PROTO_RA_MAGIC))
str = "'old' ranal";
else
str = "unrecognised";
LCONSOLE_ERROR_MSG(0x11f, "Refusing connection from %pI4h"
" magic %08x: %s acceptor protocol\n",
&peer_ip, magic, str);
return -EPROTO;
}
flip = (magic != LNET_PROTO_ACCEPTOR_MAGIC);
rc = libcfs_sock_read(sock, &cr.acr_version,
sizeof(cr.acr_version),
accept_timeout);
if (rc != 0) {
CERROR("Error %d reading connection request version from "
"%pI4h\n", rc, &peer_ip);
return -EIO;
}
if (flip)
__swab32s(&cr.acr_version);
if (cr.acr_version != LNET_PROTO_ACCEPTOR_VERSION) {
int peer_version = cr.acr_version;
memset (&cr, 0, sizeof(cr));
cr.acr_magic = LNET_PROTO_ACCEPTOR_MAGIC;
cr.acr_version = LNET_PROTO_ACCEPTOR_VERSION;
rc = libcfs_sock_write(sock, &cr, sizeof(cr),
accept_timeout);
if (rc != 0)
CERROR("Error sending magic+version in response"
"to version %d from %pI4h: %d\n",
peer_version, &peer_ip, rc);
return -EPROTO;
}
rc = libcfs_sock_read(sock, &cr.acr_nid,
sizeof(cr) -
offsetof(lnet_acceptor_connreq_t, acr_nid),
accept_timeout);
if (rc != 0) {
CERROR("Error %d reading connection request from "
"%pI4h\n", rc, &peer_ip);
return -EIO;
}
if (flip)
__swab64s(&cr.acr_nid);
ni = lnet_net2ni(LNET_NIDNET(cr.acr_nid));
if (ni == NULL ||
ni->ni_nid != cr.acr_nid) {
if (ni != NULL)
lnet_ni_decref(ni);
LCONSOLE_ERROR_MSG(0x120, "Refusing connection from %pI4h"
" for %s: No matching NI\n",
&peer_ip, libcfs_nid2str(cr.acr_nid));
return -EPERM;
}
if (ni->ni_lnd->lnd_accept == NULL) {
lnet_ni_decref(ni);
LCONSOLE_ERROR_MSG(0x121, "Refusing connection from %pI4h"
" for %s: NI doesn not accept IP connections\n",
&peer_ip, libcfs_nid2str(cr.acr_nid));
return -EPERM;
}
CDEBUG(D_NET, "Accept %s from %pI4h\n",
libcfs_nid2str(cr.acr_nid), &peer_ip);
rc = ni->ni_lnd->lnd_accept(ni, sock);
lnet_ni_decref(ni);
return rc;
}
int
lnet_acceptor(void *arg)
{
socket_t *newsock;
int rc;
__u32 magic;
__u32 peer_ip;
int peer_port;
int secure = (int)((long_ptr_t)arg);
LASSERT (lnet_acceptor_state.pta_sock == NULL);
cfs_block_allsigs();
rc = libcfs_sock_listen(&lnet_acceptor_state.pta_sock,
0, accept_port, accept_backlog);
if (rc != 0) {
if (rc == -EADDRINUSE)
LCONSOLE_ERROR_MSG(0x122, "Can't start acceptor on port"
" %d: port already in use\n",
accept_port);
else
LCONSOLE_ERROR_MSG(0x123, "Can't start acceptor on port "
"%d: unexpected error %d\n",
accept_port, rc);
lnet_acceptor_state.pta_sock = NULL;
} else {
LCONSOLE(0, "Accept %s, port %d\n", accept_type, accept_port);
}
lnet_acceptor_state.pta_shutdown = rc;
complete(&lnet_acceptor_state.pta_signal);
if (rc != 0)
return rc;
while (!lnet_acceptor_state.pta_shutdown) {
rc = libcfs_sock_accept(&newsock, lnet_acceptor_state.pta_sock);
if (rc != 0) {
if (rc != -EAGAIN) {
CWARN("Accept error %d: pausing...\n", rc);
cfs_pause(cfs_time_seconds(1));
}
continue;
}
if (lnet_acceptor_state.pta_shutdown) {
libcfs_sock_release(newsock);
break;
}
rc = libcfs_sock_getaddr(newsock, 1, &peer_ip, &peer_port);
if (rc != 0) {
CERROR("Can't determine new connection's address\n");
goto failed;
}
if (secure && peer_port > LNET_ACCEPTOR_MAX_RESERVED_PORT) {
CERROR("Refusing connection from %pI4h: "
"insecure port %d\n",
&peer_ip, peer_port);
goto failed;
}
rc = libcfs_sock_read(newsock, &magic, sizeof(magic),
accept_timeout);
if (rc != 0) {
CERROR("Error %d reading connection request from "
"%pI4h\n", rc, &peer_ip);
goto failed;
}
rc = lnet_accept(newsock, magic);
if (rc != 0)
goto failed;
continue;
failed:
libcfs_sock_release(newsock);
}
libcfs_sock_release(lnet_acceptor_state.pta_sock);
lnet_acceptor_state.pta_sock = NULL;
CDEBUG(D_NET, "Acceptor stopping\n");
complete(&lnet_acceptor_state.pta_signal);
return 0;
}
static inline int
accept2secure(const char *acc, long *sec)
{
if (!strcmp(acc, "secure")) {
*sec = 1;
return 1;
} else if (!strcmp(acc, "all")) {
*sec = 0;
return 1;
} else if (!strcmp(acc, "none")) {
return 0;
} else {
LCONSOLE_ERROR_MSG(0x124, "Can't parse 'accept=\"%s\"'\n",
acc);
return -EINVAL;
}
}
int
lnet_acceptor_start(void)
{
int rc;
long rc2;
long secure;
LASSERT (lnet_acceptor_state.pta_sock == NULL);
rc = lnet_acceptor_get_tunables();
if (rc != 0)
return rc;
init_completion(&lnet_acceptor_state.pta_signal);
rc = accept2secure(accept_type, &secure);
if (rc <= 0) {
fini_completion(&lnet_acceptor_state.pta_signal);
return rc;
}
if (lnet_count_acceptor_nis() == 0)
return 0;
rc2 = PTR_ERR(kthread_run(lnet_acceptor,
(void *)(ulong_ptr_t)secure,
"acceptor_%03ld", secure));
if (IS_ERR_VALUE(rc2)) {
CERROR("Can't start acceptor thread: %ld\n", rc2);
fini_completion(&lnet_acceptor_state.pta_signal);
return -ESRCH;
}
wait_for_completion(&lnet_acceptor_state.pta_signal);
if (!lnet_acceptor_state.pta_shutdown) {
LASSERT(lnet_acceptor_state.pta_sock != NULL);
return 0;
}
LASSERT(lnet_acceptor_state.pta_sock == NULL);
fini_completion(&lnet_acceptor_state.pta_signal);
return -ENETDOWN;
}
void
lnet_acceptor_stop(void)
{
if (lnet_acceptor_state.pta_sock == NULL)
return;
lnet_acceptor_state.pta_shutdown = 1;
libcfs_sock_abort_accept(lnet_acceptor_state.pta_sock);
wait_for_completion(&lnet_acceptor_state.pta_signal);
fini_completion(&lnet_acceptor_state.pta_signal);
}
