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
case V_6 :
return 1 ;
default:
return 0 ;
}
}
static int F_7 ( void )
{
switch ( F_6 () ) {
case V_5 :
case V_6 :
return 1 ;
default:
return 0 ;
}
}
static bool F_8 ( void )
{
return true ;
}
static int F_9 ( int V_7 )
{
V_7 += 1 ;
return V_8 * 128 - ( 8 * V_7 ) - 32768 ;
}
static bool F_8 ( void )
{
return false ;
}
static int F_9 ( int V_7 )
{
F_10 () ;
return 0 ;
}
static int F_11 ( void )
{
return ( V_9 . V_10 & 0xffff00 ) ==
( V_11 | V_12 ) ;
}
static void F_12 ( T_2 * * V_13 , struct V_14 * * V_15 , int V_16 )
{
switch ( V_16 ) {
case 0 ... 7 :
F_13 ( V_13 , V_15 , 0 , V_17 + V_16 ) ;
return;
default:
F_10 () ;
}
}
static void F_14 ( struct V_18 * * V_19 , T_2 * * V_13 , int V_16 )
{
switch ( V_16 ) {
case 0 ... 7 :
F_15 ( V_19 , * V_13 , V_17 + V_16 ) ;
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
F_17 ( L_4 , V_20 ) ;
F_17 ( L_5 , V_21 ) ;
F_17 ( L_6 , V_22 ) ;
F_17 ( L_7 , V_23 ) ;
F_17 ( L_8 , V_24 ) ;
#ifdef F_19
F_17 ( L_9 , V_25 ) ;
F_17 ( L_10 , V_26 ) ;
#endif
if ( V_27 ) {
#ifdef F_20
F_17 ( L_11 , F_20 ) ;
#endif
#ifdef F_21
F_17 ( L_12 , F_21 ) ;
#endif
}
F_17 ( L_13 , V_28 ) ;
F_17 ( L_14 , V_29 ) ;
F_17 ( L_15 , V_30 ) ;
F_17 ( L_16 , V_31 ) ;
F_18 ( L_3 ) ;
}
static inline void F_22 ( const char * V_32 , const T_2 * V_33 , int V_34 )
{
int V_7 ;
F_18 ( L_17 , V_32 ) ;
F_18 ( L_18 ) ;
F_18 ( L_19 ) ;
for ( V_7 = 0 ; V_7 < V_34 ; V_7 ++ )
F_18 ( L_20 , V_33 [ V_7 ] , & V_33 [ V_7 ] ) ;
F_18 ( L_21 ) ;
F_18 ( L_22 , V_32 ) ;
}
static inline int T_1 F_23 ( void )
{
switch ( F_6 () ) {
case V_35 :
case V_36 :
return 22 ;
default:
return 31 ;
}
}
static int F_24 ( void )
{
int V_15 ;
unsigned int V_37 = V_38 [ 0 ] . V_39 & ~ V_40 ;
V_15 = F_25 ( V_37 ) ;
if ( V_15 == 0 )
return - 1 ;
V_15 -- ;
V_40 |= ( 1 << V_15 ) ;
return V_15 ;
}
static struct V_41 F_26 ( T_2 * * V_13 )
{
struct V_41 V_15 ;
int V_42 ;
int V_43 ;
int V_44 ;
if ( V_45 >= 0 ) {
F_27 ( V_13 , 1 , F_23 () , V_45 ) ;
V_15 . V_46 = V_47 ;
V_15 . V_48 = V_49 ;
V_15 . V_50 = 1 ;
return V_15 ;
}
if ( F_28 () > 1 ) {
#ifdef F_29
V_44 = 51 ;
V_42 = 20 ;
V_43 = 0 ;
#else
# ifdef F_30
V_44 = 25 ;
V_42 = 4 ;
V_43 = 0 ;
# endif
# ifdef F_31
V_44 = 26 ;
V_42 = 4 ;
V_43 = 0 ;
# endif
#endif
F_32 ( V_13 , V_47 , V_42 , V_43 ) ;
F_33 ( V_13 , V_47 , V_47 , V_44 ) ;
F_34 ( V_13 , V_47 , V_47 , F_35 ( sizeof( struct V_51 ) ) ) ;
F_36 ( V_13 , V_49 , ( long ) & V_52 ) ;
F_37 ( V_13 , V_47 , V_47 , V_49 ) ;
} else {
F_36 ( V_13 , V_47 , ( long ) & V_52 ) ;
}
F_38 ( V_13 , 1 , F_39 ( struct V_51 , V_37 ) , V_47 ) ;
F_38 ( V_13 , 2 , F_39 ( struct V_51 , V_53 ) , V_47 ) ;
V_15 . V_46 = V_49 ;
V_15 . V_48 = 1 ;
V_15 . V_50 = 2 ;
return V_15 ;
}
static void F_40 ( T_2 * * V_13 )
{
if ( V_45 >= 0 ) {
F_32 ( V_13 , 1 , F_23 () , V_45 ) ;
return;
}
F_41 ( V_13 , 1 , F_39 ( struct V_51 , V_37 ) , V_47 ) ;
F_41 ( V_13 , 2 , F_39 ( struct V_51 , V_53 ) , V_47 ) ;
}
static void F_42 ( void )
{
long V_54 = ( long ) V_55 ;
T_2 * V_13 ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
V_13 = V_56 ;
F_43 ( & V_13 , V_47 , V_57 ) ;
F_44 ( & V_13 , V_49 , F_45 ( V_54 ) ) ;
F_46 ( & V_13 , V_49 , F_47 ( V_54 ) , V_49 ) ;
F_48 ( & V_13 , V_47 , V_47 , 22 ) ;
F_49 ( & V_13 , V_47 , V_47 , 2 ) ;
F_50 ( & V_13 , V_49 , V_49 , V_47 ) ;
F_43 ( & V_13 , V_47 , V_58 ) ;
F_46 ( & V_13 , V_49 , 0 , V_49 ) ;
F_51 ( & V_13 , V_47 , V_47 , 0xffc ) ;
F_50 ( & V_13 , V_49 , V_49 , V_47 ) ;
F_46 ( & V_13 , V_47 , 0 , V_49 ) ;
F_52 ( & V_13 ) ;
F_53 ( & V_13 , V_47 , V_59 ) ;
F_43 ( & V_13 , V_49 , V_60 ) ;
F_54 ( & V_13 ) ;
F_55 ( & V_13 , V_49 ) ;
F_56 ( & V_13 ) ;
if ( V_13 > V_56 + 32 )
F_57 ( L_23 ) ;
F_18 ( L_24 ,
( unsigned int ) ( V_13 - V_56 ) ) ;
memcpy ( ( void * ) V_61 , V_56 , 0x80 ) ;
F_22 ( L_25 , ( T_2 * ) V_61 , 32 ) ;
}
static void T_1 F_58 ( T_2 * * V_13 )
{
switch ( F_6 () ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
F_52 ( V_13 ) ;
F_59 ( V_13 ) ;
break;
default:
F_59 ( V_13 ) ;
break;
}
}
static void F_60 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 ,
enum V_66 V_67 )
{
void (* F_61)( T_2 * * ) = NULL ;
switch ( V_67 ) {
case V_68 : F_61 = F_54 ; break;
case V_69 : F_61 = V_70 ; break;
}
if ( V_71 ) {
switch ( F_6 () ) {
case V_72 :
case V_73 :
break;
default:
F_62 ( V_13 ) ;
break;
}
F_61 ( V_13 ) ;
return;
}
switch ( F_6 () ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
F_12 ( V_13 , V_15 , V_80 ) ;
F_61 ( V_13 ) ;
F_14 ( V_19 , V_13 , V_80 ) ;
V_80 ++ ;
F_52 ( V_13 ) ;
break;
case V_62 :
case V_63 :
F_52 ( V_13 ) ;
F_61 ( V_13 ) ;
F_52 ( V_13 ) ;
break;
case V_64 :
case V_65 :
F_52 ( V_13 ) ;
F_52 ( V_13 ) ;
F_61 ( V_13 ) ;
break;
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_36 :
F_52 ( V_13 ) ;
F_61 ( V_13 ) ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_72 :
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
case V_102 :
if ( F_11 () )
F_52 ( V_13 ) ;
case V_103 :
F_61 ( V_13 ) ;
break;
case V_104 :
F_52 ( V_13 ) ;
F_52 ( V_13 ) ;
F_52 ( V_13 ) ;
F_52 ( V_13 ) ;
F_61 ( V_13 ) ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
F_52 ( V_13 ) ;
F_52 ( V_13 ) ;
F_61 ( V_13 ) ;
F_52 ( V_13 ) ;
F_52 ( V_13 ) ;
break;
case V_110 :
case V_111 :
case V_112 :
F_52 ( V_13 ) ;
F_52 ( V_13 ) ;
F_61 ( V_13 ) ;
break;
case V_113 :
F_61 ( V_13 ) ;
F_52 ( V_13 ) ;
break;
default:
F_57 ( L_26 ,
V_9 . V_114 ) ;
break;
}
}
static T_1 void F_63 ( T_2 * * V_13 ,
unsigned int V_115 )
{
if ( V_27 ) {
F_64 ( V_13 , V_115 , V_115 , F_35 ( V_116 ) ) ;
} else {
#ifdef F_65
F_66 ( V_13 , V_115 , V_115 , F_35 ( V_116 ) ) ;
#else
F_67 ( V_13 , V_115 , V_115 , F_35 ( V_116 ) ) ;
#endif
}
}
static void F_68 ( T_2 * * V_13 , struct V_14 * * V_15 ,
unsigned int V_117 , enum V_118 V_119 ,
int V_120 )
{
if ( V_120 ) {
if ( V_121 >> 16 ) {
F_44 ( V_13 , V_117 , V_121 >> 16 ) ;
F_69 ( V_13 , V_117 , V_117 , V_121 & 0xffff ) ;
F_53 ( V_13 , V_117 , V_122 ) ;
F_70 ( V_13 , V_15 , V_119 ) ;
} else if ( V_121 ) {
F_69 ( V_13 , V_117 , 0 , V_121 ) ;
F_53 ( V_13 , V_117 , V_122 ) ;
F_70 ( V_13 , V_15 , V_119 ) ;
} else {
F_53 ( V_13 , 0 , V_122 ) ;
F_70 ( V_13 , V_15 , V_119 ) ;
}
if ( V_45 >= 0 )
F_32 ( V_13 , 1 , F_23 () , V_45 ) ;
else
F_41 ( V_13 , 1 , F_9 ( 0 ) , 0 ) ;
} else {
if ( V_121 >> 16 ) {
F_44 ( V_13 , V_117 , V_121 >> 16 ) ;
F_69 ( V_13 , V_117 , V_117 , V_121 & 0xffff ) ;
F_70 ( V_13 , V_15 , V_119 ) ;
F_53 ( V_13 , V_117 , V_122 ) ;
} else if ( V_121 ) {
F_69 ( V_13 , V_117 , 0 , V_121 ) ;
F_70 ( V_13 , V_15 , V_119 ) ;
F_53 ( V_13 , V_117 , V_122 ) ;
} else {
F_70 ( V_13 , V_15 , V_119 ) ;
F_53 ( V_13 , 0 , V_122 ) ;
}
}
}
static void F_71 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 ,
unsigned int V_117 ,
enum V_66 V_67 ,
int V_120 )
{
F_44 ( V_13 , V_117 , V_123 >> 16 ) ;
F_69 ( V_13 , V_117 , V_117 , V_123 & 0xffff ) ;
F_53 ( V_13 , V_117 , V_122 ) ;
F_60 ( V_13 , V_19 , V_15 , V_67 ) ;
F_68 ( V_13 , V_15 , V_117 , V_124 , V_120 ) ;
}
static void
F_72 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_117 ,
unsigned int V_125 , int V_119 )
{
F_41 ( V_13 , V_117 , 0 , V_125 ) ;
if ( F_5 () ) {
F_73 ( V_13 , V_15 , V_117 , F_35 ( V_126 ) , V_119 ) ;
} else {
F_51 ( V_13 , V_117 , V_117 , V_126 ) ;
F_74 ( V_13 , V_15 , V_117 , V_119 ) ;
}
}
static void F_75 ( T_2 * * V_13 , unsigned int V_127 ,
unsigned int V_117 )
{
int V_128 ;
V_128 = ( V_129 >> 7 ) < 0x10000 ;
if ( ! V_128 )
F_44 ( V_13 , V_117 , V_129 >> ( 7 + 16 ) ) ;
F_63 ( V_13 , V_127 ) ;
F_27 ( V_13 , V_127 , V_59 ) ;
if ( V_128 )
F_76 ( V_13 , V_127 , V_127 , V_129 >> 7 ) ;
else
F_37 ( V_13 , V_127 , V_127 , V_117 ) ;
F_27 ( V_13 , V_127 , V_130 ) ;
}
static void F_77 ( T_2 * * V_13 , struct V_14 * * V_15 ,
struct V_18 * * V_19 ,
unsigned int V_127 ,
unsigned int V_131 )
{
#ifdef F_78
F_79 ( V_13 , V_127 , 0 , V_131 ) ;
F_80 ( V_13 , V_15 , V_127 , V_132 ) ;
F_41 ( V_13 , V_127 , 0 , V_131 ) ;
#else
F_38 ( V_13 , V_127 , 0 , V_131 ) ;
#endif
F_75 ( V_13 , V_127 , V_131 ) ;
F_71 ( V_13 , V_19 , V_15 , V_127 , V_69 , 0 ) ;
}
static void
F_81 ( T_2 * * V_13 , struct V_18 * * V_19 , struct V_14 * * V_15 ,
unsigned int V_117 , unsigned int V_131 )
{
#ifndef F_29
long V_54 = ( long ) V_55 ;
#endif
F_82 ( V_13 , V_117 , V_57 ) ;
if ( V_133 ) {
F_66 ( V_13 , V_131 , V_117 , V_134 + V_135 + V_136 - 3 ) ;
F_74 ( V_13 , V_15 , V_131 , V_137 ) ;
} else {
F_83 ( V_13 , V_15 , V_117 , V_137 ) ;
}
#ifdef F_29
if ( V_138 != - 1 ) {
F_32 ( V_13 , V_131 , F_23 () , V_138 ) ;
} else {
F_32 ( V_13 , V_131 , V_58 ) ;
F_84 ( V_13 , V_131 , 0 , 0 , 23 ) ;
F_69 ( V_13 , V_131 , V_131 , 0x540 ) ;
F_85 ( V_13 , V_131 , V_131 , 11 ) ;
}
#elif F_86 ( F_78 )
# ifdef F_87
F_43 ( V_13 , V_131 , V_139 ) ;
F_66 ( V_13 , V_131 , V_131 , 19 ) ;
# else
F_82 ( V_13 , V_131 , V_58 ) ;
F_66 ( V_13 , V_131 , V_131 , 23 ) ;
# endif
F_88 ( V_13 , V_117 , V_54 ) ;
F_89 ( V_13 , V_131 , V_131 , V_117 ) ;
F_82 ( V_13 , V_117 , V_57 ) ;
F_90 ( V_13 , V_131 , F_47 ( V_54 ) , V_131 ) ;
#else
F_88 ( V_13 , V_131 , V_54 ) ;
F_90 ( V_13 , V_131 , F_47 ( V_54 ) , V_131 ) ;
#endif
F_91 ( V_19 , * V_13 ) ;
F_66 ( V_13 , V_117 , V_117 , V_134 - 3 ) ;
F_51 ( V_13 , V_117 , V_117 , ( V_140 - 1 ) << 3 ) ;
F_89 ( V_13 , V_131 , V_131 , V_117 ) ;
#ifndef F_92
F_82 ( V_13 , V_117 , V_57 ) ;
F_90 ( V_13 , V_131 , 0 , V_131 ) ;
F_66 ( V_13 , V_117 , V_117 , V_141 - 3 ) ;
F_51 ( V_13 , V_117 , V_117 , ( V_142 - 1 ) << 3 ) ;
F_89 ( V_13 , V_131 , V_131 , V_117 ) ;
#endif
}
static void
F_93 ( T_2 * * V_13 , struct V_18 * * V_19 , struct V_14 * * V_15 ,
unsigned int V_143 , unsigned int V_131 ,
enum V_144 V_145 )
{
long V_146 = ( long ) V_147 ;
int V_148 ;
int V_149 = 0 ;
V_148 = F_94 ( V_146 ) && ! F_47 ( V_146 ) ;
F_95 ( V_19 , * V_13 ) ;
if ( V_145 != V_150 && V_133 ) {
if ( V_148 ) {
F_83 ( V_13 , V_15 , V_143 , V_151 ) ;
F_44 ( V_13 , V_131 , F_45 ( V_146 ) ) ;
V_149 = 1 ;
} else {
F_96 ( V_13 , V_15 , V_143 , V_152 ) ;
}
}
if ( ! V_149 ) {
if ( F_94 ( V_146 ) && ! F_47 ( V_146 ) ) {
F_70 ( V_13 , V_15 , V_151 ) ;
F_44 ( V_13 , V_131 , F_45 ( V_146 ) ) ;
} else {
F_88 ( V_13 , V_131 , V_146 ) ;
F_70 ( V_13 , V_15 , V_151 ) ;
if ( F_94 ( V_146 ) )
F_97 ( V_13 , V_131 , V_131 , F_47 ( V_146 ) ) ;
else
F_98 ( V_13 , V_131 , V_131 , F_47 ( V_146 ) ) ;
}
}
if ( V_145 != V_150 && V_133 ) {
F_99 ( V_19 , * V_13 ) ;
F_36 ( V_13 , V_131 , ( unsigned long ) V_153 ) ;
F_55 ( V_13 , V_131 ) ;
if ( V_145 == V_154 ) {
if ( V_45 >= 0 )
F_32 ( V_13 , 1 , F_23 () , V_45 ) ;
else
F_41 ( V_13 , 1 , F_9 ( 0 ) , 0 ) ;
} else {
F_52 ( V_13 ) ;
}
}
}
static void T_1
F_100 ( T_2 * * V_13 , unsigned int V_117 , unsigned int V_131 )
{
long V_54 = ( long ) V_55 ;
#ifdef F_78
#ifdef F_87
F_43 ( V_13 , V_131 , V_139 ) ;
F_88 ( V_13 , V_117 , V_54 ) ;
F_48 ( V_13 , V_131 , V_131 , 19 ) ;
#else
F_43 ( V_13 , V_131 , V_58 ) ;
F_88 ( V_13 , V_117 , V_54 ) ;
F_48 ( V_13 , V_131 , V_131 , 23 ) ;
#endif
F_50 ( V_13 , V_131 , V_117 , V_131 ) ;
#else
F_88 ( V_13 , V_131 , V_54 ) ;
#endif
F_43 ( V_13 , V_117 , V_57 ) ;
F_46 ( V_13 , V_131 , F_47 ( V_54 ) , V_131 ) ;
F_48 ( V_13 , V_117 , V_117 , V_134 ) ;
F_49 ( V_13 , V_117 , V_117 , V_155 ) ;
F_50 ( V_13 , V_131 , V_131 , V_117 ) ;
}
static void F_101 ( T_2 * * V_13 , unsigned int V_156 )
{
unsigned int V_157 = 4 - ( V_158 + 1 ) + V_136 - 12 ;
unsigned int V_159 = ( V_160 / 2 - 1 ) << ( V_158 + 1 ) ;
switch ( F_6 () ) {
case V_161 :
case V_105 :
case V_106 :
case V_107 :
case V_110 :
case V_108 :
case V_109 :
case V_111 :
V_157 += 2 ;
break;
default:
break;
}
if ( V_157 )
F_67 ( V_13 , V_156 , V_156 , V_157 ) ;
F_51 ( V_13 , V_156 , V_156 , V_159 ) ;
}
static void F_102 ( T_2 * * V_13 , unsigned int V_117 , unsigned int V_131 )
{
switch ( F_6 () ) {
case V_65 :
F_41 ( V_13 , V_131 , 0 , V_131 ) ;
F_103 ( V_13 , V_117 ) ;
break;
default:
F_103 ( V_13 , V_117 ) ;
F_41 ( V_13 , V_131 , 0 , V_131 ) ;
break;
}
F_101 ( V_13 , V_117 ) ;
F_37 ( V_13 , V_131 , V_131 , V_117 ) ;
}
static void F_104 ( T_2 * * V_13 , unsigned int V_117 , unsigned int V_162 )
{
#ifdef F_65
if ( V_163 ) {
F_90 ( V_13 , V_117 , 0 , V_162 ) ;
F_90 ( V_13 , V_162 , sizeof( V_164 ) , V_162 ) ;
if ( V_27 ) {
F_64 ( V_13 , V_117 , V_117 , F_35 ( V_116 ) ) ;
F_27 ( V_13 , V_117 , V_59 ) ;
F_64 ( V_13 , V_162 , V_162 , F_35 ( V_116 ) ) ;
} else {
F_66 ( V_13 , V_117 , V_117 , F_35 ( V_116 ) ) ;
F_27 ( V_13 , V_117 , V_59 ) ;
F_66 ( V_13 , V_162 , V_162 , F_35 ( V_116 ) ) ;
}
F_27 ( V_13 , V_162 , V_130 ) ;
} else {
int V_165 = sizeof( V_164 ) / 2 ;
int V_166 = V_165 + sizeof( V_164 ) ;
F_46 ( V_13 , V_117 , V_165 , V_162 ) ;
F_27 ( V_13 , V_117 , V_59 ) ;
F_46 ( V_13 , V_162 , V_166 , V_162 ) ;
F_27 ( V_13 , V_162 , V_130 ) ;
}
#else
F_41 ( V_13 , V_117 , 0 , V_162 ) ;
F_41 ( V_13 , V_162 , sizeof( V_164 ) , V_162 ) ;
if ( F_1 () )
F_58 ( V_13 ) ;
if ( V_27 ) {
F_64 ( V_13 , V_117 , V_117 , F_35 ( V_116 ) ) ;
if ( F_2 () )
F_27 ( V_13 , 0 , V_59 ) ;
F_27 ( V_13 , V_117 , V_59 ) ;
F_64 ( V_13 , V_162 , V_162 , F_35 ( V_116 ) ) ;
} else {
F_67 ( V_13 , V_117 , V_117 , F_35 ( V_116 ) ) ;
if ( F_2 () )
F_27 ( V_13 , 0 , V_59 ) ;
F_27 ( V_13 , V_117 , V_59 ) ;
F_67 ( V_13 , V_162 , V_162 , F_35 ( V_116 ) ) ;
if ( F_1 () )
F_43 ( V_13 , V_117 , V_167 ) ;
}
if ( F_2 () )
F_27 ( V_13 , 0 , V_130 ) ;
F_27 ( V_13 , V_162 , V_130 ) ;
#endif
}
static struct V_168
F_105 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 , unsigned int V_117 ,
unsigned int V_131 , int V_169 )
{
struct V_168 V_170 ;
unsigned int V_171 , V_172 ;
int V_173 = 0 ;
const int V_174 = 1 ;
V_170 . V_175 = V_174 ;
V_170 . V_120 = 0 ;
if ( V_133 ) {
F_32 ( V_13 , V_117 , V_57 ) ;
if ( V_138 != - 1 )
F_32 ( V_13 , V_131 , F_23 () , V_138 ) ;
else
F_32 ( V_13 , V_131 , V_58 ) ;
if ( V_169 >= 0 )
F_27 ( V_13 , V_174 , F_23 () , V_169 ) ;
else
F_38 ( V_13 , V_174 , F_9 ( 0 ) , 0 ) ;
F_66 ( V_13 , V_174 , V_117 ,
V_134 + V_135 + V_136 - 3 ) ;
F_74 ( V_13 , V_15 , V_174 , V_137 ) ;
if ( V_138 == - 1 ) {
V_173 = 1 ;
F_84 ( V_13 , V_131 , 0 , 0 , 23 ) ;
}
} else {
if ( V_138 != - 1 )
F_32 ( V_13 , V_131 , F_23 () , V_138 ) ;
else
F_32 ( V_13 , V_131 , V_58 ) ;
F_32 ( V_13 , V_117 , V_57 ) ;
if ( V_169 >= 0 )
F_27 ( V_13 , V_174 , F_23 () , V_169 ) ;
else
F_38 ( V_13 , V_174 , F_9 ( 0 ) , 0 ) ;
if ( V_138 == - 1 )
F_84 ( V_13 , V_131 , 0 , 0 , 23 ) ;
F_83 ( V_13 , V_15 , V_117 , V_137 ) ;
}
if ( V_138 == - 1 ) {
V_173 = 1 ;
F_69 ( V_13 , V_131 , V_131 , 0x540 ) ;
F_85 ( V_13 , V_131 , V_131 , 11 ) ;
}
#ifdef F_92
#define F_106 scratch
#else
#define F_106 ptr
#endif
if ( ! V_173 )
F_66 ( V_13 , V_174 , V_117 , V_134 - 3 ) ;
F_91 ( V_19 , * V_13 ) ;
if ( V_173 )
F_66 ( V_13 , V_174 , V_117 , V_134 - 3 ) ;
#ifdef F_92
F_103 ( V_13 , V_117 ) ;
#endif
F_51 ( V_13 , V_174 , V_174 , ( V_140 - 1 ) << 3 ) ;
if ( F_7 () ) {
F_107 ( V_13 , F_106 , V_174 , V_131 ) ;
} else {
F_89 ( V_13 , V_131 , V_131 , V_174 ) ;
F_90 ( V_13 , F_106 , 0 , V_131 ) ;
}
#ifndef F_92
F_66 ( V_13 , V_174 , V_117 , V_141 - 3 ) ;
F_51 ( V_13 , V_174 , V_174 , ( V_142 - 1 ) << 3 ) ;
F_103 ( V_13 , V_117 ) ;
if ( F_7 () ) {
F_107 ( V_13 , V_174 , V_174 , V_131 ) ;
} else {
F_89 ( V_13 , V_131 , V_131 , V_174 ) ;
F_41 ( V_13 , V_174 , 0 , V_131 ) ;
}
#endif
F_101 ( V_13 , V_117 ) ;
#ifdef F_19
F_73 ( V_13 , V_15 , V_174 , F_35 ( V_126 ) , V_132 ) ;
if ( F_7 () )
F_52 ( V_13 ) ;
#endif
if ( F_7 () ) {
V_171 = V_131 ;
V_172 = V_117 ;
F_107 ( V_13 , V_171 , V_174 , V_117 ) ;
F_76 ( V_13 , V_117 , V_117 , sizeof( V_164 ) ) ;
F_107 ( V_13 , V_172 , V_174 , V_117 ) ;
} else {
F_37 ( V_13 , V_131 , V_174 , V_117 ) ;
V_171 = V_117 ;
V_172 = V_131 ;
F_41 ( V_13 , V_171 , 0 , V_131 ) ;
F_41 ( V_13 , V_172 , sizeof( V_164 ) , V_131 ) ;
}
if ( V_27 ) {
F_85 ( V_13 , V_171 , V_171 , F_35 ( V_116 ) ) ;
F_27 ( V_13 , V_171 , V_59 ) ;
F_85 ( V_13 , V_172 , V_172 , F_35 ( V_116 ) ) ;
} else {
F_66 ( V_13 , V_171 , V_171 , F_35 ( V_116 ) ) ;
F_27 ( V_13 , V_171 , V_59 ) ;
F_66 ( V_13 , V_172 , V_172 , F_35 ( V_116 ) ) ;
}
F_27 ( V_13 , V_172 , V_130 ) ;
if ( V_169 >= 0 ) {
F_32 ( V_13 , V_174 , F_23 () , V_169 ) ;
F_60 ( V_13 , V_19 , V_15 , V_68 ) ;
F_108 ( V_19 , * V_13 ) ;
V_170 . V_120 = 1 ;
} else if ( V_136 == 14 || V_136 == 13 ) {
F_60 ( V_13 , V_19 , V_15 , V_68 ) ;
F_108 ( V_19 , * V_13 ) ;
F_41 ( V_13 , V_174 , F_9 ( 0 ) , 0 ) ;
} else {
F_41 ( V_13 , V_174 , F_9 ( 0 ) , 0 ) ;
F_60 ( V_13 , V_19 , V_15 , V_68 ) ;
F_108 ( V_19 , * V_13 ) ;
V_170 . V_120 = 1 ;
}
F_109 ( V_13 ) ;
return V_170 ;
}
static void F_110 ( void )
{
T_2 * V_13 = V_56 ;
struct V_18 * V_19 = V_176 ;
struct V_14 * V_15 = V_177 ;
T_2 * V_178 ;
unsigned int V_179 ;
struct V_168 T_4 T_1 ;
enum V_144 T_5 T_1 ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
if ( ( V_45 >= 0 || F_8 () ) && F_5 () ) {
T_4 = F_105 ( & V_13 , & V_19 , & V_15 , V_47 , V_49 ,
V_45 ) ;
T_5 = V_154 ;
} else {
T_4 . V_175 = V_47 ;
T_4 . V_120 = 0 ;
T_5 = V_181 ;
if ( F_3 () ) {
unsigned int V_182 = 44 ;
F_82 ( & V_13 , V_47 , V_57 ) ;
F_82 ( & V_13 , V_49 , V_183 ) ;
F_111 ( & V_13 , V_47 , V_47 , V_49 ) ;
F_66 ( & V_13 , V_49 , V_47 , 62 ) ;
F_66 ( & V_13 , V_47 , V_47 , 12 + 1 ) ;
F_112 ( & V_13 , V_47 , V_47 , 64 + 12 + 1 - V_182 ) ;
F_113 ( & V_13 , V_47 , V_47 , V_49 ) ;
F_74 ( & V_13 , & V_15 , V_47 , V_124 ) ;
}
#ifdef F_31
F_81 ( & V_13 , & V_19 , & V_15 , V_47 , V_49 ) ;
#else
F_100 ( & V_13 , V_47 , V_49 ) ;
#endif
#ifdef F_19
F_72 ( & V_13 , & V_15 , V_47 , V_49 , V_132 ) ;
#endif
F_102 ( & V_13 , V_47 , V_49 ) ;
F_104 ( & V_13 , V_47 , V_49 ) ;
F_60 ( & V_13 , & V_19 , & V_15 , V_68 ) ;
F_108 ( & V_19 , V_13 ) ;
F_109 ( & V_13 ) ;
}
#ifdef F_19
F_114 ( & V_19 , V_13 ) ;
F_75 ( & V_13 , T_4 . V_175 , V_49 ) ;
F_71 ( & V_13 , & V_19 , & V_15 , V_47 , V_68 ,
T_4 . V_120 ) ;
#endif
#ifdef F_31
F_93 ( & V_13 , & V_19 , & V_15 , V_47 , V_49 , T_5 ) ;
#endif
#if F_86 ( F_30 ) || F_86 ( V_184 )
if ( ( V_13 - V_56 ) > 64 )
F_57 ( L_23 ) ;
#else
if ( ( ( V_13 - V_56 ) > ( V_185 * 2 ) - 1 )
|| ( ( ( V_13 - V_56 ) > ( V_185 * 2 ) - 3 )
&& F_115 ( V_177 ,
V_56 + V_185 - 3 ) ) )
F_57 ( L_23 ) ;
#endif
#if F_86 ( F_30 ) || F_86 ( V_184 )
V_178 = V_180 ;
F_116 ( V_177 , V_176 , V_56 , V_13 , V_178 ) ;
V_179 = V_13 - V_56 ;
#else
V_178 = V_180 + V_185 ;
if ( ( V_13 - V_56 ) <= V_185 ) {
F_116 ( V_177 , V_176 , V_56 , V_13 , V_178 ) ;
V_179 = V_13 - V_56 ;
} else {
#ifdef F_19
const enum V_118 V_186 = V_132 ;
#else
const enum V_118 V_186 = V_137 ;
#endif
T_2 * V_187 ;
int V_188 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_117 ( V_176 ) && V_176 [ V_7 ] . V_189 != V_186 ; V_7 ++ )
;
F_118 ( V_7 == F_117 ( V_176 ) ) ;
V_187 = V_176 [ V_7 ] . V_190 ;
if ( V_187 > V_56 + V_185 ||
V_187 < V_13 - V_185 )
V_188 = 1 ;
if ( V_188 ) {
V_187 = V_56 + V_185 - 2 ;
if ( F_115 ( V_177 , V_187 - 1 ) )
V_187 -- ;
}
F_116 ( V_177 , V_176 , V_56 , V_187 , V_178 ) ;
V_178 += V_187 - V_56 ;
if ( V_188 ) {
F_119 ( & V_19 , V_180 ) ;
F_70 ( & V_178 , & V_15 , V_191 ) ;
if ( F_115 ( V_177 , V_187 ) )
F_52 ( & V_178 ) ;
else {
F_116 ( V_177 , V_176 ,
V_187 , V_187 + 1 , V_178 ) ;
F_120 ( V_176 , V_178 , V_178 + 1 , - 1 ) ;
V_178 ++ ;
V_187 ++ ;
}
}
F_116 ( V_177 , V_176 , V_187 , V_13 , V_180 ) ;
V_179 = ( V_178 - ( V_180 + V_185 ) ) +
( V_13 - V_187 ) ;
}
#endif
F_121 ( V_177 , V_176 ) ;
F_18 ( L_24 ,
V_179 ) ;
memcpy ( ( void * ) V_61 , V_180 , 0x100 ) ;
F_22 ( L_27 , ( T_2 * ) V_61 , 64 ) ;
}
static void F_122 ( void )
{
const int V_192 = 4 ;
const int V_193 = 5 ;
T_2 * V_13 = V_194 ;
const int V_195 =
V_196 - V_194 ;
struct V_18 * V_19 = V_176 ;
struct V_14 * V_15 = V_177 ;
memset ( V_194 , 0 , V_195 *
sizeof( V_194 [ 0 ] ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
V_138 = F_24 () ;
if ( V_138 == - 1 ) {
F_123 ( & V_13 , V_193 , V_192 , 29 ) ;
F_76 ( & V_13 , V_193 , V_193 , 4 ) ;
F_74 ( & V_13 , & V_15 , V_193 , V_197 ) ;
F_52 ( & V_13 ) ;
F_124 ( & V_13 , V_192 , 0 , 29 , 64 - 29 ) ;
F_125 ( & V_19 , V_13 ) ;
F_34 ( & V_13 , V_192 , V_192 , 11 ) ;
F_55 ( & V_13 , 31 ) ;
F_27 ( & V_13 , V_192 , V_58 ) ;
} else {
F_55 ( & V_13 , 31 ) ;
F_27 ( & V_13 , V_192 , F_23 () , V_138 ) ;
}
if ( V_13 >= V_196 )
F_57 ( L_28 ) ;
F_121 ( V_177 , V_176 ) ;
F_18 ( L_29 ,
( unsigned int ) ( V_13 - V_194 ) ) ;
F_22 ( L_30 , V_194 ,
V_195 ) ;
}
static void
F_126 ( T_2 * * V_13 , unsigned int V_127 , unsigned int V_131 )
{
#ifdef F_78
# ifdef F_65
if ( V_163 )
F_127 ( V_13 , V_127 , 0 , V_131 ) ;
else
# endif
F_128 ( V_13 , V_127 , 0 , V_131 ) ;
#else
# ifdef F_65
if ( V_163 )
F_90 ( V_13 , V_127 , 0 , V_131 ) ;
else
# endif
F_41 ( V_13 , V_127 , 0 , V_131 ) ;
#endif
}
static void
F_129 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_127 , unsigned int V_131 ,
unsigned int V_145 )
{
#ifdef F_65
unsigned int V_198 = V_145 & ( V_199 | V_200 ) ;
#endif
F_69 ( V_13 , V_127 , V_127 , V_145 ) ;
#ifdef F_78
# ifdef F_65
if ( V_163 )
F_130 ( V_13 , V_127 , 0 , V_131 ) ;
else
# endif
F_79 ( V_13 , V_127 , 0 , V_131 ) ;
if ( F_4 () )
F_131 ( V_13 , V_15 , V_127 , V_201 ) ;
else
F_80 ( V_13 , V_15 , V_127 , V_201 ) ;
# ifdef F_65
if ( ! V_163 ) {
F_132 ( V_13 , V_127 , sizeof( V_164 ) / 2 , V_131 ) ;
F_69 ( V_13 , V_127 , V_127 , V_198 ) ;
F_133 ( V_13 , V_127 , sizeof( V_164 ) / 2 , V_131 ) ;
F_80 ( V_13 , V_15 , V_127 , V_201 ) ;
F_46 ( V_13 , V_127 , 0 , V_131 ) ;
} else
F_52 ( V_13 ) ;
# else
F_52 ( V_13 ) ;
# endif
#else
# ifdef F_65
if ( V_163 )
F_134 ( V_13 , V_127 , 0 , V_131 ) ;
else
# endif
F_38 ( V_13 , V_127 , 0 , V_131 ) ;
# ifdef F_65
if ( ! V_163 ) {
F_46 ( V_13 , V_127 , sizeof( V_164 ) / 2 , V_131 ) ;
F_69 ( V_13 , V_127 , V_127 , V_198 ) ;
F_135 ( V_13 , V_127 , sizeof( V_164 ) / 2 , V_131 ) ;
F_46 ( V_13 , V_127 , 0 , V_131 ) ;
}
# endif
#endif
}
static void
F_136 ( T_2 * * V_13 , struct V_14 * * V_15 ,
int V_127 , int V_131 , int V_174 , enum V_118 V_119 )
{
int V_202 = V_174 >= 0 ? V_174 : V_127 ;
if ( V_27 ) {
if ( F_5 () ) {
F_137 ( V_13 , V_15 , V_127 , F_35 ( V_203 ) , V_119 ) ;
F_52 ( V_13 ) ;
} else {
F_51 ( V_13 , V_202 , V_127 , V_203 ) ;
F_80 ( V_13 , V_15 , V_202 , V_119 ) ;
if ( V_127 == V_202 )
F_126 ( V_13 , V_127 , V_131 ) ;
}
} else {
F_51 ( V_13 , V_202 , V_127 , V_203 | V_204 ) ;
F_138 ( V_13 , V_202 , V_202 , V_203 | V_204 ) ;
F_74 ( V_13 , V_15 , V_202 , V_119 ) ;
if ( V_127 == V_202 )
F_126 ( V_13 , V_127 , V_131 ) ;
}
}
static void
F_139 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_127 ,
unsigned int V_131 )
{
unsigned int V_145 = V_199 | V_205 ;
F_129 ( V_13 , V_15 , V_127 , V_131 , V_145 ) ;
}
static void
F_140 ( T_2 * * V_13 , struct V_14 * * V_15 ,
unsigned int V_127 , unsigned int V_131 , int V_174 ,
enum V_118 V_119 )
{
int V_202 = V_174 >= 0 ? V_174 : V_127 ;
F_51 ( V_13 , V_202 , V_127 , V_203 | V_206 ) ;
F_138 ( V_13 , V_202 , V_202 , V_203 | V_206 ) ;
F_74 ( V_13 , V_15 , V_202 , V_119 ) ;
if ( V_127 == V_202 )
F_126 ( V_13 , V_127 , V_131 ) ;
else
F_52 ( V_13 ) ;
}
static void
F_141 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_127 ,
unsigned int V_131 )
{
unsigned int V_145 = ( V_205 | V_207 | V_199
| V_200 ) ;
F_129 ( V_13 , V_15 , V_127 , V_131 , V_145 ) ;
}
static void
F_142 ( T_2 * * V_13 , struct V_14 * * V_15 ,
unsigned int V_127 , unsigned int V_131 , int V_174 ,
enum V_118 V_119 )
{
if ( F_5 () ) {
F_137 ( V_13 , V_15 , V_127 , F_35 ( V_206 ) , V_119 ) ;
F_52 ( V_13 ) ;
} else {
int V_202 = V_174 >= 0 ? V_174 : V_127 ;
F_51 ( V_13 , V_202 , V_127 , V_206 ) ;
F_80 ( V_13 , V_15 , V_202 , V_119 ) ;
if ( V_127 == V_202 )
F_126 ( V_13 , V_127 , V_131 ) ;
}
}
static void
F_143 ( T_2 * * V_13 , unsigned int V_127 , unsigned int V_117 )
{
F_53 ( V_13 , V_127 , V_59 ) ;
F_43 ( V_13 , V_117 , V_60 ) ;
V_70 ( V_13 ) ;
F_55 ( V_13 , V_117 ) ;
F_56 ( V_13 ) ;
}
static void
F_144 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 , unsigned int V_127 ,
unsigned int V_117 )
{
F_43 ( V_13 , V_117 , V_167 ) ;
F_53 ( V_13 , V_127 , V_59 ) ;
F_83 ( V_13 , V_15 , V_117 , V_208 ) ;
F_43 ( V_13 , V_117 , V_60 ) ;
V_70 ( V_13 ) ;
F_55 ( V_13 , V_117 ) ;
F_56 ( V_13 ) ;
F_145 ( V_19 , * V_13 ) ;
F_54 ( V_13 ) ;
F_55 ( V_13 , V_117 ) ;
F_56 ( V_13 ) ;
}
static void
F_146 ( T_2 * * V_13 , unsigned int V_127 ,
unsigned int V_131 )
{
long V_54 = ( long ) V_55 ;
F_43 ( V_13 , V_127 , V_57 ) ;
F_44 ( V_13 , V_131 , F_45 ( V_54 ) ) ;
F_46 ( V_13 , V_131 , F_47 ( V_54 ) , V_131 ) ;
F_48 ( V_13 , V_127 , V_127 , 22 ) ;
F_49 ( V_13 , V_127 , V_127 , 2 ) ;
F_50 ( V_13 , V_131 , V_131 , V_127 ) ;
F_43 ( V_13 , V_127 , V_58 ) ;
F_46 ( V_13 , V_131 , 0 , V_131 ) ;
F_51 ( V_13 , V_127 , V_127 , 0xffc ) ;
F_50 ( V_13 , V_131 , V_131 , V_127 ) ;
F_46 ( V_13 , V_127 , 0 , V_131 ) ;
F_59 ( V_13 ) ;
}
static void F_147 ( void )
{
T_2 * V_13 = V_209 ;
const int V_210 = V_211 - V_209 ;
struct V_18 * V_19 = V_176 ;
struct V_14 * V_15 = V_177 ;
memset ( V_209 , 0 , V_210 * sizeof( V_209 [ 0 ] ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
F_146 ( & V_13 , V_47 , V_49 ) ;
F_136 ( & V_13 , & V_15 , V_47 , V_49 , - 1 , V_212 ) ;
F_52 ( & V_13 ) ;
F_139 ( & V_13 , & V_15 , V_47 , V_49 ) ;
F_144 ( & V_13 , & V_19 , & V_15 , V_47 , V_49 ) ;
F_148 ( & V_19 , V_13 ) ;
F_149 ( & V_13 , ( unsigned long ) V_153 & 0x0fffffff ) ;
F_52 ( & V_13 ) ;
if ( V_13 >= V_211 )
F_57 ( L_31 ) ;
F_121 ( V_177 , V_176 ) ;
F_18 ( L_32 ,
( unsigned int ) ( V_13 - V_209 ) ) ;
F_22 ( L_33 , V_209 , V_210 ) ;
}
static void F_150 ( void )
{
T_2 * V_13 = V_213 ;
const int V_214 = V_215 - V_213 ;
struct V_18 * V_19 = V_176 ;
struct V_14 * V_15 = V_177 ;
memset ( V_213 , 0 , V_214 * sizeof( V_213 [ 0 ] ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
F_146 ( & V_13 , V_47 , V_49 ) ;
F_140 ( & V_13 , & V_15 , V_47 , V_49 , - 1 , V_216 ) ;
F_52 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_47 , V_49 ) ;
F_144 ( & V_13 , & V_19 , & V_15 , V_47 , V_49 ) ;
F_151 ( & V_19 , V_13 ) ;
F_149 ( & V_13 , ( unsigned long ) V_217 & 0x0fffffff ) ;
F_52 ( & V_13 ) ;
if ( V_13 >= V_215 )
F_57 ( L_34 ) ;
F_121 ( V_177 , V_176 ) ;
F_18 ( L_35 ,
( unsigned int ) ( V_13 - V_213 ) ) ;
F_22 ( L_36 , V_213 , V_214 ) ;
}
static void F_152 ( void )
{
T_2 * V_13 = V_218 ;
const int V_219 = V_220 - V_218 ;
struct V_18 * V_19 = V_176 ;
struct V_14 * V_15 = V_177 ;
memset ( V_218 , 0 , V_219 * sizeof( V_218 [ 0 ] ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
F_146 ( & V_13 , V_47 , V_49 ) ;
F_142 ( & V_13 , & V_15 , V_47 , V_49 , - 1 , V_221 ) ;
F_52 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_47 , V_49 ) ;
F_143 ( & V_13 , V_47 , V_49 ) ;
F_153 ( & V_19 , V_13 ) ;
F_149 ( & V_13 , ( unsigned long ) V_217 & 0x0fffffff ) ;
F_52 ( & V_13 ) ;
if ( V_13 >= V_220 )
F_57 ( L_37 ) ;
F_121 ( V_177 , V_176 ) ;
F_18 ( L_38 ,
( unsigned int ) ( V_13 - V_218 ) ) ;
F_22 ( L_39 , V_218 , V_219 ) ;
}
static struct V_41
F_154 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 )
{
struct V_41 V_222 = F_26 ( V_13 ) ;
#ifdef F_31
F_81 ( V_13 , V_19 , V_15 , V_222 . V_46 , V_222 . V_48 ) ;
#else
F_100 ( V_13 , V_222 . V_46 , V_222 . V_48 ) ;
#endif
#ifdef F_19
F_72 ( V_13 , V_15 , V_222 . V_46 , V_222 . V_48 , V_132 ) ;
#endif
F_32 ( V_13 , V_222 . V_46 , V_57 ) ;
F_41 ( V_13 , V_222 . V_48 , 0 , V_222 . V_48 ) ;
F_67 ( V_13 , V_222 . V_46 , V_222 . V_46 , V_136 + V_223 - V_158 ) ;
F_51 ( V_13 , V_222 . V_46 , V_222 . V_46 , ( V_160 - 1 ) << V_158 ) ;
F_37 ( V_13 , V_222 . V_48 , V_222 . V_48 , V_222 . V_46 ) ;
#ifdef F_78
F_155 ( V_19 , * V_13 ) ;
#endif
F_126 ( V_13 , V_222 . V_46 , V_222 . V_48 ) ;
if ( ! F_11 () )
F_58 ( V_13 ) ;
return V_222 ;
}
static void
F_156 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 , unsigned int V_117 ,
unsigned int V_131 )
{
F_69 ( V_13 , V_131 , V_131 , sizeof( V_164 ) ) ;
F_138 ( V_13 , V_131 , V_131 , sizeof( V_164 ) ) ;
F_104 ( V_13 , V_117 , V_131 ) ;
F_60 ( V_13 , V_19 , V_15 , V_69 ) ;
F_108 ( V_19 , * V_13 ) ;
F_40 ( V_13 ) ;
F_109 ( V_13 ) ;
#ifdef F_31
F_93 ( V_13 , V_19 , V_15 , V_117 , V_131 , V_150 ) ;
#endif
}
static void F_157 ( void )
{
T_2 * V_13 = V_209 ;
const int V_210 = V_211 - V_209 ;
struct V_18 * V_19 = V_176 ;
struct V_14 * V_15 = V_177 ;
struct V_41 V_222 ;
memset ( V_209 , 0 , V_210 * sizeof( V_209 [ 0 ] ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
if ( F_3 () ) {
unsigned int V_182 = 44 ;
F_82 ( & V_13 , V_47 , V_57 ) ;
F_82 ( & V_13 , V_49 , V_183 ) ;
F_111 ( & V_13 , V_47 , V_47 , V_49 ) ;
F_66 ( & V_13 , V_49 , V_47 , 62 ) ;
F_66 ( & V_13 , V_47 , V_47 , 12 + 1 ) ;
F_112 ( & V_13 , V_47 , V_47 , 64 + 12 + 1 - V_182 ) ;
F_113 ( & V_13 , V_47 , V_47 , V_49 ) ;
F_74 ( & V_13 , & V_15 , V_47 , V_124 ) ;
}
V_222 = F_154 ( & V_13 , & V_19 , & V_15 ) ;
F_136 ( & V_13 , & V_15 , V_222 . V_46 , V_222 . V_48 , V_222 . V_50 , V_212 ) ;
if ( F_11 () )
F_58 ( & V_13 ) ;
if ( V_27 ) {
if ( F_5 () ) {
F_137 ( & V_13 , & V_15 , V_222 . V_46 , F_35 ( V_199 ) ,
V_197 ) ;
} else {
F_51 ( & V_13 , V_222 . V_50 , V_222 . V_46 , V_199 ) ;
F_80 ( & V_13 , & V_15 , V_222 . V_50 , V_197 ) ;
}
F_52 ( & V_13 ) ;
F_158 ( & V_13 ) ;
switch ( F_6 () ) {
default:
if ( V_71 ) {
F_62 ( & V_13 ) ;
case V_3 :
case V_4 :
case V_5 :
break;
}
}
if ( F_5 () ) {
F_159 ( & V_13 , V_222 . V_48 , F_35 ( sizeof( V_164 ) ) , 8 ) ;
} else {
F_51 ( & V_13 , V_222 . V_50 , V_222 . V_48 , sizeof( V_164 ) ) ;
F_160 ( & V_13 , V_222 . V_50 , 8 ) ;
}
F_32 ( & V_13 , V_222 . V_50 , V_59 ) ;
F_32 ( & V_13 , V_222 . V_50 , V_130 ) ;
if ( F_5 () ) {
F_73 ( & V_13 , & V_15 , V_222 . V_50 , 1 , V_212 ) ;
F_52 ( & V_13 ) ;
F_125 ( & V_19 , V_13 ) ;
} else {
F_51 ( & V_13 , V_222 . V_50 , V_222 . V_50 , 2 ) ;
F_74 ( & V_13 , & V_15 , V_222 . V_50 , V_212 ) ;
F_52 ( & V_13 ) ;
}
F_125 ( & V_19 , V_13 ) ;
}
F_139 ( & V_13 , & V_15 , V_222 . V_46 , V_222 . V_48 ) ;
F_156 ( & V_13 , & V_19 , & V_15 , V_222 . V_46 , V_222 . V_48 ) ;
#ifdef F_19
F_114 ( & V_19 , V_13 ) ;
F_126 ( & V_13 , V_222 . V_46 , V_222 . V_48 ) ;
F_136 ( & V_13 , & V_15 , V_222 . V_46 , V_222 . V_48 , V_222 . V_50 , V_212 ) ;
F_58 ( & V_13 ) ;
if ( V_27 ) {
if ( F_5 () ) {
F_137 ( & V_13 , & V_15 , V_222 . V_46 , F_35 ( V_199 ) ,
V_224 ) ;
} else {
F_51 ( & V_13 , V_222 . V_50 , V_222 . V_46 , V_199 ) ;
F_80 ( & V_13 , & V_15 , V_222 . V_50 , V_224 ) ;
}
F_52 ( & V_13 ) ;
F_158 ( & V_13 ) ;
switch ( F_6 () ) {
default:
if ( V_71 ) {
F_62 ( & V_13 ) ;
case V_3 :
case V_4 :
case V_5 :
break;
}
}
if ( F_5 () ) {
F_159 ( & V_13 , V_222 . V_48 , F_35 ( sizeof( V_164 ) ) , 8 ) ;
} else {
F_51 ( & V_13 , V_222 . V_50 , V_222 . V_48 , sizeof( V_164 ) ) ;
F_160 ( & V_13 , V_222 . V_50 , 8 ) ;
}
F_32 ( & V_13 , V_222 . V_50 , V_59 ) ;
F_32 ( & V_13 , V_222 . V_50 , V_130 ) ;
if ( F_5 () ) {
F_137 ( & V_13 , & V_15 , V_222 . V_50 , 1 , V_224 ) ;
} else {
F_51 ( & V_13 , V_222 . V_50 , V_222 . V_50 , 2 ) ;
F_80 ( & V_13 , & V_15 , V_222 . V_50 , V_224 ) ;
}
if ( V_121 == 0 )
F_52 ( & V_13 ) ;
F_68 ( & V_13 , & V_15 , V_222 . V_50 , V_212 , 0 ) ;
F_161 ( & V_19 , V_13 ) ;
}
F_69 ( & V_13 , V_222 . V_46 , V_222 . V_46 , ( V_205 | V_199 ) ) ;
F_77 ( & V_13 , & V_15 , & V_19 , V_222 . V_46 , V_222 . V_48 ) ;
#endif
F_148 ( & V_19 , V_13 ) ;
F_40 ( & V_13 ) ;
#ifdef F_162
if ( ( unsigned long ) V_153 & 1 ) {
F_44 ( & V_13 , V_47 , F_45 ( ( long ) V_153 ) ) ;
F_97 ( & V_13 , V_47 , V_47 , F_47 ( ( long ) V_153 ) ) ;
F_55 ( & V_13 , V_47 ) ;
} else
#endif
F_149 ( & V_13 , ( unsigned long ) V_153 & 0x0fffffff ) ;
F_52 ( & V_13 ) ;
if ( V_13 >= V_211 )
F_57 ( L_31 ) ;
F_121 ( V_177 , V_176 ) ;
F_18 ( L_32 ,
( unsigned int ) ( V_13 - V_209 ) ) ;
F_22 ( L_40 , V_209 , V_210 ) ;
}
static void F_163 ( void )
{
T_2 * V_13 = V_213 ;
const int V_214 = V_215 - V_213 ;
struct V_18 * V_19 = V_176 ;
struct V_14 * V_15 = V_177 ;
struct V_41 V_222 ;
memset ( V_213 , 0 , V_214 * sizeof( V_213 [ 0 ] ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
V_222 = F_154 ( & V_13 , & V_19 , & V_15 ) ;
F_140 ( & V_13 , & V_15 , V_222 . V_46 , V_222 . V_48 , V_222 . V_50 , V_216 ) ;
if ( F_11 () )
F_58 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_222 . V_46 , V_222 . V_48 ) ;
F_156 ( & V_13 , & V_19 , & V_15 , V_222 . V_46 , V_222 . V_48 ) ;
#ifdef F_19
F_114 ( & V_19 , V_13 ) ;
F_126 ( & V_13 , V_222 . V_46 , V_222 . V_48 ) ;
F_140 ( & V_13 , & V_15 , V_222 . V_46 , V_222 . V_48 , V_222 . V_50 , V_216 ) ;
F_58 ( & V_13 ) ;
F_69 ( & V_13 , V_222 . V_46 , V_222 . V_46 ,
V_205 | V_207 | V_199 | V_200 ) ;
F_77 ( & V_13 , & V_15 , & V_19 , V_222 . V_46 , V_222 . V_48 ) ;
#endif
F_151 ( & V_19 , V_13 ) ;
F_40 ( & V_13 ) ;
#ifdef F_162
if ( ( unsigned long ) V_217 & 1 ) {
F_44 ( & V_13 , V_47 , F_45 ( ( long ) V_217 ) ) ;
F_97 ( & V_13 , V_47 , V_47 , F_47 ( ( long ) V_217 ) ) ;
F_55 ( & V_13 , V_47 ) ;
} else
#endif
F_149 ( & V_13 , ( unsigned long ) V_217 & 0x0fffffff ) ;
F_52 ( & V_13 ) ;
if ( V_13 >= V_215 )
F_57 ( L_34 ) ;
F_121 ( V_177 , V_176 ) ;
F_18 ( L_35 ,
( unsigned int ) ( V_13 - V_213 ) ) ;
F_22 ( L_41 , V_213 , V_214 ) ;
}
static void F_164 ( void )
{
T_2 * V_13 = V_218 ;
const int V_219 = V_220 - V_218 ;
struct V_18 * V_19 = V_176 ;
struct V_14 * V_15 = V_177 ;
struct V_41 V_222 ;
memset ( V_218 , 0 , V_219 * sizeof( V_218 [ 0 ] ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
V_222 = F_154 ( & V_13 , & V_19 , & V_15 ) ;
F_142 ( & V_13 , & V_15 , V_222 . V_46 , V_222 . V_48 , V_222 . V_50 , V_221 ) ;
if ( F_11 () )
F_58 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_222 . V_46 , V_222 . V_48 ) ;
F_156 ( & V_13 , & V_19 , & V_15 , V_222 . V_46 , V_222 . V_48 ) ;
#ifdef F_19
F_114 ( & V_19 , V_13 ) ;
F_126 ( & V_13 , V_222 . V_46 , V_222 . V_48 ) ;
F_142 ( & V_13 , & V_15 , V_222 . V_46 , V_222 . V_48 , V_222 . V_50 , V_221 ) ;
F_58 ( & V_13 ) ;
F_69 ( & V_13 , V_222 . V_46 , V_222 . V_46 ,
V_205 | V_207 | V_199 | V_200 ) ;
F_77 ( & V_13 , & V_15 , & V_19 , V_222 . V_46 , V_222 . V_48 ) ;
#endif
F_153 ( & V_19 , V_13 ) ;
F_40 ( & V_13 ) ;
#ifdef F_162
if ( ( unsigned long ) V_217 & 1 ) {
F_44 ( & V_13 , V_47 , F_45 ( ( long ) V_217 ) ) ;
F_97 ( & V_13 , V_47 , V_47 , F_47 ( ( long ) V_217 ) ) ;
F_55 ( & V_13 , V_47 ) ;
} else
#endif
F_149 ( & V_13 , ( unsigned long ) V_217 & 0x0fffffff ) ;
F_52 ( & V_13 ) ;
if ( V_13 >= V_220 )
F_57 ( L_37 ) ;
F_121 ( V_177 , V_176 ) ;
F_18 ( L_38 ,
( unsigned int ) ( V_13 - V_218 ) ) ;
F_22 ( L_42 , V_218 , V_219 ) ;
}
static void F_165 ( void )
{
F_166 ( ( unsigned long ) V_209 ,
( unsigned long ) V_211 ) ;
F_166 ( ( unsigned long ) V_213 ,
( unsigned long ) V_215 ) ;
F_166 ( ( unsigned long ) V_218 ,
( unsigned long ) V_220 ) ;
#ifdef F_29
F_166 ( ( unsigned long ) V_194 ,
( unsigned long ) V_196 ) ;
#endif
}
void F_167 ( void )
{
static int V_225 = 0 ;
F_16 () ;
#ifdef F_31
V_133 = V_9 . V_226 > ( V_134 + V_135 + V_136 - 3 ) ;
#endif
switch ( F_6 () ) {
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
#ifndef F_29
if ( V_234 )
F_42 () ;
if ( ! V_225 ) {
if ( ! V_234 )
F_42 () ;
F_147 () ;
F_150 () ;
F_152 () ;
F_165 () ;
V_225 ++ ;
}
#else
F_57 ( L_43 ) ;
#endif
break;
case V_235 :
case V_236 :
F_57 ( L_44 ) ;
break;
case V_237 :
F_57 ( L_45 ) ;
break;
default:
if ( ! V_225 ) {
V_45 = F_24 () ;
#ifdef F_29
F_122 () ;
#endif
F_157 () ;
F_163 () ;
F_164 () ;
if ( ! V_234 )
F_110 () ;
F_165 () ;
V_225 ++ ;
}
if ( V_234 )
F_110 () ;
}
}
