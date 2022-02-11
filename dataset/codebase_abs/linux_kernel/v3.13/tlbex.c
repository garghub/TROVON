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
break;
default:
F_60 ( V_13 ) ;
break;
}
F_59 ( V_13 ) ;
return;
}
switch ( F_6 () ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
F_12 ( V_13 , V_15 , V_79 ) ;
F_59 ( V_13 ) ;
F_14 ( V_19 , V_13 , V_79 ) ;
V_79 ++ ;
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
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_36 :
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
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
F_50 ( V_13 ) ;
case V_102 :
F_59 ( V_13 ) ;
break;
case V_103 :
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
F_50 ( V_13 ) ;
F_50 ( V_13 ) ;
F_59 ( V_13 ) ;
break;
case V_112 :
F_59 ( V_13 ) ;
F_50 ( V_13 ) ;
break;
default:
F_55 ( L_26 ,
V_9 . V_113 ) ;
break;
}
}
static T_1 void F_61 ( T_2 * * V_13 ,
unsigned int V_114 )
{
if ( V_27 ) {
F_62 ( V_13 , V_114 , V_114 , F_32 ( V_115 ) ) ;
} else {
#ifdef F_63
F_64 ( V_13 , V_114 , V_114 , F_32 ( V_115 ) ) ;
#else
F_65 ( V_13 , V_114 , V_114 , F_32 ( V_115 ) ) ;
#endif
}
}
static void F_66 ( T_2 * * V_13 , struct V_14 * * V_15 ,
unsigned int V_116 , enum V_117 V_118 ,
int V_119 )
{
if ( V_119 ) {
if ( V_120 >> 16 ) {
F_42 ( V_13 , V_116 , V_120 >> 16 ) ;
F_67 ( V_13 , V_116 , V_116 , V_120 & 0xffff ) ;
F_51 ( V_13 , V_116 , V_121 ) ;
F_68 ( V_13 , V_15 , V_118 ) ;
} else if ( V_120 ) {
F_67 ( V_13 , V_116 , 0 , V_120 ) ;
F_51 ( V_13 , V_116 , V_121 ) ;
F_68 ( V_13 , V_15 , V_118 ) ;
} else {
F_51 ( V_13 , 0 , V_121 ) ;
F_68 ( V_13 , V_15 , V_118 ) ;
}
if ( V_42 >= 0 )
F_38 ( V_13 , 1 , F_23 () , V_42 ) ;
else
F_39 ( V_13 , 1 , F_9 ( 0 ) , 0 ) ;
} else {
if ( V_120 >> 16 ) {
F_42 ( V_13 , V_116 , V_120 >> 16 ) ;
F_67 ( V_13 , V_116 , V_116 , V_120 & 0xffff ) ;
F_68 ( V_13 , V_15 , V_118 ) ;
F_51 ( V_13 , V_116 , V_121 ) ;
} else if ( V_120 ) {
F_67 ( V_13 , V_116 , 0 , V_120 ) ;
F_68 ( V_13 , V_15 , V_118 ) ;
F_51 ( V_13 , V_116 , V_121 ) ;
} else {
F_68 ( V_13 , V_15 , V_118 ) ;
F_51 ( V_13 , 0 , V_121 ) ;
}
}
}
static void F_69 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 ,
unsigned int V_116 ,
enum V_65 V_66 ,
int V_119 )
{
F_42 ( V_13 , V_116 , V_122 >> 16 ) ;
F_67 ( V_13 , V_116 , V_116 , V_122 & 0xffff ) ;
F_51 ( V_13 , V_116 , V_121 ) ;
F_58 ( V_13 , V_19 , V_15 , V_66 ) ;
F_66 ( V_13 , V_15 , V_116 , V_123 , V_119 ) ;
}
static void
F_70 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_116 ,
unsigned int V_124 , int V_118 )
{
F_39 ( V_13 , V_116 , 0 , V_124 ) ;
if ( F_5 () ) {
F_71 ( V_13 , V_15 , V_116 , F_32 ( V_125 ) , V_118 ) ;
} else {
F_49 ( V_13 , V_116 , V_116 , V_125 ) ;
F_72 ( V_13 , V_15 , V_116 , V_118 ) ;
}
}
static void F_73 ( T_2 * * V_13 , unsigned int V_126 ,
unsigned int V_116 )
{
int V_127 ;
V_127 = ( V_128 >> 7 ) < 0x10000 ;
if ( ! V_127 )
F_42 ( V_13 , V_116 , V_128 >> ( 7 + 16 ) ) ;
F_61 ( V_13 , V_126 ) ;
F_27 ( V_13 , V_126 , V_58 ) ;
if ( V_127 )
F_74 ( V_13 , V_126 , V_126 , V_128 >> 7 ) ;
else
F_34 ( V_13 , V_126 , V_126 , V_116 ) ;
F_27 ( V_13 , V_126 , V_129 ) ;
}
static void F_75 ( T_2 * * V_13 , struct V_14 * * V_15 ,
struct V_18 * * V_19 ,
unsigned int V_126 ,
unsigned int V_130 )
{
#ifdef F_76
F_77 ( V_13 , V_126 , 0 , V_130 ) ;
F_78 ( V_13 , V_15 , V_126 , V_131 ) ;
F_39 ( V_13 , V_126 , 0 , V_130 ) ;
#else
F_35 ( V_13 , V_126 , 0 , V_130 ) ;
#endif
F_73 ( V_13 , V_126 , V_130 ) ;
F_69 ( V_13 , V_19 , V_15 , V_126 , V_68 , 0 ) ;
}
static void
F_79 ( T_2 * * V_13 , struct V_18 * * V_19 , struct V_14 * * V_15 ,
unsigned int V_116 , unsigned int V_130 )
{
#ifndef F_80
long V_53 = ( long ) V_54 ;
#endif
F_81 ( V_13 , V_116 , V_56 ) ;
if ( V_132 ) {
F_64 ( V_13 , V_130 , V_116 , V_133 + V_134 + V_135 - 3 ) ;
F_72 ( V_13 , V_15 , V_130 , V_136 ) ;
} else {
F_82 ( V_13 , V_15 , V_116 , V_136 ) ;
}
if ( V_137 != - 1 ) {
F_38 ( V_13 , V_130 , F_23 () , V_137 ) ;
} else {
#if F_83 ( F_80 )
F_38 ( V_13 , V_130 , V_57 ) ;
F_84 ( V_13 , V_130 , 0 , 0 , 23 ) ;
F_67 ( V_13 , V_130 , V_130 , 0x540 ) ;
F_85 ( V_13 , V_130 , V_130 , 11 ) ;
#elif F_83 ( F_76 )
F_29 ( V_13 , V_130 , V_48 ) ;
F_64 ( V_13 , V_130 , V_130 , V_138 ) ;
F_86 ( V_13 , V_116 , V_53 ) ;
F_87 ( V_13 , V_130 , V_130 , V_116 ) ;
F_81 ( V_13 , V_116 , V_56 ) ;
F_88 ( V_13 , V_130 , F_45 ( V_53 ) , V_130 ) ;
#else
F_86 ( V_13 , V_130 , V_53 ) ;
F_88 ( V_13 , V_130 , F_45 ( V_53 ) , V_130 ) ;
#endif
}
F_89 ( V_19 , * V_13 ) ;
F_64 ( V_13 , V_116 , V_116 , V_133 - 3 ) ;
F_49 ( V_13 , V_116 , V_116 , ( V_139 - 1 ) << 3 ) ;
F_87 ( V_13 , V_130 , V_130 , V_116 ) ;
#ifndef F_90
F_81 ( V_13 , V_116 , V_56 ) ;
F_88 ( V_13 , V_130 , 0 , V_130 ) ;
F_64 ( V_13 , V_116 , V_116 , V_140 - 3 ) ;
F_49 ( V_13 , V_116 , V_116 , ( V_141 - 1 ) << 3 ) ;
F_87 ( V_13 , V_130 , V_130 , V_116 ) ;
#endif
}
static void
F_91 ( T_2 * * V_13 , struct V_18 * * V_19 , struct V_14 * * V_15 ,
unsigned int V_142 , unsigned int V_130 ,
enum V_143 V_144 )
{
long V_145 = ( long ) V_146 ;
int V_147 ;
int V_148 = 0 ;
V_147 = F_92 ( V_145 ) && ! F_45 ( V_145 ) ;
F_93 ( V_19 , * V_13 ) ;
if ( V_144 != V_149 && V_132 ) {
if ( V_147 ) {
F_82 ( V_13 , V_15 , V_142 , V_150 ) ;
F_42 ( V_13 , V_130 , F_43 ( V_145 ) ) ;
V_148 = 1 ;
} else {
F_94 ( V_13 , V_15 , V_142 , V_151 ) ;
}
}
if ( ! V_148 ) {
if ( F_92 ( V_145 ) && ! F_45 ( V_145 ) ) {
F_68 ( V_13 , V_15 , V_150 ) ;
F_42 ( V_13 , V_130 , F_43 ( V_145 ) ) ;
} else {
F_86 ( V_13 , V_130 , V_145 ) ;
F_68 ( V_13 , V_15 , V_150 ) ;
if ( F_92 ( V_145 ) )
F_95 ( V_13 , V_130 , V_130 , F_45 ( V_145 ) ) ;
else
F_96 ( V_13 , V_130 , V_130 , F_45 ( V_145 ) ) ;
}
}
if ( V_144 != V_149 && V_132 ) {
F_97 ( V_19 , * V_13 ) ;
F_33 ( V_13 , V_130 , ( unsigned long ) V_152 ) ;
F_53 ( V_13 , V_130 ) ;
if ( V_144 == V_153 ) {
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
F_98 ( T_2 * * V_13 , unsigned int V_116 , unsigned int V_130 )
{
if ( V_137 != - 1 ) {
F_41 ( V_13 , V_130 , F_23 () , V_137 ) ;
F_41 ( V_13 , V_116 , V_56 ) ;
} else {
long V_53 = ( long ) V_54 ;
#ifdef F_76
F_41 ( V_13 , V_130 , V_48 ) ;
F_86 ( V_13 , V_116 , V_53 ) ;
F_46 ( V_13 , V_130 , V_130 , V_138 ) ;
F_48 ( V_13 , V_130 , V_116 , V_130 ) ;
#else
F_86 ( V_13 , V_130 , V_53 ) ;
#endif
F_41 ( V_13 , V_116 , V_56 ) ;
F_44 ( V_13 , V_130 , F_45 ( V_53 ) , V_130 ) ;
}
F_46 ( V_13 , V_116 , V_116 , V_133 ) ;
F_47 ( V_13 , V_116 , V_116 , V_154 ) ;
F_48 ( V_13 , V_130 , V_130 , V_116 ) ;
}
static void F_99 ( T_2 * * V_13 , unsigned int V_155 )
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
F_65 ( V_13 , V_155 , V_155 , V_156 ) ;
F_49 ( V_13 , V_155 , V_155 , V_158 ) ;
}
static void F_100 ( T_2 * * V_13 , unsigned int V_116 , unsigned int V_130 )
{
switch ( F_6 () ) {
case V_64 :
F_39 ( V_13 , V_130 , 0 , V_130 ) ;
F_101 ( V_13 , V_116 ) ;
break;
default:
F_101 ( V_13 , V_116 ) ;
F_39 ( V_13 , V_130 , 0 , V_130 ) ;
break;
}
F_99 ( V_13 , V_116 ) ;
F_34 ( V_13 , V_130 , V_130 , V_116 ) ;
}
static void F_102 ( T_2 * * V_13 , unsigned int V_116 , unsigned int V_161 )
{
#ifdef F_63
if ( V_162 ) {
F_88 ( V_13 , V_116 , 0 , V_161 ) ;
F_88 ( V_13 , V_161 , sizeof( V_163 ) , V_161 ) ;
if ( V_27 ) {
F_62 ( V_13 , V_116 , V_116 , F_32 ( V_115 ) ) ;
F_27 ( V_13 , V_116 , V_58 ) ;
F_62 ( V_13 , V_161 , V_161 , F_32 ( V_115 ) ) ;
} else {
F_64 ( V_13 , V_116 , V_116 , F_32 ( V_115 ) ) ;
F_27 ( V_13 , V_116 , V_58 ) ;
F_64 ( V_13 , V_161 , V_161 , F_32 ( V_115 ) ) ;
}
F_27 ( V_13 , V_161 , V_129 ) ;
} else {
int V_164 = sizeof( V_163 ) / 2 ;
int V_165 = V_164 + sizeof( V_163 ) ;
F_44 ( V_13 , V_116 , V_164 , V_161 ) ;
F_27 ( V_13 , V_116 , V_58 ) ;
F_44 ( V_13 , V_161 , V_165 , V_161 ) ;
F_27 ( V_13 , V_161 , V_129 ) ;
}
#else
F_39 ( V_13 , V_116 , 0 , V_161 ) ;
F_39 ( V_13 , V_161 , sizeof( V_163 ) , V_161 ) ;
if ( F_1 () )
F_56 ( V_13 ) ;
if ( V_27 ) {
F_62 ( V_13 , V_116 , V_116 , F_32 ( V_115 ) ) ;
if ( F_2 () )
F_27 ( V_13 , 0 , V_58 ) ;
F_27 ( V_13 , V_116 , V_58 ) ;
F_62 ( V_13 , V_161 , V_161 , F_32 ( V_115 ) ) ;
} else {
F_65 ( V_13 , V_116 , V_116 , F_32 ( V_115 ) ) ;
if ( F_2 () )
F_27 ( V_13 , 0 , V_58 ) ;
F_27 ( V_13 , V_116 , V_58 ) ;
F_65 ( V_13 , V_161 , V_161 , F_32 ( V_115 ) ) ;
if ( F_1 () )
F_41 ( V_13 , V_116 , V_166 ) ;
}
if ( F_2 () )
F_27 ( V_13 , 0 , V_129 ) ;
F_27 ( V_13 , V_161 , V_129 ) ;
#endif
}
static struct V_167
F_103 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 , unsigned int V_116 ,
unsigned int V_130 , int V_168 )
{
struct V_167 V_169 ;
unsigned int V_170 , V_171 ;
int V_172 = 0 ;
const int V_173 = 1 ;
V_169 . V_174 = V_173 ;
V_169 . V_119 = 0 ;
if ( V_132 ) {
F_38 ( V_13 , V_116 , V_56 ) ;
if ( V_137 != - 1 )
F_38 ( V_13 , V_130 , F_23 () , V_137 ) ;
else
F_38 ( V_13 , V_130 , V_57 ) ;
if ( V_168 >= 0 )
F_27 ( V_13 , V_173 , F_23 () , V_168 ) ;
else
F_35 ( V_13 , V_173 , F_9 ( 0 ) , 0 ) ;
F_64 ( V_13 , V_173 , V_116 ,
V_133 + V_134 + V_135 - 3 ) ;
F_72 ( V_13 , V_15 , V_173 , V_136 ) ;
if ( V_137 == - 1 ) {
V_172 = 1 ;
F_84 ( V_13 , V_130 , 0 , 0 , 23 ) ;
}
} else {
if ( V_137 != - 1 )
F_38 ( V_13 , V_130 , F_23 () , V_137 ) ;
else
F_38 ( V_13 , V_130 , V_57 ) ;
F_38 ( V_13 , V_116 , V_56 ) ;
if ( V_168 >= 0 )
F_27 ( V_13 , V_173 , F_23 () , V_168 ) ;
else
F_35 ( V_13 , V_173 , F_9 ( 0 ) , 0 ) ;
if ( V_137 == - 1 )
F_84 ( V_13 , V_130 , 0 , 0 , 23 ) ;
F_82 ( V_13 , V_15 , V_116 , V_136 ) ;
}
if ( V_137 == - 1 ) {
V_172 = 1 ;
F_67 ( V_13 , V_130 , V_130 , 0x540 ) ;
F_85 ( V_13 , V_130 , V_130 , 11 ) ;
}
#ifdef F_90
#define F_104 scratch
#else
#define F_104 ptr
#endif
if ( ! V_172 )
F_64 ( V_13 , V_173 , V_116 , V_133 - 3 ) ;
F_89 ( V_19 , * V_13 ) ;
if ( V_172 )
F_64 ( V_13 , V_173 , V_116 , V_133 - 3 ) ;
#ifdef F_90
F_101 ( V_13 , V_116 ) ;
#endif
F_49 ( V_13 , V_173 , V_173 , ( V_139 - 1 ) << 3 ) ;
if ( F_7 () ) {
F_105 ( V_13 , F_104 , V_173 , V_130 ) ;
} else {
F_87 ( V_13 , V_130 , V_130 , V_173 ) ;
F_88 ( V_13 , F_104 , 0 , V_130 ) ;
}
#ifndef F_90
F_64 ( V_13 , V_173 , V_116 , V_140 - 3 ) ;
F_49 ( V_13 , V_173 , V_173 , ( V_141 - 1 ) << 3 ) ;
F_101 ( V_13 , V_116 ) ;
if ( F_7 () ) {
F_105 ( V_13 , V_173 , V_173 , V_130 ) ;
} else {
F_87 ( V_13 , V_130 , V_130 , V_173 ) ;
F_39 ( V_13 , V_173 , 0 , V_130 ) ;
}
#endif
F_99 ( V_13 , V_116 ) ;
#ifdef F_19
F_71 ( V_13 , V_15 , V_173 , F_32 ( V_125 ) , V_131 ) ;
if ( F_7 () )
F_50 ( V_13 ) ;
#endif
if ( F_7 () ) {
V_170 = V_130 ;
V_171 = V_116 ;
F_105 ( V_13 , V_170 , V_173 , V_116 ) ;
F_74 ( V_13 , V_116 , V_116 , sizeof( V_163 ) ) ;
F_105 ( V_13 , V_171 , V_173 , V_116 ) ;
} else {
F_34 ( V_13 , V_130 , V_173 , V_116 ) ;
V_170 = V_116 ;
V_171 = V_130 ;
F_39 ( V_13 , V_170 , 0 , V_130 ) ;
F_39 ( V_13 , V_171 , sizeof( V_163 ) , V_130 ) ;
}
if ( V_27 ) {
F_85 ( V_13 , V_170 , V_170 , F_32 ( V_115 ) ) ;
F_27 ( V_13 , V_170 , V_58 ) ;
F_85 ( V_13 , V_171 , V_171 , F_32 ( V_115 ) ) ;
} else {
F_64 ( V_13 , V_170 , V_170 , F_32 ( V_115 ) ) ;
F_27 ( V_13 , V_170 , V_58 ) ;
F_64 ( V_13 , V_171 , V_171 , F_32 ( V_115 ) ) ;
}
F_27 ( V_13 , V_171 , V_129 ) ;
if ( V_168 >= 0 ) {
F_38 ( V_13 , V_173 , F_23 () , V_168 ) ;
F_58 ( V_13 , V_19 , V_15 , V_67 ) ;
F_106 ( V_19 , * V_13 ) ;
V_169 . V_119 = 1 ;
} else if ( V_135 == 14 || V_135 == 13 ) {
F_58 ( V_13 , V_19 , V_15 , V_67 ) ;
F_106 ( V_19 , * V_13 ) ;
F_39 ( V_13 , V_173 , F_9 ( 0 ) , 0 ) ;
} else {
F_39 ( V_13 , V_173 , F_9 ( 0 ) , 0 ) ;
F_58 ( V_13 , V_19 , V_15 , V_67 ) ;
F_106 ( V_19 , * V_13 ) ;
V_169 . V_119 = 1 ;
}
F_107 ( V_13 ) ;
return V_169 ;
}
static void F_108 ( void )
{
T_2 * V_13 = V_55 ;
struct V_18 * V_19 = V_175 ;
struct V_14 * V_15 = V_176 ;
T_2 * V_177 ;
unsigned int V_178 ;
struct V_167 T_4 T_1 ;
enum V_143 T_5 T_1 ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
if ( ( V_42 >= 0 || F_8 () ) && F_5 () ) {
T_4 = F_103 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 ,
V_42 ) ;
T_5 = V_153 ;
} else {
T_4 . V_174 = V_44 ;
T_4 . V_119 = 0 ;
T_5 = V_180 ;
if ( F_3 () ) {
unsigned int V_181 = 44 ;
F_81 ( & V_13 , V_44 , V_56 ) ;
F_81 ( & V_13 , V_46 , V_182 ) ;
F_109 ( & V_13 , V_44 , V_44 , V_46 ) ;
F_64 ( & V_13 , V_46 , V_44 , 62 ) ;
F_64 ( & V_13 , V_44 , V_44 , 12 + 1 ) ;
F_110 ( & V_13 , V_44 , V_44 , 64 + 12 + 1 - V_181 ) ;
F_111 ( & V_13 , V_44 , V_44 , V_46 ) ;
F_72 ( & V_13 , & V_15 , V_44 , V_123 ) ;
}
#ifdef F_112
F_79 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 ) ;
#else
F_98 ( & V_13 , V_44 , V_46 ) ;
#endif
#ifdef F_19
F_70 ( & V_13 , & V_15 , V_44 , V_46 , V_131 ) ;
#endif
F_100 ( & V_13 , V_44 , V_46 ) ;
F_102 ( & V_13 , V_44 , V_46 ) ;
F_58 ( & V_13 , & V_19 , & V_15 , V_67 ) ;
F_106 ( & V_19 , V_13 ) ;
F_107 ( & V_13 ) ;
}
#ifdef F_19
F_113 ( & V_19 , V_13 ) ;
F_73 ( & V_13 , T_4 . V_174 , V_46 ) ;
F_69 ( & V_13 , & V_19 , & V_15 , V_44 , V_67 ,
T_4 . V_119 ) ;
#endif
#ifdef F_112
F_91 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 , T_5 ) ;
#endif
switch ( F_114 () ) {
default:
if ( sizeof( long ) == 4 ) {
case V_100 :
if ( ( V_13 - V_55 ) > 64 )
F_55 ( L_23 ) ;
V_177 = V_179 ;
F_115 ( V_176 , V_175 , V_55 , V_13 , V_177 ) ;
V_178 = V_13 - V_55 ;
break;
} else {
if ( ( ( V_13 - V_55 ) > ( V_183 * 2 ) - 1 )
|| ( ( ( V_13 - V_55 ) > ( V_183 * 2 ) - 3 )
&& F_116 ( V_176 ,
V_55 + V_183 - 3 ) ) )
F_55 ( L_23 ) ;
V_177 = V_179 + V_183 ;
if ( ( V_13 - V_55 ) <= V_183 ) {
F_115 ( V_176 , V_175 , V_55 , V_13 , V_177 ) ;
V_178 = V_13 - V_55 ;
} else {
#ifdef F_19
const enum V_117 V_184 = V_131 ;
#else
const enum V_117 V_184 = V_136 ;
#endif
T_2 * V_185 ;
int V_186 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_117 ( V_175 ) && V_175 [ V_7 ] . V_187 != V_184 ; V_7 ++ )
;
F_118 ( V_7 == F_117 ( V_175 ) ) ;
V_185 = V_175 [ V_7 ] . V_188 ;
if ( V_185 > V_55 + V_183 ||
V_185 < V_13 - V_183 )
V_186 = 1 ;
if ( V_186 ) {
V_185 = V_55 + V_183 - 2 ;
if ( F_116 ( V_176 , V_185 - 1 ) )
V_185 -- ;
}
F_115 ( V_176 , V_175 , V_55 , V_185 , V_177 ) ;
V_177 += V_185 - V_55 ;
if ( V_186 ) {
F_119 ( & V_19 , V_179 ) ;
F_68 ( & V_177 , & V_15 , V_189 ) ;
if ( F_116 ( V_176 , V_185 ) )
F_50 ( & V_177 ) ;
else {
F_115 ( V_176 , V_175 ,
V_185 , V_185 + 1 , V_177 ) ;
F_120 ( V_175 , V_177 , V_177 + 1 , - 1 ) ;
V_177 ++ ;
V_185 ++ ;
}
}
F_115 ( V_176 , V_175 , V_185 , V_13 , V_179 ) ;
V_178 = ( V_177 - ( V_179 + V_183 ) ) +
( V_13 - V_185 ) ;
}
}
break;
}
F_121 ( V_176 , V_175 ) ;
F_18 ( L_24 ,
V_178 ) ;
memcpy ( ( void * ) V_60 , V_179 , 0x100 ) ;
F_22 ( L_27 , ( T_2 * ) V_60 , 64 ) ;
}
static void F_122 ( void )
{
const int V_190 = 4 ;
const int T_1 V_191 = 5 ;
const int T_1 V_192 = 6 ;
T_2 * V_13 = V_193 ;
const int V_194 =
V_195 - V_193 ;
#ifndef F_80
long V_53 = ( long ) V_54 ;
#endif
memset ( V_193 , 0 , V_194 *
sizeof( V_193 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
V_137 = F_24 () ;
#ifdef F_80
if ( V_137 == - 1 ) {
struct V_18 * V_19 = V_175 ;
struct V_14 * V_15 = V_176 ;
F_123 ( & V_13 , V_191 , V_190 , 29 ) ;
F_74 ( & V_13 , V_191 , V_191 , 4 ) ;
F_72 ( & V_13 , & V_15 , V_191 , V_196 ) ;
F_50 ( & V_13 ) ;
F_124 ( & V_13 , V_190 , 0 , 29 , 64 - 29 ) ;
F_125 ( & V_19 , V_13 ) ;
F_31 ( & V_13 , V_190 , V_190 , 11 ) ;
F_53 ( & V_13 , 31 ) ;
F_27 ( & V_13 , V_190 , V_57 ) ;
} else {
F_53 ( & V_13 , 31 ) ;
F_27 ( & V_13 , V_190 , F_23 () , V_137 ) ;
}
#else
#ifdef F_76
F_29 ( & V_13 , V_191 , V_48 ) ;
F_30 ( & V_13 , V_191 , V_191 , V_138 ) ;
F_86 ( & V_13 , V_192 , V_53 ) ;
F_34 ( & V_13 , V_192 , V_192 , V_191 ) ;
F_35 ( & V_13 , V_190 , F_45 ( V_53 ) , V_192 ) ;
#else
F_86 ( & V_13 , V_192 , V_53 ) ;
F_35 ( & V_13 , V_190 , F_45 ( V_53 ) , V_192 ) ;
#endif
F_53 ( & V_13 , 31 ) ;
if ( V_137 != - 1 )
F_27 ( & V_13 , V_190 , F_23 () , V_137 ) ;
else
F_50 ( & V_13 ) ;
#endif
if ( V_13 >= V_195 )
F_55 ( L_28 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_29 ,
( unsigned int ) ( V_13 - V_193 ) ) ;
F_22 ( L_30 , V_193 ,
V_194 ) ;
}
static void
F_126 ( T_2 * * V_13 , unsigned int V_126 , unsigned int V_130 )
{
#ifdef F_76
# ifdef F_63
if ( V_162 )
F_127 ( V_13 , V_126 , 0 , V_130 ) ;
else
# endif
F_128 ( V_13 , V_126 , 0 , V_130 ) ;
#else
# ifdef F_63
if ( V_162 )
F_88 ( V_13 , V_126 , 0 , V_130 ) ;
else
# endif
F_39 ( V_13 , V_126 , 0 , V_130 ) ;
#endif
}
static void
F_129 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_126 , unsigned int V_130 ,
unsigned int V_144 )
{
#ifdef F_63
unsigned int V_197 = V_144 & ( V_198 | V_199 ) ;
#endif
F_67 ( V_13 , V_126 , V_126 , V_144 ) ;
#ifdef F_76
# ifdef F_63
if ( V_162 )
F_130 ( V_13 , V_126 , 0 , V_130 ) ;
else
# endif
F_77 ( V_13 , V_126 , 0 , V_130 ) ;
if ( F_4 () )
F_131 ( V_13 , V_15 , V_126 , V_200 ) ;
else
F_78 ( V_13 , V_15 , V_126 , V_200 ) ;
# ifdef F_63
if ( ! V_162 ) {
F_132 ( V_13 , V_126 , sizeof( V_163 ) / 2 , V_130 ) ;
F_67 ( V_13 , V_126 , V_126 , V_197 ) ;
F_133 ( V_13 , V_126 , sizeof( V_163 ) / 2 , V_130 ) ;
F_78 ( V_13 , V_15 , V_126 , V_200 ) ;
F_44 ( V_13 , V_126 , 0 , V_130 ) ;
} else
F_50 ( V_13 ) ;
# else
F_50 ( V_13 ) ;
# endif
#else
# ifdef F_63
if ( V_162 )
F_134 ( V_13 , V_126 , 0 , V_130 ) ;
else
# endif
F_35 ( V_13 , V_126 , 0 , V_130 ) ;
# ifdef F_63
if ( ! V_162 ) {
F_44 ( V_13 , V_126 , sizeof( V_163 ) / 2 , V_130 ) ;
F_67 ( V_13 , V_126 , V_126 , V_197 ) ;
F_135 ( V_13 , V_126 , sizeof( V_163 ) / 2 , V_130 ) ;
F_44 ( V_13 , V_126 , 0 , V_130 ) ;
}
# endif
#endif
}
static void
F_136 ( T_2 * * V_13 , struct V_14 * * V_15 ,
int V_126 , int V_130 , int V_173 , enum V_117 V_118 )
{
int V_201 = V_173 >= 0 ? V_173 : V_126 ;
if ( V_27 ) {
if ( F_5 () ) {
F_137 ( V_13 , V_15 , V_126 , F_32 ( V_202 ) , V_118 ) ;
F_50 ( V_13 ) ;
} else {
F_49 ( V_13 , V_201 , V_126 , V_202 ) ;
F_78 ( V_13 , V_15 , V_201 , V_118 ) ;
if ( V_126 == V_201 )
F_126 ( V_13 , V_126 , V_130 ) ;
}
} else {
F_49 ( V_13 , V_201 , V_126 , V_202 | V_203 ) ;
F_138 ( V_13 , V_201 , V_201 , V_202 | V_203 ) ;
F_72 ( V_13 , V_15 , V_201 , V_118 ) ;
if ( V_126 == V_201 )
F_126 ( V_13 , V_126 , V_130 ) ;
}
}
static void
F_139 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_126 ,
unsigned int V_130 )
{
unsigned int V_144 = V_198 | V_204 ;
F_129 ( V_13 , V_15 , V_126 , V_130 , V_144 ) ;
}
static void
F_140 ( T_2 * * V_13 , struct V_14 * * V_15 ,
unsigned int V_126 , unsigned int V_130 , int V_173 ,
enum V_117 V_118 )
{
int V_201 = V_173 >= 0 ? V_173 : V_126 ;
F_49 ( V_13 , V_201 , V_126 , V_202 | V_205 ) ;
F_138 ( V_13 , V_201 , V_201 , V_202 | V_205 ) ;
F_72 ( V_13 , V_15 , V_201 , V_118 ) ;
if ( V_126 == V_201 )
F_126 ( V_13 , V_126 , V_130 ) ;
else
F_50 ( V_13 ) ;
}
static void
F_141 ( T_2 * * V_13 , struct V_14 * * V_15 , unsigned int V_126 ,
unsigned int V_130 )
{
unsigned int V_144 = ( V_204 | V_206 | V_198
| V_199 ) ;
F_129 ( V_13 , V_15 , V_126 , V_130 , V_144 ) ;
}
static void
F_142 ( T_2 * * V_13 , struct V_14 * * V_15 ,
unsigned int V_126 , unsigned int V_130 , int V_173 ,
enum V_117 V_118 )
{
if ( F_5 () ) {
F_137 ( V_13 , V_15 , V_126 , F_32 ( V_205 ) , V_118 ) ;
F_50 ( V_13 ) ;
} else {
int V_201 = V_173 >= 0 ? V_173 : V_126 ;
F_49 ( V_13 , V_201 , V_126 , V_205 ) ;
F_78 ( V_13 , V_15 , V_201 , V_118 ) ;
if ( V_126 == V_201 )
F_126 ( V_13 , V_126 , V_130 ) ;
}
}
static void
F_143 ( T_2 * * V_13 , unsigned int V_126 , unsigned int V_116 )
{
F_51 ( V_13 , V_126 , V_58 ) ;
F_41 ( V_13 , V_116 , V_59 ) ;
V_69 ( V_13 ) ;
F_53 ( V_13 , V_116 ) ;
F_54 ( V_13 ) ;
}
static void
F_144 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 , unsigned int V_126 ,
unsigned int V_116 )
{
F_41 ( V_13 , V_116 , V_166 ) ;
F_51 ( V_13 , V_126 , V_58 ) ;
F_82 ( V_13 , V_15 , V_116 , V_207 ) ;
F_41 ( V_13 , V_116 , V_59 ) ;
V_69 ( V_13 ) ;
F_53 ( V_13 , V_116 ) ;
F_54 ( V_13 ) ;
F_145 ( V_19 , * V_13 ) ;
F_52 ( V_13 ) ;
F_53 ( V_13 , V_116 ) ;
F_54 ( V_13 ) ;
}
static void
F_146 ( T_2 * * V_13 , unsigned int V_126 ,
unsigned int V_130 )
{
long V_53 = ( long ) V_54 ;
F_41 ( V_13 , V_126 , V_56 ) ;
F_42 ( V_13 , V_130 , F_43 ( V_53 ) ) ;
F_44 ( V_13 , V_130 , F_45 ( V_53 ) , V_130 ) ;
F_46 ( V_13 , V_126 , V_126 , 22 ) ;
F_47 ( V_13 , V_126 , V_126 , 2 ) ;
F_48 ( V_13 , V_130 , V_130 , V_126 ) ;
F_41 ( V_13 , V_126 , V_57 ) ;
F_44 ( V_13 , V_130 , 0 , V_130 ) ;
F_49 ( V_13 , V_126 , V_126 , 0xffc ) ;
F_48 ( V_13 , V_130 , V_130 , V_126 ) ;
F_44 ( V_13 , V_126 , 0 , V_130 ) ;
F_57 ( V_13 ) ;
}
static void F_147 ( void )
{
T_2 * V_13 = V_208 ;
const int V_209 = V_210 - V_208 ;
struct V_18 * V_19 = V_175 ;
struct V_14 * V_15 = V_176 ;
memset ( V_208 , 0 , V_209 * sizeof( V_208 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
F_146 ( & V_13 , V_44 , V_46 ) ;
F_136 ( & V_13 , & V_15 , V_44 , V_46 , - 1 , V_211 ) ;
F_50 ( & V_13 ) ;
F_139 ( & V_13 , & V_15 , V_44 , V_46 ) ;
F_144 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 ) ;
F_148 ( & V_19 , V_13 ) ;
F_149 ( & V_13 , ( unsigned long ) V_152 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_210 )
F_55 ( L_31 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_32 ,
( unsigned int ) ( V_13 - V_208 ) ) ;
F_22 ( L_33 , V_208 , V_209 ) ;
}
static void F_150 ( void )
{
T_2 * V_13 = V_212 ;
const int V_213 = V_214 - V_212 ;
struct V_18 * V_19 = V_175 ;
struct V_14 * V_15 = V_176 ;
memset ( V_212 , 0 , V_213 * sizeof( V_212 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
F_146 ( & V_13 , V_44 , V_46 ) ;
F_140 ( & V_13 , & V_15 , V_44 , V_46 , - 1 , V_215 ) ;
F_50 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_44 , V_46 ) ;
F_144 ( & V_13 , & V_19 , & V_15 , V_44 , V_46 ) ;
F_151 ( & V_19 , V_13 ) ;
F_149 ( & V_13 , ( unsigned long ) V_216 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_214 )
F_55 ( L_34 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_35 ,
( unsigned int ) ( V_13 - V_212 ) ) ;
F_22 ( L_36 , V_212 , V_213 ) ;
}
static void F_152 ( void )
{
T_2 * V_13 = V_217 ;
const int V_218 = V_219 - V_217 ;
struct V_18 * V_19 = V_175 ;
struct V_14 * V_15 = V_176 ;
memset ( V_217 , 0 , V_218 * sizeof( V_217 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
F_146 ( & V_13 , V_44 , V_46 ) ;
F_142 ( & V_13 , & V_15 , V_44 , V_46 , - 1 , V_220 ) ;
F_50 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_44 , V_46 ) ;
F_143 ( & V_13 , V_44 , V_46 ) ;
F_153 ( & V_19 , V_13 ) ;
F_149 ( & V_13 , ( unsigned long ) V_216 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_219 )
F_55 ( L_37 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_38 ,
( unsigned int ) ( V_13 - V_217 ) ) ;
F_22 ( L_39 , V_217 , V_218 ) ;
}
static struct V_41
F_154 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 )
{
struct V_41 V_221 = F_26 ( V_13 ) ;
#ifdef F_112
F_79 ( V_13 , V_19 , V_15 , V_221 . V_43 , V_221 . V_45 ) ;
#else
F_98 ( V_13 , V_221 . V_43 , V_221 . V_45 ) ;
#endif
#ifdef F_19
F_70 ( V_13 , V_15 , V_221 . V_43 , V_221 . V_45 , V_131 ) ;
#endif
F_38 ( V_13 , V_221 . V_43 , V_56 ) ;
F_39 ( V_13 , V_221 . V_45 , 0 , V_221 . V_45 ) ;
F_65 ( V_13 , V_221 . V_43 , V_221 . V_43 , V_135 + V_222 - V_157 ) ;
F_49 ( V_13 , V_221 . V_43 , V_221 . V_43 , ( V_159 - 1 ) << V_157 ) ;
F_34 ( V_13 , V_221 . V_45 , V_221 . V_45 , V_221 . V_43 ) ;
#ifdef F_76
F_155 ( V_19 , * V_13 ) ;
#endif
F_126 ( V_13 , V_221 . V_43 , V_221 . V_45 ) ;
if ( ! F_11 () )
F_56 ( V_13 ) ;
return V_221 ;
}
static void
F_156 ( T_2 * * V_13 , struct V_18 * * V_19 ,
struct V_14 * * V_15 , unsigned int V_116 ,
unsigned int V_130 )
{
F_67 ( V_13 , V_130 , V_130 , sizeof( V_163 ) ) ;
F_138 ( V_13 , V_130 , V_130 , sizeof( V_163 ) ) ;
F_102 ( V_13 , V_116 , V_130 ) ;
F_58 ( V_13 , V_19 , V_15 , V_68 ) ;
F_106 ( V_19 , * V_13 ) ;
F_37 ( V_13 ) ;
F_107 ( V_13 ) ;
#ifdef F_112
F_91 ( V_13 , V_19 , V_15 , V_116 , V_130 , V_149 ) ;
#endif
}
static void F_157 ( void )
{
T_2 * V_13 = V_208 ;
const int V_209 = V_210 - V_208 ;
struct V_18 * V_19 = V_175 ;
struct V_14 * V_15 = V_176 ;
struct V_41 V_221 ;
memset ( V_208 , 0 , V_209 * sizeof( V_208 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
if ( F_3 () ) {
unsigned int V_181 = 44 ;
F_81 ( & V_13 , V_44 , V_56 ) ;
F_81 ( & V_13 , V_46 , V_182 ) ;
F_109 ( & V_13 , V_44 , V_44 , V_46 ) ;
F_64 ( & V_13 , V_46 , V_44 , 62 ) ;
F_64 ( & V_13 , V_44 , V_44 , 12 + 1 ) ;
F_110 ( & V_13 , V_44 , V_44 , 64 + 12 + 1 - V_181 ) ;
F_111 ( & V_13 , V_44 , V_44 , V_46 ) ;
F_72 ( & V_13 , & V_15 , V_44 , V_123 ) ;
}
V_221 = F_154 ( & V_13 , & V_19 , & V_15 ) ;
F_136 ( & V_13 , & V_15 , V_221 . V_43 , V_221 . V_45 , V_221 . V_47 , V_211 ) ;
if ( F_11 () )
F_56 ( & V_13 ) ;
if ( V_27 ) {
if ( F_5 () ) {
F_137 ( & V_13 , & V_15 , V_221 . V_43 , F_32 ( V_198 ) ,
V_196 ) ;
} else {
F_49 ( & V_13 , V_221 . V_47 , V_221 . V_43 , V_198 ) ;
F_78 ( & V_13 , & V_15 , V_221 . V_47 , V_196 ) ;
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
F_159 ( & V_13 , V_221 . V_45 , F_32 ( sizeof( V_163 ) ) , 8 ) ;
} else {
F_49 ( & V_13 , V_221 . V_47 , V_221 . V_45 , sizeof( V_163 ) ) ;
F_160 ( & V_13 , V_221 . V_47 , 8 ) ;
}
F_38 ( & V_13 , V_221 . V_47 , V_58 ) ;
F_38 ( & V_13 , V_221 . V_47 , V_129 ) ;
if ( F_5 () ) {
F_71 ( & V_13 , & V_15 , V_221 . V_47 , 1 , V_211 ) ;
F_50 ( & V_13 ) ;
F_125 ( & V_19 , V_13 ) ;
} else {
F_49 ( & V_13 , V_221 . V_47 , V_221 . V_47 , 2 ) ;
F_72 ( & V_13 , & V_15 , V_221 . V_47 , V_211 ) ;
F_50 ( & V_13 ) ;
}
F_125 ( & V_19 , V_13 ) ;
}
F_139 ( & V_13 , & V_15 , V_221 . V_43 , V_221 . V_45 ) ;
F_156 ( & V_13 , & V_19 , & V_15 , V_221 . V_43 , V_221 . V_45 ) ;
#ifdef F_19
F_113 ( & V_19 , V_13 ) ;
F_126 ( & V_13 , V_221 . V_43 , V_221 . V_45 ) ;
F_136 ( & V_13 , & V_15 , V_221 . V_43 , V_221 . V_45 , V_221 . V_47 , V_211 ) ;
F_56 ( & V_13 ) ;
if ( V_27 ) {
if ( F_5 () ) {
F_137 ( & V_13 , & V_15 , V_221 . V_43 , F_32 ( V_198 ) ,
V_223 ) ;
} else {
F_49 ( & V_13 , V_221 . V_47 , V_221 . V_43 , V_198 ) ;
F_78 ( & V_13 , & V_15 , V_221 . V_47 , V_223 ) ;
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
F_159 ( & V_13 , V_221 . V_45 , F_32 ( sizeof( V_163 ) ) , 8 ) ;
} else {
F_49 ( & V_13 , V_221 . V_47 , V_221 . V_45 , sizeof( V_163 ) ) ;
F_160 ( & V_13 , V_221 . V_47 , 8 ) ;
}
F_38 ( & V_13 , V_221 . V_47 , V_58 ) ;
F_38 ( & V_13 , V_221 . V_47 , V_129 ) ;
if ( F_5 () ) {
F_137 ( & V_13 , & V_15 , V_221 . V_47 , 1 , V_223 ) ;
} else {
F_49 ( & V_13 , V_221 . V_47 , V_221 . V_47 , 2 ) ;
F_78 ( & V_13 , & V_15 , V_221 . V_47 , V_223 ) ;
}
if ( V_120 == 0 )
F_50 ( & V_13 ) ;
F_66 ( & V_13 , & V_15 , V_221 . V_47 , V_211 , 0 ) ;
F_161 ( & V_19 , V_13 ) ;
}
F_67 ( & V_13 , V_221 . V_43 , V_221 . V_43 , ( V_204 | V_198 ) ) ;
F_75 ( & V_13 , & V_15 , & V_19 , V_221 . V_43 , V_221 . V_45 ) ;
#endif
F_148 ( & V_19 , V_13 ) ;
F_37 ( & V_13 ) ;
#ifdef F_162
if ( ( unsigned long ) V_152 & 1 ) {
F_42 ( & V_13 , V_44 , F_43 ( ( long ) V_152 ) ) ;
F_95 ( & V_13 , V_44 , V_44 , F_45 ( ( long ) V_152 ) ) ;
F_53 ( & V_13 , V_44 ) ;
} else
#endif
F_149 ( & V_13 , ( unsigned long ) V_152 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_210 )
F_55 ( L_31 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_32 ,
( unsigned int ) ( V_13 - V_208 ) ) ;
F_22 ( L_40 , V_208 , V_209 ) ;
}
static void F_163 ( void )
{
T_2 * V_13 = V_212 ;
const int V_213 = V_214 - V_212 ;
struct V_18 * V_19 = V_175 ;
struct V_14 * V_15 = V_176 ;
struct V_41 V_221 ;
memset ( V_212 , 0 , V_213 * sizeof( V_212 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
V_221 = F_154 ( & V_13 , & V_19 , & V_15 ) ;
F_140 ( & V_13 , & V_15 , V_221 . V_43 , V_221 . V_45 , V_221 . V_47 , V_215 ) ;
if ( F_11 () )
F_56 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_221 . V_43 , V_221 . V_45 ) ;
F_156 ( & V_13 , & V_19 , & V_15 , V_221 . V_43 , V_221 . V_45 ) ;
#ifdef F_19
F_113 ( & V_19 , V_13 ) ;
F_126 ( & V_13 , V_221 . V_43 , V_221 . V_45 ) ;
F_140 ( & V_13 , & V_15 , V_221 . V_43 , V_221 . V_45 , V_221 . V_47 , V_215 ) ;
F_56 ( & V_13 ) ;
F_67 ( & V_13 , V_221 . V_43 , V_221 . V_43 ,
V_204 | V_206 | V_198 | V_199 ) ;
F_75 ( & V_13 , & V_15 , & V_19 , V_221 . V_43 , V_221 . V_45 ) ;
#endif
F_151 ( & V_19 , V_13 ) ;
F_37 ( & V_13 ) ;
#ifdef F_162
if ( ( unsigned long ) V_216 & 1 ) {
F_42 ( & V_13 , V_44 , F_43 ( ( long ) V_216 ) ) ;
F_95 ( & V_13 , V_44 , V_44 , F_45 ( ( long ) V_216 ) ) ;
F_53 ( & V_13 , V_44 ) ;
} else
#endif
F_149 ( & V_13 , ( unsigned long ) V_216 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_214 )
F_55 ( L_34 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_35 ,
( unsigned int ) ( V_13 - V_212 ) ) ;
F_22 ( L_41 , V_212 , V_213 ) ;
}
static void F_164 ( void )
{
T_2 * V_13 = V_217 ;
const int V_218 = V_219 - V_217 ;
struct V_18 * V_19 = V_175 ;
struct V_14 * V_15 = V_176 ;
struct V_41 V_221 ;
memset ( V_217 , 0 , V_218 * sizeof( V_217 [ 0 ] ) ) ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
V_221 = F_154 ( & V_13 , & V_19 , & V_15 ) ;
F_142 ( & V_13 , & V_15 , V_221 . V_43 , V_221 . V_45 , V_221 . V_47 , V_220 ) ;
if ( F_11 () )
F_56 ( & V_13 ) ;
F_141 ( & V_13 , & V_15 , V_221 . V_43 , V_221 . V_45 ) ;
F_156 ( & V_13 , & V_19 , & V_15 , V_221 . V_43 , V_221 . V_45 ) ;
#ifdef F_19
F_113 ( & V_19 , V_13 ) ;
F_126 ( & V_13 , V_221 . V_43 , V_221 . V_45 ) ;
F_142 ( & V_13 , & V_15 , V_221 . V_43 , V_221 . V_45 , V_221 . V_47 , V_220 ) ;
F_56 ( & V_13 ) ;
F_67 ( & V_13 , V_221 . V_43 , V_221 . V_43 ,
V_204 | V_206 | V_198 | V_199 ) ;
F_75 ( & V_13 , & V_15 , & V_19 , V_221 . V_43 , V_221 . V_45 ) ;
#endif
F_153 ( & V_19 , V_13 ) ;
F_37 ( & V_13 ) ;
#ifdef F_162
if ( ( unsigned long ) V_216 & 1 ) {
F_42 ( & V_13 , V_44 , F_43 ( ( long ) V_216 ) ) ;
F_95 ( & V_13 , V_44 , V_44 , F_45 ( ( long ) V_216 ) ) ;
F_53 ( & V_13 , V_44 ) ;
} else
#endif
F_149 ( & V_13 , ( unsigned long ) V_216 & 0x0fffffff ) ;
F_50 ( & V_13 ) ;
if ( V_13 >= V_219 )
F_55 ( L_37 ) ;
F_121 ( V_176 , V_175 ) ;
F_18 ( L_38 ,
( unsigned int ) ( V_13 - V_217 ) ) ;
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
F_166 ( ( unsigned long ) V_193 ,
( unsigned long ) V_195 ) ;
}
void F_167 ( void )
{
static int V_224 = 0 ;
F_16 () ;
#ifdef F_112
V_132 = V_9 . V_225 > ( V_133 + V_134 + V_135 - 3 ) ;
#endif
switch ( F_6 () ) {
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
#ifndef F_80
if ( V_233 )
F_40 () ;
if ( ! V_224 ) {
if ( ! V_233 )
F_40 () ;
F_122 () ;
F_147 () ;
F_150 () ;
F_152 () ;
F_165 () ;
V_224 ++ ;
}
#else
F_55 ( L_43 ) ;
#endif
break;
case V_234 :
case V_235 :
F_55 ( L_44 ) ;
break;
case V_236 :
F_55 ( L_45 ) ;
break;
default:
if ( ! V_224 ) {
V_42 = F_24 () ;
F_122 () ;
F_157 () ;
F_163 () ;
F_164 () ;
if ( ! V_233 )
F_108 () ;
F_165 () ;
V_224 ++ ;
}
if ( V_233 )
F_108 () ;
}
}
