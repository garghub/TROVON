T_1 * F_1 ( const T_1 * V_1 )
{ return F_2 ( V_1 ) ; }
int F_3 ( const T_1 * V_1 , const T_1 * V_2 )
{
int V_3 , V_4 ;
V_3 = V_1 -> type & V_5 ;
if ( V_3 != ( V_2 -> type & V_5 ) )
{
if ( V_3 )
return - 1 ;
else
return 1 ;
}
V_4 = F_4 ( V_1 , V_2 ) ;
if ( V_3 )
return - V_4 ;
else
return V_4 ;
}
int F_5 ( T_1 * V_6 , unsigned char * * V_7 )
{
int V_8 = 0 , V_4 , V_9 , V_3 ;
unsigned char * V_10 , * V_11 , V_12 = 0 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_13 == NULL ) ) return ( 0 ) ;
V_3 = V_6 -> type & V_5 ;
if ( V_6 -> V_14 == 0 )
V_4 = 1 ;
else
{
V_4 = V_6 -> V_14 ;
V_9 = V_6 -> V_13 [ 0 ] ;
if ( ! V_3 && ( V_9 > 127 ) ) {
V_8 = 1 ;
V_12 = 0 ;
} else if( V_3 ) {
if( V_9 > 128 ) {
V_8 = 1 ;
V_12 = 0xFF ;
} else if( V_9 == 128 ) {
for( V_9 = 1 ; V_9 < V_6 -> V_14 ; V_9 ++ ) if( V_6 -> V_13 [ V_9 ] ) {
V_8 = 1 ;
V_12 = 0xFF ;
break;
}
}
}
V_4 += V_8 ;
}
if ( V_7 == NULL ) return ( V_4 ) ;
V_10 = * V_7 ;
if ( V_8 ) * ( V_10 ++ ) = V_12 ;
if ( V_6 -> V_14 == 0 ) * ( V_10 ++ ) = 0 ;
else if ( ! V_3 ) memcpy ( V_10 , V_6 -> V_13 , ( unsigned int ) V_6 -> V_14 ) ;
else {
V_11 = V_6 -> V_13 + V_6 -> V_14 - 1 ;
V_10 += V_6 -> V_14 - 1 ;
V_9 = V_6 -> V_14 ;
while( ! * V_11 ) {
* ( V_10 -- ) = 0 ;
V_11 -- ;
V_9 -- ;
}
* ( V_10 -- ) = ( ( * ( V_11 -- ) ) ^ 0xff ) + 1 ;
V_9 -- ;
for(; V_9 > 0 ; V_9 -- ) * ( V_10 -- ) = * ( V_11 -- ) ^ 0xff ;
}
* V_7 += V_4 ;
return ( V_4 ) ;
}
T_1 * F_6 ( T_1 * * V_6 , const unsigned char * * V_7 ,
long V_15 )
{
T_1 * V_4 = NULL ;
const unsigned char * V_10 , * V_16 ;
unsigned char * V_17 , * V_18 ;
int V_9 ;
if ( ( V_6 == NULL ) || ( ( * V_6 ) == NULL ) )
{
if ( ( V_4 = F_7 () ) == NULL ) return ( NULL ) ;
V_4 -> type = V_19 ;
}
else
V_4 = ( * V_6 ) ;
V_10 = * V_7 ;
V_16 = V_10 + V_15 ;
V_18 = ( unsigned char * ) F_8 ( ( int ) V_15 + 1 ) ;
if ( V_18 == NULL )
{
V_9 = V_20 ;
goto V_21;
}
V_17 = V_18 ;
if( ! V_15 ) {
V_4 -> type = V_19 ;
} else if ( * V_10 & 0x80 )
{
V_4 -> type = V_22 ;
if ( ( * V_10 == 0xff ) && ( V_15 != 1 ) ) {
V_10 ++ ;
V_15 -- ;
}
V_9 = V_15 ;
V_10 += V_9 - 1 ;
V_17 += V_9 - 1 ;
while( ( ! * V_10 ) && V_9 ) {
* ( V_17 -- ) = 0 ;
V_9 -- ;
V_10 -- ;
}
if( ! V_9 ) {
* V_18 = 1 ;
V_18 [ V_15 ] = 0 ;
V_15 ++ ;
} else {
* ( V_17 -- ) = ( * ( V_10 -- ) ^ 0xff ) + 1 ;
V_9 -- ;
for(; V_9 > 0 ; V_9 -- ) * ( V_17 -- ) = * ( V_10 -- ) ^ 0xff ;
}
} else {
V_4 -> type = V_19 ;
if ( ( * V_10 == 0 ) && ( V_15 != 1 ) )
{
V_10 ++ ;
V_15 -- ;
}
memcpy ( V_18 , V_10 , ( int ) V_15 ) ;
}
if ( V_4 -> V_13 != NULL ) F_9 ( V_4 -> V_13 ) ;
V_4 -> V_13 = V_18 ;
V_4 -> V_14 = ( int ) V_15 ;
if ( V_6 != NULL ) ( * V_6 ) = V_4 ;
* V_7 = V_16 ;
return ( V_4 ) ;
V_21:
F_10 ( V_23 , V_9 ) ;
if ( ( V_4 != NULL ) && ( ( V_6 == NULL ) || ( * V_6 != V_4 ) ) )
F_11 ( V_4 ) ;
return ( NULL ) ;
}
T_1 * F_12 ( T_1 * * V_6 , const unsigned char * * V_7 ,
long V_14 )
{
T_1 * V_4 = NULL ;
const unsigned char * V_10 ;
unsigned char * V_18 ;
long V_15 ;
int V_24 , V_25 , V_26 ;
int V_9 ;
if ( ( V_6 == NULL ) || ( ( * V_6 ) == NULL ) )
{
if ( ( V_4 = F_7 () ) == NULL ) return ( NULL ) ;
V_4 -> type = V_19 ;
}
else
V_4 = ( * V_6 ) ;
V_10 = * V_7 ;
V_24 = F_13 ( & V_10 , & V_15 , & V_25 , & V_26 , V_14 ) ;
if ( V_24 & 0x80 )
{
V_9 = V_27 ;
goto V_21;
}
if ( V_25 != V_19 )
{
V_9 = V_28 ;
goto V_21;
}
V_18 = ( unsigned char * ) F_8 ( ( int ) V_15 + 1 ) ;
if ( V_18 == NULL )
{
V_9 = V_20 ;
goto V_21;
}
V_4 -> type = V_19 ;
if( V_15 ) {
if ( ( * V_10 == 0 ) && ( V_15 != 1 ) )
{
V_10 ++ ;
V_15 -- ;
}
memcpy ( V_18 , V_10 , ( int ) V_15 ) ;
V_10 += V_15 ;
}
if ( V_4 -> V_13 != NULL ) F_9 ( V_4 -> V_13 ) ;
V_4 -> V_13 = V_18 ;
V_4 -> V_14 = ( int ) V_15 ;
if ( V_6 != NULL ) ( * V_6 ) = V_4 ;
* V_7 = V_10 ;
return ( V_4 ) ;
V_21:
F_10 ( V_29 , V_9 ) ;
if ( ( V_4 != NULL ) && ( ( V_6 == NULL ) || ( * V_6 != V_4 ) ) )
F_11 ( V_4 ) ;
return ( NULL ) ;
}
int F_14 ( T_1 * V_6 , long V_30 )
{
int V_31 , V_32 ;
unsigned int V_9 ;
unsigned char V_33 [ sizeof( long ) + 1 ] ;
long V_34 ;
V_6 -> type = V_19 ;
if ( V_6 -> V_14 < ( int ) ( sizeof( long ) + 1 ) )
{
if ( V_6 -> V_13 != NULL )
F_9 ( V_6 -> V_13 ) ;
if ( ( V_6 -> V_13 = ( unsigned char * ) F_8 ( sizeof( long ) + 1 ) ) != NULL )
memset ( ( char * ) V_6 -> V_13 , 0 , sizeof( long ) + 1 ) ;
}
if ( V_6 -> V_13 == NULL )
{
F_10 ( V_35 , V_20 ) ;
return ( 0 ) ;
}
V_34 = V_30 ;
if ( V_34 < 0 )
{
V_34 = - V_34 ;
V_6 -> type = V_22 ;
}
for ( V_9 = 0 ; V_9 < sizeof( long ) ; V_9 ++ )
{
if ( V_34 == 0 ) break;
V_33 [ V_9 ] = ( int ) V_34 & 0xff ;
V_34 >>= 8 ;
}
V_31 = 0 ;
for ( V_32 = V_9 - 1 ; V_32 >= 0 ; V_32 -- )
V_6 -> V_13 [ V_31 ++ ] = V_33 [ V_32 ] ;
V_6 -> V_14 = V_31 ;
return ( 1 ) ;
}
long F_15 ( const T_1 * V_6 )
{
int V_3 = 0 , V_9 ;
long V_36 = 0 ;
if ( V_6 == NULL ) return ( 0L ) ;
V_9 = V_6 -> type ;
if ( V_9 == V_22 )
V_3 = 1 ;
else if ( V_9 != V_19 )
return - 1 ;
if ( V_6 -> V_14 > ( int ) sizeof( long ) )
{
return - 1 ;
}
if ( V_6 -> V_13 == NULL )
return 0 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_14 ; V_9 ++ )
{
V_36 <<= 8 ;
V_36 |= ( unsigned char ) V_6 -> V_13 [ V_9 ] ;
}
if ( V_3 ) V_36 = - V_36 ;
return ( V_36 ) ;
}
T_1 * F_16 ( const T_2 * V_37 , T_1 * V_38 )
{
T_1 * V_4 ;
int V_15 , V_31 ;
if ( V_38 == NULL )
V_4 = F_7 () ;
else
V_4 = V_38 ;
if ( V_4 == NULL )
{
F_10 ( V_39 , V_40 ) ;
goto V_21;
}
if ( F_17 ( V_37 ) )
V_4 -> type = V_22 ;
else V_4 -> type = V_19 ;
V_31 = F_18 ( V_37 ) ;
V_15 = ( ( V_31 == 0 ) ? 0 : ( ( V_31 / 8 ) + 1 ) ) ;
if ( V_4 -> V_14 < V_15 + 4 )
{
unsigned char * V_41 = F_19 ( V_4 -> V_13 , V_15 + 4 ) ;
if ( ! V_41 )
{
F_10 ( V_39 , V_20 ) ;
goto V_21;
}
V_4 -> V_13 = V_41 ;
}
V_4 -> V_14 = F_20 ( V_37 , V_4 -> V_13 ) ;
if( ! V_4 -> V_14 )
{
V_4 -> V_13 [ 0 ] = 0 ;
V_4 -> V_14 = 1 ;
}
return ( V_4 ) ;
V_21:
if ( V_4 != V_38 ) F_11 ( V_4 ) ;
return ( NULL ) ;
}
T_2 * F_21 ( const T_1 * V_38 , T_2 * V_37 )
{
T_2 * V_4 ;
if ( ( V_4 = F_22 ( V_38 -> V_13 , V_38 -> V_14 , V_37 ) ) == NULL )
F_10 ( V_42 , V_43 ) ;
else if( V_38 -> type == V_22 )
F_23 ( V_4 , 1 ) ;
return ( V_4 ) ;
}
