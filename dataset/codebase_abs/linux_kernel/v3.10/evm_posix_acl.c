int F_1 ( char * V_1 )
{
int V_2 = strlen ( V_1 ) ;
if ( ( strlen ( V_3 ) == V_2 )
&& ( strncmp ( V_3 , V_1 , V_2 ) == 0 ) )
return 1 ;
if ( ( strlen ( V_4 ) == V_2 )
&& ( strncmp ( V_4 , V_1 , V_2 ) == 0 ) )
return 1 ;
return 0 ;
}
