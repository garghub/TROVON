main()
{
fprintf(stderr,"rc4\n");
rc4();
fprintf(stderr,"cfb des\n");
des();
}
int des()
{
des_key_schedule ks;
des_cblock iv,key;
int num;
static char *keystr="01234567";
static char *in1="0123456789ABCEDFdata 12345";
static char *in2="9876543210abcdefdata 12345";
unsigned char out[100];
int i;
des_set_key((des_cblock *)keystr,ks);
num=0;
memset(iv,0,8);
des_cfb64_encrypt(in1,out,26,ks,(des_cblock *)iv,&num,1);
for (i=0; i<26; i++)
fprintf(stderr,"%02X ",out[i]);
fprintf(stderr,"\n");
num=0;
memset(iv,0,8);
des_cfb64_encrypt(in2,out,26,ks,(des_cblock *)iv,&num,1);
for (i=0; i<26; i++)
fprintf(stderr,"%02X ",out[i]);
fprintf(stderr,"\n");
}
int rc4()
{
static char *keystr="0123456789abcdef";
RC4_KEY key;
unsigned char in[100],out[100];
int i;
RC4_set_key(&key,16,keystr);
in[0]='\0';
strcpy(in,"0123456789ABCEDFdata 12345");
RC4(key,26,in,out);
for (i=0; i<26; i++)
fprintf(stderr,"%02X ",out[i]);
fprintf(stderr,"\n");
RC4_set_key(&key,16,keystr);
in[0]='\0';
strcpy(in,"9876543210abcdefdata 12345");
RC4(key,26,in,out);
for (i=0; i<26; i++)
fprintf(stderr,"%02X ",out[i]);
fprintf(stderr,"\n");
}
