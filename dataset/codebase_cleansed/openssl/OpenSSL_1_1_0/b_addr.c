BIO_ADDR *BIO_ADDR_new(void)
{
BIO_ADDR *ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL) {
BIOerr(BIO_F_BIO_ADDR_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
ret->sa.sa_family = AF_UNSPEC;
return ret;
}
void BIO_ADDR_free(BIO_ADDR *ap)
{
OPENSSL_free(ap);
}
void BIO_ADDR_clear(BIO_ADDR *ap)
{
memset(ap, 0, sizeof(*ap));
ap->sa.sa_family = AF_UNSPEC;
}
int BIO_ADDR_make(BIO_ADDR *ap, const struct sockaddr *sa)
{
if (sa->sa_family == AF_INET) {
ap->s_in = *(const struct sockaddr_in *)sa;
return 1;
}
#ifdef AF_INET6
if (sa->sa_family == AF_INET6) {
ap->s_in6 = *(const struct sockaddr_in6 *)sa;
return 1;
}
#endif
#ifdef AF_UNIX
if (ap->sa.sa_family == AF_UNIX) {
ap->s_un = *(const struct sockaddr_un *)sa;
return 1;
}
#endif
return 0;
}
int BIO_ADDR_rawmake(BIO_ADDR *ap, int family,
const void *where, size_t wherelen,
unsigned short port)
{
#ifdef AF_UNIX
if (family == AF_UNIX) {
if (wherelen + 1 > sizeof(ap->s_un.sun_path))
return 0;
memset(&ap->s_un, 0, sizeof(ap->s_un));
ap->s_un.sun_family = family;
strncpy(ap->s_un.sun_path, where, sizeof(ap->s_un.sun_path) - 1);
return 1;
}
#endif
if (family == AF_INET) {
if (wherelen != sizeof(struct in_addr))
return 0;
memset(&ap->s_in, 0, sizeof(ap->s_in));
ap->s_in.sin_family = family;
ap->s_in.sin_port = port;
ap->s_in.sin_addr = *(struct in_addr *)where;
return 1;
}
#ifdef AF_INET6
if (family == AF_INET6) {
if (wherelen != sizeof(struct in6_addr))
return 0;
memset(&ap->s_in6, 0, sizeof(ap->s_in6));
ap->s_in6.sin6_family = family;
ap->s_in6.sin6_port = port;
ap->s_in6.sin6_addr = *(struct in6_addr *)where;
return 1;
}
#endif
return 0;
}
int BIO_ADDR_family(const BIO_ADDR *ap)
{
return ap->sa.sa_family;
}
int BIO_ADDR_rawaddress(const BIO_ADDR *ap, void *p, size_t *l)
{
size_t len = 0;
const void *addrptr = NULL;
if (ap->sa.sa_family == AF_INET) {
len = sizeof(ap->s_in.sin_addr);
addrptr = &ap->s_in.sin_addr;
}
#ifdef AF_INET6
else if (ap->sa.sa_family == AF_INET6) {
len = sizeof(ap->s_in6.sin6_addr);
addrptr = &ap->s_in6.sin6_addr;
}
#endif
#ifdef AF_UNIX
else if (ap->sa.sa_family == AF_UNIX) {
len = strlen(ap->s_un.sun_path);
addrptr = &ap->s_un.sun_path;
}
#endif
if (addrptr == NULL)
return 0;
if (p != NULL) {
memcpy(p, addrptr, len);
}
if (l != NULL)
*l = len;
return 1;
}
unsigned short BIO_ADDR_rawport(const BIO_ADDR *ap)
{
if (ap->sa.sa_family == AF_INET)
return ap->s_in.sin_port;
#ifdef AF_INET6
if (ap->sa.sa_family == AF_INET6)
return ap->s_in6.sin6_port;
#endif
return 0;
}
static int addr_strings(const BIO_ADDR *ap, int numeric,
char **hostname, char **service)
{
if (BIO_sock_init() != 1)
return 0;
if (1) {
#ifdef AI_PASSIVE
int ret = 0;
char host[NI_MAXHOST] = "", serv[NI_MAXSERV] = "";
int flags = 0;
if (numeric)
flags |= NI_NUMERICHOST | NI_NUMERICSERV;
if ((ret = getnameinfo(BIO_ADDR_sockaddr(ap),
BIO_ADDR_sockaddr_size(ap),
host, sizeof(host), serv, sizeof(serv),
flags)) != 0) {
# ifdef EAI_SYSTEM
if (ret == EAI_SYSTEM) {
SYSerr(SYS_F_GETNAMEINFO, get_last_socket_error());
BIOerr(BIO_F_ADDR_STRINGS, ERR_R_SYS_LIB);
} else
# endif
{
BIOerr(BIO_F_ADDR_STRINGS, ERR_R_SYS_LIB);
ERR_add_error_data(1, gai_strerror(ret));
}
return 0;
}
if (serv[0] == '\0') {
BIO_snprintf(serv, sizeof(serv), "%d",
ntohs(BIO_ADDR_rawport(ap)));
}
if (hostname != NULL)
*hostname = OPENSSL_strdup(host);
if (service != NULL)
*service = OPENSSL_strdup(serv);
} else {
#endif
if (hostname != NULL)
*hostname = OPENSSL_strdup(inet_ntoa(ap->s_in.sin_addr));
if (service != NULL) {
char serv[6];
BIO_snprintf(serv, sizeof(serv), "%d", ntohs(ap->s_in.sin_port));
*service = OPENSSL_strdup(serv);
}
}
if ((hostname != NULL && *hostname == NULL)
|| (service != NULL && *service == NULL)) {
if (hostname != NULL) {
OPENSSL_free(*hostname);
*hostname = NULL;
}
if (service != NULL) {
OPENSSL_free(*service);
*service = NULL;
}
BIOerr(BIO_F_ADDR_STRINGS, ERR_R_MALLOC_FAILURE);
return 0;
}
return 1;
}
char *BIO_ADDR_hostname_string(const BIO_ADDR *ap, int numeric)
{
char *hostname = NULL;
if (addr_strings(ap, numeric, &hostname, NULL))
return hostname;
return NULL;
}
char *BIO_ADDR_service_string(const BIO_ADDR *ap, int numeric)
{
char *service = NULL;
if (addr_strings(ap, numeric, NULL, &service))
return service;
return NULL;
}
char *BIO_ADDR_path_string(const BIO_ADDR *ap)
{
#ifdef AF_UNIX
if (ap->sa.sa_family == AF_UNIX)
return OPENSSL_strdup(ap->s_un.sun_path);
#endif
return NULL;
}
const struct sockaddr *BIO_ADDR_sockaddr(const BIO_ADDR *ap)
{
return &(ap->sa);
}
struct sockaddr *BIO_ADDR_sockaddr_noconst(BIO_ADDR *ap)
{
return &(ap->sa);
}
socklen_t BIO_ADDR_sockaddr_size(const BIO_ADDR *ap)
{
if (ap->sa.sa_family == AF_INET)
return sizeof(ap->s_in);
#ifdef AF_INET6
if (ap->sa.sa_family == AF_INET6)
return sizeof(ap->s_in6);
#endif
#ifdef AF_UNIX
if (ap->sa.sa_family == AF_UNIX)
return sizeof(ap->s_un);
#endif
return sizeof(*ap);
}
const BIO_ADDRINFO *BIO_ADDRINFO_next(const BIO_ADDRINFO *bai)
{
if (bai != NULL)
return bai->bai_next;
return NULL;
}
int BIO_ADDRINFO_family(const BIO_ADDRINFO *bai)
{
if (bai != NULL)
return bai->bai_family;
return 0;
}
int BIO_ADDRINFO_socktype(const BIO_ADDRINFO *bai)
{
if (bai != NULL)
return bai->bai_socktype;
return 0;
}
int BIO_ADDRINFO_protocol(const BIO_ADDRINFO *bai)
{
if (bai != NULL) {
if (bai->bai_protocol != 0)
return bai->bai_protocol;
#ifdef AF_UNIX
if (bai->bai_family == AF_UNIX)
return 0;
#endif
switch (bai->bai_socktype) {
case SOCK_STREAM:
return IPPROTO_TCP;
case SOCK_DGRAM:
return IPPROTO_UDP;
default:
break;
}
}
return 0;
}
socklen_t BIO_ADDRINFO_sockaddr_size(const BIO_ADDRINFO *bai)
{
if (bai != NULL)
return bai->bai_addrlen;
return 0;
}
const struct sockaddr *BIO_ADDRINFO_sockaddr(const BIO_ADDRINFO *bai)
{
if (bai != NULL)
return bai->bai_addr;
return NULL;
}
const BIO_ADDR *BIO_ADDRINFO_address(const BIO_ADDRINFO *bai)
{
if (bai != NULL)
return (BIO_ADDR *)bai->bai_addr;
return NULL;
}
void BIO_ADDRINFO_free(BIO_ADDRINFO *bai)
{
if (bai == NULL)
return;
#ifdef AI_PASSIVE
# ifdef AF_UNIX
# define _cond bai->bai_family != AF_UNIX
# else
# define _cond 1
# endif
if (_cond) {
freeaddrinfo(bai);
return;
}
#endif
while (bai != NULL) {
BIO_ADDRINFO *next = bai->bai_next;
OPENSSL_free(bai->bai_addr);
OPENSSL_free(bai);
bai = next;
}
}
int BIO_parse_hostserv(const char *hostserv, char **host, char **service,
enum BIO_hostserv_priorities hostserv_prio)
{
const char *h = NULL; size_t hl = 0;
const char *p = NULL; size_t pl = 0;
if (*hostserv == '[') {
if ((p = strchr(hostserv, ']')) == NULL)
goto spec_err;
h = hostserv + 1;
hl = p - h;
p++;
if (*p == '\0')
p = NULL;
else if (*p != ':')
goto spec_err;
else {
p++;
pl = strlen(p);
}
} else {
const char *p2 = strrchr(hostserv, ':');
p = strchr(hostserv, ':');
if (p != p2)
goto amb_err;
if (p != NULL) {
h = hostserv;
hl = p - h;
p++;
pl = strlen(p);
} else if (hostserv_prio == BIO_PARSE_PRIO_HOST) {
h = hostserv;
hl = strlen(h);
} else {
p = hostserv;
pl = strlen(p);
}
}
if (p != NULL && strchr(p, ':'))
goto spec_err;
if (h != NULL && host != NULL) {
if (hl == 0
|| (hl == 1 && h[0] == '*')) {
*host = NULL;
} else {
*host = OPENSSL_strndup(h, hl);
if (*host == NULL)
goto memerr;
}
}
if (p != NULL && service != NULL) {
if (pl == 0
|| (pl == 1 && p[0] == '*')) {
*service = NULL;
} else {
*service = OPENSSL_strndup(p, pl);
if (*service == NULL)
goto memerr;
}
}
return 1;
amb_err:
BIOerr(BIO_F_BIO_PARSE_HOSTSERV, BIO_R_AMBIGUOUS_HOST_OR_SERVICE);
return 0;
spec_err:
BIOerr(BIO_F_BIO_PARSE_HOSTSERV, BIO_R_MALFORMED_HOST_OR_SERVICE);
return 0;
memerr:
BIOerr(BIO_F_BIO_PARSE_HOSTSERV, ERR_R_MALLOC_FAILURE);
return 0;
}
static int addrinfo_wrap(int family, int socktype,
const void *where, size_t wherelen,
unsigned short port,
BIO_ADDRINFO **bai)
{
OPENSSL_assert(bai != NULL);
*bai = OPENSSL_zalloc(sizeof(**bai));
if (*bai == NULL)
return 0;
(*bai)->bai_family = family;
(*bai)->bai_socktype = socktype;
if (socktype == SOCK_STREAM)
(*bai)->bai_protocol = IPPROTO_TCP;
if (socktype == SOCK_DGRAM)
(*bai)->bai_protocol = IPPROTO_UDP;
#ifdef AF_UNIX
if (family == AF_UNIX)
(*bai)->bai_protocol = 0;
#endif
{
BIO_ADDR *addr = BIO_ADDR_new();
if (addr != NULL) {
BIO_ADDR_rawmake(addr, family, where, wherelen, port);
(*bai)->bai_addr = BIO_ADDR_sockaddr_noconst(addr);
}
}
(*bai)->bai_next = NULL;
if ((*bai)->bai_addr == NULL) {
BIO_ADDRINFO_free(*bai);
*bai = NULL;
return 0;
}
return 1;
}
int BIO_lookup(const char *host, const char *service,
enum BIO_lookup_type lookup_type,
int family, int socktype, BIO_ADDRINFO **res)
{
int ret = 0;
switch(family) {
case AF_INET:
#ifdef AF_INET6
case AF_INET6:
#endif
#ifdef AF_UNIX
case AF_UNIX:
#endif
#ifdef AF_UNSPEC
case AF_UNSPEC:
#endif
break;
default:
BIOerr(BIO_F_BIO_LOOKUP, BIO_R_UNSUPPORTED_PROTOCOL_FAMILY);
return 0;
}
#ifdef AF_UNIX
if (family == AF_UNIX) {
if (addrinfo_wrap(family, socktype, host, strlen(host), 0, res))
return 1;
else
BIOerr(BIO_F_BIO_LOOKUP, ERR_R_MALLOC_FAILURE);
return 0;
}
#endif
if (BIO_sock_init() != 1)
return 0;
if (1) {
int gai_ret = 0;
#ifdef AI_PASSIVE
struct addrinfo hints;
memset(&hints, 0, sizeof hints);
hints.ai_family = family;
hints.ai_socktype = socktype;
if (lookup_type == BIO_LOOKUP_SERVER)
hints.ai_flags |= AI_PASSIVE;
switch ((gai_ret = getaddrinfo(host, service, &hints, res))) {
# ifdef EAI_SYSTEM
case EAI_SYSTEM:
SYSerr(SYS_F_GETADDRINFO, get_last_socket_error());
BIOerr(BIO_F_BIO_LOOKUP, ERR_R_SYS_LIB);
break;
# endif
case 0:
ret = 1;
break;
default:
BIOerr(BIO_F_BIO_LOOKUP, ERR_R_SYS_LIB);
ERR_add_error_data(1, gai_strerror(gai_ret));
break;
}
} else {
#endif
const struct hostent *he;
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size save
# pragma pointer_size 32
#endif
#ifdef OPENSSL_SYS_WINDOWS
static uint32_t he_fallback_address;
static const char *he_fallback_addresses[] =
{ (char *)&he_fallback_address, NULL };
#else
static in_addr_t he_fallback_address;
static const char *he_fallback_addresses[] =
{ (char *)&he_fallback_address, NULL };
#endif
static const struct hostent he_fallback =
{ NULL, NULL, AF_INET, sizeof(he_fallback_address),
(char **)&he_fallback_addresses };
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size restore
#endif
struct servent *se;
#ifdef _WIN64
struct servent se_fallback = { NULL, NULL, NULL, 0 };
#else
struct servent se_fallback = { NULL, NULL, 0, NULL };
#endif
if (!RUN_ONCE(&bio_lookup_init, do_bio_lookup_init)) {
BIOerr(BIO_F_BIO_LOOKUP, ERR_R_MALLOC_FAILURE);
ret = 0;
goto err;
}
CRYPTO_THREAD_write_lock(bio_lookup_lock);
he_fallback_address = INADDR_ANY;
if (host == NULL) {
he = &he_fallback;
switch(lookup_type) {
case BIO_LOOKUP_CLIENT:
he_fallback_address = INADDR_LOOPBACK;
break;
case BIO_LOOKUP_SERVER:
he_fallback_address = INADDR_ANY;
break;
default:
OPENSSL_assert(("We forgot to handle a lookup type!" == 0));
break;
}
} else {
he = gethostbyname(host);
if (he == NULL) {
#ifndef OPENSSL_SYS_WINDOWS
BIOerr(BIO_F_BIO_LOOKUP, ERR_R_SYS_LIB);
ERR_add_error_data(1, hstrerror(h_errno));
#else
SYSerr(SYS_F_GETHOSTBYNAME, WSAGetLastError());
#endif
ret = 0;
goto err;
}
}
if (service == NULL) {
se_fallback.s_port = 0;
se_fallback.s_proto = NULL;
se = &se_fallback;
} else {
char *endp = NULL;
long portnum = strtol(service, &endp, 10);
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size save
# pragma pointer_size 32
#endif
char *proto = NULL;
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size restore
#endif
switch (socktype) {
case SOCK_STREAM:
proto = "tcp";
break;
case SOCK_DGRAM:
proto = "udp";
break;
}
if (endp != service && *endp == '\0'
&& portnum > 0 && portnum < 65536) {
se_fallback.s_port = htons(portnum);
se_fallback.s_proto = proto;
se = &se_fallback;
} else if (endp == service) {
se = getservbyname(service, proto);
if (se == NULL) {
#ifndef OPENSSL_SYS_WINDOWS
BIOerr(BIO_F_BIO_LOOKUP, ERR_R_SYS_LIB);
ERR_add_error_data(1, hstrerror(h_errno));
#else
SYSerr(SYS_F_GETSERVBYNAME, WSAGetLastError());
#endif
goto err;
}
} else {
BIOerr(BIO_F_BIO_LOOKUP, BIO_R_MALFORMED_HOST_OR_SERVICE);
goto err;
}
}
*res = NULL;
{
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size save
# pragma pointer_size 32
#endif
char **addrlistp;
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma pointer_size restore
#endif
size_t addresses;
BIO_ADDRINFO *tmp_bai = NULL;
for(addrlistp = he->h_addr_list; *addrlistp != NULL;
addrlistp++)
;
for(addresses = addrlistp - he->h_addr_list;
addrlistp--, addresses-- > 0; ) {
if (!addrinfo_wrap(he->h_addrtype, socktype,
*addrlistp, he->h_length,
se->s_port, &tmp_bai))
goto addrinfo_malloc_err;
tmp_bai->bai_next = *res;
*res = tmp_bai;
continue;
addrinfo_malloc_err:
BIO_ADDRINFO_free(*res);
*res = NULL;
BIOerr(BIO_F_BIO_LOOKUP, ERR_R_MALLOC_FAILURE);
ret = 0;
goto err;
}
ret = 1;
}
err:
CRYPTO_THREAD_unlock(bio_lookup_lock);
}
return ret;
}
