int main(int argc, char **argv)
{
int i;
struct stat ins,outs;
char *p;
char *in=NULL,*out=NULL;
vflag=cflag=eflag=dflag=kflag=hflag=bflag=fflag=sflag=uflag=flag3=0;
error=0;
memset(key,0,sizeof(key));
for (i=1; i<argc; i++)
{
p=argv[i];
if ((p[0] == '-') && (p[1] != '\0'))
{
p++;
while (*p)
{
switch (*(p++))
{
case '3':
flag3=1;
longk=1;
break;
case 'c':
cflag=1;
strncpy(cksumname,p,200);
p+=strlen(cksumname);
break;
case 'C':
cflag=1;
longk=1;
strncpy(cksumname,p,200);
p+=strlen(cksumname);
break;
case 'e':
eflag=1;
break;
case 'v':
vflag=1;
break;
case 'E':
eflag=1;
longk=1;
break;
case 'd':
dflag=1;
break;
case 'D':
dflag=1;
longk=1;
break;
case 'b':
bflag=1;
break;
case 'f':
fflag=1;
break;
case 's':
sflag=1;
break;
case 'u':
uflag=1;
strncpy(uuname,p,200);
p+=strlen(uuname);
break;
case 'h':
hflag=1;
break;
case 'k':
kflag=1;
if ((i+1) == argc)
{
fputs("must have a key with the -k option\n",stderr);
error=1;
}
else
{
int j;
i++;
strncpy(key,argv[i],KEYSIZB);
for (j=strlen(argv[i])-1; j>=0; j--)
argv[i][j]='\0';
}
break;
default:
fprintf(stderr,"'%c' unknown flag\n",p[-1]);
error=1;
break;
}
}
}
else
{
if (in == NULL)
in=argv[i];
else if (out == NULL)
out=argv[i];
else
error=1;
}
}
if (error) usage();
if (((eflag+dflag) == 1) || cflag)
{
if (eflag) do_encrypt=DES_ENCRYPT;
if (dflag) do_encrypt=DES_DECRYPT;
}
else
{
if (vflag)
{
#ifndef _Windows
fprintf(stderr,"des(1) built with %s\n",libdes_version);
#endif
EXIT(1);
}
else usage();
}
#ifndef _Windows
if (vflag) fprintf(stderr,"des(1) built with %s\n",libdes_version);
#endif
if ( (in != NULL) &&
(out != NULL) &&
#ifndef MSDOS
(stat(in,&ins) != -1) &&
(stat(out,&outs) != -1) &&
(ins.st_dev == outs.st_dev) &&
(ins.st_ino == outs.st_ino))
#else
(strcmp(in,out) == 0))
#endif
{
fputs("input and output file are the same\n",stderr);
EXIT(3);
}
if (!kflag
void doencryption(void)
{
#ifdef _LIBC
extern unsigned long time();
#endif
register int i;
des_key_schedule ks,ks2;
des_cblock iv,iv2;
char *p;
int num=0,j,k,l,rem,ll,len,last,ex=0;
des_cblock kk,k2;
FILE *O;
int Exit=0;
#ifndef MSDOS
static unsigned char buf[BUFSIZE+8],obuf[BUFSIZE+8];
#else
static unsigned char *buf=NULL,*obuf=NULL;
if (buf == NULL)
{
if ( (( buf=OPENSSL_malloc(BUFSIZE+8)) == NULL) ||
((obuf=OPENSSL_malloc(BUFSIZE+8)) == NULL))
{
fputs("Not enough memory\n",stderr);
Exit=10;
goto problems;
}
}
#endif
if (hflag)
{
j=(flag3?16:8);
p=key;
for (i=0; i<j; i++)
{
k=0;
if ((*p <= '9') && (*p >= '0'))
k=(*p-'0')<<4;
else if ((*p <= 'f') && (*p >= 'a'))
k=(*p-'a'+10)<<4;
else if ((*p <= 'F') && (*p >= 'A'))
k=(*p-'A'+10)<<4;
else
{
fputs("Bad hex key\n",stderr);
Exit=9;
goto problems;
}
p++;
if ((*p <= '9') && (*p >= '0'))
k|=(*p-'0');
else if ((*p <= 'f') && (*p >= 'a'))
k|=(*p-'a'+10);
else if ((*p <= 'F') && (*p >= 'A'))
k|=(*p-'A'+10);
else
{
fputs("Bad hex key\n",stderr);
Exit=9;
goto problems;
}
p++;
if (i < 8)
kk[i]=k;
else
k2[i-8]=k;
}
des_set_key_unchecked(&k2,ks2);
memset(k2,0,sizeof(k2));
}
else if (longk || flag3)
{
if (flag3)
{
des_string_to_2keys(key,&kk,&k2);
des_set_key_unchecked(&k2,ks2);
memset(k2,0,sizeof(k2));
}
else
des_string_to_key(key,&kk);
}
else
for (i=0; i<KEYSIZ; i++)
{
l=0;
k=key[i];
for (j=0; j<8; j++)
{
if (k&1) l++;
k>>=1;
}
if (l & 1)
kk[i]=key[i]&0x7f;
else
kk[i]=key[i]|0x80;
}
des_set_key_unchecked(&kk,ks);
memset(key,0,sizeof(key));
memset(kk,0,sizeof(kk));
memset(iv,0,sizeof(iv));
memset(iv2,0,sizeof(iv2));
l=1;
rem=0;
if (eflag || (!dflag && cflag))
{
for (;;)
{
num=l=fread(&(buf[rem]),1,BUFSIZE,DES_IN);
l+=rem;
num+=rem;
if (l < 0)
{
perror("read error");
Exit=6;
goto problems;
}
rem=l%8;
len=l-rem;
if (feof(DES_IN))
{
for (i=7-rem; i>0; i--)
RAND_pseudo_bytes(buf + l++, 1);
buf[l++]=rem;
ex=1;
len+=rem;
}
else
l-=rem;
if (cflag)
{
des_cbc_cksum(buf,&cksum,
(long)len,ks,&cksum);
if (!eflag)
{
if (feof(DES_IN)) break;
else continue;
}
}
if (bflag && !flag3)
for (i=0; i<l; i+=8)
des_ecb_encrypt(
(des_cblock *)&(buf[i]),
(des_cblock *)&(obuf[i]),
ks,do_encrypt);
else if (flag3 && bflag)
for (i=0; i<l; i+=8)
des_ecb2_encrypt(
(des_cblock *)&(buf[i]),
(des_cblock *)&(obuf[i]),
ks,ks2,do_encrypt);
else if (flag3 && !bflag)
{
char tmpbuf[8];
if (rem) memcpy(tmpbuf,&(buf[l]),
(unsigned int)rem);
des_3cbc_encrypt(
(des_cblock *)buf,(des_cblock *)obuf,
(long)l,ks,ks2,&iv,
&iv2,do_encrypt);
if (rem) memcpy(&(buf[l]),tmpbuf,
(unsigned int)rem);
}
else
{
des_cbc_encrypt(
buf,obuf,
(long)l,ks,&iv,do_encrypt);
if (l >= 8) memcpy(iv,&(obuf[l-8]),8);
}
if (rem) memcpy(buf,&(buf[l]),(unsigned int)rem);
i=0;
while (i < l)
{
if (uflag)
j=uufwrite(obuf,1,(unsigned int)l-i,
DES_OUT);
else
j=fwrite(obuf,1,(unsigned int)l-i,
DES_OUT);
if (j == -1)
{
perror("Write error");
Exit=7;
goto problems;
}
i+=j;
}
if (feof(DES_IN))
{
if (uflag) uufwriteEnd(DES_OUT);
break;
}
}
}
else
{
ex=1;
for (;;)
{
if (ex) {
if (uflag)
l=uufread(buf,1,BUFSIZE,DES_IN);
else
l=fread(buf,1,BUFSIZE,DES_IN);
ex=0;
rem=l%8;
l-=rem;
}
if (l < 0)
{
perror("read error");
Exit=6;
goto problems;
}
if (bflag && !flag3)
for (i=0; i<l; i+=8)
des_ecb_encrypt(
(des_cblock *)&(buf[i]),
(des_cblock *)&(obuf[i]),
ks,do_encrypt);
else if (flag3 && bflag)
for (i=0; i<l; i+=8)
des_ecb2_encrypt(
(des_cblock *)&(buf[i]),
(des_cblock *)&(obuf[i]),
ks,ks2,do_encrypt);
else if (flag3 && !bflag)
{
des_3cbc_encrypt(
(des_cblock *)buf,(des_cblock *)obuf,
(long)l,ks,ks2,&iv,
&iv2,do_encrypt);
}
else
{
des_cbc_encrypt(
buf,obuf,
(long)l,ks,&iv,do_encrypt);
if (l >= 8) memcpy(iv,&(buf[l-8]),8);
}
if (uflag)
ll=uufread(&(buf[rem]),1,BUFSIZE,DES_IN);
else
ll=fread(&(buf[rem]),1,BUFSIZE,DES_IN);
ll+=rem;
rem=ll%8;
ll-=rem;
if (feof(DES_IN) && (ll == 0))
{
last=obuf[l-1];
if ((last > 7) || (last < 0))
{
fputs("The file was not decrypted correctly.\n",
stderr);
Exit=8;
last=0;
}
l=l-8+last;
}
i=0;
if (cflag) des_cbc_cksum(obuf,
(des_cblock *)cksum,(long)l/8*8,ks,
(des_cblock *)cksum);
while (i != l)
{
j=fwrite(obuf,1,(unsigned int)l-i,DES_OUT);
if (j == -1)
{
perror("Write error");
Exit=7;
goto problems;
}
i+=j;
}
l=ll;
if ((l == 0) && feof(DES_IN)) break;
}
}
if (cflag)
{
l=0;
if (cksumname[0] != '\0')
{
if ((O=fopen(cksumname,"w")) != NULL)
{
CKSUM_OUT=O;
l=1;
}
}
for (i=0; i<8; i++)
fprintf(CKSUM_OUT,"%02X",cksum[i]);
fprintf(CKSUM_OUT,"\n");
if (l) fclose(CKSUM_OUT);
}
problems:
memset(buf,0,sizeof(buf));
memset(obuf,0,sizeof(obuf));
memset(ks,0,sizeof(ks));
memset(ks2,0,sizeof(ks2));
memset(iv,0,sizeof(iv));
memset(iv2,0,sizeof(iv2));
memset(kk,0,sizeof(kk));
memset(k2,0,sizeof(k2));
memset(uubuf,0,sizeof(uubuf));
memset(b,0,sizeof(b));
memset(bb,0,sizeof(bb));
memset(cksum,0,sizeof(cksum));
if (Exit) EXIT(Exit);
}
int uufwrite(unsigned char *data, int size, unsigned int num, FILE *fp)
{
int i,j,left,rem,ret=num;
static int start=1;
if (start)
{
fprintf(fp,"begin 600 %s\n",
(uuname[0] == '\0')?"text.d":uuname);
start=0;
}
if (uubufnum)
{
if (uubufnum+num < 45)
{
memcpy(&(uubuf[uubufnum]),data,(unsigned int)num);
uubufnum+=num;
return(num);
}
else
{
i=45-uubufnum;
memcpy(&(uubuf[uubufnum]),data,(unsigned int)i);
j=uuencode((unsigned char *)uubuf,45,b);
fwrite(b,1,(unsigned int)j,fp);
uubufnum=0;
data+=i;
num-=i;
}
}
for (i=0; i<(((int)num)-INUUBUFN); i+=INUUBUFN)
{
j=uuencode(&(data[i]),INUUBUFN,b);
fwrite(b,1,(unsigned int)j,fp);
}
rem=(num-i)%45;
left=(num-i-rem);
if (left)
{
j=uuencode(&(data[i]),left,b);
fwrite(b,1,(unsigned int)j,fp);
i+=left;
}
if (i != num)
{
memcpy(uubuf,&(data[i]),(unsigned int)rem);
uubufnum=rem;
}
return(ret);
}
void uufwriteEnd(FILE *fp)
{
int j;
static const char *end=" \nend\n";
if (uubufnum != 0)
{
uubuf[uubufnum]='\0';
uubuf[uubufnum+1]='\0';
uubuf[uubufnum+2]='\0';
j=uuencode(uubuf,uubufnum,b);
fwrite(b,1,(unsigned int)j,fp);
}
fwrite(end,1,strlen(end),fp);
}
int uufread(unsigned char *out, int size, unsigned int num, FILE *fp)
{
int i,j,tot;
static int done=0;
static int valid=0;
static int start=1;
if (start)
{
for (;;)
{
b[0]='\0';
fgets((char *)b,300,fp);
if (b[0] == '\0')
{
fprintf(stderr,"no 'begin' found in uuencoded input\n");
return(-1);
}
if (strncmp((char *)b,"begin ",6) == 0) break;
}
start=0;
}
if (done) return(0);
tot=0;
if (valid)
{
memcpy(out,bb,(unsigned int)valid);
tot=valid;
valid=0;
}
for (;;)
{
b[0]='\0';
fgets((char *)b,300,fp);
if (b[0] == '\0') break;
i=strlen((char *)b);
if ((b[0] == 'e') && (b[1] == 'n') && (b[2] == 'd'))
{
done=1;
while (!feof(fp))
{
fgets((char *)b,300,fp);
}
break;
}
i=uudecode(b,i,bb);
if (i < 0) break;
if ((i+tot+8) > num)
{
j=(num/8*8)-tot-8;
memcpy(&(out[tot]),bb,(unsigned int)j);
tot+=j;
memcpy(bb,&(bb[j]),(unsigned int)i-j);
valid=i-j;
break;
}
memcpy(&(out[tot]),bb,(unsigned int)i);
tot+=i;
}
return(tot);
}
int uuencode(unsigned char *in, int num, unsigned char *out)
{
int j,i,n,tot=0;
DES_LONG l;
register unsigned char *p;
p=out;
for (j=0; j<num; j+=45)
{
if (j+45 > num)
i=(num-j);
else i=45;
*(p++)=i+' ';
for (n=0; n<i; n+=3)
{
ccc2l(in,l);
*(p++)=((l>>18)&0x3f)+' ';
*(p++)=((l>>12)&0x3f)+' ';
*(p++)=((l>> 6)&0x3f)+' ';
*(p++)=((l )&0x3f)+' ';
tot+=4;
}
*(p++)='\n';
tot+=2;
}
*p='\0';
l=0;
return(tot);
}
int uudecode(unsigned char *in, int num, unsigned char *out)
{
int j,i,k;
unsigned int n=0,space=0;
DES_LONG l;
DES_LONG w,x,y,z;
unsigned int blank=(unsigned int)'\n'-' ';
for (j=0; j<num; )
{
n= *(in++)-' ';
if (n == blank)
{
n=0;
in--;
}
if (n > 60)
{
fprintf(stderr,"uuencoded line length too long\n");
return(-1);
}
j++;
for (i=0; i<n; j+=4,i+=3)
{
if (space)
{
w=x=y=z=0;
}
else
{
w= *(in++)-' ';
x= *(in++)-' ';
y= *(in++)-' ';
z= *(in++)-' ';
}
if ((w > 63) || (x > 63) || (y > 63) || (z > 63))
{
k=0;
if (w == blank) k=1;
if (x == blank) k=2;
if (y == blank) k=3;
if (z == blank) k=4;
space=1;
switch (k) {
case 1: w=0; in--;
case 2: x=0; in--;
case 3: y=0; in--;
case 4: z=0; in--;
break;
case 0:
space=0;
fprintf(stderr,"bad uuencoded data values\n");
w=x=y=z=0;
return(-1);
break;
}
}
l=(w<<18)|(x<<12)|(y<< 6)|(z );
l2ccc(l,out);
}
if (*(in++) != '\n')
{
fprintf(stderr,"missing nl in uuencoded line\n");
w=x=y=z=0;
return(-1);
}
j++;
}
*out='\0';
w=x=y=z=0;
return(n);
}
