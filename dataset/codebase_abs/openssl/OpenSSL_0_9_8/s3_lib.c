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
int F_5 ( const T_3 * V_5 )
{
if ( V_5 -> V_6 == V_7 )
return 0 ;
return ( V_5 -> V_8 -> V_9 . type == V_10 ) ? V_5 -> V_8 -> V_9 . V_11 : 0 ;
}
int F_6 ( T_3 * V_5 )
{
T_4 * V_8 ;
if ( ( V_8 = F_7 ( sizeof *V_8 ) ) == NULL ) goto V_12;
memset ( V_8 , 0 , sizeof *V_8 ) ;
F_8 ( & V_8 -> V_13 ) ;
F_8 ( & V_8 -> V_14 ) ;
F_9 ( & ( V_8 -> V_9 . V_15 ) ) ;
F_9 ( & ( V_8 -> V_16 . V_15 ) ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_17 -> V_18 ( V_5 ) ;
return ( 1 ) ;
V_12:
return ( 0 ) ;
}
void F_10 ( T_3 * V_5 )
{
if( V_5 == NULL )
return;
F_11 ( V_5 ) ;
if ( V_5 -> V_8 -> V_19 . V_20 != NULL )
F_12 ( V_5 -> V_8 -> V_19 . V_20 ) ;
if ( V_5 -> V_8 -> V_21 . V_20 != NULL )
F_12 ( V_5 -> V_8 -> V_21 . V_20 ) ;
if ( V_5 -> V_8 -> V_9 . V_22 != NULL )
F_12 ( V_5 -> V_8 -> V_9 . V_22 ) ;
#ifndef F_13
if ( V_5 -> V_8 -> V_23 . V_24 != NULL )
F_14 ( V_5 -> V_8 -> V_23 . V_24 ) ;
#endif
#ifndef F_15
if ( V_5 -> V_8 -> V_23 . V_25 != NULL )
F_16 ( V_5 -> V_8 -> V_23 . V_25 ) ;
#endif
if ( V_5 -> V_8 -> V_23 . V_26 != NULL )
F_17 ( V_5 -> V_8 -> V_23 . V_26 , V_27 ) ;
F_18 ( & V_5 -> V_8 -> V_13 ) ;
F_18 ( & V_5 -> V_8 -> V_14 ) ;
F_19 ( & ( V_5 -> V_8 -> V_9 . V_15 ) ) ;
F_19 ( & ( V_5 -> V_8 -> V_16 . V_15 ) ) ;
F_20 ( V_5 -> V_8 , sizeof * V_5 -> V_8 ) ;
F_12 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
void F_21 ( T_3 * V_5 )
{
unsigned char * V_28 , * V_29 ;
T_5 V_30 , V_31 ;
F_11 ( V_5 ) ;
if ( V_5 -> V_8 -> V_23 . V_26 != NULL )
F_17 ( V_5 -> V_8 -> V_23 . V_26 , V_27 ) ;
if ( V_5 -> V_8 -> V_9 . V_22 != NULL )
{
F_12 ( V_5 -> V_8 -> V_9 . V_22 ) ;
V_5 -> V_8 -> V_9 . V_22 = NULL ;
}
#ifndef F_13
if ( V_5 -> V_8 -> V_23 . V_24 != NULL )
F_14 ( V_5 -> V_8 -> V_23 . V_24 ) ;
#endif
#ifndef F_15
if ( V_5 -> V_8 -> V_23 . V_25 != NULL )
F_16 ( V_5 -> V_8 -> V_23 . V_25 ) ;
#endif
V_28 = V_5 -> V_8 -> V_19 . V_20 ;
V_29 = V_5 -> V_8 -> V_21 . V_20 ;
V_30 = V_5 -> V_8 -> V_19 . V_32 ;
V_31 = V_5 -> V_8 -> V_21 . V_32 ;
F_18 ( & V_5 -> V_8 -> V_13 ) ;
F_18 ( & V_5 -> V_8 -> V_14 ) ;
memset ( V_5 -> V_8 , 0 , sizeof * V_5 -> V_8 ) ;
V_5 -> V_8 -> V_19 . V_20 = V_28 ;
V_5 -> V_8 -> V_21 . V_20 = V_29 ;
V_5 -> V_8 -> V_19 . V_32 = V_30 ;
V_5 -> V_8 -> V_21 . V_32 = V_31 ;
F_22 ( V_5 ) ;
V_5 -> V_33 = 0 ;
V_5 -> V_8 -> V_34 = 0 ;
V_5 -> V_8 -> V_35 = 0 ;
V_5 -> V_8 -> V_36 = 0 ;
V_5 -> V_8 -> V_37 = 0 ;
V_5 -> V_38 = V_39 ;
}
long F_23 ( T_3 * V_5 , int V_40 , long V_41 , void * V_42 )
{
int V_43 = 0 ;
#if ! F_24 ( V_44 ) || ! F_24 ( V_45 )
if (
#ifndef V_45
V_40 == V_46 ||
V_40 == V_47 ||
#endif
#ifndef V_44
V_40 == V_48 ||
V_40 == V_49 ||
#endif
0 )
{
if ( ! F_25 ( & V_5 -> V_50 ) )
{
F_26 ( V_51 , V_52 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_40 )
{
case V_53 :
V_43 = V_5 -> V_54 ;
break;
case V_55 :
break;
case V_56 :
V_43 = V_5 -> V_8 -> V_36 ;
break;
case V_57 :
V_43 = V_5 -> V_8 -> V_36 ;
V_5 -> V_8 -> V_36 = 0 ;
break;
case V_58 :
V_43 = V_5 -> V_8 -> V_35 ;
break;
case V_59 :
V_43 = ( int ) ( V_5 -> V_8 -> V_60 ) ;
break;
#ifndef V_45
case V_61 :
if ( ( V_5 -> V_50 != NULL ) && ( V_5 -> V_50 -> V_62 == NULL ) &&
( ( V_5 -> V_50 -> V_63 [ V_64 ] . V_65 == NULL ) ||
( F_27 ( V_5 -> V_50 -> V_63 [ V_64 ] . V_65 ) > ( 512 / 8 ) ) ) )
V_43 = 1 ;
break;
case V_46 :
{
T_6 * V_66 = ( T_6 * ) V_42 ;
if ( V_66 == NULL )
{
F_26 ( V_51 , V_67 ) ;
return ( V_43 ) ;
}
if ( ( V_66 = F_28 ( V_66 ) ) == NULL )
{
F_26 ( V_51 , V_68 ) ;
return ( V_43 ) ;
}
if ( V_5 -> V_50 -> V_62 != NULL )
F_29 ( V_5 -> V_50 -> V_62 ) ;
V_5 -> V_50 -> V_62 = V_66 ;
V_43 = 1 ;
}
break;
case V_47 :
{
F_26 ( V_51 , V_69 ) ;
return ( V_43 ) ;
}
break;
#endif
#ifndef F_13
case V_48 :
{
T_7 * V_24 = ( T_7 * ) V_42 ;
if ( V_24 == NULL )
{
F_26 ( V_51 , V_67 ) ;
return ( V_43 ) ;
}
if ( ( V_24 = F_30 ( V_24 ) ) == NULL )
{
F_26 ( V_51 , V_70 ) ;
return ( V_43 ) ;
}
if ( ! ( V_5 -> V_71 & V_72 ) )
{
if ( ! F_31 ( V_24 ) )
{
F_14 ( V_24 ) ;
F_26 ( V_51 , V_70 ) ;
return ( V_43 ) ;
}
}
if ( V_5 -> V_50 -> V_73 != NULL )
F_14 ( V_5 -> V_50 -> V_73 ) ;
V_5 -> V_50 -> V_73 = V_24 ;
V_43 = 1 ;
}
break;
case V_49 :
{
F_26 ( V_51 , V_69 ) ;
return ( V_43 ) ;
}
break;
#endif
#ifndef F_15
case V_74 :
{
T_8 * V_25 = NULL ;
if ( V_42 == NULL )
{
F_26 ( V_51 , V_67 ) ;
return ( V_43 ) ;
}
if ( ! F_32 ( ( T_8 * ) V_42 ) )
{
F_26 ( V_51 , V_75 ) ;
return ( V_43 ) ;
}
V_25 = ( T_8 * ) V_42 ;
if ( ! ( V_5 -> V_71 & V_76 ) )
{
if ( ! F_33 ( V_25 ) )
{
F_16 ( V_25 ) ;
F_26 ( V_51 , V_75 ) ;
return ( V_43 ) ;
}
}
if ( V_5 -> V_50 -> V_77 != NULL )
F_16 ( V_5 -> V_50 -> V_77 ) ;
V_5 -> V_50 -> V_77 = V_25 ;
V_43 = 1 ;
}
break;
case V_78 :
{
F_26 ( V_51 , V_69 ) ;
return ( V_43 ) ;
}
break;
#endif
default:
break;
}
return ( V_43 ) ;
}
long F_34 ( T_3 * V_5 , int V_40 , void (* F_35)( void ) )
{
int V_43 = 0 ;
#if ! F_24 ( V_44 ) || ! F_24 ( V_45 )
if (
#ifndef V_45
V_40 == V_47 ||
#endif
#ifndef V_44
V_40 == V_49 ||
#endif
0 )
{
if ( ! F_25 ( & V_5 -> V_50 ) )
{
F_26 ( V_79 , V_52 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_40 )
{
#ifndef V_45
case V_47 :
{
V_5 -> V_50 -> V_80 = ( T_6 * (*)( T_3 * , int , int ) ) F_35 ;
}
break;
#endif
#ifndef F_13
case V_49 :
{
V_5 -> V_50 -> V_81 = ( T_7 * (*)( T_3 * , int , int ) ) F_35 ;
}
break;
#endif
#ifndef F_15
case V_78 :
{
V_5 -> V_50 -> V_82 = ( T_8 * (*)( T_3 * , int , int ) ) F_35 ;
}
break;
#endif
default:
break;
}
return ( V_43 ) ;
}
long F_36 ( T_9 * V_83 , int V_40 , long V_41 , void * V_42 )
{
T_10 * V_50 ;
V_50 = V_83 -> V_50 ;
switch ( V_40 )
{
#ifndef V_45
case V_61 :
if ( ( V_50 -> V_62 == NULL ) &&
( ( V_50 -> V_63 [ V_64 ] . V_65 == NULL ) ||
( F_27 ( V_50 -> V_63 [ V_64 ] . V_65 ) > ( 512 / 8 ) ) )
)
return ( 1 ) ;
else
return ( 0 ) ;
case V_46 :
{
T_6 * V_66 ;
int V_84 ;
V_66 = ( T_6 * ) V_42 ;
V_84 = 1 ;
if ( V_66 == NULL )
V_84 = 0 ;
else
{
if ( ( V_66 = F_28 ( V_66 ) ) == NULL )
V_84 = 0 ;
}
if ( ! V_84 )
{
F_26 ( V_85 , V_68 ) ;
return ( 0 ) ;
}
else
{
if ( V_50 -> V_62 != NULL )
F_29 ( V_50 -> V_62 ) ;
V_50 -> V_62 = V_66 ;
return ( 1 ) ;
}
}
case V_47 :
{
F_26 ( V_85 , V_69 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_13
case V_48 :
{
T_7 * V_86 = NULL , * V_24 ;
V_24 = ( T_7 * ) V_42 ;
if ( ( V_86 = F_30 ( V_24 ) ) == NULL )
{
F_26 ( V_85 , V_70 ) ;
return 0 ;
}
if ( ! ( V_83 -> V_71 & V_72 ) )
{
if ( ! F_31 ( V_86 ) )
{
F_26 ( V_85 , V_70 ) ;
F_14 ( V_86 ) ;
return 0 ;
}
}
if ( V_50 -> V_73 != NULL )
F_14 ( V_50 -> V_73 ) ;
V_50 -> V_73 = V_86 ;
return 1 ;
}
case V_49 :
{
F_26 ( V_85 , V_69 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_15
case V_74 :
{
T_8 * V_25 = NULL ;
if ( V_42 == NULL )
{
F_26 ( V_85 , V_75 ) ;
return 0 ;
}
if ( ! F_32 ( ( T_8 * ) V_42 ) )
{
F_26 ( V_85 , V_75 ) ;
return 0 ;
}
V_25 = ( T_8 * ) V_42 ;
if ( ! ( V_83 -> V_71 & V_76 ) )
{
if ( ! F_33 ( V_25 ) )
{
F_16 ( V_25 ) ;
F_26 ( V_85 , V_75 ) ;
return 0 ;
}
}
if ( V_50 -> V_77 != NULL )
{
F_16 ( V_50 -> V_77 ) ;
}
V_50 -> V_77 = V_25 ;
return 1 ;
}
case V_78 :
{
F_26 ( V_85 , V_69 ) ;
return ( 0 ) ;
}
break;
#endif
case V_87 :
if ( V_83 -> V_88 == NULL )
{
if ( ( V_83 -> V_88 = F_37 () ) == NULL )
return ( 0 ) ;
}
F_38 ( V_83 -> V_88 , ( V_89 * ) V_42 ) ;
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
long F_39 ( T_9 * V_83 , int V_40 , void (* F_35)( void ) )
{
T_10 * V_50 ;
V_50 = V_83 -> V_50 ;
switch ( V_40 )
{
#ifndef V_45
case V_47 :
{
V_50 -> V_80 = ( T_6 * (*)( T_3 * , int , int ) ) F_35 ;
}
break;
#endif
#ifndef F_13
case V_49 :
{
V_50 -> V_81 = ( T_7 * (*)( T_3 * , int , int ) ) F_35 ;
}
break;
#endif
#ifndef F_15
case V_78 :
{
V_50 -> V_82 = ( T_8 * (*)( T_3 * , int , int ) ) F_35 ;
}
break;
#endif
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
T_2 * F_40 ( const unsigned char * V_90 )
{
static int V_91 = 1 ;
static T_2 * V_92 [ V_2 ] ;
T_2 V_93 , * V_94 = & V_93 , * * V_95 ;
unsigned long V_96 ;
unsigned int V_84 ;
if ( V_91 )
{
F_41 ( V_97 ) ;
if ( V_91 )
{
for ( V_84 = 0 ; V_84 < V_2 ; V_84 ++ )
V_92 [ V_84 ] = & ( V_4 [ V_84 ] ) ;
qsort (sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
V_91 = 0 ;
}
F_42 ( V_97 ) ;
}
V_96 = 0x03000000L | ( ( unsigned long ) V_90 [ 0 ] << 8L ) | ( unsigned long ) V_90 [ 1 ] ;
V_93 . V_96 = V_96 ;
V_95 = ( T_2 * * ) F_43 ((char *)&cp,
(char *)sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
if ( ( V_95 == NULL ) || ! ( * V_95 ) -> V_98 )
return ( NULL ) ;
else
return ( * V_95 ) ;
}
int F_44 ( const T_2 * V_93 , unsigned char * V_90 )
{
long V_99 ;
if ( V_90 != NULL )
{
V_99 = V_93 -> V_96 ;
if ( ( V_99 & 0xff000000 ) != 0x03000000 ) return ( 0 ) ;
V_90 [ 0 ] = ( ( unsigned char ) ( V_99 >> 8L ) ) & 0xFF ;
V_90 [ 1 ] = ( ( unsigned char ) ( V_99 ) ) & 0xFF ;
}
return ( 2 ) ;
}
int F_45 ( T_3 * V_5 , unsigned char * V_90 )
{
int V_43 = 0 ;
unsigned long V_100 ;
V_100 = V_5 -> V_8 -> V_23 . V_101 -> V_102 ;
#ifndef F_13
if ( V_100 & ( V_103 | V_104 ) )
{
# ifndef V_45
V_90 [ V_43 ++ ] = V_105 ;
# endif
# ifndef V_44
V_90 [ V_43 ++ ] = V_106 ;
# endif
}
if ( ( V_5 -> V_38 == V_39 ) &&
( V_100 & ( V_104 | V_107 | V_103 ) ) )
{
# ifndef V_45
V_90 [ V_43 ++ ] = V_108 ;
# endif
# ifndef V_44
V_90 [ V_43 ++ ] = V_109 ;
# endif
}
#endif
#ifndef V_45
V_90 [ V_43 ++ ] = V_110 ;
#endif
#ifndef V_44
V_90 [ V_43 ++ ] = V_111 ;
#endif
#ifndef F_15
if ( ( V_100 & V_112 ) && ( V_5 -> V_38 >= V_113 ) )
{
V_90 [ V_43 ++ ] = V_114 ;
V_90 [ V_43 ++ ] = V_115 ;
}
#endif
#ifndef F_46
if ( V_5 -> V_38 >= V_113 )
{
V_90 [ V_43 ++ ] = V_116 ;
}
#endif
return ( V_43 ) ;
}
int F_47 ( T_3 * V_5 )
{
if ( ( V_5 -> V_117 ) || ( V_5 -> V_118 == V_119 ) )
{
V_5 -> V_120 = ( V_121 | V_122 ) ;
return ( 1 ) ;
}
if ( ! ( V_5 -> V_120 & V_121 ) )
{
V_5 -> V_120 |= V_121 ;
#if 1
F_48 ( V_5 , V_123 , V_124 ) ;
#endif
}
else if ( V_5 -> V_8 -> V_125 )
{
#if 1
V_5 -> V_17 -> V_126 ( V_5 ) ;
#endif
}
else if ( ! ( V_5 -> V_120 & V_122 ) )
{
V_5 -> V_17 -> V_127 ( V_5 , 0 , NULL , 0 , 0 ) ;
}
if ( ( V_5 -> V_120 == ( V_121 | V_122 ) ) &&
! V_5 -> V_8 -> V_125 )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_49 ( T_3 * V_5 , const void * V_20 , int V_32 )
{
int V_43 , V_128 ;
#if 0
if (s->shutdown & SSL_SEND_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
F_50 () ;
if ( V_5 -> V_8 -> V_34 ) F_51 ( V_5 ) ;
if ( ( V_5 -> V_8 -> V_60 & V_129 ) && ( V_5 -> V_130 == V_5 -> V_131 ) )
{
if ( V_5 -> V_8 -> V_132 == 0 )
{
V_43 = F_52 ( V_5 , V_10 ,
V_20 , V_32 ) ;
if ( V_43 <= 0 ) return ( V_43 ) ;
V_5 -> V_8 -> V_132 = V_43 ;
}
V_5 -> V_133 = V_134 ;
V_128 = F_53 ( V_5 -> V_130 ) ;
if ( V_128 <= 0 ) return ( V_128 ) ;
V_5 -> V_133 = V_135 ;
F_22 ( V_5 ) ;
V_5 -> V_8 -> V_60 &= ~ V_129 ;
V_43 = V_5 -> V_8 -> V_132 ;
V_5 -> V_8 -> V_132 = 0 ;
}
else
{
V_43 = V_5 -> V_17 -> V_136 ( V_5 , V_10 ,
V_20 , V_32 ) ;
if ( V_43 <= 0 ) return ( V_43 ) ;
}
return ( V_43 ) ;
}
static int F_54 ( T_3 * V_5 , void * V_20 , int V_32 , int V_137 )
{
int V_43 ;
F_50 () ;
if ( V_5 -> V_8 -> V_34 ) F_51 ( V_5 ) ;
V_5 -> V_8 -> V_37 = 1 ;
V_43 = V_5 -> V_17 -> V_127 ( V_5 , V_10 , V_20 , V_32 , V_137 ) ;
if ( ( V_43 == - 1 ) && ( V_5 -> V_8 -> V_37 == 2 ) )
{
V_5 -> V_138 ++ ;
V_43 = V_5 -> V_17 -> V_127 ( V_5 , V_10 , V_20 , V_32 , V_137 ) ;
V_5 -> V_138 -- ;
}
else
V_5 -> V_8 -> V_37 = 0 ;
return ( V_43 ) ;
}
int F_55 ( T_3 * V_5 , void * V_20 , int V_32 )
{
return F_54 ( V_5 , V_20 , V_32 , 0 ) ;
}
int F_56 ( T_3 * V_5 , void * V_20 , int V_32 )
{
return F_54 ( V_5 , V_20 , V_32 , 1 ) ;
}
int F_57 ( T_3 * V_5 )
{
if ( V_5 -> V_139 == NULL )
return ( 1 ) ;
if ( V_5 -> V_8 -> V_60 & V_140 )
return ( 0 ) ;
V_5 -> V_8 -> V_34 = 1 ;
return ( 1 ) ;
}
int F_51 ( T_3 * V_5 )
{
int V_43 = 0 ;
if ( V_5 -> V_8 -> V_34 )
{
if ( ( V_5 -> V_8 -> V_19 . V_141 == 0 ) &&
( V_5 -> V_8 -> V_21 . V_141 == 0 ) &&
! F_58 ( V_5 ) )
{
V_5 -> V_118 = V_142 ;
V_5 -> V_8 -> V_34 = 0 ;
V_5 -> V_8 -> V_36 ++ ;
V_5 -> V_8 -> V_35 ++ ;
V_43 = 1 ;
}
}
return ( V_43 ) ;
}
