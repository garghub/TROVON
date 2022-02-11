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
#ifdef F_14
unsigned long V_1 ;
F_15 ( V_18 , V_19 ) ;
F_16 ( V_18 , V_20 ) ;
V_1 = F_17 ( V_18 , V_19 ) ;
while ( V_1 < V_19 ) {
F_11 ( V_21 + V_1 ) ;
V_1 = F_18 ( V_18 , V_19 , V_1 + 1 ) ;
}
#endif
if ( F_19 () )
F_11 ( V_21 ) ;
}
static void F_20 ( void )
{
unsigned int V_22 , V_23 , V_24 , V_25 ;
unsigned int V_26 , V_27 , V_28 , V_29 ;
unsigned int V_30 , V_31 , V_32 ;
struct V_33 * V_34 = F_21 () ;
F_6 ( L_2 ) ;
F_6 ( L_3
L_4 ,
V_34 -> V_35 , V_34 -> V_36 ,
V_34 -> V_37 , V_34 -> V_38 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
F_22 () ;
break;
case V_8 :
V_30 = F_3 ( V_39 ) ;
V_31 = F_3 ( V_40 ) ;
V_32 = F_3 ( V_41 ) ;
F_6 ( L_5 , V_30 ) ;
F_6 ( L_6 ,
V_32 , V_31 ) ;
break;
case V_10 :
V_25 = V_42 ;
V_26 = V_43 ;
V_27 = V_44 ;
V_28 = V_45 ;
V_29 = V_46 ;
V_22 = V_47 ;
V_23 = V_48 ;
V_24 = V_49 ;
F_6 ( L_7 , V_27 ) ;
F_6 ( L_8 , V_28 ) ;
F_6 ( L_9 , V_29 ) ;
F_6 ( L_10 , V_22 ) ;
F_6 ( L_11 , V_23 ) ;
F_6 ( L_12 , V_24 ) ;
F_6 ( L_13 , V_25 ) ;
F_6 ( L_14 , V_26 ) ;
break;
}
F_23 ( L_15 , V_34 ) ;
}
static inline int F_24 ( unsigned long V_50 )
{
__asm__(
" .set push \n"
" .set mips32 \n"
" clz %0, %1 \n"
" .set pop \n"
: "=r" (x)
: "r" (x));
return V_50 ;
}
static inline unsigned int F_25 ( unsigned int V_18 )
{
#if F_26 ( V_51 ) || F_26 ( V_52 )
return - F_24 ( V_18 ) + 31 - V_53 ;
#else
unsigned int V_54 = 7 ;
unsigned int V_55 ;
V_55 = V_18 & 0xf000 ;
V_55 = V_55 < 1 ;
V_55 = V_55 << 2 ;
V_54 = V_54 - V_55 ;
V_18 = V_18 << V_55 ;
V_55 = V_18 & 0xc000 ;
V_55 = V_55 < 1 ;
V_55 = V_55 << 1 ;
V_54 = V_54 - V_55 ;
V_18 = V_18 << V_55 ;
V_55 = V_18 & 0x8000 ;
V_55 = V_55 < 1 ;
V_54 = V_54 - V_55 ;
return V_54 ;
#endif
}
T_1 void F_27 ( void )
{
unsigned int V_18 = F_28 () & F_29 () & V_56 ;
int V_1 ;
if ( F_30 ( ! V_18 ) ) {
F_31 () ;
return;
}
V_1 = F_25 ( V_18 ) ;
if ( V_1 == V_57 )
F_10 () ;
else if ( V_58 && ( ( 1 << V_1 ) & V_59 [ F_32 () ] ) )
F_13 () ;
else
F_11 ( V_60 + V_1 ) ;
}
static void F_33 ( void )
{
F_11 ( V_60 + V_61 ) ;
}
static void F_34 ( void )
{
F_11 ( V_60 + V_62 ) ;
}
static T_2 F_35 ( int V_1 , void * V_63 )
{
#ifdef F_36
if ( V_17 )
V_17 () ;
#endif
F_37 () ;
return V_64 ;
}
static T_2 F_38 ( int V_1 , void * V_63 )
{
F_39 () ;
return V_64 ;
}
unsigned int F_40 ( unsigned int V_65 )
{
return F_41 ( V_65 ) ;
}
unsigned int F_42 ( unsigned int V_65 )
{
return F_43 ( V_65 ) ;
}
static void T_3 F_44 ( int V_66 , int V_65 , int V_67 )
{
int V_68 = V_66 + V_65 ;
V_69 [ V_68 ] . V_70 = V_65 ;
V_69 [ V_68 ] . V_71 = V_67 ;
V_69 [ V_68 ] . V_72 = V_73 ;
V_69 [ V_68 ] . V_74 = V_75 ;
V_69 [ V_68 ] . V_14 = 0 ;
V_59 [ V_65 ] |= ( 1 << ( V_67 + 2 ) ) ;
F_45 ( V_20 , V_68 , 1 ) ;
}
static void T_3 F_46 ( void )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_76 ; V_65 ++ ) {
F_44 ( V_77 , V_65 , V_78 ) ;
F_44 ( V_79 , V_65 , V_80 ) ;
}
}
void T_3 F_47 ( int V_1 , struct V_81 * V_82 )
{
F_48 ( V_1 , V_82 ) ;
F_49 ( V_1 , V_83 ) ;
}
void T_3 F_50 ( void )
{
F_51 () ;
if ( ! V_84 )
F_52 () ;
if ( F_53 () ) {
F_54 ( V_85 | V_86 ) ;
V_58 = 1 ;
} else {
if ( V_2 == V_4 ) {
V_87 = ( unsigned long )
F_55 ( V_88 ,
V_89 ) ;
V_58 = ( F_56 ( V_87 , V_90 ) &
V_91 ) >>
V_92 ;
}
}
if ( V_58 )
F_57 ( L_16 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
if ( V_84 )
F_58 ( V_93 ,
V_94 , V_95 ,
V_96 ) ;
else
F_58 ( V_93 ,
V_97 , V_98 ,
V_99 ) ;
break;
case V_5 :
case V_6 :
if ( V_84 )
F_58 ( V_100 ,
V_94 , V_95 ,
V_96 ) ;
else
F_58 ( V_100 ,
V_97 , V_98 ,
V_99 ) ;
}
if ( V_84 ) {
F_59 ( V_101 , F_10 ) ;
F_59 ( V_102 , F_20 ) ;
F_48 ( V_94 + V_101 , & V_103 ) ;
F_48 ( V_94 + V_102 , & V_104 ) ;
} else if ( V_105 ) {
F_59 ( V_57 , F_10 ) ;
F_59 ( V_106 , F_20 ) ;
F_48 ( V_60 + V_57 , & V_103 ) ;
F_48 ( V_60 + V_106 ,
& V_104 ) ;
} else {
F_48 ( V_60 + V_57 , & V_103 ) ;
F_48 ( V_60 + V_106 ,
& V_104 ) ;
}
if ( V_58 ) {
int V_107 ;
#if F_26 ( F_14 )
V_79 = V_19 -
( V_108 - V_76 ) * 2 - V_76 ;
V_77 = V_79 - V_76 ;
F_46 () ;
#endif
F_60 ( V_85 , V_109 , V_69 ,
F_61 ( V_69 ) , V_21 ) ;
if ( ! F_53 () ) {
V_107 = F_56 ( V_87 , V_90 ) ;
F_56 ( V_87 , V_90 ) =
( V_107 | ( 0x1 << V_110 ) ) ;
F_57 ( L_17 ) ;
}
#if F_26 ( F_14 )
if ( V_105 ) {
F_59 ( V_111 , F_13 ) ;
F_59 ( V_112 , F_13 ) ;
}
F_62 ( L_18 ,
F_32 () , F_29 () ) ;
F_63 ( F_29 () | V_113 | V_114 ) ;
F_62 ( L_19 ,
F_32 () , F_29 () ) ;
F_63 ( 0x1100dc00 ) ;
F_62 ( L_20 ,
F_32 () , F_29 () ) ;
for ( V_107 = 0 ; V_107 < V_76 ; V_107 ++ ) {
F_47 ( V_21 +
F_43 ( V_107 ) , & V_115 ) ;
F_47 ( V_21 +
F_41 ( V_107 ) , & V_116 ) ;
}
#endif
} else {
#if F_26 ( V_117 )
if ( V_84 ) {
F_59 ( V_118 , F_33 ) ;
F_59 ( V_119 , F_34 ) ;
V_120 = V_118 ;
V_121 = V_119 ;
} else {
if ( V_105 ) {
F_59 ( V_61 ,
F_33 ) ;
F_59 ( V_62 ,
F_34 ) ;
}
V_120 = V_60 +
V_61 ;
V_121 = V_60 +
V_62 ;
}
F_47 ( V_120 , & V_115 ) ;
F_47 ( V_121 , & V_116 ) ;
#endif
}
}
void F_64 ( void )
{
}
int F_65 ( struct V_33 * V_34 , int V_122 )
{
int V_123 = V_122 ? V_124 : V_125 ;
if ( F_53 () ) {
unsigned long V_126 = F_66 () ;
unsigned long V_127 = F_67 () ;
unsigned long V_128 = F_68 () ;
unsigned long V_129 , V_130 ;
char V_131 [ 256 ] ;
V_129 = V_126 & V_132 ;
if ( V_129 != 0 ) {
V_129 >>= V_133 ;
if ( V_129 < 16 ) {
unsigned long V_134 = ( V_126 >> 15 ) & 7 ;
unsigned long V_135 = ( V_126 >> 12 ) & 7 ;
unsigned long V_136 = ( V_126 >> 7 ) & 0x1f ;
unsigned long V_137 = ( V_126 >> 3 ) & 15 ;
unsigned long V_138 = ( V_126 >> 0 ) & 7 ;
snprintf ( V_131 , sizeof( V_131 ) ,
L_21
L_22 ,
V_134 , V_139 [ V_135 ] , V_140 [ V_136 ] ,
V_137 , V_138 ) ;
} else {
unsigned long V_141 = ( V_126 >> 18 ) & 7 ;
unsigned long V_142 = ( V_126 >> 15 ) & 7 ;
unsigned long V_143 = ( V_126 >> 12 ) & 7 ;
unsigned long V_144 = ( V_126 >> 9 ) & 7 ;
unsigned long V_145 = ( V_126 >> 8 ) & 1 ;
unsigned long V_136 = ( V_126 >> 3 ) & 0x1f ;
unsigned long V_138 = ( V_126 >> 0 ) & 7 ;
snprintf ( V_131 , sizeof( V_131 ) ,
L_23
L_24 ,
V_146 [ V_141 ] , V_146 [ V_142 ] ,
V_146 [ V_143 ] , V_146 [ V_144 ] ,
V_145 ? L_25 : L_26 ,
V_140 [ V_136 ] , V_138 ) ;
}
V_130 = ( V_128 & V_147 ) >>
V_148 ;
F_69 ( L_27 , V_126 ,
V_149 [ V_129 ] , V_131 ) ;
F_69 ( L_28 , V_127 ) ;
F_69 ( L_29 , V_128 , V_149 [ V_130 ] ) ;
F_70 ( 0 ) ;
}
}
return V_123 ;
}
void F_71 ( int V_150 )
{
F_72 ( V_150 ) ;
}
void F_73 ( int V_150 )
{
F_74 ( V_150 ) ;
}
void F_75 ( struct V_151 * V_152 )
{
int V_1 = ( V_152 -> V_1 - V_153 ) ;
F_74 ( V_1 ) ;
if ( V_154 [ V_1 ] & V_75 )
F_76 ( F_77 ( V_155 , V_156 ) , V_1 ) ;
}
void F_78 ( struct V_151 * V_152 )
{
F_72 ( V_152 -> V_1 - V_153 ) ;
}
void T_3 F_79 ( int V_157 , struct V_158 * V_159 )
{
int V_107 ;
for ( V_107 = V_153 ; V_107 < ( V_153 + V_157 ) ; V_107 ++ )
F_80 ( V_107 , V_159 ) ;
}
