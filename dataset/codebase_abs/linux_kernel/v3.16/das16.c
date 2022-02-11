static inline int F_1 ( void )
{
return V_1 / 20 ;
}
static void F_2 ( struct V_2 * V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
V_7 -> V_9 &= ~ ( V_10 |
V_11 |
V_12 ) ;
V_7 -> V_9 |= V_4 ;
if ( V_5 == V_13 )
V_7 -> V_9 |= V_14 ;
else
V_7 -> V_9 |= V_15 ;
F_3 ( V_7 -> V_9 , V_3 -> V_16 + V_17 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
V_7 -> V_9 &= ~ ( V_10 |
V_11 |
V_12 ) ;
F_3 ( V_7 -> V_9 , V_3 -> V_16 + V_17 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
int V_18 ;
int V_19 ;
static const int V_20 = 100 ;
static const int V_21 = 100 ;
F_6 ( V_7 -> V_22 ) ;
V_18 = F_7 ( V_7 -> V_22 ) ;
for ( V_19 = 0 ; V_19 < V_20 && ( V_18 % 2 ) ; ++ V_19 ) {
int V_23 ;
F_8 ( V_7 -> V_22 ) ;
for ( V_23 = 0 ; V_23 < V_21 ; ++ V_23 ) {
int V_24 ;
F_9 ( 2 ) ;
V_24 = F_7 ( V_7 -> V_22 ) ;
if ( V_24 != V_18 )
break;
}
F_6 ( V_7 -> V_22 ) ;
V_18 = F_7 ( V_7 -> V_22 ) ;
}
if ( V_19 == V_20 ) {
F_10 ( V_3 -> V_25 ,
L_1 ) ;
}
return V_18 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_26 * V_27 = V_3 -> V_28 ;
struct V_29 * V_30 = V_27 -> V_30 ;
struct V_31 * V_32 = & V_30 -> V_32 ;
unsigned long V_33 ;
unsigned long V_34 ;
int V_35 , V_18 ;
int V_36 ;
F_12 ( & V_3 -> V_37 , V_33 ) ;
if ( ! ( V_7 -> V_9 & V_11 ) ) {
F_13 ( & V_3 -> V_37 , V_33 ) ;
return;
}
V_34 = F_14 () ;
F_15 ( V_7 -> V_22 ) ;
V_18 = F_5 ( V_3 ) ;
if ( V_18 > V_7 -> V_38 ) {
F_10 ( V_3 -> V_25 , L_2 ) ;
V_30 -> V_39 |= V_40 | V_41 ;
V_35 = 0 ;
} else
V_35 = V_7 -> V_38 - V_18 ;
if ( V_32 -> V_42 == V_43 &&
V_35 >= V_7 -> V_44 ) {
V_35 = V_7 -> V_44 ;
V_30 -> V_39 |= V_41 ;
}
V_36 = V_7 -> V_45 ;
V_7 -> V_45 = ( V_7 -> V_45 + 1 ) % 2 ;
V_7 -> V_44 -= V_35 ;
if ( ( V_30 -> V_39 & V_41 ) == 0 ) {
F_16 ( V_7 -> V_22 ,
V_7 -> V_46 [ V_7 -> V_45 ] ) ;
F_17 ( V_7 -> V_22 , V_7 -> V_38 ) ;
F_8 ( V_7 -> V_22 ) ;
}
F_18 ( V_34 ) ;
F_13 ( & V_3 -> V_37 , V_33 ) ;
F_19 ( V_27 ,
V_7 -> V_47 [ V_36 ] , V_35 ) ;
F_20 ( V_3 , V_27 ) ;
}
static void F_21 ( unsigned long V_48 )
{
struct V_2 * V_3 = (struct V_2 * ) V_48 ;
struct V_6 * V_7 = V_3 -> V_8 ;
F_11 ( V_3 ) ;
if ( V_7 -> V_49 )
F_22 ( & V_7 -> V_50 , V_51 + F_1 () ) ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_31 * V_32 )
{
unsigned int V_52 = F_24 ( V_32 -> V_53 [ 0 ] ) ;
unsigned int V_54 = F_25 ( V_32 -> V_53 [ 0 ] ) ;
int V_19 ;
for ( V_19 = 1 ; V_19 < V_32 -> V_55 ; V_19 ++ ) {
unsigned int V_56 = F_24 ( V_32 -> V_53 [ V_19 ] ) ;
unsigned int V_57 = F_25 ( V_32 -> V_53 [ V_19 ] ) ;
if ( V_56 != ( ( V_52 + V_19 ) % V_27 -> V_58 ) ) {
F_26 ( V_3 -> V_25 ,
L_3 ) ;
return - V_59 ;
}
if ( V_57 != V_54 ) {
F_26 ( V_3 -> V_25 ,
L_4 ) ;
return - V_59 ;
}
}
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_26 * V_27 ,
struct V_31 * V_32 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_8 ;
int V_62 = 0 ;
unsigned int V_63 ;
unsigned int V_48 ;
V_62 |= F_29 ( & V_32 -> V_64 , V_65 ) ;
V_63 = V_66 ;
if ( V_7 -> V_67 )
V_63 |= V_68 | V_13 ;
V_62 |= F_29 ( & V_32 -> V_69 , V_63 ) ;
V_63 = V_68 | V_13 ;
if ( V_7 -> V_67 )
V_63 |= V_65 ;
V_62 |= F_29 ( & V_32 -> V_70 , V_63 ) ;
V_62 |= F_29 ( & V_32 -> V_71 , V_43 ) ;
V_62 |= F_29 ( & V_32 -> V_42 , V_43 | V_72 ) ;
if ( V_62 )
return 1 ;
V_62 |= F_30 ( V_32 -> V_69 ) ;
V_62 |= F_30 ( V_32 -> V_70 ) ;
V_62 |= F_30 ( V_32 -> V_42 ) ;
if ( V_32 -> V_69 == V_66 && V_32 -> V_70 == V_65 )
V_62 |= - V_59 ;
if ( V_32 -> V_69 != V_66 && V_32 -> V_70 != V_65 )
V_62 |= - V_59 ;
if ( V_62 )
return 2 ;
V_62 |= F_31 ( & V_32 -> V_73 , 0 ) ;
if ( V_32 -> V_69 == V_66 )
V_62 |= F_31 ( & V_32 -> V_74 , 0 ) ;
V_62 |= F_31 ( & V_32 -> V_75 , V_32 -> V_55 ) ;
if ( V_32 -> V_69 == V_68 )
V_62 |= F_32 ( & V_32 -> V_74 ,
V_61 -> V_76 * V_32 -> V_55 ) ;
if ( V_32 -> V_70 == V_68 )
V_62 |= F_32 ( & V_32 -> V_77 ,
V_61 -> V_76 ) ;
if ( V_32 -> V_42 == V_72 )
V_62 |= F_31 ( & V_32 -> V_78 , 0 ) ;
if ( V_62 )
return 3 ;
if ( V_32 -> V_69 == V_68 ) {
V_48 = V_32 -> V_74 ;
F_33 ( V_7 -> V_79 ,
& V_7 -> V_80 ,
& V_7 -> V_81 ,
& V_48 , V_32 -> V_82 ) ;
V_62 |= F_31 ( & V_32 -> V_74 , V_48 ) ;
}
if ( V_32 -> V_70 == V_68 ) {
V_48 = V_32 -> V_77 ;
F_33 ( V_7 -> V_79 ,
& V_7 -> V_80 ,
& V_7 -> V_81 ,
& V_48 , V_32 -> V_82 ) ;
V_62 |= F_31 ( & V_32 -> V_77 , V_48 ) ;
}
if ( V_62 )
return 4 ;
if ( V_32 -> V_53 && V_32 -> V_55 > 0 )
V_62 |= F_23 ( V_3 , V_27 , V_32 ) ;
if ( V_62 )
return 5 ;
return 0 ;
}
static unsigned int F_34 ( struct V_2 * V_3 , unsigned int V_83 ,
int V_84 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
unsigned long V_85 = V_3 -> V_16 + V_86 ;
F_33 ( V_7 -> V_79 ,
& V_7 -> V_80 , & V_7 -> V_81 ,
& V_83 , V_84 ) ;
F_35 ( V_85 , 0 , 1 , V_87 | V_88 ) ;
F_35 ( V_85 , 0 , 2 , V_87 | V_88 ) ;
F_36 ( V_85 , 0 , 1 , V_7 -> V_80 ) ;
F_36 ( V_85 , 0 , 2 , V_7 -> V_81 ) ;
return V_83 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_26 * V_27 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_29 * V_30 = V_27 -> V_30 ;
struct V_31 * V_32 = & V_30 -> V_32 ;
unsigned int V_89 ;
unsigned long V_82 ;
int V_57 ;
if ( V_32 -> V_82 & V_90 ) {
F_10 ( V_3 -> V_25 ,
L_5 ) ;
return - 1 ;
}
V_7 -> V_44 = V_32 -> V_78 * F_38 ( V_27 ) ;
if ( V_7 -> V_67 )
F_3 ( V_91 , V_3 -> V_16 + V_92 ) ;
V_89 = F_24 ( V_32 -> V_53 [ 0 ] ) ;
V_89 |= F_24 ( V_32 -> V_53 [ V_32 -> V_55 - 1 ] ) << 4 ;
F_3 ( V_89 , V_3 -> V_16 + V_93 ) ;
if ( V_61 -> V_94 != V_95 ) {
V_57 = F_25 ( V_32 -> V_53 [ 0 ] ) ;
F_3 ( ( V_96 [ V_61 -> V_94 ] ) [ V_57 ] ,
V_3 -> V_16 + V_97 ) ;
}
V_32 -> V_77 =
F_34 ( V_3 , V_32 -> V_77 ,
V_32 -> V_82 & V_98 ) ;
V_89 = 0 ;
if ( V_7 -> V_67 ) {
if ( V_32 -> V_70 == V_65 ) {
F_3 ( V_99 ,
V_3 -> V_16 + V_100 ) ;
V_89 |= F_39 ( V_32 -> V_55 - 1 ) ;
} else {
F_3 ( 0 , V_3 -> V_16 + V_100 ) ;
}
}
F_3 ( V_89 , V_3 -> V_16 + V_101 ) ;
V_82 = F_14 () ;
F_6 ( V_7 -> V_22 ) ;
F_15 ( V_7 -> V_22 ) ;
V_7 -> V_45 = 0 ;
F_16 ( V_7 -> V_22 ,
V_7 -> V_46 [ V_7 -> V_45 ] ) ;
V_7 -> V_38 = V_102 ;
F_17 ( V_7 -> V_22 , V_7 -> V_38 ) ;
F_8 ( V_7 -> V_22 ) ;
F_18 ( V_82 ) ;
V_7 -> V_49 = 1 ;
V_7 -> V_50 . V_103 = V_51 + F_1 () ;
F_40 ( & V_7 -> V_50 ) ;
F_2 ( V_3 , V_11 , V_32 -> V_70 ) ;
if ( V_7 -> V_67 )
F_3 ( 0 , V_3 -> V_16 + V_92 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_26 * V_27 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
unsigned long V_82 ;
F_12 ( & V_3 -> V_37 , V_82 ) ;
F_4 ( V_3 ) ;
F_6 ( V_7 -> V_22 ) ;
if ( V_7 -> V_49 ) {
V_7 -> V_49 = 0 ;
F_42 ( & V_7 -> V_50 ) ;
}
if ( V_7 -> V_67 )
F_3 ( 0 , V_3 -> V_16 + V_100 ) ;
F_13 ( & V_3 -> V_37 , V_82 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_26 * V_27 , void * V_104 ,
unsigned int V_35 ,
unsigned int V_105 )
{
unsigned int V_19 , V_106 = V_35 / sizeof( short ) ;
unsigned short * V_107 = V_104 ;
for ( V_19 = 0 ; V_19 < V_106 ; V_19 ++ ) {
V_107 [ V_19 ] = F_44 ( V_107 [ V_19 ] ) ;
if ( V_27 -> V_108 == 0x0fff )
V_107 [ V_19 ] >>= 4 ;
V_107 [ V_19 ] &= V_27 -> V_108 ;
}
}
static int F_45 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_109 * V_110 ,
unsigned long V_111 )
{
unsigned int V_112 ;
V_112 = F_46 ( V_3 -> V_16 + V_113 ) ;
if ( ( V_112 & V_114 ) == 0 )
return 0 ;
return - V_115 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_109 * V_110 ,
unsigned int * V_107 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
unsigned int V_56 = F_24 ( V_110 -> V_116 ) ;
unsigned int V_57 = F_25 ( V_110 -> V_116 ) ;
unsigned int V_117 ;
int V_118 ;
int V_19 ;
F_4 ( V_3 ) ;
F_3 ( V_56 | ( V_56 << 4 ) , V_3 -> V_16 + V_93 ) ;
if ( V_61 -> V_94 != V_95 ) {
F_3 ( ( V_96 [ V_61 -> V_94 ] ) [ V_57 ] ,
V_3 -> V_16 + V_97 ) ;
}
for ( V_19 = 0 ; V_19 < V_110 -> V_119 ; V_19 ++ ) {
F_48 ( 0 , V_3 -> V_16 + V_120 ) ;
V_118 = F_49 ( V_3 , V_27 , V_110 , F_45 , 0 ) ;
if ( V_118 )
return V_118 ;
V_117 = F_46 ( V_3 -> V_16 + V_121 ) << 8 ;
V_117 |= F_46 ( V_3 -> V_16 + V_122 ) ;
if ( V_27 -> V_108 == 0x0fff )
V_117 >>= 4 ;
V_117 &= V_27 -> V_108 ;
V_107 [ V_19 ] = V_117 ;
}
return V_110 -> V_119 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_109 * V_110 ,
unsigned int * V_107 )
{
unsigned int V_56 = F_24 ( V_110 -> V_116 ) ;
unsigned int V_117 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_110 -> V_119 ; V_19 ++ ) {
V_117 = V_107 [ V_19 ] ;
V_117 <<= 4 ;
F_3 ( V_117 & 0xff , V_3 -> V_16 + F_51 ( V_56 ) ) ;
F_3 ( ( V_117 >> 8 ) & 0xff , V_3 -> V_16 + F_52 ( V_56 ) ) ;
}
return V_110 -> V_119 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_109 * V_110 ,
unsigned int * V_107 )
{
V_107 [ 1 ] = F_46 ( V_3 -> V_16 + V_123 ) & 0xf ;
return V_110 -> V_119 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_109 * V_110 ,
unsigned int * V_107 )
{
if ( F_55 ( V_27 , V_107 ) )
F_3 ( V_27 -> V_124 , V_3 -> V_16 + V_123 ) ;
V_107 [ 1 ] = V_27 -> V_124 ;
return V_110 -> V_119 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_125 * V_126 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
int V_127 ;
V_127 = F_46 ( V_3 -> V_16 + V_123 ) & 0xf0 ;
if ( V_61 -> V_128 != V_127 ) {
F_10 ( V_3 -> V_25 ,
L_6 ,
V_61 -> V_128 , V_127 ) ;
return - V_59 ;
}
return 0 ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_3 ( 0 , V_3 -> V_16 + V_113 ) ;
F_3 ( 0 , V_3 -> V_16 + V_17 ) ;
F_3 ( 0 , V_3 -> V_16 + V_101 ) ;
F_3 ( 0 , V_3 -> V_16 + V_86 + V_129 ) ;
}
static int F_58 ( struct V_2 * V_3 , struct V_125 * V_126 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
struct V_6 * V_7 ;
struct V_26 * V_27 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
unsigned int V_22 = V_126 -> V_134 [ 2 ] ;
unsigned int V_112 ;
int V_118 ;
if ( V_126 -> V_134 [ 3 ] ) {
if ( V_126 -> V_134 [ 3 ] != 0 &&
V_126 -> V_134 [ 3 ] != 1 && V_126 -> V_134 [ 3 ] != 10 ) {
F_10 ( V_3 -> V_25 ,
L_7 ) ;
return - V_59 ;
}
}
V_7 = F_59 ( V_3 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_135 ;
if ( V_61 -> V_136 < 0x400 ) {
V_118 = F_60 ( V_3 , V_126 -> V_134 [ 0 ] , V_61 -> V_136 ) ;
if ( V_118 )
return V_118 ;
} else {
V_118 = F_60 ( V_3 , V_126 -> V_134 [ 0 ] , 0x10 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_61 ( V_3 , V_3 -> V_16 + 0x400 ,
V_61 -> V_136 & 0x3ff ) ;
if ( V_118 )
return V_118 ;
V_7 -> V_137 = V_3 -> V_16 + 0x400 ;
V_7 -> V_67 = 1 ;
}
if ( F_56 ( V_3 , V_126 ) )
return - V_59 ;
if ( V_7 -> V_67 ) {
V_112 = F_46 ( V_3 -> V_16 + V_138 ) ;
if ( V_112 & V_139 )
V_7 -> V_79 = V_140 ;
else
V_7 -> V_79 = V_141 ;
} else {
if ( V_126 -> V_134 [ 3 ] )
V_7 -> V_79 = V_141 /
V_126 -> V_134 [ 3 ] ;
else
V_7 -> V_79 = V_141 ;
}
if ( V_22 == 1 || V_22 == 3 ) {
unsigned long V_82 ;
int V_19 ;
if ( F_62 ( V_22 , V_3 -> V_142 ) ) {
F_10 ( V_3 -> V_25 ,
L_8 ,
V_22 ) ;
return - V_59 ;
}
V_7 -> V_22 = V_22 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
void * V_143 ;
V_143 = F_63 ( NULL , V_102 ,
& V_7 -> V_46 [ V_19 ] ) ;
if ( ! V_143 )
return - V_135 ;
V_7 -> V_47 [ V_19 ] = V_143 ;
}
V_82 = F_14 () ;
F_6 ( V_7 -> V_22 ) ;
F_64 ( V_7 -> V_22 , V_144 ) ;
F_18 ( V_82 ) ;
F_65 ( & V_7 -> V_50 ) ;
V_7 -> V_50 . V_145 = F_21 ;
V_7 -> V_50 . V_107 = ( unsigned long ) V_3 ;
}
if ( V_61 -> V_94 == V_95 &&
( V_126 -> V_134 [ 4 ] || V_126 -> V_134 [ 5 ] ) ) {
V_131 = F_66 ( sizeof( * V_131 ) + sizeof( * V_133 ) , V_146 ) ;
if ( ! V_131 )
return - V_135 ;
V_7 -> V_147 = V_131 ;
V_131 -> V_148 = 1 ;
V_133 = V_7 -> V_147 -> V_57 ;
V_133 -> V_149 = V_126 -> V_134 [ 4 ] ;
V_133 -> V_150 = V_126 -> V_134 [ 5 ] ;
V_133 -> V_82 = V_151 ;
}
if ( V_126 -> V_134 [ 6 ] || V_126 -> V_134 [ 7 ] ) {
V_131 = F_66 ( sizeof( * V_131 ) + sizeof( * V_133 ) , V_146 ) ;
if ( ! V_131 )
return - V_135 ;
V_7 -> V_152 = V_131 ;
V_131 -> V_148 = 1 ;
V_133 = V_7 -> V_152 -> V_57 ;
V_133 -> V_149 = V_126 -> V_134 [ 6 ] ;
V_133 -> V_150 = V_126 -> V_134 [ 7 ] ;
V_133 -> V_82 = V_151 ;
}
V_118 = F_67 ( V_3 , 4 + V_61 -> V_153 ) ;
if ( V_118 )
return V_118 ;
V_112 = F_46 ( V_3 -> V_16 + V_113 ) ;
V_27 = & V_3 -> V_154 [ 0 ] ;
V_27 -> type = V_155 ;
V_27 -> V_156 = V_157 ;
if ( V_112 & V_158 ) {
V_27 -> V_156 |= V_159 ;
V_27 -> V_58 = 16 ;
} else {
V_27 -> V_156 |= V_160 ;
V_27 -> V_58 = 8 ;
}
V_27 -> V_161 = V_27 -> V_58 ;
V_27 -> V_108 = V_61 -> V_162 ;
if ( V_7 -> V_147 ) {
V_27 -> V_163 = V_7 -> V_147 ;
} else if ( V_112 & V_164 ) {
V_27 -> V_163 = V_165 [ V_61 -> V_94 ] ;
} else {
V_27 -> V_163 = V_166 [ V_61 -> V_94 ] ;
}
V_27 -> V_167 = F_47 ;
if ( V_7 -> V_22 ) {
V_3 -> V_28 = V_27 ;
V_27 -> V_156 |= V_168 ;
V_27 -> V_169 = F_27 ;
V_27 -> V_170 = F_37 ;
V_27 -> V_171 = F_41 ;
V_27 -> V_172 = F_43 ;
}
V_27 = & V_3 -> V_154 [ 1 ] ;
if ( V_61 -> V_173 ) {
V_27 -> type = V_174 ;
V_27 -> V_156 = V_175 ;
V_27 -> V_58 = 2 ;
V_27 -> V_108 = 0x0fff ;
V_27 -> V_163 = V_7 -> V_152 ;
V_27 -> V_176 = F_50 ;
} else {
V_27 -> type = V_177 ;
}
V_27 = & V_3 -> V_154 [ 2 ] ;
V_27 -> type = V_178 ;
V_27 -> V_156 = V_157 ;
V_27 -> V_58 = 4 ;
V_27 -> V_108 = 1 ;
V_27 -> V_163 = & V_179 ;
V_27 -> V_180 = F_53 ;
V_27 = & V_3 -> V_154 [ 3 ] ;
V_27 -> type = V_181 ;
V_27 -> V_156 = V_175 ;
V_27 -> V_58 = 4 ;
V_27 -> V_108 = 1 ;
V_27 -> V_163 = & V_179 ;
V_27 -> V_180 = F_54 ;
F_3 ( V_27 -> V_124 , V_3 -> V_16 + V_123 ) ;
if ( V_61 -> V_153 ) {
V_27 = & V_3 -> V_154 [ 4 ] ;
V_118 = F_68 ( V_3 , V_27 , NULL ,
V_3 -> V_16 + V_61 -> V_182 ) ;
if ( V_118 )
return V_118 ;
}
F_57 ( V_3 ) ;
V_7 -> V_9 = F_69 ( V_3 -> V_183 ) ;
F_3 ( V_7 -> V_9 , V_3 -> V_16 + V_17 ) ;
if ( V_7 -> V_67 ) {
F_3 ( V_184 , V_3 -> V_16 + V_185 ) ;
F_3 ( 0 , V_3 -> V_16 + V_92 ) ;
F_3 ( 0 , V_3 -> V_16 + V_100 ) ;
}
return 0 ;
}
static void F_70 ( struct V_2 * V_3 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_8 ;
int V_19 ;
if ( V_7 ) {
if ( V_3 -> V_16 )
F_57 ( V_3 ) ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
if ( V_7 -> V_47 [ V_19 ] )
F_71 ( NULL , V_102 ,
V_7 -> V_47 [ V_19 ] ,
V_7 ->
V_46 [ V_19 ] ) ;
}
if ( V_7 -> V_22 )
F_72 ( V_7 -> V_22 ) ;
F_73 ( V_7 -> V_147 ) ;
F_73 ( V_7 -> V_152 ) ;
if ( V_7 -> V_137 )
F_74 ( V_7 -> V_137 ,
V_61 -> V_136 & 0x3ff ) ;
}
F_75 ( V_3 ) ;
}
