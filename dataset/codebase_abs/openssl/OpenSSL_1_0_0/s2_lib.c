long F_1 ( void )
{
return ( 300 ) ;
}
int F_2 ( void )
{
return ( V_1 ) ;
}
const T_1 * F_3 ( unsigned int V_2 )
{
if ( V_2 < V_1 )
return ( & ( V_3 [ V_1 - 1 - V_2 ] ) ) ;
else
return ( NULL ) ;
}
int F_4 ( const T_2 * V_4 )
{
return F_5 ( V_4 ) ? 0 : V_4 -> V_5 -> V_6 ;
}
int F_6 ( T_2 * V_4 )
{
T_3 * V_5 ;
if ( ( V_5 = F_7 ( sizeof *V_5 ) ) == NULL ) goto V_7;
memset ( V_5 , 0 , sizeof *V_5 ) ;
#if V_8 + 3 > V_9 + 2
# error "assertion failed"
#endif
if ( ( V_5 -> V_10 = F_7 (
V_9 + 2 ) ) == NULL ) goto V_7;
if ( ( V_5 -> V_11 = F_7 (
V_9 + 3 ) ) == NULL ) goto V_7;
V_4 -> V_5 = V_5 ;
F_8 ( V_4 ) ;
return ( 1 ) ;
V_7:
if ( V_5 != NULL )
{
if ( V_5 -> V_11 != NULL ) F_9 ( V_5 -> V_11 ) ;
if ( V_5 -> V_10 != NULL ) F_9 ( V_5 -> V_10 ) ;
F_9 ( V_5 ) ;
}
return ( 0 ) ;
}
void F_10 ( T_2 * V_4 )
{
T_3 * V_5 ;
if( V_4 == NULL )
return;
V_5 = V_4 -> V_5 ;
if ( V_5 -> V_10 != NULL ) F_9 ( V_5 -> V_10 ) ;
if ( V_5 -> V_11 != NULL ) F_9 ( V_5 -> V_11 ) ;
F_11 ( V_5 , sizeof *V_5 ) ;
F_9 ( V_5 ) ;
V_4 -> V_5 = NULL ;
}
void F_8 ( T_2 * V_4 )
{
T_3 * V_5 ;
unsigned char * V_10 , * V_11 ;
V_5 = V_4 -> V_5 ;
V_10 = V_5 -> V_10 ;
V_11 = V_5 -> V_11 ;
memset ( V_5 , 0 , sizeof *V_5 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_12 = 1 ;
V_4 -> V_13 = V_5 -> V_10 ;
V_4 -> V_14 = V_15 ;
V_4 -> V_16 = 0 ;
}
long F_12 ( T_2 * V_4 , int V_17 , long V_18 , void * V_19 )
{
int V_20 = 0 ;
switch( V_17 )
{
case V_21 :
V_20 = V_4 -> V_22 ;
break;
default:
break;
}
return ( V_20 ) ;
}
long F_13 ( T_2 * V_4 , int V_17 , void (* F_14)( void ) )
{
return ( 0 ) ;
}
long F_15 ( T_4 * V_23 , int V_17 , long V_18 , void * V_19 )
{
return ( 0 ) ;
}
long F_16 ( T_4 * V_23 , int V_17 , void (* F_14)( void ) )
{
return ( 0 ) ;
}
const T_1 * F_17 ( const unsigned char * V_24 )
{
T_1 V_25 ;
const T_1 * V_26 ;
unsigned long V_27 ;
V_27 = 0x02000000L | ( ( unsigned long ) V_24 [ 0 ] << 16L ) |
( ( unsigned long ) V_24 [ 1 ] << 8L ) | ( unsigned long ) V_24 [ 2 ] ;
V_25 . V_27 = V_27 ;
V_26 = F_18 ( & V_25 , V_3 , V_1 ) ;
if ( ( V_26 == NULL ) || ( V_26 -> V_28 == 0 ) )
return NULL ;
else
return V_26 ;
}
int F_19 ( const T_1 * V_25 , unsigned char * V_24 )
{
long V_29 ;
if ( V_24 != NULL )
{
V_29 = V_25 -> V_27 ;
if ( ( V_29 & 0xff000000 ) != 0x02000000 ) return ( 0 ) ;
V_24 [ 0 ] = ( ( unsigned char ) ( V_29 >> 16L ) ) & 0xFF ;
V_24 [ 1 ] = ( ( unsigned char ) ( V_29 >> 8L ) ) & 0xFF ;
V_24 [ 2 ] = ( ( unsigned char ) ( V_29 ) ) & 0xFF ;
}
return ( 3 ) ;
}
int F_20 ( T_2 * V_4 )
{
unsigned int V_30 ;
T_5 V_23 ;
unsigned char * V_31 ;
unsigned char V_25 = '0' ;
const T_6 * V_32 ;
int V_33 ;
V_32 = F_21 () ;
#ifdef F_22
V_25 = V_34 [ '0' ] ;
#endif
F_23 ( & V_23 ) ;
V_31 = V_4 -> V_5 -> V_35 ;
if ( V_4 -> V_36 -> V_37 < 0 ||
V_4 -> V_36 -> V_37 > ( int ) sizeof( V_4 -> V_36 -> V_38 ) )
{
F_24 ( V_39 , V_40 ) ;
return 0 ;
}
V_33 = F_25 ( V_32 ) ;
if ( V_33 < 0 )
return 0 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_5 -> V_41 ; V_30 += V_33 )
{
if ( ( ( V_31 - V_4 -> V_5 -> V_35 ) + V_33 ) >
( int ) sizeof( V_4 -> V_5 -> V_35 ) )
{
F_24 ( V_39 , V_40 ) ;
return 0 ;
}
F_26 ( & V_23 , V_32 , NULL ) ;
F_27 ( V_4 -> V_36 -> V_37 >= 0
&& V_4 -> V_36 -> V_37
< ( int ) sizeof( V_4 -> V_36 -> V_38 ) ) ;
F_28 ( & V_23 , V_4 -> V_36 -> V_38 , V_4 -> V_36 -> V_37 ) ;
F_28 ( & V_23 , & V_25 , 1 ) ;
V_25 ++ ;
F_28 ( & V_23 , V_4 -> V_5 -> V_42 , V_4 -> V_5 -> V_43 ) ;
F_28 ( & V_23 , V_4 -> V_5 -> V_44 , V_4 -> V_5 -> V_45 ) ;
F_29 ( & V_23 , V_31 , NULL ) ;
V_31 += V_33 ;
}
F_30 ( & V_23 ) ;
return 1 ;
}
void F_31 ( T_2 * V_4 , int V_7 )
{
if ( ! V_4 -> error )
{
V_4 -> error = 3 ;
V_4 -> V_46 = V_7 ;
F_32 ( V_4 ) ;
}
}
void F_32 ( T_2 * V_4 )
{
unsigned char V_47 [ 3 ] ;
int V_30 , error ;
V_47 [ 0 ] = V_48 ;
V_47 [ 1 ] = ( V_4 -> V_46 >> 8 ) & 0xff ;
V_47 [ 2 ] = ( V_4 -> V_46 ) & 0xff ;
error = V_4 -> error ;
V_4 -> error = 0 ;
F_27 ( error >= 0 && error <= ( int ) sizeof( V_47 ) ) ;
V_30 = F_33 ( V_4 , & ( V_47 [ 3 - error ] ) , error ) ;
if ( V_30 < 0 )
V_4 -> error = error ;
else
{
V_4 -> error = error - V_30 ;
if ( V_4 -> error == 0 )
if ( V_4 -> V_49 )
V_4 -> V_49 ( 1 , V_4 -> V_14 , 0 , V_47 , 3 , V_4 , V_4 -> V_50 ) ;
}
}
int F_34 ( T_2 * V_4 )
{
V_4 -> V_51 = ( V_52 | V_53 ) ;
return ( 1 ) ;
}
