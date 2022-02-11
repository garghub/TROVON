int main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
T_3 * V_1 ;
T_4 * V_2 ;
T_5 * V_3 ;
T_5 * V_4 , * V_5 ;
char V_6 [ 1024 * 4 ] ;
int V_7 ;
int V_8 = 1 ;
char * V_9 = NULL ;
const T_6 * V_10 ;
F_1 () ;
V_4 = F_2 ( F_3 () ) ;
while( T_1 > 1 )
{
if ( strcmp ( T_2 [ 1 ] , L_1 ) == 0 )
{
V_8 = 1 ;
T_2 ++ ; T_1 -- ;
}
else if ( ( strcmp ( T_2 [ 1 ] , L_2 ) == 0 ) && ( T_1 >= 2 ) ) {
if( ! ( V_10 = F_4 ( T_2 [ 2 ] ) ) ) {
fprintf ( V_11 , L_3 , T_2 [ 2 ] ) ;
goto V_12;
}
T_1 -= 2 ;
T_2 += 2 ;
} else if ( ( strcmp ( T_2 [ 1 ] , L_4 ) == 0 ) && ( T_1 >= 2 ) ) {
V_9 = T_2 [ 2 ] ;
T_1 -= 2 ;
T_2 += 2 ;
} else break;
}
if ( ! F_5 ( V_4 , T_2 [ 1 ] ) ) goto V_12;
if ( ( V_3 = F_6 ( V_9 , L_5 ) ) == NULL ) goto V_12;
if ( ( V_1 = F_7 ( V_3 , NULL , NULL ) ) == NULL ) goto V_12;
V_2 = F_8 () ;
#if 0
BIO_reset(in);
if ((pkey=PEM_read_bio_PrivateKey(in,NULL,NULL)) == NULL) goto err;
BIO_free(in);
PKCS7_set_type(p7,NID_pkcs7_signedAndEnveloped);
if (PKCS7_add_signature(p7,x509,pkey,EVP_sha1()) == NULL) goto err;
PKCS7_add_certificate(p7,x509);
#else
F_9 ( V_2 , V_13 ) ;
#endif
if( ! V_10 ) V_10 = F_10 () ;
if ( ! F_11 ( V_2 , V_10 ) ) goto V_12;
if ( F_12 ( V_2 , V_1 ) == NULL ) goto V_12;
if ( ( V_5 = F_13 ( V_2 , NULL ) ) == NULL ) goto V_12;
for (; ; )
{
V_7 = F_14 ( V_4 , V_6 , sizeof( V_6 ) ) ;
if ( V_7 <= 0 ) break;
F_15 ( V_5 , V_6 , V_7 ) ;
}
F_16 ( V_5 ) ;
if ( ! F_17 ( V_2 , V_5 ) ) goto V_12;
F_18 ( V_5 ) ;
F_19 ( stdout , V_2 ) ;
F_20 ( V_2 ) ;
exit ( 0 ) ;
V_12:
F_21 () ;
F_22 ( V_11 ) ;
exit ( 1 ) ;
}
