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
static const int V_18 = 100 ;
static const int V_19 = 100 ;
int V_20 ;
int V_21 ;
int V_22 ;
int V_23 ;
F_6 ( V_7 -> V_24 ) ;
V_20 = F_7 ( V_7 -> V_24 ) ;
for ( V_22 = 0 ; V_22 < V_18 && ( V_20 % 2 ) ; ++ V_22 ) {
F_8 ( V_7 -> V_24 ) ;
for ( V_23 = 0 ; V_23 < V_19 ; ++ V_23 ) {
F_9 ( 2 ) ;
V_21 = F_7 ( V_7 -> V_24 ) ;
if ( V_21 != V_20 )
break;
}
F_6 ( V_7 -> V_24 ) ;
V_20 = F_7 ( V_7 -> V_24 ) ;
}
if ( V_22 == V_18 ) {
F_10 ( V_3 -> V_25 ,
L_1 ) ;
}
return V_20 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_26 * V_27 = V_3 -> V_28 ;
struct V_29 * V_30 = V_27 -> V_30 ;
struct V_31 * V_32 = & V_30 -> V_32 ;
unsigned long V_33 ;
unsigned long V_34 ;
unsigned int V_35 ;
int V_36 , V_20 ;
int V_37 ;
F_12 ( & V_3 -> V_38 , V_33 ) ;
if ( ! ( V_7 -> V_9 & V_11 ) ) {
F_13 ( & V_3 -> V_38 , V_33 ) ;
return;
}
V_34 = F_14 () ;
F_15 ( V_7 -> V_24 ) ;
V_20 = F_5 ( V_3 ) ;
if ( V_20 > V_7 -> V_39 ) {
F_10 ( V_3 -> V_25 , L_2 ) ;
V_30 -> V_40 |= V_41 | V_42 ;
V_36 = 0 ;
} else
V_36 = V_7 -> V_39 - V_20 ;
if ( V_32 -> V_43 == V_44 &&
V_36 >= V_7 -> V_45 ) {
V_36 = V_7 -> V_45 ;
V_30 -> V_40 |= V_42 ;
}
V_37 = V_7 -> V_46 ;
V_7 -> V_46 = ( V_7 -> V_46 + 1 ) % 2 ;
V_7 -> V_45 -= V_36 ;
if ( ( V_30 -> V_40 & V_42 ) == 0 ) {
F_16 ( V_7 -> V_24 ,
V_7 -> V_47 [ V_7 -> V_46 ] ) ;
F_17 ( V_7 -> V_24 , V_7 -> V_39 ) ;
F_8 ( V_7 -> V_24 ) ;
}
F_18 ( V_34 ) ;
F_13 ( & V_3 -> V_38 , V_33 ) ;
V_35 = F_19 ( V_27 , V_36 ) ;
F_20 ( V_27 , V_7 -> V_48 [ V_37 ] ,
V_35 ) ;
F_21 ( V_3 , V_27 ) ;
}
static void F_22 ( unsigned long V_49 )
{
struct V_2 * V_3 = (struct V_2 * ) V_49 ;
struct V_6 * V_7 = V_3 -> V_8 ;
unsigned long V_50 ;
F_11 ( V_3 ) ;
F_12 ( & V_3 -> V_38 , V_50 ) ;
if ( V_7 -> V_51 )
F_23 ( & V_7 -> V_52 , V_53 + F_1 () ) ;
F_13 ( & V_3 -> V_38 , V_50 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_31 * V_32 )
{
unsigned int V_54 = F_25 ( V_32 -> V_55 [ 0 ] ) ;
unsigned int V_56 = F_26 ( V_32 -> V_55 [ 0 ] ) ;
int V_22 ;
for ( V_22 = 1 ; V_22 < V_32 -> V_57 ; V_22 ++ ) {
unsigned int V_58 = F_25 ( V_32 -> V_55 [ V_22 ] ) ;
unsigned int V_59 = F_26 ( V_32 -> V_55 [ V_22 ] ) ;
if ( V_58 != ( ( V_54 + V_22 ) % V_27 -> V_60 ) ) {
F_27 ( V_3 -> V_25 ,
L_3 ) ;
return - V_61 ;
}
if ( V_59 != V_56 ) {
F_27 ( V_3 -> V_25 ,
L_4 ) ;
return - V_61 ;
}
}
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_26 * V_27 ,
struct V_31 * V_32 )
{
const struct V_62 * V_63 = V_3 -> V_64 ;
struct V_6 * V_7 = V_3 -> V_8 ;
int V_65 = 0 ;
unsigned int V_66 ;
unsigned int V_49 ;
V_65 |= F_29 ( & V_32 -> V_67 , V_68 ) ;
V_66 = V_69 ;
if ( V_7 -> V_70 )
V_66 |= V_71 | V_13 ;
V_65 |= F_29 ( & V_32 -> V_72 , V_66 ) ;
V_66 = V_71 | V_13 ;
if ( V_7 -> V_70 )
V_66 |= V_68 ;
V_65 |= F_29 ( & V_32 -> V_73 , V_66 ) ;
V_65 |= F_29 ( & V_32 -> V_74 , V_44 ) ;
V_65 |= F_29 ( & V_32 -> V_43 , V_44 | V_75 ) ;
if ( V_65 )
return 1 ;
V_65 |= F_30 ( V_32 -> V_72 ) ;
V_65 |= F_30 ( V_32 -> V_73 ) ;
V_65 |= F_30 ( V_32 -> V_43 ) ;
if ( V_32 -> V_72 == V_69 && V_32 -> V_73 == V_68 )
V_65 |= - V_61 ;
if ( V_32 -> V_72 != V_69 && V_32 -> V_73 != V_68 )
V_65 |= - V_61 ;
if ( V_65 )
return 2 ;
V_65 |= F_31 ( & V_32 -> V_76 , 0 ) ;
if ( V_32 -> V_72 == V_69 )
V_65 |= F_31 ( & V_32 -> V_77 , 0 ) ;
V_65 |= F_31 ( & V_32 -> V_78 , V_32 -> V_57 ) ;
if ( V_32 -> V_72 == V_71 )
V_65 |= F_32 ( & V_32 -> V_77 ,
V_63 -> V_79 * V_32 -> V_57 ) ;
if ( V_32 -> V_73 == V_71 )
V_65 |= F_32 ( & V_32 -> V_80 ,
V_63 -> V_79 ) ;
if ( V_32 -> V_43 == V_44 )
V_65 |= F_32 ( & V_32 -> V_81 , 1 ) ;
else
V_65 |= F_31 ( & V_32 -> V_81 , 0 ) ;
if ( V_65 )
return 3 ;
if ( V_32 -> V_72 == V_71 ) {
V_49 = V_32 -> V_77 ;
F_33 ( V_7 -> V_82 ,
& V_7 -> V_83 ,
& V_7 -> V_84 ,
& V_49 , V_32 -> V_50 ) ;
V_65 |= F_31 ( & V_32 -> V_77 , V_49 ) ;
}
if ( V_32 -> V_73 == V_71 ) {
V_49 = V_32 -> V_80 ;
F_33 ( V_7 -> V_82 ,
& V_7 -> V_83 ,
& V_7 -> V_84 ,
& V_49 , V_32 -> V_50 ) ;
V_65 |= F_31 ( & V_32 -> V_80 , V_49 ) ;
}
if ( V_65 )
return 4 ;
if ( V_32 -> V_55 && V_32 -> V_57 > 0 )
V_65 |= F_24 ( V_3 , V_27 , V_32 ) ;
if ( V_65 )
return 5 ;
return 0 ;
}
static unsigned int F_34 ( struct V_2 * V_3 , unsigned int V_85 ,
unsigned int V_50 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
unsigned long V_86 = V_3 -> V_16 + V_87 ;
F_33 ( V_7 -> V_82 ,
& V_7 -> V_83 , & V_7 -> V_84 ,
& V_85 , V_50 ) ;
F_35 ( V_86 , 0 , 1 , V_88 | V_89 ) ;
F_35 ( V_86 , 0 , 2 , V_88 | V_89 ) ;
F_36 ( V_86 , 0 , 1 , V_7 -> V_83 ) ;
F_36 ( V_86 , 0 , 2 , V_7 -> V_84 ) ;
return V_85 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_26 * V_27 )
{
const struct V_62 * V_63 = V_3 -> V_64 ;
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_29 * V_30 = V_27 -> V_30 ;
struct V_31 * V_32 = & V_30 -> V_32 ;
unsigned int V_90 ;
unsigned long V_50 ;
int V_59 ;
if ( V_32 -> V_50 & V_91 ) {
F_10 ( V_3 -> V_25 ,
L_5 ) ;
return - 1 ;
}
V_7 -> V_45 = V_32 -> V_81 * F_38 ( V_27 ) ;
if ( V_7 -> V_70 )
F_3 ( V_92 , V_3 -> V_16 + V_93 ) ;
V_90 = F_25 ( V_32 -> V_55 [ 0 ] ) ;
V_90 |= F_25 ( V_32 -> V_55 [ V_32 -> V_57 - 1 ] ) << 4 ;
F_3 ( V_90 , V_3 -> V_16 + V_94 ) ;
if ( V_63 -> V_95 != V_96 ) {
V_59 = F_26 ( V_32 -> V_55 [ 0 ] ) ;
F_3 ( ( V_97 [ V_63 -> V_95 ] ) [ V_59 ] ,
V_3 -> V_16 + V_98 ) ;
}
V_32 -> V_80 = F_34 ( V_3 , V_32 -> V_80 , V_32 -> V_50 ) ;
V_90 = 0 ;
if ( V_7 -> V_70 ) {
if ( V_32 -> V_73 == V_68 ) {
F_3 ( V_99 ,
V_3 -> V_16 + V_100 ) ;
V_90 |= F_39 ( V_32 -> V_57 - 1 ) ;
} else {
F_3 ( 0 , V_3 -> V_16 + V_100 ) ;
}
}
F_3 ( V_90 , V_3 -> V_16 + V_101 ) ;
V_50 = F_14 () ;
F_6 ( V_7 -> V_24 ) ;
F_15 ( V_7 -> V_24 ) ;
V_7 -> V_46 = 0 ;
F_16 ( V_7 -> V_24 ,
V_7 -> V_47 [ V_7 -> V_46 ] ) ;
V_7 -> V_39 = V_102 ;
F_17 ( V_7 -> V_24 , V_7 -> V_39 ) ;
F_8 ( V_7 -> V_24 ) ;
F_18 ( V_50 ) ;
F_12 ( & V_3 -> V_38 , V_50 ) ;
V_7 -> V_51 = 1 ;
V_7 -> V_52 . V_103 = V_53 + F_1 () ;
F_40 ( & V_7 -> V_52 ) ;
F_2 ( V_3 , V_11 , V_32 -> V_73 ) ;
if ( V_7 -> V_70 )
F_3 ( 0 , V_3 -> V_16 + V_93 ) ;
F_13 ( & V_3 -> V_38 , V_50 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_26 * V_27 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
unsigned long V_50 ;
F_12 ( & V_3 -> V_38 , V_50 ) ;
F_4 ( V_3 ) ;
F_6 ( V_7 -> V_24 ) ;
if ( V_7 -> V_51 ) {
V_7 -> V_51 = 0 ;
F_42 ( & V_7 -> V_52 ) ;
}
if ( V_7 -> V_70 )
F_3 ( 0 , V_3 -> V_16 + V_100 ) ;
F_13 ( & V_3 -> V_38 , V_50 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_26 * V_27 , void * V_104 ,
unsigned int V_36 ,
unsigned int V_105 )
{
unsigned short * V_106 = V_104 ;
unsigned int V_107 = F_19 ( V_27 , V_36 ) ;
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < V_107 ; V_22 ++ ) {
V_106 [ V_22 ] = F_44 ( V_106 [ V_22 ] ) ;
if ( V_27 -> V_108 == 0x0fff )
V_106 [ V_22 ] >>= 4 ;
V_106 [ V_22 ] &= V_27 -> V_108 ;
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
unsigned int * V_106 )
{
const struct V_62 * V_63 = V_3 -> V_64 ;
unsigned int V_58 = F_25 ( V_110 -> V_116 ) ;
unsigned int V_59 = F_26 ( V_110 -> V_116 ) ;
unsigned int V_117 ;
int V_118 ;
int V_22 ;
F_4 ( V_3 ) ;
F_3 ( V_58 | ( V_58 << 4 ) , V_3 -> V_16 + V_94 ) ;
if ( V_63 -> V_95 != V_96 ) {
F_3 ( ( V_97 [ V_63 -> V_95 ] ) [ V_59 ] ,
V_3 -> V_16 + V_98 ) ;
}
for ( V_22 = 0 ; V_22 < V_110 -> V_119 ; V_22 ++ ) {
F_48 ( 0 , V_3 -> V_16 + V_120 ) ;
V_118 = F_49 ( V_3 , V_27 , V_110 , F_45 , 0 ) ;
if ( V_118 )
return V_118 ;
V_117 = F_46 ( V_3 -> V_16 + V_121 ) << 8 ;
V_117 |= F_46 ( V_3 -> V_16 + V_122 ) ;
if ( V_27 -> V_108 == 0x0fff )
V_117 >>= 4 ;
V_117 &= V_27 -> V_108 ;
V_106 [ V_22 ] = V_117 ;
}
return V_110 -> V_119 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_109 * V_110 ,
unsigned int * V_106 )
{
unsigned int V_58 = F_25 ( V_110 -> V_116 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_110 -> V_119 ; V_22 ++ ) {
unsigned int V_117 = V_106 [ V_22 ] ;
V_27 -> V_123 [ V_58 ] = V_117 ;
V_117 <<= 4 ;
F_3 ( V_117 & 0xff , V_3 -> V_16 + F_51 ( V_58 ) ) ;
F_3 ( ( V_117 >> 8 ) & 0xff , V_3 -> V_16 + F_52 ( V_58 ) ) ;
}
return V_110 -> V_119 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_109 * V_110 ,
unsigned int * V_106 )
{
V_106 [ 1 ] = F_46 ( V_3 -> V_16 + V_124 ) & 0xf ;
return V_110 -> V_119 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_109 * V_110 ,
unsigned int * V_106 )
{
if ( F_55 ( V_27 , V_106 ) )
F_3 ( V_27 -> V_125 , V_3 -> V_16 + V_124 ) ;
V_106 [ 1 ] = V_27 -> V_125 ;
return V_110 -> V_119 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_126 * V_127 )
{
const struct V_62 * V_63 = V_3 -> V_64 ;
int V_128 ;
V_128 = F_46 ( V_3 -> V_16 + V_124 ) & 0xf0 ;
if ( V_63 -> V_129 != V_128 ) {
F_10 ( V_3 -> V_25 ,
L_6 ,
V_63 -> V_129 , V_128 ) ;
return - V_61 ;
}
return 0 ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_3 ( 0 , V_3 -> V_16 + V_113 ) ;
F_3 ( 0 , V_3 -> V_16 + V_17 ) ;
F_3 ( 0 , V_3 -> V_16 + V_101 ) ;
F_3 ( 0 , V_3 -> V_16 + V_87 + V_130 ) ;
}
static int F_58 ( struct V_2 * V_3 , struct V_126 * V_127 )
{
const struct V_62 * V_63 = V_3 -> V_64 ;
struct V_6 * V_7 ;
struct V_26 * V_27 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
unsigned int V_24 = V_127 -> V_135 [ 2 ] ;
unsigned int V_112 ;
int V_118 ;
if ( V_127 -> V_135 [ 3 ] ) {
if ( V_127 -> V_135 [ 3 ] != 0 &&
V_127 -> V_135 [ 3 ] != 1 && V_127 -> V_135 [ 3 ] != 10 ) {
F_10 ( V_3 -> V_25 ,
L_7 ) ;
return - V_61 ;
}
}
V_7 = F_59 ( V_3 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_136 ;
if ( V_63 -> V_137 < 0x400 ) {
V_118 = F_60 ( V_3 , V_127 -> V_135 [ 0 ] , V_63 -> V_137 ) ;
if ( V_118 )
return V_118 ;
} else {
V_118 = F_60 ( V_3 , V_127 -> V_135 [ 0 ] , 0x10 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_61 ( V_3 , V_3 -> V_16 + 0x400 ,
V_63 -> V_137 & 0x3ff ) ;
if ( V_118 )
return V_118 ;
V_7 -> V_138 = V_3 -> V_16 + 0x400 ;
V_7 -> V_70 = 1 ;
}
if ( F_56 ( V_3 , V_127 ) )
return - V_61 ;
if ( V_7 -> V_70 ) {
V_112 = F_46 ( V_3 -> V_16 + V_139 ) ;
if ( V_112 & V_140 )
V_7 -> V_82 = V_141 ;
else
V_7 -> V_82 = V_142 ;
} else {
if ( V_127 -> V_135 [ 3 ] )
V_7 -> V_82 = V_142 /
V_127 -> V_135 [ 3 ] ;
else
V_7 -> V_82 = V_142 ;
}
if ( V_24 == 1 || V_24 == 3 ) {
unsigned long V_50 ;
int V_22 ;
if ( F_62 ( V_24 , V_3 -> V_143 ) ) {
F_10 ( V_3 -> V_25 ,
L_8 ,
V_24 ) ;
return - V_61 ;
}
V_7 -> V_24 = V_24 ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
void * V_144 ;
V_144 = F_63 ( NULL , V_102 ,
& V_7 -> V_47 [ V_22 ] ) ;
if ( ! V_144 )
return - V_136 ;
V_7 -> V_48 [ V_22 ] = V_144 ;
}
V_50 = F_14 () ;
F_6 ( V_7 -> V_24 ) ;
F_64 ( V_7 -> V_24 , V_145 ) ;
F_18 ( V_50 ) ;
F_65 ( & V_7 -> V_52 ) ;
V_7 -> V_52 . V_146 = F_22 ;
V_7 -> V_52 . V_106 = ( unsigned long ) V_3 ;
}
if ( V_63 -> V_95 == V_96 &&
( V_127 -> V_135 [ 4 ] || V_127 -> V_135 [ 5 ] ) ) {
V_132 = F_66 ( sizeof( * V_132 ) + sizeof( * V_134 ) , V_147 ) ;
if ( ! V_132 )
return - V_136 ;
V_7 -> V_148 = V_132 ;
V_132 -> V_149 = 1 ;
V_134 = V_7 -> V_148 -> V_59 ;
V_134 -> V_150 = V_127 -> V_135 [ 4 ] ;
V_134 -> V_151 = V_127 -> V_135 [ 5 ] ;
V_134 -> V_50 = V_152 ;
}
if ( V_127 -> V_135 [ 6 ] || V_127 -> V_135 [ 7 ] ) {
V_132 = F_66 ( sizeof( * V_132 ) + sizeof( * V_134 ) , V_147 ) ;
if ( ! V_132 )
return - V_136 ;
V_7 -> V_153 = V_132 ;
V_132 -> V_149 = 1 ;
V_134 = V_7 -> V_153 -> V_59 ;
V_134 -> V_150 = V_127 -> V_135 [ 6 ] ;
V_134 -> V_151 = V_127 -> V_135 [ 7 ] ;
V_134 -> V_50 = V_152 ;
}
V_118 = F_67 ( V_3 , 4 + V_63 -> V_154 ) ;
if ( V_118 )
return V_118 ;
V_112 = F_46 ( V_3 -> V_16 + V_113 ) ;
V_27 = & V_3 -> V_155 [ 0 ] ;
V_27 -> type = V_156 ;
V_27 -> V_157 = V_158 ;
if ( V_112 & V_159 ) {
V_27 -> V_157 |= V_160 ;
V_27 -> V_60 = 16 ;
} else {
V_27 -> V_157 |= V_161 ;
V_27 -> V_60 = 8 ;
}
V_27 -> V_162 = V_27 -> V_60 ;
V_27 -> V_108 = V_63 -> V_163 ;
if ( V_7 -> V_148 ) {
V_27 -> V_164 = V_7 -> V_148 ;
} else if ( V_112 & V_165 ) {
V_27 -> V_164 = V_166 [ V_63 -> V_95 ] ;
} else {
V_27 -> V_164 = V_167 [ V_63 -> V_95 ] ;
}
V_27 -> V_168 = F_47 ;
if ( V_7 -> V_24 ) {
V_3 -> V_28 = V_27 ;
V_27 -> V_157 |= V_169 ;
V_27 -> V_170 = F_28 ;
V_27 -> V_171 = F_37 ;
V_27 -> V_172 = F_41 ;
V_27 -> V_173 = F_43 ;
}
V_27 = & V_3 -> V_155 [ 1 ] ;
if ( V_63 -> V_174 ) {
V_27 -> type = V_175 ;
V_27 -> V_157 = V_176 ;
V_27 -> V_60 = 2 ;
V_27 -> V_108 = 0x0fff ;
V_27 -> V_164 = V_7 -> V_153 ;
V_27 -> V_177 = F_50 ;
V_118 = F_68 ( V_27 ) ;
if ( V_118 )
return V_118 ;
} else {
V_27 -> type = V_178 ;
}
V_27 = & V_3 -> V_155 [ 2 ] ;
V_27 -> type = V_179 ;
V_27 -> V_157 = V_158 ;
V_27 -> V_60 = 4 ;
V_27 -> V_108 = 1 ;
V_27 -> V_164 = & V_180 ;
V_27 -> V_181 = F_53 ;
V_27 = & V_3 -> V_155 [ 3 ] ;
V_27 -> type = V_182 ;
V_27 -> V_157 = V_176 ;
V_27 -> V_60 = 4 ;
V_27 -> V_108 = 1 ;
V_27 -> V_164 = & V_180 ;
V_27 -> V_181 = F_54 ;
F_3 ( V_27 -> V_125 , V_3 -> V_16 + V_124 ) ;
if ( V_63 -> V_154 ) {
V_27 = & V_3 -> V_155 [ 4 ] ;
V_118 = F_69 ( V_3 , V_27 , NULL , V_63 -> V_183 ) ;
if ( V_118 )
return V_118 ;
}
F_57 ( V_3 ) ;
V_7 -> V_9 = F_70 ( V_3 -> V_184 ) ;
F_3 ( V_7 -> V_9 , V_3 -> V_16 + V_17 ) ;
if ( V_7 -> V_70 ) {
F_3 ( V_185 , V_3 -> V_16 + V_186 ) ;
F_3 ( 0 , V_3 -> V_16 + V_93 ) ;
F_3 ( 0 , V_3 -> V_16 + V_100 ) ;
}
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
const struct V_62 * V_63 = V_3 -> V_64 ;
struct V_6 * V_7 = V_3 -> V_8 ;
int V_22 ;
if ( V_7 ) {
if ( V_7 -> V_52 . V_106 )
F_72 ( & V_7 -> V_52 ) ;
if ( V_3 -> V_16 )
F_57 ( V_3 ) ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
if ( V_7 -> V_48 [ V_22 ] )
F_73 ( NULL , V_102 ,
V_7 -> V_48 [ V_22 ] ,
V_7 ->
V_47 [ V_22 ] ) ;
}
if ( V_7 -> V_24 )
F_74 ( V_7 -> V_24 ) ;
F_75 ( V_7 -> V_148 ) ;
F_75 ( V_7 -> V_153 ) ;
if ( V_7 -> V_138 )
F_76 ( V_7 -> V_138 ,
V_63 -> V_137 & 0x3ff ) ;
}
F_77 ( V_3 ) ;
}
