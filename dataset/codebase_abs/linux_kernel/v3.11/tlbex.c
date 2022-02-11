static inline int F_1 ( void )
{
return 0 ;
}
static inline int F_2 ( void )
{
return 0 ;
}
static inline int T_1 F_3 ( void )
{
return V_1 ;
}
static inline int T_1 F_4 ( void )
{
return V_2 ;
}
static int F_5 ( void )
{
switch ( F_6 () ) {
case V_3 :
case V_4 :
case V_5 :
return 1 ;
default:
return 0 ;
}
}
static int F_7 ( void )
{
switch ( F_6 () ) {
case V_5 :
return 1 ;
default:
return 0 ;
}
}
static bool F_8 ( void )
{
return true ;
}
static int F_9 ( int V_6 )
{
V_6 += 1 ;
return V_7 * 128 - ( 8 * V_6 ) - 32768 ;
}
static bool F_8 ( void )
{
return false ;
}
static int F_9 ( int V_6 )
{
F_10 () ;
return 0 ;
}
static int F_11 ( void )
{
return ( V_8 . V_9 & 0xffff00 ) ==
( V_10 | V_11 ) ;
}
static void F_12 ( T_2 * * V_12 , struct V_13 * * V_14 , int V_15 )
{
switch ( V_15 ) {
case 0 ... 7 :
F_13 ( V_12 , V_14 , 0 , V_16 + V_15 ) ;
return;
default:
F_10 () ;
}
}
static void F_14 ( struct V_17 * * V_18 , T_2 * * V_12 , int V_15 )
{
switch ( V_15 ) {
case 0 ... 7 :
F_15 ( V_18 , * V_12 , V_16 + V_15 ) ;
break;
default:
F_10 () ;
}
}
static void F_16 ( void )
{
#define F_17 ( T_3 , ... ) \
pr_debug("#define " fmt, ##__VA_ARGS__)
F_18 ( L_1 ) ;
F_18 ( L_2 ) ;
F_18 ( L_3 ) ;
F_17 ( L_4 , V_19 ) ;
F_17 ( L_5 , V_20 ) ;
F_17 ( L_6 , V_21 ) ;
F_17 ( L_7 , V_22 ) ;
F_17 ( L_8 , V_23 ) ;
#ifdef F_19
F_17 ( L_9 , V_24 ) ;
F_17 ( L_10 , V_25 ) ;
#endif
if ( V_26 ) {
#ifdef F_20
F_17 ( L_11 , F_20 ) ;
#endif
#ifdef F_21
F_17 ( L_12 , F_21 ) ;
#endif
}
F_17 ( L_13 , V_27 ) ;
F_17 ( L_14 , V_28 ) ;
F_17 ( L_15 , V_29 ) ;
F_17 ( L_16 , V_30 ) ;
F_18 ( L_3 ) ;
}
static inline void F_22 ( const char * V_31 , const T_2 * V_32 , int V_33 )
{
int V_6 ;
F_18 ( L_17 , V_31 ) ;
F_18 ( L_18 ) ;
F_18 ( L_19 ) ;
for ( V_6 = 0 ; V_6 < V_33 ; V_6 ++ )
F_18 ( L_20 , V_32 [ V_6 ] , & V_32 [ V_6 ] ) ;
F_18 ( L_21 ) ;
F_18 ( L_22 , V_31 ) ;
}
static inline int T_1 F_23 ( void )
{
switch ( F_6 () ) {
case V_34 :
case V_35 :
return 22 ;
default:
return 31 ;
}
}
static int F_24 ( void )
{
int V_14 ;
unsigned int V_36 = V_37 [ 0 ] . V_38 & ~ V_39 ;
V_14 = F_25 ( V_36 ) ;
if ( V_14 == 0 )
return - 1 ;
V_14 -- ;
V_39 |= ( 1 << V_14 ) ;
return V_14 ;
}
static struct V_40 F_26 ( T_2 * * V_12 )
{
struct V_40 V_14 ;
int V_41 ;
int V_42 ;
int V_43 ;
if ( V_44 >= 0 ) {
F_27 ( V_12 , 1 , F_23 () , V_44 ) ;
V_14 . V_45 = V_46 ;
V_14 . V_47 = V_48 ;
V_14 . V_49 = 1 ;
return V_14 ;
}
if ( F_28 () > 1 ) {
#ifdef F_29
V_43 = 51 ;
V_41 = 20 ;
V_42 = 0 ;
#else
# ifdef F_30
V_43 = 25 ;
V_41 = 4 ;
V_42 = 0 ;
# endif
# ifdef F_31
V_43 = 26 ;
V_41 = 4 ;
V_42 = 0 ;
# endif
#endif
F_32 ( V_12 , V_46 , V_41 , V_42 ) ;
F_33 ( V_12 , V_46 , V_46 , V_43 ) ;
F_34 ( V_12 , V_46 , V_46 , F_35 ( sizeof( struct V_50 ) ) ) ;
F_36 ( V_12 , V_48 , ( long ) & V_51 ) ;
F_37 ( V_12 , V_46 , V_46 , V_48 ) ;
} else {
F_36 ( V_12 , V_46 , ( long ) & V_51 ) ;
}
F_38 ( V_12 , 1 , F_39 ( struct V_50 , V_36 ) , V_46 ) ;
F_38 ( V_12 , 2 , F_39 ( struct V_50 , V_52 ) , V_46 ) ;
V_14 . V_45 = V_48 ;
V_14 . V_47 = 1 ;
V_14 . V_49 = 2 ;
return V_14 ;
}
static void F_40 ( T_2 * * V_12 )
{
if ( V_44 >= 0 ) {
F_32 ( V_12 , 1 , F_23 () , V_44 ) ;
return;
}
F_41 ( V_12 , 1 , F_39 ( struct V_50 , V_36 ) , V_46 ) ;
F_41 ( V_12 , 2 , F_39 ( struct V_50 , V_52 ) , V_46 ) ;
}
static void F_42 ( void )
{
long V_53 = ( long ) V_54 ;
T_2 * V_12 ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
V_12 = V_55 ;
F_43 ( & V_12 , V_46 , V_56 ) ;
F_44 ( & V_12 , V_48 , F_45 ( V_53 ) ) ;
F_46 ( & V_12 , V_48 , F_47 ( V_53 ) , V_48 ) ;
F_48 ( & V_12 , V_46 , V_46 , 22 ) ;
F_49 ( & V_12 , V_46 , V_46 , 2 ) ;
F_50 ( & V_12 , V_48 , V_48 , V_46 ) ;
F_43 ( & V_12 , V_46 , V_57 ) ;
F_46 ( & V_12 , V_48 , 0 , V_48 ) ;
F_51 ( & V_12 , V_46 , V_46 , 0xffc ) ;
F_50 ( & V_12 , V_48 , V_48 , V_46 ) ;
F_46 ( & V_12 , V_46 , 0 , V_48 ) ;
F_52 ( & V_12 ) ;
F_53 ( & V_12 , V_46 , V_58 ) ;
F_43 ( & V_12 , V_48 , V_59 ) ;
F_54 ( & V_12 ) ;
F_55 ( & V_12 , V_48 ) ;
F_56 ( & V_12 ) ;
if ( V_12 > V_55 + 32 )
F_57 ( L_23 ) ;
F_18 ( L_24 ,
( unsigned int ) ( V_12 - V_55 ) ) ;
memcpy ( ( void * ) V_60 , V_55 , 0x80 ) ;
F_22 ( L_25 , ( T_2 * ) V_60 , 32 ) ;
}
static void T_1 F_58 ( T_2 * * V_12 )
{
switch ( F_6 () ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
F_52 ( V_12 ) ;
F_59 ( V_12 ) ;
break;
default:
F_59 ( V_12 ) ;
break;
}
}
static void F_60 ( T_2 * * V_12 , struct V_17 * * V_18 ,
struct V_13 * * V_14 ,
enum V_65 V_66 )
{
void (* F_61)( T_2 * * ) = NULL ;
switch ( V_66 ) {
case V_67 : F_61 = F_54 ; break;
case V_68 : F_61 = V_69 ; break;
}
if ( V_70 ) {
switch ( F_6 () ) {
case V_71 :
case V_72 :
break;
default:
F_62 ( V_12 ) ;
break;
}
F_61 ( V_12 ) ;
return;
}
switch ( F_6 () ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
F_12 ( V_12 , V_14 , V_79 ) ;
F_61 ( V_12 ) ;
F_14 ( V_18 , V_12 , V_79 ) ;
V_79 ++ ;
F_52 ( V_12 ) ;
break;
case V_61 :
case V_62 :
F_52 ( V_12 ) ;
F_61 ( V_12 ) ;
F_52 ( V_12 ) ;
break;
case V_63 :
case V_64 :
F_52 ( V_12 ) ;
F_52 ( V_12 ) ;
F_61 ( V_12 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_35 :
F_52 ( V_12 ) ;
F_61 ( V_12 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_71 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
if ( F_11 () )
F_52 ( V_12 ) ;
case V_102 :
F_61 ( V_12 ) ;
break;
case V_103 :
F_52 ( V_12 ) ;
F_52 ( V_12 ) ;
F_52 ( V_12 ) ;
F_52 ( V_12 ) ;
F_61 ( V_12 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
F_52 ( V_12 ) ;
F_52 ( V_12 ) ;
F_61 ( V_12 ) ;
F_52 ( V_12 ) ;
F_52 ( V_12 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
F_52 ( V_12 ) ;
F_52 ( V_12 ) ;
F_61 ( V_12 ) ;
break;
case V_112 :
F_61 ( V_12 ) ;
F_52 ( V_12 ) ;
break;
default:
F_57 ( L_26 ,
V_8 . V_113 ) ;
break;
}
}
static T_1 void F_63 ( T_2 * * V_12 ,
unsigned int V_114 )
{
if ( V_26 ) {
F_64 ( V_12 , V_114 , V_114 , F_35 ( V_115 ) ) ;
} else {
#ifdef F_65
F_66 ( V_12 , V_114 , V_114 , F_35 ( V_115 ) ) ;
#else
F_67 ( V_12 , V_114 , V_114 , F_35 ( V_115 ) ) ;
#endif
}
}
static void F_68 ( T_2 * * V_12 , struct V_13 * * V_14 ,
unsigned int V_116 , enum V_117 V_118 ,
int V_119 )
{
if ( V_119 ) {
if ( V_120 >> 16 ) {
F_44 ( V_12 , V_116 , V_120 >> 16 ) ;
F_69 ( V_12 , V_116 , V_116 , V_120 & 0xffff ) ;
F_53 ( V_12 , V_116 , V_121 ) ;
F_70 ( V_12 , V_14 , V_118 ) ;
} else if ( V_120 ) {
F_69 ( V_12 , V_116 , 0 , V_120 ) ;
F_53 ( V_12 , V_116 , V_121 ) ;
F_70 ( V_12 , V_14 , V_118 ) ;
} else {
F_53 ( V_12 , 0 , V_121 ) ;
F_70 ( V_12 , V_14 , V_118 ) ;
}
if ( V_44 >= 0 )
F_32 ( V_12 , 1 , F_23 () , V_44 ) ;
else
F_41 ( V_12 , 1 , F_9 ( 0 ) , 0 ) ;
} else {
if ( V_120 >> 16 ) {
F_44 ( V_12 , V_116 , V_120 >> 16 ) ;
F_69 ( V_12 , V_116 , V_116 , V_120 & 0xffff ) ;
F_70 ( V_12 , V_14 , V_118 ) ;
F_53 ( V_12 , V_116 , V_121 ) ;
} else if ( V_120 ) {
F_69 ( V_12 , V_116 , 0 , V_120 ) ;
F_70 ( V_12 , V_14 , V_118 ) ;
F_53 ( V_12 , V_116 , V_121 ) ;
} else {
F_70 ( V_12 , V_14 , V_118 ) ;
F_53 ( V_12 , 0 , V_121 ) ;
}
}
}
static void F_71 ( T_2 * * V_12 , struct V_17 * * V_18 ,
struct V_13 * * V_14 ,
unsigned int V_116 ,
enum V_65 V_66 ,
int V_119 )
{
F_44 ( V_12 , V_116 , V_122 >> 16 ) ;
F_69 ( V_12 , V_116 , V_116 , V_122 & 0xffff ) ;
F_53 ( V_12 , V_116 , V_121 ) ;
F_60 ( V_12 , V_18 , V_14 , V_66 ) ;
F_68 ( V_12 , V_14 , V_116 , V_123 , V_119 ) ;
}
static void
F_72 ( T_2 * * V_12 , struct V_13 * * V_14 , unsigned int V_116 ,
unsigned int V_124 , int V_118 )
{
F_41 ( V_12 , V_116 , 0 , V_124 ) ;
if ( F_5 () ) {
F_73 ( V_12 , V_14 , V_116 , F_35 ( V_125 ) , V_118 ) ;
} else {
F_51 ( V_12 , V_116 , V_116 , V_125 ) ;
F_74 ( V_12 , V_14 , V_116 , V_118 ) ;
}
}
static void F_75 ( T_2 * * V_12 , unsigned int V_126 ,
unsigned int V_116 )
{
int V_127 ;
V_127 = ( V_128 >> 7 ) < 0x10000 ;
if ( ! V_127 )
F_44 ( V_12 , V_116 , V_128 >> ( 7 + 16 ) ) ;
F_63 ( V_12 , V_126 ) ;
F_27 ( V_12 , V_126 , V_58 ) ;
if ( V_127 )
F_76 ( V_12 , V_126 , V_126 , V_128 >> 7 ) ;
else
F_37 ( V_12 , V_126 , V_126 , V_116 ) ;
F_27 ( V_12 , V_126 , V_129 ) ;
}
static void F_77 ( T_2 * * V_12 , struct V_13 * * V_14 ,
struct V_17 * * V_18 ,
unsigned int V_126 ,
unsigned int V_130 )
{
#ifdef F_78
F_79 ( V_12 , V_126 , 0 , V_130 ) ;
F_80 ( V_12 , V_14 , V_126 , V_131 ) ;
F_41 ( V_12 , V_126 , 0 , V_130 ) ;
#else
F_38 ( V_12 , V_126 , 0 , V_130 ) ;
#endif
F_75 ( V_12 , V_126 , V_130 ) ;
F_71 ( V_12 , V_18 , V_14 , V_126 , V_68 , 0 ) ;
}
static void
F_81 ( T_2 * * V_12 , struct V_17 * * V_18 , struct V_13 * * V_14 ,
unsigned int V_116 , unsigned int V_130 )
{
#ifndef F_29
long V_53 = ( long ) V_54 ;
#endif
F_82 ( V_12 , V_116 , V_56 ) ;
if ( V_132 ) {
F_66 ( V_12 , V_130 , V_116 , V_133 + V_134 + V_135 - 3 ) ;
F_74 ( V_12 , V_14 , V_130 , V_136 ) ;
} else {
F_83 ( V_12 , V_14 , V_116 , V_136 ) ;
}
#ifdef F_29
if ( V_137 != - 1 ) {
F_32 ( V_12 , V_130 , F_23 () , V_137 ) ;
} else {
F_32 ( V_12 , V_130 , V_57 ) ;
F_84 ( V_12 , V_130 , 0 , 0 , 23 ) ;
F_69 ( V_12 , V_130 , V_130 , 0x540 ) ;
F_85 ( V_12 , V_130 , V_130 , 11 ) ;
}
#elif F_86 ( F_78 )
# ifdef F_87
F_43 ( V_12 , V_130 , V_138 ) ;
F_66 ( V_12 , V_130 , V_130 , 19 ) ;
# else
F_82 ( V_12 , V_130 , V_57 ) ;
F_66 ( V_12 , V_130 , V_130 , 23 ) ;
# endif
F_88 ( V_12 , V_116 , V_53 ) ;
F_89 ( V_12 , V_130 , V_130 , V_116 ) ;
F_82 ( V_12 , V_116 , V_56 ) ;
F_90 ( V_12 , V_130 , F_47 ( V_53 ) , V_130 ) ;
#else
F_88 ( V_12 , V_130 , V_53 ) ;
F_90 ( V_12 , V_130 , F_47 ( V_53 ) , V_130 ) ;
#endif
F_91 ( V_18 , * V_12 ) ;
F_66 ( V_12 , V_116 , V_116 , V_133 - 3 ) ;
F_51 ( V_12 , V_116 , V_116 , ( V_139 - 1 ) << 3 ) ;
F_89 ( V_12 , V_130 , V_130 , V_116 ) ;
#ifndef F_92
F_82 ( V_12 , V_116 , V_56 ) ;
F_90 ( V_12 , V_130 , 0 , V_130 ) ;
F_66 ( V_12 , V_116 , V_116 , V_140 - 3 ) ;
F_51 ( V_12 , V_116 , V_116 , ( V_141 - 1 ) << 3 ) ;
F_89 ( V_12 , V_130 , V_130 , V_116 ) ;
#endif
}
static void
F_93 ( T_2 * * V_12 , struct V_17 * * V_18 , struct V_13 * * V_14 ,
unsigned int V_142 , unsigned int V_130 ,
enum V_143 V_144 )
{
long V_145 = ( long ) V_146 ;
int V_147 ;
int V_148 = 0 ;
V_147 = F_94 ( V_145 ) && ! F_47 ( V_145 ) ;
F_95 ( V_18 , * V_12 ) ;
if ( V_144 != V_149 && V_132 ) {
if ( V_147 ) {
F_83 ( V_12 , V_14 , V_142 , V_150 ) ;
F_44 ( V_12 , V_130 , F_45 ( V_145 ) ) ;
V_148 = 1 ;
} else {
F_96 ( V_12 , V_14 , V_142 , V_151 ) ;
}
}
if ( ! V_148 ) {
if ( F_94 ( V_145 ) && ! F_47 ( V_145 ) ) {
F_70 ( V_12 , V_14 , V_150 ) ;
F_44 ( V_12 , V_130 , F_45 ( V_145 ) ) ;
} else {
F_88 ( V_12 , V_130 , V_145 ) ;
F_70 ( V_12 , V_14 , V_150 ) ;
if ( F_94 ( V_145 ) )
F_97 ( V_12 , V_130 , V_130 , F_47 ( V_145 ) ) ;
else
F_98 ( V_12 , V_130 , V_130 , F_47 ( V_145 ) ) ;
}
}
if ( V_144 != V_149 && V_132 ) {
F_99 ( V_18 , * V_12 ) ;
F_36 ( V_12 , V_130 , ( unsigned long ) V_152 ) ;
F_55 ( V_12 , V_130 ) ;
if ( V_144 == V_153 ) {
if ( V_44 >= 0 )
F_32 ( V_12 , 1 , F_23 () , V_44 ) ;
else
F_41 ( V_12 , 1 , F_9 ( 0 ) , 0 ) ;
} else {
F_52 ( V_12 ) ;
}
}
}
static void T_1
F_100 ( T_2 * * V_12 , unsigned int V_116 , unsigned int V_130 )
{
long V_53 = ( long ) V_54 ;
#ifdef F_78
#ifdef F_87
F_43 ( V_12 , V_130 , V_138 ) ;
F_88 ( V_12 , V_116 , V_53 ) ;
F_48 ( V_12 , V_130 , V_130 , 19 ) ;
#else
F_43 ( V_12 , V_130 , V_57 ) ;
F_88 ( V_12 , V_116 , V_53 ) ;
F_48 ( V_12 , V_130 , V_130 , 23 ) ;
#endif
F_50 ( V_12 , V_130 , V_116 , V_130 ) ;
#else
F_88 ( V_12 , V_130 , V_53 ) ;
#endif
F_43 ( V_12 , V_116 , V_56 ) ;
F_46 ( V_12 , V_130 , F_47 ( V_53 ) , V_130 ) ;
F_48 ( V_12 , V_116 , V_116 , V_133 ) ;
F_49 ( V_12 , V_116 , V_116 , V_154 ) ;
F_50 ( V_12 , V_130 , V_130 , V_116 ) ;
}
static void F_101 ( T_2 * * V_12 , unsigned int V_155 )
{
unsigned int V_156 = 4 - ( V_157 + 1 ) + V_135 - 12 ;
unsigned int V_158 = ( V_159 / 2 - 1 ) << ( V_157 + 1 ) ;
switch ( F_6 () ) {
case V_160 :
case V_104 :
case V_105 :
case V_106 :
case V_109 :
case V_107 :
case V_108 :
case V_110 :
V_156 += 2 ;
break;
default:
break;
}
if ( V_156 )
F_67 ( V_12 , V_155 , V_155 , V_156 ) ;
F_51 ( V_12 , V_155 , V_155 , V_158 ) ;
}
static void F_102 ( T_2 * * V_12 , unsigned int V_116 , unsigned int V_130 )
{
switch ( F_6 () ) {
case V_64 :
F_41 ( V_12 , V_130 , 0 , V_130 ) ;
F_103 ( V_12 , V_116 ) ;
break;
default:
F_103 ( V_12 , V_116 ) ;
F_41 ( V_12 , V_130 , 0 , V_130 ) ;
break;
}
F_101 ( V_12 , V_116 ) ;
F_37 ( V_12 , V_130 , V_130 , V_116 ) ;
}
static void F_104 ( T_2 * * V_12 , unsigned int V_116 , unsigned int V_161 )
{
#ifdef F_65
if ( V_162 ) {
F_90 ( V_12 , V_116 , 0 , V_161 ) ;
F_90 ( V_12 , V_161 , sizeof( V_163 ) , V_161 ) ;
if ( V_26 ) {
F_64 ( V_12 , V_116 , V_116 , F_35 ( V_115 ) ) ;
F_27 ( V_12 , V_116 , V_58 ) ;
F_64 ( V_12 , V_161 , V_161 , F_35 ( V_115 ) ) ;
} else {
F_66 ( V_12 , V_116 , V_116 , F_35 ( V_115 ) ) ;
F_27 ( V_12 , V_116 , V_58 ) ;
F_66 ( V_12 , V_161 , V_161 , F_35 ( V_115 ) ) ;
}
F_27 ( V_12 , V_161 , V_129 ) ;
} else {
int V_164 = sizeof( V_163 ) / 2 ;
int V_165 = V_164 + sizeof( V_163 ) ;
F_46 ( V_12 , V_116 , V_164 , V_161 ) ;
F_27 ( V_12 , V_116 , V_58 ) ;
F_46 ( V_12 , V_161 , V_165 , V_161 ) ;
F_27 ( V_12 , V_161 , V_129 ) ;
}
#else
F_41 ( V_12 , V_116 , 0 , V_161 ) ;
F_41 ( V_12 , V_161 , sizeof( V_163 ) , V_161 ) ;
if ( F_1 () )
F_58 ( V_12 ) ;
if ( V_26 ) {
F_64 ( V_12 , V_116 , V_116 , F_35 ( V_115 ) ) ;
if ( F_2 () )
F_27 ( V_12 , 0 , V_58 ) ;
F_27 ( V_12 , V_116 , V_58 ) ;
F_64 ( V_12 , V_161 , V_161 , F_35 ( V_115 ) ) ;
} else {
F_67 ( V_12 , V_116 , V_116 , F_35 ( V_115 ) ) ;
if ( F_2 () )
F_27 ( V_12 , 0 , V_58 ) ;
F_27 ( V_12 , V_116 , V_58 ) ;
F_67 ( V_12 , V_161 , V_161 , F_35 ( V_115 ) ) ;
if ( F_1 () )
F_43 ( V_12 , V_116 , V_166 ) ;
}
if ( F_2 () )
F_27 ( V_12 , 0 , V_129 ) ;
F_27 ( V_12 , V_161 , V_129 ) ;
#endif
}
static struct V_167
F_105 ( T_2 * * V_12 , struct V_17 * * V_18 ,
struct V_13 * * V_14 , unsigned int V_116 ,
unsigned int V_130 , int V_168 )
{
struct V_167 V_169 ;
unsigned int V_170 , V_171 ;
int V_172 = 0 ;
const int V_173 = 1 ;
V_169 . V_174 = V_173 ;
V_169 . V_119 = 0 ;
if ( V_132 ) {
F_32 ( V_12 , V_116 , V_56 ) ;
if ( V_137 != - 1 )
F_32 ( V_12 , V_130 , F_23 () , V_137 ) ;
else
F_32 ( V_12 , V_130 , V_57 ) ;
if ( V_168 >= 0 )
F_27 ( V_12 , V_173 , F_23 () , V_168 ) ;
else
F_38 ( V_12 , V_173 , F_9 ( 0 ) , 0 ) ;
F_66 ( V_12 , V_173 , V_116 ,
V_133 + V_134 + V_135 - 3 ) ;
F_74 ( V_12 , V_14 , V_173 , V_136 ) ;
if ( V_137 == - 1 ) {
V_172 = 1 ;
F_84 ( V_12 , V_130 , 0 , 0 , 23 ) ;
}
} else {
if ( V_137 != - 1 )
F_32 ( V_12 , V_130 , F_23 () , V_137 ) ;
else
F_32 ( V_12 , V_130 , V_57 ) ;
F_32 ( V_12 , V_116 , V_56 ) ;
if ( V_168 >= 0 )
F_27 ( V_12 , V_173 , F_23 () , V_168 ) ;
else
F_38 ( V_12 , V_173 , F_9 ( 0 ) , 0 ) ;
if ( V_137 == - 1 )
F_84 ( V_12 , V_130 , 0 , 0 , 23 ) ;
F_83 ( V_12 , V_14 , V_116 , V_136 ) ;
}
if ( V_137 == - 1 ) {
V_172 = 1 ;
F_69 ( V_12 , V_130 , V_130 , 0x540 ) ;
F_85 ( V_12 , V_130 , V_130 , 11 ) ;
}
#ifdef F_92
#define F_106 scratch
#else
#define F_106 ptr
#endif
if ( ! V_172 )
F_66 ( V_12 , V_173 , V_116 , V_133 - 3 ) ;
F_91 ( V_18 , * V_12 ) ;
if ( V_172 )
F_66 ( V_12 , V_173 , V_116 , V_133 - 3 ) ;
#ifdef F_92
F_103 ( V_12 , V_116 ) ;
#endif
F_51 ( V_12 , V_173 , V_173 , ( V_139 - 1 ) << 3 ) ;
if ( F_7 () ) {
F_107 ( V_12 , F_106 , V_173 , V_130 ) ;
} else {
F_89 ( V_12 , V_130 , V_130 , V_173 ) ;
F_90 ( V_12 , F_106 , 0 , V_130 ) ;
}
#ifndef F_92
F_66 ( V_12 , V_173 , V_116 , V_140 - 3 ) ;
F_51 ( V_12 , V_173 , V_173 , ( V_141 - 1 ) << 3 ) ;
F_103 ( V_12 , V_116 ) ;
if ( F_7 () ) {
F_107 ( V_12 , V_173 , V_173 , V_130 ) ;
} else {
F_89 ( V_12 , V_130 , V_130 , V_173 ) ;
F_41 ( V_12 , V_173 , 0 , V_130 ) ;
}
#endif
F_101 ( V_12 , V_116 ) ;
#ifdef F_19
F_73 ( V_12 , V_14 , V_173 , F_35 ( V_125 ) , V_131 ) ;
if ( F_7 () )
F_52 ( V_12 ) ;
#endif
if ( F_7 () ) {
V_170 = V_130 ;
V_171 = V_116 ;
F_107 ( V_12 , V_170 , V_173 , V_116 ) ;
F_76 ( V_12 , V_116 , V_116 , sizeof( V_163 ) ) ;
F_107 ( V_12 , V_171 , V_173 , V_116 ) ;
} else {
F_37 ( V_12 , V_130 , V_173 , V_116 ) ;
V_170 = V_116 ;
V_171 = V_130 ;
F_41 ( V_12 , V_170 , 0 , V_130 ) ;
F_41 ( V_12 , V_171 , sizeof( V_163 ) , V_130 ) ;
}
if ( V_26 ) {
F_85 ( V_12 , V_170 , V_170 , F_35 ( V_115 ) ) ;
F_27 ( V_12 , V_170 , V_58 ) ;
F_85 ( V_12 , V_171 , V_171 , F_35 ( V_115 ) ) ;
} else {
F_66 ( V_12 , V_170 , V_170 , F_35 ( V_115 ) ) ;
F_27 ( V_12 , V_170 , V_58 ) ;
F_66 ( V_12 , V_171 , V_171 , F_35 ( V_115 ) ) ;
}
F_27 ( V_12 , V_171 , V_129 ) ;
if ( V_168 >= 0 ) {
F_32 ( V_12 , V_173 , F_23 () , V_168 ) ;
F_60 ( V_12 , V_18 , V_14 , V_67 ) ;
F_108 ( V_18 , * V_12 ) ;
V_169 . V_119 = 1 ;
} else if ( V_135 == 14 || V_135 == 13 ) {
F_60 ( V_12 , V_18 , V_14 , V_67 ) ;
F_108 ( V_18 , * V_12 ) ;
F_41 ( V_12 , V_173 , F_9 ( 0 ) , 0 ) ;
} else {
F_41 ( V_12 , V_173 , F_9 ( 0 ) , 0 ) ;
F_60 ( V_12 , V_18 , V_14 , V_67 ) ;
F_108 ( V_18 , * V_12 ) ;
V_169 . V_119 = 1 ;
}
F_109 ( V_12 ) ;
return V_169 ;
}
static void F_110 ( void )
{
T_2 * V_12 = V_55 ;
struct V_17 * V_18 = V_175 ;
struct V_13 * V_14 = V_176 ;
T_2 * V_177 ;
unsigned int V_178 ;
struct V_167 T_4 T_1 ;
enum V_143 T_5 T_1 ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
if ( ( V_44 >= 0 || F_8 () ) && F_5 () ) {
T_4 = F_105 ( & V_12 , & V_18 , & V_14 , V_46 , V_48 ,
V_44 ) ;
T_5 = V_153 ;
} else {
T_4 . V_174 = V_46 ;
T_4 . V_119 = 0 ;
T_5 = V_180 ;
if ( F_3 () ) {
unsigned int V_181 = 44 ;
F_82 ( & V_12 , V_46 , V_56 ) ;
F_82 ( & V_12 , V_48 , V_182 ) ;
F_111 ( & V_12 , V_46 , V_46 , V_48 ) ;
F_66 ( & V_12 , V_48 , V_46 , 62 ) ;
F_66 ( & V_12 , V_46 , V_46 , 12 + 1 ) ;
F_112 ( & V_12 , V_46 , V_46 , 64 + 12 + 1 - V_181 ) ;
F_113 ( & V_12 , V_46 , V_46 , V_48 ) ;
F_74 ( & V_12 , & V_14 , V_46 , V_123 ) ;
}
#ifdef F_31
F_81 ( & V_12 , & V_18 , & V_14 , V_46 , V_48 ) ;
#else
F_100 ( & V_12 , V_46 , V_48 ) ;
#endif
#ifdef F_19
F_72 ( & V_12 , & V_14 , V_46 , V_48 , V_131 ) ;
#endif
F_102 ( & V_12 , V_46 , V_48 ) ;
F_104 ( & V_12 , V_46 , V_48 ) ;
F_60 ( & V_12 , & V_18 , & V_14 , V_67 ) ;
F_108 ( & V_18 , V_12 ) ;
F_109 ( & V_12 ) ;
}
#ifdef F_19
F_114 ( & V_18 , V_12 ) ;
F_75 ( & V_12 , T_4 . V_174 , V_48 ) ;
F_71 ( & V_12 , & V_18 , & V_14 , V_46 , V_67 ,
T_4 . V_119 ) ;
#endif
#ifdef F_31
F_93 ( & V_12 , & V_18 , & V_14 , V_46 , V_48 , T_5 ) ;
#endif
#if F_86 ( F_30 ) || F_86 ( V_183 )
if ( ( V_12 - V_55 ) > 64 )
F_57 ( L_23 ) ;
#else
if ( ( ( V_12 - V_55 ) > ( V_184 * 2 ) - 1 )
|| ( ( ( V_12 - V_55 ) > ( V_184 * 2 ) - 3 )
&& F_115 ( V_176 ,
V_55 + V_184 - 3 ) ) )
F_57 ( L_23 ) ;
#endif
#if F_86 ( F_30 ) || F_86 ( V_183 )
V_177 = V_179 ;
F_116 ( V_176 , V_175 , V_55 , V_12 , V_177 ) ;
V_178 = V_12 - V_55 ;
#else
V_177 = V_179 + V_184 ;
if ( ( V_12 - V_55 ) <= V_184 ) {
F_116 ( V_176 , V_175 , V_55 , V_12 , V_177 ) ;
V_178 = V_12 - V_55 ;
} else {
#ifdef F_19
const enum V_117 V_185 = V_131 ;
#else
const enum V_117 V_185 = V_136 ;
#endif
T_2 * V_186 ;
int V_187 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_117 ( V_175 ) && V_175 [ V_6 ] . V_188 != V_185 ; V_6 ++ )
;
F_118 ( V_6 == F_117 ( V_175 ) ) ;
V_186 = V_175 [ V_6 ] . V_189 ;
if ( V_186 > V_55 + V_184 ||
V_186 < V_12 - V_184 )
V_187 = 1 ;
if ( V_187 ) {
V_186 = V_55 + V_184 - 2 ;
if ( F_115 ( V_176 , V_186 - 1 ) )
V_186 -- ;
}
F_116 ( V_176 , V_175 , V_55 , V_186 , V_177 ) ;
V_177 += V_186 - V_55 ;
if ( V_187 ) {
F_119 ( & V_18 , V_179 ) ;
F_70 ( & V_177 , & V_14 , V_190 ) ;
if ( F_115 ( V_176 , V_186 ) )
F_52 ( & V_177 ) ;
else {
F_116 ( V_176 , V_175 ,
V_186 , V_186 + 1 , V_177 ) ;
F_120 ( V_175 , V_177 , V_177 + 1 , - 1 ) ;
V_177 ++ ;
V_186 ++ ;
}
}
F_116 ( V_176 , V_175 , V_186 , V_12 , V_179 ) ;
V_178 = ( V_177 - ( V_179 + V_184 ) ) +
( V_12 - V_186 ) ;
}
#endif
F_121 ( V_176 , V_175 ) ;
F_18 ( L_24 ,
V_178 ) ;
memcpy ( ( void * ) V_60 , V_179 , 0x100 ) ;
F_22 ( L_27 , ( T_2 * ) V_60 , 64 ) ;
}
static void F_122 ( void )
{
const int V_191 = 4 ;
const int V_192 = 5 ;
T_2 * V_12 = V_193 ;
const int V_194 =
V_195 - V_193 ;
struct V_17 * V_18 = V_175 ;
struct V_13 * V_14 = V_176 ;
memset ( V_193 , 0 , V_194 *
sizeof( V_193 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
V_137 = F_24 () ;
if ( V_137 == - 1 ) {
F_123 ( & V_12 , V_192 , V_191 , 29 ) ;
F_76 ( & V_12 , V_192 , V_192 , 4 ) ;
F_74 ( & V_12 , & V_14 , V_192 , V_196 ) ;
F_52 ( & V_12 ) ;
F_124 ( & V_12 , V_191 , 0 , 29 , 64 - 29 ) ;
F_125 ( & V_18 , V_12 ) ;
F_34 ( & V_12 , V_191 , V_191 , 11 ) ;
F_55 ( & V_12 , 31 ) ;
F_27 ( & V_12 , V_191 , V_57 ) ;
} else {
F_55 ( & V_12 , 31 ) ;
F_27 ( & V_12 , V_191 , F_23 () , V_137 ) ;
}
if ( V_12 >= V_195 )
F_57 ( L_28 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_29 ,
( unsigned int ) ( V_12 - V_193 ) ) ;
F_22 ( L_30 , V_193 ,
V_194 ) ;
}
static void
F_126 ( T_2 * * V_12 , unsigned int V_126 , unsigned int V_130 )
{
#ifdef F_78
# ifdef F_65
if ( V_162 )
F_127 ( V_12 , V_126 , 0 , V_130 ) ;
else
# endif
F_128 ( V_12 , V_126 , 0 , V_130 ) ;
#else
# ifdef F_65
if ( V_162 )
F_90 ( V_12 , V_126 , 0 , V_130 ) ;
else
# endif
F_41 ( V_12 , V_126 , 0 , V_130 ) ;
#endif
}
static void
F_129 ( T_2 * * V_12 , struct V_13 * * V_14 , unsigned int V_126 , unsigned int V_130 ,
unsigned int V_144 )
{
#ifdef F_65
unsigned int V_197 = V_144 & ( V_198 | V_199 ) ;
#endif
F_69 ( V_12 , V_126 , V_126 , V_144 ) ;
#ifdef F_78
# ifdef F_65
if ( V_162 )
F_130 ( V_12 , V_126 , 0 , V_130 ) ;
else
# endif
F_79 ( V_12 , V_126 , 0 , V_130 ) ;
if ( F_4 () )
F_131 ( V_12 , V_14 , V_126 , V_200 ) ;
else
F_80 ( V_12 , V_14 , V_126 , V_200 ) ;
# ifdef F_65
if ( ! V_162 ) {
F_132 ( V_12 , V_126 , sizeof( V_163 ) / 2 , V_130 ) ;
F_69 ( V_12 , V_126 , V_126 , V_197 ) ;
F_133 ( V_12 , V_126 , sizeof( V_163 ) / 2 , V_130 ) ;
F_80 ( V_12 , V_14 , V_126 , V_200 ) ;
F_46 ( V_12 , V_126 , 0 , V_130 ) ;
} else
F_52 ( V_12 ) ;
# else
F_52 ( V_12 ) ;
# endif
#else
# ifdef F_65
if ( V_162 )
F_134 ( V_12 , V_126 , 0 , V_130 ) ;
else
# endif
F_38 ( V_12 , V_126 , 0 , V_130 ) ;
# ifdef F_65
if ( ! V_162 ) {
F_46 ( V_12 , V_126 , sizeof( V_163 ) / 2 , V_130 ) ;
F_69 ( V_12 , V_126 , V_126 , V_197 ) ;
F_135 ( V_12 , V_126 , sizeof( V_163 ) / 2 , V_130 ) ;
F_46 ( V_12 , V_126 , 0 , V_130 ) ;
}
# endif
#endif
}
static void
F_136 ( T_2 * * V_12 , struct V_13 * * V_14 ,
int V_126 , int V_130 , int V_173 , enum V_117 V_118 )
{
int V_201 = V_173 >= 0 ? V_173 : V_126 ;
if ( V_26 ) {
if ( F_5 () ) {
F_137 ( V_12 , V_14 , V_126 , F_35 ( V_202 ) , V_118 ) ;
F_52 ( V_12 ) ;
} else {
F_51 ( V_12 , V_201 , V_126 , V_202 ) ;
F_80 ( V_12 , V_14 , V_201 , V_118 ) ;
if ( V_126 == V_201 )
F_126 ( V_12 , V_126 , V_130 ) ;
}
} else {
F_51 ( V_12 , V_201 , V_126 , V_202 | V_203 ) ;
F_138 ( V_12 , V_201 , V_201 , V_202 | V_203 ) ;
F_74 ( V_12 , V_14 , V_201 , V_118 ) ;
if ( V_126 == V_201 )
F_126 ( V_12 , V_126 , V_130 ) ;
}
}
static void
F_139 ( T_2 * * V_12 , struct V_13 * * V_14 , unsigned int V_126 ,
unsigned int V_130 )
{
unsigned int V_144 = V_198 | V_204 ;
F_129 ( V_12 , V_14 , V_126 , V_130 , V_144 ) ;
}
static void
F_140 ( T_2 * * V_12 , struct V_13 * * V_14 ,
unsigned int V_126 , unsigned int V_130 , int V_173 ,
enum V_117 V_118 )
{
int V_201 = V_173 >= 0 ? V_173 : V_126 ;
F_51 ( V_12 , V_201 , V_126 , V_202 | V_205 ) ;
F_138 ( V_12 , V_201 , V_201 , V_202 | V_205 ) ;
F_74 ( V_12 , V_14 , V_201 , V_118 ) ;
if ( V_126 == V_201 )
F_126 ( V_12 , V_126 , V_130 ) ;
else
F_52 ( V_12 ) ;
}
static void
F_141 ( T_2 * * V_12 , struct V_13 * * V_14 , unsigned int V_126 ,
unsigned int V_130 )
{
unsigned int V_144 = ( V_204 | V_206 | V_198
| V_199 ) ;
F_129 ( V_12 , V_14 , V_126 , V_130 , V_144 ) ;
}
static void
F_142 ( T_2 * * V_12 , struct V_13 * * V_14 ,
unsigned int V_126 , unsigned int V_130 , int V_173 ,
enum V_117 V_118 )
{
if ( F_5 () ) {
F_137 ( V_12 , V_14 , V_126 , F_35 ( V_205 ) , V_118 ) ;
F_52 ( V_12 ) ;
} else {
int V_201 = V_173 >= 0 ? V_173 : V_126 ;
F_51 ( V_12 , V_201 , V_126 , V_205 ) ;
F_80 ( V_12 , V_14 , V_201 , V_118 ) ;
if ( V_126 == V_201 )
F_126 ( V_12 , V_126 , V_130 ) ;
}
}
static void
F_143 ( T_2 * * V_12 , unsigned int V_126 , unsigned int V_116 )
{
F_53 ( V_12 , V_126 , V_58 ) ;
F_43 ( V_12 , V_116 , V_59 ) ;
V_69 ( V_12 ) ;
F_55 ( V_12 , V_116 ) ;
F_56 ( V_12 ) ;
}
static void
F_144 ( T_2 * * V_12 , struct V_17 * * V_18 ,
struct V_13 * * V_14 , unsigned int V_126 ,
unsigned int V_116 )
{
F_43 ( V_12 , V_116 , V_166 ) ;
F_53 ( V_12 , V_126 , V_58 ) ;
F_83 ( V_12 , V_14 , V_116 , V_207 ) ;
F_43 ( V_12 , V_116 , V_59 ) ;
V_69 ( V_12 ) ;
F_55 ( V_12 , V_116 ) ;
F_56 ( V_12 ) ;
F_145 ( V_18 , * V_12 ) ;
F_54 ( V_12 ) ;
F_55 ( V_12 , V_116 ) ;
F_56 ( V_12 ) ;
}
static void
F_146 ( T_2 * * V_12 , unsigned int V_126 ,
unsigned int V_130 )
{
long V_53 = ( long ) V_54 ;
F_43 ( V_12 , V_126 , V_56 ) ;
F_44 ( V_12 , V_130 , F_45 ( V_53 ) ) ;
F_46 ( V_12 , V_130 , F_47 ( V_53 ) , V_130 ) ;
F_48 ( V_12 , V_126 , V_126 , 22 ) ;
F_49 ( V_12 , V_126 , V_126 , 2 ) ;
F_50 ( V_12 , V_130 , V_130 , V_126 ) ;
F_43 ( V_12 , V_126 , V_57 ) ;
F_46 ( V_12 , V_130 , 0 , V_130 ) ;
F_51 ( V_12 , V_126 , V_126 , 0xffc ) ;
F_50 ( V_12 , V_130 , V_130 , V_126 ) ;
F_46 ( V_12 , V_126 , 0 , V_130 ) ;
F_59 ( V_12 ) ;
}
static void F_147 ( void )
{
T_2 * V_12 = V_208 ;
const int V_209 = V_210 - V_208 ;
struct V_17 * V_18 = V_175 ;
struct V_13 * V_14 = V_176 ;
memset ( V_208 , 0 , V_209 * sizeof( V_208 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
F_146 ( & V_12 , V_46 , V_48 ) ;
F_136 ( & V_12 , & V_14 , V_46 , V_48 , - 1 , V_211 ) ;
F_52 ( & V_12 ) ;
F_139 ( & V_12 , & V_14 , V_46 , V_48 ) ;
F_144 ( & V_12 , & V_18 , & V_14 , V_46 , V_48 ) ;
F_148 ( & V_18 , V_12 ) ;
F_149 ( & V_12 , ( unsigned long ) V_152 & 0x0fffffff ) ;
F_52 ( & V_12 ) ;
if ( V_12 >= V_210 )
F_57 ( L_31 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_32 ,
( unsigned int ) ( V_12 - V_208 ) ) ;
F_22 ( L_33 , V_208 , V_209 ) ;
}
static void F_150 ( void )
{
T_2 * V_12 = V_212 ;
const int V_213 = V_214 - V_212 ;
struct V_17 * V_18 = V_175 ;
struct V_13 * V_14 = V_176 ;
memset ( V_212 , 0 , V_213 * sizeof( V_212 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
F_146 ( & V_12 , V_46 , V_48 ) ;
F_140 ( & V_12 , & V_14 , V_46 , V_48 , - 1 , V_215 ) ;
F_52 ( & V_12 ) ;
F_141 ( & V_12 , & V_14 , V_46 , V_48 ) ;
F_144 ( & V_12 , & V_18 , & V_14 , V_46 , V_48 ) ;
F_151 ( & V_18 , V_12 ) ;
F_149 ( & V_12 , ( unsigned long ) V_216 & 0x0fffffff ) ;
F_52 ( & V_12 ) ;
if ( V_12 >= V_214 )
F_57 ( L_34 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_35 ,
( unsigned int ) ( V_12 - V_212 ) ) ;
F_22 ( L_36 , V_212 , V_213 ) ;
}
static void F_152 ( void )
{
T_2 * V_12 = V_217 ;
const int V_218 = V_219 - V_217 ;
struct V_17 * V_18 = V_175 ;
struct V_13 * V_14 = V_176 ;
memset ( V_217 , 0 , V_218 * sizeof( V_217 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
F_146 ( & V_12 , V_46 , V_48 ) ;
F_142 ( & V_12 , & V_14 , V_46 , V_48 , - 1 , V_220 ) ;
F_52 ( & V_12 ) ;
F_141 ( & V_12 , & V_14 , V_46 , V_48 ) ;
F_143 ( & V_12 , V_46 , V_48 ) ;
F_153 ( & V_18 , V_12 ) ;
F_149 ( & V_12 , ( unsigned long ) V_216 & 0x0fffffff ) ;
F_52 ( & V_12 ) ;
if ( V_12 >= V_219 )
F_57 ( L_37 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_38 ,
( unsigned int ) ( V_12 - V_217 ) ) ;
F_22 ( L_39 , V_217 , V_218 ) ;
}
static struct V_40
F_154 ( T_2 * * V_12 , struct V_17 * * V_18 ,
struct V_13 * * V_14 )
{
struct V_40 V_221 = F_26 ( V_12 ) ;
#ifdef F_31
F_81 ( V_12 , V_18 , V_14 , V_221 . V_45 , V_221 . V_47 ) ;
#else
F_100 ( V_12 , V_221 . V_45 , V_221 . V_47 ) ;
#endif
#ifdef F_19
F_72 ( V_12 , V_14 , V_221 . V_45 , V_221 . V_47 , V_131 ) ;
#endif
F_32 ( V_12 , V_221 . V_45 , V_56 ) ;
F_41 ( V_12 , V_221 . V_47 , 0 , V_221 . V_47 ) ;
F_67 ( V_12 , V_221 . V_45 , V_221 . V_45 , V_135 + V_222 - V_157 ) ;
F_51 ( V_12 , V_221 . V_45 , V_221 . V_45 , ( V_159 - 1 ) << V_157 ) ;
F_37 ( V_12 , V_221 . V_47 , V_221 . V_47 , V_221 . V_45 ) ;
#ifdef F_78
F_155 ( V_18 , * V_12 ) ;
#endif
F_126 ( V_12 , V_221 . V_45 , V_221 . V_47 ) ;
if ( ! F_11 () )
F_58 ( V_12 ) ;
return V_221 ;
}
static void
F_156 ( T_2 * * V_12 , struct V_17 * * V_18 ,
struct V_13 * * V_14 , unsigned int V_116 ,
unsigned int V_130 )
{
F_69 ( V_12 , V_130 , V_130 , sizeof( V_163 ) ) ;
F_138 ( V_12 , V_130 , V_130 , sizeof( V_163 ) ) ;
F_104 ( V_12 , V_116 , V_130 ) ;
F_60 ( V_12 , V_18 , V_14 , V_68 ) ;
F_108 ( V_18 , * V_12 ) ;
F_40 ( V_12 ) ;
F_109 ( V_12 ) ;
#ifdef F_31
F_93 ( V_12 , V_18 , V_14 , V_116 , V_130 , V_149 ) ;
#endif
}
static void F_157 ( void )
{
T_2 * V_12 = V_208 ;
const int V_209 = V_210 - V_208 ;
struct V_17 * V_18 = V_175 ;
struct V_13 * V_14 = V_176 ;
struct V_40 V_221 ;
memset ( V_208 , 0 , V_209 * sizeof( V_208 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
if ( F_3 () ) {
unsigned int V_181 = 44 ;
F_82 ( & V_12 , V_46 , V_56 ) ;
F_82 ( & V_12 , V_48 , V_182 ) ;
F_111 ( & V_12 , V_46 , V_46 , V_48 ) ;
F_66 ( & V_12 , V_48 , V_46 , 62 ) ;
F_66 ( & V_12 , V_46 , V_46 , 12 + 1 ) ;
F_112 ( & V_12 , V_46 , V_46 , 64 + 12 + 1 - V_181 ) ;
F_113 ( & V_12 , V_46 , V_46 , V_48 ) ;
F_74 ( & V_12 , & V_14 , V_46 , V_123 ) ;
}
V_221 = F_154 ( & V_12 , & V_18 , & V_14 ) ;
F_136 ( & V_12 , & V_14 , V_221 . V_45 , V_221 . V_47 , V_221 . V_49 , V_211 ) ;
if ( F_11 () )
F_58 ( & V_12 ) ;
if ( V_26 ) {
if ( F_5 () ) {
F_137 ( & V_12 , & V_14 , V_221 . V_45 , F_35 ( V_198 ) ,
V_196 ) ;
} else {
F_51 ( & V_12 , V_221 . V_49 , V_221 . V_45 , V_198 ) ;
F_80 ( & V_12 , & V_14 , V_221 . V_49 , V_196 ) ;
}
F_52 ( & V_12 ) ;
F_158 ( & V_12 ) ;
switch ( F_6 () ) {
default:
if ( V_70 ) {
F_62 ( & V_12 ) ;
case V_3 :
case V_4 :
case V_5 :
break;
}
}
if ( F_5 () ) {
F_159 ( & V_12 , V_221 . V_47 , F_35 ( sizeof( V_163 ) ) , 8 ) ;
} else {
F_51 ( & V_12 , V_221 . V_49 , V_221 . V_47 , sizeof( V_163 ) ) ;
F_160 ( & V_12 , V_221 . V_49 , 8 ) ;
}
F_32 ( & V_12 , V_221 . V_49 , V_58 ) ;
F_32 ( & V_12 , V_221 . V_49 , V_129 ) ;
if ( F_5 () ) {
F_73 ( & V_12 , & V_14 , V_221 . V_49 , 1 , V_211 ) ;
F_52 ( & V_12 ) ;
F_125 ( & V_18 , V_12 ) ;
} else {
F_51 ( & V_12 , V_221 . V_49 , V_221 . V_49 , 2 ) ;
F_74 ( & V_12 , & V_14 , V_221 . V_49 , V_211 ) ;
F_52 ( & V_12 ) ;
}
F_125 ( & V_18 , V_12 ) ;
}
F_139 ( & V_12 , & V_14 , V_221 . V_45 , V_221 . V_47 ) ;
F_156 ( & V_12 , & V_18 , & V_14 , V_221 . V_45 , V_221 . V_47 ) ;
#ifdef F_19
F_114 ( & V_18 , V_12 ) ;
F_126 ( & V_12 , V_221 . V_45 , V_221 . V_47 ) ;
F_136 ( & V_12 , & V_14 , V_221 . V_45 , V_221 . V_47 , V_221 . V_49 , V_211 ) ;
F_58 ( & V_12 ) ;
if ( V_26 ) {
if ( F_5 () ) {
F_137 ( & V_12 , & V_14 , V_221 . V_45 , F_35 ( V_198 ) ,
V_223 ) ;
} else {
F_51 ( & V_12 , V_221 . V_49 , V_221 . V_45 , V_198 ) ;
F_80 ( & V_12 , & V_14 , V_221 . V_49 , V_223 ) ;
}
F_52 ( & V_12 ) ;
F_158 ( & V_12 ) ;
switch ( F_6 () ) {
default:
if ( V_70 ) {
F_62 ( & V_12 ) ;
case V_3 :
case V_4 :
case V_5 :
break;
}
}
if ( F_5 () ) {
F_159 ( & V_12 , V_221 . V_47 , F_35 ( sizeof( V_163 ) ) , 8 ) ;
} else {
F_51 ( & V_12 , V_221 . V_49 , V_221 . V_47 , sizeof( V_163 ) ) ;
F_160 ( & V_12 , V_221 . V_49 , 8 ) ;
}
F_32 ( & V_12 , V_221 . V_49 , V_58 ) ;
F_32 ( & V_12 , V_221 . V_49 , V_129 ) ;
if ( F_5 () ) {
F_137 ( & V_12 , & V_14 , V_221 . V_49 , 1 , V_223 ) ;
} else {
F_51 ( & V_12 , V_221 . V_49 , V_221 . V_49 , 2 ) ;
F_80 ( & V_12 , & V_14 , V_221 . V_49 , V_223 ) ;
}
if ( V_120 == 0 )
F_52 ( & V_12 ) ;
F_68 ( & V_12 , & V_14 , V_221 . V_49 , V_211 , 0 ) ;
F_161 ( & V_18 , V_12 ) ;
}
F_69 ( & V_12 , V_221 . V_45 , V_221 . V_45 , ( V_204 | V_198 ) ) ;
F_77 ( & V_12 , & V_14 , & V_18 , V_221 . V_45 , V_221 . V_47 ) ;
#endif
F_148 ( & V_18 , V_12 ) ;
F_40 ( & V_12 ) ;
#ifdef F_162
if ( ( unsigned long ) V_152 & 1 ) {
F_44 ( & V_12 , V_46 , F_45 ( ( long ) V_152 ) ) ;
F_97 ( & V_12 , V_46 , V_46 , F_47 ( ( long ) V_152 ) ) ;
F_55 ( & V_12 , V_46 ) ;
} else
#endif
F_149 ( & V_12 , ( unsigned long ) V_152 & 0x0fffffff ) ;
F_52 ( & V_12 ) ;
if ( V_12 >= V_210 )
F_57 ( L_31 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_32 ,
( unsigned int ) ( V_12 - V_208 ) ) ;
F_22 ( L_40 , V_208 , V_209 ) ;
}
static void F_163 ( void )
{
T_2 * V_12 = V_212 ;
const int V_213 = V_214 - V_212 ;
struct V_17 * V_18 = V_175 ;
struct V_13 * V_14 = V_176 ;
struct V_40 V_221 ;
memset ( V_212 , 0 , V_213 * sizeof( V_212 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
V_221 = F_154 ( & V_12 , & V_18 , & V_14 ) ;
F_140 ( & V_12 , & V_14 , V_221 . V_45 , V_221 . V_47 , V_221 . V_49 , V_215 ) ;
if ( F_11 () )
F_58 ( & V_12 ) ;
F_141 ( & V_12 , & V_14 , V_221 . V_45 , V_221 . V_47 ) ;
F_156 ( & V_12 , & V_18 , & V_14 , V_221 . V_45 , V_221 . V_47 ) ;
#ifdef F_19
F_114 ( & V_18 , V_12 ) ;
F_126 ( & V_12 , V_221 . V_45 , V_221 . V_47 ) ;
F_140 ( & V_12 , & V_14 , V_221 . V_45 , V_221 . V_47 , V_221 . V_49 , V_215 ) ;
F_58 ( & V_12 ) ;
F_69 ( & V_12 , V_221 . V_45 , V_221 . V_45 ,
V_204 | V_206 | V_198 | V_199 ) ;
F_77 ( & V_12 , & V_14 , & V_18 , V_221 . V_45 , V_221 . V_47 ) ;
#endif
F_151 ( & V_18 , V_12 ) ;
F_40 ( & V_12 ) ;
#ifdef F_162
if ( ( unsigned long ) V_216 & 1 ) {
F_44 ( & V_12 , V_46 , F_45 ( ( long ) V_216 ) ) ;
F_97 ( & V_12 , V_46 , V_46 , F_47 ( ( long ) V_216 ) ) ;
F_55 ( & V_12 , V_46 ) ;
} else
#endif
F_149 ( & V_12 , ( unsigned long ) V_216 & 0x0fffffff ) ;
F_52 ( & V_12 ) ;
if ( V_12 >= V_214 )
F_57 ( L_34 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_35 ,
( unsigned int ) ( V_12 - V_212 ) ) ;
F_22 ( L_41 , V_212 , V_213 ) ;
}
static void F_164 ( void )
{
T_2 * V_12 = V_217 ;
const int V_218 = V_219 - V_217 ;
struct V_17 * V_18 = V_175 ;
struct V_13 * V_14 = V_176 ;
struct V_40 V_221 ;
memset ( V_217 , 0 , V_218 * sizeof( V_217 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
V_221 = F_154 ( & V_12 , & V_18 , & V_14 ) ;
F_142 ( & V_12 , & V_14 , V_221 . V_45 , V_221 . V_47 , V_221 . V_49 , V_220 ) ;
if ( F_11 () )
F_58 ( & V_12 ) ;
F_141 ( & V_12 , & V_14 , V_221 . V_45 , V_221 . V_47 ) ;
F_156 ( & V_12 , & V_18 , & V_14 , V_221 . V_45 , V_221 . V_47 ) ;
#ifdef F_19
F_114 ( & V_18 , V_12 ) ;
F_126 ( & V_12 , V_221 . V_45 , V_221 . V_47 ) ;
F_142 ( & V_12 , & V_14 , V_221 . V_45 , V_221 . V_47 , V_221 . V_49 , V_220 ) ;
F_58 ( & V_12 ) ;
F_69 ( & V_12 , V_221 . V_45 , V_221 . V_45 ,
V_204 | V_206 | V_198 | V_199 ) ;
F_77 ( & V_12 , & V_14 , & V_18 , V_221 . V_45 , V_221 . V_47 ) ;
#endif
F_153 ( & V_18 , V_12 ) ;
F_40 ( & V_12 ) ;
#ifdef F_162
if ( ( unsigned long ) V_216 & 1 ) {
F_44 ( & V_12 , V_46 , F_45 ( ( long ) V_216 ) ) ;
F_97 ( & V_12 , V_46 , V_46 , F_47 ( ( long ) V_216 ) ) ;
F_55 ( & V_12 , V_46 ) ;
} else
#endif
F_149 ( & V_12 , ( unsigned long ) V_216 & 0x0fffffff ) ;
F_52 ( & V_12 ) ;
if ( V_12 >= V_219 )
F_57 ( L_37 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_38 ,
( unsigned int ) ( V_12 - V_217 ) ) ;
F_22 ( L_42 , V_217 , V_218 ) ;
}
static void F_165 ( void )
{
F_166 ( ( unsigned long ) V_208 ,
( unsigned long ) V_210 ) ;
F_166 ( ( unsigned long ) V_212 ,
( unsigned long ) V_214 ) ;
F_166 ( ( unsigned long ) V_217 ,
( unsigned long ) V_219 ) ;
#ifdef F_29
F_166 ( ( unsigned long ) V_193 ,
( unsigned long ) V_195 ) ;
#endif
}
void F_167 ( void )
{
static int V_224 = 0 ;
F_16 () ;
#ifdef F_31
V_132 = V_8 . V_225 > ( V_133 + V_134 + V_135 - 3 ) ;
#endif
switch ( F_6 () ) {
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
#ifndef F_29
if ( V_233 )
F_42 () ;
if ( ! V_224 ) {
if ( ! V_233 )
F_42 () ;
F_147 () ;
F_150 () ;
F_152 () ;
F_165 () ;
V_224 ++ ;
}
#else
F_57 ( L_43 ) ;
#endif
break;
case V_234 :
case V_235 :
F_57 ( L_44 ) ;
break;
case V_236 :
F_57 ( L_45 ) ;
break;
default:
if ( ! V_224 ) {
V_44 = F_24 () ;
#ifdef F_29
F_122 () ;
#endif
F_157 () ;
F_163 () ;
F_164 () ;
if ( ! V_233 )
F_110 () ;
F_165 () ;
V_224 ++ ;
}
if ( V_233 )
F_110 () ;
}
}
