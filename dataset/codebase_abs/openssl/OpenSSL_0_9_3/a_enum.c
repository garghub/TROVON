int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
int V_3 = 0 , V_4 , V_5 , V_6 , V_7 ;
unsigned char * V_8 , * V_9 , V_10 = 0 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_11 == NULL ) ) return ( 0 ) ;
V_7 = V_1 -> type ;
if ( V_1 -> V_12 == 0 )
V_4 = 1 ;
else
{
V_4 = V_1 -> V_12 ;
V_6 = V_1 -> V_11 [ 0 ] ;
if ( ( V_7 == V_13 ) && ( V_6 > 127 ) ) {
V_3 = 1 ;
V_10 = 0 ;
} else if( V_7 == V_14 ) {
if( V_6 > 128 ) {
V_3 = 1 ;
V_10 = 0xFF ;
} else if( V_6 == 128 ) {
for( V_6 = 1 ; V_6 < V_1 -> V_12 ; V_6 ++ ) if( V_1 -> V_11 [ V_6 ] ) {
V_3 = 1 ;
V_10 = 0xFF ;
break;
}
}
}
V_4 += V_3 ;
}
V_5 = F_2 ( 0 , V_4 , V_13 ) ;
if ( V_2 == NULL ) return ( V_5 ) ;
V_8 = * V_2 ;
F_3 ( & V_8 , 0 , V_4 , V_13 , V_15 ) ;
if ( V_3 ) * ( V_8 ++ ) = V_10 ;
if ( V_1 -> V_12 == 0 )
* ( V_8 ++ ) = 0 ;
else if ( V_7 == V_13 )
{
memcpy ( V_8 , V_1 -> V_11 , ( unsigned int ) V_1 -> V_12 ) ;
V_8 += V_1 -> V_12 ;
}
else {
V_9 = V_1 -> V_11 + V_1 -> V_12 - 1 ;
V_8 += V_1 -> V_12 - 1 ;
V_6 = V_1 -> V_12 ;
while( ! * V_9 ) {
* ( V_8 -- ) = 0 ;
V_9 -- ;
V_6 -- ;
}
* ( V_8 -- ) = ( ( * ( V_9 -- ) ) ^ 0xff ) + 1 ;
V_6 -- ;
for(; V_6 > 0 ; V_6 -- ) * ( V_8 -- ) = * ( V_9 -- ) ^ 0xff ;
V_8 += V_1 -> V_12 ;
}
* V_2 = V_8 ;
return ( V_5 ) ;
}
T_1 * F_4 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_12 )
{
T_1 * V_4 = NULL ;
unsigned char * V_8 , * V_16 , * V_17 ;
long V_18 ;
int V_19 , V_20 , V_21 ;
int V_6 ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) )
{
if ( ( V_4 = F_5 () ) == NULL ) return ( NULL ) ;
V_4 -> type = V_13 ;
}
else
V_4 = ( * V_1 ) ;
V_8 = * V_2 ;
V_19 = F_6 ( & V_8 , & V_18 , & V_20 , & V_21 , V_12 ) ;
if ( V_19 & 0x80 )
{
V_6 = V_22 ;
goto V_23;
}
if ( V_20 != V_13 )
{
V_6 = V_24 ;
goto V_23;
}
V_17 = ( unsigned char * ) Malloc ( ( int ) V_18 + 1 ) ;
if ( V_17 == NULL )
{
V_6 = V_25 ;
goto V_23;
}
V_16 = V_17 ;
if ( * V_8 & 0x80 )
{
V_4 -> type = V_14 ;
if ( ( * V_8 == 0xff ) && ( V_18 != 1 ) ) {
V_8 ++ ;
V_18 -- ;
}
V_6 = V_18 ;
V_8 += V_6 - 1 ;
V_16 += V_6 - 1 ;
while( ( ! * V_8 ) && V_6 ) {
* ( V_16 -- ) = 0 ;
V_6 -- ;
V_8 -- ;
}
if( ! V_6 ) {
* V_17 = 1 ;
V_17 [ V_18 ] = 0 ;
V_8 += V_18 ;
V_18 ++ ;
} else {
* ( V_16 -- ) = ( * ( V_8 -- ) ^ 0xff ) + 1 ;
V_6 -- ;
for(; V_6 > 0 ; V_6 -- ) * ( V_16 -- ) = * ( V_8 -- ) ^ 0xff ;
V_8 += V_18 ;
}
} else {
V_4 -> type = V_13 ;
if ( ( * V_8 == 0 ) && ( V_18 != 1 ) )
{
V_8 ++ ;
V_18 -- ;
}
memcpy ( V_17 , V_8 , ( int ) V_18 ) ;
V_8 += V_18 ;
}
if ( V_4 -> V_11 != NULL ) Free ( ( char * ) V_4 -> V_11 ) ;
V_4 -> V_11 = V_17 ;
V_4 -> V_12 = ( int ) V_18 ;
if ( V_1 != NULL ) ( * V_1 ) = V_4 ;
* V_2 = V_8 ;
return ( V_4 ) ;
V_23:
F_7 ( V_26 , V_6 ) ;
if ( ( V_4 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_4 ) ) )
F_8 ( V_4 ) ;
return ( NULL ) ;
}
int F_9 ( T_1 * V_1 , long V_27 )
{
int V_6 , V_28 , V_29 ;
unsigned char V_30 [ sizeof( long ) + 1 ] ;
long V_31 ;
V_1 -> type = V_13 ;
if ( V_1 -> V_12 < ( sizeof( long ) + 1 ) )
{
if ( V_1 -> V_11 != NULL )
Free ( ( char * ) V_1 -> V_11 ) ;
if ( ( V_1 -> V_11 = ( unsigned char * ) Malloc ( sizeof( long ) + 1 ) ) != NULL )
memset ( ( char * ) V_1 -> V_11 , 0 , sizeof( long ) + 1 ) ;
}
if ( V_1 -> V_11 == NULL )
{
F_7 ( V_32 , V_25 ) ;
return ( 0 ) ;
}
V_31 = V_27 ;
if ( V_31 < 0 )
{
V_31 = - V_31 ;
V_1 -> type = V_14 ;
}
for ( V_6 = 0 ; V_6 < sizeof( long ) ; V_6 ++ )
{
if ( V_31 == 0 ) break;
V_30 [ V_6 ] = ( int ) V_31 & 0xff ;
V_31 >>= 8 ;
}
V_28 = 0 ;
for ( V_29 = V_6 - 1 ; V_29 >= 0 ; V_29 -- )
V_1 -> V_11 [ V_28 ++ ] = V_30 [ V_29 ] ;
V_1 -> V_12 = V_28 ;
return ( 1 ) ;
}
long F_10 ( T_1 * V_1 )
{
int V_33 = 0 , V_6 ;
long V_5 = 0 ;
if ( V_1 == NULL ) return ( 0L ) ;
V_6 = V_1 -> type ;
if ( V_6 == V_14 )
V_33 = 1 ;
else if ( V_6 != V_13 )
return ( 0 ) ;
if ( V_1 -> V_12 > sizeof( long ) )
{
return ( 0xffffffffL ) ;
}
if ( V_1 -> V_11 == NULL )
return ( 0 ) ;
for ( V_6 = 0 ; V_6 < V_1 -> V_12 ; V_6 ++ )
{
V_5 <<= 8 ;
V_5 |= ( unsigned char ) V_1 -> V_11 [ V_6 ] ;
}
if ( V_33 ) V_5 = - V_5 ;
return ( V_5 ) ;
}
T_1 * F_11 ( T_2 * V_34 , T_1 * V_35 )
{
T_1 * V_4 ;
int V_18 , V_28 ;
if ( V_35 == NULL )
V_4 = F_5 () ;
else
V_4 = V_35 ;
if ( V_4 == NULL )
{
F_7 ( V_36 , V_37 ) ;
goto V_23;
}
if( V_34 -> V_33 ) V_4 -> type = V_14 ;
else V_4 -> type = V_13 ;
V_28 = F_12 ( V_34 ) ;
V_18 = ( ( V_28 == 0 ) ? 0 : ( ( V_28 / 8 ) + 1 ) ) ;
V_4 -> V_11 = ( unsigned char * ) Malloc ( V_18 + 4 ) ;
V_4 -> V_12 = F_13 ( V_34 , V_4 -> V_11 ) ;
return ( V_4 ) ;
V_23:
if ( V_4 != V_35 ) F_8 ( V_4 ) ;
return ( NULL ) ;
}
T_2 * F_14 ( T_1 * V_35 , T_2 * V_34 )
{
T_2 * V_4 ;
if ( ( V_4 = F_15 ( V_35 -> V_11 , V_35 -> V_12 , V_34 ) ) == NULL )
F_7 ( V_38 , V_39 ) ;
if( V_35 -> type == V_14 ) V_34 -> V_33 = 1 ;
return ( V_4 ) ;
}
