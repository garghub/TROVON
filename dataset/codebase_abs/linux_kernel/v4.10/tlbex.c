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
#endif
#ifdef F_21
if ( V_28 )
F_18 ( L_10 , F_21 ) ;
#endif
F_18 ( L_11 , V_29 ) ;
F_18 ( L_12 , V_30 ) ;
F_18 ( L_13 , V_31 ) ;
F_18 ( L_14 , V_32 ) ;
F_19 ( L_3 ) ;
}
static inline void F_22 ( const char * V_33 , const T_3 * V_34 , int V_35 )
{
int V_9 ;
F_19 ( L_15 , V_33 ) ;
F_19 ( L_16 ) ;
F_19 ( L_17 ) ;
for ( V_9 = 0 ; V_9 < V_35 ; V_9 ++ )
F_19 ( L_18 , V_34 [ V_9 ] , & V_34 [ V_9 ] ) ;
F_19 ( L_19 ) ;
F_19 ( L_20 , V_33 ) ;
}
static inline int T_2 F_23 ( void )
{
switch ( F_7 () ) {
case V_36 :
case V_37 :
return 22 ;
default:
return 31 ;
}
}
static int F_24 ( void )
{
int V_17 ;
unsigned int V_38 = V_39 [ 0 ] . V_40 & ~ V_41 ;
V_17 = F_25 ( V_38 ) ;
if ( V_17 == 0 )
return - 1 ;
V_17 -- ;
V_41 |= ( 1 << V_17 ) ;
return V_17 ;
}
static struct V_42 F_26 ( T_3 * * V_15 )
{
struct V_42 V_17 ;
if ( V_43 >= 0 ) {
F_27 ( V_15 , 1 , F_23 () , V_43 ) ;
V_17 . V_44 = V_45 ;
V_17 . V_46 = V_47 ;
V_17 . V_48 = 1 ;
return V_17 ;
}
if ( F_28 () > 1 ) {
F_29 ( V_15 , V_45 , V_49 ) ;
F_30 ( V_15 , V_45 , V_45 , V_50 ) ;
F_31 ( V_15 , V_45 , V_45 , F_32 ( sizeof( struct V_51 ) ) ) ;
F_33 ( V_15 , V_47 , ( long ) & V_52 ) ;
F_34 ( V_15 , V_45 , V_45 , V_47 ) ;
} else {
F_33 ( V_15 , V_45 , ( long ) & V_52 ) ;
}
F_35 ( V_15 , 1 , F_36 ( struct V_51 , V_38 ) , V_45 ) ;
F_35 ( V_15 , 2 , F_36 ( struct V_51 , V_53 ) , V_45 ) ;
V_17 . V_44 = V_47 ;
V_17 . V_46 = 1 ;
V_17 . V_48 = 2 ;
return V_17 ;
}
static void F_37 ( T_3 * * V_15 )
{
if ( V_43 >= 0 ) {
F_38 ( V_15 , 1 , F_23 () , V_43 ) ;
return;
}
F_39 ( V_15 , 1 , F_36 ( struct V_51 , V_38 ) , V_45 ) ;
F_39 ( V_15 , 2 , F_36 ( struct V_51 , V_53 ) , V_45 ) ;
}
static void F_40 ( void )
{
long V_54 = ( long ) V_55 ;
T_3 * V_15 ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
V_15 = V_56 ;
F_41 ( & V_15 , V_45 , V_57 ) ;
F_42 ( & V_15 , V_47 , F_43 ( V_54 ) ) ;
F_44 ( & V_15 , V_47 , F_45 ( V_54 ) , V_47 ) ;
F_46 ( & V_15 , V_45 , V_45 , 22 ) ;
F_47 ( & V_15 , V_45 , V_45 , 2 ) ;
F_48 ( & V_15 , V_47 , V_47 , V_45 ) ;
F_41 ( & V_15 , V_45 , V_58 ) ;
F_44 ( & V_15 , V_47 , 0 , V_47 ) ;
F_49 ( & V_15 , V_45 , V_45 , 0xffc ) ;
F_48 ( & V_15 , V_47 , V_47 , V_45 ) ;
F_44 ( & V_15 , V_45 , 0 , V_47 ) ;
F_50 ( & V_15 ) ;
F_51 ( & V_15 , V_45 , V_59 ) ;
F_41 ( & V_15 , V_47 , V_60 ) ;
F_52 ( & V_15 ) ;
F_53 ( & V_15 , V_47 ) ;
F_54 ( & V_15 ) ;
if ( V_15 > V_56 + 32 )
F_55 ( L_21 ) ;
F_19 ( L_22 ,
( unsigned int ) ( V_15 - V_56 ) ) ;
memcpy ( ( void * ) V_61 , V_56 , 0x80 ) ;
F_56 ( V_61 , V_61 + 0x80 ) ;
F_22 ( L_23 , ( T_3 * ) V_61 , 32 ) ;
}
static void T_2 F_57 ( T_3 * * V_15 )
{
switch ( F_7 () ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
F_50 ( V_15 ) ;
F_58 ( V_15 ) ;
break;
default:
F_58 ( V_15 ) ;
break;
}
}
static void F_59 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 ,
enum V_66 V_67 )
{
void (* F_60)( T_3 * * ) = NULL ;
switch ( V_67 ) {
case V_68 : F_60 = F_52 ; break;
case V_69 : F_60 = V_70 ; break;
}
if ( V_71 ) {
if ( V_72 )
F_61 ( V_15 ) ;
F_60 ( V_15 ) ;
return;
}
switch ( F_7 () ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
F_13 ( V_15 , V_17 , V_79 ) ;
F_60 ( V_15 ) ;
F_15 ( V_21 , V_15 , V_79 ) ;
V_79 ++ ;
F_50 ( V_15 ) ;
break;
case V_62 :
case V_63 :
F_50 ( V_15 ) ;
F_60 ( V_15 ) ;
F_50 ( V_15 ) ;
break;
case V_64 :
case V_65 :
F_50 ( V_15 ) ;
F_50 ( V_15 ) ;
F_60 ( V_15 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_37 :
F_50 ( V_15 ) ;
F_60 ( V_15 ) ;
break;
case V_84 :
case V_85 :
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
if ( F_12 () )
F_50 ( V_15 ) ;
case V_105 :
F_60 ( V_15 ) ;
break;
case V_106 :
F_50 ( V_15 ) ;
F_50 ( V_15 ) ;
F_50 ( V_15 ) ;
F_50 ( V_15 ) ;
F_60 ( V_15 ) ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
F_50 ( V_15 ) ;
F_50 ( V_15 ) ;
F_60 ( V_15 ) ;
F_50 ( V_15 ) ;
F_50 ( V_15 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
F_50 ( V_15 ) ;
F_50 ( V_15 ) ;
F_60 ( V_15 ) ;
break;
case V_115 :
F_60 ( V_15 ) ;
F_50 ( V_15 ) ;
break;
default:
F_55 ( L_24 ,
F_7 () ) ;
break;
}
}
static T_2 void F_62 ( T_3 * * V_15 ,
unsigned int V_116 )
{
if ( V_29 == 0 ) {
return;
}
if ( V_28 && V_117 ) {
if ( V_118 ) {
F_63 ( V_15 , V_116 , V_116 , F_32 ( V_119 ) ) ;
} else {
F_64 ( V_15 , V_116 , V_116 , F_32 ( V_117 ) ) ;
F_63 ( V_15 , V_116 , V_116 ,
F_32 ( V_119 ) - F_32 ( V_117 ) ) ;
}
} else {
#ifdef F_65
F_66 ( V_15 , V_116 , V_116 , F_32 ( V_119 ) ) ;
#else
F_64 ( V_15 , V_116 , V_116 , F_32 ( V_119 ) ) ;
#endif
}
}
static void F_67 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_120 , enum V_121 V_122 ,
int V_123 )
{
if ( V_123 ) {
if ( V_124 >> 16 ) {
F_42 ( V_15 , V_120 , V_124 >> 16 ) ;
F_68 ( V_15 , V_120 , V_120 , V_124 & 0xffff ) ;
F_51 ( V_15 , V_120 , V_125 ) ;
F_69 ( V_15 , V_17 , V_122 ) ;
} else if ( V_124 ) {
F_68 ( V_15 , V_120 , 0 , V_124 ) ;
F_51 ( V_15 , V_120 , V_125 ) ;
F_69 ( V_15 , V_17 , V_122 ) ;
} else {
F_51 ( V_15 , 0 , V_125 ) ;
F_69 ( V_15 , V_17 , V_122 ) ;
}
if ( V_43 >= 0 )
F_38 ( V_15 , 1 , F_23 () , V_43 ) ;
else
F_39 ( V_15 , 1 , F_10 ( 0 ) , 0 ) ;
} else {
if ( V_124 >> 16 ) {
F_42 ( V_15 , V_120 , V_124 >> 16 ) ;
F_68 ( V_15 , V_120 , V_120 , V_124 & 0xffff ) ;
F_69 ( V_15 , V_17 , V_122 ) ;
F_51 ( V_15 , V_120 , V_125 ) ;
} else if ( V_124 ) {
F_68 ( V_15 , V_120 , 0 , V_124 ) ;
F_69 ( V_15 , V_17 , V_122 ) ;
F_51 ( V_15 , V_120 , V_125 ) ;
} else {
F_69 ( V_15 , V_17 , V_122 ) ;
F_51 ( V_15 , 0 , V_125 ) ;
}
}
}
static void F_70 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 ,
unsigned int V_120 ,
enum V_66 V_67 ,
int V_123 )
{
F_42 ( V_15 , V_120 , V_126 >> 16 ) ;
F_68 ( V_15 , V_120 , V_120 , V_126 & 0xffff ) ;
F_51 ( V_15 , V_120 , V_125 ) ;
F_59 ( V_15 , V_21 , V_17 , V_67 ) ;
F_67 ( V_15 , V_17 , V_120 , V_127 , V_123 ) ;
}
static void
F_71 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_120 ,
unsigned int V_128 , int V_122 )
{
F_39 ( V_15 , V_120 , 0 , V_128 ) ;
if ( F_6 () ) {
F_72 ( V_15 , V_17 , V_120 , F_32 ( V_129 ) , V_122 ) ;
} else {
F_49 ( V_15 , V_120 , V_120 , V_129 ) ;
F_73 ( V_15 , V_17 , V_120 , V_122 ) ;
}
}
static void F_74 ( T_3 * * V_15 , unsigned int V_130 ,
unsigned int V_120 )
{
int V_131 ;
V_131 = ( V_132 >> 7 ) < 0x10000 ;
if ( ! V_131 )
F_42 ( V_15 , V_120 , V_132 >> ( 7 + 16 ) ) ;
F_62 ( V_15 , V_130 ) ;
F_27 ( V_15 , V_130 , V_59 ) ;
if ( V_131 )
F_75 ( V_15 , V_130 , V_130 , V_132 >> 7 ) ;
else
F_34 ( V_15 , V_130 , V_130 , V_120 ) ;
F_27 ( V_15 , V_130 , V_133 ) ;
}
static void F_76 ( T_3 * * V_15 , struct V_16 * * V_17 ,
struct V_20 * * V_21 ,
unsigned int V_130 ,
unsigned int V_134 )
{
#ifdef F_77
F_78 ( V_15 , V_130 , 0 , V_134 ) ;
F_79 ( V_15 , V_17 , V_130 , V_135 ) ;
F_39 ( V_15 , V_130 , 0 , V_134 ) ;
#else
F_35 ( V_15 , V_130 , 0 , V_134 ) ;
#endif
F_74 ( V_15 , V_130 , V_134 ) ;
F_70 ( V_15 , V_21 , V_17 , V_130 , V_69 , 0 ) ;
}
static void
F_80 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_120 , unsigned int V_134 )
{
#ifndef F_81
long V_54 = ( long ) V_55 ;
#endif
F_82 ( V_15 , V_120 , V_57 ) ;
if ( V_136 ) {
F_66 ( V_15 , V_134 , V_120 , V_137 + V_138 + V_139 - 3 ) ;
F_73 ( V_15 , V_17 , V_134 , V_140 ) ;
} else {
F_83 ( V_15 , V_17 , V_120 , V_140 ) ;
}
if ( V_141 != - 1 ) {
if ( V_142 )
F_38 ( V_15 , V_134 , V_143 ) ;
else
F_38 ( V_15 , V_134 , F_23 () , V_141 ) ;
} else {
#if F_84 ( F_81 )
F_38 ( V_15 , V_134 , V_58 ) ;
F_85 ( V_15 , V_134 , 0 , 0 , 23 ) ;
F_68 ( V_15 , V_134 , V_134 , 0x540 ) ;
F_86 ( V_15 , V_134 , V_134 , 11 ) ;
#elif F_84 ( F_77 )
F_29 ( V_15 , V_134 , V_49 ) ;
F_66 ( V_15 , V_134 , V_134 , V_144 ) ;
F_87 ( V_15 , V_120 , V_54 ) ;
F_88 ( V_15 , V_134 , V_134 , V_120 ) ;
F_82 ( V_15 , V_120 , V_57 ) ;
F_89 ( V_15 , V_134 , F_45 ( V_54 ) , V_134 ) ;
#else
F_87 ( V_15 , V_134 , V_54 ) ;
F_89 ( V_15 , V_134 , F_45 ( V_54 ) , V_134 ) ;
#endif
}
F_90 ( V_21 , * V_15 ) ;
F_66 ( V_15 , V_120 , V_120 , V_137 - 3 ) ;
F_49 ( V_15 , V_120 , V_120 , ( V_145 - 1 ) << 3 ) ;
F_88 ( V_15 , V_134 , V_134 , V_120 ) ;
#ifndef F_91
F_82 ( V_15 , V_120 , V_57 ) ;
F_89 ( V_15 , V_134 , 0 , V_134 ) ;
F_66 ( V_15 , V_120 , V_120 , V_146 - 3 ) ;
F_49 ( V_15 , V_120 , V_120 , ( V_147 - 1 ) << 3 ) ;
F_88 ( V_15 , V_134 , V_134 , V_120 ) ;
#endif
}
static void
F_92 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_148 , unsigned int V_134 ,
enum V_149 V_150 )
{
long V_151 = ( long ) V_152 ;
int V_153 ;
int V_154 = 0 ;
V_153 = F_93 ( V_151 ) && ! F_45 ( V_151 ) ;
F_94 ( V_21 , * V_15 ) ;
if ( V_150 != V_155 && V_136 ) {
if ( V_153 ) {
F_83 ( V_15 , V_17 , V_148 , V_156 ) ;
F_42 ( V_15 , V_134 , F_43 ( V_151 ) ) ;
V_154 = 1 ;
} else {
F_95 ( V_15 , V_17 , V_148 , V_157 ) ;
}
}
if ( ! V_154 ) {
if ( V_153 ) {
F_69 ( V_15 , V_17 , V_156 ) ;
F_42 ( V_15 , V_134 , F_43 ( V_151 ) ) ;
} else {
F_87 ( V_15 , V_134 , V_151 ) ;
F_69 ( V_15 , V_17 , V_156 ) ;
if ( F_93 ( V_151 ) )
F_96 ( V_15 , V_134 , V_134 , F_45 ( V_151 ) ) ;
else
F_97 ( V_15 , V_134 , V_134 , F_45 ( V_151 ) ) ;
}
}
if ( V_150 != V_155 && V_136 ) {
F_98 ( V_21 , * V_15 ) ;
F_33 ( V_15 , V_134 , ( unsigned long ) V_158 ) ;
F_53 ( V_15 , V_134 ) ;
if ( V_150 == V_159 ) {
if ( V_43 >= 0 )
F_38 ( V_15 , 1 , F_23 () , V_43 ) ;
else
F_39 ( V_15 , 1 , F_10 ( 0 ) , 0 ) ;
} else {
F_50 ( V_15 ) ;
}
}
}
static void T_2
F_99 ( T_3 * * V_15 , unsigned int V_120 , unsigned int V_134 )
{
if ( V_141 != - 1 ) {
F_41 ( V_15 , V_134 , F_23 () , V_141 ) ;
F_41 ( V_15 , V_120 , V_57 ) ;
} else {
long V_54 = ( long ) V_55 ;
#ifdef F_77
F_41 ( V_15 , V_134 , V_49 ) ;
F_87 ( V_15 , V_120 , V_54 ) ;
F_46 ( V_15 , V_134 , V_134 , V_144 ) ;
F_48 ( V_15 , V_134 , V_120 , V_134 ) ;
#else
F_87 ( V_15 , V_134 , V_54 ) ;
#endif
F_41 ( V_15 , V_120 , V_57 ) ;
F_44 ( V_15 , V_134 , F_45 ( V_54 ) , V_134 ) ;
}
F_46 ( V_15 , V_120 , V_120 , V_137 ) ;
F_47 ( V_15 , V_120 , V_120 , V_160 ) ;
F_48 ( V_15 , V_134 , V_134 , V_120 ) ;
}
static void F_100 ( T_3 * * V_15 , unsigned int V_161 )
{
unsigned int V_162 = 4 - ( V_163 + 1 ) + V_139 - 12 ;
unsigned int V_164 = ( V_165 / 2 - 1 ) << ( V_163 + 1 ) ;
switch ( F_7 () ) {
case V_166 :
case V_107 :
case V_108 :
case V_109 :
case V_112 :
case V_110 :
case V_111 :
case V_113 :
V_162 += 2 ;
break;
default:
break;
}
if ( V_162 )
F_64 ( V_15 , V_161 , V_161 , V_162 ) ;
F_49 ( V_15 , V_161 , V_161 , V_164 ) ;
}
static void F_101 ( T_3 * * V_15 , unsigned int V_120 , unsigned int V_134 )
{
switch ( F_7 () ) {
case V_65 :
F_39 ( V_15 , V_134 , 0 , V_134 ) ;
F_102 ( V_15 , V_120 ) ;
break;
default:
F_102 ( V_15 , V_120 ) ;
F_39 ( V_15 , V_134 , 0 , V_134 ) ;
break;
}
F_100 ( V_15 , V_120 ) ;
F_34 ( V_15 , V_134 , V_134 , V_120 ) ;
}
static void F_103 ( T_3 * * V_15 , unsigned int V_120 , unsigned int V_167 )
{
int V_168 = 0 ;
int V_169 = sizeof( V_170 ) ;
#if F_84 ( V_171 ) && F_84 ( F_65 )
V_168 += F_36 ( V_170 , V_172 ) ;
V_169 += F_36 ( V_170 , V_172 ) ;
#endif
if ( F_104 ( V_173 ) ) {
F_44 ( V_15 , V_120 , V_168 , V_167 ) ;
F_63 ( V_15 , V_120 , V_120 , F_32 ( V_119 ) ) ;
F_27 ( V_15 , V_120 , V_59 ) ;
if ( V_174 && ! V_2 ) {
F_44 ( V_15 , V_120 , 0 , V_167 ) ;
F_105 ( V_15 , V_120 , V_120 , 0 , 24 ) ;
F_106 ( V_15 , V_120 , V_59 ) ;
}
F_44 ( V_15 , V_120 , V_169 , V_167 ) ;
F_63 ( V_15 , V_120 , V_120 , F_32 ( V_119 ) ) ;
F_27 ( V_15 , V_120 , V_133 ) ;
if ( V_174 && ! V_2 ) {
F_44 ( V_15 , V_120 , sizeof( V_170 ) , V_167 ) ;
F_105 ( V_15 , V_120 , V_120 , 0 , 24 ) ;
F_106 ( V_15 , V_120 , V_133 ) ;
}
return;
}
F_39 ( V_15 , V_120 , V_168 , V_167 ) ;
F_39 ( V_15 , V_167 , V_169 , V_167 ) ;
if ( F_2 () )
F_57 ( V_15 ) ;
F_62 ( V_15 , V_120 ) ;
if ( F_3 () )
F_27 ( V_15 , 0 , V_59 ) ;
F_27 ( V_15 , V_120 , V_59 ) ;
F_62 ( V_15 , V_167 ) ;
if ( F_2 () )
F_41 ( V_15 , V_120 , V_175 ) ;
if ( F_3 () )
F_27 ( V_15 , 0 , V_133 ) ;
F_27 ( V_15 , V_167 , V_133 ) ;
}
static struct V_176
F_107 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_120 ,
unsigned int V_134 , int V_177 )
{
struct V_176 V_178 ;
unsigned int V_179 , V_180 ;
int V_181 = 0 ;
const int V_182 = 1 ;
V_178 . V_183 = V_182 ;
V_178 . V_123 = 0 ;
V_178 . V_184 = false ;
if ( V_136 ) {
F_38 ( V_15 , V_120 , V_57 ) ;
if ( V_141 != - 1 )
F_38 ( V_15 , V_134 , F_23 () , V_141 ) ;
else
F_38 ( V_15 , V_134 , V_58 ) ;
if ( V_177 >= 0 )
F_27 ( V_15 , V_182 , F_23 () , V_177 ) ;
else
F_35 ( V_15 , V_182 , F_10 ( 0 ) , 0 ) ;
F_66 ( V_15 , V_182 , V_120 ,
V_137 + V_138 + V_139 - 3 ) ;
F_73 ( V_15 , V_17 , V_182 , V_140 ) ;
if ( V_141 == - 1 ) {
V_181 = 1 ;
F_85 ( V_15 , V_134 , 0 , 0 , 23 ) ;
}
} else {
if ( V_141 != - 1 )
F_38 ( V_15 , V_134 , F_23 () , V_141 ) ;
else
F_38 ( V_15 , V_134 , V_58 ) ;
F_38 ( V_15 , V_120 , V_57 ) ;
if ( V_177 >= 0 )
F_27 ( V_15 , V_182 , F_23 () , V_177 ) ;
else
F_35 ( V_15 , V_182 , F_10 ( 0 ) , 0 ) ;
if ( V_141 == - 1 )
F_85 ( V_15 , V_134 , 0 , 0 , 23 ) ;
F_83 ( V_15 , V_17 , V_120 , V_140 ) ;
}
if ( V_141 == - 1 ) {
V_181 = 1 ;
F_68 ( V_15 , V_134 , V_134 , 0x540 ) ;
F_86 ( V_15 , V_134 , V_134 , 11 ) ;
}
#ifdef F_91
#define F_108 scratch
#else
#define F_108 ptr
#endif
if ( ! V_181 )
F_66 ( V_15 , V_182 , V_120 , V_137 - 3 ) ;
F_90 ( V_21 , * V_15 ) ;
if ( V_181 )
F_66 ( V_15 , V_182 , V_120 , V_137 - 3 ) ;
#ifdef F_91
F_102 ( V_15 , V_120 ) ;
#endif
F_49 ( V_15 , V_182 , V_182 , ( V_145 - 1 ) << 3 ) ;
if ( F_8 () ) {
F_109 ( V_15 , F_108 , V_182 , V_134 ) ;
} else {
F_88 ( V_15 , V_134 , V_134 , V_182 ) ;
F_89 ( V_15 , F_108 , 0 , V_134 ) ;
}
#ifndef F_91
F_66 ( V_15 , V_182 , V_120 , V_146 - 3 ) ;
F_49 ( V_15 , V_182 , V_182 , ( V_147 - 1 ) << 3 ) ;
F_102 ( V_15 , V_120 ) ;
if ( F_8 () ) {
F_109 ( V_15 , V_182 , V_182 , V_134 ) ;
} else {
F_88 ( V_15 , V_134 , V_134 , V_182 ) ;
F_39 ( V_15 , V_182 , 0 , V_134 ) ;
}
#endif
F_100 ( V_15 , V_120 ) ;
#ifdef F_20
F_72 ( V_15 , V_17 , V_182 , F_32 ( V_129 ) , V_135 ) ;
if ( F_8 () )
F_50 ( V_15 ) ;
#endif
if ( F_8 () ) {
V_179 = V_134 ;
V_180 = V_120 ;
F_109 ( V_15 , V_179 , V_182 , V_120 ) ;
F_75 ( V_15 , V_120 , V_120 , sizeof( V_170 ) ) ;
F_109 ( V_15 , V_180 , V_182 , V_120 ) ;
} else {
F_34 ( V_15 , V_134 , V_182 , V_120 ) ;
V_179 = V_120 ;
V_180 = V_134 ;
F_39 ( V_15 , V_179 , 0 , V_134 ) ;
F_39 ( V_15 , V_180 , sizeof( V_170 ) , V_134 ) ;
}
if ( V_28 ) {
F_86 ( V_15 , V_179 , V_179 , F_32 ( V_119 ) ) ;
F_27 ( V_15 , V_179 , V_59 ) ;
F_86 ( V_15 , V_180 , V_180 , F_32 ( V_119 ) ) ;
} else {
F_66 ( V_15 , V_179 , V_179 , F_32 ( V_119 ) ) ;
F_27 ( V_15 , V_179 , V_59 ) ;
F_66 ( V_15 , V_180 , V_180 , F_32 ( V_119 ) ) ;
}
F_27 ( V_15 , V_180 , V_133 ) ;
if ( V_177 >= 0 ) {
F_38 ( V_15 , V_182 , F_23 () , V_177 ) ;
F_59 ( V_15 , V_21 , V_17 , V_68 ) ;
F_110 ( V_21 , * V_15 ) ;
V_178 . V_123 = 1 ;
} else if ( V_139 == 14 || V_139 == 13 ) {
F_59 ( V_15 , V_21 , V_17 , V_68 ) ;
F_110 ( V_21 , * V_15 ) ;
F_39 ( V_15 , V_182 , F_10 ( 0 ) , 0 ) ;
} else {
F_39 ( V_15 , V_182 , F_10 ( 0 ) , 0 ) ;
F_59 ( V_15 , V_21 , V_17 , V_68 ) ;
F_110 ( V_21 , * V_15 ) ;
V_178 . V_123 = 1 ;
}
F_111 ( V_15 ) ;
return V_178 ;
}
static void F_112 ( void )
{
T_3 * V_15 = V_56 ;
struct V_20 * V_21 = V_185 ;
struct V_16 * V_17 = V_186 ;
T_3 * V_187 ;
unsigned int V_188 ;
struct V_176 T_5 T_2 ;
enum V_149 T_6 T_2 ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
memset ( V_189 , 0 , sizeof( V_189 ) ) ;
if ( F_104 ( V_190 ) && ( V_43 >= 0 || F_9 () ) && F_6 () ) {
T_5 = F_107 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 ,
V_43 ) ;
T_6 = V_159 ;
} else {
T_5 . V_183 = V_45 ;
T_5 . V_123 = 0 ;
T_5 . V_184 = true ;
T_6 = V_191 ;
if ( F_4 () ) {
unsigned int V_192 = 44 ;
F_82 ( & V_15 , V_45 , V_57 ) ;
F_82 ( & V_15 , V_47 , V_193 ) ;
F_113 ( & V_15 , V_45 , V_45 , V_47 ) ;
F_66 ( & V_15 , V_47 , V_45 , 62 ) ;
F_66 ( & V_15 , V_45 , V_45 , 12 + 1 ) ;
F_114 ( & V_15 , V_45 , V_45 , 64 + 12 + 1 - V_192 ) ;
F_115 ( & V_15 , V_45 , V_45 , V_47 ) ;
F_73 ( & V_15 , & V_17 , V_45 , V_127 ) ;
}
#ifdef V_190
F_80 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 ) ;
#else
F_99 ( & V_15 , V_45 , V_47 ) ;
#endif
#ifdef F_20
F_71 ( & V_15 , & V_17 , V_45 , V_47 , V_135 ) ;
#endif
F_101 ( & V_15 , V_45 , V_47 ) ;
F_103 ( & V_15 , V_45 , V_47 ) ;
F_59 ( & V_15 , & V_21 , & V_17 , V_68 ) ;
F_110 ( & V_21 , V_15 ) ;
F_111 ( & V_15 ) ;
}
#ifdef F_20
F_116 ( & V_21 , V_15 ) ;
if ( T_5 . V_184 )
F_39 ( & V_15 , T_5 . V_183 , 0 , V_47 ) ;
F_74 ( & V_15 , T_5 . V_183 , V_47 ) ;
F_70 ( & V_15 , & V_21 , & V_17 , V_45 , V_68 ,
T_5 . V_123 ) ;
#endif
#ifdef V_190
F_92 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 , T_6 ) ;
#endif
switch ( F_117 () ) {
default:
if ( sizeof( long ) == 4 ) {
case V_102 :
if ( ( V_15 - V_56 ) > 64 )
F_55 ( L_21 ) ;
V_187 = V_189 ;
F_118 ( V_186 , V_185 , V_56 , V_15 , V_187 ) ;
V_188 = V_15 - V_56 ;
break;
} else {
if ( ( ( V_15 - V_56 ) > ( V_194 * 2 ) - 1 )
|| ( ( ( V_15 - V_56 ) > ( V_194 * 2 ) - 3 )
&& F_119 ( V_186 ,
V_56 + V_194 - 3 ) ) )
F_55 ( L_21 ) ;
V_187 = V_189 + V_194 ;
if ( ( V_15 - V_56 ) <= V_194 ) {
F_118 ( V_186 , V_185 , V_56 , V_15 , V_187 ) ;
V_188 = V_15 - V_56 ;
} else {
#ifdef F_20
const enum V_121 V_195 = V_135 ;
#else
const enum V_121 V_195 = V_140 ;
#endif
T_3 * V_196 ;
int V_197 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_120 ( V_185 ) && V_185 [ V_9 ] . V_198 != V_195 ; V_9 ++ )
;
F_121 ( V_9 == F_120 ( V_185 ) ) ;
V_196 = V_185 [ V_9 ] . V_199 ;
if ( V_196 > V_56 + V_194 ||
V_196 < V_15 - V_194 )
V_197 = 1 ;
if ( V_197 ) {
V_196 = V_56 + V_194 - 2 ;
if ( F_119 ( V_186 , V_196 - 1 ) )
V_196 -- ;
}
F_118 ( V_186 , V_185 , V_56 , V_196 , V_187 ) ;
V_187 += V_196 - V_56 ;
if ( V_197 ) {
F_122 ( & V_21 , V_189 ) ;
F_69 ( & V_187 , & V_17 , V_200 ) ;
if ( F_119 ( V_186 , V_196 ) )
F_50 ( & V_187 ) ;
else {
F_118 ( V_186 , V_185 ,
V_196 , V_196 + 1 , V_187 ) ;
F_123 ( V_185 , V_187 , V_187 + 1 , - 1 ) ;
V_187 ++ ;
V_196 ++ ;
}
}
F_118 ( V_186 , V_185 , V_196 , V_15 , V_189 ) ;
V_188 = ( V_187 - ( V_189 + V_194 ) ) +
( V_15 - V_196 ) ;
}
}
break;
}
F_124 ( V_186 , V_185 ) ;
F_19 ( L_22 ,
V_188 ) ;
memcpy ( ( void * ) V_61 , V_189 , 0x100 ) ;
F_56 ( V_61 , V_61 + 0x100 ) ;
F_22 ( L_25 , ( T_3 * ) V_61 , 64 ) ;
}
static void F_125 ( void )
{
unsigned long V_201 , V_202 ;
#ifndef F_91
unsigned long V_203 , V_204 ;
#endif
unsigned long V_205 , V_206 ;
unsigned long V_207 , V_208 ;
#ifdef F_20
unsigned long V_209 ;
V_209 = F_32 ( V_129 ) ;
#endif
V_201 = V_137 ;
#ifndef F_91
V_202 = V_137 - V_146 + V_138 ;
V_203 = V_146 ;
V_204 = V_146 - V_139 ;
#else
V_202 = V_137 - V_139 + V_138 ;
#endif
V_205 = V_139 ;
V_206 = V_139 - 3 ;
V_207 = F_32 ( V_119 ) ;
V_208 = 0 ;
#ifndef F_91
F_126 ( V_201 << 24 | V_203 << 12 | V_205 << 6 | V_207 ) ;
F_127 ( 1 << 30 | V_202 << 24 | V_204 << 12 | V_206 << 6 | V_208 ) ;
#else
F_126 ( V_201 << 24 | V_205 << 6 | V_207 ) ;
F_127 ( 1 << 30 | V_202 << 24 | V_206 << 6 | V_208 ) ;
#endif
#ifdef F_20
F_128 ( 1 << 6 | V_209 ) ;
#endif
F_129 ( V_152 ) ;
V_41 |= ( 1 << 7 ) ;
}
static void F_130 ( void )
{
T_3 * V_15 = V_56 ;
struct V_20 * V_21 = V_185 ;
struct V_16 * V_17 = V_186 ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
if ( V_136 ) {
F_82 ( & V_15 , V_45 , V_57 ) ;
F_66 ( & V_15 , V_47 , V_45 , V_137 + V_138 + V_139 - 3 ) ;
F_79 ( & V_15 , & V_17 , V_47 , V_140 ) ;
F_50 ( & V_15 ) ;
F_95 ( & V_15 , & V_17 , V_45 , V_157 ) ;
F_50 ( & V_15 ) ;
F_94 ( & V_21 , V_15 ) ;
}
F_82 ( & V_15 , V_47 , V_210 ) ;
F_131 ( & V_15 , V_45 , V_47 , 3 ) ;
#ifndef F_91
F_131 ( & V_15 , V_47 , V_45 , 1 ) ;
#endif
F_132 ( & V_15 , V_47 , 0 ) ;
F_132 ( & V_15 , V_47 , 1 ) ;
F_52 ( & V_15 ) ;
if ( V_124 >> 16 ) {
F_42 ( & V_15 , V_45 , V_124 >> 16 ) ;
F_68 ( & V_15 , V_45 , V_45 , V_124 & 0xffff ) ;
F_51 ( & V_15 , V_45 , V_125 ) ;
} else if ( V_124 ) {
F_68 ( & V_15 , V_45 , 0 , V_124 ) ;
F_51 ( & V_15 , V_45 , V_125 ) ;
} else {
F_51 ( & V_15 , 0 , V_125 ) ;
}
F_111 ( & V_15 ) ;
if ( V_136 ) {
F_98 ( & V_21 , V_15 ) ;
F_33 ( & V_15 , V_47 , ( unsigned long ) V_158 ) ;
F_53 ( & V_15 , V_47 ) ;
F_50 ( & V_15 ) ;
}
F_124 ( V_186 , V_185 ) ;
memcpy ( ( void * ) ( V_61 + 0x80 ) , V_56 , 0x80 ) ;
F_56 ( V_61 + 0x80 , V_61 + 0x100 ) ;
F_22 ( L_26 , ( T_3 * ) ( V_61 + 0x80 ) , 32 ) ;
}
static void F_133 ( void )
{
const int V_211 = 4 ;
const int T_2 V_212 = 5 ;
const int T_2 V_213 = 6 ;
T_3 * V_15 = V_214 ;
const int V_215 =
V_216 - V_214 ;
#ifndef F_81
long V_54 = ( long ) V_55 ;
#endif
memset ( V_217 , 0 , V_215 *
sizeof( V_217 [ 0 ] ) ) ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
V_141 = F_24 () ;
#ifdef F_81
if ( V_141 == - 1 ) {
struct V_20 * V_21 = V_185 ;
struct V_16 * V_17 = V_186 ;
F_134 ( & V_15 , V_212 , V_211 , 29 ) ;
F_75 ( & V_15 , V_212 , V_212 , 4 ) ;
F_73 ( & V_15 , & V_17 , V_212 , V_218 ) ;
F_50 ( & V_15 ) ;
F_135 ( & V_15 , V_211 , 0 , 29 , 64 - 29 ) ;
F_136 ( & V_21 , V_15 ) ;
F_31 ( & V_15 , V_211 , V_211 , 11 ) ;
F_53 ( & V_15 , 31 ) ;
F_27 ( & V_15 , V_211 , V_58 ) ;
} else {
F_53 ( & V_15 , 31 ) ;
if ( V_142 )
F_27 ( & V_15 , V_211 , V_143 ) ;
else
F_27 ( & V_15 , V_211 , F_23 () , V_141 ) ;
}
#else
#ifdef F_77
F_29 ( & V_15 , V_212 , V_49 ) ;
F_30 ( & V_15 , V_212 , V_212 , V_144 ) ;
F_87 ( & V_15 , V_213 , V_54 ) ;
F_34 ( & V_15 , V_213 , V_213 , V_212 ) ;
F_35 ( & V_15 , V_211 , F_45 ( V_54 ) , V_213 ) ;
#else
F_87 ( & V_15 , V_213 , V_54 ) ;
F_35 ( & V_15 , V_211 , F_45 ( V_54 ) , V_213 ) ;
#endif
F_53 ( & V_15 , 31 ) ;
if ( V_141 != - 1 )
F_27 ( & V_15 , V_211 , F_23 () , V_141 ) ;
else
F_50 ( & V_15 ) ;
#endif
if ( V_15 >= V_216 )
F_55 ( L_27 ) ;
F_124 ( V_186 , V_185 ) ;
F_19 ( L_28 ,
( unsigned int ) ( V_15 - V_217 ) ) ;
F_22 ( L_29 , V_217 ,
V_215 ) ;
}
static void
F_137 ( T_3 * * V_15 , unsigned int V_130 , unsigned int V_134 )
{
#ifdef F_77
# ifdef F_65
if ( V_219 )
F_138 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_139 ( V_15 , V_130 , 0 , V_134 ) ;
#else
# ifdef F_65
if ( V_219 )
F_89 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_39 ( V_15 , V_130 , 0 , V_134 ) ;
#endif
}
static void
F_140 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_130 , unsigned int V_134 ,
unsigned int V_150 , unsigned int V_182 )
{
unsigned int V_220 = V_150 & ( V_221 | V_222 ) ;
unsigned int V_223 = V_150 & ~ V_220 ;
if ( F_104 ( V_173 ) && ! V_219 ) {
F_42 ( V_15 , V_182 , V_223 >> 16 ) ;
F_115 ( V_15 , V_130 , V_130 , V_182 ) ;
F_121 ( V_223 & 0xffff ) ;
} else {
F_68 ( V_15 , V_130 , V_130 , V_150 ) ;
}
#ifdef F_77
# ifdef F_65
if ( V_219 )
F_141 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_78 ( V_15 , V_130 , 0 , V_134 ) ;
if ( F_5 () )
F_142 ( V_15 , V_17 , V_130 , V_224 ) ;
else
F_79 ( V_15 , V_17 , V_130 , V_224 ) ;
# ifdef F_65
if ( ! V_219 ) {
F_143 ( V_15 , V_130 , sizeof( V_170 ) / 2 , V_134 ) ;
F_68 ( V_15 , V_130 , V_130 , V_220 ) ;
F_121 ( V_220 & ~ 0xffff ) ;
F_144 ( V_15 , V_130 , sizeof( V_170 ) / 2 , V_134 ) ;
F_79 ( V_15 , V_17 , V_130 , V_224 ) ;
F_44 ( V_15 , V_130 , 0 , V_134 ) ;
} else
F_50 ( V_15 ) ;
# else
F_50 ( V_15 ) ;
# endif
#else
# ifdef F_65
if ( V_219 )
F_145 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_35 ( V_15 , V_130 , 0 , V_134 ) ;
# ifdef F_65
if ( ! V_219 ) {
F_44 ( V_15 , V_130 , sizeof( V_170 ) / 2 , V_134 ) ;
F_68 ( V_15 , V_130 , V_130 , V_220 ) ;
F_121 ( V_220 & ~ 0xffff ) ;
F_146 ( V_15 , V_130 , sizeof( V_170 ) / 2 , V_134 ) ;
F_44 ( V_15 , V_130 , 0 , V_134 ) ;
}
# endif
#endif
}
static void
F_147 ( T_3 * * V_15 , struct V_16 * * V_17 ,
int V_130 , int V_134 , int V_182 , enum V_121 V_122 )
{
int V_225 = V_182 >= 0 ? V_182 : V_130 ;
int V_226 = V_130 ;
if ( V_28 ) {
if ( F_6 () ) {
F_148 ( V_15 , V_17 , V_130 , F_32 ( V_227 ) , V_122 ) ;
F_50 ( V_15 ) ;
} else {
if ( V_22 ) {
F_46 ( V_15 , V_225 , V_226 , V_22 ) ;
V_226 = V_225 ;
}
F_49 ( V_15 , V_225 , V_226 , 1 ) ;
F_79 ( V_15 , V_17 , V_225 , V_122 ) ;
if ( V_130 == V_225 )
F_137 ( V_15 , V_130 , V_134 ) ;
}
} else {
if ( V_22 ) {
F_46 ( V_15 , V_225 , V_226 , V_22 ) ;
V_226 = V_225 ;
}
F_49 ( V_15 , V_225 , V_226 ,
( V_227 | V_228 ) >> V_22 ) ;
F_149 ( V_15 , V_225 , V_225 , V_227 >> V_22 ) ;
F_73 ( V_15 , V_17 , V_225 , V_122 ) ;
if ( V_130 == V_225 )
F_137 ( V_15 , V_130 , V_134 ) ;
}
}
static void
F_150 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_130 ,
unsigned int V_134 , unsigned int V_182 )
{
unsigned int V_150 = V_221 | V_229 ;
F_140 ( V_15 , V_17 , V_130 , V_134 , V_150 , V_182 ) ;
}
static void
F_151 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_130 , unsigned int V_134 , int V_182 ,
enum V_121 V_122 )
{
int V_225 = V_182 >= 0 ? V_182 : V_130 ;
int V_226 = V_130 ;
if ( V_22 ) {
F_46 ( V_15 , V_225 , V_226 , V_22 ) ;
V_226 = V_225 ;
}
F_49 ( V_15 , V_225 , V_226 ,
( V_227 | V_230 ) >> V_22 ) ;
F_149 ( V_15 , V_225 , V_225 ,
( V_227 | V_230 ) >> V_22 ) ;
F_73 ( V_15 , V_17 , V_225 , V_122 ) ;
if ( V_130 == V_225 )
F_137 ( V_15 , V_130 , V_134 ) ;
else
F_50 ( V_15 ) ;
}
static void
F_152 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_130 ,
unsigned int V_134 , unsigned int V_182 )
{
unsigned int V_150 = ( V_229 | V_231 | V_221
| V_222 ) ;
F_140 ( V_15 , V_17 , V_130 , V_134 , V_150 , V_182 ) ;
}
static void
F_153 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_130 , unsigned int V_134 , int V_182 ,
enum V_121 V_122 )
{
if ( F_6 () ) {
F_148 ( V_15 , V_17 , V_130 , F_32 ( V_230 ) , V_122 ) ;
F_50 ( V_15 ) ;
} else {
int V_225 = V_182 >= 0 ? V_182 : V_130 ;
F_46 ( V_15 , V_225 , V_130 , V_24 ) ;
F_49 ( V_15 , V_225 , V_225 , 1 ) ;
F_79 ( V_15 , V_17 , V_225 , V_122 ) ;
if ( V_130 == V_225 )
F_137 ( V_15 , V_130 , V_134 ) ;
}
}
static void
F_154 ( T_3 * * V_15 , unsigned int V_130 , unsigned int V_120 )
{
F_51 ( V_15 , V_130 , V_59 ) ;
F_41 ( V_15 , V_120 , V_60 ) ;
V_70 ( V_15 ) ;
F_53 ( V_15 , V_120 ) ;
F_54 ( V_15 ) ;
}
static void
F_155 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_130 ,
unsigned int V_120 )
{
F_41 ( V_15 , V_120 , V_175 ) ;
F_51 ( V_15 , V_130 , V_59 ) ;
F_83 ( V_15 , V_17 , V_120 , V_232 ) ;
F_41 ( V_15 , V_120 , V_60 ) ;
V_70 ( V_15 ) ;
F_53 ( V_15 , V_120 ) ;
F_54 ( V_15 ) ;
F_156 ( V_21 , * V_15 ) ;
F_52 ( V_15 ) ;
F_53 ( V_15 , V_120 ) ;
F_54 ( V_15 ) ;
}
static void
F_157 ( T_3 * * V_15 , unsigned int V_130 ,
unsigned int V_134 )
{
long V_54 = ( long ) V_55 ;
F_41 ( V_15 , V_130 , V_57 ) ;
F_42 ( V_15 , V_134 , F_43 ( V_54 ) ) ;
F_44 ( V_15 , V_134 , F_45 ( V_54 ) , V_134 ) ;
F_46 ( V_15 , V_130 , V_130 , 22 ) ;
F_47 ( V_15 , V_130 , V_130 , 2 ) ;
F_48 ( V_15 , V_134 , V_134 , V_130 ) ;
F_41 ( V_15 , V_130 , V_58 ) ;
F_44 ( V_15 , V_134 , 0 , V_134 ) ;
F_49 ( V_15 , V_130 , V_130 , 0xffc ) ;
F_48 ( V_15 , V_134 , V_134 , V_130 ) ;
F_44 ( V_15 , V_130 , 0 , V_134 ) ;
F_58 ( V_15 ) ;
}
static void F_158 ( void )
{
T_3 * V_15 = V_233 ;
const int V_234 = V_235 - V_233 ;
struct V_20 * V_21 = V_185 ;
struct V_16 * V_17 = V_186 ;
memset ( V_233 , 0 , V_234 * sizeof( V_233 [ 0 ] ) ) ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
F_157 ( & V_15 , V_45 , V_47 ) ;
F_147 ( & V_15 , & V_17 , V_45 , V_47 , - 1 , V_236 ) ;
F_50 ( & V_15 ) ;
F_150 ( & V_15 , & V_17 , V_45 , V_47 , - 1 ) ;
F_155 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 ) ;
F_159 ( & V_21 , V_15 ) ;
F_160 ( & V_15 , ( unsigned long ) V_158 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_235 )
F_55 ( L_30 ) ;
F_124 ( V_186 , V_185 ) ;
F_19 ( L_31 ,
( unsigned int ) ( V_15 - V_233 ) ) ;
F_22 ( L_32 , V_233 , V_234 ) ;
}
static void F_161 ( void )
{
T_3 * V_15 = V_237 ;
const int V_238 = V_239 - V_237 ;
struct V_20 * V_21 = V_185 ;
struct V_16 * V_17 = V_186 ;
memset ( V_237 , 0 , V_238 * sizeof( V_237 [ 0 ] ) ) ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
F_157 ( & V_15 , V_45 , V_47 ) ;
F_151 ( & V_15 , & V_17 , V_45 , V_47 , - 1 , V_240 ) ;
F_50 ( & V_15 ) ;
F_152 ( & V_15 , & V_17 , V_45 , V_47 , - 1 ) ;
F_155 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 ) ;
F_162 ( & V_21 , V_15 ) ;
F_160 ( & V_15 , ( unsigned long ) V_241 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_239 )
F_55 ( L_33 ) ;
F_124 ( V_186 , V_185 ) ;
F_19 ( L_34 ,
( unsigned int ) ( V_15 - V_237 ) ) ;
F_22 ( L_35 , V_237 , V_238 ) ;
}
static void F_163 ( void )
{
T_3 * V_15 = V_242 ;
const int V_243 = V_244 - V_242 ;
struct V_20 * V_21 = V_185 ;
struct V_16 * V_17 = V_186 ;
memset ( V_242 , 0 , V_243 * sizeof( V_242 [ 0 ] ) ) ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
F_157 ( & V_15 , V_45 , V_47 ) ;
F_153 ( & V_15 , & V_17 , V_45 , V_47 , - 1 , V_245 ) ;
F_50 ( & V_15 ) ;
F_152 ( & V_15 , & V_17 , V_45 , V_47 , - 1 ) ;
F_154 ( & V_15 , V_45 , V_47 ) ;
F_164 ( & V_21 , V_15 ) ;
F_160 ( & V_15 , ( unsigned long ) V_241 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_244 )
F_55 ( L_36 ) ;
F_124 ( V_186 , V_185 ) ;
F_19 ( L_37 ,
( unsigned int ) ( V_15 - V_242 ) ) ;
F_22 ( L_38 , V_242 , V_243 ) ;
}
static struct V_42
F_165 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 )
{
struct V_42 V_246 = F_26 ( V_15 ) ;
#ifdef V_190
F_80 ( V_15 , V_21 , V_17 , V_246 . V_44 , V_246 . V_46 ) ;
#else
F_99 ( V_15 , V_246 . V_44 , V_246 . V_46 ) ;
#endif
#ifdef F_20
F_71 ( V_15 , V_17 , V_246 . V_44 , V_246 . V_46 , V_135 ) ;
#endif
F_38 ( V_15 , V_246 . V_44 , V_57 ) ;
F_39 ( V_15 , V_246 . V_46 , 0 , V_246 . V_46 ) ;
F_64 ( V_15 , V_246 . V_44 , V_246 . V_44 , V_139 + V_247 - V_163 ) ;
F_49 ( V_15 , V_246 . V_44 , V_246 . V_44 , ( V_165 - 1 ) << V_163 ) ;
F_34 ( V_15 , V_246 . V_46 , V_246 . V_46 , V_246 . V_44 ) ;
#ifdef F_77
F_166 ( V_21 , * V_15 ) ;
#endif
F_137 ( V_15 , V_246 . V_44 , V_246 . V_46 ) ;
if ( ! F_12 () ) {
F_57 ( V_15 ) ;
if ( V_248 ) {
F_61 ( V_15 ) ;
F_41 ( V_15 , V_246 . V_48 , V_175 ) ;
F_83 ( V_15 , V_17 , V_246 . V_48 , V_127 ) ;
F_50 ( V_15 ) ;
}
}
return V_246 ;
}
static void
F_167 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_120 ,
unsigned int V_134 )
{
F_68 ( V_15 , V_134 , V_134 , sizeof( V_170 ) ) ;
F_149 ( V_15 , V_134 , V_134 , sizeof( V_170 ) ) ;
F_103 ( V_15 , V_120 , V_134 ) ;
F_59 ( V_15 , V_21 , V_17 , V_69 ) ;
F_110 ( V_21 , * V_15 ) ;
F_37 ( V_15 ) ;
F_111 ( V_15 ) ;
#ifdef V_190
F_92 ( V_15 , V_21 , V_17 , V_120 , V_134 , V_155 ) ;
#endif
}
static void F_168 ( void )
{
T_3 * V_15 = V_233 ;
const int V_234 = V_235 - V_233 ;
struct V_20 * V_21 = V_185 ;
struct V_16 * V_17 = V_186 ;
struct V_42 V_246 ;
memset ( V_233 , 0 , V_234 * sizeof( V_233 [ 0 ] ) ) ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
if ( F_4 () ) {
unsigned int V_192 = 44 ;
F_82 ( & V_15 , V_45 , V_57 ) ;
F_82 ( & V_15 , V_47 , V_193 ) ;
F_113 ( & V_15 , V_45 , V_45 , V_47 ) ;
F_66 ( & V_15 , V_47 , V_45 , 62 ) ;
F_66 ( & V_15 , V_45 , V_45 , 12 + 1 ) ;
F_114 ( & V_15 , V_45 , V_45 , 64 + 12 + 1 - V_192 ) ;
F_115 ( & V_15 , V_45 , V_45 , V_47 ) ;
F_73 ( & V_15 , & V_17 , V_45 , V_127 ) ;
}
V_246 = F_165 ( & V_15 , & V_21 , & V_17 ) ;
F_147 ( & V_15 , & V_17 , V_246 . V_44 , V_246 . V_46 , V_246 . V_48 , V_236 ) ;
if ( F_12 () )
F_57 ( & V_15 ) ;
if ( V_28 && ! V_249 ) {
if ( F_6 () ) {
F_148 ( & V_15 , & V_17 , V_246 . V_44 , F_32 ( V_221 ) ,
V_218 ) ;
} else {
F_49 ( & V_15 , V_246 . V_48 , V_246 . V_44 , V_221 ) ;
F_79 ( & V_15 , & V_17 , V_246 . V_48 , V_218 ) ;
}
F_50 ( & V_15 ) ;
F_169 ( & V_15 ) ;
switch ( F_7 () ) {
default:
if ( V_72 ) {
F_61 ( & V_15 ) ;
case V_5 :
case V_6 :
case V_7 :
break;
}
}
if ( F_6 () ) {
F_170 ( & V_15 , V_246 . V_46 , F_32 ( sizeof( V_170 ) ) , 8 ) ;
} else {
F_49 ( & V_15 , V_246 . V_48 , V_246 . V_46 , sizeof( V_170 ) ) ;
F_171 ( & V_15 , V_246 . V_48 , 8 ) ;
}
F_38 ( & V_15 , V_246 . V_48 , V_59 ) ;
F_38 ( & V_15 , V_246 . V_48 , V_133 ) ;
if ( F_6 () ) {
F_72 ( & V_15 , & V_17 , V_246 . V_48 , 1 , V_236 ) ;
F_50 ( & V_15 ) ;
F_136 ( & V_21 , V_15 ) ;
} else {
F_49 ( & V_15 , V_246 . V_48 , V_246 . V_48 , 2 ) ;
F_73 ( & V_15 , & V_17 , V_246 . V_48 , V_236 ) ;
F_50 ( & V_15 ) ;
}
F_136 ( & V_21 , V_15 ) ;
}
F_150 ( & V_15 , & V_17 , V_246 . V_44 , V_246 . V_46 , V_246 . V_48 ) ;
F_167 ( & V_15 , & V_21 , & V_17 , V_246 . V_44 , V_246 . V_46 ) ;
#ifdef F_20
F_116 ( & V_21 , V_15 ) ;
F_137 ( & V_15 , V_246 . V_44 , V_246 . V_46 ) ;
F_147 ( & V_15 , & V_17 , V_246 . V_44 , V_246 . V_46 , V_246 . V_48 , V_236 ) ;
F_57 ( & V_15 ) ;
if ( V_28 && ! V_249 ) {
if ( F_6 () ) {
F_148 ( & V_15 , & V_17 , V_246 . V_44 , F_32 ( V_221 ) ,
V_250 ) ;
} else {
F_49 ( & V_15 , V_246 . V_48 , V_246 . V_44 , V_221 ) ;
F_79 ( & V_15 , & V_17 , V_246 . V_48 , V_250 ) ;
}
F_50 ( & V_15 ) ;
F_169 ( & V_15 ) ;
switch ( F_7 () ) {
default:
if ( V_72 ) {
F_61 ( & V_15 ) ;
case V_5 :
case V_6 :
case V_7 :
break;
}
}
if ( F_6 () ) {
F_170 ( & V_15 , V_246 . V_46 , F_32 ( sizeof( V_170 ) ) , 8 ) ;
} else {
F_49 ( & V_15 , V_246 . V_48 , V_246 . V_46 , sizeof( V_170 ) ) ;
F_171 ( & V_15 , V_246 . V_48 , 8 ) ;
}
F_38 ( & V_15 , V_246 . V_48 , V_59 ) ;
F_38 ( & V_15 , V_246 . V_48 , V_133 ) ;
if ( F_6 () ) {
F_148 ( & V_15 , & V_17 , V_246 . V_48 , 1 , V_250 ) ;
} else {
F_49 ( & V_15 , V_246 . V_48 , V_246 . V_48 , 2 ) ;
F_79 ( & V_15 , & V_17 , V_246 . V_48 , V_250 ) ;
}
if ( V_124 == 0 )
F_50 ( & V_15 ) ;
F_67 ( & V_15 , & V_17 , V_246 . V_48 , V_236 , 0 ) ;
F_172 ( & V_21 , V_15 ) ;
}
F_68 ( & V_15 , V_246 . V_44 , V_246 . V_44 , ( V_229 | V_221 ) ) ;
F_76 ( & V_15 , & V_17 , & V_21 , V_246 . V_44 , V_246 . V_46 ) ;
#endif
F_159 ( & V_21 , V_15 ) ;
F_37 ( & V_15 ) ;
#ifdef F_173
if ( ( unsigned long ) V_158 & 1 ) {
F_42 ( & V_15 , V_45 , F_43 ( ( long ) V_158 ) ) ;
F_96 ( & V_15 , V_45 , V_45 , F_45 ( ( long ) V_158 ) ) ;
F_53 ( & V_15 , V_45 ) ;
} else
#endif
F_160 ( & V_15 , ( unsigned long ) V_158 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_235 )
F_55 ( L_30 ) ;
F_124 ( V_186 , V_185 ) ;
F_19 ( L_31 ,
( unsigned int ) ( V_15 - V_233 ) ) ;
F_22 ( L_39 , V_233 , V_234 ) ;
}
static void F_174 ( void )
{
T_3 * V_15 = V_237 ;
const int V_238 = V_239 - V_237 ;
struct V_20 * V_21 = V_185 ;
struct V_16 * V_17 = V_186 ;
struct V_42 V_246 ;
memset ( V_237 , 0 , V_238 * sizeof( V_237 [ 0 ] ) ) ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
V_246 = F_165 ( & V_15 , & V_21 , & V_17 ) ;
F_151 ( & V_15 , & V_17 , V_246 . V_44 , V_246 . V_46 , V_246 . V_48 , V_240 ) ;
if ( F_12 () )
F_57 ( & V_15 ) ;
F_152 ( & V_15 , & V_17 , V_246 . V_44 , V_246 . V_46 , V_246 . V_48 ) ;
F_167 ( & V_15 , & V_21 , & V_17 , V_246 . V_44 , V_246 . V_46 ) ;
#ifdef F_20
F_116 ( & V_21 , V_15 ) ;
F_137 ( & V_15 , V_246 . V_44 , V_246 . V_46 ) ;
F_151 ( & V_15 , & V_17 , V_246 . V_44 , V_246 . V_46 , V_246 . V_48 , V_240 ) ;
F_57 ( & V_15 ) ;
F_68 ( & V_15 , V_246 . V_44 , V_246 . V_44 ,
V_229 | V_231 | V_221 | V_222 ) ;
F_76 ( & V_15 , & V_17 , & V_21 , V_246 . V_44 , V_246 . V_46 ) ;
#endif
F_162 ( & V_21 , V_15 ) ;
F_37 ( & V_15 ) ;
#ifdef F_173
if ( ( unsigned long ) V_241 & 1 ) {
F_42 ( & V_15 , V_45 , F_43 ( ( long ) V_241 ) ) ;
F_96 ( & V_15 , V_45 , V_45 , F_45 ( ( long ) V_241 ) ) ;
F_53 ( & V_15 , V_45 ) ;
} else
#endif
F_160 ( & V_15 , ( unsigned long ) V_241 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_239 )
F_55 ( L_33 ) ;
F_124 ( V_186 , V_185 ) ;
F_19 ( L_34 ,
( unsigned int ) ( V_15 - V_237 ) ) ;
F_22 ( L_40 , V_237 , V_238 ) ;
}
static void F_175 ( void )
{
T_3 * V_15 = V_242 ;
const int V_243 = V_244 - V_242 ;
struct V_20 * V_21 = V_185 ;
struct V_16 * V_17 = V_186 ;
struct V_42 V_246 ;
memset ( V_242 , 0 , V_243 * sizeof( V_242 [ 0 ] ) ) ;
memset ( V_185 , 0 , sizeof( V_185 ) ) ;
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
V_246 = F_165 ( & V_15 , & V_21 , & V_17 ) ;
F_153 ( & V_15 , & V_17 , V_246 . V_44 , V_246 . V_46 , V_246 . V_48 , V_245 ) ;
if ( F_12 () )
F_57 ( & V_15 ) ;
F_152 ( & V_15 , & V_17 , V_246 . V_44 , V_246 . V_46 , V_246 . V_48 ) ;
F_167 ( & V_15 , & V_21 , & V_17 , V_246 . V_44 , V_246 . V_46 ) ;
#ifdef F_20
F_116 ( & V_21 , V_15 ) ;
F_137 ( & V_15 , V_246 . V_44 , V_246 . V_46 ) ;
F_153 ( & V_15 , & V_17 , V_246 . V_44 , V_246 . V_46 , V_246 . V_48 , V_245 ) ;
F_57 ( & V_15 ) ;
F_68 ( & V_15 , V_246 . V_44 , V_246 . V_44 ,
V_229 | V_231 | V_221 | V_222 ) ;
F_76 ( & V_15 , & V_17 , & V_21 , V_246 . V_44 , V_246 . V_46 ) ;
#endif
F_164 ( & V_21 , V_15 ) ;
F_37 ( & V_15 ) ;
#ifdef F_173
if ( ( unsigned long ) V_241 & 1 ) {
F_42 ( & V_15 , V_45 , F_43 ( ( long ) V_241 ) ) ;
F_96 ( & V_15 , V_45 , V_45 , F_45 ( ( long ) V_241 ) ) ;
F_53 ( & V_15 , V_45 ) ;
} else
#endif
F_160 ( & V_15 , ( unsigned long ) V_241 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_244 )
F_55 ( L_36 ) ;
F_124 ( V_186 , V_185 ) ;
F_19 ( L_37 ,
( unsigned int ) ( V_15 - V_242 ) ) ;
F_22 ( L_41 , V_242 , V_243 ) ;
}
static void F_176 ( void )
{
F_56 ( ( unsigned long ) V_233 ,
( unsigned long ) V_235 ) ;
F_56 ( ( unsigned long ) V_237 ,
( unsigned long ) V_239 ) ;
F_56 ( ( unsigned long ) V_242 ,
( unsigned long ) V_244 ) ;
F_56 ( ( unsigned long ) V_217 ,
( unsigned long ) V_216 ) ;
}
static void F_177 ( void )
{
unsigned long V_251 ;
unsigned int V_252 ;
const int V_253 = 2 * sizeof( unsigned long ) ;
V_251 = F_178 () ;
F_19 ( L_42 ,
V_253 , V_251 ,
( V_251 & V_254 ) >> V_255 ,
( V_251 & V_256 ) >> V_257 ,
( V_251 & V_258 ) >> V_259 ,
( V_251 & V_260 ) >> V_261 ,
( V_251 & V_262 ) >> V_263 ) ;
V_251 = F_179 () ;
F_19 ( L_43 ,
V_253 , V_251 ,
( V_251 & V_264 ) >> V_265 ,
( V_251 & V_266 ) >> V_267 ,
( V_251 & V_268 ) >> V_269 ,
( V_251 & V_270 ) >> V_271 ,
( V_251 & V_272 ) >> V_273 ,
( V_251 & V_274 ) >> V_275 ) ;
V_252 = F_180 () ;
F_19 ( L_44 ,
V_252 ,
( V_252 & V_276 ) >> V_277 ,
( V_252 & V_278 ) >> V_279 ,
( V_252 & V_280 ) >> V_281 ,
( V_252 & V_282 ) >> V_283 ,
( V_252 & V_284 ) >> V_285 ,
( V_252 & V_286 ) >> V_287 ,
( V_252 & V_288 ) >> V_289 ) ;
}
static void F_181 ( void )
{
unsigned long V_290 , V_291 , V_292 ;
unsigned int V_251 ;
V_290 = F_178 () ;
V_290 &= ~ V_254 ;
V_290 |= V_137 << V_255 ;
V_290 &= ~ V_260 ;
V_290 |= V_139 << V_261 ;
if ( V_293 >= 3 ) {
V_290 &= ~ V_258 ;
V_290 |= V_146 << V_259 ;
}
V_292 = V_29 << V_263 ;
V_290 |= V_292 ;
F_126 ( V_290 ) ;
F_182 () ;
V_290 = F_178 () ;
if ( ( ( V_290 & V_262 ) << V_263 )
!= V_292 ) {
F_183 ( L_45 ,
V_292 ) ;
V_11 . V_294 &= ~ V_295 ;
return;
}
V_291 = F_32 ( V_145 ) << V_267 ;
V_291 |= F_32 ( V_165 ) << V_273 ;
if ( V_293 >= 3 )
V_291 |= F_32 ( V_147 ) << V_271 ;
if ( F_104 ( V_190 ) )
V_291 |= V_264 ;
V_291 |= ( ( V_163 - V_160 ) << V_275 )
& V_274 ;
F_127 ( V_291 ) ;
F_182 () ;
V_251 = 1 << V_277 ;
if ( F_104 ( V_190 ) )
V_251 |= V_282 ;
F_128 ( V_251 ) ;
F_184 ( L_46 ) ;
F_177 () ;
}
static void F_185 ( void )
{
#ifdef V_173
unsigned int V_296 ;
if ( V_2 ) {
F_184 ( L_47 ) ;
return;
}
V_296 = F_186 () ;
F_187 ( V_296 | V_297 ) ;
F_182 () ;
V_296 = F_186 () ;
if ( V_296 & V_297 )
F_184 ( L_48 ) ;
else
F_55 ( L_49 ) ;
#endif
}
static void F_188 ( void )
{
unsigned long V_298 ;
unsigned V_299 , V_300 ;
if ( ! V_28 || ! V_117 ) {
return;
}
F_189 ( ~ 0ul ) ;
F_182 () ;
V_298 = F_190 () ;
V_298 &= ~ ( ( 1 << V_301 ) - 1 ) ;
V_298 &= ~ ( V_302 | V_303 ) ;
V_299 = F_191 ( V_298 ) + 6 ;
V_300 = F_192 ( int , ( int ) V_304 - V_299 , 0 ) ;
V_300 -= F_193 ( unsigned , V_300 , 2 ) ;
if ( V_300 >= F_32 ( V_117 ) )
V_118 = true ;
F_19 ( L_50 , V_300 ) ;
}
void F_194 ( void )
{
static int V_305 = 0 ;
if ( F_104 ( V_173 ) && ! V_28 )
F_55 ( L_51 ) ;
F_17 () ;
F_188 () ;
#ifdef V_190
V_136 = V_11 . V_306 > ( V_137 + V_138 + V_139 - 3 ) ;
#endif
switch ( F_7 () ) {
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
#ifndef F_81
if ( V_314 )
F_40 () ;
if ( ! V_305 ) {
if ( ! V_314 )
F_40 () ;
F_133 () ;
F_158 () ;
F_161 () ;
F_163 () ;
F_176 () ;
V_305 ++ ;
}
#else
F_55 ( L_52 ) ;
#endif
break;
case V_315 :
case V_316 :
F_55 ( L_53 ) ;
break;
case V_317 :
F_55 ( L_54 ) ;
break;
default:
if ( V_142 )
F_125 () ;
if ( ! V_305 ) {
V_43 = F_24 () ;
F_133 () ;
F_168 () ;
F_174 () ;
F_175 () ;
if ( V_142 )
F_130 () ;
else if ( ! V_314 )
F_112 () ;
F_176 () ;
V_305 ++ ;
}
if ( V_314 )
F_112 () ;
if ( V_174 )
F_185 () ;
if ( V_248 )
F_181 () ;
}
}
