static int
libcfs_sock_ioctl(int cmd, unsigned long arg)
{
mm_segment_t oldmm = get_fs();
struct socket *sock;
int rc;
struct file *sock_filp;
rc = sock_create (PF_INET, SOCK_STREAM, 0, &sock);
if (rc != 0) {
CERROR ("Can't create socket: %d\n", rc);
return rc;
}
sock_filp = sock_alloc_file(sock, 0, NULL);
if (IS_ERR(sock_filp)) {
sock_release(sock);
rc = PTR_ERR(sock_filp);
goto out;
}
set_fs(KERNEL_DS);
if (sock_filp->f_op->unlocked_ioctl)
rc = sock_filp->f_op->unlocked_ioctl(sock_filp, cmd, arg);
set_fs(oldmm);
fput(sock_filp);
out:
return rc;
}
int
libcfs_ipif_query (char *name, int *up, __u32 *ip, __u32 *mask)
{
struct ifreq ifr;
int nob;
int rc;
__u32 val;
nob = strnlen(name, IFNAMSIZ);
if (nob == IFNAMSIZ) {
CERROR("Interface name %s too long\n", name);
return -EINVAL;
}
CLASSERT (sizeof(ifr.ifr_name) >= IFNAMSIZ);
strcpy(ifr.ifr_name, name);
rc = libcfs_sock_ioctl(SIOCGIFFLAGS, (unsigned long)&ifr);
if (rc != 0) {
CERROR("Can't get flags for interface %s\n", name);
return rc;
}
if ((ifr.ifr_flags & IFF_UP) == 0) {
CDEBUG(D_NET, "Interface %s down\n", name);
*up = 0;
*ip = *mask = 0;
return 0;
}
*up = 1;
strcpy(ifr.ifr_name, name);
ifr.ifr_addr.sa_family = AF_INET;
rc = libcfs_sock_ioctl(SIOCGIFADDR, (unsigned long)&ifr);
if (rc != 0) {
CERROR("Can't get IP address for interface %s\n", name);
return rc;
}
val = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;
*ip = ntohl(val);
strcpy(ifr.ifr_name, name);
ifr.ifr_addr.sa_family = AF_INET;
rc = libcfs_sock_ioctl(SIOCGIFNETMASK, (unsigned long)&ifr);
if (rc != 0) {
CERROR("Can't get netmask for interface %s\n", name);
return rc;
}
val = ((struct sockaddr_in *)&ifr.ifr_netmask)->sin_addr.s_addr;
*mask = ntohl(val);
return 0;
}
int
libcfs_ipif_enumerate (char ***namesp)
{
char **names;
int toobig;
int nalloc;
int nfound;
struct ifreq *ifr;
struct ifconf ifc;
int rc;
int nob;
int i;
nalloc = 16;
toobig = 0;
for (;;) {
if (nalloc * sizeof(*ifr) > PAGE_CACHE_SIZE) {
toobig = 1;
nalloc = PAGE_CACHE_SIZE/sizeof(*ifr);
CWARN("Too many interfaces: only enumerating first %d\n",
nalloc);
}
LIBCFS_ALLOC(ifr, nalloc * sizeof(*ifr));
if (ifr == NULL) {
CERROR ("ENOMEM enumerating up to %d interfaces\n", nalloc);
rc = -ENOMEM;
goto out0;
}
ifc.ifc_buf = (char *)ifr;
ifc.ifc_len = nalloc * sizeof(*ifr);
rc = libcfs_sock_ioctl(SIOCGIFCONF, (unsigned long)&ifc);
if (rc < 0) {
CERROR ("Error %d enumerating interfaces\n", rc);
goto out1;
}
LASSERT (rc == 0);
nfound = ifc.ifc_len/sizeof(*ifr);
LASSERT (nfound <= nalloc);
if (nfound < nalloc || toobig)
break;
LIBCFS_FREE(ifr, nalloc * sizeof(*ifr));
nalloc *= 2;
}
if (nfound == 0)
goto out1;
LIBCFS_ALLOC(names, nfound * sizeof(*names));
if (names == NULL) {
rc = -ENOMEM;
goto out1;
}
for (i = 0; i < nfound; i++) {
nob = strnlen (ifr[i].ifr_name, IFNAMSIZ);
if (nob == IFNAMSIZ) {
CERROR("interface name %.*s too long (%d max)\n",
nob, ifr[i].ifr_name, IFNAMSIZ);
rc = -ENAMETOOLONG;
goto out2;
}
LIBCFS_ALLOC(names[i], IFNAMSIZ);
if (names[i] == NULL) {
rc = -ENOMEM;
goto out2;
}
memcpy(names[i], ifr[i].ifr_name, nob);
names[i][nob] = 0;
}
*namesp = names;
rc = nfound;
out2:
if (rc < 0)
libcfs_ipif_free_enumeration(names, nfound);
out1:
LIBCFS_FREE(ifr, nalloc * sizeof(*ifr));
out0:
return rc;
}
void
libcfs_ipif_free_enumeration (char **names, int n)
{
int i;
LASSERT (n > 0);
for (i = 0; i < n && names[i] != NULL; i++)
LIBCFS_FREE(names[i], IFNAMSIZ);
LIBCFS_FREE(names, n * sizeof(*names));
}
int
libcfs_sock_write (struct socket *sock, void *buffer, int nob, int timeout)
{
int rc;
long ticks = timeout * HZ;
unsigned long then;
struct timeval tv;
LASSERT (nob > 0);
for (;;) {
struct kvec iov = {
.iov_base = buffer,
.iov_len = nob
};
struct msghdr msg = {
.msg_flags = (timeout == 0) ? MSG_DONTWAIT : 0
};
if (timeout != 0) {
tv = (struct timeval) {
.tv_sec = ticks / HZ,
.tv_usec = ((ticks % HZ) * 1000000) / HZ
};
rc = kernel_setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO,
(char *)&tv, sizeof(tv));
if (rc != 0) {
CERROR("Can't set socket send timeout %ld.%06d: %d\n",
(long)tv.tv_sec, (int)tv.tv_usec, rc);
return rc;
}
}
then = jiffies;
rc = kernel_sendmsg(sock, &msg, &iov, 1, nob);
ticks -= jiffies - then;
if (rc == nob)
return 0;
if (rc < 0)
return rc;
if (rc == 0) {
CERROR ("Unexpected zero rc\n");
return -ECONNABORTED;
}
if (ticks <= 0)
return -EAGAIN;
buffer = ((char *)buffer) + rc;
nob -= rc;
}
return 0;
}
int
libcfs_sock_read (struct socket *sock, void *buffer, int nob, int timeout)
{
int rc;
long ticks = timeout * HZ;
unsigned long then;
struct timeval tv;
LASSERT (nob > 0);
LASSERT (ticks > 0);
for (;;) {
struct kvec iov = {
.iov_base = buffer,
.iov_len = nob
};
struct msghdr msg = {
.msg_flags = 0
};
tv = (struct timeval) {
.tv_sec = ticks / HZ,
.tv_usec = ((ticks % HZ) * 1000000) / HZ
};
rc = kernel_setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO,
(char *)&tv, sizeof(tv));
if (rc != 0) {
CERROR("Can't set socket recv timeout %ld.%06d: %d\n",
(long)tv.tv_sec, (int)tv.tv_usec, rc);
return rc;
}
then = jiffies;
rc = kernel_recvmsg(sock, &msg, &iov, 1, nob, 0);
ticks -= jiffies - then;
if (rc < 0)
return rc;
if (rc == 0)
return -ECONNRESET;
buffer = ((char *)buffer) + rc;
nob -= rc;
if (nob == 0)
return 0;
if (ticks <= 0)
return -ETIMEDOUT;
}
}
static int
libcfs_sock_create (struct socket **sockp, int *fatal,
__u32 local_ip, int local_port)
{
struct sockaddr_in locaddr;
struct socket *sock;
int rc;
int option;
*fatal = 1;
rc = sock_create (PF_INET, SOCK_STREAM, 0, &sock);
*sockp = sock;
if (rc != 0) {
CERROR ("Can't create socket: %d\n", rc);
return rc;
}
option = 1;
rc = kernel_setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,
(char *)&option, sizeof (option));
if (rc != 0) {
CERROR("Can't set SO_REUSEADDR for socket: %d\n", rc);
goto failed;
}
if (local_ip != 0 || local_port != 0) {
memset(&locaddr, 0, sizeof(locaddr));
locaddr.sin_family = AF_INET;
locaddr.sin_port = htons(local_port);
locaddr.sin_addr.s_addr = (local_ip == 0) ?
INADDR_ANY : htonl(local_ip);
rc = sock->ops->bind(sock, (struct sockaddr *)&locaddr,
sizeof(locaddr));
if (rc == -EADDRINUSE) {
CDEBUG(D_NET, "Port %d already in use\n", local_port);
*fatal = 0;
goto failed;
}
if (rc != 0) {
CERROR("Error trying to bind to port %d: %d\n",
local_port, rc);
goto failed;
}
}
return 0;
failed:
sock_release(sock);
return rc;
}
int
libcfs_sock_setbuf (struct socket *sock, int txbufsize, int rxbufsize)
{
int option;
int rc;
if (txbufsize != 0) {
option = txbufsize;
rc = kernel_setsockopt(sock, SOL_SOCKET, SO_SNDBUF,
(char *)&option, sizeof (option));
if (rc != 0) {
CERROR ("Can't set send buffer %d: %d\n",
option, rc);
return rc;
}
}
if (rxbufsize != 0) {
option = rxbufsize;
rc = kernel_setsockopt(sock, SOL_SOCKET, SO_RCVBUF,
(char *)&option, sizeof (option));
if (rc != 0) {
CERROR ("Can't set receive buffer %d: %d\n",
option, rc);
return rc;
}
}
return 0;
}
int
libcfs_sock_getaddr (struct socket *sock, int remote, __u32 *ip, int *port)
{
struct sockaddr_in sin;
int len = sizeof (sin);
int rc;
rc = sock->ops->getname (sock, (struct sockaddr *)&sin, &len,
remote ? 2 : 0);
if (rc != 0) {
CERROR ("Error %d getting sock %s IP/port\n",
rc, remote ? "peer" : "local");
return rc;
}
if (ip != NULL)
*ip = ntohl (sin.sin_addr.s_addr);
if (port != NULL)
*port = ntohs (sin.sin_port);
return 0;
}
int
libcfs_sock_getbuf (struct socket *sock, int *txbufsize, int *rxbufsize)
{
if (txbufsize != NULL) {
*txbufsize = sock->sk->sk_sndbuf;
}
if (rxbufsize != NULL) {
*rxbufsize = sock->sk->sk_rcvbuf;
}
return 0;
}
int
libcfs_sock_listen (struct socket **sockp,
__u32 local_ip, int local_port, int backlog)
{
int fatal;
int rc;
rc = libcfs_sock_create(sockp, &fatal, local_ip, local_port);
if (rc != 0) {
if (!fatal)
CERROR("Can't create socket: port %d already in use\n",
local_port);
return rc;
}
rc = (*sockp)->ops->listen(*sockp, backlog);
if (rc == 0)
return 0;
CERROR("Can't set listen backlog %d: %d\n", backlog, rc);
sock_release(*sockp);
return rc;
}
int
libcfs_sock_accept (struct socket **newsockp, struct socket *sock)
{
wait_queue_t wait;
struct socket *newsock;
int rc;
init_waitqueue_entry(&wait, current);
rc = sock_create_lite(PF_PACKET, sock->type, IPPROTO_TCP, &newsock);
if (rc) {
CERROR("Can't allocate socket\n");
return rc;
}
newsock->ops = sock->ops;
set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue(sk_sleep(sock->sk), &wait);
rc = sock->ops->accept(sock, newsock, O_NONBLOCK);
if (rc == -EAGAIN) {
schedule();
rc = sock->ops->accept(sock, newsock, O_NONBLOCK);
}
remove_wait_queue(sk_sleep(sock->sk), &wait);
set_current_state(TASK_RUNNING);
if (rc != 0)
goto failed;
*newsockp = newsock;
return 0;
failed:
sock_release(newsock);
return rc;
}
void
libcfs_sock_abort_accept (struct socket *sock)
{
wake_up_all(sk_sleep(sock->sk));
}
int
libcfs_sock_connect (struct socket **sockp, int *fatal,
__u32 local_ip, int local_port,
__u32 peer_ip, int peer_port)
{
struct sockaddr_in srvaddr;
int rc;
rc = libcfs_sock_create(sockp, fatal, local_ip, local_port);
if (rc != 0)
return rc;
memset (&srvaddr, 0, sizeof (srvaddr));
srvaddr.sin_family = AF_INET;
srvaddr.sin_port = htons(peer_port);
srvaddr.sin_addr.s_addr = htonl(peer_ip);
rc = (*sockp)->ops->connect(*sockp,
(struct sockaddr *)&srvaddr, sizeof(srvaddr),
0);
if (rc == 0)
return 0;
*fatal = !(rc == -EADDRNOTAVAIL);
CDEBUG_LIMIT(*fatal ? D_NETERROR : D_NET,
"Error %d connecting %pI4h/%d -> %pI4h/%d\n", rc,
&local_ip, local_port, &peer_ip, peer_port);
sock_release(*sockp);
return rc;
}
void
libcfs_sock_release (struct socket *sock)
{
sock_release(sock);
}
