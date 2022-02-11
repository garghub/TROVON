static inline int F_1 ( void )
{
int V_1 ;
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
F_2 ( V_7 , V_1 ) ;
V_1 &= 0xff ;
break;
case V_8 :
V_1 = F_3 ( V_9 ) ;
V_1 &= 0xff ;
break;
case V_10 :
V_11 = 0x20000 ;
( void ) V_11 ;
F_4 () ;
V_1 = F_5 ( ( V_12 * ) V_13 ) ;
F_4 () ;
V_1 &= 0xff ;
V_11 = 0 ;
break;
default:
F_6 ( L_1 ) ;
return - 1 ;
}
return V_1 ;
}
static inline int F_7 ( void )
{
unsigned long V_14 ;
int V_1 ;
F_8 ( & V_15 , V_14 ) ;
V_1 = F_1 () ;
F_9 ( & V_15 , V_14 ) ;
return V_1 ;
}
static void F_10 ( void )
{
int V_1 ;
V_1 = F_7 () ;
if ( V_1 < 0 ) {
return;
}
F_11 ( V_16 + V_1 ) ;
#ifdef F_12
if ( V_17 )
V_17 () ;
#endif
}
static void F_13 ( void )
{
int V_1 ;
if ( F_14 () )
F_11 ( V_18 ) ;
V_1 = F_15 () ;
if ( V_1 < 0 )
return;
F_11 ( V_18 + V_1 ) ;
}
static void F_16 ( void )
{
unsigned int V_19 , V_20 , V_21 , V_22 ;
unsigned int V_23 , V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 , V_29 ;
struct V_30 * V_31 = F_17 () ;
F_6 ( L_2 ) ;
F_6 ( L_3
L_4 ,
V_31 -> V_32 , V_31 -> V_33 ,
V_31 -> V_34 , V_31 -> V_35 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
F_18 () ;
break;
case V_8 :
V_27 = F_3 ( V_36 ) ;
V_28 = F_3 ( V_37 ) ;
V_29 = F_3 ( V_38 ) ;
F_6 ( L_5 , V_27 ) ;
F_6 ( L_6 ,
V_29 , V_28 ) ;
break;
case V_10 :
V_22 = V_39 ;
V_23 = V_40 ;
V_24 = V_41 ;
V_25 = V_42 ;
V_26 = V_43 ;
V_19 = V_44 ;
V_20 = V_45 ;
V_21 = V_46 ;
F_6 ( L_7 , V_24 ) ;
F_6 ( L_8 , V_25 ) ;
F_6 ( L_9 , V_26 ) ;
F_6 ( L_10 , V_19 ) ;
F_6 ( L_11 , V_20 ) ;
F_6 ( L_12 , V_21 ) ;
F_6 ( L_13 , V_22 ) ;
F_6 ( L_14 , V_23 ) ;
break;
}
F_19 ( L_15 , V_31 ) ;
}
static inline int F_20 ( unsigned long V_47 )
{
__asm__(
" .set push \n"
" .set mips32 \n"
" clz %0, %1 \n"
" .set pop \n"
: "=r" (x)
: "r" (x));
return V_47 ;
}
static inline unsigned int F_21 ( unsigned int V_48 )
{
#if F_22 ( V_49 ) || F_22 ( V_50 )
return - F_20 ( V_48 ) + 31 - V_51 ;
#else
unsigned int V_52 = 7 ;
unsigned int V_53 ;
V_53 = V_48 & 0xf000 ;
V_53 = V_53 < 1 ;
V_53 = V_53 << 2 ;
V_52 = V_52 - V_53 ;
V_48 = V_48 << V_53 ;
V_53 = V_48 & 0xc000 ;
V_53 = V_53 < 1 ;
V_53 = V_53 << 1 ;
V_52 = V_52 - V_53 ;
V_48 = V_48 << V_53 ;
V_53 = V_48 & 0x8000 ;
V_53 = V_53 < 1 ;
V_52 = V_52 - V_53 ;
return V_52 ;
#endif
}
T_1 void F_23 ( void )
{
unsigned int V_48 = F_24 () & F_25 () & V_54 ;
int V_1 ;
if ( F_26 ( ! V_48 ) ) {
F_27 () ;
return;
}
V_1 = F_21 ( V_48 ) ;
if ( V_1 == V_55 )
F_10 () ;
else if ( V_56 && ( ( 1 << V_1 ) & V_57 [ F_28 () ] ) )
F_13 () ;
else
F_11 ( V_58 + V_1 ) ;
}
static void F_29 ( void )
{
F_11 ( V_58 + V_59 ) ;
}
static void F_30 ( void )
{
F_11 ( V_58 + V_60 ) ;
}
static T_2 F_31 ( int V_1 , void * V_61 )
{
#ifdef F_32
if ( V_17 )
V_17 () ;
#endif
F_33 () ;
return V_62 ;
}
static T_2 F_34 ( int V_1 , void * V_61 )
{
F_35 () ;
return V_62 ;
}
unsigned int F_36 ( unsigned int V_63 )
{
return F_37 ( V_63 ) ;
}
unsigned int F_38 ( unsigned int V_63 )
{
return F_39 ( V_63 ) ;
}
static void T_3 F_40 ( int V_64 , int V_63 , int V_65 )
{
int V_66 = V_64 + V_63 ;
V_67 [ V_66 ] . V_68 = V_63 ;
V_67 [ V_66 ] . V_69 = V_65 ;
V_67 [ V_66 ] . V_70 = V_71 ;
V_67 [ V_66 ] . V_72 = V_73 ;
V_67 [ V_66 ] . V_14 = V_74 ;
V_57 [ V_63 ] |= ( 1 << ( V_65 + 2 ) ) ;
}
static void T_3 F_41 ( void )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_75 ; V_63 ++ ) {
F_40 ( V_76 , V_63 , V_77 ) ;
F_40 ( V_78 , V_63 , V_79 ) ;
}
}
void T_3 F_42 ( int V_1 , struct V_80 * V_81 )
{
F_43 ( V_1 , V_81 ) ;
F_44 ( V_1 , V_82 ) ;
}
void T_3 F_45 ( void )
{
F_46 () ;
if ( ! V_83 )
F_47 () ;
if ( F_48 () ) {
F_49 ( V_84 | V_85 ) ;
V_56 = 1 ;
} else {
if ( V_2 == V_4 ) {
V_86 = ( unsigned long )
F_50 ( V_87 ,
V_88 ) ;
V_56 = ( F_51 ( V_86 , V_89 ) &
V_90 ) >>
V_91 ;
}
}
if ( V_56 )
F_52 ( L_16 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
if ( V_83 )
F_53 ( V_92 ,
V_93 , V_94 ,
V_95 ) ;
else
F_53 ( V_92 ,
V_96 , V_97 ,
V_98 ) ;
break;
case V_5 :
case V_6 :
if ( V_83 )
F_53 ( V_99 ,
V_93 , V_94 ,
V_95 ) ;
else
F_53 ( V_99 ,
V_96 , V_97 ,
V_98 ) ;
}
if ( V_83 ) {
F_54 ( V_100 , F_10 ) ;
F_54 ( V_101 , F_16 ) ;
F_43 ( V_93 + V_100 , & V_102 ) ;
F_43 ( V_93 + V_101 , & V_103 ) ;
} else if ( V_104 ) {
F_54 ( V_55 , F_10 ) ;
F_54 ( V_105 , F_16 ) ;
#ifdef F_55
F_56 ( V_58 + V_55 , & V_102 ,
( 0x100 << V_55 ) ) ;
F_56 ( V_58 + V_105 ,
& V_103 , ( 0x100 << V_105 ) ) ;
{
int V_106 ;
for ( V_106 = 0 ; V_106 < 16 ; V_106 ++ )
V_107 [ V_106 ] = ( 0x100 << V_55 ) ;
}
#else
F_43 ( V_58 + V_55 , & V_102 ) ;
F_43 ( V_58 + V_105 ,
& V_103 ) ;
#endif
} else {
F_43 ( V_58 + V_55 , & V_102 ) ;
F_43 ( V_58 + V_105 ,
& V_103 ) ;
}
if ( V_56 ) {
int V_106 ;
#if F_22 ( V_108 )
V_78 = V_109 -
( V_110 - V_75 ) * 2 - V_75 ;
V_76 = V_78 - V_75 ;
F_41 () ;
#endif
F_57 ( V_84 , V_111 , V_67 ,
F_58 ( V_67 ) , V_18 ) ;
if ( ! F_48 () ) {
V_106 = F_51 ( V_86 , V_89 ) ;
F_51 ( V_86 , V_89 ) =
( V_106 | ( 0x1 << V_112 ) ) ;
F_52 ( L_17 ) ;
}
#if F_22 ( V_108 )
if ( V_104 ) {
F_54 ( V_113 , F_13 ) ;
F_54 ( V_114 , F_13 ) ;
}
F_59 ( L_18 ,
F_28 () , F_25 () ) ;
F_60 ( F_25 () | V_115 | V_116 ) ;
F_59 ( L_19 ,
F_28 () , F_25 () ) ;
F_60 ( 0x1100dc00 ) ;
F_59 ( L_20 ,
F_28 () , F_25 () ) ;
for ( V_106 = 0 ; V_106 < V_75 ; V_106 ++ ) {
F_42 ( V_18 +
F_39 ( V_106 ) , & V_117 ) ;
F_42 ( V_18 +
F_37 ( V_106 ) , & V_118 ) ;
}
#endif
} else {
#if F_22 ( V_119 )
if ( V_83 ) {
F_54 ( V_120 , F_29 ) ;
F_54 ( V_121 , F_30 ) ;
V_122 = V_120 ;
V_123 = V_121 ;
} else {
if ( V_104 ) {
F_54 ( V_59 ,
F_29 ) ;
F_54 ( V_60 ,
F_30 ) ;
}
V_122 = V_58 +
V_59 ;
V_123 = V_58 +
V_60 ;
}
F_42 ( V_122 , & V_117 ) ;
F_42 ( V_123 , & V_118 ) ;
#endif
}
}
void F_61 ( void )
{
}
int F_62 ( struct V_30 * V_31 , int V_124 )
{
int V_125 = V_124 ? V_126 : V_127 ;
if ( F_48 () ) {
unsigned long V_128 = F_63 () ;
unsigned long V_129 = F_64 () ;
unsigned long V_130 = F_65 () ;
unsigned long V_131 , V_132 ;
char V_133 [ 256 ] ;
V_131 = V_128 & V_134 ;
if ( V_131 != 0 ) {
V_131 >>= V_135 ;
if ( V_131 < 16 ) {
unsigned long V_136 = ( V_128 >> 15 ) & 7 ;
unsigned long V_137 = ( V_128 >> 12 ) & 7 ;
unsigned long V_138 = ( V_128 >> 7 ) & 0x1f ;
unsigned long V_139 = ( V_128 >> 3 ) & 15 ;
unsigned long V_140 = ( V_128 >> 0 ) & 7 ;
snprintf ( V_133 , sizeof( V_133 ) ,
L_21
L_22 ,
V_136 , V_141 [ V_137 ] , V_142 [ V_138 ] ,
V_139 , V_140 ) ;
} else {
unsigned long V_143 = ( V_128 >> 18 ) & 7 ;
unsigned long V_144 = ( V_128 >> 15 ) & 7 ;
unsigned long V_145 = ( V_128 >> 12 ) & 7 ;
unsigned long V_146 = ( V_128 >> 9 ) & 7 ;
unsigned long V_147 = ( V_128 >> 8 ) & 1 ;
unsigned long V_138 = ( V_128 >> 3 ) & 0x1f ;
unsigned long V_140 = ( V_128 >> 0 ) & 7 ;
snprintf ( V_133 , sizeof( V_133 ) ,
L_23
L_24 ,
V_148 [ V_143 ] , V_148 [ V_144 ] ,
V_148 [ V_145 ] , V_148 [ V_146 ] ,
V_147 ? L_25 : L_26 ,
V_142 [ V_138 ] , V_140 ) ;
}
V_132 = ( V_130 & V_149 ) >>
V_150 ;
F_66 ( L_27 , V_128 ,
V_151 [ V_131 ] , V_133 ) ;
F_66 ( L_28 , V_129 ) ;
F_66 ( L_29 , V_130 , V_151 [ V_132 ] ) ;
F_67 ( 0 ) ;
}
}
return V_125 ;
}
void F_68 ( int V_152 )
{
F_69 ( V_152 ) ;
}
void F_70 ( int V_152 )
{
F_71 ( V_152 ) ;
}
void F_72 ( struct V_153 * V_154 )
{
int V_1 = ( V_154 -> V_1 - V_155 ) ;
F_71 ( V_1 ) ;
if ( V_156 [ V_1 ] & V_73 )
F_73 ( F_74 ( V_157 , V_158 ) , V_1 ) ;
}
void F_75 ( struct V_153 * V_154 )
{
F_69 ( V_154 -> V_1 - V_155 ) ;
}
void T_3 F_76 ( int V_159 , struct V_160 * V_161 )
{
int V_106 ;
for ( V_106 = V_155 ; V_106 < ( V_155 + V_159 ) ; V_106 ++ )
F_77 ( V_106 , V_161 ) ;
}
