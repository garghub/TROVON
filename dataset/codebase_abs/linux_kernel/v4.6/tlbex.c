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
#if F_21 ( V_28 ) || F_21 ( V_29 )
if ( V_30 ) {
#ifdef F_22
F_18 ( L_10 , F_22 ) ;
F_18 ( L_11 , V_31 ) ;
#endif
}
#endif
F_18 ( L_12 , V_32 ) ;
F_18 ( L_13 , V_33 ) ;
F_18 ( L_14 , V_34 ) ;
F_18 ( L_15 , V_35 ) ;
F_19 ( L_3 ) ;
}
static inline void F_23 ( const char * V_36 , const T_3 * V_37 , int V_38 )
{
int V_9 ;
F_19 ( L_16 , V_36 ) ;
F_19 ( L_17 ) ;
F_19 ( L_18 ) ;
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ )
F_19 ( L_19 , V_37 [ V_9 ] , & V_37 [ V_9 ] ) ;
F_19 ( L_20 ) ;
F_19 ( L_21 , V_36 ) ;
}
static inline int T_2 F_24 ( void )
{
switch ( F_7 () ) {
case V_39 :
case V_40 :
return 22 ;
default:
return 31 ;
}
}
static int F_25 ( void )
{
int V_17 ;
unsigned int V_41 = V_42 [ 0 ] . V_43 & ~ V_44 ;
V_17 = F_26 ( V_41 ) ;
if ( V_17 == 0 )
return - 1 ;
V_17 -- ;
V_44 |= ( 1 << V_17 ) ;
return V_17 ;
}
static struct V_45 F_27 ( T_3 * * V_15 )
{
struct V_45 V_17 ;
if ( V_46 >= 0 ) {
F_28 ( V_15 , 1 , F_24 () , V_46 ) ;
V_17 . V_47 = V_48 ;
V_17 . V_49 = V_50 ;
V_17 . V_51 = 1 ;
return V_17 ;
}
if ( F_29 () > 1 ) {
F_30 ( V_15 , V_48 , V_52 ) ;
F_31 ( V_15 , V_48 , V_48 , V_53 ) ;
F_32 ( V_15 , V_48 , V_48 , F_33 ( sizeof( struct V_54 ) ) ) ;
F_34 ( V_15 , V_50 , ( long ) & V_55 ) ;
F_35 ( V_15 , V_48 , V_48 , V_50 ) ;
} else {
F_34 ( V_15 , V_48 , ( long ) & V_55 ) ;
}
F_36 ( V_15 , 1 , F_37 ( struct V_54 , V_41 ) , V_48 ) ;
F_36 ( V_15 , 2 , F_37 ( struct V_54 , V_56 ) , V_48 ) ;
V_17 . V_47 = V_50 ;
V_17 . V_49 = 1 ;
V_17 . V_51 = 2 ;
return V_17 ;
}
static void F_38 ( T_3 * * V_15 )
{
if ( V_46 >= 0 ) {
F_39 ( V_15 , 1 , F_24 () , V_46 ) ;
return;
}
F_40 ( V_15 , 1 , F_37 ( struct V_54 , V_41 ) , V_48 ) ;
F_40 ( V_15 , 2 , F_37 ( struct V_54 , V_56 ) , V_48 ) ;
}
static void F_41 ( void )
{
long V_57 = ( long ) V_58 ;
T_3 * V_15 ;
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
V_15 = V_59 ;
F_42 ( & V_15 , V_48 , V_60 ) ;
F_43 ( & V_15 , V_50 , F_44 ( V_57 ) ) ;
F_45 ( & V_15 , V_50 , F_46 ( V_57 ) , V_50 ) ;
F_47 ( & V_15 , V_48 , V_48 , 22 ) ;
F_48 ( & V_15 , V_48 , V_48 , 2 ) ;
F_49 ( & V_15 , V_50 , V_50 , V_48 ) ;
F_42 ( & V_15 , V_48 , V_61 ) ;
F_45 ( & V_15 , V_50 , 0 , V_50 ) ;
F_50 ( & V_15 , V_48 , V_48 , 0xffc ) ;
F_49 ( & V_15 , V_50 , V_50 , V_48 ) ;
F_45 ( & V_15 , V_48 , 0 , V_50 ) ;
F_51 ( & V_15 ) ;
F_52 ( & V_15 , V_48 , V_62 ) ;
F_42 ( & V_15 , V_50 , V_63 ) ;
F_53 ( & V_15 ) ;
F_54 ( & V_15 , V_50 ) ;
F_55 ( & V_15 ) ;
if ( V_15 > V_59 + 32 )
F_56 ( L_22 ) ;
F_19 ( L_23 ,
( unsigned int ) ( V_15 - V_59 ) ) ;
memcpy ( ( void * ) V_64 , V_59 , 0x80 ) ;
F_57 ( V_64 , V_64 + 0x80 ) ;
F_23 ( L_24 , ( T_3 * ) V_64 , 32 ) ;
}
static void T_2 F_58 ( T_3 * * V_15 )
{
switch ( F_7 () ) {
case V_65 :
case V_66 :
case V_67 :
case V_68 :
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
enum V_69 V_70 )
{
void (* F_61)( T_3 * * ) = NULL ;
switch ( V_70 ) {
case V_71 : F_61 = F_53 ; break;
case V_72 : F_61 = V_73 ; break;
}
if ( V_74 ) {
if ( V_75 )
F_62 ( V_15 ) ;
F_61 ( V_15 ) ;
return;
}
switch ( F_7 () ) {
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
F_13 ( V_15 , V_17 , V_82 ) ;
F_61 ( V_15 ) ;
F_15 ( V_21 , V_15 , V_82 ) ;
V_82 ++ ;
F_51 ( V_15 ) ;
break;
case V_65 :
case V_66 :
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
F_51 ( V_15 ) ;
break;
case V_67 :
case V_68 :
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
break;
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_40 :
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
break;
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
case V_107 :
if ( F_12 () )
F_51 ( V_15 ) ;
case V_108 :
F_61 ( V_15 ) ;
break;
case V_109 :
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
break;
case V_115 :
case V_116 :
case V_117 :
F_51 ( V_15 ) ;
F_51 ( V_15 ) ;
F_61 ( V_15 ) ;
break;
case V_118 :
F_61 ( V_15 ) ;
F_51 ( V_15 ) ;
break;
default:
F_56 ( L_25 ,
F_7 () ) ;
break;
}
}
static T_2 void F_63 ( T_3 * * V_15 ,
unsigned int V_119 )
{
if ( V_30 && V_120 ) {
if ( V_121 ) {
F_64 ( V_15 , V_119 , V_119 , F_33 ( V_122 ) ) ;
} else {
F_65 ( V_15 , V_119 , V_119 , F_33 ( V_120 ) ) ;
F_64 ( V_15 , V_119 , V_119 ,
F_33 ( V_122 ) - F_33 ( V_120 ) ) ;
}
} else {
#ifdef F_66
F_67 ( V_15 , V_119 , V_119 , F_33 ( V_122 ) ) ;
#else
F_65 ( V_15 , V_119 , V_119 , F_33 ( V_122 ) ) ;
#endif
}
}
static void F_68 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_123 , enum V_124 V_125 ,
int V_126 )
{
if ( V_126 ) {
if ( V_127 >> 16 ) {
F_43 ( V_15 , V_123 , V_127 >> 16 ) ;
F_69 ( V_15 , V_123 , V_123 , V_127 & 0xffff ) ;
F_52 ( V_15 , V_123 , V_128 ) ;
F_70 ( V_15 , V_17 , V_125 ) ;
} else if ( V_127 ) {
F_69 ( V_15 , V_123 , 0 , V_127 ) ;
F_52 ( V_15 , V_123 , V_128 ) ;
F_70 ( V_15 , V_17 , V_125 ) ;
} else {
F_52 ( V_15 , 0 , V_128 ) ;
F_70 ( V_15 , V_17 , V_125 ) ;
}
if ( V_46 >= 0 )
F_39 ( V_15 , 1 , F_24 () , V_46 ) ;
else
F_40 ( V_15 , 1 , F_10 ( 0 ) , 0 ) ;
} else {
if ( V_127 >> 16 ) {
F_43 ( V_15 , V_123 , V_127 >> 16 ) ;
F_69 ( V_15 , V_123 , V_123 , V_127 & 0xffff ) ;
F_70 ( V_15 , V_17 , V_125 ) ;
F_52 ( V_15 , V_123 , V_128 ) ;
} else if ( V_127 ) {
F_69 ( V_15 , V_123 , 0 , V_127 ) ;
F_70 ( V_15 , V_17 , V_125 ) ;
F_52 ( V_15 , V_123 , V_128 ) ;
} else {
F_70 ( V_15 , V_17 , V_125 ) ;
F_52 ( V_15 , 0 , V_128 ) ;
}
}
}
static void F_71 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 ,
unsigned int V_123 ,
enum V_69 V_70 ,
int V_126 )
{
F_43 ( V_15 , V_123 , V_129 >> 16 ) ;
F_69 ( V_15 , V_123 , V_123 , V_129 & 0xffff ) ;
F_52 ( V_15 , V_123 , V_128 ) ;
F_60 ( V_15 , V_21 , V_17 , V_70 ) ;
F_68 ( V_15 , V_17 , V_123 , V_130 , V_126 ) ;
}
static void
F_72 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_123 ,
unsigned int V_131 , int V_125 )
{
F_40 ( V_15 , V_123 , 0 , V_131 ) ;
if ( F_6 () ) {
F_73 ( V_15 , V_17 , V_123 , F_33 ( V_132 ) , V_125 ) ;
} else {
F_50 ( V_15 , V_123 , V_123 , V_132 ) ;
F_74 ( V_15 , V_17 , V_123 , V_125 ) ;
}
}
static void F_75 ( T_3 * * V_15 , unsigned int V_133 ,
unsigned int V_123 )
{
int V_134 ;
V_134 = ( V_135 >> 7 ) < 0x10000 ;
if ( ! V_134 )
F_43 ( V_15 , V_123 , V_135 >> ( 7 + 16 ) ) ;
F_63 ( V_15 , V_133 ) ;
F_28 ( V_15 , V_133 , V_62 ) ;
if ( V_134 )
F_76 ( V_15 , V_133 , V_133 , V_135 >> 7 ) ;
else
F_35 ( V_15 , V_133 , V_133 , V_123 ) ;
F_28 ( V_15 , V_133 , V_136 ) ;
}
static void F_77 ( T_3 * * V_15 , struct V_16 * * V_17 ,
struct V_20 * * V_21 ,
unsigned int V_133 ,
unsigned int V_137 )
{
#ifdef F_78
F_79 ( V_15 , V_133 , 0 , V_137 ) ;
F_80 ( V_15 , V_17 , V_133 , V_138 ) ;
F_40 ( V_15 , V_133 , 0 , V_137 ) ;
#else
F_36 ( V_15 , V_133 , 0 , V_137 ) ;
#endif
F_75 ( V_15 , V_133 , V_137 ) ;
F_71 ( V_15 , V_21 , V_17 , V_133 , V_72 , 0 ) ;
}
static void
F_81 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_123 , unsigned int V_137 )
{
#ifndef F_82
long V_57 = ( long ) V_58 ;
#endif
F_83 ( V_15 , V_123 , V_60 ) ;
if ( V_139 ) {
F_67 ( V_15 , V_137 , V_123 , V_140 + V_141 + V_142 - 3 ) ;
F_74 ( V_15 , V_17 , V_137 , V_143 ) ;
} else {
F_84 ( V_15 , V_17 , V_123 , V_143 ) ;
}
if ( V_144 != - 1 ) {
F_39 ( V_15 , V_137 , F_24 () , V_144 ) ;
} else {
#if F_21 ( F_82 )
F_39 ( V_15 , V_137 , V_61 ) ;
F_85 ( V_15 , V_137 , 0 , 0 , 23 ) ;
F_69 ( V_15 , V_137 , V_137 , 0x540 ) ;
F_86 ( V_15 , V_137 , V_137 , 11 ) ;
#elif F_21 ( F_78 )
F_30 ( V_15 , V_137 , V_52 ) ;
F_67 ( V_15 , V_137 , V_137 , V_145 ) ;
F_87 ( V_15 , V_123 , V_57 ) ;
F_88 ( V_15 , V_137 , V_137 , V_123 ) ;
F_83 ( V_15 , V_123 , V_60 ) ;
F_89 ( V_15 , V_137 , F_46 ( V_57 ) , V_137 ) ;
#else
F_87 ( V_15 , V_137 , V_57 ) ;
F_89 ( V_15 , V_137 , F_46 ( V_57 ) , V_137 ) ;
#endif
}
F_90 ( V_21 , * V_15 ) ;
F_67 ( V_15 , V_123 , V_123 , V_140 - 3 ) ;
F_50 ( V_15 , V_123 , V_123 , ( V_146 - 1 ) << 3 ) ;
F_88 ( V_15 , V_137 , V_137 , V_123 ) ;
#ifndef F_91
F_83 ( V_15 , V_123 , V_60 ) ;
F_89 ( V_15 , V_137 , 0 , V_137 ) ;
F_67 ( V_15 , V_123 , V_123 , V_147 - 3 ) ;
F_50 ( V_15 , V_123 , V_123 , ( V_148 - 1 ) << 3 ) ;
F_88 ( V_15 , V_137 , V_137 , V_123 ) ;
#endif
}
static void
F_92 ( T_3 * * V_15 , struct V_20 * * V_21 , struct V_16 * * V_17 ,
unsigned int V_149 , unsigned int V_137 ,
enum V_150 V_151 )
{
long V_152 = ( long ) V_153 ;
int V_154 ;
int V_155 = 0 ;
V_154 = F_93 ( V_152 ) && ! F_46 ( V_152 ) ;
F_94 ( V_21 , * V_15 ) ;
if ( V_151 != V_156 && V_139 ) {
if ( V_154 ) {
F_84 ( V_15 , V_17 , V_149 , V_157 ) ;
F_43 ( V_15 , V_137 , F_44 ( V_152 ) ) ;
V_155 = 1 ;
} else {
F_95 ( V_15 , V_17 , V_149 , V_158 ) ;
}
}
if ( ! V_155 ) {
if ( F_93 ( V_152 ) && ! F_46 ( V_152 ) ) {
F_70 ( V_15 , V_17 , V_157 ) ;
F_43 ( V_15 , V_137 , F_44 ( V_152 ) ) ;
} else {
F_87 ( V_15 , V_137 , V_152 ) ;
F_70 ( V_15 , V_17 , V_157 ) ;
if ( F_93 ( V_152 ) )
F_96 ( V_15 , V_137 , V_137 , F_46 ( V_152 ) ) ;
else
F_97 ( V_15 , V_137 , V_137 , F_46 ( V_152 ) ) ;
}
}
if ( V_151 != V_156 && V_139 ) {
F_98 ( V_21 , * V_15 ) ;
F_34 ( V_15 , V_137 , ( unsigned long ) V_159 ) ;
F_54 ( V_15 , V_137 ) ;
if ( V_151 == V_160 ) {
if ( V_46 >= 0 )
F_39 ( V_15 , 1 , F_24 () , V_46 ) ;
else
F_40 ( V_15 , 1 , F_10 ( 0 ) , 0 ) ;
} else {
F_51 ( V_15 ) ;
}
}
}
static void T_2
F_99 ( T_3 * * V_15 , unsigned int V_123 , unsigned int V_137 )
{
if ( V_144 != - 1 ) {
F_42 ( V_15 , V_137 , F_24 () , V_144 ) ;
F_42 ( V_15 , V_123 , V_60 ) ;
} else {
long V_57 = ( long ) V_58 ;
#ifdef F_78
F_42 ( V_15 , V_137 , V_52 ) ;
F_87 ( V_15 , V_123 , V_57 ) ;
F_47 ( V_15 , V_137 , V_137 , V_145 ) ;
F_49 ( V_15 , V_137 , V_123 , V_137 ) ;
#else
F_87 ( V_15 , V_137 , V_57 ) ;
#endif
F_42 ( V_15 , V_123 , V_60 ) ;
F_45 ( V_15 , V_137 , F_46 ( V_57 ) , V_137 ) ;
}
F_47 ( V_15 , V_123 , V_123 , V_140 ) ;
F_48 ( V_15 , V_123 , V_123 , V_161 ) ;
F_49 ( V_15 , V_137 , V_137 , V_123 ) ;
}
static void F_100 ( T_3 * * V_15 , unsigned int V_162 )
{
unsigned int V_163 = 4 - ( V_164 + 1 ) + V_142 - 12 ;
unsigned int V_165 = ( V_166 / 2 - 1 ) << ( V_164 + 1 ) ;
switch ( F_7 () ) {
case V_167 :
case V_110 :
case V_111 :
case V_112 :
case V_115 :
case V_113 :
case V_114 :
case V_116 :
V_163 += 2 ;
break;
default:
break;
}
if ( V_163 )
F_65 ( V_15 , V_162 , V_162 , V_163 ) ;
F_50 ( V_15 , V_162 , V_162 , V_165 ) ;
}
static void F_101 ( T_3 * * V_15 , unsigned int V_123 , unsigned int V_137 )
{
switch ( F_7 () ) {
case V_68 :
F_40 ( V_15 , V_137 , 0 , V_137 ) ;
F_102 ( V_15 , V_123 ) ;
break;
default:
F_102 ( V_15 , V_123 ) ;
F_40 ( V_15 , V_137 , 0 , V_137 ) ;
break;
}
F_100 ( V_15 , V_123 ) ;
F_35 ( V_15 , V_137 , V_137 , V_123 ) ;
}
static void F_103 ( T_3 * * V_15 , unsigned int V_123 , unsigned int V_168 )
{
if ( F_104 ( F_66 ) && ! V_169 ) {
int V_170 = sizeof( V_171 ) / 2 ;
int V_172 = V_170 + sizeof( V_171 ) ;
#ifdef F_105
const int V_173 = 1 ;
F_49 ( V_15 , V_173 , 0 , V_168 ) ;
#endif
F_45 ( V_15 , V_123 , V_170 , V_168 ) ;
F_45 ( V_15 , V_168 , V_172 , V_168 ) ;
F_64 ( V_15 , V_123 , V_123 , F_33 ( V_122 ) ) ;
F_64 ( V_15 , V_168 , V_168 , F_33 ( V_122 ) ) ;
F_28 ( V_15 , V_123 , V_62 ) ;
F_28 ( V_15 , V_168 , V_136 ) ;
#ifdef F_105
F_45 ( V_15 , V_123 , 0 , V_173 ) ;
F_45 ( V_15 , V_168 , sizeof( V_171 ) , V_173 ) ;
F_43 ( V_15 , V_173 , 0xff ) ;
F_69 ( V_15 , V_173 , V_173 , 0xffff ) ;
F_106 ( V_15 , V_123 , V_173 , V_123 ) ;
F_106 ( V_15 , V_168 , V_173 , V_168 ) ;
F_107 ( V_15 , V_123 , V_62 ) ;
F_107 ( V_15 , V_168 , V_136 ) ;
#endif
return;
}
F_40 ( V_15 , V_123 , 0 , V_168 ) ;
F_40 ( V_15 , V_168 , sizeof( V_171 ) , V_168 ) ;
if ( F_2 () )
F_58 ( V_15 ) ;
F_63 ( V_15 , V_123 ) ;
if ( F_3 () )
F_28 ( V_15 , 0 , V_62 ) ;
F_28 ( V_15 , V_123 , V_62 ) ;
F_63 ( V_15 , V_168 ) ;
if ( F_2 () )
F_42 ( V_15 , V_123 , V_174 ) ;
if ( F_3 () )
F_28 ( V_15 , 0 , V_136 ) ;
F_28 ( V_15 , V_168 , V_136 ) ;
}
static struct V_175
F_108 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_123 ,
unsigned int V_137 , int V_176 )
{
struct V_175 V_177 ;
unsigned int V_178 , V_179 ;
int V_180 = 0 ;
const int V_173 = 1 ;
V_177 . V_181 = V_173 ;
V_177 . V_126 = 0 ;
V_177 . V_182 = false ;
if ( V_139 ) {
F_39 ( V_15 , V_123 , V_60 ) ;
if ( V_144 != - 1 )
F_39 ( V_15 , V_137 , F_24 () , V_144 ) ;
else
F_39 ( V_15 , V_137 , V_61 ) ;
if ( V_176 >= 0 )
F_28 ( V_15 , V_173 , F_24 () , V_176 ) ;
else
F_36 ( V_15 , V_173 , F_10 ( 0 ) , 0 ) ;
F_67 ( V_15 , V_173 , V_123 ,
V_140 + V_141 + V_142 - 3 ) ;
F_74 ( V_15 , V_17 , V_173 , V_143 ) ;
if ( V_144 == - 1 ) {
V_180 = 1 ;
F_85 ( V_15 , V_137 , 0 , 0 , 23 ) ;
}
} else {
if ( V_144 != - 1 )
F_39 ( V_15 , V_137 , F_24 () , V_144 ) ;
else
F_39 ( V_15 , V_137 , V_61 ) ;
F_39 ( V_15 , V_123 , V_60 ) ;
if ( V_176 >= 0 )
F_28 ( V_15 , V_173 , F_24 () , V_176 ) ;
else
F_36 ( V_15 , V_173 , F_10 ( 0 ) , 0 ) ;
if ( V_144 == - 1 )
F_85 ( V_15 , V_137 , 0 , 0 , 23 ) ;
F_84 ( V_15 , V_17 , V_123 , V_143 ) ;
}
if ( V_144 == - 1 ) {
V_180 = 1 ;
F_69 ( V_15 , V_137 , V_137 , 0x540 ) ;
F_86 ( V_15 , V_137 , V_137 , 11 ) ;
}
#ifdef F_91
#define F_109 scratch
#else
#define F_109 ptr
#endif
if ( ! V_180 )
F_67 ( V_15 , V_173 , V_123 , V_140 - 3 ) ;
F_90 ( V_21 , * V_15 ) ;
if ( V_180 )
F_67 ( V_15 , V_173 , V_123 , V_140 - 3 ) ;
#ifdef F_91
F_102 ( V_15 , V_123 ) ;
#endif
F_50 ( V_15 , V_173 , V_173 , ( V_146 - 1 ) << 3 ) ;
if ( F_8 () ) {
F_110 ( V_15 , F_109 , V_173 , V_137 ) ;
} else {
F_88 ( V_15 , V_137 , V_137 , V_173 ) ;
F_89 ( V_15 , F_109 , 0 , V_137 ) ;
}
#ifndef F_91
F_67 ( V_15 , V_173 , V_123 , V_147 - 3 ) ;
F_50 ( V_15 , V_173 , V_173 , ( V_148 - 1 ) << 3 ) ;
F_102 ( V_15 , V_123 ) ;
if ( F_8 () ) {
F_110 ( V_15 , V_173 , V_173 , V_137 ) ;
} else {
F_88 ( V_15 , V_137 , V_137 , V_173 ) ;
F_40 ( V_15 , V_173 , 0 , V_137 ) ;
}
#endif
F_100 ( V_15 , V_123 ) ;
#ifdef F_20
F_73 ( V_15 , V_17 , V_173 , F_33 ( V_132 ) , V_138 ) ;
if ( F_8 () )
F_51 ( V_15 ) ;
#endif
if ( F_8 () ) {
V_178 = V_137 ;
V_179 = V_123 ;
F_110 ( V_15 , V_178 , V_173 , V_123 ) ;
F_76 ( V_15 , V_123 , V_123 , sizeof( V_171 ) ) ;
F_110 ( V_15 , V_179 , V_173 , V_123 ) ;
} else {
F_35 ( V_15 , V_137 , V_173 , V_123 ) ;
V_178 = V_123 ;
V_179 = V_137 ;
F_40 ( V_15 , V_178 , 0 , V_137 ) ;
F_40 ( V_15 , V_179 , sizeof( V_171 ) , V_137 ) ;
}
if ( V_30 ) {
F_86 ( V_15 , V_178 , V_178 , F_33 ( V_122 ) ) ;
F_28 ( V_15 , V_178 , V_62 ) ;
F_86 ( V_15 , V_179 , V_179 , F_33 ( V_122 ) ) ;
} else {
F_67 ( V_15 , V_178 , V_178 , F_33 ( V_122 ) ) ;
F_28 ( V_15 , V_178 , V_62 ) ;
F_67 ( V_15 , V_179 , V_179 , F_33 ( V_122 ) ) ;
}
F_28 ( V_15 , V_179 , V_136 ) ;
if ( V_176 >= 0 ) {
F_39 ( V_15 , V_173 , F_24 () , V_176 ) ;
F_60 ( V_15 , V_21 , V_17 , V_71 ) ;
F_111 ( V_21 , * V_15 ) ;
V_177 . V_126 = 1 ;
} else if ( V_142 == 14 || V_142 == 13 ) {
F_60 ( V_15 , V_21 , V_17 , V_71 ) ;
F_111 ( V_21 , * V_15 ) ;
F_40 ( V_15 , V_173 , F_10 ( 0 ) , 0 ) ;
} else {
F_40 ( V_15 , V_173 , F_10 ( 0 ) , 0 ) ;
F_60 ( V_15 , V_21 , V_17 , V_71 ) ;
F_111 ( V_21 , * V_15 ) ;
V_177 . V_126 = 1 ;
}
F_112 ( V_15 ) ;
return V_177 ;
}
static void F_113 ( void )
{
T_3 * V_15 = V_59 ;
struct V_20 * V_21 = V_183 ;
struct V_16 * V_17 = V_184 ;
T_3 * V_185 ;
unsigned int V_186 ;
struct V_175 T_5 T_2 ;
enum V_150 T_6 T_2 ;
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
memset ( V_187 , 0 , sizeof( V_187 ) ) ;
if ( F_114 ( V_188 ) && ( V_46 >= 0 || F_9 () ) && F_6 () ) {
T_5 = F_108 ( & V_15 , & V_21 , & V_17 , V_48 , V_50 ,
V_46 ) ;
T_6 = V_160 ;
} else {
T_5 . V_181 = V_48 ;
T_5 . V_126 = 0 ;
T_5 . V_182 = true ;
T_6 = V_189 ;
if ( F_4 () ) {
unsigned int V_190 = 44 ;
F_83 ( & V_15 , V_48 , V_60 ) ;
F_83 ( & V_15 , V_50 , V_191 ) ;
F_115 ( & V_15 , V_48 , V_48 , V_50 ) ;
F_67 ( & V_15 , V_50 , V_48 , 62 ) ;
F_67 ( & V_15 , V_48 , V_48 , 12 + 1 ) ;
F_116 ( & V_15 , V_48 , V_48 , 64 + 12 + 1 - V_190 ) ;
F_117 ( & V_15 , V_48 , V_48 , V_50 ) ;
F_74 ( & V_15 , & V_17 , V_48 , V_130 ) ;
}
#ifdef V_188
F_81 ( & V_15 , & V_21 , & V_17 , V_48 , V_50 ) ;
#else
F_99 ( & V_15 , V_48 , V_50 ) ;
#endif
#ifdef F_20
F_72 ( & V_15 , & V_17 , V_48 , V_50 , V_138 ) ;
#endif
F_101 ( & V_15 , V_48 , V_50 ) ;
F_103 ( & V_15 , V_48 , V_50 ) ;
F_60 ( & V_15 , & V_21 , & V_17 , V_71 ) ;
F_111 ( & V_21 , V_15 ) ;
F_112 ( & V_15 ) ;
}
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
if ( T_5 . V_182 )
F_40 ( & V_15 , T_5 . V_181 , 0 , V_50 ) ;
F_75 ( & V_15 , T_5 . V_181 , V_50 ) ;
F_71 ( & V_15 , & V_21 , & V_17 , V_48 , V_71 ,
T_5 . V_126 ) ;
#endif
#ifdef V_188
F_92 ( & V_15 , & V_21 , & V_17 , V_48 , V_50 , T_6 ) ;
#endif
switch ( F_119 () ) {
default:
if ( sizeof( long ) == 4 ) {
case V_105 :
if ( ( V_15 - V_59 ) > 64 )
F_56 ( L_22 ) ;
V_185 = V_187 ;
F_120 ( V_184 , V_183 , V_59 , V_15 , V_185 ) ;
V_186 = V_15 - V_59 ;
break;
} else {
if ( ( ( V_15 - V_59 ) > ( V_192 * 2 ) - 1 )
|| ( ( ( V_15 - V_59 ) > ( V_192 * 2 ) - 3 )
&& F_121 ( V_184 ,
V_59 + V_192 - 3 ) ) )
F_56 ( L_22 ) ;
V_185 = V_187 + V_192 ;
if ( ( V_15 - V_59 ) <= V_192 ) {
F_120 ( V_184 , V_183 , V_59 , V_15 , V_185 ) ;
V_186 = V_15 - V_59 ;
} else {
#ifdef F_20
const enum V_124 V_193 = V_138 ;
#else
const enum V_124 V_193 = V_143 ;
#endif
T_3 * V_194 ;
int V_195 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_122 ( V_183 ) && V_183 [ V_9 ] . V_196 != V_193 ; V_9 ++ )
;
F_123 ( V_9 == F_122 ( V_183 ) ) ;
V_194 = V_183 [ V_9 ] . V_197 ;
if ( V_194 > V_59 + V_192 ||
V_194 < V_15 - V_192 )
V_195 = 1 ;
if ( V_195 ) {
V_194 = V_59 + V_192 - 2 ;
if ( F_121 ( V_184 , V_194 - 1 ) )
V_194 -- ;
}
F_120 ( V_184 , V_183 , V_59 , V_194 , V_185 ) ;
V_185 += V_194 - V_59 ;
if ( V_195 ) {
F_124 ( & V_21 , V_187 ) ;
F_70 ( & V_185 , & V_17 , V_198 ) ;
if ( F_121 ( V_184 , V_194 ) )
F_51 ( & V_185 ) ;
else {
F_120 ( V_184 , V_183 ,
V_194 , V_194 + 1 , V_185 ) ;
F_125 ( V_183 , V_185 , V_185 + 1 , - 1 ) ;
V_185 ++ ;
V_194 ++ ;
}
}
F_120 ( V_184 , V_183 , V_194 , V_15 , V_187 ) ;
V_186 = ( V_185 - ( V_187 + V_192 ) ) +
( V_15 - V_194 ) ;
}
}
break;
}
F_126 ( V_184 , V_183 ) ;
F_19 ( L_23 ,
V_186 ) ;
memcpy ( ( void * ) V_64 , V_187 , 0x100 ) ;
F_57 ( V_64 , V_64 + 0x100 ) ;
F_23 ( L_26 , ( T_3 * ) V_64 , 64 ) ;
}
static void F_127 ( void )
{
const int V_199 = 4 ;
const int T_2 V_200 = 5 ;
const int T_2 V_201 = 6 ;
T_3 * V_15 = V_202 ;
const int V_203 =
V_204 - V_202 ;
#ifndef F_82
long V_57 = ( long ) V_58 ;
#endif
memset ( V_205 , 0 , V_203 *
sizeof( V_205 [ 0 ] ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
V_144 = F_25 () ;
#ifdef F_82
if ( V_144 == - 1 ) {
struct V_20 * V_21 = V_183 ;
struct V_16 * V_17 = V_184 ;
F_128 ( & V_15 , V_200 , V_199 , 29 ) ;
F_76 ( & V_15 , V_200 , V_200 , 4 ) ;
F_74 ( & V_15 , & V_17 , V_200 , V_206 ) ;
F_51 ( & V_15 ) ;
F_129 ( & V_15 , V_199 , 0 , 29 , 64 - 29 ) ;
F_130 ( & V_21 , V_15 ) ;
F_32 ( & V_15 , V_199 , V_199 , 11 ) ;
F_54 ( & V_15 , 31 ) ;
F_28 ( & V_15 , V_199 , V_61 ) ;
} else {
F_54 ( & V_15 , 31 ) ;
F_28 ( & V_15 , V_199 , F_24 () , V_144 ) ;
}
#else
#ifdef F_78
F_30 ( & V_15 , V_200 , V_52 ) ;
F_31 ( & V_15 , V_200 , V_200 , V_145 ) ;
F_87 ( & V_15 , V_201 , V_57 ) ;
F_35 ( & V_15 , V_201 , V_201 , V_200 ) ;
F_36 ( & V_15 , V_199 , F_46 ( V_57 ) , V_201 ) ;
#else
F_87 ( & V_15 , V_201 , V_57 ) ;
F_36 ( & V_15 , V_199 , F_46 ( V_57 ) , V_201 ) ;
#endif
F_54 ( & V_15 , 31 ) ;
if ( V_144 != - 1 )
F_28 ( & V_15 , V_199 , F_24 () , V_144 ) ;
else
F_51 ( & V_15 ) ;
#endif
if ( V_15 >= V_204 )
F_56 ( L_27 ) ;
F_126 ( V_184 , V_183 ) ;
F_19 ( L_28 ,
( unsigned int ) ( V_15 - V_205 ) ) ;
F_23 ( L_29 , V_205 ,
V_203 ) ;
}
static void
F_131 ( T_3 * * V_15 , unsigned int V_133 , unsigned int V_137 )
{
#ifdef F_78
# ifdef F_66
if ( V_169 )
F_132 ( V_15 , V_133 , 0 , V_137 ) ;
else
# endif
F_133 ( V_15 , V_133 , 0 , V_137 ) ;
#else
# ifdef F_66
if ( V_169 )
F_89 ( V_15 , V_133 , 0 , V_137 ) ;
else
# endif
F_40 ( V_15 , V_133 , 0 , V_137 ) ;
#endif
}
static void
F_134 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_133 , unsigned int V_137 ,
unsigned int V_151 )
{
#ifdef F_66
unsigned int V_207 = V_151 & ( V_208 | V_209 ) ;
if ( ! V_169 ) {
const int V_173 = 1 ;
F_43 ( V_15 , V_173 , ( V_151 >> 16 ) ) ;
F_117 ( V_15 , V_133 , V_133 , V_173 ) ;
} else
#endif
F_69 ( V_15 , V_133 , V_133 , V_151 ) ;
#ifdef F_78
# ifdef F_66
if ( V_169 )
F_135 ( V_15 , V_133 , 0 , V_137 ) ;
else
# endif
F_79 ( V_15 , V_133 , 0 , V_137 ) ;
if ( F_5 () )
F_136 ( V_15 , V_17 , V_133 , V_210 ) ;
else
F_80 ( V_15 , V_17 , V_133 , V_210 ) ;
# ifdef F_66
if ( ! V_169 ) {
F_137 ( V_15 , V_133 , sizeof( V_171 ) / 2 , V_137 ) ;
F_69 ( V_15 , V_133 , V_133 , V_207 ) ;
F_138 ( V_15 , V_133 , sizeof( V_171 ) / 2 , V_137 ) ;
F_80 ( V_15 , V_17 , V_133 , V_210 ) ;
F_45 ( V_15 , V_133 , 0 , V_137 ) ;
} else
F_51 ( V_15 ) ;
# else
F_51 ( V_15 ) ;
# endif
#else
# ifdef F_66
if ( V_169 )
F_139 ( V_15 , V_133 , 0 , V_137 ) ;
else
# endif
F_36 ( V_15 , V_133 , 0 , V_137 ) ;
# ifdef F_66
if ( ! V_169 ) {
F_45 ( V_15 , V_133 , sizeof( V_171 ) / 2 , V_137 ) ;
F_69 ( V_15 , V_133 , V_133 , V_207 ) ;
F_140 ( V_15 , V_133 , sizeof( V_171 ) / 2 , V_137 ) ;
F_45 ( V_15 , V_133 , 0 , V_137 ) ;
}
# endif
#endif
}
static void
F_141 ( T_3 * * V_15 , struct V_16 * * V_17 ,
int V_133 , int V_137 , int V_173 , enum V_124 V_125 )
{
int V_211 = V_173 >= 0 ? V_173 : V_133 ;
int V_212 = V_133 ;
if ( V_30 ) {
if ( F_6 () ) {
F_142 ( V_15 , V_17 , V_133 , F_33 ( V_213 ) , V_125 ) ;
F_51 ( V_15 ) ;
} else {
if ( V_22 ) {
F_47 ( V_15 , V_211 , V_212 , V_22 ) ;
V_212 = V_211 ;
}
F_50 ( V_15 , V_211 , V_212 , 1 ) ;
F_80 ( V_15 , V_17 , V_211 , V_125 ) ;
if ( V_133 == V_211 )
F_131 ( V_15 , V_133 , V_137 ) ;
}
} else {
if ( V_22 ) {
F_47 ( V_15 , V_211 , V_212 , V_22 ) ;
V_212 = V_211 ;
}
F_50 ( V_15 , V_211 , V_212 ,
( V_213 | V_214 ) >> V_22 ) ;
F_143 ( V_15 , V_211 , V_211 ,
( V_213 | V_214 ) >> V_22 ) ;
F_74 ( V_15 , V_17 , V_211 , V_125 ) ;
if ( V_133 == V_211 )
F_131 ( V_15 , V_133 , V_137 ) ;
}
}
static void
F_144 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_133 ,
unsigned int V_137 )
{
unsigned int V_151 = V_208 | V_215 ;
F_134 ( V_15 , V_17 , V_133 , V_137 , V_151 ) ;
}
static void
F_145 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_133 , unsigned int V_137 , int V_173 ,
enum V_124 V_125 )
{
int V_211 = V_173 >= 0 ? V_173 : V_133 ;
int V_212 = V_133 ;
if ( V_22 ) {
F_47 ( V_15 , V_211 , V_212 , V_22 ) ;
V_212 = V_211 ;
}
F_50 ( V_15 , V_211 , V_212 ,
( V_213 | V_216 ) >> V_22 ) ;
F_143 ( V_15 , V_211 , V_211 ,
( V_213 | V_216 ) >> V_22 ) ;
F_74 ( V_15 , V_17 , V_211 , V_125 ) ;
if ( V_133 == V_211 )
F_131 ( V_15 , V_133 , V_137 ) ;
else
F_51 ( V_15 ) ;
}
static void
F_146 ( T_3 * * V_15 , struct V_16 * * V_17 , unsigned int V_133 ,
unsigned int V_137 )
{
unsigned int V_151 = ( V_215 | V_217 | V_208
| V_209 ) ;
F_134 ( V_15 , V_17 , V_133 , V_137 , V_151 ) ;
}
static void
F_147 ( T_3 * * V_15 , struct V_16 * * V_17 ,
unsigned int V_133 , unsigned int V_137 , int V_173 ,
enum V_124 V_125 )
{
if ( F_6 () ) {
F_142 ( V_15 , V_17 , V_133 , F_33 ( V_216 ) , V_125 ) ;
F_51 ( V_15 ) ;
} else {
int V_211 = V_173 >= 0 ? V_173 : V_133 ;
F_47 ( V_15 , V_211 , V_133 , V_24 ) ;
F_50 ( V_15 , V_211 , V_211 , 1 ) ;
F_80 ( V_15 , V_17 , V_211 , V_125 ) ;
if ( V_133 == V_211 )
F_131 ( V_15 , V_133 , V_137 ) ;
}
}
static void
F_148 ( T_3 * * V_15 , unsigned int V_133 , unsigned int V_123 )
{
F_52 ( V_15 , V_133 , V_62 ) ;
F_42 ( V_15 , V_123 , V_63 ) ;
V_73 ( V_15 ) ;
F_54 ( V_15 , V_123 ) ;
F_55 ( V_15 ) ;
}
static void
F_149 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_133 ,
unsigned int V_123 )
{
F_42 ( V_15 , V_123 , V_174 ) ;
F_52 ( V_15 , V_133 , V_62 ) ;
F_84 ( V_15 , V_17 , V_123 , V_218 ) ;
F_42 ( V_15 , V_123 , V_63 ) ;
V_73 ( V_15 ) ;
F_54 ( V_15 , V_123 ) ;
F_55 ( V_15 ) ;
F_150 ( V_21 , * V_15 ) ;
F_53 ( V_15 ) ;
F_54 ( V_15 , V_123 ) ;
F_55 ( V_15 ) ;
}
static void
F_151 ( T_3 * * V_15 , unsigned int V_133 ,
unsigned int V_137 )
{
long V_57 = ( long ) V_58 ;
F_42 ( V_15 , V_133 , V_60 ) ;
F_43 ( V_15 , V_137 , F_44 ( V_57 ) ) ;
F_45 ( V_15 , V_137 , F_46 ( V_57 ) , V_137 ) ;
F_47 ( V_15 , V_133 , V_133 , 22 ) ;
F_48 ( V_15 , V_133 , V_133 , 2 ) ;
F_49 ( V_15 , V_137 , V_137 , V_133 ) ;
F_42 ( V_15 , V_133 , V_61 ) ;
F_45 ( V_15 , V_137 , 0 , V_137 ) ;
F_50 ( V_15 , V_133 , V_133 , 0xffc ) ;
F_49 ( V_15 , V_137 , V_137 , V_133 ) ;
F_45 ( V_15 , V_133 , 0 , V_137 ) ;
F_59 ( V_15 ) ;
}
static void F_152 ( void )
{
T_3 * V_15 = V_219 ;
const int V_220 = V_221 - V_219 ;
struct V_20 * V_21 = V_183 ;
struct V_16 * V_17 = V_184 ;
memset ( V_219 , 0 , V_220 * sizeof( V_219 [ 0 ] ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
F_151 ( & V_15 , V_48 , V_50 ) ;
F_141 ( & V_15 , & V_17 , V_48 , V_50 , - 1 , V_222 ) ;
F_51 ( & V_15 ) ;
F_144 ( & V_15 , & V_17 , V_48 , V_50 ) ;
F_149 ( & V_15 , & V_21 , & V_17 , V_48 , V_50 ) ;
F_153 ( & V_21 , V_15 ) ;
F_154 ( & V_15 , ( unsigned long ) V_159 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_221 )
F_56 ( L_30 ) ;
F_126 ( V_184 , V_183 ) ;
F_19 ( L_31 ,
( unsigned int ) ( V_15 - V_219 ) ) ;
F_23 ( L_32 , V_219 , V_220 ) ;
}
static void F_155 ( void )
{
T_3 * V_15 = V_223 ;
const int V_224 = V_225 - V_223 ;
struct V_20 * V_21 = V_183 ;
struct V_16 * V_17 = V_184 ;
memset ( V_223 , 0 , V_224 * sizeof( V_223 [ 0 ] ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
F_151 ( & V_15 , V_48 , V_50 ) ;
F_145 ( & V_15 , & V_17 , V_48 , V_50 , - 1 , V_226 ) ;
F_51 ( & V_15 ) ;
F_146 ( & V_15 , & V_17 , V_48 , V_50 ) ;
F_149 ( & V_15 , & V_21 , & V_17 , V_48 , V_50 ) ;
F_156 ( & V_21 , V_15 ) ;
F_154 ( & V_15 , ( unsigned long ) V_227 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_225 )
F_56 ( L_33 ) ;
F_126 ( V_184 , V_183 ) ;
F_19 ( L_34 ,
( unsigned int ) ( V_15 - V_223 ) ) ;
F_23 ( L_35 , V_223 , V_224 ) ;
}
static void F_157 ( void )
{
T_3 * V_15 = V_228 ;
const int V_229 = V_230 - V_228 ;
struct V_20 * V_21 = V_183 ;
struct V_16 * V_17 = V_184 ;
memset ( V_228 , 0 , V_229 * sizeof( V_228 [ 0 ] ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
F_151 ( & V_15 , V_48 , V_50 ) ;
F_147 ( & V_15 , & V_17 , V_48 , V_50 , - 1 , V_231 ) ;
F_51 ( & V_15 ) ;
F_146 ( & V_15 , & V_17 , V_48 , V_50 ) ;
F_148 ( & V_15 , V_48 , V_50 ) ;
F_158 ( & V_21 , V_15 ) ;
F_154 ( & V_15 , ( unsigned long ) V_227 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_230 )
F_56 ( L_36 ) ;
F_126 ( V_184 , V_183 ) ;
F_19 ( L_37 ,
( unsigned int ) ( V_15 - V_228 ) ) ;
F_23 ( L_38 , V_228 , V_229 ) ;
}
static struct V_45
F_159 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 )
{
struct V_45 V_232 = F_27 ( V_15 ) ;
#ifdef V_188
F_81 ( V_15 , V_21 , V_17 , V_232 . V_47 , V_232 . V_49 ) ;
#else
F_99 ( V_15 , V_232 . V_47 , V_232 . V_49 ) ;
#endif
#ifdef F_20
F_72 ( V_15 , V_17 , V_232 . V_47 , V_232 . V_49 , V_138 ) ;
#endif
F_39 ( V_15 , V_232 . V_47 , V_60 ) ;
F_40 ( V_15 , V_232 . V_49 , 0 , V_232 . V_49 ) ;
F_65 ( V_15 , V_232 . V_47 , V_232 . V_47 , V_142 + V_233 - V_164 ) ;
F_50 ( V_15 , V_232 . V_47 , V_232 . V_47 , ( V_166 - 1 ) << V_164 ) ;
F_35 ( V_15 , V_232 . V_49 , V_232 . V_49 , V_232 . V_47 ) ;
#ifdef F_78
F_160 ( V_21 , * V_15 ) ;
#endif
F_131 ( V_15 , V_232 . V_47 , V_232 . V_49 ) ;
if ( ! F_12 () ) {
F_58 ( V_15 ) ;
if ( V_234 ) {
F_62 ( V_15 ) ;
F_42 ( V_15 , V_232 . V_51 , V_174 ) ;
F_84 ( V_15 , V_17 , V_232 . V_51 , V_130 ) ;
F_51 ( V_15 ) ;
}
}
return V_232 ;
}
static void
F_161 ( T_3 * * V_15 , struct V_20 * * V_21 ,
struct V_16 * * V_17 , unsigned int V_123 ,
unsigned int V_137 )
{
F_69 ( V_15 , V_137 , V_137 , sizeof( V_171 ) ) ;
F_143 ( V_15 , V_137 , V_137 , sizeof( V_171 ) ) ;
F_103 ( V_15 , V_123 , V_137 ) ;
F_60 ( V_15 , V_21 , V_17 , V_72 ) ;
F_111 ( V_21 , * V_15 ) ;
F_38 ( V_15 ) ;
F_112 ( V_15 ) ;
#ifdef V_188
F_92 ( V_15 , V_21 , V_17 , V_123 , V_137 , V_156 ) ;
#endif
}
static void F_162 ( void )
{
T_3 * V_15 = V_219 ;
const int V_220 = V_221 - V_219 ;
struct V_20 * V_21 = V_183 ;
struct V_16 * V_17 = V_184 ;
struct V_45 V_232 ;
memset ( V_219 , 0 , V_220 * sizeof( V_219 [ 0 ] ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
if ( F_4 () ) {
unsigned int V_190 = 44 ;
F_83 ( & V_15 , V_48 , V_60 ) ;
F_83 ( & V_15 , V_50 , V_191 ) ;
F_115 ( & V_15 , V_48 , V_48 , V_50 ) ;
F_67 ( & V_15 , V_50 , V_48 , 62 ) ;
F_67 ( & V_15 , V_48 , V_48 , 12 + 1 ) ;
F_116 ( & V_15 , V_48 , V_48 , 64 + 12 + 1 - V_190 ) ;
F_117 ( & V_15 , V_48 , V_48 , V_50 ) ;
F_74 ( & V_15 , & V_17 , V_48 , V_130 ) ;
}
V_232 = F_159 ( & V_15 , & V_21 , & V_17 ) ;
F_141 ( & V_15 , & V_17 , V_232 . V_47 , V_232 . V_49 , V_232 . V_51 , V_222 ) ;
if ( F_12 () )
F_58 ( & V_15 ) ;
if ( V_30 && ! V_235 ) {
if ( F_6 () ) {
F_142 ( & V_15 , & V_17 , V_232 . V_47 , F_33 ( V_208 ) ,
V_206 ) ;
} else {
F_50 ( & V_15 , V_232 . V_51 , V_232 . V_47 , V_208 ) ;
F_80 ( & V_15 , & V_17 , V_232 . V_51 , V_206 ) ;
}
F_51 ( & V_15 ) ;
F_163 ( & V_15 ) ;
switch ( F_7 () ) {
default:
if ( V_75 ) {
F_62 ( & V_15 ) ;
case V_5 :
case V_6 :
case V_7 :
break;
}
}
if ( F_6 () ) {
F_164 ( & V_15 , V_232 . V_49 , F_33 ( sizeof( V_171 ) ) , 8 ) ;
} else {
F_50 ( & V_15 , V_232 . V_51 , V_232 . V_49 , sizeof( V_171 ) ) ;
F_165 ( & V_15 , V_232 . V_51 , 8 ) ;
}
F_39 ( & V_15 , V_232 . V_51 , V_62 ) ;
F_39 ( & V_15 , V_232 . V_51 , V_136 ) ;
if ( F_6 () ) {
F_73 ( & V_15 , & V_17 , V_232 . V_51 , 1 , V_222 ) ;
F_51 ( & V_15 ) ;
F_130 ( & V_21 , V_15 ) ;
} else {
F_50 ( & V_15 , V_232 . V_51 , V_232 . V_51 , 2 ) ;
F_74 ( & V_15 , & V_17 , V_232 . V_51 , V_222 ) ;
F_51 ( & V_15 ) ;
}
F_130 ( & V_21 , V_15 ) ;
}
F_144 ( & V_15 , & V_17 , V_232 . V_47 , V_232 . V_49 ) ;
F_161 ( & V_15 , & V_21 , & V_17 , V_232 . V_47 , V_232 . V_49 ) ;
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
F_131 ( & V_15 , V_232 . V_47 , V_232 . V_49 ) ;
F_141 ( & V_15 , & V_17 , V_232 . V_47 , V_232 . V_49 , V_232 . V_51 , V_222 ) ;
F_58 ( & V_15 ) ;
if ( V_30 && ! V_235 ) {
if ( F_6 () ) {
F_142 ( & V_15 , & V_17 , V_232 . V_47 , F_33 ( V_208 ) ,
V_236 ) ;
} else {
F_50 ( & V_15 , V_232 . V_51 , V_232 . V_47 , V_208 ) ;
F_80 ( & V_15 , & V_17 , V_232 . V_51 , V_236 ) ;
}
F_51 ( & V_15 ) ;
F_163 ( & V_15 ) ;
switch ( F_7 () ) {
default:
if ( V_75 ) {
F_62 ( & V_15 ) ;
case V_5 :
case V_6 :
case V_7 :
break;
}
}
if ( F_6 () ) {
F_164 ( & V_15 , V_232 . V_49 , F_33 ( sizeof( V_171 ) ) , 8 ) ;
} else {
F_50 ( & V_15 , V_232 . V_51 , V_232 . V_49 , sizeof( V_171 ) ) ;
F_165 ( & V_15 , V_232 . V_51 , 8 ) ;
}
F_39 ( & V_15 , V_232 . V_51 , V_62 ) ;
F_39 ( & V_15 , V_232 . V_51 , V_136 ) ;
if ( F_6 () ) {
F_142 ( & V_15 , & V_17 , V_232 . V_51 , 1 , V_236 ) ;
} else {
F_50 ( & V_15 , V_232 . V_51 , V_232 . V_51 , 2 ) ;
F_80 ( & V_15 , & V_17 , V_232 . V_51 , V_236 ) ;
}
if ( V_127 == 0 )
F_51 ( & V_15 ) ;
F_68 ( & V_15 , & V_17 , V_232 . V_51 , V_222 , 0 ) ;
F_166 ( & V_21 , V_15 ) ;
}
F_69 ( & V_15 , V_232 . V_47 , V_232 . V_47 , ( V_215 | V_208 ) ) ;
F_77 ( & V_15 , & V_17 , & V_21 , V_232 . V_47 , V_232 . V_49 ) ;
#endif
F_153 ( & V_21 , V_15 ) ;
F_38 ( & V_15 ) ;
#ifdef F_167
if ( ( unsigned long ) V_159 & 1 ) {
F_43 ( & V_15 , V_48 , F_44 ( ( long ) V_159 ) ) ;
F_96 ( & V_15 , V_48 , V_48 , F_46 ( ( long ) V_159 ) ) ;
F_54 ( & V_15 , V_48 ) ;
} else
#endif
F_154 ( & V_15 , ( unsigned long ) V_159 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_221 )
F_56 ( L_30 ) ;
F_126 ( V_184 , V_183 ) ;
F_19 ( L_31 ,
( unsigned int ) ( V_15 - V_219 ) ) ;
F_23 ( L_39 , V_219 , V_220 ) ;
}
static void F_168 ( void )
{
T_3 * V_15 = V_223 ;
const int V_224 = V_225 - V_223 ;
struct V_20 * V_21 = V_183 ;
struct V_16 * V_17 = V_184 ;
struct V_45 V_232 ;
memset ( V_223 , 0 , V_224 * sizeof( V_223 [ 0 ] ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
V_232 = F_159 ( & V_15 , & V_21 , & V_17 ) ;
F_145 ( & V_15 , & V_17 , V_232 . V_47 , V_232 . V_49 , V_232 . V_51 , V_226 ) ;
if ( F_12 () )
F_58 ( & V_15 ) ;
F_146 ( & V_15 , & V_17 , V_232 . V_47 , V_232 . V_49 ) ;
F_161 ( & V_15 , & V_21 , & V_17 , V_232 . V_47 , V_232 . V_49 ) ;
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
F_131 ( & V_15 , V_232 . V_47 , V_232 . V_49 ) ;
F_145 ( & V_15 , & V_17 , V_232 . V_47 , V_232 . V_49 , V_232 . V_51 , V_226 ) ;
F_58 ( & V_15 ) ;
F_69 ( & V_15 , V_232 . V_47 , V_232 . V_47 ,
V_215 | V_217 | V_208 | V_209 ) ;
F_77 ( & V_15 , & V_17 , & V_21 , V_232 . V_47 , V_232 . V_49 ) ;
#endif
F_156 ( & V_21 , V_15 ) ;
F_38 ( & V_15 ) ;
#ifdef F_167
if ( ( unsigned long ) V_227 & 1 ) {
F_43 ( & V_15 , V_48 , F_44 ( ( long ) V_227 ) ) ;
F_96 ( & V_15 , V_48 , V_48 , F_46 ( ( long ) V_227 ) ) ;
F_54 ( & V_15 , V_48 ) ;
} else
#endif
F_154 ( & V_15 , ( unsigned long ) V_227 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_225 )
F_56 ( L_33 ) ;
F_126 ( V_184 , V_183 ) ;
F_19 ( L_34 ,
( unsigned int ) ( V_15 - V_223 ) ) ;
F_23 ( L_40 , V_223 , V_224 ) ;
}
static void F_169 ( void )
{
T_3 * V_15 = V_228 ;
const int V_229 = V_230 - V_228 ;
struct V_20 * V_21 = V_183 ;
struct V_16 * V_17 = V_184 ;
struct V_45 V_232 ;
memset ( V_228 , 0 , V_229 * sizeof( V_228 [ 0 ] ) ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
V_232 = F_159 ( & V_15 , & V_21 , & V_17 ) ;
F_147 ( & V_15 , & V_17 , V_232 . V_47 , V_232 . V_49 , V_232 . V_51 , V_231 ) ;
if ( F_12 () )
F_58 ( & V_15 ) ;
F_146 ( & V_15 , & V_17 , V_232 . V_47 , V_232 . V_49 ) ;
F_161 ( & V_15 , & V_21 , & V_17 , V_232 . V_47 , V_232 . V_49 ) ;
#ifdef F_20
F_118 ( & V_21 , V_15 ) ;
F_131 ( & V_15 , V_232 . V_47 , V_232 . V_49 ) ;
F_147 ( & V_15 , & V_17 , V_232 . V_47 , V_232 . V_49 , V_232 . V_51 , V_231 ) ;
F_58 ( & V_15 ) ;
F_69 ( & V_15 , V_232 . V_47 , V_232 . V_47 ,
V_215 | V_217 | V_208 | V_209 ) ;
F_77 ( & V_15 , & V_17 , & V_21 , V_232 . V_47 , V_232 . V_49 ) ;
#endif
F_158 ( & V_21 , V_15 ) ;
F_38 ( & V_15 ) ;
#ifdef F_167
if ( ( unsigned long ) V_227 & 1 ) {
F_43 ( & V_15 , V_48 , F_44 ( ( long ) V_227 ) ) ;
F_96 ( & V_15 , V_48 , V_48 , F_46 ( ( long ) V_227 ) ) ;
F_54 ( & V_15 , V_48 ) ;
} else
#endif
F_154 ( & V_15 , ( unsigned long ) V_227 & 0x0fffffff ) ;
F_51 ( & V_15 ) ;
if ( V_15 >= V_230 )
F_56 ( L_36 ) ;
F_126 ( V_184 , V_183 ) ;
F_19 ( L_37 ,
( unsigned int ) ( V_15 - V_228 ) ) ;
F_23 ( L_41 , V_228 , V_229 ) ;
}
static void F_170 ( void )
{
F_57 ( ( unsigned long ) V_219 ,
( unsigned long ) V_221 ) ;
F_57 ( ( unsigned long ) V_223 ,
( unsigned long ) V_225 ) ;
F_57 ( ( unsigned long ) V_228 ,
( unsigned long ) V_230 ) ;
F_57 ( ( unsigned long ) V_205 ,
( unsigned long ) V_204 ) ;
}
static void F_171 ( void )
{
unsigned long V_237 ;
unsigned int V_238 ;
const int V_239 = 2 * sizeof( unsigned long ) ;
V_237 = F_172 () ;
F_19 ( L_42 ,
V_239 , V_237 ,
( V_237 & V_240 ) >> V_241 ,
( V_237 & V_242 ) >> V_243 ,
( V_237 & V_244 ) >> V_245 ,
( V_237 & V_246 ) >> V_247 ,
( V_237 & V_248 ) >> V_249 ) ;
V_237 = F_173 () ;
F_19 ( L_43 ,
V_239 , V_237 ,
( V_237 & V_250 ) >> V_251 ,
( V_237 & V_252 ) >> V_253 ,
( V_237 & V_254 ) >> V_255 ,
( V_237 & V_256 ) >> V_257 ,
( V_237 & V_258 ) >> V_259 ) ;
V_238 = F_174 () ;
F_19 ( L_44 ,
V_238 ,
( V_238 & V_260 ) >> V_261 ,
( V_238 & V_262 ) >> V_263 ,
( V_238 & V_264 ) >> V_265 ,
( V_238 & V_266 ) >> V_267 ) ;
}
static void F_175 ( void )
{
unsigned long V_268 , V_269 , V_270 ;
unsigned int V_237 ;
V_268 = F_172 () ;
V_268 &= ~ V_240 ;
V_268 |= V_140 << V_241 ;
V_268 &= ~ V_246 ;
V_268 |= V_142 << V_247 ;
if ( V_271 >= 3 ) {
V_268 &= ~ V_244 ;
V_268 |= V_147 << V_245 ;
}
V_270 = V_32 << V_249 ;
V_268 |= V_270 ;
F_176 ( V_268 ) ;
F_177 () ;
V_268 = F_172 () ;
if ( ( ( V_268 & V_248 ) << V_249 )
!= V_270 ) {
F_178 ( L_45 ,
V_270 ) ;
V_11 . V_272 &= ~ V_273 ;
return;
}
V_269 = F_33 ( V_146 ) << V_251 ;
V_269 |= F_33 ( V_166 ) << V_257 ;
if ( V_271 >= 3 )
V_269 |= F_33 ( V_148 ) << V_255 ;
if ( F_104 ( V_274 ) || ( F_179 () & V_275 ) )
V_269 |= 1 ;
F_180 ( V_269 ) ;
F_177 () ;
V_237 = 1 << V_261 ;
F_181 ( V_237 ) ;
F_182 ( L_46 ) ;
F_171 () ;
}
static void F_183 ( void )
{
#ifdef F_105
unsigned int V_276 ;
if ( V_2 ) {
F_182 ( L_47 ) ;
return;
}
V_276 = F_179 () ;
F_184 ( V_276 | V_275 ) ;
F_177 () ;
V_276 = F_179 () ;
if ( V_276 & V_275 )
F_182 ( L_48 ) ;
else
F_56 ( L_49 ) ;
#endif
}
static void F_185 ( void )
{
unsigned long V_277 ;
unsigned V_278 , V_279 ;
if ( ! V_30 || ! V_120 ) {
return;
}
F_186 ( ~ 0ul ) ;
F_177 () ;
V_277 = F_187 () ;
V_277 &= ~ ( ( 1 << V_280 ) - 1 ) ;
V_277 &= ~ ( V_281 | V_282 ) ;
V_278 = F_188 ( V_277 ) + 6 ;
V_279 = F_189 ( int , ( int ) V_283 - V_278 , 0 ) ;
V_279 -= F_190 ( unsigned , V_279 , 2 ) ;
if ( V_279 >= F_33 ( V_120 ) )
V_121 = true ;
F_19 ( L_50 , V_279 ) ;
}
void F_191 ( void )
{
static int V_284 = 0 ;
F_17 () ;
F_185 () ;
#ifdef V_188
V_139 = V_11 . V_285 > ( V_140 + V_141 + V_142 - 3 ) ;
#endif
switch ( F_7 () ) {
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
#ifndef F_82
if ( V_293 )
F_41 () ;
if ( ! V_284 ) {
if ( ! V_293 )
F_41 () ;
F_127 () ;
F_152 () ;
F_155 () ;
F_157 () ;
F_170 () ;
V_284 ++ ;
}
#else
F_56 ( L_51 ) ;
#endif
break;
case V_294 :
case V_295 :
F_56 ( L_52 ) ;
break;
case V_296 :
F_56 ( L_53 ) ;
break;
default:
if ( ! V_284 ) {
V_46 = F_25 () ;
F_127 () ;
F_162 () ;
F_168 () ;
F_169 () ;
if ( ! V_293 )
F_113 () ;
F_170 () ;
V_284 ++ ;
}
if ( V_293 )
F_113 () ;
if ( V_297 )
F_183 () ;
if ( V_234 )
F_175 () ;
}
}
