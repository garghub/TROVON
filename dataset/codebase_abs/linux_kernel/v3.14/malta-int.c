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
int T_3 F_40 ( unsigned long V_64 , unsigned long V_65 )
{
if ( ( V_2 != V_4 ) &&
( V_2 != V_8 ) ) {
V_66 = 0 ;
F_41 ( L_16 ) ;
return V_66 ;
}
if ( V_66 >= 0 )
return V_66 ;
V_67 = ( unsigned long ) F_42 ( V_68 ,
V_69 ) ;
V_70 = ( unsigned long ) F_42 ( V_71 ,
V_72 ) ;
V_66 = ( ( F_43 ( V_73 ) & V_74 ) ==
V_68 ) ;
if ( V_66 )
F_41 ( L_17 ) ;
return V_66 ;
}
int T_3 F_44 ( void )
{
return V_66 ? ( ( F_43 ( V_75 ) & V_76 ) >>
V_77 ) : 0 ;
}
void T_3 F_45 ( int V_78 , unsigned long V_79 ,
unsigned long V_80 , int type )
{
F_46 ( V_81 , V_78 ) = V_79 ;
F_46 ( V_82 , V_78 ) = V_80 | type ;
}
static void T_3 F_47 ( int V_83 , int V_63 , int V_84 )
{
int V_85 = V_83 + V_63 ;
V_86 [ V_85 ] . V_87 = V_63 ;
V_86 [ V_85 ] . V_88 = V_84 ;
V_86 [ V_85 ] . V_89 = V_90 ;
V_86 [ V_85 ] . V_91 = V_92 ;
V_86 [ V_85 ] . V_14 = V_93 ;
V_57 [ V_63 ] |= ( 1 << ( V_84 + 2 ) ) ;
}
static void T_3 F_48 ( void )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_94 ; V_63 ++ ) {
F_47 ( V_95 , V_63 , V_96 ) ;
F_47 ( V_97 , V_63 , V_98 ) ;
}
}
void T_3 F_49 ( int V_1 , struct V_99 * V_100 )
{
F_50 ( V_1 , V_100 ) ;
F_51 ( V_1 , V_101 ) ;
}
void T_3 F_52 ( void )
{
F_53 () ;
if ( ! V_102 )
F_54 () ;
if ( V_66 ) {
F_43 ( V_103 ) = V_104 | V_105 ;
V_56 = 1 ;
} else {
if ( V_2 == V_4 ) {
V_70 = ( unsigned long )
F_42 ( V_71 ,
V_72 ) ;
V_56 = ( F_55 ( V_70 , V_106 ) &
V_107 ) >>
V_108 ;
}
}
if ( V_56 )
F_41 ( L_18 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
if ( V_102 )
F_56 ( V_109 ,
V_110 , V_111 ,
V_112 ) ;
else
F_56 ( V_109 ,
V_113 , V_114 ,
V_115 ) ;
break;
case V_5 :
case V_6 :
if ( V_102 )
F_56 ( V_116 ,
V_110 , V_111 ,
V_112 ) ;
else
F_56 ( V_116 ,
V_113 , V_114 ,
V_115 ) ;
}
if ( V_102 ) {
F_57 ( V_117 , F_10 ) ;
F_57 ( V_118 , F_16 ) ;
F_50 ( V_110 + V_117 , & V_119 ) ;
F_50 ( V_110 + V_118 , & V_120 ) ;
} else if ( V_121 ) {
F_57 ( V_55 , F_10 ) ;
F_57 ( V_122 , F_16 ) ;
#ifdef F_58
F_59 ( V_58 + V_55 , & V_119 ,
( 0x100 << V_55 ) ) ;
F_59 ( V_58 + V_122 ,
& V_120 , ( 0x100 << V_122 ) ) ;
{
int V_123 ;
for ( V_123 = 0 ; V_123 < 16 ; V_123 ++ )
V_124 [ V_123 ] = ( 0x100 << V_55 ) ;
}
#else
F_50 ( V_58 + V_55 , & V_119 ) ;
F_50 ( V_58 + V_122 ,
& V_120 ) ;
#endif
} else {
F_50 ( V_58 + V_55 , & V_119 ) ;
F_50 ( V_58 + V_122 ,
& V_120 ) ;
}
if ( V_56 ) {
int V_123 ;
#if F_22 ( V_125 )
V_97 = V_126 -
( V_127 - V_94 ) * 2 - V_94 ;
V_95 = V_97 - V_94 ;
F_48 () ;
#endif
F_60 ( V_104 , V_128 , V_86 ,
F_61 ( V_86 ) , V_18 ) ;
if ( ! V_66 ) {
V_123 = F_55 ( V_70 , V_106 ) ;
F_55 ( V_70 , V_106 ) =
( V_123 | ( 0x1 << V_129 ) ) ;
F_41 ( L_19 ) ;
}
#if F_22 ( V_125 )
if ( V_121 ) {
F_57 ( V_130 , F_13 ) ;
F_57 ( V_131 , F_13 ) ;
}
F_62 ( L_20 ,
F_28 () , F_25 () ) ;
F_63 ( F_25 () | V_132 | V_133 ) ;
F_62 ( L_21 ,
F_28 () , F_25 () ) ;
F_63 ( 0x1100dc00 ) ;
F_62 ( L_22 ,
F_28 () , F_25 () ) ;
for ( V_123 = 0 ; V_123 < V_94 ; V_123 ++ ) {
F_49 ( V_18 +
F_39 ( V_123 ) , & V_134 ) ;
F_49 ( V_18 +
F_37 ( V_123 ) , & V_135 ) ;
}
#endif
} else {
#if F_22 ( V_125 )
if ( V_102 ) {
F_57 ( V_136 , F_29 ) ;
F_57 ( V_137 , F_30 ) ;
V_138 = V_136 ;
V_139 = V_137 ;
} else {
if ( V_121 ) {
F_57 ( V_59 ,
F_29 ) ;
F_57 ( V_60 ,
F_30 ) ;
}
V_138 = V_58 +
V_59 ;
V_139 = V_58 +
V_60 ;
}
F_49 ( V_138 , & V_134 ) ;
F_49 ( V_139 , & V_135 ) ;
#endif
}
}
void F_64 ( void )
{
}
int F_65 ( struct V_30 * V_31 , int V_140 )
{
int V_141 = V_140 ? V_142 : V_143 ;
if ( V_66 ) {
unsigned long V_144 = F_43 ( V_145 ) ;
unsigned long V_146 = F_43 ( V_147 ) ;
unsigned long V_148 = F_43 ( V_149 ) ;
unsigned long V_150 , V_151 ;
char V_152 [ 256 ] ;
V_150 = ( V_144 & V_153 ) ;
if ( V_150 != 0 ) {
V_150 >>= V_154 ;
if ( V_150 < 16 ) {
unsigned long V_155 = ( V_144 >> 15 ) & 7 ;
unsigned long V_156 = ( V_144 >> 12 ) & 7 ;
unsigned long V_157 = ( V_144 >> 7 ) & 0x1f ;
unsigned long V_158 = ( V_144 >> 3 ) & 15 ;
unsigned long V_159 = ( V_144 >> 0 ) & 7 ;
snprintf ( V_152 , sizeof( V_152 ) ,
L_23
L_24 ,
V_155 , V_160 [ V_156 ] , V_161 [ V_157 ] ,
V_158 , V_159 ) ;
} else {
unsigned long V_162 = ( V_144 >> 18 ) & 7 ;
unsigned long V_163 = ( V_144 >> 15 ) & 7 ;
unsigned long V_164 = ( V_144 >> 12 ) & 7 ;
unsigned long V_165 = ( V_144 >> 9 ) & 7 ;
unsigned long V_166 = ( V_144 >> 8 ) & 1 ;
unsigned long V_157 = ( V_144 >> 3 ) & 0x1f ;
unsigned long V_159 = ( V_144 >> 0 ) & 7 ;
snprintf ( V_152 , sizeof( V_152 ) ,
L_25
L_26 ,
V_167 [ V_162 ] , V_167 [ V_163 ] ,
V_167 [ V_164 ] , V_167 [ V_165 ] ,
V_166 ? L_27 : L_28 ,
V_161 [ V_157 ] , V_159 ) ;
}
V_151 = ( V_148 & V_168 ) >>
V_169 ;
F_66 ( L_29 , V_144 ,
V_170 [ V_150 ] , V_152 ) ;
F_66 ( L_30 , V_146 ) ;
F_66 ( L_31 , V_148 , V_170 [ V_151 ] ) ;
F_43 ( V_145 ) = 0 ;
}
}
return V_141 ;
}
void F_67 ( int V_171 )
{
F_68 ( V_171 ) ;
}
void F_69 ( int V_171 )
{
F_70 ( V_171 ) ;
}
void F_71 ( struct V_172 * V_173 )
{
int V_1 = ( V_173 -> V_1 - V_174 ) ;
F_70 ( V_1 ) ;
if ( V_175 [ V_1 ] & V_92 )
F_72 ( F_73 ( V_176 , V_177 ) , V_1 ) ;
}
void F_74 ( struct V_172 * V_173 )
{
F_68 ( V_173 -> V_1 - V_174 ) ;
}
void T_3 F_75 ( int V_178 , struct V_179 * V_180 )
{
int V_123 ;
for ( V_123 = V_174 ; V_123 < ( V_174 + V_178 ) ; V_123 ++ )
F_76 ( V_123 , V_180 ) ;
}
