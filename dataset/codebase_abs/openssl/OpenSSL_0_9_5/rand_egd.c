int F_1 ( const char * V_1 )
{
return ( - 1 ) ;
}
int F_1 ( const char * V_1 )
{
int V_2 = - 1 ;
struct V_3 V_4 ;
int V_5 , V_6 ;
int V_7 = - 1 ;
unsigned char V_8 [ 256 ] ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_9 = V_10 ;
if ( strlen ( V_1 ) > sizeof( V_4 . V_11 ) )
return ( - 1 ) ;
strcpy ( V_4 . V_11 , V_1 ) ;
V_5 = F_2 ( struct V_3 , V_11 ) + strlen ( V_1 ) ;
V_7 = F_3 ( V_10 , V_12 , 0 ) ;
if ( V_7 == - 1 ) return ( - 1 ) ;
if ( F_4 ( V_7 , (struct V_13 * ) & V_4 , V_5 ) == - 1 ) goto V_14;
V_8 [ 0 ] = 1 ;
V_8 [ 1 ] = 255 ;
F_5 ( V_7 , V_8 , 2 ) ;
if ( F_6 ( V_7 , V_8 , 1 ) != 1 ) goto V_14;
if ( V_8 [ 0 ] == 0 ) goto V_14;
V_6 = F_6 ( V_7 , V_8 , 255 ) ;
if ( V_6 < 1 ) goto V_14;
F_7 ( V_8 , V_6 ) ;
if ( F_8 () == 1 )
V_2 = V_6 ;
V_14:
if ( V_7 != - 1 ) F_9 ( V_7 ) ;
return ( V_2 ) ;
}
