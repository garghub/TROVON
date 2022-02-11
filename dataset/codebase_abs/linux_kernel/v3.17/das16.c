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
int V_35 , V_20 ;
int V_36 ;
F_12 ( & V_3 -> V_37 , V_33 ) ;
if ( ! ( V_7 -> V_9 & V_11 ) ) {
F_13 ( & V_3 -> V_37 , V_33 ) ;
return;
}
V_34 = F_14 () ;
F_15 ( V_7 -> V_24 ) ;
V_20 = F_5 ( V_3 ) ;
if ( V_20 > V_7 -> V_38 ) {
F_10 ( V_3 -> V_25 , L_2 ) ;
V_30 -> V_39 |= V_40 | V_41 ;
V_35 = 0 ;
} else
V_35 = V_7 -> V_38 - V_20 ;
if ( V_32 -> V_42 == V_43 &&
V_35 >= V_7 -> V_44 ) {
V_35 = V_7 -> V_44 ;
V_30 -> V_39 |= V_41 ;
}
V_36 = V_7 -> V_45 ;
V_7 -> V_45 = ( V_7 -> V_45 + 1 ) % 2 ;
V_7 -> V_44 -= V_35 ;
if ( ( V_30 -> V_39 & V_41 ) == 0 ) {
F_16 ( V_7 -> V_24 ,
V_7 -> V_46 [ V_7 -> V_45 ] ) ;
F_17 ( V_7 -> V_24 , V_7 -> V_38 ) ;
F_8 ( V_7 -> V_24 ) ;
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
int V_22 ;
for ( V_22 = 1 ; V_22 < V_32 -> V_55 ; V_22 ++ ) {
unsigned int V_56 = F_24 ( V_32 -> V_53 [ V_22 ] ) ;
unsigned int V_57 = F_25 ( V_32 -> V_53 [ V_22 ] ) ;
if ( V_56 != ( ( V_52 + V_22 ) % V_27 -> V_58 ) ) {
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
unsigned int V_82 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
unsigned long V_84 = V_3 -> V_16 + V_85 ;
F_33 ( V_7 -> V_79 ,
& V_7 -> V_80 , & V_7 -> V_81 ,
& V_83 , V_82 ) ;
F_35 ( V_84 , 0 , 1 , V_86 | V_87 ) ;
F_35 ( V_84 , 0 , 2 , V_86 | V_87 ) ;
F_36 ( V_84 , 0 , 1 , V_7 -> V_80 ) ;
F_36 ( V_84 , 0 , 2 , V_7 -> V_81 ) ;
return V_83 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_26 * V_27 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_29 * V_30 = V_27 -> V_30 ;
struct V_31 * V_32 = & V_30 -> V_32 ;
unsigned int V_88 ;
unsigned long V_82 ;
int V_57 ;
if ( V_32 -> V_82 & V_89 ) {
F_10 ( V_3 -> V_25 ,
L_5 ) ;
return - 1 ;
}
V_7 -> V_44 = V_32 -> V_78 * F_38 ( V_27 ) ;
if ( V_7 -> V_67 )
F_3 ( V_90 , V_3 -> V_16 + V_91 ) ;
V_88 = F_24 ( V_32 -> V_53 [ 0 ] ) ;
V_88 |= F_24 ( V_32 -> V_53 [ V_32 -> V_55 - 1 ] ) << 4 ;
F_3 ( V_88 , V_3 -> V_16 + V_92 ) ;
if ( V_61 -> V_93 != V_94 ) {
V_57 = F_25 ( V_32 -> V_53 [ 0 ] ) ;
F_3 ( ( V_95 [ V_61 -> V_93 ] ) [ V_57 ] ,
V_3 -> V_16 + V_96 ) ;
}
V_32 -> V_77 = F_34 ( V_3 , V_32 -> V_77 , V_32 -> V_82 ) ;
V_88 = 0 ;
if ( V_7 -> V_67 ) {
if ( V_32 -> V_70 == V_65 ) {
F_3 ( V_97 ,
V_3 -> V_16 + V_98 ) ;
V_88 |= F_39 ( V_32 -> V_55 - 1 ) ;
} else {
F_3 ( 0 , V_3 -> V_16 + V_98 ) ;
}
}
F_3 ( V_88 , V_3 -> V_16 + V_99 ) ;
V_82 = F_14 () ;
F_6 ( V_7 -> V_24 ) ;
F_15 ( V_7 -> V_24 ) ;
V_7 -> V_45 = 0 ;
F_16 ( V_7 -> V_24 ,
V_7 -> V_46 [ V_7 -> V_45 ] ) ;
V_7 -> V_38 = V_100 ;
F_17 ( V_7 -> V_24 , V_7 -> V_38 ) ;
F_8 ( V_7 -> V_24 ) ;
F_18 ( V_82 ) ;
V_7 -> V_49 = 1 ;
V_7 -> V_50 . V_101 = V_51 + F_1 () ;
F_40 ( & V_7 -> V_50 ) ;
F_2 ( V_3 , V_11 , V_32 -> V_70 ) ;
if ( V_7 -> V_67 )
F_3 ( 0 , V_3 -> V_16 + V_91 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_26 * V_27 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
unsigned long V_82 ;
F_12 ( & V_3 -> V_37 , V_82 ) ;
F_4 ( V_3 ) ;
F_6 ( V_7 -> V_24 ) ;
if ( V_7 -> V_49 ) {
V_7 -> V_49 = 0 ;
F_42 ( & V_7 -> V_50 ) ;
}
if ( V_7 -> V_67 )
F_3 ( 0 , V_3 -> V_16 + V_98 ) ;
F_13 ( & V_3 -> V_37 , V_82 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_26 * V_27 , void * V_102 ,
unsigned int V_35 ,
unsigned int V_103 )
{
unsigned int V_22 , V_104 = V_35 / sizeof( short ) ;
unsigned short * V_105 = V_102 ;
for ( V_22 = 0 ; V_22 < V_104 ; V_22 ++ ) {
V_105 [ V_22 ] = F_44 ( V_105 [ V_22 ] ) ;
if ( V_27 -> V_106 == 0x0fff )
V_105 [ V_22 ] >>= 4 ;
V_105 [ V_22 ] &= V_27 -> V_106 ;
}
}
static int F_45 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_107 * V_108 ,
unsigned long V_109 )
{
unsigned int V_110 ;
V_110 = F_46 ( V_3 -> V_16 + V_111 ) ;
if ( ( V_110 & V_112 ) == 0 )
return 0 ;
return - V_113 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_107 * V_108 ,
unsigned int * V_105 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
unsigned int V_56 = F_24 ( V_108 -> V_114 ) ;
unsigned int V_57 = F_25 ( V_108 -> V_114 ) ;
unsigned int V_115 ;
int V_116 ;
int V_22 ;
F_4 ( V_3 ) ;
F_3 ( V_56 | ( V_56 << 4 ) , V_3 -> V_16 + V_92 ) ;
if ( V_61 -> V_93 != V_94 ) {
F_3 ( ( V_95 [ V_61 -> V_93 ] ) [ V_57 ] ,
V_3 -> V_16 + V_96 ) ;
}
for ( V_22 = 0 ; V_22 < V_108 -> V_117 ; V_22 ++ ) {
F_48 ( 0 , V_3 -> V_16 + V_118 ) ;
V_116 = F_49 ( V_3 , V_27 , V_108 , F_45 , 0 ) ;
if ( V_116 )
return V_116 ;
V_115 = F_46 ( V_3 -> V_16 + V_119 ) << 8 ;
V_115 |= F_46 ( V_3 -> V_16 + V_120 ) ;
if ( V_27 -> V_106 == 0x0fff )
V_115 >>= 4 ;
V_115 &= V_27 -> V_106 ;
V_105 [ V_22 ] = V_115 ;
}
return V_108 -> V_117 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_107 * V_108 ,
unsigned int * V_105 )
{
unsigned int V_56 = F_24 ( V_108 -> V_114 ) ;
unsigned int V_115 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_108 -> V_117 ; V_22 ++ ) {
V_115 = V_105 [ V_22 ] ;
V_115 <<= 4 ;
F_3 ( V_115 & 0xff , V_3 -> V_16 + F_51 ( V_56 ) ) ;
F_3 ( ( V_115 >> 8 ) & 0xff , V_3 -> V_16 + F_52 ( V_56 ) ) ;
}
return V_108 -> V_117 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_107 * V_108 ,
unsigned int * V_105 )
{
V_105 [ 1 ] = F_46 ( V_3 -> V_16 + V_121 ) & 0xf ;
return V_108 -> V_117 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_107 * V_108 ,
unsigned int * V_105 )
{
if ( F_55 ( V_27 , V_105 ) )
F_3 ( V_27 -> V_122 , V_3 -> V_16 + V_121 ) ;
V_105 [ 1 ] = V_27 -> V_122 ;
return V_108 -> V_117 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_123 * V_124 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
int V_125 ;
V_125 = F_46 ( V_3 -> V_16 + V_121 ) & 0xf0 ;
if ( V_61 -> V_126 != V_125 ) {
F_10 ( V_3 -> V_25 ,
L_6 ,
V_61 -> V_126 , V_125 ) ;
return - V_59 ;
}
return 0 ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_3 ( 0 , V_3 -> V_16 + V_111 ) ;
F_3 ( 0 , V_3 -> V_16 + V_17 ) ;
F_3 ( 0 , V_3 -> V_16 + V_99 ) ;
F_3 ( 0 , V_3 -> V_16 + V_85 + V_127 ) ;
}
static int F_58 ( struct V_2 * V_3 , struct V_123 * V_124 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
struct V_6 * V_7 ;
struct V_26 * V_27 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
unsigned int V_24 = V_124 -> V_132 [ 2 ] ;
unsigned int V_110 ;
int V_116 ;
if ( V_124 -> V_132 [ 3 ] ) {
if ( V_124 -> V_132 [ 3 ] != 0 &&
V_124 -> V_132 [ 3 ] != 1 && V_124 -> V_132 [ 3 ] != 10 ) {
F_10 ( V_3 -> V_25 ,
L_7 ) ;
return - V_59 ;
}
}
V_7 = F_59 ( V_3 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_133 ;
if ( V_61 -> V_134 < 0x400 ) {
V_116 = F_60 ( V_3 , V_124 -> V_132 [ 0 ] , V_61 -> V_134 ) ;
if ( V_116 )
return V_116 ;
} else {
V_116 = F_60 ( V_3 , V_124 -> V_132 [ 0 ] , 0x10 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_61 ( V_3 , V_3 -> V_16 + 0x400 ,
V_61 -> V_134 & 0x3ff ) ;
if ( V_116 )
return V_116 ;
V_7 -> V_135 = V_3 -> V_16 + 0x400 ;
V_7 -> V_67 = 1 ;
}
if ( F_56 ( V_3 , V_124 ) )
return - V_59 ;
if ( V_7 -> V_67 ) {
V_110 = F_46 ( V_3 -> V_16 + V_136 ) ;
if ( V_110 & V_137 )
V_7 -> V_79 = V_138 ;
else
V_7 -> V_79 = V_139 ;
} else {
if ( V_124 -> V_132 [ 3 ] )
V_7 -> V_79 = V_139 /
V_124 -> V_132 [ 3 ] ;
else
V_7 -> V_79 = V_139 ;
}
if ( V_24 == 1 || V_24 == 3 ) {
unsigned long V_82 ;
int V_22 ;
if ( F_62 ( V_24 , V_3 -> V_140 ) ) {
F_10 ( V_3 -> V_25 ,
L_8 ,
V_24 ) ;
return - V_59 ;
}
V_7 -> V_24 = V_24 ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
void * V_141 ;
V_141 = F_63 ( NULL , V_100 ,
& V_7 -> V_46 [ V_22 ] ) ;
if ( ! V_141 )
return - V_133 ;
V_7 -> V_47 [ V_22 ] = V_141 ;
}
V_82 = F_14 () ;
F_6 ( V_7 -> V_24 ) ;
F_64 ( V_7 -> V_24 , V_142 ) ;
F_18 ( V_82 ) ;
F_65 ( & V_7 -> V_50 ) ;
V_7 -> V_50 . V_143 = F_21 ;
V_7 -> V_50 . V_105 = ( unsigned long ) V_3 ;
}
if ( V_61 -> V_93 == V_94 &&
( V_124 -> V_132 [ 4 ] || V_124 -> V_132 [ 5 ] ) ) {
V_129 = F_66 ( sizeof( * V_129 ) + sizeof( * V_131 ) , V_144 ) ;
if ( ! V_129 )
return - V_133 ;
V_7 -> V_145 = V_129 ;
V_129 -> V_146 = 1 ;
V_131 = V_7 -> V_145 -> V_57 ;
V_131 -> V_147 = V_124 -> V_132 [ 4 ] ;
V_131 -> V_148 = V_124 -> V_132 [ 5 ] ;
V_131 -> V_82 = V_149 ;
}
if ( V_124 -> V_132 [ 6 ] || V_124 -> V_132 [ 7 ] ) {
V_129 = F_66 ( sizeof( * V_129 ) + sizeof( * V_131 ) , V_144 ) ;
if ( ! V_129 )
return - V_133 ;
V_7 -> V_150 = V_129 ;
V_129 -> V_146 = 1 ;
V_131 = V_7 -> V_150 -> V_57 ;
V_131 -> V_147 = V_124 -> V_132 [ 6 ] ;
V_131 -> V_148 = V_124 -> V_132 [ 7 ] ;
V_131 -> V_82 = V_149 ;
}
V_116 = F_67 ( V_3 , 4 + V_61 -> V_151 ) ;
if ( V_116 )
return V_116 ;
V_110 = F_46 ( V_3 -> V_16 + V_111 ) ;
V_27 = & V_3 -> V_152 [ 0 ] ;
V_27 -> type = V_153 ;
V_27 -> V_154 = V_155 ;
if ( V_110 & V_156 ) {
V_27 -> V_154 |= V_157 ;
V_27 -> V_58 = 16 ;
} else {
V_27 -> V_154 |= V_158 ;
V_27 -> V_58 = 8 ;
}
V_27 -> V_159 = V_27 -> V_58 ;
V_27 -> V_106 = V_61 -> V_160 ;
if ( V_7 -> V_145 ) {
V_27 -> V_161 = V_7 -> V_145 ;
} else if ( V_110 & V_162 ) {
V_27 -> V_161 = V_163 [ V_61 -> V_93 ] ;
} else {
V_27 -> V_161 = V_164 [ V_61 -> V_93 ] ;
}
V_27 -> V_165 = F_47 ;
if ( V_7 -> V_24 ) {
V_3 -> V_28 = V_27 ;
V_27 -> V_154 |= V_166 ;
V_27 -> V_167 = F_27 ;
V_27 -> V_168 = F_37 ;
V_27 -> V_169 = F_41 ;
V_27 -> V_170 = F_43 ;
}
V_27 = & V_3 -> V_152 [ 1 ] ;
if ( V_61 -> V_171 ) {
V_27 -> type = V_172 ;
V_27 -> V_154 = V_173 ;
V_27 -> V_58 = 2 ;
V_27 -> V_106 = 0x0fff ;
V_27 -> V_161 = V_7 -> V_150 ;
V_27 -> V_174 = F_50 ;
} else {
V_27 -> type = V_175 ;
}
V_27 = & V_3 -> V_152 [ 2 ] ;
V_27 -> type = V_176 ;
V_27 -> V_154 = V_155 ;
V_27 -> V_58 = 4 ;
V_27 -> V_106 = 1 ;
V_27 -> V_161 = & V_177 ;
V_27 -> V_178 = F_53 ;
V_27 = & V_3 -> V_152 [ 3 ] ;
V_27 -> type = V_179 ;
V_27 -> V_154 = V_173 ;
V_27 -> V_58 = 4 ;
V_27 -> V_106 = 1 ;
V_27 -> V_161 = & V_177 ;
V_27 -> V_178 = F_54 ;
F_3 ( V_27 -> V_122 , V_3 -> V_16 + V_121 ) ;
if ( V_61 -> V_151 ) {
V_27 = & V_3 -> V_152 [ 4 ] ;
V_116 = F_68 ( V_3 , V_27 , NULL ,
V_3 -> V_16 + V_61 -> V_180 ) ;
if ( V_116 )
return V_116 ;
}
F_57 ( V_3 ) ;
V_7 -> V_9 = F_69 ( V_3 -> V_181 ) ;
F_3 ( V_7 -> V_9 , V_3 -> V_16 + V_17 ) ;
if ( V_7 -> V_67 ) {
F_3 ( V_182 , V_3 -> V_16 + V_183 ) ;
F_3 ( 0 , V_3 -> V_16 + V_91 ) ;
F_3 ( 0 , V_3 -> V_16 + V_98 ) ;
}
return 0 ;
}
static void F_70 ( struct V_2 * V_3 )
{
const struct V_60 * V_61 = F_28 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_8 ;
int V_22 ;
if ( V_7 ) {
if ( V_3 -> V_16 )
F_57 ( V_3 ) ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
if ( V_7 -> V_47 [ V_22 ] )
F_71 ( NULL , V_100 ,
V_7 -> V_47 [ V_22 ] ,
V_7 ->
V_46 [ V_22 ] ) ;
}
if ( V_7 -> V_24 )
F_72 ( V_7 -> V_24 ) ;
F_73 ( V_7 -> V_145 ) ;
F_73 ( V_7 -> V_150 ) ;
if ( V_7 -> V_135 )
F_74 ( V_7 -> V_135 ,
V_61 -> V_134 & 0x3ff ) ;
}
F_75 ( V_3 ) ;
}
