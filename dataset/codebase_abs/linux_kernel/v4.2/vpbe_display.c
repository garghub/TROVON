static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
int V_6 ;
V_5 = F_2 ( V_4 -> V_7 ,
V_8 ,
V_9 ,
V_10 ,
& V_6 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_1 ) ;
}
return V_6 ;
}
static void F_4 ( struct V_1 * V_12 ,
struct V_13 * V_14 )
{
if ( V_14 -> V_15 == V_14 -> V_16 )
return;
F_5 ( & V_14 -> V_15 -> V_17 . V_18 . V_19 ) ;
F_6 ( & V_14 -> V_15 -> V_17 , V_20 ) ;
V_14 -> V_15 = V_14 -> V_16 ;
}
static void F_7 ( struct V_1 * V_12 ,
struct V_13 * V_14 )
{
struct V_21 * V_22 = V_12 -> V_22 ;
unsigned long V_23 ;
F_8 ( & V_12 -> V_24 ) ;
if ( F_9 ( & V_14 -> V_25 ) ||
( V_14 -> V_15 != V_14 -> V_16 ) ) {
F_10 ( & V_12 -> V_24 ) ;
return;
}
V_14 -> V_16 = F_11 ( V_14 -> V_25 . V_26 ,
struct V_27 , V_28 ) ;
F_12 ( & V_14 -> V_16 -> V_28 ) ;
F_10 ( & V_12 -> V_24 ) ;
V_14 -> V_16 -> V_17 . V_29 = V_30 ;
V_23 = F_13 ( & V_14 -> V_16 -> V_17 , 0 ) ;
V_22 -> V_31 . V_32 ( V_22 ,
V_14 -> V_33 . V_34 ,
V_23 ,
V_12 -> V_35 ) ;
}
static T_1 F_14 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
struct V_13 * V_14 ;
static unsigned V_38 ;
unsigned V_39 = 0 ;
int V_40 ;
int V_41 ;
if ( ( NULL == V_37 ) || ( NULL == V_2 -> V_42 [ 0 ] ) )
return V_43 ;
if ( F_1 ( V_2 ) )
V_39 |= V_44 ;
else
V_39 |= V_45 ;
if ( V_39 == ( V_38 & ~ V_46 ) ) {
V_39 |= V_46 ;
} else if ( V_39 == V_44 ) {
V_39 |= V_46 ;
}
V_38 = V_39 ;
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
V_14 = V_2 -> V_42 [ V_41 ] ;
if ( ! F_15 ( & V_14 -> V_48 ) )
continue;
if ( V_14 -> V_49 ) {
V_14 -> V_49 = 0 ;
continue;
}
if ( ( V_50 == V_14 -> V_51 . V_52 ) &&
( V_39 & V_46 ) ) {
F_4 ( V_2 , V_14 ) ;
F_7 ( V_2 , V_14 ) ;
} else {
V_14 -> V_53 ^= 1 ;
if ( V_39 & V_45 )
V_40 = 0 ;
else
V_40 = 1 ;
if ( V_40 != V_14 -> V_53 ) {
V_14 -> V_53 = V_40 ;
continue;
}
if ( 0 == V_40 )
F_4 ( V_2 , V_14 ) ;
else
F_7 ( V_2 , V_14 ) ;
}
}
return V_43 ;
}
static int F_16 ( struct V_54 * V_17 )
{
struct V_55 * V_56 = V_17 -> V_55 ;
struct V_13 * V_14 = F_17 ( V_56 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned long V_23 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_2 ) ;
F_19 ( V_17 , 0 , V_14 -> V_51 . V_58 ) ;
if ( F_20 ( V_17 , 0 ) > F_21 ( V_17 , 0 ) )
return - V_59 ;
V_23 = F_13 ( V_17 , 0 ) ;
if ( ! F_22 ( V_23 , 8 ) ) {
F_3 ( & V_4 -> V_11 ,
L_3 ) ;
return - V_59 ;
}
return 0 ;
}
static int
F_23 ( struct V_55 * V_60 , const struct V_61 * V_62 ,
unsigned int * V_63 , unsigned int * V_64 ,
unsigned int V_65 [] , void * V_66 [] )
{
struct V_13 * V_14 = F_17 ( V_60 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_4 ) ;
if ( V_62 && V_62 -> V_62 . V_67 . V_58 < V_14 -> V_51 . V_58 )
return - V_59 ;
if ( V_60 -> V_68 + * V_63 < V_69 )
* V_63 = V_69 - V_60 -> V_68 ;
* V_64 = 1 ;
V_65 [ 0 ] = V_62 ? V_62 -> V_62 . V_67 . V_58 : V_14 -> V_51 . V_58 ;
V_66 [ 0 ] = V_14 -> V_70 ;
return 0 ;
}
static void F_24 ( struct V_54 * V_17 )
{
struct V_27 * V_71 = F_25 ( V_17 ,
struct V_27 , V_17 ) ;
struct V_13 * V_14 = F_17 ( V_17 -> V_55 ) ;
struct V_1 * V_72 = V_14 -> V_2 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned long V_73 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_5 ) ;
F_26 ( & V_72 -> V_24 , V_73 ) ;
F_27 ( & V_71 -> V_28 , & V_14 -> V_25 ) ;
F_28 ( & V_72 -> V_24 , V_73 ) ;
}
static int F_29 ( struct V_55 * V_60 , unsigned int V_74 )
{
struct V_13 * V_14 = F_17 ( V_60 ) ;
struct V_21 * V_22 = V_14 -> V_2 -> V_22 ;
int V_5 ;
V_22 -> V_31 . V_75 ( V_22 , V_14 -> V_33 . V_34 ) ;
V_14 -> V_16 = V_14 -> V_15 = F_11 ( V_14 -> V_25 . V_26 ,
struct V_27 , V_28 ) ;
F_12 ( & V_14 -> V_15 -> V_28 ) ;
V_14 -> V_15 -> V_17 . V_29 = V_30 ;
V_14 -> V_53 = 0 ;
V_5 = F_30 ( V_14 -> V_2 , V_14 ) ;
if ( V_5 < 0 ) {
struct V_27 * V_71 , * V_76 ;
F_6 ( & V_14 -> V_15 -> V_17 , V_77 ) ;
F_31 (buf, tmp, &layer->dma_queue, list) {
F_12 ( & V_71 -> V_28 ) ;
F_6 ( & V_71 -> V_17 , V_77 ) ;
}
return V_5 ;
}
V_14 -> V_49 = 1 ;
return V_5 ;
}
static void F_32 ( struct V_55 * V_60 )
{
struct V_13 * V_14 = F_17 ( V_60 ) ;
struct V_21 * V_22 = V_14 -> V_2 -> V_22 ;
struct V_1 * V_72 = V_14 -> V_2 ;
unsigned long V_73 ;
if ( ! F_33 ( V_60 ) )
return;
V_22 -> V_31 . V_75 ( V_22 , V_14 -> V_33 . V_34 ) ;
F_26 ( & V_72 -> V_24 , V_73 ) ;
if ( V_14 -> V_15 == V_14 -> V_16 ) {
F_6 ( & V_14 -> V_15 -> V_17 , V_78 ) ;
} else {
if ( V_14 -> V_15 != NULL )
F_6 ( & V_14 -> V_15 -> V_17 ,
V_78 ) ;
if ( V_14 -> V_16 != NULL )
F_6 ( & V_14 -> V_16 -> V_17 ,
V_78 ) ;
}
while ( ! F_9 ( & V_14 -> V_25 ) ) {
V_14 -> V_16 = F_11 ( V_14 -> V_25 . V_26 ,
struct V_27 , V_28 ) ;
F_12 ( & V_14 -> V_16 -> V_28 ) ;
F_6 ( & V_14 -> V_16 -> V_17 , V_78 ) ;
}
F_28 ( & V_72 -> V_24 , V_73 ) ;
}
static
struct V_13 *
F_34 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
enum V_79 V_80 , V_81 ;
V_80 = V_14 -> V_82 ;
V_81 = ( V_80 == V_83 ) ?
V_84 : V_83 ;
return V_2 -> V_42 [ V_81 ] ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_85 * V_86 = & V_14 -> V_33 . V_87 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_23 ;
int V_5 ;
V_23 = F_13 ( & V_14 -> V_15 -> V_17 , 0 ) ;
V_22 -> V_31 . V_32 ( V_22 ,
V_14 -> V_33 . V_34 ,
V_23 ,
V_2 -> V_35 ) ;
V_5 = V_22 -> V_31 . V_88 ( V_22 ,
V_14 -> V_33 . V_34 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_6 ) ;
return - 1 ;
}
V_14 -> V_33 . V_89 = 1 ;
if ( V_86 -> V_90 == V_91 ) {
struct V_13 * V_92 =
F_34 ( V_2 , V_14 ) ;
V_5 = V_22 -> V_31 . V_88 ( V_22 ,
V_92 -> V_33 . V_34 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_7 ) ;
return - 1 ;
}
V_92 -> V_33 . V_89 = 1 ;
}
return 0 ;
}
static void
F_35 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_93 , int V_94 )
{
struct V_95 * V_33 = & V_14 -> V_33 ;
struct V_96 * V_90 = & V_14 -> V_51 ;
struct V_85 * V_86 = & V_14 -> V_33 . V_87 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_97 ;
int V_98 = 0 ;
int V_99 = 0 ;
int V_100 ;
int V_101 ;
T_2 V_102 = V_4 -> V_103 . V_104 ;
V_86 -> V_105 = V_90 -> V_106 ;
V_86 -> V_107 = V_90 -> V_108 ;
V_33 -> V_109 = V_110 ;
V_33 -> V_111 = V_110 ;
V_33 -> V_98 = V_112 ;
V_33 -> V_99 = V_113 ;
if ( V_90 -> V_106 < V_93 ) {
V_100 = V_4 -> V_103 . V_114 / V_90 -> V_106 ;
if ( V_100 < 2 )
V_100 = 1 ;
else if ( V_100 >= 4 )
V_100 = 4 ;
else
V_100 = 2 ;
V_86 -> V_105 *= V_100 ;
if ( V_86 -> V_105 < V_93 ) {
if ( ( V_102 & V_115 ) ||
( V_102 & V_116 ) ) {
V_97 = ( V_86 -> V_105 *
V_117 ) /
V_118 ;
if ( V_97 <= V_93 ) {
V_98 = 1 ;
V_86 -> V_105 = V_97 ;
}
}
}
if ( V_100 == 2 )
V_33 -> V_109 = V_119 ;
else if ( V_100 == 4 )
V_33 -> V_109 = V_120 ;
if ( V_98 )
V_33 -> V_98 = V_121 ;
} else {
V_86 -> V_105 = V_93 ;
}
if ( V_90 -> V_108 < V_94 ) {
V_101 = V_94 / V_90 -> V_108 ;
if ( V_101 < 2 )
V_101 = 1 ;
else if ( V_101 >= 4 )
V_101 = 4 ;
else
V_101 = 2 ;
V_86 -> V_107 *= V_101 ;
if ( V_86 -> V_107 < V_94 ) {
if ( ( V_102 & V_116 ) ) {
V_97 = ( V_86 -> V_107 *
V_122 ) /
V_123 ;
if ( V_97 <= V_94 ) {
V_99 = 1 ;
V_86 -> V_107 = V_97 ;
}
}
}
if ( V_101 == 2 )
V_33 -> V_111 = V_119 ;
else if ( V_101 == 4 )
V_33 -> V_111 = V_120 ;
if ( V_99 )
V_33 -> V_98 = V_124 ;
} else {
V_86 -> V_107 = V_94 ;
}
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_8 ,
V_86 -> V_105 , V_86 -> V_107 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_125 , int V_126 )
{
struct V_85 * V_86 = & V_14 -> V_33 . V_87 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_86 -> V_127 = F_37 ( ( unsigned int ) V_126 ,
V_4 -> V_103 . V_114 - V_86 -> V_105 ) ;
V_86 -> V_128 = F_37 ( ( unsigned int ) V_125 ,
V_4 -> V_103 . V_129 - V_86 -> V_107 ) ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_9 ,
V_86 -> V_127 , V_86 -> V_128 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ( V_131 -> V_106 == 0 ) ||
( ( V_131 -> V_106 + V_131 -> V_126 ) > V_4 -> V_103 . V_114 ) )
V_131 -> V_106 = V_4 -> V_103 . V_114 - V_131 -> V_126 ;
if ( ( V_131 -> V_108 == 0 ) || ( ( V_131 -> V_108 + V_131 -> V_125 ) >
V_4 -> V_103 . V_129 ) )
V_131 -> V_108 = V_4 -> V_103 . V_129 - V_131 -> V_125 ;
if ( V_4 -> V_103 . V_132 )
V_131 -> V_108 &= ( ~ 0x01 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_96 * V_90 , int V_133 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_134 = 1 ;
int V_135 = 32 ;
int V_136 ;
int V_137 ;
int V_138 ;
if ( ( V_90 -> V_139 != V_140 ) &&
( V_90 -> V_139 != V_141 ) )
V_90 -> V_139 = V_140 ;
if ( ( V_90 -> V_52 != V_142 ) &&
( V_90 -> V_52 != V_50 ) ) {
if ( V_4 -> V_103 . V_132 )
V_90 -> V_52 = V_142 ;
else
V_90 -> V_52 = V_50 ;
}
if ( V_90 -> V_52 == V_142 )
V_134 = 2 ;
if ( V_90 -> V_139 == V_141 )
V_138 = 1 ;
else
V_138 = 2 ;
V_137 = V_4 -> V_103 . V_114 ;
V_136 = V_4 -> V_103 . V_129 ;
V_135 /= V_138 ;
if ( ! V_90 -> V_106 || ( V_90 -> V_106 < V_135 ) ||
( V_90 -> V_106 > V_137 ) ) {
V_90 -> V_106 = V_4 -> V_103 . V_114 ;
}
if ( ! V_90 -> V_108 || ( V_90 -> V_108 < V_134 ) ||
( V_90 -> V_108 > V_136 ) ) {
V_90 -> V_108 = V_4 -> V_103 . V_129 ;
}
if ( V_90 -> V_143 < ( V_90 -> V_106 * V_138 ) )
V_90 -> V_143 = V_90 -> V_106 * V_138 ;
V_90 -> V_143 = ( ( V_90 -> V_106 * V_138 + 31 ) & ~ 31 ) ;
if ( V_90 -> V_139 == V_141 )
V_90 -> V_58 = V_90 -> V_143 * V_90 -> V_108 +
( V_90 -> V_143 * V_90 -> V_108 >> 1 ) ;
else
V_90 -> V_58 = V_90 -> V_143 * V_90 -> V_108 ;
return 0 ;
}
static int F_40 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
V_147 -> V_148 = V_149 | V_150 ;
V_147 -> V_151 = V_147 -> V_148 | V_152 ;
snprintf ( V_147 -> V_153 , sizeof( V_147 -> V_153 ) , L_10 ,
F_42 ( V_4 -> V_154 ) ) ;
snprintf ( V_147 -> V_155 , sizeof( V_147 -> V_155 ) , L_11 ,
F_42 ( V_4 -> V_154 ) ) ;
F_43 ( V_147 -> V_156 , V_4 -> V_86 -> V_157 , sizeof( V_147 -> V_156 ) ) ;
return 0 ;
}
static int F_44 ( struct V_144 * V_144 , void * V_145 ,
const struct V_158 * V_159 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_85 * V_86 = & V_14 -> V_33 . V_87 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_130 V_160 = V_159 -> V_131 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_12 , V_14 -> V_82 ) ;
if ( V_159 -> type != V_161 ) {
F_3 ( & V_4 -> V_11 , L_13 ) ;
return - V_59 ;
}
if ( V_160 . V_125 < 0 )
V_160 . V_125 = 0 ;
if ( V_160 . V_126 < 0 )
V_160 . V_126 = 0 ;
F_38 ( V_2 , & V_160 ) ;
V_22 -> V_31 . V_162 ( V_22 ,
V_14 -> V_33 . V_34 , V_86 ) ;
F_35 ( V_2 , V_14 ,
V_160 . V_106 ,
V_160 . V_108 ) ;
F_36 ( V_2 , V_14 , V_160 . V_125 ,
V_160 . V_126 ) ;
V_5 = V_22 -> V_31 . V_163 ( V_22 ,
V_14 -> V_33 . V_34 , V_86 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_14 ) ;
return - V_59 ;
}
V_22 -> V_31 . V_164 ( V_22 ,
V_14 -> V_33 . V_34 ,
V_14 -> V_33 . V_109 ,
V_14 -> V_33 . V_111 ) ;
V_5 = V_22 -> V_31 . V_165 ( V_22 ,
V_14 -> V_33 . V_98 ,
V_14 -> V_33 . V_99 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_15 ) ;
return - V_59 ;
}
if ( ( V_14 -> V_33 . V_109 != V_110 ) ||
( V_14 -> V_33 . V_111 != V_110 ) ||
( V_14 -> V_33 . V_98 != V_112 ) ||
( V_14 -> V_33 . V_99 != V_113 ) )
V_22 -> V_31 . V_166 ( V_22 , 1 ) ;
else
V_22 -> V_31 . V_166 ( V_22 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_144 * V_144 , void * V_145 ,
struct V_158 * V_159 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_85 * V_86 = & V_14 -> V_33 . V_87 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
struct V_21 * V_22 = V_14 -> V_2 -> V_22 ;
struct V_130 * V_160 = & V_159 -> V_131 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_16 ,
V_14 -> V_82 ) ;
if ( V_159 -> type != V_161 ) {
F_3 ( & V_4 -> V_11 , L_13 ) ;
return - V_59 ;
}
V_22 -> V_31 . V_162 ( V_22 ,
V_14 -> V_33 . V_34 , V_86 ) ;
V_160 -> V_125 = V_86 -> V_128 ;
V_160 -> V_126 = V_86 -> V_127 ;
V_160 -> V_106 = V_86 -> V_105 ;
V_160 -> V_108 = V_86 -> V_107 ;
return 0 ;
}
static int F_46 ( struct V_144 * V_144 , void * V_145 ,
struct V_167 * V_168 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_17 ) ;
V_168 -> type = V_161 ;
V_168 -> V_169 . V_126 = 0 ;
V_168 -> V_169 . V_125 = 0 ;
V_168 -> V_169 . V_106 = V_4 -> V_103 . V_114 ;
V_168 -> V_169 . V_108 = V_4 -> V_103 . V_129 ;
V_168 -> V_170 = V_4 -> V_103 . V_171 ;
V_168 -> V_172 = V_168 -> V_169 ;
return 0 ;
}
static int F_47 ( struct V_144 * V_144 , void * V_145 ,
struct V_61 * V_62 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_18 ,
V_14 -> V_82 ) ;
if ( V_161 != V_62 -> type ) {
F_3 ( & V_4 -> V_11 , L_19 ) ;
return - V_59 ;
}
V_62 -> V_62 . V_67 = V_14 -> V_51 ;
return 0 ;
}
static int F_48 ( struct V_144 * V_144 , void * V_145 ,
struct V_173 * V_62 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned int V_174 = 0 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_20 ,
V_14 -> V_82 ) ;
if ( V_62 -> V_174 > 1 ) {
F_3 ( & V_4 -> V_11 , L_21 ) ;
return - V_59 ;
}
V_174 = V_62 -> V_174 ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_174 = V_174 ;
V_62 -> type = V_161 ;
if ( V_174 == 0 ) {
strcpy ( V_62 -> V_175 , L_22 ) ;
V_62 -> V_139 = V_140 ;
} else {
strcpy ( V_62 -> V_175 , L_23 ) ;
V_62 -> V_139 = V_141 ;
}
return 0 ;
}
static int F_49 ( struct V_144 * V_144 , void * V_145 ,
struct V_61 * V_62 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_85 * V_86 = & V_14 -> V_33 . V_87 ;
struct V_96 * V_90 = & V_62 -> V_62 . V_67 ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_24 ,
V_14 -> V_82 ) ;
if ( F_50 ( & V_14 -> V_48 ) )
return - V_176 ;
if ( V_161 != V_62 -> type ) {
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_19 ) ;
return - V_59 ;
}
V_5 = F_39 ( V_2 , V_90 , 1 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_51 = * V_90 ;
if ( V_90 -> V_139 == V_141 ) {
struct V_13 * V_92 ;
V_92 = F_34 ( V_2 , V_14 ) ;
V_5 = V_22 -> V_31 . V_177 ( V_22 ,
V_92 -> V_33 . V_34 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_25 ) ;
return - V_176 ;
}
}
V_22 -> V_31 . V_162 ( V_22 ,
V_14 -> V_33 . V_34 , V_86 ) ;
V_86 -> V_105 = V_90 -> V_106 ;
V_86 -> V_107 = V_90 -> V_108 ;
V_86 -> V_178 = V_90 -> V_143 ;
V_86 -> V_128 = 0 ;
V_86 -> V_127 = 0 ;
V_86 -> V_132 = V_4 -> V_103 . V_132 ;
if ( V_140 == V_90 -> V_139 )
V_86 -> V_90 = V_179 ;
if ( V_141 == V_90 -> V_139 ) {
struct V_13 * V_92 ;
V_86 -> V_90 = V_91 ;
V_92 = F_34 ( V_2 ,
V_14 ) ;
V_92 -> V_33 . V_87 . V_90 = V_91 ;
}
V_5 = V_22 -> V_31 . V_163 ( V_22 ,
V_14 -> V_33 . V_34 , V_86 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_26 ) ;
return - V_59 ;
}
V_22 -> V_31 . V_162 ( V_22 ,
V_14 -> V_33 . V_34 , V_86 ) ;
return 0 ;
}
static int F_51 ( struct V_144 * V_144 , void * V_145 ,
struct V_61 * V_62 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
struct V_96 * V_90 = & V_62 -> V_62 . V_67 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_27 ) ;
if ( V_161 != V_62 -> type ) {
F_3 ( & V_4 -> V_11 , L_19 ) ;
return - V_59 ;
}
return F_39 ( V_2 , V_90 , 0 ) ;
}
static int F_52 ( struct V_144 * V_144 , void * V_145 ,
T_2 V_104 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_28 ) ;
if ( F_50 ( & V_14 -> V_48 ) )
return - V_176 ;
if ( NULL != V_4 -> V_31 . V_180 ) {
V_5 = V_4 -> V_31 . V_180 ( V_4 , V_104 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_29 ) ;
return - V_59 ;
}
} else {
return - V_59 ;
}
return 0 ;
}
static int F_53 ( struct V_144 * V_144 , void * V_145 ,
T_2 * V_104 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_30 ) ;
if ( V_4 -> V_103 . V_181 & V_182 ) {
* V_104 = V_4 -> V_103 . V_104 ;
return 0 ;
}
return - V_59 ;
}
static int F_54 ( struct V_144 * V_144 , void * V_145 ,
struct V_183 * V_184 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_31 ) ;
if ( NULL == V_4 -> V_31 . V_185 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_185 ( V_4 , V_184 ) ;
if ( V_5 ) {
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_32 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_55 ( struct V_144 * V_144 , void * V_145 ,
unsigned int V_41 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_33 ) ;
if ( F_50 ( & V_14 -> V_48 ) )
return - V_176 ;
if ( NULL == V_4 -> V_31 . V_186 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_186 ( V_4 , V_41 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_34 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_56 ( struct V_144 * V_144 , void * V_145 ,
unsigned int * V_41 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_35 ) ;
* V_41 = V_4 -> V_187 ;
return 0 ;
}
static int
F_57 ( struct V_144 * V_144 , void * V_145 ,
struct V_188 * V_189 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_36 ) ;
if ( NULL == V_4 -> V_31 . V_190 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_190 ( V_4 , V_189 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_37 ) ;
return - V_59 ;
}
return 0 ;
}
static int
F_58 ( struct V_144 * V_144 , void * V_145 ,
struct V_191 * V_189 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_38 ) ;
if ( F_50 ( & V_14 -> V_48 ) )
return - V_176 ;
if ( ! V_4 -> V_31 . V_192 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_192 ( V_4 , V_189 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_39 ) ;
return - V_59 ;
}
return 0 ;
}
static int
F_59 ( struct V_144 * V_144 , void * V_145 ,
struct V_191 * V_193 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_40 ) ;
if ( V_4 -> V_103 . V_181 &
V_194 ) {
* V_193 = V_4 -> V_103 . V_193 ;
} else {
return - V_59 ;
}
return 0 ;
}
static int F_60 ( struct V_144 * V_144 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_195 ;
V_195 = F_61 ( V_144 ) ;
if ( V_195 ) {
F_3 ( & V_4 -> V_11 , L_41 ) ;
return V_195 ;
}
if ( ! F_62 ( V_144 ) )
return V_195 ;
if ( ! V_14 -> V_196 ) {
if ( F_63 ( & V_14 -> V_197 ) )
return - V_198 ;
V_195 = V_22 -> V_31 . V_177 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
F_64 ( & V_14 -> V_197 ) ;
if ( V_195 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_25 ) ;
F_65 ( V_144 ) ;
return - V_59 ;
}
}
V_14 -> V_196 ++ ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_42 ) ;
return 0 ;
}
static int F_66 ( struct V_144 * V_144 )
{
struct V_13 * V_14 = F_41 ( V_144 ) ;
struct V_85 * V_86 = & V_14 -> V_33 . V_87 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_43 ) ;
F_67 ( & V_14 -> V_197 ) ;
V_22 -> V_31 . V_75 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
V_14 -> V_196 -- ;
if ( ! V_14 -> V_196 ) {
if ( V_86 -> V_90 == V_91 ) {
struct V_13 * V_92 ;
V_92 =
F_34 ( V_2 , V_14 ) ;
V_22 -> V_31 . V_75 ( V_22 ,
V_92 -> V_33 . V_34 ) ;
V_22 -> V_31 . V_199 ( V_22 ,
V_92 -> V_33 . V_34 ) ;
}
V_22 -> V_31 . V_75 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
V_22 -> V_31 . V_199 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
}
F_68 ( V_144 , NULL ) ;
F_64 ( & V_14 -> V_197 ) ;
V_2 -> V_35 = 0 ;
return 0 ;
}
static int F_69 ( struct V_200 * V_42 , void * V_201 )
{
struct V_202 * V_154 = F_70 ( V_42 ) ;
struct V_1 * V_203 = V_201 ;
if ( strcmp ( L_44 , V_154 -> V_204 ) == 0 )
V_203 -> V_4 = F_71 ( V_154 ) ;
if ( strstr ( V_154 -> V_204 , L_45 ) != NULL )
V_203 -> V_22 = F_71 ( V_154 ) ;
return 0 ;
}
static int F_72 ( int V_41 , struct V_1 * V_2 ,
struct V_202 * V_154 )
{
struct V_13 * V_205 = NULL ;
struct V_206 * V_207 = NULL ;
V_2 -> V_42 [ V_41 ] =
F_73 ( sizeof( struct V_13 ) , V_208 ) ;
if ( ! V_2 -> V_42 [ V_41 ] ) {
F_74 ( V_209 L_46 ) ;
return - V_210 ;
}
F_75 ( & V_2 -> V_42 [ V_41 ] -> V_211 ) ;
F_76 ( & V_2 -> V_42 [ V_41 ] -> V_197 ) ;
V_205 = V_2 -> V_42 [ V_41 ] ;
V_207 = & V_205 -> V_212 ;
V_207 -> V_213 = V_214 ;
V_207 -> V_215 = & V_216 ;
V_207 -> V_217 = & V_218 ;
V_207 -> V_219 = - 1 ;
V_207 -> V_11 = & V_2 -> V_4 -> V_11 ;
V_207 -> V_220 = & V_205 -> V_197 ;
V_207 -> V_221 = V_222 ;
if ( V_2 -> V_4 -> V_103 . V_181 &
V_182 )
V_207 -> V_223 = ( V_115 | V_116 ) ;
snprintf ( V_207 -> V_204 , sizeof( V_207 -> V_204 ) ,
L_47 ,
( V_224 >> 16 ) & 0xff ,
( V_224 >> 8 ) & 0xff ,
( V_224 ) & 0xff ) ;
V_205 -> V_82 = V_41 ;
V_205 -> V_33 . V_34 =
( ( V_41 == V_83 ) ? V_225 : V_226 ) ;
return 0 ;
}
static int F_77 ( struct V_13 * V_205 ,
struct V_1 * V_2 ,
struct V_202 * V_154 )
{
int V_195 ;
F_78 ( & V_2 -> V_4 -> V_11 ,
L_48 ) ;
F_78 ( & V_2 -> V_4 -> V_11 ,
L_49 ,
( int ) V_205 ,
( int ) & V_205 -> V_212 ) ;
V_205 -> V_212 . V_227 = & V_205 -> V_48 ;
V_195 = F_79 ( & V_205 -> V_212 ,
V_228 ,
- 1 ) ;
if ( V_195 )
return - V_229 ;
V_205 -> V_2 = V_2 ;
F_80 ( V_154 , V_2 ) ;
F_81 ( & V_205 -> V_212 ,
V_205 ) ;
return 0 ;
}
static int F_82 ( struct V_202 * V_154 )
{
struct V_1 * V_2 ;
struct V_230 * V_11 ;
struct V_231 * V_232 = NULL ;
struct V_55 * V_56 ;
int V_233 ;
int V_41 ;
int V_195 ;
int V_36 ;
F_74 ( V_234 L_50 ) ;
V_2 = F_83 ( & V_154 -> V_42 , sizeof( struct V_1 ) ,
V_208 ) ;
if ( ! V_2 )
return - V_210 ;
F_75 ( & V_2 -> V_24 ) ;
V_195 = F_84 ( & V_235 , NULL , V_2 ,
F_69 ) ;
if ( V_195 < 0 )
return V_195 ;
V_11 = & V_2 -> V_4 -> V_11 ;
if ( NULL != V_2 -> V_4 -> V_31 . V_236 ) {
V_195 = V_2 -> V_4 -> V_31 . V_236 ( & V_154 -> V_42 ,
V_2 -> V_4 ) ;
if ( V_195 ) {
F_3 ( V_11 , L_51 ) ;
V_195 = - V_210 ;
goto V_237;
}
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
if ( F_72 ( V_41 , V_2 , V_154 ) ) {
V_195 = - V_229 ;
goto V_237;
}
}
V_232 = F_85 ( V_154 , V_238 , 0 ) ;
if ( ! V_232 ) {
F_3 ( V_11 , L_52 ) ;
V_195 = - V_229 ;
goto V_237;
}
V_36 = V_232 -> V_239 ;
V_195 = F_86 ( & V_154 -> V_42 , V_36 , F_14 , 0 ,
V_240 , V_2 ) ;
if ( V_195 ) {
F_3 ( V_11 , L_53 ) ;
goto V_237;
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
V_56 = & V_2 -> V_42 [ V_41 ] -> V_48 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> type = V_161 ;
V_56 -> V_241 = V_242 | V_243 | V_244 ;
V_56 -> V_245 = V_2 -> V_42 [ V_41 ] ;
V_56 -> V_31 = & V_246 ;
V_56 -> V_247 = & V_248 ;
V_56 -> V_249 = sizeof( struct V_27 ) ;
V_56 -> V_250 = V_251 ;
V_56 -> V_252 = 1 ;
V_56 -> V_220 = & V_2 -> V_42 [ V_41 ] -> V_197 ;
V_195 = F_87 ( V_56 ) ;
if ( V_195 ) {
F_3 ( V_11 , L_54 ) ;
goto V_237;
}
V_2 -> V_42 [ V_41 ] -> V_70 =
F_88 ( V_2 -> V_4 -> V_154 ) ;
if ( F_89 ( V_2 -> V_42 [ V_41 ] -> V_70 ) ) {
F_3 ( V_11 , L_55 ) ;
V_195 = F_90 ( V_2 -> V_42 [ V_41 ] -> V_70 ) ;
goto V_237;
}
F_91 ( & V_2 -> V_42 [ V_41 ] -> V_25 ) ;
if ( F_77 ( V_2 -> V_42 [ V_41 ] , V_2 , V_154 ) ) {
V_195 = - V_229 ;
goto V_237;
}
}
F_18 ( 1 , V_57 , V_11 ,
L_56 ) ;
return 0 ;
V_237:
for ( V_233 = 0 ; V_233 < V_47 ; V_233 ++ ) {
if ( V_2 -> V_42 [ V_233 ] != NULL ) {
F_92 ( V_2 -> V_42 [ V_233 ] -> V_70 ) ;
F_93 ( & V_2 -> V_42 [ V_233 ] -> V_212 ) ;
F_94 ( V_2 -> V_42 [ V_233 ] ) ;
}
}
return V_195 ;
}
static int F_95 ( struct V_202 * V_154 )
{
struct V_13 * V_205 ;
struct V_1 * V_2 = F_71 ( V_154 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_41 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_57 ) ;
if ( NULL != V_4 -> V_31 . V_253 )
V_4 -> V_31 . V_253 ( & V_154 -> V_42 , V_4 ) ;
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
V_205 = V_2 -> V_42 [ V_41 ] ;
F_92 ( V_205 -> V_70 ) ;
F_93 ( & V_205 -> V_212 ) ;
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
F_94 ( V_2 -> V_42 [ V_41 ] ) ;
V_2 -> V_42 [ V_41 ] = NULL ;
}
return 0 ;
}
