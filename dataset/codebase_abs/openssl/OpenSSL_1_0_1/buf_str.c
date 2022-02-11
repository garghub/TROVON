char * F_1 ( const char * V_1 )
{
if ( V_1 == NULL ) return ( NULL ) ;
return F_2 ( V_1 , strlen ( V_1 ) ) ;
}
char * F_2 ( const char * V_1 , T_1 V_2 )
{
char * V_3 ;
if ( V_1 == NULL ) return ( NULL ) ;
V_3 = F_3 ( V_2 + 1 ) ;
if ( V_3 == NULL )
{
F_4 ( V_4 , V_5 ) ;
return ( NULL ) ;
}
F_5 ( V_3 , V_1 , V_2 + 1 ) ;
return ( V_3 ) ;
}
void * F_6 ( const void * V_6 , T_1 V_2 )
{
void * V_3 ;
if ( V_6 == NULL ) return ( NULL ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 == NULL )
{
F_4 ( V_7 , V_5 ) ;
return ( NULL ) ;
}
return memcpy ( V_3 , V_6 , V_2 ) ;
}
T_1 F_5 ( char * V_8 , const char * V_9 , T_1 V_10 )
{
T_1 V_11 = 0 ;
for(; V_10 > 1 && * V_9 ; V_10 -- )
{
* V_8 ++ = * V_9 ++ ;
V_11 ++ ;
}
if ( V_10 )
* V_8 = '\0' ;
return V_11 + strlen ( V_9 ) ;
}
T_1 F_7 ( char * V_8 , const char * V_9 , T_1 V_10 )
{
T_1 V_11 = 0 ;
for(; V_10 > 0 && * V_8 ; V_10 -- , V_8 ++ )
V_11 ++ ;
return V_11 + F_5 ( V_8 , V_9 , V_10 ) ;
}
