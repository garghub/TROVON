static inline int F_1 ( void )
{
return V_1 / 20 ;
}
static void F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_12 * V_13 = & V_11 -> V_13 [ V_11 -> V_14 ] ;
unsigned int V_15 = F_3 ( V_5 , V_13 -> V_16 ) ;
unsigned int V_17 ;
V_17 = F_4 ( V_5 , V_15 + V_6 ) ;
if ( V_17 > V_6 ) {
V_17 -= V_6 ;
V_13 -> V_18 = F_5 ( V_5 , V_17 ) ;
F_6 ( V_13 ) ;
}
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_4 * V_5 = V_3 -> V_19 ;
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_12 * V_13 = & V_11 -> V_13 [ V_11 -> V_14 ] ;
unsigned long V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned int V_17 ;
F_8 ( & V_3 -> V_27 , V_24 ) ;
if ( ! ( V_8 -> V_28 & V_29 ) ) {
F_9 ( & V_3 -> V_27 , V_24 ) ;
return;
}
V_25 = F_10 ( V_13 -> V_30 ,
F_11 ( V_5 ) ) ;
if ( V_25 > V_13 -> V_18 ) {
F_12 ( V_3 -> V_31 , L_1 ) ;
V_21 -> V_32 |= V_33 ;
V_26 = 0 ;
} else {
V_26 = V_13 -> V_18 - V_25 ;
}
V_17 = F_3 ( V_5 , V_26 ) ;
if ( V_17 ) {
V_11 -> V_14 = 1 - V_11 -> V_14 ;
F_2 ( V_3 , V_5 , V_17 ) ;
}
F_9 ( & V_3 -> V_27 , V_24 ) ;
F_13 ( V_5 , V_13 -> V_34 , V_17 ) ;
if ( V_23 -> V_35 == V_36 && V_21 -> V_37 >= V_23 -> V_38 )
V_21 -> V_32 |= V_39 ;
F_14 ( V_3 , V_5 ) ;
}
static void F_15 ( unsigned long V_40 )
{
struct V_2 * V_3 = (struct V_2 * ) V_40 ;
struct V_7 * V_8 = V_3 -> V_9 ;
unsigned long V_41 ;
F_7 ( V_3 ) ;
F_8 ( & V_3 -> V_27 , V_41 ) ;
if ( V_8 -> V_42 )
F_16 ( & V_8 -> V_43 , V_44 + F_1 () ) ;
F_9 ( & V_3 -> V_27 , V_41 ) ;
}
static void F_17 ( struct V_2 * V_3 ,
unsigned int V_45 ,
unsigned int V_46 ,
unsigned int V_47 )
{
const struct V_48 * V_49 = V_3 -> V_50 ;
F_18 ( V_45 | ( V_46 << 4 ) , V_3 -> V_51 + V_52 ) ;
if ( V_49 -> V_53 == V_54 )
return;
F_18 ( ( V_55 [ V_49 -> V_53 ] ) [ V_47 ] ,
V_3 -> V_51 + V_56 ) ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_22 * V_23 )
{
unsigned int V_57 = F_20 ( V_23 -> V_58 [ 0 ] ) ;
unsigned int V_59 = F_21 ( V_23 -> V_58 [ 0 ] ) ;
int V_60 ;
for ( V_60 = 1 ; V_60 < V_23 -> V_61 ; V_60 ++ ) {
unsigned int V_30 = F_20 ( V_23 -> V_58 [ V_60 ] ) ;
unsigned int V_47 = F_21 ( V_23 -> V_58 [ V_60 ] ) ;
if ( V_30 != ( ( V_57 + V_60 ) % V_5 -> V_62 ) ) {
F_22 ( V_3 -> V_31 ,
L_2 ) ;
return - V_63 ;
}
if ( V_47 != V_59 ) {
F_22 ( V_3 -> V_31 ,
L_3 ) ;
return - V_63 ;
}
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_22 * V_23 )
{
const struct V_48 * V_49 = V_3 -> V_50 ;
struct V_7 * V_8 = V_3 -> V_9 ;
int V_64 = 0 ;
unsigned int V_65 ;
unsigned int V_40 ;
V_64 |= F_24 ( & V_23 -> V_66 , V_67 ) ;
V_65 = V_68 ;
if ( V_8 -> V_69 )
V_65 |= V_70 | V_71 ;
V_64 |= F_24 ( & V_23 -> V_72 , V_65 ) ;
V_65 = V_70 | V_71 ;
if ( V_8 -> V_69 )
V_65 |= V_67 ;
V_64 |= F_24 ( & V_23 -> V_73 , V_65 ) ;
V_64 |= F_24 ( & V_23 -> V_74 , V_36 ) ;
V_64 |= F_24 ( & V_23 -> V_35 , V_36 | V_75 ) ;
if ( V_64 )
return 1 ;
V_64 |= F_25 ( V_23 -> V_72 ) ;
V_64 |= F_25 ( V_23 -> V_73 ) ;
V_64 |= F_25 ( V_23 -> V_35 ) ;
if ( V_23 -> V_72 == V_68 && V_23 -> V_73 == V_67 )
V_64 |= - V_63 ;
if ( V_23 -> V_72 != V_68 && V_23 -> V_73 != V_67 )
V_64 |= - V_63 ;
if ( V_64 )
return 2 ;
V_64 |= F_26 ( & V_23 -> V_76 , 0 ) ;
if ( V_23 -> V_72 == V_68 )
V_64 |= F_26 ( & V_23 -> V_77 , 0 ) ;
V_64 |= F_26 ( & V_23 -> V_78 ,
V_23 -> V_61 ) ;
if ( V_23 -> V_72 == V_70 ) {
V_64 |= F_27 ( & V_23 -> V_77 ,
V_49 -> V_79 *
V_23 -> V_61 ) ;
}
if ( V_23 -> V_73 == V_70 ) {
V_64 |= F_27 ( & V_23 -> V_80 ,
V_49 -> V_79 ) ;
}
if ( V_23 -> V_35 == V_36 )
V_64 |= F_27 ( & V_23 -> V_38 , 1 ) ;
else
V_64 |= F_26 ( & V_23 -> V_38 , 0 ) ;
if ( V_64 )
return 3 ;
if ( V_23 -> V_72 == V_70 ) {
V_40 = V_23 -> V_77 ;
F_28 ( V_3 -> V_81 , & V_40 , V_23 -> V_41 ) ;
V_64 |= F_26 ( & V_23 -> V_77 , V_40 ) ;
}
if ( V_23 -> V_73 == V_70 ) {
V_40 = V_23 -> V_80 ;
F_28 ( V_3 -> V_81 , & V_40 , V_23 -> V_41 ) ;
V_64 |= F_26 ( & V_23 -> V_80 , V_40 ) ;
}
if ( V_64 )
return 4 ;
if ( V_23 -> V_58 && V_23 -> V_61 > 0 )
V_64 |= F_19 ( V_3 , V_5 , V_23 ) ;
if ( V_64 )
return 5 ;
return 0 ;
}
static unsigned int F_29 ( struct V_2 * V_3 , unsigned int V_82 ,
unsigned int V_41 )
{
F_28 ( V_3 -> V_81 , & V_82 , V_41 ) ;
F_30 ( V_3 -> V_81 ) ;
F_31 ( V_3 -> V_81 , 1 , 2 , true ) ;
return V_82 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_22 * V_23 = & V_21 -> V_23 ;
unsigned int V_45 = F_20 ( V_23 -> V_58 [ 0 ] ) ;
unsigned int V_46 = F_20 ( V_23 -> V_58 [ V_23 -> V_61 - 1 ] ) ;
unsigned int V_47 = F_21 ( V_23 -> V_58 [ 0 ] ) ;
unsigned int V_83 ;
unsigned long V_41 ;
if ( V_23 -> V_41 & V_84 ) {
F_12 ( V_3 -> V_31 ,
L_4 ) ;
return - 1 ;
}
if ( V_8 -> V_69 )
F_18 ( V_85 , V_3 -> V_51 + V_86 ) ;
F_17 ( V_3 , V_45 , V_46 , V_47 ) ;
V_23 -> V_80 = F_29 ( V_3 , V_23 -> V_80 , V_23 -> V_41 ) ;
V_83 = 0 ;
if ( V_8 -> V_69 ) {
if ( V_23 -> V_73 == V_67 ) {
F_18 ( V_87 ,
V_3 -> V_51 + V_88 ) ;
V_83 |= F_33 ( V_23 -> V_61 - 1 ) ;
} else {
F_18 ( 0 , V_3 -> V_51 + V_88 ) ;
}
}
F_18 ( V_83 , V_3 -> V_51 + V_89 ) ;
V_11 -> V_14 = 0 ;
F_2 ( V_3 , V_5 , 0 ) ;
F_8 ( & V_3 -> V_27 , V_41 ) ;
V_8 -> V_42 = 1 ;
V_8 -> V_43 . V_90 = V_44 + F_1 () ;
F_34 ( & V_8 -> V_43 ) ;
V_8 -> V_28 &= ~ ( V_91 | V_92 ) ;
V_8 -> V_28 |= V_29 ;
if ( V_23 -> V_73 == V_71 )
V_8 -> V_28 |= V_93 ;
else
V_8 -> V_28 |= V_94 ;
F_18 ( V_8 -> V_28 , V_3 -> V_51 + V_95 ) ;
if ( V_8 -> V_69 )
F_18 ( 0 , V_3 -> V_51 + V_86 ) ;
F_9 ( & V_3 -> V_27 , V_41 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_11 ;
unsigned long V_41 ;
F_8 ( & V_3 -> V_27 , V_41 ) ;
V_8 -> V_28 &= ~ ( V_91 | V_29 |
V_92 ) ;
F_18 ( V_8 -> V_28 , V_3 -> V_51 + V_95 ) ;
F_36 ( V_11 -> V_30 ) ;
if ( V_8 -> V_42 ) {
V_8 -> V_42 = 0 ;
F_37 ( & V_8 -> V_43 ) ;
}
if ( V_8 -> V_69 )
F_18 ( 0 , V_3 -> V_51 + V_88 ) ;
F_9 ( & V_3 -> V_27 , V_41 ) ;
return 0 ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_4 * V_5 , void * V_96 ,
unsigned int V_97 ,
unsigned int V_98 )
{
unsigned short * V_99 = V_96 ;
unsigned int V_100 = F_3 ( V_5 , V_97 ) ;
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_100 ; V_60 ++ ) {
V_99 [ V_60 ] = F_39 ( V_99 [ V_60 ] ) ;
if ( V_5 -> V_101 == 0x0fff )
V_99 [ V_60 ] >>= 4 ;
V_99 [ V_60 ] &= V_5 -> V_101 ;
}
}
static int F_40 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_102 * V_103 ,
unsigned long V_104 )
{
unsigned int V_105 ;
V_105 = F_41 ( V_3 -> V_51 + V_106 ) ;
if ( ( V_105 & V_107 ) == 0 )
return 0 ;
return - V_108 ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_102 * V_103 ,
unsigned int * V_99 )
{
unsigned int V_30 = F_20 ( V_103 -> V_109 ) ;
unsigned int V_47 = F_21 ( V_103 -> V_109 ) ;
unsigned int V_110 ;
int V_111 ;
int V_60 ;
F_17 ( V_3 , V_30 , V_30 , V_47 ) ;
for ( V_60 = 0 ; V_60 < V_103 -> V_112 ; V_60 ++ ) {
F_43 ( 0 , V_3 -> V_51 + V_113 ) ;
V_111 = F_44 ( V_3 , V_5 , V_103 , F_40 , 0 ) ;
if ( V_111 )
return V_111 ;
V_110 = F_41 ( V_3 -> V_51 + V_114 ) << 8 ;
V_110 |= F_41 ( V_3 -> V_51 + V_115 ) ;
if ( V_5 -> V_101 == 0x0fff )
V_110 >>= 4 ;
V_110 &= V_5 -> V_101 ;
V_99 [ V_60 ] = V_110 ;
}
return V_103 -> V_112 ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_102 * V_103 ,
unsigned int * V_99 )
{
unsigned int V_30 = F_20 ( V_103 -> V_109 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_103 -> V_112 ; V_60 ++ ) {
unsigned int V_110 = V_99 [ V_60 ] ;
V_5 -> V_116 [ V_30 ] = V_110 ;
V_110 <<= 4 ;
F_18 ( V_110 & 0xff , V_3 -> V_51 + F_46 ( V_30 ) ) ;
F_18 ( ( V_110 >> 8 ) & 0xff , V_3 -> V_51 + F_47 ( V_30 ) ) ;
}
return V_103 -> V_112 ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_102 * V_103 ,
unsigned int * V_99 )
{
V_99 [ 1 ] = F_41 ( V_3 -> V_51 + V_117 ) & 0xf ;
return V_103 -> V_112 ;
}
static int F_49 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_102 * V_103 ,
unsigned int * V_99 )
{
if ( F_50 ( V_5 , V_99 ) )
F_18 ( V_5 -> V_118 , V_3 -> V_51 + V_117 ) ;
V_99 [ 1 ] = V_5 -> V_118 ;
return V_103 -> V_112 ;
}
static int F_51 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
const struct V_48 * V_49 = V_3 -> V_50 ;
int V_121 ;
V_121 = F_41 ( V_3 -> V_51 + V_117 ) & 0xf0 ;
if ( V_49 -> V_122 != V_121 ) {
F_12 ( V_3 -> V_31 ,
L_5 ,
V_49 -> V_122 , V_121 ) ;
return - V_63 ;
}
return 0 ;
}
static void F_52 ( struct V_2 * V_3 )
{
F_18 ( 0 , V_3 -> V_51 + V_106 ) ;
F_18 ( 0 , V_3 -> V_51 + V_95 ) ;
F_18 ( 0 , V_3 -> V_51 + V_89 ) ;
}
static void F_53 ( struct V_2 * V_3 , unsigned int V_123 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
if ( ! ( V_123 == 1 || V_123 == 3 ) )
return;
V_8 -> V_11 = F_54 ( V_3 , 2 , V_123 , V_123 ,
V_124 , V_125 ) ;
if ( V_8 -> V_11 ) {
F_55 ( & V_8 -> V_43 , F_15 ,
( unsigned long ) V_3 ) ;
}
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
if ( V_8 ) {
if ( V_8 -> V_43 . V_99 )
F_57 ( & V_8 -> V_43 ) ;
F_58 ( V_8 -> V_11 ) ;
}
}
static const struct V_126 * F_59 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_119 * V_120 ,
unsigned int V_127 ,
unsigned int V_105 )
{
unsigned int V_128 = V_120 -> V_129 [ 4 ] ;
unsigned int V_130 = V_120 -> V_129 [ 5 ] ;
if ( V_127 == V_54 && ( V_128 || V_130 ) ) {
struct V_126 * V_131 ;
struct V_132 * V_133 ;
V_131 = F_60 ( V_5 ,
sizeof( * V_131 ) + sizeof( * V_133 ) ) ;
if ( ! V_131 )
return & V_134 ;
V_131 -> V_135 = 1 ;
V_133 = V_131 -> V_47 ;
V_133 -> V_128 = V_128 ;
V_133 -> V_130 = V_130 ;
V_133 -> V_41 = V_136 ;
return V_131 ;
}
if ( V_105 & V_137 )
return V_138 [ V_127 ] ;
return V_139 [ V_127 ] ;
}
static const struct V_126 * F_61 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_119 * V_120 )
{
unsigned int V_128 = V_120 -> V_129 [ 6 ] ;
unsigned int V_130 = V_120 -> V_129 [ 7 ] ;
if ( V_128 || V_130 ) {
struct V_126 * V_131 ;
struct V_132 * V_133 ;
V_131 = F_60 ( V_5 ,
sizeof( * V_131 ) + sizeof( * V_133 ) ) ;
if ( ! V_131 )
return & V_134 ;
V_131 -> V_135 = 1 ;
V_133 = V_131 -> V_47 ;
V_133 -> V_128 = V_128 ;
V_133 -> V_130 = V_130 ;
V_133 -> V_41 = V_136 ;
return V_131 ;
}
return & V_134 ;
}
static int F_62 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
const struct V_48 * V_49 = V_3 -> V_50 ;
struct V_7 * V_8 ;
struct V_4 * V_5 ;
unsigned int V_140 ;
unsigned int V_105 ;
int V_111 ;
if ( V_120 -> V_129 [ 3 ] ) {
if ( V_120 -> V_129 [ 3 ] != 0 &&
V_120 -> V_129 [ 3 ] != 1 && V_120 -> V_129 [ 3 ] != 10 ) {
F_12 ( V_3 -> V_31 ,
L_6 ) ;
return - V_63 ;
}
}
V_8 = F_63 ( V_3 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_141 ;
if ( V_49 -> V_18 < 0x400 ) {
V_111 = F_64 ( V_3 , V_120 -> V_129 [ 0 ] , V_49 -> V_18 ) ;
if ( V_111 )
return V_111 ;
} else {
V_111 = F_64 ( V_3 , V_120 -> V_129 [ 0 ] , 0x10 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_65 ( V_3 , V_3 -> V_51 + 0x400 ,
V_49 -> V_18 & 0x3ff ) ;
if ( V_111 )
return V_111 ;
V_8 -> V_142 = V_3 -> V_51 + 0x400 ;
V_8 -> V_69 = 1 ;
}
if ( F_51 ( V_3 , V_120 ) )
return - V_63 ;
V_140 = V_143 ;
if ( V_8 -> V_69 ) {
V_105 = F_41 ( V_3 -> V_51 + V_144 ) ;
if ( V_105 & V_145 )
V_140 = V_146 ;
} else {
if ( V_120 -> V_129 [ 3 ] )
V_140 = V_143 / V_120 -> V_129 [ 3 ] ;
}
V_3 -> V_81 = F_66 ( V_3 -> V_51 + V_147 ,
V_140 , V_148 , 0 ) ;
if ( ! V_3 -> V_81 )
return - V_141 ;
F_53 ( V_3 , V_120 -> V_129 [ 2 ] ) ;
V_111 = F_67 ( V_3 , 4 + V_49 -> V_149 ) ;
if ( V_111 )
return V_111 ;
V_105 = F_41 ( V_3 -> V_51 + V_106 ) ;
V_5 = & V_3 -> V_150 [ 0 ] ;
V_5 -> type = V_151 ;
V_5 -> V_152 = V_153 ;
if ( V_105 & V_154 ) {
V_5 -> V_152 |= V_155 ;
V_5 -> V_62 = 16 ;
} else {
V_5 -> V_152 |= V_156 ;
V_5 -> V_62 = 8 ;
}
V_5 -> V_157 = V_5 -> V_62 ;
V_5 -> V_101 = V_49 -> V_158 ;
V_5 -> V_159 = F_59 ( V_3 , V_5 , V_120 , V_49 -> V_53 , V_105 ) ;
V_5 -> V_160 = F_42 ;
if ( V_8 -> V_11 ) {
V_3 -> V_19 = V_5 ;
V_5 -> V_152 |= V_161 ;
V_5 -> V_162 = F_23 ;
V_5 -> V_163 = F_32 ;
V_5 -> V_164 = F_35 ;
V_5 -> V_165 = F_38 ;
}
V_5 = & V_3 -> V_150 [ 1 ] ;
if ( V_49 -> V_166 ) {
V_5 -> type = V_167 ;
V_5 -> V_152 = V_168 ;
V_5 -> V_62 = 2 ;
V_5 -> V_101 = 0x0fff ;
V_5 -> V_159 = F_61 ( V_3 , V_5 , V_120 ) ;
V_5 -> V_169 = F_45 ;
V_111 = F_68 ( V_5 ) ;
if ( V_111 )
return V_111 ;
} else {
V_5 -> type = V_170 ;
}
V_5 = & V_3 -> V_150 [ 2 ] ;
V_5 -> type = V_171 ;
V_5 -> V_152 = V_153 ;
V_5 -> V_62 = 4 ;
V_5 -> V_101 = 1 ;
V_5 -> V_159 = & V_172 ;
V_5 -> V_173 = F_48 ;
V_5 = & V_3 -> V_150 [ 3 ] ;
V_5 -> type = V_174 ;
V_5 -> V_152 = V_168 ;
V_5 -> V_62 = 4 ;
V_5 -> V_101 = 1 ;
V_5 -> V_159 = & V_172 ;
V_5 -> V_173 = F_49 ;
F_18 ( V_5 -> V_118 , V_3 -> V_51 + V_117 ) ;
if ( V_49 -> V_149 ) {
V_5 = & V_3 -> V_150 [ 4 ] ;
V_111 = F_69 ( V_3 , V_5 , NULL , V_49 -> V_175 ) ;
if ( V_111 )
return V_111 ;
}
F_52 ( V_3 ) ;
V_8 -> V_28 = F_70 ( V_3 -> V_176 ) ;
F_18 ( V_8 -> V_28 , V_3 -> V_51 + V_95 ) ;
if ( V_8 -> V_69 ) {
F_18 ( V_177 , V_3 -> V_51 + V_178 ) ;
F_18 ( 0 , V_3 -> V_51 + V_86 ) ;
F_18 ( 0 , V_3 -> V_51 + V_88 ) ;
}
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
const struct V_48 * V_49 = V_3 -> V_50 ;
struct V_7 * V_8 = V_3 -> V_9 ;
if ( V_8 ) {
if ( V_3 -> V_51 )
F_52 ( V_3 ) ;
F_56 ( V_3 ) ;
if ( V_8 -> V_142 )
F_72 ( V_8 -> V_142 ,
V_49 -> V_18 & 0x3ff ) ;
}
F_73 ( V_3 ) ;
}
