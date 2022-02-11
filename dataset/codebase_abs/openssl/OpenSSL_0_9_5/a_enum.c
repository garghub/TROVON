T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_2 , unsigned char * * V_3 )
{
int V_4 = 0 , V_5 , V_6 , V_7 , V_8 ;
unsigned char * V_9 , * V_10 , V_11 = 0 ;
if ( ( V_2 == NULL ) || ( V_2 -> V_12 == NULL ) ) return ( 0 ) ;
V_8 = V_2 -> type ;
if ( V_2 -> V_13 == 0 )
V_5 = 1 ;
else
{
V_5 = V_2 -> V_13 ;
V_7 = V_2 -> V_12 [ 0 ] ;
if ( ( V_8 == V_14 ) && ( V_7 > 127 ) ) {
V_4 = 1 ;
V_11 = 0 ;
} else if( V_8 == V_15 ) {
if( V_7 > 128 ) {
V_4 = 1 ;
V_11 = 0xFF ;
} else if( V_7 == 128 ) {
for( V_7 = 1 ; V_7 < V_2 -> V_13 ; V_7 ++ ) if( V_2 -> V_12 [ V_7 ] ) {
V_4 = 1 ;
V_11 = 0xFF ;
break;
}
}
}
V_5 += V_4 ;
}
V_6 = F_6 ( 0 , V_5 , V_14 ) ;
if ( V_3 == NULL ) return ( V_6 ) ;
V_9 = * V_3 ;
F_7 ( & V_9 , 0 , V_5 , V_14 , V_16 ) ;
if ( V_4 ) * ( V_9 ++ ) = V_11 ;
if ( V_2 -> V_13 == 0 )
* ( V_9 ++ ) = 0 ;
else if ( V_8 == V_14 )
{
memcpy ( V_9 , V_2 -> V_12 , ( unsigned int ) V_2 -> V_13 ) ;
V_9 += V_2 -> V_13 ;
}
else {
V_10 = V_2 -> V_12 + V_2 -> V_13 - 1 ;
V_9 += V_2 -> V_13 - 1 ;
V_7 = V_2 -> V_13 ;
while( ! * V_10 ) {
* ( V_9 -- ) = 0 ;
V_10 -- ;
V_7 -- ;
}
* ( V_9 -- ) = ( ( * ( V_10 -- ) ) ^ 0xff ) + 1 ;
V_7 -- ;
for(; V_7 > 0 ; V_7 -- ) * ( V_9 -- ) = * ( V_10 -- ) ^ 0xff ;
V_9 += V_2 -> V_13 ;
}
* V_3 = V_9 ;
return ( V_6 ) ;
}
T_1 * F_8 ( T_1 * * V_2 , unsigned char * * V_3 ,
long V_13 )
{
T_1 * V_5 = NULL ;
unsigned char * V_9 , * V_17 , * V_18 ;
long V_19 ;
int V_20 , V_21 , V_22 ;
int V_7 ;
if ( ( V_2 == NULL ) || ( ( * V_2 ) == NULL ) )
{
if ( ( V_5 = F_2 () ) == NULL ) return ( NULL ) ;
V_5 -> type = V_14 ;
}
else
V_5 = ( * V_2 ) ;
V_9 = * V_3 ;
V_20 = F_9 ( & V_9 , & V_19 , & V_21 , & V_22 , V_13 ) ;
if ( V_20 & 0x80 )
{
V_7 = V_23 ;
goto V_24;
}
if ( V_21 != V_14 )
{
V_7 = V_25 ;
goto V_24;
}
V_18 = ( unsigned char * ) Malloc ( ( int ) V_19 + 1 ) ;
if ( V_18 == NULL )
{
V_7 = V_26 ;
goto V_24;
}
V_17 = V_18 ;
if( ! V_19 ) {
V_5 -> type = V_14 ;
} else if ( * V_9 & 0x80 )
{
V_5 -> type = V_15 ;
if ( ( * V_9 == 0xff ) && ( V_19 != 1 ) ) {
V_9 ++ ;
V_19 -- ;
}
V_7 = V_19 ;
V_9 += V_7 - 1 ;
V_17 += V_7 - 1 ;
while( ( ! * V_9 ) && V_7 ) {
* ( V_17 -- ) = 0 ;
V_7 -- ;
V_9 -- ;
}
if( ! V_7 ) {
* V_18 = 1 ;
V_18 [ V_19 ] = 0 ;
V_9 += V_19 ;
V_19 ++ ;
} else {
* ( V_17 -- ) = ( * ( V_9 -- ) ^ 0xff ) + 1 ;
V_7 -- ;
for(; V_7 > 0 ; V_7 -- ) * ( V_17 -- ) = * ( V_9 -- ) ^ 0xff ;
V_9 += V_19 ;
}
} else {
V_5 -> type = V_14 ;
if ( ( * V_9 == 0 ) && ( V_19 != 1 ) )
{
V_9 ++ ;
V_19 -- ;
}
memcpy ( V_18 , V_9 , ( int ) V_19 ) ;
V_9 += V_19 ;
}
if ( V_5 -> V_12 != NULL ) Free ( V_5 -> V_12 ) ;
V_5 -> V_12 = V_18 ;
V_5 -> V_13 = ( int ) V_19 ;
if ( V_2 != NULL ) ( * V_2 ) = V_5 ;
* V_3 = V_9 ;
return ( V_5 ) ;
V_24:
F_10 ( V_27 , V_7 ) ;
if ( ( V_5 != NULL ) && ( ( V_2 == NULL ) || ( * V_2 != V_5 ) ) )
F_4 ( V_5 ) ;
return ( NULL ) ;
}
int F_11 ( T_1 * V_2 , long V_28 )
{
int V_7 , V_29 , V_30 ;
unsigned char V_31 [ sizeof( long ) + 1 ] ;
long V_32 ;
V_2 -> type = V_14 ;
if ( V_2 -> V_13 < ( sizeof( long ) + 1 ) )
{
if ( V_2 -> V_12 != NULL )
Free ( V_2 -> V_12 ) ;
if ( ( V_2 -> V_12 = ( unsigned char * ) Malloc ( sizeof( long ) + 1 ) ) != NULL )
memset ( ( char * ) V_2 -> V_12 , 0 , sizeof( long ) + 1 ) ;
}
if ( V_2 -> V_12 == NULL )
{
F_10 ( V_33 , V_26 ) ;
return ( 0 ) ;
}
V_32 = V_28 ;
if ( V_32 < 0 )
{
V_32 = - V_32 ;
V_2 -> type = V_15 ;
}
for ( V_7 = 0 ; V_7 < sizeof( long ) ; V_7 ++ )
{
if ( V_32 == 0 ) break;
V_31 [ V_7 ] = ( int ) V_32 & 0xff ;
V_32 >>= 8 ;
}
V_29 = 0 ;
for ( V_30 = V_7 - 1 ; V_30 >= 0 ; V_30 -- )
V_2 -> V_12 [ V_29 ++ ] = V_31 [ V_30 ] ;
V_2 -> V_13 = V_29 ;
return ( 1 ) ;
}
long F_12 ( T_1 * V_2 )
{
int V_34 = 0 , V_7 ;
long V_6 = 0 ;
if ( V_2 == NULL ) return ( 0L ) ;
V_7 = V_2 -> type ;
if ( V_7 == V_15 )
V_34 = 1 ;
else if ( V_7 != V_14 )
return ( 0 ) ;
if ( V_2 -> V_13 > sizeof( long ) )
{
return ( 0xffffffffL ) ;
}
if ( V_2 -> V_12 == NULL )
return ( 0 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ )
{
V_6 <<= 8 ;
V_6 |= ( unsigned char ) V_2 -> V_12 [ V_7 ] ;
}
if ( V_34 ) V_6 = - V_6 ;
return ( V_6 ) ;
}
T_1 * F_13 ( T_2 * V_35 , T_1 * V_36 )
{
T_1 * V_5 ;
int V_19 , V_29 ;
if ( V_36 == NULL )
V_5 = F_2 () ;
else
V_5 = V_36 ;
if ( V_5 == NULL )
{
F_10 ( V_37 , V_38 ) ;
goto V_24;
}
if( V_35 -> V_34 ) V_5 -> type = V_15 ;
else V_5 -> type = V_14 ;
V_29 = F_14 ( V_35 ) ;
V_19 = ( ( V_29 == 0 ) ? 0 : ( ( V_29 / 8 ) + 1 ) ) ;
V_5 -> V_12 = ( unsigned char * ) Malloc ( V_19 + 4 ) ;
V_5 -> V_13 = F_15 ( V_35 , V_5 -> V_12 ) ;
return ( V_5 ) ;
V_24:
if ( V_5 != V_36 ) F_4 ( V_5 ) ;
return ( NULL ) ;
}
T_2 * F_16 ( T_1 * V_36 , T_2 * V_35 )
{
T_2 * V_5 ;
if ( ( V_5 = F_17 ( V_36 -> V_12 , V_36 -> V_13 , V_35 ) ) == NULL )
F_10 ( V_39 , V_40 ) ;
if( V_36 -> type == V_15 ) V_35 -> V_34 = 1 ;
return ( V_5 ) ;
}
