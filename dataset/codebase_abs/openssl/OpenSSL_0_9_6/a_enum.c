T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_2 , unsigned char * * V_3 )
{
int V_4 , V_5 ;
if( ! V_2 ) return 0 ;
V_4 = F_6 ( V_2 , NULL ) ;
V_5 = F_7 ( 0 , V_4 , V_6 ) ;
if( V_3 ) {
F_8 ( V_3 , 0 , V_4 , V_6 , V_7 ) ;
F_6 ( V_2 , V_3 ) ;
}
return V_5 ;
}
T_1 * F_9 ( T_1 * * V_2 , unsigned char * * V_3 ,
long V_8 )
{
unsigned char * V_9 ;
long V_4 ;
int V_10 ;
int V_11 , V_12 , V_13 ;
T_1 * V_5 ;
V_9 = * V_3 ;
V_11 = F_10 ( & V_9 , & V_4 , & V_12 , & V_13 , V_8 ) ;
if ( V_11 & 0x80 )
{
V_10 = V_14 ;
goto V_15;
}
if ( V_12 != V_6 )
{
V_10 = V_16 ;
goto V_15;
}
V_5 = F_11 ( V_2 , & V_9 , V_4 ) ;
if( V_5 ) {
V_5 -> type = ( V_17 & V_5 -> type ) | V_6 ;
* V_3 = V_9 ;
}
return V_5 ;
V_15:
F_12 ( V_18 , V_10 ) ;
return ( NULL ) ;
}
int F_13 ( T_1 * V_2 , long V_19 )
{
int V_10 , V_20 , V_21 ;
unsigned char V_22 [ sizeof( long ) + 1 ] ;
long V_23 ;
V_2 -> type = V_6 ;
if ( V_2 -> V_8 < ( sizeof( long ) + 1 ) )
{
if ( V_2 -> V_24 != NULL )
F_14 ( V_2 -> V_24 ) ;
if ( ( V_2 -> V_24 = ( unsigned char * ) F_15 ( sizeof( long ) + 1 ) ) != NULL )
memset ( ( char * ) V_2 -> V_24 , 0 , sizeof( long ) + 1 ) ;
}
if ( V_2 -> V_24 == NULL )
{
F_12 ( V_25 , V_26 ) ;
return ( 0 ) ;
}
V_23 = V_19 ;
if ( V_23 < 0 )
{
V_23 = - V_23 ;
V_2 -> type = V_27 ;
}
for ( V_10 = 0 ; V_10 < sizeof( long ) ; V_10 ++ )
{
if ( V_23 == 0 ) break;
V_22 [ V_10 ] = ( int ) V_23 & 0xff ;
V_23 >>= 8 ;
}
V_20 = 0 ;
for ( V_21 = V_10 - 1 ; V_21 >= 0 ; V_21 -- )
V_2 -> V_24 [ V_20 ++ ] = V_22 [ V_21 ] ;
V_2 -> V_8 = V_20 ;
return ( 1 ) ;
}
long F_16 ( T_1 * V_2 )
{
int V_28 = 0 , V_10 ;
long V_29 = 0 ;
if ( V_2 == NULL ) return ( 0L ) ;
V_10 = V_2 -> type ;
if ( V_10 == V_27 )
V_28 = 1 ;
else if ( V_10 != V_6 )
return ( 0 ) ;
if ( V_2 -> V_8 > sizeof( long ) )
{
return ( 0xffffffffL ) ;
}
if ( V_2 -> V_24 == NULL )
return ( 0 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_8 ; V_10 ++ )
{
V_29 <<= 8 ;
V_29 |= ( unsigned char ) V_2 -> V_24 [ V_10 ] ;
}
if ( V_28 ) V_29 = - V_29 ;
return ( V_29 ) ;
}
T_1 * F_17 ( T_2 * V_30 , T_1 * V_31 )
{
T_1 * V_5 ;
int V_4 , V_20 ;
if ( V_31 == NULL )
V_5 = F_2 () ;
else
V_5 = V_31 ;
if ( V_5 == NULL )
{
F_12 ( V_32 , V_33 ) ;
goto V_15;
}
if( V_30 -> V_28 ) V_5 -> type = V_27 ;
else V_5 -> type = V_6 ;
V_20 = F_18 ( V_30 ) ;
V_4 = ( ( V_20 == 0 ) ? 0 : ( ( V_20 / 8 ) + 1 ) ) ;
V_5 -> V_24 = ( unsigned char * ) F_15 ( V_4 + 4 ) ;
V_5 -> V_8 = F_19 ( V_30 , V_5 -> V_24 ) ;
return ( V_5 ) ;
V_15:
if ( V_5 != V_31 ) F_4 ( V_5 ) ;
return ( NULL ) ;
}
T_2 * F_20 ( T_1 * V_31 , T_2 * V_30 )
{
T_2 * V_5 ;
if ( ( V_5 = F_21 ( V_31 -> V_24 , V_31 -> V_8 , V_30 ) ) == NULL )
F_12 ( V_34 , V_35 ) ;
else if( V_31 -> type == V_27 ) V_5 -> V_28 = 1 ;
return ( V_5 ) ;
}
