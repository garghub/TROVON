int BIO_dump(BIO *bio, const char *s, int len)
{
int ret=0;
char buf[160+1],tmp[20];
int i,j,rows,trunc;
unsigned char ch;
trunc=0;
#ifdef TRUNCATE
for(; (len > 0) && ((s[len-1] == ' ') || (s[len-1] == '\0')); len--)
trunc++;
#endif
rows=(len/DUMP_WIDTH);
if ((rows*DUMP_WIDTH)<len)
rows++;
for(i=0;i<rows;i++) {
buf[0]='\0';
sprintf(tmp,"%04x - ",i*DUMP_WIDTH);
strcpy(buf,tmp);
for(j=0;j<DUMP_WIDTH;j++) {
if (((i*DUMP_WIDTH)+j)>=len) {
strcat(buf," ");
} else {
ch=((unsigned char)*((char *)(s)+i*DUMP_WIDTH+j)) & 0xff;
sprintf(tmp,"%02x%c",ch,j==7?'-':' ');
strcat(buf,tmp);
}
}
strcat(buf," ");
for(j=0;j<DUMP_WIDTH;j++) {
if (((i*DUMP_WIDTH)+j)>=len)
break;
ch=((unsigned char)*((char *)(s)+i*DUMP_WIDTH+j)) & 0xff;
sprintf(tmp,"%c",((ch>=' ')&&(ch<='~'))?ch:'.');
strcat(buf,tmp);
}
strcat(buf,"\n");
ret+=BIO_write(bio,(char *)buf,strlen(buf));
}
#ifdef TRUNCATE
if (trunc > 0) {
sprintf(buf,"%04x - <SPACES/NULS>\n",len+trunc);
ret+=BIO_write(bio,(char *)buf,strlen(buf));
}
#endif
return(ret);
}
