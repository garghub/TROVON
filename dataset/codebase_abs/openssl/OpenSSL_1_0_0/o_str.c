int F_1 ( const char * V_1 , const char * V_2 , T_1 V_3 )
{
#if F_2 ( V_4 )
while ( * V_1 && * V_2 && V_3 )
{
int V_5 = toupper ( * V_1 ) - toupper ( * V_2 ) ;
if ( V_5 ) return V_5 < 0 ? - 1 : 1 ;
V_1 ++ ;
V_2 ++ ;
V_3 -- ;
}
if ( V_3 == 0 )
return 0 ;
if ( * V_1 )
return 1 ;
if ( * V_2 )
return - 1 ;
return 0 ;
#else
return strncasecmp ( V_1 , V_2 , V_3 ) ;
#endif
}
int F_3 ( const char * V_1 , const char * V_2 )
{
#if F_2 ( V_4 )
return F_1 ( V_1 , V_2 , ( T_1 ) - 1 ) ;
#else
return strcasecmp ( V_1 , V_2 ) ;
#endif
}
int F_4 ( const void * V_6 , const void * V_7 , T_1 V_3 )
{
const unsigned char * V_8 = V_6 , * V_9 = V_7 ;
int V_10 = 0 ;
while( V_3 && ( V_10 = * V_8 - * V_9 ) == 0 ) V_3 -- , V_8 ++ , V_9 ++ ;
return V_10 ;
}
