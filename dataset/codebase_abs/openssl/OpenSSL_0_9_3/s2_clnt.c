static T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return ( F_2 () ) ;
else
return ( NULL ) ;
}
T_1 * F_2 ( void )
{
static int V_3 = 1 ;
static T_1 V_4 ;
if ( V_3 )
{
memcpy ( ( char * ) & V_4 , ( char * ) F_3 () ,
sizeof( T_1 ) ) ;
V_4 . V_5 = V_6 ;
V_4 . V_7 = F_1 ;
V_3 = 0 ;
}
return ( & V_4 ) ;
}
int V_6 ( T_2 * V_8 )
{
unsigned long V_9 = time ( NULL ) ;
T_3 * V_10 = NULL ;
int V_11 = - 1 ;
void (* F_4)() = NULL ;
int V_12 , V_13 ;
F_5 ( & V_9 , sizeof( V_9 ) ) ;
F_6 () ;
F_7 () ;
if ( V_8 -> V_14 != NULL )
F_4 = V_8 -> V_14 ;
else if ( V_8 -> V_15 -> V_14 != NULL )
F_4 = V_8 -> V_15 -> V_14 ;
if ( ! F_8 ( V_8 ) || F_9 ( V_8 ) ) F_10 ( V_8 ) ;
V_8 -> V_16 ++ ;
for (; ; )
{
V_13 = V_8 -> V_13 ;
switch ( V_8 -> V_13 )
{
case V_17 :
case V_18 :
case V_17 | V_18 :
case V_19 | V_18 :
V_8 -> V_20 = 0 ;
if ( F_4 != NULL ) F_4 ( V_8 , V_21 , 1 ) ;
V_8 -> V_22 = V_2 ;
V_8 -> type = V_18 ;
V_10 = V_8 -> V_23 ;
if ( ( V_10 == NULL ) && ( ( V_10 = F_11 () ) == NULL ) )
{
V_11 = - 1 ;
goto V_24;
}
if ( ! F_12 ( V_10 ,
V_25 ) )
{
V_11 = - 1 ;
goto V_24;
}
V_8 -> V_23 = V_10 ;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_27 ;
V_8 -> V_15 -> V_28 . V_29 ++ ;
V_8 -> V_30 = V_6 ;
BREAK ;
case V_27 :
case V_31 :
V_8 -> V_32 = 0 ;
V_11 = F_13 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_33 ;
BREAK ;
case V_33 :
case V_34 :
V_11 = F_14 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
if ( ! V_8 -> V_35 )
{
V_8 -> V_13 = V_36 ;
BREAK ;
}
else
{
V_8 -> V_13 = V_37 ;
break;
}
case V_36 :
case V_38 :
V_11 = F_15 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_37 ;
break;
case V_37 :
if ( ! F_16 ( V_8 , 1 ) )
{
V_11 = - 1 ;
goto V_24;
}
V_8 -> V_39 -> V_40 = 0 ;
V_8 -> V_13 = V_41 ;
break;
case V_41 :
case V_42 :
V_11 = F_17 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_43 ;
break;
case V_43 :
case V_44 :
V_11 = F_18 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_45 ;
break;
case V_45 :
case V_46 :
V_11 = F_19 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_11 = F_20 ( V_8 ) ;
if ( V_11 <= 0 ) goto V_24;
V_8 -> V_26 = 0 ;
V_8 -> V_13 = V_45 ;
break;
case V_19 :
if ( V_8 -> V_23 != NULL )
{
F_21 ( V_8 -> V_23 ) ;
V_8 -> V_23 = NULL ;
}
V_8 -> V_26 = 0 ;
F_22 ( V_8 , V_52 ) ;
if ( V_8 -> V_35 ) V_8 -> V_15 -> V_28 . V_53 ++ ;
V_11 = 1 ;
V_8 -> V_15 -> V_28 . V_54 ++ ;
if ( F_4 != NULL ) F_4 ( V_8 , V_55 , 1 ) ;
goto V_24;
default:
F_23 ( V_56 , V_57 ) ;
return ( - 1 ) ;
}
if ( ( F_4 != NULL ) && ( V_8 -> V_13 != V_13 ) )
{
V_12 = V_8 -> V_13 ;
V_8 -> V_13 = V_13 ;
F_4 ( V_8 , V_58 , 1 ) ;
V_8 -> V_13 = V_12 ;
}
}
V_24:
V_8 -> V_16 -- ;
if ( F_4 != NULL )
F_4 ( V_8 , V_59 , V_11 ) ;
return ( V_11 ) ;
}
static int F_14 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 ;
int V_61 , V_62 ;
F_24 ( V_63 ) * V_64 = NULL , * V_65 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
V_60 = V_10 ;
if ( V_8 -> V_13 == V_33 )
{
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) , 11 - V_8 -> V_26 ) ;
if ( V_61 < ( 11 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_67 , V_61 ) ) ;
if ( * ( V_60 ++ ) != V_68 )
{
if ( V_60 [ - 1 ] != V_69 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_67 ,
V_71 ) ;
}
else
F_23 ( V_67 ,
V_72 ) ;
return ( - 1 ) ;
}
V_8 -> V_35 = ( * ( V_60 ++ ) ) ? 1 : 0 ;
V_8 -> V_39 -> V_73 . V_74 = * ( V_60 ++ ) ;
F_28 ( V_60 , V_61 ) ;
if ( V_61 < V_8 -> V_22 ) V_8 -> V_22 = V_61 ;
F_28 ( V_60 , V_61 ) ; V_8 -> V_39 -> V_73 . V_75 = V_61 ;
F_28 ( V_60 , V_61 ) ; V_8 -> V_39 -> V_73 . V_76 = V_61 ;
F_28 ( V_60 , V_61 ) ; V_8 -> V_39 -> V_73 . V_77 = V_61 ;
V_8 -> V_13 = V_34 ;
V_8 -> V_26 = 0 ;
}
V_62 = V_8 -> V_39 -> V_73 . V_75 + V_8 -> V_39 -> V_73 . V_76 + V_8 -> V_39 -> V_73 . V_77
- V_8 -> V_26 ;
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) , V_62 ) ;
if ( V_61 != V_62 ) return ( F_26 ( V_8 , V_67 , V_61 ) ) ;
V_60 = V_10 ;
if ( V_8 -> V_35 )
{
if ( V_8 -> V_39 -> V_73 . V_75 != 0 )
{
F_23 ( V_67 , V_78 ) ;
return ( - 1 ) ;
}
if ( V_8 -> V_39 -> V_73 . V_74 != 0 )
{
if ( ! ( V_8 -> V_79 &
V_80 ) )
{
F_23 ( V_67 , V_81 ) ;
return ( - 1 ) ;
}
}
if ( V_8 -> V_39 -> V_73 . V_76 != 0 )
{
F_23 ( V_67 , V_82 ) ;
return ( - 1 ) ;
}
}
else
{
#ifdef undef
memset ( V_8 -> V_83 -> V_84 , 0 ,
V_85 ) ;
V_8 -> V_83 -> V_86 = 0 ;
* /
#endif
if ( V_8 -> V_83 -> V_86 > 0 )
{
if ( ! F_29 ( V_8 , 0 ) )
{
F_27 ( V_8 , V_70 ) ;
return ( - 1 ) ;
}
}
if ( F_30 ( V_8 , V_8 -> V_39 -> V_73 . V_74 ,
V_8 -> V_39 -> V_73 . V_75 , V_60 ) <= 0 )
{
F_27 ( V_8 , V_87 ) ;
return ( - 1 ) ;
}
V_60 += V_8 -> V_39 -> V_73 . V_75 ;
if ( V_8 -> V_39 -> V_73 . V_76 == 0 )
{
F_27 ( V_8 , V_88 ) ;
F_23 ( V_67 , V_89 ) ;
return ( - 1 ) ;
}
V_64 = F_31 ( V_8 , V_60 , V_8 -> V_39 -> V_73 . V_76 ,
& V_8 -> V_83 -> V_90 ) ;
V_60 += V_8 -> V_39 -> V_73 . V_76 ;
if ( V_64 == NULL )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_67 , V_91 ) ;
return ( - 1 ) ;
}
F_32 ( V_64 , V_92 ) ;
V_65 = F_33 ( V_8 ) ;
for ( V_61 = 0 ; V_61 < F_34 ( V_65 ) ; V_61 ++ )
{
if ( F_35 ( V_64 ,
F_36 ( V_65 , V_61 ) ) >= 0 )
break;
}
if ( V_61 >= F_34 ( V_65 ) )
{
F_27 ( V_8 , V_88 ) ;
F_23 ( V_67 , V_93 ) ;
return ( - 1 ) ;
}
V_8 -> V_83 -> V_94 = F_36 ( V_65 , V_61 ) ;
}
if ( V_8 -> V_83 -> V_95 != NULL )
F_37 ( V_8 -> V_83 -> V_95 ) ;
#if 0
CRYPTO_w_lock(CRYPTO_LOCK_X509);
s->session->peer=s->session->sess_cert->key->x509;
s->session->peer->references++;
CRYPTO_w_unlock(CRYPTO_LOCK_X509);
#else
V_8 -> V_83 -> V_95 = V_8 -> V_83 -> V_96 -> V_97 -> V_98 ;
F_38 ( & V_8 -> V_83 -> V_95 -> V_99 , 1 , V_100 ) ;
#endif
V_8 -> V_39 -> V_77 = V_8 -> V_39 -> V_73 . V_77 ;
memcpy ( V_8 -> V_39 -> V_101 , V_60 , V_8 -> V_39 -> V_73 . V_77 ) ;
return ( 1 ) ;
}
static int F_13 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 , * V_102 ;
int V_61 , V_103 , V_62 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
if ( V_8 -> V_13 == V_27 )
{
if ( ( V_8 -> V_83 == NULL ) ||
( V_8 -> V_83 -> V_104 != V_8 -> V_22 ) )
{
if ( ! F_29 ( V_8 , 0 ) )
{
F_27 ( V_8 , V_70 ) ;
return ( - 1 ) ;
}
}
V_60 = V_10 ;
V_102 = V_60 + 9 ;
* ( V_60 ++ ) = V_105 ;
F_39 ( V_2 , V_60 ) ;
V_103 = V_62 = 0 ;
V_103 = F_40 ( V_8 , F_41 ( V_8 ) , V_102 ) ;
V_102 += V_103 ;
if ( V_103 == 0 )
{
F_23 ( V_106 , V_107 ) ;
return ( - 1 ) ;
}
F_39 ( V_103 , V_60 ) ;
if ( ( V_8 -> V_83 -> V_86 > 0 ) &&
( V_8 -> V_83 -> V_86 <=
V_108 ) )
{
V_61 = V_8 -> V_83 -> V_86 ;
F_39 ( V_61 , V_60 ) ;
memcpy ( V_102 , V_8 -> V_83 -> V_84 , ( unsigned int ) V_61 ) ;
V_102 += V_61 ;
}
else
{
F_39 ( 0 , V_60 ) ;
}
V_8 -> V_39 -> V_109 = V_110 ;
F_39 ( V_110 , V_60 ) ;
F_42 ( V_8 -> V_39 -> V_111 , V_110 ) ;
memcpy ( V_102 , V_8 -> V_39 -> V_111 , V_110 ) ;
V_102 += V_110 ;
V_8 -> V_13 = V_31 ;
V_8 -> V_26 = V_102 - V_10 ;
V_8 -> V_112 = 0 ;
}
return ( F_43 ( V_8 ) ) ;
}
static int F_15 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 , * V_102 ;
int V_113 , V_114 , V_115 , V_61 ;
T_4 * V_116 ;
const T_5 * V_117 ;
const T_6 * V_118 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
if ( V_8 -> V_13 == V_36 )
{
if ( ! F_44 ( V_8 -> V_83 , & V_117 , & V_118 , NULL ) )
{
F_27 ( V_8 , V_88 ) ;
F_23 ( V_119 , V_120 ) ;
return ( - 1 ) ;
}
V_116 = V_8 -> V_83 ;
V_60 = V_10 ;
V_102 = V_60 + 10 ;
* ( V_60 ++ ) = V_121 ;
V_61 = F_45 ( V_8 , V_116 -> V_94 , V_60 ) ;
V_60 += V_61 ;
V_61 = F_46 ( V_117 ) ;
V_116 -> V_122 = V_61 ;
if ( V_61 > 0 ) F_42 ( V_116 -> V_123 , V_61 ) ;
V_61 = F_47 ( V_117 ) ;
V_116 -> V_124 = V_61 ;
if ( V_61 > 0 ) F_42 ( V_116 -> V_125 , V_61 ) ;
if ( V_116 -> V_94 -> V_126 & V_127 )
V_114 = 8 ;
else if ( F_48 ( V_116 -> V_94 ) )
V_114 = 5 ;
else
V_114 = V_61 ;
if ( V_61 < V_114 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_119 , V_128 ) ;
return ( - 1 ) ;
}
V_113 = V_61 - V_114 ;
F_39 ( V_113 , V_60 ) ;
memcpy ( V_102 , V_116 -> V_125 , ( unsigned int ) V_113 ) ;
V_102 += V_113 ;
V_114 = F_49 ( V_116 -> V_96 , V_114 ,
& ( V_116 -> V_125 [ V_113 ] ) , V_102 ,
( V_8 -> V_39 -> V_129 ) ? V_130 : V_131 ) ;
if ( V_114 <= 0 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_119 , V_132 ) ;
return ( - 1 ) ;
}
#ifdef F_50
if ( V_8 -> V_79 & V_133 ) V_102 [ 1 ] ++ ;
if ( V_8 -> V_79 & V_134 )
V_116 -> V_125 [ V_113 ] ++ ;
#endif
F_39 ( V_114 , V_60 ) ;
V_102 += V_114 ;
V_115 = V_116 -> V_122 ;
F_39 ( V_115 , V_60 ) ;
memcpy ( V_102 , V_116 -> V_123 , ( unsigned int ) V_115 ) ;
V_102 += V_115 ;
V_8 -> V_13 = V_38 ;
V_8 -> V_26 = V_102 - V_10 ;
V_8 -> V_112 = 0 ;
}
return ( F_43 ( V_8 ) ) ;
}
static int F_17 ( T_2 * V_8 )
{
unsigned char * V_60 ;
if ( V_8 -> V_13 == V_41 )
{
V_60 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
* ( V_60 ++ ) = V_135 ;
memcpy ( V_60 , V_8 -> V_39 -> V_101 , ( unsigned int ) V_8 -> V_39 -> V_77 ) ;
V_8 -> V_13 = V_42 ;
V_8 -> V_26 = V_8 -> V_39 -> V_77 + 1 ;
V_8 -> V_112 = 0 ;
}
return ( F_43 ( V_8 ) ) ;
}
static int F_20 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 , * V_102 ;
int V_61 ;
unsigned int V_103 ;
int V_136 = 0 ;
unsigned char * V_137 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
V_137 = & ( V_10 [ 2 ] ) ;
if ( V_8 -> V_13 == V_47 )
{
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) ,
V_138 + 1 - V_8 -> V_26 ) ;
if ( V_61 < ( V_139 + 1 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_140 , V_61 ) ) ;
if ( V_10 [ 1 ] != V_141 )
{
F_27 ( V_8 , V_142 ) ;
F_23 ( V_140 , V_143 ) ;
return ( - 1 ) ;
}
V_136 = V_61 - 1 ;
if ( ( V_8 -> V_144 == NULL ) ||
( V_8 -> V_144 -> V_145 -> V_98 == NULL ) ||
( V_8 -> V_144 -> V_145 -> V_146 == NULL ) )
{
V_8 -> V_13 = V_51 ;
}
else
V_8 -> V_13 = V_49 ;
}
if ( V_8 -> V_13 == V_51 )
{
T_7 * V_98 = NULL ;
T_8 * V_147 = NULL ;
V_61 = 0 ;
if ( V_8 -> V_15 -> V_148 != NULL )
{
V_61 = V_8 -> V_15 -> V_148 ( V_8 , & ( V_98 ) , & ( V_147 ) ) ;
}
if ( V_61 < 0 )
{
V_8 -> V_149 = V_150 ;
return ( - 1 ) ;
}
V_8 -> V_149 = V_151 ;
if ( ( V_61 == 1 ) && ( V_147 != NULL ) && ( V_98 != NULL ) )
{
V_8 -> V_13 = V_49 ;
if ( ! F_51 ( V_8 , V_98 ) ||
! F_52 ( V_8 , V_147 ) )
{
V_61 = 0 ;
}
F_37 ( V_98 ) ;
F_53 ( V_147 ) ;
}
else if ( V_61 == 1 )
{
if ( V_98 != NULL ) F_37 ( V_98 ) ;
if ( V_147 != NULL ) F_53 ( V_147 ) ;
F_23 ( V_140 , V_152 ) ;
V_61 = 0 ;
}
if ( V_61 == 0 )
{
V_8 -> V_13 = V_48 ;
V_60 = V_10 ;
* ( V_60 ++ ) = V_69 ;
F_39 ( V_153 , V_60 ) ;
V_8 -> V_112 = 0 ;
V_8 -> V_26 = 3 ;
}
}
if ( V_8 -> V_13 == V_48 )
{
return ( F_43 ( V_8 ) ) ;
}
if ( V_8 -> V_13 == V_49 )
{
T_9 V_15 ;
V_60 = V_10 ;
F_54 ( & V_15 , V_8 -> V_15 -> V_154 ) ;
F_55 ( & V_15 , V_8 -> V_39 -> V_155 ,
( unsigned int ) V_8 -> V_39 -> V_156 ) ;
F_55 ( & V_15 , V_137 , ( unsigned int ) V_136 ) ;
V_103 = F_56 ( V_8 -> V_83 -> V_96 -> V_97 -> V_98 , & V_60 ) ;
F_55 ( & V_15 , V_10 , ( unsigned int ) V_103 ) ;
V_60 = V_10 ;
V_102 = V_60 + 6 ;
* ( V_60 ++ ) = V_157 ;
* ( V_60 ++ ) = V_158 ;
V_103 = F_56 ( V_8 -> V_144 -> V_145 -> V_98 , & V_102 ) ;
F_39 ( V_103 , V_60 ) ;
if ( ! F_57 ( & V_15 , V_102 , & V_103 , V_8 -> V_144 -> V_145 -> V_146 ) )
{
}
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
F_39 ( V_103 , V_60 ) ;
V_102 += V_103 ;
V_8 -> V_13 = V_50 ;
V_8 -> V_26 = V_102 - V_10 ;
V_8 -> V_112 = 0 ;
}
return ( F_43 ( V_8 ) ) ;
}
static int F_18 ( T_2 * V_8 )
{
unsigned char * V_60 ;
int V_61 ;
V_60 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
if ( V_8 -> V_13 == V_43 )
{
V_61 = F_25 ( V_8 , ( char * ) & ( V_60 [ V_8 -> V_26 ] ) , 1 - V_8 -> V_26 ) ;
if ( V_61 < ( 1 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_159 , V_61 ) ) ;
V_8 -> V_13 = V_44 ;
V_8 -> V_26 = 0 ;
if ( * V_60 != V_160 )
{
if ( V_60 [ 0 ] != V_69 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_159 ,
V_71 ) ;
}
else
F_23 ( V_159 ,
V_72 ) ;
return ( - 1 ) ;
}
}
V_60 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
V_61 = F_25 ( V_8 , ( char * ) & ( V_60 [ V_8 -> V_26 ] ) ,
( unsigned int ) V_8 -> V_39 -> V_109 - V_8 -> V_26 ) ;
if ( V_61 < ( ( int ) V_8 -> V_39 -> V_109 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_159 , V_61 ) ) ;
if ( memcmp ( V_60 , V_8 -> V_39 -> V_111 , ( unsigned int ) V_8 -> V_39 -> V_109 ) != 0 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_159 , V_161 ) ;
return ( - 1 ) ;
}
return ( 1 ) ;
}
static int F_19 ( T_2 * V_8 )
{
unsigned char * V_10 ;
unsigned char * V_60 ;
int V_61 ;
V_10 = ( unsigned char * ) V_8 -> V_23 -> V_66 ;
V_60 = V_10 ;
if ( V_8 -> V_13 == V_45 )
{
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) , 1 - V_8 -> V_26 ) ;
if ( V_61 < ( 1 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_162 , V_61 ) ) ;
V_8 -> V_26 = V_61 ;
if ( * V_60 == V_163 )
{
V_8 -> V_13 = V_47 ;
return ( 1 ) ;
}
else if ( * V_60 != V_164 )
{
if ( V_60 [ 0 ] != V_69 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_162 , V_71 ) ;
}
else
F_23 ( V_162 , V_72 ) ;
return ( - 1 ) ;
}
V_8 -> V_13 = V_19 ;
V_8 -> V_26 = 0 ;
}
V_61 = F_25 ( V_8 , ( char * ) & ( V_10 [ V_8 -> V_26 ] ) ,
V_165 - V_8 -> V_26 ) ;
if ( V_61 < ( V_165 - V_8 -> V_26 ) )
return ( F_26 ( V_8 , V_162 , V_61 ) ) ;
if ( ! V_8 -> V_35 )
{
V_8 -> V_83 -> V_86 = V_165 ;
memcpy ( V_8 -> V_83 -> V_84 , V_60 , V_165 ) ;
}
else
{
if ( ! ( V_8 -> V_79 & V_166 ) )
{
if ( memcmp ( V_10 , V_8 -> V_83 -> V_84 ,
( unsigned int ) V_8 -> V_83 -> V_86 ) != 0 )
{
F_27 ( V_8 , V_70 ) ;
F_23 ( V_162 , V_167 ) ;
return ( - 1 ) ;
}
}
}
return ( 1 ) ;
}
int F_30 ( T_2 * V_8 , int type , int V_168 , unsigned char * V_66 )
{
F_24 ( T_7 ) * V_64 = NULL ;
T_8 * V_147 = NULL ;
T_10 * V_169 = NULL ;
int V_61 ;
T_7 * V_98 = NULL ;
int V_11 = 0 ;
V_98 = F_58 ( NULL , & V_66 , ( long ) V_168 ) ;
if ( V_98 == NULL )
{
F_23 ( V_170 , V_171 ) ;
goto V_172;
}
if ( ( V_64 = F_59 () ) == NULL || ! F_60 ( V_64 , V_98 ) )
{
F_23 ( V_170 , V_91 ) ;
goto V_172;
}
V_61 = F_61 ( V_8 , V_64 ) ;
if ( ( V_8 -> V_173 != V_174 ) && ( ! V_61 ) )
{
F_23 ( V_170 , V_175 ) ;
goto V_172;
}
V_169 = F_62 () ;
if ( V_169 == NULL )
{
V_11 = - 1 ;
goto V_172;
}
if ( V_8 -> V_83 -> V_96 ) F_63 ( V_8 -> V_83 -> V_96 ) ;
V_8 -> V_83 -> V_96 = V_169 ;
V_169 -> V_176 [ V_177 ] . V_98 = V_98 ;
V_169 -> V_97 = & ( V_169 -> V_176 [ V_177 ] ) ;
V_147 = F_64 ( V_98 ) ;
V_98 = NULL ;
if ( V_147 == NULL )
{
F_23 ( V_170 , V_178 ) ;
goto V_172;
}
if ( V_147 -> type != V_179 )
{
F_23 ( V_170 , V_180 ) ;
goto V_172;
}
if ( ! F_65 ( V_169 , V_158 ) )
goto V_172;
V_11 = 1 ;
V_172:
F_66 ( V_64 ) ;
F_37 ( V_98 ) ;
F_53 ( V_147 ) ;
return ( V_11 ) ;
}
static int F_49 ( T_10 * V_169 , int V_168 , unsigned char * V_181 ,
unsigned char * V_182 , int V_183 )
{
T_8 * V_147 = NULL ;
int V_61 = - 1 ;
if ( ( V_169 == NULL ) || ( V_169 -> V_97 -> V_98 == NULL ) ||
( ( V_147 = F_64 ( V_169 -> V_97 -> V_98 ) ) == NULL ) )
{
F_23 ( V_184 , V_185 ) ;
return ( - 1 ) ;
}
if ( V_147 -> type != V_179 )
{
F_23 ( V_184 , V_186 ) ;
goto V_24;
}
V_61 = F_67 ( V_168 , V_181 , V_182 , V_147 -> V_147 . V_187 , V_183 ) ;
if ( V_61 < 0 )
F_23 ( V_184 , V_188 ) ;
V_24:
F_53 ( V_147 ) ;
return ( V_61 ) ;
}
