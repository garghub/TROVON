BIO_METHOD *BIO_s_datagram(void)
{
return (&methods_dgramp);
}
BIO *BIO_new_dgram(int fd, int close_flag)
{
BIO *ret;
ret = BIO_new(BIO_s_datagram());
if (ret == NULL)
return (NULL);
BIO_set_fd(ret, fd, close_flag);
return (ret);
}
static int dgram_new(BIO *bi)
{
bio_dgram_data *data = NULL;
bi->init = 0;
bi->num = 0;
data = OPENSSL_malloc(sizeof(bio_dgram_data));
if (data == NULL)
return 0;
memset(data, 0x00, sizeof(bio_dgram_data));
bi->ptr = data;
bi->flags = 0;
return (1);
}
static int dgram_free(BIO *a)
{
bio_dgram_data *data;
if (a == NULL)
return (0);
if (!dgram_clear(a))
return 0;
data = (bio_dgram_data *)a->ptr;
if (data != NULL)
OPENSSL_free(data);
return (1);
}
static int dgram_clear(BIO *a)
{
if (a == NULL)
return (0);
if (a->shutdown) {
if (a->init) {
SHUTDOWN2(a->num);
}
a->init = 0;
a->flags = 0;
}
return (1);
}
static void dgram_adjust_rcv_timeout(BIO *b)
{
# if defined(SO_RCVTIMEO)
bio_dgram_data *data = (bio_dgram_data *)b->ptr;
union {
size_t s;
int i;
} sz = {
0
};
if (data->next_timeout.tv_sec > 0 || data->next_timeout.tv_usec > 0) {
struct timeval timenow, timeleft;
# ifdef OPENSSL_SYS_WINDOWS
int timeout;
sz.i = sizeof(timeout);
if (getsockopt(b->num, SOL_SOCKET, SO_RCVTIMEO,
(void *)&timeout, &sz.i) < 0) {
perror("getsockopt");
} else {
data->socket_timeout.tv_sec = timeout / 1000;
data->socket_timeout.tv_usec = (timeout % 1000) * 1000;
}
# else
sz.i = sizeof(data->socket_timeout);
if (getsockopt(b->num, SOL_SOCKET, SO_RCVTIMEO,
&(data->socket_timeout), (void *)&sz) < 0) {
perror("getsockopt");
} else if (sizeof(sz.s) != sizeof(sz.i) && sz.i == 0)
OPENSSL_assert(sz.s <= sizeof(data->socket_timeout));
# endif
get_current_time(&timenow);
memcpy(&timeleft, &(data->next_timeout), sizeof(struct timeval));
timeleft.tv_sec -= timenow.tv_sec;
timeleft.tv_usec -= timenow.tv_usec;
if (timeleft.tv_usec < 0) {
timeleft.tv_sec--;
timeleft.tv_usec += 1000000;
}
if (timeleft.tv_sec < 0) {
timeleft.tv_sec = 0;
timeleft.tv_usec = 1;
}
if ((data->socket_timeout.tv_sec == 0
&& data->socket_timeout.tv_usec == 0)
|| (data->socket_timeout.tv_sec > timeleft.tv_sec)
|| (data->socket_timeout.tv_sec == timeleft.tv_sec
&& data->socket_timeout.tv_usec >= timeleft.tv_usec)) {
# ifdef OPENSSL_SYS_WINDOWS
timeout = timeleft.tv_sec * 1000 + timeleft.tv_usec / 1000;
if (setsockopt(b->num, SOL_SOCKET, SO_RCVTIMEO,
(void *)&timeout, sizeof(timeout)) < 0) {
perror("setsockopt");
}
# else
if (setsockopt(b->num, SOL_SOCKET, SO_RCVTIMEO, &timeleft,
sizeof(struct timeval)) < 0) {
perror("setsockopt");
}
# endif
}
}
# endif
}
static void dgram_reset_rcv_timeout(BIO *b)
{
# if defined(SO_RCVTIMEO)
bio_dgram_data *data = (bio_dgram_data *)b->ptr;
if (data->next_timeout.tv_sec > 0 || data->next_timeout.tv_usec > 0) {
# ifdef OPENSSL_SYS_WINDOWS
int timeout = data->socket_timeout.tv_sec * 1000 +
data->socket_timeout.tv_usec / 1000;
if (setsockopt(b->num, SOL_SOCKET, SO_RCVTIMEO,
(void *)&timeout, sizeof(timeout)) < 0) {
perror("setsockopt");
}
# else
if (setsockopt
(b->num, SOL_SOCKET, SO_RCVTIMEO, &(data->socket_timeout),
sizeof(struct timeval)) < 0) {
perror("setsockopt");
}
# endif
}
# endif
}
static int dgram_read(BIO *b, char *out, int outl)
{
int ret = 0;
bio_dgram_data *data = (bio_dgram_data *)b->ptr;
struct {
union {
size_t s;
int i;
} len;
union {
struct sockaddr sa;
struct sockaddr_in sa_in;
# if OPENSSL_USE_IPV6
struct sockaddr_in6 sa_in6;
# endif
} peer;
} sa;
sa.len.s = 0;
sa.len.i = sizeof(sa.peer);
if (out != NULL) {
clear_socket_error();
memset(&sa.peer, 0x00, sizeof(sa.peer));
dgram_adjust_rcv_timeout(b);
ret = recvfrom(b->num, out, outl, 0, &sa.peer.sa, (void *)&sa.len);
if (sizeof(sa.len.i) != sizeof(sa.len.s) && sa.len.i == 0) {
OPENSSL_assert(sa.len.s <= sizeof(sa.peer));
sa.len.i = (int)sa.len.s;
}
if (!data->connected && ret >= 0)
BIO_ctrl(b, BIO_CTRL_DGRAM_SET_PEER, 0, &sa.peer);
BIO_clear_retry_flags(b);
if (ret < 0) {
if (BIO_dgram_should_retry(ret)) {
BIO_set_retry_read(b);
data->_errno = get_last_socket_error();
}
}
dgram_reset_rcv_timeout(b);
}
return (ret);
}
static int dgram_write(BIO *b, const char *in, int inl)
{
int ret;
bio_dgram_data *data = (bio_dgram_data *)b->ptr;
clear_socket_error();
if (data->connected)
ret = writesocket(b->num, in, inl);
else {
int peerlen = sizeof(data->peer);
if (data->peer.sa.sa_family == AF_INET)
peerlen = sizeof(data->peer.sa_in);
# if OPENSSL_USE_IPV6
else if (data->peer.sa.sa_family == AF_INET6)
peerlen = sizeof(data->peer.sa_in6);
# endif
# if defined(NETWARE_CLIB) && defined(NETWARE_BSDSOCK)
ret = sendto(b->num, (char *)in, inl, 0, &data->peer.sa, peerlen);
# else
ret = sendto(b->num, in, inl, 0, &data->peer.sa, peerlen);
# endif
}
BIO_clear_retry_flags(b);
if (ret <= 0) {
if (BIO_dgram_should_retry(ret)) {
BIO_set_retry_write(b);
data->_errno = get_last_socket_error();
# if 0
if (data->_errno == EMSGSIZE)
BIO_ctrl(b, BIO_CTRL_DGRAM_QUERY_MTU, 0, NULL);
# endif
}
}
return (ret);
}
static long dgram_get_mtu_overhead(bio_dgram_data *data)
{
long ret;
switch (data->peer.sa.sa_family) {
case AF_INET:
ret = 28;
break;
# if OPENSSL_USE_IPV6
case AF_INET6:
# ifdef IN6_IS_ADDR_V4MAPPED
if (IN6_IS_ADDR_V4MAPPED(&data->peer.sa_in6.sin6_addr))
ret = 28;
else
# endif
ret = 48;
break;
# endif
default:
ret = 28;
break;
}
return ret;
}
static long dgram_ctrl(BIO *b, int cmd, long num, void *ptr)
{
long ret = 1;
int *ip;
struct sockaddr *to = NULL;
bio_dgram_data *data = NULL;
int sockopt_val = 0;
# if defined(OPENSSL_SYS_LINUX) && (defined(IP_MTU_DISCOVER) || defined(IP_MTU))
socklen_t sockopt_len;
socklen_t addr_len;
union {
struct sockaddr sa;
struct sockaddr_in s4;
# if OPENSSL_USE_IPV6
struct sockaddr_in6 s6;
# endif
} addr;
# endif
data = (bio_dgram_data *)b->ptr;
switch (cmd) {
case BIO_CTRL_RESET:
num = 0;
case BIO_C_FILE_SEEK:
ret = 0;
break;
case BIO_C_FILE_TELL:
case BIO_CTRL_INFO:
ret = 0;
break;
case BIO_C_SET_FD:
dgram_clear(b);
b->num = *((int *)ptr);
b->shutdown = (int)num;
b->init = 1;
break;
case BIO_C_GET_FD:
if (b->init) {
ip = (int *)ptr;
if (ip != NULL)
*ip = b->num;
ret = b->num;
} else
ret = -1;
break;
case BIO_CTRL_GET_CLOSE:
ret = b->shutdown;
break;
case BIO_CTRL_SET_CLOSE:
b->shutdown = (int)num;
break;
case BIO_CTRL_PENDING:
case BIO_CTRL_WPENDING:
ret = 0;
break;
case BIO_CTRL_DUP:
case BIO_CTRL_FLUSH:
ret = 1;
break;
case BIO_CTRL_DGRAM_CONNECT:
to = (struct sockaddr *)ptr;
# if 0
if (connect(b->num, to, sizeof(struct sockaddr)) < 0) {
perror("connect");
ret = 0;
} else {
# endif
switch (to->sa_family) {
case AF_INET:
memcpy(&data->peer, to, sizeof(data->peer.sa_in));
break;
# if OPENSSL_USE_IPV6
case AF_INET6:
memcpy(&data->peer, to, sizeof(data->peer.sa_in6));
break;
# endif
default:
memcpy(&data->peer, to, sizeof(data->peer.sa));
break;
}
# if 0
}
# endif
break;
case BIO_CTRL_DGRAM_MTU_DISCOVER:
# if defined(OPENSSL_SYS_LINUX) && defined(IP_MTU_DISCOVER) && defined(IP_PMTUDISC_DO)
addr_len = (socklen_t) sizeof(addr);
memset((void *)&addr, 0, sizeof(addr));
if (getsockname(b->num, &addr.sa, &addr_len) < 0) {
ret = 0;
break;
}
switch (addr.sa.sa_family) {
case AF_INET:
sockopt_val = IP_PMTUDISC_DO;
if ((ret = setsockopt(b->num, IPPROTO_IP, IP_MTU_DISCOVER,
&sockopt_val, sizeof(sockopt_val))) < 0)
perror("setsockopt");
break;
# if OPENSSL_USE_IPV6 && defined(IPV6_MTU_DISCOVER) && defined(IPV6_PMTUDISC_DO)
case AF_INET6:
sockopt_val = IPV6_PMTUDISC_DO;
if ((ret = setsockopt(b->num, IPPROTO_IPV6, IPV6_MTU_DISCOVER,
&sockopt_val, sizeof(sockopt_val))) < 0)
perror("setsockopt");
break;
# endif
default:
ret = -1;
break;
}
ret = -1;
# else
break;
# endif
case BIO_CTRL_DGRAM_QUERY_MTU:
# if defined(OPENSSL_SYS_LINUX) && defined(IP_MTU)
addr_len = (socklen_t) sizeof(addr);
memset((void *)&addr, 0, sizeof(addr));
if (getsockname(b->num, &addr.sa, &addr_len) < 0) {
ret = 0;
break;
}
sockopt_len = sizeof(sockopt_val);
switch (addr.sa.sa_family) {
case AF_INET:
if ((ret =
getsockopt(b->num, IPPROTO_IP, IP_MTU, (void *)&sockopt_val,
&sockopt_len)) < 0 || sockopt_val < 0) {
ret = 0;
} else {
data->mtu = sockopt_val - 8 - 20;
ret = data->mtu;
}
break;
# if OPENSSL_USE_IPV6 && defined(IPV6_MTU)
case AF_INET6:
if ((ret =
getsockopt(b->num, IPPROTO_IPV6, IPV6_MTU,
(void *)&sockopt_val, &sockopt_len)) < 0
|| sockopt_val < 0) {
ret = 0;
} else {
data->mtu = sockopt_val - 8 - 40;
ret = data->mtu;
}
break;
# endif
default:
ret = 0;
break;
}
# else
ret = 0;
# endif
break;
case BIO_CTRL_DGRAM_GET_FALLBACK_MTU:
ret = -dgram_get_mtu_overhead(data);
switch (data->peer.sa.sa_family) {
case AF_INET:
ret += 576;
break;
# if OPENSSL_USE_IPV6
case AF_INET6:
# ifdef IN6_IS_ADDR_V4MAPPED
if (IN6_IS_ADDR_V4MAPPED(&data->peer.sa_in6.sin6_addr))
ret += 576;
else
# endif
ret += 1280;
break;
# endif
default:
ret += 576;
break;
}
break;
case BIO_CTRL_DGRAM_GET_MTU:
return data->mtu;
break;
case BIO_CTRL_DGRAM_SET_MTU:
data->mtu = num;
ret = num;
break;
case BIO_CTRL_DGRAM_SET_CONNECTED:
to = (struct sockaddr *)ptr;
if (to != NULL) {
data->connected = 1;
switch (to->sa_family) {
case AF_INET:
memcpy(&data->peer, to, sizeof(data->peer.sa_in));
break;
# if OPENSSL_USE_IPV6
case AF_INET6:
memcpy(&data->peer, to, sizeof(data->peer.sa_in6));
break;
# endif
default:
memcpy(&data->peer, to, sizeof(data->peer.sa));
break;
}
} else {
data->connected = 0;
memset(&(data->peer), 0x00, sizeof(data->peer));
}
break;
case BIO_CTRL_DGRAM_GET_PEER:
switch (data->peer.sa.sa_family) {
case AF_INET:
ret = sizeof(data->peer.sa_in);
break;
# if OPENSSL_USE_IPV6
case AF_INET6:
ret = sizeof(data->peer.sa_in6);
break;
# endif
default:
ret = sizeof(data->peer.sa);
break;
}
if (num == 0 || num > ret)
num = ret;
memcpy(ptr, &data->peer, (ret = num));
break;
case BIO_CTRL_DGRAM_SET_PEER:
to = (struct sockaddr *)ptr;
switch (to->sa_family) {
case AF_INET:
memcpy(&data->peer, to, sizeof(data->peer.sa_in));
break;
# if OPENSSL_USE_IPV6
case AF_INET6:
memcpy(&data->peer, to, sizeof(data->peer.sa_in6));
break;
# endif
default:
memcpy(&data->peer, to, sizeof(data->peer.sa));
break;
}
break;
case BIO_CTRL_DGRAM_SET_NEXT_TIMEOUT:
memcpy(&(data->next_timeout), ptr, sizeof(struct timeval));
break;
# if defined(SO_RCVTIMEO)
case BIO_CTRL_DGRAM_SET_RECV_TIMEOUT:
# ifdef OPENSSL_SYS_WINDOWS
{
struct timeval *tv = (struct timeval *)ptr;
int timeout = tv->tv_sec * 1000 + tv->tv_usec / 1000;
if (setsockopt(b->num, SOL_SOCKET, SO_RCVTIMEO,
(void *)&timeout, sizeof(timeout)) < 0) {
perror("setsockopt");
ret = -1;
}
}
# else
if (setsockopt(b->num, SOL_SOCKET, SO_RCVTIMEO, ptr,
sizeof(struct timeval)) < 0) {
perror("setsockopt");
ret = -1;
}
# endif
break;
case BIO_CTRL_DGRAM_GET_RECV_TIMEOUT:
{
union {
size_t s;
int i;
} sz = {
0
};
# ifdef OPENSSL_SYS_WINDOWS
int timeout;
struct timeval *tv = (struct timeval *)ptr;
sz.i = sizeof(timeout);
if (getsockopt(b->num, SOL_SOCKET, SO_RCVTIMEO,
(void *)&timeout, &sz.i) < 0) {
perror("getsockopt");
ret = -1;
} else {
tv->tv_sec = timeout / 1000;
tv->tv_usec = (timeout % 1000) * 1000;
ret = sizeof(*tv);
}
# else
sz.i = sizeof(struct timeval);
if (getsockopt(b->num, SOL_SOCKET, SO_RCVTIMEO,
ptr, (void *)&sz) < 0) {
perror("getsockopt");
ret = -1;
} else if (sizeof(sz.s) != sizeof(sz.i) && sz.i == 0) {
OPENSSL_assert(sz.s <= sizeof(struct timeval));
ret = (int)sz.s;
} else
ret = sz.i;
# endif
}
break;
# endif
# if defined(SO_SNDTIMEO)
case BIO_CTRL_DGRAM_SET_SEND_TIMEOUT:
# ifdef OPENSSL_SYS_WINDOWS
{
struct timeval *tv = (struct timeval *)ptr;
int timeout = tv->tv_sec * 1000 + tv->tv_usec / 1000;
if (setsockopt(b->num, SOL_SOCKET, SO_SNDTIMEO,
(void *)&timeout, sizeof(timeout)) < 0) {
perror("setsockopt");
ret = -1;
}
}
# else
if (setsockopt(b->num, SOL_SOCKET, SO_SNDTIMEO, ptr,
sizeof(struct timeval)) < 0) {
perror("setsockopt");
ret = -1;
}
# endif
break;
case BIO_CTRL_DGRAM_GET_SEND_TIMEOUT:
{
union {
size_t s;
int i;
} sz = {
0
};
# ifdef OPENSSL_SYS_WINDOWS
int timeout;
struct timeval *tv = (struct timeval *)ptr;
sz.i = sizeof(timeout);
if (getsockopt(b->num, SOL_SOCKET, SO_SNDTIMEO,
(void *)&timeout, &sz.i) < 0) {
perror("getsockopt");
ret = -1;
} else {
tv->tv_sec = timeout / 1000;
tv->tv_usec = (timeout % 1000) * 1000;
ret = sizeof(*tv);
}
# else
sz.i = sizeof(struct timeval);
if (getsockopt(b->num, SOL_SOCKET, SO_SNDTIMEO,
ptr, (void *)&sz) < 0) {
perror("getsockopt");
ret = -1;
} else if (sizeof(sz.s) != sizeof(sz.i) && sz.i == 0) {
OPENSSL_assert(sz.s <= sizeof(struct timeval));
ret = (int)sz.s;
} else
ret = sz.i;
# endif
}
break;
# endif
case BIO_CTRL_DGRAM_GET_SEND_TIMER_EXP:
case BIO_CTRL_DGRAM_GET_RECV_TIMER_EXP:
# ifdef OPENSSL_SYS_WINDOWS
if (data->_errno == WSAETIMEDOUT)
# else
if (data->_errno == EAGAIN)
# endif
{
ret = 1;
data->_errno = 0;
} else
ret = 0;
break;
# ifdef EMSGSIZE
case BIO_CTRL_DGRAM_MTU_EXCEEDED:
if (data->_errno == EMSGSIZE) {
ret = 1;
data->_errno = 0;
} else
ret = 0;
break;
# endif
case BIO_CTRL_DGRAM_SET_DONT_FRAG:
sockopt_val = num ? 1 : 0;
switch (data->peer.sa.sa_family) {
case AF_INET:
# if defined(IP_DONTFRAG)
if ((ret = setsockopt(b->num, IPPROTO_IP, IP_DONTFRAG,
&sockopt_val, sizeof(sockopt_val))) < 0) {
perror("setsockopt");
ret = -1;
}
# elif defined(OPENSSL_SYS_LINUX) && defined(IP_MTUDISCOVER)
if ((sockopt_val = num ? IP_PMTUDISC_PROBE : IP_PMTUDISC_DONT),
(ret = setsockopt(b->num, IPPROTO_IP, IP_MTU_DISCOVER,
&sockopt_val, sizeof(sockopt_val))) < 0) {
perror("setsockopt");
ret = -1;
}
# elif defined(OPENSSL_SYS_WINDOWS) && defined(IP_DONTFRAGMENT)
if ((ret = setsockopt(b->num, IPPROTO_IP, IP_DONTFRAGMENT,
(const char *)&sockopt_val,
sizeof(sockopt_val))) < 0) {
perror("setsockopt");
ret = -1;
}
# else
ret = -1;
# endif
break;
# if OPENSSL_USE_IPV6
case AF_INET6:
# if defined(IPV6_DONTFRAG)
if ((ret = setsockopt(b->num, IPPROTO_IPV6, IPV6_DONTFRAG,
(const void *)&sockopt_val,
sizeof(sockopt_val))) < 0) {
perror("setsockopt");
ret = -1;
}
# elif defined(OPENSSL_SYS_LINUX) && defined(IPV6_MTUDISCOVER)
if ((sockopt_val = num ? IP_PMTUDISC_PROBE : IP_PMTUDISC_DONT),
(ret = setsockopt(b->num, IPPROTO_IPV6, IPV6_MTU_DISCOVER,
&sockopt_val, sizeof(sockopt_val))) < 0) {
perror("setsockopt");
ret = -1;
}
# else
ret = -1;
# endif
break;
# endif
default:
ret = -1;
break;
}
break;
case BIO_CTRL_DGRAM_GET_MTU_OVERHEAD:
ret = dgram_get_mtu_overhead(data);
break;
default:
ret = 0;
break;
}
return (ret);
}
static int dgram_puts(BIO *bp, const char *str)
{
int n, ret;
n = strlen(str);
ret = dgram_write(bp, str, n);
return (ret);
}
BIO_METHOD *BIO_s_datagram_sctp(void)
{
return (&methods_dgramp_sctp);
}
BIO *BIO_new_dgram_sctp(int fd, int close_flag)
{
BIO *bio;
int ret, optval = 20000;
int auth_data = 0, auth_forward = 0;
unsigned char *p;
struct sctp_authchunk auth;
struct sctp_authchunks *authchunks;
socklen_t sockopt_len;
# ifdef SCTP_AUTHENTICATION_EVENT
# ifdef SCTP_EVENT
struct sctp_event event;
# else
struct sctp_event_subscribe event;
# endif
# endif
bio = BIO_new(BIO_s_datagram_sctp());
if (bio == NULL)
return (NULL);
BIO_set_fd(bio, fd, close_flag);
auth.sauth_chunk = OPENSSL_SCTP_DATA_CHUNK_TYPE;
ret =
setsockopt(fd, IPPROTO_SCTP, SCTP_AUTH_CHUNK, &auth,
sizeof(struct sctp_authchunk));
if (ret < 0) {
BIO_vfree(bio);
return (NULL);
}
auth.sauth_chunk = OPENSSL_SCTP_FORWARD_CUM_TSN_CHUNK_TYPE;
ret =
setsockopt(fd, IPPROTO_SCTP, SCTP_AUTH_CHUNK, &auth,
sizeof(struct sctp_authchunk));
if (ret < 0) {
BIO_vfree(bio);
return (NULL);
}
sockopt_len = (socklen_t) (sizeof(sctp_assoc_t) + 256 * sizeof(uint8_t));
authchunks = OPENSSL_malloc(sockopt_len);
memset(authchunks, 0, sizeof(sockopt_len));
ret =
getsockopt(fd, IPPROTO_SCTP, SCTP_LOCAL_AUTH_CHUNKS, authchunks,
&sockopt_len);
if (ret < 0) {
OPENSSL_free(authchunks);
BIO_vfree(bio);
return (NULL);
}
for (p = (unsigned char *)authchunks->gauth_chunks;
p < (unsigned char *)authchunks + sockopt_len;
p += sizeof(uint8_t)) {
if (*p == OPENSSL_SCTP_DATA_CHUNK_TYPE)
auth_data = 1;
if (*p == OPENSSL_SCTP_FORWARD_CUM_TSN_CHUNK_TYPE)
auth_forward = 1;
}
OPENSSL_free(authchunks);
OPENSSL_assert(auth_data);
OPENSSL_assert(auth_forward);
# ifdef SCTP_AUTHENTICATION_EVENT
# ifdef SCTP_EVENT
memset(&event, 0, sizeof(struct sctp_event));
event.se_assoc_id = 0;
event.se_type = SCTP_AUTHENTICATION_EVENT;
event.se_on = 1;
ret =
setsockopt(fd, IPPROTO_SCTP, SCTP_EVENT, &event,
sizeof(struct sctp_event));
if (ret < 0) {
BIO_vfree(bio);
return (NULL);
}
# else
sockopt_len = (socklen_t) sizeof(struct sctp_event_subscribe);
ret = getsockopt(fd, IPPROTO_SCTP, SCTP_EVENTS, &event, &sockopt_len);
if (ret < 0) {
BIO_vfree(bio);
return (NULL);
}
event.sctp_authentication_event = 1;
ret =
setsockopt(fd, IPPROTO_SCTP, SCTP_EVENTS, &event,
sizeof(struct sctp_event_subscribe));
if (ret < 0) {
BIO_vfree(bio);
return (NULL);
}
# endif
# endif
ret =
setsockopt(fd, IPPROTO_SCTP, SCTP_PARTIAL_DELIVERY_POINT, &optval,
sizeof(optval));
if (ret < 0) {
BIO_vfree(bio);
return (NULL);
}
return (bio);
}
int BIO_dgram_is_sctp(BIO *bio)
{
return (BIO_method_type(bio) == BIO_TYPE_DGRAM_SCTP);
}
static int dgram_sctp_new(BIO *bi)
{
bio_dgram_sctp_data *data = NULL;
bi->init = 0;
bi->num = 0;
data = OPENSSL_malloc(sizeof(bio_dgram_sctp_data));
if (data == NULL)
return 0;
memset(data, 0x00, sizeof(bio_dgram_sctp_data));
# ifdef SCTP_PR_SCTP_NONE
data->prinfo.pr_policy = SCTP_PR_SCTP_NONE;
# endif
bi->ptr = data;
bi->flags = 0;
return (1);
}
static int dgram_sctp_free(BIO *a)
{
bio_dgram_sctp_data *data;
if (a == NULL)
return (0);
if (!dgram_clear(a))
return 0;
data = (bio_dgram_sctp_data *) a->ptr;
if (data != NULL) {
if (data->saved_message.data != NULL)
OPENSSL_free(data->saved_message.data);
OPENSSL_free(data);
}
return (1);
}
void dgram_sctp_handle_auth_free_key_event(BIO *b,
union sctp_notification *snp)
{
int ret;
struct sctp_authkey_event *authkeyevent = &snp->sn_auth_event;
if (authkeyevent->auth_indication == SCTP_AUTH_FREE_KEY) {
struct sctp_authkeyid authkeyid;
authkeyid.scact_keynumber = authkeyevent->auth_keynumber;
ret = setsockopt(b->num, IPPROTO_SCTP, SCTP_AUTH_DELETE_KEY,
&authkeyid, sizeof(struct sctp_authkeyid));
}
}
static int dgram_sctp_read(BIO *b, char *out, int outl)
{
int ret = 0, n = 0, i, optval;
socklen_t optlen;
bio_dgram_sctp_data *data = (bio_dgram_sctp_data *) b->ptr;
union sctp_notification *snp;
struct msghdr msg;
struct iovec iov;
struct cmsghdr *cmsg;
char cmsgbuf[512];
if (out != NULL) {
clear_socket_error();
do {
memset(&data->rcvinfo, 0x00,
sizeof(struct bio_dgram_sctp_rcvinfo));
iov.iov_base = out;
iov.iov_len = outl;
msg.msg_name = NULL;
msg.msg_namelen = 0;
msg.msg_iov = &iov;
msg.msg_iovlen = 1;
msg.msg_control = cmsgbuf;
msg.msg_controllen = 512;
msg.msg_flags = 0;
n = recvmsg(b->num, &msg, 0);
if (n <= 0) {
if (n < 0)
ret = n;
break;
}
if (msg.msg_controllen > 0) {
for (cmsg = CMSG_FIRSTHDR(&msg); cmsg;
cmsg = CMSG_NXTHDR(&msg, cmsg)) {
if (cmsg->cmsg_level != IPPROTO_SCTP)
continue;
# ifdef SCTP_RCVINFO
if (cmsg->cmsg_type == SCTP_RCVINFO) {
struct sctp_rcvinfo *rcvinfo;
rcvinfo = (struct sctp_rcvinfo *)CMSG_DATA(cmsg);
data->rcvinfo.rcv_sid = rcvinfo->rcv_sid;
data->rcvinfo.rcv_ssn = rcvinfo->rcv_ssn;
data->rcvinfo.rcv_flags = rcvinfo->rcv_flags;
data->rcvinfo.rcv_ppid = rcvinfo->rcv_ppid;
data->rcvinfo.rcv_tsn = rcvinfo->rcv_tsn;
data->rcvinfo.rcv_cumtsn = rcvinfo->rcv_cumtsn;
data->rcvinfo.rcv_context = rcvinfo->rcv_context;
}
# endif
# ifdef SCTP_SNDRCV
if (cmsg->cmsg_type == SCTP_SNDRCV) {
struct sctp_sndrcvinfo *sndrcvinfo;
sndrcvinfo =
(struct sctp_sndrcvinfo *)CMSG_DATA(cmsg);
data->rcvinfo.rcv_sid = sndrcvinfo->sinfo_stream;
data->rcvinfo.rcv_ssn = sndrcvinfo->sinfo_ssn;
data->rcvinfo.rcv_flags = sndrcvinfo->sinfo_flags;
data->rcvinfo.rcv_ppid = sndrcvinfo->sinfo_ppid;
data->rcvinfo.rcv_tsn = sndrcvinfo->sinfo_tsn;
data->rcvinfo.rcv_cumtsn = sndrcvinfo->sinfo_cumtsn;
data->rcvinfo.rcv_context = sndrcvinfo->sinfo_context;
}
# endif
}
}
if (msg.msg_flags & MSG_NOTIFICATION) {
snp = (union sctp_notification *)out;
if (snp->sn_header.sn_type == SCTP_SENDER_DRY_EVENT) {
# ifdef SCTP_EVENT
struct sctp_event event;
# else
struct sctp_event_subscribe event;
socklen_t eventsize;
# endif
if (data->saved_message.length > 0) {
dgram_sctp_write(data->saved_message.bio,
data->saved_message.data,
data->saved_message.length);
OPENSSL_free(data->saved_message.data);
data->saved_message.data = NULL;
data->saved_message.length = 0;
}
# ifdef SCTP_EVENT
memset(&event, 0, sizeof(struct sctp_event));
event.se_assoc_id = 0;
event.se_type = SCTP_SENDER_DRY_EVENT;
event.se_on = 0;
i = setsockopt(b->num, IPPROTO_SCTP, SCTP_EVENT, &event,
sizeof(struct sctp_event));
if (i < 0) {
ret = i;
break;
}
# else
eventsize = sizeof(struct sctp_event_subscribe);
i = getsockopt(b->num, IPPROTO_SCTP, SCTP_EVENTS, &event,
&eventsize);
if (i < 0) {
ret = i;
break;
}
event.sctp_sender_dry_event = 0;
i = setsockopt(b->num, IPPROTO_SCTP, SCTP_EVENTS, &event,
sizeof(struct sctp_event_subscribe));
if (i < 0) {
ret = i;
break;
}
# endif
}
# ifdef SCTP_AUTHENTICATION_EVENT
if (snp->sn_header.sn_type == SCTP_AUTHENTICATION_EVENT)
dgram_sctp_handle_auth_free_key_event(b, snp);
# endif
if (data->handle_notifications != NULL)
data->handle_notifications(b, data->notification_context,
(void *)out);
memset(out, 0, outl);
} else
ret += n;
}
while ((msg.msg_flags & MSG_NOTIFICATION) && (msg.msg_flags & MSG_EOR)
&& (ret < outl));
if (ret > 0 && !(msg.msg_flags & MSG_EOR)) {
if (ret == outl)
return -1;
optlen = (socklen_t) sizeof(int);
ret = getsockopt(b->num, SOL_SOCKET, SO_RCVBUF, &optval, &optlen);
if (ret >= 0)
OPENSSL_assert(optval >= 18445);
optlen = (socklen_t) sizeof(int);
ret =
getsockopt(b->num, IPPROTO_SCTP, SCTP_PARTIAL_DELIVERY_POINT,
&optval, &optlen);
if (ret >= 0)
OPENSSL_assert(optval >= 18445);
OPENSSL_assert(!(msg.msg_flags & MSG_NOTIFICATION));
memset(out, 0, outl);
BIO_set_retry_read(b);
return -1;
}
BIO_clear_retry_flags(b);
if (ret < 0) {
if (BIO_dgram_should_retry(ret)) {
BIO_set_retry_read(b);
data->_errno = get_last_socket_error();
}
}
if (!data->peer_auth_tested) {
int ii, auth_data = 0, auth_forward = 0;
unsigned char *p;
struct sctp_authchunks *authchunks;
optlen =
(socklen_t) (sizeof(sctp_assoc_t) + 256 * sizeof(uint8_t));
authchunks = OPENSSL_malloc(optlen);
memset(authchunks, 0, sizeof(optlen));
ii = getsockopt(b->num, IPPROTO_SCTP, SCTP_PEER_AUTH_CHUNKS,
authchunks, &optlen);
if (ii >= 0)
for (p = (unsigned char *)authchunks->gauth_chunks;
p < (unsigned char *)authchunks + optlen;
p += sizeof(uint8_t)) {
if (*p == OPENSSL_SCTP_DATA_CHUNK_TYPE)
auth_data = 1;
if (*p == OPENSSL_SCTP_FORWARD_CUM_TSN_CHUNK_TYPE)
auth_forward = 1;
}
OPENSSL_free(authchunks);
if (!auth_data || !auth_forward) {
BIOerr(BIO_F_DGRAM_SCTP_READ, BIO_R_CONNECT_ERROR);
return -1;
}
data->peer_auth_tested = 1;
}
}
return (ret);
}
static int dgram_sctp_write(BIO *b, const char *in, int inl)
{
int ret;
bio_dgram_sctp_data *data = (bio_dgram_sctp_data *) b->ptr;
struct bio_dgram_sctp_sndinfo *sinfo = &(data->sndinfo);
struct bio_dgram_sctp_prinfo *pinfo = &(data->prinfo);
struct bio_dgram_sctp_sndinfo handshake_sinfo;
struct iovec iov[1];
struct msghdr msg;
struct cmsghdr *cmsg;
# if defined(SCTP_SNDINFO) && defined(SCTP_PRINFO)
char cmsgbuf[CMSG_SPACE(sizeof(struct sctp_sndinfo)) +
CMSG_SPACE(sizeof(struct sctp_prinfo))];
struct sctp_sndinfo *sndinfo;
struct sctp_prinfo *prinfo;
# else
char cmsgbuf[CMSG_SPACE(sizeof(struct sctp_sndrcvinfo))];
struct sctp_sndrcvinfo *sndrcvinfo;
# endif
clear_socket_error();
if (in[0] != 23) {
memset(&handshake_sinfo, 0x00, sizeof(struct bio_dgram_sctp_sndinfo));
# ifdef SCTP_SACK_IMMEDIATELY
handshake_sinfo.snd_flags = SCTP_SACK_IMMEDIATELY;
# endif
sinfo = &handshake_sinfo;
}
if (data->save_shutdown && !BIO_dgram_sctp_wait_for_dry(b)) {
data->saved_message.bio = b;
if (data->saved_message.data)
OPENSSL_free(data->saved_message.data);
data->saved_message.data = OPENSSL_malloc(inl);
memcpy(data->saved_message.data, in, inl);
data->saved_message.length = inl;
return inl;
}
iov[0].iov_base = (char *)in;
iov[0].iov_len = inl;
msg.msg_name = NULL;
msg.msg_namelen = 0;
msg.msg_iov = iov;
msg.msg_iovlen = 1;
msg.msg_control = (caddr_t) cmsgbuf;
msg.msg_controllen = 0;
msg.msg_flags = 0;
# if defined(SCTP_SNDINFO) && defined(SCTP_PRINFO)
cmsg = (struct cmsghdr *)cmsgbuf;
cmsg->cmsg_level = IPPROTO_SCTP;
cmsg->cmsg_type = SCTP_SNDINFO;
cmsg->cmsg_len = CMSG_LEN(sizeof(struct sctp_sndinfo));
sndinfo = (struct sctp_sndinfo *)CMSG_DATA(cmsg);
memset(sndinfo, 0, sizeof(struct sctp_sndinfo));
sndinfo->snd_sid = sinfo->snd_sid;
sndinfo->snd_flags = sinfo->snd_flags;
sndinfo->snd_ppid = sinfo->snd_ppid;
sndinfo->snd_context = sinfo->snd_context;
msg.msg_controllen += CMSG_SPACE(sizeof(struct sctp_sndinfo));
cmsg =
(struct cmsghdr *)&cmsgbuf[CMSG_SPACE(sizeof(struct sctp_sndinfo))];
cmsg->cmsg_level = IPPROTO_SCTP;
cmsg->cmsg_type = SCTP_PRINFO;
cmsg->cmsg_len = CMSG_LEN(sizeof(struct sctp_prinfo));
prinfo = (struct sctp_prinfo *)CMSG_DATA(cmsg);
memset(prinfo, 0, sizeof(struct sctp_prinfo));
prinfo->pr_policy = pinfo->pr_policy;
prinfo->pr_value = pinfo->pr_value;
msg.msg_controllen += CMSG_SPACE(sizeof(struct sctp_prinfo));
# else
cmsg = (struct cmsghdr *)cmsgbuf;
cmsg->cmsg_level = IPPROTO_SCTP;
cmsg->cmsg_type = SCTP_SNDRCV;
cmsg->cmsg_len = CMSG_LEN(sizeof(struct sctp_sndrcvinfo));
sndrcvinfo = (struct sctp_sndrcvinfo *)CMSG_DATA(cmsg);
memset(sndrcvinfo, 0, sizeof(struct sctp_sndrcvinfo));
sndrcvinfo->sinfo_stream = sinfo->snd_sid;
sndrcvinfo->sinfo_flags = sinfo->snd_flags;
# ifdef __FreeBSD__
sndrcvinfo->sinfo_flags |= pinfo->pr_policy;
# endif
sndrcvinfo->sinfo_ppid = sinfo->snd_ppid;
sndrcvinfo->sinfo_context = sinfo->snd_context;
sndrcvinfo->sinfo_timetolive = pinfo->pr_value;
msg.msg_controllen += CMSG_SPACE(sizeof(struct sctp_sndrcvinfo));
# endif
ret = sendmsg(b->num, &msg, 0);
BIO_clear_retry_flags(b);
if (ret <= 0) {
if (BIO_dgram_should_retry(ret)) {
BIO_set_retry_write(b);
data->_errno = get_last_socket_error();
}
}
return (ret);
}
static long dgram_sctp_ctrl(BIO *b, int cmd, long num, void *ptr)
{
long ret = 1;
bio_dgram_sctp_data *data = NULL;
socklen_t sockopt_len = 0;
struct sctp_authkeyid authkeyid;
struct sctp_authkey *authkey = NULL;
data = (bio_dgram_sctp_data *) b->ptr;
switch (cmd) {
case BIO_CTRL_DGRAM_QUERY_MTU:
data->mtu = 16384;
ret = data->mtu;
break;
case BIO_CTRL_DGRAM_SET_MTU:
data->mtu = 16384;
ret = data->mtu;
break;
case BIO_CTRL_DGRAM_SET_CONNECTED:
case BIO_CTRL_DGRAM_CONNECT:
ret = -1;
break;
case BIO_CTRL_DGRAM_SET_NEXT_TIMEOUT:
break;
case BIO_CTRL_DGRAM_GET_MTU_OVERHEAD:
ret = 0;
break;
case BIO_CTRL_DGRAM_SCTP_SET_IN_HANDSHAKE:
if (num > 0)
data->in_handshake = 1;
else
data->in_handshake = 0;
ret =
setsockopt(b->num, IPPROTO_SCTP, SCTP_NODELAY,
&data->in_handshake, sizeof(int));
break;
case BIO_CTRL_DGRAM_SCTP_ADD_AUTH_KEY:
sockopt_len = sizeof(struct sctp_authkeyid);
ret =
getsockopt(b->num, IPPROTO_SCTP, SCTP_AUTH_ACTIVE_KEY, &authkeyid,
&sockopt_len);
if (ret < 0)
break;
sockopt_len = sizeof(struct sctp_authkey) + 64 * sizeof(uint8_t);
authkey = OPENSSL_malloc(sockopt_len);
if (authkey == NULL) {
ret = -1;
break;
}
memset(authkey, 0x00, sockopt_len);
authkey->sca_keynumber = authkeyid.scact_keynumber + 1;
# ifndef __FreeBSD__
authkey->sca_keylength = 64;
# endif
memcpy(&authkey->sca_key[0], ptr, 64 * sizeof(uint8_t));
ret =
setsockopt(b->num, IPPROTO_SCTP, SCTP_AUTH_KEY, authkey,
sockopt_len);
OPENSSL_free(authkey);
authkey = NULL;
if (ret < 0)
break;
ret = setsockopt(b->num, IPPROTO_SCTP, SCTP_AUTH_ACTIVE_KEY,
&authkeyid, sizeof(struct sctp_authkeyid));
if (ret < 0)
break;
break;
case BIO_CTRL_DGRAM_SCTP_NEXT_AUTH_KEY:
sockopt_len = sizeof(struct sctp_authkeyid);
ret =
getsockopt(b->num, IPPROTO_SCTP, SCTP_AUTH_ACTIVE_KEY, &authkeyid,
&sockopt_len);
if (ret < 0)
break;
authkeyid.scact_keynumber = authkeyid.scact_keynumber + 1;
ret = setsockopt(b->num, IPPROTO_SCTP, SCTP_AUTH_ACTIVE_KEY,
&authkeyid, sizeof(struct sctp_authkeyid));
if (ret < 0)
break;
data->ccs_sent = 1;
case BIO_CTRL_DGRAM_SCTP_AUTH_CCS_RCVD:
if (cmd == BIO_CTRL_DGRAM_SCTP_AUTH_CCS_RCVD)
data->ccs_rcvd = 1;
if (data->ccs_rcvd == 1 && data->ccs_sent == 1) {
sockopt_len = sizeof(struct sctp_authkeyid);
ret =
getsockopt(b->num, IPPROTO_SCTP, SCTP_AUTH_ACTIVE_KEY,
&authkeyid, &sockopt_len);
if (ret < 0)
break;
authkeyid.scact_keynumber = authkeyid.scact_keynumber - 1;
# ifdef SCTP_AUTH_DEACTIVATE_KEY
sockopt_len = sizeof(struct sctp_authkeyid);
ret = setsockopt(b->num, IPPROTO_SCTP, SCTP_AUTH_DEACTIVATE_KEY,
&authkeyid, sockopt_len);
if (ret < 0)
break;
# endif
# ifndef SCTP_AUTHENTICATION_EVENT
if (authkeyid.scact_keynumber > 0) {
authkeyid.scact_keynumber = authkeyid.scact_keynumber - 1;
ret = setsockopt(b->num, IPPROTO_SCTP, SCTP_AUTH_DELETE_KEY,
&authkeyid, sizeof(struct sctp_authkeyid));
if (ret < 0)
break;
}
# endif
data->ccs_rcvd = 0;
data->ccs_sent = 0;
}
break;
case BIO_CTRL_DGRAM_SCTP_GET_SNDINFO:
if (num > (long)sizeof(struct bio_dgram_sctp_sndinfo))
num = sizeof(struct bio_dgram_sctp_sndinfo);
memcpy(ptr, &(data->sndinfo), num);
ret = num;
break;
case BIO_CTRL_DGRAM_SCTP_SET_SNDINFO:
if (num > (long)sizeof(struct bio_dgram_sctp_sndinfo))
num = sizeof(struct bio_dgram_sctp_sndinfo);
memcpy(&(data->sndinfo), ptr, num);
break;
case BIO_CTRL_DGRAM_SCTP_GET_RCVINFO:
if (num > (long)sizeof(struct bio_dgram_sctp_rcvinfo))
num = sizeof(struct bio_dgram_sctp_rcvinfo);
memcpy(ptr, &data->rcvinfo, num);
ret = num;
break;
case BIO_CTRL_DGRAM_SCTP_SET_RCVINFO:
if (num > (long)sizeof(struct bio_dgram_sctp_rcvinfo))
num = sizeof(struct bio_dgram_sctp_rcvinfo);
memcpy(&(data->rcvinfo), ptr, num);
break;
case BIO_CTRL_DGRAM_SCTP_GET_PRINFO:
if (num > (long)sizeof(struct bio_dgram_sctp_prinfo))
num = sizeof(struct bio_dgram_sctp_prinfo);
memcpy(ptr, &(data->prinfo), num);
ret = num;
break;
case BIO_CTRL_DGRAM_SCTP_SET_PRINFO:
if (num > (long)sizeof(struct bio_dgram_sctp_prinfo))
num = sizeof(struct bio_dgram_sctp_prinfo);
memcpy(&(data->prinfo), ptr, num);
break;
case BIO_CTRL_DGRAM_SCTP_SAVE_SHUTDOWN:
if (num > 0)
data->save_shutdown = 1;
else
data->save_shutdown = 0;
break;
default:
ret = dgram_ctrl(b, cmd, num, ptr);
break;
}
return (ret);
}
int BIO_dgram_sctp_notification_cb(BIO *b,
void (*handle_notifications) (BIO *bio,
void
*context,
void *buf),
void *context)
{
bio_dgram_sctp_data *data = (bio_dgram_sctp_data *) b->ptr;
if (handle_notifications != NULL) {
data->handle_notifications = handle_notifications;
data->notification_context = context;
} else
return -1;
return 0;
}
int BIO_dgram_sctp_wait_for_dry(BIO *b)
{
int is_dry = 0;
int n, sockflags, ret;
union sctp_notification snp;
struct msghdr msg;
struct iovec iov;
# ifdef SCTP_EVENT
struct sctp_event event;
# else
struct sctp_event_subscribe event;
socklen_t eventsize;
# endif
bio_dgram_sctp_data *data = (bio_dgram_sctp_data *) b->ptr;
# ifdef SCTP_EVENT
memset(&event, 0, sizeof(struct sctp_event));
event.se_assoc_id = 0;
event.se_type = SCTP_SENDER_DRY_EVENT;
event.se_on = 1;
ret =
setsockopt(b->num, IPPROTO_SCTP, SCTP_EVENT, &event,
sizeof(struct sctp_event));
# else
eventsize = sizeof(struct sctp_event_subscribe);
ret = getsockopt(b->num, IPPROTO_SCTP, SCTP_EVENTS, &event, &eventsize);
if (ret < 0)
return -1;
event.sctp_sender_dry_event = 1;
ret =
setsockopt(b->num, IPPROTO_SCTP, SCTP_EVENTS, &event,
sizeof(struct sctp_event_subscribe));
# endif
if (ret < 0)
return -1;
memset(&snp, 0x00, sizeof(union sctp_notification));
iov.iov_base = (char *)&snp;
iov.iov_len = sizeof(union sctp_notification);
msg.msg_name = NULL;
msg.msg_namelen = 0;
msg.msg_iov = &iov;
msg.msg_iovlen = 1;
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
n = recvmsg(b->num, &msg, MSG_PEEK);
if (n <= 0) {
if ((n < 0) && (get_last_socket_error() != EAGAIN)
&& (get_last_socket_error() != EWOULDBLOCK))
return -1;
else
return 0;
}
while (msg.msg_flags & MSG_NOTIFICATION) {
memset(&snp, 0x00, sizeof(union sctp_notification));
iov.iov_base = (char *)&snp;
iov.iov_len = sizeof(union sctp_notification);
msg.msg_name = NULL;
msg.msg_namelen = 0;
msg.msg_iov = &iov;
msg.msg_iovlen = 1;
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
n = recvmsg(b->num, &msg, 0);
if (n <= 0) {
if ((n < 0) && (get_last_socket_error() != EAGAIN)
&& (get_last_socket_error() != EWOULDBLOCK))
return -1;
else
return is_dry;
}
if (snp.sn_header.sn_type == SCTP_SENDER_DRY_EVENT) {
is_dry = 1;
# ifdef SCTP_EVENT
memset(&event, 0, sizeof(struct sctp_event));
event.se_assoc_id = 0;
event.se_type = SCTP_SENDER_DRY_EVENT;
event.se_on = 0;
ret =
setsockopt(b->num, IPPROTO_SCTP, SCTP_EVENT, &event,
sizeof(struct sctp_event));
# else
eventsize = (socklen_t) sizeof(struct sctp_event_subscribe);
ret =
getsockopt(b->num, IPPROTO_SCTP, SCTP_EVENTS, &event,
&eventsize);
if (ret < 0)
return -1;
event.sctp_sender_dry_event = 0;
ret =
setsockopt(b->num, IPPROTO_SCTP, SCTP_EVENTS, &event,
sizeof(struct sctp_event_subscribe));
# endif
if (ret < 0)
return -1;
}
# ifdef SCTP_AUTHENTICATION_EVENT
if (snp.sn_header.sn_type == SCTP_AUTHENTICATION_EVENT)
dgram_sctp_handle_auth_free_key_event(b, &snp);
# endif
if (data->handle_notifications != NULL)
data->handle_notifications(b, data->notification_context,
(void *)&snp);
memset(&snp, 0x00, sizeof(union sctp_notification));
iov.iov_base = (char *)&snp;
iov.iov_len = sizeof(union sctp_notification);
msg.msg_name = NULL;
msg.msg_namelen = 0;
msg.msg_iov = &iov;
msg.msg_iovlen = 1;
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
if (is_dry) {
sockflags = fcntl(b->num, F_GETFL, 0);
fcntl(b->num, F_SETFL, O_NONBLOCK);
}
n = recvmsg(b->num, &msg, MSG_PEEK);
if (is_dry) {
fcntl(b->num, F_SETFL, sockflags);
}
if (n <= 0) {
if ((n < 0) && (get_last_socket_error() != EAGAIN)
&& (get_last_socket_error() != EWOULDBLOCK))
return -1;
else
return is_dry;
}
}
return is_dry;
}
int BIO_dgram_sctp_msg_waiting(BIO *b)
{
int n, sockflags;
union sctp_notification snp;
struct msghdr msg;
struct iovec iov;
bio_dgram_sctp_data *data = (bio_dgram_sctp_data *) b->ptr;
do {
memset(&snp, 0x00, sizeof(union sctp_notification));
iov.iov_base = (char *)&snp;
iov.iov_len = sizeof(union sctp_notification);
msg.msg_name = NULL;
msg.msg_namelen = 0;
msg.msg_iov = &iov;
msg.msg_iovlen = 1;
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
sockflags = fcntl(b->num, F_GETFL, 0);
fcntl(b->num, F_SETFL, O_NONBLOCK);
n = recvmsg(b->num, &msg, MSG_PEEK);
fcntl(b->num, F_SETFL, sockflags);
if (n > 0 && (msg.msg_flags & MSG_NOTIFICATION)) {
# ifdef SCTP_AUTHENTICATION_EVENT
if (snp.sn_header.sn_type == SCTP_AUTHENTICATION_EVENT)
dgram_sctp_handle_auth_free_key_event(b, &snp);
# endif
memset(&snp, 0x00, sizeof(union sctp_notification));
iov.iov_base = (char *)&snp;
iov.iov_len = sizeof(union sctp_notification);
msg.msg_name = NULL;
msg.msg_namelen = 0;
msg.msg_iov = &iov;
msg.msg_iovlen = 1;
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
n = recvmsg(b->num, &msg, 0);
if (data->handle_notifications != NULL)
data->handle_notifications(b, data->notification_context,
(void *)&snp);
}
} while (n > 0 && (msg.msg_flags & MSG_NOTIFICATION));
if (n > 0)
return 1;
else
return 0;
}
static int dgram_sctp_puts(BIO *bp, const char *str)
{
int n, ret;
n = strlen(str);
ret = dgram_sctp_write(bp, str, n);
return (ret);
}
static int BIO_dgram_should_retry(int i)
{
int err;
if ((i == 0) || (i == -1)) {
err = get_last_socket_error();
# if defined(OPENSSL_SYS_WINDOWS)
# endif
return (BIO_dgram_non_fatal_error(err));
}
return (0);
}
int BIO_dgram_non_fatal_error(int err)
{
switch (err) {
# if defined(OPENSSL_SYS_WINDOWS)
# if defined(WSAEWOULDBLOCK)
case WSAEWOULDBLOCK:
# endif
# if 0
# if defined(WSAENOTCONN)
case WSAENOTCONN:
# endif
# endif
# endif
# ifdef EWOULDBLOCK
# ifdef WSAEWOULDBLOCK
# if WSAEWOULDBLOCK != EWOULDBLOCK
case EWOULDBLOCK:
# endif
# else
case EWOULDBLOCK:
# endif
# endif
# ifdef EINTR
case EINTR:
# endif
# ifdef EAGAIN
# if EWOULDBLOCK != EAGAIN
case EAGAIN:
# endif
# endif
# ifdef EPROTO
case EPROTO:
# endif
# ifdef EINPROGRESS
case EINPROGRESS:
# endif
# ifdef EALREADY
case EALREADY:
# endif
return (1);
default:
break;
}
return (0);
}
static void get_current_time(struct timeval *t)
{
# if defined(_WIN32)
SYSTEMTIME st;
union {
unsigned __int64 ul;
FILETIME ft;
} now;
GetSystemTime(&st);
SystemTimeToFileTime(&st, &now.ft);
# ifdef __MINGW32__
now.ul -= 116444736000000000ULL;
# else
now.ul -= 116444736000000000UI64;
# endif
t->tv_sec = (long)(now.ul / 10000000);
t->tv_usec = ((int)(now.ul % 10000000)) / 10;
# elif defined(OPENSSL_SYS_VMS)
struct timeb tb;
ftime(&tb);
t->tv_sec = (long)tb.time;
t->tv_usec = (long)tb.millitm * 1000;
# else
gettimeofday(t, NULL);
# endif
}
