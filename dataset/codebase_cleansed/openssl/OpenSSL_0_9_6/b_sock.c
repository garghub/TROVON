int BIO_get_host_ip(const char *str, unsigned char *ip)
{
int i;
int err = 1;
int locked = 0;
struct hostent *he;
i=get_ip(str,ip);
if (i < 0)
{
BIOerr(BIO_F_BIO_GET_HOST_IP,BIO_R_INVALID_IP_ADDRESS);
goto err;
}
if (!BIO_sock_init())
return(0);
if (i > 0) return(1);
CRYPTO_w_lock(CRYPTO_LOCK_GETHOSTBYNAME);
locked = 1;
he=BIO_gethostbyname(str);
if (he == NULL)
{
BIOerr(BIO_F_BIO_GET_HOST_IP,BIO_R_BAD_HOSTNAME_LOOKUP);
goto err;
}
if ((short)he->h_addrtype != AF_INET)
{
BIOerr(BIO_F_BIO_GET_HOST_IP,BIO_R_GETHOSTBYNAME_ADDR_IS_NOT_AF_INET);
goto err;
}
for (i=0; i<4; i++)
ip[i]=he->h_addr_list[0][i];
err = 0;
err:
if (locked)
CRYPTO_w_unlock(CRYPTO_LOCK_GETHOSTBYNAME);
if (err)
{
ERR_add_error_data(2,"host=",str);
return 0;
}
else
return 1;
}
int BIO_get_port(const char *str, unsigned short *port_ptr)
{
int i;
struct servent *s;
if (str == NULL)
{
BIOerr(BIO_F_BIO_GET_PORT,BIO_R_NO_PORT_DEFINED);
return(0);
}
i=atoi(str);
if (i != 0)
*port_ptr=(unsigned short)i;
else
{
CRYPTO_w_lock(CRYPTO_LOCK_GETSERVBYNAME);
s=getservbyname(
#ifndef CONST_STRICT
(char *)
#endif
str,"tcp");
if(s != NULL)
*port_ptr=ntohs((unsigned short)s->s_port);
CRYPTO_w_unlock(CRYPTO_LOCK_GETSERVBYNAME);
if(s == NULL)
{
if (strcmp(str,"http") == 0)
*port_ptr=80;
else if (strcmp(str,"telnet") == 0)
*port_ptr=23;
else if (strcmp(str,"socks") == 0)
*port_ptr=1080;
else if (strcmp(str,"https") == 0)
*port_ptr=443;
else if (strcmp(str,"ssl") == 0)
*port_ptr=443;
else if (strcmp(str,"ftp") == 0)
*port_ptr=21;
else if (strcmp(str,"gopher") == 0)
*port_ptr=70;
#if 0
else if (strcmp(str,"wais") == 0)
*port_ptr=21;
#endif
else
{
SYSerr(SYS_F_GETSERVBYNAME,get_last_socket_error());
ERR_add_error_data(3,"service='",str,"'");
return(0);
}
}
}
return(1);
}
int BIO_sock_error(int sock)
{
int j,i;
int size;
size=sizeof(int);
i=getsockopt(sock,SOL_SOCKET,SO_ERROR,(void *)&j,(void *)&size);
if (i < 0)
return(1);
else
return(j);
}
long BIO_ghbn_ctrl(int cmd, int iarg, char *parg)
{
int i;
char **p;
switch (cmd)
{
case BIO_GHBN_CTRL_HITS:
return(BIO_ghbn_hits);
case BIO_GHBN_CTRL_MISSES:
return(BIO_ghbn_miss);
case BIO_GHBN_CTRL_CACHE_SIZE:
return(GHBN_NUM);
case BIO_GHBN_CTRL_GET_ENTRY:
if ((iarg >= 0) && (iarg <GHBN_NUM) &&
(ghbn_cache[iarg].order > 0))
{
p=(char **)parg;
if (p == NULL) return(0);
*p=ghbn_cache[iarg].name;
ghbn_cache[iarg].name[128]='\0';
return(1);
}
return(0);
case BIO_GHBN_CTRL_FLUSH:
for (i=0; i<GHBN_NUM; i++)
ghbn_cache[i].order=0;
break;
default:
return(0);
}
return(1);
}
static struct hostent *ghbn_dup(struct hostent *a)
{
struct hostent *ret;
int i,j;
MemCheck_off();
ret=(struct hostent *)OPENSSL_malloc(sizeof(struct hostent));
if (ret == NULL) return(NULL);
memset(ret,0,sizeof(struct hostent));
for (i=0; a->h_aliases[i] != NULL; i++)
;
i++;
ret->h_aliases = (char **)OPENSSL_malloc(i*sizeof(char *));
if (ret->h_aliases == NULL)
goto err;
memset(ret->h_aliases, 0, i*sizeof(char *));
for (i=0; a->h_addr_list[i] != NULL; i++)
;
i++;
ret->h_addr_list=(char **)OPENSSL_malloc(i*sizeof(char *));
if (ret->h_addr_list == NULL)
goto err;
memset(ret->h_addr_list, 0, i*sizeof(char *));
j=strlen(a->h_name)+1;
if ((ret->h_name=OPENSSL_malloc(j)) == NULL) goto err;
memcpy((char *)ret->h_name,a->h_name,j);
for (i=0; a->h_aliases[i] != NULL; i++)
{
j=strlen(a->h_aliases[i])+1;
if ((ret->h_aliases[i]=OPENSSL_malloc(j)) == NULL) goto err;
memcpy(ret->h_aliases[i],a->h_aliases[i],j);
}
ret->h_length=a->h_length;
ret->h_addrtype=a->h_addrtype;
for (i=0; a->h_addr_list[i] != NULL; i++)
{
if ((ret->h_addr_list[i]=OPENSSL_malloc(a->h_length)) == NULL)
goto err;
memcpy(ret->h_addr_list[i],a->h_addr_list[i],a->h_length);
}
if (0)
{
err:
if (ret != NULL)
ghbn_free(ret);
ret=NULL;
}
MemCheck_on();
return(ret);
}
static void ghbn_free(struct hostent *a)
{
int i;
if(a == NULL)
return;
if (a->h_aliases != NULL)
{
for (i=0; a->h_aliases[i] != NULL; i++)
OPENSSL_free(a->h_aliases[i]);
OPENSSL_free(a->h_aliases);
}
if (a->h_addr_list != NULL)
{
for (i=0; a->h_addr_list[i] != NULL; i++)
OPENSSL_free(a->h_addr_list[i]);
OPENSSL_free(a->h_addr_list);
}
if (a->h_name != NULL) OPENSSL_free(a->h_name);
OPENSSL_free(a);
}
struct hostent *BIO_gethostbyname(const char *name)
{
struct hostent *ret;
int i,lowi=0,j;
unsigned long low= (unsigned long)-1;
#if 0
CRYPTO_w_lock(CRYPTO_LOCK_GETHOSTBYNAME);
#endif
j=strlen(name);
if (j < 128)
{
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
}
else
i=GHBN_NUM;
if (i == GHBN_NUM)
{
BIO_ghbn_miss++;
ret=gethostbyname(
#ifndef CONST_STRICT
(char *)
#endif
name);
if (ret == NULL)
goto end;
if (j > 128)
{
#if 0
ret = NULL;
#endif
goto end;
}
if (ghbn_cache[lowi].ent != NULL)
ghbn_free(ghbn_cache[lowi].ent);
ghbn_cache[lowi].name[0] = '\0';
if((ret=ghbn_cache[lowi].ent=ghbn_dup(ret)) == NULL)
{
BIOerr(BIO_F_BIO_GETHOSTBYNAME,ERR_R_MALLOC_FAILURE);
goto end;
}
strncpy(ghbn_cache[lowi].name,name,128);
ghbn_cache[lowi].order=BIO_ghbn_miss+BIO_ghbn_hits;
}
else
{
BIO_ghbn_hits++;
ret= ghbn_cache[i].ent;
ghbn_cache[i].order=BIO_ghbn_miss+BIO_ghbn_hits;
}
end:
#if 0
CRYPTO_w_unlock(CRYPTO_LOCK_GETHOSTBYNAME);
#endif
return(ret);
}
int BIO_sock_init(void)
{
#ifdef WINDOWS
static struct WSAData wsa_state;
if (!wsa_init_done)
{
int err;
#ifdef SIGINT
signal(SIGINT,(void (*)(int))BIO_sock_cleanup);
#endif
wsa_init_done=1;
memset(&wsa_state,0,sizeof(wsa_state));
if (WSAStartup(0x0101,&wsa_state)!=0)
{
err=WSAGetLastError();
SYSerr(SYS_F_WSASTARTUP,err);
BIOerr(BIO_F_BIO_SOCK_INIT,BIO_R_WSASTARTUP);
return(-1);
}
}
#endif
return(1);
}
void BIO_sock_cleanup(void)
{
#ifdef WINDOWS
if (wsa_init_done)
{
wsa_init_done=0;
WSACancelBlockingCall();
WSACleanup();
}
#endif
}
int BIO_socket_ioctl(int fd, long type, unsigned long *arg)
{
int i;
i=ioctlsocket(fd,type,arg);
if (i < 0)
SYSerr(SYS_F_IOCTLSOCKET,get_last_socket_error());
return(i);
}
static int get_ip(const char *str, unsigned char ip[4])
{
unsigned int tmp[4];
int num=0,c,ok=0;
tmp[0]=tmp[1]=tmp[2]=tmp[3]=0;
for (;;)
{
c= *(str++);
if ((c >= '0') && (c <= '9'))
{
ok=1;
tmp[num]=tmp[num]*10+c-'0';
if (tmp[num] > 255) return(-1);
}
else if (c == '.')
{
if (!ok) return(-1);
if (num == 3) break;
num++;
ok=0;
}
else if ((num == 3) && ok)
break;
else
return(0);
}
ip[0]=tmp[0];
ip[1]=tmp[1];
ip[2]=tmp[2];
ip[3]=tmp[3];
return(1);
}
int BIO_get_accept_socket(char *host, int bind_mode)
{
int ret=0;
struct sockaddr_in server,client;
int s= -1,cs;
unsigned char ip[4];
unsigned short port;
char *str,*e;
const char *h,*p;
unsigned long l;
int err_num;
if (!BIO_sock_init()) return(INVALID_SOCKET);
if ((str=BUF_strdup(host)) == NULL) return(INVALID_SOCKET);
h=p=NULL;
h=str;
for (e=str; *e; e++)
{
if (*e == ':')
{
p= &(e[1]);
*e='\0';
}
else if (*e == '/')
{
*e='\0';
break;
}
}
if (p == NULL)
{
p=h;
h="*";
}
if (!BIO_get_port(p,&port)) return(INVALID_SOCKET);
memset((char *)&server,0,sizeof(server));
server.sin_family=AF_INET;
server.sin_port=htons(port);
if (strcmp(h,"*") == 0)
server.sin_addr.s_addr=INADDR_ANY;
else
{
if (!BIO_get_host_ip(h,&(ip[0]))) return(INVALID_SOCKET);
l=(unsigned long)
((unsigned long)ip[0]<<24L)|
((unsigned long)ip[1]<<16L)|
((unsigned long)ip[2]<< 8L)|
((unsigned long)ip[3]);
server.sin_addr.s_addr=htonl(l);
}
again:
s=socket(AF_INET,SOCK_STREAM,SOCKET_PROTOCOL);
if (s == INVALID_SOCKET)
{
SYSerr(SYS_F_SOCKET,get_last_socket_error());
ERR_add_error_data(3,"port='",host,"'");
BIOerr(BIO_F_BIO_GET_ACCEPT_SOCKET,BIO_R_UNABLE_TO_CREATE_SOCKET);
goto err;
}
#ifdef SO_REUSEADDR
if (bind_mode == BIO_BIND_REUSEADDR)
{
int i=1;
ret=setsockopt(s,SOL_SOCKET,SO_REUSEADDR,(char *)&i,sizeof(i));
bind_mode=BIO_BIND_NORMAL;
}
#endif
if (bind(s,(struct sockaddr *)&server,sizeof(server)) == -1)
{
#ifdef SO_REUSEADDR
err_num=get_last_socket_error();
if ((bind_mode == BIO_BIND_REUSEADDR_IF_UNUSED) &&
(err_num == EADDRINUSE))
{
memcpy((char *)&client,(char *)&server,sizeof(server));
if (strcmp(h,"*") == 0)
client.sin_addr.s_addr=htonl(0x7F000001);
cs=socket(AF_INET,SOCK_STREAM,SOCKET_PROTOCOL);
if (cs != INVALID_SOCKET)
{
int ii;
ii=connect(cs,(struct sockaddr *)&client,
sizeof(client));
closesocket(cs);
if (ii == INVALID_SOCKET)
{
bind_mode=BIO_BIND_REUSEADDR;
closesocket(s);
goto again;
}
}
}
#endif
SYSerr(SYS_F_BIND,err_num);
ERR_add_error_data(3,"port='",host,"'");
BIOerr(BIO_F_BIO_GET_ACCEPT_SOCKET,BIO_R_UNABLE_TO_BIND_SOCKET);
goto err;
}
if (listen(s,MAX_LISTEN) == -1)
{
SYSerr(SYS_F_BIND,get_last_socket_error());
ERR_add_error_data(3,"port='",host,"'");
BIOerr(BIO_F_BIO_GET_ACCEPT_SOCKET,BIO_R_UNABLE_TO_LISTEN_SOCKET);
goto err;
}
ret=1;
err:
if (str != NULL) OPENSSL_free(str);
if ((ret == 0) && (s != INVALID_SOCKET))
{
closesocket(s);
s= INVALID_SOCKET;
}
return(s);
}
int BIO_accept(int sock, char **addr)
{
int ret=INVALID_SOCKET;
static struct sockaddr_in from;
unsigned long l;
unsigned short port;
int len;
char *p;
memset((char *)&from,0,sizeof(from));
len=sizeof(from);
ret=accept(sock,(struct sockaddr *)&from,(void *)&len);
if (ret == INVALID_SOCKET)
{
SYSerr(SYS_F_ACCEPT,get_last_socket_error());
BIOerr(BIO_F_BIO_ACCEPT,BIO_R_ACCEPT_ERROR);
goto end;
}
if (addr == NULL) goto end;
l=ntohl(from.sin_addr.s_addr);
port=ntohs(from.sin_port);
if (*addr == NULL)
{
if ((p=OPENSSL_malloc(24)) == NULL)
{
BIOerr(BIO_F_BIO_ACCEPT,ERR_R_MALLOC_FAILURE);
goto end;
}
*addr=p;
}
sprintf(*addr,"%d.%d.%d.%d:%d",
(unsigned char)(l>>24L)&0xff,
(unsigned char)(l>>16L)&0xff,
(unsigned char)(l>> 8L)&0xff,
(unsigned char)(l )&0xff,
port);
end:
return(ret);
}
int BIO_set_tcp_ndelay(int s, int on)
{
int ret=0;
#if defined(TCP_NODELAY) && (defined(IPPROTO_TCP) || defined(SOL_TCP))
int opt;
#ifdef SOL_TCP
opt=SOL_TCP;
#else
#ifdef IPPROTO_TCP
opt=IPPROTO_TCP;
#endif
#endif
ret=setsockopt(s,opt,TCP_NODELAY,(char *)&on,sizeof(on));
#endif
return(ret == 0);
}
int BIO_socket_nbio(int s, int mode)
{
int ret= -1;
unsigned long l;
l=mode;
#ifdef FIONBIO
ret=BIO_socket_ioctl(s,FIONBIO,&l);
#endif
return(ret == 0);
}
