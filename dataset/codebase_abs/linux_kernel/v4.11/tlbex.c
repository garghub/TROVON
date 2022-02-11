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
void F_59 ( T_3 * * V_15 , struct V_20 * * V_21 ,
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
unsigned int V_134 ,
unsigned int V_135 )
{
#ifdef F_77
F_78 ( V_15 , V_130 , 0 , V_134 ) ;
F_79 ( V_15 , V_17 , V_130 , V_136 ) ;
F_39 ( V_15 , V_130 , 0 , V_134 ) ;
#else
F_35 ( V_15 , V_130 , 0 , V_134 ) ;
#endif
if ( V_137 && V_135 ) {
F_80 ( ! V_138 ) ;
F_38 ( V_15 , V_134 , V_139 ) ;
F_68 ( V_15 , V_134 , V_134 , V_140 ) ;
F_27 ( V_15 , V_134 , V_139 ) ;
F_59 ( V_15 , V_21 , V_17 , V_69 ) ;
F_81 ( V_15 , V_134 , V_134 , V_140 ) ;
F_27 ( V_15 , V_134 , V_139 ) ;
F_74 ( V_15 , V_130 , V_134 ) ;
F_70 ( V_15 , V_21 , V_17 , V_130 , V_68 , 0 ) ;
return;
}
F_74 ( V_15 , V_130 , V_134 ) ;
F_70 ( V_15 , V_21 , V_17 , V_130 , V_69 , 0 ) ;
}
void F_82 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_120 , unsigned int V_134 )
{
#ifndef F_83
long V_54 = ( long ) V_55 ;
#endif
F_84 ( V_15 , V_120 , V_57 ) ;
if ( V_141 ) {
F_66 ( V_15 , V_134 , V_120 , V_142 + V_143 + V_144 - 3 ) ;
F_73 ( V_15 , V_17 , V_134 , V_145 ) ;
} else {
F_85 ( V_15 , V_17 , V_120 , V_145 ) ;
}
if ( V_146 != - 1 ) {
if ( V_147 )
F_38 ( V_15 , V_134 , V_148 ) ;
else
F_38 ( V_15 , V_134 , F_23 () , V_146 ) ;
} else {
#if F_86 ( F_83 )
F_38 ( V_15 , V_134 , V_58 ) ;
F_87 ( V_15 , V_134 , 0 , 0 , 23 ) ;
F_68 ( V_15 , V_134 , V_134 , 0x540 ) ;
F_88 ( V_15 , V_134 , V_134 , 11 ) ;
#elif F_86 ( F_77 )
F_29 ( V_15 , V_134 , V_49 ) ;
F_66 ( V_15 , V_134 , V_134 , V_149 ) ;
F_89 ( V_15 , V_120 , V_54 ) ;
F_90 ( V_15 , V_134 , V_134 , V_120 ) ;
F_84 ( V_15 , V_120 , V_57 ) ;
F_91 ( V_15 , V_134 , F_45 ( V_54 ) , V_134 ) ;
#else
F_89 ( V_15 , V_134 , V_54 ) ;
F_91 ( V_15 , V_134 , F_45 ( V_54 ) , V_134 ) ;
#endif
}
F_92 ( V_21 , * V_15 ) ;
F_66 ( V_15 , V_120 , V_120 , V_142 - 3 ) ;
F_49 ( V_15 , V_120 , V_120 , ( V_150 - 1 ) << 3 ) ;
F_90 ( V_15 , V_134 , V_134 , V_120 ) ;
#ifndef F_93
F_84 ( V_15 , V_120 , V_57 ) ;
F_91 ( V_15 , V_134 , 0 , V_134 ) ;
F_66 ( V_15 , V_120 , V_120 , V_151 - 3 ) ;
F_49 ( V_15 , V_120 , V_120 , ( V_152 - 1 ) << 3 ) ;
F_90 ( V_15 , V_134 , V_134 , V_120 ) ;
#endif
}
static void
F_94 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_153 , unsigned int V_134 ,
enum V_154 V_155 )
{
long V_156 = ( long ) V_157 ;
int V_158 ;
int V_159 = 0 ;
V_158 = F_95 ( V_156 ) && ! F_45 ( V_156 ) ;
F_96 ( V_21 , * V_15 ) ;
if ( V_155 != V_160 && V_141 ) {
if ( V_158 ) {
F_85 ( V_15 , V_17 , V_153 , V_161 ) ;
F_42 ( V_15 , V_134 , F_43 ( V_156 ) ) ;
V_159 = 1 ;
} else {
F_97 ( V_15 , V_17 , V_153 , V_162 ) ;
}
}
if ( ! V_159 ) {
if ( V_158 ) {
F_69 ( V_15 , V_17 , V_161 ) ;
F_42 ( V_15 , V_134 , F_43 ( V_156 ) ) ;
} else {
F_89 ( V_15 , V_134 , V_156 ) ;
F_69 ( V_15 , V_17 , V_161 ) ;
if ( F_95 ( V_156 ) )
F_98 ( V_15 , V_134 , V_134 , F_45 ( V_156 ) ) ;
else
F_99 ( V_15 , V_134 , V_134 , F_45 ( V_156 ) ) ;
}
}
if ( V_155 != V_160 && V_141 ) {
F_100 ( V_21 , * V_15 ) ;
F_33 ( V_15 , V_134 , ( unsigned long ) V_163 ) ;
F_53 ( V_15 , V_134 ) ;
if ( V_155 == V_164 ) {
if ( V_43 >= 0 )
F_38 ( V_15 , 1 , F_23 () , V_43 ) ;
else
F_39 ( V_15 , 1 , F_10 ( 0 ) , 0 ) ;
} else {
F_50 ( V_15 ) ;
}
}
}
void F_101 ( T_3 * * V_15 , unsigned int V_120 , unsigned int V_134 )
{
if ( V_146 != - 1 ) {
F_41 ( V_15 , V_134 , F_23 () , V_146 ) ;
F_41 ( V_15 , V_120 , V_57 ) ;
} else {
long V_54 = ( long ) V_55 ;
#ifdef F_77
F_41 ( V_15 , V_134 , V_49 ) ;
F_89 ( V_15 , V_120 , V_54 ) ;
F_46 ( V_15 , V_134 , V_134 , V_149 ) ;
F_48 ( V_15 , V_134 , V_120 , V_134 ) ;
#else
F_89 ( V_15 , V_134 , V_54 ) ;
#endif
F_41 ( V_15 , V_120 , V_57 ) ;
F_44 ( V_15 , V_134 , F_45 ( V_54 ) , V_134 ) ;
}
F_46 ( V_15 , V_120 , V_120 , V_142 ) ;
F_47 ( V_15 , V_120 , V_120 , V_165 ) ;
F_48 ( V_15 , V_134 , V_134 , V_120 ) ;
}
static void F_102 ( T_3 * * V_15 , unsigned int V_166 )
{
unsigned int V_167 = 4 - ( V_168 + 1 ) + V_144 - 12 ;
unsigned int V_169 = ( V_170 / 2 - 1 ) << ( V_168 + 1 ) ;
switch ( F_7 () ) {
case V_171 :
case V_107 :
case V_108 :
case V_109 :
case V_112 :
case V_110 :
case V_111 :
case V_113 :
V_167 += 2 ;
break;
default:
break;
}
if ( V_167 )
F_64 ( V_15 , V_166 , V_166 , V_167 ) ;
F_49 ( V_15 , V_166 , V_166 , V_169 ) ;
}
void F_103 ( T_3 * * V_15 , unsigned int V_120 , unsigned int V_134 )
{
switch ( F_7 () ) {
case V_65 :
F_39 ( V_15 , V_134 , 0 , V_134 ) ;
F_104 ( V_15 , V_120 ) ;
break;
default:
F_104 ( V_15 , V_120 ) ;
F_39 ( V_15 , V_134 , 0 , V_134 ) ;
break;
}
F_102 ( V_15 , V_120 ) ;
F_34 ( V_15 , V_134 , V_134 , V_120 ) ;
}
void F_105 ( T_3 * * V_15 , unsigned int V_120 , unsigned int V_172 )
{
int V_173 = 0 ;
int V_174 = sizeof( V_175 ) ;
#if F_86 ( V_176 ) && F_86 ( F_65 )
V_173 += F_36 ( V_175 , V_177 ) ;
V_174 += F_36 ( V_175 , V_177 ) ;
#endif
if ( F_106 ( V_178 ) ) {
F_44 ( V_15 , V_120 , V_173 , V_172 ) ;
F_63 ( V_15 , V_120 , V_120 , F_32 ( V_119 ) ) ;
F_27 ( V_15 , V_120 , V_59 ) ;
if ( V_179 && ! V_2 ) {
F_44 ( V_15 , V_120 , 0 , V_172 ) ;
F_107 ( V_15 , V_120 , V_120 , 0 , 24 ) ;
F_108 ( V_15 , V_120 , V_59 ) ;
}
F_44 ( V_15 , V_120 , V_174 , V_172 ) ;
F_63 ( V_15 , V_120 , V_120 , F_32 ( V_119 ) ) ;
F_27 ( V_15 , V_120 , V_133 ) ;
if ( V_179 && ! V_2 ) {
F_44 ( V_15 , V_120 , sizeof( V_175 ) , V_172 ) ;
F_107 ( V_15 , V_120 , V_120 , 0 , 24 ) ;
F_108 ( V_15 , V_120 , V_133 ) ;
}
return;
}
F_39 ( V_15 , V_120 , V_173 , V_172 ) ;
F_39 ( V_15 , V_172 , V_174 , V_172 ) ;
if ( F_2 () )
F_57 ( V_15 ) ;
F_62 ( V_15 , V_120 ) ;
if ( F_3 () )
F_27 ( V_15 , 0 , V_59 ) ;
F_27 ( V_15 , V_120 , V_59 ) ;
F_62 ( V_15 , V_172 ) ;
if ( F_2 () )
F_41 ( V_15 , V_120 , V_180 ) ;
if ( F_3 () )
F_27 ( V_15 , 0 , V_133 ) ;
F_27 ( V_15 , V_172 , V_133 ) ;
}
static struct V_181
F_109 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_120 ,
unsigned int V_134 , int V_182 )
{
struct V_181 V_183 ;
unsigned int V_184 , V_185 ;
int V_186 = 0 ;
const int V_187 = 1 ;
V_183 . V_188 = V_187 ;
V_183 . V_123 = 0 ;
V_183 . V_189 = false ;
if ( V_141 ) {
F_38 ( V_15 , V_120 , V_57 ) ;
if ( V_146 != - 1 )
F_38 ( V_15 , V_134 , F_23 () , V_146 ) ;
else
F_38 ( V_15 , V_134 , V_58 ) ;
if ( V_182 >= 0 )
F_27 ( V_15 , V_187 , F_23 () , V_182 ) ;
else
F_35 ( V_15 , V_187 , F_10 ( 0 ) , 0 ) ;
F_66 ( V_15 , V_187 , V_120 ,
V_142 + V_143 + V_144 - 3 ) ;
F_73 ( V_15 , V_17 , V_187 , V_145 ) ;
if ( V_146 == - 1 ) {
V_186 = 1 ;
F_87 ( V_15 , V_134 , 0 , 0 , 23 ) ;
}
} else {
if ( V_146 != - 1 )
F_38 ( V_15 , V_134 , F_23 () , V_146 ) ;
else
F_38 ( V_15 , V_134 , V_58 ) ;
F_38 ( V_15 , V_120 , V_57 ) ;
if ( V_182 >= 0 )
F_27 ( V_15 , V_187 , F_23 () , V_182 ) ;
else
F_35 ( V_15 , V_187 , F_10 ( 0 ) , 0 ) ;
if ( V_146 == - 1 )
F_87 ( V_15 , V_134 , 0 , 0 , 23 ) ;
F_85 ( V_15 , V_17 , V_120 , V_145 ) ;
}
if ( V_146 == - 1 ) {
V_186 = 1 ;
F_68 ( V_15 , V_134 , V_134 , 0x540 ) ;
F_88 ( V_15 , V_134 , V_134 , 11 ) ;
}
#ifdef F_93
#define F_110 scratch
#else
#define F_110 ptr
#endif
if ( ! V_186 )
F_66 ( V_15 , V_187 , V_120 , V_142 - 3 ) ;
F_92 ( V_21 , * V_15 ) ;
if ( V_186 )
F_66 ( V_15 , V_187 , V_120 , V_142 - 3 ) ;
#ifdef F_93
F_104 ( V_15 , V_120 ) ;
#endif
F_49 ( V_15 , V_187 , V_187 , ( V_150 - 1 ) << 3 ) ;
if ( F_8 () ) {
F_111 ( V_15 , F_110 , V_187 , V_134 ) ;
} else {
F_90 ( V_15 , V_134 , V_134 , V_187 ) ;
F_91 ( V_15 , F_110 , 0 , V_134 ) ;
}
#ifndef F_93
F_66 ( V_15 , V_187 , V_120 , V_151 - 3 ) ;
F_49 ( V_15 , V_187 , V_187 , ( V_152 - 1 ) << 3 ) ;
F_104 ( V_15 , V_120 ) ;
if ( F_8 () ) {
F_111 ( V_15 , V_187 , V_187 , V_134 ) ;
} else {
F_90 ( V_15 , V_134 , V_134 , V_187 ) ;
F_39 ( V_15 , V_187 , 0 , V_134 ) ;
}
#endif
F_102 ( V_15 , V_120 ) ;
#ifdef F_20
F_72 ( V_15 , V_17 , V_187 , F_32 ( V_129 ) , V_136 ) ;
if ( F_8 () )
F_50 ( V_15 ) ;
#endif
if ( F_8 () ) {
V_184 = V_134 ;
V_185 = V_120 ;
F_111 ( V_15 , V_184 , V_187 , V_120 ) ;
F_75 ( V_15 , V_120 , V_120 , sizeof( V_175 ) ) ;
F_111 ( V_15 , V_185 , V_187 , V_120 ) ;
} else {
F_34 ( V_15 , V_134 , V_187 , V_120 ) ;
V_184 = V_120 ;
V_185 = V_134 ;
F_39 ( V_15 , V_184 , 0 , V_134 ) ;
F_39 ( V_15 , V_185 , sizeof( V_175 ) , V_134 ) ;
}
if ( V_28 ) {
F_88 ( V_15 , V_184 , V_184 , F_32 ( V_119 ) ) ;
F_27 ( V_15 , V_184 , V_59 ) ;
F_88 ( V_15 , V_185 , V_185 , F_32 ( V_119 ) ) ;
} else {
F_66 ( V_15 , V_184 , V_184 , F_32 ( V_119 ) ) ;
F_27 ( V_15 , V_184 , V_59 ) ;
F_66 ( V_15 , V_185 , V_185 , F_32 ( V_119 ) ) ;
}
F_27 ( V_15 , V_185 , V_133 ) ;
if ( V_182 >= 0 ) {
F_38 ( V_15 , V_187 , F_23 () , V_182 ) ;
F_59 ( V_15 , V_21 , V_17 , V_68 ) ;
F_112 ( V_21 , * V_15 ) ;
V_183 . V_123 = 1 ;
} else if ( V_144 == 14 || V_144 == 13 ) {
F_59 ( V_15 , V_21 , V_17 , V_68 ) ;
F_112 ( V_21 , * V_15 ) ;
F_39 ( V_15 , V_187 , F_10 ( 0 ) , 0 ) ;
} else {
F_39 ( V_15 , V_187 , F_10 ( 0 ) , 0 ) ;
F_59 ( V_15 , V_21 , V_17 , V_68 ) ;
F_112 ( V_21 , * V_15 ) ;
V_183 . V_123 = 1 ;
}
F_113 ( V_15 ) ;
return V_183 ;
}
static void F_114 ( void )
{
T_3 * V_15 = V_56 ;
struct V_20 * V_21 = V_190 ;
struct V_16 * V_17 = V_191 ;
T_3 * V_192 ;
unsigned int V_193 ;
struct V_181 T_5 T_2 ;
enum V_154 T_6 T_2 ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
memset ( V_194 , 0 , sizeof( V_194 ) ) ;
if ( F_106 ( V_195 ) && ( V_43 >= 0 || F_9 () ) && F_6 () ) {
T_5 = F_109 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 ,
V_43 ) ;
T_6 = V_164 ;
} else {
T_5 . V_188 = V_45 ;
T_5 . V_123 = 0 ;
T_5 . V_189 = true ;
T_6 = V_196 ;
if ( F_4 () ) {
unsigned int V_197 = 44 ;
F_84 ( & V_15 , V_45 , V_57 ) ;
F_84 ( & V_15 , V_47 , V_139 ) ;
F_115 ( & V_15 , V_45 , V_45 , V_47 ) ;
F_66 ( & V_15 , V_47 , V_45 , 62 ) ;
F_66 ( & V_15 , V_45 , V_45 , 12 + 1 ) ;
F_116 ( & V_15 , V_45 , V_45 , 64 + 12 + 1 - V_197 ) ;
F_117 ( & V_15 , V_45 , V_45 , V_47 ) ;
F_73 ( & V_15 , & V_17 , V_45 , V_127 ) ;
}
#ifdef V_195
F_82 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 ) ;
#else
F_101 ( & V_15 , V_45 , V_47 ) ;
#endif
#ifdef F_20
F_71 ( & V_15 , & V_17 , V_45 , V_47 , V_136 ) ;
#endif
F_103 ( & V_15 , V_45 , V_47 ) ;
F_105 ( & V_15 , V_45 , V_47 ) ;
F_59 ( & V_15 , & V_21 , & V_17 , V_68 ) ;
F_112 ( & V_21 , V_15 ) ;
F_113 ( & V_15 ) ;
}
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
if ( T_5 . V_189 )
F_39 ( & V_15 , T_5 . V_188 , 0 , V_47 ) ;
F_74 ( & V_15 , T_5 . V_188 , V_47 ) ;
F_70 ( & V_15 , & V_21 , & V_17 , V_45 , V_68 ,
T_5 . V_123 ) ;
#endif
#ifdef V_195
F_94 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 , T_6 ) ;
#endif
switch ( F_119 () ) {
default:
if ( sizeof( long ) == 4 ) {
case V_102 :
if ( ( V_15 - V_56 ) > 64 )
F_55 ( L_21 ) ;
V_192 = V_194 ;
F_120 ( V_191 , V_190 , V_56 , V_15 , V_192 ) ;
V_193 = V_15 - V_56 ;
break;
} else {
if ( ( ( V_15 - V_56 ) > ( V_198 * 2 ) - 1 )
|| ( ( ( V_15 - V_56 ) > ( V_198 * 2 ) - 3 )
&& F_121 ( V_191 ,
V_56 + V_198 - 3 ) ) )
F_55 ( L_21 ) ;
V_192 = V_194 + V_198 ;
if ( ( V_15 - V_56 ) <= V_198 ) {
F_120 ( V_191 , V_190 , V_56 , V_15 , V_192 ) ;
V_193 = V_15 - V_56 ;
} else {
#ifdef F_20
const enum V_121 V_199 = V_136 ;
#else
const enum V_121 V_199 = V_145 ;
#endif
T_3 * V_200 ;
int V_201 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_122 ( V_190 ) && V_190 [ V_9 ] . V_202 != V_199 ; V_9 ++ )
;
F_80 ( V_9 == F_122 ( V_190 ) ) ;
V_200 = V_190 [ V_9 ] . V_203 ;
if ( V_200 > V_56 + V_198 ||
V_200 < V_15 - V_198 )
V_201 = 1 ;
if ( V_201 ) {
V_200 = V_56 + V_198 - 2 ;
if ( F_121 ( V_191 , V_200 - 1 ) )
V_200 -- ;
}
F_120 ( V_191 , V_190 , V_56 , V_200 , V_192 ) ;
V_192 += V_200 - V_56 ;
if ( V_201 ) {
F_123 ( & V_21 , V_194 ) ;
F_69 ( & V_192 , & V_17 , V_204 ) ;
if ( F_121 ( V_191 , V_200 ) )
F_50 ( & V_192 ) ;
else {
F_120 ( V_191 , V_190 ,
V_200 , V_200 + 1 , V_192 ) ;
F_124 ( V_190 , V_192 , V_192 + 1 , - 1 ) ;
V_192 ++ ;
V_200 ++ ;
}
}
F_120 ( V_191 , V_190 , V_200 , V_15 , V_194 ) ;
V_193 = ( V_192 - ( V_194 + V_198 ) ) +
( V_15 - V_200 ) ;
}
}
break;
}
F_125 ( V_191 , V_190 ) ;
F_19 ( L_22 ,
V_193 ) ;
memcpy ( ( void * ) V_61 , V_194 , 0x100 ) ;
F_56 ( V_61 , V_61 + 0x100 ) ;
F_22 ( L_25 , ( T_3 * ) V_61 , 64 ) ;
}
static void F_126 ( void )
{
unsigned long V_205 , V_206 ;
#ifndef F_93
unsigned long V_207 , V_208 ;
#endif
unsigned long V_209 , V_210 ;
unsigned long V_211 , V_212 ;
#ifdef F_20
unsigned long V_213 ;
V_213 = F_32 ( V_129 ) ;
#endif
V_205 = V_142 ;
#ifndef F_93
V_206 = V_142 - V_151 + V_143 ;
V_207 = V_151 ;
V_208 = V_151 - V_144 ;
#else
V_206 = V_142 - V_144 + V_143 ;
#endif
V_209 = V_144 ;
V_210 = V_144 - 3 ;
V_211 = F_32 ( V_119 ) ;
V_212 = 0 ;
#ifndef F_93
F_127 ( V_205 << 24 | V_207 << 12 | V_209 << 6 | V_211 ) ;
F_128 ( 1 << 30 | V_206 << 24 | V_208 << 12 | V_210 << 6 | V_212 ) ;
#else
F_127 ( V_205 << 24 | V_209 << 6 | V_211 ) ;
F_128 ( 1 << 30 | V_206 << 24 | V_210 << 6 | V_212 ) ;
#endif
#ifdef F_20
F_129 ( 1 << 6 | V_213 ) ;
#endif
F_130 ( V_157 ) ;
V_41 |= ( 1 << 7 ) ;
}
static void F_131 ( void )
{
T_3 * V_15 = V_56 ;
struct V_20 * V_21 = V_190 ;
struct V_16 * V_17 = V_191 ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
if ( V_141 ) {
F_84 ( & V_15 , V_45 , V_57 ) ;
F_66 ( & V_15 , V_47 , V_45 , V_142 + V_143 + V_144 - 3 ) ;
F_79 ( & V_15 , & V_17 , V_47 , V_145 ) ;
F_50 ( & V_15 ) ;
F_97 ( & V_15 , & V_17 , V_45 , V_162 ) ;
F_50 ( & V_15 ) ;
F_96 ( & V_21 , V_15 ) ;
}
F_84 ( & V_15 , V_47 , V_214 ) ;
F_132 ( & V_15 , V_45 , V_47 , 3 ) ;
#ifndef F_93
F_132 ( & V_15 , V_47 , V_45 , 1 ) ;
#endif
F_133 ( & V_15 , V_47 , 0 ) ;
F_133 ( & V_15 , V_47 , 1 ) ;
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
F_113 ( & V_15 ) ;
if ( V_141 ) {
F_100 ( & V_21 , V_15 ) ;
F_33 ( & V_15 , V_47 , ( unsigned long ) V_163 ) ;
F_53 ( & V_15 , V_47 ) ;
F_50 ( & V_15 ) ;
}
F_125 ( V_191 , V_190 ) ;
memcpy ( ( void * ) ( V_61 + 0x80 ) , V_56 , 0x80 ) ;
F_56 ( V_61 + 0x80 , V_61 + 0x100 ) ;
F_22 ( L_26 , ( T_3 * ) ( V_61 + 0x80 ) , 32 ) ;
}
static void F_134 ( void )
{
const int V_215 = 4 ;
const int T_2 V_216 = 5 ;
const int T_2 V_217 = 6 ;
T_3 * V_15 = V_218 ;
const int V_219 =
V_220 - V_218 ;
#ifndef F_83
long V_54 = ( long ) V_55 ;
#endif
memset ( V_221 , 0 , V_219 *
sizeof( V_221 [ 0 ] ) ) ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
V_146 = F_24 () ;
#ifdef F_83
if ( V_146 == - 1 ) {
struct V_20 * V_21 = V_190 ;
struct V_16 * V_17 = V_191 ;
F_135 ( & V_15 , V_216 , V_215 , 29 ) ;
F_75 ( & V_15 , V_216 , V_216 , 4 ) ;
F_73 ( & V_15 , & V_17 , V_216 , V_222 ) ;
F_50 ( & V_15 ) ;
F_136 ( & V_15 , V_215 , 0 , 29 , 64 - 29 ) ;
F_137 ( & V_21 , V_15 ) ;
F_31 ( & V_15 , V_215 , V_215 , 11 ) ;
F_53 ( & V_15 , 31 ) ;
F_27 ( & V_15 , V_215 , V_58 ) ;
} else {
F_53 ( & V_15 , 31 ) ;
if ( V_147 )
F_27 ( & V_15 , V_215 , V_148 ) ;
else
F_27 ( & V_15 , V_215 , F_23 () , V_146 ) ;
}
#else
#ifdef F_77
F_29 ( & V_15 , V_216 , V_49 ) ;
F_30 ( & V_15 , V_216 , V_216 , V_149 ) ;
F_89 ( & V_15 , V_217 , V_54 ) ;
F_34 ( & V_15 , V_217 , V_217 , V_216 ) ;
F_35 ( & V_15 , V_215 , F_45 ( V_54 ) , V_217 ) ;
#else
F_89 ( & V_15 , V_217 , V_54 ) ;
F_35 ( & V_15 , V_215 , F_45 ( V_54 ) , V_217 ) ;
#endif
F_53 ( & V_15 , 31 ) ;
if ( V_146 != - 1 )
F_27 ( & V_15 , V_215 , F_23 () , V_146 ) ;
else
F_50 ( & V_15 ) ;
#endif
if ( V_15 >= V_220 )
F_55 ( L_27 ) ;
F_125 ( V_191 , V_190 ) ;
F_19 ( L_28 ,
( unsigned int ) ( V_15 - V_221 ) ) ;
F_22 ( L_29 , V_221 ,
V_219 ) ;
}
static void
F_138 ( T_3 * * V_15 , unsigned int V_130 , unsigned int V_134 )
{
#ifdef F_77
# ifdef F_65
if ( V_223 )
F_139 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_140 ( V_15 , V_130 , 0 , V_134 ) ;
#else
# ifdef F_65
if ( V_223 )
F_91 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_39 ( V_15 , V_130 , 0 , V_134 ) ;
#endif
}
static void
F_141 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_130 , unsigned int V_134 ,
unsigned int V_155 , unsigned int V_187 )
{
unsigned int V_224 = V_155 & ( V_225 | V_226 ) ;
unsigned int V_227 = V_155 & ~ V_224 ;
if ( F_106 ( V_178 ) && ! V_223 ) {
F_42 ( V_15 , V_187 , V_227 >> 16 ) ;
F_117 ( V_15 , V_130 , V_130 , V_187 ) ;
F_80 ( V_227 & 0xffff ) ;
} else {
F_68 ( V_15 , V_130 , V_130 , V_155 ) ;
}
#ifdef F_77
# ifdef F_65
if ( V_223 )
F_142 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_78 ( V_15 , V_130 , 0 , V_134 ) ;
if ( F_5 () )
F_143 ( V_15 , V_17 , V_130 , V_228 ) ;
else
F_79 ( V_15 , V_17 , V_130 , V_228 ) ;
# ifdef F_65
if ( ! V_223 ) {
F_144 ( V_15 , V_130 , sizeof( V_175 ) / 2 , V_134 ) ;
F_68 ( V_15 , V_130 , V_130 , V_224 ) ;
F_80 ( V_224 & ~ 0xffff ) ;
F_145 ( V_15 , V_130 , sizeof( V_175 ) / 2 , V_134 ) ;
F_79 ( V_15 , V_17 , V_130 , V_228 ) ;
F_44 ( V_15 , V_130 , 0 , V_134 ) ;
} else
F_50 ( V_15 ) ;
# else
F_50 ( V_15 ) ;
# endif
#else
# ifdef F_65
if ( V_223 )
F_146 ( V_15 , V_130 , 0 , V_134 ) ;
else
# endif
F_35 ( V_15 , V_130 , 0 , V_134 ) ;
# ifdef F_65
if ( ! V_223 ) {
F_44 ( V_15 , V_130 , sizeof( V_175 ) / 2 , V_134 ) ;
F_68 ( V_15 , V_130 , V_130 , V_224 ) ;
F_80 ( V_224 & ~ 0xffff ) ;
F_147 ( V_15 , V_130 , sizeof( V_175 ) / 2 , V_134 ) ;
F_44 ( V_15 , V_130 , 0 , V_134 ) ;
}
# endif
#endif
}
static void
F_148 ( T_3 * * V_15 , struct V_16 * * V_17 ,
int V_130 , int V_134 , int V_187 , enum V_121 V_122 )
{
int V_229 = V_187 >= 0 ? V_187 : V_130 ;
int V_230 = V_130 ;
if ( V_28 ) {
if ( F_6 () ) {
F_149 ( V_15 , V_17 , V_130 , F_32 ( V_231 ) , V_122 ) ;
F_50 ( V_15 ) ;
} else {
if ( V_22 ) {
F_46 ( V_15 , V_229 , V_230 , V_22 ) ;
V_230 = V_229 ;
}
F_49 ( V_15 , V_229 , V_230 , 1 ) ;
F_79 ( V_15 , V_17 , V_229 , V_122 ) ;
if ( V_130 == V_229 )
F_138 ( V_15 , V_130 , V_134 ) ;
}
} else {
if ( V_22 ) {
F_46 ( V_15 , V_229 , V_230 , V_22 ) ;
V_230 = V_229 ;
}
F_49 ( V_15 , V_229 , V_230 ,
( V_231 | V_232 ) >> V_22 ) ;
F_81 ( V_15 , V_229 , V_229 , V_231 >> V_22 ) ;
F_73 ( V_15 , V_17 , V_229 , V_122 ) ;
if ( V_130 == V_229 )
F_138 ( V_15 , V_130 , V_134 ) ;
}
}
static void
F_150 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_130 ,
unsigned int V_134 , unsigned int V_187 )
{
unsigned int V_155 = V_225 | V_233 ;
F_141 ( V_15 , V_17 , V_130 , V_134 , V_155 , V_187 ) ;
}
static void
F_151 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_130 , unsigned int V_134 , int V_187 ,
enum V_121 V_122 )
{
int V_229 = V_187 >= 0 ? V_187 : V_130 ;
int V_230 = V_130 ;
if ( V_22 ) {
F_46 ( V_15 , V_229 , V_230 , V_22 ) ;
V_230 = V_229 ;
}
F_49 ( V_15 , V_229 , V_230 ,
( V_231 | V_234 ) >> V_22 ) ;
F_81 ( V_15 , V_229 , V_229 ,
( V_231 | V_234 ) >> V_22 ) ;
F_73 ( V_15 , V_17 , V_229 , V_122 ) ;
if ( V_130 == V_229 )
F_138 ( V_15 , V_130 , V_134 ) ;
else
F_50 ( V_15 ) ;
}
static void
F_152 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_130 ,
unsigned int V_134 , unsigned int V_187 )
{
unsigned int V_155 = ( V_233 | V_235 | V_225
| V_226 ) ;
F_141 ( V_15 , V_17 , V_130 , V_134 , V_155 , V_187 ) ;
}
static void
F_153 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_130 , unsigned int V_134 , int V_187 ,
enum V_121 V_122 )
{
if ( F_6 () ) {
F_149 ( V_15 , V_17 , V_130 , F_32 ( V_234 ) , V_122 ) ;
F_50 ( V_15 ) ;
} else {
int V_229 = V_187 >= 0 ? V_187 : V_130 ;
F_46 ( V_15 , V_229 , V_130 , V_24 ) ;
F_49 ( V_15 , V_229 , V_229 , 1 ) ;
F_79 ( V_15 , V_17 , V_229 , V_122 ) ;
if ( V_130 == V_229 )
F_138 ( V_15 , V_130 , V_134 ) ;
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
F_41 ( V_15 , V_120 , V_180 ) ;
F_51 ( V_15 , V_130 , V_59 ) ;
F_85 ( V_15 , V_17 , V_120 , V_236 ) ;
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
T_3 * V_15 = V_237 ;
const int V_238 = V_239 - V_237 ;
struct V_20 * V_21 = V_190 ;
struct V_16 * V_17 = V_191 ;
memset ( V_237 , 0 , V_238 * sizeof( V_237 [ 0 ] ) ) ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
F_157 ( & V_15 , V_45 , V_47 ) ;
F_148 ( & V_15 , & V_17 , V_45 , V_47 , - 1 , V_240 ) ;
F_50 ( & V_15 ) ;
F_150 ( & V_15 , & V_17 , V_45 , V_47 , - 1 ) ;
F_155 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 ) ;
F_159 ( & V_21 , V_15 ) ;
F_160 ( & V_15 , ( unsigned long ) V_163 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_239 )
F_55 ( L_30 ) ;
F_125 ( V_191 , V_190 ) ;
F_19 ( L_31 ,
( unsigned int ) ( V_15 - V_237 ) ) ;
F_22 ( L_32 , V_237 , V_238 ) ;
}
static void F_161 ( void )
{
T_3 * V_15 = V_241 ;
const int V_242 = V_243 - V_241 ;
struct V_20 * V_21 = V_190 ;
struct V_16 * V_17 = V_191 ;
memset ( V_241 , 0 , V_242 * sizeof( V_241 [ 0 ] ) ) ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
F_157 ( & V_15 , V_45 , V_47 ) ;
F_151 ( & V_15 , & V_17 , V_45 , V_47 , - 1 , V_244 ) ;
F_50 ( & V_15 ) ;
F_152 ( & V_15 , & V_17 , V_45 , V_47 , - 1 ) ;
F_155 ( & V_15 , & V_21 , & V_17 , V_45 , V_47 ) ;
F_162 ( & V_21 , V_15 ) ;
F_160 ( & V_15 , ( unsigned long ) V_245 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_243 )
F_55 ( L_33 ) ;
F_125 ( V_191 , V_190 ) ;
F_19 ( L_34 ,
( unsigned int ) ( V_15 - V_241 ) ) ;
F_22 ( L_35 , V_241 , V_242 ) ;
}
static void F_163 ( void )
{
T_3 * V_15 = V_246 ;
const int V_247 = V_248 - V_246 ;
struct V_20 * V_21 = V_190 ;
struct V_16 * V_17 = V_191 ;
memset ( V_246 , 0 , V_247 * sizeof( V_246 [ 0 ] ) ) ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
F_157 ( & V_15 , V_45 , V_47 ) ;
F_153 ( & V_15 , & V_17 , V_45 , V_47 , - 1 , V_249 ) ;
F_50 ( & V_15 ) ;
F_152 ( & V_15 , & V_17 , V_45 , V_47 , - 1 ) ;
F_154 ( & V_15 , V_45 , V_47 ) ;
F_164 ( & V_21 , V_15 ) ;
F_160 ( & V_15 , ( unsigned long ) V_245 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_248 )
F_55 ( L_36 ) ;
F_125 ( V_191 , V_190 ) ;
F_19 ( L_37 ,
( unsigned int ) ( V_15 - V_246 ) ) ;
F_22 ( L_38 , V_246 , V_247 ) ;
}
static struct V_42
F_165 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 )
{
struct V_42 V_250 = F_26 ( V_15 ) ;
#ifdef V_195
F_82 ( V_15 , V_21 , V_17 , V_250 . V_44 , V_250 . V_46 ) ;
#else
F_101 ( V_15 , V_250 . V_44 , V_250 . V_46 ) ;
#endif
#ifdef F_20
F_71 ( V_15 , V_17 , V_250 . V_44 , V_250 . V_46 , V_136 ) ;
#endif
F_38 ( V_15 , V_250 . V_44 , V_57 ) ;
F_39 ( V_15 , V_250 . V_46 , 0 , V_250 . V_46 ) ;
F_64 ( V_15 , V_250 . V_44 , V_250 . V_44 , V_144 + V_251 - V_168 ) ;
F_49 ( V_15 , V_250 . V_44 , V_250 . V_44 , ( V_170 - 1 ) << V_168 ) ;
F_34 ( V_15 , V_250 . V_46 , V_250 . V_46 , V_250 . V_44 ) ;
#ifdef F_77
F_166 ( V_21 , * V_15 ) ;
#endif
F_138 ( V_15 , V_250 . V_44 , V_250 . V_46 ) ;
if ( ! F_12 () ) {
F_57 ( V_15 ) ;
if ( V_252 ) {
F_61 ( V_15 ) ;
F_41 ( V_15 , V_250 . V_48 , V_180 ) ;
F_85 ( V_15 , V_17 , V_250 . V_48 , V_127 ) ;
F_50 ( V_15 ) ;
}
}
return V_250 ;
}
static void
F_167 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_120 ,
unsigned int V_134 )
{
F_68 ( V_15 , V_134 , V_134 , sizeof( V_175 ) ) ;
F_81 ( V_15 , V_134 , V_134 , sizeof( V_175 ) ) ;
F_105 ( V_15 , V_120 , V_134 ) ;
F_59 ( V_15 , V_21 , V_17 , V_69 ) ;
F_112 ( V_21 , * V_15 ) ;
F_37 ( V_15 ) ;
F_113 ( V_15 ) ;
#ifdef V_195
F_94 ( V_15 , V_21 , V_17 , V_120 , V_134 , V_160 ) ;
#endif
}
static void F_168 ( void )
{
T_3 * V_15 = ( T_3 * ) F_169 ( ( V_253 ) V_237 ) ;
const int V_238 = V_239 - V_237 ;
struct V_20 * V_21 = V_190 ;
struct V_16 * V_17 = V_191 ;
struct V_42 V_250 ;
memset ( V_237 , 0 , V_238 * sizeof( V_237 [ 0 ] ) ) ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
if ( F_4 () ) {
unsigned int V_197 = 44 ;
F_84 ( & V_15 , V_45 , V_57 ) ;
F_84 ( & V_15 , V_47 , V_139 ) ;
F_115 ( & V_15 , V_45 , V_45 , V_47 ) ;
F_66 ( & V_15 , V_47 , V_45 , 62 ) ;
F_66 ( & V_15 , V_45 , V_45 , 12 + 1 ) ;
F_116 ( & V_15 , V_45 , V_45 , 64 + 12 + 1 - V_197 ) ;
F_117 ( & V_15 , V_45 , V_45 , V_47 ) ;
F_73 ( & V_15 , & V_17 , V_45 , V_127 ) ;
}
V_250 = F_165 ( & V_15 , & V_21 , & V_17 ) ;
F_148 ( & V_15 , & V_17 , V_250 . V_44 , V_250 . V_46 , V_250 . V_48 , V_240 ) ;
if ( F_12 () )
F_57 ( & V_15 ) ;
if ( V_28 && ! V_254 ) {
if ( F_6 () ) {
F_149 ( & V_15 , & V_17 , V_250 . V_44 , F_32 ( V_225 ) ,
V_222 ) ;
} else {
F_49 ( & V_15 , V_250 . V_48 , V_250 . V_44 , V_225 ) ;
F_79 ( & V_15 , & V_17 , V_250 . V_48 , V_222 ) ;
}
F_50 ( & V_15 ) ;
F_170 ( & V_15 ) ;
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
F_171 ( & V_15 , V_250 . V_46 , F_32 ( sizeof( V_175 ) ) , 8 ) ;
} else {
F_49 ( & V_15 , V_250 . V_48 , V_250 . V_46 , sizeof( V_175 ) ) ;
F_172 ( & V_15 , V_250 . V_48 , 8 ) ;
}
F_38 ( & V_15 , V_250 . V_48 , V_59 ) ;
F_38 ( & V_15 , V_250 . V_48 , V_133 ) ;
if ( F_6 () ) {
F_72 ( & V_15 , & V_17 , V_250 . V_48 , 1 , V_240 ) ;
F_50 ( & V_15 ) ;
F_137 ( & V_21 , V_15 ) ;
} else {
F_49 ( & V_15 , V_250 . V_48 , V_250 . V_48 , 2 ) ;
F_73 ( & V_15 , & V_17 , V_250 . V_48 , V_240 ) ;
F_50 ( & V_15 ) ;
}
F_137 ( & V_21 , V_15 ) ;
}
F_150 ( & V_15 , & V_17 , V_250 . V_44 , V_250 . V_46 , V_250 . V_48 ) ;
F_167 ( & V_15 , & V_21 , & V_17 , V_250 . V_44 , V_250 . V_46 ) ;
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
F_138 ( & V_15 , V_250 . V_44 , V_250 . V_46 ) ;
F_148 ( & V_15 , & V_17 , V_250 . V_44 , V_250 . V_46 , V_250 . V_48 , V_240 ) ;
F_57 ( & V_15 ) ;
if ( V_28 && ! V_254 ) {
if ( F_6 () ) {
F_149 ( & V_15 , & V_17 , V_250 . V_44 , F_32 ( V_225 ) ,
V_255 ) ;
} else {
F_49 ( & V_15 , V_250 . V_48 , V_250 . V_44 , V_225 ) ;
F_79 ( & V_15 , & V_17 , V_250 . V_48 , V_255 ) ;
}
F_50 ( & V_15 ) ;
F_170 ( & V_15 ) ;
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
F_171 ( & V_15 , V_250 . V_46 , F_32 ( sizeof( V_175 ) ) , 8 ) ;
} else {
F_49 ( & V_15 , V_250 . V_48 , V_250 . V_46 , sizeof( V_175 ) ) ;
F_172 ( & V_15 , V_250 . V_48 , 8 ) ;
}
F_38 ( & V_15 , V_250 . V_48 , V_59 ) ;
F_38 ( & V_15 , V_250 . V_48 , V_133 ) ;
if ( F_6 () ) {
F_149 ( & V_15 , & V_17 , V_250 . V_48 , 1 , V_255 ) ;
} else {
F_49 ( & V_15 , V_250 . V_48 , V_250 . V_48 , 2 ) ;
F_79 ( & V_15 , & V_17 , V_250 . V_48 , V_255 ) ;
}
if ( V_124 == 0 )
F_50 ( & V_15 ) ;
F_67 ( & V_15 , & V_17 , V_250 . V_48 , V_240 , 0 ) ;
F_173 ( & V_21 , V_15 ) ;
}
F_68 ( & V_15 , V_250 . V_44 , V_250 . V_44 , ( V_233 | V_225 ) ) ;
F_76 ( & V_15 , & V_17 , & V_21 , V_250 . V_44 , V_250 . V_46 , 1 ) ;
#endif
F_159 ( & V_21 , V_15 ) ;
F_37 ( & V_15 ) ;
#ifdef F_174
if ( ( unsigned long ) V_163 & 1 ) {
F_42 ( & V_15 , V_45 , F_43 ( ( long ) V_163 ) ) ;
F_98 ( & V_15 , V_45 , V_45 , F_45 ( ( long ) V_163 ) ) ;
F_53 ( & V_15 , V_45 ) ;
} else
#endif
F_160 ( & V_15 , ( unsigned long ) V_163 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_239 )
F_55 ( L_30 ) ;
F_125 ( V_191 , V_190 ) ;
F_19 ( L_31 ,
( unsigned int ) ( V_15 - V_237 ) ) ;
F_22 ( L_39 , V_237 , V_238 ) ;
}
static void F_175 ( void )
{
T_3 * V_15 = ( T_3 * ) F_169 ( ( V_253 ) V_241 ) ;
const int V_242 = V_243 - V_241 ;
struct V_20 * V_21 = V_190 ;
struct V_16 * V_17 = V_191 ;
struct V_42 V_250 ;
memset ( V_241 , 0 , V_242 * sizeof( V_241 [ 0 ] ) ) ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
V_250 = F_165 ( & V_15 , & V_21 , & V_17 ) ;
F_151 ( & V_15 , & V_17 , V_250 . V_44 , V_250 . V_46 , V_250 . V_48 , V_244 ) ;
if ( F_12 () )
F_57 ( & V_15 ) ;
F_152 ( & V_15 , & V_17 , V_250 . V_44 , V_250 . V_46 , V_250 . V_48 ) ;
F_167 ( & V_15 , & V_21 , & V_17 , V_250 . V_44 , V_250 . V_46 ) ;
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
F_138 ( & V_15 , V_250 . V_44 , V_250 . V_46 ) ;
F_151 ( & V_15 , & V_17 , V_250 . V_44 , V_250 . V_46 , V_250 . V_48 , V_244 ) ;
F_57 ( & V_15 ) ;
F_68 ( & V_15 , V_250 . V_44 , V_250 . V_44 ,
V_233 | V_235 | V_225 | V_226 ) ;
F_76 ( & V_15 , & V_17 , & V_21 , V_250 . V_44 , V_250 . V_46 , 1 ) ;
#endif
F_162 ( & V_21 , V_15 ) ;
F_37 ( & V_15 ) ;
#ifdef F_174
if ( ( unsigned long ) V_245 & 1 ) {
F_42 ( & V_15 , V_45 , F_43 ( ( long ) V_245 ) ) ;
F_98 ( & V_15 , V_45 , V_45 , F_45 ( ( long ) V_245 ) ) ;
F_53 ( & V_15 , V_45 ) ;
} else
#endif
F_160 ( & V_15 , ( unsigned long ) V_245 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_243 )
F_55 ( L_33 ) ;
F_125 ( V_191 , V_190 ) ;
F_19 ( L_34 ,
( unsigned int ) ( V_15 - V_241 ) ) ;
F_22 ( L_40 , V_241 , V_242 ) ;
}
static void F_176 ( void )
{
T_3 * V_15 = ( T_3 * ) F_169 ( ( V_253 ) V_246 ) ;
const int V_247 = V_248 - V_246 ;
struct V_20 * V_21 = V_190 ;
struct V_16 * V_17 = V_191 ;
struct V_42 V_250 ;
memset ( V_246 , 0 , V_247 * sizeof( V_246 [ 0 ] ) ) ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
V_250 = F_165 ( & V_15 , & V_21 , & V_17 ) ;
F_153 ( & V_15 , & V_17 , V_250 . V_44 , V_250 . V_46 , V_250 . V_48 , V_249 ) ;
if ( F_12 () )
F_57 ( & V_15 ) ;
F_152 ( & V_15 , & V_17 , V_250 . V_44 , V_250 . V_46 , V_250 . V_48 ) ;
F_167 ( & V_15 , & V_21 , & V_17 , V_250 . V_44 , V_250 . V_46 ) ;
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
F_138 ( & V_15 , V_250 . V_44 , V_250 . V_46 ) ;
F_153 ( & V_15 , & V_17 , V_250 . V_44 , V_250 . V_46 , V_250 . V_48 , V_249 ) ;
F_57 ( & V_15 ) ;
F_68 ( & V_15 , V_250 . V_44 , V_250 . V_44 ,
V_233 | V_235 | V_225 | V_226 ) ;
F_76 ( & V_15 , & V_17 , & V_21 , V_250 . V_44 , V_250 . V_46 , 0 ) ;
#endif
F_164 ( & V_21 , V_15 ) ;
F_37 ( & V_15 ) ;
#ifdef F_174
if ( ( unsigned long ) V_245 & 1 ) {
F_42 ( & V_15 , V_45 , F_43 ( ( long ) V_245 ) ) ;
F_98 ( & V_15 , V_45 , V_45 , F_45 ( ( long ) V_245 ) ) ;
F_53 ( & V_15 , V_45 ) ;
} else
#endif
F_160 ( & V_15 , ( unsigned long ) V_245 & 0x0fffffff ) ;
F_50 ( & V_15 ) ;
if ( V_15 >= V_248 )
F_55 ( L_36 ) ;
F_125 ( V_191 , V_190 ) ;
F_19 ( L_37 ,
( unsigned int ) ( V_15 - V_246 ) ) ;
F_22 ( L_41 , V_246 , V_247 ) ;
}
static void F_177 ( void )
{
F_56 ( ( unsigned long ) V_237 ,
( unsigned long ) V_239 ) ;
F_56 ( ( unsigned long ) V_241 ,
( unsigned long ) V_243 ) ;
F_56 ( ( unsigned long ) V_246 ,
( unsigned long ) V_248 ) ;
F_56 ( ( unsigned long ) V_221 ,
( unsigned long ) V_220 ) ;
}
static void F_178 ( void )
{
unsigned long V_256 ;
unsigned int V_257 ;
const int V_258 = 2 * sizeof( unsigned long ) ;
V_256 = F_179 () ;
F_19 ( L_42 ,
V_258 , V_256 ,
( V_256 & V_259 ) >> V_260 ,
( V_256 & V_261 ) >> V_262 ,
( V_256 & V_263 ) >> V_264 ,
( V_256 & V_265 ) >> V_266 ,
( V_256 & V_267 ) >> V_268 ) ;
V_256 = F_180 () ;
F_19 ( L_43 ,
V_258 , V_256 ,
( V_256 & V_269 ) >> V_270 ,
( V_256 & V_271 ) >> V_272 ,
( V_256 & V_273 ) >> V_274 ,
( V_256 & V_275 ) >> V_276 ,
( V_256 & V_277 ) >> V_278 ,
( V_256 & V_279 ) >> V_280 ) ;
V_257 = F_181 () ;
F_19 ( L_44 ,
V_257 ,
( V_257 & V_281 ) >> V_282 ,
( V_257 & V_283 ) >> V_284 ,
( V_257 & V_285 ) >> V_286 ,
( V_257 & V_287 ) >> V_288 ,
( V_257 & V_289 ) >> V_290 ,
( V_257 & V_291 ) >> V_292 ,
( V_257 & V_293 ) >> V_294 ) ;
}
static void F_182 ( void )
{
unsigned long V_295 , V_296 , V_297 ;
unsigned int V_256 ;
V_295 = F_179 () ;
V_295 &= ~ V_259 ;
V_295 |= V_142 << V_260 ;
V_295 &= ~ V_265 ;
V_295 |= V_144 << V_266 ;
if ( V_298 >= 3 ) {
V_295 &= ~ V_263 ;
V_295 |= V_151 << V_264 ;
}
V_297 = V_29 << V_268 ;
V_295 |= V_297 ;
F_127 ( V_295 ) ;
F_183 () ;
V_295 = F_179 () ;
if ( ( ( V_295 & V_267 ) << V_268 )
!= V_297 ) {
F_184 ( L_45 ,
V_297 ) ;
V_11 . V_299 &= ~ V_300 ;
return;
}
V_296 = F_32 ( V_150 ) << V_272 ;
V_296 |= F_32 ( V_170 ) << V_278 ;
if ( V_298 >= 3 )
V_296 |= F_32 ( V_152 ) << V_276 ;
if ( F_106 ( V_195 ) )
V_296 |= V_269 ;
V_296 |= ( ( V_168 - V_165 ) << V_280 )
& V_279 ;
F_128 ( V_296 ) ;
F_183 () ;
V_256 = 1 << V_282 ;
if ( F_106 ( V_195 ) )
V_256 |= V_287 ;
F_129 ( V_256 ) ;
F_185 ( L_46 ) ;
F_178 () ;
}
static void F_186 ( void )
{
#ifdef V_178
unsigned int V_301 ;
if ( V_2 ) {
F_185 ( L_47 ) ;
return;
}
V_301 = F_187 () ;
F_188 ( V_301 | V_302 ) ;
F_183 () ;
V_301 = F_187 () ;
if ( V_301 & V_302 )
F_185 ( L_48 ) ;
else
F_55 ( L_49 ) ;
#endif
}
static void F_189 ( void )
{
unsigned long V_303 ;
unsigned V_304 , V_305 ;
if ( ! V_28 || ! V_117 ) {
return;
}
F_190 ( ~ 0ul ) ;
F_183 () ;
V_303 = F_191 () ;
V_303 &= ~ ( ( 1 << V_306 ) - 1 ) ;
V_303 &= ~ ( V_307 | V_308 ) ;
V_304 = F_192 ( V_303 ) + 6 ;
V_305 = F_193 ( int , ( int ) V_309 - V_304 , 0 ) ;
V_305 -= F_194 ( unsigned , V_305 , 2 ) ;
if ( V_305 >= F_32 ( V_117 ) )
V_118 = true ;
F_19 ( L_50 , V_305 ) ;
}
void F_195 ( void )
{
static int V_310 = 0 ;
if ( F_106 ( V_178 ) && ! V_28 )
F_55 ( L_51 ) ;
F_17 () ;
F_189 () ;
#ifdef V_195
V_141 = V_11 . V_311 > ( V_142 + V_143 + V_144 - 3 ) ;
#endif
switch ( F_7 () ) {
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
#ifndef F_83
if ( V_319 )
F_40 () ;
if ( ! V_310 ) {
if ( ! V_319 )
F_40 () ;
F_134 () ;
F_158 () ;
F_161 () ;
F_163 () ;
F_177 () ;
V_310 ++ ;
}
#else
F_55 ( L_52 ) ;
#endif
break;
case V_320 :
case V_321 :
F_55 ( L_53 ) ;
break;
case V_322 :
F_55 ( L_54 ) ;
break;
default:
if ( V_147 )
F_126 () ;
if ( ! V_310 ) {
V_43 = F_24 () ;
F_134 () ;
F_168 () ;
F_175 () ;
F_176 () ;
if ( V_147 )
F_131 () ;
else if ( ! V_319 )
F_114 () ;
F_177 () ;
V_310 ++ ;
}
if ( V_319 )
F_114 () ;
if ( V_179 )
F_186 () ;
if ( V_252 )
F_182 () ;
}
}
