static inline void F_1 ( void )
{
V_1 . V_2 . V_3 () ;
}
static inline int F_2 ( int V_4 )
{
return V_1 . V_2 . V_5 ( V_4 ) ;
}
static int F_3 ( int V_6 )
{
if ( V_6 < 0 )
return V_1 . V_7 . V_6 ;
if ( V_1 . V_2 . V_8 &&
( V_6 > V_1 . V_2 . V_8 ) )
V_6 = V_1 . V_2 . V_8 ;
V_1 . V_7 . V_6 = V_6 ;
if ( V_1 . V_9 == V_10 )
V_1 . V_11 . V_6 = V_1 . V_7 . V_6 ;
return V_1 . V_7 . V_6 ;
}
static int F_4 ( int V_12 )
{
if ( V_12 < 0 )
return V_1 . V_7 . V_12 ;
V_12 = ! ! V_12 ;
V_1 . V_7 . V_12 = V_12 ;
if ( V_1 . V_9 == V_10 )
V_1 . V_11 . V_12 = V_12 ;
return V_12 ;
}
static T_1 F_5 ( T_2 * V_13 , const T_3 T_4 * V_14 ,
T_5 V_15 , T_3 V_16 [] ,
T_1 * V_17 , T_1 V_18 )
{
T_1 (* F_6)( const T_3 T_4 * , T_5 , T_3 * , T_1 * , T_1 );
switch ( V_1 . V_7 . V_4 ) {
case V_19 :
F_6 = V_13 -> V_20 ;
break;
case V_21 :
F_6 = V_13 -> V_22 ;
break;
case V_23 :
F_6 = V_13 -> V_24 ;
break;
case V_25 :
F_6 = V_13 -> V_26 ;
break;
case V_27 :
F_6 = V_13 -> V_28 ;
break;
case V_29 :
F_6 = V_13 -> V_30 ;
break;
case V_31 :
F_6 = V_13 -> V_32 ;
break;
case V_33 :
F_6 = V_13 -> V_34 ;
break;
default:
return 0 ;
}
if ( F_6 )
return F_6 ( V_14 , V_15 , V_16 , V_17 , V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
F_8 ( & V_37 ) ;
if ( ! F_9 ( V_1 . V_2 . V_38 ) ) {
F_10 ( & V_37 ) ;
return - V_39 ;
}
V_40 . V_41 = 1 ;
F_10 ( & V_37 ) ;
return 0 ;
}
static int F_11 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
F_8 ( & V_37 ) ;
V_40 . V_41 = 0 ;
F_12 ( V_1 . V_2 . V_38 ) ;
F_10 ( & V_37 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_36 , T_6 V_42 , T_7 V_43 )
{
if ( F_14 ( V_42 ) & V_44 )
V_40 . V_45 ++ ;
switch ( V_42 ) {
case V_46 :
return F_15 ( V_43 , V_47 ) ;
case V_48 :
{
T_8 V_49 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
F_16 ( V_49 . V_50 , V_1 . V_2 . V_51 , sizeof( V_49 . V_50 ) ) ;
F_16 ( V_49 . V_52 , V_1 . V_2 . V_51 , sizeof( V_49 . V_52 ) ) ;
V_49 . V_45 = V_40 . V_45 ;
if ( F_17 ( ( void T_4 * ) V_43 , & V_49 , sizeof( V_49 ) ) )
return - V_53 ;
return 0 ;
}
}
if ( V_1 . V_2 . F_13 )
return V_1 . V_2 . F_13 ( V_42 , V_43 ) ;
return - V_54 ;
}
static long F_18 ( struct V_36 * V_36 , T_6 V_42 , T_7 V_43 )
{
int V_55 ;
F_8 ( & V_37 ) ;
V_55 = F_13 ( V_36 , V_42 , V_43 ) ;
F_10 ( & V_37 ) ;
return V_55 ;
}
static void F_19 ( void )
{
#ifndef F_20
int V_56 ;
#endif
V_56 = F_21 ( & V_57 , - 1 ) ;
if ( V_56 < 0 )
return;
V_40 . V_41 = 0 ;
V_1 . V_58 = 0 ;
V_1 . V_59 = 0 ;
if ( V_1 . V_2 . F_19 )
V_1 . V_2 . F_19 () ;
}
static int F_22 ( struct V_60 * V_61 , int V_62 , int V_63 )
{
int V_64 ;
if ( V_61 -> V_65 )
return 0 ;
V_61 -> V_66 = V_62 ;
V_61 -> V_67 = V_63 ;
V_61 -> V_65 = F_23 ( V_62 * sizeof( char * ) , V_68 ) ;
if ( ! V_61 -> V_65 )
return - V_69 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
V_61 -> V_65 [ V_64 ] = V_1 . V_2 . V_70 ( V_63 , V_68 ) ;
if ( ! V_61 -> V_65 [ V_64 ] ) {
while ( V_64 -- )
V_1 . V_2 . V_71 ( V_61 -> V_65 [ V_64 ] , V_63 ) ;
F_24 ( V_61 -> V_65 ) ;
V_61 -> V_65 = NULL ;
return - V_69 ;
}
}
return 0 ;
}
static void F_25 ( struct V_60 * V_61 )
{
int V_64 ;
if ( V_61 -> V_65 ) {
for ( V_64 = 0 ; V_64 < V_61 -> V_66 ; V_64 ++ )
V_1 . V_2 . V_71 ( V_61 -> V_65 [ V_64 ] , V_61 -> V_67 ) ;
F_24 ( V_61 -> V_65 ) ;
V_61 -> V_65 = NULL ;
}
}
static int F_26 ( struct V_60 * V_61 )
{
int (* F_27)( void ) = NULL ;
int V_72 ;
if ( V_61 -> V_73 ) {
#ifdef F_28
F_29 ( L_1 ) ;
#endif
return - V_54 ;
}
V_61 -> V_73 = 1 ;
V_1 . V_2 . V_74 () ;
if ( V_61 -> V_75 <= 0 ) {
V_61 -> V_76 = V_61 -> V_66 ;
V_61 -> V_77 = V_61 -> V_66 ;
V_61 -> V_78 = V_61 -> V_67 ;
V_61 -> V_75 = V_61 -> V_66 ;
V_61 -> V_79 = V_61 -> V_67 ;
V_61 -> V_79 *=
( V_1 . V_7 . V_63 * ( V_1 . V_7 . V_12 + 1 ) ) ;
V_61 -> V_79 /=
( V_1 . V_80 . V_63 * ( V_1 . V_80 . V_12 + 1 ) ) ;
} else {
V_61 -> V_78 = V_61 -> V_79 ;
V_61 -> V_78 *=
( V_1 . V_80 . V_63 * ( V_1 . V_80 . V_12 + 1 ) ) ;
V_61 -> V_78 /=
( V_1 . V_7 . V_63 * ( V_1 . V_7 . V_12 + 1 ) ) ;
V_61 -> V_78 *= V_1 . V_80 . V_6 ;
V_61 -> V_78 /= V_1 . V_7 . V_6 ;
V_72 =
( V_1 . V_80 . V_63 * ( V_1 . V_80 . V_12 + 1 ) ) / 8 ;
V_61 -> V_78 += ( V_72 - 1 ) ;
V_61 -> V_78 &= ~ ( V_72 - 1 ) ;
if ( V_61 -> V_78 <= 0 || V_61 -> V_78 > V_61 -> V_67 ) {
#ifdef F_28
F_29 ( L_2 , V_61 -> V_79 ) ;
#endif
V_61 -> V_78 = V_61 -> V_67 ;
}
if ( V_61 -> V_75 <= V_61 -> V_66 ) {
V_61 -> V_76 = V_61 -> V_75 ;
V_61 -> V_77 = ( V_61 -> V_77 <= V_61 -> V_76 ) ?
V_61 -> V_77 : V_61 -> V_76 ;
} else {
#ifdef F_28
F_29 ( L_3 , V_61 -> V_75 ) ;
#endif
V_61 -> V_76 =
V_61 -> V_77 = V_61 -> V_66 ;
}
}
V_61 -> V_81 = V_61 -> V_82 = V_61 -> V_83 = 0 ;
V_61 -> V_84 = 0 ;
V_61 -> V_85 = 0 ;
if ( V_61 == & V_86 ) {
V_61 -> V_87 = - 1 ;
F_27 = V_1 . V_2 . V_88 ;
}
if ( F_27 )
return F_27 () ;
return 0 ;
}
static inline void F_30 ( void )
{
V_1 . V_2 . V_89 () ;
}
static T_1 F_31 ( struct V_36 * V_36 , const char T_4 * V_90 , T_5 V_91 ,
T_9 * V_92 )
{
T_1 V_93 = 0 ;
T_3 * V_94 ;
T_1 V_95 = 0 , V_96 , V_97 ;
unsigned long V_98 ;
if ( V_91 == 0 )
return 0 ;
if ( V_99 == 0 ) {
V_1 . V_2 . V_74 () ;
V_99 = 1 ;
}
if ( V_86 . V_73 == 0 ) {
if ( ( V_93 = F_26 ( & V_86 ) ) < 0 ) return V_93 ;
V_93 = 0 ;
}
F_32 ( & V_1 . V_100 , V_98 ) ;
V_86 . V_84 &= ~ 2 ;
F_33 ( & V_1 . V_100 , V_98 ) ;
if ( V_86 . V_82 > 0 &&
( V_97 = V_86 . V_78 - V_86 . V_83 ) > 0 ) {
V_94 = V_86 . V_65 [ V_86 . V_87 ] ;
V_96 = V_86 . V_83 ;
V_95 = F_5 ( V_1 . V_101 , V_90 , V_91 ,
V_94 , & V_96 , V_97 ) ;
if ( V_95 <= 0 )
return V_95 ;
V_90 += V_95 ;
V_93 += V_95 ;
V_91 = ( V_95 <= V_91 ) ? ( V_91 - V_95 ) : 0 ;
V_86 . V_83 = V_96 ;
}
while ( V_91 ) {
while ( V_86 . V_82 >= V_86 . V_77 ) {
F_30 () ;
if ( V_86 . V_102 )
return V_93 > 0 ? V_93 : - V_103 ;
F_34 ( V_86 . V_104 ) ;
if ( F_35 ( V_105 ) )
return V_93 > 0 ? V_93 : - V_106 ;
}
V_94 = V_86 . V_65 [ ( V_86 . V_87 + 1 ) % V_86 . V_76 ] ;
V_96 = 0 ;
V_97 = V_86 . V_78 ;
V_95 = F_5 ( V_1 . V_101 , V_90 , V_91 ,
V_94 , & V_96 , V_97 ) ;
if ( V_95 <= 0 )
break;
V_90 += V_95 ;
V_93 += V_95 ;
V_91 = ( V_95 <= V_91 ) ? ( V_91 - V_95 ) : 0 ;
if ( V_96 ) {
V_86 . V_87 = ( V_86 . V_87 + 1 ) % V_86 . V_76 ;
V_86 . V_83 = V_96 ;
V_86 . V_82 ++ ;
}
}
F_30 () ;
return V_95 < 0 ? V_95 : V_93 ;
}
static unsigned int F_36 ( struct V_36 * V_36 , struct V_107 * V_108 )
{
unsigned int V_109 = 0 ;
int V_110 ;
if ( V_86 . V_73 == 0 ) {
if ( ( V_110 = F_26 ( & V_86 ) ) < 0 )
return V_110 ;
return 0 ;
}
if ( V_36 -> V_111 & V_112 )
F_37 ( V_36 , & V_86 . V_104 , V_108 ) ;
if ( V_36 -> V_111 & V_112 )
if ( V_86 . V_82 < V_86 . V_77 || V_86 . V_78 - V_86 . V_83 > 0 )
V_109 |= V_113 | V_114 ;
return V_109 ;
}
static inline void F_38 ( struct V_60 * V_61 )
{
F_39 ( & V_61 -> V_104 ) ;
F_39 ( & V_61 -> V_115 ) ;
F_39 ( & V_61 -> V_116 ) ;
V_61 -> V_41 = 0 ;
}
static int F_40 ( struct V_60 * V_61 , struct V_36 * V_36 , T_10 V_117 ,
int V_118 , int V_119 )
{
int V_120 = 0 ;
if ( V_36 -> V_111 & V_117 ) {
if ( V_61 -> V_41 ) {
#if 0
rc = -EBUSY;
if (file->f_flags & O_NONBLOCK)
return rc;
rc = -EINTR;
while (sq->busy) {
SLEEP(sq->open_queue);
if (signal_pending(current))
return rc;
}
rc = 0;
#else
return - V_121 ;
#endif
}
V_61 -> V_41 = 1 ;
if ( ( V_120 = F_22 ( V_61 , V_118 , V_119 ) ) ) {
#if 0
sq_wake_up(sq, file, mode);
#else
V_61 -> V_41 = 0 ;
#endif
return V_120 ;
}
V_61 -> V_102 = V_36 -> V_122 & V_123 ;
}
return V_120 ;
}
static int F_41 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
int V_120 ;
F_8 ( & V_37 ) ;
if ( ! F_9 ( V_1 . V_2 . V_38 ) ) {
F_10 ( & V_37 ) ;
return - V_39 ;
}
V_120 = F_42 ( V_36 ) ;
if ( V_120 )
goto V_124;
if ( V_36 -> V_111 & V_125 ) {
V_120 = - V_126 ;
goto V_124;
}
if ( V_1 . V_2 . F_41 )
V_1 . V_2 . F_41 ( V_36 -> V_111 ) ;
V_1 . V_9 = F_43 ( V_35 ) & 0x0f ;
if ( V_127 == 0 ) {
V_1 . V_7 = V_1 . V_2 . V_128 ;
V_1 . V_11 = V_1 . V_2 . V_128 ;
V_1 . V_80 = V_1 . V_2 . V_129 ;
}
#ifndef F_44
if ( V_1 . V_9 == V_130 ) {
F_3 ( 8000 ) ;
F_4 ( 0 ) ;
F_2 ( V_19 ) ;
}
#endif
F_10 ( & V_37 ) ;
return 0 ;
V_124:
F_12 ( V_1 . V_2 . V_38 ) ;
F_10 ( & V_37 ) ;
return V_120 ;
}
static void F_45 ( void )
{
F_1 () ;
V_86 . V_85 = 0 ;
V_86 . V_82 = 0 ;
V_86 . V_83 = 0 ;
V_86 . V_81 = 0 ;
V_86 . V_87 = - 1 ;
V_86 . V_73 = 0 ;
V_86 . V_75 = 0 ;
V_86 . V_79 = 0 ;
}
static void F_46 ( void )
{
F_45 () ;
V_99 = 0 ;
}
static int F_47 ( struct V_36 * V_131 , struct V_132 * V_132 )
{
int V_120 = 0 ;
int V_133 = 5 ;
V_86 . V_84 |= 1 ;
F_30 () ;
while ( V_86 . V_85 ) {
F_34 ( V_86 . V_116 ) ;
if ( F_35 ( V_105 ) ) {
F_45 () ;
V_120 = - V_106 ;
break;
}
if ( ! -- V_133 ) {
F_29 ( V_134 L_4 ) ;
F_45 () ;
V_120 = - V_135 ;
break;
}
}
V_86 . V_84 = 0 ;
return V_120 ;
}
static int F_48 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
int V_120 = 0 ;
F_8 ( & V_37 ) ;
if ( V_36 -> V_111 & V_112 ) {
if ( V_86 . V_41 )
V_120 = F_47 ( V_36 , V_36 -> V_136 . V_132 ) ;
F_45 () ;
F_49 () ;
V_86 . V_41 = 0 ;
}
if ( V_36 -> V_111 & V_127 ) {
V_127 = 0 ;
V_99 = 0 ;
V_1 . V_80 = V_1 . V_2 . V_129 ;
}
F_12 ( V_1 . V_2 . V_38 ) ;
#if 0
read_sq_wake_up(file);
write_sq_wake_up(file);
#endif
F_10 ( & V_37 ) ;
return V_120 ;
}
static int F_50 ( T_10 V_137 )
{
if ( V_127 )
return ( V_127 & V_137 ) != 0 ;
else {
V_127 = V_137 ;
return 1 ;
}
}
static int F_51 ( void )
{
if ( V_86 . V_73 )
return 0 ;
return 1 ;
}
static int F_52 ( struct V_60 * V_61 , int V_138 , int V_63 )
{
if ( V_61 -> V_73 ) {
#ifdef F_28
F_29 ( L_5 ) ;
#endif
return - V_54 ;
}
if ( ( V_63 < V_139 ) || ( V_63 > V_140 ) )
return - V_54 ;
V_63 = ( 1 << V_63 ) ;
if ( V_63 > V_61 -> V_67 )
return - V_54 ;
if ( V_138 <= 0 )
return - V_54 ;
if ( V_138 > V_61 -> V_66 )
V_138 = V_61 -> V_66 ;
V_61 -> V_75 =
V_61 -> V_77 = V_138 ;
V_61 -> V_79 = V_63 ;
return 0 ;
}
static int F_53 ( struct V_36 * V_36 , T_6 V_42 , T_7 V_43 )
{
int V_141 , V_142 ;
T_7 V_143 ;
int V_144 ;
int V_63 , V_145 ;
T_11 V_49 ;
switch ( V_42 ) {
case V_146 :
F_46 () ;
return 0 ;
break ;
case V_147 :
V_143 = V_1 . V_2 . V_148 ;
return F_15 ( V_43 , V_143 ) ;
break ;
case V_149 :
V_63 = 0 ;
if ( V_36 -> V_111 & V_112 ) {
if ( ! V_86 . V_73 )
F_26 ( & V_86 ) ;
V_63 = V_86 . V_79 ;
}
return F_15 ( V_43 , V_63 ) ;
break ;
case V_150 :
V_86 . V_84 |= 0x2 ;
F_30 () ;
return 0 ;
case V_151 :
V_142 = 0 ;
if ( V_36 -> V_111 & V_112 ) {
V_142 = F_47 ( V_36 , V_36 -> V_136 . V_132 ) ;
F_45 () ;
}
if ( V_36 -> V_111 & V_127 )
V_99 = 0 ;
return V_142 ;
break ;
case V_152 :
return F_15 ( V_43 , V_1 . V_7 . V_6 ) ;
case V_153 :
if ( F_50 ( V_36 -> V_111 ) ) {
F_54 ( V_43 , V_144 ) ;
V_144 = F_3 ( V_144 ) ;
V_99 = 0 ;
return F_15 ( V_43 , V_144 ) ;
} else
return - V_54 ;
break ;
case V_154 :
if ( F_50 ( V_36 -> V_111 ) &&
F_51 () ) {
F_54 ( V_43 , V_144 ) ;
V_99 = 0 ;
return F_15 ( V_43 , F_4 ( V_144 ) ) ;
} else
return - V_54 ;
break ;
case V_155 :
if ( F_50 ( V_36 -> V_111 ) &&
F_51 () ) {
F_54 ( V_43 , V_144 ) ;
V_99 = 0 ;
return F_15 ( V_43 , F_4 ( V_144 - 1 ) + 1 ) ;
} else
return - V_54 ;
break ;
case V_156 :
if ( F_50 ( V_36 -> V_111 ) &&
F_51 () ) {
int V_4 ;
F_54 ( V_43 , V_144 ) ;
V_99 = 0 ;
V_4 = F_2 ( V_144 ) ;
V_142 = F_15 ( V_43 , V_4 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( V_4 != V_144 && V_144 != V_157 )
return - V_54 ;
return 0 ;
} else
return - V_54 ;
case V_158 :
return - V_54 ;
case V_159 :
F_54 ( V_43 , V_144 ) ;
V_142 = 0 ;
V_145 = ( V_144 >> 16 ) & 0x7fff ;
V_63 = V_144 & 0xffff ;
if ( V_36 -> V_111 & V_112 ) {
V_142 = F_52 ( & V_86 , V_145 , V_63 ) ;
if ( V_142 )
return V_142 ;
}
return F_15 ( V_43 , V_144 ) ;
break ;
case V_160 :
if ( V_36 -> V_111 & V_112 ) {
if ( ! V_86 . V_73 )
F_26 ( & V_86 ) ;
V_49 . V_161 = V_86 . V_77 - V_86 . V_82 ;
V_49 . V_162 = V_86 . V_77 ;
V_49 . V_163 = V_86 . V_79 ;
V_49 . V_164 = V_49 . V_161 * V_49 . V_163 ;
if ( F_17 ( ( void T_4 * ) V_43 , & V_49 , sizeof( V_49 ) ) )
return - V_53 ;
return 0 ;
} else
return - V_54 ;
break ;
case V_165 :
V_141 = V_1 . V_2 . V_166 & 0xffffff00 ;
return F_15 ( V_43 , V_141 ) ;
default:
return F_13 ( V_36 , V_42 , V_43 ) ;
}
return - V_54 ;
}
static long F_55 ( struct V_36 * V_36 , T_6 V_42 , T_7 V_43 )
{
int V_55 ;
F_8 ( & V_37 ) ;
V_55 = F_53 ( V_36 , V_42 , V_43 ) ;
F_10 ( & V_37 ) ;
return V_55 ;
}
static int F_56 ( void )
{
const struct V_167 * V_168 = & V_169 ;
#ifndef F_20
int V_170 ;
#endif
V_170 = F_57 ( V_168 , - 1 ) ;
if ( V_170 < 0 ) {
F_29 ( V_171 L_6 ) ;
return V_170 ;
}
F_58 () ;
if ( V_127 == 0 ) {
V_1 . V_7 = V_1 . V_2 . V_128 ;
V_1 . V_80 = V_1 . V_2 . V_129 ;
V_1 . V_11 = V_1 . V_2 . V_128 ;
V_99 = 0 ;
}
return 0 ;
}
static char * F_59 ( int V_172 )
{
switch( V_172 ) {
case V_19 :
return L_7 ;
break;
case V_21 :
return L_8 ;
break;
case V_25 :
return L_9 ;
break;
case V_23 :
return L_10 ;
break;
case V_27 :
return L_11 ;
break;
case V_29 :
return L_12 ;
break;
case V_31 :
return L_13 ;
break;
case V_33 :
return L_14 ;
break;
case 0 :
return L_15 ;
break ;
default:
break ;
}
return L_16 ;
}
static int F_60 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
char * V_173 = V_174 . V_175 ;
int V_176 = 0 ;
int V_55 ;
F_8 ( & V_37 ) ;
V_55 = - V_121 ;
if ( V_174 . V_41 )
goto V_124;
V_55 = - V_39 ;
if ( ! F_9 ( V_1 . V_2 . V_38 ) )
goto V_124;
V_174 . V_177 = 0 ;
V_174 . V_41 = 1 ;
V_176 += sprintf ( V_173 + V_176 , L_17 ,
V_1 . V_2 . V_52 , ( V_178 << 4 ) +
( ( V_1 . V_2 . V_179 >> 8 ) & 0x0f ) ) ;
V_176 += sprintf ( V_173 + V_176 ,
L_18 ,
V_178 , V_180 , V_1 . V_2 . V_51 ,
( V_1 . V_2 . V_179 >> 8 ) , ( V_1 . V_2 . V_179 & 0xff ) ) ;
if ( V_1 . V_2 . V_181 )
V_176 += V_1 . V_2 . V_181 ( V_173 + V_176 ,
( T_5 ) V_182 ) ;
V_176 += sprintf ( V_173 + V_176 , L_19 ) ;
V_176 += sprintf ( V_173 + V_176 , L_20 , L_21 , L_22 ) ;
V_176 += sprintf ( V_173 + V_176 , L_23 ,
F_59 ( V_1 . V_7 . V_4 ) ,
F_59 ( V_1 . V_80 . V_4 ) ) ;
V_176 += sprintf ( V_173 + V_176 , L_24 ,
V_1 . V_7 . V_6 , V_1 . V_80 . V_6 ) ;
V_176 += sprintf ( V_173 + V_176 , L_25 ,
V_1 . V_7 . V_12 ? L_26 : L_27 ,
V_1 . V_80 . V_12 ? L_26 : L_27 ) ;
V_176 += sprintf ( V_173 + V_176 , L_28 ) ;
V_176 += sprintf ( V_173 + V_176 , L_29 , L_30 , L_31 ) ;
V_176 += sprintf ( V_173 + V_176 , L_32 ,
L_33 , V_86 . V_66 , V_86 . V_67 ) ;
V_176 += sprintf ( V_173 + V_176 ,
L_34
L_35 ) ;
V_176 += sprintf ( V_173 + V_176 , L_36 ,
L_33 , V_86 . V_76 , V_86 . V_78 ,
V_86 . V_77 , V_86 . V_81 , V_86 . V_87 ,
V_86 . V_82 , V_86 . V_83 , V_86 . V_85 ,
V_86 . V_41 , V_86 . V_84 , V_86 . V_73 , V_86 . V_183 ) ;
#ifdef F_28
F_29 ( L_37 , V_176 ) ;
#endif
if ( V_176 >= V_184 )
F_29 ( V_171 L_38 ) ;
V_174 . V_176 = V_176 ;
V_55 = 0 ;
V_124:
F_10 ( & V_37 ) ;
return V_55 ;
}
static int F_61 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
F_8 ( & V_37 ) ;
V_174 . V_41 = 0 ;
F_12 ( V_1 . V_2 . V_38 ) ;
F_10 ( & V_37 ) ;
return 0 ;
}
static T_1 F_62 ( struct V_36 * V_36 , char T_4 * V_175 , T_5 V_82 ,
T_9 * V_92 )
{
int V_185 = V_174 . V_176 - V_174 . V_177 ;
if ( V_185 > V_82 )
V_185 = V_82 ;
if ( V_185 <= 0 )
return 0 ;
if ( F_17 ( V_175 , & V_174 . V_175 [ V_174 . V_177 ] , V_185 ) )
return - V_53 ;
V_174 . V_177 += V_185 ;
return V_185 ;
}
static int F_63 ( void )
{
#ifndef F_20
int V_186 ;
#endif
V_186 = F_64 ( & V_187 , V_188 ) ;
if ( V_186 < 0 )
return V_186 ;
V_174 . V_41 = 0 ;
return 0 ;
}
int F_65 ( void )
{
int V_189 ;
#ifdef F_20
if ( V_190 )
return - V_121 ;
#endif
if ( ( V_189 = F_56 () ) < 0 )
return V_189 ;
if ( ( V_189 = F_63 () ) < 0 )
return V_189 ;
F_19 () ;
if ( ! V_1 . V_2 . V_191 () ) {
F_29 ( V_171 L_39 ) ;
return - V_39 ;
}
#ifdef F_20
V_190 = 1 ;
#endif
F_29 ( V_192 L_40 ,
V_1 . V_2 . V_52 , ( V_178 << 4 ) +
( ( V_1 . V_2 . V_179 >> 8 ) & 0x0f ) ) ;
F_29 ( V_192
L_18 ,
V_178 , V_180 , V_1 . V_2 . V_51 ,
( V_1 . V_2 . V_179 >> 8 ) , ( V_1 . V_2 . V_179 & 0xff ) ) ;
F_29 ( V_192 L_41 ,
V_193 , V_194 ) ;
return 0 ;
}
void F_66 ( void )
{
if ( V_190 ) {
F_1 () ;
V_1 . V_2 . V_195 () ;
V_190 = 0 ;
}
F_49 () ;
if ( V_56 >= 0 )
F_67 ( V_56 ) ;
if ( V_186 >= 0 )
F_68 ( V_186 ) ;
if ( V_170 >= 0 )
F_69 ( V_170 ) ;
}
static int F_70 ( char * V_196 )
{
int V_197 [ 6 ] , V_63 ;
V_196 = F_71 ( V_196 , F_72 ( V_197 ) , V_197 ) ;
switch ( V_197 [ 0 ] ) {
case 3 :
if ( ( V_197 [ 3 ] < 0 ) || ( V_197 [ 3 ] > V_198 ) )
F_29 ( L_42 , V_199 ) ;
else
V_199 = V_197 [ 3 ] ;
case 2 :
if ( V_197 [ 1 ] < V_200 )
F_29 ( L_43 , V_193 ) ;
else
V_193 = V_197 [ 1 ] ;
case 1 :
if ( ( V_63 = V_197 [ 2 ] ) < 256 )
V_63 <<= 10 ;
if ( V_63 < V_201 || V_63 > V_202 )
F_29 ( L_44 , V_194 ) ;
else
V_194 = V_63 ;
case 0 :
break;
default:
F_29 ( L_45 ) ;
return 0 ;
}
return 1 ;
}
