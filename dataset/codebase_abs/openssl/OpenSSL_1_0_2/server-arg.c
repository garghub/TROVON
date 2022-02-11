int main ( int V_1 , char * V_2 [] )
{
char * V_3 = L_1 ;
T_1 * V_4 , * V_5 ;
T_2 * V_6 ;
T_3 * V_7 ;
char V_8 [ 512 ] ;
T_1 * V_9 = NULL ;
int V_10 = 1 , V_11 ;
char * * args = V_2 + 1 ;
int V_12 = V_1 - 1 ;
F_1 () ;
F_2 () ;
V_6 = F_3 ( F_4 () ) ;
V_7 = F_5 () ;
F_6 ( V_7 , V_13 ) ;
F_6 ( V_7 , V_14 ) ;
F_7 ( V_7 , V_6 ) ;
while ( * args && * * args == '-' ) {
int V_15 ;
V_15 = F_8 ( V_7 , & V_12 , & args ) ;
if ( V_15 == - 3 ) {
fprintf ( V_16 , L_2 , * args ) ;
goto V_17;
}
if ( V_15 < 0 ) {
fprintf ( V_16 , L_3 , * args ) ;
F_9 ( V_16 ) ;
goto V_17;
}
if ( V_15 > 0 )
continue;
if ( ! strcmp ( * args , L_4 ) ) {
V_3 = args [ 1 ] ;
if ( V_3 == NULL ) {
fprintf ( V_16 , L_5 ) ;
goto V_17;
}
args += 2 ;
V_12 -= 2 ;
continue;
} else {
fprintf ( V_16 , L_6 , * args ) ;
goto V_17;
}
}
if ( ! F_10 ( V_7 ) ) {
fprintf ( V_16 , L_7 ) ;
F_9 ( V_16 ) ;
goto V_17;
}
#if 0
{
X509 *x;
int rv;
rv = SSL_CTX_set_current_cert(ctx, SSL_CERT_SET_FIRST);
while (rv) {
X509 *x = SSL_CTX_get0_certificate(ctx);
X509_NAME_print_ex_fp(stdout, X509_get_subject_name(x), 0,
XN_FLAG_ONELINE);
printf("\n");
rv = SSL_CTX_set_current_cert(ctx, SSL_CERT_SET_NEXT);
}
fflush(stdout);
}
#endif
V_4 = F_11 ( V_6 , 0 ) ;
if ( ( V_9 = F_12 ( V_3 ) ) == NULL )
goto V_17;
F_13 ( V_9 , V_4 ) ;
V_18:
if ( F_14 ( V_9 ) <= 0 )
goto V_17;
for (; ; ) {
V_11 = F_15 ( V_9 , V_8 , 512 ) ;
if ( V_11 == 0 ) {
printf ( L_8 ) ;
V_5 = F_16 ( V_9 ) ;
F_17 ( V_5 ) ;
goto V_18;
}
if ( V_11 < 0 )
goto V_17;
fwrite ( V_8 , 1 , V_11 , stdout ) ;
fflush ( stdout ) ;
}
V_10 = 0 ;
V_17:
if ( V_10 ) {
F_9 ( V_16 ) ;
}
if ( V_9 != NULL )
F_18 ( V_9 ) ;
exit ( V_10 ) ;
return ( ! V_10 ) ;
}
