T_1
#else
# include <stdio.h>
# include <openssl/evp.h>
# include <openssl/objects.h>
# include <openssl/x509.h>
# include <openssl/rsa.h>
int F_1 ( T_2 * V_1 , const T_3 * type ,
const unsigned char * V_2 , int V_3 , const unsigned char * V_4 ,
T_4 * V_5 )
{
unsigned char * V_6 = NULL ;
int V_7 , V_8 = 0 , V_9 = 0 ;
if ( type ) {
F_2 ( V_1 ) ;
if ( ! F_3 ( V_1 , type , NULL , NULL , NULL ) )
return 0 ;
}
if ( ! V_5 )
return 1 ;
if ( F_4 ( V_5 ) != V_10 ) {
F_5 ( V_11 , V_12 ) ;
goto V_13;
}
V_8 = F_6 ( V_5 ) ;
V_6 = F_7 ( V_8 + 2 ) ;
if ( V_6 == NULL ) {
F_5 ( V_11 , V_14 ) ;
goto V_13;
}
V_7 = F_8 ( V_6 , V_2 , V_3 , V_5 ) ;
if ( ( V_7 <= 0 ) || ! F_9 ( V_1 , V_7 ) ) {
goto V_13;
}
if ( ! F_3 ( V_1 , NULL , NULL , V_6 , V_4 ) )
goto V_13;
V_9 = 1 ;
V_13:
F_10 ( V_6 , V_8 ) ;
return ( V_9 ) ;
}
int F_11 ( T_2 * V_1 , unsigned char * V_15 , int * V_16 )
{
int V_7 ;
V_7 = F_12 ( V_1 , V_15 , V_16 ) ;
if ( V_7 )
V_7 = F_3 ( V_1 , NULL , NULL , NULL , NULL ) ;
return ( V_7 ) ;
}
