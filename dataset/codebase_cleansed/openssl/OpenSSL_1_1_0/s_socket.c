int init_client(int *sock, const char *host, const char *port,
int family, int type)
{
BIO_ADDRINFO *res = NULL;
const BIO_ADDRINFO *ai = NULL;
int ret;
if (!BIO_sock_init())
return 0;
ret = BIO_lookup(host, port, BIO_LOOKUP_CLIENT, family, type, &res);
if (ret == 0) {
ERR_print_errors(bio_err);
return 0;
}
ret = 0;
for (ai = res; ai != NULL; ai = BIO_ADDRINFO_next(ai)) {
OPENSSL_assert((family == AF_UNSPEC || family == BIO_ADDRINFO_family(res))
&& (type == 0 || type == BIO_ADDRINFO_socktype(res)));
*sock = BIO_socket(BIO_ADDRINFO_family(ai), BIO_ADDRINFO_socktype(ai),
BIO_ADDRINFO_protocol(res), 0);
if (*sock == INVALID_SOCKET) {
continue;
}
if (!BIO_connect(*sock, BIO_ADDRINFO_address(ai), 0)) {
BIO_closesocket(*sock);
*sock = INVALID_SOCKET;
continue;
}
break;
}
if (*sock == INVALID_SOCKET) {
ERR_print_errors(bio_err);
} else {
ERR_clear_error();
ret = 1;
}
BIO_ADDRINFO_free(res);
return ret;
}
int do_server(int *accept_sock, const char *host, const char *port,
int family, int type, do_server_cb cb,
unsigned char *context, int naccept)
{
int asock = 0;
int sock;
int i;
BIO_ADDRINFO *res = NULL;
int ret = 0;
if (!BIO_sock_init())
return 0;
if (!BIO_lookup(host, port, BIO_LOOKUP_SERVER, family, type, &res)) {
ERR_print_errors(bio_err);
return 0;
}
OPENSSL_assert((family == AF_UNSPEC || family == BIO_ADDRINFO_family(res))
&& (type == 0 || type == BIO_ADDRINFO_socktype(res)));
asock = BIO_socket(BIO_ADDRINFO_family(res), BIO_ADDRINFO_socktype(res),
BIO_ADDRINFO_protocol(res), 0);
if (asock == INVALID_SOCKET
|| !BIO_listen(asock, BIO_ADDRINFO_address(res), BIO_SOCK_REUSEADDR)) {
BIO_ADDRINFO_free(res);
ERR_print_errors(bio_err);
if (asock != INVALID_SOCKET)
BIO_closesocket(asock);
goto end;
}
BIO_ADDRINFO_free(res);
res = NULL;
if (accept_sock != NULL)
*accept_sock = asock;
for (;;) {
if (type == SOCK_STREAM) {
do {
sock = BIO_accept_ex(asock, NULL, 0);
} while (sock < 0 && BIO_sock_should_retry(ret));
if (sock < 0) {
ERR_print_errors(bio_err);
BIO_closesocket(asock);
break;
}
i = (*cb)(sock, type, context);
BIO_closesocket(sock);
} else {
i = (*cb)(asock, type, context);
}
if (naccept != -1)
naccept--;
if (i < 0 || naccept == 0) {
BIO_closesocket(asock);
ret = i;
break;
}
}
end:
# ifdef AF_UNIX
if (family == AF_UNIX)
unlink(host);
# endif
return ret;
}
