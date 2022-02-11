int F_1 ( const char * V_1 )
{
return ( - 1 ) ;
}
int F_2 ( const char * V_1 , int V_2 )
{
return ( - 1 ) ;
}
int F_1 ( const char * V_1 )
{
int V_3 = - 1 ;
struct V_4 V_5 ;
int V_6 , V_7 ;
int V_8 = - 1 ;
unsigned char V_9 [ 256 ] ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_10 = V_11 ;
if ( strlen ( V_1 ) > sizeof( V_5 . V_12 ) )
return ( - 1 ) ;
strcpy ( V_5 . V_12 , V_1 ) ;
V_6 = F_3 ( struct V_4 , V_12 ) + strlen ( V_1 ) ;
V_8 = F_4 ( V_11 , V_13 , 0 ) ;
if ( V_8 == - 1 ) return ( - 1 ) ;
if ( F_5 ( V_8 , (struct V_14 * ) & V_5 , V_6 ) == - 1 ) goto V_15;
V_9 [ 0 ] = 1 ;
V_9 [ 1 ] = 255 ;
F_6 ( V_8 , V_9 , 2 ) ;
if ( F_7 ( V_8 , V_9 , 1 ) != 1 ) goto V_15;
if ( V_9 [ 0 ] == 0 ) goto V_15;
V_7 = F_7 ( V_8 , V_9 , 255 ) ;
if ( V_7 < 1 ) goto V_15;
F_8 ( V_9 , V_7 ) ;
if ( F_9 () == 1 )
V_3 = V_7 ;
V_15:
if ( V_8 != - 1 ) F_10 ( V_8 ) ;
return ( V_3 ) ;
}
int F_2 ( const char * V_1 , int V_2 )
{
int V_3 = 0 ;
struct V_4 V_5 ;
int V_6 , V_7 ;
int V_8 = - 1 ;
unsigned char V_9 [ 255 ] ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_10 = V_11 ;
if ( strlen ( V_1 ) > sizeof( V_5 . V_12 ) )
return ( - 1 ) ;
strcpy ( V_5 . V_12 , V_1 ) ;
V_6 = F_3 ( struct V_4 , V_12 ) + strlen ( V_1 ) ;
V_8 = F_4 ( V_11 , V_13 , 0 ) ;
if ( V_8 == - 1 ) return ( - 1 ) ;
if ( F_5 ( V_8 , (struct V_14 * ) & V_5 , V_6 ) == - 1 ) goto V_15;
while( V_2 > 0 )
{
V_9 [ 0 ] = 1 ;
V_9 [ 1 ] = V_2 < 255 ? V_2 : 255 ;
F_6 ( V_8 , V_9 , 2 ) ;
if ( F_7 ( V_8 , V_9 , 1 ) != 1 )
{
V_3 = - 1 ;
goto V_15;
}
if( V_9 [ 0 ] == 0 )
goto V_15;
V_7 = F_7 ( V_8 , V_9 , V_9 [ 0 ] ) ;
if ( V_7 < 1 )
{
V_3 = - 1 ;
goto V_15;
}
F_8 ( V_9 , V_7 ) ;
if ( F_9 () != 1 )
{
V_3 = - 1 ;
goto V_15;
}
V_3 += V_7 ;
V_2 -= V_7 ;
}
V_15:
if ( V_8 != - 1 ) F_10 ( V_8 ) ;
return ( V_3 ) ;
}
