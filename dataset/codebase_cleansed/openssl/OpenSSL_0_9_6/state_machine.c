void SSLStateMachine_print_error(SSLStateMachine *pMachine,const char *szErr)
{
unsigned long l;
fprintf(stderr,"%s\n",szErr);
while((l=ERR_get_error()))
{
char buf[1024];
ERR_error_string_n(l,buf,sizeof buf);
fprintf(stderr,"Error %lx: %s\n",l,buf);
}
}
SSLStateMachine *SSLStateMachine_new(const char *szCertificateFile,
const char *szKeyFile)
{
SSLStateMachine *pMachine=malloc(sizeof *pMachine);
int n;
die_unless(pMachine);
pMachine->pCtx=SSL_CTX_new(SSLv23_server_method());
die_unless(pMachine->pCtx);
n=SSL_CTX_use_certificate_file(pMachine->pCtx,szCertificateFile,
SSL_FILETYPE_PEM);
die_unless(n > 0);
n=SSL_CTX_use_PrivateKey_file(pMachine->pCtx,szKeyFile,SSL_FILETYPE_PEM);
die_unless(n > 0);
pMachine->pSSL=SSL_new(pMachine->pCtx);
die_unless(pMachine->pSSL);
pMachine->pbioRead=BIO_new(BIO_s_mem());
pMachine->pbioWrite=BIO_new(BIO_s_mem());
SSL_set_bio(pMachine->pSSL,pMachine->pbioRead,pMachine->pbioWrite);
SSL_set_accept_state(pMachine->pSSL);
return pMachine;
}
void SSLStateMachine_read_inject(SSLStateMachine *pMachine,
const unsigned char *aucBuf,int nBuf)
{
int n=BIO_write(pMachine->pbioRead,aucBuf,nBuf);
assert(n == nBuf);
fprintf(stderr,"%d bytes of encrypted data fed to state machine\n",n);
}
int SSLStateMachine_read_extract(SSLStateMachine *pMachine,
unsigned char *aucBuf,int nBuf)
{
int n;
if(!SSL_is_init_finished(pMachine->pSSL))
{
fprintf(stderr,"Doing SSL_accept\n");
n=SSL_accept(pMachine->pSSL);
if(n == 0)
fprintf(stderr,"SSL_accept returned zero\n");
if(n < 0)
{
int err;
if((err=SSL_get_error(pMachine->pSSL,n)) == SSL_ERROR_WANT_READ)
{
fprintf(stderr,"SSL_accept wants more data\n");
return 0;
}
SSLStateMachine_print_error(pMachine,"SSL_accept error");
exit(7);
}
return 0;
}
n=SSL_read(pMachine->pSSL,aucBuf,nBuf);
if(n < 0)
{
int err=SSL_get_error(pMachine->pSSL,n);
if(err == SSL_ERROR_WANT_READ)
{
fprintf(stderr,"SSL_read wants more data\n");
return 0;
}
}
fprintf(stderr,"%d bytes of decrypted data read from state machine\n",n);
return n;
}
int SSLStateMachine_write_can_extract(SSLStateMachine *pMachine)
{
int n=BIO_pending(pMachine->pbioWrite);
if(n)
fprintf(stderr,"There is encrypted data available to write\n");
else
fprintf(stderr,"There is no encrypted data available to write\n");
return n;
}
int SSLStateMachine_write_extract(SSLStateMachine *pMachine,
unsigned char *aucBuf,int nBuf)
{
int n;
n=BIO_read(pMachine->pbioWrite,aucBuf,nBuf);
fprintf(stderr,"%d bytes of encrypted data read from state machine\n",n);
return n;
}
void SSLStateMachine_write_inject(SSLStateMachine *pMachine,
const unsigned char *aucBuf,int nBuf)
{
int n=SSL_write(pMachine->pSSL,aucBuf,nBuf);
assert(n == nBuf);
fprintf(stderr,"%d bytes of unencrypted data fed to state machine\n",n);
}
int OpenSocket(int nPort)
{
int nSocket;
struct sockaddr_in saServer;
struct sockaddr_in saClient;
int one=1;
int nSize;
int nFD;
int nLen;
nSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(nSocket < 0)
{
perror("socket");
exit(1);
}
if(setsockopt(nSocket,SOL_SOCKET,SO_REUSEADDR,(char *)&one,sizeof one) < 0)
{
perror("setsockopt");
exit(2);
}
memset(&saServer,0,sizeof saServer);
saServer.sin_family=AF_INET;
saServer.sin_port=htons(nPort);
nSize=sizeof saServer;
if(bind(nSocket,(struct sockaddr *)&saServer,nSize) < 0)
{
perror("bind");
exit(3);
}
if(listen(nSocket,512) < 0)
{
perror("listen");
exit(4);
}
nLen=sizeof saClient;
nFD=accept(nSocket,(struct sockaddr *)&saClient,&nLen);
if(nFD < 0)
{
perror("accept");
exit(5);
}
fprintf(stderr,"Incoming accepted on port %d\n",nPort);
return nFD;
}
int main(int argc,char **argv)
{
SSLStateMachine *pMachine;
int nPort;
int nFD;
const char *szCertificateFile;
const char *szKeyFile;
if(argc != 4)
{
fprintf(stderr,"%s <port> <certificate file> <key file>\n",argv[0]);
exit(6);
}
nPort=atoi(argv[1]);
szCertificateFile=argv[2];
szKeyFile=argv[3];
SSL_library_init();
OpenSSL_add_ssl_algorithms();
SSL_load_error_strings();
ERR_load_crypto_strings();
nFD=OpenSocket(nPort);
pMachine=SSLStateMachine_new(szCertificateFile,szKeyFile);
for( ; ; )
{
fd_set rfds,wfds;
unsigned char buf[1024];
int n;
FD_ZERO(&rfds);
FD_ZERO(&wfds);
FD_SET(nFD,&rfds);
if(SSLStateMachine_write_can_extract(pMachine))
FD_SET(nFD,&wfds);
FD_SET(0,&rfds);
n=select(nFD+1,&rfds,&wfds,NULL,NULL);
assert(n > 0);
if(FD_ISSET(nFD,&rfds))
{
n=read(nFD,buf,sizeof buf);
if(n == 0)
{
fprintf(stderr,"Got EOF on socket\n");
exit(0);
}
assert(n > 0);
SSLStateMachine_read_inject(pMachine,buf,n);
}
n=SSLStateMachine_read_extract(pMachine,buf,n);
if(n < 0)
{
SSLStateMachine_print_error(pMachine,"read extract failed");
break;
}
assert(n >= 0);
if(n > 0)
{
int w;
w=write(1,buf,n);
assert(w == n);
}
if(FD_ISSET(nFD,&wfds))
{
int w;
n=SSLStateMachine_write_extract(pMachine,buf,sizeof buf);
assert(n > 0);
w=write(nFD,buf,n);
assert(w == n);
}
if(FD_ISSET(0,&rfds))
{
n=read(0,buf,sizeof buf);
if(n == 0)
{
fprintf(stderr,"Got EOF on stdin\n");
exit(0);
}
assert(n > 0);
SSLStateMachine_write_inject(pMachine,buf,n);
}
}
return 0;
}
