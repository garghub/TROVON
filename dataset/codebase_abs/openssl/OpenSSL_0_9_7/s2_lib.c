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
return F_6 ( V_5 ) ? 0 : V_5 -> V_6 -> V_7 ;
}
int F_7 ( T_3 * V_5 )
{
T_4 * V_6 ;
if ( ( V_6 = F_8 ( sizeof *V_6 ) ) == NULL ) goto V_8;
memset ( V_6 , 0 , sizeof *V_6 ) ;
#if V_9 + 3 > V_10 + 2
# error "assertion failed"
#endif
if ( ( V_6 -> V_11 = F_8 (
V_10 + 2 ) ) == NULL ) goto V_8;
if ( ( V_6 -> V_12 = F_8 (
V_10 + 3 ) ) == NULL ) goto V_8;
V_5 -> V_6 = V_6 ;
F_9 ( V_5 ) ;
return ( 1 ) ;
V_8:
if ( V_6 != NULL )
{
if ( V_6 -> V_12 != NULL ) F_10 ( V_6 -> V_12 ) ;
if ( V_6 -> V_11 != NULL ) F_10 ( V_6 -> V_11 ) ;
F_10 ( V_6 ) ;
}
return ( 0 ) ;
}
void F_11 ( T_3 * V_5 )
{
T_4 * V_6 ;
if( V_5 == NULL )
return;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_11 != NULL ) F_10 ( V_6 -> V_11 ) ;
if ( V_6 -> V_12 != NULL ) F_10 ( V_6 -> V_12 ) ;
F_12 ( V_6 , sizeof *V_6 ) ;
F_10 ( V_6 ) ;
V_5 -> V_6 = NULL ;
}
void F_9 ( T_3 * V_5 )
{
T_4 * V_6 ;
unsigned char * V_11 , * V_12 ;
V_6 = V_5 -> V_6 ;
V_11 = V_6 -> V_11 ;
V_12 = V_6 -> V_12 ;
memset ( V_6 , 0 , sizeof *V_6 ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_13 = 1 ;
V_5 -> V_14 = V_6 -> V_11 ;
V_5 -> V_15 = V_16 ;
V_5 -> V_17 = 0 ;
}
long F_13 ( T_3 * V_5 , int V_18 , long V_19 , void * V_20 )
{
int V_21 = 0 ;
switch( V_18 )
{
case V_22 :
V_21 = V_5 -> V_23 ;
break;
default:
break;
}
return ( V_21 ) ;
}
long F_14 ( T_3 * V_5 , int V_18 , void (* F_15)() )
{
return ( 0 ) ;
}
long F_16 ( T_5 * V_24 , int V_18 , long V_19 , void * V_20 )
{
return ( 0 ) ;
}
long F_17 ( T_5 * V_24 , int V_18 , void (* F_15)() )
{
return ( 0 ) ;
}
T_2 * F_18 ( const unsigned char * V_25 )
{
static int V_26 = 1 ;
static T_2 * V_27 [ V_2 ] ;
T_2 V_28 , * V_29 = & V_28 , * * V_30 ;
unsigned long V_31 ;
int V_32 ;
if ( V_26 )
{
F_19 ( V_33 ) ;
if ( V_26 )
{
for ( V_32 = 0 ; V_32 < V_2 ; V_32 ++ )
V_27 [ V_32 ] = & ( V_4 [ V_32 ] ) ;
qsort ((char *)sorted,
SSL2_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
V_26 = 0 ;
}
F_20 ( V_33 ) ;
}
V_31 = 0x02000000L | ( ( unsigned long ) V_25 [ 0 ] << 16L ) |
( ( unsigned long ) V_25 [ 1 ] << 8L ) | ( unsigned long ) V_25 [ 2 ] ;
V_28 . V_31 = V_31 ;
V_30 = ( T_2 * * ) F_21 ((char *)&cp,
(char *)sorted,
SSL2_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
if ( ( V_30 == NULL ) || ! ( * V_30 ) -> V_34 )
return ( NULL ) ;
else
return ( * V_30 ) ;
}
int F_22 ( const T_2 * V_28 , unsigned char * V_25 )
{
long V_35 ;
if ( V_25 != NULL )
{
V_35 = V_28 -> V_31 ;
if ( ( V_35 & 0xff000000 ) != 0x02000000 ) return ( 0 ) ;
V_25 [ 0 ] = ( ( unsigned char ) ( V_35 >> 16L ) ) & 0xFF ;
V_25 [ 1 ] = ( ( unsigned char ) ( V_35 >> 8L ) ) & 0xFF ;
V_25 [ 2 ] = ( ( unsigned char ) ( V_35 ) ) & 0xFF ;
}
return ( 3 ) ;
}
int F_23 ( T_3 * V_5 )
{
unsigned int V_32 ;
T_6 V_24 ;
unsigned char * V_36 ;
unsigned char V_28 = '0' ;
const T_7 * V_37 ;
V_37 = F_24 () ;
#ifdef F_25
V_28 = V_38 [ '0' ] ;
#endif
F_26 ( & V_24 ) ;
V_36 = V_5 -> V_6 -> V_39 ;
if ( V_5 -> V_40 -> V_41 < 0 || V_5 -> V_40 -> V_41 > sizeof V_5 -> V_40 -> V_42 )
{
F_27 ( V_43 , V_44 ) ;
return 0 ;
}
for ( V_32 = 0 ; V_32 < V_5 -> V_6 -> V_45 ; V_32 += F_28 ( V_37 ) )
{
if ( ( ( V_36 - V_5 -> V_6 -> V_39 ) + F_28 ( V_37 ) ) > sizeof V_5 -> V_6 -> V_39 )
{
F_27 ( V_43 , V_44 ) ;
return 0 ;
}
F_29 ( & V_24 , V_37 , NULL ) ;
F_30 ( V_5 -> V_40 -> V_41 >= 0
&& V_5 -> V_40 -> V_41
< sizeof V_5 -> V_40 -> V_42 ) ;
F_31 ( & V_24 , V_5 -> V_40 -> V_42 , V_5 -> V_40 -> V_41 ) ;
F_31 ( & V_24 , & V_28 , 1 ) ;
V_28 ++ ;
F_31 ( & V_24 , V_5 -> V_6 -> V_46 , V_5 -> V_6 -> V_47 ) ;
F_31 ( & V_24 , V_5 -> V_6 -> V_48 , V_5 -> V_6 -> V_49 ) ;
F_32 ( & V_24 , V_36 , NULL ) ;
V_36 += F_28 ( V_37 ) ;
}
F_33 ( & V_24 ) ;
return 1 ;
}
void F_34 ( T_3 * V_5 , int V_8 )
{
if ( ! V_5 -> error )
{
V_5 -> error = 3 ;
V_5 -> V_50 = V_8 ;
F_35 ( V_5 ) ;
}
}
void F_35 ( T_3 * V_5 )
{
unsigned char V_51 [ 3 ] ;
int V_32 , error ;
V_51 [ 0 ] = V_52 ;
V_51 [ 1 ] = ( V_5 -> V_50 >> 8 ) & 0xff ;
V_51 [ 2 ] = ( V_5 -> V_50 ) & 0xff ;
error = V_5 -> error ;
V_5 -> error = 0 ;
F_30 ( error >= 0 && error <= sizeof V_51 ) ;
V_32 = F_36 ( V_5 , & ( V_51 [ 3 - error ] ) , error ) ;
if ( V_32 < 0 )
V_5 -> error = error ;
else
{
V_5 -> error = error - V_32 ;
if ( V_5 -> error == 0 )
if ( V_5 -> V_53 )
V_5 -> V_53 ( 1 , V_5 -> V_15 , 0 , V_51 , 3 , V_5 , V_5 -> V_54 ) ;
}
}
int F_37 ( T_3 * V_5 )
{
V_5 -> V_55 = ( V_56 | V_57 ) ;
return ( 1 ) ;
}
