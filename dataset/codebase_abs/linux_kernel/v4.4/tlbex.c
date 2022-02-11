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
if ( V_29 && V_119 ) {
if ( V_120 ) {
F_64 ( V_15 , V_118 , V_118 , F_33 ( V_121 ) ) ;
} else {
F_65 ( V_15 , V_118 , V_118 , F_33 ( V_119 ) ) ;
F_64 ( V_15 , V_118 , V_118 ,
F_33 ( V_121 ) - F_33 ( V_119 ) ) ;
}
} else {
#ifdef F_66
F_67 ( V_15 , V_118 , V_118 , F_33 ( V_121 ) ) ;
#else
F_65 ( V_15 , V_118 , V_118 , F_33 ( V_121 ) ) ;
#endif
}
}
static void F_68 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_122 , enum V_123 V_124 ,
int V_125 )
{
if ( V_125 ) {
if ( V_126 >> 16 ) {
F_43 ( V_15 , V_122 , V_126 >> 16 ) ;
F_69 ( V_15 , V_122 , V_122 , V_126 & 0xffff ) ;
F_52 ( V_15 , V_122 , V_127 ) ;
F_70 ( V_15 , V_17 , V_124 ) ;
} else if ( V_126 ) {
F_69 ( V_15 , V_122 , 0 , V_126 ) ;
F_52 ( V_15 , V_122 , V_127 ) ;
F_70 ( V_15 , V_17 , V_124 ) ;
} else {
F_52 ( V_15 , 0 , V_127 ) ;
F_70 ( V_15 , V_17 , V_124 ) ;
}
if ( V_45 >= 0 )
F_39 ( V_15 , 1 , F_24 () , V_45 ) ;
else
F_40 ( V_15 , 1 , F_10 ( 0 ) , 0 ) ;
} else {
if ( V_126 >> 16 ) {
F_43 ( V_15 , V_122 , V_126 >> 16 ) ;
F_69 ( V_15 , V_122 , V_122 , V_126 & 0xffff ) ;
F_70 ( V_15 , V_17 , V_124 ) ;
F_52 ( V_15 , V_122 , V_127 ) ;
} else if ( V_126 ) {
F_69 ( V_15 , V_122 , 0 , V_126 ) ;
F_70 ( V_15 , V_17 , V_124 ) ;
F_52 ( V_15 , V_122 , V_127 ) ;
} else {
F_70 ( V_15 , V_17 , V_124 ) ;
F_52 ( V_15 , 0 , V_127 ) ;
}
}
}
static void F_71 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 ,
unsigned int V_122 ,
enum V_68 V_69 ,
int V_125 )
{
F_43 ( V_15 , V_122 , V_128 >> 16 ) ;
F_69 ( V_15 , V_122 , V_122 , V_128 & 0xffff ) ;
F_52 ( V_15 , V_122 , V_127 ) ;
F_60 ( V_15 , V_21 , V_17 , V_69 ) ;
F_68 ( V_15 , V_17 , V_122 , V_129 , V_125 ) ;
}
static void
F_72 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_122 ,
unsigned int V_130 , int V_124 )
{
F_40 ( V_15 , V_122 , 0 , V_130 ) ;
if ( F_6 () ) {
F_73 ( V_15 , V_17 , V_122 , F_33 ( V_131 ) , V_124 ) ;
} else {
F_50 ( V_15 , V_122 , V_122 , V_131 ) ;
F_74 ( V_15 , V_17 , V_122 , V_124 ) ;
}
}
static void F_75 ( T_3 * * V_15 , unsigned int V_132 ,
unsigned int V_122 )
{
int V_133 ;
V_133 = ( V_134 >> 7 ) < 0x10000 ;
if ( ! V_133 )
F_43 ( V_15 , V_122 , V_134 >> ( 7 + 16 ) ) ;
F_63 ( V_15 , V_132 ) ;
F_28 ( V_15 , V_132 , V_61 ) ;
if ( V_133 )
F_76 ( V_15 , V_132 , V_132 , V_134 >> 7 ) ;
else
F_35 ( V_15 , V_132 , V_132 , V_122 ) ;
F_28 ( V_15 , V_132 , V_135 ) ;
}
static void F_77 ( T_3 * * V_15 , struct V_16 * * V_17 ,
struct V_20 * * V_21 ,
unsigned int V_132 ,
unsigned int V_136 )
{
#ifdef F_78
F_79 ( V_15 , V_132 , 0 , V_136 ) ;
F_80 ( V_15 , V_17 , V_132 , V_137 ) ;
F_40 ( V_15 , V_132 , 0 , V_136 ) ;
#else
F_36 ( V_15 , V_132 , 0 , V_136 ) ;
#endif
F_75 ( V_15 , V_132 , V_136 ) ;
F_71 ( V_15 , V_21 , V_17 , V_132 , V_71 , 0 ) ;
}
static void
F_81 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_122 , unsigned int V_136 )
{
#ifndef F_82
long V_56 = ( long ) V_57 ;
#endif
F_83 ( V_15 , V_122 , V_59 ) ;
if ( V_138 ) {
F_67 ( V_15 , V_136 , V_122 , V_139 + V_140 + V_141 - 3 ) ;
F_74 ( V_15 , V_17 , V_136 , V_142 ) ;
} else {
F_84 ( V_15 , V_17 , V_122 , V_142 ) ;
}
if ( V_143 != - 1 ) {
F_39 ( V_15 , V_136 , F_24 () , V_143 ) ;
} else {
#if F_85 ( F_82 )
F_39 ( V_15 , V_136 , V_60 ) ;
F_86 ( V_15 , V_136 , 0 , 0 , 23 ) ;
F_69 ( V_15 , V_136 , V_136 , 0x540 ) ;
F_87 ( V_15 , V_136 , V_136 , 11 ) ;
#elif F_85 ( F_78 )
F_30 ( V_15 , V_136 , V_51 ) ;
F_67 ( V_15 , V_136 , V_136 , V_144 ) ;
F_88 ( V_15 , V_122 , V_56 ) ;
F_89 ( V_15 , V_136 , V_136 , V_122 ) ;
F_83 ( V_15 , V_122 , V_59 ) ;
F_90 ( V_15 , V_136 , F_46 ( V_56 ) , V_136 ) ;
#else
F_88 ( V_15 , V_136 , V_56 ) ;
F_90 ( V_15 , V_136 , F_46 ( V_56 ) , V_136 ) ;
#endif
}
F_91 ( V_21 , * V_15 ) ;
F_67 ( V_15 , V_122 , V_122 , V_139 - 3 ) ;
F_50 ( V_15 , V_122 , V_122 , ( V_145 - 1 ) << 3 ) ;
F_89 ( V_15 , V_136 , V_136 , V_122 ) ;
#ifndef F_92
F_83 ( V_15 , V_122 , V_59 ) ;
F_90 ( V_15 , V_136 , 0 , V_136 ) ;
F_67 ( V_15 , V_122 , V_122 , V_146 - 3 ) ;
F_50 ( V_15 , V_122 , V_122 , ( V_147 - 1 ) << 3 ) ;
F_89 ( V_15 , V_136 , V_136 , V_122 ) ;
#endif
}
static void
F_93 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_148 , unsigned int V_136 ,
enum V_149 V_150 )
{
long V_151 = ( long ) V_152 ;
int V_153 ;
int V_154 = 0 ;
V_153 = F_94 ( V_151 ) && ! F_46 ( V_151 ) ;
F_95 ( V_21 , * V_15 ) ;
if ( V_150 != V_155 && V_138 ) {
if ( V_153 ) {
F_84 ( V_15 , V_17 , V_148 , V_156 ) ;
F_43 ( V_15 , V_136 , F_44 ( V_151 ) ) ;
V_154 = 1 ;
} else {
F_96 ( V_15 , V_17 , V_148 , V_157 ) ;
}
}
if ( ! V_154 ) {
if ( F_94 ( V_151 ) && ! F_46 ( V_151 ) ) {
F_70 ( V_15 , V_17 , V_156 ) ;
F_43 ( V_15 , V_136 , F_44 ( V_151 ) ) ;
} else {
F_88 ( V_15 , V_136 , V_151 ) ;
F_70 ( V_15 , V_17 , V_156 ) ;
if ( F_94 ( V_151 ) )
F_97 ( V_15 , V_136 , V_136 , F_46 ( V_151 ) ) ;
else
F_98 ( V_15 , V_136 , V_136 , F_46 ( V_151 ) ) ;
}
}
if ( V_150 != V_155 && V_138 ) {
F_99 ( V_21 , * V_15 ) ;
F_34 ( V_15 , V_136 , ( unsigned long ) V_158 ) ;
F_54 ( V_15 , V_136 ) ;
if ( V_150 == V_159 ) {
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
F_100 ( T_3 * * V_15 , unsigned int V_122 , unsigned int V_136 )
{
if ( V_143 != - 1 ) {
F_42 ( V_15 , V_136 , F_24 () , V_143 ) ;
F_42 ( V_15 , V_122 , V_59 ) ;
} else {
long V_56 = ( long ) V_57 ;
#ifdef F_78
F_42 ( V_15 , V_136 , V_51 ) ;
F_88 ( V_15 , V_122 , V_56 ) ;
F_47 ( V_15 , V_136 , V_136 , V_144 ) ;
F_49 ( V_15 , V_136 , V_122 , V_136 ) ;
#else
F_88 ( V_15 , V_136 , V_56 ) ;
#endif
F_42 ( V_15 , V_122 , V_59 ) ;
F_45 ( V_15 , V_136 , F_46 ( V_56 ) , V_136 ) ;
}
F_47 ( V_15 , V_122 , V_122 , V_139 ) ;
F_48 ( V_15 , V_122 , V_122 , V_160 ) ;
F_49 ( V_15 , V_136 , V_136 , V_122 ) ;
}
static void F_101 ( T_3 * * V_15 , unsigned int V_161 )
{
unsigned int V_162 = 4 - ( V_163 + 1 ) + V_141 - 12 ;
unsigned int V_164 = ( V_165 / 2 - 1 ) << ( V_163 + 1 ) ;
switch ( F_7 () ) {
case V_166 :
case V_109 :
case V_110 :
case V_111 :
case V_114 :
case V_112 :
case V_113 :
case V_115 :
V_162 += 2 ;
break;
default:
break;
}
if ( V_162 )
F_65 ( V_15 , V_161 , V_161 , V_162 ) ;
F_50 ( V_15 , V_161 , V_161 , V_164 ) ;
}
static void F_102 ( T_3 * * V_15 , unsigned int V_122 , unsigned int V_136 )
{
switch ( F_7 () ) {
case V_67 :
F_40 ( V_15 , V_136 , 0 , V_136 ) ;
F_103 ( V_15 , V_122 ) ;
break;
default:
F_103 ( V_15 , V_122 ) ;
F_40 ( V_15 , V_136 , 0 , V_136 ) ;
break;
}
F_101 ( V_15 , V_122 ) ;
F_35 ( V_15 , V_136 , V_136 , V_122 ) ;
}
static void F_104 ( T_3 * * V_15 , unsigned int V_122 , unsigned int V_167 )
{
if ( F_105 ( F_66 ) && ! V_168 ) {
int V_169 = sizeof( V_170 ) / 2 ;
int V_171 = V_169 + sizeof( V_170 ) ;
#ifdef F_106
const int V_172 = 1 ;
F_49 ( V_15 , V_172 , 0 , V_167 ) ;
#endif
F_45 ( V_15 , V_122 , V_169 , V_167 ) ;
F_45 ( V_15 , V_167 , V_171 , V_167 ) ;
F_64 ( V_15 , V_122 , V_122 , F_33 ( V_121 ) ) ;
F_64 ( V_15 , V_167 , V_167 , F_33 ( V_121 ) ) ;
F_28 ( V_15 , V_122 , V_61 ) ;
F_28 ( V_15 , V_167 , V_135 ) ;
#ifdef F_106
F_45 ( V_15 , V_122 , 0 , V_172 ) ;
F_45 ( V_15 , V_167 , sizeof( V_170 ) , V_172 ) ;
F_43 ( V_15 , V_172 , 0xff ) ;
F_69 ( V_15 , V_172 , V_172 , 0xffff ) ;
F_107 ( V_15 , V_122 , V_172 , V_122 ) ;
F_107 ( V_15 , V_167 , V_172 , V_167 ) ;
F_108 ( V_15 , V_122 , V_61 ) ;
F_108 ( V_15 , V_167 , V_135 ) ;
#endif
return;
}
F_40 ( V_15 , V_122 , 0 , V_167 ) ;
F_40 ( V_15 , V_167 , sizeof( V_170 ) , V_167 ) ;
if ( F_2 () )
F_58 ( V_15 ) ;
F_63 ( V_15 , V_122 ) ;
if ( F_3 () )
F_28 ( V_15 , 0 , V_61 ) ;
F_28 ( V_15 , V_122 , V_61 ) ;
F_63 ( V_15 , V_167 ) ;
if ( F_2 () )
F_42 ( V_15 , V_122 , V_173 ) ;
if ( F_3 () )
F_28 ( V_15 , 0 , V_135 ) ;
F_28 ( V_15 , V_167 , V_135 ) ;
}
static struct V_174
F_109 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_122 ,
unsigned int V_136 , int V_175 )
{
struct V_174 V_176 ;
unsigned int V_177 , V_178 ;
int V_179 = 0 ;
const int V_172 = 1 ;
V_176 . V_180 = V_172 ;
V_176 . V_125 = 0 ;
V_176 . V_181 = false ;
if ( V_138 ) {
F_39 ( V_15 , V_122 , V_59 ) ;
if ( V_143 != - 1 )
F_39 ( V_15 , V_136 , F_24 () , V_143 ) ;
else
F_39 ( V_15 , V_136 , V_60 ) ;
if ( V_175 >= 0 )
F_28 ( V_15 , V_172 , F_24 () , V_175 ) ;
else
F_36 ( V_15 , V_172 , F_10 ( 0 ) , 0 ) ;
F_67 ( V_15 , V_172 , V_122 ,
V_139 + V_140 + V_141 - 3 ) ;
F_74 ( V_15 , V_17 , V_172 , V_142 ) ;
if ( V_143 == - 1 ) {
V_179 = 1 ;
F_86 ( V_15 , V_136 , 0 , 0 , 23 ) ;
}
} else {
if ( V_143 != - 1 )
F_39 ( V_15 , V_136 , F_24 () , V_143 ) ;
else
F_39 ( V_15 , V_136 , V_60 ) ;
F_39 ( V_15 , V_122 , V_59 ) ;
if ( V_175 >= 0 )
F_28 ( V_15 , V_172 , F_24 () , V_175 ) ;
else
F_36 ( V_15 , V_172 , F_10 ( 0 ) , 0 ) ;
if ( V_143 == - 1 )
F_86 ( V_15 , V_136 , 0 , 0 , 23 ) ;
F_84 ( V_15 , V_17 , V_122 , V_142 ) ;
}
if ( V_143 == - 1 ) {
V_179 = 1 ;
F_69 ( V_15 , V_136 , V_136 , 0x540 ) ;
F_87 ( V_15 , V_136 , V_136 , 11 ) ;
}
#ifdef F_92
#define F_110 scratch
#else
#define F_110 ptr
#endif
if ( ! V_179 )
F_67 ( V_15 , V_172 , V_122 , V_139 - 3 ) ;
F_91 ( V_21 , * V_15 ) ;
if ( V_179 )
F_67 ( V_15 , V_172 , V_122 , V_139 - 3 ) ;
#ifdef F_92
F_103 ( V_15 , V_122 ) ;
#endif
F_50 ( V_15 , V_172 , V_172 , ( V_145 - 1 ) << 3 ) ;
if ( F_8 () ) {
F_111 ( V_15 , F_110 , V_172 , V_136 ) ;
} else {
F_89 ( V_15 , V_136 , V_136 , V_172 ) ;
F_90 ( V_15 , F_110 , 0 , V_136 ) ;
}
#ifndef F_92
F_67 ( V_15 , V_172 , V_122 , V_146 - 3 ) ;
F_50 ( V_15 , V_172 , V_172 , ( V_147 - 1 ) << 3 ) ;
F_103 ( V_15 , V_122 ) ;
if ( F_8 () ) {
F_111 ( V_15 , V_172 , V_172 , V_136 ) ;
} else {
F_89 ( V_15 , V_136 , V_136 , V_172 ) ;
F_40 ( V_15 , V_172 , 0 , V_136 ) ;
}
#endif
F_101 ( V_15 , V_122 ) ;
#ifdef F_20
F_73 ( V_15 , V_17 , V_172 , F_33 ( V_131 ) , V_137 ) ;
if ( F_8 () )
F_51 ( V_15 ) ;
#endif
if ( F_8 () ) {
V_177 = V_136 ;
V_178 = V_122 ;
F_111 ( V_15 , V_177 , V_172 , V_122 ) ;
F_76 ( V_15 , V_122 , V_122 , sizeof( V_170 ) ) ;
F_111 ( V_15 , V_178 , V_172 , V_122 ) ;
} else {
F_35 ( V_15 , V_136 , V_172 , V_122 ) ;
V_177 = V_122 ;
V_178 = V_136 ;
F_40 ( V_15 , V_177 , 0 , V_136 ) ;
F_40 ( V_15 , V_178 , sizeof( V_170 ) , V_136 ) ;
}
if ( V_29 ) {
F_87 ( V_15 , V_177 , V_177 , F_33 ( V_121 ) ) ;
F_28 ( V_15 , V_177 , V_61 ) ;
F_87 ( V_15 , V_178 , V_178 , F_33 ( V_121 ) ) ;
} else {
F_67 ( V_15 , V_177 , V_177 , F_33 ( V_121 ) ) ;
F_28 ( V_15 , V_177 , V_61 ) ;
F_67 ( V_15 , V_178 , V_178 , F_33 ( V_121 ) ) ;
}
F_28 ( V_15 , V_178 , V_135 ) ;
if ( V_175 >= 0 ) {
F_39 ( V_15 , V_172 , F_24 () , V_175 ) ;
F_60 ( V_15 , V_21 , V_17 , V_70 ) ;
F_112 ( V_21 , * V_15 ) ;
V_176 . V_125 = 1 ;
} else if ( V_141 == 14 || V_141 == 13 ) {
F_60 ( V_15 , V_21 , V_17 , V_70 ) ;
F_112 ( V_21 , * V_15 ) ;
F_40 ( V_15 , V_172 , F_10 ( 0 ) , 0 ) ;
} else {
F_40 ( V_15 , V_172 , F_10 ( 0 ) , 0 ) ;
F_60 ( V_15 , V_21 , V_17 , V_70 ) ;
F_112 ( V_21 , * V_15 ) ;
V_176 . V_125 = 1 ;
}
F_113 ( V_15 ) ;
return V_176 ;
}
static void F_114 ( void )
{
T_3 * V_15 = V_58 ;
struct V_20 * V_21 = V_182 ;
struct V_16 * V_17 = V_183 ;
T_3 * V_184 ;
unsigned int V_185 ;
struct V_174 T_5 T_2 ;
enum V_149 T_6 T_2 ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
if ( F_115 ( V_187 ) && ( V_45 >= 0 || F_9 () ) && F_6 () ) {
T_5 = F_109 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 ,
V_45 ) ;
T_6 = V_159 ;
} else {
T_5 . V_180 = V_47 ;
T_5 . V_125 = 0 ;
T_5 . V_181 = true ;
T_6 = V_188 ;
if ( F_4 () ) {
unsigned int V_189 = 44 ;
F_83 ( & V_15 , V_47 , V_59 ) ;
F_83 ( & V_15 , V_49 , V_190 ) ;
F_116 ( & V_15 , V_47 , V_47 , V_49 ) ;
F_67 ( & V_15 , V_49 , V_47 , 62 ) ;
F_67 ( & V_15 , V_47 , V_47 , 12 + 1 ) ;
F_117 ( & V_15 , V_47 , V_47 , 64 + 12 + 1 - V_189 ) ;
F_118 ( & V_15 , V_47 , V_47 , V_49 ) ;
F_74 ( & V_15 , & V_17 , V_47 , V_129 ) ;
}
#ifdef V_187
F_81 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 ) ;
#else
F_100 ( & V_15 , V_47 , V_49 ) ;
#endif
#ifdef F_20
F_72 ( & V_15 , & V_17 , V_47 , V_49 , V_137 ) ;
#endif
F_102 ( & V_15 , V_47 , V_49 ) ;
F_104 ( & V_15 , V_47 , V_49 ) ;
F_60 ( & V_15 , & V_21 , & V_17 , V_70 ) ;
F_112 ( & V_21 , V_15 ) ;
F_113 ( & V_15 ) ;
}
#ifdef F_20
F_119 ( & V_21 , V_15 ) ;
if ( T_5 . V_181 )
F_40 ( & V_15 , T_5 . V_180 , 0 , V_49 ) ;
F_75 ( & V_15 , T_5 . V_180 , V_49 ) ;
F_71 ( & V_15 , & V_21 , & V_17 , V_47 , V_70 ,
T_5 . V_125 ) ;
#endif
#ifdef V_187
F_93 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 , T_6 ) ;
#endif
switch ( F_120 () ) {
default:
if ( sizeof( long ) == 4 ) {
case V_104 :
if ( ( V_15 - V_58 ) > 64 )
F_56 ( L_23 ) ;
V_184 = V_186 ;
F_121 ( V_183 , V_182 , V_58 , V_15 , V_184 ) ;
V_185 = V_15 - V_58 ;
break;
} else {
if ( ( ( V_15 - V_58 ) > ( V_191 * 2 ) - 1 )
|| ( ( ( V_15 - V_58 ) > ( V_191 * 2 ) - 3 )
&& F_122 ( V_183 ,
V_58 + V_191 - 3 ) ) )
F_56 ( L_23 ) ;
V_184 = V_186 + V_191 ;
if ( ( V_15 - V_58 ) <= V_191 ) {
F_121 ( V_183 , V_182 , V_58 , V_15 , V_184 ) ;
V_185 = V_15 - V_58 ;
} else {
#ifdef F_20
const enum V_123 V_192 = V_137 ;
#else
const enum V_123 V_192 = V_142 ;
#endif
T_3 * V_193 ;
int V_194 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_123 ( V_182 ) && V_182 [ V_9 ] . V_195 != V_192 ; V_9 ++ )
;
F_124 ( V_9 == F_123 ( V_182 ) ) ;
V_193 = V_182 [ V_9 ] . V_196 ;
if ( V_193 > V_58 + V_191 ||
V_193 < V_15 - V_191 )
V_194 = 1 ;
if ( V_194 ) {
V_193 = V_58 + V_191 - 2 ;
if ( F_122 ( V_183 , V_193 - 1 ) )
V_193 -- ;
}
F_121 ( V_183 , V_182 , V_58 , V_193 , V_184 ) ;
V_184 += V_193 - V_58 ;
if ( V_194 ) {
F_125 ( & V_21 , V_186 ) ;
F_70 ( & V_184 , & V_17 , V_197 ) ;
if ( F_122 ( V_183 , V_193 ) )
F_51 ( & V_184 ) ;
else {
F_121 ( V_183 , V_182 ,
V_193 , V_193 + 1 , V_184 ) ;
F_126 ( V_182 , V_184 , V_184 + 1 , - 1 ) ;
V_184 ++ ;
V_193 ++ ;
}
}
F_121 ( V_183 , V_182 , V_193 , V_15 , V_186 ) ;
V_185 = ( V_184 - ( V_186 + V_191 ) ) +
( V_15 - V_193 ) ;
}
}
break;
}
F_127 ( V_183 , V_182 ) ;
F_19 ( L_24 ,
V_185 ) ;
memcpy ( ( void * ) V_63 , V_186 , 0x100 ) ;
F_57 ( V_63 , V_63 + 0x100 ) ;
F_23 ( L_27 , ( T_3 * ) V_63 , 64 ) ;
}
static void F_128 ( void )
{
const int V_198 = 4 ;
const int T_2 V_199 = 5 ;
const int T_2 V_200 = 6 ;
T_3 * V_15 = V_201 ;
const int V_202 =
V_203 - V_201 ;
#ifndef F_82
long V_56 = ( long ) V_57 ;
#endif
memset ( V_204 , 0 , V_202 *
sizeof( V_204 [ 0 ] ) ) ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
V_143 = F_25 () ;
#ifdef F_82
if ( V_143 == - 1 ) {
struct V_20 * V_21 = V_182 ;
struct V_16 * V_17 = V_183 ;
F_129 ( & V_15 , V_199 , V_198 , 29 ) ;
F_76 ( & V_15 , V_199 , V_199 , 4 ) ;
F_74 ( & V_15 , & V_17 , V_199 , V_205 ) ;
F_51 ( & V_15 ) ;
F_130 ( & V_15 , V_198 , 0 , 29 , 64 - 29 ) ;
F_131 ( & V_21 , V_15 ) ;
F_32 ( & V_15 , V_198 , V_198 , 11 ) ;
F_54 ( & V_15 , 31 ) ;
F_28 ( & V_15 , V_198 , V_60 ) ;
} else {
F_54 ( & V_15 , 31 ) ;
F_28 ( & V_15 , V_198 , F_24 () , V_143 ) ;
}
#else
#ifdef F_78
F_30 ( & V_15 , V_199 , V_51 ) ;
F_31 ( & V_15 , V_199 , V_199 , V_144 ) ;
F_88 ( & V_15 , V_200 , V_56 ) ;
F_35 ( & V_15 , V_200 , V_200 , V_199 ) ;
F_36 ( & V_15 , V_198 , F_46 ( V_56 ) , V_200 ) ;
#else
F_88 ( & V_15 , V_200 , V_56 ) ;
F_36 ( & V_15 , V_198 , F_46 ( V_56 ) , V_200 ) ;
#endif
F_54 ( & V_15 , 31 ) ;
if ( V_143 != - 1 )
F_28 ( & V_15 , V_198 , F_24 () , V_143 ) ;
else
F_51 ( & V_15 ) ;
#endif
if ( V_15 >= V_203 )
F_56 ( L_28 ) ;
F_127 ( V_183 , V_182 ) ;
F_19 ( L_29 ,
( unsigned int ) ( V_15 - V_204 ) ) ;
F_23 ( L_30 , V_204 ,
V_202 ) ;
}
static void
F_132 ( T_3 * * V_15 , unsigned int V_132 , unsigned int V_136 )
{
#ifdef F_78
# ifdef F_66
if ( V_168 )
F_133 ( V_15 , V_132 , 0 , V_136 ) ;
else
# endif
F_134 ( V_15 , V_132 , 0 , V_136 ) ;
#else
# ifdef F_66
if ( V_168 )
F_90 ( V_15 , V_132 , 0 , V_136 ) ;
else
# endif
F_40 ( V_15 , V_132 , 0 , V_136 ) ;
#endif
}
static void
F_135 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_132 , unsigned int V_136 ,
unsigned int V_150 )
{
#ifdef F_66
unsigned int V_206 = V_150 & ( V_207 | V_208 ) ;
if ( ! V_168 ) {
const int V_172 = 1 ;
F_43 ( V_15 , V_172 , ( V_150 >> 16 ) ) ;
F_118 ( V_15 , V_132 , V_132 , V_172 ) ;
} else
#endif
F_69 ( V_15 , V_132 , V_132 , V_150 ) ;
#ifdef F_78
# ifdef F_66
if ( V_168 )
F_136 ( V_15 , V_132 , 0 , V_136 ) ;
else
# endif
F_79 ( V_15 , V_132 , 0 , V_136 ) ;
if ( F_5 () )
F_137 ( V_15 , V_17 , V_132 , V_209 ) ;
else
F_80 ( V_15 , V_17 , V_132 , V_209 ) ;
# ifdef F_66
if ( ! V_168 ) {
F_138 ( V_15 , V_132 , sizeof( V_170 ) / 2 , V_136 ) ;
F_69 ( V_15 , V_132 , V_132 , V_206 ) ;
F_139 ( V_15 , V_132 , sizeof( V_170 ) / 2 , V_136 ) ;
F_80 ( V_15 , V_17 , V_132 , V_209 ) ;
F_45 ( V_15 , V_132 , 0 , V_136 ) ;
} else
F_51 ( V_15 ) ;
# else
F_51 ( V_15 ) ;
# endif
#else
# ifdef F_66
if ( V_168 )
F_140 ( V_15 , V_132 , 0 , V_136 ) ;
else
# endif
F_36 ( V_15 , V_132 , 0 , V_136 ) ;
# ifdef F_66
if ( ! V_168 ) {
F_45 ( V_15 , V_132 , sizeof( V_170 ) / 2 , V_136 ) ;
F_69 ( V_15 , V_132 , V_132 , V_206 ) ;
F_141 ( V_15 , V_132 , sizeof( V_170 ) / 2 , V_136 ) ;
F_45 ( V_15 , V_132 , 0 , V_136 ) ;
}
# endif
#endif
}
static void
F_142 ( T_3 * * V_15 , struct V_16 * * V_17 ,
int V_132 , int V_136 , int V_172 , enum V_123 V_124 )
{
int V_210 = V_172 >= 0 ? V_172 : V_132 ;
int V_211 = V_132 ;
if ( V_29 ) {
if ( F_6 () ) {
F_143 ( V_15 , V_17 , V_132 , F_33 ( V_212 ) , V_124 ) ;
F_51 ( V_15 ) ;
} else {
if ( V_22 ) {
F_47 ( V_15 , V_210 , V_211 , V_22 ) ;
V_211 = V_210 ;
}
F_50 ( V_15 , V_210 , V_211 , 1 ) ;
F_80 ( V_15 , V_17 , V_210 , V_124 ) ;
if ( V_132 == V_210 )
F_132 ( V_15 , V_132 , V_136 ) ;
}
} else {
if ( V_22 ) {
F_47 ( V_15 , V_210 , V_211 , V_22 ) ;
V_211 = V_210 ;
}
F_50 ( V_15 , V_210 , V_211 ,
( V_212 | V_213 ) >> V_22 ) ;
F_144 ( V_15 , V_210 , V_210 ,
( V_212 | V_213 ) >> V_22 ) ;
F_74 ( V_15 , V_17 , V_210 , V_124 ) ;
if ( V_132 == V_210 )
F_132 ( V_15 , V_132 , V_136 ) ;
}
}
static void
F_145 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_132 ,
unsigned int V_136 )
{
unsigned int V_150 = V_207 | V_214 ;
F_135 ( V_15 , V_17 , V_132 , V_136 , V_150 ) ;
}
static void
F_146 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_132 , unsigned int V_136 , int V_172 ,
enum V_123 V_124 )
{
int V_210 = V_172 >= 0 ? V_172 : V_132 ;
int V_211 = V_132 ;
if ( V_22 ) {
F_47 ( V_15 , V_210 , V_211 , V_22 ) ;
V_211 = V_210 ;
}
F_50 ( V_15 , V_210 , V_211 ,
( V_212 | V_215 ) >> V_22 ) ;
F_144 ( V_15 , V_210 , V_210 ,
( V_212 | V_215 ) >> V_22 ) ;
F_74 ( V_15 , V_17 , V_210 , V_124 ) ;
if ( V_132 == V_210 )
F_132 ( V_15 , V_132 , V_136 ) ;
else
F_51 ( V_15 ) ;
}
static void
F_147 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_132 ,
unsigned int V_136 )
{
unsigned int V_150 = ( V_214 | V_216 | V_207
| V_208 ) ;
F_135 ( V_15 , V_17 , V_132 , V_136 , V_150 ) ;
}
static void
F_148 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_132 , unsigned int V_136 , int V_172 ,
enum V_123 V_124 )
{
if ( F_6 () ) {
F_143 ( V_15 , V_17 , V_132 , F_33 ( V_215 ) , V_124 ) ;
F_51 ( V_15 ) ;
} else {
int V_210 = V_172 >= 0 ? V_172 : V_132 ;
F_47 ( V_15 , V_210 , V_132 , V_24 ) ;
F_50 ( V_15 , V_210 , V_210 , 1 ) ;
F_80 ( V_15 , V_17 , V_210 , V_124 ) ;
if ( V_132 == V_210 )
F_132 ( V_15 , V_132 , V_136 ) ;
}
}
static void
F_149 ( T_3 * * V_15 , unsigned int V_132 , unsigned int V_122 )
{
F_52 ( V_15 , V_132 , V_61 ) ;
F_42 ( V_15 , V_122 , V_62 ) ;
V_72 ( V_15 ) ;
F_54 ( V_15 , V_122 ) ;
F_55 ( V_15 ) ;
}
static void
F_150 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_132 ,
unsigned int V_122 )
{
F_42 ( V_15 , V_122 , V_173 ) ;
F_52 ( V_15 , V_132 , V_61 ) ;
F_84 ( V_15 , V_17 , V_122 , V_217 ) ;
F_42 ( V_15 , V_122 , V_62 ) ;
V_72 ( V_15 ) ;
F_54 ( V_15 , V_122 ) ;
F_55 ( V_15 ) ;
F_151 ( V_21 , * V_15 ) ;
F_53 ( V_15 ) ;
F_54 ( V_15 , V_122 ) ;
F_55 ( V_15 ) ;
}
static void
F_152 ( T_3 * * V_15 , unsigned int V_132 ,
unsigned int V_136 )
{
long V_56 = ( long ) V_57 ;
F_42 ( V_15 , V_132 , V_59 ) ;
F_43 ( V_15 , V_136 , F_44 ( V_56 ) ) ;
F_45 ( V_15 , V_136 , F_46 ( V_56 ) , V_136 ) ;
F_47 ( V_15 , V_132 , V_132 , 22 ) ;
F_48 ( V_15 , V_132 , V_132 , 2 ) ;
F_49 ( V_15 , V_136 , V_136 , V_132 ) ;
F_42 ( V_15 , V_132 , V_60 ) ;
F_45 ( V_15 , V_136 , 0 , V_136 ) ;
F_50 ( V_15 , V_132 , V_132 , 0xffc ) ;
F_49 ( V_15 , V_136 , V_136 , V_132 ) ;
F_45 ( V_15 , V_132 , 0 , V_136 ) ;
F_59 ( V_15 ) ;
}
static void F_153 ( void )
{
T_3 * V_15 = V_218 ;
const int V_219 = V_220 - V_218 ;
struct V_20 * V_21 = V_182 ;
struct V_16 * V_17 = V_183 ;
memset ( V_218 , 0 , V_219 * sizeof( V_218 [ 0 ] ) ) ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
F_152 ( & V_15 , V_47 , V_49 ) ;
F_142 ( & V_15 , & V_17 , V_47 , V_49 , - 1 , V_221 ) ;
F_51 ( & V_15 ) ;
F_145 ( & V_15 , & V_17 , V_47 , V_49 ) ;
F_150 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 ) ;
F_154 ( & V_21 , V_15 ) ;
F_155 ( & V_15 , ( unsigned long ) V_158 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_220 )
F_56 ( L_31 ) ;
F_127 ( V_183 , V_182 ) ;
F_19 ( L_32 ,
( unsigned int ) ( V_15 - V_218 ) ) ;
F_23 ( L_33 , V_218 , V_219 ) ;
}
static void F_156 ( void )
{
T_3 * V_15 = V_222 ;
const int V_223 = V_224 - V_222 ;
struct V_20 * V_21 = V_182 ;
struct V_16 * V_17 = V_183 ;
memset ( V_222 , 0 , V_223 * sizeof( V_222 [ 0 ] ) ) ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
F_152 ( & V_15 , V_47 , V_49 ) ;
F_146 ( & V_15 , & V_17 , V_47 , V_49 , - 1 , V_225 ) ;
F_51 ( & V_15 ) ;
F_147 ( & V_15 , & V_17 , V_47 , V_49 ) ;
F_150 ( & V_15 , & V_21 , & V_17 , V_47 , V_49 ) ;
F_157 ( & V_21 , V_15 ) ;
F_155 ( & V_15 , ( unsigned long ) V_226 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_224 )
F_56 ( L_34 ) ;
F_127 ( V_183 , V_182 ) ;
F_19 ( L_35 ,
( unsigned int ) ( V_15 - V_222 ) ) ;
F_23 ( L_36 , V_222 , V_223 ) ;
}
static void F_158 ( void )
{
T_3 * V_15 = V_227 ;
const int V_228 = V_229 - V_227 ;
struct V_20 * V_21 = V_182 ;
struct V_16 * V_17 = V_183 ;
memset ( V_227 , 0 , V_228 * sizeof( V_227 [ 0 ] ) ) ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
F_152 ( & V_15 , V_47 , V_49 ) ;
F_148 ( & V_15 , & V_17 , V_47 , V_49 , - 1 , V_230 ) ;
F_51 ( & V_15 ) ;
F_147 ( & V_15 , & V_17 , V_47 , V_49 ) ;
F_149 ( & V_15 , V_47 , V_49 ) ;
F_159 ( & V_21 , V_15 ) ;
F_155 ( & V_15 , ( unsigned long ) V_226 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_229 )
F_56 ( L_37 ) ;
F_127 ( V_183 , V_182 ) ;
F_19 ( L_38 ,
( unsigned int ) ( V_15 - V_227 ) ) ;
F_23 ( L_39 , V_227 , V_228 ) ;
}
static struct V_44
F_160 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 )
{
struct V_44 V_231 = F_27 ( V_15 ) ;
#ifdef V_187
F_81 ( V_15 , V_21 , V_17 , V_231 . V_46 , V_231 . V_48 ) ;
#else
F_100 ( V_15 , V_231 . V_46 , V_231 . V_48 ) ;
#endif
#ifdef F_20
F_72 ( V_15 , V_17 , V_231 . V_46 , V_231 . V_48 , V_137 ) ;
#endif
F_39 ( V_15 , V_231 . V_46 , V_59 ) ;
F_40 ( V_15 , V_231 . V_48 , 0 , V_231 . V_48 ) ;
F_65 ( V_15 , V_231 . V_46 , V_231 . V_46 , V_141 + V_232 - V_163 ) ;
F_50 ( V_15 , V_231 . V_46 , V_231 . V_46 , ( V_165 - 1 ) << V_163 ) ;
F_35 ( V_15 , V_231 . V_48 , V_231 . V_48 , V_231 . V_46 ) ;
#ifdef F_78
F_161 ( V_21 , * V_15 ) ;
#endif
F_132 ( V_15 , V_231 . V_46 , V_231 . V_48 ) ;
if ( ! F_12 () ) {
F_58 ( V_15 ) ;
if ( V_233 ) {
F_62 ( V_15 ) ;
F_42 ( V_15 , V_231 . V_50 , V_173 ) ;
F_84 ( V_15 , V_17 , V_231 . V_50 , V_129 ) ;
F_51 ( V_15 ) ;
}
}
return V_231 ;
}
static void
F_162 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_122 ,
unsigned int V_136 )
{
F_69 ( V_15 , V_136 , V_136 , sizeof( V_170 ) ) ;
F_144 ( V_15 , V_136 , V_136 , sizeof( V_170 ) ) ;
F_104 ( V_15 , V_122 , V_136 ) ;
F_60 ( V_15 , V_21 , V_17 , V_71 ) ;
F_112 ( V_21 , * V_15 ) ;
F_38 ( V_15 ) ;
F_113 ( V_15 ) ;
#ifdef V_187
F_93 ( V_15 , V_21 , V_17 , V_122 , V_136 , V_155 ) ;
#endif
}
static void F_163 ( void )
{
T_3 * V_15 = V_218 ;
const int V_219 = V_220 - V_218 ;
struct V_20 * V_21 = V_182 ;
struct V_16 * V_17 = V_183 ;
struct V_44 V_231 ;
memset ( V_218 , 0 , V_219 * sizeof( V_218 [ 0 ] ) ) ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
if ( F_4 () ) {
unsigned int V_189 = 44 ;
F_83 ( & V_15 , V_47 , V_59 ) ;
F_83 ( & V_15 , V_49 , V_190 ) ;
F_116 ( & V_15 , V_47 , V_47 , V_49 ) ;
F_67 ( & V_15 , V_49 , V_47 , 62 ) ;
F_67 ( & V_15 , V_47 , V_47 , 12 + 1 ) ;
F_117 ( & V_15 , V_47 , V_47 , 64 + 12 + 1 - V_189 ) ;
F_118 ( & V_15 , V_47 , V_47 , V_49 ) ;
F_74 ( & V_15 , & V_17 , V_47 , V_129 ) ;
}
V_231 = F_160 ( & V_15 , & V_21 , & V_17 ) ;
F_142 ( & V_15 , & V_17 , V_231 . V_46 , V_231 . V_48 , V_231 . V_50 , V_221 ) ;
if ( F_12 () )
F_58 ( & V_15 ) ;
if ( V_29 && ! V_234 ) {
if ( F_6 () ) {
F_143 ( & V_15 , & V_17 , V_231 . V_46 , F_33 ( V_207 ) ,
V_205 ) ;
} else {
F_50 ( & V_15 , V_231 . V_50 , V_231 . V_46 , V_207 ) ;
F_80 ( & V_15 , & V_17 , V_231 . V_50 , V_205 ) ;
}
F_51 ( & V_15 ) ;
F_164 ( & V_15 ) ;
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
F_165 ( & V_15 , V_231 . V_48 , F_33 ( sizeof( V_170 ) ) , 8 ) ;
} else {
F_50 ( & V_15 , V_231 . V_50 , V_231 . V_48 , sizeof( V_170 ) ) ;
F_166 ( & V_15 , V_231 . V_50 , 8 ) ;
}
F_39 ( & V_15 , V_231 . V_50 , V_61 ) ;
F_39 ( & V_15 , V_231 . V_50 , V_135 ) ;
if ( F_6 () ) {
F_73 ( & V_15 , & V_17 , V_231 . V_50 , 1 , V_221 ) ;
F_51 ( & V_15 ) ;
F_131 ( & V_21 , V_15 ) ;
} else {
F_50 ( & V_15 , V_231 . V_50 , V_231 . V_50 , 2 ) ;
F_74 ( & V_15 , & V_17 , V_231 . V_50 , V_221 ) ;
F_51 ( & V_15 ) ;
}
F_131 ( & V_21 , V_15 ) ;
}
F_145 ( & V_15 , & V_17 , V_231 . V_46 , V_231 . V_48 ) ;
F_162 ( & V_15 , & V_21 , & V_17 , V_231 . V_46 , V_231 . V_48 ) ;
#ifdef F_20
F_119 ( & V_21 , V_15 ) ;
F_132 ( & V_15 , V_231 . V_46 , V_231 . V_48 ) ;
F_142 ( & V_15 , & V_17 , V_231 . V_46 , V_231 . V_48 , V_231 . V_50 , V_221 ) ;
F_58 ( & V_15 ) ;
if ( V_29 && ! V_234 ) {
if ( F_6 () ) {
F_143 ( & V_15 , & V_17 , V_231 . V_46 , F_33 ( V_207 ) ,
V_235 ) ;
} else {
F_50 ( & V_15 , V_231 . V_50 , V_231 . V_46 , V_207 ) ;
F_80 ( & V_15 , & V_17 , V_231 . V_50 , V_235 ) ;
}
F_51 ( & V_15 ) ;
F_164 ( & V_15 ) ;
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
F_165 ( & V_15 , V_231 . V_48 , F_33 ( sizeof( V_170 ) ) , 8 ) ;
} else {
F_50 ( & V_15 , V_231 . V_50 , V_231 . V_48 , sizeof( V_170 ) ) ;
F_166 ( & V_15 , V_231 . V_50 , 8 ) ;
}
F_39 ( & V_15 , V_231 . V_50 , V_61 ) ;
F_39 ( & V_15 , V_231 . V_50 , V_135 ) ;
if ( F_6 () ) {
F_143 ( & V_15 , & V_17 , V_231 . V_50 , 1 , V_235 ) ;
} else {
F_50 ( & V_15 , V_231 . V_50 , V_231 . V_50 , 2 ) ;
F_80 ( & V_15 , & V_17 , V_231 . V_50 , V_235 ) ;
}
if ( V_126 == 0 )
F_51 ( & V_15 ) ;
F_68 ( & V_15 , & V_17 , V_231 . V_50 , V_221 , 0 ) ;
F_167 ( & V_21 , V_15 ) ;
}
F_69 ( & V_15 , V_231 . V_46 , V_231 . V_46 , ( V_214 | V_207 ) ) ;
F_77 ( & V_15 , & V_17 , & V_21 , V_231 . V_46 , V_231 . V_48 ) ;
#endif
F_154 ( & V_21 , V_15 ) ;
F_38 ( & V_15 ) ;
#ifdef F_168
if ( ( unsigned long ) V_158 & 1 ) {
F_43 ( & V_15 , V_47 , F_44 ( ( long ) V_158 ) ) ;
F_97 ( & V_15 , V_47 , V_47 , F_46 ( ( long ) V_158 ) ) ;
F_54 ( & V_15 , V_47 ) ;
} else
#endif
F_155 ( & V_15 , ( unsigned long ) V_158 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_220 )
F_56 ( L_31 ) ;
F_127 ( V_183 , V_182 ) ;
F_19 ( L_32 ,
( unsigned int ) ( V_15 - V_218 ) ) ;
F_23 ( L_40 , V_218 , V_219 ) ;
}
static void F_169 ( void )
{
T_3 * V_15 = V_222 ;
const int V_223 = V_224 - V_222 ;
struct V_20 * V_21 = V_182 ;
struct V_16 * V_17 = V_183 ;
struct V_44 V_231 ;
memset ( V_222 , 0 , V_223 * sizeof( V_222 [ 0 ] ) ) ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
V_231 = F_160 ( & V_15 , & V_21 , & V_17 ) ;
F_146 ( & V_15 , & V_17 , V_231 . V_46 , V_231 . V_48 , V_231 . V_50 , V_225 ) ;
if ( F_12 () )
F_58 ( & V_15 ) ;
F_147 ( & V_15 , & V_17 , V_231 . V_46 , V_231 . V_48 ) ;
F_162 ( & V_15 , & V_21 , & V_17 , V_231 . V_46 , V_231 . V_48 ) ;
#ifdef F_20
F_119 ( & V_21 , V_15 ) ;
F_132 ( & V_15 , V_231 . V_46 , V_231 . V_48 ) ;
F_146 ( & V_15 , & V_17 , V_231 . V_46 , V_231 . V_48 , V_231 . V_50 , V_225 ) ;
F_58 ( & V_15 ) ;
F_69 ( & V_15 , V_231 . V_46 , V_231 . V_46 ,
V_214 | V_216 | V_207 | V_208 ) ;
F_77 ( & V_15 , & V_17 , & V_21 , V_231 . V_46 , V_231 . V_48 ) ;
#endif
F_157 ( & V_21 , V_15 ) ;
F_38 ( & V_15 ) ;
#ifdef F_168
if ( ( unsigned long ) V_226 & 1 ) {
F_43 ( & V_15 , V_47 , F_44 ( ( long ) V_226 ) ) ;
F_97 ( & V_15 , V_47 , V_47 , F_46 ( ( long ) V_226 ) ) ;
F_54 ( & V_15 , V_47 ) ;
} else
#endif
F_155 ( & V_15 , ( unsigned long ) V_226 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_224 )
F_56 ( L_34 ) ;
F_127 ( V_183 , V_182 ) ;
F_19 ( L_35 ,
( unsigned int ) ( V_15 - V_222 ) ) ;
F_23 ( L_41 , V_222 , V_223 ) ;
}
static void F_170 ( void )
{
T_3 * V_15 = V_227 ;
const int V_228 = V_229 - V_227 ;
struct V_20 * V_21 = V_182 ;
struct V_16 * V_17 = V_183 ;
struct V_44 V_231 ;
memset ( V_227 , 0 , V_228 * sizeof( V_227 [ 0 ] ) ) ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
V_231 = F_160 ( & V_15 , & V_21 , & V_17 ) ;
F_148 ( & V_15 , & V_17 , V_231 . V_46 , V_231 . V_48 , V_231 . V_50 , V_230 ) ;
if ( F_12 () )
F_58 ( & V_15 ) ;
F_147 ( & V_15 , & V_17 , V_231 . V_46 , V_231 . V_48 ) ;
F_162 ( & V_15 , & V_21 , & V_17 , V_231 . V_46 , V_231 . V_48 ) ;
#ifdef F_20
F_119 ( & V_21 , V_15 ) ;
F_132 ( & V_15 , V_231 . V_46 , V_231 . V_48 ) ;
F_148 ( & V_15 , & V_17 , V_231 . V_46 , V_231 . V_48 , V_231 . V_50 , V_230 ) ;
F_58 ( & V_15 ) ;
F_69 ( & V_15 , V_231 . V_46 , V_231 . V_46 ,
V_214 | V_216 | V_207 | V_208 ) ;
F_77 ( & V_15 , & V_17 , & V_21 , V_231 . V_46 , V_231 . V_48 ) ;
#endif
F_159 ( & V_21 , V_15 ) ;
F_38 ( & V_15 ) ;
#ifdef F_168
if ( ( unsigned long ) V_226 & 1 ) {
F_43 ( & V_15 , V_47 , F_44 ( ( long ) V_226 ) ) ;
F_97 ( & V_15 , V_47 , V_47 , F_46 ( ( long ) V_226 ) ) ;
F_54 ( & V_15 , V_47 ) ;
} else
#endif
F_155 ( & V_15 , ( unsigned long ) V_226 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_229 )
F_56 ( L_37 ) ;
F_127 ( V_183 , V_182 ) ;
F_19 ( L_38 ,
( unsigned int ) ( V_15 - V_227 ) ) ;
F_23 ( L_42 , V_227 , V_228 ) ;
}
static void F_171 ( void )
{
F_57 ( ( unsigned long ) V_218 ,
( unsigned long ) V_220 ) ;
F_57 ( ( unsigned long ) V_222 ,
( unsigned long ) V_224 ) ;
F_57 ( ( unsigned long ) V_227 ,
( unsigned long ) V_229 ) ;
F_57 ( ( unsigned long ) V_204 ,
( unsigned long ) V_203 ) ;
}
static void F_172 ( void )
{
unsigned long V_236 ;
unsigned int V_237 ;
const int V_238 = 2 * sizeof( unsigned long ) ;
V_236 = F_173 () ;
F_19 ( L_43 ,
V_238 , V_236 ,
( V_236 & V_239 ) >> V_240 ,
( V_236 & V_241 ) >> V_242 ,
( V_236 & V_243 ) >> V_244 ,
( V_236 & V_245 ) >> V_246 ,
( V_236 & V_247 ) >> V_248 ) ;
V_236 = F_174 () ;
F_19 ( L_44 ,
V_238 , V_236 ,
( V_236 & V_249 ) >> V_250 ,
( V_236 & V_251 ) >> V_252 ,
( V_236 & V_253 ) >> V_254 ,
( V_236 & V_255 ) >> V_256 ,
( V_236 & V_257 ) >> V_258 ) ;
V_237 = F_175 () ;
F_19 ( L_45 ,
V_237 ,
( V_237 & V_259 ) >> V_260 ,
( V_237 & V_261 ) >> V_262 ,
( V_237 & V_263 ) >> V_264 ,
( V_237 & V_265 ) >> V_266 ) ;
}
static void F_176 ( void )
{
unsigned long V_267 , V_268 , V_269 ;
unsigned int V_236 ;
V_267 = F_173 () ;
V_267 &= ~ V_239 ;
V_267 |= V_139 << V_240 ;
V_267 &= ~ V_245 ;
V_267 |= V_141 << V_246 ;
if ( V_270 >= 3 ) {
V_267 &= ~ V_243 ;
V_267 |= V_146 << V_244 ;
}
V_269 = V_31 << V_248 ;
V_267 |= V_269 ;
F_177 ( V_267 ) ;
F_178 () ;
V_267 = F_173 () ;
if ( ( ( V_267 & V_247 ) << V_248 )
!= V_269 ) {
F_179 ( L_46 ,
V_269 ) ;
V_11 . V_271 &= ~ V_272 ;
return;
}
V_268 = F_33 ( V_145 ) << V_250 ;
V_268 |= F_33 ( V_165 ) << V_256 ;
if ( V_270 >= 3 )
V_268 |= F_33 ( V_147 ) << V_254 ;
if ( F_105 ( V_273 ) || ( F_180 () & V_274 ) )
V_268 |= 1 ;
F_181 ( V_268 ) ;
F_178 () ;
V_236 = 1 << V_260 ;
F_182 ( V_236 ) ;
F_183 ( L_47 ) ;
F_172 () ;
}
static void F_184 ( void )
{
#ifdef F_106
unsigned int V_275 ;
if ( V_2 ) {
F_183 ( L_48 ) ;
return;
}
V_275 = F_180 () ;
F_185 ( V_275 | V_274 ) ;
F_178 () ;
V_275 = F_180 () ;
if ( V_275 & V_274 )
F_183 ( L_49 ) ;
else
F_56 ( L_50 ) ;
#endif
}
static void F_186 ( void )
{
unsigned long V_276 ;
unsigned V_277 , V_278 ;
if ( ! V_29 || ! V_119 ) {
return;
}
F_187 ( ~ 0ul ) ;
F_178 () ;
V_276 = F_188 () ;
V_276 &= ~ ( ( 1 << V_279 ) - 1 ) ;
V_276 &= ~ ( V_280 | V_281 ) ;
V_277 = F_189 ( V_276 ) + 6 ;
V_278 = F_190 ( int , ( int ) V_282 - V_277 , 0 ) ;
V_278 -= F_191 ( unsigned , V_278 , 2 ) ;
if ( V_278 >= F_33 ( V_119 ) )
V_120 = true ;
F_19 ( L_51 , V_278 ) ;
}
void F_192 ( void )
{
static int V_283 = 0 ;
F_17 () ;
F_186 () ;
#ifdef V_187
V_138 = V_11 . V_284 > ( V_139 + V_140 + V_141 - 3 ) ;
#endif
switch ( F_7 () ) {
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
#ifndef F_82
if ( V_292 )
F_41 () ;
if ( ! V_283 ) {
if ( ! V_292 )
F_41 () ;
F_128 () ;
F_153 () ;
F_156 () ;
F_158 () ;
F_171 () ;
V_283 ++ ;
}
#else
F_56 ( L_52 ) ;
#endif
break;
case V_293 :
case V_294 :
F_56 ( L_53 ) ;
break;
case V_295 :
F_56 ( L_54 ) ;
break;
default:
if ( ! V_283 ) {
V_45 = F_25 () ;
F_128 () ;
F_163 () ;
F_169 () ;
F_170 () ;
if ( ! V_292 )
F_114 () ;
F_171 () ;
V_283 ++ ;
}
if ( V_292 )
F_114 () ;
if ( V_296 )
F_184 () ;
if ( V_233 )
F_176 () ;
}
}
