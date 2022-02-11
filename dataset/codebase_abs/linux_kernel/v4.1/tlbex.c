static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
static inline int F_2 ( void )
{
return 0 ;
}
static inline int F_3 ( void )
{
return 0 ;
}
static inline int T_2 F_4 ( void )
{
return V_3 ;
}
static inline int T_2 F_5 ( void )
{
return V_4 ;
}
static int F_6 ( void )
{
switch ( F_7 () ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return 1 ;
default:
return 0 ;
}
}
static int F_8 ( void )
{
switch ( F_7 () ) {
case V_7 :
case V_8 :
return 1 ;
default:
return 0 ;
}
}
static bool F_9 ( void )
{
return true ;
}
static int F_10 ( int V_9 )
{
V_9 += 1 ;
return V_10 * 128 - ( 8 * V_9 ) - 32768 ;
}
static bool F_9 ( void )
{
return false ;
}
static int F_10 ( int V_9 )
{
F_11 () ;
return 0 ;
}
static int F_12 ( void )
{
return ( V_11 . V_12 & 0xffff00 ) ==
( V_13 | V_14 ) ;
}
static void F_13 ( T_3 * * V_15 , struct V_16 * * V_17 , int V_18 )
{
switch ( V_18 ) {
case 0 ... 7 :
F_14 ( V_15 , V_17 , 0 , V_19 + V_18 ) ;
return;
default:
F_11 () ;
}
}
static void F_15 ( struct V_20 * * V_21 , T_3 * * V_15 , int V_18 )
{
switch ( V_18 ) {
case 0 ... 7 :
F_16 ( V_21 , * V_15 , V_19 + V_18 ) ;
break;
default:
F_11 () ;
}
}
static void F_17 ( void )
{
#define F_18 ( T_4 , ... ) \
pr_debug("#define " fmt, ##__VA_ARGS__)
F_19 ( L_1 ) ;
F_19 ( L_2 ) ;
F_19 ( L_3 ) ;
F_18 ( L_4 , V_22 ) ;
F_18 ( L_5 , V_23 ) ;
F_18 ( L_6 , V_24 ) ;
F_18 ( L_7 , V_25 ) ;
F_18 ( L_8 , V_26 ) ;
#ifdef F_20
F_18 ( L_9 , V_27 ) ;
F_18 ( L_10 , V_28 ) ;
#endif
#ifdef F_21
if ( V_29 ) {
#ifdef F_22
F_18 ( L_11 , F_22 ) ;
F_18 ( L_12 , V_30 ) ;
#endif
}
#endif
F_18 ( L_13 , V_31 ) ;
F_18 ( L_14 , V_32 ) ;
F_18 ( L_15 , V_33 ) ;
F_18 ( L_16 , V_34 ) ;
F_19 ( L_3 ) ;
}
static inline void F_23 ( const char * V_35 , const T_3 * V_36 , int V_37 )
{
int V_9 ;
F_19 ( L_17 , V_35 ) ;
F_19 ( L_18 ) ;
F_19 ( L_19 ) ;
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ )
F_19 ( L_20 , V_36 [ V_9 ] , & V_36 [ V_9 ] ) ;
F_19 ( L_21 ) ;
F_19 ( L_22 , V_35 ) ;
}
static inline int T_2 F_24 ( void )
{
switch ( F_7 () ) {
case V_38 :
case V_39 :
return 22 ;
default:
return 31 ;
}
}
static int F_25 ( void )
{
int V_17 ;
unsigned int V_40 = V_41 [ 0 ] . V_42 & ~ V_43 ;
V_17 = F_26 ( V_40 ) ;
if ( V_17 == 0 )
return - 1 ;
V_17 -- ;
V_43 |= ( 1 << V_17 ) ;
return V_17 ;
}
static struct V_44 F_27 ( T_3 * * V_15 )
{
struct V_44 V_17 ;
if ( V_45 >= 0 ) {
F_28 ( V_15 , 1 , F_24 () , V_45 ) ;
V_17 . V_46 = V_47 ;
V_17 . V_48 = V_49 ;
V_17 . V_50 = 1 ;
return V_17 ;
}
if ( F_29 () > 1 ) {
F_30 ( V_15 , V_47 , V_51 ) ;
F_31 ( V_15 , V_47 , V_47 , V_52 ) ;
F_32 ( V_15 , V_47 , V_47 , F_33 ( sizeof( struct V_53 ) ) ) ;
F_34 ( V_15 , V_49 , ( long ) & V_54 ) ;
F_35 ( V_15 , V_47 , V_47 , V_49 ) ;
} else {
F_34 ( V_15 , V_47 , ( long ) & V_54 ) ;
}
F_36 ( V_15 , 1 , F_37 ( struct V_53 , V_40 ) , V_47 ) ;
F_36 ( V_15 , 2 , F_37 ( struct V_53 , V_55 ) , V_47 ) ;
V_17 . V_46 = V_49 ;
V_17 . V_48 = 1 ;
V_17 . V_50 = 2 ;
return V_17 ;
}
static void F_38 ( T_3 * * V_15 )
{
if ( V_45 >= 0 ) {
F_39 ( V_15 , 1 , F_24 () , V_45 ) ;
return;
}
F_40 ( V_15 , 1 , F_37 ( struct V_53 , V_40 ) , V_47 ) ;
F_40 ( V_15 , 2 , F_37 ( struct V_53 , V_55 ) , V_47 ) ;
}
static void F_41 ( void )
{
long V_56 = ( long ) V_57 ;
T_3 * V_15 ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
V_15 = V_58 ;
F_42 ( & V_15 , V_47 , V_59 ) ;
F_43 ( & V_15 , V_49 , F_44 ( V_56 ) ) ;
F_45 ( & V_15 , V_49 , F_46 ( V_56 ) , V_49 ) ;
F_47 ( & V_15 , V_47 , V_47 , 22 ) ;
F_48 ( & V_15 , V_47 , V_47 , 2 ) ;
F_49 ( & V_15 , V_49 , V_49 , V_47 ) ;
F_42 ( & V_15 , V_47 , V_60 ) ;
F_45 ( & V_15 , V_49 , 0 , V_49 ) ;
F_50 ( & V_15 , V_47 , V_47 , 0xffc ) ;
F_49 ( & V_15 , V_49 , V_49 , V_47 ) ;
F_45 ( & V_15 , V_47 , 0 , V_49 ) ;
F_51 ( & V_15 ) ;
F_52 ( & V_15 , V_47 , V_61 ) ;
F_42 ( & V_15 , V_49 , V_62 ) ;
F_53 ( & V_15 ) ;
F_54 ( & V_15 , V_49 ) ;
F_55 ( & V_15 ) ;
if ( V_15 > V_58 + 32 )
F_56 ( L_23 ) ;
F_19 ( L_24 ,
( unsigned int ) ( V_15 - V_58 ) ) ;
memcpy ( ( void * ) V_63 , V_58 , 0x80 ) ;
F_57 ( V_63 , V_63 + 0x80 ) ;
F_23 ( L_25 , ( T_3 * ) V_63 , 32 ) ;
}
static void T_2 F_58 ( T_3 * * V_15 )
{
switch ( F_7 () ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
F_51 ( V_15 ) ;
F_59 ( V_15 ) ;
break;
default:
F_59 ( V_15 ) ;
break;
}
}
static void F_60 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 ,
enum V_68 V_69 )
{
void (* F_61)( T_3 * * ) = NULL ;
switch ( V_69 ) {
case V_70 : F_61 = F_53 ; break;
case V_71 : F_61 = V_72 ; break;
}
if ( V_73 ) {
if ( V_74 )
F_62 ( V_15 ) ;
F_61 ( V_15 ) ;
return;
}
switch ( F_7 () ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
F_13 ( V_15 , V_17 , V_81 ) ;
F_61 ( V_15 ) ;
F_15 ( V_21 , V_15 , V_81 ) ;
V_81 ++ ;
F_51 ( V_15 ) ;
break;
case V_64 :
case V_65 :
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
F_51 ( V_15 ) ;
break;
case V_66 :
case V_67 :
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
break;
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_39 :
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
break;
case V_86 :
case V_87 :
case V_88 :
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
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
if ( F_12 () )
F_51 ( V_15 ) ;
case V_107 :
F_61 ( V_15 ) ;
break;
case V_108 :
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
break;
case V_114 :
case V_115 :
case V_116 :
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
break;
case V_117 :
F_61 ( V_15 ) ;
F_51 ( V_15 ) ;
break;
default:
F_56 ( L_26 ,
F_7 () ) ;
break;
}
}
static T_2 void F_63 ( T_3 * * V_15 ,
unsigned int V_118 )
{
if ( V_29 ) {
F_64 ( V_15 , V_118 , V_118 , F_33 ( V_119 ) ) ;
} else {
#ifdef F_65
F_66 ( V_15 , V_118 , V_118 , F_33 ( V_119 ) ) ;
#else
F_67 ( V_15 , V_118 , V_118 , F_33 ( V_119 ) ) ;
#endif
}
}
static void F_68 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_120 , enum V_121 V_122 ,
int V_123 )
{
if ( V_123 ) {
if ( V_124 >> 16 ) {
F_43 ( V_15 , V_120 , V_124 >> 16 ) ;
F_69 ( V_15 , V_120 , V_120 , V_124 & 0xffff ) ;
F_52 ( V_15 , V_120 , V_125 ) ;
F_70 ( V_15 , V_17 , V_122 ) ;
} else if ( V_124 ) {
F_69 ( V_15 , V_120 , 0 , V_124 ) ;
F_52 ( V_15 , V_120 , V_125 ) ;
F_70 ( V_15 , V_17 , V_122 ) ;
} else {
F_52 ( V_15 , 0 , V_125 ) ;
F_70 ( V_15 , V_17 , V_122 ) ;
}
if ( V_45 >= 0 )
F_39 ( V_15 , 1 , F_24 () , V_45 ) ;
else
F_40 ( V_15 , 1 , F_10 ( 0 ) , 0 ) ;
} else {
if ( V_124 >> 16 ) {
F_43 ( V_15 , V_120 , V_124 >> 16 ) ;
F_69 ( V_15 , V_120 , V_120 , V_124 & 0xffff ) ;
F_70 ( V_15 , V_17 , V_122 ) ;
F_52 ( V_15 , V_120 , V_125 ) ;
} else if ( V_124 ) {
F_69 ( V_15 , V_120 , 0 , V_124 ) ;
F_70 ( V_15 , V_17 , V_122 ) ;
F_52 ( V_15 , V_120 , V_125 ) ;
} else {
F_70 ( V_15 , V_17 , V_122 ) ;
F_52 ( V_15 , 0 , V_125 ) ;
}
}
}
static void F_71 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 ,
unsigned int V_120 ,
enum V_68 V_69 ,
int V_123 )
{
F_43 ( V_15 , V_120 , V_126 >> 16 ) ;
F_69 ( V_15 , V_120 , V_120 , V_126 & 0xffff ) ;
F_52 ( V_15 , V_120 , V_125 ) ;
F_60 ( V_15 , V_21 , V_17 , V_69 ) ;
F_68 ( V_15 , V_17 , V_120 , V_127 , V_123 ) ;
}
static void
F_72 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_120 ,
unsigned int V_128 , int V_122 )
{
F_40 ( V_15 , V_120 , 0 , V_128 ) ;
if ( F_6 () ) {
F_73 ( V_15 , V_17 , V_120 , F_33 ( V_129 ) , V_122 ) ;
} else {
F_50 ( V_15 , V_120 , V_120 , V_129 ) ;
F_74 ( V_15 , V_17 , V_120 , V_122 ) ;
}
}
static void F_75 ( T_3 * * V_15 , unsigned int V_130 ,
unsigned int V_120 )
{
int V_131 ;
V_131 = ( V_132 >> 7 ) < 0x10000 ;
if ( ! V_131 )
F_43 ( V_15 , V_120 , V_132 >> ( 7 + 16 ) ) ;
F_63 ( V_15 , V_130 ) ;
F_28 ( V_15 , V_130 , V_61 ) ;
if ( V_131 )
F_76 ( V_15 , V_130 , V_130 , V_132 >> 7 ) ;
else
F_35 ( V_15 , V_130 , V_130 , V_120 ) ;
F_28 ( V_15 , V_130 , V_133 ) ;
}
static void F_77 ( T_3 * * V_15 , struct V_16 * * V_17 ,
struct V_20 * * V_21 ,
unsigned int V_130 ,
unsigned int V_134 )
{
#ifdef F_78
F_79 ( V_15 , V_130 , 0 , V_134 ) ;
F_80 ( V_15 , V_17 , V_130 , V_135 ) ;
F_40 ( V_15 , V_130 , 0 , V_134 ) ;
#else
F_36 ( V_15 , V_130 , 0 , V_134 ) ;
#endif
F_75 ( V_15 , V_130 , V_134 ) ;
F_71 ( V_15 , V_21 , V_17 , V_130 , V_71 , 0 ) ;
}
static void
F_81 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_120 , unsigned int V_134 )
{
#ifndef F_82
long V_56 = ( long ) V_57 ;
#endif
F_83 ( V_15 , V_120 , V_59 ) ;
if ( V_136 ) {
F_66 ( V_15 , V_134 , V_120 , V_137 + V_138 + V_139 - 3 ) ;
F_74 ( V_15 , V_17 , V_134 , V_140 ) ;
} else {
F_84 ( V_15 , V_17 , V_120 , V_140 ) ;
}
if ( V_141 != - 1 ) {
F_39 ( V_15 , V_134 , F_24 () , V_141 ) ;
} else {
#if F_85 ( F_82 )
F_39 ( V_15 , V_134 , V_60 ) ;
F_86 ( V_15 , V_134 , 0 , 0 , 23 ) ;
F_69 ( V_15 , V_134 , V_134 , 0x540 ) ;
F_87 ( V_15 , V_134 , V_134 , 11 ) ;
#elif F_85 ( F_78 )
F_30 ( V_15 , V_134 , V_51 ) ;
F_66 ( V_15 , V_134 , V_134 , V_142 ) ;
F_88 ( V_15 , V_120 , V_56 ) ;
F_89 ( V_15 , V_134 , V_134 , V_120 ) ;
F_83 ( V_15 , V_120 , V_59 ) ;
F_90 ( V_15 , V_134 , F_46 ( V_56 ) , V_134 ) ;
#else
F_88 ( V_15 , V_134 , V_56 ) ;
F_90 ( V_15 , V_134 , F_46 ( V_56 ) , V_134 ) ;
#endif
}
F_91 ( V_21 , * V_15 ) ;
F_66 ( V_15 , V_120 , V_120 , V_137 - 3 ) ;
F_50 ( V_15 , V_120 , V_120 , ( V_143 - 1 ) << 3 ) ;
F_89 ( V_15 , V_134 , V_134 , V_120 ) ;
#ifndef F_92
F_83 ( V_15 , V_120 , V_59 ) ;
F_90 ( V_15 , V_134 , 0 , V_134 ) ;
F_66 ( V_15 , V_120 , V_120 , V_144 - 3 ) ;
F_50 ( V_15 , V_120 , V_120 , ( V_145 - 1 ) << 3 ) ;
F_89 ( V_15 , V_134 , V_134 , V_120 ) ;
#endif
}
static void
F_93 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_146 , unsigned int V_134 ,
enum V_147 V_148 )
{
long V_149 = ( long ) V_150 ;
int V_151 ;
int V_152 = 0 ;
V_151 = F_94 ( V_149 ) && ! F_46 ( V_149 ) ;
F_95 ( V_21 , * V_15 ) ;
if ( V_148 != V_153 && V_136 ) {
if ( V_151 ) {
F_84 ( V_15 , V_17 , V_146 , V_154 ) ;
F_43 ( V_15 , V_134 , F_44 ( V_149 ) ) ;
V_152 = 1 ;
} else {
F_96 ( V_15 , V_17 , V_146 , V_155 ) ;
}
}
if ( ! V_152 ) {
if ( F_94 ( V_149 ) && ! F_46 ( V_149 ) ) {
F_70 ( V_15 , V_17 , V_154 ) ;
F_43 ( V_15 , V_134 , F_44 ( V_149 ) ) ;
} else {
F_88 ( V_15 , V_134 , V_149 ) ;
F_70 ( V_15 , V_17 , V_154 ) ;
if ( F_94 ( V_149 ) )
F_97 ( V_15 , V_134 , V_134 , F_46 ( V_149 ) ) ;
else
F_98 ( V_15 , V_134 , V_134 , F_46 ( V_149 ) ) ;
}
}
if ( V_148 != V_153 && V_136 ) {
F_99 ( V_21 , * V_15 ) ;
F_34 ( V_15 , V_134 , ( unsigned long ) V_156 ) ;
F_54 ( V_15 , V_134 ) ;
if ( V_148 == V_157 ) {
if ( V_45 >= 0 )
F_39 ( V_15 , 1 , F_24 () , V_45 ) ;
else
F_40 ( V_15 , 1 , F_10 ( 0 ) , 0 ) ;
} else {
F_51 ( V_15 ) ;
}
}
}
static void T_2
F_100 ( T_3 * * V_15 , unsigned int V_120 , unsigned int V_134 )
{
if ( V_141 != - 1 ) {
F_42 ( V_15 , V_134 , F_24 () , V_141 ) ;
F_42 ( V_15 , V_120 , V_59 ) ;
} else {
long V_56 = ( long ) V_57 ;
#ifdef F_78
F_42 ( V_15 , V_134 , V_51 ) ;
F_88 ( V_15 , V_120 , V_56 ) ;
F_47 ( V_15 , V_134 , V_134 , V_142 ) ;
F_49 ( V_15 , V_134 , V_120 , V_134 ) ;
#else
F_88 ( V_15 , V_134 , V_56 ) ;
#endif
F_42 ( V_15 , V_120 , V_59 ) ;
F_45 ( V_15 , V_134 , F_46 ( V_56 ) , V_134 ) ;
}
F_47 ( V_15 , V_120 , V_120 , V_137 ) ;
F_48 ( V_15 , V_120 , V_120 , V_158 ) ;
F_49 ( V_15 , V_134 , V_134 , V_120 ) ;
}
static void F_101 ( T_3 * * V_15 , unsigned int V_159 )
{
unsigned int V_160 = 4 - ( V_161 + 1 ) + V_139 - 12 ;
unsigned int V_162 = ( V_163 / 2 - 1 ) << ( V_161 + 1 ) ;
switch ( F_7 () ) {
case V_164 :
case V_109 :
case V_110 :
case V_111 :
case V_114 :
case V_112 :
case V_113 :
case V_115 :
V_160 += 2 ;
break;
default:
break;
}
if ( V_160 )
F_67 ( V_15 , V_159 , V_159 , V_160 ) ;
F_50 ( V_15 , V_159 , V_159 , V_162 ) ;
}
static void F_102 ( T_3 * * V_15 , unsigned int V_120 , unsigned int V_134 )
{
switch ( F_7 () ) {
case V_67 :
F_40 ( V_15 , V_134 , 0 , V_134 ) ;
F_103 ( V_15 , V_120 ) ;
break;
default:
F_103 ( V_15 , V_120 ) ;
F_40 ( V_15 , V_134 , 0 , V_134 ) ;
break;
}
F_101 ( V_15 , V_120 ) ;
F_35 ( V_15 , V_134 , V_134 , V_120 ) ;
}
static void F_104 ( T_3 * * V_15 , unsigned int V_120 , unsigned int V_165 )
{
#ifdef F_65
if ( V_166 ) {
F_90 ( V_15 , V_120 , 0 , V_165 ) ;
F_90 ( V_15 , V_165 , sizeof( V_167 ) , V_165 ) ;
if ( V_29 ) {
F_64 ( V_15 , V_120 , V_120 , F_33 ( V_119 ) ) ;
F_28 ( V_15 , V_120 , V_61 ) ;
F_64 ( V_15 , V_165 , V_165 , F_33 ( V_119 ) ) ;
} else {
F_66 ( V_15 , V_120 , V_120 , F_33 ( V_119 ) ) ;
F_28 ( V_15 , V_120 , V_61 ) ;
F_66 ( V_15 , V_165 , V_165 , F_33 ( V_119 ) ) ;
}
F_28 ( V_15 , V_165 , V_133 ) ;
} else {
int V_168 = sizeof( V_167 ) / 2 ;
int V_169 = V_168 + sizeof( V_167 ) ;
#ifdef F_105
const int V_170 = 1 ;
F_49 ( V_15 , V_170 , 0 , V_165 ) ;
#endif
F_45 ( V_15 , V_120 , V_168 , V_165 ) ;
F_45 ( V_15 , V_165 , V_169 , V_165 ) ;
F_64 ( V_15 , V_120 , V_120 , F_33 ( V_119 ) ) ;
F_64 ( V_15 , V_165 , V_165 , F_33 ( V_119 ) ) ;
F_28 ( V_15 , V_120 , V_61 ) ;
F_28 ( V_15 , V_165 , V_133 ) ;
#ifdef F_105
F_45 ( V_15 , V_120 , 0 , V_170 ) ;
F_45 ( V_15 , V_165 , sizeof( V_167 ) , V_170 ) ;
F_43 ( V_15 , V_170 , 0xff ) ;
F_69 ( V_15 , V_170 , V_170 , 0xffff ) ;
F_106 ( V_15 , V_120 , V_170 , V_120 ) ;
F_106 ( V_15 , V_165 , V_170 , V_165 ) ;
F_107 ( V_15 , V_120 , V_61 ) ;
F_107 ( V_15 , V_165 , V_133 ) ;
#endif
}
#else
F_40 ( V_15 , V_120 , 0 , V_165 ) ;
F_40 ( V_15 , V_165 , sizeof( V_167 ) , V_165 ) ;
if ( F_2 () )
F_58 ( V_15 ) ;
if ( V_29 ) {
F_64 ( V_15 , V_120 , V_120 , F_33 ( V_119 ) ) ;
if ( F_3 () )
F_28 ( V_15 , 0 , V_61 ) ;
F_28 ( V_15 , V_120 , V_61 ) ;
F_64 ( V_15 , V_165 , V_165 , F_33 ( V_119 ) ) ;
} else {
F_67 ( V_15 , V_120 , V_120 , F_33 ( V_119 ) ) ;
if ( F_3 () )
F_28 ( V_15 , 0 , V_61 ) ;
F_28 ( V_15 , V_120 , V_61 ) ;
F_67 ( V_15 , V_165 , V_165 , F_33 ( V_119 ) ) ;
if ( F_2 () )
F_42 ( V_15 , V_120 , V_171 ) ;
}
if ( F_3 () )
F_28 ( V_15 , 0 , V_133 ) ;
F_28 ( V_15 , V_165 , V_133 ) ;
#endif
}
static struct V_172
F_108 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_120 ,
unsigned int V_134 , int V_173 )
{
struct V_172 V_174 ;
unsigned int V_175 , V_176 ;
int V_177 = 0 ;
const int V_170 = 1 ;
V_174 . V_178 = V_170 ;
V_174 . V_123 = 0 ;
V_174 . V_179 = false ;
if ( V_136 ) {
F_39 ( V_15 , V_120 , V_59 ) ;
if ( V_141 != - 1 )
F_39 ( V_15 , V_134 , F_24 () , V_141 ) ;
else
F_39 ( V_15 , V_134 , V_60 ) ;
if ( V_173 >= 0 )
F_28 ( V_15 , V_170 , F_24 () , V_173 ) ;
else
F_36 ( V_15 , V_170 , F_10 ( 0 ) , 0 ) ;
F_66 ( V_15 , V_170 , V_120 ,
V_137 + V_138 + V_139 - 3 ) ;
F_74 ( V_15 , V_17 , V_170 , V_140 ) ;
if ( V_141 == - 1 ) {
V_177 = 1 ;
F_86 ( V_15 , V_134 , 0 , 0 , 23 ) ;
}
} else {
if ( V_141 != - 1 )
F_39 ( V_15 , V_134 , F_24 () , V_141 ) ;
else
F_39 ( V_15 , V_134 , V_60 ) ;
F_39 ( V_15 , V_120 , V_59 ) ;
if ( V_173 >= 0 )
F_28 ( V_15 , V_170 , F_24 () , V_173 ) ;
else
F_36 ( V_15 , V_170 , F_10 ( 0 ) , 0 ) ;
if ( V_141 == - 1 )
F_86 ( V_15 , V_134 , 0 , 0 , 23 ) ;
F_84 ( V_15 , V_17 , V_120 , V_140 ) ;
}
if ( V_141 == - 1 ) {
V_177 = 1 ;
F_69 ( V_15 , V_134 , V_134 , 0x540 ) ;
F_87 ( V_15 , V_134 , V_134 , 11 ) ;
}
#ifdef F_92
#define F_109 scratch
#else
#define F_109 ptr
#endif
if ( ! V_177 )
F_66 ( V_15 , V_170 , V_120 , V_137 - 3 ) ;
F_91 ( V_21 , * V_15 ) ;
if ( V_177 )
F_66 ( V_15 , V_170 , V_120 , V_137 - 3 ) ;
#ifdef F_92
F_103 ( V_15 , V_120 ) ;
#endif
F_50 ( V_15 , V_170 , V_170 , ( V_143 - 1 ) << 3 ) ;
if ( F_8 () ) {
F_110 ( V_15 , F_109 , V_170 , V_134 ) ;
} else {
F_89 ( V_15 , V_134 , V_134 , V_170 ) ;
F_90 ( V_15 , F_109 , 0 , V_134 ) ;
}
#ifndef F_92
F_66 ( V_15 , V_170 , V_120 , V_144 - 3 ) ;
F_50 ( V_15 , V_170 , V_170 , ( V_145 - 1 ) << 3 ) ;
F_103 ( V_15 , V_120 ) ;
if ( F_8 () ) {
F_110 ( V_15 , V_170 , V_170 , V_134 ) ;
} else {
F_89 ( V_15 , V_134 , V_134 , V_170 ) ;
F_40 ( V_15 , V_170 , 0 , V_134 ) ;
}
#endif
F_101 ( V_15 , V_120 ) ;
#ifdef F_20
F_73 ( V_15 , V_17 , V_170 , F_33 ( V_129 ) , V_135 ) ;
if ( F_8 () )
F_51 ( V_15 ) ;
#endif
if ( F_8 () ) {
V_175 = V_134 ;
V_176 = V_120 ;
F_110 ( V_15 , V_175 , V_170 , V_120 ) ;
F_76 ( V_15 , V_120 , V_120 , sizeof( V_167 ) ) ;
F_110 ( V_15 , V_176 , V_170 , V_120 ) ;
} else {
F_35 ( V_15 , V_134 , V_170 , V_120 ) ;
V_175 = V_120 ;
V_176 = V_134 ;
F_40 ( V_15 , V_175 , 0 , V_134 ) ;
F_40 ( V_15 , V_176 , sizeof( V_167 ) , V_134 ) ;
}
if ( V_29 ) {
F_87 ( V_15 , V_175 , V_175 , F_33 ( V_119 ) ) ;
F_28 ( V_15 , V_175 , V_61 ) ;
F_87 ( V_15 , V_176 , V_176 , F_33 ( V_119 ) ) ;
} else {
F_66 ( V_15 , V_175 , V_175 , F_33 ( V_119 ) ) ;
F_28 ( V_15 , V_175 , V_61 ) ;
F_66 ( V_15 , V_176 , V_176 , F_33 ( V_119 ) ) ;
}
F_28 ( V_15 , V_176 , V_133 ) ;
if ( V_173 >= 0 ) {
F_39 ( V_15 , V_170 , F_24 () , V_173 ) ;
F_60 ( V_15 , V_21 , V_17 , V_70 ) ;
F_111 ( V_21 , * V_15 ) ;
V_174 . V_123 = 1 ;
} else if ( V_139 == 14 || V_139 == 13 ) {
F_60 ( V_15 , V_21 , V_17 , V_70 ) ;
F_111 ( V_21 , * V_15 ) ;
F_40 ( V_15 , V_170 , F_10 ( 0 ) , 0 ) ;
} else {
F_40 ( V_15 , V_170 , F_10 ( 0 ) , 0 ) ;
F_60 ( V_15 , V_21 , V_17 , V_70 ) ;
F_111 ( V_21 , * V_15 ) ;
V_174 . V_123 = 1 ;
}
F_112 ( V_15 ) ;
return V_174 ;
}
static void F_113 ( void )
{
T_3 * V_15 = V_58 ;
struct V_20 * V_21 = V_180 ;
struct V_16 * V_17 = V_181 ;
T_3 * V_182 ;
unsigned int V_183 ;
struct V_172 T_5 T_2 ;
enum V_147 T_6 T_2 ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
if ( F_114 ( V_185 ) && ( V_45 >= 0 || F_9 () ) && F_6 () ) {
T_5 = F_108 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 ,
V_45 ) ;
T_6 = V_157 ;
} else {
T_5 . V_178 = V_47 ;
T_5 . V_123 = 0 ;
T_5 . V_179 = true ;
T_6 = V_186 ;
if ( F_4 () ) {
unsigned int V_187 = 44 ;
F_83 ( & V_15 , V_47 , V_59 ) ;
F_83 ( & V_15 , V_49 , V_188 ) ;
F_115 ( & V_15 , V_47 , V_47 , V_49 ) ;
F_66 ( & V_15 , V_49 , V_47 , 62 ) ;
F_66 ( & V_15 , V_47 , V_47 , 12 + 1 ) ;
F_116 ( & V_15 , V_47 , V_47 , 64 + 12 + 1 - V_187 ) ;
F_117 ( & V_15 , V_47 , V_47 , V_49 ) ;
F_74 ( & V_15 , & V_17 , V_47 , V_127 ) ;
}
#ifdef V_185
F_81 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 ) ;
#else
F_100 ( & V_15 , V_47 , V_49 ) ;
#endif
#ifdef F_20
F_72 ( & V_15 , & V_17 , V_47 , V_49 , V_135 ) ;
#endif
F_102 ( & V_15 , V_47 , V_49 ) ;
F_104 ( & V_15 , V_47 , V_49 ) ;
F_60 ( & V_15 , & V_21 , & V_17 , V_70 ) ;
F_111 ( & V_21 , V_15 ) ;
F_112 ( & V_15 ) ;
}
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
if ( T_5 . V_179 )
F_40 ( & V_15 , T_5 . V_178 , 0 , V_49 ) ;
F_75 ( & V_15 , T_5 . V_178 , V_49 ) ;
F_71 ( & V_15 , & V_21 , & V_17 , V_47 , V_70 ,
T_5 . V_123 ) ;
#endif
#ifdef V_185
F_93 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 , T_6 ) ;
#endif
switch ( F_119 () ) {
default:
if ( sizeof( long ) == 4 ) {
case V_104 :
if ( ( V_15 - V_58 ) > 64 )
F_56 ( L_23 ) ;
V_182 = V_184 ;
F_120 ( V_181 , V_180 , V_58 , V_15 , V_182 ) ;
V_183 = V_15 - V_58 ;
break;
} else {
if ( ( ( V_15 - V_58 ) > ( V_189 * 2 ) - 1 )
|| ( ( ( V_15 - V_58 ) > ( V_189 * 2 ) - 3 )
&& F_121 ( V_181 ,
V_58 + V_189 - 3 ) ) )
F_56 ( L_23 ) ;
V_182 = V_184 + V_189 ;
if ( ( V_15 - V_58 ) <= V_189 ) {
F_120 ( V_181 , V_180 , V_58 , V_15 , V_182 ) ;
V_183 = V_15 - V_58 ;
} else {
#ifdef F_20
const enum V_121 V_190 = V_135 ;
#else
const enum V_121 V_190 = V_140 ;
#endif
T_3 * V_191 ;
int V_192 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_122 ( V_180 ) && V_180 [ V_9 ] . V_193 != V_190 ; V_9 ++ )
;
F_123 ( V_9 == F_122 ( V_180 ) ) ;
V_191 = V_180 [ V_9 ] . V_194 ;
if ( V_191 > V_58 + V_189 ||
V_191 < V_15 - V_189 )
V_192 = 1 ;
if ( V_192 ) {
V_191 = V_58 + V_189 - 2 ;
if ( F_121 ( V_181 , V_191 - 1 ) )
V_191 -- ;
}
F_120 ( V_181 , V_180 , V_58 , V_191 , V_182 ) ;
V_182 += V_191 - V_58 ;
if ( V_192 ) {
F_124 ( & V_21 , V_184 ) ;
F_70 ( & V_182 , & V_17 , V_195 ) ;
if ( F_121 ( V_181 , V_191 ) )
F_51 ( & V_182 ) ;
else {
F_120 ( V_181 , V_180 ,
V_191 , V_191 + 1 , V_182 ) ;
F_125 ( V_180 , V_182 , V_182 + 1 , - 1 ) ;
V_182 ++ ;
V_191 ++ ;
}
}
F_120 ( V_181 , V_180 , V_191 , V_15 , V_184 ) ;
V_183 = ( V_182 - ( V_184 + V_189 ) ) +
( V_15 - V_191 ) ;
}
}
break;
}
F_126 ( V_181 , V_180 ) ;
F_19 ( L_24 ,
V_183 ) ;
memcpy ( ( void * ) V_63 , V_184 , 0x100 ) ;
F_57 ( V_63 , V_63 + 0x100 ) ;
F_23 ( L_27 , ( T_3 * ) V_63 , 64 ) ;
}
static void F_127 ( void )
{
const int V_196 = 4 ;
const int T_2 V_197 = 5 ;
const int T_2 V_198 = 6 ;
T_3 * V_15 = V_199 ;
const int V_200 =
V_201 - V_199 ;
#ifndef F_82
long V_56 = ( long ) V_57 ;
#endif
memset ( V_202 , 0 , V_200 *
sizeof( V_202 [ 0 ] ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
V_141 = F_25 () ;
#ifdef F_82
if ( V_141 == - 1 ) {
struct V_20 * V_21 = V_180 ;
struct V_16 * V_17 = V_181 ;
F_128 ( & V_15 , V_197 , V_196 , 29 ) ;
F_76 ( & V_15 , V_197 , V_197 , 4 ) ;
F_74 ( & V_15 , & V_17 , V_197 , V_203 ) ;
F_51 ( & V_15 ) ;
F_129 ( & V_15 , V_196 , 0 , 29 , 64 - 29 ) ;
F_130 ( & V_21 , V_15 ) ;
F_32 ( & V_15 , V_196 , V_196 , 11 ) ;
F_54 ( & V_15 , 31 ) ;
F_28 ( & V_15 , V_196 , V_60 ) ;
} else {
F_54 ( & V_15 , 31 ) ;
F_28 ( & V_15 , V_196 , F_24 () , V_141 ) ;
}
#else
#ifdef F_78
F_30 ( & V_15 , V_197 , V_51 ) ;
F_31 ( & V_15 , V_197 , V_197 , V_142 ) ;
F_88 ( & V_15 , V_198 , V_56 ) ;
F_35 ( & V_15 , V_198 , V_198 , V_197 ) ;
F_36 ( & V_15 , V_196 , F_46 ( V_56 ) , V_198 ) ;
#else
F_88 ( & V_15 , V_198 , V_56 ) ;
F_36 ( & V_15 , V_196 , F_46 ( V_56 ) , V_198 ) ;
#endif
F_54 ( & V_15 , 31 ) ;
if ( V_141 != - 1 )
F_28 ( & V_15 , V_196 , F_24 () , V_141 ) ;
else
F_51 ( & V_15 ) ;
#endif
if ( V_15 >= V_201 )
F_56 ( L_28 ) ;
F_126 ( V_181 , V_180 ) ;
F_19 ( L_29 ,
( unsigned int ) ( V_15 - V_202 ) ) ;
F_23 ( L_30 , V_202 ,
V_200 ) ;
}
static void
F_131 ( T_3 * * V_15 , unsigned int V_130 , unsigned int V_134 )
{
#ifdef F_78
# ifdef F_65
if ( V_166 )
F_132 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_133 ( V_15 , V_130 , 0 , V_134 ) ;
#else
# ifdef F_65
if ( V_166 )
F_90 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_40 ( V_15 , V_130 , 0 , V_134 ) ;
#endif
}
static void
F_134 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_130 , unsigned int V_134 ,
unsigned int V_148 )
{
#ifdef F_65
unsigned int V_204 = V_148 & ( V_205 | V_206 ) ;
if ( ! V_166 ) {
const int V_170 = 1 ;
F_43 ( V_15 , V_170 , ( V_148 >> 16 ) ) ;
F_117 ( V_15 , V_130 , V_130 , V_170 ) ;
} else
#endif
F_69 ( V_15 , V_130 , V_130 , V_148 ) ;
#ifdef F_78
# ifdef F_65
if ( V_166 )
F_135 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_79 ( V_15 , V_130 , 0 , V_134 ) ;
if ( F_5 () )
F_136 ( V_15 , V_17 , V_130 , V_207 ) ;
else
F_80 ( V_15 , V_17 , V_130 , V_207 ) ;
# ifdef F_65
if ( ! V_166 ) {
F_137 ( V_15 , V_130 , sizeof( V_167 ) / 2 , V_134 ) ;
F_69 ( V_15 , V_130 , V_130 , V_204 ) ;
F_138 ( V_15 , V_130 , sizeof( V_167 ) / 2 , V_134 ) ;
F_80 ( V_15 , V_17 , V_130 , V_207 ) ;
F_45 ( V_15 , V_130 , 0 , V_134 ) ;
} else
F_51 ( V_15 ) ;
# else
F_51 ( V_15 ) ;
# endif
#else
# ifdef F_65
if ( V_166 )
F_139 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_36 ( V_15 , V_130 , 0 , V_134 ) ;
# ifdef F_65
if ( ! V_166 ) {
F_45 ( V_15 , V_130 , sizeof( V_167 ) / 2 , V_134 ) ;
F_69 ( V_15 , V_130 , V_130 , V_204 ) ;
F_140 ( V_15 , V_130 , sizeof( V_167 ) / 2 , V_134 ) ;
F_45 ( V_15 , V_130 , 0 , V_134 ) ;
}
# endif
#endif
}
static void
F_141 ( T_3 * * V_15 , struct V_16 * * V_17 ,
int V_130 , int V_134 , int V_170 , enum V_121 V_122 )
{
int V_208 = V_170 >= 0 ? V_170 : V_130 ;
if ( V_29 ) {
if ( F_6 () ) {
F_142 ( V_15 , V_17 , V_130 , F_33 ( V_209 ) , V_122 ) ;
F_51 ( V_15 ) ;
} else {
F_47 ( V_15 , V_208 , V_130 , V_22 ) ;
F_50 ( V_15 , V_208 , V_208 , 1 ) ;
F_80 ( V_15 , V_17 , V_208 , V_122 ) ;
if ( V_130 == V_208 )
F_131 ( V_15 , V_130 , V_134 ) ;
}
} else {
F_47 ( V_15 , V_208 , V_130 , V_22 ) ;
F_50 ( V_15 , V_208 , V_208 , 3 ) ;
F_143 ( V_15 , V_208 , V_208 , 3 ) ;
F_74 ( V_15 , V_17 , V_208 , V_122 ) ;
if ( V_130 == V_208 )
F_131 ( V_15 , V_130 , V_134 ) ;
}
}
static void
F_144 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_130 ,
unsigned int V_134 )
{
unsigned int V_148 = V_205 | V_210 ;
F_134 ( V_15 , V_17 , V_130 , V_134 , V_148 ) ;
}
static void
F_145 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_130 , unsigned int V_134 , int V_170 ,
enum V_121 V_122 )
{
int V_208 = V_170 >= 0 ? V_170 : V_130 ;
F_47 ( V_15 , V_208 , V_130 , V_22 ) ;
F_50 ( V_15 , V_208 , V_208 , 5 ) ;
F_143 ( V_15 , V_208 , V_208 , 5 ) ;
F_74 ( V_15 , V_17 , V_208 , V_122 ) ;
if ( V_130 == V_208 )
F_131 ( V_15 , V_130 , V_134 ) ;
else
F_51 ( V_15 ) ;
}
static void
F_146 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_130 ,
unsigned int V_134 )
{
unsigned int V_148 = ( V_210 | V_211 | V_205
| V_206 ) ;
F_134 ( V_15 , V_17 , V_130 , V_134 , V_148 ) ;
}
static void
F_147 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_130 , unsigned int V_134 , int V_170 ,
enum V_121 V_122 )
{
if ( F_6 () ) {
F_142 ( V_15 , V_17 , V_130 , F_33 ( V_212 ) , V_122 ) ;
F_51 ( V_15 ) ;
} else {
int V_208 = V_170 >= 0 ? V_170 : V_130 ;
F_47 ( V_15 , V_208 , V_130 , V_24 ) ;
F_50 ( V_15 , V_208 , V_208 , 1 ) ;
F_80 ( V_15 , V_17 , V_208 , V_122 ) ;
if ( V_130 == V_208 )
F_131 ( V_15 , V_130 , V_134 ) ;
}
}
static void
F_148 ( T_3 * * V_15 , unsigned int V_130 , unsigned int V_120 )
{
F_52 ( V_15 , V_130 , V_61 ) ;
F_42 ( V_15 , V_120 , V_62 ) ;
V_72 ( V_15 ) ;
F_54 ( V_15 , V_120 ) ;
F_55 ( V_15 ) ;
}
static void
F_149 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_130 ,
unsigned int V_120 )
{
F_42 ( V_15 , V_120 , V_171 ) ;
F_52 ( V_15 , V_130 , V_61 ) ;
F_84 ( V_15 , V_17 , V_120 , V_213 ) ;
F_42 ( V_15 , V_120 , V_62 ) ;
V_72 ( V_15 ) ;
F_54 ( V_15 , V_120 ) ;
F_55 ( V_15 ) ;
F_150 ( V_21 , * V_15 ) ;
F_53 ( V_15 ) ;
F_54 ( V_15 , V_120 ) ;
F_55 ( V_15 ) ;
}
static void
F_151 ( T_3 * * V_15 , unsigned int V_130 ,
unsigned int V_134 )
{
long V_56 = ( long ) V_57 ;
F_42 ( V_15 , V_130 , V_59 ) ;
F_43 ( V_15 , V_134 , F_44 ( V_56 ) ) ;
F_45 ( V_15 , V_134 , F_46 ( V_56 ) , V_134 ) ;
F_47 ( V_15 , V_130 , V_130 , 22 ) ;
F_48 ( V_15 , V_130 , V_130 , 2 ) ;
F_49 ( V_15 , V_134 , V_134 , V_130 ) ;
F_42 ( V_15 , V_130 , V_60 ) ;
F_45 ( V_15 , V_134 , 0 , V_134 ) ;
F_50 ( V_15 , V_130 , V_130 , 0xffc ) ;
F_49 ( V_15 , V_134 , V_134 , V_130 ) ;
F_45 ( V_15 , V_130 , 0 , V_134 ) ;
F_59 ( V_15 ) ;
}
static void F_152 ( void )
{
T_3 * V_15 = V_214 ;
const int V_215 = V_216 - V_214 ;
struct V_20 * V_21 = V_180 ;
struct V_16 * V_17 = V_181 ;
memset ( V_214 , 0 , V_215 * sizeof( V_214 [ 0 ] ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
F_151 ( & V_15 , V_47 , V_49 ) ;
F_141 ( & V_15 , & V_17 , V_47 , V_49 , - 1 , V_217 ) ;
F_51 ( & V_15 ) ;
F_144 ( & V_15 , & V_17 , V_47 , V_49 ) ;
F_149 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 ) ;
F_153 ( & V_21 , V_15 ) ;
F_154 ( & V_15 , ( unsigned long ) V_156 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_216 )
F_56 ( L_31 ) ;
F_126 ( V_181 , V_180 ) ;
F_19 ( L_32 ,
( unsigned int ) ( V_15 - V_214 ) ) ;
F_23 ( L_33 , V_214 , V_215 ) ;
}
static void F_155 ( void )
{
T_3 * V_15 = V_218 ;
const int V_219 = V_220 - V_218 ;
struct V_20 * V_21 = V_180 ;
struct V_16 * V_17 = V_181 ;
memset ( V_218 , 0 , V_219 * sizeof( V_218 [ 0 ] ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
F_151 ( & V_15 , V_47 , V_49 ) ;
F_145 ( & V_15 , & V_17 , V_47 , V_49 , - 1 , V_221 ) ;
F_51 ( & V_15 ) ;
F_146 ( & V_15 , & V_17 , V_47 , V_49 ) ;
F_149 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 ) ;
F_156 ( & V_21 , V_15 ) ;
F_154 ( & V_15 , ( unsigned long ) V_222 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_220 )
F_56 ( L_34 ) ;
F_126 ( V_181 , V_180 ) ;
F_19 ( L_35 ,
( unsigned int ) ( V_15 - V_218 ) ) ;
F_23 ( L_36 , V_218 , V_219 ) ;
}
static void F_157 ( void )
{
T_3 * V_15 = V_223 ;
const int V_224 = V_225 - V_223 ;
struct V_20 * V_21 = V_180 ;
struct V_16 * V_17 = V_181 ;
memset ( V_223 , 0 , V_224 * sizeof( V_223 [ 0 ] ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
F_151 ( & V_15 , V_47 , V_49 ) ;
F_147 ( & V_15 , & V_17 , V_47 , V_49 , - 1 , V_226 ) ;
F_51 ( & V_15 ) ;
F_146 ( & V_15 , & V_17 , V_47 , V_49 ) ;
F_148 ( & V_15 , V_47 , V_49 ) ;
F_158 ( & V_21 , V_15 ) ;
F_154 ( & V_15 , ( unsigned long ) V_222 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_225 )
F_56 ( L_37 ) ;
F_126 ( V_181 , V_180 ) ;
F_19 ( L_38 ,
( unsigned int ) ( V_15 - V_223 ) ) ;
F_23 ( L_39 , V_223 , V_224 ) ;
}
static struct V_44
F_159 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 )
{
struct V_44 V_227 = F_27 ( V_15 ) ;
#ifdef V_185
F_81 ( V_15 , V_21 , V_17 , V_227 . V_46 , V_227 . V_48 ) ;
#else
F_100 ( V_15 , V_227 . V_46 , V_227 . V_48 ) ;
#endif
#ifdef F_20
F_72 ( V_15 , V_17 , V_227 . V_46 , V_227 . V_48 , V_135 ) ;
#endif
F_39 ( V_15 , V_227 . V_46 , V_59 ) ;
F_40 ( V_15 , V_227 . V_48 , 0 , V_227 . V_48 ) ;
F_67 ( V_15 , V_227 . V_46 , V_227 . V_46 , V_139 + V_228 - V_161 ) ;
F_50 ( V_15 , V_227 . V_46 , V_227 . V_46 , ( V_163 - 1 ) << V_161 ) ;
F_35 ( V_15 , V_227 . V_48 , V_227 . V_48 , V_227 . V_46 ) ;
#ifdef F_78
F_160 ( V_21 , * V_15 ) ;
#endif
F_131 ( V_15 , V_227 . V_46 , V_227 . V_48 ) ;
if ( ! F_12 () ) {
F_58 ( V_15 ) ;
if ( V_229 ) {
F_62 ( V_15 ) ;
F_42 ( V_15 , V_227 . V_50 , V_171 ) ;
F_84 ( V_15 , V_17 , V_227 . V_50 , V_127 ) ;
F_51 ( V_15 ) ;
}
}
return V_227 ;
}
static void
F_161 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_120 ,
unsigned int V_134 )
{
F_69 ( V_15 , V_134 , V_134 , sizeof( V_167 ) ) ;
F_143 ( V_15 , V_134 , V_134 , sizeof( V_167 ) ) ;
F_104 ( V_15 , V_120 , V_134 ) ;
F_60 ( V_15 , V_21 , V_17 , V_71 ) ;
F_111 ( V_21 , * V_15 ) ;
F_38 ( V_15 ) ;
F_112 ( V_15 ) ;
#ifdef V_185
F_93 ( V_15 , V_21 , V_17 , V_120 , V_134 , V_153 ) ;
#endif
}
static void F_162 ( void )
{
T_3 * V_15 = V_214 ;
const int V_215 = V_216 - V_214 ;
struct V_20 * V_21 = V_180 ;
struct V_16 * V_17 = V_181 ;
struct V_44 V_227 ;
memset ( V_214 , 0 , V_215 * sizeof( V_214 [ 0 ] ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
if ( F_4 () ) {
unsigned int V_187 = 44 ;
F_83 ( & V_15 , V_47 , V_59 ) ;
F_83 ( & V_15 , V_49 , V_188 ) ;
F_115 ( & V_15 , V_47 , V_47 , V_49 ) ;
F_66 ( & V_15 , V_49 , V_47 , 62 ) ;
F_66 ( & V_15 , V_47 , V_47 , 12 + 1 ) ;
F_116 ( & V_15 , V_47 , V_47 , 64 + 12 + 1 - V_187 ) ;
F_117 ( & V_15 , V_47 , V_47 , V_49 ) ;
F_74 ( & V_15 , & V_17 , V_47 , V_127 ) ;
}
V_227 = F_159 ( & V_15 , & V_21 , & V_17 ) ;
F_141 ( & V_15 , & V_17 , V_227 . V_46 , V_227 . V_48 , V_227 . V_50 , V_217 ) ;
if ( F_12 () )
F_58 ( & V_15 ) ;
if ( V_29 && ! V_230 ) {
if ( F_6 () ) {
F_142 ( & V_15 , & V_17 , V_227 . V_46 , F_33 ( V_205 ) ,
V_203 ) ;
} else {
F_50 ( & V_15 , V_227 . V_50 , V_227 . V_46 , V_205 ) ;
F_80 ( & V_15 , & V_17 , V_227 . V_50 , V_203 ) ;
}
F_51 ( & V_15 ) ;
F_163 ( & V_15 ) ;
switch ( F_7 () ) {
default:
if ( V_74 ) {
F_62 ( & V_15 ) ;
case V_5 :
case V_6 :
case V_7 :
break;
}
}
if ( F_6 () ) {
F_164 ( & V_15 , V_227 . V_48 , F_33 ( sizeof( V_167 ) ) , 8 ) ;
} else {
F_50 ( & V_15 , V_227 . V_50 , V_227 . V_48 , sizeof( V_167 ) ) ;
F_165 ( & V_15 , V_227 . V_50 , 8 ) ;
}
F_39 ( & V_15 , V_227 . V_50 , V_61 ) ;
F_39 ( & V_15 , V_227 . V_50 , V_133 ) ;
if ( F_6 () ) {
F_73 ( & V_15 , & V_17 , V_227 . V_50 , 1 , V_217 ) ;
F_51 ( & V_15 ) ;
F_130 ( & V_21 , V_15 ) ;
} else {
F_50 ( & V_15 , V_227 . V_50 , V_227 . V_50 , 2 ) ;
F_74 ( & V_15 , & V_17 , V_227 . V_50 , V_217 ) ;
F_51 ( & V_15 ) ;
}
F_130 ( & V_21 , V_15 ) ;
}
F_144 ( & V_15 , & V_17 , V_227 . V_46 , V_227 . V_48 ) ;
F_161 ( & V_15 , & V_21 , & V_17 , V_227 . V_46 , V_227 . V_48 ) ;
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
F_131 ( & V_15 , V_227 . V_46 , V_227 . V_48 ) ;
F_141 ( & V_15 , & V_17 , V_227 . V_46 , V_227 . V_48 , V_227 . V_50 , V_217 ) ;
F_58 ( & V_15 ) ;
if ( V_29 && ! V_230 ) {
if ( F_6 () ) {
F_142 ( & V_15 , & V_17 , V_227 . V_46 , F_33 ( V_205 ) ,
V_231 ) ;
} else {
F_50 ( & V_15 , V_227 . V_50 , V_227 . V_46 , V_205 ) ;
F_80 ( & V_15 , & V_17 , V_227 . V_50 , V_231 ) ;
}
F_51 ( & V_15 ) ;
F_163 ( & V_15 ) ;
switch ( F_7 () ) {
default:
if ( V_74 ) {
F_62 ( & V_15 ) ;
case V_5 :
case V_6 :
case V_7 :
break;
}
}
if ( F_6 () ) {
F_164 ( & V_15 , V_227 . V_48 , F_33 ( sizeof( V_167 ) ) , 8 ) ;
} else {
F_50 ( & V_15 , V_227 . V_50 , V_227 . V_48 , sizeof( V_167 ) ) ;
F_165 ( & V_15 , V_227 . V_50 , 8 ) ;
}
F_39 ( & V_15 , V_227 . V_50 , V_61 ) ;
F_39 ( & V_15 , V_227 . V_50 , V_133 ) ;
if ( F_6 () ) {
F_142 ( & V_15 , & V_17 , V_227 . V_50 , 1 , V_231 ) ;
} else {
F_50 ( & V_15 , V_227 . V_50 , V_227 . V_50 , 2 ) ;
F_80 ( & V_15 , & V_17 , V_227 . V_50 , V_231 ) ;
}
if ( V_124 == 0 )
F_51 ( & V_15 ) ;
F_68 ( & V_15 , & V_17 , V_227 . V_50 , V_217 , 0 ) ;
F_166 ( & V_21 , V_15 ) ;
}
F_69 ( & V_15 , V_227 . V_46 , V_227 . V_46 , ( V_210 | V_205 ) ) ;
F_77 ( & V_15 , & V_17 , & V_21 , V_227 . V_46 , V_227 . V_48 ) ;
#endif
F_153 ( & V_21 , V_15 ) ;
F_38 ( & V_15 ) ;
#ifdef F_167
if ( ( unsigned long ) V_156 & 1 ) {
F_43 ( & V_15 , V_47 , F_44 ( ( long ) V_156 ) ) ;
F_97 ( & V_15 , V_47 , V_47 , F_46 ( ( long ) V_156 ) ) ;
F_54 ( & V_15 , V_47 ) ;
} else
#endif
F_154 ( & V_15 , ( unsigned long ) V_156 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_216 )
F_56 ( L_31 ) ;
F_126 ( V_181 , V_180 ) ;
F_19 ( L_32 ,
( unsigned int ) ( V_15 - V_214 ) ) ;
F_23 ( L_40 , V_214 , V_215 ) ;
}
static void F_168 ( void )
{
T_3 * V_15 = V_218 ;
const int V_219 = V_220 - V_218 ;
struct V_20 * V_21 = V_180 ;
struct V_16 * V_17 = V_181 ;
struct V_44 V_227 ;
memset ( V_218 , 0 , V_219 * sizeof( V_218 [ 0 ] ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
V_227 = F_159 ( & V_15 , & V_21 , & V_17 ) ;
F_145 ( & V_15 , & V_17 , V_227 . V_46 , V_227 . V_48 , V_227 . V_50 , V_221 ) ;
if ( F_12 () )
F_58 ( & V_15 ) ;
F_146 ( & V_15 , & V_17 , V_227 . V_46 , V_227 . V_48 ) ;
F_161 ( & V_15 , & V_21 , & V_17 , V_227 . V_46 , V_227 . V_48 ) ;
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
F_131 ( & V_15 , V_227 . V_46 , V_227 . V_48 ) ;
F_145 ( & V_15 , & V_17 , V_227 . V_46 , V_227 . V_48 , V_227 . V_50 , V_221 ) ;
F_58 ( & V_15 ) ;
F_69 ( & V_15 , V_227 . V_46 , V_227 . V_46 ,
V_210 | V_211 | V_205 | V_206 ) ;
F_77 ( & V_15 , & V_17 , & V_21 , V_227 . V_46 , V_227 . V_48 ) ;
#endif
F_156 ( & V_21 , V_15 ) ;
F_38 ( & V_15 ) ;
#ifdef F_167
if ( ( unsigned long ) V_222 & 1 ) {
F_43 ( & V_15 , V_47 , F_44 ( ( long ) V_222 ) ) ;
F_97 ( & V_15 , V_47 , V_47 , F_46 ( ( long ) V_222 ) ) ;
F_54 ( & V_15 , V_47 ) ;
} else
#endif
F_154 ( & V_15 , ( unsigned long ) V_222 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_220 )
F_56 ( L_34 ) ;
F_126 ( V_181 , V_180 ) ;
F_19 ( L_35 ,
( unsigned int ) ( V_15 - V_218 ) ) ;
F_23 ( L_41 , V_218 , V_219 ) ;
}
static void F_169 ( void )
{
T_3 * V_15 = V_223 ;
const int V_224 = V_225 - V_223 ;
struct V_20 * V_21 = V_180 ;
struct V_16 * V_17 = V_181 ;
struct V_44 V_227 ;
memset ( V_223 , 0 , V_224 * sizeof( V_223 [ 0 ] ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
V_227 = F_159 ( & V_15 , & V_21 , & V_17 ) ;
F_147 ( & V_15 , & V_17 , V_227 . V_46 , V_227 . V_48 , V_227 . V_50 , V_226 ) ;
if ( F_12 () )
F_58 ( & V_15 ) ;
F_146 ( & V_15 , & V_17 , V_227 . V_46 , V_227 . V_48 ) ;
F_161 ( & V_15 , & V_21 , & V_17 , V_227 . V_46 , V_227 . V_48 ) ;
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
F_131 ( & V_15 , V_227 . V_46 , V_227 . V_48 ) ;
F_147 ( & V_15 , & V_17 , V_227 . V_46 , V_227 . V_48 , V_227 . V_50 , V_226 ) ;
F_58 ( & V_15 ) ;
F_69 ( & V_15 , V_227 . V_46 , V_227 . V_46 ,
V_210 | V_211 | V_205 | V_206 ) ;
F_77 ( & V_15 , & V_17 , & V_21 , V_227 . V_46 , V_227 . V_48 ) ;
#endif
F_158 ( & V_21 , V_15 ) ;
F_38 ( & V_15 ) ;
#ifdef F_167
if ( ( unsigned long ) V_222 & 1 ) {
F_43 ( & V_15 , V_47 , F_44 ( ( long ) V_222 ) ) ;
F_97 ( & V_15 , V_47 , V_47 , F_46 ( ( long ) V_222 ) ) ;
F_54 ( & V_15 , V_47 ) ;
} else
#endif
F_154 ( & V_15 , ( unsigned long ) V_222 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_225 )
F_56 ( L_37 ) ;
F_126 ( V_181 , V_180 ) ;
F_19 ( L_38 ,
( unsigned int ) ( V_15 - V_223 ) ) ;
F_23 ( L_42 , V_223 , V_224 ) ;
}
static void F_170 ( void )
{
F_57 ( ( unsigned long ) V_214 ,
( unsigned long ) V_216 ) ;
F_57 ( ( unsigned long ) V_218 ,
( unsigned long ) V_220 ) ;
F_57 ( ( unsigned long ) V_223 ,
( unsigned long ) V_225 ) ;
F_57 ( ( unsigned long ) V_202 ,
( unsigned long ) V_201 ) ;
}
static void F_171 ( void )
{
unsigned long V_232 ;
unsigned int V_233 ;
const int V_234 = 2 * sizeof( unsigned long ) ;
V_232 = F_172 () ;
F_19 ( L_43 ,
V_234 , V_232 ,
( V_232 & V_235 ) >> V_236 ,
( V_232 & V_237 ) >> V_238 ,
( V_232 & V_239 ) >> V_240 ,
( V_232 & V_241 ) >> V_242 ,
( V_232 & V_243 ) >> V_244 ) ;
V_232 = F_173 () ;
F_19 ( L_44 ,
V_234 , V_232 ,
( V_232 & V_245 ) >> V_246 ,
( V_232 & V_247 ) >> V_248 ,
( V_232 & V_249 ) >> V_250 ,
( V_232 & V_251 ) >> V_252 ,
( V_232 & V_253 ) >> V_254 ) ;
V_233 = F_174 () ;
F_19 ( L_45 ,
V_233 ,
( V_233 & V_255 ) >> V_256 ,
( V_233 & V_257 ) >> V_258 ,
( V_233 & V_259 ) >> V_260 ,
( V_233 & V_261 ) >> V_262 ) ;
}
static void F_175 ( void )
{
unsigned long V_263 , V_264 , V_265 ;
unsigned int V_232 ;
V_263 = F_172 () ;
V_263 &= ~ V_235 ;
V_263 |= V_137 << V_236 ;
V_263 &= ~ V_241 ;
V_263 |= V_139 << V_242 ;
V_265 = V_31 << V_244 ;
V_263 |= V_265 ;
F_176 ( V_263 ) ;
F_177 () ;
V_263 = F_172 () ;
if ( ( ( V_263 & V_243 ) << V_244 )
!= V_265 ) {
F_178 ( L_46 ,
V_265 ) ;
V_11 . V_266 &= ~ V_267 ;
return;
}
V_264 = F_33 ( V_143 ) << V_246 ;
V_264 |= F_33 ( V_163 ) << V_252 ;
if ( F_179 () & V_268 )
V_264 |= 1 ;
F_180 ( V_264 ) ;
F_177 () ;
V_232 = 1 << V_256 ;
F_181 ( V_232 ) ;
F_182 ( L_47 ) ;
F_171 () ;
}
static void F_183 ( void )
{
#ifdef F_105
unsigned int V_269 ;
if ( V_2 ) {
F_182 ( L_48 ) ;
return;
}
V_269 = F_179 () ;
F_184 ( V_269 | V_268 ) ;
F_177 () ;
V_269 = F_179 () ;
if ( V_269 & V_268 )
F_182 ( L_49 ) ;
else
F_56 ( L_50 ) ;
#endif
}
void F_185 ( void )
{
static int V_270 = 0 ;
F_17 () ;
#ifdef V_185
V_136 = V_11 . V_271 > ( V_137 + V_138 + V_139 - 3 ) ;
#endif
switch ( F_7 () ) {
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
#ifndef F_82
if ( V_279 )
F_41 () ;
if ( ! V_270 ) {
if ( ! V_279 )
F_41 () ;
F_127 () ;
F_152 () ;
F_155 () ;
F_157 () ;
F_170 () ;
V_270 ++ ;
}
#else
F_56 ( L_51 ) ;
#endif
break;
case V_280 :
case V_281 :
F_56 ( L_52 ) ;
break;
case V_282 :
F_56 ( L_53 ) ;
break;
default:
if ( ! V_270 ) {
V_45 = F_25 () ;
F_127 () ;
F_162 () ;
F_168 () ;
F_169 () ;
if ( ! V_279 )
F_113 () ;
F_170 () ;
V_270 ++ ;
}
if ( V_279 )
F_113 () ;
if ( V_283 )
F_183 () ;
if ( V_229 )
F_175 () ;
}
}
