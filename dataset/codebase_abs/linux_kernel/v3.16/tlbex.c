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
if ( V_42 >= 0 ) {
F_27 ( V_13 , 1 , F_23 () , V_42 ) ;
V_15 . V_43 = V_44 ;
V_15 . V_45 = V_46 ;
V_15 . V_47 = 1 ;
return V_15 ;
}
if ( F_28 () > 1 ) {
F_29 ( V_13 , V_44 , V_48 ) ;
F_30 ( V_13 , V_44 , V_44 , V_49 ) ;
F_31 ( V_13 , V_44 , V_44 , F_32 ( sizeof( struct V_50 ) ) ) ;
F_33 ( V_13 , V_46 , ( long ) & V_51 ) ;
F_34 ( V_13 , V_44 , V_44 , V_46 ) ;
} else {
F_33 ( V_13 , V_44 , ( long ) & V_51 ) ;
}
F_35 ( V_13 , 1 , F_36 ( struct V_50 , V_37 ) , V_44 ) ;
F_35 ( V_13 , 2 , F_36 ( struct V_50 , V_52 ) , V_44 ) ;
V_15 . V_43 = V_46 ;
V_15 . V_45 = 1 ;
V_15 . V_47 = 2 ;
return V_15 ;
}
static void F_37 ( T_2 * * V_13 )
{
if ( V_42 >= 0 ) {
F_38 ( V_13 , 1 , F_23 () , V_42 ) ;
return;
}
F_39 ( V_13 , 1 , F_36 ( struct V_50 , V_37 ) , V_44 ) ;
F_39 ( V_13 , 2 , F_36 ( struct V_50 , V_52 ) , V_44 ) ;
}
static void F_40 ( void )
{
long V_53 = ( long ) V_54 ;
T_2 * V_13 ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
V_13 = V_55 ;
F_41 ( & V_13 , V_44 , V_56 ) ;
F_42 ( & V_13 , V_46 , F_43 ( V_53 ) ) ;
F_44 ( & V_13 , V_46 , F_45 ( V_53 ) , V_46 ) ;
F_46 ( & V_13 , V_44 , V_44 , 22 ) ;
F_47 ( & V_13 , V_44 , V_44 , 2 ) ;
F_48 ( & V_13 , V_46 , V_46 , V_44 ) ;
F_41 ( & V_13 , V_44 , V_57 ) ;
F_44 ( & V_13 , V_46 , 0 , V_46 ) ;
F_49 ( & V_13 , V_44 , V_44 , 0xffc ) ;
F_48 ( & V_13 , V_46 , V_46 , V_44 ) ;
F_44 ( & V_13 , V_44 , 0 , V_46 ) ;
F_50 ( & V_13 ) ;
F_51 ( & V_13 , V_44 , V_58 ) ;
F_41 ( & V_13 , V_46 , V_59 ) ;
F_52 ( & V_13 ) ;
F_53 ( & V_13 , V_46 ) ;
F_54 ( & V_13 ) ;
if ( V_13 > V_55 + 32 )
F_55 ( L_23 ) ;
F_18 ( L_24 ,
( unsigned int ) ( V_13 - V_55 ) ) ;
memcpy ( ( void * ) V_60 , V_55 , 0x80 ) ;
F_22 ( L_25 , ( T_2 * ) V_60 , 32 ) ;
}
static void T_1 F_56 ( T_2 * * V_13 )
{
switch ( F_6 () ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
F_50 ( V_13 ) ;
F_57 ( V_13 ) ;
break;
default:
F_57 ( V_13 ) ;
break;
}
}
static void F_58 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 ,
enum V_65 V_66 )
{
void (* F_59)( T_2 * * ) = NULL ;
switch ( V_66 ) {
case V_67 : F_59 = F_52 ; break;
case V_68 : F_59 = V_69 ; break;
}
if ( V_70 ) {
switch ( F_6 () ) {
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
break;
default:
F_60 ( V_13 ) ;
break;
}
F_59 ( V_13 ) ;
return;
}
switch ( F_6 () ) {
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
F_12 ( V_13 , V_15 , V_83 ) ;
F_59 ( V_13 ) ;
F_14 ( V_19 , V_13 , V_83 ) ;
V_83 ++ ;
F_50 ( V_13 ) ;
break;
case V_61 :
case V_62 :
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
F_50 ( V_13 ) ;
break;
case V_63 :
case V_64 :
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_36 :
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
break;
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_71 :
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
if ( F_11 () )
F_50 ( V_13 ) ;
case V_107 :
F_59 ( V_13 ) ;
break;
case V_108 :
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
break;
case V_114 :
case V_115 :
case V_116 :
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
break;
case V_117 :
F_59 ( V_13 ) ;
F_50 ( V_13 ) ;
break;
default:
F_55 ( L_26 ,
F_6 () ) ;
break;
}
}
static T_1 void F_61 ( T_2 * * V_13 ,
unsigned int V_118 )
{
if ( V_27 ) {
F_62 ( V_13 , V_118 , V_118 , F_32 ( V_119 ) ) ;
} else {
#ifdef F_63
F_64 ( V_13 , V_118 , V_118 , F_32 ( V_119 ) ) ;
#else
F_65 ( V_13 , V_118 , V_118 , F_32 ( V_119 ) ) ;
#endif
}
}
static void F_66 ( T_2 * * V_13 , struct V_14 * * V_15 ,
unsigned int V_120 , enum V_121 V_122 ,
int V_123 )
{
if ( V_123 ) {
if ( V_124 >> 16 ) {
F_42 ( V_13 , V_120 , V_124 >> 16 ) ;
F_67 ( V_13 , V_120 , V_120 , V_124 & 0xffff ) ;
F_51 ( V_13 , V_120 , V_125 ) ;
F_68 ( V_13 , V_15 , V_122 ) ;
} else if ( V_124 ) {
F_67 ( V_13 , V_120 , 0 , V_124 ) ;
F_51 ( V_13 , V_120 , V_125 ) ;
F_68 ( V_13 , V_15 , V_122 ) ;
} else {
F_51 ( V_13 , 0 , V_125 ) ;
F_68 ( V_13 , V_15 , V_122 ) ;
}
if ( V_42 >= 0 )
F_38 ( V_13 , 1 , F_23 () , V_42 ) ;
else
F_39 ( V_13 , 1 , F_9 ( 0 ) , 0 ) ;
} else {
if ( V_124 >> 16 ) {
F_42 ( V_13 , V_120 , V_124 >> 16 ) ;
F_67 ( V_13 , V_120 , V_120 , V_124 & 0xffff ) ;
F_68 ( V_13 , V_15 , V_122 ) ;
F_51 ( V_13 , V_120 , V_125 ) ;
} else if ( V_124 ) {
F_67 ( V_13 , V_120 , 0 , V_124 ) ;
F_68 ( V_13 , V_15 , V_122 ) ;
F_51 ( V_13 , V_120 , V_125 ) ;
} else {
F_68 ( V_13 , V_15 , V_122 ) ;
F_51 ( V_13 , 0 , V_125 ) ;
}
}
}
static void F_69 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 ,
unsigned int V_120 ,
enum V_65 V_66 ,
int V_123 )
{
F_42 ( V_13 , V_120 , V_126 >> 16 ) ;
F_67 ( V_13 , V_120 , V_120 , V_126 & 0xffff ) ;
F_51 ( V_13 , V_120 , V_125 ) ;
F_58 ( V_13 , V_19 , V_15 , V_66 ) ;
F_66 ( V_13 , V_15 , V_120 , V_127 , V_123 ) ;
}
static void
F_70 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_120 ,
unsigned int V_128 , int V_122 )
{
F_39 ( V_13 , V_120 , 0 , V_128 ) ;
if ( F_5 () ) {
F_71 ( V_13 , V_15 , V_120 , F_32 ( V_129 ) , V_122 ) ;
} else {
F_49 ( V_13 , V_120 , V_120 , V_129 ) ;
F_72 ( V_13 , V_15 , V_120 , V_122 ) ;
}
}
static void F_73 ( T_2 * * V_13 , unsigned int V_130 ,
unsigned int V_120 )
{
int V_131 ;
V_131 = ( V_132 >> 7 ) < 0x10000 ;
if ( ! V_131 )
F_42 ( V_13 , V_120 , V_132 >> ( 7 + 16 ) ) ;
F_61 ( V_13 , V_130 ) ;
F_27 ( V_13 , V_130 , V_58 ) ;
if ( V_131 )
F_74 ( V_13 , V_130 , V_130 , V_132 >> 7 ) ;
else
F_34 ( V_13 , V_130 , V_130 , V_120 ) ;
F_27 ( V_13 , V_130 , V_133 ) ;
}
static void F_75 ( T_2 * * V_13 , struct V_14 * * V_15 ,
struct V_18 * * V_19 ,
unsigned int V_130 ,
unsigned int V_134 )
{
#ifdef F_76
F_77 ( V_13 , V_130 , 0 , V_134 ) ;
F_78 ( V_13 , V_15 , V_130 , V_135 ) ;
F_39 ( V_13 , V_130 , 0 , V_134 ) ;
#else
F_35 ( V_13 , V_130 , 0 , V_134 ) ;
#endif
F_73 ( V_13 , V_130 , V_134 ) ;
F_69 ( V_13 , V_19 , V_15 , V_130 , V_68 , 0 ) ;
}
static void
F_79 ( T_2 * * V_13 , struct V_18 * * V_19 , struct V_14 * * V_15 ,
unsigned int V_120 , unsigned int V_134 )
{
#ifndef F_80
long V_53 = ( long ) V_54 ;
#endif
F_81 ( V_13 , V_120 , V_56 ) ;
if ( V_136 ) {
F_64 ( V_13 , V_134 , V_120 , V_137 + V_138 + V_139 - 3 ) ;
F_72 ( V_13 , V_15 , V_134 , V_140 ) ;
} else {
F_82 ( V_13 , V_15 , V_120 , V_140 ) ;
}
if ( V_141 != - 1 ) {
F_38 ( V_13 , V_134 , F_23 () , V_141 ) ;
} else {
#if F_83 ( F_80 )
F_38 ( V_13 , V_134 , V_57 ) ;
F_84 ( V_13 , V_134 , 0 , 0 , 23 ) ;
F_67 ( V_13 , V_134 , V_134 , 0x540 ) ;
F_85 ( V_13 , V_134 , V_134 , 11 ) ;
#elif F_83 ( F_76 )
F_29 ( V_13 , V_134 , V_48 ) ;
F_64 ( V_13 , V_134 , V_134 , V_142 ) ;
F_86 ( V_13 , V_120 , V_53 ) ;
F_87 ( V_13 , V_134 , V_134 , V_120 ) ;
F_81 ( V_13 , V_120 , V_56 ) ;
F_88 ( V_13 , V_134 , F_45 ( V_53 ) , V_134 ) ;
#else
F_86 ( V_13 , V_134 , V_53 ) ;
F_88 ( V_13 , V_134 , F_45 ( V_53 ) , V_134 ) ;
#endif
}
F_89 ( V_19 , * V_13 ) ;
F_64 ( V_13 , V_120 , V_120 , V_137 - 3 ) ;
F_49 ( V_13 , V_120 , V_120 , ( V_143 - 1 ) << 3 ) ;
F_87 ( V_13 , V_134 , V_134 , V_120 ) ;
#ifndef F_90
F_81 ( V_13 , V_120 , V_56 ) ;
F_88 ( V_13 , V_134 , 0 , V_134 ) ;
F_64 ( V_13 , V_120 , V_120 , V_144 - 3 ) ;
F_49 ( V_13 , V_120 , V_120 , ( V_145 - 1 ) << 3 ) ;
F_87 ( V_13 , V_134 , V_134 , V_120 ) ;
#endif
}
static void
F_91 ( T_2 * * V_13 , struct V_18 * * V_19 , struct V_14 * * V_15 ,
unsigned int V_146 , unsigned int V_134 ,
enum V_147 V_148 )
{
long V_149 = ( long ) V_150 ;
int V_151 ;
int V_152 = 0 ;
V_151 = F_92 ( V_149 ) && ! F_45 ( V_149 ) ;
F_93 ( V_19 , * V_13 ) ;
if ( V_148 != V_153 && V_136 ) {
if ( V_151 ) {
F_82 ( V_13 , V_15 , V_146 , V_154 ) ;
F_42 ( V_13 , V_134 , F_43 ( V_149 ) ) ;
V_152 = 1 ;
} else {
F_94 ( V_13 , V_15 , V_146 , V_155 ) ;
}
}
if ( ! V_152 ) {
if ( F_92 ( V_149 ) && ! F_45 ( V_149 ) ) {
F_68 ( V_13 , V_15 , V_154 ) ;
F_42 ( V_13 , V_134 , F_43 ( V_149 ) ) ;
} else {
F_86 ( V_13 , V_134 , V_149 ) ;
F_68 ( V_13 , V_15 , V_154 ) ;
if ( F_92 ( V_149 ) )
F_95 ( V_13 , V_134 , V_134 , F_45 ( V_149 ) ) ;
else
F_96 ( V_13 , V_134 , V_134 , F_45 ( V_149 ) ) ;
}
}
if ( V_148 != V_153 && V_136 ) {
F_97 ( V_19 , * V_13 ) ;
F_33 ( V_13 , V_134 , ( unsigned long ) V_156 ) ;
F_53 ( V_13 , V_134 ) ;
if ( V_148 == V_157 ) {
if ( V_42 >= 0 )
F_38 ( V_13 , 1 , F_23 () , V_42 ) ;
else
F_39 ( V_13 , 1 , F_9 ( 0 ) , 0 ) ;
} else {
F_50 ( V_13 ) ;
}
}
}
static void T_1
F_98 ( T_2 * * V_13 , unsigned int V_120 , unsigned int V_134 )
{
if ( V_141 != - 1 ) {
F_41 ( V_13 , V_134 , F_23 () , V_141 ) ;
F_41 ( V_13 , V_120 , V_56 ) ;
} else {
long V_53 = ( long ) V_54 ;
#ifdef F_76
F_41 ( V_13 , V_134 , V_48 ) ;
F_86 ( V_13 , V_120 , V_53 ) ;
F_46 ( V_13 , V_134 , V_134 , V_142 ) ;
F_48 ( V_13 , V_134 , V_120 , V_134 ) ;
#else
F_86 ( V_13 , V_134 , V_53 ) ;
#endif
F_41 ( V_13 , V_120 , V_56 ) ;
F_44 ( V_13 , V_134 , F_45 ( V_53 ) , V_134 ) ;
}
F_46 ( V_13 , V_120 , V_120 , V_137 ) ;
F_47 ( V_13 , V_120 , V_120 , V_158 ) ;
F_48 ( V_13 , V_134 , V_134 , V_120 ) ;
}
static void F_99 ( T_2 * * V_13 , unsigned int V_159 )
{
unsigned int V_160 = 4 - ( V_161 + 1 ) + V_139 - 12 ;
unsigned int V_162 = ( V_163 / 2 - 1 ) << ( V_161 + 1 ) ;
switch ( F_6 () ) {
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
F_65 ( V_13 , V_159 , V_159 , V_160 ) ;
F_49 ( V_13 , V_159 , V_159 , V_162 ) ;
}
static void F_100 ( T_2 * * V_13 , unsigned int V_120 , unsigned int V_134 )
{
switch ( F_6 () ) {
case V_64 :
F_39 ( V_13 , V_134 , 0 , V_134 ) ;
F_101 ( V_13 , V_120 ) ;
break;
default:
F_101 ( V_13 , V_120 ) ;
F_39 ( V_13 , V_134 , 0 , V_134 ) ;
break;
}
F_99 ( V_13 , V_120 ) ;
F_34 ( V_13 , V_134 , V_134 , V_120 ) ;
}
static void F_102 ( T_2 * * V_13 , unsigned int V_120 , unsigned int V_165 )
{
#ifdef F_63
if ( V_166 ) {
F_88 ( V_13 , V_120 , 0 , V_165 ) ;
F_88 ( V_13 , V_165 , sizeof( V_167 ) , V_165 ) ;
if ( V_27 ) {
F_62 ( V_13 , V_120 , V_120 , F_32 ( V_119 ) ) ;
F_27 ( V_13 , V_120 , V_58 ) ;
F_62 ( V_13 , V_165 , V_165 , F_32 ( V_119 ) ) ;
} else {
F_64 ( V_13 , V_120 , V_120 , F_32 ( V_119 ) ) ;
F_27 ( V_13 , V_120 , V_58 ) ;
F_64 ( V_13 , V_165 , V_165 , F_32 ( V_119 ) ) ;
}
F_27 ( V_13 , V_165 , V_133 ) ;
} else {
int V_168 = sizeof( V_167 ) / 2 ;
int V_169 = V_168 + sizeof( V_167 ) ;
F_44 ( V_13 , V_120 , V_168 , V_165 ) ;
F_27 ( V_13 , V_120 , V_58 ) ;
F_44 ( V_13 , V_165 , V_169 , V_165 ) ;
F_27 ( V_13 , V_165 , V_133 ) ;
}
#else
F_39 ( V_13 , V_120 , 0 , V_165 ) ;
F_39 ( V_13 , V_165 , sizeof( V_167 ) , V_165 ) ;
if ( F_1 () )
F_56 ( V_13 ) ;
if ( V_27 ) {
F_62 ( V_13 , V_120 , V_120 , F_32 ( V_119 ) ) ;
if ( F_2 () )
F_27 ( V_13 , 0 , V_58 ) ;
F_27 ( V_13 , V_120 , V_58 ) ;
F_62 ( V_13 , V_165 , V_165 , F_32 ( V_119 ) ) ;
} else {
F_65 ( V_13 , V_120 , V_120 , F_32 ( V_119 ) ) ;
if ( F_2 () )
F_27 ( V_13 , 0 , V_58 ) ;
F_27 ( V_13 , V_120 , V_58 ) ;
F_65 ( V_13 , V_165 , V_165 , F_32 ( V_119 ) ) ;
if ( F_1 () )
F_41 ( V_13 , V_120 , V_170 ) ;
}
if ( F_2 () )
F_27 ( V_13 , 0 , V_133 ) ;
F_27 ( V_13 , V_165 , V_133 ) ;
#endif
}
static struct V_171
F_103 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 , unsigned int V_120 ,
unsigned int V_134 , int V_172 )
{
struct V_171 V_173 ;
unsigned int V_174 , V_175 ;
int V_176 = 0 ;
const int V_177 = 1 ;
V_173 . V_178 = V_177 ;
V_173 . V_123 = 0 ;
if ( V_136 ) {
F_38 ( V_13 , V_120 , V_56 ) ;
if ( V_141 != - 1 )
F_38 ( V_13 , V_134 , F_23 () , V_141 ) ;
else
F_38 ( V_13 , V_134 , V_57 ) ;
if ( V_172 >= 0 )
F_27 ( V_13 , V_177 , F_23 () , V_172 ) ;
else
F_35 ( V_13 , V_177 , F_9 ( 0 ) , 0 ) ;
F_64 ( V_13 , V_177 , V_120 ,
V_137 + V_138 + V_139 - 3 ) ;
F_72 ( V_13 , V_15 , V_177 , V_140 ) ;
if ( V_141 == - 1 ) {
V_176 = 1 ;
F_84 ( V_13 , V_134 , 0 , 0 , 23 ) ;
}
} else {
if ( V_141 != - 1 )
F_38 ( V_13 , V_134 , F_23 () , V_141 ) ;
else
F_38 ( V_13 , V_134 , V_57 ) ;
F_38 ( V_13 , V_120 , V_56 ) ;
if ( V_172 >= 0 )
F_27 ( V_13 , V_177 , F_23 () , V_172 ) ;
else
F_35 ( V_13 , V_177 , F_9 ( 0 ) , 0 ) ;
if ( V_141 == - 1 )
F_84 ( V_13 , V_134 , 0 , 0 , 23 ) ;
F_82 ( V_13 , V_15 , V_120 , V_140 ) ;
}
if ( V_141 == - 1 ) {
V_176 = 1 ;
F_67 ( V_13 , V_134 , V_134 , 0x540 ) ;
F_85 ( V_13 , V_134 , V_134 , 11 ) ;
}
#ifdef F_90
#define F_104 scratch
#else
#define F_104 ptr
#endif
if ( ! V_176 )
F_64 ( V_13 , V_177 , V_120 , V_137 - 3 ) ;
F_89 ( V_19 , * V_13 ) ;
if ( V_176 )
F_64 ( V_13 , V_177 , V_120 , V_137 - 3 ) ;
#ifdef F_90
F_101 ( V_13 , V_120 ) ;
#endif
F_49 ( V_13 , V_177 , V_177 , ( V_143 - 1 ) << 3 ) ;
if ( F_7 () ) {
F_105 ( V_13 , F_104 , V_177 , V_134 ) ;
} else {
F_87 ( V_13 , V_134 , V_134 , V_177 ) ;
F_88 ( V_13 , F_104 , 0 , V_134 ) ;
}
#ifndef F_90
F_64 ( V_13 , V_177 , V_120 , V_144 - 3 ) ;
F_49 ( V_13 , V_177 , V_177 , ( V_145 - 1 ) << 3 ) ;
F_101 ( V_13 , V_120 ) ;
if ( F_7 () ) {
F_105 ( V_13 , V_177 , V_177 , V_134 ) ;
} else {
F_87 ( V_13 , V_134 , V_134 , V_177 ) ;
F_39 ( V_13 , V_177 , 0 , V_134 ) ;
}
#endif
F_99 ( V_13 , V_120 ) ;
#ifdef F_19
F_71 ( V_13 , V_15 , V_177 , F_32 ( V_129 ) , V_135 ) ;
if ( F_7 () )
F_50 ( V_13 ) ;
#endif
if ( F_7 () ) {
V_174 = V_134 ;
V_175 = V_120 ;
F_105 ( V_13 , V_174 , V_177 , V_120 ) ;
F_74 ( V_13 , V_120 , V_120 , sizeof( V_167 ) ) ;
F_105 ( V_13 , V_175 , V_177 , V_120 ) ;
} else {
F_34 ( V_13 , V_134 , V_177 , V_120 ) ;
V_174 = V_120 ;
V_175 = V_134 ;
F_39 ( V_13 , V_174 , 0 , V_134 ) ;
F_39 ( V_13 , V_175 , sizeof( V_167 ) , V_134 ) ;
}
if ( V_27 ) {
F_85 ( V_13 , V_174 , V_174 , F_32 ( V_119 ) ) ;
F_27 ( V_13 , V_174 , V_58 ) ;
F_85 ( V_13 , V_175 , V_175 , F_32 ( V_119 ) ) ;
} else {
F_64 ( V_13 , V_174 , V_174 , F_32 ( V_119 ) ) ;
F_27 ( V_13 , V_174 , V_58 ) ;
F_64 ( V_13 , V_175 , V_175 , F_32 ( V_119 ) ) ;
}
F_27 ( V_13 , V_175 , V_133 ) ;
if ( V_172 >= 0 ) {
F_38 ( V_13 , V_177 , F_23 () , V_172 ) ;
F_58 ( V_13 , V_19 , V_15 , V_67 ) ;
F_106 ( V_19 , * V_13 ) ;
V_173 . V_123 = 1 ;
} else if ( V_139 == 14 || V_139 == 13 ) {
F_58 ( V_13 , V_19 , V_15 , V_67 ) ;
F_106 ( V_19 , * V_13 ) ;
F_39 ( V_13 , V_177 , F_9 ( 0 ) , 0 ) ;
} else {
F_39 ( V_13 , V_177 , F_9 ( 0 ) , 0 ) ;
F_58 ( V_13 , V_19 , V_15 , V_67 ) ;
F_106 ( V_19 , * V_13 ) ;
V_173 . V_123 = 1 ;
}
F_107 ( V_13 ) ;
return V_173 ;
}
static void F_108 ( void )
{
T_2 * V_13 = V_55 ;
struct V_18 * V_19 = V_179 ;
struct V_14 * V_15 = V_180 ;
T_2 * V_181 ;
unsigned int V_182 ;
struct V_171 T_4 T_1 ;
enum V_147 T_5 T_1 ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
if ( F_109 ( V_184 ) && ( V_42 >= 0 || F_8 () ) && F_5 () ) {
T_4 = F_103 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 ,
V_42 ) ;
T_5 = V_157 ;
} else {
T_4 . V_178 = V_44 ;
T_4 . V_123 = 0 ;
T_5 = V_185 ;
if ( F_3 () ) {
unsigned int V_186 = 44 ;
F_81 ( & V_13 , V_44 , V_56 ) ;
F_81 ( & V_13 , V_46 , V_187 ) ;
F_110 ( & V_13 , V_44 , V_44 , V_46 ) ;
F_64 ( & V_13 , V_46 , V_44 , 62 ) ;
F_64 ( & V_13 , V_44 , V_44 , 12 + 1 ) ;
F_111 ( & V_13 , V_44 , V_44 , 64 + 12 + 1 - V_186 ) ;
F_112 ( & V_13 , V_44 , V_44 , V_46 ) ;
F_72 ( & V_13 , & V_15 , V_44 , V_127 ) ;
}
#ifdef V_184
F_79 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 ) ;
#else
F_98 ( & V_13 , V_44 , V_46 ) ;
#endif
#ifdef F_19
F_70 ( & V_13 , & V_15 , V_44 , V_46 , V_135 ) ;
#endif
F_100 ( & V_13 , V_44 , V_46 ) ;
F_102 ( & V_13 , V_44 , V_46 ) ;
F_58 ( & V_13 , & V_19 , & V_15 , V_67 ) ;
F_106 ( & V_19 , V_13 ) ;
F_107 ( & V_13 ) ;
}
#ifdef F_19
F_113 ( & V_19 , V_13 ) ;
F_73 ( & V_13 , T_4 . V_178 , V_46 ) ;
F_69 ( & V_13 , & V_19 , & V_15 , V_44 , V_67 ,
T_4 . V_123 ) ;
#endif
#ifdef V_184
F_91 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 , T_5 ) ;
#endif
switch ( F_114 () ) {
default:
if ( sizeof( long ) == 4 ) {
case V_104 :
if ( ( V_13 - V_55 ) > 64 )
F_55 ( L_23 ) ;
V_181 = V_183 ;
F_115 ( V_180 , V_179 , V_55 , V_13 , V_181 ) ;
V_182 = V_13 - V_55 ;
break;
} else {
if ( ( ( V_13 - V_55 ) > ( V_188 * 2 ) - 1 )
|| ( ( ( V_13 - V_55 ) > ( V_188 * 2 ) - 3 )
&& F_116 ( V_180 ,
V_55 + V_188 - 3 ) ) )
F_55 ( L_23 ) ;
V_181 = V_183 + V_188 ;
if ( ( V_13 - V_55 ) <= V_188 ) {
F_115 ( V_180 , V_179 , V_55 , V_13 , V_181 ) ;
V_182 = V_13 - V_55 ;
} else {
#ifdef F_19
const enum V_121 V_189 = V_135 ;
#else
const enum V_121 V_189 = V_140 ;
#endif
T_2 * V_190 ;
int V_191 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_117 ( V_179 ) && V_179 [ V_7 ] . V_192 != V_189 ; V_7 ++ )
;
F_118 ( V_7 == F_117 ( V_179 ) ) ;
V_190 = V_179 [ V_7 ] . V_193 ;
if ( V_190 > V_55 + V_188 ||
V_190 < V_13 - V_188 )
V_191 = 1 ;
if ( V_191 ) {
V_190 = V_55 + V_188 - 2 ;
if ( F_116 ( V_180 , V_190 - 1 ) )
V_190 -- ;
}
F_115 ( V_180 , V_179 , V_55 , V_190 , V_181 ) ;
V_181 += V_190 - V_55 ;
if ( V_191 ) {
F_119 ( & V_19 , V_183 ) ;
F_68 ( & V_181 , & V_15 , V_194 ) ;
if ( F_116 ( V_180 , V_190 ) )
F_50 ( & V_181 ) ;
else {
F_115 ( V_180 , V_179 ,
V_190 , V_190 + 1 , V_181 ) ;
F_120 ( V_179 , V_181 , V_181 + 1 , - 1 ) ;
V_181 ++ ;
V_190 ++ ;
}
}
F_115 ( V_180 , V_179 , V_190 , V_13 , V_183 ) ;
V_182 = ( V_181 - ( V_183 + V_188 ) ) +
( V_13 - V_190 ) ;
}
}
break;
}
F_121 ( V_180 , V_179 ) ;
F_18 ( L_24 ,
V_182 ) ;
memcpy ( ( void * ) V_60 , V_183 , 0x100 ) ;
F_22 ( L_27 , ( T_2 * ) V_60 , 64 ) ;
}
static void F_122 ( void )
{
const int V_195 = 4 ;
const int T_1 V_196 = 5 ;
const int T_1 V_197 = 6 ;
T_2 * V_13 = V_198 ;
const int V_199 =
V_200 - V_198 ;
#ifndef F_80
long V_53 = ( long ) V_54 ;
#endif
memset ( V_201 , 0 , V_199 *
sizeof( V_201 [ 0 ] ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
V_141 = F_24 () ;
#ifdef F_80
if ( V_141 == - 1 ) {
struct V_18 * V_19 = V_179 ;
struct V_14 * V_15 = V_180 ;
F_123 ( & V_13 , V_196 , V_195 , 29 ) ;
F_74 ( & V_13 , V_196 , V_196 , 4 ) ;
F_72 ( & V_13 , & V_15 , V_196 , V_202 ) ;
F_50 ( & V_13 ) ;
F_124 ( & V_13 , V_195 , 0 , 29 , 64 - 29 ) ;
F_125 ( & V_19 , V_13 ) ;
F_31 ( & V_13 , V_195 , V_195 , 11 ) ;
F_53 ( & V_13 , 31 ) ;
F_27 ( & V_13 , V_195 , V_57 ) ;
} else {
F_53 ( & V_13 , 31 ) ;
F_27 ( & V_13 , V_195 , F_23 () , V_141 ) ;
}
#else
#ifdef F_76
F_29 ( & V_13 , V_196 , V_48 ) ;
F_30 ( & V_13 , V_196 , V_196 , V_142 ) ;
F_86 ( & V_13 , V_197 , V_53 ) ;
F_34 ( & V_13 , V_197 , V_197 , V_196 ) ;
F_35 ( & V_13 , V_195 , F_45 ( V_53 ) , V_197 ) ;
#else
F_86 ( & V_13 , V_197 , V_53 ) ;
F_35 ( & V_13 , V_195 , F_45 ( V_53 ) , V_197 ) ;
#endif
F_53 ( & V_13 , 31 ) ;
if ( V_141 != - 1 )
F_27 ( & V_13 , V_195 , F_23 () , V_141 ) ;
else
F_50 ( & V_13 ) ;
#endif
if ( V_13 >= V_200 )
F_55 ( L_28 ) ;
F_121 ( V_180 , V_179 ) ;
F_18 ( L_29 ,
( unsigned int ) ( V_13 - V_201 ) ) ;
F_22 ( L_30 , V_201 ,
V_199 ) ;
}
static void
F_126 ( T_2 * * V_13 , unsigned int V_130 , unsigned int V_134 )
{
#ifdef F_76
# ifdef F_63
if ( V_166 )
F_127 ( V_13 , V_130 , 0 , V_134 ) ;
else
# endif
F_128 ( V_13 , V_130 , 0 , V_134 ) ;
#else
# ifdef F_63
if ( V_166 )
F_88 ( V_13 , V_130 , 0 , V_134 ) ;
else
# endif
F_39 ( V_13 , V_130 , 0 , V_134 ) ;
#endif
}
static void
F_129 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_130 , unsigned int V_134 ,
unsigned int V_148 )
{
#ifdef F_63
unsigned int V_203 = V_148 & ( V_204 | V_205 ) ;
#endif
F_67 ( V_13 , V_130 , V_130 , V_148 ) ;
#ifdef F_76
# ifdef F_63
if ( V_166 )
F_130 ( V_13 , V_130 , 0 , V_134 ) ;
else
# endif
F_77 ( V_13 , V_130 , 0 , V_134 ) ;
if ( F_4 () )
F_131 ( V_13 , V_15 , V_130 , V_206 ) ;
else
F_78 ( V_13 , V_15 , V_130 , V_206 ) ;
# ifdef F_63
if ( ! V_166 ) {
F_132 ( V_13 , V_130 , sizeof( V_167 ) / 2 , V_134 ) ;
F_67 ( V_13 , V_130 , V_130 , V_203 ) ;
F_133 ( V_13 , V_130 , sizeof( V_167 ) / 2 , V_134 ) ;
F_78 ( V_13 , V_15 , V_130 , V_206 ) ;
F_44 ( V_13 , V_130 , 0 , V_134 ) ;
} else
F_50 ( V_13 ) ;
# else
F_50 ( V_13 ) ;
# endif
#else
# ifdef F_63
if ( V_166 )
F_134 ( V_13 , V_130 , 0 , V_134 ) ;
else
# endif
F_35 ( V_13 , V_130 , 0 , V_134 ) ;
# ifdef F_63
if ( ! V_166 ) {
F_44 ( V_13 , V_130 , sizeof( V_167 ) / 2 , V_134 ) ;
F_67 ( V_13 , V_130 , V_130 , V_203 ) ;
F_135 ( V_13 , V_130 , sizeof( V_167 ) / 2 , V_134 ) ;
F_44 ( V_13 , V_130 , 0 , V_134 ) ;
}
# endif
#endif
}
static void
F_136 ( T_2 * * V_13 , struct V_14 * * V_15 ,
int V_130 , int V_134 , int V_177 , enum V_121 V_122 )
{
int V_207 = V_177 >= 0 ? V_177 : V_130 ;
if ( V_27 ) {
if ( F_5 () ) {
F_137 ( V_13 , V_15 , V_130 , F_32 ( V_208 ) , V_122 ) ;
F_50 ( V_13 ) ;
} else {
F_49 ( V_13 , V_207 , V_130 , V_208 ) ;
F_78 ( V_13 , V_15 , V_207 , V_122 ) ;
if ( V_130 == V_207 )
F_126 ( V_13 , V_130 , V_134 ) ;
}
} else {
F_49 ( V_13 , V_207 , V_130 , V_208 | V_209 ) ;
F_138 ( V_13 , V_207 , V_207 , V_208 | V_209 ) ;
F_72 ( V_13 , V_15 , V_207 , V_122 ) ;
if ( V_130 == V_207 )
F_126 ( V_13 , V_130 , V_134 ) ;
}
}
static void
F_139 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_130 ,
unsigned int V_134 )
{
unsigned int V_148 = V_204 | V_210 ;
F_129 ( V_13 , V_15 , V_130 , V_134 , V_148 ) ;
}
static void
F_140 ( T_2 * * V_13 , struct V_14 * * V_15 ,
unsigned int V_130 , unsigned int V_134 , int V_177 ,
enum V_121 V_122 )
{
int V_207 = V_177 >= 0 ? V_177 : V_130 ;
F_49 ( V_13 , V_207 , V_130 , V_208 | V_211 ) ;
F_138 ( V_13 , V_207 , V_207 , V_208 | V_211 ) ;
F_72 ( V_13 , V_15 , V_207 , V_122 ) ;
if ( V_130 == V_207 )
F_126 ( V_13 , V_130 , V_134 ) ;
else
F_50 ( V_13 ) ;
}
static void
F_141 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_130 ,
unsigned int V_134 )
{
unsigned int V_148 = ( V_210 | V_212 | V_204
| V_205 ) ;
F_129 ( V_13 , V_15 , V_130 , V_134 , V_148 ) ;
}
static void
F_142 ( T_2 * * V_13 , struct V_14 * * V_15 ,
unsigned int V_130 , unsigned int V_134 , int V_177 ,
enum V_121 V_122 )
{
if ( F_5 () ) {
F_137 ( V_13 , V_15 , V_130 , F_32 ( V_211 ) , V_122 ) ;
F_50 ( V_13 ) ;
} else {
int V_207 = V_177 >= 0 ? V_177 : V_130 ;
F_49 ( V_13 , V_207 , V_130 , V_211 ) ;
F_78 ( V_13 , V_15 , V_207 , V_122 ) ;
if ( V_130 == V_207 )
F_126 ( V_13 , V_130 , V_134 ) ;
}
}
static void
F_143 ( T_2 * * V_13 , unsigned int V_130 , unsigned int V_120 )
{
F_51 ( V_13 , V_130 , V_58 ) ;
F_41 ( V_13 , V_120 , V_59 ) ;
V_69 ( V_13 ) ;
F_53 ( V_13 , V_120 ) ;
F_54 ( V_13 ) ;
}
static void
F_144 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 , unsigned int V_130 ,
unsigned int V_120 )
{
F_41 ( V_13 , V_120 , V_170 ) ;
F_51 ( V_13 , V_130 , V_58 ) ;
F_82 ( V_13 , V_15 , V_120 , V_213 ) ;
F_41 ( V_13 , V_120 , V_59 ) ;
V_69 ( V_13 ) ;
F_53 ( V_13 , V_120 ) ;
F_54 ( V_13 ) ;
F_145 ( V_19 , * V_13 ) ;
F_52 ( V_13 ) ;
F_53 ( V_13 , V_120 ) ;
F_54 ( V_13 ) ;
}
static void
F_146 ( T_2 * * V_13 , unsigned int V_130 ,
unsigned int V_134 )
{
long V_53 = ( long ) V_54 ;
F_41 ( V_13 , V_130 , V_56 ) ;
F_42 ( V_13 , V_134 , F_43 ( V_53 ) ) ;
F_44 ( V_13 , V_134 , F_45 ( V_53 ) , V_134 ) ;
F_46 ( V_13 , V_130 , V_130 , 22 ) ;
F_47 ( V_13 , V_130 , V_130 , 2 ) ;
F_48 ( V_13 , V_134 , V_134 , V_130 ) ;
F_41 ( V_13 , V_130 , V_57 ) ;
F_44 ( V_13 , V_134 , 0 , V_134 ) ;
F_49 ( V_13 , V_130 , V_130 , 0xffc ) ;
F_48 ( V_13 , V_134 , V_134 , V_130 ) ;
F_44 ( V_13 , V_130 , 0 , V_134 ) ;
F_57 ( V_13 ) ;
}
static void F_147 ( void )
{
T_2 * V_13 = V_214 ;
const int V_215 = V_216 - V_214 ;
struct V_18 * V_19 = V_179 ;
struct V_14 * V_15 = V_180 ;
memset ( V_214 , 0 , V_215 * sizeof( V_214 [ 0 ] ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
F_146 ( & V_13 , V_44 , V_46 ) ;
F_136 ( & V_13 , & V_15 , V_44 , V_46 , - 1 , V_217 ) ;
F_50 ( & V_13 ) ;
F_139 ( & V_13 , & V_15 , V_44 , V_46 ) ;
F_144 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 ) ;
F_148 ( & V_19 , V_13 ) ;
F_149 ( & V_13 , ( unsigned long ) V_156 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_216 )
F_55 ( L_31 ) ;
F_121 ( V_180 , V_179 ) ;
F_18 ( L_32 ,
( unsigned int ) ( V_13 - V_214 ) ) ;
F_22 ( L_33 , V_214 , V_215 ) ;
}
static void F_150 ( void )
{
T_2 * V_13 = V_218 ;
const int V_219 = V_220 - V_218 ;
struct V_18 * V_19 = V_179 ;
struct V_14 * V_15 = V_180 ;
memset ( V_218 , 0 , V_219 * sizeof( V_218 [ 0 ] ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
F_146 ( & V_13 , V_44 , V_46 ) ;
F_140 ( & V_13 , & V_15 , V_44 , V_46 , - 1 , V_221 ) ;
F_50 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_44 , V_46 ) ;
F_144 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 ) ;
F_151 ( & V_19 , V_13 ) ;
F_149 ( & V_13 , ( unsigned long ) V_222 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_220 )
F_55 ( L_34 ) ;
F_121 ( V_180 , V_179 ) ;
F_18 ( L_35 ,
( unsigned int ) ( V_13 - V_218 ) ) ;
F_22 ( L_36 , V_218 , V_219 ) ;
}
static void F_152 ( void )
{
T_2 * V_13 = V_223 ;
const int V_224 = V_225 - V_223 ;
struct V_18 * V_19 = V_179 ;
struct V_14 * V_15 = V_180 ;
memset ( V_223 , 0 , V_224 * sizeof( V_223 [ 0 ] ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
F_146 ( & V_13 , V_44 , V_46 ) ;
F_142 ( & V_13 , & V_15 , V_44 , V_46 , - 1 , V_226 ) ;
F_50 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_44 , V_46 ) ;
F_143 ( & V_13 , V_44 , V_46 ) ;
F_153 ( & V_19 , V_13 ) ;
F_149 ( & V_13 , ( unsigned long ) V_222 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_225 )
F_55 ( L_37 ) ;
F_121 ( V_180 , V_179 ) ;
F_18 ( L_38 ,
( unsigned int ) ( V_13 - V_223 ) ) ;
F_22 ( L_39 , V_223 , V_224 ) ;
}
static struct V_41
F_154 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 )
{
struct V_41 V_227 = F_26 ( V_13 ) ;
#ifdef V_184
F_79 ( V_13 , V_19 , V_15 , V_227 . V_43 , V_227 . V_45 ) ;
#else
F_98 ( V_13 , V_227 . V_43 , V_227 . V_45 ) ;
#endif
#ifdef F_19
F_70 ( V_13 , V_15 , V_227 . V_43 , V_227 . V_45 , V_135 ) ;
#endif
F_38 ( V_13 , V_227 . V_43 , V_56 ) ;
F_39 ( V_13 , V_227 . V_45 , 0 , V_227 . V_45 ) ;
F_65 ( V_13 , V_227 . V_43 , V_227 . V_43 , V_139 + V_228 - V_161 ) ;
F_49 ( V_13 , V_227 . V_43 , V_227 . V_43 , ( V_163 - 1 ) << V_161 ) ;
F_34 ( V_13 , V_227 . V_45 , V_227 . V_45 , V_227 . V_43 ) ;
#ifdef F_76
F_155 ( V_19 , * V_13 ) ;
#endif
F_126 ( V_13 , V_227 . V_43 , V_227 . V_45 ) ;
if ( ! F_11 () )
F_56 ( V_13 ) ;
return V_227 ;
}
static void
F_156 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 , unsigned int V_120 ,
unsigned int V_134 )
{
F_67 ( V_13 , V_134 , V_134 , sizeof( V_167 ) ) ;
F_138 ( V_13 , V_134 , V_134 , sizeof( V_167 ) ) ;
F_102 ( V_13 , V_120 , V_134 ) ;
F_58 ( V_13 , V_19 , V_15 , V_68 ) ;
F_106 ( V_19 , * V_13 ) ;
F_37 ( V_13 ) ;
F_107 ( V_13 ) ;
#ifdef V_184
F_91 ( V_13 , V_19 , V_15 , V_120 , V_134 , V_153 ) ;
#endif
}
static void F_157 ( void )
{
T_2 * V_13 = V_214 ;
const int V_215 = V_216 - V_214 ;
struct V_18 * V_19 = V_179 ;
struct V_14 * V_15 = V_180 ;
struct V_41 V_227 ;
memset ( V_214 , 0 , V_215 * sizeof( V_214 [ 0 ] ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
if ( F_3 () ) {
unsigned int V_186 = 44 ;
F_81 ( & V_13 , V_44 , V_56 ) ;
F_81 ( & V_13 , V_46 , V_187 ) ;
F_110 ( & V_13 , V_44 , V_44 , V_46 ) ;
F_64 ( & V_13 , V_46 , V_44 , 62 ) ;
F_64 ( & V_13 , V_44 , V_44 , 12 + 1 ) ;
F_111 ( & V_13 , V_44 , V_44 , 64 + 12 + 1 - V_186 ) ;
F_112 ( & V_13 , V_44 , V_44 , V_46 ) ;
F_72 ( & V_13 , & V_15 , V_44 , V_127 ) ;
}
V_227 = F_154 ( & V_13 , & V_19 , & V_15 ) ;
F_136 ( & V_13 , & V_15 , V_227 . V_43 , V_227 . V_45 , V_227 . V_47 , V_217 ) ;
if ( F_11 () )
F_56 ( & V_13 ) ;
if ( V_27 ) {
if ( F_5 () ) {
F_137 ( & V_13 , & V_15 , V_227 . V_43 , F_32 ( V_204 ) ,
V_202 ) ;
} else {
F_49 ( & V_13 , V_227 . V_47 , V_227 . V_43 , V_204 ) ;
F_78 ( & V_13 , & V_15 , V_227 . V_47 , V_202 ) ;
}
F_50 ( & V_13 ) ;
F_158 ( & V_13 ) ;
switch ( F_6 () ) {
default:
if ( V_70 ) {
F_60 ( & V_13 ) ;
case V_3 :
case V_4 :
case V_5 :
break;
}
}
if ( F_5 () ) {
F_159 ( & V_13 , V_227 . V_45 , F_32 ( sizeof( V_167 ) ) , 8 ) ;
} else {
F_49 ( & V_13 , V_227 . V_47 , V_227 . V_45 , sizeof( V_167 ) ) ;
F_160 ( & V_13 , V_227 . V_47 , 8 ) ;
}
F_38 ( & V_13 , V_227 . V_47 , V_58 ) ;
F_38 ( & V_13 , V_227 . V_47 , V_133 ) ;
if ( F_5 () ) {
F_71 ( & V_13 , & V_15 , V_227 . V_47 , 1 , V_217 ) ;
F_50 ( & V_13 ) ;
F_125 ( & V_19 , V_13 ) ;
} else {
F_49 ( & V_13 , V_227 . V_47 , V_227 . V_47 , 2 ) ;
F_72 ( & V_13 , & V_15 , V_227 . V_47 , V_217 ) ;
F_50 ( & V_13 ) ;
}
F_125 ( & V_19 , V_13 ) ;
}
F_139 ( & V_13 , & V_15 , V_227 . V_43 , V_227 . V_45 ) ;
F_156 ( & V_13 , & V_19 , & V_15 , V_227 . V_43 , V_227 . V_45 ) ;
#ifdef F_19
F_113 ( & V_19 , V_13 ) ;
F_126 ( & V_13 , V_227 . V_43 , V_227 . V_45 ) ;
F_136 ( & V_13 , & V_15 , V_227 . V_43 , V_227 . V_45 , V_227 . V_47 , V_217 ) ;
F_56 ( & V_13 ) ;
if ( V_27 ) {
if ( F_5 () ) {
F_137 ( & V_13 , & V_15 , V_227 . V_43 , F_32 ( V_204 ) ,
V_229 ) ;
} else {
F_49 ( & V_13 , V_227 . V_47 , V_227 . V_43 , V_204 ) ;
F_78 ( & V_13 , & V_15 , V_227 . V_47 , V_229 ) ;
}
F_50 ( & V_13 ) ;
F_158 ( & V_13 ) ;
switch ( F_6 () ) {
default:
if ( V_70 ) {
F_60 ( & V_13 ) ;
case V_3 :
case V_4 :
case V_5 :
break;
}
}
if ( F_5 () ) {
F_159 ( & V_13 , V_227 . V_45 , F_32 ( sizeof( V_167 ) ) , 8 ) ;
} else {
F_49 ( & V_13 , V_227 . V_47 , V_227 . V_45 , sizeof( V_167 ) ) ;
F_160 ( & V_13 , V_227 . V_47 , 8 ) ;
}
F_38 ( & V_13 , V_227 . V_47 , V_58 ) ;
F_38 ( & V_13 , V_227 . V_47 , V_133 ) ;
if ( F_5 () ) {
F_137 ( & V_13 , & V_15 , V_227 . V_47 , 1 , V_229 ) ;
} else {
F_49 ( & V_13 , V_227 . V_47 , V_227 . V_47 , 2 ) ;
F_78 ( & V_13 , & V_15 , V_227 . V_47 , V_229 ) ;
}
if ( V_124 == 0 )
F_50 ( & V_13 ) ;
F_66 ( & V_13 , & V_15 , V_227 . V_47 , V_217 , 0 ) ;
F_161 ( & V_19 , V_13 ) ;
}
F_67 ( & V_13 , V_227 . V_43 , V_227 . V_43 , ( V_210 | V_204 ) ) ;
F_75 ( & V_13 , & V_15 , & V_19 , V_227 . V_43 , V_227 . V_45 ) ;
#endif
F_148 ( & V_19 , V_13 ) ;
F_37 ( & V_13 ) ;
#ifdef F_162
if ( ( unsigned long ) V_156 & 1 ) {
F_42 ( & V_13 , V_44 , F_43 ( ( long ) V_156 ) ) ;
F_95 ( & V_13 , V_44 , V_44 , F_45 ( ( long ) V_156 ) ) ;
F_53 ( & V_13 , V_44 ) ;
} else
#endif
F_149 ( & V_13 , ( unsigned long ) V_156 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_216 )
F_55 ( L_31 ) ;
F_121 ( V_180 , V_179 ) ;
F_18 ( L_32 ,
( unsigned int ) ( V_13 - V_214 ) ) ;
F_22 ( L_40 , V_214 , V_215 ) ;
}
static void F_163 ( void )
{
T_2 * V_13 = V_218 ;
const int V_219 = V_220 - V_218 ;
struct V_18 * V_19 = V_179 ;
struct V_14 * V_15 = V_180 ;
struct V_41 V_227 ;
memset ( V_218 , 0 , V_219 * sizeof( V_218 [ 0 ] ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
V_227 = F_154 ( & V_13 , & V_19 , & V_15 ) ;
F_140 ( & V_13 , & V_15 , V_227 . V_43 , V_227 . V_45 , V_227 . V_47 , V_221 ) ;
if ( F_11 () )
F_56 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_227 . V_43 , V_227 . V_45 ) ;
F_156 ( & V_13 , & V_19 , & V_15 , V_227 . V_43 , V_227 . V_45 ) ;
#ifdef F_19
F_113 ( & V_19 , V_13 ) ;
F_126 ( & V_13 , V_227 . V_43 , V_227 . V_45 ) ;
F_140 ( & V_13 , & V_15 , V_227 . V_43 , V_227 . V_45 , V_227 . V_47 , V_221 ) ;
F_56 ( & V_13 ) ;
F_67 ( & V_13 , V_227 . V_43 , V_227 . V_43 ,
V_210 | V_212 | V_204 | V_205 ) ;
F_75 ( & V_13 , & V_15 , & V_19 , V_227 . V_43 , V_227 . V_45 ) ;
#endif
F_151 ( & V_19 , V_13 ) ;
F_37 ( & V_13 ) ;
#ifdef F_162
if ( ( unsigned long ) V_222 & 1 ) {
F_42 ( & V_13 , V_44 , F_43 ( ( long ) V_222 ) ) ;
F_95 ( & V_13 , V_44 , V_44 , F_45 ( ( long ) V_222 ) ) ;
F_53 ( & V_13 , V_44 ) ;
} else
#endif
F_149 ( & V_13 , ( unsigned long ) V_222 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_220 )
F_55 ( L_34 ) ;
F_121 ( V_180 , V_179 ) ;
F_18 ( L_35 ,
( unsigned int ) ( V_13 - V_218 ) ) ;
F_22 ( L_41 , V_218 , V_219 ) ;
}
static void F_164 ( void )
{
T_2 * V_13 = V_223 ;
const int V_224 = V_225 - V_223 ;
struct V_18 * V_19 = V_179 ;
struct V_14 * V_15 = V_180 ;
struct V_41 V_227 ;
memset ( V_223 , 0 , V_224 * sizeof( V_223 [ 0 ] ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
V_227 = F_154 ( & V_13 , & V_19 , & V_15 ) ;
F_142 ( & V_13 , & V_15 , V_227 . V_43 , V_227 . V_45 , V_227 . V_47 , V_226 ) ;
if ( F_11 () )
F_56 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_227 . V_43 , V_227 . V_45 ) ;
F_156 ( & V_13 , & V_19 , & V_15 , V_227 . V_43 , V_227 . V_45 ) ;
#ifdef F_19
F_113 ( & V_19 , V_13 ) ;
F_126 ( & V_13 , V_227 . V_43 , V_227 . V_45 ) ;
F_142 ( & V_13 , & V_15 , V_227 . V_43 , V_227 . V_45 , V_227 . V_47 , V_226 ) ;
F_56 ( & V_13 ) ;
F_67 ( & V_13 , V_227 . V_43 , V_227 . V_43 ,
V_210 | V_212 | V_204 | V_205 ) ;
F_75 ( & V_13 , & V_15 , & V_19 , V_227 . V_43 , V_227 . V_45 ) ;
#endif
F_153 ( & V_19 , V_13 ) ;
F_37 ( & V_13 ) ;
#ifdef F_162
if ( ( unsigned long ) V_222 & 1 ) {
F_42 ( & V_13 , V_44 , F_43 ( ( long ) V_222 ) ) ;
F_95 ( & V_13 , V_44 , V_44 , F_45 ( ( long ) V_222 ) ) ;
F_53 ( & V_13 , V_44 ) ;
} else
#endif
F_149 ( & V_13 , ( unsigned long ) V_222 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_225 )
F_55 ( L_37 ) ;
F_121 ( V_180 , V_179 ) ;
F_18 ( L_38 ,
( unsigned int ) ( V_13 - V_223 ) ) ;
F_22 ( L_42 , V_223 , V_224 ) ;
}
static void F_165 ( void )
{
F_166 ( ( unsigned long ) V_214 ,
( unsigned long ) V_216 ) ;
F_166 ( ( unsigned long ) V_218 ,
( unsigned long ) V_220 ) ;
F_166 ( ( unsigned long ) V_223 ,
( unsigned long ) V_225 ) ;
F_166 ( ( unsigned long ) V_201 ,
( unsigned long ) V_200 ) ;
}
void F_167 ( void )
{
static int V_230 = 0 ;
F_16 () ;
#ifdef V_184
V_136 = V_9 . V_231 > ( V_137 + V_138 + V_139 - 3 ) ;
#endif
switch ( F_6 () ) {
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
#ifndef F_80
if ( V_239 )
F_40 () ;
if ( ! V_230 ) {
if ( ! V_239 )
F_40 () ;
F_122 () ;
F_147 () ;
F_150 () ;
F_152 () ;
F_165 () ;
V_230 ++ ;
}
#else
F_55 ( L_43 ) ;
#endif
break;
case V_240 :
case V_241 :
F_55 ( L_44 ) ;
break;
case V_242 :
F_55 ( L_45 ) ;
break;
default:
if ( ! V_230 ) {
V_42 = F_24 () ;
F_122 () ;
F_157 () ;
F_163 () ;
F_164 () ;
if ( ! V_239 )
F_108 () ;
F_165 () ;
V_230 ++ ;
}
if ( V_239 )
F_108 () ;
}
}
