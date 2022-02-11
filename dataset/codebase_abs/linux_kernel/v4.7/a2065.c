static void F_1 ( struct V_1 * V_2 )
{
volatile struct V_3 * V_4 = V_2 -> V_4 ;
volatile struct V_5 * V_6 = V_2 -> V_5 ;
int V_7 = F_2 ( V_6 ) ;
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
volatile struct V_5 * V_6 = V_2 -> V_5 ;
int V_7 ;
int V_19 ;
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
F_6 ( V_16 , L_1 ) ;
for ( V_19 = 0 ; V_19 <= 1 << V_2 -> V_27 ; V_19 ++ ) {
V_7 = F_2 ( & V_6 -> V_28 [ V_19 ] [ 0 ] ) ;
V_17 -> V_29 [ V_19 ] . V_30 = V_7 ;
V_17 -> V_29 [ V_19 ] . V_31 = V_7 >> 16 ;
V_17 -> V_29 [ V_19 ] . V_32 = 0 ;
V_17 -> V_29 [ V_19 ] . V_33 = 0xf000 ;
V_17 -> V_29 [ V_19 ] . V_34 = 0 ;
if ( V_19 < 3 )
F_6 ( V_16 , L_2 , V_19 , V_7 ) ;
}
F_6 ( V_16 , L_3 ) ;
for ( V_19 = 0 ; V_19 < 1 << V_2 -> V_35 ; V_19 ++ ) {
V_7 = F_2 ( & V_6 -> V_36 [ V_19 ] [ 0 ] ) ;
V_17 -> V_37 [ V_19 ] . V_38 = V_7 ;
V_17 -> V_37 [ V_19 ] . V_39 = V_7 >> 16 ;
V_17 -> V_37 [ V_19 ] . V_40 = V_41 ;
V_17 -> V_37 [ V_19 ] . V_33 = - V_42 | 0xf000 ;
V_17 -> V_37 [ V_19 ] . V_43 = 0 ;
if ( V_19 < 3 )
F_6 ( V_16 , L_2 , V_19 , V_7 ) ;
}
V_7 = F_2 ( & V_6 -> V_37 ) ;
V_17 -> V_44 = ( V_2 -> V_35 << 13 ) | ( V_7 >> 16 ) ;
V_17 -> V_45 = V_7 ;
F_6 ( V_16 , L_4 , V_7 ) ;
V_7 = F_2 ( & V_6 -> V_29 ) ;
V_17 -> V_46 = ( V_2 -> V_27 << 13 ) | ( V_7 >> 16 ) ;
V_17 -> V_47 = V_7 ;
F_6 ( V_16 , L_5 , V_7 ) ;
V_17 -> V_48 [ 0 ] = 0 ;
V_17 -> V_48 [ 1 ] = 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
volatile struct V_3 * V_4 = V_2 -> V_4 ;
int V_19 ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_49 ;
for ( V_19 = 0 ; ( V_19 < 100 ) && ! ( V_4 -> V_10 & ( V_50 | V_51 ) ) ; V_19 ++ )
F_8 () ;
if ( ( V_19 == 100 ) || ( V_4 -> V_10 & V_50 ) ) {
F_9 ( L_6 , V_19 , V_4 -> V_10 ) ;
return - V_52 ;
}
V_4 -> V_10 = V_51 ;
V_4 -> V_10 = V_53 | V_54 ;
return 0 ;
}
static int F_10 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
volatile struct V_55 * V_56 ;
unsigned char V_57 ;
#ifdef F_11
int V_19 ;
char V_58 [ V_59 + 1 ] ;
for ( V_19 = 0 ; V_19 < V_59 ; V_19 ++ ) {
char V_60 = V_17 -> V_37 [ V_19 ] . V_40 & V_41 ;
if ( V_19 == V_2 -> V_20 )
V_58 [ V_19 ] = V_60 ? '_' : 'X' ;
else
V_58 [ V_19 ] = V_60 ? '.' : '1' ;
}
V_58 [ V_59 ] = 0 ;
F_12 ( L_7 , V_58 ) ;
#endif
V_4 -> V_10 = V_61 | V_53 ;
for ( V_56 = & V_17 -> V_37 [ V_2 -> V_20 ] ;
! ( ( V_57 = V_56 -> V_40 ) & V_41 ) ;
V_56 = & V_17 -> V_37 [ V_2 -> V_20 ] ) {
if ( ( V_57 & V_62 ) != V_62 ) {
V_16 -> V_63 . V_64 ++ ;
V_16 -> V_63 . V_65 ++ ;
continue;
} else if ( V_57 & V_66 ) {
if ( V_57 & V_67 )
V_16 -> V_63 . V_68 ++ ;
if ( V_57 & V_69 )
V_16 -> V_63 . V_70 ++ ;
if ( V_57 & V_71 )
V_16 -> V_63 . V_64 ++ ;
if ( V_57 & V_72 )
V_16 -> V_63 . V_73 ++ ;
if ( V_57 & V_74 )
V_16 -> V_63 . V_65 ++ ;
} else {
int V_75 = ( V_56 -> V_43 & 0xfff ) - 4 ;
struct V_76 * V_77 = F_13 ( V_16 , V_75 + 2 ) ;
if ( ! V_77 ) {
V_16 -> V_63 . V_78 ++ ;
V_56 -> V_43 = 0 ;
V_56 -> V_40 = V_41 ;
V_2 -> V_20 = ( V_2 -> V_20 + 1 ) & V_2 -> V_79 ;
return 0 ;
}
F_14 ( V_77 , 2 ) ;
F_15 ( V_77 , V_75 ) ;
F_16 ( V_77 ,
( unsigned char * ) & V_17 -> V_36 [ V_2 -> V_20 ] [ 0 ] ,
V_75 ) ;
V_77 -> V_80 = F_17 ( V_77 , V_16 ) ;
F_18 ( V_77 ) ;
V_16 -> V_63 . V_81 ++ ;
V_16 -> V_63 . V_82 += V_75 ;
}
V_56 -> V_43 = 0 ;
V_56 -> V_40 = V_41 ;
V_2 -> V_20 = ( V_2 -> V_20 + 1 ) & V_2 -> V_79 ;
}
return 0 ;
}
static int F_19 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
volatile struct V_83 * V_84 ;
int V_19 , V_85 ;
int V_86 ;
V_4 -> V_10 = V_87 | V_53 ;
V_85 = V_2 -> V_23 ;
for ( V_19 = V_85 ; V_19 != V_2 -> V_21 ; V_19 = V_85 ) {
V_84 = & V_17 -> V_29 [ V_19 ] ;
if ( V_84 -> V_32 & V_88 )
break;
if ( V_84 -> V_32 & V_89 ) {
V_86 = V_84 -> V_34 ;
V_16 -> V_63 . V_90 ++ ;
if ( V_86 & V_91 )
V_16 -> V_63 . V_92 ++ ;
if ( V_86 & V_93 )
V_16 -> V_63 . V_94 ++ ;
if ( V_86 & V_95 ) {
V_16 -> V_63 . V_96 ++ ;
if ( V_2 -> V_97 ) {
V_2 -> V_98 = 1 - V_2 -> V_98 ;
F_20 ( V_16 , L_8 ,
V_2 -> V_98 ? L_9 : L_10 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_99 ;
F_3 ( V_16 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
}
if ( V_86 & ( V_100 | V_101 ) ) {
V_16 -> V_63 . V_102 ++ ;
F_20 ( V_16 , L_11 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_99 ;
F_3 ( V_16 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
} else if ( ( V_84 -> V_32 & V_103 ) == V_103 ) {
V_84 -> V_32 &= ~ ( V_103 ) ;
if ( V_84 -> V_32 & V_104 )
V_16 -> V_63 . V_105 ++ ;
if ( V_84 -> V_32 & V_106 )
V_16 -> V_63 . V_105 += 2 ;
V_16 -> V_63 . V_107 ++ ;
}
V_85 = ( V_85 + 1 ) & V_2 -> V_108 ;
}
V_2 -> V_23 = V_85 ;
V_4 -> V_10 = V_87 | V_53 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 <= V_2 -> V_21 )
return V_2 -> V_23 + V_2 -> V_108 - V_2 -> V_21 ;
return V_2 -> V_23 - V_2 -> V_21 - 1 ;
}
static T_1 F_22 ( int V_109 , void * V_110 )
{
struct V_15 * V_16 = V_110 ;
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
int V_111 ;
V_4 -> V_8 = V_14 ;
V_111 = V_4 -> V_10 ;
if ( ! ( V_111 & V_112 ) )
return V_113 ;
V_4 -> V_10 = V_111 & ~ ( V_53 | V_114 | V_99 | V_54 |
V_49 ) ;
if ( V_111 & V_50 ) {
V_4 -> V_10 = V_115 | V_50 | V_116 | V_53 ;
}
if ( V_111 & V_61 )
F_10 ( V_16 ) ;
if ( V_111 & V_87 )
F_19 ( V_16 ) ;
if ( V_111 & V_115 )
V_16 -> V_63 . V_90 ++ ;
if ( V_111 & V_116 )
V_16 -> V_63 . V_65 ++ ;
if ( V_111 & V_117 ) {
F_20 ( V_16 , L_12 ,
V_111 ) ;
V_4 -> V_10 = V_54 ;
}
if ( F_23 ( V_16 ) && F_21 ( V_2 ) > 0 )
F_24 ( V_16 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = ( V_115 | V_118 | V_116 | V_117 |
V_51 | V_53 ) ;
return V_119 ;
}
static int F_25 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
int V_120 ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_99 ;
V_120 = F_26 ( V_121 , F_22 , V_122 ,
V_16 -> V_123 , V_16 ) ;
if ( V_120 )
return V_120 ;
F_1 ( V_2 ) ;
F_3 ( V_16 ) ;
F_27 ( V_16 ) ;
return F_7 ( V_2 ) ;
}
static int F_28 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
F_5 ( V_16 ) ;
F_29 ( & V_2 -> V_124 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_99 ;
F_30 ( V_121 , V_16 ) ;
return 0 ;
}
static inline int F_31 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
int V_86 ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_99 ;
F_1 ( V_2 ) ;
F_3 ( V_16 ) ;
F_32 ( V_16 ) ;
F_27 ( V_16 ) ;
V_86 = F_7 ( V_2 ) ;
F_6 ( V_16 , L_13 , V_86 ) ;
return V_86 ;
}
static void F_33 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
F_20 ( V_16 , L_14 , V_4 -> V_10 ) ;
F_31 ( V_16 ) ;
F_24 ( V_16 ) ;
}
static T_2 F_34 ( struct V_76 * V_77 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
int V_125 , V_126 ;
int V_86 = V_127 ;
unsigned long V_128 ;
if ( F_35 ( V_77 , V_129 ) )
return V_127 ;
V_126 = F_36 ( unsigned , V_77 -> V_75 , V_129 ) ;
F_37 ( V_128 ) ;
if ( ! F_21 ( V_2 ) )
goto V_130;
#ifdef F_38
F_39 ( V_131 , L_15 , V_132 ,
16 , 1 , V_77 -> V_133 , 64 , true ) ;
#endif
V_125 = V_2 -> V_21 & V_2 -> V_108 ;
V_17 -> V_29 [ V_125 ] . V_33 = ( - V_126 ) | 0xf000 ;
V_17 -> V_29 [ V_125 ] . V_34 = 0 ;
F_40 ( V_77 , ( void * ) & V_17 -> V_28 [ V_125 ] [ 0 ] , V_126 ) ;
V_17 -> V_29 [ V_125 ] . V_32 = ( V_103 | V_88 ) ;
V_2 -> V_21 = ( V_2 -> V_21 + 1 ) & V_2 -> V_108 ;
V_16 -> V_63 . V_134 += V_126 ;
if ( F_21 ( V_2 ) <= 0 )
F_5 ( V_16 ) ;
V_4 -> V_10 = V_53 | V_114 ;
V_130:
F_41 ( V_77 ) ;
F_42 ( V_128 ) ;
return V_86 ;
}
static void F_43 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
volatile T_3 * V_135 = ( T_3 * ) & V_17 -> V_48 ;
struct V_136 * V_137 ;
T_4 V_138 ;
if ( V_16 -> V_128 & V_139 ) {
V_17 -> V_48 [ 0 ] = 0xffffffff ;
V_17 -> V_48 [ 1 ] = 0xffffffff ;
return;
}
V_17 -> V_48 [ 0 ] = 0 ;
V_17 -> V_48 [ 1 ] = 0 ;
F_44 (ha, dev) {
V_138 = F_45 ( 6 , V_137 -> V_140 ) ;
V_138 = V_138 >> 26 ;
V_135 [ V_138 >> 4 ] |= 1 << ( V_138 & 0xf ) ;
}
}
static void F_46 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
volatile struct V_5 * V_17 = V_2 -> V_18 ;
volatile struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_47 ( V_16 ) )
return;
if ( V_2 -> V_23 != V_2 -> V_21 ) {
F_48 ( & V_2 -> V_124 , V_141 + 4 ) ;
F_24 ( V_16 ) ;
return;
}
F_5 ( V_16 ) ;
V_4 -> V_8 = V_14 ;
V_4 -> V_10 = V_99 ;
F_3 ( V_16 ) ;
if ( V_16 -> V_128 & V_142 ) {
V_17 -> V_24 |= V_143 ;
} else {
V_17 -> V_24 &= ~ V_143 ;
F_43 ( V_16 ) ;
}
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
F_24 ( V_16 ) ;
}
static int F_49 ( struct V_144 * V_145 ,
const struct V_146 * V_147 )
{
struct V_15 * V_16 ;
struct V_1 * V_148 ;
unsigned long V_149 = V_145 -> V_150 . V_151 ;
unsigned long V_152 = V_149 + V_153 ;
unsigned long V_154 = V_149 + V_155 ;
struct V_150 * V_156 , * V_157 ;
T_4 V_158 ;
int V_159 ;
V_156 = F_50 ( V_152 , sizeof( struct V_3 ) ,
L_16 ) ;
if ( ! V_156 )
return - V_160 ;
V_157 = F_50 ( V_154 , V_161 , L_17 ) ;
if ( ! V_157 ) {
F_51 ( V_152 , sizeof( struct V_3 ) ) ;
return - V_160 ;
}
V_16 = F_52 ( sizeof( struct V_1 ) ) ;
if ( V_16 == NULL ) {
F_51 ( V_152 , sizeof( struct V_3 ) ) ;
F_51 ( V_154 , V_161 ) ;
return - V_162 ;
}
V_148 = F_4 ( V_16 ) ;
V_156 -> V_123 = V_16 -> V_123 ;
V_157 -> V_123 = V_16 -> V_123 ;
V_158 = F_53 ( V_145 -> V_163 . V_164 ) ;
V_16 -> V_26 [ 0 ] = 0x00 ;
if ( V_145 -> V_165 != V_166 ) {
V_16 -> V_26 [ 1 ] = 0x80 ;
V_16 -> V_26 [ 2 ] = 0x10 ;
} else {
V_16 -> V_26 [ 1 ] = 0x00 ;
V_16 -> V_26 [ 2 ] = 0x9f ;
}
V_16 -> V_26 [ 3 ] = ( V_158 >> 16 ) & 0xff ;
V_16 -> V_26 [ 4 ] = ( V_158 >> 8 ) & 0xff ;
V_16 -> V_26 [ 5 ] = V_158 & 0xff ;
V_16 -> V_152 = ( unsigned long ) F_54 ( V_152 ) ;
V_16 -> V_154 = ( unsigned long ) F_54 ( V_154 ) ;
V_16 -> V_167 = V_16 -> V_154 + V_161 ;
V_148 -> V_4 = ( volatile struct V_3 * ) V_16 -> V_152 ;
V_148 -> V_18 = (struct V_5 * ) V_16 -> V_154 ;
V_148 -> V_5 = (struct V_5 * ) V_155 ;
V_148 -> V_97 = 0 ;
V_148 -> V_13 = V_168 ;
V_148 -> V_35 = V_169 ;
V_148 -> V_27 = V_170 ;
V_148 -> V_79 = V_171 ;
V_148 -> V_108 = V_172 ;
V_16 -> V_173 = & V_174 ;
V_16 -> V_175 = 5 * V_176 ;
V_16 -> V_177 = 0 ;
F_55 ( & V_148 -> V_124 ) ;
V_148 -> V_124 . V_133 = ( unsigned long ) V_16 ;
V_148 -> V_124 . V_178 =
( void (*) ( unsigned long ) ) F_46 ;
V_159 = F_56 ( V_16 ) ;
if ( V_159 ) {
F_51 ( V_152 , sizeof( struct V_3 ) ) ;
F_51 ( V_154 , V_161 ) ;
F_57 ( V_16 ) ;
return V_159 ;
}
F_58 ( V_145 , V_16 ) ;
F_59 ( V_16 , L_18 ,
V_149 , V_16 -> V_26 ) ;
return 0 ;
}
static void F_60 ( struct V_144 * V_145 )
{
struct V_15 * V_16 = F_61 ( V_145 ) ;
F_62 ( V_16 ) ;
F_51 ( F_63 ( V_16 -> V_152 ) ,
sizeof( struct V_3 ) ) ;
F_51 ( F_63 ( V_16 -> V_154 ) , V_161 ) ;
F_57 ( V_16 ) ;
}
static int T_5 F_64 ( void )
{
return F_65 ( & V_179 ) ;
}
static void T_6 F_66 ( void )
{
F_67 ( & V_179 ) ;
}
