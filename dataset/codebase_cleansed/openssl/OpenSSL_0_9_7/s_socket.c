static LONG FAR PASCAL topHookProc(HWND hwnd, UINT message, WPARAM wParam,
LPARAM lParam)
{
if (hwnd == topWnd)
{
switch(message)
{
case WM_DESTROY:
case WM_CLOSE:
SetWindowLong(topWnd,GWL_WNDPROC,(LONG)lpTopWndProc);
ssl_sock_cleanup();
break;
}
}
return CallWindowProc(lpTopWndProc,hwnd,message,wParam,lParam);
}
static BOOL CALLBACK enumproc(HWND hwnd,LPARAM lParam)
{
topWnd=hwnd;
return(FALSE);
}
static void ssl_sock_cleanup(void)
{
if (wsa_init_done)
{
wsa_init_done=0;
#ifndef OPENSSL_SYS_WINCE
WSACancelBlockingCall();
#endif
WSACleanup();
}
}
static int ssl_sock_init(void)
{
#ifdef WATT32
extern int _watt_do_exit;
_watt_do_exit = 0;
dbug_init();
if (sock_init())
return (0);
#elif defined(OPENSSL_SYS_WINDOWS)
if (!wsa_init_done)
{
int err;
#ifdef SIGINT
signal(SIGINT,(void (*)(int))ssl_sock_cleanup);
#endif
wsa_init_done=1;
memset(&wsa_state,0,sizeof(wsa_state));
if (WSAStartup(0x0101,&wsa_state)!=0)
{
err=WSAGetLastError();
BIO_printf(bio_err,"unable to start WINSOCK, error code=%d\n",err);
return(0);
}
#ifdef OPENSSL_SYS_WIN16
EnumTaskWindows(GetCurrentTask(),enumproc,0L);
lpTopWndProc=(FARPROC)GetWindowLong(topWnd,GWL_WNDPROC);
lpTopHookProc=MakeProcInstance((FARPROC)topHookProc,_hInstance);
SetWindowLong(topWnd,GWL_WNDPROC,(LONG)lpTopHookProc);
#endif
}
#endif
return(1);
}
int init_client(int *sock, char *host, int port)
{
unsigned char ip[4];
short p=0;
if (!host_ip(host,&(ip[0])))
{
return(0);
}
if (p != 0) port=p;
return(init_client_ip(sock,ip,port));
}
static int init_client_ip(int *sock, unsigned char ip[4], int port)
{
unsigned long addr;
struct sockaddr_in them;
int s,i;
if (!ssl_sock_init()) return(0);
memset((char *)&them,0,sizeof(them));
them.sin_family=AF_INET;
them.sin_port=htons((unsigned short)port);
addr=(unsigned long)
((unsigned long)ip[0]<<24L)|
((unsigned long)ip[1]<<16L)|
((unsigned long)ip[2]<< 8L)|
((unsigned long)ip[3]);
them.sin_addr.s_addr=htonl(addr);
s=socket(AF_INET,SOCK_STREAM,SOCKET_PROTOCOL);
if (s == INVALID_SOCKET) { perror("socket"); return(0); }
#ifndef OPENSSL_SYS_MPE
i=0;
i=setsockopt(s,SOL_SOCKET,SO_KEEPALIVE,(char *)&i,sizeof(i));
if (i < 0) { perror("keepalive"); return(0); }
#endif
if (connect(s,(struct sockaddr *)&them,sizeof(them)) == -1)
{ close(s); perror("connect"); return(0); }
*sock=s;
return(1);
}
int do_server(int port, int *ret, int (*cb)(), char *context)
{
int sock;
char *name;
int accept_socket;
int i;
if (!init_server(&accept_socket,port)) return(0);
if (ret != NULL)
{
*ret=accept_socket;
}
for (;;)
{
if (do_accept(accept_socket,&sock,&name) == 0)
{
SHUTDOWN(accept_socket);
return(0);
}
i=(*cb)(name,sock, context);
if (name != NULL) OPENSSL_free(name);
SHUTDOWN2(sock);
if (i < 0)
{
SHUTDOWN2(accept_socket);
return(i);
}
}
}
static int init_server_long(int *sock, int port, char *ip)
{
int ret=0;
struct sockaddr_in server;
int s= -1,i;
if (!ssl_sock_init()) return(0);
memset((char *)&server,0,sizeof(server));
server.sin_family=AF_INET;
server.sin_port=htons((unsigned short)port);
if (ip == NULL)
server.sin_addr.s_addr=INADDR_ANY;
else
#ifndef BIT_FIELD_LIMITS
memcpy(&server.sin_addr.s_addr,ip,4);
#else
memcpy(&server.sin_addr,ip,4);
#endif
s=socket(AF_INET,SOCK_STREAM,SOCKET_PROTOCOL);
if (s == INVALID_SOCKET) goto err;
#if defined SOL_SOCKET && defined SO_REUSEADDR
{
int j = 1;
setsockopt(s, SOL_SOCKET, SO_REUSEADDR,
(void *) &j, sizeof j);
}
#endif
if (bind(s,(struct sockaddr *)&server,sizeof(server)) == -1)
{
#ifndef OPENSSL_SYS_WINDOWS
perror("bind");
#endif
goto err;
}
if (listen(s,128) == -1) goto err;
i=0;
*sock=s;
ret=1;
err:
if ((ret == 0) && (s != -1))
{
SHUTDOWN(s);
}
return(ret);
}
static int init_server(int *sock, int port)
{
return(init_server_long(sock, port, NULL));
}
static int do_accept(int acc_sock, int *sock, char **host)
{
int ret,i;
struct hostent *h1,*h2;
static struct sockaddr_in from;
int len;
if (!ssl_sock_init()) return(0);
#ifndef OPENSSL_SYS_WINDOWS
redoit:
#endif
memset((char *)&from,0,sizeof(from));
len=sizeof(from);
ret=accept(acc_sock,(struct sockaddr *)&from,(void *)&len);
if (ret == INVALID_SOCKET)
{
#ifdef OPENSSL_SYS_WINDOWS
i=WSAGetLastError();
BIO_printf(bio_err,"accept error %d\n",i);
#else
if (errno == EINTR)
{
goto redoit;
}
fprintf(stderr,"errno=%d ",errno);
perror("accept");
#endif
return(0);
}
if (host == NULL) goto end;
#ifndef BIT_FIELD_LIMITS
h1=gethostbyaddr((char *)&from.sin_addr.s_addr,
sizeof(from.sin_addr.s_addr),AF_INET);
#else
h1=gethostbyaddr((char *)&from.sin_addr,
sizeof(struct in_addr),AF_INET);
#endif
if (h1 == NULL)
{
BIO_printf(bio_err,"bad gethostbyaddr\n");
*host=NULL;
}
else
{
if ((*host=(char *)OPENSSL_malloc(strlen(h1->h_name)+1)) == NULL)
{
perror("OPENSSL_malloc");
return(0);
}
strcpy(*host,h1->h_name);
h2=GetHostByName(*host);
if (h2 == NULL)
{
BIO_printf(bio_err,"gethostbyname failure\n");
return(0);
}
i=0;
if (h2->h_addrtype != AF_INET)
{
BIO_printf(bio_err,"gethostbyname addr is not AF_INET\n");
return(0);
}
}
end:
*sock=ret;
return(1);
}
int extract_host_port(char *str, char **host_ptr, unsigned char *ip,
short *port_ptr)
{
char *h,*p;
h=str;
p=strchr(str,':');
if (p == NULL)
{
BIO_printf(bio_err,"no port defined\n");
return(0);
}
*(p++)='\0';
if ((ip != NULL) && !host_ip(str,ip))
goto err;
if (host_ptr != NULL) *host_ptr=h;
if (!extract_port(p,port_ptr))
goto err;
return(1);
err:
return(0);
}
static int host_ip(char *str, unsigned char ip[4])
{
unsigned int in[4];
int i;
if (sscanf(str,"%u.%u.%u.%u",&(in[0]),&(in[1]),&(in[2]),&(in[3])) == 4)
{
for (i=0; i<4; i++)
if (in[i] > 255)
{
BIO_printf(bio_err,"invalid IP address\n");
goto err;
}
ip[0]=in[0];
ip[1]=in[1];
ip[2]=in[2];
ip[3]=in[3];
}
else
{
struct hostent *he;
if (!ssl_sock_init()) return(0);
he=GetHostByName(str);
if (he == NULL)
{
BIO_printf(bio_err,"gethostbyname failure\n");
goto err;
}
if ((short)he->h_addrtype != AF_INET)
{
BIO_printf(bio_err,"gethostbyname addr is not AF_INET\n");
return(0);
}
ip[0]=he->h_addr_list[0][0];
ip[1]=he->h_addr_list[0][1];
ip[2]=he->h_addr_list[0][2];
ip[3]=he->h_addr_list[0][3];
}
return(1);
err:
return(0);
}
int extract_port(char *str, short *port_ptr)
{
int i;
struct servent *s;
i=atoi(str);
if (i != 0)
*port_ptr=(unsigned short)i;
else
{
s=getservbyname(str,"tcp");
if (s == NULL)
{
BIO_printf(bio_err,"getservbyname failure for %s\n",str);
return(0);
}
*port_ptr=ntohs((unsigned short)s->s_port);
}
return(1);
}
static struct hostent *GetHostByName(char *name)
{
struct hostent *ret;
int i,lowi=0;
unsigned long low= (unsigned long)-1;
for (i=0; i<GHBN_NUM; i++)
{
if (low > ghbn_cache[i].order)
{
low=ghbn_cache[i].order;
lowi=i;
}
if (ghbn_cache[i].order > 0)
{
if (strncmp(name,ghbn_cache[i].name,128) == 0)
break;
}
}
if (i == GHBN_NUM)
{
ghbn_miss++;
ret=gethostbyname(name);
if (ret == NULL) return(NULL);
if(strlen(name) < sizeof ghbn_cache[0].name)
{
strcpy(ghbn_cache[lowi].name,name);
memcpy((char *)&(ghbn_cache[lowi].ent),ret,sizeof(struct hostent));
ghbn_cache[lowi].order=ghbn_miss+ghbn_hits;
}
return(ret);
}
else
{
ghbn_hits++;
ret= &(ghbn_cache[i].ent);
ghbn_cache[i].order=ghbn_miss+ghbn_hits;
return(ret);
}
}
