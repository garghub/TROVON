static const T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return ( F_2 () ) ;
else
return ( NULL ) ;
}
int F_3 ( T_2 * V_3 )
{
unsigned long V_4 = ( unsigned long ) time ( NULL ) ;
T_3 * V_5 = NULL ;
int V_6 = - 1 ;
void (* F_4) ( const T_2 * V_7 , int type , int V_8 ) = NULL ;
int V_9 , V_10 ;
F_5 ( & V_4 , sizeof( V_4 ) , 0 ) ;
F_6 () ;
F_7 () ;
if ( V_3 -> V_11 != NULL )
F_4 = V_3 -> V_11 ;
else if ( V_3 -> V_12 -> V_11 != NULL )
F_4 = V_3 -> V_12 -> V_11 ;
V_3 -> V_13 ++ ;
if ( ! F_8 ( V_3 ) || F_9 ( V_3 ) )
F_10 ( V_3 ) ;
for (; ; ) {
V_10 = V_3 -> V_10 ;
switch ( V_3 -> V_10 ) {
case V_14 :
case V_15 :
case V_14 | V_15 :
case V_16 | V_15 :
V_3 -> V_17 = 0 ;
if ( F_4 != NULL )
F_4 ( V_3 , V_18 , 1 ) ;
V_3 -> V_19 = V_2 ;
V_3 -> type = V_15 ;
V_5 = V_3 -> V_20 ;
if ( ( V_5 == NULL ) && ( ( V_5 = F_11 () ) == NULL ) ) {
V_6 = - 1 ;
goto V_21;
}
if ( ! F_12 ( V_5 , V_22 ) ) {
if ( V_5 == V_3 -> V_20 )
V_5 = NULL ;
V_6 = - 1 ;
goto V_21;
}
V_3 -> V_20 = V_5 ;
V_5 = NULL ;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_24 ;
V_3 -> V_12 -> V_25 . V_26 ++ ;
V_3 -> V_27 = F_3 ;
BREAK ;
case V_24 :
case V_28 :
V_3 -> V_29 = 0 ;
V_6 = F_13 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_30 ;
BREAK ;
case V_30 :
case V_31 :
V_6 = F_14 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_21;
V_3 -> V_23 = 0 ;
if ( ! V_3 -> V_32 ) {
V_3 -> V_10 = V_33 ;
BREAK ;
} else {
V_3 -> V_10 = V_34 ;
break;
}
case V_33 :
case V_35 :
V_6 = F_15 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_34 ;
break;
case V_34 :
if ( ! F_16 ( V_3 , 1 ) ) {
V_6 = - 1 ;
goto V_21;
}
V_3 -> V_36 -> V_37 = 0 ;
V_3 -> V_10 = V_38 ;
break;
case V_38 :
case V_39 :
V_6 = F_17 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_40 ;
break;
case V_40 :
case V_41 :
V_6 = F_18 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_42 ;
break;
case V_42 :
case V_43 :
V_6 = F_19 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_21;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_6 = F_20 ( V_3 ) ;
if ( V_6 <= 0 )
goto V_21;
V_3 -> V_23 = 0 ;
V_3 -> V_10 = V_42 ;
break;
case V_16 :
if ( V_3 -> V_20 != NULL ) {
F_21 ( V_3 -> V_20 ) ;
V_3 -> V_20 = NULL ;
}
V_3 -> V_23 = 0 ;
F_22 ( V_3 , V_49 ) ;
if ( V_3 -> V_32 )
V_3 -> V_12 -> V_25 . V_50 ++ ;
V_6 = 1 ;
V_3 -> V_12 -> V_25 . V_51 ++ ;
if ( F_4 != NULL )
F_4 ( V_3 , V_52 , 1 ) ;
goto V_21;
default:
F_23 ( V_53 , V_54 ) ;
return ( - 1 ) ;
}
if ( ( F_4 != NULL ) && ( V_3 -> V_10 != V_10 ) ) {
V_9 = V_3 -> V_10 ;
V_3 -> V_10 = V_10 ;
F_4 ( V_3 , V_55 , 1 ) ;
V_3 -> V_10 = V_9 ;
}
}
V_21:
V_3 -> V_13 -- ;
if ( V_5 != NULL )
F_21 ( V_5 ) ;
if ( F_4 != NULL )
F_4 ( V_3 , V_56 , V_6 ) ;
return ( V_6 ) ;
}
static int F_14 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 ;
int V_58 , V_59 ;
unsigned long V_60 ;
F_24 ( V_61 ) * V_62 = NULL , * V_63 , * V_64 , * V_65 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
V_57 = V_5 ;
if ( V_3 -> V_10 == V_30 ) {
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) , 11 - V_3 -> V_23 ) ;
if ( V_58 < ( 11 - V_3 -> V_23 ) )
return ( F_26 ( V_3 , V_67 , V_58 ) ) ;
V_3 -> V_23 = 11 ;
if ( * ( V_57 ++ ) != V_68 ) {
if ( V_57 [ - 1 ] != V_69 ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 , V_71 ) ;
} else
F_23 ( V_67 , V_72 ) ;
return ( - 1 ) ;
}
# if 0
s->hit = (*(p++)) ? 1 : 0;
# else
V_3 -> V_32 = ( * V_57 ) ? 1 : 0 ;
V_57 ++ ;
# endif
V_3 -> V_36 -> V_73 . V_74 = * ( V_57 ++ ) ;
F_28 ( V_57 , V_58 ) ;
if ( V_58 < V_3 -> V_19 )
V_3 -> V_19 = V_58 ;
F_28 ( V_57 , V_58 ) ;
V_3 -> V_36 -> V_73 . V_75 = V_58 ;
F_28 ( V_57 , V_58 ) ;
V_3 -> V_36 -> V_73 . V_76 = V_58 ;
F_28 ( V_57 , V_58 ) ;
V_3 -> V_36 -> V_73 . V_77 = V_58 ;
V_3 -> V_10 = V_31 ;
}
V_60 =
11 + ( unsigned long ) V_3 -> V_36 -> V_73 . V_75 +
( unsigned long ) V_3 -> V_36 -> V_73 . V_76 +
( unsigned long ) V_3 -> V_36 -> V_73 . V_77 ;
if ( V_60 > V_22 ) {
F_23 ( V_67 , V_78 ) ;
return - 1 ;
}
V_59 = ( int ) V_60 - V_3 -> V_23 ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) , V_59 ) ;
if ( V_58 != V_59 )
return ( F_26 ( V_3 , V_67 , V_58 ) ) ;
if ( V_3 -> V_79 ) {
V_3 -> V_79 ( 0 , V_3 -> V_19 , 0 , V_5 , ( V_80 ) V_60 , V_3 ,
V_3 -> V_81 ) ;
}
V_57 = V_5 + 11 ;
if ( V_3 -> V_32 ) {
if ( V_3 -> V_36 -> V_73 . V_75 != 0 ) {
F_23 ( V_67 , V_82 ) ;
return ( - 1 ) ;
}
if ( V_3 -> V_36 -> V_73 . V_74 != 0 ) {
if ( ! ( V_3 -> V_83 & V_84 ) ) {
F_23 ( V_67 ,
V_85 ) ;
return ( - 1 ) ;
}
}
if ( V_3 -> V_36 -> V_73 . V_76 != 0 ) {
F_23 ( V_67 , V_86 ) ;
return ( - 1 ) ;
}
} else {
# if 0
memset(s->session->session_id, 0,
SSL_MAX_SSL_SESSION_ID_LENGTH_IN_BYTES);
s->session->session_id_length = 0;
# endif
if ( V_3 -> V_87 -> V_88 > 0 ) {
if ( ! F_29 ( V_3 , 0 ) ) {
F_27 ( V_3 , V_70 ) ;
return ( - 1 ) ;
}
}
if ( F_30 ( V_3 , V_3 -> V_36 -> V_73 . V_74 ,
V_3 -> V_36 -> V_73 . V_75 , V_57 ) <= 0 ) {
F_27 ( V_3 , V_89 ) ;
return ( - 1 ) ;
}
V_57 += V_3 -> V_36 -> V_73 . V_75 ;
if ( V_3 -> V_36 -> V_73 . V_76 == 0 ) {
F_27 ( V_3 , V_90 ) ;
F_23 ( V_67 , V_91 ) ;
return ( - 1 ) ;
}
V_62 = F_31 ( V_3 , V_57 , V_3 -> V_36 -> V_73 . V_76 ,
& V_3 -> V_87 -> V_92 ) ;
V_57 += V_3 -> V_36 -> V_73 . V_76 ;
if ( V_62 == NULL ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 , V_93 ) ;
return ( - 1 ) ;
}
( void ) F_32 ( V_62 , V_94 ) ;
V_63 = F_33 ( V_3 ) ;
( void ) F_32 ( V_63 , V_94 ) ;
if ( V_3 -> V_83 & V_95 ) {
V_64 = V_62 ;
V_65 = V_63 ;
} else {
V_64 = V_63 ;
V_65 = V_62 ;
}
for ( V_58 = 0 ; V_58 < F_34 ( V_64 ) ; V_58 ++ ) {
if ( F_35 ( V_65 , F_36 ( V_64 , V_58 ) ) >= 0 )
break;
}
if ( V_58 >= F_34 ( V_64 ) ) {
F_27 ( V_3 , V_90 ) ;
F_23 ( V_67 , V_96 ) ;
return ( - 1 ) ;
}
V_3 -> V_87 -> V_97 = F_36 ( V_64 , V_58 ) ;
if ( V_3 -> V_87 -> V_98 != NULL ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 , V_99 ) ;
return ( - 1 ) ;
}
V_3 -> V_87 -> V_98 = V_3 -> V_87 -> V_100 -> V_101 -> V_102 ;
F_37 ( & V_3 -> V_87 -> V_98 -> V_103 , 1 , V_104 ) ;
}
if ( V_3 -> V_87 -> V_100 == NULL
|| V_3 -> V_87 -> V_98 != V_3 -> V_87 -> V_100 -> V_101 -> V_102 )
{
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 , V_99 ) ;
return ( - 1 ) ;
}
V_3 -> V_36 -> V_77 = V_3 -> V_36 -> V_73 . V_77 ;
if ( V_3 -> V_36 -> V_77 > sizeof V_3 -> V_36 -> V_105 ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_67 , V_106 ) ;
return - 1 ;
}
memcpy ( V_3 -> V_36 -> V_105 , V_57 , V_3 -> V_36 -> V_73 . V_77 ) ;
return ( 1 ) ;
}
static int F_13 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 , * V_107 ;
int V_58 , V_108 , V_59 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
if ( V_3 -> V_10 == V_24 ) {
if ( ( V_3 -> V_87 == NULL ) || ( V_3 -> V_87 -> V_109 != V_3 -> V_19 ) ) {
if ( ! F_29 ( V_3 , 0 ) ) {
F_27 ( V_3 , V_70 ) ;
return ( - 1 ) ;
}
}
V_57 = V_5 ;
V_107 = V_57 + 9 ;
* ( V_57 ++ ) = V_110 ;
F_38 ( V_2 , V_57 ) ;
V_108 = V_59 = 0 ;
V_108 = F_39 ( V_3 , F_33 ( V_3 ) , V_107 , 0 ) ;
V_107 += V_108 ;
if ( V_108 == 0 ) {
F_23 ( V_111 , V_112 ) ;
return ( - 1 ) ;
}
F_38 ( V_108 , V_57 ) ;
if ( ( V_3 -> V_87 -> V_88 > 0 ) &&
( V_3 -> V_87 -> V_88 <=
V_113 ) ) {
V_58 = V_3 -> V_87 -> V_88 ;
F_38 ( V_58 , V_57 ) ;
memcpy ( V_107 , V_3 -> V_87 -> V_114 , ( unsigned int ) V_58 ) ;
V_107 += V_58 ;
} else {
F_38 ( 0 , V_57 ) ;
}
V_3 -> V_36 -> V_115 = V_116 ;
F_38 ( V_116 , V_57 ) ;
if ( F_40 ( V_3 -> V_36 -> V_117 , V_116 ) <= 0 )
return - 1 ;
memcpy ( V_107 , V_3 -> V_36 -> V_117 , V_116 ) ;
V_107 += V_116 ;
V_3 -> V_10 = V_28 ;
V_3 -> V_23 = V_107 - V_5 ;
V_3 -> V_118 = 0 ;
}
return ( F_41 ( V_3 ) ) ;
}
static int F_15 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 , * V_107 ;
int V_119 , V_120 , V_121 , V_58 ;
T_4 * V_122 ;
const T_5 * V_123 ;
const T_6 * V_124 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
if ( V_3 -> V_10 == V_33 ) {
if ( ! F_42 ( V_3 -> V_87 , & V_123 , & V_124 , NULL , NULL , NULL ) ) {
F_27 ( V_3 , V_90 ) ;
F_23 ( V_125 ,
V_126 ) ;
return ( - 1 ) ;
}
V_122 = V_3 -> V_87 ;
V_57 = V_5 ;
V_107 = V_57 + 10 ;
* ( V_57 ++ ) = V_127 ;
V_58 = F_43 ( V_3 , V_122 -> V_97 , V_57 ) ;
V_57 += V_58 ;
V_58 = F_44 ( V_123 ) ;
V_122 -> V_128 = V_58 ;
if ( V_58 > V_129 ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_125 , V_99 ) ;
return - 1 ;
}
if ( V_58 > 0 )
if ( F_40 ( V_122 -> V_130 , V_58 ) <= 0 )
return - 1 ;
V_58 = F_45 ( V_123 ) ;
V_122 -> V_131 = V_58 ;
if ( V_58 > 0 ) {
if ( V_58 > ( int ) sizeof( V_122 -> V_132 ) ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_125 , V_99 ) ;
return - 1 ;
}
if ( F_46 ( V_122 -> V_132 , V_58 ) <= 0 ) {
F_27 ( V_3 , V_70 ) ;
return ( - 1 ) ;
}
}
if ( V_122 -> V_97 -> V_133 & V_134 )
V_120 = 8 ;
else if ( F_47 ( V_122 -> V_97 ) )
V_120 = 5 ;
else
V_120 = V_58 ;
if ( ( int ) V_58 < V_120 ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_125 , V_135 ) ;
return ( - 1 ) ;
}
V_119 = V_58 - V_120 ;
F_38 ( V_119 , V_57 ) ;
memcpy ( V_107 , V_122 -> V_132 , ( unsigned int ) V_119 ) ;
V_107 += V_119 ;
V_120 = F_48 ( V_122 -> V_100 , V_120 ,
& ( V_122 -> V_132 [ V_119 ] ) , V_107 ,
( V_3 ->
V_36 -> V_136 ) ? V_137
: V_138 ) ;
if ( V_120 <= 0 ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_125 , V_139 ) ;
return ( - 1 ) ;
}
# ifdef F_49
if ( V_3 -> V_83 & V_140 )
V_107 [ 1 ] ++ ;
if ( V_3 -> V_83 & V_141 )
V_122 -> V_132 [ V_119 ] ++ ;
# endif
F_38 ( V_120 , V_57 ) ;
V_107 += V_120 ;
V_121 = V_122 -> V_128 ;
F_38 ( V_121 , V_57 ) ;
if ( V_121 > ( int ) sizeof( V_122 -> V_130 ) ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_125 , V_99 ) ;
return - 1 ;
}
memcpy ( V_107 , V_122 -> V_130 , ( unsigned int ) V_121 ) ;
V_107 += V_121 ;
V_3 -> V_10 = V_35 ;
V_3 -> V_23 = V_107 - V_5 ;
V_3 -> V_118 = 0 ;
}
return ( F_41 ( V_3 ) ) ;
}
static int F_17 ( T_2 * V_3 )
{
unsigned char * V_57 ;
if ( V_3 -> V_10 == V_38 ) {
V_57 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
* ( V_57 ++ ) = V_142 ;
if ( V_3 -> V_36 -> V_77 > sizeof V_3 -> V_36 -> V_105 ) {
F_23 ( V_143 , V_99 ) ;
return - 1 ;
}
memcpy ( V_57 , V_3 -> V_36 -> V_105 , ( unsigned int ) V_3 -> V_36 -> V_77 ) ;
V_3 -> V_10 = V_39 ;
V_3 -> V_23 = V_3 -> V_36 -> V_77 + 1 ;
V_3 -> V_118 = 0 ;
}
return ( F_41 ( V_3 ) ) ;
}
static int F_20 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 , * V_107 ;
int V_58 ;
unsigned int V_108 ;
int V_144 ;
unsigned char * V_145 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
if ( V_3 -> V_10 == V_44 ) {
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) ,
V_146 + 2 - V_3 -> V_23 ) ;
if ( V_58 < ( V_147 + 2 - V_3 -> V_23 ) )
return ( F_26 ( V_3 , V_148 , V_58 ) ) ;
V_3 -> V_23 += V_58 ;
if ( V_3 -> V_79 ) {
V_3 -> V_79 ( 0 , V_3 -> V_19 , 0 , V_5 , ( V_80 ) V_3 -> V_23 , V_3 ,
V_3 -> V_81 ) ;
}
if ( V_5 [ 1 ] != V_149 ) {
F_27 ( V_3 , V_150 ) ;
F_23 ( V_148 , V_151 ) ;
return ( - 1 ) ;
}
if ( ( V_3 -> V_152 == NULL ) ||
( V_3 -> V_152 -> V_153 -> V_102 == NULL ) ||
( V_3 -> V_152 -> V_153 -> V_154 == NULL ) ) {
V_3 -> V_10 = V_48 ;
} else
V_3 -> V_10 = V_46 ;
}
V_145 = V_5 + 2 ;
V_144 = V_3 -> V_23 - 2 ;
if ( V_3 -> V_10 == V_48 ) {
T_7 * V_102 = NULL ;
T_8 * V_155 = NULL ;
V_58 = 0 ;
if ( V_3 -> V_12 -> V_156 != NULL ) {
V_58 = V_3 -> V_12 -> V_156 ( V_3 , & ( V_102 ) , & ( V_155 ) ) ;
}
if ( V_58 < 0 ) {
V_3 -> V_157 = V_158 ;
return ( - 1 ) ;
}
V_3 -> V_157 = V_159 ;
if ( ( V_58 == 1 ) && ( V_155 != NULL ) && ( V_102 != NULL ) ) {
V_3 -> V_10 = V_46 ;
if ( ! F_50 ( V_3 , V_102 ) || ! F_51 ( V_3 , V_155 ) ) {
V_58 = 0 ;
}
F_52 ( V_102 ) ;
F_53 ( V_155 ) ;
} else if ( V_58 == 1 ) {
if ( V_102 != NULL )
F_52 ( V_102 ) ;
if ( V_155 != NULL )
F_53 ( V_155 ) ;
F_23 ( V_148 ,
V_160 ) ;
V_58 = 0 ;
}
if ( V_58 == 0 ) {
V_3 -> V_10 = V_45 ;
V_57 = V_5 ;
* ( V_57 ++ ) = V_69 ;
F_38 ( V_161 , V_57 ) ;
V_3 -> V_118 = 0 ;
V_3 -> V_23 = 3 ;
}
}
if ( V_3 -> V_10 == V_45 ) {
return ( F_41 ( V_3 ) ) ;
}
if ( V_3 -> V_10 == V_46 ) {
T_9 V_12 ;
V_57 = V_5 ;
F_54 ( & V_12 ) ;
F_55 ( & V_12 , V_3 -> V_12 -> V_162 , NULL ) ;
F_56 ( & V_12 , V_3 -> V_36 -> V_163 , V_3 -> V_36 -> V_164 ) ;
F_56 ( & V_12 , V_145 , ( unsigned int ) V_144 ) ;
V_58 = F_57 ( V_3 -> V_87 -> V_100 -> V_101 -> V_102 , & V_57 ) ;
if ( V_58 > 0 )
F_56 ( & V_12 , V_5 , ( unsigned int ) V_58 ) ;
V_57 = V_5 ;
V_107 = V_57 + 6 ;
* ( V_57 ++ ) = V_165 ;
* ( V_57 ++ ) = V_166 ;
V_108 = F_57 ( V_3 -> V_152 -> V_153 -> V_102 , & V_107 ) ;
F_38 ( V_108 , V_57 ) ;
if ( ! F_58 ( & V_12 , V_107 , & V_108 , V_3 -> V_152 -> V_153 -> V_154 ) ) {
}
F_59 ( & V_12 ) ;
F_38 ( V_108 , V_57 ) ;
V_107 += V_108 ;
V_3 -> V_10 = V_47 ;
V_3 -> V_23 = V_107 - V_5 ;
V_3 -> V_118 = 0 ;
}
return ( F_41 ( V_3 ) ) ;
}
static int F_18 ( T_2 * V_3 )
{
unsigned char * V_57 ;
int V_58 , V_108 , V_60 ;
V_57 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
if ( V_3 -> V_10 == V_40 ) {
V_58 = F_25 ( V_3 , ( char * ) & ( V_57 [ V_3 -> V_23 ] ) , 1 - V_3 -> V_23 ) ;
if ( V_58 < ( 1 - V_3 -> V_23 ) )
return ( F_26 ( V_3 , V_167 , V_58 ) ) ;
V_3 -> V_23 += V_58 ;
V_3 -> V_10 = V_41 ;
if ( * V_57 != V_168 ) {
if ( V_57 [ 0 ] != V_69 ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_167 , V_71 ) ;
} else {
F_23 ( V_167 , V_72 ) ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_57 [ V_3 -> V_23 ] ) , 3 - V_3 -> V_23 ) ;
return F_26 ( V_3 , V_167 , V_58 ) ;
}
return ( - 1 ) ;
}
}
V_57 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
V_60 = 1 + V_3 -> V_36 -> V_115 ;
V_108 = V_60 - V_3 -> V_23 ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_57 [ V_3 -> V_23 ] ) , V_108 ) ;
if ( V_58 < V_108 )
return ( F_26 ( V_3 , V_167 , V_58 ) ) ;
if ( V_3 -> V_79 ) {
V_3 -> V_79 ( 0 , V_3 -> V_19 , 0 , V_57 , V_60 , V_3 , V_3 -> V_81 ) ;
}
V_57 += 1 ;
if ( F_60 ( V_57 , V_3 -> V_36 -> V_117 , V_3 -> V_36 -> V_115 ) != 0 ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_167 , V_169 ) ;
return ( - 1 ) ;
}
return ( 1 ) ;
}
static int F_19 ( T_2 * V_3 )
{
unsigned char * V_5 ;
unsigned char * V_57 ;
int V_58 , V_108 , V_60 ;
V_5 = ( unsigned char * ) V_3 -> V_20 -> V_66 ;
V_57 = V_5 ;
if ( V_3 -> V_10 == V_42 ) {
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) , 1 - V_3 -> V_23 ) ;
if ( V_58 < ( 1 - V_3 -> V_23 ) )
return ( F_26 ( V_3 , V_170 , V_58 ) ) ;
V_3 -> V_23 += V_58 ;
if ( * V_57 == V_171 ) {
V_3 -> V_10 = V_44 ;
return ( 1 ) ;
} else if ( * V_57 != V_172 ) {
if ( V_57 [ 0 ] != V_69 ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_170 ,
V_71 ) ;
} else {
F_23 ( V_170 , V_72 ) ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_57 [ V_3 -> V_23 ] ) , 3 - V_3 -> V_23 ) ;
return F_26 ( V_3 , V_167 , V_58 ) ;
}
return ( - 1 ) ;
}
V_3 -> V_10 = V_43 ;
}
V_60 = 1 + V_173 ;
V_108 = V_60 - V_3 -> V_23 ;
V_58 = F_25 ( V_3 , ( char * ) & ( V_5 [ V_3 -> V_23 ] ) , V_108 ) ;
if ( V_58 < V_108 ) {
return ( F_26 ( V_3 , V_170 , V_58 ) ) ;
}
V_3 -> V_23 += V_58 ;
if ( V_3 -> V_79 ) {
V_3 -> V_79 ( 0 , V_3 -> V_19 , 0 , V_5 , ( V_80 ) V_3 -> V_23 , V_3 ,
V_3 -> V_81 ) ;
}
if ( ! V_3 -> V_32 ) {
V_3 -> V_87 -> V_88 = V_173 ;
memcpy ( V_3 -> V_87 -> V_114 , V_57 + 1 , V_173 ) ;
} else {
if ( ! ( V_3 -> V_83 & V_174 ) ) {
if ( ( V_3 -> V_87 -> V_88 >
sizeof V_3 -> V_87 -> V_114 )
|| ( 0 !=
memcmp ( V_5 + 1 , V_3 -> V_87 -> V_114 ,
( unsigned int ) V_3 -> V_87 -> V_88 ) ) ) {
F_27 ( V_3 , V_70 ) ;
F_23 ( V_170 ,
V_175 ) ;
return ( - 1 ) ;
}
}
}
V_3 -> V_10 = V_16 ;
return ( 1 ) ;
}
int F_30 ( T_2 * V_3 , int type , int V_60 , const unsigned char * V_66 )
{
F_24 ( T_7 ) * V_62 = NULL ;
T_8 * V_155 = NULL ;
T_10 * V_176 = NULL ;
int V_58 ;
T_7 * V_102 = NULL ;
int V_6 = 0 ;
V_102 = F_61 ( NULL , & V_66 , ( long ) V_60 ) ;
if ( V_102 == NULL ) {
F_23 ( V_177 , V_178 ) ;
goto V_179;
}
if ( ( V_62 = F_62 () ) == NULL || ! F_63 ( V_62 , V_102 ) ) {
F_23 ( V_177 , V_93 ) ;
goto V_179;
}
V_58 = F_64 ( V_3 , V_62 ) ;
if ( ( V_3 -> V_180 != V_181 ) && ( V_58 <= 0 ) ) {
F_23 ( V_177 , V_182 ) ;
goto V_179;
}
F_6 () ;
V_3 -> V_87 -> V_183 = V_3 -> V_183 ;
V_176 = F_65 () ;
if ( V_176 == NULL ) {
V_6 = - 1 ;
goto V_179;
}
if ( V_3 -> V_87 -> V_100 )
F_66 ( V_3 -> V_87 -> V_100 ) ;
V_3 -> V_87 -> V_100 = V_176 ;
V_176 -> V_184 [ V_185 ] . V_102 = V_102 ;
V_176 -> V_101 = & ( V_176 -> V_184 [ V_185 ] ) ;
V_155 = F_67 ( V_102 ) ;
V_102 = NULL ;
if ( V_155 == NULL ) {
F_23 ( V_177 ,
V_186 ) ;
goto V_179;
}
if ( V_155 -> type != V_187 ) {
F_23 ( V_177 , V_188 ) ;
goto V_179;
}
if ( ! F_68 ( V_176 , V_166 ) )
goto V_179;
V_6 = 1 ;
V_179:
F_69 ( V_62 ) ;
F_52 ( V_102 ) ;
F_53 ( V_155 ) ;
return ( V_6 ) ;
}
static int F_48 ( T_10 * V_176 , int V_60 , unsigned char * V_189 ,
unsigned char * V_190 , int V_191 )
{
T_8 * V_155 = NULL ;
int V_58 = - 1 ;
if ( ( V_176 == NULL ) || ( V_176 -> V_101 -> V_102 == NULL ) ||
( ( V_155 = F_67 ( V_176 -> V_101 -> V_102 ) ) == NULL ) ) {
F_23 ( V_192 , V_193 ) ;
return ( - 1 ) ;
}
if ( V_155 -> type != V_187 ) {
F_23 ( V_192 , V_194 ) ;
goto V_21;
}
V_58 = F_70 ( V_60 , V_189 , V_190 , V_155 -> V_155 . V_195 , V_191 ) ;
if ( V_58 < 0 )
F_23 ( V_192 , V_196 ) ;
V_21:
F_53 ( V_155 ) ;
return ( V_58 ) ;
}
