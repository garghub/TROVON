T_1 F_1 ( const char * V_1 , T_1 V_2 )
{
const char * V_3 ;
for ( V_3 = V_1 ; V_2 -- != 0 && * V_3 != '\0' ; ++ V_3 ) ;
return V_3 - V_1 ;
}
char * F_2 ( const char * V_1 )
{
if ( V_1 == NULL )
return ( NULL ) ;
return F_3 ( V_1 , strlen ( V_1 ) ) ;
}
char * F_3 ( const char * V_1 , T_1 V_4 )
{
char * V_5 ;
if ( V_1 == NULL )
return ( NULL ) ;
V_4 = F_1 ( V_1 , V_4 ) ;
V_5 = F_4 ( V_4 + 1 ) ;
if ( V_5 == NULL ) {
F_5 ( V_6 , V_7 ) ;
return ( NULL ) ;
}
F_6 ( V_5 , V_1 , V_4 + 1 ) ;
return ( V_5 ) ;
}
void * F_7 ( const void * V_8 , T_1 V_4 )
{
void * V_5 ;
if ( V_8 == NULL )
return ( NULL ) ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 == NULL ) {
F_5 ( V_9 , V_7 ) ;
return ( NULL ) ;
}
return memcpy ( V_5 , V_8 , V_4 ) ;
}
T_1 F_6 ( char * V_10 , const char * V_11 , T_1 V_12 )
{
T_1 V_13 = 0 ;
for (; V_12 > 1 && * V_11 ; V_12 -- ) {
* V_10 ++ = * V_11 ++ ;
V_13 ++ ;
}
if ( V_12 )
* V_10 = '\0' ;
return V_13 + strlen ( V_11 ) ;
}
T_1 F_8 ( char * V_10 , const char * V_11 , T_1 V_12 )
{
T_1 V_13 = 0 ;
for (; V_12 > 0 && * V_10 ; V_12 -- , V_10 ++ )
V_13 ++ ;
return V_13 + F_6 ( V_10 , V_11 , V_12 ) ;
}
