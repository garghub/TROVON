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
if ( ( V_6 = F_7 ( sizeof *V_6 ) ) == NULL ) goto V_9;
memset ( V_6 , 0 , sizeof *V_6 ) ;
V_5 -> V_6 = V_6 ;
V_5 -> V_10 -> V_11 ( V_5 ) ;
return ( 1 ) ;
V_9:
return ( 0 ) ;
}
void F_8 ( T_3 * V_5 )
{
if( V_5 == NULL )
return;
F_9 ( V_5 ) ;
if ( V_5 -> V_6 -> V_12 . V_13 != NULL )
F_10 ( V_5 -> V_6 -> V_12 . V_13 ) ;
if ( V_5 -> V_6 -> V_14 . V_13 != NULL )
F_10 ( V_5 -> V_6 -> V_14 . V_13 ) ;
if ( V_5 -> V_6 -> V_7 . V_15 != NULL )
F_10 ( V_5 -> V_6 -> V_7 . V_15 ) ;
#ifndef F_11
if ( V_5 -> V_6 -> V_16 . V_17 != NULL )
F_12 ( V_5 -> V_6 -> V_16 . V_17 ) ;
#endif
if ( V_5 -> V_6 -> V_16 . V_18 != NULL )
F_13 ( V_5 -> V_6 -> V_16 . V_18 , V_19 ) ;
memset ( V_5 -> V_6 , 0 , sizeof * V_5 -> V_6 ) ;
F_10 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
}
void F_14 ( T_3 * V_5 )
{
unsigned char * V_20 , * V_21 ;
F_9 ( V_5 ) ;
if ( V_5 -> V_6 -> V_16 . V_18 != NULL )
F_13 ( V_5 -> V_6 -> V_16 . V_18 , V_19 ) ;
if ( V_5 -> V_6 -> V_7 . V_15 != NULL )
{
F_10 ( V_5 -> V_6 -> V_7 . V_15 ) ;
V_5 -> V_6 -> V_7 . V_15 = NULL ;
}
#ifndef F_11
if ( V_5 -> V_6 -> V_16 . V_17 != NULL )
F_12 ( V_5 -> V_6 -> V_16 . V_17 ) ;
#endif
V_20 = V_5 -> V_6 -> V_12 . V_13 ;
V_21 = V_5 -> V_6 -> V_14 . V_13 ;
memset ( V_5 -> V_6 , 0 , sizeof * V_5 -> V_6 ) ;
if ( V_20 != NULL ) V_5 -> V_6 -> V_12 . V_13 = V_20 ;
if ( V_21 != NULL ) V_5 -> V_6 -> V_14 . V_13 = V_21 ;
F_15 ( V_5 ) ;
V_5 -> V_22 = 0 ;
V_5 -> V_6 -> V_23 = 0 ;
V_5 -> V_6 -> V_24 = 0 ;
V_5 -> V_6 -> V_25 = 0 ;
V_5 -> V_6 -> V_26 = 0 ;
V_5 -> V_27 = V_28 ;
}
long F_16 ( T_3 * V_5 , int V_29 , long V_30 , char * V_31 )
{
int V_32 = 0 ;
#if ! F_17 ( V_33 ) || ! F_17 ( V_34 )
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
if ( ! F_18 ( & V_5 -> V_39 ) )
{
F_19 ( V_40 , V_41 ) ;
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
( F_20 ( V_5 -> V_39 -> V_52 [ V_53 ] . V_54 ) > ( 512 / 8 ) ) ) )
V_32 = 1 ;
break;
case V_35 :
{
T_5 * V_55 = ( T_5 * ) V_31 ;
if ( V_55 == NULL )
{
F_19 ( V_40 , V_56 ) ;
return ( V_32 ) ;
}
if ( ( V_55 = F_21 ( V_55 ) ) == NULL )
{
F_19 ( V_40 , V_57 ) ;
return ( V_32 ) ;
}
if ( V_5 -> V_39 -> V_51 != NULL )
F_22 ( V_5 -> V_39 -> V_51 ) ;
V_5 -> V_39 -> V_51 = V_55 ;
V_32 = 1 ;
}
break;
case V_36 :
{
F_19 ( V_40 , V_58 ) ;
return ( V_32 ) ;
}
break;
#endif
#ifndef F_11
case V_37 :
{
T_6 * V_17 = ( T_6 * ) V_31 ;
if ( V_17 == NULL )
{
F_19 ( V_40 , V_56 ) ;
return ( V_32 ) ;
}
if ( ( V_17 = F_23 ( V_17 ) ) == NULL )
{
F_19 ( V_40 , V_59 ) ;
return ( V_32 ) ;
}
if ( ! ( V_5 -> V_60 & V_61 ) )
{
if ( ! F_24 ( V_17 ) )
{
F_12 ( V_17 ) ;
F_19 ( V_40 , V_59 ) ;
return ( V_32 ) ;
}
}
if ( V_5 -> V_39 -> V_62 != NULL )
F_12 ( V_5 -> V_39 -> V_62 ) ;
V_5 -> V_39 -> V_62 = V_17 ;
V_32 = 1 ;
}
break;
case V_38 :
{
F_19 ( V_40 , V_58 ) ;
return ( V_32 ) ;
}
break;
#endif
default:
break;
}
return ( V_32 ) ;
}
long F_25 ( T_3 * V_5 , int V_29 , void (* F_26)() )
{
int V_32 = 0 ;
#if ! F_17 ( V_33 ) || ! F_17 ( V_34 )
if (
#ifndef V_34
V_29 == V_36 ||
#endif
#ifndef V_33
V_29 == V_38 ||
#endif
0 )
{
if ( ! F_18 ( & V_5 -> V_39 ) )
{
F_19 ( V_63 , V_41 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_29 )
{
#ifndef V_34
case V_36 :
{
V_5 -> V_39 -> V_64 = ( T_5 * (*)( T_3 * , int , int ) ) F_26 ;
}
break;
#endif
#ifndef F_11
case V_38 :
{
V_5 -> V_39 -> V_65 = ( T_6 * (*)( T_3 * , int , int ) ) F_26 ;
}
break;
#endif
default:
break;
}
return ( V_32 ) ;
}
long F_27 ( T_7 * V_66 , int V_29 , long V_30 , char * V_31 )
{
T_8 * V_39 ;
V_39 = V_66 -> V_39 ;
switch ( V_29 )
{
#ifndef V_34
case V_50 :
if ( ( V_39 -> V_51 == NULL ) &&
( ( V_39 -> V_52 [ V_53 ] . V_54 == NULL ) ||
( F_20 ( V_39 -> V_52 [ V_53 ] . V_54 ) > ( 512 / 8 ) ) )
)
return ( 1 ) ;
else
return ( 0 ) ;
case V_35 :
{
T_5 * V_55 ;
int V_67 ;
V_55 = ( T_5 * ) V_31 ;
V_67 = 1 ;
if ( V_55 == NULL )
V_67 = 0 ;
else
{
if ( ( V_55 = F_21 ( V_55 ) ) == NULL )
V_67 = 0 ;
}
if ( ! V_67 )
{
F_19 ( V_68 , V_57 ) ;
return ( 0 ) ;
}
else
{
if ( V_39 -> V_51 != NULL )
F_22 ( V_39 -> V_51 ) ;
V_39 -> V_51 = V_55 ;
return ( 1 ) ;
}
}
case V_36 :
{
F_19 ( V_68 , V_58 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_11
case V_37 :
{
T_6 * V_69 = NULL , * V_17 ;
V_17 = ( T_6 * ) V_31 ;
if ( ( V_69 = F_23 ( V_17 ) ) == NULL )
{
F_19 ( V_68 , V_59 ) ;
return 0 ;
}
if ( ! ( V_66 -> V_60 & V_61 ) )
{
if ( ! F_24 ( V_69 ) )
{
F_19 ( V_68 , V_59 ) ;
F_12 ( V_69 ) ;
return 0 ;
}
}
if ( V_39 -> V_62 != NULL )
F_12 ( V_39 -> V_62 ) ;
V_39 -> V_62 = V_69 ;
return 1 ;
}
case V_38 :
{
F_19 ( V_68 , V_58 ) ;
return ( 0 ) ;
}
break;
#endif
case V_70 :
if ( V_66 -> V_71 == NULL )
{
if ( ( V_66 -> V_71 = F_28 () ) == NULL )
return ( 0 ) ;
}
F_29 ( V_66 -> V_71 , ( V_72 * ) V_31 ) ;
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
long F_30 ( T_7 * V_66 , int V_29 , void (* F_26)() )
{
T_8 * V_39 ;
V_39 = V_66 -> V_39 ;
switch ( V_29 )
{
#ifndef V_34
case V_36 :
{
V_39 -> V_64 = ( T_5 * (*)( T_3 * , int , int ) ) F_26 ;
}
break;
#endif
#ifndef F_11
case V_38 :
{
V_39 -> V_65 = ( T_6 * (*)( T_3 * , int , int ) ) F_26 ;
}
break;
#endif
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
T_2 * F_31 ( const unsigned char * V_73 )
{
static int V_74 = 1 ;
static T_2 * V_75 [ V_2 ] ;
T_2 V_76 , * V_77 = & V_76 , * * V_78 ;
unsigned long V_79 ;
int V_67 ;
if ( V_74 )
{
F_32 ( V_80 ) ;
for ( V_67 = 0 ; V_67 < V_2 ; V_67 ++ )
V_75 [ V_67 ] = & ( V_4 [ V_67 ] ) ;
qsort ( (char *)sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
F_33 ( V_80 ) ;
V_74 = 0 ;
}
V_79 = 0x03000000L | ( ( unsigned long ) V_73 [ 0 ] << 8L ) | ( unsigned long ) V_73 [ 1 ] ;
V_76 . V_79 = V_79 ;
V_78 = ( T_2 * * ) F_34 ((char *)&cp,
(char *)sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
if ( ( V_78 == NULL ) || ! ( * V_78 ) -> V_81 )
return ( NULL ) ;
else
return ( * V_78 ) ;
}
int F_35 ( const T_2 * V_76 , unsigned char * V_73 )
{
long V_82 ;
if ( V_73 != NULL )
{
V_82 = V_76 -> V_79 ;
if ( ( V_82 & 0xff000000 ) != 0x03000000 ) return ( 0 ) ;
V_73 [ 0 ] = ( ( unsigned char ) ( V_82 >> 8L ) ) & 0xFF ;
V_73 [ 1 ] = ( ( unsigned char ) ( V_82 ) ) & 0xFF ;
}
return ( 2 ) ;
}
int F_36 ( T_3 * V_5 , unsigned char * V_73 )
{
int V_32 = 0 ;
unsigned long V_83 ;
V_83 = V_5 -> V_6 -> V_16 . V_84 -> V_85 ;
#ifndef F_11
if ( V_83 & ( V_86 | V_87 ) )
{
# ifndef V_34
V_73 [ V_32 ++ ] = V_88 ;
# endif
# ifndef V_33
V_73 [ V_32 ++ ] = V_89 ;
# endif
}
if ( ( V_5 -> V_27 == V_28 ) &&
( V_83 & ( V_87 | V_90 | V_86 ) ) )
{
# ifndef V_34
V_73 [ V_32 ++ ] = V_91 ;
# endif
# ifndef V_33
V_73 [ V_32 ++ ] = V_92 ;
# endif
}
#endif
#ifndef V_34
V_73 [ V_32 ++ ] = V_93 ;
#endif
#ifndef V_33
V_73 [ V_32 ++ ] = V_94 ;
#endif
return ( V_32 ) ;
}
int F_37 ( T_3 * V_5 )
{
if ( ( V_5 -> V_95 ) || ( V_5 -> V_96 == V_97 ) )
{
V_5 -> V_98 = ( V_99 | V_100 ) ;
return ( 1 ) ;
}
if ( ! ( V_5 -> V_98 & V_99 ) )
{
V_5 -> V_98 |= V_99 ;
#if 1
F_38 ( V_5 , V_101 , V_102 ) ;
#endif
}
else if ( V_5 -> V_6 -> V_103 )
{
#if 1
F_39 ( V_5 ) ;
#endif
}
else if ( ! ( V_5 -> V_98 & V_100 ) )
{
F_40 ( V_5 , 0 , NULL , 0 ) ;
}
if ( ( V_5 -> V_98 == ( V_99 | V_100 ) ) &&
! V_5 -> V_6 -> V_103 )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_41 ( T_3 * V_5 , const void * V_13 , int V_104 )
{
int V_32 , V_105 ;
#if 0
if (s->shutdown & SSL_SEND_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
F_42 () ;
if ( V_5 -> V_6 -> V_23 ) F_43 ( V_5 ) ;
if ( ( V_5 -> V_6 -> V_49 & V_106 ) && ( V_5 -> V_107 == V_5 -> V_108 ) )
{
if ( V_5 -> V_6 -> V_109 == 0 )
{
V_32 = F_44 ( V_5 , V_110 ,
V_13 , V_104 ) ;
if ( V_32 <= 0 ) return ( V_32 ) ;
V_5 -> V_6 -> V_109 = V_32 ;
}
V_5 -> V_111 = V_112 ;
V_105 = F_45 ( V_5 -> V_107 ) ;
if ( V_105 <= 0 ) return ( V_105 ) ;
V_5 -> V_111 = V_113 ;
F_15 ( V_5 ) ;
V_5 -> V_6 -> V_49 &= ~ V_106 ;
V_32 = V_5 -> V_6 -> V_109 ;
V_5 -> V_6 -> V_109 = 0 ;
}
else
{
V_32 = F_44 ( V_5 , V_110 ,
V_13 , V_104 ) ;
if ( V_32 <= 0 ) return ( V_32 ) ;
}
return ( V_32 ) ;
}
int F_46 ( T_3 * V_5 , void * V_13 , int V_104 )
{
int V_32 ;
F_42 () ;
if ( V_5 -> V_6 -> V_23 ) F_43 ( V_5 ) ;
V_5 -> V_6 -> V_26 = 1 ;
V_32 = F_40 ( V_5 , V_110 , V_13 , V_104 ) ;
if ( ( V_32 == - 1 ) && ( V_5 -> V_6 -> V_26 == 0 ) )
{
V_5 -> V_114 ++ ;
V_32 = F_40 ( V_5 , V_110 , V_13 , V_104 ) ;
V_5 -> V_114 -- ;
}
else
V_5 -> V_6 -> V_26 = 0 ;
return ( V_32 ) ;
}
int F_47 ( T_3 * V_5 , char * V_13 , int V_104 )
{
T_9 * V_115 ;
int V_105 ;
V_115 = & ( V_5 -> V_6 -> V_7 ) ;
if ( ( V_115 -> V_8 == 0 ) || ( V_115 -> type != V_110 ) )
{
V_105 = F_46 ( V_5 , V_13 , 1 ) ;
if ( V_105 <= 0 ) return ( V_105 ) ;
V_115 -> V_8 ++ ;
V_115 -> V_116 -- ;
}
if ( ( unsigned int ) V_104 > V_115 -> V_8 )
V_105 = V_115 -> V_8 ;
else
V_105 = V_104 ;
memcpy ( V_13 , & ( V_115 -> V_117 [ V_115 -> V_116 ] ) , ( unsigned int ) V_105 ) ;
return ( V_105 ) ;
}
int F_48 ( T_3 * V_5 )
{
if ( V_5 -> V_118 == NULL )
return ( 1 ) ;
if ( V_5 -> V_6 -> V_49 & V_119 )
return ( 0 ) ;
V_5 -> V_6 -> V_23 = 1 ;
return ( 1 ) ;
}
int F_43 ( T_3 * V_5 )
{
int V_32 = 0 ;
if ( V_5 -> V_6 -> V_23 )
{
if ( ( V_5 -> V_6 -> V_12 . V_120 == 0 ) &&
( V_5 -> V_6 -> V_14 . V_120 == 0 ) &&
! F_49 ( V_5 ) )
{
V_5 -> V_96 = V_121 ;
V_5 -> V_6 -> V_23 = 0 ;
V_5 -> V_6 -> V_25 ++ ;
V_5 -> V_6 -> V_24 ++ ;
V_32 = 1 ;
}
}
return ( V_32 ) ;
}
