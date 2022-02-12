int BIO_dump(BIO *bio, const char *s, int len)
{
return BIO_dump_indent(bio, s, len, 0);
}
int BIO_dump_indent(BIO *bio, const char *s, int len, int indent)
{
int ret=0;
char buf[288+1],tmp[20],str[128+1];
int i,j,rows,trunc;
unsigned char ch;
int dump_width;
trunc=0;
#ifdef TRUNCATE
for(; (len > 0) && ((s[len-1] == ' ') || (s[len-1] == '\0')); len--)
trunc++;
#endif
if (indent < 0)
indent = 0;
if (indent)
{
if (indent > 128) indent=128;
memset(str,' ',indent);
}
str[indent]='\0';
dump_width=DUMP_WIDTH_LESS_INDENT(indent);
rows=(len/dump_width);
if ((rows*dump_width)<len)
rows++;
for(i=0;i<rows;i++)
{
buf[0]='\0';
strcpy(buf,str);
sprintf(tmp,"%04x - ",i*dump_width);
strcat(buf,tmp);
for(j=0;j<dump_width;j++)
{
if (((i*dump_width)+j)>=len)
{
strcat(buf," ");
}
else
{
ch=((unsigned char)*(s+i*dump_width+j)) & 0xff;
sprintf(tmp,"%02x%c",ch,j==7?'-':' ');
strcat(buf,tmp);
}
}
strcat(buf," ");
for(j=0;j<dump_width;j++)
{
if (((i*dump_width)+j)>=len)
break;
ch=((unsigned char)*(s+i*dump_width+j)) & 0xff;
#ifndef CHARSET_EBCDIC
sprintf(tmp,"%c",((ch>=' ')&&(ch<='~'))?ch:'.');
#else
sprintf(tmp,"%c",((ch>=os_toascii[' '])&&(ch<=os_toascii['~']))
? os_toebcdic[ch]
: '.');
#endif
strcat(buf,tmp);
}
strcat(buf,"\n");
ret+=BIO_write(bio,(char *)buf,strlen(buf));
}
#ifdef TRUNCATE
if (trunc > 0)
{
sprintf(buf,"%s%04x - <SPACES/NULS>\n",str,len+trunc);
ret+=BIO_write(bio,(char *)buf,strlen(buf));
}
#endif
return(ret);
}
