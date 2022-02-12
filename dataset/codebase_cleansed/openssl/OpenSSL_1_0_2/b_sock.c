int BIO_get_host_ip(const char *str, unsigned char *ip)
{
int i;
int err = 1;
int locked = 0;
struct hostent *he;
i = get_ip(str, ip);
if (i < 0) {
BIOerr(BIO_F_BIO_GET_HOST_IP, BIO_R_INVALID_IP_ADDRESS);
goto err;
}
if (BIO_sock_init() != 1)
return 0;
if (i > 0)
return (1);
CRYPTO_w_lock(CRYPTO_LOCK_GETHOSTBYNAME);
locked = 1;
he = BIO_gethostbyname(str);
if (he == NULL) {
BIOerr(BIO_F_BIO_GET_HOST_IP, BIO_R_BAD_HOSTNAME_LOOKUP);
goto err;
}
if ((short)he->h_addrtype != AF_INET) {
BIOerr(BIO_F_BIO_GET_HOST_IP,
BIO_R_GETHOSTBYNAME_ADDR_IS_NOT_AF_INET);
goto err;
}
for (i = 0; i < 4; i++)
ip[i] = he->h_addr_list[0][i];
err = 0;
err:
if (locked)
CRYPTO_w_unlock(CRYPTO_LOCK_GETHOSTBYNAME);
if (err) {
ERR_add_error_data(2, "host=", str);
return 0;
} else
return 1;
}
int BIO_get_port(const char *str, unsigned short *port_ptr)
{
int i;
struct servent *s;
if (str == NULL) {
BIOerr(BIO_F_BIO_GET_PORT, BIO_R_NO_PORT_DEFINED);
return (0);
}
i = atoi(str);
if (i != 0)
*port_ptr = (unsigned short)i;
else {
CRYPTO_w_lock(CRYPTO_LOCK_GETSERVBYNAME);
# ifndef CONST_STRICT
s = getservbyname((char *)str, "tcp");
# else
s = getservbyname(str, "tcp");
# endif
if (s != NULL)
*port_ptr = ntohs((unsigned short)s->s_port);
CRYPTO_w_unlock(CRYPTO_LOCK_GETSERVBYNAME);
if (s == NULL) {
if (strcmp(str, "http") == 0)
*port_ptr = 80;
else if (strcmp(str, "telnet") == 0)
*port_ptr = 23;
else if (strcmp(str, "socks") == 0)
*port_ptr = 1080;
else if (strcmp(str, "https") == 0)
*port_ptr = 443;
else if (strcmp(str, "ssl") == 0)
*port_ptr = 443;
else if (strcmp(str, "ftp") == 0)
*port_ptr = 21;
else if (strcmp(str, "gopher") == 0)
*port_ptr = 70;
# if 0
else if (strcmp(str, "wais") == 0)
*port_ptr = 21;
# endif
else {
SYSerr(SYS_F_GETSERVBYNAME, get_last_socket_error());
ERR_add_error_data(3, "service='", str, "'");
return (0);
}
}
}
return (1);
}
int BIO_sock_error(int sock)
{
int j, i;
union {
size_t s;
int i;
} size;
# if defined(OPENSSL_SYS_BEOS_R5)
return 0;
# endif
size.s = 0, size.i = sizeof(j);
i = getsockopt(sock, SOL_SOCKET, SO_ERROR, (void *)&j, (void *)&size);
if (i < 0)
return (1);
else
return (j);
}
struct hostent *BIO_gethostbyname(const char *name)
{
# if 1
# if (defined(NETWARE_BSDSOCK) && !defined(__NOVELL_LIBC__))
return gethostbyname((char *)name);
# else
return gethostbyname(name);
# endif
# else
struct hostent *ret;
int i, lowi = 0, j;
unsigned long low = (unsigned long)-1;
# if 0
CRYPTO_w_lock(CRYPTO_LOCK_GETHOSTBYNAME);
# endif
j = strlen(name);
if (j < 128) {
for (i = 0; i < GHBN_NUM; i++) {
if (low > ghbn_cache[i].order) {
low = ghbn_cache[i].order;
lowi = i;
}
if (ghbn_cache[i].order > 0) {
if (strncmp(name, ghbn_cache[i].name, 128) == 0)
break;
}
}
} else
i = GHBN_NUM;
if (i == GHBN_NUM) {
BIO_ghbn_miss++;
# ifndef CONST_STRICT
ret = gethostbyname((char *)name);
# else
ret = gethostbyname(name);
# endif
if (ret == NULL)
goto end;
if (j > 128) {
# if 0
ret = NULL;
# endif
goto end;
}
if (ghbn_cache[lowi].ent != NULL)
ghbn_free(ghbn_cache[lowi].ent);
ghbn_cache[lowi].name[0] = '\0';
if ((ret = ghbn_cache[lowi].ent = ghbn_dup(ret)) == NULL) {
BIOerr(BIO_F_BIO_GETHOSTBYNAME, ERR_R_MALLOC_FAILURE);
goto end;
}
strncpy(ghbn_cache[lowi].name, name, 128);
ghbn_cache[lowi].order = BIO_ghbn_miss + BIO_ghbn_hits;
} else {
BIO_ghbn_hits++;
ret = ghbn_cache[i].ent;
ghbn_cache[i].order = BIO_ghbn_miss + BIO_ghbn_hits;
}
end:
# if 0
CRYPTO_w_unlock(CRYPTO_LOCK_GETHOSTBYNAME);
# endif
return (ret);
# endif
}
int BIO_sock_init(void)
{
# ifdef OPENSSL_SYS_WINDOWS
static struct WSAData wsa_state;
if (!wsa_init_done) {
int err;
wsa_init_done = 1;
memset(&wsa_state, 0, sizeof(wsa_state));
if (WSAStartup(0x0202, &wsa_state) != 0) {
err = WSAGetLastError();
SYSerr(SYS_F_WSASTARTUP, err);
BIOerr(BIO_F_BIO_SOCK_INIT, BIO_R_WSASTARTUP);
return (-1);
}
}
# endif
# ifdef WATT32
extern int _watt_do_exit;
_watt_do_exit = 0;
if (sock_init())
return (-1);
# endif
# if defined(OPENSSL_SYS_NETWARE) && !defined(NETWARE_BSDSOCK)
WORD wVerReq;
WSADATA wsaData;
int err;
if (!wsa_init_done) {
wsa_init_done = 1;
wVerReq = MAKEWORD(2, 0);
err = WSAStartup(wVerReq, &wsaData);
if (err != 0) {
SYSerr(SYS_F_WSASTARTUP, err);
BIOerr(BIO_F_BIO_SOCK_INIT, BIO_R_WSASTARTUP);
return (-1);
}
}
# endif
return (1);
}
void BIO_sock_cleanup(void)
{
# ifdef OPENSSL_SYS_WINDOWS
if (wsa_init_done) {
wsa_init_done = 0;
# if 0
WSACancelBlockingCall();
# endif
WSACleanup();
}
# elif defined(OPENSSL_SYS_NETWARE) && !defined(NETWARE_BSDSOCK)
if (wsa_init_done) {
wsa_init_done = 0;
WSACleanup();
}
# endif
}
int BIO_socket_ioctl(int fd, long type, void *arg)
{
int i;
# ifdef __DJGPP__
i = ioctlsocket(fd, type, (char *)arg);
# else
# if defined(OPENSSL_SYS_VMS)
# if __INITIAL_POINTER_SIZE == 64
# define ARG arg_32p
# pragma pointer_size save
# pragma pointer_size 32
unsigned long arg_32;
unsigned long *arg_32p;
# pragma pointer_size restore
arg_32p = &arg_32;
arg_32 = *((unsigned long *)arg);
# else
# define ARG arg
# endif
# else
# define ARG arg
# endif
i = ioctlsocket(fd, type, ARG);
# endif
if (i < 0)
SYSerr(SYS_F_IOCTLSOCKET, get_last_socket_error());
return (i);
}
static int get_ip(const char *str, unsigned char ip[4])
{
unsigned int tmp[4];
int num = 0, c, ok = 0;
tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0;
for (;;) {
c = *(str++);
if ((c >= '0') && (c <= '9')) {
ok = 1;
tmp[num] = tmp[num] * 10 + c - '0';
if (tmp[num] > 255)
return (0);
} else if (c == '.') {
if (!ok)
return (-1);
if (num == 3)
return (0);
num++;
ok = 0;
} else if (c == '\0' && (num == 3) && ok)
break;
else
return (0);
}
ip[0] = tmp[0];
ip[1] = tmp[1];
ip[2] = tmp[2];
ip[3] = tmp[3];
return (1);
}
int BIO_get_accept_socket(char *host, int bind_mode)
{
int ret = 0;
union {
struct sockaddr sa;
struct sockaddr_in sa_in;
# if OPENSSL_USE_IPV6
struct sockaddr_in6 sa_in6;
# endif
} server, client;
int s = INVALID_SOCKET, cs, addrlen;
unsigned char ip[4];
unsigned short port;
char *str = NULL, *e;
char *h, *p;
unsigned long l;
int err_num;
if (BIO_sock_init() != 1)
return (INVALID_SOCKET);
if ((str = BUF_strdup(host)) == NULL)
return (INVALID_SOCKET);
h = p = NULL;
h = str;
for (e = str; *e; e++) {
if (*e == ':') {
p = e;
} else if (*e == '/') {
*e = '\0';
break;
}
}
if (p)
*p++ = '\0';
else
p = h, h = NULL;
# ifdef EAI_FAMILY
do {
static union {
void *p;
int (WSAAPI *f) (const char *, const char *,
const struct addrinfo *, struct addrinfo **);
} p_getaddrinfo = {
NULL
};
static union {
void *p;
void (WSAAPI *f) (struct addrinfo *);
} p_freeaddrinfo = {
NULL
};
struct addrinfo *res, hint;
if (p_getaddrinfo.p == NULL) {
if ((p_getaddrinfo.p = DSO_global_lookup("getaddrinfo")) == NULL
|| (p_freeaddrinfo.p =
DSO_global_lookup("freeaddrinfo")) == NULL)
p_getaddrinfo.p = (void *)-1;
}
if (p_getaddrinfo.p == (void *)-1)
break;
memset(&hint, 0, sizeof(hint));
hint.ai_flags = AI_PASSIVE;
if (h) {
if (strchr(h, ':')) {
if (h[1] == '\0')
h = NULL;
# if OPENSSL_USE_IPV6
hint.ai_family = AF_INET6;
# else
h = NULL;
# endif
} else if (h[0] == '*' && h[1] == '\0') {
hint.ai_family = AF_INET;
h = NULL;
}
}
if ((*p_getaddrinfo.f) (h, p, &hint, &res))
break;
addrlen = res->ai_addrlen <= sizeof(server) ?
res->ai_addrlen : sizeof(server);
memcpy(&server, res->ai_addr, addrlen);
(*p_freeaddrinfo.f) (res);
goto again;
} while (0);
# endif
if (!BIO_get_port(p, &port))
goto err;
memset((char *)&server, 0, sizeof(server));
server.sa_in.sin_family = AF_INET;
server.sa_in.sin_port = htons(port);
addrlen = sizeof(server.sa_in);
if (h == NULL || strcmp(h, "*") == 0)
server.sa_in.sin_addr.s_addr = INADDR_ANY;
else {
if (!BIO_get_host_ip(h, &(ip[0])))
goto err;
l = (unsigned long)
((unsigned long)ip[0] << 24L) |
((unsigned long)ip[1] << 16L) |
((unsigned long)ip[2] << 8L) | ((unsigned long)ip[3]);
server.sa_in.sin_addr.s_addr = htonl(l);
}
again:
s = socket(server.sa.sa_family, SOCK_STREAM, SOCKET_PROTOCOL);
if (s == INVALID_SOCKET) {
SYSerr(SYS_F_SOCKET, get_last_socket_error());
ERR_add_error_data(3, "port='", host, "'");
BIOerr(BIO_F_BIO_GET_ACCEPT_SOCKET, BIO_R_UNABLE_TO_CREATE_SOCKET);
goto err;
}
# ifdef SO_REUSEADDR
if (bind_mode == BIO_BIND_REUSEADDR) {
int i = 1;
ret = setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char *)&i, sizeof(i));
bind_mode = BIO_BIND_NORMAL;
}
# endif
if (bind(s, &server.sa, addrlen) == -1) {
# ifdef SO_REUSEADDR
err_num = get_last_socket_error();
if ((bind_mode == BIO_BIND_REUSEADDR_IF_UNUSED) &&
# ifdef OPENSSL_SYS_WINDOWS
(err_num == WSAEADDRINUSE))
# else
(err_num == EADDRINUSE))
# endif
{
client = server;
if (h == NULL || strcmp(h, "*") == 0) {
# if OPENSSL_USE_IPV6
if (client.sa.sa_family == AF_INET6) {
memset(&client.sa_in6.sin6_addr, 0,
sizeof(client.sa_in6.sin6_addr));
client.sa_in6.sin6_addr.s6_addr[15] = 1;
} else
# endif
if (client.sa.sa_family == AF_INET) {
client.sa_in.sin_addr.s_addr = htonl(0x7F000001);
} else
goto err;
}
cs = socket(client.sa.sa_family, SOCK_STREAM, SOCKET_PROTOCOL);
if (cs != INVALID_SOCKET) {
int ii;
ii = connect(cs, &client.sa, addrlen);
closesocket(cs);
if (ii == INVALID_SOCKET) {
bind_mode = BIO_BIND_REUSEADDR;
closesocket(s);
goto again;
}
}
}
# endif
SYSerr(SYS_F_BIND, err_num);
ERR_add_error_data(3, "port='", host, "'");
BIOerr(BIO_F_BIO_GET_ACCEPT_SOCKET, BIO_R_UNABLE_TO_BIND_SOCKET);
goto err;
}
int BIO_set_tcp_ndelay(int s, int on)
{
int ret = 0;
# if defined(TCP_NODELAY) && (defined(IPPROTO_TCP) || defined(SOL_TCP))
int opt;
# ifdef SOL_TCP
opt = SOL_TCP;
# else
# ifdef IPPROTO_TCP
opt = IPPROTO_TCP;
# endif
# endif
ret = setsockopt(s, opt, TCP_NODELAY, (char *)&on, sizeof(on));
# endif
return (ret == 0);
}
int BIO_socket_nbio(int s, int mode)
{
int ret = -1;
int l;
l = mode;
# ifdef FIONBIO
ret = BIO_socket_ioctl(s, FIONBIO, &l);
# endif
return (ret == 0);
}
