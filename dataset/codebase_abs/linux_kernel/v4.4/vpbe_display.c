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
F_5 ( & V_14 -> V_15 -> V_17 . V_18 ) ;
F_6 ( & V_14 -> V_15 -> V_17 . V_19 , V_20 ) ;
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
V_14 -> V_16 -> V_17 . V_19 . V_29 = V_30 ;
V_23 = F_13 ( & V_14 -> V_16 -> V_17 . V_19 , 0 ) ;
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
F_23 ( struct V_55 * V_60 , const void * V_61 ,
unsigned int * V_62 , unsigned int * V_63 ,
unsigned int V_64 [] , void * V_65 [] )
{
const struct V_66 * V_67 = V_61 ;
struct V_13 * V_14 = F_17 ( V_60 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_4 ) ;
if ( V_67 && V_67 -> V_67 . V_68 . V_58 < V_14 -> V_51 . V_58 )
return - V_59 ;
if ( V_60 -> V_69 + * V_62 < V_70 )
* V_62 = V_70 - V_60 -> V_69 ;
* V_63 = 1 ;
V_64 [ 0 ] = V_67 ? V_67 -> V_67 . V_68 . V_58 : V_14 -> V_51 . V_58 ;
V_65 [ 0 ] = V_14 -> V_71 ;
return 0 ;
}
static void F_24 ( struct V_54 * V_17 )
{
struct V_72 * V_73 = F_25 ( V_17 ) ;
struct V_27 * V_74 = F_26 ( V_73 ,
struct V_27 , V_17 ) ;
struct V_13 * V_14 = F_17 ( V_17 -> V_55 ) ;
struct V_1 * V_75 = V_14 -> V_2 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned long V_76 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_5 ) ;
F_27 ( & V_75 -> V_24 , V_76 ) ;
F_28 ( & V_74 -> V_28 , & V_14 -> V_25 ) ;
F_29 ( & V_75 -> V_24 , V_76 ) ;
}
static int F_30 ( struct V_55 * V_60 , unsigned int V_77 )
{
struct V_13 * V_14 = F_17 ( V_60 ) ;
struct V_21 * V_22 = V_14 -> V_2 -> V_22 ;
int V_5 ;
V_22 -> V_31 . V_78 ( V_22 , V_14 -> V_33 . V_34 ) ;
V_14 -> V_16 = V_14 -> V_15 = F_11 ( V_14 -> V_25 . V_26 ,
struct V_27 , V_28 ) ;
F_12 ( & V_14 -> V_15 -> V_28 ) ;
V_14 -> V_15 -> V_17 . V_19 . V_29 = V_30 ;
V_14 -> V_53 = 0 ;
V_5 = F_31 ( V_14 -> V_2 , V_14 ) ;
if ( V_5 < 0 ) {
struct V_27 * V_74 , * V_79 ;
F_6 ( & V_14 -> V_15 -> V_17 . V_19 ,
V_80 ) ;
F_32 (buf, tmp, &layer->dma_queue, list) {
F_12 ( & V_74 -> V_28 ) ;
F_6 ( & V_74 -> V_17 . V_19 ,
V_80 ) ;
}
return V_5 ;
}
V_14 -> V_49 = 1 ;
return V_5 ;
}
static void F_33 ( struct V_55 * V_60 )
{
struct V_13 * V_14 = F_17 ( V_60 ) ;
struct V_21 * V_22 = V_14 -> V_2 -> V_22 ;
struct V_1 * V_75 = V_14 -> V_2 ;
unsigned long V_76 ;
if ( ! F_34 ( V_60 ) )
return;
V_22 -> V_31 . V_78 ( V_22 , V_14 -> V_33 . V_34 ) ;
F_27 ( & V_75 -> V_24 , V_76 ) ;
if ( V_14 -> V_15 == V_14 -> V_16 ) {
F_6 ( & V_14 -> V_15 -> V_17 . V_19 ,
V_81 ) ;
} else {
if ( V_14 -> V_15 != NULL )
F_6 ( & V_14 -> V_15 -> V_17 . V_19 ,
V_81 ) ;
if ( V_14 -> V_16 != NULL )
F_6 ( & V_14 -> V_16 -> V_17 . V_19 ,
V_81 ) ;
}
while ( ! F_9 ( & V_14 -> V_25 ) ) {
V_14 -> V_16 = F_11 ( V_14 -> V_25 . V_26 ,
struct V_27 , V_28 ) ;
F_12 ( & V_14 -> V_16 -> V_28 ) ;
F_6 ( & V_14 -> V_16 -> V_17 . V_19 ,
V_81 ) ;
}
F_29 ( & V_75 -> V_24 , V_76 ) ;
}
static
struct V_13 *
F_35 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
enum V_82 V_83 , V_84 ;
V_83 = V_14 -> V_85 ;
V_84 = ( V_83 == V_86 ) ?
V_87 : V_86 ;
return V_2 -> V_42 [ V_84 ] ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_88 * V_89 = & V_14 -> V_33 . V_90 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_23 ;
int V_5 ;
V_23 = F_13 ( & V_14 -> V_15 -> V_17 . V_19 , 0 ) ;
V_22 -> V_31 . V_32 ( V_22 ,
V_14 -> V_33 . V_34 ,
V_23 ,
V_2 -> V_35 ) ;
V_5 = V_22 -> V_31 . V_91 ( V_22 ,
V_14 -> V_33 . V_34 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_6 ) ;
return - 1 ;
}
V_14 -> V_33 . V_92 = 1 ;
if ( V_89 -> V_93 == V_94 ) {
struct V_13 * V_95 =
F_35 ( V_2 , V_14 ) ;
V_5 = V_22 -> V_31 . V_91 ( V_22 ,
V_95 -> V_33 . V_34 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_7 ) ;
return - 1 ;
}
V_95 -> V_33 . V_92 = 1 ;
}
return 0 ;
}
static void
F_36 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_96 , int V_97 )
{
struct V_98 * V_33 = & V_14 -> V_33 ;
struct V_99 * V_93 = & V_14 -> V_51 ;
struct V_88 * V_89 = & V_14 -> V_33 . V_90 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_100 ;
int V_101 = 0 ;
int V_102 = 0 ;
int V_103 ;
int V_104 ;
T_2 V_105 = V_4 -> V_106 . V_107 ;
V_89 -> V_108 = V_93 -> V_109 ;
V_89 -> V_110 = V_93 -> V_111 ;
V_33 -> V_112 = V_113 ;
V_33 -> V_114 = V_113 ;
V_33 -> V_101 = V_115 ;
V_33 -> V_102 = V_116 ;
if ( V_93 -> V_109 < V_96 ) {
V_103 = V_4 -> V_106 . V_117 / V_93 -> V_109 ;
if ( V_103 < 2 )
V_103 = 1 ;
else if ( V_103 >= 4 )
V_103 = 4 ;
else
V_103 = 2 ;
V_89 -> V_108 *= V_103 ;
if ( V_89 -> V_108 < V_96 ) {
if ( ( V_105 & V_118 ) ||
( V_105 & V_119 ) ) {
V_100 = ( V_89 -> V_108 *
V_120 ) /
V_121 ;
if ( V_100 <= V_96 ) {
V_101 = 1 ;
V_89 -> V_108 = V_100 ;
}
}
}
if ( V_103 == 2 )
V_33 -> V_112 = V_122 ;
else if ( V_103 == 4 )
V_33 -> V_112 = V_123 ;
if ( V_101 )
V_33 -> V_101 = V_124 ;
} else {
V_89 -> V_108 = V_96 ;
}
if ( V_93 -> V_111 < V_97 ) {
V_104 = V_97 / V_93 -> V_111 ;
if ( V_104 < 2 )
V_104 = 1 ;
else if ( V_104 >= 4 )
V_104 = 4 ;
else
V_104 = 2 ;
V_89 -> V_110 *= V_104 ;
if ( V_89 -> V_110 < V_97 ) {
if ( ( V_105 & V_119 ) ) {
V_100 = ( V_89 -> V_110 *
V_125 ) /
V_126 ;
if ( V_100 <= V_97 ) {
V_102 = 1 ;
V_89 -> V_110 = V_100 ;
}
}
}
if ( V_104 == 2 )
V_33 -> V_114 = V_122 ;
else if ( V_104 == 4 )
V_33 -> V_114 = V_123 ;
if ( V_102 )
V_33 -> V_101 = V_127 ;
} else {
V_89 -> V_110 = V_97 ;
}
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_8 ,
V_89 -> V_108 , V_89 -> V_110 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_128 , int V_129 )
{
struct V_88 * V_89 = & V_14 -> V_33 . V_90 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_89 -> V_130 = F_38 ( ( unsigned int ) V_129 ,
V_4 -> V_106 . V_117 - V_89 -> V_108 ) ;
V_89 -> V_131 = F_38 ( ( unsigned int ) V_128 ,
V_4 -> V_106 . V_132 - V_89 -> V_110 ) ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_9 ,
V_89 -> V_130 , V_89 -> V_131 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ( V_134 -> V_109 == 0 ) ||
( ( V_134 -> V_109 + V_134 -> V_129 ) > V_4 -> V_106 . V_117 ) )
V_134 -> V_109 = V_4 -> V_106 . V_117 - V_134 -> V_129 ;
if ( ( V_134 -> V_111 == 0 ) || ( ( V_134 -> V_111 + V_134 -> V_128 ) >
V_4 -> V_106 . V_132 ) )
V_134 -> V_111 = V_4 -> V_106 . V_132 - V_134 -> V_128 ;
if ( V_4 -> V_106 . V_135 )
V_134 -> V_111 &= ( ~ 0x01 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_99 * V_93 , int V_136 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_137 = 1 ;
int V_138 = 32 ;
int V_139 ;
int V_140 ;
int V_141 ;
if ( ( V_93 -> V_142 != V_143 ) &&
( V_93 -> V_142 != V_144 ) )
V_93 -> V_142 = V_143 ;
if ( ( V_93 -> V_52 != V_145 ) &&
( V_93 -> V_52 != V_50 ) ) {
if ( V_4 -> V_106 . V_135 )
V_93 -> V_52 = V_145 ;
else
V_93 -> V_52 = V_50 ;
}
if ( V_93 -> V_52 == V_145 )
V_137 = 2 ;
if ( V_93 -> V_142 == V_144 )
V_141 = 1 ;
else
V_141 = 2 ;
V_140 = V_4 -> V_106 . V_117 ;
V_139 = V_4 -> V_106 . V_132 ;
V_138 /= V_141 ;
if ( ! V_93 -> V_109 || ( V_93 -> V_109 < V_138 ) ||
( V_93 -> V_109 > V_140 ) ) {
V_93 -> V_109 = V_4 -> V_106 . V_117 ;
}
if ( ! V_93 -> V_111 || ( V_93 -> V_111 < V_137 ) ||
( V_93 -> V_111 > V_139 ) ) {
V_93 -> V_111 = V_4 -> V_106 . V_132 ;
}
if ( V_93 -> V_146 < ( V_93 -> V_109 * V_141 ) )
V_93 -> V_146 = V_93 -> V_109 * V_141 ;
V_93 -> V_146 = ( ( V_93 -> V_109 * V_141 + 31 ) & ~ 31 ) ;
if ( V_93 -> V_142 == V_144 )
V_93 -> V_58 = V_93 -> V_146 * V_93 -> V_111 +
( V_93 -> V_146 * V_93 -> V_111 >> 1 ) ;
else
V_93 -> V_58 = V_93 -> V_146 * V_93 -> V_111 ;
return 0 ;
}
static int F_41 ( struct V_147 * V_147 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
V_150 -> V_151 = V_152 | V_153 ;
V_150 -> V_154 = V_150 -> V_151 | V_155 ;
snprintf ( V_150 -> V_156 , sizeof( V_150 -> V_156 ) , L_10 ,
F_43 ( V_4 -> V_157 ) ) ;
snprintf ( V_150 -> V_158 , sizeof( V_150 -> V_158 ) , L_11 ,
F_43 ( V_4 -> V_157 ) ) ;
F_44 ( V_150 -> V_159 , V_4 -> V_89 -> V_160 , sizeof( V_150 -> V_159 ) ) ;
return 0 ;
}
static int F_45 ( struct V_147 * V_147 , void * V_148 ,
const struct V_161 * V_162 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_88 * V_89 = & V_14 -> V_33 . V_90 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_133 V_163 = V_162 -> V_134 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_12 , V_14 -> V_85 ) ;
if ( V_162 -> type != V_164 ) {
F_3 ( & V_4 -> V_11 , L_13 ) ;
return - V_59 ;
}
if ( V_163 . V_128 < 0 )
V_163 . V_128 = 0 ;
if ( V_163 . V_129 < 0 )
V_163 . V_129 = 0 ;
F_39 ( V_2 , & V_163 ) ;
V_22 -> V_31 . V_165 ( V_22 ,
V_14 -> V_33 . V_34 , V_89 ) ;
F_36 ( V_2 , V_14 ,
V_163 . V_109 ,
V_163 . V_111 ) ;
F_37 ( V_2 , V_14 , V_163 . V_128 ,
V_163 . V_129 ) ;
V_5 = V_22 -> V_31 . V_166 ( V_22 ,
V_14 -> V_33 . V_34 , V_89 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_14 ) ;
return - V_59 ;
}
V_22 -> V_31 . V_167 ( V_22 ,
V_14 -> V_33 . V_34 ,
V_14 -> V_33 . V_112 ,
V_14 -> V_33 . V_114 ) ;
V_5 = V_22 -> V_31 . V_168 ( V_22 ,
V_14 -> V_33 . V_101 ,
V_14 -> V_33 . V_102 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_15 ) ;
return - V_59 ;
}
if ( ( V_14 -> V_33 . V_112 != V_113 ) ||
( V_14 -> V_33 . V_114 != V_113 ) ||
( V_14 -> V_33 . V_101 != V_115 ) ||
( V_14 -> V_33 . V_102 != V_116 ) )
V_22 -> V_31 . V_169 ( V_22 , 1 ) ;
else
V_22 -> V_31 . V_169 ( V_22 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_147 * V_147 , void * V_148 ,
struct V_161 * V_162 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_88 * V_89 = & V_14 -> V_33 . V_90 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
struct V_21 * V_22 = V_14 -> V_2 -> V_22 ;
struct V_133 * V_163 = & V_162 -> V_134 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_16 ,
V_14 -> V_85 ) ;
if ( V_162 -> type != V_164 ) {
F_3 ( & V_4 -> V_11 , L_13 ) ;
return - V_59 ;
}
V_22 -> V_31 . V_165 ( V_22 ,
V_14 -> V_33 . V_34 , V_89 ) ;
V_163 -> V_128 = V_89 -> V_131 ;
V_163 -> V_129 = V_89 -> V_130 ;
V_163 -> V_109 = V_89 -> V_108 ;
V_163 -> V_111 = V_89 -> V_110 ;
return 0 ;
}
static int F_47 ( struct V_147 * V_147 , void * V_148 ,
struct V_170 * V_171 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_17 ) ;
V_171 -> type = V_164 ;
V_171 -> V_172 . V_129 = 0 ;
V_171 -> V_172 . V_128 = 0 ;
V_171 -> V_172 . V_109 = V_4 -> V_106 . V_117 ;
V_171 -> V_172 . V_111 = V_4 -> V_106 . V_132 ;
V_171 -> V_173 = V_4 -> V_106 . V_174 ;
V_171 -> V_175 = V_171 -> V_172 ;
return 0 ;
}
static int F_48 ( struct V_147 * V_147 , void * V_148 ,
struct V_66 * V_67 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_18 ,
V_14 -> V_85 ) ;
if ( V_164 != V_67 -> type ) {
F_3 ( & V_4 -> V_11 , L_19 ) ;
return - V_59 ;
}
V_67 -> V_67 . V_68 = V_14 -> V_51 ;
return 0 ;
}
static int F_49 ( struct V_147 * V_147 , void * V_148 ,
struct V_176 * V_67 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned int V_177 = 0 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_20 ,
V_14 -> V_85 ) ;
if ( V_67 -> V_177 > 1 ) {
F_3 ( & V_4 -> V_11 , L_21 ) ;
return - V_59 ;
}
V_177 = V_67 -> V_177 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_177 = V_177 ;
V_67 -> type = V_164 ;
if ( V_177 == 0 ) {
strcpy ( V_67 -> V_178 , L_22 ) ;
V_67 -> V_142 = V_143 ;
} else {
strcpy ( V_67 -> V_178 , L_23 ) ;
V_67 -> V_142 = V_144 ;
}
return 0 ;
}
static int F_50 ( struct V_147 * V_147 , void * V_148 ,
struct V_66 * V_67 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_88 * V_89 = & V_14 -> V_33 . V_90 ;
struct V_99 * V_93 = & V_67 -> V_67 . V_68 ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_24 ,
V_14 -> V_85 ) ;
if ( F_51 ( & V_14 -> V_48 ) )
return - V_179 ;
if ( V_164 != V_67 -> type ) {
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_19 ) ;
return - V_59 ;
}
V_5 = F_40 ( V_2 , V_93 , 1 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_51 = * V_93 ;
if ( V_93 -> V_142 == V_144 ) {
struct V_13 * V_95 ;
V_95 = F_35 ( V_2 , V_14 ) ;
V_5 = V_22 -> V_31 . V_180 ( V_22 ,
V_95 -> V_33 . V_34 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_25 ) ;
return - V_179 ;
}
}
V_22 -> V_31 . V_165 ( V_22 ,
V_14 -> V_33 . V_34 , V_89 ) ;
V_89 -> V_108 = V_93 -> V_109 ;
V_89 -> V_110 = V_93 -> V_111 ;
V_89 -> V_181 = V_93 -> V_146 ;
V_89 -> V_131 = 0 ;
V_89 -> V_130 = 0 ;
V_89 -> V_135 = V_4 -> V_106 . V_135 ;
if ( V_143 == V_93 -> V_142 )
V_89 -> V_93 = V_182 ;
if ( V_144 == V_93 -> V_142 ) {
struct V_13 * V_95 ;
V_89 -> V_93 = V_94 ;
V_95 = F_35 ( V_2 ,
V_14 ) ;
V_95 -> V_33 . V_90 . V_93 = V_94 ;
}
V_5 = V_22 -> V_31 . V_166 ( V_22 ,
V_14 -> V_33 . V_34 , V_89 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_26 ) ;
return - V_59 ;
}
V_22 -> V_31 . V_165 ( V_22 ,
V_14 -> V_33 . V_34 , V_89 ) ;
return 0 ;
}
static int F_52 ( struct V_147 * V_147 , void * V_148 ,
struct V_66 * V_67 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
struct V_99 * V_93 = & V_67 -> V_67 . V_68 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_27 ) ;
if ( V_164 != V_67 -> type ) {
F_3 ( & V_4 -> V_11 , L_19 ) ;
return - V_59 ;
}
return F_40 ( V_2 , V_93 , 0 ) ;
}
static int F_53 ( struct V_147 * V_147 , void * V_148 ,
T_2 V_107 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_28 ) ;
if ( F_51 ( & V_14 -> V_48 ) )
return - V_179 ;
if ( NULL != V_4 -> V_31 . V_183 ) {
V_5 = V_4 -> V_31 . V_183 ( V_4 , V_107 ) ;
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
static int F_54 ( struct V_147 * V_147 , void * V_148 ,
T_2 * V_107 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_30 ) ;
if ( V_4 -> V_106 . V_184 & V_185 ) {
* V_107 = V_4 -> V_106 . V_107 ;
return 0 ;
}
return - V_59 ;
}
static int F_55 ( struct V_147 * V_147 , void * V_148 ,
struct V_186 * V_187 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_31 ) ;
if ( NULL == V_4 -> V_31 . V_188 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_188 ( V_4 , V_187 ) ;
if ( V_5 ) {
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_32 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_56 ( struct V_147 * V_147 , void * V_148 ,
unsigned int V_41 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_33 ) ;
if ( F_51 ( & V_14 -> V_48 ) )
return - V_179 ;
if ( NULL == V_4 -> V_31 . V_189 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_189 ( V_4 , V_41 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_34 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_57 ( struct V_147 * V_147 , void * V_148 ,
unsigned int * V_41 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_35 ) ;
* V_41 = V_4 -> V_190 ;
return 0 ;
}
static int
F_58 ( struct V_147 * V_147 , void * V_148 ,
struct V_191 * V_192 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_36 ) ;
if ( NULL == V_4 -> V_31 . V_193 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_193 ( V_4 , V_192 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_37 ) ;
return - V_59 ;
}
return 0 ;
}
static int
F_59 ( struct V_147 * V_147 , void * V_148 ,
struct V_194 * V_192 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_38 ) ;
if ( F_51 ( & V_14 -> V_48 ) )
return - V_179 ;
if ( ! V_4 -> V_31 . V_195 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_195 ( V_4 , V_192 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_39 ) ;
return - V_59 ;
}
return 0 ;
}
static int
F_60 ( struct V_147 * V_147 , void * V_148 ,
struct V_194 * V_196 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_40 ) ;
if ( V_4 -> V_106 . V_184 &
V_197 ) {
* V_196 = V_4 -> V_106 . V_196 ;
} else {
return - V_59 ;
}
return 0 ;
}
static int F_61 ( struct V_147 * V_147 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_198 ;
V_198 = F_62 ( V_147 ) ;
if ( V_198 ) {
F_3 ( & V_4 -> V_11 , L_41 ) ;
return V_198 ;
}
if ( ! F_63 ( V_147 ) )
return V_198 ;
if ( ! V_14 -> V_199 ) {
if ( F_64 ( & V_14 -> V_200 ) )
return - V_201 ;
V_198 = V_22 -> V_31 . V_180 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
F_65 ( & V_14 -> V_200 ) ;
if ( V_198 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_25 ) ;
F_66 ( V_147 ) ;
return - V_59 ;
}
}
V_14 -> V_199 ++ ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_42 ) ;
return 0 ;
}
static int F_67 ( struct V_147 * V_147 )
{
struct V_13 * V_14 = F_42 ( V_147 ) ;
struct V_88 * V_89 = & V_14 -> V_33 . V_90 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_43 ) ;
F_68 ( & V_14 -> V_200 ) ;
V_22 -> V_31 . V_78 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
V_14 -> V_199 -- ;
if ( ! V_14 -> V_199 ) {
if ( V_89 -> V_93 == V_94 ) {
struct V_13 * V_95 ;
V_95 =
F_35 ( V_2 , V_14 ) ;
V_22 -> V_31 . V_78 ( V_22 ,
V_95 -> V_33 . V_34 ) ;
V_22 -> V_31 . V_202 ( V_22 ,
V_95 -> V_33 . V_34 ) ;
}
V_22 -> V_31 . V_78 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
V_22 -> V_31 . V_202 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
}
F_69 ( V_147 , NULL ) ;
F_65 ( & V_14 -> V_200 ) ;
V_2 -> V_35 = 0 ;
return 0 ;
}
static int F_70 ( struct V_203 * V_42 , void * V_204 )
{
struct V_205 * V_157 = F_71 ( V_42 ) ;
struct V_1 * V_206 = V_204 ;
if ( strcmp ( L_44 , V_157 -> V_207 ) == 0 )
V_206 -> V_4 = F_72 ( V_157 ) ;
if ( strstr ( V_157 -> V_207 , L_45 ) != NULL )
V_206 -> V_22 = F_72 ( V_157 ) ;
return 0 ;
}
static int F_73 ( int V_41 , struct V_1 * V_2 ,
struct V_205 * V_157 )
{
struct V_13 * V_208 = NULL ;
struct V_209 * V_210 = NULL ;
V_2 -> V_42 [ V_41 ] =
F_74 ( sizeof( struct V_13 ) , V_211 ) ;
if ( ! V_2 -> V_42 [ V_41 ] ) {
F_75 ( V_212 L_46 ) ;
return - V_213 ;
}
F_76 ( & V_2 -> V_42 [ V_41 ] -> V_214 ) ;
F_77 ( & V_2 -> V_42 [ V_41 ] -> V_200 ) ;
V_208 = V_2 -> V_42 [ V_41 ] ;
V_210 = & V_208 -> V_215 ;
V_210 -> V_216 = V_217 ;
V_210 -> V_218 = & V_219 ;
V_210 -> V_220 = & V_221 ;
V_210 -> V_222 = - 1 ;
V_210 -> V_11 = & V_2 -> V_4 -> V_11 ;
V_210 -> V_223 = & V_208 -> V_200 ;
V_210 -> V_224 = V_225 ;
if ( V_2 -> V_4 -> V_106 . V_184 &
V_185 )
V_210 -> V_226 = ( V_118 | V_119 ) ;
snprintf ( V_210 -> V_207 , sizeof( V_210 -> V_207 ) ,
L_47 ,
( V_227 >> 16 ) & 0xff ,
( V_227 >> 8 ) & 0xff ,
( V_227 ) & 0xff ) ;
V_208 -> V_85 = V_41 ;
V_208 -> V_33 . V_34 =
( ( V_41 == V_86 ) ? V_228 : V_229 ) ;
return 0 ;
}
static int F_78 ( struct V_13 * V_208 ,
struct V_1 * V_2 ,
struct V_205 * V_157 )
{
int V_198 ;
F_79 ( & V_2 -> V_4 -> V_11 ,
L_48 ) ;
F_79 ( & V_2 -> V_4 -> V_11 ,
L_49 ,
( int ) V_208 ,
( int ) & V_208 -> V_215 ) ;
V_208 -> V_215 . V_230 = & V_208 -> V_48 ;
V_198 = F_80 ( & V_208 -> V_215 ,
V_231 ,
- 1 ) ;
if ( V_198 )
return - V_232 ;
V_208 -> V_2 = V_2 ;
F_81 ( V_157 , V_2 ) ;
F_82 ( & V_208 -> V_215 ,
V_208 ) ;
return 0 ;
}
static int F_83 ( struct V_205 * V_157 )
{
struct V_1 * V_2 ;
struct V_233 * V_11 ;
struct V_234 * V_235 = NULL ;
struct V_55 * V_56 ;
int V_236 ;
int V_41 ;
int V_198 ;
int V_36 ;
F_75 ( V_237 L_50 ) ;
V_2 = F_84 ( & V_157 -> V_42 , sizeof( struct V_1 ) ,
V_211 ) ;
if ( ! V_2 )
return - V_213 ;
F_76 ( & V_2 -> V_24 ) ;
V_198 = F_85 ( & V_238 , NULL , V_2 ,
F_70 ) ;
if ( V_198 < 0 )
return V_198 ;
V_11 = & V_2 -> V_4 -> V_11 ;
if ( NULL != V_2 -> V_4 -> V_31 . V_239 ) {
V_198 = V_2 -> V_4 -> V_31 . V_239 ( & V_157 -> V_42 ,
V_2 -> V_4 ) ;
if ( V_198 ) {
F_3 ( V_11 , L_51 ) ;
V_198 = - V_213 ;
goto V_240;
}
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
if ( F_73 ( V_41 , V_2 , V_157 ) ) {
V_198 = - V_232 ;
goto V_240;
}
}
V_235 = F_86 ( V_157 , V_241 , 0 ) ;
if ( ! V_235 ) {
F_3 ( V_11 , L_52 ) ;
V_198 = - V_232 ;
goto V_240;
}
V_36 = V_235 -> V_242 ;
V_198 = F_87 ( & V_157 -> V_42 , V_36 , F_14 , 0 ,
V_243 , V_2 ) ;
if ( V_198 ) {
F_3 ( V_11 , L_53 ) ;
goto V_240;
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
V_56 = & V_2 -> V_42 [ V_41 ] -> V_48 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> type = V_164 ;
V_56 -> V_244 = V_245 | V_246 | V_247 ;
V_56 -> V_248 = V_2 -> V_42 [ V_41 ] ;
V_56 -> V_31 = & V_249 ;
V_56 -> V_250 = & V_251 ;
V_56 -> V_252 = sizeof( struct V_27 ) ;
V_56 -> V_253 = V_254 ;
V_56 -> V_255 = 1 ;
V_56 -> V_223 = & V_2 -> V_42 [ V_41 ] -> V_200 ;
V_198 = F_88 ( V_56 ) ;
if ( V_198 ) {
F_3 ( V_11 , L_54 ) ;
goto V_240;
}
V_2 -> V_42 [ V_41 ] -> V_71 =
F_89 ( V_2 -> V_4 -> V_157 ) ;
if ( F_90 ( V_2 -> V_42 [ V_41 ] -> V_71 ) ) {
F_3 ( V_11 , L_55 ) ;
V_198 = F_91 ( V_2 -> V_42 [ V_41 ] -> V_71 ) ;
goto V_240;
}
F_92 ( & V_2 -> V_42 [ V_41 ] -> V_25 ) ;
if ( F_78 ( V_2 -> V_42 [ V_41 ] , V_2 , V_157 ) ) {
V_198 = - V_232 ;
goto V_240;
}
}
F_18 ( 1 , V_57 , V_11 ,
L_56 ) ;
return 0 ;
V_240:
for ( V_236 = 0 ; V_236 < V_47 ; V_236 ++ ) {
if ( V_2 -> V_42 [ V_236 ] != NULL ) {
F_93 ( V_2 -> V_42 [ V_236 ] -> V_71 ) ;
F_94 ( & V_2 -> V_42 [ V_236 ] -> V_215 ) ;
F_95 ( V_2 -> V_42 [ V_236 ] ) ;
}
}
return V_198 ;
}
static int F_96 ( struct V_205 * V_157 )
{
struct V_13 * V_208 ;
struct V_1 * V_2 = F_72 ( V_157 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_41 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_57 ) ;
if ( NULL != V_4 -> V_31 . V_256 )
V_4 -> V_31 . V_256 ( & V_157 -> V_42 , V_4 ) ;
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
V_208 = V_2 -> V_42 [ V_41 ] ;
F_93 ( V_208 -> V_71 ) ;
F_94 ( & V_208 -> V_215 ) ;
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
F_95 ( V_2 -> V_42 [ V_41 ] ) ;
V_2 -> V_42 [ V_41 ] = NULL ;
}
return 0 ;
}
