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
F_34 ( V_102 ) ;
while ( V_86 . V_82 >= V_86 . V_77 ) {
F_35 ( & V_86 . V_103 , & V_102 , V_104 ) ;
F_30 () ;
if ( V_86 . V_105 ) {
F_36 ( & V_86 . V_103 , & V_102 ) ;
return V_93 > 0 ? V_93 : - V_106 ;
}
if ( V_86 . V_82 < V_86 . V_77 )
break;
F_37 ( V_107 ) ;
if ( F_38 ( V_108 ) ) {
F_36 ( & V_86 . V_103 , & V_102 ) ;
return V_93 > 0 ? V_93 : - V_109 ;
}
}
F_36 ( & V_86 . V_103 , & V_102 ) ;
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
static unsigned int F_39 ( struct V_36 * V_36 , struct V_110 * V_102 )
{
unsigned int V_111 = 0 ;
int V_112 ;
if ( V_86 . V_73 == 0 ) {
if ( ( V_112 = F_26 ( & V_86 ) ) < 0 )
return V_112 ;
return 0 ;
}
if ( V_36 -> V_113 & V_114 )
F_40 ( V_36 , & V_86 . V_103 , V_102 ) ;
if ( V_36 -> V_113 & V_114 )
if ( V_86 . V_82 < V_86 . V_77 || V_86 . V_78 - V_86 . V_83 > 0 )
V_111 |= V_115 | V_116 ;
return V_111 ;
}
static inline void F_41 ( struct V_60 * V_61 )
{
F_42 ( & V_61 -> V_103 ) ;
F_42 ( & V_61 -> V_117 ) ;
F_42 ( & V_61 -> V_118 ) ;
V_61 -> V_41 = 0 ;
}
static int F_43 ( struct V_60 * V_61 , struct V_36 * V_36 , T_10 V_119 ,
int V_120 , int V_121 )
{
int V_122 = 0 ;
if ( V_36 -> V_113 & V_119 ) {
if ( V_61 -> V_41 ) {
#if 0
rc = -EBUSY;
if (file->f_flags & O_NONBLOCK)
return rc;
rc = -EINTR;
if (wait_event_interruptible(sq->open_queue, !sq->busy))
return rc;
rc = 0;
#else
return - V_123 ;
#endif
}
V_61 -> V_41 = 1 ;
if ( ( V_122 = F_22 ( V_61 , V_120 , V_121 ) ) ) {
#if 0
sq_wake_up(sq, file, mode);
#else
V_61 -> V_41 = 0 ;
#endif
return V_122 ;
}
V_61 -> V_105 = V_36 -> V_124 & V_125 ;
}
return V_122 ;
}
static int F_44 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
int V_122 ;
F_8 ( & V_37 ) ;
if ( ! F_9 ( V_1 . V_2 . V_38 ) ) {
F_10 ( & V_37 ) ;
return - V_39 ;
}
V_122 = F_45 ( V_36 ) ;
if ( V_122 )
goto V_126;
if ( V_36 -> V_113 & V_127 ) {
V_122 = - V_128 ;
goto V_126;
}
if ( V_1 . V_2 . F_44 )
V_1 . V_2 . F_44 ( V_36 -> V_113 ) ;
V_1 . V_9 = F_46 ( V_35 ) & 0x0f ;
if ( V_129 == 0 ) {
V_1 . V_7 = V_1 . V_2 . V_130 ;
V_1 . V_11 = V_1 . V_2 . V_130 ;
V_1 . V_80 = V_1 . V_2 . V_131 ;
}
#ifndef F_47
if ( V_1 . V_9 == V_132 ) {
F_3 ( 8000 ) ;
F_4 ( 0 ) ;
F_2 ( V_19 ) ;
}
#endif
F_10 ( & V_37 ) ;
return 0 ;
V_126:
F_12 ( V_1 . V_2 . V_38 ) ;
F_10 ( & V_37 ) ;
return V_122 ;
}
static void F_48 ( void )
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
static void F_49 ( void )
{
F_48 () ;
V_99 = 0 ;
}
static int F_50 ( void )
{
int V_122 = 0 ;
int V_133 = 5 ;
V_86 . V_84 |= 1 ;
F_30 () ;
while ( V_86 . V_85 ) {
F_51 ( V_86 . V_118 ,
! V_86 . V_85 , V_107 ) ;
if ( F_38 ( V_108 ) ) {
F_48 () ;
V_122 = - V_109 ;
break;
}
if ( ! -- V_133 ) {
F_29 ( V_134 L_4 ) ;
F_48 () ;
V_122 = - V_135 ;
break;
}
}
V_86 . V_84 = 0 ;
return V_122 ;
}
static int F_52 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
int V_122 = 0 ;
F_8 ( & V_37 ) ;
if ( V_36 -> V_113 & V_114 ) {
if ( V_86 . V_41 )
V_122 = F_50 () ;
F_48 () ;
F_53 () ;
V_86 . V_41 = 0 ;
}
if ( V_36 -> V_113 & V_129 ) {
V_129 = 0 ;
V_99 = 0 ;
V_1 . V_80 = V_1 . V_2 . V_131 ;
}
F_12 ( V_1 . V_2 . V_38 ) ;
#if 0
read_sq_wake_up(file);
write_sq_wake_up(file);
#endif
F_10 ( & V_37 ) ;
return V_122 ;
}
static int F_54 ( T_10 V_136 )
{
if ( V_129 )
return ( V_129 & V_136 ) != 0 ;
else {
V_129 = V_136 ;
return 1 ;
}
}
static int F_55 ( void )
{
if ( V_86 . V_73 )
return 0 ;
return 1 ;
}
static int F_56 ( struct V_60 * V_61 , int V_137 , int V_63 )
{
if ( V_61 -> V_73 ) {
#ifdef F_28
F_29 ( L_5 ) ;
#endif
return - V_54 ;
}
if ( ( V_63 < V_138 ) || ( V_63 > V_139 ) )
return - V_54 ;
V_63 = ( 1 << V_63 ) ;
if ( V_63 > V_61 -> V_67 )
return - V_54 ;
if ( V_137 <= 0 )
return - V_54 ;
if ( V_137 > V_61 -> V_66 )
V_137 = V_61 -> V_66 ;
V_61 -> V_75 =
V_61 -> V_77 = V_137 ;
V_61 -> V_79 = V_63 ;
return 0 ;
}
static int F_57 ( struct V_36 * V_36 , T_6 V_42 , T_7 V_43 )
{
int V_140 , V_141 ;
T_7 V_142 ;
int V_143 ;
int V_63 , V_144 ;
T_11 V_49 ;
switch ( V_42 ) {
case V_145 :
F_49 () ;
return 0 ;
break ;
case V_146 :
V_142 = V_1 . V_2 . V_147 ;
return F_15 ( V_43 , V_142 ) ;
break ;
case V_148 :
V_63 = 0 ;
if ( V_36 -> V_113 & V_114 ) {
if ( ! V_86 . V_73 )
F_26 ( & V_86 ) ;
V_63 = V_86 . V_79 ;
}
return F_15 ( V_43 , V_63 ) ;
break ;
case V_149 :
V_86 . V_84 |= 0x2 ;
F_30 () ;
return 0 ;
case V_150 :
V_141 = 0 ;
if ( V_36 -> V_113 & V_114 ) {
V_141 = F_50 () ;
F_48 () ;
}
if ( V_36 -> V_113 & V_129 )
V_99 = 0 ;
return V_141 ;
break ;
case V_151 :
return F_15 ( V_43 , V_1 . V_7 . V_6 ) ;
case V_152 :
if ( F_54 ( V_36 -> V_113 ) ) {
F_58 ( V_43 , V_143 ) ;
V_143 = F_3 ( V_143 ) ;
V_99 = 0 ;
return F_15 ( V_43 , V_143 ) ;
} else
return - V_54 ;
break ;
case V_153 :
if ( F_54 ( V_36 -> V_113 ) &&
F_55 () ) {
F_58 ( V_43 , V_143 ) ;
V_99 = 0 ;
return F_15 ( V_43 , F_4 ( V_143 ) ) ;
} else
return - V_54 ;
break ;
case V_154 :
if ( F_54 ( V_36 -> V_113 ) &&
F_55 () ) {
F_58 ( V_43 , V_143 ) ;
V_99 = 0 ;
return F_15 ( V_43 , F_4 ( V_143 - 1 ) + 1 ) ;
} else
return - V_54 ;
break ;
case V_155 :
if ( F_54 ( V_36 -> V_113 ) &&
F_55 () ) {
int V_4 ;
F_58 ( V_43 , V_143 ) ;
V_99 = 0 ;
V_4 = F_2 ( V_143 ) ;
V_141 = F_15 ( V_43 , V_4 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( V_4 != V_143 && V_143 != V_156 )
return - V_54 ;
return 0 ;
} else
return - V_54 ;
case V_157 :
return - V_54 ;
case V_158 :
F_58 ( V_43 , V_143 ) ;
V_141 = 0 ;
V_144 = ( V_143 >> 16 ) & 0x7fff ;
V_63 = V_143 & 0xffff ;
if ( V_36 -> V_113 & V_114 ) {
V_141 = F_56 ( & V_86 , V_144 , V_63 ) ;
if ( V_141 )
return V_141 ;
}
return F_15 ( V_43 , V_143 ) ;
break ;
case V_159 :
if ( V_36 -> V_113 & V_114 ) {
if ( ! V_86 . V_73 )
F_26 ( & V_86 ) ;
V_49 . V_160 = V_86 . V_77 - V_86 . V_82 ;
V_49 . V_161 = V_86 . V_77 ;
V_49 . V_162 = V_86 . V_79 ;
V_49 . V_163 = V_49 . V_160 * V_49 . V_162 ;
if ( F_17 ( ( void T_4 * ) V_43 , & V_49 , sizeof( V_49 ) ) )
return - V_53 ;
return 0 ;
} else
return - V_54 ;
break ;
case V_164 :
V_140 = V_1 . V_2 . V_165 & 0xffffff00 ;
return F_15 ( V_43 , V_140 ) ;
default:
return F_13 ( V_36 , V_42 , V_43 ) ;
}
return - V_54 ;
}
static long F_59 ( struct V_36 * V_36 , T_6 V_42 , T_7 V_43 )
{
int V_55 ;
F_8 ( & V_37 ) ;
V_55 = F_57 ( V_36 , V_42 , V_43 ) ;
F_10 ( & V_37 ) ;
return V_55 ;
}
static int F_60 ( void )
{
const struct V_166 * V_167 = & V_168 ;
#ifndef F_20
int V_169 ;
#endif
V_169 = F_61 ( V_167 , - 1 ) ;
if ( V_169 < 0 ) {
F_29 ( V_170 L_6 ) ;
return V_169 ;
}
F_62 () ;
if ( V_129 == 0 ) {
V_1 . V_7 = V_1 . V_2 . V_130 ;
V_1 . V_80 = V_1 . V_2 . V_131 ;
V_1 . V_11 = V_1 . V_2 . V_130 ;
V_99 = 0 ;
}
return 0 ;
}
static char * F_63 ( int V_171 )
{
switch( V_171 ) {
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
static int F_64 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
char * V_172 = V_173 . V_174 ;
int V_175 = 0 ;
int V_55 ;
F_8 ( & V_37 ) ;
V_55 = - V_123 ;
if ( V_173 . V_41 )
goto V_126;
V_55 = - V_39 ;
if ( ! F_9 ( V_1 . V_2 . V_38 ) )
goto V_126;
V_173 . V_176 = 0 ;
V_173 . V_41 = 1 ;
V_175 += sprintf ( V_172 + V_175 , L_17 ,
V_1 . V_2 . V_52 , ( V_177 << 4 ) +
( ( V_1 . V_2 . V_178 >> 8 ) & 0x0f ) ) ;
V_175 += sprintf ( V_172 + V_175 ,
L_18 ,
V_177 , V_179 , V_1 . V_2 . V_51 ,
( V_1 . V_2 . V_178 >> 8 ) , ( V_1 . V_2 . V_178 & 0xff ) ) ;
if ( V_1 . V_2 . V_180 )
V_175 += V_1 . V_2 . V_180 ( V_172 + V_175 ,
( T_5 ) V_181 ) ;
V_175 += sprintf ( V_172 + V_175 , L_19 ) ;
V_175 += sprintf ( V_172 + V_175 , L_20 , L_21 , L_22 ) ;
V_175 += sprintf ( V_172 + V_175 , L_23 ,
F_63 ( V_1 . V_7 . V_4 ) ,
F_63 ( V_1 . V_80 . V_4 ) ) ;
V_175 += sprintf ( V_172 + V_175 , L_24 ,
V_1 . V_7 . V_6 , V_1 . V_80 . V_6 ) ;
V_175 += sprintf ( V_172 + V_175 , L_25 ,
V_1 . V_7 . V_12 ? L_26 : L_27 ,
V_1 . V_80 . V_12 ? L_26 : L_27 ) ;
V_175 += sprintf ( V_172 + V_175 , L_28 ) ;
V_175 += sprintf ( V_172 + V_175 , L_29 , L_30 , L_31 ) ;
V_175 += sprintf ( V_172 + V_175 , L_32 ,
L_33 , V_86 . V_66 , V_86 . V_67 ) ;
V_175 += sprintf ( V_172 + V_175 ,
L_34
L_35 ) ;
V_175 += sprintf ( V_172 + V_175 , L_36 ,
L_33 , V_86 . V_76 , V_86 . V_78 ,
V_86 . V_77 , V_86 . V_81 , V_86 . V_87 ,
V_86 . V_82 , V_86 . V_83 , V_86 . V_85 ,
V_86 . V_41 , V_86 . V_84 , V_86 . V_73 , V_86 . V_182 ) ;
#ifdef F_28
F_29 ( L_37 , V_175 ) ;
#endif
if ( V_175 >= V_183 )
F_29 ( V_170 L_38 ) ;
V_173 . V_175 = V_175 ;
V_55 = 0 ;
V_126:
F_10 ( & V_37 ) ;
return V_55 ;
}
static int F_65 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
F_8 ( & V_37 ) ;
V_173 . V_41 = 0 ;
F_12 ( V_1 . V_2 . V_38 ) ;
F_10 ( & V_37 ) ;
return 0 ;
}
static T_1 F_66 ( struct V_36 * V_36 , char T_4 * V_174 , T_5 V_82 ,
T_9 * V_92 )
{
int V_184 = V_173 . V_175 - V_173 . V_176 ;
if ( V_184 > V_82 )
V_184 = V_82 ;
if ( V_184 <= 0 )
return 0 ;
if ( F_17 ( V_174 , & V_173 . V_174 [ V_173 . V_176 ] , V_184 ) )
return - V_53 ;
V_173 . V_176 += V_184 ;
return V_184 ;
}
static int F_67 ( void )
{
#ifndef F_20
int V_185 ;
#endif
V_185 = F_68 ( & V_186 , V_187 ) ;
if ( V_185 < 0 )
return V_185 ;
V_173 . V_41 = 0 ;
return 0 ;
}
int F_69 ( void )
{
int V_188 ;
#ifdef F_20
if ( V_189 )
return - V_123 ;
#endif
if ( ( V_188 = F_60 () ) < 0 )
return V_188 ;
if ( ( V_188 = F_67 () ) < 0 )
return V_188 ;
F_19 () ;
if ( ! V_1 . V_2 . V_190 () ) {
F_29 ( V_170 L_39 ) ;
return - V_39 ;
}
#ifdef F_20
V_189 = 1 ;
#endif
F_29 ( V_191 L_40 ,
V_1 . V_2 . V_52 , ( V_177 << 4 ) +
( ( V_1 . V_2 . V_178 >> 8 ) & 0x0f ) ) ;
F_29 ( V_191
L_18 ,
V_177 , V_179 , V_1 . V_2 . V_51 ,
( V_1 . V_2 . V_178 >> 8 ) , ( V_1 . V_2 . V_178 & 0xff ) ) ;
F_29 ( V_191 L_41 ,
V_192 , V_193 ) ;
return 0 ;
}
void F_70 ( void )
{
if ( V_189 ) {
F_1 () ;
V_1 . V_2 . V_194 () ;
V_189 = 0 ;
}
F_53 () ;
if ( V_56 >= 0 )
F_71 ( V_56 ) ;
if ( V_185 >= 0 )
F_72 ( V_185 ) ;
if ( V_169 >= 0 )
F_73 ( V_169 ) ;
}
static int F_74 ( char * V_195 )
{
int V_196 [ 6 ] , V_63 ;
V_195 = F_75 ( V_195 , F_76 ( V_196 ) , V_196 ) ;
switch ( V_196 [ 0 ] ) {
case 3 :
if ( ( V_196 [ 3 ] < 0 ) || ( V_196 [ 3 ] > V_197 ) )
F_29 ( L_42 , V_198 ) ;
else
V_198 = V_196 [ 3 ] ;
case 2 :
if ( V_196 [ 1 ] < V_199 )
F_29 ( L_43 , V_192 ) ;
else
V_192 = V_196 [ 1 ] ;
case 1 :
if ( ( V_63 = V_196 [ 2 ] ) < 256 )
V_63 <<= 10 ;
if ( V_63 < V_200 || V_63 > V_201 )
F_29 ( L_44 , V_193 ) ;
else
V_193 = V_63 ;
case 0 :
break;
default:
F_29 ( L_45 ) ;
return 0 ;
}
return 1 ;
}
