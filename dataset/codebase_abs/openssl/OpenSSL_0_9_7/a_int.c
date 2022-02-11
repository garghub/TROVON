T_1 * F_1 ( T_1 * V_1 )
{ return F_2 ( V_1 ) ; }
int F_3 ( T_1 * V_1 , T_1 * V_2 )
{ return F_4 ( V_1 , V_2 ) ; }
int F_5 ( T_1 * V_3 , unsigned char * * V_4 )
{
int V_5 = 0 , V_6 , V_7 , V_8 ;
unsigned char * V_9 , * V_10 , V_11 = 0 ;
if ( ( V_3 == NULL ) || ( V_3 -> V_12 == NULL ) ) return ( 0 ) ;
V_8 = V_3 -> type & V_13 ;
if ( V_3 -> V_14 == 0 )
V_6 = 1 ;
else
{
V_6 = V_3 -> V_14 ;
V_7 = V_3 -> V_12 [ 0 ] ;
if ( ! V_8 && ( V_7 > 127 ) ) {
V_5 = 1 ;
V_11 = 0 ;
} else if( V_8 ) {
if( V_7 > 128 ) {
V_5 = 1 ;
V_11 = 0xFF ;
} else if( V_7 == 128 ) {
for( V_7 = 1 ; V_7 < V_3 -> V_14 ; V_7 ++ ) if( V_3 -> V_12 [ V_7 ] ) {
V_5 = 1 ;
V_11 = 0xFF ;
break;
}
}
}
V_6 += V_5 ;
}
if ( V_4 == NULL ) return ( V_6 ) ;
V_9 = * V_4 ;
if ( V_5 ) * ( V_9 ++ ) = V_11 ;
if ( V_3 -> V_14 == 0 ) * ( V_9 ++ ) = 0 ;
else if ( ! V_8 ) memcpy ( V_9 , V_3 -> V_12 , ( unsigned int ) V_3 -> V_14 ) ;
else {
V_10 = V_3 -> V_12 + V_3 -> V_14 - 1 ;
V_9 += V_3 -> V_14 - 1 ;
V_7 = V_3 -> V_14 ;
while( ! * V_10 ) {
* ( V_9 -- ) = 0 ;
V_10 -- ;
V_7 -- ;
}
* ( V_9 -- ) = ( ( * ( V_10 -- ) ) ^ 0xff ) + 1 ;
V_7 -- ;
for(; V_7 > 0 ; V_7 -- ) * ( V_9 -- ) = * ( V_10 -- ) ^ 0xff ;
}
* V_4 += V_6 ;
return ( V_6 ) ;
}
T_1 * F_6 ( T_1 * * V_3 , unsigned char * * V_4 ,
long V_15 )
{
T_1 * V_6 = NULL ;
unsigned char * V_9 , * V_16 , * V_17 , * V_18 ;
int V_7 ;
if ( ( V_3 == NULL ) || ( ( * V_3 ) == NULL ) )
{
if ( ( V_6 = F_7 () ) == NULL ) return ( NULL ) ;
V_6 -> type = V_19 ;
}
else
V_6 = ( * V_3 ) ;
V_9 = * V_4 ;
V_18 = V_9 + V_15 ;
V_17 = ( unsigned char * ) F_8 ( ( int ) V_15 + 1 ) ;
if ( V_17 == NULL )
{
V_7 = V_20 ;
goto V_21;
}
V_16 = V_17 ;
if( ! V_15 ) {
V_6 -> type = V_19 ;
} else if ( * V_9 & 0x80 )
{
V_6 -> type = V_22 ;
if ( ( * V_9 == 0xff ) && ( V_15 != 1 ) ) {
V_9 ++ ;
V_15 -- ;
}
V_7 = V_15 ;
V_9 += V_7 - 1 ;
V_16 += V_7 - 1 ;
while( ( ! * V_9 ) && V_7 ) {
* ( V_16 -- ) = 0 ;
V_7 -- ;
V_9 -- ;
}
if( ! V_7 ) {
* V_17 = 1 ;
V_17 [ V_15 ] = 0 ;
V_15 ++ ;
} else {
* ( V_16 -- ) = ( * ( V_9 -- ) ^ 0xff ) + 1 ;
V_7 -- ;
for(; V_7 > 0 ; V_7 -- ) * ( V_16 -- ) = * ( V_9 -- ) ^ 0xff ;
}
} else {
V_6 -> type = V_19 ;
if ( ( * V_9 == 0 ) && ( V_15 != 1 ) )
{
V_9 ++ ;
V_15 -- ;
}
memcpy ( V_17 , V_9 , ( int ) V_15 ) ;
}
if ( V_6 -> V_12 != NULL ) F_9 ( V_6 -> V_12 ) ;
V_6 -> V_12 = V_17 ;
V_6 -> V_14 = ( int ) V_15 ;
if ( V_3 != NULL ) ( * V_3 ) = V_6 ;
* V_4 = V_18 ;
return ( V_6 ) ;
V_21:
F_10 ( V_23 , V_7 ) ;
if ( ( V_6 != NULL ) && ( ( V_3 == NULL ) || ( * V_3 != V_6 ) ) )
F_11 ( V_6 ) ;
return ( NULL ) ;
}
T_1 * F_12 ( T_1 * * V_3 , unsigned char * * V_4 ,
long V_14 )
{
T_1 * V_6 = NULL ;
unsigned char * V_9 , * V_16 , * V_17 ;
long V_15 ;
int V_24 , V_25 , V_26 ;
int V_7 ;
if ( ( V_3 == NULL ) || ( ( * V_3 ) == NULL ) )
{
if ( ( V_6 = F_7 () ) == NULL ) return ( NULL ) ;
V_6 -> type = V_19 ;
}
else
V_6 = ( * V_3 ) ;
V_9 = * V_4 ;
V_24 = F_13 ( & V_9 , & V_15 , & V_25 , & V_26 , V_14 ) ;
if ( V_24 & 0x80 )
{
V_7 = V_27 ;
goto V_21;
}
if ( V_25 != V_19 )
{
V_7 = V_28 ;
goto V_21;
}
V_17 = ( unsigned char * ) F_8 ( ( int ) V_15 + 1 ) ;
if ( V_17 == NULL )
{
V_7 = V_20 ;
goto V_21;
}
V_16 = V_17 ;
V_6 -> type = V_19 ;
if( V_15 ) {
if ( ( * V_9 == 0 ) && ( V_15 != 1 ) )
{
V_9 ++ ;
V_15 -- ;
}
memcpy ( V_17 , V_9 , ( int ) V_15 ) ;
V_9 += V_15 ;
}
if ( V_6 -> V_12 != NULL ) F_9 ( V_6 -> V_12 ) ;
V_6 -> V_12 = V_17 ;
V_6 -> V_14 = ( int ) V_15 ;
if ( V_3 != NULL ) ( * V_3 ) = V_6 ;
* V_4 = V_9 ;
return ( V_6 ) ;
V_21:
F_10 ( V_29 , V_7 ) ;
if ( ( V_6 != NULL ) && ( ( V_3 == NULL ) || ( * V_3 != V_6 ) ) )
F_11 ( V_6 ) ;
return ( NULL ) ;
}
int F_14 ( T_1 * V_3 , long V_30 )
{
int V_7 , V_31 , V_32 ;
unsigned char V_33 [ sizeof( long ) + 1 ] ;
long V_34 ;
V_3 -> type = V_19 ;
if ( V_3 -> V_14 < ( sizeof( long ) + 1 ) )
{
if ( V_3 -> V_12 != NULL )
F_9 ( V_3 -> V_12 ) ;
if ( ( V_3 -> V_12 = ( unsigned char * ) F_8 ( sizeof( long ) + 1 ) ) != NULL )
memset ( ( char * ) V_3 -> V_12 , 0 , sizeof( long ) + 1 ) ;
}
if ( V_3 -> V_12 == NULL )
{
F_10 ( V_35 , V_20 ) ;
return ( 0 ) ;
}
V_34 = V_30 ;
if ( V_34 < 0 )
{
V_34 = - V_34 ;
V_3 -> type = V_22 ;
}
for ( V_7 = 0 ; V_7 < sizeof( long ) ; V_7 ++ )
{
if ( V_34 == 0 ) break;
V_33 [ V_7 ] = ( int ) V_34 & 0xff ;
V_34 >>= 8 ;
}
V_31 = 0 ;
for ( V_32 = V_7 - 1 ; V_32 >= 0 ; V_32 -- )
V_3 -> V_12 [ V_31 ++ ] = V_33 [ V_32 ] ;
V_3 -> V_14 = V_31 ;
return ( 1 ) ;
}
long F_15 ( T_1 * V_3 )
{
int V_8 = 0 , V_7 ;
long V_36 = 0 ;
if ( V_3 == NULL ) return ( 0L ) ;
V_7 = V_3 -> type ;
if ( V_7 == V_22 )
V_8 = 1 ;
else if ( V_7 != V_19 )
return - 1 ;
if ( V_3 -> V_14 > sizeof( long ) )
{
return ( 0xffffffffL ) ;
}
if ( V_3 -> V_12 == NULL )
return 0 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_14 ; V_7 ++ )
{
V_36 <<= 8 ;
V_36 |= ( unsigned char ) V_3 -> V_12 [ V_7 ] ;
}
if ( V_8 ) V_36 = - V_36 ;
return ( V_36 ) ;
}
T_1 * F_16 ( T_2 * V_37 , T_1 * V_38 )
{
T_1 * V_6 ;
int V_15 , V_31 ;
if ( V_38 == NULL )
V_6 = F_7 () ;
else
V_6 = V_38 ;
if ( V_6 == NULL )
{
F_10 ( V_39 , V_40 ) ;
goto V_21;
}
if( V_37 -> V_8 ) V_6 -> type = V_22 ;
else V_6 -> type = V_19 ;
V_31 = F_17 ( V_37 ) ;
V_15 = ( ( V_31 == 0 ) ? 0 : ( ( V_31 / 8 ) + 1 ) ) ;
if ( V_6 -> V_14 < V_15 + 4 )
{
unsigned char * V_41 = F_18 ( V_6 -> V_12 , V_15 + 4 ) ;
if ( ! V_41 )
{
F_10 ( V_39 , V_20 ) ;
goto V_21;
}
V_6 -> V_12 = V_41 ;
}
V_6 -> V_14 = F_19 ( V_37 , V_6 -> V_12 ) ;
if( ! V_6 -> V_14 )
{
V_6 -> V_12 [ 0 ] = 0 ;
V_6 -> V_14 = 1 ;
}
return ( V_6 ) ;
V_21:
if ( V_6 != V_38 ) F_11 ( V_6 ) ;
return ( NULL ) ;
}
T_2 * F_20 ( T_1 * V_38 , T_2 * V_37 )
{
T_2 * V_6 ;
if ( ( V_6 = F_21 ( V_38 -> V_12 , V_38 -> V_14 , V_37 ) ) == NULL )
F_10 ( V_42 , V_43 ) ;
else if( V_38 -> type == V_22 ) V_6 -> V_8 = 1 ;
return ( V_6 ) ;
}
