T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
T_1 * F_5 ( T_1 * V_1 )
{ return F_6 ( V_1 ) ; }
int F_7 ( T_1 * V_1 , T_1 * V_2 )
{ return F_8 ( V_1 , V_2 ) ; }
int F_9 ( T_1 * V_3 , unsigned char * * V_4 )
{
int V_5 , V_6 ;
if( ! V_3 ) return 0 ;
V_5 = F_10 ( V_3 , NULL ) ;
V_6 = F_11 ( 0 , V_5 , V_7 ) ;
if( V_4 ) {
F_12 ( V_4 , 0 , V_5 , V_7 , V_8 ) ;
F_10 ( V_3 , V_4 ) ;
}
return V_6 ;
}
int F_10 ( T_1 * V_3 , unsigned char * * V_4 )
{
int V_9 = 0 , V_6 , V_10 , V_11 ;
unsigned char * V_12 , * V_13 , V_14 = 0 ;
if ( ( V_3 == NULL ) || ( V_3 -> V_15 == NULL ) ) return ( 0 ) ;
V_11 = V_3 -> type & V_16 ;
if ( V_3 -> V_17 == 0 )
V_6 = 1 ;
else
{
V_6 = V_3 -> V_17 ;
V_10 = V_3 -> V_15 [ 0 ] ;
if ( ! V_11 && ( V_10 > 127 ) ) {
V_9 = 1 ;
V_14 = 0 ;
} else if( V_11 ) {
if( V_10 > 128 ) {
V_9 = 1 ;
V_14 = 0xFF ;
} else if( V_10 == 128 ) {
for( V_10 = 1 ; V_10 < V_3 -> V_17 ; V_10 ++ ) if( V_3 -> V_15 [ V_10 ] ) {
V_9 = 1 ;
V_14 = 0xFF ;
break;
}
}
}
V_6 += V_9 ;
}
if ( V_4 == NULL ) return ( V_6 ) ;
V_12 = * V_4 ;
if ( V_9 ) * ( V_12 ++ ) = V_14 ;
if ( V_3 -> V_17 == 0 ) * ( V_12 ++ ) = 0 ;
else if ( ! V_11 ) memcpy ( V_12 , V_3 -> V_15 , ( unsigned int ) V_3 -> V_17 ) ;
else {
V_13 = V_3 -> V_15 + V_3 -> V_17 - 1 ;
V_12 += V_3 -> V_17 - 1 ;
V_10 = V_3 -> V_17 ;
while( ! * V_13 ) {
* ( V_12 -- ) = 0 ;
V_13 -- ;
V_10 -- ;
}
* ( V_12 -- ) = ( ( * ( V_13 -- ) ) ^ 0xff ) + 1 ;
V_10 -- ;
for(; V_10 > 0 ; V_10 -- ) * ( V_12 -- ) = * ( V_13 -- ) ^ 0xff ;
}
* V_4 += V_6 ;
return ( V_6 ) ;
}
T_1 * F_13 ( T_1 * * V_3 , unsigned char * * V_4 ,
long V_17 )
{
unsigned char * V_12 ;
long V_5 ;
int V_10 ;
int V_18 , V_19 , V_20 ;
T_1 * V_6 ;
V_12 = * V_4 ;
V_18 = F_14 ( & V_12 , & V_5 , & V_19 , & V_20 , V_17 ) ;
if ( V_18 & 0x80 )
{
V_10 = V_21 ;
goto V_22;
}
if ( V_19 != V_7 )
{
V_10 = V_23 ;
goto V_22;
}
V_6 = F_15 ( V_3 , & V_12 , V_5 ) ;
if( V_6 ) * V_4 = V_12 ;
return V_6 ;
V_22:
F_16 ( V_24 , V_10 ) ;
return ( NULL ) ;
}
T_1 * F_15 ( T_1 * * V_3 , unsigned char * * V_4 ,
long V_5 )
{
T_1 * V_6 = NULL ;
unsigned char * V_12 , * V_25 , * V_26 , * V_27 ;
int V_10 ;
if ( ( V_3 == NULL ) || ( ( * V_3 ) == NULL ) )
{
if ( ( V_6 = F_2 () ) == NULL ) return ( NULL ) ;
V_6 -> type = V_7 ;
}
else
V_6 = ( * V_3 ) ;
V_12 = * V_4 ;
V_27 = V_12 + V_5 ;
V_26 = ( unsigned char * ) F_17 ( ( int ) V_5 + 1 ) ;
if ( V_26 == NULL )
{
V_10 = V_28 ;
goto V_22;
}
V_25 = V_26 ;
if( ! V_5 ) {
V_6 -> type = V_7 ;
} else if ( * V_12 & 0x80 )
{
V_6 -> type = V_29 ;
if ( ( * V_12 == 0xff ) && ( V_5 != 1 ) ) {
V_12 ++ ;
V_5 -- ;
}
V_10 = V_5 ;
V_12 += V_10 - 1 ;
V_25 += V_10 - 1 ;
while( ( ! * V_12 ) && V_10 ) {
* ( V_25 -- ) = 0 ;
V_10 -- ;
V_12 -- ;
}
if( ! V_10 ) {
* V_26 = 1 ;
V_26 [ V_5 ] = 0 ;
V_5 ++ ;
} else {
* ( V_25 -- ) = ( * ( V_12 -- ) ^ 0xff ) + 1 ;
V_10 -- ;
for(; V_10 > 0 ; V_10 -- ) * ( V_25 -- ) = * ( V_12 -- ) ^ 0xff ;
}
} else {
V_6 -> type = V_7 ;
if ( ( * V_12 == 0 ) && ( V_5 != 1 ) )
{
V_12 ++ ;
V_5 -- ;
}
memcpy ( V_26 , V_12 , ( int ) V_5 ) ;
}
if ( V_6 -> V_15 != NULL ) F_18 ( V_6 -> V_15 ) ;
V_6 -> V_15 = V_26 ;
V_6 -> V_17 = ( int ) V_5 ;
if ( V_3 != NULL ) ( * V_3 ) = V_6 ;
* V_4 = V_27 ;
return ( V_6 ) ;
V_22:
F_16 ( V_24 , V_10 ) ;
if ( ( V_6 != NULL ) && ( ( V_3 == NULL ) || ( * V_3 != V_6 ) ) )
F_4 ( V_6 ) ;
return ( NULL ) ;
}
T_1 * F_19 ( T_1 * * V_3 , unsigned char * * V_4 ,
long V_17 )
{
T_1 * V_6 = NULL ;
unsigned char * V_12 , * V_25 , * V_26 ;
long V_5 ;
int V_18 , V_19 , V_20 ;
int V_10 ;
if ( ( V_3 == NULL ) || ( ( * V_3 ) == NULL ) )
{
if ( ( V_6 = F_2 () ) == NULL ) return ( NULL ) ;
V_6 -> type = V_7 ;
}
else
V_6 = ( * V_3 ) ;
V_12 = * V_4 ;
V_18 = F_14 ( & V_12 , & V_5 , & V_19 , & V_20 , V_17 ) ;
if ( V_18 & 0x80 )
{
V_10 = V_21 ;
goto V_22;
}
if ( V_19 != V_7 )
{
V_10 = V_23 ;
goto V_22;
}
V_26 = ( unsigned char * ) F_17 ( ( int ) V_5 + 1 ) ;
if ( V_26 == NULL )
{
V_10 = V_28 ;
goto V_22;
}
V_25 = V_26 ;
V_6 -> type = V_7 ;
if( V_5 ) {
if ( ( * V_12 == 0 ) && ( V_5 != 1 ) )
{
V_12 ++ ;
V_5 -- ;
}
memcpy ( V_26 , V_12 , ( int ) V_5 ) ;
V_12 += V_5 ;
}
if ( V_6 -> V_15 != NULL ) F_18 ( V_6 -> V_15 ) ;
V_6 -> V_15 = V_26 ;
V_6 -> V_17 = ( int ) V_5 ;
if ( V_3 != NULL ) ( * V_3 ) = V_6 ;
* V_4 = V_12 ;
return ( V_6 ) ;
V_22:
F_16 ( V_30 , V_10 ) ;
if ( ( V_6 != NULL ) && ( ( V_3 == NULL ) || ( * V_3 != V_6 ) ) )
F_4 ( V_6 ) ;
return ( NULL ) ;
}
int F_20 ( T_1 * V_3 , long V_31 )
{
int V_10 , V_32 , V_33 ;
unsigned char V_34 [ sizeof( long ) + 1 ] ;
long V_35 ;
V_3 -> type = V_7 ;
if ( V_3 -> V_17 < ( sizeof( long ) + 1 ) )
{
if ( V_3 -> V_15 != NULL )
F_18 ( V_3 -> V_15 ) ;
if ( ( V_3 -> V_15 = ( unsigned char * ) F_17 ( sizeof( long ) + 1 ) ) != NULL )
memset ( ( char * ) V_3 -> V_15 , 0 , sizeof( long ) + 1 ) ;
}
if ( V_3 -> V_15 == NULL )
{
F_16 ( V_36 , V_28 ) ;
return ( 0 ) ;
}
V_35 = V_31 ;
if ( V_35 < 0 )
{
V_35 = - V_35 ;
V_3 -> type = V_29 ;
}
for ( V_10 = 0 ; V_10 < sizeof( long ) ; V_10 ++ )
{
if ( V_35 == 0 ) break;
V_34 [ V_10 ] = ( int ) V_35 & 0xff ;
V_35 >>= 8 ;
}
V_32 = 0 ;
for ( V_33 = V_10 - 1 ; V_33 >= 0 ; V_33 -- )
V_3 -> V_15 [ V_32 ++ ] = V_34 [ V_33 ] ;
V_3 -> V_17 = V_32 ;
return ( 1 ) ;
}
long F_21 ( T_1 * V_3 )
{
int V_11 = 0 , V_10 ;
long V_37 = 0 ;
if ( V_3 == NULL ) return ( 0L ) ;
V_10 = V_3 -> type ;
if ( V_10 == V_29 )
V_11 = 1 ;
else if ( V_10 != V_7 )
return ( 0 ) ;
if ( V_3 -> V_17 > sizeof( long ) )
{
return ( 0xffffffffL ) ;
}
if ( V_3 -> V_15 == NULL )
return ( 0 ) ;
for ( V_10 = 0 ; V_10 < V_3 -> V_17 ; V_10 ++ )
{
V_37 <<= 8 ;
V_37 |= ( unsigned char ) V_3 -> V_15 [ V_10 ] ;
}
if ( V_11 ) V_37 = - V_37 ;
return ( V_37 ) ;
}
T_1 * F_22 ( T_2 * V_38 , T_1 * V_39 )
{
T_1 * V_6 ;
int V_5 , V_32 ;
if ( V_39 == NULL )
V_6 = F_2 () ;
else
V_6 = V_39 ;
if ( V_6 == NULL )
{
F_16 ( V_40 , V_41 ) ;
goto V_22;
}
if( V_38 -> V_11 ) V_6 -> type = V_29 ;
else V_6 -> type = V_7 ;
V_32 = F_23 ( V_38 ) ;
V_5 = ( ( V_32 == 0 ) ? 0 : ( ( V_32 / 8 ) + 1 ) ) ;
V_6 -> V_15 = ( unsigned char * ) F_17 ( V_5 + 4 ) ;
V_6 -> V_17 = F_24 ( V_38 , V_6 -> V_15 ) ;
return ( V_6 ) ;
V_22:
if ( V_6 != V_39 ) F_4 ( V_6 ) ;
return ( NULL ) ;
}
T_2 * F_25 ( T_1 * V_39 , T_2 * V_38 )
{
T_2 * V_6 ;
if ( ( V_6 = F_26 ( V_39 -> V_15 , V_39 -> V_17 , V_38 ) ) == NULL )
F_16 ( V_42 , V_43 ) ;
else if( V_39 -> type == V_29 ) V_6 -> V_11 = 1 ;
return ( V_6 ) ;
}
