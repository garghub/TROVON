T_1 F_1 ( const void * V_1 , const void * V_2 , T_2 V_3 )
{
return memcmp ( V_1 , V_2 , V_3 ) ;
}
void F_2 ( void * V_4 , const void * V_5 , T_2 V_3 )
{
memcpy ( V_4 , V_5 , V_3 ) ;
}
void * F_3 ( void * V_4 , T_3 V_6 , T_2 V_3 )
{
return memset ( V_4 , V_6 , V_3 ) ;
}
char * F_4 ( char * V_7 , const char * V_8 ,
T_2 V_3 )
{
return strncpy ( V_7 , V_8 , V_3 ) ;
}
T_1 F_5 ( const char * V_9 , const char * V_10 ,
T_2 V_3 )
{
T_1 V_11 ;
if ( V_9 == NULL && V_10 == NULL ) {
V_11 = 0 ;
} else if ( V_9 == NULL ) {
V_11 = - 1 ;
} else if ( V_10 == NULL ) {
V_11 = 1 ;
} else {
V_11 = strncmp ( V_9 , V_10 , V_3 ) ;
if ( V_11 < 0 ) {
V_11 = - 1 ;
} else if ( V_11 > 0 ) {
V_11 = 1 ;
}
}
return V_11 ;
}
T_2 F_6 ( const char * V_12 )
{
return ( T_2 ) strlen ( V_12 ) ;
}
