int BIO_socket(int domain, int socktype, int protocol, int options)
{
int sock = -1;
if (BIO_sock_init() != 1)
return INVALID_SOCKET;
sock = socket(domain, socktype, protocol);
if (sock == -1) {
SYSerr(SYS_F_SOCKET, get_last_socket_error());
BIOerr(BIO_F_BIO_SOCKET, BIO_R_UNABLE_TO_CREATE_SOCKET);
return INVALID_SOCKET;
}
return sock;
}
int BIO_connect(int sock, const BIO_ADDR *addr, int options)
{
int on = 1;
if (sock == -1) {
BIOerr(BIO_F_BIO_CONNECT, BIO_R_INVALID_SOCKET);
return 0;
}
if (!BIO_socket_nbio(sock, (options & BIO_SOCK_NONBLOCK) != 0))
return 0;
if (options & BIO_SOCK_KEEPALIVE) {
if (setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof(on)) != 0) {
SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
BIOerr(BIO_F_BIO_CONNECT, BIO_R_UNABLE_TO_KEEPALIVE);
return 0;
}
}
if (options & BIO_SOCK_NODELAY) {
if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &on, sizeof(on)) != 0) {
SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
BIOerr(BIO_F_BIO_CONNECT, BIO_R_UNABLE_TO_NODELAY);
return 0;
}
}
if (connect(sock, BIO_ADDR_sockaddr(addr),
BIO_ADDR_sockaddr_size(addr)) == -1) {
if (!BIO_sock_should_retry(-1)) {
SYSerr(SYS_F_CONNECT, get_last_socket_error());
BIOerr(BIO_F_BIO_CONNECT, BIO_R_CONNECT_ERROR);
}
return 0;
}
return 1;
}
int BIO_listen(int sock, const BIO_ADDR *addr, int options)
{
int on = 1;
int socktype;
socklen_t socktype_len = sizeof(socktype);
if (sock == -1) {
BIOerr(BIO_F_BIO_LISTEN, BIO_R_INVALID_SOCKET);
return 0;
}
if (getsockopt(sock, SOL_SOCKET, SO_TYPE, &socktype, &socktype_len) != 0
|| socktype_len != sizeof(socktype)) {
SYSerr(SYS_F_GETSOCKOPT, get_last_socket_error());
BIOerr(BIO_F_BIO_LISTEN, BIO_R_GETTING_SOCKTYPE);
return 0;
}
if (!BIO_socket_nbio(sock, (options & BIO_SOCK_NONBLOCK) != 0))
return 0;
# ifndef OPENSSL_SYS_WINDOWS
if (options & BIO_SOCK_REUSEADDR) {
if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) != 0) {
SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
BIOerr(BIO_F_BIO_LISTEN, BIO_R_UNABLE_TO_REUSEADDR);
return 0;
}
}
# endif
if (options & BIO_SOCK_KEEPALIVE) {
if (setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof(on)) != 0) {
SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
BIOerr(BIO_F_BIO_LISTEN, BIO_R_UNABLE_TO_KEEPALIVE);
return 0;
}
}
if (options & BIO_SOCK_NODELAY) {
if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &on, sizeof(on)) != 0) {
SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
BIOerr(BIO_F_BIO_LISTEN, BIO_R_UNABLE_TO_NODELAY);
return 0;
}
}
# ifdef IPV6_V6ONLY
if ((options & BIO_SOCK_V6_ONLY) && BIO_ADDR_family(addr) == AF_INET6) {
if (setsockopt(sock, IPPROTO_IPV6, IPV6_V6ONLY, &on, sizeof(on)) != 0) {
SYSerr(SYS_F_SETSOCKOPT, get_last_socket_error());
BIOerr(BIO_F_BIO_LISTEN, BIO_R_LISTEN_V6_ONLY);
return 0;
}
}
# endif
if (bind(sock, BIO_ADDR_sockaddr(addr), BIO_ADDR_sockaddr_size(addr)) != 0) {
SYSerr(SYS_F_BIND, get_last_socket_error());
BIOerr(BIO_F_BIO_LISTEN, BIO_R_UNABLE_TO_BIND_SOCKET);
return 0;
}
if (socktype != SOCK_DGRAM && listen(sock, MAX_LISTEN) == -1) {
SYSerr(SYS_F_LISTEN, get_last_socket_error());
BIOerr(BIO_F_BIO_LISTEN, BIO_R_UNABLE_TO_LISTEN_SOCKET);
return 0;
}
return 1;
}
int BIO_accept_ex(int accept_sock, BIO_ADDR *addr_, int options)
{
socklen_t len;
int accepted_sock;
BIO_ADDR locaddr;
BIO_ADDR *addr = addr_ == NULL ? &locaddr : addr_;
len = sizeof(*addr);
accepted_sock = accept(accept_sock,
BIO_ADDR_sockaddr_noconst(addr), &len);
if (accepted_sock == -1) {
if (!BIO_sock_should_retry(accepted_sock)) {
SYSerr(SYS_F_ACCEPT, get_last_socket_error());
BIOerr(BIO_F_BIO_ACCEPT_EX, BIO_R_ACCEPT_ERROR);
}
return INVALID_SOCKET;
}
if (!BIO_socket_nbio(accepted_sock, (options & BIO_SOCK_NONBLOCK) != 0)) {
closesocket(accepted_sock);
return INVALID_SOCKET;
}
return accepted_sock;
}
int BIO_closesocket(int sock)
{
if (closesocket(sock) < 0)
return 0;
return 1;
}
