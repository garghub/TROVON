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
V_14 -> V_15 -> V_17 . V_18 . V_19 = F_5 () ;
F_6 ( & V_14 -> V_15 -> V_17 . V_18 , V_20 ) ;
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
V_14 -> V_16 -> V_17 . V_18 . V_29 = V_30 ;
V_23 = F_13 ( & V_14 -> V_16 -> V_17 . V_18 , 0 ) ;
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
F_23 ( struct V_55 * V_60 ,
unsigned int * V_61 , unsigned int * V_62 ,
unsigned int V_63 [] , struct V_64 * V_65 [] )
{
struct V_13 * V_14 = F_17 ( V_60 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_4 ) ;
if ( V_60 -> V_66 + * V_61 < V_67 )
* V_61 = V_67 - V_60 -> V_66 ;
if ( * V_62 )
return V_63 [ 0 ] < V_14 -> V_51 . V_58 ? - V_59 : 0 ;
* V_62 = 1 ;
V_63 [ 0 ] = V_14 -> V_51 . V_58 ;
return 0 ;
}
static void F_24 ( struct V_54 * V_17 )
{
struct V_68 * V_69 = F_25 ( V_17 ) ;
struct V_27 * V_70 = F_26 ( V_69 ,
struct V_27 , V_17 ) ;
struct V_13 * V_14 = F_17 ( V_17 -> V_55 ) ;
struct V_1 * V_71 = V_14 -> V_2 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned long V_72 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_5 ) ;
F_27 ( & V_71 -> V_24 , V_72 ) ;
F_28 ( & V_70 -> V_28 , & V_14 -> V_25 ) ;
F_29 ( & V_71 -> V_24 , V_72 ) ;
}
static int F_30 ( struct V_55 * V_60 , unsigned int V_73 )
{
struct V_13 * V_14 = F_17 ( V_60 ) ;
struct V_21 * V_22 = V_14 -> V_2 -> V_22 ;
int V_5 ;
V_22 -> V_31 . V_74 ( V_22 , V_14 -> V_33 . V_34 ) ;
V_14 -> V_16 = V_14 -> V_15 = F_11 ( V_14 -> V_25 . V_26 ,
struct V_27 , V_28 ) ;
F_12 ( & V_14 -> V_15 -> V_28 ) ;
V_14 -> V_15 -> V_17 . V_18 . V_29 = V_30 ;
V_14 -> V_53 = 0 ;
V_5 = F_31 ( V_14 -> V_2 , V_14 ) ;
if ( V_5 < 0 ) {
struct V_27 * V_70 , * V_75 ;
F_6 ( & V_14 -> V_15 -> V_17 . V_18 ,
V_76 ) ;
F_32 (buf, tmp, &layer->dma_queue, list) {
F_12 ( & V_70 -> V_28 ) ;
F_6 ( & V_70 -> V_17 . V_18 ,
V_76 ) ;
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
struct V_1 * V_71 = V_14 -> V_2 ;
unsigned long V_72 ;
if ( ! F_34 ( V_60 ) )
return;
V_22 -> V_31 . V_74 ( V_22 , V_14 -> V_33 . V_34 ) ;
F_27 ( & V_71 -> V_24 , V_72 ) ;
if ( V_14 -> V_15 == V_14 -> V_16 ) {
F_6 ( & V_14 -> V_15 -> V_17 . V_18 ,
V_77 ) ;
} else {
if ( V_14 -> V_15 != NULL )
F_6 ( & V_14 -> V_15 -> V_17 . V_18 ,
V_77 ) ;
if ( V_14 -> V_16 != NULL )
F_6 ( & V_14 -> V_16 -> V_17 . V_18 ,
V_77 ) ;
}
while ( ! F_9 ( & V_14 -> V_25 ) ) {
V_14 -> V_16 = F_11 ( V_14 -> V_25 . V_26 ,
struct V_27 , V_28 ) ;
F_12 ( & V_14 -> V_16 -> V_28 ) ;
F_6 ( & V_14 -> V_16 -> V_17 . V_18 ,
V_77 ) ;
}
F_29 ( & V_71 -> V_24 , V_72 ) ;
}
static
struct V_13 *
F_35 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
enum V_78 V_79 , V_80 ;
V_79 = V_14 -> V_81 ;
V_80 = ( V_79 == V_82 ) ?
V_83 : V_82 ;
return V_2 -> V_42 [ V_80 ] ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_84 * V_85 = & V_14 -> V_33 . V_86 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_23 ;
int V_5 ;
V_23 = F_13 ( & V_14 -> V_15 -> V_17 . V_18 , 0 ) ;
V_22 -> V_31 . V_32 ( V_22 ,
V_14 -> V_33 . V_34 ,
V_23 ,
V_2 -> V_35 ) ;
V_5 = V_22 -> V_31 . V_87 ( V_22 ,
V_14 -> V_33 . V_34 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_6 ) ;
return - 1 ;
}
V_14 -> V_33 . V_88 = 1 ;
if ( V_85 -> V_89 == V_90 ) {
struct V_13 * V_91 =
F_35 ( V_2 , V_14 ) ;
V_5 = V_22 -> V_31 . V_87 ( V_22 ,
V_91 -> V_33 . V_34 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_7 ) ;
return - 1 ;
}
V_91 -> V_33 . V_88 = 1 ;
}
return 0 ;
}
static void
F_36 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_92 , int V_93 )
{
struct V_94 * V_33 = & V_14 -> V_33 ;
struct V_95 * V_89 = & V_14 -> V_51 ;
struct V_84 * V_85 = & V_14 -> V_33 . V_86 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_96 ;
int V_97 = 0 ;
int V_98 = 0 ;
int V_99 ;
int V_100 ;
T_2 V_101 = V_4 -> V_102 . V_103 ;
V_85 -> V_104 = V_89 -> V_105 ;
V_85 -> V_106 = V_89 -> V_107 ;
V_33 -> V_108 = V_109 ;
V_33 -> V_110 = V_109 ;
V_33 -> V_97 = V_111 ;
V_33 -> V_98 = V_112 ;
if ( V_89 -> V_105 < V_92 ) {
V_99 = V_4 -> V_102 . V_113 / V_89 -> V_105 ;
if ( V_99 < 2 )
V_99 = 1 ;
else if ( V_99 >= 4 )
V_99 = 4 ;
else
V_99 = 2 ;
V_85 -> V_104 *= V_99 ;
if ( V_85 -> V_104 < V_92 ) {
if ( ( V_101 & V_114 ) ||
( V_101 & V_115 ) ) {
V_96 = ( V_85 -> V_104 *
V_116 ) /
V_117 ;
if ( V_96 <= V_92 ) {
V_97 = 1 ;
V_85 -> V_104 = V_96 ;
}
}
}
if ( V_99 == 2 )
V_33 -> V_108 = V_118 ;
else if ( V_99 == 4 )
V_33 -> V_108 = V_119 ;
if ( V_97 )
V_33 -> V_97 = V_120 ;
} else {
V_85 -> V_104 = V_92 ;
}
if ( V_89 -> V_107 < V_93 ) {
V_100 = V_93 / V_89 -> V_107 ;
if ( V_100 < 2 )
V_100 = 1 ;
else if ( V_100 >= 4 )
V_100 = 4 ;
else
V_100 = 2 ;
V_85 -> V_106 *= V_100 ;
if ( V_85 -> V_106 < V_93 ) {
if ( ( V_101 & V_115 ) ) {
V_96 = ( V_85 -> V_106 *
V_121 ) /
V_122 ;
if ( V_96 <= V_93 ) {
V_98 = 1 ;
V_85 -> V_106 = V_96 ;
}
}
}
if ( V_100 == 2 )
V_33 -> V_110 = V_118 ;
else if ( V_100 == 4 )
V_33 -> V_110 = V_119 ;
if ( V_98 )
V_33 -> V_97 = V_123 ;
} else {
V_85 -> V_106 = V_93 ;
}
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_8 ,
V_85 -> V_104 , V_85 -> V_106 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_124 , int V_125 )
{
struct V_84 * V_85 = & V_14 -> V_33 . V_86 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_85 -> V_126 = F_38 ( ( unsigned int ) V_125 ,
V_4 -> V_102 . V_113 - V_85 -> V_104 ) ;
V_85 -> V_127 = F_38 ( ( unsigned int ) V_124 ,
V_4 -> V_102 . V_128 - V_85 -> V_106 ) ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_9 ,
V_85 -> V_126 , V_85 -> V_127 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ( V_130 -> V_105 == 0 ) ||
( ( V_130 -> V_105 + V_130 -> V_125 ) > V_4 -> V_102 . V_113 ) )
V_130 -> V_105 = V_4 -> V_102 . V_113 - V_130 -> V_125 ;
if ( ( V_130 -> V_107 == 0 ) || ( ( V_130 -> V_107 + V_130 -> V_124 ) >
V_4 -> V_102 . V_128 ) )
V_130 -> V_107 = V_4 -> V_102 . V_128 - V_130 -> V_124 ;
if ( V_4 -> V_102 . V_131 )
V_130 -> V_107 &= ( ~ 0x01 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_95 * V_89 , int V_132 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_133 = 1 ;
int V_134 = 32 ;
int V_135 ;
int V_136 ;
int V_137 ;
if ( ( V_89 -> V_138 != V_139 ) &&
( V_89 -> V_138 != V_140 ) )
V_89 -> V_138 = V_139 ;
if ( ( V_89 -> V_52 != V_141 ) &&
( V_89 -> V_52 != V_50 ) ) {
if ( V_4 -> V_102 . V_131 )
V_89 -> V_52 = V_141 ;
else
V_89 -> V_52 = V_50 ;
}
if ( V_89 -> V_52 == V_141 )
V_133 = 2 ;
if ( V_89 -> V_138 == V_140 )
V_137 = 1 ;
else
V_137 = 2 ;
V_136 = V_4 -> V_102 . V_113 ;
V_135 = V_4 -> V_102 . V_128 ;
V_134 /= V_137 ;
if ( ! V_89 -> V_105 || ( V_89 -> V_105 < V_134 ) ||
( V_89 -> V_105 > V_136 ) ) {
V_89 -> V_105 = V_4 -> V_102 . V_113 ;
}
if ( ! V_89 -> V_107 || ( V_89 -> V_107 < V_133 ) ||
( V_89 -> V_107 > V_135 ) ) {
V_89 -> V_107 = V_4 -> V_102 . V_128 ;
}
if ( V_89 -> V_142 < ( V_89 -> V_105 * V_137 ) )
V_89 -> V_142 = V_89 -> V_105 * V_137 ;
V_89 -> V_142 = ( ( V_89 -> V_105 * V_137 + 31 ) & ~ 31 ) ;
if ( V_89 -> V_138 == V_140 )
V_89 -> V_58 = V_89 -> V_142 * V_89 -> V_107 +
( V_89 -> V_142 * V_89 -> V_107 >> 1 ) ;
else
V_89 -> V_58 = V_89 -> V_142 * V_89 -> V_107 ;
return 0 ;
}
static int F_41 ( struct V_143 * V_143 , void * V_144 ,
struct V_145 * V_146 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
V_146 -> V_147 = V_148 | V_149 ;
V_146 -> V_150 = V_146 -> V_147 | V_151 ;
snprintf ( V_146 -> V_152 , sizeof( V_146 -> V_152 ) , L_10 ,
F_43 ( V_4 -> V_153 ) ) ;
snprintf ( V_146 -> V_154 , sizeof( V_146 -> V_154 ) , L_11 ,
F_43 ( V_4 -> V_153 ) ) ;
F_44 ( V_146 -> V_155 , V_4 -> V_85 -> V_156 , sizeof( V_146 -> V_155 ) ) ;
return 0 ;
}
static int F_45 ( struct V_143 * V_143 , void * V_144 ,
const struct V_157 * V_158 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_84 * V_85 = & V_14 -> V_33 . V_86 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_129 V_159 = V_158 -> V_130 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_12 , V_14 -> V_81 ) ;
if ( V_158 -> type != V_160 ) {
F_3 ( & V_4 -> V_11 , L_13 ) ;
return - V_59 ;
}
if ( V_159 . V_124 < 0 )
V_159 . V_124 = 0 ;
if ( V_159 . V_125 < 0 )
V_159 . V_125 = 0 ;
F_39 ( V_2 , & V_159 ) ;
V_22 -> V_31 . V_161 ( V_22 ,
V_14 -> V_33 . V_34 , V_85 ) ;
F_36 ( V_2 , V_14 ,
V_159 . V_105 ,
V_159 . V_107 ) ;
F_37 ( V_2 , V_14 , V_159 . V_124 ,
V_159 . V_125 ) ;
V_5 = V_22 -> V_31 . V_162 ( V_22 ,
V_14 -> V_33 . V_34 , V_85 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_14 ) ;
return - V_59 ;
}
V_22 -> V_31 . V_163 ( V_22 ,
V_14 -> V_33 . V_34 ,
V_14 -> V_33 . V_108 ,
V_14 -> V_33 . V_110 ) ;
V_5 = V_22 -> V_31 . V_164 ( V_22 ,
V_14 -> V_33 . V_97 ,
V_14 -> V_33 . V_98 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_15 ) ;
return - V_59 ;
}
if ( ( V_14 -> V_33 . V_108 != V_109 ) ||
( V_14 -> V_33 . V_110 != V_109 ) ||
( V_14 -> V_33 . V_97 != V_111 ) ||
( V_14 -> V_33 . V_98 != V_112 ) )
V_22 -> V_31 . V_165 ( V_22 , 1 ) ;
else
V_22 -> V_31 . V_165 ( V_22 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_143 * V_143 , void * V_144 ,
struct V_157 * V_158 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_84 * V_85 = & V_14 -> V_33 . V_86 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
struct V_21 * V_22 = V_14 -> V_2 -> V_22 ;
struct V_129 * V_159 = & V_158 -> V_130 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_16 ,
V_14 -> V_81 ) ;
if ( V_158 -> type != V_160 ) {
F_3 ( & V_4 -> V_11 , L_13 ) ;
return - V_59 ;
}
V_22 -> V_31 . V_161 ( V_22 ,
V_14 -> V_33 . V_34 , V_85 ) ;
V_159 -> V_124 = V_85 -> V_127 ;
V_159 -> V_125 = V_85 -> V_126 ;
V_159 -> V_105 = V_85 -> V_104 ;
V_159 -> V_107 = V_85 -> V_106 ;
return 0 ;
}
static int F_47 ( struct V_143 * V_143 , void * V_144 ,
struct V_166 * V_167 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_17 ) ;
V_167 -> type = V_160 ;
V_167 -> V_168 . V_125 = 0 ;
V_167 -> V_168 . V_124 = 0 ;
V_167 -> V_168 . V_105 = V_4 -> V_102 . V_113 ;
V_167 -> V_168 . V_107 = V_4 -> V_102 . V_128 ;
V_167 -> V_169 = V_4 -> V_102 . V_170 ;
V_167 -> V_171 = V_167 -> V_168 ;
return 0 ;
}
static int F_48 ( struct V_143 * V_143 , void * V_144 ,
struct V_172 * V_173 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_18 ,
V_14 -> V_81 ) ;
if ( V_160 != V_173 -> type ) {
F_3 ( & V_4 -> V_11 , L_19 ) ;
return - V_59 ;
}
V_173 -> V_173 . V_174 = V_14 -> V_51 ;
return 0 ;
}
static int F_49 ( struct V_143 * V_143 , void * V_144 ,
struct V_175 * V_173 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned int V_176 = 0 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_20 ,
V_14 -> V_81 ) ;
if ( V_173 -> V_176 > 1 ) {
F_3 ( & V_4 -> V_11 , L_21 ) ;
return - V_59 ;
}
V_176 = V_173 -> V_176 ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_176 = V_176 ;
V_173 -> type = V_160 ;
if ( V_176 == 0 ) {
strcpy ( V_173 -> V_177 , L_22 ) ;
V_173 -> V_138 = V_139 ;
} else {
strcpy ( V_173 -> V_177 , L_23 ) ;
V_173 -> V_138 = V_140 ;
}
return 0 ;
}
static int F_50 ( struct V_143 * V_143 , void * V_144 ,
struct V_172 * V_173 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_84 * V_85 = & V_14 -> V_33 . V_86 ;
struct V_95 * V_89 = & V_173 -> V_173 . V_174 ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_24 ,
V_14 -> V_81 ) ;
if ( F_51 ( & V_14 -> V_48 ) )
return - V_178 ;
if ( V_160 != V_173 -> type ) {
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_19 ) ;
return - V_59 ;
}
V_5 = F_40 ( V_2 , V_89 , 1 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_51 = * V_89 ;
if ( V_89 -> V_138 == V_140 ) {
struct V_13 * V_91 ;
V_91 = F_35 ( V_2 , V_14 ) ;
V_5 = V_22 -> V_31 . V_179 ( V_22 ,
V_91 -> V_33 . V_34 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_25 ) ;
return - V_178 ;
}
}
V_22 -> V_31 . V_161 ( V_22 ,
V_14 -> V_33 . V_34 , V_85 ) ;
V_85 -> V_104 = V_89 -> V_105 ;
V_85 -> V_106 = V_89 -> V_107 ;
V_85 -> V_180 = V_89 -> V_142 ;
V_85 -> V_127 = 0 ;
V_85 -> V_126 = 0 ;
V_85 -> V_131 = V_4 -> V_102 . V_131 ;
if ( V_139 == V_89 -> V_138 )
V_85 -> V_89 = V_181 ;
if ( V_140 == V_89 -> V_138 ) {
struct V_13 * V_91 ;
V_85 -> V_89 = V_90 ;
V_91 = F_35 ( V_2 ,
V_14 ) ;
V_91 -> V_33 . V_86 . V_89 = V_90 ;
}
V_5 = V_22 -> V_31 . V_162 ( V_22 ,
V_14 -> V_33 . V_34 , V_85 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_26 ) ;
return - V_59 ;
}
V_22 -> V_31 . V_161 ( V_22 ,
V_14 -> V_33 . V_34 , V_85 ) ;
return 0 ;
}
static int F_52 ( struct V_143 * V_143 , void * V_144 ,
struct V_172 * V_173 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
struct V_95 * V_89 = & V_173 -> V_173 . V_174 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_27 ) ;
if ( V_160 != V_173 -> type ) {
F_3 ( & V_4 -> V_11 , L_19 ) ;
return - V_59 ;
}
return F_40 ( V_2 , V_89 , 0 ) ;
}
static int F_53 ( struct V_143 * V_143 , void * V_144 ,
T_2 V_103 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_28 ) ;
if ( F_51 ( & V_14 -> V_48 ) )
return - V_178 ;
if ( NULL != V_4 -> V_31 . V_182 ) {
V_5 = V_4 -> V_31 . V_182 ( V_4 , V_103 ) ;
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
static int F_54 ( struct V_143 * V_143 , void * V_144 ,
T_2 * V_103 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_30 ) ;
if ( V_4 -> V_102 . V_183 & V_184 ) {
* V_103 = V_4 -> V_102 . V_103 ;
return 0 ;
}
return - V_59 ;
}
static int F_55 ( struct V_143 * V_143 , void * V_144 ,
struct V_185 * V_186 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_31 ) ;
if ( NULL == V_4 -> V_31 . V_187 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_187 ( V_4 , V_186 ) ;
if ( V_5 ) {
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_32 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_56 ( struct V_143 * V_143 , void * V_144 ,
unsigned int V_41 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_33 ) ;
if ( F_51 ( & V_14 -> V_48 ) )
return - V_178 ;
if ( NULL == V_4 -> V_31 . V_188 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_188 ( V_4 , V_41 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_34 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_57 ( struct V_143 * V_143 , void * V_144 ,
unsigned int * V_41 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_35 ) ;
* V_41 = V_4 -> V_189 ;
return 0 ;
}
static int
F_58 ( struct V_143 * V_143 , void * V_144 ,
struct V_190 * V_191 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_36 ) ;
if ( NULL == V_4 -> V_31 . V_192 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_192 ( V_4 , V_191 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_37 ) ;
return - V_59 ;
}
return 0 ;
}
static int
F_59 ( struct V_143 * V_143 , void * V_144 ,
struct V_193 * V_191 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_38 ) ;
if ( F_51 ( & V_14 -> V_48 ) )
return - V_178 ;
if ( ! V_4 -> V_31 . V_194 )
return - V_59 ;
V_5 = V_4 -> V_31 . V_194 ( V_4 , V_191 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_39 ) ;
return - V_59 ;
}
return 0 ;
}
static int
F_60 ( struct V_143 * V_143 , void * V_144 ,
struct V_193 * V_195 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_40 ) ;
if ( V_4 -> V_102 . V_183 &
V_196 ) {
* V_195 = V_4 -> V_102 . V_195 ;
} else {
return - V_59 ;
}
return 0 ;
}
static int F_61 ( struct V_143 * V_143 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_197 ;
V_197 = F_62 ( V_143 ) ;
if ( V_197 ) {
F_3 ( & V_4 -> V_11 , L_41 ) ;
return V_197 ;
}
if ( ! F_63 ( V_143 ) )
return V_197 ;
if ( ! V_14 -> V_198 ) {
if ( F_64 ( & V_14 -> V_199 ) )
return - V_200 ;
V_197 = V_22 -> V_31 . V_179 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
F_65 ( & V_14 -> V_199 ) ;
if ( V_197 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_25 ) ;
F_66 ( V_143 ) ;
return - V_59 ;
}
}
V_14 -> V_198 ++ ;
F_18 ( 1 , V_57 , & V_4 -> V_11 ,
L_42 ) ;
return 0 ;
}
static int F_67 ( struct V_143 * V_143 )
{
struct V_13 * V_14 = F_42 ( V_143 ) ;
struct V_84 * V_85 = & V_14 -> V_33 . V_86 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_43 ) ;
F_68 ( & V_14 -> V_199 ) ;
V_22 -> V_31 . V_74 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
V_14 -> V_198 -- ;
if ( ! V_14 -> V_198 ) {
if ( V_85 -> V_89 == V_90 ) {
struct V_13 * V_91 ;
V_91 =
F_35 ( V_2 , V_14 ) ;
V_22 -> V_31 . V_74 ( V_22 ,
V_91 -> V_33 . V_34 ) ;
V_22 -> V_31 . V_201 ( V_22 ,
V_91 -> V_33 . V_34 ) ;
}
V_22 -> V_31 . V_74 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
V_22 -> V_31 . V_201 ( V_22 ,
V_14 -> V_33 . V_34 ) ;
}
F_69 ( V_143 , NULL ) ;
F_65 ( & V_14 -> V_199 ) ;
V_2 -> V_35 = 0 ;
return 0 ;
}
static int F_70 ( struct V_64 * V_42 , void * V_202 )
{
struct V_203 * V_153 = F_71 ( V_42 ) ;
struct V_1 * V_204 = V_202 ;
if ( strcmp ( L_44 , V_153 -> V_205 ) == 0 )
V_204 -> V_4 = F_72 ( V_153 ) ;
if ( strstr ( V_153 -> V_205 , L_45 ) != NULL )
V_204 -> V_22 = F_72 ( V_153 ) ;
return 0 ;
}
static int F_73 ( int V_41 , struct V_1 * V_2 ,
struct V_203 * V_153 )
{
struct V_13 * V_206 = NULL ;
struct V_207 * V_208 = NULL ;
V_2 -> V_42 [ V_41 ] =
F_74 ( sizeof( struct V_13 ) , V_209 ) ;
if ( ! V_2 -> V_42 [ V_41 ] ) {
F_75 ( V_210 L_46 ) ;
return - V_211 ;
}
F_76 ( & V_2 -> V_42 [ V_41 ] -> V_212 ) ;
F_77 ( & V_2 -> V_42 [ V_41 ] -> V_199 ) ;
V_206 = V_2 -> V_42 [ V_41 ] ;
V_208 = & V_206 -> V_213 ;
V_208 -> V_214 = V_215 ;
V_208 -> V_216 = & V_217 ;
V_208 -> V_218 = & V_219 ;
V_208 -> V_220 = - 1 ;
V_208 -> V_11 = & V_2 -> V_4 -> V_11 ;
V_208 -> V_221 = & V_206 -> V_199 ;
V_208 -> V_222 = V_223 ;
if ( V_2 -> V_4 -> V_102 . V_183 &
V_184 )
V_208 -> V_224 = ( V_114 | V_115 ) ;
snprintf ( V_208 -> V_205 , sizeof( V_208 -> V_205 ) ,
L_47 ,
( V_225 >> 16 ) & 0xff ,
( V_225 >> 8 ) & 0xff ,
( V_225 ) & 0xff ) ;
V_206 -> V_81 = V_41 ;
V_206 -> V_33 . V_34 =
( ( V_41 == V_82 ) ? V_226 : V_227 ) ;
return 0 ;
}
static int F_78 ( struct V_13 * V_206 ,
struct V_1 * V_2 ,
struct V_203 * V_153 )
{
int V_197 ;
F_79 ( & V_2 -> V_4 -> V_11 ,
L_48 ) ;
F_79 ( & V_2 -> V_4 -> V_11 ,
L_49 ,
( int ) V_206 ,
( int ) & V_206 -> V_213 ) ;
V_206 -> V_213 . V_228 = & V_206 -> V_48 ;
V_197 = F_80 ( & V_206 -> V_213 ,
V_229 ,
- 1 ) ;
if ( V_197 )
return - V_230 ;
V_206 -> V_2 = V_2 ;
F_81 ( V_153 , V_2 ) ;
F_82 ( & V_206 -> V_213 ,
V_206 ) ;
return 0 ;
}
static int F_83 ( struct V_203 * V_153 )
{
struct V_1 * V_2 ;
struct V_231 * V_11 ;
struct V_232 * V_233 = NULL ;
struct V_55 * V_56 ;
int V_234 ;
int V_41 ;
int V_197 ;
int V_36 ;
F_75 ( V_235 L_50 ) ;
V_2 = F_84 ( & V_153 -> V_42 , sizeof( struct V_1 ) ,
V_209 ) ;
if ( ! V_2 )
return - V_211 ;
F_76 ( & V_2 -> V_24 ) ;
V_197 = F_85 ( & V_236 , NULL , V_2 ,
F_70 ) ;
if ( V_197 < 0 )
return V_197 ;
V_11 = & V_2 -> V_4 -> V_11 ;
if ( NULL != V_2 -> V_4 -> V_31 . V_237 ) {
V_197 = V_2 -> V_4 -> V_31 . V_237 ( & V_153 -> V_42 ,
V_2 -> V_4 ) ;
if ( V_197 ) {
F_3 ( V_11 , L_51 ) ;
V_197 = - V_211 ;
goto V_238;
}
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
if ( F_73 ( V_41 , V_2 , V_153 ) ) {
V_197 = - V_230 ;
goto V_238;
}
}
V_233 = F_86 ( V_153 , V_239 , 0 ) ;
if ( ! V_233 ) {
F_3 ( V_11 , L_52 ) ;
V_197 = - V_230 ;
goto V_238;
}
V_36 = V_233 -> V_240 ;
V_197 = F_87 ( & V_153 -> V_42 , V_36 , F_14 , 0 ,
V_241 , V_2 ) ;
if ( V_197 ) {
F_3 ( V_11 , L_53 ) ;
goto V_238;
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
V_56 = & V_2 -> V_42 [ V_41 ] -> V_48 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> type = V_160 ;
V_56 -> V_242 = V_243 | V_244 | V_245 ;
V_56 -> V_246 = V_2 -> V_42 [ V_41 ] ;
V_56 -> V_31 = & V_247 ;
V_56 -> V_248 = & V_249 ;
V_56 -> V_250 = sizeof( struct V_27 ) ;
V_56 -> V_251 = V_252 ;
V_56 -> V_253 = 1 ;
V_56 -> V_221 = & V_2 -> V_42 [ V_41 ] -> V_199 ;
V_56 -> V_42 = V_2 -> V_4 -> V_153 ;
V_197 = F_88 ( V_56 ) ;
if ( V_197 ) {
F_3 ( V_11 , L_54 ) ;
goto V_238;
}
F_89 ( & V_2 -> V_42 [ V_41 ] -> V_25 ) ;
if ( F_78 ( V_2 -> V_42 [ V_41 ] , V_2 , V_153 ) ) {
V_197 = - V_230 ;
goto V_238;
}
}
F_18 ( 1 , V_57 , V_11 ,
L_55 ) ;
return 0 ;
V_238:
for ( V_234 = 0 ; V_234 < V_47 ; V_234 ++ ) {
if ( V_2 -> V_42 [ V_234 ] != NULL ) {
F_90 ( & V_2 -> V_42 [ V_234 ] -> V_213 ) ;
F_91 ( V_2 -> V_42 [ V_234 ] ) ;
}
}
return V_197 ;
}
static int F_92 ( struct V_203 * V_153 )
{
struct V_13 * V_206 ;
struct V_1 * V_2 = F_72 ( V_153 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_41 ;
F_18 ( 1 , V_57 , & V_4 -> V_11 , L_56 ) ;
if ( NULL != V_4 -> V_31 . V_254 )
V_4 -> V_31 . V_254 ( & V_153 -> V_42 , V_4 ) ;
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
V_206 = V_2 -> V_42 [ V_41 ] ;
F_90 ( & V_206 -> V_213 ) ;
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
F_91 ( V_2 -> V_42 [ V_41 ] ) ;
V_2 -> V_42 [ V_41 ] = NULL ;
}
return 0 ;
}
