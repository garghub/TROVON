static long F_1 ( void )
{
return ( 300 ) ;
}
T_1 * F_2 ( void )
{
return ( & V_1 ) ;
}
int F_3 ( void )
{
return ( V_2 ) ;
}
T_2 * F_4 ( unsigned int V_3 )
{
if ( V_3 < V_2 )
return ( & ( V_4 [ V_2 - 1 - V_3 ] ) ) ;
else
return ( NULL ) ;
}
int F_5 ( T_3 * V_5 )
{
return ( V_5 -> V_6 -> V_7 ) ;
}
int F_6 ( T_3 * V_5 )
{
T_4 * V_6 ;
if ( ( V_6 = Malloc ( sizeof *V_6 ) ) == NULL ) goto V_8;
memset ( V_6 , 0 , sizeof *V_6 ) ;
if ( ( V_6 -> V_9 = Malloc (
V_10 + 2 ) ) == NULL ) goto V_8;
if ( ( V_6 -> V_11 = Malloc (
V_10 + 2 ) ) == NULL ) goto V_8;
V_5 -> V_6 = V_6 ;
F_7 ( V_5 ) ;
return ( 1 ) ;
V_8:
if ( V_6 != NULL )
{
if ( V_6 -> V_11 != NULL ) Free ( V_6 -> V_11 ) ;
if ( V_6 -> V_9 != NULL ) Free ( V_6 -> V_9 ) ;
Free ( V_6 ) ;
}
return ( 0 ) ;
}
void F_8 ( T_3 * V_5 )
{
T_4 * V_6 ;
if( V_5 == NULL )
return;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_9 != NULL ) Free ( V_6 -> V_9 ) ;
if ( V_6 -> V_11 != NULL ) Free ( V_6 -> V_11 ) ;
memset ( V_6 , 0 , sizeof *V_6 ) ;
Free ( V_6 ) ;
V_5 -> V_6 = NULL ;
}
void F_7 ( T_3 * V_5 )
{
T_4 * V_6 ;
unsigned char * V_9 , * V_11 ;
V_6 = V_5 -> V_6 ;
V_9 = V_6 -> V_9 ;
V_11 = V_6 -> V_11 ;
memset ( V_6 , 0 , sizeof *V_6 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_12 = 1 ;
V_5 -> V_13 = V_6 -> V_9 ;
V_5 -> V_14 = V_15 ;
V_5 -> V_16 = 0 ;
}
long F_9 ( T_3 * V_5 , int V_17 , long V_18 , char * V_19 )
{
int V_20 = 0 ;
switch( V_17 )
{
case V_21 :
V_20 = V_5 -> V_22 ;
break;
default:
break;
}
return ( V_20 ) ;
}
long F_10 ( T_3 * V_5 , int V_17 , void (* F_11)() )
{
return ( 0 ) ;
}
long F_12 ( T_5 * V_23 , int V_17 , long V_18 , char * V_19 )
{
return ( 0 ) ;
}
long F_13 ( T_5 * V_23 , int V_17 , void (* F_11)() )
{
return ( 0 ) ;
}
T_2 * F_14 ( const unsigned char * V_24 )
{
static int V_25 = 1 ;
static T_2 * V_26 [ V_2 ] ;
T_2 V_27 , * V_28 = & V_27 , * * V_29 ;
unsigned long V_30 ;
int V_31 ;
if ( V_25 )
{
F_15 ( V_32 ) ;
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ )
V_26 [ V_31 ] = & ( V_4 [ V_31 ] ) ;
qsort ( (char *)sorted,
SSL2_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
F_16 ( V_32 ) ;
V_25 = 0 ;
}
V_30 = 0x02000000L | ( ( unsigned long ) V_24 [ 0 ] << 16L ) |
( ( unsigned long ) V_24 [ 1 ] << 8L ) | ( unsigned long ) V_24 [ 2 ] ;
V_27 . V_30 = V_30 ;
V_29 = ( T_2 * * ) F_17 ( ( char * ) & V_28 ,
( char * ) V_26 ,
V_2 , sizeof( T_2 * ) ,
( int ( * ) () ) V_33 ) ;
if ( ( V_29 == NULL ) || ! ( * V_29 ) -> V_34 )
return ( NULL ) ;
else
return ( * V_29 ) ;
}
int F_18 ( const T_2 * V_27 , unsigned char * V_24 )
{
long V_35 ;
if ( V_24 != NULL )
{
V_35 = V_27 -> V_30 ;
if ( ( V_35 & 0xff000000 ) != 0x02000000 ) return ( 0 ) ;
V_24 [ 0 ] = ( ( unsigned char ) ( V_35 >> 16L ) ) & 0xFF ;
V_24 [ 1 ] = ( ( unsigned char ) ( V_35 >> 8L ) ) & 0xFF ;
V_24 [ 2 ] = ( ( unsigned char ) ( V_35 ) ) & 0xFF ;
}
return ( 3 ) ;
}
void F_19 ( T_3 * V_5 )
{
unsigned int V_31 ;
T_6 V_23 ;
unsigned char * V_36 ;
unsigned char V_27 = '0' ;
#ifdef F_20
V_27 = V_37 [ '0' ] ;
#endif
V_36 = V_5 -> V_6 -> V_38 ;
for ( V_31 = 0 ; V_31 < V_5 -> V_6 -> V_39 ; V_31 += V_40 )
{
F_21 ( & V_23 ) ;
F_22 ( & V_23 , V_5 -> V_41 -> V_42 , V_5 -> V_41 -> V_43 ) ;
F_22 ( & V_23 , & V_27 , 1 ) ;
V_27 ++ ;
F_22 ( & V_23 , V_5 -> V_6 -> V_44 , V_5 -> V_6 -> V_45 ) ;
F_22 ( & V_23 , V_5 -> V_6 -> V_46 , V_5 -> V_6 -> V_47 ) ;
F_23 ( V_36 , & V_23 ) ;
V_36 += V_40 ;
}
}
void F_24 ( T_3 * V_5 , int V_8 )
{
if ( ! V_5 -> error )
{
V_5 -> error = 3 ;
V_5 -> V_48 = V_8 ;
F_25 ( V_5 ) ;
}
}
void F_25 ( T_3 * V_5 )
{
unsigned char V_49 [ 3 ] ;
int V_31 , error ;
V_49 [ 0 ] = V_50 ;
V_49 [ 1 ] = ( V_5 -> V_48 >> 8 ) & 0xff ;
V_49 [ 2 ] = ( V_5 -> V_48 ) & 0xff ;
error = V_5 -> error ;
V_5 -> error = 0 ;
V_31 = F_26 ( V_5 , & ( V_49 [ 3 - error ] ) , error ) ;
if ( V_31 < 0 )
V_5 -> error = error ;
else if ( V_31 != V_5 -> error )
V_5 -> error = error - V_31 ;
}
int F_27 ( T_3 * V_5 )
{
V_5 -> V_51 = ( V_52 | V_53 ) ;
return ( 1 ) ;
}
