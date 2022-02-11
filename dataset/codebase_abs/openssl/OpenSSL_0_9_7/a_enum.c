int F_1 ( T_1 * V_1 , long V_2 )
{
int V_3 , V_4 , V_5 ;
unsigned char V_6 [ sizeof( long ) + 1 ] ;
long V_7 ;
V_1 -> type = V_8 ;
if ( V_1 -> V_9 < ( sizeof( long ) + 1 ) )
{
if ( V_1 -> V_10 != NULL )
F_2 ( V_1 -> V_10 ) ;
if ( ( V_1 -> V_10 = ( unsigned char * ) F_3 ( sizeof( long ) + 1 ) ) != NULL )
memset ( ( char * ) V_1 -> V_10 , 0 , sizeof( long ) + 1 ) ;
}
if ( V_1 -> V_10 == NULL )
{
F_4 ( V_11 , V_12 ) ;
return ( 0 ) ;
}
V_7 = V_2 ;
if ( V_7 < 0 )
{
V_7 = - V_7 ;
V_1 -> type = V_13 ;
}
for ( V_3 = 0 ; V_3 < sizeof( long ) ; V_3 ++ )
{
if ( V_7 == 0 ) break;
V_6 [ V_3 ] = ( int ) V_7 & 0xff ;
V_7 >>= 8 ;
}
V_4 = 0 ;
for ( V_5 = V_3 - 1 ; V_5 >= 0 ; V_5 -- )
V_1 -> V_10 [ V_4 ++ ] = V_6 [ V_5 ] ;
V_1 -> V_9 = V_4 ;
return ( 1 ) ;
}
long F_5 ( T_1 * V_1 )
{
int V_14 = 0 , V_3 ;
long V_15 = 0 ;
if ( V_1 == NULL ) return ( 0L ) ;
V_3 = V_1 -> type ;
if ( V_3 == V_13 )
V_14 = 1 ;
else if ( V_3 != V_8 )
return - 1 ;
if ( V_1 -> V_9 > sizeof( long ) )
{
return ( 0xffffffffL ) ;
}
if ( V_1 -> V_10 == NULL )
return 0 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_9 ; V_3 ++ )
{
V_15 <<= 8 ;
V_15 |= ( unsigned char ) V_1 -> V_10 [ V_3 ] ;
}
if ( V_14 ) V_15 = - V_15 ;
return ( V_15 ) ;
}
T_1 * F_6 ( T_2 * V_16 , T_1 * V_17 )
{
T_1 * V_18 ;
int V_19 , V_4 ;
if ( V_17 == NULL )
V_18 = F_7 () ;
else
V_18 = V_17 ;
if ( V_18 == NULL )
{
F_4 ( V_20 , V_21 ) ;
goto V_22;
}
if( V_16 -> V_14 ) V_18 -> type = V_13 ;
else V_18 -> type = V_8 ;
V_4 = F_8 ( V_16 ) ;
V_19 = ( ( V_4 == 0 ) ? 0 : ( ( V_4 / 8 ) + 1 ) ) ;
if ( V_18 -> V_9 < V_19 + 4 )
{
unsigned char * V_23 = F_9 ( V_18 -> V_10 , V_19 + 4 ) ;
if ( ! V_23 )
{
F_4 ( V_24 , V_12 ) ;
goto V_22;
}
V_18 -> V_10 = V_23 ;
}
V_18 -> V_9 = F_10 ( V_16 , V_18 -> V_10 ) ;
return ( V_18 ) ;
V_22:
if ( V_18 != V_17 ) F_11 ( V_18 ) ;
return ( NULL ) ;
}
T_2 * F_12 ( T_1 * V_17 , T_2 * V_16 )
{
T_2 * V_18 ;
if ( ( V_18 = F_13 ( V_17 -> V_10 , V_17 -> V_9 , V_16 ) ) == NULL )
F_4 ( V_25 , V_26 ) ;
else if( V_17 -> type == V_13 ) V_18 -> V_14 = 1 ;
return ( V_18 ) ;
}
