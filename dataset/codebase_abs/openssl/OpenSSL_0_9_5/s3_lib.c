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
if ( ( V_6 = Malloc ( sizeof *V_6 ) ) == NULL ) goto V_9;
memset ( V_6 , 0 , sizeof *V_6 ) ;
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
memset ( V_5 -> V_6 , 0 , sizeof * V_5 -> V_6 ) ;
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
#ifndef F_9
if ( V_5 -> V_6 -> V_16 . V_17 != NULL )
F_10 ( V_5 -> V_6 -> V_16 . V_17 ) ;
#endif
V_20 = V_5 -> V_6 -> V_12 . V_13 ;
V_21 = V_5 -> V_6 -> V_14 . V_13 ;
memset ( V_5 -> V_6 , 0 , sizeof * V_5 -> V_6 ) ;
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
{
F_17 ( V_40 , V_58 ) ;
return ( V_32 ) ;
}
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
{
F_17 ( V_40 , V_58 ) ;
return ( V_32 ) ;
}
break;
#endif
default:
break;
}
return ( V_32 ) ;
}
long F_23 ( T_3 * V_5 , int V_29 , void (* F_24)() )
{
int V_32 = 0 ;
#if ! F_15 ( V_33 ) || ! F_15 ( V_34 )
if (
#ifndef V_34
V_29 == V_36 ||
#endif
#ifndef V_33
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
#ifndef V_34
case V_36 :
{
V_5 -> V_39 -> V_61 = ( T_5 * (*)( T_3 * , int , int ) ) F_24 ;
}
break;
#endif
#ifndef F_9
case V_38 :
{
V_5 -> V_39 -> V_62 = ( T_6 * (*)( T_3 * , int , int ) ) F_24 ;
}
break;
#endif
default:
break;
}
return ( V_32 ) ;
}
long F_25 ( T_7 * V_63 , int V_29 , long V_30 , char * V_31 )
{
T_8 * V_39 ;
V_39 = V_63 -> V_39 ;
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
int V_64 ;
V_55 = ( T_5 * ) V_31 ;
V_64 = 1 ;
if ( V_55 == NULL )
V_64 = 0 ;
else
{
if ( ( V_55 = F_19 ( V_55 ) ) == NULL )
V_64 = 0 ;
}
if ( ! V_64 )
{
F_17 ( V_65 , V_57 ) ;
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
{
F_17 ( V_65 , V_58 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_9
case V_37 :
{
T_6 * V_66 = NULL , * V_17 ;
int V_67 = 0 ;
V_17 = ( T_6 * ) V_31 ;
if ( ( ( V_66 = F_21 ( V_17 ) ) == NULL ) ||
( ! F_22 ( V_66 ) ) )
{
F_17 ( V_65 , V_59 ) ;
if ( V_66 != NULL ) F_10 ( V_66 ) ;
}
else
{
if ( V_39 -> V_60 != NULL )
F_10 ( V_39 -> V_60 ) ;
V_39 -> V_60 = V_66 ;
V_67 = 1 ;
}
return ( V_67 ) ;
}
case V_38 :
{
F_17 ( V_65 , V_58 ) ;
return ( 0 ) ;
}
break;
#endif
case V_68 :
if ( V_63 -> V_69 == NULL )
{
if ( ( V_63 -> V_69 = F_26 () ) == NULL )
return ( 0 ) ;
}
F_27 ( V_63 -> V_69 , ( V_70 * ) V_31 ) ;
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
long F_28 ( T_7 * V_63 , int V_29 , void (* F_24)() )
{
T_8 * V_39 ;
V_39 = V_63 -> V_39 ;
switch ( V_29 )
{
#ifndef V_34
case V_36 :
{
V_39 -> V_61 = ( T_5 * (*)( T_3 * , int , int ) ) F_24 ;
}
break;
#endif
#ifndef F_9
case V_38 :
{
V_39 -> V_62 = ( T_6 * (*)( T_3 * , int , int ) ) F_24 ;
}
break;
#endif
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
T_2 * F_29 ( const unsigned char * V_71 )
{
static int V_72 = 1 ;
static T_2 * V_73 [ V_2 ] ;
T_2 V_74 , * V_75 = & V_74 , * * V_76 ;
unsigned long V_77 ;
int V_64 ;
if ( V_72 )
{
F_30 ( V_78 ) ;
for ( V_64 = 0 ; V_64 < V_2 ; V_64 ++ )
V_73 [ V_64 ] = & ( V_4 [ V_64 ] ) ;
qsort ( (char *)sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
F_31 ( V_78 ) ;
V_72 = 0 ;
}
V_77 = 0x03000000L | ( ( unsigned long ) V_71 [ 0 ] << 8L ) | ( unsigned long ) V_71 [ 1 ] ;
V_74 . V_77 = V_77 ;
V_76 = ( T_2 * * ) F_32 ( ( char * ) & V_75 ,
( char * ) V_73 ,
V_2 , sizeof( T_2 * ) ,
( int ( * ) () ) V_79 ) ;
if ( ( V_76 == NULL ) || ! ( * V_76 ) -> V_80 )
return ( NULL ) ;
else
return ( * V_76 ) ;
}
int F_33 ( const T_2 * V_74 , unsigned char * V_71 )
{
long V_81 ;
if ( V_71 != NULL )
{
V_81 = V_74 -> V_77 ;
if ( ( V_81 & 0xff000000 ) != 0x03000000 ) return ( 0 ) ;
V_71 [ 0 ] = ( ( unsigned char ) ( V_81 >> 8L ) ) & 0xFF ;
V_71 [ 1 ] = ( ( unsigned char ) ( V_81 ) ) & 0xFF ;
}
return ( 2 ) ;
}
int F_34 ( T_3 * V_5 , unsigned char * V_71 )
{
int V_32 = 0 ;
unsigned long V_82 ;
V_82 = V_5 -> V_6 -> V_16 . V_83 -> V_84 ;
#ifndef F_9
if ( V_82 & ( V_85 | V_86 ) )
{
# ifndef V_34
V_71 [ V_32 ++ ] = V_87 ;
# endif
# ifndef V_33
V_71 [ V_32 ++ ] = V_88 ;
# endif
}
if ( ( V_5 -> V_27 == V_28 ) &&
( V_82 & ( V_86 | V_89 | V_85 ) ) )
{
# ifndef V_34
V_71 [ V_32 ++ ] = V_90 ;
# endif
# ifndef V_33
V_71 [ V_32 ++ ] = V_91 ;
# endif
}
#endif
#ifndef V_34
V_71 [ V_32 ++ ] = V_92 ;
#endif
#ifndef V_33
V_71 [ V_32 ++ ] = V_93 ;
#endif
return ( V_32 ) ;
}
int F_35 ( T_3 * V_5 )
{
if ( ( V_5 -> V_94 ) || ( V_5 -> V_95 == V_96 ) )
{
V_5 -> V_97 = ( V_98 | V_99 ) ;
return ( 1 ) ;
}
if ( ! ( V_5 -> V_97 & V_98 ) )
{
V_5 -> V_97 |= V_98 ;
#if 1
F_36 ( V_5 , V_100 , V_101 ) ;
#endif
}
else if ( V_5 -> V_6 -> V_102 )
{
#if 1
F_37 ( V_5 ) ;
#endif
}
else if ( ! ( V_5 -> V_97 & V_99 ) )
{
F_38 ( V_5 , 0 , NULL , 0 ) ;
}
if ( ( V_5 -> V_97 == ( V_98 | V_99 ) ) &&
! V_5 -> V_6 -> V_102 )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_39 ( T_3 * V_5 , const void * V_13 , int V_103 )
{
int V_32 , V_104 ;
#if 0
if (s->shutdown & SSL_SEND_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
F_40 () ;
if ( V_5 -> V_6 -> V_23 ) F_41 ( V_5 ) ;
if ( ( V_5 -> V_6 -> V_49 & V_105 ) && ( V_5 -> V_106 == V_5 -> V_107 ) )
{
if ( V_5 -> V_6 -> V_108 == 0 )
{
V_32 = F_42 ( V_5 , V_109 ,
V_13 , V_103 ) ;
if ( V_32 <= 0 ) return ( V_32 ) ;
V_5 -> V_6 -> V_108 = V_32 ;
}
V_5 -> V_110 = V_111 ;
V_104 = F_43 ( V_5 -> V_106 ) ;
if ( V_104 <= 0 ) return ( V_104 ) ;
V_5 -> V_110 = V_112 ;
F_13 ( V_5 ) ;
V_5 -> V_6 -> V_49 &= ~ V_105 ;
V_32 = V_5 -> V_6 -> V_108 ;
V_5 -> V_6 -> V_108 = 0 ;
}
else
{
V_32 = F_42 ( V_5 , V_109 ,
V_13 , V_103 ) ;
if ( V_32 <= 0 ) return ( V_32 ) ;
}
return ( V_32 ) ;
}
int F_44 ( T_3 * V_5 , void * V_13 , int V_103 )
{
int V_32 ;
F_40 () ;
if ( V_5 -> V_6 -> V_23 ) F_41 ( V_5 ) ;
V_5 -> V_6 -> V_26 = 1 ;
V_32 = F_38 ( V_5 , V_109 , V_13 , V_103 ) ;
if ( ( V_32 == - 1 ) && ( V_5 -> V_6 -> V_26 == 0 ) )
{
V_5 -> V_113 ++ ;
V_32 = F_38 ( V_5 , V_109 , V_13 , V_103 ) ;
V_5 -> V_113 -- ;
}
else
V_5 -> V_6 -> V_26 = 0 ;
return ( V_32 ) ;
}
int F_45 ( T_3 * V_5 , char * V_13 , int V_103 )
{
T_9 * V_114 ;
int V_104 ;
V_114 = & ( V_5 -> V_6 -> V_7 ) ;
if ( ( V_114 -> V_8 == 0 ) || ( V_114 -> type != V_109 ) )
{
V_104 = F_44 ( V_5 , V_13 , 1 ) ;
if ( V_104 <= 0 ) return ( V_104 ) ;
V_114 -> V_8 ++ ;
V_114 -> V_115 -- ;
}
if ( ( unsigned int ) V_103 > V_114 -> V_8 )
V_104 = V_114 -> V_8 ;
else
V_104 = V_103 ;
memcpy ( V_13 , & ( V_114 -> V_116 [ V_114 -> V_115 ] ) , ( unsigned int ) V_104 ) ;
return ( V_104 ) ;
}
int F_46 ( T_3 * V_5 )
{
if ( V_5 -> V_117 == NULL )
return ( 1 ) ;
if ( V_5 -> V_6 -> V_49 & V_118 )
return ( 0 ) ;
V_5 -> V_6 -> V_23 = 1 ;
return ( 1 ) ;
}
int F_41 ( T_3 * V_5 )
{
int V_32 = 0 ;
if ( V_5 -> V_6 -> V_23 )
{
if ( ( V_5 -> V_6 -> V_12 . V_119 == 0 ) &&
( V_5 -> V_6 -> V_14 . V_119 == 0 ) &&
! F_47 ( V_5 ) )
{
V_5 -> V_95 = V_120 ;
V_5 -> V_6 -> V_23 = 0 ;
V_5 -> V_6 -> V_25 ++ ;
V_5 -> V_6 -> V_24 ++ ;
V_32 = 1 ;
}
}
return ( V_32 ) ;
}
