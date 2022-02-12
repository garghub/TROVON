void callback(type,num)
int type,num;
{
if (type == 0)
fprintf(stderr,".");
else if (type == 1)
fprintf(stderr,"+");
else if (type == 2)
fprintf(stderr,"*");
fflush(stderr);
}
int main(argc,argv)
int argc;
char *argv[];
{
BIGNUM *rand;
int num=256;
if (argc >= 2)
{
num=atoi(argv[1]);
if (num == 0) num=256;
}
fprintf(stderr,"generate a strong prime\n");
rand=BN_generate_prime(NULL,num,1,NULL,NULL,callback,NULL);
fprintf(stderr,"\n");
BN_print_fp(stdout,rand);
fprintf(stdout,"\n");
BN_free(rand);
exit(0);
return(0);
}
