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
int V_5 = 0 , V_6 , V_7 , V_8 , V_9 ;
unsigned char * V_10 , * V_11 , V_12 = 0 ;
if ( ( V_3 == NULL ) || ( V_3 -> V_13 == NULL ) ) return ( 0 ) ;
V_9 = V_3 -> type ;
if ( V_3 -> V_14 == 0 )
V_6 = 1 ;
else
{
V_6 = V_3 -> V_14 ;
V_8 = V_3 -> V_13 [ 0 ] ;
if ( ( V_9 == V_15 ) && ( V_8 > 127 ) ) {
V_5 = 1 ;
V_12 = 0 ;
} else if( V_9 == V_16 ) {
if( V_8 > 128 ) {
V_5 = 1 ;
V_12 = 0xFF ;
} else if( V_8 == 128 ) {
for( V_8 = 1 ; V_8 < V_3 -> V_14 ; V_8 ++ ) if( V_3 -> V_13 [ V_8 ] ) {
V_5 = 1 ;
V_12 = 0xFF ;
break;
}
}
}
V_6 += V_5 ;
}
V_7 = F_10 ( 0 , V_6 , V_15 ) ;
if ( V_4 == NULL ) return ( V_7 ) ;
V_10 = * V_4 ;
F_11 ( & V_10 , 0 , V_6 , V_15 , V_17 ) ;
if ( V_5 ) * ( V_10 ++ ) = V_12 ;
if ( V_3 -> V_14 == 0 ) * ( V_10 ++ ) = 0 ;
else if ( V_9 == V_15 ) memcpy ( V_10 , V_3 -> V_13 , ( unsigned int ) V_3 -> V_14 ) ;
else {
V_11 = V_3 -> V_13 + V_3 -> V_14 - 1 ;
V_10 += V_3 -> V_14 - 1 ;
V_8 = V_3 -> V_14 ;
while( ! * V_11 ) {
* ( V_10 -- ) = 0 ;
V_11 -- ;
V_8 -- ;
}
* ( V_10 -- ) = ( ( * ( V_11 -- ) ) ^ 0xff ) + 1 ;
V_8 -- ;
for(; V_8 > 0 ; V_8 -- ) * ( V_10 -- ) = * ( V_11 -- ) ^ 0xff ;
}
* V_4 += V_7 ;
return ( V_7 ) ;
}
T_1 * F_12 ( T_1 * * V_3 , unsigned char * * V_4 ,
long V_14 )
{
T_1 * V_6 = NULL ;
unsigned char * V_10 , * V_18 , * V_19 , * V_20 ;
long V_21 ;
int V_22 , V_23 , V_24 ;
int V_8 ;
if ( ( V_3 == NULL ) || ( ( * V_3 ) == NULL ) )
{
if ( ( V_6 = F_2 () ) == NULL ) return ( NULL ) ;
V_6 -> type = V_15 ;
}
else
V_6 = ( * V_3 ) ;
V_10 = * V_4 ;
V_22 = F_13 ( & V_10 , & V_21 , & V_23 , & V_24 , V_14 ) ;
V_20 = V_10 + V_21 ;
if ( V_22 & 0x80 )
{
V_8 = V_25 ;
goto V_26;
}
if ( V_23 != V_15 )
{
V_8 = V_27 ;
goto V_26;
}
V_19 = ( unsigned char * ) Malloc ( ( int ) V_21 + 1 ) ;
if ( V_19 == NULL )
{
V_8 = V_28 ;
goto V_26;
}
V_18 = V_19 ;
if( ! V_21 ) {
V_6 -> type = V_15 ;
} else if ( * V_10 & 0x80 )
{
V_6 -> type = V_16 ;
if ( ( * V_10 == 0xff ) && ( V_21 != 1 ) ) {
V_10 ++ ;
V_21 -- ;
}
V_8 = V_21 ;
V_10 += V_8 - 1 ;
V_18 += V_8 - 1 ;
while( ( ! * V_10 ) && V_8 ) {
* ( V_18 -- ) = 0 ;
V_8 -- ;
V_10 -- ;
}
if( ! V_8 ) {
* V_19 = 1 ;
V_19 [ V_21 ] = 0 ;
V_21 ++ ;
} else {
* ( V_18 -- ) = ( * ( V_10 -- ) ^ 0xff ) + 1 ;
V_8 -- ;
for(; V_8 > 0 ; V_8 -- ) * ( V_18 -- ) = * ( V_10 -- ) ^ 0xff ;
}
} else {
V_6 -> type = V_15 ;
if ( ( * V_10 == 0 ) && ( V_21 != 1 ) )
{
V_10 ++ ;
V_21 -- ;
}
memcpy ( V_19 , V_10 , ( int ) V_21 ) ;
}
if ( V_6 -> V_13 != NULL ) Free ( V_6 -> V_13 ) ;
V_6 -> V_13 = V_19 ;
V_6 -> V_14 = ( int ) V_21 ;
if ( V_3 != NULL ) ( * V_3 ) = V_6 ;
* V_4 = V_20 ;
return ( V_6 ) ;
V_26:
F_14 ( V_29 , V_8 ) ;
if ( ( V_6 != NULL ) && ( ( V_3 == NULL ) || ( * V_3 != V_6 ) ) )
F_4 ( V_6 ) ;
return ( NULL ) ;
}
T_1 * F_15 ( T_1 * * V_3 , unsigned char * * V_4 ,
long V_14 )
{
T_1 * V_6 = NULL ;
unsigned char * V_10 , * V_18 , * V_19 ;
long V_21 ;
int V_22 , V_23 , V_24 ;
int V_8 ;
if ( ( V_3 == NULL ) || ( ( * V_3 ) == NULL ) )
{
if ( ( V_6 = F_2 () ) == NULL ) return ( NULL ) ;
V_6 -> type = V_15 ;
}
else
V_6 = ( * V_3 ) ;
V_10 = * V_4 ;
V_22 = F_13 ( & V_10 , & V_21 , & V_23 , & V_24 , V_14 ) ;
if ( V_22 & 0x80 )
{
V_8 = V_25 ;
goto V_26;
}
if ( V_23 != V_15 )
{
V_8 = V_27 ;
goto V_26;
}
V_19 = ( unsigned char * ) Malloc ( ( int ) V_21 + 1 ) ;
if ( V_19 == NULL )
{
V_8 = V_28 ;
goto V_26;
}
V_18 = V_19 ;
V_6 -> type = V_15 ;
if( V_21 ) {
if ( ( * V_10 == 0 ) && ( V_21 != 1 ) )
{
V_10 ++ ;
V_21 -- ;
}
memcpy ( V_19 , V_10 , ( int ) V_21 ) ;
V_10 += V_21 ;
}
if ( V_6 -> V_13 != NULL ) Free ( V_6 -> V_13 ) ;
V_6 -> V_13 = V_19 ;
V_6 -> V_14 = ( int ) V_21 ;
if ( V_3 != NULL ) ( * V_3 ) = V_6 ;
* V_4 = V_10 ;
return ( V_6 ) ;
V_26:
F_14 ( V_30 , V_8 ) ;
if ( ( V_6 != NULL ) && ( ( V_3 == NULL ) || ( * V_3 != V_6 ) ) )
F_4 ( V_6 ) ;
return ( NULL ) ;
}
int F_16 ( T_1 * V_3 , long V_31 )
{
int V_8 , V_32 , V_33 ;
unsigned char V_34 [ sizeof( long ) + 1 ] ;
long V_35 ;
V_3 -> type = V_15 ;
if ( V_3 -> V_14 < ( sizeof( long ) + 1 ) )
{
if ( V_3 -> V_13 != NULL )
Free ( V_3 -> V_13 ) ;
if ( ( V_3 -> V_13 = ( unsigned char * ) Malloc ( sizeof( long ) + 1 ) ) != NULL )
memset ( ( char * ) V_3 -> V_13 , 0 , sizeof( long ) + 1 ) ;
}
if ( V_3 -> V_13 == NULL )
{
F_14 ( V_36 , V_28 ) ;
return ( 0 ) ;
}
V_35 = V_31 ;
if ( V_35 < 0 )
{
V_35 = - V_35 ;
V_3 -> type = V_16 ;
}
for ( V_8 = 0 ; V_8 < sizeof( long ) ; V_8 ++ )
{
if ( V_35 == 0 ) break;
V_34 [ V_8 ] = ( int ) V_35 & 0xff ;
V_35 >>= 8 ;
}
V_32 = 0 ;
for ( V_33 = V_8 - 1 ; V_33 >= 0 ; V_33 -- )
V_3 -> V_13 [ V_32 ++ ] = V_34 [ V_33 ] ;
V_3 -> V_14 = V_32 ;
return ( 1 ) ;
}
long F_17 ( T_1 * V_3 )
{
int V_37 = 0 , V_8 ;
long V_7 = 0 ;
if ( V_3 == NULL ) return ( 0L ) ;
V_8 = V_3 -> type ;
if ( V_8 == V_16 )
V_37 = 1 ;
else if ( V_8 != V_15 )
return ( 0 ) ;
if ( V_3 -> V_14 > sizeof( long ) )
{
return ( 0xffffffffL ) ;
}
if ( V_3 -> V_13 == NULL )
return ( 0 ) ;
for ( V_8 = 0 ; V_8 < V_3 -> V_14 ; V_8 ++ )
{
V_7 <<= 8 ;
V_7 |= ( unsigned char ) V_3 -> V_13 [ V_8 ] ;
}
if ( V_37 ) V_7 = - V_7 ;
return ( V_7 ) ;
}
T_1 * F_18 ( T_2 * V_38 , T_1 * V_39 )
{
T_1 * V_6 ;
int V_21 , V_32 ;
if ( V_39 == NULL )
V_6 = F_2 () ;
else
V_6 = V_39 ;
if ( V_6 == NULL )
{
F_14 ( V_40 , V_41 ) ;
goto V_26;
}
if( V_38 -> V_37 ) V_6 -> type = V_16 ;
else V_6 -> type = V_15 ;
V_32 = F_19 ( V_38 ) ;
V_21 = ( ( V_32 == 0 ) ? 0 : ( ( V_32 / 8 ) + 1 ) ) ;
V_6 -> V_13 = ( unsigned char * ) Malloc ( V_21 + 4 ) ;
V_6 -> V_14 = F_20 ( V_38 , V_6 -> V_13 ) ;
return ( V_6 ) ;
V_26:
if ( V_6 != V_39 ) F_4 ( V_6 ) ;
return ( NULL ) ;
}
T_2 * F_21 ( T_1 * V_39 , T_2 * V_38 )
{
T_2 * V_6 ;
if ( ( V_6 = F_22 ( V_39 -> V_13 , V_39 -> V_14 , V_38 ) ) == NULL )
F_14 ( V_42 , V_43 ) ;
if( V_39 -> type == V_16 ) V_38 -> V_37 = 1 ;
return ( V_6 ) ;
}
