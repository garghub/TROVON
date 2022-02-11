int
strncasecmp ( const char * V_1 , const char * V_2 , T_1 V_3 )
{
register const unsigned char * V_4 = ( const unsigned char * ) V_1 ;
register const unsigned char * V_5 = ( const unsigned char * ) V_2 ;
unsigned char V_6 , V_7 ;
if ( V_4 == V_5 || V_3 == 0 )
return 0 ;
do
{
V_6 = tolower ( * V_4 ++ ) ;
V_7 = tolower ( * V_5 ++ ) ;
if ( V_6 == '\0' || V_6 != V_7 )
return V_6 - V_7 ;
} while ( -- V_3 > 0 );
return V_6 - V_7 ;
}
