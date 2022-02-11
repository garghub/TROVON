int F_1 ( char * V_1 , const char * V_2 , char * const V_3 [] )
{
if ( * V_2 == '\0' ) {
return - V_4 ;
}
if ( strchr ( V_2 , '/' ) != NULL ) {
F_2 ( V_2 , V_3 ) ;
} else {
int V_5 ;
T_1 V_6 , V_7 ;
char * V_8 , * V_9 ;
char * V_10 = getenv ( L_1 ) ;
if ( V_10 == NULL )
V_10 = L_2 ;
V_6 = strlen ( V_2 ) + 1 ;
V_7 = strlen ( V_10 ) ;
V_8 = memcpy ( V_1 + V_7 + 1 , V_2 , V_6 ) ;
* -- V_8 = '/' ;
V_5 = 0 ;
V_9 = V_10 ;
do {
char * V_11 ;
V_10 = V_9 ;
V_9 = strchr ( V_10 , ':' ) ;
if ( ! V_9 )
V_9 = strchr ( V_10 , '\0' ) ;
if ( V_9 == V_10 )
V_11 = V_8 + 1 ;
else
V_11 = memcpy ( V_8 - ( V_9 - V_10 ) , V_10 , V_9 - V_10 ) ;
F_2 ( V_11 , V_3 ) ;
switch ( V_12 ) {
case V_13 :
V_5 = 1 ;
case V_4 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
break;
default:
return - V_12 ;
}
} while ( * V_9 ++ != '\0' );
if ( V_5 )
return - V_13 ;
}
return - V_12 ;
}
int main ( int V_19 , char * * V_3 )
{
char V_1 [ V_20 ] ;
int V_21 ;
V_19 -- ;
if ( ! V_19 ) {
fprintf ( V_22 , L_3 ) ;
return 1 ;
}
V_3 ++ ;
if ( V_21 = F_1 ( V_1 , V_3 [ 0 ] , V_3 ) ) {
V_12 = - V_21 ;
perror ( L_4 ) ;
}
return 0 ;
}
