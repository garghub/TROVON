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
F_6 ( V_14 L_1 ) ;
return - 1 ;
}
return V_1 ;
}
static inline int F_7 ( void )
{
unsigned long V_15 ;
int V_1 ;
F_8 ( & V_16 , V_15 ) ;
V_1 = F_1 () ;
F_9 ( & V_16 , V_15 ) ;
return V_1 ;
}
static void F_10 ( void )
{
int V_1 ;
V_1 = F_7 () ;
if ( V_1 < 0 ) {
return;
}
F_11 ( V_17 + V_1 ) ;
}
static void F_12 ( void )
{
int V_1 ;
V_1 = F_13 () ;
if ( V_1 < 0 )
return;
F_11 ( V_18 + V_1 ) ;
}
static void F_14 ( void )
{
unsigned int V_19 , V_20 , V_21 , V_22 ;
unsigned int V_23 , V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 , V_29 ;
struct V_30 * V_31 = F_15 () ;
F_6 ( V_32 L_2 ) ;
F_6 ( V_32 L_3
L_4 ,
V_31 -> V_33 , V_31 -> V_34 ,
V_31 -> V_35 , V_31 -> V_36 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
F_16 () ;
break;
case V_8 :
V_27 = F_3 ( V_37 ) ;
V_28 = F_3 ( V_38 ) ;
V_29 = F_3 ( V_39 ) ;
F_6 ( V_32 L_5 , V_27 ) ;
F_6 ( V_32 L_6 ,
V_29 , V_28 ) ;
break;
case V_10 :
V_22 = V_40 ;
V_23 = V_41 ;
V_24 = V_42 ;
V_25 = V_43 ;
V_26 = V_44 ;
V_19 = V_45 ;
V_20 = V_46 ;
V_21 = V_47 ;
F_6 ( V_32 L_7 , V_24 ) ;
F_6 ( V_32 L_8 , V_25 ) ;
F_6 ( V_32 L_9 , V_26 ) ;
F_6 ( V_32 L_10 , V_19 ) ;
F_6 ( V_32 L_11 , V_20 ) ;
F_6 ( V_32 L_12 , V_21 ) ;
F_6 ( V_32 L_13 , V_22 ) ;
F_6 ( V_32 L_14 , V_23 ) ;
break;
}
F_17 ( L_15 , V_31 ) ;
}
static inline int F_18 ( unsigned long V_48 )
{
__asm__(
" .set push \n"
" .set mips32 \n"
" clz %0, %1 \n"
" .set pop \n"
: "=r" (x)
: "r" (x));
return V_48 ;
}
static inline unsigned int F_19 ( unsigned int V_49 )
{
#if F_20 ( V_50 ) || F_20 ( V_51 )
return - F_18 ( V_49 ) + 31 - V_52 ;
#else
unsigned int V_53 = 7 ;
unsigned int V_54 ;
V_54 = V_49 & 0xf000 ;
V_54 = V_54 < 1 ;
V_54 = V_54 << 2 ;
V_53 = V_53 - V_54 ;
V_49 = V_49 << V_54 ;
V_54 = V_49 & 0xc000 ;
V_54 = V_54 < 1 ;
V_54 = V_54 << 1 ;
V_53 = V_53 - V_54 ;
V_49 = V_49 << V_54 ;
V_54 = V_49 & 0x8000 ;
V_54 = V_54 < 1 ;
V_53 = V_53 - V_54 ;
return V_53 ;
#endif
}
T_1 void F_21 ( void )
{
unsigned int V_49 = F_22 () & F_23 () & V_55 ;
int V_1 ;
if ( F_24 ( ! V_49 ) ) {
F_25 () ;
return;
}
V_1 = F_19 ( V_49 ) ;
if ( V_1 == V_56 )
F_10 () ;
else if ( V_57 && ( ( 1 << V_1 ) & V_58 [ F_26 () ] ) )
F_12 () ;
else
F_11 ( V_59 + V_1 ) ;
}
static void F_27 ( void )
{
F_11 ( V_59 + V_60 ) ;
}
static void F_28 ( void )
{
F_11 ( V_59 + V_61 ) ;
}
static T_2 F_29 ( int V_1 , void * V_62 )
{
F_30 () ;
return V_63 ;
}
static T_2 F_31 ( int V_1 , void * V_62 )
{
F_32 () ;
return V_63 ;
}
unsigned int F_33 ( unsigned int V_64 )
{
return F_34 ( V_64 ) ;
}
unsigned int F_35 ( unsigned int V_64 )
{
return F_36 ( V_64 ) ;
}
int T_3 F_37 ( unsigned long V_65 , unsigned long V_66 )
{
if ( V_2 != V_4 ) {
V_67 = 0 ;
return V_67 ;
}
if ( V_67 >= 0 )
return V_67 ;
V_68 = ( unsigned long ) F_38 ( V_69 , V_70 ) ;
V_71 = ( unsigned long ) F_38 ( V_72 , V_73 ) ;
V_67 = ( F_39 ( V_74 ) & V_75 ) == V_69 ;
if ( V_67 )
F_40 ( L_16 ) ;
return V_67 ;
}
int T_3 F_41 ( void )
{
return V_67 ?
( F_39 ( V_76 ) & V_77 ) >> V_78 :
0 ;
}
void T_3 F_42 ( int V_79 , unsigned long V_80 ,
unsigned long V_81 , int type )
{
F_43 ( V_82 , V_79 ) = V_80 ;
F_43 ( V_83 , V_79 ) = V_81 | type ;
}
static void T_3 F_44 ( int V_84 , int V_64 , int V_85 )
{
int V_86 = V_84 + V_64 ;
V_87 [ V_86 ] . V_88 = V_64 ;
V_87 [ V_86 ] . V_89 = V_85 ;
V_87 [ V_86 ] . V_90 = V_91 ;
V_87 [ V_86 ] . V_92 = V_93 ;
V_87 [ V_86 ] . V_15 = V_94 ;
V_58 [ V_64 ] |= ( 1 << ( V_85 + 2 ) ) ;
}
static void T_3 F_45 ( void )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_95 ; V_64 ++ ) {
F_44 ( V_96 , V_64 , V_97 ) ;
F_44 ( V_98 , V_64 , V_99 ) ;
}
}
void T_3 F_46 ( int V_1 , struct V_100 * V_101 )
{
F_47 ( V_1 , V_101 ) ;
F_48 ( V_1 , V_102 ) ;
}
void T_3 F_49 ( void )
{
F_50 () ;
if ( ! V_103 )
F_51 () ;
if ( V_67 ) {
F_39 ( V_104 ) = V_105 | V_106 ;
V_57 = 1 ;
} else {
if ( V_2 == V_4 ) {
V_71 = ( unsigned long )
F_38 ( V_72 ,
V_73 ) ;
V_57 = ( F_52 ( V_71 , V_107 ) &
V_108 ) >>
V_109 ;
}
}
if ( V_57 )
F_40 ( L_17 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
if ( V_103 )
F_53 ( V_110 ,
V_111 , V_112 ,
V_113 ) ;
else
F_53 ( V_110 ,
V_114 , V_115 ,
V_116 ) ;
break;
case V_5 :
case V_6 :
if ( V_103 )
F_53 ( V_117 ,
V_111 , V_112 ,
V_113 ) ;
else
F_53 ( V_117 ,
V_114 , V_115 ,
V_116 ) ;
}
if ( V_103 ) {
F_54 ( V_118 , F_10 ) ;
F_54 ( V_119 , F_14 ) ;
F_47 ( V_111 + V_118 , & V_120 ) ;
F_47 ( V_111 + V_119 , & V_121 ) ;
} else if ( V_122 ) {
F_54 ( V_56 , F_10 ) ;
F_54 ( V_123 , F_14 ) ;
#ifdef F_55
F_56 ( V_59 + V_56 , & V_120 ,
( 0x100 << V_56 ) ) ;
F_56 ( V_59 + V_123 ,
& V_121 , ( 0x100 << V_123 ) ) ;
{
int V_124 ;
for ( V_124 = 0 ; V_124 < 16 ; V_124 ++ )
V_125 [ V_124 ] = ( 0x100 << V_56 ) ;
}
#else
F_47 ( V_59 + V_56 , & V_120 ) ;
F_47 ( V_59 + V_123 ,
& V_121 ) ;
#endif
} else {
F_47 ( V_59 + V_56 , & V_120 ) ;
F_47 ( V_59 + V_123 ,
& V_121 ) ;
}
if ( V_57 ) {
int V_124 ;
#if F_20 ( V_126 )
V_98 = V_127 - V_95 ;
V_96 = V_98 - V_95 ;
F_45 () ;
#endif
F_57 ( V_105 , V_128 , V_87 ,
F_58 ( V_87 ) , V_18 ) ;
if ( ! V_67 ) {
V_124 = F_52 ( V_71 , V_107 ) ;
F_52 ( V_71 , V_107 ) =
( V_124 | ( 0x1 << V_129 ) ) ;
F_40 ( L_18 ) ;
}
#if F_20 ( V_126 )
if ( V_122 ) {
F_54 ( V_130 , F_12 ) ;
F_54 ( V_131 , F_12 ) ;
}
F_6 ( L_19 , F_26 () , F_23 () ) ;
F_59 ( F_23 () | V_132 | V_133 ) ;
F_6 ( L_20 , F_26 () , F_23 () ) ;
F_59 ( 0x1100dc00 ) ;
F_6 ( L_21 , F_26 () , F_23 () ) ;
for ( V_124 = 0 ; V_124 < V_95 ; V_124 ++ ) {
F_46 ( V_18 +
F_36 ( V_124 ) , & V_134 ) ;
F_46 ( V_18 +
F_34 ( V_124 ) , & V_135 ) ;
}
#endif
} else {
#if F_20 ( V_126 )
if ( V_103 ) {
F_54 ( V_136 , F_27 ) ;
F_54 ( V_137 , F_28 ) ;
V_138 = V_136 ;
V_139 = V_137 ;
} else {
if ( V_122 ) {
F_54 ( V_60 , F_27 ) ;
F_54 ( V_61 , F_28 ) ;
}
V_138 = V_59 + V_60 ;
V_139 = V_59 + V_61 ;
}
F_46 ( V_138 , & V_134 ) ;
F_46 ( V_139 , & V_135 ) ;
#endif
}
}
void F_60 ( void )
{
if ( V_67 ) {
}
}
int F_61 ( struct V_30 * V_31 , int V_140 )
{
int V_141 = V_140 ? V_142 : V_143 ;
if ( V_67 ) {
unsigned long V_144 = F_39 ( V_145 ) ;
unsigned long V_146 = F_39 ( V_147 ) ;
unsigned long V_148 = F_39 ( V_149 ) ;
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
L_22
L_23 ,
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
L_24
L_25 ,
V_167 [ V_162 ] , V_167 [ V_163 ] ,
V_167 [ V_164 ] , V_167 [ V_165 ] ,
V_166 ? L_26 : L_27 ,
V_161 [ V_157 ] , V_159 ) ;
}
V_151 = ( V_148 & V_168 ) >>
V_169 ;
F_6 ( L_28 , V_144 ,
V_170 [ V_150 ] , V_152 ) ;
F_6 ( L_29 , V_146 ) ;
F_6 ( L_30 , V_148 , V_170 [ V_151 ] ) ;
F_39 ( V_145 ) = 0 ;
}
}
return V_141 ;
}
void F_62 ( int V_171 )
{
F_63 ( V_171 ) ;
}
void F_64 ( int V_171 )
{
F_65 ( V_171 ) ;
}
void F_66 ( struct V_172 * V_173 )
{
int V_1 = ( V_173 -> V_1 - V_174 ) ;
F_65 ( V_1 ) ;
if ( V_175 [ V_1 ] & V_93 )
F_67 ( F_68 ( V_176 , V_177 ) , V_1 ) ;
}
void F_69 ( struct V_172 * V_173 )
{
F_63 ( V_173 -> V_1 - V_174 ) ;
}
void T_3 F_70 ( int V_178 , struct V_179 * V_180 )
{
int V_124 ;
for ( V_124 = V_174 ; V_124 < ( V_174 + V_178 ) ; V_124 ++ )
F_71 ( V_124 , V_180 ) ;
}
