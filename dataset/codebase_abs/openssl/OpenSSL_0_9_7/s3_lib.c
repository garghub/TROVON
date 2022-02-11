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
V_5 -> V_8 = V_8 ;
V_5 -> V_15 -> V_16 ( V_5 ) ;
return ( 1 ) ;
V_12:
return ( 0 ) ;
}
void F_9 ( T_3 * V_5 )
{
if( V_5 == NULL )
return;
F_10 ( V_5 ) ;
if ( V_5 -> V_8 -> V_17 . V_18 != NULL )
F_11 ( V_5 -> V_8 -> V_17 . V_18 ) ;
if ( V_5 -> V_8 -> V_19 . V_18 != NULL )
F_11 ( V_5 -> V_8 -> V_19 . V_18 ) ;
if ( V_5 -> V_8 -> V_9 . V_20 != NULL )
F_11 ( V_5 -> V_8 -> V_9 . V_20 ) ;
#ifndef F_12
if ( V_5 -> V_8 -> V_21 . V_22 != NULL )
F_13 ( V_5 -> V_8 -> V_21 . V_22 ) ;
#endif
if ( V_5 -> V_8 -> V_21 . V_23 != NULL )
F_14 ( V_5 -> V_8 -> V_21 . V_23 , V_24 ) ;
F_15 ( & V_5 -> V_8 -> V_13 ) ;
F_15 ( & V_5 -> V_8 -> V_14 ) ;
F_16 ( V_5 -> V_8 , sizeof * V_5 -> V_8 ) ;
F_11 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
void F_17 ( T_3 * V_5 )
{
unsigned char * V_25 , * V_26 ;
T_5 V_27 , V_28 ;
F_10 ( V_5 ) ;
if ( V_5 -> V_8 -> V_21 . V_23 != NULL )
F_14 ( V_5 -> V_8 -> V_21 . V_23 , V_24 ) ;
if ( V_5 -> V_8 -> V_9 . V_20 != NULL )
{
F_11 ( V_5 -> V_8 -> V_9 . V_20 ) ;
V_5 -> V_8 -> V_9 . V_20 = NULL ;
}
#ifndef F_12
if ( V_5 -> V_8 -> V_21 . V_22 != NULL )
F_13 ( V_5 -> V_8 -> V_21 . V_22 ) ;
#endif
V_25 = V_5 -> V_8 -> V_17 . V_18 ;
V_26 = V_5 -> V_8 -> V_19 . V_18 ;
V_27 = V_5 -> V_8 -> V_17 . V_29 ;
V_28 = V_5 -> V_8 -> V_19 . V_29 ;
F_15 ( & V_5 -> V_8 -> V_13 ) ;
F_15 ( & V_5 -> V_8 -> V_14 ) ;
memset ( V_5 -> V_8 , 0 , sizeof * V_5 -> V_8 ) ;
V_5 -> V_8 -> V_17 . V_18 = V_25 ;
V_5 -> V_8 -> V_19 . V_18 = V_26 ;
V_5 -> V_8 -> V_17 . V_29 = V_27 ;
V_5 -> V_8 -> V_19 . V_29 = V_28 ;
F_18 ( V_5 ) ;
V_5 -> V_30 = 0 ;
V_5 -> V_8 -> V_31 = 0 ;
V_5 -> V_8 -> V_32 = 0 ;
V_5 -> V_8 -> V_33 = 0 ;
V_5 -> V_8 -> V_34 = 0 ;
V_5 -> V_35 = V_36 ;
}
long F_19 ( T_3 * V_5 , int V_37 , long V_38 , void * V_39 )
{
int V_40 = 0 ;
#if ! F_20 ( V_41 ) || ! F_20 ( V_42 )
if (
#ifndef V_42
V_37 == V_43 ||
V_37 == V_44 ||
#endif
#ifndef V_41
V_37 == V_45 ||
V_37 == V_46 ||
#endif
0 )
{
if ( ! F_21 ( & V_5 -> V_47 ) )
{
F_22 ( V_48 , V_49 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_37 )
{
case V_50 :
V_40 = V_5 -> V_51 ;
break;
case V_52 :
break;
case V_53 :
V_40 = V_5 -> V_8 -> V_33 ;
break;
case V_54 :
V_40 = V_5 -> V_8 -> V_33 ;
V_5 -> V_8 -> V_33 = 0 ;
break;
case V_55 :
V_40 = V_5 -> V_8 -> V_32 ;
break;
case V_56 :
V_40 = ( int ) ( V_5 -> V_8 -> V_57 ) ;
break;
#ifndef V_42
case V_58 :
if ( ( V_5 -> V_47 != NULL ) && ( V_5 -> V_47 -> V_59 == NULL ) &&
( ( V_5 -> V_47 -> V_60 [ V_61 ] . V_62 == NULL ) ||
( F_23 ( V_5 -> V_47 -> V_60 [ V_61 ] . V_62 ) > ( 512 / 8 ) ) ) )
V_40 = 1 ;
break;
case V_43 :
{
T_6 * V_63 = ( T_6 * ) V_39 ;
if ( V_63 == NULL )
{
F_22 ( V_48 , V_64 ) ;
return ( V_40 ) ;
}
if ( ( V_63 = F_24 ( V_63 ) ) == NULL )
{
F_22 ( V_48 , V_65 ) ;
return ( V_40 ) ;
}
if ( V_5 -> V_47 -> V_59 != NULL )
F_25 ( V_5 -> V_47 -> V_59 ) ;
V_5 -> V_47 -> V_59 = V_63 ;
V_40 = 1 ;
}
break;
case V_44 :
{
F_22 ( V_48 , V_66 ) ;
return ( V_40 ) ;
}
break;
#endif
#ifndef F_12
case V_45 :
{
T_7 * V_22 = ( T_7 * ) V_39 ;
if ( V_22 == NULL )
{
F_22 ( V_48 , V_64 ) ;
return ( V_40 ) ;
}
if ( ( V_22 = F_26 ( V_22 ) ) == NULL )
{
F_22 ( V_48 , V_67 ) ;
return ( V_40 ) ;
}
if ( ! ( V_5 -> V_68 & V_69 ) )
{
if ( ! F_27 ( V_22 ) )
{
F_13 ( V_22 ) ;
F_22 ( V_48 , V_67 ) ;
return ( V_40 ) ;
}
}
if ( V_5 -> V_47 -> V_70 != NULL )
F_13 ( V_5 -> V_47 -> V_70 ) ;
V_5 -> V_47 -> V_70 = V_22 ;
V_40 = 1 ;
}
break;
case V_46 :
{
F_22 ( V_48 , V_66 ) ;
return ( V_40 ) ;
}
break;
#endif
default:
break;
}
return ( V_40 ) ;
}
long F_28 ( T_3 * V_5 , int V_37 , void (* F_29)() )
{
int V_40 = 0 ;
#if ! F_20 ( V_41 ) || ! F_20 ( V_42 )
if (
#ifndef V_42
V_37 == V_44 ||
#endif
#ifndef V_41
V_37 == V_46 ||
#endif
0 )
{
if ( ! F_21 ( & V_5 -> V_47 ) )
{
F_22 ( V_71 , V_49 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_37 )
{
#ifndef V_42
case V_44 :
{
V_5 -> V_47 -> V_72 = ( T_6 * (*)( T_3 * , int , int ) ) F_29 ;
}
break;
#endif
#ifndef F_12
case V_46 :
{
V_5 -> V_47 -> V_73 = ( T_7 * (*)( T_3 * , int , int ) ) F_29 ;
}
break;
#endif
default:
break;
}
return ( V_40 ) ;
}
long F_30 ( T_8 * V_74 , int V_37 , long V_38 , void * V_39 )
{
T_9 * V_47 ;
V_47 = V_74 -> V_47 ;
switch ( V_37 )
{
#ifndef V_42
case V_58 :
if ( ( V_47 -> V_59 == NULL ) &&
( ( V_47 -> V_60 [ V_61 ] . V_62 == NULL ) ||
( F_23 ( V_47 -> V_60 [ V_61 ] . V_62 ) > ( 512 / 8 ) ) )
)
return ( 1 ) ;
else
return ( 0 ) ;
case V_43 :
{
T_6 * V_63 ;
int V_75 ;
V_63 = ( T_6 * ) V_39 ;
V_75 = 1 ;
if ( V_63 == NULL )
V_75 = 0 ;
else
{
if ( ( V_63 = F_24 ( V_63 ) ) == NULL )
V_75 = 0 ;
}
if ( ! V_75 )
{
F_22 ( V_76 , V_65 ) ;
return ( 0 ) ;
}
else
{
if ( V_47 -> V_59 != NULL )
F_25 ( V_47 -> V_59 ) ;
V_47 -> V_59 = V_63 ;
return ( 1 ) ;
}
}
case V_44 :
{
F_22 ( V_76 , V_66 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_12
case V_45 :
{
T_7 * V_77 = NULL , * V_22 ;
V_22 = ( T_7 * ) V_39 ;
if ( ( V_77 = F_26 ( V_22 ) ) == NULL )
{
F_22 ( V_76 , V_67 ) ;
return 0 ;
}
if ( ! ( V_74 -> V_68 & V_69 ) )
{
if ( ! F_27 ( V_77 ) )
{
F_22 ( V_76 , V_67 ) ;
F_13 ( V_77 ) ;
return 0 ;
}
}
if ( V_47 -> V_70 != NULL )
F_13 ( V_47 -> V_70 ) ;
V_47 -> V_70 = V_77 ;
return 1 ;
}
case V_46 :
{
F_22 ( V_76 , V_66 ) ;
return ( 0 ) ;
}
break;
#endif
case V_78 :
if ( V_74 -> V_79 == NULL )
{
if ( ( V_74 -> V_79 = F_31 () ) == NULL )
return ( 0 ) ;
}
F_32 ( V_74 -> V_79 , ( V_80 * ) V_39 ) ;
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
long F_33 ( T_8 * V_74 , int V_37 , void (* F_29)() )
{
T_9 * V_47 ;
V_47 = V_74 -> V_47 ;
switch ( V_37 )
{
#ifndef V_42
case V_44 :
{
V_47 -> V_72 = ( T_6 * (*)( T_3 * , int , int ) ) F_29 ;
}
break;
#endif
#ifndef F_12
case V_46 :
{
V_47 -> V_73 = ( T_7 * (*)( T_3 * , int , int ) ) F_29 ;
}
break;
#endif
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
T_2 * F_34 ( const unsigned char * V_81 )
{
static int V_82 = 1 ;
static T_2 * V_83 [ V_2 ] ;
T_2 V_84 , * V_85 = & V_84 , * * V_86 ;
unsigned long V_87 ;
int V_75 ;
if ( V_82 )
{
F_35 ( V_88 ) ;
if ( V_82 )
{
for ( V_75 = 0 ; V_75 < V_2 ; V_75 ++ )
V_83 [ V_75 ] = & ( V_4 [ V_75 ] ) ;
qsort (sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
V_82 = 0 ;
}
F_36 ( V_88 ) ;
}
V_87 = 0x03000000L | ( ( unsigned long ) V_81 [ 0 ] << 8L ) | ( unsigned long ) V_81 [ 1 ] ;
V_84 . V_87 = V_87 ;
V_86 = ( T_2 * * ) F_37 ((char *)&cp,
(char *)sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp) ;
if ( ( V_86 == NULL ) || ! ( * V_86 ) -> V_89 )
return ( NULL ) ;
else
return ( * V_86 ) ;
}
int F_38 ( const T_2 * V_84 , unsigned char * V_81 )
{
long V_90 ;
if ( V_81 != NULL )
{
V_90 = V_84 -> V_87 ;
if ( ( V_90 & 0xff000000 ) != 0x03000000 ) return ( 0 ) ;
V_81 [ 0 ] = ( ( unsigned char ) ( V_90 >> 8L ) ) & 0xFF ;
V_81 [ 1 ] = ( ( unsigned char ) ( V_90 ) ) & 0xFF ;
}
return ( 2 ) ;
}
int F_39 ( T_3 * V_5 , unsigned char * V_81 )
{
int V_40 = 0 ;
unsigned long V_91 ;
V_91 = V_5 -> V_8 -> V_21 . V_92 -> V_93 ;
#ifndef F_12
if ( V_91 & ( V_94 | V_95 ) )
{
# ifndef V_42
V_81 [ V_40 ++ ] = V_96 ;
# endif
# ifndef V_41
V_81 [ V_40 ++ ] = V_97 ;
# endif
}
if ( ( V_5 -> V_35 == V_36 ) &&
( V_91 & ( V_95 | V_98 | V_94 ) ) )
{
# ifndef V_42
V_81 [ V_40 ++ ] = V_99 ;
# endif
# ifndef V_41
V_81 [ V_40 ++ ] = V_100 ;
# endif
}
#endif
#ifndef V_42
V_81 [ V_40 ++ ] = V_101 ;
#endif
#ifndef V_41
V_81 [ V_40 ++ ] = V_102 ;
#endif
return ( V_40 ) ;
}
int F_40 ( T_3 * V_5 )
{
if ( ( V_5 -> V_103 ) || ( V_5 -> V_104 == V_105 ) )
{
V_5 -> V_106 = ( V_107 | V_108 ) ;
return ( 1 ) ;
}
if ( ! ( V_5 -> V_106 & V_107 ) )
{
V_5 -> V_106 |= V_107 ;
#if 1
F_41 ( V_5 , V_109 , V_110 ) ;
#endif
}
else if ( V_5 -> V_8 -> V_111 )
{
#if 1
F_42 ( V_5 ) ;
#endif
}
else if ( ! ( V_5 -> V_106 & V_108 ) )
{
F_43 ( V_5 , 0 , NULL , 0 , 0 ) ;
}
if ( ( V_5 -> V_106 == ( V_107 | V_108 ) ) &&
! V_5 -> V_8 -> V_111 )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_44 ( T_3 * V_5 , const void * V_18 , int V_29 )
{
int V_40 , V_112 ;
#if 0
if (s->shutdown & SSL_SEND_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
F_45 () ;
if ( V_5 -> V_8 -> V_31 ) F_46 ( V_5 ) ;
if ( ( V_5 -> V_8 -> V_57 & V_113 ) && ( V_5 -> V_114 == V_5 -> V_115 ) )
{
if ( V_5 -> V_8 -> V_116 == 0 )
{
V_40 = F_47 ( V_5 , V_10 ,
V_18 , V_29 ) ;
if ( V_40 <= 0 ) return ( V_40 ) ;
V_5 -> V_8 -> V_116 = V_40 ;
}
V_5 -> V_117 = V_118 ;
V_112 = F_48 ( V_5 -> V_114 ) ;
if ( V_112 <= 0 ) return ( V_112 ) ;
V_5 -> V_117 = V_119 ;
F_18 ( V_5 ) ;
V_5 -> V_8 -> V_57 &= ~ V_113 ;
V_40 = V_5 -> V_8 -> V_116 ;
V_5 -> V_8 -> V_116 = 0 ;
}
else
{
V_40 = F_47 ( V_5 , V_10 ,
V_18 , V_29 ) ;
if ( V_40 <= 0 ) return ( V_40 ) ;
}
return ( V_40 ) ;
}
static int F_49 ( T_3 * V_5 , void * V_18 , int V_29 , int V_120 )
{
int V_40 ;
F_45 () ;
if ( V_5 -> V_8 -> V_31 ) F_46 ( V_5 ) ;
V_5 -> V_8 -> V_34 = 1 ;
V_40 = F_43 ( V_5 , V_10 , V_18 , V_29 , V_120 ) ;
if ( ( V_40 == - 1 ) && ( V_5 -> V_8 -> V_34 == 2 ) )
{
V_5 -> V_121 ++ ;
V_40 = F_43 ( V_5 , V_10 , V_18 , V_29 , V_120 ) ;
V_5 -> V_121 -- ;
}
else
V_5 -> V_8 -> V_34 = 0 ;
return ( V_40 ) ;
}
int F_50 ( T_3 * V_5 , void * V_18 , int V_29 )
{
return F_49 ( V_5 , V_18 , V_29 , 0 ) ;
}
int F_51 ( T_3 * V_5 , void * V_18 , int V_29 )
{
return F_49 ( V_5 , V_18 , V_29 , 1 ) ;
}
int F_52 ( T_3 * V_5 )
{
if ( V_5 -> V_122 == NULL )
return ( 1 ) ;
if ( V_5 -> V_8 -> V_57 & V_123 )
return ( 0 ) ;
V_5 -> V_8 -> V_31 = 1 ;
return ( 1 ) ;
}
int F_46 ( T_3 * V_5 )
{
int V_40 = 0 ;
if ( V_5 -> V_8 -> V_31 )
{
if ( ( V_5 -> V_8 -> V_17 . V_124 == 0 ) &&
( V_5 -> V_8 -> V_19 . V_124 == 0 ) &&
! F_53 ( V_5 ) )
{
V_5 -> V_104 = V_125 ;
V_5 -> V_8 -> V_31 = 0 ;
V_5 -> V_8 -> V_33 ++ ;
V_5 -> V_8 -> V_32 ++ ;
V_40 = 1 ;
}
}
return ( V_40 ) ;
}
