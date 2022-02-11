static void F_1 ( struct V_1 * V_2 )
{
volatile struct V_3 * V_4 = V_2 -> V_4 ;
volatile struct V_5 * V_6 = V_2 -> V_5 ;
int V_7 ;
V_7 = F_2 ( V_6 ) ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = ( V_7 & 0xFFFF ) ;
V_4 -> V_8 = V_11 ;
V_4 -> V_10 = V_7 >> 16 ;
V_4 -> V_8 = V_12 ;
V_4 -> V_10 = V_2 -> V_13 ;
V_4 -> V_8 = V_14 ;
}
static void F_3 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
volatile struct V_5 * V_6 ;
int V_7 ;
int V_19 ;
V_6 = V_2 -> V_5 ;
F_5 ( V_16 ) ;
V_2 -> V_20 = V_2 -> V_21 = 0 ;
V_2 -> V_22 = V_2 -> V_23 = 0 ;
V_17 -> V_24 = 0 ;
V_17 -> V_25 [ 0 ] = V_16 -> V_26 [ 1 ] ;
V_17 -> V_25 [ 1 ] = V_16 -> V_26 [ 0 ] ;
V_17 -> V_25 [ 2 ] = V_16 -> V_26 [ 3 ] ;
V_17 -> V_25 [ 3 ] = V_16 -> V_26 [ 2 ] ;
V_17 -> V_25 [ 4 ] = V_16 -> V_26 [ 5 ] ;
V_17 -> V_25 [ 5 ] = V_16 -> V_26 [ 4 ] ;
if ( V_27 )
F_6 ( V_28 L_1 ) ;
for ( V_19 = 0 ; V_19 <= ( 1 << V_2 -> V_29 ) ; V_19 ++ ) {
V_7 = F_2 ( & V_6 -> V_30 [ V_19 ] [ 0 ] ) ;
V_17 -> V_31 [ V_19 ] . V_32 = V_7 ;
V_17 -> V_31 [ V_19 ] . V_33 = V_7 >> 16 ;
V_17 -> V_31 [ V_19 ] . V_34 = 0 ;
V_17 -> V_31 [ V_19 ] . V_35 = 0xf000 ;
V_17 -> V_31 [ V_19 ] . V_36 = 0 ;
if ( V_19 < 3 && V_27 )
F_6 ( V_28 L_2 , V_19 , V_7 ) ;
}
if ( V_27 )
F_6 ( V_28 L_3 ) ;
for ( V_19 = 0 ; V_19 < ( 1 << V_2 -> V_37 ) ; V_19 ++ ) {
V_7 = F_2 ( & V_6 -> V_38 [ V_19 ] [ 0 ] ) ;
V_17 -> V_39 [ V_19 ] . V_40 = V_7 ;
V_17 -> V_39 [ V_19 ] . V_41 = V_7 >> 16 ;
V_17 -> V_39 [ V_19 ] . V_42 = V_43 ;
V_17 -> V_39 [ V_19 ] . V_35 = - V_44 | 0xf000 ;
V_17 -> V_39 [ V_19 ] . V_45 = 0 ;
if ( V_19 < 3 && V_27 )
F_6 ( V_28 L_2 , V_19 , V_7 ) ;
}
V_7 = F_2 ( & V_6 -> V_39 ) ;
V_17 -> V_46 = ( V_2 -> V_37 << 13 ) | ( V_7 >> 16 ) ;
V_17 -> V_47 = V_7 ;
if ( V_27 )
F_6 ( V_28 L_4 , V_7 ) ;
V_7 = F_2 ( & V_6 -> V_31 ) ;
V_17 -> V_48 = ( V_2 -> V_29 << 13 ) | ( V_7 >> 16 ) ;
V_17 -> V_49 = V_7 ;
if ( V_27 )
F_6 ( V_28 L_5 , V_7 ) ;
V_17 -> V_50 [ 0 ] = 0 ;
V_17 -> V_50 [ 1 ] = 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
volatile struct V_3 * V_4 = V_2 -> V_4 ;
int V_19 ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_51 ;
for ( V_19 = 0 ; ( V_19 < 100 ) && ! ( V_4 -> V_10 & ( V_52 | V_53 ) ) ; V_19 ++ )
F_8 () ;
if ( ( V_19 == 100 ) || ( V_4 -> V_10 & V_52 ) ) {
F_6 ( V_54 L_6 ,
V_19 , V_4 -> V_10 ) ;
return - V_55 ;
}
V_4 -> V_10 = V_53 ;
V_4 -> V_10 = V_56 | V_57 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
volatile struct V_58 * V_59 ;
unsigned char V_60 ;
#ifdef F_10
int V_19 ;
F_6 ( V_28 L_7 ) ;
for ( V_19 = 0 ; V_19 < V_61 ; V_19 ++ ) {
if ( V_19 == V_2 -> V_20 )
F_6 ( L_8 ,
V_17 -> V_39 [ V_19 ] . V_42 & V_43 ? L_9 : L_10 ) ;
else
F_6 ( L_8 ,
V_17 -> V_39 [ V_19 ] . V_42 & V_43 ? L_11 : L_12 ) ;
}
F_6 ( L_13 ) ;
#endif
V_4 -> V_10 = V_62 | V_56 ;
for ( V_59 = & V_17 -> V_39 [ V_2 -> V_20 ] ;
! ( ( V_60 = V_59 -> V_42 ) & V_43 ) ;
V_59 = & V_17 -> V_39 [ V_2 -> V_20 ] ) {
if ( ( V_60 & V_63 ) != V_63 ) {
V_16 -> V_64 . V_65 ++ ;
V_16 -> V_64 . V_66 ++ ;
continue;
} else if ( V_60 & V_67 ) {
if ( V_60 & V_68 ) V_16 -> V_64 . V_69 ++ ;
if ( V_60 & V_70 ) V_16 -> V_64 . V_71 ++ ;
if ( V_60 & V_72 ) V_16 -> V_64 . V_65 ++ ;
if ( V_60 & V_73 ) V_16 -> V_64 . V_74 ++ ;
if ( V_60 & V_75 ) V_16 -> V_64 . V_66 ++ ;
} else {
int V_76 = ( V_59 -> V_45 & 0xfff ) - 4 ;
struct V_77 * V_78 = F_11 ( V_76 + 2 ) ;
if ( ! V_78 ) {
F_6 ( V_79 L_14
L_15 , V_16 -> V_80 ) ;
V_16 -> V_64 . V_81 ++ ;
V_59 -> V_45 = 0 ;
V_59 -> V_42 = V_43 ;
V_2 -> V_20 = ( V_2 -> V_20 + 1 ) & V_2 -> V_82 ;
return 0 ;
}
F_12 ( V_78 , 2 ) ;
F_13 ( V_78 , V_76 ) ;
F_14 ( V_78 ,
( unsigned char * ) & ( V_17 -> V_38 [ V_2 -> V_20 ] [ 0 ] ) ,
V_76 ) ;
V_78 -> V_83 = F_15 ( V_78 , V_16 ) ;
F_16 ( V_78 ) ;
V_16 -> V_64 . V_84 ++ ;
V_16 -> V_64 . V_85 += V_76 ;
}
V_59 -> V_45 = 0 ;
V_59 -> V_42 = V_43 ;
V_2 -> V_20 = ( V_2 -> V_20 + 1 ) & V_2 -> V_82 ;
}
return 0 ;
}
static int F_17 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
volatile struct V_86 * V_87 ;
int V_19 , V_88 ;
int V_89 ;
V_4 -> V_10 = V_90 | V_56 ;
V_88 = V_2 -> V_23 ;
for ( V_19 = V_88 ; V_19 != V_2 -> V_21 ; V_19 = V_88 ) {
V_87 = & V_17 -> V_31 [ V_19 ] ;
if ( V_87 -> V_34 & V_91 )
break;
if ( V_87 -> V_34 & V_92 ) {
V_89 = V_87 -> V_36 ;
V_16 -> V_64 . V_93 ++ ;
if ( V_89 & V_94 ) V_16 -> V_64 . V_95 ++ ;
if ( V_89 & V_96 ) V_16 -> V_64 . V_97 ++ ;
if ( V_89 & V_98 ) {
V_16 -> V_64 . V_99 ++ ;
if ( V_2 -> V_100 ) {
V_2 -> V_101 = 1 - V_2 -> V_101 ;
F_6 ( V_54 L_16
L_17 , V_16 -> V_80 ,
V_2 -> V_101 ? L_18 : L_19 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_102 ;
F_3 ( V_16 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
}
if ( V_89 & ( V_103 | V_104 ) ) {
V_16 -> V_64 . V_105 ++ ;
F_6 ( V_54 L_20
L_21 , V_16 -> V_80 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_102 ;
F_3 ( V_16 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
} else if ( ( V_87 -> V_34 & V_106 ) == V_106 ) {
V_87 -> V_34 &= ~ ( V_106 ) ;
if ( V_87 -> V_34 & V_107 )
V_16 -> V_64 . V_108 ++ ;
if ( V_87 -> V_34 & V_109 )
V_16 -> V_64 . V_108 += 2 ;
V_16 -> V_64 . V_110 ++ ;
}
V_88 = ( V_88 + 1 ) & V_2 -> V_111 ;
}
V_2 -> V_23 = V_88 ;
V_4 -> V_10 = V_90 | V_56 ;
return 0 ;
}
static T_1 F_18 ( int V_112 , void * V_113 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
volatile struct V_3 * V_4 ;
int V_114 ;
V_16 = (struct V_15 * ) V_113 ;
V_2 = F_4 ( V_16 ) ;
V_4 = V_2 -> V_4 ;
V_4 -> V_8 = V_14 ;
V_114 = V_4 -> V_10 ;
if ( ! ( V_114 & V_115 ) )
return V_116 ;
V_4 -> V_10 = V_114 & ~ ( V_56 | V_117 | V_102 | V_57 |
V_51 ) ;
if ( ( V_114 & V_52 ) ) {
V_4 -> V_10 = V_118 | V_52 | V_119 | V_56 ;
}
if ( V_114 & V_62 )
F_9 ( V_16 ) ;
if ( V_114 & V_90 )
F_17 ( V_16 ) ;
if ( V_114 & V_118 )
V_16 -> V_64 . V_93 ++ ;
if ( V_114 & V_119 )
V_16 -> V_64 . V_66 ++ ;
if ( V_114 & V_120 ) {
F_6 ( V_54 L_22
L_23 , V_16 -> V_80 , V_114 ) ;
V_4 -> V_10 = V_57 ;
}
if ( F_19 ( V_16 ) && V_121 > 0 )
F_20 ( V_16 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_118 | V_122 | V_119 | V_120 |
V_53 | V_56 ;
return V_123 ;
}
static int F_21 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
int V_124 ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_102 ;
V_124 = F_22 ( V_125 , F_18 , V_126 ,
V_16 -> V_80 , V_16 ) ;
if ( V_124 ) return V_124 ;
F_1 ( V_2 ) ;
F_3 ( V_16 ) ;
F_23 ( V_16 ) ;
return F_7 ( V_2 ) ;
}
static int F_24 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
F_5 ( V_16 ) ;
F_25 ( & V_2 -> V_127 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_102 ;
F_26 ( V_125 , V_16 ) ;
return 0 ;
}
static inline int F_27 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
int V_89 ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_102 ;
F_1 ( V_2 ) ;
F_3 ( V_16 ) ;
V_16 -> V_128 = V_129 ;
F_23 ( V_16 ) ;
V_89 = F_7 ( V_2 ) ;
#ifdef F_28
F_6 ( V_28 L_24 , V_89 ) ;
#endif
return V_89 ;
}
static void F_29 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
F_6 ( V_54 L_25 ,
V_16 -> V_80 , V_4 -> V_10 ) ;
F_27 ( V_16 ) ;
F_20 ( V_16 ) ;
}
static T_2 F_30 ( struct V_77 * V_78 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
int V_130 , V_131 ;
int V_89 = V_132 ;
unsigned long V_133 ;
if ( F_31 ( V_78 , V_134 ) )
return V_132 ;
V_131 = F_32 ( unsigned , V_78 -> V_76 , V_134 ) ;
F_33 ( V_133 ) ;
if ( ! V_121 ) {
F_34 ( V_133 ) ;
return V_135 ;
}
#ifdef F_28
F_35 ( V_28 , L_26 , V_136 ,
16 , 1 , V_78 -> V_137 , 64 , true ) ;
#endif
V_130 = V_2 -> V_21 & V_2 -> V_111 ;
V_17 -> V_31 [ V_130 ] . V_35 = ( - V_131 ) | 0xf000 ;
V_17 -> V_31 [ V_130 ] . V_36 = 0 ;
F_36 ( V_78 , ( void * ) & V_17 -> V_30 [ V_130 ] [ 0 ] , V_131 ) ;
V_17 -> V_31 [ V_130 ] . V_34 = ( V_106 | V_91 ) ;
V_2 -> V_21 = ( V_2 -> V_21 + 1 ) & V_2 -> V_111 ;
V_16 -> V_64 . V_138 += V_131 ;
if ( V_121 <= 0 )
F_5 ( V_16 ) ;
V_4 -> V_10 = V_56 | V_117 ;
F_37 ( V_78 ) ;
F_34 ( V_133 ) ;
return V_89 ;
}
static void F_38 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
volatile T_3 * V_139 = ( T_3 * ) & V_17 -> V_50 ;
struct V_140 * V_141 ;
char * V_142 ;
T_4 V_143 ;
if ( V_16 -> V_133 & V_144 ) {
V_17 -> V_50 [ 0 ] = 0xffffffff ;
V_17 -> V_50 [ 1 ] = 0xffffffff ;
return;
}
V_17 -> V_50 [ 0 ] = 0 ;
V_17 -> V_50 [ 1 ] = 0 ;
F_39 (ha, dev) {
V_142 = V_141 -> V_145 ;
if ( ! ( * V_142 & 1 ) )
continue;
V_143 = F_40 ( 6 , V_142 ) ;
V_143 = V_143 >> 26 ;
V_139 [ V_143 >> 4 ] |= 1 << ( V_143 & 0xf ) ;
}
}
static void F_41 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_42 ( V_16 ) )
return;
if ( V_2 -> V_23 != V_2 -> V_21 ) {
F_43 ( & V_2 -> V_127 , V_129 + 4 ) ;
F_20 ( V_16 ) ;
return;
}
F_5 ( V_16 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_102 ;
F_3 ( V_16 ) ;
if ( V_16 -> V_133 & V_146 ) {
V_17 -> V_24 |= V_147 ;
} else {
V_17 -> V_24 &= ~ V_147 ;
F_38 ( V_16 ) ;
}
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
F_20 ( V_16 ) ;
}
static int T_5 F_44 ( struct V_148 * V_149 ,
const struct V_150 * V_151 )
{
struct V_15 * V_16 ;
struct V_1 * V_152 ;
unsigned long V_153 , V_154 , V_155 ;
struct V_156 * V_157 , * V_158 ;
int V_159 ;
V_153 = V_149 -> V_156 . V_160 ;
V_154 = V_153 + V_161 ;
V_155 = V_153 + V_162 ;
V_157 = F_45 ( V_154 , sizeof( struct V_3 ) ,
L_27 ) ;
if ( ! V_157 )
return - V_163 ;
V_158 = F_45 ( V_155 , V_164 , L_28 ) ;
if ( ! V_158 ) {
F_46 ( V_154 , sizeof( struct V_3 ) ) ;
return - V_163 ;
}
V_16 = F_47 ( sizeof( struct V_1 ) ) ;
if ( V_16 == NULL ) {
F_46 ( V_154 , sizeof( struct V_3 ) ) ;
F_46 ( V_155 , V_164 ) ;
return - V_165 ;
}
V_152 = F_4 ( V_16 ) ;
V_157 -> V_80 = V_16 -> V_80 ;
V_158 -> V_80 = V_16 -> V_80 ;
V_16 -> V_26 [ 0 ] = 0x00 ;
if ( V_149 -> V_166 != V_167 ) {
V_16 -> V_26 [ 1 ] = 0x80 ;
V_16 -> V_26 [ 2 ] = 0x10 ;
} else {
V_16 -> V_26 [ 1 ] = 0x00 ;
V_16 -> V_26 [ 2 ] = 0x9f ;
}
V_16 -> V_26 [ 3 ] = ( V_149 -> V_168 . V_169 >> 16 ) & 0xff ;
V_16 -> V_26 [ 4 ] = ( V_149 -> V_168 . V_169 >> 8 ) & 0xff ;
V_16 -> V_26 [ 5 ] = V_149 -> V_168 . V_169 & 0xff ;
V_16 -> V_154 = F_48 ( V_154 ) ;
V_16 -> V_155 = F_48 ( V_155 ) ;
V_16 -> V_170 = V_16 -> V_155 + V_164 ;
V_152 -> V_4 = ( volatile struct V_3 * ) V_16 -> V_154 ;
V_152 -> V_18 = (struct V_5 * ) V_16 -> V_155 ;
V_152 -> V_5 = (struct V_5 * ) V_162 ;
V_152 -> V_100 = 0 ;
V_152 -> V_13 = V_171 ;
V_152 -> V_37 = V_172 ;
V_152 -> V_29 = V_173 ;
V_152 -> V_82 = V_174 ;
V_152 -> V_111 = V_175 ;
V_16 -> V_176 = & V_177 ;
V_16 -> V_178 = 5 * V_179 ;
V_16 -> V_180 = 0 ;
F_49 ( & V_152 -> V_127 ) ;
V_152 -> V_127 . V_137 = ( unsigned long ) V_16 ;
V_152 -> V_127 . V_181 =
( void (*) ( unsigned long ) ) & F_41 ;
V_159 = F_50 ( V_16 ) ;
if ( V_159 ) {
F_46 ( V_154 , sizeof( struct V_3 ) ) ;
F_46 ( V_155 , V_164 ) ;
F_51 ( V_16 ) ;
return V_159 ;
}
F_52 ( V_149 , V_16 ) ;
F_6 ( V_182 L_29
L_30 , V_16 -> V_80 , V_153 , V_16 -> V_26 ) ;
return 0 ;
}
static void T_6 F_53 ( struct V_148 * V_149 )
{
struct V_15 * V_16 = F_54 ( V_149 ) ;
F_55 ( V_16 ) ;
F_46 ( F_56 ( V_16 -> V_154 ) ,
sizeof( struct V_3 ) ) ;
F_46 ( F_56 ( V_16 -> V_155 ) , V_164 ) ;
F_51 ( V_16 ) ;
}
static int T_7 F_57 ( void )
{
return F_58 ( & V_183 ) ;
}
static void T_8 F_59 ( void )
{
F_60 ( & V_183 ) ;
}
