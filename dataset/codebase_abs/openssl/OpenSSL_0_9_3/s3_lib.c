static long F_1 ( void )
{
return ( 60 * 60 * 2 ) ;
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
return ( V_5 -> V_6 -> V_7 . V_8 ) ;
}
int F_6 ( T_3 * V_5 )
{
T_4 * V_6 ;
if ( ( V_6 = ( T_4 * ) Malloc ( sizeof( T_4 ) ) ) == NULL ) goto V_9;
memset ( V_6 , 0 , sizeof( T_4 ) ) ;
V_5 -> V_6 = V_6 ;
V_5 -> V_10 -> V_11 ( V_5 ) ;
return ( 1 ) ;
V_9:
return ( 0 ) ;
}
void F_7 ( T_3 * V_5 )
{
if( V_5 == NULL )
return;
F_8 ( V_5 ) ;
if ( V_5 -> V_6 -> V_12 . V_13 != NULL )
Free ( V_5 -> V_6 -> V_12 . V_13 ) ;
if ( V_5 -> V_6 -> V_14 . V_13 != NULL )
Free ( V_5 -> V_6 -> V_14 . V_13 ) ;
if ( V_5 -> V_6 -> V_7 . V_15 != NULL )
Free ( V_5 -> V_6 -> V_7 . V_15 ) ;
#ifndef F_9
if ( V_5 -> V_6 -> V_16 . V_17 != NULL )
F_10 ( V_5 -> V_6 -> V_16 . V_17 ) ;
#endif
if ( V_5 -> V_6 -> V_16 . V_18 != NULL )
F_11 ( V_5 -> V_6 -> V_16 . V_18 , V_19 ) ;
memset ( V_5 -> V_6 , 0 , sizeof( T_4 ) ) ;
Free ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
}
void F_12 ( T_3 * V_5 )
{
unsigned char * V_20 , * V_21 ;
F_8 ( V_5 ) ;
if ( V_5 -> V_6 -> V_16 . V_18 != NULL )
F_11 ( V_5 -> V_6 -> V_16 . V_18 , V_19 ) ;
if ( V_5 -> V_6 -> V_7 . V_15 != NULL )
{
Free ( V_5 -> V_6 -> V_7 . V_15 ) ;
V_5 -> V_6 -> V_7 . V_15 = NULL ;
}
V_20 = V_5 -> V_6 -> V_12 . V_13 ;
V_21 = V_5 -> V_6 -> V_14 . V_13 ;
memset ( V_5 -> V_6 , 0 , sizeof( T_4 ) ) ;
if ( V_20 != NULL ) V_5 -> V_6 -> V_12 . V_13 = V_20 ;
if ( V_21 != NULL ) V_5 -> V_6 -> V_14 . V_13 = V_21 ;
F_13 ( V_5 ) ;
V_5 -> V_22 = 0 ;
V_5 -> V_6 -> V_23 = 0 ;
V_5 -> V_6 -> V_24 = 0 ;
V_5 -> V_6 -> V_25 = 0 ;
V_5 -> V_6 -> V_26 = 0 ;
V_5 -> V_27 = V_28 ;
}
long F_14 ( T_3 * V_5 , int V_29 , long V_30 , char * V_31 )
{
int V_32 = 0 ;
#if ! F_15 ( V_33 ) || ! F_15 ( V_34 )
if (
#ifndef V_34
V_29 == V_35 ||
V_29 == V_36 ||
#endif
#ifndef V_33
V_29 == V_37 ||
V_29 == V_38 ||
#endif
0 )
{
if ( ! F_16 ( & V_5 -> V_39 ) )
{
F_17 ( V_40 , V_41 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_29 )
{
case V_42 :
V_32 = V_5 -> V_43 ;
break;
case V_44 :
break;
case V_45 :
V_32 = V_5 -> V_6 -> V_25 ;
break;
case V_46 :
V_32 = V_5 -> V_6 -> V_25 ;
V_5 -> V_6 -> V_25 = 0 ;
break;
case V_47 :
V_32 = V_5 -> V_6 -> V_24 ;
break;
case V_48 :
V_32 = ( int ) ( V_5 -> V_6 -> V_49 ) ;
break;
#ifndef V_34
case V_50 :
if ( ( V_5 -> V_39 != NULL ) && ( V_5 -> V_39 -> V_51 == NULL ) &&
( ( V_5 -> V_39 -> V_52 [ V_53 ] . V_54 == NULL ) ||
( F_18 ( V_5 -> V_39 -> V_52 [ V_53 ] . V_54 ) > ( 512 / 8 ) ) ) )
V_32 = 1 ;
break;
case V_35 :
{
T_5 * V_55 = ( T_5 * ) V_31 ;
if ( V_55 == NULL ) {
F_17 ( V_40 , V_56 ) ;
return ( V_32 ) ;
}
if ( ( V_55 = F_19 ( V_55 ) ) == NULL ) {
F_17 ( V_40 , V_57 ) ;
return ( V_32 ) ;
}
if ( V_5 -> V_39 -> V_51 != NULL )
F_20 ( V_5 -> V_39 -> V_51 ) ;
V_5 -> V_39 -> V_51 = V_55 ;
V_32 = 1 ;
}
break;
case V_36 :
V_5 -> V_39 -> V_58 = ( T_5 * (*)( T_3 * , int , int ) ) V_31 ;
break;
#endif
#ifndef F_9
case V_37 :
{
T_6 * V_17 = ( T_6 * ) V_31 ;
if ( V_17 == NULL ) {
F_17 ( V_40 , V_56 ) ;
return ( V_32 ) ;
}
if ( ( V_17 = F_21 ( V_17 ) ) == NULL ) {
F_17 ( V_40 , V_59 ) ;
return ( V_32 ) ;
}
if ( ! F_22 ( V_17 ) ) {
F_10 ( V_17 ) ;
F_17 ( V_40 , V_59 ) ;
return ( V_32 ) ;
}
if ( V_5 -> V_39 -> V_60 != NULL )
F_10 ( V_5 -> V_39 -> V_60 ) ;
V_5 -> V_39 -> V_60 = V_17 ;
V_32 = 1 ;
}
break;
case V_38 :
V_5 -> V_39 -> V_61 = ( T_6 * (*)( T_3 * , int , int ) ) V_31 ;
break;
#endif
default:
break;
}
return ( V_32 ) ;
}
long F_23 ( T_7 * V_62 , int V_29 , long V_30 , char * V_31 )
{
T_8 * V_39 ;
V_39 = V_62 -> V_39 ;
switch ( V_29 )
{
#ifndef V_34
case V_50 :
if ( ( V_39 -> V_51 == NULL ) &&
( ( V_39 -> V_52 [ V_53 ] . V_54 == NULL ) ||
( F_18 ( V_39 -> V_52 [ V_53 ] . V_54 ) > ( 512 / 8 ) ) )
)
return ( 1 ) ;
else
return ( 0 ) ;
case V_35 :
{
T_5 * V_55 ;
int V_63 ;
V_55 = ( T_5 * ) V_31 ;
V_63 = 1 ;
if ( V_55 == NULL )
V_63 = 0 ;
else
{
if ( ( V_55 = F_19 ( V_55 ) ) == NULL )
V_63 = 0 ;
}
if ( ! V_63 )
{
F_17 ( V_64 , V_57 ) ;
return ( 0 ) ;
}
else
{
if ( V_39 -> V_51 != NULL )
F_20 ( V_39 -> V_51 ) ;
V_39 -> V_51 = V_55 ;
return ( 1 ) ;
}
}
case V_36 :
V_39 -> V_58 = ( T_5 * (*)( T_3 * , int , int ) ) V_31 ;
break;
#endif
#ifndef F_9
case V_37 :
{
T_6 * V_65 = NULL , * V_17 ;
int V_66 = 0 ;
V_17 = ( T_6 * ) V_31 ;
if ( ( ( V_65 = F_21 ( V_17 ) ) == NULL ) ||
( ! F_22 ( V_65 ) ) )
{
F_17 ( V_64 , V_59 ) ;
if ( V_65 != NULL ) F_10 ( V_65 ) ;
}
else
{
if ( V_39 -> V_60 != NULL )
F_10 ( V_39 -> V_60 ) ;
V_39 -> V_60 = V_65 ;
V_66 = 1 ;
}
return ( V_66 ) ;
}
case V_38 :
V_39 -> V_61 = ( T_6 * (*)( T_3 * , int , int ) ) V_31 ;
break;
#endif
case V_67 :
if ( V_62 -> V_68 == NULL )
{
if ( ( V_62 -> V_68 = F_24 () ) == NULL )
return ( 0 ) ;
}
F_25 ( V_62 -> V_68 , ( V_69 * ) V_31 ) ;
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
T_2 * F_26 ( const unsigned char * V_70 )
{
static int V_71 = 1 ;
static T_2 * V_72 [ V_2 ] ;
T_2 V_73 , * V_74 = & V_73 , * * V_75 ;
unsigned long V_76 ;
int V_63 ;
if ( V_71 )
{
F_27 ( V_77 ) ;
for ( V_63 = 0 ; V_63 < V_2 ; V_63 ++ )
V_72 [ V_63 ] = & ( V_4 [ V_63 ] ) ;
qsort ( (char *)sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
F_28 ( V_77 ) ;
V_71 = 0 ;
}
V_76 = 0x03000000L | ( ( unsigned long ) V_70 [ 0 ] << 8L ) | ( unsigned long ) V_70 [ 1 ] ;
V_73 . V_76 = V_76 ;
V_75 = ( T_2 * * ) F_29 ( ( char * ) & V_74 ,
( char * ) V_72 ,
V_2 , sizeof( T_2 * ) ,
( int ( * ) () ) V_78 ) ;
if ( ( V_75 == NULL ) || ! ( * V_75 ) -> V_79 )
return ( NULL ) ;
else
return ( * V_75 ) ;
}
int F_30 ( const T_2 * V_73 , unsigned char * V_70 )
{
long V_80 ;
if ( V_70 != NULL )
{
V_80 = V_73 -> V_76 ;
if ( ( V_80 & 0xff000000 ) != 0x03000000 ) return ( 0 ) ;
V_70 [ 0 ] = ( ( unsigned char ) ( V_80 >> 8L ) ) & 0xFF ;
V_70 [ 1 ] = ( ( unsigned char ) ( V_80 ) ) & 0xFF ;
}
return ( 2 ) ;
}
int F_31 ( T_3 * V_5 , int V_63 )
{
V_5 -> V_81 = V_82 ;
if ( V_63 < 0 )
{
return ( V_63 ) ;
}
else
{
V_5 -> V_83 += V_63 ;
return ( 0 ) ;
}
}
int F_32 ( T_3 * V_5 , unsigned char * V_70 )
{
int V_32 = 0 ;
unsigned long V_84 ;
V_84 = V_5 -> V_6 -> V_16 . V_85 -> V_86 ;
#ifndef F_9
if ( V_84 & ( V_87 | V_88 ) )
{
# ifndef V_34
V_70 [ V_32 ++ ] = V_89 ;
# endif
# ifndef V_33
V_70 [ V_32 ++ ] = V_90 ;
# endif
}
if ( ( V_5 -> V_27 == V_28 ) &&
( V_84 & ( V_88 | V_91 | V_87 ) ) )
{
# ifndef V_34
V_70 [ V_32 ++ ] = V_92 ;
# endif
# ifndef V_33
V_70 [ V_32 ++ ] = V_93 ;
# endif
}
#endif
#ifndef V_34
V_70 [ V_32 ++ ] = V_94 ;
#endif
#ifndef V_33
V_70 [ V_32 ++ ] = V_95 ;
#endif
return ( V_32 ) ;
}
int F_33 ( T_3 * V_5 )
{
if ( ( V_5 -> V_96 ) || ( V_5 -> V_97 == V_98 ) )
{
V_5 -> V_99 = ( V_100 | V_101 ) ;
return ( 1 ) ;
}
if ( ! ( V_5 -> V_99 & V_100 ) )
{
V_5 -> V_99 |= V_100 ;
#if 1
F_34 ( V_5 , V_102 , V_103 ) ;
#endif
}
else if ( V_5 -> V_6 -> V_104 )
{
#if 1
F_35 ( V_5 ) ;
#endif
}
else if ( ! ( V_5 -> V_99 & V_101 ) )
{
F_36 ( V_5 , 0 , NULL , 0 ) ;
}
if ( ( V_5 -> V_99 == ( V_100 | V_101 ) ) &&
! V_5 -> V_6 -> V_104 )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_37 ( T_3 * V_5 , const void * V_13 , int V_105 )
{
int V_32 , V_106 ;
#if 0
if (s->shutdown & SSL_SEND_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
F_38 () ;
if ( V_5 -> V_6 -> V_23 ) F_39 ( V_5 ) ;
if ( ( V_5 -> V_6 -> V_49 & V_107 ) && ( V_5 -> V_108 == V_5 -> V_109 ) )
{
if ( V_5 -> V_6 -> V_110 == 0 )
{
V_32 = F_40 ( V_5 , V_111 ,
V_13 , V_105 ) ;
if ( V_32 <= 0 ) return ( V_32 ) ;
V_5 -> V_6 -> V_110 = V_32 ;
}
V_5 -> V_81 = V_112 ;
V_106 = F_41 ( V_5 -> V_108 ) ;
if ( V_106 <= 0 ) return ( V_106 ) ;
V_5 -> V_81 = V_113 ;
F_13 ( V_5 ) ;
V_5 -> V_6 -> V_49 &= ~ V_107 ;
V_32 = V_5 -> V_6 -> V_110 ;
V_5 -> V_6 -> V_110 = 0 ;
}
else
{
V_32 = F_40 ( V_5 , V_111 ,
V_13 , V_105 ) ;
if ( V_32 <= 0 ) return ( V_32 ) ;
}
return ( V_32 ) ;
}
int F_42 ( T_3 * V_5 , void * V_13 , int V_105 )
{
int V_32 ;
F_38 () ;
if ( V_5 -> V_6 -> V_23 ) F_39 ( V_5 ) ;
V_5 -> V_6 -> V_26 = 1 ;
V_32 = F_36 ( V_5 , V_111 , V_13 , V_105 ) ;
if ( ( V_32 == - 1 ) && ( V_5 -> V_6 -> V_26 == 0 ) )
{
F_43 () ;
V_5 -> V_6 -> V_26 = 0 ;
V_5 -> V_114 ++ ;
V_32 = F_36 ( V_5 , V_111 , V_13 , V_105 ) ;
V_5 -> V_114 -- ;
}
else
V_5 -> V_6 -> V_26 = 0 ;
return ( V_32 ) ;
}
int F_44 ( T_3 * V_5 , char * V_13 , int V_105 )
{
T_9 * V_115 ;
int V_106 ;
V_115 = & ( V_5 -> V_6 -> V_7 ) ;
if ( ( V_115 -> V_8 == 0 ) || ( V_115 -> type != V_111 ) )
{
V_106 = F_42 ( V_5 , V_13 , 1 ) ;
if ( V_106 <= 0 ) return ( V_106 ) ;
V_115 -> V_8 ++ ;
V_115 -> V_116 -- ;
}
if ( ( unsigned int ) V_105 > V_115 -> V_8 )
V_106 = V_115 -> V_8 ;
else
V_106 = V_105 ;
memcpy ( V_13 , & ( V_115 -> V_117 [ V_115 -> V_116 ] ) , ( unsigned int ) V_106 ) ;
return ( V_106 ) ;
}
int F_45 ( T_3 * V_5 )
{
if ( V_5 -> V_118 == NULL )
return ( 1 ) ;
if ( V_5 -> V_6 -> V_49 & V_119 )
return ( 0 ) ;
V_5 -> V_6 -> V_23 = 1 ;
return ( 1 ) ;
}
int F_39 ( T_3 * V_5 )
{
int V_32 = 0 ;
if ( V_5 -> V_6 -> V_23 )
{
if ( ( V_5 -> V_6 -> V_12 . V_120 == 0 ) &&
( V_5 -> V_6 -> V_14 . V_120 == 0 ) &&
! F_46 ( V_5 ) )
{
V_5 -> V_97 = V_121 ;
V_5 -> V_6 -> V_23 = 0 ;
V_5 -> V_6 -> V_25 ++ ;
V_5 -> V_6 -> V_24 ++ ;
V_32 = 1 ;
}
}
return ( V_32 ) ;
}
